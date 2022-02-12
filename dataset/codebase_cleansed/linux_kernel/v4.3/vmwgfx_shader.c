static inline struct vmw_shader *
vmw_res_to_shader(struct vmw_resource *res)
{
return container_of(res, struct vmw_shader, res);
}
static inline struct vmw_dx_shader *
vmw_res_to_dx_shader(struct vmw_resource *res)
{
return container_of(res, struct vmw_dx_shader, res);
}
static void vmw_hw_shader_destroy(struct vmw_resource *res)
{
if (likely(res->func->destroy))
(void) res->func->destroy(res);
else
res->id = -1;
}
static int vmw_gb_shader_init(struct vmw_private *dev_priv,
struct vmw_resource *res,
uint32_t size,
uint64_t offset,
SVGA3dShaderType type,
uint8_t num_input_sig,
uint8_t num_output_sig,
struct vmw_dma_buffer *byte_code,
void (*res_free) (struct vmw_resource *res))
{
struct vmw_shader *shader = vmw_res_to_shader(res);
int ret;
ret = vmw_resource_init(dev_priv, res, true, res_free,
&vmw_gb_shader_func);
if (unlikely(ret != 0)) {
if (res_free)
res_free(res);
else
kfree(res);
return ret;
}
res->backup_size = size;
if (byte_code) {
res->backup = vmw_dmabuf_reference(byte_code);
res->backup_offset = offset;
}
shader->size = size;
shader->type = type;
shader->num_input_sig = num_input_sig;
shader->num_output_sig = num_output_sig;
vmw_resource_activate(res, vmw_hw_shader_destroy);
return 0;
}
static int vmw_gb_shader_create(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_shader *shader = vmw_res_to_shader(res);
int ret;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDefineGBShader body;
} *cmd;
if (likely(res->id != -1))
return 0;
ret = vmw_resource_alloc_id(res);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to allocate a shader id.\n");
goto out_no_id;
}
if (unlikely(res->id >= VMWGFX_NUM_GB_SHADER)) {
ret = -EBUSY;
goto out_no_fifo;
}
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for shader "
"creation.\n");
ret = -ENOMEM;
goto out_no_fifo;
}
cmd->header.id = SVGA_3D_CMD_DEFINE_GB_SHADER;
cmd->header.size = sizeof(cmd->body);
cmd->body.shid = res->id;
cmd->body.type = shader->type;
cmd->body.sizeInBytes = shader->size;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
vmw_fifo_resource_inc(dev_priv);
return 0;
out_no_fifo:
vmw_resource_release_id(res);
out_no_id:
return ret;
}
static int vmw_gb_shader_bind(struct vmw_resource *res,
struct ttm_validate_buffer *val_buf)
{
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdBindGBShader body;
} *cmd;
struct ttm_buffer_object *bo = val_buf->bo;
BUG_ON(bo->mem.mem_type != VMW_PL_MOB);
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for shader "
"binding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_BIND_GB_SHADER;
cmd->header.size = sizeof(cmd->body);
cmd->body.shid = res->id;
cmd->body.mobid = bo->mem.start;
cmd->body.offsetInBytes = res->backup_offset;
res->backup_dirty = false;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
}
static int vmw_gb_shader_unbind(struct vmw_resource *res,
bool readback,
struct ttm_validate_buffer *val_buf)
{
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdBindGBShader body;
} *cmd;
struct vmw_fence_obj *fence;
BUG_ON(res->backup->base.mem.mem_type != VMW_PL_MOB);
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for shader "
"unbinding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_BIND_GB_SHADER;
cmd->header.size = sizeof(cmd->body);
cmd->body.shid = res->id;
cmd->body.mobid = SVGA3D_INVALID_ID;
cmd->body.offsetInBytes = 0;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
(void) vmw_execbuf_fence_commands(NULL, dev_priv,
&fence, NULL);
vmw_fence_single_bo(val_buf->bo, fence);
if (likely(fence != NULL))
vmw_fence_obj_unreference(&fence);
return 0;
}
static int vmw_gb_shader_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDestroyGBShader body;
} *cmd;
if (likely(res->id == -1))
return 0;
mutex_lock(&dev_priv->binding_mutex);
vmw_binding_res_list_scrub(&res->binding_head);
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for shader "
"destruction.\n");
mutex_unlock(&dev_priv->binding_mutex);
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DESTROY_GB_SHADER;
cmd->header.size = sizeof(cmd->body);
cmd->body.shid = res->id;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
mutex_unlock(&dev_priv->binding_mutex);
vmw_resource_release_id(res);
vmw_fifo_resource_dec(dev_priv);
return 0;
}
static void vmw_dx_shader_commit_notify(struct vmw_resource *res,
enum vmw_cmdbuf_res_state state)
{
struct vmw_dx_shader *shader = vmw_res_to_dx_shader(res);
struct vmw_private *dev_priv = res->dev_priv;
if (state == VMW_CMDBUF_RES_ADD) {
mutex_lock(&dev_priv->binding_mutex);
vmw_cotable_add_resource(shader->cotable,
&shader->cotable_head);
shader->committed = true;
res->id = shader->id;
mutex_unlock(&dev_priv->binding_mutex);
} else {
mutex_lock(&dev_priv->binding_mutex);
list_del_init(&shader->cotable_head);
shader->committed = false;
res->id = -1;
mutex_unlock(&dev_priv->binding_mutex);
}
}
static int vmw_dx_shader_unscrub(struct vmw_resource *res)
{
struct vmw_dx_shader *shader = vmw_res_to_dx_shader(res);
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXBindShader body;
} *cmd;
if (!list_empty(&shader->cotable_head) || !shader->committed)
return 0;
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd),
shader->ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for shader "
"scrubbing.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_BIND_SHADER;
cmd->header.size = sizeof(cmd->body);
cmd->body.cid = shader->ctx->id;
cmd->body.shid = shader->id;
cmd->body.mobid = res->backup->base.mem.start;
cmd->body.offsetInBytes = res->backup_offset;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
vmw_cotable_add_resource(shader->cotable, &shader->cotable_head);
return 0;
}
static int vmw_dx_shader_create(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_dx_shader *shader = vmw_res_to_dx_shader(res);
int ret = 0;
WARN_ON_ONCE(!shader->committed);
if (!list_empty(&res->mob_head)) {
mutex_lock(&dev_priv->binding_mutex);
ret = vmw_dx_shader_unscrub(res);
mutex_unlock(&dev_priv->binding_mutex);
}
res->id = shader->id;
return ret;
}
static int vmw_dx_shader_bind(struct vmw_resource *res,
struct ttm_validate_buffer *val_buf)
{
struct vmw_private *dev_priv = res->dev_priv;
struct ttm_buffer_object *bo = val_buf->bo;
BUG_ON(bo->mem.mem_type != VMW_PL_MOB);
mutex_lock(&dev_priv->binding_mutex);
vmw_dx_shader_unscrub(res);
mutex_unlock(&dev_priv->binding_mutex);
return 0;
}
static int vmw_dx_shader_scrub(struct vmw_resource *res)
{
struct vmw_dx_shader *shader = vmw_res_to_dx_shader(res);
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXBindShader body;
} *cmd;
if (list_empty(&shader->cotable_head))
return 0;
WARN_ON_ONCE(!shader->committed);
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for shader "
"scrubbing.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_BIND_SHADER;
cmd->header.size = sizeof(cmd->body);
cmd->body.cid = shader->ctx->id;
cmd->body.shid = res->id;
cmd->body.mobid = SVGA3D_INVALID_ID;
cmd->body.offsetInBytes = 0;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
res->id = -1;
list_del_init(&shader->cotable_head);
return 0;
}
static int vmw_dx_shader_unbind(struct vmw_resource *res,
bool readback,
struct ttm_validate_buffer *val_buf)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_fence_obj *fence;
int ret;
BUG_ON(res->backup->base.mem.mem_type != VMW_PL_MOB);
mutex_lock(&dev_priv->binding_mutex);
ret = vmw_dx_shader_scrub(res);
mutex_unlock(&dev_priv->binding_mutex);
if (ret)
return ret;
(void) vmw_execbuf_fence_commands(NULL, dev_priv,
&fence, NULL);
vmw_fence_single_bo(val_buf->bo, fence);
if (likely(fence != NULL))
vmw_fence_obj_unreference(&fence);
return 0;
}
void vmw_dx_shader_cotable_list_scrub(struct vmw_private *dev_priv,
struct list_head *list,
bool readback)
{
struct vmw_dx_shader *entry, *next;
WARN_ON_ONCE(!mutex_is_locked(&dev_priv->binding_mutex));
list_for_each_entry_safe(entry, next, list, cotable_head) {
WARN_ON(vmw_dx_shader_scrub(&entry->res));
if (!readback)
entry->committed = false;
}
}
static void vmw_dx_shader_res_free(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_dx_shader *shader = vmw_res_to_dx_shader(res);
vmw_resource_unreference(&shader->cotable);
kfree(shader);
ttm_mem_global_free(vmw_mem_glob(dev_priv), vmw_shader_dx_size);
}
int vmw_dx_shader_add(struct vmw_cmdbuf_res_manager *man,
struct vmw_resource *ctx,
u32 user_key,
SVGA3dShaderType shader_type,
struct list_head *list)
{
struct vmw_dx_shader *shader;
struct vmw_resource *res;
struct vmw_private *dev_priv = ctx->dev_priv;
int ret;
if (!vmw_shader_dx_size)
vmw_shader_dx_size = ttm_round_pot(sizeof(*shader));
if (!vmw_shader_id_ok(user_key, shader_type))
return -EINVAL;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv), vmw_shader_dx_size,
false, true);
if (ret) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Out of graphics memory for shader "
"creation.\n");
return ret;
}
shader = kmalloc(sizeof(*shader), GFP_KERNEL);
if (!shader) {
ttm_mem_global_free(vmw_mem_glob(dev_priv), vmw_shader_dx_size);
return -ENOMEM;
}
res = &shader->res;
shader->ctx = ctx;
shader->cotable = vmw_context_cotable(ctx, SVGA_COTABLE_DXSHADER);
shader->id = user_key;
shader->committed = false;
INIT_LIST_HEAD(&shader->cotable_head);
ret = vmw_resource_init(dev_priv, res, true,
vmw_dx_shader_res_free, &vmw_dx_shader_func);
if (ret)
goto out_resource_init;
ret = vmw_cmdbuf_res_add(man, vmw_cmdbuf_res_shader,
vmw_shader_key(user_key, 0),
res, list);
if (ret)
goto out_resource_init;
res->id = shader->id;
vmw_resource_activate(res, vmw_hw_shader_destroy);
out_resource_init:
vmw_resource_unreference(&res);
return ret;
}
static struct vmw_resource *
vmw_user_shader_base_to_res(struct ttm_base_object *base)
{
return &(container_of(base, struct vmw_user_shader, base)->
shader.res);
}
static void vmw_user_shader_free(struct vmw_resource *res)
{
struct vmw_user_shader *ushader =
container_of(res, struct vmw_user_shader, shader.res);
struct vmw_private *dev_priv = res->dev_priv;
ttm_base_object_kfree(ushader, base);
ttm_mem_global_free(vmw_mem_glob(dev_priv),
vmw_user_shader_size);
}
static void vmw_shader_free(struct vmw_resource *res)
{
struct vmw_shader *shader = vmw_res_to_shader(res);
struct vmw_private *dev_priv = res->dev_priv;
kfree(shader);
ttm_mem_global_free(vmw_mem_glob(dev_priv),
vmw_shader_size);
}
static void vmw_user_shader_base_release(struct ttm_base_object **p_base)
{
struct ttm_base_object *base = *p_base;
struct vmw_resource *res = vmw_user_shader_base_to_res(base);
*p_base = NULL;
vmw_resource_unreference(&res);
}
int vmw_shader_destroy_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_shader_arg *arg = (struct drm_vmw_shader_arg *)data;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
return ttm_ref_object_base_unref(tfile, arg->handle,
TTM_REF_USAGE);
}
static int vmw_user_shader_alloc(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buffer,
size_t shader_size,
size_t offset,
SVGA3dShaderType shader_type,
uint8_t num_input_sig,
uint8_t num_output_sig,
struct ttm_object_file *tfile,
u32 *handle)
{
struct vmw_user_shader *ushader;
struct vmw_resource *res, *tmp;
int ret;
if (unlikely(vmw_user_shader_size == 0))
vmw_user_shader_size =
ttm_round_pot(sizeof(struct vmw_user_shader)) + 128;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv),
vmw_user_shader_size,
false, true);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Out of graphics memory for shader "
"creation.\n");
goto out;
}
ushader = kzalloc(sizeof(*ushader), GFP_KERNEL);
if (unlikely(ushader == NULL)) {
ttm_mem_global_free(vmw_mem_glob(dev_priv),
vmw_user_shader_size);
ret = -ENOMEM;
goto out;
}
res = &ushader->shader.res;
ushader->base.shareable = false;
ushader->base.tfile = NULL;
ret = vmw_gb_shader_init(dev_priv, res, shader_size,
offset, shader_type, num_input_sig,
num_output_sig, buffer,
vmw_user_shader_free);
if (unlikely(ret != 0))
goto out;
tmp = vmw_resource_reference(res);
ret = ttm_base_object_init(tfile, &ushader->base, false,
VMW_RES_SHADER,
&vmw_user_shader_base_release, NULL);
if (unlikely(ret != 0)) {
vmw_resource_unreference(&tmp);
goto out_err;
}
if (handle)
*handle = ushader->base.hash.key;
out_err:
vmw_resource_unreference(&res);
out:
return ret;
}
static struct vmw_resource *vmw_shader_alloc(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buffer,
size_t shader_size,
size_t offset,
SVGA3dShaderType shader_type)
{
struct vmw_shader *shader;
struct vmw_resource *res;
int ret;
if (unlikely(vmw_shader_size == 0))
vmw_shader_size =
ttm_round_pot(sizeof(struct vmw_shader)) + 128;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv),
vmw_shader_size,
false, true);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Out of graphics memory for shader "
"creation.\n");
goto out_err;
}
shader = kzalloc(sizeof(*shader), GFP_KERNEL);
if (unlikely(shader == NULL)) {
ttm_mem_global_free(vmw_mem_glob(dev_priv),
vmw_shader_size);
ret = -ENOMEM;
goto out_err;
}
res = &shader->res;
ret = vmw_gb_shader_init(dev_priv, res, shader_size,
offset, shader_type, 0, 0, buffer,
vmw_shader_free);
out_err:
return ret ? ERR_PTR(ret) : res;
}
static int vmw_shader_define(struct drm_device *dev, struct drm_file *file_priv,
enum drm_vmw_shader_type shader_type_drm,
u32 buffer_handle, size_t size, size_t offset,
uint8_t num_input_sig, uint8_t num_output_sig,
uint32_t *shader_handle)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_dma_buffer *buffer = NULL;
SVGA3dShaderType shader_type;
int ret;
if (buffer_handle != SVGA3D_INVALID_ID) {
ret = vmw_user_dmabuf_lookup(tfile, buffer_handle,
&buffer, NULL);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not find buffer for shader "
"creation.\n");
return ret;
}
if ((u64)buffer->base.num_pages * PAGE_SIZE <
(u64)size + (u64)offset) {
DRM_ERROR("Illegal buffer- or shader size.\n");
ret = -EINVAL;
goto out_bad_arg;
}
}
switch (shader_type_drm) {
case drm_vmw_shader_type_vs:
shader_type = SVGA3D_SHADERTYPE_VS;
break;
case drm_vmw_shader_type_ps:
shader_type = SVGA3D_SHADERTYPE_PS;
break;
default:
DRM_ERROR("Illegal shader type.\n");
ret = -EINVAL;
goto out_bad_arg;
}
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
goto out_bad_arg;
ret = vmw_user_shader_alloc(dev_priv, buffer, size, offset,
shader_type, num_input_sig,
num_output_sig, tfile, shader_handle);
ttm_read_unlock(&dev_priv->reservation_sem);
out_bad_arg:
vmw_dmabuf_unreference(&buffer);
return ret;
}
static bool vmw_shader_id_ok(u32 user_key, SVGA3dShaderType shader_type)
{
return user_key <= ((1 << 20) - 1) && (unsigned) shader_type < 16;
}
static u32 vmw_shader_key(u32 user_key, SVGA3dShaderType shader_type)
{
return user_key | (shader_type << 20);
}
int vmw_shader_remove(struct vmw_cmdbuf_res_manager *man,
u32 user_key, SVGA3dShaderType shader_type,
struct list_head *list)
{
struct vmw_resource *dummy;
if (!vmw_shader_id_ok(user_key, shader_type))
return -EINVAL;
return vmw_cmdbuf_res_remove(man, vmw_cmdbuf_res_shader,
vmw_shader_key(user_key, shader_type),
list, &dummy);
}
int vmw_compat_shader_add(struct vmw_private *dev_priv,
struct vmw_cmdbuf_res_manager *man,
u32 user_key, const void *bytecode,
SVGA3dShaderType shader_type,
size_t size,
struct list_head *list)
{
struct vmw_dma_buffer *buf;
struct ttm_bo_kmap_obj map;
bool is_iomem;
int ret;
struct vmw_resource *res;
if (!vmw_shader_id_ok(user_key, shader_type))
return -EINVAL;
buf = kzalloc(sizeof(*buf), GFP_KERNEL);
if (unlikely(buf == NULL))
return -ENOMEM;
ret = vmw_dmabuf_init(dev_priv, buf, size, &vmw_sys_ne_placement,
true, vmw_dmabuf_bo_free);
if (unlikely(ret != 0))
goto out;
ret = ttm_bo_reserve(&buf->base, false, true, false, NULL);
if (unlikely(ret != 0))
goto no_reserve;
ret = ttm_bo_kmap(&buf->base, 0, PAGE_ALIGN(size) >> PAGE_SHIFT,
&map);
if (unlikely(ret != 0)) {
ttm_bo_unreserve(&buf->base);
goto no_reserve;
}
memcpy(ttm_kmap_obj_virtual(&map, &is_iomem), bytecode, size);
WARN_ON(is_iomem);
ttm_bo_kunmap(&map);
ret = ttm_bo_validate(&buf->base, &vmw_sys_placement, false, true);
WARN_ON(ret != 0);
ttm_bo_unreserve(&buf->base);
res = vmw_shader_alloc(dev_priv, buf, size, 0, shader_type);
if (unlikely(ret != 0))
goto no_reserve;
ret = vmw_cmdbuf_res_add(man, vmw_cmdbuf_res_shader,
vmw_shader_key(user_key, shader_type),
res, list);
vmw_resource_unreference(&res);
no_reserve:
vmw_dmabuf_unreference(&buf);
out:
return ret;
}
struct vmw_resource *
vmw_shader_lookup(struct vmw_cmdbuf_res_manager *man,
u32 user_key,
SVGA3dShaderType shader_type)
{
if (!vmw_shader_id_ok(user_key, shader_type))
return ERR_PTR(-EINVAL);
return vmw_cmdbuf_res_lookup(man, vmw_cmdbuf_res_shader,
vmw_shader_key(user_key, shader_type));
}
int vmw_shader_define_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_shader_create_arg *arg =
(struct drm_vmw_shader_create_arg *)data;
return vmw_shader_define(dev, file_priv, arg->shader_type,
arg->buffer_handle,
arg->size, arg->offset,
0, 0,
&arg->shader_handle);
}
