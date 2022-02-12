static void mityomapl138_cpufreq_init(const char *partnum)
{
int i, ret;
for (i = 0; partnum && i < ARRAY_SIZE(mityomapl138_pn_info); i++) {
if (!strncmp(partnum, mityomapl138_pn_info[i].part_no,
strlen(mityomapl138_pn_info[i].part_no))) {
da850_max_speed = mityomapl138_pn_info[i].max_freq;
break;
}
}
ret = da850_register_cpufreq("pll0_sysclk3");
if (ret)
pr_warning("cpufreq registration failed: %d\n", ret);
}
static void mityomapl138_cpufreq_init(const char *partnum) { }
static void read_factory_config(struct memory_accessor *a, void *context)
{
int ret;
const char *partnum = NULL;
struct davinci_soc_info *soc_info = &davinci_soc_info;
ret = a->read(a, (char *)&factory_config, 0, sizeof(factory_config));
if (ret != sizeof(struct factory_config)) {
pr_warning("MityOMAPL138: Read Factory Config Failed: %d\n",
ret);
goto bad_config;
}
if (factory_config.magic != FACTORY_CONFIG_MAGIC) {
pr_warning("MityOMAPL138: Factory Config Magic Wrong (%X)\n",
factory_config.magic);
goto bad_config;
}
if (factory_config.version != FACTORY_CONFIG_VERSION) {
pr_warning("MityOMAPL138: Factory Config Version Wrong (%X)\n",
factory_config.version);
goto bad_config;
}
pr_info("MityOMAPL138: Found MAC = %pM\n", factory_config.mac);
if (is_valid_ether_addr(factory_config.mac))
memcpy(soc_info->emac_pdata->mac_addr,
factory_config.mac, ETH_ALEN);
else
pr_warning("MityOMAPL138: Invalid MAC found "
"in factory config block\n");
partnum = factory_config.partnum;
pr_info("MityOMAPL138: Part Number = %s\n", partnum);
bad_config:
mityomapl138_cpufreq_init(partnum);
}
static int __init pmic_tps65023_init(void)
{
return i2c_register_board_info(1, mityomap_tps65023_info,
ARRAY_SIZE(mityomap_tps65023_info));
}
static void __init mityomapl138_setup_nand(void)
{
platform_add_devices(mityomapl138_devices,
ARRAY_SIZE(mityomapl138_devices));
if (davinci_aemif_setup(&mityomapl138_nandflash_device))
pr_warn("%s: Cannot configure AEMIF.\n", __func__);
}
static void __init mityomapl138_config_emac(void)
{
void __iomem *cfg_chip3_base;
int ret;
u32 val;
struct davinci_soc_info *soc_info = &davinci_soc_info;
soc_info->emac_pdata->rmii_en = 0;
cfg_chip3_base = DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP3_REG);
val = __raw_readl(cfg_chip3_base);
if (soc_info->emac_pdata->rmii_en) {
val |= BIT(8);
ret = davinci_cfg_reg_list(mityomap_rmii_pins);
pr_info("RMII PHY configured\n");
} else {
val &= ~BIT(8);
ret = davinci_cfg_reg_list(mityomap_mii_pins);
pr_info("MII PHY configured\n");
}
if (ret) {
pr_warning("mii/rmii mux setup failed: %d\n", ret);
return;
}
__raw_writel(val, cfg_chip3_base);
soc_info->emac_pdata->phy_id = MITYOMAPL138_PHY_ID;
ret = da8xx_register_emac();
if (ret)
pr_warning("emac registration failed: %d\n", ret);
}
static void __init mityomapl138_init(void)
{
int ret;
ret = da850_register_edma(NULL);
if (ret)
pr_warning("edma registration failed: %d\n", ret);
ret = da8xx_register_watchdog();
if (ret)
pr_warning("watchdog registration failed: %d\n", ret);
davinci_serial_init(da8xx_serial_device);
ret = da8xx_register_i2c(0, &mityomap_i2c_0_pdata);
if (ret)
pr_warning("i2c0 registration failed: %d\n", ret);
ret = pmic_tps65023_init();
if (ret)
pr_warning("TPS65023 PMIC init failed: %d\n", ret);
mityomapl138_setup_nand();
ret = spi_register_board_info(mityomapl138_spi_flash_info,
ARRAY_SIZE(mityomapl138_spi_flash_info));
if (ret)
pr_warn("spi info registration failed: %d\n", ret);
ret = da8xx_register_spi_bus(1,
ARRAY_SIZE(mityomapl138_spi_flash_info));
if (ret)
pr_warning("spi 1 registration failed: %d\n", ret);
mityomapl138_config_emac();
ret = da8xx_register_rtc();
if (ret)
pr_warning("rtc setup failed: %d\n", ret);
ret = da8xx_register_cpuidle();
if (ret)
pr_warning("cpuidle registration failed: %d\n", ret);
ret = da850_register_pm(&da850_pm_device);
if (ret)
pr_warning("da850_evm_init: suspend registration failed: %d\n",
ret);
}
static int __init mityomapl138_console_init(void)
{
if (!machine_is_mityomapl138())
return 0;
return add_preferred_console("ttyS", 1, "115200");
}
static void __init mityomapl138_map_io(void)
{
da850_init();
}
