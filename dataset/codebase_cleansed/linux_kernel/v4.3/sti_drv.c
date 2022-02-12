static void sti_atomic_schedule(struct sti_private *private,
struct drm_atomic_state *state)
{
private->commit.state = state;
schedule_work(&private->commit.work);
}
static void sti_atomic_complete(struct sti_private *private,
struct drm_atomic_state *state)
{
struct drm_device *drm = private->drm_dev;
drm_atomic_helper_commit_modeset_disables(drm, state);
drm_atomic_helper_commit_planes(drm, state);
drm_atomic_helper_commit_modeset_enables(drm, state);
drm_atomic_helper_wait_for_vblanks(drm, state);
drm_atomic_helper_cleanup_planes(drm, state);
drm_atomic_state_free(state);
}
static void sti_atomic_work(struct work_struct *work)
{
struct sti_private *private = container_of(work,
struct sti_private, commit.work);
sti_atomic_complete(private, private->commit.state);
}
static int sti_atomic_commit(struct drm_device *drm,
struct drm_atomic_state *state, bool async)
{
struct sti_private *private = drm->dev_private;
int err;
err = drm_atomic_helper_prepare_planes(drm, state);
if (err)
return err;
mutex_lock(&private->commit.lock);
flush_work(&private->commit.work);
drm_atomic_helper_swap_state(drm, state);
if (async)
sti_atomic_schedule(private, state);
else
sti_atomic_complete(private, state);
mutex_unlock(&private->commit.lock);
return 0;
}
static void sti_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = STI_MAX_FB_HEIGHT;
dev->mode_config.max_height = STI_MAX_FB_WIDTH;
dev->mode_config.funcs = &sti_mode_config_funcs;
}
static int sti_load(struct drm_device *dev, unsigned long flags)
{
struct sti_private *private;
int ret;
private = kzalloc(sizeof(*private), GFP_KERNEL);
if (!private) {
DRM_ERROR("Failed to allocate private\n");
return -ENOMEM;
}
dev->dev_private = (void *)private;
private->drm_dev = dev;
mutex_init(&private->commit.lock);
INIT_WORK(&private->commit.work, sti_atomic_work);
drm_mode_config_init(dev);
drm_kms_helper_poll_init(dev);
sti_mode_config_init(dev);
ret = component_bind_all(dev->dev, dev);
if (ret) {
drm_kms_helper_poll_fini(dev);
drm_mode_config_cleanup(dev);
kfree(private);
return ret;
}
drm_mode_config_reset(dev);
#ifdef CONFIG_DRM_STI_FBDEV
drm_fbdev_cma_init(dev, 32,
dev->mode_config.num_crtc,
dev->mode_config.num_connector);
#endif
return 0;
}
static struct dma_buf *sti_gem_prime_export(struct drm_device *dev,
struct drm_gem_object *obj,
int flags)
{
flags |= O_RDWR;
return drm_gem_prime_export(dev, obj, flags);
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int sti_bind(struct device *dev)
{
return drm_platform_init(&sti_driver, to_platform_device(dev));
}
static void sti_unbind(struct device *dev)
{
drm_put_dev(dev_get_drvdata(dev));
}
static int sti_platform_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct device_node *child_np;
struct component_match *match = NULL;
dma_set_coherent_mask(dev, DMA_BIT_MASK(32));
of_platform_populate(node, NULL, NULL, dev);
child_np = of_get_next_available_child(node, NULL);
while (child_np) {
component_match_add(dev, &match, compare_of, child_np);
of_node_put(child_np);
child_np = of_get_next_available_child(node, child_np);
}
return component_master_add_with_match(dev, &sti_ops, match);
}
static int sti_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &sti_ops);
of_platform_depopulate(&pdev->dev);
return 0;
}
