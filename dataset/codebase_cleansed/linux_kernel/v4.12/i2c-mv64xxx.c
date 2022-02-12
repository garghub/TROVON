static void
mv64xxx_i2c_prepare_for_io(struct mv64xxx_i2c_data *drv_data,
struct i2c_msg *msg)
{
u32 dir = 0;
drv_data->cntl_bits = MV64XXX_I2C_REG_CONTROL_ACK |
MV64XXX_I2C_REG_CONTROL_INTEN | MV64XXX_I2C_REG_CONTROL_TWSIEN;
if (msg->flags & I2C_M_RD)
dir = 1;
if (msg->flags & I2C_M_TEN) {
drv_data->addr1 = 0xf0 | (((u32)msg->addr & 0x300) >> 7) | dir;
drv_data->addr2 = (u32)msg->addr & 0xff;
} else {
drv_data->addr1 = MV64XXX_I2C_ADDR_ADDR((u32)msg->addr) | dir;
drv_data->addr2 = 0;
}
}
static void
mv64xxx_i2c_hw_init(struct mv64xxx_i2c_data *drv_data)
{
if (drv_data->offload_enabled) {
writel(0, drv_data->reg_base + MV64XXX_I2C_REG_BRIDGE_CONTROL);
writel(0, drv_data->reg_base + MV64XXX_I2C_REG_BRIDGE_TIMING);
writel(0, drv_data->reg_base +
MV64XXX_I2C_REG_BRIDGE_INTR_CAUSE);
writel(0, drv_data->reg_base +
MV64XXX_I2C_REG_BRIDGE_INTR_MASK);
}
writel(0, drv_data->reg_base + drv_data->reg_offsets.soft_reset);
writel(MV64XXX_I2C_BAUD_DIV_M(drv_data->freq_m) | MV64XXX_I2C_BAUD_DIV_N(drv_data->freq_n),
drv_data->reg_base + drv_data->reg_offsets.clock);
writel(0, drv_data->reg_base + drv_data->reg_offsets.addr);
writel(0, drv_data->reg_base + drv_data->reg_offsets.ext_addr);
writel(MV64XXX_I2C_REG_CONTROL_TWSIEN | MV64XXX_I2C_REG_CONTROL_STOP,
drv_data->reg_base + drv_data->reg_offsets.control);
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
if (drv_data->send_stop || drv_data->aborting) {
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
drv_data->rc = -ENXIO;
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
static void mv64xxx_i2c_send_start(struct mv64xxx_i2c_data *drv_data)
{
drv_data->msg = drv_data->msgs;
drv_data->byte_posn = 0;
drv_data->bytes_left = drv_data->msg->len;
drv_data->aborting = 0;
drv_data->rc = 0;
mv64xxx_i2c_prepare_for_io(drv_data, drv_data->msgs);
writel(drv_data->cntl_bits | MV64XXX_I2C_REG_CONTROL_START,
drv_data->reg_base + drv_data->reg_offsets.control);
}
static void
mv64xxx_i2c_do_action(struct mv64xxx_i2c_data *drv_data)
{
switch(drv_data->action) {
case MV64XXX_I2C_ACTION_SEND_RESTART:
BUG_ON(drv_data->num_msgs == 0);
drv_data->msgs++;
drv_data->num_msgs--;
mv64xxx_i2c_send_start(drv_data);
if (drv_data->errata_delay)
udelay(5);
drv_data->send_stop = drv_data->num_msgs == 1;
break;
case MV64XXX_I2C_ACTION_CONTINUE:
writel(drv_data->cntl_bits,
drv_data->reg_base + drv_data->reg_offsets.control);
break;
case MV64XXX_I2C_ACTION_SEND_ADDR_1:
writel(drv_data->addr1,
drv_data->reg_base + drv_data->reg_offsets.data);
writel(drv_data->cntl_bits,
drv_data->reg_base + drv_data->reg_offsets.control);
break;
case MV64XXX_I2C_ACTION_SEND_ADDR_2:
writel(drv_data->addr2,
drv_data->reg_base + drv_data->reg_offsets.data);
writel(drv_data->cntl_bits,
drv_data->reg_base + drv_data->reg_offsets.control);
break;
case MV64XXX_I2C_ACTION_SEND_DATA:
writel(drv_data->msg->buf[drv_data->byte_posn++],
drv_data->reg_base + drv_data->reg_offsets.data);
writel(drv_data->cntl_bits,
drv_data->reg_base + drv_data->reg_offsets.control);
break;
case MV64XXX_I2C_ACTION_RCV_DATA:
drv_data->msg->buf[drv_data->byte_posn++] =
readl(drv_data->reg_base + drv_data->reg_offsets.data);
writel(drv_data->cntl_bits,
drv_data->reg_base + drv_data->reg_offsets.control);
break;
case MV64XXX_I2C_ACTION_RCV_DATA_STOP:
drv_data->msg->buf[drv_data->byte_posn++] =
readl(drv_data->reg_base + drv_data->reg_offsets.data);
drv_data->cntl_bits &= ~MV64XXX_I2C_REG_CONTROL_INTEN;
writel(drv_data->cntl_bits | MV64XXX_I2C_REG_CONTROL_STOP,
drv_data->reg_base + drv_data->reg_offsets.control);
drv_data->block = 0;
if (drv_data->errata_delay)
udelay(5);
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
drv_data->reg_base + drv_data->reg_offsets.control);
drv_data->block = 0;
wake_up(&drv_data->waitq);
break;
}
}
static void
mv64xxx_i2c_read_offload_rx_data(struct mv64xxx_i2c_data *drv_data,
struct i2c_msg *msg)
{
u32 buf[2];
buf[0] = readl(drv_data->reg_base + MV64XXX_I2C_REG_RX_DATA_LO);
buf[1] = readl(drv_data->reg_base + MV64XXX_I2C_REG_RX_DATA_HI);
memcpy(msg->buf, buf, msg->len);
}
static int
mv64xxx_i2c_intr_offload(struct mv64xxx_i2c_data *drv_data)
{
u32 cause, status;
cause = readl(drv_data->reg_base +
MV64XXX_I2C_REG_BRIDGE_INTR_CAUSE);
if (!cause)
return IRQ_NONE;
status = readl(drv_data->reg_base +
MV64XXX_I2C_REG_BRIDGE_STATUS);
if (status & MV64XXX_I2C_BRIDGE_STATUS_ERROR) {
drv_data->rc = -EIO;
goto out;
}
drv_data->rc = 0;
if (drv_data->num_msgs == 1 && drv_data->msgs[0].flags & I2C_M_RD) {
mv64xxx_i2c_read_offload_rx_data(drv_data, drv_data->msgs);
drv_data->msgs++;
drv_data->num_msgs--;
}
else if (drv_data->num_msgs == 2 &&
!(drv_data->msgs[0].flags & I2C_M_RD) &&
drv_data->msgs[1].flags & I2C_M_RD) {
mv64xxx_i2c_read_offload_rx_data(drv_data, drv_data->msgs + 1);
drv_data->msgs += 2;
drv_data->num_msgs -= 2;
}
out:
writel(0, drv_data->reg_base + MV64XXX_I2C_REG_BRIDGE_CONTROL);
writel(0, drv_data->reg_base +
MV64XXX_I2C_REG_BRIDGE_INTR_CAUSE);
drv_data->block = 0;
wake_up(&drv_data->waitq);
return IRQ_HANDLED;
}
static irqreturn_t
mv64xxx_i2c_intr(int irq, void *dev_id)
{
struct mv64xxx_i2c_data *drv_data = dev_id;
unsigned long flags;
u32 status;
irqreturn_t rc = IRQ_NONE;
spin_lock_irqsave(&drv_data->lock, flags);
if (drv_data->offload_enabled)
rc = mv64xxx_i2c_intr_offload(drv_data);
while (readl(drv_data->reg_base + drv_data->reg_offsets.control) &
MV64XXX_I2C_REG_CONTROL_IFLG) {
status = readl(drv_data->reg_base + drv_data->reg_offsets.status);
mv64xxx_i2c_fsm(drv_data, status);
mv64xxx_i2c_do_action(drv_data);
if (drv_data->irq_clear_inverted)
writel(drv_data->cntl_bits | MV64XXX_I2C_REG_CONTROL_IFLG,
drv_data->reg_base + drv_data->reg_offsets.control);
rc = IRQ_HANDLED;
}
spin_unlock_irqrestore(&drv_data->lock, flags);
return rc;
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
int is_last)
{
unsigned long flags;
spin_lock_irqsave(&drv_data->lock, flags);
drv_data->state = MV64XXX_I2C_STATE_WAITING_FOR_START_COND;
drv_data->send_stop = is_last;
drv_data->block = 1;
mv64xxx_i2c_send_start(drv_data);
spin_unlock_irqrestore(&drv_data->lock, flags);
mv64xxx_i2c_wait_for_completion(drv_data);
return drv_data->rc;
}
static void
mv64xxx_i2c_prepare_tx(struct mv64xxx_i2c_data *drv_data)
{
struct i2c_msg *msg = drv_data->msgs;
u32 buf[2];
memcpy(buf, msg->buf, msg->len);
writel(buf[0], drv_data->reg_base + MV64XXX_I2C_REG_TX_DATA_LO);
writel(buf[1], drv_data->reg_base + MV64XXX_I2C_REG_TX_DATA_HI);
}
static int
mv64xxx_i2c_offload_xfer(struct mv64xxx_i2c_data *drv_data)
{
struct i2c_msg *msgs = drv_data->msgs;
int num = drv_data->num_msgs;
unsigned long ctrl_reg;
unsigned long flags;
spin_lock_irqsave(&drv_data->lock, flags);
ctrl_reg = MV64XXX_I2C_BRIDGE_CONTROL_ENABLE |
(msgs[0].addr << MV64XXX_I2C_BRIDGE_CONTROL_ADDR_SHIFT);
if (msgs[0].flags & I2C_M_TEN)
ctrl_reg |= MV64XXX_I2C_BRIDGE_CONTROL_ADDR_EXT;
if (num == 1 && !(msgs[0].flags & I2C_M_RD)) {
size_t len = msgs[0].len - 1;
ctrl_reg |= MV64XXX_I2C_BRIDGE_CONTROL_WR |
(len << MV64XXX_I2C_BRIDGE_CONTROL_TX_SIZE_SHIFT);
mv64xxx_i2c_prepare_tx(drv_data);
}
else if (num == 1 && msgs[0].flags & I2C_M_RD) {
size_t len = msgs[0].len - 1;
ctrl_reg |= MV64XXX_I2C_BRIDGE_CONTROL_RD |
(len << MV64XXX_I2C_BRIDGE_CONTROL_RX_SIZE_SHIFT);
}
else if (num == 2) {
size_t lentx = msgs[0].len - 1;
size_t lenrx = msgs[1].len - 1;
ctrl_reg |=
MV64XXX_I2C_BRIDGE_CONTROL_RD |
MV64XXX_I2C_BRIDGE_CONTROL_WR |
(lentx << MV64XXX_I2C_BRIDGE_CONTROL_TX_SIZE_SHIFT) |
(lenrx << MV64XXX_I2C_BRIDGE_CONTROL_RX_SIZE_SHIFT) |
MV64XXX_I2C_BRIDGE_CONTROL_REPEATED_START;
mv64xxx_i2c_prepare_tx(drv_data);
}
drv_data->block = 1;
writel(ctrl_reg, drv_data->reg_base + MV64XXX_I2C_REG_BRIDGE_CONTROL);
spin_unlock_irqrestore(&drv_data->lock, flags);
mv64xxx_i2c_wait_for_completion(drv_data);
return drv_data->rc;
}
static bool
mv64xxx_i2c_valid_offload_sz(struct i2c_msg *msg)
{
return msg->len <= 8 && msg->len >= 1;
}
static bool
mv64xxx_i2c_can_offload(struct mv64xxx_i2c_data *drv_data)
{
struct i2c_msg *msgs = drv_data->msgs;
int num = drv_data->num_msgs;
if (!drv_data->offload_enabled)
return false;
if (num == 1 && mv64xxx_i2c_valid_offload_sz(msgs))
return true;
if (num == 2 &&
mv64xxx_i2c_valid_offload_sz(msgs) &&
mv64xxx_i2c_valid_offload_sz(msgs + 1) &&
!(msgs[0].flags & I2C_M_RD) &&
msgs[1].flags & I2C_M_RD)
return true;
return false;
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
int rc, ret = num;
BUG_ON(drv_data->msgs != NULL);
drv_data->msgs = msgs;
drv_data->num_msgs = num;
if (mv64xxx_i2c_can_offload(drv_data))
rc = mv64xxx_i2c_offload_xfer(drv_data);
else
rc = mv64xxx_i2c_execute_msg(drv_data, &msgs[0], num == 1);
if (rc < 0)
ret = rc;
drv_data->num_msgs = 0;
drv_data->msgs = NULL;
return ret;
}
static int
mv64xxx_calc_freq(struct mv64xxx_i2c_data *drv_data,
const int tclk, const int n, const int m)
{
if (drv_data->clk_n_base_0)
return tclk / (10 * (m + 1) * (1 << n));
else
return tclk / (10 * (m + 1) * (2 << n));
}
static bool
mv64xxx_find_baud_factors(struct mv64xxx_i2c_data *drv_data,
const u32 req_freq, const u32 tclk)
{
int freq, delta, best_delta = INT_MAX;
int m, n;
for (n = 0; n <= 7; n++)
for (m = 0; m <= 15; m++) {
freq = mv64xxx_calc_freq(drv_data, tclk, n, m);
delta = req_freq - freq;
if (delta >= 0 && delta < best_delta) {
drv_data->freq_m = m;
drv_data->freq_n = n;
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
struct device *dev)
{
const struct of_device_id *device;
struct device_node *np = dev->of_node;
u32 bus_freq, tclk;
int rc = 0;
if (IS_ERR(drv_data->clk)) {
rc = -ENODEV;
goto out;
}
tclk = clk_get_rate(drv_data->clk);
if (of_property_read_u32(np, "clock-frequency", &bus_freq))
bus_freq = 100000;
if (of_device_is_compatible(np, "allwinner,sun4i-a10-i2c") ||
of_device_is_compatible(np, "allwinner,sun6i-a31-i2c"))
drv_data->clk_n_base_0 = true;
if (!mv64xxx_find_baud_factors(drv_data, bus_freq, tclk)) {
rc = -EINVAL;
goto out;
}
drv_data->rstc = devm_reset_control_get_optional(dev, NULL);
if (IS_ERR(drv_data->rstc)) {
rc = PTR_ERR(drv_data->rstc);
goto out;
}
reset_control_deassert(drv_data->rstc);
drv_data->adapter.timeout = HZ;
device = of_match_device(mv64xxx_i2c_of_match_table, dev);
if (!device)
return -ENODEV;
memcpy(&drv_data->reg_offsets, device->data, sizeof(drv_data->reg_offsets));
if (of_device_is_compatible(np, "marvell,mv78230-i2c")) {
drv_data->offload_enabled = true;
drv_data->errata_delay = true;
}
if (of_device_is_compatible(np, "marvell,mv78230-a0-i2c")) {
drv_data->offload_enabled = false;
drv_data->errata_delay = true;
}
if (of_device_is_compatible(np, "allwinner,sun6i-a31-i2c"))
drv_data->irq_clear_inverted = true;
out:
return rc;
}
static int
mv64xxx_of_config(struct mv64xxx_i2c_data *drv_data,
struct device *dev)
{
return -ENODEV;
}
static int
mv64xxx_i2c_probe(struct platform_device *pd)
{
struct mv64xxx_i2c_data *drv_data;
struct mv64xxx_i2c_pdata *pdata = dev_get_platdata(&pd->dev);
struct resource *r;
int rc;
if ((!pdata && !pd->dev.of_node))
return -ENODEV;
drv_data = devm_kzalloc(&pd->dev, sizeof(struct mv64xxx_i2c_data),
GFP_KERNEL);
if (!drv_data)
return -ENOMEM;
r = platform_get_resource(pd, IORESOURCE_MEM, 0);
drv_data->reg_base = devm_ioremap_resource(&pd->dev, r);
if (IS_ERR(drv_data->reg_base))
return PTR_ERR(drv_data->reg_base);
strlcpy(drv_data->adapter.name, MV64XXX_I2C_CTLR_NAME " adapter",
sizeof(drv_data->adapter.name));
init_waitqueue_head(&drv_data->waitq);
spin_lock_init(&drv_data->lock);
drv_data->clk = devm_clk_get(&pd->dev, NULL);
if (IS_ERR(drv_data->clk) && PTR_ERR(drv_data->clk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (!IS_ERR(drv_data->clk))
clk_prepare_enable(drv_data->clk);
drv_data->irq = platform_get_irq(pd, 0);
if (pdata) {
drv_data->freq_m = pdata->freq_m;
drv_data->freq_n = pdata->freq_n;
drv_data->adapter.timeout = msecs_to_jiffies(pdata->timeout);
drv_data->offload_enabled = false;
memcpy(&drv_data->reg_offsets, &mv64xxx_i2c_regs_mv64xxx, sizeof(drv_data->reg_offsets));
} else if (pd->dev.of_node) {
rc = mv64xxx_of_config(drv_data, &pd->dev);
if (rc)
goto exit_clk;
}
if (drv_data->irq < 0) {
rc = drv_data->irq;
goto exit_reset;
}
drv_data->adapter.dev.parent = &pd->dev;
drv_data->adapter.algo = &mv64xxx_i2c_algo;
drv_data->adapter.owner = THIS_MODULE;
drv_data->adapter.class = I2C_CLASS_DEPRECATED;
drv_data->adapter.nr = pd->id;
drv_data->adapter.dev.of_node = pd->dev.of_node;
platform_set_drvdata(pd, drv_data);
i2c_set_adapdata(&drv_data->adapter, drv_data);
mv64xxx_i2c_hw_init(drv_data);
rc = request_irq(drv_data->irq, mv64xxx_i2c_intr, 0,
MV64XXX_I2C_CTLR_NAME, drv_data);
if (rc) {
dev_err(&drv_data->adapter.dev,
"mv64xxx: Can't register intr handler irq%d: %d\n",
drv_data->irq, rc);
goto exit_reset;
} else if ((rc = i2c_add_numbered_adapter(&drv_data->adapter)) != 0) {
dev_err(&drv_data->adapter.dev,
"mv64xxx: Can't add i2c adapter, rc: %d\n", -rc);
goto exit_free_irq;
}
return 0;
exit_free_irq:
free_irq(drv_data->irq, drv_data);
exit_reset:
reset_control_assert(drv_data->rstc);
exit_clk:
if (!IS_ERR(drv_data->clk))
clk_disable_unprepare(drv_data->clk);
return rc;
}
static int
mv64xxx_i2c_remove(struct platform_device *dev)
{
struct mv64xxx_i2c_data *drv_data = platform_get_drvdata(dev);
i2c_del_adapter(&drv_data->adapter);
free_irq(drv_data->irq, drv_data);
reset_control_assert(drv_data->rstc);
if (!IS_ERR(drv_data->clk))
clk_disable_unprepare(drv_data->clk);
return 0;
}
static int mv64xxx_i2c_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct mv64xxx_i2c_data *drv_data = platform_get_drvdata(pdev);
mv64xxx_i2c_hw_init(drv_data);
return 0;
}
