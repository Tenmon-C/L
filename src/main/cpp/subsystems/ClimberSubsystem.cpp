#include "subsystems/ClimberSubsystem.h"
#include <ctre/phoenix6/configs/Configuration.hpp>
#include <ctre/phoenix6/signals/SpnEnums.hpp>

ClimberSubsystem::ClimberSubsystem(int motorCANID)
: ClimberMotor(motorCANID)
{
  ctre::phoenix6::configs::TalonFXConfiguration config{};

  // Brake mode so climber holds position
  config.MotorOutput.NeutralMode = ctre::phoenix6::signals::NeutralModeValue::Brake;

  // Current limiting
  config.CurrentLimits.SupplyCurrentLimit = 40_A;
  config.CurrentLimits.SupplyCurrentLimitEnable = true;

  ClimberMotor.GetConfigurator().Apply(config);
}

void ClimberSubsystem::Raise(double percent) {
  ClimberMotor.SetControl(ctre::phoenix6::controls::DutyCycleOut(percent));
}

void ClimberSubsystem::Lower(double percent) {
  ClimberMotor.SetControl(ctre::phoenix6::controls::DutyCycleOut(-percent));
}

void ClimberSubsystem::Stop() {
  ClimberMotor.SetControl(ctre::phoenix6::controls::DutyCycleOut(0));
}

void ClimberSubsystem::Periodic() {
}