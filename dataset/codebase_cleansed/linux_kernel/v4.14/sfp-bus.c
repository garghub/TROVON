int sfp_parse_port(struct sfp_bus *bus, const struct sfp_eeprom_id *id,
unsigned long *support)
{
int port;
switch (id->base.connector) {
case SFP_CONNECTOR_SC:
case SFP_CONNECTOR_FIBERJACK:
case SFP_CONNECTOR_LC:
case SFP_CONNECTOR_MT_RJ:
case SFP_CONNECTOR_MU:
case SFP_CONNECTOR_OPTICAL_PIGTAIL:
if (support)
phylink_set(support, FIBRE);
port = PORT_FIBRE;
break;
case SFP_CONNECTOR_RJ45:
if (support)
phylink_set(support, TP);
port = PORT_TP;
break;
case SFP_CONNECTOR_UNSPEC:
if (id->base.e1000_base_t) {
if (support)
phylink_set(support, TP);
port = PORT_TP;
break;
}
case SFP_CONNECTOR_SG:
case SFP_CONNECTOR_MPO_1X12:
case SFP_CONNECTOR_MPO_2X16:
case SFP_CONNECTOR_HSSDC_II:
case SFP_CONNECTOR_COPPER_PIGTAIL:
case SFP_CONNECTOR_NOSEPARATE:
case SFP_CONNECTOR_MXC_2X16:
port = PORT_OTHER;
break;
default:
dev_warn(bus->sfp_dev, "SFP: unknown connector id 0x%02x\n",
id->base.connector);
port = PORT_OTHER;
break;
}
return port;
}
phy_interface_t sfp_parse_interface(struct sfp_bus *bus,
const struct sfp_eeprom_id *id)
{
phy_interface_t iface;
switch (id->base.encoding) {
case SFP_ENCODING_8472_64B66B:
iface = PHY_INTERFACE_MODE_10GKR;
break;
case SFP_ENCODING_8B10B:
if (!id->base.e1000_base_t &&
!id->base.e100_base_lx &&
!id->base.e100_base_fx)
iface = PHY_INTERFACE_MODE_1000BASEX;
else
iface = PHY_INTERFACE_MODE_SGMII;
break;
default:
iface = PHY_INTERFACE_MODE_NA;
dev_err(bus->sfp_dev,
"SFP module encoding does not support 8b10b nor 64b66b\n");
break;
}
return iface;
}
void sfp_parse_support(struct sfp_bus *bus, const struct sfp_eeprom_id *id,
unsigned long *support)
{
phylink_set(support, Autoneg);
phylink_set(support, Pause);
phylink_set(support, Asym_Pause);
if (id->base.e10g_base_sr)
phylink_set(support, 10000baseSR_Full);
if (id->base.e10g_base_lr)
phylink_set(support, 10000baseLR_Full);
if (id->base.e10g_base_lrm)
phylink_set(support, 10000baseLRM_Full);
if (id->base.e10g_base_er)
phylink_set(support, 10000baseER_Full);
if (id->base.e1000_base_sx ||
id->base.e1000_base_lx ||
id->base.e1000_base_cx)
phylink_set(support, 1000baseX_Full);
if (id->base.e1000_base_t) {
phylink_set(support, 1000baseT_Half);
phylink_set(support, 1000baseT_Full);
}
switch (id->base.extended_cc) {
case 0x00:
break;
case 0x02:
phylink_set(support, 100000baseSR4_Full);
phylink_set(support, 25000baseSR_Full);
break;
case 0x03:
case 0x04:
phylink_set(support, 100000baseLR4_ER4_Full);
break;
case 0x0b:
case 0x0c:
case 0x0d:
phylink_set(support, 100000baseCR4_Full);
phylink_set(support, 25000baseCR_Full);
break;
default:
dev_warn(bus->sfp_dev,
"Unknown/unsupported extended compliance code: 0x%02x\n",
id->base.extended_cc);
break;
}
if (id->base.fc_speed_100 ||
id->base.fc_speed_200 ||
id->base.fc_speed_400) {
if (id->base.br_nominal >= 31)
phylink_set(support, 2500baseX_Full);
if (id->base.br_nominal >= 12)
phylink_set(support, 1000baseX_Full);
}
switch (id->base.connector) {
case SFP_CONNECTOR_SC:
case SFP_CONNECTOR_FIBERJACK:
case SFP_CONNECTOR_LC:
case SFP_CONNECTOR_MT_RJ:
case SFP_CONNECTOR_MU:
case SFP_CONNECTOR_OPTICAL_PIGTAIL:
break;
case SFP_CONNECTOR_UNSPEC:
if (id->base.e1000_base_t)
break;
case SFP_CONNECTOR_SG:
case SFP_CONNECTOR_MPO_1X12:
case SFP_CONNECTOR_MPO_2X16:
case SFP_CONNECTOR_HSSDC_II:
case SFP_CONNECTOR_COPPER_PIGTAIL:
case SFP_CONNECTOR_NOSEPARATE:
case SFP_CONNECTOR_MXC_2X16:
default:
dev_warn(bus->sfp_dev,
"Guessing link modes, please report...\n");
phylink_set(support, 1000baseT_Half);
phylink_set(support, 1000baseT_Full);
break;
}
}
static const struct sfp_upstream_ops *sfp_get_upstream_ops(struct sfp_bus *bus)
{
return bus->registered ? bus->upstream_ops : NULL;
}
static struct sfp_bus *sfp_bus_get(struct device_node *np)
{
struct sfp_bus *sfp, *new, *found = NULL;
new = kzalloc(sizeof(*new), GFP_KERNEL);
mutex_lock(&sfp_mutex);
list_for_each_entry(sfp, &sfp_buses, node) {
if (sfp->device_node == np) {
kref_get(&sfp->kref);
found = sfp;
break;
}
}
if (!found && new) {
kref_init(&new->kref);
new->device_node = np;
list_add(&new->node, &sfp_buses);
found = new;
new = NULL;
}
mutex_unlock(&sfp_mutex);
kfree(new);
return found;
}
static void sfp_bus_release(struct kref *kref) __releases(sfp_mutex)
{
struct sfp_bus *bus = container_of(kref, struct sfp_bus, kref);
list_del(&bus->node);
mutex_unlock(&sfp_mutex);
kfree(bus);
}
static void sfp_bus_put(struct sfp_bus *bus)
{
kref_put_mutex(&bus->kref, sfp_bus_release, &sfp_mutex);
}
static int sfp_register_bus(struct sfp_bus *bus)
{
const struct sfp_upstream_ops *ops = bus->upstream_ops;
int ret;
if (ops) {
if (ops->link_down)
ops->link_down(bus->upstream);
if (ops->connect_phy && bus->phydev) {
ret = ops->connect_phy(bus->upstream, bus->phydev);
if (ret)
return ret;
}
}
if (bus->started)
bus->socket_ops->start(bus->sfp);
bus->registered = true;
return 0;
}
static void sfp_unregister_bus(struct sfp_bus *bus)
{
const struct sfp_upstream_ops *ops = bus->upstream_ops;
if (bus->registered) {
if (bus->started)
bus->socket_ops->stop(bus->sfp);
if (bus->phydev && ops && ops->disconnect_phy)
ops->disconnect_phy(bus->upstream);
}
bus->registered = false;
}
int sfp_get_module_info(struct sfp_bus *bus, struct ethtool_modinfo *modinfo)
{
if (!bus->registered)
return -ENOIOCTLCMD;
return bus->socket_ops->module_info(bus->sfp, modinfo);
}
int sfp_get_module_eeprom(struct sfp_bus *bus, struct ethtool_eeprom *ee,
u8 *data)
{
if (!bus->registered)
return -ENOIOCTLCMD;
return bus->socket_ops->module_eeprom(bus->sfp, ee, data);
}
void sfp_upstream_start(struct sfp_bus *bus)
{
if (bus->registered)
bus->socket_ops->start(bus->sfp);
bus->started = true;
}
void sfp_upstream_stop(struct sfp_bus *bus)
{
if (bus->registered)
bus->socket_ops->stop(bus->sfp);
bus->started = false;
}
struct sfp_bus *sfp_register_upstream(struct device_node *np,
struct net_device *ndev, void *upstream,
const struct sfp_upstream_ops *ops)
{
struct sfp_bus *bus = sfp_bus_get(np);
int ret = 0;
if (bus) {
rtnl_lock();
bus->upstream_ops = ops;
bus->upstream = upstream;
bus->netdev = ndev;
if (bus->sfp)
ret = sfp_register_bus(bus);
rtnl_unlock();
}
if (ret) {
sfp_bus_put(bus);
bus = NULL;
}
return bus;
}
void sfp_unregister_upstream(struct sfp_bus *bus)
{
rtnl_lock();
sfp_unregister_bus(bus);
bus->upstream = NULL;
bus->netdev = NULL;
rtnl_unlock();
sfp_bus_put(bus);
}
int sfp_add_phy(struct sfp_bus *bus, struct phy_device *phydev)
{
const struct sfp_upstream_ops *ops = sfp_get_upstream_ops(bus);
int ret = 0;
if (ops && ops->connect_phy)
ret = ops->connect_phy(bus->upstream, phydev);
if (ret == 0)
bus->phydev = phydev;
return ret;
}
void sfp_remove_phy(struct sfp_bus *bus)
{
const struct sfp_upstream_ops *ops = sfp_get_upstream_ops(bus);
if (ops && ops->disconnect_phy)
ops->disconnect_phy(bus->upstream);
bus->phydev = NULL;
}
void sfp_link_up(struct sfp_bus *bus)
{
const struct sfp_upstream_ops *ops = sfp_get_upstream_ops(bus);
if (ops && ops->link_up)
ops->link_up(bus->upstream);
}
void sfp_link_down(struct sfp_bus *bus)
{
const struct sfp_upstream_ops *ops = sfp_get_upstream_ops(bus);
if (ops && ops->link_down)
ops->link_down(bus->upstream);
}
int sfp_module_insert(struct sfp_bus *bus, const struct sfp_eeprom_id *id)
{
const struct sfp_upstream_ops *ops = sfp_get_upstream_ops(bus);
int ret = 0;
if (ops && ops->module_insert)
ret = ops->module_insert(bus->upstream, id);
return ret;
}
void sfp_module_remove(struct sfp_bus *bus)
{
const struct sfp_upstream_ops *ops = sfp_get_upstream_ops(bus);
if (ops && ops->module_remove)
ops->module_remove(bus->upstream);
}
struct sfp_bus *sfp_register_socket(struct device *dev, struct sfp *sfp,
const struct sfp_socket_ops *ops)
{
struct sfp_bus *bus = sfp_bus_get(dev->of_node);
int ret = 0;
if (bus) {
rtnl_lock();
bus->sfp_dev = dev;
bus->sfp = sfp;
bus->socket_ops = ops;
if (bus->netdev)
ret = sfp_register_bus(bus);
rtnl_unlock();
}
if (ret) {
sfp_bus_put(bus);
bus = NULL;
}
return bus;
}
void sfp_unregister_socket(struct sfp_bus *bus)
{
rtnl_lock();
sfp_unregister_bus(bus);
bus->sfp_dev = NULL;
bus->sfp = NULL;
bus->socket_ops = NULL;
rtnl_unlock();
sfp_bus_put(bus);
}
