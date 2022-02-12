static int
evm_led_setup(struct i2c_client *client, int gpio, unsigned ngpio, void *c)
{
struct gpio_led *leds = evm_leds;
int status;
while (ngpio--) {
leds->gpio = gpio++;
leds++;
}
evm_led_dev = platform_device_alloc("leds-gpio", 0);
platform_device_add_data(evm_led_dev,
&evm_led_data, sizeof evm_led_data);
evm_led_dev->dev.parent = &client->dev;
status = platform_device_add(evm_led_dev);
if (status < 0) {
platform_device_put(evm_led_dev);
evm_led_dev = NULL;
}
return status;
}
static int
evm_led_teardown(struct i2c_client *client, int gpio, unsigned ngpio, void *c)
{
if (evm_led_dev) {
platform_device_unregister(evm_led_dev);
evm_led_dev = NULL;
}
return 0;
}
static ssize_t
sw_show(struct device *d, struct device_attribute *a, char *buf)
{
char *s = gpio_get_value_cansleep(sw_gpio) ? "on\n" : "off\n";
strcpy(buf, s);
return strlen(s);
}
static int
evm_u18_setup(struct i2c_client *client, int gpio, unsigned ngpio, void *c)
{
int status;
sw_gpio = gpio + 7;
status = gpio_request(sw_gpio, "user_sw");
if (status == 0)
status = gpio_direction_input(sw_gpio);
if (status == 0)
status = device_create_file(&client->dev, &dev_attr_user_sw);
else
gpio_free(sw_gpio);
if (status != 0)
sw_gpio = -EINVAL;
gpio_request(gpio + 3, "pll_fs2");
gpio_direction_output(gpio + 3, 0);
gpio_request(gpio + 2, "pll_fs1");
gpio_direction_output(gpio + 2, 0);
gpio_request(gpio + 1, "pll_sr");
gpio_direction_output(gpio + 1, 0);
return 0;
}
static int
evm_u18_teardown(struct i2c_client *client, int gpio, unsigned ngpio, void *c)
{
gpio_free(gpio + 1);
gpio_free(gpio + 2);
gpio_free(gpio + 3);
if (sw_gpio > 0) {
device_remove_file(&client->dev, &dev_attr_user_sw);
gpio_free(sw_gpio);
}
return 0;
}
static int
evm_u35_setup(struct i2c_client *client, int gpio, unsigned ngpio, void *c)
{
gpio_request(gpio + 0, "nDRV_VBUS");
gpio_direction_output(gpio + 0, 1);
gpio_request(gpio + 1, "VDDIMX_EN");
gpio_direction_output(gpio + 1, 1);
gpio_request(gpio + 2, "VLYNQ_EN");
gpio_direction_output(gpio + 2, 1);
gpio_request(gpio + 3, "nCF_RESET");
gpio_direction_output(gpio + 3, 0);
gpio_request(gpio + 5, "WLAN_RESET");
gpio_direction_output(gpio + 5, 1);
gpio_request(gpio + 6, "nATA_SEL");
gpio_direction_output(gpio + 6, 0);
gpio_request(gpio + 7, "nCF_SEL");
gpio_direction_output(gpio + 7, 1);
return 0;
}
static int
evm_u35_teardown(struct i2c_client *client, int gpio, unsigned ngpio, void *c)
{
gpio_free(gpio + 7);
gpio_free(gpio + 6);
gpio_free(gpio + 5);
gpio_free(gpio + 3);
gpio_free(gpio + 2);
gpio_free(gpio + 1);
gpio_free(gpio + 0);
return 0;
}
static int dm6446evm_msp_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
dm6446evm_msp = client;
return 0;
}
static int dm6446evm_msp_remove(struct i2c_client *client)
{
dm6446evm_msp = NULL;
return 0;
}
static int dm6444evm_msp430_get_pins(void)
{
static const char txbuf[2] = { 2, 4, };
char buf[4];
struct i2c_msg msg[2] = {
{
.flags = 0,
.len = 2,
.buf = (void __force *)txbuf,
},
{
.flags = I2C_M_RD,
.len = 4,
.buf = buf,
},
};
int status;
if (!dm6446evm_msp)
return -ENXIO;
msg[0].addr = dm6446evm_msp->addr;
msg[1].addr = dm6446evm_msp->addr;
status = i2c_transfer(dm6446evm_msp->adapter, msg, 2);
if (status < 0)
return status;
dev_dbg(&dm6446evm_msp->dev,
"PINS: %02x %02x %02x %02x\n",
buf[0], buf[1], buf[2], buf[3]);
return (buf[3] << 8) | buf[2];
}
static int dm6444evm_mmc_get_cd(int module)
{
int status = dm6444evm_msp430_get_pins();
return (status < 0) ? status : !(status & BIT(1));
}
static int dm6444evm_mmc_get_ro(int module)
{
int status = dm6444evm_msp430_get_pins();
return (status < 0) ? status : status & BIT(6 + 8);
}
static void __init evm_init_i2c(void)
{
davinci_init_i2c(&i2c_pdata);
i2c_add_driver(&dm6446evm_msp_driver);
i2c_register_board_info(1, i2c_info, ARRAY_SIZE(i2c_info));
}
static void __init
davinci_evm_map_io(void)
{
dm644x_init();
}
static int davinci_phy_fixup(struct phy_device *phydev)
{
unsigned int control;
control = phy_read(phydev, 26);
phy_write(phydev, 26, (control | 0x800));
return 0;
}
static __init void davinci_evm_init(void)
{
int ret;
struct clk *aemif_clk;
struct davinci_soc_info *soc_info = &davinci_soc_info;
ret = dm644x_gpio_register();
if (ret)
pr_warn("%s: GPIO init failed: %d\n", __func__, ret);
aemif_clk = clk_get(NULL, "aemif");
clk_prepare_enable(aemif_clk);
if (HAS_ATA) {
if (HAS_NAND || HAS_NOR)
pr_warning("WARNING: both IDE and Flash are "
"enabled, but they share AEMIF pins.\n"
"\tDisable IDE for NAND/NOR support.\n");
davinci_init_ide();
} else if (HAS_NAND || HAS_NOR) {
davinci_cfg_reg(DM644X_HPIEN_DISABLE);
davinci_cfg_reg(DM644X_ATAEN_DISABLE);
if (HAS_NAND) {
platform_device_register(&davinci_evm_nandflash_device);
evm_leds[7].default_trigger = "nand-disk";
if (HAS_NOR)
pr_warning("WARNING: both NAND and NOR flash "
"are enabled; disable one of them.\n");
} else if (HAS_NOR)
platform_device_register(&davinci_evm_norflash_device);
}
platform_add_devices(davinci_evm_devices,
ARRAY_SIZE(davinci_evm_devices));
evm_init_i2c();
davinci_setup_mmc(0, &dm6446evm_mmc_config);
dm644x_init_video(&dm644xevm_capture_cfg, &dm644xevm_display_cfg);
davinci_serial_init(dm644x_serial_device);
dm644x_init_asp(&dm644x_evm_snd_data);
davinci_setup_usb(1000, 8);
soc_info->emac_pdata->phy_id = DM644X_EVM_PHY_ID;
phy_register_fixup_for_uid(LXT971_PHY_ID, LXT971_PHY_MASK,
davinci_phy_fixup);
}
