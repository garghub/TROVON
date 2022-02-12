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
cmd->body.format = srf->format;
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
if (res->func->destroy == vmw_gb_surface_destroy) {
(void) vmw_gb_surface_destroy(res);
return;
}
if (res->id != -1) {
cmd = vmw_fifo_reserve(dev_priv, vmw_surface_destroy_size());
if (unlikely(!cmd)) {
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
vmw_fifo_resource_dec(dev_priv);
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
if (unlikely(!cmd)) {
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
BUG_ON(!val_buf->bo);
submit_size = vmw_surface_dma_size(srf);
cmd = vmw_fifo_reserve(dev_priv, submit_size);
if (unlikely(!cmd)) {
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
if (unlikely(!cmd)) {
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
BUG_ON(!res_free);
if (!dev_priv->has_mob)
vmw_fifo_resource_inc(dev_priv);
ret = vmw_resource_init(dev_priv, res, true, res_free,
(dev_priv->has_mob) ? &vmw_gb_surface_func :
&vmw_legacy_surface_func);
if (unlikely(ret != 0)) {
if (!dev_priv->has_mob)
vmw_fifo_resource_dec(dev_priv);
res_free(res);
return ret;
}
INIT_LIST_HEAD(&srf->view_list);
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
if (user_srf->master)
drm_master_put(&user_srf->master);
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
if (user_srf->backup_base)
ttm_base_object_unref(&user_srf->backup_base);
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
int ret;
int i, j;
uint32_t cur_bo_offset;
struct drm_vmw_size *cur_size;
struct vmw_surface_offset *cur_offset;
uint32_t num_sizes;
uint32_t size;
const struct svga3d_surface_desc *desc;
if (unlikely(vmw_user_surface_size == 0))
vmw_user_surface_size = ttm_round_pot(sizeof(*user_srf)) +
128;
num_sizes = 0;
for (i = 0; i < DRM_VMW_MAX_SURFACE_FACES; ++i) {
if (req->mip_levels[i] > DRM_VMW_MAX_MIP_LEVELS)
return -EINVAL;
num_sizes += req->mip_levels[i];
}
if (num_sizes > DRM_VMW_MAX_SURFACE_FACES * DRM_VMW_MAX_MIP_LEVELS ||
num_sizes == 0)
return -EINVAL;
size = vmw_user_surface_size + 128 +
ttm_round_pot(num_sizes * sizeof(struct drm_vmw_size)) +
ttm_round_pot(num_sizes * sizeof(struct vmw_surface_offset));
desc = svga3dsurface_get_desc(req->format);
if (unlikely(desc->block_desc == SVGA3DBLOCKDESC_NONE)) {
DRM_ERROR("Invalid surface format for surface creation.\n");
DRM_ERROR("Format requested is: %d\n", req->format);
return -EINVAL;
}
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
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
if (unlikely(!user_srf)) {
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
srf->sizes = memdup_user((struct drm_vmw_size __user *)(unsigned long)
req->size_addr,
sizeof(*srf->sizes) * srf->num_sizes);
if (IS_ERR(srf->sizes)) {
ret = PTR_ERR(srf->sizes);
goto out_no_sizes;
}
srf->offsets = kmalloc_array(srf->num_sizes,
sizeof(*srf->offsets),
GFP_KERNEL);
if (unlikely(!srf->offsets)) {
ret = -ENOMEM;
goto out_no_offsets;
}
srf->base_size = *srf->sizes;
srf->autogen_filter = SVGA3D_TEX_FILTER_NONE;
srf->multisample_count = 0;
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
srf->snooper.image = kzalloc(64 * 64 * 4, GFP_KERNEL);
if (!srf->snooper.image) {
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
if (drm_is_primary_client(file_priv))
user_srf->master = drm_master_get(file_priv->master);
ret = vmw_surface_init(dev_priv, srf, vmw_user_surface_free);
if (unlikely(ret != 0))
goto out_unlock;
if (dev_priv->has_mob && req->shareable) {
uint32_t backup_handle;
ret = vmw_user_dmabuf_alloc(dev_priv, tfile,
res->backup_size,
true,
&backup_handle,
&res->backup,
&user_srf->backup_base);
if (unlikely(ret != 0)) {
vmw_resource_unreference(&res);
goto out_unlock;
}
}
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
ttm_read_unlock(&dev_priv->reservation_sem);
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
ttm_read_unlock(&dev_priv->reservation_sem);
return ret;
}
static int
vmw_surface_handle_reference(struct vmw_private *dev_priv,
struct drm_file *file_priv,
uint32_t u_handle,
enum drm_vmw_handle_type handle_type,
struct ttm_base_object **base_p)
{
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_user_surface *user_srf;
uint32_t handle;
struct ttm_base_object *base;
int ret;
bool require_exist = false;
if (handle_type == DRM_VMW_HANDLE_PRIME) {
ret = ttm_prime_fd_to_handle(tfile, u_handle, &handle);
if (unlikely(ret != 0))
return ret;
} else {
if (unlikely(drm_is_render_client(file_priv)))
require_exist = true;
if (ACCESS_ONCE(vmw_fpriv(file_priv)->locked_master)) {
DRM_ERROR("Locked master refused legacy "
"surface reference.\n");
return -EACCES;
}
handle = u_handle;
}
ret = -EINVAL;
base = ttm_base_object_lookup_for_ref(dev_priv->tdev, handle);
if (unlikely(!base)) {
DRM_ERROR("Could not find surface to reference.\n");
goto out_no_lookup;
}
if (unlikely(ttm_base_object_type(base) != VMW_RES_SURFACE)) {
DRM_ERROR("Referenced object is not a surface.\n");
goto out_bad_resource;
}
if (handle_type != DRM_VMW_HANDLE_PRIME) {
user_srf = container_of(base, struct vmw_user_surface,
prime.base);
if (drm_is_primary_client(file_priv) &&
user_srf->master != file_priv->master)
require_exist = true;
ret = ttm_ref_object_add(tfile, base, TTM_REF_USAGE, NULL,
require_exist);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not add a reference to a surface.\n");
goto out_bad_resource;
}
}
*base_p = base;
return 0;
out_bad_resource:
ttm_base_object_unref(&base);
out_no_lookup:
if (handle_type == DRM_VMW_HANDLE_PRIME)
(void) ttm_ref_object_base_unref(tfile, handle, TTM_REF_USAGE);
return ret;
}
int vmw_surface_reference_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
union drm_vmw_surface_reference_arg *arg =
(union drm_vmw_surface_reference_arg *)data;
struct drm_vmw_surface_arg *req = &arg->req;
struct drm_vmw_surface_create_req *rep = &arg->rep;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_surface *srf;
struct vmw_user_surface *user_srf;
struct drm_vmw_size __user *user_sizes;
struct ttm_base_object *base;
int ret;
ret = vmw_surface_handle_reference(dev_priv, file_priv, req->sid,
req->handle_type, &base);
if (unlikely(ret != 0))
return ret;
user_srf = container_of(base, struct vmw_user_surface, prime.base);
srf = &user_srf->srf;
rep->flags = srf->flags;
rep->format = srf->format;
memcpy(rep->mip_levels, srf->mip_levels, sizeof(srf->mip_levels));
user_sizes = (struct drm_vmw_size __user *)(unsigned long)
rep->size_addr;
if (user_sizes)
ret = copy_to_user(user_sizes, &srf->base_size,
sizeof(srf->base_size));
if (unlikely(ret != 0)) {
DRM_ERROR("copy_to_user failed %p %u\n",
user_sizes, srf->num_sizes);
ttm_ref_object_base_unref(tfile, base->hash.key, TTM_REF_USAGE);
ret = -EFAULT;
}
ttm_base_object_unref(&base);
return ret;
}
static int vmw_gb_surface_create(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_surface *srf = vmw_res_to_srf(res);
uint32_t cmd_len, cmd_id, submit_len;
int ret;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDefineGBSurface body;
} *cmd;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDefineGBSurface_v2 body;
} *cmd2;
if (likely(res->id != -1))
return 0;
vmw_fifo_resource_inc(dev_priv);
ret = vmw_resource_alloc_id(res);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to allocate a surface id.\n");
goto out_no_id;
}
if (unlikely(res->id >= VMWGFX_NUM_GB_SURFACE)) {
ret = -EBUSY;
goto out_no_fifo;
}
if (srf->array_size > 0) {
cmd_id = SVGA_3D_CMD_DEFINE_GB_SURFACE_V2;
cmd_len = sizeof(cmd2->body);
submit_len = sizeof(*cmd2);
} else {
cmd_id = SVGA_3D_CMD_DEFINE_GB_SURFACE;
cmd_len = sizeof(cmd->body);
submit_len = sizeof(*cmd);
}
cmd = vmw_fifo_reserve(dev_priv, submit_len);
cmd2 = (typeof(cmd2))cmd;
if (unlikely(!cmd)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"creation.\n");
ret = -ENOMEM;
goto out_no_fifo;
}
if (srf->array_size > 0) {
cmd2->header.id = cmd_id;
cmd2->header.size = cmd_len;
cmd2->body.sid = srf->res.id;
cmd2->body.surfaceFlags = srf->flags;
cmd2->body.format = cpu_to_le32(srf->format);
cmd2->body.numMipLevels = srf->mip_levels[0];
cmd2->body.multisampleCount = srf->multisample_count;
cmd2->body.autogenFilter = srf->autogen_filter;
cmd2->body.size.width = srf->base_size.width;
cmd2->body.size.height = srf->base_size.height;
cmd2->body.size.depth = srf->base_size.depth;
cmd2->body.arraySize = srf->array_size;
} else {
cmd->header.id = cmd_id;
cmd->header.size = cmd_len;
cmd->body.sid = srf->res.id;
cmd->body.surfaceFlags = srf->flags;
cmd->body.format = cpu_to_le32(srf->format);
cmd->body.numMipLevels = srf->mip_levels[0];
cmd->body.multisampleCount = srf->multisample_count;
cmd->body.autogenFilter = srf->autogen_filter;
cmd->body.size.width = srf->base_size.width;
cmd->body.size.height = srf->base_size.height;
cmd->body.size.depth = srf->base_size.depth;
}
vmw_fifo_commit(dev_priv, submit_len);
return 0;
out_no_fifo:
vmw_resource_release_id(res);
out_no_id:
vmw_fifo_resource_dec(dev_priv);
return ret;
}
static int vmw_gb_surface_bind(struct vmw_resource *res,
struct ttm_validate_buffer *val_buf)
{
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdBindGBSurface body;
} *cmd1;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdUpdateGBSurface body;
} *cmd2;
uint32_t submit_size;
struct ttm_buffer_object *bo = val_buf->bo;
BUG_ON(bo->mem.mem_type != VMW_PL_MOB);
submit_size = sizeof(*cmd1) + (res->backup_dirty ? sizeof(*cmd2) : 0);
cmd1 = vmw_fifo_reserve(dev_priv, submit_size);
if (unlikely(!cmd1)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"binding.\n");
return -ENOMEM;
}
cmd1->header.id = SVGA_3D_CMD_BIND_GB_SURFACE;
cmd1->header.size = sizeof(cmd1->body);
cmd1->body.sid = res->id;
cmd1->body.mobid = bo->mem.start;
if (res->backup_dirty) {
cmd2 = (void *) &cmd1[1];
cmd2->header.id = SVGA_3D_CMD_UPDATE_GB_SURFACE;
cmd2->header.size = sizeof(cmd2->body);
cmd2->body.sid = res->id;
res->backup_dirty = false;
}
vmw_fifo_commit(dev_priv, submit_size);
return 0;
}
static int vmw_gb_surface_unbind(struct vmw_resource *res,
bool readback,
struct ttm_validate_buffer *val_buf)
{
struct vmw_private *dev_priv = res->dev_priv;
struct ttm_buffer_object *bo = val_buf->bo;
struct vmw_fence_obj *fence;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdReadbackGBSurface body;
} *cmd1;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdInvalidateGBSurface body;
} *cmd2;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdBindGBSurface body;
} *cmd3;
uint32_t submit_size;
uint8_t *cmd;
BUG_ON(bo->mem.mem_type != VMW_PL_MOB);
submit_size = sizeof(*cmd3) + (readback ? sizeof(*cmd1) : sizeof(*cmd2));
cmd = vmw_fifo_reserve(dev_priv, submit_size);
if (unlikely(!cmd)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"unbinding.\n");
return -ENOMEM;
}
if (readback) {
cmd1 = (void *) cmd;
cmd1->header.id = SVGA_3D_CMD_READBACK_GB_SURFACE;
cmd1->header.size = sizeof(cmd1->body);
cmd1->body.sid = res->id;
cmd3 = (void *) &cmd1[1];
} else {
cmd2 = (void *) cmd;
cmd2->header.id = SVGA_3D_CMD_INVALIDATE_GB_SURFACE;
cmd2->header.size = sizeof(cmd2->body);
cmd2->body.sid = res->id;
cmd3 = (void *) &cmd2[1];
}
cmd3->header.id = SVGA_3D_CMD_BIND_GB_SURFACE;
cmd3->header.size = sizeof(cmd3->body);
cmd3->body.sid = res->id;
cmd3->body.mobid = SVGA3D_INVALID_ID;
vmw_fifo_commit(dev_priv, submit_size);
(void) vmw_execbuf_fence_commands(NULL, dev_priv,
&fence, NULL);
vmw_fence_single_bo(val_buf->bo, fence);
if (likely(fence != NULL))
vmw_fence_obj_unreference(&fence);
return 0;
}
static int vmw_gb_surface_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_surface *srf = vmw_res_to_srf(res);
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDestroyGBSurface body;
} *cmd;
if (likely(res->id == -1))
return 0;
mutex_lock(&dev_priv->binding_mutex);
vmw_view_surface_list_destroy(dev_priv, &srf->view_list);
vmw_binding_res_list_scrub(&res->binding_head);
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(!cmd)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"destruction.\n");
mutex_unlock(&dev_priv->binding_mutex);
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DESTROY_GB_SURFACE;
cmd->header.size = sizeof(cmd->body);
cmd->body.sid = res->id;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
mutex_unlock(&dev_priv->binding_mutex);
vmw_resource_release_id(res);
vmw_fifo_resource_dec(dev_priv);
return 0;
}
int vmw_gb_surface_define_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_user_surface *user_srf;
struct vmw_surface *srf;
struct vmw_resource *res;
struct vmw_resource *tmp;
union drm_vmw_gb_surface_create_arg *arg =
(union drm_vmw_gb_surface_create_arg *)data;
struct drm_vmw_gb_surface_create_req *req = &arg->req;
struct drm_vmw_gb_surface_create_rep *rep = &arg->rep;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
int ret;
uint32_t size;
uint32_t backup_handle;
if (req->multisample_count != 0)
return -EINVAL;
if (unlikely(vmw_user_surface_size == 0))
vmw_user_surface_size = ttm_round_pot(sizeof(*user_srf)) +
128;
size = vmw_user_surface_size + 128;
ret = vmw_surface_gb_priv_define(dev,
size,
req->svga3d_flags,
req->format,
req->drm_surface_flags & drm_vmw_surface_flag_scanout,
req->mip_levels,
req->multisample_count,
req->array_size,
req->base_size,
&srf);
if (unlikely(ret != 0))
return ret;
user_srf = container_of(srf, struct vmw_user_surface, srf);
if (drm_is_primary_client(file_priv))
user_srf->master = drm_master_get(file_priv->master);
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
return ret;
res = &user_srf->srf.res;
if (req->buffer_handle != SVGA3D_INVALID_ID) {
ret = vmw_user_dmabuf_lookup(tfile, req->buffer_handle,
&res->backup,
&user_srf->backup_base);
if (ret == 0 && res->backup->base.num_pages * PAGE_SIZE <
res->backup_size) {
DRM_ERROR("Surface backup buffer is too small.\n");
vmw_dmabuf_unreference(&res->backup);
ret = -EINVAL;
goto out_unlock;
}
} else if (req->drm_surface_flags & drm_vmw_surface_flag_create_buffer)
ret = vmw_user_dmabuf_alloc(dev_priv, tfile,
res->backup_size,
req->drm_surface_flags &
drm_vmw_surface_flag_shareable,
&backup_handle,
&res->backup,
&user_srf->backup_base);
if (unlikely(ret != 0)) {
vmw_resource_unreference(&res);
goto out_unlock;
}
tmp = vmw_resource_reference(res);
ret = ttm_prime_object_init(tfile, res->backup_size, &user_srf->prime,
req->drm_surface_flags &
drm_vmw_surface_flag_shareable,
VMW_RES_SURFACE,
&vmw_user_surface_base_release, NULL);
if (unlikely(ret != 0)) {
vmw_resource_unreference(&tmp);
vmw_resource_unreference(&res);
goto out_unlock;
}
rep->handle = user_srf->prime.base.hash.key;
rep->backup_size = res->backup_size;
if (res->backup) {
rep->buffer_map_handle =
drm_vma_node_offset_addr(&res->backup->base.vma_node);
rep->buffer_size = res->backup->base.num_pages * PAGE_SIZE;
rep->buffer_handle = backup_handle;
} else {
rep->buffer_map_handle = 0;
rep->buffer_size = 0;
rep->buffer_handle = SVGA3D_INVALID_ID;
}
vmw_resource_unreference(&res);
out_unlock:
ttm_read_unlock(&dev_priv->reservation_sem);
return ret;
}
int vmw_gb_surface_reference_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
union drm_vmw_gb_surface_reference_arg *arg =
(union drm_vmw_gb_surface_reference_arg *)data;
struct drm_vmw_surface_arg *req = &arg->req;
struct drm_vmw_gb_surface_ref_rep *rep = &arg->rep;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_surface *srf;
struct vmw_user_surface *user_srf;
struct ttm_base_object *base;
uint32_t backup_handle;
int ret = -EINVAL;
ret = vmw_surface_handle_reference(dev_priv, file_priv, req->sid,
req->handle_type, &base);
if (unlikely(ret != 0))
return ret;
user_srf = container_of(base, struct vmw_user_surface, prime.base);
srf = &user_srf->srf;
if (!srf->res.backup) {
DRM_ERROR("Shared GB surface is missing a backup buffer.\n");
goto out_bad_resource;
}
mutex_lock(&dev_priv->cmdbuf_mutex);
ret = vmw_user_dmabuf_reference(tfile, srf->res.backup,
&backup_handle);
mutex_unlock(&dev_priv->cmdbuf_mutex);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not add a reference to a GB surface "
"backup buffer.\n");
(void) ttm_ref_object_base_unref(tfile, base->hash.key,
TTM_REF_USAGE);
goto out_bad_resource;
}
rep->creq.svga3d_flags = srf->flags;
rep->creq.format = srf->format;
rep->creq.mip_levels = srf->mip_levels[0];
rep->creq.drm_surface_flags = 0;
rep->creq.multisample_count = srf->multisample_count;
rep->creq.autogen_filter = srf->autogen_filter;
rep->creq.array_size = srf->array_size;
rep->creq.buffer_handle = backup_handle;
rep->creq.base_size = srf->base_size;
rep->crep.handle = user_srf->prime.base.hash.key;
rep->crep.backup_size = srf->res.backup_size;
rep->crep.buffer_handle = backup_handle;
rep->crep.buffer_map_handle =
drm_vma_node_offset_addr(&srf->res.backup->base.vma_node);
rep->crep.buffer_size = srf->res.backup->base.num_pages * PAGE_SIZE;
out_bad_resource:
ttm_base_object_unref(&base);
return ret;
}
int vmw_surface_gb_priv_define(struct drm_device *dev,
uint32_t user_accounting_size,
uint32_t svga3d_flags,
SVGA3dSurfaceFormat format,
bool for_scanout,
uint32_t num_mip_levels,
uint32_t multisample_count,
uint32_t array_size,
struct drm_vmw_size size,
struct vmw_surface **srf_out)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_user_surface *user_srf;
struct vmw_surface *srf;
int ret;
u32 num_layers;
*srf_out = NULL;
if (for_scanout) {
if (!svga3dsurface_is_screen_target_format(format)) {
DRM_ERROR("Invalid Screen Target surface format.");
return -EINVAL;
}
} else {
const struct svga3d_surface_desc *desc;
desc = svga3dsurface_get_desc(format);
if (unlikely(desc->block_desc == SVGA3DBLOCKDESC_NONE)) {
DRM_ERROR("Invalid surface format.\n");
return -EINVAL;
}
}
if (array_size > 0 && !dev_priv->has_dx) {
DRM_ERROR("Tried to create DX surface on non-DX host.\n");
return -EINVAL;
}
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
return ret;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv),
user_accounting_size, false, true);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Out of graphics memory for surface"
" creation.\n");
goto out_unlock;
}
user_srf = kzalloc(sizeof(*user_srf), GFP_KERNEL);
if (unlikely(!user_srf)) {
ret = -ENOMEM;
goto out_no_user_srf;
}
*srf_out = &user_srf->srf;
user_srf->size = user_accounting_size;
user_srf->prime.base.shareable = false;
user_srf->prime.base.tfile = NULL;
srf = &user_srf->srf;
srf->flags = svga3d_flags;
srf->format = format;
srf->scanout = for_scanout;
srf->mip_levels[0] = num_mip_levels;
srf->num_sizes = 1;
srf->sizes = NULL;
srf->offsets = NULL;
srf->base_size = size;
srf->autogen_filter = SVGA3D_TEX_FILTER_NONE;
srf->array_size = array_size;
srf->multisample_count = multisample_count;
if (array_size)
num_layers = array_size;
else if (svga3d_flags & SVGA3D_SURFACE_CUBEMAP)
num_layers = SVGA3D_MAX_SURFACE_FACES;
else
num_layers = 1;
srf->res.backup_size =
svga3dsurface_get_serialized_size(srf->format,
srf->base_size,
srf->mip_levels[0],
num_layers);
if (srf->flags & SVGA3D_SURFACE_BIND_STREAM_OUTPUT)
srf->res.backup_size += sizeof(SVGA3dDXSOState);
if (dev_priv->active_display_unit == vmw_du_screen_target &&
for_scanout)
srf->flags |= SVGA3D_SURFACE_SCREENTARGET;
ret = vmw_surface_init(dev_priv, srf, vmw_user_surface_free);
ttm_read_unlock(&dev_priv->reservation_sem);
return ret;
out_no_user_srf:
ttm_mem_global_free(vmw_mem_glob(dev_priv), user_accounting_size);
out_unlock:
ttm_read_unlock(&dev_priv->reservation_sem);
return ret;
}
