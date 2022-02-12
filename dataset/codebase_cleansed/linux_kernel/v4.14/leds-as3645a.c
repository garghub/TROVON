static int as3645a_write(struct as3645a *flash, u8 addr, u8 val)
{
struct i2c_client *client = flash->client;
int rval;
rval = i2c_smbus_write_byte_data(client, addr, val);
dev_dbg(&client->dev, "Write Addr:%02X Val:%02X %s\n", addr, val,
rval < 0 ? "fail" : "ok");
return rval;
}
static int as3645a_read(struct as3645a *flash, u8 addr)
{
struct i2c_client *client = flash->client;
int rval;
rval = i2c_smbus_read_byte_data(client, addr);
dev_dbg(&client->dev, "Read Addr:%02X Val:%02X %s\n", addr, rval,
rval < 0 ? "fail" : "ok");
return rval;
}
static int as3645a_set_current(struct as3645a *flash)
{
u8 val;
val = (flash->flash_current << AS_CURRENT_FLASH_CURRENT_SHIFT)
| (flash->assist_current << AS_CURRENT_ASSIST_LIGHT_SHIFT)
| AS_CURRENT_LED_DET_ON;
return as3645a_write(flash, AS_CURRENT_SET_REG, val);
}
static int as3645a_set_timeout(struct as3645a *flash)
{
u8 val;
val = flash->timeout << AS_INDICATOR_AND_TIMER_TIMEOUT_SHIFT;
val |= (flash->cfg.voltage_reference
<< AS_INDICATOR_AND_TIMER_VREF_SHIFT)
| ((flash->indicator_current ? flash->indicator_current - 1 : 0)
<< AS_INDICATOR_AND_TIMER_INDICATOR_SHIFT);
return as3645a_write(flash, AS_INDICATOR_AND_TIMER_REG, val);
}
static int
as3645a_set_control(struct as3645a *flash, enum as_mode mode, bool on)
{
u8 reg;
reg = (flash->cfg.peak << AS_CONTROL_COIL_PEAK_SHIFT)
| (on ? AS_CONTROL_OUT_ON : 0)
| mode;
if (mode == AS_MODE_FLASH &&
flash->strobe_source == V4L2_FLASH_STROBE_SOURCE_EXTERNAL)
reg |= AS_CONTROL_STROBE_TYPE_LEVEL
| AS_CONTROL_STROBE_ON;
return as3645a_write(flash, AS_CONTROL_REG, reg);
}
static int as3645a_get_fault(struct led_classdev_flash *fled, u32 *fault)
{
struct as3645a *flash = fled_to_as3645a(fled);
int rval;
rval = as3645a_read(flash, AS_FAULT_INFO_REG);
if (rval < 0)
return rval;
if (rval & AS_FAULT_INFO_INDUCTOR_PEAK_LIMIT)
*fault |= LED_FAULT_OVER_CURRENT;
if (rval & AS_FAULT_INFO_INDICATOR_LED)
*fault |= LED_FAULT_INDICATOR;
dev_dbg(&flash->client->dev, "%u connected LEDs\n",
rval & AS_FAULT_INFO_LED_AMOUNT ? 2 : 1);
if (rval & AS_FAULT_INFO_TIMEOUT)
*fault |= LED_FAULT_TIMEOUT;
if (rval & AS_FAULT_INFO_OVER_TEMPERATURE)
*fault |= LED_FAULT_OVER_TEMPERATURE;
if (rval & AS_FAULT_INFO_SHORT_CIRCUIT)
*fault |= LED_FAULT_OVER_CURRENT;
if (rval & AS_FAULT_INFO_OVER_VOLTAGE)
*fault |= LED_FAULT_INPUT_VOLTAGE;
return rval;
}
static unsigned int __as3645a_current_to_reg(unsigned int min, unsigned int max,
unsigned int step,
unsigned int val)
{
if (val < min)
val = min;
if (val > max)
val = max;
return (val - min) / step;
}
static unsigned int as3645a_current_to_reg(struct as3645a *flash, bool is_flash,
unsigned int ua)
{
if (is_flash)
return __as3645a_current_to_reg(AS_TORCH_INTENSITY_MIN,
flash->cfg.assist_max_ua,
AS_TORCH_INTENSITY_STEP, ua);
else
return __as3645a_current_to_reg(AS_FLASH_INTENSITY_MIN,
flash->cfg.flash_max_ua,
AS_FLASH_INTENSITY_STEP, ua);
}
static int as3645a_set_indicator_brightness(struct led_classdev *iled_cdev,
enum led_brightness brightness)
{
struct as3645a *flash = iled_cdev_to_as3645a(iled_cdev);
int rval;
flash->indicator_current = brightness;
rval = as3645a_set_timeout(flash);
if (rval)
return rval;
return as3645a_set_control(flash, AS_MODE_INDICATOR, brightness);
}
static int as3645a_set_assist_brightness(struct led_classdev *fled_cdev,
enum led_brightness brightness)
{
struct led_classdev_flash *fled = lcdev_to_flcdev(fled_cdev);
struct as3645a *flash = fled_to_as3645a(fled);
int rval;
if (brightness) {
flash->assist_current = brightness - 1;
rval = as3645a_set_current(flash);
if (rval)
return rval;
}
return as3645a_set_control(flash, AS_MODE_ASSIST, brightness);
}
static int as3645a_set_flash_brightness(struct led_classdev_flash *fled,
u32 brightness_ua)
{
struct as3645a *flash = fled_to_as3645a(fled);
flash->flash_current = as3645a_current_to_reg(flash, true, brightness_ua);
return as3645a_set_current(flash);
}
static int as3645a_set_flash_timeout(struct led_classdev_flash *fled,
u32 timeout_us)
{
struct as3645a *flash = fled_to_as3645a(fled);
flash->timeout = AS_TIMER_US_TO_CODE(timeout_us);
return as3645a_set_timeout(flash);
}
static int as3645a_set_strobe(struct led_classdev_flash *fled, bool state)
{
struct as3645a *flash = fled_to_as3645a(fled);
return as3645a_set_control(flash, AS_MODE_FLASH, state);
}
static int as3645a_setup(struct as3645a *flash)
{
struct device *dev = &flash->client->dev;
u32 fault = 0;
int rval;
rval = as3645a_read(flash, AS_FAULT_INFO_REG);
if (rval < 0)
return rval;
dev_dbg(dev, "Fault info: %02x\n", rval);
rval = as3645a_set_current(flash);
if (rval < 0)
return rval;
rval = as3645a_set_timeout(flash);
if (rval < 0)
return rval;
rval = as3645a_set_control(flash, AS_MODE_INDICATOR, false);
if (rval < 0)
return rval;
rval = as3645a_get_fault(&flash->fled, &fault);
if (rval < 0)
return rval;
dev_dbg(dev, "AS_INDICATOR_AND_TIMER_REG: %02x\n",
as3645a_read(flash, AS_INDICATOR_AND_TIMER_REG));
dev_dbg(dev, "AS_CURRENT_SET_REG: %02x\n",
as3645a_read(flash, AS_CURRENT_SET_REG));
dev_dbg(dev, "AS_CONTROL_REG: %02x\n",
as3645a_read(flash, AS_CONTROL_REG));
return rval & ~AS_FAULT_INFO_LED_AMOUNT ? -EIO : 0;
}
static int as3645a_detect(struct as3645a *flash)
{
struct device *dev = &flash->client->dev;
int rval, man, model, rfu, version;
const char *vendor;
rval = as3645a_read(flash, AS_DESIGN_INFO_REG);
if (rval < 0) {
dev_err(dev, "can't read design info reg\n");
return rval;
}
man = AS_DESIGN_INFO_FACTORY(rval);
model = AS_DESIGN_INFO_MODEL(rval);
rval = as3645a_read(flash, AS_VERSION_CONTROL_REG);
if (rval < 0) {
dev_err(dev, "can't read version control reg\n");
return rval;
}
rfu = AS_VERSION_CONTROL_RFU(rval);
version = AS_VERSION_CONTROL_VERSION(rval);
if (model != 0x01 || rfu != 0x00) {
dev_err(dev, "AS3645A not detected "
"(model %d rfu %d)\n", model, rfu);
return -ENODEV;
}
switch (man) {
case 1:
vendor = "AMS, Austria Micro Systems";
break;
case 2:
vendor = "ADI, Analog Devices Inc.";
break;
case 3:
vendor = "NSC, National Semiconductor";
break;
case 4:
vendor = "NXP";
break;
case 5:
vendor = "TI, Texas Instrument";
break;
default:
vendor = "Unknown";
}
dev_info(dev, "Chip vendor: %s (%d) Version: %d\n", vendor,
man, version);
rval = as3645a_write(flash, AS_PASSWORD_REG, AS_PASSWORD_UNLOCK_VALUE);
if (rval < 0)
return rval;
return as3645a_write(flash, AS_BOOST_REG, AS_BOOST_CURRENT_DISABLE);
}
static int as3645a_parse_node(struct as3645a *flash,
struct as3645a_names *names,
struct device_node *node)
{
struct as3645a_config *cfg = &flash->cfg;
struct device_node *child;
const char *name;
int rval;
for_each_child_of_node(node, child) {
u32 id = 0;
of_property_read_u32(child, "reg", &id);
switch (id) {
case AS_LED_FLASH:
flash->flash_node = of_node_get(child);
break;
case AS_LED_INDICATOR:
flash->indicator_node = of_node_get(child);
break;
default:
dev_warn(&flash->client->dev,
"unknown LED %u encountered, ignoring\n", id);
break;
}
}
if (!flash->flash_node) {
dev_err(&flash->client->dev, "can't find flash node\n");
return -ENODEV;
}
rval = of_property_read_string(flash->flash_node, "label", &name);
if (!rval)
strlcpy(names->flash, name, sizeof(names->flash));
else
snprintf(names->flash, sizeof(names->flash),
"%s:flash", node->name);
rval = of_property_read_u32(flash->flash_node, "flash-timeout-us",
&cfg->flash_timeout_us);
if (rval < 0) {
dev_err(&flash->client->dev,
"can't read flash-timeout-us property for flash\n");
goto out_err;
}
rval = of_property_read_u32(flash->flash_node, "flash-max-microamp",
&cfg->flash_max_ua);
if (rval < 0) {
dev_err(&flash->client->dev,
"can't read flash-max-microamp property for flash\n");
goto out_err;
}
rval = of_property_read_u32(flash->flash_node, "led-max-microamp",
&cfg->assist_max_ua);
if (rval < 0) {
dev_err(&flash->client->dev,
"can't read led-max-microamp property for flash\n");
goto out_err;
}
of_property_read_u32(flash->flash_node, "voltage-reference",
&cfg->voltage_reference);
of_property_read_u32(flash->flash_node, "ams,input-max-microamp",
&cfg->peak);
cfg->peak = AS_PEAK_mA_TO_REG(cfg->peak);
if (!flash->indicator_node) {
dev_warn(&flash->client->dev,
"can't find indicator node\n");
goto out_err;
}
rval = of_property_read_string(flash->indicator_node, "label", &name);
if (!rval)
strlcpy(names->indicator, name, sizeof(names->indicator));
else
snprintf(names->indicator, sizeof(names->indicator),
"%s:indicator", node->name);
rval = of_property_read_u32(flash->indicator_node, "led-max-microamp",
&cfg->indicator_max_ua);
if (rval < 0) {
dev_err(&flash->client->dev,
"can't read led-max-microamp property for indicator\n");
goto out_err;
}
return 0;
out_err:
of_node_put(flash->flash_node);
of_node_put(flash->indicator_node);
return rval;
}
static int as3645a_led_class_setup(struct as3645a *flash,
struct as3645a_names *names)
{
struct led_classdev *fled_cdev = &flash->fled.led_cdev;
struct led_classdev *iled_cdev = &flash->iled_cdev;
struct led_flash_setting *cfg;
int rval;
iled_cdev->name = names->indicator;
iled_cdev->brightness_set_blocking = as3645a_set_indicator_brightness;
iled_cdev->max_brightness =
flash->cfg.indicator_max_ua / AS_INDICATOR_INTENSITY_STEP;
iled_cdev->flags = LED_CORE_SUSPENDRESUME;
rval = led_classdev_register(&flash->client->dev, iled_cdev);
if (rval < 0)
return rval;
cfg = &flash->fled.brightness;
cfg->min = AS_FLASH_INTENSITY_MIN;
cfg->max = flash->cfg.flash_max_ua;
cfg->step = AS_FLASH_INTENSITY_STEP;
cfg->val = flash->cfg.flash_max_ua;
cfg = &flash->fled.timeout;
cfg->min = AS_FLASH_TIMEOUT_MIN;
cfg->max = flash->cfg.flash_timeout_us;
cfg->step = AS_FLASH_TIMEOUT_STEP;
cfg->val = flash->cfg.flash_timeout_us;
flash->fled.ops = &as3645a_led_flash_ops;
fled_cdev->name = names->flash;
fled_cdev->brightness_set_blocking = as3645a_set_assist_brightness;
fled_cdev->max_brightness =
as3645a_current_to_reg(flash, false,
flash->cfg.assist_max_ua) + 1;
fled_cdev->flags = LED_DEV_CAP_FLASH | LED_CORE_SUSPENDRESUME;
rval = led_classdev_flash_register(&flash->client->dev, &flash->fled);
if (rval) {
led_classdev_unregister(iled_cdev);
dev_err(&flash->client->dev,
"led_classdev_flash_register() failed, error %d\n",
rval);
}
return rval;
}
static int as3645a_v4l2_setup(struct as3645a *flash)
{
struct led_classdev_flash *fled = &flash->fled;
struct led_classdev *led = &fled->led_cdev;
struct v4l2_flash_config cfg = {
.intensity = {
.min = AS_TORCH_INTENSITY_MIN,
.max = flash->cfg.assist_max_ua,
.step = AS_TORCH_INTENSITY_STEP,
.val = flash->cfg.assist_max_ua,
},
};
struct v4l2_flash_config cfgind = {
.intensity = {
.min = AS_INDICATOR_INTENSITY_MIN,
.max = flash->cfg.indicator_max_ua,
.step = AS_INDICATOR_INTENSITY_STEP,
.val = flash->cfg.indicator_max_ua,
},
};
strlcpy(cfg.dev_name, led->name, sizeof(cfg.dev_name));
strlcpy(cfgind.dev_name, flash->iled_cdev.name, sizeof(cfg.dev_name));
flash->vf = v4l2_flash_init(
&flash->client->dev, of_fwnode_handle(flash->flash_node),
&flash->fled, NULL, &cfg);
if (IS_ERR(flash->vf))
return PTR_ERR(flash->vf);
flash->vfind = v4l2_flash_indicator_init(
&flash->client->dev, of_fwnode_handle(flash->indicator_node),
&flash->iled_cdev, &cfgind);
if (IS_ERR(flash->vfind)) {
v4l2_flash_release(flash->vf);
return PTR_ERR(flash->vfind);
}
return 0;
}
static int as3645a_probe(struct i2c_client *client)
{
struct as3645a_names names;
struct as3645a *flash;
int rval;
if (client->dev.of_node == NULL)
return -ENODEV;
flash = devm_kzalloc(&client->dev, sizeof(*flash), GFP_KERNEL);
if (flash == NULL)
return -ENOMEM;
flash->client = client;
rval = as3645a_parse_node(flash, &names, client->dev.of_node);
if (rval < 0)
return rval;
rval = as3645a_detect(flash);
if (rval < 0)
goto out_put_nodes;
mutex_init(&flash->mutex);
i2c_set_clientdata(client, flash);
rval = as3645a_setup(flash);
if (rval)
goto out_mutex_destroy;
rval = as3645a_led_class_setup(flash, &names);
if (rval)
goto out_mutex_destroy;
rval = as3645a_v4l2_setup(flash);
if (rval)
goto out_led_classdev_flash_unregister;
return 0;
out_led_classdev_flash_unregister:
led_classdev_flash_unregister(&flash->fled);
out_mutex_destroy:
mutex_destroy(&flash->mutex);
out_put_nodes:
of_node_put(flash->flash_node);
of_node_put(flash->indicator_node);
return rval;
}
static int as3645a_remove(struct i2c_client *client)
{
struct as3645a *flash = i2c_get_clientdata(client);
as3645a_set_control(flash, AS_MODE_EXT_TORCH, false);
v4l2_flash_release(flash->vf);
v4l2_flash_release(flash->vfind);
led_classdev_flash_unregister(&flash->fled);
led_classdev_unregister(&flash->iled_cdev);
mutex_destroy(&flash->mutex);
of_node_put(flash->flash_node);
of_node_put(flash->indicator_node);
return 0;
}
