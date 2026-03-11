#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem(int motor1CANID, int motor2CANID, int motor3CANID) 
: Intake1(motor1CANID), Intake2(motor2CANID), Indexer(motor3CANID) 
{
  // Constructor implementation
}
void IntakeSubsystem::SetIntake(double percent) {
  Intake1.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
  Intake2.SetControl(ctre::phoenix6::controls::DutyCycleOut(-percent));
  Indexer.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
}

void IntakeSubsystem::Shooting(double percent) {
  Intake1.SetControl(ctre::phoenix6::controls::DutyCycleOut(-percent));
  Intake2.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
  Indexer.SetControl(ctre::phoenix6::controls::DutyCycleOut(-percent));
}
void IntakeSubsystem::Stop() {
  Intake1.SetControl(ctre::phoenix6::controls::DutyCycleOut(0));
  Intake2.SetControl(ctre::phoenix6::controls::DutyCycleOut(0));
  Indexer.SetControl(ctre::phoenix6::controls::DutyCycleOut(0));
}
void IntakeSubsystem::Periodic() {
  // This method will be called once per scheduler run
}