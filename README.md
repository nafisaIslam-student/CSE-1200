# Innerworld Chronicles

## Game Description
The Innerworld Chronicles is a 2d adventure game with hints of surrealism. The main character is stuck in a parallel world, created by his own subconsciousness which is full of obstacles and unknown creatures. The players must help him to navigate the mystical world, fight through surreal challenges and to overcome his inner demons.

## Tools & Technologies Used
In this game, all character maps, obstacles, objects, and weapons were created using our own graphic designs, giving the game a unique and original visual style.:
- IDE: Visual Studio 2010/2013
- Graphics Library: iGraphics
- Platform: Windows PC
- Map Design: Tiled
- Character & Object Design: Pixquare	

## How to run the project

Make sure you have the following installed:

- Visual Studio 2013
- MinGW Compiler (if needed)
- iGraphics Library (included in this repository)
- Open the project in Visual Studio 2013.
- Go to File → Open → Project/Solution.
- Locate and select the .sln file from the cloned repository.
- Click Build → Build Solution
- Run the program by clicking Debug → Start Without Debugging


## Core Features

| Function   | Move Left     | Move Right     | Move Up       | Move Down     | Attack       |
|------------|---------------|----------------|----------------|----------------|--------------|
| Button     | ← (Left Arrow) | → (Right Arrow) | ↑ (Up Arrow)   | ↓ (Down Arrow) | Spacebar     |

-	Player Weapon: Players can press the P/p key to pick up the sword and use spacebar to use it.
-	Sword Fighting: Players engage monsters fighting using sword.
-	Health bar: Player’s health bar decreases due to attack by monster.
-	Object Collection: Player has to collect objects within a certain time limit
-	Monster Battles: In 1st and 3rd level features a powerful monster to battle.
-	Game Over Conditions: The game ends if players cannot collect specific objects by a required time or doesn’t defeat the monster 
                                        Implementation Details

## Challenges Faced & Solutions

| Challenge                                     | Solution                                      |
|-----------------------------------------------|-----------------------------------------------|
| Handling multiple enemies and simultaneous attacks. | Use states (idle, attack, dead) for enemies to simplify logic. |
| Tracking multiple interactive objects efficiently. | Use arrays or update timer to manage interactive objects. |
| Designing puzzles that are challenging but solvable. | Use triggers and flags to manage puzzle progress. |

## Rules 
Monster attacks must be fought to progress. Collect mirrors within a time limit.   Monsters appear based on time; defeat them before time runs out. Collect crystals from specific boxes; monsters spawn if the wrong box is chosen or crystals aren’t collected in time. Win by gathering required items and defeating spawned monsters. Specific instruction will be provided in dialogue box and information chart.

## Project contribution 
- Madhobi Bardhan 
- Ayesha Binte Habib
- Nafisa Islam
  
## Screenshorts

### ** Interface  **
<img width="664" height="393" alt="Screenshot 2025-10-13 222523" src="https://github.com/user-attachments/assets/844ffc91-52ac-4bd3-94ad-cf250f09f54a" />


### ** Menu  **
<img width="664" height="393" alt="Screenshot 2025-10-13 222523" src="https://github.com/user-attachments/assets/a3bf7a6e-7d97-4085-a78e-d8d2a82e0fd3" />


### ** Main Character Design  **
<img width="664" height="393" alt="Screenshot 2025-10-13 212820" src="https://github.com/user-attachments/assets/5055605c-a1b6-498f-b2f1-017c48fea4b2" />


### ** Level 1  **
<img width="664" height="393" alt="Screenshot 2025-10-13 215208" src="https://github.com/user-attachments/assets/8fb21a0a-455f-442a-9d9d-798ef083ebcc" />


### ** Level 2  **
<img width="664" height="393" alt="Screenshot 2025-10-13 215227" src="https://github.com/user-attachments/assets/4988ad9b-836f-4442-8c53-b4657aff6fc0" />


### ** Level 3  **
<img width="664" height="393" alt="Screenshot 2025-10-13 215531" src="https://github.com/user-attachments/assets/d8e0a9da-5617-4da4-a178-a72c165b48e9" />


### ** Level 4  **
<img width="664" height="393" alt="Screenshot 2025-10-13 215706" src="https://github.com/user-attachments/assets/c3e69730-3859-42b1-bfe6-79e48cff668e" />


### ** Fighting Scene  **
<img width="664" height="393" alt="Screenshot 2025-10-13 220446" src="https://github.com/user-attachments/assets/4014a717-9893-49c9-8c13-eb316a7b9a80" />


### ** Object Collection 1 **
<img width="664" height="393" alt="Screenshot 2025-10-13 214717" src="https://github.com/user-attachments/assets/a946fc4a-0852-4796-9ae5-e5f7344bd508" />

### ** Main boss  **
<img width="664" height="393" alt="Screenshot 2025-10-13 215738" src="https://github.com/user-attachments/assets/5560bb9b-b725-4ad8-a961-fd67ceff703d" />


### ** Object Collection 2  **
<img width="664" height="393" alt="Screenshot 2025-10-13 215738" src="https://github.com/user-attachments/assets/b0f603a1-bf83-4356-8680-3c742632930d" />


### ** Death Scene  **
<img width="664" height="393" alt="Screenshot 2025-10-13 214548" src="https://github.com/user-attachments/assets/8fba922d-6d30-4fec-a30b-118208f16f97" />

## Youtube Link 
[CSE:1200 Project:Innerworld Chronicles](https://www.youtube.com/watch?v=SVEQPKPQlgo)

## Project Report 
[Project Report:Innerworld Chronicles](https://drive.google.com/file/d/1yNszarXwD-l4HbzJ6SiMVupcui_2hA07/view?usp=drive_link)
