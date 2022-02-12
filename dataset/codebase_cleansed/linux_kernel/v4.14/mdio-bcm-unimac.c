static inline u32 unimac_mdio_readl(struct unimac_mdio_priv *priv, u32 offset)
{
if (IS_ENABLED(CONFIG_MIPS) && IS_ENABLED(CONFIG_CPU_BIG_ENDIAN))
return __raw_readl(priv->base + offset);
else
return readl_relaxed(priv->base + offset);
}
static inline void unimac_mdio_writel(struct unimac_mdio_priv *priv, u32 val,
u32 offset)
{
if (IS_ENABLED(CONFIG_MIPS) && IS_ENABLED(CONFIG_CPU_BIG_ENDIAN))
__raw_writel(val, priv->base + offset);
else
writel_relaxed(val, priv->base + offset);
}
static inline void unimac_mdio_start(struct unimac_mdio_priv *priv)
{
u32 reg;
reg = unimac_mdio_readl(priv, MDIO_CMD);
reg |= MDIO_START_BUSY;
unimac_mdio_writel(priv, reg, MDIO_CMD);
}
static inline unsigned int unimac_mdio_busy(struct unimac_mdio_priv *priv)
{
return unimac_mdio_readl(priv, MDIO_CMD) & MDIO_START_BUSY;
}
static int unimac_mdio_poll(void *wait_func_data)
{
struct unimac_mdio_priv *priv = wait_func_data;
unsigned int timeout = 1000;
do {
if (!unimac_mdio_busy(priv))
return 0;
usleep_range(1000, 2000);
} while (--timeout);
if (!timeout)
return -ETIMEDOUT;
return 0;
}
static int unimac_mdio_read(struct mii_bus *bus, int phy_id, int reg)
{
struct unimac_mdio_priv *priv = bus->priv;
int ret;
u32 cmd;
cmd = MDIO_RD | (phy_id << MDIO_PMD_SHIFT) | (reg << MDIO_REG_SHIFT);
unimac_mdio_writel(priv, cmd, MDIO_CMD);
unimac_mdio_start(priv);
ret = priv->wait_func(priv->wait_func_data);
if (ret)
return ret;
cmd = unimac_mdio_readl(priv, MDIO_CMD);
if (!(bus->phy_ignore_ta_mask & 1 << phy_id) && (cmd & MDIO_READ_FAIL))
return -EIO;
return cmd & 0xffff;
}
static int unimac_mdio_write(struct mii_bus *bus, int phy_id,
int reg, u16 val)
{
struct unimac_mdio_priv *priv = bus->priv;
u32 cmd;
cmd = MDIO_WR | (phy_id << MDIO_PMD_SHIFT) |
(reg << MDIO_REG_SHIFT) | (0xffff & val);
unimac_mdio_writel(priv, cmd, MDIO_CMD);
unimac_mdio_start(priv);
return priv->wait_func(priv->wait_func_data);
}
static int unimac_mdio_reset(struct mii_bus *bus)
{
struct device_node *np = bus->dev.of_node;
struct device_node *child;
u32 read_mask = 0;
int addr;
if (!np) {
read_mask = ~bus->phy_mask;
} else {
for_each_available_child_of_node(np, child) {
addr = of_mdio_parse_addr(&bus->dev, child);
if (addr < 0)
continue;
read_mask |= 1 << addr;
}
}
for (addr = 0; addr < PHY_MAX_ADDR; addr++) {
if (read_mask & 1 << addr) {
dev_dbg(&bus->dev, "Workaround for PHY @ %d\n", addr);
mdiobus_read(bus, addr, MII_BMSR);
}
}
return 0;
}
static int unimac_mdio_probe(struct platform_device *pdev)
{
struct unimac_mdio_pdata *pdata = pdev->dev.platform_data;
struct unimac_mdio_priv *priv;
struct device_node *np;
struct mii_bus *bus;
struct resource *r;
int ret;
np = pdev->dev.of_node;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
if (!priv->base) {
dev_err(&pdev->dev, "failed to remap register\n");
return -ENOMEM;
}
priv->mii_bus = mdiobus_alloc();
if (!priv->mii_bus)
return -ENOMEM;
bus = priv->mii_bus;
bus->priv = priv;
if (pdata) {
bus->name = pdata->bus_name;
priv->wait_func = pdata->wait_func;
priv->wait_func_data = pdata->wait_func_data;
bus->phy_mask = ~pdata->phy_mask;
} else {
bus->name = "unimac MII bus";
priv->wait_func_data = priv;
priv->wait_func = unimac_mdio_poll;
}
bus->parent = &pdev->dev;
bus->read = unimac_mdio_read;
bus->write = unimac_mdio_write;
bus->reset = unimac_mdio_reset;
snprintf(bus->id, MII_BUS_ID_SIZE, "%s-%d", pdev->name, pdev->id);
ret = of_mdiobus_register(bus, np);
if (ret) {
dev_err(&pdev->dev, "MDIO bus registration failed\n");
goto out_mdio_free;
}
platform_set_drvdata(pdev, priv);
dev_info(&pdev->dev, "Broadcom UniMAC MDIO bus at 0x%p\n", priv->base);
return 0;
out_mdio_free:
mdiobus_free(bus);
return ret;
}
static int unimac_mdio_remove(struct platform_device *pdev)
{
struct unimac_mdio_priv *priv = platform_get_drvdata(pdev);
mdiobus_unregister(priv->mii_bus);
mdiobus_free(priv->mii_bus);
return 0;
}
