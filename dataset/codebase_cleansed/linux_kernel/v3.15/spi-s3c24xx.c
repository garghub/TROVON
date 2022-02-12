static inline struct s3c24xx_spi *to_hw(struct spi_device *sdev)
{
return spi_master_get_devdata(sdev->master);
}
static void s3c24xx_spi_gpiocs(struct s3c2410_spi_info *spi, int cs, int pol)
{
gpio_set_value(spi->pin_cs, pol);
}
static void s3c24xx_spi_chipsel(struct spi_device *spi, int value)
{
struct s3c24xx_spi_devstate *cs = spi->controller_state;
struct s3c24xx_spi *hw = to_hw(spi);
unsigned int cspol = spi->mode & SPI_CS_HIGH ? 1 : 0;
switch (value) {
case BITBANG_CS_INACTIVE:
hw->set_cs(hw->pdata, spi->chip_select, cspol^1);
writeb(cs->spcon, hw->regs + S3C2410_SPCON);
break;
case BITBANG_CS_ACTIVE:
writeb(cs->spcon | S3C2410_SPCON_ENSCK,
hw->regs + S3C2410_SPCON);
hw->set_cs(hw->pdata, spi->chip_select, cspol);
break;
}
}
static int s3c24xx_spi_update_state(struct spi_device *spi,
struct spi_transfer *t)
{
struct s3c24xx_spi *hw = to_hw(spi);
struct s3c24xx_spi_devstate *cs = spi->controller_state;
unsigned int hz;
unsigned int div;
unsigned long clk;
hz = t ? t->speed_hz : spi->max_speed_hz;
if (!hz)
hz = spi->max_speed_hz;
if (spi->mode != cs->mode) {
u8 spcon = SPCON_DEFAULT | S3C2410_SPCON_ENSCK;
if (spi->mode & SPI_CPHA)
spcon |= S3C2410_SPCON_CPHA_FMTB;
if (spi->mode & SPI_CPOL)
spcon |= S3C2410_SPCON_CPOL_HIGH;
cs->mode = spi->mode;
cs->spcon = spcon;
}
if (cs->hz != hz) {
clk = clk_get_rate(hw->clk);
div = DIV_ROUND_UP(clk, hz * 2) - 1;
if (div > 255)
div = 255;
dev_dbg(&spi->dev, "pre-scaler=%d (wanted %d, got %ld)\n",
div, hz, clk / (2 * (div + 1)));
cs->hz = hz;
cs->sppre = div;
}
return 0;
}
static int s3c24xx_spi_setupxfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct s3c24xx_spi_devstate *cs = spi->controller_state;
struct s3c24xx_spi *hw = to_hw(spi);
int ret;
ret = s3c24xx_spi_update_state(spi, t);
if (!ret)
writeb(cs->sppre, hw->regs + S3C2410_SPPRE);
return ret;
}
static int s3c24xx_spi_setup(struct spi_device *spi)
{
struct s3c24xx_spi_devstate *cs = spi->controller_state;
struct s3c24xx_spi *hw = to_hw(spi);
int ret;
if (!cs) {
cs = kzalloc(sizeof(struct s3c24xx_spi_devstate), GFP_KERNEL);
if (!cs) {
dev_err(&spi->dev, "no memory for controller state\n");
return -ENOMEM;
}
cs->spcon = SPCON_DEFAULT;
cs->hz = -1;
spi->controller_state = cs;
}
ret = s3c24xx_spi_update_state(spi, NULL);
if (ret)
return ret;
spin_lock(&hw->bitbang.lock);
if (!hw->bitbang.busy) {
hw->bitbang.chipselect(spi, BITBANG_CS_INACTIVE);
}
spin_unlock(&hw->bitbang.lock);
return 0;
}
static void s3c24xx_spi_cleanup(struct spi_device *spi)
{
kfree(spi->controller_state);
}
static inline unsigned int hw_txbyte(struct s3c24xx_spi *hw, int count)
{
return hw->tx ? hw->tx[count] : 0;
}
static inline u32 ack_bit(unsigned int irq)
{
return 1 << (irq - IRQ_EINT0);
}
static void s3c24xx_spi_tryfiq(struct s3c24xx_spi *hw)
{
struct pt_regs regs;
enum spi_fiq_mode mode;
struct spi_fiq_code *code;
int ret;
if (!hw->fiq_claimed) {
ret = claim_fiq(&hw->fiq_handler);
if (ret)
return;
}
if (hw->tx && !hw->rx)
mode = FIQ_MODE_TX;
else if (hw->rx && !hw->tx)
mode = FIQ_MODE_RX;
else
mode = FIQ_MODE_TXRX;
regs.uregs[fiq_rspi] = (long)hw->regs;
regs.uregs[fiq_rrx] = (long)hw->rx;
regs.uregs[fiq_rtx] = (long)hw->tx + 1;
regs.uregs[fiq_rcount] = hw->len - 1;
regs.uregs[fiq_rirq] = (long)S3C24XX_VA_IRQ;
set_fiq_regs(&regs);
if (hw->fiq_mode != mode) {
u32 *ack_ptr;
hw->fiq_mode = mode;
switch (mode) {
case FIQ_MODE_TX:
code = &s3c24xx_spi_fiq_tx;
break;
case FIQ_MODE_RX:
code = &s3c24xx_spi_fiq_rx;
break;
case FIQ_MODE_TXRX:
code = &s3c24xx_spi_fiq_txrx;
break;
default:
code = NULL;
}
BUG_ON(!code);
ack_ptr = (u32 *)&code->data[code->ack_offset];
*ack_ptr = ack_bit(hw->irq);
set_fiq_handler(&code->data, code->length);
}
s3c24xx_set_fiq(hw->irq, true);
hw->fiq_mode = mode;
hw->fiq_inuse = 1;
}
static int s3c24xx_spi_fiqop(void *pw, int release)
{
struct s3c24xx_spi *hw = pw;
int ret = 0;
if (release) {
if (hw->fiq_inuse)
ret = -EBUSY;
hw->fiq_mode = FIQ_MODE_NONE;
hw->fiq_claimed = 0;
} else {
hw->fiq_claimed = 1;
}
return ret;
}
static inline void s3c24xx_spi_initfiq(struct s3c24xx_spi *hw)
{
hw->fiq_handler.dev_id = hw;
hw->fiq_handler.name = dev_name(hw->dev);
hw->fiq_handler.fiq_op = s3c24xx_spi_fiqop;
}
static inline bool s3c24xx_spi_usefiq(struct s3c24xx_spi *hw)
{
return hw->pdata->use_fiq;
}
static inline bool s3c24xx_spi_usingfiq(struct s3c24xx_spi *spi)
{
return spi->fiq_inuse;
}
static inline void s3c24xx_spi_initfiq(struct s3c24xx_spi *s) { }
static inline void s3c24xx_spi_tryfiq(struct s3c24xx_spi *s) { }
static inline bool s3c24xx_spi_usefiq(struct s3c24xx_spi *s) { return false; }
static inline bool s3c24xx_spi_usingfiq(struct s3c24xx_spi *s) { return false; }
static int s3c24xx_spi_txrx(struct spi_device *spi, struct spi_transfer *t)
{
struct s3c24xx_spi *hw = to_hw(spi);
hw->tx = t->tx_buf;
hw->rx = t->rx_buf;
hw->len = t->len;
hw->count = 0;
init_completion(&hw->done);
hw->fiq_inuse = 0;
if (s3c24xx_spi_usefiq(hw) && t->len >= 3)
s3c24xx_spi_tryfiq(hw);
writeb(hw_txbyte(hw, 0), hw->regs + S3C2410_SPTDAT);
wait_for_completion(&hw->done);
return hw->count;
}
static irqreturn_t s3c24xx_spi_irq(int irq, void *dev)
{
struct s3c24xx_spi *hw = dev;
unsigned int spsta = readb(hw->regs + S3C2410_SPSTA);
unsigned int count = hw->count;
if (spsta & S3C2410_SPSTA_DCOL) {
dev_dbg(hw->dev, "data-collision\n");
complete(&hw->done);
goto irq_done;
}
if (!(spsta & S3C2410_SPSTA_READY)) {
dev_dbg(hw->dev, "spi not ready for tx?\n");
complete(&hw->done);
goto irq_done;
}
if (!s3c24xx_spi_usingfiq(hw)) {
hw->count++;
if (hw->rx)
hw->rx[count] = readb(hw->regs + S3C2410_SPRDAT);
count++;
if (count < hw->len)
writeb(hw_txbyte(hw, count), hw->regs + S3C2410_SPTDAT);
else
complete(&hw->done);
} else {
hw->count = hw->len;
hw->fiq_inuse = 0;
if (hw->rx)
hw->rx[hw->len-1] = readb(hw->regs + S3C2410_SPRDAT);
complete(&hw->done);
}
irq_done:
return IRQ_HANDLED;
}
static void s3c24xx_spi_initialsetup(struct s3c24xx_spi *hw)
{
clk_enable(hw->clk);
writeb(0xff, hw->regs + S3C2410_SPPRE);
writeb(SPPIN_DEFAULT, hw->regs + S3C2410_SPPIN);
writeb(SPCON_DEFAULT, hw->regs + S3C2410_SPCON);
if (hw->pdata) {
if (hw->set_cs == s3c24xx_spi_gpiocs)
gpio_direction_output(hw->pdata->pin_cs, 1);
if (hw->pdata->gpio_setup)
hw->pdata->gpio_setup(hw->pdata, 1);
}
}
static int s3c24xx_spi_probe(struct platform_device *pdev)
{
struct s3c2410_spi_info *pdata;
struct s3c24xx_spi *hw;
struct spi_master *master;
struct resource *res;
int err = 0;
master = spi_alloc_master(&pdev->dev, sizeof(struct s3c24xx_spi));
if (master == NULL) {
dev_err(&pdev->dev, "No memory for spi_master\n");
return -ENOMEM;
}
hw = spi_master_get_devdata(master);
memset(hw, 0, sizeof(struct s3c24xx_spi));
hw->master = master;
hw->pdata = pdata = dev_get_platdata(&pdev->dev);
hw->dev = &pdev->dev;
if (pdata == NULL) {
dev_err(&pdev->dev, "No platform data supplied\n");
err = -ENOENT;
goto err_no_pdata;
}
platform_set_drvdata(pdev, hw);
init_completion(&hw->done);
s3c24xx_spi_initfiq(hw);
master->mode_bits = SPI_CPOL | SPI_CPHA | SPI_CS_HIGH;
master->num_chipselect = hw->pdata->num_cs;
master->bus_num = pdata->bus_num;
master->bits_per_word_mask = SPI_BPW_MASK(8);
hw->bitbang.master = hw->master;
hw->bitbang.setup_transfer = s3c24xx_spi_setupxfer;
hw->bitbang.chipselect = s3c24xx_spi_chipsel;
hw->bitbang.txrx_bufs = s3c24xx_spi_txrx;
hw->master->setup = s3c24xx_spi_setup;
hw->master->cleanup = s3c24xx_spi_cleanup;
dev_dbg(hw->dev, "bitbang at %p\n", &hw->bitbang);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hw->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hw->regs)) {
err = PTR_ERR(hw->regs);
goto err_no_pdata;
}
hw->irq = platform_get_irq(pdev, 0);
if (hw->irq < 0) {
dev_err(&pdev->dev, "No IRQ specified\n");
err = -ENOENT;
goto err_no_pdata;
}
err = devm_request_irq(&pdev->dev, hw->irq, s3c24xx_spi_irq, 0,
pdev->name, hw);
if (err) {
dev_err(&pdev->dev, "Cannot claim IRQ\n");
goto err_no_pdata;
}
hw->clk = devm_clk_get(&pdev->dev, "spi");
if (IS_ERR(hw->clk)) {
dev_err(&pdev->dev, "No clock for device\n");
err = PTR_ERR(hw->clk);
goto err_no_pdata;
}
if (!pdata->set_cs) {
if (pdata->pin_cs < 0) {
dev_err(&pdev->dev, "No chipselect pin\n");
err = -EINVAL;
goto err_register;
}
err = devm_gpio_request(&pdev->dev, pdata->pin_cs,
dev_name(&pdev->dev));
if (err) {
dev_err(&pdev->dev, "Failed to get gpio for cs\n");
goto err_register;
}
hw->set_cs = s3c24xx_spi_gpiocs;
gpio_direction_output(pdata->pin_cs, 1);
} else
hw->set_cs = pdata->set_cs;
s3c24xx_spi_initialsetup(hw);
err = spi_bitbang_start(&hw->bitbang);
if (err) {
dev_err(&pdev->dev, "Failed to register SPI master\n");
goto err_register;
}
return 0;
err_register:
clk_disable(hw->clk);
err_no_pdata:
spi_master_put(hw->master);
return err;
}
static int s3c24xx_spi_remove(struct platform_device *dev)
{
struct s3c24xx_spi *hw = platform_get_drvdata(dev);
spi_bitbang_stop(&hw->bitbang);
clk_disable(hw->clk);
spi_master_put(hw->master);
return 0;
}
static int s3c24xx_spi_suspend(struct device *dev)
{
struct s3c24xx_spi *hw = dev_get_drvdata(dev);
int ret;
ret = spi_master_suspend(hw->master);
if (ret)
return ret;
if (hw->pdata && hw->pdata->gpio_setup)
hw->pdata->gpio_setup(hw->pdata, 0);
clk_disable(hw->clk);
return 0;
}
static int s3c24xx_spi_resume(struct device *dev)
{
struct s3c24xx_spi *hw = dev_get_drvdata(dev);
s3c24xx_spi_initialsetup(hw);
return spi_master_resume(hw->master);
}
