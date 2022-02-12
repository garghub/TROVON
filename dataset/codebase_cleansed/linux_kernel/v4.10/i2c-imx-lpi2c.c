static void lpi2c_imx_intctrl(struct lpi2c_imx_struct *lpi2c_imx,
unsigned int enable)
{
writel(enable, lpi2c_imx->base + LPI2C_MIER);
}
static int lpi2c_imx_bus_busy(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned long orig_jiffies = jiffies;
unsigned int temp;
while (1) {
temp = readl(lpi2c_imx->base + LPI2C_MSR);
if (temp & MSR_ALF) {
writel(temp, lpi2c_imx->base + LPI2C_MSR);
return -EAGAIN;
}
if (temp & (MSR_BBF | MSR_MBF))
break;
if (time_after(jiffies, orig_jiffies + msecs_to_jiffies(500))) {
dev_dbg(&lpi2c_imx->adapter.dev, "bus not work\n");
return -ETIMEDOUT;
}
schedule();
}
return 0;
}
static void lpi2c_imx_set_mode(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned int bitrate = lpi2c_imx->bitrate;
enum lpi2c_imx_mode mode;
if (bitrate < STARDARD_MAX_BITRATE)
mode = STANDARD;
else if (bitrate < FAST_MAX_BITRATE)
mode = FAST;
else if (bitrate < FAST_PLUS_MAX_BITRATE)
mode = FAST_PLUS;
else if (bitrate < HIGHSPEED_MAX_BITRATE)
mode = HS;
else
mode = ULTRA_FAST;
lpi2c_imx->mode = mode;
}
static int lpi2c_imx_start(struct lpi2c_imx_struct *lpi2c_imx,
struct i2c_msg *msgs)
{
unsigned int temp;
u8 read;
temp = readl(lpi2c_imx->base + LPI2C_MCR);
temp |= MCR_RRF | MCR_RTF;
writel(temp, lpi2c_imx->base + LPI2C_MCR);
writel(0x7f00, lpi2c_imx->base + LPI2C_MSR);
read = msgs->flags & I2C_M_RD;
temp = (msgs->addr << 1 | read) | (GEN_START << 8);
writel(temp, lpi2c_imx->base + LPI2C_MTDR);
return lpi2c_imx_bus_busy(lpi2c_imx);
}
static void lpi2c_imx_stop(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned long orig_jiffies = jiffies;
unsigned int temp;
writel(GEN_STOP << 8, lpi2c_imx->base + LPI2C_MTDR);
do {
temp = readl(lpi2c_imx->base + LPI2C_MSR);
if (temp & MSR_SDF)
break;
if (time_after(jiffies, orig_jiffies + msecs_to_jiffies(500))) {
dev_dbg(&lpi2c_imx->adapter.dev, "stop timeout\n");
break;
}
schedule();
} while (1);
}
static int lpi2c_imx_config(struct lpi2c_imx_struct *lpi2c_imx)
{
u8 prescale, filt, sethold, clkhi, clklo, datavd;
unsigned int clk_rate, clk_cycle;
enum lpi2c_imx_pincfg pincfg;
unsigned int temp;
lpi2c_imx_set_mode(lpi2c_imx);
clk_rate = clk_get_rate(lpi2c_imx->clk);
if (lpi2c_imx->mode == HS || lpi2c_imx->mode == ULTRA_FAST)
filt = 0;
else
filt = 2;
for (prescale = 0; prescale <= 7; prescale++) {
clk_cycle = clk_rate / ((1 << prescale) * lpi2c_imx->bitrate)
- 3 - (filt >> 1);
clkhi = (clk_cycle + I2C_CLK_RATIO) / (I2C_CLK_RATIO + 1);
clklo = clk_cycle - clkhi;
if (clklo < 64)
break;
}
if (prescale > 7)
return -EINVAL;
if (lpi2c_imx->mode == ULTRA_FAST)
pincfg = TWO_PIN_OO;
else
pincfg = TWO_PIN_OD;
temp = prescale | pincfg << 24;
if (lpi2c_imx->mode == ULTRA_FAST)
temp |= MCFGR1_IGNACK;
writel(temp, lpi2c_imx->base + LPI2C_MCFGR1);
temp = (filt << 16) | (filt << 24);
writel(temp, lpi2c_imx->base + LPI2C_MCFGR2);
sethold = clkhi;
datavd = clkhi >> 1;
temp = datavd << 24 | sethold << 16 | clkhi << 8 | clklo;
if (lpi2c_imx->mode == HS)
writel(temp, lpi2c_imx->base + LPI2C_MCCR1);
else
writel(temp, lpi2c_imx->base + LPI2C_MCCR0);
return 0;
}
static int lpi2c_imx_master_enable(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned int temp;
int ret;
ret = clk_enable(lpi2c_imx->clk);
if (ret)
return ret;
temp = MCR_RST;
writel(temp, lpi2c_imx->base + LPI2C_MCR);
writel(0, lpi2c_imx->base + LPI2C_MCR);
ret = lpi2c_imx_config(lpi2c_imx);
if (ret)
goto clk_disable;
temp = readl(lpi2c_imx->base + LPI2C_MCR);
temp |= MCR_MEN;
writel(temp, lpi2c_imx->base + LPI2C_MCR);
return 0;
clk_disable:
clk_disable(lpi2c_imx->clk);
return ret;
}
static int lpi2c_imx_master_disable(struct lpi2c_imx_struct *lpi2c_imx)
{
u32 temp;
temp = readl(lpi2c_imx->base + LPI2C_MCR);
temp &= ~MCR_MEN;
writel(temp, lpi2c_imx->base + LPI2C_MCR);
clk_disable(lpi2c_imx->clk);
return 0;
}
static int lpi2c_imx_msg_complete(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned long timeout;
timeout = wait_for_completion_timeout(&lpi2c_imx->complete, HZ);
return timeout ? 0 : -ETIMEDOUT;
}
static int lpi2c_imx_txfifo_empty(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned long orig_jiffies = jiffies;
u32 txcnt;
do {
txcnt = readl(lpi2c_imx->base + LPI2C_MFSR) & 0xff;
if (readl(lpi2c_imx->base + LPI2C_MSR) & MSR_NDF) {
dev_dbg(&lpi2c_imx->adapter.dev, "NDF detected\n");
return -EIO;
}
if (time_after(jiffies, orig_jiffies + msecs_to_jiffies(500))) {
dev_dbg(&lpi2c_imx->adapter.dev, "txfifo empty timeout\n");
return -ETIMEDOUT;
}
schedule();
} while (txcnt);
return 0;
}
static void lpi2c_imx_set_tx_watermark(struct lpi2c_imx_struct *lpi2c_imx)
{
writel(lpi2c_imx->txfifosize >> 1, lpi2c_imx->base + LPI2C_MFCR);
}
static void lpi2c_imx_set_rx_watermark(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned int temp, remaining;
remaining = lpi2c_imx->msglen - lpi2c_imx->delivered;
if (remaining > (lpi2c_imx->rxfifosize >> 1))
temp = lpi2c_imx->rxfifosize >> 1;
else
temp = 0;
writel(temp << 16, lpi2c_imx->base + LPI2C_MFCR);
}
static void lpi2c_imx_write_txfifo(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned int data, txcnt;
txcnt = readl(lpi2c_imx->base + LPI2C_MFSR) & 0xff;
while (txcnt < lpi2c_imx->txfifosize) {
if (lpi2c_imx->delivered == lpi2c_imx->msglen)
break;
data = lpi2c_imx->tx_buf[lpi2c_imx->delivered++];
writel(data, lpi2c_imx->base + LPI2C_MTDR);
txcnt++;
}
if (lpi2c_imx->delivered < lpi2c_imx->msglen)
lpi2c_imx_intctrl(lpi2c_imx, MIER_TDIE | MIER_NDIE);
else
complete(&lpi2c_imx->complete);
}
static void lpi2c_imx_read_rxfifo(struct lpi2c_imx_struct *lpi2c_imx)
{
unsigned int blocklen, remaining;
unsigned int temp, data;
do {
data = readl(lpi2c_imx->base + LPI2C_MRDR);
if (data & MRDR_RXEMPTY)
break;
lpi2c_imx->rx_buf[lpi2c_imx->delivered++] = data & 0xff;
} while (1);
if (lpi2c_imx->block_data) {
blocklen = lpi2c_imx->rx_buf[0];
lpi2c_imx->msglen += blocklen;
}
remaining = lpi2c_imx->msglen - lpi2c_imx->delivered;
if (!remaining) {
complete(&lpi2c_imx->complete);
return;
}
lpi2c_imx_set_rx_watermark(lpi2c_imx);
if (lpi2c_imx->block_data) {
lpi2c_imx->block_data = 0;
temp = remaining;
temp |= (RECV_DATA << 8);
writel(temp, lpi2c_imx->base + LPI2C_MTDR);
} else if (!(lpi2c_imx->delivered & 0xff)) {
temp = (remaining > CHUNK_DATA ? CHUNK_DATA : remaining) - 1;
temp |= (RECV_DATA << 8);
writel(temp, lpi2c_imx->base + LPI2C_MTDR);
}
lpi2c_imx_intctrl(lpi2c_imx, MIER_RDIE);
}
static void lpi2c_imx_write(struct lpi2c_imx_struct *lpi2c_imx,
struct i2c_msg *msgs)
{
lpi2c_imx->tx_buf = msgs->buf;
lpi2c_imx_set_tx_watermark(lpi2c_imx);
lpi2c_imx_write_txfifo(lpi2c_imx);
}
static void lpi2c_imx_read(struct lpi2c_imx_struct *lpi2c_imx,
struct i2c_msg *msgs)
{
unsigned int temp;
lpi2c_imx->rx_buf = msgs->buf;
lpi2c_imx->block_data = msgs->flags & I2C_M_RECV_LEN;
lpi2c_imx_set_rx_watermark(lpi2c_imx);
temp = msgs->len > CHUNK_DATA ? CHUNK_DATA - 1 : msgs->len - 1;
temp |= (RECV_DATA << 8);
writel(temp, lpi2c_imx->base + LPI2C_MTDR);
lpi2c_imx_intctrl(lpi2c_imx, MIER_RDIE | MIER_NDIE);
}
static int lpi2c_imx_xfer(struct i2c_adapter *adapter,
struct i2c_msg *msgs, int num)
{
struct lpi2c_imx_struct *lpi2c_imx = i2c_get_adapdata(adapter);
unsigned int temp;
int i, result;
result = lpi2c_imx_master_enable(lpi2c_imx);
if (result)
return result;
for (i = 0; i < num; i++) {
result = lpi2c_imx_start(lpi2c_imx, &msgs[i]);
if (result)
goto disable;
if (num == 1 && msgs[0].len == 0)
goto stop;
lpi2c_imx->delivered = 0;
lpi2c_imx->msglen = msgs[i].len;
init_completion(&lpi2c_imx->complete);
if (msgs[i].flags & I2C_M_RD)
lpi2c_imx_read(lpi2c_imx, &msgs[i]);
else
lpi2c_imx_write(lpi2c_imx, &msgs[i]);
result = lpi2c_imx_msg_complete(lpi2c_imx);
if (result)
goto stop;
if (!(msgs[i].flags & I2C_M_RD)) {
result = lpi2c_imx_txfifo_empty(lpi2c_imx);
if (result)
goto stop;
}
}
stop:
lpi2c_imx_stop(lpi2c_imx);
temp = readl(lpi2c_imx->base + LPI2C_MSR);
if ((temp & MSR_NDF) && !result)
result = -EIO;
disable:
lpi2c_imx_master_disable(lpi2c_imx);
dev_dbg(&lpi2c_imx->adapter.dev, "<%s> exit with: %s: %d\n", __func__,
(result < 0) ? "error" : "success msg",
(result < 0) ? result : num);
return (result < 0) ? result : num;
}
static irqreturn_t lpi2c_imx_isr(int irq, void *dev_id)
{
struct lpi2c_imx_struct *lpi2c_imx = dev_id;
unsigned int temp;
lpi2c_imx_intctrl(lpi2c_imx, 0);
temp = readl(lpi2c_imx->base + LPI2C_MSR);
if (temp & MSR_RDF)
lpi2c_imx_read_rxfifo(lpi2c_imx);
if (temp & MSR_TDF)
lpi2c_imx_write_txfifo(lpi2c_imx);
if (temp & MSR_NDF)
complete(&lpi2c_imx->complete);
return IRQ_HANDLED;
}
static u32 lpi2c_imx_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
I2C_FUNC_SMBUS_READ_BLOCK_DATA;
}
static int lpi2c_imx_probe(struct platform_device *pdev)
{
struct lpi2c_imx_struct *lpi2c_imx;
struct resource *res;
unsigned int temp;
int irq, ret;
lpi2c_imx = devm_kzalloc(&pdev->dev, sizeof(*lpi2c_imx), GFP_KERNEL);
if (!lpi2c_imx)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
lpi2c_imx->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(lpi2c_imx->base))
return PTR_ERR(lpi2c_imx->base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "can't get irq number\n");
return irq;
}
lpi2c_imx->adapter.owner = THIS_MODULE;
lpi2c_imx->adapter.algo = &lpi2c_imx_algo;
lpi2c_imx->adapter.dev.parent = &pdev->dev;
lpi2c_imx->adapter.dev.of_node = pdev->dev.of_node;
strlcpy(lpi2c_imx->adapter.name, pdev->name,
sizeof(lpi2c_imx->adapter.name));
lpi2c_imx->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(lpi2c_imx->clk)) {
dev_err(&pdev->dev, "can't get I2C peripheral clock\n");
return PTR_ERR(lpi2c_imx->clk);
}
ret = of_property_read_u32(pdev->dev.of_node,
"clock-frequency", &lpi2c_imx->bitrate);
if (ret)
lpi2c_imx->bitrate = LPI2C_DEFAULT_RATE;
ret = devm_request_irq(&pdev->dev, irq, lpi2c_imx_isr, 0,
pdev->name, lpi2c_imx);
if (ret) {
dev_err(&pdev->dev, "can't claim irq %d\n", irq);
return ret;
}
i2c_set_adapdata(&lpi2c_imx->adapter, lpi2c_imx);
platform_set_drvdata(pdev, lpi2c_imx);
ret = clk_prepare_enable(lpi2c_imx->clk);
if (ret) {
dev_err(&pdev->dev, "clk enable failed %d\n", ret);
return ret;
}
temp = readl(lpi2c_imx->base + LPI2C_PARAM);
lpi2c_imx->txfifosize = 1 << (temp & 0x0f);
lpi2c_imx->rxfifosize = 1 << ((temp >> 8) & 0x0f);
clk_disable(lpi2c_imx->clk);
ret = i2c_add_adapter(&lpi2c_imx->adapter);
if (ret)
goto clk_unprepare;
dev_info(&lpi2c_imx->adapter.dev, "LPI2C adapter registered\n");
return 0;
clk_unprepare:
clk_unprepare(lpi2c_imx->clk);
return ret;
}
static int lpi2c_imx_remove(struct platform_device *pdev)
{
struct lpi2c_imx_struct *lpi2c_imx = platform_get_drvdata(pdev);
i2c_del_adapter(&lpi2c_imx->adapter);
clk_unprepare(lpi2c_imx->clk);
return 0;
}
static int lpi2c_imx_suspend(struct device *dev)
{
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int lpi2c_imx_resume(struct device *dev)
{
pinctrl_pm_select_default_state(dev);
return 0;
}
