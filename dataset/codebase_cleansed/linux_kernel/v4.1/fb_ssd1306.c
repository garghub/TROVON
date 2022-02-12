static int init_display(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->fbtftops.reset(par);
if (par->gamma.curves[0] == 0) {
mutex_lock(&par->gamma.lock);
if (par->info->var.yres == 64)
par->gamma.curves[0] = 0xCF;
else
par->gamma.curves[0] = 0x8F;
mutex_unlock(&par->gamma.lock);
}
write_reg(par, 0xAE);
write_reg(par, 0xD5);
write_reg(par, 0x80);
write_reg(par, 0xA8);
if (par->info->var.yres == 64)
write_reg(par, 0x3F);
else
write_reg(par, 0x1F);
write_reg(par, 0xD3);
write_reg(par, 0x0);
write_reg(par, 0x40 | 0x0);
write_reg(par, 0x8D);
write_reg(par, 0x14);
write_reg(par, 0x20);
write_reg(par, 0x01);
write_reg(par, 0xA0 | 0x1);
write_reg(par, 0xC8);
write_reg(par, 0xDA);
if (par->info->var.yres == 64)
write_reg(par, 0x12);
else
write_reg(par, 0x02);
write_reg(par, 0xD9);
write_reg(par, 0xF1);
write_reg(par, 0xDB);
write_reg(par, 0x40);
write_reg(par, 0xA4);
write_reg(par, 0xA6);
write_reg(par, 0xAF);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe, ye);
write_reg(par, 0x00 | 0x0);
write_reg(par, 0x10 | 0x0);
write_reg(par, 0x40 | 0x0);
}
static int blank(struct fbtft_par *par, bool on)
{
fbtft_par_dbg(DEBUG_BLANK, par, "%s(blank=%s)\n",
__func__, on ? "true" : "false");
if (on)
write_reg(par, 0xAE);
else
write_reg(par, 0xAF);
return 0;
}
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
curves[0] &= 0xFF;
write_reg(par, 0x81);
write_reg(par, curves[0]);
return 0;
}
static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16 = (u16 *)par->info->screen_base;
u8 *buf = par->txbuf.buf;
int x, y, i;
int ret = 0;
fbtft_par_dbg(DEBUG_WRITE_VMEM, par, "%s()\n", __func__);
for (x = 0; x < par->info->var.xres; x++) {
for (y = 0; y < par->info->var.yres/8; y++) {
*buf = 0x00;
for (i = 0; i < 8; i++)
*buf |= (vmem16[(y*8+i)*par->info->var.xres+x] ? 1 : 0) << i;
buf++;
}
}
gpio_set_value(par->gpio.dc, 1);
ret = par->fbtftops.write(par, par->txbuf.buf,
par->info->var.xres*par->info->var.yres/8);
if (ret < 0)
dev_err(par->info->device, "write failed and returned: %d\n",
ret);
return ret;
}
