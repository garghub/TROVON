static u8 csiphy_get_bpp(u32 code)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(csiphy_formats); i++)
if (code == csiphy_formats[i].code)
return csiphy_formats[i].bpp;
WARN(1, "Unknown format\n");
return csiphy_formats[0].bpp;
}
static irqreturn_t csiphy_isr(int irq, void *dev)
{
struct csiphy_device *csiphy = dev;
u8 i;
for (i = 0; i < 8; i++) {
u8 val = readl_relaxed(csiphy->base +
CAMSS_CSI_PHY_INTERRUPT_STATUSn(i));
writel_relaxed(val, csiphy->base +
CAMSS_CSI_PHY_INTERRUPT_CLEARn(i));
writel_relaxed(0x1, csiphy->base + CAMSS_CSI_PHY_GLBL_IRQ_CMD);
writel_relaxed(0x0, csiphy->base + CAMSS_CSI_PHY_GLBL_IRQ_CMD);
writel_relaxed(0x0, csiphy->base +
CAMSS_CSI_PHY_INTERRUPT_CLEARn(i));
}
return IRQ_HANDLED;
}
static int csiphy_set_clock_rates(struct csiphy_device *csiphy)
{
struct device *dev = to_device_index(csiphy, csiphy->id);
u32 pixel_clock;
int i, j;
int ret;
ret = camss_get_pixel_clock(&csiphy->subdev.entity, &pixel_clock);
if (ret)
pixel_clock = 0;
for (i = 0; i < csiphy->nclocks; i++) {
struct camss_clock *clock = &csiphy->clock[i];
if (!strcmp(clock->name, "csiphy0_timer") ||
!strcmp(clock->name, "csiphy1_timer")) {
u8 bpp = csiphy_get_bpp(
csiphy->fmt[MSM_CSIPHY_PAD_SINK].code);
u8 num_lanes = csiphy->cfg.csi2->lane_cfg.num_data;
u64 min_rate = pixel_clock * bpp / (2 * num_lanes * 4);
long round_rate;
camss_add_clock_margin(&min_rate);
for (j = 0; j < clock->nfreqs; j++)
if (min_rate < clock->freq[j])
break;
if (j == clock->nfreqs) {
dev_err(dev,
"Pixel clock is too high for CSIPHY\n");
return -EINVAL;
}
if (min_rate == 0)
j = clock->nfreqs - 1;
round_rate = clk_round_rate(clock->clk, clock->freq[j]);
if (round_rate < 0) {
dev_err(dev, "clk round rate failed: %ld\n",
round_rate);
return -EINVAL;
}
csiphy->timer_clk_rate = round_rate;
ret = clk_set_rate(clock->clk, csiphy->timer_clk_rate);
if (ret < 0) {
dev_err(dev, "clk set rate failed: %d\n", ret);
return ret;
}
}
}
return 0;
}
static void csiphy_reset(struct csiphy_device *csiphy)
{
writel_relaxed(0x1, csiphy->base + CAMSS_CSI_PHY_GLBL_RESET);
usleep_range(5000, 8000);
writel_relaxed(0x0, csiphy->base + CAMSS_CSI_PHY_GLBL_RESET);
}
static int csiphy_set_power(struct v4l2_subdev *sd, int on)
{
struct csiphy_device *csiphy = v4l2_get_subdevdata(sd);
struct device *dev = to_device_index(csiphy, csiphy->id);
if (on) {
u8 hw_version;
int ret;
ret = csiphy_set_clock_rates(csiphy);
if (ret < 0)
return ret;
ret = camss_enable_clocks(csiphy->nclocks, csiphy->clock, dev);
if (ret < 0)
return ret;
enable_irq(csiphy->irq);
csiphy_reset(csiphy);
hw_version = readl_relaxed(csiphy->base +
CAMSS_CSI_PHY_HW_VERSION);
dev_dbg(dev, "CSIPHY HW Version = 0x%02x\n", hw_version);
} else {
disable_irq(csiphy->irq);
camss_disable_clocks(csiphy->nclocks, csiphy->clock);
}
return 0;
}
static u8 csiphy_get_lane_mask(struct csiphy_lanes_cfg *lane_cfg)
{
u8 lane_mask;
int i;
lane_mask = 1 << lane_cfg->clk.pos;
for (i = 0; i < lane_cfg->num_data; i++)
lane_mask |= 1 << lane_cfg->data[i].pos;
return lane_mask;
}
static u8 csiphy_settle_cnt_calc(struct csiphy_device *csiphy)
{
u8 bpp = csiphy_get_bpp(
csiphy->fmt[MSM_CSIPHY_PAD_SINK].code);
u8 num_lanes = csiphy->cfg.csi2->lane_cfg.num_data;
u32 pixel_clock;
u32 mipi_clock;
u32 ui;
u32 timer_period;
u32 t_hs_prepare_max;
u32 t_hs_prepare_zero_min;
u32 t_hs_settle;
u8 settle_cnt;
int ret;
ret = camss_get_pixel_clock(&csiphy->subdev.entity, &pixel_clock);
if (ret) {
dev_err(to_device_index(csiphy, csiphy->id),
"Cannot get CSI2 transmitter's pixel clock\n");
return 0;
}
if (!pixel_clock) {
dev_err(to_device_index(csiphy, csiphy->id),
"Got pixel clock == 0, cannot continue\n");
return 0;
}
mipi_clock = pixel_clock * bpp / (2 * num_lanes);
ui = div_u64(1000000000000LL, mipi_clock);
ui /= 2;
t_hs_prepare_max = 85000 + 6 * ui;
t_hs_prepare_zero_min = 145000 + 10 * ui;
t_hs_settle = (t_hs_prepare_max + t_hs_prepare_zero_min) / 2;
timer_period = div_u64(1000000000000LL, csiphy->timer_clk_rate);
settle_cnt = t_hs_settle / timer_period;
return settle_cnt;
}
static int csiphy_stream_on(struct csiphy_device *csiphy)
{
struct csiphy_config *cfg = &csiphy->cfg;
u8 lane_mask = csiphy_get_lane_mask(&cfg->csi2->lane_cfg);
u8 settle_cnt;
u8 val;
int i = 0;
settle_cnt = csiphy_settle_cnt_calc(csiphy);
if (!settle_cnt)
return -EINVAL;
val = readl_relaxed(csiphy->base_clk_mux);
if (cfg->combo_mode && (lane_mask & 0x18) == 0x18) {
val &= ~0xf0;
val |= cfg->csid_id << 4;
} else {
val &= ~0xf;
val |= cfg->csid_id;
}
writel_relaxed(val, csiphy->base_clk_mux);
writel_relaxed(0x1, csiphy->base +
CAMSS_CSI_PHY_GLBL_T_INIT_CFG0);
writel_relaxed(0x1, csiphy->base +
CAMSS_CSI_PHY_T_WAKEUP_CFG0);
val = 0x1;
val |= lane_mask << 1;
writel_relaxed(val, csiphy->base + CAMSS_CSI_PHY_GLBL_PWR_CFG);
val = cfg->combo_mode << 4;
writel_relaxed(val, csiphy->base + CAMSS_CSI_PHY_GLBL_RESET);
while (lane_mask) {
if (lane_mask & 0x1) {
writel_relaxed(0x10, csiphy->base +
CAMSS_CSI_PHY_LNn_CFG2(i));
writel_relaxed(settle_cnt, csiphy->base +
CAMSS_CSI_PHY_LNn_CFG3(i));
writel_relaxed(0x3f, csiphy->base +
CAMSS_CSI_PHY_INTERRUPT_MASKn(i));
writel_relaxed(0x3f, csiphy->base +
CAMSS_CSI_PHY_INTERRUPT_CLEARn(i));
}
lane_mask >>= 1;
i++;
}
return 0;
}
static void csiphy_stream_off(struct csiphy_device *csiphy)
{
u8 lane_mask = csiphy_get_lane_mask(&csiphy->cfg.csi2->lane_cfg);
int i = 0;
while (lane_mask) {
if (lane_mask & 0x1)
writel_relaxed(0x0, csiphy->base +
CAMSS_CSI_PHY_LNn_CFG2(i));
lane_mask >>= 1;
i++;
}
writel_relaxed(0x0, csiphy->base + CAMSS_CSI_PHY_GLBL_PWR_CFG);
}
static int csiphy_set_stream(struct v4l2_subdev *sd, int enable)
{
struct csiphy_device *csiphy = v4l2_get_subdevdata(sd);
int ret = 0;
if (enable)
ret = csiphy_stream_on(csiphy);
else
csiphy_stream_off(csiphy);
return ret;
}
static struct v4l2_mbus_framefmt *
__csiphy_get_format(struct csiphy_device *csiphy,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad,
enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(&csiphy->subdev, cfg, pad);
return &csiphy->fmt[pad];
}
static void csiphy_try_format(struct csiphy_device *csiphy,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad,
struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
unsigned int i;
switch (pad) {
case MSM_CSIPHY_PAD_SINK:
for (i = 0; i < ARRAY_SIZE(csiphy_formats); i++)
if (fmt->code == csiphy_formats[i].code)
break;
if (i >= ARRAY_SIZE(csiphy_formats))
fmt->code = MEDIA_BUS_FMT_UYVY8_2X8;
fmt->width = clamp_t(u32, fmt->width, 1, 8191);
fmt->height = clamp_t(u32, fmt->height, 1, 8191);
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
break;
case MSM_CSIPHY_PAD_SRC:
*fmt = *__csiphy_get_format(csiphy, cfg, MSM_CSID_PAD_SINK,
which);
break;
}
}
static int csiphy_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct csiphy_device *csiphy = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
if (code->pad == MSM_CSIPHY_PAD_SINK) {
if (code->index >= ARRAY_SIZE(csiphy_formats))
return -EINVAL;
code->code = csiphy_formats[code->index].code;
} else {
if (code->index > 0)
return -EINVAL;
format = __csiphy_get_format(csiphy, cfg, MSM_CSIPHY_PAD_SINK,
code->which);
code->code = format->code;
}
return 0;
}
static int csiphy_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct csiphy_device *csiphy = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt format;
if (fse->index != 0)
return -EINVAL;
format.code = fse->code;
format.width = 1;
format.height = 1;
csiphy_try_format(csiphy, cfg, fse->pad, &format, fse->which);
fse->min_width = format.width;
fse->min_height = format.height;
if (format.code != fse->code)
return -EINVAL;
format.code = fse->code;
format.width = -1;
format.height = -1;
csiphy_try_format(csiphy, cfg, fse->pad, &format, fse->which);
fse->max_width = format.width;
fse->max_height = format.height;
return 0;
}
static int csiphy_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct csiphy_device *csiphy = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __csiphy_get_format(csiphy, cfg, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
fmt->format = *format;
return 0;
}
static int csiphy_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct csiphy_device *csiphy = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __csiphy_get_format(csiphy, cfg, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
csiphy_try_format(csiphy, cfg, fmt->pad, &fmt->format, fmt->which);
*format = fmt->format;
if (fmt->pad == MSM_CSIPHY_PAD_SINK) {
format = __csiphy_get_format(csiphy, cfg, MSM_CSIPHY_PAD_SRC,
fmt->which);
*format = fmt->format;
csiphy_try_format(csiphy, cfg, MSM_CSIPHY_PAD_SRC, format,
fmt->which);
}
return 0;
}
static int csiphy_init_formats(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh)
{
struct v4l2_subdev_format format = {
.pad = MSM_CSIPHY_PAD_SINK,
.which = fh ? V4L2_SUBDEV_FORMAT_TRY :
V4L2_SUBDEV_FORMAT_ACTIVE,
.format = {
.code = MEDIA_BUS_FMT_UYVY8_2X8,
.width = 1920,
.height = 1080
}
};
return csiphy_set_format(sd, fh ? fh->pad : NULL, &format);
}
int msm_csiphy_subdev_init(struct csiphy_device *csiphy,
const struct resources *res, u8 id)
{
struct device *dev = to_device_index(csiphy, id);
struct platform_device *pdev = to_platform_device(dev);
struct resource *r;
int i, j;
int ret;
csiphy->id = id;
csiphy->cfg.combo_mode = 0;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, res->reg[0]);
csiphy->base = devm_ioremap_resource(dev, r);
if (IS_ERR(csiphy->base)) {
dev_err(dev, "could not map memory\n");
return PTR_ERR(csiphy->base);
}
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, res->reg[1]);
csiphy->base_clk_mux = devm_ioremap_resource(dev, r);
if (IS_ERR(csiphy->base_clk_mux)) {
dev_err(dev, "could not map memory\n");
return PTR_ERR(csiphy->base_clk_mux);
}
r = platform_get_resource_byname(pdev, IORESOURCE_IRQ,
res->interrupt[0]);
if (!r) {
dev_err(dev, "missing IRQ\n");
return -EINVAL;
}
csiphy->irq = r->start;
snprintf(csiphy->irq_name, sizeof(csiphy->irq_name), "%s_%s%d",
dev_name(dev), MSM_CSIPHY_NAME, csiphy->id);
ret = devm_request_irq(dev, csiphy->irq, csiphy_isr,
IRQF_TRIGGER_RISING, csiphy->irq_name, csiphy);
if (ret < 0) {
dev_err(dev, "request_irq failed: %d\n", ret);
return ret;
}
disable_irq(csiphy->irq);
csiphy->nclocks = 0;
while (res->clock[csiphy->nclocks])
csiphy->nclocks++;
csiphy->clock = devm_kzalloc(dev, csiphy->nclocks *
sizeof(*csiphy->clock), GFP_KERNEL);
if (!csiphy->clock)
return -ENOMEM;
for (i = 0; i < csiphy->nclocks; i++) {
struct camss_clock *clock = &csiphy->clock[i];
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
return 0;
}
static int csiphy_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
if ((local->flags & MEDIA_PAD_FL_SOURCE) &&
(flags & MEDIA_LNK_FL_ENABLED)) {
struct v4l2_subdev *sd;
struct csiphy_device *csiphy;
struct csid_device *csid;
if (media_entity_remote_pad(local))
return -EBUSY;
sd = media_entity_to_v4l2_subdev(entity);
csiphy = v4l2_get_subdevdata(sd);
sd = media_entity_to_v4l2_subdev(remote->entity);
csid = v4l2_get_subdevdata(sd);
csiphy->cfg.csid_id = csid->id;
}
return 0;
}
int msm_csiphy_register_entity(struct csiphy_device *csiphy,
struct v4l2_device *v4l2_dev)
{
struct v4l2_subdev *sd = &csiphy->subdev;
struct media_pad *pads = csiphy->pads;
struct device *dev = to_device_index(csiphy, csiphy->id);
int ret;
v4l2_subdev_init(sd, &csiphy_v4l2_ops);
sd->internal_ops = &csiphy_v4l2_internal_ops;
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
snprintf(sd->name, ARRAY_SIZE(sd->name), "%s%d",
MSM_CSIPHY_NAME, csiphy->id);
v4l2_set_subdevdata(sd, csiphy);
ret = csiphy_init_formats(sd, NULL);
if (ret < 0) {
dev_err(dev, "Failed to init format: %d\n", ret);
return ret;
}
pads[MSM_CSIPHY_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
pads[MSM_CSIPHY_PAD_SRC].flags = MEDIA_PAD_FL_SOURCE;
sd->entity.function = MEDIA_ENT_F_IO_V4L;
sd->entity.ops = &csiphy_media_ops;
ret = media_entity_pads_init(&sd->entity, MSM_CSIPHY_PADS_NUM, pads);
if (ret < 0) {
dev_err(dev, "Failed to init media entity: %d\n", ret);
return ret;
}
ret = v4l2_device_register_subdev(v4l2_dev, sd);
if (ret < 0) {
dev_err(dev, "Failed to register subdev: %d\n", ret);
media_entity_cleanup(&sd->entity);
}
return ret;
}
void msm_csiphy_unregister_entity(struct csiphy_device *csiphy)
{
v4l2_device_unregister_subdev(&csiphy->subdev);
media_entity_cleanup(&csiphy->subdev.entity);
}
