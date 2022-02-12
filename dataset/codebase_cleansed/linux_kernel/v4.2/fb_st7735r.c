static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, 0x2A, xs >> 8, xs & 0xFF, xe >> 8, xe & 0xFF);
write_reg(par, 0x2B, ys >> 8, ys & 0xFF, ye >> 8, ye & 0xFF);
write_reg(par, 0x2C);
}
static int set_var(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x36, MX | MY | (par->bgr << 3));
break;
case 270:
write_reg(par, 0x36, MY | MV | (par->bgr << 3));
break;
case 180:
write_reg(par, 0x36, par->bgr << 3);
break;
case 90:
write_reg(par, 0x36, MX | MV | (par->bgr << 3));
break;
}
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
int i, j;
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
for (i = 0; i < par->gamma.num_curves; i++)
for (j = 0; j < par->gamma.num_values; j++)
CURVE(i, j) &= 0x3f;
for (i = 0; i < par->gamma.num_curves; i++)
write_reg(par, 0xE0 + i,
CURVE(i, 0), CURVE(i, 1), CURVE(i, 2), CURVE(i, 3),
CURVE(i, 4), CURVE(i, 5), CURVE(i, 6), CURVE(i, 7),
CURVE(i, 8), CURVE(i, 9), CURVE(i, 10), CURVE(i, 11),
CURVE(i, 12), CURVE(i, 13), CURVE(i, 14), CURVE(i, 15));
return 0;
}
