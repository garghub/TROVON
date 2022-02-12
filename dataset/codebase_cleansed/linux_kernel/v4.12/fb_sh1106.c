static int init_display(struct fbtft_par *par)
{
if (!par->info->var.xres || par->info->var.xres > WIDTH ||
!par->info->var.yres || par->info->var.yres > HEIGHT ||
par->info->var.yres % 8) {
dev_err(par->info->device, "Invalid screen size\n");
return -EINVAL;
}
if (par->info->var.rotate) {
dev_err(par->info->device, "Display rotation not supported\n");
return -EINVAL;
}
par->fbtftops.reset(par);
write_reg(par, 0xAE);
write_reg(par, 0xD5, 0x80);
write_reg(par, 0xA8, par->info->var.yres - 1);
write_reg(par, 0xD3, 0x00);
write_reg(par, 0x40 | 0x0);
write_reg(par, 0xA0 | 0x1);
write_reg(par, 0xC8);
if (par->info->var.yres == 64)
write_reg(par, 0xDA, 0x12);
else if (par->info->var.yres == 48)
write_reg(par, 0xDA, 0x12);
else
write_reg(par, 0xDA, 0x02);
write_reg(par, 0xD9, 0xF1);
write_reg(par, 0xDB, 0x40);
write_reg(par, 0xAF);
msleep(150);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
}
static int blank(struct fbtft_par *par, bool on)
{
fbtft_par_dbg(DEBUG_BLANK, par, "%s(blank=%s)\n",
__func__, on ? "true" : "false");
write_reg(par, on ? 0xAE : 0xAF);
return 0;
}
static int set_gamma(struct fbtft_par *par, u32 *curves)
{
curves[0] &= 0xFF;
write_reg(par, 0x81, curves[0]);
return 0;
}
static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16 = (u16 *)par->info->screen_buffer;
u32 xres = par->info->var.xres;
int page, page_start, page_end, x, i, ret;
u8 *buf = par->txbuf.buf;
page_start = offset / (8 * 2 * xres);
page_end = DIV_ROUND_UP(offset + len, 8 * 2 * xres);
for (page = page_start; page < page_end; page++) {
write_reg(par, 0xb0 | page, 0x00 | 2, 0x10 | 0);
memset(buf, 0, xres);
for (x = 0; x < xres; x++)
for (i = 0; i < 8; i++)
if (vmem16[(page * 8 + i) * xres + x])
buf[x] |= BIT(i);
ret = fbtft_write_buf_dc(par, buf, xres, 1);
if (ret < 0)
return ret;
}
return 0;
}
static void write_register(struct fbtft_par *par, int len, ...)
{
va_list args;
int i;
va_start(args, len);
for (i = 0; i < len; i++)
par->buf[i] = va_arg(args, unsigned int);
fbtft_write_buf_dc(par, par->buf, len, 0);
va_end(args);
}
