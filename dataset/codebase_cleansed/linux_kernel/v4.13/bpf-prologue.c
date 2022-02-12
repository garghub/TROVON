static inline int
pos_get_cnt(struct bpf_insn_pos *pos)
{
return pos->pos - pos->begin;
}
static int
append_insn(struct bpf_insn new_insn, struct bpf_insn_pos *pos)
{
if (!pos->pos)
return -BPF_LOADER_ERRNO__PROLOGUE2BIG;
if (pos->pos + 1 >= pos->end) {
pr_err("bpf prologue: prologue too long\n");
pos->pos = NULL;
return -BPF_LOADER_ERRNO__PROLOGUE2BIG;
}
*(pos->pos)++ = new_insn;
return 0;
}
static int
check_pos(struct bpf_insn_pos *pos)
{
if (!pos->pos || pos->pos >= pos->end)
return -BPF_LOADER_ERRNO__PROLOGUE2BIG;
return 0;
}
static int
gen_ldx_reg_from_ctx(struct bpf_insn_pos *pos, int ctx_reg,
const char *reg, int target_reg)
{
int offset = regs_query_register_offset(reg);
if (offset < 0) {
pr_err("bpf: prologue: failed to get register %s\n",
reg);
return offset;
}
ins(BPF_LDX_MEM(BPF_DW, target_reg, ctx_reg, offset), pos);
return check_pos(pos);
}
static int
gen_read_mem(struct bpf_insn_pos *pos,
int src_base_addr_reg,
int dst_addr_reg,
long offset)
{
if (src_base_addr_reg != BPF_REG_ARG3)
ins(BPF_MOV64_REG(BPF_REG_ARG3, src_base_addr_reg), pos);
if (offset)
ins(BPF_ALU64_IMM(BPF_ADD, BPF_REG_ARG3, offset), pos);
ins(BPF_ALU64_IMM(BPF_MOV, BPF_REG_ARG2, BPF_REG_SIZE), pos);
if (dst_addr_reg != BPF_REG_ARG1)
ins(BPF_MOV64_REG(BPF_REG_ARG1, dst_addr_reg), pos);
ins(BPF_EMIT_CALL(BPF_FUNC_probe_read), pos);
ins(BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 0, JMP_TO_ERROR_CODE),
pos);
return check_pos(pos);
}
static int
gen_prologue_fastpath(struct bpf_insn_pos *pos,
struct probe_trace_arg *args, int nargs)
{
int i, err = 0;
for (i = 0; i < nargs; i++) {
err = gen_ldx_reg_from_ctx(pos, BPF_REG_1, args[i].value,
BPF_PROLOGUE_START_ARG_REG + i);
if (err)
goto errout;
}
return check_pos(pos);
errout:
return err;
}
static int
gen_prologue_slowpath(struct bpf_insn_pos *pos,
struct probe_trace_arg *args, int nargs)
{
int err, i;
for (i = 0; i < nargs; i++) {
struct probe_trace_arg *arg = &args[i];
const char *reg = arg->value;
struct probe_trace_arg_ref *ref = NULL;
int stack_offset = (i + 1) * -8;
pr_debug("prologue: fetch arg %d, base reg is %s\n",
i, reg);
err = gen_ldx_reg_from_ctx(pos, BPF_REG_CTX, reg,
BPF_REG_ARG3);
if (err) {
pr_err("prologue: failed to get offset of register %s\n",
reg);
goto errout;
}
ins(BPF_MOV64_REG(BPF_REG_7, BPF_REG_FP), pos);
ins(BPF_ALU64_IMM(BPF_ADD, BPF_REG_7, stack_offset), pos);
ins(BPF_STX_MEM(BPF_DW, BPF_REG_FP, BPF_REG_ARG3,
stack_offset), pos);
ref = arg->ref;
while (ref) {
pr_debug("prologue: arg %d: offset %ld\n",
i, ref->offset);
err = gen_read_mem(pos, BPF_REG_3, BPF_REG_7,
ref->offset);
if (err) {
pr_err("prologue: failed to generate probe_read function call\n");
goto errout;
}
ref = ref->next;
if (ref)
ins(BPF_LDX_MEM(BPF_DW, BPF_REG_ARG3,
BPF_REG_FP, stack_offset), pos);
}
}
for (i = 0; i < nargs; i++)
ins(BPF_LDX_MEM(BPF_DW, BPF_PROLOGUE_START_ARG_REG + i,
BPF_REG_FP, -BPF_REG_SIZE * (i + 1)), pos);
ins(BPF_JMP_IMM(BPF_JA, BPF_REG_0, 0, JMP_TO_SUCCESS_CODE), pos);
return check_pos(pos);
errout:
return err;
}
static int
prologue_relocate(struct bpf_insn_pos *pos, struct bpf_insn *error_code,
struct bpf_insn *success_code, struct bpf_insn *user_code)
{
struct bpf_insn *insn;
if (check_pos(pos))
return -BPF_LOADER_ERRNO__PROLOGUE2BIG;
for (insn = pos->begin; insn < pos->pos; insn++) {
struct bpf_insn *target;
u8 class = BPF_CLASS(insn->code);
u8 opcode;
if (class != BPF_JMP)
continue;
opcode = BPF_OP(insn->code);
if (opcode == BPF_CALL)
continue;
switch (insn->off) {
case JMP_TO_ERROR_CODE:
target = error_code;
break;
case JMP_TO_SUCCESS_CODE:
target = success_code;
break;
case JMP_TO_USER_CODE:
target = user_code;
break;
default:
pr_err("bpf prologue: internal error: relocation failed\n");
return -BPF_LOADER_ERRNO__PROLOGUE;
}
insn->off = target - (insn + 1);
}
return 0;
}
int bpf__gen_prologue(struct probe_trace_arg *args, int nargs,
struct bpf_insn *new_prog, size_t *new_cnt,
size_t cnt_space)
{
struct bpf_insn *success_code = NULL;
struct bpf_insn *error_code = NULL;
struct bpf_insn *user_code = NULL;
struct bpf_insn_pos pos;
bool fastpath = true;
int err = 0, i;
if (!new_prog || !new_cnt)
return -EINVAL;
if (cnt_space > BPF_MAXINSNS)
cnt_space = BPF_MAXINSNS;
pos.begin = new_prog;
pos.end = new_prog + cnt_space;
pos.pos = new_prog;
if (!nargs) {
ins(BPF_ALU64_IMM(BPF_MOV, BPF_PROLOGUE_FETCH_RESULT_REG, 0),
&pos);
if (check_pos(&pos))
goto errout;
*new_cnt = pos_get_cnt(&pos);
return 0;
}
if (nargs > BPF_PROLOGUE_MAX_ARGS) {
pr_warning("bpf: prologue: %d arguments are dropped\n",
nargs - BPF_PROLOGUE_MAX_ARGS);
nargs = BPF_PROLOGUE_MAX_ARGS;
}
for (i = 0; i < nargs; i++) {
struct probe_trace_arg_ref *ref = args[i].ref;
if (args[i].value[0] == '@') {
pr_err("bpf: prologue: global %s%+ld not support\n",
args[i].value, ref ? ref->offset : 0);
return -ENOTSUP;
}
while (ref) {
fastpath = false;
#ifdef __LP64__
#define OFFSET_MAX ((1LL << 31) - 1)
#define OFFSET_MIN ((1LL << 31) * -1)
if (ref->offset > OFFSET_MAX ||
ref->offset < OFFSET_MIN) {
pr_err("bpf: prologue: offset out of bound: %ld\n",
ref->offset);
return -BPF_LOADER_ERRNO__PROLOGUEOOB;
}
#endif
ref = ref->next;
}
}
pr_debug("prologue: pass validation\n");
if (fastpath) {
pr_debug("prologue: fast path\n");
err = gen_prologue_fastpath(&pos, args, nargs);
if (err)
goto errout;
} else {
pr_debug("prologue: slow path\n");
ins(BPF_MOV64_REG(BPF_REG_CTX, BPF_REG_ARG1), &pos);
err = gen_prologue_slowpath(&pos, args, nargs);
if (err)
goto errout;
error_code = pos.pos;
ins(BPF_ALU64_IMM(BPF_MOV, BPF_PROLOGUE_FETCH_RESULT_REG, 1),
&pos);
for (i = 0; i < nargs; i++)
ins(BPF_ALU64_IMM(BPF_MOV,
BPF_PROLOGUE_START_ARG_REG + i,
0),
&pos);
ins(BPF_JMP_IMM(BPF_JA, BPF_REG_0, 0, JMP_TO_USER_CODE),
&pos);
}
success_code = pos.pos;
ins(BPF_ALU64_IMM(BPF_MOV, BPF_PROLOGUE_FETCH_RESULT_REG, 0), &pos);
user_code = pos.pos;
if (!fastpath) {
ins(BPF_MOV64_REG(BPF_REG_ARG1, BPF_REG_CTX), &pos);
err = prologue_relocate(&pos, error_code, success_code,
user_code);
if (err)
goto errout;
}
err = check_pos(&pos);
if (err)
goto errout;
*new_cnt = pos_get_cnt(&pos);
return 0;
errout:
return err;
}
