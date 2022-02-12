static inline void venc_write_reg(int idx, u32 val)
{
__raw_writel(val, venc.base + idx);
}
static inline u32 venc_read_reg(int idx)
{
u32 l = __raw_readl(venc.base + idx);
return l;
}
static void venc_write_config(const struct venc_config *config)
{
DSSDBG("write venc conf\n");
venc_write_reg(VENC_LLEN, config->llen);
venc_write_reg(VENC_FLENS, config->flens);
venc_write_reg(VENC_CC_CARR_WSS_CARR, config->cc_carr_wss_carr);
venc_write_reg(VENC_C_PHASE, config->c_phase);
venc_write_reg(VENC_GAIN_U, config->gain_u);
venc_write_reg(VENC_GAIN_V, config->gain_v);
venc_write_reg(VENC_GAIN_Y, config->gain_y);
venc_write_reg(VENC_BLACK_LEVEL, config->black_level);
venc_write_reg(VENC_BLANK_LEVEL, config->blank_level);
venc_write_reg(VENC_M_CONTROL, config->m_control);
venc_write_reg(VENC_BSTAMP_WSS_DATA, config->bstamp_wss_data |
venc.wss_data);
venc_write_reg(VENC_S_CARR, config->s_carr);
venc_write_reg(VENC_L21__WC_CTL, config->l21__wc_ctl);
venc_write_reg(VENC_SAVID__EAVID, config->savid__eavid);
venc_write_reg(VENC_FLEN__FAL, config->flen__fal);
venc_write_reg(VENC_LAL__PHASE_RESET, config->lal__phase_reset);
venc_write_reg(VENC_HS_INT_START_STOP_X, config->hs_int_start_stop_x);
venc_write_reg(VENC_HS_EXT_START_STOP_X, config->hs_ext_start_stop_x);
venc_write_reg(VENC_VS_INT_START_X, config->vs_int_start_x);
venc_write_reg(VENC_VS_INT_STOP_X__VS_INT_START_Y,
config->vs_int_stop_x__vs_int_start_y);
venc_write_reg(VENC_VS_INT_STOP_Y__VS_EXT_START_X,
config->vs_int_stop_y__vs_ext_start_x);
venc_write_reg(VENC_VS_EXT_STOP_X__VS_EXT_START_Y,
config->vs_ext_stop_x__vs_ext_start_y);
venc_write_reg(VENC_VS_EXT_STOP_Y, config->vs_ext_stop_y);
venc_write_reg(VENC_AVID_START_STOP_X, config->avid_start_stop_x);
venc_write_reg(VENC_AVID_START_STOP_Y, config->avid_start_stop_y);
venc_write_reg(VENC_FID_INT_START_X__FID_INT_START_Y,
config->fid_int_start_x__fid_int_start_y);
venc_write_reg(VENC_FID_INT_OFFSET_Y__FID_EXT_START_X,
config->fid_int_offset_y__fid_ext_start_x);
venc_write_reg(VENC_FID_EXT_START_Y__FID_EXT_OFFSET_Y,
config->fid_ext_start_y__fid_ext_offset_y);
venc_write_reg(VENC_DAC_B__DAC_C, venc_read_reg(VENC_DAC_B__DAC_C));
venc_write_reg(VENC_VIDOUT_CTRL, config->vidout_ctrl);
venc_write_reg(VENC_HFLTR_CTRL, config->hfltr_ctrl);
venc_write_reg(VENC_X_COLOR, config->x_color);
venc_write_reg(VENC_LINE21, config->line21);
venc_write_reg(VENC_LN_SEL, config->ln_sel);
venc_write_reg(VENC_HTRIGGER_VTRIGGER, config->htrigger_vtrigger);
venc_write_reg(VENC_TVDETGP_INT_START_STOP_X,
config->tvdetgp_int_start_stop_x);
venc_write_reg(VENC_TVDETGP_INT_START_STOP_Y,
config->tvdetgp_int_start_stop_y);
venc_write_reg(VENC_GEN_CTRL, config->gen_ctrl);
venc_write_reg(VENC_F_CONTROL, config->f_control);
venc_write_reg(VENC_SYNC_CTRL, config->sync_ctrl);
}
static void venc_reset(void)
{
int t = 1000;
venc_write_reg(VENC_F_CONTROL, 1<<8);
while (venc_read_reg(VENC_F_CONTROL) & (1<<8)) {
if (--t == 0) {
DSSERR("Failed to reset venc\n");
return;
}
}
#ifdef CONFIG_OMAP2_DSS_SLEEP_AFTER_VENC_RESET
msleep(20);
#endif
}
static int venc_runtime_get(void)
{
int r;
DSSDBG("venc_runtime_get\n");
r = pm_runtime_get_sync(&venc.pdev->dev);
WARN_ON(r < 0);
return r < 0 ? r : 0;
}
static void venc_runtime_put(void)
{
int r;
DSSDBG("venc_runtime_put\n");
r = pm_runtime_put(&venc.pdev->dev);
WARN_ON(r < 0);
}
static const struct venc_config *venc_timings_to_config(
struct omap_video_timings *timings)
{
if (memcmp(&omap_dss_pal_timings, timings, sizeof(*timings)) == 0)
return &venc_config_pal_trm;
if (memcmp(&omap_dss_ntsc_timings, timings, sizeof(*timings)) == 0)
return &venc_config_ntsc_trm;
BUG();
}
static void venc_power_on(struct omap_dss_device *dssdev)
{
u32 l;
venc_reset();
venc_write_config(venc_timings_to_config(&dssdev->panel.timings));
dss_set_venc_output(dssdev->phy.venc.type);
dss_set_dac_pwrdn_bgz(1);
l = 0;
if (dssdev->phy.venc.type == OMAP_DSS_VENC_TYPE_COMPOSITE)
l |= 1 << 1;
else
l |= (1 << 0) | (1 << 2);
if (dssdev->phy.venc.invert_polarity == false)
l |= 1 << 3;
venc_write_reg(VENC_OUTPUT_CONTROL, l);
dispc_set_digit_size(dssdev->panel.timings.x_res,
dssdev->panel.timings.y_res/2);
regulator_enable(venc.vdda_dac_reg);
if (dssdev->platform_enable)
dssdev->platform_enable(dssdev);
dssdev->manager->enable(dssdev->manager);
}
static void venc_power_off(struct omap_dss_device *dssdev)
{
venc_write_reg(VENC_OUTPUT_CONTROL, 0);
dss_set_dac_pwrdn_bgz(0);
dssdev->manager->disable(dssdev->manager);
if (dssdev->platform_disable)
dssdev->platform_disable(dssdev);
regulator_disable(venc.vdda_dac_reg);
}
static int venc_panel_probe(struct omap_dss_device *dssdev)
{
dssdev->panel.timings = omap_dss_pal_timings;
return 0;
}
static void venc_panel_remove(struct omap_dss_device *dssdev)
{
}
static int venc_panel_enable(struct omap_dss_device *dssdev)
{
int r = 0;
DSSDBG("venc_enable_display\n");
mutex_lock(&venc.venc_lock);
r = omap_dss_start_device(dssdev);
if (r) {
DSSERR("failed to start device\n");
goto err0;
}
if (dssdev->state != OMAP_DSS_DISPLAY_DISABLED) {
r = -EINVAL;
goto err1;
}
r = venc_runtime_get();
if (r)
goto err1;
venc_power_on(dssdev);
venc.wss_data = 0;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
mutex_unlock(&venc.venc_lock);
return 0;
err1:
omap_dss_stop_device(dssdev);
err0:
mutex_unlock(&venc.venc_lock);
return r;
}
static void venc_panel_disable(struct omap_dss_device *dssdev)
{
DSSDBG("venc_disable_display\n");
mutex_lock(&venc.venc_lock);
if (dssdev->state == OMAP_DSS_DISPLAY_DISABLED)
goto end;
if (dssdev->state == OMAP_DSS_DISPLAY_SUSPENDED) {
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
goto end;
}
venc_power_off(dssdev);
venc_runtime_put();
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
omap_dss_stop_device(dssdev);
end:
mutex_unlock(&venc.venc_lock);
}
static int venc_panel_suspend(struct omap_dss_device *dssdev)
{
venc_panel_disable(dssdev);
return 0;
}
static int venc_panel_resume(struct omap_dss_device *dssdev)
{
return venc_panel_enable(dssdev);
}
static void venc_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
*timings = dssdev->panel.timings;
}
static void venc_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
DSSDBG("venc_set_timings\n");
if (memcmp(&dssdev->panel.timings, timings, sizeof(*timings)))
venc.wss_data = 0;
dssdev->panel.timings = *timings;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE) {
venc_panel_disable(dssdev);
venc_panel_enable(dssdev);
}
}
static int venc_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
DSSDBG("venc_check_timings\n");
if (memcmp(&omap_dss_pal_timings, timings, sizeof(*timings)) == 0)
return 0;
if (memcmp(&omap_dss_ntsc_timings, timings, sizeof(*timings)) == 0)
return 0;
return -EINVAL;
}
static u32 venc_get_wss(struct omap_dss_device *dssdev)
{
return (venc.wss_data >> 8) ^ 0xfffff;
}
static int venc_set_wss(struct omap_dss_device *dssdev, u32 wss)
{
const struct venc_config *config;
int r;
DSSDBG("venc_set_wss\n");
mutex_lock(&venc.venc_lock);
config = venc_timings_to_config(&dssdev->panel.timings);
venc.wss_data = (wss ^ 0xfffff) << 8;
r = venc_runtime_get();
if (r)
goto err;
venc_write_reg(VENC_BSTAMP_WSS_DATA, config->bstamp_wss_data |
venc.wss_data);
venc_runtime_put();
err:
mutex_unlock(&venc.venc_lock);
return r;
}
int venc_init_display(struct omap_dss_device *dssdev)
{
DSSDBG("init_display\n");
if (venc.vdda_dac_reg == NULL) {
struct regulator *vdda_dac;
vdda_dac = regulator_get(&venc.pdev->dev, "vdda_dac");
if (IS_ERR(vdda_dac)) {
DSSERR("can't get VDDA_DAC regulator\n");
return PTR_ERR(vdda_dac);
}
venc.vdda_dac_reg = vdda_dac;
}
return 0;
}
void venc_dump_regs(struct seq_file *s)
{
#define DUMPREG(r) seq_printf(s, "%-35s %08x\n", #r, venc_read_reg(r))
if (venc_runtime_get())
return;
DUMPREG(VENC_F_CONTROL);
DUMPREG(VENC_VIDOUT_CTRL);
DUMPREG(VENC_SYNC_CTRL);
DUMPREG(VENC_LLEN);
DUMPREG(VENC_FLENS);
DUMPREG(VENC_HFLTR_CTRL);
DUMPREG(VENC_CC_CARR_WSS_CARR);
DUMPREG(VENC_C_PHASE);
DUMPREG(VENC_GAIN_U);
DUMPREG(VENC_GAIN_V);
DUMPREG(VENC_GAIN_Y);
DUMPREG(VENC_BLACK_LEVEL);
DUMPREG(VENC_BLANK_LEVEL);
DUMPREG(VENC_X_COLOR);
DUMPREG(VENC_M_CONTROL);
DUMPREG(VENC_BSTAMP_WSS_DATA);
DUMPREG(VENC_S_CARR);
DUMPREG(VENC_LINE21);
DUMPREG(VENC_LN_SEL);
DUMPREG(VENC_L21__WC_CTL);
DUMPREG(VENC_HTRIGGER_VTRIGGER);
DUMPREG(VENC_SAVID__EAVID);
DUMPREG(VENC_FLEN__FAL);
DUMPREG(VENC_LAL__PHASE_RESET);
DUMPREG(VENC_HS_INT_START_STOP_X);
DUMPREG(VENC_HS_EXT_START_STOP_X);
DUMPREG(VENC_VS_INT_START_X);
DUMPREG(VENC_VS_INT_STOP_X__VS_INT_START_Y);
DUMPREG(VENC_VS_INT_STOP_Y__VS_EXT_START_X);
DUMPREG(VENC_VS_EXT_STOP_X__VS_EXT_START_Y);
DUMPREG(VENC_VS_EXT_STOP_Y);
DUMPREG(VENC_AVID_START_STOP_X);
DUMPREG(VENC_AVID_START_STOP_Y);
DUMPREG(VENC_FID_INT_START_X__FID_INT_START_Y);
DUMPREG(VENC_FID_INT_OFFSET_Y__FID_EXT_START_X);
DUMPREG(VENC_FID_EXT_START_Y__FID_EXT_OFFSET_Y);
DUMPREG(VENC_TVDETGP_INT_START_STOP_X);
DUMPREG(VENC_TVDETGP_INT_START_STOP_Y);
DUMPREG(VENC_GEN_CTRL);
DUMPREG(VENC_OUTPUT_CONTROL);
DUMPREG(VENC_OUTPUT_TEST);
venc_runtime_put();
#undef DUMPREG
}
static int venc_get_clocks(struct platform_device *pdev)
{
struct clk *clk;
clk = clk_get(&pdev->dev, "fck");
if (IS_ERR(clk)) {
DSSERR("can't get fck\n");
return PTR_ERR(clk);
}
venc.tv_clk = clk;
if (dss_has_feature(FEAT_VENC_REQUIRES_TV_DAC_CLK)) {
if (cpu_is_omap34xx() || cpu_is_omap3630())
clk = clk_get(&pdev->dev, "dss_96m_fck");
else
clk = clk_get(&pdev->dev, "tv_dac_clk");
if (IS_ERR(clk)) {
DSSERR("can't get tv_dac_clk\n");
clk_put(venc.tv_clk);
return PTR_ERR(clk);
}
} else {
clk = NULL;
}
venc.tv_dac_clk = clk;
return 0;
}
static void venc_put_clocks(void)
{
if (venc.tv_clk)
clk_put(venc.tv_clk);
if (venc.tv_dac_clk)
clk_put(venc.tv_dac_clk);
}
static int omap_venchw_probe(struct platform_device *pdev)
{
u8 rev_id;
struct resource *venc_mem;
int r;
venc.pdev = pdev;
mutex_init(&venc.venc_lock);
venc.wss_data = 0;
venc_mem = platform_get_resource(venc.pdev, IORESOURCE_MEM, 0);
if (!venc_mem) {
DSSERR("can't get IORESOURCE_MEM VENC\n");
r = -EINVAL;
goto err_ioremap;
}
venc.base = ioremap(venc_mem->start, resource_size(venc_mem));
if (!venc.base) {
DSSERR("can't ioremap VENC\n");
r = -ENOMEM;
goto err_ioremap;
}
r = venc_get_clocks(pdev);
if (r)
goto err_get_clk;
pm_runtime_enable(&pdev->dev);
r = venc_runtime_get();
if (r)
goto err_get_venc;
rev_id = (u8)(venc_read_reg(VENC_REV_ID) & 0xff);
dev_dbg(&pdev->dev, "OMAP VENC rev %d\n", rev_id);
venc_runtime_put();
return omap_dss_register_driver(&venc_driver);
err_get_venc:
pm_runtime_disable(&pdev->dev);
venc_put_clocks();
err_get_clk:
iounmap(venc.base);
err_ioremap:
return r;
}
static int omap_venchw_remove(struct platform_device *pdev)
{
if (venc.vdda_dac_reg != NULL) {
regulator_put(venc.vdda_dac_reg);
venc.vdda_dac_reg = NULL;
}
omap_dss_unregister_driver(&venc_driver);
pm_runtime_disable(&pdev->dev);
venc_put_clocks();
iounmap(venc.base);
return 0;
}
static int venc_runtime_suspend(struct device *dev)
{
if (venc.tv_dac_clk)
clk_disable(venc.tv_dac_clk);
clk_disable(venc.tv_clk);
dispc_runtime_put();
dss_runtime_put();
return 0;
}
static int venc_runtime_resume(struct device *dev)
{
int r;
r = dss_runtime_get();
if (r < 0)
goto err_get_dss;
r = dispc_runtime_get();
if (r < 0)
goto err_get_dispc;
clk_enable(venc.tv_clk);
if (venc.tv_dac_clk)
clk_enable(venc.tv_dac_clk);
return 0;
err_get_dispc:
dss_runtime_put();
err_get_dss:
return r;
}
int venc_init_platform_driver(void)
{
if (cpu_is_omap44xx())
return 0;
return platform_driver_register(&omap_venchw_driver);
}
void venc_uninit_platform_driver(void)
{
if (cpu_is_omap44xx())
return;
return platform_driver_unregister(&omap_venchw_driver);
}
