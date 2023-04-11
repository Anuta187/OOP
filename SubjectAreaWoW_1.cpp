#include <iostream>
#include <string>

class Characteristics
{
public:
	std::string fraction;
	std::string name;
	std::string klass;
	int level;
};

class Character : public Characteristics
{
public:
	int honor;
	std::string result;
	std::string resp;
	std::string rang;

	std::string Respect(Character object)
	{
		if ((level > 50) and (honor > 100))
		{
			result = "Has respect from the faction";
		}
		else result = "No respect";
		return object.resp = result;
	}

	std::string HowRang(Character object)
	{
		if (level < 40)
		{
			result = '1';
		}
		else result = '2';
		return object.rang = result;
	}
};

int main()
{
	Character orc;
	std::cout << "---------------------------------------------" << std::endl;
	orc.name = "Saurfang";
	std::cout << "Name - " << orc.name << std::endl;
	orc.level = 30;
	std::cout << "Level - " << orc.level << std::endl;
	orc.klass = "Warrior";
	std::cout << "Class - " << orc.klass << std::endl;
	orc.fraction = "Horde";
	std::cout << "Fraction - " << orc.fraction << std::endl;
	orc.honor = 300;
	std::cout << "Honor - " << orc.honor << std::endl;
	orc.resp = orc.Respect(orc);
	std::cout << "Respect - " << orc.resp << std::endl;
	orc.resp = orc.HowRang(orc);
	std::cout << "Rang - " << orc.resp << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	Character elf;
	elf.name = "Alexstrasza";
	std::cout << "Name - " << elf.name << std::endl;
	elf.level = 78;
	std::cout << "Level - " << elf.level << std::endl;
	elf.klass = "Priest";
	std::cout << "Class - " << elf.klass << std::endl;
	elf.fraction = "Horde";
	std::cout << "Fraction - " << elf.fraction << std::endl;
	elf.honor = 340;
	std::cout << "Honor - " << elf.honor << std::endl;
	elf.resp = elf.Respect(elf);
	std::cout << "Respect - " << elf.resp << std::endl;
	elf.resp = elf.HowRang(elf);
	std::cout << "Rang - " << elf.resp << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	Character human;
	human.name = "Anduin";
	std::cout << "Name - " << human.name << std::endl;
	human.level = 78;
	std::cout << "Level - " << human.level << std::endl;
	human.klass = "Warrior";
	std::cout << "Class - " << human.klass << std::endl;
	human.fraction = "Alliance";
	std::cout << "Fraction - " << human.fraction << std::endl;
	human.honor = 80;
	std::cout << "Honor - " << human.honor << std::endl;
	human.resp = human.Respect(human);
	std::cout << "Respect - " << human.resp << std::endl;
	human.resp = human.HowRang(human);
	std::cout << "Rang - " << human.resp << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	Character dworf;
	dworf.name = "Genn";
	std::cout << "Name - " << dworf.name << std::endl;
	dworf.level = 101;
	std::cout << "Level - " << dworf.level << std::endl;
	dworf.klass = "Hunter";
	std::cout << "Class - " << dworf.klass << std::endl;
	dworf.fraction = "Alliance";
	std::cout << "Fraction - " << dworf.fraction << std::endl;
	dworf.honor = 270;
	std::cout << "Honor - " << dworf.honor << std::endl;
	dworf.resp = dworf.Respect(dworf);
	std::cout << "Respect - " << dworf.resp << std::endl;
	dworf.resp = dworf.HowRang(dworf);
	std::cout << "Rang - " << dworf.resp << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

}

