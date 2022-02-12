static int usbhsf_get_id(struct platform_device *pdev)
{
return USBHS_GADGET;
}
static int usbhsf_power_ctrl(struct platform_device *pdev,
void __iomem *base, int enable)
{
enable = !!enable;
r8a7778_usb_phy_power(enable);
iowrite16(enable << 14, base + SUSPMODE);
return 0;
}
static int rsnd_codec_power(int id, int enable)
{
static int sound_user[SOUND_MAX] = {0, 0, 0};
int *usr = NULL;
u32 bit;
switch (id) {
case 3:
case 4:
usr = sound_user + AK4554_34;
bit = (1 << 10);
break;
case 5:
case 6:
usr = sound_user + AK4643_56;
bit = (1 << 6);
break;
case 7:
case 8:
usr = sound_user + AK4554_78;
bit = (1 << 7);
break;
}
if (!usr)
return -EIO;
if (enable) {
if (*usr == 0) {
u32 val = ioread16(fpga + COMCTLR);
val &= ~bit;
iowrite16(val, fpga + COMCTLR);
}
(*usr)++;
} else {
if (*usr == 0)
return 0;
(*usr)--;
if (*usr == 0) {
u32 val = ioread16(fpga + COMCTLR);
val |= bit;
iowrite16(val, fpga + COMCTLR);
}
}
return 0;
}
static int rsnd_start(int id)
{
return rsnd_codec_power(id, 1);
}
static int rsnd_stop(int id)
{
return rsnd_codec_power(id, 0);
}
static void __init bockw_init(void)
{
void __iomem *base;
struct clk *clk;
int i;
r8a7778_clock_init();
r8a7778_init_irq_extpin(1);
r8a7778_add_standard_devices();
platform_device_register_resndata(&platform_bus, "r8a777x-ether", -1,
ether_resources,
ARRAY_SIZE(ether_resources),
&ether_platform_data,
sizeof(ether_platform_data));
platform_device_register_full(&vin0_info);
if (!IS_ENABLED(CONFIG_SH_ETH))
platform_device_register_full(&vin1_info);
platform_device_register_data(&platform_bus, "soc-camera-pdrv", 0,
&iclink0_ml86v7667,
sizeof(iclink0_ml86v7667));
platform_device_register_data(&platform_bus, "soc-camera-pdrv", 1,
&iclink1_ml86v7667,
sizeof(iclink1_ml86v7667));
i2c_register_board_info(0, i2c0_devices,
ARRAY_SIZE(i2c0_devices));
spi_register_board_info(spi_board_info,
ARRAY_SIZE(spi_board_info));
pinctrl_register_mappings(bockw_pinctrl_map,
ARRAY_SIZE(bockw_pinctrl_map));
r8a7778_pinmux_init();
platform_device_register_resndata(
&platform_bus, "sh_mmcif", -1,
mmc_resources, ARRAY_SIZE(mmc_resources),
&sh_mmcif_plat, sizeof(struct sh_mmcif_plat_data));
platform_device_register_resndata(
&platform_bus, "rcar_usb_phy", -1,
usb_phy_resources,
ARRAY_SIZE(usb_phy_resources),
&usb_phy_platform_data,
sizeof(struct rcar_phy_platform_data));
fpga = ioremap_nocache(FPGA, SZ_1M);
if (fpga) {
u16 val = ioread16(fpga + IRQ0MR);
val &= ~(1 << 4);
iowrite16(val, fpga + IRQ0MR);
regulator_register_fixed(0, dummy_supplies,
ARRAY_SIZE(dummy_supplies));
platform_device_register_resndata(
&platform_bus, "smsc911x", -1,
smsc911x_resources, ARRAY_SIZE(smsc911x_resources),
&smsc911x_data, sizeof(smsc911x_data));
}
base = ioremap_nocache(PFC, 0x200);
if (base) {
iowrite32(ioread32(base + PUPR4) | (3 << 26), base + PUPR4);
iounmap(base);
platform_device_register_resndata(
&platform_bus, "sh_mobile_sdhi", 0,
sdhi0_resources, ARRAY_SIZE(sdhi0_resources),
&sdhi0_info, sizeof(struct sh_mobile_sdhi_info));
}
clk = clk_get(NULL, "audio_clk_b");
clk_set_rate(clk, 24576000);
clk_put(clk);
rsnd_codec_power(5, 1);
platform_device_register_simple(
"ak4554-adc-dac", 0, NULL, 0);
platform_device_register_simple(
"ak4554-adc-dac", 1, NULL, 0);
platform_device_register_resndata(
&platform_bus, "rcar_sound", -1,
rsnd_resources, ARRAY_SIZE(rsnd_resources),
&rsnd_info, sizeof(rsnd_info));
for (i = 0; i < ARRAY_SIZE(rsnd_card_info); i++) {
struct platform_device_info cardinfo = {
.parent = &platform_bus,
.name = "asoc-simple-card",
.id = i,
.data = &rsnd_card_info[i],
.size_data = sizeof(struct asoc_simple_card_info),
.dma_mask = DMA_BIT_MASK(32),
};
platform_device_register_full(&cardinfo);
}
}
static void __init bockw_init_late(void)
{
r8a7778_init_late();
ADD_USB_FUNC_DEVICE_IF_POSSIBLE();
}
