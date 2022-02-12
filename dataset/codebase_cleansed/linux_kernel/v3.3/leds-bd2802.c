static inline int bd2802_is_rgb_off(struct bd2802_led *led, enum led_ids id,
enum led_colors color)
{
switch (color) {
case RED:
return !led->led[id].r;
case GREEN:
return !led->led[id].g;
case BLUE:
return !led->led[id].b;
default:
dev_err(&led->client->dev, "%s: Invalid color\n", __func__);
return -EINVAL;
}
}
static inline int bd2802_is_led_off(struct bd2802_led *led, enum led_ids id)
{
if (led->led[id].r || led->led[id].g || led->led[id].b)
return 0;
return 1;
}
static inline int bd2802_is_all_off(struct bd2802_led *led)
{
int i;
for (i = 0; i < LED_NUM; i++)
if (!bd2802_is_led_off(led, i))
return 0;
return 1;
}
static inline u8 bd2802_get_base_offset(enum led_ids id, enum led_colors color)
{
return id * BD2802_LED_OFFSET + color * BD2802_COLOR_OFFSET;
}
static inline u8 bd2802_get_reg_addr(enum led_ids id, enum led_colors color,
u8 reg_offset)
{
return reg_offset + bd2802_get_base_offset(id, color);
}
static int bd2802_write_byte(struct i2c_client *client, u8 reg, u8 val)
{
int ret = i2c_smbus_write_byte_data(client, reg, val);
if (ret >= 0)
return 0;
dev_err(&client->dev, "%s: reg 0x%x, val 0x%x, err %d\n",
__func__, reg, val, ret);
return ret;
}
static void bd2802_update_state(struct bd2802_led *led, enum led_ids id,
enum led_colors color, enum led_bits led_bit)
{
int i;
u8 value;
for (i = 0; i < LED_NUM; i++) {
if (i == id) {
switch (color) {
case RED:
led->led[i].r = led_bit;
break;
case GREEN:
led->led[i].g = led_bit;
break;
case BLUE:
led->led[i].b = led_bit;
break;
default:
dev_err(&led->client->dev,
"%s: Invalid color\n", __func__);
return;
}
}
}
if (led_bit == BD2802_BLINK || led_bit == BD2802_ON)
return;
if (!bd2802_is_led_off(led, id))
return;
if (bd2802_is_all_off(led) && !led->adf_on) {
gpio_set_value(led->pdata->reset_gpio, 0);
return;
}
value = (id == LED1) ? LED_CTL(1, 0) : LED_CTL(0, 1);
bd2802_write_byte(led->client, BD2802_REG_CONTROL, value);
}
static void bd2802_configure(struct bd2802_led *led)
{
struct bd2802_led_platform_data *pdata = led->pdata;
u8 reg;
reg = bd2802_get_reg_addr(LED1, RED, BD2802_REG_HOURSETUP);
bd2802_write_byte(led->client, reg, pdata->rgb_time);
reg = bd2802_get_reg_addr(LED2, RED, BD2802_REG_HOURSETUP);
bd2802_write_byte(led->client, reg, pdata->rgb_time);
}
static void bd2802_reset_cancel(struct bd2802_led *led)
{
gpio_set_value(led->pdata->reset_gpio, 1);
udelay(100);
bd2802_configure(led);
}
static void bd2802_enable(struct bd2802_led *led, enum led_ids id)
{
enum led_ids other_led = (id == LED1) ? LED2 : LED1;
u8 value, other_led_on;
other_led_on = !bd2802_is_led_off(led, other_led);
if (id == LED1)
value = LED_CTL(other_led_on, 1);
else
value = LED_CTL(1 , other_led_on);
bd2802_write_byte(led->client, BD2802_REG_CONTROL, value);
}
static void bd2802_set_on(struct bd2802_led *led, enum led_ids id,
enum led_colors color)
{
u8 reg;
if (bd2802_is_all_off(led) && !led->adf_on)
bd2802_reset_cancel(led);
reg = bd2802_get_reg_addr(id, color, BD2802_REG_CURRENT1SETUP);
bd2802_write_byte(led->client, reg, led->rgb_current);
reg = bd2802_get_reg_addr(id, color, BD2802_REG_CURRENT2SETUP);
bd2802_write_byte(led->client, reg, BD2802_CURRENT_000);
reg = bd2802_get_reg_addr(id, color, BD2802_REG_WAVEPATTERN);
bd2802_write_byte(led->client, reg, BD2802_PATTERN_FULL);
bd2802_enable(led, id);
bd2802_update_state(led, id, color, BD2802_ON);
}
static void bd2802_set_blink(struct bd2802_led *led, enum led_ids id,
enum led_colors color)
{
u8 reg;
if (bd2802_is_all_off(led) && !led->adf_on)
bd2802_reset_cancel(led);
reg = bd2802_get_reg_addr(id, color, BD2802_REG_CURRENT1SETUP);
bd2802_write_byte(led->client, reg, BD2802_CURRENT_000);
reg = bd2802_get_reg_addr(id, color, BD2802_REG_CURRENT2SETUP);
bd2802_write_byte(led->client, reg, led->rgb_current);
reg = bd2802_get_reg_addr(id, color, BD2802_REG_WAVEPATTERN);
bd2802_write_byte(led->client, reg, led->wave_pattern);
bd2802_enable(led, id);
bd2802_update_state(led, id, color, BD2802_BLINK);
}
static void bd2802_turn_on(struct bd2802_led *led, enum led_ids id,
enum led_colors color, enum led_bits led_bit)
{
if (led_bit == BD2802_OFF) {
dev_err(&led->client->dev,
"Only 'blink' and 'on' are allowed\n");
return;
}
if (led_bit == BD2802_BLINK)
bd2802_set_blink(led, id, color);
else
bd2802_set_on(led, id, color);
}
static void bd2802_turn_off(struct bd2802_led *led, enum led_ids id,
enum led_colors color)
{
u8 reg;
if (bd2802_is_rgb_off(led, id, color))
return;
reg = bd2802_get_reg_addr(id, color, BD2802_REG_CURRENT1SETUP);
bd2802_write_byte(led->client, reg, BD2802_CURRENT_000);
reg = bd2802_get_reg_addr(id, color, BD2802_REG_CURRENT2SETUP);
bd2802_write_byte(led->client, reg, BD2802_CURRENT_000);
bd2802_update_state(led, id, color, BD2802_OFF);
}
static void bd2802_enable_adv_conf(struct bd2802_led *led)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(bd2802_addr_attributes); i++) {
ret = device_create_file(&led->client->dev,
bd2802_addr_attributes[i]);
if (ret) {
dev_err(&led->client->dev, "failed: sysfs file %s\n",
bd2802_addr_attributes[i]->attr.name);
goto failed_remove_files;
}
}
if (bd2802_is_all_off(led))
bd2802_reset_cancel(led);
led->adf_on = 1;
return;
failed_remove_files:
for (i--; i >= 0; i--)
device_remove_file(&led->client->dev,
bd2802_addr_attributes[i]);
}
static void bd2802_disable_adv_conf(struct bd2802_led *led)
{
int i;
for (i = 0; i < ARRAY_SIZE(bd2802_addr_attributes); i++)
device_remove_file(&led->client->dev,
bd2802_addr_attributes[i]);
if (bd2802_is_all_off(led))
gpio_set_value(led->pdata->reset_gpio, 0);
led->adf_on = 0;
}
static ssize_t bd2802_show_adv_conf(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bd2802_led *led = i2c_get_clientdata(to_i2c_client(dev));
ssize_t ret;
down_read(&led->rwsem);
if (led->adf_on)
ret = sprintf(buf, "on\n");
else
ret = sprintf(buf, "off\n");
up_read(&led->rwsem);
return ret;
}
static ssize_t bd2802_store_adv_conf(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct bd2802_led *led = i2c_get_clientdata(to_i2c_client(dev));
if (!count)
return -EINVAL;
down_write(&led->rwsem);
if (!led->adf_on && !strncmp(buf, "on", 2))
bd2802_enable_adv_conf(led);
else if (led->adf_on && !strncmp(buf, "off", 3))
bd2802_disable_adv_conf(led);
up_write(&led->rwsem);
return count;
}
static void bd2802_led_work(struct work_struct *work)
{
struct bd2802_led *led = container_of(work, struct bd2802_led, work);
if (led->state)
bd2802_turn_on(led, led->led_id, led->color, led->state);
else
bd2802_turn_off(led, led->led_id, led->color);
}
static int bd2802_register_led_classdev(struct bd2802_led *led)
{
int ret;
INIT_WORK(&led->work, bd2802_led_work);
led->cdev_led1r.name = "led1_R";
led->cdev_led1r.brightness = LED_OFF;
led->cdev_led1r.brightness_set = bd2802_set_led1r_brightness;
led->cdev_led1r.blink_set = bd2802_set_led1r_blink;
ret = led_classdev_register(&led->client->dev, &led->cdev_led1r);
if (ret < 0) {
dev_err(&led->client->dev, "couldn't register LED %s\n",
led->cdev_led1r.name);
goto failed_unregister_led1_R;
}
led->cdev_led1g.name = "led1_G";
led->cdev_led1g.brightness = LED_OFF;
led->cdev_led1g.brightness_set = bd2802_set_led1g_brightness;
led->cdev_led1g.blink_set = bd2802_set_led1g_blink;
ret = led_classdev_register(&led->client->dev, &led->cdev_led1g);
if (ret < 0) {
dev_err(&led->client->dev, "couldn't register LED %s\n",
led->cdev_led1g.name);
goto failed_unregister_led1_G;
}
led->cdev_led1b.name = "led1_B";
led->cdev_led1b.brightness = LED_OFF;
led->cdev_led1b.brightness_set = bd2802_set_led1b_brightness;
led->cdev_led1b.blink_set = bd2802_set_led1b_blink;
ret = led_classdev_register(&led->client->dev, &led->cdev_led1b);
if (ret < 0) {
dev_err(&led->client->dev, "couldn't register LED %s\n",
led->cdev_led1b.name);
goto failed_unregister_led1_B;
}
led->cdev_led2r.name = "led2_R";
led->cdev_led2r.brightness = LED_OFF;
led->cdev_led2r.brightness_set = bd2802_set_led2r_brightness;
led->cdev_led2r.blink_set = bd2802_set_led2r_blink;
ret = led_classdev_register(&led->client->dev, &led->cdev_led2r);
if (ret < 0) {
dev_err(&led->client->dev, "couldn't register LED %s\n",
led->cdev_led2r.name);
goto failed_unregister_led2_R;
}
led->cdev_led2g.name = "led2_G";
led->cdev_led2g.brightness = LED_OFF;
led->cdev_led2g.brightness_set = bd2802_set_led2g_brightness;
led->cdev_led2g.blink_set = bd2802_set_led2g_blink;
ret = led_classdev_register(&led->client->dev, &led->cdev_led2g);
if (ret < 0) {
dev_err(&led->client->dev, "couldn't register LED %s\n",
led->cdev_led2g.name);
goto failed_unregister_led2_G;
}
led->cdev_led2b.name = "led2_B";
led->cdev_led2b.brightness = LED_OFF;
led->cdev_led2b.brightness_set = bd2802_set_led2b_brightness;
led->cdev_led2b.blink_set = bd2802_set_led2b_blink;
led->cdev_led2b.flags |= LED_CORE_SUSPENDRESUME;
ret = led_classdev_register(&led->client->dev, &led->cdev_led2b);
if (ret < 0) {
dev_err(&led->client->dev, "couldn't register LED %s\n",
led->cdev_led2b.name);
goto failed_unregister_led2_B;
}
return 0;
failed_unregister_led2_B:
led_classdev_unregister(&led->cdev_led2g);
failed_unregister_led2_G:
led_classdev_unregister(&led->cdev_led2r);
failed_unregister_led2_R:
led_classdev_unregister(&led->cdev_led1b);
failed_unregister_led1_B:
led_classdev_unregister(&led->cdev_led1g);
failed_unregister_led1_G:
led_classdev_unregister(&led->cdev_led1r);
failed_unregister_led1_R:
return ret;
}
static void bd2802_unregister_led_classdev(struct bd2802_led *led)
{
cancel_work_sync(&led->work);
led_classdev_unregister(&led->cdev_led2b);
led_classdev_unregister(&led->cdev_led2g);
led_classdev_unregister(&led->cdev_led2r);
led_classdev_unregister(&led->cdev_led1b);
led_classdev_unregister(&led->cdev_led1g);
led_classdev_unregister(&led->cdev_led1r);
}
static int __devinit bd2802_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bd2802_led *led;
struct bd2802_led_platform_data *pdata;
int ret, i;
led = kzalloc(sizeof(struct bd2802_led), GFP_KERNEL);
if (!led) {
dev_err(&client->dev, "failed to allocate driver data\n");
return -ENOMEM;
}
led->client = client;
pdata = led->pdata = client->dev.platform_data;
i2c_set_clientdata(client, led);
gpio_request_one(pdata->reset_gpio, GPIOF_OUT_INIT_HIGH, "RGB_RESETB");
udelay(100);
ret = bd2802_write_byte(client, BD2802_REG_CLKSETUP, 0x00);
if (ret < 0) {
dev_err(&client->dev, "failed to detect device\n");
goto failed_free;
} else
dev_info(&client->dev, "return 0x%02x\n", ret);
gpio_set_value(led->pdata->reset_gpio, 0);
led->wave_pattern = BD2802_PATTERN_HALF;
led->rgb_current = BD2802_CURRENT_032;
init_rwsem(&led->rwsem);
for (i = 0; i < ARRAY_SIZE(bd2802_attributes); i++) {
ret = device_create_file(&led->client->dev,
bd2802_attributes[i]);
if (ret) {
dev_err(&led->client->dev, "failed: sysfs file %s\n",
bd2802_attributes[i]->attr.name);
goto failed_unregister_dev_file;
}
}
ret = bd2802_register_led_classdev(led);
if (ret < 0)
goto failed_unregister_dev_file;
return 0;
failed_unregister_dev_file:
for (i--; i >= 0; i--)
device_remove_file(&led->client->dev, bd2802_attributes[i]);
failed_free:
kfree(led);
return ret;
}
static int __exit bd2802_remove(struct i2c_client *client)
{
struct bd2802_led *led = i2c_get_clientdata(client);
int i;
gpio_set_value(led->pdata->reset_gpio, 0);
bd2802_unregister_led_classdev(led);
if (led->adf_on)
bd2802_disable_adv_conf(led);
for (i = 0; i < ARRAY_SIZE(bd2802_attributes); i++)
device_remove_file(&led->client->dev, bd2802_attributes[i]);
kfree(led);
return 0;
}
static void bd2802_restore_state(struct bd2802_led *led)
{
int i;
for (i = 0; i < LED_NUM; i++) {
if (led->led[i].r)
bd2802_turn_on(led, i, RED, led->led[i].r);
if (led->led[i].g)
bd2802_turn_on(led, i, GREEN, led->led[i].g);
if (led->led[i].b)
bd2802_turn_on(led, i, BLUE, led->led[i].b);
}
}
static int bd2802_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct bd2802_led *led = i2c_get_clientdata(client);
gpio_set_value(led->pdata->reset_gpio, 0);
return 0;
}
static int bd2802_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct bd2802_led *led = i2c_get_clientdata(client);
if (!bd2802_is_all_off(led) || led->adf_on) {
bd2802_reset_cancel(led);
bd2802_restore_state(led);
}
return 0;
}
