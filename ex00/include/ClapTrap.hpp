/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:33:58 by tblaase           #+#    #+#             */
/*   Updated: 2022/03/25 10:39:15 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>

// classes

class ClapTrap
{
	private:
		std::string _name;
		int _hit_pts;
		int _energy_pts;
		int _attack_dmg;

	public:
	// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap(std::string name);

	// Deconstructors
		~ClapTrap();

	// Overloaded Operators
		ClapTrap &operator=(const ClapTrap &src);

	// Public Methods
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	// Getter

	// Setter

};