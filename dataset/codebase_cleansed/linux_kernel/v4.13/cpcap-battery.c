static struct cpcap_battery_state_data *
cpcap_battery_get_state(struct cpcap_battery_ddata *ddata,
enum cpcap_battery_state state)
{
if (state >= CPCAP_BATTERY_STATE_NR)
return NULL;
return &ddata->state[state];
}
static struct cpcap_battery_state_data *
cpcap_battery_latest(struct cpcap_battery_ddata *ddata)
{
return cpcap_battery_get_state(ddata, CPCAP_BATTERY_STATE_LATEST);
}
static struct cpcap_battery_state_data *
cpcap_battery_previous(struct cpcap_battery_ddata *ddata)
{
return cpcap_battery_get_state(ddata, CPCAP_BATTERY_STATE_PREVIOUS);
}
static int cpcap_charger_battery_temperature(struct cpcap_battery_ddata *ddata,
int *value)
{
struct iio_channel *channel;
int error;
channel = ddata->channels[CPCAP_BATTERY_IIO_BATTDET];
error = iio_read_channel_processed(channel, value);
if (error < 0) {
dev_warn(ddata->dev, "%s failed: %i\n", __func__, error);
*value = CPCAP_NO_BATTERY;
return error;
}
*value /= 100;
return 0;
}
static int cpcap_battery_get_voltage(struct cpcap_battery_ddata *ddata)
{
struct iio_channel *channel;
int error, value = 0;
channel = ddata->channels[CPCAP_BATTERY_IIO_VOLTAGE];
error = iio_read_channel_processed(channel, &value);
if (error < 0) {
dev_warn(ddata->dev, "%s failed: %i\n", __func__, error);
return 0;
}
return value * 1000;
}
static int cpcap_battery_get_current(struct cpcap_battery_ddata *ddata)
{
struct iio_channel *channel;
int error, value = 0;
channel = ddata->channels[CPCAP_BATTERY_IIO_BATT_CURRENT];
error = iio_read_channel_processed(channel, &value);
if (error < 0) {
dev_warn(ddata->dev, "%s failed: %i\n", __func__, error);
return 0;
}
return value * 1000;
}
static int cpcap_battery_cc_raw_div(struct cpcap_battery_ddata *ddata,
u32 sample, s32 accumulator,
s16 offset, u32 divider)
{
s64 acc;
u64 tmp;
int avg_current;
u32 cc_lsb;
sample &= 0xffffff;
offset &= 0x7ff;
switch (ddata->vendor) {
case CPCAP_VENDOR_ST:
cc_lsb = 95374;
break;
case CPCAP_VENDOR_TI:
cc_lsb = 91501;
break;
default:
return -EINVAL;
}
acc = accumulator;
acc = acc - ((s64)sample * offset);
cc_lsb = (cc_lsb * ddata->config.cd_factor) / 1000;
if (acc >= 0)
tmp = acc;
else
tmp = acc * -1;
tmp = tmp * cc_lsb;
do_div(tmp, divider);
avg_current = tmp;
if (acc >= 0)
return -avg_current;
else
return avg_current;
}
static int cpcap_battery_cc_to_uah(struct cpcap_battery_ddata *ddata,
u32 sample, s32 accumulator,
s16 offset)
{
return cpcap_battery_cc_raw_div(ddata, sample,
accumulator, offset,
3600000);
}
static int cpcap_battery_cc_to_ua(struct cpcap_battery_ddata *ddata,
u32 sample, s32 accumulator,
s16 offset)
{
return cpcap_battery_cc_raw_div(ddata, sample,
accumulator, offset,
sample *
CPCAP_BATTERY_CC_SAMPLE_PERIOD_MS);
}
static int
cpcap_battery_read_accumulated(struct cpcap_battery_ddata *ddata,
struct cpcap_coulomb_counter_data *ccd)
{
u16 buf[7];
int error;
ccd->sample = 0;
ccd->accumulator = 0;
ccd->offset = 0;
error = regmap_bulk_read(ddata->reg, CPCAP_REG_CCS1,
buf, ARRAY_SIZE(buf));
if (error)
return 0;
ccd->sample = (buf[1] & 0x0fff) << 16;
ccd->sample |= buf[0];
ccd->accumulator = ((s16)buf[3]) << 16;
ccd->accumulator |= buf[2];
ccd->offset = buf[5];
if (buf[4] >= 0x200)
ccd->offset |= 0xfc00;
return cpcap_battery_cc_to_uah(ddata,
ccd->sample,
ccd->accumulator,
ccd->offset);
}
static int cpcap_battery_cc_get_avg_current(struct cpcap_battery_ddata *ddata)
{
int value, acc, error;
s32 sample = 1;
s16 offset;
if (ddata->vendor == CPCAP_VENDOR_ST)
sample = 4;
error = regmap_read(ddata->reg, CPCAP_REG_CCI, &value);
if (error)
return error;
if ((ddata->vendor == CPCAP_VENDOR_TI) && (value > 0x2000))
value = value | 0xc000;
acc = (s16)value;
error = regmap_read(ddata->reg, CPCAP_REG_CCM, &value);
if (error)
return error;
if (value < 0x200)
offset = value;
else
offset = value | 0xfc00;
return cpcap_battery_cc_to_ua(ddata, sample, acc, offset);
}
static bool cpcap_battery_full(struct cpcap_battery_ddata *ddata)
{
struct cpcap_battery_state_data *state = cpcap_battery_latest(ddata);
if (state->voltage >= (ddata->config.info.voltage_max_design - 4000))
return true;
return false;
}
static int cpcap_battery_update_status(struct cpcap_battery_ddata *ddata)
{
struct cpcap_battery_state_data state, *latest, *previous;
ktime_t now;
int error;
memset(&state, 0, sizeof(state));
now = ktime_get();
latest = cpcap_battery_latest(ddata);
if (latest) {
s64 delta_ms = ktime_to_ms(ktime_sub(now, latest->time));
if (delta_ms < CPCAP_BATTERY_CC_SAMPLE_PERIOD_MS)
return delta_ms;
}
state.time = now;
state.voltage = cpcap_battery_get_voltage(ddata);
state.current_ua = cpcap_battery_get_current(ddata);
state.counter_uah = cpcap_battery_read_accumulated(ddata, &state.cc);
error = cpcap_charger_battery_temperature(ddata,
&state.temperature);
if (error)
return error;
previous = cpcap_battery_previous(ddata);
memcpy(previous, latest, sizeof(*previous));
memcpy(latest, &state, sizeof(*latest));
return 0;
}
static int cpcap_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct cpcap_battery_ddata *ddata = power_supply_get_drvdata(psy);
struct cpcap_battery_state_data *latest, *previous;
u32 sample;
s32 accumulator;
int cached;
s64 tmp;
cached = cpcap_battery_update_status(ddata);
if (cached < 0)
return cached;
latest = cpcap_battery_latest(ddata);
previous = cpcap_battery_previous(ddata);
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
if (latest->temperature > CPCAP_NO_BATTERY)
val->intval = 1;
else
val->intval = 0;
break;
case POWER_SUPPLY_PROP_STATUS:
if (cpcap_battery_full(ddata)) {
val->intval = POWER_SUPPLY_STATUS_FULL;
break;
}
if (cpcap_battery_cc_get_avg_current(ddata) < 0)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = ddata->config.info.technology;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = cpcap_battery_get_voltage(ddata);
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
val->intval = ddata->config.info.voltage_max_design;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = ddata->config.info.voltage_min_design;
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
if (cached) {
val->intval = cpcap_battery_cc_get_avg_current(ddata);
break;
}
sample = latest->cc.sample - previous->cc.sample;
accumulator = latest->cc.accumulator - previous->cc.accumulator;
val->intval = cpcap_battery_cc_to_ua(ddata, sample,
accumulator,
latest->cc.offset);
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
val->intval = latest->current_ua;
break;
case POWER_SUPPLY_PROP_CHARGE_COUNTER:
val->intval = latest->counter_uah;
break;
case POWER_SUPPLY_PROP_POWER_NOW:
tmp = (latest->voltage / 10000) * latest->current_ua;
val->intval = div64_s64(tmp, 100);
break;
case POWER_SUPPLY_PROP_POWER_AVG:
if (cached) {
tmp = cpcap_battery_cc_get_avg_current(ddata);
tmp *= (latest->voltage / 10000);
val->intval = div64_s64(tmp, 100);
break;
}
sample = latest->cc.sample - previous->cc.sample;
accumulator = latest->cc.accumulator - previous->cc.accumulator;
tmp = cpcap_battery_cc_to_ua(ddata, sample, accumulator,
latest->cc.offset);
tmp *= ((latest->voltage + previous->voltage) / 20000);
val->intval = div64_s64(tmp, 100);
break;
case POWER_SUPPLY_PROP_CAPACITY_LEVEL:
if (cpcap_battery_full(ddata))
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_FULL;
else if (latest->voltage >= 3750000)
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_HIGH;
else if (latest->voltage >= 3300000)
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_NORMAL;
else if (latest->voltage > 3100000)
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_LOW;
else if (latest->voltage <= 3100000)
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_CRITICAL;
else
val->intval = POWER_SUPPLY_CAPACITY_LEVEL_UNKNOWN;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
val->intval = ddata->config.info.charge_full_design;
break;
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_SYSTEM;
break;
case POWER_SUPPLY_PROP_TEMP:
val->intval = latest->temperature;
break;
default:
return -EINVAL;
}
return 0;
}
static irqreturn_t cpcap_battery_irq_thread(int irq, void *data)
{
struct cpcap_battery_ddata *ddata = data;
struct cpcap_battery_state_data *latest;
struct cpcap_interrupt_desc *d;
if (!atomic_read(&ddata->active))
return IRQ_NONE;
list_for_each_entry(d, &ddata->irq_list, node) {
if (irq == d->irq)
break;
}
if (!d)
return IRQ_NONE;
latest = cpcap_battery_latest(ddata);
switch (d->action) {
case CPCAP_BATTERY_IRQ_ACTION_BATTERY_LOW:
if (latest->counter_uah >= 0)
dev_warn(ddata->dev, "Battery low at 3.3V!\n");
break;
case CPCAP_BATTERY_IRQ_ACTION_POWEROFF:
if (latest->counter_uah >= 0) {
dev_emerg(ddata->dev,
"Battery empty at 3.1V, powering off\n");
orderly_poweroff(true);
}
break;
default:
break;
}
power_supply_changed(ddata->psy);
return IRQ_HANDLED;
}
static int cpcap_battery_init_irq(struct platform_device *pdev,
struct cpcap_battery_ddata *ddata,
const char *name)
{
struct cpcap_interrupt_desc *d;
int irq, error;
irq = platform_get_irq_byname(pdev, name);
if (!irq)
return -ENODEV;
error = devm_request_threaded_irq(ddata->dev, irq, NULL,
cpcap_battery_irq_thread,
IRQF_SHARED,
name, ddata);
if (error) {
dev_err(ddata->dev, "could not get irq %s: %i\n",
name, error);
return error;
}
d = devm_kzalloc(ddata->dev, sizeof(*d), GFP_KERNEL);
if (!d)
return -ENOMEM;
d->name = name;
d->irq = irq;
if (!strncmp(name, "lowbph", 6))
d->action = CPCAP_BATTERY_IRQ_ACTION_BATTERY_LOW;
else if (!strncmp(name, "lowbpl", 6))
d->action = CPCAP_BATTERY_IRQ_ACTION_POWEROFF;
list_add(&d->node, &ddata->irq_list);
return 0;
}
static int cpcap_battery_init_interrupts(struct platform_device *pdev,
struct cpcap_battery_ddata *ddata)
{
const char * const cpcap_battery_irqs[] = {
"eol", "lowbph", "lowbpl",
"chrgcurr1", "battdetb"
};
int i, error;
for (i = 0; i < ARRAY_SIZE(cpcap_battery_irqs); i++) {
error = cpcap_battery_init_irq(pdev, ddata,
cpcap_battery_irqs[i]);
if (error)
return error;
}
error = regmap_update_bits(ddata->reg, CPCAP_REG_BPEOL,
0xffff,
CPCAP_REG_BPEOL_BIT_BATTDETEN);
if (error)
return error;
return 0;
}
static int cpcap_battery_init_iio(struct cpcap_battery_ddata *ddata)
{
const char * const names[CPCAP_BATTERY_IIO_NR] = {
"battdetb", "battp", "chg_isense", "batti",
};
int error, i;
for (i = 0; i < CPCAP_BATTERY_IIO_NR; i++) {
ddata->channels[i] = devm_iio_channel_get(ddata->dev,
names[i]);
if (IS_ERR(ddata->channels[i])) {
error = PTR_ERR(ddata->channels[i]);
goto out_err;
}
if (!ddata->channels[i]->indio_dev) {
error = -ENXIO;
goto out_err;
}
}
return 0;
out_err:
dev_err(ddata->dev, "could not initialize VBUS or ID IIO: %i\n",
error);
return error;
}
static int cpcap_battery_probe(struct platform_device *pdev)
{
struct power_supply_desc *psy_desc;
struct cpcap_battery_ddata *ddata;
const struct of_device_id *match;
struct power_supply_config psy_cfg = {};
int error;
match = of_match_device(of_match_ptr(cpcap_battery_id_table),
&pdev->dev);
if (!match)
return -EINVAL;
if (!match->data) {
dev_err(&pdev->dev, "no configuration data found\n");
return -ENODEV;
}
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
INIT_LIST_HEAD(&ddata->irq_list);
ddata->dev = &pdev->dev;
memcpy(&ddata->config, match->data, sizeof(ddata->config));
ddata->reg = dev_get_regmap(ddata->dev->parent, NULL);
if (!ddata->reg)
return -ENODEV;
error = cpcap_get_vendor(ddata->dev, ddata->reg, &ddata->vendor);
if (error)
return error;
platform_set_drvdata(pdev, ddata);
error = regmap_update_bits(ddata->reg, CPCAP_REG_CCM,
0xffff, ddata->config.ccm);
if (error)
return error;
error = cpcap_battery_init_interrupts(pdev, ddata);
if (error)
return error;
error = cpcap_battery_init_iio(ddata);
if (error)
return error;
psy_desc = devm_kzalloc(ddata->dev, sizeof(*psy_desc), GFP_KERNEL);
if (!psy_desc)
return -ENOMEM;
psy_desc->name = "battery",
psy_desc->type = POWER_SUPPLY_TYPE_BATTERY,
psy_desc->properties = cpcap_battery_props,
psy_desc->num_properties = ARRAY_SIZE(cpcap_battery_props),
psy_desc->get_property = cpcap_battery_get_property,
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = ddata;
ddata->psy = devm_power_supply_register(ddata->dev, psy_desc,
&psy_cfg);
error = PTR_ERR_OR_ZERO(ddata->psy);
if (error) {
dev_err(ddata->dev, "failed to register power supply\n");
return error;
}
atomic_set(&ddata->active, 1);
return 0;
}
static int cpcap_battery_remove(struct platform_device *pdev)
{
struct cpcap_battery_ddata *ddata = platform_get_drvdata(pdev);
int error;
atomic_set(&ddata->active, 0);
error = regmap_update_bits(ddata->reg, CPCAP_REG_BPEOL,
0xffff, 0);
if (error)
dev_err(&pdev->dev, "could not disable: %i\n", error);
return 0;
}
