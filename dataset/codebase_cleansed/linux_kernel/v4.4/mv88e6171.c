static char *mv88e6171_probe(struct device *host_dev, int sw_addr)
{
return mv88e6xxx_lookup_name(host_dev, sw_addr, mv88e6171_table,
ARRAY_SIZE(mv88e6171_table));
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
