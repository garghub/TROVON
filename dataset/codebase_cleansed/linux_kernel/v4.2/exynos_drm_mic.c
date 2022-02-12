static void mic_set_path(struct exynos_mic *mic, bool enable)
{
int ret;
unsigned int val;
ret = regmap_read(mic->sysreg, DSD_CFG_MUX, &val);
if (ret) {
DRM_ERROR("mic: Failed to read system register\n");
return;
}
if (enable) {
if (mic->i80_mode)
val |= MIC0_I80_MUX;
else
val |= MIC0_RGB_MUX;
val |= MIC0_ON_MUX;
} else
val &= ~(MIC0_RGB_MUX | MIC0_I80_MUX | MIC0_ON_MUX);
regmap_write(mic->sysreg, DSD_CFG_MUX, val);
if (ret)
DRM_ERROR("mic: Failed to read system register\n");
}
static int mic_sw_reset(struct exynos_mic *mic)
{
unsigned int retry = 100;
int ret;
writel(MIC_SW_RST, mic->reg + MIC_OP);
while (retry-- > 0) {
ret = readl(mic->reg + MIC_OP);
if (!(ret & MIC_SW_RST))
return 0;
udelay(10);
}
return -ETIMEDOUT;
}
static void mic_set_porch_timing(struct exynos_mic *mic)
{
struct videomode vm = mic->vm;
u32 reg;
reg = MIC_V_PULSE_WIDTH(vm.vsync_len) +
MIC_V_PERIOD_LINE(vm.vsync_len + vm.vactive +
vm.vback_porch + vm.vfront_porch);
writel(reg, mic->reg + MIC_V_TIMING_0);
reg = MIC_VBP_SIZE(vm.vback_porch) +
MIC_VFP_SIZE(vm.vfront_porch);
writel(reg, mic->reg + MIC_V_TIMING_1);
reg = MIC_V_PULSE_WIDTH(vm.hsync_len) +
MIC_V_PERIOD_LINE(vm.hsync_len + vm.hactive +
vm.hback_porch + vm.hfront_porch);
writel(reg, mic->reg + MIC_INPUT_TIMING_0);
reg = MIC_VBP_SIZE(vm.hback_porch) +
MIC_VFP_SIZE(vm.hfront_porch);
writel(reg, mic->reg + MIC_INPUT_TIMING_1);
}
static void mic_set_img_size(struct exynos_mic *mic)
{
struct videomode *vm = &mic->vm;
u32 reg;
reg = MIC_IMG_H_SIZE(vm->hactive) +
MIC_IMG_V_SIZE(vm->vactive);
writel(reg, mic->reg + MIC_IMG_SIZE);
}
static void mic_set_output_timing(struct exynos_mic *mic)
{
struct videomode vm = mic->vm;
u32 reg, bs_size_2d;
DRM_DEBUG("w: %u, h: %u\n", vm.hactive, vm.vactive);
bs_size_2d = ((vm.hactive >> 2) << 1) + (vm.vactive % 4);
reg = MIC_BS_SIZE_2D(bs_size_2d);
writel(reg, mic->reg + MIC_2D_OUTPUT_TIMING_2);
if (!mic->i80_mode) {
reg = MIC_H_PULSE_WIDTH_2D(vm.hsync_len) +
MIC_H_PERIOD_PIXEL_2D(vm.hsync_len + bs_size_2d +
vm.hback_porch + vm.hfront_porch);
writel(reg, mic->reg + MIC_2D_OUTPUT_TIMING_0);
reg = MIC_HBP_SIZE_2D(vm.hback_porch) +
MIC_H_PERIOD_PIXEL_2D(vm.hfront_porch);
writel(reg, mic->reg + MIC_2D_OUTPUT_TIMING_1);
}
}
static void mic_set_reg_on(struct exynos_mic *mic, bool enable)
{
u32 reg = readl(mic->reg + MIC_OP);
if (enable) {
reg &= ~(MIC_MODE_SEL_MASK | MIC_CORE_VER_CONTROL | MIC_PSR_EN);
reg |= (MIC_CORE_EN | MIC_BS_CHG_OUT | MIC_ON_REG);
reg &= ~MIC_MODE_SEL_COMMAND_MODE;
if (mic->i80_mode)
reg |= MIC_MODE_SEL_COMMAND_MODE;
} else {
reg &= ~MIC_CORE_EN;
}
reg |= MIC_UPD_REG;
writel(reg, mic->reg + MIC_OP);
}
static struct device_node *get_remote_node(struct device_node *from, int reg)
{
struct device_node *endpoint = NULL, *remote_node = NULL;
endpoint = of_graph_get_endpoint_by_regs(from, reg, -1);
if (!endpoint) {
DRM_ERROR("mic: Failed to find remote port from %s",
from->full_name);
goto exit;
}
remote_node = of_graph_get_remote_port_parent(endpoint);
if (!remote_node) {
DRM_ERROR("mic: Failed to find remote port parent from %s",
from->full_name);
goto exit;
}
exit:
of_node_put(endpoint);
return remote_node;
}
static int parse_dt(struct exynos_mic *mic)
{
int ret = 0, i, j;
struct device_node *remote_node;
struct device_node *nodes[3];
for (i = 0, j = 0; i < NUM_ENDPOINTS; i++) {
remote_node = get_remote_node(mic->dev->of_node, i);
if (!remote_node) {
ret = -EPIPE;
goto exit;
}
nodes[j++] = remote_node;
switch (i) {
case ENDPOINT_DECON_NODE:
if (of_get_child_by_name(remote_node,
"i80-if-timings"))
mic->i80_mode = 1;
break;
case ENDPOINT_DSI_NODE:
remote_node = get_remote_node(remote_node, 1);
if (!remote_node) {
ret = -EPIPE;
goto exit;
}
nodes[j++] = remote_node;
ret = of_get_videomode(remote_node,
&mic->vm, 0);
if (ret) {
DRM_ERROR("mic: failed to get videomode");
goto exit;
}
break;
default:
DRM_ERROR("mic: Unknown endpoint from MIC");
break;
}
}
exit:
while (--j > -1)
of_node_put(nodes[j]);
return ret;
}
void mic_disable(struct drm_bridge *bridge) { }
void mic_post_disable(struct drm_bridge *bridge)
{
struct exynos_mic *mic = bridge->driver_private;
int i;
mutex_lock(&mic_mutex);
if (!mic->enabled)
goto already_disabled;
mic_set_path(mic, 0);
for (i = NUM_CLKS - 1; i > -1; i--)
clk_disable_unprepare(mic->clks[i]);
mic->enabled = 0;
already_disabled:
mutex_unlock(&mic_mutex);
}
void mic_pre_enable(struct drm_bridge *bridge)
{
struct exynos_mic *mic = bridge->driver_private;
int ret, i;
mutex_lock(&mic_mutex);
if (mic->enabled)
goto already_enabled;
for (i = 0; i < NUM_CLKS; i++) {
ret = clk_prepare_enable(mic->clks[i]);
if (ret < 0) {
DRM_ERROR("Failed to enable clock (%s)\n",
clk_names[i]);
goto turn_off_clks;
}
}
mic_set_path(mic, 1);
ret = mic_sw_reset(mic);
if (ret) {
DRM_ERROR("Failed to reset\n");
goto turn_off_clks;
}
if (!mic->i80_mode)
mic_set_porch_timing(mic);
mic_set_img_size(mic);
mic_set_output_timing(mic);
mic_set_reg_on(mic, 1);
mic->enabled = 1;
mutex_unlock(&mic_mutex);
return;
turn_off_clks:
while (--i > -1)
clk_disable_unprepare(mic->clks[i]);
already_enabled:
mutex_unlock(&mic_mutex);
}
void mic_enable(struct drm_bridge *bridge) { }
void mic_destroy(struct drm_bridge *bridge)
{
struct exynos_mic *mic = bridge->driver_private;
int i;
mutex_lock(&mic_mutex);
if (!mic->enabled)
goto already_disabled;
for (i = NUM_CLKS - 1; i > -1; i--)
clk_disable_unprepare(mic->clks[i]);
already_disabled:
mutex_unlock(&mic_mutex);
}
int exynos_mic_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct exynos_mic *mic;
struct resource res;
int ret, i;
mic = devm_kzalloc(dev, sizeof(*mic), GFP_KERNEL);
if (!mic) {
DRM_ERROR("mic: Failed to allocate memory for MIC object\n");
ret = -ENOMEM;
goto err;
}
mic->dev = dev;
ret = parse_dt(mic);
if (ret)
goto err;
ret = of_address_to_resource(dev->of_node, 0, &res);
if (ret) {
DRM_ERROR("mic: Failed to get mem region for MIC\n");
goto err;
}
mic->reg = devm_ioremap(dev, res.start, resource_size(&res));
if (!mic->reg) {
DRM_ERROR("mic: Failed to remap for MIC\n");
ret = -ENOMEM;
goto err;
}
mic->sysreg = syscon_regmap_lookup_by_phandle(dev->of_node,
"samsung,disp-syscon");
if (IS_ERR(mic->sysreg)) {
DRM_ERROR("mic: Failed to get system register.\n");
goto err;
}
mic->bridge.funcs = &mic_bridge_funcs;
mic->bridge.of_node = dev->of_node;
mic->bridge.driver_private = mic;
ret = drm_bridge_add(&mic->bridge);
if (ret) {
DRM_ERROR("mic: Failed to add MIC to the global bridge list\n");
goto err;
}
for (i = 0; i < NUM_CLKS; i++) {
mic->clks[i] = of_clk_get_by_name(dev->of_node, clk_names[i]);
if (IS_ERR(mic->clks[i])) {
DRM_ERROR("mic: Failed to get clock (%s)\n",
clk_names[i]);
ret = PTR_ERR(mic->clks[i]);
goto err;
}
}
DRM_DEBUG_KMS("MIC has been probed\n");
err:
return ret;
}
static int exynos_mic_remove(struct platform_device *pdev)
{
struct exynos_mic *mic = platform_get_drvdata(pdev);
int i;
drm_bridge_remove(&mic->bridge);
for (i = NUM_CLKS - 1; i > -1; i--)
clk_put(mic->clks[i]);
return 0;
}
