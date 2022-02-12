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
if ((ret & 0xfff0) == PORT_SWITCH_ID_6175)
return "Marvell 88E6175";
if ((ret & 0xfff0) == PORT_SWITCH_ID_6350)
return "Marvell 88E6350";
if ((ret & 0xfff0) == PORT_SWITCH_ID_6351)
return "Marvell 88E6351";
}
return NULL;
}
static int mv88e6171_setup_global(struct dsa_switch *ds)
{
u32 upstream_port = dsa_upstream_port(ds);
int ret;
u32 reg;
ret = mv88e6xxx_setup_global(ds);
if (ret)
return ret;
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL,
GLOBAL_CONTROL_PPU_ENABLE | GLOBAL_CONTROL_DISCARD_EXCESS);
reg = upstream_port << GLOBAL_MONITOR_CONTROL_INGRESS_SHIFT |
upstream_port << GLOBAL_MONITOR_CONTROL_EGRESS_SHIFT |
upstream_port << GLOBAL_MONITOR_CONTROL_ARP_SHIFT |
upstream_port << GLOBAL_MONITOR_CONTROL_MIRROR_SHIFT;
REG_WRITE(REG_GLOBAL, GLOBAL_MONITOR_CONTROL, reg);
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL_2, ds->index & 0x1f);
return 0;
}
static int mv88e6171_setup(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
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
return mv88e6xxx_setup_ports(ds);
}
