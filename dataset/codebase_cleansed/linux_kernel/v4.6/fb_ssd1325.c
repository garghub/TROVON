static int init_display(struct fbtft_par *par)
{
par->fbtftops.reset(par);
gpio_set_value(par->gpio.cs, 0);
write_reg(par, 0xb3);
write_reg(par, 0xf0);
write_reg(par, 0xae);
write_reg(par, 0xa1);
write_reg(par, 0x00);
write_reg(par, 0xa8);
write_reg(par, 0x3f);
write_reg(par, 0xa0);
write_reg(par, 0x45);
write_reg(par, 0xa2);
write_reg(par, 0x40);
write_reg(par, 0x75);
write_reg(par, 0x00);
write_reg(par, 0x3f);
write_reg(par, 0x15);
write_reg(par, 0x00);
write_reg(par, 0x7f);
write_reg(par, 0xa4);
write_reg(par, 0xaf);
return 0;
}
static uint8_t rgb565_to_g16(u16 pixel)
{
u16 b = pixel & 0x1f;
u16 g = (pixel & (0x3f << 5)) >> 5;
u16 r = (pixel & (0x1f << (5 + 6))) >> (5 + 6);
pixel = (299 * r + 587 * g + 114 * b) / 195;
if (pixel > 255)
pixel = 255;
return (uint8_t)pixel / 16;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n", __func__, xs, ys, xe,
ye);
write_reg(par, 0x75);
write_reg(par, 0x00);
write_reg(par, 0x3f);
write_reg(par, 0x15);
write_reg(par, 0x00);
write_reg(par, 0x7f);
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
int i;
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
for (i = 0; i < GAMMA_LEN; i++) {
if (i > 0 && curves[i] < 1) {
dev_err(par->info->device,
"Illegal value in Grayscale Lookup Table at index %d.\n"
"Must be greater than 0\n", i);
return -EINVAL;
}
if (curves[i] > 7) {
dev_err(par->info->device,
"Illegal value(s) in Grayscale Lookup Table.\n"
"At index=%d, the accumulated value has exceeded 7\n",
i);
return -EINVAL;
}
}
write_reg(par, 0xB8);
for (i = 0; i < 8; i++)
write_reg(par, (curves[i] & 0xFF));
return 0;
}
static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16 = (u16 *)par->info->screen_buffer;
u8 *buf = par->txbuf.buf;
u8 n1;
u8 n2;
int y, x;
int ret;
for (x = 0; x < par->info->var.xres; x++) {
if (x % 2)
continue;
for (y = 0; y < par->info->var.yres; y++) {
n1 = rgb565_to_g16(vmem16[y * par->info->var.xres + x]);
n2 = rgb565_to_g16(vmem16
[y * par->info->var.xres + x + 1]);
*buf = (n1 << 4) | n2;
buf++;
}
}
gpio_set_value(par->gpio.dc, 1);
ret = par->fbtftops.write(par, par->txbuf.buf,
par->info->var.xres * par->info->var.yres / 2);
if (ret < 0)
dev_err(par->info->device,
"%s: write failed and returned: %d\n", __func__, ret);
return ret;
}
