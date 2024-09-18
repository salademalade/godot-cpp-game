#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <godot_cpp/classes/character_body2d.hpp>

namespace godot
{
class Character : public CharacterBody2D
{
    GDCLASS(Character, CharacterBody2D)

private:
    double speed;

protected:
    static void _bind_methods();

public:
    Character();
    ~Character();

    void _process(double delta) override;

    double get_speed();
    void set_speed(const double p_speed);

    void get_input();
};
}

#endif
