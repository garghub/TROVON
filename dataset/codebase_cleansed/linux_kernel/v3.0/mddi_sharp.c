static void sub_through_write(int sub_rs, uint32 sub_data)
{
mddi_queue_register_write(REG_SUBTCMDD, sub_data, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x000e | sub_rs, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x0006 | sub_rs, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x0004 | sub_rs, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x0006 | sub_rs, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x000e | sub_rs, TRUE, 0);
}
static uint32 sub_through_read(int sub_rs)
{
uint32 sub_data;
mddi_queue_register_write(REG_SUBTCMD, 0x000e | sub_rs, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x0006 | sub_rs, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x0002 | sub_rs, TRUE, 0);
mddi_queue_register_read(REG_SUBTCMDD, &sub_data, TRUE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x0006 | sub_rs, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x000e | sub_rs, TRUE, 0);
return sub_data;
}
static void serigo(uint32 ssd)
{
uint32 ssdctl;
mddi_queue_register_read(REG_SSDCTL, &ssdctl, TRUE, 0);
ssdctl = ((ssdctl & 0xE7) | 0x02);
mddi_queue_register_write(REG_SSD0, ssd, FALSE, 0);
mddi_queue_register_write(REG_SSDCTL, ssdctl, TRUE, 0);
do {
mddi_queue_register_read(REG_SSDCTL, &ssdctl, TRUE, 0);
} while ((ssdctl & 0x0002) != 0);
if (mddi_debug_prim_wait)
mddi_wait(2);
}
static void mddi_sharp_lcd_powerdown(void)
{
serigo(0x0131);
serigo(0x0300);
mddi_wait(40);
serigo(0x0135);
mddi_wait(20);
serigo(0x2122);
mddi_wait(20);
serigo(0x0201);
mddi_wait(20);
serigo(0x2100);
mddi_wait(20);
serigo(0x2000);
mddi_wait(20);
mddi_queue_register_write(REG_PSTCTL1, 0x1, TRUE, 0);
mddi_wait(100);
mddi_queue_register_write(REG_PSTCTL1, 0x0, TRUE, 0);
mddi_wait(2);
mddi_queue_register_write(REG_SYSCTL, 0x1, TRUE, 0);
mddi_wait(2);
mddi_queue_register_write(REG_CLKDIV1, 0x3, TRUE, 0);
mddi_wait(2);
mddi_queue_register_write(REG_SSDCTL, 0x0000, TRUE, 0);
mddi_queue_register_write(REG_SYSCTL, 0x0, TRUE, 0);
mddi_wait(2);
}
static void mddi_sharp_lcd_set_backlight(struct msm_fb_data_type *mfd)
{
uint32 regdata;
int32 level;
int max = mfd->panel_info.bl_max;
int min = mfd->panel_info.bl_min;
if (mddi_sharp_pdata && mddi_sharp_pdata->backlight_level) {
level = mddi_sharp_pdata->backlight_level(mfd->bl_level,
max,
min);
if (level < 0)
return;
mddi_queue_register_read(REG_GIOA, &regdata, TRUE, 0);
mddi_queue_register_write(REG_GIOA, regdata & 0xfff8, TRUE, 0);
mddi_queue_register_read(REG_GIOD, &regdata, TRUE, 0);
mddi_queue_register_write(REG_GIOD,
(regdata & 0xfff8) | (0x07 & level), TRUE, 0);
}
}
static void mddi_sharp_prim_lcd_init(void)
{
mddi_queue_register_write(REG_SYSCTL, 0x4000, TRUE, 0);
mddi_wait(1);
mddi_queue_register_write(REG_SYSCTL, 0x0000, TRUE, 0);
mddi_wait(5);
mddi_queue_register_write(REG_SYSCTL, 0x0001, FALSE, 0);
mddi_queue_register_write(REG_CLKDIV1, 0x000b, FALSE, 0);
if (mddi_sharp_debug_60hz_refresh)
mddi_queue_register_write(REG_CLKCNF, 0x070d, FALSE, 0);
else
mddi_queue_register_write(REG_CLKCNF, 0x0708, FALSE, 0);
mddi_queue_register_write(REG_SYSCTL, 0x0201, FALSE, 0);
mddi_queue_register_write(REG_PTGCTL, 0x0010, FALSE, 0);
mddi_queue_register_write(REG_PTHP, 4, FALSE, 0);
mddi_queue_register_write(REG_PTHB, 40, FALSE, 0);
mddi_queue_register_write(REG_PTHW, 240, FALSE, 0);
if (mddi_sharp_debug_60hz_refresh)
mddi_queue_register_write(REG_PTHF, 12, FALSE, 0);
else
mddi_queue_register_write(REG_PTHF, 92, FALSE, 0);
mddi_wait(1);
mddi_queue_register_write(REG_PTVP, 1, FALSE, 0);
mddi_queue_register_write(REG_PTVB, 2, FALSE, 0);
mddi_queue_register_write(REG_PTVW, 320, FALSE, 0);
mddi_queue_register_write(REG_PTVF, 15, FALSE, 0);
mddi_wait(1);
mddi_queue_register_write(REG_AGM, 0x0000, TRUE, 0);
mddi_queue_register_write(REG_SSDCTL, 0x0000, FALSE, 0);
mddi_queue_register_write(REG_SSDCTL, 0x0001, TRUE, 0);
mddi_wait(1);
mddi_queue_register_write(REG_PSTCTL1, 0x0001, TRUE, 0);
mddi_wait(10);
serigo(0x0701);
mddi_wait(1);
serigo(0x0400);
serigo(0x2900);
serigo(0x2606);
mddi_wait(20);
serigo(0x0503);
serigo(0x062C);
serigo(0x2001);
mddi_wait(20);
serigo(0x2120);
mddi_wait(20);
serigo(0x2130);
mddi_wait(20);
serigo(0x2132);
mddi_wait(10);
serigo(0x2133);
mddi_wait(20);
serigo(0x0200);
mddi_wait(1);
serigo(0x0131);
mddi_wait(1);
mddi_queue_register_write(REG_PSTCTL1, 0x0003, TRUE, 0);
serigo(0x0130);
mddi_wait(1);
if (mddi_sharp_vsync_wake) {
mddi_queue_register_write(REG_VBLKS, 0x1001, TRUE, 0);
mddi_queue_register_write(REG_VBLKE, 0x1002, TRUE, 0);
}
mddi_host_write_pix_attr_reg(0x00C3);
return;
}
void mddi_sharp_sub_lcd_init(void)
{
mddi_queue_register_write(REG_SYSCTL, 0x4000, FALSE, 0);
mddi_queue_register_write(REG_SYSCTL, 0x0000, TRUE, 0);
mddi_wait(100);
mddi_queue_register_write(REG_SYSCTL, 0x0001, FALSE, 0);
mddi_queue_register_write(REG_CLKDIV1, 0x000b, FALSE, 0);
mddi_queue_register_write(REG_CLKCNF, 0x0708, FALSE, 0);
mddi_queue_register_write(REG_SYSCTL, 0x0201, FALSE, 0);
mddi_queue_register_write(REG_PTGCTL, 0x0010, FALSE, 0);
mddi_queue_register_write(REG_PTHP, 4, FALSE, 0);
mddi_queue_register_write(REG_PTHB, 40, FALSE, 0);
mddi_queue_register_write(REG_PTHW, 128, FALSE, 0);
mddi_queue_register_write(REG_PTHF, 92, FALSE, 0);
mddi_queue_register_write(REG_PTVP, 1, FALSE, 0);
mddi_queue_register_write(REG_PTVB, 2, FALSE, 0);
mddi_queue_register_write(REG_PTVW, 128, FALSE, 0);
mddi_queue_register_write(REG_PTVF, 15, FALSE, 0);
mddi_queue_register_write(REG_SUBCTL, 0x0200, FALSE, 0);
mddi_queue_register_write(REG_SUBTCMD, 0x000f, TRUE, 0);
mddi_wait(1);
if (sharp_subpanel_type == SHARP_SUB_UNKNOWN) {
uint32 data;
sub_through_write(1, 0x05);
sub_through_write(1, 0x6A);
sub_through_write(1, 0x1D);
sub_through_write(1, 0x05);
data = sub_through_read(1);
if (data == 0x6A) {
sharp_subpanel_type = SHARP_SUB_HYNIX;
} else {
sub_through_write(0, 0x36);
sub_through_write(1, 0xA8);
sub_through_write(0, 0x09);
data = sub_through_read(1);
data = sub_through_read(1);
if (data == 0x54) {
sub_through_write(0, 0x36);
sub_through_write(1, 0x00);
sharp_subpanel_type = SHARP_SUB_ROHM;
}
}
}
if (sharp_subpanel_type == SHARP_SUB_HYNIX) {
sub_through_write(1, 0x00);
sub_through_write(1, 0x04);
sub_through_write(1, 0x01);
sub_through_write(1, 0x05);
sub_through_write(1, 0x0280);
sub_through_write(1, 0x0301);
sub_through_write(1, 0x0402);
sub_through_write(1, 0x0500);
sub_through_write(1, 0x0681);
sub_through_write(1, 0x077F);
sub_through_write(1, 0x08C0);
sub_through_write(1, 0x0905);
sub_through_write(1, 0x0A02);
sub_through_write(1, 0x0B00);
sub_through_write(1, 0x0C00);
sub_through_write(1, 0x0D00);
sub_through_write(1, 0x0E00);
sub_through_write(1, 0x0F00);
sub_through_write(1, 0x100B);
sub_through_write(1, 0x1103);
sub_through_write(1, 0x1237);
sub_through_write(1, 0x1300);
sub_through_write(1, 0x1400);
sub_through_write(1, 0x1500);
sub_through_write(1, 0x1605);
sub_through_write(1, 0x1700);
sub_through_write(1, 0x1800);
sub_through_write(1, 0x192E);
sub_through_write(1, 0x1A00);
sub_through_write(1, 0x1B00);
sub_through_write(1, 0x1C00);
sub_through_write(1, 0x151A);
sub_through_write(1, 0x2002);
sub_through_write(1, 0x2107);
sub_through_write(1, 0x220C);
sub_through_write(1, 0x2310);
sub_through_write(1, 0x2414);
sub_through_write(1, 0x2518);
sub_through_write(1, 0x261C);
sub_through_write(1, 0x2720);
sub_through_write(1, 0x2824);
sub_through_write(1, 0x2928);
sub_through_write(1, 0x2A2B);
sub_through_write(1, 0x2B2E);
sub_through_write(1, 0x2C31);
sub_through_write(1, 0x2D34);
sub_through_write(1, 0x2E37);
sub_through_write(1, 0x2F3A);
sub_through_write(1, 0x303C);
sub_through_write(1, 0x313E);
sub_through_write(1, 0x323F);
sub_through_write(1, 0x3340);
sub_through_write(1, 0x3441);
sub_through_write(1, 0x3543);
sub_through_write(1, 0x3646);
sub_through_write(1, 0x3749);
sub_through_write(1, 0x384C);
sub_through_write(1, 0x394F);
sub_through_write(1, 0x3A52);
sub_through_write(1, 0x3B59);
sub_through_write(1, 0x3C60);
sub_through_write(1, 0x3D67);
sub_through_write(1, 0x3E6E);
sub_through_write(1, 0x3F7F);
sub_through_write(1, 0x4001);
sub_through_write(1, 0x4107);
sub_through_write(1, 0x420C);
sub_through_write(1, 0x4310);
sub_through_write(1, 0x4414);
sub_through_write(1, 0x4518);
sub_through_write(1, 0x461C);
sub_through_write(1, 0x4720);
sub_through_write(1, 0x4824);
sub_through_write(1, 0x4928);
sub_through_write(1, 0x4A2B);
sub_through_write(1, 0x4B2E);
sub_through_write(1, 0x4C31);
sub_through_write(1, 0x4D34);
sub_through_write(1, 0x4E37);
sub_through_write(1, 0x4F3A);
sub_through_write(1, 0x503C);
sub_through_write(1, 0x513E);
sub_through_write(1, 0x523F);
sub_through_write(1, 0x5340);
sub_through_write(1, 0x5441);
sub_through_write(1, 0x5543);
sub_through_write(1, 0x5646);
sub_through_write(1, 0x5749);
sub_through_write(1, 0x584C);
sub_through_write(1, 0x594F);
sub_through_write(1, 0x5A52);
sub_through_write(1, 0x5B59);
sub_through_write(1, 0x5C60);
sub_through_write(1, 0x5D67);
sub_through_write(1, 0x5E6E);
sub_through_write(1, 0x5F7E);
sub_through_write(1, 0x6000);
sub_through_write(1, 0x6107);
sub_through_write(1, 0x620C);
sub_through_write(1, 0x6310);
sub_through_write(1, 0x6414);
sub_through_write(1, 0x6518);
sub_through_write(1, 0x661C);
sub_through_write(1, 0x6720);
sub_through_write(1, 0x6824);
sub_through_write(1, 0x6928);
sub_through_write(1, 0x6A2B);
sub_through_write(1, 0x6B2E);
sub_through_write(1, 0x6C31);
sub_through_write(1, 0x6D34);
sub_through_write(1, 0x6E37);
sub_through_write(1, 0x6F3A);
sub_through_write(1, 0x703C);
sub_through_write(1, 0x713E);
sub_through_write(1, 0x723F);
sub_through_write(1, 0x7340);
sub_through_write(1, 0x7441);
sub_through_write(1, 0x7543);
sub_through_write(1, 0x7646);
sub_through_write(1, 0x7749);
sub_through_write(1, 0x784C);
sub_through_write(1, 0x794F);
sub_through_write(1, 0x7A52);
sub_through_write(1, 0x7B59);
sub_through_write(1, 0x7C60);
sub_through_write(1, 0x7D67);
sub_through_write(1, 0x7E6E);
sub_through_write(1, 0x7F7D);
sub_through_write(1, 0x1851);
mddi_queue_register_write(REG_AGM, 0x0000, TRUE, 0);
mddi_queue_register_write(REG_CLKDIV2, 0x3b00, FALSE, 0);
mddi_queue_register_write(REG_PSTCTL2, 0x0080, FALSE, 0);
mddi_queue_register_write(REG_SUBCTL, 0x0202, FALSE, 0);
mddi_queue_register_write(REG_PSTCTL1, 0x0003, FALSE, 0);
} else if (sharp_subpanel_type == SHARP_SUB_ROHM) {
sub_through_write(0, 0x01);
sub_through_write(1, 0x00);
mddi_wait(1);
sub_through_write(0, 0xB6);
sub_through_write(1, 0x0C);
sub_through_write(1, 0x4A);
sub_through_write(1, 0x20);
sub_through_write(0, 0x3A);
sub_through_write(1, 0x05);
sub_through_write(0, 0xB7);
sub_through_write(1, 0x01);
sub_through_write(0, 0xBA);
sub_through_write(1, 0x20);
sub_through_write(1, 0x02);
sub_through_write(0, 0x25);
sub_through_write(1, 0x4F);
sub_through_write(0, 0xBB);
sub_through_write(1, 0x00);
sub_through_write(0, 0x36);
sub_through_write(1, 0x00);
sub_through_write(0, 0xB1);
sub_through_write(1, 0x05);
sub_through_write(0, 0xBE);
sub_through_write(1, 0x80);
sub_through_write(0, 0x26);
sub_through_write(1, 0x01);
sub_through_write(0, 0x2A);
sub_through_write(1, 0x02);
sub_through_write(1, 0x81);
sub_through_write(0, 0x2B);
sub_through_write(1, 0x00);
sub_through_write(1, 0x7F);
sub_through_write(0, 0x2C);
sub_through_write(0, 0x11);
mddi_wait(1);
sub_through_write(0, 0x29);
sub_through_write(0, 0xB3);
sub_through_write(1, 0x20);
sub_through_write(1, 0xAA);
sub_through_write(1, 0xA0);
sub_through_write(1, 0x20);
sub_through_write(1, 0x30);
sub_through_write(1, 0xA6);
sub_through_write(1, 0xFF);
sub_through_write(1, 0x9A);
sub_through_write(1, 0x9F);
sub_through_write(1, 0xAF);
sub_through_write(1, 0xBC);
sub_through_write(1, 0xCF);
sub_through_write(1, 0xDF);
sub_through_write(1, 0x20);
sub_through_write(1, 0x9C);
sub_through_write(1, 0x8A);
sub_through_write(0, 0x002C);
mddi_queue_register_write(REG_CLKDIV2, 0x7b00, FALSE, 0);
mddi_queue_register_write(REG_PSTCTL2, 0x0080, FALSE, 0);
mddi_queue_register_write(REG_SUBCTL, 0x0242, FALSE, 0);
mddi_queue_register_write(REG_PSTCTL1, 0x0003, FALSE, 0);
}
mddi_host_write_pix_attr_reg(0x00C0);
}
void mddi_sharp_lcd_vsync_detected(boolean detected)
{
static struct timeval start_time;
static boolean first_time = TRUE;
struct timeval now;
uint32 elapsed_us;
uint32 num_vsyncs;
if ((detected) || (mddi_sharp_vsync_attempts > 5)) {
if ((detected) && (mddi_sharp_monitor_refresh_value)) {
if (!first_time) {
jiffies_to_timeval(jiffies, &now);
elapsed_us =
(now.tv_sec - start_time.tv_sec) * 1000000 +
now.tv_usec - start_time.tv_usec;
num_vsyncs = (elapsed_us +
(mddi_sharp_usecs_per_refresh >>
1)) /
mddi_sharp_usecs_per_refresh;
mddi_sharp_rows_per_second =
(mddi_sharp_rows_per_refresh * 1000 *
num_vsyncs) / (elapsed_us / 1000);
}
first_time = FALSE;
jiffies_to_timeval(jiffies, &start_time);
if (mddi_sharp_report_refresh_measurements) {
}
}
if (mddi_sharp_vsync_handler != NULL) {
(*mddi_sharp_vsync_handler)
(mddi_sharp_vsync_handler_arg);
mddi_sharp_vsync_handler = NULL;
}
mddi_vsync_detect_enabled = FALSE;
mddi_sharp_vsync_attempts = 0;
if (!mddi_queue_register_write_int(REG_INTR, 0x0000)) {
MDDI_MSG_ERR("Vsync interrupt clear failed!\n");
}
if (!detected) {
MDDI_MSG_NOTICE("Vsync detection failed!\n");
} else if ((mddi_sharp_monitor_refresh_value) &&
(mddi_sharp_report_refresh_measurements)) {
MDDI_MSG_NOTICE(" Lines Per Second=%d!\n",
mddi_sharp_rows_per_second);
}
} else
mddi_sharp_vsync_attempts++;
}
void mddi_sharp_vsync_set_handler(msm_fb_vsync_handler_type handler, void *arg)
{
boolean error = FALSE;
unsigned long flags;
spin_lock_irqsave(&mddi_host_spin_lock, flags);
if (mddi_sharp_vsync_handler != NULL)
error = TRUE;
mddi_sharp_vsync_handler = handler;
mddi_sharp_vsync_handler_arg = arg;
spin_unlock_irqrestore(&mddi_host_spin_lock, flags);
if (error)
MDDI_MSG_ERR("MDDI: Previous Vsync handler never called\n");
mddi_queue_register_write(REG_INTR, 0x8100, FALSE, 0);
mddi_sharp_vsync_attempts = 1;
mddi_vsync_detect_enabled = TRUE;
}
static int mddi_sharp_lcd_on(struct platform_device *pdev)
{
struct msm_fb_data_type *mfd;
mfd = platform_get_drvdata(pdev);
if (!mfd)
return -ENODEV;
if (mfd->key != MFD_KEY)
return -EINVAL;
if (mfd->panel.id == SHARP_QVGA_PRIM)
mddi_sharp_prim_lcd_init();
else
mddi_sharp_sub_lcd_init();
return 0;
}
static int mddi_sharp_lcd_off(struct platform_device *pdev)
{
mddi_sharp_lcd_powerdown();
return 0;
}
static int __init mddi_sharp_probe(struct platform_device *pdev)
{
if (pdev->id == 0) {
mddi_sharp_pdata = pdev->dev.platform_data;
return 0;
}
msm_fb_add_device(pdev);
return 0;
}
static int __init mddi_sharp_init(void)
{
int ret;
struct msm_panel_info *pinfo;
#ifdef CONFIG_FB_MSM_MDDI_AUTO_DETECT
u32 id;
ret = msm_fb_detect_client("mddi_sharp_qvga");
if (ret == -ENODEV)
return 0;
if (ret) {
id = mddi_get_client_id();
if (((id >> 16) != 0x0) || ((id & 0xffff) != 0x8835))
return 0;
}
#endif
if (mddi_host_core_version > 8) {
mddi_sharp_debug_60hz_refresh = TRUE;
mddi_sharp_rows_per_second = 20270;
mddi_sharp_rows_per_refresh = 338;
mddi_sharp_usecs_per_refresh = 16674;
} else {
mddi_sharp_rows_per_second = 13830;
mddi_sharp_rows_per_refresh = 338;
mddi_sharp_usecs_per_refresh = 24440;
}
ret = platform_driver_register(&this_driver);
if (!ret) {
pinfo = &mddi_sharp_panel_data0.panel_info;
pinfo->xres = 240;
pinfo->yres = 320;
pinfo->type = MDDI_PANEL;
pinfo->pdest = DISPLAY_1;
pinfo->mddi.vdopkt = MDDI_DEFAULT_PRIM_PIX_ATTR;
pinfo->wait_cycle = 0;
pinfo->bpp = 18;
pinfo->fb_num = 2;
pinfo->clk_rate = 122880000;
pinfo->clk_min = 120000000;
pinfo->clk_max = 125000000;
pinfo->lcd.vsync_enable = TRUE;
pinfo->lcd.refx100 =
(mddi_sharp_rows_per_second * 100) /
mddi_sharp_rows_per_refresh;
pinfo->lcd.v_back_porch = 12;
pinfo->lcd.v_front_porch = 6;
pinfo->lcd.v_pulse_width = 0;
pinfo->lcd.hw_vsync_mode = FALSE;
pinfo->lcd.vsync_notifier_period = (1 * HZ);
pinfo->bl_max = 7;
pinfo->bl_min = 1;
ret = platform_device_register(&this_device_0);
if (ret)
platform_driver_unregister(&this_driver);
pinfo = &mddi_sharp_panel_data1.panel_info;
pinfo->xres = 128;
pinfo->yres = 128;
pinfo->type = MDDI_PANEL;
pinfo->pdest = DISPLAY_2;
pinfo->mddi.vdopkt = 0x400;
pinfo->wait_cycle = 0;
pinfo->bpp = 18;
pinfo->clk_rate = 122880000;
pinfo->clk_min = 120000000;
pinfo->clk_max = 125000000;
pinfo->fb_num = 2;
ret = platform_device_register(&this_device_1);
if (ret) {
platform_device_unregister(&this_device_0);
platform_driver_unregister(&this_driver);
}
}
if (!ret)
mddi_lcd.vsync_detected = mddi_sharp_lcd_vsync_detected;
return ret;
}
