static inline u32 hdmi_reg_read(struct hdmi_context *hdata, u32 reg_id)
{
return readl(hdata->regs + reg_id);
}
static inline void hdmi_reg_writeb(struct hdmi_context *hdata,
u32 reg_id, u8 value)
{
writeb(value, hdata->regs + reg_id);
}
static inline void hdmi_reg_writemask(struct hdmi_context *hdata,
u32 reg_id, u32 value, u32 mask)
{
u32 old = readl(hdata->regs + reg_id);
value = (value & mask) | (old & ~mask);
writel(value, hdata->regs + reg_id);
}
static void hdmi_regs_dump(struct hdmi_context *hdata, char *prefix)
{
#define DUMPREG(reg_id) \
DRM_DEBUG_KMS("%s:" #reg_id " = %08x\n", prefix, \
readl(hdata->regs + reg_id))
DRM_DEBUG_KMS("%s: ---- CONTROL REGISTERS ----\n", prefix);
DUMPREG(HDMI_INTC_FLAG);
DUMPREG(HDMI_INTC_CON);
DUMPREG(HDMI_HPD_STATUS);
DUMPREG(HDMI_PHY_RSTOUT);
DUMPREG(HDMI_PHY_VPLL);
DUMPREG(HDMI_PHY_CMU);
DUMPREG(HDMI_CORE_RSTOUT);
DRM_DEBUG_KMS("%s: ---- CORE REGISTERS ----\n", prefix);
DUMPREG(HDMI_CON_0);
DUMPREG(HDMI_CON_1);
DUMPREG(HDMI_CON_2);
DUMPREG(HDMI_SYS_STATUS);
DUMPREG(HDMI_PHY_STATUS);
DUMPREG(HDMI_STATUS_EN);
DUMPREG(HDMI_HPD);
DUMPREG(HDMI_MODE_SEL);
DUMPREG(HDMI_HPD_GEN);
DUMPREG(HDMI_DC_CONTROL);
DUMPREG(HDMI_VIDEO_PATTERN_GEN);
DRM_DEBUG_KMS("%s: ---- CORE SYNC REGISTERS ----\n", prefix);
DUMPREG(HDMI_H_BLANK_0);
DUMPREG(HDMI_H_BLANK_1);
DUMPREG(HDMI_V_BLANK_0);
DUMPREG(HDMI_V_BLANK_1);
DUMPREG(HDMI_V_BLANK_2);
DUMPREG(HDMI_H_V_LINE_0);
DUMPREG(HDMI_H_V_LINE_1);
DUMPREG(HDMI_H_V_LINE_2);
DUMPREG(HDMI_VSYNC_POL);
DUMPREG(HDMI_INT_PRO_MODE);
DUMPREG(HDMI_V_BLANK_F_0);
DUMPREG(HDMI_V_BLANK_F_1);
DUMPREG(HDMI_V_BLANK_F_2);
DUMPREG(HDMI_H_SYNC_GEN_0);
DUMPREG(HDMI_H_SYNC_GEN_1);
DUMPREG(HDMI_H_SYNC_GEN_2);
DUMPREG(HDMI_V_SYNC_GEN_1_0);
DUMPREG(HDMI_V_SYNC_GEN_1_1);
DUMPREG(HDMI_V_SYNC_GEN_1_2);
DUMPREG(HDMI_V_SYNC_GEN_2_0);
DUMPREG(HDMI_V_SYNC_GEN_2_1);
DUMPREG(HDMI_V_SYNC_GEN_2_2);
DUMPREG(HDMI_V_SYNC_GEN_3_0);
DUMPREG(HDMI_V_SYNC_GEN_3_1);
DUMPREG(HDMI_V_SYNC_GEN_3_2);
DRM_DEBUG_KMS("%s: ---- TG REGISTERS ----\n", prefix);
DUMPREG(HDMI_TG_CMD);
DUMPREG(HDMI_TG_H_FSZ_L);
DUMPREG(HDMI_TG_H_FSZ_H);
DUMPREG(HDMI_TG_HACT_ST_L);
DUMPREG(HDMI_TG_HACT_ST_H);
DUMPREG(HDMI_TG_HACT_SZ_L);
DUMPREG(HDMI_TG_HACT_SZ_H);
DUMPREG(HDMI_TG_V_FSZ_L);
DUMPREG(HDMI_TG_V_FSZ_H);
DUMPREG(HDMI_TG_VSYNC_L);
DUMPREG(HDMI_TG_VSYNC_H);
DUMPREG(HDMI_TG_VSYNC2_L);
DUMPREG(HDMI_TG_VSYNC2_H);
DUMPREG(HDMI_TG_VACT_ST_L);
DUMPREG(HDMI_TG_VACT_ST_H);
DUMPREG(HDMI_TG_VACT_SZ_L);
DUMPREG(HDMI_TG_VACT_SZ_H);
DUMPREG(HDMI_TG_FIELD_CHG_L);
DUMPREG(HDMI_TG_FIELD_CHG_H);
DUMPREG(HDMI_TG_VACT_ST2_L);
DUMPREG(HDMI_TG_VACT_ST2_H);
DUMPREG(HDMI_TG_VSYNC_TOP_HDMI_L);
DUMPREG(HDMI_TG_VSYNC_TOP_HDMI_H);
DUMPREG(HDMI_TG_VSYNC_BOT_HDMI_L);
DUMPREG(HDMI_TG_VSYNC_BOT_HDMI_H);
DUMPREG(HDMI_TG_FIELD_TOP_HDMI_L);
DUMPREG(HDMI_TG_FIELD_TOP_HDMI_H);
DUMPREG(HDMI_TG_FIELD_BOT_HDMI_L);
DUMPREG(HDMI_TG_FIELD_BOT_HDMI_H);
#undef DUMPREG
}
static int hdmi_conf_index(struct drm_display_mode *mode)
{
int i;
for (i = 0; i < ARRAY_SIZE(hdmi_confs); ++i)
if (hdmi_confs[i].width == mode->hdisplay &&
hdmi_confs[i].height == mode->vdisplay &&
hdmi_confs[i].vrefresh == mode->vrefresh &&
hdmi_confs[i].interlace ==
((mode->flags & DRM_MODE_FLAG_INTERLACE) ?
true : false))
return i;
return -1;
}
static bool hdmi_is_connected(void *ctx)
{
struct hdmi_context *hdata = (struct hdmi_context *)ctx;
u32 val = hdmi_reg_read(hdata, HDMI_HPD_STATUS);
if (val)
return true;
return false;
}
static int hdmi_get_edid(void *ctx, struct drm_connector *connector,
u8 *edid, int len)
{
struct edid *raw_edid;
struct hdmi_context *hdata = (struct hdmi_context *)ctx;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
if (!hdata->ddc_port)
return -ENODEV;
raw_edid = drm_get_edid(connector, hdata->ddc_port->adapter);
if (raw_edid) {
memcpy(edid, raw_edid, min((1 + raw_edid->extensions)
* EDID_LENGTH, len));
DRM_DEBUG_KMS("width[%d] x height[%d]\n",
raw_edid->width_cm, raw_edid->height_cm);
} else {
return -ENODEV;
}
return 0;
}
static int hdmi_check_timing(void *ctx, void *timing)
{
struct fb_videomode *check_timing = timing;
int i;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
DRM_DEBUG_KMS("[%d]x[%d] [%d]Hz [%x]\n", check_timing->xres,
check_timing->yres, check_timing->refresh,
check_timing->vmode);
for (i = 0; i < ARRAY_SIZE(hdmi_confs); ++i)
if (hdmi_confs[i].width == check_timing->xres &&
hdmi_confs[i].height == check_timing->yres &&
hdmi_confs[i].vrefresh == check_timing->refresh &&
hdmi_confs[i].interlace ==
((check_timing->vmode & FB_VMODE_INTERLACED) ?
true : false))
return 0;
return -EINVAL;
}
static int hdmi_display_power_on(void *ctx, int mode)
{
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
switch (mode) {
case DRM_MODE_DPMS_ON:
DRM_DEBUG_KMS("hdmi [on]\n");
break;
case DRM_MODE_DPMS_STANDBY:
break;
case DRM_MODE_DPMS_SUSPEND:
break;
case DRM_MODE_DPMS_OFF:
DRM_DEBUG_KMS("hdmi [off]\n");
break;
default:
break;
}
return 0;
}
static void hdmi_conf_reset(struct hdmi_context *hdata)
{
hdata->hpd_handle = false;
hdmi_reg_writemask(hdata, HDMI_CORE_RSTOUT, 0, HDMI_CORE_SW_RSTOUT);
mdelay(10);
hdmi_reg_writemask(hdata, HDMI_CORE_RSTOUT, ~0, HDMI_CORE_SW_RSTOUT);
mdelay(10);
hdata->hpd_handle = true;
}
static void hdmi_conf_init(struct hdmi_context *hdata)
{
hdata->hpd_handle = false;
hdmi_reg_writemask(hdata, HDMI_INTC_CON, 0, HDMI_INTC_EN_GLOBAL |
HDMI_INTC_EN_HPD_PLUG | HDMI_INTC_EN_HPD_UNPLUG);
mdelay(10);
hdmi_reg_writemask(hdata, HDMI_INTC_CON, ~0, HDMI_INTC_EN_GLOBAL |
HDMI_INTC_EN_HPD_PLUG | HDMI_INTC_EN_HPD_UNPLUG);
hdmi_reg_writemask(hdata, HDMI_MODE_SEL,
HDMI_MODE_HDMI_EN, HDMI_MODE_MASK);
hdmi_reg_writemask(hdata, HDMI_CON_0, 0, HDMI_BLUE_SCR_EN);
hdmi_reg_writeb(hdata, HDMI_BLUE_SCREEN_0, 0x12);
hdmi_reg_writeb(hdata, HDMI_BLUE_SCREEN_1, 0x34);
hdmi_reg_writeb(hdata, HDMI_BLUE_SCREEN_2, 0x56);
hdmi_reg_writeb(hdata, HDMI_AVI_CON, 0x02);
hdmi_reg_writeb(hdata, HDMI_AVI_BYTE(0), 0 << 5);
hdmi_reg_writemask(hdata, HDMI_CON_1, 0x10 << 5, 0x11 << 5);
hdmi_reg_writeb(hdata, HDMI_SPD_CON, 0x02);
hdmi_reg_writeb(hdata, HDMI_AUI_CON, 0x02);
hdmi_reg_writeb(hdata, HDMI_ACR_CON, 0x04);
hdata->hpd_handle = true;
}
static void hdmi_timing_apply(struct hdmi_context *hdata,
const struct hdmi_preset_conf *conf)
{
const struct hdmi_core_regs *core = &conf->core;
const struct hdmi_tg_regs *tg = &conf->tg;
int tries;
hdmi_reg_writeb(hdata, HDMI_H_BLANK_0, core->h_blank[0]);
hdmi_reg_writeb(hdata, HDMI_H_BLANK_1, core->h_blank[1]);
hdmi_reg_writeb(hdata, HDMI_V_BLANK_0, core->v_blank[0]);
hdmi_reg_writeb(hdata, HDMI_V_BLANK_1, core->v_blank[1]);
hdmi_reg_writeb(hdata, HDMI_V_BLANK_2, core->v_blank[2]);
hdmi_reg_writeb(hdata, HDMI_H_V_LINE_0, core->h_v_line[0]);
hdmi_reg_writeb(hdata, HDMI_H_V_LINE_1, core->h_v_line[1]);
hdmi_reg_writeb(hdata, HDMI_H_V_LINE_2, core->h_v_line[2]);
hdmi_reg_writeb(hdata, HDMI_VSYNC_POL, core->vsync_pol[0]);
hdmi_reg_writeb(hdata, HDMI_INT_PRO_MODE, core->int_pro_mode[0]);
hdmi_reg_writeb(hdata, HDMI_V_BLANK_F_0, core->v_blank_f[0]);
hdmi_reg_writeb(hdata, HDMI_V_BLANK_F_1, core->v_blank_f[1]);
hdmi_reg_writeb(hdata, HDMI_V_BLANK_F_2, core->v_blank_f[2]);
hdmi_reg_writeb(hdata, HDMI_H_SYNC_GEN_0, core->h_sync_gen[0]);
hdmi_reg_writeb(hdata, HDMI_H_SYNC_GEN_1, core->h_sync_gen[1]);
hdmi_reg_writeb(hdata, HDMI_H_SYNC_GEN_2, core->h_sync_gen[2]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_1_0, core->v_sync_gen1[0]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_1_1, core->v_sync_gen1[1]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_1_2, core->v_sync_gen1[2]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_2_0, core->v_sync_gen2[0]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_2_1, core->v_sync_gen2[1]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_2_2, core->v_sync_gen2[2]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_3_0, core->v_sync_gen3[0]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_3_1, core->v_sync_gen3[1]);
hdmi_reg_writeb(hdata, HDMI_V_SYNC_GEN_3_2, core->v_sync_gen3[2]);
hdmi_reg_writeb(hdata, HDMI_TG_H_FSZ_L, tg->h_fsz_l);
hdmi_reg_writeb(hdata, HDMI_TG_H_FSZ_H, tg->h_fsz_h);
hdmi_reg_writeb(hdata, HDMI_TG_HACT_ST_L, tg->hact_st_l);
hdmi_reg_writeb(hdata, HDMI_TG_HACT_ST_H, tg->hact_st_h);
hdmi_reg_writeb(hdata, HDMI_TG_HACT_SZ_L, tg->hact_sz_l);
hdmi_reg_writeb(hdata, HDMI_TG_HACT_SZ_H, tg->hact_sz_h);
hdmi_reg_writeb(hdata, HDMI_TG_V_FSZ_L, tg->v_fsz_l);
hdmi_reg_writeb(hdata, HDMI_TG_V_FSZ_H, tg->v_fsz_h);
hdmi_reg_writeb(hdata, HDMI_TG_VSYNC_L, tg->vsync_l);
hdmi_reg_writeb(hdata, HDMI_TG_VSYNC_H, tg->vsync_h);
hdmi_reg_writeb(hdata, HDMI_TG_VSYNC2_L, tg->vsync2_l);
hdmi_reg_writeb(hdata, HDMI_TG_VSYNC2_H, tg->vsync2_h);
hdmi_reg_writeb(hdata, HDMI_TG_VACT_ST_L, tg->vact_st_l);
hdmi_reg_writeb(hdata, HDMI_TG_VACT_ST_H, tg->vact_st_h);
hdmi_reg_writeb(hdata, HDMI_TG_VACT_SZ_L, tg->vact_sz_l);
hdmi_reg_writeb(hdata, HDMI_TG_VACT_SZ_H, tg->vact_sz_h);
hdmi_reg_writeb(hdata, HDMI_TG_FIELD_CHG_L, tg->field_chg_l);
hdmi_reg_writeb(hdata, HDMI_TG_FIELD_CHG_H, tg->field_chg_h);
hdmi_reg_writeb(hdata, HDMI_TG_VACT_ST2_L, tg->vact_st2_l);
hdmi_reg_writeb(hdata, HDMI_TG_VACT_ST2_H, tg->vact_st2_h);
hdmi_reg_writeb(hdata, HDMI_TG_VSYNC_TOP_HDMI_L, tg->vsync_top_hdmi_l);
hdmi_reg_writeb(hdata, HDMI_TG_VSYNC_TOP_HDMI_H, tg->vsync_top_hdmi_h);
hdmi_reg_writeb(hdata, HDMI_TG_VSYNC_BOT_HDMI_L, tg->vsync_bot_hdmi_l);
hdmi_reg_writeb(hdata, HDMI_TG_VSYNC_BOT_HDMI_H, tg->vsync_bot_hdmi_h);
hdmi_reg_writeb(hdata, HDMI_TG_FIELD_TOP_HDMI_L, tg->field_top_hdmi_l);
hdmi_reg_writeb(hdata, HDMI_TG_FIELD_TOP_HDMI_H, tg->field_top_hdmi_h);
hdmi_reg_writeb(hdata, HDMI_TG_FIELD_BOT_HDMI_L, tg->field_bot_hdmi_l);
hdmi_reg_writeb(hdata, HDMI_TG_FIELD_BOT_HDMI_H, tg->field_bot_hdmi_h);
for (tries = 100; tries; --tries) {
u32 val = hdmi_reg_read(hdata, HDMI_PHY_STATUS);
if (val & HDMI_PHY_STATUS_READY)
break;
mdelay(1);
}
if (tries == 0) {
DRM_ERROR("hdmiphy's pll could not reach steady state.\n");
hdmi_regs_dump(hdata, "timing apply");
}
clk_disable(hdata->res.sclk_hdmi);
clk_set_parent(hdata->res.sclk_hdmi, hdata->res.sclk_hdmiphy);
clk_enable(hdata->res.sclk_hdmi);
hdmi_reg_writemask(hdata, HDMI_CON_0, ~0, HDMI_EN);
if (core->int_pro_mode[0])
hdmi_reg_writemask(hdata, HDMI_TG_CMD, ~0, HDMI_TG_EN |
HDMI_FIELD_EN);
else
hdmi_reg_writemask(hdata, HDMI_TG_CMD, ~0, HDMI_TG_EN);
}
static void hdmiphy_conf_reset(struct hdmi_context *hdata)
{
u8 buffer[2];
clk_disable(hdata->res.sclk_hdmi);
clk_set_parent(hdata->res.sclk_hdmi, hdata->res.sclk_pixel);
clk_enable(hdata->res.sclk_hdmi);
buffer[0] = 0x1f;
buffer[1] = 0x00;
if (hdata->hdmiphy_port)
i2c_master_send(hdata->hdmiphy_port, buffer, 2);
hdmi_reg_writemask(hdata, HDMI_PHY_RSTOUT, ~0, HDMI_PHY_SW_RSTOUT);
mdelay(10);
hdmi_reg_writemask(hdata, HDMI_PHY_RSTOUT, 0, HDMI_PHY_SW_RSTOUT);
mdelay(10);
}
static void hdmiphy_conf_apply(struct hdmi_context *hdata)
{
u8 buffer[32];
u8 operation[2];
u8 read_buffer[32] = {0, };
int ret;
int i;
if (!hdata->hdmiphy_port) {
DRM_ERROR("hdmiphy is not attached\n");
return;
}
memcpy(buffer, hdmi_confs[hdata->cur_conf].hdmiphy_data, 32);
ret = i2c_master_send(hdata->hdmiphy_port, buffer, 32);
if (ret != 32) {
DRM_ERROR("failed to configure HDMIPHY via I2C\n");
return;
}
mdelay(10);
operation[0] = 0x1f;
operation[1] = 0x80;
ret = i2c_master_send(hdata->hdmiphy_port, operation, 2);
if (ret != 2) {
DRM_ERROR("failed to enable hdmiphy\n");
return;
}
ret = i2c_master_recv(hdata->hdmiphy_port, read_buffer, 32);
if (ret < 0) {
DRM_ERROR("failed to read hdmiphy config\n");
return;
}
for (i = 0; i < ret; i++)
DRM_DEBUG_KMS("hdmiphy[0x%02x] write[0x%02x] - "
"recv [0x%02x]\n", i, buffer[i], read_buffer[i]);
}
static void hdmi_conf_apply(struct hdmi_context *hdata)
{
const struct hdmi_preset_conf *conf =
hdmi_confs[hdata->cur_conf].conf;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
hdmiphy_conf_reset(hdata);
hdmiphy_conf_apply(hdata);
hdmi_conf_reset(hdata);
hdmi_conf_init(hdata);
hdmi_timing_apply(hdata, conf);
hdmi_regs_dump(hdata, "start");
}
static void hdmi_mode_set(void *ctx, void *mode)
{
struct hdmi_context *hdata = (struct hdmi_context *)ctx;
int conf_idx;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
conf_idx = hdmi_conf_index(mode);
if (conf_idx >= 0 && conf_idx < ARRAY_SIZE(hdmi_confs))
hdata->cur_conf = conf_idx;
else
DRM_DEBUG_KMS("not supported mode\n");
}
static void hdmi_commit(void *ctx)
{
struct hdmi_context *hdata = (struct hdmi_context *)ctx;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
hdmi_conf_apply(hdata);
hdata->enabled = true;
}
static void hdmi_disable(void *ctx)
{
struct hdmi_context *hdata = (struct hdmi_context *)ctx;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
if (hdata->enabled) {
hdmiphy_conf_reset(hdata);
hdmi_conf_reset(hdata);
}
}
static void hdmi_hotplug_func(struct work_struct *work)
{
struct hdmi_context *hdata =
container_of(work, struct hdmi_context, hotplug_work);
struct exynos_drm_hdmi_context *ctx =
(struct exynos_drm_hdmi_context *)hdata->parent_ctx;
drm_helper_hpd_irq_event(ctx->drm_dev);
}
static irqreturn_t hdmi_irq_handler(int irq, void *arg)
{
struct exynos_drm_hdmi_context *ctx = arg;
struct hdmi_context *hdata = (struct hdmi_context *)ctx->ctx;
u32 intc_flag;
intc_flag = hdmi_reg_read(hdata, HDMI_INTC_FLAG);
if (intc_flag & HDMI_INTC_FLAG_HPD_UNPLUG) {
DRM_DEBUG_KMS("unplugged, handling:%d\n", hdata->hpd_handle);
hdmi_reg_writemask(hdata, HDMI_INTC_FLAG, ~0,
HDMI_INTC_FLAG_HPD_UNPLUG);
}
if (intc_flag & HDMI_INTC_FLAG_HPD_PLUG) {
DRM_DEBUG_KMS("plugged, handling:%d\n", hdata->hpd_handle);
hdmi_reg_writemask(hdata, HDMI_INTC_FLAG, ~0,
HDMI_INTC_FLAG_HPD_PLUG);
}
if (ctx->drm_dev && hdata->hpd_handle)
queue_work(hdata->wq, &hdata->hotplug_work);
return IRQ_HANDLED;
}
static int __devinit hdmi_resources_init(struct hdmi_context *hdata)
{
struct device *dev = hdata->dev;
struct hdmi_resources *res = &hdata->res;
static char *supply[] = {
"hdmi-en",
"vdd",
"vdd_osc",
"vdd_pll",
};
int i, ret;
DRM_DEBUG_KMS("HDMI resource init\n");
memset(res, 0, sizeof *res);
res->hdmi = clk_get(dev, "hdmi");
if (IS_ERR_OR_NULL(res->hdmi)) {
DRM_ERROR("failed to get clock 'hdmi'\n");
goto fail;
}
res->sclk_hdmi = clk_get(dev, "sclk_hdmi");
if (IS_ERR_OR_NULL(res->sclk_hdmi)) {
DRM_ERROR("failed to get clock 'sclk_hdmi'\n");
goto fail;
}
res->sclk_pixel = clk_get(dev, "sclk_pixel");
if (IS_ERR_OR_NULL(res->sclk_pixel)) {
DRM_ERROR("failed to get clock 'sclk_pixel'\n");
goto fail;
}
res->sclk_hdmiphy = clk_get(dev, "sclk_hdmiphy");
if (IS_ERR_OR_NULL(res->sclk_hdmiphy)) {
DRM_ERROR("failed to get clock 'sclk_hdmiphy'\n");
goto fail;
}
res->hdmiphy = clk_get(dev, "hdmiphy");
if (IS_ERR_OR_NULL(res->hdmiphy)) {
DRM_ERROR("failed to get clock 'hdmiphy'\n");
goto fail;
}
clk_set_parent(res->sclk_hdmi, res->sclk_pixel);
res->regul_bulk = kzalloc(ARRAY_SIZE(supply) *
sizeof res->regul_bulk[0], GFP_KERNEL);
if (!res->regul_bulk) {
DRM_ERROR("failed to get memory for regulators\n");
goto fail;
}
for (i = 0; i < ARRAY_SIZE(supply); ++i) {
res->regul_bulk[i].supply = supply[i];
res->regul_bulk[i].consumer = NULL;
}
ret = regulator_bulk_get(dev, ARRAY_SIZE(supply), res->regul_bulk);
if (ret) {
DRM_ERROR("failed to get regulators\n");
goto fail;
}
res->regul_count = ARRAY_SIZE(supply);
return 0;
fail:
DRM_ERROR("HDMI resource init - failed\n");
return -ENODEV;
}
static int hdmi_resources_cleanup(struct hdmi_context *hdata)
{
struct hdmi_resources *res = &hdata->res;
regulator_bulk_free(res->regul_count, res->regul_bulk);
kfree(res->regul_bulk);
if (!IS_ERR_OR_NULL(res->hdmiphy))
clk_put(res->hdmiphy);
if (!IS_ERR_OR_NULL(res->sclk_hdmiphy))
clk_put(res->sclk_hdmiphy);
if (!IS_ERR_OR_NULL(res->sclk_pixel))
clk_put(res->sclk_pixel);
if (!IS_ERR_OR_NULL(res->sclk_hdmi))
clk_put(res->sclk_hdmi);
if (!IS_ERR_OR_NULL(res->hdmi))
clk_put(res->hdmi);
memset(res, 0, sizeof *res);
return 0;
}
static void hdmi_resource_poweron(struct hdmi_context *hdata)
{
struct hdmi_resources *res = &hdata->res;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
regulator_bulk_enable(res->regul_count, res->regul_bulk);
clk_enable(res->hdmiphy);
clk_enable(res->hdmi);
clk_enable(res->sclk_hdmi);
hdmiphy_conf_reset(hdata);
hdmi_conf_reset(hdata);
hdmi_conf_init(hdata);
}
static void hdmi_resource_poweroff(struct hdmi_context *hdata)
{
struct hdmi_resources *res = &hdata->res;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
clk_disable(res->sclk_hdmi);
clk_disable(res->hdmi);
clk_disable(res->hdmiphy);
regulator_bulk_disable(res->regul_count, res->regul_bulk);
}
static int hdmi_runtime_suspend(struct device *dev)
{
struct exynos_drm_hdmi_context *ctx = get_hdmi_context(dev);
DRM_DEBUG_KMS("%s\n", __func__);
hdmi_resource_poweroff((struct hdmi_context *)ctx->ctx);
return 0;
}
static int hdmi_runtime_resume(struct device *dev)
{
struct exynos_drm_hdmi_context *ctx = get_hdmi_context(dev);
DRM_DEBUG_KMS("%s\n", __func__);
hdmi_resource_poweron((struct hdmi_context *)ctx->ctx);
return 0;
}
void hdmi_attach_ddc_client(struct i2c_client *ddc)
{
if (ddc)
hdmi_ddc = ddc;
}
void hdmi_attach_hdmiphy_client(struct i2c_client *hdmiphy)
{
if (hdmiphy)
hdmi_hdmiphy = hdmiphy;
}
static int __devinit hdmi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct exynos_drm_hdmi_context *drm_hdmi_ctx;
struct hdmi_context *hdata;
struct exynos_drm_hdmi_pdata *pdata;
struct resource *res;
int ret;
DRM_DEBUG_KMS("[%d]\n", __LINE__);
pdata = pdev->dev.platform_data;
if (!pdata) {
DRM_ERROR("no platform data specified\n");
return -EINVAL;
}
drm_hdmi_ctx = kzalloc(sizeof(*drm_hdmi_ctx), GFP_KERNEL);
if (!drm_hdmi_ctx) {
DRM_ERROR("failed to allocate common hdmi context.\n");
return -ENOMEM;
}
hdata = kzalloc(sizeof(struct hdmi_context), GFP_KERNEL);
if (!hdata) {
DRM_ERROR("out of memory\n");
kfree(drm_hdmi_ctx);
return -ENOMEM;
}
drm_hdmi_ctx->ctx = (void *)hdata;
hdata->parent_ctx = (void *)drm_hdmi_ctx;
platform_set_drvdata(pdev, drm_hdmi_ctx);
hdata->default_win = pdata->default_win;
hdata->default_timing = &pdata->timing;
hdata->default_bpp = pdata->bpp;
hdata->dev = dev;
ret = hdmi_resources_init(hdata);
if (ret) {
ret = -EINVAL;
goto err_data;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
DRM_ERROR("failed to find registers\n");
ret = -ENOENT;
goto err_resource;
}
hdata->regs_res = request_mem_region(res->start, resource_size(res),
dev_name(dev));
if (!hdata->regs_res) {
DRM_ERROR("failed to claim register region\n");
ret = -ENOENT;
goto err_resource;
}
hdata->regs = ioremap(res->start, resource_size(res));
if (!hdata->regs) {
DRM_ERROR("failed to map registers\n");
ret = -ENXIO;
goto err_req_region;
}
if (i2c_add_driver(&ddc_driver)) {
DRM_ERROR("failed to register ddc i2c driver\n");
ret = -ENOENT;
goto err_iomap;
}
hdata->ddc_port = hdmi_ddc;
if (i2c_add_driver(&hdmiphy_driver)) {
DRM_ERROR("failed to register hdmiphy i2c driver\n");
ret = -ENOENT;
goto err_ddc;
}
hdata->hdmiphy_port = hdmi_hdmiphy;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
DRM_ERROR("get interrupt resource failed.\n");
ret = -ENXIO;
goto err_hdmiphy;
}
hdata->wq = alloc_workqueue("exynos-drm-hdmi",
WQ_UNBOUND | WQ_NON_REENTRANT, 1);
if (hdata->wq == NULL) {
DRM_ERROR("Failed to create workqueue.\n");
ret = -ENOMEM;
goto err_hdmiphy;
}
INIT_WORK(&hdata->hotplug_work, hdmi_hotplug_func);
ret = request_irq(res->start, hdmi_irq_handler, 0, "drm_hdmi",
drm_hdmi_ctx);
if (ret) {
DRM_ERROR("request interrupt failed.\n");
goto err_workqueue;
}
hdata->irq = res->start;
exynos_drm_display_ops_register(&display_ops);
exynos_drm_manager_ops_register(&manager_ops);
hdmi_resource_poweron(hdata);
return 0;
err_workqueue:
destroy_workqueue(hdata->wq);
err_hdmiphy:
i2c_del_driver(&hdmiphy_driver);
err_ddc:
i2c_del_driver(&ddc_driver);
err_iomap:
iounmap(hdata->regs);
err_req_region:
release_mem_region(hdata->regs_res->start,
resource_size(hdata->regs_res));
err_resource:
hdmi_resources_cleanup(hdata);
err_data:
kfree(hdata);
kfree(drm_hdmi_ctx);
return ret;
}
static int __devexit hdmi_remove(struct platform_device *pdev)
{
struct exynos_drm_hdmi_context *ctx = platform_get_drvdata(pdev);
struct hdmi_context *hdata = (struct hdmi_context *)ctx->ctx;
DRM_DEBUG_KMS("[%d] %s\n", __LINE__, __func__);
hdmi_resource_poweroff(hdata);
disable_irq(hdata->irq);
free_irq(hdata->irq, hdata);
cancel_work_sync(&hdata->hotplug_work);
destroy_workqueue(hdata->wq);
hdmi_resources_cleanup(hdata);
iounmap(hdata->regs);
release_mem_region(hdata->regs_res->start,
resource_size(hdata->regs_res));
i2c_del_driver(&hdmiphy_driver);
i2c_del_driver(&ddc_driver);
kfree(hdata);
return 0;
}
