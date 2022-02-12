static int tvenc_off(struct platform_device *pdev)
{
int ret = 0;
ret = panel_next_off(pdev);
clk_disable(tvenc_clk);
clk_disable(tvdac_clk);
if (tvenc_pdata && tvenc_pdata->pm_vid_en)
ret = tvenc_pdata->pm_vid_en(0);
if (ret)
printk(KERN_ERR "%s: pm_vid_en(off) failed! %d\n",
__func__, ret);
return ret;
}
static int tvenc_on(struct platform_device *pdev)
{
int ret = 0;
if (tvenc_pdata && tvenc_pdata->pm_vid_en)
ret = tvenc_pdata->pm_vid_en(1);
if (ret) {
printk(KERN_ERR "%s: pm_vid_en(on) failed! %d\n",
__func__, ret);
return ret;
}
clk_enable(tvenc_clk);
clk_enable(tvdac_clk);
ret = panel_next_on(pdev);
return ret;
}
void tvenc_gen_test_pattern(struct msm_fb_data_type *mfd)
{
uint32 reg = 0, i;
reg = readl(MSM_TV_ENC_CTL);
reg |= TVENC_CTL_TEST_PATT_EN;
for (i = 0; i < 3; i++) {
TV_OUT(TV_ENC_CTL, 0);
switch (i) {
case 0:
reg |= TVENC_CTL_TPG_CLRBAR;
break;
case 1:
reg |= TVENC_CTL_TPG_REDCLR;
break;
default:
reg |= TVENC_CTL_TPG_MODRAMP;
break;
}
TV_OUT(TV_ENC_CTL, reg);
mdelay(5000);
switch (i) {
case 0:
reg &= ~TVENC_CTL_TPG_CLRBAR;
break;
case 1:
reg &= ~TVENC_CTL_TPG_REDCLR;
break;
default:
reg &= ~TVENC_CTL_TPG_MODRAMP;
break;
}
}
}
static int tvenc_probe(struct platform_device *pdev)
{
struct msm_fb_data_type *mfd;
struct platform_device *mdp_dev = NULL;
struct msm_fb_panel_data *pdata = NULL;
int rc;
if (pdev->id == 0) {
tvenc_base = ioremap(pdev->resource[0].start,
pdev->resource[0].end -
pdev->resource[0].start + 1);
if (!tvenc_base) {
printk(KERN_ERR
"tvenc_base ioremap failed!\n");
return -ENOMEM;
}
tvenc_pdata = pdev->dev.platform_data;
tvenc_resource_initialized = 1;
return 0;
}
if (!tvenc_resource_initialized)
return -EPERM;
mfd = platform_get_drvdata(pdev);
if (!mfd)
return -ENODEV;
if (mfd->key != MFD_KEY)
return -EINVAL;
if (pdev_list_cnt >= MSM_FB_MAX_DEV_LIST)
return -ENOMEM;
if (tvenc_base == NULL)
return -ENOMEM;
mdp_dev = platform_device_alloc("mdp", pdev->id);
if (!mdp_dev)
return -ENOMEM;
mfd->pdev = mdp_dev;
mfd->dest = DISPLAY_TV;
if (platform_device_add_data
(mdp_dev, pdev->dev.platform_data,
sizeof(struct msm_fb_panel_data))) {
printk(KERN_ERR "tvenc_probe: platform_device_add_data failed!\n");
platform_device_put(mdp_dev);
return -ENOMEM;
}
pdata = mdp_dev->dev.platform_data;
pdata->on = tvenc_on;
pdata->off = tvenc_off;
pdata->next = pdev;
mfd->panel_info = pdata->panel_info;
mfd->fb_imgType = MDP_YCRYCB_H2V1;
platform_set_drvdata(mdp_dev, mfd);
rc = platform_device_add(mdp_dev);
if (rc)
goto tvenc_probe_err;
pdev_list[pdev_list_cnt++] = pdev;
return 0;
tvenc_probe_err:
platform_device_put(mdp_dev);
return rc;
}
static int tvenc_remove(struct platform_device *pdev)
{
return 0;
}
static int tvenc_register_driver(void)
{
return platform_driver_register(&tvenc_driver);
}
static int __init tvenc_driver_init(void)
{
tvenc_clk = clk_get(NULL, "tv_enc_clk");
tvdac_clk = clk_get(NULL, "tv_dac_clk");
if (IS_ERR(tvenc_clk)) {
printk(KERN_ERR "error: can't get tvenc_clk!\n");
return PTR_ERR(tvenc_clk);
}
if (IS_ERR(tvdac_clk)) {
printk(KERN_ERR "error: can't get tvdac_clk!\n");
clk_put(tvenc_clk);
return PTR_ERR(tvdac_clk);
}
return tvenc_register_driver();
}
