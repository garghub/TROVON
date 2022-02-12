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
u32 client = (cmd_header & INSTR_CLIENT_MASK) >> INSTR_CLIENT_SHIFT;
if (client == INSTR_MI_CLIENT)
return 0x3F;
else if (client == INSTR_BC_CLIENT)
return 0xFF;
DRM_DEBUG_DRIVER("CMD: Abnormal blt cmd length! 0x%08X\n", cmd_header);
return 0;
}
static bool validate_cmds_sorted(struct intel_engine_cs *engine,
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
DRM_ERROR("CMD: table not sorted ring=%d table=%d entry=%d cmd=0x%08X prev=0x%08X\n",
engine->id, i, j, curr, previous);
ret = false;
}
previous = curr;
}
}
return ret;
}
static bool check_sorted(int ring_id,
const struct drm_i915_reg_descriptor *reg_table,
int reg_count)
{
int i;
u32 previous = 0;
bool ret = true;
for (i = 0; i < reg_count; i++) {
u32 curr = i915_mmio_reg_offset(reg_table[i].addr);
if (curr < previous) {
DRM_ERROR("CMD: table not sorted ring=%d entry=%d reg=0x%08X prev=0x%08X\n",
ring_id, i, curr, previous);
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
if (!check_sorted(engine->id, table->regs, table->num_regs))
return false;
}
return true;
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
desc->cmd.value & CMD_HASH_MASK);
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
int i915_cmd_parser_init_ring(struct intel_engine_cs *engine)
{
const struct drm_i915_cmd_table *cmd_tables;
int cmd_table_count;
int ret;
if (!IS_GEN7(engine->i915))
return 0;
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
DRM_ERROR("CMD: cmd_parser_init with unknown ring: %d\n",
engine->id);
BUG();
}
BUG_ON(!validate_cmds_sorted(engine, cmd_tables, cmd_table_count));
BUG_ON(!validate_regs_sorted(engine));
WARN_ON(!hash_empty(engine->cmd_hash));
ret = init_hash_table(engine, cmd_tables, cmd_table_count);
if (ret) {
DRM_ERROR("CMD: cmd_parser_init failed!\n");
fini_hash_table(engine);
return ret;
}
engine->needs_cmd_parser = true;
return 0;
}
void i915_cmd_parser_fini_ring(struct intel_engine_cs *engine)
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
find_cmd(struct intel_engine_cs *engine,
u32 cmd_header,
struct drm_i915_cmd_descriptor *default_desc)
{
const struct drm_i915_cmd_descriptor *desc;
u32 mask;
desc = find_cmd_in_table(engine, cmd_header);
if (desc)
return desc;
mask = engine->get_cmd_length_mask(cmd_header);
if (!mask)
return NULL;
BUG_ON(!default_desc);
default_desc->flags = CMD_DESC_SKIP;
default_desc->length.mask = mask;
return default_desc;
}
static const struct drm_i915_reg_descriptor *
find_reg(const struct drm_i915_reg_descriptor *table,
int count, u32 addr)
{
int i;
for (i = 0; i < count; i++) {
if (i915_mmio_reg_offset(table[i].addr) == addr)
return &table[i];
}
return NULL;
}
static const struct drm_i915_reg_descriptor *
find_reg_in_tables(const struct drm_i915_reg_table *tables,
int count, bool is_master, u32 addr)
{
int i;
const struct drm_i915_reg_table *table;
const struct drm_i915_reg_descriptor *reg;
for (i = 0; i < count; i++) {
table = &tables[i];
if (!table->master || is_master) {
reg = find_reg(table->regs, table->num_regs,
addr);
if (reg != NULL)
return reg;
}
}
return NULL;
}
static u32 *vmap_batch(struct drm_i915_gem_object *obj,
unsigned start, unsigned len)
{
int i;
void *addr = NULL;
struct sg_page_iter sg_iter;
int first_page = start >> PAGE_SHIFT;
int last_page = (len + start + 4095) >> PAGE_SHIFT;
int npages = last_page - first_page;
struct page **pages;
pages = drm_malloc_ab(npages, sizeof(*pages));
if (pages == NULL) {
DRM_DEBUG_DRIVER("Failed to get space for pages\n");
goto finish;
}
i = 0;
for_each_sg_page(obj->pages->sgl, &sg_iter, obj->pages->nents, first_page) {
pages[i++] = sg_page_iter_page(&sg_iter);
if (i == npages)
break;
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
static u32 *copy_batch(struct drm_i915_gem_object *dest_obj,
struct drm_i915_gem_object *src_obj,
u32 batch_start_offset,
u32 batch_len)
{
int needs_clflush = 0;
void *src_base, *src;
void *dst = NULL;
int ret;
if (batch_len > dest_obj->base.size ||
batch_len + batch_start_offset > src_obj->base.size)
return ERR_PTR(-E2BIG);
if (WARN_ON(dest_obj->pages_pin_count == 0))
return ERR_PTR(-ENODEV);
ret = i915_gem_obj_prepare_shmem_read(src_obj, &needs_clflush);
if (ret) {
DRM_DEBUG_DRIVER("CMD: failed to prepare shadow batch\n");
return ERR_PTR(ret);
}
src_base = vmap_batch(src_obj, batch_start_offset, batch_len);
if (!src_base) {
DRM_DEBUG_DRIVER("CMD: Failed to vmap batch\n");
ret = -ENOMEM;
goto unpin_src;
}
ret = i915_gem_object_set_to_cpu_domain(dest_obj, true);
if (ret) {
DRM_DEBUG_DRIVER("CMD: Failed to set shadow batch to CPU\n");
goto unmap_src;
}
dst = vmap_batch(dest_obj, 0, batch_len);
if (!dst) {
DRM_DEBUG_DRIVER("CMD: Failed to vmap shadow batch\n");
ret = -ENOMEM;
goto unmap_src;
}
src = src_base + offset_in_page(batch_start_offset);
if (needs_clflush)
drm_clflush_virt_range(src, batch_len);
memcpy(dst, src, batch_len);
unmap_src:
vunmap(src_base);
unpin_src:
i915_gem_object_unpin_pages(src_obj);
return ret ? ERR_PTR(ret) : dst;
}
bool i915_needs_cmd_parser(struct intel_engine_cs *engine)
{
if (!engine->needs_cmd_parser)
return false;
if (!USES_PPGTT(engine->i915))
return false;
return (i915.enable_cmd_parser == 1);
}
static bool check_cmd(const struct intel_engine_cs *engine,
const struct drm_i915_cmd_descriptor *desc,
const u32 *cmd, u32 length,
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
const u32 step = desc->reg.step ? desc->reg.step : length;
u32 offset;
for (offset = desc->reg.offset; offset < length;
offset += step) {
const u32 reg_addr = cmd[offset] & desc->reg.mask;
const struct drm_i915_reg_descriptor *reg =
find_reg_in_tables(engine->reg_tables,
engine->reg_table_count,
is_master,
reg_addr);
if (!reg) {
DRM_DEBUG_DRIVER("CMD: Rejected register 0x%08X in command: 0x%08X (ring=%d)\n",
reg_addr, *cmd, engine->id);
return false;
}
if (reg_addr == i915_mmio_reg_offset(OACONTROL)) {
if (desc->cmd.value == MI_LOAD_REGISTER_MEM) {
DRM_DEBUG_DRIVER("CMD: Rejected LRM to OACONTROL\n");
return false;
}
if (desc->cmd.value == MI_LOAD_REGISTER_REG) {
DRM_DEBUG_DRIVER("CMD: Rejected LRR to OACONTROL\n");
return false;
}
if (desc->cmd.value == MI_LOAD_REGISTER_IMM(1))
*oacontrol_set = (cmd[offset + 1] != 0);
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
DRM_DEBUG_DRIVER("CMD: Rejected command 0x%08X for bitmask 0x%08X (exp=0x%08X act=0x%08X) (ring=%d)\n",
*cmd,
desc->bits[i].mask,
desc->bits[i].expected,
dword, engine->id);
return false;
}
}
}
return true;
}
int i915_parse_cmds(struct intel_engine_cs *engine,
struct drm_i915_gem_object *batch_obj,
struct drm_i915_gem_object *shadow_batch_obj,
u32 batch_start_offset,
u32 batch_len,
bool is_master)
{
u32 *cmd, *batch_base, *batch_end;
struct drm_i915_cmd_descriptor default_desc = { 0 };
bool oacontrol_set = false;
int ret = 0;
batch_base = copy_batch(shadow_batch_obj, batch_obj,
batch_start_offset, batch_len);
if (IS_ERR(batch_base)) {
DRM_DEBUG_DRIVER("CMD: Failed to copy batch\n");
return PTR_ERR(batch_base);
}
batch_end = batch_base + (batch_len / sizeof(*batch_end));
cmd = batch_base;
while (cmd < batch_end) {
const struct drm_i915_cmd_descriptor *desc;
u32 length;
if (*cmd == MI_BATCH_BUFFER_END)
break;
desc = find_cmd(engine, *cmd, &default_desc);
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
if (!check_cmd(engine, desc, cmd, length, is_master,
&oacontrol_set)) {
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
return ret;
}
int i915_cmd_parser_get_version(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
bool active = false;
for_each_engine(engine, dev_priv) {
if (i915_needs_cmd_parser(engine)) {
active = true;
break;
}
}
if (!active)
return 0;
return 7;
}
