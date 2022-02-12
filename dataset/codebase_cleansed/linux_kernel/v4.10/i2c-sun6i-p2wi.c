static irqreturn_t p2wi_interrupt(int irq, void *dev_id)
{
struct p2wi *p2wi = dev_id;
unsigned long status;
status = readl(p2wi->regs + P2WI_INTS);
p2wi->status = status;
status &= (P2WI_INTS_LOAD_BSY | P2WI_INTS_TRANS_ERR |
P2WI_INTS_TRANS_OVER);
writel(status, p2wi->regs + P2WI_INTS);
complete(&p2wi->complete);
return IRQ_HANDLED;
}
static u32 p2wi_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_BYTE_DATA;
}
static int p2wi_smbus_xfer(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size, union i2c_smbus_data *data)
{
struct p2wi *p2wi = i2c_get_adapdata(adap);
unsigned long dlen = P2WI_DLEN_DATA_LENGTH(1);
if (p2wi->slave_addr >= 0 && addr != p2wi->slave_addr) {
dev_err(&adap->dev, "invalid P2WI address\n");
return -EINVAL;
}
if (!data)
return -EINVAL;
writel(command, p2wi->regs + P2WI_DADDR0);
if (read_write == I2C_SMBUS_READ)
dlen |= P2WI_DLEN_READ;
else
writel(data->byte, p2wi->regs + P2WI_DATA0);
writel(dlen, p2wi->regs + P2WI_DLEN);
if (readl(p2wi->regs + P2WI_CTRL) & P2WI_CTRL_START_TRANS) {
dev_err(&adap->dev, "P2WI bus busy\n");
return -EBUSY;
}
reinit_completion(&p2wi->complete);
writel(P2WI_INTS_LOAD_BSY | P2WI_INTS_TRANS_ERR | P2WI_INTS_TRANS_OVER,
p2wi->regs + P2WI_INTE);
writel(P2WI_CTRL_START_TRANS | P2WI_CTRL_GLOBAL_INT_ENB,
p2wi->regs + P2WI_CTRL);
wait_for_completion(&p2wi->complete);
if (p2wi->status & P2WI_INTS_LOAD_BSY) {
dev_err(&adap->dev, "P2WI bus busy\n");
return -EBUSY;
}
if (p2wi->status & P2WI_INTS_TRANS_ERR) {
dev_err(&adap->dev, "P2WI bus xfer error\n");
return -ENXIO;
}
if (read_write == I2C_SMBUS_READ)
data->byte = readl(p2wi->regs + P2WI_DATA0);
return 0;
}
static int p2wi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *childnp;
unsigned long parent_clk_freq;
u32 clk_freq = 100000;
struct resource *r;
struct p2wi *p2wi;
u32 slave_addr;
int clk_div;
int irq;
int ret;
of_property_read_u32(np, "clock-frequency", &clk_freq);
if (clk_freq > P2WI_MAX_FREQ) {
dev_err(dev,
"required clock-frequency (%u Hz) is too high (max = 6MHz)",
clk_freq);
return -EINVAL;
}
if (of_get_child_count(np) > 1) {
dev_err(dev, "P2WI only supports one slave device\n");
return -EINVAL;
}
p2wi = devm_kzalloc(dev, sizeof(struct p2wi), GFP_KERNEL);
if (!p2wi)
return -ENOMEM;
p2wi->slave_addr = -1;
childnp = of_get_next_available_child(np, NULL);
if (childnp) {
ret = of_property_read_u32(childnp, "reg", &slave_addr);
if (ret) {
dev_err(dev, "invalid slave address on node %s\n",
childnp->full_name);
return -EINVAL;
}
p2wi->slave_addr = slave_addr;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
p2wi->regs = devm_ioremap_resource(dev, r);
if (IS_ERR(p2wi->regs))
return PTR_ERR(p2wi->regs);
strlcpy(p2wi->adapter.name, pdev->name, sizeof(p2wi->adapter.name));
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "failed to retrieve irq: %d\n", irq);
return irq;
}
p2wi->clk = devm_clk_get(dev, NULL);
if (IS_ERR(p2wi->clk)) {
ret = PTR_ERR(p2wi->clk);
dev_err(dev, "failed to retrieve clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(p2wi->clk);
if (ret) {
dev_err(dev, "failed to enable clk: %d\n", ret);
return ret;
}
parent_clk_freq = clk_get_rate(p2wi->clk);
p2wi->rstc = devm_reset_control_get(dev, NULL);
if (IS_ERR(p2wi->rstc)) {
ret = PTR_ERR(p2wi->rstc);
dev_err(dev, "failed to retrieve reset controller: %d\n", ret);
goto err_clk_disable;
}
ret = reset_control_deassert(p2wi->rstc);
if (ret) {
dev_err(dev, "failed to deassert reset line: %d\n", ret);
goto err_clk_disable;
}
init_completion(&p2wi->complete);
p2wi->adapter.dev.parent = dev;
p2wi->adapter.algo = &p2wi_algo;
p2wi->adapter.owner = THIS_MODULE;
p2wi->adapter.dev.of_node = pdev->dev.of_node;
platform_set_drvdata(pdev, p2wi);
i2c_set_adapdata(&p2wi->adapter, p2wi);
ret = devm_request_irq(dev, irq, p2wi_interrupt, 0, pdev->name, p2wi);
if (ret) {
dev_err(dev, "can't register interrupt handler irq%d: %d\n",
irq, ret);
goto err_reset_assert;
}
writel(P2WI_CTRL_SOFT_RST, p2wi->regs + P2WI_CTRL);
clk_div = parent_clk_freq / clk_freq;
if (!clk_div) {
dev_warn(dev,
"clock-frequency is too high, setting it to %lu Hz\n",
parent_clk_freq);
clk_div = 1;
} else if (clk_div > P2WI_CCR_MAX_CLK_DIV) {
dev_warn(dev,
"clock-frequency is too low, setting it to %lu Hz\n",
parent_clk_freq / P2WI_CCR_MAX_CLK_DIV);
clk_div = P2WI_CCR_MAX_CLK_DIV;
}
writel(P2WI_CCR_SDA_OUT_DELAY(1) | P2WI_CCR_CLK_DIV(clk_div),
p2wi->regs + P2WI_CCR);
ret = i2c_add_adapter(&p2wi->adapter);
if (!ret)
return 0;
err_reset_assert:
reset_control_assert(p2wi->rstc);
err_clk_disable:
clk_disable_unprepare(p2wi->clk);
return ret;
}
static int p2wi_remove(struct platform_device *dev)
{
struct p2wi *p2wi = platform_get_drvdata(dev);
reset_control_assert(p2wi->rstc);
clk_disable_unprepare(p2wi->clk);
i2c_del_adapter(&p2wi->adapter);
return 0;
}
