static char *mv88e6123_probe(struct device *host_dev, int sw_addr)
{
return mv88e6xxx_lookup_name(host_dev, sw_addr, mv88e6123_table,
ARRAY_SIZE(mv88e6123_table));
}
static int mv88e6123_setup_global(struct dsa_switch *ds)
{
u32 upstream_port = dsa_upstream_port(ds);
int ret;
u32 reg;
ret = mv88e6xxx_setup_global(ds);
if (ret)
return ret;
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL, 0x0000);
reg = upstream_port << GLOBAL_MONITOR_CONTROL_INGRESS_SHIFT |
upstream_port << GLOBAL_MONITOR_CONTROL_EGRESS_SHIFT |
upstream_port << GLOBAL_MONITOR_CONTROL_ARP_SHIFT;
REG_WRITE(REG_GLOBAL, GLOBAL_MONITOR_CONTROL, reg);
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL_2, ds->index & 0x1f);
return 0;
}
static int mv88e6123_setup(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
ret = mv88e6xxx_setup_common(ds);
if (ret < 0)
return ret;
switch (ps->id) {
case PORT_SWITCH_ID_6123:
ps->num_ports = 3;
break;
case PORT_SWITCH_ID_6161:
case PORT_SWITCH_ID_6165:
ps->num_ports = 6;
break;
default:
return -ENODEV;
}
ret = mv88e6xxx_switch_reset(ds, false);
if (ret < 0)
return ret;
ret = mv88e6123_setup_global(ds);
if (ret < 0)
return ret;
return mv88e6xxx_setup_ports(ds);
}
