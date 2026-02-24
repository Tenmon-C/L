#include "subsystems/IntakeSubsystem.h"
IntakeSubsystem::IntakeSubsystem(int motor1CANID, int motor2CANID) 
: Intake1(motor1CANID), Intake2(motor2CANID) 
{
  // Constructor implementation
}
void IntakeSubsystem::SetIntake(double percent) {
  Intake1.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
  Intake2.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
}
void IntakeSubsystem::motor1Test(double percent) {
  Intake1.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
}
void IntakeSubsystem::motor2Test(double percent) {
  Intake2.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
}
void IntakeSubsystem::Shooting(double percent) {
  Intake1.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
  Intake2.SetControl(ctre::phoenix6::controls::DutyCycleOut(-percent));
}
void IntakeSubsystem::Stop() {
  Intake1.SetControl(ctre::phoenix6::controls::DutyCycleOut(0));
  Intake2.SetControl(ctre::phoenix6::controls::DutyCycleOut(0));
}