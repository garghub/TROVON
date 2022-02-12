static inline int pca95xx_num_input_regs(int bits)
{
return (bits + 7) / 8;
}
static inline int pca95xx_num_led_regs(int bits)
{
return (bits + 3) / 4;
}
static inline u8 pca955x_ledsel(u8 oldval, int led_num, int state)
{
return (oldval & (~(0x3 << (led_num << 1)))) |
((state & 0x3) << (led_num << 1));
}
static int pca955x_write_psc(struct i2c_client *client, int n, u8 val)
{
struct pca955x *pca955x = i2c_get_clientdata(client);
int ret;
ret = i2c_smbus_write_byte_data(client,
pca95xx_num_input_regs(pca955x->chipdef->bits) + 2*n,
val);
if (ret < 0)
dev_err(&client->dev, "%s: reg 0x%x, val 0x%x, err %d\n",
__func__, n, val, ret);
return ret;
}
static int pca955x_write_pwm(struct i2c_client *client, int n, u8 val)
{
struct pca955x *pca955x = i2c_get_clientdata(client);
int ret;
ret = i2c_smbus_write_byte_data(client,
pca95xx_num_input_regs(pca955x->chipdef->bits) + 1 + 2*n,
val);
if (ret < 0)
dev_err(&client->dev, "%s: reg 0x%x, val 0x%x, err %d\n",
__func__, n, val, ret);
return ret;
}
static int pca955x_write_ls(struct i2c_client *client, int n, u8 val)
{
struct pca955x *pca955x = i2c_get_clientdata(client);
int ret;
ret = i2c_smbus_write_byte_data(client,
pca95xx_num_input_regs(pca955x->chipdef->bits) + 4 + n,
val);
if (ret < 0)
dev_err(&client->dev, "%s: reg 0x%x, val 0x%x, err %d\n",
__func__, n, val, ret);
return ret;
}
static int pca955x_read_ls(struct i2c_client *client, int n, u8 *val)
{
struct pca955x *pca955x = i2c_get_clientdata(client);
int ret;
ret = i2c_smbus_read_byte_data(client,
pca95xx_num_input_regs(pca955x->chipdef->bits) + 4 + n);
if (ret < 0) {
dev_err(&client->dev, "%s: reg 0x%x, err %d\n",
__func__, n, ret);
return ret;
}
*val = (u8)ret;
return 0;
}
static int pca955x_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct pca955x_led *pca955x_led;
struct pca955x *pca955x;
u8 ls;
int chip_ls;
int ls_led;
int ret;
pca955x_led = container_of(led_cdev, struct pca955x_led, led_cdev);
pca955x = pca955x_led->pca955x;
chip_ls = pca955x_led->led_num / 4;
ls_led = pca955x_led->led_num % 4;
mutex_lock(&pca955x->lock);
ret = pca955x_read_ls(pca955x->client, chip_ls, &ls);
if (ret)
goto out;
switch (value) {
case LED_FULL:
ls = pca955x_ledsel(ls, ls_led, PCA955X_LS_LED_ON);
break;
case LED_OFF:
ls = pca955x_ledsel(ls, ls_led, PCA955X_LS_LED_OFF);
break;
case LED_HALF:
ls = pca955x_ledsel(ls, ls_led, PCA955X_LS_BLINK0);
break;
default:
ret = pca955x_write_pwm(pca955x->client, 1, 255 - value);
if (ret)
goto out;
ls = pca955x_ledsel(ls, ls_led, PCA955X_LS_BLINK1);
break;
}
ret = pca955x_write_ls(pca955x->client, chip_ls, ls);
out:
mutex_unlock(&pca955x->lock);
return ret;
}
static int pca955x_read_input(struct i2c_client *client, int n, u8 *val)
{
int ret = i2c_smbus_read_byte_data(client, n);
if (ret < 0) {
dev_err(&client->dev, "%s: reg 0x%x, err %d\n",
__func__, n, ret);
return ret;
}
*val = (u8)ret;
return 0;
}
static int pca955x_gpio_request_pin(struct gpio_chip *gc, unsigned int offset)
{
struct pca955x *pca955x = gpiochip_get_data(gc);
struct pca955x_led *led = &pca955x->leds[offset];
if (led->type == PCA955X_TYPE_GPIO)
return 0;
return -EBUSY;
}
static int pca955x_set_value(struct gpio_chip *gc, unsigned int offset,
int val)
{
struct pca955x *pca955x = gpiochip_get_data(gc);
struct pca955x_led *led = &pca955x->leds[offset];
if (val)
return pca955x_led_set(&led->led_cdev, LED_FULL);
else
return pca955x_led_set(&led->led_cdev, LED_OFF);
}
static void pca955x_gpio_set_value(struct gpio_chip *gc, unsigned int offset,
int val)
{
pca955x_set_value(gc, offset, val);
}
static int pca955x_gpio_get_value(struct gpio_chip *gc, unsigned int offset)
{
struct pca955x *pca955x = gpiochip_get_data(gc);
struct pca955x_led *led = &pca955x->leds[offset];
u8 reg = 0;
pca955x_read_input(pca955x->client, led->led_num / 8, &reg);
return !!(reg & (1 << (led->led_num % 8)));
}
static int pca955x_gpio_direction_input(struct gpio_chip *gc,
unsigned int offset)
{
return pca955x_set_value(gc, offset, 0);
}
static int pca955x_gpio_direction_output(struct gpio_chip *gc,
unsigned int offset, int val)
{
return pca955x_set_value(gc, offset, val);
}
static struct pca955x_platform_data *
pca955x_pdata_of_init(struct i2c_client *client, struct pca955x_chipdef *chip)
{
struct device_node *np = client->dev.of_node;
struct device_node *child;
struct pca955x_platform_data *pdata;
int count;
count = of_get_child_count(np);
if (!count || count > chip->bits)
return ERR_PTR(-ENODEV);
pdata = devm_kzalloc(&client->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
pdata->leds = devm_kzalloc(&client->dev,
sizeof(struct pca955x_led) * chip->bits,
GFP_KERNEL);
if (!pdata->leds)
return ERR_PTR(-ENOMEM);
for_each_child_of_node(np, child) {
const char *name;
u32 reg;
int res;
res = of_property_read_u32(child, "reg", &reg);
if ((res != 0) || (reg >= chip->bits))
continue;
if (of_property_read_string(child, "label", &name))
name = child->name;
snprintf(pdata->leds[reg].name, sizeof(pdata->leds[reg].name),
"%s", name);
pdata->leds[reg].type = PCA955X_TYPE_LED;
of_property_read_u32(child, "type", &pdata->leds[reg].type);
of_property_read_string(child, "linux,default-trigger",
&pdata->leds[reg].default_trigger);
}
pdata->num_leds = chip->bits;
return pdata;
}
static struct pca955x_platform_data *
pca955x_pdata_of_init(struct i2c_client *client, struct pca955x_chipdef *chip)
{
return ERR_PTR(-ENODEV);
}
static int pca955x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pca955x *pca955x;
struct pca955x_led *pca955x_led;
struct pca955x_chipdef *chip;
struct i2c_adapter *adapter;
int i, err;
struct pca955x_platform_data *pdata;
int ngpios = 0;
if (id) {
chip = &pca955x_chipdefs[id->driver_data];
} else {
const struct acpi_device_id *acpi_id;
acpi_id = acpi_match_device(pca955x_acpi_ids, &client->dev);
if (!acpi_id)
return -ENODEV;
chip = &pca955x_chipdefs[acpi_id->driver_data];
}
adapter = to_i2c_adapter(client->dev.parent);
pdata = dev_get_platdata(&client->dev);
if (!pdata) {
pdata = pca955x_pdata_of_init(client, chip);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
}
if ((client->addr & ~((1 << chip->slv_addr_shift) - 1)) !=
chip->slv_addr) {
dev_err(&client->dev, "invalid slave address %02x\n",
client->addr);
return -ENODEV;
}
dev_info(&client->dev, "leds-pca955x: Using %s %d-bit LED driver at "
"slave address 0x%02x\n",
client->name, chip->bits, client->addr);
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
if (pdata->num_leds != chip->bits) {
dev_err(&client->dev,
"board info claims %d LEDs on a %d-bit chip\n",
pdata->num_leds, chip->bits);
return -ENODEV;
}
pca955x = devm_kzalloc(&client->dev, sizeof(*pca955x), GFP_KERNEL);
if (!pca955x)
return -ENOMEM;
pca955x->leds = devm_kzalloc(&client->dev,
sizeof(*pca955x_led) * chip->bits, GFP_KERNEL);
if (!pca955x->leds)
return -ENOMEM;
i2c_set_clientdata(client, pca955x);
mutex_init(&pca955x->lock);
pca955x->client = client;
pca955x->chipdef = chip;
for (i = 0; i < chip->bits; i++) {
pca955x_led = &pca955x->leds[i];
pca955x_led->led_num = i;
pca955x_led->pca955x = pca955x;
pca955x_led->type = pdata->leds[i].type;
switch (pca955x_led->type) {
case PCA955X_TYPE_NONE:
break;
case PCA955X_TYPE_GPIO:
ngpios++;
break;
case PCA955X_TYPE_LED:
if (pdata->leds[i].name[0] == '\0')
snprintf(pdata->leds[i].name,
sizeof(pdata->leds[i].name), "%d", i);
snprintf(pca955x_led->name,
sizeof(pca955x_led->name), "pca955x:%s",
pdata->leds[i].name);
if (pdata->leds[i].default_trigger)
pca955x_led->led_cdev.default_trigger =
pdata->leds[i].default_trigger;
pca955x_led->led_cdev.name = pca955x_led->name;
pca955x_led->led_cdev.brightness_set_blocking =
pca955x_led_set;
err = devm_led_classdev_register(&client->dev,
&pca955x_led->led_cdev);
if (err)
return err;
err = pca955x_led_set(&pca955x_led->led_cdev, LED_OFF);
if (err)
return err;
}
}
err = pca955x_write_pwm(client, 0, 255 - LED_HALF);
if (err)
return err;
err = pca955x_write_pwm(client, 1, 0);
if (err)
return err;
err = pca955x_write_psc(client, 0, 0);
if (err)
return err;
err = pca955x_write_psc(client, 1, 0);
if (err)
return err;
#ifdef CONFIG_LEDS_PCA955X_GPIO
if (ngpios) {
pca955x->gpio.label = "gpio-pca955x";
pca955x->gpio.direction_input = pca955x_gpio_direction_input;
pca955x->gpio.direction_output = pca955x_gpio_direction_output;
pca955x->gpio.set = pca955x_gpio_set_value;
pca955x->gpio.get = pca955x_gpio_get_value;
pca955x->gpio.request = pca955x_gpio_request_pin;
pca955x->gpio.can_sleep = 1;
pca955x->gpio.base = -1;
pca955x->gpio.ngpio = ngpios;
pca955x->gpio.parent = &client->dev;
pca955x->gpio.owner = THIS_MODULE;
err = devm_gpiochip_add_data(&client->dev, &pca955x->gpio,
pca955x);
if (err) {
pca955x->gpio.parent = NULL;
dev_warn(&client->dev, "could not add gpiochip\n");
return err;
}
dev_info(&client->dev, "gpios %i...%i\n",
pca955x->gpio.base, pca955x->gpio.base +
pca955x->gpio.ngpio - 1);
}
#endif
return 0;
}
