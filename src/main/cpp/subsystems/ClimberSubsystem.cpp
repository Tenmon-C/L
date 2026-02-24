#include <wpi/sendable/SendableBuilder.h>
#include "subsystems/ClimberSubsystem.h"
#include <frc/controller/PIDController.h>
#include <iostream>
#include <ctre/phoenix/motorcontrol/ControlMode.h>

ClimberSubsystem::ClimberSubsystem() {}

 frc2::CommandPtr ClimberSubsystem::GoToMax() {
    return this->RunOnce(
        [this] {
            C_motor.SetControl(m_request.WithPosition(2_tr));
        }
    );
}
frc2::CommandPtr ClimberSubsystem::GoToRest() {
    return this->RunOnce(
        [this] {
            C_motor.SetControl(m_request.WithPosition(0_tr));
        }
    );
}