# Maze Hunter [Final Project for Software Engineering for Embedded Applications EEP520]

This Repository contains the code and implementation plan for my final project in EE P 520 [Software Engineering for Embedded Applications], taught by *Sep Makhsous*. This project is a implemention of a Maze Hunter game  that uses "Enviro" framework by Klavinslab[^1].

"Navigate a shifting maze, battle enemies that chase and shoot, and use your shooting skills to outsmart your foes in an action-packed adventure!" 

## Overview
Overview:
Maze Hunter is an engaging shooting game where the player navigates a maze while facing off against enemies. The maze layout changes dynamically, and enemies possess varying abilities to patrol, shoot, and chase the player. The player must adapt quickly, avoiding enemy fire while using strategic movement and shooting to eliminate enemies. The game focuses on the use of the "Enviro" framework to create dynamic agent behaviors and interactions, providing an immersive and challenging experience.


### Implementation:

1. Player
- The player is controlled using keyboard inputs and can move, shoot bullets, and avoid obstacles.
- The goal is to survive while eliminating enemies in the dynamically generated maze.

2. Enemies
- Patrol within a defined area or chase the player.
- Ability to shoot at the player when in range. 
- They shoot projectiles at the player when in range.

3. Dynamic Maze
- The game generates random maze layouts at the start of each session.
- Walls shift dynamically, forcing players to adapt to an ever-changing environment.
- Entry and exit points are generated to create an immersive gameplay experience.

4. Weapons & Shooting Mechanics
- Both the player and enemies can shoot bullets.
- Bullets destroy on impact when hitting the target.

5. Projectiles:
- Represented by bullets 
- Collision detection with Player, Enemy and Walls.

6. Game Physics & Interactions
- Collision detection ensures the player and enemies can't walk through walls.
- Bullets disappear upon hitting obstacles or characters.
- Enemies react to the player's movement and obstacles in real-time.


## Key Challenges and Solutions

### Implementation Plan
Coming up with the implementation plan on how to built the game, what all agents it will require and the working abilities of components was challenge. I started out by making a list of tasks and the order in which they need to be completed to be have a good idea on what needs to be done and what to expect next. Here is the Implemention plan that I wrote:
- Setup Enviro Environment:
- Design basic functionality of the Blocks/Maze:
- Developing the Player Agent Funtionality:
- Creating Enemy Agents behaviour:
- Implement working of Bullets:
- Incorporate basic functionality of components to form a level
- Testing, and Debugging

### Managing Dynamic Maze Generation
- Challenge: Ensuring a navigable path in a randomly generated maze.
- Solution: Using an algorithm that guarantees connectivity between start and exit points.

### Preventing Players from Passing Through Walls
- Challenge: Physics-based collision could sometimes allow players to pass through thin gaps.
- Solution: Implemented rigid-body physics constraints and recalculated the player’s movement vector when hitting walls.

### Handing Friendly Fire
Since both the Enemy and the Player has the ability to shoot, I was facing issues with friendly fire inbetween the enemies. Initially, I was using the same bullet agent for both the Player and Enemy. Since the bullet was make to handle collision with the enemies, the bullets fired by the enemies were killing a few of their own. So, I created different bullet agents bullet,bulletenemy for the Player and the Enemy respectively. Using this I was able to eliminate friendly fire. 

# Installation

## Docker Images
Assuming that Docker is already installed in your system. A docker image must be loaded to run the enviro server from a bash prompt. If you do not have docker installed, please visit Docker Installation[^2]

To start, run the below command:
````
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.61 bash
````
Use the below commands to start esm, make the project and start the enviro server as:
````
esm start
make
enviro
````
Then navigate to `http://localhost` and begin the gameplay!   
To end the game, press `Ctrl-C` in the `bash` terminal to stop the enviro server.

## Usage

After loading the "Enviro" environment, and navigation to the localhost, You should be able to see the game in your browser.
Here are a few instructions you should keep in mind,

### Instructions

1. Take some time to read the messages on the game, I have provided a few tips and ideas on how to approach the game.
2. The Player is not made to stop immediately on key release on purpose, It is to make the game a little challenging
4. Tapping the keys are the best way to move the Player, Holding down the keys while the player is about to be killed can occasionally lead the game to crash as the Player agent is looking for key.
5. Re-launch enviro when game over over

### Controls

`a` - Move Left
`d` - Move Right
`w` - Move Up
`s` - Move Down
`Spacebar` - Shoot a bullet in the direction of the last pressed key (Unlimited Shoots.!)


## Acknowledgements
We would like to acknowledge the following sources of information and code used in this project:
- [^1]: Enviro, https://github.com/klavinslab/enviro
- [^2]: Docker Install, https://docs.docker.com/
- https://github.com/klavinslab/elma.git

Special Mentions Sep's course repo, which I referred for generic idea and gameflow
- https://github.com/sosper30/eep520-wi25/


