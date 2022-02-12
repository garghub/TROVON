static const struct csid_fmts *csid_get_fmt_entry(u32 code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(csid_input_fmts); i++)
if (code == csid_input_fmts[i].code)
return &csid_input_fmts[i];
WARN(1, "Unknown format\n");
return &csid_input_fmts[0];
}
static irqreturn_t csid_isr(int irq, void *dev)
{
struct csid_device *csid = dev;
u32 value;
value = readl_relaxed(csid->base + CAMSS_CSID_IRQ_STATUS);
writel_relaxed(value, csid->base + CAMSS_CSID_IRQ_CLEAR_CMD);
if ((value >> 11) & 0x1)
complete(&csid->reset_complete);
return IRQ_HANDLED;
}
static int csid_set_clock_rates(struct csid_device *csid)
{
struct device *dev = to_device_index(csid, csid->id);
u32 pixel_clock;
int i, j;
int ret;
ret = camss_get_pixel_clock(&csid->subdev.entity, &pixel_clock);
if (ret)
pixel_clock = 0;
for (i = 0; i < csid->nclocks; i++) {
struct camss_clock *clock = &csid->clock[i];
if (!strcmp(clock->name, "csi0") ||
!strcmp(clock->name, "csi1")) {
u8 bpp = csid_get_fmt_entry(
csid->fmt[MSM_CSIPHY_PAD_SINK].code)->bpp;
u8 num_lanes = csid->phy.lane_cnt;
u64 min_rate = pixel_clock * bpp / (2 * num_lanes * 4);
long rate;
camss_add_clock_margin(&min_rate);
for (j = 0; j < clock->nfreqs; j++)
if (min_rate < clock->freq[j])
break;
if (j == clock->nfreqs) {
dev_err(dev,
"Pixel clock is too high for CSID\n");
return -EINVAL;
}
if (min_rate == 0)
j = clock->nfreqs - 1;
rate = clk_round_rate(clock->clk, clock->freq[j]);
if (rate < 0) {
dev_err(dev, "clk round rate failed: %ld\n",
rate);
return -EINVAL;
}
ret = clk_set_rate(clock->clk, rate);
if (ret < 0) {
dev_err(dev, "clk set rate failed: %d\n", ret);
return ret;
}
}
}
return 0;
}
static int csid_reset(struct csid_device *csid)
{
unsigned long time;
reinit_completion(&csid->reset_complete);
writel_relaxed(0x7fff, csid->base + CAMSS_CSID_RST_CMD);
time = wait_for_completion_timeout(&csid->reset_complete,
msecs_to_jiffies(CSID_RESET_TIMEOUT_MS));
if (!time) {
dev_err(to_device_index(csid, csid->id),
"CSID reset timeout\n");
return -EIO;
}
return 0;
}
static int csid_set_power(struct v4l2_subdev *sd, int on)
{
struct csid_device *csid = v4l2_get_subdevdata(sd);
struct device *dev = to_device_index(csid, csid->id);
int ret;
if (on) {
u32 hw_version;
ret = regulator_enable(csid->vdda);
if (ret < 0)
return ret;
ret = csid_set_clock_rates(csid);
if (ret < 0) {
regulator_disable(csid->vdda);
return ret;
}
ret = camss_enable_clocks(csid->nclocks, csid->clock, dev);
if (ret < 0) {
regulator_disable(csid->vdda);
return ret;
}
enable_irq(csid->irq);
ret = csid_reset(csid);
if (ret < 0) {
disable_irq(csid->irq);
camss_disable_clocks(csid->nclocks, csid->clock);
regulator_disable(csid->vdda);
return ret;
}
hw_version = readl_relaxed(csid->base + CAMSS_CSID_HW_VERSION);
dev_dbg(dev, "CSID HW Version = 0x%08x\n", hw_version);
} else {
disable_irq(csid->irq);
camss_disable_clocks(csid->nclocks, csid->clock);
ret = regulator_disable(csid->vdda);
}
return ret;
}
static int csid_set_stream(struct v4l2_subdev *sd, int enable)
{
struct csid_device *csid = v4l2_get_subdevdata(sd);
struct csid_testgen_config *tg = &csid->testgen;
u32 val;
if (enable) {
u8 vc = 0;
u8 cid = vc * 4;
u8 dt, dt_shift, df;
int ret;
ret = v4l2_ctrl_handler_setup(&csid->ctrls);
if (ret < 0) {
dev_err(to_device_index(csid, csid->id),
"could not sync v4l2 controls: %d\n", ret);
return ret;
}
if (!tg->enabled &&
!media_entity_remote_pad(&csid->pads[MSM_CSID_PAD_SINK]))
return -ENOLINK;
dt = csid_get_fmt_entry(csid->fmt[MSM_CSID_PAD_SRC].code)->
data_type;
if (tg->enabled) {
struct v4l2_mbus_framefmt *f =
&csid->fmt[MSM_CSID_PAD_SRC];
u8 bpp = csid_get_fmt_entry(f->code)->bpp;
u8 spp = csid_get_fmt_entry(f->code)->spp;
u32 num_bytes_per_line = f->width * bpp * spp / 8;
u32 num_lines = f->height;
val = ((CAMSS_CSID_TG_VC_CFG_V_BLANKING & 0xff) << 24) |
((CAMSS_CSID_TG_VC_CFG_H_BLANKING & 0x7ff) << 13);
writel_relaxed(val, csid->base + CAMSS_CSID_TG_VC_CFG);
val = ((num_bytes_per_line & 0x1fff) << 16) |
(num_lines & 0x1fff);
writel_relaxed(val, csid->base +
CAMSS_CSID_TG_DT_n_CGG_0(0));
val = dt;
writel_relaxed(val, csid->base +
CAMSS_CSID_TG_DT_n_CGG_1(0));
val = tg->payload_mode;
writel_relaxed(val, csid->base +
CAMSS_CSID_TG_DT_n_CGG_2(0));
} else {
struct csid_phy_config *phy = &csid->phy;
val = phy->lane_cnt - 1;
val |= phy->lane_assign << 4;
writel_relaxed(val,
csid->base + CAMSS_CSID_CORE_CTRL_0);
val = phy->csiphy_id << 17;
val |= 0x9;
writel_relaxed(val,
csid->base + CAMSS_CSID_CORE_CTRL_1);
}
dt_shift = (cid % 4) * 8;
df = csid_get_fmt_entry(csid->fmt[MSM_CSID_PAD_SINK].code)->
decode_format;
val = readl_relaxed(csid->base + CAMSS_CSID_CID_LUT_VC_n(vc));
val &= ~(0xff << dt_shift);
val |= dt << dt_shift;
writel_relaxed(val, csid->base + CAMSS_CSID_CID_LUT_VC_n(vc));
val = (df << 4) | 0x3;
writel_relaxed(val, csid->base + CAMSS_CSID_CID_n_CFG(cid));
if (tg->enabled) {
val = CAMSS_CSID_TG_CTRL_ENABLE;
writel_relaxed(val, csid->base + CAMSS_CSID_TG_CTRL);
}
} else {
if (tg->enabled) {
val = CAMSS_CSID_TG_CTRL_DISABLE;
writel_relaxed(val, csid->base + CAMSS_CSID_TG_CTRL);
}
}
return 0;
}
static struct v4l2_mbus_framefmt *
__csid_get_format(struct csid_device *csid,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad,
enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(&csid->subdev, cfg, pad);
return &csid->fmt[pad];
}
static void csid_try_format(struct csid_device *csid,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad,
struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
unsigned int i;
switch (pad) {
case MSM_CSID_PAD_SINK:
for (i = 0; i < ARRAY_SIZE(csid_input_fmts); i++)
if (fmt->code == csid_input_fmts[i].code)
break;
if (i >= ARRAY_SIZE(csid_input_fmts))
fmt->code = MEDIA_BUS_FMT_UYVY8_2X8;
fmt->width = clamp_t(u32, fmt->width, 1, 8191);
fmt->height = clamp_t(u32, fmt->height, 1, 8191);
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
break;
case MSM_CSID_PAD_SRC:
if (csid->testgen_mode->cur.val == 0) {
struct v4l2_mbus_framefmt format;
format = *__csid_get_format(csid, cfg,
MSM_CSID_PAD_SINK, which);
*fmt = format;
} else {
for (i = 0; i < ARRAY_SIZE(csid_input_fmts); i++)
if (csid_input_fmts[i].code == fmt->code)
break;
if (i >= ARRAY_SIZE(csid_input_fmts))
fmt->code = MEDIA_BUS_FMT_UYVY8_2X8;
fmt->width = clamp_t(u32, fmt->width, 1, 8191);
fmt->height = clamp_t(u32, fmt->height, 1, 8191);
fmt->field = V4L2_FIELD_NONE;
}
break;
}
fmt->colorspace = V4L2_COLORSPACE_SRGB;
}
static int csid_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct csid_device *csid = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
if (code->pad == MSM_CSID_PAD_SINK) {
if (code->index >= ARRAY_SIZE(csid_input_fmts))
return -EINVAL;
code->code = csid_input_fmts[code->index].code;
} else {
if (csid->testgen_mode->cur.val == 0) {
if (code->index > 0)
return -EINVAL;
format = __csid_get_format(csid, cfg, MSM_CSID_PAD_SINK,
code->which);
code->code = format->code;
} else {
if (code->index >= ARRAY_SIZE(csid_input_fmts))
return -EINVAL;
code->code = csid_input_fmts[code->index].code;
}
}
return 0;
}
static int csid_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct csid_device *csid = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt format;
if (fse->index != 0)
return -EINVAL;
format.code = fse->code;
format.width = 1;
format.height = 1;
csid_try_format(csid, cfg, fse->pad, &format, fse->which);
fse->min_width = format.width;
fse->min_height = format.height;
if (format.code != fse->code)
return -EINVAL;
format.code = fse->code;
format.width = -1;
format.height = -1;
csid_try_format(csid, cfg, fse->pad, &format, fse->which);
fse->max_width = format.width;
fse->max_height = format.height;
return 0;
}
static int csid_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct csid_device *csid = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __csid_get_format(csid, cfg, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
fmt->format = *format;
return 0;
}
static int csid_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct csid_device *csid = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __csid_get_format(csid, cfg, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
csid_try_format(csid, cfg, fmt->pad, &fmt->format, fmt->which);
*format = fmt->format;
if (fmt->pad == MSM_CSID_PAD_SINK) {
format = __csid_get_format(csid, cfg, MSM_CSID_PAD_SRC,
fmt->which);
*format = fmt->format;
csid_try_format(csid, cfg, MSM_CSID_PAD_SRC, format,
fmt->which);
}
return 0;
}
static int csid_init_formats(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_subdev_format format = {
.pad = MSM_CSID_PAD_SINK,
.which = fh ? V4L2_SUBDEV_FORMAT_TRY :
V4L2_SUBDEV_FORMAT_ACTIVE,
.format = {
.code = MEDIA_BUS_FMT_UYVY8_2X8,
.width = 1920,
.height = 1080
}
};
return csid_set_format(sd, fh ? fh->pad : NULL, &format);
}
static int csid_set_test_pattern(struct csid_device *csid, s32 value)
{
struct csid_testgen_config *tg = &csid->testgen;
if (value && media_entity_remote_pad(&csid->pads[MSM_CSID_PAD_SINK]))
return -EBUSY;
tg->enabled = !!value;
switch (value) {
case 1:
tg->payload_mode = CSID_PAYLOAD_MODE_INCREMENTING;
break;
case 2:
tg->payload_mode = CSID_PAYLOAD_MODE_ALTERNATING_55_AA;
break;
case 3:
tg->payload_mode = CSID_PAYLOAD_MODE_ALL_ZEROES;
break;
case 4:
tg->payload_mode = CSID_PAYLOAD_MODE_ALL_ONES;
break;
case 5:
tg->payload_mode = CSID_PAYLOAD_MODE_RANDOM;
break;
}
return 0;
}
static int csid_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct csid_device *csid = container_of(ctrl->handler,
struct csid_device, ctrls);
int ret = -EINVAL;
switch (ctrl->id) {
case V4L2_CID_TEST_PATTERN:
ret = csid_set_test_pattern(csid, ctrl->val);
break;
}
return ret;
}
int msm_csid_subdev_init(struct csid_device *csid,
const struct resources *res, u8 id)
{
struct device *dev = to_device_index(csid, id);
struct platform_device *pdev = to_platform_device(dev);
struct resource *r;
int i, j;
int ret;
csid->id = id;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, res->reg[0]);
csid->base = devm_ioremap_resource(dev, r);
if (IS_ERR(csid->base)) {
dev_err(dev, "could not map memory\n");
return PTR_ERR(csid->base);
}
r = platform_get_resource_byname(pdev, IORESOURCE_IRQ,
res->interrupt[0]);
if (!r) {
dev_err(dev, "missing IRQ\n");
return -EINVAL;
}
csid->irq = r->start;
snprintf(csid->irq_name, sizeof(csid->irq_name), "%s_%s%d",
dev_name(dev), MSM_CSID_NAME, csid->id);
ret = devm_request_irq(dev, csid->irq, csid_isr,
IRQF_TRIGGER_RISING, csid->irq_name, csid);
if (ret < 0) {
dev_err(dev, "request_irq failed: %d\n", ret);
return ret;
}
disable_irq(csid->irq);
csid->nclocks = 0;
while (res->clock[csid->nclocks])
csid->nclocks++;
csid->clock = devm_kzalloc(dev, csid->nclocks * sizeof(*csid->clock),
GFP_KERNEL);
if (!csid->clock)
return -ENOMEM;
for (i = 0; i < csid->nclocks; i++) {
struct camss_clock *clock = &csid->clock[i];
clock->clk = devm_clk_get(dev, res->clock[i]);
if (IS_ERR(clock->clk))
return PTR_ERR(clock->clk);
clock->name = res->clock[i];
clock->nfreqs = 0;
while (res->clock_rate[i][clock->nfreqs])
clock->nfreqs++;
if (!clock->nfreqs) {
clock->freq = NULL;
continue;
}
clock->freq = devm_kzalloc(dev, clock->nfreqs *
sizeof(*clock->freq), GFP_KERNEL);
if (!clock->freq)
return -ENOMEM;
for (j = 0; j < clock->nfreqs; j++)
clock->freq[j] = res->clock_rate[i][j];
}
csid->vdda = devm_regulator_get(dev, res->regulator[0]);
if (IS_ERR(csid->vdda)) {
dev_err(dev, "could not get regulator\n");
return PTR_ERR(csid->vdda);
}
init_completion(&csid->reset_complete);
return 0;
}
void msm_csid_get_csid_id(struct media_entity *entity, u8 *id)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct csid_device *csid = v4l2_get_subdevdata(sd);
*id = csid->id;
}
static u32 csid_get_lane_assign(struct csiphy_lanes_cfg *lane_cfg)
{
u32 lane_assign = 0;
int i;
for (i = 0; i < lane_cfg->num_data; i++)
lane_assign |= lane_cfg->data[i].pos << (i * 4);
return lane_assign;
}
static int csid_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
if (flags & MEDIA_LNK_FL_ENABLED)
if (media_entity_remote_pad(local))
return -EBUSY;
if ((local->flags & MEDIA_PAD_FL_SINK) &&
(flags & MEDIA_LNK_FL_ENABLED)) {
struct v4l2_subdev *sd;
struct csid_device *csid;
struct csiphy_device *csiphy;
struct csiphy_lanes_cfg *lane_cfg;
struct v4l2_subdev_format format = { 0 };
sd = media_entity_to_v4l2_subdev(entity);
csid = v4l2_get_subdevdata(sd);
if (csid->testgen_mode->cur.val != 0)
return -EBUSY;
sd = media_entity_to_v4l2_subdev(remote->entity);
csiphy = v4l2_get_subdevdata(sd);
if (!csiphy->cfg.csi2)
return -EPERM;
csid->phy.csiphy_id = csiphy->id;
lane_cfg = &csiphy->cfg.csi2->lane_cfg;
csid->phy.lane_cnt = lane_cfg->num_data;
csid->phy.lane_assign = csid_get_lane_assign(lane_cfg);
format.pad = MSM_CSID_PAD_SRC;
format.which = V4L2_SUBDEV_FORMAT_ACTIVE;
csid_set_format(&csid->subdev, NULL, &format);
}
return 0;
}
int msm_csid_register_entity(struct csid_device *csid,
struct v4l2_device *v4l2_dev)
{
struct v4l2_subdev *sd = &csid->subdev;
struct media_pad *pads = csid->pads;
struct device *dev = to_device_index(csid, csid->id);
int ret;
v4l2_subdev_init(sd, &csid_v4l2_ops);
sd->internal_ops = &csid_v4l2_internal_ops;
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
snprintf(sd->name, ARRAY_SIZE(sd->name), "%s%d",
MSM_CSID_NAME, csid->id);
v4l2_set_subdevdata(sd, csid);
ret = v4l2_ctrl_handler_init(&csid->ctrls, 1);
if (ret < 0) {
dev_err(dev, "Failed to init ctrl handler: %d\n", ret);
return ret;
}
csid->testgen_mode = v4l2_ctrl_new_std_menu_items(&csid->ctrls,
&csid_ctrl_ops, V4L2_CID_TEST_PATTERN,
ARRAY_SIZE(csid_test_pattern_menu) - 1, 0, 0,
csid_test_pattern_menu);
if (csid->ctrls.error) {
dev_err(dev, "Failed to init ctrl: %d\n", csid->ctrls.error);
ret = csid->ctrls.error;
goto free_ctrl;
}
csid->subdev.ctrl_handler = &csid->ctrls;
ret = csid_init_formats(sd, NULL);
if (ret < 0) {
dev_err(dev, "Failed to init format: %d\n", ret);
goto free_ctrl;
}
pads[MSM_CSID_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
pads[MSM_CSID_PAD_SRC].flags = MEDIA_PAD_FL_SOURCE;
sd->entity.function = MEDIA_ENT_F_IO_V4L;
sd->entity.ops = &csid_media_ops;
ret = media_entity_pads_init(&sd->entity, MSM_CSID_PADS_NUM, pads);
if (ret < 0) {
dev_err(dev, "Failed to init media entity: %d\n", ret);
goto free_ctrl;
}
ret = v4l2_device_register_subdev(v4l2_dev, sd);
if (ret < 0) {
dev_err(dev, "Failed to register subdev: %d\n", ret);
goto media_cleanup;
}
return 0;
media_cleanup:
media_entity_cleanup(&sd->entity);
free_ctrl:
v4l2_ctrl_handler_free(&csid->ctrls);
return ret;
}
void msm_csid_unregister_entity(struct csid_device *csid)
{
v4l2_device_unregister_subdev(&csid->subdev);
media_entity_cleanup(&csid->subdev.entity);
v4l2_ctrl_handler_free(&csid->ctrls);
}
