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
  pathplanner::NamedCommands::registerCommand("Climb", std::make_shared<max>(&m_climber));
  
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
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
  frc2::cmd::Run(
    [this] { m_climber.max(); },
    {&m_climber}
  )
);
m_operatorController.B().OnTrue(
  frc2::cmd::Run(
    [this] { m_climber.rest(); },
    {&m_climber}
  )
);
m_operatorController.POVUp().OnTrue(
  frc2::cmd::Run(
    [this] { m_intake.motor1Test(0.5); },
    {&m_intake}
  )
);
m_operatorController.POVDown().OnTrue(
  frc2::cmd::Run(
    [this] { m_intake.motor1Test(0); },
    {&m_intake}
  )
);
m_operatorController.POVLeft().OnTrue(
  frc2::cmd::Run(
    [this] { m_intake.motor2Test(0.5); },
    {&m_intake}
  )
);
m_operatorController.POVLeft().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_intake.motor2Test(0); },
    {&m_intake}
  )
);
m_operatorController.POVRight().OnTrue(
  frc2::cmd::Run(
    [this] { m_intake.motor3Test(0.5); },
    {&m_intake}
  )
);
m_operatorController.POVRight().OnFalse(
  frc2::cmd::RunOnce(
    [this] { m_intake.motor3Test(0); },
    {&m_intake}
  )
);
}
frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return pathplanner::PathPlannerAuto("Basic Drive Forward").ToPtr();
}
