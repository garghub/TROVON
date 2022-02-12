static struct vmw_cotable *vmw_cotable(struct vmw_resource *res)
{
return container_of(res, struct vmw_cotable, res);
}
static int vmw_cotable_destroy(struct vmw_resource *res)
{
res->id = -1;
return 0;
}
static int vmw_cotable_unscrub(struct vmw_resource *res)
{
struct vmw_cotable *vcotbl = vmw_cotable(res);
struct vmw_private *dev_priv = res->dev_priv;
struct ttm_buffer_object *bo = &res->backup->base;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetCOTable body;
} *cmd;
WARN_ON_ONCE(bo->mem.mem_type != VMW_PL_MOB);
lockdep_assert_held(&bo->resv->lock.base);
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd), SVGA3D_INVALID_ID);
if (!cmd) {
DRM_ERROR("Failed reserving FIFO space for cotable "
"binding.\n");
return -ENOMEM;
}
WARN_ON(vcotbl->ctx->id == SVGA3D_INVALID_ID);
WARN_ON(bo->mem.mem_type != VMW_PL_MOB);
cmd->header.id = SVGA_3D_CMD_DX_SET_COTABLE;
cmd->header.size = sizeof(cmd->body);
cmd->body.cid = vcotbl->ctx->id;
cmd->body.type = vcotbl->type;
cmd->body.mobid = bo->mem.start;
cmd->body.validSizeInBytes = vcotbl->size_read_back;
vmw_fifo_commit_flush(dev_priv, sizeof(*cmd));
vcotbl->scrubbed = false;
return 0;
}
static int vmw_cotable_bind(struct vmw_resource *res,
struct ttm_validate_buffer *val_buf)
{
val_buf->bo = &res->backup->base;
return vmw_cotable_unscrub(res);
}
int vmw_cotable_scrub(struct vmw_resource *res, bool readback)
{
struct vmw_cotable *vcotbl = vmw_cotable(res);
struct vmw_private *dev_priv = res->dev_priv;
size_t submit_size;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXReadbackCOTable body;
} *cmd0;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetCOTable body;
} *cmd1;
if (vcotbl->scrubbed)
return 0;
if (co_info[vcotbl->type].unbind_func)
co_info[vcotbl->type].unbind_func(dev_priv,
&vcotbl->resource_list,
readback);
submit_size = sizeof(*cmd1);
if (readback)
submit_size += sizeof(*cmd0);
cmd1 = vmw_fifo_reserve_dx(dev_priv, submit_size, SVGA3D_INVALID_ID);
if (!cmd1) {
DRM_ERROR("Failed reserving FIFO space for cotable "
"unbinding.\n");
return -ENOMEM;
}
vcotbl->size_read_back = 0;
if (readback) {
cmd0 = (void *) cmd1;
cmd0->header.id = SVGA_3D_CMD_DX_READBACK_COTABLE;
cmd0->header.size = sizeof(cmd0->body);
cmd0->body.cid = vcotbl->ctx->id;
cmd0->body.type = vcotbl->type;
cmd1 = (void *) &cmd0[1];
vcotbl->size_read_back = res->backup_size;
}
cmd1->header.id = SVGA_3D_CMD_DX_SET_COTABLE;
cmd1->header.size = sizeof(cmd1->body);
cmd1->body.cid = vcotbl->ctx->id;
cmd1->body.type = vcotbl->type;
cmd1->body.mobid = SVGA3D_INVALID_ID;
cmd1->body.validSizeInBytes = 0;
vmw_fifo_commit_flush(dev_priv, submit_size);
vcotbl->scrubbed = true;
res->id = -1;
return 0;
}
static int vmw_cotable_unbind(struct vmw_resource *res,
bool readback,
struct ttm_validate_buffer *val_buf)
{
struct vmw_cotable *vcotbl = vmw_cotable(res);
struct vmw_private *dev_priv = res->dev_priv;
struct ttm_buffer_object *bo = val_buf->bo;
struct vmw_fence_obj *fence;
if (list_empty(&res->mob_head))
return 0;
WARN_ON_ONCE(bo->mem.mem_type != VMW_PL_MOB);
lockdep_assert_held(&bo->resv->lock.base);
mutex_lock(&dev_priv->binding_mutex);
if (!vcotbl->scrubbed)
vmw_dx_context_scrub_cotables(vcotbl->ctx, readback);
mutex_unlock(&dev_priv->binding_mutex);
(void) vmw_execbuf_fence_commands(NULL, dev_priv, &fence, NULL);
vmw_fence_single_bo(bo, fence);
if (likely(fence != NULL))
vmw_fence_obj_unreference(&fence);
return 0;
}
static int vmw_cotable_readback(struct vmw_resource *res)
{
struct vmw_cotable *vcotbl = vmw_cotable(res);
struct vmw_private *dev_priv = res->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXReadbackCOTable body;
} *cmd;
struct vmw_fence_obj *fence;
if (!vcotbl->scrubbed) {
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd),
SVGA3D_INVALID_ID);
if (!cmd) {
DRM_ERROR("Failed reserving FIFO space for cotable "
"readback.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_READBACK_COTABLE;
cmd->header.size = sizeof(cmd->body);
cmd->body.cid = vcotbl->ctx->id;
cmd->body.type = vcotbl->type;
vcotbl->size_read_back = res->backup_size;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
}
(void) vmw_execbuf_fence_commands(NULL, dev_priv, &fence, NULL);
vmw_fence_single_bo(&res->backup->base, fence);
vmw_fence_obj_unreference(&fence);
return 0;
}
static int vmw_cotable_resize(struct vmw_resource *res, size_t new_size)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_cotable *vcotbl = vmw_cotable(res);
struct vmw_dma_buffer *buf, *old_buf = res->backup;
struct ttm_buffer_object *bo, *old_bo = &res->backup->base;
size_t old_size = res->backup_size;
size_t old_size_read_back = vcotbl->size_read_back;
size_t cur_size_read_back;
struct ttm_bo_kmap_obj old_map, new_map;
int ret;
size_t i;
ret = vmw_cotable_readback(res);
if (ret)
return ret;
cur_size_read_back = vcotbl->size_read_back;
vcotbl->size_read_back = old_size_read_back;
buf = kzalloc(sizeof(*buf), GFP_KERNEL);
if (!buf)
return -ENOMEM;
ret = vmw_dmabuf_init(dev_priv, buf, new_size, &vmw_mob_ne_placement,
true, vmw_dmabuf_bo_free);
if (ret) {
DRM_ERROR("Failed initializing new cotable MOB.\n");
return ret;
}
bo = &buf->base;
WARN_ON_ONCE(ttm_bo_reserve(bo, false, true, false, NULL));
ret = ttm_bo_wait(old_bo, false, false, false);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed waiting for cotable unbind.\n");
goto out_wait;
}
for (i = 0; i < old_bo->num_pages; ++i) {
bool dummy;
ret = ttm_bo_kmap(old_bo, i, 1, &old_map);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed mapping old COTable on resize.\n");
goto out_wait;
}
ret = ttm_bo_kmap(bo, i, 1, &new_map);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed mapping new COTable on resize.\n");
goto out_map_new;
}
memcpy(ttm_kmap_obj_virtual(&new_map, &dummy),
ttm_kmap_obj_virtual(&old_map, &dummy),
PAGE_SIZE);
ttm_bo_kunmap(&new_map);
ttm_bo_kunmap(&old_map);
}
ret = ttm_bo_validate(bo, &vmw_mob_placement, false, false);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed validating new COTable backup buffer.\n");
goto out_wait;
}
res->backup = buf;
res->backup_size = new_size;
vcotbl->size_read_back = cur_size_read_back;
ret = vmw_cotable_unscrub(res);
if (ret) {
DRM_ERROR("Failed switching COTable backup buffer.\n");
res->backup = old_buf;
res->backup_size = old_size;
vcotbl->size_read_back = old_size_read_back;
goto out_wait;
}
list_del(&res->mob_head);
list_add_tail(&res->mob_head, &buf->res_list);
vmw_dmabuf_unreference(&old_buf);
res->id = vcotbl->type;
return 0;
out_map_new:
ttm_bo_kunmap(&old_map);
out_wait:
ttm_bo_unreserve(bo);
vmw_dmabuf_unreference(&buf);
return ret;
}
static int vmw_cotable_create(struct vmw_resource *res)
{
struct vmw_cotable *vcotbl = vmw_cotable(res);
size_t new_size = res->backup_size;
size_t needed_size;
int ret;
needed_size = (vcotbl->seen_entries + 1) * co_info[vcotbl->type].size;
while (needed_size > new_size)
new_size *= 2;
if (likely(new_size <= res->backup_size)) {
if (vcotbl->scrubbed && !list_empty(&res->mob_head)) {
ret = vmw_cotable_unscrub(res);
if (ret)
return ret;
}
res->id = vcotbl->type;
return 0;
}
return vmw_cotable_resize(res, new_size);
}
static void vmw_hw_cotable_destroy(struct vmw_resource *res)
{
(void) vmw_cotable_destroy(res);
}
static void vmw_cotable_free(struct vmw_resource *res)
{
struct vmw_private *dev_priv = res->dev_priv;
kfree(res);
ttm_mem_global_free(vmw_mem_glob(dev_priv), cotable_acc_size);
}
struct vmw_resource *vmw_cotable_alloc(struct vmw_private *dev_priv,
struct vmw_resource *ctx,
u32 type)
{
struct vmw_cotable *vcotbl;
int ret;
u32 num_entries;
if (unlikely(cotable_acc_size == 0))
cotable_acc_size = ttm_round_pot(sizeof(struct vmw_cotable));
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv),
cotable_acc_size, false, true);
if (unlikely(ret))
return ERR_PTR(ret);
vcotbl = kzalloc(sizeof(*vcotbl), GFP_KERNEL);
if (unlikely(vcotbl == NULL)) {
ret = -ENOMEM;
goto out_no_alloc;
}
ret = vmw_resource_init(dev_priv, &vcotbl->res, true,
vmw_cotable_free, &vmw_cotable_func);
if (unlikely(ret != 0))
goto out_no_init;
INIT_LIST_HEAD(&vcotbl->resource_list);
vcotbl->res.id = type;
vcotbl->res.backup_size = PAGE_SIZE;
num_entries = PAGE_SIZE / co_info[type].size;
if (num_entries < co_info[type].min_initial_entries) {
vcotbl->res.backup_size = co_info[type].min_initial_entries *
co_info[type].size;
vcotbl->res.backup_size =
(vcotbl->res.backup_size + PAGE_SIZE - 1) & PAGE_MASK;
}
vcotbl->scrubbed = true;
vcotbl->seen_entries = -1;
vcotbl->type = type;
vcotbl->ctx = ctx;
vmw_resource_activate(&vcotbl->res, vmw_hw_cotable_destroy);
return &vcotbl->res;
out_no_init:
kfree(vcotbl);
out_no_alloc:
ttm_mem_global_free(vmw_mem_glob(dev_priv), cotable_acc_size);
return ERR_PTR(ret);
}
int vmw_cotable_notify(struct vmw_resource *res, int id)
{
struct vmw_cotable *vcotbl = vmw_cotable(res);
if (id < 0 || id >= SVGA_COTABLE_MAX_IDS) {
DRM_ERROR("Illegal COTable id. Type is %u. Id is %d\n",
(unsigned) vcotbl->type, id);
return -EINVAL;
}
if (vcotbl->seen_entries < id) {
res->id = -1;
vcotbl->seen_entries = id;
}
return 0;
}
void vmw_cotable_add_resource(struct vmw_resource *res, struct list_head *head)
{
struct vmw_cotable *vcotbl =
container_of(res, struct vmw_cotable, res);
list_add_tail(head, &vcotbl->resource_list);
}
