static void udlfb_dpy_deferred_io(struct fb_info *info,
struct list_head *pagelist)
{
struct page *cur;
struct fb_deferred_io *fbdefio = info->fbdefio;
struct udl_fbdev *ufbdev = info->par;
struct drm_device *dev = ufbdev->ufb.base.dev;
struct udl_device *udl = dev->dev_private;
struct urb *urb;
char *cmd;
cycles_t start_cycles, end_cycles;
int bytes_sent = 0;
int bytes_identical = 0;
int bytes_rendered = 0;
if (!fb_defio)
return;
start_cycles = get_cycles();
urb = udl_get_urb(dev);
if (!urb)
return;
cmd = urb->transfer_buffer;
list_for_each_entry(cur, &fbdefio->pagelist, lru) {
if (udl_render_hline(dev, (ufbdev->ufb.base.bits_per_pixel / 8),
&urb, (char *) info->fix.smem_start,
&cmd, cur->index << PAGE_SHIFT,
cur->index << PAGE_SHIFT,
PAGE_SIZE, &bytes_identical, &bytes_sent))
goto error;
bytes_rendered += PAGE_SIZE;
}
if (cmd > (char *) urb->transfer_buffer) {
int len = cmd - (char *) urb->transfer_buffer;
udl_submit_urb(dev, urb, len);
bytes_sent += len;
} else
udl_urb_completion(urb);
error:
atomic_add(bytes_sent, &udl->bytes_sent);
atomic_add(bytes_identical, &udl->bytes_identical);
atomic_add(bytes_rendered, &udl->bytes_rendered);
end_cycles = get_cycles();
atomic_add(((unsigned int) ((end_cycles - start_cycles)
>> 10)),
&udl->cpu_kcycles_used);
}
int udl_handle_damage(struct udl_framebuffer *fb, int x, int y,
int width, int height)
{
struct drm_device *dev = fb->base.dev;
struct udl_device *udl = dev->dev_private;
int i, ret;
char *cmd;
cycles_t start_cycles, end_cycles;
int bytes_sent = 0;
int bytes_identical = 0;
struct urb *urb;
int aligned_x;
int bpp = (fb->base.bits_per_pixel / 8);
int x2, y2;
bool store_for_later = false;
unsigned long flags;
if (!fb->active_16)
return 0;
if (!fb->obj->vmapping) {
ret = udl_gem_vmap(fb->obj);
if (ret == -ENOMEM) {
DRM_ERROR("failed to vmap fb\n");
return 0;
}
if (!fb->obj->vmapping) {
DRM_ERROR("failed to vmapping\n");
return 0;
}
}
aligned_x = DL_ALIGN_DOWN(x, sizeof(unsigned long));
width = DL_ALIGN_UP(width + (x-aligned_x), sizeof(unsigned long));
x = aligned_x;
if ((width <= 0) ||
(x + width > fb->base.width) ||
(y + height > fb->base.height))
return -EINVAL;
if (in_atomic())
store_for_later = true;
x2 = x + width - 1;
y2 = y + height - 1;
spin_lock_irqsave(&fb->dirty_lock, flags);
if (fb->y1 < y)
y = fb->y1;
if (fb->y2 > y2)
y2 = fb->y2;
if (fb->x1 < x)
x = fb->x1;
if (fb->x2 > x2)
x2 = fb->x2;
if (store_for_later) {
fb->x1 = x;
fb->x2 = x2;
fb->y1 = y;
fb->y2 = y2;
spin_unlock_irqrestore(&fb->dirty_lock, flags);
return 0;
}
fb->x1 = fb->y1 = INT_MAX;
fb->x2 = fb->y2 = 0;
spin_unlock_irqrestore(&fb->dirty_lock, flags);
start_cycles = get_cycles();
urb = udl_get_urb(dev);
if (!urb)
return 0;
cmd = urb->transfer_buffer;
for (i = y; i <= y2 ; i++) {
const int line_offset = fb->base.pitches[0] * i;
const int byte_offset = line_offset + (x * bpp);
const int dev_byte_offset = (fb->base.width * bpp * i) + (x * bpp);
if (udl_render_hline(dev, bpp, &urb,
(char *) fb->obj->vmapping,
&cmd, byte_offset, dev_byte_offset,
(x2 - x + 1) * bpp,
&bytes_identical, &bytes_sent))
goto error;
}
if (cmd > (char *) urb->transfer_buffer) {
int len = cmd - (char *) urb->transfer_buffer;
ret = udl_submit_urb(dev, urb, len);
bytes_sent += len;
} else
udl_urb_completion(urb);
error:
atomic_add(bytes_sent, &udl->bytes_sent);
atomic_add(bytes_identical, &udl->bytes_identical);
atomic_add(width*height*bpp, &udl->bytes_rendered);
end_cycles = get_cycles();
atomic_add(((unsigned int) ((end_cycles - start_cycles)
>> 10)),
&udl->cpu_kcycles_used);
return 0;
}
static int udl_fb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
unsigned long start = vma->vm_start;
unsigned long size = vma->vm_end - vma->vm_start;
unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
unsigned long page, pos;
if (offset + size > info->fix.smem_len)
return -EINVAL;
pos = (unsigned long)info->fix.smem_start + offset;
pr_notice("mmap() framebuffer addr:%lu size:%lu\n",
pos, size);
while (size > 0) {
page = vmalloc_to_pfn((void *)pos);
if (remap_pfn_range(vma, start, page, PAGE_SIZE, PAGE_SHARED))
return -EAGAIN;
start += PAGE_SIZE;
pos += PAGE_SIZE;
if (size > PAGE_SIZE)
size -= PAGE_SIZE;
else
size = 0;
}
return 0;
}
static void udl_fb_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct udl_fbdev *ufbdev = info->par;
drm_fb_helper_sys_fillrect(info, rect);
udl_handle_damage(&ufbdev->ufb, rect->dx, rect->dy, rect->width,
rect->height);
}
static void udl_fb_copyarea(struct fb_info *info, const struct fb_copyarea *region)
{
struct udl_fbdev *ufbdev = info->par;
drm_fb_helper_sys_copyarea(info, region);
udl_handle_damage(&ufbdev->ufb, region->dx, region->dy, region->width,
region->height);
}
static void udl_fb_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct udl_fbdev *ufbdev = info->par;
drm_fb_helper_sys_imageblit(info, image);
udl_handle_damage(&ufbdev->ufb, image->dx, image->dy, image->width,
image->height);
}
static int udl_fb_open(struct fb_info *info, int user)
{
struct udl_fbdev *ufbdev = info->par;
struct drm_device *dev = ufbdev->ufb.base.dev;
struct udl_device *udl = dev->dev_private;
if (drm_device_is_unplugged(udl->ddev))
return -ENODEV;
ufbdev->fb_count++;
if (fb_defio && (info->fbdefio == NULL)) {
struct fb_deferred_io *fbdefio;
fbdefio = kmalloc(sizeof(struct fb_deferred_io), GFP_KERNEL);
if (fbdefio) {
fbdefio->delay = DL_DEFIO_WRITE_DELAY;
fbdefio->deferred_io = udlfb_dpy_deferred_io;
}
info->fbdefio = fbdefio;
fb_deferred_io_init(info);
}
pr_notice("open /dev/fb%d user=%d fb_info=%p count=%d\n",
info->node, user, info, ufbdev->fb_count);
return 0;
}
static int udl_fb_release(struct fb_info *info, int user)
{
struct udl_fbdev *ufbdev = info->par;
ufbdev->fb_count--;
if ((ufbdev->fb_count == 0) && (info->fbdefio)) {
fb_deferred_io_cleanup(info);
kfree(info->fbdefio);
info->fbdefio = NULL;
info->fbops->fb_mmap = udl_fb_mmap;
}
pr_warn("released /dev/fb%d user=%d count=%d\n",
info->node, user, ufbdev->fb_count);
return 0;
}
static int udl_user_framebuffer_dirty(struct drm_framebuffer *fb,
struct drm_file *file,
unsigned flags, unsigned color,
struct drm_clip_rect *clips,
unsigned num_clips)
{
struct udl_framebuffer *ufb = to_udl_fb(fb);
int i;
int ret = 0;
drm_modeset_lock_all(fb->dev);
if (!ufb->active_16)
goto unlock;
if (ufb->obj->base.import_attach) {
ret = dma_buf_begin_cpu_access(ufb->obj->base.import_attach->dmabuf,
0, ufb->obj->base.size,
DMA_FROM_DEVICE);
if (ret)
goto unlock;
}
for (i = 0; i < num_clips; i++) {
ret = udl_handle_damage(ufb, clips[i].x1, clips[i].y1,
clips[i].x2 - clips[i].x1,
clips[i].y2 - clips[i].y1);
if (ret)
break;
}
if (ufb->obj->base.import_attach) {
dma_buf_end_cpu_access(ufb->obj->base.import_attach->dmabuf,
0, ufb->obj->base.size,
DMA_FROM_DEVICE);
}
unlock:
drm_modeset_unlock_all(fb->dev);
return ret;
}
static void udl_user_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct udl_framebuffer *ufb = to_udl_fb(fb);
if (ufb->obj)
drm_gem_object_unreference_unlocked(&ufb->obj->base);
drm_framebuffer_cleanup(fb);
kfree(ufb);
}
static int
udl_framebuffer_init(struct drm_device *dev,
struct udl_framebuffer *ufb,
struct drm_mode_fb_cmd2 *mode_cmd,
struct udl_gem_object *obj)
{
int ret;
spin_lock_init(&ufb->dirty_lock);
ufb->obj = obj;
drm_helper_mode_fill_fb_struct(&ufb->base, mode_cmd);
ret = drm_framebuffer_init(dev, &ufb->base, &udlfb_funcs);
return ret;
}
static int udlfb_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct udl_fbdev *ufbdev =
container_of(helper, struct udl_fbdev, helper);
struct drm_device *dev = ufbdev->helper.dev;
struct fb_info *info;
struct drm_framebuffer *fb;
struct drm_mode_fb_cmd2 mode_cmd;
struct udl_gem_object *obj;
uint32_t size;
int ret = 0;
if (sizes->surface_bpp == 24)
sizes->surface_bpp = 32;
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] = mode_cmd.width * ((sizes->surface_bpp + 7) / 8);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
size = mode_cmd.pitches[0] * mode_cmd.height;
size = ALIGN(size, PAGE_SIZE);
obj = udl_gem_alloc_object(dev, size);
if (!obj)
goto out;
ret = udl_gem_vmap(obj);
if (ret) {
DRM_ERROR("failed to vmap fb\n");
goto out_gfree;
}
info = drm_fb_helper_alloc_fbi(helper);
if (IS_ERR(info)) {
ret = PTR_ERR(info);
goto out_gfree;
}
info->par = ufbdev;
ret = udl_framebuffer_init(dev, &ufbdev->ufb, &mode_cmd, obj);
if (ret)
goto out_destroy_fbi;
fb = &ufbdev->ufb.base;
ufbdev->helper.fb = fb;
strcpy(info->fix.id, "udldrmfb");
info->screen_base = ufbdev->ufb.obj->vmapping;
info->fix.smem_len = size;
info->fix.smem_start = (unsigned long)ufbdev->ufb.obj->vmapping;
info->flags = FBINFO_DEFAULT | FBINFO_CAN_FORCE_OUTPUT;
info->fbops = &udlfb_ops;
drm_fb_helper_fill_fix(info, fb->pitches[0], fb->depth);
drm_fb_helper_fill_var(info, &ufbdev->helper, sizes->fb_width, sizes->fb_height);
DRM_DEBUG_KMS("allocated %dx%d vmal %p\n",
fb->width, fb->height,
ufbdev->ufb.obj->vmapping);
return ret;
out_destroy_fbi:
drm_fb_helper_release_fbi(helper);
out_gfree:
drm_gem_object_unreference(&ufbdev->ufb.obj->base);
out:
return ret;
}
static void udl_fbdev_destroy(struct drm_device *dev,
struct udl_fbdev *ufbdev)
{
drm_fb_helper_unregister_fbi(&ufbdev->helper);
drm_fb_helper_release_fbi(&ufbdev->helper);
drm_fb_helper_fini(&ufbdev->helper);
drm_framebuffer_unregister_private(&ufbdev->ufb.base);
drm_framebuffer_cleanup(&ufbdev->ufb.base);
drm_gem_object_unreference_unlocked(&ufbdev->ufb.obj->base);
}
int udl_fbdev_init(struct drm_device *dev)
{
struct udl_device *udl = dev->dev_private;
int bpp_sel = fb_bpp;
struct udl_fbdev *ufbdev;
int ret;
ufbdev = kzalloc(sizeof(struct udl_fbdev), GFP_KERNEL);
if (!ufbdev)
return -ENOMEM;
udl->fbdev = ufbdev;
drm_fb_helper_prepare(dev, &ufbdev->helper, &udl_fb_helper_funcs);
ret = drm_fb_helper_init(dev, &ufbdev->helper,
1, 1);
if (ret)
goto free;
ret = drm_fb_helper_single_add_all_connectors(&ufbdev->helper);
if (ret)
goto fini;
drm_helper_disable_unused_functions(dev);
ret = drm_fb_helper_initial_config(&ufbdev->helper, bpp_sel);
if (ret)
goto fini;
return 0;
fini:
drm_fb_helper_fini(&ufbdev->helper);
free:
kfree(ufbdev);
return ret;
}
void udl_fbdev_cleanup(struct drm_device *dev)
{
struct udl_device *udl = dev->dev_private;
if (!udl->fbdev)
return;
udl_fbdev_destroy(dev, udl->fbdev);
kfree(udl->fbdev);
udl->fbdev = NULL;
}
void udl_fbdev_unplug(struct drm_device *dev)
{
struct udl_device *udl = dev->dev_private;
struct udl_fbdev *ufbdev;
if (!udl->fbdev)
return;
ufbdev = udl->fbdev;
drm_fb_helper_unlink_fbi(&ufbdev->helper);
}
struct drm_framebuffer *
udl_fb_user_fb_create(struct drm_device *dev,
struct drm_file *file,
struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *obj;
struct udl_framebuffer *ufb;
int ret;
uint32_t size;
obj = drm_gem_object_lookup(dev, file, mode_cmd->handles[0]);
if (obj == NULL)
return ERR_PTR(-ENOENT);
size = mode_cmd->pitches[0] * mode_cmd->height;
size = ALIGN(size, PAGE_SIZE);
if (size > obj->size) {
DRM_ERROR("object size not sufficient for fb %d %zu %d %d\n", size, obj->size, mode_cmd->pitches[0], mode_cmd->height);
return ERR_PTR(-ENOMEM);
}
ufb = kzalloc(sizeof(*ufb), GFP_KERNEL);
if (ufb == NULL)
return ERR_PTR(-ENOMEM);
ret = udl_framebuffer_init(dev, ufb, mode_cmd, to_udl_bo(obj));
if (ret) {
kfree(ufb);
return ERR_PTR(-EINVAL);
}
return &ufb->base;
}
