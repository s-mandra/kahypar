/***************************************************************************
 *  Copyright (C) 2016 Sebastian Schlag <sebastian.schlag@kit.edu>
 **************************************************************************/

#include "gmock/gmock.h"

#include "lib/utils/Math.h"

using::testing::Eq;

namespace utils {
TEST(NextPowerOfTwoCeiled, WorksAsExpected) {
  ASSERT_THAT(nextPowerOfTwoCeiled(1), Eq(1));
  ASSERT_THAT(nextPowerOfTwoCeiled(4), Eq(4));
  ASSERT_THAT(nextPowerOfTwoCeiled(26), Eq(32));
  ASSERT_THAT(nextPowerOfTwoCeiled(65), Eq(128));
}

TEST(NearestMultipleOf, WorksAsExpected) {
  ASSERT_THAT(nearestMultipleOf(2, 64), Eq(64));
  ASSERT_THAT(nearestMultipleOf(64, 64), Eq(64));
  ASSERT_THAT(nearestMultipleOf(65, 64), Eq(128));
}
}  // namespace utils
