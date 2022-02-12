static u32 gen7_render_get_cmd_length_mask(u32 cmd_header)
{
u32 client = cmd_header >> INSTR_CLIENT_SHIFT;
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
u32 client = cmd_header >> INSTR_CLIENT_SHIFT;
u32 subclient =
(cmd_header & INSTR_SUBCLIENT_MASK) >> INSTR_SUBCLIENT_SHIFT;
u32 op = (cmd_header & INSTR_26_TO_24_MASK) >> INSTR_26_TO_24_SHIFT;
if (client == INSTR_MI_CLIENT)
return 0x3F;
else if (client == INSTR_RC_CLIENT) {
if (subclient == INSTR_MEDIA_SUBCLIENT) {
if (op == 6)
return 0xFFFF;
else
return 0xFFF;
} else
return 0xFF;
}
DRM_DEBUG_DRIVER("CMD: Abnormal bsd cmd length! 0x%08X\n", cmd_header);
return 0;
}
static u32 gen7_blt_get_cmd_length_mask(u32 cmd_header)
{
u32 client = cmd_header >> INSTR_CLIENT_SHIFT;
if (client == INSTR_MI_CLIENT)
return 0x3F;
else if (client == INSTR_BC_CLIENT)
return 0xFF;
DRM_DEBUG_DRIVER("CMD: Abnormal blt cmd length! 0x%08X\n", cmd_header);
return 0;
}
static bool validate_cmds_sorted(const struct intel_engine_cs *engine,
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
&table->table[j];
u32 curr = desc->cmd.value & desc->cmd.mask;
if (curr < previous) {
DRM_ERROR("CMD: %s [%d] command table not sorted: "
"table=%d entry=%d cmd=0x%08X prev=0x%08X\n",
engine->name, engine->id,
i, j, curr, previous);
ret = false;
}
previous = curr;
}
}
return ret;
}
static bool check_sorted(const struct intel_engine_cs *engine,
const struct drm_i915_reg_descriptor *reg_table,
int reg_count)
{
int i;
u32 previous = 0;
bool ret = true;
for (i = 0; i < reg_count; i++) {
u32 curr = i915_mmio_reg_offset(reg_table[i].addr);
if (curr < previous) {
DRM_ERROR("CMD: %s [%d] register table not sorted: "
"entry=%d reg=0x%08X prev=0x%08X\n",
engine->name, engine->id,
i, curr, previous);
ret = false;
}
previous = curr;
}
return ret;
}
static bool validate_regs_sorted(struct intel_engine_cs *engine)
{
int i;
const struct drm_i915_reg_table *table;
for (i = 0; i < engine->reg_table_count; i++) {
table = &engine->reg_tables[i];
if (!check_sorted(engine, table->regs, table->num_regs))
return false;
}
return true;
}
static inline u32 cmd_header_key(u32 x)
{
u32 shift;
switch (x >> INSTR_CLIENT_SHIFT) {
default:
case INSTR_MI_CLIENT:
shift = STD_MI_OPCODE_SHIFT;
break;
case INSTR_RC_CLIENT:
shift = STD_3D_OPCODE_SHIFT;
break;
case INSTR_BC_CLIENT:
shift = STD_2D_OPCODE_SHIFT;
break;
}
return x >> shift;
}
static int init_hash_table(struct intel_engine_cs *engine,
const struct drm_i915_cmd_table *cmd_tables,
int cmd_table_count)
{
int i, j;
hash_init(engine->cmd_hash);
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
hash_add(engine->cmd_hash, &desc_node->node,
cmd_header_key(desc->cmd.value));
}
}
return 0;
}
static void fini_hash_table(struct intel_engine_cs *engine)
{
struct hlist_node *tmp;
struct cmd_node *desc_node;
int i;
hash_for_each_safe(engine->cmd_hash, i, tmp, desc_node, node) {
hash_del(&desc_node->node);
kfree(desc_node);
}
}
void intel_engine_init_cmd_parser(struct intel_engine_cs *engine)
{
const struct drm_i915_cmd_table *cmd_tables;
int cmd_table_count;
int ret;
if (!IS_GEN7(engine->i915))
return;
switch (engine->id) {
case RCS:
if (IS_HASWELL(engine->i915)) {
cmd_tables = hsw_render_ring_cmds;
cmd_table_count =
ARRAY_SIZE(hsw_render_ring_cmds);
} else {
cmd_tables = gen7_render_cmds;
cmd_table_count = ARRAY_SIZE(gen7_render_cmds);
}
if (IS_HASWELL(engine->i915)) {
engine->reg_tables = hsw_render_reg_tables;
engine->reg_table_count = ARRAY_SIZE(hsw_render_reg_tables);
} else {
engine->reg_tables = ivb_render_reg_tables;
engine->reg_table_count = ARRAY_SIZE(ivb_render_reg_tables);
}
engine->get_cmd_length_mask = gen7_render_get_cmd_length_mask;
break;
case VCS:
cmd_tables = gen7_video_cmds;
cmd_table_count = ARRAY_SIZE(gen7_video_cmds);
engine->get_cmd_length_mask = gen7_bsd_get_cmd_length_mask;
break;
case BCS:
if (IS_HASWELL(engine->i915)) {
cmd_tables = hsw_blt_ring_cmds;
cmd_table_count = ARRAY_SIZE(hsw_blt_ring_cmds);
} else {
cmd_tables = gen7_blt_cmds;
cmd_table_count = ARRAY_SIZE(gen7_blt_cmds);
}
if (IS_HASWELL(engine->i915)) {
engine->reg_tables = hsw_blt_reg_tables;
engine->reg_table_count = ARRAY_SIZE(hsw_blt_reg_tables);
} else {
engine->reg_tables = ivb_blt_reg_tables;
engine->reg_table_count = ARRAY_SIZE(ivb_blt_reg_tables);
}
engine->get_cmd_length_mask = gen7_blt_get_cmd_length_mask;
break;
case VECS:
cmd_tables = hsw_vebox_cmds;
cmd_table_count = ARRAY_SIZE(hsw_vebox_cmds);
engine->get_cmd_length_mask = gen7_bsd_get_cmd_length_mask;
break;
default:
MISSING_CASE(engine->id);
return;
}
if (!validate_cmds_sorted(engine, cmd_tables, cmd_table_count)) {
DRM_ERROR("%s: command descriptions are not sorted\n",
engine->name);
return;
}
if (!validate_regs_sorted(engine)) {
DRM_ERROR("%s: registers are not sorted\n", engine->name);
return;
}
ret = init_hash_table(engine, cmd_tables, cmd_table_count);
if (ret) {
DRM_ERROR("%s: initialised failed!\n", engine->name);
fini_hash_table(engine);
return;
}
engine->needs_cmd_parser = true;
}
void intel_engine_cleanup_cmd_parser(struct intel_engine_cs *engine)
{
if (!engine->needs_cmd_parser)
return;
fini_hash_table(engine);
}
static const struct drm_i915_cmd_descriptor*
find_cmd_in_table(struct intel_engine_cs *engine,
u32 cmd_header)
{
struct cmd_node *desc_node;
hash_for_each_possible(engine->cmd_hash, desc_node, node,
cmd_header_key(cmd_header)) {
const struct drm_i915_cmd_descriptor *desc = desc_node->desc;
if (((cmd_header ^ desc->cmd.value) & desc->cmd.mask) == 0)
return desc;
}
return NULL;
}
static const struct drm_i915_cmd_descriptor*
find_cmd(struct intel_engine_cs *engine,
u32 cmd_header,
const struct drm_i915_cmd_descriptor *desc,
struct drm_i915_cmd_descriptor *default_desc)
{
u32 mask;
if (((cmd_header ^ desc->cmd.value) & desc->cmd.mask) == 0)
return desc;
desc = find_cmd_in_table(engine, cmd_header);
if (desc)
return desc;
mask = engine->get_cmd_length_mask(cmd_header);
if (!mask)
return NULL;
default_desc->cmd.value = cmd_header;
default_desc->cmd.mask = ~0u << MIN_OPCODE_SHIFT;
default_desc->length.mask = mask;
default_desc->flags = CMD_DESC_SKIP;
return default_desc;
}
static const struct drm_i915_reg_descriptor *
__find_reg(const struct drm_i915_reg_descriptor *table, int count, u32 addr)
{
int start = 0, end = count;
while (start < end) {
int mid = start + (end - start) / 2;
int ret = addr - i915_mmio_reg_offset(table[mid].addr);
if (ret < 0)
end = mid;
else if (ret > 0)
start = mid + 1;
else
return &table[mid];
}
return NULL;
}
static const struct drm_i915_reg_descriptor *
find_reg(const struct intel_engine_cs *engine, bool is_master, u32 addr)
{
const struct drm_i915_reg_table *table = engine->reg_tables;
int count = engine->reg_table_count;
do {
if (!table->master || is_master) {
const struct drm_i915_reg_descriptor *reg;
reg = __find_reg(table->regs, table->num_regs, addr);
if (reg != NULL)
return reg;
}
} while (table++, --count);
return NULL;
}
static u32 *copy_batch(struct drm_i915_gem_object *dst_obj,
struct drm_i915_gem_object *src_obj,
u32 batch_start_offset,
u32 batch_len,
bool *needs_clflush_after)
{
unsigned int src_needs_clflush;
unsigned int dst_needs_clflush;
void *dst, *src;
int ret;
ret = i915_gem_obj_prepare_shmem_read(src_obj, &src_needs_clflush);
if (ret)
return ERR_PTR(ret);
ret = i915_gem_obj_prepare_shmem_write(dst_obj, &dst_needs_clflush);
if (ret) {
dst = ERR_PTR(ret);
goto unpin_src;
}
dst = i915_gem_object_pin_map(dst_obj, I915_MAP_WB);
if (IS_ERR(dst))
goto unpin_dst;
src = ERR_PTR(-ENODEV);
if (src_needs_clflush &&
i915_can_memcpy_from_wc(NULL, batch_start_offset, 0)) {
src = i915_gem_object_pin_map(src_obj, I915_MAP_WC);
if (!IS_ERR(src)) {
i915_memcpy_from_wc(dst,
src + batch_start_offset,
ALIGN(batch_len, 16));
i915_gem_object_unpin_map(src_obj);
}
}
if (IS_ERR(src)) {
void *ptr;
int offset, n;
offset = offset_in_page(batch_start_offset);
if (dst_needs_clflush & CLFLUSH_BEFORE)
batch_len = roundup(batch_len,
boot_cpu_data.x86_clflush_size);
ptr = dst;
for (n = batch_start_offset >> PAGE_SHIFT; batch_len; n++) {
int len = min_t(int, batch_len, PAGE_SIZE - offset);
src = kmap_atomic(i915_gem_object_get_page(src_obj, n));
if (src_needs_clflush)
drm_clflush_virt_range(src + offset, len);
memcpy(ptr, src + offset, len);
kunmap_atomic(src);
ptr += len;
batch_len -= len;
offset = 0;
}
}
*needs_clflush_after = dst_needs_clflush & CLFLUSH_AFTER;
unpin_dst:
i915_gem_obj_finish_shmem_access(dst_obj);
unpin_src:
i915_gem_obj_finish_shmem_access(src_obj);
return dst;
}
static bool check_cmd(const struct intel_engine_cs *engine,
const struct drm_i915_cmd_descriptor *desc,
const u32 *cmd, u32 length,
const bool is_master)
{
if (desc->flags & CMD_DESC_SKIP)
return true;
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
const u32 step = desc->reg.step ? desc->reg.step : length;
u32 offset;
for (offset = desc->reg.offset; offset < length;
offset += step) {
const u32 reg_addr = cmd[offset] & desc->reg.mask;
const struct drm_i915_reg_descriptor *reg =
find_reg(engine, is_master, reg_addr);
if (!reg) {
DRM_DEBUG_DRIVER("CMD: Rejected register 0x%08X in command: 0x%08X (exec_id=%d)\n",
reg_addr, *cmd, engine->exec_id);
return false;
}
if (reg->mask) {
if (desc->cmd.value == MI_LOAD_REGISTER_MEM) {
DRM_DEBUG_DRIVER("CMD: Rejected LRM to masked register 0x%08X\n",
reg_addr);
return false;
}
if (desc->cmd.value == MI_LOAD_REGISTER_REG) {
DRM_DEBUG_DRIVER("CMD: Rejected LRR to masked register 0x%08X\n",
reg_addr);
return false;
}
if (desc->cmd.value == MI_LOAD_REGISTER_IMM(1) &&
(offset + 2 > length ||
(cmd[offset + 1] & reg->mask) != reg->value)) {
DRM_DEBUG_DRIVER("CMD: Rejected LRI to masked register 0x%08X\n",
reg_addr);
return false;
}
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
DRM_DEBUG_DRIVER("CMD: Rejected command 0x%08X for bitmask 0x%08X (exp=0x%08X act=0x%08X) (exec_id=%d)\n",
*cmd,
desc->bits[i].mask,
desc->bits[i].expected,
dword, engine->exec_id);
return false;
}
}
}
return true;
}
int intel_engine_cmd_parser(struct intel_engine_cs *engine,
struct drm_i915_gem_object *batch_obj,
struct drm_i915_gem_object *shadow_batch_obj,
u32 batch_start_offset,
u32 batch_len,
bool is_master)
{
u32 *cmd, *batch_end;
struct drm_i915_cmd_descriptor default_desc = noop_desc;
const struct drm_i915_cmd_descriptor *desc = &default_desc;
bool needs_clflush_after = false;
int ret = 0;
cmd = copy_batch(shadow_batch_obj, batch_obj,
batch_start_offset, batch_len,
&needs_clflush_after);
if (IS_ERR(cmd)) {
DRM_DEBUG_DRIVER("CMD: Failed to copy batch\n");
return PTR_ERR(cmd);
}
batch_end = cmd + (batch_len / sizeof(*batch_end));
while (cmd < batch_end) {
u32 length;
if (*cmd == MI_BATCH_BUFFER_END)
break;
desc = find_cmd(engine, *cmd, desc, &default_desc);
if (!desc) {
DRM_DEBUG_DRIVER("CMD: Unrecognized command: 0x%08X\n",
*cmd);
ret = -EINVAL;
break;
}
if (desc->cmd.value == MI_BATCH_BUFFER_START) {
ret = -EACCES;
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
if (!check_cmd(engine, desc, cmd, length, is_master)) {
ret = -EACCES;
break;
}
cmd += length;
}
if (cmd >= batch_end) {
DRM_DEBUG_DRIVER("CMD: Got to the end of the buffer w/o a BBE cmd!\n");
ret = -EINVAL;
}
if (ret == 0 && needs_clflush_after)
drm_clflush_virt_range(shadow_batch_obj->mm.mapping, batch_len);
i915_gem_object_unpin_map(shadow_batch_obj);
return ret;
}
int i915_cmd_parser_get_version(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
bool active = false;
for_each_engine(engine, dev_priv, id) {
if (engine->needs_cmd_parser) {
active = true;
break;
}
}
if (!active)
return 0;
return 9;
}
