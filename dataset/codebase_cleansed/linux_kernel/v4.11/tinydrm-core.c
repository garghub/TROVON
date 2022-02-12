void tinydrm_lastclose(struct drm_device *drm)
{
struct tinydrm_device *tdev = drm->dev_private;
DRM_DEBUG_KMS("\n");
drm_fbdev_cma_restore_mode(tdev->fbdev_cma);
}
struct drm_gem_object *
tinydrm_gem_cma_prime_import_sg_table(struct drm_device *drm,
struct dma_buf_attachment *attach,
struct sg_table *sgt)
{
struct drm_gem_cma_object *cma_obj;
struct drm_gem_object *obj;
void *vaddr;
vaddr = dma_buf_vmap(attach->dmabuf);
if (!vaddr) {
DRM_ERROR("Failed to vmap PRIME buffer\n");
return ERR_PTR(-ENOMEM);
}
obj = drm_gem_cma_prime_import_sg_table(drm, attach, sgt);
if (IS_ERR(obj)) {
dma_buf_vunmap(attach->dmabuf, vaddr);
return obj;
}
cma_obj = to_drm_gem_cma_obj(obj);
cma_obj->vaddr = vaddr;
return obj;
}
void tinydrm_gem_cma_free_object(struct drm_gem_object *gem_obj)
{
if (gem_obj->import_attach) {
struct drm_gem_cma_object *cma_obj;
cma_obj = to_drm_gem_cma_obj(gem_obj);
dma_buf_vunmap(gem_obj->import_attach->dmabuf, cma_obj->vaddr);
cma_obj->vaddr = NULL;
}
drm_gem_cma_free_object(gem_obj);
}
static struct drm_framebuffer *
tinydrm_fb_create(struct drm_device *drm, struct drm_file *file_priv,
const struct drm_mode_fb_cmd2 *mode_cmd)
{
struct tinydrm_device *tdev = drm->dev_private;
return drm_fb_cma_create_with_funcs(drm, file_priv, mode_cmd,
tdev->fb_funcs);
}
static int tinydrm_init(struct device *parent, struct tinydrm_device *tdev,
const struct drm_framebuffer_funcs *fb_funcs,
struct drm_driver *driver)
{
struct drm_device *drm;
mutex_init(&tdev->dirty_lock);
tdev->fb_funcs = fb_funcs;
drm = drm_dev_alloc(driver, parent);
if (IS_ERR(drm))
return PTR_ERR(drm);
tdev->drm = drm;
drm->dev_private = tdev;
drm_mode_config_init(drm);
drm->mode_config.funcs = &tinydrm_mode_config_funcs;
return 0;
}
static void tinydrm_fini(struct tinydrm_device *tdev)
{
drm_mode_config_cleanup(tdev->drm);
mutex_destroy(&tdev->dirty_lock);
tdev->drm->dev_private = NULL;
drm_dev_unref(tdev->drm);
}
static void devm_tinydrm_release(void *data)
{
tinydrm_fini(data);
}
int devm_tinydrm_init(struct device *parent, struct tinydrm_device *tdev,
const struct drm_framebuffer_funcs *fb_funcs,
struct drm_driver *driver)
{
int ret;
ret = tinydrm_init(parent, tdev, fb_funcs, driver);
if (ret)
return ret;
ret = devm_add_action(parent, devm_tinydrm_release, tdev);
if (ret)
tinydrm_fini(tdev);
return ret;
}
static int tinydrm_register(struct tinydrm_device *tdev)
{
struct drm_device *drm = tdev->drm;
int bpp = drm->mode_config.preferred_depth;
struct drm_fbdev_cma *fbdev;
int ret;
ret = drm_dev_register(tdev->drm, 0);
if (ret)
return ret;
fbdev = drm_fbdev_cma_init_with_funcs(drm, bpp ? bpp : 32,
drm->mode_config.num_connector,
tdev->fb_funcs);
if (IS_ERR(fbdev))
DRM_ERROR("Failed to initialize fbdev: %ld\n", PTR_ERR(fbdev));
else
tdev->fbdev_cma = fbdev;
return 0;
}
static void tinydrm_unregister(struct tinydrm_device *tdev)
{
struct drm_fbdev_cma *fbdev_cma = tdev->fbdev_cma;
drm_crtc_force_disable_all(tdev->drm);
tdev->fbdev_cma = NULL;
drm_dev_unregister(tdev->drm);
if (fbdev_cma)
drm_fbdev_cma_fini(fbdev_cma);
}
static void devm_tinydrm_register_release(void *data)
{
tinydrm_unregister(data);
}
int devm_tinydrm_register(struct tinydrm_device *tdev)
{
struct device *dev = tdev->drm->dev;
int ret;
ret = tinydrm_register(tdev);
if (ret)
return ret;
ret = devm_add_action(dev, devm_tinydrm_register_release, tdev);
if (ret)
tinydrm_unregister(tdev);
return ret;
}
void tinydrm_shutdown(struct tinydrm_device *tdev)
{
drm_crtc_force_disable_all(tdev->drm);
}
int tinydrm_suspend(struct tinydrm_device *tdev)
{
struct drm_atomic_state *state;
if (tdev->suspend_state) {
DRM_ERROR("Failed to suspend: state already set\n");
return -EINVAL;
}
drm_fbdev_cma_set_suspend_unlocked(tdev->fbdev_cma, 1);
state = drm_atomic_helper_suspend(tdev->drm);
if (IS_ERR(state)) {
drm_fbdev_cma_set_suspend_unlocked(tdev->fbdev_cma, 0);
return PTR_ERR(state);
}
tdev->suspend_state = state;
return 0;
}
int tinydrm_resume(struct tinydrm_device *tdev)
{
struct drm_atomic_state *state = tdev->suspend_state;
int ret;
if (!state) {
DRM_ERROR("Failed to resume: state is not set\n");
return -EINVAL;
}
tdev->suspend_state = NULL;
ret = drm_atomic_helper_resume(tdev->drm, state);
if (ret) {
DRM_ERROR("Error resuming state: %d\n", ret);
return ret;
}
drm_fbdev_cma_set_suspend_unlocked(tdev->fbdev_cma, 0);
return 0;
}
