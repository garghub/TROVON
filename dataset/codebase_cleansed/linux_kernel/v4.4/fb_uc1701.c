static int init_display(struct fbtft_par *par)
{
par->fbtftops.reset(par);
write_reg(par, LCD_RESET_CMD);
mdelay(10);
write_reg(par, LCD_START_LINE);
write_reg(par, LCD_BOTTOMVIEW | 1);
write_reg(par, LCD_SCAN_DIR | 0x00);
write_reg(par, LCD_ALL_PIXEL | 0);
write_reg(par, LCD_DISPLAY_INVERT | 0);
write_reg(par, LCD_BIAS | 0);
write_reg(par, LCD_POWER_CONTROL | 0x07);
write_reg(par, LCD_VOLTAGE | 0x07);
write_reg(par, LCD_VOLUME_MODE);
write_reg(par, 0x09);
write_reg(par, LCD_NO_OP);
write_reg(par, LCD_ADV_PROG_CTRL);
write_reg(par, LCD_ADV_PROG_CTRL2 | LCD_TEMPCOMP_HIGH);
write_reg(par, LCD_DISPLAY_ENABLE | 1);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
write_reg(par, LCD_PAGE_ADDRESS);
write_reg(par, 0x00);
write_reg(par, LCD_COL_ADDRESS);
}
static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16 = (u16 *)par->info->screen_buffer;
u8 *buf = par->txbuf.buf;
int x, y, i;
int ret = 0;
for (y = 0; y < PAGES; y++) {
buf = par->txbuf.buf;
for (x = 0; x < WIDTH; x++) {
*buf = 0x00;
for (i = 0; i < 8; i++)
*buf |= (vmem16[((y * 8 * WIDTH) +
(i * WIDTH)) + x] ?
1 : 0) << i;
buf++;
}
write_reg(par, LCD_PAGE_ADDRESS | (u8)y);
write_reg(par, 0x00);
write_reg(par, LCD_COL_ADDRESS);
gpio_set_value(par->gpio.dc, 1);
ret = par->fbtftops.write(par, par->txbuf.buf, WIDTH);
gpio_set_value(par->gpio.dc, 0);
}
if (ret < 0)
dev_err(par->info->device, "write failed and returned: %d\n",
ret);
return ret;
}
