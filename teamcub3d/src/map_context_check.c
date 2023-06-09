/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_context_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:24:39 by sohyupar          #+#    #+#             */
/*   Updated: 2023/05/23 16:57:29 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_player_space(t_game *dir, char **map)
{
	if (map[(int)dir->info->p_pos[0] - 1][(int)dir->info->p_pos[1]] == ' ')
		return (FALSE);
	if (map[(int)dir->info->p_pos[0] + 1][(int)dir->info->p_pos[1]] == ' ')
		return (FALSE);
	if (map[(int)dir->info->p_pos[0]][(int)dir->info->p_pos[1] - 1] == ' ')
		return (FALSE);
	if (map[(int)dir->info->p_pos[0]][(int)dir->info->p_pos[1] + 1] == ' ')
		return (FALSE);
	return (TRUE);
}

static int	other_context(char context)
{
	if (context != '0' && context != '1' && context != 'W' \
		&& context != 'S' && context != 'E' && context != 'N' \
		&& context != ' ')
		return (FALSE);
	return (TRUE);
}

static void	west_east(char context, t_game *dir, int x, int y)
{
	if (context == 'W')
	{
		dir->info->w++;
		dir->info->p_pos[0] = y;
		dir->info->p_pos[1] = x;
		dir->info->player++;
	}
	else if (context == 'E')
	{
		dir->info->e++;
		dir->info->p_pos[0] = y;
		dir->info->p_pos[1] = x;
		dir->info->player++;
	}
}

static void	south_north(char context, t_game *dir, int x, int y)
{
	if (context == 'S')
	{
		dir->info->s++;
		dir->info->p_pos[0] = y;
		dir->info->p_pos[1] = x;
		dir->info->player++;
	}
	else if (context == 'N')
	{
		dir->info->n++;
		dir->info->p_pos[0] = y;
		dir->info->p_pos[1] = x;
		dir->info->player++;
	}
}

int	context_check(char context, t_game *dir, int x, int y)
{
	if (!other_context(context))
		return (FALSE);
	west_east(context, dir, x, y);
	south_north(context, dir, x, y);
	return (TRUE);
}
