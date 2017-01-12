/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:51:41 by jfortin           #+#    #+#             */
/*   Updated: 2017/01/12 21:42:19 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(unsigned int hp_missile, unsigned int damageDeal, unsigned int speed_missile, unsigned int rateOfFire) :
	hp_missile(hp_missile), damageDeal(damageDeal), speed_missile(speed_missile), rateOfFire(rateOfFire), cnt_shoot(0)
{}

AWeapon::AWeapon()
{}

AWeapon::AWeapon(AWeapon const &src) : cnt_shoot(0)
{
	*this = src;
}

AWeapon::~AWeapon() {}

AWeapon	&AWeapon::operator=(AWeapon const &rhs)
{
	if (this != &rhs)
	{
		hp_missile = rhs.hp_missile;
		speed_missile = rhs.speed_missile;
		rateOfFire = rhs.rateOfFire;
		cnt_shoot = rhs.cnt_shoot;
	}
	return (*this);
}

AWeapon::RateOfFireException::RateOfFireException() { return ; }

AWeapon::RateOfFireException::RateOfFireException(RateOfFireException const &src) { *this = src; }

AWeapon::RateOfFireException::~RateOfFireException() throw() { return ; }

AWeapon::RateOfFireException  &AWeapon::RateOfFireException::operator=(AWeapon::RateOfFireException const &rhs)
{
    (void)rhs;
    return (*this);
}

char const					*AWeapon::RateOfFireException::what(void) const throw()
{
    return ("Rate of fire");
}