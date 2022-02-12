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
static int omap_i2c_init(struct omap_i2c_dev *dev)
{
u16 psc = 0, scll = 0, sclh = 0, buf = 0;
u16 fsscll = 0, fssclh = 0, hsscll = 0, hssclh = 0;
unsigned long fclk_rate = 12000000;
unsigned long timeout;
unsigned long internal_clk = 0;
struct clk *fclk;
if (dev->rev >= OMAP_I2C_OMAP1_REV_2) {
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
if (dev->rev == OMAP_I2C_REV_ON_2430) {
omap_i2c_write_reg(dev, OMAP_I2C_SYSC_REG,
SYSC_AUTOIDLE_MASK);
} else if (dev->rev >= OMAP_I2C_REV_ON_3430_3530) {
dev->syscstate = SYSC_AUTOIDLE_MASK;
dev->syscstate |= SYSC_ENAWAKEUP_MASK;
dev->syscstate |= (SYSC_IDLEMODE_SMART <<
__ffs(SYSC_SIDLEMODE_MASK));
dev->syscstate |= (SYSC_CLOCKACTIVITY_FCLK <<
__ffs(SYSC_CLOCKACTIVITY_MASK));
omap_i2c_write_reg(dev, OMAP_I2C_SYSC_REG,
dev->syscstate);
dev->westate = OMAP_I2C_WE_ALL;
omap_i2c_write_reg(dev, OMAP_I2C_WE_REG,
dev->westate);
}
}
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, 0);
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
omap_i2c_write_reg(dev, OMAP_I2C_PSC_REG, psc);
omap_i2c_write_reg(dev, OMAP_I2C_SCLL_REG, scll);
omap_i2c_write_reg(dev, OMAP_I2C_SCLH_REG, sclh);
if (dev->fifo_size) {
buf = (dev->fifo_size - 1) << 8 | OMAP_I2C_BUF_RXFIF_CLR |
(dev->fifo_size - 1) | OMAP_I2C_BUF_TXFIF_CLR;
omap_i2c_write_reg(dev, OMAP_I2C_BUF_REG, buf);
}
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, OMAP_I2C_CON_EN);
dev->iestate = (OMAP_I2C_IE_XRDY | OMAP_I2C_IE_RRDY |
OMAP_I2C_IE_ARDY | OMAP_I2C_IE_NACK |
OMAP_I2C_IE_AL) | ((dev->fifo_size) ?
(OMAP_I2C_IE_RDR | OMAP_I2C_IE_XDR) : 0);
omap_i2c_write_reg(dev, OMAP_I2C_IE_REG, dev->iestate);
if (dev->flags & OMAP_I2C_FLAG_RESET_REGS_POSTIDLE) {
dev->pscstate = psc;
dev->scllstate = scll;
dev->sclhstate = sclh;
dev->bufstate = buf;
}
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
omap_i2c_write_reg(dev, OMAP_I2C_SA_REG, msg->addr);
dev->buf = msg->buf;
dev->buf_len = msg->len;
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
dev->buf_len = 0;
if (timeout == 0) {
dev_err(dev->dev, "controller timed out\n");
omap_i2c_init(dev);
return -ETIMEDOUT;
}
if (likely(!dev->cmd_err))
return 0;
if (dev->cmd_err & (OMAP_I2C_STAT_AL | OMAP_I2C_STAT_ROVR |
OMAP_I2C_STAT_XUDF)) {
omap_i2c_init(dev);
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
if (dev->set_mpu_wkup_lat != NULL)
dev->set_mpu_wkup_lat(dev->dev, -1);
if (r == 0)
r = num;
omap_i2c_wait_for_bb(dev);
out:
pm_runtime_put(dev->dev);
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
static int errata_omap3_i462(struct omap_i2c_dev *dev, u16 *stat, int *err)
{
unsigned long timeout = 10000;
while (--timeout && !(*stat & OMAP_I2C_STAT_XUDF)) {
if (*stat & (OMAP_I2C_STAT_NACK | OMAP_I2C_STAT_AL)) {
omap_i2c_ack_stat(dev, *stat & (OMAP_I2C_STAT_XRDY |
OMAP_I2C_STAT_XDR));
return -ETIMEDOUT;
}
cpu_relax();
*stat = omap_i2c_read_reg(dev, OMAP_I2C_STAT_REG);
}
if (!timeout) {
dev_err(dev->dev, "timeout waiting on XUDF bit\n");
return 0;
}
*err |= OMAP_I2C_STAT_XUDF;
return 0;
}
static irqreturn_t
omap_i2c_isr(int this_irq, void *dev_id)
{
struct omap_i2c_dev *dev = dev_id;
u16 bits;
u16 stat, w;
int err, count = 0;
if (pm_runtime_suspended(dev->dev))
return IRQ_NONE;
bits = omap_i2c_read_reg(dev, OMAP_I2C_IE_REG);
while ((stat = (omap_i2c_read_reg(dev, OMAP_I2C_STAT_REG))) & bits) {
dev_dbg(dev->dev, "IRQ (ISR = 0x%04x)\n", stat);
if (count++ == 100) {
dev_warn(dev->dev, "Too much work in one IRQ\n");
break;
}
err = 0;
complete:
omap_i2c_write_reg(dev, OMAP_I2C_STAT_REG, stat &
~(OMAP_I2C_STAT_RRDY | OMAP_I2C_STAT_RDR |
OMAP_I2C_STAT_XRDY | OMAP_I2C_STAT_XDR));
if (stat & OMAP_I2C_STAT_NACK)
err |= OMAP_I2C_STAT_NACK;
if (stat & OMAP_I2C_STAT_AL) {
dev_err(dev->dev, "Arbitration lost\n");
err |= OMAP_I2C_STAT_AL;
}
if (stat & (OMAP_I2C_STAT_ARDY | OMAP_I2C_STAT_NACK |
OMAP_I2C_STAT_AL)) {
omap_i2c_ack_stat(dev, stat &
(OMAP_I2C_STAT_RRDY | OMAP_I2C_STAT_RDR |
OMAP_I2C_STAT_XRDY | OMAP_I2C_STAT_XDR |
OMAP_I2C_STAT_ARDY));
omap_i2c_complete_cmd(dev, err);
return IRQ_HANDLED;
}
if (stat & (OMAP_I2C_STAT_RRDY | OMAP_I2C_STAT_RDR)) {
u8 num_bytes = 1;
if (dev->errata & I2C_OMAP_ERRATA_I207)
i2c_omap_errata_i207(dev, stat);
if (dev->fifo_size) {
if (stat & OMAP_I2C_STAT_RRDY)
num_bytes = dev->fifo_size;
else
num_bytes = (omap_i2c_read_reg(dev,
OMAP_I2C_BUFSTAT_REG)
>> 8) & 0x3F;
}
while (num_bytes) {
num_bytes--;
w = omap_i2c_read_reg(dev, OMAP_I2C_DATA_REG);
if (dev->buf_len) {
*dev->buf++ = w;
dev->buf_len--;
if (dev->flags &
OMAP_I2C_FLAG_16BIT_DATA_REG) {
if (dev->buf_len) {
*dev->buf++ = w >> 8;
dev->buf_len--;
}
}
} else {
if (stat & OMAP_I2C_STAT_RRDY)
dev_err(dev->dev,
"RRDY IRQ while no data"
" requested\n");
if (stat & OMAP_I2C_STAT_RDR)
dev_err(dev->dev,
"RDR IRQ while no data"
" requested\n");
break;
}
}
omap_i2c_ack_stat(dev,
stat & (OMAP_I2C_STAT_RRDY | OMAP_I2C_STAT_RDR));
continue;
}
if (stat & (OMAP_I2C_STAT_XRDY | OMAP_I2C_STAT_XDR)) {
u8 num_bytes = 1;
if (dev->fifo_size) {
if (stat & OMAP_I2C_STAT_XRDY)
num_bytes = dev->fifo_size;
else
num_bytes = omap_i2c_read_reg(dev,
OMAP_I2C_BUFSTAT_REG)
& 0x3F;
}
while (num_bytes) {
num_bytes--;
w = 0;
if (dev->buf_len) {
w = *dev->buf++;
dev->buf_len--;
if (dev->flags &
OMAP_I2C_FLAG_16BIT_DATA_REG) {
if (dev->buf_len) {
w |= *dev->buf++ << 8;
dev->buf_len--;
}
}
} else {
if (stat & OMAP_I2C_STAT_XRDY)
dev_err(dev->dev,
"XRDY IRQ while no "
"data to send\n");
if (stat & OMAP_I2C_STAT_XDR)
dev_err(dev->dev,
"XDR IRQ while no "
"data to send\n");
break;
}
if ((dev->errata & I2C_OMAP_ERRATA_I462) &&
errata_omap3_i462(dev, &stat, &err))
goto complete;
omap_i2c_write_reg(dev, OMAP_I2C_DATA_REG, w);
}
omap_i2c_ack_stat(dev,
stat & (OMAP_I2C_STAT_XRDY | OMAP_I2C_STAT_XDR));
continue;
}
if (stat & OMAP_I2C_STAT_ROVR) {
dev_err(dev->dev, "Receive overrun\n");
dev->cmd_err |= OMAP_I2C_STAT_ROVR;
}
if (stat & OMAP_I2C_STAT_XUDF) {
dev_err(dev->dev, "Transmit underflow\n");
dev->cmd_err |= OMAP_I2C_STAT_XUDF;
}
}
return count ? IRQ_HANDLED : IRQ_NONE;
}
static int __devinit
omap_i2c_probe(struct platform_device *pdev)
{
struct omap_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *mem, *irq, *ioarea;
struct omap_i2c_bus_platform_data *pdata = pdev->dev.platform_data;
struct device_node *node = pdev->dev.of_node;
const struct of_device_id *match;
irq_handler_t isr;
int r;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -ENODEV;
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq) {
dev_err(&pdev->dev, "no irq resource?\n");
return -ENODEV;
}
ioarea = request_mem_region(mem->start, resource_size(mem),
pdev->name);
if (!ioarea) {
dev_err(&pdev->dev, "I2C region already claimed\n");
return -EBUSY;
}
dev = kzalloc(sizeof(struct omap_i2c_dev), GFP_KERNEL);
if (!dev) {
r = -ENOMEM;
goto err_release_region;
}
match = of_match_device(of_match_ptr(omap_i2c_of_match), &pdev->dev);
if (match) {
u32 freq = 100000;
pdata = match->data;
dev->dtrev = pdata->rev;
dev->flags = pdata->flags;
of_property_read_u32(node, "clock-frequency", &freq);
dev->speed = freq / 1000;
} else if (pdata != NULL) {
dev->speed = pdata->clkrate;
dev->flags = pdata->flags;
dev->set_mpu_wkup_lat = pdata->set_mpu_wkup_lat;
dev->dtrev = pdata->rev;
}
dev->dev = &pdev->dev;
dev->irq = irq->start;
dev->base = ioremap(mem->start, resource_size(mem));
if (!dev->base) {
r = -ENOMEM;
goto err_free_mem;
}
platform_set_drvdata(pdev, dev);
init_completion(&dev->cmd_complete);
dev->reg_shift = (dev->flags >> OMAP_I2C_FLAG_BUS_SHIFT__SHIFT) & 3;
if (dev->dtrev == OMAP_I2C_IP_VERSION_2)
dev->regs = (u8 *)reg_map_ip_v2;
else
dev->regs = (u8 *)reg_map_ip_v1;
pm_runtime_enable(dev->dev);
r = pm_runtime_get_sync(dev->dev);
if (IS_ERR_VALUE(r))
goto err_free_mem;
dev->rev = omap_i2c_read_reg(dev, OMAP_I2C_REV_REG) & 0xff;
dev->errata = 0;
if (dev->flags & OMAP_I2C_FLAG_APPLY_ERRATA_I207)
dev->errata |= I2C_OMAP_ERRATA_I207;
if (dev->rev <= OMAP_I2C_REV_ON_3430_3530)
dev->errata |= I2C_OMAP_ERRATA_I462;
if (!(dev->flags & OMAP_I2C_FLAG_NO_FIFO)) {
u16 s;
s = (omap_i2c_read_reg(dev, OMAP_I2C_BUFSTAT_REG) >> 14) & 0x3;
dev->fifo_size = 0x8 << s;
dev->fifo_size = (dev->fifo_size / 2);
if (dev->rev >= OMAP_I2C_REV_ON_3630_4430)
dev->b_hw = 0;
else
dev->b_hw = 1;
if (dev->set_mpu_wkup_lat != NULL)
dev->latency = (1000000 * dev->fifo_size) /
(1000 * dev->speed / 8);
}
omap_i2c_init(dev);
isr = (dev->rev < OMAP_I2C_OMAP1_REV_2) ? omap_i2c_omap1_isr :
omap_i2c_isr;
r = request_irq(dev->irq, isr, IRQF_NO_SUSPEND, pdev->name, dev);
if (r) {
dev_err(dev->dev, "failure requesting irq %i\n", dev->irq);
goto err_unuse_clocks;
}
dev_info(dev->dev, "bus %d rev%d.%d.%d at %d kHz\n", pdev->id,
dev->dtrev, dev->rev >> 4, dev->rev & 0xf, dev->speed);
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
goto err_free_irq;
}
of_i2c_register_devices(adap);
pm_runtime_put(dev->dev);
return 0;
err_free_irq:
free_irq(dev->irq, dev);
err_unuse_clocks:
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, 0);
pm_runtime_put(dev->dev);
iounmap(dev->base);
pm_runtime_disable(&pdev->dev);
err_free_mem:
platform_set_drvdata(pdev, NULL);
kfree(dev);
err_release_region:
release_mem_region(mem->start, resource_size(mem));
return r;
}
static int __devexit omap_i2c_remove(struct platform_device *pdev)
{
struct omap_i2c_dev *dev = platform_get_drvdata(pdev);
struct resource *mem;
int ret;
platform_set_drvdata(pdev, NULL);
free_irq(dev->irq, dev);
i2c_del_adapter(&dev->adapter);
ret = pm_runtime_get_sync(&pdev->dev);
if (IS_ERR_VALUE(ret))
return ret;
omap_i2c_write_reg(dev, OMAP_I2C_CON_REG, 0);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
iounmap(dev->base);
kfree(dev);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
return 0;
}
static int omap_i2c_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct omap_i2c_dev *_dev = platform_get_drvdata(pdev);
u16 iv;
_dev->iestate = omap_i2c_read_reg(_dev, OMAP_I2C_IE_REG);
omap_i2c_write_reg(_dev, OMAP_I2C_IE_REG, 0);
if (_dev->rev < OMAP_I2C_OMAP1_REV_2) {
iv = omap_i2c_read_reg(_dev, OMAP_I2C_IV_REG);
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
if (_dev->flags & OMAP_I2C_FLAG_RESET_REGS_POSTIDLE) {
omap_i2c_write_reg(_dev, OMAP_I2C_CON_REG, 0);
omap_i2c_write_reg(_dev, OMAP_I2C_PSC_REG, _dev->pscstate);
omap_i2c_write_reg(_dev, OMAP_I2C_SCLL_REG, _dev->scllstate);
omap_i2c_write_reg(_dev, OMAP_I2C_SCLH_REG, _dev->sclhstate);
omap_i2c_write_reg(_dev, OMAP_I2C_BUF_REG, _dev->bufstate);
omap_i2c_write_reg(_dev, OMAP_I2C_SYSC_REG, _dev->syscstate);
omap_i2c_write_reg(_dev, OMAP_I2C_WE_REG, _dev->westate);
omap_i2c_write_reg(_dev, OMAP_I2C_CON_REG, OMAP_I2C_CON_EN);
}
if (_dev->iestate)
omap_i2c_write_reg(_dev, OMAP_I2C_IE_REG, _dev->iestate);
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
