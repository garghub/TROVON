static void malidp_write_gamma_table(struct malidp_hw_device *hwdev,
u32 data[MALIDP_COEFFTAB_NUM_COEFFS])
{
int i;
const u32 gamma_write_mask = GENMASK(18, 16);
malidp_hw_write(hwdev, gamma_write_mask,
hwdev->map.coeffs_base + MALIDP_COEF_TABLE_ADDR);
for (i = 0; i < MALIDP_COEFFTAB_NUM_COEFFS; ++i)
malidp_hw_write(hwdev, data[i],
hwdev->map.coeffs_base +
MALIDP_COEF_TABLE_DATA);
}
static void malidp_atomic_commit_update_gamma(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
if (!crtc->state->color_mgmt_changed)
return;
if (!crtc->state->gamma_lut) {
malidp_hw_clearbits(hwdev,
MALIDP_DISP_FUNC_GAMMA,
MALIDP_DE_DISPLAY_FUNC);
} else {
struct malidp_crtc_state *mc =
to_malidp_crtc_state(crtc->state);
if (!old_state->gamma_lut || (crtc->state->gamma_lut->base.id !=
old_state->gamma_lut->base.id))
malidp_write_gamma_table(hwdev, mc->gamma_coeffs);
malidp_hw_setbits(hwdev, MALIDP_DISP_FUNC_GAMMA,
MALIDP_DE_DISPLAY_FUNC);
}
}
static
void malidp_atomic_commit_update_coloradj(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
int i;
if (!crtc->state->color_mgmt_changed)
return;
if (!crtc->state->ctm) {
malidp_hw_clearbits(hwdev, MALIDP_DISP_FUNC_CADJ,
MALIDP_DE_DISPLAY_FUNC);
} else {
struct malidp_crtc_state *mc =
to_malidp_crtc_state(crtc->state);
if (!old_state->ctm || (crtc->state->ctm->base.id !=
old_state->ctm->base.id))
for (i = 0; i < MALIDP_COLORADJ_NUM_COEFFS; ++i)
malidp_hw_write(hwdev,
mc->coloradj_coeffs[i],
hwdev->map.coeffs_base +
MALIDP_COLOR_ADJ_COEF + 4 * i);
malidp_hw_setbits(hwdev, MALIDP_DISP_FUNC_CADJ,
MALIDP_DE_DISPLAY_FUNC);
}
}
static void malidp_atomic_commit_se_config(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct malidp_crtc_state *cs = to_malidp_crtc_state(crtc->state);
struct malidp_crtc_state *old_cs = to_malidp_crtc_state(old_state);
struct malidp_drm *malidp = crtc_to_malidp_device(crtc);
struct malidp_hw_device *hwdev = malidp->dev;
struct malidp_se_config *s = &cs->scaler_config;
struct malidp_se_config *old_s = &old_cs->scaler_config;
u32 se_control = hwdev->map.se_base +
((hwdev->map.features & MALIDP_REGMAP_HAS_CLEARIRQ) ?
0x10 : 0xC);
u32 layer_control = se_control + MALIDP_SE_LAYER_CONTROL;
u32 scr = se_control + MALIDP_SE_SCALING_CONTROL;
u32 val;
if (!s->scale_enable) {
val = malidp_hw_read(hwdev, se_control);
val &= ~MALIDP_SE_SCALING_EN;
malidp_hw_write(hwdev, val, se_control);
return;
}
hwdev->se_set_scaling_coeffs(hwdev, s, old_s);
val = malidp_hw_read(hwdev, se_control);
val |= MALIDP_SE_SCALING_EN | MALIDP_SE_ALPHA_EN;
val &= ~MALIDP_SE_ENH(MALIDP_SE_ENH_MASK);
val |= s->enhancer_enable ? MALIDP_SE_ENH(3) : 0;
val |= MALIDP_SE_RGBO_IF_EN;
malidp_hw_write(hwdev, val, se_control);
val = MALIDP_SE_SET_V_SIZE(s->input_h) |
MALIDP_SE_SET_H_SIZE(s->input_w);
malidp_hw_write(hwdev, val, layer_control + MALIDP_SE_L0_IN_SIZE);
val = MALIDP_SE_SET_V_SIZE(s->output_h) |
MALIDP_SE_SET_H_SIZE(s->output_w);
malidp_hw_write(hwdev, val, layer_control + MALIDP_SE_L0_OUT_SIZE);
malidp_hw_write(hwdev, s->h_init_phase, scr + MALIDP_SE_H_INIT_PH);
malidp_hw_write(hwdev, s->h_delta_phase, scr + MALIDP_SE_H_DELTA_PH);
malidp_hw_write(hwdev, s->v_init_phase, scr + MALIDP_SE_V_INIT_PH);
malidp_hw_write(hwdev, s->v_delta_phase, scr + MALIDP_SE_V_DELTA_PH);
}
static int malidp_set_and_wait_config_valid(struct drm_device *drm)
{
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
int ret;
atomic_set(&malidp->config_valid, 0);
hwdev->set_config_valid(hwdev);
if (hwdev->in_config_mode(hwdev))
return 0;
ret = wait_event_interruptible_timeout(malidp->wq,
atomic_read(&malidp->config_valid) == 1,
msecs_to_jiffies(MALIDP_CONF_VALID_TIMEOUT));
return (ret > 0) ? 0 : -ETIMEDOUT;
}
static void malidp_output_poll_changed(struct drm_device *drm)
{
struct malidp_drm *malidp = drm->dev_private;
drm_fbdev_cma_hotplug_event(malidp->fbdev);
}
static void malidp_atomic_commit_hw_done(struct drm_atomic_state *state)
{
struct drm_pending_vblank_event *event;
struct drm_device *drm = state->dev;
struct malidp_drm *malidp = drm->dev_private;
if (malidp->crtc.enabled) {
if (malidp_set_and_wait_config_valid(drm))
DRM_DEBUG_DRIVER("timed out waiting for updated configuration\n");
}
event = malidp->crtc.state->event;
if (event) {
malidp->crtc.state->event = NULL;
spin_lock_irq(&drm->event_lock);
if (drm_crtc_vblank_get(&malidp->crtc) == 0)
drm_crtc_arm_vblank_event(&malidp->crtc, event);
else
drm_crtc_send_vblank_event(&malidp->crtc, event);
spin_unlock_irq(&drm->event_lock);
}
drm_atomic_helper_commit_hw_done(state);
}
static void malidp_atomic_commit_tail(struct drm_atomic_state *state)
{
struct drm_device *drm = state->dev;
struct drm_crtc *crtc;
struct drm_crtc_state *old_crtc_state;
int i;
pm_runtime_get_sync(drm->dev);
drm_atomic_helper_commit_modeset_disables(drm, state);
for_each_crtc_in_state(state, crtc, old_crtc_state, i) {
malidp_atomic_commit_update_gamma(crtc, old_crtc_state);
malidp_atomic_commit_update_coloradj(crtc, old_crtc_state);
malidp_atomic_commit_se_config(crtc, old_crtc_state);
}
drm_atomic_helper_commit_planes(drm, state, 0);
drm_atomic_helper_commit_modeset_enables(drm, state);
malidp_atomic_commit_hw_done(state);
drm_atomic_helper_wait_for_vblanks(drm, state);
pm_runtime_put(drm->dev);
drm_atomic_helper_cleanup_planes(drm, state);
}
static int malidp_init(struct drm_device *drm)
{
int ret;
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
drm_mode_config_init(drm);
drm->mode_config.min_width = hwdev->min_line_size;
drm->mode_config.min_height = hwdev->min_line_size;
drm->mode_config.max_width = hwdev->max_line_size;
drm->mode_config.max_height = hwdev->max_line_size;
drm->mode_config.funcs = &malidp_mode_config_funcs;
drm->mode_config.helper_private = &malidp_mode_config_helpers;
ret = malidp_crtc_init(drm);
if (ret) {
drm_mode_config_cleanup(drm);
return ret;
}
return 0;
}
static void malidp_fini(struct drm_device *drm)
{
malidp_de_planes_destroy(drm);
drm_mode_config_cleanup(drm);
}
static int malidp_irq_init(struct platform_device *pdev)
{
int irq_de, irq_se, ret = 0;
struct drm_device *drm = dev_get_drvdata(&pdev->dev);
irq_de = platform_get_irq_byname(pdev, "DE");
if (irq_de < 0) {
DRM_ERROR("no 'DE' IRQ specified!\n");
return irq_de;
}
irq_se = platform_get_irq_byname(pdev, "SE");
if (irq_se < 0) {
DRM_ERROR("no 'SE' IRQ specified!\n");
return irq_se;
}
ret = malidp_de_irq_init(drm, irq_de);
if (ret)
return ret;
ret = malidp_se_irq_init(drm, irq_se);
if (ret) {
malidp_de_irq_fini(drm);
return ret;
}
return 0;
}
static void malidp_lastclose(struct drm_device *drm)
{
struct malidp_drm *malidp = drm->dev_private;
drm_fbdev_cma_restore_mode(malidp->fbdev);
}
static bool malidp_is_compatible_hw_id(struct malidp_hw_device *hwdev,
const struct of_device_id *dev_id)
{
u32 core_id;
const char *compatstr_dp500 = "arm,mali-dp500";
bool is_dp500;
bool dt_is_dp500;
core_id = malidp_hw_read(hwdev, MALIDP500_DC_BASE + MALIDP_DE_CORE_ID);
is_dp500 = (MALIDP_PRODUCT_ID(core_id) == 0x500);
dt_is_dp500 = strnstr(dev_id->compatible, compatstr_dp500,
sizeof(dev_id->compatible)) != NULL;
if (is_dp500 != dt_is_dp500) {
DRM_ERROR("Device-tree expects %s, but hardware %s DP500.\n",
dev_id->compatible, is_dp500 ? "is" : "is not");
return false;
} else if (!dt_is_dp500) {
u16 product_id;
char buf[32];
core_id = malidp_hw_read(hwdev,
MALIDP550_DC_BASE + MALIDP_DE_CORE_ID);
product_id = MALIDP_PRODUCT_ID(core_id);
snprintf(buf, sizeof(buf), "arm,mali-dp%X", product_id);
if (!strnstr(dev_id->compatible, buf,
sizeof(dev_id->compatible))) {
DRM_ERROR("Device-tree expects %s, but hardware is DP%03X.\n",
dev_id->compatible, product_id);
return false;
}
}
return true;
}
static bool malidp_has_sufficient_address_space(const struct resource *res,
const struct of_device_id *dev_id)
{
resource_size_t res_size = resource_size(res);
const char *compatstr_dp500 = "arm,mali-dp500";
if (!strnstr(dev_id->compatible, compatstr_dp500,
sizeof(dev_id->compatible)))
return res_size >= MALIDP550_ADDR_SPACE_SIZE;
else if (res_size < MALIDP500_ADDR_SPACE_SIZE)
return false;
return true;
}
static ssize_t core_id_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct malidp_drm *malidp = drm->dev_private;
return snprintf(buf, PAGE_SIZE, "%08x\n", malidp->core_id);
}
static int malidp_init_sysfs(struct device *dev)
{
int ret = device_create_file(dev, &dev_attr_core_id);
if (ret)
DRM_ERROR("failed to create device file for core_id\n");
return ret;
}
static void malidp_fini_sysfs(struct device *dev)
{
device_remove_file(dev, &dev_attr_core_id);
}
static int malidp_runtime_pm_suspend(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
WARN_ON(!hwdev->in_config_mode(hwdev));
hwdev->pm_suspended = true;
clk_disable_unprepare(hwdev->mclk);
clk_disable_unprepare(hwdev->aclk);
clk_disable_unprepare(hwdev->pclk);
return 0;
}
static int malidp_runtime_pm_resume(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
clk_prepare_enable(hwdev->pclk);
clk_prepare_enable(hwdev->aclk);
clk_prepare_enable(hwdev->mclk);
hwdev->pm_suspended = false;
return 0;
}
static int malidp_bind(struct device *dev)
{
struct resource *res;
struct drm_device *drm;
struct malidp_drm *malidp;
struct malidp_hw_device *hwdev;
struct platform_device *pdev = to_platform_device(dev);
struct of_device_id const *dev_id;
u8 output_width[MAX_OUTPUT_CHANNELS];
int ret = 0, i;
u32 version, out_depth = 0;
malidp = devm_kzalloc(dev, sizeof(*malidp), GFP_KERNEL);
if (!malidp)
return -ENOMEM;
hwdev = devm_kzalloc(dev, sizeof(*hwdev), GFP_KERNEL);
if (!hwdev)
return -ENOMEM;
memcpy(hwdev, of_device_get_match_data(dev), sizeof(*hwdev));
malidp->dev = hwdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hwdev->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(hwdev->regs))
return PTR_ERR(hwdev->regs);
hwdev->pclk = devm_clk_get(dev, "pclk");
if (IS_ERR(hwdev->pclk))
return PTR_ERR(hwdev->pclk);
hwdev->aclk = devm_clk_get(dev, "aclk");
if (IS_ERR(hwdev->aclk))
return PTR_ERR(hwdev->aclk);
hwdev->mclk = devm_clk_get(dev, "mclk");
if (IS_ERR(hwdev->mclk))
return PTR_ERR(hwdev->mclk);
hwdev->pxlclk = devm_clk_get(dev, "pxlclk");
if (IS_ERR(hwdev->pxlclk))
return PTR_ERR(hwdev->pxlclk);
ret = of_reserved_mem_device_init(dev);
if (ret && ret != -ENODEV)
return ret;
drm = drm_dev_alloc(&malidp_driver, dev);
if (IS_ERR(drm)) {
ret = PTR_ERR(drm);
goto alloc_fail;
}
drm->dev_private = malidp;
dev_set_drvdata(dev, drm);
pm_runtime_enable(dev);
if (pm_runtime_enabled(dev))
pm_runtime_get_sync(dev);
else
malidp_runtime_pm_resume(dev);
dev_id = of_match_device(malidp_drm_of_match, dev);
if (!dev_id) {
ret = -EINVAL;
goto query_hw_fail;
}
if (!malidp_has_sufficient_address_space(res, dev_id)) {
DRM_ERROR("Insufficient address space in device-tree.\n");
ret = -EINVAL;
goto query_hw_fail;
}
if (!malidp_is_compatible_hw_id(hwdev, dev_id)) {
ret = -EINVAL;
goto query_hw_fail;
}
ret = hwdev->query_hw(hwdev);
if (ret) {
DRM_ERROR("Invalid HW configuration\n");
goto query_hw_fail;
}
version = malidp_hw_read(hwdev, hwdev->map.dc_base + MALIDP_DE_CORE_ID);
DRM_INFO("found ARM Mali-DP%3x version r%dp%d\n", version >> 16,
(version >> 12) & 0xf, (version >> 8) & 0xf);
malidp->core_id = version;
ret = of_property_read_u8_array(dev->of_node,
"arm,malidp-output-port-lines",
output_width, MAX_OUTPUT_CHANNELS);
if (ret)
goto query_hw_fail;
for (i = 0; i < MAX_OUTPUT_CHANNELS; i++)
out_depth = (out_depth << 8) | (output_width[i] & 0xf);
malidp_hw_write(hwdev, out_depth, hwdev->map.out_depth_base);
atomic_set(&malidp->config_valid, 0);
init_waitqueue_head(&malidp->wq);
ret = malidp_init(drm);
if (ret < 0)
goto query_hw_fail;
ret = malidp_init_sysfs(dev);
if (ret)
goto init_fail;
malidp->crtc.port = of_graph_get_port_by_id(dev->of_node, 0);
ret = component_bind_all(dev, drm);
if (ret) {
DRM_ERROR("Failed to bind all components\n");
goto bind_fail;
}
ret = malidp_irq_init(pdev);
if (ret < 0)
goto irq_init_fail;
drm->irq_enabled = true;
ret = drm_vblank_init(drm, drm->mode_config.num_crtc);
if (ret < 0) {
DRM_ERROR("failed to initialise vblank\n");
goto vblank_fail;
}
pm_runtime_put(dev);
drm_mode_config_reset(drm);
malidp->fbdev = drm_fbdev_cma_init(drm, 32,
drm->mode_config.num_connector);
if (IS_ERR(malidp->fbdev)) {
ret = PTR_ERR(malidp->fbdev);
malidp->fbdev = NULL;
goto fbdev_fail;
}
drm_kms_helper_poll_init(drm);
ret = drm_dev_register(drm, 0);
if (ret)
goto register_fail;
return 0;
register_fail:
if (malidp->fbdev) {
drm_fbdev_cma_fini(malidp->fbdev);
malidp->fbdev = NULL;
}
drm_kms_helper_poll_fini(drm);
fbdev_fail:
pm_runtime_get_sync(dev);
vblank_fail:
malidp_se_irq_fini(drm);
malidp_de_irq_fini(drm);
drm->irq_enabled = false;
irq_init_fail:
component_unbind_all(dev, drm);
bind_fail:
of_node_put(malidp->crtc.port);
malidp->crtc.port = NULL;
init_fail:
malidp_fini_sysfs(dev);
malidp_fini(drm);
query_hw_fail:
pm_runtime_put(dev);
if (pm_runtime_enabled(dev))
pm_runtime_disable(dev);
else
malidp_runtime_pm_suspend(dev);
drm->dev_private = NULL;
dev_set_drvdata(dev, NULL);
drm_dev_unref(drm);
alloc_fail:
of_reserved_mem_device_release(dev);
return ret;
}
static void malidp_unbind(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct malidp_drm *malidp = drm->dev_private;
drm_dev_unregister(drm);
if (malidp->fbdev) {
drm_fbdev_cma_fini(malidp->fbdev);
malidp->fbdev = NULL;
}
drm_kms_helper_poll_fini(drm);
pm_runtime_get_sync(dev);
malidp_se_irq_fini(drm);
malidp_de_irq_fini(drm);
component_unbind_all(dev, drm);
of_node_put(malidp->crtc.port);
malidp->crtc.port = NULL;
malidp_fini_sysfs(dev);
malidp_fini(drm);
pm_runtime_put(dev);
if (pm_runtime_enabled(dev))
pm_runtime_disable(dev);
else
malidp_runtime_pm_suspend(dev);
drm->dev_private = NULL;
dev_set_drvdata(dev, NULL);
drm_dev_unref(drm);
of_reserved_mem_device_release(dev);
}
static int malidp_compare_dev(struct device *dev, void *data)
{
struct device_node *np = data;
return dev->of_node == np;
}
static int malidp_platform_probe(struct platform_device *pdev)
{
struct device_node *port;
struct component_match *match = NULL;
if (!pdev->dev.of_node)
return -ENODEV;
port = of_graph_get_remote_node(pdev->dev.of_node, 0, 0);
if (!port)
return -ENODEV;
drm_of_component_match_add(&pdev->dev, &match, malidp_compare_dev,
port);
of_node_put(port);
return component_master_add_with_match(&pdev->dev, &malidp_master_ops,
match);
}
static int malidp_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &malidp_master_ops);
return 0;
}
static int __maybe_unused malidp_pm_suspend(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct malidp_drm *malidp = drm->dev_private;
drm_kms_helper_poll_disable(drm);
console_lock();
drm_fbdev_cma_set_suspend(malidp->fbdev, 1);
console_unlock();
malidp->pm_state = drm_atomic_helper_suspend(drm);
if (IS_ERR(malidp->pm_state)) {
console_lock();
drm_fbdev_cma_set_suspend(malidp->fbdev, 0);
console_unlock();
drm_kms_helper_poll_enable(drm);
return PTR_ERR(malidp->pm_state);
}
return 0;
}
static int __maybe_unused malidp_pm_resume(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
struct malidp_drm *malidp = drm->dev_private;
drm_atomic_helper_resume(drm, malidp->pm_state);
console_lock();
drm_fbdev_cma_set_suspend(malidp->fbdev, 0);
console_unlock();
drm_kms_helper_poll_enable(drm);
return 0;
}
