static void drv2665_worker(struct work_struct *work)
{
struct drv2665_data *haptics =
container_of(work, struct drv2665_data, work);
unsigned int read_buf;
int error;
error = regmap_read(haptics->regmap, DRV2665_STATUS, &read_buf);
if (error) {
dev_err(&haptics->client->dev,
"Failed to read status: %d\n", error);
return;
}
if (read_buf & DRV2665_FIFO_EMPTY) {
error = regmap_bulk_write(haptics->regmap,
DRV2665_FIFO,
drv2665_sine_wave_form,
ARRAY_SIZE(drv2665_sine_wave_form));
if (error) {
dev_err(&haptics->client->dev,
"Failed to write FIFO: %d\n", error);
return;
}
}
}
static int drv2665_haptics_play(struct input_dev *input, void *data,
struct ff_effect *effect)
{
struct drv2665_data *haptics = input_get_drvdata(input);
schedule_work(&haptics->work);
return 0;
}
static void drv2665_close(struct input_dev *input)
{
struct drv2665_data *haptics = input_get_drvdata(input);
int error;
cancel_work_sync(&haptics->work);
error = regmap_update_bits(haptics->regmap,
DRV2665_CTRL_2, DRV2665_STANDBY, 1);
if (error)
dev_err(&haptics->client->dev,
"Failed to enter standby mode: %d\n", error);
}
static int drv2665_init(struct drv2665_data *haptics)
{
int error;
error = regmap_register_patch(haptics->regmap,
drv2665_init_regs,
ARRAY_SIZE(drv2665_init_regs));
if (error) {
dev_err(&haptics->client->dev,
"Failed to write init registers: %d\n",
error);
return error;
}
return 0;
}
static int drv2665_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct drv2665_data *haptics;
int error;
haptics = devm_kzalloc(&client->dev, sizeof(*haptics), GFP_KERNEL);
if (!haptics)
return -ENOMEM;
haptics->regulator = devm_regulator_get(&client->dev, "vbat");
if (IS_ERR(haptics->regulator)) {
error = PTR_ERR(haptics->regulator);
dev_err(&client->dev,
"unable to get regulator, error: %d\n", error);
return error;
}
haptics->input_dev = devm_input_allocate_device(&client->dev);
if (!haptics->input_dev) {
dev_err(&client->dev, "Failed to allocate input device\n");
return -ENOMEM;
}
haptics->input_dev->name = "drv2665:haptics";
haptics->input_dev->dev.parent = client->dev.parent;
haptics->input_dev->close = drv2665_close;
input_set_drvdata(haptics->input_dev, haptics);
input_set_capability(haptics->input_dev, EV_FF, FF_RUMBLE);
error = input_ff_create_memless(haptics->input_dev, NULL,
drv2665_haptics_play);
if (error) {
dev_err(&client->dev, "input_ff_create() failed: %d\n",
error);
return error;
}
INIT_WORK(&haptics->work, drv2665_worker);
haptics->client = client;
i2c_set_clientdata(client, haptics);
haptics->regmap = devm_regmap_init_i2c(client, &drv2665_regmap_config);
if (IS_ERR(haptics->regmap)) {
error = PTR_ERR(haptics->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
error = drv2665_init(haptics);
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
static int __maybe_unused drv2665_suspend(struct device *dev)
{
struct drv2665_data *haptics = dev_get_drvdata(dev);
int ret = 0;
mutex_lock(&haptics->input_dev->mutex);
if (haptics->input_dev->users) {
ret = regmap_update_bits(haptics->regmap, DRV2665_CTRL_2,
DRV2665_STANDBY, 1);
if (ret) {
dev_err(dev, "Failed to set standby mode\n");
regulator_disable(haptics->regulator);
goto out;
}
ret = regulator_disable(haptics->regulator);
if (ret) {
dev_err(dev, "Failed to disable regulator\n");
regmap_update_bits(haptics->regmap,
DRV2665_CTRL_2,
DRV2665_STANDBY, 0);
}
}
out:
mutex_unlock(&haptics->input_dev->mutex);
return ret;
}
static int __maybe_unused drv2665_resume(struct device *dev)
{
struct drv2665_data *haptics = dev_get_drvdata(dev);
int ret = 0;
mutex_lock(&haptics->input_dev->mutex);
if (haptics->input_dev->users) {
ret = regulator_enable(haptics->regulator);
if (ret) {
dev_err(dev, "Failed to enable regulator\n");
goto out;
}
ret = regmap_update_bits(haptics->regmap, DRV2665_CTRL_2,
DRV2665_STANDBY, 0);
if (ret) {
dev_err(dev, "Failed to unset standby mode\n");
regulator_disable(haptics->regulator);
goto out;
}
}
out:
mutex_unlock(&haptics->input_dev->mutex);
return ret;
}
