/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 18:06:28 by jfortin           #+#    #+#             */
/*   Updated: 2017/03/11 13:00:34 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(unsigned int hp, unsigned int damageDeal, unsigned int speed, unsigned int score, std::string skin, Weapon *weapon, t_coord coord) : AEntity(hp, damageDeal, speed, score, skin, weapon, coord) {}

Enemy::Enemy(Enemy const &src) : AEntity(src) {}

Enemy::~Enemy()
{
    if (_weapon)
        delete _weapon;
}

Enemy	                &Enemy::operator=(Enemy const &rhs)
{
    _weapon = rhs._weapon->clone();
    AEntity::operator=(rhs);
    return (*this);
}

bool                    Enemy::move(unsigned int height, unsigned int width, int key)
{
    (void)width;
    (void)key;
    if (Game::_checkTime(_speed, _lastMove))
    {
        if (_coord.y < height - _skinSize.y - 1)
            _coord.y += 1;
        else
            return (false);
    }
    return (true);
}

AEntity::t_entityList    *Enemy::shoot(int key)
{
    (void)key;
    if (!_weapon)
        throw(AEntity::NoWeaponEquippedException::NoWeaponEquippedException());
    return (_weapon->createMissile(*this, 'S'));
}