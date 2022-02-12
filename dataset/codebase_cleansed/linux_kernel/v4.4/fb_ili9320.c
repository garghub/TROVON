static unsigned read_devicecode(struct fbtft_par *par)
{
int ret;
u8 rxbuf[8] = {0, };
write_reg(par, 0x0000);
ret = par->fbtftops.read(par, rxbuf, 4);
return (rxbuf[2] << 8) | rxbuf[3];
}
static int init_display(struct fbtft_par *par)
{
unsigned devcode;
par->fbtftops.reset(par);
devcode = read_devicecode(par);
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "Device code: 0x%04X\n",
devcode);
if ((devcode != 0x0000) && (devcode != 0x9320))
dev_warn(par->info->device,
"Unrecognized Device code: 0x%04X (expected 0x9320)\n",
devcode);
write_reg(par, 0x00E5, 0x8000);
write_reg(par, 0x0000, 0x0001);
write_reg(par, 0x0001, 0x0100);
write_reg(par, 0x0002, 0x0700);
write_reg(par, 0x0004, 0x0000);
write_reg(par, 0x0008, 0x0202);
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
write_reg(par, 0x0010, 0x17B0);
write_reg(par, 0x0011, 0x0031);
mdelay(50);
write_reg(par, 0x0012, 0x0138);
mdelay(50);
write_reg(par, 0x0013, 0x1800);
write_reg(par, 0x0029, 0x0008);
mdelay(50);
write_reg(par, 0x0020, 0x0000);
write_reg(par, 0x0021, 0x0000);
write_reg(par, 0x0050, 0x0000);
write_reg(par, 0x0051, 0x00EF);
write_reg(par, 0x0052, 0x0000);
write_reg(par, 0x0053, 0x013F);
write_reg(par, 0x0060, 0x2700);
write_reg(par, 0x0061, 0x0001);
write_reg(par, 0x006A, 0x0000);
write_reg(par, 0x0080, 0x0000);
write_reg(par, 0x0081, 0x0000);
write_reg(par, 0x0082, 0x0000);
write_reg(par, 0x0083, 0x0000);
write_reg(par, 0x0084, 0x0000);
write_reg(par, 0x0085, 0x0000);
write_reg(par, 0x0090, 0x0010);
write_reg(par, 0x0092, 0x0000);
write_reg(par, 0x0093, 0x0003);
write_reg(par, 0x0095, 0x0110);
write_reg(par, 0x0097, 0x0000);
write_reg(par, 0x0098, 0x0000);
write_reg(par, 0x0007, 0x0173);
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
write_reg(par, 0x3, (par->bgr << 12) | 0x30);
break;
case 270:
write_reg(par, 0x3, (par->bgr << 12) | 0x28);
break;
case 180:
write_reg(par, 0x3, (par->bgr << 12) | 0x00);
break;
case 90:
write_reg(par, 0x3, (par->bgr << 12) | 0x18);
break;
}
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
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
