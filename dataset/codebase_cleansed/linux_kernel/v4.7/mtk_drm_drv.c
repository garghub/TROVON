static void mtk_atomic_schedule(struct mtk_drm_private *private,
struct drm_atomic_state *state)
{
private->commit.state = state;
schedule_work(&private->commit.work);
}
static void mtk_atomic_wait_for_fences(struct drm_atomic_state *state)
{
struct drm_plane *plane;
struct drm_plane_state *plane_state;
int i;
for_each_plane_in_state(state, plane, plane_state, i)
mtk_fb_wait(plane->state->fb);
}
static void mtk_atomic_complete(struct mtk_drm_private *private,
struct drm_atomic_state *state)
{
struct drm_device *drm = private->drm;
mtk_atomic_wait_for_fences(state);
drm_atomic_helper_commit_modeset_disables(drm, state);
drm_atomic_helper_commit_planes(drm, state, false);
drm_atomic_helper_commit_modeset_enables(drm, state);
drm_atomic_helper_wait_for_vblanks(drm, state);
drm_atomic_helper_cleanup_planes(drm, state);
drm_atomic_state_free(state);
}
static void mtk_atomic_work(struct work_struct *work)
{
struct mtk_drm_private *private = container_of(work,
struct mtk_drm_private, commit.work);
mtk_atomic_complete(private, private->commit.state);
}
static int mtk_atomic_commit(struct drm_device *drm,
struct drm_atomic_state *state,
bool async)
{
struct mtk_drm_private *private = drm->dev_private;
int ret;
ret = drm_atomic_helper_prepare_planes(drm, state);
if (ret)
return ret;
mutex_lock(&private->commit.lock);
flush_work(&private->commit.work);
drm_atomic_helper_swap_state(drm, state);
if (async)
mtk_atomic_schedule(private, state);
else
mtk_atomic_complete(private, state);
mutex_unlock(&private->commit.lock);
return 0;
}
static int mtk_drm_kms_init(struct drm_device *drm)
{
struct mtk_drm_private *private = drm->dev_private;
struct platform_device *pdev;
struct device_node *np;
int ret;
if (!iommu_present(&platform_bus_type))
return -EPROBE_DEFER;
pdev = of_find_device_by_node(private->mutex_node);
if (!pdev) {
dev_err(drm->dev, "Waiting for disp-mutex device %s\n",
private->mutex_node->full_name);
of_node_put(private->mutex_node);
return -EPROBE_DEFER;
}
private->mutex_dev = &pdev->dev;
drm_mode_config_init(drm);
drm->mode_config.min_width = 64;
drm->mode_config.min_height = 64;
drm->mode_config.max_width = 4096;
drm->mode_config.max_height = 4096;
drm->mode_config.funcs = &mtk_drm_mode_config_funcs;
ret = component_bind_all(drm->dev, drm);
if (ret)
goto err_config_cleanup;
ret = mtk_drm_crtc_create(drm, mtk_ddp_main, ARRAY_SIZE(mtk_ddp_main));
if (ret < 0)
goto err_component_unbind;
ret = mtk_drm_crtc_create(drm, mtk_ddp_ext, ARRAY_SIZE(mtk_ddp_ext));
if (ret < 0)
goto err_component_unbind;
np = private->comp_node[mtk_ddp_main[0]] ?:
private->comp_node[mtk_ddp_ext[0]];
pdev = of_find_device_by_node(np);
if (!pdev) {
ret = -ENODEV;
dev_err(drm->dev, "Need at least one OVL device\n");
goto err_component_unbind;
}
private->dma_dev = &pdev->dev;
drm->irq_enabled = true;
ret = drm_vblank_init(drm, MAX_CRTC);
if (ret < 0)
goto err_component_unbind;
drm_kms_helper_poll_init(drm);
drm_mode_config_reset(drm);
return 0;
err_component_unbind:
component_unbind_all(drm->dev, drm);
err_config_cleanup:
drm_mode_config_cleanup(drm);
return ret;
}
static void mtk_drm_kms_deinit(struct drm_device *drm)
{
drm_kms_helper_poll_fini(drm);
drm_vblank_cleanup(drm);
component_unbind_all(drm->dev, drm);
drm_mode_config_cleanup(drm);
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int mtk_drm_bind(struct device *dev)
{
struct mtk_drm_private *private = dev_get_drvdata(dev);
struct drm_device *drm;
int ret;
drm = drm_dev_alloc(&mtk_drm_driver, dev);
if (!drm)
return -ENOMEM;
drm_dev_set_unique(drm, dev_name(dev));
drm->dev_private = private;
private->drm = drm;
ret = mtk_drm_kms_init(drm);
if (ret < 0)
goto err_free;
ret = drm_dev_register(drm, 0);
if (ret < 0)
goto err_deinit;
ret = drm_connector_register_all(drm);
if (ret < 0)
goto err_unregister;
return 0;
err_unregister:
drm_dev_unregister(drm);
err_deinit:
mtk_drm_kms_deinit(drm);
err_free:
drm_dev_unref(drm);
return ret;
}
static void mtk_drm_unbind(struct device *dev)
{
struct mtk_drm_private *private = dev_get_drvdata(dev);
drm_put_dev(private->drm);
private->drm = NULL;
}
static int mtk_drm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_drm_private *private;
struct resource *mem;
struct device_node *node;
struct component_match *match = NULL;
int ret;
int i;
private = devm_kzalloc(dev, sizeof(*private), GFP_KERNEL);
if (!private)
return -ENOMEM;
mutex_init(&private->commit.lock);
INIT_WORK(&private->commit.work, mtk_atomic_work);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
private->config_regs = devm_ioremap_resource(dev, mem);
if (IS_ERR(private->config_regs)) {
ret = PTR_ERR(private->config_regs);
dev_err(dev, "Failed to ioremap mmsys-config resource: %d\n",
ret);
return ret;
}
for_each_child_of_node(dev->of_node->parent, node) {
const struct of_device_id *of_id;
enum mtk_ddp_comp_type comp_type;
int comp_id;
of_id = of_match_node(mtk_ddp_comp_dt_ids, node);
if (!of_id)
continue;
if (!of_device_is_available(node)) {
dev_dbg(dev, "Skipping disabled component %s\n",
node->full_name);
continue;
}
comp_type = (enum mtk_ddp_comp_type)of_id->data;
if (comp_type == MTK_DISP_MUTEX) {
private->mutex_node = of_node_get(node);
continue;
}
comp_id = mtk_ddp_comp_get_id(node, comp_type);
if (comp_id < 0) {
dev_warn(dev, "Skipping unknown component %s\n",
node->full_name);
continue;
}
private->comp_node[comp_id] = of_node_get(node);
if (comp_type == MTK_DISP_OVL ||
comp_type == MTK_DISP_RDMA ||
comp_type == MTK_DSI ||
comp_type == MTK_DPI) {
dev_info(dev, "Adding component match for %s\n",
node->full_name);
component_match_add(dev, &match, compare_of, node);
} else {
struct mtk_ddp_comp *comp;
comp = devm_kzalloc(dev, sizeof(*comp), GFP_KERNEL);
if (!comp) {
ret = -ENOMEM;
goto err_node;
}
ret = mtk_ddp_comp_init(dev, node, comp, comp_id, NULL);
if (ret)
goto err_node;
private->ddp_comp[comp_id] = comp;
}
}
if (!private->mutex_node) {
dev_err(dev, "Failed to find disp-mutex node\n");
ret = -ENODEV;
goto err_node;
}
pm_runtime_enable(dev);
platform_set_drvdata(pdev, private);
ret = component_master_add_with_match(dev, &mtk_drm_ops, match);
if (ret)
goto err_pm;
return 0;
err_pm:
pm_runtime_disable(dev);
err_node:
of_node_put(private->mutex_node);
for (i = 0; i < DDP_COMPONENT_ID_MAX; i++)
of_node_put(private->comp_node[i]);
return ret;
}
static int mtk_drm_remove(struct platform_device *pdev)
{
struct mtk_drm_private *private = platform_get_drvdata(pdev);
struct drm_device *drm = private->drm;
int i;
drm_connector_unregister_all(drm);
drm_dev_unregister(drm);
mtk_drm_kms_deinit(drm);
drm_dev_unref(drm);
component_master_del(&pdev->dev, &mtk_drm_ops);
pm_runtime_disable(&pdev->dev);
of_node_put(private->mutex_node);
for (i = 0; i < DDP_COMPONENT_ID_MAX; i++)
of_node_put(private->comp_node[i]);
return 0;
}
static int mtk_drm_sys_suspend(struct device *dev)
{
struct mtk_drm_private *private = dev_get_drvdata(dev);
struct drm_device *drm = private->drm;
drm_kms_helper_poll_disable(drm);
private->suspend_state = drm_atomic_helper_suspend(drm);
if (IS_ERR(private->suspend_state)) {
drm_kms_helper_poll_enable(drm);
return PTR_ERR(private->suspend_state);
}
DRM_DEBUG_DRIVER("mtk_drm_sys_suspend\n");
return 0;
}
static int mtk_drm_sys_resume(struct device *dev)
{
struct mtk_drm_private *private = dev_get_drvdata(dev);
struct drm_device *drm = private->drm;
drm_atomic_helper_resume(drm, private->suspend_state);
drm_kms_helper_poll_enable(drm);
DRM_DEBUG_DRIVER("mtk_drm_sys_resume\n");
return 0;
}
static int __init mtk_drm_init(void)
{
int ret;
int i;
for (i = 0; i < ARRAY_SIZE(mtk_drm_drivers); i++) {
ret = platform_driver_register(mtk_drm_drivers[i]);
if (ret < 0) {
pr_err("Failed to register %s driver: %d\n",
mtk_drm_drivers[i]->driver.name, ret);
goto err;
}
}
return 0;
err:
while (--i >= 0)
platform_driver_unregister(mtk_drm_drivers[i]);
return ret;
}
static void __exit mtk_drm_exit(void)
{
int i;
for (i = ARRAY_SIZE(mtk_drm_drivers) - 1; i >= 0; i--)
platform_driver_unregister(mtk_drm_drivers[i]);
}
