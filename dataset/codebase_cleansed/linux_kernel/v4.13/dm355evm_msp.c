int dm355evm_msp_write(u8 value, u8 reg)
{
return i2c_smbus_write_byte_data(msp430, reg, value);
}
int dm355evm_msp_read(u8 reg)
{
return i2c_smbus_read_byte_data(msp430, reg);
}
static int msp_gpio_in(struct gpio_chip *chip, unsigned offset)
{
switch (MSP_GPIO_REG(offset)) {
case DM355EVM_MSP_SWITCH1:
case DM355EVM_MSP_SWITCH2:
case DM355EVM_MSP_SDMMC:
return 0;
default:
return -EINVAL;
}
}
static int msp_gpio_get(struct gpio_chip *chip, unsigned offset)
{
int reg, status;
reg = MSP_GPIO_REG(offset);
status = dm355evm_msp_read(reg);
if (status < 0)
return status;
if (reg == DM355EVM_MSP_LED)
msp_led_cache = status;
return !!(status & MSP_GPIO_MASK(offset));
}
static int msp_gpio_out(struct gpio_chip *chip, unsigned offset, int value)
{
int mask, bits;
if (MSP_GPIO_REG(offset) != DM355EVM_MSP_LED)
return -EINVAL;
mask = MSP_GPIO_MASK(offset);
bits = msp_led_cache;
bits &= ~mask;
if (value)
bits |= mask;
msp_led_cache = bits;
return dm355evm_msp_write(bits, DM355EVM_MSP_LED);
}
static void msp_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
msp_gpio_out(chip, offset, value);
}
static struct device *add_child(struct i2c_client *client, const char *name,
void *pdata, unsigned pdata_len,
bool can_wakeup, int irq)
{
struct platform_device *pdev;
int status;
pdev = platform_device_alloc(name, -1);
if (!pdev)
return ERR_PTR(-ENOMEM);
device_init_wakeup(&pdev->dev, can_wakeup);
pdev->dev.parent = &client->dev;
if (pdata) {
status = platform_device_add_data(pdev, pdata, pdata_len);
if (status < 0) {
dev_dbg(&pdev->dev, "can't add platform_data\n");
goto put_device;
}
}
if (irq) {
struct resource r = {
.start = irq,
.flags = IORESOURCE_IRQ,
};
status = platform_device_add_resources(pdev, &r, 1);
if (status < 0) {
dev_dbg(&pdev->dev, "can't add irq\n");
goto put_device;
}
}
status = platform_device_add(pdev);
if (status)
goto put_device;
return &pdev->dev;
put_device:
platform_device_put(pdev);
dev_err(&client->dev, "failed to add device %s\n", name);
return ERR_PTR(status);
}
static int add_children(struct i2c_client *client)
{
static const struct {
int offset;
char *label;
} config_inputs[] = {
{ 8 + 0, "sw6_1", },
{ 8 + 1, "sw6_2", },
{ 8 + 2, "sw6_3", },
{ 8 + 3, "sw6_4", },
{ 8 + 4, "NTSC/nPAL", },
};
struct device *child;
int status;
int i;
dm355evm_msp_gpio.parent = &client->dev;
status = gpiochip_add_data(&dm355evm_msp_gpio, NULL);
if (status < 0)
return status;
if (msp_has_leds()) {
#define GPIO_LED(l) .name = l, .active_low = true
static struct gpio_led evm_leds[] = {
{ GPIO_LED("dm355evm::ds14"),
.default_trigger = "heartbeat", },
{ GPIO_LED("dm355evm::ds15"),
.default_trigger = "mmc0", },
{ GPIO_LED("dm355evm::ds16"),
.default_trigger = "mmc1", },
{ GPIO_LED("dm355evm::ds17"),
.default_trigger = "nand-disk", },
{ GPIO_LED("dm355evm::ds18"), },
{ GPIO_LED("dm355evm::ds19"), },
{ GPIO_LED("dm355evm::ds20"), },
{ GPIO_LED("dm355evm::ds21"), },
};
#undef GPIO_LED
struct gpio_led_platform_data evm_led_data = {
.num_leds = ARRAY_SIZE(evm_leds),
.leds = evm_leds,
};
for (i = 0; i < ARRAY_SIZE(evm_leds); i++)
evm_leds[i].gpio = i + dm355evm_msp_gpio.base;
child = add_child(client, "leds-gpio",
&evm_led_data, sizeof(evm_led_data),
false, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
for (i = 0; i < ARRAY_SIZE(config_inputs); i++) {
int gpio = dm355evm_msp_gpio.base + config_inputs[i].offset;
gpio_request_one(gpio, GPIOF_IN, config_inputs[i].label);
gpio_export(gpio, false);
}
if (dev_get_platdata(&client->dev)) {
void (*mmcsd_setup)(unsigned) = dev_get_platdata(&client->dev);
mmcsd_setup(dm355evm_msp_gpio.base + 8 + 5);
}
if (msp_has_rtc()) {
child = add_child(client, "rtc-dm355evm",
NULL, 0, false, 0);
if (IS_ERR(child))
return PTR_ERR(child);
}
if (msp_has_keyboard()) {
child = add_child(client, "dm355evm_keys",
NULL, 0, true, client->irq);
if (IS_ERR(child))
return PTR_ERR(child);
}
return 0;
}
static void dm355evm_command(unsigned command)
{
int status;
status = dm355evm_msp_write(command, DM355EVM_MSP_COMMAND);
if (status < 0)
dev_err(&msp430->dev, "command %d failure %d\n",
command, status);
}
static void dm355evm_power_off(void)
{
dm355evm_command(MSP_COMMAND_POWEROFF);
}
static int dm355evm_msp_remove(struct i2c_client *client)
{
pm_power_off = NULL;
msp430 = NULL;
return 0;
}
static int
dm355evm_msp_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
int status;
const char *video = msp_has_tvp() ? "TVP5146" : "imager";
if (msp430)
return -EBUSY;
msp430 = client;
status = dm355evm_msp_read(DM355EVM_MSP_FIRMREV);
if (status < 0)
goto fail;
dev_info(&client->dev, "firmware v.%02X, %s as video-in\n",
status, video);
status = dm355evm_msp_write(msp_has_tvp() ? 0 : MSP_VIDEO_IMAGER,
DM355EVM_MSP_VIDEO_IN);
if (status < 0)
dev_warn(&client->dev, "error %d muxing %s as video-in\n",
status, video);
msp_led_cache = 0xff;
dm355evm_msp_write(msp_led_cache, DM355EVM_MSP_LED);
status = add_children(client);
if (status < 0)
goto fail;
pm_power_off = dm355evm_power_off;
return 0;
fail:
dm355evm_msp_remove(client);
return status;
}
static int __init dm355evm_msp_init(void)
{
return i2c_add_driver(&dm355evm_msp_driver);
}
static void __exit dm355evm_msp_exit(void)
{
i2c_del_driver(&dm355evm_msp_driver);
}
