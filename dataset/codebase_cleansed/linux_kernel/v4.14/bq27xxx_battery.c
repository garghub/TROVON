static inline u16 *bq27xxx_dm_reg_ptr(struct bq27xxx_dm_buf *buf,
struct bq27xxx_dm_reg *reg)
{
if (buf->class == reg->subclass_id &&
buf->block == reg->offset / BQ27XXX_DM_SZ)
return (u16 *) (buf->data + reg->offset % BQ27XXX_DM_SZ);
return NULL;
}
static int poll_interval_param_set(const char *val, const struct kernel_param *kp)
{
struct bq27xxx_device_info *di;
unsigned int prev_val = *(unsigned int *) kp->arg;
int ret;
ret = param_set_uint(val, kp);
if (ret < 0 || prev_val == *(unsigned int *) kp->arg)
return ret;
mutex_lock(&bq27xxx_list_lock);
list_for_each_entry(di, &bq27xxx_battery_devices, list) {
cancel_delayed_work_sync(&di->work);
schedule_delayed_work(&di->work, 0);
}
mutex_unlock(&bq27xxx_list_lock);
return ret;
}
static inline int bq27xxx_read(struct bq27xxx_device_info *di, int reg_index,
bool single)
{
int ret;
if (!di || di->regs[reg_index] == INVALID_REG_ADDR)
return -EINVAL;
ret = di->bus.read(di, di->regs[reg_index], single);
if (ret < 0)
dev_dbg(di->dev, "failed to read register 0x%02x (index %d)\n",
di->regs[reg_index], reg_index);
return ret;
}
static inline int bq27xxx_write(struct bq27xxx_device_info *di, int reg_index,
u16 value, bool single)
{
int ret;
if (!di || di->regs[reg_index] == INVALID_REG_ADDR)
return -EINVAL;
if (!di->bus.write)
return -EPERM;
ret = di->bus.write(di, di->regs[reg_index], value, single);
if (ret < 0)
dev_dbg(di->dev, "failed to write register 0x%02x (index %d)\n",
di->regs[reg_index], reg_index);
return ret;
}
static inline int bq27xxx_read_block(struct bq27xxx_device_info *di, int reg_index,
u8 *data, int len)
{
int ret;
if (!di || di->regs[reg_index] == INVALID_REG_ADDR)
return -EINVAL;
if (!di->bus.read_bulk)
return -EPERM;
ret = di->bus.read_bulk(di, di->regs[reg_index], data, len);
if (ret < 0)
dev_dbg(di->dev, "failed to read_bulk register 0x%02x (index %d)\n",
di->regs[reg_index], reg_index);
return ret;
}
static inline int bq27xxx_write_block(struct bq27xxx_device_info *di, int reg_index,
u8 *data, int len)
{
int ret;
if (!di || di->regs[reg_index] == INVALID_REG_ADDR)
return -EINVAL;
if (!di->bus.write_bulk)
return -EPERM;
ret = di->bus.write_bulk(di, di->regs[reg_index], data, len);
if (ret < 0)
dev_dbg(di->dev, "failed to write_bulk register 0x%02x (index %d)\n",
di->regs[reg_index], reg_index);
return ret;
}
static int bq27xxx_battery_seal(struct bq27xxx_device_info *di)
{
int ret;
ret = bq27xxx_write(di, BQ27XXX_REG_CTRL, BQ27XXX_SEALED, false);
if (ret < 0) {
dev_err(di->dev, "bus error on seal: %d\n", ret);
return ret;
}
return 0;
}
static int bq27xxx_battery_unseal(struct bq27xxx_device_info *di)
{
int ret;
if (di->unseal_key == 0) {
dev_err(di->dev, "unseal failed due to missing key\n");
return -EINVAL;
}
ret = bq27xxx_write(di, BQ27XXX_REG_CTRL, (u16)(di->unseal_key >> 16), false);
if (ret < 0)
goto out;
ret = bq27xxx_write(di, BQ27XXX_REG_CTRL, (u16)di->unseal_key, false);
if (ret < 0)
goto out;
return 0;
out:
dev_err(di->dev, "bus error on unseal: %d\n", ret);
return ret;
}
static u8 bq27xxx_battery_checksum_dm_block(struct bq27xxx_dm_buf *buf)
{
u16 sum = 0;
int i;
for (i = 0; i < BQ27XXX_DM_SZ; i++)
sum += buf->data[i];
sum &= 0xff;
return 0xff - sum;
}
static int bq27xxx_battery_read_dm_block(struct bq27xxx_device_info *di,
struct bq27xxx_dm_buf *buf)
{
int ret;
buf->has_data = false;
ret = bq27xxx_write(di, BQ27XXX_DM_CLASS, buf->class, true);
if (ret < 0)
goto out;
ret = bq27xxx_write(di, BQ27XXX_DM_BLOCK, buf->block, true);
if (ret < 0)
goto out;
BQ27XXX_MSLEEP(1);
ret = bq27xxx_read_block(di, BQ27XXX_DM_DATA, buf->data, BQ27XXX_DM_SZ);
if (ret < 0)
goto out;
ret = bq27xxx_read(di, BQ27XXX_DM_CKSUM, true);
if (ret < 0)
goto out;
if ((u8)ret != bq27xxx_battery_checksum_dm_block(buf)) {
ret = -EINVAL;
goto out;
}
buf->has_data = true;
buf->dirty = false;
return 0;
out:
dev_err(di->dev, "bus error reading chip memory: %d\n", ret);
return ret;
}
static int bq27xxx_battery_cfgupdate_priv(struct bq27xxx_device_info *di, bool active)
{
const int limit = 100;
u16 cmd = active ? BQ27XXX_SET_CFGUPDATE : BQ27XXX_SOFT_RESET;
int ret, try = limit;
ret = bq27xxx_write(di, BQ27XXX_REG_CTRL, cmd, false);
if (ret < 0)
return ret;
do {
BQ27XXX_MSLEEP(25);
ret = bq27xxx_read(di, BQ27XXX_REG_FLAGS, false);
if (ret < 0)
return ret;
} while (!!(ret & BQ27XXX_FLAG_CFGUP) != active && --try);
if (!try && di->chip != BQ27425) {
dev_err(di->dev, "timed out waiting for cfgupdate flag %d\n", active);
return -EINVAL;
}
if (limit - try > 3)
dev_warn(di->dev, "cfgupdate %d, retries %d\n", active, limit - try);
return 0;
}
static inline int bq27xxx_battery_set_cfgupdate(struct bq27xxx_device_info *di)
{
int ret = bq27xxx_battery_cfgupdate_priv(di, true);
if (ret < 0 && ret != -EINVAL)
dev_err(di->dev, "bus error on set_cfgupdate: %d\n", ret);
return ret;
}
static inline int bq27xxx_battery_soft_reset(struct bq27xxx_device_info *di)
{
int ret = bq27xxx_battery_cfgupdate_priv(di, false);
if (ret < 0 && ret != -EINVAL)
dev_err(di->dev, "bus error on soft_reset: %d\n", ret);
return ret;
}
static int bq27xxx_battery_write_dm_block(struct bq27xxx_device_info *di,
struct bq27xxx_dm_buf *buf)
{
bool cfgup = di->opts & BQ27XXX_O_CFGUP;
int ret;
if (!buf->dirty)
return 0;
if (cfgup) {
ret = bq27xxx_battery_set_cfgupdate(di);
if (ret < 0)
return ret;
}
ret = bq27xxx_write(di, BQ27XXX_DM_CTRL, 0, true);
if (ret < 0)
goto out;
ret = bq27xxx_write(di, BQ27XXX_DM_CLASS, buf->class, true);
if (ret < 0)
goto out;
ret = bq27xxx_write(di, BQ27XXX_DM_BLOCK, buf->block, true);
if (ret < 0)
goto out;
BQ27XXX_MSLEEP(1);
ret = bq27xxx_write_block(di, BQ27XXX_DM_DATA, buf->data, BQ27XXX_DM_SZ);
if (ret < 0)
goto out;
ret = bq27xxx_write(di, BQ27XXX_DM_CKSUM,
bq27xxx_battery_checksum_dm_block(buf), true);
if (ret < 0)
goto out;
if (cfgup) {
BQ27XXX_MSLEEP(1);
ret = bq27xxx_battery_soft_reset(di);
if (ret < 0)
return ret;
} else {
BQ27XXX_MSLEEP(100);
}
buf->dirty = false;
return 0;
out:
if (cfgup)
bq27xxx_battery_soft_reset(di);
dev_err(di->dev, "bus error writing chip memory: %d\n", ret);
return ret;
}
static void bq27xxx_battery_set_config(struct bq27xxx_device_info *di,
struct power_supply_battery_info *info)
{
struct bq27xxx_dm_buf bd = BQ27XXX_DM_BUF(di, BQ27XXX_DM_DESIGN_CAPACITY);
struct bq27xxx_dm_buf bt = BQ27XXX_DM_BUF(di, BQ27XXX_DM_TERMINATE_VOLTAGE);
bool updated;
if (bq27xxx_battery_unseal(di) < 0)
return;
if (info->charge_full_design_uah != -EINVAL &&
info->energy_full_design_uwh != -EINVAL) {
bq27xxx_battery_read_dm_block(di, &bd);
bq27xxx_battery_update_dm_block(di, &bd,
BQ27XXX_DM_DESIGN_CAPACITY,
info->charge_full_design_uah / 1000);
bq27xxx_battery_update_dm_block(di, &bd,
BQ27XXX_DM_DESIGN_ENERGY,
info->energy_full_design_uwh / 1000);
}
if (info->voltage_min_design_uv != -EINVAL) {
bool same = bd.class == bt.class && bd.block == bt.block;
if (!same)
bq27xxx_battery_read_dm_block(di, &bt);
bq27xxx_battery_update_dm_block(di, same ? &bd : &bt,
BQ27XXX_DM_TERMINATE_VOLTAGE,
info->voltage_min_design_uv / 1000);
}
updated = bd.dirty || bt.dirty;
bq27xxx_battery_write_dm_block(di, &bd);
bq27xxx_battery_write_dm_block(di, &bt);
bq27xxx_battery_seal(di);
if (updated && !(di->opts & BQ27XXX_O_CFGUP)) {
bq27xxx_write(di, BQ27XXX_REG_CTRL, BQ27XXX_RESET, false);
BQ27XXX_MSLEEP(300);
}
}
static void bq27xxx_battery_settings(struct bq27xxx_device_info *di)
{
struct power_supply_battery_info info = {};
unsigned int min, max;
if (power_supply_get_battery_info(di->bat, &info) < 0)
return;
if (!di->dm_regs) {
dev_warn(di->dev, "data memory update not supported for chip\n");
return;
}
if (info.energy_full_design_uwh != info.charge_full_design_uah) {
if (info.energy_full_design_uwh == -EINVAL)
dev_warn(di->dev, "missing battery:energy-full-design-microwatt-hours\n");
else if (info.charge_full_design_uah == -EINVAL)
dev_warn(di->dev, "missing battery:charge-full-design-microamp-hours\n");
}
max = di->dm_regs[BQ27XXX_DM_DESIGN_ENERGY].max;
if (info.energy_full_design_uwh > max * 1000) {
dev_err(di->dev, "invalid battery:energy-full-design-microwatt-hours %d\n",
info.energy_full_design_uwh);
info.energy_full_design_uwh = -EINVAL;
}
max = di->dm_regs[BQ27XXX_DM_DESIGN_CAPACITY].max;
if (info.charge_full_design_uah > max * 1000) {
dev_err(di->dev, "invalid battery:charge-full-design-microamp-hours %d\n",
info.charge_full_design_uah);
info.charge_full_design_uah = -EINVAL;
}
min = di->dm_regs[BQ27XXX_DM_TERMINATE_VOLTAGE].min;
max = di->dm_regs[BQ27XXX_DM_TERMINATE_VOLTAGE].max;
if ((info.voltage_min_design_uv < min * 1000 ||
info.voltage_min_design_uv > max * 1000) &&
info.voltage_min_design_uv != -EINVAL) {
dev_err(di->dev, "invalid battery:voltage-min-design-microvolt %d\n",
info.voltage_min_design_uv);
info.voltage_min_design_uv = -EINVAL;
}
if ((info.energy_full_design_uwh != -EINVAL &&
info.charge_full_design_uah != -EINVAL) ||
info.voltage_min_design_uv != -EINVAL)
bq27xxx_battery_set_config(di, &info);
}
static int bq27xxx_battery_read_soc(struct bq27xxx_device_info *di)
{
int soc;
if (di->opts & BQ27XXX_O_ZERO)
soc = bq27xxx_read(di, BQ27XXX_REG_SOC, true);
else
soc = bq27xxx_read(di, BQ27XXX_REG_SOC, false);
if (soc < 0)
dev_dbg(di->dev, "error reading State-of-Charge\n");
return soc;
}
static int bq27xxx_battery_read_charge(struct bq27xxx_device_info *di, u8 reg)
{
int charge;
charge = bq27xxx_read(di, reg, false);
if (charge < 0) {
dev_dbg(di->dev, "error reading charge register %02x: %d\n",
reg, charge);
return charge;
}
if (di->opts & BQ27XXX_O_ZERO)
charge *= BQ27XXX_CURRENT_CONSTANT / BQ27XXX_RS;
else
charge *= 1000;
return charge;
}
static inline int bq27xxx_battery_read_nac(struct bq27xxx_device_info *di)
{
int flags;
if (di->opts & BQ27XXX_O_ZERO) {
flags = bq27xxx_read(di, BQ27XXX_REG_FLAGS, true);
if (flags >= 0 && (flags & BQ27000_FLAG_CI))
return -ENODATA;
}
return bq27xxx_battery_read_charge(di, BQ27XXX_REG_NAC);
}
static inline int bq27xxx_battery_read_fcc(struct bq27xxx_device_info *di)
{
return bq27xxx_battery_read_charge(di, BQ27XXX_REG_FCC);
}
static int bq27xxx_battery_read_dcap(struct bq27xxx_device_info *di)
{
int dcap;
if (di->opts & BQ27XXX_O_ZERO)
dcap = bq27xxx_read(di, BQ27XXX_REG_DCAP, true);
else
dcap = bq27xxx_read(di, BQ27XXX_REG_DCAP, false);
if (dcap < 0) {
dev_dbg(di->dev, "error reading initial last measured discharge\n");
return dcap;
}
if (di->opts & BQ27XXX_O_ZERO)
dcap = (dcap << 8) * BQ27XXX_CURRENT_CONSTANT / BQ27XXX_RS;
else
dcap *= 1000;
return dcap;
}
static int bq27xxx_battery_read_energy(struct bq27xxx_device_info *di)
{
int ae;
ae = bq27xxx_read(di, BQ27XXX_REG_AE, false);
if (ae < 0) {
dev_dbg(di->dev, "error reading available energy\n");
return ae;
}
if (di->opts & BQ27XXX_O_ZERO)
ae *= BQ27XXX_POWER_CONSTANT / BQ27XXX_RS;
else
ae *= 1000;
return ae;
}
static int bq27xxx_battery_read_temperature(struct bq27xxx_device_info *di)
{
int temp;
temp = bq27xxx_read(di, BQ27XXX_REG_TEMP, false);
if (temp < 0) {
dev_err(di->dev, "error reading temperature\n");
return temp;
}
if (di->opts & BQ27XXX_O_ZERO)
temp = 5 * temp / 2;
return temp;
}
static int bq27xxx_battery_read_cyct(struct bq27xxx_device_info *di)
{
int cyct;
cyct = bq27xxx_read(di, BQ27XXX_REG_CYCT, false);
if (cyct < 0)
dev_err(di->dev, "error reading cycle count total\n");
return cyct;
}
static int bq27xxx_battery_read_time(struct bq27xxx_device_info *di, u8 reg)
{
int tval;
tval = bq27xxx_read(di, reg, false);
if (tval < 0) {
dev_dbg(di->dev, "error reading time register %02x: %d\n",
reg, tval);
return tval;
}
if (tval == 65535)
return -ENODATA;
return tval * 60;
}
static int bq27xxx_battery_read_pwr_avg(struct bq27xxx_device_info *di)
{
int tval;
tval = bq27xxx_read(di, BQ27XXX_REG_AP, false);
if (tval < 0) {
dev_err(di->dev, "error reading average power register %02x: %d\n",
BQ27XXX_REG_AP, tval);
return tval;
}
if (di->opts & BQ27XXX_O_ZERO)
return (tval * BQ27XXX_POWER_CONSTANT) / BQ27XXX_RS;
else
return tval;
}
static bool bq27xxx_battery_overtemp(struct bq27xxx_device_info *di, u16 flags)
{
if (di->opts & BQ27XXX_O_OTDC)
return flags & (BQ27XXX_FLAG_OTC | BQ27XXX_FLAG_OTD);
if (di->opts & BQ27XXX_O_UTOT)
return flags & BQ27XXX_FLAG_OT;
return false;
}
static bool bq27xxx_battery_undertemp(struct bq27xxx_device_info *di, u16 flags)
{
if (di->opts & BQ27XXX_O_UTOT)
return flags & BQ27XXX_FLAG_UT;
return false;
}
static bool bq27xxx_battery_dead(struct bq27xxx_device_info *di, u16 flags)
{
if (di->opts & BQ27XXX_O_ZERO)
return flags & (BQ27000_FLAG_EDV1 | BQ27000_FLAG_EDVF);
else
return flags & (BQ27XXX_FLAG_SOC1 | BQ27XXX_FLAG_SOCF);
}
static int bq27xxx_battery_read_health(struct bq27xxx_device_info *di)
{
int flags;
bool has_singe_flag = di->opts & BQ27XXX_O_ZERO;
flags = bq27xxx_read(di, BQ27XXX_REG_FLAGS, has_singe_flag);
if (flags < 0) {
dev_err(di->dev, "error reading flag register:%d\n", flags);
return flags;
}
if (unlikely(bq27xxx_battery_overtemp(di, flags)))
return POWER_SUPPLY_HEALTH_OVERHEAT;
if (unlikely(bq27xxx_battery_undertemp(di, flags)))
return POWER_SUPPLY_HEALTH_COLD;
if (unlikely(bq27xxx_battery_dead(di, flags)))
return POWER_SUPPLY_HEALTH_DEAD;
return POWER_SUPPLY_HEALTH_GOOD;
}
void bq27xxx_battery_update(struct bq27xxx_device_info *di)
{
struct bq27xxx_reg_cache cache = {0, };
bool has_ci_flag = di->opts & BQ27XXX_O_ZERO;
bool has_singe_flag = di->opts & BQ27XXX_O_ZERO;
cache.flags = bq27xxx_read(di, BQ27XXX_REG_FLAGS, has_singe_flag);
if ((cache.flags & 0xff) == 0xff)
cache.flags = -1;
if (cache.flags >= 0) {
cache.temperature = bq27xxx_battery_read_temperature(di);
if (has_ci_flag && (cache.flags & BQ27000_FLAG_CI)) {
dev_info_once(di->dev, "battery is not calibrated! ignoring capacity values\n");
cache.capacity = -ENODATA;
cache.energy = -ENODATA;
cache.time_to_empty = -ENODATA;
cache.time_to_empty_avg = -ENODATA;
cache.time_to_full = -ENODATA;
cache.charge_full = -ENODATA;
cache.health = -ENODATA;
} else {
if (di->regs[BQ27XXX_REG_TTE] != INVALID_REG_ADDR)
cache.time_to_empty = bq27xxx_battery_read_time(di, BQ27XXX_REG_TTE);
if (di->regs[BQ27XXX_REG_TTECP] != INVALID_REG_ADDR)
cache.time_to_empty_avg = bq27xxx_battery_read_time(di, BQ27XXX_REG_TTECP);
if (di->regs[BQ27XXX_REG_TTF] != INVALID_REG_ADDR)
cache.time_to_full = bq27xxx_battery_read_time(di, BQ27XXX_REG_TTF);
cache.charge_full = bq27xxx_battery_read_fcc(di);
cache.capacity = bq27xxx_battery_read_soc(di);
if (di->regs[BQ27XXX_REG_AE] != INVALID_REG_ADDR)
cache.energy = bq27xxx_battery_read_energy(di);
cache.health = bq27xxx_battery_read_health(di);
}
if (di->regs[BQ27XXX_REG_CYCT] != INVALID_REG_ADDR)
cache.cycle_count = bq27xxx_battery_read_cyct(di);
if (di->regs[BQ27XXX_REG_AP] != INVALID_REG_ADDR)
cache.power_avg = bq27xxx_battery_read_pwr_avg(di);
if (di->charge_design_full <= 0)
di->charge_design_full = bq27xxx_battery_read_dcap(di);
}
if (di->cache.capacity != cache.capacity)
power_supply_changed(di->bat);
if (memcmp(&di->cache, &cache, sizeof(cache)) != 0)
di->cache = cache;
di->last_update = jiffies;
}
static void bq27xxx_battery_poll(struct work_struct *work)
{
struct bq27xxx_device_info *di =
container_of(work, struct bq27xxx_device_info,
work.work);
bq27xxx_battery_update(di);
if (poll_interval > 0)
schedule_delayed_work(&di->work, poll_interval * HZ);
}
static int bq27xxx_battery_current(struct bq27xxx_device_info *di,
union power_supply_propval *val)
{
int curr;
int flags;
curr = bq27xxx_read(di, BQ27XXX_REG_AI, false);
if (curr < 0) {
dev_err(di->dev, "error reading current\n");
return curr;
}
if (di->opts & BQ27XXX_O_ZERO) {
flags = bq27xxx_read(di, BQ27XXX_REG_FLAGS, true);
if (flags & BQ27000_FLAG_CHGS) {
dev_dbg(di->dev, "negative current!\n");
curr = -curr;
}
val->intval = curr * BQ27XXX_CURRENT_CONSTANT / BQ27XXX_RS;
} else {
val->intval = (int)((s16)curr) * 1000;
}
return 0;
}
static int bq27xxx_battery_status(struct bq27xxx_device_info *di,
union power_supply_propval *val)
{
int status;
if (di->opts & BQ27XXX_O_ZERO) {
if (di->cache.flags & BQ27000_FLAG_FC)
status = POWER_SUPPLY_STATUS_FULL;
else if (di->cache.flags & BQ27000_FLAG_CHGS)
status = POWER_SUPPLY_STATUS_CHARGING;
else if (power_supply_am_i_supplied(di->bat))
status = POWER_SUPPLY_STATUS_NOT_CHARGING;
else
status = POWER_SUPPLY_STATUS_DISCHARGING;
} else {
if (di->cache.flags & BQ27XXX_FLAG_FC)
status = POWER_SUPPLY_STATUS_FULL;
else if (di->cache.flags & BQ27XXX_FLAG_DSC)
status = POWER_SUPPLY_STATUS_DISCHARGING;
else
status = POWER_SUPPLY_STATUS_CHARGING;
}
val->intval = status;
return 0;
}
static int bq27xxx_battery_capacity_level(struct bq27xxx_device_info *di,
union power_supply_propval *val)
{
int level;
if (di->opts & BQ27XXX_O_ZERO) {
if (di->cache.flags & BQ27000_FLAG_FC)
level = POWER_SUPPLY_CAPACITY_LEVEL_FULL;
else if (di->cache.flags & BQ27000_FLAG_EDV1)
level = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
else if (di->cache.flags & BQ27000_FLAG_EDVF)
level = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
else
level = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
} else {
if (di->cache.flags & BQ27XXX_FLAG_FC)
level = POWER_SUPPLY_CAPACITY_LEVEL_FULL;
else if (di->cache.flags & BQ27XXX_FLAG_SOC1)
level = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
else if (di->cache.flags & BQ27XXX_FLAG_SOCF)
level = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
else
level = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
}
val->intval = level;
return 0;
}
static int bq27xxx_battery_voltage(struct bq27xxx_device_info *di,
union power_supply_propval *val)
{
int volt;
volt = bq27xxx_read(di, BQ27XXX_REG_VOLT, false);
if (volt < 0) {
dev_err(di->dev, "error reading voltage\n");
return volt;
}
val->intval = volt * 1000;
return 0;
}
static int bq27xxx_simple_value(int value,
union power_supply_propval *val)
{
if (value < 0)
return value;
val->intval = value;
return 0;
}
static int bq27xxx_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret = 0;
struct bq27xxx_device_info *di = power_supply_get_drvdata(psy);
mutex_lock(&di->lock);
if (time_is_before_jiffies(di->last_update + 5 * HZ)) {
cancel_delayed_work_sync(&di->work);
bq27xxx_battery_poll(&di->work.work);
}
mutex_unlock(&di->lock);
if (psp != POWER_SUPPLY_PROP_PRESENT && di->cache.flags < 0)
return -ENODEV;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
ret = bq27xxx_battery_status(di, val);
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = bq27xxx_battery_voltage(di, val);
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = di->cache.flags < 0 ? 0 : 1;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
ret = bq27xxx_battery_current(di, val);
break;
case POWER_SUPPLY_PROP_CAPACITY:
ret = bq27xxx_simple_value(di->cache.capacity, val);
break;
case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
ret = bq27xxx_battery_capacity_level(di, val);
break;
case POWER_SUPPLY_PROP_TEMP:
ret = bq27xxx_simple_value(di->cache.temperature, val);
if (ret == 0)
val->intval -= 2731;
break;
case POWER_SUPPLY_PROP_TIME_TO_EMPTY_NOW:
ret = bq27xxx_simple_value(di->cache.time_to_empty, val);
break;
case POWER_SUPPLY_PROP_TIME_TO_EMPTY_AVG:
ret = bq27xxx_simple_value(di->cache.time_to_empty_avg, val);
break;
case POWER_SUPPLY_PROP_TIME_TO_FULL_NOW:
ret = bq27xxx_simple_value(di->cache.time_to_full, val);
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
ret = bq27xxx_simple_value(bq27xxx_battery_read_nac(di), val);
break;
case POWER_SUPPLY_PROP_CHARGE_FULL:
ret = bq27xxx_simple_value(di->cache.charge_full, val);
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
ret = bq27xxx_simple_value(di->charge_design_full, val);
break;
case POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN:
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
return -EINVAL;
case POWER_SUPPLY_PROP_CYCLE_COUNT:
ret = bq27xxx_simple_value(di->cache.cycle_count, val);
break;
case POWER_SUPPLY_PROP_ENERGY_NOW:
ret = bq27xxx_simple_value(di->cache.energy, val);
break;
case POWER_SUPPLY_PROP_POWER_AVG:
ret = bq27xxx_simple_value(di->cache.power_avg, val);
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = bq27xxx_simple_value(di->cache.health, val);
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = BQ27XXX_MANUFACTURER;
break;
default:
return -EINVAL;
}
return ret;
}
static void bq27xxx_external_power_changed(struct power_supply *psy)
{
struct bq27xxx_device_info *di = power_supply_get_drvdata(psy);
cancel_delayed_work_sync(&di->work);
schedule_delayed_work(&di->work, 0);
}
int bq27xxx_battery_setup(struct bq27xxx_device_info *di)
{
struct power_supply_desc *psy_desc;
struct power_supply_config psy_cfg = {
.of_node = di->dev->of_node,
.drv_data = di,
};
INIT_DELAYED_WORK(&di->work, bq27xxx_battery_poll);
mutex_init(&di->lock);
di->regs = bq27xxx_chip_data[di->chip].regs;
di->unseal_key = bq27xxx_chip_data[di->chip].unseal_key;
di->dm_regs = bq27xxx_chip_data[di->chip].dm_regs;
di->opts = bq27xxx_chip_data[di->chip].opts;
psy_desc = devm_kzalloc(di->dev, sizeof(*psy_desc), GFP_KERNEL);
if (!psy_desc)
return -ENOMEM;
psy_desc->name = di->name;
psy_desc->type = POWER_SUPPLY_TYPE_BATTERY;
psy_desc->properties = bq27xxx_chip_data[di->chip].props;
psy_desc->num_properties = bq27xxx_chip_data[di->chip].props_size;
psy_desc->get_property = bq27xxx_battery_get_property;
psy_desc->external_power_changed = bq27xxx_external_power_changed;
di->bat = power_supply_register_no_ws(di->dev, psy_desc, &psy_cfg);
if (IS_ERR(di->bat)) {
dev_err(di->dev, "failed to register battery\n");
return PTR_ERR(di->bat);
}
bq27xxx_battery_settings(di);
bq27xxx_battery_update(di);
mutex_lock(&bq27xxx_list_lock);
list_add(&di->list, &bq27xxx_battery_devices);
mutex_unlock(&bq27xxx_list_lock);
return 0;
}
void bq27xxx_battery_teardown(struct bq27xxx_device_info *di)
{
poll_interval = 0;
cancel_delayed_work_sync(&di->work);
power_supply_unregister(di->bat);
mutex_lock(&bq27xxx_list_lock);
list_del(&di->list);
mutex_unlock(&bq27xxx_list_lock);
mutex_destroy(&di->lock);
}
