#include "character.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input.hpp>

void godot::Character::_bind_methods()
{
    godot::ClassDB::bind_method(D_METHOD("get_input"), &Character::get_input);

    godot::ClassDB::bind_method(D_METHOD("get_speed"), &Character::get_speed);
    godot::ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &Character::set_speed);
    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

godot::Character::Character()
{

}

godot::Character::~Character()
{

}

void godot::Character::_process(double delta)
{
    get_input();
    move_and_slide();
}

void godot::Character::set_speed(const double p_speed)
{
    speed = p_speed;
}

double godot::Character::get_speed()
{
    return speed;
}

void godot::Character::get_input()
{
    godot::Vector2 direction = godot::Input::get_singleton()->get_vector("ui_left", "ui_right", "ui_up", "ui_down");
    set_velocity(direction * speed);
}
