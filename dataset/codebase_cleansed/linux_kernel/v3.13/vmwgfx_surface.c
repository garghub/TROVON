static inline uint32_t vmw_surface_dma_size(const struct vmw_surface *srf)
{
return srf->num_sizes * sizeof(struct vmw_surface_dma);
}
static inline uint32_t vmw_surface_define_size(const struct vmw_surface *srf)
{
return sizeof(struct vmw_surface_define) + srf->num_sizes *
sizeof(SVGA3dSize);
}
static inline uint32_t vmw_surface_destroy_size(void)
{
return sizeof(struct vmw_surface_destroy);
}
static void vmw_surface_destroy_encode(uint32_t id,
void *cmd_space)
{
struct vmw_surface_destroy *cmd = (struct vmw_surface_destroy *)
cmd_space;
cmd->header.id = SVGA_3D_CMD_SURFACE_DESTROY;
cmd->header.size = sizeof(cmd->body);
cmd->body.sid = id;
}
static void vmw_surface_define_encode(const struct vmw_surface *srf,
void *cmd_space)
{
struct vmw_surface_define *cmd = (struct vmw_surface_define *)
cmd_space;
struct drm_vmw_size *src_size;
SVGA3dSize *cmd_size;
uint32_t cmd_len;
int i;
cmd_len = sizeof(cmd->body) + srf->num_sizes * sizeof(SVGA3dSize);
cmd->header.id = SVGA_3D_CMD_SURFACE_DEFINE;
cmd->header.size = cmd_len;
cmd->body.sid = srf->res.id;
cmd->body.surfaceFlags = srf->flags;
cmd->body.format = cpu_to_le32(srf->format);
for (i = 0; i < DRM_VMW_MAX_SURFACE_FACES; ++i)
cmd->body.face[i].numMipLevels = srf->mip_levels[i];
cmd += 1;
cmd_size = (SVGA3dSize *) cmd;
src_size = srf->sizes;
for (i = 0; i < srf->num_sizes; ++i, cmd_size++, src_size++) {
cmd_size->width = src_size->width;
cmd_size->height = src_size->height;
cmd_size->depth = src_size->depth;
}
}
static void vmw_surface_dma_encode(struct vmw_surface *srf,
void *cmd_space,
const SVGAGuestPtr *ptr,
bool to_surface)
{
uint32_t i;
struct vmw_surface_dma *cmd = (struct vmw_surface_dma *)cmd_space;
const struct svga3d_surface_desc *desc =
svga3dsurface_get_desc(srf->format);
for (i = 0; i < srf->num_sizes; ++i) {
SVGA3dCmdHeader *header = &cmd->header;
SVGA3dCmdSurfaceDMA *body = &cmd->body;
SVGA3dCopyBox *cb = &cmd->cb;
SVGA3dCmdSurfaceDMASuffix *suffix = &cmd->suffix;
const struct vmw_surface_offset *cur_offset = &srf->offsets[i];
const struct drm_vmw_size *cur_size = &srf->sizes[i];
header->id = SVGA_3D_CMD_SURFACE_DMA;
header->size = sizeof(*body) + sizeof(*cb) + sizeof(*suffix);
body->guest.ptr = *ptr;
body->guest.ptr.offset += cur_offset->bo_offset;
body->guest.pitch = svga3dsurface_calculate_pitch(desc,
cur_size);
body->host.sid = srf->res.id;
body->host.face = cur_offset->face;
body->host.mipmap = cur_offset->mip;
body->transfer = ((to_surface) ? SVGA3D_WRITE_HOST_VRAM :
SVGA3D_READ_HOST_VRAM);
cb->x = 0;
cb->y = 0;
cb->z = 0;
cb->srcx = 0;
cb->srcy = 0;
cb->srcz = 0;
cb->w = cur_size->width;
cb->h = cur_size->height;
cb->d = cur_size->depth;
suffix->suffixSize = sizeof(*suffix);
suffix->maximumOffset =
svga3dsurface_get_image_buffer_size(desc, cur_size,
body->guest.pitch);
suffix->flags.discard = 0;
suffix->flags.unsynchronized = 0;
suffix->flags.reserved = 0;
++cmd;
}
}
static void vmw_hw_surface_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_surface *srf;
void *cmd;
if (res->id != -1) {
cmd = vmw_fifo_reserve(dev_priv, vmw_surface_destroy_size());
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"destruction.\n");
return;
}
vmw_surface_destroy_encode(res->id, cmd);
vmw_fifo_commit(dev_priv, vmw_surface_destroy_size());
mutex_lock(&dev_priv->cmdbuf_mutex);
srf = vmw_res_to_srf(res);
dev_priv->used_memory_size -= res->backup_size;
mutex_unlock(&dev_priv->cmdbuf_mutex);
}
vmw_3d_resource_dec(dev_priv, false);
}
static int vmw_legacy_srf_create(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_surface *srf;
uint32_t submit_size;
uint8_t *cmd;
int ret;
if (likely(res->id != -1))
return 0;
srf = vmw_res_to_srf(res);
if (unlikely(dev_priv->used_memory_size + res->backup_size >=
dev_priv->memory_size))
return -EBUSY;
ret = vmw_resource_alloc_id(res);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to allocate a surface id.\n");
goto out_no_id;
}
if (unlikely(res->id >= SVGA3D_MAX_SURFACE_IDS)) {
ret = -EBUSY;
goto out_no_fifo;
}
submit_size = vmw_surface_define_size(srf);
cmd = vmw_fifo_reserve(dev_priv, submit_size);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"creation.\n");
ret = -ENOMEM;
goto out_no_fifo;
}
vmw_surface_define_encode(srf, cmd);
vmw_fifo_commit(dev_priv, submit_size);
dev_priv->used_memory_size += res->backup_size;
return 0;
out_no_fifo:
vmw_resource_release_id(res);
out_no_id:
return ret;
}
static int vmw_legacy_srf_dma(struct vmw_resource *res,
struct ttm_validate_buffer *val_buf,
bool bind)
{
SVGAGuestPtr ptr;
struct vmw_fence_obj *fence;
uint32_t submit_size;
struct vmw_surface *srf = vmw_res_to_srf(res);
uint8_t *cmd;
struct vmw_private *dev_priv = res->dev_priv;
BUG_ON(val_buf->bo == NULL);
submit_size = vmw_surface_dma_size(srf);
cmd = vmw_fifo_reserve(dev_priv, submit_size);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"DMA.\n");
return -ENOMEM;
}
vmw_bo_get_guest_ptr(val_buf->bo, &ptr);
vmw_surface_dma_encode(srf, cmd, &ptr, bind);
vmw_fifo_commit(dev_priv, submit_size);
(void) vmw_execbuf_fence_commands(NULL, dev_priv,
&fence, NULL);
vmw_fence_single_bo(val_buf->bo, fence);
if (likely(fence != NULL))
vmw_fence_obj_unreference(&fence);
return 0;
}
static int vmw_legacy_srf_bind(struct vmw_resource *res,
struct ttm_validate_buffer *val_buf)
{
if (!res->backup_dirty)
return 0;
return vmw_legacy_srf_dma(res, val_buf, true);
}
static int vmw_legacy_srf_unbind(struct vmw_resource *res,
bool readback,
struct ttm_validate_buffer *val_buf)
{
if (unlikely(readback))
return vmw_legacy_srf_dma(res, val_buf, false);
return 0;
}
static int vmw_legacy_srf_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
uint32_t submit_size;
uint8_t *cmd;
BUG_ON(res->id == -1);
submit_size = vmw_surface_destroy_size();
cmd = vmw_fifo_reserve(dev_priv, submit_size);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"eviction.\n");
return -ENOMEM;
}
vmw_surface_destroy_encode(res->id, cmd);
vmw_fifo_commit(dev_priv, submit_size);
dev_priv->used_memory_size -= res->backup_size;
vmw_resource_release_id(res);
return 0;
}
static int vmw_surface_init(struct vmw_private *dev_priv,
struct vmw_surface *srf,
void (*res_free) (struct vmw_resource *res))
{
int ret;
struct vmw_resource *res = &srf->res;
BUG_ON(res_free == NULL);
(void) vmw_3d_resource_inc(dev_priv, false);
ret = vmw_resource_init(dev_priv, res, true, res_free,
&vmw_legacy_surface_func);
if (unlikely(ret != 0)) {
vmw_3d_resource_dec(dev_priv, false);
res_free(res);
return ret;
}
vmw_resource_activate(res, vmw_hw_surface_destroy);
return ret;
}
static struct vmw_resource *
vmw_user_surface_base_to_res(struct ttm_base_object *base)
{
return &(container_of(base, struct vmw_user_surface,
prime.base)->srf.res);
}
static void vmw_user_surface_free(struct vmw_resource *res)
{
struct vmw_surface *srf = vmw_res_to_srf(res);
struct vmw_user_surface *user_srf =
container_of(srf, struct vmw_user_surface, srf);
struct vmw_private *dev_priv = srf->res.dev_priv;
uint32_t size = user_srf->size;
kfree(srf->offsets);
kfree(srf->sizes);
kfree(srf->snooper.image);
ttm_prime_object_kfree(user_srf, prime);
ttm_mem_global_free(vmw_mem_glob(dev_priv), size);
}
static void vmw_user_surface_base_release(struct ttm_base_object **p_base)
{
struct ttm_base_object *base = *p_base;
struct vmw_user_surface *user_srf =
container_of(base, struct vmw_user_surface, prime.base);
struct vmw_resource *res = &user_srf->srf.res;
*p_base = NULL;
vmw_resource_unreference(&res);
}
int vmw_surface_destroy_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_surface_arg *arg = (struct drm_vmw_surface_arg *)data;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
return ttm_ref_object_base_unref(tfile, arg->sid, TTM_REF_USAGE);
}
int vmw_surface_define_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_user_surface *user_srf;
struct vmw_surface *srf;
struct vmw_resource *res;
struct vmw_resource *tmp;
union drm_vmw_surface_create_arg *arg =
(union drm_vmw_surface_create_arg *)data;
struct drm_vmw_surface_create_req *req = &arg->req;
struct drm_vmw_surface_arg *rep = &arg->rep;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct drm_vmw_size __user *user_sizes;
int ret;
int i, j;
uint32_t cur_bo_offset;
struct drm_vmw_size *cur_size;
struct vmw_surface_offset *cur_offset;
uint32_t num_sizes;
uint32_t size;
struct vmw_master *vmaster = vmw_master(file_priv->master);
const struct svga3d_surface_desc *desc;
if (unlikely(vmw_user_surface_size == 0))
vmw_user_surface_size = ttm_round_pot(sizeof(*user_srf)) +
128;
num_sizes = 0;
for (i = 0; i < DRM_VMW_MAX_SURFACE_FACES; ++i)
num_sizes += req->mip_levels[i];
if (num_sizes > DRM_VMW_MAX_SURFACE_FACES *
DRM_VMW_MAX_MIP_LEVELS)
return -EINVAL;
size = vmw_user_surface_size + 128 +
ttm_round_pot(num_sizes * sizeof(struct drm_vmw_size)) +
ttm_round_pot(num_sizes * sizeof(struct vmw_surface_offset));
desc = svga3dsurface_get_desc(req->format);
if (unlikely(desc->block_desc == SVGA3DBLOCKDESC_NONE)) {
DRM_ERROR("Invalid surface format for surface creation.\n");
return -EINVAL;
}
ret = ttm_read_lock(&vmaster->lock, true);
if (unlikely(ret != 0))
return ret;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv),
size, false, true);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Out of graphics memory for surface"
" creation.\n");
goto out_unlock;
}
user_srf = kzalloc(sizeof(*user_srf), GFP_KERNEL);
if (unlikely(user_srf == NULL)) {
ret = -ENOMEM;
goto out_no_user_srf;
}
srf = &user_srf->srf;
res = &srf->res;
srf->flags = req->flags;
srf->format = req->format;
srf->scanout = req->scanout;
memcpy(srf->mip_levels, req->mip_levels, sizeof(srf->mip_levels));
srf->num_sizes = num_sizes;
user_srf->size = size;
srf->sizes = kmalloc(srf->num_sizes * sizeof(*srf->sizes), GFP_KERNEL);
if (unlikely(srf->sizes == NULL)) {
ret = -ENOMEM;
goto out_no_sizes;
}
srf->offsets = kmalloc(srf->num_sizes * sizeof(*srf->offsets),
GFP_KERNEL);
if (unlikely(srf->sizes == NULL)) {
ret = -ENOMEM;
goto out_no_offsets;
}
user_sizes = (struct drm_vmw_size __user *)(unsigned long)
req->size_addr;
ret = copy_from_user(srf->sizes, user_sizes,
srf->num_sizes * sizeof(*srf->sizes));
if (unlikely(ret != 0)) {
ret = -EFAULT;
goto out_no_copy;
}
srf->base_size = *srf->sizes;
srf->autogen_filter = SVGA3D_TEX_FILTER_NONE;
srf->multisample_count = 1;
cur_bo_offset = 0;
cur_offset = srf->offsets;
cur_size = srf->sizes;
for (i = 0; i < DRM_VMW_MAX_SURFACE_FACES; ++i) {
for (j = 0; j < srf->mip_levels[i]; ++j) {
uint32_t stride = svga3dsurface_calculate_pitch
(desc, cur_size);
cur_offset->face = i;
cur_offset->mip = j;
cur_offset->bo_offset = cur_bo_offset;
cur_bo_offset += svga3dsurface_get_image_buffer_size
(desc, cur_size, stride);
++cur_offset;
++cur_size;
}
}
res->backup_size = cur_bo_offset;
if (srf->scanout &&
srf->num_sizes == 1 &&
srf->sizes[0].width == 64 &&
srf->sizes[0].height == 64 &&
srf->format == SVGA3D_A8R8G8B8) {
srf->snooper.image = kmalloc(64 * 64 * 4, GFP_KERNEL);
if (srf->snooper.image) {
memset(srf->snooper.image, 0x00, 64 * 64 * 4);
} else {
DRM_ERROR("Failed to allocate cursor_image\n");
ret = -ENOMEM;
goto out_no_copy;
}
} else {
srf->snooper.image = NULL;
}
srf->snooper.crtc = NULL;
user_srf->prime.base.shareable = false;
user_srf->prime.base.tfile = NULL;
ret = vmw_surface_init(dev_priv, srf, vmw_user_surface_free);
if (unlikely(ret != 0))
goto out_unlock;
tmp = vmw_resource_reference(&srf->res);
ret = ttm_prime_object_init(tfile, res->backup_size, &user_srf->prime,
req->shareable, VMW_RES_SURFACE,
&vmw_user_surface_base_release, NULL);
if (unlikely(ret != 0)) {
vmw_resource_unreference(&tmp);
vmw_resource_unreference(&res);
goto out_unlock;
}
rep->sid = user_srf->prime.base.hash.key;
vmw_resource_unreference(&res);
ttm_read_unlock(&vmaster->lock);
return 0;
out_no_copy:
kfree(srf->offsets);
out_no_offsets:
kfree(srf->sizes);
out_no_sizes:
ttm_prime_object_kfree(user_srf, prime);
out_no_user_srf:
ttm_mem_global_free(vmw_mem_glob(dev_priv), size);
out_unlock:
ttm_read_unlock(&vmaster->lock);
return ret;
}
int vmw_surface_reference_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
union drm_vmw_surface_reference_arg *arg =
(union drm_vmw_surface_reference_arg *)data;
struct drm_vmw_surface_arg *req = &arg->req;
struct drm_vmw_surface_create_req *rep = &arg->rep;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_surface *srf;
struct vmw_user_surface *user_srf;
struct drm_vmw_size __user *user_sizes;
struct ttm_base_object *base;
int ret = -EINVAL;
base = ttm_base_object_lookup(tfile, req->sid);
if (unlikely(base == NULL)) {
DRM_ERROR("Could not find surface to reference.\n");
return -EINVAL;
}
if (unlikely(ttm_base_object_type(base) != VMW_RES_SURFACE))
goto out_bad_resource;
user_srf = container_of(base, struct vmw_user_surface, prime.base);
srf = &user_srf->srf;
ret = ttm_ref_object_add(tfile, &user_srf->prime.base,
TTM_REF_USAGE, NULL);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not add a reference to a surface.\n");
goto out_no_reference;
}
rep->flags = srf->flags;
rep->format = srf->format;
memcpy(rep->mip_levels, srf->mip_levels, sizeof(srf->mip_levels));
user_sizes = (struct drm_vmw_size __user *)(unsigned long)
rep->size_addr;
if (user_sizes)
ret = copy_to_user(user_sizes, srf->sizes,
srf->num_sizes * sizeof(*srf->sizes));
if (unlikely(ret != 0)) {
DRM_ERROR("copy_to_user failed %p %u\n",
user_sizes, srf->num_sizes);
ret = -EFAULT;
}
out_bad_resource:
out_no_reference:
ttm_base_object_unref(&base);
return ret;
}
