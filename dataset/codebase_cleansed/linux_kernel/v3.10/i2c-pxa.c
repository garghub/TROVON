static inline void
decode_bits(const char *prefix, const struct bits *bits, int num, u32 val)
{
printk("%s %08x: ", prefix, val);
while (num--) {
const char *str = val & bits->mask ? bits->set : bits->unset;
if (str)
printk("%s ", str);
bits++;
}
}
static void decode_ISR(unsigned int val)
{
decode_bits(KERN_DEBUG "ISR", isr_bits, ARRAY_SIZE(isr_bits), val);
printk("\n");
}
static void decode_ICR(unsigned int val)
{
decode_bits(KERN_DEBUG "ICR", icr_bits, ARRAY_SIZE(icr_bits), val);
printk("\n");
}
static void i2c_pxa_show_state(struct pxa_i2c *i2c, int lno, const char *fname)
{
dev_dbg(&i2c->adap.dev, "state:%s:%d: ISR=%08x, ICR=%08x, IBMR=%02x\n", fname, lno,
readl(_ISR(i2c)), readl(_ICR(i2c)), readl(_IBMR(i2c)));
}
static void i2c_pxa_scream_blue_murder(struct pxa_i2c *i2c, const char *why)
{
unsigned int i;
printk(KERN_ERR "i2c: error: %s\n", why);
printk(KERN_ERR "i2c: msg_num: %d msg_idx: %d msg_ptr: %d\n",
i2c->msg_num, i2c->msg_idx, i2c->msg_ptr);
printk(KERN_ERR "i2c: ICR: %08x ISR: %08x\n",
readl(_ICR(i2c)), readl(_ISR(i2c)));
printk(KERN_DEBUG "i2c: log: ");
for (i = 0; i < i2c->irqlogidx; i++)
printk("[%08x:%08x] ", i2c->isrlog[i], i2c->icrlog[i]);
printk("\n");
}
static inline int i2c_pxa_is_slavemode(struct pxa_i2c *i2c)
{
return !(readl(_ICR(i2c)) & ICR_SCLE);
}
static void i2c_pxa_abort(struct pxa_i2c *i2c)
{
int i = 250;
if (i2c_pxa_is_slavemode(i2c)) {
dev_dbg(&i2c->adap.dev, "%s: called in slave mode\n", __func__);
return;
}
while ((i > 0) && (readl(_IBMR(i2c)) & 0x1) == 0) {
unsigned long icr = readl(_ICR(i2c));
icr &= ~ICR_START;
icr |= ICR_ACKNAK | ICR_STOP | ICR_TB;
writel(icr, _ICR(i2c));
show_state(i2c);
mdelay(1);
i --;
}
writel(readl(_ICR(i2c)) & ~(ICR_MA | ICR_START | ICR_STOP),
_ICR(i2c));
}
static int i2c_pxa_wait_bus_not_busy(struct pxa_i2c *i2c)
{
int timeout = DEF_TIMEOUT;
while (timeout-- && readl(_ISR(i2c)) & (ISR_IBB | ISR_UB)) {
if ((readl(_ISR(i2c)) & ISR_SAD) != 0)
timeout += 4;
msleep(2);
show_state(i2c);
}
if (timeout < 0)
show_state(i2c);
return timeout < 0 ? I2C_RETRY : 0;
}
static int i2c_pxa_wait_master(struct pxa_i2c *i2c)
{
unsigned long timeout = jiffies + HZ*4;
while (time_before(jiffies, timeout)) {
if (i2c_debug > 1)
dev_dbg(&i2c->adap.dev, "%s: %ld: ISR=%08x, ICR=%08x, IBMR=%02x\n",
__func__, (long)jiffies, readl(_ISR(i2c)), readl(_ICR(i2c)), readl(_IBMR(i2c)));
if (readl(_ISR(i2c)) & ISR_SAD) {
if (i2c_debug > 0)
dev_dbg(&i2c->adap.dev, "%s: Slave detected\n", __func__);
goto out;
}
if ((readl(_ISR(i2c)) & (ISR_UB | ISR_IBB)) == 0 && readl(_IBMR(i2c)) == 3) {
if (i2c_debug > 0)
dev_dbg(&i2c->adap.dev, "%s: done\n", __func__);
return 1;
}
msleep(1);
}
if (i2c_debug > 0)
dev_dbg(&i2c->adap.dev, "%s: did not free\n", __func__);
out:
return 0;
}
static int i2c_pxa_set_master(struct pxa_i2c *i2c)
{
if (i2c_debug)
dev_dbg(&i2c->adap.dev, "setting to bus master\n");
if ((readl(_ISR(i2c)) & (ISR_UB | ISR_IBB)) != 0) {
dev_dbg(&i2c->adap.dev, "%s: unit is busy\n", __func__);
if (!i2c_pxa_wait_master(i2c)) {
dev_dbg(&i2c->adap.dev, "%s: error: unit busy\n", __func__);
return I2C_RETRY;
}
}
writel(readl(_ICR(i2c)) | ICR_SCLE, _ICR(i2c));
return 0;
}
static int i2c_pxa_wait_slave(struct pxa_i2c *i2c)
{
unsigned long timeout = jiffies + HZ*1;
show_state(i2c);
while (time_before(jiffies, timeout)) {
if (i2c_debug > 1)
dev_dbg(&i2c->adap.dev, "%s: %ld: ISR=%08x, ICR=%08x, IBMR=%02x\n",
__func__, (long)jiffies, readl(_ISR(i2c)), readl(_ICR(i2c)), readl(_IBMR(i2c)));
if ((readl(_ISR(i2c)) & (ISR_UB|ISR_IBB)) == 0 ||
(readl(_ISR(i2c)) & ISR_SAD) != 0 ||
(readl(_ICR(i2c)) & ICR_SCLE) == 0) {
if (i2c_debug > 1)
dev_dbg(&i2c->adap.dev, "%s: done\n", __func__);
return 1;
}
msleep(1);
}
if (i2c_debug > 0)
dev_dbg(&i2c->adap.dev, "%s: did not free\n", __func__);
return 0;
}
static void i2c_pxa_set_slave(struct pxa_i2c *i2c, int errcode)
{
show_state(i2c);
if (errcode < 0) {
udelay(100);
} else {
if (readl(_ICR(i2c)) & ICR_STOP) {
udelay(100);
writel(readl(_ICR(i2c)) & ~ICR_STOP, _ICR(i2c));
}
if (!i2c_pxa_wait_slave(i2c)) {
dev_err(&i2c->adap.dev, "%s: wait timedout\n",
__func__);
return;
}
}
writel(readl(_ICR(i2c)) & ~(ICR_STOP|ICR_ACKNAK|ICR_MA), _ICR(i2c));
writel(readl(_ICR(i2c)) & ~ICR_SCLE, _ICR(i2c));
if (i2c_debug) {
dev_dbg(&i2c->adap.dev, "ICR now %08x, ISR %08x\n", readl(_ICR(i2c)), readl(_ISR(i2c)));
decode_ICR(readl(_ICR(i2c)));
}
}
static void i2c_pxa_reset(struct pxa_i2c *i2c)
{
pr_debug("Resetting I2C Controller Unit\n");
i2c_pxa_abort(i2c);
writel(ICR_UR, _ICR(i2c));
writel(I2C_ISR_INIT, _ISR(i2c));
writel(readl(_ICR(i2c)) & ~ICR_UR, _ICR(i2c));
if (i2c->reg_isar)
writel(i2c->slave_addr, _ISAR(i2c));
writel(I2C_ICR_INIT | (i2c->fast_mode ? ICR_FM : 0), _ICR(i2c));
#ifdef CONFIG_I2C_PXA_SLAVE
dev_info(&i2c->adap.dev, "Enabling slave mode\n");
writel(readl(_ICR(i2c)) | ICR_SADIE | ICR_ALDIE | ICR_SSDIE, _ICR(i2c));
#endif
i2c_pxa_set_slave(i2c, 0);
writel(readl(_ICR(i2c)) | ICR_IUE, _ICR(i2c));
udelay(100);
}
static void i2c_pxa_slave_txempty(struct pxa_i2c *i2c, u32 isr)
{
if (isr & ISR_BED) {
} else {
int ret = 0;
if (i2c->slave != NULL)
ret = i2c->slave->read(i2c->slave->data);
writel(ret, _IDBR(i2c));
writel(readl(_ICR(i2c)) | ICR_TB, _ICR(i2c));
}
}
static void i2c_pxa_slave_rxfull(struct pxa_i2c *i2c, u32 isr)
{
unsigned int byte = readl(_IDBR(i2c));
if (i2c->slave != NULL)
i2c->slave->write(i2c->slave->data, byte);
writel(readl(_ICR(i2c)) | ICR_TB, _ICR(i2c));
}
static void i2c_pxa_slave_start(struct pxa_i2c *i2c, u32 isr)
{
int timeout;
if (i2c_debug > 0)
dev_dbg(&i2c->adap.dev, "SAD, mode is slave-%cx\n",
(isr & ISR_RWM) ? 'r' : 't');
if (i2c->slave != NULL)
i2c->slave->event(i2c->slave->data,
(isr & ISR_RWM) ? I2C_SLAVE_EVENT_START_READ : I2C_SLAVE_EVENT_START_WRITE);
writel(readl(_ICR(i2c)) & ~(ICR_START|ICR_STOP), _ICR(i2c));
writel(readl(_ICR(i2c)) | ICR_TB, _ICR(i2c));
timeout = 0x10000;
while (1) {
if ((readl(_IBMR(i2c)) & 2) == 2)
break;
timeout--;
if (timeout <= 0) {
dev_err(&i2c->adap.dev, "timeout waiting for SCL high\n");
break;
}
}
writel(readl(_ICR(i2c)) & ~ICR_SCLE, _ICR(i2c));
}
static void i2c_pxa_slave_stop(struct pxa_i2c *i2c)
{
if (i2c_debug > 2)
dev_dbg(&i2c->adap.dev, "ISR: SSD (Slave Stop)\n");
if (i2c->slave != NULL)
i2c->slave->event(i2c->slave->data, I2C_SLAVE_EVENT_STOP);
if (i2c_debug > 2)
dev_dbg(&i2c->adap.dev, "ISR: SSD (Slave Stop) acked\n");
if (i2c->msg)
i2c_pxa_master_complete(i2c, I2C_RETRY);
}
static void i2c_pxa_slave_txempty(struct pxa_i2c *i2c, u32 isr)
{
if (isr & ISR_BED) {
} else {
writel(0, _IDBR(i2c));
writel(readl(_ICR(i2c)) | ICR_TB, _ICR(i2c));
}
}
static void i2c_pxa_slave_rxfull(struct pxa_i2c *i2c, u32 isr)
{
writel(readl(_ICR(i2c)) | ICR_TB | ICR_ACKNAK, _ICR(i2c));
}
static void i2c_pxa_slave_start(struct pxa_i2c *i2c, u32 isr)
{
int timeout;
writel(readl(_ICR(i2c)) & ~(ICR_START|ICR_STOP), _ICR(i2c));
writel(readl(_ICR(i2c)) | ICR_TB | ICR_ACKNAK, _ICR(i2c));
timeout = 0x10000;
while (1) {
if ((readl(_IBMR(i2c)) & 2) == 2)
break;
timeout--;
if (timeout <= 0) {
dev_err(&i2c->adap.dev, "timeout waiting for SCL high\n");
break;
}
}
writel(readl(_ICR(i2c)) & ~ICR_SCLE, _ICR(i2c));
}
static void i2c_pxa_slave_stop(struct pxa_i2c *i2c)
{
if (i2c->msg)
i2c_pxa_master_complete(i2c, I2C_RETRY);
}
static inline unsigned int i2c_pxa_addr_byte(struct i2c_msg *msg)
{
unsigned int addr = (msg->addr & 0x7f) << 1;
if (msg->flags & I2C_M_RD)
addr |= 1;
return addr;
}
static inline void i2c_pxa_start_message(struct pxa_i2c *i2c)
{
u32 icr;
writel(i2c_pxa_addr_byte(i2c->msg), _IDBR(i2c));
icr = readl(_ICR(i2c)) & ~(ICR_STOP | ICR_ALDIE);
writel(icr | ICR_START | ICR_TB, _ICR(i2c));
}
static inline void i2c_pxa_stop_message(struct pxa_i2c *i2c)
{
u32 icr;
icr = readl(_ICR(i2c));
icr &= ~(ICR_STOP | ICR_ACKNAK);
writel(icr, _ICR(i2c));
}
static int i2c_pxa_pio_set_master(struct pxa_i2c *i2c)
{
long timeout = 2 * DEF_TIMEOUT;
while (timeout-- && readl(_ISR(i2c)) & (ISR_IBB | ISR_UB)) {
udelay(1000);
show_state(i2c);
}
if (timeout < 0) {
show_state(i2c);
dev_err(&i2c->adap.dev,
"i2c_pxa: timeout waiting for bus free\n");
return I2C_RETRY;
}
writel(readl(_ICR(i2c)) | ICR_SCLE, _ICR(i2c));
return 0;
}
static int i2c_pxa_do_pio_xfer(struct pxa_i2c *i2c,
struct i2c_msg *msg, int num)
{
unsigned long timeout = 500000;
int ret = 0;
ret = i2c_pxa_pio_set_master(i2c);
if (ret)
goto out;
i2c->msg = msg;
i2c->msg_num = num;
i2c->msg_idx = 0;
i2c->msg_ptr = 0;
i2c->irqlogidx = 0;
i2c_pxa_start_message(i2c);
while (i2c->msg_num > 0 && --timeout) {
i2c_pxa_handler(0, i2c);
udelay(10);
}
i2c_pxa_stop_message(i2c);
ret = i2c->msg_idx;
out:
if (timeout == 0)
i2c_pxa_scream_blue_murder(i2c, "timeout");
return ret;
}
static int i2c_pxa_do_xfer(struct pxa_i2c *i2c, struct i2c_msg *msg, int num)
{
long timeout;
int ret;
ret = i2c_pxa_wait_bus_not_busy(i2c);
if (ret) {
dev_err(&i2c->adap.dev, "i2c_pxa: timeout waiting for bus free\n");
goto out;
}
ret = i2c_pxa_set_master(i2c);
if (ret) {
dev_err(&i2c->adap.dev, "i2c_pxa_set_master: error %d\n", ret);
goto out;
}
spin_lock_irq(&i2c->lock);
i2c->msg = msg;
i2c->msg_num = num;
i2c->msg_idx = 0;
i2c->msg_ptr = 0;
i2c->irqlogidx = 0;
i2c_pxa_start_message(i2c);
spin_unlock_irq(&i2c->lock);
timeout = wait_event_timeout(i2c->wait, i2c->msg_num == 0, HZ * 5);
i2c_pxa_stop_message(i2c);
ret = i2c->msg_idx;
if (!timeout && i2c->msg_num) {
i2c_pxa_scream_blue_murder(i2c, "timeout");
ret = I2C_RETRY;
}
out:
return ret;
}
static int i2c_pxa_pio_xfer(struct i2c_adapter *adap,
struct i2c_msg msgs[], int num)
{
struct pxa_i2c *i2c = adap->algo_data;
int ret, i;
if (!(readl(_ICR(i2c)) & ICR_IUE))
i2c_pxa_reset(i2c);
for (i = adap->retries; i >= 0; i--) {
ret = i2c_pxa_do_pio_xfer(i2c, msgs, num);
if (ret != I2C_RETRY)
goto out;
if (i2c_debug)
dev_dbg(&adap->dev, "Retrying transmission\n");
udelay(100);
}
i2c_pxa_scream_blue_murder(i2c, "exhausted retries");
ret = -EREMOTEIO;
out:
i2c_pxa_set_slave(i2c, ret);
return ret;
}
static void i2c_pxa_master_complete(struct pxa_i2c *i2c, int ret)
{
i2c->msg_ptr = 0;
i2c->msg = NULL;
i2c->msg_idx ++;
i2c->msg_num = 0;
if (ret)
i2c->msg_idx = ret;
if (!i2c->use_pio)
wake_up(&i2c->wait);
}
static void i2c_pxa_irq_txempty(struct pxa_i2c *i2c, u32 isr)
{
u32 icr = readl(_ICR(i2c)) & ~(ICR_START|ICR_STOP|ICR_ACKNAK|ICR_TB);
again:
if (isr & ISR_ALD) {
i2c_pxa_scream_blue_murder(i2c, "ALD set");
return;
}
if (isr & ISR_BED) {
int ret = BUS_ERROR;
if (isr & ISR_ACKNAK) {
if (i2c->msg_ptr == 0 && i2c->msg_idx == 0)
ret = I2C_RETRY;
else
ret = XFER_NAKED;
}
i2c_pxa_master_complete(i2c, ret);
} else if (isr & ISR_RWM) {
if (i2c->msg_ptr == i2c->msg->len - 1 &&
i2c->msg_idx == i2c->msg_num - 1)
icr |= ICR_STOP | ICR_ACKNAK;
icr |= ICR_ALDIE | ICR_TB;
} else if (i2c->msg_ptr < i2c->msg->len) {
writel(i2c->msg->buf[i2c->msg_ptr++], _IDBR(i2c));
icr |= ICR_ALDIE | ICR_TB;
if (i2c->msg_ptr == i2c->msg->len &&
i2c->msg_idx == i2c->msg_num - 1)
icr |= ICR_STOP;
} else if (i2c->msg_idx < i2c->msg_num - 1) {
i2c->msg_ptr = 0;
i2c->msg_idx ++;
i2c->msg++;
if (i2c->msg->flags & I2C_M_NOSTART)
goto again;
writel(i2c_pxa_addr_byte(i2c->msg), _IDBR(i2c));
icr &= ~ICR_ALDIE;
icr |= ICR_START | ICR_TB;
} else {
if (i2c->msg->len == 0) {
i2c_pxa_reset(i2c);
}
i2c_pxa_master_complete(i2c, 0);
}
i2c->icrlog[i2c->irqlogidx-1] = icr;
writel(icr, _ICR(i2c));
show_state(i2c);
}
static void i2c_pxa_irq_rxfull(struct pxa_i2c *i2c, u32 isr)
{
u32 icr = readl(_ICR(i2c)) & ~(ICR_START|ICR_STOP|ICR_ACKNAK|ICR_TB);
i2c->msg->buf[i2c->msg_ptr++] = readl(_IDBR(i2c));
if (i2c->msg_ptr < i2c->msg->len) {
if (i2c->msg_ptr == i2c->msg->len - 1)
icr |= ICR_STOP | ICR_ACKNAK;
icr |= ICR_ALDIE | ICR_TB;
} else {
i2c_pxa_master_complete(i2c, 0);
}
i2c->icrlog[i2c->irqlogidx-1] = icr;
writel(icr, _ICR(i2c));
}
static irqreturn_t i2c_pxa_handler(int this_irq, void *dev_id)
{
struct pxa_i2c *i2c = dev_id;
u32 isr = readl(_ISR(i2c));
if (!(isr & VALID_INT_SOURCE))
return IRQ_NONE;
if (i2c_debug > 2 && 0) {
dev_dbg(&i2c->adap.dev, "%s: ISR=%08x, ICR=%08x, IBMR=%02x\n",
__func__, isr, readl(_ICR(i2c)), readl(_IBMR(i2c)));
decode_ISR(isr);
}
if (i2c->irqlogidx < ARRAY_SIZE(i2c->isrlog))
i2c->isrlog[i2c->irqlogidx++] = isr;
show_state(i2c);
writel(isr & VALID_INT_SOURCE, _ISR(i2c));
if (isr & ISR_SAD)
i2c_pxa_slave_start(i2c, isr);
if (isr & ISR_SSD)
i2c_pxa_slave_stop(i2c);
if (i2c_pxa_is_slavemode(i2c)) {
if (isr & ISR_ITE)
i2c_pxa_slave_txempty(i2c, isr);
if (isr & ISR_IRF)
i2c_pxa_slave_rxfull(i2c, isr);
} else if (i2c->msg) {
if (isr & ISR_ITE)
i2c_pxa_irq_txempty(i2c, isr);
if (isr & ISR_IRF)
i2c_pxa_irq_rxfull(i2c, isr);
} else {
i2c_pxa_scream_blue_murder(i2c, "spurious irq");
}
return IRQ_HANDLED;
}
static int i2c_pxa_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct pxa_i2c *i2c = adap->algo_data;
int ret, i;
for (i = adap->retries; i >= 0; i--) {
ret = i2c_pxa_do_xfer(i2c, msgs, num);
if (ret != I2C_RETRY)
goto out;
if (i2c_debug)
dev_dbg(&adap->dev, "Retrying transmission\n");
udelay(100);
}
i2c_pxa_scream_blue_murder(i2c, "exhausted retries");
ret = -EREMOTEIO;
out:
i2c_pxa_set_slave(i2c, ret);
return ret;
}
static u32 i2c_pxa_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int i2c_pxa_probe_dt(struct platform_device *pdev, struct pxa_i2c *i2c,
enum pxa_i2c_types *i2c_types)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(i2c_pxa_dt_ids, &pdev->dev);
if (!of_id)
return 1;
i2c->adap.nr = -1;
if (of_get_property(np, "mrvl,i2c-polling", NULL))
i2c->use_pio = 1;
if (of_get_property(np, "mrvl,i2c-fast-mode", NULL))
i2c->fast_mode = 1;
*i2c_types = (u32)(of_id->data);
return 0;
}
static int i2c_pxa_probe_pdata(struct platform_device *pdev,
struct pxa_i2c *i2c,
enum pxa_i2c_types *i2c_types)
{
struct i2c_pxa_platform_data *plat = pdev->dev.platform_data;
const struct platform_device_id *id = platform_get_device_id(pdev);
*i2c_types = id->driver_data;
if (plat) {
i2c->use_pio = plat->use_pio;
i2c->fast_mode = plat->fast_mode;
}
return 0;
}
static int i2c_pxa_probe(struct platform_device *dev)
{
struct i2c_pxa_platform_data *plat = dev->dev.platform_data;
enum pxa_i2c_types i2c_type;
struct pxa_i2c *i2c;
struct resource *res = NULL;
int ret, irq;
i2c = kzalloc(sizeof(struct pxa_i2c), GFP_KERNEL);
if (!i2c) {
ret = -ENOMEM;
goto emalloc;
}
i2c->adap.nr = dev->id;
ret = i2c_pxa_probe_dt(dev, i2c, &i2c_type);
if (ret > 0)
ret = i2c_pxa_probe_pdata(dev, i2c, &i2c_type);
if (ret < 0)
goto eclk;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
irq = platform_get_irq(dev, 0);
if (res == NULL || irq < 0) {
ret = -ENODEV;
goto eclk;
}
if (!request_mem_region(res->start, resource_size(res), res->name)) {
ret = -ENOMEM;
goto eclk;
}
i2c->adap.owner = THIS_MODULE;
i2c->adap.retries = 5;
spin_lock_init(&i2c->lock);
init_waitqueue_head(&i2c->wait);
strlcpy(i2c->adap.name, "pxa_i2c-i2c", sizeof(i2c->adap.name));
i2c->clk = clk_get(&dev->dev, NULL);
if (IS_ERR(i2c->clk)) {
ret = PTR_ERR(i2c->clk);
goto eclk;
}
i2c->reg_base = ioremap(res->start, resource_size(res));
if (!i2c->reg_base) {
ret = -EIO;
goto eremap;
}
i2c->reg_ibmr = i2c->reg_base + pxa_reg_layout[i2c_type].ibmr;
i2c->reg_idbr = i2c->reg_base + pxa_reg_layout[i2c_type].idbr;
i2c->reg_icr = i2c->reg_base + pxa_reg_layout[i2c_type].icr;
i2c->reg_isr = i2c->reg_base + pxa_reg_layout[i2c_type].isr;
if (i2c_type != REGS_CE4100)
i2c->reg_isar = i2c->reg_base + pxa_reg_layout[i2c_type].isar;
i2c->iobase = res->start;
i2c->iosize = resource_size(res);
i2c->irq = irq;
i2c->slave_addr = I2C_PXA_SLAVE_ADDR;
if (plat) {
#ifdef CONFIG_I2C_PXA_SLAVE
i2c->slave_addr = plat->slave_addr;
i2c->slave = plat->slave;
#endif
i2c->adap.class = plat->class;
}
clk_enable(i2c->clk);
if (i2c->use_pio) {
i2c->adap.algo = &i2c_pxa_pio_algorithm;
} else {
i2c->adap.algo = &i2c_pxa_algorithm;
ret = request_irq(irq, i2c_pxa_handler, IRQF_SHARED,
dev_name(&dev->dev), i2c);
if (ret)
goto ereqirq;
}
i2c_pxa_reset(i2c);
i2c->adap.algo_data = i2c;
i2c->adap.dev.parent = &dev->dev;
#ifdef CONFIG_OF
i2c->adap.dev.of_node = dev->dev.of_node;
#endif
ret = i2c_add_numbered_adapter(&i2c->adap);
if (ret < 0) {
printk(KERN_INFO "I2C: Failed to add bus\n");
goto eadapt;
}
of_i2c_register_devices(&i2c->adap);
platform_set_drvdata(dev, i2c);
#ifdef CONFIG_I2C_PXA_SLAVE
printk(KERN_INFO "I2C: %s: PXA I2C adapter, slave address %d\n",
dev_name(&i2c->adap.dev), i2c->slave_addr);
#else
printk(KERN_INFO "I2C: %s: PXA I2C adapter\n",
dev_name(&i2c->adap.dev));
#endif
return 0;
eadapt:
if (!i2c->use_pio)
free_irq(irq, i2c);
ereqirq:
clk_disable(i2c->clk);
iounmap(i2c->reg_base);
eremap:
clk_put(i2c->clk);
eclk:
kfree(i2c);
emalloc:
release_mem_region(res->start, resource_size(res));
return ret;
}
static int i2c_pxa_remove(struct platform_device *dev)
{
struct pxa_i2c *i2c = platform_get_drvdata(dev);
i2c_del_adapter(&i2c->adap);
if (!i2c->use_pio)
free_irq(i2c->irq, i2c);
clk_disable(i2c->clk);
clk_put(i2c->clk);
iounmap(i2c->reg_base);
release_mem_region(i2c->iobase, i2c->iosize);
kfree(i2c);
return 0;
}
static int i2c_pxa_suspend_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pxa_i2c *i2c = platform_get_drvdata(pdev);
clk_disable(i2c->clk);
return 0;
}
static int i2c_pxa_resume_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pxa_i2c *i2c = platform_get_drvdata(pdev);
clk_enable(i2c->clk);
i2c_pxa_reset(i2c);
return 0;
}
static int __init i2c_adap_pxa_init(void)
{
return platform_driver_register(&i2c_pxa_driver);
}
static void __exit i2c_adap_pxa_exit(void)
{
platform_driver_unregister(&i2c_pxa_driver);
}
