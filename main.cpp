#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Move {
    string name;
    int power;
};

// Pokemon Class
class Pokemon {
public:
    string name;
    string type;
    int hp;
    int attack;
    int defense;
    Move moves[3];

    Pokemon() {}

    Pokemon(string n, string t, int h, int a, int d, Move m1, Move m2, Move m3) {
        name = n;
        type = t;
        hp = h;
        attack = a;
        defense = d;
        moves[0] = m1;
        moves[1] = m2;
        moves[2] = m3;
    }

    void displayStats() {
        cout << "=== " << name << " ===\n";
        cout << "Moves: ";
        for (int i = 0; i < 3; i++) {
            cout << moves[i].name;
            if (i < 2) cout << " | ";
        }
        cout << "\n";
    }

    void takeDamage(int damage) {
        if (damage < 0) damage = 0;
        hp -= damage;
        if (hp < 0) hp = 0;
        cout << name << " took " << damage << " damage! Remaining HP: " << hp << endl;
    }

    void attackTarget(Pokemon &target, int moveIndex) {
        Move chosenMove = moves[moveIndex];
        cout << name << " uses " << chosenMove.name << " on " << target.name << "!" << endl;
        int damage = (chosenMove.power + (attack - target.defense)) / 2;
        target.takeDamage(damage);
        cout << endl;
    }

    bool isFainted() {
        return hp <= 0;
    }
};

// Trainer Class
class Trainer {
public:
    string name;
    Pokemon team[3];
    int currentIndex;

    Trainer(string n, Pokemon p1, Pokemon p2, Pokemon p3) {
        name = n;
        team[0] = p1;
        team[1] = p2;
        team[2] = p3;
        currentIndex = -1;
    }

    Pokemon& currentPokemon() {
        return team[currentIndex];
    }

    void displayTeam() {
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << team[i].name << " (HP: " << team[i].hp << ")";
            if (team[i].isFainted()) cout << " (Fainted)";
            cout << endl;
        }
    }

    bool hasRemainingPokemon() {
        for (int i = 0; i < 3; i++) {
            if (!team[i].isFainted()) return true;
        }
        return false;
    }

    void choosePokemon() {
        cout << "\n";
        cout << name << ", choose your Pokemon:\n";
        int choice;
        do {
            displayTeam();
            cout << "Enter 1-3: ";
            cin >> choice;
            choice--;
        } while (choice < 0 || choice >= 3 || team[choice].isFainted());

        currentIndex = choice;
        cout << name << " sends out " << currentPokemon().name << "!\n";
    }

    void autoChooseIfFainted() {
        if (!currentPokemon().isFainted()) return;
        for (int i = 0; i < 3; i++) {
            if (!team[i].isFainted()) {
                currentIndex = i;
                cout << name << " sends out " << team[i].name << "!\n";
                return;
            }
        }
    }
};

int main() {
    cout << " === PokeQuest - Pokemon Battle Simulator ===\n\n";
    srand(time(0));

    // Define moves
    Move flareBlitz = {"Flare Blitz", 120};
    Move flamethrower = {"Flamethrower", 85};
    Move airSlash = {"Air Slash", 75};

    Move hydroPump = {"Hydro Pump", 110};
    Move bubbleBeam = {"Bubble Beam", 80};
    Move skullBash = {"Skull Bash", 90};

    Move wildCharge = {"Wild Charge", 110};
    Move thunderWave = {"Thunder Wave", 70};
    Move crunch = {"Crunch", 80};

    Move nightSlash = {"Night Slash", 70};
    Move waterShuriken = {"Water Shuriken", 60};

    Move thunder = {"Thunder", 120};
    Move electroBall = {"Electro Ball", 90};
    Move powerGem = {"Power Gem", 80};

    Move blazeKick = {"Blaze Kick", 85};
    Move flameCharge = {"Flame Charge", 65};

    // Create Pokemon
    Pokemon charizard("Mega Charizard X", "Fire - Dragon", 250, 130, 111,
                      flareBlitz, flamethrower, airSlash);
    Pokemon blastoise("Mega Blastoise", "Water", 250, 103, 120,
                      hydroPump, bubbleBeam, skullBash);
    Pokemon luxray("Luxray", "Electric", 250, 120, 79,
                   wildCharge, thunderWave, crunch);
    Pokemon greninja("Greninja", "Water - Dark", 250, 95, 67,
                     hydroPump, nightSlash, waterShuriken);
    Pokemon ampharos("Ampharos", "Electric", 250, 75, 85,
                     thunder, electroBall, powerGem);
    Pokemon blaziken("Blaziken", "Fire - Fighting", 250, 120, 70,
                     flareBlitz, blazeKick, flameCharge);

    // Create Trainers
    Trainer you("You", charizard, luxray, greninja);
    Trainer enemy("Enemy", blastoise, ampharos, blaziken);

    cout << "Your Team:\n";
    you.team[0].displayStats();
    you.team[1].displayStats();
    you.team[2].displayStats();
    cout << "\n";
    cout << "Enemy Team:\n";
    enemy.team[0].displayStats();
    enemy.team[1].displayStats();
    enemy.team[2].displayStats();

    // Choose first Pokemon
    you.choosePokemon();
    do {
        enemy.currentIndex = rand() % 3;
    } while (enemy.team[enemy.currentIndex].isFainted());

    cout << "Enemy sends out " << enemy.currentPokemon().name << "!\n\n";


    bool userTurn = rand() % 2 == 0;
    cout << (userTurn ? "You" : "Enemy") << " go first!\n\n";

    while (you.hasRemainingPokemon() && enemy.hasRemainingPokemon()) {
        cout << "================== TURN ==================\n";

        Pokemon &userMon = you.currentPokemon();
        Pokemon &enemyMon = enemy.currentPokemon();

        if (userTurn) {
            cout << "Your Turn! Choose a move for " << userMon.name << ":\n";
            for (int i = 0; i < 3; i++) {
                cout << "  " << (i + 1) << ". " << userMon.moves[i].name << endl;
            }

            int moveChoice;
            do {
                cout << "Enter move number (1-3): ";
                cin >> moveChoice;
            } while (moveChoice < 1 || moveChoice > 3);

            userMon.attackTarget(enemyMon, moveChoice - 1);

            if (enemyMon.isFainted() && enemy.hasRemainingPokemon()) {
                enemy.autoChooseIfFainted();
            }

        } else {
            cout << "Enemy Turn...\n";
            int enemyMove = rand() % 3;
            enemyMon.attackTarget(userMon, enemyMove);

            if (userMon.isFainted() && you.hasRemainingPokemon()) {
                you.choosePokemon();
            }
        }

        userTurn = !userTurn;
    }

    cout << "Battle Over! ";
    if (!you.hasRemainingPokemon() && !enemy.hasRemainingPokemon()) {
        cout << "It's a draw!\n";
    } else if (!you.hasRemainingPokemon()) {
        cout << "Enemy wins!\n";
    } else {
        cout << "You win!\n";
    }

    return 0;
}
