static int adp8860_read(struct i2c_client *client, int reg, uint8_t *val)
{
int ret;
ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0) {
dev_err(&client->dev, "failed reading at 0x%02x\n", reg);
return ret;
}
*val = (uint8_t)ret;
return 0;
}
static int adp8860_write(struct i2c_client *client, u8 reg, u8 val)
{
return i2c_smbus_write_byte_data(client, reg, val);
}
static int adp8860_set_bits(struct i2c_client *client, int reg, uint8_t bit_mask)
{
struct adp8860_bl *data = i2c_get_clientdata(client);
uint8_t reg_val;
int ret;
mutex_lock(&data->lock);
ret = adp8860_read(client, reg, &reg_val);
if (!ret && ((reg_val & bit_mask) != bit_mask)) {
reg_val |= bit_mask;
ret = adp8860_write(client, reg, reg_val);
}
mutex_unlock(&data->lock);
return ret;
}
static int adp8860_clr_bits(struct i2c_client *client, int reg, uint8_t bit_mask)
{
struct adp8860_bl *data = i2c_get_clientdata(client);
uint8_t reg_val;
int ret;
mutex_lock(&data->lock);
ret = adp8860_read(client, reg, &reg_val);
if (!ret && (reg_val & bit_mask)) {
reg_val &= ~bit_mask;
ret = adp8860_write(client, reg, reg_val);
}
mutex_unlock(&data->lock);
return ret;
}
static void adp8860_led_work(struct work_struct *work)
{
struct adp8860_led *led = container_of(work, struct adp8860_led, work);
adp8860_write(led->client, ADP8860_ISC1 - led->id + 1,
led->new_brightness >> 1);
}
static void adp8860_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct adp8860_led *led;
led = container_of(led_cdev, struct adp8860_led, cdev);
led->new_brightness = value;
schedule_work(&led->work);
}
static int adp8860_led_setup(struct adp8860_led *led)
{
struct i2c_client *client = led->client;
int ret = 0;
ret = adp8860_write(client, ADP8860_ISC1 - led->id + 1, 0);
ret |= adp8860_set_bits(client, ADP8860_ISCC, 1 << (led->id - 1));
if (led->id > 4)
ret |= adp8860_set_bits(client, ADP8860_ISCT1,
(led->flags & 0x3) << ((led->id - 5) * 2));
else
ret |= adp8860_set_bits(client, ADP8860_ISCT2,
(led->flags & 0x3) << ((led->id - 1) * 2));
return ret;
}
static int adp8860_led_probe(struct i2c_client *client)
{
struct adp8860_backlight_platform_data *pdata =
client->dev.platform_data;
struct adp8860_bl *data = i2c_get_clientdata(client);
struct adp8860_led *led, *led_dat;
struct led_info *cur_led;
int ret, i;
led = devm_kzalloc(&client->dev, sizeof(*led) * pdata->num_leds,
GFP_KERNEL);
if (led == NULL) {
dev_err(&client->dev, "failed to alloc memory\n");
return -ENOMEM;
}
ret = adp8860_write(client, ADP8860_ISCFR, pdata->led_fade_law);
ret = adp8860_write(client, ADP8860_ISCT1,
(pdata->led_on_time & 0x3) << 6);
ret |= adp8860_write(client, ADP8860_ISCF,
FADE_VAL(pdata->led_fade_in, pdata->led_fade_out));
if (ret) {
dev_err(&client->dev, "failed to write\n");
return ret;
}
for (i = 0; i < pdata->num_leds; ++i) {
cur_led = &pdata->leds[i];
led_dat = &led[i];
led_dat->id = cur_led->flags & ADP8860_FLAG_LED_MASK;
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
led_dat->cdev.brightness_set = adp8860_led_set;
led_dat->cdev.brightness = LED_OFF;
led_dat->flags = cur_led->flags >> FLAG_OFFT_SHIFT;
led_dat->client = client;
led_dat->new_brightness = LED_OFF;
INIT_WORK(&led_dat->work, adp8860_led_work);
ret = led_classdev_register(&client->dev, &led_dat->cdev);
if (ret) {
dev_err(&client->dev, "failed to register LED %d\n",
led_dat->id);
goto err;
}
ret = adp8860_led_setup(led_dat);
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
static int adp8860_led_remove(struct i2c_client *client)
{
struct adp8860_backlight_platform_data *pdata =
client->dev.platform_data;
struct adp8860_bl *data = i2c_get_clientdata(client);
int i;
for (i = 0; i < pdata->num_leds; i++) {
led_classdev_unregister(&data->led[i].cdev);
cancel_work_sync(&data->led[i].work);
}
return 0;
}
static int adp8860_led_probe(struct i2c_client *client)
{
return 0;
}
static int adp8860_led_remove(struct i2c_client *client)
{
return 0;
}
static int adp8860_bl_set(struct backlight_device *bl, int brightness)
{
struct adp8860_bl *data = bl_get_data(bl);
struct i2c_client *client = data->client;
int ret = 0;
if (data->en_ambl_sens) {
if ((brightness > 0) && (brightness < ADP8860_MAX_BRIGHTNESS)) {
ret |= adp8860_clr_bits(client, ADP8860_MDCR,
CMP_AUTOEN);
ret |= adp8860_write(client, ADP8860_BLMX1, brightness);
} else {
ret |= adp8860_write(client, ADP8860_BLMX1,
data->cached_daylight_max);
ret |= adp8860_set_bits(client, ADP8860_MDCR,
CMP_AUTOEN);
}
} else
ret |= adp8860_write(client, ADP8860_BLMX1, brightness);
if (data->current_brightness && brightness == 0)
ret |= adp8860_set_bits(client,
ADP8860_MDCR, DIM_EN);
else if (data->current_brightness == 0 && brightness)
ret |= adp8860_clr_bits(client,
ADP8860_MDCR, DIM_EN);
if (!ret)
data->current_brightness = brightness;
return ret;
}
static int adp8860_bl_update_status(struct backlight_device *bl)
{
int brightness = bl->props.brightness;
if (bl->props.power != FB_BLANK_UNBLANK)
brightness = 0;
if (bl->props.fb_blank != FB_BLANK_UNBLANK)
brightness = 0;
return adp8860_bl_set(bl, brightness);
}
static int adp8860_bl_get_brightness(struct backlight_device *bl)
{
struct adp8860_bl *data = bl_get_data(bl);
return data->current_brightness;
}
static int adp8860_bl_setup(struct backlight_device *bl)
{
struct adp8860_bl *data = bl_get_data(bl);
struct i2c_client *client = data->client;
struct adp8860_backlight_platform_data *pdata = data->pdata;
int ret = 0;
ret |= adp8860_write(client, ADP8860_BLSEN, ~pdata->bl_led_assign);
ret |= adp8860_write(client, ADP8860_BLMX1, pdata->l1_daylight_max);
ret |= adp8860_write(client, ADP8860_BLDM1, pdata->l1_daylight_dim);
if (data->en_ambl_sens) {
data->cached_daylight_max = pdata->l1_daylight_max;
ret |= adp8860_write(client, ADP8860_BLMX2,
pdata->l2_office_max);
ret |= adp8860_write(client, ADP8860_BLDM2,
pdata->l2_office_dim);
ret |= adp8860_write(client, ADP8860_BLMX3,
pdata->l3_dark_max);
ret |= adp8860_write(client, ADP8860_BLDM3,
pdata->l3_dark_dim);
ret |= adp8860_write(client, ADP8860_L2_TRP, pdata->l2_trip);
ret |= adp8860_write(client, ADP8860_L2_HYS, pdata->l2_hyst);
ret |= adp8860_write(client, ADP8860_L3_TRP, pdata->l3_trip);
ret |= adp8860_write(client, ADP8860_L3_HYS, pdata->l3_hyst);
ret |= adp8860_write(client, ADP8860_CCFG, L2_EN | L3_EN |
ALS_CCFG_VAL(pdata->abml_filt));
}
ret |= adp8860_write(client, ADP8860_CFGR,
BL_CFGR_VAL(pdata->bl_fade_law, 0));
ret |= adp8860_write(client, ADP8860_BLFR, FADE_VAL(pdata->bl_fade_in,
pdata->bl_fade_out));
ret |= adp8860_set_bits(client, ADP8860_MDCR, BLEN | DIM_EN | NSTBY |
(data->gdwn_dis ? GDWN_DIS : 0));
return ret;
}
static ssize_t adp8860_show(struct device *dev, char *buf, int reg)
{
struct adp8860_bl *data = dev_get_drvdata(dev);
int error;
uint8_t reg_val;
mutex_lock(&data->lock);
error = adp8860_read(data->client, reg, &reg_val);
mutex_unlock(&data->lock);
if (error < 0)
return error;
return sprintf(buf, "%u\n", reg_val);
}
static ssize_t adp8860_store(struct device *dev, const char *buf,
size_t count, int reg)
{
struct adp8860_bl *data = dev_get_drvdata(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&data->lock);
adp8860_write(data->client, reg, val);
mutex_unlock(&data->lock);
return count;
}
static ssize_t adp8860_bl_l3_dark_max_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8860_show(dev, buf, ADP8860_BLMX3);
}
static ssize_t adp8860_bl_l3_dark_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return adp8860_store(dev, buf, count, ADP8860_BLMX3);
}
static ssize_t adp8860_bl_l2_office_max_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8860_show(dev, buf, ADP8860_BLMX2);
}
static ssize_t adp8860_bl_l2_office_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return adp8860_store(dev, buf, count, ADP8860_BLMX2);
}
static ssize_t adp8860_bl_l1_daylight_max_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8860_show(dev, buf, ADP8860_BLMX1);
}
static ssize_t adp8860_bl_l1_daylight_max_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct adp8860_bl *data = dev_get_drvdata(dev);
int ret = kstrtoul(buf, 10, &data->cached_daylight_max);
if (ret)
return ret;
return adp8860_store(dev, buf, count, ADP8860_BLMX1);
}
static ssize_t adp8860_bl_l3_dark_dim_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8860_show(dev, buf, ADP8860_BLDM3);
}
static ssize_t adp8860_bl_l3_dark_dim_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return adp8860_store(dev, buf, count, ADP8860_BLDM3);
}
static ssize_t adp8860_bl_l2_office_dim_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8860_show(dev, buf, ADP8860_BLDM2);
}
static ssize_t adp8860_bl_l2_office_dim_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return adp8860_store(dev, buf, count, ADP8860_BLDM2);
}
static ssize_t adp8860_bl_l1_daylight_dim_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return adp8860_show(dev, buf, ADP8860_BLDM1);
}
static ssize_t adp8860_bl_l1_daylight_dim_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return adp8860_store(dev, buf, count, ADP8860_BLDM1);
}
static ssize_t adp8860_bl_ambient_light_level_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adp8860_bl *data = dev_get_drvdata(dev);
int error;
uint8_t reg_val;
uint16_t ret_val;
mutex_lock(&data->lock);
error = adp8860_read(data->client, ADP8860_PH1LEVL, &reg_val);
ret_val = reg_val;
error |= adp8860_read(data->client, ADP8860_PH1LEVH, &reg_val);
mutex_unlock(&data->lock);
if (error < 0)
return error;
ret_val += (reg_val & 0x1F) << 8;
return sprintf(buf, "%u\n", ret_val);
}
static ssize_t adp8860_bl_ambient_light_zone_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adp8860_bl *data = dev_get_drvdata(dev);
int error;
uint8_t reg_val;
mutex_lock(&data->lock);
error = adp8860_read(data->client, ADP8860_CFGR, &reg_val);
mutex_unlock(&data->lock);
if (error < 0)
return error;
return sprintf(buf, "%u\n",
((reg_val >> CFGR_BLV_SHIFT) & CFGR_BLV_MASK) + 1);
}
static ssize_t adp8860_bl_ambient_light_zone_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct adp8860_bl *data = dev_get_drvdata(dev);
unsigned long val;
uint8_t reg_val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val == 0) {
adp8860_set_bits(data->client, ADP8860_MDCR, CMP_AUTOEN);
} else if ((val > 0) && (val <= 3)) {
adp8860_clr_bits(data->client, ADP8860_MDCR, CMP_AUTOEN);
mutex_lock(&data->lock);
adp8860_read(data->client, ADP8860_CFGR, &reg_val);
reg_val &= ~(CFGR_BLV_MASK << CFGR_BLV_SHIFT);
reg_val |= (val - 1) << CFGR_BLV_SHIFT;
adp8860_write(data->client, ADP8860_CFGR, reg_val);
mutex_unlock(&data->lock);
}
return count;
}
static int adp8860_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct backlight_device *bl;
struct adp8860_bl *data;
struct adp8860_backlight_platform_data *pdata =
client->dev.platform_data;
struct backlight_properties props;
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
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
ret = adp8860_read(client, ADP8860_MFDVID, &reg_val);
if (ret < 0)
return ret;
switch (ADP8860_MANID(reg_val)) {
case ADP8863_MANUFID:
data->gdwn_dis = !!pdata->gdwn_dis;
case ADP8860_MANUFID:
data->en_ambl_sens = !!pdata->en_ambl_sens;
break;
case ADP8861_MANUFID:
data->gdwn_dis = !!pdata->gdwn_dis;
break;
default:
dev_err(&client->dev, "failed to probe\n");
return -ENODEV;
}
data->revid = ADP8860_DEVID(reg_val);
data->client = client;
data->pdata = pdata;
data->id = id->driver_data;
data->current_brightness = 0;
i2c_set_clientdata(client, data);
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_RAW;
props.max_brightness = ADP8860_MAX_BRIGHTNESS;
mutex_init(&data->lock);
bl = backlight_device_register(dev_driver_string(&client->dev),
&client->dev, data, &adp8860_bl_ops, &props);
if (IS_ERR(bl)) {
dev_err(&client->dev, "failed to register backlight\n");
return PTR_ERR(bl);
}
bl->props.brightness = ADP8860_MAX_BRIGHTNESS;
data->bl = bl;
if (data->en_ambl_sens)
ret = sysfs_create_group(&bl->dev.kobj,
&adp8860_bl_attr_group);
if (ret) {
dev_err(&client->dev, "failed to register sysfs\n");
goto out1;
}
ret = adp8860_bl_setup(bl);
if (ret) {
ret = -EIO;
goto out;
}
backlight_update_status(bl);
dev_info(&client->dev, "%s Rev.%d Backlight\n",
client->name, data->revid);
if (pdata->num_leds)
adp8860_led_probe(client);
return 0;
out:
if (data->en_ambl_sens)
sysfs_remove_group(&data->bl->dev.kobj,
&adp8860_bl_attr_group);
out1:
backlight_device_unregister(bl);
return ret;
}
static int adp8860_remove(struct i2c_client *client)
{
struct adp8860_bl *data = i2c_get_clientdata(client);
adp8860_clr_bits(client, ADP8860_MDCR, NSTBY);
if (data->led)
adp8860_led_remove(client);
if (data->en_ambl_sens)
sysfs_remove_group(&data->bl->dev.kobj,
&adp8860_bl_attr_group);
backlight_device_unregister(data->bl);
return 0;
}
static int adp8860_i2c_suspend(struct i2c_client *client, pm_message_t message)
{
adp8860_clr_bits(client, ADP8860_MDCR, NSTBY);
return 0;
}
static int adp8860_i2c_resume(struct i2c_client *client)
{
adp8860_set_bits(client, ADP8860_MDCR, NSTBY);
return 0;
}
