/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:33:55 by tblaase           #+#    #+#             */
/*   Updated: 2022/03/25 11:23:24 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Cody");

	a.attack("some other robot");
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	for (int i = 0; i < 12; i++)
		b.attack("Cody-clone");
	b.beRepaired(3);
}