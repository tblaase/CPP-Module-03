/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:27:18 by tblaase           #+#    #+#             */
/*   Updated: 2022/03/28 16:59:41 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include "ScavTrap.hpp"

// classes

class FragTrap:public ClapTrap
{
	private:

	public:
	// Constructors
		FragTrap();
		FragTrap(const FragTrap& copy);
		FragTrap(std::string name);

	// Deconstructors
		virtual ~FragTrap();

	// Overloaded Operators
		FragTrap &operator=(const FragTrap &src);

	// Public Methods
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFiveGuys(void);
	// Getter

	// Setter

};
