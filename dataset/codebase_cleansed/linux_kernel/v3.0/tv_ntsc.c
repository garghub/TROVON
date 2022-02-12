static int ntsc_on(struct platform_device *pdev)
{
uint32 reg = 0;
int ret = 0;
struct msm_fb_data_type *mfd;
mfd = platform_get_drvdata(pdev);
if (!mfd)
return -ENODEV;
if (mfd->key != MFD_KEY)
return -EINVAL;
TV_OUT(TV_ENC_CTL, 0);
if (mfd->panel.id == NTSC_M) {
TV_OUT(TV_GAIN, 0x0081B697);
} else {
TV_OUT(TV_GAIN, 0x008bc4a3);
reg |= TVENC_CTL_NTSCJ_MODE;
}
TV_OUT(TV_CGMS, 0x0);
TV_OUT(TV_SYNC_1, 0x0020009e);
TV_OUT(TV_SYNC_2, 0x011306B4);
TV_OUT(TV_SYNC_3, 0x0006000C);
TV_OUT(TV_SYNC_4, 0x0028020D);
TV_OUT(TV_SYNC_5, 0x005E02FB);
TV_OUT(TV_SYNC_6, 0x0006000C);
TV_OUT(TV_SYNC_7, 0x00000012);
TV_OUT(TV_BURST_V1, 0x0013020D);
TV_OUT(TV_BURST_V2, 0x0014020C);
TV_OUT(TV_BURST_V3, 0x0013020D);
TV_OUT(TV_BURST_V4, 0x0014020C);
TV_OUT(TV_BURST_H, 0x00AE00F2);
TV_OUT(TV_SOL_REQ_ODD, 0x00280208);
TV_OUT(TV_SOL_REQ_EVEN, 0x00290209);
reg |= TVENC_CTL_TV_MODE_NTSC_M_PAL60;
reg |= TVENC_CTL_Y_FILTER_EN |
TVENC_CTL_CR_FILTER_EN |
TVENC_CTL_CB_FILTER_EN | TVENC_CTL_SINX_FILTER_EN;
#ifdef CONFIG_FB_MSM_TVOUT_SVIDEO
reg |= TVENC_CTL_S_VIDEO_EN;
#endif
TV_OUT(TV_LEVEL, 0x00000000);
TV_OUT(TV_OFFSET, 0x008080f0);
#ifdef CONFIG_FB_MSM_MDP31
TV_OUT(TV_DAC_INTF, 0x29);
#endif
TV_OUT(TV_ENC_CTL, reg);
reg |= TVENC_CTL_ENC_EN;
TV_OUT(TV_ENC_CTL, reg);
return ret;
}
static int ntsc_off(struct platform_device *pdev)
{
TV_OUT(TV_ENC_CTL, 0);
return 0;
}
static int __init ntsc_probe(struct platform_device *pdev)
{
msm_fb_add_device(pdev);
return 0;
}
static int __init ntsc_init(void)
{
int ret;
ret = platform_driver_register(&this_driver);
if (!ret) {
ret = platform_device_register(&this_device);
if (ret)
platform_driver_unregister(&this_driver);
}
return ret;
}
