static ssize_t show_color_common(struct device *dev, char *buf, int color)
{
struct i2c_client *client;
struct blinkm_data *data;
int ret;
client = to_i2c_client(dev);
data = i2c_get_clientdata(client);
ret = blinkm_transfer_hw(client, BLM_GET_CUR_RGB);
if (ret < 0)
return ret;
switch (color) {
case RED:
return scnprintf(buf, PAGE_SIZE, "%02X\n", data->red);
case GREEN:
return scnprintf(buf, PAGE_SIZE, "%02X\n", data->green);
case BLUE:
return scnprintf(buf, PAGE_SIZE, "%02X\n", data->blue);
default:
return -EINVAL;
}
return -EINVAL;
}
static int store_color_common(struct device *dev, const char *buf, int color)
{
struct i2c_client *client;
struct blinkm_data *data;
int ret;
u8 value;
client = to_i2c_client(dev);
data = i2c_get_clientdata(client);
ret = kstrtou8(buf, 10, &value);
if (ret < 0) {
dev_err(dev, "BlinkM: value too large!\n");
return ret;
}
switch (color) {
case RED:
data->next_red = value;
break;
case GREEN:
data->next_green = value;
break;
case BLUE:
data->next_blue = value;
break;
default:
return -EINVAL;
}
dev_dbg(dev, "next_red = %d, next_green = %d, next_blue = %d\n",
data->next_red, data->next_green, data->next_blue);
ret = blinkm_transfer_hw(client, BLM_GO_RGB);
if (ret < 0) {
dev_err(dev, "BlinkM: can't set RGB\n");
return ret;
}
return 0;
}
static ssize_t show_red(struct device *dev, struct device_attribute *attr,
char *buf)
{
return show_color_common(dev, buf, RED);
}
static ssize_t store_red(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
ret = store_color_common(dev, buf, RED);
if (ret < 0)
return ret;
return count;
}
static ssize_t show_green(struct device *dev, struct device_attribute *attr,
char *buf)
{
return show_color_common(dev, buf, GREEN);
}
static ssize_t store_green(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
ret = store_color_common(dev, buf, GREEN);
if (ret < 0)
return ret;
return count;
}
static ssize_t show_blue(struct device *dev, struct device_attribute *attr,
char *buf)
{
return show_color_common(dev, buf, BLUE);
}
static ssize_t store_blue(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
ret = store_color_common(dev, buf, BLUE);
if (ret < 0)
return ret;
return count;
}
static ssize_t show_test(struct device *dev, struct device_attribute *attr,
char *buf)
{
return scnprintf(buf, PAGE_SIZE,
"#Write into test to start test sequence!#\n");
}
static ssize_t store_test(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client;
int ret;
client = to_i2c_client(dev);
ret = blinkm_test_run(client);
if (ret < 0)
return ret;
return count;
}
static int blinkm_write(struct i2c_client *client, int cmd, u8 *arg)
{
int result;
int i;
int arglen = blinkm_cmds[cmd].nr_args;
result = i2c_smbus_write_byte(client, blinkm_cmds[cmd].cmdbyte);
if (result < 0)
return result;
if (arglen == 0)
return 0;
for (i = 0; i < arglen; i++) {
result = i2c_smbus_write_byte(client, arg[i]);
if (result < 0)
return result;
}
return 0;
}
static int blinkm_read(struct i2c_client *client, int cmd, u8 *arg)
{
int result;
int i;
int retlen = blinkm_cmds[cmd].nr_ret;
for (i = 0; i < retlen; i++) {
result = i2c_smbus_read_byte(client);
if (result < 0)
return result;
arg[i] = result;
}
return 0;
}
static int blinkm_transfer_hw(struct i2c_client *client, int cmd)
{
struct blinkm_data *data = i2c_get_clientdata(client);
if (mutex_lock_interruptible(&data->update_lock) < 0)
return -EAGAIN;
switch (cmd) {
case BLM_FADE_RAND_RGB:
case BLM_GO_RGB:
case BLM_FADE_RGB:
data->args[0] = data->next_red;
data->args[1] = data->next_green;
data->args[2] = data->next_blue;
blinkm_write(client, cmd, data->args);
data->red = data->args[0];
data->green = data->args[1];
data->blue = data->args[2];
break;
case BLM_FADE_HSB:
case BLM_FADE_RAND_HSB:
data->args[0] = data->next_hue;
data->args[1] = data->next_saturation;
data->args[2] = data->next_brightness;
blinkm_write(client, cmd, data->args);
data->hue = data->next_hue;
data->saturation = data->next_saturation;
data->brightness = data->next_brightness;
break;
case BLM_PLAY_SCRIPT:
data->args[0] = data->script_id;
data->args[1] = data->script_repeats;
data->args[2] = data->script_startline;
blinkm_write(client, cmd, data->args);
break;
case BLM_STOP_SCRIPT:
blinkm_write(client, cmd, NULL);
break;
case BLM_GET_CUR_RGB:
data->args[0] = data->red;
data->args[1] = data->green;
data->args[2] = data->blue;
blinkm_write(client, cmd, NULL);
blinkm_read(client, cmd, data->args);
data->red = data->args[0];
data->green = data->args[1];
data->blue = data->args[2];
break;
case BLM_GET_ADDR:
data->args[0] = data->i2c_addr;
blinkm_write(client, cmd, NULL);
blinkm_read(client, cmd, data->args);
data->i2c_addr = data->args[0];
break;
case BLM_SET_TIME_ADJ:
case BLM_SET_FADE_SPEED:
case BLM_READ_SCRIPT_LINE:
case BLM_WRITE_SCRIPT_LINE:
case BLM_SET_SCRIPT_LR:
case BLM_SET_ADDR:
case BLM_GET_FW_VER:
case BLM_SET_STARTUP_PARAM:
dev_err(&client->dev,
"BlinkM: cmd %d not implemented yet.\n", cmd);
break;
default:
dev_err(&client->dev, "BlinkM: unknown command %d\n", cmd);
mutex_unlock(&data->update_lock);
return -EINVAL;
}
mutex_unlock(&data->update_lock);
return 0;
}
static void led_work(struct work_struct *work)
{
int ret;
struct blinkm_led *led;
struct blinkm_data *data;
struct blinkm_work *blm_work = work_to_blmwork(work);
led = blm_work->blinkm_led;
data = i2c_get_clientdata(led->i2c_client);
ret = blinkm_transfer_hw(led->i2c_client, BLM_GO_RGB);
atomic_dec(&led->active);
dev_dbg(&led->i2c_client->dev,
"# DONE # next_red = %d, next_green = %d,"
" next_blue = %d, active = %d\n",
data->next_red, data->next_green,
data->next_blue, atomic_read(&led->active));
kfree(blm_work);
}
static int blinkm_led_common_set(struct led_classdev *led_cdev,
enum led_brightness value, int color)
{
struct blinkm_led *led = cdev_to_blmled(led_cdev);
struct blinkm_data *data = i2c_get_clientdata(led->i2c_client);
struct blinkm_work *bl_work;
switch (color) {
case RED:
if (data->next_red == (u8) value)
return 0;
if (atomic_read(&led->active) > 1)
return 0;
data->next_red = (u8) value;
break;
case GREEN:
if (data->next_green == (u8) value)
return 0;
if (atomic_read(&led->active) > 1)
return 0;
data->next_green = (u8) value;
break;
case BLUE:
if (data->next_blue == (u8) value)
return 0;
if (atomic_read(&led->active) > 1)
return 0;
data->next_blue = (u8) value;
break;
default:
dev_err(&led->i2c_client->dev, "BlinkM: unknown color.\n");
return -EINVAL;
}
bl_work = kzalloc(sizeof(*bl_work), GFP_ATOMIC);
if (!bl_work)
return -ENOMEM;
atomic_inc(&led->active);
dev_dbg(&led->i2c_client->dev,
"#TO_SCHED# next_red = %d, next_green = %d,"
" next_blue = %d, active = %d\n",
data->next_red, data->next_green,
data->next_blue, atomic_read(&led->active));
bl_work->blinkm_led = led;
INIT_WORK(&bl_work->work, led_work);
schedule_work(&bl_work->work);
return 0;
}
static void blinkm_led_red_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
blinkm_led_common_set(led_cdev, value, RED);
}
static void blinkm_led_green_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
blinkm_led_common_set(led_cdev, value, GREEN);
}
static void blinkm_led_blue_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
blinkm_led_common_set(led_cdev, value, BLUE);
}
static void blinkm_init_hw(struct i2c_client *client)
{
int ret;
ret = blinkm_transfer_hw(client, BLM_STOP_SCRIPT);
ret = blinkm_transfer_hw(client, BLM_GO_RGB);
}
static int blinkm_test_run(struct i2c_client *client)
{
int ret;
struct blinkm_data *data = i2c_get_clientdata(client);
data->next_red = 0x01;
data->next_green = 0x05;
data->next_blue = 0x10;
ret = blinkm_transfer_hw(client, BLM_GO_RGB);
if (ret < 0)
return ret;
msleep(2000);
data->next_red = 0x25;
data->next_green = 0x10;
data->next_blue = 0x31;
ret = blinkm_transfer_hw(client, BLM_FADE_RGB);
if (ret < 0)
return ret;
msleep(2000);
data->next_hue = 0x50;
data->next_saturation = 0x10;
data->next_brightness = 0x20;
ret = blinkm_transfer_hw(client, BLM_FADE_HSB);
if (ret < 0)
return ret;
msleep(2000);
return 0;
}
static int blinkm_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int ret;
int count = 99;
u8 tmpargs[7];
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_WORD_DATA
| I2C_FUNC_SMBUS_WRITE_BYTE))
return -ENODEV;
while (count > 0) {
ret = blinkm_write(client, BLM_GET_ADDR, NULL);
usleep_range(5000, 10000);
ret = blinkm_read(client, BLM_GET_ADDR, tmpargs);
usleep_range(5000, 10000);
if (tmpargs[0] == 0x09)
count = 0;
count--;
}
ret = blinkm_write(client, BLM_GET_ADDR, NULL);
if (ret < 0)
return ret;
usleep_range(20000, 30000);
ret = blinkm_read(client, BLM_GET_ADDR, tmpargs);
if (ret < 0)
return ret;
if (tmpargs[0] != 0x09) {
dev_err(&client->dev, "enodev DEV ADDR = 0x%02X\n", tmpargs[0]);
return -ENODEV;
}
strlcpy(info->type, "blinkm", I2C_NAME_SIZE);
return 0;
}
static int blinkm_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct blinkm_data *data;
struct blinkm_led *led[3];
int err, i;
char blinkm_led_name[28];
data = devm_kzalloc(&client->dev,
sizeof(struct blinkm_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
data->i2c_addr = 0x09;
data->i2c_addr = 0x08;
data->fw_ver = 0xfe;
data->script_id = 0x01;
data->i2c_client = client;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = sysfs_create_group(&client->dev.kobj, &blinkm_group);
if (err < 0) {
dev_err(&client->dev, "couldn't register sysfs group\n");
goto exit;
}
for (i = 0; i < 3; i++) {
led[i] = &data->blinkm_leds[i];
led[i]->i2c_client = client;
led[i]->id = i;
led[i]->led_cdev.max_brightness = 255;
led[i]->led_cdev.flags = LED_CORE_SUSPENDRESUME;
atomic_set(&led[i]->active, 0);
switch (i) {
case RED:
snprintf(blinkm_led_name, sizeof(blinkm_led_name),
"blinkm-%d-%d-red",
client->adapter->nr,
client->addr);
led[i]->led_cdev.name = blinkm_led_name;
led[i]->led_cdev.brightness_set = blinkm_led_red_set;
err = led_classdev_register(&client->dev,
&led[i]->led_cdev);
if (err < 0) {
dev_err(&client->dev,
"couldn't register LED %s\n",
led[i]->led_cdev.name);
goto failred;
}
break;
case GREEN:
snprintf(blinkm_led_name, sizeof(blinkm_led_name),
"blinkm-%d-%d-green",
client->adapter->nr,
client->addr);
led[i]->led_cdev.name = blinkm_led_name;
led[i]->led_cdev.brightness_set = blinkm_led_green_set;
err = led_classdev_register(&client->dev,
&led[i]->led_cdev);
if (err < 0) {
dev_err(&client->dev,
"couldn't register LED %s\n",
led[i]->led_cdev.name);
goto failgreen;
}
break;
case BLUE:
snprintf(blinkm_led_name, sizeof(blinkm_led_name),
"blinkm-%d-%d-blue",
client->adapter->nr,
client->addr);
led[i]->led_cdev.name = blinkm_led_name;
led[i]->led_cdev.brightness_set = blinkm_led_blue_set;
err = led_classdev_register(&client->dev,
&led[i]->led_cdev);
if (err < 0) {
dev_err(&client->dev,
"couldn't register LED %s\n",
led[i]->led_cdev.name);
goto failblue;
}
break;
}
}
blinkm_init_hw(client);
return 0;
failblue:
led_classdev_unregister(&led[GREEN]->led_cdev);
failgreen:
led_classdev_unregister(&led[RED]->led_cdev);
failred:
sysfs_remove_group(&client->dev.kobj, &blinkm_group);
exit:
return err;
}
static int blinkm_remove(struct i2c_client *client)
{
struct blinkm_data *data = i2c_get_clientdata(client);
int ret = 0;
int i;
for (i = 0; i < 3; i++) {
flush_scheduled_work();
led_classdev_unregister(&data->blinkm_leds[i].led_cdev);
}
data->next_red = 0x00;
data->next_green = 0x00;
data->next_blue = 0x00;
ret = blinkm_transfer_hw(client, BLM_FADE_RGB);
if (ret < 0)
dev_err(&client->dev, "Failure in blinkm_remove ignored. Continuing.\n");
data->next_hue = 0x00;
data->next_saturation = 0x00;
data->next_brightness = 0x00;
ret = blinkm_transfer_hw(client, BLM_FADE_HSB);
if (ret < 0)
dev_err(&client->dev, "Failure in blinkm_remove ignored. Continuing.\n");
data->next_red = 0xff;
ret = blinkm_transfer_hw(client, BLM_GO_RGB);
if (ret < 0)
dev_err(&client->dev, "Failure in blinkm_remove ignored. Continuing.\n");
data->next_red = 0x00;
ret = blinkm_transfer_hw(client, BLM_FADE_RGB);
if (ret < 0)
dev_err(&client->dev, "Failure in blinkm_remove ignored. Continuing.\n");
sysfs_remove_group(&client->dev.kobj, &blinkm_group);
return 0;
}
