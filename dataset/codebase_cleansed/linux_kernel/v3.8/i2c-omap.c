static inline void omap_i2c_write_reg(struct omap_i2c_dev *i2c_dev,
int reg, u16 val)
{
__raw_writew(val, i2c_dev->base +
(i2c_dev->regs[reg] << i2c_dev->reg_shift));
}
static inline u16 omap_i2c_read_reg(struct omap_i2c_dev *i2c_dev, int reg)
{
return __raw_readw(i2c_dev->base +
(i2c_dev->regs[reg] << i2c_dev->reg_shift));
}
static void __omap_i2c_init(struct omap_i2c_dev *dev)
{
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, 0);
omap_i2c_write_reg(dev, OMAP_I2C_PSC_REG, dev->pscstate);
omap_i2c_write_reg(dev, OMAP_I2C_SCLL_REG, dev->scllstate);
omap_i2c_write_reg(dev, OMAP_I2C_SCLH_REG, dev->sclhstate);
if (dev->rev >= OMAP_I2C_REV_ON_3430_3530)
omap_i2c_write_reg(dev, OMAP_I2C_WE_REG, dev->westate);
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, OMAP_I2C_CON_EN);
if (dev->iestate)
omap_i2c_write_reg(dev, OMAP_I2C_IE_REG, dev->iestate);
}
static int omap_i2c_reset(struct omap_i2c_dev *dev)
{
unsigned long timeout;
u16 sysc;
if (dev->rev >= OMAP_I2C_OMAP1_REV_2) {
sysc = omap_i2c_read_reg(dev, OMAP_I2C_SYSC_REG);
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG,
omap_i2c_read_reg(dev, OMAP_I2C_CON_REG) &
~(OMAP_I2C_CON_EN));
omap_i2c_write_reg(dev, OMAP_I2C_SYSC_REG, SYSC_SOFTRESET_MASK);
timeout = jiffies + OMAP_I2C_TIMEOUT;
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, OMAP_I2C_CON_EN);
while (!(omap_i2c_read_reg(dev, OMAP_I2C_SYSS_REG) &
SYSS_RESETDONE_MASK)) {
if (time_after(jiffies, timeout)) {
dev_warn(dev->dev, "timeout waiting "
"for controller reset\n");
return -ETIMEDOUT;
}
msleep(1);
}
omap_i2c_write_reg(dev, OMAP_I2C_SYSC_REG, sysc);
}
return 0;
}
static int omap_i2c_init(struct omap_i2c_dev *dev)
{
u16 psc = 0, scll = 0, sclh = 0;
u16 fsscll = 0, fssclh = 0, hsscll = 0, hssclh = 0;
unsigned long fclk_rate = 12000000;
unsigned long internal_clk = 0;
struct clk *fclk;
if (dev->rev >= OMAP_I2C_REV_ON_3430_3530) {
dev->westate = OMAP_I2C_WE_ALL;
}
if (dev->flags & OMAP_I2C_FLAG_ALWAYS_ARMXOR_CLK) {
fclk = clk_get(dev->dev, "fck");
fclk_rate = clk_get_rate(fclk);
clk_put(fclk);
if (fclk_rate > 12000000)
psc = fclk_rate / 12000000;
}
if (!(dev->flags & OMAP_I2C_FLAG_SIMPLE_CLOCK)) {
if (dev->speed > 400 ||
dev->flags & OMAP_I2C_FLAG_FORCE_19200_INT_CLK)
internal_clk = 19200;
else if (dev->speed > 100)
internal_clk = 9600;
else
internal_clk = 4000;
fclk = clk_get(dev->dev, "fck");
fclk_rate = clk_get_rate(fclk) / 1000;
clk_put(fclk);
psc = fclk_rate / internal_clk;
psc = psc - 1;
if (dev->speed > 400) {
unsigned long scl;
scl = internal_clk / 400;
fsscll = scl - (scl / 3) - 7;
fssclh = (scl / 3) - 5;
scl = fclk_rate / dev->speed;
hsscll = scl - (scl / 3) - 7;
hssclh = (scl / 3) - 5;
} else if (dev->speed > 100) {
unsigned long scl;
scl = internal_clk / dev->speed;
fsscll = scl - (scl / 3) - 7;
fssclh = (scl / 3) - 5;
} else {
fsscll = internal_clk / (dev->speed * 2) - 7;
fssclh = internal_clk / (dev->speed * 2) - 5;
}
scll = (hsscll << OMAP_I2C_SCLL_HSSCLL) | fsscll;
sclh = (hssclh << OMAP_I2C_SCLH_HSSCLH) | fssclh;
} else {
fclk_rate /= (psc + 1) * 1000;
if (psc > 2)
psc = 2;
scll = fclk_rate / (dev->speed * 2) - 7 + psc;
sclh = fclk_rate / (dev->speed * 2) - 7 + psc;
}
dev->iestate = (OMAP_I2C_IE_XRDY | OMAP_I2C_IE_RRDY |
OMAP_I2C_IE_ARDY | OMAP_I2C_IE_NACK |
OMAP_I2C_IE_AL) | ((dev->fifo_size) ?
(OMAP_I2C_IE_RDR | OMAP_I2C_IE_XDR) : 0);
dev->pscstate = psc;
dev->scllstate = scll;
dev->sclhstate = sclh;
__omap_i2c_init(dev);
return 0;
}
static int omap_i2c_wait_for_bb(struct omap_i2c_dev *dev)
{
unsigned long timeout;
timeout = jiffies + OMAP_I2C_TIMEOUT;
while (omap_i2c_read_reg(dev, OMAP_I2C_STAT_REG) & OMAP_I2C_STAT_BB) {
if (time_after(jiffies, timeout)) {
dev_warn(dev->dev, "timeout waiting for bus ready\n");
return -ETIMEDOUT;
}
msleep(1);
}
return 0;
}
static void omap_i2c_resize_fifo(struct omap_i2c_dev *dev, u8 size, bool is_rx)
{
u16 buf;
if (dev->flags & OMAP_I2C_FLAG_NO_FIFO)
return;
dev->threshold = clamp(size, (u8) 1, dev->fifo_size);
buf = omap_i2c_read_reg(dev, OMAP_I2C_BUF_REG);
if (is_rx) {
buf &= ~(0x3f << 8);
buf |= ((dev->threshold - 1) << 8) | OMAP_I2C_BUF_RXFIF_CLR;
} else {
buf &= ~0x3f;
buf |= (dev->threshold - 1) | OMAP_I2C_BUF_TXFIF_CLR;
}
omap_i2c_write_reg(dev, OMAP_I2C_BUF_REG, buf);
if (dev->rev < OMAP_I2C_REV_ON_3630)
dev->b_hw = 1;
if (dev->set_mpu_wkup_lat != NULL)
dev->latency = (1000000 * dev->threshold) /
(1000 * dev->speed / 8);
}
static int omap_i2c_xfer_msg(struct i2c_adapter *adap,
struct i2c_msg *msg, int stop)
{
struct omap_i2c_dev *dev = i2c_get_adapdata(adap);
unsigned long timeout;
u16 w;
dev_dbg(dev->dev, "addr: 0x%04x, len: %d, flags: 0x%x, stop: %d\n",
msg->addr, msg->len, msg->flags, stop);
if (msg->len == 0)
return -EINVAL;
dev->receiver = !!(msg->flags & I2C_M_RD);
omap_i2c_resize_fifo(dev, msg->len, dev->receiver);
omap_i2c_write_reg(dev, OMAP_I2C_SA_REG, msg->addr);
dev->buf = msg->buf;
dev->buf_len = msg->len;
barrier();
omap_i2c_write_reg(dev, OMAP_I2C_CNT_REG, dev->buf_len);
w = omap_i2c_read_reg(dev, OMAP_I2C_BUF_REG);
w |= OMAP_I2C_BUF_RXFIF_CLR | OMAP_I2C_BUF_TXFIF_CLR;
omap_i2c_write_reg(dev, OMAP_I2C_BUF_REG, w);
INIT_COMPLETION(dev->cmd_complete);
dev->cmd_err = 0;
w = OMAP_I2C_CON_EN | OMAP_I2C_CON_MST | OMAP_I2C_CON_STT;
if (dev->speed > 400)
w |= OMAP_I2C_CON_OPMODE_HS;
if (msg->flags & I2C_M_STOP)
stop = 1;
if (msg->flags & I2C_M_TEN)
w |= OMAP_I2C_CON_XA;
if (!(msg->flags & I2C_M_RD))
w |= OMAP_I2C_CON_TRX;
if (!dev->b_hw && stop)
w |= OMAP_I2C_CON_STP;
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, w);
if (dev->b_hw && stop) {
unsigned long delay = jiffies + OMAP_I2C_TIMEOUT;
u16 con = omap_i2c_read_reg(dev, OMAP_I2C_CON_REG);
while (con & OMAP_I2C_CON_STT) {
con = omap_i2c_read_reg(dev, OMAP_I2C_CON_REG);
if (time_after(jiffies, delay)) {
dev_err(dev->dev, "controller timed out "
"waiting for start condition to finish\n");
return -ETIMEDOUT;
}
cpu_relax();
}
w |= OMAP_I2C_CON_STP;
w &= ~OMAP_I2C_CON_STT;
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, w);
}
timeout = wait_for_completion_timeout(&dev->cmd_complete,
OMAP_I2C_TIMEOUT);
if (timeout == 0) {
dev_err(dev->dev, "controller timed out\n");
omap_i2c_reset(dev);
__omap_i2c_init(dev);
return -ETIMEDOUT;
}
if (likely(!dev->cmd_err))
return 0;
if (dev->cmd_err & (OMAP_I2C_STAT_AL | OMAP_I2C_STAT_ROVR |
OMAP_I2C_STAT_XUDF)) {
omap_i2c_reset(dev);
__omap_i2c_init(dev);
return -EIO;
}
if (dev->cmd_err & OMAP_I2C_STAT_NACK) {
if (msg->flags & I2C_M_IGNORE_NAK)
return 0;
if (stop) {
w = omap_i2c_read_reg(dev, OMAP_I2C_CON_REG);
w |= OMAP_I2C_CON_STP;
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, w);
}
return -EREMOTEIO;
}
return -EIO;
}
static int
omap_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct omap_i2c_dev *dev = i2c_get_adapdata(adap);
int i;
int r;
r = pm_runtime_get_sync(dev->dev);
if (IS_ERR_VALUE(r))
goto out;
r = omap_i2c_wait_for_bb(dev);
if (r < 0)
goto out;
if (dev->set_mpu_wkup_lat != NULL)
dev->set_mpu_wkup_lat(dev->dev, dev->latency);
for (i = 0; i < num; i++) {
r = omap_i2c_xfer_msg(adap, &msgs[i], (i == (num - 1)));
if (r != 0)
break;
}
if (r == 0)
r = num;
omap_i2c_wait_for_bb(dev);
if (dev->set_mpu_wkup_lat != NULL)
dev->set_mpu_wkup_lat(dev->dev, -1);
out:
pm_runtime_mark_last_busy(dev->dev);
pm_runtime_put_autosuspend(dev->dev);
return r;
}
static u32
omap_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK) |
I2C_FUNC_PROTOCOL_MANGLING;
}
static inline void
omap_i2c_complete_cmd(struct omap_i2c_dev *dev, u16 err)
{
dev->cmd_err |= err;
complete(&dev->cmd_complete);
}
static inline void
omap_i2c_ack_stat(struct omap_i2c_dev *dev, u16 stat)
{
omap_i2c_write_reg(dev, OMAP_I2C_STAT_REG, stat);
}
static inline void i2c_omap_errata_i207(struct omap_i2c_dev *dev, u16 stat)
{
if (stat & OMAP_I2C_STAT_RDR) {
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_RDR);
if (!(omap_i2c_read_reg(dev, OMAP_I2C_STAT_REG)
& OMAP_I2C_STAT_BB)) {
if (omap_i2c_read_reg(dev, OMAP_I2C_STAT_REG)
& OMAP_I2C_STAT_RDR) {
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_RDR);
dev_dbg(dev->dev, "RDR when bus is busy.\n");
}
}
}
}
static irqreturn_t
omap_i2c_omap1_isr(int this_irq, void *dev_id)
{
struct omap_i2c_dev *dev = dev_id;
u16 iv, w;
if (pm_runtime_suspended(dev->dev))
return IRQ_NONE;
iv = omap_i2c_read_reg(dev, OMAP_I2C_IV_REG);
switch (iv) {
case 0x00:
break;
case 0x01:
dev_err(dev->dev, "Arbitration lost\n");
omap_i2c_complete_cmd(dev, OMAP_I2C_STAT_AL);
break;
case 0x02:
omap_i2c_complete_cmd(dev, OMAP_I2C_STAT_NACK);
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, OMAP_I2C_CON_STP);
break;
case 0x03:
omap_i2c_complete_cmd(dev, 0);
break;
case 0x04:
if (dev->buf_len) {
w = omap_i2c_read_reg(dev, OMAP_I2C_DATA_REG);
*dev->buf++ = w;
dev->buf_len--;
if (dev->buf_len) {
*dev->buf++ = w >> 8;
dev->buf_len--;
}
} else
dev_err(dev->dev, "RRDY IRQ while no data requested\n");
break;
case 0x05:
if (dev->buf_len) {
w = *dev->buf++;
dev->buf_len--;
if (dev->buf_len) {
w |= *dev->buf++ << 8;
dev->buf_len--;
}
omap_i2c_write_reg(dev, OMAP_I2C_DATA_REG, w);
} else
dev_err(dev->dev, "XRDY IRQ while no data to send\n");
break;
default:
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static int errata_omap3_i462(struct omap_i2c_dev *dev)
{
unsigned long timeout = 10000;
u16 stat;
do {
stat = omap_i2c_read_reg(dev, OMAP_I2C_STAT_REG);
if (stat & OMAP_I2C_STAT_XUDF)
break;
if (stat & (OMAP_I2C_STAT_NACK | OMAP_I2C_STAT_AL)) {
omap_i2c_ack_stat(dev, (OMAP_I2C_STAT_XRDY |
OMAP_I2C_STAT_XDR));
if (stat & OMAP_I2C_STAT_NACK) {
dev->cmd_err |= OMAP_I2C_STAT_NACK;
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_NACK);
}
if (stat & OMAP_I2C_STAT_AL) {
dev_err(dev->dev, "Arbitration lost\n");
dev->cmd_err |= OMAP_I2C_STAT_AL;
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_AL);
}
return -EIO;
}
cpu_relax();
} while (--timeout);
if (!timeout) {
dev_err(dev->dev, "timeout waiting on XUDF bit\n");
return 0;
}
return 0;
}
static void omap_i2c_receive_data(struct omap_i2c_dev *dev, u8 num_bytes,
bool is_rdr)
{
u16 w;
while (num_bytes--) {
w = omap_i2c_read_reg(dev, OMAP_I2C_DATA_REG);
*dev->buf++ = w;
dev->buf_len--;
if (dev->flags & OMAP_I2C_FLAG_16BIT_DATA_REG) {
*dev->buf++ = w >> 8;
dev->buf_len--;
}
}
}
static int omap_i2c_transmit_data(struct omap_i2c_dev *dev, u8 num_bytes,
bool is_xdr)
{
u16 w;
while (num_bytes--) {
w = *dev->buf++;
dev->buf_len--;
if (dev->flags & OMAP_I2C_FLAG_16BIT_DATA_REG) {
w |= *dev->buf++ << 8;
dev->buf_len--;
}
if (dev->errata & I2C_OMAP_ERRATA_I462) {
int ret;
ret = errata_omap3_i462(dev);
if (ret < 0)
return ret;
}
omap_i2c_write_reg(dev, OMAP_I2C_DATA_REG, w);
}
return 0;
}
static irqreturn_t
omap_i2c_isr(int irq, void *dev_id)
{
struct omap_i2c_dev *dev = dev_id;
irqreturn_t ret = IRQ_HANDLED;
u16 mask;
u16 stat;
spin_lock(&dev->lock);
mask = omap_i2c_read_reg(dev, OMAP_I2C_IE_REG);
stat = omap_i2c_read_reg(dev, OMAP_I2C_STAT_REG);
if (stat & mask)
ret = IRQ_WAKE_THREAD;
spin_unlock(&dev->lock);
return ret;
}
static irqreturn_t
omap_i2c_isr_thread(int this_irq, void *dev_id)
{
struct omap_i2c_dev *dev = dev_id;
unsigned long flags;
u16 bits;
u16 stat;
int err = 0, count = 0;
spin_lock_irqsave(&dev->lock, flags);
do {
bits = omap_i2c_read_reg(dev, OMAP_I2C_IE_REG);
stat = omap_i2c_read_reg(dev, OMAP_I2C_STAT_REG);
stat &= bits;
if (dev->receiver)
stat &= ~(OMAP_I2C_STAT_XDR | OMAP_I2C_STAT_XRDY);
else
stat &= ~(OMAP_I2C_STAT_RDR | OMAP_I2C_STAT_RRDY);
if (!stat) {
goto out;
}
dev_dbg(dev->dev, "IRQ (ISR = 0x%04x)\n", stat);
if (count++ == 100) {
dev_warn(dev->dev, "Too much work in one IRQ\n");
break;
}
if (stat & OMAP_I2C_STAT_NACK) {
err |= OMAP_I2C_STAT_NACK;
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_NACK);
break;
}
if (stat & OMAP_I2C_STAT_AL) {
dev_err(dev->dev, "Arbitration lost\n");
err |= OMAP_I2C_STAT_AL;
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_AL);
break;
}
if (stat & (OMAP_I2C_STAT_ARDY | OMAP_I2C_STAT_NACK |
OMAP_I2C_STAT_AL)) {
omap_i2c_ack_stat(dev, (OMAP_I2C_STAT_RRDY |
OMAP_I2C_STAT_RDR |
OMAP_I2C_STAT_XRDY |
OMAP_I2C_STAT_XDR |
OMAP_I2C_STAT_ARDY));
break;
}
if (stat & OMAP_I2C_STAT_RDR) {
u8 num_bytes = 1;
if (dev->fifo_size)
num_bytes = dev->buf_len;
omap_i2c_receive_data(dev, num_bytes, true);
if (dev->errata & I2C_OMAP_ERRATA_I207)
i2c_omap_errata_i207(dev, stat);
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_RDR);
continue;
}
if (stat & OMAP_I2C_STAT_RRDY) {
u8 num_bytes = 1;
if (dev->threshold)
num_bytes = dev->threshold;
omap_i2c_receive_data(dev, num_bytes, false);
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_RRDY);
continue;
}
if (stat & OMAP_I2C_STAT_XDR) {
u8 num_bytes = 1;
int ret;
if (dev->fifo_size)
num_bytes = dev->buf_len;
ret = omap_i2c_transmit_data(dev, num_bytes, true);
if (ret < 0)
break;
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_XDR);
continue;
}
if (stat & OMAP_I2C_STAT_XRDY) {
u8 num_bytes = 1;
int ret;
if (dev->threshold)
num_bytes = dev->threshold;
ret = omap_i2c_transmit_data(dev, num_bytes, false);
if (ret < 0)
break;
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_XRDY);
continue;
}
if (stat & OMAP_I2C_STAT_ROVR) {
dev_err(dev->dev, "Receive overrun\n");
err |= OMAP_I2C_STAT_ROVR;
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_ROVR);
break;
}
if (stat & OMAP_I2C_STAT_XUDF) {
dev_err(dev->dev, "Transmit underflow\n");
err |= OMAP_I2C_STAT_XUDF;
omap_i2c_ack_stat(dev, OMAP_I2C_STAT_XUDF);
break;
}
} while (stat);
omap_i2c_complete_cmd(dev, err);
out:
spin_unlock_irqrestore(&dev->lock, flags);
return IRQ_HANDLED;
}
static int
omap_i2c_probe(struct platform_device *pdev)
{
struct omap_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *mem;
const struct omap_i2c_bus_platform_data *pdata =
pdev->dev.platform_data;
struct device_node *node = pdev->dev.of_node;
const struct of_device_id *match;
int irq;
int r;
u32 rev;
u16 minor, major, scheme;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -ENODEV;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
dev = devm_kzalloc(&pdev->dev, sizeof(struct omap_i2c_dev), GFP_KERNEL);
if (!dev) {
dev_err(&pdev->dev, "Menory allocation failed\n");
return -ENOMEM;
}
dev->base = devm_request_and_ioremap(&pdev->dev, mem);
if (!dev->base) {
dev_err(&pdev->dev, "I2C region already claimed\n");
return -ENOMEM;
}
match = of_match_device(of_match_ptr(omap_i2c_of_match), &pdev->dev);
if (match) {
u32 freq = 100000;
pdata = match->data;
dev->flags = pdata->flags;
of_property_read_u32(node, "clock-frequency", &freq);
dev->speed = freq / 1000;
} else if (pdata != NULL) {
dev->speed = pdata->clkrate;
dev->flags = pdata->flags;
dev->set_mpu_wkup_lat = pdata->set_mpu_wkup_lat;
}
dev->pins = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(dev->pins)) {
if (PTR_ERR(dev->pins) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_warn(&pdev->dev, "did not get pins for i2c error: %li\n",
PTR_ERR(dev->pins));
dev->pins = NULL;
}
dev->dev = &pdev->dev;
dev->irq = irq;
spin_lock_init(&dev->lock);
platform_set_drvdata(pdev, dev);
init_completion(&dev->cmd_complete);
dev->reg_shift = (dev->flags >> OMAP_I2C_FLAG_BUS_SHIFT__SHIFT) & 3;
pm_runtime_enable(dev->dev);
pm_runtime_set_autosuspend_delay(dev->dev, OMAP_I2C_PM_TIMEOUT);
pm_runtime_use_autosuspend(dev->dev);
r = pm_runtime_get_sync(dev->dev);
if (IS_ERR_VALUE(r))
goto err_free_mem;
rev = __raw_readw(dev->base + 0x04);
scheme = OMAP_I2C_SCHEME(rev);
switch (scheme) {
case OMAP_I2C_SCHEME_0:
dev->regs = (u8 *)reg_map_ip_v1;
dev->rev = omap_i2c_read_reg(dev, OMAP_I2C_REV_REG);
minor = OMAP_I2C_REV_SCHEME_0_MAJOR(dev->rev);
major = OMAP_I2C_REV_SCHEME_0_MAJOR(dev->rev);
break;
case OMAP_I2C_SCHEME_1:
default:
dev->regs = (u8 *)reg_map_ip_v2;
rev = (rev << 16) |
omap_i2c_read_reg(dev, OMAP_I2C_IP_V2_REVNB_LO);
minor = OMAP_I2C_REV_SCHEME_1_MINOR(rev);
major = OMAP_I2C_REV_SCHEME_1_MAJOR(rev);
dev->rev = rev;
}
dev->errata = 0;
if (dev->rev >= OMAP_I2C_REV_ON_2430 &&
dev->rev < OMAP_I2C_REV_ON_4430_PLUS)
dev->errata |= I2C_OMAP_ERRATA_I207;
if (dev->rev <= OMAP_I2C_REV_ON_3430_3530)
dev->errata |= I2C_OMAP_ERRATA_I462;
if (!(dev->flags & OMAP_I2C_FLAG_NO_FIFO)) {
u16 s;
s = (omap_i2c_read_reg(dev, OMAP_I2C_BUFSTAT_REG) >> 14) & 0x3;
dev->fifo_size = 0x8 << s;
dev->fifo_size = (dev->fifo_size / 2);
if (dev->rev < OMAP_I2C_REV_ON_3630)
dev->b_hw = 1;
if (dev->set_mpu_wkup_lat != NULL)
dev->latency = (1000000 * dev->fifo_size) /
(1000 * dev->speed / 8);
}
omap_i2c_init(dev);
if (dev->rev < OMAP_I2C_OMAP1_REV_2)
r = devm_request_irq(&pdev->dev, dev->irq, omap_i2c_omap1_isr,
IRQF_NO_SUSPEND, pdev->name, dev);
else
r = devm_request_threaded_irq(&pdev->dev, dev->irq,
omap_i2c_isr, omap_i2c_isr_thread,
IRQF_NO_SUSPEND | IRQF_ONESHOT,
pdev->name, dev);
if (r) {
dev_err(dev->dev, "failure requesting irq %i\n", dev->irq);
goto err_unuse_clocks;
}
adap = &dev->adapter;
i2c_set_adapdata(adap, dev);
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_HWMON;
strlcpy(adap->name, "OMAP I2C adapter", sizeof(adap->name));
adap->algo = &omap_i2c_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
adap->nr = pdev->id;
r = i2c_add_numbered_adapter(adap);
if (r) {
dev_err(dev->dev, "failure adding adapter\n");
goto err_unuse_clocks;
}
dev_info(dev->dev, "bus %d rev%d.%d at %d kHz\n", adap->nr,
major, minor, dev->speed);
of_i2c_register_devices(adap);
pm_runtime_mark_last_busy(dev->dev);
pm_runtime_put_autosuspend(dev->dev);
return 0;
err_unuse_clocks:
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, 0);
pm_runtime_put(dev->dev);
pm_runtime_disable(&pdev->dev);
err_free_mem:
platform_set_drvdata(pdev, NULL);
return r;
}
static int omap_i2c_remove(struct platform_device *pdev)
{
struct omap_i2c_dev *dev = platform_get_drvdata(pdev);
int ret;
platform_set_drvdata(pdev, NULL);
i2c_del_adapter(&dev->adapter);
ret = pm_runtime_get_sync(&pdev->dev);
if (IS_ERR_VALUE(ret))
return ret;
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, 0);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int omap_i2c_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_i2c_dev *_dev = platform_get_drvdata(pdev);
_dev->iestate = omap_i2c_read_reg(_dev, OMAP_I2C_IE_REG);
omap_i2c_write_reg(_dev, OMAP_I2C_IE_REG, 0);
if (_dev->rev < OMAP_I2C_OMAP1_REV_2) {
omap_i2c_read_reg(_dev, OMAP_I2C_IV_REG);
} else {
omap_i2c_write_reg(_dev, OMAP_I2C_STAT_REG, _dev->iestate);
omap_i2c_read_reg(_dev, OMAP_I2C_STAT_REG);
}
return 0;
}
static int omap_i2c_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_i2c_dev *_dev = platform_get_drvdata(pdev);
if (!_dev->regs)
return 0;
__omap_i2c_init(_dev);
return 0;
}
static int __init
omap_i2c_init_driver(void)
{
return platform_driver_register(&omap_i2c_driver);
}
static void __exit omap_i2c_exit_driver(void)
{
platform_driver_unregister(&omap_i2c_driver);
}
