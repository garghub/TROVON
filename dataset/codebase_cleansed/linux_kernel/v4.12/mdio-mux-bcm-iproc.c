static int iproc_mdio_wait_for_idle(void __iomem *base, bool result)
{
unsigned int timeout = 1000;
u32 val;
do {
val = readl(base + MDIO_STAT_OFFSET);
if ((val & MDIO_STAT_DONE) == result)
return 0;
usleep_range(1000, 2000);
} while (timeout--);
return -ETIMEDOUT;
}
static int start_miim_ops(void __iomem *base,
u16 phyid, u32 reg, u16 val, u32 op)
{
u32 param;
int ret;
writel(0, base + MDIO_CTRL_OFFSET);
ret = iproc_mdio_wait_for_idle(base, 0);
if (ret)
goto err;
param = readl(base + MDIO_PARAM_OFFSET);
param |= phyid << MDIO_PARAM_PHY_ID;
param |= val << MDIO_PARAM_PHY_DATA;
if (reg & MII_ADDR_C45)
param |= BIT(MDIO_PARAM_C45_SEL);
writel(param, base + MDIO_PARAM_OFFSET);
writel(reg, base + MDIO_ADDR_OFFSET);
writel(op, base + MDIO_CTRL_OFFSET);
ret = iproc_mdio_wait_for_idle(base, 1);
if (ret)
goto err;
if (op == MDIO_CTRL_READ_OP)
ret = readl(base + MDIO_READ_OFFSET) & MDIO_READ_DATA_MASK;
err:
return ret;
}
static int iproc_mdiomux_read(struct mii_bus *bus, int phyid, int reg)
{
struct iproc_mdiomux_desc *md = bus->priv;
int ret;
ret = start_miim_ops(md->base, phyid, reg, 0, MDIO_CTRL_READ_OP);
if (ret < 0)
dev_err(&bus->dev, "mdiomux read operation failed!!!");
return ret;
}
static int iproc_mdiomux_write(struct mii_bus *bus,
int phyid, int reg, u16 val)
{
struct iproc_mdiomux_desc *md = bus->priv;
int ret;
ret = start_miim_ops(md->base, phyid, reg, val, MDIO_CTRL_WRITE_OP);
if (ret < 0)
dev_err(&bus->dev, "mdiomux write operation failed!!!");
return ret;
}
static int mdio_mux_iproc_switch_fn(int current_child, int desired_child,
void *data)
{
struct iproc_mdiomux_desc *md = data;
u32 param, bus_id;
bool bus_dir;
bus_dir = (desired_child < EXT_BUS_START_ADDR);
bus_id = bus_dir ? desired_child : (desired_child - EXT_BUS_START_ADDR);
param = (bus_dir ? 1 : 0) << MDIO_PARAM_INTERNAL_SEL;
param |= (bus_id << MDIO_PARAM_BUS_ID);
writel(param, md->base + MDIO_PARAM_OFFSET);
return 0;
}
static int mdio_mux_iproc_probe(struct platform_device *pdev)
{
struct iproc_mdiomux_desc *md;
struct mii_bus *bus;
struct resource *res;
int rc;
md = devm_kzalloc(&pdev->dev, sizeof(*md), GFP_KERNEL);
if (!md)
return -ENOMEM;
md->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
md->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(md->base)) {
dev_err(&pdev->dev, "failed to ioremap register\n");
return PTR_ERR(md->base);
}
md->mii_bus = mdiobus_alloc();
if (!md->mii_bus) {
dev_err(&pdev->dev, "mdiomux bus alloc failed\n");
return -ENOMEM;
}
bus = md->mii_bus;
bus->priv = md;
bus->name = "iProc MDIO mux bus";
snprintf(bus->id, MII_BUS_ID_SIZE, "%s-%d", pdev->name, pdev->id);
bus->parent = &pdev->dev;
bus->read = iproc_mdiomux_read;
bus->write = iproc_mdiomux_write;
bus->phy_mask = ~0;
bus->dev.of_node = pdev->dev.of_node;
rc = mdiobus_register(bus);
if (rc) {
dev_err(&pdev->dev, "mdiomux registration failed\n");
goto out;
}
platform_set_drvdata(pdev, md);
rc = mdio_mux_init(md->dev, mdio_mux_iproc_switch_fn,
&md->mux_handle, md, md->mii_bus);
if (rc) {
dev_info(md->dev, "mdiomux initialization failed\n");
goto out_register;
}
dev_info(md->dev, "iProc mdiomux registered\n");
return 0;
out_register:
mdiobus_unregister(bus);
out:
mdiobus_free(bus);
return rc;
}
static int mdio_mux_iproc_remove(struct platform_device *pdev)
{
struct iproc_mdiomux_desc *md = dev_get_platdata(&pdev->dev);
mdio_mux_uninit(md->mux_handle);
mdiobus_unregister(md->mii_bus);
mdiobus_free(md->mii_bus);
return 0;
}
