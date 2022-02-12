static int init_display(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->fbtftops.reset(par);
write_reg(par, 0x21);
write_reg(par, 0x04 | (tc & 0x3));
write_reg(par, 0x10 | (bs & 0x7));
write_reg(par, 0x22);
write_reg(par, 0x08 | 4);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par, "%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, 0x80);
write_reg(par, 0x40);
}
static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16 = (u16 *)par->info->screen_base;
u8 *buf = par->txbuf.buf;
int x, y, i;
int ret = 0;
fbtft_par_dbg(DEBUG_WRITE_VMEM, par, "%s()\n", __func__);
for (x = 0; x < 84; x++) {
for (y = 0; y < 6; y++) {
*buf = 0x00;
for (i = 0; i < 8; i++) {
*buf |= (vmem16[(y*8+i)*84+x] ? 1 : 0) << i;
}
buf++;
}
}
gpio_set_value(par->gpio.dc, 1);
ret = par->fbtftops.write(par, par->txbuf.buf, 6*84);
if (ret < 0)
dev_err(par->info->device, "%s: write failed and returned: %d\n", __func__, ret);
return ret;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
curves[0] &= 0x7F;
write_reg(par, 0x23);
write_reg(par, 0x80 | curves[0]);
write_reg(par, 0x22);
return 0;
}
