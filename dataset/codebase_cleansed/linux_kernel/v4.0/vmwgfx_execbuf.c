static void vmw_resource_list_unreserve(struct list_head *list,
bool backoff)
{
struct vmw_resource_val_node *val;
list_for_each_entry(val, list, head) {
struct vmw_resource *res = val->res;
struct vmw_dma_buffer *new_backup =
backoff ? NULL : val->new_backup;
if (unlikely(val->staged_bindings)) {
if (!backoff) {
vmw_context_binding_state_transfer
(val->res, val->staged_bindings);
}
kfree(val->staged_bindings);
val->staged_bindings = NULL;
}
vmw_resource_unreserve(res, new_backup,
val->new_backup_offset);
vmw_dmabuf_unreference(&val->new_backup);
}
}
static int vmw_resource_val_add(struct vmw_sw_context *sw_context,
struct vmw_resource *res,
struct vmw_resource_val_node **p_node)
{
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
if (unlikely(node == NULL)) {
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
list_add_tail(&node->head, &sw_context->resource_list);
node->res = vmw_resource_reference(res);
node->first_usage = true;
if (unlikely(p_node != NULL))
*p_node = node;
return 0;
}
static int vmw_resource_context_res_add(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
struct vmw_resource *ctx)
{
struct list_head *binding_list;
struct vmw_ctx_binding *entry;
int ret = 0;
struct vmw_resource *res;
mutex_lock(&dev_priv->binding_mutex);
binding_list = vmw_context_binding_list(ctx);
list_for_each_entry(entry, binding_list, ctx_list) {
res = vmw_resource_reference_unless_doomed(entry->bi.res);
if (unlikely(res == NULL))
continue;
ret = vmw_resource_val_add(sw_context, entry->bi.res, NULL);
vmw_resource_unreference(&res);
if (unlikely(ret != 0))
break;
}
mutex_unlock(&dev_priv->binding_mutex);
return ret;
}
static int vmw_resource_relocation_add(struct list_head *list,
const struct vmw_resource *res,
unsigned long offset)
{
struct vmw_resource_relocation *rel;
rel = kmalloc(sizeof(*rel), GFP_KERNEL);
if (unlikely(rel == NULL)) {
DRM_ERROR("Failed to allocate a resource relocation.\n");
return -ENOMEM;
}
rel->res = res;
rel->offset = offset;
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
list_for_each_entry(rel, list, head) {
if (likely(rel->res != NULL))
cb[rel->offset] = rel->res->id;
else
cb[rel->offset] = SVGA_3D_CMD_NOP;
}
}
static int vmw_cmd_invalid(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
return capable(CAP_SYS_ADMIN) ? : -EINVAL;
}
static int vmw_cmd_ok(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGA3dCmdHeader *header)
{
return 0;
}
static int vmw_bo_to_validate_list(struct vmw_sw_context *sw_context,
struct ttm_buffer_object *bo,
bool validate_as_mob,
uint32_t *p_val_node)
{
uint32_t val_node;
struct vmw_validate_buffer *vval_buf;
struct ttm_validate_buffer *val_buf;
struct drm_hash_item *hash;
int ret;
if (likely(drm_ht_find_item(&sw_context->res_ht, (unsigned long) bo,
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
vval_buf->hash.key = (unsigned long) bo;
ret = drm_ht_insert_item(&sw_context->res_ht, &vval_buf->hash);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to initialize a buffer validation "
"entry.\n");
return ret;
}
++sw_context->cur_val_buf;
val_buf = &vval_buf->base;
val_buf->bo = ttm_bo_reference(bo);
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
int ret;
list_for_each_entry(val, &sw_context->resource_list, head) {
struct vmw_resource *res = val->res;
ret = vmw_resource_reserve(res, val->no_buffer_needed);
if (unlikely(ret != 0))
return ret;
if (res->backup) {
struct ttm_buffer_object *bo = &res->backup->base;
ret = vmw_bo_to_validate_list
(sw_context, bo,
vmw_resource_needs_backup(res), NULL);
if (unlikely(ret != 0))
return ret;
}
}
return 0;
}
static int vmw_resources_validate(struct vmw_sw_context *sw_context)
{
struct vmw_resource_val_node *val;
int ret;
list_for_each_entry(val, &sw_context->resource_list, head) {
struct vmw_resource *res = val->res;
ret = vmw_resource_validate(res);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Failed to validate resource.\n");
return ret;
}
}
return 0;
}
static int vmw_cmd_res_reloc_add(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
enum vmw_res_type res_type,
uint32_t *id_loc,
struct vmw_resource *res,
struct vmw_resource_val_node **p_val)
{
int ret;
struct vmw_resource_val_node *node;
*p_val = NULL;
ret = vmw_resource_relocation_add(&sw_context->res_relocations,
res,
id_loc - sw_context->buf_start);
if (unlikely(ret != 0))
return ret;
ret = vmw_resource_val_add(sw_context, res, &node);
if (unlikely(ret != 0))
return ret;
if (res_type == vmw_res_context && dev_priv->has_mob &&
node->first_usage) {
list_del(&node->head);
list_add(&node->head, &sw_context->resource_list);
ret = vmw_resource_context_res_add(dev_priv, sw_context, res);
if (unlikely(ret != 0))
return ret;
node->staged_bindings =
kzalloc(sizeof(*node->staged_bindings), GFP_KERNEL);
if (node->staged_bindings == NULL) {
DRM_ERROR("Failed to allocate context binding "
"information.\n");
return -ENOMEM;
}
INIT_LIST_HEAD(&node->staged_bindings->list);
}
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
id_loc - sw_context->buf_start);
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
ret = vmw_cmd_res_reloc_add(dev_priv, sw_context, res_type, id_loc,
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
static int vmw_rebind_contexts(struct vmw_sw_context *sw_context)
{
struct vmw_resource_val_node *val;
int ret;
list_for_each_entry(val, &sw_context->resource_list, head) {
if (unlikely(!val->staged_bindings))
break;
ret = vmw_context_rebind_all(val->res);
if (unlikely(ret != 0)) {
if (ret != -ERESTARTSYS)
DRM_ERROR("Failed to rebind context.\n");
return ret;
}
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
struct vmw_ctx_bindinfo bi;
bi.ctx = ctx_node->res;
bi.res = res_node ? res_node->res : NULL;
bi.bt = vmw_ctx_binding_rt;
bi.i1.rt_type = cmd->body.type;
return vmw_context_binding_add(ctx_node->staged_bindings, &bi);
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
if (unlikely(ret != 0))
return ret;
return vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cmd->body.dest.sid, NULL);
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
struct ttm_buffer_object *new_query_bo,
struct vmw_sw_context *sw_context)
{
struct vmw_res_cache_entry *ctx_entry =
&sw_context->res_cache[vmw_res_context];
int ret;
BUG_ON(!ctx_entry->valid);
sw_context->last_query_ctx = ctx_entry->res;
if (unlikely(new_query_bo != sw_context->cur_query_bo)) {
if (unlikely(new_query_bo->num_pages > 4)) {
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
vmw_bo_pin(dev_priv->pinned_bo, false);
ttm_bo_unref(&dev_priv->pinned_bo);
}
if (!sw_context->needs_post_query_barrier) {
vmw_bo_pin(sw_context->cur_query_bo, true);
vmw_bo_pin(dev_priv->dummy_query_bo, true);
dev_priv->dummy_query_bo_pinned = true;
BUG_ON(sw_context->last_query_ctx == NULL);
dev_priv->query_cid = sw_context->last_query_ctx->id;
dev_priv->query_cid_valid = true;
dev_priv->pinned_bo =
ttm_bo_reference(sw_context->cur_query_bo);
}
}
}
static int vmw_translate_mob_ptr(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
SVGAMobId *id,
struct vmw_dma_buffer **vmw_bo_p)
{
struct vmw_dma_buffer *vmw_bo = NULL;
struct ttm_buffer_object *bo;
uint32_t handle = *id;
struct vmw_relocation *reloc;
int ret;
ret = vmw_user_dmabuf_lookup(sw_context->fp->tfile, handle, &vmw_bo);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not find or use MOB buffer.\n");
ret = -EINVAL;
goto out_no_reloc;
}
bo = &vmw_bo->base;
if (unlikely(sw_context->cur_reloc >= VMWGFX_MAX_RELOCATIONS)) {
DRM_ERROR("Max number relocations per submission"
" exceeded\n");
ret = -EINVAL;
goto out_no_reloc;
}
reloc = &sw_context->relocs[sw_context->cur_reloc++];
reloc->mob_loc = id;
reloc->location = NULL;
ret = vmw_bo_to_validate_list(sw_context, bo, true, &reloc->index);
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
struct ttm_buffer_object *bo;
uint32_t handle = ptr->gmrId;
struct vmw_relocation *reloc;
int ret;
ret = vmw_user_dmabuf_lookup(sw_context->fp->tfile, handle, &vmw_bo);
if (unlikely(ret != 0)) {
DRM_ERROR("Could not find or use GMR region.\n");
ret = -EINVAL;
goto out_no_reloc;
}
bo = &vmw_bo->base;
if (unlikely(sw_context->cur_reloc >= VMWGFX_MAX_RELOCATIONS)) {
DRM_ERROR("Max number relocations per submission"
" exceeded\n");
ret = -EINVAL;
goto out_no_reloc;
}
reloc = &sw_context->relocs[sw_context->cur_reloc++];
reloc->location = ptr;
ret = vmw_bo_to_validate_list(sw_context, bo, false, &reloc->index);
if (unlikely(ret != 0))
goto out_no_reloc;
*vmw_bo_p = vmw_bo;
return 0;
out_no_reloc:
vmw_dmabuf_unreference(&vmw_bo);
*vmw_bo_p = NULL;
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
ret = vmw_query_bo_switch_prepare(dev_priv, &vmw_bo->base, sw_context);
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
ret = vmw_query_bo_switch_prepare(dev_priv, &vmw_bo->base, sw_context);
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
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_surface,
user_surface_converter,
&cur_state->value, &res_node);
if (unlikely(ret != 0))
return ret;
if (dev_priv->has_mob) {
struct vmw_ctx_bindinfo bi;
bi.ctx = ctx_node->res;
bi.res = res_node ? res_node->res : NULL;
bi.bt = vmw_ctx_binding_tex;
bi.i1.texture_stage = cur_state->stage;
vmw_context_binding_add(ctx_node->staged_bindings,
&bi);
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
static int vmw_cmd_switch_backup(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
enum vmw_res_type res_type,
const struct vmw_user_resource_conv
*converter,
uint32_t *res_id,
uint32_t *buf_id,
unsigned long backup_offset)
{
int ret;
struct vmw_dma_buffer *dma_buf;
struct vmw_resource_val_node *val_node;
ret = vmw_cmd_res_check(dev_priv, sw_context, res_type,
converter, res_id, &val_node);
if (unlikely(ret != 0))
return ret;
ret = vmw_translate_mob_ptr(dev_priv, sw_context, buf_id, &dma_buf);
if (unlikely(ret != 0))
return ret;
if (val_node->first_usage)
val_node->no_buffer_needed = true;
vmw_dmabuf_unreference(&val_node->new_backup);
val_node->new_backup = dma_buf;
val_node->new_backup_offset = backup_offset;
return 0;
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
NULL, &cmd->header.id -
sw_context->buf_start);
return 0;
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
ret = vmw_compat_shader_remove(vmw_context_res_man(val->res),
cmd->body.shid,
cmd->body.type,
&sw_context->staged_cmd_res);
if (unlikely(ret != 0))
return ret;
return vmw_resource_relocation_add(&sw_context->res_relocations,
NULL, &cmd->header.id -
sw_context->buf_start);
return 0;
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
struct vmw_ctx_bindinfo bi;
struct vmw_resource *res = NULL;
int ret;
cmd = container_of(header, struct vmw_set_shader_cmd,
header);
ret = vmw_cmd_res_check(dev_priv, sw_context, vmw_res_context,
user_context_converter, &cmd->body.cid,
&ctx_node);
if (unlikely(ret != 0))
return ret;
if (!dev_priv->has_mob)
return 0;
if (cmd->body.shid != SVGA3D_INVALID_ID) {
res = vmw_compat_shader_lookup
(vmw_context_res_man(ctx_node->res),
cmd->body.shid,
cmd->body.type);
if (!IS_ERR(res)) {
ret = vmw_cmd_res_reloc_add(dev_priv, sw_context,
vmw_res_shader,
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
bi.ctx = ctx_node->res;
bi.res = res_node ? res_node->res : NULL;
bi.bt = vmw_ctx_binding_shader;
bi.i1.shader_type = cmd->body.type;
return vmw_context_binding_add(ctx_node->staged_bindings, &bi);
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
static int vmw_cmd_check_not_3d(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context,
void *buf, uint32_t *size)
{
uint32_t size_remaining = *size;
uint32_t cmd_id;
cmd_id = le32_to_cpu(((uint32_t *)buf)[0]);
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
cmd_id = le32_to_cpu(((uint32_t *)buf)[0]);
if (unlikely(cmd_id < SVGA_CMD_MAX))
return vmw_cmd_check_not_3d(dev_priv, sw_context, buf, size);
cmd_id = le32_to_cpu(header->id);
*size = le32_to_cpu(header->size) + sizeof(SVGA3dCmdHeader);
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
static void vmw_resource_list_unreference(struct list_head *list)
{
struct vmw_resource_val_node *val, *val_next;
list_for_each_entry_safe(val, val_next, list, head) {
list_del_init(&val->head);
vmw_resource_unreference(&val->res);
if (unlikely(val->staged_bindings))
kfree(val->staged_bindings);
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
static int vmw_validate_single_buffer(struct vmw_private *dev_priv,
struct ttm_buffer_object *bo,
bool validate_as_mob)
{
int ret;
if (bo == dev_priv->pinned_bo ||
(bo == dev_priv->dummy_query_bo &&
dev_priv->dummy_query_bo_pinned))
return 0;
if (validate_as_mob)
return ttm_bo_validate(bo, &vmw_mob_placement, true, false);
ret = ttm_bo_validate(bo, &vmw_vram_gmr_placement, true, false);
if (likely(ret == 0 || ret == -ERESTARTSYS))
return ret;
DRM_INFO("Falling through to VRAM.\n");
ret = ttm_bo_validate(bo, &vmw_vram_placement, true, false);
return ret;
}
static int vmw_validate_buffers(struct vmw_private *dev_priv,
struct vmw_sw_context *sw_context)
{
struct vmw_validate_buffer *entry;
int ret;
list_for_each_entry(entry, &sw_context->validate_nodes, base.head) {
ret = vmw_validate_single_buffer(dev_priv, entry->base.bo,
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
if (sw_context->cmd_bounce != NULL)
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
int vmw_execbuf_process(struct drm_file *file_priv,
struct vmw_private *dev_priv,
void __user *user_commands,
void *kernel_commands,
uint32_t command_size,
uint64_t throttle_us,
struct drm_vmw_fence_rep __user *user_fence_rep,
struct vmw_fence_obj **out_fence)
{
struct vmw_sw_context *sw_context = &dev_priv->ctx;
struct vmw_fence_obj *fence = NULL;
struct vmw_resource *error_resource;
struct list_head resource_list;
struct ww_acquire_ctx ticket;
uint32_t handle;
void *cmd;
int ret;
ret = mutex_lock_interruptible(&dev_priv->cmdbuf_mutex);
if (unlikely(ret != 0))
return -ERESTARTSYS;
if (kernel_commands == NULL) {
sw_context->kernel = false;
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
} else
sw_context->kernel = true;
sw_context->fp = vmw_fpriv(file_priv);
sw_context->cur_reloc = 0;
sw_context->cur_val_buf = 0;
INIT_LIST_HEAD(&sw_context->resource_list);
sw_context->cur_query_bo = dev_priv->pinned_bo;
sw_context->last_query_ctx = NULL;
sw_context->needs_post_query_barrier = false;
memset(sw_context->res_cache, 0, sizeof(sw_context->res_cache));
INIT_LIST_HEAD(&sw_context->validate_nodes);
INIT_LIST_HEAD(&sw_context->res_relocations);
if (!sw_context->res_ht_initialized) {
ret = drm_ht_create(&sw_context->res_ht, VMW_RES_HT_ORDER);
if (unlikely(ret != 0))
goto out_unlock;
sw_context->res_ht_initialized = true;
}
INIT_LIST_HEAD(&sw_context->staged_cmd_res);
INIT_LIST_HEAD(&resource_list);
ret = vmw_cmd_check_all(dev_priv, sw_context, kernel_commands,
command_size);
if (unlikely(ret != 0))
goto out_err_nores;
ret = vmw_resources_reserve(sw_context);
if (unlikely(ret != 0))
goto out_err_nores;
ret = ttm_eu_reserve_buffers(&ticket, &sw_context->validate_nodes,
true, NULL);
if (unlikely(ret != 0))
goto out_err;
ret = vmw_validate_buffers(dev_priv, sw_context);
if (unlikely(ret != 0))
goto out_err;
ret = vmw_resources_validate(sw_context);
if (unlikely(ret != 0))
goto out_err;
if (throttle_us) {
ret = vmw_wait_lag(dev_priv, &dev_priv->fifo.marker_queue,
throttle_us);
if (unlikely(ret != 0))
goto out_err;
}
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
cmd = vmw_fifo_reserve(dev_priv, command_size);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving fifo space for commands.\n");
ret = -ENOMEM;
goto out_unlock_binding;
}
vmw_apply_relocations(sw_context);
memcpy(cmd, kernel_commands, command_size);
vmw_resource_relocations_apply(cmd, &sw_context->res_relocations);
vmw_resource_relocations_free(&sw_context->res_relocations);
vmw_fifo_commit(dev_priv, command_size);
vmw_query_bo_switch_commit(dev_priv, sw_context);
ret = vmw_execbuf_fence_commands(file_priv, dev_priv,
&fence,
(user_fence_rep) ? &handle : NULL);
if (ret != 0)
DRM_ERROR("Fence submission error. Syncing.\n");
vmw_resource_list_unreserve(&sw_context->resource_list, false);
mutex_unlock(&dev_priv->binding_mutex);
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
vmw_resource_list_unreference(&resource_list);
return 0;
out_unlock_binding:
mutex_unlock(&dev_priv->binding_mutex);
out_err:
ttm_eu_backoff_reservation(&ticket, &sw_context->validate_nodes);
out_err_nores:
vmw_resource_list_unreserve(&sw_context->resource_list, true);
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
vmw_resource_list_unreference(&resource_list);
if (unlikely(error_resource != NULL))
vmw_resource_unreference(&error_resource);
return ret;
}
static void vmw_execbuf_unpin_panic(struct vmw_private *dev_priv)
{
DRM_ERROR("Can't unpin query buffer. Trying to recover.\n");
(void) vmw_fallback_wait(dev_priv, false, true, 0, false, 10*HZ);
vmw_bo_pin(dev_priv->pinned_bo, false);
vmw_bo_pin(dev_priv->dummy_query_bo, false);
dev_priv->dummy_query_bo_pinned = false;
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
pinned_val.bo = ttm_bo_reference(dev_priv->pinned_bo);
pinned_val.shared = false;
list_add_tail(&pinned_val.head, &validate_list);
query_val.bo = ttm_bo_reference(dev_priv->dummy_query_bo);
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
vmw_bo_pin(dev_priv->pinned_bo, false);
vmw_bo_pin(dev_priv->dummy_query_bo, false);
dev_priv->dummy_query_bo_pinned = false;
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
ttm_bo_unref(&dev_priv->pinned_bo);
out_unlock:
return;
out_no_emit:
ttm_eu_backoff_reservation(&ticket, &validate_list);
out_no_reserve:
ttm_bo_unref(&query_val.bo);
ttm_bo_unref(&pinned_val.bo);
ttm_bo_unref(&dev_priv->pinned_bo);
}
void vmw_execbuf_release_pinned_bo(struct vmw_private *dev_priv)
{
mutex_lock(&dev_priv->cmdbuf_mutex);
if (dev_priv->query_cid_valid)
__vmw_execbuf_release_pinned_bo(dev_priv, NULL);
mutex_unlock(&dev_priv->cmdbuf_mutex);
}
int vmw_execbuf_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_vmw_execbuf_arg *arg = (struct drm_vmw_execbuf_arg *)data;
int ret;
if (unlikely(arg->version != DRM_VMW_EXECBUF_VERSION)) {
DRM_ERROR("Incorrect execbuf version.\n");
DRM_ERROR("You're running outdated experimental "
"vmwgfx user-space drivers.");
return -EINVAL;
}
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
return ret;
ret = vmw_execbuf_process(file_priv, dev_priv,
(void __user *)(unsigned long)arg->commands,
NULL, arg->command_size, arg->throttle_us,
(void __user *)(unsigned long)arg->fence_rep,
NULL);
ttm_read_unlock(&dev_priv->reservation_sem);
if (unlikely(ret != 0))
return ret;
vmw_kms_cursor_post_execbuf(dev_priv);
return 0;
}
