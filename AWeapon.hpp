/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:18:27 by jfortin           #+#    #+#             */
/*   Updated: 2017/01/06 16:32:49 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include "Missile.hpp"
// #include "AEntity.hpp"
// class   AEntity;
// class   AWeapon;
// class   Missile;
// # include "Game.hpp"
#include "AEntity.hpp"
// class	Missile;
// class	AEntity;

class	AWeapon{

public:
	AWeapon();
	~AWeapon();
	AWeapon(AWeapon const &src);

	virtual AEntity	*createMissile(AEntity const &shooter);

	AWeapon	&operator=(AWeapon const &rhs);

private:

};

#endif