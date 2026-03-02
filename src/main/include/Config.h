#pragma once



#include <frc/DigitalInput.h>
#include <ctre/phoenix6/CANBus.hpp>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/configs/Configuration.hpp>
#include <Vector>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <frc2/command/button/CommandXboxController.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>



inline ctre::phoenix6::CANBus CAN{""};
inline nt::NetworkTableInstance m_inst = nt::NetworkTableInstance::GetDefault();
inline std::shared_ptr<nt::NetworkTable> slam = m_inst.GetTable("slam");
inline std::shared_ptr<nt::NetworkTable> limelight = m_inst.GetTable("limelight");

class ClimberCostants {

    public:
        static constexpr int ClimbMotorID = 1;
        static constexpr int ClimbMotorFollower1ID = 2;
        static constexpr int ClimbMotorFollower2ID = 3;
        static constexpr int RotorSensor = 0;
        static constexpr int ClimbNeutral = 1;
        static constexpr double maxSpeed = 0.8;
        static constexpr double minSpeed = -0.8;
        static constexpr int stopSpeed = 0;
        static constexpr units::turn_t PIDTolorance = 0.1_tr;
        static constexpr double kP = 0.1;
        static constexpr int kI = 0.0;
        static constexpr int kD = 0.0;

        static constexpr units::turn_t restPID = 0.0_tr;
        static constexpr units::turn_t maxPID = 1.0_tr;
};
