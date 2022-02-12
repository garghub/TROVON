void phy_device_free(struct phy_device *phydev)
{
put_device(&phydev->mdio.dev);
}
static void phy_mdio_device_free(struct mdio_device *mdiodev)
{
struct phy_device *phydev;
phydev = container_of(mdiodev, struct phy_device, mdio);
phy_device_free(phydev);
}
static void phy_device_release(struct device *dev)
{
kfree(to_phy_device(dev));
}
static void phy_mdio_device_remove(struct mdio_device *mdiodev)
{
struct phy_device *phydev;
phydev = container_of(mdiodev, struct phy_device, mdio);
phy_device_remove(phydev);
}
static bool mdio_bus_phy_may_suspend(struct phy_device *phydev)
{
struct device_driver *drv = phydev->mdio.dev.driver;
struct phy_driver *phydrv = to_phy_driver(drv);
struct net_device *netdev = phydev->attached_dev;
if (!drv || !phydrv->suspend)
return false;
if (!netdev)
return !phydev->suspended;
if (netdev->dev.parent && device_may_wakeup(netdev->dev.parent))
return false;
if (device_may_wakeup(&netdev->dev))
return false;
return true;
}
static int mdio_bus_phy_suspend(struct device *dev)
{
struct phy_device *phydev = to_phy_device(dev);
if (phydev->attached_dev && phydev->adjust_link)
phy_stop_machine(phydev);
if (!mdio_bus_phy_may_suspend(phydev))
return 0;
return phy_suspend(phydev);
}
static int mdio_bus_phy_resume(struct device *dev)
{
struct phy_device *phydev = to_phy_device(dev);
int ret;
if (!mdio_bus_phy_may_suspend(phydev))
goto no_resume;
ret = phy_resume(phydev);
if (ret < 0)
return ret;
no_resume:
if (phydev->attached_dev && phydev->adjust_link)
phy_start_machine(phydev);
return 0;
}
static int mdio_bus_phy_restore(struct device *dev)
{
struct phy_device *phydev = to_phy_device(dev);
struct net_device *netdev = phydev->attached_dev;
int ret;
if (!netdev)
return 0;
ret = phy_init_hw(phydev);
if (ret < 0)
return ret;
phydev->link = 0;
phydev->state = PHY_UP;
phy_start_machine(phydev);
return 0;
}
int phy_register_fixup(const char *bus_id, u32 phy_uid, u32 phy_uid_mask,
int (*run)(struct phy_device *))
{
struct phy_fixup *fixup = kzalloc(sizeof(*fixup), GFP_KERNEL);
if (!fixup)
return -ENOMEM;
strlcpy(fixup->bus_id, bus_id, sizeof(fixup->bus_id));
fixup->phy_uid = phy_uid;
fixup->phy_uid_mask = phy_uid_mask;
fixup->run = run;
mutex_lock(&phy_fixup_lock);
list_add_tail(&fixup->list, &phy_fixup_list);
mutex_unlock(&phy_fixup_lock);
return 0;
}
int phy_register_fixup_for_uid(u32 phy_uid, u32 phy_uid_mask,
int (*run)(struct phy_device *))
{
return phy_register_fixup(PHY_ANY_ID, phy_uid, phy_uid_mask, run);
}
int phy_register_fixup_for_id(const char *bus_id,
int (*run)(struct phy_device *))
{
return phy_register_fixup(bus_id, PHY_ANY_UID, 0xffffffff, run);
}
int phy_unregister_fixup(const char *bus_id, u32 phy_uid, u32 phy_uid_mask)
{
struct list_head *pos, *n;
struct phy_fixup *fixup;
int ret;
ret = -ENODEV;
mutex_lock(&phy_fixup_lock);
list_for_each_safe(pos, n, &phy_fixup_list) {
fixup = list_entry(pos, struct phy_fixup, list);
if ((!strcmp(fixup->bus_id, bus_id)) &&
((fixup->phy_uid & phy_uid_mask) ==
(phy_uid & phy_uid_mask))) {
list_del(&fixup->list);
kfree(fixup);
ret = 0;
break;
}
}
mutex_unlock(&phy_fixup_lock);
return ret;
}
int phy_unregister_fixup_for_uid(u32 phy_uid, u32 phy_uid_mask)
{
return phy_unregister_fixup(PHY_ANY_ID, phy_uid, phy_uid_mask);
}
int phy_unregister_fixup_for_id(const char *bus_id)
{
return phy_unregister_fixup(bus_id, PHY_ANY_UID, 0xffffffff);
}
static int phy_needs_fixup(struct phy_device *phydev, struct phy_fixup *fixup)
{
if (strcmp(fixup->bus_id, phydev_name(phydev)) != 0)
if (strcmp(fixup->bus_id, PHY_ANY_ID) != 0)
return 0;
if ((fixup->phy_uid & fixup->phy_uid_mask) !=
(phydev->phy_id & fixup->phy_uid_mask))
if (fixup->phy_uid != PHY_ANY_UID)
return 0;
return 1;
}
static int phy_scan_fixups(struct phy_device *phydev)
{
struct phy_fixup *fixup;
mutex_lock(&phy_fixup_lock);
list_for_each_entry(fixup, &phy_fixup_list, list) {
if (phy_needs_fixup(phydev, fixup)) {
int err = fixup->run(phydev);
if (err < 0) {
mutex_unlock(&phy_fixup_lock);
return err;
}
phydev->has_fixups = true;
}
}
mutex_unlock(&phy_fixup_lock);
return 0;
}
static int phy_bus_match(struct device *dev, struct device_driver *drv)
{
struct phy_device *phydev = to_phy_device(dev);
struct phy_driver *phydrv = to_phy_driver(drv);
const int num_ids = ARRAY_SIZE(phydev->c45_ids.device_ids);
int i;
if (!(phydrv->mdiodrv.flags & MDIO_DEVICE_IS_PHY))
return 0;
if (phydrv->match_phy_device)
return phydrv->match_phy_device(phydev);
if (phydev->is_c45) {
for (i = 1; i < num_ids; i++) {
if (!(phydev->c45_ids.devices_in_package & (1 << i)))
continue;
if ((phydrv->phy_id & phydrv->phy_id_mask) ==
(phydev->c45_ids.device_ids[i] &
phydrv->phy_id_mask))
return 1;
}
return 0;
} else {
return (phydrv->phy_id & phydrv->phy_id_mask) ==
(phydev->phy_id & phydrv->phy_id_mask);
}
}
struct phy_device *phy_device_create(struct mii_bus *bus, int addr, int phy_id,
bool is_c45,
struct phy_c45_device_ids *c45_ids)
{
struct phy_device *dev;
struct mdio_device *mdiodev;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return ERR_PTR(-ENOMEM);
mdiodev = &dev->mdio;
mdiodev->dev.release = phy_device_release;
mdiodev->dev.parent = &bus->dev;
mdiodev->dev.bus = &mdio_bus_type;
mdiodev->bus = bus;
mdiodev->pm_ops = MDIO_BUS_PHY_PM_OPS;
mdiodev->bus_match = phy_bus_match;
mdiodev->addr = addr;
mdiodev->flags = MDIO_DEVICE_FLAG_PHY;
mdiodev->device_free = phy_mdio_device_free;
mdiodev->device_remove = phy_mdio_device_remove;
dev->speed = 0;
dev->duplex = -1;
dev->pause = 0;
dev->asym_pause = 0;
dev->link = 1;
dev->interface = PHY_INTERFACE_MODE_GMII;
dev->autoneg = AUTONEG_ENABLE;
dev->is_c45 = is_c45;
dev->phy_id = phy_id;
if (c45_ids)
dev->c45_ids = *c45_ids;
dev->irq = bus->irq[addr];
dev_set_name(&mdiodev->dev, PHY_ID_FMT, bus->id, addr);
dev->state = PHY_DOWN;
mutex_init(&dev->lock);
INIT_DELAYED_WORK(&dev->state_queue, phy_state_machine);
INIT_WORK(&dev->phy_queue, phy_change_work);
request_module(MDIO_MODULE_PREFIX MDIO_ID_FMT, MDIO_ID_ARGS(phy_id));
device_initialize(&mdiodev->dev);
return dev;
}
static int get_phy_c45_devs_in_pkg(struct mii_bus *bus, int addr, int dev_addr,
u32 *devices_in_package)
{
int phy_reg, reg_addr;
reg_addr = MII_ADDR_C45 | dev_addr << 16 | MDIO_DEVS2;
phy_reg = mdiobus_read(bus, addr, reg_addr);
if (phy_reg < 0)
return -EIO;
*devices_in_package = (phy_reg & 0xffff) << 16;
reg_addr = MII_ADDR_C45 | dev_addr << 16 | MDIO_DEVS1;
phy_reg = mdiobus_read(bus, addr, reg_addr);
if (phy_reg < 0)
return -EIO;
*devices_in_package |= (phy_reg & 0xffff);
return 0;
}
static int get_phy_c45_ids(struct mii_bus *bus, int addr, u32 *phy_id,
struct phy_c45_device_ids *c45_ids) {
int phy_reg;
int i, reg_addr;
const int num_ids = ARRAY_SIZE(c45_ids->device_ids);
u32 *devs = &c45_ids->devices_in_package;
for (i = 1; i < num_ids && *devs == 0; i++) {
phy_reg = get_phy_c45_devs_in_pkg(bus, addr, i, devs);
if (phy_reg < 0)
return -EIO;
if ((*devs & 0x1fffffff) == 0x1fffffff) {
phy_reg = get_phy_c45_devs_in_pkg(bus, addr, 0, devs);
if (phy_reg < 0)
return -EIO;
if ((*devs & 0x1fffffff) == 0x1fffffff) {
*phy_id = 0xffffffff;
return 0;
} else {
break;
}
}
}
for (i = 1; i < num_ids; i++) {
if (!(c45_ids->devices_in_package & (1 << i)))
continue;
reg_addr = MII_ADDR_C45 | i << 16 | MII_PHYSID1;
phy_reg = mdiobus_read(bus, addr, reg_addr);
if (phy_reg < 0)
return -EIO;
c45_ids->device_ids[i] = (phy_reg & 0xffff) << 16;
reg_addr = MII_ADDR_C45 | i << 16 | MII_PHYSID2;
phy_reg = mdiobus_read(bus, addr, reg_addr);
if (phy_reg < 0)
return -EIO;
c45_ids->device_ids[i] |= (phy_reg & 0xffff);
}
*phy_id = 0;
return 0;
}
static int get_phy_id(struct mii_bus *bus, int addr, u32 *phy_id,
bool is_c45, struct phy_c45_device_ids *c45_ids)
{
int phy_reg;
if (is_c45)
return get_phy_c45_ids(bus, addr, phy_id, c45_ids);
phy_reg = mdiobus_read(bus, addr, MII_PHYSID1);
if (phy_reg < 0)
return -EIO;
*phy_id = (phy_reg & 0xffff) << 16;
phy_reg = mdiobus_read(bus, addr, MII_PHYSID2);
if (phy_reg < 0)
return -EIO;
*phy_id |= (phy_reg & 0xffff);
return 0;
}
struct phy_device *get_phy_device(struct mii_bus *bus, int addr, bool is_c45)
{
struct phy_c45_device_ids c45_ids = {0};
u32 phy_id = 0;
int r;
r = get_phy_id(bus, addr, &phy_id, is_c45, &c45_ids);
if (r)
return ERR_PTR(r);
if ((phy_id & 0x1fffffff) == 0x1fffffff)
return ERR_PTR(-ENODEV);
return phy_device_create(bus, addr, phy_id, is_c45, &c45_ids);
}
static ssize_t
phy_id_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct phy_device *phydev = to_phy_device(dev);
return sprintf(buf, "0x%.8lx\n", (unsigned long)phydev->phy_id);
}
static ssize_t
phy_interface_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct phy_device *phydev = to_phy_device(dev);
const char *mode = NULL;
if (phy_is_internal(phydev))
mode = "internal";
else
mode = phy_modes(phydev->interface);
return sprintf(buf, "%s\n", mode);
}
static ssize_t
phy_has_fixups_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct phy_device *phydev = to_phy_device(dev);
return sprintf(buf, "%d\n", phydev->has_fixups);
}
int phy_device_register(struct phy_device *phydev)
{
int err;
err = mdiobus_register_device(&phydev->mdio);
if (err)
return err;
err = phy_scan_fixups(phydev);
if (err) {
pr_err("PHY %d failed to initialize\n", phydev->mdio.addr);
goto out;
}
phydev->mdio.dev.groups = phy_dev_groups;
err = device_add(&phydev->mdio.dev);
if (err) {
pr_err("PHY %d failed to add\n", phydev->mdio.addr);
goto out;
}
return 0;
out:
mdiobus_unregister_device(&phydev->mdio);
return err;
}
void phy_device_remove(struct phy_device *phydev)
{
device_del(&phydev->mdio.dev);
mdiobus_unregister_device(&phydev->mdio);
}
struct phy_device *phy_find_first(struct mii_bus *bus)
{
struct phy_device *phydev;
int addr;
for (addr = 0; addr < PHY_MAX_ADDR; addr++) {
phydev = mdiobus_get_phy(bus, addr);
if (phydev)
return phydev;
}
return NULL;
}
static void phy_link_change(struct phy_device *phydev, bool up, bool do_carrier)
{
struct net_device *netdev = phydev->attached_dev;
if (do_carrier) {
if (up)
netif_carrier_on(netdev);
else
netif_carrier_off(netdev);
}
phydev->adjust_link(netdev);
}
static void phy_prepare_link(struct phy_device *phydev,
void (*handler)(struct net_device *))
{
phydev->adjust_link = handler;
}
int phy_connect_direct(struct net_device *dev, struct phy_device *phydev,
void (*handler)(struct net_device *),
phy_interface_t interface)
{
int rc;
rc = phy_attach_direct(dev, phydev, phydev->dev_flags, interface);
if (rc)
return rc;
phy_prepare_link(phydev, handler);
phy_start_machine(phydev);
if (phydev->irq > 0)
phy_start_interrupts(phydev);
return 0;
}
struct phy_device *phy_connect(struct net_device *dev, const char *bus_id,
void (*handler)(struct net_device *),
phy_interface_t interface)
{
struct phy_device *phydev;
struct device *d;
int rc;
d = bus_find_device_by_name(&mdio_bus_type, NULL, bus_id);
if (!d) {
pr_err("PHY %s not found\n", bus_id);
return ERR_PTR(-ENODEV);
}
phydev = to_phy_device(d);
rc = phy_connect_direct(dev, phydev, handler, interface);
put_device(d);
if (rc)
return ERR_PTR(rc);
return phydev;
}
void phy_disconnect(struct phy_device *phydev)
{
if (phydev->irq > 0)
phy_stop_interrupts(phydev);
phy_stop_machine(phydev);
phydev->adjust_link = NULL;
phy_detach(phydev);
}
static int phy_poll_reset(struct phy_device *phydev)
{
unsigned int retries = 12;
int ret;
do {
msleep(50);
ret = phy_read(phydev, MII_BMCR);
if (ret < 0)
return ret;
} while (ret & BMCR_RESET && --retries);
if (ret & BMCR_RESET)
return -ETIMEDOUT;
msleep(1);
return 0;
}
int phy_init_hw(struct phy_device *phydev)
{
int ret = 0;
if (!phydev->drv || !phydev->drv->config_init)
return 0;
if (phydev->drv->soft_reset)
ret = phydev->drv->soft_reset(phydev);
else
ret = genphy_soft_reset(phydev);
if (ret < 0)
return ret;
ret = phy_scan_fixups(phydev);
if (ret < 0)
return ret;
return phydev->drv->config_init(phydev);
}
void phy_attached_info(struct phy_device *phydev)
{
phy_attached_print(phydev, NULL);
}
void phy_attached_print(struct phy_device *phydev, const char *fmt, ...)
{
const char *drv_name = phydev->drv ? phydev->drv->name : "unbound";
char *irq_str;
char irq_num[8];
switch(phydev->irq) {
case PHY_POLL:
irq_str = "POLL";
break;
case PHY_IGNORE_INTERRUPT:
irq_str = "IGNORE";
break;
default:
snprintf(irq_num, sizeof(irq_num), "%d", phydev->irq);
irq_str = irq_num;
break;
}
if (!fmt) {
dev_info(&phydev->mdio.dev, ATTACHED_FMT "\n",
drv_name, phydev_name(phydev),
irq_str);
} else {
va_list ap;
dev_info(&phydev->mdio.dev, ATTACHED_FMT,
drv_name, phydev_name(phydev),
irq_str);
va_start(ap, fmt);
vprintk(fmt, ap);
va_end(ap);
}
}
int phy_attach_direct(struct net_device *dev, struct phy_device *phydev,
u32 flags, phy_interface_t interface)
{
struct module *ndev_owner = dev->dev.parent->driver->owner;
struct mii_bus *bus = phydev->mdio.bus;
struct device *d = &phydev->mdio.dev;
bool using_genphy = false;
int err;
if (ndev_owner != bus->owner && !try_module_get(bus->owner)) {
dev_err(&dev->dev, "failed to get the bus module\n");
return -EIO;
}
get_device(d);
if (!d->driver) {
if (phydev->is_c45)
d->driver = &genphy_10g_driver.mdiodrv.driver;
else
d->driver = &genphy_driver.mdiodrv.driver;
using_genphy = true;
}
if (!try_module_get(d->driver->owner)) {
dev_err(&dev->dev, "failed to get the device driver module\n");
err = -EIO;
goto error_put_device;
}
if (using_genphy) {
err = d->driver->probe(d);
if (err >= 0)
err = device_bind_driver(d);
if (err)
goto error_module_put;
}
if (phydev->attached_dev) {
dev_err(&dev->dev, "PHY already attached\n");
err = -EBUSY;
goto error;
}
phydev->phy_link_change = phy_link_change;
phydev->attached_dev = dev;
dev->phydev = phydev;
phydev->sysfs_links = false;
err = sysfs_create_link(&phydev->mdio.dev.kobj, &dev->dev.kobj,
"attached_dev");
if (!err) {
err = sysfs_create_link(&dev->dev.kobj, &phydev->mdio.dev.kobj,
"phydev");
if (err)
goto error;
phydev->sysfs_links = true;
}
phydev->dev_flags = flags;
phydev->interface = interface;
phydev->state = PHY_READY;
netif_carrier_off(phydev->attached_dev);
err = phy_init_hw(phydev);
if (err)
goto error;
phy_resume(phydev);
phy_led_triggers_register(phydev);
return err;
error:
phy_detach(phydev);
return err;
error_module_put:
module_put(d->driver->owner);
error_put_device:
put_device(d);
if (ndev_owner != bus->owner)
module_put(bus->owner);
return err;
}
struct phy_device *phy_attach(struct net_device *dev, const char *bus_id,
phy_interface_t interface)
{
struct bus_type *bus = &mdio_bus_type;
struct phy_device *phydev;
struct device *d;
int rc;
d = bus_find_device_by_name(bus, NULL, bus_id);
if (!d) {
pr_err("PHY %s not found\n", bus_id);
return ERR_PTR(-ENODEV);
}
phydev = to_phy_device(d);
rc = phy_attach_direct(dev, phydev, phydev->dev_flags, interface);
put_device(d);
if (rc)
return ERR_PTR(rc);
return phydev;
}
void phy_detach(struct phy_device *phydev)
{
struct net_device *dev = phydev->attached_dev;
struct module *ndev_owner = dev->dev.parent->driver->owner;
struct mii_bus *bus;
if (phydev->sysfs_links) {
sysfs_remove_link(&dev->dev.kobj, "phydev");
sysfs_remove_link(&phydev->mdio.dev.kobj, "attached_dev");
}
phydev->attached_dev->phydev = NULL;
phydev->attached_dev = NULL;
phy_suspend(phydev);
phydev->phylink = NULL;
phy_led_triggers_unregister(phydev);
module_put(phydev->mdio.dev.driver->owner);
if (phydev->mdio.dev.driver == &genphy_10g_driver.mdiodrv.driver ||
phydev->mdio.dev.driver == &genphy_driver.mdiodrv.driver)
device_release_driver(&phydev->mdio.dev);
bus = phydev->mdio.bus;
put_device(&phydev->mdio.dev);
if (ndev_owner != bus->owner)
module_put(bus->owner);
}
int phy_suspend(struct phy_device *phydev)
{
struct phy_driver *phydrv = to_phy_driver(phydev->mdio.dev.driver);
struct ethtool_wolinfo wol = { .cmd = ETHTOOL_GWOL };
int ret = 0;
phy_ethtool_get_wol(phydev, &wol);
if (wol.wolopts)
return -EBUSY;
if (phydev->drv && phydrv->suspend)
ret = phydrv->suspend(phydev);
if (ret)
return ret;
phydev->suspended = true;
return ret;
}
int phy_resume(struct phy_device *phydev)
{
struct phy_driver *phydrv = to_phy_driver(phydev->mdio.dev.driver);
int ret = 0;
if (phydev->drv && phydrv->resume)
ret = phydrv->resume(phydev);
if (ret)
return ret;
phydev->suspended = false;
return ret;
}
int phy_loopback(struct phy_device *phydev, bool enable)
{
struct phy_driver *phydrv = to_phy_driver(phydev->mdio.dev.driver);
int ret = 0;
mutex_lock(&phydev->lock);
if (enable && phydev->loopback_enabled) {
ret = -EBUSY;
goto out;
}
if (!enable && !phydev->loopback_enabled) {
ret = -EINVAL;
goto out;
}
if (phydev->drv && phydrv->set_loopback)
ret = phydrv->set_loopback(phydev, enable);
else
ret = -EOPNOTSUPP;
if (ret)
goto out;
phydev->loopback_enabled = enable;
out:
mutex_unlock(&phydev->lock);
return ret;
}
static int genphy_config_advert(struct phy_device *phydev)
{
u32 advertise;
int oldadv, adv, bmsr;
int err, changed = 0;
phydev->advertising &= phydev->supported;
advertise = phydev->advertising;
adv = phy_read(phydev, MII_ADVERTISE);
if (adv < 0)
return adv;
oldadv = adv;
adv &= ~(ADVERTISE_ALL | ADVERTISE_100BASE4 | ADVERTISE_PAUSE_CAP |
ADVERTISE_PAUSE_ASYM);
adv |= ethtool_adv_to_mii_adv_t(advertise);
if (adv != oldadv) {
err = phy_write(phydev, MII_ADVERTISE, adv);
if (err < 0)
return err;
changed = 1;
}
bmsr = phy_read(phydev, MII_BMSR);
if (bmsr < 0)
return bmsr;
if (!(bmsr & BMSR_ESTATEN))
return changed;
adv = phy_read(phydev, MII_CTRL1000);
if (adv < 0)
return adv;
oldadv = adv;
adv &= ~(ADVERTISE_1000FULL | ADVERTISE_1000HALF);
if (phydev->supported & (SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full)) {
adv |= ethtool_adv_to_mii_ctrl1000_t(advertise);
}
if (adv != oldadv)
changed = 1;
err = phy_write(phydev, MII_CTRL1000, adv);
if (err < 0)
return err;
return changed;
}
static int genphy_config_eee_advert(struct phy_device *phydev)
{
int broken = phydev->eee_broken_modes;
int old_adv, adv;
if (!broken)
return 0;
adv = phy_read_mmd(phydev, MDIO_MMD_AN, MDIO_AN_EEE_ADV);
if (adv <= 0)
return 0;
old_adv = adv;
adv &= ~broken;
if (old_adv == adv)
return 0;
phy_write_mmd(phydev, MDIO_MMD_AN, MDIO_AN_EEE_ADV, adv);
return 1;
}
int genphy_setup_forced(struct phy_device *phydev)
{
int ctl = phy_read(phydev, MII_BMCR);
ctl &= BMCR_LOOPBACK | BMCR_ISOLATE | BMCR_PDOWN;
phydev->pause = 0;
phydev->asym_pause = 0;
if (SPEED_1000 == phydev->speed)
ctl |= BMCR_SPEED1000;
else if (SPEED_100 == phydev->speed)
ctl |= BMCR_SPEED100;
if (DUPLEX_FULL == phydev->duplex)
ctl |= BMCR_FULLDPLX;
return phy_write(phydev, MII_BMCR, ctl);
}
int genphy_restart_aneg(struct phy_device *phydev)
{
int ctl = phy_read(phydev, MII_BMCR);
if (ctl < 0)
return ctl;
ctl |= BMCR_ANENABLE | BMCR_ANRESTART;
ctl &= ~BMCR_ISOLATE;
return phy_write(phydev, MII_BMCR, ctl);
}
int genphy_config_aneg(struct phy_device *phydev)
{
int err, changed;
changed = genphy_config_eee_advert(phydev);
if (AUTONEG_ENABLE != phydev->autoneg)
return genphy_setup_forced(phydev);
err = genphy_config_advert(phydev);
if (err < 0)
return err;
changed |= err;
if (changed == 0) {
int ctl = phy_read(phydev, MII_BMCR);
if (ctl < 0)
return ctl;
if (!(ctl & BMCR_ANENABLE) || (ctl & BMCR_ISOLATE))
changed = 1;
}
if (changed > 0)
return genphy_restart_aneg(phydev);
return 0;
}
int genphy_aneg_done(struct phy_device *phydev)
{
int retval = phy_read(phydev, MII_BMSR);
return (retval < 0) ? retval : (retval & BMSR_ANEGCOMPLETE);
}
int genphy_update_link(struct phy_device *phydev)
{
int status;
status = phy_read(phydev, MII_BMSR);
if (status < 0)
return status;
status = phy_read(phydev, MII_BMSR);
if (status < 0)
return status;
if ((status & BMSR_LSTATUS) == 0)
phydev->link = 0;
else
phydev->link = 1;
return 0;
}
int genphy_read_status(struct phy_device *phydev)
{
int adv;
int err;
int lpa;
int lpagb = 0;
int common_adv;
int common_adv_gb = 0;
err = genphy_update_link(phydev);
if (err)
return err;
phydev->lp_advertising = 0;
if (AUTONEG_ENABLE == phydev->autoneg) {
if (phydev->supported & (SUPPORTED_1000baseT_Half
| SUPPORTED_1000baseT_Full)) {
lpagb = phy_read(phydev, MII_STAT1000);
if (lpagb < 0)
return lpagb;
adv = phy_read(phydev, MII_CTRL1000);
if (adv < 0)
return adv;
phydev->lp_advertising =
mii_stat1000_to_ethtool_lpa_t(lpagb);
common_adv_gb = lpagb & adv << 2;
}
lpa = phy_read(phydev, MII_LPA);
if (lpa < 0)
return lpa;
phydev->lp_advertising |= mii_lpa_to_ethtool_lpa_t(lpa);
adv = phy_read(phydev, MII_ADVERTISE);
if (adv < 0)
return adv;
common_adv = lpa & adv;
phydev->speed = SPEED_10;
phydev->duplex = DUPLEX_HALF;
phydev->pause = 0;
phydev->asym_pause = 0;
if (common_adv_gb & (LPA_1000FULL | LPA_1000HALF)) {
phydev->speed = SPEED_1000;
if (common_adv_gb & LPA_1000FULL)
phydev->duplex = DUPLEX_FULL;
} else if (common_adv & (LPA_100FULL | LPA_100HALF)) {
phydev->speed = SPEED_100;
if (common_adv & LPA_100FULL)
phydev->duplex = DUPLEX_FULL;
} else
if (common_adv & LPA_10FULL)
phydev->duplex = DUPLEX_FULL;
if (phydev->duplex == DUPLEX_FULL) {
phydev->pause = lpa & LPA_PAUSE_CAP ? 1 : 0;
phydev->asym_pause = lpa & LPA_PAUSE_ASYM ? 1 : 0;
}
} else {
int bmcr = phy_read(phydev, MII_BMCR);
if (bmcr < 0)
return bmcr;
if (bmcr & BMCR_FULLDPLX)
phydev->duplex = DUPLEX_FULL;
else
phydev->duplex = DUPLEX_HALF;
if (bmcr & BMCR_SPEED1000)
phydev->speed = SPEED_1000;
else if (bmcr & BMCR_SPEED100)
phydev->speed = SPEED_100;
else
phydev->speed = SPEED_10;
phydev->pause = 0;
phydev->asym_pause = 0;
}
return 0;
}
int genphy_soft_reset(struct phy_device *phydev)
{
int ret;
ret = phy_write(phydev, MII_BMCR, BMCR_RESET);
if (ret < 0)
return ret;
return phy_poll_reset(phydev);
}
int genphy_config_init(struct phy_device *phydev)
{
int val;
u32 features;
features = (SUPPORTED_TP | SUPPORTED_MII
| SUPPORTED_AUI | SUPPORTED_FIBRE |
SUPPORTED_BNC | SUPPORTED_Pause | SUPPORTED_Asym_Pause);
val = phy_read(phydev, MII_BMSR);
if (val < 0)
return val;
if (val & BMSR_ANEGCAPABLE)
features |= SUPPORTED_Autoneg;
if (val & BMSR_100FULL)
features |= SUPPORTED_100baseT_Full;
if (val & BMSR_100HALF)
features |= SUPPORTED_100baseT_Half;
if (val & BMSR_10FULL)
features |= SUPPORTED_10baseT_Full;
if (val & BMSR_10HALF)
features |= SUPPORTED_10baseT_Half;
if (val & BMSR_ESTATEN) {
val = phy_read(phydev, MII_ESTATUS);
if (val < 0)
return val;
if (val & ESTATUS_1000_TFULL)
features |= SUPPORTED_1000baseT_Full;
if (val & ESTATUS_1000_THALF)
features |= SUPPORTED_1000baseT_Half;
}
phydev->supported &= features;
phydev->advertising &= features;
return 0;
}
int genphy_suspend(struct phy_device *phydev)
{
int value;
mutex_lock(&phydev->lock);
value = phy_read(phydev, MII_BMCR);
phy_write(phydev, MII_BMCR, value | BMCR_PDOWN);
mutex_unlock(&phydev->lock);
return 0;
}
int genphy_resume(struct phy_device *phydev)
{
int value;
mutex_lock(&phydev->lock);
value = phy_read(phydev, MII_BMCR);
phy_write(phydev, MII_BMCR, value & ~BMCR_PDOWN);
mutex_unlock(&phydev->lock);
return 0;
}
int genphy_loopback(struct phy_device *phydev, bool enable)
{
int value;
value = phy_read(phydev, MII_BMCR);
if (value < 0)
return value;
if (enable)
value |= BMCR_LOOPBACK;
else
value &= ~BMCR_LOOPBACK;
return phy_write(phydev, MII_BMCR, value);
}
static int __set_phy_supported(struct phy_device *phydev, u32 max_speed)
{
phydev->supported &= PHY_DEFAULT_FEATURES;
switch (max_speed) {
default:
return -ENOTSUPP;
case SPEED_1000:
phydev->supported |= PHY_1000BT_FEATURES;
case SPEED_100:
phydev->supported |= PHY_100BT_FEATURES;
case SPEED_10:
phydev->supported |= PHY_10BT_FEATURES;
}
return 0;
}
int phy_set_max_speed(struct phy_device *phydev, u32 max_speed)
{
int err;
err = __set_phy_supported(phydev, max_speed);
if (err)
return err;
phydev->advertising = phydev->supported;
return 0;
}
static void of_set_phy_supported(struct phy_device *phydev)
{
struct device_node *node = phydev->mdio.dev.of_node;
u32 max_speed;
if (!IS_ENABLED(CONFIG_OF_MDIO))
return;
if (!node)
return;
if (!of_property_read_u32(node, "max-speed", &max_speed))
__set_phy_supported(phydev, max_speed);
}
static void of_set_phy_eee_broken(struct phy_device *phydev)
{
struct device_node *node = phydev->mdio.dev.of_node;
u32 broken = 0;
if (!IS_ENABLED(CONFIG_OF_MDIO))
return;
if (!node)
return;
if (of_property_read_bool(node, "eee-broken-100tx"))
broken |= MDIO_EEE_100TX;
if (of_property_read_bool(node, "eee-broken-1000t"))
broken |= MDIO_EEE_1000T;
if (of_property_read_bool(node, "eee-broken-10gt"))
broken |= MDIO_EEE_10GT;
if (of_property_read_bool(node, "eee-broken-1000kx"))
broken |= MDIO_EEE_1000KX;
if (of_property_read_bool(node, "eee-broken-10gkx4"))
broken |= MDIO_EEE_10GKX4;
if (of_property_read_bool(node, "eee-broken-10gkr"))
broken |= MDIO_EEE_10GKR;
phydev->eee_broken_modes = broken;
}
static int phy_probe(struct device *dev)
{
struct phy_device *phydev = to_phy_device(dev);
struct device_driver *drv = phydev->mdio.dev.driver;
struct phy_driver *phydrv = to_phy_driver(drv);
int err = 0;
phydev->drv = phydrv;
if (!(phydrv->flags & PHY_HAS_INTERRUPT) &&
phy_interrupt_is_valid(phydev))
phydev->irq = PHY_POLL;
if (phydrv->flags & PHY_IS_INTERNAL)
phydev->is_internal = true;
mutex_lock(&phydev->lock);
phydev->supported = phydrv->features;
of_set_phy_supported(phydev);
phydev->advertising = phydev->supported;
of_set_phy_eee_broken(phydev);
if (phydrv->features & (SUPPORTED_Pause | SUPPORTED_Asym_Pause)) {
phydev->supported &= ~(SUPPORTED_Pause | SUPPORTED_Asym_Pause);
phydev->supported |= phydrv->features &
(SUPPORTED_Pause | SUPPORTED_Asym_Pause);
} else {
phydev->supported |= SUPPORTED_Pause | SUPPORTED_Asym_Pause;
}
phydev->state = PHY_READY;
if (phydev->drv->probe)
err = phydev->drv->probe(phydev);
mutex_unlock(&phydev->lock);
return err;
}
static int phy_remove(struct device *dev)
{
struct phy_device *phydev = to_phy_device(dev);
cancel_delayed_work_sync(&phydev->state_queue);
mutex_lock(&phydev->lock);
phydev->state = PHY_DOWN;
mutex_unlock(&phydev->lock);
if (phydev->drv && phydev->drv->remove)
phydev->drv->remove(phydev);
phydev->drv = NULL;
return 0;
}
int phy_driver_register(struct phy_driver *new_driver, struct module *owner)
{
int retval;
new_driver->mdiodrv.flags |= MDIO_DEVICE_IS_PHY;
new_driver->mdiodrv.driver.name = new_driver->name;
new_driver->mdiodrv.driver.bus = &mdio_bus_type;
new_driver->mdiodrv.driver.probe = phy_probe;
new_driver->mdiodrv.driver.remove = phy_remove;
new_driver->mdiodrv.driver.owner = owner;
retval = driver_register(&new_driver->mdiodrv.driver);
if (retval) {
pr_err("%s: Error %d in registering driver\n",
new_driver->name, retval);
return retval;
}
pr_debug("%s: Registered new driver\n", new_driver->name);
return 0;
}
int phy_drivers_register(struct phy_driver *new_driver, int n,
struct module *owner)
{
int i, ret = 0;
for (i = 0; i < n; i++) {
ret = phy_driver_register(new_driver + i, owner);
if (ret) {
while (i-- > 0)
phy_driver_unregister(new_driver + i);
break;
}
}
return ret;
}
void phy_driver_unregister(struct phy_driver *drv)
{
driver_unregister(&drv->mdiodrv.driver);
}
void phy_drivers_unregister(struct phy_driver *drv, int n)
{
int i;
for (i = 0; i < n; i++)
phy_driver_unregister(drv + i);
}
static int __init phy_init(void)
{
int rc;
rc = mdio_bus_init();
if (rc)
return rc;
rc = phy_driver_register(&genphy_10g_driver, THIS_MODULE);
if (rc)
goto err_10g;
rc = phy_driver_register(&genphy_driver, THIS_MODULE);
if (rc) {
phy_driver_unregister(&genphy_10g_driver);
err_10g:
mdio_bus_exit();
}
return rc;
}
static void __exit phy_exit(void)
{
phy_driver_unregister(&genphy_10g_driver);
phy_driver_unregister(&genphy_driver);
mdio_bus_exit();
}
