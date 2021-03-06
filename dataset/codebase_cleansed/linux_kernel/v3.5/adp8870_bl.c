static int adp8870_read(struct i2c_client *client, int reg, uint8_t *val)
{
int ret;
ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0) {
dev_err(&client->dev, "failed reading at 0x%02x\n", reg);
return ret;
}
*val = ret;
return 0;
}
static int adp8870_write(struct i2c_client *client, u8 reg, u8 val)
{
int ret = i2c_smbus_write_byte_data(client, reg, val);
if (ret)
dev_err(&client->dev, "failed to write\n");
return ret;
}
static int adp8870_set_bits(struct i2c_client *client, int reg, uint8_t bit_mask)
{
struct adp8870_bl *data = i2c_get_clientdata(client);
uint8_t reg_val;
int ret;
mutex_lock(&data->lock);
ret = adp8870_read(client, reg, &reg_val);
if (!ret && ((reg_val & bit_mask) != bit_mask)) {
reg_val |= bit_mask;
ret = adp8870_write(client, reg, reg_val);
}
mutex_unlock(&data->lock);
return ret;
}
static int adp8870_clr_bits(struct i2c_client *client, int reg, uint8_t bit_mask)
{
struct adp8870_bl *data = i2c_get_clientdata(client);
uint8_t reg_val;
int ret;
mutex_lock(&data->lock);
ret = adp8870_read(client, reg, &reg_val);
if (!ret && (reg_val & bit_mask)) {
reg_val &= ~bit_mask;
ret = adp8870_write(client, reg, reg_val);
}
mutex_unlock(&data->lock);
return ret;
}
static void adp8870_led_work(struct work_struct *work)
{
struct adp8870_led *led = container_of(work, struct adp8870_led, work);
adp8870_write(led->client, ADP8870_ISC1 + led->id - 1,
led->new_brightness >> 1);
}
static void adp8870_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct adp8870_led *led;
led = container_of(led_cdev, struct adp8870_led, cdev);
led->new_brightness = value;
schedule_work(&led->work);
}
static int adp8870_led_setup(struct adp8870_led *led)
{
struct i2c_client *client = led->client;
int ret = 0;
ret = adp8870_write(client, ADP8870_ISC1 + led->id - 1, 0);
if (ret)
return ret;
ret = adp8870_set_bits(client, ADP8870_ISCC, 1 << (led->id - 1));
if (ret)
return ret;
if (led->id > 4)
ret = adp8870_set_bits(client, ADP8870_ISCT1,
(led->flags & 0x3) << ((led->id - 5) * 2));
else
ret = adp8870_set_bits(client, ADP8870_ISCT2,
(led->flags & 0x3) << ((led->id - 1) * 2));
return ret;
}
static int __devinit adp8870_led_probe(struct i2c_client *client)
{
struct adp8870_backlight_platform_data *pdata =
client->dev.platform_data;
struct adp8870_bl *data = i2c_get_clientdata(client);
struct adp8870_led *led, *led_dat;
struct led_info *cur_led;
int ret, i;
led = devm_kzalloc(&client->dev, pdata->num_leds * sizeof(*led),
GFP_KERNEL);
if (led == NULL) {
dev_err(&client->dev, "failed to alloc memory\n");
return -ENOMEM;
}
ret = adp8870_write(client, ADP8870_ISCLAW, pdata->led_fade_law);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_ISCT1,
(pdata->led_on_time & 0x3) << 6);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_ISCF,
FADE_VAL(pdata->led_fade_in, pdata->led_fade_out));
if (ret)
return ret;
for (i = 0; i < pdata->num_leds; ++i) {
cur_led = &pdata->leds[i];
led_dat = &led[i];
led_dat->id = cur_led->flags & ADP8870_FLAG_LED_MASK;
if (led_dat->id > 7 || led_dat->id < 1) {
dev_err(&client->dev, "Invalid LED ID %d\n",
led_dat->id);
goto err;
}
if (pdata->bl_led_assign & (1 << (led_dat->id - 1))) {
dev_err(&client->dev, "LED %d used by Backlight\n",
led_dat->id);
goto err;
}
led_dat->cdev.name = cur_led->name;
led_dat->cdev.default_trigger = cur_led->default_trigger;
led_dat->cdev.brightness_set = adp8870_led_set;
led_dat->cdev.brightness = LED_OFF;
led_dat->flags = cur_led->flags >> FLAG_OFFT_SHIFT;
led_dat->client = client;
led_dat->new_brightness = LED_OFF;
INIT_WORK(&led_dat->work, adp8870_led_work);
ret = led_classdev_register(&client->dev, &led_dat->cdev);
if (ret) {
dev_err(&client->dev, "failed to register LED %d\n",
led_dat->id);
goto err;
}
ret = adp8870_led_setup(led_dat);
if (ret) {
dev_err(&client->dev, "failed to write\n");
i++;
goto err;
}
}
data->led = led;
return 0;
err:
for (i = i - 1; i >= 0; --i) {
led_classdev_unregister(&led[i].cdev);
cancel_work_sync(&led[i].work);
}
return ret;
}
static int __devexit adp8870_led_remove(struct i2c_client *client)
{
struct adp8870_backlight_platform_data *pdata =
client->dev.platform_data;
struct adp8870_bl *data = i2c_get_clientdata(client);
int i;
for (i = 0; i < pdata->num_leds; i++) {
led_classdev_unregister(&data->led[i].cdev);
cancel_work_sync(&data->led[i].work);
}
return 0;
}
static int __devinit adp8870_led_probe(struct i2c_client *client)
{
return 0;
}
static int __devexit adp8870_led_remove(struct i2c_client *client)
{
return 0;
}
static int adp8870_bl_set(struct backlight_device *bl, int brightness)
{
struct adp8870_bl *data = bl_get_data(bl);
struct i2c_client *client = data->client;
int ret = 0;
if (data->pdata->en_ambl_sens) {
if ((brightness > 0) && (brightness < ADP8870_MAX_BRIGHTNESS)) {
ret = adp8870_clr_bits(client, ADP8870_MDCR,
CMP_AUTOEN);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLMX1, brightness);
if (ret)
return ret;
} else {
ret = adp8870_write(client, ADP8870_BLMX1,
data->cached_daylight_max);
if (ret)
return ret;
ret = adp8870_set_bits(client, ADP8870_MDCR,
CMP_AUTOEN);
if (ret)
return ret;
}
} else {
ret = adp8870_write(client, ADP8870_BLMX1, brightness);
if (ret)
return ret;
}
if (data->current_brightness && brightness == 0)
ret = adp8870_set_bits(client,
ADP8870_MDCR, DIM_EN);
else if (data->current_brightness == 0 && brightness)
ret = adp8870_clr_bits(client,
ADP8870_MDCR, DIM_EN);
if (!ret)
data->current_brightness = brightness;
return ret;
}
static int adp8870_bl_update_status(struct backlight_device *bl)
{
int brightness = bl->props.brightness;
if (bl->props.power != FB_BLANK_UNBLANK)
brightness = 0;
if (bl->props.fb_blank != FB_BLANK_UNBLANK)
brightness = 0;
return adp8870_bl_set(bl, brightness);
}
static int adp8870_bl_get_brightness(struct backlight_device *bl)
{
struct adp8870_bl *data = bl_get_data(bl);
return data->current_brightness;
}
static int adp8870_bl_setup(struct backlight_device *bl)
{
struct adp8870_bl *data = bl_get_data(bl);
struct i2c_client *client = data->client;
struct adp8870_backlight_platform_data *pdata = data->pdata;
int ret = 0;
ret = adp8870_write(client, ADP8870_BLSEL, ~pdata->bl_led_assign);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_PWMLED, pdata->pwm_assign);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLMX1, pdata->l1_daylight_max);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLDM1, pdata->l1_daylight_dim);
if (ret)
return ret;
if (pdata->en_ambl_sens) {
data->cached_daylight_max = pdata->l1_daylight_max;
ret = adp8870_write(client, ADP8870_BLMX2,
pdata->l2_bright_max);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLDM2,
pdata->l2_bright_dim);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLMX3,
pdata->l3_office_max);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLDM3,
pdata->l3_office_dim);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLMX4,
pdata->l4_indoor_max);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLDM4,
pdata->l4_indor_dim);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLMX5,
pdata->l5_dark_max);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLDM5,
pdata->l5_dark_dim);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_L2TRP, pdata->l2_trip);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_L2HYS, pdata->l2_hyst);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_L3TRP, pdata->l3_trip);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_L3HYS, pdata->l3_hyst);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_L4TRP, pdata->l4_trip);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_L4HYS, pdata->l4_hyst);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_L5TRP, pdata->l5_trip);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_L5HYS, pdata->l5_hyst);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_ALS1_EN, L5_EN | L4_EN |
L3_EN | L2_EN);
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_CMP_CTL,
ALS_CMPR_CFG_VAL(pdata->abml_filt));
if (ret)
return ret;
}
ret = adp8870_write(client, ADP8870_CFGR,
BL_CFGR_VAL(pdata->bl_fade_law, 0));
if (ret)
return ret;
ret = adp8870_write(client, ADP8870_BLFR, FADE_VAL(pdata->bl_fade_in,
pdata->bl_fade_out));
if (ret)
return ret;
ret = adp8870_set_bits(client, ADP8870_MDCR, BLEN | DIM_EN | NSTBY |
(data->revid == 0 ? GDWN_DIS : 0));
return ret;
}
static ssize_t adp8870_show(struct device *dev, char *buf, int reg)
{
struct adp8870_bl *data = dev_get_drvdata(dev);
int error;
uint8_t reg_val;
mutex_lock(&data->lock);
error = adp8870_read(data->client, reg, &reg_val);
mutex_unlock(&data->lock);
if (error < 0)
return error;
return sprintf(buf, "%u\n", reg_val);
}
static ssize_t adp8870_store(struct device *dev, const char *buf,
size_t count, int reg)
{
struct adp8870_bl *data = dev_get_drvdata(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&data->lock);
adp8870_write(data->client, reg, val);
mutex_unlock(&data->lock);
return count;
}
static ssize_t adp8870_bl_l5_dark_max_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLMX5);
}
static ssize_t adp8870_bl_l5_dark_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLMX5);
}
static ssize_t adp8870_bl_l4_indoor_max_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLMX4);
}
static ssize_t adp8870_bl_l4_indoor_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLMX4);
}
static ssize_t adp8870_bl_l3_office_max_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLMX3);
}
static ssize_t adp8870_bl_l3_office_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLMX3);
}
static ssize_t adp8870_bl_l2_bright_max_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLMX2);
}
static ssize_t adp8870_bl_l2_bright_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLMX2);
}
static ssize_t adp8870_bl_l1_daylight_max_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLMX1);
}
static ssize_t adp8870_bl_l1_daylight_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct adp8870_bl *data = dev_get_drvdata(dev);
int ret = kstrtoul(buf, 10, &data->cached_daylight_max);
if (ret)
return ret;
return adp8870_store(dev, buf, count, ADP8870_BLMX1);
}
static ssize_t adp8870_bl_l5_dark_dim_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLDM5);
}
static ssize_t adp8870_bl_l5_dark_dim_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLDM5);
}
static ssize_t adp8870_bl_l4_indoor_dim_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLDM4);
}
static ssize_t adp8870_bl_l4_indoor_dim_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLDM4);
}
static ssize_t adp8870_bl_l3_office_dim_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLDM3);
}
static ssize_t adp8870_bl_l3_office_dim_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLDM3);
}
static ssize_t adp8870_bl_l2_bright_dim_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLDM2);
}
static ssize_t adp8870_bl_l2_bright_dim_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLDM2);
}
static ssize_t adp8870_bl_l1_daylight_dim_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8870_show(dev, buf, ADP8870_BLDM1);
}
static ssize_t adp8870_bl_l1_daylight_dim_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return adp8870_store(dev, buf, count, ADP8870_BLDM1);
}
static ssize_t adp8870_bl_ambient_light_level_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adp8870_bl *data = dev_get_drvdata(dev);
int error;
uint8_t reg_val;
uint16_t ret_val;
mutex_lock(&data->lock);
error = adp8870_read(data->client, ADP8870_PH1LEVL, &reg_val);
if (error < 0) {
mutex_unlock(&data->lock);
return error;
}
ret_val = reg_val;
error = adp8870_read(data->client, ADP8870_PH1LEVH, &reg_val);
mutex_unlock(&data->lock);
if (error < 0)
return error;
ret_val += (reg_val & 0x1F) << 8;
return sprintf(buf, "%u\n", ret_val);
}
static ssize_t adp8870_bl_ambient_light_zone_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adp8870_bl *data = dev_get_drvdata(dev);
int error;
uint8_t reg_val;
mutex_lock(&data->lock);
error = adp8870_read(data->client, ADP8870_CFGR, &reg_val);
mutex_unlock(&data->lock);
if (error < 0)
return error;
return sprintf(buf, "%u\n",
((reg_val >> CFGR_BLV_SHIFT) & CFGR_BLV_MASK) + 1);
}
static ssize_t adp8870_bl_ambient_light_zone_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct adp8870_bl *data = dev_get_drvdata(dev);
unsigned long val;
uint8_t reg_val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val == 0) {
adp8870_set_bits(data->client, ADP8870_MDCR, CMP_AUTOEN);
} else if ((val > 0) && (val < 6)) {
adp8870_clr_bits(data->client, ADP8870_MDCR, CMP_AUTOEN);
mutex_lock(&data->lock);
adp8870_read(data->client, ADP8870_CFGR, &reg_val);
reg_val &= ~(CFGR_BLV_MASK << CFGR_BLV_SHIFT);
reg_val |= (val - 1) << CFGR_BLV_SHIFT;
adp8870_write(data->client, ADP8870_CFGR, reg_val);
mutex_unlock(&data->lock);
}
return count;
}
static int __devinit adp8870_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct backlight_properties props;
struct backlight_device *bl;
struct adp8870_bl *data;
struct adp8870_backlight_platform_data *pdata =
client->dev.platform_data;
uint8_t reg_val;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev, "SMBUS Byte Data not Supported\n");
return -EIO;
}
if (!pdata) {
dev_err(&client->dev, "no platform data?\n");
return -EINVAL;
}
ret = adp8870_read(client, ADP8870_MFDVID, &reg_val);
if (ret < 0)
return -EIO;
if (ADP8870_MANID(reg_val) != ADP8870_MANUFID) {
dev_err(&client->dev, "failed to probe\n");
return -ENODEV;
}
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
data->revid = ADP8870_DEVID(reg_val);
data->client = client;
data->pdata = pdata;
data->id = id->driver_data;
data->current_brightness = 0;
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_RAW;
props.max_brightness = props.brightness = ADP8870_MAX_BRIGHTNESS;
bl = backlight_device_register(dev_driver_string(&client->dev),
&client->dev, data, &adp8870_bl_ops, &props);
if (IS_ERR(bl)) {
dev_err(&client->dev, "failed to register backlight\n");
return PTR_ERR(bl);
}
data->bl = bl;
if (pdata->en_ambl_sens)
ret = sysfs_create_group(&bl->dev.kobj,
&adp8870_bl_attr_group);
if (ret) {
dev_err(&client->dev, "failed to register sysfs\n");
goto out1;
}
ret = adp8870_bl_setup(bl);
if (ret) {
ret = -EIO;
goto out;
}
backlight_update_status(bl);
dev_info(&client->dev, "Rev.%d Backlight\n", data->revid);
if (pdata->num_leds)
adp8870_led_probe(client);
return 0;
out:
if (data->pdata->en_ambl_sens)
sysfs_remove_group(&data->bl->dev.kobj,
&adp8870_bl_attr_group);
out1:
backlight_device_unregister(bl);
return ret;
}
static int __devexit adp8870_remove(struct i2c_client *client)
{
struct adp8870_bl *data = i2c_get_clientdata(client);
adp8870_clr_bits(client, ADP8870_MDCR, NSTBY);
if (data->led)
adp8870_led_remove(client);
if (data->pdata->en_ambl_sens)
sysfs_remove_group(&data->bl->dev.kobj,
&adp8870_bl_attr_group);
backlight_device_unregister(data->bl);
return 0;
}
static int adp8870_i2c_suspend(struct i2c_client *client, pm_message_t message)
{
adp8870_clr_bits(client, ADP8870_MDCR, NSTBY);
return 0;
}
static int adp8870_i2c_resume(struct i2c_client *client)
{
adp8870_set_bits(client, ADP8870_MDCR, NSTBY);
return 0;
}
