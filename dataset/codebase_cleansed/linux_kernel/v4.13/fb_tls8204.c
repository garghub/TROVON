static int init_display(struct fbtft_par *par)
{
par->fbtftops.reset(par);
write_reg(par, 0x21);
write_reg(par, 0x10 | (bs & 0x7));
write_reg(par, 0x04 | (64 >> 6));
write_reg(par, 0x40 | (64 & 0x3F));
write_reg(par, 0x20);
write_reg(par, 0x08 | 4);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
write_reg(par, 0x80);
write_reg(par, 0x40);
}
static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16 = (u16 *)par->info->screen_buffer;
int x, y, i;
int ret = 0;
for (y = 0; y < HEIGHT / 8; y++) {
u8 *buf = par->txbuf.buf;
gpio_set_value(par->gpio.dc, 0);
write_reg(par, 0x80 | 0);
write_reg(par, 0x40 | y);
for (x = 0; x < WIDTH; x++) {
u8 ch = 0;
for (i = 0; i < 8 * WIDTH; i += WIDTH) {
ch >>= 1;
if (vmem16[(y * 8 * WIDTH) + i + x])
ch |= 0x80;
}
*buf++ = ch;
}
gpio_set_value(par->gpio.dc, 1);
ret = par->fbtftops.write(par, par->txbuf.buf, WIDTH);
if (ret < 0) {
dev_err(par->info->device,
"write failed and returned: %d\n", ret);
break;
}
}
return ret;
}
static int set_gamma(struct fbtft_par *par, u32 *curves)
{
curves[0] &= 0x7F;
write_reg(par, 0x21);
write_reg(par, 0x80 | curves[0]);
write_reg(par, 0x20);
return 0;
}
