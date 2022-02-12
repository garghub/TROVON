static void print_verifier_state(struct verifier_state *state)
{
struct reg_state *reg;
enum bpf_reg_type t;
int i;
for (i = 0; i < MAX_BPF_REG; i++) {
reg = &state->regs[i];
t = reg->type;
if (t == NOT_INIT)
continue;
verbose(" R%d=%s", i, reg_type_str[t]);
if (t == CONST_IMM || t == PTR_TO_STACK)
verbose("%lld", reg->imm);
else if (t == PTR_TO_PACKET)
verbose("(id=%d,off=%d,r=%d)",
reg->id, reg->off, reg->range);
else if (t == UNKNOWN_VALUE && reg->imm)
verbose("%lld", reg->imm);
else if (t == CONST_PTR_TO_MAP || t == PTR_TO_MAP_VALUE ||
t == PTR_TO_MAP_VALUE_OR_NULL)
verbose("(ks=%d,vs=%d)",
reg->map_ptr->key_size,
reg->map_ptr->value_size);
}
for (i = 0; i < MAX_BPF_STACK; i += BPF_REG_SIZE) {
if (state->stack_slot_type[i] == STACK_SPILL)
verbose(" fp%d=%s", -MAX_BPF_STACK + i,
reg_type_str[state->spilled_regs[i / BPF_REG_SIZE].type]);
}
verbose("\n");
}
static void print_bpf_insn(struct bpf_insn *insn)
{
u8 class = BPF_CLASS(insn->code);
if (class == BPF_ALU || class == BPF_ALU64) {
if (BPF_SRC(insn->code) == BPF_X)
verbose("(%02x) %sr%d %s %sr%d\n",
insn->code, class == BPF_ALU ? "(u32) " : "",
insn->dst_reg,
bpf_alu_string[BPF_OP(insn->code) >> 4],
class == BPF_ALU ? "(u32) " : "",
insn->src_reg);
else
verbose("(%02x) %sr%d %s %s%d\n",
insn->code, class == BPF_ALU ? "(u32) " : "",
insn->dst_reg,
bpf_alu_string[BPF_OP(insn->code) >> 4],
class == BPF_ALU ? "(u32) " : "",
insn->imm);
} else if (class == BPF_STX) {
if (BPF_MODE(insn->code) == BPF_MEM)
verbose("(%02x) *(%s *)(r%d %+d) = r%d\n",
insn->code,
bpf_ldst_string[BPF_SIZE(insn->code) >> 3],
insn->dst_reg,
insn->off, insn->src_reg);
else if (BPF_MODE(insn->code) == BPF_XADD)
verbose("(%02x) lock *(%s *)(r%d %+d) += r%d\n",
insn->code,
bpf_ldst_string[BPF_SIZE(insn->code) >> 3],
insn->dst_reg, insn->off,
insn->src_reg);
else
verbose("BUG_%02x\n", insn->code);
} else if (class == BPF_ST) {
if (BPF_MODE(insn->code) != BPF_MEM) {
verbose("BUG_st_%02x\n", insn->code);
return;
}
verbose("(%02x) *(%s *)(r%d %+d) = %d\n",
insn->code,
bpf_ldst_string[BPF_SIZE(insn->code) >> 3],
insn->dst_reg,
insn->off, insn->imm);
} else if (class == BPF_LDX) {
if (BPF_MODE(insn->code) != BPF_MEM) {
verbose("BUG_ldx_%02x\n", insn->code);
return;
}
verbose("(%02x) r%d = *(%s *)(r%d %+d)\n",
insn->code, insn->dst_reg,
bpf_ldst_string[BPF_SIZE(insn->code) >> 3],
insn->src_reg, insn->off);
} else if (class == BPF_LD) {
if (BPF_MODE(insn->code) == BPF_ABS) {
verbose("(%02x) r0 = *(%s *)skb[%d]\n",
insn->code,
bpf_ldst_string[BPF_SIZE(insn->code) >> 3],
insn->imm);
} else if (BPF_MODE(insn->code) == BPF_IND) {
verbose("(%02x) r0 = *(%s *)skb[r%d + %d]\n",
insn->code,
bpf_ldst_string[BPF_SIZE(insn->code) >> 3],
insn->src_reg, insn->imm);
} else if (BPF_MODE(insn->code) == BPF_IMM) {
verbose("(%02x) r%d = 0x%x\n",
insn->code, insn->dst_reg, insn->imm);
} else {
verbose("BUG_ld_%02x\n", insn->code);
return;
}
} else if (class == BPF_JMP) {
u8 opcode = BPF_OP(insn->code);
if (opcode == BPF_CALL) {
verbose("(%02x) call %d\n", insn->code, insn->imm);
} else if (insn->code == (BPF_JMP | BPF_JA)) {
verbose("(%02x) goto pc%+d\n",
insn->code, insn->off);
} else if (insn->code == (BPF_JMP | BPF_EXIT)) {
verbose("(%02x) exit\n", insn->code);
} else if (BPF_SRC(insn->code) == BPF_X) {
verbose("(%02x) if r%d %s r%d goto pc%+d\n",
insn->code, insn->dst_reg,
bpf_jmp_string[BPF_OP(insn->code) >> 4],
insn->src_reg, insn->off);
} else {
verbose("(%02x) if r%d %s 0x%x goto pc%+d\n",
insn->code, insn->dst_reg,
bpf_jmp_string[BPF_OP(insn->code) >> 4],
insn->imm, insn->off);
}
} else {
verbose("(%02x) %s\n", insn->code, bpf_class_string[class]);
}
}
static int pop_stack(struct verifier_env *env, int *prev_insn_idx)
{
struct verifier_stack_elem *elem;
int insn_idx;
if (env->head == NULL)
return -1;
memcpy(&env->cur_state, &env->head->st, sizeof(env->cur_state));
insn_idx = env->head->insn_idx;
if (prev_insn_idx)
*prev_insn_idx = env->head->prev_insn_idx;
elem = env->head->next;
kfree(env->head);
env->head = elem;
env->stack_size--;
return insn_idx;
}
static struct verifier_state *push_stack(struct verifier_env *env, int insn_idx,
int prev_insn_idx)
{
struct verifier_stack_elem *elem;
elem = kmalloc(sizeof(struct verifier_stack_elem), GFP_KERNEL);
if (!elem)
goto err;
memcpy(&elem->st, &env->cur_state, sizeof(env->cur_state));
elem->insn_idx = insn_idx;
elem->prev_insn_idx = prev_insn_idx;
elem->next = env->head;
env->head = elem;
env->stack_size++;
if (env->stack_size > BPF_COMPLEXITY_LIMIT_STACK) {
verbose("BPF program is too complex\n");
goto err;
}
return &elem->st;
err:
while (pop_stack(env, NULL) >= 0);
return NULL;
}
static void init_reg_state(struct reg_state *regs)
{
int i;
for (i = 0; i < MAX_BPF_REG; i++) {
regs[i].type = NOT_INIT;
regs[i].imm = 0;
}
regs[BPF_REG_FP].type = FRAME_PTR;
regs[BPF_REG_1].type = PTR_TO_CTX;
}
static void mark_reg_unknown_value(struct reg_state *regs, u32 regno)
{
BUG_ON(regno >= MAX_BPF_REG);
regs[regno].type = UNKNOWN_VALUE;
regs[regno].imm = 0;
}
static int check_reg_arg(struct reg_state *regs, u32 regno,
enum reg_arg_type t)
{
if (regno >= MAX_BPF_REG) {
verbose("R%d is invalid\n", regno);
return -EINVAL;
}
if (t == SRC_OP) {
if (regs[regno].type == NOT_INIT) {
verbose("R%d !read_ok\n", regno);
return -EACCES;
}
} else {
if (regno == BPF_REG_FP) {
verbose("frame pointer is read only\n");
return -EACCES;
}
if (t == DST_OP)
mark_reg_unknown_value(regs, regno);
}
return 0;
}
static int bpf_size_to_bytes(int bpf_size)
{
if (bpf_size == BPF_W)
return 4;
else if (bpf_size == BPF_H)
return 2;
else if (bpf_size == BPF_B)
return 1;
else if (bpf_size == BPF_DW)
return 8;
else
return -EINVAL;
}
static bool is_spillable_regtype(enum bpf_reg_type type)
{
switch (type) {
case PTR_TO_MAP_VALUE:
case PTR_TO_MAP_VALUE_OR_NULL:
case PTR_TO_STACK:
case PTR_TO_CTX:
case PTR_TO_PACKET:
case PTR_TO_PACKET_END:
case FRAME_PTR:
case CONST_PTR_TO_MAP:
return true;
default:
return false;
}
}
static int check_stack_write(struct verifier_state *state, int off, int size,
int value_regno)
{
int i;
if (value_regno >= 0 &&
is_spillable_regtype(state->regs[value_regno].type)) {
if (size != BPF_REG_SIZE) {
verbose("invalid size of register spill\n");
return -EACCES;
}
state->spilled_regs[(MAX_BPF_STACK + off) / BPF_REG_SIZE] =
state->regs[value_regno];
for (i = 0; i < BPF_REG_SIZE; i++)
state->stack_slot_type[MAX_BPF_STACK + off + i] = STACK_SPILL;
} else {
state->spilled_regs[(MAX_BPF_STACK + off) / BPF_REG_SIZE] =
(struct reg_state) {};
for (i = 0; i < size; i++)
state->stack_slot_type[MAX_BPF_STACK + off + i] = STACK_MISC;
}
return 0;
}
static int check_stack_read(struct verifier_state *state, int off, int size,
int value_regno)
{
u8 *slot_type;
int i;
slot_type = &state->stack_slot_type[MAX_BPF_STACK + off];
if (slot_type[0] == STACK_SPILL) {
if (size != BPF_REG_SIZE) {
verbose("invalid size of register spill\n");
return -EACCES;
}
for (i = 1; i < BPF_REG_SIZE; i++) {
if (slot_type[i] != STACK_SPILL) {
verbose("corrupted spill memory\n");
return -EACCES;
}
}
if (value_regno >= 0)
state->regs[value_regno] =
state->spilled_regs[(MAX_BPF_STACK + off) / BPF_REG_SIZE];
return 0;
} else {
for (i = 0; i < size; i++) {
if (slot_type[i] != STACK_MISC) {
verbose("invalid read from stack off %d+%d size %d\n",
off, i, size);
return -EACCES;
}
}
if (value_regno >= 0)
mark_reg_unknown_value(state->regs, value_regno);
return 0;
}
}
static int check_map_access(struct verifier_env *env, u32 regno, int off,
int size)
{
struct bpf_map *map = env->cur_state.regs[regno].map_ptr;
if (off < 0 || off + size > map->value_size) {
verbose("invalid access to map value, value_size=%d off=%d size=%d\n",
map->value_size, off, size);
return -EACCES;
}
return 0;
}
static int check_packet_access(struct verifier_env *env, u32 regno, int off,
int size)
{
struct reg_state *regs = env->cur_state.regs;
struct reg_state *reg = &regs[regno];
off += reg->off;
if (off < 0 || off + size > reg->range) {
verbose("invalid access to packet, off=%d size=%d, R%d(id=%d,off=%d,r=%d)\n",
off, size, regno, reg->id, reg->off, reg->range);
return -EACCES;
}
return 0;
}
static int check_ctx_access(struct verifier_env *env, int off, int size,
enum bpf_access_type t, enum bpf_reg_type *reg_type)
{
if (env->prog->aux->ops->is_valid_access &&
env->prog->aux->ops->is_valid_access(off, size, t, reg_type)) {
if (env->prog->aux->max_ctx_offset < off + size)
env->prog->aux->max_ctx_offset = off + size;
return 0;
}
verbose("invalid bpf_context access off=%d size=%d\n", off, size);
return -EACCES;
}
static bool is_pointer_value(struct verifier_env *env, int regno)
{
if (env->allow_ptr_leaks)
return false;
switch (env->cur_state.regs[regno].type) {
case UNKNOWN_VALUE:
case CONST_IMM:
return false;
default:
return true;
}
}
static int check_ptr_alignment(struct verifier_env *env, struct reg_state *reg,
int off, int size)
{
if (reg->type != PTR_TO_PACKET) {
if (off % size != 0) {
verbose("misaligned access off %d size %d\n", off, size);
return -EACCES;
} else {
return 0;
}
}
switch (env->prog->type) {
case BPF_PROG_TYPE_SCHED_CLS:
case BPF_PROG_TYPE_SCHED_ACT:
break;
default:
verbose("verifier is misconfigured\n");
return -EACCES;
}
if (IS_ENABLED(CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS))
return 0;
if (reg->id && size != 1) {
verbose("Unknown packet alignment. Only byte-sized access allowed\n");
return -EACCES;
}
if ((NET_IP_ALIGN + reg->off + off) % size != 0) {
verbose("misaligned packet access off %d+%d+%d size %d\n",
NET_IP_ALIGN, reg->off, off, size);
return -EACCES;
}
return 0;
}
static int check_mem_access(struct verifier_env *env, u32 regno, int off,
int bpf_size, enum bpf_access_type t,
int value_regno)
{
struct verifier_state *state = &env->cur_state;
struct reg_state *reg = &state->regs[regno];
int size, err = 0;
if (reg->type == PTR_TO_STACK)
off += reg->imm;
size = bpf_size_to_bytes(bpf_size);
if (size < 0)
return size;
err = check_ptr_alignment(env, reg, off, size);
if (err)
return err;
if (reg->type == PTR_TO_MAP_VALUE) {
if (t == BPF_WRITE && value_regno >= 0 &&
is_pointer_value(env, value_regno)) {
verbose("R%d leaks addr into map\n", value_regno);
return -EACCES;
}
err = check_map_access(env, regno, off, size);
if (!err && t == BPF_READ && value_regno >= 0)
mark_reg_unknown_value(state->regs, value_regno);
} else if (reg->type == PTR_TO_CTX) {
enum bpf_reg_type reg_type = UNKNOWN_VALUE;
if (t == BPF_WRITE && value_regno >= 0 &&
is_pointer_value(env, value_regno)) {
verbose("R%d leaks addr into ctx\n", value_regno);
return -EACCES;
}
err = check_ctx_access(env, off, size, t, &reg_type);
if (!err && t == BPF_READ && value_regno >= 0) {
mark_reg_unknown_value(state->regs, value_regno);
if (env->allow_ptr_leaks)
state->regs[value_regno].type = reg_type;
}
} else if (reg->type == FRAME_PTR || reg->type == PTR_TO_STACK) {
if (off >= 0 || off < -MAX_BPF_STACK) {
verbose("invalid stack off=%d size=%d\n", off, size);
return -EACCES;
}
if (t == BPF_WRITE) {
if (!env->allow_ptr_leaks &&
state->stack_slot_type[MAX_BPF_STACK + off] == STACK_SPILL &&
size != BPF_REG_SIZE) {
verbose("attempt to corrupt spilled pointer on stack\n");
return -EACCES;
}
err = check_stack_write(state, off, size, value_regno);
} else {
err = check_stack_read(state, off, size, value_regno);
}
} else if (state->regs[regno].type == PTR_TO_PACKET) {
if (t == BPF_WRITE) {
verbose("cannot write into packet\n");
return -EACCES;
}
err = check_packet_access(env, regno, off, size);
if (!err && t == BPF_READ && value_regno >= 0)
mark_reg_unknown_value(state->regs, value_regno);
} else {
verbose("R%d invalid mem access '%s'\n",
regno, reg_type_str[reg->type]);
return -EACCES;
}
if (!err && size <= 2 && value_regno >= 0 && env->allow_ptr_leaks &&
state->regs[value_regno].type == UNKNOWN_VALUE) {
state->regs[value_regno].imm = 64 - size * 8;
}
return err;
}
static int check_xadd(struct verifier_env *env, struct bpf_insn *insn)
{
struct reg_state *regs = env->cur_state.regs;
int err;
if ((BPF_SIZE(insn->code) != BPF_W && BPF_SIZE(insn->code) != BPF_DW) ||
insn->imm != 0) {
verbose("BPF_XADD uses reserved fields\n");
return -EINVAL;
}
err = check_reg_arg(regs, insn->src_reg, SRC_OP);
if (err)
return err;
err = check_reg_arg(regs, insn->dst_reg, SRC_OP);
if (err)
return err;
err = check_mem_access(env, insn->dst_reg, insn->off,
BPF_SIZE(insn->code), BPF_READ, -1);
if (err)
return err;
return check_mem_access(env, insn->dst_reg, insn->off,
BPF_SIZE(insn->code), BPF_WRITE, -1);
}
static int check_stack_boundary(struct verifier_env *env, int regno,
int access_size, bool zero_size_allowed,
struct bpf_call_arg_meta *meta)
{
struct verifier_state *state = &env->cur_state;
struct reg_state *regs = state->regs;
int off, i;
if (regs[regno].type != PTR_TO_STACK) {
if (zero_size_allowed && access_size == 0 &&
regs[regno].type == CONST_IMM &&
regs[regno].imm == 0)
return 0;
verbose("R%d type=%s expected=%s\n", regno,
reg_type_str[regs[regno].type],
reg_type_str[PTR_TO_STACK]);
return -EACCES;
}
off = regs[regno].imm;
if (off >= 0 || off < -MAX_BPF_STACK || off + access_size > 0 ||
access_size <= 0) {
verbose("invalid stack type R%d off=%d access_size=%d\n",
regno, off, access_size);
return -EACCES;
}
if (meta && meta->raw_mode) {
meta->access_size = access_size;
meta->regno = regno;
return 0;
}
for (i = 0; i < access_size; i++) {
if (state->stack_slot_type[MAX_BPF_STACK + off + i] != STACK_MISC) {
verbose("invalid indirect read from stack off %d+%d size %d\n",
off, i, access_size);
return -EACCES;
}
}
return 0;
}
static int check_func_arg(struct verifier_env *env, u32 regno,
enum bpf_arg_type arg_type,
struct bpf_call_arg_meta *meta)
{
struct reg_state *reg = env->cur_state.regs + regno;
enum bpf_reg_type expected_type;
int err = 0;
if (arg_type == ARG_DONTCARE)
return 0;
if (reg->type == NOT_INIT) {
verbose("R%d !read_ok\n", regno);
return -EACCES;
}
if (arg_type == ARG_ANYTHING) {
if (is_pointer_value(env, regno)) {
verbose("R%d leaks addr into helper function\n", regno);
return -EACCES;
}
return 0;
}
if (arg_type == ARG_PTR_TO_MAP_KEY ||
arg_type == ARG_PTR_TO_MAP_VALUE) {
expected_type = PTR_TO_STACK;
} else if (arg_type == ARG_CONST_STACK_SIZE ||
arg_type == ARG_CONST_STACK_SIZE_OR_ZERO) {
expected_type = CONST_IMM;
} else if (arg_type == ARG_CONST_MAP_PTR) {
expected_type = CONST_PTR_TO_MAP;
} else if (arg_type == ARG_PTR_TO_CTX) {
expected_type = PTR_TO_CTX;
} else if (arg_type == ARG_PTR_TO_STACK ||
arg_type == ARG_PTR_TO_RAW_STACK) {
expected_type = PTR_TO_STACK;
if (reg->type == CONST_IMM && reg->imm == 0)
expected_type = CONST_IMM;
meta->raw_mode = arg_type == ARG_PTR_TO_RAW_STACK;
} else {
verbose("unsupported arg_type %d\n", arg_type);
return -EFAULT;
}
if (reg->type != expected_type) {
verbose("R%d type=%s expected=%s\n", regno,
reg_type_str[reg->type], reg_type_str[expected_type]);
return -EACCES;
}
if (arg_type == ARG_CONST_MAP_PTR) {
meta->map_ptr = reg->map_ptr;
} else if (arg_type == ARG_PTR_TO_MAP_KEY) {
if (!meta->map_ptr) {
verbose("invalid map_ptr to access map->key\n");
return -EACCES;
}
err = check_stack_boundary(env, regno, meta->map_ptr->key_size,
false, NULL);
} else if (arg_type == ARG_PTR_TO_MAP_VALUE) {
if (!meta->map_ptr) {
verbose("invalid map_ptr to access map->value\n");
return -EACCES;
}
err = check_stack_boundary(env, regno,
meta->map_ptr->value_size,
false, NULL);
} else if (arg_type == ARG_CONST_STACK_SIZE ||
arg_type == ARG_CONST_STACK_SIZE_OR_ZERO) {
bool zero_size_allowed = (arg_type == ARG_CONST_STACK_SIZE_OR_ZERO);
if (regno == 0) {
verbose("ARG_CONST_STACK_SIZE cannot be first argument\n");
return -EACCES;
}
err = check_stack_boundary(env, regno - 1, reg->imm,
zero_size_allowed, meta);
}
return err;
}
static int check_map_func_compatibility(struct bpf_map *map, int func_id)
{
if (!map)
return 0;
switch (map->map_type) {
case BPF_MAP_TYPE_PROG_ARRAY:
if (func_id != BPF_FUNC_tail_call)
goto error;
break;
case BPF_MAP_TYPE_PERF_EVENT_ARRAY:
if (func_id != BPF_FUNC_perf_event_read &&
func_id != BPF_FUNC_perf_event_output)
goto error;
break;
case BPF_MAP_TYPE_STACK_TRACE:
if (func_id != BPF_FUNC_get_stackid)
goto error;
break;
default:
break;
}
switch (func_id) {
case BPF_FUNC_tail_call:
if (map->map_type != BPF_MAP_TYPE_PROG_ARRAY)
goto error;
break;
case BPF_FUNC_perf_event_read:
case BPF_FUNC_perf_event_output:
if (map->map_type != BPF_MAP_TYPE_PERF_EVENT_ARRAY)
goto error;
break;
case BPF_FUNC_get_stackid:
if (map->map_type != BPF_MAP_TYPE_STACK_TRACE)
goto error;
break;
default:
break;
}
return 0;
error:
verbose("cannot pass map_type %d into func %d\n",
map->map_type, func_id);
return -EINVAL;
}
static int check_raw_mode(const struct bpf_func_proto *fn)
{
int count = 0;
if (fn->arg1_type == ARG_PTR_TO_RAW_STACK)
count++;
if (fn->arg2_type == ARG_PTR_TO_RAW_STACK)
count++;
if (fn->arg3_type == ARG_PTR_TO_RAW_STACK)
count++;
if (fn->arg4_type == ARG_PTR_TO_RAW_STACK)
count++;
if (fn->arg5_type == ARG_PTR_TO_RAW_STACK)
count++;
return count > 1 ? -EINVAL : 0;
}
static void clear_all_pkt_pointers(struct verifier_env *env)
{
struct verifier_state *state = &env->cur_state;
struct reg_state *regs = state->regs, *reg;
int i;
for (i = 0; i < MAX_BPF_REG; i++)
if (regs[i].type == PTR_TO_PACKET ||
regs[i].type == PTR_TO_PACKET_END)
mark_reg_unknown_value(regs, i);
for (i = 0; i < MAX_BPF_STACK; i += BPF_REG_SIZE) {
if (state->stack_slot_type[i] != STACK_SPILL)
continue;
reg = &state->spilled_regs[i / BPF_REG_SIZE];
if (reg->type != PTR_TO_PACKET &&
reg->type != PTR_TO_PACKET_END)
continue;
reg->type = UNKNOWN_VALUE;
reg->imm = 0;
}
}
static int check_call(struct verifier_env *env, int func_id)
{
struct verifier_state *state = &env->cur_state;
const struct bpf_func_proto *fn = NULL;
struct reg_state *regs = state->regs;
struct reg_state *reg;
struct bpf_call_arg_meta meta;
bool changes_data;
int i, err;
if (func_id < 0 || func_id >= __BPF_FUNC_MAX_ID) {
verbose("invalid func %d\n", func_id);
return -EINVAL;
}
if (env->prog->aux->ops->get_func_proto)
fn = env->prog->aux->ops->get_func_proto(func_id);
if (!fn) {
verbose("unknown func %d\n", func_id);
return -EINVAL;
}
if (!env->prog->gpl_compatible && fn->gpl_only) {
verbose("cannot call GPL only function from proprietary program\n");
return -EINVAL;
}
changes_data = bpf_helper_changes_skb_data(fn->func);
memset(&meta, 0, sizeof(meta));
err = check_raw_mode(fn);
if (err) {
verbose("kernel subsystem misconfigured func %d\n", func_id);
return err;
}
err = check_func_arg(env, BPF_REG_1, fn->arg1_type, &meta);
if (err)
return err;
err = check_func_arg(env, BPF_REG_2, fn->arg2_type, &meta);
if (err)
return err;
err = check_func_arg(env, BPF_REG_3, fn->arg3_type, &meta);
if (err)
return err;
err = check_func_arg(env, BPF_REG_4, fn->arg4_type, &meta);
if (err)
return err;
err = check_func_arg(env, BPF_REG_5, fn->arg5_type, &meta);
if (err)
return err;
for (i = 0; i < meta.access_size; i++) {
err = check_mem_access(env, meta.regno, i, BPF_B, BPF_WRITE, -1);
if (err)
return err;
}
for (i = 0; i < CALLER_SAVED_REGS; i++) {
reg = regs + caller_saved[i];
reg->type = NOT_INIT;
reg->imm = 0;
}
if (fn->ret_type == RET_INTEGER) {
regs[BPF_REG_0].type = UNKNOWN_VALUE;
} else if (fn->ret_type == RET_VOID) {
regs[BPF_REG_0].type = NOT_INIT;
} else if (fn->ret_type == RET_PTR_TO_MAP_VALUE_OR_NULL) {
regs[BPF_REG_0].type = PTR_TO_MAP_VALUE_OR_NULL;
if (meta.map_ptr == NULL) {
verbose("kernel subsystem misconfigured verifier\n");
return -EINVAL;
}
regs[BPF_REG_0].map_ptr = meta.map_ptr;
} else {
verbose("unknown return type %d of func %d\n",
fn->ret_type, func_id);
return -EINVAL;
}
err = check_map_func_compatibility(meta.map_ptr, func_id);
if (err)
return err;
if (changes_data)
clear_all_pkt_pointers(env);
return 0;
}
static int check_packet_ptr_add(struct verifier_env *env, struct bpf_insn *insn)
{
struct reg_state *regs = env->cur_state.regs;
struct reg_state *dst_reg = &regs[insn->dst_reg];
struct reg_state *src_reg = &regs[insn->src_reg];
struct reg_state tmp_reg;
s32 imm;
if (BPF_SRC(insn->code) == BPF_K) {
imm = insn->imm;
add_imm:
if (imm <= 0) {
verbose("addition of negative constant to packet pointer is not allowed\n");
return -EACCES;
}
if (imm >= MAX_PACKET_OFF ||
imm + dst_reg->off >= MAX_PACKET_OFF) {
verbose("constant %d is too large to add to packet pointer\n",
imm);
return -EACCES;
}
dst_reg->off += imm;
} else {
if (src_reg->type == PTR_TO_PACKET) {
tmp_reg = *dst_reg;
*dst_reg = *src_reg;
src_reg = &tmp_reg;
}
if (src_reg->type == CONST_IMM) {
imm = src_reg->imm;
goto add_imm;
}
if (src_reg->type != UNKNOWN_VALUE) {
verbose("cannot add '%s' to ptr_to_packet\n",
reg_type_str[src_reg->type]);
return -EACCES;
}
if (src_reg->imm < 48) {
verbose("cannot add integer value with %lld upper zero bits to ptr_to_packet\n",
src_reg->imm);
return -EACCES;
}
dst_reg->id++;
dst_reg->off = 0;
dst_reg->range = 0;
}
return 0;
}
static int evaluate_reg_alu(struct verifier_env *env, struct bpf_insn *insn)
{
struct reg_state *regs = env->cur_state.regs;
struct reg_state *dst_reg = &regs[insn->dst_reg];
u8 opcode = BPF_OP(insn->code);
s64 imm_log2;
if (BPF_SRC(insn->code) == BPF_X) {
struct reg_state *src_reg = &regs[insn->src_reg];
if (src_reg->type == UNKNOWN_VALUE && src_reg->imm > 0 &&
dst_reg->imm && opcode == BPF_ADD) {
dst_reg->imm = min(dst_reg->imm, src_reg->imm);
dst_reg->imm--;
return 0;
}
if (src_reg->type == CONST_IMM && src_reg->imm > 0 &&
dst_reg->imm && opcode == BPF_ADD) {
imm_log2 = __ilog2_u64((long long)src_reg->imm);
dst_reg->imm = min(dst_reg->imm, 63 - imm_log2);
dst_reg->imm--;
return 0;
}
dst_reg->imm = 0;
return 0;
}
imm_log2 = __ilog2_u64((long long)insn->imm);
if (dst_reg->imm && opcode == BPF_LSH) {
dst_reg->imm -= insn->imm;
} else if (dst_reg->imm && opcode == BPF_MUL) {
dst_reg->imm -= imm_log2 + 1;
} else if (opcode == BPF_AND) {
dst_reg->imm = 63 - imm_log2;
} else if (dst_reg->imm && opcode == BPF_ADD) {
dst_reg->imm = min(dst_reg->imm, 63 - imm_log2);
dst_reg->imm--;
} else if (opcode == BPF_RSH) {
dst_reg->imm += insn->imm;
if (unlikely(dst_reg->imm > 64))
dst_reg->imm = 64;
} else {
dst_reg->imm = 0;
}
if (dst_reg->imm < 0) {
dst_reg->imm = 0;
}
return 0;
}
static int evaluate_reg_imm_alu(struct verifier_env *env, struct bpf_insn *insn)
{
struct reg_state *regs = env->cur_state.regs;
struct reg_state *dst_reg = &regs[insn->dst_reg];
struct reg_state *src_reg = &regs[insn->src_reg];
u8 opcode = BPF_OP(insn->code);
if (opcode == BPF_ADD && BPF_SRC(insn->code) == BPF_K)
dst_reg->imm += insn->imm;
else if (opcode == BPF_ADD && BPF_SRC(insn->code) == BPF_X &&
src_reg->type == CONST_IMM)
dst_reg->imm += src_reg->imm;
else
mark_reg_unknown_value(regs, insn->dst_reg);
return 0;
}
static int check_alu_op(struct verifier_env *env, struct bpf_insn *insn)
{
struct reg_state *regs = env->cur_state.regs, *dst_reg;
u8 opcode = BPF_OP(insn->code);
int err;
if (opcode == BPF_END || opcode == BPF_NEG) {
if (opcode == BPF_NEG) {
if (BPF_SRC(insn->code) != 0 ||
insn->src_reg != BPF_REG_0 ||
insn->off != 0 || insn->imm != 0) {
verbose("BPF_NEG uses reserved fields\n");
return -EINVAL;
}
} else {
if (insn->src_reg != BPF_REG_0 || insn->off != 0 ||
(insn->imm != 16 && insn->imm != 32 && insn->imm != 64)) {
verbose("BPF_END uses reserved fields\n");
return -EINVAL;
}
}
err = check_reg_arg(regs, insn->dst_reg, SRC_OP);
if (err)
return err;
if (is_pointer_value(env, insn->dst_reg)) {
verbose("R%d pointer arithmetic prohibited\n",
insn->dst_reg);
return -EACCES;
}
err = check_reg_arg(regs, insn->dst_reg, DST_OP);
if (err)
return err;
} else if (opcode == BPF_MOV) {
if (BPF_SRC(insn->code) == BPF_X) {
if (insn->imm != 0 || insn->off != 0) {
verbose("BPF_MOV uses reserved fields\n");
return -EINVAL;
}
err = check_reg_arg(regs, insn->src_reg, SRC_OP);
if (err)
return err;
} else {
if (insn->src_reg != BPF_REG_0 || insn->off != 0) {
verbose("BPF_MOV uses reserved fields\n");
return -EINVAL;
}
}
err = check_reg_arg(regs, insn->dst_reg, DST_OP);
if (err)
return err;
if (BPF_SRC(insn->code) == BPF_X) {
if (BPF_CLASS(insn->code) == BPF_ALU64) {
regs[insn->dst_reg] = regs[insn->src_reg];
} else {
if (is_pointer_value(env, insn->src_reg)) {
verbose("R%d partial copy of pointer\n",
insn->src_reg);
return -EACCES;
}
regs[insn->dst_reg].type = UNKNOWN_VALUE;
regs[insn->dst_reg].map_ptr = NULL;
}
} else {
regs[insn->dst_reg].type = CONST_IMM;
regs[insn->dst_reg].imm = insn->imm;
}
} else if (opcode > BPF_END) {
verbose("invalid BPF_ALU opcode %x\n", opcode);
return -EINVAL;
} else {
if (BPF_SRC(insn->code) == BPF_X) {
if (insn->imm != 0 || insn->off != 0) {
verbose("BPF_ALU uses reserved fields\n");
return -EINVAL;
}
err = check_reg_arg(regs, insn->src_reg, SRC_OP);
if (err)
return err;
} else {
if (insn->src_reg != BPF_REG_0 || insn->off != 0) {
verbose("BPF_ALU uses reserved fields\n");
return -EINVAL;
}
}
err = check_reg_arg(regs, insn->dst_reg, SRC_OP);
if (err)
return err;
if ((opcode == BPF_MOD || opcode == BPF_DIV) &&
BPF_SRC(insn->code) == BPF_K && insn->imm == 0) {
verbose("div by zero\n");
return -EINVAL;
}
if ((opcode == BPF_LSH || opcode == BPF_RSH ||
opcode == BPF_ARSH) && BPF_SRC(insn->code) == BPF_K) {
int size = BPF_CLASS(insn->code) == BPF_ALU64 ? 64 : 32;
if (insn->imm < 0 || insn->imm >= size) {
verbose("invalid shift %d\n", insn->imm);
return -EINVAL;
}
}
err = check_reg_arg(regs, insn->dst_reg, DST_OP_NO_MARK);
if (err)
return err;
dst_reg = &regs[insn->dst_reg];
if (opcode == BPF_ADD && BPF_CLASS(insn->code) == BPF_ALU64 &&
dst_reg->type == FRAME_PTR && BPF_SRC(insn->code) == BPF_K) {
dst_reg->type = PTR_TO_STACK;
dst_reg->imm = insn->imm;
return 0;
} else if (opcode == BPF_ADD &&
BPF_CLASS(insn->code) == BPF_ALU64 &&
(dst_reg->type == PTR_TO_PACKET ||
(BPF_SRC(insn->code) == BPF_X &&
regs[insn->src_reg].type == PTR_TO_PACKET))) {
return check_packet_ptr_add(env, insn);
} else if (BPF_CLASS(insn->code) == BPF_ALU64 &&
dst_reg->type == UNKNOWN_VALUE &&
env->allow_ptr_leaks) {
return evaluate_reg_alu(env, insn);
} else if (BPF_CLASS(insn->code) == BPF_ALU64 &&
dst_reg->type == CONST_IMM &&
env->allow_ptr_leaks) {
return evaluate_reg_imm_alu(env, insn);
} else if (is_pointer_value(env, insn->dst_reg)) {
verbose("R%d pointer arithmetic prohibited\n",
insn->dst_reg);
return -EACCES;
} else if (BPF_SRC(insn->code) == BPF_X &&
is_pointer_value(env, insn->src_reg)) {
verbose("R%d pointer arithmetic prohibited\n",
insn->src_reg);
return -EACCES;
}
mark_reg_unknown_value(regs, insn->dst_reg);
}
return 0;
}
static void find_good_pkt_pointers(struct verifier_env *env,
struct reg_state *dst_reg)
{
struct verifier_state *state = &env->cur_state;
struct reg_state *regs = state->regs, *reg;
int i;
for (i = 0; i < MAX_BPF_REG; i++)
if (regs[i].type == PTR_TO_PACKET && regs[i].id == dst_reg->id)
regs[i].range = dst_reg->off;
for (i = 0; i < MAX_BPF_STACK; i += BPF_REG_SIZE) {
if (state->stack_slot_type[i] != STACK_SPILL)
continue;
reg = &state->spilled_regs[i / BPF_REG_SIZE];
if (reg->type == PTR_TO_PACKET && reg->id == dst_reg->id)
reg->range = dst_reg->off;
}
}
static int check_cond_jmp_op(struct verifier_env *env,
struct bpf_insn *insn, int *insn_idx)
{
struct reg_state *regs = env->cur_state.regs, *dst_reg;
struct verifier_state *other_branch;
u8 opcode = BPF_OP(insn->code);
int err;
if (opcode > BPF_EXIT) {
verbose("invalid BPF_JMP opcode %x\n", opcode);
return -EINVAL;
}
if (BPF_SRC(insn->code) == BPF_X) {
if (insn->imm != 0) {
verbose("BPF_JMP uses reserved fields\n");
return -EINVAL;
}
err = check_reg_arg(regs, insn->src_reg, SRC_OP);
if (err)
return err;
if (is_pointer_value(env, insn->src_reg)) {
verbose("R%d pointer comparison prohibited\n",
insn->src_reg);
return -EACCES;
}
} else {
if (insn->src_reg != BPF_REG_0) {
verbose("BPF_JMP uses reserved fields\n");
return -EINVAL;
}
}
err = check_reg_arg(regs, insn->dst_reg, SRC_OP);
if (err)
return err;
dst_reg = &regs[insn->dst_reg];
if (BPF_SRC(insn->code) == BPF_K &&
(opcode == BPF_JEQ || opcode == BPF_JNE) &&
dst_reg->type == CONST_IMM && dst_reg->imm == insn->imm) {
if (opcode == BPF_JEQ) {
*insn_idx += insn->off;
return 0;
} else {
return 0;
}
}
other_branch = push_stack(env, *insn_idx + insn->off + 1, *insn_idx);
if (!other_branch)
return -EFAULT;
if (BPF_SRC(insn->code) == BPF_K &&
insn->imm == 0 && (opcode == BPF_JEQ || opcode == BPF_JNE) &&
dst_reg->type == PTR_TO_MAP_VALUE_OR_NULL) {
if (opcode == BPF_JEQ) {
regs[insn->dst_reg].type = PTR_TO_MAP_VALUE;
mark_reg_unknown_value(other_branch->regs,
insn->dst_reg);
} else {
other_branch->regs[insn->dst_reg].type = PTR_TO_MAP_VALUE;
mark_reg_unknown_value(regs, insn->dst_reg);
}
} else if (BPF_SRC(insn->code) == BPF_X && opcode == BPF_JGT &&
dst_reg->type == PTR_TO_PACKET &&
regs[insn->src_reg].type == PTR_TO_PACKET_END) {
find_good_pkt_pointers(env, dst_reg);
} else if (is_pointer_value(env, insn->dst_reg)) {
verbose("R%d pointer comparison prohibited\n", insn->dst_reg);
return -EACCES;
}
if (log_level)
print_verifier_state(&env->cur_state);
return 0;
}
static struct bpf_map *ld_imm64_to_map_ptr(struct bpf_insn *insn)
{
u64 imm64 = ((u64) (u32) insn[0].imm) | ((u64) (u32) insn[1].imm) << 32;
return (struct bpf_map *) (unsigned long) imm64;
}
static int check_ld_imm(struct verifier_env *env, struct bpf_insn *insn)
{
struct reg_state *regs = env->cur_state.regs;
int err;
if (BPF_SIZE(insn->code) != BPF_DW) {
verbose("invalid BPF_LD_IMM insn\n");
return -EINVAL;
}
if (insn->off != 0) {
verbose("BPF_LD_IMM64 uses reserved fields\n");
return -EINVAL;
}
err = check_reg_arg(regs, insn->dst_reg, DST_OP);
if (err)
return err;
if (insn->src_reg == 0)
return 0;
BUG_ON(insn->src_reg != BPF_PSEUDO_MAP_FD);
regs[insn->dst_reg].type = CONST_PTR_TO_MAP;
regs[insn->dst_reg].map_ptr = ld_imm64_to_map_ptr(insn);
return 0;
}
static bool may_access_skb(enum bpf_prog_type type)
{
switch (type) {
case BPF_PROG_TYPE_SOCKET_FILTER:
case BPF_PROG_TYPE_SCHED_CLS:
case BPF_PROG_TYPE_SCHED_ACT:
return true;
default:
return false;
}
}
static int check_ld_abs(struct verifier_env *env, struct bpf_insn *insn)
{
struct reg_state *regs = env->cur_state.regs;
u8 mode = BPF_MODE(insn->code);
struct reg_state *reg;
int i, err;
if (!may_access_skb(env->prog->type)) {
verbose("BPF_LD_[ABS|IND] instructions not allowed for this program type\n");
return -EINVAL;
}
if (insn->dst_reg != BPF_REG_0 || insn->off != 0 ||
BPF_SIZE(insn->code) == BPF_DW ||
(mode == BPF_ABS && insn->src_reg != BPF_REG_0)) {
verbose("BPF_LD_[ABS|IND] uses reserved fields\n");
return -EINVAL;
}
err = check_reg_arg(regs, BPF_REG_6, SRC_OP);
if (err)
return err;
if (regs[BPF_REG_6].type != PTR_TO_CTX) {
verbose("at the time of BPF_LD_ABS|IND R6 != pointer to skb\n");
return -EINVAL;
}
if (mode == BPF_IND) {
err = check_reg_arg(regs, insn->src_reg, SRC_OP);
if (err)
return err;
}
for (i = 0; i < CALLER_SAVED_REGS; i++) {
reg = regs + caller_saved[i];
reg->type = NOT_INIT;
reg->imm = 0;
}
regs[BPF_REG_0].type = UNKNOWN_VALUE;
return 0;
}
static int push_insn(int t, int w, int e, struct verifier_env *env)
{
if (e == FALLTHROUGH && insn_state[t] >= (DISCOVERED | FALLTHROUGH))
return 0;
if (e == BRANCH && insn_state[t] >= (DISCOVERED | BRANCH))
return 0;
if (w < 0 || w >= env->prog->len) {
verbose("jump out of range from insn %d to %d\n", t, w);
return -EINVAL;
}
if (e == BRANCH)
env->explored_states[w] = STATE_LIST_MARK;
if (insn_state[w] == 0) {
insn_state[t] = DISCOVERED | e;
insn_state[w] = DISCOVERED;
if (cur_stack >= env->prog->len)
return -E2BIG;
insn_stack[cur_stack++] = w;
return 1;
} else if ((insn_state[w] & 0xF0) == DISCOVERED) {
verbose("back-edge from insn %d to %d\n", t, w);
return -EINVAL;
} else if (insn_state[w] == EXPLORED) {
insn_state[t] = DISCOVERED | e;
} else {
verbose("insn state internal bug\n");
return -EFAULT;
}
return 0;
}
static int check_cfg(struct verifier_env *env)
{
struct bpf_insn *insns = env->prog->insnsi;
int insn_cnt = env->prog->len;
int ret = 0;
int i, t;
insn_state = kcalloc(insn_cnt, sizeof(int), GFP_KERNEL);
if (!insn_state)
return -ENOMEM;
insn_stack = kcalloc(insn_cnt, sizeof(int), GFP_KERNEL);
if (!insn_stack) {
kfree(insn_state);
return -ENOMEM;
}
insn_state[0] = DISCOVERED;
insn_stack[0] = 0;
cur_stack = 1;
peek_stack:
if (cur_stack == 0)
goto check_state;
t = insn_stack[cur_stack - 1];
if (BPF_CLASS(insns[t].code) == BPF_JMP) {
u8 opcode = BPF_OP(insns[t].code);
if (opcode == BPF_EXIT) {
goto mark_explored;
} else if (opcode == BPF_CALL) {
ret = push_insn(t, t + 1, FALLTHROUGH, env);
if (ret == 1)
goto peek_stack;
else if (ret < 0)
goto err_free;
if (t + 1 < insn_cnt)
env->explored_states[t + 1] = STATE_LIST_MARK;
} else if (opcode == BPF_JA) {
if (BPF_SRC(insns[t].code) != BPF_K) {
ret = -EINVAL;
goto err_free;
}
ret = push_insn(t, t + insns[t].off + 1,
FALLTHROUGH, env);
if (ret == 1)
goto peek_stack;
else if (ret < 0)
goto err_free;
if (t + 1 < insn_cnt)
env->explored_states[t + 1] = STATE_LIST_MARK;
} else {
ret = push_insn(t, t + 1, FALLTHROUGH, env);
if (ret == 1)
goto peek_stack;
else if (ret < 0)
goto err_free;
ret = push_insn(t, t + insns[t].off + 1, BRANCH, env);
if (ret == 1)
goto peek_stack;
else if (ret < 0)
goto err_free;
}
} else {
ret = push_insn(t, t + 1, FALLTHROUGH, env);
if (ret == 1)
goto peek_stack;
else if (ret < 0)
goto err_free;
}
mark_explored:
insn_state[t] = EXPLORED;
if (cur_stack-- <= 0) {
verbose("pop stack internal bug\n");
ret = -EFAULT;
goto err_free;
}
goto peek_stack;
check_state:
for (i = 0; i < insn_cnt; i++) {
if (insn_state[i] != EXPLORED) {
verbose("unreachable insn %d\n", i);
ret = -EINVAL;
goto err_free;
}
}
ret = 0;
err_free:
kfree(insn_state);
kfree(insn_stack);
return ret;
}
static bool compare_ptrs_to_packet(struct reg_state *old, struct reg_state *cur)
{
if (old->id != cur->id)
return false;
if (old->off == cur->off && old->range < cur->range)
return true;
if (old->off <= cur->off &&
old->off >= old->range && cur->off >= cur->range)
return true;
return false;
}
static bool states_equal(struct verifier_state *old, struct verifier_state *cur)
{
struct reg_state *rold, *rcur;
int i;
for (i = 0; i < MAX_BPF_REG; i++) {
rold = &old->regs[i];
rcur = &cur->regs[i];
if (memcmp(rold, rcur, sizeof(*rold)) == 0)
continue;
if (rold->type == NOT_INIT ||
(rold->type == UNKNOWN_VALUE && rcur->type != NOT_INIT))
continue;
if (rold->type == PTR_TO_PACKET && rcur->type == PTR_TO_PACKET &&
compare_ptrs_to_packet(rold, rcur))
continue;
return false;
}
for (i = 0; i < MAX_BPF_STACK; i++) {
if (old->stack_slot_type[i] == STACK_INVALID)
continue;
if (old->stack_slot_type[i] != cur->stack_slot_type[i])
return false;
if (i % BPF_REG_SIZE)
continue;
if (memcmp(&old->spilled_regs[i / BPF_REG_SIZE],
&cur->spilled_regs[i / BPF_REG_SIZE],
sizeof(old->spilled_regs[0])))
return false;
else
continue;
}
return true;
}
static int is_state_visited(struct verifier_env *env, int insn_idx)
{
struct verifier_state_list *new_sl;
struct verifier_state_list *sl;
sl = env->explored_states[insn_idx];
if (!sl)
return 0;
while (sl != STATE_LIST_MARK) {
if (states_equal(&sl->state, &env->cur_state))
return 1;
sl = sl->next;
}
new_sl = kmalloc(sizeof(struct verifier_state_list), GFP_USER);
if (!new_sl)
return -ENOMEM;
memcpy(&new_sl->state, &env->cur_state, sizeof(env->cur_state));
new_sl->next = env->explored_states[insn_idx];
env->explored_states[insn_idx] = new_sl;
return 0;
}
static int do_check(struct verifier_env *env)
{
struct verifier_state *state = &env->cur_state;
struct bpf_insn *insns = env->prog->insnsi;
struct reg_state *regs = state->regs;
int insn_cnt = env->prog->len;
int insn_idx, prev_insn_idx = 0;
int insn_processed = 0;
bool do_print_state = false;
init_reg_state(regs);
insn_idx = 0;
for (;;) {
struct bpf_insn *insn;
u8 class;
int err;
if (insn_idx >= insn_cnt) {
verbose("invalid insn idx %d insn_cnt %d\n",
insn_idx, insn_cnt);
return -EFAULT;
}
insn = &insns[insn_idx];
class = BPF_CLASS(insn->code);
if (++insn_processed > BPF_COMPLEXITY_LIMIT_INSNS) {
verbose("BPF program is too large. Proccessed %d insn\n",
insn_processed);
return -E2BIG;
}
err = is_state_visited(env, insn_idx);
if (err < 0)
return err;
if (err == 1) {
if (log_level) {
if (do_print_state)
verbose("\nfrom %d to %d: safe\n",
prev_insn_idx, insn_idx);
else
verbose("%d: safe\n", insn_idx);
}
goto process_bpf_exit;
}
if (log_level && do_print_state) {
verbose("\nfrom %d to %d:", prev_insn_idx, insn_idx);
print_verifier_state(&env->cur_state);
do_print_state = false;
}
if (log_level) {
verbose("%d: ", insn_idx);
print_bpf_insn(insn);
}
if (class == BPF_ALU || class == BPF_ALU64) {
err = check_alu_op(env, insn);
if (err)
return err;
} else if (class == BPF_LDX) {
enum bpf_reg_type src_reg_type;
err = check_reg_arg(regs, insn->src_reg, SRC_OP);
if (err)
return err;
err = check_reg_arg(regs, insn->dst_reg, DST_OP_NO_MARK);
if (err)
return err;
src_reg_type = regs[insn->src_reg].type;
err = check_mem_access(env, insn->src_reg, insn->off,
BPF_SIZE(insn->code), BPF_READ,
insn->dst_reg);
if (err)
return err;
if (BPF_SIZE(insn->code) != BPF_W) {
insn_idx++;
continue;
}
if (insn->imm == 0) {
insn->imm = src_reg_type;
} else if (src_reg_type != insn->imm &&
(src_reg_type == PTR_TO_CTX ||
insn->imm == PTR_TO_CTX)) {
verbose("same insn cannot be used with different pointers\n");
return -EINVAL;
}
} else if (class == BPF_STX) {
enum bpf_reg_type dst_reg_type;
if (BPF_MODE(insn->code) == BPF_XADD) {
err = check_xadd(env, insn);
if (err)
return err;
insn_idx++;
continue;
}
err = check_reg_arg(regs, insn->src_reg, SRC_OP);
if (err)
return err;
err = check_reg_arg(regs, insn->dst_reg, SRC_OP);
if (err)
return err;
dst_reg_type = regs[insn->dst_reg].type;
err = check_mem_access(env, insn->dst_reg, insn->off,
BPF_SIZE(insn->code), BPF_WRITE,
insn->src_reg);
if (err)
return err;
if (insn->imm == 0) {
insn->imm = dst_reg_type;
} else if (dst_reg_type != insn->imm &&
(dst_reg_type == PTR_TO_CTX ||
insn->imm == PTR_TO_CTX)) {
verbose("same insn cannot be used with different pointers\n");
return -EINVAL;
}
} else if (class == BPF_ST) {
if (BPF_MODE(insn->code) != BPF_MEM ||
insn->src_reg != BPF_REG_0) {
verbose("BPF_ST uses reserved fields\n");
return -EINVAL;
}
err = check_reg_arg(regs, insn->dst_reg, SRC_OP);
if (err)
return err;
err = check_mem_access(env, insn->dst_reg, insn->off,
BPF_SIZE(insn->code), BPF_WRITE,
-1);
if (err)
return err;
} else if (class == BPF_JMP) {
u8 opcode = BPF_OP(insn->code);
if (opcode == BPF_CALL) {
if (BPF_SRC(insn->code) != BPF_K ||
insn->off != 0 ||
insn->src_reg != BPF_REG_0 ||
insn->dst_reg != BPF_REG_0) {
verbose("BPF_CALL uses reserved fields\n");
return -EINVAL;
}
err = check_call(env, insn->imm);
if (err)
return err;
} else if (opcode == BPF_JA) {
if (BPF_SRC(insn->code) != BPF_K ||
insn->imm != 0 ||
insn->src_reg != BPF_REG_0 ||
insn->dst_reg != BPF_REG_0) {
verbose("BPF_JA uses reserved fields\n");
return -EINVAL;
}
insn_idx += insn->off + 1;
continue;
} else if (opcode == BPF_EXIT) {
if (BPF_SRC(insn->code) != BPF_K ||
insn->imm != 0 ||
insn->src_reg != BPF_REG_0 ||
insn->dst_reg != BPF_REG_0) {
verbose("BPF_EXIT uses reserved fields\n");
return -EINVAL;
}
err = check_reg_arg(regs, BPF_REG_0, SRC_OP);
if (err)
return err;
if (is_pointer_value(env, BPF_REG_0)) {
verbose("R0 leaks addr as return value\n");
return -EACCES;
}
process_bpf_exit:
insn_idx = pop_stack(env, &prev_insn_idx);
if (insn_idx < 0) {
break;
} else {
do_print_state = true;
continue;
}
} else {
err = check_cond_jmp_op(env, insn, &insn_idx);
if (err)
return err;
}
} else if (class == BPF_LD) {
u8 mode = BPF_MODE(insn->code);
if (mode == BPF_ABS || mode == BPF_IND) {
err = check_ld_abs(env, insn);
if (err)
return err;
} else if (mode == BPF_IMM) {
err = check_ld_imm(env, insn);
if (err)
return err;
insn_idx++;
} else {
verbose("invalid BPF_LD mode\n");
return -EINVAL;
}
} else {
verbose("unknown insn class %d\n", class);
return -EINVAL;
}
insn_idx++;
}
verbose("processed %d insns\n", insn_processed);
return 0;
}
static int replace_map_fd_with_map_ptr(struct verifier_env *env)
{
struct bpf_insn *insn = env->prog->insnsi;
int insn_cnt = env->prog->len;
int i, j;
for (i = 0; i < insn_cnt; i++, insn++) {
if (BPF_CLASS(insn->code) == BPF_LDX &&
(BPF_MODE(insn->code) != BPF_MEM || insn->imm != 0)) {
verbose("BPF_LDX uses reserved fields\n");
return -EINVAL;
}
if (BPF_CLASS(insn->code) == BPF_STX &&
((BPF_MODE(insn->code) != BPF_MEM &&
BPF_MODE(insn->code) != BPF_XADD) || insn->imm != 0)) {
verbose("BPF_STX uses reserved fields\n");
return -EINVAL;
}
if (insn[0].code == (BPF_LD | BPF_IMM | BPF_DW)) {
struct bpf_map *map;
struct fd f;
if (i == insn_cnt - 1 || insn[1].code != 0 ||
insn[1].dst_reg != 0 || insn[1].src_reg != 0 ||
insn[1].off != 0) {
verbose("invalid bpf_ld_imm64 insn\n");
return -EINVAL;
}
if (insn->src_reg == 0)
goto next_insn;
if (insn->src_reg != BPF_PSEUDO_MAP_FD) {
verbose("unrecognized bpf_ld_imm64 insn\n");
return -EINVAL;
}
f = fdget(insn->imm);
map = __bpf_map_get(f);
if (IS_ERR(map)) {
verbose("fd %d is not pointing to valid bpf_map\n",
insn->imm);
return PTR_ERR(map);
}
insn[0].imm = (u32) (unsigned long) map;
insn[1].imm = ((u64) (unsigned long) map) >> 32;
for (j = 0; j < env->used_map_cnt; j++)
if (env->used_maps[j] == map) {
fdput(f);
goto next_insn;
}
if (env->used_map_cnt >= MAX_USED_MAPS) {
fdput(f);
return -E2BIG;
}
map = bpf_map_inc(map, false);
if (IS_ERR(map)) {
fdput(f);
return PTR_ERR(map);
}
env->used_maps[env->used_map_cnt++] = map;
fdput(f);
next_insn:
insn++;
i++;
}
}
return 0;
}
static void release_maps(struct verifier_env *env)
{
int i;
for (i = 0; i < env->used_map_cnt; i++)
bpf_map_put(env->used_maps[i]);
}
static void convert_pseudo_ld_imm64(struct verifier_env *env)
{
struct bpf_insn *insn = env->prog->insnsi;
int insn_cnt = env->prog->len;
int i;
for (i = 0; i < insn_cnt; i++, insn++)
if (insn->code == (BPF_LD | BPF_IMM | BPF_DW))
insn->src_reg = 0;
}
static int convert_ctx_accesses(struct verifier_env *env)
{
struct bpf_insn *insn = env->prog->insnsi;
int insn_cnt = env->prog->len;
struct bpf_insn insn_buf[16];
struct bpf_prog *new_prog;
enum bpf_access_type type;
int i;
if (!env->prog->aux->ops->convert_ctx_access)
return 0;
for (i = 0; i < insn_cnt; i++, insn++) {
u32 insn_delta, cnt;
if (insn->code == (BPF_LDX | BPF_MEM | BPF_W))
type = BPF_READ;
else if (insn->code == (BPF_STX | BPF_MEM | BPF_W))
type = BPF_WRITE;
else
continue;
if (insn->imm != PTR_TO_CTX) {
insn->imm = 0;
continue;
}
cnt = env->prog->aux->ops->
convert_ctx_access(type, insn->dst_reg, insn->src_reg,
insn->off, insn_buf, env->prog);
if (cnt == 0 || cnt >= ARRAY_SIZE(insn_buf)) {
verbose("bpf verifier is misconfigured\n");
return -EINVAL;
}
new_prog = bpf_patch_insn_single(env->prog, i, insn_buf, cnt);
if (!new_prog)
return -ENOMEM;
insn_delta = cnt - 1;
env->prog = new_prog;
insn = new_prog->insnsi + i + insn_delta;
insn_cnt += insn_delta;
i += insn_delta;
}
return 0;
}
static void free_states(struct verifier_env *env)
{
struct verifier_state_list *sl, *sln;
int i;
if (!env->explored_states)
return;
for (i = 0; i < env->prog->len; i++) {
sl = env->explored_states[i];
if (sl)
while (sl != STATE_LIST_MARK) {
sln = sl->next;
kfree(sl);
sl = sln;
}
}
kfree(env->explored_states);
}
int bpf_check(struct bpf_prog **prog, union bpf_attr *attr)
{
char __user *log_ubuf = NULL;
struct verifier_env *env;
int ret = -EINVAL;
if ((*prog)->len <= 0 || (*prog)->len > BPF_MAXINSNS)
return -E2BIG;
env = kzalloc(sizeof(struct verifier_env), GFP_KERNEL);
if (!env)
return -ENOMEM;
env->prog = *prog;
mutex_lock(&bpf_verifier_lock);
if (attr->log_level || attr->log_buf || attr->log_size) {
log_level = attr->log_level;
log_ubuf = (char __user *) (unsigned long) attr->log_buf;
log_size = attr->log_size;
log_len = 0;
ret = -EINVAL;
if (log_size < 128 || log_size > UINT_MAX >> 8 ||
log_level == 0 || log_ubuf == NULL)
goto free_env;
ret = -ENOMEM;
log_buf = vmalloc(log_size);
if (!log_buf)
goto free_env;
} else {
log_level = 0;
}
ret = replace_map_fd_with_map_ptr(env);
if (ret < 0)
goto skip_full_check;
env->explored_states = kcalloc(env->prog->len,
sizeof(struct verifier_state_list *),
GFP_USER);
ret = -ENOMEM;
if (!env->explored_states)
goto skip_full_check;
ret = check_cfg(env);
if (ret < 0)
goto skip_full_check;
env->allow_ptr_leaks = capable(CAP_SYS_ADMIN);
ret = do_check(env);
skip_full_check:
while (pop_stack(env, NULL) >= 0);
free_states(env);
if (ret == 0)
ret = convert_ctx_accesses(env);
if (log_level && log_len >= log_size - 1) {
BUG_ON(log_len >= log_size);
ret = -ENOSPC;
}
if (log_level && copy_to_user(log_ubuf, log_buf, log_len + 1) != 0) {
ret = -EFAULT;
goto free_log_buf;
}
if (ret == 0 && env->used_map_cnt) {
env->prog->aux->used_maps = kmalloc_array(env->used_map_cnt,
sizeof(env->used_maps[0]),
GFP_KERNEL);
if (!env->prog->aux->used_maps) {
ret = -ENOMEM;
goto free_log_buf;
}
memcpy(env->prog->aux->used_maps, env->used_maps,
sizeof(env->used_maps[0]) * env->used_map_cnt);
env->prog->aux->used_map_cnt = env->used_map_cnt;
convert_pseudo_ld_imm64(env);
}
free_log_buf:
if (log_level)
vfree(log_buf);
free_env:
if (!env->prog->aux->used_maps)
release_maps(env);
*prog = env->prog;
kfree(env);
mutex_unlock(&bpf_verifier_lock);
return ret;
}
