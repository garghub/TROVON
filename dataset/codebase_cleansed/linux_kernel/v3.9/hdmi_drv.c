static struct hdmi_device *sd_to_hdmi_dev(struct v4l2_subdev *sd)
{
return container_of(sd, struct hdmi_device, sd);
}
static inline
void hdmi_write(struct hdmi_device *hdev, u32 reg_id, u32 value)
{
writel(value, hdev->regs + reg_id);
}
static inline
void hdmi_write_mask(struct hdmi_device *hdev, u32 reg_id, u32 value, u32 mask)
{
u32 old = readl(hdev->regs + reg_id);
value = (value & mask) | (old & ~mask);
writel(value, hdev->regs + reg_id);
}
static inline
void hdmi_writeb(struct hdmi_device *hdev, u32 reg_id, u8 value)
{
writeb(value, hdev->regs + reg_id);
}
static inline
void hdmi_writebn(struct hdmi_device *hdev, u32 reg_id, int n, u32 value)
{
switch (n) {
default:
writeb(value >> 24, hdev->regs + reg_id + 12);
case 3:
writeb(value >> 16, hdev->regs + reg_id + 8);
case 2:
writeb(value >> 8, hdev->regs + reg_id + 4);
case 1:
writeb(value >> 0, hdev->regs + reg_id + 0);
}
}
static inline u32 hdmi_read(struct hdmi_device *hdev, u32 reg_id)
{
return readl(hdev->regs + reg_id);
}
static irqreturn_t hdmi_irq_handler(int irq, void *dev_data)
{
struct hdmi_device *hdev = dev_data;
u32 intc_flag;
(void)irq;
intc_flag = hdmi_read(hdev, HDMI_INTC_FLAG);
if (intc_flag & HDMI_INTC_FLAG_HPD_UNPLUG) {
pr_info("unplugged\n");
hdmi_write_mask(hdev, HDMI_INTC_FLAG, ~0,
HDMI_INTC_FLAG_HPD_UNPLUG);
}
if (intc_flag & HDMI_INTC_FLAG_HPD_PLUG) {
pr_info("plugged\n");
hdmi_write_mask(hdev, HDMI_INTC_FLAG, ~0,
HDMI_INTC_FLAG_HPD_PLUG);
}
return IRQ_HANDLED;
}
static void hdmi_reg_init(struct hdmi_device *hdev)
{
hdmi_write_mask(hdev, HDMI_INTC_CON, ~0, HDMI_INTC_EN_GLOBAL |
HDMI_INTC_EN_HPD_PLUG | HDMI_INTC_EN_HPD_UNPLUG);
hdmi_write_mask(hdev, HDMI_MODE_SEL,
HDMI_MODE_DVI_EN, HDMI_MODE_MASK);
hdmi_write_mask(hdev, HDMI_CON_2, ~0,
HDMI_DVI_PERAMBLE_EN | HDMI_DVI_BAND_EN);
hdmi_write_mask(hdev, HDMI_CON_0, 0, HDMI_BLUE_SCR_EN);
hdmi_writeb(hdev, HDMI_BLUE_SCREEN_0, 0x12);
hdmi_writeb(hdev, HDMI_BLUE_SCREEN_1, 0x34);
hdmi_writeb(hdev, HDMI_BLUE_SCREEN_2, 0x56);
}
static void hdmi_timing_apply(struct hdmi_device *hdev,
const struct hdmi_timings *t)
{
hdmi_writebn(hdev, HDMI_H_BLANK_0, 2, t->hact.beg);
hdmi_writebn(hdev, HDMI_H_SYNC_GEN_0, 3,
(t->hsyn_pol << 20) | (t->hsyn.end << 10) | t->hsyn.beg);
hdmi_writeb(hdev, HDMI_VSYNC_POL, t->vsyn_pol);
hdmi_writebn(hdev, HDMI_V_BLANK_0, 3,
(t->vact[0].beg << 11) | t->vact[0].end);
hdmi_writebn(hdev, HDMI_V_SYNC_GEN_1_0, 3,
(t->vsyn[0].beg << 12) | t->vsyn[0].end);
if (t->interlaced) {
u32 vsyn_trans = t->hsyn.beg + t->vsyn_off;
hdmi_writeb(hdev, HDMI_INT_PRO_MODE, 1);
hdmi_writebn(hdev, HDMI_H_V_LINE_0, 3,
(t->hact.end << 12) | t->vact[1].end);
hdmi_writebn(hdev, HDMI_V_BLANK_F_0, 3,
(t->vact[1].end << 11) | t->vact[1].beg);
hdmi_writebn(hdev, HDMI_V_SYNC_GEN_2_0, 3,
(t->vsyn[1].beg << 12) | t->vsyn[1].end);
hdmi_writebn(hdev, HDMI_V_SYNC_GEN_3_0, 3,
(vsyn_trans << 12) | vsyn_trans);
} else {
hdmi_writeb(hdev, HDMI_INT_PRO_MODE, 0);
hdmi_writebn(hdev, HDMI_H_V_LINE_0, 3,
(t->hact.end << 12) | t->vact[0].end);
}
hdmi_writebn(hdev, HDMI_TG_H_FSZ_L, 2, t->hact.end);
hdmi_writebn(hdev, HDMI_TG_HACT_ST_L, 2, t->hact.beg);
hdmi_writebn(hdev, HDMI_TG_HACT_SZ_L, 2, t->hact.end - t->hact.beg);
hdmi_writebn(hdev, HDMI_TG_VSYNC_L, 2, t->vsyn[0].beg);
hdmi_writebn(hdev, HDMI_TG_VACT_ST_L, 2, t->vact[0].beg);
hdmi_writebn(hdev, HDMI_TG_VACT_SZ_L, 2,
t->vact[0].end - t->vact[0].beg);
hdmi_writebn(hdev, HDMI_TG_VSYNC_TOP_HDMI_L, 2, t->vsyn[0].beg);
hdmi_writebn(hdev, HDMI_TG_FIELD_TOP_HDMI_L, 2, t->vsyn[0].beg);
if (t->interlaced) {
hdmi_write_mask(hdev, HDMI_TG_CMD, ~0, HDMI_TG_FIELD_EN);
hdmi_writebn(hdev, HDMI_TG_V_FSZ_L, 2, t->vact[1].end);
hdmi_writebn(hdev, HDMI_TG_VSYNC2_L, 2, t->vsyn[1].beg);
hdmi_writebn(hdev, HDMI_TG_FIELD_CHG_L, 2, t->vact[0].end);
hdmi_writebn(hdev, HDMI_TG_VACT_ST2_L, 2, t->vact[1].beg);
hdmi_writebn(hdev, HDMI_TG_VSYNC_BOT_HDMI_L, 2, t->vsyn[1].beg);
hdmi_writebn(hdev, HDMI_TG_FIELD_BOT_HDMI_L, 2, t->vsyn[1].beg);
} else {
hdmi_write_mask(hdev, HDMI_TG_CMD, 0, HDMI_TG_FIELD_EN);
hdmi_writebn(hdev, HDMI_TG_V_FSZ_L, 2, t->vact[0].end);
}
}
static int hdmi_conf_apply(struct hdmi_device *hdmi_dev)
{
struct device *dev = hdmi_dev->dev;
const struct hdmi_timings *conf = hdmi_dev->cur_conf;
struct v4l2_dv_preset preset;
int ret;
dev_dbg(dev, "%s\n", __func__);
if (!hdmi_dev->cur_conf_dirty)
return 0;
hdmi_write_mask(hdmi_dev, HDMI_PHY_RSTOUT, ~0, HDMI_PHY_SW_RSTOUT);
mdelay(10);
hdmi_write_mask(hdmi_dev, HDMI_PHY_RSTOUT, 0, HDMI_PHY_SW_RSTOUT);
mdelay(10);
preset.preset = hdmi_dev->cur_preset;
ret = v4l2_subdev_call(hdmi_dev->phy_sd, video, s_dv_preset, &preset);
if (ret) {
dev_err(dev, "failed to set preset (%u)\n", preset.preset);
return ret;
}
hdmi_write_mask(hdmi_dev, HDMI_CORE_RSTOUT, 0, HDMI_CORE_SW_RSTOUT);
mdelay(10);
hdmi_write_mask(hdmi_dev, HDMI_CORE_RSTOUT, ~0, HDMI_CORE_SW_RSTOUT);
mdelay(10);
hdmi_reg_init(hdmi_dev);
hdmi_timing_apply(hdmi_dev, conf);
hdmi_dev->cur_conf_dirty = 0;
return 0;
}
static void hdmi_dumpregs(struct hdmi_device *hdev, char *prefix)
{
#define DUMPREG(reg_id) \
dev_dbg(hdev->dev, "%s:" #reg_id " = %08x\n", prefix, \
readl(hdev->regs + reg_id))
dev_dbg(hdev->dev, "%s: ---- CONTROL REGISTERS ----\n", prefix);
DUMPREG(HDMI_INTC_FLAG);
DUMPREG(HDMI_INTC_CON);
DUMPREG(HDMI_HPD_STATUS);
DUMPREG(HDMI_PHY_RSTOUT);
DUMPREG(HDMI_PHY_VPLL);
DUMPREG(HDMI_PHY_CMU);
DUMPREG(HDMI_CORE_RSTOUT);
dev_dbg(hdev->dev, "%s: ---- CORE REGISTERS ----\n", prefix);
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
dev_dbg(hdev->dev, "%s: ---- CORE SYNC REGISTERS ----\n", prefix);
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
dev_dbg(hdev->dev, "%s: ---- TG REGISTERS ----\n", prefix);
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
static const struct hdmi_timings *hdmi_preset2timings(u32 preset)
{
int i;
for (i = 0; i < ARRAY_SIZE(hdmi_timings); ++i)
if (hdmi_timings[i].preset == preset)
return hdmi_timings[i].timings;
return NULL;
}
static int hdmi_streamon(struct hdmi_device *hdev)
{
struct device *dev = hdev->dev;
struct hdmi_resources *res = &hdev->res;
int ret, tries;
dev_dbg(dev, "%s\n", __func__);
ret = hdmi_conf_apply(hdev);
if (ret)
return ret;
ret = v4l2_subdev_call(hdev->phy_sd, video, s_stream, 1);
if (ret)
return ret;
for (tries = 100; tries; --tries) {
u32 val = hdmi_read(hdev, HDMI_PHY_STATUS);
if (val & HDMI_PHY_STATUS_READY)
break;
mdelay(1);
}
if (tries == 0) {
dev_err(dev, "hdmiphy's pll could not reach steady state.\n");
v4l2_subdev_call(hdev->phy_sd, video, s_stream, 0);
hdmi_dumpregs(hdev, "hdmiphy - s_stream");
return -EIO;
}
ret = v4l2_subdev_call(hdev->mhl_sd, video, s_stream, 1);
if (hdev->mhl_sd && ret) {
v4l2_subdev_call(hdev->phy_sd, video, s_stream, 0);
hdmi_dumpregs(hdev, "mhl - s_stream");
return -EIO;
}
clk_disable(res->sclk_hdmi);
clk_set_parent(res->sclk_hdmi, res->sclk_hdmiphy);
clk_enable(res->sclk_hdmi);
hdmi_write_mask(hdev, HDMI_CON_0, ~0, HDMI_EN);
hdmi_write_mask(hdev, HDMI_TG_CMD, ~0, HDMI_TG_EN);
hdmi_dumpregs(hdev, "streamon");
return 0;
}
static int hdmi_streamoff(struct hdmi_device *hdev)
{
struct device *dev = hdev->dev;
struct hdmi_resources *res = &hdev->res;
dev_dbg(dev, "%s\n", __func__);
hdmi_write_mask(hdev, HDMI_CON_0, 0, HDMI_EN);
hdmi_write_mask(hdev, HDMI_TG_CMD, 0, HDMI_TG_EN);
clk_disable(res->sclk_hdmi);
clk_set_parent(res->sclk_hdmi, res->sclk_pixel);
clk_enable(res->sclk_hdmi);
v4l2_subdev_call(hdev->mhl_sd, video, s_stream, 0);
v4l2_subdev_call(hdev->phy_sd, video, s_stream, 0);
hdmi_dumpregs(hdev, "streamoff");
return 0;
}
static int hdmi_s_stream(struct v4l2_subdev *sd, int enable)
{
struct hdmi_device *hdev = sd_to_hdmi_dev(sd);
struct device *dev = hdev->dev;
dev_dbg(dev, "%s(%d)\n", __func__, enable);
if (enable)
return hdmi_streamon(hdev);
return hdmi_streamoff(hdev);
}
static void hdmi_resource_poweron(struct hdmi_resources *res)
{
regulator_bulk_enable(res->regul_count, res->regul_bulk);
clk_enable(res->hdmiphy);
clk_set_parent(res->sclk_hdmi, res->sclk_pixel);
clk_enable(res->sclk_hdmi);
}
static void hdmi_resource_poweroff(struct hdmi_resources *res)
{
clk_disable(res->sclk_hdmi);
clk_disable(res->hdmiphy);
regulator_bulk_disable(res->regul_count, res->regul_bulk);
}
static int hdmi_s_power(struct v4l2_subdev *sd, int on)
{
struct hdmi_device *hdev = sd_to_hdmi_dev(sd);
int ret;
if (on)
ret = pm_runtime_get_sync(hdev->dev);
else
ret = pm_runtime_put_sync(hdev->dev);
return IS_ERR_VALUE(ret) ? ret : 0;
}
static int hdmi_s_dv_preset(struct v4l2_subdev *sd,
struct v4l2_dv_preset *preset)
{
struct hdmi_device *hdev = sd_to_hdmi_dev(sd);
struct device *dev = hdev->dev;
const struct hdmi_timings *conf;
conf = hdmi_preset2timings(preset->preset);
if (conf == NULL) {
dev_err(dev, "preset (%u) not supported\n", preset->preset);
return -EINVAL;
}
hdev->cur_conf = conf;
hdev->cur_conf_dirty = 1;
hdev->cur_preset = preset->preset;
return 0;
}
static int hdmi_g_dv_preset(struct v4l2_subdev *sd,
struct v4l2_dv_preset *preset)
{
memset(preset, 0, sizeof(*preset));
preset->preset = sd_to_hdmi_dev(sd)->cur_preset;
return 0;
}
static int hdmi_g_mbus_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *fmt)
{
struct hdmi_device *hdev = sd_to_hdmi_dev(sd);
const struct hdmi_timings *t = hdev->cur_conf;
dev_dbg(hdev->dev, "%s\n", __func__);
if (!hdev->cur_conf)
return -EINVAL;
memset(fmt, 0, sizeof(*fmt));
fmt->width = t->hact.end - t->hact.beg;
fmt->height = t->vact[0].end - t->vact[0].beg;
fmt->code = V4L2_MBUS_FMT_FIXED;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
if (t->interlaced) {
fmt->field = V4L2_FIELD_INTERLACED;
fmt->height *= 2;
} else {
fmt->field = V4L2_FIELD_NONE;
}
return 0;
}
static int hdmi_enum_dv_presets(struct v4l2_subdev *sd,
struct v4l2_dv_enum_preset *preset)
{
if (preset->index >= ARRAY_SIZE(hdmi_timings))
return -EINVAL;
return v4l_fill_dv_preset_info(hdmi_timings[preset->index].preset,
preset);
}
static int hdmi_runtime_suspend(struct device *dev)
{
struct v4l2_subdev *sd = dev_get_drvdata(dev);
struct hdmi_device *hdev = sd_to_hdmi_dev(sd);
dev_dbg(dev, "%s\n", __func__);
v4l2_subdev_call(hdev->mhl_sd, core, s_power, 0);
hdmi_resource_poweroff(&hdev->res);
hdev->cur_conf_dirty = 1;
return 0;
}
static int hdmi_runtime_resume(struct device *dev)
{
struct v4l2_subdev *sd = dev_get_drvdata(dev);
struct hdmi_device *hdev = sd_to_hdmi_dev(sd);
int ret = 0;
dev_dbg(dev, "%s\n", __func__);
hdmi_resource_poweron(&hdev->res);
ret = v4l2_subdev_call(hdev->mhl_sd, core, s_power, 1);
if (hdev->mhl_sd && ret)
goto fail;
dev_dbg(dev, "poweron succeed\n");
return 0;
fail:
hdmi_resource_poweroff(&hdev->res);
dev_err(dev, "poweron failed\n");
return ret;
}
static void hdmi_resources_cleanup(struct hdmi_device *hdev)
{
struct hdmi_resources *res = &hdev->res;
dev_dbg(hdev->dev, "HDMI resource cleanup\n");
if (res->regul_count)
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
memset(res, 0, sizeof(*res));
}
static int hdmi_resources_init(struct hdmi_device *hdev)
{
struct device *dev = hdev->dev;
struct hdmi_resources *res = &hdev->res;
static char *supply[] = {
"hdmi-en",
"vdd",
"vdd_osc",
"vdd_pll",
};
int i, ret;
dev_dbg(dev, "HDMI resource init\n");
memset(res, 0, sizeof(*res));
res->hdmi = clk_get(dev, "hdmi");
if (IS_ERR(res->hdmi)) {
dev_err(dev, "failed to get clock 'hdmi'\n");
goto fail;
}
res->sclk_hdmi = clk_get(dev, "sclk_hdmi");
if (IS_ERR(res->sclk_hdmi)) {
dev_err(dev, "failed to get clock 'sclk_hdmi'\n");
goto fail;
}
res->sclk_pixel = clk_get(dev, "sclk_pixel");
if (IS_ERR(res->sclk_pixel)) {
dev_err(dev, "failed to get clock 'sclk_pixel'\n");
goto fail;
}
res->sclk_hdmiphy = clk_get(dev, "sclk_hdmiphy");
if (IS_ERR(res->sclk_hdmiphy)) {
dev_err(dev, "failed to get clock 'sclk_hdmiphy'\n");
goto fail;
}
res->hdmiphy = clk_get(dev, "hdmiphy");
if (IS_ERR(res->hdmiphy)) {
dev_err(dev, "failed to get clock 'hdmiphy'\n");
goto fail;
}
res->regul_bulk = kcalloc(ARRAY_SIZE(supply),
sizeof(res->regul_bulk[0]), GFP_KERNEL);
if (!res->regul_bulk) {
dev_err(dev, "failed to get memory for regulators\n");
goto fail;
}
for (i = 0; i < ARRAY_SIZE(supply); ++i) {
res->regul_bulk[i].supply = supply[i];
res->regul_bulk[i].consumer = NULL;
}
ret = regulator_bulk_get(dev, ARRAY_SIZE(supply), res->regul_bulk);
if (ret) {
dev_err(dev, "failed to get regulators\n");
goto fail;
}
res->regul_count = ARRAY_SIZE(supply);
return 0;
fail:
dev_err(dev, "HDMI resource init - failed\n");
hdmi_resources_cleanup(hdev);
return -ENODEV;
}
static int hdmi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct i2c_adapter *adapter;
struct v4l2_subdev *sd;
struct hdmi_device *hdmi_dev = NULL;
struct s5p_hdmi_platform_data *pdata = dev->platform_data;
int ret;
dev_dbg(dev, "probe start\n");
if (!pdata) {
dev_err(dev, "platform data is missing\n");
ret = -ENODEV;
goto fail;
}
hdmi_dev = devm_kzalloc(&pdev->dev, sizeof(*hdmi_dev), GFP_KERNEL);
if (!hdmi_dev) {
dev_err(dev, "out of memory\n");
ret = -ENOMEM;
goto fail;
}
hdmi_dev->dev = dev;
ret = hdmi_resources_init(hdmi_dev);
if (ret)
goto fail;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(dev, "get memory resource failed.\n");
ret = -ENXIO;
goto fail_init;
}
hdmi_dev->regs = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (hdmi_dev->regs == NULL) {
dev_err(dev, "register mapping failed.\n");
ret = -ENXIO;
goto fail_init;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
dev_err(dev, "get interrupt resource failed.\n");
ret = -ENXIO;
goto fail_init;
}
ret = devm_request_irq(&pdev->dev, res->start, hdmi_irq_handler, 0,
"hdmi", hdmi_dev);
if (ret) {
dev_err(dev, "request interrupt failed.\n");
goto fail_init;
}
hdmi_dev->irq = res->start;
strlcpy(hdmi_dev->v4l2_dev.name, dev_name(dev),
sizeof(hdmi_dev->v4l2_dev.name));
ret = v4l2_device_register(NULL, &hdmi_dev->v4l2_dev);
if (ret) {
dev_err(dev, "could not register v4l2 device.\n");
goto fail_init;
}
if (!pdata->hdmiphy_info) {
dev_err(dev, "hdmiphy info is missing in platform data\n");
ret = -ENXIO;
goto fail_vdev;
}
adapter = i2c_get_adapter(pdata->hdmiphy_bus);
if (adapter == NULL) {
dev_err(dev, "hdmiphy adapter request failed\n");
ret = -ENXIO;
goto fail_vdev;
}
hdmi_dev->phy_sd = v4l2_i2c_new_subdev_board(&hdmi_dev->v4l2_dev,
adapter, pdata->hdmiphy_info, NULL);
i2c_put_adapter(adapter);
if (hdmi_dev->phy_sd == NULL) {
dev_err(dev, "missing subdev for hdmiphy\n");
ret = -ENODEV;
goto fail_vdev;
}
if (pdata->mhl_info) {
adapter = i2c_get_adapter(pdata->mhl_bus);
if (adapter == NULL) {
dev_err(dev, "MHL adapter request failed\n");
ret = -ENXIO;
goto fail_vdev;
}
hdmi_dev->mhl_sd = v4l2_i2c_new_subdev_board(
&hdmi_dev->v4l2_dev, adapter,
pdata->mhl_info, NULL);
i2c_put_adapter(adapter);
if (hdmi_dev->mhl_sd == NULL) {
dev_err(dev, "missing subdev for MHL\n");
ret = -ENODEV;
goto fail_vdev;
}
}
clk_enable(hdmi_dev->res.hdmi);
pm_runtime_enable(dev);
sd = &hdmi_dev->sd;
v4l2_subdev_init(sd, &hdmi_sd_ops);
sd->owner = THIS_MODULE;
strlcpy(sd->name, "s5p-hdmi", sizeof(sd->name));
hdmi_dev->cur_preset = HDMI_DEFAULT_PRESET;
hdmi_dev->cur_conf = hdmi_preset2timings(hdmi_dev->cur_preset);
hdmi_dev->cur_conf_dirty = 1;
dev_set_drvdata(dev, sd);
dev_info(dev, "probe successful\n");
return 0;
fail_vdev:
v4l2_device_unregister(&hdmi_dev->v4l2_dev);
fail_init:
hdmi_resources_cleanup(hdmi_dev);
fail:
dev_err(dev, "probe failed\n");
return ret;
}
static int hdmi_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct v4l2_subdev *sd = dev_get_drvdata(dev);
struct hdmi_device *hdmi_dev = sd_to_hdmi_dev(sd);
pm_runtime_disable(dev);
clk_disable(hdmi_dev->res.hdmi);
v4l2_device_unregister(&hdmi_dev->v4l2_dev);
disable_irq(hdmi_dev->irq);
hdmi_resources_cleanup(hdmi_dev);
dev_info(dev, "remove successful\n");
return 0;
}
