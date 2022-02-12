static struct csis_state *sd_to_csis_state(struct v4l2_subdev *sdev)
{
return container_of(sdev, struct csis_state, sd);
}
static const struct csis_pix_format *find_csis_format(
struct v4l2_mbus_framefmt *mf)
{
int i;
for (i = 0; i < ARRAY_SIZE(s5pcsis_formats); i++)
if (mf->code == s5pcsis_formats[i].code)
return &s5pcsis_formats[i];
return NULL;
}
static void s5pcsis_enable_interrupts(struct csis_state *state, bool on)
{
u32 val = s5pcsis_read(state, S5PCSIS_INTMSK);
val = on ? val | S5PCSIS_INTMSK_EN_ALL :
val & ~S5PCSIS_INTMSK_EN_ALL;
s5pcsis_write(state, S5PCSIS_INTMSK, val);
}
static void s5pcsis_reset(struct csis_state *state)
{
u32 val = s5pcsis_read(state, S5PCSIS_CTRL);
s5pcsis_write(state, S5PCSIS_CTRL, val | S5PCSIS_CTRL_RESET);
udelay(10);
}
static void s5pcsis_system_enable(struct csis_state *state, int on)
{
u32 val;
val = s5pcsis_read(state, S5PCSIS_CTRL);
if (on)
val |= S5PCSIS_CTRL_ENABLE;
else
val &= ~S5PCSIS_CTRL_ENABLE;
s5pcsis_write(state, S5PCSIS_CTRL, val);
val = s5pcsis_read(state, S5PCSIS_DPHYCTRL);
if (on)
val |= S5PCSIS_DPHYCTRL_ENABLE;
else
val &= ~S5PCSIS_DPHYCTRL_ENABLE;
s5pcsis_write(state, S5PCSIS_DPHYCTRL, val);
}
static void __s5pcsis_set_format(struct csis_state *state)
{
struct v4l2_mbus_framefmt *mf = &state->format;
u32 val;
v4l2_dbg(1, debug, &state->sd, "fmt: %#x, %d x %d\n",
mf->code, mf->width, mf->height);
val = s5pcsis_read(state, S5PCSIS_CONFIG);
val = (val & ~S5PCSIS_CFG_FMT_MASK) | state->csis_fmt->fmt_reg;
s5pcsis_write(state, S5PCSIS_CONFIG, val);
val = (mf->width << 16) | mf->height;
s5pcsis_write(state, S5PCSIS_RESOL, val);
}
static void s5pcsis_set_hsync_settle(struct csis_state *state, int settle)
{
u32 val = s5pcsis_read(state, S5PCSIS_DPHYCTRL);
val = (val & ~S5PCSIS_DPHYCTRL_HSS_MASK) | (settle << 27);
s5pcsis_write(state, S5PCSIS_DPHYCTRL, val);
}
static void s5pcsis_set_params(struct csis_state *state)
{
struct s5p_platform_mipi_csis *pdata = state->pdev->dev.platform_data;
u32 val;
val = s5pcsis_read(state, S5PCSIS_CONFIG);
val = (val & ~S5PCSIS_CFG_NR_LANE_MASK) | (pdata->lanes - 1);
s5pcsis_write(state, S5PCSIS_CONFIG, val);
__s5pcsis_set_format(state);
s5pcsis_set_hsync_settle(state, pdata->hs_settle);
val = s5pcsis_read(state, S5PCSIS_CTRL);
if (state->csis_fmt->data_alignment == 32)
val |= S5PCSIS_CTRL_ALIGN_32BIT;
else
val &= ~S5PCSIS_CTRL_ALIGN_32BIT;
val &= ~S5PCSIS_CTRL_WCLK_EXTCLK;
if (pdata->wclk_source)
val |= S5PCSIS_CTRL_WCLK_EXTCLK;
s5pcsis_write(state, S5PCSIS_CTRL, val);
val = s5pcsis_read(state, S5PCSIS_CTRL);
s5pcsis_write(state, S5PCSIS_CTRL, val | S5PCSIS_CTRL_UPDATE_SHADOW);
}
static void s5pcsis_clk_put(struct csis_state *state)
{
int i;
for (i = 0; i < NUM_CSIS_CLOCKS; i++) {
if (IS_ERR_OR_NULL(state->clock[i]))
continue;
clk_unprepare(state->clock[i]);
clk_put(state->clock[i]);
state->clock[i] = NULL;
}
}
static int s5pcsis_clk_get(struct csis_state *state)
{
struct device *dev = &state->pdev->dev;
int i, ret;
for (i = 0; i < NUM_CSIS_CLOCKS; i++) {
state->clock[i] = clk_get(dev, csi_clock_name[i]);
if (IS_ERR(state->clock[i]))
goto err;
ret = clk_prepare(state->clock[i]);
if (ret < 0) {
clk_put(state->clock[i]);
state->clock[i] = NULL;
goto err;
}
}
return 0;
err:
s5pcsis_clk_put(state);
dev_err(dev, "failed to get clock: %s\n", csi_clock_name[i]);
return -ENXIO;
}
static void s5pcsis_start_stream(struct csis_state *state)
{
s5pcsis_reset(state);
s5pcsis_set_params(state);
s5pcsis_system_enable(state, true);
s5pcsis_enable_interrupts(state, true);
}
static void s5pcsis_stop_stream(struct csis_state *state)
{
s5pcsis_enable_interrupts(state, false);
s5pcsis_system_enable(state, false);
}
static void s5pcsis_clear_counters(struct csis_state *state)
{
unsigned long flags;
int i;
spin_lock_irqsave(&state->slock, flags);
for (i = 0; i < S5PCSIS_NUM_EVENTS; i++)
state->events[i].counter = 0;
spin_unlock_irqrestore(&state->slock, flags);
}
static void s5pcsis_log_counters(struct csis_state *state, bool non_errors)
{
int i = non_errors ? S5PCSIS_NUM_EVENTS : S5PCSIS_NUM_EVENTS - 4;
unsigned long flags;
spin_lock_irqsave(&state->slock, flags);
for (i--; i >= 0; i--)
if (state->events[i].counter >= 0)
v4l2_info(&state->sd, "%s events: %d\n",
state->events[i].name,
state->events[i].counter);
spin_unlock_irqrestore(&state->slock, flags);
}
static int s5pcsis_s_power(struct v4l2_subdev *sd, int on)
{
struct csis_state *state = sd_to_csis_state(sd);
struct device *dev = &state->pdev->dev;
if (on)
return pm_runtime_get_sync(dev);
return pm_runtime_put_sync(dev);
}
static int s5pcsis_s_stream(struct v4l2_subdev *sd, int enable)
{
struct csis_state *state = sd_to_csis_state(sd);
int ret = 0;
v4l2_dbg(1, debug, sd, "%s: %d, state: 0x%x\n",
__func__, enable, state->flags);
if (enable) {
s5pcsis_clear_counters(state);
ret = pm_runtime_get_sync(&state->pdev->dev);
if (ret && ret != 1)
return ret;
}
mutex_lock(&state->lock);
if (enable) {
if (state->flags & ST_SUSPENDED) {
ret = -EBUSY;
goto unlock;
}
s5pcsis_start_stream(state);
state->flags |= ST_STREAMING;
} else {
s5pcsis_stop_stream(state);
state->flags &= ~ST_STREAMING;
if (debug > 0)
s5pcsis_log_counters(state, true);
}
unlock:
mutex_unlock(&state->lock);
if (!enable)
pm_runtime_put(&state->pdev->dev);
return ret == 1 ? 0 : ret;
}
static int s5pcsis_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index >= ARRAY_SIZE(s5pcsis_formats))
return -EINVAL;
code->code = s5pcsis_formats[code->index].code;
return 0;
}
static struct csis_pix_format const *s5pcsis_try_format(
struct v4l2_mbus_framefmt *mf)
{
struct csis_pix_format const *csis_fmt;
csis_fmt = find_csis_format(mf);
if (csis_fmt == NULL)
csis_fmt = &s5pcsis_formats[0];
mf->code = csis_fmt->code;
v4l_bound_align_image(&mf->width, 1, CSIS_MAX_PIX_WIDTH,
csis_fmt->pix_width_alignment,
&mf->height, 1, CSIS_MAX_PIX_HEIGHT, 1,
0);
return csis_fmt;
}
static struct v4l2_mbus_framefmt *__s5pcsis_get_format(
struct csis_state *state, struct v4l2_subdev_fh *fh,
u32 pad, enum v4l2_subdev_format_whence which)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return fh ? v4l2_subdev_get_try_format(fh, pad) : NULL;
return &state->format;
}
static int s5pcsis_set_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct csis_state *state = sd_to_csis_state(sd);
struct csis_pix_format const *csis_fmt;
struct v4l2_mbus_framefmt *mf;
if (fmt->pad != CSIS_PAD_SOURCE && fmt->pad != CSIS_PAD_SINK)
return -EINVAL;
mf = __s5pcsis_get_format(state, fh, fmt->pad, fmt->which);
if (fmt->pad == CSIS_PAD_SOURCE) {
if (mf) {
mutex_lock(&state->lock);
fmt->format = *mf;
mutex_unlock(&state->lock);
}
return 0;
}
csis_fmt = s5pcsis_try_format(&fmt->format);
if (mf) {
mutex_lock(&state->lock);
*mf = fmt->format;
if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE)
state->csis_fmt = csis_fmt;
mutex_unlock(&state->lock);
}
return 0;
}
static int s5pcsis_get_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct csis_state *state = sd_to_csis_state(sd);
struct v4l2_mbus_framefmt *mf;
if (fmt->pad != CSIS_PAD_SOURCE && fmt->pad != CSIS_PAD_SINK)
return -EINVAL;
mf = __s5pcsis_get_format(state, fh, fmt->pad, fmt->which);
if (!mf)
return -EINVAL;
mutex_lock(&state->lock);
fmt->format = *mf;
mutex_unlock(&state->lock);
return 0;
}
static int s5pcsis_s_rx_buffer(struct v4l2_subdev *sd, void *buf,
unsigned int *size)
{
struct csis_state *state = sd_to_csis_state(sd);
unsigned long flags;
*size = min_t(unsigned int, *size, S5PCSIS_PKTDATA_SIZE);
spin_lock_irqsave(&state->slock, flags);
state->pkt_buf.data = buf;
state->pkt_buf.len = *size;
spin_unlock_irqrestore(&state->slock, flags);
return 0;
}
static int s5pcsis_log_status(struct v4l2_subdev *sd)
{
struct csis_state *state = sd_to_csis_state(sd);
s5pcsis_log_counters(state, true);
return 0;
}
static int s5pcsis_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_mbus_framefmt *format = v4l2_subdev_get_try_format(fh, 0);
format->colorspace = V4L2_COLORSPACE_JPEG;
format->code = s5pcsis_formats[0].code;
format->width = S5PCSIS_DEF_PIX_WIDTH;
format->height = S5PCSIS_DEF_PIX_HEIGHT;
format->field = V4L2_FIELD_NONE;
return 0;
}
static irqreturn_t s5pcsis_irq_handler(int irq, void *dev_id)
{
struct csis_state *state = dev_id;
struct csis_pktbuf *pktbuf = &state->pkt_buf;
unsigned long flags;
u32 status;
status = s5pcsis_read(state, S5PCSIS_INTSRC);
spin_lock_irqsave(&state->slock, flags);
if ((status & S5PCSIS_INTSRC_NON_IMAGE_DATA) && pktbuf->data) {
u32 offset;
if (status & S5PCSIS_INTSRC_EVEN)
offset = S5PCSIS_PKTDATA_EVEN;
else
offset = S5PCSIS_PKTDATA_ODD;
memcpy(pktbuf->data, state->regs + offset, pktbuf->len);
pktbuf->data = NULL;
rmb();
}
if ((status & S5PCSIS_INTSRC_ERRORS) || debug) {
int i;
for (i = 0; i < S5PCSIS_NUM_EVENTS; i++) {
if (!(status & state->events[i].mask))
continue;
state->events[i].counter++;
v4l2_dbg(2, debug, &state->sd, "%s: %d\n",
state->events[i].name,
state->events[i].counter);
}
v4l2_dbg(2, debug, &state->sd, "status: %08x\n", status);
}
spin_unlock_irqrestore(&state->slock, flags);
s5pcsis_write(state, S5PCSIS_INTSRC, status);
return IRQ_HANDLED;
}
static int __devinit s5pcsis_probe(struct platform_device *pdev)
{
struct s5p_platform_mipi_csis *pdata;
struct resource *mem_res;
struct csis_state *state;
int ret = -ENOMEM;
int i;
state = devm_kzalloc(&pdev->dev, sizeof(*state), GFP_KERNEL);
if (!state)
return -ENOMEM;
mutex_init(&state->lock);
spin_lock_init(&state->slock);
state->pdev = pdev;
state->index = max(0, pdev->id);
pdata = pdev->dev.platform_data;
if (pdata == NULL) {
dev_err(&pdev->dev, "Platform data not fully specified\n");
return -EINVAL;
}
if ((state->index == 1 && pdata->lanes > CSIS1_MAX_LANES) ||
pdata->lanes > CSIS0_MAX_LANES) {
dev_err(&pdev->dev, "Unsupported number of data lanes: %d\n",
pdata->lanes);
return -EINVAL;
}
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
state->regs = devm_request_and_ioremap(&pdev->dev, mem_res);
if (state->regs == NULL) {
dev_err(&pdev->dev, "Failed to request and remap io memory\n");
return -ENXIO;
}
state->irq = platform_get_irq(pdev, 0);
if (state->irq < 0) {
dev_err(&pdev->dev, "Failed to get irq\n");
return state->irq;
}
for (i = 0; i < CSIS_NUM_SUPPLIES; i++)
state->supplies[i].supply = csis_supply_name[i];
ret = regulator_bulk_get(&pdev->dev, CSIS_NUM_SUPPLIES,
state->supplies);
if (ret)
return ret;
ret = s5pcsis_clk_get(state);
if (ret)
goto e_clkput;
clk_enable(state->clock[CSIS_CLK_MUX]);
if (pdata->clk_rate)
clk_set_rate(state->clock[CSIS_CLK_MUX], pdata->clk_rate);
else
dev_WARN(&pdev->dev, "No clock frequency specified!\n");
ret = devm_request_irq(&pdev->dev, state->irq, s5pcsis_irq_handler,
0, dev_name(&pdev->dev), state);
if (ret) {
dev_err(&pdev->dev, "Interrupt request failed\n");
goto e_regput;
}
v4l2_subdev_init(&state->sd, &s5pcsis_subdev_ops);
state->sd.owner = THIS_MODULE;
strlcpy(state->sd.name, dev_name(&pdev->dev), sizeof(state->sd.name));
state->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
state->csis_fmt = &s5pcsis_formats[0];
state->format.code = s5pcsis_formats[0].code;
state->format.width = S5PCSIS_DEF_PIX_WIDTH;
state->format.height = S5PCSIS_DEF_PIX_HEIGHT;
state->pads[CSIS_PAD_SINK].flags = MEDIA_PAD_FL_SINK;
state->pads[CSIS_PAD_SOURCE].flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&state->sd.entity,
CSIS_PADS_NUM, state->pads, 0);
if (ret < 0)
goto e_clkput;
v4l2_set_subdevdata(&state->sd, pdev);
platform_set_drvdata(pdev, &state->sd);
memcpy(state->events, s5pcsis_events, sizeof(state->events));
pm_runtime_enable(&pdev->dev);
return 0;
e_regput:
regulator_bulk_free(CSIS_NUM_SUPPLIES, state->supplies);
e_clkput:
clk_disable(state->clock[CSIS_CLK_MUX]);
s5pcsis_clk_put(state);
return ret;
}
static int s5pcsis_pm_suspend(struct device *dev, bool runtime)
{
struct platform_device *pdev = to_platform_device(dev);
struct v4l2_subdev *sd = platform_get_drvdata(pdev);
struct csis_state *state = sd_to_csis_state(sd);
int ret = 0;
v4l2_dbg(1, debug, sd, "%s: flags: 0x%x\n",
__func__, state->flags);
mutex_lock(&state->lock);
if (state->flags & ST_POWERED) {
s5pcsis_stop_stream(state);
ret = s5p_csis_phy_enable(state->index, false);
if (ret)
goto unlock;
ret = regulator_bulk_disable(CSIS_NUM_SUPPLIES,
state->supplies);
if (ret)
goto unlock;
clk_disable(state->clock[CSIS_CLK_GATE]);
state->flags &= ~ST_POWERED;
if (!runtime)
state->flags |= ST_SUSPENDED;
}
unlock:
mutex_unlock(&state->lock);
return ret ? -EAGAIN : 0;
}
static int s5pcsis_pm_resume(struct device *dev, bool runtime)
{
struct platform_device *pdev = to_platform_device(dev);
struct v4l2_subdev *sd = platform_get_drvdata(pdev);
struct csis_state *state = sd_to_csis_state(sd);
int ret = 0;
v4l2_dbg(1, debug, sd, "%s: flags: 0x%x\n",
__func__, state->flags);
mutex_lock(&state->lock);
if (!runtime && !(state->flags & ST_SUSPENDED))
goto unlock;
if (!(state->flags & ST_POWERED)) {
ret = regulator_bulk_enable(CSIS_NUM_SUPPLIES,
state->supplies);
if (ret)
goto unlock;
ret = s5p_csis_phy_enable(state->index, true);
if (!ret) {
state->flags |= ST_POWERED;
} else {
regulator_bulk_disable(CSIS_NUM_SUPPLIES,
state->supplies);
goto unlock;
}
clk_enable(state->clock[CSIS_CLK_GATE]);
}
if (state->flags & ST_STREAMING)
s5pcsis_start_stream(state);
state->flags &= ~ST_SUSPENDED;
unlock:
mutex_unlock(&state->lock);
return ret ? -EAGAIN : 0;
}
static int s5pcsis_suspend(struct device *dev)
{
return s5pcsis_pm_suspend(dev, false);
}
static int s5pcsis_resume(struct device *dev)
{
return s5pcsis_pm_resume(dev, false);
}
static int s5pcsis_runtime_suspend(struct device *dev)
{
return s5pcsis_pm_suspend(dev, true);
}
static int s5pcsis_runtime_resume(struct device *dev)
{
return s5pcsis_pm_resume(dev, true);
}
static int __devexit s5pcsis_remove(struct platform_device *pdev)
{
struct v4l2_subdev *sd = platform_get_drvdata(pdev);
struct csis_state *state = sd_to_csis_state(sd);
pm_runtime_disable(&pdev->dev);
s5pcsis_pm_suspend(&pdev->dev, false);
clk_disable(state->clock[CSIS_CLK_MUX]);
pm_runtime_set_suspended(&pdev->dev);
s5pcsis_clk_put(state);
regulator_bulk_free(CSIS_NUM_SUPPLIES, state->supplies);
media_entity_cleanup(&state->sd.entity);
return 0;
}
