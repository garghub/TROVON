static void __davinci_mdio_reset(struct davinci_mdio_data *data)
{
u32 mdio_in, div, mdio_out_khz, access_time;
mdio_in = clk_get_rate(data->clk);
div = (mdio_in / data->pdata.bus_freq) - 1;
if (div > CONTROL_MAX_DIV)
div = CONTROL_MAX_DIV;
__raw_writel(div | CONTROL_ENABLE, &data->regs->control);
mdio_out_khz = mdio_in / (1000 * (div + 1));
access_time = (88 * 1000) / mdio_out_khz;
data->access_time = usecs_to_jiffies(access_time * 4);
if (!data->access_time)
data->access_time = 1;
}
static int davinci_mdio_reset(struct mii_bus *bus)
{
struct davinci_mdio_data *data = bus->priv;
u32 phy_mask, ver;
__davinci_mdio_reset(data);
msleep(PHY_MAX_ADDR * data->access_time);
ver = __raw_readl(&data->regs->version);
dev_info(data->dev, "davinci mdio revision %d.%d\n",
(ver >> 8) & 0xff, ver & 0xff);
phy_mask = __raw_readl(&data->regs->alive);
if (phy_mask) {
dev_info(data->dev, "detected phy mask %x\n", ~phy_mask);
phy_mask = ~phy_mask;
} else {
dev_warn(data->dev, "no live phy, scanning all\n");
phy_mask = 0;
}
data->bus->phy_mask = phy_mask;
return 0;
}
static inline int wait_for_user_access(struct davinci_mdio_data *data)
{
struct davinci_mdio_regs __iomem *regs = data->regs;
unsigned long timeout = jiffies + msecs_to_jiffies(MDIO_TIMEOUT);
u32 reg;
while (time_after(timeout, jiffies)) {
reg = __raw_readl(&regs->user[0].access);
if ((reg & USERACCESS_GO) == 0)
return 0;
reg = __raw_readl(&regs->control);
if ((reg & CONTROL_IDLE) == 0)
continue;
dev_warn(data->dev, "resetting idled controller\n");
__davinci_mdio_reset(data);
return -EAGAIN;
}
reg = __raw_readl(&regs->user[0].access);
if ((reg & USERACCESS_GO) == 0)
return 0;
dev_err(data->dev, "timed out waiting for user access\n");
return -ETIMEDOUT;
}
static inline int wait_for_idle(struct davinci_mdio_data *data)
{
struct davinci_mdio_regs __iomem *regs = data->regs;
unsigned long timeout = jiffies + msecs_to_jiffies(MDIO_TIMEOUT);
while (time_after(timeout, jiffies)) {
if (__raw_readl(&regs->control) & CONTROL_IDLE)
return 0;
}
dev_err(data->dev, "timed out waiting for idle\n");
return -ETIMEDOUT;
}
static int davinci_mdio_read(struct mii_bus *bus, int phy_id, int phy_reg)
{
struct davinci_mdio_data *data = bus->priv;
u32 reg;
int ret;
if (phy_reg & ~PHY_REG_MASK || phy_id & ~PHY_ID_MASK)
return -EINVAL;
spin_lock(&data->lock);
if (data->suspended) {
spin_unlock(&data->lock);
return -ENODEV;
}
reg = (USERACCESS_GO | USERACCESS_READ | (phy_reg << 21) |
(phy_id << 16));
while (1) {
ret = wait_for_user_access(data);
if (ret == -EAGAIN)
continue;
if (ret < 0)
break;
__raw_writel(reg, &data->regs->user[0].access);
ret = wait_for_user_access(data);
if (ret == -EAGAIN)
continue;
if (ret < 0)
break;
reg = __raw_readl(&data->regs->user[0].access);
ret = (reg & USERACCESS_ACK) ? (reg & USERACCESS_DATA) : -EIO;
break;
}
spin_unlock(&data->lock);
return ret;
}
static int davinci_mdio_write(struct mii_bus *bus, int phy_id,
int phy_reg, u16 phy_data)
{
struct davinci_mdio_data *data = bus->priv;
u32 reg;
int ret;
if (phy_reg & ~PHY_REG_MASK || phy_id & ~PHY_ID_MASK)
return -EINVAL;
spin_lock(&data->lock);
if (data->suspended) {
spin_unlock(&data->lock);
return -ENODEV;
}
reg = (USERACCESS_GO | USERACCESS_WRITE | (phy_reg << 21) |
(phy_id << 16) | (phy_data & USERACCESS_DATA));
while (1) {
ret = wait_for_user_access(data);
if (ret == -EAGAIN)
continue;
if (ret < 0)
break;
__raw_writel(reg, &data->regs->user[0].access);
ret = wait_for_user_access(data);
if (ret == -EAGAIN)
continue;
break;
}
spin_unlock(&data->lock);
return 0;
}
static int davinci_mdio_probe_dt(struct mdio_platform_data *data,
struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
u32 prop;
if (!node)
return -EINVAL;
if (of_property_read_u32(node, "bus_freq", &prop)) {
pr_err("Missing bus_freq property in the DT.\n");
return -EINVAL;
}
data->bus_freq = prop;
return 0;
}
static int davinci_mdio_probe(struct platform_device *pdev)
{
struct mdio_platform_data *pdata = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
struct davinci_mdio_data *data;
struct resource *res;
struct phy_device *phy;
int ret, addr;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->bus = mdiobus_alloc();
if (!data->bus) {
dev_err(dev, "failed to alloc mii bus\n");
ret = -ENOMEM;
goto bail_out;
}
if (dev->of_node) {
if (davinci_mdio_probe_dt(&data->pdata, pdev))
data->pdata = default_pdata;
snprintf(data->bus->id, MII_BUS_ID_SIZE, "%s", pdev->name);
} else {
data->pdata = pdata ? (*pdata) : default_pdata;
snprintf(data->bus->id, MII_BUS_ID_SIZE, "%s-%x",
pdev->name, pdev->id);
}
data->bus->name = dev_name(dev);
data->bus->read = davinci_mdio_read,
data->bus->write = davinci_mdio_write,
data->bus->reset = davinci_mdio_reset,
data->bus->parent = dev;
data->bus->priv = data;
pinctrl_pm_select_default_state(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
data->clk = clk_get(&pdev->dev, "fck");
if (IS_ERR(data->clk)) {
dev_err(dev, "failed to get device clock\n");
ret = PTR_ERR(data->clk);
data->clk = NULL;
goto bail_out;
}
dev_set_drvdata(dev, data);
data->dev = dev;
spin_lock_init(&data->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "could not find register map resource\n");
ret = -ENOENT;
goto bail_out;
}
res = devm_request_mem_region(dev, res->start, resource_size(res),
dev_name(dev));
if (!res) {
dev_err(dev, "could not allocate register map resource\n");
ret = -ENXIO;
goto bail_out;
}
data->regs = devm_ioremap_nocache(dev, res->start, resource_size(res));
if (!data->regs) {
dev_err(dev, "could not map mdio registers\n");
ret = -ENOMEM;
goto bail_out;
}
ret = mdiobus_register(data->bus);
if (ret)
goto bail_out;
for (addr = 0; addr < PHY_MAX_ADDR; addr++) {
phy = data->bus->phy_map[addr];
if (phy) {
dev_info(dev, "phy[%d]: device %s, driver %s\n",
phy->addr, dev_name(&phy->dev),
phy->drv ? phy->drv->name : "unknown");
}
}
return 0;
bail_out:
if (data->bus)
mdiobus_free(data->bus);
if (data->clk)
clk_put(data->clk);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
kfree(data);
return ret;
}
static int davinci_mdio_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct davinci_mdio_data *data = dev_get_drvdata(dev);
if (data->bus) {
mdiobus_unregister(data->bus);
mdiobus_free(data->bus);
}
if (data->clk)
clk_put(data->clk);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
dev_set_drvdata(dev, NULL);
kfree(data);
return 0;
}
static int davinci_mdio_suspend(struct device *dev)
{
struct davinci_mdio_data *data = dev_get_drvdata(dev);
u32 ctrl;
spin_lock(&data->lock);
ctrl = __raw_readl(&data->regs->control);
ctrl &= ~CONTROL_ENABLE;
__raw_writel(ctrl, &data->regs->control);
wait_for_idle(data);
data->suspended = true;
spin_unlock(&data->lock);
pm_runtime_put_sync(data->dev);
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int davinci_mdio_resume(struct device *dev)
{
struct davinci_mdio_data *data = dev_get_drvdata(dev);
pinctrl_pm_select_default_state(dev);
pm_runtime_get_sync(data->dev);
spin_lock(&data->lock);
__davinci_mdio_reset(data);
data->suspended = false;
spin_unlock(&data->lock);
return 0;
}
static int __init davinci_mdio_init(void)
{
return platform_driver_register(&davinci_mdio_driver);
}
static void __exit davinci_mdio_exit(void)
{
platform_driver_unregister(&davinci_mdio_driver);
}
