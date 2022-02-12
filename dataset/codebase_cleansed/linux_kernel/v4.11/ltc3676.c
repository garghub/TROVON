static int ltc3676_set_suspend_voltage(struct regulator_dev *rdev, int uV)
{
struct ltc3676 *ltc3676 = rdev_get_drvdata(rdev);
struct device *dev = ltc3676->dev;
int dcdc = rdev_get_id(rdev);
int sel;
dev_dbg(dev, "%s id=%d uV=%d\n", __func__, dcdc, uV);
sel = regulator_map_voltage_linear(rdev, uV, uV);
if (sel < 0)
return sel;
return regmap_update_bits(ltc3676->regmap, rdev->desc->vsel_reg + 1,
rdev->desc->vsel_mask, sel);
}
static int ltc3676_set_suspend_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct ltc3676 *ltc3676= rdev_get_drvdata(rdev);
struct device *dev = ltc3676->dev;
int mask, val;
int dcdc = rdev_get_id(rdev);
dev_dbg(dev, "%s id=%d mode=%d\n", __func__, dcdc, mode);
mask = LTC3676_DVBxA_REF_SELECT;
switch (mode) {
case REGULATOR_MODE_STANDBY:
val = 0;
break;
case REGULATOR_MODE_NORMAL:
val = LTC3676_DVBxA_REF_SELECT;
break;
default:
dev_warn(&rdev->dev, "%s: regulator mode: 0x%x not supported\n",
rdev->desc->name, mode);
return -EINVAL;
}
return regmap_update_bits(ltc3676->regmap, rdev->desc->vsel_reg,
mask, val);
}
static inline unsigned int ltc3676_scale(unsigned int uV, u32 r1, u32 r2)
{
uint64_t tmp;
if (uV == 0)
return 0;
tmp = (uint64_t)uV * r1;
do_div(tmp, r2);
return uV + (unsigned int)tmp;
}
static int ltc3676_of_parse_cb(struct device_node *np,
const struct regulator_desc *desc,
struct regulator_config *config)
{
struct ltc3676 *ltc3676 = config->driver_data;
struct regulator_desc *rdesc = &ltc3676->regulator_descs[desc->id];
u32 r[2];
int ret;
if (desc->id == LTC3676_LDO3)
return 0;
ret = of_property_read_u32_array(np, "lltc,fb-voltage-divider", r, 2);
if (ret) {
dev_err(ltc3676->dev, "Failed to parse voltage divider: %d\n",
ret);
return ret;
}
rdesc->min_uV = ltc3676_scale(desc->min_uV, r[0], r[1]);
rdesc->uV_step = ltc3676_scale(desc->uV_step, r[0], r[1]);
rdesc->fixed_uV = ltc3676_scale(desc->fixed_uV, r[0], r[1]);
return 0;
}
static bool ltc3676_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case LTC3676_IRQSTAT:
case LTC3676_BUCK1:
case LTC3676_BUCK2:
case LTC3676_BUCK3:
case LTC3676_BUCK4:
case LTC3676_LDOA:
case LTC3676_LDOB:
case LTC3676_SQD1:
case LTC3676_SQD2:
case LTC3676_CNTRL:
case LTC3676_DVB1A:
case LTC3676_DVB1B:
case LTC3676_DVB2A:
case LTC3676_DVB2B:
case LTC3676_DVB3A:
case LTC3676_DVB3B:
case LTC3676_DVB4A:
case LTC3676_DVB4B:
case LTC3676_MSKIRQ:
case LTC3676_MSKPG:
case LTC3676_USER:
case LTC3676_HRST:
case LTC3676_CLIRQ:
return true;
}
return false;
}
static bool ltc3676_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case LTC3676_IRQSTAT:
case LTC3676_BUCK1:
case LTC3676_BUCK2:
case LTC3676_BUCK3:
case LTC3676_BUCK4:
case LTC3676_LDOA:
case LTC3676_LDOB:
case LTC3676_SQD1:
case LTC3676_SQD2:
case LTC3676_CNTRL:
case LTC3676_DVB1A:
case LTC3676_DVB1B:
case LTC3676_DVB2A:
case LTC3676_DVB2B:
case LTC3676_DVB3A:
case LTC3676_DVB3B:
case LTC3676_DVB4A:
case LTC3676_DVB4B:
case LTC3676_MSKIRQ:
case LTC3676_MSKPG:
case LTC3676_USER:
case LTC3676_HRST:
case LTC3676_CLIRQ:
return true;
}
return false;
}
static bool ltc3676_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case LTC3676_IRQSTAT:
case LTC3676_PGSTATL:
case LTC3676_PGSTATRT:
return true;
}
return false;
}
static irqreturn_t ltc3676_isr(int irq, void *dev_id)
{
struct ltc3676 *ltc3676 = dev_id;
struct device *dev = ltc3676->dev;
unsigned int i, irqstat, event;
regmap_read(ltc3676->regmap, LTC3676_IRQSTAT, &irqstat);
dev_dbg(dev, "irq%d irqstat=0x%02x\n", irq, irqstat);
if (irqstat & LTC3676_IRQSTAT_THERMAL_WARN) {
dev_warn(dev, "Over-temperature Warning\n");
event = REGULATOR_EVENT_OVER_TEMP;
for (i = 0; i < LTC3676_NUM_REGULATORS; i++)
regulator_notifier_call_chain(ltc3676->regulators[i],
event, NULL);
}
if (irqstat & LTC3676_IRQSTAT_UNDERVOLT_WARN) {
dev_info(dev, "Undervoltage Warning\n");
event = REGULATOR_EVENT_UNDER_VOLTAGE;
for (i = 0; i < LTC3676_NUM_REGULATORS; i++)
regulator_notifier_call_chain(ltc3676->regulators[i],
event, NULL);
}
regmap_write(ltc3676->regmap, LTC3676_CLIRQ, 0);
return IRQ_HANDLED;
}
static int ltc3676_regulator_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct regulator_init_data *init_data = dev_get_platdata(dev);
struct regulator_desc *descs;
struct ltc3676 *ltc3676;
int i, ret;
ltc3676 = devm_kzalloc(dev, sizeof(*ltc3676), GFP_KERNEL);
if (!ltc3676)
return -ENOMEM;
i2c_set_clientdata(client, ltc3676);
ltc3676->dev = dev;
descs = ltc3676->regulator_descs;
memcpy(descs, ltc3676_regulators, sizeof(ltc3676_regulators));
descs[LTC3676_LDO3].fixed_uV = 1800000;
ltc3676->regmap = devm_regmap_init_i2c(client, &ltc3676_regmap_config);
if (IS_ERR(ltc3676->regmap)) {
ret = PTR_ERR(ltc3676->regmap);
dev_err(dev, "failed to initialize regmap: %d\n", ret);
return ret;
}
for (i = 0; i < LTC3676_NUM_REGULATORS; i++) {
struct regulator_desc *desc = &ltc3676->regulator_descs[i];
struct regulator_config config = { };
if (init_data)
config.init_data = &init_data[i];
config.dev = dev;
config.driver_data = ltc3676;
ltc3676->regulators[i] = devm_regulator_register(dev, desc,
&config);
if (IS_ERR(ltc3676->regulators[i])) {
ret = PTR_ERR(ltc3676->regulators[i]);
dev_err(dev, "failed to register regulator %s: %d\n",
desc->name, ret);
return ret;
}
}
regmap_write(ltc3676->regmap, LTC3676_CLIRQ, 0);
if (client->irq) {
ret = devm_request_threaded_irq(dev, client->irq, NULL,
ltc3676_isr,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
client->name, ltc3676);
if (ret) {
dev_err(dev, "Failed to request IRQ: %d\n", ret);
return ret;
}
}
return 0;
}
