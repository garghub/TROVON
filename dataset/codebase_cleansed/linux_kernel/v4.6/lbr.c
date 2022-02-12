static void __intel_pmu_lbr_enable(bool pmi)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
u64 debugctl, lbr_select = 0, orig_debugctl;
if (pmi && x86_pmu.version >= 4)
return;
if (cpuc->lbr_sel)
lbr_select = cpuc->lbr_sel->config & x86_pmu.lbr_sel_mask;
if (!pmi && cpuc->lbr_sel)
wrmsrl(MSR_LBR_SELECT, lbr_select);
rdmsrl(MSR_IA32_DEBUGCTLMSR, debugctl);
orig_debugctl = debugctl;
debugctl |= DEBUGCTLMSR_LBR;
if (!(lbr_select & LBR_CALL_STACK))
debugctl |= DEBUGCTLMSR_FREEZE_LBRS_ON_PMI;
if (orig_debugctl != debugctl)
wrmsrl(MSR_IA32_DEBUGCTLMSR, debugctl);
}
static void __intel_pmu_lbr_disable(void)
{
u64 debugctl;
rdmsrl(MSR_IA32_DEBUGCTLMSR, debugctl);
debugctl &= ~(DEBUGCTLMSR_LBR | DEBUGCTLMSR_FREEZE_LBRS_ON_PMI);
wrmsrl(MSR_IA32_DEBUGCTLMSR, debugctl);
}
static void intel_pmu_lbr_reset_32(void)
{
int i;
for (i = 0; i < x86_pmu.lbr_nr; i++)
wrmsrl(x86_pmu.lbr_from + i, 0);
}
static void intel_pmu_lbr_reset_64(void)
{
int i;
for (i = 0; i < x86_pmu.lbr_nr; i++) {
wrmsrl(x86_pmu.lbr_from + i, 0);
wrmsrl(x86_pmu.lbr_to + i, 0);
if (x86_pmu.intel_cap.lbr_format == LBR_FORMAT_INFO)
wrmsrl(MSR_LBR_INFO_0 + i, 0);
}
}
void intel_pmu_lbr_reset(void)
{
if (!x86_pmu.lbr_nr)
return;
if (x86_pmu.intel_cap.lbr_format == LBR_FORMAT_32)
intel_pmu_lbr_reset_32();
else
intel_pmu_lbr_reset_64();
}
static inline u64 intel_pmu_lbr_tos(void)
{
u64 tos;
rdmsrl(x86_pmu.lbr_tos, tos);
return tos;
}
static void __intel_pmu_lbr_restore(struct x86_perf_task_context *task_ctx)
{
int i;
unsigned lbr_idx, mask;
u64 tos;
if (task_ctx->lbr_callstack_users == 0 ||
task_ctx->lbr_stack_state == LBR_NONE) {
intel_pmu_lbr_reset();
return;
}
mask = x86_pmu.lbr_nr - 1;
tos = task_ctx->tos;
for (i = 0; i < tos; i++) {
lbr_idx = (tos - i) & mask;
wrmsrl(x86_pmu.lbr_from + lbr_idx, task_ctx->lbr_from[i]);
wrmsrl(x86_pmu.lbr_to + lbr_idx, task_ctx->lbr_to[i]);
if (x86_pmu.intel_cap.lbr_format == LBR_FORMAT_INFO)
wrmsrl(MSR_LBR_INFO_0 + lbr_idx, task_ctx->lbr_info[i]);
}
wrmsrl(x86_pmu.lbr_tos, tos);
task_ctx->lbr_stack_state = LBR_NONE;
}
static void __intel_pmu_lbr_save(struct x86_perf_task_context *task_ctx)
{
int i;
unsigned lbr_idx, mask;
u64 tos;
if (task_ctx->lbr_callstack_users == 0) {
task_ctx->lbr_stack_state = LBR_NONE;
return;
}
mask = x86_pmu.lbr_nr - 1;
tos = intel_pmu_lbr_tos();
for (i = 0; i < tos; i++) {
lbr_idx = (tos - i) & mask;
rdmsrl(x86_pmu.lbr_from + lbr_idx, task_ctx->lbr_from[i]);
rdmsrl(x86_pmu.lbr_to + lbr_idx, task_ctx->lbr_to[i]);
if (x86_pmu.intel_cap.lbr_format == LBR_FORMAT_INFO)
rdmsrl(MSR_LBR_INFO_0 + lbr_idx, task_ctx->lbr_info[i]);
}
task_ctx->tos = tos;
task_ctx->lbr_stack_state = LBR_VALID;
}
void intel_pmu_lbr_sched_task(struct perf_event_context *ctx, bool sched_in)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct x86_perf_task_context *task_ctx;
task_ctx = ctx ? ctx->task_ctx_data : NULL;
if (task_ctx) {
if (sched_in) {
__intel_pmu_lbr_restore(task_ctx);
cpuc->lbr_context = ctx;
} else {
__intel_pmu_lbr_save(task_ctx);
}
return;
}
if (sched_in) {
intel_pmu_lbr_reset();
cpuc->lbr_context = ctx;
}
}
static inline bool branch_user_callstack(unsigned br_sel)
{
return (br_sel & X86_BR_USER) && (br_sel & X86_BR_CALL_STACK);
}
void intel_pmu_lbr_enable(struct perf_event *event)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct x86_perf_task_context *task_ctx;
if (!x86_pmu.lbr_nr)
return;
if (event->ctx->task && cpuc->lbr_context != event->ctx) {
intel_pmu_lbr_reset();
cpuc->lbr_context = event->ctx;
}
cpuc->br_sel = event->hw.branch_reg.reg;
if (branch_user_callstack(cpuc->br_sel) && event->ctx &&
event->ctx->task_ctx_data) {
task_ctx = event->ctx->task_ctx_data;
task_ctx->lbr_callstack_users++;
}
cpuc->lbr_users++;
perf_sched_cb_inc(event->ctx->pmu);
}
void intel_pmu_lbr_disable(struct perf_event *event)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct x86_perf_task_context *task_ctx;
if (!x86_pmu.lbr_nr)
return;
if (branch_user_callstack(cpuc->br_sel) && event->ctx &&
event->ctx->task_ctx_data) {
task_ctx = event->ctx->task_ctx_data;
task_ctx->lbr_callstack_users--;
}
cpuc->lbr_users--;
WARN_ON_ONCE(cpuc->lbr_users < 0);
perf_sched_cb_dec(event->ctx->pmu);
if (cpuc->enabled && !cpuc->lbr_users) {
__intel_pmu_lbr_disable();
cpuc->lbr_context = NULL;
}
}
void intel_pmu_lbr_enable_all(bool pmi)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
if (cpuc->lbr_users)
__intel_pmu_lbr_enable(pmi);
}
void intel_pmu_lbr_disable_all(void)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
if (cpuc->lbr_users)
__intel_pmu_lbr_disable();
}
static void intel_pmu_lbr_read_32(struct cpu_hw_events *cpuc)
{
unsigned long mask = x86_pmu.lbr_nr - 1;
u64 tos = intel_pmu_lbr_tos();
int i;
for (i = 0; i < x86_pmu.lbr_nr; i++) {
unsigned long lbr_idx = (tos - i) & mask;
union {
struct {
u32 from;
u32 to;
};
u64 lbr;
} msr_lastbranch;
rdmsrl(x86_pmu.lbr_from + lbr_idx, msr_lastbranch.lbr);
cpuc->lbr_entries[i].from = msr_lastbranch.from;
cpuc->lbr_entries[i].to = msr_lastbranch.to;
cpuc->lbr_entries[i].mispred = 0;
cpuc->lbr_entries[i].predicted = 0;
cpuc->lbr_entries[i].reserved = 0;
}
cpuc->lbr_stack.nr = i;
}
static void intel_pmu_lbr_read_64(struct cpu_hw_events *cpuc)
{
bool need_info = false;
unsigned long mask = x86_pmu.lbr_nr - 1;
int lbr_format = x86_pmu.intel_cap.lbr_format;
u64 tos = intel_pmu_lbr_tos();
int i;
int out = 0;
int num = x86_pmu.lbr_nr;
if (cpuc->lbr_sel) {
need_info = !(cpuc->lbr_sel->config & LBR_NO_INFO);
if (cpuc->lbr_sel->config & LBR_CALL_STACK)
num = tos;
}
for (i = 0; i < num; i++) {
unsigned long lbr_idx = (tos - i) & mask;
u64 from, to, mis = 0, pred = 0, in_tx = 0, abort = 0;
int skip = 0;
u16 cycles = 0;
int lbr_flags = lbr_desc[lbr_format];
rdmsrl(x86_pmu.lbr_from + lbr_idx, from);
rdmsrl(x86_pmu.lbr_to + lbr_idx, to);
if (lbr_format == LBR_FORMAT_INFO && need_info) {
u64 info;
rdmsrl(MSR_LBR_INFO_0 + lbr_idx, info);
mis = !!(info & LBR_INFO_MISPRED);
pred = !mis;
in_tx = !!(info & LBR_INFO_IN_TX);
abort = !!(info & LBR_INFO_ABORT);
cycles = (info & LBR_INFO_CYCLES);
}
if (lbr_flags & LBR_EIP_FLAGS) {
mis = !!(from & LBR_FROM_FLAG_MISPRED);
pred = !mis;
skip = 1;
}
if (lbr_flags & LBR_TSX) {
in_tx = !!(from & LBR_FROM_FLAG_IN_TX);
abort = !!(from & LBR_FROM_FLAG_ABORT);
skip = 3;
}
from = (u64)((((s64)from) << skip) >> skip);
if (abort && x86_pmu.lbr_double_abort && out > 0)
out--;
cpuc->lbr_entries[out].from = from;
cpuc->lbr_entries[out].to = to;
cpuc->lbr_entries[out].mispred = mis;
cpuc->lbr_entries[out].predicted = pred;
cpuc->lbr_entries[out].in_tx = in_tx;
cpuc->lbr_entries[out].abort = abort;
cpuc->lbr_entries[out].cycles = cycles;
cpuc->lbr_entries[out].reserved = 0;
out++;
}
cpuc->lbr_stack.nr = out;
}
void intel_pmu_lbr_read(void)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
if (!cpuc->lbr_users)
return;
if (x86_pmu.intel_cap.lbr_format == LBR_FORMAT_32)
intel_pmu_lbr_read_32(cpuc);
else
intel_pmu_lbr_read_64(cpuc);
intel_pmu_lbr_filter(cpuc);
}
static int intel_pmu_setup_sw_lbr_filter(struct perf_event *event)
{
u64 br_type = event->attr.branch_sample_type;
int mask = 0;
if (br_type & PERF_SAMPLE_BRANCH_USER)
mask |= X86_BR_USER;
if (br_type & PERF_SAMPLE_BRANCH_KERNEL)
mask |= X86_BR_KERNEL;
if (br_type & PERF_SAMPLE_BRANCH_ANY)
mask |= X86_BR_ANY;
if (br_type & PERF_SAMPLE_BRANCH_ANY_CALL)
mask |= X86_BR_ANY_CALL;
if (br_type & PERF_SAMPLE_BRANCH_ANY_RETURN)
mask |= X86_BR_RET | X86_BR_IRET | X86_BR_SYSRET;
if (br_type & PERF_SAMPLE_BRANCH_IND_CALL)
mask |= X86_BR_IND_CALL;
if (br_type & PERF_SAMPLE_BRANCH_ABORT_TX)
mask |= X86_BR_ABORT;
if (br_type & PERF_SAMPLE_BRANCH_IN_TX)
mask |= X86_BR_IN_TX;
if (br_type & PERF_SAMPLE_BRANCH_NO_TX)
mask |= X86_BR_NO_TX;
if (br_type & PERF_SAMPLE_BRANCH_COND)
mask |= X86_BR_JCC;
if (br_type & PERF_SAMPLE_BRANCH_CALL_STACK) {
if (!x86_pmu_has_lbr_callstack())
return -EOPNOTSUPP;
if (mask & ~(X86_BR_USER | X86_BR_KERNEL))
return -EINVAL;
mask |= X86_BR_CALL | X86_BR_IND_CALL | X86_BR_RET |
X86_BR_CALL_STACK;
}
if (br_type & PERF_SAMPLE_BRANCH_IND_JUMP)
mask |= X86_BR_IND_JMP;
if (br_type & PERF_SAMPLE_BRANCH_CALL)
mask |= X86_BR_CALL | X86_BR_ZERO_CALL;
event->hw.branch_reg.reg = mask;
return 0;
}
static int intel_pmu_setup_hw_lbr_filter(struct perf_event *event)
{
struct hw_perf_event_extra *reg;
u64 br_type = event->attr.branch_sample_type;
u64 mask = 0, v;
int i;
for (i = 0; i < PERF_SAMPLE_BRANCH_MAX_SHIFT; i++) {
if (!(br_type & (1ULL << i)))
continue;
v = x86_pmu.lbr_sel_map[i];
if (v == LBR_NOT_SUPP)
return -EOPNOTSUPP;
if (v != LBR_IGN)
mask |= v;
}
reg = &event->hw.branch_reg;
reg->idx = EXTRA_REG_LBR;
reg->config = mask ^ (x86_pmu.lbr_sel_mask & ~LBR_CALL_STACK);
if ((br_type & PERF_SAMPLE_BRANCH_NO_CYCLES) &&
(br_type & PERF_SAMPLE_BRANCH_NO_FLAGS) &&
(x86_pmu.intel_cap.lbr_format == LBR_FORMAT_INFO))
reg->config |= LBR_NO_INFO;
return 0;
}
int intel_pmu_setup_lbr_filter(struct perf_event *event)
{
int ret = 0;
if (!x86_pmu.lbr_nr)
return -EOPNOTSUPP;
ret = intel_pmu_setup_sw_lbr_filter(event);
if (ret)
return ret;
if (x86_pmu.lbr_sel_map)
ret = intel_pmu_setup_hw_lbr_filter(event);
return ret;
}
static int branch_type(unsigned long from, unsigned long to, int abort)
{
struct insn insn;
void *addr;
int bytes_read, bytes_left;
int ret = X86_BR_NONE;
int ext, to_plm, from_plm;
u8 buf[MAX_INSN_SIZE];
int is64 = 0;
to_plm = kernel_ip(to) ? X86_BR_KERNEL : X86_BR_USER;
from_plm = kernel_ip(from) ? X86_BR_KERNEL : X86_BR_USER;
if (from == 0 || to == 0)
return X86_BR_NONE;
if (abort)
return X86_BR_ABORT | to_plm;
if (from_plm == X86_BR_USER) {
if (!current->mm)
return X86_BR_NONE;
bytes_left = copy_from_user_nmi(buf, (void __user *)from,
MAX_INSN_SIZE);
bytes_read = MAX_INSN_SIZE - bytes_left;
if (!bytes_read)
return X86_BR_NONE;
addr = buf;
} else {
if (kernel_text_address(from)) {
addr = (void *)from;
bytes_read = MAX_INSN_SIZE;
} else {
return X86_BR_NONE;
}
}
#ifdef CONFIG_X86_64
is64 = kernel_ip((unsigned long)addr) || !test_thread_flag(TIF_IA32);
#endif
insn_init(&insn, addr, bytes_read, is64);
insn_get_opcode(&insn);
if (!insn.opcode.got)
return X86_BR_ABORT;
switch (insn.opcode.bytes[0]) {
case 0xf:
switch (insn.opcode.bytes[1]) {
case 0x05:
case 0x34:
ret = X86_BR_SYSCALL;
break;
case 0x07:
case 0x35:
ret = X86_BR_SYSRET;
break;
case 0x80 ... 0x8f:
ret = X86_BR_JCC;
break;
default:
ret = X86_BR_NONE;
}
break;
case 0x70 ... 0x7f:
ret = X86_BR_JCC;
break;
case 0xc2:
case 0xc3:
case 0xca:
case 0xcb:
ret = X86_BR_RET;
break;
case 0xcf:
ret = X86_BR_IRET;
break;
case 0xcc ... 0xce:
ret = X86_BR_INT;
break;
case 0xe8:
insn_get_immediate(&insn);
if (insn.immediate1.value == 0) {
ret = X86_BR_ZERO_CALL;
break;
}
case 0x9a:
ret = X86_BR_CALL;
break;
case 0xe0 ... 0xe3:
ret = X86_BR_JCC;
break;
case 0xe9 ... 0xeb:
ret = X86_BR_JMP;
break;
case 0xff:
insn_get_modrm(&insn);
ext = (insn.modrm.bytes[0] >> 3) & 0x7;
switch (ext) {
case 2:
case 3:
ret = X86_BR_IND_CALL;
break;
case 4:
case 5:
ret = X86_BR_IND_JMP;
break;
}
break;
default:
ret = X86_BR_NONE;
}
if (from_plm == X86_BR_USER && to_plm == X86_BR_KERNEL
&& ret != X86_BR_SYSCALL && ret != X86_BR_INT)
ret = X86_BR_IRQ;
if (ret != X86_BR_NONE)
ret |= to_plm;
return ret;
}
static void
intel_pmu_lbr_filter(struct cpu_hw_events *cpuc)
{
u64 from, to;
int br_sel = cpuc->br_sel;
int i, j, type;
bool compress = false;
if ((br_sel & X86_BR_ALL) == X86_BR_ALL)
return;
for (i = 0; i < cpuc->lbr_stack.nr; i++) {
from = cpuc->lbr_entries[i].from;
to = cpuc->lbr_entries[i].to;
type = branch_type(from, to, cpuc->lbr_entries[i].abort);
if (type != X86_BR_NONE && (br_sel & X86_BR_ANYTX)) {
if (cpuc->lbr_entries[i].in_tx)
type |= X86_BR_IN_TX;
else
type |= X86_BR_NO_TX;
}
if (type == X86_BR_NONE || (br_sel & type) != type) {
cpuc->lbr_entries[i].from = 0;
compress = true;
}
}
if (!compress)
return;
for (i = 0; i < cpuc->lbr_stack.nr; ) {
if (!cpuc->lbr_entries[i].from) {
j = i;
while (++j < cpuc->lbr_stack.nr)
cpuc->lbr_entries[j-1] = cpuc->lbr_entries[j];
cpuc->lbr_stack.nr--;
if (!cpuc->lbr_entries[i].from)
continue;
}
i++;
}
}
void __init intel_pmu_lbr_init_core(void)
{
x86_pmu.lbr_nr = 4;
x86_pmu.lbr_tos = MSR_LBR_TOS;
x86_pmu.lbr_from = MSR_LBR_CORE_FROM;
x86_pmu.lbr_to = MSR_LBR_CORE_TO;
pr_cont("4-deep LBR, ");
}
void __init intel_pmu_lbr_init_nhm(void)
{
x86_pmu.lbr_nr = 16;
x86_pmu.lbr_tos = MSR_LBR_TOS;
x86_pmu.lbr_from = MSR_LBR_NHM_FROM;
x86_pmu.lbr_to = MSR_LBR_NHM_TO;
x86_pmu.lbr_sel_mask = LBR_SEL_MASK;
x86_pmu.lbr_sel_map = nhm_lbr_sel_map;
pr_cont("16-deep LBR, ");
}
void __init intel_pmu_lbr_init_snb(void)
{
x86_pmu.lbr_nr = 16;
x86_pmu.lbr_tos = MSR_LBR_TOS;
x86_pmu.lbr_from = MSR_LBR_NHM_FROM;
x86_pmu.lbr_to = MSR_LBR_NHM_TO;
x86_pmu.lbr_sel_mask = LBR_SEL_MASK;
x86_pmu.lbr_sel_map = snb_lbr_sel_map;
pr_cont("16-deep LBR, ");
}
void intel_pmu_lbr_init_hsw(void)
{
x86_pmu.lbr_nr = 16;
x86_pmu.lbr_tos = MSR_LBR_TOS;
x86_pmu.lbr_from = MSR_LBR_NHM_FROM;
x86_pmu.lbr_to = MSR_LBR_NHM_TO;
x86_pmu.lbr_sel_mask = LBR_SEL_MASK;
x86_pmu.lbr_sel_map = hsw_lbr_sel_map;
pr_cont("16-deep LBR, ");
}
__init void intel_pmu_lbr_init_skl(void)
{
x86_pmu.lbr_nr = 32;
x86_pmu.lbr_tos = MSR_LBR_TOS;
x86_pmu.lbr_from = MSR_LBR_NHM_FROM;
x86_pmu.lbr_to = MSR_LBR_NHM_TO;
x86_pmu.lbr_sel_mask = LBR_SEL_MASK;
x86_pmu.lbr_sel_map = hsw_lbr_sel_map;
pr_cont("32-deep LBR, ");
}
void __init intel_pmu_lbr_init_atom(void)
{
if (boot_cpu_data.x86_model == 28
&& boot_cpu_data.x86_mask < 10) {
pr_cont("LBR disabled due to erratum");
return;
}
x86_pmu.lbr_nr = 8;
x86_pmu.lbr_tos = MSR_LBR_TOS;
x86_pmu.lbr_from = MSR_LBR_CORE_FROM;
x86_pmu.lbr_to = MSR_LBR_CORE_TO;
pr_cont("8-deep LBR, ");
}
void intel_pmu_lbr_init_knl(void)
{
x86_pmu.lbr_nr = 8;
x86_pmu.lbr_tos = MSR_LBR_TOS;
x86_pmu.lbr_from = MSR_LBR_NHM_FROM;
x86_pmu.lbr_to = MSR_LBR_NHM_TO;
x86_pmu.lbr_sel_mask = LBR_SEL_MASK;
x86_pmu.lbr_sel_map = snb_lbr_sel_map;
pr_cont("8-deep LBR, ");
}
