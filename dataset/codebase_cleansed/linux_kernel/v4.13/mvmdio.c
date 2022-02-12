static int orion_mdio_wait_ready(const struct orion_mdio_ops *ops,
struct mii_bus *bus)
{
struct orion_mdio_dev *dev = bus->priv;
unsigned long timeout = usecs_to_jiffies(MVMDIO_SMI_TIMEOUT);
unsigned long end = jiffies + timeout;
int timedout = 0;
while (1) {
if (ops->is_done(dev))
return 0;
else if (timedout)
break;
if (dev->err_interrupt <= 0) {
usleep_range(ops->poll_interval_min,
ops->poll_interval_max);
if (time_is_before_jiffies(end))
++timedout;
} else {
if (timeout < 2)
timeout = 2;
wait_event_timeout(dev->smi_busy_wait,
ops->is_done(dev), timeout);
++timedout;
}
}
dev_err(bus->parent, "Timeout: SMI busy for too long\n");
return -ETIMEDOUT;
}
static int orion_mdio_smi_is_done(struct orion_mdio_dev *dev)
{
return !(readl(dev->regs) & MVMDIO_SMI_BUSY);
}
static int orion_mdio_smi_read(struct mii_bus *bus, int mii_id,
int regnum)
{
struct orion_mdio_dev *dev = bus->priv;
u32 val;
int ret;
if (regnum & MII_ADDR_C45)
return -EOPNOTSUPP;
ret = orion_mdio_wait_ready(&orion_mdio_smi_ops, bus);
if (ret < 0)
return ret;
writel(((mii_id << MVMDIO_SMI_PHY_ADDR_SHIFT) |
(regnum << MVMDIO_SMI_PHY_REG_SHIFT) |
MVMDIO_SMI_READ_OPERATION),
dev->regs);
ret = orion_mdio_wait_ready(&orion_mdio_smi_ops, bus);
if (ret < 0)
return ret;
val = readl(dev->regs);
if (!(val & MVMDIO_SMI_READ_VALID)) {
dev_err(bus->parent, "SMI bus read not valid\n");
return -ENODEV;
}
return val & GENMASK(15, 0);
}
static int orion_mdio_smi_write(struct mii_bus *bus, int mii_id,
int regnum, u16 value)
{
struct orion_mdio_dev *dev = bus->priv;
int ret;
if (regnum & MII_ADDR_C45)
return -EOPNOTSUPP;
ret = orion_mdio_wait_ready(&orion_mdio_smi_ops, bus);
if (ret < 0)
return ret;
writel(((mii_id << MVMDIO_SMI_PHY_ADDR_SHIFT) |
(regnum << MVMDIO_SMI_PHY_REG_SHIFT) |
MVMDIO_SMI_WRITE_OPERATION |
(value << MVMDIO_SMI_DATA_SHIFT)),
dev->regs);
return 0;
}
static int orion_mdio_xsmi_is_done(struct orion_mdio_dev *dev)
{
return !(readl(dev->regs + MVMDIO_XSMI_MGNT_REG) & MVMDIO_XSMI_BUSY);
}
static int orion_mdio_xsmi_read(struct mii_bus *bus, int mii_id,
int regnum)
{
struct orion_mdio_dev *dev = bus->priv;
u16 dev_addr = (regnum >> 16) & GENMASK(4, 0);
int ret;
if (!(regnum & MII_ADDR_C45))
return -EOPNOTSUPP;
ret = orion_mdio_wait_ready(&orion_mdio_xsmi_ops, bus);
if (ret < 0)
return ret;
writel(regnum & GENMASK(15, 0), dev->regs + MVMDIO_XSMI_ADDR_REG);
writel((mii_id << MVMDIO_XSMI_PHYADDR_SHIFT) |
(dev_addr << MVMDIO_XSMI_DEVADDR_SHIFT) |
MVMDIO_XSMI_READ_OPERATION,
dev->regs + MVMDIO_XSMI_MGNT_REG);
ret = orion_mdio_wait_ready(&orion_mdio_xsmi_ops, bus);
if (ret < 0)
return ret;
if (!(readl(dev->regs + MVMDIO_XSMI_MGNT_REG) &
MVMDIO_XSMI_READ_VALID)) {
dev_err(bus->parent, "XSMI bus read not valid\n");
return -ENODEV;
}
return readl(dev->regs + MVMDIO_XSMI_MGNT_REG) & GENMASK(15, 0);
}
static int orion_mdio_xsmi_write(struct mii_bus *bus, int mii_id,
int regnum, u16 value)
{
struct orion_mdio_dev *dev = bus->priv;
u16 dev_addr = (regnum >> 16) & GENMASK(4, 0);
int ret;
if (!(regnum & MII_ADDR_C45))
return -EOPNOTSUPP;
ret = orion_mdio_wait_ready(&orion_mdio_xsmi_ops, bus);
if (ret < 0)
return ret;
writel(regnum & GENMASK(15, 0), dev->regs + MVMDIO_XSMI_ADDR_REG);
writel((mii_id << MVMDIO_XSMI_PHYADDR_SHIFT) |
(dev_addr << MVMDIO_XSMI_DEVADDR_SHIFT) |
MVMDIO_XSMI_WRITE_OPERATION | value,
dev->regs + MVMDIO_XSMI_MGNT_REG);
return 0;
}
static irqreturn_t orion_mdio_err_irq(int irq, void *dev_id)
{
struct orion_mdio_dev *dev = dev_id;
if (readl(dev->regs + MVMDIO_ERR_INT_CAUSE) &
MVMDIO_ERR_INT_SMI_DONE) {
writel(~MVMDIO_ERR_INT_SMI_DONE,
dev->regs + MVMDIO_ERR_INT_CAUSE);
wake_up(&dev->smi_busy_wait);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int orion_mdio_probe(struct platform_device *pdev)
{
enum orion_mdio_bus_type type;
struct resource *r;
struct mii_bus *bus;
struct orion_mdio_dev *dev;
int i, ret;
type = (enum orion_mdio_bus_type)of_device_get_match_data(&pdev->dev);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "No SMI register address given\n");
return -ENODEV;
}
bus = devm_mdiobus_alloc_size(&pdev->dev,
sizeof(struct orion_mdio_dev));
if (!bus)
return -ENOMEM;
switch (type) {
case BUS_TYPE_SMI:
bus->read = orion_mdio_smi_read;
bus->write = orion_mdio_smi_write;
break;
case BUS_TYPE_XSMI:
bus->read = orion_mdio_xsmi_read;
bus->write = orion_mdio_xsmi_write;
break;
}
bus->name = "orion_mdio_bus";
snprintf(bus->id, MII_BUS_ID_SIZE, "%s-mii",
dev_name(&pdev->dev));
bus->parent = &pdev->dev;
dev = bus->priv;
dev->regs = devm_ioremap(&pdev->dev, r->start, resource_size(r));
if (!dev->regs) {
dev_err(&pdev->dev, "Unable to remap SMI register\n");
return -ENODEV;
}
init_waitqueue_head(&dev->smi_busy_wait);
for (i = 0; i < ARRAY_SIZE(dev->clk); i++) {
dev->clk[i] = of_clk_get(pdev->dev.of_node, i);
if (IS_ERR(dev->clk[i]))
break;
clk_prepare_enable(dev->clk[i]);
}
dev->err_interrupt = platform_get_irq(pdev, 0);
if (dev->err_interrupt > 0 &&
resource_size(r) < MVMDIO_ERR_INT_MASK + 4) {
dev_err(&pdev->dev,
"disabling interrupt, resource size is too small\n");
dev->err_interrupt = 0;
}
if (dev->err_interrupt > 0) {
ret = devm_request_irq(&pdev->dev, dev->err_interrupt,
orion_mdio_err_irq,
IRQF_SHARED, pdev->name, dev);
if (ret)
goto out_mdio;
writel(MVMDIO_ERR_INT_SMI_DONE,
dev->regs + MVMDIO_ERR_INT_MASK);
} else if (dev->err_interrupt == -EPROBE_DEFER) {
return -EPROBE_DEFER;
}
if (pdev->dev.of_node)
ret = of_mdiobus_register(bus, pdev->dev.of_node);
else
ret = mdiobus_register(bus);
if (ret < 0) {
dev_err(&pdev->dev, "Cannot register MDIO bus (%d)\n", ret);
goto out_mdio;
}
platform_set_drvdata(pdev, bus);
return 0;
out_mdio:
if (dev->err_interrupt > 0)
writel(0, dev->regs + MVMDIO_ERR_INT_MASK);
for (i = 0; i < ARRAY_SIZE(dev->clk); i++) {
if (IS_ERR(dev->clk[i]))
break;
clk_disable_unprepare(dev->clk[i]);
clk_put(dev->clk[i]);
}
return ret;
}
static int orion_mdio_remove(struct platform_device *pdev)
{
struct mii_bus *bus = platform_get_drvdata(pdev);
struct orion_mdio_dev *dev = bus->priv;
int i;
if (dev->err_interrupt > 0)
writel(0, dev->regs + MVMDIO_ERR_INT_MASK);
mdiobus_unregister(bus);
for (i = 0; i < ARRAY_SIZE(dev->clk); i++) {
if (IS_ERR(dev->clk[i]))
break;
clk_disable_unprepare(dev->clk[i]);
clk_put(dev->clk[i]);
}
return 0;
}
