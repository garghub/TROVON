static int ltc3589_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
struct ltc3589 *ltc3589 = rdev_get_drvdata(rdev);
int sel, shift;
if (unlikely(ramp_delay <= 0))
return -EINVAL;
shift = ffs(rdev->desc->apply_bit) - 1;
for (sel = 0; sel < 4; sel++) {
if ((880 << sel) >= ramp_delay) {
return regmap_update_bits(ltc3589->regmap,
LTC3589_VRRCR,
0x3 << shift, sel << shift);
}
}
return -EINVAL;
}
static int ltc3589_set_suspend_voltage(struct regulator_dev *rdev, int uV)
{
struct ltc3589 *ltc3589 = rdev_get_drvdata(rdev);
int sel;
sel = regulator_map_voltage_linear(rdev, uV, uV);
if (sel < 0)
return sel;
return regmap_update_bits(ltc3589->regmap, rdev->desc->vsel_reg + 1,
rdev->desc->vsel_mask, sel);
}
static int ltc3589_set_suspend_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct ltc3589 *ltc3589 = rdev_get_drvdata(rdev);
int mask, bit = 0;
mask = rdev->desc->apply_bit << 1;
if (mode == REGULATOR_MODE_STANDBY)
bit = mask;
mask |= rdev->desc->apply_bit;
bit |= rdev->desc->apply_bit;
return regmap_update_bits(ltc3589->regmap, LTC3589_VCCR, mask, bit);
}
static int ltc3589_parse_regulators_dt(struct ltc3589 *ltc3589)
{
struct device *dev = ltc3589->dev;
struct device_node *node;
int i, ret;
node = of_get_child_by_name(dev->of_node, "regulators");
if (!node) {
dev_err(dev, "regulators node not found\n");
return -EINVAL;
}
ret = of_regulator_match(dev, node, ltc3589_matches,
ARRAY_SIZE(ltc3589_matches));
of_node_put(node);
if (ret < 0) {
dev_err(dev, "Error parsing regulator init data: %d\n", ret);
return ret;
}
if (ret != LTC3589_NUM_REGULATORS) {
dev_err(dev, "Only %d regulators described in device tree\n",
ret);
return -EINVAL;
}
for (i = 0; i < LTC3589_LDO3; i++) {
struct ltc3589_regulator *desc = &ltc3589->regulator_descs[i];
struct device_node *np = ltc3589_matches[i].of_node;
u32 vdiv[2];
ret = of_property_read_u32_array(np, "lltc,fb-voltage-divider",
vdiv, 2);
if (ret) {
dev_err(dev, "Failed to parse voltage divider: %d\n",
ret);
return ret;
}
desc->r1 = vdiv[0];
desc->r2 = vdiv[1];
}
return 0;
}
static inline struct regulator_init_data *match_init_data(int index)
{
return ltc3589_matches[index].init_data;
}
static inline struct device_node *match_of_node(int index)
{
return ltc3589_matches[index].of_node;
}
static inline int ltc3589_parse_regulators_dt(struct ltc3589 *ltc3589)
{
return 0;
}
static inline struct regulator_init_data *match_init_data(int index)
{
return NULL;
}
static inline struct device_node *match_of_node(int index)
{
return NULL;
}
static bool ltc3589_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case LTC3589_IRQSTAT:
case LTC3589_SCR1:
case LTC3589_OVEN:
case LTC3589_SCR2:
case LTC3589_VCCR:
case LTC3589_CLIRQ:
case LTC3589_B1DTV1:
case LTC3589_B1DTV2:
case LTC3589_VRRCR:
case LTC3589_B2DTV1:
case LTC3589_B2DTV2:
case LTC3589_B3DTV1:
case LTC3589_B3DTV2:
case LTC3589_L2DTV1:
case LTC3589_L2DTV2:
return true;
}
return false;
}
static bool ltc3589_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case LTC3589_IRQSTAT:
case LTC3589_SCR1:
case LTC3589_OVEN:
case LTC3589_SCR2:
case LTC3589_PGSTAT:
case LTC3589_VCCR:
case LTC3589_B1DTV1:
case LTC3589_B1DTV2:
case LTC3589_VRRCR:
case LTC3589_B2DTV1:
case LTC3589_B2DTV2:
case LTC3589_B3DTV1:
case LTC3589_B3DTV2:
case LTC3589_L2DTV1:
case LTC3589_L2DTV2:
return true;
}
return false;
}
static bool ltc3589_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case LTC3589_IRQSTAT:
case LTC3589_PGSTAT:
return true;
}
return false;
}
static irqreturn_t ltc3589_isr(int irq, void *dev_id)
{
struct ltc3589 *ltc3589 = dev_id;
unsigned int i, irqstat, event;
regmap_read(ltc3589->regmap, LTC3589_IRQSTAT, &irqstat);
if (irqstat & LTC3589_IRQSTAT_THERMAL_WARN) {
event = REGULATOR_EVENT_OVER_TEMP;
for (i = 0; i < LTC3589_NUM_REGULATORS; i++)
regulator_notifier_call_chain(ltc3589->regulators[i],
event, NULL);
}
if (irqstat & LTC3589_IRQSTAT_UNDERVOLT_WARN) {
event = REGULATOR_EVENT_UNDER_VOLTAGE;
for (i = 0; i < LTC3589_NUM_REGULATORS; i++)
regulator_notifier_call_chain(ltc3589->regulators[i],
event, NULL);
}
regmap_write(ltc3589->regmap, LTC3589_CLIRQ, 0);
return IRQ_HANDLED;
}
static inline unsigned int ltc3589_scale(unsigned int uV, u32 r1, u32 r2)
{
uint64_t tmp;
if (uV == 0)
return 0;
tmp = (uint64_t)uV * r1;
do_div(tmp, r2);
return uV + (unsigned int)tmp;
}
static void ltc3589_apply_fb_voltage_divider(struct ltc3589_regulator *rdesc)
{
struct regulator_desc *desc = &rdesc->desc;
if (!rdesc->r1 || !rdesc->r2)
return;
desc->min_uV = ltc3589_scale(desc->min_uV, rdesc->r1, rdesc->r2);
desc->uV_step = ltc3589_scale(desc->uV_step, rdesc->r1, rdesc->r2);
desc->fixed_uV = ltc3589_scale(desc->fixed_uV, rdesc->r1, rdesc->r2);
}
static int ltc3589_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct ltc3589_regulator *descs;
struct ltc3589 *ltc3589;
int i, ret;
ltc3589 = devm_kzalloc(dev, sizeof(*ltc3589), GFP_KERNEL);
if (!ltc3589)
return -ENOMEM;
i2c_set_clientdata(client, ltc3589);
ltc3589->variant = id->driver_data;
ltc3589->dev = dev;
descs = ltc3589->regulator_descs;
memcpy(descs, ltc3589_regulators, sizeof(ltc3589_regulators));
if (ltc3589->variant == LTC3589) {
descs[LTC3589_LDO3].desc.fixed_uV = 1800000;
descs[LTC3589_LDO4].desc.volt_table = ltc3589_ldo4;
} else {
descs[LTC3589_LDO3].desc.fixed_uV = 2800000;
descs[LTC3589_LDO4].desc.volt_table = ltc3589_12_ldo4;
}
ltc3589->regmap = devm_regmap_init_i2c(client, &ltc3589_regmap_config);
if (IS_ERR(ltc3589->regmap)) {
ret = PTR_ERR(ltc3589->regmap);
dev_err(dev, "failed to initialize regmap: %d\n", ret);
return ret;
}
ret = ltc3589_parse_regulators_dt(ltc3589);
if (ret)
return ret;
for (i = 0; i < LTC3589_NUM_REGULATORS; i++) {
struct ltc3589_regulator *rdesc = &ltc3589->regulator_descs[i];
struct regulator_desc *desc = &rdesc->desc;
struct regulator_init_data *init_data;
struct regulator_config config = { };
init_data = match_init_data(i);
if (i < LTC3589_LDO3)
ltc3589_apply_fb_voltage_divider(rdesc);
config.dev = dev;
config.init_data = init_data;
config.driver_data = ltc3589;
config.of_node = match_of_node(i);
ltc3589->regulators[i] = devm_regulator_register(dev, desc,
&config);
if (IS_ERR(ltc3589->regulators[i])) {
ret = PTR_ERR(ltc3589->regulators[i]);
dev_err(dev, "failed to register regulator %s: %d\n",
desc->name, ret);
return ret;
}
}
ret = devm_request_threaded_irq(dev, client->irq, NULL, ltc3589_isr,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
client->name, ltc3589);
if (ret) {
dev_err(dev, "Failed to request IRQ: %d\n", ret);
return ret;
}
return 0;
}
