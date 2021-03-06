static int reg_read(struct dsa_switch *ds, int addr, int reg)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(ds->master_dev);
if (bus == NULL)
return -EINVAL;
return mdiobus_read_nested(bus, ds->pd->sw_addr + addr, reg);
}
static int reg_write(struct dsa_switch *ds, int addr, int reg, u16 val)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(ds->master_dev);
if (bus == NULL)
return -EINVAL;
return mdiobus_write_nested(bus, ds->pd->sw_addr + addr, reg, val);
}
static char *mv88e6060_probe(struct device *host_dev, int sw_addr)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(host_dev);
int ret;
if (bus == NULL)
return NULL;
ret = mdiobus_read(bus, sw_addr + REG_PORT(0), PORT_SWITCH_ID);
if (ret >= 0) {
if (ret == PORT_SWITCH_ID_6060)
return "Marvell 88E6060 (A0)";
if (ret == PORT_SWITCH_ID_6060_R1 ||
ret == PORT_SWITCH_ID_6060_R2)
return "Marvell 88E6060 (B0)";
if ((ret & PORT_SWITCH_ID_6060_MASK) == PORT_SWITCH_ID_6060)
return "Marvell 88E6060";
}
return NULL;
}
static int mv88e6060_switch_reset(struct dsa_switch *ds)
{
int i;
int ret;
unsigned long timeout;
for (i = 0; i < MV88E6060_PORTS; i++) {
ret = REG_READ(REG_PORT(i), PORT_CONTROL);
REG_WRITE(REG_PORT(i), PORT_CONTROL,
ret & ~PORT_CONTROL_STATE_MASK);
}
usleep_range(2000, 4000);
REG_WRITE(REG_GLOBAL, GLOBAL_ATU_CONTROL,
GLOBAL_ATU_CONTROL_SWRESET |
GLOBAL_ATU_CONTROL_ATUSIZE_1024 |
GLOBAL_ATU_CONTROL_ATE_AGE_5MIN);
timeout = jiffies + 1 * HZ;
while (time_before(jiffies, timeout)) {
ret = REG_READ(REG_GLOBAL, GLOBAL_STATUS);
if (ret & GLOBAL_STATUS_INIT_READY)
break;
usleep_range(1000, 2000);
}
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
return 0;
}
static int mv88e6060_setup_global(struct dsa_switch *ds)
{
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL, GLOBAL_CONTROL_MAX_FRAME_1536);
REG_WRITE(REG_GLOBAL, GLOBAL_ATU_CONTROL,
GLOBAL_ATU_CONTROL_ATUSIZE_1024 |
GLOBAL_ATU_CONTROL_ATE_AGE_5MIN);
return 0;
}
static int mv88e6060_setup_port(struct dsa_switch *ds, int p)
{
int addr = REG_PORT(p);
REG_WRITE(addr, PORT_CONTROL,
dsa_is_cpu_port(ds, p) ?
PORT_CONTROL_TRAILER |
PORT_CONTROL_INGRESS_MODE |
PORT_CONTROL_STATE_FORWARDING :
PORT_CONTROL_STATE_FORWARDING);
REG_WRITE(addr, PORT_VLAN_MAP,
((p & 0xf) << PORT_VLAN_MAP_DBNUM_SHIFT) |
(dsa_is_cpu_port(ds, p) ?
ds->phys_port_mask :
BIT(ds->dst->cpu_port)));
REG_WRITE(addr, PORT_ASSOC_VECTOR, BIT(p));
return 0;
}
static int mv88e6060_setup(struct dsa_switch *ds)
{
int i;
int ret;
ret = mv88e6060_switch_reset(ds);
if (ret < 0)
return ret;
ret = mv88e6060_setup_global(ds);
if (ret < 0)
return ret;
for (i = 0; i < MV88E6060_PORTS; i++) {
ret = mv88e6060_setup_port(ds, i);
if (ret < 0)
return ret;
}
return 0;
}
static int mv88e6060_set_addr(struct dsa_switch *ds, u8 *addr)
{
REG_WRITE(REG_GLOBAL, GLOBAL_MAC_01, (addr[0] << 9) | addr[1]);
REG_WRITE(REG_GLOBAL, GLOBAL_MAC_23, (addr[2] << 8) | addr[3]);
REG_WRITE(REG_GLOBAL, GLOBAL_MAC_45, (addr[4] << 8) | addr[5]);
return 0;
}
static int mv88e6060_port_to_phy_addr(int port)
{
if (port >= 0 && port < MV88E6060_PORTS)
return port;
return -1;
}
static int mv88e6060_phy_read(struct dsa_switch *ds, int port, int regnum)
{
int addr;
addr = mv88e6060_port_to_phy_addr(port);
if (addr == -1)
return 0xffff;
return reg_read(ds, addr, regnum);
}
static int
mv88e6060_phy_write(struct dsa_switch *ds, int port, int regnum, u16 val)
{
int addr;
addr = mv88e6060_port_to_phy_addr(port);
if (addr == -1)
return 0xffff;
return reg_write(ds, addr, regnum, val);
}
static int __init mv88e6060_init(void)
{
register_switch_driver(&mv88e6060_switch_driver);
return 0;
}
static void __exit mv88e6060_cleanup(void)
{
unregister_switch_driver(&mv88e6060_switch_driver);
}
