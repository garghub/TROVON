static u32 gen7_render_get_cmd_length_mask(u32 cmd_header)
{
u32 client = (cmd_header & INSTR_CLIENT_MASK) >> INSTR_CLIENT_SHIFT;
u32 subclient =
(cmd_header & INSTR_SUBCLIENT_MASK) >> INSTR_SUBCLIENT_SHIFT;
if (client == INSTR_MI_CLIENT)
return 0x3F;
else if (client == INSTR_RC_CLIENT) {
if (subclient == INSTR_MEDIA_SUBCLIENT)
return 0xFFFF;
else
return 0xFF;
}
DRM_DEBUG_DRIVER("CMD: Abnormal rcs cmd length! 0x%08X\n", cmd_header);
return 0;
}
static u32 gen7_bsd_get_cmd_length_mask(u32 cmd_header)
{
u32 client = (cmd_header & INSTR_CLIENT_MASK) >> INSTR_CLIENT_SHIFT;
u32 subclient =
(cmd_header & INSTR_SUBCLIENT_MASK) >> INSTR_SUBCLIENT_SHIFT;
if (client == INSTR_MI_CLIENT)
return 0x3F;
else if (client == INSTR_RC_CLIENT) {
if (subclient == INSTR_MEDIA_SUBCLIENT)
return 0xFFF;
else
return 0xFF;
}
DRM_DEBUG_DRIVER("CMD: Abnormal bsd cmd length! 0x%08X\n", cmd_header);
return 0;
}
static u32 gen7_blt_get_cmd_length_mask(u32 cmd_header)
{
u32 client = (cmd_header & INSTR_CLIENT_MASK) >> INSTR_CLIENT_SHIFT;
if (client == INSTR_MI_CLIENT)
return 0x3F;
else if (client == INSTR_BC_CLIENT)
return 0xFF;
DRM_DEBUG_DRIVER("CMD: Abnormal blt cmd length! 0x%08X\n", cmd_header);
return 0;
}
static void validate_cmds_sorted(struct intel_ring_buffer *ring)
{
int i;
if (!ring->cmd_tables || ring->cmd_table_count == 0)
return;
for (i = 0; i < ring->cmd_table_count; i++) {
const struct drm_i915_cmd_table *table = &ring->cmd_tables[i];
u32 previous = 0;
int j;
for (j = 0; j < table->count; j++) {
const struct drm_i915_cmd_descriptor *desc =
&table->table[i];
u32 curr = desc->cmd.value & desc->cmd.mask;
if (curr < previous)
DRM_ERROR("CMD: table not sorted ring=%d table=%d entry=%d cmd=0x%08X prev=0x%08X\n",
ring->id, i, j, curr, previous);
previous = curr;
}
}
}
static void check_sorted(int ring_id, const u32 *reg_table, int reg_count)
{
int i;
u32 previous = 0;
for (i = 0; i < reg_count; i++) {
u32 curr = reg_table[i];
if (curr < previous)
DRM_ERROR("CMD: table not sorted ring=%d entry=%d reg=0x%08X prev=0x%08X\n",
ring_id, i, curr, previous);
previous = curr;
}
}
static void validate_regs_sorted(struct intel_ring_buffer *ring)
{
check_sorted(ring->id, ring->reg_table, ring->reg_count);
check_sorted(ring->id, ring->master_reg_table, ring->master_reg_count);
}
void i915_cmd_parser_init_ring(struct intel_ring_buffer *ring)
{
if (!IS_GEN7(ring->dev))
return;
switch (ring->id) {
case RCS:
ring->get_cmd_length_mask = gen7_render_get_cmd_length_mask;
break;
case VCS:
ring->get_cmd_length_mask = gen7_bsd_get_cmd_length_mask;
break;
case BCS:
ring->get_cmd_length_mask = gen7_blt_get_cmd_length_mask;
break;
case VECS:
ring->get_cmd_length_mask = gen7_bsd_get_cmd_length_mask;
break;
default:
DRM_ERROR("CMD: cmd_parser_init with unknown ring: %d\n",
ring->id);
BUG();
}
validate_cmds_sorted(ring);
validate_regs_sorted(ring);
}
static const struct drm_i915_cmd_descriptor*
find_cmd_in_table(const struct drm_i915_cmd_table *table,
u32 cmd_header)
{
int i;
for (i = 0; i < table->count; i++) {
const struct drm_i915_cmd_descriptor *desc = &table->table[i];
u32 masked_cmd = desc->cmd.mask & cmd_header;
u32 masked_value = desc->cmd.value & desc->cmd.mask;
if (masked_cmd == masked_value)
return desc;
}
return NULL;
}
static const struct drm_i915_cmd_descriptor*
find_cmd(struct intel_ring_buffer *ring,
u32 cmd_header,
struct drm_i915_cmd_descriptor *default_desc)
{
u32 mask;
int i;
for (i = 0; i < ring->cmd_table_count; i++) {
const struct drm_i915_cmd_descriptor *desc;
desc = find_cmd_in_table(&ring->cmd_tables[i], cmd_header);
if (desc)
return desc;
}
mask = ring->get_cmd_length_mask(cmd_header);
if (!mask)
return NULL;
BUG_ON(!default_desc);
default_desc->flags = CMD_DESC_SKIP;
default_desc->length.mask = mask;
return default_desc;
}
static bool valid_reg(const u32 *table, int count, u32 addr)
{
if (table && count != 0) {
int i;
for (i = 0; i < count; i++) {
if (table[i] == addr)
return true;
}
}
return false;
}
static u32 *vmap_batch(struct drm_i915_gem_object *obj)
{
int i;
void *addr = NULL;
struct sg_page_iter sg_iter;
struct page **pages;
pages = drm_malloc_ab(obj->base.size >> PAGE_SHIFT, sizeof(*pages));
if (pages == NULL) {
DRM_DEBUG_DRIVER("Failed to get space for pages\n");
goto finish;
}
i = 0;
for_each_sg_page(obj->pages->sgl, &sg_iter, obj->pages->nents, 0) {
pages[i] = sg_page_iter_page(&sg_iter);
i++;
}
addr = vmap(pages, i, 0, PAGE_KERNEL);
if (addr == NULL) {
DRM_DEBUG_DRIVER("Failed to vmap pages\n");
goto finish;
}
finish:
if (pages)
drm_free_large(pages);
return (u32*)addr;
}
bool i915_needs_cmd_parser(struct intel_ring_buffer *ring)
{
if (!ring->cmd_tables)
return false;
return (i915.enable_cmd_parser == 1);
}
int i915_parse_cmds(struct intel_ring_buffer *ring,
struct drm_i915_gem_object *batch_obj,
u32 batch_start_offset,
bool is_master)
{
int ret = 0;
u32 *cmd, *batch_base, *batch_end;
struct drm_i915_cmd_descriptor default_desc = { 0 };
int needs_clflush = 0;
ret = i915_gem_obj_prepare_shmem_read(batch_obj, &needs_clflush);
if (ret) {
DRM_DEBUG_DRIVER("CMD: failed to prep read\n");
return ret;
}
batch_base = vmap_batch(batch_obj);
if (!batch_base) {
DRM_DEBUG_DRIVER("CMD: Failed to vmap batch\n");
i915_gem_object_unpin_pages(batch_obj);
return -ENOMEM;
}
if (needs_clflush)
drm_clflush_virt_range((char *)batch_base, batch_obj->base.size);
cmd = batch_base + (batch_start_offset / sizeof(*cmd));
batch_end = cmd + (batch_obj->base.size / sizeof(*batch_end));
while (cmd < batch_end) {
const struct drm_i915_cmd_descriptor *desc;
u32 length;
if (*cmd == MI_BATCH_BUFFER_END)
break;
desc = find_cmd(ring, *cmd, &default_desc);
if (!desc) {
DRM_DEBUG_DRIVER("CMD: Unrecognized command: 0x%08X\n",
*cmd);
ret = -EINVAL;
break;
}
if (desc->flags & CMD_DESC_FIXED)
length = desc->length.fixed;
else
length = ((*cmd & desc->length.mask) + LENGTH_BIAS);
if ((batch_end - cmd) < length) {
DRM_DEBUG_DRIVER("CMD: Command length exceeds batch length: 0x%08X length=%d batchlen=%td\n",
*cmd,
length,
(unsigned long)(batch_end - cmd));
ret = -EINVAL;
break;
}
if (desc->flags & CMD_DESC_REJECT) {
DRM_DEBUG_DRIVER("CMD: Rejected command: 0x%08X\n", *cmd);
ret = -EINVAL;
break;
}
if ((desc->flags & CMD_DESC_MASTER) && !is_master) {
DRM_DEBUG_DRIVER("CMD: Rejected master-only command: 0x%08X\n",
*cmd);
ret = -EINVAL;
break;
}
if (desc->flags & CMD_DESC_REGISTER) {
u32 reg_addr = cmd[desc->reg.offset] & desc->reg.mask;
if (!valid_reg(ring->reg_table,
ring->reg_count, reg_addr)) {
if (!is_master ||
!valid_reg(ring->master_reg_table,
ring->master_reg_count,
reg_addr)) {
DRM_DEBUG_DRIVER("CMD: Rejected register 0x%08X in command: 0x%08X (ring=%d)\n",
reg_addr,
*cmd,
ring->id);
ret = -EINVAL;
break;
}
}
}
if (desc->flags & CMD_DESC_BITMASK) {
int i;
for (i = 0; i < MAX_CMD_DESC_BITMASKS; i++) {
u32 dword;
if (desc->bits[i].mask == 0)
break;
dword = cmd[desc->bits[i].offset] &
desc->bits[i].mask;
if (dword != desc->bits[i].expected) {
DRM_DEBUG_DRIVER("CMD: Rejected command 0x%08X for bitmask 0x%08X (exp=0x%08X act=0x%08X) (ring=%d)\n",
*cmd,
desc->bits[i].mask,
desc->bits[i].expected,
dword, ring->id);
ret = -EINVAL;
break;
}
}
if (ret)
break;
}
cmd += length;
}
if (cmd >= batch_end) {
DRM_DEBUG_DRIVER("CMD: Got to the end of the buffer w/o a BBE cmd!\n");
ret = -EINVAL;
}
vunmap(batch_base);
i915_gem_object_unpin_pages(batch_obj);
return ret;
}
