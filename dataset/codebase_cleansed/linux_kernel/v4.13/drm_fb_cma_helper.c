static inline struct drm_fbdev_cma *to_fbdev_cma(struct drm_fb_helper *helper)
{
return container_of(helper, struct drm_fbdev_cma, fb_helper);
}
static inline struct drm_fb_cma *to_fb_cma(struct drm_framebuffer *fb)
{
return container_of(fb, struct drm_fb_cma, fb);
}
void drm_fb_cma_destroy(struct drm_framebuffer *fb)
{
struct drm_fb_cma *fb_cma = to_fb_cma(fb);
int i;
for (i = 0; i < 4; i++) {
if (fb_cma->obj[i])
drm_gem_object_put_unlocked(&fb_cma->obj[i]->base);
}
drm_framebuffer_cleanup(fb);
kfree(fb_cma);
}
int drm_fb_cma_create_handle(struct drm_framebuffer *fb,
struct drm_file *file_priv, unsigned int *handle)
{
struct drm_fb_cma *fb_cma = to_fb_cma(fb);
return drm_gem_handle_create(file_priv,
&fb_cma->obj[0]->base, handle);
}
static struct drm_fb_cma *drm_fb_cma_alloc(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_gem_cma_object **obj,
unsigned int num_planes, const struct drm_framebuffer_funcs *funcs)
{
struct drm_fb_cma *fb_cma;
int ret;
int i;
fb_cma = kzalloc(sizeof(*fb_cma), GFP_KERNEL);
if (!fb_cma)
return ERR_PTR(-ENOMEM);
drm_helper_mode_fill_fb_struct(dev, &fb_cma->fb, mode_cmd);
for (i = 0; i < num_planes; i++)
fb_cma->obj[i] = obj[i];
ret = drm_framebuffer_init(dev, &fb_cma->fb, funcs);
if (ret) {
dev_err(dev->dev, "Failed to initialize framebuffer: %d\n", ret);
kfree(fb_cma);
return ERR_PTR(ret);
}
return fb_cma;
}
struct drm_framebuffer *drm_fb_cma_create_with_funcs(struct drm_device *dev,
struct drm_file *file_priv, const struct drm_mode_fb_cmd2 *mode_cmd,
const struct drm_framebuffer_funcs *funcs)
{
const struct drm_format_info *info;
struct drm_fb_cma *fb_cma;
struct drm_gem_cma_object *objs[4];
struct drm_gem_object *obj;
int ret;
int i;
info = drm_get_format_info(dev, mode_cmd);
if (!info)
return ERR_PTR(-EINVAL);
for (i = 0; i < info->num_planes; i++) {
unsigned int width = mode_cmd->width / (i ? info->hsub : 1);
unsigned int height = mode_cmd->height / (i ? info->vsub : 1);
unsigned int min_size;
obj = drm_gem_object_lookup(file_priv, mode_cmd->handles[i]);
if (!obj) {
dev_err(dev->dev, "Failed to lookup GEM object\n");
ret = -ENOENT;
goto err_gem_object_put;
}
min_size = (height - 1) * mode_cmd->pitches[i]
+ width * info->cpp[i]
+ mode_cmd->offsets[i];
if (obj->size < min_size) {
drm_gem_object_put_unlocked(obj);
ret = -EINVAL;
goto err_gem_object_put;
}
objs[i] = to_drm_gem_cma_obj(obj);
}
fb_cma = drm_fb_cma_alloc(dev, mode_cmd, objs, i, funcs);
if (IS_ERR(fb_cma)) {
ret = PTR_ERR(fb_cma);
goto err_gem_object_put;
}
return &fb_cma->fb;
err_gem_object_put:
for (i--; i >= 0; i--)
drm_gem_object_put_unlocked(&objs[i]->base);
return ERR_PTR(ret);
}
struct drm_framebuffer *drm_fb_cma_create(struct drm_device *dev,
struct drm_file *file_priv, const struct drm_mode_fb_cmd2 *mode_cmd)
{
return drm_fb_cma_create_with_funcs(dev, file_priv, mode_cmd,
&drm_fb_cma_funcs);
}
struct drm_gem_cma_object *drm_fb_cma_get_gem_obj(struct drm_framebuffer *fb,
unsigned int plane)
{
struct drm_fb_cma *fb_cma = to_fb_cma(fb);
if (plane >= 4)
return NULL;
return fb_cma->obj[plane];
}
dma_addr_t drm_fb_cma_get_gem_addr(struct drm_framebuffer *fb,
struct drm_plane_state *state,
unsigned int plane)
{
struct drm_fb_cma *fb_cma = to_fb_cma(fb);
dma_addr_t paddr;
if (plane >= 4)
return 0;
paddr = fb_cma->obj[plane]->paddr + fb->offsets[plane];
paddr += fb->format->cpp[plane] * (state->src_x >> 16);
paddr += fb->pitches[plane] * (state->src_y >> 16);
return paddr;
}
int drm_fb_cma_prepare_fb(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct dma_buf *dma_buf;
struct dma_fence *fence;
if ((plane->state->fb == state->fb) || !state->fb)
return 0;
dma_buf = drm_fb_cma_get_gem_obj(state->fb, 0)->base.dma_buf;
if (dma_buf) {
fence = reservation_object_get_excl_rcu(dma_buf->resv);
drm_atomic_set_fence_for_plane(state, fence);
}
return 0;
}
static void drm_fb_cma_describe(struct drm_framebuffer *fb, struct seq_file *m)
{
struct drm_fb_cma *fb_cma = to_fb_cma(fb);
int i;
seq_printf(m, "fb: %dx%d@%4.4s\n", fb->width, fb->height,
(char *)&fb->format->format);
for (i = 0; i < fb->format->num_planes; i++) {
seq_printf(m, " %d: offset=%d pitch=%d, obj: ",
i, fb->offsets[i], fb->pitches[i]);
drm_gem_cma_describe(fb_cma->obj[i], m);
}
}
int drm_fb_cma_debugfs_show(struct seq_file *m, void *arg)
{
struct drm_info_node *node = (struct drm_info_node *) m->private;
struct drm_device *dev = node->minor->dev;
struct drm_framebuffer *fb;
mutex_lock(&dev->mode_config.fb_lock);
drm_for_each_fb(fb, dev)
drm_fb_cma_describe(fb, m);
mutex_unlock(&dev->mode_config.fb_lock);
return 0;
}
static int drm_fb_cma_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
return dma_mmap_writecombine(info->device, vma, info->screen_base,
info->fix.smem_start, info->fix.smem_len);
}
static int drm_fbdev_cma_deferred_io_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
fb_deferred_io_mmap(info, vma);
vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
return 0;
}
static int drm_fbdev_cma_defio_init(struct fb_info *fbi,
struct drm_gem_cma_object *cma_obj)
{
struct fb_deferred_io *fbdefio;
struct fb_ops *fbops;
fbdefio = kzalloc(sizeof(*fbdefio), GFP_KERNEL);
fbops = kzalloc(sizeof(*fbops), GFP_KERNEL);
if (!fbdefio || !fbops) {
kfree(fbdefio);
kfree(fbops);
return -ENOMEM;
}
fbi->screen_buffer = cma_obj->vaddr;
fbi->fix.smem_start = page_to_phys(virt_to_page(fbi->screen_buffer));
*fbops = *fbi->fbops;
fbi->fbops = fbops;
fbdefio->delay = msecs_to_jiffies(DEFAULT_FBDEFIO_DELAY_MS);
fbdefio->deferred_io = drm_fb_helper_deferred_io;
fbi->fbdefio = fbdefio;
fb_deferred_io_init(fbi);
fbi->fbops->fb_mmap = drm_fbdev_cma_deferred_io_mmap;
return 0;
}
static void drm_fbdev_cma_defio_fini(struct fb_info *fbi)
{
if (!fbi->fbdefio)
return;
fb_deferred_io_cleanup(fbi);
kfree(fbi->fbdefio);
kfree(fbi->fbops);
}
static int
drm_fbdev_cma_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct drm_fbdev_cma *fbdev_cma = to_fbdev_cma(helper);
struct drm_mode_fb_cmd2 mode_cmd = { 0 };
struct drm_device *dev = helper->dev;
struct drm_gem_cma_object *obj;
struct drm_framebuffer *fb;
unsigned int bytes_per_pixel;
unsigned long offset;
struct fb_info *fbi;
size_t size;
int ret;
DRM_DEBUG_KMS("surface width(%d), height(%d) and bpp(%d)\n",
sizes->surface_width, sizes->surface_height,
sizes->surface_bpp);
bytes_per_pixel = DIV_ROUND_UP(sizes->surface_bpp, 8);
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] = sizes->surface_width * bytes_per_pixel;
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
size = mode_cmd.pitches[0] * mode_cmd.height;
obj = drm_gem_cma_create(dev, size);
if (IS_ERR(obj))
return -ENOMEM;
fbi = drm_fb_helper_alloc_fbi(helper);
if (IS_ERR(fbi)) {
ret = PTR_ERR(fbi);
goto err_gem_free_object;
}
fbdev_cma->fb = drm_fb_cma_alloc(dev, &mode_cmd, &obj, 1,
fbdev_cma->fb_funcs);
if (IS_ERR(fbdev_cma->fb)) {
dev_err(dev->dev, "Failed to allocate DRM framebuffer.\n");
ret = PTR_ERR(fbdev_cma->fb);
goto err_fb_info_destroy;
}
fb = &fbdev_cma->fb->fb;
helper->fb = fb;
fbi->par = helper;
fbi->flags = FBINFO_FLAG_DEFAULT;
fbi->fbops = &drm_fbdev_cma_ops;
drm_fb_helper_fill_fix(fbi, fb->pitches[0], fb->format->depth);
drm_fb_helper_fill_var(fbi, helper, sizes->fb_width, sizes->fb_height);
offset = fbi->var.xoffset * bytes_per_pixel;
offset += fbi->var.yoffset * fb->pitches[0];
dev->mode_config.fb_base = (resource_size_t)obj->paddr;
fbi->screen_base = obj->vaddr + offset;
fbi->fix.smem_start = (unsigned long)(obj->paddr + offset);
fbi->screen_size = size;
fbi->fix.smem_len = size;
if (fbdev_cma->fb_funcs->dirty) {
ret = drm_fbdev_cma_defio_init(fbi, obj);
if (ret)
goto err_cma_destroy;
}
return 0;
err_cma_destroy:
drm_framebuffer_remove(&fbdev_cma->fb->fb);
err_fb_info_destroy:
drm_fb_helper_fini(helper);
err_gem_free_object:
drm_gem_object_put_unlocked(&obj->base);
return ret;
}
struct drm_fbdev_cma *drm_fbdev_cma_init_with_funcs(struct drm_device *dev,
unsigned int preferred_bpp, unsigned int max_conn_count,
const struct drm_framebuffer_funcs *funcs)
{
struct drm_fbdev_cma *fbdev_cma;
struct drm_fb_helper *helper;
int ret;
fbdev_cma = kzalloc(sizeof(*fbdev_cma), GFP_KERNEL);
if (!fbdev_cma) {
dev_err(dev->dev, "Failed to allocate drm fbdev.\n");
return ERR_PTR(-ENOMEM);
}
fbdev_cma->fb_funcs = funcs;
helper = &fbdev_cma->fb_helper;
drm_fb_helper_prepare(dev, helper, &drm_fb_cma_helper_funcs);
ret = drm_fb_helper_init(dev, helper, max_conn_count);
if (ret < 0) {
dev_err(dev->dev, "Failed to initialize drm fb helper.\n");
goto err_free;
}
ret = drm_fb_helper_single_add_all_connectors(helper);
if (ret < 0) {
dev_err(dev->dev, "Failed to add connectors.\n");
goto err_drm_fb_helper_fini;
}
ret = drm_fb_helper_initial_config(helper, preferred_bpp);
if (ret < 0) {
dev_err(dev->dev, "Failed to set initial hw configuration.\n");
goto err_drm_fb_helper_fini;
}
return fbdev_cma;
err_drm_fb_helper_fini:
drm_fb_helper_fini(helper);
err_free:
kfree(fbdev_cma);
return ERR_PTR(ret);
}
struct drm_fbdev_cma *drm_fbdev_cma_init(struct drm_device *dev,
unsigned int preferred_bpp, unsigned int max_conn_count)
{
return drm_fbdev_cma_init_with_funcs(dev, preferred_bpp,
max_conn_count,
&drm_fb_cma_funcs);
}
void drm_fbdev_cma_fini(struct drm_fbdev_cma *fbdev_cma)
{
drm_fb_helper_unregister_fbi(&fbdev_cma->fb_helper);
if (fbdev_cma->fb_helper.fbdev)
drm_fbdev_cma_defio_fini(fbdev_cma->fb_helper.fbdev);
if (fbdev_cma->fb)
drm_framebuffer_remove(&fbdev_cma->fb->fb);
drm_fb_helper_fini(&fbdev_cma->fb_helper);
kfree(fbdev_cma);
}
void drm_fbdev_cma_restore_mode(struct drm_fbdev_cma *fbdev_cma)
{
if (fbdev_cma)
drm_fb_helper_restore_fbdev_mode_unlocked(&fbdev_cma->fb_helper);
}
void drm_fbdev_cma_hotplug_event(struct drm_fbdev_cma *fbdev_cma)
{
if (fbdev_cma)
drm_fb_helper_hotplug_event(&fbdev_cma->fb_helper);
}
void drm_fbdev_cma_set_suspend(struct drm_fbdev_cma *fbdev_cma, int state)
{
if (fbdev_cma)
drm_fb_helper_set_suspend(&fbdev_cma->fb_helper, state);
}
void drm_fbdev_cma_set_suspend_unlocked(struct drm_fbdev_cma *fbdev_cma,
int state)
{
if (fbdev_cma)
drm_fb_helper_set_suspend_unlocked(&fbdev_cma->fb_helper,
state);
}
