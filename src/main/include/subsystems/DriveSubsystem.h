#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/controls/DutyCycleOut.hpp>

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  void ArcadeDrive(double fwd, double rot);
  void Stop();

  void Periodic() override;

    private:
   ctre::phoenix6::hardware::TalonFX m_leftLeader{0};
   ctre::phoenix6::hardware::TalonFX m_rightLeader{2};
   ctre::phoenix6::hardware::TalonFX m_leftFollower{1};
   ctre::phoenix6::hardware::TalonFX m_rightFollower{3};

   ctre::phoenix6::controls::DutyCycleOut m_leftOut{0};
   ctre::phoenix6::controls::DutyCycleOut m_rightOut{0};
};