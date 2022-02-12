static enum dsa_tag_protocol dsa_loop_get_protocol(struct dsa_switch *ds)
{
dev_dbg(ds->dev, "%s\n", __func__);
return DSA_TAG_PROTO_NONE;
}
static int dsa_loop_setup(struct dsa_switch *ds)
{
dev_dbg(ds->dev, "%s\n", __func__);
return 0;
}
static int dsa_loop_set_addr(struct dsa_switch *ds, u8 *addr)
{
dev_dbg(ds->dev, "%s\n", __func__);
return 0;
}
static int dsa_loop_phy_read(struct dsa_switch *ds, int port, int regnum)
{
struct dsa_loop_priv *ps = ds->priv;
struct mii_bus *bus = ps->bus;
dev_dbg(ds->dev, "%s\n", __func__);
return mdiobus_read_nested(bus, ps->port_base + port, regnum);
}
static int dsa_loop_phy_write(struct dsa_switch *ds, int port,
int regnum, u16 value)
{
struct dsa_loop_priv *ps = ds->priv;
struct mii_bus *bus = ps->bus;
dev_dbg(ds->dev, "%s\n", __func__);
return mdiobus_write_nested(bus, ps->port_base + port, regnum, value);
}
static int dsa_loop_port_bridge_join(struct dsa_switch *ds, int port,
struct net_device *bridge)
{
dev_dbg(ds->dev, "%s\n", __func__);
return 0;
}
static void dsa_loop_port_bridge_leave(struct dsa_switch *ds, int port,
struct net_device *bridge)
{
dev_dbg(ds->dev, "%s\n", __func__);
}
static void dsa_loop_port_stp_state_set(struct dsa_switch *ds, int port,
u8 state)
{
dev_dbg(ds->dev, "%s\n", __func__);
}
static int dsa_loop_port_vlan_filtering(struct dsa_switch *ds, int port,
bool vlan_filtering)
{
dev_dbg(ds->dev, "%s\n", __func__);
return 0;
}
static int dsa_loop_port_vlan_prepare(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan,
struct switchdev_trans *trans)
{
struct dsa_loop_priv *ps = ds->priv;
struct mii_bus *bus = ps->bus;
dev_dbg(ds->dev, "%s\n", __func__);
mdiobus_read(bus, ps->port_base + port, MII_BMSR);
if (vlan->vid_end > DSA_LOOP_VLANS)
return -ERANGE;
return 0;
}
static void dsa_loop_port_vlan_add(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan,
struct switchdev_trans *trans)
{
bool untagged = vlan->flags & BRIDGE_VLAN_INFO_UNTAGGED;
bool pvid = vlan->flags & BRIDGE_VLAN_INFO_PVID;
struct dsa_loop_priv *ps = ds->priv;
struct mii_bus *bus = ps->bus;
struct dsa_loop_vlan *vl;
u16 vid;
dev_dbg(ds->dev, "%s\n", __func__);
mdiobus_read(bus, ps->port_base + port, MII_BMSR);
for (vid = vlan->vid_begin; vid <= vlan->vid_end; ++vid) {
vl = &ps->vlans[vid];
vl->members |= BIT(port);
if (untagged)
vl->untagged |= BIT(port);
else
vl->untagged &= ~BIT(port);
}
if (pvid)
ps->pvid = vid;
}
static int dsa_loop_port_vlan_del(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan)
{
bool untagged = vlan->flags & BRIDGE_VLAN_INFO_UNTAGGED;
struct dsa_loop_priv *ps = ds->priv;
struct mii_bus *bus = ps->bus;
struct dsa_loop_vlan *vl;
u16 vid, pvid = ps->pvid;
dev_dbg(ds->dev, "%s\n", __func__);
mdiobus_read(bus, ps->port_base + port, MII_BMSR);
for (vid = vlan->vid_begin; vid <= vlan->vid_end; ++vid) {
vl = &ps->vlans[vid];
vl->members &= ~BIT(port);
if (untagged)
vl->untagged &= ~BIT(port);
if (pvid == vid)
pvid = 1;
}
ps->pvid = pvid;
return 0;
}
static int dsa_loop_port_vlan_dump(struct dsa_switch *ds, int port,
struct switchdev_obj_port_vlan *vlan,
int (*cb)(struct switchdev_obj *obj))
{
struct dsa_loop_priv *ps = ds->priv;
struct mii_bus *bus = ps->bus;
struct dsa_loop_vlan *vl;
u16 vid, vid_start = 0;
int err = 0;
dev_dbg(ds->dev, "%s\n", __func__);
mdiobus_read(bus, ps->port_base + port, MII_BMSR);
for (vid = vid_start; vid < DSA_LOOP_VLANS; vid++) {
vl = &ps->vlans[vid];
if (!(vl->members & BIT(port)))
continue;
vlan->vid_begin = vlan->vid_end = vid;
vlan->flags = 0;
if (vl->untagged & BIT(port))
vlan->flags |= BRIDGE_VLAN_INFO_UNTAGGED;
if (ps->pvid == vid)
vlan->flags |= BRIDGE_VLAN_INFO_PVID;
err = cb(&vlan->obj);
if (err)
break;
}
return err;
}
static int dsa_loop_drv_probe(struct mdio_device *mdiodev)
{
struct dsa_loop_pdata *pdata = mdiodev->dev.platform_data;
struct dsa_loop_priv *ps;
struct dsa_switch *ds;
if (!pdata)
return -ENODEV;
dev_info(&mdiodev->dev, "%s: 0x%0x\n",
pdata->name, pdata->enabled_ports);
ds = dsa_switch_alloc(&mdiodev->dev, DSA_MAX_PORTS);
if (!ds)
return -ENOMEM;
ps = devm_kzalloc(&mdiodev->dev, sizeof(*ps), GFP_KERNEL);
if (!ps)
return -ENOMEM;
ps->netdev = dev_get_by_name(&init_net, pdata->netdev);
if (!ps->netdev)
return -EPROBE_DEFER;
pdata->cd.netdev[DSA_LOOP_CPU_PORT] = &ps->netdev->dev;
ds->dev = &mdiodev->dev;
ds->ops = &dsa_loop_driver;
ds->priv = ps;
ps->bus = mdiodev->bus;
dev_set_drvdata(&mdiodev->dev, ds);
return dsa_register_switch(ds, ds->dev);
}
static void dsa_loop_drv_remove(struct mdio_device *mdiodev)
{
struct dsa_switch *ds = dev_get_drvdata(&mdiodev->dev);
struct dsa_loop_priv *ps = ds->priv;
dsa_unregister_switch(ds);
dev_put(ps->netdev);
}
static void unregister_fixed_phys(void)
{
unsigned int i;
for (i = 0; i < NUM_FIXED_PHYS; i++)
if (phydevs[i])
fixed_phy_unregister(phydevs[i]);
}
static int __init dsa_loop_init(void)
{
struct fixed_phy_status status = {
.link = 1,
.speed = SPEED_100,
.duplex = DUPLEX_FULL,
};
unsigned int i;
for (i = 0; i < NUM_FIXED_PHYS; i++)
phydevs[i] = fixed_phy_register(PHY_POLL, &status, -1, NULL);
return mdio_driver_register(&dsa_loop_drv);
}
static void __exit dsa_loop_exit(void)
{
mdio_driver_unregister(&dsa_loop_drv);
unregister_fixed_phys();
}
