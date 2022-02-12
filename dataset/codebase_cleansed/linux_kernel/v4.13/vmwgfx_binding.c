static const struct vmw_resource *
vmw_cbs_context(const struct vmw_ctx_binding_state *cbs)
{
if (list_empty(&cbs->list))
return NULL;
return list_first_entry(&cbs->list, struct vmw_ctx_bindinfo,
ctx_list)->ctx;
}
static struct vmw_ctx_bindinfo *
vmw_binding_loc(struct vmw_ctx_binding_state *cbs,
enum vmw_ctx_binding_type bt, u32 shader_slot, u32 slot)
{
const struct vmw_binding_info *b = &vmw_binding_infos[bt];
size_t offset = b->offsets[shader_slot] + b->size*slot;
return (struct vmw_ctx_bindinfo *)((u8 *) cbs + offset);
}
static void vmw_binding_drop(struct vmw_ctx_bindinfo *bi)
{
list_del(&bi->ctx_list);
if (!list_empty(&bi->res_list))
list_del(&bi->res_list);
bi->ctx = NULL;
}
void vmw_binding_add(struct vmw_ctx_binding_state *cbs,
const struct vmw_ctx_bindinfo *bi,
u32 shader_slot, u32 slot)
{
struct vmw_ctx_bindinfo *loc =
vmw_binding_loc(cbs, bi->bt, shader_slot, slot);
const struct vmw_binding_info *b = &vmw_binding_infos[bi->bt];
if (loc->ctx != NULL)
vmw_binding_drop(loc);
memcpy(loc, bi, b->size);
loc->scrubbed = false;
list_add(&loc->ctx_list, &cbs->list);
INIT_LIST_HEAD(&loc->res_list);
}
static void vmw_binding_transfer(struct vmw_ctx_binding_state *cbs,
const struct vmw_ctx_binding_state *from,
const struct vmw_ctx_bindinfo *bi)
{
size_t offset = (unsigned long)bi - (unsigned long)from;
struct vmw_ctx_bindinfo *loc = (struct vmw_ctx_bindinfo *)
((unsigned long) cbs + offset);
if (loc->ctx != NULL) {
WARN_ON(bi->scrubbed);
vmw_binding_drop(loc);
}
if (bi->res != NULL) {
memcpy(loc, bi, vmw_binding_infos[bi->bt].size);
list_add_tail(&loc->ctx_list, &cbs->list);
list_add_tail(&loc->res_list, &loc->res->binding_head);
}
}
void vmw_binding_state_kill(struct vmw_ctx_binding_state *cbs)
{
struct vmw_ctx_bindinfo *entry, *next;
vmw_binding_state_scrub(cbs);
list_for_each_entry_safe(entry, next, &cbs->list, ctx_list)
vmw_binding_drop(entry);
}
void vmw_binding_state_scrub(struct vmw_ctx_binding_state *cbs)
{
struct vmw_ctx_bindinfo *entry;
list_for_each_entry(entry, &cbs->list, ctx_list) {
if (!entry->scrubbed) {
(void) vmw_binding_infos[entry->bt].scrub_func
(entry, false);
entry->scrubbed = true;
}
}
(void) vmw_binding_emit_dirty(cbs);
}
void vmw_binding_res_list_kill(struct list_head *head)
{
struct vmw_ctx_bindinfo *entry, *next;
vmw_binding_res_list_scrub(head);
list_for_each_entry_safe(entry, next, head, res_list)
vmw_binding_drop(entry);
}
void vmw_binding_res_list_scrub(struct list_head *head)
{
struct vmw_ctx_bindinfo *entry;
list_for_each_entry(entry, head, res_list) {
if (!entry->scrubbed) {
(void) vmw_binding_infos[entry->bt].scrub_func
(entry, false);
entry->scrubbed = true;
}
}
list_for_each_entry(entry, head, res_list) {
struct vmw_ctx_binding_state *cbs =
vmw_context_binding_state(entry->ctx);
(void) vmw_binding_emit_dirty(cbs);
}
}
void vmw_binding_state_commit(struct vmw_ctx_binding_state *to,
struct vmw_ctx_binding_state *from)
{
struct vmw_ctx_bindinfo *entry, *next;
list_for_each_entry_safe(entry, next, &from->list, ctx_list) {
vmw_binding_transfer(to, from, entry);
vmw_binding_drop(entry);
}
}
int vmw_binding_rebind_all(struct vmw_ctx_binding_state *cbs)
{
struct vmw_ctx_bindinfo *entry;
int ret;
list_for_each_entry(entry, &cbs->list, ctx_list) {
if (likely(!entry->scrubbed))
continue;
if ((entry->res == NULL || entry->res->id ==
SVGA3D_INVALID_ID))
continue;
ret = vmw_binding_infos[entry->bt].scrub_func(entry, true);
if (unlikely(ret != 0))
return ret;
entry->scrubbed = false;
}
return vmw_binding_emit_dirty(cbs);
}
static int vmw_binding_scrub_shader(struct vmw_ctx_bindinfo *bi, bool rebind)
{
struct vmw_ctx_bindinfo_shader *binding =
container_of(bi, typeof(*binding), bi);
struct vmw_private *dev_priv = bi->ctx->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdSetShader body;
} *cmd;
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for shader "
"unbinding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_SET_SHADER;
cmd->header.size = sizeof(cmd->body);
cmd->body.cid = bi->ctx->id;
cmd->body.type = binding->shader_slot + SVGA3D_SHADERTYPE_MIN;
cmd->body.shid = ((rebind) ? bi->res->id : SVGA3D_INVALID_ID);
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
}
static int vmw_binding_scrub_render_target(struct vmw_ctx_bindinfo *bi,
bool rebind)
{
struct vmw_ctx_bindinfo_view *binding =
container_of(bi, typeof(*binding), bi);
struct vmw_private *dev_priv = bi->ctx->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdSetRenderTarget body;
} *cmd;
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for render target "
"unbinding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_SETRENDERTARGET;
cmd->header.size = sizeof(cmd->body);
cmd->body.cid = bi->ctx->id;
cmd->body.type = binding->slot;
cmd->body.target.sid = ((rebind) ? bi->res->id : SVGA3D_INVALID_ID);
cmd->body.target.face = 0;
cmd->body.target.mipmap = 0;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
}
static int vmw_binding_scrub_texture(struct vmw_ctx_bindinfo *bi,
bool rebind)
{
struct vmw_ctx_bindinfo_tex *binding =
container_of(bi, typeof(*binding), bi);
struct vmw_private *dev_priv = bi->ctx->dev_priv;
struct {
SVGA3dCmdHeader header;
struct {
SVGA3dCmdSetTextureState c;
SVGA3dTextureState s1;
} body;
} *cmd;
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for texture "
"unbinding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_SETTEXTURESTATE;
cmd->header.size = sizeof(cmd->body);
cmd->body.c.cid = bi->ctx->id;
cmd->body.s1.stage = binding->texture_stage;
cmd->body.s1.name = SVGA3D_TS_BIND_TEXTURE;
cmd->body.s1.value = ((rebind) ? bi->res->id : SVGA3D_INVALID_ID);
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
}
static int vmw_binding_scrub_dx_shader(struct vmw_ctx_bindinfo *bi, bool rebind)
{
struct vmw_ctx_bindinfo_shader *binding =
container_of(bi, typeof(*binding), bi);
struct vmw_private *dev_priv = bi->ctx->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetShader body;
} *cmd;
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd), bi->ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for DX shader "
"unbinding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_SET_SHADER;
cmd->header.size = sizeof(cmd->body);
cmd->body.type = binding->shader_slot + SVGA3D_SHADERTYPE_MIN;
cmd->body.shaderId = ((rebind) ? bi->res->id : SVGA3D_INVALID_ID);
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
}
static int vmw_binding_scrub_cb(struct vmw_ctx_bindinfo *bi, bool rebind)
{
struct vmw_ctx_bindinfo_cb *binding =
container_of(bi, typeof(*binding), bi);
struct vmw_private *dev_priv = bi->ctx->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetSingleConstantBuffer body;
} *cmd;
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd), bi->ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for DX shader "
"unbinding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_SET_SINGLE_CONSTANT_BUFFER;
cmd->header.size = sizeof(cmd->body);
cmd->body.slot = binding->slot;
cmd->body.type = binding->shader_slot + SVGA3D_SHADERTYPE_MIN;
if (rebind) {
cmd->body.offsetInBytes = binding->offset;
cmd->body.sizeInBytes = binding->size;
cmd->body.sid = bi->res->id;
} else {
cmd->body.offsetInBytes = 0;
cmd->body.sizeInBytes = 0;
cmd->body.sid = SVGA3D_INVALID_ID;
}
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
}
static void vmw_collect_view_ids(struct vmw_ctx_binding_state *cbs,
const struct vmw_ctx_bindinfo *bi,
u32 max_num)
{
const struct vmw_ctx_bindinfo_view *biv =
container_of(bi, struct vmw_ctx_bindinfo_view, bi);
unsigned long i;
cbs->bind_cmd_count = 0;
cbs->bind_first_slot = 0;
for (i = 0; i < max_num; ++i, ++biv) {
if (!biv->bi.ctx)
break;
cbs->bind_cmd_buffer[cbs->bind_cmd_count++] =
((biv->bi.scrubbed) ?
SVGA3D_INVALID_ID : biv->bi.res->id);
}
}
static void vmw_collect_dirty_view_ids(struct vmw_ctx_binding_state *cbs,
const struct vmw_ctx_bindinfo *bi,
unsigned long *dirty,
u32 max_num)
{
const struct vmw_ctx_bindinfo_view *biv =
container_of(bi, struct vmw_ctx_bindinfo_view, bi);
unsigned long i, next_bit;
cbs->bind_cmd_count = 0;
i = find_first_bit(dirty, max_num);
next_bit = i;
cbs->bind_first_slot = i;
biv += i;
for (; i < max_num; ++i, ++biv) {
cbs->bind_cmd_buffer[cbs->bind_cmd_count++] =
((!biv->bi.ctx || biv->bi.scrubbed) ?
SVGA3D_INVALID_ID : biv->bi.res->id);
if (next_bit == i) {
next_bit = find_next_bit(dirty, max_num, i + 1);
if (next_bit >= max_num)
break;
}
}
}
static int vmw_emit_set_sr(struct vmw_ctx_binding_state *cbs,
int shader_slot)
{
const struct vmw_ctx_bindinfo *loc =
&cbs->per_shader[shader_slot].shader_res[0].bi;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetShaderResources body;
} *cmd;
size_t cmd_size, view_id_size;
const struct vmw_resource *ctx = vmw_cbs_context(cbs);
vmw_collect_dirty_view_ids(cbs, loc,
cbs->per_shader[shader_slot].dirty_sr,
SVGA3D_DX_MAX_SRVIEWS);
if (cbs->bind_cmd_count == 0)
return 0;
view_id_size = cbs->bind_cmd_count*sizeof(uint32);
cmd_size = sizeof(*cmd) + view_id_size;
cmd = vmw_fifo_reserve_dx(ctx->dev_priv, cmd_size, ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for DX shader"
" resource binding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_SET_SHADER_RESOURCES;
cmd->header.size = sizeof(cmd->body) + view_id_size;
cmd->body.type = shader_slot + SVGA3D_SHADERTYPE_MIN;
cmd->body.startView = cbs->bind_first_slot;
memcpy(&cmd[1], cbs->bind_cmd_buffer, view_id_size);
vmw_fifo_commit(ctx->dev_priv, cmd_size);
bitmap_clear(cbs->per_shader[shader_slot].dirty_sr,
cbs->bind_first_slot, cbs->bind_cmd_count);
return 0;
}
static int vmw_emit_set_rt(struct vmw_ctx_binding_state *cbs)
{
const struct vmw_ctx_bindinfo *loc = &cbs->render_targets[0].bi;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetRenderTargets body;
} *cmd;
size_t cmd_size, view_id_size;
const struct vmw_resource *ctx = vmw_cbs_context(cbs);
vmw_collect_view_ids(cbs, loc, SVGA3D_MAX_SIMULTANEOUS_RENDER_TARGETS);
view_id_size = cbs->bind_cmd_count*sizeof(uint32);
cmd_size = sizeof(*cmd) + view_id_size;
cmd = vmw_fifo_reserve_dx(ctx->dev_priv, cmd_size, ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for DX render-target"
" binding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_SET_RENDERTARGETS;
cmd->header.size = sizeof(cmd->body) + view_id_size;
if (cbs->ds_view.bi.ctx && !cbs->ds_view.bi.scrubbed)
cmd->body.depthStencilViewId = cbs->ds_view.bi.res->id;
else
cmd->body.depthStencilViewId = SVGA3D_INVALID_ID;
memcpy(&cmd[1], cbs->bind_cmd_buffer, view_id_size);
vmw_fifo_commit(ctx->dev_priv, cmd_size);
return 0;
}
static void vmw_collect_so_targets(struct vmw_ctx_binding_state *cbs,
const struct vmw_ctx_bindinfo *bi,
u32 max_num)
{
const struct vmw_ctx_bindinfo_so *biso =
container_of(bi, struct vmw_ctx_bindinfo_so, bi);
unsigned long i;
SVGA3dSoTarget *so_buffer = (SVGA3dSoTarget *) cbs->bind_cmd_buffer;
cbs->bind_cmd_count = 0;
cbs->bind_first_slot = 0;
for (i = 0; i < max_num; ++i, ++biso, ++so_buffer,
++cbs->bind_cmd_count) {
if (!biso->bi.ctx)
break;
if (!biso->bi.scrubbed) {
so_buffer->sid = biso->bi.res->id;
so_buffer->offset = biso->offset;
so_buffer->sizeInBytes = biso->size;
} else {
so_buffer->sid = SVGA3D_INVALID_ID;
so_buffer->offset = 0;
so_buffer->sizeInBytes = 0;
}
}
}
static int vmw_emit_set_so(struct vmw_ctx_binding_state *cbs)
{
const struct vmw_ctx_bindinfo *loc = &cbs->so_targets[0].bi;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetSOTargets body;
} *cmd;
size_t cmd_size, so_target_size;
const struct vmw_resource *ctx = vmw_cbs_context(cbs);
vmw_collect_so_targets(cbs, loc, SVGA3D_DX_MAX_SOTARGETS);
if (cbs->bind_cmd_count == 0)
return 0;
so_target_size = cbs->bind_cmd_count*sizeof(SVGA3dSoTarget);
cmd_size = sizeof(*cmd) + so_target_size;
cmd = vmw_fifo_reserve_dx(ctx->dev_priv, cmd_size, ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for DX SO target"
" binding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_SET_SOTARGETS;
cmd->header.size = sizeof(cmd->body) + so_target_size;
memcpy(&cmd[1], cbs->bind_cmd_buffer, so_target_size);
vmw_fifo_commit(ctx->dev_priv, cmd_size);
return 0;
}
static int vmw_binding_emit_dirty_ps(struct vmw_ctx_binding_state *cbs)
{
struct vmw_dx_shader_bindings *sb = &cbs->per_shader[0];
u32 i;
int ret;
for (i = 0; i < SVGA3D_NUM_SHADERTYPE_DX10; ++i, ++sb) {
if (!test_bit(VMW_BINDING_PS_SR_BIT, &sb->dirty))
continue;
ret = vmw_emit_set_sr(cbs, i);
if (ret)
break;
__clear_bit(VMW_BINDING_PS_SR_BIT, &sb->dirty);
}
return 0;
}
static void vmw_collect_dirty_vbs(struct vmw_ctx_binding_state *cbs,
const struct vmw_ctx_bindinfo *bi,
unsigned long *dirty,
u32 max_num)
{
const struct vmw_ctx_bindinfo_vb *biv =
container_of(bi, struct vmw_ctx_bindinfo_vb, bi);
unsigned long i, next_bit;
SVGA3dVertexBuffer *vbs = (SVGA3dVertexBuffer *) &cbs->bind_cmd_buffer;
cbs->bind_cmd_count = 0;
i = find_first_bit(dirty, max_num);
next_bit = i;
cbs->bind_first_slot = i;
biv += i;
for (; i < max_num; ++i, ++biv, ++vbs) {
if (!biv->bi.ctx || biv->bi.scrubbed) {
vbs->sid = SVGA3D_INVALID_ID;
vbs->stride = 0;
vbs->offset = 0;
} else {
vbs->sid = biv->bi.res->id;
vbs->stride = biv->stride;
vbs->offset = biv->offset;
}
cbs->bind_cmd_count++;
if (next_bit == i) {
next_bit = find_next_bit(dirty, max_num, i + 1);
if (next_bit >= max_num)
break;
}
}
}
static int vmw_emit_set_vb(struct vmw_ctx_binding_state *cbs)
{
const struct vmw_ctx_bindinfo *loc =
&cbs->vertex_buffers[0].bi;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetVertexBuffers body;
} *cmd;
size_t cmd_size, set_vb_size;
const struct vmw_resource *ctx = vmw_cbs_context(cbs);
vmw_collect_dirty_vbs(cbs, loc, cbs->dirty_vb,
SVGA3D_DX_MAX_VERTEXBUFFERS);
if (cbs->bind_cmd_count == 0)
return 0;
set_vb_size = cbs->bind_cmd_count*sizeof(SVGA3dVertexBuffer);
cmd_size = sizeof(*cmd) + set_vb_size;
cmd = vmw_fifo_reserve_dx(ctx->dev_priv, cmd_size, ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for DX vertex buffer"
" binding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_SET_VERTEX_BUFFERS;
cmd->header.size = sizeof(cmd->body) + set_vb_size;
cmd->body.startBuffer = cbs->bind_first_slot;
memcpy(&cmd[1], cbs->bind_cmd_buffer, set_vb_size);
vmw_fifo_commit(ctx->dev_priv, cmd_size);
bitmap_clear(cbs->dirty_vb,
cbs->bind_first_slot, cbs->bind_cmd_count);
return 0;
}
static int vmw_binding_emit_dirty(struct vmw_ctx_binding_state *cbs)
{
int ret = 0;
unsigned long hit = 0;
while ((hit = find_next_bit(&cbs->dirty, VMW_BINDING_NUM_BITS, hit))
< VMW_BINDING_NUM_BITS) {
switch (hit) {
case VMW_BINDING_RT_BIT:
ret = vmw_emit_set_rt(cbs);
break;
case VMW_BINDING_PS_BIT:
ret = vmw_binding_emit_dirty_ps(cbs);
break;
case VMW_BINDING_SO_BIT:
ret = vmw_emit_set_so(cbs);
break;
case VMW_BINDING_VB_BIT:
ret = vmw_emit_set_vb(cbs);
break;
default:
BUG();
}
if (ret)
return ret;
__clear_bit(hit, &cbs->dirty);
hit++;
}
return 0;
}
static int vmw_binding_scrub_sr(struct vmw_ctx_bindinfo *bi, bool rebind)
{
struct vmw_ctx_bindinfo_view *biv =
container_of(bi, struct vmw_ctx_bindinfo_view, bi);
struct vmw_ctx_binding_state *cbs =
vmw_context_binding_state(bi->ctx);
__set_bit(biv->slot, cbs->per_shader[biv->shader_slot].dirty_sr);
__set_bit(VMW_BINDING_PS_SR_BIT,
&cbs->per_shader[biv->shader_slot].dirty);
__set_bit(VMW_BINDING_PS_BIT, &cbs->dirty);
return 0;
}
static int vmw_binding_scrub_dx_rt(struct vmw_ctx_bindinfo *bi, bool rebind)
{
struct vmw_ctx_binding_state *cbs =
vmw_context_binding_state(bi->ctx);
__set_bit(VMW_BINDING_RT_BIT, &cbs->dirty);
return 0;
}
static int vmw_binding_scrub_so(struct vmw_ctx_bindinfo *bi, bool rebind)
{
struct vmw_ctx_binding_state *cbs =
vmw_context_binding_state(bi->ctx);
__set_bit(VMW_BINDING_SO_BIT, &cbs->dirty);
return 0;
}
static int vmw_binding_scrub_vb(struct vmw_ctx_bindinfo *bi, bool rebind)
{
struct vmw_ctx_bindinfo_vb *bivb =
container_of(bi, struct vmw_ctx_bindinfo_vb, bi);
struct vmw_ctx_binding_state *cbs =
vmw_context_binding_state(bi->ctx);
__set_bit(bivb->slot, cbs->dirty_vb);
__set_bit(VMW_BINDING_VB_BIT, &cbs->dirty);
return 0;
}
static int vmw_binding_scrub_ib(struct vmw_ctx_bindinfo *bi, bool rebind)
{
struct vmw_ctx_bindinfo_ib *binding =
container_of(bi, typeof(*binding), bi);
struct vmw_private *dev_priv = bi->ctx->dev_priv;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDXSetIndexBuffer body;
} *cmd;
cmd = vmw_fifo_reserve_dx(dev_priv, sizeof(*cmd), bi->ctx->id);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for DX index buffer "
"binding.\n");
return -ENOMEM;
}
cmd->header.id = SVGA_3D_CMD_DX_SET_INDEX_BUFFER;
cmd->header.size = sizeof(cmd->body);
if (rebind) {
cmd->body.sid = bi->res->id;
cmd->body.format = binding->format;
cmd->body.offset = binding->offset;
} else {
cmd->body.sid = SVGA3D_INVALID_ID;
cmd->body.format = 0;
cmd->body.offset = 0;
}
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
}
struct vmw_ctx_binding_state *
vmw_binding_state_alloc(struct vmw_private *dev_priv)
{
struct vmw_ctx_binding_state *cbs;
int ret;
ret = ttm_mem_global_alloc(vmw_mem_glob(dev_priv), sizeof(*cbs),
false, false);
if (ret)
return ERR_PTR(ret);
cbs = vzalloc(sizeof(*cbs));
if (!cbs) {
ttm_mem_global_free(vmw_mem_glob(dev_priv), sizeof(*cbs));
return ERR_PTR(-ENOMEM);
}
cbs->dev_priv = dev_priv;
INIT_LIST_HEAD(&cbs->list);
return cbs;
}
void vmw_binding_state_free(struct vmw_ctx_binding_state *cbs)
{
struct vmw_private *dev_priv = cbs->dev_priv;
vfree(cbs);
ttm_mem_global_free(vmw_mem_glob(dev_priv), sizeof(*cbs));
}
struct list_head *vmw_binding_state_list(struct vmw_ctx_binding_state *cbs)
{
return &cbs->list;
}
void vmw_binding_state_reset(struct vmw_ctx_binding_state *cbs)
{
struct vmw_ctx_bindinfo *entry, *next;
list_for_each_entry_safe(entry, next, &cbs->list, ctx_list)
vmw_binding_drop(entry);
}
static void vmw_binding_build_asserts(void)
{
BUILD_BUG_ON(SVGA3D_NUM_SHADERTYPE_DX10 != 3);
BUILD_BUG_ON(SVGA3D_MAX_SIMULTANEOUS_RENDER_TARGETS > SVGA3D_RT_MAX);
BUILD_BUG_ON(sizeof(uint32) != sizeof(u32));
BUILD_BUG_ON(VMW_MAX_VIEW_BINDINGS < SVGA3D_RT_MAX);
BUILD_BUG_ON(VMW_MAX_VIEW_BINDINGS < SVGA3D_DX_MAX_SRVIEWS);
BUILD_BUG_ON(VMW_MAX_VIEW_BINDINGS < SVGA3D_DX_MAX_CONSTBUFFERS);
BUILD_BUG_ON(SVGA3D_DX_MAX_SOTARGETS*sizeof(SVGA3dSoTarget) >
VMW_MAX_VIEW_BINDINGS*sizeof(u32));
BUILD_BUG_ON(SVGA3D_DX_MAX_VERTEXBUFFERS*sizeof(SVGA3dVertexBuffer) >
VMW_MAX_VIEW_BINDINGS*sizeof(u32));
}
