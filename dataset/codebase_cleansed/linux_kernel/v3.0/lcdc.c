static int lcdc_off(struct platform_device *pdev)
{
int ret = 0;
ret = panel_next_off(pdev);
clk_disable(mdp_lcdc_pclk_clk);
clk_disable(mdp_lcdc_pad_pclk_clk);
if (lcdc_pdata && lcdc_pdata->lcdc_power_save)
lcdc_pdata->lcdc_power_save(0);
if (lcdc_pdata && lcdc_pdata->lcdc_gpio_config)
ret = lcdc_pdata->lcdc_gpio_config(0);
return ret;
}
static int lcdc_on(struct platform_device *pdev)
{
int ret = 0;
struct msm_fb_data_type *mfd;
unsigned long panel_pixclock_freq , pm_qos_freq;
mfd = platform_get_drvdata(pdev);
panel_pixclock_freq = mfd->fbi->var.pixclock;
if (panel_pixclock_freq > 58000000)
pm_qos_freq = panel_pixclock_freq / 1000 ;
else
pm_qos_freq = 58000;
mfd = platform_get_drvdata(pdev);
clk_enable(mdp_lcdc_pclk_clk);
clk_enable(mdp_lcdc_pad_pclk_clk);
if (lcdc_pdata && lcdc_pdata->lcdc_power_save)
lcdc_pdata->lcdc_power_save(1);
if (lcdc_pdata && lcdc_pdata->lcdc_gpio_config)
ret = lcdc_pdata->lcdc_gpio_config(1);
clk_set_rate(mdp_lcdc_pclk_clk, mfd->fbi->var.pixclock);
clk_set_rate(mdp_lcdc_pad_pclk_clk, mfd->fbi->var.pixclock);
mdp_lcdc_pclk_clk_rate = clk_get_rate(mdp_lcdc_pclk_clk);
mdp_lcdc_pad_pclk_clk_rate = clk_get_rate(mdp_lcdc_pad_pclk_clk);
ret = panel_next_on(pdev);
return ret;
}
static int lcdc_probe(struct platform_device *pdev)
{
struct msm_fb_data_type *mfd;
struct fb_info *fbi;
struct platform_device *mdp_dev = NULL;
struct msm_fb_panel_data *pdata = NULL;
int rc;
if (pdev->id == 0) {
lcdc_pdata = pdev->dev.platform_data;
return 0;
}
mfd = platform_get_drvdata(pdev);
if (!mfd)
return -ENODEV;
if (mfd->key != MFD_KEY)
return -EINVAL;
if (pdev_list_cnt >= MSM_FB_MAX_DEV_LIST)
return -ENOMEM;
mdp_dev = platform_device_alloc("mdp", pdev->id);
if (!mdp_dev)
return -ENOMEM;
mfd->pdev = mdp_dev;
mfd->dest = DISPLAY_LCDC;
if (platform_device_add_data
(mdp_dev, pdev->dev.platform_data,
sizeof(struct msm_fb_panel_data))) {
printk(KERN_ERR "lcdc_probe: platform_device_add_data failed!\n");
platform_device_put(mdp_dev);
return -ENOMEM;
}
pdata = (struct msm_fb_panel_data *)mdp_dev->dev.platform_data;
pdata->on = lcdc_on;
pdata->off = lcdc_off;
pdata->next = pdev;
mfd->panel_info = pdata->panel_info;
mfd->fb_imgType = MDP_RGB_565;
fbi = mfd->fbi;
fbi->var.pixclock = mfd->panel_info.clk_rate;
fbi->var.left_margin = mfd->panel_info.lcdc.h_back_porch;
fbi->var.right_margin = mfd->panel_info.lcdc.h_front_porch;
fbi->var.upper_margin = mfd->panel_info.lcdc.v_back_porch;
fbi->var.lower_margin = mfd->panel_info.lcdc.v_front_porch;
fbi->var.hsync_len = mfd->panel_info.lcdc.h_pulse_width;
fbi->var.vsync_len = mfd->panel_info.lcdc.v_pulse_width;
platform_set_drvdata(mdp_dev, mfd);
rc = platform_device_add(mdp_dev);
if (rc)
goto lcdc_probe_err;
pdev_list[pdev_list_cnt++] = pdev;
return 0;
lcdc_probe_err:
platform_device_put(mdp_dev);
return rc;
}
static int lcdc_remove(struct platform_device *pdev)
{
return 0;
}
static int lcdc_register_driver(void)
{
return platform_driver_register(&lcdc_driver);
}
static int __init lcdc_driver_init(void)
{
mdp_lcdc_pclk_clk = clk_get(NULL, "mdp_lcdc_pclk_clk");
if (IS_ERR(mdp_lcdc_pclk_clk)) {
printk(KERN_ERR "error: can't get mdp_lcdc_pclk_clk!\n");
return PTR_ERR(mdp_lcdc_pclk_clk);
}
mdp_lcdc_pad_pclk_clk = clk_get(NULL, "mdp_lcdc_pad_pclk_clk");
if (IS_ERR(mdp_lcdc_pad_pclk_clk)) {
printk(KERN_ERR "error: can't get mdp_lcdc_pad_pclk_clk!\n");
return PTR_ERR(mdp_lcdc_pad_pclk_clk);
}
return lcdc_register_driver();
}
