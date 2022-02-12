static int aspeed_i2c_recover_bus(struct aspeed_i2c_bus *bus)
{
unsigned long time_left, flags;
int ret = 0;
u32 command;
spin_lock_irqsave(&bus->lock, flags);
command = readl(bus->base + ASPEED_I2C_CMD_REG);
if (command & ASPEED_I2CD_SDA_LINE_STS) {
if (command & ASPEED_I2CD_SCL_LINE_STS)
goto out;
dev_dbg(bus->dev, "SCL hung (state %x), attempting recovery\n",
command);
reinit_completion(&bus->cmd_complete);
writel(ASPEED_I2CD_M_STOP_CMD, bus->base + ASPEED_I2C_CMD_REG);
spin_unlock_irqrestore(&bus->lock, flags);
time_left = wait_for_completion_timeout(
&bus->cmd_complete, bus->adap.timeout);
spin_lock_irqsave(&bus->lock, flags);
if (time_left == 0)
goto reset_out;
else if (bus->cmd_err)
goto reset_out;
else if (!(readl(bus->base + ASPEED_I2C_CMD_REG) &
ASPEED_I2CD_SCL_LINE_STS))
goto reset_out;
} else {
dev_dbg(bus->dev, "SDA hung (state %x), attempting recovery\n",
command);
reinit_completion(&bus->cmd_complete);
writel(ASPEED_I2CD_BUS_RECOVER_CMD,
bus->base + ASPEED_I2C_CMD_REG);
spin_unlock_irqrestore(&bus->lock, flags);
time_left = wait_for_completion_timeout(
&bus->cmd_complete, bus->adap.timeout);
spin_lock_irqsave(&bus->lock, flags);
if (time_left == 0)
goto reset_out;
else if (bus->cmd_err)
goto reset_out;
else if (!(readl(bus->base + ASPEED_I2C_CMD_REG) &
ASPEED_I2CD_SDA_LINE_STS))
goto reset_out;
}
out:
spin_unlock_irqrestore(&bus->lock, flags);
return ret;
reset_out:
spin_unlock_irqrestore(&bus->lock, flags);
return aspeed_i2c_reset(bus);
}
static bool aspeed_i2c_slave_irq(struct aspeed_i2c_bus *bus)
{
u32 command, irq_status, status_ack = 0;
struct i2c_client *slave = bus->slave;
bool irq_handled = true;
u8 value;
spin_lock(&bus->lock);
if (!slave) {
irq_handled = false;
goto out;
}
command = readl(bus->base + ASPEED_I2C_CMD_REG);
irq_status = readl(bus->base + ASPEED_I2C_INTR_STS_REG);
if (irq_status & ASPEED_I2CD_INTR_SLAVE_MATCH) {
status_ack |= ASPEED_I2CD_INTR_SLAVE_MATCH;
bus->slave_state = ASPEED_I2C_SLAVE_START;
}
if (bus->slave_state == ASPEED_I2C_SLAVE_STOP) {
irq_handled = false;
goto out;
}
dev_dbg(bus->dev, "slave irq status 0x%08x, cmd 0x%08x\n",
irq_status, command);
if (irq_status & ASPEED_I2CD_INTR_RX_DONE) {
value = readl(bus->base + ASPEED_I2C_BYTE_BUF_REG) >> 8;
if (bus->slave_state == ASPEED_I2C_SLAVE_START) {
if (value & 0x1)
bus->slave_state =
ASPEED_I2C_SLAVE_READ_REQUESTED;
else
bus->slave_state =
ASPEED_I2C_SLAVE_WRITE_REQUESTED;
}
status_ack |= ASPEED_I2CD_INTR_RX_DONE;
}
if (irq_status & ASPEED_I2CD_INTR_NORMAL_STOP) {
status_ack |= ASPEED_I2CD_INTR_NORMAL_STOP;
bus->slave_state = ASPEED_I2C_SLAVE_STOP;
}
if (irq_status & ASPEED_I2CD_INTR_TX_NAK) {
status_ack |= ASPEED_I2CD_INTR_TX_NAK;
bus->slave_state = ASPEED_I2C_SLAVE_STOP;
}
switch (bus->slave_state) {
case ASPEED_I2C_SLAVE_READ_REQUESTED:
if (irq_status & ASPEED_I2CD_INTR_TX_ACK)
dev_err(bus->dev, "Unexpected ACK on read request.\n");
bus->slave_state = ASPEED_I2C_SLAVE_READ_PROCESSED;
i2c_slave_event(slave, I2C_SLAVE_READ_REQUESTED, &value);
writel(value, bus->base + ASPEED_I2C_BYTE_BUF_REG);
writel(ASPEED_I2CD_S_TX_CMD, bus->base + ASPEED_I2C_CMD_REG);
break;
case ASPEED_I2C_SLAVE_READ_PROCESSED:
status_ack |= ASPEED_I2CD_INTR_TX_ACK;
if (!(irq_status & ASPEED_I2CD_INTR_TX_ACK))
dev_err(bus->dev,
"Expected ACK after processed read.\n");
i2c_slave_event(slave, I2C_SLAVE_READ_PROCESSED, &value);
writel(value, bus->base + ASPEED_I2C_BYTE_BUF_REG);
writel(ASPEED_I2CD_S_TX_CMD, bus->base + ASPEED_I2C_CMD_REG);
break;
case ASPEED_I2C_SLAVE_WRITE_REQUESTED:
bus->slave_state = ASPEED_I2C_SLAVE_WRITE_RECEIVED;
i2c_slave_event(slave, I2C_SLAVE_WRITE_REQUESTED, &value);
break;
case ASPEED_I2C_SLAVE_WRITE_RECEIVED:
i2c_slave_event(slave, I2C_SLAVE_WRITE_RECEIVED, &value);
break;
case ASPEED_I2C_SLAVE_STOP:
i2c_slave_event(slave, I2C_SLAVE_STOP, &value);
break;
default:
dev_err(bus->dev, "unhandled slave_state: %d\n",
bus->slave_state);
break;
}
if (status_ack != irq_status)
dev_err(bus->dev,
"irq handled != irq. expected %x, but was %x\n",
irq_status, status_ack);
writel(status_ack, bus->base + ASPEED_I2C_INTR_STS_REG);
out:
spin_unlock(&bus->lock);
return irq_handled;
}
static void aspeed_i2c_do_start(struct aspeed_i2c_bus *bus)
{
u32 command = ASPEED_I2CD_M_START_CMD | ASPEED_I2CD_M_TX_CMD;
struct i2c_msg *msg = &bus->msgs[bus->msgs_index];
u8 slave_addr = msg->addr << 1;
bus->master_state = ASPEED_I2C_MASTER_START;
bus->buf_index = 0;
if (msg->flags & I2C_M_RD) {
slave_addr |= 1;
command |= ASPEED_I2CD_M_RX_CMD;
if (msg->len == 1 && !(msg->flags & I2C_M_RECV_LEN))
command |= ASPEED_I2CD_M_S_RX_CMD_LAST;
}
writel(slave_addr, bus->base + ASPEED_I2C_BYTE_BUF_REG);
writel(command, bus->base + ASPEED_I2C_CMD_REG);
}
static void aspeed_i2c_do_stop(struct aspeed_i2c_bus *bus)
{
bus->master_state = ASPEED_I2C_MASTER_STOP;
writel(ASPEED_I2CD_M_STOP_CMD, bus->base + ASPEED_I2C_CMD_REG);
}
static void aspeed_i2c_next_msg_or_stop(struct aspeed_i2c_bus *bus)
{
if (bus->msgs_index + 1 < bus->msgs_count) {
bus->msgs_index++;
aspeed_i2c_do_start(bus);
} else {
aspeed_i2c_do_stop(bus);
}
}
static int aspeed_i2c_is_irq_error(u32 irq_status)
{
if (irq_status & ASPEED_I2CD_INTR_ARBIT_LOSS)
return -EAGAIN;
if (irq_status & (ASPEED_I2CD_INTR_SDA_DL_TIMEOUT |
ASPEED_I2CD_INTR_SCL_TIMEOUT))
return -EBUSY;
if (irq_status & (ASPEED_I2CD_INTR_ABNORMAL))
return -EPROTO;
return 0;
}
static bool aspeed_i2c_master_irq(struct aspeed_i2c_bus *bus)
{
u32 irq_status, status_ack = 0, command = 0;
struct i2c_msg *msg;
u8 recv_byte;
int ret;
spin_lock(&bus->lock);
irq_status = readl(bus->base + ASPEED_I2C_INTR_STS_REG);
writel(irq_status, bus->base + ASPEED_I2C_INTR_STS_REG);
if (irq_status & ASPEED_I2CD_INTR_BUS_RECOVER_DONE) {
bus->master_state = ASPEED_I2C_MASTER_INACTIVE;
status_ack |= ASPEED_I2CD_INTR_BUS_RECOVER_DONE;
goto out_complete;
}
ret = aspeed_i2c_is_irq_error(irq_status);
if (ret < 0) {
dev_dbg(bus->dev, "received error interrupt: 0x%08x",
irq_status);
bus->cmd_err = ret;
bus->master_state = ASPEED_I2C_MASTER_INACTIVE;
goto out_complete;
}
if (!bus->msgs) {
dev_err(bus->dev, "bus in unknown state");
bus->cmd_err = -EIO;
if (bus->master_state != ASPEED_I2C_MASTER_STOP)
aspeed_i2c_do_stop(bus);
goto out_no_complete;
}
msg = &bus->msgs[bus->msgs_index];
if (bus->master_state == ASPEED_I2C_MASTER_START) {
if (unlikely(!(irq_status & ASPEED_I2CD_INTR_TX_ACK))) {
pr_devel("no slave present at %02x", msg->addr);
status_ack |= ASPEED_I2CD_INTR_TX_NAK;
bus->cmd_err = -ENXIO;
aspeed_i2c_do_stop(bus);
goto out_no_complete;
}
status_ack |= ASPEED_I2CD_INTR_TX_ACK;
if (msg->len == 0) {
aspeed_i2c_do_stop(bus);
goto out_no_complete;
}
if (msg->flags & I2C_M_RD)
bus->master_state = ASPEED_I2C_MASTER_RX_FIRST;
else
bus->master_state = ASPEED_I2C_MASTER_TX_FIRST;
}
switch (bus->master_state) {
case ASPEED_I2C_MASTER_TX:
if (unlikely(irq_status & ASPEED_I2CD_INTR_TX_NAK)) {
dev_dbg(bus->dev, "slave NACKed TX");
status_ack |= ASPEED_I2CD_INTR_TX_NAK;
goto error_and_stop;
} else if (unlikely(!(irq_status & ASPEED_I2CD_INTR_TX_ACK))) {
dev_err(bus->dev, "slave failed to ACK TX");
goto error_and_stop;
}
status_ack |= ASPEED_I2CD_INTR_TX_ACK;
case ASPEED_I2C_MASTER_TX_FIRST:
if (bus->buf_index < msg->len) {
bus->master_state = ASPEED_I2C_MASTER_TX;
writel(msg->buf[bus->buf_index++],
bus->base + ASPEED_I2C_BYTE_BUF_REG);
writel(ASPEED_I2CD_M_TX_CMD,
bus->base + ASPEED_I2C_CMD_REG);
} else {
aspeed_i2c_next_msg_or_stop(bus);
}
goto out_no_complete;
case ASPEED_I2C_MASTER_RX_FIRST:
if (!(irq_status & ASPEED_I2CD_INTR_RX_DONE))
goto out_no_complete;
case ASPEED_I2C_MASTER_RX:
if (unlikely(!(irq_status & ASPEED_I2CD_INTR_RX_DONE))) {
dev_err(bus->dev, "master failed to RX");
goto error_and_stop;
}
status_ack |= ASPEED_I2CD_INTR_RX_DONE;
recv_byte = readl(bus->base + ASPEED_I2C_BYTE_BUF_REG) >> 8;
msg->buf[bus->buf_index++] = recv_byte;
if (msg->flags & I2C_M_RECV_LEN) {
if (unlikely(recv_byte > I2C_SMBUS_BLOCK_MAX)) {
bus->cmd_err = -EPROTO;
aspeed_i2c_do_stop(bus);
goto out_no_complete;
}
msg->len = recv_byte +
((msg->flags & I2C_CLIENT_PEC) ? 2 : 1);
msg->flags &= ~I2C_M_RECV_LEN;
}
if (bus->buf_index < msg->len) {
bus->master_state = ASPEED_I2C_MASTER_RX;
command = ASPEED_I2CD_M_RX_CMD;
if (bus->buf_index + 1 == msg->len)
command |= ASPEED_I2CD_M_S_RX_CMD_LAST;
writel(command, bus->base + ASPEED_I2C_CMD_REG);
} else {
aspeed_i2c_next_msg_or_stop(bus);
}
goto out_no_complete;
case ASPEED_I2C_MASTER_STOP:
if (unlikely(!(irq_status & ASPEED_I2CD_INTR_NORMAL_STOP))) {
dev_err(bus->dev, "master failed to STOP");
bus->cmd_err = -EIO;
} else {
status_ack |= ASPEED_I2CD_INTR_NORMAL_STOP;
}
bus->master_state = ASPEED_I2C_MASTER_INACTIVE;
goto out_complete;
case ASPEED_I2C_MASTER_INACTIVE:
dev_err(bus->dev,
"master received interrupt 0x%08x, but is inactive",
irq_status);
bus->cmd_err = -EIO;
goto out_complete;
default:
WARN(1, "unknown master state\n");
bus->master_state = ASPEED_I2C_MASTER_INACTIVE;
bus->cmd_err = -EINVAL;
goto out_complete;
}
error_and_stop:
bus->cmd_err = -EIO;
aspeed_i2c_do_stop(bus);
goto out_no_complete;
out_complete:
bus->msgs = NULL;
if (bus->cmd_err)
bus->master_xfer_result = bus->cmd_err;
else
bus->master_xfer_result = bus->msgs_index + 1;
complete(&bus->cmd_complete);
out_no_complete:
if (irq_status != status_ack)
dev_err(bus->dev,
"irq handled != irq. expected 0x%08x, but was 0x%08x\n",
irq_status, status_ack);
spin_unlock(&bus->lock);
return !!irq_status;
}
static irqreturn_t aspeed_i2c_bus_irq(int irq, void *dev_id)
{
struct aspeed_i2c_bus *bus = dev_id;
#if IS_ENABLED(CONFIG_I2C_SLAVE)
if (aspeed_i2c_slave_irq(bus)) {
dev_dbg(bus->dev, "irq handled by slave.\n");
return IRQ_HANDLED;
}
#endif
return aspeed_i2c_master_irq(bus) ? IRQ_HANDLED : IRQ_NONE;
}
static int aspeed_i2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct aspeed_i2c_bus *bus = i2c_get_adapdata(adap);
unsigned long time_left, flags;
int ret = 0;
spin_lock_irqsave(&bus->lock, flags);
bus->cmd_err = 0;
if (readl(bus->base + ASPEED_I2C_CMD_REG) & ASPEED_I2CD_BUS_BUSY_STS) {
spin_unlock_irqrestore(&bus->lock, flags);
ret = aspeed_i2c_recover_bus(bus);
if (ret)
return ret;
spin_lock_irqsave(&bus->lock, flags);
}
bus->cmd_err = 0;
bus->msgs = msgs;
bus->msgs_index = 0;
bus->msgs_count = num;
reinit_completion(&bus->cmd_complete);
aspeed_i2c_do_start(bus);
spin_unlock_irqrestore(&bus->lock, flags);
time_left = wait_for_completion_timeout(&bus->cmd_complete,
bus->adap.timeout);
if (time_left == 0)
return -ETIMEDOUT;
else
return bus->master_xfer_result;
}
static u32 aspeed_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_SMBUS_BLOCK_DATA;
}
static void __aspeed_i2c_reg_slave(struct aspeed_i2c_bus *bus, u16 slave_addr)
{
u32 addr_reg_val, func_ctrl_reg_val;
addr_reg_val = readl(bus->base + ASPEED_I2C_DEV_ADDR_REG);
addr_reg_val &= ~ASPEED_I2CD_DEV_ADDR_MASK;
addr_reg_val |= slave_addr & ASPEED_I2CD_DEV_ADDR_MASK;
writel(addr_reg_val, bus->base + ASPEED_I2C_DEV_ADDR_REG);
func_ctrl_reg_val = readl(bus->base + ASPEED_I2C_FUN_CTRL_REG);
func_ctrl_reg_val |= ASPEED_I2CD_SLAVE_EN;
writel(func_ctrl_reg_val, bus->base + ASPEED_I2C_FUN_CTRL_REG);
}
static int aspeed_i2c_reg_slave(struct i2c_client *client)
{
struct aspeed_i2c_bus *bus = i2c_get_adapdata(client->adapter);
unsigned long flags;
spin_lock_irqsave(&bus->lock, flags);
if (bus->slave) {
spin_unlock_irqrestore(&bus->lock, flags);
return -EINVAL;
}
__aspeed_i2c_reg_slave(bus, client->addr);
bus->slave = client;
bus->slave_state = ASPEED_I2C_SLAVE_STOP;
spin_unlock_irqrestore(&bus->lock, flags);
return 0;
}
static int aspeed_i2c_unreg_slave(struct i2c_client *client)
{
struct aspeed_i2c_bus *bus = i2c_get_adapdata(client->adapter);
u32 func_ctrl_reg_val;
unsigned long flags;
spin_lock_irqsave(&bus->lock, flags);
if (!bus->slave) {
spin_unlock_irqrestore(&bus->lock, flags);
return -EINVAL;
}
func_ctrl_reg_val = readl(bus->base + ASPEED_I2C_FUN_CTRL_REG);
func_ctrl_reg_val &= ~ASPEED_I2CD_SLAVE_EN;
writel(func_ctrl_reg_val, bus->base + ASPEED_I2C_FUN_CTRL_REG);
bus->slave = NULL;
spin_unlock_irqrestore(&bus->lock, flags);
return 0;
}
static u32 aspeed_i2c_get_clk_reg_val(u32 divisor)
{
u32 base_clk, clk_high, clk_low, tmp;
base_clk = divisor > 33 ? ilog2((divisor - 1) / 32) + 1 : 0;
tmp = divisor / (1 << base_clk);
clk_high = tmp / 2 + tmp % 2;
clk_low = tmp - clk_high;
clk_high -= 1;
clk_low -= 1;
return ((clk_high << ASPEED_I2CD_TIME_SCL_HIGH_SHIFT)
& ASPEED_I2CD_TIME_SCL_HIGH_MASK)
| ((clk_low << ASPEED_I2CD_TIME_SCL_LOW_SHIFT)
& ASPEED_I2CD_TIME_SCL_LOW_MASK)
| (base_clk & ASPEED_I2CD_TIME_BASE_DIVISOR_MASK);
}
static int aspeed_i2c_init_clk(struct aspeed_i2c_bus *bus)
{
u32 divisor, clk_reg_val;
divisor = bus->parent_clk_frequency / bus->bus_frequency;
clk_reg_val = aspeed_i2c_get_clk_reg_val(divisor);
writel(clk_reg_val, bus->base + ASPEED_I2C_AC_TIMING_REG1);
writel(ASPEED_NO_TIMEOUT_CTRL, bus->base + ASPEED_I2C_AC_TIMING_REG2);
return 0;
}
static int aspeed_i2c_init(struct aspeed_i2c_bus *bus,
struct platform_device *pdev)
{
u32 fun_ctrl_reg = ASPEED_I2CD_MASTER_EN;
int ret;
writel(0, bus->base + ASPEED_I2C_FUN_CTRL_REG);
ret = aspeed_i2c_init_clk(bus);
if (ret < 0)
return ret;
if (!of_property_read_bool(pdev->dev.of_node, "multi-master"))
fun_ctrl_reg |= ASPEED_I2CD_MULTI_MASTER_DIS;
writel(readl(bus->base + ASPEED_I2C_FUN_CTRL_REG) | fun_ctrl_reg,
bus->base + ASPEED_I2C_FUN_CTRL_REG);
#if IS_ENABLED(CONFIG_I2C_SLAVE)
if (bus->slave)
__aspeed_i2c_reg_slave(bus, bus->slave->addr);
#endif
writel(ASPEED_I2CD_INTR_ALL, bus->base + ASPEED_I2C_INTR_CTRL_REG);
return 0;
}
static int aspeed_i2c_reset(struct aspeed_i2c_bus *bus)
{
struct platform_device *pdev = to_platform_device(bus->dev);
unsigned long flags;
int ret;
spin_lock_irqsave(&bus->lock, flags);
writel(0, bus->base + ASPEED_I2C_INTR_CTRL_REG);
writel(0xffffffff, bus->base + ASPEED_I2C_INTR_STS_REG);
ret = aspeed_i2c_init(bus, pdev);
spin_unlock_irqrestore(&bus->lock, flags);
return ret;
}
static int aspeed_i2c_probe_bus(struct platform_device *pdev)
{
struct aspeed_i2c_bus *bus;
struct clk *parent_clk;
struct resource *res;
int irq, ret;
bus = devm_kzalloc(&pdev->dev, sizeof(*bus), GFP_KERNEL);
if (!bus)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bus->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(bus->base))
return PTR_ERR(bus->base);
parent_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(parent_clk))
return PTR_ERR(parent_clk);
bus->parent_clk_frequency = clk_get_rate(parent_clk);
devm_clk_put(&pdev->dev, parent_clk);
ret = of_property_read_u32(pdev->dev.of_node,
"bus-frequency", &bus->bus_frequency);
if (ret < 0) {
dev_err(&pdev->dev,
"Could not read bus-frequency property\n");
bus->bus_frequency = 100000;
}
spin_lock_init(&bus->lock);
init_completion(&bus->cmd_complete);
bus->adap.owner = THIS_MODULE;
bus->adap.retries = 0;
bus->adap.timeout = 5 * HZ;
bus->adap.algo = &aspeed_i2c_algo;
bus->adap.dev.parent = &pdev->dev;
bus->adap.dev.of_node = pdev->dev.of_node;
strlcpy(bus->adap.name, pdev->name, sizeof(bus->adap.name));
i2c_set_adapdata(&bus->adap, bus);
bus->dev = &pdev->dev;
writel(0, bus->base + ASPEED_I2C_INTR_CTRL_REG);
writel(0xffffffff, bus->base + ASPEED_I2C_INTR_STS_REG);
ret = aspeed_i2c_init(bus, pdev);
if (ret < 0)
return ret;
irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
ret = devm_request_irq(&pdev->dev, irq, aspeed_i2c_bus_irq,
0, dev_name(&pdev->dev), bus);
if (ret < 0)
return ret;
ret = i2c_add_adapter(&bus->adap);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, bus);
dev_info(bus->dev, "i2c bus %d registered, irq %d\n",
bus->adap.nr, irq);
return 0;
}
static int aspeed_i2c_remove_bus(struct platform_device *pdev)
{
struct aspeed_i2c_bus *bus = platform_get_drvdata(pdev);
unsigned long flags;
spin_lock_irqsave(&bus->lock, flags);
writel(0, bus->base + ASPEED_I2C_FUN_CTRL_REG);
writel(0, bus->base + ASPEED_I2C_INTR_CTRL_REG);
spin_unlock_irqrestore(&bus->lock, flags);
i2c_del_adapter(&bus->adap);
return 0;
}
