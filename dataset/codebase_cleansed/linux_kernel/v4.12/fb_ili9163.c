static int init_display(struct fbtft_par *par)
{
par->fbtftops.reset(par);
if (par->gpio.cs != -1)
gpio_set_value(par->gpio.cs, 0);
write_reg(par, MIPI_DCS_SOFT_RESET);
mdelay(500);
write_reg(par, MIPI_DCS_EXIT_SLEEP_MODE);
mdelay(5);
write_reg(par, MIPI_DCS_SET_PIXEL_FORMAT, MIPI_DCS_PIXEL_FMT_16BIT);
write_reg(par, MIPI_DCS_SET_GAMMA_CURVE, 0x02);
#ifdef GAMMA_ADJ
write_reg(par, CMD_GAMRSEL, 0x01);
#endif
write_reg(par, MIPI_DCS_ENTER_NORMAL_MODE);
write_reg(par, CMD_DFUNCTR, 0xff, 0x06);
write_reg(par, CMD_FRMCTR1, 0x08, 0x02);
write_reg(par, CMD_DINVCTR, 0x07);
write_reg(par, CMD_PWCTR1, 0x0A, 0x02);
write_reg(par, CMD_PWCTR2, 0x02);
write_reg(par, CMD_VCOMCTR1, 0x50, 0x63);
write_reg(par, CMD_VCOMOFFS, 0);
write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS, 0, 0, 0, WIDTH);
write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS, 0, 0, 0, HEIGHT);
write_reg(par, MIPI_DCS_SET_DISPLAY_ON);
write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys,
int xe, int ye)
{
switch (par->info->var.rotate) {
case 0:
write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
xs >> 8, xs & 0xff, xe >> 8, xe & 0xff);
write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
(ys + __OFFSET) >> 8, (ys + __OFFSET) & 0xff,
(ye + __OFFSET) >> 8, (ye + __OFFSET) & 0xff);
break;
case 90:
write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
(xs + __OFFSET) >> 8, (xs + __OFFSET) & 0xff,
(xe + __OFFSET) >> 8, (xe + __OFFSET) & 0xff);
write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
ys >> 8, ys & 0xff, ye >> 8, ye & 0xff);
break;
case 180:
case 270:
write_reg(par, MIPI_DCS_SET_COLUMN_ADDRESS,
xs >> 8, xs & 0xff, xe >> 8, xe & 0xff);
write_reg(par, MIPI_DCS_SET_PAGE_ADDRESS,
ys >> 8, ys & 0xff, ye >> 8, ye & 0xff);
break;
default:
par->info->var.rotate = 0;
}
write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
}
static int set_var(struct fbtft_par *par)
{
u8 mactrl_data = 0;
switch (par->info->var.rotate) {
case 0:
mactrl_data = 0x08;
break;
case 180:
mactrl_data = 0xC8;
break;
case 270:
mactrl_data = 0xA8;
break;
case 90:
mactrl_data = 0x68;
break;
}
if (par->bgr)
mactrl_data |= BIT(2);
write_reg(par, MIPI_DCS_SET_ADDRESS_MODE, mactrl_data);
write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
return 0;
}
static int gamma_adj(struct fbtft_par *par, u32 *curves)
{
unsigned long mask[] = {
0x3F, 0x3F, 0x3F, 0x3F, 0x3F,
0x1f, 0x3f, 0x0f, 0x0f, 0x7f, 0x1f,
0x3F, 0x3F, 0x3F, 0x3F, 0x3F};
int i, j;
for (i = 0; i < GAMMA_NUM; i++)
for (j = 0; j < GAMMA_LEN; j++)
CURVE(i, j) &= mask[i * par->gamma.num_values + j];
write_reg(par, CMD_PGAMMAC,
CURVE(0, 0),
CURVE(0, 1),
CURVE(0, 2),
CURVE(0, 3),
CURVE(0, 4),
CURVE(0, 5),
CURVE(0, 6),
(CURVE(0, 7) << 4) | CURVE(0, 8),
CURVE(0, 9),
CURVE(0, 10),
CURVE(0, 11),
CURVE(0, 12),
CURVE(0, 13),
CURVE(0, 14),
CURVE(0, 15));
write_reg(par, MIPI_DCS_WRITE_MEMORY_START);
return 0;
}
