static int sxgbe_mdio_busy_wait(void __iomem *ioaddr, unsigned int mii_data)
{
unsigned long fin_time = jiffies + 3 * HZ;
while (!time_after(jiffies, fin_time)) {
if (!(readl(ioaddr + mii_data) & SXGBE_MII_BUSY))
return 0;
cpu_relax();
}
return -EBUSY;
}
static void sxgbe_mdio_ctrl_data(struct sxgbe_priv_data *sp, u32 cmd,
u16 phydata)
{
u32 reg = phydata;
reg |= (cmd << 16) | SXGBE_SMA_SKIP_ADDRFRM |
((sp->clk_csr & 0x7) << 19) | SXGBE_MII_BUSY;
writel(reg, sp->ioaddr + sp->hw->mii.data);
}
static void sxgbe_mdio_c45(struct sxgbe_priv_data *sp, u32 cmd, int phyaddr,
int phyreg, u16 phydata)
{
u32 reg;
reg = ((phyreg >> 16) & 0x1f) << 21;
reg |= (phyaddr << 16) | (phyreg & 0xffff);
writel(reg, sp->ioaddr + sp->hw->mii.addr);
sxgbe_mdio_ctrl_data(sp, cmd, phydata);
}
static void sxgbe_mdio_c22(struct sxgbe_priv_data *sp, u32 cmd, int phyaddr,
int phyreg, u16 phydata)
{
u32 reg;
writel(1 << phyaddr, sp->ioaddr + SXGBE_MDIO_CLAUSE22_PORT_REG);
reg = (phyaddr << 16) | (phyreg & 0x1f);
writel(reg, sp->ioaddr + sp->hw->mii.addr);
sxgbe_mdio_ctrl_data(sp, cmd, phydata);
}
static int sxgbe_mdio_access(struct sxgbe_priv_data *sp, u32 cmd, int phyaddr,
int phyreg, u16 phydata)
{
const struct mii_regs *mii = &sp->hw->mii;
int rc;
rc = sxgbe_mdio_busy_wait(sp->ioaddr, mii->data);
if (rc < 0)
return rc;
if (phyreg & MII_ADDR_C45) {
sxgbe_mdio_c45(sp, cmd, phyaddr, phyreg, phydata);
} else {
if (phyaddr >= 4)
return -ENODEV;
sxgbe_mdio_c22(sp, cmd, phyaddr, phyreg, phydata);
}
return sxgbe_mdio_busy_wait(sp->ioaddr, mii->data);
}
static int sxgbe_mdio_read(struct mii_bus *bus, int phyaddr, int phyreg)
{
struct net_device *ndev = bus->priv;
struct sxgbe_priv_data *priv = netdev_priv(ndev);
int rc;
rc = sxgbe_mdio_access(priv, SXGBE_SMA_READ_CMD, phyaddr, phyreg, 0);
if (rc < 0)
return rc;
return readl(priv->ioaddr + priv->hw->mii.data) & 0xffff;
}
static int sxgbe_mdio_write(struct mii_bus *bus, int phyaddr, int phyreg,
u16 phydata)
{
struct net_device *ndev = bus->priv;
struct sxgbe_priv_data *priv = netdev_priv(ndev);
return sxgbe_mdio_access(priv, SXGBE_SMA_WRITE_CMD, phyaddr, phyreg,
phydata);
}
int sxgbe_mdio_register(struct net_device *ndev)
{
struct mii_bus *mdio_bus;
struct sxgbe_priv_data *priv = netdev_priv(ndev);
struct sxgbe_mdio_bus_data *mdio_data = priv->plat->mdio_bus_data;
int err, phy_addr;
int *irqlist;
bool phy_found = false;
bool act;
mdio_bus = mdiobus_alloc();
if (!mdio_bus) {
netdev_err(ndev, "%s: mii bus allocation failed\n", __func__);
return -ENOMEM;
}
if (mdio_data->irqs)
irqlist = mdio_data->irqs;
else
irqlist = priv->mii_irq;
mdio_bus->name = "sxgbe";
mdio_bus->read = &sxgbe_mdio_read;
mdio_bus->write = &sxgbe_mdio_write;
snprintf(mdio_bus->id, MII_BUS_ID_SIZE, "%s-%x",
mdio_bus->name, priv->plat->bus_id);
mdio_bus->priv = ndev;
mdio_bus->phy_mask = mdio_data->phy_mask;
mdio_bus->parent = priv->device;
err = mdiobus_register(mdio_bus);
if (err != 0) {
netdev_err(ndev, "mdiobus register failed\n");
goto mdiobus_err;
}
for (phy_addr = 0; phy_addr < PHY_MAX_ADDR; phy_addr++) {
struct phy_device *phy = mdio_bus->phy_map[phy_addr];
if (phy) {
char irq_num[4];
char *irq_str;
if ((mdio_data->irqs == NULL) &&
(mdio_data->probed_phy_irq > 0)) {
irqlist[phy_addr] = mdio_data->probed_phy_irq;
phy->irq = mdio_data->probed_phy_irq;
}
if (priv->plat->phy_addr == -1)
priv->plat->phy_addr = phy_addr;
act = (priv->plat->phy_addr == phy_addr);
switch (phy->irq) {
case PHY_POLL:
irq_str = "POLL";
break;
case PHY_IGNORE_INTERRUPT:
irq_str = "IGNORE";
break;
default:
sprintf(irq_num, "%d", phy->irq);
irq_str = irq_num;
break;
}
netdev_info(ndev, "PHY ID %08x at %d IRQ %s (%s)%s\n",
phy->phy_id, phy_addr, irq_str,
dev_name(&phy->dev), act ? " active" : "");
phy_found = true;
}
}
if (!phy_found) {
netdev_err(ndev, "PHY not found\n");
goto phyfound_err;
}
priv->mii = mdio_bus;
return 0;
phyfound_err:
err = -ENODEV;
mdiobus_unregister(mdio_bus);
mdiobus_err:
mdiobus_free(mdio_bus);
return err;
}
int sxgbe_mdio_unregister(struct net_device *ndev)
{
struct sxgbe_priv_data *priv = netdev_priv(ndev);
if (!priv->mii)
return 0;
mdiobus_unregister(priv->mii);
priv->mii->priv = NULL;
mdiobus_free(priv->mii);
priv->mii = NULL;
return 0;
}
