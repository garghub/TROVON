void register_switch_driver(struct dsa_switch_driver *drv)
{
mutex_lock(&dsa_switch_drivers_mutex);
list_add_tail(&drv->list, &dsa_switch_drivers);
mutex_unlock(&dsa_switch_drivers_mutex);
}
void unregister_switch_driver(struct dsa_switch_driver *drv)
{
mutex_lock(&dsa_switch_drivers_mutex);
list_del_init(&drv->list);
mutex_unlock(&dsa_switch_drivers_mutex);
}
static const struct dsa_switch_ops *
dsa_switch_probe(struct device *parent, struct device *host_dev, int sw_addr,
const char **_name, void **priv)
{
const struct dsa_switch_ops *ret;
struct list_head *list;
const char *name;
ret = NULL;
name = NULL;
mutex_lock(&dsa_switch_drivers_mutex);
list_for_each(list, &dsa_switch_drivers) {
const struct dsa_switch_ops *ops;
struct dsa_switch_driver *drv;
drv = list_entry(list, struct dsa_switch_driver, list);
ops = drv->ops;
name = ops->probe(parent, host_dev, sw_addr, priv);
if (name != NULL) {
ret = ops;
break;
}
}
mutex_unlock(&dsa_switch_drivers_mutex);
*_name = name;
return ret;
}
static int dsa_cpu_dsa_setups(struct dsa_switch *ds)
{
int ret, port;
for (port = 0; port < ds->num_ports; port++) {
if (!(dsa_is_cpu_port(ds, port) || dsa_is_dsa_port(ds, port)))
continue;
ret = dsa_cpu_dsa_setup(&ds->ports[port]);
if (ret)
return ret;
}
return 0;
}
static int dsa_switch_setup_one(struct dsa_switch *ds,
struct net_device *master)
{
const struct dsa_switch_ops *ops = ds->ops;
struct dsa_switch_tree *dst = ds->dst;
struct dsa_chip_data *cd = ds->cd;
bool valid_name_found = false;
int index = ds->index;
int i, ret;
for (i = 0; i < ds->num_ports; i++) {
char *name;
name = cd->port_names[i];
if (name == NULL)
continue;
if (!strcmp(name, "cpu")) {
if (dst->cpu_dp) {
netdev_err(master,
"multiple cpu ports?!\n");
return -EINVAL;
}
dst->cpu_dp = &ds->ports[i];
dst->cpu_dp->netdev = master;
ds->cpu_port_mask |= 1 << i;
} else if (!strcmp(name, "dsa")) {
ds->dsa_port_mask |= 1 << i;
} else {
ds->enabled_port_mask |= 1 << i;
}
valid_name_found = true;
}
if (!valid_name_found && i == ds->num_ports)
return -EINVAL;
ds->phys_mii_mask = ds->enabled_port_mask;
if (dst->cpu_dp->ds == ds) {
enum dsa_tag_protocol tag_protocol;
tag_protocol = ops->get_tag_protocol(ds);
dst->tag_ops = dsa_resolve_tag_protocol(tag_protocol);
if (IS_ERR(dst->tag_ops))
return PTR_ERR(dst->tag_ops);
dst->rcv = dst->tag_ops->rcv;
}
memcpy(ds->rtable, cd->rtable, sizeof(ds->rtable));
ret = ops->setup(ds);
if (ret < 0)
return ret;
ret = dsa_switch_register_notifier(ds);
if (ret)
return ret;
if (ops->set_addr) {
ret = ops->set_addr(ds, master->dev_addr);
if (ret < 0)
return ret;
}
if (!ds->slave_mii_bus && ops->phy_read) {
ds->slave_mii_bus = devm_mdiobus_alloc(ds->dev);
if (!ds->slave_mii_bus)
return -ENOMEM;
dsa_slave_mii_bus_init(ds);
ret = mdiobus_register(ds->slave_mii_bus);
if (ret < 0)
return ret;
}
for (i = 0; i < ds->num_ports; i++) {
ds->ports[i].dn = cd->port_dn[i];
ds->ports[i].cpu_dp = dst->cpu_dp;
if (!(ds->enabled_port_mask & (1 << i)))
continue;
ret = dsa_slave_create(&ds->ports[i], cd->port_names[i]);
if (ret < 0)
netdev_err(master, "[%d]: can't create dsa slave device for port %d(%s): %d\n",
index, i, cd->port_names[i], ret);
}
ret = dsa_cpu_dsa_setups(ds);
if (ret < 0)
netdev_err(master, "[%d] : can't configure CPU and DSA ports\n",
index);
ret = dsa_cpu_port_ethtool_setup(ds->dst->cpu_dp);
if (ret)
return ret;
return 0;
}
static struct dsa_switch *
dsa_switch_setup(struct dsa_switch_tree *dst, struct net_device *master,
int index, struct device *parent, struct device *host_dev)
{
struct dsa_chip_data *cd = dst->pd->chip + index;
const struct dsa_switch_ops *ops;
struct dsa_switch *ds;
int ret;
const char *name;
void *priv;
ops = dsa_switch_probe(parent, host_dev, cd->sw_addr, &name, &priv);
if (!ops) {
netdev_err(master, "[%d]: could not detect attached switch\n",
index);
return ERR_PTR(-EINVAL);
}
netdev_info(master, "[%d]: detected a %s switch\n",
index, name);
ds = dsa_switch_alloc(parent, DSA_MAX_PORTS);
if (!ds)
return ERR_PTR(-ENOMEM);
ds->dst = dst;
ds->index = index;
ds->cd = cd;
ds->ops = ops;
ds->priv = priv;
ret = dsa_switch_setup_one(ds, master);
if (ret)
return ERR_PTR(ret);
return ds;
}
static void dsa_switch_destroy(struct dsa_switch *ds)
{
int port;
for (port = 0; port < ds->num_ports; port++) {
if (!(ds->enabled_port_mask & (1 << port)))
continue;
if (!ds->ports[port].netdev)
continue;
dsa_slave_destroy(ds->ports[port].netdev);
}
for (port = 0; port < ds->num_ports; port++) {
if (!(dsa_is_cpu_port(ds, port) || dsa_is_dsa_port(ds, port)))
continue;
dsa_cpu_dsa_destroy(&ds->ports[port]);
ds->cpu_port_mask |= ~(1 << port);
ds->dsa_port_mask |= ~(1 << port);
}
if (ds->slave_mii_bus && ds->ops->phy_read)
mdiobus_unregister(ds->slave_mii_bus);
dsa_switch_unregister_notifier(ds);
}
static int dev_is_class(struct device *dev, void *class)
{
if (dev->class != NULL && !strcmp(dev->class->name, class))
return 1;
return 0;
}
static struct device *dev_find_class(struct device *parent, char *class)
{
if (dev_is_class(parent, class)) {
get_device(parent);
return parent;
}
return device_find_child(parent, class, dev_is_class);
}
struct mii_bus *dsa_host_dev_to_mii_bus(struct device *dev)
{
struct device *d;
d = dev_find_class(dev, "mdio_bus");
if (d != NULL) {
struct mii_bus *bus;
bus = to_mii_bus(d);
put_device(d);
return bus;
}
return NULL;
}
static int dsa_of_setup_routing_table(struct dsa_platform_data *pd,
struct dsa_chip_data *cd,
int chip_index, int port_index,
struct device_node *link)
{
const __be32 *reg;
int link_sw_addr;
struct device_node *parent_sw;
int len;
parent_sw = of_get_parent(link);
if (!parent_sw)
return -EINVAL;
reg = of_get_property(parent_sw, "reg", &len);
if (!reg || (len != sizeof(*reg) * 2))
return -EINVAL;
link_sw_addr = be32_to_cpup(reg + 1);
if (link_sw_addr >= pd->nr_chips)
return -EINVAL;
cd->rtable[link_sw_addr] = port_index;
return 0;
}
static int dsa_of_probe_links(struct dsa_platform_data *pd,
struct dsa_chip_data *cd,
int chip_index, int port_index,
struct device_node *port,
const char *port_name)
{
struct device_node *link;
int link_index;
int ret;
for (link_index = 0;; link_index++) {
link = of_parse_phandle(port, "link", link_index);
if (!link)
break;
if (!strcmp(port_name, "dsa") && pd->nr_chips > 1) {
ret = dsa_of_setup_routing_table(pd, cd, chip_index,
port_index, link);
if (ret)
return ret;
}
}
return 0;
}
static void dsa_of_free_platform_data(struct dsa_platform_data *pd)
{
int i;
int port_index;
for (i = 0; i < pd->nr_chips; i++) {
port_index = 0;
while (port_index < DSA_MAX_PORTS) {
kfree(pd->chip[i].port_names[port_index]);
port_index++;
}
if (pd->chip[i].host_dev)
put_device(pd->chip[i].host_dev);
}
kfree(pd->chip);
}
static int dsa_of_probe(struct device *dev)
{
struct device_node *np = dev->of_node;
struct device_node *child, *mdio, *ethernet, *port;
struct mii_bus *mdio_bus, *mdio_bus_switch;
struct net_device *ethernet_dev;
struct dsa_platform_data *pd;
struct dsa_chip_data *cd;
const char *port_name;
int chip_index, port_index;
const unsigned int *sw_addr, *port_reg;
u32 eeprom_len;
int ret;
mdio = of_parse_phandle(np, "dsa,mii-bus", 0);
if (!mdio)
return -EINVAL;
mdio_bus = of_mdio_find_bus(mdio);
if (!mdio_bus)
return -EPROBE_DEFER;
ethernet = of_parse_phandle(np, "dsa,ethernet", 0);
if (!ethernet) {
ret = -EINVAL;
goto out_put_mdio;
}
ethernet_dev = of_find_net_device_by_node(ethernet);
if (!ethernet_dev) {
ret = -EPROBE_DEFER;
goto out_put_mdio;
}
pd = kzalloc(sizeof(*pd), GFP_KERNEL);
if (!pd) {
ret = -ENOMEM;
goto out_put_ethernet;
}
dev->platform_data = pd;
pd->of_netdev = ethernet_dev;
pd->nr_chips = of_get_available_child_count(np);
if (pd->nr_chips > DSA_MAX_SWITCHES)
pd->nr_chips = DSA_MAX_SWITCHES;
pd->chip = kcalloc(pd->nr_chips, sizeof(struct dsa_chip_data),
GFP_KERNEL);
if (!pd->chip) {
ret = -ENOMEM;
goto out_free;
}
chip_index = -1;
for_each_available_child_of_node(np, child) {
int i;
chip_index++;
cd = &pd->chip[chip_index];
cd->of_node = child;
for (i = 0; i < DSA_MAX_SWITCHES; ++i)
cd->rtable[i] = DSA_RTABLE_NONE;
cd->host_dev = get_device(&mdio_bus->dev);
sw_addr = of_get_property(child, "reg", NULL);
if (!sw_addr)
continue;
cd->sw_addr = be32_to_cpup(sw_addr);
if (cd->sw_addr >= PHY_MAX_ADDR)
continue;
if (!of_property_read_u32(child, "eeprom-length", &eeprom_len))
cd->eeprom_len = eeprom_len;
mdio = of_parse_phandle(child, "mii-bus", 0);
if (mdio) {
mdio_bus_switch = of_mdio_find_bus(mdio);
if (!mdio_bus_switch) {
ret = -EPROBE_DEFER;
goto out_free_chip;
}
put_device(cd->host_dev);
cd->host_dev = &mdio_bus_switch->dev;
}
for_each_available_child_of_node(child, port) {
port_reg = of_get_property(port, "reg", NULL);
if (!port_reg)
continue;
port_index = be32_to_cpup(port_reg);
if (port_index >= DSA_MAX_PORTS)
break;
port_name = of_get_property(port, "label", NULL);
if (!port_name)
continue;
cd->port_dn[port_index] = port;
cd->port_names[port_index] = kstrdup(port_name,
GFP_KERNEL);
if (!cd->port_names[port_index]) {
ret = -ENOMEM;
goto out_free_chip;
}
ret = dsa_of_probe_links(pd, cd, chip_index,
port_index, port, port_name);
if (ret)
goto out_free_chip;
}
}
put_device(&mdio_bus->dev);
return 0;
out_free_chip:
dsa_of_free_platform_data(pd);
out_free:
kfree(pd);
dev->platform_data = NULL;
out_put_ethernet:
put_device(&ethernet_dev->dev);
out_put_mdio:
put_device(&mdio_bus->dev);
return ret;
}
static void dsa_of_remove(struct device *dev)
{
struct dsa_platform_data *pd = dev->platform_data;
if (!dev->of_node)
return;
dsa_of_free_platform_data(pd);
put_device(&pd->of_netdev->dev);
kfree(pd);
}
static inline int dsa_of_probe(struct device *dev)
{
return 0;
}
static inline void dsa_of_remove(struct device *dev)
{
}
static int dsa_setup_dst(struct dsa_switch_tree *dst, struct net_device *dev,
struct device *parent, struct dsa_platform_data *pd)
{
int i;
unsigned configured = 0;
dst->pd = pd;
for (i = 0; i < pd->nr_chips; i++) {
struct dsa_switch *ds;
ds = dsa_switch_setup(dst, dev, i, parent, pd->chip[i].host_dev);
if (IS_ERR(ds)) {
netdev_err(dev, "[%d]: couldn't create dsa switch instance (error %ld)\n",
i, PTR_ERR(ds));
continue;
}
dst->ds[i] = ds;
++configured;
}
if (!configured)
return -EPROBE_DEFER;
wmb();
dev->dsa_ptr = dst;
return 0;
}
static int dsa_probe(struct platform_device *pdev)
{
struct dsa_platform_data *pd = pdev->dev.platform_data;
struct net_device *dev;
struct dsa_switch_tree *dst;
int ret;
if (pdev->dev.of_node) {
ret = dsa_of_probe(&pdev->dev);
if (ret)
return ret;
pd = pdev->dev.platform_data;
}
if (pd == NULL || (pd->netdev == NULL && pd->of_netdev == NULL))
return -EINVAL;
if (pd->of_netdev) {
dev = pd->of_netdev;
dev_hold(dev);
} else {
dev = dsa_dev_to_net_device(pd->netdev);
}
if (dev == NULL) {
ret = -EPROBE_DEFER;
goto out;
}
if (dev->dsa_ptr != NULL) {
dev_put(dev);
ret = -EEXIST;
goto out;
}
dst = devm_kzalloc(&pdev->dev, sizeof(*dst), GFP_KERNEL);
if (dst == NULL) {
dev_put(dev);
ret = -ENOMEM;
goto out;
}
platform_set_drvdata(pdev, dst);
ret = dsa_setup_dst(dst, dev, &pdev->dev, pd);
if (ret) {
dev_put(dev);
goto out;
}
return 0;
out:
dsa_of_remove(&pdev->dev);
return ret;
}
static void dsa_remove_dst(struct dsa_switch_tree *dst)
{
int i;
dst->cpu_dp->netdev->dsa_ptr = NULL;
wmb();
for (i = 0; i < dst->pd->nr_chips; i++) {
struct dsa_switch *ds = dst->ds[i];
if (ds)
dsa_switch_destroy(ds);
}
dsa_cpu_port_ethtool_restore(dst->cpu_dp);
dev_put(dst->cpu_dp->netdev);
}
static int dsa_remove(struct platform_device *pdev)
{
struct dsa_switch_tree *dst = platform_get_drvdata(pdev);
dsa_remove_dst(dst);
dsa_of_remove(&pdev->dev);
return 0;
}
static void dsa_shutdown(struct platform_device *pdev)
{
}
static int dsa_suspend(struct device *d)
{
struct platform_device *pdev = to_platform_device(d);
struct dsa_switch_tree *dst = platform_get_drvdata(pdev);
int i, ret = 0;
for (i = 0; i < dst->pd->nr_chips; i++) {
struct dsa_switch *ds = dst->ds[i];
if (ds != NULL)
ret = dsa_switch_suspend(ds);
}
return ret;
}
static int dsa_resume(struct device *d)
{
struct platform_device *pdev = to_platform_device(d);
struct dsa_switch_tree *dst = platform_get_drvdata(pdev);
int i, ret = 0;
for (i = 0; i < dst->pd->nr_chips; i++) {
struct dsa_switch *ds = dst->ds[i];
if (ds != NULL)
ret = dsa_switch_resume(ds);
}
return ret;
}
int dsa_legacy_fdb_add(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev,
const unsigned char *addr, u16 vid,
u16 flags)
{
struct dsa_slave_priv *p = netdev_priv(dev);
struct dsa_port *dp = p->dp;
return dsa_port_fdb_add(dp, addr, vid);
}
int dsa_legacy_fdb_del(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev,
const unsigned char *addr, u16 vid)
{
struct dsa_slave_priv *p = netdev_priv(dev);
struct dsa_port *dp = p->dp;
return dsa_port_fdb_del(dp, addr, vid);
}
int dsa_legacy_register(void)
{
return platform_driver_register(&dsa_driver);
}
void dsa_legacy_unregister(void)
{
platform_driver_unregister(&dsa_driver);
}
