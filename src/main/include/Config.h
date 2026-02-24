#pragma once



#include <frc/DigitalInput.h>
#include <ctre/phoenix6/CANBus.hpp>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/configs/MotorOutputConfigs.hpp>
#include <Vector>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <frc2/command/button/CommandXboxController.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>



inline ctre::phoenix6::CANBus CAN{""};
inline nt::NetworkTableInstance m_inst = nt::NetworkTableInstance::GetDefault();
inline std::shared_ptr<nt::NetworkTable> slam = m_inst.GetTable("slam");
inline std::shared_ptr<nt::NetworkTable> limelight = m_inst.GetTable("limelight");

