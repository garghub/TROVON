static void
mv64xxx_i2c_hw_init(struct mv64xxx_i2c_data *drv_data)
{
writel(0, drv_data->reg_base + MV64XXX_I2C_REG_SOFT_RESET);
writel((((drv_data->freq_m & 0xf) << 3) | (drv_data->freq_n & 0x7)),
drv_data->reg_base + MV64XXX_I2C_REG_BAUD);
writel(0, drv_data->reg_base + MV64XXX_I2C_REG_SLAVE_ADDR);
writel(0, drv_data->reg_base + MV64XXX_I2C_REG_EXT_SLAVE_ADDR);
writel(MV64XXX_I2C_REG_CONTROL_TWSIEN | MV64XXX_I2C_REG_CONTROL_STOP,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
drv_data->state = MV64XXX_I2C_STATE_IDLE;
}
static void
mv64xxx_i2c_fsm(struct mv64xxx_i2c_data *drv_data, u32 status)
{
if (drv_data->state == MV64XXX_I2C_STATE_IDLE) {
drv_data->action = MV64XXX_I2C_ACTION_SEND_STOP;
return;
}
switch (status) {
case MV64XXX_I2C_STATUS_MAST_START:
case MV64XXX_I2C_STATUS_MAST_REPEAT_START:
drv_data->action = MV64XXX_I2C_ACTION_SEND_ADDR_1;
drv_data->state = MV64XXX_I2C_STATE_WAITING_FOR_ADDR_1_ACK;
break;
case MV64XXX_I2C_STATUS_MAST_WR_ADDR_ACK:
if (drv_data->msg->flags & I2C_M_TEN) {
drv_data->action = MV64XXX_I2C_ACTION_SEND_ADDR_2;
drv_data->state =
MV64XXX_I2C_STATE_WAITING_FOR_ADDR_2_ACK;
break;
}
case MV64XXX_I2C_STATUS_MAST_WR_ADDR_2_ACK:
case MV64XXX_I2C_STATUS_MAST_WR_ACK:
if ((drv_data->bytes_left == 0)
|| (drv_data->aborting
&& (drv_data->byte_posn != 0))) {
if (drv_data->send_stop) {
drv_data->action = MV64XXX_I2C_ACTION_SEND_STOP;
drv_data->state = MV64XXX_I2C_STATE_IDLE;
} else {
drv_data->action =
MV64XXX_I2C_ACTION_SEND_RESTART;
drv_data->state =
MV64XXX_I2C_STATE_WAITING_FOR_RESTART;
}
} else {
drv_data->action = MV64XXX_I2C_ACTION_SEND_DATA;
drv_data->state =
MV64XXX_I2C_STATE_WAITING_FOR_SLAVE_ACK;
drv_data->bytes_left--;
}
break;
case MV64XXX_I2C_STATUS_MAST_RD_ADDR_ACK:
if (drv_data->msg->flags & I2C_M_TEN) {
drv_data->action = MV64XXX_I2C_ACTION_SEND_ADDR_2;
drv_data->state =
MV64XXX_I2C_STATE_WAITING_FOR_ADDR_2_ACK;
break;
}
case MV64XXX_I2C_STATUS_MAST_RD_ADDR_2_ACK:
if (drv_data->bytes_left == 0) {
drv_data->action = MV64XXX_I2C_ACTION_SEND_STOP;
drv_data->state = MV64XXX_I2C_STATE_IDLE;
break;
}
case MV64XXX_I2C_STATUS_MAST_RD_DATA_ACK:
if (status != MV64XXX_I2C_STATUS_MAST_RD_DATA_ACK)
drv_data->action = MV64XXX_I2C_ACTION_CONTINUE;
else {
drv_data->action = MV64XXX_I2C_ACTION_RCV_DATA;
drv_data->bytes_left--;
}
drv_data->state = MV64XXX_I2C_STATE_WAITING_FOR_SLAVE_DATA;
if ((drv_data->bytes_left == 1) || drv_data->aborting)
drv_data->cntl_bits &= ~MV64XXX_I2C_REG_CONTROL_ACK;
break;
case MV64XXX_I2C_STATUS_MAST_RD_DATA_NO_ACK:
drv_data->action = MV64XXX_I2C_ACTION_RCV_DATA_STOP;
drv_data->state = MV64XXX_I2C_STATE_IDLE;
break;
case MV64XXX_I2C_STATUS_MAST_WR_ADDR_NO_ACK:
case MV64XXX_I2C_STATUS_MAST_WR_NO_ACK:
case MV64XXX_I2C_STATUS_MAST_RD_ADDR_NO_ACK:
drv_data->action = MV64XXX_I2C_ACTION_SEND_STOP;
drv_data->state = MV64XXX_I2C_STATE_IDLE;
drv_data->rc = -ENODEV;
break;
default:
dev_err(&drv_data->adapter.dev,
"mv64xxx_i2c_fsm: Ctlr Error -- state: 0x%x, "
"status: 0x%x, addr: 0x%x, flags: 0x%x\n",
drv_data->state, status, drv_data->msg->addr,
drv_data->msg->flags);
drv_data->action = MV64XXX_I2C_ACTION_SEND_STOP;
mv64xxx_i2c_hw_init(drv_data);
drv_data->rc = -EIO;
}
}
static void
mv64xxx_i2c_do_action(struct mv64xxx_i2c_data *drv_data)
{
switch(drv_data->action) {
case MV64XXX_I2C_ACTION_SEND_RESTART:
drv_data->cntl_bits |= MV64XXX_I2C_REG_CONTROL_START;
drv_data->cntl_bits &= ~MV64XXX_I2C_REG_CONTROL_INTEN;
writel(drv_data->cntl_bits,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
drv_data->block = 0;
wake_up(&drv_data->waitq);
break;
case MV64XXX_I2C_ACTION_CONTINUE:
writel(drv_data->cntl_bits,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
break;
case MV64XXX_I2C_ACTION_SEND_START:
writel(drv_data->cntl_bits | MV64XXX_I2C_REG_CONTROL_START,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
break;
case MV64XXX_I2C_ACTION_SEND_ADDR_1:
writel(drv_data->addr1,
drv_data->reg_base + MV64XXX_I2C_REG_DATA);
writel(drv_data->cntl_bits,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
break;
case MV64XXX_I2C_ACTION_SEND_ADDR_2:
writel(drv_data->addr2,
drv_data->reg_base + MV64XXX_I2C_REG_DATA);
writel(drv_data->cntl_bits,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
break;
case MV64XXX_I2C_ACTION_SEND_DATA:
writel(drv_data->msg->buf[drv_data->byte_posn++],
drv_data->reg_base + MV64XXX_I2C_REG_DATA);
writel(drv_data->cntl_bits,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
break;
case MV64XXX_I2C_ACTION_RCV_DATA:
drv_data->msg->buf[drv_data->byte_posn++] =
readl(drv_data->reg_base + MV64XXX_I2C_REG_DATA);
writel(drv_data->cntl_bits,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
break;
case MV64XXX_I2C_ACTION_RCV_DATA_STOP:
drv_data->msg->buf[drv_data->byte_posn++] =
readl(drv_data->reg_base + MV64XXX_I2C_REG_DATA);
drv_data->cntl_bits &= ~MV64XXX_I2C_REG_CONTROL_INTEN;
writel(drv_data->cntl_bits | MV64XXX_I2C_REG_CONTROL_STOP,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
drv_data->block = 0;
wake_up(&drv_data->waitq);
break;
case MV64XXX_I2C_ACTION_INVALID:
default:
dev_err(&drv_data->adapter.dev,
"mv64xxx_i2c_do_action: Invalid action: %d\n",
drv_data->action);
drv_data->rc = -EIO;
case MV64XXX_I2C_ACTION_SEND_STOP:
drv_data->cntl_bits &= ~MV64XXX_I2C_REG_CONTROL_INTEN;
writel(drv_data->cntl_bits | MV64XXX_I2C_REG_CONTROL_STOP,
drv_data->reg_base + MV64XXX_I2C_REG_CONTROL);
drv_data->block = 0;
wake_up(&drv_data->waitq);
break;
}
}
static irqreturn_t
mv64xxx_i2c_intr(int irq, void *dev_id)
{
struct mv64xxx_i2c_data *drv_data = dev_id;
unsigned long flags;
u32 status;
irqreturn_t rc = IRQ_NONE;
spin_lock_irqsave(&drv_data->lock, flags);
while (readl(drv_data->reg_base + MV64XXX_I2C_REG_CONTROL) &
MV64XXX_I2C_REG_CONTROL_IFLG) {
status = readl(drv_data->reg_base + MV64XXX_I2C_REG_STATUS);
mv64xxx_i2c_fsm(drv_data, status);
mv64xxx_i2c_do_action(drv_data);
rc = IRQ_HANDLED;
}
spin_unlock_irqrestore(&drv_data->lock, flags);
return rc;
}
static void
mv64xxx_i2c_prepare_for_io(struct mv64xxx_i2c_data *drv_data,
struct i2c_msg *msg)
{
u32 dir = 0;
drv_data->msg = msg;
drv_data->byte_posn = 0;
drv_data->bytes_left = msg->len;
drv_data->aborting = 0;
drv_data->rc = 0;
drv_data->cntl_bits = MV64XXX_I2C_REG_CONTROL_ACK |
MV64XXX_I2C_REG_CONTROL_INTEN | MV64XXX_I2C_REG_CONTROL_TWSIEN;
if (msg->flags & I2C_M_RD)
dir = 1;
if (msg->flags & I2C_M_TEN) {
drv_data->addr1 = 0xf0 | (((u32)msg->addr & 0x300) >> 7) | dir;
drv_data->addr2 = (u32)msg->addr & 0xff;
} else {
drv_data->addr1 = ((u32)msg->addr & 0x7f) << 1 | dir;
drv_data->addr2 = 0;
}
}
static void
mv64xxx_i2c_wait_for_completion(struct mv64xxx_i2c_data *drv_data)
{
long time_left;
unsigned long flags;
char abort = 0;
time_left = wait_event_timeout(drv_data->waitq,
!drv_data->block, drv_data->adapter.timeout);
spin_lock_irqsave(&drv_data->lock, flags);
if (!time_left) {
drv_data->rc = -ETIMEDOUT;
abort = 1;
} else if (time_left < 0) {
drv_data->rc = time_left;
abort = 1;
}
if (abort && drv_data->block) {
drv_data->aborting = 1;
spin_unlock_irqrestore(&drv_data->lock, flags);
time_left = wait_event_timeout(drv_data->waitq,
!drv_data->block, drv_data->adapter.timeout);
if ((time_left <= 0) && drv_data->block) {
drv_data->state = MV64XXX_I2C_STATE_IDLE;
dev_err(&drv_data->adapter.dev,
"mv64xxx: I2C bus locked, block: %d, "
"time_left: %d\n", drv_data->block,
(int)time_left);
mv64xxx_i2c_hw_init(drv_data);
}
} else
spin_unlock_irqrestore(&drv_data->lock, flags);
}
static int
mv64xxx_i2c_execute_msg(struct mv64xxx_i2c_data *drv_data, struct i2c_msg *msg,
int is_first, int is_last)
{
unsigned long flags;
spin_lock_irqsave(&drv_data->lock, flags);
mv64xxx_i2c_prepare_for_io(drv_data, msg);
if (unlikely(msg->flags & I2C_M_NOSTART)) {
if (drv_data->msg->flags & I2C_M_RD) {
drv_data->action = MV64XXX_I2C_ACTION_CONTINUE;
drv_data->state =
MV64XXX_I2C_STATE_WAITING_FOR_SLAVE_DATA;
} else {
drv_data->action = MV64XXX_I2C_ACTION_SEND_DATA;
drv_data->state =
MV64XXX_I2C_STATE_WAITING_FOR_SLAVE_ACK;
drv_data->bytes_left--;
}
} else {
if (is_first) {
drv_data->action = MV64XXX_I2C_ACTION_SEND_START;
drv_data->state =
MV64XXX_I2C_STATE_WAITING_FOR_START_COND;
} else {
drv_data->action = MV64XXX_I2C_ACTION_SEND_ADDR_1;
drv_data->state =
MV64XXX_I2C_STATE_WAITING_FOR_ADDR_1_ACK;
}
}
drv_data->send_stop = is_last;
drv_data->block = 1;
mv64xxx_i2c_do_action(drv_data);
spin_unlock_irqrestore(&drv_data->lock, flags);
mv64xxx_i2c_wait_for_completion(drv_data);
return drv_data->rc;
}
static u32
mv64xxx_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR | I2C_FUNC_SMBUS_EMUL;
}
static int
mv64xxx_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct mv64xxx_i2c_data *drv_data = i2c_get_adapdata(adap);
int i, rc;
for (i = 0; i < num; i++) {
rc = mv64xxx_i2c_execute_msg(drv_data, &msgs[i],
i == 0, i + 1 == num);
if (rc < 0)
return rc;
}
return num;
}
static int
mv64xxx_i2c_map_regs(struct platform_device *pd,
struct mv64xxx_i2c_data *drv_data)
{
int size;
struct resource *r = platform_get_resource(pd, IORESOURCE_MEM, 0);
if (!r)
return -ENODEV;
size = resource_size(r);
if (!request_mem_region(r->start, size, drv_data->adapter.name))
return -EBUSY;
drv_data->reg_base = ioremap(r->start, size);
drv_data->reg_base_p = r->start;
drv_data->reg_size = size;
return 0;
}
static void
mv64xxx_i2c_unmap_regs(struct mv64xxx_i2c_data *drv_data)
{
if (drv_data->reg_base) {
iounmap(drv_data->reg_base);
release_mem_region(drv_data->reg_base_p, drv_data->reg_size);
}
drv_data->reg_base = NULL;
drv_data->reg_base_p = 0;
}
static int
mv64xxx_calc_freq(const int tclk, const int n, const int m)
{
return tclk / (10 * (m + 1) * (2 << n));
}
static bool
mv64xxx_find_baud_factors(const u32 req_freq, const u32 tclk, u32 *best_n,
u32 *best_m)
{
int freq, delta, best_delta = INT_MAX;
int m, n;
for (n = 0; n <= 7; n++)
for (m = 0; m <= 15; m++) {
freq = mv64xxx_calc_freq(tclk, n, m);
delta = req_freq - freq;
if (delta >= 0 && delta < best_delta) {
*best_m = m;
*best_n = n;
best_delta = delta;
}
if (best_delta == 0)
return true;
}
if (best_delta == INT_MAX)
return false;
return true;
}
static int
mv64xxx_of_config(struct mv64xxx_i2c_data *drv_data,
struct device_node *np)
{
u32 bus_freq, tclk;
int rc = 0;
#if !defined(CONFIG_HAVE_CLK)
return -ENODEV;
#else
if (IS_ERR(drv_data->clk)) {
rc = -ENODEV;
goto out;
}
tclk = clk_get_rate(drv_data->clk);
of_property_read_u32(np, "clock-frequency", &bus_freq);
if (!mv64xxx_find_baud_factors(bus_freq, tclk,
&drv_data->freq_n, &drv_data->freq_m)) {
rc = -EINVAL;
goto out;
}
drv_data->irq = irq_of_parse_and_map(np, 0);
drv_data->adapter.timeout = HZ;
out:
return rc;
#endif
}
static int
mv64xxx_of_config(struct mv64xxx_i2c_data *drv_data,
struct device_node *np)
{
return -ENODEV;
}
static int
mv64xxx_i2c_probe(struct platform_device *pd)
{
struct mv64xxx_i2c_data *drv_data;
struct mv64xxx_i2c_pdata *pdata = pd->dev.platform_data;
int rc;
if ((!pdata && !pd->dev.of_node))
return -ENODEV;
drv_data = kzalloc(sizeof(struct mv64xxx_i2c_data), GFP_KERNEL);
if (!drv_data)
return -ENOMEM;
if (mv64xxx_i2c_map_regs(pd, drv_data)) {
rc = -ENODEV;
goto exit_kfree;
}
strlcpy(drv_data->adapter.name, MV64XXX_I2C_CTLR_NAME " adapter",
sizeof(drv_data->adapter.name));
init_waitqueue_head(&drv_data->waitq);
spin_lock_init(&drv_data->lock);
#if defined(CONFIG_HAVE_CLK)
drv_data->clk = clk_get(&pd->dev, NULL);
if (!IS_ERR(drv_data->clk)) {
clk_prepare(drv_data->clk);
clk_enable(drv_data->clk);
}
#endif
if (pdata) {
drv_data->freq_m = pdata->freq_m;
drv_data->freq_n = pdata->freq_n;
drv_data->irq = platform_get_irq(pd, 0);
drv_data->adapter.timeout = msecs_to_jiffies(pdata->timeout);
} else if (pd->dev.of_node) {
rc = mv64xxx_of_config(drv_data, pd->dev.of_node);
if (rc)
goto exit_unmap_regs;
}
if (drv_data->irq < 0) {
rc = -ENXIO;
goto exit_unmap_regs;
}
drv_data->adapter.dev.parent = &pd->dev;
drv_data->adapter.algo = &mv64xxx_i2c_algo;
drv_data->adapter.owner = THIS_MODULE;
drv_data->adapter.class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
drv_data->adapter.nr = pd->id;
drv_data->adapter.dev.of_node = pd->dev.of_node;
platform_set_drvdata(pd, drv_data);
i2c_set_adapdata(&drv_data->adapter, drv_data);
mv64xxx_i2c_hw_init(drv_data);
if (request_irq(drv_data->irq, mv64xxx_i2c_intr, 0,
MV64XXX_I2C_CTLR_NAME, drv_data)) {
dev_err(&drv_data->adapter.dev,
"mv64xxx: Can't register intr handler irq: %d\n",
drv_data->irq);
rc = -EINVAL;
goto exit_unmap_regs;
} else if ((rc = i2c_add_numbered_adapter(&drv_data->adapter)) != 0) {
dev_err(&drv_data->adapter.dev,
"mv64xxx: Can't add i2c adapter, rc: %d\n", -rc);
goto exit_free_irq;
}
of_i2c_register_devices(&drv_data->adapter);
return 0;
exit_free_irq:
free_irq(drv_data->irq, drv_data);
exit_unmap_regs:
#if defined(CONFIG_HAVE_CLK)
if (!IS_ERR(drv_data->clk)) {
clk_disable(drv_data->clk);
clk_unprepare(drv_data->clk);
}
#endif
mv64xxx_i2c_unmap_regs(drv_data);
exit_kfree:
kfree(drv_data);
return rc;
}
static int
mv64xxx_i2c_remove(struct platform_device *dev)
{
struct mv64xxx_i2c_data *drv_data = platform_get_drvdata(dev);
i2c_del_adapter(&drv_data->adapter);
free_irq(drv_data->irq, drv_data);
mv64xxx_i2c_unmap_regs(drv_data);
#if defined(CONFIG_HAVE_CLK)
if (!IS_ERR(drv_data->clk)) {
clk_disable(drv_data->clk);
clk_unprepare(drv_data->clk);
}
#endif
kfree(drv_data);
return 0;
}
