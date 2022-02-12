static int uniphier_tm_initialize_sensor(struct uniphier_tm_dev *tdev)
{
struct regmap *map = tdev->regmap;
u32 val;
u32 tmod_calib[2];
int ret;
regmap_write_bits(map, tdev->data->block_base + PVTCTLEN,
PVTCTLEN_EN, 0);
ret = regmap_read(map, tdev->data->map_base + TMODCOEF, &val);
if (ret)
return ret;
if (!val) {
ret = of_property_read_u32_array(tdev->dev->of_node,
"socionext,tmod-calibration",
tmod_calib,
ARRAY_SIZE(tmod_calib));
if (ret)
return ret;
regmap_write(map, tdev->data->tmod_setup_addr,
TMODSETUP0_EN | TMODSETUP0_VAL(tmod_calib[0]) |
TMODSETUP1_EN | TMODSETUP1_VAL(tmod_calib[1]));
}
regmap_write_bits(map, tdev->data->block_base + PVTCTLMODE,
PVTCTLMODE_MASK, PVTCTLMODE_TEMPMON);
regmap_write_bits(map, tdev->data->block_base + EMONREPEAT,
EMONREPEAT_ENDLESS | EMONREPEAT_PERIOD,
EMONREPEAT_ENDLESS | EMONREPEAT_PERIOD_1000000);
regmap_write_bits(map, tdev->data->map_base + PVTCTLSEL,
PVTCTLSEL_MASK, PVTCTLSEL_MONITOR);
return 0;
}
static void uniphier_tm_set_alert(struct uniphier_tm_dev *tdev, u32 ch,
u32 temp)
{
struct regmap *map = tdev->regmap;
regmap_write_bits(map, tdev->data->map_base + SETALERT0 + (ch << 2),
SETALERT_EN | SETALERT_TEMP_OVF,
SETALERT_EN |
SETALERT_TEMP_OVF_VALUE(temp / 1000));
}
static void uniphier_tm_enable_sensor(struct uniphier_tm_dev *tdev)
{
struct regmap *map = tdev->regmap;
int i;
u32 bits = 0;
for (i = 0; i < ALERT_CH_NUM; i++)
if (tdev->alert_en[i])
bits |= PMALERTINTCTL_EN(i);
regmap_write_bits(map, tdev->data->map_base + PMALERTINTCTL,
PMALERTINTCTL_MASK, bits);
regmap_write_bits(map, tdev->data->block_base + PVTCTLEN,
PVTCTLEN_EN, PVTCTLEN_EN);
usleep_range(700, 1500);
}
static void uniphier_tm_disable_sensor(struct uniphier_tm_dev *tdev)
{
struct regmap *map = tdev->regmap;
regmap_write_bits(map, tdev->data->map_base + PMALERTINTCTL,
PMALERTINTCTL_MASK, 0);
regmap_write_bits(map, tdev->data->block_base + PVTCTLEN,
PVTCTLEN_EN, 0);
usleep_range(1000, 2000);
}
static int uniphier_tm_get_temp(void *data, int *out_temp)
{
struct uniphier_tm_dev *tdev = data;
struct regmap *map = tdev->regmap;
int ret;
u32 temp;
ret = regmap_read(map, tdev->data->map_base + TMOD, &temp);
if (ret)
return ret;
*out_temp = sign_extend32(temp, TMOD_WIDTH - 1) * 1000;
return 0;
}
static void uniphier_tm_irq_clear(struct uniphier_tm_dev *tdev)
{
u32 mask = 0, bits = 0;
int i;
for (i = 0; i < ALERT_CH_NUM; i++) {
mask |= (PMALERTINTCTL_CLR(i) | PMALERTINTCTL_SET(i));
bits |= PMALERTINTCTL_CLR(i);
}
regmap_write_bits(tdev->regmap,
tdev->data->map_base + PMALERTINTCTL, mask, bits);
}
static irqreturn_t uniphier_tm_alarm_irq(int irq, void *_tdev)
{
struct uniphier_tm_dev *tdev = _tdev;
disable_irq_nosync(irq);
uniphier_tm_irq_clear(tdev);
return IRQ_WAKE_THREAD;
}
static irqreturn_t uniphier_tm_alarm_irq_thread(int irq, void *_tdev)
{
struct uniphier_tm_dev *tdev = _tdev;
thermal_zone_device_update(tdev->tz_dev, THERMAL_EVENT_UNSPECIFIED);
return IRQ_HANDLED;
}
static int uniphier_tm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct regmap *regmap;
struct device_node *parent;
struct uniphier_tm_dev *tdev;
const struct thermal_trip *trips;
int i, ret, irq, ntrips, crit_temp = INT_MAX;
tdev = devm_kzalloc(dev, sizeof(*tdev), GFP_KERNEL);
if (!tdev)
return -ENOMEM;
tdev->dev = dev;
tdev->data = of_device_get_match_data(dev);
if (WARN_ON(!tdev->data))
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
parent = of_get_parent(dev->of_node);
regmap = syscon_node_to_regmap(parent);
of_node_put(parent);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to get regmap (error %ld)\n",
PTR_ERR(regmap));
return PTR_ERR(regmap);
}
tdev->regmap = regmap;
ret = uniphier_tm_initialize_sensor(tdev);
if (ret) {
dev_err(dev, "failed to initialize sensor\n");
return ret;
}
ret = devm_request_threaded_irq(dev, irq, uniphier_tm_alarm_irq,
uniphier_tm_alarm_irq_thread,
0, "thermal", tdev);
if (ret)
return ret;
platform_set_drvdata(pdev, tdev);
tdev->tz_dev = devm_thermal_zone_of_sensor_register(dev, 0, tdev,
&uniphier_of_thermal_ops);
if (IS_ERR(tdev->tz_dev)) {
dev_err(dev, "failed to register sensor device\n");
return PTR_ERR(tdev->tz_dev);
}
trips = of_thermal_get_trip_points(tdev->tz_dev);
ntrips = of_thermal_get_ntrips(tdev->tz_dev);
if (ntrips > ALERT_CH_NUM) {
dev_err(dev, "thermal zone has too many trips\n");
return -E2BIG;
}
for (i = 0; i < ntrips; i++) {
if (trips[i].type == THERMAL_TRIP_CRITICAL &&
trips[i].temperature < crit_temp)
crit_temp = trips[i].temperature;
uniphier_tm_set_alert(tdev, i, trips[i].temperature);
tdev->alert_en[i] = true;
}
if (crit_temp > CRITICAL_TEMP_LIMIT) {
dev_err(dev, "critical trip is over limit(>%d), or not set\n",
CRITICAL_TEMP_LIMIT);
return -EINVAL;
}
uniphier_tm_enable_sensor(tdev);
return 0;
}
static int uniphier_tm_remove(struct platform_device *pdev)
{
struct uniphier_tm_dev *tdev = platform_get_drvdata(pdev);
uniphier_tm_disable_sensor(tdev);
return 0;
}
