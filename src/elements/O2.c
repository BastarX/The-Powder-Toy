#include <element.h>

int update_O2(UPDATE_FUNC_ARGS)
{
	int r,rx,ry;
	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (x+rx>=0 && y+ry>=0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if ((r>>8)>=NPART || !r)
					continue;

				if ((r&0xFF)==PT_FIRE)
				{
					parts[r>>8].life+=(rand()/(RAND_MAX/100))*2;
					parts[r>>8].temp+=(rand()/(RAND_MAX/100));
					parts[i].tmp++;
				}

			}

	if (pv[y/CELL][x/CELL] > 8.0f)
	{
		for (rx=-2; rx<3; rx++)
			for (ry=-2; ry<3; ry++)
				if (x+rx>=0 && y+ry>=0 && x+rx<XRES && y+ry<YRES && (rx || ry))
				{
					r = pmap[y+ry][x+rx];
					if ((r>>8)>=NPART || !r)
						continue;
					if ((r&0xFF)==PT_H2)
					{
						part_change_type(r>>8,x+rx,y+ry,PT_WATR);
						if (50<(rand()/(RAND_MAX/100))) {
							part_change_type(i,x,y,PT_WATR);
							rx = ry = 3;
						}
					}
				}
	}


	if (parts[i].tmp>=50)
	{
		create_part(i,x,y,PT_FIRE);
		parts[i].life+=(rand()/(RAND_MAX/100))+50;
		parts[i].temp+=(rand()/(RAND_MAX/100));
	}
	return 0;
}
