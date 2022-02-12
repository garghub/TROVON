static int fixed_phy_update_regs(struct fixed_phy *fp)
{
u16 bmsr = BMSR_ANEGCAPABLE;
u16 bmcr = 0;
u16 lpagb = 0;
u16 lpa = 0;
if (fp->status.duplex) {
bmcr |= BMCR_FULLDPLX;
switch (fp->status.speed) {
case 1000:
bmsr |= BMSR_ESTATEN;
bmcr |= BMCR_SPEED1000;
lpagb |= LPA_1000FULL;
break;
case 100:
bmsr |= BMSR_100FULL;
bmcr |= BMCR_SPEED100;
lpa |= LPA_100FULL;
break;
case 10:
bmsr |= BMSR_10FULL;
lpa |= LPA_10FULL;
break;
default:
pr_warn("fixed phy: unknown speed\n");
return -EINVAL;
}
} else {
switch (fp->status.speed) {
case 1000:
bmsr |= BMSR_ESTATEN;
bmcr |= BMCR_SPEED1000;
lpagb |= LPA_1000HALF;
break;
case 100:
bmsr |= BMSR_100HALF;
bmcr |= BMCR_SPEED100;
lpa |= LPA_100HALF;
break;
case 10:
bmsr |= BMSR_10HALF;
lpa |= LPA_10HALF;
break;
default:
pr_warn("fixed phy: unknown speed\n");
return -EINVAL;
}
}
if (fp->status.link)
bmsr |= BMSR_LSTATUS | BMSR_ANEGCOMPLETE;
if (fp->status.pause)
lpa |= LPA_PAUSE_CAP;
if (fp->status.asym_pause)
lpa |= LPA_PAUSE_ASYM;
fp->regs[MII_PHYSID1] = 0;
fp->regs[MII_PHYSID2] = 0;
fp->regs[MII_BMSR] = bmsr;
fp->regs[MII_BMCR] = bmcr;
fp->regs[MII_LPA] = lpa;
fp->regs[MII_STAT1000] = lpagb;
return 0;
}
static int fixed_mdio_read(struct mii_bus *bus, int phy_addr, int reg_num)
{
struct fixed_mdio_bus *fmb = bus->priv;
struct fixed_phy *fp;
if (reg_num >= MII_REGS_NUM)
return -1;
switch (reg_num) {
case MII_MMD_CTRL:
case MII_MMD_DATA:
return -1;
default:
break;
}
list_for_each_entry(fp, &fmb->phys, node) {
if (fp->addr == phy_addr) {
if (fp->link_update) {
fp->link_update(fp->phydev->attached_dev,
&fp->status);
fixed_phy_update_regs(fp);
}
return fp->regs[reg_num];
}
}
return 0xFFFF;
}
static int fixed_mdio_write(struct mii_bus *bus, int phy_addr, int reg_num,
u16 val)
{
return 0;
}
int fixed_phy_set_link_update(struct phy_device *phydev,
int (*link_update)(struct net_device *,
struct fixed_phy_status *))
{
struct fixed_mdio_bus *fmb = &platform_fmb;
struct fixed_phy *fp;
if (!phydev || !phydev->bus)
return -EINVAL;
list_for_each_entry(fp, &fmb->phys, node) {
if (fp->addr == phydev->addr) {
fp->link_update = link_update;
fp->phydev = phydev;
return 0;
}
}
return -ENOENT;
}
int fixed_phy_add(unsigned int irq, int phy_addr,
struct fixed_phy_status *status)
{
int ret;
struct fixed_mdio_bus *fmb = &platform_fmb;
struct fixed_phy *fp;
fp = kzalloc(sizeof(*fp), GFP_KERNEL);
if (!fp)
return -ENOMEM;
memset(fp->regs, 0xFF, sizeof(fp->regs[0]) * MII_REGS_NUM);
fmb->irqs[phy_addr] = irq;
fp->addr = phy_addr;
fp->status = *status;
ret = fixed_phy_update_regs(fp);
if (ret)
goto err_regs;
list_add_tail(&fp->node, &fmb->phys);
return 0;
err_regs:
kfree(fp);
return ret;
}
void fixed_phy_del(int phy_addr)
{
struct fixed_mdio_bus *fmb = &platform_fmb;
struct fixed_phy *fp, *tmp;
list_for_each_entry_safe(fp, tmp, &fmb->phys, node) {
if (fp->addr == phy_addr) {
list_del(&fp->node);
kfree(fp);
return;
}
}
}
struct phy_device *fixed_phy_register(unsigned int irq,
struct fixed_phy_status *status,
struct device_node *np)
{
struct fixed_mdio_bus *fmb = &platform_fmb;
struct phy_device *phy;
int phy_addr;
int ret;
spin_lock(&phy_fixed_addr_lock);
if (phy_fixed_addr == PHY_MAX_ADDR) {
spin_unlock(&phy_fixed_addr_lock);
return ERR_PTR(-ENOSPC);
}
phy_addr = phy_fixed_addr++;
spin_unlock(&phy_fixed_addr_lock);
ret = fixed_phy_add(PHY_POLL, phy_addr, status);
if (ret < 0)
return ERR_PTR(ret);
phy = get_phy_device(fmb->mii_bus, phy_addr, false);
if (!phy || IS_ERR(phy)) {
fixed_phy_del(phy_addr);
return ERR_PTR(-EINVAL);
}
of_node_get(np);
phy->dev.of_node = np;
ret = phy_device_register(phy);
if (ret) {
phy_device_free(phy);
of_node_put(np);
fixed_phy_del(phy_addr);
return ERR_PTR(ret);
}
return phy;
}
static int __init fixed_mdio_bus_init(void)
{
struct fixed_mdio_bus *fmb = &platform_fmb;
int ret;
pdev = platform_device_register_simple("Fixed MDIO bus", 0, NULL, 0);
if (IS_ERR(pdev)) {
ret = PTR_ERR(pdev);
goto err_pdev;
}
fmb->mii_bus = mdiobus_alloc();
if (fmb->mii_bus == NULL) {
ret = -ENOMEM;
goto err_mdiobus_reg;
}
snprintf(fmb->mii_bus->id, MII_BUS_ID_SIZE, "fixed-0");
fmb->mii_bus->name = "Fixed MDIO Bus";
fmb->mii_bus->priv = fmb;
fmb->mii_bus->parent = &pdev->dev;
fmb->mii_bus->read = &fixed_mdio_read;
fmb->mii_bus->write = &fixed_mdio_write;
fmb->mii_bus->irq = fmb->irqs;
ret = mdiobus_register(fmb->mii_bus);
if (ret)
goto err_mdiobus_alloc;
return 0;
err_mdiobus_alloc:
mdiobus_free(fmb->mii_bus);
err_mdiobus_reg:
platform_device_unregister(pdev);
err_pdev:
return ret;
}
static void __exit fixed_mdio_bus_exit(void)
{
struct fixed_mdio_bus *fmb = &platform_fmb;
struct fixed_phy *fp, *tmp;
mdiobus_unregister(fmb->mii_bus);
mdiobus_free(fmb->mii_bus);
platform_device_unregister(pdev);
list_for_each_entry_safe(fp, tmp, &fmb->phys, node) {
list_del(&fp->node);
kfree(fp);
}
}
