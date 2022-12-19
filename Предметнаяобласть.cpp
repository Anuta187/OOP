#include <iostream>
#include <string>

class Characteristics {
public:
    std::string name;
    int level;
    std::string fraction;
    std::string class_info;
    int honor;
};
class Character : public Characteristics {
public:
    std::string resp;
    std::string name;
    std::string fraction;
    std::string class_info;
    int lvl;
    int honor;
    Character(std::string name, int lvl, std::string fraction,
        std::string class_info, int honor)
    {
        this->name = name;
        this->lvl = lvl;
        this->fraction = fraction;
        this->class_info = class_info;
        this->honor = honor;
    }

    void show()
    {
        char star = '-';
        int num = 30;
        std::cout << std::string(num, star) << std::endl;
        std::cout << "Name       : " << this->name << std::endl;
        std::cout << "Lvl        : " << this->lvl << std::endl;
        std::cout << "Fraction   : " << this->fraction << std::endl;
        std::cout << "Class info : " << this->class_info << std::endl;
        std::cout << "Honor	     : " << this->honor << std::endl;
        std::cout << std::string(num, star) << std::endl;
    }
    std::string respect()
    {
        std::string result;
        if ((lvl > 30) and (honor < 100))
            return result = "Has respect from the fraction";
        else return result = "No respect";
    }
    bool operator > (const Character& object)
    {
        return object.honor > honor;
    }
};

int main()
{
    std::string resp;
    Character orc("Saurfang", 30, "Horde", "Warrior", 90);
    Character elf("Alexstrasza", 90, "Horde", "Priest", 90);
    Character human("Anduin", 100, "Alliance", "Warrior", 100);
    Character dworf("Genn", 150, "Alliance", "Hunter", 70);

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

    std::cout << "<------------------------------>" << std::endl;

    if (orc > elf)
    {
         std::cout << "Lok'tar Ogar!";
    }
    else std::cout << "Anar'ala!";
}


