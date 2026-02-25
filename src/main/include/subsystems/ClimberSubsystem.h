#pragma once 
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h> //Subsystem things
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/DigitalInput.h>
#include "Config.h"
#include <ctre/phoenix6/TalonFX.hpp>

class ClimberSubsystem : public frc2::SubsystemBase {
    public: 
        ClimberSubsystem(int motorCANID);

        frc2::CommandPtr GoToRest();
        frc2::CommandPtr GoToMax();
        void InitSendable(wpi::SendableBuilder& builder) override;
   
    private: 
            ctre::phoenix6::hardware::TalonFX C_motor;
            
            ctre::phoenix6::controls::PositionVoltage m_request = ctre::phoenix6::controls::PositionVoltage{0_tr}.WithSlot(0).WithOverrideBrakeDurNeutral(true);
};