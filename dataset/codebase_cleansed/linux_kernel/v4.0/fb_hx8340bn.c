static int init_display(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->fbtftops.reset(par);
write_reg(par, 0xC1, 0xFF, 0x83, 0x40);
write_reg(par, 0x11);
mdelay(150);
write_reg(par, 0xCA, 0x70, 0x00, 0xD9);
write_reg(par, 0xB0, 0x01, 0x11);
write_reg(par, 0xC9, 0x90, 0x49, 0x10, 0x28, 0x28, 0x10, 0x00, 0x06);
mdelay(20);
write_reg(par, 0xB5, 0x35, 0x20, 0x45);
write_reg(par, 0xB4, 0x33, 0x25, 0x4C);
mdelay(10);
write_reg(par, 0x3A, 0x05);
write_reg(par, 0x29);
mdelay(10);
return 0;
}
void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, FBTFT_CASET, 0x00, xs, 0x00, xe);
write_reg(par, FBTFT_RASET, 0x00, ys, 0x00, ye);
write_reg(par, FBTFT_RAMWR);
}
static int set_var(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
#define MY (1 << 7)
#define MX (1 << 6)
#define MV (1 << 5)
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x36, (par->bgr << 3));
break;
case 270:
write_reg(par, 0x36, MX | MV | (par->bgr << 3));
break;
case 180:
write_reg(par, 0x36, MX | MY | (par->bgr << 3));
break;
case 90:
write_reg(par, 0x36, MY | MV | (par->bgr << 3));
break;
}
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
unsigned long mask[] = {
0b1111, 0b1111, 0b11111, 0b1111, 0b1111, 0b1111, 0b11111,
0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b11, 0b11,
0b1111, 0b1111, 0b11111, 0b1111, 0b1111, 0b1111, 0b11111,
0b111, 0b111, 0b111, 0b111, 0b111, 0b111, 0b0, 0b0 };
int i, j;
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
for (i = 0; i < par->gamma.num_curves; i++)
for (j = 0; j < par->gamma.num_values; j++)
CURVE(i, j) &= mask[i * par->gamma.num_values + j];
write_reg(par, 0x26, 1 << CURVE(1, 14));
if (CURVE(1, 14))
return 0;
write_reg(par, 0xC2,
(CURVE(0, 8) << 4) | CURVE(0, 7),
(CURVE(0, 10) << 4) | CURVE(0, 9),
(CURVE(0, 12) << 4) | CURVE(0, 11),
CURVE(0, 2),
(CURVE(0, 4) << 4) | CURVE(0, 3),
CURVE(0, 5),
CURVE(0, 6),
(CURVE(0, 1) << 4) | CURVE(0, 0),
(CURVE(0, 14) << 2) | CURVE(0, 13));
write_reg(par, 0xC3,
(CURVE(1, 8) << 4) | CURVE(1, 7),
(CURVE(1, 10) << 4) | CURVE(1, 9),
(CURVE(1, 12) << 4) | CURVE(1, 11),
CURVE(1, 2),
(CURVE(1, 4) << 4) | CURVE(1, 3),
CURVE(1, 5),
CURVE(1, 6),
(CURVE(1, 1) << 4) | CURVE(1, 0));
mdelay(10);
return 0;
}
