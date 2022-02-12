static int init_display(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->fbtftops.reset(par);
write_reg(par, 0xEA, 0x00);
write_reg(par, 0xEB, 0x20);
write_reg(par, 0xEC, 0x0C);
write_reg(par, 0xED, 0xC4);
write_reg(par, 0xE8, 0x40);
write_reg(par, 0xE9, 0x38);
write_reg(par, 0xF1, 0x01);
write_reg(par, 0xF2, 0x10);
write_reg(par, 0x27, 0xA3);
write_reg(par, 0x1B, 0x1B);
write_reg(par, 0x1A, 0x01);
write_reg(par, 0x24, 0x2F);
write_reg(par, 0x25, 0x57);
write_reg(par, 0x23, 0x8D);
write_reg(par, 0x18, 0x36);
write_reg(par, 0x19, 0x01);
write_reg(par, 0x01, 0x00);
write_reg(par, 0x1F, 0x88);
mdelay(5);
write_reg(par, 0x1F, 0x80);
mdelay(5);
write_reg(par, 0x1F, 0x90);
mdelay(5);
write_reg(par, 0x1F, 0xD0);
mdelay(5);
write_reg(par, 0x17, 0x05);
write_reg(par, 0x36, 0x00);
write_reg(par, 0x28, 0x38);
mdelay(40);
write_reg(par, 0x28, 0x3C);
write_reg(par, 0x16, 0x60 | (par->bgr << 3));
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, 0x02, (xs >> 8) & 0xFF);
write_reg(par, 0x03, xs & 0xFF);
write_reg(par, 0x04, (xe >> 8) & 0xFF);
write_reg(par, 0x05, xe & 0xFF);
write_reg(par, 0x06, (ys >> 8) & 0xFF);
write_reg(par, 0x07, ys & 0xFF);
write_reg(par, 0x08, (ye >> 8) & 0xFF);
write_reg(par, 0x09, ye & 0xFF);
write_reg(par, 0x22);
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
unsigned long mask[] = {
0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x1f, 0x1f,
0x1f, 0x1f, 0x1f, 0x0f,
};
int i, j;
int acc = 0;
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
for (i = 0; i < par->gamma.num_curves; i++)
for (j = 0; j < par->gamma.num_values; j++) {
acc += CURVE(i, j);
CURVE(i, j) &= mask[j];
}
if (acc == 0)
return 0;
for (i = 0; i < par->gamma.num_curves; i++) {
write_reg(par, 0x40 + (i * 0x10), CURVE(i, 0));
write_reg(par, 0x41 + (i * 0x10), CURVE(i, 1));
write_reg(par, 0x42 + (i * 0x10), CURVE(i, 2));
write_reg(par, 0x43 + (i * 0x10), CURVE(i, 3));
write_reg(par, 0x44 + (i * 0x10), CURVE(i, 4));
write_reg(par, 0x45 + (i * 0x10), CURVE(i, 5));
write_reg(par, 0x46 + (i * 0x10), CURVE(i, 6));
write_reg(par, 0x47 + (i * 0x10), CURVE(i, 7));
write_reg(par, 0x48 + (i * 0x10), CURVE(i, 8));
write_reg(par, 0x49 + (i * 0x10), CURVE(i, 9));
write_reg(par, 0x4A + (i * 0x10), CURVE(i, 10));
write_reg(par, 0x4B + (i * 0x10), CURVE(i, 11));
write_reg(par, 0x4C + (i * 0x10), CURVE(i, 12));
}
write_reg(par, 0x5D, (CURVE(1, 0) << 4) | CURVE(0, 0));
return 0;
}
