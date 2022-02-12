static inline u32 pmcmsptwi_clock_to_reg(
const struct pmcmsptwi_clock *clock)
{
return ((clock->filter & 0xf) << 12) | (clock->clock & 0x03ff);
}
static inline u32 pmcmsptwi_cfg_to_reg(const struct pmcmsptwi_cfg *cfg)
{
return ((cfg->arbf & 0xf) << 12) |
((cfg->nak & 0xf) << 8) |
((cfg->add10 & 0x1) << 7) |
((cfg->mst_code & 0x7) << 4) |
((cfg->arb & 0x1) << 1) |
(cfg->highspeed & 0x1);
}
static inline void pmcmsptwi_reg_to_cfg(u32 reg, struct pmcmsptwi_cfg *cfg)
{
cfg->arbf = (reg >> 12) & 0xf;
cfg->nak = (reg >> 8) & 0xf;
cfg->add10 = (reg >> 7) & 0x1;
cfg->mst_code = (reg >> 4) & 0x7;
cfg->arb = (reg >> 1) & 0x1;
cfg->highspeed = reg & 0x1;
}
static void pmcmsptwi_set_clock_config(const struct pmcmsptwi_clockcfg *cfg,
struct pmcmsptwi_data *data)
{
mutex_lock(&data->lock);
pmcmsptwi_writel(pmcmsptwi_clock_to_reg(&cfg->standard),
data->iobase + MSP_TWI_SF_CLK_REG_OFFSET);
pmcmsptwi_writel(pmcmsptwi_clock_to_reg(&cfg->highspeed),
data->iobase + MSP_TWI_HS_CLK_REG_OFFSET);
mutex_unlock(&data->lock);
}
static void pmcmsptwi_get_twi_config(struct pmcmsptwi_cfg *cfg,
struct pmcmsptwi_data *data)
{
mutex_lock(&data->lock);
pmcmsptwi_reg_to_cfg(pmcmsptwi_readl(
data->iobase + MSP_TWI_CFG_REG_OFFSET), cfg);
mutex_unlock(&data->lock);
}
static void pmcmsptwi_set_twi_config(const struct pmcmsptwi_cfg *cfg,
struct pmcmsptwi_data *data)
{
mutex_lock(&data->lock);
pmcmsptwi_writel(pmcmsptwi_cfg_to_reg(cfg),
data->iobase + MSP_TWI_CFG_REG_OFFSET);
mutex_unlock(&data->lock);
}
static enum pmcmsptwi_xfer_result pmcmsptwi_get_result(u32 reg)
{
if (reg & MSP_TWI_INT_STS_LOST_ARBITRATION) {
dev_dbg(&pmcmsptwi_adapter.dev,
"Result: Lost arbitration\n");
return MSP_TWI_XFER_LOST_ARBITRATION;
} else if (reg & MSP_TWI_INT_STS_NO_RESPONSE) {
dev_dbg(&pmcmsptwi_adapter.dev,
"Result: No response\n");
return MSP_TWI_XFER_NO_RESPONSE;
} else if (reg & MSP_TWI_INT_STS_DATA_COLLISION) {
dev_dbg(&pmcmsptwi_adapter.dev,
"Result: Data collision\n");
return MSP_TWI_XFER_DATA_COLLISION;
} else if (reg & MSP_TWI_INT_STS_BUSY) {
dev_dbg(&pmcmsptwi_adapter.dev,
"Result: Bus busy\n");
return MSP_TWI_XFER_BUSY;
}
dev_dbg(&pmcmsptwi_adapter.dev, "Result: Operation succeeded\n");
return MSP_TWI_XFER_OK;
}
static irqreturn_t pmcmsptwi_interrupt(int irq, void *ptr)
{
struct pmcmsptwi_data *data = ptr;
u32 reason = pmcmsptwi_readl(data->iobase +
MSP_TWI_INT_STS_REG_OFFSET);
pmcmsptwi_writel(reason, data->iobase + MSP_TWI_INT_STS_REG_OFFSET);
dev_dbg(&pmcmsptwi_adapter.dev, "Got interrupt 0x%08x\n", reason);
if (!(reason & MSP_TWI_INT_STS_DONE))
return IRQ_NONE;
data->last_result = pmcmsptwi_get_result(reason);
complete(&data->wait);
return IRQ_HANDLED;
}
static int pmcmsptwi_probe(struct platform_device *pldev)
{
struct resource *res;
int rc = -ENODEV;
res = platform_get_resource(pldev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pldev->dev, "IOMEM resource not found\n");
goto ret_err;
}
if (!request_mem_region(res->start, resource_size(res),
pldev->name)) {
dev_err(&pldev->dev,
"Unable to get memory/io address region 0x%08x\n",
res->start);
rc = -EBUSY;
goto ret_err;
}
pmcmsptwi_data.iobase = ioremap_nocache(res->start,
resource_size(res));
if (!pmcmsptwi_data.iobase) {
dev_err(&pldev->dev,
"Unable to ioremap address 0x%08x\n", res->start);
rc = -EIO;
goto ret_unreserve;
}
pmcmsptwi_data.irq = platform_get_irq(pldev, 0);
if (pmcmsptwi_data.irq) {
rc = request_irq(pmcmsptwi_data.irq, &pmcmsptwi_interrupt,
IRQF_SHARED, pldev->name, &pmcmsptwi_data);
if (rc == 0) {
pmcmsptwi_writel(MSP_TWI_INT_STS_DONE,
pmcmsptwi_data.iobase +
MSP_TWI_INT_MSK_REG_OFFSET);
} else {
dev_warn(&pldev->dev,
"Could not assign TWI IRQ handler "
"to irq %d (continuing with poll)\n",
pmcmsptwi_data.irq);
pmcmsptwi_data.irq = 0;
}
}
init_completion(&pmcmsptwi_data.wait);
mutex_init(&pmcmsptwi_data.lock);
pmcmsptwi_set_clock_config(&pmcmsptwi_defclockcfg, &pmcmsptwi_data);
pmcmsptwi_set_twi_config(&pmcmsptwi_defcfg, &pmcmsptwi_data);
printk(KERN_INFO DRV_NAME ": Registering MSP71xx I2C adapter\n");
pmcmsptwi_adapter.dev.parent = &pldev->dev;
platform_set_drvdata(pldev, &pmcmsptwi_adapter);
i2c_set_adapdata(&pmcmsptwi_adapter, &pmcmsptwi_data);
rc = i2c_add_adapter(&pmcmsptwi_adapter);
if (rc) {
dev_err(&pldev->dev, "Unable to register I2C adapter\n");
goto ret_unmap;
}
return 0;
ret_unmap:
if (pmcmsptwi_data.irq) {
pmcmsptwi_writel(0,
pmcmsptwi_data.iobase + MSP_TWI_INT_MSK_REG_OFFSET);
free_irq(pmcmsptwi_data.irq, &pmcmsptwi_data);
}
iounmap(pmcmsptwi_data.iobase);
ret_unreserve:
release_mem_region(res->start, resource_size(res));
ret_err:
return rc;
}
static int pmcmsptwi_remove(struct platform_device *pldev)
{
struct resource *res;
i2c_del_adapter(&pmcmsptwi_adapter);
if (pmcmsptwi_data.irq) {
pmcmsptwi_writel(0,
pmcmsptwi_data.iobase + MSP_TWI_INT_MSK_REG_OFFSET);
free_irq(pmcmsptwi_data.irq, &pmcmsptwi_data);
}
iounmap(pmcmsptwi_data.iobase);
res = platform_get_resource(pldev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
return 0;
}
static void pmcmsptwi_poll_complete(struct pmcmsptwi_data *data)
{
int i;
for (i = 0; i < MSP_MAX_POLL; i++) {
u32 val = pmcmsptwi_readl(data->iobase +
MSP_TWI_BUSY_REG_OFFSET);
if (val == 0) {
u32 reason = pmcmsptwi_readl(data->iobase +
MSP_TWI_INT_STS_REG_OFFSET);
pmcmsptwi_writel(reason, data->iobase +
MSP_TWI_INT_STS_REG_OFFSET);
data->last_result = pmcmsptwi_get_result(reason);
return;
}
udelay(MSP_POLL_DELAY);
}
dev_dbg(&pmcmsptwi_adapter.dev, "Result: Poll timeout\n");
data->last_result = MSP_TWI_XFER_TIMEOUT;
}
static enum pmcmsptwi_xfer_result pmcmsptwi_do_xfer(
u32 reg, struct pmcmsptwi_data *data)
{
dev_dbg(&pmcmsptwi_adapter.dev, "Writing cmd reg 0x%08x\n", reg);
pmcmsptwi_writel(reg, data->iobase + MSP_TWI_CMD_REG_OFFSET);
if (data->irq) {
unsigned long timeleft = wait_for_completion_timeout(
&data->wait, MSP_IRQ_TIMEOUT);
if (timeleft == 0) {
dev_dbg(&pmcmsptwi_adapter.dev,
"Result: IRQ timeout\n");
complete(&data->wait);
data->last_result = MSP_TWI_XFER_TIMEOUT;
}
} else
pmcmsptwi_poll_complete(data);
return data->last_result;
}
static inline u32 pmcmsptwi_cmd_to_reg(const struct pmcmsptwi_cmd *cmd)
{
return ((cmd->type & 0x3) << 8) |
(((cmd->write_len - 1) & 0x7) << 4) |
((cmd->read_len - 1) & 0x7);
}
static enum pmcmsptwi_xfer_result pmcmsptwi_xfer_cmd(
struct pmcmsptwi_cmd *cmd,
struct pmcmsptwi_data *data)
{
enum pmcmsptwi_xfer_result retval;
if ((cmd->type == MSP_TWI_CMD_WRITE && cmd->write_len == 0) ||
(cmd->type == MSP_TWI_CMD_READ && cmd->read_len == 0) ||
(cmd->type == MSP_TWI_CMD_WRITE_READ &&
(cmd->read_len == 0 || cmd->write_len == 0))) {
dev_err(&pmcmsptwi_adapter.dev,
"%s: Cannot transfer less than 1 byte\n",
__func__);
return -EINVAL;
}
if (cmd->read_len > MSP_MAX_BYTES_PER_RW ||
cmd->write_len > MSP_MAX_BYTES_PER_RW) {
dev_err(&pmcmsptwi_adapter.dev,
"%s: Cannot transfer more than %d bytes\n",
__func__, MSP_MAX_BYTES_PER_RW);
return -EINVAL;
}
mutex_lock(&data->lock);
dev_dbg(&pmcmsptwi_adapter.dev,
"Setting address to 0x%04x\n", cmd->addr);
pmcmsptwi_writel(cmd->addr, data->iobase + MSP_TWI_ADD_REG_OFFSET);
if (cmd->type == MSP_TWI_CMD_WRITE ||
cmd->type == MSP_TWI_CMD_WRITE_READ) {
u64 tmp = be64_to_cpup((__be64 *)cmd->write_data);
tmp >>= (MSP_MAX_BYTES_PER_RW - cmd->write_len) * 8;
dev_dbg(&pmcmsptwi_adapter.dev, "Writing 0x%016llx\n", tmp);
pmcmsptwi_writel(tmp & 0x00000000ffffffffLL,
data->iobase + MSP_TWI_DAT_0_REG_OFFSET);
if (cmd->write_len > 4)
pmcmsptwi_writel(tmp >> 32,
data->iobase + MSP_TWI_DAT_1_REG_OFFSET);
}
retval = pmcmsptwi_do_xfer(pmcmsptwi_cmd_to_reg(cmd), data);
if (retval != MSP_TWI_XFER_OK)
goto xfer_err;
if (cmd->type == MSP_TWI_CMD_READ ||
cmd->type == MSP_TWI_CMD_WRITE_READ) {
int i;
u64 rmsk = ~(0xffffffffffffffffLL << (cmd->read_len * 8));
u64 tmp = (u64)pmcmsptwi_readl(data->iobase +
MSP_TWI_DAT_0_REG_OFFSET);
if (cmd->read_len > 4)
tmp |= (u64)pmcmsptwi_readl(data->iobase +
MSP_TWI_DAT_1_REG_OFFSET) << 32;
tmp &= rmsk;
dev_dbg(&pmcmsptwi_adapter.dev, "Read 0x%016llx\n", tmp);
for (i = 0; i < cmd->read_len; i++)
cmd->read_data[i] = tmp >> i;
}
xfer_err:
mutex_unlock(&data->lock);
return retval;
}
static int pmcmsptwi_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msg, int num)
{
struct pmcmsptwi_data *data = i2c_get_adapdata(adap);
struct pmcmsptwi_cmd cmd;
struct pmcmsptwi_cfg oldcfg, newcfg;
int ret;
if (num > 2) {
dev_dbg(&adap->dev, "%d messages unsupported\n", num);
return -EINVAL;
} else if (num == 2) {
struct i2c_msg *nextmsg = msg + 1;
if (!(msg->flags & I2C_M_RD) &&
(nextmsg->flags & I2C_M_RD) &&
msg->addr == nextmsg->addr) {
cmd.type = MSP_TWI_CMD_WRITE_READ;
cmd.write_len = msg->len;
cmd.write_data = msg->buf;
cmd.read_len = nextmsg->len;
cmd.read_data = nextmsg->buf;
} else {
dev_dbg(&adap->dev,
"Non write-read dual messages unsupported\n");
return -EINVAL;
}
} else if (msg->flags & I2C_M_RD) {
cmd.type = MSP_TWI_CMD_READ;
cmd.read_len = msg->len;
cmd.read_data = msg->buf;
cmd.write_len = 0;
cmd.write_data = NULL;
} else {
cmd.type = MSP_TWI_CMD_WRITE;
cmd.read_len = 0;
cmd.read_data = NULL;
cmd.write_len = msg->len;
cmd.write_data = msg->buf;
}
if (msg->len == 0) {
dev_err(&adap->dev, "Zero-byte messages unsupported\n");
return -EINVAL;
}
cmd.addr = msg->addr;
if (msg->flags & I2C_M_TEN) {
pmcmsptwi_get_twi_config(&newcfg, data);
memcpy(&oldcfg, &newcfg, sizeof(oldcfg));
newcfg.add10 = 1;
pmcmsptwi_set_twi_config(&newcfg, data);
}
ret = pmcmsptwi_xfer_cmd(&cmd, data);
if (msg->flags & I2C_M_TEN)
pmcmsptwi_set_twi_config(&oldcfg, data);
dev_dbg(&adap->dev, "I2C %s of %d bytes %s\n",
(msg->flags & I2C_M_RD) ? "read" : "write", msg->len,
(ret == MSP_TWI_XFER_OK) ? "succeeded" : "failed");
if (ret != MSP_TWI_XFER_OK) {
return -1;
}
return 0;
}
static u32 pmcmsptwi_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR |
I2C_FUNC_SMBUS_BYTE | I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA | I2C_FUNC_SMBUS_PROC_CALL;
}
