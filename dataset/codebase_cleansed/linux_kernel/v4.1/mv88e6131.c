static char *mv88e6131_probe(struct device *host_dev, int sw_addr)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(host_dev);
int ret;
if (bus == NULL)
return NULL;
ret = __mv88e6xxx_reg_read(bus, sw_addr, REG_PORT(0), PORT_SWITCH_ID);
if (ret >= 0) {
int ret_masked = ret & 0xfff0;
if (ret_masked == PORT_SWITCH_ID_6085)
return "Marvell 88E6085";
if (ret_masked == PORT_SWITCH_ID_6095)
return "Marvell 88E6095/88E6095F";
if (ret == PORT_SWITCH_ID_6131_B2)
return "Marvell 88E6131 (B2)";
if (ret_masked == PORT_SWITCH_ID_6131)
return "Marvell 88E6131";
}
return NULL;
}
static int mv88e6131_setup_global(struct dsa_switch *ds)
{
int ret;
int i;
REG_WRITE(REG_GLOBAL, 0x04, 0x4400);
REG_WRITE(REG_GLOBAL, 0x0a, 0x0148);
ret = mv88e6xxx_config_prio(ds);
if (ret < 0)
return ret;
REG_WRITE(REG_GLOBAL, 0x19, 0x8100);
REG_WRITE(REG_GLOBAL, 0x1a, (dsa_upstream_port(ds) * 0x1100) | 0x00f0);
if (ds->dst->pd->nr_chips > 1)
REG_WRITE(REG_GLOBAL, 0x1c, 0xf000 | (ds->index & 0x1f));
else
REG_WRITE(REG_GLOBAL, 0x1c, 0xe000 | (ds->index & 0x1f));
REG_WRITE(REG_GLOBAL2, 0x03, 0xffff);
REG_WRITE(REG_GLOBAL2, 0x05, 0x00ff);
for (i = 0; i < 32; i++) {
int nexthop;
nexthop = 0x1f;
if (ds->pd->rtable &&
i != ds->index && i < ds->dst->pd->nr_chips)
nexthop = ds->pd->rtable[i] & 0x1f;
REG_WRITE(REG_GLOBAL2, 0x06, 0x8000 | (i << 8) | nexthop);
}
for (i = 0; i < 8; i++)
REG_WRITE(REG_GLOBAL2, 0x07, 0x8000 | (i << 12) | 0x7ff);
for (i = 0; i < 16; i++)
REG_WRITE(REG_GLOBAL2, 0x08, 0x8000 | (i << 11));
REG_WRITE(REG_GLOBAL2, 0x0f, 0x00ff);
return 0;
}
static int mv88e6131_setup_port(struct dsa_switch *ds, int p)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int addr = REG_PORT(p);
u16 val;
if (dsa_is_cpu_port(ds, p) || ds->dsa_port_mask & (1 << p))
if (ps->id == PORT_SWITCH_ID_6085)
REG_WRITE(addr, 0x01, 0x003d);
else
REG_WRITE(addr, 0x01, 0x003e);
else
REG_WRITE(addr, 0x01, 0x0003);
val = 0x0433;
if (p == dsa_upstream_port(ds)) {
val |= 0x0104;
if (ps->id == PORT_SWITCH_ID_6085)
val |= 0x0008;
}
if (ds->dsa_port_mask & (1 << p))
val |= 0x0100;
REG_WRITE(addr, 0x04, val);
if (ps->id == PORT_SWITCH_ID_6085)
REG_WRITE(addr, 0x08, 0x0080);
else {
val = 0x0080 | dsa_upstream_port(ds);
if (p == dsa_upstream_port(ds))
val |= 0x0040;
REG_WRITE(addr, 0x08, val);
}
REG_WRITE(addr, 0x09, 0x0000);
REG_WRITE(addr, 0x0a, 0x0000);
REG_WRITE(addr, 0x0b, 1 << p);
REG_WRITE(addr, 0x18, 0x3210);
REG_WRITE(addr, 0x19, 0x7654);
return mv88e6xxx_setup_port_common(ds, p);
}
static int mv88e6131_setup(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int i;
int ret;
ret = mv88e6xxx_setup_common(ds);
if (ret < 0)
return ret;
mv88e6xxx_ppu_state_init(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6085:
ps->num_ports = 10;
break;
case PORT_SWITCH_ID_6095:
ps->num_ports = 11;
break;
case PORT_SWITCH_ID_6131:
case PORT_SWITCH_ID_6131_B2:
ps->num_ports = 8;
break;
default:
return -ENODEV;
}
ret = mv88e6xxx_switch_reset(ds, false);
if (ret < 0)
return ret;
ret = mv88e6131_setup_global(ds);
if (ret < 0)
return ret;
for (i = 0; i < ps->num_ports; i++) {
ret = mv88e6131_setup_port(ds, i);
if (ret < 0)
return ret;
}
return 0;
}
static int mv88e6131_port_to_phy_addr(struct dsa_switch *ds, int port)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
if (port >= 0 && port < ps->num_ports)
return port;
return -EINVAL;
}
static int
mv88e6131_phy_read(struct dsa_switch *ds, int port, int regnum)
{
int addr = mv88e6131_port_to_phy_addr(ds, port);
if (addr < 0)
return addr;
return mv88e6xxx_phy_read_ppu(ds, addr, regnum);
}
static int
mv88e6131_phy_write(struct dsa_switch *ds,
int port, int regnum, u16 val)
{
int addr = mv88e6131_port_to_phy_addr(ds, port);
if (addr < 0)
return addr;
return mv88e6xxx_phy_write_ppu(ds, addr, regnum, val);
}
