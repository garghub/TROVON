static int micro_bl_update_status(struct backlight_device *bd)
{
struct ipaq_micro *micro = dev_get_drvdata(&bd->dev);
int intensity = bd->props.brightness;
struct ipaq_micro_msg msg = {
.id = MSG_BACKLIGHT,
.tx_len = 3,
};
if (bd->props.power != FB_BLANK_UNBLANK)
intensity = 0;
if (bd->props.state & (BL_CORE_FBBLANK | BL_CORE_SUSPENDED))
intensity = 0;
msg.tx_data[0] = 0x01;
msg.tx_data[1] = intensity > 0 ? 1 : 0;
msg.tx_data[2] = intensity;
return ipaq_micro_tx_msg_sync(micro, &msg);
}
static int micro_backlight_probe(struct platform_device *pdev)
{
struct backlight_device *bd;
struct ipaq_micro *micro = dev_get_drvdata(pdev->dev.parent);
bd = devm_backlight_device_register(&pdev->dev, "ipaq-micro-backlight",
&pdev->dev, micro, &micro_bl_ops,
&micro_bl_props);
if (IS_ERR(bd))
return PTR_ERR(bd);
platform_set_drvdata(pdev, bd);
backlight_update_status(bd);
return 0;
}
