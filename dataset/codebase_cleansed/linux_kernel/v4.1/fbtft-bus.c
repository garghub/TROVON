void fbtft_write_reg8_bus9(struct fbtft_par *par, int len, ...)
{
va_list args;
int i, ret;
int pad = 0;
u16 *buf = (u16 *)par->buf;
if (unlikely(par->debug & DEBUG_WRITE_REGISTER)) {
va_start(args, len);
for (i = 0; i < len; i++)
*(((u8 *)buf) + i) = (u8)va_arg(args, unsigned int);
va_end(args);
fbtft_par_dbg_hex(DEBUG_WRITE_REGISTER, par,
par->info->device, u8, buf, len, "%s: ", __func__);
}
if (len <= 0)
return;
if (par->spi && (par->spi->bits_per_word == 8)) {
pad = (len % 4) ? 4 - (len % 4) : 0;
for (i = 0; i < pad; i++)
*buf++ = 0x000;
}
va_start(args, len);
*buf++ = (u8)va_arg(args, unsigned int);
i = len - 1;
while (i--) {
*buf = (u8)va_arg(args, unsigned int);
*buf++ |= 0x100;
}
va_end(args);
ret = par->fbtftops.write(par, par->buf, (len + pad) * sizeof(u16));
if (ret < 0) {
dev_err(par->info->device,
"write() failed and returned %d\n", ret);
return;
}
}
int fbtft_write_vmem16_bus8(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16;
u16 *txbuf16 = (u16 *)par->txbuf.buf;
size_t remain;
size_t to_copy;
size_t tx_array_size;
int i;
int ret = 0;
size_t startbyte_size = 0;
fbtft_par_dbg(DEBUG_WRITE_VMEM, par, "%s(offset=%zu, len=%zu)\n",
__func__, offset, len);
remain = len / 2;
vmem16 = (u16 *)(par->info->screen_base + offset);
if (par->gpio.dc != -1)
gpio_set_value(par->gpio.dc, 1);
if (!par->txbuf.buf)
return par->fbtftops.write(par, vmem16, len);
tx_array_size = par->txbuf.len / 2;
if (par->startbyte) {
txbuf16 = (u16 *)(par->txbuf.buf + 1);
tx_array_size -= 2;
*(u8 *)(par->txbuf.buf) = par->startbyte | 0x2;
startbyte_size = 1;
}
while (remain) {
to_copy = remain > tx_array_size ? tx_array_size : remain;
dev_dbg(par->info->device, " to_copy=%zu, remain=%zu\n",
to_copy, remain - to_copy);
for (i = 0; i < to_copy; i++)
txbuf16[i] = cpu_to_be16(vmem16[i]);
vmem16 = vmem16 + to_copy;
ret = par->fbtftops.write(par, par->txbuf.buf,
startbyte_size + to_copy * 2);
if (ret < 0)
return ret;
remain -= to_copy;
}
return ret;
}
int fbtft_write_vmem16_bus9(struct fbtft_par *par, size_t offset, size_t len)
{
u8 *vmem8;
u16 *txbuf16 = par->txbuf.buf;
size_t remain;
size_t to_copy;
size_t tx_array_size;
int i;
int ret = 0;
fbtft_par_dbg(DEBUG_WRITE_VMEM, par, "%s(offset=%zu, len=%zu)\n",
__func__, offset, len);
if (!par->txbuf.buf) {
dev_err(par->info->device, "%s: txbuf.buf is NULL\n", __func__);
return -1;
}
remain = len;
vmem8 = par->info->screen_base + offset;
tx_array_size = par->txbuf.len / 2;
while (remain) {
to_copy = remain > tx_array_size ? tx_array_size : remain;
dev_dbg(par->info->device, " to_copy=%zu, remain=%zu\n",
to_copy, remain - to_copy);
#ifdef __LITTLE_ENDIAN
for (i = 0; i < to_copy; i += 2) {
txbuf16[i] = 0x0100 | vmem8[i+1];
txbuf16[i+1] = 0x0100 | vmem8[i];
}
#else
for (i = 0; i < to_copy; i++)
txbuf16[i] = 0x0100 | vmem8[i];
#endif
vmem8 = vmem8 + to_copy;
ret = par->fbtftops.write(par, par->txbuf.buf, to_copy*2);
if (ret < 0)
return ret;
remain -= to_copy;
}
return ret;
}
int fbtft_write_vmem8_bus8(struct fbtft_par *par, size_t offset, size_t len)
{
dev_err(par->info->device, "%s: function not implemented\n", __func__);
return -1;
}
int fbtft_write_vmem16_bus16(struct fbtft_par *par, size_t offset, size_t len)
{
u16 *vmem16;
fbtft_par_dbg(DEBUG_WRITE_VMEM, par, "%s(offset=%zu, len=%zu)\n",
__func__, offset, len);
vmem16 = (u16 *)(par->info->screen_base + offset);
if (par->gpio.dc != -1)
gpio_set_value(par->gpio.dc, 1);
return par->fbtftops.write(par, vmem16, len);
}
