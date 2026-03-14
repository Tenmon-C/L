// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include <frc2/command/Commands.h>
#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include "commands/Intake.h"
#include "commands/Shoot.h"
#include "commands/Climb.h"


#include <pathplanner/lib/commands/PathPlannerAuto.h>
#include <pathplanner/lib/events/EventTrigger.h>
#include <pathplanner/lib/auto/NamedCommands.h>
RobotContainer::RobotContainer() {
  
  pathplanner::NamedCommands::registerCommand("Intake", std::make_shared<Intake>(&m_intake, 0.5));
  pathplanner::NamedCommands::registerCommand("Outake", std::make_shared<Intake>(&m_intake, -0.5));
  pathplanner::NamedCommands::registerCommand("Shoot", std::make_shared<Shoot>(&m_intake, 0.5));
  pathplanner::NamedCommands::registerCommand("Stop", std::make_shared<Intake>(&m_intake, 0));
 // pathplanner::NamedCommands::registerCommand("Climb", std::make_shared<max>(&m_climber));
  
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();

  m_drive.SetDefaultCommand(
  frc2::cmd::Run(
    [this] {
     double fwd = frc::ApplyDeadband(-m_driverController.GetLeftY(), 0.05);
     double rot = frc::ApplyDeadband(m_driverController.GetRightX(), 0.05);  

      m_drive.ArcadeDrive(fwd, rot);
    },
    {&m_drive}
  )
);
  
}

void RobotContainer::ConfigureBindings() {


// Run the intake when the right bumper is held
m_driverController.RightBumper().OnTrue(
  frc2::cmd::Run(
    [this] {
      m_intake.SetIntake(1);
    },
    {&m_intake}
  )
);
// Stop the intake when the right bumper is released
m_driverController.RightBumper().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_intake.Stop(); },
    {&m_intake}
  )
);


// Run the intake in reverse when the left bumper is held
m_driverController.LeftBumper().OnTrue(
  frc2::cmd::Run(
    [this] {  m_intake.SetIntake(-1); },
    {&m_intake}
  )
);
// Stop the intake when the left bumper is released
m_driverController.LeftBumper().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_intake.Stop();},
    {&m_intake}
  )
);


// Shoot the intake when the A button is held
m_driverController.POVUp().OnTrue(
  frc2::cmd::Run(
    [this] { m_intake.Shooting(1); },
    {&m_intake}
  )
);
// Stop the intake when the A button is released
m_driverController.POVUp().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_intake.Stop(); },
    {&m_intake}
  )
);
m_operatorController.A().OnTrue(
  frc2::cmd::RunOnce(
    [this] { m_climber.Raise(0.8); },
    {&m_climber}
  )
);
m_operatorController.A().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_climber.Stop(); },
    {&m_climber}
  )
);
m_operatorController.B().OnTrue(
  frc2::cmd::RunOnce(
    [this] { m_climber.Lower(0.8); },
    {&m_climber}
  )
);
m_operatorController.B().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_climber.Stop(); },
    {&m_climber}
  )
);
}
frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return frc2::cmd::Sequence(

    // DRIVE FORWARD
    frc2::cmd::RunOnce([this] {
      m_drive.ArcadeDrive(0.4, 0);
    }, {&m_drive}),

    frc2::cmd::Wait(units::second_t(2)),

    // STOP DRIVE
    frc2::cmd::RunOnce([this] {
      m_drive.Stop();
    }, {&m_drive}),

    // SHOOT
    frc2::cmd::RunOnce([this] {
      m_intake.Shooting(1);
    }, {&m_intake}),

    frc2::cmd::Wait(units::second_t(3)),

    // STOP SHOOTER
    frc2::cmd::RunOnce([this] {
      m_intake.Stop();
    }, {&m_intake}),

    // DRIVE BACKWARD
    frc2::cmd::RunOnce([this] {
      m_drive.ArcadeDrive(-0.4, 0);
    }, {&m_drive}),

    frc2::cmd::Wait(units::second_t(2)),

    // STOP DRIVE
    frc2::cmd::RunOnce([this] {
      m_drive.Stop();
    }, {&m_drive}),

    // CLIMB
    frc2::cmd::RunOnce([this] {
      m_climber.Raise(0.8);
    }, {&m_climber}),

    frc2::cmd::Wait(units::second_t(3)),

    // STOP CLIMBER
    frc2::cmd::RunOnce([this] {
      m_climber.Stop();
    }, {&m_climber})

  );
}
