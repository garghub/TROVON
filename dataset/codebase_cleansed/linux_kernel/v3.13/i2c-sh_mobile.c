static void iic_wr(struct sh_mobile_i2c_data *pd, int offs, unsigned char data)
{
if (offs == ICIC)
data |= pd->icic;
iowrite8(data, pd->reg + offs);
}
static unsigned char iic_rd(struct sh_mobile_i2c_data *pd, int offs)
{
return ioread8(pd->reg + offs);
}
static void iic_set_clr(struct sh_mobile_i2c_data *pd, int offs,
unsigned char set, unsigned char clr)
{
iic_wr(pd, offs, (iic_rd(pd, offs) | set) & ~clr);
}
static u32 sh_mobile_i2c_iccl(unsigned long count_khz, u32 tLOW, u32 tf, int offset)
{
return (((count_khz * (tLOW + tf)) + 5000) / 10000) + offset;
}
static u32 sh_mobile_i2c_icch(unsigned long count_khz, u32 tHIGH, u32 tf, int offset)
{
return (((count_khz * (tHIGH + tf)) + 5000) / 10000) + offset;
}
static void sh_mobile_i2c_init(struct sh_mobile_i2c_data *pd)
{
unsigned long i2c_clk_khz;
u32 tHIGH, tLOW, tf;
int offset;
clk_prepare_enable(pd->clk);
i2c_clk_khz = clk_get_rate(pd->clk) / 1000;
i2c_clk_khz /= pd->clks_per_count;
if (pd->bus_speed == STANDARD_MODE) {
tLOW = 47;
tHIGH = 40;
tf = 3;
offset = 0;
} else if (pd->bus_speed == FAST_MODE) {
tLOW = 13;
tHIGH = 6;
tf = 3;
offset = 0;
} else {
dev_err(pd->dev, "unrecognized bus speed %lu Hz\n",
pd->bus_speed);
goto out;
}
pd->iccl = sh_mobile_i2c_iccl(i2c_clk_khz, tLOW, tf, offset);
if ((pd->iccl > 0xff) && (pd->flags & IIC_FLAG_HAS_ICIC67))
pd->icic |= ICIC_ICCLB8;
else
pd->icic &= ~ICIC_ICCLB8;
pd->icch = sh_mobile_i2c_icch(i2c_clk_khz, tHIGH, tf, offset);
if ((pd->icch > 0xff) && (pd->flags & IIC_FLAG_HAS_ICIC67))
pd->icic |= ICIC_ICCHB8;
else
pd->icic &= ~ICIC_ICCHB8;
out:
clk_disable_unprepare(pd->clk);
}
static void activate_ch(struct sh_mobile_i2c_data *pd)
{
pm_runtime_get_sync(pd->dev);
clk_prepare_enable(pd->clk);
iic_set_clr(pd, ICCR, ICCR_ICE, 0);
iic_wr(pd, ICIC, 0);
iic_wr(pd, ICCL, pd->iccl & 0xff);
iic_wr(pd, ICCH, pd->icch & 0xff);
}
static void deactivate_ch(struct sh_mobile_i2c_data *pd)
{
iic_wr(pd, ICSR, 0);
iic_wr(pd, ICIC, 0);
iic_set_clr(pd, ICCR, 0, ICCR_ICE);
clk_disable_unprepare(pd->clk);
pm_runtime_put_sync(pd->dev);
}
static unsigned char i2c_op(struct sh_mobile_i2c_data *pd,
enum sh_mobile_i2c_op op, unsigned char data)
{
unsigned char ret = 0;
unsigned long flags;
dev_dbg(pd->dev, "op %d, data in 0x%02x\n", op, data);
spin_lock_irqsave(&pd->lock, flags);
switch (op) {
case OP_START:
iic_wr(pd, ICCR, 0x94);
break;
case OP_TX_FIRST:
iic_wr(pd, ICIC, ICIC_WAITE | ICIC_ALE | ICIC_TACKE);
iic_wr(pd, ICDR, data);
break;
case OP_TX:
iic_wr(pd, ICDR, data);
break;
case OP_TX_STOP:
iic_wr(pd, ICDR, data);
iic_wr(pd, ICCR, pd->send_stop ? 0x90 : 0x94);
break;
case OP_TX_TO_RX:
iic_wr(pd, ICCR, 0x81);
break;
case OP_RX:
ret = iic_rd(pd, ICDR);
break;
case OP_RX_STOP:
iic_wr(pd, ICIC,
ICIC_DTEE | ICIC_WAITE | ICIC_ALE | ICIC_TACKE);
iic_wr(pd, ICCR, 0xc0);
break;
case OP_RX_STOP_DATA:
iic_wr(pd, ICIC,
ICIC_DTEE | ICIC_WAITE | ICIC_ALE | ICIC_TACKE);
ret = iic_rd(pd, ICDR);
iic_wr(pd, ICCR, 0xc0);
break;
}
spin_unlock_irqrestore(&pd->lock, flags);
dev_dbg(pd->dev, "op %d, data out 0x%02x\n", op, ret);
return ret;
}
static bool sh_mobile_i2c_is_first_byte(struct sh_mobile_i2c_data *pd)
{
return pd->pos == -1;
}
static bool sh_mobile_i2c_is_last_byte(struct sh_mobile_i2c_data *pd)
{
return pd->pos == pd->msg->len - 1;
}
static void sh_mobile_i2c_get_data(struct sh_mobile_i2c_data *pd,
unsigned char *buf)
{
switch (pd->pos) {
case -1:
*buf = (pd->msg->addr & 0x7f) << 1;
*buf |= (pd->msg->flags & I2C_M_RD) ? 1 : 0;
break;
default:
*buf = pd->msg->buf[pd->pos];
}
}
static int sh_mobile_i2c_isr_tx(struct sh_mobile_i2c_data *pd)
{
unsigned char data;
if (pd->pos == pd->msg->len)
return 1;
sh_mobile_i2c_get_data(pd, &data);
if (sh_mobile_i2c_is_last_byte(pd))
i2c_op(pd, OP_TX_STOP, data);
else if (sh_mobile_i2c_is_first_byte(pd))
i2c_op(pd, OP_TX_FIRST, data);
else
i2c_op(pd, OP_TX, data);
pd->pos++;
return 0;
}
static int sh_mobile_i2c_isr_rx(struct sh_mobile_i2c_data *pd)
{
unsigned char data;
int real_pos;
do {
if (pd->pos <= -1) {
sh_mobile_i2c_get_data(pd, &data);
if (sh_mobile_i2c_is_first_byte(pd))
i2c_op(pd, OP_TX_FIRST, data);
else
i2c_op(pd, OP_TX, data);
break;
}
if (pd->pos == 0) {
i2c_op(pd, OP_TX_TO_RX, 0);
break;
}
real_pos = pd->pos - 2;
if (pd->pos == pd->msg->len) {
if (real_pos < 0) {
i2c_op(pd, OP_RX_STOP, 0);
break;
}
data = i2c_op(pd, OP_RX_STOP_DATA, 0);
} else
data = i2c_op(pd, OP_RX, 0);
if (real_pos >= 0)
pd->msg->buf[real_pos] = data;
} while (0);
pd->pos++;
return pd->pos == (pd->msg->len + 2);
}
static irqreturn_t sh_mobile_i2c_isr(int irq, void *dev_id)
{
struct platform_device *dev = dev_id;
struct sh_mobile_i2c_data *pd = platform_get_drvdata(dev);
unsigned char sr;
int wakeup;
sr = iic_rd(pd, ICSR);
pd->sr |= sr;
dev_dbg(pd->dev, "i2c_isr 0x%02x 0x%02x %s %d %d!\n", sr, pd->sr,
(pd->msg->flags & I2C_M_RD) ? "read" : "write",
pd->pos, pd->msg->len);
if (sr & (ICSR_AL | ICSR_TACK)) {
iic_wr(pd, ICSR, sr & ~(ICSR_AL | ICSR_TACK));
wakeup = 0;
} else if (pd->msg->flags & I2C_M_RD)
wakeup = sh_mobile_i2c_isr_rx(pd);
else
wakeup = sh_mobile_i2c_isr_tx(pd);
if (sr & ICSR_WAIT)
iic_wr(pd, ICSR, sr & ~ICSR_WAIT);
if (wakeup) {
pd->sr |= SW_DONE;
wake_up(&pd->wait);
}
iic_rd(pd, ICSR);
return IRQ_HANDLED;
}
static int start_ch(struct sh_mobile_i2c_data *pd, struct i2c_msg *usr_msg,
bool do_init)
{
if (usr_msg->len == 0 && (usr_msg->flags & I2C_M_RD)) {
dev_err(pd->dev, "Unsupported zero length i2c read\n");
return -EIO;
}
if (do_init) {
iic_set_clr(pd, ICCR, 0, ICCR_ICE);
iic_set_clr(pd, ICCR, ICCR_ICE, 0);
iic_wr(pd, ICCL, pd->iccl & 0xff);
iic_wr(pd, ICCH, pd->icch & 0xff);
}
pd->msg = usr_msg;
pd->pos = -1;
pd->sr = 0;
iic_wr(pd, ICIC, ICIC_DTEE | ICIC_WAITE | ICIC_ALE | ICIC_TACKE);
return 0;
}
static int poll_dte(struct sh_mobile_i2c_data *pd)
{
int i;
for (i = 1000; i; i--) {
u_int8_t val = iic_rd(pd, ICSR);
if (val & ICSR_DTE)
break;
if (val & ICSR_TACK)
return -EIO;
udelay(10);
}
if (!i) {
dev_warn(pd->dev, "Timeout polling for DTE!\n");
return -ETIMEDOUT;
}
return 0;
}
static int poll_busy(struct sh_mobile_i2c_data *pd)
{
int i;
for (i = 1000; i; i--) {
u_int8_t val = iic_rd(pd, ICSR);
dev_dbg(pd->dev, "val 0x%02x pd->sr 0x%02x\n", val, pd->sr);
if (!(val & ICSR_BUSY)) {
if ((val | pd->sr) & (ICSR_TACK | ICSR_AL))
return -EIO;
break;
}
udelay(10);
}
if (!i) {
dev_err(pd->dev, "Polling timed out\n");
return -ETIMEDOUT;
}
return 0;
}
static int sh_mobile_i2c_xfer(struct i2c_adapter *adapter,
struct i2c_msg *msgs,
int num)
{
struct sh_mobile_i2c_data *pd = i2c_get_adapdata(adapter);
struct i2c_msg *msg;
int err = 0;
int i, k;
activate_ch(pd);
for (i = 0; i < num; i++) {
bool do_start = pd->send_stop || !i;
msg = &msgs[i];
pd->send_stop = i == num - 1 || msg->flags & I2C_M_STOP;
err = start_ch(pd, msg, do_start);
if (err)
break;
if (do_start)
i2c_op(pd, OP_START, 0);
k = wait_event_timeout(pd->wait,
pd->sr & (ICSR_TACK | SW_DONE),
5 * HZ);
if (!k) {
dev_err(pd->dev, "Transfer request timed out\n");
err = -ETIMEDOUT;
break;
}
if (pd->send_stop)
err = poll_busy(pd);
else
err = poll_dte(pd);
if (err < 0)
break;
}
deactivate_ch(pd);
if (!err)
err = num;
return err;
}
static u32 sh_mobile_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_PROTOCOL_MANGLING;
}
static int sh_mobile_i2c_hook_irqs(struct platform_device *dev, int hook)
{
struct resource *res;
int ret = -ENXIO;
int n, k = 0;
while ((res = platform_get_resource(dev, IORESOURCE_IRQ, k))) {
for (n = res->start; hook && n <= res->end; n++) {
if (request_irq(n, sh_mobile_i2c_isr, 0,
dev_name(&dev->dev), dev)) {
for (n--; n >= res->start; n--)
free_irq(n, dev);
goto rollback;
}
}
k++;
}
if (hook)
return k > 0 ? 0 : -ENOENT;
ret = 0;
rollback:
k--;
while (k >= 0) {
res = platform_get_resource(dev, IORESOURCE_IRQ, k);
for (n = res->start; n <= res->end; n++)
free_irq(n, dev);
k--;
}
return ret;
}
static int sh_mobile_i2c_probe(struct platform_device *dev)
{
struct i2c_sh_mobile_platform_data *pdata = dev_get_platdata(&dev->dev);
struct sh_mobile_i2c_data *pd;
struct i2c_adapter *adap;
struct resource *res;
int size;
int ret;
pd = kzalloc(sizeof(struct sh_mobile_i2c_data), GFP_KERNEL);
if (pd == NULL) {
dev_err(&dev->dev, "cannot allocate private data\n");
return -ENOMEM;
}
pd->clk = clk_get(&dev->dev, NULL);
if (IS_ERR(pd->clk)) {
dev_err(&dev->dev, "cannot get clock\n");
ret = PTR_ERR(pd->clk);
goto err;
}
ret = sh_mobile_i2c_hook_irqs(dev, 1);
if (ret) {
dev_err(&dev->dev, "cannot request IRQ\n");
goto err_clk;
}
pd->dev = &dev->dev;
platform_set_drvdata(dev, pd);
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&dev->dev, "cannot find IO resource\n");
ret = -ENOENT;
goto err_irq;
}
size = resource_size(res);
pd->reg = ioremap(res->start, size);
if (pd->reg == NULL) {
dev_err(&dev->dev, "cannot map IO\n");
ret = -ENXIO;
goto err_irq;
}
pd->bus_speed = STANDARD_MODE;
if (pdata && pdata->bus_speed)
pd->bus_speed = pdata->bus_speed;
pd->clks_per_count = 1;
if (pdata && pdata->clks_per_count)
pd->clks_per_count = pdata->clks_per_count;
if (size > 0x17)
pd->flags |= IIC_FLAG_HAS_ICIC67;
sh_mobile_i2c_init(pd);
pm_suspend_ignore_children(&dev->dev, true);
pm_runtime_enable(&dev->dev);
adap = &pd->adap;
i2c_set_adapdata(adap, pd);
adap->owner = THIS_MODULE;
adap->algo = &sh_mobile_i2c_algorithm;
adap->dev.parent = &dev->dev;
adap->retries = 5;
adap->nr = dev->id;
adap->dev.of_node = dev->dev.of_node;
strlcpy(adap->name, dev->name, sizeof(adap->name));
spin_lock_init(&pd->lock);
init_waitqueue_head(&pd->wait);
ret = i2c_add_numbered_adapter(adap);
if (ret < 0) {
dev_err(&dev->dev, "cannot add numbered adapter\n");
goto err_all;
}
dev_info(&dev->dev,
"I2C adapter %d with bus speed %lu Hz (L/H=%x/%x)\n",
adap->nr, pd->bus_speed, pd->iccl, pd->icch);
return 0;
err_all:
iounmap(pd->reg);
err_irq:
sh_mobile_i2c_hook_irqs(dev, 0);
err_clk:
clk_put(pd->clk);
err:
kfree(pd);
return ret;
}
static int sh_mobile_i2c_remove(struct platform_device *dev)
{
struct sh_mobile_i2c_data *pd = platform_get_drvdata(dev);
i2c_del_adapter(&pd->adap);
iounmap(pd->reg);
sh_mobile_i2c_hook_irqs(dev, 0);
clk_put(pd->clk);
pm_runtime_disable(&dev->dev);
kfree(pd);
return 0;
}
static int sh_mobile_i2c_runtime_nop(struct device *dev)
{
return 0;
}
static int __init sh_mobile_i2c_adap_init(void)
{
return platform_driver_register(&sh_mobile_i2c_driver);
}
static void __exit sh_mobile_i2c_adap_exit(void)
{
platform_driver_unregister(&sh_mobile_i2c_driver);
}
