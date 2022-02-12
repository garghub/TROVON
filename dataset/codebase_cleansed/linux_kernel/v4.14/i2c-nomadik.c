static inline void i2c_set_bit(void __iomem *reg, u32 mask)
{
writel(readl(reg) | mask, reg);
}
static inline void i2c_clr_bit(void __iomem *reg, u32 mask)
{
writel(readl(reg) & ~mask, reg);
}
static int flush_i2c_fifo(struct nmk_i2c_dev *dev)
{
#define LOOP_ATTEMPTS 10
int i;
unsigned long timeout;
writel((I2C_CR_FTX | I2C_CR_FRX), dev->virtbase + I2C_CR);
for (i = 0; i < LOOP_ATTEMPTS; i++) {
timeout = jiffies + dev->adap.timeout;
while (!time_after(jiffies, timeout)) {
if ((readl(dev->virtbase + I2C_CR) &
(I2C_CR_FTX | I2C_CR_FRX)) == 0)
return 0;
}
}
dev_err(&dev->adev->dev,
"flushing operation timed out giving up after %d attempts",
LOOP_ATTEMPTS);
return -ETIMEDOUT;
}
static void disable_all_interrupts(struct nmk_i2c_dev *dev)
{
u32 mask = IRQ_MASK(0);
writel(mask, dev->virtbase + I2C_IMSCR);
}
static void clear_all_interrupts(struct nmk_i2c_dev *dev)
{
u32 mask;
mask = IRQ_MASK(I2C_CLEAR_ALL_INTS);
writel(mask, dev->virtbase + I2C_ICR);
}
static int init_hw(struct nmk_i2c_dev *dev)
{
int stat;
stat = flush_i2c_fifo(dev);
if (stat)
goto exit;
i2c_clr_bit(dev->virtbase + I2C_CR , I2C_CR_PE);
disable_all_interrupts(dev);
clear_all_interrupts(dev);
dev->cli.operation = I2C_NO_OPERATION;
exit:
return stat;
}
static u32 load_i2c_mcr_reg(struct nmk_i2c_dev *dev, u16 flags)
{
u32 mcr = 0;
unsigned short slave_adr_3msb_bits;
mcr |= GEN_MASK(dev->cli.slave_adr, I2C_MCR_A7, 1);
if (unlikely(flags & I2C_M_TEN)) {
mcr |= GEN_MASK(2, I2C_MCR_AM, 12);
slave_adr_3msb_bits = (dev->cli.slave_adr >> 7) & 0x7;
mcr |= GEN_MASK(slave_adr_3msb_bits, I2C_MCR_EA10, 8);
} else {
mcr |= GEN_MASK(1, I2C_MCR_AM, 12);
}
mcr |= GEN_MASK(0, I2C_MCR_SB, 11);
if (dev->cli.operation == I2C_WRITE)
mcr |= GEN_MASK(I2C_WRITE, I2C_MCR_OP, 0);
else
mcr |= GEN_MASK(I2C_READ, I2C_MCR_OP, 0);
if (dev->stop)
mcr |= GEN_MASK(1, I2C_MCR_STOP, 14);
else
mcr &= ~(GEN_MASK(1, I2C_MCR_STOP, 14));
mcr |= GEN_MASK(dev->cli.count, I2C_MCR_LENGTH, 15);
return mcr;
}
static void setup_i2c_controller(struct nmk_i2c_dev *dev)
{
u32 brcr1, brcr2;
u32 i2c_clk, div;
u32 ns;
u16 slsu;
writel(0x0, dev->virtbase + I2C_CR);
writel(0x0, dev->virtbase + I2C_HSMCR);
writel(0x0, dev->virtbase + I2C_TFTR);
writel(0x0, dev->virtbase + I2C_RFTR);
writel(0x0, dev->virtbase + I2C_DMAR);
i2c_clk = clk_get_rate(dev->clk);
ns = DIV_ROUND_UP_ULL(1000000000ULL, i2c_clk);
switch (dev->sm) {
case I2C_FREQ_MODE_FAST:
case I2C_FREQ_MODE_FAST_PLUS:
slsu = DIV_ROUND_UP(100, ns);
break;
case I2C_FREQ_MODE_HIGH_SPEED:
slsu = DIV_ROUND_UP(10, ns);
break;
case I2C_FREQ_MODE_STANDARD:
default:
slsu = DIV_ROUND_UP(250, ns);
break;
}
slsu += 1;
dev_dbg(&dev->adev->dev, "calculated SLSU = %04x\n", slsu);
writel(slsu << 16, dev->virtbase + I2C_SCR);
div = (dev->clk_freq > 100000) ? 3 : 2;
brcr1 = 0 << 16;
brcr2 = (i2c_clk/(dev->clk_freq * div)) & 0xffff;
writel((brcr1 | brcr2), dev->virtbase + I2C_BRCR);
if (dev->sm > I2C_FREQ_MODE_FAST) {
dev_err(&dev->adev->dev,
"do not support this mode defaulting to std. mode\n");
brcr2 = i2c_clk/(100000 * 2) & 0xffff;
writel((brcr1 | brcr2), dev->virtbase + I2C_BRCR);
writel(I2C_FREQ_MODE_STANDARD << 4,
dev->virtbase + I2C_CR);
}
writel(dev->sm << 4, dev->virtbase + I2C_CR);
writel(dev->tft, dev->virtbase + I2C_TFTR);
writel(dev->rft, dev->virtbase + I2C_RFTR);
}
static int read_i2c(struct nmk_i2c_dev *dev, u16 flags)
{
int status = 0;
u32 mcr, irq_mask;
unsigned long timeout;
mcr = load_i2c_mcr_reg(dev, flags);
writel(mcr, dev->virtbase + I2C_MCR);
writel(readl(dev->virtbase + I2C_CR) | DEFAULT_I2C_REG_CR,
dev->virtbase + I2C_CR);
i2c_set_bit(dev->virtbase + I2C_CR, I2C_CR_PE);
init_completion(&dev->xfer_complete);
irq_mask = (I2C_IT_RXFNF | I2C_IT_RXFF |
I2C_IT_MAL | I2C_IT_BERR);
if (dev->stop || !dev->vendor->has_mtdws)
irq_mask |= I2C_IT_MTD;
else
irq_mask |= I2C_IT_MTDWS;
irq_mask = I2C_CLEAR_ALL_INTS & IRQ_MASK(irq_mask);
writel(readl(dev->virtbase + I2C_IMSCR) | irq_mask,
dev->virtbase + I2C_IMSCR);
timeout = wait_for_completion_timeout(
&dev->xfer_complete, dev->adap.timeout);
if (timeout == 0) {
dev_err(&dev->adev->dev, "read from slave 0x%x timed out\n",
dev->cli.slave_adr);
status = -ETIMEDOUT;
}
return status;
}
static void fill_tx_fifo(struct nmk_i2c_dev *dev, int no_bytes)
{
int count;
for (count = (no_bytes - 2);
(count > 0) &&
(dev->cli.count != 0);
count--) {
writeb(*dev->cli.buffer,
dev->virtbase + I2C_TFR);
dev->cli.buffer++;
dev->cli.count--;
dev->cli.xfer_bytes++;
}
}
static int write_i2c(struct nmk_i2c_dev *dev, u16 flags)
{
u32 status = 0;
u32 mcr, irq_mask;
unsigned long timeout;
mcr = load_i2c_mcr_reg(dev, flags);
writel(mcr, dev->virtbase + I2C_MCR);
writel(readl(dev->virtbase + I2C_CR) | DEFAULT_I2C_REG_CR,
dev->virtbase + I2C_CR);
i2c_set_bit(dev->virtbase + I2C_CR , I2C_CR_PE);
init_completion(&dev->xfer_complete);
irq_mask = (I2C_IT_TXFOVR | I2C_IT_MAL | I2C_IT_BERR);
fill_tx_fifo(dev, MAX_I2C_FIFO_THRESHOLD);
if (dev->cli.count != 0)
irq_mask |= I2C_IT_TXFNE;
if (dev->stop || !dev->vendor->has_mtdws)
irq_mask |= I2C_IT_MTD;
else
irq_mask |= I2C_IT_MTDWS;
irq_mask = I2C_CLEAR_ALL_INTS & IRQ_MASK(irq_mask);
writel(readl(dev->virtbase + I2C_IMSCR) | irq_mask,
dev->virtbase + I2C_IMSCR);
timeout = wait_for_completion_timeout(
&dev->xfer_complete, dev->adap.timeout);
if (timeout == 0) {
dev_err(&dev->adev->dev, "write to slave 0x%x timed out\n",
dev->cli.slave_adr);
status = -ETIMEDOUT;
}
return status;
}
static int nmk_i2c_xfer_one(struct nmk_i2c_dev *dev, u16 flags)
{
int status;
if (flags & I2C_M_RD) {
dev->cli.operation = I2C_READ;
status = read_i2c(dev, flags);
} else {
dev->cli.operation = I2C_WRITE;
status = write_i2c(dev, flags);
}
if (status || (dev->result)) {
u32 i2c_sr;
u32 cause;
i2c_sr = readl(dev->virtbase + I2C_SR);
if (((i2c_sr >> 2) & 0x3) == 0x3) {
cause = (i2c_sr >> 4) & 0x7;
dev_err(&dev->adev->dev, "%s\n",
cause >= ARRAY_SIZE(abort_causes) ?
"unknown reason" :
abort_causes[cause]);
}
(void) init_hw(dev);
status = status ? status : dev->result;
}
return status;
}
static int nmk_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msgs[], int num_msgs)
{
int status = 0;
int i;
struct nmk_i2c_dev *dev = i2c_get_adapdata(i2c_adap);
int j;
pm_runtime_get_sync(&dev->adev->dev);
for (j = 0; j < 3; j++) {
setup_i2c_controller(dev);
for (i = 0; i < num_msgs; i++) {
dev->cli.slave_adr = msgs[i].addr;
dev->cli.buffer = msgs[i].buf;
dev->cli.count = msgs[i].len;
dev->stop = (i < (num_msgs - 1)) ? 0 : 1;
dev->result = 0;
status = nmk_i2c_xfer_one(dev, msgs[i].flags);
if (status != 0)
break;
}
if (status == 0)
break;
}
pm_runtime_put_sync(&dev->adev->dev);
if (status)
return status;
else
return num_msgs;
}
static int disable_interrupts(struct nmk_i2c_dev *dev, u32 irq)
{
irq = IRQ_MASK(irq);
writel(readl(dev->virtbase + I2C_IMSCR) & ~(I2C_CLEAR_ALL_INTS & irq),
dev->virtbase + I2C_IMSCR);
return 0;
}
static irqreturn_t i2c_irq_handler(int irq, void *arg)
{
struct nmk_i2c_dev *dev = arg;
u32 tft, rft;
u32 count;
u32 misr, src;
tft = readl(dev->virtbase + I2C_TFTR);
rft = readl(dev->virtbase + I2C_RFTR);
misr = readl(dev->virtbase + I2C_MISR);
src = __ffs(misr);
switch ((1 << src)) {
case I2C_IT_TXFNE:
{
if (dev->cli.operation == I2C_READ) {
disable_interrupts(dev, I2C_IT_TXFNE);
} else {
fill_tx_fifo(dev, (MAX_I2C_FIFO_THRESHOLD - tft));
if (dev->cli.count == 0)
disable_interrupts(dev, I2C_IT_TXFNE);
}
}
break;
case I2C_IT_RXFNF:
for (count = rft; count > 0; count--) {
*dev->cli.buffer = readb(dev->virtbase + I2C_RFR);
dev->cli.buffer++;
}
dev->cli.count -= rft;
dev->cli.xfer_bytes += rft;
break;
case I2C_IT_RXFF:
for (count = MAX_I2C_FIFO_THRESHOLD; count > 0; count--) {
*dev->cli.buffer = readb(dev->virtbase + I2C_RFR);
dev->cli.buffer++;
}
dev->cli.count -= MAX_I2C_FIFO_THRESHOLD;
dev->cli.xfer_bytes += MAX_I2C_FIFO_THRESHOLD;
break;
case I2C_IT_MTD:
case I2C_IT_MTDWS:
if (dev->cli.operation == I2C_READ) {
while (!(readl(dev->virtbase + I2C_RISR)
& I2C_IT_RXFE)) {
if (dev->cli.count == 0)
break;
*dev->cli.buffer =
readb(dev->virtbase + I2C_RFR);
dev->cli.buffer++;
dev->cli.count--;
dev->cli.xfer_bytes++;
}
}
disable_all_interrupts(dev);
clear_all_interrupts(dev);
if (dev->cli.count) {
dev->result = -EIO;
dev_err(&dev->adev->dev,
"%lu bytes still remain to be xfered\n",
dev->cli.count);
(void) init_hw(dev);
}
complete(&dev->xfer_complete);
break;
case I2C_IT_MAL:
dev->result = -EIO;
(void) init_hw(dev);
i2c_set_bit(dev->virtbase + I2C_ICR, I2C_IT_MAL);
complete(&dev->xfer_complete);
break;
case I2C_IT_BERR:
dev->result = -EIO;
if (((readl(dev->virtbase + I2C_SR) >> 2) & 0x3) == I2C_ABORT)
(void) init_hw(dev);
i2c_set_bit(dev->virtbase + I2C_ICR, I2C_IT_BERR);
complete(&dev->xfer_complete);
break;
case I2C_IT_TXFOVR:
dev->result = -EIO;
(void) init_hw(dev);
dev_err(&dev->adev->dev, "Tx Fifo Over run\n");
complete(&dev->xfer_complete);
break;
case I2C_IT_TXFE:
case I2C_IT_TXFF:
case I2C_IT_RXFE:
case I2C_IT_RFSR:
case I2C_IT_RFSE:
case I2C_IT_WTSR:
case I2C_IT_STD:
dev_err(&dev->adev->dev, "unhandled Interrupt\n");
break;
default:
dev_err(&dev->adev->dev, "spurious Interrupt..\n");
break;
}
return IRQ_HANDLED;
}
static int nmk_i2c_suspend_late(struct device *dev)
{
int ret;
ret = pm_runtime_force_suspend(dev);
if (ret)
return ret;
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int nmk_i2c_resume_early(struct device *dev)
{
return pm_runtime_force_resume(dev);
}
static int nmk_i2c_runtime_suspend(struct device *dev)
{
struct amba_device *adev = to_amba_device(dev);
struct nmk_i2c_dev *nmk_i2c = amba_get_drvdata(adev);
clk_disable_unprepare(nmk_i2c->clk);
pinctrl_pm_select_idle_state(dev);
return 0;
}
static int nmk_i2c_runtime_resume(struct device *dev)
{
struct amba_device *adev = to_amba_device(dev);
struct nmk_i2c_dev *nmk_i2c = amba_get_drvdata(adev);
int ret;
ret = clk_prepare_enable(nmk_i2c->clk);
if (ret) {
dev_err(dev, "can't prepare_enable clock\n");
return ret;
}
pinctrl_pm_select_default_state(dev);
ret = init_hw(nmk_i2c);
if (ret) {
clk_disable_unprepare(nmk_i2c->clk);
pinctrl_pm_select_idle_state(dev);
}
return ret;
}
static unsigned int nmk_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_10BIT_ADDR;
}
static void nmk_i2c_of_probe(struct device_node *np,
struct nmk_i2c_dev *nmk)
{
if (of_property_read_u32(np, "clock-frequency", &nmk->clk_freq))
nmk->clk_freq = 100000;
if (nmk->clk_freq <= 100000)
nmk->sm = I2C_FREQ_MODE_STANDARD;
else
nmk->sm = I2C_FREQ_MODE_FAST;
nmk->tft = 1;
nmk->rft = 8;
nmk->timeout = 200;
}
static int nmk_i2c_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret = 0;
struct device_node *np = adev->dev.of_node;
struct nmk_i2c_dev *dev;
struct i2c_adapter *adap;
struct i2c_vendor_data *vendor = id->data;
u32 max_fifo_threshold = (vendor->fifodepth / 2) - 1;
dev = devm_kzalloc(&adev->dev, sizeof(struct nmk_i2c_dev), GFP_KERNEL);
if (!dev) {
dev_err(&adev->dev, "cannot allocate memory\n");
ret = -ENOMEM;
goto err_no_mem;
}
dev->vendor = vendor;
dev->adev = adev;
nmk_i2c_of_probe(np, dev);
if (dev->tft > max_fifo_threshold) {
dev_warn(&adev->dev, "requested TX FIFO threshold %u, adjusted down to %u\n",
dev->tft, max_fifo_threshold);
dev->tft = max_fifo_threshold;
}
if (dev->rft > max_fifo_threshold) {
dev_warn(&adev->dev, "requested RX FIFO threshold %u, adjusted down to %u\n",
dev->rft, max_fifo_threshold);
dev->rft = max_fifo_threshold;
}
amba_set_drvdata(adev, dev);
dev->virtbase = devm_ioremap(&adev->dev, adev->res.start,
resource_size(&adev->res));
if (!dev->virtbase) {
ret = -ENOMEM;
goto err_no_mem;
}
dev->irq = adev->irq[0];
ret = devm_request_irq(&adev->dev, dev->irq, i2c_irq_handler, 0,
DRIVER_NAME, dev);
if (ret) {
dev_err(&adev->dev, "cannot claim the irq %d\n", dev->irq);
goto err_no_mem;
}
pm_suspend_ignore_children(&adev->dev, true);
dev->clk = devm_clk_get(&adev->dev, NULL);
if (IS_ERR(dev->clk)) {
dev_err(&adev->dev, "could not get i2c clock\n");
ret = PTR_ERR(dev->clk);
goto err_no_mem;
}
ret = clk_prepare_enable(dev->clk);
if (ret) {
dev_err(&adev->dev, "can't prepare_enable clock\n");
goto err_no_mem;
}
init_hw(dev);
adap = &dev->adap;
adap->dev.of_node = np;
adap->dev.parent = &adev->dev;
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DEPRECATED;
adap->algo = &nmk_i2c_algo;
adap->timeout = msecs_to_jiffies(dev->timeout);
snprintf(adap->name, sizeof(adap->name),
"Nomadik I2C at %pR", &adev->res);
i2c_set_adapdata(adap, dev);
dev_info(&adev->dev,
"initialize %s on virtual base %p\n",
adap->name, dev->virtbase);
ret = i2c_add_adapter(adap);
if (ret)
goto err_no_adap;
pm_runtime_put(&adev->dev);
return 0;
err_no_adap:
clk_disable_unprepare(dev->clk);
err_no_mem:
return ret;
}
static int nmk_i2c_remove(struct amba_device *adev)
{
struct resource *res = &adev->res;
struct nmk_i2c_dev *dev = amba_get_drvdata(adev);
i2c_del_adapter(&dev->adap);
flush_i2c_fifo(dev);
disable_all_interrupts(dev);
clear_all_interrupts(dev);
i2c_clr_bit(dev->virtbase + I2C_CR, I2C_CR_PE);
clk_disable_unprepare(dev->clk);
if (res)
release_mem_region(res->start, resource_size(res));
return 0;
}
static int __init nmk_i2c_init(void)
{
return amba_driver_register(&nmk_i2c_driver);
}
static void __exit nmk_i2c_exit(void)
{
amba_driver_unregister(&nmk_i2c_driver);
}
