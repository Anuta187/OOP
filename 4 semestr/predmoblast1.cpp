#include <iostream>
#include <string>
#include "WOW.h"

int main()
{
    std::string resp;
    Character orc("Saurfang", 30, "Horde", "Warrior", 90);
    Character elf("Alexstrasza", 90, "Horde", "Priest", 90);
    Character human("Anduin", 100, "Alliance", "Warrior", 100);
    Character dworf("Genn", 150, "Alliance", "Hunter", 70);
    Mob Mob_1("Dentarg", 50, "Ogr");
    Mob Mob_2("Cho'gall", 120, "Murloc");
    Dungeon dungeon_1("Uldaman", "Khaz Modan");

    dungeon_1.addMob(Mob_1);
    dungeon_1.addMob(Mob_2);
    dungeon_1.addCharacter(orc);
    dungeon_1.addCharacter(elf);

    std::cout << "Name of the dungeon: " << dungeon_1.getName() << std::endl;
    std::cout << "Location of the dungeon: " << dungeon_1.getLocation() << std::endl;


    std::cout << "Dungeon Mobs: " << std::endl;
    for (const Mob& mob : dungeon_1.getMob()) {
        std::cout << mob.getName() << " Level:  " << mob.getLevel()  << "Class:" << mob.getKlass() << std::endl;
    }
    return 0;

    resp = orc.respect();
    orc.show();
    std::cout << resp << std::endl;

    resp = elf.respect();
    elf.show();
    std::cout << resp << std::endl;

    resp = human.respect();
    human.show();
    std::cout << resp << std::endl;

    resp = dworf.respect();
    dworf.show();
    std::cout << resp << std::endl;

    std::cout << "<------------------------------>" << std::endl;/////////////////////////// lambda

    auto sum{ [](int lvl, int honor) {return lvl + honor; } };
    auto subtract{ [](int lvl, int honor) {return lvl - honor; } };
    human.do_operation(orc.lvl, orc.honor, subtract);
    orc.do_operation(orc.lvl, orc.honor, sum);

    std::cout << "<------------------------------>" << std::endl;
    auto press = []() {
        puts("Press enter to continue...");
        getchar();
    };

    press();
    if (orc > elf)
    {
        std::cout << "Lok'tar Ogar!";
    }
    else std::cout << "Anar'ala!";
}

