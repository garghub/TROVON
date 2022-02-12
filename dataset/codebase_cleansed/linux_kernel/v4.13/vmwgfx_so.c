static struct vmw_view *vmw_view(struct vmw_resource *res)
{
return container_of(res, struct vmw_view, res);
}
static void vmw_view_commit_notify(struct vmw_resource *res,
enum vmw_cmdbuf_res_state state)
{
struct vmw_view *view = vmw_view(res);
struct vmw_private *dev_priv = res->dev_priv;
mutex_lock(&dev_priv->binding_mutex);
if (state == VMW_CMDBUF_RES_ADD) {
struct vmw_surface *srf = vmw_res_to_srf(view->srf);
list_add_tail(&view->srf_head, &srf->view_list);
vmw_cotable_add_resource(view->cotable, &view->cotable_head);
view->committed = true;
res->id = view->view_id;
} else {
list_del_init(&view->cotable_head);
list_del_init(&view->srf_head);
view->committed = false;
res->id = -1;
}
mutex_unlock(&dev_priv->binding_mutex);
}
static int vmw_view_create(struct vmw_resource *res)
{
struct vmw_view *view = vmw_view(res);
struct vmw_surface *srf = vmw_res_to_srf(view->srf);
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
struct vmw_view_define body;
} *cmd;
mutex_lock(&dev_priv->binding_mutex);
if (!view->committed) {
mutex_unlock(&dev_priv->binding_mutex);
return 0;
}
cmd = vmw_fifo_reserve_dx(res->dev_priv, view->cmd_size,
view->ctx->id);
if (!cmd) {
DRM_ERROR("Failed reserving FIFO space for view creation.\n");
mutex_unlock(&dev_priv->binding_mutex);
return -ENOMEM;
}
memcpy(cmd, &view->cmd, view->cmd_size);
WARN_ON(cmd->body.view_id != view->view_id);
WARN_ON(view->srf->id == SVGA3D_INVALID_ID);
cmd->body.sid = view->srf->id;
vmw_fifo_commit(res->dev_priv, view->cmd_size);
res->id = view->view_id;
list_add_tail(&view->srf_head, &srf->view_list);
vmw_cotable_add_resource(view->cotable, &view->cotable_head);
mutex_unlock(&dev_priv->binding_mutex);
return 0;
}
static int vmw_view_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_view *view = vmw_view(res);
struct {
SVGA3dCmdHeader header;
union vmw_view_destroy body;
} *cmd;
WARN_ON_ONCE(!mutex_is_locked(&dev_priv->binding_mutex));
vmw_binding_res_list_scrub(&res->binding_head);
if (!view->committed || res->id == -1)
return 0;
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd), view->ctx->id);
if (!cmd) {
DRM_ERROR("Failed reserving FIFO space for view "
"destruction.\n");
return -ENOMEM;
}
cmd->header.id = vmw_view_destroy_cmds[view->view_type];
cmd->header.size = sizeof(cmd->body);
cmd->body.view_id = view->view_id;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
res->id = -1;
list_del_init(&view->cotable_head);
list_del_init(&view->srf_head);
return 0;
}
static void vmw_hw_view_destroy(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
mutex_lock(&dev_priv->binding_mutex);
WARN_ON(vmw_view_destroy(res));
res->id = -1;
mutex_unlock(&dev_priv->binding_mutex);
}
static u32 vmw_view_key(u32 user_key, enum vmw_view_type view_type)
{
return user_key | (view_type << 20);
}
static bool vmw_view_id_ok(u32 user_key, enum vmw_view_type view_type)
{
return (user_key < SVGA_COTABLE_MAX_IDS &&
view_type < vmw_view_max);
}
static void vmw_view_res_free(struct vmw_resource *res)
{
struct vmw_view *view = vmw_view(res);
size_t size = offsetof(struct vmw_view, cmd) + view->cmd_size;
struct vmw_private *dev_priv = res->dev_priv;
vmw_resource_unreference(&view->cotable);
vmw_resource_unreference(&view->srf);
kfree_rcu(view, rcu);
ttm_mem_global_free(vmw_mem_glob(dev_priv), size);
}
int vmw_view_add(struct vmw_cmdbuf_res_manager *man,
struct vmw_resource *ctx,
struct vmw_resource *srf,
enum vmw_view_type view_type,
u32 user_key,
const void *cmd,
size_t cmd_size,
struct list_head *list)
{
static const size_t vmw_view_define_sizes[] = {
[vmw_view_sr] = sizeof(SVGA3dCmdDXDefineShaderResourceView),
[vmw_view_rt] = sizeof(SVGA3dCmdDXDefineRenderTargetView),
[vmw_view_ds] = sizeof(SVGA3dCmdDXDefineDepthStencilView)
};
struct vmw_private *dev_priv = ctx->dev_priv;
struct vmw_resource *res;
struct vmw_view *view;
size_t size;
int ret;
if (cmd_size != vmw_view_define_sizes[view_type] +
sizeof(SVGA3dCmdHeader)) {
DRM_ERROR("Illegal view create command size.\n");
return -EINVAL;
}
if (!vmw_view_id_ok(user_key, view_type)) {
DRM_ERROR("Illegal view add view id.\n");
return -EINVAL;
}
size = offsetof(struct vmw_view, cmd) + cmd_size;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv), size, false, true);
if (ret) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Out of graphics memory for view"
" creation.\n");
return ret;
}
view = kmalloc(size, GFP_KERNEL);
if (!view) {
ttm_mem_global_free(vmw_mem_glob(dev_priv), size);
return -ENOMEM;
}
res = &view->res;
view->ctx = ctx;
view->srf = vmw_resource_reference(srf);
view->cotable = vmw_context_cotable(ctx, vmw_view_cotables[view_type]);
view->view_type = view_type;
view->view_id = user_key;
view->cmd_size = cmd_size;
view->committed = false;
INIT_LIST_HEAD(&view->srf_head);
INIT_LIST_HEAD(&view->cotable_head);
memcpy(&view->cmd, cmd, cmd_size);
ret = vmw_resource_init(dev_priv, res, true,
vmw_view_res_free, &vmw_view_func);
if (ret)
goto out_resource_init;
ret = vmw_cmdbuf_res_add(man, vmw_cmdbuf_res_view,
vmw_view_key(user_key, view_type),
res, list);
if (ret)
goto out_resource_init;
res->id = view->view_id;
vmw_resource_activate(res, vmw_hw_view_destroy);
out_resource_init:
vmw_resource_unreference(&res);
return ret;
}
int vmw_view_remove(struct vmw_cmdbuf_res_manager *man,
u32 user_key, enum vmw_view_type view_type,
struct list_head *list,
struct vmw_resource **res_p)
{
if (!vmw_view_id_ok(user_key, view_type)) {
DRM_ERROR("Illegal view remove view id.\n");
return -EINVAL;
}
return vmw_cmdbuf_res_remove(man, vmw_cmdbuf_res_view,
vmw_view_key(user_key, view_type),
list, res_p);
}
void vmw_view_cotable_list_destroy(struct vmw_private *dev_priv,
struct list_head *list,
bool readback)
{
struct vmw_view *entry, *next;
WARN_ON_ONCE(!mutex_is_locked(&dev_priv->binding_mutex));
list_for_each_entry_safe(entry, next, list, cotable_head)
WARN_ON(vmw_view_destroy(&entry->res));
}
void vmw_view_surface_list_destroy(struct vmw_private *dev_priv,
struct list_head *list)
{
struct vmw_view *entry, *next;
WARN_ON_ONCE(!mutex_is_locked(&dev_priv->binding_mutex));
list_for_each_entry_safe(entry, next, list, srf_head)
WARN_ON(vmw_view_destroy(&entry->res));
}
struct vmw_resource *vmw_view_srf(struct vmw_resource *res)
{
return vmw_view(res)->srf;
}
struct vmw_resource *vmw_view_lookup(struct vmw_cmdbuf_res_manager *man,
enum vmw_view_type view_type,
u32 user_key)
{
return vmw_cmdbuf_res_lookup(man, vmw_cmdbuf_res_view,
vmw_view_key(user_key, view_type));
}
static void vmw_so_build_asserts(void)
{
BUILD_BUG_ON(SVGA_3D_CMD_DX_DESTROY_SHADERRESOURCE_VIEW !=
SVGA_3D_CMD_DX_DEFINE_SHADERRESOURCE_VIEW + 1);
BUILD_BUG_ON(SVGA_3D_CMD_DX_DEFINE_RENDERTARGET_VIEW !=
SVGA_3D_CMD_DX_DEFINE_SHADERRESOURCE_VIEW + 2);
BUILD_BUG_ON(SVGA_3D_CMD_DX_DESTROY_RENDERTARGET_VIEW !=
SVGA_3D_CMD_DX_DEFINE_SHADERRESOURCE_VIEW + 3);
BUILD_BUG_ON(SVGA_3D_CMD_DX_DEFINE_DEPTHSTENCIL_VIEW !=
SVGA_3D_CMD_DX_DEFINE_SHADERRESOURCE_VIEW + 4);
BUILD_BUG_ON(SVGA_3D_CMD_DX_DESTROY_DEPTHSTENCIL_VIEW !=
SVGA_3D_CMD_DX_DEFINE_SHADERRESOURCE_VIEW + 5);
BUILD_BUG_ON(sizeof(union vmw_view_destroy) != sizeof(u32));
BUILD_BUG_ON(SVGA_COTABLE_MAX_IDS >= ((1 << 20) - 1));
BUILD_BUG_ON(offsetof(struct vmw_view_define, sid) !=
offsetof(SVGA3dCmdDXDefineShaderResourceView, sid));
BUILD_BUG_ON(offsetof(struct vmw_view_define, sid) !=
offsetof(SVGA3dCmdDXDefineRenderTargetView, sid));
BUILD_BUG_ON(offsetof(struct vmw_view_define, sid) !=
offsetof(SVGA3dCmdDXDefineDepthStencilView, sid));
}
