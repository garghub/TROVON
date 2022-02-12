static unsigned bitbang_txrx_8(
struct spi_device *spi,
u32 (*txrx_word)(struct spi_device *spi,
unsigned nsecs,
u32 word, u8 bits),
unsigned ns,
struct spi_transfer *t
) {
unsigned bits = t->bits_per_word;
unsigned count = t->len;
const u8 *tx = t->tx_buf;
u8 *rx = t->rx_buf;
while (likely(count > 0)) {
u8 word = 0;
if (tx)
word = *tx++;
word = txrx_word(spi, ns, word, bits);
if (rx)
*rx++ = word;
count -= 1;
}
return t->len - count;
}
static unsigned bitbang_txrx_16(
struct spi_device *spi,
u32 (*txrx_word)(struct spi_device *spi,
unsigned nsecs,
u32 word, u8 bits),
unsigned ns,
struct spi_transfer *t
) {
unsigned bits = t->bits_per_word;
unsigned count = t->len;
const u16 *tx = t->tx_buf;
u16 *rx = t->rx_buf;
while (likely(count > 1)) {
u16 word = 0;
if (tx)
word = *tx++;
word = txrx_word(spi, ns, word, bits);
if (rx)
*rx++ = word;
count -= 2;
}
return t->len - count;
}
static unsigned bitbang_txrx_32(
struct spi_device *spi,
u32 (*txrx_word)(struct spi_device *spi,
unsigned nsecs,
u32 word, u8 bits),
unsigned ns,
struct spi_transfer *t
) {
unsigned bits = t->bits_per_word;
unsigned count = t->len;
const u32 *tx = t->tx_buf;
u32 *rx = t->rx_buf;
while (likely(count > 3)) {
u32 word = 0;
if (tx)
word = *tx++;
word = txrx_word(spi, ns, word, bits);
if (rx)
*rx++ = word;
count -= 4;
}
return t->len - count;
}
int spi_bitbang_setup_transfer(struct spi_device *spi, struct spi_transfer *t)
{
struct spi_bitbang_cs *cs = spi->controller_state;
u8 bits_per_word;
u32 hz;
if (t) {
bits_per_word = t->bits_per_word;
hz = t->speed_hz;
} else {
bits_per_word = 0;
hz = 0;
}
if (!bits_per_word)
bits_per_word = spi->bits_per_word;
if (bits_per_word <= 8)
cs->txrx_bufs = bitbang_txrx_8;
else if (bits_per_word <= 16)
cs->txrx_bufs = bitbang_txrx_16;
else if (bits_per_word <= 32)
cs->txrx_bufs = bitbang_txrx_32;
else
return -EINVAL;
if (!hz)
hz = spi->max_speed_hz;
if (hz) {
cs->nsecs = (1000000000/2) / hz;
if (cs->nsecs > (MAX_UDELAY_MS * 1000 * 1000))
return -EINVAL;
}
return 0;
}
int spi_bitbang_setup(struct spi_device *spi)
{
struct spi_bitbang_cs *cs = spi->controller_state;
struct spi_bitbang *bitbang;
bitbang = spi_master_get_devdata(spi->master);
if (!cs) {
cs = kzalloc(sizeof(*cs), GFP_KERNEL);
if (!cs)
return -ENOMEM;
spi->controller_state = cs;
}
cs->txrx_word = bitbang->txrx_word[spi->mode & (SPI_CPOL|SPI_CPHA)];
if (!cs->txrx_word)
return -EINVAL;
if (bitbang->setup_transfer) {
int retval = bitbang->setup_transfer(spi, NULL);
if (retval < 0)
return retval;
}
dev_dbg(&spi->dev, "%s, %u nsec/bit\n", __func__, 2 * cs->nsecs);
mutex_lock(&bitbang->lock);
if (!bitbang->busy) {
bitbang->chipselect(spi, BITBANG_CS_INACTIVE);
ndelay(cs->nsecs);
}
mutex_unlock(&bitbang->lock);
return 0;
}
void spi_bitbang_cleanup(struct spi_device *spi)
{
kfree(spi->controller_state);
}
static int spi_bitbang_bufs(struct spi_device *spi, struct spi_transfer *t)
{
struct spi_bitbang_cs *cs = spi->controller_state;
unsigned nsecs = cs->nsecs;
return cs->txrx_bufs(spi, cs->txrx_word, nsecs, t);
}
static int spi_bitbang_prepare_hardware(struct spi_master *spi)
{
struct spi_bitbang *bitbang;
bitbang = spi_master_get_devdata(spi);
mutex_lock(&bitbang->lock);
bitbang->busy = 1;
mutex_unlock(&bitbang->lock);
return 0;
}
static int spi_bitbang_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *transfer)
{
struct spi_bitbang *bitbang = spi_master_get_devdata(master);
int status = 0;
if (bitbang->setup_transfer) {
status = bitbang->setup_transfer(spi, transfer);
if (status < 0)
goto out;
}
if (transfer->len)
status = bitbang->txrx_bufs(spi, transfer);
if (status == transfer->len)
status = 0;
else if (status >= 0)
status = -EREMOTEIO;
out:
spi_finalize_current_transfer(master);
return status;
}
static int spi_bitbang_unprepare_hardware(struct spi_master *spi)
{
struct spi_bitbang *bitbang;
bitbang = spi_master_get_devdata(spi);
mutex_lock(&bitbang->lock);
bitbang->busy = 0;
mutex_unlock(&bitbang->lock);
return 0;
}
static void spi_bitbang_set_cs(struct spi_device *spi, bool enable)
{
struct spi_bitbang *bitbang = spi_master_get_devdata(spi->master);
enable = (!!(spi->mode & SPI_CS_HIGH) == enable);
ndelay(SPI_BITBANG_CS_DELAY);
bitbang->chipselect(spi, enable ? BITBANG_CS_ACTIVE :
BITBANG_CS_INACTIVE);
ndelay(SPI_BITBANG_CS_DELAY);
}
int spi_bitbang_start(struct spi_bitbang *bitbang)
{
struct spi_master *master = bitbang->master;
int ret;
if (!master || !bitbang->chipselect)
return -EINVAL;
mutex_init(&bitbang->lock);
if (!master->mode_bits)
master->mode_bits = SPI_CPOL | SPI_CPHA | bitbang->flags;
if (master->transfer || master->transfer_one_message)
return -EINVAL;
master->prepare_transfer_hardware = spi_bitbang_prepare_hardware;
master->unprepare_transfer_hardware = spi_bitbang_unprepare_hardware;
master->transfer_one = spi_bitbang_transfer_one;
master->set_cs = spi_bitbang_set_cs;
if (!bitbang->txrx_bufs) {
bitbang->use_dma = 0;
bitbang->txrx_bufs = spi_bitbang_bufs;
if (!master->setup) {
if (!bitbang->setup_transfer)
bitbang->setup_transfer =
spi_bitbang_setup_transfer;
master->setup = spi_bitbang_setup;
master->cleanup = spi_bitbang_cleanup;
}
}
ret = spi_register_master(spi_master_get(master));
if (ret)
spi_master_put(master);
return 0;
}
void spi_bitbang_stop(struct spi_bitbang *bitbang)
{
spi_unregister_master(bitbang->master);
}
