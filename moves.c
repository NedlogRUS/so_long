#include "so_long.h"

void move_right(t_game *sl)
{
    while(1)
    {
        if(sl->map->mapchars[sl->map->b_y][sl->map->b_x + 1] == '1')
            return;
        if(sl->map->mapchars[sl->map->b_y][sl->map->b_x + 1] == '7')
            break;
        if(sl->map->mapchars[sl->map->b_y][sl->map->b_x + 1] == 'J')
        {
            sl->map->num_honey -= 1;
            break;
        }
        if(sl->map->mapchars[sl->map->b_y][sl->map->b_x + 1] == 'L')
        {
            if(sl->map->num_honey == 0)
                end_game(sl);
                // break; // END GAME
            else
                return;
        }
        else
            return;
    }
        sl->map->mapchars[sl->map->b_y][sl->map->b_x] = '7';
        sl->map->mapchars[sl->map->b_y][sl->map->b_x + 1] = 'P';
        sl->map->b_x += 1;
        sl->step_count += 1;
        print_map(sl);
        return ;
}

void move_left(t_game *sl)
{
    while(1)
    {
        if(sl->map->mapchars[sl->map->b_y][sl->map->b_x - 1] == '1')
            return;
        if(sl->map->mapchars[sl->map->b_y][sl->map->b_x - 1] == '7')
            break;
        if(sl->map->mapchars[sl->map->b_y][sl->map->b_x - 1] == 'J')
        {
            sl->map->num_honey -= 1;
            break;
        }
        if(sl->map->mapchars[sl->map->b_y][sl->map->b_x - 1] == 'L')
        {
            if(sl->map->num_honey == 0)
                end_game(sl);
                // break; // END GAME
            else
                return;
        }
        else
            return;
    }
        sl->map->mapchars[sl->map->b_y][sl->map->b_x] = '7';
        sl->map->mapchars[sl->map->b_y][sl->map->b_x - 1] = 'W';
        sl->map->b_x -= 1;
        sl->step_count += 1;
        print_map(sl);
        return ;
}

void move_up(t_game *sl)
{
    while(1)
    {
        if(sl->map->mapchars[sl->map->b_y - 1][sl->map->b_x] == '1')
            return;
        if(sl->map->mapchars[sl->map->b_y - 1][sl->map->b_x] == '7')
            break;
        if(sl->map->mapchars[sl->map->b_y - 1][sl->map->b_x] == 'J')
        {
            sl->map->num_honey -= 1;
            break;
        }
        if(sl->map->mapchars[sl->map->b_y - 1][sl->map->b_x] == 'L')
        {
            if(sl->map->num_honey == 0)
                end_game(sl);
                // break; // END GAME
            else
                return;
        }
        else
            return;
    }
        sl->map->mapchars[sl->map->b_y][sl->map->b_x] = '7';
        sl->map->mapchars[sl->map->b_y - 1][sl->map->b_x] = 'P';
        sl->map->b_y -= 1;
        sl->step_count += 1;
        print_map(sl);
        return ;
}

void move_down(t_game *sl)
{
    while(1)
    {
        if(sl->map->mapchars[sl->map->b_y + 1][sl->map->b_x] == '1')
            return;
        if(sl->map->mapchars[sl->map->b_y + 1][sl->map->b_x] == '7')
            break;
        if(sl->map->mapchars[sl->map->b_y + 1][sl->map->b_x] == 'J')
        {
            sl->map->num_honey -= 1;
            break;
        }
        if(sl->map->mapchars[sl->map->b_y + 1][sl->map->b_x] == 'L')
        {
            if(sl->map->num_honey == 0)
                end_game(sl);
                // break; // END GAME
            else
                return;
        }
        else
            return;
    }
        sl->map->mapchars[sl->map->b_y][sl->map->b_x] = '7';
        sl->map->mapchars[sl->map->b_y + 1][sl->map->b_x] = 'W';
        sl->map->b_y += 1;
        sl->step_count += 1;
        print_map(sl);
        return ;
}

void moves(int i, t_game *sl)
{
    if(i == 124 || i == 2)
        move_right(sl);
    if(i == 123 || i == 0)
        move_left(sl);
    if(i == 126 || i == 13)
        move_up(sl);
    if(i == 125 || i == 1)
        move_down(sl);
}