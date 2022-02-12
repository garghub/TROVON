static char *mv88e6123_61_65_probe(struct device *host_dev, int sw_addr)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(host_dev);
int ret;
if (bus == NULL)
return NULL;
ret = __mv88e6xxx_reg_read(bus, sw_addr, REG_PORT(0), PORT_SWITCH_ID);
if (ret >= 0) {
if (ret == PORT_SWITCH_ID_6123_A1)
return "Marvell 88E6123 (A1)";
if (ret == PORT_SWITCH_ID_6123_A2)
return "Marvell 88E6123 (A2)";
if ((ret & 0xfff0) == PORT_SWITCH_ID_6123)
return "Marvell 88E6123";
if (ret == PORT_SWITCH_ID_6161_A1)
return "Marvell 88E6161 (A1)";
if (ret == PORT_SWITCH_ID_6161_A2)
return "Marvell 88E6161 (A2)";
if ((ret & 0xfff0) == PORT_SWITCH_ID_6161)
return "Marvell 88E6161";
if (ret == PORT_SWITCH_ID_6165_A1)
return "Marvell 88E6165 (A1)";
if (ret == PORT_SWITCH_ID_6165_A2)
return "Marvell 88e6165 (A2)";
if ((ret & 0xfff0) == PORT_SWITCH_ID_6165)
return "Marvell 88E6165";
}
return NULL;
}
static int mv88e6123_61_65_setup_global(struct dsa_switch *ds)
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
static int mv88e6123_61_65_setup(struct dsa_switch *ds)
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
ret = mv88e6123_61_65_setup_global(ds);
if (ret < 0)
return ret;
return mv88e6xxx_setup_ports(ds);
}
