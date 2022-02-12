static int init_display(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->fbtftops.reset(par);
write_reg(par, 0x01);
mdelay(5);
write_reg(par, 0x28);
write_reg(par, 0xCF, 0x00, 0x83, 0x30);
write_reg(par, 0xED, 0x64, 0x03, 0x12, 0x81);
write_reg(par, 0xE8, 0x85, 0x01, 0x79);
write_reg(par, 0xCB, 0x39, 0X2C, 0x00, 0x34, 0x02);
write_reg(par, 0xF7, 0x20);
write_reg(par, 0xEA, 0x00, 0x00);
write_reg(par, 0xC0, 0x26);
write_reg(par, 0xC1, 0x11);
write_reg(par, 0xC5, 0x35, 0x3E);
write_reg(par, 0xC7, 0xBE);
write_reg(par, 0x3A, 0x55);
write_reg(par, 0xB1, 0x00, 0x1B);
write_reg(par, 0x26, 0x01);
write_reg(par, 0xB7, 0x07);
write_reg(par, 0xB6, 0x0A, 0x82, 0x27, 0x00);
write_reg(par, 0x11);
mdelay(100);
write_reg(par, 0x29);
mdelay(20);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, 0x2A,
(xs >> 8) & 0xFF, xs & 0xFF, (xe >> 8) & 0xFF, xe & 0xFF);
write_reg(par, 0x2B,
(ys >> 8) & 0xFF, ys & 0xFF, (ye >> 8) & 0xFF, ye & 0xFF);
write_reg(par, 0x2C);
}
static int set_var(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x36, (1 << MEM_X) | (par->bgr << MEM_BGR));
break;
case 270:
write_reg(par, 0x36,
(1<<MEM_V) | (1 << MEM_L) | (par->bgr << MEM_BGR));
break;
case 180:
write_reg(par, 0x36, (1 << MEM_Y) | (par->bgr << MEM_BGR));
break;
case 90:
write_reg(par, 0x36, (1 << MEM_Y) | (1 << MEM_X) |
(1 << MEM_V) | (par->bgr << MEM_BGR));
break;
}
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
int i;
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
for (i = 0; i < par->gamma.num_curves; i++)
write_reg(par, 0xE0 + i,
CURVE(i, 0), CURVE(i, 1), CURVE(i, 2),
CURVE(i, 3), CURVE(i, 4), CURVE(i, 5),
CURVE(i, 6), CURVE(i, 7), CURVE(i, 8),
CURVE(i, 9), CURVE(i, 10), CURVE(i, 11),
CURVE(i, 12), CURVE(i, 13), CURVE(i, 14));
return 0;
}
