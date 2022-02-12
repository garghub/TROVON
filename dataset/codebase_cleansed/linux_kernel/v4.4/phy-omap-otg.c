static void omap_otg_ctrl(struct otg_device *otg_dev, u32 outputs)
{
u32 l;
l = readl(otg_dev->base + OMAP_OTG_CTRL);
l &= ~OMAP_OTG_XCEIV_OUTPUTS;
l |= outputs;
writel(l, otg_dev->base + OMAP_OTG_CTRL);
}
static void omap_otg_set_mode(struct otg_device *otg_dev)
{
if (!otg_dev->id && otg_dev->vbus)
omap_otg_ctrl(otg_dev, OMAP_OTG_ID | OMAP_OTG_BSESSVLD);
else if (otg_dev->vbus)
omap_otg_ctrl(otg_dev, OMAP_OTG_ASESSVLD);
else if (!otg_dev->id)
omap_otg_ctrl(otg_dev, OMAP_OTG_ID | OMAP_OTG_BSESSEND);
}
static int omap_otg_id_notifier(struct notifier_block *nb,
unsigned long event, void *ptr)
{
struct otg_device *otg_dev = container_of(nb, struct otg_device, id_nb);
otg_dev->id = event;
omap_otg_set_mode(otg_dev);
return NOTIFY_DONE;
}
static int omap_otg_vbus_notifier(struct notifier_block *nb,
unsigned long event, void *ptr)
{
struct otg_device *otg_dev = container_of(nb, struct otg_device,
vbus_nb);
otg_dev->vbus = event;
omap_otg_set_mode(otg_dev);
return NOTIFY_DONE;
}
static int omap_otg_probe(struct platform_device *pdev)
{
const struct omap_usb_config *config = pdev->dev.platform_data;
struct otg_device *otg_dev;
struct extcon_dev *extcon;
int ret;
u32 rev;
if (!config || !config->extcon)
return -ENODEV;
extcon = extcon_get_extcon_dev(config->extcon);
if (!extcon)
return -EPROBE_DEFER;
otg_dev = devm_kzalloc(&pdev->dev, sizeof(*otg_dev), GFP_KERNEL);
if (!otg_dev)
return -ENOMEM;
otg_dev->base = devm_ioremap_resource(&pdev->dev, &pdev->resource[0]);
if (IS_ERR(otg_dev->base))
return PTR_ERR(otg_dev->base);
otg_dev->extcon = extcon;
otg_dev->id_nb.notifier_call = omap_otg_id_notifier;
otg_dev->vbus_nb.notifier_call = omap_otg_vbus_notifier;
ret = extcon_register_notifier(extcon, EXTCON_USB_HOST, &otg_dev->id_nb);
if (ret)
return ret;
ret = extcon_register_notifier(extcon, EXTCON_USB, &otg_dev->vbus_nb);
if (ret) {
extcon_unregister_notifier(extcon, EXTCON_USB_HOST,
&otg_dev->id_nb);
return ret;
}
otg_dev->id = extcon_get_cable_state_(extcon, EXTCON_USB_HOST);
otg_dev->vbus = extcon_get_cable_state_(extcon, EXTCON_USB);
omap_otg_set_mode(otg_dev);
rev = readl(otg_dev->base);
dev_info(&pdev->dev,
"OMAP USB OTG controller rev %d.%d (%s, id=%d, vbus=%d)\n",
(rev >> 4) & 0xf, rev & 0xf, config->extcon, otg_dev->id,
otg_dev->vbus);
return 0;
}
static int omap_otg_remove(struct platform_device *pdev)
{
struct otg_device *otg_dev = platform_get_drvdata(pdev);
struct extcon_dev *edev = otg_dev->extcon;
extcon_unregister_notifier(edev, EXTCON_USB_HOST,&otg_dev->id_nb);
extcon_unregister_notifier(edev, EXTCON_USB, &otg_dev->vbus_nb);
return 0;
}
