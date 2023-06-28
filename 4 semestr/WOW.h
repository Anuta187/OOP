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
    void do_operation(int lvl, int honor, int (*op)(int, int))
    {
        std::cout << op(lvl, honor) << std::endl;
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
class Mob {
public:
    Mob(std::string name, int level, std::string klass) {
        this->name = name;
        this->level = level;
        this->klass = klass;
    }
    std::string getName() const {
        return name;
    }

    int getLevel() const {
        return level;
    }

    std::string getKlass() const {
        return klass;
    }
private:
    std::string name;
    int level;
    std::string klass;
};
    /////////////////////////////////
    template<typename T>
    class WowIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        WowIterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        wowiterator& operator++() {
            ++m_ptr;
            return *this;
        }

        WowIterator operator++(int) {
            WowIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const WowIterator& other) const {
            return m_ptr == other.m_ptr;
        }

        bool operator!=(const WowIterator& other) const {
            return !(*this == other);
        }

    private:
        pointer m_ptr;
    };
    //////////////////////////////////
    template<typename T>
    class WowContainer {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = WowIterator<T>;
        using const_iterator = WowIterator<const T>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;

        void addElement(T element) {
            elements.push_back(element);
        }

        iterator begin() { return iterator(&elements[0]); }
        iterator end() { return iterator(&elements[elements.size()]); }

        const_iterator cbegin() const { return const_iterator(&elements[0]); }
        const_iterator cend() const { return const_iterator(&elements[elements.size()]); }

        bool empty() const { return elements.empty(); }
        size_type size() const { return elements.size(); }
        size_type max_size() const { return elements.max_size(); }

        void clear() { elements.clear(); }

        iterator insert(iterator pos, const T& value) {
            return iterator(elements.insert(pos.operator->(), value));
        }

        iterator erase(iterator pos) {
            return iterator(elements.erase(pos.operator->()));
        }

        void swap(WowContainer& other) {
            elements.swap(other.elements);
        }

        template<typename... Args>
        iterator emplace(const_iterator pos, Args&&... args) {
            return iterator(elements.emplace(pos.operator->(), std::forward<Args>(args)...));
        }
        template<typename... Args>
        iterator emplace_hint(const_iterator pos, Args&&... args) {
            return iterator(elements.emplace_hint(pos.operator->(), std::forward<Args>(args)...));
        }
    private:
        std::vector<T> elements;
    };

    class Dungeon {
    public:
        Dungeon(std::string name, std::string location) {
            this->name = name;
            this->location = location;
        }
        std::string getName() const {
            return name;
        }

        std::string getLocation() const {
            return location;
        }

        void addCharacter(Character character) {
            charact.addElement(character);
        }

        void addMob(Mob mob) {
            mobs.addElement(mob);
        }

        WowContainer<Character>& getCharacter() {
            return charact;
        }

        const WowContainer<Character>& getCharacter() const {
            return charact;
        }

        WowContainer<Mob>& getMob() {
            return mobs;
        }

        const WowContainer<Mob>& getMob() const {
            return mobs;
        }

    private:
        std::string name;
        std::string location;
        WowContainer<Character> charact;
        WowContainer<Mob> mobs;
    };

    


