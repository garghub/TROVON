static int cpld_reg0_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
if (HAS_ATA) {
u8 data;
struct i2c_msg msg[2] = {
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = 1,
.buf = &data,
},
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &data,
},
};
i2c_transfer(client->adapter, msg, 1);
data &= ~(DM646X_EVM_ATA_RST | DM646X_EVM_ATA_PWD);
i2c_transfer(client->adapter, msg + 1, 1);
}
return 0;
}
static int evm_led_setup(struct i2c_client *client, int gpio,
unsigned int ngpio, void *c)
{
struct gpio_led *leds = evm_leds;
int status;
while (ngpio--) {
leds->gpio = gpio++;
leds++;
};
evm_led_dev = platform_device_alloc("leds-gpio", 0);
platform_device_add_data(evm_led_dev, &evm_led_data,
sizeof(evm_led_data));
evm_led_dev->dev.parent = &client->dev;
status = platform_device_add(evm_led_dev);
if (status < 0) {
platform_device_put(evm_led_dev);
evm_led_dev = NULL;
}
return status;
}
static int evm_led_teardown(struct i2c_client *client, int gpio,
unsigned ngpio, void *c)
{
if (evm_led_dev) {
platform_device_unregister(evm_led_dev);
evm_led_dev = NULL;
}
return 0;
}
static int evm_sw_setup(struct i2c_client *client, int gpio,
unsigned ngpio, void *c)
{
int status;
int i;
char label[10];
for (i = 0; i < 4; ++i) {
snprintf(label, 10, "user_sw%d", i);
status = gpio_request(gpio, label);
if (status)
goto out_free;
evm_sw_gpio[i] = gpio++;
status = gpio_direction_input(evm_sw_gpio[i]);
if (status) {
gpio_free(evm_sw_gpio[i]);
evm_sw_gpio[i] = -EINVAL;
goto out_free;
}
status = gpio_export(evm_sw_gpio[i], 0);
if (status) {
gpio_free(evm_sw_gpio[i]);
evm_sw_gpio[i] = -EINVAL;
goto out_free;
}
}
return status;
out_free:
for (i = 0; i < 4; ++i) {
if (evm_sw_gpio[i] != -EINVAL) {
gpio_free(evm_sw_gpio[i]);
evm_sw_gpio[i] = -EINVAL;
}
}
return status;
}
static int evm_sw_teardown(struct i2c_client *client, int gpio,
unsigned ngpio, void *c)
{
int i;
for (i = 0; i < 4; ++i) {
if (evm_sw_gpio[i] != -EINVAL) {
gpio_unexport(evm_sw_gpio[i]);
gpio_free(evm_sw_gpio[i]);
evm_sw_gpio[i] = -EINVAL;
}
}
return 0;
}
static int evm_pcf_setup(struct i2c_client *client, int gpio,
unsigned int ngpio, void *c)
{
int status;
if (ngpio < 8)
return -EINVAL;
status = evm_sw_setup(client, gpio, 4, c);
if (status)
return status;
return evm_led_setup(client, gpio+4, 4, c);
}
static int evm_pcf_teardown(struct i2c_client *client, int gpio,
unsigned int ngpio, void *c)
{
BUG_ON(ngpio < 8);
evm_sw_teardown(client, gpio, 4, c);
evm_led_teardown(client, gpio+4, 4, c);
return 0;
}
static int cpld_video_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
cpld_client = client;
return 0;
}
static int __devexit cpld_video_remove(struct i2c_client *client)
{
cpld_client = NULL;
return 0;
}
static void evm_init_cpld(void)
{
i2c_add_driver(&cpld_video_driver);
}
static int set_vpif_clock(int mux_mode, int hd)
{
unsigned long flags;
unsigned int value;
int val = 0;
int err = 0;
if (!vpif_vidclkctl_reg || !vpif_vsclkdis_reg || !cpld_client)
return -ENXIO;
spin_lock_irqsave(&vpif_reg_lock, flags);
value = __raw_readl(vpif_vsclkdis_reg);
value |= (VIDCH3CLK | VIDCH2CLK);
__raw_writel(value, vpif_vsclkdis_reg);
spin_unlock_irqrestore(&vpif_reg_lock, flags);
val = i2c_smbus_read_byte(cpld_client);
if (val < 0)
return val;
if (mux_mode == 1)
val &= ~0x40;
else
val |= 0x40;
err = i2c_smbus_write_byte(cpld_client, val);
if (err)
return err;
value = __raw_readl(vpif_vidclkctl_reg);
value &= ~(VCH2CLK_MASK);
value &= ~(VCH3CLK_MASK);
if (hd >= 1)
value |= (VCH2CLK_SYSCLK8 | VCH3CLK_SYSCLK8);
else
value |= (VCH2CLK_AUXCLK | VCH3CLK_AUXCLK);
__raw_writel(value, vpif_vidclkctl_reg);
spin_lock_irqsave(&vpif_reg_lock, flags);
value = __raw_readl(vpif_vsclkdis_reg);
value &= ~(VIDCH3CLK | VIDCH2CLK);
__raw_writel(value, vpif_vsclkdis_reg);
spin_unlock_irqrestore(&vpif_reg_lock, flags);
return 0;
}
static int setup_vpif_input_path(int channel, const char *sub_dev_name)
{
int err = 0;
int val;
if (channel != 0)
return 0;
if (!cpld_client)
return -ENXIO;
val = i2c_smbus_read_byte(cpld_client);
if (val < 0)
return val;
if (!strcmp(sub_dev_name, TVP5147_CH0) ||
!strcmp(sub_dev_name, TVP5147_CH1))
val &= TVP5147_INPUT;
else
val |= TVP7002_INPUT;
err = i2c_smbus_write_byte(cpld_client, val);
if (err)
return err;
return 0;
}
static int setup_vpif_input_channel_mode(int mux_mode)
{
unsigned long flags;
int err = 0;
int val;
u32 value;
if (!vpif_vsclkdis_reg || !cpld_client)
return -ENXIO;
val = i2c_smbus_read_byte(cpld_client);
if (val < 0)
return val;
spin_lock_irqsave(&vpif_reg_lock, flags);
value = __raw_readl(vpif_vsclkdis_reg);
if (mux_mode) {
val &= VPIF_INPUT_TWO_CHANNEL;
value |= VIDCH1CLK;
} else {
val |= VPIF_INPUT_ONE_CHANNEL;
value &= ~VIDCH1CLK;
}
__raw_writel(value, vpif_vsclkdis_reg);
spin_unlock_irqrestore(&vpif_reg_lock, flags);
err = i2c_smbus_write_byte(cpld_client, val);
if (err)
return err;
return 0;
}
static void __init evm_init_video(void)
{
vpif_vidclkctl_reg = ioremap(VIDCLKCTL_OFFSET, 4);
vpif_vsclkdis_reg = ioremap(VSCLKDIS_OFFSET, 4);
if (!vpif_vidclkctl_reg || !vpif_vsclkdis_reg) {
pr_err("Can't map VPIF VIDCLKCTL or VSCLKDIS registers\n");
return;
}
spin_lock_init(&vpif_reg_lock);
dm646x_setup_vpif(&dm646x_vpif_display_config,
&dm646x_vpif_capture_cfg);
}
static void __init evm_init_i2c(void)
{
davinci_init_i2c(&i2c_pdata);
i2c_add_driver(&dm6467evm_cpld_driver);
i2c_register_board_info(1, i2c_info, ARRAY_SIZE(i2c_info));
evm_init_cpld();
evm_init_video();
}
static void __init cdce_clk_init(void)
{
struct clk_lookup *c;
struct clk *clk;
for (c = cdce_clks; c->clk; c++) {
clk = c->clk;
clkdev_add(c);
clk_register(clk);
}
}
static void __init davinci_map_io(void)
{
dm646x_init();
cdce_clk_init();
}
static __init void evm_init(void)
{
struct davinci_soc_info *soc_info = &davinci_soc_info;
evm_init_i2c();
davinci_serial_init(&uart_config);
dm646x_init_mcasp0(&dm646x_evm_snd_data[0]);
dm646x_init_mcasp1(&dm646x_evm_snd_data[1]);
if (machine_is_davinci_dm6467tevm())
davinci_nand_data.timing = &dm6467tevm_nandflash_timing;
platform_device_register(&davinci_nand_device);
dm646x_init_edma(dm646x_edma_rsv);
if (HAS_ATA)
davinci_init_ide();
soc_info->emac_pdata->phy_id = DM646X_EVM_PHY_ID;
}
void __init dm646x_board_setup_refclk(struct clk *clk)
{
if (machine_is_davinci_dm6467tevm())
clk->rate = DM6467T_EVM_REF_FREQ;
else
clk->rate = DM646X_EVM_REF_FREQ;
}
