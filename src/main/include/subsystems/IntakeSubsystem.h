#pragma once
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix6/TalonFX.hpp>

class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem(int motor1CANID, int motor2CANID, int motor3CANID);

  void SetIntake(double percent);
  void motor1Test(double percent);
  void motor2Test(double percent);
  void motor3Test(double percent);
  void Shooting(double percent);
  void Stop();

  void Periodic() override;

 private:
 ctre::phoenix6::hardware::TalonFX Intake1;
 ctre::phoenix6::hardware::TalonFX Intake2;
 ctre::phoenix6::hardware::TalonFX Indexer;
  // Add any necessary member variables and methods for the intake subsystem
};