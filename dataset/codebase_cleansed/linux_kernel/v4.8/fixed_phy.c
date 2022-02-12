static void fixed_phy_update(struct fixed_phy *fp)
{
if (gpio_is_valid(fp->link_gpio))
fp->status.link = !!gpio_get_value_cansleep(fp->link_gpio);
}
static int fixed_mdio_read(struct mii_bus *bus, int phy_addr, int reg_num)
{
struct fixed_mdio_bus *fmb = bus->priv;
struct fixed_phy *fp;
list_for_each_entry(fp, &fmb->phys, node) {
if (fp->addr == phy_addr) {
struct fixed_phy_status state;
int s;
do {
s = read_seqcount_begin(&fp->seqcount);
if (fp->link_update) {
fp->link_update(fp->phydev->attached_dev,
&fp->status);
fixed_phy_update(fp);
}
state = fp->status;
} while (read_seqcount_retry(&fp->seqcount, s));
return swphy_read_reg(reg_num, &state);
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
if (!phydev || !phydev->mdio.bus)
return -EINVAL;
list_for_each_entry(fp, &fmb->phys, node) {
if (fp->addr == phydev->mdio.addr) {
fp->link_update = link_update;
fp->phydev = phydev;
return 0;
}
}
return -ENOENT;
}
int fixed_phy_update_state(struct phy_device *phydev,
const struct fixed_phy_status *status,
const struct fixed_phy_status *changed)
{
struct fixed_mdio_bus *fmb = &platform_fmb;
struct fixed_phy *fp;
if (!phydev || phydev->mdio.bus != fmb->mii_bus)
return -EINVAL;
list_for_each_entry(fp, &fmb->phys, node) {
if (fp->addr == phydev->mdio.addr) {
write_seqcount_begin(&fp->seqcount);
#define _UPD(x) if (changed->x) \
fp->status.x = status->x
_UPD(link);
_UPD(speed);
_UPD(duplex);
_UPD(pause);
_UPD(asym_pause);
#undef _UPD
fixed_phy_update(fp);
write_seqcount_end(&fp->seqcount);
return 0;
}
}
return -ENOENT;
}
int fixed_phy_add(unsigned int irq, int phy_addr,
struct fixed_phy_status *status,
int link_gpio)
{
int ret;
struct fixed_mdio_bus *fmb = &platform_fmb;
struct fixed_phy *fp;
ret = swphy_validate_state(status);
if (ret < 0)
return ret;
fp = kzalloc(sizeof(*fp), GFP_KERNEL);
if (!fp)
return -ENOMEM;
seqcount_init(&fp->seqcount);
if (irq != PHY_POLL)
fmb->mii_bus->irq[phy_addr] = irq;
fp->addr = phy_addr;
fp->status = *status;
fp->link_gpio = link_gpio;
if (gpio_is_valid(fp->link_gpio)) {
ret = gpio_request_one(fp->link_gpio, GPIOF_DIR_IN,
"fixed-link-gpio-link");
if (ret)
goto err_regs;
}
fixed_phy_update(fp);
list_add_tail(&fp->node, &fmb->phys);
return 0;
err_regs:
kfree(fp);
return ret;
}
static void fixed_phy_del(int phy_addr)
{
struct fixed_mdio_bus *fmb = &platform_fmb;
struct fixed_phy *fp, *tmp;
list_for_each_entry_safe(fp, tmp, &fmb->phys, node) {
if (fp->addr == phy_addr) {
list_del(&fp->node);
if (gpio_is_valid(fp->link_gpio))
gpio_free(fp->link_gpio);
kfree(fp);
ida_simple_remove(&phy_fixed_ida, phy_addr);
return;
}
}
}
struct phy_device *fixed_phy_register(unsigned int irq,
struct fixed_phy_status *status,
int link_gpio,
struct device_node *np)
{
struct fixed_mdio_bus *fmb = &platform_fmb;
struct phy_device *phy;
int phy_addr;
int ret;
if (!fmb->mii_bus || fmb->mii_bus->state != MDIOBUS_REGISTERED)
return ERR_PTR(-EPROBE_DEFER);
phy_addr = ida_simple_get(&phy_fixed_ida, 0, PHY_MAX_ADDR, GFP_KERNEL);
if (phy_addr < 0)
return ERR_PTR(phy_addr);
ret = fixed_phy_add(irq, phy_addr, status, link_gpio);
if (ret < 0) {
ida_simple_remove(&phy_fixed_ida, phy_addr);
return ERR_PTR(ret);
}
phy = get_phy_device(fmb->mii_bus, phy_addr, false);
if (IS_ERR(phy)) {
fixed_phy_del(phy_addr);
return ERR_PTR(-EINVAL);
}
phy->link = status->link;
if (status->link) {
phy->speed = status->speed;
phy->duplex = status->duplex;
phy->pause = status->pause;
phy->asym_pause = status->asym_pause;
}
of_node_get(np);
phy->mdio.dev.of_node = np;
phy->is_pseudo_fixed_link = true;
switch (status->speed) {
case SPEED_1000:
phy->supported = PHY_1000BT_FEATURES;
break;
case SPEED_100:
phy->supported = PHY_100BT_FEATURES;
break;
case SPEED_10:
default:
phy->supported = PHY_10BT_FEATURES;
}
ret = phy_device_register(phy);
if (ret) {
phy_device_free(phy);
of_node_put(np);
fixed_phy_del(phy_addr);
return ERR_PTR(ret);
}
return phy;
}
void fixed_phy_unregister(struct phy_device *phy)
{
phy_device_remove(phy);
fixed_phy_del(phy->mdio.addr);
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
ida_destroy(&phy_fixed_ida);
}
