static inline void uwire_write_reg(int idx, u16 val)
{
__raw_writew(val, uwire_base + (idx << uwire_idx_shift));
}
static inline u16 uwire_read_reg(int idx)
{
return __raw_readw(uwire_base + (idx << uwire_idx_shift));
}
static inline void omap_uwire_configure_mode(u8 cs, unsigned long flags)
{
u16 w, val = 0;
int shift, reg;
if (flags & UWIRE_CLK_INVERTED)
val ^= 0x03;
val = flags & 0x3f;
if (cs & 1)
shift = 6;
else
shift = 0;
if (cs <= 1)
reg = UWIRE_SR1;
else
reg = UWIRE_SR2;
w = uwire_read_reg(reg);
w &= ~(0x3f << shift);
w |= val << shift;
uwire_write_reg(reg, w);
}
static int wait_uwire_csr_flag(u16 mask, u16 val, int might_not_catch)
{
u16 w;
int c = 0;
unsigned long max_jiffies = jiffies + HZ;
for (;;) {
w = uwire_read_reg(UWIRE_CSR);
if ((w & mask) == val)
break;
if (time_after(jiffies, max_jiffies)) {
printk(KERN_ERR "%s: timeout. reg=%#06x "
"mask=%#06x val=%#06x\n",
__func__, w, mask, val);
return -1;
}
c++;
if (might_not_catch && c > 64)
break;
}
return 0;
}
static void uwire_set_clk1_div(int div1_idx)
{
u16 w;
w = uwire_read_reg(UWIRE_SR3);
w &= ~(0x03 << 1);
w |= div1_idx << 1;
uwire_write_reg(UWIRE_SR3, w);
}
static void uwire_chipselect(struct spi_device *spi, int value)
{
struct uwire_state *ust = spi->controller_state;
u16 w;
int old_cs;
BUG_ON(wait_uwire_csr_flag(CSRB, 0, 0));
w = uwire_read_reg(UWIRE_CSR);
old_cs = (w >> 10) & 0x03;
if (value == BITBANG_CS_INACTIVE || old_cs != spi->chip_select) {
w &= ~CS_CMD;
uwire_write_reg(UWIRE_CSR, w);
}
if (value == BITBANG_CS_ACTIVE) {
uwire_set_clk1_div(ust->div1_idx);
if (spi->mode & SPI_CPOL)
uwire_write_reg(UWIRE_SR4, 1);
else
uwire_write_reg(UWIRE_SR4, 0);
w = spi->chip_select << 10;
w |= CS_CMD;
uwire_write_reg(UWIRE_CSR, w);
}
}
static int uwire_txrx(struct spi_device *spi, struct spi_transfer *t)
{
struct uwire_state *ust = spi->controller_state;
unsigned len = t->len;
unsigned bits = ust->bits_per_word;
unsigned bytes;
u16 val, w;
int status = 0;
if (!t->tx_buf && !t->rx_buf)
return 0;
if (t->tx_buf && t->rx_buf)
return -EPERM;
w = spi->chip_select << 10;
w |= CS_CMD;
if (t->tx_buf) {
const u8 *buf = t->tx_buf;
while (len >= 1) {
val = *buf++;
if (bits > 8) {
bytes = 2;
val |= *buf++ << 8;
} else
bytes = 1;
val <<= 16 - bits;
#ifdef VERBOSE
pr_debug("%s: write-%d =%04x\n",
dev_name(&spi->dev), bits, val);
#endif
if (wait_uwire_csr_flag(CSRB, 0, 0))
goto eio;
uwire_write_reg(UWIRE_TDR, val);
val = START | w | (bits << 5);
uwire_write_reg(UWIRE_CSR, val);
len -= bytes;
if (wait_uwire_csr_flag(CSRB, CSRB, 1))
goto eio;
status += bytes;
}
if (wait_uwire_csr_flag(CSRB, 0, 0))
goto eio;
} else if (t->rx_buf) {
u8 *buf = t->rx_buf;
while (len) {
if (bits > 8) {
bytes = 2;
} else
bytes = 1;
val = START | w | (bits << 0);
uwire_write_reg(UWIRE_CSR, val);
len -= bytes;
(void) wait_uwire_csr_flag(CSRB, CSRB, 1);
if (wait_uwire_csr_flag(RDRB | CSRB,
RDRB, 0))
goto eio;
val = uwire_read_reg(UWIRE_RDR);
val &= (1 << bits) - 1;
*buf++ = (u8) val;
if (bytes == 2)
*buf++ = val >> 8;
status += bytes;
#ifdef VERBOSE
pr_debug("%s: read-%d =%04x\n",
dev_name(&spi->dev), bits, val);
#endif
}
}
return status;
eio:
return -EIO;
}
static int uwire_setup_transfer(struct spi_device *spi, struct spi_transfer *t)
{
struct uwire_state *ust = spi->controller_state;
struct uwire_spi *uwire;
unsigned flags = 0;
unsigned bits;
unsigned hz;
unsigned long rate;
int div1_idx;
int div1;
int div2;
int status;
uwire = spi_master_get_devdata(spi->master);
if (spi->chip_select > 3) {
pr_debug("%s: cs%d?\n", dev_name(&spi->dev), spi->chip_select);
status = -ENODEV;
goto done;
}
bits = spi->bits_per_word;
if (t != NULL && t->bits_per_word)
bits = t->bits_per_word;
if (bits > 16) {
pr_debug("%s: wordsize %d?\n", dev_name(&spi->dev), bits);
status = -ENODEV;
goto done;
}
ust->bits_per_word = bits;
if (spi->mode & SPI_CS_HIGH)
flags |= UWIRE_CS_ACTIVE_HIGH;
if (spi->mode & SPI_CPOL)
flags |= UWIRE_CLK_INVERTED;
switch (spi->mode & (SPI_CPOL | SPI_CPHA)) {
case SPI_MODE_0:
case SPI_MODE_3:
flags |= UWIRE_WRITE_FALLING_EDGE | UWIRE_READ_RISING_EDGE;
break;
case SPI_MODE_1:
case SPI_MODE_2:
flags |= UWIRE_WRITE_RISING_EDGE | UWIRE_READ_FALLING_EDGE;
break;
}
rate = clk_get_rate(uwire->ck);
hz = spi->max_speed_hz;
if (t != NULL && t->speed_hz)
hz = t->speed_hz;
if (!hz) {
pr_debug("%s: zero speed?\n", dev_name(&spi->dev));
status = -EINVAL;
goto done;
}
for (div1_idx = 0; div1_idx < 4; div1_idx++) {
switch (div1_idx) {
case 0:
div1 = 2;
break;
case 1:
div1 = 4;
break;
case 2:
div1 = 7;
break;
default:
case 3:
div1 = 10;
break;
}
div2 = (rate / div1 + hz - 1) / hz;
if (div2 <= 8)
break;
}
if (div1_idx == 4) {
pr_debug("%s: lowest clock %ld, need %d\n",
dev_name(&spi->dev), rate / 10 / 8, hz);
status = -EDOM;
goto done;
}
ust->div1_idx = div1_idx;
uwire_set_clk1_div(div1_idx);
rate /= div1;
switch (div2) {
case 0:
case 1:
case 2:
flags |= UWIRE_FREQ_DIV_2;
rate /= 2;
break;
case 3:
case 4:
flags |= UWIRE_FREQ_DIV_4;
rate /= 4;
break;
case 5:
case 6:
case 7:
case 8:
flags |= UWIRE_FREQ_DIV_8;
rate /= 8;
break;
}
omap_uwire_configure_mode(spi->chip_select, flags);
pr_debug("%s: uwire flags %02x, armxor %lu KHz, SCK %lu KHz\n",
__func__, flags,
clk_get_rate(uwire->ck) / 1000,
rate / 1000);
status = 0;
done:
return status;
}
static int uwire_setup(struct spi_device *spi)
{
struct uwire_state *ust = spi->controller_state;
if (ust == NULL) {
ust = kzalloc(sizeof(*ust), GFP_KERNEL);
if (ust == NULL)
return -ENOMEM;
spi->controller_state = ust;
}
return uwire_setup_transfer(spi, NULL);
}
static void uwire_cleanup(struct spi_device *spi)
{
kfree(spi->controller_state);
}
static void uwire_off(struct uwire_spi *uwire)
{
uwire_write_reg(UWIRE_SR3, 0);
clk_disable(uwire->ck);
clk_put(uwire->ck);
spi_master_put(uwire->bitbang.master);
}
static int uwire_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct uwire_spi *uwire;
int status;
master = spi_alloc_master(&pdev->dev, sizeof *uwire);
if (!master)
return -ENODEV;
uwire = spi_master_get_devdata(master);
uwire_base = ioremap(UWIRE_BASE_PHYS, UWIRE_IO_SIZE);
if (!uwire_base) {
dev_dbg(&pdev->dev, "can't ioremap UWIRE\n");
spi_master_put(master);
return -ENOMEM;
}
platform_set_drvdata(pdev, uwire);
uwire->ck = clk_get(&pdev->dev, "fck");
if (IS_ERR(uwire->ck)) {
status = PTR_ERR(uwire->ck);
dev_dbg(&pdev->dev, "no functional clock?\n");
spi_master_put(master);
return status;
}
clk_enable(uwire->ck);
if (cpu_is_omap7xx())
uwire_idx_shift = 1;
else
uwire_idx_shift = 2;
uwire_write_reg(UWIRE_SR3, 1);
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->flags = SPI_MASTER_HALF_DUPLEX;
master->bus_num = 2;
master->num_chipselect = 4;
master->setup = uwire_setup;
master->cleanup = uwire_cleanup;
uwire->bitbang.master = master;
uwire->bitbang.chipselect = uwire_chipselect;
uwire->bitbang.setup_transfer = uwire_setup_transfer;
uwire->bitbang.txrx_bufs = uwire_txrx;
status = spi_bitbang_start(&uwire->bitbang);
if (status < 0) {
uwire_off(uwire);
iounmap(uwire_base);
}
return status;
}
static int uwire_remove(struct platform_device *pdev)
{
struct uwire_spi *uwire = platform_get_drvdata(pdev);
int status;
status = spi_bitbang_stop(&uwire->bitbang);
uwire_off(uwire);
iounmap(uwire_base);
return status;
}
static int __init omap_uwire_init(void)
{
if (machine_is_omap_h2()) {
omap_cfg_reg(N14_1610_UWIRE_CS0);
omap_cfg_reg(N15_1610_UWIRE_CS1);
}
if (machine_is_omap_perseus2()) {
int val = omap_readl(OMAP7XX_IO_CONF_9) & ~0x00EEE000;
omap_writel(val | 0x00AAA000, OMAP7XX_IO_CONF_9);
}
return platform_driver_probe(&uwire_driver, uwire_probe);
}
static void __exit omap_uwire_exit(void)
{
platform_driver_unregister(&uwire_driver);
}
