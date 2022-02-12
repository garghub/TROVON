static void vmw_hw_context_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDestroyContext body;
} *cmd;
vmw_execbuf_release_pinned_bo(dev_priv);
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for surface "
"destruction.\n");
return;
}
cmd->header.id = cpu_to_le32(SVGA_3D_CMD_CONTEXT_DESTROY);
cmd->header.size = cpu_to_le32(sizeof(cmd->body));
cmd->body.cid = cpu_to_le32(res->id);
vmw_fifo_commit(dev_priv, sizeof(*cmd));
vmw_3d_resource_dec(dev_priv, false);
}
static int vmw_context_init(struct vmw_private *dev_priv,
struct vmw_resource *res,
void (*res_free) (struct vmw_resource *res))
{
int ret;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDefineContext body;
} *cmd;
ret = vmw_resource_init(dev_priv, res, false,
res_free, &vmw_legacy_context_func);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to allocate a resource id.\n");
goto out_early;
}
if (unlikely(res->id >= SVGA3D_MAX_CONTEXT_IDS)) {
DRM_ERROR("Out of hw context ids.\n");
vmw_resource_unreference(&res);
return -ENOMEM;
}
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Fifo reserve failed.\n");
vmw_resource_unreference(&res);
return -ENOMEM;
}
cmd->header.id = cpu_to_le32(SVGA_3D_CMD_CONTEXT_DEFINE);
cmd->header.size = cpu_to_le32(sizeof(cmd->body));
cmd->body.cid = cpu_to_le32(res->id);
vmw_fifo_commit(dev_priv, sizeof(*cmd));
(void) vmw_3d_resource_inc(dev_priv, false);
vmw_resource_activate(res, vmw_hw_context_destroy);
return 0;
out_early:
if (res_free == NULL)
kfree(res);
else
res_free(res);
return ret;
}
struct vmw_resource *vmw_context_alloc(struct vmw_private *dev_priv)
{
struct vmw_resource *res = kmalloc(sizeof(*res), GFP_KERNEL);
int ret;
if (unlikely(res == NULL))
return NULL;
ret = vmw_context_init(dev_priv, res, NULL);
return (ret == 0) ? res : NULL;
}
static struct vmw_resource *
vmw_user_context_base_to_res(struct ttm_base_object *base)
{
return &(container_of(base, struct vmw_user_context, base)->res);
}
static void vmw_user_context_free(struct vmw_resource *res)
{
struct vmw_user_context *ctx =
container_of(res, struct vmw_user_context, res);
struct vmw_private *dev_priv = res->dev_priv;
ttm_base_object_kfree(ctx, base);
ttm_mem_global_free(vmw_mem_glob(dev_priv),
vmw_user_context_size);
}
static void vmw_user_context_base_release(struct ttm_base_object **p_base)
{
struct ttm_base_object *base = *p_base;
struct vmw_user_context *ctx =
container_of(base, struct vmw_user_context, base);
struct vmw_resource *res = &ctx->res;
*p_base = NULL;
vmw_resource_unreference(&res);
}
int vmw_context_destroy_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_context_arg *arg = (struct drm_vmw_context_arg *)data;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
return ttm_ref_object_base_unref(tfile, arg->cid, TTM_REF_USAGE);
}
int vmw_context_define_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_user_context *ctx;
struct vmw_resource *res;
struct vmw_resource *tmp;
struct drm_vmw_context_arg *arg = (struct drm_vmw_context_arg *)data;
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_master *vmaster = vmw_master(file_priv->master);
int ret;
if (unlikely(vmw_user_context_size == 0))
vmw_user_context_size = ttm_round_pot(sizeof(*ctx)) + 128;
ret = ttm_read_lock(&vmaster->lock, true);
if (unlikely(ret != 0))
return ret;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv),
vmw_user_context_size,
false, true);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Out of graphics memory for context"
" creation.\n");
goto out_unlock;
}
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (unlikely(ctx == NULL)) {
ttm_mem_global_free(vmw_mem_glob(dev_priv),
vmw_user_context_size);
ret = -ENOMEM;
goto out_unlock;
}
res = &ctx->res;
ctx->base.shareable = false;
ctx->base.tfile = NULL;
ret = vmw_context_init(dev_priv, res, vmw_user_context_free);
if (unlikely(ret != 0))
goto out_unlock;
tmp = vmw_resource_reference(&ctx->res);
ret = ttm_base_object_init(tfile, &ctx->base, false, VMW_RES_CONTEXT,
&vmw_user_context_base_release, NULL);
if (unlikely(ret != 0)) {
vmw_resource_unreference(&tmp);
goto out_err;
}
arg->cid = ctx->base.hash.key;
out_err:
vmw_resource_unreference(&res);
out_unlock:
ttm_read_unlock(&vmaster->lock);
return ret;
}
