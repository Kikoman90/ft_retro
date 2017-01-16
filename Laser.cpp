/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:06:23 by jfortin           #+#    #+#             */
/*   Updated: 2017/01/16 19:02:29 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Laser.hpp"

Laser::Laser(unsigned int hp_missile, unsigned int damageDeal, unsigned int speed_missile, unsigned int rateOfFire) : AWeapon(hp_missile, damageDeal, speed_missile, rateOfFire) {}

Laser::Laser() : AWeapon(1, 2, 50, 200) {}

Laser::Laser(Laser const &src) : AWeapon(src._hp_missile, src._damageDeal, src._speed_missile, src._rateOfFire) {}

Laser::~Laser() {}

Laser		&Laser::operator=(Laser const &rhs)
{
	AWeapon::operator=(rhs);
	return (*this);
}

AWeapon		*Laser::clone() const
{
	AWeapon	*clone = new Laser(*this);

	return (clone);
}

AEntity		*Laser::createMissile(t_coord coord, char direction)
{
	if (_cnt_shoot++ < _rateOfFire)
        throw(AWeapon::RateOfFireException::RateOfFireException());
	_cnt_shoot = 0;
	return (new Missile(_hp_missile, _damageDeal, _speed_missile, "|", NULL, coord, direction));
}