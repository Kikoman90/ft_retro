/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfortin <jfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:51:42 by fsidler           #+#    #+#             */
/*   Updated: 2017/01/01 16:20:48 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntity.hpp"

AEntity::AEntity(unsigned int hp, unsigned int speed, std::string skin, AWeapon *weapon, t_coord coord)
	: hp(hp), speed(speed), skin(skin), weapon(weapon), coord(coord)
{
	this->sizeSkin = getSizeSkin();
	//temporaire (retirer plus tard)
	(void)weapon;
	//temporaire
}

AEntity::AEntity(AEntity const &src)
{
	*this = src;
}

//temporaire??
AEntity::AEntity() { return ; }
//temporaire??

AEntity::~AEntity()
{}

AEntity	&AEntity::operator=(AEntity const &rhs)
{
	if (this != &rhs)
	{
		hp = rhs.hp;
		speed = rhs.speed;
		skin = rhs.skin;
		weapon = rhs.weapon;
		coord = rhs.coord;
	}
	return (*this);
}

void	AEntity::equipWeapon(AWeapon *weapon)
{
	this->weapon = weapon;
}

AEntity	*AEntity::shoot()
{
	return (NULL);
	/*if (this->weapon)
		return (this->weapon->createMissile());
	return (NULL);*/
}

/*void	AEntity::takeDamage(AEntity const &attcker)
{
	
}*/

void	AEntity::displaySkin(WINDOW *win) const
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = this->coord.y;
	wattron(win, COLOR_PAIR(3));
	while (skin.c_str()[i])
	{
		x = 0;
		while (skin.c_str()[i] && skin.c_str()[i] != '\n')
			mvwaddch(win, y, coord.x + (x++), skin.c_str()[i++]);
		i += skin.c_str()[i] ? 1 : 0;
		y++;
	}
	wattroff(stdscr, COLOR_PAIR(3));
}

t_coord	AEntity::getCoord() const
{
	return (this->coord);
}

t_coord	AEntity::getSizeSkin() const
{
    std::size_t length_max;
    std::size_t length_tmp;
    std::size_t index;
	std::size_t	height;

    index = 0;
    length_max = 0;
    length_tmp = 0;
	height = 0;
    while (index < this->skin.length() - 1)
    {
		height++;
        index += length_tmp + 1;
        if ((length_tmp = this->skin.find("\n", index + 1) - index) > this->skin.length())
        {
            length_tmp = this->skin.length() - index;
            length_max = (length_max < length_tmp) ? length_tmp : length_max;        
            break ;
        }
        length_max = (length_max < length_tmp) ? length_tmp : length_max;
    }
	return (t_coord){length_max, height};
}