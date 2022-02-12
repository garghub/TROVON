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
static bool validate_cmds_sorted(struct intel_engine_cs *ring,
const struct drm_i915_cmd_table *cmd_tables,
int cmd_table_count)
{
int i;
bool ret = true;
if (!cmd_tables || cmd_table_count == 0)
return true;
for (i = 0; i < cmd_table_count; i++) {
const struct drm_i915_cmd_table *table = &cmd_tables[i];
u32 previous = 0;
int j;
for (j = 0; j < table->count; j++) {
const struct drm_i915_cmd_descriptor *desc =
&table->table[i];
u32 curr = desc->cmd.value & desc->cmd.mask;
if (curr < previous) {
DRM_ERROR("CMD: table not sorted ring=%d table=%d entry=%d cmd=0x%08X prev=0x%08X\n",
ring->id, i, j, curr, previous);
ret = false;
}
previous = curr;
}
}
return ret;
}
static bool check_sorted(int ring_id, const u32 *reg_table, int reg_count)
{
int i;
u32 previous = 0;
bool ret = true;
for (i = 0; i < reg_count; i++) {
u32 curr = reg_table[i];
if (curr < previous) {
DRM_ERROR("CMD: table not sorted ring=%d entry=%d reg=0x%08X prev=0x%08X\n",
ring_id, i, curr, previous);
ret = false;
}
previous = curr;
}
return ret;
}
static bool validate_regs_sorted(struct intel_engine_cs *ring)
{
return check_sorted(ring->id, ring->reg_table, ring->reg_count) &&
check_sorted(ring->id, ring->master_reg_table,
ring->master_reg_count);
}
static int init_hash_table(struct intel_engine_cs *ring,
const struct drm_i915_cmd_table *cmd_tables,
int cmd_table_count)
{
int i, j;
hash_init(ring->cmd_hash);
for (i = 0; i < cmd_table_count; i++) {
const struct drm_i915_cmd_table *table = &cmd_tables[i];
for (j = 0; j < table->count; j++) {
const struct drm_i915_cmd_descriptor *desc =
&table->table[j];
struct cmd_node *desc_node =
kmalloc(sizeof(*desc_node), GFP_KERNEL);
if (!desc_node)
return -ENOMEM;
desc_node->desc = desc;
hash_add(ring->cmd_hash, &desc_node->node,
desc->cmd.value & CMD_HASH_MASK);
}
}
return 0;
}
static void fini_hash_table(struct intel_engine_cs *ring)
{
struct hlist_node *tmp;
struct cmd_node *desc_node;
int i;
hash_for_each_safe(ring->cmd_hash, i, tmp, desc_node, node) {
hash_del(&desc_node->node);
kfree(desc_node);
}
}
int i915_cmd_parser_init_ring(struct intel_engine_cs *ring)
{
const struct drm_i915_cmd_table *cmd_tables;
int cmd_table_count;
int ret;
if (!IS_GEN7(ring->dev))
return 0;
switch (ring->id) {
case RCS:
if (IS_HASWELL(ring->dev)) {
cmd_tables = hsw_render_ring_cmds;
cmd_table_count =
ARRAY_SIZE(hsw_render_ring_cmds);
} else {
cmd_tables = gen7_render_cmds;
cmd_table_count = ARRAY_SIZE(gen7_render_cmds);
}
ring->reg_table = gen7_render_regs;
ring->reg_count = ARRAY_SIZE(gen7_render_regs);
if (IS_HASWELL(ring->dev)) {
ring->master_reg_table = hsw_master_regs;
ring->master_reg_count = ARRAY_SIZE(hsw_master_regs);
} else {
ring->master_reg_table = ivb_master_regs;
ring->master_reg_count = ARRAY_SIZE(ivb_master_regs);
}
ring->get_cmd_length_mask = gen7_render_get_cmd_length_mask;
break;
case VCS:
cmd_tables = gen7_video_cmds;
cmd_table_count = ARRAY_SIZE(gen7_video_cmds);
ring->get_cmd_length_mask = gen7_bsd_get_cmd_length_mask;
break;
case BCS:
if (IS_HASWELL(ring->dev)) {
cmd_tables = hsw_blt_ring_cmds;
cmd_table_count = ARRAY_SIZE(hsw_blt_ring_cmds);
} else {
cmd_tables = gen7_blt_cmds;
cmd_table_count = ARRAY_SIZE(gen7_blt_cmds);
}
ring->reg_table = gen7_blt_regs;
ring->reg_count = ARRAY_SIZE(gen7_blt_regs);
if (IS_HASWELL(ring->dev)) {
ring->master_reg_table = hsw_master_regs;
ring->master_reg_count = ARRAY_SIZE(hsw_master_regs);
} else {
ring->master_reg_table = ivb_master_regs;
ring->master_reg_count = ARRAY_SIZE(ivb_master_regs);
}
ring->get_cmd_length_mask = gen7_blt_get_cmd_length_mask;
break;
case VECS:
cmd_tables = hsw_vebox_cmds;
cmd_table_count = ARRAY_SIZE(hsw_vebox_cmds);
ring->get_cmd_length_mask = gen7_bsd_get_cmd_length_mask;
break;
default:
DRM_ERROR("CMD: cmd_parser_init with unknown ring: %d\n",
ring->id);
BUG();
}
BUG_ON(!validate_cmds_sorted(ring, cmd_tables, cmd_table_count));
BUG_ON(!validate_regs_sorted(ring));
if (hash_empty(ring->cmd_hash)) {
ret = init_hash_table(ring, cmd_tables, cmd_table_count);
if (ret) {
DRM_ERROR("CMD: cmd_parser_init failed!\n");
fini_hash_table(ring);
return ret;
}
}
ring->needs_cmd_parser = true;
return 0;
}
void i915_cmd_parser_fini_ring(struct intel_engine_cs *ring)
{
if (!ring->needs_cmd_parser)
return;
fini_hash_table(ring);
}
static const struct drm_i915_cmd_descriptor*
find_cmd_in_table(struct intel_engine_cs *ring,
u32 cmd_header)
{
struct cmd_node *desc_node;
hash_for_each_possible(ring->cmd_hash, desc_node, node,
cmd_header & CMD_HASH_MASK) {
const struct drm_i915_cmd_descriptor *desc = desc_node->desc;
u32 masked_cmd = desc->cmd.mask & cmd_header;
u32 masked_value = desc->cmd.value & desc->cmd.mask;
if (masked_cmd == masked_value)
return desc;
}
return NULL;
}
static const struct drm_i915_cmd_descriptor*
find_cmd(struct intel_engine_cs *ring,
u32 cmd_header,
struct drm_i915_cmd_descriptor *default_desc)
{
const struct drm_i915_cmd_descriptor *desc;
u32 mask;
desc = find_cmd_in_table(ring, cmd_header);
if (desc)
return desc;
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
bool i915_needs_cmd_parser(struct intel_engine_cs *ring)
{
if (!ring->needs_cmd_parser)
return false;
if (USES_PPGTT(ring->dev))
return false;
return (i915.enable_cmd_parser == 1);
}
static bool check_cmd(const struct intel_engine_cs *ring,
const struct drm_i915_cmd_descriptor *desc,
const u32 *cmd,
const bool is_master,
bool *oacontrol_set)
{
if (desc->flags & CMD_DESC_REJECT) {
DRM_DEBUG_DRIVER("CMD: Rejected command: 0x%08X\n", *cmd);
return false;
}
if ((desc->flags & CMD_DESC_MASTER) && !is_master) {
DRM_DEBUG_DRIVER("CMD: Rejected master-only command: 0x%08X\n",
*cmd);
return false;
}
if (desc->flags & CMD_DESC_REGISTER) {
u32 reg_addr = cmd[desc->reg.offset] & desc->reg.mask;
if (reg_addr == OACONTROL) {
if (desc->cmd.value == MI_LOAD_REGISTER_MEM)
return false;
if (desc->cmd.value == MI_LOAD_REGISTER_IMM(1))
*oacontrol_set = (cmd[2] != 0);
}
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
return false;
}
}
}
if (desc->flags & CMD_DESC_BITMASK) {
int i;
for (i = 0; i < MAX_CMD_DESC_BITMASKS; i++) {
u32 dword;
if (desc->bits[i].mask == 0)
break;
if (desc->bits[i].condition_mask != 0) {
u32 offset =
desc->bits[i].condition_offset;
u32 condition = cmd[offset] &
desc->bits[i].condition_mask;
if (condition == 0)
continue;
}
dword = cmd[desc->bits[i].offset] &
desc->bits[i].mask;
if (dword != desc->bits[i].expected) {
DRM_DEBUG_DRIVER("CMD: Rejected command 0x%08X for bitmask 0x%08X (exp=0x%08X act=0x%08X) (ring=%d)\n",
*cmd,
desc->bits[i].mask,
desc->bits[i].expected,
dword, ring->id);
return false;
}
}
}
return true;
}
int i915_parse_cmds(struct intel_engine_cs *ring,
struct drm_i915_gem_object *batch_obj,
u32 batch_start_offset,
bool is_master)
{
int ret = 0;
u32 *cmd, *batch_base, *batch_end;
struct drm_i915_cmd_descriptor default_desc = { 0 };
int needs_clflush = 0;
bool oacontrol_set = false;
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
DRM_DEBUG_DRIVER("CMD: Command length exceeds batch length: 0x%08X length=%u batchlen=%td\n",
*cmd,
length,
batch_end - cmd);
ret = -EINVAL;
break;
}
if (!check_cmd(ring, desc, cmd, is_master, &oacontrol_set)) {
ret = -EINVAL;
break;
}
cmd += length;
}
if (oacontrol_set) {
DRM_DEBUG_DRIVER("CMD: batch set OACONTROL but did not clear it\n");
ret = -EINVAL;
}
if (cmd >= batch_end) {
DRM_DEBUG_DRIVER("CMD: Got to the end of the buffer w/o a BBE cmd!\n");
ret = -EINVAL;
}
vunmap(batch_base);
i915_gem_object_unpin_pages(batch_obj);
return ret;
}
int i915_cmd_parser_get_version(void)
{
return 1;
}
