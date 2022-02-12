void __init usb_musb_init(struct omap_musb_board_data *musb_board_data)
{
struct omap_hwmod *oh;
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
if (cpu_is_omap3517() || cpu_is_omap3505()) {
oh_name = "am35x_otg_hs";
name = "musb-am35x";
} else if (cpu_is_ti81xx()) {
oh_name = "usb_otg_hs";
name = "musb-ti81xx";
} else {
oh_name = "usb_otg_hs";
name = "musb-omap2430";
}
oh = omap_hwmod_lookup(oh_name);
if (WARN(!oh, "%s: could not find omap_hwmod for %s\n",
__func__, oh_name))
return;
pdev = omap_device_build(name, bus_id, oh, &musb_plat,
sizeof(musb_plat), NULL, 0, false);
if (IS_ERR(pdev)) {
pr_err("Could not build omap_device for %s %s\n",
name, oh_name);
return;
}
dev = &pdev->dev;
get_device(dev);
dev->dma_mask = &musb_dmamask;
dev->coherent_dma_mask = musb_dmamask;
put_device(dev);
if (cpu_is_omap44xx())
omap4430_phy_init(dev);
}
