static int init_display(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->fbtftops.reset(par);
if (par->gpio.cs != -1)
gpio_set_value(par->gpio.cs, 0);
write_reg(par, 0x00, 0x0001);
write_reg(par, 0x03, 0xA8A4);
write_reg(par, 0x0C, 0x0000);
write_reg(par, 0x0D, 0x080C);
write_reg(par, 0x0E, 0x2B00);
write_reg(par, 0x1E, 0x00B7);
write_reg(par, 0x01,
(1 << 13) | (par->bgr << 11) | (1 << 9) | (HEIGHT - 1));
write_reg(par, 0x02, 0x0600);
write_reg(par, 0x10, 0x0000);
write_reg(par, 0x05, 0x0000);
write_reg(par, 0x06, 0x0000);
write_reg(par, 0x16, 0xEF1C);
write_reg(par, 0x17, 0x0003);
write_reg(par, 0x07, 0x0233);
write_reg(par, 0x0B, 0x0000);
write_reg(par, 0x0F, 0x0000);
write_reg(par, 0x41, 0x0000);
write_reg(par, 0x42, 0x0000);
write_reg(par, 0x48, 0x0000);
write_reg(par, 0x49, 0x013F);
write_reg(par, 0x4A, 0x0000);
write_reg(par, 0x4B, 0x0000);
write_reg(par, 0x44, 0xEF00);
write_reg(par, 0x45, 0x0000);
write_reg(par, 0x46, 0x013F);
write_reg(par, 0x23, 0x0000);
write_reg(par, 0x24, 0x0000);
write_reg(par, 0x25, 0x8000);
write_reg(par, 0x4f, 0x0000);
write_reg(par, 0x4e, 0x0000);
write_reg(par, 0x22);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x4e, xs);
write_reg(par, 0x4f, ys);
break;
case 180:
write_reg(par, 0x4e, par->info->var.xres - 1 - xs);
write_reg(par, 0x4f, par->info->var.yres - 1 - ys);
break;
case 270:
write_reg(par, 0x4e, par->info->var.yres - 1 - ys);
write_reg(par, 0x4f, xs);
break;
case 90:
write_reg(par, 0x4e, ys);
write_reg(par, 0x4f, par->info->var.xres - 1 - xs);
break;
}
write_reg(par, 0x22);
}
static int set_var(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
if (par->fbtftops.init_display != init_display) {
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par,
"%s: skipping since custom init_display() is used\n",
__func__);
return 0;
}
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x11, reg11 | 0b110000);
break;
case 270:
write_reg(par, 0x11, reg11 | 0b101000);
break;
case 180:
write_reg(par, 0x11, reg11 | 0b000000);
break;
case 90:
write_reg(par, 0x11, reg11 | 0b011000);
break;
}
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
unsigned long mask[] = {
0b11111, 0b11111, 0b111, 0b111, 0b111,
0b111, 0b111, 0b111, 0b111, 0b111,
0b11111, 0b11111, 0b111, 0b111, 0b111,
0b111, 0b111, 0b111, 0b111, 0b111 };
int i, j;
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
for (i = 0; i < 2; i++)
for (j = 0; j < 10; j++)
CURVE(i, j) &= mask[i*par->gamma.num_values + j];
write_reg(par, 0x0030, CURVE(0, 5) << 8 | CURVE(0, 4));
write_reg(par, 0x0031, CURVE(0, 7) << 8 | CURVE(0, 6));
write_reg(par, 0x0032, CURVE(0, 9) << 8 | CURVE(0, 8));
write_reg(par, 0x0033, CURVE(0, 3) << 8 | CURVE(0, 2));
write_reg(par, 0x0034, CURVE(1, 5) << 8 | CURVE(1, 4));
write_reg(par, 0x0035, CURVE(1, 7) << 8 | CURVE(1, 6));
write_reg(par, 0x0036, CURVE(1, 9) << 8 | CURVE(1, 8));
write_reg(par, 0x0037, CURVE(1, 3) << 8 | CURVE(1, 2));
write_reg(par, 0x003A, CURVE(0, 1) << 8 | CURVE(0, 0));
write_reg(par, 0x003B, CURVE(1, 1) << 8 | CURVE(1, 0));
return 0;
}
