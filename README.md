# cowboy_vs_ninja_b

In this exercise, we will create a simulation of a battle between ninjas and cowboys.

## Part 1: Point

First, we will write a class that helps us keep track of the position on the game board. The position is given by two
double coordinates, representing the unit's position along the x and y axes, respectively. The class interface should
support the following operations:

- `Constructor`: Receives the two coordinates.
- `Distance`: Receives a point and computes the distance between the two points.
- `Print`: Prints the two coordinates enclosed in parentheses.
- `Move Towards`: Receives a source point, a target point, and a distance. The function returns the point closest to the
  target point, at most the given distance away from the source point.

## Part 2: Character

This class represents a **character**. A character has a position (of type Point), a hit points value (represented by an
integer), and a name represented by a string of characters.

The defined functions for the character are:

- `isAlive`: Returns a Boolean value indicating whether the character is alive (i.e., has more than zero hit points).
- `Distance`: Receives a pointer to another character and returns the distance between the characters (double).
- `Hit`: Receives an integer number and subtracts the corresponding hit points from the character. It does not return
  anything.
- `getName`: Returns the character's name.
- `getLocation`: Returns the character's location.
- `Print`: Prints the character's name, its hit points, and its location. If the character is dead, the hit points will
  not be printed, and the name will be enclosed in parentheses. Before the name, there will be a letter indicating the
  character type: 'N' for ninja and 'C' for cowboy.

For cowboys, there is also the parameter "number of bullets" (integer). A cowboy is always created with six bullets and
110 hit points. The following functions are defined for cowboys only:

- `Shoot`: Receives a pointer to an enemy. If the cowboy is alive and has bullets left, the cowboy shoots the enemy,
  subtracts 10 hit points from the enemy, and loses one bullet. Otherwise, the enemy does not receive any damage.
- `Has Bullets`: Returns a Boolean value indicating whether the cowboy has bullets left in their gun.
- `Reload`: Reloads the gun with six new bullets.

For **ninjas**, the parameter "speed" (integer) is defined. The following functions are defined for ninjas only:

- `Move`: Receives a pointer to an enemy and moves towards the enemy. The ninja advances a distance equal to their
  speed.
- `Slash`: Receives a pointer to an enemy. If the ninja is alive and the enemy is within one meter, the ninja inflicts
  40 hit points of damage to the enemy. Otherwise, the enemy does not receive any damage.

There are `three` types of ninjas:

- `YoungNinja`: Moves at a speed of 14. Created with 100 hit points.
- `TrainedNinja`: Moves at a speed of 12. Created with 120 hit points.
- `OldNinja`: Moves at a speed of 8. Created with 150 hit points.

## Part 3: Team

This class represents a **team** of up to ten fighters, where each fighter can be a `ninja` or a `cowboy`. Each team has a
leader who is one of the fighters.

When a team is created, it receives a pointer to the leader.

The defined functions for the team are:

- `Add`: Receives a pointer to a cowboy or ninja and adds it to the team.
- `Attack`: Receives a pointer to an enemy team. The attack of the enemy team is carried out as follows:

First, check if the attacking team's leader is alive. Otherwise, choose a new leader, which is the living character
closest in proximity to the current leader.

- Then, select a victim from the enemy team. The victim is a member of the enemy team who is alive and closest in
  proximity to the attacking team's leader.
- All living members of the attacking team will attack the selected victim. Cowboys with bullets will shoot the victim,
  subtracting damage, and cowboys without bullets will reload their gun. Ninjas within one meter of the victim will
  slash the victim, and ninjas farther away will move towards the victim.
- At each stage, if the victim dies, a new victim is chosen (again, the closest living enemy character to the attacking
  team's leader).
- If there are no living members in the attacking team or in the enemy team, the attack ends.
- Is Still Alive: Returns an integer representing the number of living members in the team.
- Print: Iterates over all the characters in the team and prints their details.
- Destructor: Releases the memory allocated for all the characters in the team.

Traversal of the team members (for the purpose of attacking, printing, or comparison) is always performed in the
following order: first, iterate over all the cowboys, and then iterate over all the ninjas. Within each team, the
traversal is based on the order in which the characters were added. The purpose of the requirement to separate cowboys
and ninjas in this part is to make it easier for you. If you find that the requirement complicates the implementation,
consider an alternative implementation. When searching for the closest character and two characters are at the same
distance, choose the first character that is checked among them.

## team2

Same as `team`, but the traversal of the characters will be based on the order of addition without distinguishing
between cowboys or ninjas.

## SmartTeam

Same as `team`, but the traversal of the characters will be based on your chosen order of implementation. It is allowed
and desirable at this stage to "ask" the second team about the locations and status of its fighters and also take into
account the situation of the attacking team to maximize the damage. When this task is evaluated in the student lab with
a smart, creative, efficient, and effective algorithm, bonus points will be awarded (you cannot exceed the maximum of 10
points, but a simple algorithm can still earn you 10 points if it eliminates errors in other areas).

**Part B**: You should write:

* Full implementation of the task to pass the test.

Write all the required files so that the following commands work without errors:

```bash
bash grade
```

It is also recommended to run:

```bash
make tidy
make valgrind
```

Do not modify existing files, only add new ones.

Good luck!