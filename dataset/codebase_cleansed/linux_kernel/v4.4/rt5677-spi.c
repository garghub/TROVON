static u8 rt5677_spi_select_cmd(bool read, u32 align, u32 remain, u32 *len)
{
u8 cmd;
if (align == 2 || align == 6 || remain == 2) {
cmd = RT5677_SPI_READ_16;
*len = 2;
} else if (align == 4 || remain <= 6) {
cmd = RT5677_SPI_READ_32;
*len = 4;
} else {
cmd = RT5677_SPI_READ_BURST;
*len = min_t(u32, remain & ~7, RT5677_SPI_BURST_LEN);
}
return read ? cmd : cmd + 1;
}
static void rt5677_spi_reverse(u8 *dst, u32 dstlen, const u8 *src, u32 srclen)
{
u32 w, i, si;
u32 word_size = min_t(u32, dstlen, 8);
for (w = 0; w < dstlen; w += word_size) {
for (i = 0; i < word_size; i++) {
si = w + word_size - i - 1;
dst[w + i] = si < srclen ? src[si] : 0;
}
}
}
int rt5677_spi_read(u32 addr, void *rxbuf, size_t len)
{
u32 offset;
int status = 0;
struct spi_transfer t[2];
struct spi_message m;
u8 header[RT5677_SPI_HEADER + 4];
u8 body[RT5677_SPI_BURST_LEN];
u8 spi_cmd;
u8 *cb = rxbuf;
if (!g_spi)
return -ENODEV;
if ((addr & 1) || (len & 1)) {
dev_err(&g_spi->dev, "Bad read align 0x%x(%zu)\n", addr, len);
return -EACCES;
}
memset(t, 0, sizeof(t));
t[0].tx_buf = header;
t[0].len = sizeof(header);
t[0].speed_hz = RT5677_SPI_FREQ;
t[1].rx_buf = body;
t[1].speed_hz = RT5677_SPI_FREQ;
spi_message_init_with_transfers(&m, t, ARRAY_SIZE(t));
for (offset = 0; offset < len; offset += t[1].len) {
spi_cmd = rt5677_spi_select_cmd(true, (addr + offset) & 7,
len - offset, &t[1].len);
header[0] = spi_cmd;
header[1] = ((addr + offset) & 0xff000000) >> 24;
header[2] = ((addr + offset) & 0x00ff0000) >> 16;
header[3] = ((addr + offset) & 0x0000ff00) >> 8;
header[4] = ((addr + offset) & 0x000000ff) >> 0;
mutex_lock(&spi_mutex);
status |= spi_sync(g_spi, &m);
mutex_unlock(&spi_mutex);
rt5677_spi_reverse(cb + offset, t[1].len, body, t[1].len);
}
return status;
}
int rt5677_spi_write(u32 addr, const void *txbuf, size_t len)
{
u32 offset, len_with_pad = len;
int status = 0;
struct spi_transfer t;
struct spi_message m;
u8 buf[RT5677_SPI_HEADER + RT5677_SPI_BURST_LEN + 1];
u8 *body = buf + RT5677_SPI_HEADER;
u8 spi_cmd;
const u8 *cb = txbuf;
if (!g_spi)
return -ENODEV;
if (addr & 1) {
dev_err(&g_spi->dev, "Bad write align 0x%x(%zu)\n", addr, len);
return -EACCES;
}
if (len & 1)
len_with_pad = len + 1;
memset(&t, 0, sizeof(t));
t.tx_buf = buf;
t.speed_hz = RT5677_SPI_FREQ;
spi_message_init_with_transfers(&m, &t, 1);
for (offset = 0; offset < len_with_pad;) {
spi_cmd = rt5677_spi_select_cmd(false, (addr + offset) & 7,
len_with_pad - offset, &t.len);
buf[0] = spi_cmd;
buf[1] = ((addr + offset) & 0xff000000) >> 24;
buf[2] = ((addr + offset) & 0x00ff0000) >> 16;
buf[3] = ((addr + offset) & 0x0000ff00) >> 8;
buf[4] = ((addr + offset) & 0x000000ff) >> 0;
rt5677_spi_reverse(body, t.len, cb + offset, len - offset);
offset += t.len;
t.len += RT5677_SPI_HEADER + 1;
mutex_lock(&spi_mutex);
status |= spi_sync(g_spi, &m);
mutex_unlock(&spi_mutex);
}
return status;
}
int rt5677_spi_write_firmware(u32 addr, const struct firmware *fw)
{
return rt5677_spi_write(addr, fw->data, fw->size);
}
static int rt5677_spi_probe(struct spi_device *spi)
{
g_spi = spi;
return 0;
}
