static int max17042_get_temperature(struct max17042_chip *chip, int *temp)
{
int ret;
u32 data;
struct regmap *map = chip->regmap;
ret = regmap_read(map, MAX17042_TEMP, &data);
if (ret < 0)
return ret;
*temp = sign_extend32(data, 15);
*temp = *temp * 10 / 256;
return 0;
}
static int max17042_get_status(struct max17042_chip *chip, int *status)
{
int ret, charge_full, charge_now;
ret = power_supply_am_i_supplied(chip->battery);
if (ret < 0) {
*status = POWER_SUPPLY_STATUS_UNKNOWN;
return 0;
}
if (ret == 0) {
*status = POWER_SUPPLY_STATUS_DISCHARGING;
return 0;
}
ret = regmap_read(chip->regmap, MAX17042_FullCAP, &charge_full);
if (ret < 0)
return ret;
ret = regmap_read(chip->regmap, MAX17042_RepCap, &charge_now);
if (ret < 0)
return ret;
if ((charge_full - charge_now) <= MAX17042_FULL_THRESHOLD)
*status = POWER_SUPPLY_STATUS_FULL;
else
*status = POWER_SUPPLY_STATUS_CHARGING;
return 0;
}
static int max17042_get_battery_health(struct max17042_chip *chip, int *health)
{
int temp, vavg, vbatt, ret;
u32 val;
ret = regmap_read(chip->regmap, MAX17042_AvgVCELL, &val);
if (ret < 0)
goto health_error;
vavg = val * 625 / 8;
vavg /= 1000;
ret = regmap_read(chip->regmap, MAX17042_VCELL, &val);
if (ret < 0)
goto health_error;
vbatt = val * 625 / 8;
vbatt /= 1000;
if (vavg < chip->pdata->vmin) {
*health = POWER_SUPPLY_HEALTH_DEAD;
goto out;
}
if (vbatt > chip->pdata->vmax + MAX17042_VMAX_TOLERANCE) {
*health = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
goto out;
}
ret = max17042_get_temperature(chip, &temp);
if (ret < 0)
goto health_error;
if (temp < chip->pdata->temp_min) {
*health = POWER_SUPPLY_HEALTH_COLD;
goto out;
}
if (temp > chip->pdata->temp_max) {
*health = POWER_SUPPLY_HEALTH_OVERHEAT;
goto out;
}
*health = POWER_SUPPLY_HEALTH_GOOD;
out:
return 0;
health_error:
return ret;
}
static int max17042_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max17042_chip *chip = power_supply_get_drvdata(psy);
struct regmap *map = chip->regmap;
int ret;
u32 data;
u64 data64;
if (!chip->init_complete)
return -EAGAIN;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
ret = max17042_get_status(chip, &val->intval);
if (ret < 0)
return ret;
break;
case POWER_SUPPLY_PROP_PRESENT:
ret = regmap_read(map, MAX17042_STATUS, &data);
if (ret < 0)
return ret;
if (data & MAX17042_STATUS_BattAbsent)
val->intval = 0;
else
val->intval = 1;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
case POWER_SUPPLY_PROP_CYCLE_COUNT:
ret = regmap_read(map, MAX17042_Cycles, &data);
if (ret < 0)
return ret;
val->intval = data;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX:
ret = regmap_read(map, MAX17042_MinMaxVolt, &data);
if (ret < 0)
return ret;
val->intval = data >> 8;
val->intval *= 20000;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN:
ret = regmap_read(map, MAX17042_MinMaxVolt, &data);
if (ret < 0)
return ret;
val->intval = (data & 0xff) * 20000;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
if (chip->chip_type == MAXIM_DEVICE_TYPE_MAX17042)
ret = regmap_read(map, MAX17042_V_empty, &data);
else
ret = regmap_read(map, MAX17047_V_empty, &data);
if (ret < 0)
return ret;
val->intval = data >> 7;
val->intval *= 10000;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = regmap_read(map, MAX17042_VCELL, &data);
if (ret < 0)
return ret;
val->intval = data * 625 / 8;
break;
case POWER_SUPPLY_PROP_VOLTAGE_AVG:
ret = regmap_read(map, MAX17042_AvgVCELL, &data);
if (ret < 0)
return ret;
val->intval = data * 625 / 8;
break;
case POWER_SUPPLY_PROP_VOLTAGE_OCV:
ret = regmap_read(map, MAX17042_OCVInternal, &data);
if (ret < 0)
return ret;
val->intval = data * 625 / 8;
break;
case POWER_SUPPLY_PROP_CAPACITY:
ret = regmap_read(map, MAX17042_RepSOC, &data);
if (ret < 0)
return ret;
val->intval = data >> 8;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
ret = regmap_read(map, MAX17042_DesignCap, &data);
if (ret < 0)
return ret;
data64 = data * 5000000ll;
do_div(data64, chip->pdata->r_sns);
val->intval = data64;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL:
ret = regmap_read(map, MAX17042_FullCAP, &data);
if (ret < 0)
return ret;
data64 = data * 5000000ll;
do_div(data64, chip->pdata->r_sns);
val->intval = data64;
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
ret = regmap_read(map, MAX17042_RepCap, &data);
if (ret < 0)
return ret;
data64 = data * 5000000ll;
do_div(data64, chip->pdata->r_sns);
val->intval = data64;
break;
case POWER_SUPPLY_PROP_CHARGE_COUNTER:
ret = regmap_read(map, MAX17042_QH, &data);
if (ret < 0)
return ret;
val->intval = data * 1000 / 2;
break;
case POWER_SUPPLY_PROP_TEMP:
ret = max17042_get_temperature(chip, &val->intval);
if (ret < 0)
return ret;
break;
case POWER_SUPPLY_PROP_TEMP_ALERT_MIN:
ret = regmap_read(map, MAX17042_TALRT_Th, &data);
if (ret < 0)
return ret;
val->intval = sign_extend32(data & 0xff, 7) * 10;
break;
case POWER_SUPPLY_PROP_TEMP_ALERT_MAX:
ret = regmap_read(map, MAX17042_TALRT_Th, &data);
if (ret < 0)
return ret;
val->intval = sign_extend32(data >> 8, 7) * 10;
break;
case POWER_SUPPLY_PROP_TEMP_MIN:
val->intval = chip->pdata->temp_min;
break;
case POWER_SUPPLY_PROP_TEMP_MAX:
val->intval = chip->pdata->temp_max;
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = max17042_get_battery_health(chip, &val->intval);
if (ret < 0)
return ret;
break;
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_SYSTEM;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
if (chip->pdata->enable_current_sense) {
ret = regmap_read(map, MAX17042_Current, &data);
if (ret < 0)
return ret;
val->intval = sign_extend32(data, 15);
val->intval *= 1562500 / chip->pdata->r_sns;
} else {
return -EINVAL;
}
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
if (chip->pdata->enable_current_sense) {
ret = regmap_read(map, MAX17042_AvgCurrent, &data);
if (ret < 0)
return ret;
val->intval = sign_extend32(data, 15);
val->intval *= 1562500 / chip->pdata->r_sns;
} else {
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int max17042_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct max17042_chip *chip = power_supply_get_drvdata(psy);
struct regmap *map = chip->regmap;
int ret = 0;
u32 data;
int8_t temp;
switch (psp) {
case POWER_SUPPLY_PROP_TEMP_ALERT_MIN:
ret = regmap_read(map, MAX17042_TALRT_Th, &data);
if (ret < 0)
return ret;
temp = val->intval / 10;
if (temp >= (int8_t)(data >> 8))
temp = (int8_t)(data >> 8) - 1;
data = (data & 0xff00) + temp;
ret = regmap_write(map, MAX17042_TALRT_Th, data);
break;
case POWER_SUPPLY_PROP_TEMP_ALERT_MAX:
ret = regmap_read(map, MAX17042_TALRT_Th, &data);
if (ret < 0)
return ret;
temp = val->intval / 10;
if (temp <= (int8_t)(data & 0xff))
temp = (int8_t)(data & 0xff) + 1;
data = (data & 0xff) + (temp << 8);
ret = regmap_write(map, MAX17042_TALRT_Th, data);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int max17042_property_is_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
int ret;
switch (psp) {
case POWER_SUPPLY_PROP_TEMP_ALERT_MIN:
case POWER_SUPPLY_PROP_TEMP_ALERT_MAX:
ret = 1;
break;
default:
ret = 0;
}
return ret;
}
static void max17042_external_power_changed(struct power_supply *psy)
{
power_supply_changed(psy);
}
static int max17042_write_verify_reg(struct regmap *map, u8 reg, u32 value)
{
int retries = 8;
int ret;
u32 read_value;
do {
ret = regmap_write(map, reg, value);
regmap_read(map, reg, &read_value);
if (read_value != value) {
ret = -EIO;
retries--;
}
} while (retries && read_value != value);
if (ret < 0)
pr_err("%s: err %d\n", __func__, ret);
return ret;
}
static inline void max17042_override_por(struct regmap *map,
u8 reg, u16 value)
{
if (value)
regmap_write(map, reg, value);
}
static inline void max10742_unlock_model(struct max17042_chip *chip)
{
struct regmap *map = chip->regmap;
regmap_write(map, MAX17042_MLOCKReg1, MODEL_UNLOCK1);
regmap_write(map, MAX17042_MLOCKReg2, MODEL_UNLOCK2);
}
static inline void max10742_lock_model(struct max17042_chip *chip)
{
struct regmap *map = chip->regmap;
regmap_write(map, MAX17042_MLOCKReg1, MODEL_LOCK1);
regmap_write(map, MAX17042_MLOCKReg2, MODEL_LOCK2);
}
static inline void max17042_write_model_data(struct max17042_chip *chip,
u8 addr, int size)
{
struct regmap *map = chip->regmap;
int i;
for (i = 0; i < size; i++)
regmap_write(map, addr + i,
chip->pdata->config_data->cell_char_tbl[i]);
}
static inline void max17042_read_model_data(struct max17042_chip *chip,
u8 addr, u16 *data, int size)
{
struct regmap *map = chip->regmap;
int i;
u32 tmp;
for (i = 0; i < size; i++) {
regmap_read(map, addr + i, &tmp);
data[i] = (u16)tmp;
}
}
static inline int max17042_model_data_compare(struct max17042_chip *chip,
u16 *data1, u16 *data2, int size)
{
int i;
if (memcmp(data1, data2, size)) {
dev_err(&chip->client->dev, "%s compare failed\n", __func__);
for (i = 0; i < size; i++)
dev_info(&chip->client->dev, "0x%x, 0x%x",
data1[i], data2[i]);
dev_info(&chip->client->dev, "\n");
return -EINVAL;
}
return 0;
}
static int max17042_init_model(struct max17042_chip *chip)
{
int ret;
int table_size = ARRAY_SIZE(chip->pdata->config_data->cell_char_tbl);
u16 *temp_data;
temp_data = kcalloc(table_size, sizeof(*temp_data), GFP_KERNEL);
if (!temp_data)
return -ENOMEM;
max10742_unlock_model(chip);
max17042_write_model_data(chip, MAX17042_MODELChrTbl,
table_size);
max17042_read_model_data(chip, MAX17042_MODELChrTbl, temp_data,
table_size);
ret = max17042_model_data_compare(
chip,
chip->pdata->config_data->cell_char_tbl,
temp_data,
table_size);
max10742_lock_model(chip);
kfree(temp_data);
return ret;
}
static int max17042_verify_model_lock(struct max17042_chip *chip)
{
int i;
int table_size = ARRAY_SIZE(chip->pdata->config_data->cell_char_tbl);
u16 *temp_data;
int ret = 0;
temp_data = kcalloc(table_size, sizeof(*temp_data), GFP_KERNEL);
if (!temp_data)
return -ENOMEM;
max17042_read_model_data(chip, MAX17042_MODELChrTbl, temp_data,
table_size);
for (i = 0; i < table_size; i++)
if (temp_data[i])
ret = -EINVAL;
kfree(temp_data);
return ret;
}
static void max17042_write_config_regs(struct max17042_chip *chip)
{
struct max17042_config_data *config = chip->pdata->config_data;
struct regmap *map = chip->regmap;
regmap_write(map, MAX17042_CONFIG, config->config);
regmap_write(map, MAX17042_LearnCFG, config->learn_cfg);
regmap_write(map, MAX17042_FilterCFG,
config->filter_cfg);
regmap_write(map, MAX17042_RelaxCFG, config->relax_cfg);
if (chip->chip_type == MAXIM_DEVICE_TYPE_MAX17047 ||
chip->chip_type == MAXIM_DEVICE_TYPE_MAX17050)
regmap_write(map, MAX17047_FullSOCThr,
config->full_soc_thresh);
}
static void max17042_write_custom_regs(struct max17042_chip *chip)
{
struct max17042_config_data *config = chip->pdata->config_data;
struct regmap *map = chip->regmap;
max17042_write_verify_reg(map, MAX17042_RCOMP0, config->rcomp0);
max17042_write_verify_reg(map, MAX17042_TempCo, config->tcompc0);
max17042_write_verify_reg(map, MAX17042_ICHGTerm, config->ichgt_term);
if (chip->chip_type == MAXIM_DEVICE_TYPE_MAX17042) {
regmap_write(map, MAX17042_EmptyTempCo, config->empty_tempco);
max17042_write_verify_reg(map, MAX17042_K_empty0,
config->kempty0);
} else {
max17042_write_verify_reg(map, MAX17047_QRTbl00,
config->qrtbl00);
max17042_write_verify_reg(map, MAX17047_QRTbl10,
config->qrtbl10);
max17042_write_verify_reg(map, MAX17047_QRTbl20,
config->qrtbl20);
max17042_write_verify_reg(map, MAX17047_QRTbl30,
config->qrtbl30);
}
}
static void max17042_update_capacity_regs(struct max17042_chip *chip)
{
struct max17042_config_data *config = chip->pdata->config_data;
struct regmap *map = chip->regmap;
max17042_write_verify_reg(map, MAX17042_FullCAP,
config->fullcap);
regmap_write(map, MAX17042_DesignCap, config->design_cap);
max17042_write_verify_reg(map, MAX17042_FullCAPNom,
config->fullcapnom);
}
static void max17042_reset_vfsoc0_reg(struct max17042_chip *chip)
{
unsigned int vfSoc;
struct regmap *map = chip->regmap;
regmap_read(map, MAX17042_VFSOC, &vfSoc);
regmap_write(map, MAX17042_VFSOC0Enable, VFSOC0_UNLOCK);
max17042_write_verify_reg(map, MAX17042_VFSOC0, vfSoc);
regmap_write(map, MAX17042_VFSOC0Enable, VFSOC0_LOCK);
}
static void max17042_load_new_capacity_params(struct max17042_chip *chip)
{
u32 full_cap0, rep_cap, dq_acc, vfSoc;
u32 rem_cap;
struct max17042_config_data *config = chip->pdata->config_data;
struct regmap *map = chip->regmap;
regmap_read(map, MAX17042_FullCAP0, &full_cap0);
regmap_read(map, MAX17042_VFSOC, &vfSoc);
rem_cap = ((vfSoc >> 8) * full_cap0) / 100;
max17042_write_verify_reg(map, MAX17042_RemCap, rem_cap);
rep_cap = rem_cap;
max17042_write_verify_reg(map, MAX17042_RepCap, rep_cap);
dq_acc = config->fullcap / dQ_ACC_DIV;
max17042_write_verify_reg(map, MAX17042_dQacc, dq_acc);
max17042_write_verify_reg(map, MAX17042_dPacc, dP_ACC_200);
max17042_write_verify_reg(map, MAX17042_FullCAP,
config->fullcap);
regmap_write(map, MAX17042_DesignCap,
config->design_cap);
max17042_write_verify_reg(map, MAX17042_FullCAPNom,
config->fullcapnom);
regmap_write(map, MAX17042_RepSOC, vfSoc);
}
static inline void max17042_override_por_values(struct max17042_chip *chip)
{
struct regmap *map = chip->regmap;
struct max17042_config_data *config = chip->pdata->config_data;
max17042_override_por(map, MAX17042_TGAIN, config->tgain);
max17042_override_por(map, MAx17042_TOFF, config->toff);
max17042_override_por(map, MAX17042_CGAIN, config->cgain);
max17042_override_por(map, MAX17042_COFF, config->coff);
max17042_override_por(map, MAX17042_VALRT_Th, config->valrt_thresh);
max17042_override_por(map, MAX17042_TALRT_Th, config->talrt_thresh);
max17042_override_por(map, MAX17042_SALRT_Th,
config->soc_alrt_thresh);
max17042_override_por(map, MAX17042_CONFIG, config->config);
max17042_override_por(map, MAX17042_SHDNTIMER, config->shdntimer);
max17042_override_por(map, MAX17042_DesignCap, config->design_cap);
max17042_override_por(map, MAX17042_ICHGTerm, config->ichgt_term);
max17042_override_por(map, MAX17042_AtRate, config->at_rate);
max17042_override_por(map, MAX17042_LearnCFG, config->learn_cfg);
max17042_override_por(map, MAX17042_FilterCFG, config->filter_cfg);
max17042_override_por(map, MAX17042_RelaxCFG, config->relax_cfg);
max17042_override_por(map, MAX17042_MiscCFG, config->misc_cfg);
max17042_override_por(map, MAX17042_MaskSOC, config->masksoc);
max17042_override_por(map, MAX17042_FullCAP, config->fullcap);
max17042_override_por(map, MAX17042_FullCAPNom, config->fullcapnom);
if (chip->chip_type == MAXIM_DEVICE_TYPE_MAX17042)
max17042_override_por(map, MAX17042_SOC_empty,
config->socempty);
max17042_override_por(map, MAX17042_LAvg_empty, config->lavg_empty);
max17042_override_por(map, MAX17042_dQacc, config->dqacc);
max17042_override_por(map, MAX17042_dPacc, config->dpacc);
if (chip->chip_type == MAXIM_DEVICE_TYPE_MAX17042)
max17042_override_por(map, MAX17042_V_empty, config->vempty);
else
max17042_override_por(map, MAX17047_V_empty, config->vempty);
max17042_override_por(map, MAX17042_TempNom, config->temp_nom);
max17042_override_por(map, MAX17042_TempLim, config->temp_lim);
max17042_override_por(map, MAX17042_FCTC, config->fctc);
max17042_override_por(map, MAX17042_RCOMP0, config->rcomp0);
max17042_override_por(map, MAX17042_TempCo, config->tcompc0);
if (chip->chip_type) {
max17042_override_por(map, MAX17042_EmptyTempCo,
config->empty_tempco);
max17042_override_por(map, MAX17042_K_empty0,
config->kempty0);
}
}
static int max17042_init_chip(struct max17042_chip *chip)
{
struct regmap *map = chip->regmap;
int ret;
max17042_override_por_values(chip);
msleep(500);
max17042_write_config_regs(chip);
ret = max17042_init_model(chip);
if (ret) {
dev_err(&chip->client->dev, "%s init failed\n",
__func__);
return -EIO;
}
ret = max17042_verify_model_lock(chip);
if (ret) {
dev_err(&chip->client->dev, "%s lock verify failed\n",
__func__);
return -EIO;
}
max17042_write_custom_regs(chip);
max17042_update_capacity_regs(chip);
msleep(350);
max17042_reset_vfsoc0_reg(chip);
max17042_load_new_capacity_params(chip);
regmap_update_bits(map, MAX17042_STATUS, STATUS_POR_BIT, 0x0);
return 0;
}
static void max17042_set_soc_threshold(struct max17042_chip *chip, u16 off)
{
struct regmap *map = chip->regmap;
u32 soc, soc_tr;
regmap_read(map, MAX17042_RepSOC, &soc);
soc >>= 8;
soc_tr = (soc + off) << 8;
soc_tr |= (soc - off);
regmap_write(map, MAX17042_SALRT_Th, soc_tr);
}
static irqreturn_t max17042_thread_handler(int id, void *dev)
{
struct max17042_chip *chip = dev;
u32 val;
regmap_read(chip->regmap, MAX17042_STATUS, &val);
if ((val & STATUS_INTR_SOCMIN_BIT) ||
(val & STATUS_INTR_SOCMAX_BIT)) {
dev_info(&chip->client->dev, "SOC threshold INTR\n");
max17042_set_soc_threshold(chip, 1);
}
power_supply_changed(chip->battery);
return IRQ_HANDLED;
}
static void max17042_init_worker(struct work_struct *work)
{
struct max17042_chip *chip = container_of(work,
struct max17042_chip, work);
int ret;
if (chip->pdata->enable_por_init && chip->pdata->config_data) {
ret = max17042_init_chip(chip);
if (ret)
return;
}
chip->init_complete = 1;
}
static struct max17042_platform_data *
max17042_get_pdata(struct max17042_chip *chip)
{
struct device *dev = &chip->client->dev;
struct device_node *np = dev->of_node;
u32 prop;
struct max17042_platform_data *pdata;
if (!np)
return dev->platform_data;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
if (of_property_read_u32(np, "maxim,rsns-microohm", &prop) == 0) {
pdata->r_sns = prop;
pdata->enable_current_sense = true;
}
if (of_property_read_s32(np, "maxim,cold-temp", &pdata->temp_min))
pdata->temp_min = INT_MIN;
if (of_property_read_s32(np, "maxim,over-heat-temp", &pdata->temp_max))
pdata->temp_max = INT_MAX;
if (of_property_read_s32(np, "maxim,dead-volt", &pdata->vmin))
pdata->vmin = INT_MIN;
if (of_property_read_s32(np, "maxim,over-volt", &pdata->vmax))
pdata->vmax = INT_MAX;
return pdata;
}
static struct max17042_platform_data *
max17042_get_pdata(struct max17042_chip *chip)
{
struct device *dev = &chip->client->dev;
struct max17042_platform_data *pdata;
int ret, misc_cfg;
if (dev->platform_data)
return dev->platform_data;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return pdata;
if (chip->chip_type != MAXIM_DEVICE_TYPE_MAX17042) {
pdata->init_data = max17047_default_pdata_init_regs;
pdata->num_init_data =
ARRAY_SIZE(max17047_default_pdata_init_regs);
}
ret = regmap_read(chip->regmap, MAX17042_MiscCFG, &misc_cfg);
if (ret < 0)
return NULL;
if ((misc_cfg & 0x3) == 0x3)
pdata->enable_current_sense = false;
else
pdata->enable_current_sense = true;
pdata->vmin = MAX17042_DEFAULT_VMIN;
pdata->vmax = MAX17042_DEFAULT_VMAX;
pdata->temp_min = MAX17042_DEFAULT_TEMP_MIN;
pdata->temp_max = MAX17042_DEFAULT_TEMP_MAX;
return pdata;
}
static int max17042_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
const struct power_supply_desc *max17042_desc = &max17042_psy_desc;
struct power_supply_config psy_cfg = {};
const struct acpi_device_id *acpi_id = NULL;
struct device *dev = &client->dev;
struct max17042_chip *chip;
int ret;
int i;
u32 val;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -EIO;
chip = devm_kzalloc(&client->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->client = client;
if (id) {
chip->chip_type = id->driver_data;
} else {
acpi_id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!acpi_id)
return -ENODEV;
chip->chip_type = acpi_id->driver_data;
}
chip->regmap = devm_regmap_init_i2c(client, &max17042_regmap_config);
if (IS_ERR(chip->regmap)) {
dev_err(&client->dev, "Failed to initialize regmap\n");
return -EINVAL;
}
chip->pdata = max17042_get_pdata(chip);
if (!chip->pdata) {
dev_err(&client->dev, "no platform data provided\n");
return -EINVAL;
}
i2c_set_clientdata(client, chip);
psy_cfg.drv_data = chip;
if (!chip->pdata->enable_current_sense)
max17042_desc = &max17042_no_current_sense_psy_desc;
if (chip->pdata->r_sns == 0)
chip->pdata->r_sns = MAX17042_DEFAULT_SNS_RESISTOR;
if (chip->pdata->init_data)
for (i = 0; i < chip->pdata->num_init_data; i++)
regmap_write(chip->regmap,
chip->pdata->init_data[i].addr,
chip->pdata->init_data[i].data);
if (!chip->pdata->enable_current_sense) {
regmap_write(chip->regmap, MAX17042_CGAIN, 0x0000);
regmap_write(chip->regmap, MAX17042_MiscCFG, 0x0003);
regmap_write(chip->regmap, MAX17042_LearnCFG, 0x0007);
}
chip->battery = devm_power_supply_register(&client->dev, max17042_desc,
&psy_cfg);
if (IS_ERR(chip->battery)) {
dev_err(&client->dev, "failed: power supply register\n");
return PTR_ERR(chip->battery);
}
if (client->irq) {
unsigned int flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
if (acpi_id)
flags |= IRQF_SHARED | IRQF_PROBE_SHARED;
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL,
max17042_thread_handler, flags,
chip->battery->desc->name,
chip);
if (!ret) {
regmap_update_bits(chip->regmap, MAX17042_CONFIG,
CONFIG_ALRT_BIT_ENBL,
CONFIG_ALRT_BIT_ENBL);
max17042_set_soc_threshold(chip, 1);
} else {
client->irq = 0;
if (ret != -EBUSY)
dev_err(&client->dev, "Failed to get IRQ\n");
}
}
if (!client->irq)
regmap_write(chip->regmap, MAX17042_SALRT_Th, 0xff00);
regmap_read(chip->regmap, MAX17042_STATUS, &val);
if (val & STATUS_POR_BIT) {
INIT_WORK(&chip->work, max17042_init_worker);
schedule_work(&chip->work);
} else {
chip->init_complete = 1;
}
return 0;
}
static int max17042_suspend(struct device *dev)
{
struct max17042_chip *chip = dev_get_drvdata(dev);
if (chip->client->irq) {
disable_irq(chip->client->irq);
enable_irq_wake(chip->client->irq);
}
return 0;
}
static int max17042_resume(struct device *dev)
{
struct max17042_chip *chip = dev_get_drvdata(dev);
if (chip->client->irq) {
disable_irq_wake(chip->client->irq);
enable_irq(chip->client->irq);
max17042_set_soc_threshold(chip, 1);
}
return 0;
}
