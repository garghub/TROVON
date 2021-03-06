static void fsl_dcu_drm_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
}
static int fsl_dcu_drm_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
return 0;
}
static void fsl_dcu_drm_crtc_atomic_flush(struct drm_crtc *crtc,
struct drm_crtc_state *old_crtc_state)
{
}
static void fsl_dcu_drm_disable_crtc(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
int ret;
ret = regmap_update_bits(fsl_dev->regmap, DCU_DCU_MODE,
DCU_MODE_DCU_MODE_MASK,
DCU_MODE_DCU_MODE(DCU_MODE_OFF));
if (ret)
dev_err(fsl_dev->dev, "Disable CRTC failed\n");
ret = regmap_write(fsl_dev->regmap, DCU_UPDATE_MODE,
DCU_UPDATE_MODE_READREG);
if (ret)
dev_err(fsl_dev->dev, "Enable CRTC failed\n");
}
static void fsl_dcu_drm_crtc_enable(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
int ret;
ret = regmap_update_bits(fsl_dev->regmap, DCU_DCU_MODE,
DCU_MODE_DCU_MODE_MASK,
DCU_MODE_DCU_MODE(DCU_MODE_NORMAL));
if (ret)
dev_err(fsl_dev->dev, "Enable CRTC failed\n");
ret = regmap_write(fsl_dev->regmap, DCU_UPDATE_MODE,
DCU_UPDATE_MODE_READREG);
if (ret)
dev_err(fsl_dev->dev, "Enable CRTC failed\n");
}
static bool fsl_dcu_drm_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void fsl_dcu_drm_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct fsl_dcu_drm_device *fsl_dev = dev->dev_private;
struct drm_display_mode *mode = &crtc->state->mode;
unsigned int hbp, hfp, hsw, vbp, vfp, vsw, div, index;
unsigned long dcuclk;
int ret;
index = drm_crtc_index(crtc);
dcuclk = clk_get_rate(fsl_dev->clk);
div = dcuclk / mode->clock / 1000;
hbp = mode->htotal - mode->hsync_end;
hfp = mode->hsync_start - mode->hdisplay;
hsw = mode->hsync_end - mode->hsync_start;
vbp = mode->vtotal - mode->vsync_end;
vfp = mode->vsync_start - mode->vdisplay;
vsw = mode->vsync_end - mode->vsync_start;
ret = regmap_write(fsl_dev->regmap, DCU_HSYN_PARA,
DCU_HSYN_PARA_BP(hbp) |
DCU_HSYN_PARA_PW(hsw) |
DCU_HSYN_PARA_FP(hfp));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_VSYN_PARA,
DCU_VSYN_PARA_BP(vbp) |
DCU_VSYN_PARA_PW(vsw) |
DCU_VSYN_PARA_FP(vfp));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_DISP_SIZE,
DCU_DISP_SIZE_DELTA_Y(mode->vdisplay) |
DCU_DISP_SIZE_DELTA_X(mode->hdisplay));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_DIV_RATIO, div);
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_SYN_POL,
DCU_SYN_POL_INV_VS_LOW | DCU_SYN_POL_INV_HS_LOW);
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_BGND, DCU_BGND_R(0) |
DCU_BGND_G(0) | DCU_BGND_B(0));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_DCU_MODE,
DCU_MODE_BLEND_ITER(1) | DCU_MODE_RASTER_EN);
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_THRESHOLD,
DCU_THRESHOLD_LS_BF_VS(BF_VS_VAL) |
DCU_THRESHOLD_OUT_BUF_HIGH(BUF_MAX_VAL) |
DCU_THRESHOLD_OUT_BUF_LOW(BUF_MIN_VAL));
if (ret)
goto set_failed;
ret = regmap_write(fsl_dev->regmap, DCU_UPDATE_MODE,
DCU_UPDATE_MODE_READREG);
if (ret)
goto set_failed;
return;
set_failed:
dev_err(dev->dev, "set DCU register failed\n");
}
int fsl_dcu_drm_crtc_create(struct fsl_dcu_drm_device *fsl_dev)
{
struct drm_plane *primary;
struct drm_crtc *crtc = &fsl_dev->crtc;
unsigned int i, j, reg_num;
int ret;
primary = fsl_dcu_drm_primary_create_plane(fsl_dev->drm);
ret = drm_crtc_init_with_planes(fsl_dev->drm, crtc, primary, NULL,
&fsl_dcu_drm_crtc_funcs);
if (ret < 0)
return ret;
drm_crtc_helper_add(crtc, &fsl_dcu_drm_crtc_helper_funcs);
if (!strcmp(fsl_dev->soc->name, "ls1021a"))
reg_num = LS1021A_LAYER_REG_NUM;
else
reg_num = VF610_LAYER_REG_NUM;
for (i = 0; i <= fsl_dev->soc->total_layer; i++) {
for (j = 0; j < reg_num; j++) {
ret = regmap_write(fsl_dev->regmap,
DCU_CTRLDESCLN(i, j), 0);
if (ret)
goto init_failed;
}
}
ret = regmap_update_bits(fsl_dev->regmap, DCU_DCU_MODE,
DCU_MODE_DCU_MODE_MASK,
DCU_MODE_DCU_MODE(DCU_MODE_OFF));
if (ret)
goto init_failed;
ret = regmap_write(fsl_dev->regmap, DCU_UPDATE_MODE,
DCU_UPDATE_MODE_READREG);
if (ret)
goto init_failed;
return 0;
init_failed:
dev_err(fsl_dev->dev, "init DCU register failed\n");
return ret;
}
