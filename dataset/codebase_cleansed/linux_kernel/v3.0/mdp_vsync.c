void mdp_hw_vsync_clk_enable(struct msm_fb_data_type *mfd)
{
if (mfd->use_mdp_vsync)
clk_enable(mdp_vsync_clk);
}
void mdp_hw_vsync_clk_disable(struct msm_fb_data_type *mfd)
{
if (mfd->use_mdp_vsync)
clk_disable(mdp_vsync_clk);
}
static void mdp_set_vsync(unsigned long data)
{
struct msm_fb_data_type *mfd = (struct msm_fb_data_type *)data;
struct msm_fb_panel_data *pdata = NULL;
pdata = (struct msm_fb_panel_data *)mfd->pdev->dev.platform_data;
if ((pdata) && (pdata->set_vsync_notifier == NULL))
return;
init_timer(&mfd->vsync_resync_timer);
mfd->vsync_resync_timer.function = mdp_set_vsync;
mfd->vsync_resync_timer.data = data;
mfd->vsync_resync_timer.expires =
jiffies + mfd->panel_info.lcd.vsync_notifier_period;
add_timer(&mfd->vsync_resync_timer);
if ((mfd->panel_info.lcd.vsync_enable) && (mfd->panel_power_on)
&& (!mfd->vsync_handler_pending)) {
mfd->vsync_handler_pending = TRUE;
if (!queue_work(mdp_vsync_wq, &mfd->vsync_resync_worker)) {
MSM_FB_INFO
("mdp_set_vsync: can't queue_work! -> needs to increase vsync_resync_timer_duration\n");
}
} else {
MSM_FB_DEBUG
("mdp_set_vsync failed! EN:%d PWR:%d PENDING:%d\n",
mfd->panel_info.lcd.vsync_enable, mfd->panel_power_on,
mfd->vsync_handler_pending);
}
}
static void mdp_vsync_handler(void *data)
{
struct msm_fb_data_type *mfd = (struct msm_fb_data_type *)data;
if (mfd->use_mdp_vsync) {
#ifdef MDP_HW_VSYNC
if (mfd->panel_power_on)
MDP_OUTP(MDP_BASE + MDP_SYNC_STATUS_0, vsync_load_cnt);
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_OFF, TRUE);
#endif
} else {
mfd->last_vsync_timetick = ktime_get_real();
}
mfd->vsync_handler_pending = FALSE;
}
irqreturn_t mdp_hw_vsync_handler_proxy(int irq, void *data)
{
mdp_vsync_handler(data);
return IRQ_HANDLED;
}
static void mdp_set_sync_cfg_0(struct msm_fb_data_type *mfd, int vsync_cnt)
{
unsigned long cfg;
cfg = mfd->total_lcd_lines - 1;
cfg <<= MDP_SYNCFG_HGT_LOC;
if (mfd->panel_info.lcd.hw_vsync_mode)
cfg |= MDP_SYNCFG_VSYNC_EXT_EN;
cfg |= (MDP_SYNCFG_VSYNC_INT_EN | vsync_cnt);
MDP_OUTP(MDP_BASE + MDP_SYNC_CFG_0, cfg);
}
void mdp_config_vsync(struct msm_fb_data_type *mfd)
{
if ((mfd->dest != DISPLAY_LCD) || (mfd->panel_info.pdest != DISPLAY_1)
|| (!vsync_mode)) {
goto err_handle;
}
if (mfd->panel_info.lcd.vsync_enable) {
mfd->total_porch_lines = mfd->panel_info.lcd.v_back_porch +
mfd->panel_info.lcd.v_front_porch +
mfd->panel_info.lcd.v_pulse_width;
mfd->total_lcd_lines =
mfd->panel_info.yres + mfd->total_porch_lines;
mfd->lcd_ref_usec_time =
100000000 / mfd->panel_info.lcd.refx100;
mfd->vsync_handler_pending = FALSE;
mfd->last_vsync_timetick.tv.sec = 0;
mfd->last_vsync_timetick.tv.nsec = 0;
#ifdef MDP_HW_VSYNC
if (mdp_vsync_clk == NULL)
mdp_vsync_clk = clk_get(NULL, "mdp_vsync_clk");
if (IS_ERR(mdp_vsync_clk)) {
printk(KERN_ERR "error: can't get mdp_vsync_clk!\n");
mfd->use_mdp_vsync = 0;
} else
mfd->use_mdp_vsync = 1;
if (mfd->use_mdp_vsync) {
uint32 vsync_cnt_cfg, vsync_cnt_cfg_dem;
uint32 mdp_vsync_clk_speed_hz;
mdp_vsync_clk_speed_hz = clk_get_rate(mdp_vsync_clk);
if (mdp_vsync_clk_speed_hz == 0) {
mfd->use_mdp_vsync = 0;
} else {
vsync_cnt_cfg_dem =
(mfd->panel_info.lcd.refx100 *
mfd->total_lcd_lines) / 100;
vsync_cnt_cfg =
(mdp_vsync_clk_speed_hz) /
vsync_cnt_cfg_dem;
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON,
FALSE);
mdp_hw_vsync_clk_enable(mfd);
mdp_set_sync_cfg_0(mfd, vsync_cnt_cfg);
vsync_load_cnt = mfd->panel_info.yres;
MDP_OUTP(MDP_BASE + MDP_PRIM_VSYNC_INIT_VAL,
vsync_load_cnt);
MDP_OUTP(MDP_BASE + MDP_PRIM_VSYNC_OUT_CTRL,
BIT(30) | BIT(0));
MDP_OUTP(MDP_BASE + 0x200,
(vsync_above_th << 16) |
(vsync_start_th));
mdp_hw_vsync_clk_disable(mfd);
mdp_pipe_ctrl(MDP_CMD_BLOCK,
MDP_BLOCK_POWER_OFF, FALSE);
}
}
#else
mfd->use_mdp_vsync = 0;
hrtimer_init(&mfd->dma_hrtimer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
mfd->dma_hrtimer.function = mdp_dma2_vsync_hrtimer_handler;
mfd->vsync_width_boundary = vmalloc(mfd->panel_info.xres * 4);
#endif
mfd->channel_irq = 0;
if (mfd->panel_info.lcd.hw_vsync_mode) {
u32 vsync_gpio = mfd->vsync_gpio;
u32 ret;
if (vsync_gpio == -1) {
MSM_FB_INFO("vsync_gpio not defined!\n");
goto err_handle;
}
ret = gpio_tlmm_config(GPIO_CFG
(vsync_gpio,
(mfd->use_mdp_vsync) ? 1 : 0,
GPIO_INPUT,
GPIO_PULL_DOWN,
GPIO_2MA),
GPIO_ENABLE);
if (ret)
goto err_handle;
if (!mfd->use_mdp_vsync) {
mfd->channel_irq = MSM_GPIO_TO_INT(vsync_gpio);
if (request_irq
(mfd->channel_irq,
&mdp_hw_vsync_handler_proxy,
IRQF_TRIGGER_FALLING, "VSYNC_GPIO",
(void *)mfd)) {
MSM_FB_INFO
("irq=%d failed! vsync_gpio=%d\n",
mfd->channel_irq,
vsync_gpio);
goto err_handle;
}
}
}
mdp_set_vsync((unsigned long)mfd);
}
return;
err_handle:
if (mfd->vsync_width_boundary)
vfree(mfd->vsync_width_boundary);
mfd->panel_info.lcd.vsync_enable = FALSE;
printk(KERN_ERR "%s: failed!\n", __func__);
}
void mdp_vsync_resync_workqueue_handler(struct work_struct *work)
{
struct msm_fb_data_type *mfd = NULL;
int vsync_fnc_enabled = FALSE;
struct msm_fb_panel_data *pdata = NULL;
mfd = container_of(work, struct msm_fb_data_type, vsync_resync_worker);
if (mfd) {
if (mfd->panel_power_on) {
pdata =
(struct msm_fb_panel_data *)mfd->pdev->dev.
platform_data;
if ((!mfd->panel_info.lcd.hw_vsync_mode) &&
(mfd->use_mdp_vsync) &&
(pdata) && (pdata->set_vsync_notifier != NULL)) {
mdp_pipe_ctrl(MDP_CMD_BLOCK, MDP_BLOCK_POWER_ON,
FALSE);
}
if (pdata->set_vsync_notifier != NULL) {
vsync_fnc_enabled = TRUE;
pdata->set_vsync_notifier(mdp_vsync_handler,
(void *)mfd);
}
}
}
if ((mfd) && (!vsync_fnc_enabled))
mfd->vsync_handler_pending = FALSE;
}
boolean mdp_hw_vsync_set_handler(msm_fb_vsync_handler_type handler, void *data)
{
return TRUE;
}
uint32 mdp_get_lcd_line_counter(struct msm_fb_data_type *mfd)
{
uint32 elapsed_usec_time;
uint32 lcd_line;
ktime_t last_vsync_timetick_local;
ktime_t curr_time;
unsigned long flag;
if ((!mfd->panel_info.lcd.vsync_enable) || (!vsync_mode))
return 0;
spin_lock_irqsave(&mdp_spin_lock, flag);
last_vsync_timetick_local = mfd->last_vsync_timetick;
spin_unlock_irqrestore(&mdp_spin_lock, flag);
curr_time = ktime_get_real();
elapsed_usec_time =
((curr_time.tv.sec - last_vsync_timetick_local.tv.sec) * 1000000) +
((curr_time.tv.nsec - last_vsync_timetick_local.tv.nsec) / 1000);
elapsed_usec_time = elapsed_usec_time % mfd->lcd_ref_usec_time;
lcd_line =
(elapsed_usec_time * mfd->total_lcd_lines) / mfd->lcd_ref_usec_time;
lcd_line =
(mfd->total_lcd_lines - mfd->panel_info.lcd.v_back_porch +
lcd_line) % (mfd->total_lcd_lines + 1);
if (lcd_line > mfd->total_lcd_lines) {
MSM_FB_INFO
("mdp_get_lcd_line_counter: mdp_lcd_rd_cnt >= mfd->total_lcd_lines error!\n");
}
return lcd_line;
}
