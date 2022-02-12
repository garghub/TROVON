static void __init davinci_ntosd2_map_io(void)
{
dm644x_init();
}
static __init void davinci_ntosd2_init(void)
{
struct clk *aemif_clk;
struct davinci_soc_info *soc_info = &davinci_soc_info;
aemif_clk = clk_get(NULL, "aemif");
clk_prepare_enable(aemif_clk);
if (HAS_ATA) {
if (HAS_NAND)
pr_warning("WARNING: both IDE and Flash are "
"enabled, but they share AEMIF pins.\n"
"\tDisable IDE for NAND/NOR support.\n");
davinci_init_ide();
} else if (HAS_NAND) {
davinci_cfg_reg(DM644X_HPIEN_DISABLE);
davinci_cfg_reg(DM644X_ATAEN_DISABLE);
if (HAS_NAND)
platform_device_register(
&davinci_ntosd2_nandflash_device);
}
platform_add_devices(davinci_ntosd2_devices,
ARRAY_SIZE(davinci_ntosd2_devices));
davinci_serial_init(&uart_config);
dm644x_init_asp(&dm644x_ntosd2_snd_data);
soc_info->emac_pdata->phy_id = NEUROS_OSD2_PHY_ID;
davinci_setup_usb(1000, 8);
davinci_cfg_reg(DM644X_AEAW0);
davinci_cfg_reg(DM644X_AEAW1);
davinci_cfg_reg(DM644X_AEAW2);
davinci_cfg_reg(DM644X_AEAW3);
davinci_cfg_reg(DM644X_AEAW4);
davinci_setup_mmc(0, &davinci_ntosd2_mmc_config);
}
