static char *mv88e6131_probe(struct device *host_dev, int sw_addr)
{
return mv88e6xxx_lookup_name(host_dev, sw_addr, mv88e6131_table,
ARRAY_SIZE(mv88e6131_table));
}
static int mv88e6131_setup_global(struct dsa_switch *ds)
{
u32 upstream_port = dsa_upstream_port(ds);
int ret;
u32 reg;
ret = mv88e6xxx_setup_global(ds);
if (ret)
return ret;
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL,
GLOBAL_CONTROL_PPU_ENABLE | GLOBAL_CONTROL_MAX_FRAME_1632);
REG_WRITE(REG_GLOBAL, GLOBAL_CORE_TAG_TYPE, 0x8100);
reg = upstream_port << GLOBAL_MONITOR_CONTROL_INGRESS_SHIFT |
upstream_port << GLOBAL_MONITOR_CONTROL_EGRESS_SHIFT |
GLOBAL_MONITOR_CONTROL_ARP_DISABLED;
REG_WRITE(REG_GLOBAL, GLOBAL_MONITOR_CONTROL, reg);
if (ds->dst->pd->nr_chips > 1)
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL_2,
GLOBAL_CONTROL_2_MULTIPLE_CASCADE |
(ds->index & 0x1f));
else
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL_2,
GLOBAL_CONTROL_2_NO_CASCADE |
(ds->index & 0x1f));
REG_WRITE(REG_GLOBAL2, GLOBAL2_PRIO_OVERRIDE,
GLOBAL2_PRIO_OVERRIDE_FORCE_SNOOP |
7 << GLOBAL2_PRIO_OVERRIDE_SNOOP_SHIFT |
GLOBAL2_PRIO_OVERRIDE_FORCE_ARP |
7 << GLOBAL2_PRIO_OVERRIDE_ARP_SHIFT);
return 0;
}
static int mv88e6131_setup(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
ret = mv88e6xxx_setup_common(ds);
if (ret < 0)
return ret;
mv88e6xxx_ppu_state_init(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6085:
case PORT_SWITCH_ID_6185:
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
return mv88e6xxx_setup_ports(ds);
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
