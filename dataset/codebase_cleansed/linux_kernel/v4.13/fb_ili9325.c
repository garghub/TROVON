static int init_display(struct fbtft_par *par)
{
par->fbtftops.reset(par);
if (par->gpio.cs != -1)
gpio_set_value(par->gpio.cs, 0);
bt &= 0x07;
vc &= 0x07;
vrh &= 0x0f;
vdv &= 0x1f;
vcm &= 0x3f;
write_reg(par, 0x00E3, 0x3008);
write_reg(par, 0x00E7, 0x0012);
write_reg(par, 0x00EF, 0x1231);
write_reg(par, 0x0001, 0x0100);
write_reg(par, 0x0002, 0x0700);
write_reg(par, 0x0004, 0x0000);
write_reg(par, 0x0008, 0x0207);
write_reg(par, 0x0009, 0x0000);
write_reg(par, 0x000A, 0x0000);
write_reg(par, 0x000C, 0x0000);
write_reg(par, 0x000D, 0x0000);
write_reg(par, 0x000F, 0x0000);
write_reg(par, 0x0010, 0x0000);
write_reg(par, 0x0011, 0x0007);
write_reg(par, 0x0012, 0x0000);
write_reg(par, 0x0013, 0x0000);
mdelay(200);
write_reg(par, 0x0010,
BIT(12) | (bt << 8) | BIT(7) | BIT(4));
write_reg(par, 0x0011, 0x220 | vc);
mdelay(50);
write_reg(par, 0x0012, vrh);
mdelay(50);
write_reg(par, 0x0013, vdv << 8);
write_reg(par, 0x0029, vcm);
write_reg(par, 0x002B, 0x000C);
mdelay(50);
write_reg(par, 0x0020, 0x0000);
write_reg(par, 0x0021, 0x0000);
write_reg(par, 0x0050, 0x0000);
write_reg(par, 0x0051, 0x00EF);
write_reg(par, 0x0052, 0x0000);
write_reg(par, 0x0053, 0x013F);
write_reg(par, 0x0060, 0xA700);
write_reg(par, 0x0061, 0x0001);
write_reg(par, 0x006A, 0x0000);
write_reg(par, 0x0080, 0x0000);
write_reg(par, 0x0081, 0x0000);
write_reg(par, 0x0082, 0x0000);
write_reg(par, 0x0083, 0x0000);
write_reg(par, 0x0084, 0x0000);
write_reg(par, 0x0085, 0x0000);
write_reg(par, 0x0090, 0x0010);
write_reg(par, 0x0092, 0x0600);
write_reg(par, 0x0007, 0x0133);
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
write_reg(par, 0x03, 0x0030 | (par->bgr << 12));
break;
case 180:
write_reg(par, 0x03, 0x0000 | (par->bgr << 12));
break;
case 270:
write_reg(par, 0x03, 0x0028 | (par->bgr << 12));
break;
case 90:
write_reg(par, 0x03, 0x0018 | (par->bgr << 12));
break;
}
return 0;
}
static int set_gamma(struct fbtft_par *par, u32 *curves)
{
unsigned long mask[] = {
0x1f, 0x1f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
0x1f, 0x1f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
};
int i, j;
for (i = 0; i < 2; i++)
for (j = 0; j < 10; j++)
CURVE(i, j) &= mask[i * par->gamma.num_values + j];
write_reg(par, 0x0030, CURVE(0, 5) << 8 | CURVE(0, 4));
write_reg(par, 0x0031, CURVE(0, 7) << 8 | CURVE(0, 6));
write_reg(par, 0x0032, CURVE(0, 9) << 8 | CURVE(0, 8));
write_reg(par, 0x0035, CURVE(0, 3) << 8 | CURVE(0, 2));
write_reg(par, 0x0036, CURVE(0, 1) << 8 | CURVE(0, 0));
write_reg(par, 0x0037, CURVE(1, 5) << 8 | CURVE(1, 4));
write_reg(par, 0x0038, CURVE(1, 7) << 8 | CURVE(1, 6));
write_reg(par, 0x0039, CURVE(1, 9) << 8 | CURVE(1, 8));
write_reg(par, 0x003C, CURVE(1, 3) << 8 | CURVE(1, 2));
write_reg(par, 0x003D, CURVE(1, 1) << 8 | CURVE(1, 0));
return 0;
}
