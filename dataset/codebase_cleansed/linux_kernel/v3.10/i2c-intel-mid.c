static int intel_mid_i2c_disable(struct i2c_adapter *adap)
{
struct intel_mid_i2c_private *i2c = i2c_get_adapdata(adap);
int err = 0;
int count = 0;
int ret1, ret2;
static const u16 delay[NUM_SPEEDS] = {100, 25, 3};
writel(0, i2c->base + IC_ENABLE);
dev_dbg(&adap->dev, "mrst i2c disable\n");
while ((ret1 = readl(i2c->base + IC_ENABLE_STATUS) & 0x1)
|| (ret2 = readl(i2c->base + IC_STATUS) & 0x1)) {
udelay(delay[i2c->speed]);
writel(0, i2c->base + IC_ENABLE);
dev_dbg(&adap->dev, "i2c is busy, count is %d speed %d\n",
count, i2c->speed);
if (count++ > 10) {
err = -ETIMEDOUT;
break;
}
}
readl(i2c->base + IC_CLR_INTR);
readl(i2c->base + IC_CLR_STOP_DET);
readl(i2c->base + IC_CLR_START_DET);
readl(i2c->base + IC_CLR_ACTIVITY);
readl(i2c->base + IC_CLR_TX_ABRT);
readl(i2c->base + IC_CLR_RX_OVER);
readl(i2c->base + IC_CLR_RX_UNDER);
readl(i2c->base + IC_CLR_TX_OVER);
readl(i2c->base + IC_CLR_RX_DONE);
readl(i2c->base + IC_CLR_GEN_CALL);
writel(0x0000, i2c->base + IC_INTR_MASK);
return err;
}
static int intel_mid_i2c_hwinit(struct intel_mid_i2c_private *i2c)
{
int err;
static const u16 hcnt[NUM_PLATFORMS][NUM_SPEEDS] = {
{ 0x75, 0x15, 0x07 },
{ 0x04c, 0x10, 0x06 }
};
static const u16 lcnt[NUM_PLATFORMS][NUM_SPEEDS] = {
{ 0x7C, 0x21, 0x0E },
{ 0x053, 0x19, 0x0F }
};
err = intel_mid_i2c_disable(&i2c->adap);
if (err)
return err;
writel((i2c->speed + 1) << 1 | SLV_DIS | RESTART | MASTER_EN,
i2c->base + IC_CON);
writel(hcnt[i2c->platform][i2c->speed],
i2c->base + (IC_SS_SCL_HCNT + (i2c->speed << 3)));
writel(lcnt[i2c->platform][i2c->speed],
i2c->base + (IC_SS_SCL_LCNT + (i2c->speed << 3)));
writel(0x0, i2c->base + IC_RX_TL);
writel(0x0, i2c->base + IC_TX_TL);
return 0;
}
static u32 intel_mid_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR | I2C_FUNC_SMBUS_EMUL;
}
static inline bool intel_mid_i2c_address_neq(const struct i2c_msg *p1,
const struct i2c_msg *p2)
{
if (p1->addr != p2->addr)
return 1;
if ((p1->flags ^ p2->flags) & I2C_M_TEN)
return 1;
return 0;
}
static void intel_mid_i2c_abort(struct intel_mid_i2c_private *i2c)
{
int abort = i2c->abort;
struct i2c_adapter *adap = &i2c->adap;
if (abort & ABRT_MASTER_DIS)
dev_err(&adap->dev,
"initiate master operation with master mode disabled.\n");
if (abort & ABRT_10B_RD_NORSTRT)
dev_err(&adap->dev,
"RESTART disabled and master sent READ cmd in 10-bit addressing.\n");
if (abort & ABRT_SBYTE_NORSTRT) {
dev_err(&adap->dev,
"RESTART disabled and user is trying to send START byte.\n");
writel(~ABRT_SBYTE_NORSTRT, i2c->base + IC_TX_ABRT_SOURCE);
writel(RESTART, i2c->base + IC_CON);
writel(~IC_TAR_SPECIAL, i2c->base + IC_TAR);
}
if (abort & ABRT_SBYTE_ACKDET)
dev_err(&adap->dev,
"START byte was not acknowledged.\n");
if (abort & ABRT_TXDATA_NOACK)
dev_dbg(&adap->dev,
"No acknowledgement received from slave.\n");
if (abort & ABRT_10ADDR2_NOACK)
dev_dbg(&adap->dev,
"The 2nd address byte of the 10-bit address was not acknowledged.\n");
if (abort & ABRT_10ADDR1_NOACK)
dev_dbg(&adap->dev,
"The 1st address byte of 10-bit address was not acknowledged.\n");
if (abort & ABRT_7B_ADDR_NOACK)
dev_dbg(&adap->dev,
"I2C slave device not acknowledged.\n");
readl(i2c->base + IC_CLR_TX_ABRT);
i2c->status = STATUS_XFER_ABORT;
}
static int xfer_read(struct i2c_adapter *adap, unsigned char *buf, int length)
{
struct intel_mid_i2c_private *i2c = i2c_get_adapdata(adap);
int i = length;
int err;
if (length >= 256) {
dev_err(&adap->dev,
"I2C FIFO cannot support larger than 256 bytes\n");
return -EMSGSIZE;
}
INIT_COMPLETION(i2c->complete);
readl(i2c->base + IC_CLR_INTR);
writel(0x0044, i2c->base + IC_INTR_MASK);
i2c->status = STATUS_READ_START;
while (i--)
writel(IC_RD, i2c->base + IC_DATA_CMD);
i2c->status = STATUS_READ_START;
err = wait_for_completion_interruptible_timeout(&i2c->complete, HZ);
if (!err) {
dev_err(&adap->dev, "Timeout for ACK from I2C slave device\n");
intel_mid_i2c_hwinit(i2c);
return -ETIMEDOUT;
}
if (i2c->status == STATUS_READ_SUCCESS)
return 0;
else
return -EIO;
}
static int xfer_write(struct i2c_adapter *adap,
unsigned char *buf, int length)
{
struct intel_mid_i2c_private *i2c = i2c_get_adapdata(adap);
int i, err;
if (length >= 256) {
dev_err(&adap->dev,
"I2C FIFO cannot support larger than 256 bytes\n");
return -EMSGSIZE;
}
INIT_COMPLETION(i2c->complete);
readl(i2c->base + IC_CLR_INTR);
writel(0x0050, i2c->base + IC_INTR_MASK);
i2c->status = STATUS_WRITE_START;
for (i = 0; i < length; i++)
writel((u16)(*(buf + i)), i2c->base + IC_DATA_CMD);
i2c->status = STATUS_WRITE_START;
err = wait_for_completion_interruptible_timeout(&i2c->complete, HZ);
if (!err) {
dev_err(&adap->dev, "Timeout for ACK from I2C slave device\n");
intel_mid_i2c_hwinit(i2c);
return -ETIMEDOUT;
} else {
if (i2c->status == STATUS_WRITE_SUCCESS)
return 0;
else
return -EIO;
}
}
static int intel_mid_i2c_setup(struct i2c_adapter *adap, struct i2c_msg *pmsg)
{
struct intel_mid_i2c_private *i2c = i2c_get_adapdata(adap);
int err;
u32 reg;
u32 bit_mask;
u32 mode;
err = intel_mid_i2c_disable(adap);
if (err) {
dev_err(&adap->dev,
"Cannot disable i2c controller, timeout\n");
return err;
}
mode = (1 + i2c->speed) << 1;
reg = readl(i2c->base + IC_CON);
if ((reg & 0x06) != mode) {
dev_dbg(&adap->dev, "set mode %d\n", i2c->speed);
writel((reg & ~0x6) | mode, i2c->base + IC_CON);
}
reg = readl(i2c->base + IC_CON);
if (pmsg->flags & I2C_M_TEN) {
if ((reg & ADDR_10BIT) != ADDR_10BIT) {
dev_dbg(&adap->dev, "set i2c 10 bit address mode\n");
writel(reg | ADDR_10BIT, i2c->base + IC_CON);
}
} else {
if ((reg & ADDR_10BIT) != 0x0) {
dev_dbg(&adap->dev, "set i2c 7 bit address mode\n");
writel(reg & ~ADDR_10BIT, i2c->base + IC_CON);
}
}
reg = readl(i2c->base + IC_CON);
if ((reg & RESTART) != RESTART) {
dev_dbg(&adap->dev, "enable restart conditions\n");
writel(reg | RESTART, i2c->base + IC_CON);
}
reg = readl(i2c->base + IC_CON);
dev_dbg(&adap->dev, "ic_con reg is 0x%x\n", reg);
writel(reg | MASTER_EN, i2c->base + IC_CON);
if ((reg & SLV_DIS) != SLV_DIS) {
dev_dbg(&adap->dev, "enable master FSM\n");
writel(reg | SLV_DIS, i2c->base + IC_CON);
dev_dbg(&adap->dev, "ic_con reg is 0x%x\n", reg);
}
reg = readl(i2c->base + IC_TAR);
bit_mask = IC_TAR_SPECIAL | IC_TAR_GC_OR_START;
if ((reg & bit_mask) != 0x0) {
dev_dbg(&adap->dev,
"WR: use target address when intiating transfer, i2c_tx_target\n");
writel(reg & ~bit_mask, i2c->base + IC_TAR);
}
dev_dbg(&adap->dev,
"set target address to the I2C slave address, addr is %x\n",
pmsg->addr);
writel(pmsg->addr | (pmsg->flags & I2C_M_TEN ? IC_TAR_10BIT_ADDR : 0),
i2c->base + IC_TAR);
writel(ENABLE, i2c->base + IC_ENABLE);
return 0;
}
static int intel_mid_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg *pmsg,
int num)
{
struct intel_mid_i2c_private *i2c = i2c_get_adapdata(adap);
int i, err = 0;
if (num == 0)
return 0;
pm_runtime_get(i2c->dev);
mutex_lock(&i2c->lock);
dev_dbg(&adap->dev, "intel_mid_i2c_xfer, process %d msg(s)\n", num);
dev_dbg(&adap->dev, "slave address is %x\n", pmsg->addr);
if (i2c->status != STATUS_IDLE) {
dev_err(&adap->dev, "Adapter %d in transfer/standby\n",
adap->nr);
mutex_unlock(&i2c->lock);
pm_runtime_put(i2c->dev);
return -1;
}
for (i = 1; i < num; i++) {
if (unlikely(intel_mid_i2c_address_neq(&pmsg[0], &pmsg[i]))) {
dev_err(&adap->dev, "Invalid address in msg[%d]\n", i);
mutex_unlock(&i2c->lock);
pm_runtime_put(i2c->dev);
return -EINVAL;
}
}
if (intel_mid_i2c_setup(adap, pmsg)) {
mutex_unlock(&i2c->lock);
pm_runtime_put(i2c->dev);
return -EINVAL;
}
for (i = 0; i < num; i++) {
i2c->msg = pmsg;
i2c->status = STATUS_IDLE;
if (pmsg->flags & I2C_M_RD) {
dev_dbg(&adap->dev, "I2C_M_RD\n");
err = xfer_read(adap, pmsg->buf, pmsg->len);
} else {
dev_dbg(&adap->dev, "I2C_M_WR\n");
err = xfer_write(adap, pmsg->buf, pmsg->len);
}
if (err < 0)
break;
dev_dbg(&adap->dev, "msg[%d] transfer complete\n", i);
pmsg++;
}
writel(0x0000, i2c->base + IC_INTR_MASK);
readl(i2c->base + IC_CLR_INTR);
i2c->status = STATUS_IDLE;
mutex_unlock(&i2c->lock);
pm_runtime_put(i2c->dev);
return err;
}
static int intel_mid_i2c_runtime_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct intel_mid_i2c_private *i2c = pci_get_drvdata(pdev);
struct i2c_adapter *adap = to_i2c_adapter(dev);
int err;
if (i2c->status != STATUS_IDLE)
return -1;
intel_mid_i2c_disable(adap);
err = pci_save_state(pdev);
if (err) {
dev_err(dev, "pci_save_state failed\n");
return err;
}
err = pci_set_power_state(pdev, PCI_D3hot);
if (err) {
dev_err(dev, "pci_set_power_state failed\n");
return err;
}
i2c->status = STATUS_STANDBY;
return 0;
}
static int intel_mid_i2c_runtime_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct intel_mid_i2c_private *i2c = pci_get_drvdata(pdev);
int err;
if (i2c->status != STATUS_STANDBY)
return 0;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
err = pci_enable_device(pdev);
if (err) {
dev_err(dev, "pci_enable_device failed\n");
return err;
}
i2c->status = STATUS_IDLE;
intel_mid_i2c_hwinit(i2c);
return err;
}
static void i2c_isr_read(struct intel_mid_i2c_private *i2c)
{
struct i2c_msg *msg = i2c->msg;
int rx_num;
u32 len;
u8 *buf;
if (!(msg->flags & I2C_M_RD))
return;
if (i2c->status != STATUS_READ_IN_PROGRESS) {
len = msg->len;
buf = msg->buf;
} else {
len = i2c->rx_buf_len;
buf = i2c->rx_buf;
}
rx_num = readl(i2c->base + IC_RXFLR);
for (; len > 0 && rx_num > 0; len--, rx_num--)
*buf++ = readl(i2c->base + IC_DATA_CMD);
if (len > 0) {
i2c->status = STATUS_READ_IN_PROGRESS;
i2c->rx_buf_len = len;
i2c->rx_buf = buf;
} else
i2c->status = STATUS_READ_SUCCESS;
return;
}
static irqreturn_t intel_mid_i2c_isr(int this_irq, void *dev)
{
struct intel_mid_i2c_private *i2c = dev;
u32 stat = readl(i2c->base + IC_INTR_STAT);
if (!stat)
return IRQ_NONE;
dev_dbg(&i2c->adap.dev, "%s, stat = 0x%x\n", __func__, stat);
stat &= 0x54;
if (i2c->status != STATUS_WRITE_START &&
i2c->status != STATUS_READ_START &&
i2c->status != STATUS_READ_IN_PROGRESS)
goto err;
if (stat & TX_ABRT)
i2c->abort = readl(i2c->base + IC_TX_ABRT_SOURCE);
readl(i2c->base + IC_CLR_INTR);
if (stat & TX_ABRT) {
intel_mid_i2c_abort(i2c);
goto exit;
}
if (stat & RX_FULL) {
i2c_isr_read(i2c);
goto exit;
}
if (stat & TX_EMPTY) {
if (readl(i2c->base + IC_STATUS) & 0x4)
i2c->status = STATUS_WRITE_SUCCESS;
}
exit:
if (i2c->status == STATUS_READ_SUCCESS ||
i2c->status == STATUS_WRITE_SUCCESS ||
i2c->status == STATUS_XFER_ABORT) {
readl(i2c->base + IC_CLR_INTR);
writel(0, i2c->base + IC_INTR_MASK);
complete(&i2c->complete);
}
err:
return IRQ_HANDLED;
}
static int intel_mid_i2c_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct intel_mid_i2c_private *mrst;
unsigned long start, len;
int err, busnum;
void __iomem *base = NULL;
dev_dbg(&dev->dev, "Get into probe function for I2C\n");
err = pci_enable_device(dev);
if (err) {
dev_err(&dev->dev, "Failed to enable I2C PCI device (%d)\n",
err);
goto exit;
}
start = pci_resource_start(dev, 0);
len = pci_resource_len(dev, 0);
if (!start || len == 0) {
dev_err(&dev->dev, "base address not set\n");
err = -ENODEV;
goto exit;
}
dev_dbg(&dev->dev, "%s i2c resource start 0x%lx, len=%ld\n",
PLATFORM, start, len);
err = pci_request_region(dev, 0, DRIVER_NAME);
if (err) {
dev_err(&dev->dev, "failed to request I2C region "
"0x%lx-0x%lx\n", start,
(unsigned long)pci_resource_end(dev, 0));
goto exit;
}
base = ioremap_nocache(start, len);
if (!base) {
dev_err(&dev->dev, "I/O memory remapping failed\n");
err = -ENOMEM;
goto fail0;
}
mrst = kzalloc(sizeof(struct intel_mid_i2c_private), GFP_KERNEL);
if (mrst == NULL) {
dev_err(&dev->dev, "can't allocate interface\n");
err = -ENOMEM;
goto fail1;
}
snprintf(mrst->adap.name, sizeof(mrst->adap.name),
"Intel MID I2C at %lx", start);
mrst->adap.owner = THIS_MODULE;
mrst->adap.algo = &intel_mid_i2c_algorithm;
mrst->adap.dev.parent = &dev->dev;
mrst->dev = &dev->dev;
mrst->base = base;
mrst->speed = STANDARD;
mrst->abort = 0;
mrst->rx_buf_len = 0;
mrst->status = STATUS_IDLE;
pci_set_drvdata(dev, mrst);
i2c_set_adapdata(&mrst->adap, mrst);
mrst->adap.nr = busnum = id->driver_data;
if (dev->device <= 0x0804)
mrst->platform = MOORESTOWN;
else
mrst->platform = MEDFIELD;
dev_dbg(&dev->dev, "I2C%d\n", busnum);
if (ctl_num > busnum) {
if (speed_mode[busnum] < 0 || speed_mode[busnum] >= NUM_SPEEDS)
dev_warn(&dev->dev, "invalid speed %d ignored.\n",
speed_mode[busnum]);
else
mrst->speed = speed_mode[busnum];
}
err = intel_mid_i2c_hwinit(mrst);
if (err < 0) {
dev_err(&dev->dev, "I2C interface initialization failed\n");
goto fail2;
}
mutex_init(&mrst->lock);
init_completion(&mrst->complete);
readl(mrst->base + IC_CLR_INTR);
writel(0x0000, mrst->base + IC_INTR_MASK);
err = request_irq(dev->irq, intel_mid_i2c_isr, IRQF_SHARED,
mrst->adap.name, mrst);
if (err) {
dev_err(&dev->dev, "Failed to request IRQ for I2C controller: "
"%s", mrst->adap.name);
goto fail2;
}
err = i2c_add_numbered_adapter(&mrst->adap);
if (err) {
dev_err(&dev->dev, "Adapter %s registration failed\n",
mrst->adap.name);
goto fail3;
}
dev_dbg(&dev->dev, "%s I2C bus %d driver bind success.\n",
(mrst->platform == MOORESTOWN) ? "Moorestown" : "Medfield",
busnum);
pm_runtime_enable(&dev->dev);
return 0;
fail3:
free_irq(dev->irq, mrst);
fail2:
kfree(mrst);
fail1:
iounmap(base);
fail0:
pci_release_region(dev, 0);
exit:
return err;
}
static void intel_mid_i2c_remove(struct pci_dev *dev)
{
struct intel_mid_i2c_private *mrst = pci_get_drvdata(dev);
intel_mid_i2c_disable(&mrst->adap);
i2c_del_adapter(&mrst->adap);
free_irq(dev->irq, mrst);
iounmap(mrst->base);
kfree(mrst);
pci_release_region(dev, 0);
}
