static int mv88e6xxx_mdiobus_read(struct mii_bus *bus, int addr, u32 regnum)
{
int ret;
mutex_lock_nested(&bus->mdio_lock, SINGLE_DEPTH_NESTING);
ret = bus->read(bus, addr, regnum);
mutex_unlock(&bus->mdio_lock);
return ret;
}
static int mv88e6xxx_mdiobus_write(struct mii_bus *bus, int addr, u32 regnum,
u16 val)
{
int ret;
mutex_lock_nested(&bus->mdio_lock, SINGLE_DEPTH_NESTING);
ret = bus->write(bus, addr, regnum, val);
mutex_unlock(&bus->mdio_lock);
return ret;
}
static int mv88e6xxx_reg_wait_ready(struct mii_bus *bus, int sw_addr)
{
int ret;
int i;
for (i = 0; i < 16; i++) {
ret = mv88e6xxx_mdiobus_read(bus, sw_addr, SMI_CMD);
if (ret < 0)
return ret;
if ((ret & SMI_CMD_BUSY) == 0)
return 0;
}
return -ETIMEDOUT;
}
int __mv88e6xxx_reg_read(struct mii_bus *bus, int sw_addr, int addr, int reg)
{
int ret;
if (sw_addr == 0)
return mv88e6xxx_mdiobus_read(bus, addr, reg);
ret = mv88e6xxx_reg_wait_ready(bus, sw_addr);
if (ret < 0)
return ret;
ret = mv88e6xxx_mdiobus_write(bus, sw_addr, SMI_CMD,
SMI_CMD_OP_22_READ | (addr << 5) | reg);
if (ret < 0)
return ret;
ret = mv88e6xxx_reg_wait_ready(bus, sw_addr);
if (ret < 0)
return ret;
ret = mv88e6xxx_mdiobus_read(bus, sw_addr, SMI_DATA);
if (ret < 0)
return ret;
return ret & 0xffff;
}
static int _mv88e6xxx_reg_read(struct dsa_switch *ds, int addr, int reg)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(ds->master_dev);
int ret;
if (bus == NULL)
return -EINVAL;
ret = __mv88e6xxx_reg_read(bus, ds->pd->sw_addr, addr, reg);
if (ret < 0)
return ret;
dev_dbg(ds->master_dev, "<- addr: 0x%.2x reg: 0x%.2x val: 0x%.4x\n",
addr, reg, ret);
return ret;
}
int mv88e6xxx_reg_read(struct dsa_switch *ds, int addr, int reg)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_reg_read(ds, addr, reg);
mutex_unlock(&ps->smi_mutex);
return ret;
}
int __mv88e6xxx_reg_write(struct mii_bus *bus, int sw_addr, int addr,
int reg, u16 val)
{
int ret;
if (sw_addr == 0)
return mv88e6xxx_mdiobus_write(bus, addr, reg, val);
ret = mv88e6xxx_reg_wait_ready(bus, sw_addr);
if (ret < 0)
return ret;
ret = mv88e6xxx_mdiobus_write(bus, sw_addr, SMI_DATA, val);
if (ret < 0)
return ret;
ret = mv88e6xxx_mdiobus_write(bus, sw_addr, SMI_CMD,
SMI_CMD_OP_22_WRITE | (addr << 5) | reg);
if (ret < 0)
return ret;
ret = mv88e6xxx_reg_wait_ready(bus, sw_addr);
if (ret < 0)
return ret;
return 0;
}
static int _mv88e6xxx_reg_write(struct dsa_switch *ds, int addr, int reg,
u16 val)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(ds->master_dev);
if (bus == NULL)
return -EINVAL;
dev_dbg(ds->master_dev, "-> addr: 0x%.2x reg: 0x%.2x val: 0x%.4x\n",
addr, reg, val);
return __mv88e6xxx_reg_write(bus, ds->pd->sw_addr, addr, reg, val);
}
int mv88e6xxx_reg_write(struct dsa_switch *ds, int addr, int reg, u16 val)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_reg_write(ds, addr, reg, val);
mutex_unlock(&ps->smi_mutex);
return ret;
}
int mv88e6xxx_set_addr_direct(struct dsa_switch *ds, u8 *addr)
{
REG_WRITE(REG_GLOBAL, GLOBAL_MAC_01, (addr[0] << 8) | addr[1]);
REG_WRITE(REG_GLOBAL, GLOBAL_MAC_23, (addr[2] << 8) | addr[3]);
REG_WRITE(REG_GLOBAL, GLOBAL_MAC_45, (addr[4] << 8) | addr[5]);
return 0;
}
int mv88e6xxx_set_addr_indirect(struct dsa_switch *ds, u8 *addr)
{
int i;
int ret;
for (i = 0; i < 6; i++) {
int j;
REG_WRITE(REG_GLOBAL2, GLOBAL2_SWITCH_MAC,
GLOBAL2_SWITCH_MAC_BUSY | (i << 8) | addr[i]);
for (j = 0; j < 16; j++) {
ret = REG_READ(REG_GLOBAL2, GLOBAL2_SWITCH_MAC);
if ((ret & GLOBAL2_SWITCH_MAC_BUSY) == 0)
break;
}
if (j == 16)
return -ETIMEDOUT;
}
return 0;
}
static int _mv88e6xxx_phy_read(struct dsa_switch *ds, int addr, int regnum)
{
if (addr >= 0)
return _mv88e6xxx_reg_read(ds, addr, regnum);
return 0xffff;
}
static int _mv88e6xxx_phy_write(struct dsa_switch *ds, int addr, int regnum,
u16 val)
{
if (addr >= 0)
return _mv88e6xxx_reg_write(ds, addr, regnum, val);
return 0;
}
static int mv88e6xxx_ppu_disable(struct dsa_switch *ds)
{
int ret;
unsigned long timeout;
ret = REG_READ(REG_GLOBAL, GLOBAL_CONTROL);
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL,
ret & ~GLOBAL_CONTROL_PPU_ENABLE);
timeout = jiffies + 1 * HZ;
while (time_before(jiffies, timeout)) {
ret = REG_READ(REG_GLOBAL, GLOBAL_STATUS);
usleep_range(1000, 2000);
if ((ret & GLOBAL_STATUS_PPU_MASK) !=
GLOBAL_STATUS_PPU_POLLING)
return 0;
}
return -ETIMEDOUT;
}
static int mv88e6xxx_ppu_enable(struct dsa_switch *ds)
{
int ret;
unsigned long timeout;
ret = REG_READ(REG_GLOBAL, GLOBAL_CONTROL);
REG_WRITE(REG_GLOBAL, GLOBAL_CONTROL, ret | GLOBAL_CONTROL_PPU_ENABLE);
timeout = jiffies + 1 * HZ;
while (time_before(jiffies, timeout)) {
ret = REG_READ(REG_GLOBAL, GLOBAL_STATUS);
usleep_range(1000, 2000);
if ((ret & GLOBAL_STATUS_PPU_MASK) ==
GLOBAL_STATUS_PPU_POLLING)
return 0;
}
return -ETIMEDOUT;
}
static void mv88e6xxx_ppu_reenable_work(struct work_struct *ugly)
{
struct mv88e6xxx_priv_state *ps;
ps = container_of(ugly, struct mv88e6xxx_priv_state, ppu_work);
if (mutex_trylock(&ps->ppu_mutex)) {
struct dsa_switch *ds = ((struct dsa_switch *)ps) - 1;
if (mv88e6xxx_ppu_enable(ds) == 0)
ps->ppu_disabled = 0;
mutex_unlock(&ps->ppu_mutex);
}
}
static void mv88e6xxx_ppu_reenable_timer(unsigned long _ps)
{
struct mv88e6xxx_priv_state *ps = (void *)_ps;
schedule_work(&ps->ppu_work);
}
static int mv88e6xxx_ppu_access_get(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->ppu_mutex);
if (!ps->ppu_disabled) {
ret = mv88e6xxx_ppu_disable(ds);
if (ret < 0) {
mutex_unlock(&ps->ppu_mutex);
return ret;
}
ps->ppu_disabled = 1;
} else {
del_timer(&ps->ppu_timer);
ret = 0;
}
return ret;
}
static void mv88e6xxx_ppu_access_put(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
mod_timer(&ps->ppu_timer, jiffies + msecs_to_jiffies(10));
mutex_unlock(&ps->ppu_mutex);
}
void mv88e6xxx_ppu_state_init(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
mutex_init(&ps->ppu_mutex);
INIT_WORK(&ps->ppu_work, mv88e6xxx_ppu_reenable_work);
init_timer(&ps->ppu_timer);
ps->ppu_timer.data = (unsigned long)ps;
ps->ppu_timer.function = mv88e6xxx_ppu_reenable_timer;
}
int mv88e6xxx_phy_read_ppu(struct dsa_switch *ds, int addr, int regnum)
{
int ret;
ret = mv88e6xxx_ppu_access_get(ds);
if (ret >= 0) {
ret = mv88e6xxx_reg_read(ds, addr, regnum);
mv88e6xxx_ppu_access_put(ds);
}
return ret;
}
int mv88e6xxx_phy_write_ppu(struct dsa_switch *ds, int addr,
int regnum, u16 val)
{
int ret;
ret = mv88e6xxx_ppu_access_get(ds);
if (ret >= 0) {
ret = mv88e6xxx_reg_write(ds, addr, regnum, val);
mv88e6xxx_ppu_access_put(ds);
}
return ret;
}
void mv88e6xxx_poll_link(struct dsa_switch *ds)
{
int i;
for (i = 0; i < DSA_MAX_PORTS; i++) {
struct net_device *dev;
int uninitialized_var(port_status);
int pcs_ctrl;
int link;
int speed;
int duplex;
int fc;
dev = ds->ports[i];
if (dev == NULL)
continue;
pcs_ctrl = mv88e6xxx_reg_read(ds, REG_PORT(i), PORT_PCS_CTRL);
if (pcs_ctrl < 0 || pcs_ctrl & PORT_PCS_CTRL_FORCE_LINK)
continue;
link = 0;
if (dev->flags & IFF_UP) {
port_status = mv88e6xxx_reg_read(ds, REG_PORT(i),
PORT_STATUS);
if (port_status < 0)
continue;
link = !!(port_status & PORT_STATUS_LINK);
}
if (!link) {
if (netif_carrier_ok(dev)) {
netdev_info(dev, "link down\n");
netif_carrier_off(dev);
}
continue;
}
switch (port_status & PORT_STATUS_SPEED_MASK) {
case PORT_STATUS_SPEED_10:
speed = 10;
break;
case PORT_STATUS_SPEED_100:
speed = 100;
break;
case PORT_STATUS_SPEED_1000:
speed = 1000;
break;
default:
speed = -1;
break;
}
duplex = (port_status & PORT_STATUS_DUPLEX) ? 1 : 0;
fc = (port_status & PORT_STATUS_PAUSE_EN) ? 1 : 0;
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
static bool mv88e6xxx_6065_family(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6031:
case PORT_SWITCH_ID_6061:
case PORT_SWITCH_ID_6035:
case PORT_SWITCH_ID_6065:
return true;
}
return false;
}
static bool mv88e6xxx_6095_family(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6092:
case PORT_SWITCH_ID_6095:
return true;
}
return false;
}
static bool mv88e6xxx_6097_family(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6046:
case PORT_SWITCH_ID_6085:
case PORT_SWITCH_ID_6096:
case PORT_SWITCH_ID_6097:
return true;
}
return false;
}
static bool mv88e6xxx_6165_family(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6123:
case PORT_SWITCH_ID_6161:
case PORT_SWITCH_ID_6165:
return true;
}
return false;
}
static bool mv88e6xxx_6185_family(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6121:
case PORT_SWITCH_ID_6122:
case PORT_SWITCH_ID_6152:
case PORT_SWITCH_ID_6155:
case PORT_SWITCH_ID_6182:
case PORT_SWITCH_ID_6185:
case PORT_SWITCH_ID_6108:
case PORT_SWITCH_ID_6131:
return true;
}
return false;
}
static bool mv88e6xxx_6320_family(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6320:
case PORT_SWITCH_ID_6321:
return true;
}
return false;
}
static bool mv88e6xxx_6351_family(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6171:
case PORT_SWITCH_ID_6175:
case PORT_SWITCH_ID_6350:
case PORT_SWITCH_ID_6351:
return true;
}
return false;
}
static bool mv88e6xxx_6352_family(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6172:
case PORT_SWITCH_ID_6176:
case PORT_SWITCH_ID_6240:
case PORT_SWITCH_ID_6352:
return true;
}
return false;
}
void mv88e6xxx_adjust_link(struct dsa_switch *ds, int port,
struct phy_device *phydev)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
u32 ret, reg;
if (!phy_is_pseudo_fixed_link(phydev))
return;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_reg_read(ds, REG_PORT(port), PORT_PCS_CTRL);
if (ret < 0)
goto out;
reg = ret & ~(PORT_PCS_CTRL_LINK_UP |
PORT_PCS_CTRL_FORCE_LINK |
PORT_PCS_CTRL_DUPLEX_FULL |
PORT_PCS_CTRL_FORCE_DUPLEX |
PORT_PCS_CTRL_UNFORCED);
reg |= PORT_PCS_CTRL_FORCE_LINK;
if (phydev->link)
reg |= PORT_PCS_CTRL_LINK_UP;
if (mv88e6xxx_6065_family(ds) && phydev->speed > SPEED_100)
goto out;
switch (phydev->speed) {
case SPEED_1000:
reg |= PORT_PCS_CTRL_1000;
break;
case SPEED_100:
reg |= PORT_PCS_CTRL_100;
break;
case SPEED_10:
reg |= PORT_PCS_CTRL_10;
break;
default:
pr_info("Unknown speed");
goto out;
}
reg |= PORT_PCS_CTRL_FORCE_DUPLEX;
if (phydev->duplex == DUPLEX_FULL)
reg |= PORT_PCS_CTRL_DUPLEX_FULL;
if ((mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds)) &&
(port >= ps->num_ports - 2)) {
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID)
reg |= PORT_PCS_CTRL_RGMII_DELAY_RXCLK;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)
reg |= PORT_PCS_CTRL_RGMII_DELAY_TXCLK;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID)
reg |= (PORT_PCS_CTRL_RGMII_DELAY_RXCLK |
PORT_PCS_CTRL_RGMII_DELAY_TXCLK);
}
_mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_PCS_CTRL, reg);
out:
mutex_unlock(&ps->smi_mutex);
}
static int _mv88e6xxx_stats_wait(struct dsa_switch *ds)
{
int ret;
int i;
for (i = 0; i < 10; i++) {
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL, GLOBAL_STATS_OP);
if ((ret & GLOBAL_STATS_OP_BUSY) == 0)
return 0;
}
return -ETIMEDOUT;
}
static int _mv88e6xxx_stats_snapshot(struct dsa_switch *ds, int port)
{
int ret;
if (mv88e6xxx_6320_family(ds) || mv88e6xxx_6352_family(ds))
port = (port + 1) << 5;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_STATS_OP,
GLOBAL_STATS_OP_CAPTURE_PORT |
GLOBAL_STATS_OP_HIST_RX_TX | port);
if (ret < 0)
return ret;
ret = _mv88e6xxx_stats_wait(ds);
if (ret < 0)
return ret;
return 0;
}
static void _mv88e6xxx_stats_read(struct dsa_switch *ds, int stat, u32 *val)
{
u32 _val;
int ret;
*val = 0;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_STATS_OP,
GLOBAL_STATS_OP_READ_CAPTURED |
GLOBAL_STATS_OP_HIST_RX_TX | stat);
if (ret < 0)
return;
ret = _mv88e6xxx_stats_wait(ds);
if (ret < 0)
return;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL, GLOBAL_STATS_COUNTER_32);
if (ret < 0)
return;
_val = ret << 16;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL, GLOBAL_STATS_COUNTER_01);
if (ret < 0)
return;
*val = _val | ret;
}
static bool have_sw_in_discards(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
switch (ps->id) {
case PORT_SWITCH_ID_6095: case PORT_SWITCH_ID_6161:
case PORT_SWITCH_ID_6165: case PORT_SWITCH_ID_6171:
case PORT_SWITCH_ID_6172: case PORT_SWITCH_ID_6176:
case PORT_SWITCH_ID_6182: case PORT_SWITCH_ID_6185:
case PORT_SWITCH_ID_6352:
return true;
default:
return false;
}
}
static void _mv88e6xxx_get_strings(struct dsa_switch *ds,
int nr_stats,
struct mv88e6xxx_hw_stat *stats,
int port, uint8_t *data)
{
int i;
for (i = 0; i < nr_stats; i++) {
memcpy(data + i * ETH_GSTRING_LEN,
stats[i].string, ETH_GSTRING_LEN);
}
}
static uint64_t _mv88e6xxx_get_ethtool_stat(struct dsa_switch *ds,
int stat,
struct mv88e6xxx_hw_stat *stats,
int port)
{
struct mv88e6xxx_hw_stat *s = stats + stat;
u32 low;
u32 high = 0;
int ret;
u64 value;
if (s->reg >= 0x100) {
ret = _mv88e6xxx_reg_read(ds, REG_PORT(port),
s->reg - 0x100);
if (ret < 0)
return UINT64_MAX;
low = ret;
if (s->sizeof_stat == 4) {
ret = _mv88e6xxx_reg_read(ds, REG_PORT(port),
s->reg - 0x100 + 1);
if (ret < 0)
return UINT64_MAX;
high = ret;
}
} else {
_mv88e6xxx_stats_read(ds, s->reg, &low);
if (s->sizeof_stat == 8)
_mv88e6xxx_stats_read(ds, s->reg + 1, &high);
}
value = (((u64)high) << 16) | low;
return value;
}
static void _mv88e6xxx_get_ethtool_stats(struct dsa_switch *ds,
int nr_stats,
struct mv88e6xxx_hw_stat *stats,
int port, uint64_t *data)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
int i;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_stats_snapshot(ds, port);
if (ret < 0) {
mutex_unlock(&ps->smi_mutex);
return;
}
for (i = 0; i < nr_stats; i++)
data[i] = _mv88e6xxx_get_ethtool_stat(ds, i, stats, port);
mutex_unlock(&ps->smi_mutex);
}
void
mv88e6xxx_get_strings(struct dsa_switch *ds, int port, uint8_t *data)
{
if (have_sw_in_discards(ds))
_mv88e6xxx_get_strings(ds, ARRAY_SIZE(mv88e6xxx_hw_stats),
mv88e6xxx_hw_stats, port, data);
else
_mv88e6xxx_get_strings(ds, ARRAY_SIZE(mv88e6xxx_hw_stats) - 3,
mv88e6xxx_hw_stats, port, data);
}
int mv88e6xxx_get_sset_count(struct dsa_switch *ds)
{
if (have_sw_in_discards(ds))
return ARRAY_SIZE(mv88e6xxx_hw_stats);
return ARRAY_SIZE(mv88e6xxx_hw_stats) - 3;
}
void
mv88e6xxx_get_ethtool_stats(struct dsa_switch *ds,
int port, uint64_t *data)
{
if (have_sw_in_discards(ds))
_mv88e6xxx_get_ethtool_stats(
ds, ARRAY_SIZE(mv88e6xxx_hw_stats),
mv88e6xxx_hw_stats, port, data);
else
_mv88e6xxx_get_ethtool_stats(
ds, ARRAY_SIZE(mv88e6xxx_hw_stats) - 3,
mv88e6xxx_hw_stats, port, data);
}
int mv88e6xxx_get_regs_len(struct dsa_switch *ds, int port)
{
return 32 * sizeof(u16);
}
void mv88e6xxx_get_regs(struct dsa_switch *ds, int port,
struct ethtool_regs *regs, void *_p)
{
u16 *p = _p;
int i;
regs->version = 0;
memset(p, 0xff, 32 * sizeof(u16));
for (i = 0; i < 32; i++) {
int ret;
ret = mv88e6xxx_reg_read(ds, REG_PORT(port), i);
if (ret >= 0)
p[i] = ret;
}
}
static int _mv88e6xxx_wait(struct dsa_switch *ds, int reg, int offset,
u16 mask)
{
unsigned long timeout = jiffies + HZ / 10;
while (time_before(jiffies, timeout)) {
int ret;
ret = _mv88e6xxx_reg_read(ds, reg, offset);
if (ret < 0)
return ret;
if (!(ret & mask))
return 0;
usleep_range(1000, 2000);
}
return -ETIMEDOUT;
}
static int mv88e6xxx_wait(struct dsa_switch *ds, int reg, int offset, u16 mask)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_wait(ds, reg, offset, mask);
mutex_unlock(&ps->smi_mutex);
return ret;
}
static int _mv88e6xxx_phy_wait(struct dsa_switch *ds)
{
return _mv88e6xxx_wait(ds, REG_GLOBAL2, GLOBAL2_SMI_OP,
GLOBAL2_SMI_OP_BUSY);
}
int mv88e6xxx_eeprom_load_wait(struct dsa_switch *ds)
{
return mv88e6xxx_wait(ds, REG_GLOBAL2, GLOBAL2_EEPROM_OP,
GLOBAL2_EEPROM_OP_LOAD);
}
int mv88e6xxx_eeprom_busy_wait(struct dsa_switch *ds)
{
return mv88e6xxx_wait(ds, REG_GLOBAL2, GLOBAL2_EEPROM_OP,
GLOBAL2_EEPROM_OP_BUSY);
}
static int _mv88e6xxx_atu_wait(struct dsa_switch *ds)
{
return _mv88e6xxx_wait(ds, REG_GLOBAL, GLOBAL_ATU_OP,
GLOBAL_ATU_OP_BUSY);
}
static int _mv88e6xxx_scratch_wait(struct dsa_switch *ds)
{
return _mv88e6xxx_wait(ds, REG_GLOBAL2, GLOBAL2_SCRATCH_MISC,
GLOBAL2_SCRATCH_BUSY);
}
static int _mv88e6xxx_phy_read_indirect(struct dsa_switch *ds, int addr,
int regnum)
{
int ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL2, GLOBAL2_SMI_OP,
GLOBAL2_SMI_OP_22_READ | (addr << 5) |
regnum);
if (ret < 0)
return ret;
ret = _mv88e6xxx_phy_wait(ds);
if (ret < 0)
return ret;
return _mv88e6xxx_reg_read(ds, REG_GLOBAL2, GLOBAL2_SMI_DATA);
}
static int _mv88e6xxx_phy_write_indirect(struct dsa_switch *ds, int addr,
int regnum, u16 val)
{
int ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL2, GLOBAL2_SMI_DATA, val);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL2, GLOBAL2_SMI_OP,
GLOBAL2_SMI_OP_22_WRITE | (addr << 5) |
regnum);
return _mv88e6xxx_phy_wait(ds);
}
int mv88e6xxx_get_eee(struct dsa_switch *ds, int port, struct ethtool_eee *e)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int reg;
mutex_lock(&ps->smi_mutex);
reg = _mv88e6xxx_phy_read_indirect(ds, port, 16);
if (reg < 0)
goto out;
e->eee_enabled = !!(reg & 0x0200);
e->tx_lpi_enabled = !!(reg & 0x0100);
reg = _mv88e6xxx_reg_read(ds, REG_PORT(port), PORT_STATUS);
if (reg < 0)
goto out;
e->eee_active = !!(reg & PORT_STATUS_EEE);
reg = 0;
out:
mutex_unlock(&ps->smi_mutex);
return reg;
}
int mv88e6xxx_set_eee(struct dsa_switch *ds, int port,
struct phy_device *phydev, struct ethtool_eee *e)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int reg;
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_phy_read_indirect(ds, port, 16);
if (ret < 0)
goto out;
reg = ret & ~0x0300;
if (e->eee_enabled)
reg |= 0x0200;
if (e->tx_lpi_enabled)
reg |= 0x0100;
ret = _mv88e6xxx_phy_write_indirect(ds, port, 16, reg);
out:
mutex_unlock(&ps->smi_mutex);
return ret;
}
static int _mv88e6xxx_atu_cmd(struct dsa_switch *ds, int fid, u16 cmd)
{
int ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_ATU_FID, fid);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_ATU_OP, cmd);
if (ret < 0)
return ret;
return _mv88e6xxx_atu_wait(ds);
}
static int _mv88e6xxx_flush_fid(struct dsa_switch *ds, int fid)
{
int ret;
ret = _mv88e6xxx_atu_wait(ds);
if (ret < 0)
return ret;
return _mv88e6xxx_atu_cmd(ds, fid, GLOBAL_ATU_OP_FLUSH_NON_STATIC_DB);
}
static int mv88e6xxx_set_port_state(struct dsa_switch *ds, int port, u8 state)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int reg, ret = 0;
u8 oldstate;
mutex_lock(&ps->smi_mutex);
reg = _mv88e6xxx_reg_read(ds, REG_PORT(port), PORT_CONTROL);
if (reg < 0) {
ret = reg;
goto abort;
}
oldstate = reg & PORT_CONTROL_STATE_MASK;
if (oldstate != state) {
if (oldstate >= PORT_CONTROL_STATE_LEARNING &&
state <= PORT_CONTROL_STATE_BLOCKING) {
ret = _mv88e6xxx_flush_fid(ds, ps->fid[port]);
if (ret)
goto abort;
}
reg = (reg & ~PORT_CONTROL_STATE_MASK) | state;
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_CONTROL,
reg);
}
abort:
mutex_unlock(&ps->smi_mutex);
return ret;
}
static int _mv88e6xxx_update_port_config(struct dsa_switch *ds, int port)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
u8 fid = ps->fid[port];
u16 reg = fid << 12;
if (dsa_is_cpu_port(ds, port))
reg |= ds->phys_port_mask;
else
reg |= (ps->bridge_mask[fid] |
(1 << dsa_upstream_port(ds))) & ~(1 << port);
return _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_BASE_VLAN, reg);
}
static int _mv88e6xxx_update_bridge_config(struct dsa_switch *ds, int fid)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int port;
u32 mask;
int ret;
mask = ds->phys_port_mask;
while (mask) {
port = __ffs(mask);
mask &= ~(1 << port);
if (ps->fid[port] != fid)
continue;
ret = _mv88e6xxx_update_port_config(ds, port);
if (ret)
return ret;
}
return _mv88e6xxx_flush_fid(ds, fid);
}
int mv88e6xxx_join_bridge(struct dsa_switch *ds, int port, u32 br_port_mask)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret = 0;
u32 nmask;
int fid;
fid = ps->fid[port];
nmask = br_port_mask & ~(1 << port);
if (nmask)
fid = ps->fid[__ffs(nmask)];
nmask = ps->bridge_mask[fid] | (1 << port);
if (nmask != br_port_mask) {
netdev_err(ds->ports[port],
"join: Bridge port mask mismatch fid=%d mask=0x%x expected 0x%x\n",
fid, br_port_mask, nmask);
return -EINVAL;
}
mutex_lock(&ps->smi_mutex);
ps->bridge_mask[fid] = br_port_mask;
if (fid != ps->fid[port]) {
clear_bit(ps->fid[port], ps->fid_bitmap);
ps->fid[port] = fid;
ret = _mv88e6xxx_update_bridge_config(ds, fid);
}
mutex_unlock(&ps->smi_mutex);
return ret;
}
int mv88e6xxx_leave_bridge(struct dsa_switch *ds, int port, u32 br_port_mask)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
u8 fid, newfid;
int ret;
fid = ps->fid[port];
if (ps->bridge_mask[fid] != br_port_mask) {
netdev_err(ds->ports[port],
"leave: Bridge port mask mismatch fid=%d mask=0x%x expected 0x%x\n",
fid, br_port_mask, ps->bridge_mask[fid]);
return -EINVAL;
}
if (br_port_mask == (1 << port))
return 0;
mutex_lock(&ps->smi_mutex);
newfid = find_next_zero_bit(ps->fid_bitmap, VLAN_N_VID, 1);
if (unlikely(newfid > ps->num_ports)) {
netdev_err(ds->ports[port], "all first %d FIDs are used\n",
ps->num_ports);
ret = -ENOSPC;
goto unlock;
}
ps->fid[port] = newfid;
set_bit(newfid, ps->fid_bitmap);
ps->bridge_mask[fid] &= ~(1 << port);
ps->bridge_mask[newfid] = 1 << port;
ret = _mv88e6xxx_update_bridge_config(ds, fid);
if (!ret)
ret = _mv88e6xxx_update_bridge_config(ds, newfid);
unlock:
mutex_unlock(&ps->smi_mutex);
return ret;
}
int mv88e6xxx_port_stp_update(struct dsa_switch *ds, int port, u8 state)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int stp_state;
switch (state) {
case BR_STATE_DISABLED:
stp_state = PORT_CONTROL_STATE_DISABLED;
break;
case BR_STATE_BLOCKING:
case BR_STATE_LISTENING:
stp_state = PORT_CONTROL_STATE_BLOCKING;
break;
case BR_STATE_LEARNING:
stp_state = PORT_CONTROL_STATE_LEARNING;
break;
case BR_STATE_FORWARDING:
default:
stp_state = PORT_CONTROL_STATE_FORWARDING;
break;
}
netdev_dbg(ds->ports[port], "port state %d [%d]\n", state, stp_state);
ps->port_state[port] = stp_state;
set_bit(port, &ps->port_state_update_mask);
schedule_work(&ps->bridge_work);
return 0;
}
int mv88e6xxx_port_pvid_get(struct dsa_switch *ds, int port, u16 *pvid)
{
int ret;
ret = mv88e6xxx_reg_read(ds, REG_PORT(port), PORT_DEFAULT_VLAN);
if (ret < 0)
return ret;
*pvid = ret & PORT_DEFAULT_VLAN_MASK;
return 0;
}
int mv88e6xxx_port_pvid_set(struct dsa_switch *ds, int port, u16 pvid)
{
return mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_DEFAULT_VLAN,
pvid & PORT_DEFAULT_VLAN_MASK);
}
static int _mv88e6xxx_vtu_wait(struct dsa_switch *ds)
{
return _mv88e6xxx_wait(ds, REG_GLOBAL, GLOBAL_VTU_OP,
GLOBAL_VTU_OP_BUSY);
}
static int _mv88e6xxx_vtu_cmd(struct dsa_switch *ds, u16 op)
{
int ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_OP, op);
if (ret < 0)
return ret;
return _mv88e6xxx_vtu_wait(ds);
}
static int _mv88e6xxx_vtu_stu_flush(struct dsa_switch *ds)
{
int ret;
ret = _mv88e6xxx_vtu_wait(ds);
if (ret < 0)
return ret;
return _mv88e6xxx_vtu_cmd(ds, GLOBAL_VTU_OP_FLUSH_ALL);
}
static int _mv88e6xxx_vtu_stu_data_read(struct dsa_switch *ds,
struct mv88e6xxx_vtu_stu_entry *entry,
unsigned int nibble_offset)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
u16 regs[3];
int i;
int ret;
for (i = 0; i < 3; ++i) {
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL,
GLOBAL_VTU_DATA_0_3 + i);
if (ret < 0)
return ret;
regs[i] = ret;
}
for (i = 0; i < ps->num_ports; ++i) {
unsigned int shift = (i % 4) * 4 + nibble_offset;
u16 reg = regs[i / 4];
entry->data[i] = (reg >> shift) & GLOBAL_VTU_STU_DATA_MASK;
}
return 0;
}
static int _mv88e6xxx_vtu_stu_data_write(struct dsa_switch *ds,
struct mv88e6xxx_vtu_stu_entry *entry,
unsigned int nibble_offset)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
u16 regs[3] = { 0 };
int i;
int ret;
for (i = 0; i < ps->num_ports; ++i) {
unsigned int shift = (i % 4) * 4 + nibble_offset;
u8 data = entry->data[i];
regs[i / 4] |= (data & GLOBAL_VTU_STU_DATA_MASK) << shift;
}
for (i = 0; i < 3; ++i) {
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL,
GLOBAL_VTU_DATA_0_3 + i, regs[i]);
if (ret < 0)
return ret;
}
return 0;
}
static int _mv88e6xxx_vtu_getnext(struct dsa_switch *ds, u16 vid,
struct mv88e6xxx_vtu_stu_entry *entry)
{
struct mv88e6xxx_vtu_stu_entry next = { 0 };
int ret;
ret = _mv88e6xxx_vtu_wait(ds);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_VID,
vid & GLOBAL_VTU_VID_MASK);
if (ret < 0)
return ret;
ret = _mv88e6xxx_vtu_cmd(ds, GLOBAL_VTU_OP_VTU_GET_NEXT);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL, GLOBAL_VTU_VID);
if (ret < 0)
return ret;
next.vid = ret & GLOBAL_VTU_VID_MASK;
next.valid = !!(ret & GLOBAL_VTU_VID_VALID);
if (next.valid) {
ret = _mv88e6xxx_vtu_stu_data_read(ds, &next, 0);
if (ret < 0)
return ret;
if (mv88e6xxx_6097_family(ds) || mv88e6xxx_6165_family(ds) ||
mv88e6xxx_6351_family(ds) || mv88e6xxx_6352_family(ds)) {
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL,
GLOBAL_VTU_FID);
if (ret < 0)
return ret;
next.fid = ret & GLOBAL_VTU_FID_MASK;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL,
GLOBAL_VTU_SID);
if (ret < 0)
return ret;
next.sid = ret & GLOBAL_VTU_SID_MASK;
}
}
*entry = next;
return 0;
}
static int _mv88e6xxx_vtu_loadpurge(struct dsa_switch *ds,
struct mv88e6xxx_vtu_stu_entry *entry)
{
u16 reg = 0;
int ret;
ret = _mv88e6xxx_vtu_wait(ds);
if (ret < 0)
return ret;
if (!entry->valid)
goto loadpurge;
ret = _mv88e6xxx_vtu_stu_data_write(ds, entry, 0);
if (ret < 0)
return ret;
if (mv88e6xxx_6097_family(ds) || mv88e6xxx_6165_family(ds) ||
mv88e6xxx_6351_family(ds) || mv88e6xxx_6352_family(ds)) {
reg = entry->sid & GLOBAL_VTU_SID_MASK;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_SID, reg);
if (ret < 0)
return ret;
reg = entry->fid & GLOBAL_VTU_FID_MASK;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_FID, reg);
if (ret < 0)
return ret;
}
reg = GLOBAL_VTU_VID_VALID;
loadpurge:
reg |= entry->vid & GLOBAL_VTU_VID_MASK;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_VID, reg);
if (ret < 0)
return ret;
return _mv88e6xxx_vtu_cmd(ds, GLOBAL_VTU_OP_VTU_LOAD_PURGE);
}
static int _mv88e6xxx_stu_getnext(struct dsa_switch *ds, u8 sid,
struct mv88e6xxx_vtu_stu_entry *entry)
{
struct mv88e6xxx_vtu_stu_entry next = { 0 };
int ret;
ret = _mv88e6xxx_vtu_wait(ds);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_SID,
sid & GLOBAL_VTU_SID_MASK);
if (ret < 0)
return ret;
ret = _mv88e6xxx_vtu_cmd(ds, GLOBAL_VTU_OP_STU_GET_NEXT);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL, GLOBAL_VTU_SID);
if (ret < 0)
return ret;
next.sid = ret & GLOBAL_VTU_SID_MASK;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL, GLOBAL_VTU_VID);
if (ret < 0)
return ret;
next.valid = !!(ret & GLOBAL_VTU_VID_VALID);
if (next.valid) {
ret = _mv88e6xxx_vtu_stu_data_read(ds, &next, 2);
if (ret < 0)
return ret;
}
*entry = next;
return 0;
}
static int _mv88e6xxx_stu_loadpurge(struct dsa_switch *ds,
struct mv88e6xxx_vtu_stu_entry *entry)
{
u16 reg = 0;
int ret;
ret = _mv88e6xxx_vtu_wait(ds);
if (ret < 0)
return ret;
if (!entry->valid)
goto loadpurge;
ret = _mv88e6xxx_vtu_stu_data_write(ds, entry, 2);
if (ret < 0)
return ret;
reg = GLOBAL_VTU_VID_VALID;
loadpurge:
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_VID, reg);
if (ret < 0)
return ret;
reg = entry->sid & GLOBAL_VTU_SID_MASK;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_SID, reg);
if (ret < 0)
return ret;
return _mv88e6xxx_vtu_cmd(ds, GLOBAL_VTU_OP_STU_LOAD_PURGE);
}
static int _mv88e6xxx_vlan_init(struct dsa_switch *ds, u16 vid,
struct mv88e6xxx_vtu_stu_entry *entry)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_vtu_stu_entry vlan = {
.valid = true,
.vid = vid,
};
int i;
for (i = 0; i < ps->num_ports; ++i)
vlan.data[i] = dsa_is_cpu_port(ds, i) ?
GLOBAL_VTU_DATA_MEMBER_TAG_TAGGED :
GLOBAL_VTU_DATA_MEMBER_TAG_NON_MEMBER;
if (mv88e6xxx_6097_family(ds) || mv88e6xxx_6165_family(ds) ||
mv88e6xxx_6351_family(ds) || mv88e6xxx_6352_family(ds)) {
struct mv88e6xxx_vtu_stu_entry vstp;
int err;
vlan.sid = 0;
err = _mv88e6xxx_stu_getnext(ds, GLOBAL_VTU_SID_MASK, &vstp);
if (err)
return err;
if (vstp.sid != vlan.sid || !vstp.valid) {
memset(&vstp, 0, sizeof(vstp));
vstp.valid = true;
vstp.sid = vlan.sid;
err = _mv88e6xxx_stu_loadpurge(ds, &vstp);
if (err)
return err;
}
vlan.fid = find_next_zero_bit(ps->fid_bitmap, VLAN_N_VID,
ps->num_ports + 1);
if (unlikely(vlan.fid == VLAN_N_VID)) {
pr_err("no more FID available for VLAN %d\n", vid);
return -ENOSPC;
}
err = _mv88e6xxx_flush_fid(ds, vlan.fid);
if (err)
return err;
set_bit(vlan.fid, ps->fid_bitmap);
}
*entry = vlan;
return 0;
}
int mv88e6xxx_port_vlan_add(struct dsa_switch *ds, int port, u16 vid,
bool untagged)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_vtu_stu_entry vlan;
int err;
mutex_lock(&ps->smi_mutex);
err = _mv88e6xxx_vtu_getnext(ds, vid - 1, &vlan);
if (err)
goto unlock;
if (vlan.vid != vid || !vlan.valid) {
err = _mv88e6xxx_vlan_init(ds, vid, &vlan);
if (err)
goto unlock;
}
vlan.data[port] = untagged ?
GLOBAL_VTU_DATA_MEMBER_TAG_UNTAGGED :
GLOBAL_VTU_DATA_MEMBER_TAG_TAGGED;
err = _mv88e6xxx_vtu_loadpurge(ds, &vlan);
unlock:
mutex_unlock(&ps->smi_mutex);
return err;
}
int mv88e6xxx_port_vlan_del(struct dsa_switch *ds, int port, u16 vid)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_vtu_stu_entry vlan;
bool keep = false;
int i, err;
mutex_lock(&ps->smi_mutex);
err = _mv88e6xxx_vtu_getnext(ds, vid - 1, &vlan);
if (err)
goto unlock;
if (vlan.vid != vid || !vlan.valid ||
vlan.data[port] == GLOBAL_VTU_DATA_MEMBER_TAG_NON_MEMBER) {
err = -ENOENT;
goto unlock;
}
vlan.data[port] = GLOBAL_VTU_DATA_MEMBER_TAG_NON_MEMBER;
for (i = 0; i < ps->num_ports; ++i) {
if (dsa_is_cpu_port(ds, i))
continue;
if (vlan.data[i] != GLOBAL_VTU_DATA_MEMBER_TAG_NON_MEMBER) {
keep = true;
break;
}
}
vlan.valid = keep;
err = _mv88e6xxx_vtu_loadpurge(ds, &vlan);
if (err)
goto unlock;
if (!keep)
clear_bit(vlan.fid, ps->fid_bitmap);
unlock:
mutex_unlock(&ps->smi_mutex);
return err;
}
static int _mv88e6xxx_port_vtu_getnext(struct dsa_switch *ds, int port, u16 vid,
struct mv88e6xxx_vtu_stu_entry *entry)
{
int err;
do {
if (vid == 4095)
return -ENOENT;
err = _mv88e6xxx_vtu_getnext(ds, vid, entry);
if (err)
return err;
if (!entry->valid)
return -ENOENT;
vid = entry->vid;
} while (entry->data[port] != GLOBAL_VTU_DATA_MEMBER_TAG_TAGGED &&
entry->data[port] != GLOBAL_VTU_DATA_MEMBER_TAG_UNTAGGED);
return 0;
}
int mv88e6xxx_vlan_getnext(struct dsa_switch *ds, u16 *vid,
unsigned long *ports, unsigned long *untagged)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_vtu_stu_entry next;
int port;
int err;
if (*vid == 4095)
return -ENOENT;
mutex_lock(&ps->smi_mutex);
err = _mv88e6xxx_vtu_getnext(ds, *vid, &next);
mutex_unlock(&ps->smi_mutex);
if (err)
return err;
if (!next.valid)
return -ENOENT;
*vid = next.vid;
for (port = 0; port < ps->num_ports; ++port) {
clear_bit(port, ports);
clear_bit(port, untagged);
if (dsa_is_cpu_port(ds, port))
continue;
if (next.data[port] == GLOBAL_VTU_DATA_MEMBER_TAG_TAGGED ||
next.data[port] == GLOBAL_VTU_DATA_MEMBER_TAG_UNTAGGED)
set_bit(port, ports);
if (next.data[port] == GLOBAL_VTU_DATA_MEMBER_TAG_UNTAGGED)
set_bit(port, untagged);
}
return 0;
}
static int _mv88e6xxx_atu_mac_write(struct dsa_switch *ds,
const unsigned char *addr)
{
int i, ret;
for (i = 0; i < 3; i++) {
ret = _mv88e6xxx_reg_write(
ds, REG_GLOBAL, GLOBAL_ATU_MAC_01 + i,
(addr[i * 2] << 8) | addr[i * 2 + 1]);
if (ret < 0)
return ret;
}
return 0;
}
static int _mv88e6xxx_atu_mac_read(struct dsa_switch *ds, unsigned char *addr)
{
int i, ret;
for (i = 0; i < 3; i++) {
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL,
GLOBAL_ATU_MAC_01 + i);
if (ret < 0)
return ret;
addr[i * 2] = ret >> 8;
addr[i * 2 + 1] = ret & 0xff;
}
return 0;
}
static int _mv88e6xxx_atu_load(struct dsa_switch *ds,
struct mv88e6xxx_atu_entry *entry)
{
u16 reg = 0;
int ret;
ret = _mv88e6xxx_atu_wait(ds);
if (ret < 0)
return ret;
ret = _mv88e6xxx_atu_mac_write(ds, entry->mac);
if (ret < 0)
return ret;
if (entry->state != GLOBAL_ATU_DATA_STATE_UNUSED) {
unsigned int mask, shift;
if (entry->trunk) {
reg |= GLOBAL_ATU_DATA_TRUNK;
mask = GLOBAL_ATU_DATA_TRUNK_ID_MASK;
shift = GLOBAL_ATU_DATA_TRUNK_ID_SHIFT;
} else {
mask = GLOBAL_ATU_DATA_PORT_VECTOR_MASK;
shift = GLOBAL_ATU_DATA_PORT_VECTOR_SHIFT;
}
reg |= (entry->portv_trunkid << shift) & mask;
}
reg |= entry->state & GLOBAL_ATU_DATA_STATE_MASK;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_ATU_DATA, reg);
if (ret < 0)
return ret;
return _mv88e6xxx_atu_cmd(ds, entry->fid, GLOBAL_ATU_OP_LOAD_DB);
}
static int _mv88e6xxx_port_vid_to_fid(struct dsa_switch *ds, int port, u16 vid)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_vtu_stu_entry vlan;
int err;
if (vid == 0)
return ps->fid[port];
err = _mv88e6xxx_port_vtu_getnext(ds, port, vid - 1, &vlan);
if (err)
return err;
if (vlan.vid == vid)
return vlan.fid;
return -ENOENT;
}
static int _mv88e6xxx_port_fdb_load(struct dsa_switch *ds, int port,
const unsigned char *addr, u16 vid,
u8 state)
{
struct mv88e6xxx_atu_entry entry = { 0 };
int ret;
ret = _mv88e6xxx_port_vid_to_fid(ds, port, vid);
if (ret < 0)
return ret;
entry.fid = ret;
entry.state = state;
ether_addr_copy(entry.mac, addr);
if (state != GLOBAL_ATU_DATA_STATE_UNUSED) {
entry.trunk = false;
entry.portv_trunkid = BIT(port);
}
return _mv88e6xxx_atu_load(ds, &entry);
}
int mv88e6xxx_port_fdb_add(struct dsa_switch *ds, int port,
const unsigned char *addr, u16 vid)
{
int state = is_multicast_ether_addr(addr) ?
GLOBAL_ATU_DATA_STATE_MC_STATIC :
GLOBAL_ATU_DATA_STATE_UC_STATIC;
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_port_fdb_load(ds, port, addr, vid, state);
mutex_unlock(&ps->smi_mutex);
return ret;
}
int mv88e6xxx_port_fdb_del(struct dsa_switch *ds, int port,
const unsigned char *addr, u16 vid)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_port_fdb_load(ds, port, addr, vid,
GLOBAL_ATU_DATA_STATE_UNUSED);
mutex_unlock(&ps->smi_mutex);
return ret;
}
static int _mv88e6xxx_atu_getnext(struct dsa_switch *ds, u16 fid,
const unsigned char *addr,
struct mv88e6xxx_atu_entry *entry)
{
struct mv88e6xxx_atu_entry next = { 0 };
int ret;
next.fid = fid;
ret = _mv88e6xxx_atu_wait(ds);
if (ret < 0)
return ret;
ret = _mv88e6xxx_atu_mac_write(ds, addr);
if (ret < 0)
return ret;
ret = _mv88e6xxx_atu_cmd(ds, fid, GLOBAL_ATU_OP_GET_NEXT_DB);
if (ret < 0)
return ret;
ret = _mv88e6xxx_atu_mac_read(ds, next.mac);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL, GLOBAL_ATU_DATA);
if (ret < 0)
return ret;
next.state = ret & GLOBAL_ATU_DATA_STATE_MASK;
if (next.state != GLOBAL_ATU_DATA_STATE_UNUSED) {
unsigned int mask, shift;
if (ret & GLOBAL_ATU_DATA_TRUNK) {
next.trunk = true;
mask = GLOBAL_ATU_DATA_TRUNK_ID_MASK;
shift = GLOBAL_ATU_DATA_TRUNK_ID_SHIFT;
} else {
next.trunk = false;
mask = GLOBAL_ATU_DATA_PORT_VECTOR_MASK;
shift = GLOBAL_ATU_DATA_PORT_VECTOR_SHIFT;
}
next.portv_trunkid = (ret & mask) >> shift;
}
*entry = next;
return 0;
}
int mv88e6xxx_port_fdb_getnext(struct dsa_switch *ds, int port,
unsigned char *addr, u16 *vid, bool *is_static)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_atu_entry next;
u16 fid;
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_port_vid_to_fid(ds, port, *vid);
if (ret < 0)
goto unlock;
fid = ret;
do {
if (is_broadcast_ether_addr(addr)) {
struct mv88e6xxx_vtu_stu_entry vtu;
ret = _mv88e6xxx_port_vtu_getnext(ds, port, *vid, &vtu);
if (ret < 0)
goto unlock;
*vid = vtu.vid;
fid = vtu.fid;
}
ret = _mv88e6xxx_atu_getnext(ds, fid, addr, &next);
if (ret < 0)
goto unlock;
ether_addr_copy(addr, next.mac);
if (next.state == GLOBAL_ATU_DATA_STATE_UNUSED)
continue;
} while (next.trunk || (next.portv_trunkid & BIT(port)) == 0);
*is_static = next.state == (is_multicast_ether_addr(addr) ?
GLOBAL_ATU_DATA_STATE_MC_STATIC :
GLOBAL_ATU_DATA_STATE_UC_STATIC);
unlock:
mutex_unlock(&ps->smi_mutex);
return ret;
}
static void mv88e6xxx_bridge_work(struct work_struct *work)
{
struct mv88e6xxx_priv_state *ps;
struct dsa_switch *ds;
int port;
ps = container_of(work, struct mv88e6xxx_priv_state, bridge_work);
ds = ((struct dsa_switch *)ps) - 1;
while (ps->port_state_update_mask) {
port = __ffs(ps->port_state_update_mask);
clear_bit(port, &ps->port_state_update_mask);
mv88e6xxx_set_port_state(ds, port, ps->port_state[port]);
}
}
static int mv88e6xxx_setup_port(struct dsa_switch *ds, int port)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret, fid;
u16 reg;
mutex_lock(&ps->smi_mutex);
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6185_family(ds) || mv88e6xxx_6095_family(ds) ||
mv88e6xxx_6065_family(ds) || mv88e6xxx_6320_family(ds)) {
reg = _mv88e6xxx_reg_read(ds, REG_PORT(port), PORT_PCS_CTRL);
if (dsa_is_cpu_port(ds, port) || dsa_is_dsa_port(ds, port)) {
reg &= ~PORT_PCS_CTRL_UNFORCED;
reg |= PORT_PCS_CTRL_FORCE_LINK |
PORT_PCS_CTRL_LINK_UP |
PORT_PCS_CTRL_DUPLEX_FULL |
PORT_PCS_CTRL_FORCE_DUPLEX;
if (mv88e6xxx_6065_family(ds))
reg |= PORT_PCS_CTRL_100;
else
reg |= PORT_PCS_CTRL_1000;
} else {
reg |= PORT_PCS_CTRL_UNFORCED;
}
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_PCS_CTRL, reg);
if (ret)
goto abort;
}
reg = 0;
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6095_family(ds) || mv88e6xxx_6065_family(ds) ||
mv88e6xxx_6185_family(ds) || mv88e6xxx_6320_family(ds))
reg = PORT_CONTROL_IGMP_MLD_SNOOP |
PORT_CONTROL_USE_TAG | PORT_CONTROL_USE_IP |
PORT_CONTROL_STATE_FORWARDING;
if (dsa_is_cpu_port(ds, port)) {
if (mv88e6xxx_6095_family(ds) || mv88e6xxx_6185_family(ds))
reg |= PORT_CONTROL_DSA_TAG;
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6320_family(ds)) {
if (ds->dst->tag_protocol == DSA_TAG_PROTO_EDSA)
reg |= PORT_CONTROL_FRAME_ETHER_TYPE_DSA;
else
reg |= PORT_CONTROL_FRAME_MODE_DSA;
reg |= PORT_CONTROL_FORWARD_UNKNOWN |
PORT_CONTROL_FORWARD_UNKNOWN_MC;
}
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6095_family(ds) || mv88e6xxx_6065_family(ds) ||
mv88e6xxx_6185_family(ds) || mv88e6xxx_6320_family(ds)) {
if (ds->dst->tag_protocol == DSA_TAG_PROTO_EDSA)
reg |= PORT_CONTROL_EGRESS_ADD_TAG;
}
}
if (dsa_is_dsa_port(ds, port)) {
if (mv88e6xxx_6095_family(ds) || mv88e6xxx_6185_family(ds))
reg |= PORT_CONTROL_DSA_TAG;
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6320_family(ds)) {
reg |= PORT_CONTROL_FRAME_MODE_DSA;
}
if (port == dsa_upstream_port(ds))
reg |= PORT_CONTROL_FORWARD_UNKNOWN |
PORT_CONTROL_FORWARD_UNKNOWN_MC;
}
if (reg) {
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_CONTROL, reg);
if (ret)
goto abort;
}
reg = 0;
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6095_family(ds) || mv88e6xxx_6320_family(ds))
reg = PORT_CONTROL_2_MAP_DA;
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6320_family(ds))
reg |= PORT_CONTROL_2_JUMBO_10240;
if (mv88e6xxx_6095_family(ds) || mv88e6xxx_6185_family(ds)) {
reg |= dsa_upstream_port(ds);
if (port == dsa_upstream_port(ds))
reg |= PORT_CONTROL_2_FORWARD_UNKNOWN;
}
reg |= PORT_CONTROL_2_8021Q_FALLBACK;
if (reg) {
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_CONTROL_2, reg);
if (ret)
goto abort;
}
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_ASSOC_VECTOR,
1 << port);
if (ret)
goto abort;
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_RATE_CONTROL_2,
0x0000);
if (ret)
goto abort;
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6320_family(ds)) {
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_PAUSE_CTRL, 0x0000);
if (ret)
goto abort;
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_ATU_CONTROL, 0x0000);
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_PRI_OVERRIDE, 0x0000);
if (ret)
goto abort;
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_ETH_TYPE, ETH_P_EDSA);
if (ret)
goto abort;
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_TAG_REGMAP_0123, 0x3210);
if (ret)
goto abort;
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_TAG_REGMAP_4567, 0x7654);
if (ret)
goto abort;
}
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6185_family(ds) || mv88e6xxx_6095_family(ds) ||
mv88e6xxx_6320_family(ds)) {
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_RATE_CONTROL, 0x0001);
if (ret)
goto abort;
}
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_CONTROL_1, 0x0000);
if (ret)
goto abort;
fid = port + 1;
ps->fid[port] = fid;
set_bit(fid, ps->fid_bitmap);
if (!dsa_is_cpu_port(ds, port))
ps->bridge_mask[fid] = 1 << port;
ret = _mv88e6xxx_update_port_config(ds, port);
if (ret)
goto abort;
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_DEFAULT_VLAN,
0x0000);
abort:
mutex_unlock(&ps->smi_mutex);
return ret;
}
int mv88e6xxx_setup_ports(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
int i;
for (i = 0; i < ps->num_ports; i++) {
ret = mv88e6xxx_setup_port(ds, i);
if (ret < 0)
return ret;
}
return 0;
}
static int mv88e6xxx_regs_show(struct seq_file *s, void *p)
{
struct dsa_switch *ds = s->private;
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int reg, port;
seq_puts(s, " GLOBAL GLOBAL2 ");
for (port = 0 ; port < ps->num_ports; port++)
seq_printf(s, " %2d ", port);
seq_puts(s, "\n");
for (reg = 0; reg < 32; reg++) {
seq_printf(s, "%2x: ", reg);
seq_printf(s, " %4x %4x ",
mv88e6xxx_reg_read(ds, REG_GLOBAL, reg),
mv88e6xxx_reg_read(ds, REG_GLOBAL2, reg));
for (port = 0 ; port < ps->num_ports; port++)
seq_printf(s, "%4x ",
mv88e6xxx_reg_read(ds, REG_PORT(port), reg));
seq_puts(s, "\n");
}
return 0;
}
static int mv88e6xxx_regs_open(struct inode *inode, struct file *file)
{
return single_open(file, mv88e6xxx_regs_show, inode->i_private);
}
static void mv88e6xxx_atu_show_header(struct seq_file *s)
{
seq_puts(s, "DB T/P Vec State Addr\n");
}
static void mv88e6xxx_atu_show_entry(struct seq_file *s, int dbnum,
unsigned char *addr, int data)
{
bool trunk = !!(data & GLOBAL_ATU_DATA_TRUNK);
int portvec = ((data & GLOBAL_ATU_DATA_PORT_VECTOR_MASK) >>
GLOBAL_ATU_DATA_PORT_VECTOR_SHIFT);
int state = data & GLOBAL_ATU_DATA_STATE_MASK;
seq_printf(s, "%03x %5s %10pb %x %pM\n",
dbnum, (trunk ? "Trunk" : "Port"), &portvec, state, addr);
}
static int mv88e6xxx_atu_show_db(struct seq_file *s, struct dsa_switch *ds,
int dbnum)
{
unsigned char bcast[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
unsigned char addr[6];
int ret, data, state;
ret = _mv88e6xxx_atu_mac_write(ds, bcast);
if (ret < 0)
return ret;
do {
ret = _mv88e6xxx_atu_cmd(ds, dbnum, GLOBAL_ATU_OP_GET_NEXT_DB);
if (ret < 0)
return ret;
data = _mv88e6xxx_reg_read(ds, REG_GLOBAL, GLOBAL_ATU_DATA);
if (data < 0)
return data;
state = data & GLOBAL_ATU_DATA_STATE_MASK;
if (state == GLOBAL_ATU_DATA_STATE_UNUSED)
break;
ret = _mv88e6xxx_atu_mac_read(ds, addr);
if (ret < 0)
return ret;
mv88e6xxx_atu_show_entry(s, dbnum, addr, data);
} while (state != GLOBAL_ATU_DATA_STATE_UNUSED);
return 0;
}
static int mv88e6xxx_atu_show(struct seq_file *s, void *p)
{
struct dsa_switch *ds = s->private;
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int dbnum;
mv88e6xxx_atu_show_header(s);
for (dbnum = 0; dbnum < 255; dbnum++) {
mutex_lock(&ps->smi_mutex);
mv88e6xxx_atu_show_db(s, ds, dbnum);
mutex_unlock(&ps->smi_mutex);
}
return 0;
}
static int mv88e6xxx_atu_open(struct inode *inode, struct file *file)
{
return single_open(file, mv88e6xxx_atu_show, inode->i_private);
}
static void mv88e6xxx_stats_show_header(struct seq_file *s,
struct mv88e6xxx_priv_state *ps)
{
int port;
seq_puts(s, " Statistic ");
for (port = 0 ; port < ps->num_ports; port++)
seq_printf(s, "Port %2d ", port);
seq_puts(s, "\n");
}
static int mv88e6xxx_stats_show(struct seq_file *s, void *p)
{
struct dsa_switch *ds = s->private;
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_hw_stat *stats = mv88e6xxx_hw_stats;
int port, stat, max_stats;
uint64_t value;
if (have_sw_in_discards(ds))
max_stats = ARRAY_SIZE(mv88e6xxx_hw_stats);
else
max_stats = ARRAY_SIZE(mv88e6xxx_hw_stats) - 3;
mv88e6xxx_stats_show_header(s, ps);
mutex_lock(&ps->smi_mutex);
for (stat = 0; stat < max_stats; stat++) {
seq_printf(s, "%19s: ", stats[stat].string);
for (port = 0 ; port < ps->num_ports; port++) {
_mv88e6xxx_stats_snapshot(ds, port);
value = _mv88e6xxx_get_ethtool_stat(ds, stat, stats,
port);
seq_printf(s, "%8llu ", value);
}
seq_puts(s, "\n");
}
mutex_unlock(&ps->smi_mutex);
return 0;
}
static int mv88e6xxx_stats_open(struct inode *inode, struct file *file)
{
return single_open(file, mv88e6xxx_stats_show, inode->i_private);
}
static int mv88e6xxx_device_map_show(struct seq_file *s, void *p)
{
struct dsa_switch *ds = s->private;
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int target, ret;
seq_puts(s, "Target Port\n");
mutex_lock(&ps->smi_mutex);
for (target = 0; target < 32; target++) {
ret = _mv88e6xxx_reg_write(
ds, REG_GLOBAL2, GLOBAL2_DEVICE_MAPPING,
target << GLOBAL2_DEVICE_MAPPING_TARGET_SHIFT);
if (ret < 0)
goto out;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL2,
GLOBAL2_DEVICE_MAPPING);
seq_printf(s, " %2d %2d\n", target,
ret & GLOBAL2_DEVICE_MAPPING_PORT_MASK);
}
out:
mutex_unlock(&ps->smi_mutex);
return 0;
}
static int mv88e6xxx_device_map_open(struct inode *inode, struct file *file)
{
return single_open(file, mv88e6xxx_device_map_show, inode->i_private);
}
static int mv88e6xxx_scratch_show(struct seq_file *s, void *p)
{
struct dsa_switch *ds = s->private;
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int reg, ret;
seq_puts(s, "Register Value\n");
mutex_lock(&ps->smi_mutex);
for (reg = 0; reg < 0x80; reg++) {
ret = _mv88e6xxx_reg_write(
ds, REG_GLOBAL2, GLOBAL2_SCRATCH_MISC,
reg << GLOBAL2_SCRATCH_REGISTER_SHIFT);
if (ret < 0)
goto out;
ret = _mv88e6xxx_scratch_wait(ds);
if (ret < 0)
goto out;
ret = _mv88e6xxx_reg_read(ds, REG_GLOBAL2,
GLOBAL2_SCRATCH_MISC);
seq_printf(s, " %2x %2x\n", reg,
ret & GLOBAL2_SCRATCH_VALUE_MASK);
}
out:
mutex_unlock(&ps->smi_mutex);
return 0;
}
static int mv88e6xxx_scratch_open(struct inode *inode, struct file *file)
{
return single_open(file, mv88e6xxx_scratch_show, inode->i_private);
}
int mv88e6xxx_setup_common(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
char *name;
mutex_init(&ps->smi_mutex);
ps->id = REG_READ(REG_PORT(0), PORT_SWITCH_ID) & 0xfff0;
INIT_WORK(&ps->bridge_work, mv88e6xxx_bridge_work);
name = kasprintf(GFP_KERNEL, "dsa%d", ds->index);
ps->dbgfs = debugfs_create_dir(name, NULL);
kfree(name);
debugfs_create_file("regs", S_IRUGO, ps->dbgfs, ds,
&mv88e6xxx_regs_fops);
debugfs_create_file("atu", S_IRUGO, ps->dbgfs, ds,
&mv88e6xxx_atu_fops);
debugfs_create_file("stats", S_IRUGO, ps->dbgfs, ds,
&mv88e6xxx_stats_fops);
debugfs_create_file("device_map", S_IRUGO, ps->dbgfs, ds,
&mv88e6xxx_device_map_fops);
debugfs_create_file("scratch", S_IRUGO, ps->dbgfs, ds,
&mv88e6xxx_scratch_fops);
return 0;
}
int mv88e6xxx_setup_global(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
int i;
REG_WRITE(REG_GLOBAL, GLOBAL_ATU_CONTROL,
0x0140 | GLOBAL_ATU_CONTROL_LEARN2ALL);
REG_WRITE(REG_GLOBAL, GLOBAL_IP_PRI_0, 0x0000);
REG_WRITE(REG_GLOBAL, GLOBAL_IP_PRI_1, 0x0000);
REG_WRITE(REG_GLOBAL, GLOBAL_IP_PRI_2, 0x5555);
REG_WRITE(REG_GLOBAL, GLOBAL_IP_PRI_3, 0x5555);
REG_WRITE(REG_GLOBAL, GLOBAL_IP_PRI_4, 0xaaaa);
REG_WRITE(REG_GLOBAL, GLOBAL_IP_PRI_5, 0xaaaa);
REG_WRITE(REG_GLOBAL, GLOBAL_IP_PRI_6, 0xffff);
REG_WRITE(REG_GLOBAL, GLOBAL_IP_PRI_7, 0xffff);
REG_WRITE(REG_GLOBAL, GLOBAL_IEEE_PRI, 0xfa41);
REG_WRITE(REG_GLOBAL2, GLOBAL2_MGMT_EN_0X, 0xffff);
REG_WRITE(REG_GLOBAL2, GLOBAL2_SWITCH_MGMT,
0x7 | GLOBAL2_SWITCH_MGMT_RSVD2CPU | 0x70 |
GLOBAL2_SWITCH_MGMT_FORCE_FLOW_CTRL_PRI);
for (i = 0; i < 32; i++) {
int nexthop = 0x1f;
if (ds->pd->rtable &&
i != ds->index && i < ds->dst->pd->nr_chips)
nexthop = ds->pd->rtable[i] & 0x1f;
REG_WRITE(REG_GLOBAL2, GLOBAL2_DEVICE_MAPPING,
GLOBAL2_DEVICE_MAPPING_UPDATE |
(i << GLOBAL2_DEVICE_MAPPING_TARGET_SHIFT) |
nexthop);
}
for (i = 0; i < 8; i++)
REG_WRITE(REG_GLOBAL2, GLOBAL2_TRUNK_MASK,
0x8000 | (i << GLOBAL2_TRUNK_MASK_NUM_SHIFT) |
((1 << ps->num_ports) - 1));
for (i = 0; i < 16; i++)
REG_WRITE(REG_GLOBAL2, GLOBAL2_TRUNK_MAPPING,
GLOBAL2_TRUNK_MAPPING_UPDATE |
(i << GLOBAL2_TRUNK_MAPPING_ID_SHIFT));
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6320_family(ds)) {
REG_WRITE(REG_GLOBAL2, GLOBAL2_MGMT_EN_2X, 0xffff);
REG_WRITE(REG_GLOBAL2, GLOBAL2_PVT_ADDR, 0x9000);
for (i = 0; i < 16; i++)
REG_WRITE(REG_GLOBAL2, GLOBAL2_PRIO_OVERRIDE,
0x8000 | (i << 8));
}
if (mv88e6xxx_6352_family(ds) || mv88e6xxx_6351_family(ds) ||
mv88e6xxx_6165_family(ds) || mv88e6xxx_6097_family(ds) ||
mv88e6xxx_6185_family(ds) || mv88e6xxx_6095_family(ds) ||
mv88e6xxx_6320_family(ds)) {
for (i = 0; i < ps->num_ports; i++)
REG_WRITE(REG_GLOBAL2, GLOBAL2_INGRESS_OP,
0x9000 | (i << 8));
}
REG_WRITE(REG_GLOBAL, GLOBAL_STATS_OP, GLOBAL_STATS_OP_FLUSH_ALL);
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_stats_wait(ds);
if (ret < 0)
goto unlock;
ret = _mv88e6xxx_vtu_stu_flush(ds);
unlock:
mutex_unlock(&ps->smi_mutex);
return ret;
}
int mv88e6xxx_switch_reset(struct dsa_switch *ds, bool ppu_active)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
u16 is_reset = (ppu_active ? 0x8800 : 0xc800);
unsigned long timeout;
int ret;
int i;
for (i = 0; i < ps->num_ports; i++) {
ret = REG_READ(REG_PORT(i), PORT_CONTROL);
REG_WRITE(REG_PORT(i), PORT_CONTROL, ret & 0xfffc);
}
usleep_range(2000, 4000);
if (ppu_active)
REG_WRITE(REG_GLOBAL, 0x04, 0xc000);
else
REG_WRITE(REG_GLOBAL, 0x04, 0xc400);
timeout = jiffies + 1 * HZ;
while (time_before(jiffies, timeout)) {
ret = REG_READ(REG_GLOBAL, 0x00);
if ((ret & is_reset) == is_reset)
break;
usleep_range(1000, 2000);
}
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
return 0;
}
int mv88e6xxx_phy_page_read(struct dsa_switch *ds, int port, int page, int reg)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_phy_write_indirect(ds, port, 0x16, page);
if (ret < 0)
goto error;
ret = _mv88e6xxx_phy_read_indirect(ds, port, reg);
error:
_mv88e6xxx_phy_write_indirect(ds, port, 0x16, 0x0);
mutex_unlock(&ps->smi_mutex);
return ret;
}
int mv88e6xxx_phy_page_write(struct dsa_switch *ds, int port, int page,
int reg, int val)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_phy_write_indirect(ds, port, 0x16, page);
if (ret < 0)
goto error;
ret = _mv88e6xxx_phy_write_indirect(ds, port, reg, val);
error:
_mv88e6xxx_phy_write_indirect(ds, port, 0x16, 0x0);
mutex_unlock(&ps->smi_mutex);
return ret;
}
static int mv88e6xxx_port_to_phy_addr(struct dsa_switch *ds, int port)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
if (port >= 0 && port < ps->num_ports)
return port;
return -EINVAL;
}
int
mv88e6xxx_phy_read(struct dsa_switch *ds, int port, int regnum)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int addr = mv88e6xxx_port_to_phy_addr(ds, port);
int ret;
if (addr < 0)
return addr;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_phy_read(ds, addr, regnum);
mutex_unlock(&ps->smi_mutex);
return ret;
}
int
mv88e6xxx_phy_write(struct dsa_switch *ds, int port, int regnum, u16 val)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int addr = mv88e6xxx_port_to_phy_addr(ds, port);
int ret;
if (addr < 0)
return addr;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_phy_write(ds, addr, regnum, val);
mutex_unlock(&ps->smi_mutex);
return ret;
}
int
mv88e6xxx_phy_read_indirect(struct dsa_switch *ds, int port, int regnum)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int addr = mv88e6xxx_port_to_phy_addr(ds, port);
int ret;
if (addr < 0)
return addr;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_phy_read_indirect(ds, addr, regnum);
mutex_unlock(&ps->smi_mutex);
return ret;
}
int
mv88e6xxx_phy_write_indirect(struct dsa_switch *ds, int port, int regnum,
u16 val)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int addr = mv88e6xxx_port_to_phy_addr(ds, port);
int ret;
if (addr < 0)
return addr;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_phy_write_indirect(ds, addr, regnum, val);
mutex_unlock(&ps->smi_mutex);
return ret;
}
static int mv88e61xx_get_temp(struct dsa_switch *ds, int *temp)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
int val;
*temp = 0;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_phy_write(ds, 0x0, 0x16, 0x6);
if (ret < 0)
goto error;
ret = _mv88e6xxx_phy_read(ds, 0x0, 0x1a);
if (ret < 0)
goto error;
ret = _mv88e6xxx_phy_write(ds, 0x0, 0x1a, ret | (1 << 5));
if (ret < 0)
goto error;
usleep_range(10000, 12000);
val = _mv88e6xxx_phy_read(ds, 0x0, 0x1a);
if (val < 0) {
ret = val;
goto error;
}
ret = _mv88e6xxx_phy_write(ds, 0x0, 0x1a, ret & ~(1 << 5));
if (ret < 0)
goto error;
*temp = ((val & 0x1f) - 5) * 5;
error:
_mv88e6xxx_phy_write(ds, 0x0, 0x16, 0x0);
mutex_unlock(&ps->smi_mutex);
return ret;
}
static int mv88e63xx_get_temp(struct dsa_switch *ds, int *temp)
{
int phy = mv88e6xxx_6320_family(ds) ? 3 : 0;
int ret;
*temp = 0;
ret = mv88e6xxx_phy_page_read(ds, phy, 6, 27);
if (ret < 0)
return ret;
*temp = (ret & 0xff) - 25;
return 0;
}
int mv88e6xxx_get_temp(struct dsa_switch *ds, int *temp)
{
if (mv88e6xxx_6320_family(ds) || mv88e6xxx_6352_family(ds))
return mv88e63xx_get_temp(ds, temp);
return mv88e61xx_get_temp(ds, temp);
}
int mv88e6xxx_get_temp_limit(struct dsa_switch *ds, int *temp)
{
int phy = mv88e6xxx_6320_family(ds) ? 3 : 0;
int ret;
if (!mv88e6xxx_6320_family(ds) && !mv88e6xxx_6352_family(ds))
return -EOPNOTSUPP;
*temp = 0;
ret = mv88e6xxx_phy_page_read(ds, phy, 6, 26);
if (ret < 0)
return ret;
*temp = (((ret >> 8) & 0x1f) * 5) - 25;
return 0;
}
int mv88e6xxx_set_temp_limit(struct dsa_switch *ds, int temp)
{
int phy = mv88e6xxx_6320_family(ds) ? 3 : 0;
int ret;
if (!mv88e6xxx_6320_family(ds) && !mv88e6xxx_6352_family(ds))
return -EOPNOTSUPP;
ret = mv88e6xxx_phy_page_read(ds, phy, 6, 26);
if (ret < 0)
return ret;
temp = clamp_val(DIV_ROUND_CLOSEST(temp, 5) + 5, 0, 0x1f);
return mv88e6xxx_phy_page_write(ds, phy, 6, 26,
(ret & 0xe0ff) | (temp << 8));
}
int mv88e6xxx_get_temp_alarm(struct dsa_switch *ds, bool *alarm)
{
int phy = mv88e6xxx_6320_family(ds) ? 3 : 0;
int ret;
if (!mv88e6xxx_6320_family(ds) && !mv88e6xxx_6352_family(ds))
return -EOPNOTSUPP;
*alarm = false;
ret = mv88e6xxx_phy_page_read(ds, phy, 6, 26);
if (ret < 0)
return ret;
*alarm = !!(ret & 0x40);
return 0;
}
static int __init mv88e6xxx_init(void)
{
#if IS_ENABLED(CONFIG_NET_DSA_MV88E6131)
register_switch_driver(&mv88e6131_switch_driver);
#endif
#if IS_ENABLED(CONFIG_NET_DSA_MV88E6123_61_65)
register_switch_driver(&mv88e6123_61_65_switch_driver);
#endif
#if IS_ENABLED(CONFIG_NET_DSA_MV88E6352)
register_switch_driver(&mv88e6352_switch_driver);
#endif
#if IS_ENABLED(CONFIG_NET_DSA_MV88E6171)
register_switch_driver(&mv88e6171_switch_driver);
#endif
return 0;
}
static void __exit mv88e6xxx_cleanup(void)
{
#if IS_ENABLED(CONFIG_NET_DSA_MV88E6171)
unregister_switch_driver(&mv88e6171_switch_driver);
#endif
#if IS_ENABLED(CONFIG_NET_DSA_MV88E6352)
unregister_switch_driver(&mv88e6352_switch_driver);
#endif
#if IS_ENABLED(CONFIG_NET_DSA_MV88E6123_61_65)
unregister_switch_driver(&mv88e6123_61_65_switch_driver);
#endif
#if IS_ENABLED(CONFIG_NET_DSA_MV88E6131)
unregister_switch_driver(&mv88e6131_switch_driver);
#endif
}
