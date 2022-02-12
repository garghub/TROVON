static int bq25890_field_read(struct bq25890_device *bq,
enum bq25890_fields field_id)
{
int ret;
int val;
ret = regmap_field_read(bq->rmap_fields[field_id], &val);
if (ret < 0)
return ret;
return val;
}
static int bq25890_field_write(struct bq25890_device *bq,
enum bq25890_fields field_id, u8 val)
{
return regmap_field_write(bq->rmap_fields[field_id], val);
}
static u8 bq25890_find_idx(u32 value, enum bq25890_table_ids id)
{
u8 idx;
if (id >= TBL_TREG) {
const u32 *tbl = bq25890_tables[id].lt.tbl;
u32 tbl_size = bq25890_tables[id].lt.size;
for (idx = 1; idx < tbl_size && tbl[idx] <= value; idx++)
;
} else {
const struct bq25890_range *rtbl = &bq25890_tables[id].rt;
u8 rtbl_size;
rtbl_size = (rtbl->max - rtbl->min) / rtbl->step + 1;
for (idx = 1;
idx < rtbl_size && (idx * rtbl->step + rtbl->min <= value);
idx++)
;
}
return idx - 1;
}
static u32 bq25890_find_val(u8 idx, enum bq25890_table_ids id)
{
const struct bq25890_range *rtbl;
if (id >= TBL_TREG)
return bq25890_tables[id].lt.tbl[idx];
rtbl = &bq25890_tables[id].rt;
return (rtbl->min + idx * rtbl->step);
}
static int bq25890_power_supply_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret;
struct bq25890_device *bq = power_supply_get_drvdata(psy);
struct bq25890_state state;
mutex_lock(&bq->lock);
state = bq->state;
mutex_unlock(&bq->lock);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (!state.online)
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else if (state.chrg_status == STATUS_NOT_CHARGING)
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else if (state.chrg_status == STATUS_PRE_CHARGING ||
state.chrg_status == STATUS_FAST_CHARGING)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else if (state.chrg_status == STATUS_TERMINATION_DONE)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = BQ25890_MANUFACTURER;
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = state.online;
break;
case POWER_SUPPLY_PROP_HEALTH:
if (!state.chrg_fault && !state.bat_fault && !state.boost_fault)
val->intval = POWER_SUPPLY_HEALTH_GOOD;
else if (state.bat_fault)
val->intval = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
else if (state.chrg_fault == CHRG_FAULT_TIMER_EXPIRED)
val->intval = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
else if (state.chrg_fault == CHRG_FAULT_THERMAL_SHUTDOWN)
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
else
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
ret = bq25890_field_read(bq, F_ICHGR);
if (ret < 0)
return ret;
val->intval = ret * 50000;
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT_MAX:
val->intval = bq25890_tables[TBL_ICHG].rt.max;
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE:
if (!state.online) {
val->intval = 0;
break;
}
ret = bq25890_field_read(bq, F_BATV);
if (ret < 0)
return ret;
val->intval = 2304000 + ret * 20000;
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE_MAX:
val->intval = bq25890_tables[TBL_VREG].rt.max;
break;
case POWER_SUPPLY_PROP_CHARGE_TERM_CURRENT:
val->intval = bq25890_find_val(bq->init_data.iterm, TBL_ITERM);
break;
default:
return -EINVAL;
}
return 0;
}
static int bq25890_get_chip_state(struct bq25890_device *bq,
struct bq25890_state *state)
{
int i, ret;
struct {
enum bq25890_fields id;
u8 *data;
} state_fields[] = {
{F_CHG_STAT, &state->chrg_status},
{F_PG_STAT, &state->online},
{F_VSYS_STAT, &state->vsys_status},
{F_BOOST_FAULT, &state->boost_fault},
{F_BAT_FAULT, &state->bat_fault},
{F_CHG_FAULT, &state->chrg_fault}
};
for (i = 0; i < ARRAY_SIZE(state_fields); i++) {
ret = bq25890_field_read(bq, state_fields[i].id);
if (ret < 0)
return ret;
*state_fields[i].data = ret;
}
dev_dbg(bq->dev, "S:CHG/PG/VSYS=%d/%d/%d, F:CHG/BOOST/BAT=%d/%d/%d\n",
state->chrg_status, state->online, state->vsys_status,
state->chrg_fault, state->boost_fault, state->bat_fault);
return 0;
}
static bool bq25890_state_changed(struct bq25890_device *bq,
struct bq25890_state *new_state)
{
struct bq25890_state old_state;
mutex_lock(&bq->lock);
old_state = bq->state;
mutex_unlock(&bq->lock);
return (old_state.chrg_status != new_state->chrg_status ||
old_state.chrg_fault != new_state->chrg_fault ||
old_state.online != new_state->online ||
old_state.bat_fault != new_state->bat_fault ||
old_state.boost_fault != new_state->boost_fault ||
old_state.vsys_status != new_state->vsys_status);
}
static void bq25890_handle_state_change(struct bq25890_device *bq,
struct bq25890_state *new_state)
{
int ret;
struct bq25890_state old_state;
mutex_lock(&bq->lock);
old_state = bq->state;
mutex_unlock(&bq->lock);
if (!new_state->online) {
ret = bq25890_field_write(bq, F_CONV_START, 0);
if (ret < 0)
goto error;
} else if (!old_state.online) {
ret = bq25890_field_write(bq, F_CONV_START, 1);
if (ret < 0)
goto error;
}
return;
error:
dev_err(bq->dev, "Error communicating with the chip.\n");
}
static irqreturn_t bq25890_irq_handler_thread(int irq, void *private)
{
struct bq25890_device *bq = private;
int ret;
struct bq25890_state state;
ret = bq25890_get_chip_state(bq, &state);
if (ret < 0)
goto handled;
if (!bq25890_state_changed(bq, &state))
goto handled;
bq25890_handle_state_change(bq, &state);
mutex_lock(&bq->lock);
bq->state = state;
mutex_unlock(&bq->lock);
power_supply_changed(bq->charger);
handled:
return IRQ_HANDLED;
}
static int bq25890_chip_reset(struct bq25890_device *bq)
{
int ret;
int rst_check_counter = 10;
ret = bq25890_field_write(bq, F_REG_RST, 1);
if (ret < 0)
return ret;
do {
ret = bq25890_field_read(bq, F_REG_RST);
if (ret < 0)
return ret;
usleep_range(5, 10);
} while (ret == 1 && --rst_check_counter);
if (!rst_check_counter)
return -ETIMEDOUT;
return 0;
}
static int bq25890_hw_init(struct bq25890_device *bq)
{
int ret;
int i;
struct bq25890_state state;
const struct {
enum bq25890_fields id;
u32 value;
} init_data[] = {
{F_ICHG, bq->init_data.ichg},
{F_VREG, bq->init_data.vreg},
{F_ITERM, bq->init_data.iterm},
{F_IPRECHG, bq->init_data.iprechg},
{F_SYSVMIN, bq->init_data.sysvmin},
{F_BOOSTV, bq->init_data.boostv},
{F_BOOSTI, bq->init_data.boosti},
{F_BOOSTF, bq->init_data.boostf},
{F_EN_ILIM, bq->init_data.ilim_en},
{F_TREG, bq->init_data.treg}
};
ret = bq25890_chip_reset(bq);
if (ret < 0)
return ret;
ret = bq25890_field_write(bq, F_WD, 0);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(init_data); i++) {
ret = bq25890_field_write(bq, init_data[i].id,
init_data[i].value);
if (ret < 0)
return ret;
}
ret = bq25890_field_write(bq, F_CONV_RATE, 1);
if (ret < 0)
return ret;
ret = bq25890_get_chip_state(bq, &state);
if (ret < 0)
return ret;
mutex_lock(&bq->lock);
bq->state = state;
mutex_unlock(&bq->lock);
return 0;
}
static int bq25890_power_supply_init(struct bq25890_device *bq)
{
struct power_supply_config psy_cfg = { .drv_data = bq, };
psy_cfg.supplied_to = bq25890_charger_supplied_to;
psy_cfg.num_supplicants = ARRAY_SIZE(bq25890_charger_supplied_to);
bq->charger = power_supply_register(bq->dev, &bq25890_power_supply_desc,
&psy_cfg);
return PTR_ERR_OR_ZERO(bq->charger);
}
static void bq25890_usb_work(struct work_struct *data)
{
int ret;
struct bq25890_device *bq =
container_of(data, struct bq25890_device, usb_work);
switch (bq->usb_event) {
case USB_EVENT_ID:
ret = bq25890_field_write(bq, F_OTG_CFG, 1);
if (ret < 0)
goto error;
break;
case USB_EVENT_NONE:
ret = bq25890_field_write(bq, F_OTG_CFG, 0);
if (ret < 0)
goto error;
power_supply_changed(bq->charger);
break;
}
return;
error:
dev_err(bq->dev, "Error switching to boost/charger mode.\n");
}
static int bq25890_usb_notifier(struct notifier_block *nb, unsigned long val,
void *priv)
{
struct bq25890_device *bq =
container_of(nb, struct bq25890_device, usb_nb);
bq->usb_event = val;
queue_work(system_power_efficient_wq, &bq->usb_work);
return NOTIFY_OK;
}
static int bq25890_irq_probe(struct bq25890_device *bq)
{
struct gpio_desc *irq;
irq = devm_gpiod_get_index(bq->dev, BQ25890_IRQ_PIN, 0, GPIOD_IN);
if (IS_ERR(irq)) {
dev_err(bq->dev, "Could not probe irq pin.\n");
return PTR_ERR(irq);
}
return gpiod_to_irq(irq);
}
static int bq25890_fw_read_u32_props(struct bq25890_device *bq)
{
int ret;
u32 property;
int i;
struct bq25890_init_data *init = &bq->init_data;
struct {
char *name;
bool optional;
enum bq25890_table_ids tbl_id;
u8 *conv_data;
} props[] = {
{"ti,charge-current", false, TBL_ICHG, &init->ichg},
{"ti,battery-regulation-voltage", false, TBL_VREG, &init->vreg},
{"ti,termination-current", false, TBL_ITERM, &init->iterm},
{"ti,precharge-current", false, TBL_ITERM, &init->iprechg},
{"ti,minimum-sys-voltage", false, TBL_SYSVMIN, &init->sysvmin},
{"ti,boost-voltage", false, TBL_BOOSTV, &init->boostv},
{"ti,boost-max-current", false, TBL_BOOSTI, &init->boosti},
{"ti,thermal-regulation-threshold", true, TBL_TREG, &init->treg}
};
init->treg = 3;
for (i = 0; i < ARRAY_SIZE(props); i++) {
ret = device_property_read_u32(bq->dev, props[i].name,
&property);
if (ret < 0) {
if (props[i].optional)
continue;
return ret;
}
*props[i].conv_data = bq25890_find_idx(property,
props[i].tbl_id);
}
return 0;
}
static int bq25890_fw_probe(struct bq25890_device *bq)
{
int ret;
struct bq25890_init_data *init = &bq->init_data;
ret = bq25890_fw_read_u32_props(bq);
if (ret < 0)
return ret;
init->ilim_en = device_property_read_bool(bq->dev, "ti,use-ilim-pin");
init->boostf = device_property_read_bool(bq->dev, "ti,boost-low-freq");
return 0;
}
static int bq25890_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct device *dev = &client->dev;
struct bq25890_device *bq;
int ret;
int i;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(dev, "No support for SMBUS_BYTE_DATA\n");
return -ENODEV;
}
bq = devm_kzalloc(dev, sizeof(*bq), GFP_KERNEL);
if (!bq)
return -ENOMEM;
bq->client = client;
bq->dev = dev;
mutex_init(&bq->lock);
bq->rmap = devm_regmap_init_i2c(client, &bq25890_regmap_config);
if (IS_ERR(bq->rmap)) {
dev_err(dev, "failed to allocate register map\n");
return PTR_ERR(bq->rmap);
}
for (i = 0; i < ARRAY_SIZE(bq25890_reg_fields); i++) {
const struct reg_field *reg_fields = bq25890_reg_fields;
bq->rmap_fields[i] = devm_regmap_field_alloc(dev, bq->rmap,
reg_fields[i]);
if (IS_ERR(bq->rmap_fields[i])) {
dev_err(dev, "cannot allocate regmap field\n");
return PTR_ERR(bq->rmap_fields[i]);
}
}
i2c_set_clientdata(client, bq);
bq->chip_id = bq25890_field_read(bq, F_PN);
if (bq->chip_id < 0) {
dev_err(dev, "Cannot read chip ID.\n");
return bq->chip_id;
}
if (bq->chip_id != BQ25890_ID) {
dev_err(dev, "Chip with ID=%d, not supported!\n", bq->chip_id);
return -ENODEV;
}
if (!dev->platform_data) {
ret = bq25890_fw_probe(bq);
if (ret < 0) {
dev_err(dev, "Cannot read device properties.\n");
return ret;
}
} else {
return -ENODEV;
}
ret = bq25890_hw_init(bq);
if (ret < 0) {
dev_err(dev, "Cannot initialize the chip.\n");
return ret;
}
if (client->irq <= 0)
client->irq = bq25890_irq_probe(bq);
if (client->irq < 0) {
dev_err(dev, "No irq resource found.\n");
return client->irq;
}
bq->usb_phy = devm_usb_get_phy(dev, USB_PHY_TYPE_USB2);
if (!IS_ERR_OR_NULL(bq->usb_phy)) {
INIT_WORK(&bq->usb_work, bq25890_usb_work);
bq->usb_nb.notifier_call = bq25890_usb_notifier;
usb_register_notifier(bq->usb_phy, &bq->usb_nb);
}
ret = devm_request_threaded_irq(dev, client->irq, NULL,
bq25890_irq_handler_thread,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
BQ25890_IRQ_PIN, bq);
if (ret)
goto irq_fail;
ret = bq25890_power_supply_init(bq);
if (ret < 0) {
dev_err(dev, "Failed to register power supply\n");
goto irq_fail;
}
return 0;
irq_fail:
if (!IS_ERR_OR_NULL(bq->usb_phy))
usb_unregister_notifier(bq->usb_phy, &bq->usb_nb);
return ret;
}
static int bq25890_remove(struct i2c_client *client)
{
struct bq25890_device *bq = i2c_get_clientdata(client);
power_supply_unregister(bq->charger);
if (!IS_ERR_OR_NULL(bq->usb_phy))
usb_unregister_notifier(bq->usb_phy, &bq->usb_nb);
bq25890_chip_reset(bq);
return 0;
}
static int bq25890_suspend(struct device *dev)
{
struct bq25890_device *bq = dev_get_drvdata(dev);
return bq25890_field_write(bq, F_CONV_START, 0);
}
static int bq25890_resume(struct device *dev)
{
int ret;
struct bq25890_state state;
struct bq25890_device *bq = dev_get_drvdata(dev);
ret = bq25890_get_chip_state(bq, &state);
if (ret < 0)
return ret;
mutex_lock(&bq->lock);
bq->state = state;
mutex_unlock(&bq->lock);
if (state.online) {
ret = bq25890_field_write(bq, F_CONV_START, 1);
if (ret < 0)
return ret;
}
power_supply_changed(bq->charger);
return 0;
}
