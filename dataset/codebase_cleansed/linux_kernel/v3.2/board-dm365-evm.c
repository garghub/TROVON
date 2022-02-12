static inline int have_imager(void)
{
return 0;
}
static inline int have_tvp7002(void)
{
return 0;
}
static int dm365evm_keyscan_enable(struct device *dev)
{
return davinci_cfg_reg(DM365_KEYSCAN);
}
static int cpld_mmc_get_cd(int module)
{
if (!cpld)
return -ENXIO;
return !(__raw_readb(cpld + CPLD_CARDSTAT) & BIT(module ? 4 : 0));
}
static int cpld_mmc_get_ro(int module)
{
if (!cpld)
return -ENXIO;
return !!(__raw_readb(cpld + CPLD_CARDSTAT) & BIT(module ? 5 : 1));
}
static void dm365evm_emac_configure(void)
{
davinci_cfg_reg(DM365_EMAC_TX_EN);
davinci_cfg_reg(DM365_EMAC_TX_CLK);
davinci_cfg_reg(DM365_EMAC_COL);
davinci_cfg_reg(DM365_EMAC_TXD3);
davinci_cfg_reg(DM365_EMAC_TXD2);
davinci_cfg_reg(DM365_EMAC_TXD1);
davinci_cfg_reg(DM365_EMAC_TXD0);
davinci_cfg_reg(DM365_EMAC_RXD3);
davinci_cfg_reg(DM365_EMAC_RXD2);
davinci_cfg_reg(DM365_EMAC_RXD1);
davinci_cfg_reg(DM365_EMAC_RXD0);
davinci_cfg_reg(DM365_EMAC_RX_CLK);
davinci_cfg_reg(DM365_EMAC_RX_DV);
davinci_cfg_reg(DM365_EMAC_RX_ER);
davinci_cfg_reg(DM365_EMAC_CRS);
davinci_cfg_reg(DM365_EMAC_MDIO);
davinci_cfg_reg(DM365_EMAC_MDCLK);
davinci_cfg_reg(DM365_INT_EMAC_RXTHRESH);
davinci_cfg_reg(DM365_INT_EMAC_RXPULSE);
davinci_cfg_reg(DM365_INT_EMAC_TXPULSE);
davinci_cfg_reg(DM365_INT_EMAC_MISCPULSE);
}
static void dm365evm_mmc_configure(void)
{
davinci_cfg_reg(DM365_SD1_CLK);
davinci_cfg_reg(DM365_SD1_CMD);
davinci_cfg_reg(DM365_SD1_DATA3);
davinci_cfg_reg(DM365_SD1_DATA2);
davinci_cfg_reg(DM365_SD1_DATA1);
davinci_cfg_reg(DM365_SD1_DATA0);
}
static void __init evm_init_i2c(void)
{
davinci_init_i2c(&i2c_pdata);
i2c_register_board_info(1, i2c_info, ARRAY_SIZE(i2c_info));
}
static inline int have_leds(void)
{
#ifdef CONFIG_LEDS_CLASS
return 1;
#else
return 0;
#endif
}
static void cpld_led_set(struct led_classdev *cdev, enum led_brightness b)
{
struct cpld_led *led = container_of(cdev, struct cpld_led, cdev);
u8 reg = __raw_readb(cpld + CPLD_LEDS);
if (b != LED_OFF)
reg &= ~led->mask;
else
reg |= led->mask;
__raw_writeb(reg, cpld + CPLD_LEDS);
}
static enum led_brightness cpld_led_get(struct led_classdev *cdev)
{
struct cpld_led *led = container_of(cdev, struct cpld_led, cdev);
u8 reg = __raw_readb(cpld + CPLD_LEDS);
return (reg & led->mask) ? LED_OFF : LED_FULL;
}
static int __init cpld_leds_init(void)
{
int i;
if (!have_leds() || !cpld)
return 0;
__raw_writeb(0xff, cpld + CPLD_LEDS);
for (i = 0; i < ARRAY_SIZE(cpld_leds); i++) {
struct cpld_led *led;
led = kzalloc(sizeof(*led), GFP_KERNEL);
if (!led)
break;
led->cdev.name = cpld_leds[i].name;
led->cdev.brightness_set = cpld_led_set;
led->cdev.brightness_get = cpld_led_get;
led->cdev.default_trigger = cpld_leds[i].trigger;
led->mask = BIT(i);
if (led_classdev_register(NULL, &led->cdev) < 0) {
kfree(led);
break;
}
}
return 0;
}
static void __init evm_init_cpld(void)
{
u8 mux, resets;
const char *label;
struct clk *aemif_clk;
aemif_clk = clk_get(NULL, "aemif");
if (IS_ERR(aemif_clk))
return;
clk_enable(aemif_clk);
if (request_mem_region(DM365_ASYNC_EMIF_DATA_CE1_BASE, SECTION_SIZE,
"cpld") == NULL)
goto fail;
cpld = ioremap(DM365_ASYNC_EMIF_DATA_CE1_BASE, SECTION_SIZE);
if (!cpld) {
release_mem_region(DM365_ASYNC_EMIF_DATA_CE1_BASE,
SECTION_SIZE);
fail:
pr_err("ERROR: can't map CPLD\n");
clk_disable(aemif_clk);
return;
}
mux = 0;
if ((__raw_readb(cpld + CPLD_SWITCH) & BIT(5)) == 0) {
mux |= BIT(7);
platform_add_devices(dm365_evm_nand_devices,
ARRAY_SIZE(dm365_evm_nand_devices));
} else {
}
resets = BIT(3) | BIT(2) | BIT(1) | BIT(0);
if (have_imager()) {
label = "HD imager";
mux |= 2;
mux |= BIT(6) | BIT(5) | BIT(3);
} else {
struct davinci_soc_info *soc_info = &davinci_soc_info;
dm365evm_mmc_configure();
davinci_setup_mmc(1, &dm365evm_mmc_config);
dm365evm_emac_configure();
soc_info->emac_pdata->phy_id = DM365_EVM_PHY_ID;
resets &= ~BIT(3);
resets &= ~BIT(1);
if (have_tvp7002()) {
mux |= 1;
resets &= ~BIT(2);
label = "tvp7002 HD";
} else {
mux |= 5;
resets &= ~BIT(0);
label = "tvp5146 SD";
}
}
__raw_writeb(mux, cpld + CPLD_MUX);
__raw_writeb(resets, cpld + CPLD_RESETS);
pr_info("EVM: %s video input\n", label);
}
static void __init dm365_evm_map_io(void)
{
dm365_set_vpfe_config(&vpfe_cfg);
dm365_init();
}
static __init void dm365_evm_init(void)
{
evm_init_i2c();
davinci_serial_init(&uart_config);
dm365evm_emac_configure();
dm365evm_mmc_configure();
davinci_setup_mmc(0, &dm365evm_mmc_config);
evm_init_cpld();
#ifdef CONFIG_SND_DM365_AIC3X_CODEC
dm365_init_asp(&dm365_evm_snd_data);
#elif defined(CONFIG_SND_DM365_VOICE_CODEC)
dm365_init_vc(&dm365_evm_snd_data);
#endif
dm365_init_rtc();
dm365_init_ks(&dm365evm_ks_data);
dm365_init_spi0(BIT(0), dm365_evm_spi_info,
ARRAY_SIZE(dm365_evm_spi_info));
}
