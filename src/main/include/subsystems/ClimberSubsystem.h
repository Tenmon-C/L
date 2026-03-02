#pragma once

#include <frc2/command/SubsystemBase.h> //Subsystem things

#include <ctre/phoenix6/configs/Configuration.hpp>

#include "Config.h"


class ClimberSubsystem : public frc2::SubsystemBase {
    public: 
        ClimberSubsystem();
        void raise();
        void lower();
        void stop();
        void max();
        void rest();
        units::turn_t getPIDPosition();
        bool isAtSetPoint();
        bool isAtRest();


    private: 
        ctre::phoenix6::hardware::TalonFX m_climb{ClimberCostants::ClimbMotorID, CAN};
        units::turn_t m_setPoint = 0_tr;
};