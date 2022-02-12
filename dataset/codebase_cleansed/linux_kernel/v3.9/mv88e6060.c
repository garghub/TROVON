static int reg_read(struct dsa_switch *ds, int addr, int reg)
{
return mdiobus_read(ds->master_mii_bus, ds->pd->sw_addr + addr, reg);
}
static int reg_write(struct dsa_switch *ds, int addr, int reg, u16 val)
{
return mdiobus_write(ds->master_mii_bus, ds->pd->sw_addr + addr,
reg, val);
}
static char *mv88e6060_probe(struct mii_bus *bus, int sw_addr)
{
int ret;
ret = mdiobus_read(bus, sw_addr + REG_PORT(0), 0x03);
if (ret >= 0) {
ret &= 0xfff0;
if (ret == 0x0600)
return "Marvell 88E6060";
}
return NULL;
}
static int mv88e6060_switch_reset(struct dsa_switch *ds)
{
int i;
int ret;
unsigned long timeout;
for (i = 0; i < 6; i++) {
ret = REG_READ(REG_PORT(i), 0x04);
REG_WRITE(REG_PORT(i), 0x04, ret & 0xfffc);
}
usleep_range(2000, 4000);
REG_WRITE(REG_GLOBAL, 0x0a, 0xa130);
timeout = jiffies + 1 * HZ;
while (time_before(jiffies, timeout)) {
ret = REG_READ(REG_GLOBAL, 0x00);
if ((ret & 0x8000) == 0x0000)
break;
usleep_range(1000, 2000);
}
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
return 0;
}
static int mv88e6060_setup_global(struct dsa_switch *ds)
{
REG_WRITE(REG_GLOBAL, 0x04, 0x0800);
REG_WRITE(REG_GLOBAL, 0x0a, 0x2130);
return 0;
}
static int mv88e6060_setup_port(struct dsa_switch *ds, int p)
{
int addr = REG_PORT(p);
REG_WRITE(addr, 0x04, dsa_is_cpu_port(ds, p) ? 0x4103 : 0x0003);
REG_WRITE(addr, 0x06,
((p & 0xf) << 12) |
(dsa_is_cpu_port(ds, p) ?
ds->phys_port_mask :
(1 << ds->dst->cpu_port)));
REG_WRITE(addr, 0x0b, 1 << p);
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
for (i = 0; i < 6; i++) {
ret = mv88e6060_setup_port(ds, i);
if (ret < 0)
return ret;
}
return 0;
}
static int mv88e6060_set_addr(struct dsa_switch *ds, u8 *addr)
{
REG_WRITE(REG_GLOBAL, 0x01, (addr[0] << 8) | addr[1]);
REG_WRITE(REG_GLOBAL, 0x02, (addr[2] << 8) | addr[3]);
REG_WRITE(REG_GLOBAL, 0x03, (addr[4] << 8) | addr[5]);
return 0;
}
static int mv88e6060_port_to_phy_addr(int port)
{
if (port >= 0 && port <= 5)
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
static void mv88e6060_poll_link(struct dsa_switch *ds)
{
int i;
for (i = 0; i < DSA_MAX_PORTS; i++) {
struct net_device *dev;
int uninitialized_var(port_status);
int link;
int speed;
int duplex;
int fc;
dev = ds->ports[i];
if (dev == NULL)
continue;
link = 0;
if (dev->flags & IFF_UP) {
port_status = reg_read(ds, REG_PORT(i), 0x00);
if (port_status < 0)
continue;
link = !!(port_status & 0x1000);
}
if (!link) {
if (netif_carrier_ok(dev)) {
netdev_info(dev, "link down\n");
netif_carrier_off(dev);
}
continue;
}
speed = (port_status & 0x0100) ? 100 : 10;
duplex = (port_status & 0x0200) ? 1 : 0;
fc = ((port_status & 0xc000) == 0xc000) ? 1 : 0;
if (!netif_carrier_ok(dev)) {
netdev_info(dev,
"link up, %d Mb/s, %s duplex, flow control %sabled\n",
speed,
duplex ? "full" : "half",
fc ? "en" : "dis");
netif_carrier_on(dev);
}
}
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
