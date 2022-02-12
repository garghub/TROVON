static void __init davinci_ntosd2_map_io(void)
{
dm644x_init();
}
static int ntosd2_init_i2c(void)
{
int status;
davinci_init_i2c(&ntosd2_i2c_pdata);
status = gpio_request(NTOSD2_MSP430_IRQ, ntosd2_i2c_info[0].type);
if (status == 0) {
status = gpio_direction_input(NTOSD2_MSP430_IRQ);
if (status == 0) {
status = gpio_to_irq(NTOSD2_MSP430_IRQ);
if (status > 0) {
ntosd2_i2c_info[0].irq = status;
i2c_register_board_info(1,
ntosd2_i2c_info,
ARRAY_SIZE(ntosd2_i2c_info));
}
}
}
return status;
}
static __init void davinci_ntosd2_init(void)
{
struct clk *aemif_clk;
struct davinci_soc_info *soc_info = &davinci_soc_info;
int status;
aemif_clk = clk_get(NULL, "aemif");
clk_enable(aemif_clk);
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
status = ntosd2_init_i2c();
if (status < 0)
pr_warning("davinci_ntosd2_init: msp430 irq setup failed:"
" %d\n", status);
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
