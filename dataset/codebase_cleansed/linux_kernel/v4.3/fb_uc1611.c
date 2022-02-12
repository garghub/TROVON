static int init_display(struct fbtft_par *par)
{
int ret;
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->spi->mode |= SPI_CS_HIGH;
ret = spi_setup(par->spi);
if (ret) {
dev_err(par->info->device, "Could not set SPI_CS_HIGH\n");
return ret;
}
write_reg(par, 0xE2);
write_reg(par, 0xE8 | (ratio & 0x03));
write_reg(par, 0x81);
write_reg(par, (gain & 0x03) << 6 | (pot & 0x3F));
write_reg(par, 0x24 | (temp & 0x03));
write_reg(par, 0x28 | (load & 0x03));
write_reg(par, 0x2C | (pump & 0x03));
write_reg(par, 0xA6 | (0x01 & 0x01));
write_reg(par, 0xD0 | (0x02 & 0x03));
write_reg(par, 0xA8 | 0x07);
return 0;
}
static void set_addr_win(struct fbtft_par *par, int xs, int ys, int xe, int ye)
{
fbtft_par_dbg(DEBUG_SET_ADDR_WIN, par,
"%s(xs=%d, ys=%d, xe=%d, ye=%d)\n",
__func__, xs, ys, xe, ye);
switch (par->info->var.rotate) {
case 90:
case 270:
write_reg(par, ys & 0x0F);
write_reg(par, 0x10 | (ys >> 4));
write_reg(par, 0x60 | ((xs >> 1) & 0x0F));
write_reg(par, 0x70 | (xs >> 5));
break;
default:
write_reg(par, xs & 0x0F);
write_reg(par, 0x10 | (xs >> 4));
write_reg(par, 0x60 | ((ys >> 1) & 0x0F));
write_reg(par, 0x70 | (ys >> 5));
break;
}
}
static int blank(struct fbtft_par *par, bool on)
{
fbtft_par_dbg(DEBUG_BLANK, par, "%s(blank=%s)\n",
__func__, on ? "true" : "false");
if (on)
write_reg(par, 0xA8 | 0x00);
else
write_reg(par, 0xA8 | 0x07);
return 0;
}
static int set_var(struct fbtft_par *par)
{
fbtft_par_dbg(DEBUG_INIT_DISPLAY, par, "%s()\n", __func__);
par->info->var.grayscale = 1;
par->info->var.red.offset = 0;
par->info->var.red.length = 8;
par->info->var.green.offset = 0;
par->info->var.green.length = 8;
par->info->var.blue.offset = 0;
par->info->var.blue.length = 8;
par->info->var.transp.offset = 0;
par->info->var.transp.length = 0;
switch (par->info->var.rotate) {
case 90:
write_reg(par, 0x88
| (0x0 & 0x1) << 2
| (0x1 & 0x1) << 1
| (0x1 & 0x1));
write_reg(par, 0xC0
| (0x0 & 0x1) << 2
| (0x0 & 0x1) << 1
| (0x0 & 0x1));
break;
case 180:
write_reg(par, 0x88
| (0x0 & 0x1) << 2
| (0x0 & 0x1) << 1
| (0x1 & 0x1));
write_reg(par, 0xC0
| (0x1 & 0x1) << 2
| (0x0 & 0x1) << 1
| (0x0 & 0x1));
break;
case 270:
write_reg(par, 0x88
| (0x0 & 0x1) << 2
| (0x1 & 0x1) << 1
| (0x1 & 0x1));
write_reg(par, 0xC0
| (0x1 & 0x1) << 2
| (0x1 & 0x1) << 1
| (0x0 & 0x1));
break;
default:
write_reg(par, 0x88
| (0x0 & 0x1) << 2
| (0x0 & 0x1) << 1
| (0x1 & 0x1));
write_reg(par, 0xC0
| (0x0 & 0x1) << 2
| (0x1 & 0x1) << 1
| (0x0 & 0x1));
break;
}
return 0;
}
static int write_vmem(struct fbtft_par *par, size_t offset, size_t len)
{
u8 *vmem8 = (u8 *)(par->info->screen_base);
u8 *buf8 = (u8 *)(par->txbuf.buf);
u16 *buf16 = (u16 *)(par->txbuf.buf);
int line_length = par->info->fix.line_length;
int y_start = (offset / line_length);
int y_end = (offset + len - 1) / line_length;
int x, y, i;
int ret = 0;
fbtft_par_dbg(DEBUG_WRITE_VMEM, par, "%s()\n", __func__);
switch (par->pdata->display.buswidth) {
case 8:
switch (par->info->var.rotate) {
case 90:
case 270:
i = y_start * line_length;
for (y = y_start; y <= y_end; y++) {
for (x = 0; x < line_length; x += 2) {
*buf8 = vmem8[i] >> 4;
*buf8 |= vmem8[i + 1] & 0xF0;
buf8++;
i += 2;
}
}
break;
default:
y_start &= 0xFE;
i = y_start * line_length;
for (y = y_start; y <= y_end; y += 2) {
for (x = 0; x < line_length; x++) {
*buf8 = vmem8[i] >> 4;
*buf8 |= vmem8[i + line_length] & 0xF0;
buf8++;
i++;
}
i += line_length;
}
break;
}
gpio_set_value(par->gpio.dc, 1);
ret = par->fbtftops.write(par, par->txbuf.buf, len / 2);
break;
case 9:
switch (par->info->var.rotate) {
case 90:
case 270:
i = y_start * line_length;
for (y = y_start; y <= y_end; y++) {
for (x = 0; x < line_length; x += 2) {
*buf16 = 0x100;
*buf16 |= vmem8[i] >> 4;
*buf16 |= vmem8[i + 1] & 0xF0;
buf16++;
i += 2;
}
}
break;
default:
y_start &= 0xFE;
i = y_start * line_length;
for (y = y_start; y <= y_end; y += 2) {
for (x = 0; x < line_length; x++) {
*buf16 = 0x100;
*buf16 |= vmem8[i] >> 4;
*buf16 |= vmem8[i + line_length] & 0xF0;
buf16++;
i++;
}
i += line_length;
}
break;
}
ret = par->fbtftops.write(par, par->txbuf.buf, len);
break;
default:
dev_err(par->info->device, "unsupported buswidth %d\n",
par->pdata->display.buswidth);
}
if (ret < 0)
dev_err(par->info->device, "write failed and returned: %d\n",
ret);
return ret;
}
