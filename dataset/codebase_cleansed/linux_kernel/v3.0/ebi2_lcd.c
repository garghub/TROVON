static int ebi2_lcd_probe(struct platform_device *pdev)
{
struct msm_fb_data_type *mfd;
struct platform_device *mdp_dev = NULL;
struct msm_fb_panel_data *pdata = NULL;
int rc, i;
if (pdev->id == 0) {
for (i = 0; i < pdev->num_resources; i++) {
if (!strncmp(pdev->resource[i].name, "base", 4)) {
ebi2_base = ioremap(pdev->resource[i].start,
pdev->resource[i].end -
pdev->resource[i].start + 1);
if (!ebi2_base) {
printk(KERN_ERR
"ebi2_base ioremap failed!\n");
return -ENOMEM;
}
ebi2_lcd_cfg0 = (void *)(ebi2_base + 0x20);
ebi2_lcd_cfg1 = (void *)(ebi2_base + 0x24);
} else if (!strncmp(pdev->resource[i].name,
"lcd01", 5)) {
lcd01_base = ioremap(pdev->resource[i].start,
pdev->resource[i].end -
pdev->resource[i].start + 1);
if (!lcd01_base) {
printk(KERN_ERR
"lcd01_base ioremap failed!\n");
return -ENOMEM;
}
} else if (!strncmp(pdev->resource[i].name,
"lcd02", 5)) {
lcd02_base = ioremap(pdev->resource[i].start,
pdev->resource[i].end -
pdev->resource[i].start + 1);
if (!lcd02_base) {
printk(KERN_ERR
"lcd02_base ioremap failed!\n");
return -ENOMEM;
}
}
}
ebi2_lcd_resource_initialized = 1;
return 0;
}
if (!ebi2_lcd_resource_initialized)
return -EPERM;
mfd = platform_get_drvdata(pdev);
if (!mfd)
return -ENODEV;
if (mfd->key != MFD_KEY)
return -EINVAL;
if (pdev_list_cnt >= MSM_FB_MAX_DEV_LIST)
return -ENOMEM;
if (ebi2_base == NULL)
return -ENOMEM;
mdp_dev = platform_device_alloc("mdp", pdev->id);
if (!mdp_dev)
return -ENOMEM;
mfd->pdev = mdp_dev;
mfd->dest = DISPLAY_LCD;
if (platform_device_add_data
(mdp_dev, pdev->dev.platform_data,
sizeof(struct msm_fb_panel_data))) {
printk(KERN_ERR "ebi2_lcd_probe: platform_device_add_data failed!\n");
platform_device_put(mdp_dev);
return -ENOMEM;
}
pdata = mdp_dev->dev.platform_data;
pdata->on = panel_next_on;
pdata->off = panel_next_off;
pdata->next = pdev;
mfd->panel_info = pdata->panel_info;
if (mfd->panel_info.bpp == 24)
mfd->fb_imgType = MDP_RGB_888;
else
mfd->fb_imgType = MDP_RGB_565;
if (mfd->panel_info.pdest == DISPLAY_1) {
outp32(ebi2_base,
(inp32(ebi2_base) & (~(EBI2_PRIM_LCD_CLR))) |
EBI2_PRIM_LCD_SEL);
outp32(ebi2_lcd_cfg0, mfd->panel_info.wait_cycle);
if (mfd->panel_info.bpp == 18)
outp32(ebi2_lcd_cfg1, 0x01000000);
else
outp32(ebi2_lcd_cfg1, 0x0);
} else {
#ifdef DEBUG_EBI2_LCD
outp32(ebi2_base, (inp32(ebi2_base)&(~(EBI2_SECD_LCD_CLR)))
|EBI2_SECD_LCD_SEL);
#endif
}
if (mfd->panel_info.pdest == DISPLAY_1) {
mfd->cmd_port = lcd01_base;
mfd->data_port =
(void *)((uint32) mfd->cmd_port + EBI2_PRIM_LCD_RS_PIN);
mfd->data_port_phys =
(void *)(LCD_PRIM_BASE_PHYS + EBI2_PRIM_LCD_RS_PIN);
} else {
mfd->cmd_port = lcd01_base;
mfd->data_port =
(void *)((uint32) mfd->cmd_port + EBI2_SECD_LCD_RS_PIN);
mfd->data_port_phys =
(void *)(LCD_SECD_BASE_PHYS + EBI2_SECD_LCD_RS_PIN);
}
platform_set_drvdata(mdp_dev, mfd);
rc = platform_device_add(mdp_dev);
if (rc) {
goto ebi2_lcd_probe_err;
}
pdev_list[pdev_list_cnt++] = pdev;
return 0;
ebi2_lcd_probe_err:
platform_device_put(mdp_dev);
return rc;
}
static int ebi2_lcd_remove(struct platform_device *pdev)
{
struct msm_fb_data_type *mfd;
mfd = (struct msm_fb_data_type *)platform_get_drvdata(pdev);
if (!mfd)
return 0;
if (mfd->key != MFD_KEY)
return 0;
iounmap(mfd->cmd_port);
return 0;
}
static int ebi2_lcd_register_driver(void)
{
return platform_driver_register(&ebi2_lcd_driver);
}
static int __init ebi2_lcd_driver_init(void)
{
return ebi2_lcd_register_driver();
}
