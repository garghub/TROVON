static int __init mxs_icoll_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
irq_domain_add_legacy(np, 128, 0, 0, &irq_domain_simple_ops, NULL);
return 0;
}
static int __init mxs_gpio_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
static int gpio_irq_base = MXS_GPIO_IRQ_START;
irq_domain_add_legacy(np, 32, gpio_irq_base, 0, &irq_domain_simple_ops, NULL);
gpio_irq_base += 32;
return 0;
}
static void __init mxs_dt_init_irq(void)
{
icoll_init_irq();
of_irq_init(mxs_irq_match);
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
}
val = ocotp[i];
macaddr[3] = (val >> 16) & 0xff;
macaddr[4] = (val >> 8) & 0xff;
macaddr[5] = (val >> 0) & 0xff;
prom_update_property(np, newmac);
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
}
static void __init m28evk_init(void)
{
enable_clk_enet_out();
update_fec_mac_prop(OUI_DENX);
mxsfb_pdata.mode_list = m28evk_video_modes;
mxsfb_pdata.mode_count = ARRAY_SIZE(m28evk_video_modes);
mxsfb_pdata.default_bpp = 16;
mxsfb_pdata.ld_intf_width = STMLCDIF_18BIT;
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
of_platform_populate(NULL, of_default_bus_match_table,
mxs_auxdata_lookup, NULL);
}
