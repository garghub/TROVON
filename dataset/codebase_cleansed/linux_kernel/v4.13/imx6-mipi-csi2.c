static inline struct csi2_dev *sd_to_dev(struct v4l2_subdev *sdev)
{
return container_of(sdev, struct csi2_dev, sd);
}
static void csi2_enable(struct csi2_dev *csi2, bool enable)
{
if (enable) {
writel(0x1, csi2->base + CSI2_PHY_SHUTDOWNZ);
writel(0x1, csi2->base + CSI2_DPHY_RSTZ);
writel(0x1, csi2->base + CSI2_RESETN);
} else {
writel(0x0, csi2->base + CSI2_PHY_SHUTDOWNZ);
writel(0x0, csi2->base + CSI2_DPHY_RSTZ);
writel(0x0, csi2->base + CSI2_RESETN);
}
}
static void csi2_set_lanes(struct csi2_dev *csi2)
{
int lanes = csi2->bus.num_data_lanes;
writel(lanes - 1, csi2->base + CSI2_N_LANES);
}
static void dw_mipi_csi2_phy_write(struct csi2_dev *csi2,
u32 test_code, u32 test_data)
{
writel(PHY_TESTCLR, csi2->base + CSI2_PHY_TST_CTRL0);
writel(0x0, csi2->base + CSI2_PHY_TST_CTRL1);
writel(0x0, csi2->base + CSI2_PHY_TST_CTRL0);
writel(PHY_TESTCLK, csi2->base + CSI2_PHY_TST_CTRL0);
writel(PHY_TESTEN | test_code, csi2->base + CSI2_PHY_TST_CTRL1);
writel(0x0, csi2->base + CSI2_PHY_TST_CTRL0);
writel(test_data, csi2->base + CSI2_PHY_TST_CTRL1);
writel(PHY_TESTCLK, csi2->base + CSI2_PHY_TST_CTRL0);
writel(0x0, csi2->base + CSI2_PHY_TST_CTRL0);
}
static int max_mbps_to_hsfreqrange_sel(u32 max_mbps)
{
int i;
for (i = 0; i < ARRAY_SIZE(hsfreq_map); i++)
if (hsfreq_map[i].max_mbps > max_mbps)
return hsfreq_map[i].hsfreqrange_sel;
return -EINVAL;
}
static int csi2_dphy_init(struct csi2_dev *csi2)
{
struct v4l2_ctrl *ctrl;
u32 mbps_per_lane;
int sel;
ctrl = v4l2_ctrl_find(csi2->src_sd->ctrl_handler,
V4L2_CID_LINK_FREQ);
if (!ctrl)
mbps_per_lane = CSI2_DEFAULT_MAX_MBPS;
else
mbps_per_lane = DIV_ROUND_UP_ULL(2 * ctrl->qmenu_int[ctrl->val],
USEC_PER_SEC);
sel = max_mbps_to_hsfreqrange_sel(mbps_per_lane);
if (sel < 0)
return sel;
dw_mipi_csi2_phy_write(csi2, 0x44, sel);
return 0;
}
static int __maybe_unused csi2_dphy_wait_ulp(struct csi2_dev *csi2)
{
u32 reg;
int ret;
ret = readl_poll_timeout(csi2->base + CSI2_PHY_STATE, reg,
!(reg & PHY_RXULPSCLKNOT), 0, 500000);
if (ret) {
v4l2_err(&csi2->sd, "ULP timeout, phy_state = 0x%08x\n", reg);
return ret;
}
ret = readl_poll_timeout(csi2->base + CSI2_ERR1, reg,
reg == 0x0, 0, 500000);
if (ret) {
v4l2_err(&csi2->sd, "stable bus timeout, err1 = 0x%08x\n", reg);
return ret;
}
return 0;
}
static int csi2_dphy_wait_stopstate(struct csi2_dev *csi2)
{
u32 mask, reg;
int ret;
mask = PHY_STOPSTATECLK |
((csi2->bus.num_data_lanes - 1) << PHY_STOPSTATEDATA_BIT);
ret = readl_poll_timeout(csi2->base + CSI2_PHY_STATE, reg,
(reg & mask) == mask, 0, 500000);
if (ret) {
v4l2_err(&csi2->sd, "LP-11 timeout, phy_state = 0x%08x\n", reg);
return ret;
}
return 0;
}
static int csi2_dphy_wait_clock_lane(struct csi2_dev *csi2)
{
u32 reg;
int ret;
ret = readl_poll_timeout(csi2->base + CSI2_PHY_STATE, reg,
(reg & PHY_RXCLKACTIVEHS), 0, 500000);
if (ret) {
v4l2_err(&csi2->sd, "clock lane timeout, phy_state = 0x%08x\n",
reg);
return ret;
}
return 0;
}
static void csi2ipu_gasket_init(struct csi2_dev *csi2)
{
u32 reg = 0;
switch (csi2->format_mbus.code) {
case MEDIA_BUS_FMT_YUYV8_2X8:
case MEDIA_BUS_FMT_YUYV8_1X16:
reg = CSI2IPU_YUV422_YUYV;
break;
default:
break;
}
writel(reg, csi2->base + CSI2IPU_GASKET);
}
static int csi2_start(struct csi2_dev *csi2)
{
int ret;
ret = clk_prepare_enable(csi2->pix_clk);
if (ret)
return ret;
csi2ipu_gasket_init(csi2);
ret = csi2_dphy_init(csi2);
if (ret)
goto err_disable_clk;
csi2_set_lanes(csi2);
csi2_enable(csi2, true);
ret = csi2_dphy_wait_stopstate(csi2);
if (ret)
goto err_assert_reset;
ret = v4l2_subdev_call(csi2->src_sd, video, s_stream, 1);
ret = (ret && ret != -ENOIOCTLCMD) ? ret : 0;
if (ret)
goto err_assert_reset;
ret = csi2_dphy_wait_clock_lane(csi2);
if (ret)
goto err_stop_upstream;
return 0;
err_stop_upstream:
v4l2_subdev_call(csi2->src_sd, video, s_stream, 0);
err_assert_reset:
csi2_enable(csi2, false);
err_disable_clk:
clk_disable_unprepare(csi2->pix_clk);
return ret;
}
static void csi2_stop(struct csi2_dev *csi2)
{
v4l2_subdev_call(csi2->src_sd, video, s_stream, 0);
csi2_enable(csi2, false);
clk_disable_unprepare(csi2->pix_clk);
}
static int csi2_s_stream(struct v4l2_subdev *sd, int enable)
{
struct csi2_dev *csi2 = sd_to_dev(sd);
int i, ret = 0;
mutex_lock(&csi2->lock);
if (!csi2->src_sd) {
ret = -EPIPE;
goto out;
}
for (i = 0; i < CSI2_NUM_SRC_PADS; i++) {
if (csi2->sink_linked[i])
break;
}
if (i >= CSI2_NUM_SRC_PADS) {
ret = -EPIPE;
goto out;
}
if (csi2->stream_count != !enable)
goto update_count;
dev_dbg(csi2->dev, "stream %s\n", enable ? "ON" : "OFF");
if (enable)
ret = csi2_start(csi2);
else
csi2_stop(csi2);
if (ret)
goto out;
update_count:
csi2->stream_count += enable ? 1 : -1;
if (csi2->stream_count < 0)
csi2->stream_count = 0;
out:
mutex_unlock(&csi2->lock);
return ret;
}
static int csi2_link_setup(struct media_entity *entity,
const struct media_pad *local,
const struct media_pad *remote, u32 flags)
{
struct v4l2_subdev *sd = media_entity_to_v4l2_subdev(entity);
struct csi2_dev *csi2 = sd_to_dev(sd);
struct v4l2_subdev *remote_sd;
int ret = 0;
dev_dbg(csi2->dev, "link setup %s -> %s", remote->entity->name,
local->entity->name);
remote_sd = media_entity_to_v4l2_subdev(remote->entity);
mutex_lock(&csi2->lock);
if (local->flags & MEDIA_PAD_FL_SOURCE) {
if (flags & MEDIA_LNK_FL_ENABLED) {
if (csi2->sink_linked[local->index - 1]) {
ret = -EBUSY;
goto out;
}
csi2->sink_linked[local->index - 1] = true;
} else {
csi2->sink_linked[local->index - 1] = false;
}
} else {
if (flags & MEDIA_LNK_FL_ENABLED) {
if (csi2->src_sd) {
ret = -EBUSY;
goto out;
}
csi2->src_sd = remote_sd;
} else {
csi2->src_sd = NULL;
}
}
out:
mutex_unlock(&csi2->lock);
return ret;
}
static int csi2_get_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct csi2_dev *csi2 = sd_to_dev(sd);
struct v4l2_mbus_framefmt *fmt;
mutex_lock(&csi2->lock);
if (sdformat->which == V4L2_SUBDEV_FORMAT_TRY)
fmt = v4l2_subdev_get_try_format(&csi2->sd, cfg,
sdformat->pad);
else
fmt = &csi2->format_mbus;
sdformat->format = *fmt;
mutex_unlock(&csi2->lock);
return 0;
}
static int csi2_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *sdformat)
{
struct csi2_dev *csi2 = sd_to_dev(sd);
int ret = 0;
if (sdformat->pad >= CSI2_NUM_PADS)
return -EINVAL;
mutex_lock(&csi2->lock);
if (csi2->stream_count > 0) {
ret = -EBUSY;
goto out;
}
if (sdformat->pad != CSI2_SINK_PAD)
sdformat->format = csi2->format_mbus;
if (sdformat->which == V4L2_SUBDEV_FORMAT_TRY)
cfg->try_fmt = sdformat->format;
else
csi2->format_mbus = sdformat->format;
out:
mutex_unlock(&csi2->lock);
return ret;
}
static int csi2_registered(struct v4l2_subdev *sd)
{
struct csi2_dev *csi2 = sd_to_dev(sd);
int i, ret;
for (i = 0; i < CSI2_NUM_PADS; i++) {
csi2->pad[i].flags = (i == CSI2_SINK_PAD) ?
MEDIA_PAD_FL_SINK : MEDIA_PAD_FL_SOURCE;
}
ret = imx_media_init_mbus_fmt(&csi2->format_mbus,
640, 480, 0, V4L2_FIELD_NONE, NULL);
if (ret)
return ret;
return media_entity_pads_init(&sd->entity, CSI2_NUM_PADS, csi2->pad);
}
static int csi2_parse_endpoints(struct csi2_dev *csi2)
{
struct device_node *node = csi2->dev->of_node;
struct device_node *epnode;
struct v4l2_fwnode_endpoint ep;
epnode = of_graph_get_endpoint_by_regs(node, 0, -1);
if (!epnode) {
v4l2_err(&csi2->sd, "failed to get sink endpoint node\n");
return -EINVAL;
}
v4l2_fwnode_endpoint_parse(of_fwnode_handle(epnode), &ep);
of_node_put(epnode);
if (ep.bus_type != V4L2_MBUS_CSI2) {
v4l2_err(&csi2->sd, "invalid bus type, must be MIPI CSI2\n");
return -EINVAL;
}
csi2->bus = ep.bus.mipi_csi2;
dev_dbg(csi2->dev, "data lanes: %d\n", csi2->bus.num_data_lanes);
dev_dbg(csi2->dev, "flags: 0x%08x\n", csi2->bus.flags);
return 0;
}
static int csi2_probe(struct platform_device *pdev)
{
struct csi2_dev *csi2;
struct resource *res;
int ret;
csi2 = devm_kzalloc(&pdev->dev, sizeof(*csi2), GFP_KERNEL);
if (!csi2)
return -ENOMEM;
csi2->dev = &pdev->dev;
v4l2_subdev_init(&csi2->sd, &csi2_subdev_ops);
v4l2_set_subdevdata(&csi2->sd, &pdev->dev);
csi2->sd.internal_ops = &csi2_internal_ops;
csi2->sd.entity.ops = &csi2_entity_ops;
csi2->sd.dev = &pdev->dev;
csi2->sd.owner = THIS_MODULE;
csi2->sd.flags = V4L2_SUBDEV_FL_HAS_DEVNODE;
strcpy(csi2->sd.name, DEVICE_NAME);
csi2->sd.entity.function = MEDIA_ENT_F_VID_IF_BRIDGE;
csi2->sd.grp_id = IMX_MEDIA_GRP_ID_CSI2;
ret = csi2_parse_endpoints(csi2);
if (ret)
return ret;
csi2->pllref_clk = devm_clk_get(&pdev->dev, "ref");
if (IS_ERR(csi2->pllref_clk)) {
v4l2_err(&csi2->sd, "failed to get pll reference clock\n");
ret = PTR_ERR(csi2->pllref_clk);
return ret;
}
csi2->dphy_clk = devm_clk_get(&pdev->dev, "dphy");
if (IS_ERR(csi2->dphy_clk)) {
v4l2_err(&csi2->sd, "failed to get dphy clock\n");
ret = PTR_ERR(csi2->dphy_clk);
return ret;
}
csi2->pix_clk = devm_clk_get(&pdev->dev, "pix");
if (IS_ERR(csi2->pix_clk)) {
v4l2_err(&csi2->sd, "failed to get pixel clock\n");
ret = PTR_ERR(csi2->pix_clk);
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
v4l2_err(&csi2->sd, "failed to get platform resources\n");
return -ENODEV;
}
csi2->base = devm_ioremap(&pdev->dev, res->start, PAGE_SIZE);
if (!csi2->base) {
v4l2_err(&csi2->sd, "failed to map CSI-2 registers\n");
return -ENOMEM;
}
mutex_init(&csi2->lock);
ret = clk_prepare_enable(csi2->pllref_clk);
if (ret) {
v4l2_err(&csi2->sd, "failed to enable pllref_clk\n");
goto rmmutex;
}
ret = clk_prepare_enable(csi2->dphy_clk);
if (ret) {
v4l2_err(&csi2->sd, "failed to enable dphy_clk\n");
goto pllref_off;
}
platform_set_drvdata(pdev, &csi2->sd);
ret = v4l2_async_register_subdev(&csi2->sd);
if (ret)
goto dphy_off;
return 0;
dphy_off:
clk_disable_unprepare(csi2->dphy_clk);
pllref_off:
clk_disable_unprepare(csi2->pllref_clk);
rmmutex:
mutex_destroy(&csi2->lock);
return ret;
}
static int csi2_remove(struct platform_device *pdev)
{
struct v4l2_subdev *sd = platform_get_drvdata(pdev);
struct csi2_dev *csi2 = sd_to_dev(sd);
v4l2_async_unregister_subdev(sd);
clk_disable_unprepare(csi2->dphy_clk);
clk_disable_unprepare(csi2->pllref_clk);
mutex_destroy(&csi2->lock);
media_entity_cleanup(&sd->entity);
return 0;
}
