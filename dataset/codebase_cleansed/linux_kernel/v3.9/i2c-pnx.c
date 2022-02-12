static inline int wait_timeout(struct i2c_pnx_algo_data *data)
{
long timeout = data->timeout;
while (timeout > 0 &&
(ioread32(I2C_REG_STS(data)) & mstatus_active)) {
mdelay(1);
timeout--;
}
return (timeout <= 0);
}
static inline int wait_reset(struct i2c_pnx_algo_data *data)
{
long timeout = data->timeout;
while (timeout > 0 &&
(ioread32(I2C_REG_CTL(data)) & mcntrl_reset)) {
mdelay(1);
timeout--;
}
return (timeout <= 0);
}
static inline void i2c_pnx_arm_timer(struct i2c_pnx_algo_data *alg_data)
{
struct timer_list *timer = &alg_data->mif.timer;
unsigned long expires = msecs_to_jiffies(alg_data->timeout);
if (expires <= 1)
expires = 2;
del_timer_sync(timer);
dev_dbg(&alg_data->adapter.dev, "Timer armed at %lu plus %lu jiffies.\n",
jiffies, expires);
timer->expires = jiffies + expires;
timer->data = (unsigned long)alg_data;
add_timer(timer);
}
static int i2c_pnx_start(unsigned char slave_addr,
struct i2c_pnx_algo_data *alg_data)
{
dev_dbg(&alg_data->adapter.dev, "%s(): addr 0x%x mode %d\n", __func__,
slave_addr, alg_data->mif.mode);
if (slave_addr & ~0x7f) {
dev_err(&alg_data->adapter.dev,
"%s: Invalid slave address %x. Only 7-bit addresses are supported\n",
alg_data->adapter.name, slave_addr);
return -EINVAL;
}
if (wait_timeout(alg_data)) {
dev_err(&alg_data->adapter.dev,
"%s: Bus busy. Slave addr = %02x, cntrl = %x, stat = %x\n",
alg_data->adapter.name, slave_addr,
ioread32(I2C_REG_CTL(alg_data)),
ioread32(I2C_REG_STS(alg_data)));
return -EBUSY;
} else if (ioread32(I2C_REG_STS(alg_data)) & mstatus_afi) {
dev_err(&alg_data->adapter.dev,
"%s: Arbitration failure. Slave addr = %02x\n",
alg_data->adapter.name, slave_addr);
return -EIO;
}
iowrite32(ioread32(I2C_REG_STS(alg_data)) | mstatus_tdi | mstatus_afi,
I2C_REG_STS(alg_data));
dev_dbg(&alg_data->adapter.dev, "%s(): sending %#x\n", __func__,
(slave_addr << 1) | start_bit | alg_data->mif.mode);
iowrite32((slave_addr << 1) | start_bit | alg_data->mif.mode,
I2C_REG_TX(alg_data));
dev_dbg(&alg_data->adapter.dev, "%s(): exit\n", __func__);
return 0;
}
static void i2c_pnx_stop(struct i2c_pnx_algo_data *alg_data)
{
long timeout = 1000;
dev_dbg(&alg_data->adapter.dev, "%s(): entering: stat = %04x.\n",
__func__, ioread32(I2C_REG_STS(alg_data)));
iowrite32(0xff | stop_bit, I2C_REG_TX(alg_data));
while (timeout > 0 &&
(ioread32(I2C_REG_STS(alg_data)) & mstatus_active)) {
udelay(1);
timeout--;
}
dev_dbg(&alg_data->adapter.dev, "%s(): exiting: stat = %04x.\n",
__func__, ioread32(I2C_REG_STS(alg_data)));
}
static int i2c_pnx_master_xmit(struct i2c_pnx_algo_data *alg_data)
{
u32 val;
dev_dbg(&alg_data->adapter.dev, "%s(): entering: stat = %04x.\n",
__func__, ioread32(I2C_REG_STS(alg_data)));
if (alg_data->mif.len > 0) {
val = *alg_data->mif.buf++;
if (alg_data->mif.len == 1)
val |= stop_bit;
alg_data->mif.len--;
iowrite32(val, I2C_REG_TX(alg_data));
dev_dbg(&alg_data->adapter.dev, "%s(): xmit %#x [%d]\n",
__func__, val, alg_data->mif.len + 1);
if (alg_data->mif.len == 0) {
if (alg_data->last) {
if (wait_timeout(alg_data))
dev_err(&alg_data->adapter.dev,
"The bus is still active after timeout\n");
}
iowrite32(ioread32(I2C_REG_CTL(alg_data)) &
~(mcntrl_afie | mcntrl_naie | mcntrl_drmie),
I2C_REG_CTL(alg_data));
del_timer_sync(&alg_data->mif.timer);
dev_dbg(&alg_data->adapter.dev,
"%s(): Waking up xfer routine.\n",
__func__);
complete(&alg_data->mif.complete);
}
} else if (alg_data->mif.len == 0) {
i2c_pnx_stop(alg_data);
iowrite32(ioread32(I2C_REG_CTL(alg_data)) &
~(mcntrl_afie | mcntrl_naie | mcntrl_drmie),
I2C_REG_CTL(alg_data));
del_timer_sync(&alg_data->mif.timer);
dev_dbg(&alg_data->adapter.dev,
"%s(): Waking up xfer routine after zero-xfer.\n",
__func__);
complete(&alg_data->mif.complete);
}
dev_dbg(&alg_data->adapter.dev, "%s(): exiting: stat = %04x.\n",
__func__, ioread32(I2C_REG_STS(alg_data)));
return 0;
}
static int i2c_pnx_master_rcv(struct i2c_pnx_algo_data *alg_data)
{
unsigned int val = 0;
u32 ctl = 0;
dev_dbg(&alg_data->adapter.dev, "%s(): entering: stat = %04x.\n",
__func__, ioread32(I2C_REG_STS(alg_data)));
if (ioread32(I2C_REG_STS(alg_data)) & mstatus_rfe) {
if (alg_data->mif.order) {
dev_dbg(&alg_data->adapter.dev,
"%s(): Write dummy data to fill Rx-fifo...\n",
__func__);
if (alg_data->mif.order == 1) {
val |= stop_bit;
ctl = ioread32(I2C_REG_CTL(alg_data));
ctl |= mcntrl_rffie | mcntrl_daie;
ctl &= ~mcntrl_drmie;
iowrite32(ctl, I2C_REG_CTL(alg_data));
}
iowrite32(val, I2C_REG_TX(alg_data));
alg_data->mif.order--;
}
return 0;
}
if (alg_data->mif.len > 0) {
val = ioread32(I2C_REG_RX(alg_data));
*alg_data->mif.buf++ = (u8) (val & 0xff);
dev_dbg(&alg_data->adapter.dev, "%s(): rcv 0x%x [%d]\n",
__func__, val, alg_data->mif.len);
alg_data->mif.len--;
if (alg_data->mif.len == 0) {
if (alg_data->last)
if (wait_timeout(alg_data))
dev_err(&alg_data->adapter.dev,
"The bus is still active after timeout\n");
ctl = ioread32(I2C_REG_CTL(alg_data));
ctl &= ~(mcntrl_afie | mcntrl_naie | mcntrl_rffie |
mcntrl_drmie | mcntrl_daie);
iowrite32(ctl, I2C_REG_CTL(alg_data));
del_timer_sync(&alg_data->mif.timer);
complete(&alg_data->mif.complete);
}
}
dev_dbg(&alg_data->adapter.dev, "%s(): exiting: stat = %04x.\n",
__func__, ioread32(I2C_REG_STS(alg_data)));
return 0;
}
static irqreturn_t i2c_pnx_interrupt(int irq, void *dev_id)
{
struct i2c_pnx_algo_data *alg_data = dev_id;
u32 stat, ctl;
dev_dbg(&alg_data->adapter.dev,
"%s(): mstat = %x mctrl = %x, mode = %d\n",
__func__,
ioread32(I2C_REG_STS(alg_data)),
ioread32(I2C_REG_CTL(alg_data)),
alg_data->mif.mode);
stat = ioread32(I2C_REG_STS(alg_data));
if (stat & mstatus_afi) {
alg_data->mif.ret = -EIO;
ctl = ioread32(I2C_REG_CTL(alg_data));
ctl &= ~(mcntrl_afie | mcntrl_naie | mcntrl_rffie |
mcntrl_drmie);
iowrite32(ctl, I2C_REG_CTL(alg_data));
del_timer_sync(&alg_data->mif.timer);
complete(&alg_data->mif.complete);
} else if (stat & mstatus_nai) {
dev_dbg(&alg_data->adapter.dev,
"%s(): Slave did not acknowledge, generating a STOP.\n",
__func__);
i2c_pnx_stop(alg_data);
ctl = ioread32(I2C_REG_CTL(alg_data));
ctl &= ~(mcntrl_afie | mcntrl_naie | mcntrl_rffie |
mcntrl_drmie);
iowrite32(ctl, I2C_REG_CTL(alg_data));
alg_data->mif.ret = -EIO;
del_timer_sync(&alg_data->mif.timer);
complete(&alg_data->mif.complete);
} else {
if ((stat & mstatus_drmi) || !(stat & mstatus_rfe)) {
if (alg_data->mif.mode == I2C_SMBUS_WRITE) {
i2c_pnx_master_xmit(alg_data);
} else if (alg_data->mif.mode == I2C_SMBUS_READ) {
i2c_pnx_master_rcv(alg_data);
}
}
}
stat = ioread32(I2C_REG_STS(alg_data));
iowrite32(stat | mstatus_tdi | mstatus_afi, I2C_REG_STS(alg_data));
dev_dbg(&alg_data->adapter.dev,
"%s(): exiting, stat = %x ctrl = %x.\n",
__func__, ioread32(I2C_REG_STS(alg_data)),
ioread32(I2C_REG_CTL(alg_data)));
return IRQ_HANDLED;
}
static void i2c_pnx_timeout(unsigned long data)
{
struct i2c_pnx_algo_data *alg_data = (struct i2c_pnx_algo_data *)data;
u32 ctl;
dev_err(&alg_data->adapter.dev,
"Master timed out. stat = %04x, cntrl = %04x. Resetting master...\n",
ioread32(I2C_REG_STS(alg_data)),
ioread32(I2C_REG_CTL(alg_data)));
ctl = ioread32(I2C_REG_CTL(alg_data));
ctl &= ~(mcntrl_afie | mcntrl_naie | mcntrl_rffie | mcntrl_drmie);
iowrite32(ctl, I2C_REG_CTL(alg_data));
ctl |= mcntrl_reset;
iowrite32(ctl, I2C_REG_CTL(alg_data));
wait_reset(alg_data);
alg_data->mif.ret = -EIO;
complete(&alg_data->mif.complete);
}
static inline void bus_reset_if_active(struct i2c_pnx_algo_data *alg_data)
{
u32 stat;
if ((stat = ioread32(I2C_REG_STS(alg_data))) & mstatus_active) {
dev_err(&alg_data->adapter.dev,
"%s: Bus is still active after xfer. Reset it...\n",
alg_data->adapter.name);
iowrite32(ioread32(I2C_REG_CTL(alg_data)) | mcntrl_reset,
I2C_REG_CTL(alg_data));
wait_reset(alg_data);
} else if (!(stat & mstatus_rfe) || !(stat & mstatus_tfe)) {
iowrite32(ioread32(I2C_REG_CTL(alg_data)) | mcntrl_reset,
I2C_REG_CTL(alg_data));
wait_reset(alg_data);
} else if (stat & mstatus_nai) {
iowrite32(ioread32(I2C_REG_CTL(alg_data)) | mcntrl_reset,
I2C_REG_CTL(alg_data));
wait_reset(alg_data);
}
}
static int
i2c_pnx_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
struct i2c_msg *pmsg;
int rc = 0, completed = 0, i;
struct i2c_pnx_algo_data *alg_data = adap->algo_data;
u32 stat = ioread32(I2C_REG_STS(alg_data));
dev_dbg(&alg_data->adapter.dev,
"%s(): entering: %d messages, stat = %04x.\n",
__func__, num, ioread32(I2C_REG_STS(alg_data)));
bus_reset_if_active(alg_data);
for (i = 0; rc >= 0 && i < num; i++) {
u8 addr;
pmsg = &msgs[i];
addr = pmsg->addr;
if (pmsg->flags & I2C_M_TEN) {
dev_err(&alg_data->adapter.dev,
"%s: 10 bits addr not supported!\n",
alg_data->adapter.name);
rc = -EINVAL;
break;
}
alg_data->mif.buf = pmsg->buf;
alg_data->mif.len = pmsg->len;
alg_data->mif.order = pmsg->len;
alg_data->mif.mode = (pmsg->flags & I2C_M_RD) ?
I2C_SMBUS_READ : I2C_SMBUS_WRITE;
alg_data->mif.ret = 0;
alg_data->last = (i == num - 1);
dev_dbg(&alg_data->adapter.dev, "%s(): mode %d, %d bytes\n",
__func__, alg_data->mif.mode, alg_data->mif.len);
i2c_pnx_arm_timer(alg_data);
init_completion(&alg_data->mif.complete);
iowrite32(ioread32(I2C_REG_CTL(alg_data)) | mcntrl_afie |
mcntrl_naie | mcntrl_drmie,
I2C_REG_CTL(alg_data));
rc = i2c_pnx_start(addr, alg_data);
if (rc < 0)
break;
wait_for_completion(&alg_data->mif.complete);
if (!(rc = alg_data->mif.ret))
completed++;
dev_dbg(&alg_data->adapter.dev,
"%s(): Complete, return code = %d.\n",
__func__, rc);
if ((stat = ioread32(I2C_REG_STS(alg_data))) & mstatus_tdi) {
dev_dbg(&alg_data->adapter.dev,
"%s: TDI still set... clearing now.\n",
alg_data->adapter.name);
iowrite32(stat, I2C_REG_STS(alg_data));
}
if ((stat = ioread32(I2C_REG_STS(alg_data))) & mstatus_afi) {
dev_dbg(&alg_data->adapter.dev,
"%s: AFI still set... clearing now.\n",
alg_data->adapter.name);
iowrite32(stat, I2C_REG_STS(alg_data));
}
}
bus_reset_if_active(alg_data);
alg_data->mif.buf = NULL;
alg_data->mif.len = 0;
alg_data->mif.order = 0;
dev_dbg(&alg_data->adapter.dev, "%s(): exiting, stat = %x\n",
__func__, ioread32(I2C_REG_STS(alg_data)));
if (completed != num)
return ((rc < 0) ? rc : -EREMOTEIO);
return num;
}
static u32 i2c_pnx_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int i2c_pnx_controller_suspend(struct device *dev)
{
struct i2c_pnx_algo_data *alg_data = dev_get_drvdata(dev);
clk_disable(alg_data->clk);
return 0;
}
static int i2c_pnx_controller_resume(struct device *dev)
{
struct i2c_pnx_algo_data *alg_data = dev_get_drvdata(dev);
return clk_enable(alg_data->clk);
}
static int i2c_pnx_probe(struct platform_device *pdev)
{
unsigned long tmp;
int ret = 0;
struct i2c_pnx_algo_data *alg_data;
unsigned long freq;
struct resource *res;
u32 speed = I2C_PNX_SPEED_KHZ_DEFAULT * 1000;
alg_data = kzalloc(sizeof(*alg_data), GFP_KERNEL);
if (!alg_data) {
ret = -ENOMEM;
goto err_kzalloc;
}
platform_set_drvdata(pdev, alg_data);
alg_data->adapter.dev.parent = &pdev->dev;
alg_data->adapter.algo = &pnx_algorithm;
alg_data->adapter.algo_data = alg_data;
alg_data->adapter.nr = pdev->id;
alg_data->timeout = I2C_PNX_TIMEOUT_DEFAULT;
#ifdef CONFIG_OF
alg_data->adapter.dev.of_node = of_node_get(pdev->dev.of_node);
if (pdev->dev.of_node) {
of_property_read_u32(pdev->dev.of_node, "clock-frequency",
&speed);
}
#endif
alg_data->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(alg_data->clk)) {
ret = PTR_ERR(alg_data->clk);
goto out_drvdata;
}
init_timer(&alg_data->mif.timer);
alg_data->mif.timer.function = i2c_pnx_timeout;
alg_data->mif.timer.data = (unsigned long)alg_data;
snprintf(alg_data->adapter.name, sizeof(alg_data->adapter.name),
"%s", pdev->name);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Unable to get mem resource.\n");
ret = -EBUSY;
goto out_clkget;
}
if (!request_mem_region(res->start, I2C_PNX_REGION_SIZE,
pdev->name)) {
dev_err(&pdev->dev,
"I/O region 0x%08x for I2C already in use.\n",
res->start);
ret = -ENOMEM;
goto out_clkget;
}
alg_data->base = res->start;
alg_data->ioaddr = ioremap(res->start, I2C_PNX_REGION_SIZE);
if (!alg_data->ioaddr) {
dev_err(&pdev->dev, "Couldn't ioremap I2C I/O region\n");
ret = -ENOMEM;
goto out_release;
}
ret = clk_enable(alg_data->clk);
if (ret)
goto out_unmap;
freq = clk_get_rate(alg_data->clk);
tmp = (freq / speed) / 2 - 2;
if (tmp > 0x3FF)
tmp = 0x3FF;
iowrite32(tmp, I2C_REG_CKH(alg_data));
iowrite32(tmp, I2C_REG_CKL(alg_data));
iowrite32(mcntrl_reset, I2C_REG_CTL(alg_data));
if (wait_reset(alg_data)) {
ret = -ENODEV;
goto out_clock;
}
init_completion(&alg_data->mif.complete);
alg_data->irq = platform_get_irq(pdev, 0);
if (alg_data->irq < 0) {
dev_err(&pdev->dev, "Failed to get IRQ from platform resource\n");
goto out_irq;
}
ret = request_irq(alg_data->irq, i2c_pnx_interrupt,
0, pdev->name, alg_data);
if (ret)
goto out_clock;
ret = i2c_add_numbered_adapter(&alg_data->adapter);
if (ret < 0) {
dev_err(&pdev->dev, "I2C: Failed to add bus\n");
goto out_irq;
}
of_i2c_register_devices(&alg_data->adapter);
dev_dbg(&pdev->dev, "%s: Master at %#8x, irq %d.\n",
alg_data->adapter.name, res->start, alg_data->irq);
return 0;
out_irq:
free_irq(alg_data->irq, alg_data);
out_clock:
clk_disable(alg_data->clk);
out_unmap:
iounmap(alg_data->ioaddr);
out_release:
release_mem_region(res->start, I2C_PNX_REGION_SIZE);
out_clkget:
clk_put(alg_data->clk);
out_drvdata:
kfree(alg_data);
err_kzalloc:
return ret;
}
static int i2c_pnx_remove(struct platform_device *pdev)
{
struct i2c_pnx_algo_data *alg_data = platform_get_drvdata(pdev);
free_irq(alg_data->irq, alg_data);
i2c_del_adapter(&alg_data->adapter);
clk_disable(alg_data->clk);
iounmap(alg_data->ioaddr);
release_mem_region(alg_data->base, I2C_PNX_REGION_SIZE);
clk_put(alg_data->clk);
kfree(alg_data);
return 0;
}
static int __init i2c_adap_pnx_init(void)
{
return platform_driver_register(&i2c_pnx_driver);
}
static void __exit i2c_adap_pnx_exit(void)
{
platform_driver_unregister(&i2c_pnx_driver);
}
