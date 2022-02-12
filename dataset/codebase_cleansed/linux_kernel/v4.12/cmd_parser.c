static inline u32 get_opcode(u32 cmd, int ring_id)
{
struct decode_info *d_info;
d_info = ring_decode_info[ring_id][CMD_TYPE(cmd)];
if (d_info == NULL)
return INVALID_OP;
return cmd >> (32 - d_info->op_len);
}
static inline struct cmd_info *find_cmd_entry(struct intel_gvt *gvt,
unsigned int opcode, int ring_id)
{
struct cmd_entry *e;
hash_for_each_possible(gvt->cmd_table, e, hlist, opcode) {
if ((opcode == e->info->opcode) &&
(e->info->rings & (1 << ring_id)))
return e->info;
}
return NULL;
}
static inline struct cmd_info *get_cmd_info(struct intel_gvt *gvt,
u32 cmd, int ring_id)
{
u32 opcode;
opcode = get_opcode(cmd, ring_id);
if (opcode == INVALID_OP)
return NULL;
return find_cmd_entry(gvt, opcode, ring_id);
}
static inline u32 sub_op_val(u32 cmd, u32 hi, u32 low)
{
return (cmd >> low) & ((1U << (hi - low + 1)) - 1);
}
static inline void print_opcode(u32 cmd, int ring_id)
{
struct decode_info *d_info;
int i;
d_info = ring_decode_info[ring_id][CMD_TYPE(cmd)];
if (d_info == NULL)
return;
gvt_dbg_cmd("opcode=0x%x %s sub_ops:",
cmd >> (32 - d_info->op_len), d_info->name);
for (i = 0; i < d_info->nr_sub_op; i++)
pr_err("0x%x ", sub_op_val(cmd, d_info->sub_op[i].hi,
d_info->sub_op[i].low));
pr_err("\n");
}
static inline u32 *cmd_ptr(struct parser_exec_state *s, int index)
{
return s->ip_va + (index << 2);
}
static inline u32 cmd_val(struct parser_exec_state *s, int index)
{
return *cmd_ptr(s, index);
}
static void parser_exec_state_dump(struct parser_exec_state *s)
{
int cnt = 0;
int i;
gvt_dbg_cmd(" vgpu%d RING%d: ring_start(%08lx) ring_end(%08lx)"
" ring_head(%08lx) ring_tail(%08lx)\n", s->vgpu->id,
s->ring_id, s->ring_start, s->ring_start + s->ring_size,
s->ring_head, s->ring_tail);
gvt_dbg_cmd(" %s %s ip_gma(%08lx) ",
s->buf_type == RING_BUFFER_INSTRUCTION ?
"RING_BUFFER" : "BATCH_BUFFER",
s->buf_addr_type == GTT_BUFFER ?
"GTT" : "PPGTT", s->ip_gma);
if (s->ip_va == NULL) {
gvt_dbg_cmd(" ip_va(NULL)");
return;
}
gvt_dbg_cmd(" ip_va=%p: %08x %08x %08x %08x\n",
s->ip_va, cmd_val(s, 0), cmd_val(s, 1),
cmd_val(s, 2), cmd_val(s, 3));
print_opcode(cmd_val(s, 0), s->ring_id);
pr_err(" ip_va=%p: %08x %08x %08x %08x\n",
s->ip_va, cmd_val(s, 0), cmd_val(s, 1),
cmd_val(s, 2), cmd_val(s, 3));
s->ip_va = (u32 *)((((u64)s->ip_va) >> 12) << 12);
while (cnt < 1024) {
pr_err("ip_va=%p: ", s->ip_va);
for (i = 0; i < 8; i++)
pr_err("%08x ", cmd_val(s, i));
pr_err("\n");
s->ip_va += 8 * sizeof(u32);
cnt += 8;
}
}
static inline void update_ip_va(struct parser_exec_state *s)
{
unsigned long len = 0;
if (WARN_ON(s->ring_head == s->ring_tail))
return;
if (s->buf_type == RING_BUFFER_INSTRUCTION) {
unsigned long ring_top = s->ring_start + s->ring_size;
if (s->ring_head > s->ring_tail) {
if (s->ip_gma >= s->ring_head && s->ip_gma < ring_top)
len = (s->ip_gma - s->ring_head);
else if (s->ip_gma >= s->ring_start &&
s->ip_gma <= s->ring_tail)
len = (ring_top - s->ring_head) +
(s->ip_gma - s->ring_start);
} else
len = (s->ip_gma - s->ring_head);
s->ip_va = s->rb_va + len;
} else {
s->ip_va = s->ret_bb_va;
}
}
static inline int ip_gma_set(struct parser_exec_state *s,
unsigned long ip_gma)
{
WARN_ON(!IS_ALIGNED(ip_gma, 4));
s->ip_gma = ip_gma;
update_ip_va(s);
return 0;
}
static inline int ip_gma_advance(struct parser_exec_state *s,
unsigned int dw_len)
{
s->ip_gma += (dw_len << 2);
if (s->buf_type == RING_BUFFER_INSTRUCTION) {
if (s->ip_gma >= s->ring_start + s->ring_size)
s->ip_gma -= s->ring_size;
update_ip_va(s);
} else {
s->ip_va += (dw_len << 2);
}
return 0;
}
static inline int get_cmd_length(struct cmd_info *info, u32 cmd)
{
if ((info->flag & F_LEN_MASK) == F_LEN_CONST)
return info->len;
else
return (cmd & ((1U << info->len) - 1)) + 2;
return 0;
}
static inline int cmd_length(struct parser_exec_state *s)
{
return get_cmd_length(s->info, cmd_val(s, 0));
}
static bool is_shadowed_mmio(unsigned int offset)
{
bool ret = false;
if ((offset == 0x2168) ||
(offset == 0x2140) ||
(offset == 0x211c) ||
(offset == 0x2114)) {
ret = true;
}
return ret;
}
static inline bool is_force_nonpriv_mmio(unsigned int offset)
{
return (offset >= 0x24d0 && offset < 0x2500);
}
static int force_nonpriv_reg_handler(struct parser_exec_state *s,
unsigned int offset, unsigned int index)
{
struct intel_gvt *gvt = s->vgpu->gvt;
unsigned int data = cmd_val(s, index + 1);
if (!intel_gvt_in_force_nonpriv_whitelist(gvt, data)) {
gvt_err("Unexpected forcenonpriv 0x%x LRI write, value=0x%x\n",
offset, data);
return -EINVAL;
}
return 0;
}
static int cmd_reg_handler(struct parser_exec_state *s,
unsigned int offset, unsigned int index, char *cmd)
{
struct intel_vgpu *vgpu = s->vgpu;
struct intel_gvt *gvt = vgpu->gvt;
if (offset + 4 > gvt->device_info.mmio_size) {
gvt_vgpu_err("%s access to (%x) outside of MMIO range\n",
cmd, offset);
return -EINVAL;
}
if (!intel_gvt_mmio_is_cmd_access(gvt, offset)) {
gvt_vgpu_err("%s access to non-render register (%x)\n",
cmd, offset);
return 0;
}
if (is_shadowed_mmio(offset)) {
gvt_vgpu_err("found access of shadowed MMIO %x\n", offset);
return 0;
}
if (is_force_nonpriv_mmio(offset) &&
force_nonpriv_reg_handler(s, offset, index))
return -EINVAL;
if (offset == i915_mmio_reg_offset(DERRMR) ||
offset == i915_mmio_reg_offset(FORCEWAKE_MT)) {
patch_value(s, cmd_ptr(s, index), VGT_PVINFO_PAGE);
}
intel_gvt_mmio_set_cmd_accessed(gvt, offset);
return 0;
}
static int cmd_handler_lri(struct parser_exec_state *s)
{
int i, ret = 0;
int cmd_len = cmd_length(s);
struct intel_gvt *gvt = s->vgpu->gvt;
for (i = 1; i < cmd_len; i += 2) {
if (IS_BROADWELL(gvt->dev_priv) &&
(s->ring_id != RCS)) {
if (s->ring_id == BCS &&
cmd_reg(s, i) ==
i915_mmio_reg_offset(DERRMR))
ret |= 0;
else
ret |= (cmd_reg_inhibit(s, i)) ? -EINVAL : 0;
}
if (ret)
break;
ret |= cmd_reg_handler(s, cmd_reg(s, i), i, "lri");
}
return ret;
}
static int cmd_handler_lrr(struct parser_exec_state *s)
{
int i, ret = 0;
int cmd_len = cmd_length(s);
for (i = 1; i < cmd_len; i += 2) {
if (IS_BROADWELL(s->vgpu->gvt->dev_priv))
ret |= ((cmd_reg_inhibit(s, i) ||
(cmd_reg_inhibit(s, i + 1)))) ?
-EINVAL : 0;
if (ret)
break;
ret |= cmd_reg_handler(s, cmd_reg(s, i), i, "lrr-src");
ret |= cmd_reg_handler(s, cmd_reg(s, i + 1), i, "lrr-dst");
}
return ret;
}
static int cmd_handler_lrm(struct parser_exec_state *s)
{
struct intel_gvt *gvt = s->vgpu->gvt;
int gmadr_bytes = gvt->device_info.gmadr_bytes_in_cmd;
unsigned long gma;
int i, ret = 0;
int cmd_len = cmd_length(s);
for (i = 1; i < cmd_len;) {
if (IS_BROADWELL(gvt->dev_priv))
ret |= (cmd_reg_inhibit(s, i)) ? -EINVAL : 0;
if (ret)
break;
ret |= cmd_reg_handler(s, cmd_reg(s, i), i, "lrm");
if (cmd_val(s, 0) & (1 << 22)) {
gma = cmd_gma(s, i + 1);
if (gmadr_bytes == 8)
gma |= (cmd_gma_hi(s, i + 2)) << 32;
ret |= cmd_address_audit(s, gma, sizeof(u32), false);
}
i += gmadr_dw_number(s) + 1;
}
return ret;
}
static int cmd_handler_srm(struct parser_exec_state *s)
{
int gmadr_bytes = s->vgpu->gvt->device_info.gmadr_bytes_in_cmd;
unsigned long gma;
int i, ret = 0;
int cmd_len = cmd_length(s);
for (i = 1; i < cmd_len;) {
ret |= cmd_reg_handler(s, cmd_reg(s, i), i, "srm");
if (cmd_val(s, 0) & (1 << 22)) {
gma = cmd_gma(s, i + 1);
if (gmadr_bytes == 8)
gma |= (cmd_gma_hi(s, i + 2)) << 32;
ret |= cmd_address_audit(s, gma, sizeof(u32), false);
}
i += gmadr_dw_number(s) + 1;
}
return ret;
}
static int cmd_handler_pipe_control(struct parser_exec_state *s)
{
int gmadr_bytes = s->vgpu->gvt->device_info.gmadr_bytes_in_cmd;
unsigned long gma;
bool index_mode = false;
unsigned int post_sync;
int ret = 0;
post_sync = (cmd_val(s, 1) & PIPE_CONTROL_POST_SYNC_OP_MASK) >> 14;
if (cmd_val(s, 1) & PIPE_CONTROL_MMIO_WRITE)
ret = cmd_reg_handler(s, cmd_reg(s, 2), 1, "pipe_ctrl");
else if (post_sync) {
if (post_sync == 2)
ret = cmd_reg_handler(s, 0x2350, 1, "pipe_ctrl");
else if (post_sync == 3)
ret = cmd_reg_handler(s, 0x2358, 1, "pipe_ctrl");
else if (post_sync == 1) {
if ((cmd_val(s, 1) & PIPE_CONTROL_GLOBAL_GTT_IVB)) {
gma = cmd_val(s, 2) & GENMASK(31, 3);
if (gmadr_bytes == 8)
gma |= (cmd_gma_hi(s, 3)) << 32;
if (cmd_val(s, 1) & (1 << 21))
index_mode = true;
ret |= cmd_address_audit(s, gma, sizeof(u64),
index_mode);
}
}
}
if (ret)
return ret;
if (cmd_val(s, 1) & PIPE_CONTROL_NOTIFY)
set_bit(cmd_interrupt_events[s->ring_id].pipe_control_notify,
s->workload->pending_events);
return 0;
}
static int cmd_handler_mi_user_interrupt(struct parser_exec_state *s)
{
set_bit(cmd_interrupt_events[s->ring_id].mi_user_interrupt,
s->workload->pending_events);
return 0;
}
static int cmd_advance_default(struct parser_exec_state *s)
{
return ip_gma_advance(s, cmd_length(s));
}
static int cmd_handler_mi_batch_buffer_end(struct parser_exec_state *s)
{
int ret;
if (s->buf_type == BATCH_BUFFER_2ND_LEVEL) {
s->buf_type = BATCH_BUFFER_INSTRUCTION;
ret = ip_gma_set(s, s->ret_ip_gma_bb);
s->buf_addr_type = s->saved_buf_addr_type;
} else {
s->buf_type = RING_BUFFER_INSTRUCTION;
s->buf_addr_type = GTT_BUFFER;
if (s->ret_ip_gma_ring >= s->ring_start + s->ring_size)
s->ret_ip_gma_ring -= s->ring_size;
ret = ip_gma_set(s, s->ret_ip_gma_ring);
}
return ret;
}
static int gen8_decode_mi_display_flip(struct parser_exec_state *s,
struct mi_display_flip_command_info *info)
{
struct drm_i915_private *dev_priv = s->vgpu->gvt->dev_priv;
struct plane_code_mapping gen8_plane_code[] = {
[0] = {PIPE_A, PLANE_A, PRIMARY_A_FLIP_DONE},
[1] = {PIPE_B, PLANE_A, PRIMARY_B_FLIP_DONE},
[2] = {PIPE_A, PLANE_B, SPRITE_A_FLIP_DONE},
[3] = {PIPE_B, PLANE_B, SPRITE_B_FLIP_DONE},
[4] = {PIPE_C, PLANE_A, PRIMARY_C_FLIP_DONE},
[5] = {PIPE_C, PLANE_B, SPRITE_C_FLIP_DONE},
};
u32 dword0, dword1, dword2;
u32 v;
dword0 = cmd_val(s, 0);
dword1 = cmd_val(s, 1);
dword2 = cmd_val(s, 2);
v = (dword0 & GENMASK(21, 19)) >> 19;
if (WARN_ON(v >= ARRAY_SIZE(gen8_plane_code)))
return -EINVAL;
info->pipe = gen8_plane_code[v].pipe;
info->plane = gen8_plane_code[v].plane;
info->event = gen8_plane_code[v].event;
info->stride_val = (dword1 & GENMASK(15, 6)) >> 6;
info->tile_val = (dword1 & 0x1);
info->surf_val = (dword2 & GENMASK(31, 12)) >> 12;
info->async_flip = ((dword2 & GENMASK(1, 0)) == 0x1);
if (info->plane == PLANE_A) {
info->ctrl_reg = DSPCNTR(info->pipe);
info->stride_reg = DSPSTRIDE(info->pipe);
info->surf_reg = DSPSURF(info->pipe);
} else if (info->plane == PLANE_B) {
info->ctrl_reg = SPRCTL(info->pipe);
info->stride_reg = SPRSTRIDE(info->pipe);
info->surf_reg = SPRSURF(info->pipe);
} else {
WARN_ON(1);
return -EINVAL;
}
return 0;
}
static int skl_decode_mi_display_flip(struct parser_exec_state *s,
struct mi_display_flip_command_info *info)
{
struct drm_i915_private *dev_priv = s->vgpu->gvt->dev_priv;
struct intel_vgpu *vgpu = s->vgpu;
u32 dword0 = cmd_val(s, 0);
u32 dword1 = cmd_val(s, 1);
u32 dword2 = cmd_val(s, 2);
u32 plane = (dword0 & GENMASK(12, 8)) >> 8;
info->plane = PRIMARY_PLANE;
switch (plane) {
case MI_DISPLAY_FLIP_SKL_PLANE_1_A:
info->pipe = PIPE_A;
info->event = PRIMARY_A_FLIP_DONE;
break;
case MI_DISPLAY_FLIP_SKL_PLANE_1_B:
info->pipe = PIPE_B;
info->event = PRIMARY_B_FLIP_DONE;
break;
case MI_DISPLAY_FLIP_SKL_PLANE_1_C:
info->pipe = PIPE_C;
info->event = PRIMARY_C_FLIP_DONE;
break;
case MI_DISPLAY_FLIP_SKL_PLANE_2_A:
info->pipe = PIPE_A;
info->event = SPRITE_A_FLIP_DONE;
info->plane = SPRITE_PLANE;
break;
case MI_DISPLAY_FLIP_SKL_PLANE_2_B:
info->pipe = PIPE_B;
info->event = SPRITE_B_FLIP_DONE;
info->plane = SPRITE_PLANE;
break;
case MI_DISPLAY_FLIP_SKL_PLANE_2_C:
info->pipe = PIPE_C;
info->event = SPRITE_C_FLIP_DONE;
info->plane = SPRITE_PLANE;
break;
default:
gvt_vgpu_err("unknown plane code %d\n", plane);
return -EINVAL;
}
info->stride_val = (dword1 & GENMASK(15, 6)) >> 6;
info->tile_val = (dword1 & GENMASK(2, 0));
info->surf_val = (dword2 & GENMASK(31, 12)) >> 12;
info->async_flip = ((dword2 & GENMASK(1, 0)) == 0x1);
info->ctrl_reg = DSPCNTR(info->pipe);
info->stride_reg = DSPSTRIDE(info->pipe);
info->surf_reg = DSPSURF(info->pipe);
return 0;
}
static int gen8_check_mi_display_flip(struct parser_exec_state *s,
struct mi_display_flip_command_info *info)
{
struct drm_i915_private *dev_priv = s->vgpu->gvt->dev_priv;
u32 stride, tile;
if (!info->async_flip)
return 0;
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
stride = vgpu_vreg(s->vgpu, info->stride_reg) & GENMASK(9, 0);
tile = (vgpu_vreg(s->vgpu, info->ctrl_reg) &
GENMASK(12, 10)) >> 10;
} else {
stride = (vgpu_vreg(s->vgpu, info->stride_reg) &
GENMASK(15, 6)) >> 6;
tile = (vgpu_vreg(s->vgpu, info->ctrl_reg) & (1 << 10)) >> 10;
}
if (stride != info->stride_val)
gvt_dbg_cmd("cannot change stride during async flip\n");
if (tile != info->tile_val)
gvt_dbg_cmd("cannot change tile during async flip\n");
return 0;
}
static int gen8_update_plane_mmio_from_mi_display_flip(
struct parser_exec_state *s,
struct mi_display_flip_command_info *info)
{
struct drm_i915_private *dev_priv = s->vgpu->gvt->dev_priv;
struct intel_vgpu *vgpu = s->vgpu;
set_mask_bits(&vgpu_vreg(vgpu, info->surf_reg), GENMASK(31, 12),
info->surf_val << 12);
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) {
set_mask_bits(&vgpu_vreg(vgpu, info->stride_reg), GENMASK(9, 0),
info->stride_val);
set_mask_bits(&vgpu_vreg(vgpu, info->ctrl_reg), GENMASK(12, 10),
info->tile_val << 10);
} else {
set_mask_bits(&vgpu_vreg(vgpu, info->stride_reg), GENMASK(15, 6),
info->stride_val << 6);
set_mask_bits(&vgpu_vreg(vgpu, info->ctrl_reg), GENMASK(10, 10),
info->tile_val << 10);
}
vgpu_vreg(vgpu, PIPE_FRMCOUNT_G4X(info->pipe))++;
intel_vgpu_trigger_virtual_event(vgpu, info->event);
return 0;
}
static int decode_mi_display_flip(struct parser_exec_state *s,
struct mi_display_flip_command_info *info)
{
struct drm_i915_private *dev_priv = s->vgpu->gvt->dev_priv;
if (IS_BROADWELL(dev_priv))
return gen8_decode_mi_display_flip(s, info);
if (IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv))
return skl_decode_mi_display_flip(s, info);
return -ENODEV;
}
static int check_mi_display_flip(struct parser_exec_state *s,
struct mi_display_flip_command_info *info)
{
struct drm_i915_private *dev_priv = s->vgpu->gvt->dev_priv;
if (IS_BROADWELL(dev_priv)
|| IS_SKYLAKE(dev_priv)
|| IS_KABYLAKE(dev_priv))
return gen8_check_mi_display_flip(s, info);
return -ENODEV;
}
static int update_plane_mmio_from_mi_display_flip(
struct parser_exec_state *s,
struct mi_display_flip_command_info *info)
{
struct drm_i915_private *dev_priv = s->vgpu->gvt->dev_priv;
if (IS_BROADWELL(dev_priv)
|| IS_SKYLAKE(dev_priv)
|| IS_KABYLAKE(dev_priv))
return gen8_update_plane_mmio_from_mi_display_flip(s, info);
return -ENODEV;
}
static int cmd_handler_mi_display_flip(struct parser_exec_state *s)
{
struct mi_display_flip_command_info info;
struct intel_vgpu *vgpu = s->vgpu;
int ret;
int i;
int len = cmd_length(s);
ret = decode_mi_display_flip(s, &info);
if (ret) {
gvt_vgpu_err("fail to decode MI display flip command\n");
return ret;
}
ret = check_mi_display_flip(s, &info);
if (ret) {
gvt_vgpu_err("invalid MI display flip command\n");
return ret;
}
ret = update_plane_mmio_from_mi_display_flip(s, &info);
if (ret) {
gvt_vgpu_err("fail to update plane mmio\n");
return ret;
}
for (i = 0; i < len; i++)
patch_value(s, cmd_ptr(s, i), MI_NOOP);
return 0;
}
static bool is_wait_for_flip_pending(u32 cmd)
{
return cmd & (MI_WAIT_FOR_PLANE_A_FLIP_PENDING |
MI_WAIT_FOR_PLANE_B_FLIP_PENDING |
MI_WAIT_FOR_PLANE_C_FLIP_PENDING |
MI_WAIT_FOR_SPRITE_A_FLIP_PENDING |
MI_WAIT_FOR_SPRITE_B_FLIP_PENDING |
MI_WAIT_FOR_SPRITE_C_FLIP_PENDING);
}
static int cmd_handler_mi_wait_for_event(struct parser_exec_state *s)
{
u32 cmd = cmd_val(s, 0);
if (!is_wait_for_flip_pending(cmd))
return 0;
patch_value(s, cmd_ptr(s, 0), MI_NOOP);
return 0;
}
static unsigned long get_gma_bb_from_cmd(struct parser_exec_state *s, int index)
{
unsigned long addr;
unsigned long gma_high, gma_low;
int gmadr_bytes = s->vgpu->gvt->device_info.gmadr_bytes_in_cmd;
if (WARN_ON(gmadr_bytes != 4 && gmadr_bytes != 8))
return INTEL_GVT_INVALID_ADDR;
gma_low = cmd_val(s, index) & BATCH_BUFFER_ADDR_MASK;
if (gmadr_bytes == 4) {
addr = gma_low;
} else {
gma_high = cmd_val(s, index + 1) & BATCH_BUFFER_ADDR_HIGH_MASK;
addr = (((unsigned long)gma_high) << 32) | gma_low;
}
return addr;
}
static inline int cmd_address_audit(struct parser_exec_state *s,
unsigned long guest_gma, int op_size, bool index_mode)
{
struct intel_vgpu *vgpu = s->vgpu;
u32 max_surface_size = vgpu->gvt->device_info.max_surface_size;
int i;
int ret;
if (op_size > max_surface_size) {
gvt_vgpu_err("command address audit fail name %s\n",
s->info->name);
return -EINVAL;
}
if (index_mode) {
if (guest_gma >= GTT_PAGE_SIZE / sizeof(u64)) {
ret = -EINVAL;
goto err;
}
} else if ((!vgpu_gmadr_is_valid(s->vgpu, guest_gma)) ||
(!vgpu_gmadr_is_valid(s->vgpu,
guest_gma + op_size - 1))) {
ret = -EINVAL;
goto err;
}
return 0;
err:
gvt_vgpu_err("cmd_parser: Malicious %s detected, addr=0x%lx, len=%d!\n",
s->info->name, guest_gma, op_size);
pr_err("cmd dump: ");
for (i = 0; i < cmd_length(s); i++) {
if (!(i % 4))
pr_err("\n%08x ", cmd_val(s, i));
else
pr_err("%08x ", cmd_val(s, i));
}
pr_err("\nvgpu%d: aperture 0x%llx - 0x%llx, hidden 0x%llx - 0x%llx\n",
vgpu->id,
vgpu_aperture_gmadr_base(vgpu),
vgpu_aperture_gmadr_end(vgpu),
vgpu_hidden_gmadr_base(vgpu),
vgpu_hidden_gmadr_end(vgpu));
return ret;
}
static int cmd_handler_mi_store_data_imm(struct parser_exec_state *s)
{
int gmadr_bytes = s->vgpu->gvt->device_info.gmadr_bytes_in_cmd;
int op_size = (cmd_length(s) - 3) * sizeof(u32);
int core_id = (cmd_val(s, 2) & (1 << 0)) ? 1 : 0;
unsigned long gma, gma_low, gma_high;
int ret = 0;
if (!(cmd_val(s, 0) & (1 << 22)))
return 0;
gma = cmd_val(s, 2) & GENMASK(31, 2);
if (gmadr_bytes == 8) {
gma_low = cmd_val(s, 1) & GENMASK(31, 2);
gma_high = cmd_val(s, 2) & GENMASK(15, 0);
gma = (gma_high << 32) | gma_low;
core_id = (cmd_val(s, 1) & (1 << 0)) ? 1 : 0;
}
ret = cmd_address_audit(s, gma + op_size * core_id, op_size, false);
return ret;
}
static inline int unexpected_cmd(struct parser_exec_state *s)
{
struct intel_vgpu *vgpu = s->vgpu;
gvt_vgpu_err("Unexpected %s in command buffer!\n", s->info->name);
return -EINVAL;
}
static int cmd_handler_mi_semaphore_wait(struct parser_exec_state *s)
{
return unexpected_cmd(s);
}
static int cmd_handler_mi_report_perf_count(struct parser_exec_state *s)
{
return unexpected_cmd(s);
}
static int cmd_handler_mi_op_2e(struct parser_exec_state *s)
{
return unexpected_cmd(s);
}
static int cmd_handler_mi_op_2f(struct parser_exec_state *s)
{
int gmadr_bytes = s->vgpu->gvt->device_info.gmadr_bytes_in_cmd;
int op_size = (1 << ((cmd_val(s, 0) & GENMASK(20, 19)) >> 19)) *
sizeof(u32);
unsigned long gma, gma_high;
int ret = 0;
if (!(cmd_val(s, 0) & (1 << 22)))
return ret;
gma = cmd_val(s, 1) & GENMASK(31, 2);
if (gmadr_bytes == 8) {
gma_high = cmd_val(s, 2) & GENMASK(15, 0);
gma = (gma_high << 32) | gma;
}
ret = cmd_address_audit(s, gma, op_size, false);
return ret;
}
static int cmd_handler_mi_store_data_index(struct parser_exec_state *s)
{
return unexpected_cmd(s);
}
static int cmd_handler_mi_clflush(struct parser_exec_state *s)
{
return unexpected_cmd(s);
}
static int cmd_handler_mi_conditional_batch_buffer_end(
struct parser_exec_state *s)
{
return unexpected_cmd(s);
}
static int cmd_handler_mi_update_gtt(struct parser_exec_state *s)
{
return unexpected_cmd(s);
}
static int cmd_handler_mi_flush_dw(struct parser_exec_state *s)
{
int gmadr_bytes = s->vgpu->gvt->device_info.gmadr_bytes_in_cmd;
unsigned long gma;
bool index_mode = false;
int ret = 0;
if (((cmd_val(s, 0) >> 14) & 0x3) && (cmd_val(s, 1) & (1 << 2))) {
gma = cmd_val(s, 1) & GENMASK(31, 3);
if (gmadr_bytes == 8)
gma |= (cmd_val(s, 2) & GENMASK(15, 0)) << 32;
if (cmd_val(s, 0) & (1 << 21))
index_mode = true;
ret = cmd_address_audit(s, gma, sizeof(u64), index_mode);
}
if ((cmd_val(s, 0) & (1 << 8)))
set_bit(cmd_interrupt_events[s->ring_id].mi_flush_dw,
s->workload->pending_events);
return ret;
}
static void addr_type_update_snb(struct parser_exec_state *s)
{
if ((s->buf_type == RING_BUFFER_INSTRUCTION) &&
(BATCH_BUFFER_ADR_SPACE_BIT(cmd_val(s, 0)) == 1)) {
s->buf_addr_type = PPGTT_BUFFER;
}
}
static int copy_gma_to_hva(struct intel_vgpu *vgpu, struct intel_vgpu_mm *mm,
unsigned long gma, unsigned long end_gma, void *va)
{
unsigned long copy_len, offset;
unsigned long len = 0;
unsigned long gpa;
while (gma != end_gma) {
gpa = intel_vgpu_gma_to_gpa(mm, gma);
if (gpa == INTEL_GVT_INVALID_ADDR) {
gvt_vgpu_err("invalid gma address: %lx\n", gma);
return -EFAULT;
}
offset = gma & (GTT_PAGE_SIZE - 1);
copy_len = (end_gma - gma) >= (GTT_PAGE_SIZE - offset) ?
GTT_PAGE_SIZE - offset : end_gma - gma;
intel_gvt_hypervisor_read_gpa(vgpu, gpa, va + len, copy_len);
len += copy_len;
gma += copy_len;
}
return len;
}
static int batch_buffer_needs_scan(struct parser_exec_state *s)
{
struct intel_gvt *gvt = s->vgpu->gvt;
if (IS_BROADWELL(gvt->dev_priv) || IS_SKYLAKE(gvt->dev_priv)
|| IS_KABYLAKE(gvt->dev_priv)) {
if (cmd_val(s, 0) & (1 << 8))
return 0;
}
return 1;
}
static uint32_t find_bb_size(struct parser_exec_state *s)
{
unsigned long gma = 0;
struct cmd_info *info;
uint32_t bb_size = 0;
uint32_t cmd_len = 0;
bool met_bb_end = false;
struct intel_vgpu *vgpu = s->vgpu;
u32 cmd;
gma = get_gma_bb_from_cmd(s, 1);
cmd = cmd_val(s, 0);
info = get_cmd_info(s->vgpu->gvt, cmd, s->ring_id);
if (info == NULL) {
gvt_vgpu_err("unknown cmd 0x%x, opcode=0x%x\n",
cmd, get_opcode(cmd, s->ring_id));
return -EINVAL;
}
do {
copy_gma_to_hva(s->vgpu, s->vgpu->gtt.ggtt_mm,
gma, gma + 4, &cmd);
info = get_cmd_info(s->vgpu->gvt, cmd, s->ring_id);
if (info == NULL) {
gvt_vgpu_err("unknown cmd 0x%x, opcode=0x%x\n",
cmd, get_opcode(cmd, s->ring_id));
return -EINVAL;
}
if (info->opcode == OP_MI_BATCH_BUFFER_END) {
met_bb_end = true;
} else if (info->opcode == OP_MI_BATCH_BUFFER_START) {
if (BATCH_BUFFER_2ND_LEVEL_BIT(cmd) == 0) {
met_bb_end = true;
}
}
cmd_len = get_cmd_length(info, cmd) << 2;
bb_size += cmd_len;
gma += cmd_len;
} while (!met_bb_end);
return bb_size;
}
static int perform_bb_shadow(struct parser_exec_state *s)
{
struct intel_shadow_bb_entry *entry_obj;
struct intel_vgpu *vgpu = s->vgpu;
unsigned long gma = 0;
uint32_t bb_size;
void *dst = NULL;
int ret = 0;
gma = get_gma_bb_from_cmd(s, 1);
bb_size = find_bb_size(s);
entry_obj = kmalloc(sizeof(*entry_obj), GFP_KERNEL);
if (entry_obj == NULL)
return -ENOMEM;
entry_obj->obj =
i915_gem_object_create(s->vgpu->gvt->dev_priv,
roundup(bb_size, PAGE_SIZE));
if (IS_ERR(entry_obj->obj)) {
ret = PTR_ERR(entry_obj->obj);
goto free_entry;
}
entry_obj->len = bb_size;
INIT_LIST_HEAD(&entry_obj->list);
dst = i915_gem_object_pin_map(entry_obj->obj, I915_MAP_WB);
if (IS_ERR(dst)) {
ret = PTR_ERR(dst);
goto put_obj;
}
ret = i915_gem_object_set_to_cpu_domain(entry_obj->obj, false);
if (ret) {
gvt_vgpu_err("failed to set shadow batch to CPU\n");
goto unmap_src;
}
entry_obj->va = dst;
entry_obj->bb_start_cmd_va = s->ip_va;
ret = copy_gma_to_hva(s->vgpu, s->vgpu->gtt.ggtt_mm,
gma, gma + bb_size,
dst);
if (ret < 0) {
gvt_vgpu_err("fail to copy guest ring buffer\n");
goto unmap_src;
}
list_add(&entry_obj->list, &s->workload->shadow_bb);
s->ip_va = dst;
s->ip_gma = gma;
return 0;
unmap_src:
i915_gem_object_unpin_map(entry_obj->obj);
put_obj:
i915_gem_object_put(entry_obj->obj);
free_entry:
kfree(entry_obj);
return ret;
}
static int cmd_handler_mi_batch_buffer_start(struct parser_exec_state *s)
{
bool second_level;
int ret = 0;
struct intel_vgpu *vgpu = s->vgpu;
if (s->buf_type == BATCH_BUFFER_2ND_LEVEL) {
gvt_vgpu_err("Found MI_BATCH_BUFFER_START in 2nd level BB\n");
return -EINVAL;
}
second_level = BATCH_BUFFER_2ND_LEVEL_BIT(cmd_val(s, 0)) == 1;
if (second_level && (s->buf_type != BATCH_BUFFER_INSTRUCTION)) {
gvt_vgpu_err("Jumping to 2nd level BB from RB is not allowed\n");
return -EINVAL;
}
s->saved_buf_addr_type = s->buf_addr_type;
addr_type_update_snb(s);
if (s->buf_type == RING_BUFFER_INSTRUCTION) {
s->ret_ip_gma_ring = s->ip_gma + cmd_length(s) * sizeof(u32);
s->buf_type = BATCH_BUFFER_INSTRUCTION;
} else if (second_level) {
s->buf_type = BATCH_BUFFER_2ND_LEVEL;
s->ret_ip_gma_bb = s->ip_gma + cmd_length(s) * sizeof(u32);
s->ret_bb_va = s->ip_va + cmd_length(s) * sizeof(u32);
}
if (batch_buffer_needs_scan(s)) {
ret = perform_bb_shadow(s);
if (ret < 0)
gvt_vgpu_err("invalid shadow batch buffer\n");
} else {
ret = cmd_handler_mi_batch_buffer_end(s);
if (ret < 0)
return ret;
}
return ret;
}
static void add_cmd_entry(struct intel_gvt *gvt, struct cmd_entry *e)
{
hash_add(gvt->cmd_table, &e->hlist, e->info->opcode);
}
static void trace_cs_command(struct parser_exec_state *s,
cycles_t cost_pre_cmd_handler, cycles_t cost_cmd_handler)
{
u32 cmd_trace_buf[GVT_MAX_CMD_LENGTH];
int i;
u32 cmd_len = cmd_length(s);
if (unlikely(cmd_len > GVT_MAX_CMD_LENGTH)) {
gvt_dbg_cmd("cmd length exceed tracing limitation!\n");
cmd_len = GVT_MAX_CMD_LENGTH;
}
for (i = 0; i < cmd_len; i++)
cmd_trace_buf[i] = cmd_val(s, i);
trace_gvt_command(s->vgpu->id, s->ring_id, s->ip_gma, cmd_trace_buf,
cmd_len, s->buf_type == RING_BUFFER_INSTRUCTION,
cost_pre_cmd_handler, cost_cmd_handler);
}
static int cmd_parser_exec(struct parser_exec_state *s)
{
struct cmd_info *info;
u32 cmd;
int ret = 0;
cycles_t t0, t1, t2;
struct parser_exec_state s_before_advance_custom;
struct intel_vgpu *vgpu = s->vgpu;
t0 = get_cycles();
cmd = cmd_val(s, 0);
info = get_cmd_info(s->vgpu->gvt, cmd, s->ring_id);
if (info == NULL) {
gvt_vgpu_err("unknown cmd 0x%x, opcode=0x%x\n",
cmd, get_opcode(cmd, s->ring_id));
return -EINVAL;
}
gvt_dbg_cmd("%s\n", info->name);
s->info = info;
t1 = get_cycles();
s_before_advance_custom = *s;
if (info->handler) {
ret = info->handler(s);
if (ret < 0) {
gvt_vgpu_err("%s handler error\n", info->name);
return ret;
}
}
t2 = get_cycles();
trace_cs_command(&s_before_advance_custom, t1 - t0, t2 - t1);
if (!(info->flag & F_IP_ADVANCE_CUSTOM)) {
ret = cmd_advance_default(s);
if (ret) {
gvt_vgpu_err("%s IP advance error\n", info->name);
return ret;
}
}
return 0;
}
static inline bool gma_out_of_range(unsigned long gma,
unsigned long gma_head, unsigned int gma_tail)
{
if (gma_tail >= gma_head)
return (gma < gma_head) || (gma > gma_tail);
else
return (gma > gma_tail) && (gma < gma_head);
}
static int command_scan(struct parser_exec_state *s,
unsigned long rb_head, unsigned long rb_tail,
unsigned long rb_start, unsigned long rb_len)
{
unsigned long gma_head, gma_tail, gma_bottom;
int ret = 0;
struct intel_vgpu *vgpu = s->vgpu;
gma_head = rb_start + rb_head;
gma_tail = rb_start + rb_tail;
gma_bottom = rb_start + rb_len;
gvt_dbg_cmd("scan_start: start=%lx end=%lx\n", gma_head, gma_tail);
while (s->ip_gma != gma_tail) {
if (s->buf_type == RING_BUFFER_INSTRUCTION) {
if (!(s->ip_gma >= rb_start) ||
!(s->ip_gma < gma_bottom)) {
gvt_vgpu_err("ip_gma %lx out of ring scope."
"(base:0x%lx, bottom: 0x%lx)\n",
s->ip_gma, rb_start,
gma_bottom);
parser_exec_state_dump(s);
return -EINVAL;
}
if (gma_out_of_range(s->ip_gma, gma_head, gma_tail)) {
gvt_vgpu_err("ip_gma %lx out of range."
"base 0x%lx head 0x%lx tail 0x%lx\n",
s->ip_gma, rb_start,
rb_head, rb_tail);
parser_exec_state_dump(s);
break;
}
}
ret = cmd_parser_exec(s);
if (ret) {
gvt_vgpu_err("cmd parser error\n");
parser_exec_state_dump(s);
break;
}
}
gvt_dbg_cmd("scan_end\n");
return ret;
}
static int scan_workload(struct intel_vgpu_workload *workload)
{
unsigned long gma_head, gma_tail, gma_bottom;
struct parser_exec_state s;
int ret = 0;
if (WARN_ON(!IS_ALIGNED(workload->rb_start, GTT_PAGE_SIZE)))
return -EINVAL;
gma_head = workload->rb_start + workload->rb_head;
gma_tail = workload->rb_start + workload->rb_tail;
gma_bottom = workload->rb_start + _RING_CTL_BUF_SIZE(workload->rb_ctl);
s.buf_type = RING_BUFFER_INSTRUCTION;
s.buf_addr_type = GTT_BUFFER;
s.vgpu = workload->vgpu;
s.ring_id = workload->ring_id;
s.ring_start = workload->rb_start;
s.ring_size = _RING_CTL_BUF_SIZE(workload->rb_ctl);
s.ring_head = gma_head;
s.ring_tail = gma_tail;
s.rb_va = workload->shadow_ring_buffer_va;
s.workload = workload;
if ((bypass_scan_mask & (1 << workload->ring_id)) ||
gma_head == gma_tail)
return 0;
ret = ip_gma_set(&s, gma_head);
if (ret)
goto out;
ret = command_scan(&s, workload->rb_head, workload->rb_tail,
workload->rb_start, _RING_CTL_BUF_SIZE(workload->rb_ctl));
out:
return ret;
}
static int scan_wa_ctx(struct intel_shadow_wa_ctx *wa_ctx)
{
unsigned long gma_head, gma_tail, gma_bottom, ring_size, ring_tail;
struct parser_exec_state s;
int ret = 0;
struct intel_vgpu_workload *workload = container_of(wa_ctx,
struct intel_vgpu_workload,
wa_ctx);
if (WARN_ON(!IS_ALIGNED(wa_ctx->indirect_ctx.guest_gma, GTT_PAGE_SIZE)))
return -EINVAL;
ring_tail = wa_ctx->indirect_ctx.size + 3 * sizeof(uint32_t);
ring_size = round_up(wa_ctx->indirect_ctx.size + CACHELINE_BYTES,
PAGE_SIZE);
gma_head = wa_ctx->indirect_ctx.guest_gma;
gma_tail = wa_ctx->indirect_ctx.guest_gma + ring_tail;
gma_bottom = wa_ctx->indirect_ctx.guest_gma + ring_size;
s.buf_type = RING_BUFFER_INSTRUCTION;
s.buf_addr_type = GTT_BUFFER;
s.vgpu = workload->vgpu;
s.ring_id = workload->ring_id;
s.ring_start = wa_ctx->indirect_ctx.guest_gma;
s.ring_size = ring_size;
s.ring_head = gma_head;
s.ring_tail = gma_tail;
s.rb_va = wa_ctx->indirect_ctx.shadow_va;
s.workload = workload;
ret = ip_gma_set(&s, gma_head);
if (ret)
goto out;
ret = command_scan(&s, 0, ring_tail,
wa_ctx->indirect_ctx.guest_gma, ring_size);
out:
return ret;
}
static int shadow_workload_ring_buffer(struct intel_vgpu_workload *workload)
{
struct intel_vgpu *vgpu = workload->vgpu;
unsigned long gma_head, gma_tail, gma_top, guest_rb_size;
u32 *cs;
int ret;
guest_rb_size = _RING_CTL_BUF_SIZE(workload->rb_ctl);
workload->rb_len = (workload->rb_tail + guest_rb_size -
workload->rb_head) % guest_rb_size;
gma_head = workload->rb_start + workload->rb_head;
gma_tail = workload->rb_start + workload->rb_tail;
gma_top = workload->rb_start + guest_rb_size;
cs = intel_ring_begin(workload->req, workload->rb_len / sizeof(u32));
if (IS_ERR(cs))
return PTR_ERR(cs);
workload->shadow_ring_buffer_va = cs;
if (gma_head > gma_tail) {
ret = copy_gma_to_hva(vgpu, vgpu->gtt.ggtt_mm,
gma_head, gma_top, cs);
if (ret < 0) {
gvt_vgpu_err("fail to copy guest ring buffer\n");
return ret;
}
cs += ret / sizeof(u32);
gma_head = workload->rb_start;
}
ret = copy_gma_to_hva(vgpu, vgpu->gtt.ggtt_mm, gma_head, gma_tail, cs);
if (ret < 0) {
gvt_vgpu_err("fail to copy guest ring buffer\n");
return ret;
}
cs += ret / sizeof(u32);
intel_ring_advance(workload->req, cs);
return 0;
}
int intel_gvt_scan_and_shadow_workload(struct intel_vgpu_workload *workload)
{
int ret;
struct intel_vgpu *vgpu = workload->vgpu;
ret = shadow_workload_ring_buffer(workload);
if (ret) {
gvt_vgpu_err("fail to shadow workload ring_buffer\n");
return ret;
}
ret = scan_workload(workload);
if (ret) {
gvt_vgpu_err("scan workload error\n");
return ret;
}
return 0;
}
static int shadow_indirect_ctx(struct intel_shadow_wa_ctx *wa_ctx)
{
int ctx_size = wa_ctx->indirect_ctx.size;
unsigned long guest_gma = wa_ctx->indirect_ctx.guest_gma;
struct intel_vgpu_workload *workload = container_of(wa_ctx,
struct intel_vgpu_workload,
wa_ctx);
struct intel_vgpu *vgpu = workload->vgpu;
struct drm_i915_gem_object *obj;
int ret = 0;
void *map;
obj = i915_gem_object_create(workload->vgpu->gvt->dev_priv,
roundup(ctx_size + CACHELINE_BYTES,
PAGE_SIZE));
if (IS_ERR(obj))
return PTR_ERR(obj);
map = i915_gem_object_pin_map(obj, I915_MAP_WB);
if (IS_ERR(map)) {
gvt_vgpu_err("failed to vmap shadow indirect ctx\n");
ret = PTR_ERR(map);
goto put_obj;
}
ret = i915_gem_object_set_to_cpu_domain(obj, false);
if (ret) {
gvt_vgpu_err("failed to set shadow indirect ctx to CPU\n");
goto unmap_src;
}
ret = copy_gma_to_hva(workload->vgpu,
workload->vgpu->gtt.ggtt_mm,
guest_gma, guest_gma + ctx_size,
map);
if (ret < 0) {
gvt_vgpu_err("fail to copy guest indirect ctx\n");
goto unmap_src;
}
wa_ctx->indirect_ctx.obj = obj;
wa_ctx->indirect_ctx.shadow_va = map;
return 0;
unmap_src:
i915_gem_object_unpin_map(obj);
put_obj:
i915_gem_object_put(wa_ctx->indirect_ctx.obj);
return ret;
}
static int combine_wa_ctx(struct intel_shadow_wa_ctx *wa_ctx)
{
uint32_t per_ctx_start[CACHELINE_DWORDS] = {0};
unsigned char *bb_start_sva;
per_ctx_start[0] = 0x18800001;
per_ctx_start[1] = wa_ctx->per_ctx.guest_gma;
bb_start_sva = (unsigned char *)wa_ctx->indirect_ctx.shadow_va +
wa_ctx->indirect_ctx.size;
memcpy(bb_start_sva, per_ctx_start, CACHELINE_BYTES);
return 0;
}
int intel_gvt_scan_and_shadow_wa_ctx(struct intel_shadow_wa_ctx *wa_ctx)
{
int ret;
struct intel_vgpu_workload *workload = container_of(wa_ctx,
struct intel_vgpu_workload,
wa_ctx);
struct intel_vgpu *vgpu = workload->vgpu;
if (wa_ctx->indirect_ctx.size == 0)
return 0;
ret = shadow_indirect_ctx(wa_ctx);
if (ret) {
gvt_vgpu_err("fail to shadow indirect ctx\n");
return ret;
}
combine_wa_ctx(wa_ctx);
ret = scan_wa_ctx(wa_ctx);
if (ret) {
gvt_vgpu_err("scan wa ctx error\n");
return ret;
}
return 0;
}
static struct cmd_info *find_cmd_entry_any_ring(struct intel_gvt *gvt,
unsigned int opcode, int rings)
{
struct cmd_info *info = NULL;
unsigned int ring;
for_each_set_bit(ring, (unsigned long *)&rings, I915_NUM_ENGINES) {
info = find_cmd_entry(gvt, opcode, ring);
if (info)
break;
}
return info;
}
static int init_cmd_table(struct intel_gvt *gvt)
{
int i;
struct cmd_entry *e;
struct cmd_info *info;
unsigned int gen_type;
gen_type = intel_gvt_get_device_type(gvt);
for (i = 0; i < ARRAY_SIZE(cmd_info); i++) {
if (!(cmd_info[i].devices & gen_type))
continue;
e = kzalloc(sizeof(*e), GFP_KERNEL);
if (!e)
return -ENOMEM;
e->info = &cmd_info[i];
info = find_cmd_entry_any_ring(gvt,
e->info->opcode, e->info->rings);
if (info) {
gvt_err("%s %s duplicated\n", e->info->name,
info->name);
return -EEXIST;
}
INIT_HLIST_NODE(&e->hlist);
add_cmd_entry(gvt, e);
gvt_dbg_cmd("add %-30s op %04x flag %x devs %02x rings %02x\n",
e->info->name, e->info->opcode, e->info->flag,
e->info->devices, e->info->rings);
}
return 0;
}
static void clean_cmd_table(struct intel_gvt *gvt)
{
struct hlist_node *tmp;
struct cmd_entry *e;
int i;
hash_for_each_safe(gvt->cmd_table, i, tmp, e, hlist)
kfree(e);
hash_init(gvt->cmd_table);
}
void intel_gvt_clean_cmd_parser(struct intel_gvt *gvt)
{
clean_cmd_table(gvt);
}
int intel_gvt_init_cmd_parser(struct intel_gvt *gvt)
{
int ret;
ret = init_cmd_table(gvt);
if (ret) {
intel_gvt_clean_cmd_parser(gvt);
return ret;
}
return 0;
}
