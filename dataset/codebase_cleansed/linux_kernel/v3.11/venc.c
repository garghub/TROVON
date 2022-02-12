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
r = pm_runtime_put_sync(&venc.pdev->dev);
WARN_ON(r < 0 && r != -ENOSYS);
}
static const struct venc_config *venc_timings_to_config(
struct omap_video_timings *timings)
{
if (memcmp(&omap_dss_pal_timings, timings, sizeof(*timings)) == 0)
return &venc_config_pal_trm;
if (memcmp(&omap_dss_ntsc_timings, timings, sizeof(*timings)) == 0)
return &venc_config_ntsc_trm;
BUG();
return NULL;
}
static int venc_power_on(struct omap_dss_device *dssdev)
{
struct omap_overlay_manager *mgr = venc.output.manager;
u32 l;
int r;
r = venc_runtime_get();
if (r)
goto err0;
venc_reset();
venc_write_config(venc_timings_to_config(&venc.timings));
dss_set_venc_output(venc.type);
dss_set_dac_pwrdn_bgz(1);
l = 0;
if (venc.type == OMAP_DSS_VENC_TYPE_COMPOSITE)
l |= 1 << 1;
else
l |= (1 << 0) | (1 << 2);
if (venc.invert_polarity == false)
l |= 1 << 3;
venc_write_reg(VENC_OUTPUT_CONTROL, l);
dss_mgr_set_timings(mgr, &venc.timings);
r = regulator_enable(venc.vdda_dac_reg);
if (r)
goto err1;
r = dss_mgr_enable(mgr);
if (r)
goto err2;
return 0;
err2:
regulator_disable(venc.vdda_dac_reg);
err1:
venc_write_reg(VENC_OUTPUT_CONTROL, 0);
dss_set_dac_pwrdn_bgz(0);
venc_runtime_put();
err0:
return r;
}
static void venc_power_off(struct omap_dss_device *dssdev)
{
struct omap_overlay_manager *mgr = venc.output.manager;
venc_write_reg(VENC_OUTPUT_CONTROL, 0);
dss_set_dac_pwrdn_bgz(0);
dss_mgr_disable(mgr);
regulator_disable(venc.vdda_dac_reg);
venc_runtime_put();
}
int omapdss_venc_display_enable(struct omap_dss_device *dssdev)
{
struct omap_dss_device *out = &venc.output;
int r;
DSSDBG("venc_display_enable\n");
mutex_lock(&venc.venc_lock);
if (out == NULL || out->manager == NULL) {
DSSERR("Failed to enable display: no output/manager\n");
r = -ENODEV;
goto err0;
}
r = venc_power_on(dssdev);
if (r)
goto err0;
venc.wss_data = 0;
mutex_unlock(&venc.venc_lock);
return 0;
err0:
mutex_unlock(&venc.venc_lock);
return r;
}
void omapdss_venc_display_disable(struct omap_dss_device *dssdev)
{
DSSDBG("venc_display_disable\n");
mutex_lock(&venc.venc_lock);
venc_power_off(dssdev);
mutex_unlock(&venc.venc_lock);
}
void omapdss_venc_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
DSSDBG("venc_set_timings\n");
mutex_lock(&venc.venc_lock);
if (memcmp(&venc.timings, timings, sizeof(*timings)))
venc.wss_data = 0;
venc.timings = *timings;
dispc_set_tv_pclk(13500000);
mutex_unlock(&venc.venc_lock);
}
int omapdss_venc_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
DSSDBG("venc_check_timings\n");
if (memcmp(&omap_dss_pal_timings, timings, sizeof(*timings)) == 0)
return 0;
if (memcmp(&omap_dss_ntsc_timings, timings, sizeof(*timings)) == 0)
return 0;
return -EINVAL;
}
static void venc_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
mutex_lock(&venc.venc_lock);
*timings = venc.timings;
mutex_unlock(&venc.venc_lock);
}
u32 omapdss_venc_get_wss(struct omap_dss_device *dssdev)
{
return (venc.wss_data >> 8) ^ 0xfffff;
}
int omapdss_venc_set_wss(struct omap_dss_device *dssdev, u32 wss)
{
const struct venc_config *config;
int r;
DSSDBG("venc_set_wss\n");
mutex_lock(&venc.venc_lock);
config = venc_timings_to_config(&venc.timings);
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
void omapdss_venc_set_type(struct omap_dss_device *dssdev,
enum omap_dss_venc_type type)
{
mutex_lock(&venc.venc_lock);
venc.type = type;
mutex_unlock(&venc.venc_lock);
}
void omapdss_venc_invert_vid_out_polarity(struct omap_dss_device *dssdev,
bool invert_polarity)
{
mutex_lock(&venc.venc_lock);
venc.invert_polarity = invert_polarity;
mutex_unlock(&venc.venc_lock);
}
static int venc_init_regulator(void)
{
struct regulator *vdda_dac;
if (venc.vdda_dac_reg != NULL)
return 0;
vdda_dac = devm_regulator_get(&venc.pdev->dev, "vdda_dac");
if (IS_ERR(vdda_dac)) {
DSSERR("can't get VDDA_DAC regulator\n");
return PTR_ERR(vdda_dac);
}
venc.vdda_dac_reg = vdda_dac;
return 0;
}
static void venc_dump_regs(struct seq_file *s)
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
if (dss_has_feature(FEAT_VENC_REQUIRES_TV_DAC_CLK)) {
clk = devm_clk_get(&pdev->dev, "tv_dac_clk");
if (IS_ERR(clk)) {
DSSERR("can't get tv_dac_clk\n");
return PTR_ERR(clk);
}
} else {
clk = NULL;
}
venc.tv_dac_clk = clk;
return 0;
}
static struct omap_dss_device *venc_find_dssdev(struct platform_device *pdev)
{
struct omap_dss_board_info *pdata = pdev->dev.platform_data;
const char *def_disp_name = omapdss_get_default_display_name();
struct omap_dss_device *def_dssdev;
int i;
def_dssdev = NULL;
for (i = 0; i < pdata->num_devices; ++i) {
struct omap_dss_device *dssdev = pdata->devices[i];
if (dssdev->type != OMAP_DISPLAY_TYPE_VENC)
continue;
if (def_dssdev == NULL)
def_dssdev = dssdev;
if (def_disp_name != NULL &&
strcmp(dssdev->name, def_disp_name) == 0) {
def_dssdev = dssdev;
break;
}
}
return def_dssdev;
}
static int venc_probe_pdata(struct platform_device *vencdev)
{
struct omap_dss_device *plat_dssdev;
struct omap_dss_device *dssdev;
int r;
plat_dssdev = venc_find_dssdev(vencdev);
if (!plat_dssdev)
return 0;
r = venc_init_regulator();
if (r)
return r;
dssdev = dss_alloc_and_init_device(&vencdev->dev);
if (!dssdev)
return -ENOMEM;
dss_copy_device_pdata(dssdev, plat_dssdev);
r = omapdss_output_set_device(&venc.output, dssdev);
if (r) {
DSSERR("failed to connect output to new device: %s\n",
dssdev->name);
dss_put_device(dssdev);
return r;
}
r = dss_add_device(dssdev);
if (r) {
DSSERR("device %s register failed: %d\n", dssdev->name, r);
omapdss_output_unset_device(&venc.output);
dss_put_device(dssdev);
return r;
}
return 0;
}
static int venc_connect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
struct omap_overlay_manager *mgr;
int r;
r = venc_init_regulator();
if (r)
return r;
mgr = omap_dss_get_overlay_manager(dssdev->dispc_channel);
if (!mgr)
return -ENODEV;
r = dss_mgr_connect(mgr, dssdev);
if (r)
return r;
r = omapdss_output_set_device(dssdev, dst);
if (r) {
DSSERR("failed to connect output to new device: %s\n",
dst->name);
dss_mgr_disconnect(mgr, dssdev);
return r;
}
return 0;
}
static void venc_disconnect(struct omap_dss_device *dssdev,
struct omap_dss_device *dst)
{
WARN_ON(dst != dssdev->device);
if (dst != dssdev->device)
return;
omapdss_output_unset_device(dssdev);
if (dssdev->manager)
dss_mgr_disconnect(dssdev->manager, dssdev);
}
static void venc_init_output(struct platform_device *pdev)
{
struct omap_dss_device *out = &venc.output;
out->dev = &pdev->dev;
out->id = OMAP_DSS_OUTPUT_VENC;
out->output_type = OMAP_DISPLAY_TYPE_VENC;
out->name = "venc.0";
out->dispc_channel = OMAP_DSS_CHANNEL_DIGIT;
out->ops.atv = &venc_ops;
out->owner = THIS_MODULE;
omapdss_register_output(out);
}
static void __exit venc_uninit_output(struct platform_device *pdev)
{
struct omap_dss_device *out = &venc.output;
omapdss_unregister_output(out);
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
return -EINVAL;
}
venc.base = devm_ioremap(&pdev->dev, venc_mem->start,
resource_size(venc_mem));
if (!venc.base) {
DSSERR("can't ioremap VENC\n");
return -ENOMEM;
}
r = venc_get_clocks(pdev);
if (r)
return r;
pm_runtime_enable(&pdev->dev);
r = venc_runtime_get();
if (r)
goto err_runtime_get;
rev_id = (u8)(venc_read_reg(VENC_REV_ID) & 0xff);
dev_dbg(&pdev->dev, "OMAP VENC rev %d\n", rev_id);
venc_runtime_put();
r = venc_panel_init();
if (r)
goto err_panel_init;
dss_debugfs_create_file("venc", venc_dump_regs);
venc_init_output(pdev);
if (pdev->dev.platform_data) {
r = venc_probe_pdata(pdev);
if (r)
goto err_probe;
}
return 0;
err_probe:
venc_panel_exit();
venc_uninit_output(pdev);
err_panel_init:
err_runtime_get:
pm_runtime_disable(&pdev->dev);
return r;
}
static int __exit omap_venchw_remove(struct platform_device *pdev)
{
dss_unregister_child_devices(&pdev->dev);
venc_panel_exit();
venc_uninit_output(pdev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int venc_runtime_suspend(struct device *dev)
{
if (venc.tv_dac_clk)
clk_disable_unprepare(venc.tv_dac_clk);
dispc_runtime_put();
return 0;
}
static int venc_runtime_resume(struct device *dev)
{
int r;
r = dispc_runtime_get();
if (r < 0)
return r;
if (venc.tv_dac_clk)
clk_prepare_enable(venc.tv_dac_clk);
return 0;
}
int __init venc_init_platform_driver(void)
{
return platform_driver_register(&omap_venchw_driver);
}
void __exit venc_uninit_platform_driver(void)
{
platform_driver_unregister(&omap_venchw_driver);
}
