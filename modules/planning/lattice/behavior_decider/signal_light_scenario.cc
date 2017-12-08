/***************************************************************************
 *
 * Copyright (c) 2016 Baidu.com.0, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file signal_light_scenario.cpp
 **/

#include "modules/planning/lattice/behavior_decider/signal_light_scenario.h"
#include "modules/planning/common/planning_gflags.h"
#include "modules/common/log.h"

#include "gflags/gflags.h"

namespace apollo {
namespace planning {

void SignalLightScenario::Reset() {}

bool SignalLightScenario::Init() {
  exist_ = true;
  return exist_;
}

int SignalLightScenario::ComputeScenarioDecision(
    Frame* frame,
    ReferenceLineInfo* const reference_line_info,
    const common::TrajectoryPoint& init_planning_point,
    const std::array<double, 3>& lon_init_state,
    const std::vector<common::PathPoint>& discretized_reference_line,
    std::vector<PlanningTarget>* const decisions) {
  CHECK(frame != nullptr);

  // Only handles one reference line
  CHECK_GT(discretized_reference_line.size(), 0);

  PlanningTarget ret;
  for (const auto& reference_point : discretized_reference_line) {
    ret.mutable_discretized_reference_line()
        ->add_discretized_reference_line_point()
        ->CopyFrom(reference_point);
  }

  //ret.set_decision_type(PlanningTarget::CRUISE);
  //ret.set_cruise_speed(FLAGS_default_cruise_speed);

  //decisions->emplace_back(std::move(ret));

  return 0;
}

bool SignalLightScenario::FindValidSignalLight(
    ReferenceLineInfo* const reference_line_info) {
  return false;
}

void SignalLightScenario::ReadSignals() {
  detected_signals_.clear();
  return;
}


}
}
