static void mx28evk_flexcan_switch(void)
{
if (flexcan0_en || flexcan1_en)
gpio_set_value(MX28EVK_FLEXCAN_SWITCH, 1);
else
gpio_set_value(MX28EVK_FLEXCAN_SWITCH, 0);
}
static void mx28evk_flexcan0_switch(int enable)
{
flexcan0_en = enable;
mx28evk_flexcan_switch();
}
static void mx28evk_flexcan1_switch(int enable)
{
flexcan1_en = enable;
mx28evk_flexcan_switch();
}
static void __init imx23_timer_init(void)
{
mx23_clocks_init();
}
static void __init imx28_timer_init(void)
{
mx28_clocks_init();
}
static void __init update_fec_mac_prop(enum mac_oui oui)
{
struct device_node *np, *from = NULL;
struct property *newmac;
const u32 *ocotp = mxs_get_ocotp();
u8 *macaddr;
u32 val;
int i;
for (i = 0; i < 2; i++) {
np = of_find_compatible_node(from, NULL, "fsl,imx28-fec");
if (!np)
return;
from = np;
if (of_get_property(np, "local-mac-address", NULL))
continue;
newmac = kzalloc(sizeof(*newmac) + 6, GFP_KERNEL);
if (!newmac)
return;
newmac->value = newmac + 1;
newmac->length = 6;
newmac->name = kstrdup("local-mac-address", GFP_KERNEL);
if (!newmac->name) {
kfree(newmac);
return;
}
macaddr = newmac->value;
switch (oui) {
case OUI_FSL:
macaddr[0] = 0x00;
macaddr[1] = 0x04;
macaddr[2] = 0x9f;
break;
case OUI_DENX:
macaddr[0] = 0xc0;
macaddr[1] = 0xe5;
macaddr[2] = 0x4e;
break;
case OUI_CRYSTALFONTZ:
macaddr[0] = 0x58;
macaddr[1] = 0xb9;
macaddr[2] = 0xe1;
break;
}
val = ocotp[i];
macaddr[3] = (val >> 16) & 0xff;
macaddr[4] = (val >> 8) & 0xff;
macaddr[5] = (val >> 0) & 0xff;
of_update_property(np, newmac);
}
}
static void __init imx23_evk_init(void)
{
mxsfb_pdata.mode_list = mx23evk_video_modes;
mxsfb_pdata.mode_count = ARRAY_SIZE(mx23evk_video_modes);
mxsfb_pdata.default_bpp = 32;
mxsfb_pdata.ld_intf_width = STMLCDIF_24BIT;
}
static inline void enable_clk_enet_out(void)
{
struct clk *clk = clk_get_sys("enet_out", NULL);
if (!IS_ERR(clk))
clk_prepare_enable(clk);
}
static void __init imx28_evk_init(void)
{
enable_clk_enet_out();
update_fec_mac_prop(OUI_FSL);
mxsfb_pdata.mode_list = mx28evk_video_modes;
mxsfb_pdata.mode_count = ARRAY_SIZE(mx28evk_video_modes);
mxsfb_pdata.default_bpp = 32;
mxsfb_pdata.ld_intf_width = STMLCDIF_24BIT;
mxs_saif_clkmux_select(MXS_DIGCTL_SAIF_CLKMUX_EXTMSTR0);
}
static void __init imx28_evk_post_init(void)
{
if (!gpio_request_one(MX28EVK_FLEXCAN_SWITCH, GPIOF_DIR_OUT,
"flexcan-switch")) {
flexcan_pdata[0].transceiver_switch = mx28evk_flexcan0_switch;
flexcan_pdata[1].transceiver_switch = mx28evk_flexcan1_switch;
}
}
static void __init m28evk_init(void)
{
mxsfb_pdata.mode_list = m28evk_video_modes;
mxsfb_pdata.mode_count = ARRAY_SIZE(m28evk_video_modes);
mxsfb_pdata.default_bpp = 16;
mxsfb_pdata.ld_intf_width = STMLCDIF_18BIT;
}
static void __init sc_sps1_init(void)
{
enable_clk_enet_out();
}
static int apx4devkit_phy_fixup(struct phy_device *phy)
{
phy->dev_flags |= MICREL_PHY_50MHZ_CLK;
return 0;
}
static void __init apx4devkit_init(void)
{
enable_clk_enet_out();
if (IS_BUILTIN(CONFIG_PHYLIB))
phy_register_fixup_for_uid(PHY_ID_KSZ8051, MICREL_PHY_ID_MASK,
apx4devkit_phy_fixup);
mxsfb_pdata.mode_list = apx4devkit_video_modes;
mxsfb_pdata.mode_count = ARRAY_SIZE(apx4devkit_video_modes);
mxsfb_pdata.default_bpp = 32;
mxsfb_pdata.ld_intf_width = STMLCDIF_24BIT;
}
static void __init tx28_post_init(void)
{
struct device_node *np;
struct platform_device *pdev;
struct pinctrl *pctl;
int ret;
enable_clk_enet_out();
np = of_find_compatible_node(NULL, NULL, "fsl,imx28-fec");
pdev = of_find_device_by_node(np);
if (!pdev) {
pr_err("%s: failed to find fec device\n", __func__);
return;
}
pctl = pinctrl_get_select(&pdev->dev, "gpio_mode");
if (IS_ERR(pctl)) {
pr_err("%s: failed to get pinctrl state\n", __func__);
return;
}
ret = gpio_request_array(tx28_gpios, ARRAY_SIZE(tx28_gpios));
if (ret) {
pr_err("%s: failed to request gpios: %d\n", __func__, ret);
return;
}
gpio_set_value(TX28_FEC_PHY_POWER, 1);
msleep(26);
gpio_set_value(ENET0_RX_EN__GPIO_4_2, 1);
gpio_set_value(ENET0_RXD0__GPIO_4_3, 1);
gpio_set_value(ENET0_RXD1__GPIO_4_4, 1);
udelay(100);
gpio_set_value(TX28_FEC_PHY_RESET, 1);
pinctrl_put(pctl);
}
static void __init cfa10049_init(void)
{
enable_clk_enet_out();
update_fec_mac_prop(OUI_CRYSTALFONTZ);
}
static void __init apf28_init(void)
{
enable_clk_enet_out();
mxsfb_pdata.mode_list = apf28dev_video_modes;
mxsfb_pdata.mode_count = ARRAY_SIZE(apf28dev_video_modes);
mxsfb_pdata.default_bpp = 16;
mxsfb_pdata.ld_intf_width = STMLCDIF_16BIT;
}
static void __init mxs_machine_init(void)
{
if (of_machine_is_compatible("fsl,imx28-evk"))
imx28_evk_init();
else if (of_machine_is_compatible("fsl,imx23-evk"))
imx23_evk_init();
else if (of_machine_is_compatible("denx,m28evk"))
m28evk_init();
else if (of_machine_is_compatible("bluegiga,apx4devkit"))
apx4devkit_init();
else if (of_machine_is_compatible("crystalfontz,cfa10049"))
cfa10049_init();
else if (of_machine_is_compatible("armadeus,imx28-apf28"))
apf28_init();
else if (of_machine_is_compatible("schulercontrol,imx28-sps1"))
sc_sps1_init();
of_platform_populate(NULL, of_default_bus_match_table,
mxs_auxdata_lookup, NULL);
if (of_machine_is_compatible("karo,tx28"))
tx28_post_init();
if (of_machine_is_compatible("fsl,imx28-evk"))
imx28_evk_post_init();
}
