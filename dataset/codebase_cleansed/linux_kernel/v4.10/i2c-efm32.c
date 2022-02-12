static u32 efm32_i2c_read32(struct efm32_i2c_ddata *ddata, unsigned offset)
{
return readl(ddata->base + offset);
}
static void efm32_i2c_write32(struct efm32_i2c_ddata *ddata,
unsigned offset, u32 value)
{
writel(value, ddata->base + offset);
}
static void efm32_i2c_send_next_msg(struct efm32_i2c_ddata *ddata)
{
struct i2c_msg *cur_msg = &ddata->msgs[ddata->current_msg];
efm32_i2c_write32(ddata, REG_CMD, REG_CMD_START);
efm32_i2c_write32(ddata, REG_TXDATA, cur_msg->addr << 1 |
(cur_msg->flags & I2C_M_RD ? 1 : 0));
}
static void efm32_i2c_send_next_byte(struct efm32_i2c_ddata *ddata)
{
struct i2c_msg *cur_msg = &ddata->msgs[ddata->current_msg];
if (ddata->current_word >= cur_msg->len) {
ddata->current_word = 0;
ddata->current_msg += 1;
if (ddata->current_msg >= ddata->num_msgs) {
efm32_i2c_write32(ddata, REG_CMD, REG_CMD_STOP);
complete(&ddata->done);
} else {
efm32_i2c_send_next_msg(ddata);
}
} else {
efm32_i2c_write32(ddata, REG_TXDATA,
cur_msg->buf[ddata->current_word++]);
}
}
static void efm32_i2c_recv_next_byte(struct efm32_i2c_ddata *ddata)
{
struct i2c_msg *cur_msg = &ddata->msgs[ddata->current_msg];
cur_msg->buf[ddata->current_word] = efm32_i2c_read32(ddata, REG_RXDATA);
ddata->current_word += 1;
if (ddata->current_word >= cur_msg->len) {
ddata->current_word = 0;
ddata->current_msg += 1;
efm32_i2c_write32(ddata, REG_CMD, REG_CMD_NACK);
if (ddata->current_msg >= ddata->num_msgs) {
efm32_i2c_write32(ddata, REG_CMD, REG_CMD_STOP);
complete(&ddata->done);
} else {
efm32_i2c_send_next_msg(ddata);
}
} else {
efm32_i2c_write32(ddata, REG_CMD, REG_CMD_ACK);
}
}
static irqreturn_t efm32_i2c_irq(int irq, void *dev_id)
{
struct efm32_i2c_ddata *ddata = dev_id;
struct i2c_msg *cur_msg = &ddata->msgs[ddata->current_msg];
u32 irqflag = efm32_i2c_read32(ddata, REG_IF);
u32 state = efm32_i2c_read32(ddata, REG_STATE);
efm32_i2c_write32(ddata, REG_IFC, irqflag & REG_IFC__MASK);
switch (state & REG_STATE_STATE__MASK) {
case REG_STATE_STATE_IDLE:
ddata->retval = -EAGAIN;
complete(&ddata->done);
break;
case REG_STATE_STATE_WAIT:
ddata->retval = -EIO;
efm32_i2c_write32(ddata, REG_CMD,
REG_CMD_STOP | REG_CMD_ABORT |
REG_CMD_CLEARTX | REG_CMD_CLEARPC);
complete(&ddata->done);
break;
case REG_STATE_STATE_START:
break;
case REG_STATE_STATE_ADDR:
break;
case REG_STATE_STATE_ADDRACK:
if (state & REG_STATE_NACKED) {
efm32_i2c_write32(ddata, REG_CMD, REG_CMD_STOP);
ddata->retval = -ENXIO;
complete(&ddata->done);
} else if (cur_msg->flags & I2C_M_RD) {
} else {
efm32_i2c_send_next_byte(ddata);
}
break;
case REG_STATE_STATE_DATA:
if (cur_msg->flags & I2C_M_RD) {
efm32_i2c_recv_next_byte(ddata);
} else {
}
break;
case REG_STATE_STATE_DATAACK:
if (state & REG_STATE_NACKED) {
efm32_i2c_write32(ddata, REG_CMD, REG_CMD_STOP);
complete(&ddata->done);
} else {
efm32_i2c_send_next_byte(ddata);
}
}
return IRQ_HANDLED;
}
static int efm32_i2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct efm32_i2c_ddata *ddata = i2c_get_adapdata(adap);
int ret;
if (ddata->msgs)
return -EBUSY;
ddata->msgs = msgs;
ddata->num_msgs = num;
ddata->current_word = 0;
ddata->current_msg = 0;
ddata->retval = -EIO;
reinit_completion(&ddata->done);
dev_dbg(&ddata->adapter.dev, "state: %08x, status: %08x\n",
efm32_i2c_read32(ddata, REG_STATE),
efm32_i2c_read32(ddata, REG_STATUS));
efm32_i2c_send_next_msg(ddata);
wait_for_completion(&ddata->done);
if (ddata->current_msg >= ddata->num_msgs)
ret = ddata->num_msgs;
else
ret = ddata->retval;
return ret;
}
static u32 efm32_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static u32 efm32_i2c_get_configured_location(struct efm32_i2c_ddata *ddata)
{
u32 reg = efm32_i2c_read32(ddata, REG_ROUTE);
return (reg & REG_ROUTE_LOCATION__MASK) >>
__ffs(REG_ROUTE_LOCATION__MASK);
}
static int efm32_i2c_probe(struct platform_device *pdev)
{
struct efm32_i2c_ddata *ddata;
struct resource *res;
unsigned long rate;
struct device_node *np = pdev->dev.of_node;
u32 location, frequency;
int ret;
u32 clkdiv;
if (!np)
return -EINVAL;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
platform_set_drvdata(pdev, ddata);
init_completion(&ddata->done);
strlcpy(ddata->adapter.name, pdev->name, sizeof(ddata->adapter.name));
ddata->adapter.owner = THIS_MODULE;
ddata->adapter.algo = &efm32_i2c_algo;
ddata->adapter.dev.parent = &pdev->dev;
ddata->adapter.dev.of_node = pdev->dev.of_node;
i2c_set_adapdata(&ddata->adapter, ddata);
ddata->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(ddata->clk)) {
ret = PTR_ERR(ddata->clk);
dev_err(&pdev->dev, "failed to get clock: %d\n", ret);
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to determine base address\n");
return -ENODEV;
}
if (resource_size(res) < 0x42) {
dev_err(&pdev->dev, "memory resource too small\n");
return -EINVAL;
}
ddata->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ddata->base))
return PTR_ERR(ddata->base);
ret = platform_get_irq(pdev, 0);
if (ret <= 0) {
dev_err(&pdev->dev, "failed to get irq (%d)\n", ret);
if (!ret)
ret = -EINVAL;
return ret;
}
ddata->irq = ret;
ret = clk_prepare_enable(ddata->clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable clock (%d)\n", ret);
return ret;
}
ret = of_property_read_u32(np, "energymicro,location", &location);
if (ret)
ret = of_property_read_u32(np, "efm32,location", &location);
if (!ret) {
dev_dbg(&pdev->dev, "using location %u\n", location);
} else {
location = efm32_i2c_get_configured_location(ddata);
dev_info(&pdev->dev, "fall back to location %u\n", location);
}
ddata->location = location;
ret = of_property_read_u32(np, "clock-frequency", &frequency);
if (!ret) {
dev_dbg(&pdev->dev, "using frequency %u\n", frequency);
} else {
frequency = 100000;
dev_info(&pdev->dev, "defaulting to 100 kHz\n");
}
ddata->frequency = frequency;
rate = clk_get_rate(ddata->clk);
if (!rate) {
dev_err(&pdev->dev, "there is no input clock available\n");
ret = -EINVAL;
goto err_disable_clk;
}
clkdiv = DIV_ROUND_UP(rate, 8 * ddata->frequency) - 1;
if (clkdiv >= 0x200) {
dev_err(&pdev->dev,
"input clock too fast (%lu) to divide down to bus freq (%lu)",
rate, ddata->frequency);
ret = -EINVAL;
goto err_disable_clk;
}
dev_dbg(&pdev->dev, "input clock = %lu, bus freq = %lu, clkdiv = %lu\n",
rate, ddata->frequency, (unsigned long)clkdiv);
efm32_i2c_write32(ddata, REG_CLKDIV, REG_CLKDIV_DIV(clkdiv));
efm32_i2c_write32(ddata, REG_ROUTE, REG_ROUTE_SDAPEN |
REG_ROUTE_SCLPEN |
REG_ROUTE_LOCATION(ddata->location));
efm32_i2c_write32(ddata, REG_CTRL, REG_CTRL_EN |
REG_CTRL_BITO_160PCC | 0 * REG_CTRL_GIBITO);
efm32_i2c_write32(ddata, REG_IFC, REG_IFC__MASK);
efm32_i2c_write32(ddata, REG_IEN, REG_IF_TXC | REG_IF_ACK | REG_IF_NACK
| REG_IF_ARBLOST | REG_IF_BUSERR | REG_IF_RXDATAV);
efm32_i2c_write32(ddata, REG_CMD, REG_CMD_ABORT);
ret = request_irq(ddata->irq, efm32_i2c_irq, 0, DRIVER_NAME, ddata);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request irq (%d)\n", ret);
goto err_disable_clk;
}
ret = i2c_add_adapter(&ddata->adapter);
if (ret) {
free_irq(ddata->irq, ddata);
err_disable_clk:
clk_disable_unprepare(ddata->clk);
}
return ret;
}
static int efm32_i2c_remove(struct platform_device *pdev)
{
struct efm32_i2c_ddata *ddata = platform_get_drvdata(pdev);
i2c_del_adapter(&ddata->adapter);
free_irq(ddata->irq, ddata);
clk_disable_unprepare(ddata->clk);
return 0;
}
