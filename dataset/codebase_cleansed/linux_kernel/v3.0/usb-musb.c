static void usb_musb_mux_init(struct omap_musb_board_data *board_data)
{
switch (board_data->interface_type) {
case MUSB_INTERFACE_UTMI:
omap_mux_init_signal("usba0_otg_dp", OMAP_PIN_INPUT);
omap_mux_init_signal("usba0_otg_dm", OMAP_PIN_INPUT);
break;
case MUSB_INTERFACE_ULPI:
omap_mux_init_signal("usba0_ulpiphy_clk",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_stp",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dir",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_nxt",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dat0",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dat1",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dat2",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dat3",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dat4",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dat5",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dat6",
OMAP_PIN_INPUT_PULLDOWN);
omap_mux_init_signal("usba0_ulpiphy_dat7",
OMAP_PIN_INPUT_PULLDOWN);
break;
default:
break;
}
}
void __init usb_musb_init(struct omap_musb_board_data *musb_board_data)
{
struct omap_hwmod *oh;
struct omap_device *od;
struct platform_device *pdev;
struct device *dev;
int bus_id = -1;
const char *oh_name, *name;
struct omap_musb_board_data *board_data;
if (musb_board_data)
board_data = musb_board_data;
else
board_data = &musb_default_board_data;
musb_plat.clock = "ick";
musb_plat.board_data = board_data;
musb_plat.power = board_data->power >> 1;
musb_plat.mode = board_data->mode;
musb_plat.extvbus = board_data->extvbus;
if (cpu_is_omap44xx())
omap4430_phy_init(dev);
if (cpu_is_omap3517() || cpu_is_omap3505()) {
oh_name = "am35x_otg_hs";
name = "musb-am35x";
} else {
oh_name = "usb_otg_hs";
name = "musb-omap2430";
}
oh = omap_hwmod_lookup(oh_name);
if (!oh) {
pr_err("Could not look up %s\n", oh_name);
return;
}
od = omap_device_build(name, bus_id, oh, &musb_plat,
sizeof(musb_plat), omap_musb_latency,
ARRAY_SIZE(omap_musb_latency), false);
if (IS_ERR(od)) {
pr_err("Could not build omap_device for %s %s\n",
name, oh_name);
return;
}
pdev = &od->pdev;
dev = &pdev->dev;
get_device(dev);
dev->dma_mask = &musb_dmamask;
dev->coherent_dma_mask = musb_dmamask;
put_device(dev);
if (cpu_is_omap44xx())
omap4430_phy_init(dev);
}
void __init usb_musb_init(struct omap_musb_board_data *board_data)
{
if (cpu_is_omap44xx())
omap4430_phy_init(NULL);
}
