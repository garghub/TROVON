static int drv260x_calculate_voltage(unsigned int voltage)
{
return (voltage * 255 / 5600);
}
static void drv260x_worker(struct work_struct *work)
{
struct drv260x_data *haptics = container_of(work, struct drv260x_data, work);
int error;
gpiod_set_value(haptics->enable_gpio, 1);
udelay(250);
error = regmap_write(haptics->regmap,
DRV260X_MODE, DRV260X_RT_PLAYBACK);
if (error) {
dev_err(&haptics->client->dev,
"Failed to write set mode: %d\n", error);
} else {
error = regmap_write(haptics->regmap,
DRV260X_RT_PB_IN, haptics->magnitude);
if (error)
dev_err(&haptics->client->dev,
"Failed to set magnitude: %d\n", error);
}
}
static int drv260x_haptics_play(struct input_dev *input, void *data,
struct ff_effect *effect)
{
struct drv260x_data *haptics = input_get_drvdata(input);
haptics->mode = DRV260X_LRA_NO_CAL_MODE;
if (effect->u.rumble.strong_magnitude > 0)
haptics->magnitude = effect->u.rumble.strong_magnitude;
else if (effect->u.rumble.weak_magnitude > 0)
haptics->magnitude = effect->u.rumble.weak_magnitude;
else
haptics->magnitude = 0;
schedule_work(&haptics->work);
return 0;
}
static void drv260x_close(struct input_dev *input)
{
struct drv260x_data *haptics = input_get_drvdata(input);
int error;
cancel_work_sync(&haptics->work);
error = regmap_write(haptics->regmap, DRV260X_MODE, DRV260X_STANDBY);
if (error)
dev_err(&haptics->client->dev,
"Failed to enter standby mode: %d\n", error);
gpiod_set_value(haptics->enable_gpio, 0);
}
static int drv260x_init(struct drv260x_data *haptics)
{
int error;
unsigned int cal_buf;
error = regmap_write(haptics->regmap,
DRV260X_RATED_VOLT, haptics->rated_voltage);
if (error) {
dev_err(&haptics->client->dev,
"Failed to write DRV260X_RATED_VOLT register: %d\n",
error);
return error;
}
error = regmap_write(haptics->regmap,
DRV260X_OD_CLAMP_VOLT, haptics->overdrive_voltage);
if (error) {
dev_err(&haptics->client->dev,
"Failed to write DRV260X_OD_CLAMP_VOLT register: %d\n",
error);
return error;
}
switch (haptics->mode) {
case DRV260X_LRA_MODE:
error = regmap_register_patch(haptics->regmap,
drv260x_lra_cal_regs,
ARRAY_SIZE(drv260x_lra_cal_regs));
if (error) {
dev_err(&haptics->client->dev,
"Failed to write LRA calibration registers: %d\n",
error);
return error;
}
break;
case DRV260X_ERM_MODE:
error = regmap_register_patch(haptics->regmap,
drv260x_erm_cal_regs,
ARRAY_SIZE(drv260x_erm_cal_regs));
if (error) {
dev_err(&haptics->client->dev,
"Failed to write ERM calibration registers: %d\n",
error);
return error;
}
error = regmap_update_bits(haptics->regmap, DRV260X_LIB_SEL,
DRV260X_LIB_SEL_MASK,
haptics->library);
if (error) {
dev_err(&haptics->client->dev,
"Failed to write DRV260X_LIB_SEL register: %d\n",
error);
return error;
}
break;
default:
error = regmap_register_patch(haptics->regmap,
drv260x_lra_init_regs,
ARRAY_SIZE(drv260x_lra_init_regs));
if (error) {
dev_err(&haptics->client->dev,
"Failed to write LRA init registers: %d\n",
error);
return error;
}
error = regmap_update_bits(haptics->regmap, DRV260X_LIB_SEL,
DRV260X_LIB_SEL_MASK,
haptics->library);
if (error) {
dev_err(&haptics->client->dev,
"Failed to write DRV260X_LIB_SEL register: %d\n",
error);
return error;
}
return 0;
}
error = regmap_write(haptics->regmap, DRV260X_GO, DRV260X_GO_BIT);
if (error) {
dev_err(&haptics->client->dev,
"Failed to write GO register: %d\n",
error);
return error;
}
do {
error = regmap_read(haptics->regmap, DRV260X_GO, &cal_buf);
if (error) {
dev_err(&haptics->client->dev,
"Failed to read GO register: %d\n",
error);
return error;
}
} while (cal_buf == DRV260X_GO_BIT);
return 0;
}
static int drv260x_parse_dt(struct device *dev,
struct drv260x_data *haptics)
{
struct device_node *np = dev->of_node;
unsigned int voltage;
int error;
error = of_property_read_u32(np, "mode", &haptics->mode);
if (error) {
dev_err(dev, "%s: No entry for mode\n", __func__);
return error;
}
error = of_property_read_u32(np, "library-sel", &haptics->library);
if (error) {
dev_err(dev, "%s: No entry for library selection\n",
__func__);
return error;
}
error = of_property_read_u32(np, "vib-rated-mv", &voltage);
if (!error)
haptics->rated_voltage = drv260x_calculate_voltage(voltage);
error = of_property_read_u32(np, "vib-overdrive-mv", &voltage);
if (!error)
haptics->overdrive_voltage = drv260x_calculate_voltage(voltage);
return 0;
}
static inline int drv260x_parse_dt(struct device *dev,
struct drv260x_data *haptics)
{
dev_err(dev, "no platform data defined\n");
return -EINVAL;
}
static int drv260x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct drv260x_platform_data *pdata = dev_get_platdata(&client->dev);
struct drv260x_data *haptics;
int error;
haptics = devm_kzalloc(&client->dev, sizeof(*haptics), GFP_KERNEL);
if (!haptics)
return -ENOMEM;
haptics->rated_voltage = DRV260X_DEF_OD_CLAMP_VOLT;
haptics->rated_voltage = DRV260X_DEF_RATED_VOLT;
if (pdata) {
haptics->mode = pdata->mode;
haptics->library = pdata->library_selection;
if (pdata->vib_overdrive_voltage)
haptics->overdrive_voltage = drv260x_calculate_voltage(pdata->vib_overdrive_voltage);
if (pdata->vib_rated_voltage)
haptics->rated_voltage = drv260x_calculate_voltage(pdata->vib_rated_voltage);
} else if (client->dev.of_node) {
error = drv260x_parse_dt(&client->dev, haptics);
if (error)
return error;
} else {
dev_err(&client->dev, "Platform data not set\n");
return -ENODEV;
}
if (haptics->mode < DRV260X_LRA_MODE ||
haptics->mode > DRV260X_ERM_MODE) {
dev_err(&client->dev,
"Vibrator mode is invalid: %i\n",
haptics->mode);
return -EINVAL;
}
if (haptics->library < DRV260X_LIB_EMPTY ||
haptics->library > DRV260X_ERM_LIB_F) {
dev_err(&client->dev,
"Library value is invalid: %i\n", haptics->library);
return -EINVAL;
}
if (haptics->mode == DRV260X_LRA_MODE &&
haptics->library != DRV260X_LIB_EMPTY &&
haptics->library != DRV260X_LIB_LRA) {
dev_err(&client->dev,
"LRA Mode with ERM Library mismatch\n");
return -EINVAL;
}
if (haptics->mode == DRV260X_ERM_MODE &&
(haptics->library == DRV260X_LIB_EMPTY ||
haptics->library == DRV260X_LIB_LRA)) {
dev_err(&client->dev,
"ERM Mode with LRA Library mismatch\n");
return -EINVAL;
}
haptics->regulator = devm_regulator_get(&client->dev, "vbat");
if (IS_ERR(haptics->regulator)) {
error = PTR_ERR(haptics->regulator);
dev_err(&client->dev,
"unable to get regulator, error: %d\n", error);
return error;
}
haptics->enable_gpio = devm_gpiod_get(&client->dev, "enable");
if (IS_ERR(haptics->enable_gpio)) {
error = PTR_ERR(haptics->enable_gpio);
if (error != -ENOENT && error != -ENOSYS)
return error;
haptics->enable_gpio = NULL;
} else {
gpiod_direction_output(haptics->enable_gpio, 1);
}
haptics->input_dev = devm_input_allocate_device(&client->dev);
if (!haptics->input_dev) {
dev_err(&client->dev, "Failed to allocate input device\n");
return -ENOMEM;
}
haptics->input_dev->name = "drv260x:haptics";
haptics->input_dev->dev.parent = client->dev.parent;
haptics->input_dev->close = drv260x_close;
input_set_drvdata(haptics->input_dev, haptics);
input_set_capability(haptics->input_dev, EV_FF, FF_RUMBLE);
error = input_ff_create_memless(haptics->input_dev, NULL,
drv260x_haptics_play);
if (error) {
dev_err(&client->dev, "input_ff_create() failed: %d\n",
error);
return error;
}
INIT_WORK(&haptics->work, drv260x_worker);
haptics->client = client;
i2c_set_clientdata(client, haptics);
haptics->regmap = devm_regmap_init_i2c(client, &drv260x_regmap_config);
if (IS_ERR(haptics->regmap)) {
error = PTR_ERR(haptics->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
error = drv260x_init(haptics);
if (error) {
dev_err(&client->dev, "Device init failed: %d\n", error);
return error;
}
error = input_register_device(haptics->input_dev);
if (error) {
dev_err(&client->dev, "couldn't register input device: %d\n",
error);
return error;
}
return 0;
}
static int __maybe_unused drv260x_suspend(struct device *dev)
{
struct drv260x_data *haptics = dev_get_drvdata(dev);
int ret = 0;
mutex_lock(&haptics->input_dev->mutex);
if (haptics->input_dev->users) {
ret = regmap_update_bits(haptics->regmap,
DRV260X_MODE,
DRV260X_STANDBY_MASK,
DRV260X_STANDBY);
if (ret) {
dev_err(dev, "Failed to set standby mode\n");
goto out;
}
gpiod_set_value(haptics->enable_gpio, 0);
ret = regulator_disable(haptics->regulator);
if (ret) {
dev_err(dev, "Failed to disable regulator\n");
regmap_update_bits(haptics->regmap,
DRV260X_MODE,
DRV260X_STANDBY_MASK, 0);
}
}
out:
mutex_unlock(&haptics->input_dev->mutex);
return ret;
}
static int __maybe_unused drv260x_resume(struct device *dev)
{
struct drv260x_data *haptics = dev_get_drvdata(dev);
int ret = 0;
mutex_lock(&haptics->input_dev->mutex);
if (haptics->input_dev->users) {
ret = regulator_enable(haptics->regulator);
if (ret) {
dev_err(dev, "Failed to enable regulator\n");
goto out;
}
ret = regmap_update_bits(haptics->regmap,
DRV260X_MODE,
DRV260X_STANDBY_MASK, 0);
if (ret) {
dev_err(dev, "Failed to unset standby mode\n");
regulator_disable(haptics->regulator);
goto out;
}
gpiod_set_value(haptics->enable_gpio, 1);
}
out:
mutex_unlock(&haptics->input_dev->mutex);
return ret;
}
