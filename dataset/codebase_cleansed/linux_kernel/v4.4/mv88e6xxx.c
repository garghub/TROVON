static void assert_smi_lock(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
if (unlikely(!mutex_is_locked(&ps->smi_mutex))) {
dev_err(ds->master_dev, "SMI lock not held!\n");
dump_stack();
}
}
static int mv88e6xxx_reg_wait_ready(struct mii_bus *bus, int sw_addr)
{
int ret;
int i;
for (i = 0; i < 16; i++) {
ret = mdiobus_read_nested(bus, sw_addr, SMI_CMD);
if (ret < 0)
return ret;
if ((ret & SMI_CMD_BUSY) == 0)
return 0;
}
return -ETIMEDOUT;
}
static int __mv88e6xxx_reg_read(struct mii_bus *bus, int sw_addr, int addr,
int reg)
{
int ret;
if (sw_addr == 0)
return mdiobus_read_nested(bus, addr, reg);
ret = mv88e6xxx_reg_wait_ready(bus, sw_addr);
if (ret < 0)
return ret;
ret = mdiobus_write_nested(bus, sw_addr, SMI_CMD,
SMI_CMD_OP_22_READ | (addr << 5) | reg);
if (ret < 0)
return ret;
ret = mv88e6xxx_reg_wait_ready(bus, sw_addr);
if (ret < 0)
return ret;
ret = mdiobus_read_nested(bus, sw_addr, SMI_DATA);
if (ret < 0)
return ret;
return ret & 0xffff;
}
static int _mv88e6xxx_reg_read(struct dsa_switch *ds, int addr, int reg)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(ds->master_dev);
int ret;
assert_smi_lock(ds);
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
static int __mv88e6xxx_reg_write(struct mii_bus *bus, int sw_addr, int addr,
int reg, u16 val)
{
int ret;
if (sw_addr == 0)
return mdiobus_write_nested(bus, addr, reg, val);
ret = mv88e6xxx_reg_wait_ready(bus, sw_addr);
if (ret < 0)
return ret;
ret = mdiobus_write_nested(bus, sw_addr, SMI_DATA, val);
if (ret < 0)
return ret;
ret = mdiobus_write_nested(bus, sw_addr, SMI_CMD,
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
assert_smi_lock(ds);
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
u32 reg;
int ret;
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
static int _mv88e6xxx_atu_cmd(struct dsa_switch *ds, u16 cmd)
{
int ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_ATU_OP, cmd);
if (ret < 0)
return ret;
return _mv88e6xxx_atu_wait(ds);
}
static int _mv88e6xxx_atu_data_write(struct dsa_switch *ds,
struct mv88e6xxx_atu_entry *entry)
{
u16 data = entry->state & GLOBAL_ATU_DATA_STATE_MASK;
if (entry->state != GLOBAL_ATU_DATA_STATE_UNUSED) {
unsigned int mask, shift;
if (entry->trunk) {
data |= GLOBAL_ATU_DATA_TRUNK;
mask = GLOBAL_ATU_DATA_TRUNK_ID_MASK;
shift = GLOBAL_ATU_DATA_TRUNK_ID_SHIFT;
} else {
mask = GLOBAL_ATU_DATA_PORT_VECTOR_MASK;
shift = GLOBAL_ATU_DATA_PORT_VECTOR_SHIFT;
}
data |= (entry->portv_trunkid << shift) & mask;
}
return _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_ATU_DATA, data);
}
static int _mv88e6xxx_atu_flush_move(struct dsa_switch *ds,
struct mv88e6xxx_atu_entry *entry,
bool static_too)
{
int op;
int err;
err = _mv88e6xxx_atu_wait(ds);
if (err)
return err;
err = _mv88e6xxx_atu_data_write(ds, entry);
if (err)
return err;
if (entry->fid) {
err = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_ATU_FID,
entry->fid);
if (err)
return err;
op = static_too ? GLOBAL_ATU_OP_FLUSH_MOVE_ALL_DB :
GLOBAL_ATU_OP_FLUSH_MOVE_NON_STATIC_DB;
} else {
op = static_too ? GLOBAL_ATU_OP_FLUSH_MOVE_ALL :
GLOBAL_ATU_OP_FLUSH_MOVE_NON_STATIC;
}
return _mv88e6xxx_atu_cmd(ds, op);
}
static int _mv88e6xxx_atu_flush(struct dsa_switch *ds, u16 fid, bool static_too)
{
struct mv88e6xxx_atu_entry entry = {
.fid = fid,
.state = 0,
};
return _mv88e6xxx_atu_flush_move(ds, &entry, static_too);
}
static int _mv88e6xxx_atu_move(struct dsa_switch *ds, u16 fid, int from_port,
int to_port, bool static_too)
{
struct mv88e6xxx_atu_entry entry = {
.trunk = false,
.fid = fid,
};
entry.state = GLOBAL_ATU_DATA_STATE_MASK;
entry.portv_trunkid = (to_port & 0x0f) << 4;
entry.portv_trunkid |= from_port & 0x0f;
return _mv88e6xxx_atu_flush_move(ds, &entry, static_too);
}
static int _mv88e6xxx_atu_remove(struct dsa_switch *ds, u16 fid, int port,
bool static_too)
{
return _mv88e6xxx_atu_move(ds, fid, port, 0x0f, static_too);
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
ret = _mv88e6xxx_atu_remove(ds, 0, port, false);
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
static int _mv88e6xxx_port_vlan_map_set(struct dsa_switch *ds, int port,
u16 output_ports)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
const u16 mask = (1 << ps->num_ports) - 1;
int reg;
reg = _mv88e6xxx_reg_read(ds, REG_PORT(port), PORT_BASE_VLAN);
if (reg < 0)
return reg;
reg &= ~mask;
reg |= output_ports & mask;
return _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_BASE_VLAN, reg);
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
static int _mv88e6xxx_port_pvid_get(struct dsa_switch *ds, int port, u16 *pvid)
{
int ret;
ret = _mv88e6xxx_reg_read(ds, REG_PORT(port), PORT_DEFAULT_VLAN);
if (ret < 0)
return ret;
*pvid = ret & PORT_DEFAULT_VLAN_MASK;
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
static int _mv88e6xxx_port_pvid_set(struct dsa_switch *ds, int port, u16 pvid)
{
return _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_DEFAULT_VLAN,
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
static int _mv88e6xxx_vtu_vid_write(struct dsa_switch *ds, u16 vid)
{
return _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_VTU_VID,
vid & GLOBAL_VTU_VID_MASK);
}
static int _mv88e6xxx_vtu_getnext(struct dsa_switch *ds,
struct mv88e6xxx_vtu_stu_entry *entry)
{
struct mv88e6xxx_vtu_stu_entry next = { 0 };
int ret;
ret = _mv88e6xxx_vtu_wait(ds);
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
.fid = vid,
};
int i;
for (i = 0; i < ps->num_ports; ++i)
vlan.data[i] = dsa_is_cpu_port(ds, i) || dsa_is_dsa_port(ds, i)
? GLOBAL_VTU_DATA_MEMBER_TAG_UNMODIFIED
: GLOBAL_VTU_DATA_MEMBER_TAG_NON_MEMBER;
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
err = _mv88e6xxx_atu_flush(ds, vlan.fid, true);
if (err)
return err;
}
*entry = vlan;
return 0;
}
int mv88e6xxx_port_vlan_prepare(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan,
struct switchdev_trans *trans)
{
if (vlan->vid_end >= 4000)
return -EOPNOTSUPP;
return 0;
}
static int _mv88e6xxx_port_vlan_add(struct dsa_switch *ds, int port, u16 vid,
bool untagged)
{
struct mv88e6xxx_vtu_stu_entry vlan;
int err;
err = _mv88e6xxx_vtu_vid_write(ds, vid - 1);
if (err)
return err;
err = _mv88e6xxx_vtu_getnext(ds, &vlan);
if (err)
return err;
if (vlan.vid != vid || !vlan.valid) {
err = _mv88e6xxx_vlan_init(ds, vid, &vlan);
if (err)
return err;
}
vlan.data[port] = untagged ?
GLOBAL_VTU_DATA_MEMBER_TAG_UNTAGGED :
GLOBAL_VTU_DATA_MEMBER_TAG_TAGGED;
return _mv88e6xxx_vtu_loadpurge(ds, &vlan);
}
int mv88e6xxx_port_vlan_add(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan,
struct switchdev_trans *trans)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
bool untagged = vlan->flags & BRIDGE_VLAN_INFO_UNTAGGED;
bool pvid = vlan->flags & BRIDGE_VLAN_INFO_PVID;
u16 vid;
int err = 0;
mutex_lock(&ps->smi_mutex);
for (vid = vlan->vid_begin; vid <= vlan->vid_end; ++vid) {
err = _mv88e6xxx_port_vlan_add(ds, port, vid, untagged);
if (err)
goto unlock;
}
if (pvid)
err = _mv88e6xxx_port_pvid_set(ds, port, vid);
unlock:
mutex_unlock(&ps->smi_mutex);
return err;
}
static int _mv88e6xxx_port_vlan_del(struct dsa_switch *ds, int port, u16 vid)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_vtu_stu_entry vlan;
int i, err;
err = _mv88e6xxx_vtu_vid_write(ds, vid - 1);
if (err)
return err;
err = _mv88e6xxx_vtu_getnext(ds, &vlan);
if (err)
return err;
if (vlan.vid != vid || !vlan.valid ||
vlan.data[port] == GLOBAL_VTU_DATA_MEMBER_TAG_NON_MEMBER)
return -ENOENT;
vlan.data[port] = GLOBAL_VTU_DATA_MEMBER_TAG_NON_MEMBER;
vlan.valid = false;
for (i = 0; i < ps->num_ports; ++i) {
if (dsa_is_cpu_port(ds, i) || dsa_is_dsa_port(ds, i))
continue;
if (vlan.data[i] != GLOBAL_VTU_DATA_MEMBER_TAG_NON_MEMBER) {
vlan.valid = true;
break;
}
}
err = _mv88e6xxx_vtu_loadpurge(ds, &vlan);
if (err)
return err;
return _mv88e6xxx_atu_remove(ds, vlan.fid, port, false);
}
int mv88e6xxx_port_vlan_del(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
u16 pvid, vid;
int err = 0;
mutex_lock(&ps->smi_mutex);
err = _mv88e6xxx_port_pvid_get(ds, port, &pvid);
if (err)
goto unlock;
for (vid = vlan->vid_begin; vid <= vlan->vid_end; ++vid) {
err = _mv88e6xxx_port_vlan_del(ds, port, vid);
if (err)
goto unlock;
if (vid == pvid) {
err = _mv88e6xxx_port_pvid_set(ds, port, 0);
if (err)
goto unlock;
}
}
unlock:
mutex_unlock(&ps->smi_mutex);
return err;
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
err = _mv88e6xxx_vtu_vid_write(ds, *vid);
if (err)
goto unlock;
err = _mv88e6xxx_vtu_getnext(ds, &next);
unlock:
mutex_unlock(&ps->smi_mutex);
if (err)
return err;
if (!next.valid)
return -ENOENT;
*vid = next.vid;
for (port = 0; port < ps->num_ports; ++port) {
clear_bit(port, ports);
clear_bit(port, untagged);
if (dsa_is_cpu_port(ds, port) || dsa_is_dsa_port(ds, port))
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
int ret;
ret = _mv88e6xxx_atu_wait(ds);
if (ret < 0)
return ret;
ret = _mv88e6xxx_atu_mac_write(ds, entry->mac);
if (ret < 0)
return ret;
ret = _mv88e6xxx_atu_data_write(ds, entry);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_ATU_FID, entry->fid);
if (ret < 0)
return ret;
return _mv88e6xxx_atu_cmd(ds, GLOBAL_ATU_OP_LOAD_DB);
}
static int _mv88e6xxx_port_fdb_load(struct dsa_switch *ds, int port,
const unsigned char *addr, u16 vid,
u8 state)
{
struct mv88e6xxx_atu_entry entry = { 0 };
entry.fid = vid;
entry.state = state;
ether_addr_copy(entry.mac, addr);
if (state != GLOBAL_ATU_DATA_STATE_UNUSED) {
entry.trunk = false;
entry.portv_trunkid = BIT(port);
}
return _mv88e6xxx_atu_load(ds, &entry);
}
int mv88e6xxx_port_fdb_prepare(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb,
struct switchdev_trans *trans)
{
if (fdb->vid == 0)
return -EOPNOTSUPP;
return 0;
}
int mv88e6xxx_port_fdb_add(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb,
struct switchdev_trans *trans)
{
int state = is_multicast_ether_addr(fdb->addr) ?
GLOBAL_ATU_DATA_STATE_MC_STATIC :
GLOBAL_ATU_DATA_STATE_UC_STATIC;
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_port_fdb_load(ds, port, fdb->addr, fdb->vid, state);
mutex_unlock(&ps->smi_mutex);
return ret;
}
int mv88e6xxx_port_fdb_del(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_fdb *fdb)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->smi_mutex);
ret = _mv88e6xxx_port_fdb_load(ds, port, fdb->addr, fdb->vid,
GLOBAL_ATU_DATA_STATE_UNUSED);
mutex_unlock(&ps->smi_mutex);
return ret;
}
static int _mv88e6xxx_atu_getnext(struct dsa_switch *ds, u16 fid,
struct mv88e6xxx_atu_entry *entry)
{
struct mv88e6xxx_atu_entry next = { 0 };
int ret;
next.fid = fid;
ret = _mv88e6xxx_atu_wait(ds);
if (ret < 0)
return ret;
ret = _mv88e6xxx_reg_write(ds, REG_GLOBAL, GLOBAL_ATU_FID, fid);
if (ret < 0)
return ret;
ret = _mv88e6xxx_atu_cmd(ds, GLOBAL_ATU_OP_GET_NEXT_DB);
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
int mv88e6xxx_port_fdb_dump(struct dsa_switch *ds, int port,
struct switchdev_obj_port_fdb *fdb,
int (*cb)(struct switchdev_obj *obj))
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
struct mv88e6xxx_vtu_stu_entry vlan = {
.vid = GLOBAL_VTU_VID_MASK,
};
int err;
mutex_lock(&ps->smi_mutex);
err = _mv88e6xxx_vtu_vid_write(ds, vlan.vid);
if (err)
goto unlock;
do {
struct mv88e6xxx_atu_entry addr = {
.mac = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff },
};
err = _mv88e6xxx_vtu_getnext(ds, &vlan);
if (err)
goto unlock;
if (!vlan.valid)
break;
err = _mv88e6xxx_atu_mac_write(ds, addr.mac);
if (err)
goto unlock;
do {
err = _mv88e6xxx_atu_getnext(ds, vlan.fid, &addr);
if (err)
goto unlock;
if (addr.state == GLOBAL_ATU_DATA_STATE_UNUSED)
break;
if (!addr.trunk && addr.portv_trunkid & BIT(port)) {
bool is_static = addr.state ==
(is_multicast_ether_addr(addr.mac) ?
GLOBAL_ATU_DATA_STATE_MC_STATIC :
GLOBAL_ATU_DATA_STATE_UC_STATIC);
fdb->vid = vlan.vid;
ether_addr_copy(fdb->addr, addr.mac);
fdb->ndm_state = is_static ? NUD_NOARP :
NUD_REACHABLE;
err = cb(&fdb->obj);
if (err)
goto unlock;
}
} while (!is_broadcast_ether_addr(addr.mac));
} while (vlan.vid < GLOBAL_VTU_VID_MASK);
unlock:
mutex_unlock(&ps->smi_mutex);
return err;
}
int mv88e6xxx_port_bridge_join(struct dsa_switch *ds, int port, u32 members)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
const u16 pvid = 4000 + ds->index * DSA_MAX_PORTS + port;
int err;
mutex_lock(&ps->smi_mutex);
err = _mv88e6xxx_port_vlan_del(ds, port, pvid);
if (!err)
err = _mv88e6xxx_port_pvid_set(ds, port, 0);
mutex_unlock(&ps->smi_mutex);
return err;
}
int mv88e6xxx_port_bridge_leave(struct dsa_switch *ds, int port, u32 members)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
const u16 pvid = 4000 + ds->index * DSA_MAX_PORTS + port;
int err;
mutex_lock(&ps->smi_mutex);
err = _mv88e6xxx_port_vlan_add(ds, port, pvid, true);
if (!err)
err = _mv88e6xxx_port_pvid_set(ds, port, pvid);
mutex_unlock(&ps->smi_mutex);
return err;
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
int ret;
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
reg |= PORT_CONTROL_2_8021Q_SECURE;
if (reg) {
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port),
PORT_CONTROL_2, reg);
if (ret)
goto abort;
}
reg = 1 << port;
if (dsa_is_cpu_port(ds, port) || dsa_is_dsa_port(ds, port))
reg = PORT_ASSOC_VECTOR_LOCKED_PORT;
ret = _mv88e6xxx_reg_write(ds, REG_PORT(port), PORT_ASSOC_VECTOR, reg);
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
reg = BIT(ps->num_ports) - 1;
ret = _mv88e6xxx_port_vlan_map_set(ds, port, reg & ~port);
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
if (dsa_is_cpu_port(ds, i) || dsa_is_dsa_port(ds, i))
continue;
ret = mv88e6xxx_port_bridge_leave(ds, i, 0);
if (ret < 0)
return ret;
}
return 0;
}
int mv88e6xxx_setup_common(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
mutex_init(&ps->smi_mutex);
ps->id = REG_READ(REG_PORT(0), PORT_SWITCH_ID) & 0xfff0;
INIT_WORK(&ps->bridge_work, mv88e6xxx_bridge_work);
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
ret = _mv88e6xxx_atu_flush(ds, 0, true);
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
char *mv88e6xxx_lookup_name(struct device *host_dev, int sw_addr,
const struct mv88e6xxx_switch_id *table,
unsigned int num)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(host_dev);
int i, ret;
if (!bus)
return NULL;
ret = __mv88e6xxx_reg_read(bus, sw_addr, REG_PORT(0), PORT_SWITCH_ID);
if (ret < 0)
return NULL;
for (i = 0; i < num; ++i)
if (table[i].id == ret)
return table[i].name;
for (i = 0; i < num; ++i) {
if (table[i].id == (ret & PORT_SWITCH_ID_PROD_NUM_MASK)) {
dev_warn(host_dev, "unknown revision %d, using base switch 0x%x\n",
ret & PORT_SWITCH_ID_REV_MASK,
ret & PORT_SWITCH_ID_PROD_NUM_MASK);
return table[i].name;
}
}
return NULL;
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
