static inline void st_i2c_set_bits(void __iomem *reg, u32 mask)
{
writel_relaxed(readl_relaxed(reg) | mask, reg);
}
static inline void st_i2c_clr_bits(void __iomem *reg, u32 mask)
{
writel_relaxed(readl_relaxed(reg) & ~mask, reg);
}
static void st_i2c_flush_rx_fifo(struct st_i2c_dev *i2c_dev)
{
int count, i;
if (readl_relaxed(i2c_dev->base + SSC_STA) & SSC_STA_RIR)
count = SSC_RXFIFO_SIZE;
else
count = readl_relaxed(i2c_dev->base + SSC_RX_FSTAT) &
SSC_RX_FSTAT_STATUS;
for (i = 0; i < count; i++)
readl_relaxed(i2c_dev->base + SSC_RBUF);
}
static void st_i2c_soft_reset(struct st_i2c_dev *i2c_dev)
{
st_i2c_flush_rx_fifo(i2c_dev);
st_i2c_set_bits(i2c_dev->base + SSC_CTL, SSC_CTL_SR);
st_i2c_clr_bits(i2c_dev->base + SSC_CTL, SSC_CTL_SR);
}
static void st_i2c_hw_config(struct st_i2c_dev *i2c_dev)
{
unsigned long rate;
u32 val, ns_per_clk;
struct st_i2c_timings *t = &i2c_timings[i2c_dev->mode];
st_i2c_soft_reset(i2c_dev);
val = SSC_CLR_REPSTRT | SSC_CLR_NACK | SSC_CLR_SSCARBL |
SSC_CLR_SSCAAS | SSC_CLR_SSCSTOP;
writel_relaxed(val, i2c_dev->base + SSC_CLR);
val = SSC_CTL_PO | SSC_CTL_PH | SSC_CTL_HB | SSC_CTL_DATA_WIDTH_9;
writel_relaxed(val, i2c_dev->base + SSC_CTL);
rate = clk_get_rate(i2c_dev->clk);
ns_per_clk = 1000000000 / rate;
val = rate / (2 * t->rate);
writel_relaxed(val, i2c_dev->base + SSC_BRG);
writel_relaxed(1, i2c_dev->base + SSC_PRE_SCALER_BRG);
writel_relaxed(SSC_I2C_I2CM, i2c_dev->base + SSC_I2C);
val = t->rep_start_hold / ns_per_clk;
writel_relaxed(val, i2c_dev->base + SSC_REP_START_HOLD);
val = t->rep_start_setup / ns_per_clk;
writel_relaxed(val, i2c_dev->base + SSC_REP_START_SETUP);
val = t->start_hold / ns_per_clk;
writel_relaxed(val, i2c_dev->base + SSC_START_HOLD);
val = t->data_setup_time / ns_per_clk;
writel_relaxed(val, i2c_dev->base + SSC_DATA_SETUP);
val = t->stop_setup_time / ns_per_clk;
writel_relaxed(val, i2c_dev->base + SSC_STOP_SETUP);
val = t->bus_free_time / ns_per_clk;
writel_relaxed(val, i2c_dev->base + SSC_BUS_FREE);
val = rate / 10000000;
writel_relaxed(val, i2c_dev->base + SSC_PRSCALER);
writel_relaxed(val, i2c_dev->base + SSC_PRSCALER_DATAOUT);
val = i2c_dev->scl_min_width_us * rate / 100000000;
writel_relaxed(val, i2c_dev->base + SSC_NOISE_SUPP_WIDTH);
val = i2c_dev->sda_min_width_us * rate / 100000000;
writel_relaxed(val, i2c_dev->base + SSC_NOISE_SUPP_WIDTH_DATAOUT);
}
static int st_i2c_wait_free_bus(struct st_i2c_dev *i2c_dev)
{
u32 sta;
int i;
for (i = 0; i < 10; i++) {
sta = readl_relaxed(i2c_dev->base + SSC_STA);
if (!(sta & SSC_STA_BUSY))
return 0;
usleep_range(2000, 4000);
}
dev_err(i2c_dev->dev, "bus not free (status = 0x%08x)\n", sta);
return -EBUSY;
}
static inline void st_i2c_write_tx_fifo(struct st_i2c_dev *i2c_dev, u8 byte)
{
u16 tbuf = byte << 1;
writel_relaxed(tbuf | 1, i2c_dev->base + SSC_TBUF);
}
static void st_i2c_wr_fill_tx_fifo(struct st_i2c_dev *i2c_dev)
{
struct st_i2c_client *c = &i2c_dev->client;
u32 tx_fstat, sta;
int i;
sta = readl_relaxed(i2c_dev->base + SSC_STA);
if (sta & SSC_STA_TX_FIFO_FULL)
return;
tx_fstat = readl_relaxed(i2c_dev->base + SSC_TX_FSTAT);
tx_fstat &= SSC_TX_FSTAT_STATUS;
if (c->count < (SSC_TXFIFO_SIZE - tx_fstat))
i = c->count;
else
i = SSC_TXFIFO_SIZE - tx_fstat;
for (; i > 0; i--, c->count--, c->buf++)
st_i2c_write_tx_fifo(i2c_dev, *c->buf);
}
static void st_i2c_rd_fill_tx_fifo(struct st_i2c_dev *i2c_dev, int max)
{
struct st_i2c_client *c = &i2c_dev->client;
u32 tx_fstat, sta;
int i;
sta = readl_relaxed(i2c_dev->base + SSC_STA);
if (sta & SSC_STA_TX_FIFO_FULL)
return;
tx_fstat = readl_relaxed(i2c_dev->base + SSC_TX_FSTAT);
tx_fstat &= SSC_TX_FSTAT_STATUS;
if (max < (SSC_TXFIFO_SIZE - tx_fstat))
i = max;
else
i = SSC_TXFIFO_SIZE - tx_fstat;
for (; i > 0; i--, c->xfered++)
st_i2c_write_tx_fifo(i2c_dev, 0xff);
}
static void st_i2c_read_rx_fifo(struct st_i2c_dev *i2c_dev)
{
struct st_i2c_client *c = &i2c_dev->client;
u32 i, sta;
u16 rbuf;
sta = readl_relaxed(i2c_dev->base + SSC_STA);
if (sta & SSC_STA_RIR) {
i = SSC_RXFIFO_SIZE;
} else {
i = readl_relaxed(i2c_dev->base + SSC_RX_FSTAT);
i &= SSC_RX_FSTAT_STATUS;
}
for (; (i > 0) && (c->count > 0); i--, c->count--) {
rbuf = readl_relaxed(i2c_dev->base + SSC_RBUF) >> 1;
*c->buf++ = (u8)rbuf & 0xff;
}
if (i) {
dev_err(i2c_dev->dev, "Unexpected %d bytes in rx fifo\n", i);
st_i2c_flush_rx_fifo(i2c_dev);
}
}
static void st_i2c_terminate_xfer(struct st_i2c_dev *i2c_dev)
{
struct st_i2c_client *c = &i2c_dev->client;
st_i2c_clr_bits(i2c_dev->base + SSC_IEN, SSC_IEN_TEEN);
st_i2c_clr_bits(i2c_dev->base + SSC_I2C, SSC_I2C_STRTG);
if (c->stop) {
st_i2c_set_bits(i2c_dev->base + SSC_IEN, SSC_IEN_STOPEN);
st_i2c_set_bits(i2c_dev->base + SSC_I2C, SSC_I2C_STOPG);
} else {
st_i2c_set_bits(i2c_dev->base + SSC_IEN, SSC_IEN_REPSTRTEN);
st_i2c_set_bits(i2c_dev->base + SSC_I2C, SSC_I2C_REPSTRTG);
}
}
static void st_i2c_handle_write(struct st_i2c_dev *i2c_dev)
{
struct st_i2c_client *c = &i2c_dev->client;
st_i2c_flush_rx_fifo(i2c_dev);
if (!c->count)
st_i2c_terminate_xfer(i2c_dev);
else
st_i2c_wr_fill_tx_fifo(i2c_dev);
}
static void st_i2c_handle_read(struct st_i2c_dev *i2c_dev)
{
struct st_i2c_client *c = &i2c_dev->client;
u32 ien;
if (!c->xfered) {
readl_relaxed(i2c_dev->base + SSC_RBUF);
st_i2c_clr_bits(i2c_dev->base + SSC_I2C, SSC_I2C_TXENB);
} else {
st_i2c_read_rx_fifo(i2c_dev);
}
if (!c->count) {
st_i2c_terminate_xfer(i2c_dev);
} else if (c->count == 1) {
st_i2c_clr_bits(i2c_dev->base + SSC_I2C, SSC_I2C_ACKG);
ien = SSC_IEN_NACKEN | SSC_IEN_ARBLEN;
writel_relaxed(ien, i2c_dev->base + SSC_IEN);
st_i2c_rd_fill_tx_fifo(i2c_dev, c->count);
} else {
st_i2c_rd_fill_tx_fifo(i2c_dev, c->count - 1);
}
}
static irqreturn_t st_i2c_isr_thread(int irq, void *data)
{
struct st_i2c_dev *i2c_dev = data;
struct st_i2c_client *c = &i2c_dev->client;
u32 sta, ien;
int it;
ien = readl_relaxed(i2c_dev->base + SSC_IEN);
sta = readl_relaxed(i2c_dev->base + SSC_STA);
it = __fls(sta & ien);
if (it < 0) {
dev_dbg(i2c_dev->dev, "spurious it (sta=0x%04x, ien=0x%04x)\n",
sta, ien);
return IRQ_NONE;
}
switch (1 << it) {
case SSC_STA_TE:
if (c->addr & I2C_M_RD)
st_i2c_handle_read(i2c_dev);
else
st_i2c_handle_write(i2c_dev);
break;
case SSC_STA_STOP:
case SSC_STA_REPSTRT:
writel_relaxed(0, i2c_dev->base + SSC_IEN);
complete(&i2c_dev->complete);
break;
case SSC_STA_NACK:
writel_relaxed(SSC_CLR_NACK, i2c_dev->base + SSC_CLR);
if ((c->addr & I2C_M_RD) && (c->count == 1) && (c->xfered)) {
st_i2c_handle_read(i2c_dev);
break;
}
it = SSC_IEN_STOPEN | SSC_IEN_ARBLEN;
writel_relaxed(it, i2c_dev->base + SSC_IEN);
st_i2c_set_bits(i2c_dev->base + SSC_I2C, SSC_I2C_STOPG);
c->result = -EIO;
break;
case SSC_STA_ARBL:
writel_relaxed(SSC_CLR_SSCARBL, i2c_dev->base + SSC_CLR);
it = SSC_IEN_STOPEN | SSC_IEN_ARBLEN;
writel_relaxed(it, i2c_dev->base + SSC_IEN);
st_i2c_set_bits(i2c_dev->base + SSC_I2C, SSC_I2C_STOPG);
c->result = -EAGAIN;
break;
default:
dev_err(i2c_dev->dev,
"it %d unhandled (sta=0x%04x)\n", it, sta);
}
readl(i2c_dev->base + SSC_IEN);
return IRQ_HANDLED;
}
static int st_i2c_xfer_msg(struct st_i2c_dev *i2c_dev, struct i2c_msg *msg,
bool is_first, bool is_last)
{
struct st_i2c_client *c = &i2c_dev->client;
u32 ctl, i2c, it;
unsigned long timeout;
int ret;
c->addr = (u8)(msg->addr << 1);
c->addr |= (msg->flags & I2C_M_RD);
c->buf = msg->buf;
c->count = msg->len;
c->xfered = 0;
c->result = 0;
c->stop = is_last;
reinit_completion(&i2c_dev->complete);
ctl = SSC_CTL_EN | SSC_CTL_MS | SSC_CTL_EN_RX_FIFO | SSC_CTL_EN_TX_FIFO;
st_i2c_set_bits(i2c_dev->base + SSC_CTL, ctl);
i2c = SSC_I2C_TXENB;
if (c->addr & I2C_M_RD)
i2c |= SSC_I2C_ACKG;
st_i2c_set_bits(i2c_dev->base + SSC_I2C, i2c);
st_i2c_write_tx_fifo(i2c_dev, c->addr);
if (!(c->addr & I2C_M_RD))
st_i2c_wr_fill_tx_fifo(i2c_dev);
it = SSC_IEN_NACKEN | SSC_IEN_TEEN | SSC_IEN_ARBLEN;
writel_relaxed(it, i2c_dev->base + SSC_IEN);
if (is_first) {
ret = st_i2c_wait_free_bus(i2c_dev);
if (ret)
return ret;
st_i2c_set_bits(i2c_dev->base + SSC_I2C, SSC_I2C_STRTG);
}
timeout = wait_for_completion_timeout(&i2c_dev->complete,
i2c_dev->adap.timeout);
ret = c->result;
if (!timeout) {
dev_err(i2c_dev->dev, "Write to slave 0x%x timed out\n",
c->addr);
ret = -ETIMEDOUT;
}
i2c = SSC_I2C_STOPG | SSC_I2C_REPSTRTG;
st_i2c_clr_bits(i2c_dev->base + SSC_I2C, i2c);
writel_relaxed(SSC_CLR_SSCSTOP | SSC_CLR_REPSTRT,
i2c_dev->base + SSC_CLR);
return ret;
}
static int st_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msgs[], int num)
{
struct st_i2c_dev *i2c_dev = i2c_get_adapdata(i2c_adap);
int ret, i;
i2c_dev->busy = true;
ret = clk_prepare_enable(i2c_dev->clk);
if (ret) {
dev_err(i2c_dev->dev, "Failed to prepare_enable clock\n");
return ret;
}
pinctrl_pm_select_default_state(i2c_dev->dev);
st_i2c_hw_config(i2c_dev);
for (i = 0; (i < num) && !ret; i++)
ret = st_i2c_xfer_msg(i2c_dev, &msgs[i], i == 0, i == num - 1);
pinctrl_pm_select_idle_state(i2c_dev->dev);
clk_disable_unprepare(i2c_dev->clk);
i2c_dev->busy = false;
return (ret < 0) ? ret : i;
}
static int st_i2c_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct st_i2c_dev *i2c_dev = platform_get_drvdata(pdev);
if (i2c_dev->busy)
return -EBUSY;
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int st_i2c_resume(struct device *dev)
{
pinctrl_pm_select_default_state(dev);
pinctrl_pm_select_idle_state(dev);
return 0;
}
static u32 st_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int st_i2c_of_get_deglitch(struct device_node *np,
struct st_i2c_dev *i2c_dev)
{
int ret;
ret = of_property_read_u32(np, "st,i2c-min-scl-pulse-width-us",
&i2c_dev->scl_min_width_us);
if ((ret == -ENODATA) || (ret == -EOVERFLOW)) {
dev_err(i2c_dev->dev, "st,i2c-min-scl-pulse-width-us invalid\n");
return ret;
}
ret = of_property_read_u32(np, "st,i2c-min-sda-pulse-width-us",
&i2c_dev->sda_min_width_us);
if ((ret == -ENODATA) || (ret == -EOVERFLOW)) {
dev_err(i2c_dev->dev, "st,i2c-min-sda-pulse-width-us invalid\n");
return ret;
}
return 0;
}
static int st_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct st_i2c_dev *i2c_dev;
struct resource *res;
u32 clk_rate;
struct i2c_adapter *adap;
int ret;
i2c_dev = devm_kzalloc(&pdev->dev, sizeof(*i2c_dev), GFP_KERNEL);
if (!i2c_dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c_dev->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c_dev->base))
return PTR_ERR(i2c_dev->base);
i2c_dev->irq = irq_of_parse_and_map(np, 0);
if (!i2c_dev->irq) {
dev_err(&pdev->dev, "IRQ missing or invalid\n");
return -EINVAL;
}
i2c_dev->clk = of_clk_get_by_name(np, "ssc");
if (IS_ERR(i2c_dev->clk)) {
dev_err(&pdev->dev, "Unable to request clock\n");
return PTR_ERR(i2c_dev->clk);
}
i2c_dev->mode = I2C_MODE_STANDARD;
ret = of_property_read_u32(np, "clock-frequency", &clk_rate);
if ((!ret) && (clk_rate == 400000))
i2c_dev->mode = I2C_MODE_FAST;
i2c_dev->dev = &pdev->dev;
ret = devm_request_threaded_irq(&pdev->dev, i2c_dev->irq,
NULL, st_i2c_isr_thread,
IRQF_ONESHOT, pdev->name, i2c_dev);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq %i\n", i2c_dev->irq);
return ret;
}
pinctrl_pm_select_default_state(i2c_dev->dev);
pinctrl_pm_select_idle_state(i2c_dev->dev);
ret = st_i2c_of_get_deglitch(np, i2c_dev);
if (ret)
return ret;
adap = &i2c_dev->adap;
i2c_set_adapdata(adap, i2c_dev);
snprintf(adap->name, sizeof(adap->name), "ST I2C(%pa)", &res->start);
adap->owner = THIS_MODULE;
adap->timeout = 2 * HZ;
adap->retries = 0;
adap->algo = &st_i2c_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
init_completion(&i2c_dev->complete);
ret = i2c_add_adapter(adap);
if (ret) {
dev_err(&pdev->dev, "Failed to add adapter\n");
return ret;
}
platform_set_drvdata(pdev, i2c_dev);
dev_info(i2c_dev->dev, "%s initialized\n", adap->name);
return 0;
}
static int st_i2c_remove(struct platform_device *pdev)
{
struct st_i2c_dev *i2c_dev = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c_dev->adap);
return 0;
}
