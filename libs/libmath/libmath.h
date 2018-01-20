/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:51:29 by maghayev          #+#    #+#             */
/*   Updated: 2018/01/19 21:13:52 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

/*
** Pre-Def values
** Macroses Part 0
*/
# define INT_MIN -2147483648
# define INT_MAX 2147483647

/*
**	Math operations
*/
int		ft_floorsqrt(int toroot);
int		ft_pow(int num1, int power);

/*
** Math comparison
*/
int		ft_min(int num1, int num2);

#endif