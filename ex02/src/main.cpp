/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:33:55 by tblaase           #+#    #+#             */
/*   Updated: 2022/03/28 18:47:18 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Cody");
	ScavTrap c;
	ScavTrap d("Savage");
	FragTrap e;
	FragTrap f("chadd");

	a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("Cody-clone");
	b.beRepaired(3);
	c.attack("CloneTrap");
	// for (int i = 0; i < 50; i++)
	// 	c.attack("CloneTrap");
	c.beRepaired(22);
	c.takeDamage(21);
	c.beRepaired(22);
	c.guardGate();
	c.guardGate();
	d.attack("Savage-clone");
	d.takeDamage(101);
	d.takeDamage(15);
	d.attack("ScavTrap-clone");
	e.highFiveGuys();
	e.takeDamage(101);
	e.takeDamage(1);
	e.attack("some random dude");
	f.highFiveGuys();
	// for(int i = 0; i < 101; i++)
	// 	f.attack("FragTrap-clone");
	return (0);
}