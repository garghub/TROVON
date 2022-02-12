static int qpnp_tm_read(struct qpnp_tm_chip *chip, u16 addr, u8 *data)
{
unsigned int val;
int ret;
ret = regmap_read(chip->map, chip->base + addr, &val);
if (ret < 0)
return ret;
*data = val;
return 0;
}
static int qpnp_tm_write(struct qpnp_tm_chip *chip, u16 addr, u8 data)
{
return regmap_write(chip->map, chip->base + addr, data);
}
static int qpnp_tm_update_temp_no_adc(struct qpnp_tm_chip *chip)
{
unsigned int stage;
int ret;
u8 reg = 0;
ret = qpnp_tm_read(chip, QPNP_TM_REG_STATUS, &reg);
if (ret < 0)
return ret;
stage = reg & STATUS_STAGE_MASK;
if (stage > chip->stage) {
chip->temp = (stage - 1) * TEMP_STAGE_STEP +
chip->thresh * TEMP_THRESH_STEP +
TEMP_STAGE_HYSTERESIS + TEMP_THRESH_MIN;
} else if (stage < chip->stage) {
chip->temp = stage * TEMP_STAGE_STEP +
chip->thresh * TEMP_THRESH_STEP -
TEMP_STAGE_HYSTERESIS + TEMP_THRESH_MIN;
}
chip->stage = stage;
return 0;
}
static int qpnp_tm_get_temp(void *data, int *temp)
{
struct qpnp_tm_chip *chip = data;
int ret, mili_celsius;
if (!temp)
return -EINVAL;
if (IS_ERR(chip->adc)) {
ret = qpnp_tm_update_temp_no_adc(chip);
if (ret < 0)
return ret;
} else {
ret = iio_read_channel_processed(chip->adc, &mili_celsius);
if (ret < 0)
return ret;
chip->temp = mili_celsius;
}
*temp = chip->temp < 0 ? 0 : chip->temp;
return 0;
}
static irqreturn_t qpnp_tm_isr(int irq, void *data)
{
struct qpnp_tm_chip *chip = data;
thermal_zone_device_update(chip->tz_dev, THERMAL_EVENT_UNSPECIFIED);
return IRQ_HANDLED;
}
static int qpnp_tm_init(struct qpnp_tm_chip *chip)
{
int ret;
u8 reg;
chip->thresh = THRESH_MIN;
chip->temp = DEFAULT_TEMP;
ret = qpnp_tm_read(chip, QPNP_TM_REG_STATUS, &reg);
if (ret < 0)
return ret;
chip->stage = reg & STATUS_STAGE_MASK;
if (chip->stage)
chip->temp = chip->thresh * TEMP_THRESH_STEP +
(chip->stage - 1) * TEMP_STAGE_STEP +
TEMP_THRESH_MIN;
reg = chip->thresh & SHUTDOWN_CTRL1_THRESHOLD_MASK;
ret = qpnp_tm_write(chip, QPNP_TM_REG_SHUTDOWN_CTRL1, reg);
if (ret < 0)
return ret;
reg = ALARM_CTRL_FORCE_ENABLE;
ret = qpnp_tm_write(chip, QPNP_TM_REG_ALARM_CTRL, reg);
return ret;
}
static int qpnp_tm_probe(struct platform_device *pdev)
{
struct qpnp_tm_chip *chip;
struct device_node *node;
u8 type, subtype;
u32 res;
int ret, irq;
node = pdev->dev.of_node;
chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
dev_set_drvdata(&pdev->dev, chip);
chip->map = dev_get_regmap(pdev->dev.parent, NULL);
if (!chip->map)
return -ENXIO;
ret = of_property_read_u32(node, "reg", &res);
if (ret < 0)
return ret;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
chip->adc = iio_channel_get(&pdev->dev, "thermal");
if (PTR_ERR(chip->adc) == -EPROBE_DEFER)
return PTR_ERR(chip->adc);
chip->base = res;
ret = qpnp_tm_read(chip, QPNP_TM_REG_TYPE, &type);
if (ret < 0) {
dev_err(&pdev->dev, "could not read type\n");
goto fail;
}
ret = qpnp_tm_read(chip, QPNP_TM_REG_SUBTYPE, &subtype);
if (ret < 0) {
dev_err(&pdev->dev, "could not read subtype\n");
goto fail;
}
if (type != QPNP_TM_TYPE || subtype != QPNP_TM_SUBTYPE) {
dev_err(&pdev->dev, "invalid type 0x%02x or subtype 0x%02x\n",
type, subtype);
ret = -ENODEV;
goto fail;
}
ret = qpnp_tm_init(chip);
if (ret < 0) {
dev_err(&pdev->dev, "init failed\n");
goto fail;
}
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL, qpnp_tm_isr,
IRQF_ONESHOT, node->name, chip);
if (ret < 0)
goto fail;
chip->tz_dev = devm_thermal_zone_of_sensor_register(&pdev->dev, 0, chip,
&qpnp_tm_sensor_ops);
if (IS_ERR(chip->tz_dev)) {
dev_err(&pdev->dev, "failed to register sensor\n");
ret = PTR_ERR(chip->tz_dev);
goto fail;
}
return 0;
fail:
if (!IS_ERR(chip->adc))
iio_channel_release(chip->adc);
return ret;
}
static int qpnp_tm_remove(struct platform_device *pdev)
{
struct qpnp_tm_chip *chip = dev_get_drvdata(&pdev->dev);
if (!IS_ERR(chip->adc))
iio_channel_release(chip->adc);
return 0;
}
