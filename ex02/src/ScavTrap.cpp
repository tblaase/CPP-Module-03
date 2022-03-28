/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:19:54 by tblaase           #+#    #+#             */
/*   Updated: 2022/03/28 16:58:14 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap()
{
	this->_name = "defaultST";
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy):ClapTrap(copy)
{
	this->_guarding_gate = copy._guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hit_pts = 100;
	this->_energy_pts = 50;
	this->_attack_dmg = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Constructor for the name " << this->_name << " called" << std::endl;
}

// Deconstructors
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << this->_name << " called" << std::endl;
}

// Overloaded Operators
ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_pts = src._hit_pts;
	this->_energy_pts = src._energy_pts;
	this->_attack_dmg = src._attack_dmg;
	return *this;
}

// Public Methods
void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_dmg << " points of damage!" << std::endl;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "\033[31mScavTrap " << this->_name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
	else
		std::cout << "\033[31mScavTrap " << this->_name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts == 0)
	{
		std::cout << "\033[33mScavTrap " << this->_name << " is already dead, stop beating it.\033[0m" << std::endl;
		return ;
	}
	else if (amount > this->_hit_pts)
		this->_hit_pts = 0;
	else
		this->_hit_pts -= amount;
	std::cout << "ScavTrap " << this->_name << " was attacked and lost " << amount << " hit points, he now has " << _hit_pts << " hit points." << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0 && this->_hit_pts + amount <= 100)
	{
		this->_hit_pts += amount;
		std::cout << "ScavTrap " << this->_name << " repaired itself and gained " << amount << " of hit points, he now has " << _hit_pts << "hit points." << std::endl;
		this->_energy_pts--;
	}
	else if (this->_energy_pts == 0)
		std::cout << "\033[31mScavTrap " << this->_name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m" << std::endl;
	else if (this->_hit_pts == 0)
		std::cout << "\033[31mScavTrap " << this->_name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m" << std::endl;
	else
		std::cout << "\033[33mScavTrap " << this->_name << " can't be repaired to have more than 100 hit points.\033[0m" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_guarding_gate == false)
	{
		this->_guarding_gate = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "\033[33mScavTrap " << this->_name << " is already guarding the gate.\033[0m" << std::endl;
}

// Getter

// Setter

