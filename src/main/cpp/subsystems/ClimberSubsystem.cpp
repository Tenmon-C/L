#include "subsystems/ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() {
m_setPoint = ClimberCostants::restPID;
    ctre::phoenix6::controls::PositionVoltage m_initial{m_setPoint};

    ctre::phoenix6::configs::TalonFXConfiguration config{};
        config.Feedback.WithFeedbackSensorSource(ClimberCostants::RotorSensor);
        config.Slot0.WithKP(ClimberCostants::kP).WithKI(ClimberCostants::kI).WithKD(ClimberCostants::kD);
        config.MotorOutput.WithNeutralMode(ClimberCostants::ClimbNeutral).WithInverted(true);

    m_climb.GetConfigurator().Apply(config);
    m_climb.SetControl(m_initial);
}

void ClimberSubsystem::raise() {
    m_climb.Set(ClimberCostants::maxSpeed);
}
void ClimberSubsystem::lower() {
    m_climb.Set(ClimberCostants::minSpeed);
}
void ClimberSubsystem::stop() {
    m_climb.Set(ClimberCostants::stopSpeed);
}
void ClimberSubsystem::max() {
    ctre::phoenix6::controls::PositionVoltage m_request = ctre::phoenix6::controls::PositionVoltage{ClimberCostants::maxPID};
    m_climb.SetControl(m_request);
    m_setPoint = ClimberCostants::maxPID;
}
void ClimberSubsystem::rest(){
    ctre::phoenix6::controls::PositionVoltage m_request = ctre::phoenix6::controls::PositionVoltage{ClimberCostants::restPID};
    m_climb.SetControl(m_request);
    m_setPoint = ClimberCostants::restPID;
}
units::turn_t ClimberSubsystem::getPIDPosition() {
    return m_climb.GetPosition().GetValue();
}
bool ClimberSubsystem::isAtSetPoint() {
    return (units::math::abs(m_setPoint - m_climb.GetPosition().GetValue()) <= ClimberCostants::PIDTolorance);
}
bool ClimberSubsystem::isAtRest() {
    return (units::math::abs(ClimberCostants::restPID - m_climb.GetPosition().GetValue()) <= ClimberCostants::PIDTolorance);
}