static int drv2667_set_waveform_freq(struct drv2667_data *haptics)
{
unsigned int read_buf;
int freq;
int error;
freq = (haptics->frequency * 1000) / 78125;
if (freq <= 0) {
dev_err(&haptics->client->dev,
"ERROR: Frequency calculated to %i\n", freq);
return -EINVAL;
}
error = regmap_read(haptics->regmap, DRV2667_PAGE, &read_buf);
if (error) {
dev_err(&haptics->client->dev,
"Failed to read the page number: %d\n", error);
return -EIO;
}
if (read_buf == DRV2667_PAGE_0 ||
haptics->page != read_buf) {
error = regmap_write(haptics->regmap,
DRV2667_PAGE, haptics->page);
if (error) {
dev_err(&haptics->client->dev,
"Failed to set the page: %d\n", error);
return -EIO;
}
}
error = regmap_write(haptics->regmap, DRV2667_RAM_FREQ, freq);
if (error)
dev_err(&haptics->client->dev,
"Failed to set the frequency: %d\n", error);
if (read_buf == DRV2667_PAGE_0 ||
haptics->page != read_buf) {
error = regmap_write(haptics->regmap, DRV2667_PAGE, read_buf);
if (error) {
dev_err(&haptics->client->dev,
"Failed to set the page: %d\n", error);
return -EIO;
}
}
return error;
}
static void drv2667_worker(struct work_struct *work)
{
struct drv2667_data *haptics = container_of(work, struct drv2667_data, work);
int error;
if (haptics->magnitude) {
error = regmap_write(haptics->regmap,
DRV2667_PAGE, haptics->page);
if (error) {
dev_err(&haptics->client->dev,
"Failed to set the page: %d\n", error);
return;
}
error = regmap_write(haptics->regmap, DRV2667_RAM_AMP,
haptics->magnitude);
if (error) {
dev_err(&haptics->client->dev,
"Failed to set the amplitude: %d\n", error);
return;
}
error = regmap_write(haptics->regmap,
DRV2667_PAGE, DRV2667_PAGE_0);
if (error) {
dev_err(&haptics->client->dev,
"Failed to set the page: %d\n", error);
return;
}
error = regmap_write(haptics->regmap,
DRV2667_CTRL_2, DRV2667_GO);
if (error) {
dev_err(&haptics->client->dev,
"Failed to set the GO bit: %d\n", error);
}
} else {
error = regmap_update_bits(haptics->regmap, DRV2667_CTRL_2,
DRV2667_GO, 0);
if (error) {
dev_err(&haptics->client->dev,
"Failed to unset the GO bit: %d\n", error);
}
}
}
static int drv2667_haptics_play(struct input_dev *input, void *data,
struct ff_effect *effect)
{
struct drv2667_data *haptics = input_get_drvdata(input);
if (effect->u.rumble.strong_magnitude > 0)
haptics->magnitude = effect->u.rumble.strong_magnitude;
else if (effect->u.rumble.weak_magnitude > 0)
haptics->magnitude = effect->u.rumble.weak_magnitude;
else
haptics->magnitude = 0;
schedule_work(&haptics->work);
return 0;
}
static void drv2667_close(struct input_dev *input)
{
struct drv2667_data *haptics = input_get_drvdata(input);
int error;
cancel_work_sync(&haptics->work);
error = regmap_update_bits(haptics->regmap, DRV2667_CTRL_2,
DRV2667_STANDBY, 1);
if (error)
dev_err(&haptics->client->dev,
"Failed to enter standby mode: %d\n", error);
}
static int drv2667_init(struct drv2667_data *haptics)
{
int error;
haptics->frequency = 195;
haptics->page = DRV2667_PAGE_1;
error = regmap_register_patch(haptics->regmap,
drv2667_init_regs,
ARRAY_SIZE(drv2667_init_regs));
if (error) {
dev_err(&haptics->client->dev,
"Failed to write init registers: %d\n",
error);
return error;
}
error = regmap_write(haptics->regmap, DRV2667_PAGE, haptics->page);
if (error) {
dev_err(&haptics->client->dev, "Failed to set page: %d\n",
error);
goto error_out;
}
error = drv2667_set_waveform_freq(haptics);
if (error)
goto error_page;
error = regmap_register_patch(haptics->regmap,
drv2667_page1_init,
ARRAY_SIZE(drv2667_page1_init));
if (error) {
dev_err(&haptics->client->dev,
"Failed to write page registers: %d\n",
error);
return error;
}
error = regmap_write(haptics->regmap, DRV2667_PAGE, DRV2667_PAGE_0);
return error;
error_page:
regmap_write(haptics->regmap, DRV2667_PAGE, DRV2667_PAGE_0);
error_out:
return error;
}
static int drv2667_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct drv2667_data *haptics;
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
haptics->input_dev->name = "drv2667:haptics";
haptics->input_dev->dev.parent = client->dev.parent;
haptics->input_dev->close = drv2667_close;
input_set_drvdata(haptics->input_dev, haptics);
input_set_capability(haptics->input_dev, EV_FF, FF_RUMBLE);
error = input_ff_create_memless(haptics->input_dev, NULL,
drv2667_haptics_play);
if (error) {
dev_err(&client->dev, "input_ff_create() failed: %d\n",
error);
return error;
}
INIT_WORK(&haptics->work, drv2667_worker);
haptics->client = client;
i2c_set_clientdata(client, haptics);
haptics->regmap = devm_regmap_init_i2c(client, &drv2667_regmap_config);
if (IS_ERR(haptics->regmap)) {
error = PTR_ERR(haptics->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
error);
return error;
}
error = drv2667_init(haptics);
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
static int __maybe_unused drv2667_suspend(struct device *dev)
{
struct drv2667_data *haptics = dev_get_drvdata(dev);
int ret = 0;
mutex_lock(&haptics->input_dev->mutex);
if (haptics->input_dev->users) {
ret = regmap_update_bits(haptics->regmap, DRV2667_CTRL_2,
DRV2667_STANDBY, 1);
if (ret) {
dev_err(dev, "Failed to set standby mode\n");
regulator_disable(haptics->regulator);
goto out;
}
ret = regulator_disable(haptics->regulator);
if (ret) {
dev_err(dev, "Failed to disable regulator\n");
regmap_update_bits(haptics->regmap,
DRV2667_CTRL_2,
DRV2667_STANDBY, 0);
}
}
out:
mutex_unlock(&haptics->input_dev->mutex);
return ret;
}
static int __maybe_unused drv2667_resume(struct device *dev)
{
struct drv2667_data *haptics = dev_get_drvdata(dev);
int ret = 0;
mutex_lock(&haptics->input_dev->mutex);
if (haptics->input_dev->users) {
ret = regulator_enable(haptics->regulator);
if (ret) {
dev_err(dev, "Failed to enable regulator\n");
goto out;
}
ret = regmap_update_bits(haptics->regmap, DRV2667_CTRL_2,
DRV2667_STANDBY, 0);
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
