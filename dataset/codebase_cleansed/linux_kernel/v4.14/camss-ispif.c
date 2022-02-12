static irqreturn_t ispif_isr(int irq, void *dev)
{
struct ispif_device *ispif = dev;
u32 value0, value1, value2;
value0 = readl_relaxed(ispif->base + ISPIF_VFE_m_IRQ_STATUS_0(0));
value1 = readl_relaxed(ispif->base + ISPIF_VFE_m_IRQ_STATUS_1(0));
value2 = readl_relaxed(ispif->base + ISPIF_VFE_m_IRQ_STATUS_2(0));
writel_relaxed(value0, ispif->base + ISPIF_VFE_m_IRQ_CLEAR_0(0));
writel_relaxed(value1, ispif->base + ISPIF_VFE_m_IRQ_CLEAR_1(0));
writel_relaxed(value2, ispif->base + ISPIF_VFE_m_IRQ_CLEAR_2(0));
writel(0x1, ispif->base + ISPIF_IRQ_GLOBAL_CLEAR_CMD);
if ((value0 >> 27) & 0x1)
complete(&ispif->reset_complete);
if (unlikely(value0 & ISPIF_VFE_m_IRQ_STATUS_0_PIX0_OVERFLOW))
dev_err_ratelimited(to_device(ispif), "VFE0 pix0 overflow\n");
if (unlikely(value0 & ISPIF_VFE_m_IRQ_STATUS_0_RDI0_OVERFLOW))
dev_err_ratelimited(to_device(ispif), "VFE0 rdi0 overflow\n");
if (unlikely(value1 & ISPIF_VFE_m_IRQ_STATUS_1_PIX1_OVERFLOW))
dev_err_ratelimited(to_device(ispif), "VFE0 pix1 overflow\n");
if (unlikely(value1 & ISPIF_VFE_m_IRQ_STATUS_1_RDI1_OVERFLOW))
dev_err_ratelimited(to_device(ispif), "VFE0 rdi1 overflow\n");
if (unlikely(value2 & ISPIF_VFE_m_IRQ_STATUS_2_RDI2_OVERFLOW))
dev_err_ratelimited(to_device(ispif), "VFE0 rdi2 overflow\n");
return IRQ_HANDLED;
}
static int ispif_reset(struct ispif_device *ispif)
{
unsigned long time;
u32 val;
int ret;
ret = camss_enable_clocks(ispif->nclocks_for_reset,
ispif->clock_for_reset,
to_device(ispif));
if (ret < 0)
return ret;
reinit_completion(&ispif->reset_complete);
val = ISPIF_RST_CMD_0_STROBED_RST_EN |
ISPIF_RST_CMD_0_MISC_LOGIC_RST |
ISPIF_RST_CMD_0_SW_REG_RST |
ISPIF_RST_CMD_0_PIX_INTF_0_CSID_RST |
ISPIF_RST_CMD_0_PIX_INTF_0_VFE_RST |
ISPIF_RST_CMD_0_PIX_INTF_1_CSID_RST |
ISPIF_RST_CMD_0_PIX_INTF_1_VFE_RST |
ISPIF_RST_CMD_0_RDI_INTF_0_CSID_RST |
ISPIF_RST_CMD_0_RDI_INTF_0_VFE_RST |
ISPIF_RST_CMD_0_RDI_INTF_1_CSID_RST |
ISPIF_RST_CMD_0_RDI_INTF_1_VFE_RST |
ISPIF_RST_CMD_0_RDI_INTF_2_CSID_RST |
ISPIF_RST_CMD_0_RDI_INTF_2_VFE_RST |
ISPIF_RST_CMD_0_PIX_OUTPUT_0_MISR_RST |
ISPIF_RST_CMD_0_RDI_OUTPUT_0_MISR_RST |
ISPIF_RST_CMD_0_RDI_OUTPUT_1_MISR_RST |
ISPIF_RST_CMD_0_RDI_OUTPUT_2_MISR_RST;
writel_relaxed(val, ispif->base + ISPIF_RST_CMD_0);
time = wait_for_completion_timeout(&ispif->reset_complete,
msecs_to_jiffies(ISPIF_RESET_TIMEOUT_MS));
if (!time) {
dev_err(to_device(ispif), "ISPIF reset timeout\n");
return -EIO;
}
camss_disable_clocks(ispif->nclocks_for_reset, ispif->clock_for_reset);
return 0;
}
static int ispif_set_power(struct v4l2_subdev *sd, int on)
{
struct ispif_line *line = v4l2_get_subdevdata(sd);
struct ispif_device *ispif = to_ispif(line);
struct device *dev = to_device(ispif);
int ret = 0;
mutex_lock(&ispif->power_lock);
if (on) {
if (ispif->power_count) {
ispif->power_count++;
goto exit;
}
ret = camss_enable_clocks(ispif->nclocks, ispif->clock, dev);
if (ret < 0)
goto exit;
ret = ispif_reset(ispif);
if (ret < 0) {
camss_disable_clocks(ispif->nclocks, ispif->clock);
goto exit;
}
ispif->intf_cmd[line->vfe_id].cmd_0 = CMD_ALL_NO_CHANGE;
ispif->intf_cmd[line->vfe_id].cmd_1 = CMD_ALL_NO_CHANGE;
ispif->power_count++;
} else {
if (ispif->power_count == 0) {
dev_err(dev, "ispif power off on power_count == 0\n");
goto exit;
} else if (ispif->power_count == 1) {
camss_disable_clocks(ispif->nclocks, ispif->clock);
}
ispif->power_count--;
}
exit:
mutex_unlock(&ispif->power_lock);
return ret;
}
static void ispif_select_clk_mux(struct ispif_device *ispif,
enum ispif_intf intf, u8 csid,
u8 vfe, u8 enable)
{
u32 val;
switch (intf) {
case PIX0:
val = readl_relaxed(ispif->base_clk_mux + CSI_PIX_CLK_MUX_SEL);
val &= ~(0xf << (vfe * 8));
if (enable)
val |= (csid << (vfe * 8));
writel_relaxed(val, ispif->base_clk_mux + CSI_PIX_CLK_MUX_SEL);
break;
case RDI0:
val = readl_relaxed(ispif->base_clk_mux + CSI_RDI_CLK_MUX_SEL);
val &= ~(0xf << (vfe * 12));
if (enable)
val |= (csid << (vfe * 12));
writel_relaxed(val, ispif->base_clk_mux + CSI_RDI_CLK_MUX_SEL);
break;
case PIX1:
val = readl_relaxed(ispif->base_clk_mux + CSI_PIX_CLK_MUX_SEL);
val &= ~(0xf << (4 + (vfe * 8)));
if (enable)
val |= (csid << (4 + (vfe * 8)));
writel_relaxed(val, ispif->base_clk_mux + CSI_PIX_CLK_MUX_SEL);
break;
case RDI1:
val = readl_relaxed(ispif->base_clk_mux + CSI_RDI_CLK_MUX_SEL);
val &= ~(0xf << (4 + (vfe * 12)));
if (enable)
val |= (csid << (4 + (vfe * 12)));
writel_relaxed(val, ispif->base_clk_mux + CSI_RDI_CLK_MUX_SEL);
break;
case RDI2:
val = readl_relaxed(ispif->base_clk_mux + CSI_RDI_CLK_MUX_SEL);
val &= ~(0xf << (8 + (vfe * 12)));
if (enable)
val |= (csid << (8 + (vfe * 12)));
writel_relaxed(val, ispif->base_clk_mux + CSI_RDI_CLK_MUX_SEL);
break;
}
mb();
}
static int ispif_validate_intf_status(struct ispif_device *ispif,
enum ispif_intf intf, u8 vfe)
{
int ret = 0;
u32 val = 0;
switch (intf) {
case PIX0:
val = readl_relaxed(ispif->base +
ISPIF_VFE_m_PIX_INTF_n_STATUS(vfe, 0));
break;
case RDI0:
val = readl_relaxed(ispif->base +
ISPIF_VFE_m_RDI_INTF_n_STATUS(vfe, 0));
break;
case PIX1:
val = readl_relaxed(ispif->base +
ISPIF_VFE_m_PIX_INTF_n_STATUS(vfe, 1));
break;
case RDI1:
val = readl_relaxed(ispif->base +
ISPIF_VFE_m_RDI_INTF_n_STATUS(vfe, 1));
break;
case RDI2:
val = readl_relaxed(ispif->base +
ISPIF_VFE_m_RDI_INTF_n_STATUS(vfe, 2));
break;
}
if ((val & 0xf) != 0xf) {
dev_err(to_device(ispif), "%s: ispif is busy: 0x%x\n",
__func__, val);
ret = -EBUSY;
}
return ret;
}
static int ispif_wait_for_stop(struct ispif_device *ispif,
enum ispif_intf intf, u8 vfe)
{
u32 addr = 0;
u32 stop_flag = 0;
int ret;
switch (intf) {
case PIX0:
addr = ISPIF_VFE_m_PIX_INTF_n_STATUS(vfe, 0);
break;
case RDI0:
addr = ISPIF_VFE_m_RDI_INTF_n_STATUS(vfe, 0);
break;
case PIX1:
addr = ISPIF_VFE_m_PIX_INTF_n_STATUS(vfe, 1);
break;
case RDI1:
addr = ISPIF_VFE_m_RDI_INTF_n_STATUS(vfe, 1);
break;
case RDI2:
addr = ISPIF_VFE_m_RDI_INTF_n_STATUS(vfe, 2);
break;
}
ret = readl_poll_timeout(ispif->base + addr,
stop_flag,
(stop_flag & 0xf) == 0xf,
ISPIF_TIMEOUT_SLEEP_US,
ISPIF_TIMEOUT_ALL_US);
if (ret < 0)
dev_err(to_device(ispif), "%s: ispif stop timeout\n",
__func__);
return ret;
}
static void ispif_select_csid(struct ispif_device *ispif, enum ispif_intf intf,
u8 csid, u8 vfe, u8 enable)
{
u32 val;
val = readl_relaxed(ispif->base + ISPIF_VFE_m_INTF_INPUT_SEL(vfe));
switch (intf) {
case PIX0:
val &= ~(BIT(1) | BIT(0));
if (enable)
val |= csid;
break;
case RDI0:
val &= ~(BIT(5) | BIT(4));
if (enable)
val |= (csid << 4);
break;
case PIX1:
val &= ~(BIT(9) | BIT(8));
if (enable)
val |= (csid << 8);
break;
case RDI1:
val &= ~(BIT(13) | BIT(12));
if (enable)
val |= (csid << 12);
break;
case RDI2:
val &= ~(BIT(21) | BIT(20));
if (enable)
val |= (csid << 20);
break;
}
writel(val, ispif->base + ISPIF_VFE_m_INTF_INPUT_SEL(vfe));
}
static void ispif_select_cid(struct ispif_device *ispif, enum ispif_intf intf,
u8 cid, u8 vfe, u8 enable)
{
u32 cid_mask = 1 << cid;
u32 addr = 0;
u32 val;
switch (intf) {
case PIX0:
addr = ISPIF_VFE_m_PIX_INTF_n_CID_MASK(vfe, 0);
break;
case RDI0:
addr = ISPIF_VFE_m_RDI_INTF_n_CID_MASK(vfe, 0);
break;
case PIX1:
addr = ISPIF_VFE_m_PIX_INTF_n_CID_MASK(vfe, 1);
break;
case RDI1:
addr = ISPIF_VFE_m_RDI_INTF_n_CID_MASK(vfe, 1);
break;
case RDI2:
addr = ISPIF_VFE_m_RDI_INTF_n_CID_MASK(vfe, 2);
break;
}
val = readl_relaxed(ispif->base + addr);
if (enable)
val |= cid_mask;
else
val &= ~cid_mask;
writel(val, ispif->base + addr);
}
static void ispif_config_irq(struct ispif_device *ispif, enum ispif_intf intf,
u8 vfe, u8 enable)
{
u32 val;
switch (intf) {
case PIX0:
val = readl_relaxed(ispif->base + ISPIF_VFE_m_IRQ_MASK_0(vfe));
val &= ~ISPIF_VFE_m_IRQ_MASK_0_PIX0_MASK;
if (enable)
val |= ISPIF_VFE_m_IRQ_MASK_0_PIX0_ENABLE;
writel_relaxed(val, ispif->base + ISPIF_VFE_m_IRQ_MASK_0(vfe));
writel_relaxed(ISPIF_VFE_m_IRQ_MASK_0_PIX0_ENABLE,
ispif->base + ISPIF_VFE_m_IRQ_CLEAR_0(vfe));
break;
case RDI0:
val = readl_relaxed(ispif->base + ISPIF_VFE_m_IRQ_MASK_0(vfe));
val &= ~ISPIF_VFE_m_IRQ_MASK_0_RDI0_MASK;
if (enable)
val |= ISPIF_VFE_m_IRQ_MASK_0_RDI0_ENABLE;
writel_relaxed(val, ispif->base + ISPIF_VFE_m_IRQ_MASK_0(vfe));
writel_relaxed(ISPIF_VFE_m_IRQ_MASK_0_RDI0_ENABLE,
ispif->base + ISPIF_VFE_m_IRQ_CLEAR_0(vfe));
break;
case PIX1:
val = readl_relaxed(ispif->base + ISPIF_VFE_m_IRQ_MASK_1(vfe));
val &= ~ISPIF_VFE_m_IRQ_MASK_1_PIX1_MASK;
if (enable)
val |= ISPIF_VFE_m_IRQ_MASK_1_PIX1_ENABLE;
writel_relaxed(val, ispif->base + ISPIF_VFE_m_IRQ_MASK_1(vfe));
writel_relaxed(ISPIF_VFE_m_IRQ_MASK_1_PIX1_ENABLE,
ispif->base + ISPIF_VFE_m_IRQ_CLEAR_1(vfe));
break;
case RDI1:
val = readl_relaxed(ispif->base + ISPIF_VFE_m_IRQ_MASK_1(vfe));
val &= ~ISPIF_VFE_m_IRQ_MASK_1_RDI1_MASK;
if (enable)
val |= ISPIF_VFE_m_IRQ_MASK_1_RDI1_ENABLE;
writel_relaxed(val, ispif->base + ISPIF_VFE_m_IRQ_MASK_1(vfe));
writel_relaxed(ISPIF_VFE_m_IRQ_MASK_1_RDI1_ENABLE,
ispif->base + ISPIF_VFE_m_IRQ_CLEAR_1(vfe));
break;
case RDI2:
val = readl_relaxed(ispif->base + ISPIF_VFE_m_IRQ_MASK_2(vfe));
val &= ~ISPIF_VFE_m_IRQ_MASK_2_RDI2_MASK;
if (enable)
val |= ISPIF_VFE_m_IRQ_MASK_2_RDI2_ENABLE;
writel_relaxed(val, ispif->base + ISPIF_VFE_m_IRQ_MASK_2(vfe));
writel_relaxed(ISPIF_VFE_m_IRQ_MASK_2_RDI2_ENABLE,
ispif->base + ISPIF_VFE_m_IRQ_CLEAR_2(vfe));
break;
}
writel(0x1, ispif->base + ISPIF_IRQ_GLOBAL_CLEAR_CMD);
}
static void ispif_set_intf_cmd(struct ispif_device *ispif, u8 cmd,
enum ispif_intf intf, u8 vfe, u8 vc)
{
u32 *val;
if (intf == RDI2) {
val = &ispif->intf_cmd[vfe].cmd_1;
*val &= ~(0x3 << (vc * 2 + 8));
*val |= (cmd << (vc * 2 + 8));
wmb();
writel_relaxed(*val, ispif->base + ISPIF_VFE_m_INTF_CMD_1(vfe));
wmb();
} else {
val = &ispif->intf_cmd[vfe].cmd_0;
*val &= ~(0x3 << (vc * 2 + intf * 8));
*val |= (cmd << (vc * 2 + intf * 8));
wmb();
writel_relaxed(*val, ispif->base + ISPIF_VFE_m_INTF_CMD_0(vfe));
wmb();
}
}
static int ispif_set_stream(struct v4l2_subdev *sd, int enable)
{
struct ispif_line *line = v4l2_get_subdevdata(sd);
struct ispif_device *ispif = to_ispif(line);
enum ispif_intf intf = line->interface;
u8 csid = line->csid_id;
u8 vfe = line->vfe_id;
u8 vc = 0;
u8 cid = vc * 4;
int ret;
if (enable) {
if (!media_entity_remote_pad(&line->pads[MSM_ISPIF_PAD_SINK]))
return -ENOLINK;
mutex_lock(&ispif->config_lock);
ispif_select_clk_mux(ispif, intf, csid, vfe, 1);
ret = ispif_validate_intf_status(ispif, intf, vfe);
if (ret < 0) {
mutex_unlock(&ispif->config_lock);
return ret;
}
ispif_select_csid(ispif, intf, csid, vfe, 1);
ispif_select_cid(ispif, intf, cid, vfe, 1);
ispif_config_irq(ispif, intf, vfe, 1);
ispif_set_intf_cmd(ispif, CMD_ENABLE_FRAME_BOUNDARY,
intf, vfe, vc);
} else {
mutex_lock(&ispif->config_lock);
ispif_set_intf_cmd(ispif, CMD_DISABLE_FRAME_BOUNDARY,
intf, vfe, vc);
mutex_unlock(&ispif->config_lock);
ret = ispif_wait_for_stop(ispif, intf, vfe);
if (ret < 0)
return ret;
mutex_lock(&ispif->config_lock);
ispif_config_irq(ispif, intf, vfe, 0);
ispif_select_cid(ispif, intf, cid, vfe, 0);
ispif_select_csid(ispif, intf, csid, vfe, 0);
ispif_select_clk_mux(ispif, intf, csid, vfe, 0);
}
mutex_unlock(&ispif->config_lock);
return 0;
}
static struct v4l2_mbus_framefmt *
__ispif_get_format(struct ispif_line *line,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad,
enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return v4l2_subdev_get_try_format(&line->subdev, cfg, pad);
return &line->fmt[pad];
}
static void ispif_try_format(struct ispif_line *line,
struct v4l2_subdev_pad_config *cfg,
unsigned int pad,
struct v4l2_mbus_framefmt *fmt,
enum v4l2_subdev_format_whence which)
{
unsigned int i;
switch (pad) {
case MSM_ISPIF_PAD_SINK:
for (i = 0; i < ARRAY_SIZE(ispif_formats); i++)
if (fmt->code == ispif_formats[i])
break;
if (i >= ARRAY_SIZE(ispif_formats))
fmt->code = MEDIA_BUS_FMT_UYVY8_2X8;
fmt->width = clamp_t(u32, fmt->width, 1, 8191);
fmt->height = clamp_t(u32, fmt->height, 1, 8191);
fmt->field = V4L2_FIELD_NONE;
fmt->colorspace = V4L2_COLORSPACE_SRGB;
break;
case MSM_ISPIF_PAD_SRC:
*fmt = *__ispif_get_format(line, cfg, MSM_ISPIF_PAD_SINK,
which);
break;
}
fmt->colorspace = V4L2_COLORSPACE_SRGB;
}
static int ispif_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
struct ispif_line *line = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
if (code->pad == MSM_ISPIF_PAD_SINK) {
if (code->index >= ARRAY_SIZE(ispif_formats))
return -EINVAL;
code->code = ispif_formats[code->index];
} else {
if (code->index > 0)
return -EINVAL;
format = __ispif_get_format(line, cfg, MSM_ISPIF_PAD_SINK,
code->which);
code->code = format->code;
}
return 0;
}
static int ispif_enum_frame_size(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_frame_size_enum *fse)
{
struct ispif_line *line = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt format;
if (fse->index != 0)
return -EINVAL;
format.code = fse->code;
format.width = 1;
format.height = 1;
ispif_try_format(line, cfg, fse->pad, &format, fse->which);
fse->min_width = format.width;
fse->min_height = format.height;
if (format.code != fse->code)
return -EINVAL;
format.code = fse->code;
format.width = -1;
format.height = -1;
ispif_try_format(line, cfg, fse->pad, &format, fse->which);
fse->max_width = format.width;
fse->max_height = format.height;
return 0;
}
static int ispif_get_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct ispif_line *line = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __ispif_get_format(line, cfg, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
fmt->format = *format;
return 0;
}
static int ispif_set_format(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *fmt)
{
struct ispif_line *line = v4l2_get_subdevdata(sd);
struct v4l2_mbus_framefmt *format;
format = __ispif_get_format(line, cfg, fmt->pad, fmt->which);
if (format == NULL)
return -EINVAL;
ispif_try_format(line, cfg, fmt->pad, &fmt->format, fmt->which);
*format = fmt->format;
if (fmt->pad == MSM_ISPIF_PAD_SINK) {
format = __ispif_get_format(line, cfg, MSM_ISPIF_PAD_SRC,
fmt->which);
*format = fmt->format;
ispif_try_format(line, cfg, MSM_ISPIF_PAD_SRC, format,
fmt->which);
}
return 0;
}
static int ispif_init_formats(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_subdev_format format = {
.pad = MSM_ISPIF_PAD_SINK,
.which = fh ? V4L2_SUBDEV_FORMAT_TRY :
V4L2_SUBDEV_FORMAT_ACTIVE,
.format = {
.code = MEDIA_BUS_FMT_UYVY8_2X8,
.width = 1920,
.height = 1080
}
};
return ispif_set_format(sd, fh ? fh->pad : NULL, &format);
}
int msm_ispif_subdev_init(struct ispif_device *ispif,
const struct resources_ispif *res)
{
struct device *dev = to_device(ispif);
struct platform_device *pdev = to_platform_device(dev);
struct resource *r;
int i;
int ret;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, res->reg[0]);
ispif->base = devm_ioremap_resource(dev, r);
if (IS_ERR(ispif->base)) {
dev_err(dev, "could not map memory\n");
return PTR_ERR(ispif->base);
}
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, res->reg[1]);
ispif->base_clk_mux = devm_ioremap_resource(dev, r);
if (IS_ERR(ispif->base_clk_mux)) {
dev_err(dev, "could not map memory\n");
return PTR_ERR(ispif->base_clk_mux);
}
r = platform_get_resource_byname(pdev, IORESOURCE_IRQ, res->interrupt);
if (!r) {
dev_err(dev, "missing IRQ\n");
return -EINVAL;
}
ispif->irq = r->start;
snprintf(ispif->irq_name, sizeof(ispif->irq_name), "%s_%s",
dev_name(dev), MSM_ISPIF_NAME);
ret = devm_request_irq(dev, ispif->irq, ispif_isr,
IRQF_TRIGGER_RISING, ispif->irq_name, ispif);
if (ret < 0) {
dev_err(dev, "request_irq failed: %d\n", ret);
return ret;
}
ispif->nclocks = 0;
while (res->clock[ispif->nclocks])
ispif->nclocks++;
ispif->clock = devm_kzalloc(dev, ispif->nclocks * sizeof(*ispif->clock),
GFP_KERNEL);
if (!ispif->clock)
return -ENOMEM;
for (i = 0; i < ispif->nclocks; i++) {
struct camss_clock *clock = &ispif->clock[i];
clock->clk = devm_clk_get(dev, res->clock[i]);
if (IS_ERR(clock->clk))
return PTR_ERR(clock->clk);
clock->freq = NULL;
clock->nfreqs = 0;
}
ispif->nclocks_for_reset = 0;
while (res->clock_for_reset[ispif->nclocks_for_reset])
ispif->nclocks_for_reset++;
ispif->clock_for_reset = devm_kzalloc(dev, ispif->nclocks_for_reset *
sizeof(*ispif->clock_for_reset), GFP_KERNEL);
if (!ispif->clock_for_reset)
return -ENOMEM;
for (i = 0; i < ispif->nclocks_for_reset; i++) {
struct camss_clock *clock = &ispif->clock_for_reset[i];
clock->clk = devm_clk_get(dev, res->clock_for_reset[i]);
if (IS_ERR(clock->clk))
return PTR_ERR(clock->clk);
clock->freq = NULL;
clock->nfreqs = 0;
}
for (i = 0; i < ARRAY_SIZE(ispif->line); i++)
ispif->line[i].id = i;
mutex_init(&ispif->power_lock);
ispif->power_count = 0;
mutex_init(&ispif->config_lock);
init_completion(&ispif->reset_complete);
return 0;
}
static enum ispif_intf ispif_get_intf(enum vfe_line_id line_id)
{
switch (line_id) {
case (VFE_LINE_RDI0):
return RDI0;
case (VFE_LINE_RDI1):
return RDI1;
case (VFE_LINE_RDI2):
return RDI2;
case (VFE_LINE_PIX):
return PIX0;
default:
return RDI0;
}
}
static int ispif_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
if (flags & MEDIA_LNK_FL_ENABLED) {
if (media_entity_remote_pad(local))
return -EBUSY;
if (local->flags & MEDIA_PAD_FL_SINK) {
struct v4l2_subdev *sd;
struct ispif_line *line;
sd = media_entity_to_v4l2_subdev(entity);
line = v4l2_get_subdevdata(sd);
msm_csid_get_csid_id(remote->entity, &line->csid_id);
} else {
struct v4l2_subdev *sd;
struct ispif_line *line;
enum vfe_line_id id;
sd = media_entity_to_v4l2_subdev(entity);
line = v4l2_get_subdevdata(sd);
msm_vfe_get_vfe_id(remote->entity, &line->vfe_id);
msm_vfe_get_vfe_line_id(remote->entity, &id);
line->interface = ispif_get_intf(id);
}
}
return 0;
}
int msm_ispif_register_entities(struct ispif_device *ispif,
struct v4l2_device *v4l2_dev)
{
struct device *dev = to_device(ispif);
int ret;
int i;
for (i = 0; i < ARRAY_SIZE(ispif->line); i++) {
struct v4l2_subdev *sd = &ispif->line[i].subdev;
struct media_pad *pads = ispif->line[i].pads;
v4l2_subdev_init(sd, &ispif_v4l2_ops);
sd->internal_ops = &ispif_v4l2_internal_ops;
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
snprintf(sd->name, ARRAY_SIZE(sd->name), "%s%d",
MSM_ISPIF_NAME, i);
v4l2_set_subdevdata(sd, &ispif->line[i]);
ret = ispif_init_formats(sd, NULL);
if (ret < 0) {
dev_err(dev, "Failed to init format: %d\n", ret);
goto error;
}
pads[MSM_ISPIF_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
pads[MSM_ISPIF_PAD_SRC].flags = MEDIA_PAD_FL_SOURCE;
sd->entity.function = MEDIA_ENT_F_IO_V4L;
sd->entity.ops = &ispif_media_ops;
ret = media_entity_pads_init(&sd->entity, MSM_ISPIF_PADS_NUM,
pads);
if (ret < 0) {
dev_err(dev, "Failed to init media entity: %d\n", ret);
goto error;
}
ret = v4l2_device_register_subdev(v4l2_dev, sd);
if (ret < 0) {
dev_err(dev, "Failed to register subdev: %d\n", ret);
media_entity_cleanup(&sd->entity);
goto error;
}
}
return 0;
error:
for (i--; i >= 0; i--) {
struct v4l2_subdev *sd = &ispif->line[i].subdev;
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
}
return ret;
}
void msm_ispif_unregister_entities(struct ispif_device *ispif)
{
int i;
mutex_destroy(&ispif->power_lock);
mutex_destroy(&ispif->config_lock);
for (i = 0; i < ARRAY_SIZE(ispif->line); i++) {
struct v4l2_subdev *sd = &ispif->line[i].subdev;
v4l2_device_unregister_subdev(sd);
media_entity_cleanup(&sd->entity);
}
}
