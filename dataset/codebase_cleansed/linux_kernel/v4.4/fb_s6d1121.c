static int init_display(struct fbtft_par *par)
{
par->fbtftops.reset(par);
if (par->gpio.cs != -1)
gpio_set_value(par->gpio.cs, 0);
write_reg(par, 0x0011, 0x2004);
write_reg(par, 0x0013, 0xCC00);
write_reg(par, 0x0015, 0x2600);
write_reg(par, 0x0014, 0x252A);
write_reg(par, 0x0012, 0x0033);
write_reg(par, 0x0013, 0xCC04);
write_reg(par, 0x0013, 0xCC06);
write_reg(par, 0x0013, 0xCC4F);
write_reg(par, 0x0013, 0x674F);
write_reg(par, 0x0011, 0x2003);
write_reg(par, 0x0016, 0x0007);
write_reg(par, 0x0002, 0x0013);
write_reg(par, 0x0003, 0x0003);
write_reg(par, 0x0001, 0x0127);
write_reg(par, 0x0008, 0x0303);
write_reg(par, 0x000A, 0x000B);
write_reg(par, 0x000B, 0x0003);
write_reg(par, 0x000C, 0x0000);
write_reg(par, 0x0041, 0x0000);
write_reg(par, 0x0050, 0x0000);
write_reg(par, 0x0060, 0x0005);
write_reg(par, 0x0070, 0x000B);
write_reg(par, 0x0071, 0x0000);
write_reg(par, 0x0078, 0x0000);
write_reg(par, 0x007A, 0x0000);
write_reg(par, 0x0079, 0x0007);
write_reg(par, 0x0007, 0x0051);
write_reg(par, 0x0007, 0x0053);
write_reg(par, 0x0079, 0x0000);
write_reg(par, 0x0022);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x0020, xs);
write_reg(par, 0x0021, ys);
break;
case 180:
write_reg(par, 0x0020, WIDTH - 1 - xs);
write_reg(par, 0x0021, HEIGHT - 1 - ys);
break;
case 270:
write_reg(par, 0x0020, WIDTH - 1 - ys);
write_reg(par, 0x0021, xs);
break;
case 90:
write_reg(par, 0x0020, ys);
write_reg(par, 0x0021, HEIGHT - 1 - xs);
break;
}
write_reg(par, 0x0022);
}
static int set_var(struct fbtft_par *par)
{
switch (par->info->var.rotate) {
case 0:
write_reg(par, 0x03, 0x0003 | (par->bgr << 12));
break;
case 180:
write_reg(par, 0x03, 0x0000 | (par->bgr << 12));
break;
case 270:
write_reg(par, 0x03, 0x000A | (par->bgr << 12));
break;
case 90:
write_reg(par, 0x03, 0x0009 | (par->bgr << 12));
break;
}
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
unsigned long mask[] = {
0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
0x3f, 0x3f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f,
};
int i, j;
for (i = 0; i < 2; i++)
for (j = 0; j < 14; j++)
CURVE(i, j) &= mask[i * par->gamma.num_values + j];
write_reg(par, 0x0030, CURVE(0, 1) << 8 | CURVE(0, 0));
write_reg(par, 0x0031, CURVE(0, 3) << 8 | CURVE(0, 2));
write_reg(par, 0x0032, CURVE(0, 5) << 8 | CURVE(0, 3));
write_reg(par, 0x0033, CURVE(0, 7) << 8 | CURVE(0, 6));
write_reg(par, 0x0034, CURVE(0, 9) << 8 | CURVE(0, 8));
write_reg(par, 0x0035, CURVE(0, 11) << 8 | CURVE(0, 10));
write_reg(par, 0x0036, CURVE(1, 1) << 8 | CURVE(1, 0));
write_reg(par, 0x0037, CURVE(1, 3) << 8 | CURVE(1, 2));
write_reg(par, 0x0038, CURVE(1, 5) << 8 | CURVE(1, 4));
write_reg(par, 0x0039, CURVE(1, 7) << 8 | CURVE(1, 6));
write_reg(par, 0x003A, CURVE(1, 9) << 8 | CURVE(1, 8));
write_reg(par, 0x003B, CURVE(1, 11) << 8 | CURVE(1, 10));
write_reg(par, 0x003C, CURVE(0, 13) << 8 | CURVE(0, 12));
write_reg(par, 0x003D, CURVE(1, 13) << 8 | CURVE(1, 12));
return 0;
}
