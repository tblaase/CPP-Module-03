/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:33:50 by tblaase           #+#    #+#             */
/*   Updated: 2022/03/29 14:03:14 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
#include "../include/ClapTrap.hpp"


// Constructors
ClapTrap::ClapTrap(): _name("default"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << "ClapTrap Constructor for the name " << this->_name << " called" << std::endl;
}

// Deconstructors
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor for " << this->_name << " called" << std::endl;
}

// Overloaded Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_pts = src._hit_pts;
	this->_energy_pts = src._energy_pts;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

// Public Methods
void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_dmg << " points of damage!" << std::endl;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "\033[31mClapTrap " << this->_name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
	else
		std::cout << "\033[31mClapTrap " << this->_name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts > amount)
		this->_hit_pts -= amount;
	else if (this->_hit_pts > 0)
		this->_hit_pts = 0;
	else
	{
		std::cout << "\033[33mClapTrap " << this->_name << " is already dead, stop beating it.\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " was attacked and lost " << amount << " hit points, he now has " << this->_hit_pts << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0 && this->_hit_pts + amount <= 10)
	{
		this->_hit_pts += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself and gained " << amount << " of hit points, he now has " << this->_hit_pts << "hit points." << std::endl;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "\033[31mClapTrap " << this->_name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m" << std::endl;
	else if (this->_hit_pts == 0)
		std::cout << "\033[31mClapTrap " << this->_name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m" << std::endl;
	else
		std::cout << "\033[33mClapTrap " << this->_name << " can't be repaired to have more than 10 hit points.\033[0m" << std::endl;
}
// Getter

// Setter

