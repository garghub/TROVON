static size_t vmw_ptr_diff(void *a, void *b)
{
return (unsigned long) b - (unsigned long) a;
}
static void vmw_resources_unreserve(struct vmw_sw_context *sw_context,
bool backoff)
{
struct vmw_resource_val_node *val;
struct list_head *list = &sw_context->resource_list;
if (sw_context->dx_query_mob && !backoff)
vmw_context_bind_dx_query(sw_context->dx_query_ctx,
sw_context->dx_query_mob);
list_for_each_entry(val, list, head) {
struct vmw_resource *res = val->res;
bool switch_backup =
(backoff) ? false : val->switching_backup;
if (unlikely(val->staged_bindings)) {
if (!backoff) {
vmw_binding_state_commit
(vmw_context_binding_state(val->res),
val->staged_bindings);
}
if (val->staged_bindings != sw_context->staged_bindings)
vmw_binding_state_free(val->staged_bindings);
else
sw_context->staged_bindings_inuse = false;
val->staged_bindings = NULL;
}
vmw_resource_unreserve(res, switch_backup, val->new_backup,
val->new_backup_offset);
vmw_dmabuf_unreference(&val->new_backup);
}
}
static int vmw_cmd_ctx_first_setup(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
struct vmw_resource_val_node *node)
{
int ret;
ret = vmw_resource_context_res_add(dev_priv, sw_context, node->res);
if (unlikely(ret != 0))
goto out_err;
if (!sw_context->staged_bindings) {
sw_context->staged_bindings =
vmw_binding_state_alloc(dev_priv);
if (IS_ERR(sw_context->staged_bindings)) {
DRM_ERROR("Failed to allocate context binding "
"information.\n");
ret = PTR_ERR(sw_context->staged_bindings);
sw_context->staged_bindings = NULL;
goto out_err;
}
}
if (sw_context->staged_bindings_inuse) {
node->staged_bindings = vmw_binding_state_alloc(dev_priv);
if (IS_ERR(node->staged_bindings)) {
DRM_ERROR("Failed to allocate context binding "
"information.\n");
ret = PTR_ERR(node->staged_bindings);
node->staged_bindings = NULL;
goto out_err;
}
} else {
node->staged_bindings = sw_context->staged_bindings;
sw_context->staged_bindings_inuse = true;
}
return 0;
out_err:
return ret;
}
static int vmw_resource_val_add(struct vmw_sw_context *sw_context,
struct vmw_resource *res,
struct vmw_resource_val_node **p_node)
{
struct vmw_private *dev_priv = res->dev_priv;
struct vmw_resource_val_node *node;
struct drm_hash_item *hash;
int ret;
if (likely(drm_ht_find_item(&sw_context->res_ht, (unsigned long) res,
&hash) == 0)) {
node = container_of(hash, struct vmw_resource_val_node, hash);
node->first_usage = false;
if (unlikely(p_node != NULL))
*p_node = node;
return 0;
}
node = kzalloc(sizeof(*node), GFP_KERNEL);
if (unlikely(!node)) {
DRM_ERROR("Failed to allocate a resource validation "
"entry.\n");
return -ENOMEM;
}
node->hash.key = (unsigned long) res;
ret = drm_ht_insert_item(&sw_context->res_ht, &node->hash);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to initialize a resource validation "
"entry.\n");
kfree(node);
return ret;
}
node->res = vmw_resource_reference(res);
node->first_usage = true;
if (unlikely(p_node != NULL))
*p_node = node;
if (!dev_priv->has_mob) {
list_add_tail(&node->head, &sw_context->resource_list);
return 0;
}
switch (vmw_res_type(res)) {
case vmw_res_context:
case vmw_res_dx_context:
list_add(&node->head, &sw_context->ctx_resource_list);
ret = vmw_cmd_ctx_first_setup(dev_priv, sw_context, node);
break;
case vmw_res_cotable:
list_add_tail(&node->head, &sw_context->ctx_resource_list);
break;
default:
list_add_tail(&node->head, &sw_context->resource_list);
break;
}
return ret;
}
static int vmw_view_res_val_add(struct vmw_sw_context *sw_context,
struct vmw_resource *view)
{
int ret;
ret = vmw_resource_val_add(sw_context, vmw_view_srf(view), NULL);
if (ret)
return ret;
return vmw_resource_val_add(sw_context, view, NULL);
}
static int vmw_view_id_val_add(struct vmw_sw_context *sw_context,
enum vmw_view_type view_type, u32 id)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_resource *view;
int ret;
if (!ctx_node) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
view = vmw_view_lookup(sw_context->man, view_type, id);
if (IS_ERR(view))
return PTR_ERR(view);
ret = vmw_view_res_val_add(sw_context, view);
vmw_resource_unreference(&view);
return ret;
}
static int vmw_resource_context_res_add(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
struct vmw_resource *ctx)
{
struct list_head *binding_list;
struct vmw_ctx_bindinfo *entry;
int ret = 0;
struct vmw_resource *res;
u32 i;
if (dev_priv->has_dx && vmw_res_type(ctx) == vmw_res_dx_context) {
for (i = 0; i < SVGA_COTABLE_DX10_MAX; ++i) {
res = vmw_context_cotable(ctx, i);
if (IS_ERR(res))
continue;
ret = vmw_resource_val_add(sw_context, res, NULL);
vmw_resource_unreference(&res);
if (unlikely(ret != 0))
return ret;
}
}
mutex_lock(&dev_priv->binding_mutex);
binding_list = vmw_context_binding_list(ctx);
list_for_each_entry(entry, binding_list, ctx_list) {
res = vmw_resource_reference_unless_doomed(entry->res);
if (unlikely(res == NULL))
continue;
if (vmw_res_type(entry->res) == vmw_res_view)
ret = vmw_view_res_val_add(sw_context, entry->res);
else
ret = vmw_resource_val_add(sw_context, entry->res,
NULL);
vmw_resource_unreference(&res);
if (unlikely(ret != 0))
break;
}
if (dev_priv->has_dx && vmw_res_type(ctx) == vmw_res_dx_context) {
struct vmw_dma_buffer *dx_query_mob;
dx_query_mob = vmw_context_get_dx_query_mob(ctx);
if (dx_query_mob)
ret = vmw_bo_to_validate_list(sw_context,
dx_query_mob,
true, NULL);
}
mutex_unlock(&dev_priv->binding_mutex);
return ret;
}
static int vmw_resource_relocation_add(struct list_head *list,
const struct vmw_resource *res,
unsigned long offset,
enum vmw_resource_relocation_type
rel_type)
{
struct vmw_resource_relocation *rel;
rel = kmalloc(sizeof(*rel), GFP_KERNEL);
if (unlikely(!rel)) {
DRM_ERROR("Failed to allocate a resource relocation.\n");
return -ENOMEM;
}
rel->res = res;
rel->offset = offset;
rel->rel_type = rel_type;
list_add_tail(&rel->head, list);
return 0;
}
static void vmw_resource_relocations_free(struct list_head *list)
{
struct vmw_resource_relocation *rel, *n;
list_for_each_entry_safe(rel, n, list, head) {
list_del(&rel->head);
kfree(rel);
}
}
static void vmw_resource_relocations_apply(uint32_t *cb,
struct list_head *list)
{
struct vmw_resource_relocation *rel;
BUILD_BUG_ON(SVGA_CB_MAX_SIZE >= (1 << 29));
BUILD_BUG_ON(vmw_res_rel_max >= (1 << 3));
list_for_each_entry(rel, list, head) {
u32 *addr = (u32 *)((unsigned long) cb + rel->offset);
switch (rel->rel_type) {
case vmw_res_rel_normal:
*addr = rel->res->id;
break;
case vmw_res_rel_nop:
*addr = SVGA_3D_CMD_NOP;
break;
default:
if (rel->res->id == -1)
*addr = SVGA_3D_CMD_NOP;
break;
}
}
}
static int vmw_cmd_invalid(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
return -EINVAL;
}
static int vmw_cmd_ok(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
return 0;
}
static int vmw_bo_to_validate_list(struct vmw_sw_context *sw_context,
struct vmw_dma_buffer *vbo,
bool validate_as_mob,
uint32_t *p_val_node)
{
uint32_t val_node;
struct vmw_validate_buffer *vval_buf;
struct ttm_validate_buffer *val_buf;
struct drm_hash_item *hash;
int ret;
if (likely(drm_ht_find_item(&sw_context->res_ht, (unsigned long) vbo,
&hash) == 0)) {
vval_buf = container_of(hash, struct vmw_validate_buffer,
hash);
if (unlikely(vval_buf->validate_as_mob != validate_as_mob)) {
DRM_ERROR("Inconsistent buffer usage.\n");
return -EINVAL;
}
val_buf = &vval_buf->base;
val_node = vval_buf - sw_context->val_bufs;
} else {
val_node = sw_context->cur_val_buf;
if (unlikely(val_node >= VMWGFX_MAX_VALIDATIONS)) {
DRM_ERROR("Max number of DMA buffers per submission "
"exceeded.\n");
return -EINVAL;
}
vval_buf = &sw_context->val_bufs[val_node];
vval_buf->hash.key = (unsigned long) vbo;
ret = drm_ht_insert_item(&sw_context->res_ht, &vval_buf->hash);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to initialize a buffer validation "
"entry.\n");
return ret;
}
++sw_context->cur_val_buf;
val_buf = &vval_buf->base;
val_buf->bo = ttm_bo_reference(&vbo->base);
val_buf->shared = false;
list_add_tail(&val_buf->head, &sw_context->validate_nodes);
vval_buf->validate_as_mob = validate_as_mob;
}
if (p_val_node)
*p_val_node = val_node;
return 0;
}
static int vmw_resources_reserve(struct vmw_sw_context *sw_context)
{
struct vmw_resource_val_node *val;
int ret = 0;
list_for_each_entry(val, &sw_context->resource_list, head) {
struct vmw_resource *res = val->res;
ret = vmw_resource_reserve(res, true, val->no_buffer_needed);
if (unlikely(ret != 0))
return ret;
if (res->backup) {
struct vmw_dma_buffer *vbo = res->backup;
ret = vmw_bo_to_validate_list
(sw_context, vbo,
vmw_resource_needs_backup(res), NULL);
if (unlikely(ret != 0))
return ret;
}
}
if (sw_context->dx_query_mob) {
struct vmw_dma_buffer *expected_dx_query_mob;
expected_dx_query_mob =
vmw_context_get_dx_query_mob(sw_context->dx_query_ctx);
if (expected_dx_query_mob &&
expected_dx_query_mob != sw_context->dx_query_mob) {
ret = -EINVAL;
}
}
return ret;
}
static int vmw_resources_validate(struct vmw_sw_context *sw_context)
{
struct vmw_resource_val_node *val;
int ret;
list_for_each_entry(val, &sw_context->resource_list, head) {
struct vmw_resource *res = val->res;
struct vmw_dma_buffer *backup = res->backup;
ret = vmw_resource_validate(res);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Failed to validate resource.\n");
return ret;
}
if (backup && res->backup && (backup != res->backup)) {
struct vmw_dma_buffer *vbo = res->backup;
ret = vmw_bo_to_validate_list
(sw_context, vbo,
vmw_resource_needs_backup(res), NULL);
if (ret) {
ttm_bo_unreserve(&vbo->base);
return ret;
}
}
}
return 0;
}
static int vmw_cmd_res_reloc_add(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
uint32_t *id_loc,
struct vmw_resource *res,
struct vmw_resource_val_node **p_val)
{
int ret;
struct vmw_resource_val_node *node;
*p_val = NULL;
ret = vmw_resource_relocation_add(&sw_context->res_relocations,
res,
vmw_ptr_diff(sw_context->buf_start,
id_loc),
vmw_res_rel_normal);
if (unlikely(ret != 0))
return ret;
ret = vmw_resource_val_add(sw_context, res, &node);
if (unlikely(ret != 0))
return ret;
if (p_val)
*p_val = node;
return 0;
}
static int
vmw_cmd_res_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
enum vmw_res_type res_type,
const struct vmw_user_resource_conv *converter,
uint32_t *id_loc,
struct vmw_resource_val_node **p_val)
{
struct vmw_res_cache_entry *rcache =
&sw_context->res_cache[res_type];
struct vmw_resource *res;
struct vmw_resource_val_node *node;
int ret;
if (*id_loc == SVGA3D_INVALID_ID) {
if (p_val)
*p_val = NULL;
if (res_type == vmw_res_context) {
DRM_ERROR("Illegal context invalid id.\n");
return -EINVAL;
}
return 0;
}
if (likely(rcache->valid && *id_loc == rcache->handle)) {
const struct vmw_resource *res = rcache->res;
rcache->node->first_usage = false;
if (p_val)
*p_val = rcache->node;
return vmw_resource_relocation_add
(&sw_context->res_relocations, res,
vmw_ptr_diff(sw_context->buf_start, id_loc),
vmw_res_rel_normal);
}
ret = vmw_user_resource_lookup_handle(dev_priv,
sw_context->fp->tfile,
*id_loc,
converter,
&res);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not find or use resource 0x%08x.\n",
(unsigned) *id_loc);
dump_stack();
return ret;
}
rcache->valid = true;
rcache->res = res;
rcache->handle = *id_loc;
ret = vmw_cmd_res_reloc_add(dev_priv, sw_context, id_loc,
res, &node);
if (unlikely(ret != 0))
goto out_no_reloc;
rcache->node = node;
if (p_val)
*p_val = node;
vmw_resource_unreference(&res);
return 0;
out_no_reloc:
BUG_ON(sw_context->error_resource != NULL);
sw_context->error_resource = res;
return ret;
}
static int vmw_rebind_all_dx_query(struct vmw_resource *ctx_res)
{
struct vmw_private *dev_priv = ctx_res->dev_priv;
struct vmw_dma_buffer *dx_query_mob;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXBindAllQuery body;
} *cmd;
dx_query_mob = vmw_context_get_dx_query_mob(ctx_res);
if (!dx_query_mob || dx_query_mob->dx_query_ctx)
return 0;
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd), ctx_res->id);
if (cmd == NULL) {
DRM_ERROR("Failed to rebind queries.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_BIND_ALL_QUERY;
cmd->header.size = sizeof(cmd->body);
cmd->body.cid = ctx_res->id;
cmd->body.mobid = dx_query_mob->base.mem.start;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
vmw_context_bind_dx_query(ctx_res, dx_query_mob);
return 0;
}
static int vmw_rebind_contexts(struct vmw_sw_context *sw_context)
{
struct vmw_resource_val_node *val;
int ret;
list_for_each_entry(val, &sw_context->resource_list, head) {
if (unlikely(!val->staged_bindings))
break;
ret = vmw_binding_rebind_all
(vmw_context_binding_state(val->res));
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Failed to rebind context.\n");
return ret;
}
ret = vmw_rebind_all_dx_query(val->res);
if (ret != 0)
return ret;
}
return 0;
}
static int vmw_view_bindings_add(struct vmw_sw_context *sw_context,
enum vmw_view_type view_type,
enum vmw_ctx_binding_type binding_type,
uint32 shader_slot,
uint32 view_ids[], u32 num_views,
u32 first_slot)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_cmdbuf_res_manager *man;
u32 i;
int ret;
if (!ctx_node) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
man = sw_context->man;
for (i = 0; i < num_views; ++i) {
struct vmw_ctx_bindinfo_view binding;
struct vmw_resource *view = NULL;
if (view_ids[i] != SVGA3D_INVALID_ID) {
view = vmw_view_lookup(man, view_type, view_ids[i]);
if (IS_ERR(view)) {
DRM_ERROR("View not found.\n");
return PTR_ERR(view);
}
ret = vmw_view_res_val_add(sw_context, view);
if (ret) {
DRM_ERROR("Could not add view to "
"validation list.\n");
vmw_resource_unreference(&view);
return ret;
}
}
binding.bi.ctx = ctx_node->res;
binding.bi.res = view;
binding.bi.bt = binding_type;
binding.shader_slot = shader_slot;
binding.slot = first_slot + i;
vmw_binding_add(ctx_node->staged_bindings, &binding.bi,
shader_slot, binding.slot);
if (view)
vmw_resource_unreference(&view);
}
return 0;
}
static int vmw_cmd_cid_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_cid_cmd {
SVGA3dCmdHeader header;
uint32_t cid;
} *cmd;
cmd = container_of(header, struct vmw_cid_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->cid, NULL);
}
static int vmw_cmd_set_render_target_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_sid_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdSetRenderTarget body;
} *cmd;
struct vmw_resource_val_node *ctx_node;
struct vmw_resource_val_node *res_node;
int ret;
cmd = container_of(header, struct vmw_sid_cmd, header);
if (cmd->body.type >= SVGA3D_RT_MAX) {
DRM_ERROR("Illegal render target type %u.\n",
(unsigned) cmd->body.type);
return -EINVAL;
}
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->body.cid,
&ctx_node);
if (unlikely(ret != 0))
return ret;
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.target.sid, &res_node);
if (unlikely(ret != 0))
return ret;
if (dev_priv->has_mob) {
struct vmw_ctx_bindinfo_view binding;
binding.bi.ctx = ctx_node->res;
binding.bi.res = res_node ? res_node->res : NULL;
binding.bi.bt = vmw_ctx_binding_rt;
binding.slot = cmd->body.type;
vmw_binding_add(ctx_node->staged_bindings,
&binding.bi, 0, binding.slot);
}
return 0;
}
static int vmw_cmd_surface_copy_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_sid_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdSurfaceCopy body;
} *cmd;
int ret;
cmd = container_of(header, struct vmw_sid_cmd, header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.src.sid, NULL);
if (ret)
return ret;
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.dest.sid, NULL);
}
static int vmw_cmd_buffer_copy_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXBufferCopy body;
} *cmd;
int ret;
cmd = container_of(header, typeof(*cmd), header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.src, NULL);
if (ret != 0)
return ret;
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.dest, NULL);
}
static int vmw_cmd_pred_copy_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXPredCopyRegion body;
} *cmd;
int ret;
cmd = container_of(header, typeof(*cmd), header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.srcSid, NULL);
if (ret != 0)
return ret;
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.dstSid, NULL);
}
static int vmw_cmd_stretch_blt_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_sid_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdSurfaceStretchBlt body;
} *cmd;
int ret;
cmd = container_of(header, struct vmw_sid_cmd, header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.src.sid, NULL);
if (unlikely(ret != 0))
return ret;
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.dest.sid, NULL);
}
static int vmw_cmd_blt_surf_screen_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_sid_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdBlitSurfaceToScreen body;
} *cmd;
cmd = container_of(header, struct vmw_sid_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.srcImage.sid, NULL);
}
static int vmw_cmd_present_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_sid_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdPresent body;
} *cmd;
cmd = container_of(header, struct vmw_sid_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter, &cmd->body.sid,
NULL);
}
static int vmw_query_bo_switch_prepare(struct vmw_private *dev_priv,
struct vmw_dma_buffer *new_query_bo,
struct vmw_sw_context *sw_context)
{
struct vmw_res_cache_entry *ctx_entry =
&sw_context->res_cache[vmw_res_context];
int ret;
BUG_ON(!ctx_entry->valid);
sw_context->last_query_ctx = ctx_entry->res;
if (unlikely(new_query_bo != sw_context->cur_query_bo)) {
if (unlikely(new_query_bo->base.num_pages > 4)) {
DRM_ERROR("Query buffer too large.\n");
return -EINVAL;
}
if (unlikely(sw_context->cur_query_bo != NULL)) {
sw_context->needs_post_query_barrier = true;
ret = vmw_bo_to_validate_list(sw_context,
sw_context->cur_query_bo,
dev_priv->has_mob, NULL);
if (unlikely(ret != 0))
return ret;
}
sw_context->cur_query_bo = new_query_bo;
ret = vmw_bo_to_validate_list(sw_context,
dev_priv->dummy_query_bo,
dev_priv->has_mob, NULL);
if (unlikely(ret != 0))
return ret;
}
return 0;
}
static void vmw_query_bo_switch_commit(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context)
{
if (sw_context->needs_post_query_barrier) {
struct vmw_res_cache_entry *ctx_entry =
&sw_context->res_cache[vmw_res_context];
struct vmw_resource *ctx;
int ret;
BUG_ON(!ctx_entry->valid);
ctx = ctx_entry->res;
ret = vmw_fifo_emit_dummy_query(dev_priv, ctx->id);
if (unlikely(ret != 0))
DRM_ERROR("Out of fifo space for dummy query.\n");
}
if (dev_priv->pinned_bo != sw_context->cur_query_bo) {
if (dev_priv->pinned_bo) {
vmw_bo_pin_reserved(dev_priv->pinned_bo, false);
vmw_dmabuf_unreference(&dev_priv->pinned_bo);
}
if (!sw_context->needs_post_query_barrier) {
vmw_bo_pin_reserved(sw_context->cur_query_bo, true);
if (!dev_priv->dummy_query_bo_pinned) {
vmw_bo_pin_reserved(dev_priv->dummy_query_bo,
true);
dev_priv->dummy_query_bo_pinned = true;
}
BUG_ON(sw_context->last_query_ctx == NULL);
dev_priv->query_cid = sw_context->last_query_ctx->id;
dev_priv->query_cid_valid = true;
dev_priv->pinned_bo =
vmw_dmabuf_reference(sw_context->cur_query_bo);
}
}
}
static int vmw_translate_mob_ptr(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGAMobId *id,
struct vmw_dma_buffer **vmw_bo_p)
{
struct vmw_dma_buffer *vmw_bo = NULL;
uint32_t handle = *id;
struct vmw_relocation *reloc;
int ret;
ret = vmw_user_dmabuf_lookup(sw_context->fp->tfile, handle, &vmw_bo,
NULL);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not find or use MOB buffer.\n");
ret = -EINVAL;
goto out_no_reloc;
}
if (unlikely(sw_context->cur_reloc >= VMWGFX_MAX_RELOCATIONS)) {
DRM_ERROR("Max number relocations per submission"
" exceeded\n");
ret = -EINVAL;
goto out_no_reloc;
}
reloc = &sw_context->relocs[sw_context->cur_reloc++];
reloc->mob_loc = id;
reloc->location = NULL;
ret = vmw_bo_to_validate_list(sw_context, vmw_bo, true, &reloc->index);
if (unlikely(ret != 0))
goto out_no_reloc;
*vmw_bo_p = vmw_bo;
return 0;
out_no_reloc:
vmw_dmabuf_unreference(&vmw_bo);
*vmw_bo_p = NULL;
return ret;
}
static int vmw_translate_guest_ptr(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGAGuestPtr *ptr,
struct vmw_dma_buffer **vmw_bo_p)
{
struct vmw_dma_buffer *vmw_bo = NULL;
uint32_t handle = ptr->gmrId;
struct vmw_relocation *reloc;
int ret;
ret = vmw_user_dmabuf_lookup(sw_context->fp->tfile, handle, &vmw_bo,
NULL);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not find or use GMR region.\n");
ret = -EINVAL;
goto out_no_reloc;
}
if (unlikely(sw_context->cur_reloc >= VMWGFX_MAX_RELOCATIONS)) {
DRM_ERROR("Max number relocations per submission"
" exceeded\n");
ret = -EINVAL;
goto out_no_reloc;
}
reloc = &sw_context->relocs[sw_context->cur_reloc++];
reloc->location = ptr;
ret = vmw_bo_to_validate_list(sw_context, vmw_bo, false, &reloc->index);
if (unlikely(ret != 0))
goto out_no_reloc;
*vmw_bo_p = vmw_bo;
return 0;
out_no_reloc:
vmw_dmabuf_unreference(&vmw_bo);
*vmw_bo_p = NULL;
return ret;
}
static int vmw_cmd_dx_define_query(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_dx_define_query_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdDXDefineQuery q;
} *cmd;
int ret;
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_resource *cotable_res;
if (ctx_node == NULL) {
DRM_ERROR("DX Context not set for query.\n");
return -EINVAL;
}
cmd = container_of(header, struct vmw_dx_define_query_cmd, header);
if (cmd->q.type < SVGA3D_QUERYTYPE_MIN ||
cmd->q.type >= SVGA3D_QUERYTYPE_MAX)
return -EINVAL;
cotable_res = vmw_context_cotable(ctx_node->res, SVGA_COTABLE_DXQUERY);
ret = vmw_cotable_notify(cotable_res, cmd->q.queryId);
vmw_resource_unreference(&cotable_res);
return ret;
}
static int vmw_cmd_dx_bind_query(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_dx_bind_query_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdDXBindQuery q;
} *cmd;
struct vmw_dma_buffer *vmw_bo;
int ret;
cmd = container_of(header, struct vmw_dx_bind_query_cmd, header);
ret = vmw_translate_mob_ptr(dev_priv, sw_context, &cmd->q.mobid,
&vmw_bo);
if (ret != 0)
return ret;
sw_context->dx_query_mob = vmw_bo;
sw_context->dx_query_ctx = sw_context->dx_ctx_node->res;
vmw_dmabuf_unreference(&vmw_bo);
return ret;
}
static int vmw_cmd_begin_gb_query(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_begin_gb_query_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdBeginGBQuery q;
} *cmd;
cmd = container_of(header, struct vmw_begin_gb_query_cmd,
header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->q.cid,
NULL);
}
static int vmw_cmd_begin_query(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_begin_query_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdBeginQuery q;
} *cmd;
cmd = container_of(header, struct vmw_begin_query_cmd,
header);
if (unlikely(dev_priv->has_mob)) {
struct {
SVGA3dCmdHeader header;
SVGA3dCmdBeginGBQuery q;
} gb_cmd;
BUG_ON(sizeof(gb_cmd) != sizeof(*cmd));
gb_cmd.header.id = SVGA_3D_CMD_BEGIN_GB_QUERY;
gb_cmd.header.size = cmd->header.size;
gb_cmd.q.cid = cmd->q.cid;
gb_cmd.q.type = cmd->q.type;
memcpy(cmd, &gb_cmd, sizeof(*cmd));
return vmw_cmd_begin_gb_query(dev_priv, sw_context, header);
}
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->q.cid,
NULL);
}
static int vmw_cmd_end_gb_query(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_dma_buffer *vmw_bo;
struct vmw_query_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdEndGBQuery q;
} *cmd;
int ret;
cmd = container_of(header, struct vmw_query_cmd, header);
ret = vmw_cmd_cid_check(dev_priv, sw_context, header);
if (unlikely(ret != 0))
return ret;
ret = vmw_translate_mob_ptr(dev_priv, sw_context,
&cmd->q.mobid,
&vmw_bo);
if (unlikely(ret != 0))
return ret;
ret = vmw_query_bo_switch_prepare(dev_priv, vmw_bo, sw_context);
vmw_dmabuf_unreference(&vmw_bo);
return ret;
}
static int vmw_cmd_end_query(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_dma_buffer *vmw_bo;
struct vmw_query_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdEndQuery q;
} *cmd;
int ret;
cmd = container_of(header, struct vmw_query_cmd, header);
if (dev_priv->has_mob) {
struct {
SVGA3dCmdHeader header;
SVGA3dCmdEndGBQuery q;
} gb_cmd;
BUG_ON(sizeof(gb_cmd) != sizeof(*cmd));
gb_cmd.header.id = SVGA_3D_CMD_END_GB_QUERY;
gb_cmd.header.size = cmd->header.size;
gb_cmd.q.cid = cmd->q.cid;
gb_cmd.q.type = cmd->q.type;
gb_cmd.q.mobid = cmd->q.guestResult.gmrId;
gb_cmd.q.offset = cmd->q.guestResult.offset;
memcpy(cmd, &gb_cmd, sizeof(*cmd));
return vmw_cmd_end_gb_query(dev_priv, sw_context, header);
}
ret = vmw_cmd_cid_check(dev_priv, sw_context, header);
if (unlikely(ret != 0))
return ret;
ret = vmw_translate_guest_ptr(dev_priv, sw_context,
&cmd->q.guestResult,
&vmw_bo);
if (unlikely(ret != 0))
return ret;
ret = vmw_query_bo_switch_prepare(dev_priv, vmw_bo, sw_context);
vmw_dmabuf_unreference(&vmw_bo);
return ret;
}
static int vmw_cmd_wait_gb_query(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_dma_buffer *vmw_bo;
struct vmw_query_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdWaitForGBQuery q;
} *cmd;
int ret;
cmd = container_of(header, struct vmw_query_cmd, header);
ret = vmw_cmd_cid_check(dev_priv, sw_context, header);
if (unlikely(ret != 0))
return ret;
ret = vmw_translate_mob_ptr(dev_priv, sw_context,
&cmd->q.mobid,
&vmw_bo);
if (unlikely(ret != 0))
return ret;
vmw_dmabuf_unreference(&vmw_bo);
return 0;
}
static int vmw_cmd_wait_query(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_dma_buffer *vmw_bo;
struct vmw_query_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdWaitForQuery q;
} *cmd;
int ret;
cmd = container_of(header, struct vmw_query_cmd, header);
if (dev_priv->has_mob) {
struct {
SVGA3dCmdHeader header;
SVGA3dCmdWaitForGBQuery q;
} gb_cmd;
BUG_ON(sizeof(gb_cmd) != sizeof(*cmd));
gb_cmd.header.id = SVGA_3D_CMD_WAIT_FOR_GB_QUERY;
gb_cmd.header.size = cmd->header.size;
gb_cmd.q.cid = cmd->q.cid;
gb_cmd.q.type = cmd->q.type;
gb_cmd.q.mobid = cmd->q.guestResult.gmrId;
gb_cmd.q.offset = cmd->q.guestResult.offset;
memcpy(cmd, &gb_cmd, sizeof(*cmd));
return vmw_cmd_wait_gb_query(dev_priv, sw_context, header);
}
ret = vmw_cmd_cid_check(dev_priv, sw_context, header);
if (unlikely(ret != 0))
return ret;
ret = vmw_translate_guest_ptr(dev_priv, sw_context,
&cmd->q.guestResult,
&vmw_bo);
if (unlikely(ret != 0))
return ret;
vmw_dmabuf_unreference(&vmw_bo);
return 0;
}
static int vmw_cmd_dma(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_dma_buffer *vmw_bo = NULL;
struct vmw_surface *srf = NULL;
struct vmw_dma_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdSurfaceDMA dma;
} *cmd;
int ret;
SVGA3dCmdSurfaceDMASuffix *suffix;
uint32_t bo_size;
cmd = container_of(header, struct vmw_dma_cmd, header);
suffix = (SVGA3dCmdSurfaceDMASuffix *)((unsigned long) &cmd->dma +
header->size - sizeof(*suffix));
if (unlikely(suffix->suffixSize != sizeof(*suffix))) {
DRM_ERROR("Invalid DMA suffix size.\n");
return -EINVAL;
}
ret = vmw_translate_guest_ptr(dev_priv, sw_context,
&cmd->dma.guest.ptr,
&vmw_bo);
if (unlikely(ret != 0))
return ret;
bo_size = vmw_bo->base.num_pages * PAGE_SIZE;
if (unlikely(cmd->dma.guest.ptr.offset > bo_size)) {
DRM_ERROR("Invalid DMA offset.\n");
return -EINVAL;
}
bo_size -= cmd->dma.guest.ptr.offset;
if (unlikely(suffix->maximumOffset > bo_size))
suffix->maximumOffset = bo_size;
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter, &cmd->dma.host.sid,
NULL);
if (unlikely(ret != 0)) {
if (unlikely(ret != -ERESTARTSYS))
DRM_ERROR("could not find surface for DMA.\n");
goto out_no_surface;
}
srf = vmw_res_to_srf(sw_context->res_cache[vmw_res_surface].res);
vmw_kms_cursor_snoop(srf, sw_context->fp->tfile, &vmw_bo->base,
header);
out_no_surface:
vmw_dmabuf_unreference(&vmw_bo);
return ret;
}
static int vmw_cmd_draw(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_draw_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdDrawPrimitives body;
} *cmd;
SVGA3dVertexDecl *decl = (SVGA3dVertexDecl *)(
(unsigned long)header + sizeof(*cmd));
SVGA3dPrimitiveRange *range;
uint32_t i;
uint32_t maxnum;
int ret;
ret = vmw_cmd_cid_check(dev_priv, sw_context, header);
if (unlikely(ret != 0))
return ret;
cmd = container_of(header, struct vmw_draw_cmd, header);
maxnum = (header->size - sizeof(cmd->body)) / sizeof(*decl);
if (unlikely(cmd->body.numVertexDecls > maxnum)) {
DRM_ERROR("Illegal number of vertex declarations.\n");
return -EINVAL;
}
for (i = 0; i < cmd->body.numVertexDecls; ++i, ++decl) {
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&decl->array.surfaceId, NULL);
if (unlikely(ret != 0))
return ret;
}
maxnum = (header->size - sizeof(cmd->body) -
cmd->body.numVertexDecls * sizeof(*decl)) / sizeof(*range);
if (unlikely(cmd->body.numRanges > maxnum)) {
DRM_ERROR("Illegal number of index ranges.\n");
return -EINVAL;
}
range = (SVGA3dPrimitiveRange *) decl;
for (i = 0; i < cmd->body.numRanges; ++i, ++range) {
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&range->indexArray.surfaceId, NULL);
if (unlikely(ret != 0))
return ret;
}
return 0;
}
static int vmw_cmd_tex_state(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_tex_state_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdSetTextureState state;
} *cmd;
SVGA3dTextureState *last_state = (SVGA3dTextureState *)
((unsigned long) header + header->size + sizeof(header));
SVGA3dTextureState *cur_state = (SVGA3dTextureState *)
((unsigned long) header + sizeof(struct vmw_tex_state_cmd));
struct vmw_resource_val_node *ctx_node;
struct vmw_resource_val_node *res_node;
int ret;
cmd = container_of(header, struct vmw_tex_state_cmd,
header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->state.cid,
&ctx_node);
if (unlikely(ret != 0))
return ret;
for (; cur_state < last_state; ++cur_state) {
if (likely(cur_state->name != SVGA3D_TS_BIND_TEXTURE))
continue;
if (cur_state->stage >= SVGA3D_NUM_TEXTURE_UNITS) {
DRM_ERROR("Illegal texture/sampler unit %u.\n",
(unsigned) cur_state->stage);
return -EINVAL;
}
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cur_state->value, &res_node);
if (unlikely(ret != 0))
return ret;
if (dev_priv->has_mob) {
struct vmw_ctx_bindinfo_tex binding;
binding.bi.ctx = ctx_node->res;
binding.bi.res = res_node ? res_node->res : NULL;
binding.bi.bt = vmw_ctx_binding_tex;
binding.texture_stage = cur_state->stage;
vmw_binding_add(ctx_node->staged_bindings, &binding.bi,
0, binding.texture_stage);
}
}
return 0;
}
static int vmw_cmd_check_define_gmrfb(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
void *buf)
{
struct vmw_dma_buffer *vmw_bo;
int ret;
struct {
uint32_t header;
SVGAFifoCmdDefineGMRFB body;
} *cmd = buf;
ret = vmw_translate_guest_ptr(dev_priv, sw_context,
&cmd->body.ptr,
&vmw_bo);
if (unlikely(ret != 0))
return ret;
vmw_dmabuf_unreference(&vmw_bo);
return ret;
}
static int vmw_cmd_res_switch_backup(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
struct vmw_resource_val_node *val_node,
uint32_t *buf_id,
unsigned long backup_offset)
{
struct vmw_dma_buffer *dma_buf;
int ret;
ret = vmw_translate_mob_ptr(dev_priv, sw_context, buf_id, &dma_buf);
if (ret)
return ret;
val_node->switching_backup = true;
if (val_node->first_usage)
val_node->no_buffer_needed = true;
vmw_dmabuf_unreference(&val_node->new_backup);
val_node->new_backup = dma_buf;
val_node->new_backup_offset = backup_offset;
return 0;
}
static int vmw_cmd_switch_backup(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
enum vmw_res_type res_type,
const struct vmw_user_resource_conv
*converter,
uint32_t *res_id,
uint32_t *buf_id,
unsigned long backup_offset)
{
struct vmw_resource_val_node *val_node;
int ret;
ret = vmw_cmd_res_check(dev_priv, sw_context, res_type,
converter, res_id, &val_node);
if (ret)
return ret;
return vmw_cmd_res_switch_backup(dev_priv, sw_context, val_node,
buf_id, backup_offset);
}
static int vmw_cmd_bind_gb_surface(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_bind_gb_surface_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdBindGBSurface body;
} *cmd;
cmd = container_of(header, struct vmw_bind_gb_surface_cmd, header);
return vmw_cmd_switch_backup(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.sid, &cmd->body.mobid,
0);
}
static int vmw_cmd_update_gb_image(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_gb_surface_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdUpdateGBImage body;
} *cmd;
cmd = container_of(header, struct vmw_gb_surface_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.image.sid, NULL);
}
static int vmw_cmd_update_gb_surface(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_gb_surface_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdUpdateGBSurface body;
} *cmd;
cmd = container_of(header, struct vmw_gb_surface_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.sid, NULL);
}
static int vmw_cmd_readback_gb_image(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_gb_surface_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdReadbackGBImage body;
} *cmd;
cmd = container_of(header, struct vmw_gb_surface_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.image.sid, NULL);
}
static int vmw_cmd_readback_gb_surface(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_gb_surface_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdReadbackGBSurface body;
} *cmd;
cmd = container_of(header, struct vmw_gb_surface_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.sid, NULL);
}
static int vmw_cmd_invalidate_gb_image(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_gb_surface_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdInvalidateGBImage body;
} *cmd;
cmd = container_of(header, struct vmw_gb_surface_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.image.sid, NULL);
}
static int vmw_cmd_invalidate_gb_surface(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_gb_surface_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdInvalidateGBSurface body;
} *cmd;
cmd = container_of(header, struct vmw_gb_surface_cmd, header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.sid, NULL);
}
static int vmw_cmd_shader_define(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_shader_define_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdDefineShader body;
} *cmd;
int ret;
size_t size;
struct vmw_resource_val_node *val;
cmd = container_of(header, struct vmw_shader_define_cmd,
header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->body.cid,
&val);
if (unlikely(ret != 0))
return ret;
if (unlikely(!dev_priv->has_mob))
return 0;
size = cmd->header.size - sizeof(cmd->body);
ret = vmw_compat_shader_add(dev_priv,
vmw_context_res_man(val->res),
cmd->body.shid, cmd + 1,
cmd->body.type, size,
&sw_context->staged_cmd_res);
if (unlikely(ret != 0))
return ret;
return vmw_resource_relocation_add(&sw_context->res_relocations,
NULL,
vmw_ptr_diff(sw_context->buf_start,
&cmd->header.id),
vmw_res_rel_nop);
}
static int vmw_cmd_shader_destroy(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_shader_destroy_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdDestroyShader body;
} *cmd;
int ret;
struct vmw_resource_val_node *val;
cmd = container_of(header, struct vmw_shader_destroy_cmd,
header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->body.cid,
&val);
if (unlikely(ret != 0))
return ret;
if (unlikely(!dev_priv->has_mob))
return 0;
ret = vmw_shader_remove(vmw_context_res_man(val->res),
cmd->body.shid,
cmd->body.type,
&sw_context->staged_cmd_res);
if (unlikely(ret != 0))
return ret;
return vmw_resource_relocation_add(&sw_context->res_relocations,
NULL,
vmw_ptr_diff(sw_context->buf_start,
&cmd->header.id),
vmw_res_rel_nop);
}
static int vmw_cmd_set_shader(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_set_shader_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdSetShader body;
} *cmd;
struct vmw_resource_val_node *ctx_node, *res_node = NULL;
struct vmw_ctx_bindinfo_shader binding;
struct vmw_resource *res = NULL;
int ret;
cmd = container_of(header, struct vmw_set_shader_cmd,
header);
if (cmd->body.type >= SVGA3D_SHADERTYPE_PREDX_MAX) {
DRM_ERROR("Illegal shader type %u.\n",
(unsigned) cmd->body.type);
return -EINVAL;
}
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->body.cid,
&ctx_node);
if (unlikely(ret != 0))
return ret;
if (!dev_priv->has_mob)
return 0;
if (cmd->body.shid != SVGA3D_INVALID_ID) {
res = vmw_shader_lookup(vmw_context_res_man(ctx_node->res),
cmd->body.shid,
cmd->body.type);
if (!IS_ERR(res)) {
ret = vmw_cmd_res_reloc_add(dev_priv, sw_context,
&cmd->body.shid, res,
&res_node);
vmw_resource_unreference(&res);
if (unlikely(ret != 0))
return ret;
}
}
if (!res_node) {
ret = vmw_cmd_res_check(dev_priv, sw_context,
vmw_res_shader,
user_shader_converter,
&cmd->body.shid, &res_node);
if (unlikely(ret != 0))
return ret;
}
binding.bi.ctx = ctx_node->res;
binding.bi.res = res_node ? res_node->res : NULL;
binding.bi.bt = vmw_ctx_binding_shader;
binding.shader_slot = cmd->body.type - SVGA3D_SHADERTYPE_MIN;
vmw_binding_add(ctx_node->staged_bindings, &binding.bi,
binding.shader_slot, 0);
return 0;
}
static int vmw_cmd_set_shader_const(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_set_shader_const_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdSetShaderConst body;
} *cmd;
int ret;
cmd = container_of(header, struct vmw_set_shader_const_cmd,
header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->body.cid,
NULL);
if (unlikely(ret != 0))
return ret;
if (dev_priv->has_mob)
header->id = SVGA_3D_CMD_SET_GB_SHADERCONSTS_INLINE;
return 0;
}
static int vmw_cmd_bind_gb_shader(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_bind_gb_shader_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdBindGBShader body;
} *cmd;
cmd = container_of(header, struct vmw_bind_gb_shader_cmd,
header);
return vmw_cmd_switch_backup(dev_priv, sw_context, vmw_res_shader,
user_shader_converter,
&cmd->body.shid, &cmd->body.mobid,
cmd->body.offsetInBytes);
}
static int
vmw_cmd_dx_set_single_constant_buffer(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetSingleConstantBuffer body;
} *cmd;
struct vmw_resource_val_node *res_node = NULL;
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_ctx_bindinfo_cb binding;
int ret;
if (unlikely(ctx_node == NULL)) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
cmd = container_of(header, typeof(*cmd), header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.sid, &res_node);
if (unlikely(ret != 0))
return ret;
binding.bi.ctx = ctx_node->res;
binding.bi.res = res_node ? res_node->res : NULL;
binding.bi.bt = vmw_ctx_binding_cb;
binding.shader_slot = cmd->body.type - SVGA3D_SHADERTYPE_MIN;
binding.offset = cmd->body.offsetInBytes;
binding.size = cmd->body.sizeInBytes;
binding.slot = cmd->body.slot;
if (binding.shader_slot >= SVGA3D_NUM_SHADERTYPE_DX10 ||
binding.slot >= SVGA3D_DX_MAX_CONSTBUFFERS) {
DRM_ERROR("Illegal const buffer shader %u slot %u.\n",
(unsigned) cmd->body.type,
(unsigned) binding.slot);
return -EINVAL;
}
vmw_binding_add(ctx_node->staged_bindings, &binding.bi,
binding.shader_slot, binding.slot);
return 0;
}
static int vmw_cmd_dx_set_shader_res(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetShaderResources body;
} *cmd = container_of(header, typeof(*cmd), header);
u32 num_sr_view = (cmd->header.size - sizeof(cmd->body)) /
sizeof(SVGA3dShaderResourceViewId);
if ((u64) cmd->body.startView + (u64) num_sr_view >
(u64) SVGA3D_DX_MAX_SRVIEWS ||
cmd->body.type >= SVGA3D_SHADERTYPE_DX10_MAX) {
DRM_ERROR("Invalid shader binding.\n");
return -EINVAL;
}
return vmw_view_bindings_add(sw_context, vmw_view_sr,
vmw_ctx_binding_sr,
cmd->body.type - SVGA3D_SHADERTYPE_MIN,
(void *) &cmd[1], num_sr_view,
cmd->body.startView);
}
static int vmw_cmd_dx_set_shader(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetShader body;
} *cmd;
struct vmw_resource *res = NULL;
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_ctx_bindinfo_shader binding;
int ret = 0;
if (unlikely(ctx_node == NULL)) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
cmd = container_of(header, typeof(*cmd), header);
if (cmd->body.type >= SVGA3D_SHADERTYPE_DX10_MAX) {
DRM_ERROR("Illegal shader type %u.\n",
(unsigned) cmd->body.type);
return -EINVAL;
}
if (cmd->body.shaderId != SVGA3D_INVALID_ID) {
res = vmw_shader_lookup(sw_context->man, cmd->body.shaderId, 0);
if (IS_ERR(res)) {
DRM_ERROR("Could not find shader for binding.\n");
return PTR_ERR(res);
}
ret = vmw_resource_val_add(sw_context, res, NULL);
if (ret)
goto out_unref;
}
binding.bi.ctx = ctx_node->res;
binding.bi.res = res;
binding.bi.bt = vmw_ctx_binding_dx_shader;
binding.shader_slot = cmd->body.type - SVGA3D_SHADERTYPE_MIN;
vmw_binding_add(ctx_node->staged_bindings, &binding.bi,
binding.shader_slot, 0);
out_unref:
if (res)
vmw_resource_unreference(&res);
return ret;
}
static int vmw_cmd_dx_set_vertex_buffers(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_ctx_bindinfo_vb binding;
struct vmw_resource_val_node *res_node;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetVertexBuffers body;
SVGA3dVertexBuffer buf[];
} *cmd;
int i, ret, num;
if (unlikely(ctx_node == NULL)) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
cmd = container_of(header, typeof(*cmd), header);
num = (cmd->header.size - sizeof(cmd->body)) /
sizeof(SVGA3dVertexBuffer);
if ((u64)num + (u64)cmd->body.startBuffer >
(u64)SVGA3D_DX_MAX_VERTEXBUFFERS) {
DRM_ERROR("Invalid number of vertex buffers.\n");
return -EINVAL;
}
for (i = 0; i < num; i++) {
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->buf[i].sid, &res_node);
if (unlikely(ret != 0))
return ret;
binding.bi.ctx = ctx_node->res;
binding.bi.bt = vmw_ctx_binding_vb;
binding.bi.res = ((res_node) ? res_node->res : NULL);
binding.offset = cmd->buf[i].offset;
binding.stride = cmd->buf[i].stride;
binding.slot = i + cmd->body.startBuffer;
vmw_binding_add(ctx_node->staged_bindings, &binding.bi,
0, binding.slot);
}
return 0;
}
static int vmw_cmd_dx_set_index_buffer(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_ctx_bindinfo_ib binding;
struct vmw_resource_val_node *res_node;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetIndexBuffer body;
} *cmd;
int ret;
if (unlikely(ctx_node == NULL)) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
cmd = container_of(header, typeof(*cmd), header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.sid, &res_node);
if (unlikely(ret != 0))
return ret;
binding.bi.ctx = ctx_node->res;
binding.bi.res = ((res_node) ? res_node->res : NULL);
binding.bi.bt = vmw_ctx_binding_ib;
binding.offset = cmd->body.offset;
binding.format = cmd->body.format;
vmw_binding_add(ctx_node->staged_bindings, &binding.bi, 0, 0);
return 0;
}
static int vmw_cmd_dx_set_rendertargets(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetRenderTargets body;
} *cmd = container_of(header, typeof(*cmd), header);
int ret;
u32 num_rt_view = (cmd->header.size - sizeof(cmd->body)) /
sizeof(SVGA3dRenderTargetViewId);
if (num_rt_view > SVGA3D_MAX_SIMULTANEOUS_RENDER_TARGETS) {
DRM_ERROR("Invalid DX Rendertarget binding.\n");
return -EINVAL;
}
ret = vmw_view_bindings_add(sw_context, vmw_view_ds,
vmw_ctx_binding_ds, 0,
&cmd->body.depthStencilViewId, 1, 0);
if (ret)
return ret;
return vmw_view_bindings_add(sw_context, vmw_view_rt,
vmw_ctx_binding_dx_rt, 0,
(void *)&cmd[1], num_rt_view, 0);
}
static int vmw_cmd_dx_clear_rendertarget_view(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXClearRenderTargetView body;
} *cmd = container_of(header, typeof(*cmd), header);
return vmw_view_id_val_add(sw_context, vmw_view_rt,
cmd->body.renderTargetViewId);
}
static int vmw_cmd_dx_clear_depthstencil_view(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXClearDepthStencilView body;
} *cmd = container_of(header, typeof(*cmd), header);
return vmw_view_id_val_add(sw_context, vmw_view_ds,
cmd->body.depthStencilViewId);
}
static int vmw_cmd_dx_view_define(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_resource_val_node *srf_node;
struct vmw_resource *res;
enum vmw_view_type view_type;
int ret;
struct {
SVGA3dCmdHeader header;
uint32 defined_id;
uint32 sid;
} *cmd;
if (unlikely(ctx_node == NULL)) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
view_type = vmw_view_cmd_to_type(header->id);
cmd = container_of(header, typeof(*cmd), header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->sid, &srf_node);
if (unlikely(ret != 0))
return ret;
res = vmw_context_cotable(ctx_node->res, vmw_view_cotables[view_type]);
ret = vmw_cotable_notify(res, cmd->defined_id);
vmw_resource_unreference(&res);
if (unlikely(ret != 0))
return ret;
return vmw_view_add(sw_context->man,
ctx_node->res,
srf_node->res,
view_type,
cmd->defined_id,
header,
header->size + sizeof(*header),
&sw_context->staged_cmd_res);
}
static int vmw_cmd_dx_set_so_targets(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_ctx_bindinfo_so binding;
struct vmw_resource_val_node *res_node;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetSOTargets body;
SVGA3dSoTarget targets[];
} *cmd;
int i, ret, num;
if (unlikely(ctx_node == NULL)) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
cmd = container_of(header, typeof(*cmd), header);
num = (cmd->header.size - sizeof(cmd->body)) /
sizeof(SVGA3dSoTarget);
if (num > SVGA3D_DX_MAX_SOTARGETS) {
DRM_ERROR("Invalid DX SO binding.\n");
return -EINVAL;
}
for (i = 0; i < num; i++) {
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->targets[i].sid, &res_node);
if (unlikely(ret != 0))
return ret;
binding.bi.ctx = ctx_node->res;
binding.bi.res = ((res_node) ? res_node->res : NULL);
binding.bi.bt = vmw_ctx_binding_so,
binding.offset = cmd->targets[i].offset;
binding.size = cmd->targets[i].sizeInBytes;
binding.slot = i;
vmw_binding_add(ctx_node->staged_bindings, &binding.bi,
0, binding.slot);
}
return 0;
}
static int vmw_cmd_dx_so_define(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_resource *res;
struct {
SVGA3dCmdHeader header;
uint32 defined_id;
} *cmd;
enum vmw_so_type so_type;
int ret;
if (unlikely(ctx_node == NULL)) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
so_type = vmw_so_cmd_to_type(header->id);
res = vmw_context_cotable(ctx_node->res, vmw_so_cotables[so_type]);
cmd = container_of(header, typeof(*cmd), header);
ret = vmw_cotable_notify(res, cmd->defined_id);
vmw_resource_unreference(&res);
return ret;
}
static int vmw_cmd_dx_check_subresource(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
union {
SVGA3dCmdDXReadbackSubResource r_body;
SVGA3dCmdDXInvalidateSubResource i_body;
SVGA3dCmdDXUpdateSubResource u_body;
SVGA3dSurfaceId sid;
};
} *cmd;
BUILD_BUG_ON(offsetof(typeof(*cmd), r_body.sid) !=
offsetof(typeof(*cmd), sid));
BUILD_BUG_ON(offsetof(typeof(*cmd), i_body.sid) !=
offsetof(typeof(*cmd), sid));
BUILD_BUG_ON(offsetof(typeof(*cmd), u_body.sid) !=
offsetof(typeof(*cmd), sid));
cmd = container_of(header, typeof(*cmd), header);
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->sid, NULL);
}
static int vmw_cmd_dx_cid_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
if (unlikely(ctx_node == NULL)) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
return 0;
}
static int vmw_cmd_dx_view_remove(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct {
SVGA3dCmdHeader header;
union vmw_view_destroy body;
} *cmd = container_of(header, typeof(*cmd), header);
enum vmw_view_type view_type = vmw_view_cmd_to_type(header->id);
struct vmw_resource *view;
int ret;
if (!ctx_node) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
ret = vmw_view_remove(sw_context->man,
cmd->body.view_id, view_type,
&sw_context->staged_cmd_res,
&view);
if (ret || !view)
return ret;
return vmw_resource_relocation_add(&sw_context->res_relocations,
view,
vmw_ptr_diff(sw_context->buf_start,
&cmd->header.id),
vmw_res_rel_cond_nop);
}
static int vmw_cmd_dx_define_shader(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct vmw_resource *res;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXDefineShader body;
} *cmd = container_of(header, typeof(*cmd), header);
int ret;
if (!ctx_node) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
res = vmw_context_cotable(ctx_node->res, SVGA_COTABLE_DXSHADER);
ret = vmw_cotable_notify(res, cmd->body.shaderId);
vmw_resource_unreference(&res);
if (ret)
return ret;
return vmw_dx_shader_add(sw_context->man, ctx_node->res,
cmd->body.shaderId, cmd->body.type,
&sw_context->staged_cmd_res);
}
static int vmw_cmd_dx_destroy_shader(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node = sw_context->dx_ctx_node;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXDestroyShader body;
} *cmd = container_of(header, typeof(*cmd), header);
int ret;
if (!ctx_node) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
ret = vmw_shader_remove(sw_context->man, cmd->body.shaderId, 0,
&sw_context->staged_cmd_res);
if (ret)
DRM_ERROR("Could not find shader to remove.\n");
return ret;
}
static int vmw_cmd_dx_bind_shader(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct vmw_resource_val_node *ctx_node;
struct vmw_resource_val_node *res_node;
struct vmw_resource *res;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXBindShader body;
} *cmd = container_of(header, typeof(*cmd), header);
int ret;
if (cmd->body.cid != SVGA3D_INVALID_ID) {
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter,
&cmd->body.cid, &ctx_node);
if (ret)
return ret;
} else {
ctx_node = sw_context->dx_ctx_node;
if (!ctx_node) {
DRM_ERROR("DX Context not set.\n");
return -EINVAL;
}
}
res = vmw_shader_lookup(vmw_context_res_man(ctx_node->res),
cmd->body.shid, 0);
if (IS_ERR(res)) {
DRM_ERROR("Could not find shader to bind.\n");
return PTR_ERR(res);
}
ret = vmw_resource_val_add(sw_context, res, &res_node);
if (ret) {
DRM_ERROR("Error creating resource validation node.\n");
goto out_unref;
}
ret = vmw_cmd_res_switch_backup(dev_priv, sw_context, res_node,
&cmd->body.mobid,
cmd->body.offsetInBytes);
out_unref:
vmw_resource_unreference(&res);
return ret;
}
static int vmw_cmd_dx_genmips(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXGenMips body;
} *cmd = container_of(header, typeof(*cmd), header);
return vmw_view_id_val_add(sw_context, vmw_view_sr,
cmd->body.shaderResourceViewId);
}
static int vmw_cmd_dx_transfer_from_buffer(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXTransferFromBuffer body;
} *cmd = container_of(header, typeof(*cmd), header);
int ret;
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.srcSid, NULL);
if (ret != 0)
return ret;
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.destSid, NULL);
}
static int vmw_cmd_check_not_3d(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
void *buf, uint32_t *size)
{
uint32_t size_remaining = *size;
uint32_t cmd_id;
cmd_id = ((uint32_t *)buf)[0];
switch (cmd_id) {
case SVGA_CMD_UPDATE:
*size = sizeof(uint32_t) + sizeof(SVGAFifoCmdUpdate);
break;
case SVGA_CMD_DEFINE_GMRFB:
*size = sizeof(uint32_t) + sizeof(SVGAFifoCmdDefineGMRFB);
break;
case SVGA_CMD_BLIT_GMRFB_TO_SCREEN:
*size = sizeof(uint32_t) + sizeof(SVGAFifoCmdBlitGMRFBToScreen);
break;
case SVGA_CMD_BLIT_SCREEN_TO_GMRFB:
*size = sizeof(uint32_t) + sizeof(SVGAFifoCmdBlitGMRFBToScreen);
break;
default:
DRM_ERROR("Unsupported SVGA command: %u.\n", cmd_id);
return -EINVAL;
}
if (*size > size_remaining) {
DRM_ERROR("Invalid SVGA command (size mismatch):"
" %u.\n", cmd_id);
return -EINVAL;
}
if (unlikely(!sw_context->kernel)) {
DRM_ERROR("Kernel only SVGA command: %u.\n", cmd_id);
return -EPERM;
}
if (cmd_id == SVGA_CMD_DEFINE_GMRFB)
return vmw_cmd_check_define_gmrfb(dev_priv, sw_context, buf);
return 0;
}
static int vmw_cmd_check(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
void *buf, uint32_t *size)
{
uint32_t cmd_id;
uint32_t size_remaining = *size;
SVGA3dCmdHeader *header = (SVGA3dCmdHeader *) buf;
int ret;
const struct vmw_cmd_entry *entry;
bool gb = dev_priv->capabilities & SVGA_CAP_GBOBJECTS;
cmd_id = ((uint32_t *)buf)[0];
if (unlikely(cmd_id < SVGA_CMD_MAX))
return vmw_cmd_check_not_3d(dev_priv, sw_context, buf, size);
cmd_id = header->id;
*size = header->size + sizeof(SVGA3dCmdHeader);
cmd_id -= SVGA_3D_CMD_BASE;
if (unlikely(*size > size_remaining))
goto out_invalid;
if (unlikely(cmd_id >= SVGA_3D_CMD_MAX - SVGA_3D_CMD_BASE))
goto out_invalid;
entry = &vmw_cmd_entries[cmd_id];
if (unlikely(!entry->func))
goto out_invalid;
if (unlikely(!entry->user_allow && !sw_context->kernel))
goto out_privileged;
if (unlikely(entry->gb_disable && gb))
goto out_old;
if (unlikely(entry->gb_enable && !gb))
goto out_new;
ret = entry->func(dev_priv, sw_context, header);
if (unlikely(ret != 0))
goto out_invalid;
return 0;
out_invalid:
DRM_ERROR("Invalid SVGA3D command: %d\n",
cmd_id + SVGA_3D_CMD_BASE);
return -EINVAL;
out_privileged:
DRM_ERROR("Privileged SVGA3D command: %d\n",
cmd_id + SVGA_3D_CMD_BASE);
return -EPERM;
out_old:
DRM_ERROR("Deprecated (disallowed) SVGA3D command: %d\n",
cmd_id + SVGA_3D_CMD_BASE);
return -EINVAL;
out_new:
DRM_ERROR("SVGA3D command: %d not supported by virtual hardware.\n",
cmd_id + SVGA_3D_CMD_BASE);
return -EINVAL;
}
static int vmw_cmd_check_all(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
void *buf,
uint32_t size)
{
int32_t cur_size = size;
int ret;
sw_context->buf_start = buf;
while (cur_size > 0) {
size = cur_size;
ret = vmw_cmd_check(dev_priv, sw_context, buf, &size);
if (unlikely(ret != 0))
return ret;
buf = (void *)((unsigned long) buf + size);
cur_size -= size;
}
if (unlikely(cur_size != 0)) {
DRM_ERROR("Command verifier out of sync.\n");
return -EINVAL;
}
return 0;
}
static void vmw_free_relocations(struct vmw_sw_context *sw_context)
{
sw_context->cur_reloc = 0;
}
static void vmw_apply_relocations(struct vmw_sw_context *sw_context)
{
uint32_t i;
struct vmw_relocation *reloc;
struct ttm_validate_buffer *validate;
struct ttm_buffer_object *bo;
for (i = 0; i < sw_context->cur_reloc; ++i) {
reloc = &sw_context->relocs[i];
validate = &sw_context->val_bufs[reloc->index].base;
bo = validate->bo;
switch (bo->mem.mem_type) {
case TTM_PL_VRAM:
reloc->location->offset += bo->offset;
reloc->location->gmrId = SVGA_GMR_FRAMEBUFFER;
break;
case VMW_PL_GMR:
reloc->location->gmrId = bo->mem.start;
break;
case VMW_PL_MOB:
*reloc->mob_loc = bo->mem.start;
break;
default:
BUG();
}
}
vmw_free_relocations(sw_context);
}
static void vmw_resource_list_unreference(struct vmw_sw_context *sw_context,
struct list_head *list)
{
struct vmw_resource_val_node *val, *val_next;
list_for_each_entry_safe(val, val_next, list, head) {
list_del_init(&val->head);
vmw_resource_unreference(&val->res);
if (val->staged_bindings) {
if (val->staged_bindings != sw_context->staged_bindings)
vmw_binding_state_free(val->staged_bindings);
else
sw_context->staged_bindings_inuse = false;
val->staged_bindings = NULL;
}
kfree(val);
}
}
static void vmw_clear_validations(struct vmw_sw_context *sw_context)
{
struct vmw_validate_buffer *entry, *next;
struct vmw_resource_val_node *val;
list_for_each_entry_safe(entry, next, &sw_context->validate_nodes,
base.head) {
list_del(&entry->base.head);
ttm_bo_unref(&entry->base.bo);
(void) drm_ht_remove_item(&sw_context->res_ht, &entry->hash);
sw_context->cur_val_buf--;
}
BUG_ON(sw_context->cur_val_buf != 0);
list_for_each_entry(val, &sw_context->resource_list, head)
(void) drm_ht_remove_item(&sw_context->res_ht, &val->hash);
}
int vmw_validate_single_buffer(struct vmw_private *dev_priv,
struct ttm_buffer_object *bo,
bool interruptible,
bool validate_as_mob)
{
struct vmw_dma_buffer *vbo = container_of(bo, struct vmw_dma_buffer,
base);
int ret;
if (vbo->pin_count > 0)
return 0;
if (validate_as_mob)
return ttm_bo_validate(bo, &vmw_mob_placement, interruptible,
false);
ret = ttm_bo_validate(bo, &vmw_vram_gmr_placement, interruptible,
false);
if (likely(ret == 0 || ret == -ERESTARTSYS))
return ret;
ret = ttm_bo_validate(bo, &vmw_vram_placement, interruptible, false);
return ret;
}
static int vmw_validate_buffers(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context)
{
struct vmw_validate_buffer *entry;
int ret;
list_for_each_entry(entry, &sw_context->validate_nodes, base.head) {
ret = vmw_validate_single_buffer(dev_priv, entry->base.bo,
true,
entry->validate_as_mob);
if (unlikely(ret != 0))
return ret;
}
return 0;
}
static int vmw_resize_cmd_bounce(struct vmw_sw_context *sw_context,
uint32_t size)
{
if (likely(sw_context->cmd_bounce_size >= size))
return 0;
if (sw_context->cmd_bounce_size == 0)
sw_context->cmd_bounce_size = VMWGFX_CMD_BOUNCE_INIT_SIZE;
while (sw_context->cmd_bounce_size < size) {
sw_context->cmd_bounce_size =
PAGE_ALIGN(sw_context->cmd_bounce_size +
(sw_context->cmd_bounce_size >> 1));
}
vfree(sw_context->cmd_bounce);
sw_context->cmd_bounce = vmalloc(sw_context->cmd_bounce_size);
if (sw_context->cmd_bounce == NULL) {
DRM_ERROR("Failed to allocate command bounce buffer.\n");
sw_context->cmd_bounce_size = 0;
return -ENOMEM;
}
return 0;
}
int vmw_execbuf_fence_commands(struct drm_file *file_priv,
struct vmw_private *dev_priv,
struct vmw_fence_obj **p_fence,
uint32_t *p_handle)
{
uint32_t sequence;
int ret;
bool synced = false;
BUG_ON(p_handle != NULL && file_priv == NULL);
ret = vmw_fifo_send_fence(dev_priv, &sequence);
if (unlikely(ret != 0)) {
DRM_ERROR("Fence submission error. Syncing.\n");
synced = true;
}
if (p_handle != NULL)
ret = vmw_user_fence_create(file_priv, dev_priv->fman,
sequence, p_fence, p_handle);
else
ret = vmw_fence_create(dev_priv->fman, sequence, p_fence);
if (unlikely(ret != 0 && !synced)) {
(void) vmw_fallback_wait(dev_priv, false, false,
sequence, false,
VMW_FENCE_WAIT_TIMEOUT);
*p_fence = NULL;
}
return 0;
}
void
vmw_execbuf_copy_fence_user(struct vmw_private *dev_priv,
struct vmw_fpriv *vmw_fp,
int ret,
struct drm_vmw_fence_rep __user *user_fence_rep,
struct vmw_fence_obj *fence,
uint32_t fence_handle)
{
struct drm_vmw_fence_rep fence_rep;
if (user_fence_rep == NULL)
return;
memset(&fence_rep, 0, sizeof(fence_rep));
fence_rep.error = ret;
if (ret == 0) {
BUG_ON(fence == NULL);
fence_rep.handle = fence_handle;
fence_rep.seqno = fence->base.seqno;
vmw_update_seqno(dev_priv, &dev_priv->fifo);
fence_rep.passed_seqno = dev_priv->last_read_seqno;
}
ret = copy_to_user(user_fence_rep, &fence_rep,
sizeof(fence_rep));
if (unlikely(ret != 0) && (fence_rep.error == 0)) {
ttm_ref_object_base_unref(vmw_fp->tfile,
fence_handle, TTM_REF_USAGE);
DRM_ERROR("Fence copy error. Syncing.\n");
(void) vmw_fence_obj_wait(fence, false, false,
VMW_FENCE_WAIT_TIMEOUT);
}
}
static int vmw_execbuf_submit_fifo(struct vmw_private *dev_priv,
void *kernel_commands,
u32 command_size,
struct vmw_sw_context *sw_context)
{
void *cmd;
if (sw_context->dx_ctx_node)
cmd = vmw_fifo_reserve_dx(dev_priv, command_size,
sw_context->dx_ctx_node->res->id);
else
cmd = vmw_fifo_reserve(dev_priv, command_size);
if (!cmd) {
DRM_ERROR("Failed reserving fifo space for commands.\n");
return -ENOMEM;
}
vmw_apply_relocations(sw_context);
memcpy(cmd, kernel_commands, command_size);
vmw_resource_relocations_apply(cmd, &sw_context->res_relocations);
vmw_resource_relocations_free(&sw_context->res_relocations);
vmw_fifo_commit(dev_priv, command_size);
return 0;
}
static int vmw_execbuf_submit_cmdbuf(struct vmw_private *dev_priv,
struct vmw_cmdbuf_header *header,
u32 command_size,
struct vmw_sw_context *sw_context)
{
u32 id = ((sw_context->dx_ctx_node) ? sw_context->dx_ctx_node->res->id :
SVGA3D_INVALID_ID);
void *cmd = vmw_cmdbuf_reserve(dev_priv->cman, command_size,
id, false, header);
vmw_apply_relocations(sw_context);
vmw_resource_relocations_apply(cmd, &sw_context->res_relocations);
vmw_resource_relocations_free(&sw_context->res_relocations);
vmw_cmdbuf_commit(dev_priv->cman, command_size, header, false);
return 0;
}
static void *vmw_execbuf_cmdbuf(struct vmw_private *dev_priv,
void __user *user_commands,
void *kernel_commands,
u32 command_size,
struct vmw_cmdbuf_header **header)
{
size_t cmdbuf_size;
int ret;
*header = NULL;
if (command_size > SVGA_CB_MAX_SIZE) {
DRM_ERROR("Command buffer is too large.\n");
return ERR_PTR(-EINVAL);
}
if (!dev_priv->cman || kernel_commands)
return kernel_commands;
cmdbuf_size = command_size + 512;
cmdbuf_size = min_t(size_t, cmdbuf_size, SVGA_CB_MAX_SIZE);
kernel_commands = vmw_cmdbuf_alloc(dev_priv->cman, cmdbuf_size,
true, header);
if (IS_ERR(kernel_commands))
return kernel_commands;
ret = copy_from_user(kernel_commands, user_commands,
command_size);
if (ret) {
DRM_ERROR("Failed copying commands.\n");
vmw_cmdbuf_header_free(*header);
*header = NULL;
return ERR_PTR(-EFAULT);
}
return kernel_commands;
}
static int vmw_execbuf_tie_context(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
uint32_t handle)
{
struct vmw_resource_val_node *ctx_node;
struct vmw_resource *res;
int ret;
if (handle == SVGA3D_INVALID_ID)
return 0;
ret = vmw_user_resource_lookup_handle(dev_priv, sw_context->fp->tfile,
handle, user_context_converter,
&res);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not find or user DX context 0x%08x.\n",
(unsigned) handle);
return ret;
}
ret = vmw_resource_val_add(sw_context, res, &ctx_node);
if (unlikely(ret != 0))
goto out_err;
sw_context->dx_ctx_node = ctx_node;
sw_context->man = vmw_context_res_man(res);
out_err:
vmw_resource_unreference(&res);
return ret;
}
int vmw_execbuf_process(struct drm_file *file_priv,
struct vmw_private *dev_priv,
void __user *user_commands,
void *kernel_commands,
uint32_t command_size,
uint64_t throttle_us,
uint32_t dx_context_handle,
struct drm_vmw_fence_rep __user *user_fence_rep,
struct vmw_fence_obj **out_fence)
{
struct vmw_sw_context *sw_context = &dev_priv->ctx;
struct vmw_fence_obj *fence = NULL;
struct vmw_resource *error_resource;
struct list_head resource_list;
struct vmw_cmdbuf_header *header;
struct ww_acquire_ctx ticket;
uint32_t handle;
int ret;
if (throttle_us) {
ret = vmw_wait_lag(dev_priv, &dev_priv->fifo.marker_queue,
throttle_us);
if (ret)
return ret;
}
kernel_commands = vmw_execbuf_cmdbuf(dev_priv, user_commands,
kernel_commands, command_size,
&header);
if (IS_ERR(kernel_commands))
return PTR_ERR(kernel_commands);
ret = mutex_lock_interruptible(&dev_priv->cmdbuf_mutex);
if (ret) {
ret = -ERESTARTSYS;
goto out_free_header;
}
sw_context->kernel = false;
if (kernel_commands == NULL) {
ret = vmw_resize_cmd_bounce(sw_context, command_size);
if (unlikely(ret != 0))
goto out_unlock;
ret = copy_from_user(sw_context->cmd_bounce,
user_commands, command_size);
if (unlikely(ret != 0)) {
ret = -EFAULT;
DRM_ERROR("Failed copying commands.\n");
goto out_unlock;
}
kernel_commands = sw_context->cmd_bounce;
} else if (!header)
sw_context->kernel = true;
sw_context->fp = vmw_fpriv(file_priv);
sw_context->cur_reloc = 0;
sw_context->cur_val_buf = 0;
INIT_LIST_HEAD(&sw_context->resource_list);
INIT_LIST_HEAD(&sw_context->ctx_resource_list);
sw_context->cur_query_bo = dev_priv->pinned_bo;
sw_context->last_query_ctx = NULL;
sw_context->needs_post_query_barrier = false;
sw_context->dx_ctx_node = NULL;
sw_context->dx_query_mob = NULL;
sw_context->dx_query_ctx = NULL;
memset(sw_context->res_cache, 0, sizeof(sw_context->res_cache));
INIT_LIST_HEAD(&sw_context->validate_nodes);
INIT_LIST_HEAD(&sw_context->res_relocations);
if (sw_context->staged_bindings)
vmw_binding_state_reset(sw_context->staged_bindings);
if (!sw_context->res_ht_initialized) {
ret = drm_ht_create(&sw_context->res_ht, VMW_RES_HT_ORDER);
if (unlikely(ret != 0))
goto out_unlock;
sw_context->res_ht_initialized = true;
}
INIT_LIST_HEAD(&sw_context->staged_cmd_res);
INIT_LIST_HEAD(&resource_list);
ret = vmw_execbuf_tie_context(dev_priv, sw_context, dx_context_handle);
if (unlikely(ret != 0)) {
list_splice_init(&sw_context->ctx_resource_list,
&sw_context->resource_list);
goto out_err_nores;
}
ret = vmw_cmd_check_all(dev_priv, sw_context, kernel_commands,
command_size);
list_splice_init(&sw_context->ctx_resource_list,
&sw_context->resource_list);
if (unlikely(ret != 0))
goto out_err_nores;
ret = vmw_resources_reserve(sw_context);
if (unlikely(ret != 0))
goto out_err_nores;
ret = ttm_eu_reserve_buffers(&ticket, &sw_context->validate_nodes,
true, NULL);
if (unlikely(ret != 0))
goto out_err_nores;
ret = vmw_validate_buffers(dev_priv, sw_context);
if (unlikely(ret != 0))
goto out_err;
ret = vmw_resources_validate(sw_context);
if (unlikely(ret != 0))
goto out_err;
ret = mutex_lock_interruptible(&dev_priv->binding_mutex);
if (unlikely(ret != 0)) {
ret = -ERESTARTSYS;
goto out_err;
}
if (dev_priv->has_mob) {
ret = vmw_rebind_contexts(sw_context);
if (unlikely(ret != 0))
goto out_unlock_binding;
}
if (!header) {
ret = vmw_execbuf_submit_fifo(dev_priv, kernel_commands,
command_size, sw_context);
} else {
ret = vmw_execbuf_submit_cmdbuf(dev_priv, header, command_size,
sw_context);
header = NULL;
}
mutex_unlock(&dev_priv->binding_mutex);
if (ret)
goto out_err;
vmw_query_bo_switch_commit(dev_priv, sw_context);
ret = vmw_execbuf_fence_commands(file_priv, dev_priv,
&fence,
(user_fence_rep) ? &handle : NULL);
if (ret != 0)
DRM_ERROR("Fence submission error. Syncing.\n");
vmw_resources_unreserve(sw_context, false);
ttm_eu_fence_buffer_objects(&ticket, &sw_context->validate_nodes,
(void *) fence);
if (unlikely(dev_priv->pinned_bo != NULL &&
!dev_priv->query_cid_valid))
__vmw_execbuf_release_pinned_bo(dev_priv, fence);
vmw_clear_validations(sw_context);
vmw_execbuf_copy_fence_user(dev_priv, vmw_fpriv(file_priv), ret,
user_fence_rep, fence, handle);
if (unlikely(out_fence != NULL)) {
*out_fence = fence;
fence = NULL;
} else if (likely(fence != NULL)) {
vmw_fence_obj_unreference(&fence);
}
list_splice_init(&sw_context->resource_list, &resource_list);
vmw_cmdbuf_res_commit(&sw_context->staged_cmd_res);
mutex_unlock(&dev_priv->cmdbuf_mutex);
vmw_resource_list_unreference(sw_context, &resource_list);
return 0;
out_unlock_binding:
mutex_unlock(&dev_priv->binding_mutex);
out_err:
ttm_eu_backoff_reservation(&ticket, &sw_context->validate_nodes);
out_err_nores:
vmw_resources_unreserve(sw_context, true);
vmw_resource_relocations_free(&sw_context->res_relocations);
vmw_free_relocations(sw_context);
vmw_clear_validations(sw_context);
if (unlikely(dev_priv->pinned_bo != NULL &&
!dev_priv->query_cid_valid))
__vmw_execbuf_release_pinned_bo(dev_priv, NULL);
out_unlock:
list_splice_init(&sw_context->resource_list, &resource_list);
error_resource = sw_context->error_resource;
sw_context->error_resource = NULL;
vmw_cmdbuf_res_revert(&sw_context->staged_cmd_res);
mutex_unlock(&dev_priv->cmdbuf_mutex);
vmw_resource_list_unreference(sw_context, &resource_list);
if (unlikely(error_resource != NULL))
vmw_resource_unreference(&error_resource);
out_free_header:
if (header)
vmw_cmdbuf_header_free(header);
return ret;
}
static void vmw_execbuf_unpin_panic(struct vmw_private *dev_priv)
{
DRM_ERROR("Can't unpin query buffer. Trying to recover.\n");
(void) vmw_fallback_wait(dev_priv, false, true, 0, false, 10*HZ);
vmw_bo_pin_reserved(dev_priv->pinned_bo, false);
if (dev_priv->dummy_query_bo_pinned) {
vmw_bo_pin_reserved(dev_priv->dummy_query_bo, false);
dev_priv->dummy_query_bo_pinned = false;
}
}
void __vmw_execbuf_release_pinned_bo(struct vmw_private *dev_priv,
struct vmw_fence_obj *fence)
{
int ret = 0;
struct list_head validate_list;
struct ttm_validate_buffer pinned_val, query_val;
struct vmw_fence_obj *lfence = NULL;
struct ww_acquire_ctx ticket;
if (dev_priv->pinned_bo == NULL)
goto out_unlock;
INIT_LIST_HEAD(&validate_list);
pinned_val.bo = ttm_bo_reference(&dev_priv->pinned_bo->base);
pinned_val.shared = false;
list_add_tail(&pinned_val.head, &validate_list);
query_val.bo = ttm_bo_reference(&dev_priv->dummy_query_bo->base);
query_val.shared = false;
list_add_tail(&query_val.head, &validate_list);
ret = ttm_eu_reserve_buffers(&ticket, &validate_list,
false, NULL);
if (unlikely(ret != 0)) {
vmw_execbuf_unpin_panic(dev_priv);
goto out_no_reserve;
}
if (dev_priv->query_cid_valid) {
BUG_ON(fence != NULL);
ret = vmw_fifo_emit_dummy_query(dev_priv, dev_priv->query_cid);
if (unlikely(ret != 0)) {
vmw_execbuf_unpin_panic(dev_priv);
goto out_no_emit;
}
dev_priv->query_cid_valid = false;
}
vmw_bo_pin_reserved(dev_priv->pinned_bo, false);
if (dev_priv->dummy_query_bo_pinned) {
vmw_bo_pin_reserved(dev_priv->dummy_query_bo, false);
dev_priv->dummy_query_bo_pinned = false;
}
if (fence == NULL) {
(void) vmw_execbuf_fence_commands(NULL, dev_priv, &lfence,
NULL);
fence = lfence;
}
ttm_eu_fence_buffer_objects(&ticket, &validate_list, (void *) fence);
if (lfence != NULL)
vmw_fence_obj_unreference(&lfence);
ttm_bo_unref(&query_val.bo);
ttm_bo_unref(&pinned_val.bo);
vmw_dmabuf_unreference(&dev_priv->pinned_bo);
out_unlock:
return;
out_no_emit:
ttm_eu_backoff_reservation(&ticket, &validate_list);
out_no_reserve:
ttm_bo_unref(&query_val.bo);
ttm_bo_unref(&pinned_val.bo);
vmw_dmabuf_unreference(&dev_priv->pinned_bo);
}
void vmw_execbuf_release_pinned_bo(struct vmw_private *dev_priv)
{
mutex_lock(&dev_priv->cmdbuf_mutex);
if (dev_priv->query_cid_valid)
__vmw_execbuf_release_pinned_bo(dev_priv, NULL);
mutex_unlock(&dev_priv->cmdbuf_mutex);
}
int vmw_execbuf_ioctl(struct drm_device *dev, unsigned long data,
struct drm_file *file_priv, size_t size)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_vmw_execbuf_arg arg;
int ret;
static const size_t copy_offset[] = {
offsetof(struct drm_vmw_execbuf_arg, context_handle),
sizeof(struct drm_vmw_execbuf_arg)};
if (unlikely(size < copy_offset[0])) {
DRM_ERROR("Invalid command size, ioctl %d\n",
DRM_VMW_EXECBUF);
return -EINVAL;
}
if (copy_from_user(&arg, (void __user *) data, copy_offset[0]) != 0)
return -EFAULT;
if (unlikely(arg.version > DRM_VMW_EXECBUF_VERSION ||
arg.version == 0)) {
DRM_ERROR("Incorrect execbuf version.\n");
return -EINVAL;
}
if (arg.version > 1 &&
copy_from_user(&arg.context_handle,
(void __user *) (data + copy_offset[0]),
copy_offset[arg.version - 1] -
copy_offset[0]) != 0)
return -EFAULT;
switch (arg.version) {
case 1:
arg.context_handle = (uint32_t) -1;
break;
case 2:
if (arg.pad64 != 0) {
DRM_ERROR("Unused IOCTL data not set to zero.\n");
return -EINVAL;
}
break;
default:
break;
}
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
return ret;
ret = vmw_execbuf_process(file_priv, dev_priv,
(void __user *)(unsigned long)arg.commands,
NULL, arg.command_size, arg.throttle_us,
arg.context_handle,
(void __user *)(unsigned long)arg.fence_rep,
NULL);
ttm_read_unlock(&dev_priv->reservation_sem);
if (unlikely(ret != 0))
return ret;
vmw_kms_cursor_post_execbuf(dev_priv);
return 0;
}
