#pragma once

#include <vector>

#include "definitions.h"

namespace partition {


class SingleNodeHyperedgeRemover {
 public:
  struct RemovalResult {
    HyperedgeID num_removed_single_node_hes;
    HypernodeID num_unconnected_hns;
  };

  SingleNodeHyperedgeRemover() :
      _removed_hes() { }

  SingleNodeHyperedgeRemover(const SingleNodeHyperedgeRemover&) = delete;
  SingleNodeHyperedgeRemover& operator= (const SingleNodeHyperedgeRemover&) = delete;

  SingleNodeHyperedgeRemover(SingleNodeHyperedgeRemover&&) = delete;
  SingleNodeHyperedgeRemover& operator= (SingleNodeHyperedgeRemover&&) = delete;

  RemovalResult removeSingleNodeHyperedges(Hypergraph& hypergraph) {
    RemovalResult result{0,0};
    for (const HyperedgeID he : hypergraph.edges()) {
      if (hypergraph.edgeSize(he) == 1) {
        ++result.num_removed_single_node_hes;
        if (hypergraph.nodeDegree(*hypergraph.pins(he).first) == 1) {
          ++result.num_unconnected_hns;
        }
        hypergraph.removeEdge(he, false);
        _removed_hes.push_back(he);
      }
    }
    return result;
  }

  void restoreSingleNodeHyperedges(Hypergraph& hypergraph) {
    for (auto he_it = _removed_hes.rbegin(); he_it != _removed_hes.rend(); ++he_it) {
      hypergraph.restoreEdge(*he_it);
    }
    _removed_hes.clear();
  }

 private:
  std::vector<HyperedgeID> _removed_hes;
};


} // namespace partition