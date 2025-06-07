# 🎮 PokéQuest
### 🌀 **OOP-driven Pokémon Battle Simulator in C++**

PokéQuest is a command-line, turn-based Pokémon battle simulator built entirely in C++ using object-oriented programming principles. It features two trainers, each with a team of three Pokémon, engaging in a strategic showdown using unique moves, randomized turn order, and dynamic battle flow.

---

## 🚀 Features

✅ **Object-Oriented Design**: Built using `classes`, `objects`, and structured design.  
⚔️ **Battle System**: Turn-based combat with randomized first turn.  
🧠 **Strategic Gameplay**: Players choose moves per turn, and switch Pokémon when one faints.  
🔥 **Predefined Pokémon**: Fully statted-out Pokémon with different types and moves.  
🎲 **Mystery Stats**: Attack, defense, and move power are hidden from the user for a more fun, unpredictable experience.  

---

## 👥 Trainers and Pokémon

### **Trainer: You**
- **Mega Charizard X** (Fire - Dragon)
- **Luxray** (Electric)
- **Greninja** (Water - Dark)

### **Trainer: Enemy (Computer)**
- **Mega Blastoise** (Water)
- **Ampharos** (Electric)
- **Blaziken** (Fire - Fighting)

> **Note:** Can be modified in the code as per the user's wish.

---

## 📦 Code Structure
- `Move` struct: Represents a move with a name and power.  
- `Pokémon` class: Encapsulates stats, moves, and attack logic.  
- `Trainer` class: Handles teams, Pokémon selection, and switching.  

---

## 🛠️ How to Run

1. Make sure you have a C++ compiler (like `g++`) installed.
2. Compile the code:
   ```bash
   g++ -o pokequest main.cpp
   ```
3. Run the code:
   ```bash
   ./pokequest
   ```

---

## 🧠 Learning Goals
- Practice OOP concepts like encapsulation, class composition, and dynamic behavior.
- Simulate real-world logic in C++ (turns, randomness, battle flow).
- Understand abstraction and game logic modeling.

---

## 📚 Future Plans
- Add type-effectiveness system.
- Option to take Pokémons and their stats as user inputs.
- Increase the number of Pokémons per trainer and their corresponding moves.

---

_Made with ❤️ by [Anirudh](https://github.com/Anirudh-Navalgund/)_
