static char *mv88e6171_probe(struct device *host_dev, int sw_addr)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(host_dev);
int ret;
if (bus == NULL)
return NULL;
ret = __mv88e6xxx_reg_read(bus, sw_addr, REG_PORT(0), PORT_SWITCH_ID);
if (ret >= 0) {
if ((ret & 0xfff0) == PORT_SWITCH_ID_6171)
return "Marvell 88E6171";
if ((ret & 0xfff0) == PORT_SWITCH_ID_6172)
return "Marvell 88E6172";
}
return NULL;
}
static int mv88e6171_setup_global(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
int i;
REG_WRITE(REG_GLOBAL, 0x04, 0x6000);
REG_WRITE(REG_GLOBAL, 0x0a, 0x0148);
ret = mv88e6xxx_config_prio(ds);
if (ret < 0)
return ret;
if (REG_READ(REG_PORT(0), 0x03) == 0x1710)
REG_WRITE(REG_GLOBAL, 0x1a, (dsa_upstream_port(ds) * 0x1111));
else
REG_WRITE(REG_GLOBAL, 0x1a, (dsa_upstream_port(ds) * 0x1110));
REG_WRITE(REG_GLOBAL, 0x1c, ds->index & 0x1f);
REG_WRITE(REG_GLOBAL2, 0x02, 0xffff);
REG_WRITE(REG_GLOBAL2, 0x03, 0xffff);
REG_WRITE(REG_GLOBAL2, 0x05, 0x00ff);
for (i = 0; i < 32; i++) {
int nexthop;
nexthop = 0x1f;
if (i != ds->index && i < ds->dst->pd->nr_chips)
nexthop = ds->pd->rtable[i] & 0x1f;
REG_WRITE(REG_GLOBAL2, 0x06, 0x8000 | (i << 8) | nexthop);
}
for (i = 0; i < ps->num_ports; i++)
REG_WRITE(REG_GLOBAL2, 0x07, 0x8000 | (i << 12) | 0xff);
for (i = 0; i < 16; i++)
REG_WRITE(REG_GLOBAL2, 0x08, 0x8000 | (i << 11));
for (i = 0; i < 6; i++)
REG_WRITE(REG_GLOBAL2, 0x09, 0x9000 | (i << 8));
REG_WRITE(REG_GLOBAL2, 0x0b, 0x9000);
for (i = 0; i < 16; i++)
REG_WRITE(REG_GLOBAL2, 0x0f, 0x8000 | (i << 8));
return 0;
}
static int mv88e6171_setup_port(struct dsa_switch *ds, int p)
{
int addr = REG_PORT(p);
u16 val;
val = REG_READ(addr, 0x01);
if (dsa_is_cpu_port(ds, p) || ds->dsa_port_mask & (1 << p))
REG_WRITE(addr, 0x01, val | 0x003e);
else
REG_WRITE(addr, 0x01, val | 0x0003);
REG_WRITE(addr, 0x02, 0x0000);
val = 0x0433;
if (dsa_is_cpu_port(ds, p)) {
if (ds->dst->tag_protocol == DSA_TAG_PROTO_EDSA)
val |= 0x3300;
else
val |= 0x0100;
}
if (ds->dsa_port_mask & (1 << p))
val |= 0x0100;
if (p == dsa_upstream_port(ds))
val |= 0x000c;
REG_WRITE(addr, 0x04, val);
REG_WRITE(addr, 0x08, 0x2080);
REG_WRITE(addr, 0x09, 0x0001);
REG_WRITE(addr, 0x0a, 0x0000);
REG_WRITE(addr, 0x0b, 1 << p);
REG_WRITE(addr, 0x0c, 0x0000);
REG_WRITE(addr, 0x0d, 0x0000);
REG_WRITE(addr, 0x0f, ETH_P_EDSA);
REG_WRITE(addr, 0x18, 0x3210);
REG_WRITE(addr, 0x19, 0x7654);
return mv88e6xxx_setup_port_common(ds, p);
}
static int mv88e6171_setup(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int i;
int ret;
ret = mv88e6xxx_setup_common(ds);
if (ret < 0)
return ret;
ps->num_ports = 7;
ret = mv88e6xxx_switch_reset(ds, true);
if (ret < 0)
return ret;
ret = mv88e6171_setup_global(ds);
if (ret < 0)
return ret;
for (i = 0; i < ps->num_ports; i++) {
if (!(dsa_is_cpu_port(ds, i) || ds->phys_port_mask & (1 << i)))
continue;
ret = mv88e6171_setup_port(ds, i);
if (ret < 0)
return ret;
}
return 0;
}
static int mv88e6171_get_eee(struct dsa_switch *ds, int port,
struct ethtool_eee *e)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
if (ps->id == PORT_SWITCH_ID_6172)
return mv88e6xxx_get_eee(ds, port, e);
return -EOPNOTSUPP;
}
static int mv88e6171_set_eee(struct dsa_switch *ds, int port,
struct phy_device *phydev, struct ethtool_eee *e)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
if (ps->id == PORT_SWITCH_ID_6172)
return mv88e6xxx_set_eee(ds, port, phydev, e);
return -EOPNOTSUPP;
}
