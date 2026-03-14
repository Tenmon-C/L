#pragma once
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>

class ClimberSubsystem : public frc2::SubsystemBase {
 public:
  ClimberSubsystem(int motorCANID);

  void Raise(double percent);
  void Lower(double percent);
  void Stop();

  void Periodic() override;

 private:
  ctre::phoenix6::hardware::TalonFX ClimberMotor;
};