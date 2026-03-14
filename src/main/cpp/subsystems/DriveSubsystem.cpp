#include "subsystems/DriveSubsystem.h"

using namespace ctre::phoenix6;

DriveSubsystem::DriveSubsystem() {

  configs::MotorOutputConfigs currentConfigs{};

  // Left side inverted CCW+
  currentConfigs.Inverted = signals::InvertedValue::CounterClockwise_Positive;
  m_leftLeader.GetConfigurator().Apply(currentConfigs);

  // Right side inverted CW+
  currentConfigs.Inverted = signals::InvertedValue::Clockwise_Positive;
  m_rightLeader.GetConfigurator().Apply(currentConfigs);

  // Followers
  m_leftFollower.SetControl(controls::Follower{m_leftLeader.GetDeviceID(), false});
  m_rightFollower.SetControl(controls::Follower{m_rightLeader.GetDeviceID(), false});
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {

  double left = fwd + rot;
  double right = fwd - rot;

  // Normalize outputs if they exceed 1.0
  double maxMagnitude = std::max(std::abs(left), std::abs(right));

  if (maxMagnitude > 1.0) {
    left /= maxMagnitude;
    right /= maxMagnitude;
  }

  m_leftOut.Output = left;
  m_rightOut.Output = right;

  m_leftLeader.SetControl(m_leftOut);
  m_rightLeader.SetControl(m_rightOut);
}

void DriveSubsystem::Stop() {

  m_leftOut.Output = 0;
  m_rightOut.Output = 0;

  m_leftLeader.SetControl(m_leftOut);
  m_rightLeader.SetControl(m_rightOut);
}

void DriveSubsystem::Periodic() {}
