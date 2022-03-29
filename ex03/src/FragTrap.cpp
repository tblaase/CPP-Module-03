/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:26:49 by tblaase           #+#    #+#             */
/*   Updated: 2022/03/29 13:35:19 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(): ClapTrap()
{
	if (this->_hit_pts == 10)
		this->_hit_pts = 100;
	this->_energy_pts = 100;
	if (this->_attack_dmg == 0)
		this->_attack_dmg = 30;
	std::cout << "FragTrap Default Constructor for " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	// this->_name = name;
	if (this->_hit_pts == 10)
		this->_hit_pts = 100;
	this->_energy_pts = 100;
	if (this->_attack_dmg == 0)
		this->_attack_dmg = 30;
	std::cout << "FragTrap Constructor for the name " << this->_name << " called" << std::endl;
}

// Deconstructors
FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor for " << this->_name << " called" << std::endl;
}

// Overloaded Operators
FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_pts = src._hit_pts;
	this->_energy_pts = src._energy_pts;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

// Public Methods
void	FragTrap::attack(const std::string &target)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_dmg << " points of damage!" << std::endl;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "\033[31mFragTrap " << this->_name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
	else
		std::cout << "\033[31mFragTrap " << this->_name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "\033[33mFragTrap " << this->_name << " is already dead, stop beating it.\033[0m" << std::endl;
		return ;
	}
	else if (amount > this->_hit_pts)
		this->_hit_pts = 0;
	else
		this->_hit_pts -= amount;
	std::cout << "FragTrap " << this->_name << " was attacked and lost " << amount << " hit points, he now has " << _hit_pts << " hit points." << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0 && this->_hit_pts + amount <= 100)
	{
		this->_hit_pts += amount;
		std::cout << "FragTrap " << this->_name << " repaired itself and gained " << amount << " of hit points, he now has " << _hit_pts << "hit points." << std::endl;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "\033[31mFragTrap " << this->_name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m" << std::endl;
	else if (this->_hit_pts == 0)
		std::cout << "\033[31mFragTrap " << this->_name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m" << std::endl;
	else
		std::cout << "\033[33mFragTrap " << this->_name << " can't be repaired to have more than 100 hit points.\033[0m" << std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}

// Getter

// Setter

