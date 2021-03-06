static inline unsigned long orc_ip(const int *ip)
{
return (unsigned long)ip + *ip;
}
static struct orc_entry *__orc_find(int *ip_table, struct orc_entry *u_table,
unsigned int num_entries, unsigned long ip)
{
int *first = ip_table;
int *last = ip_table + num_entries - 1;
int *mid = first, *found = first;
if (!num_entries)
return NULL;
while (first <= last) {
mid = first + ((last - first) / 2);
if (orc_ip(mid) <= ip) {
found = mid;
first = mid + 1;
} else
last = mid - 1;
}
return u_table + (found - ip_table);
}
static struct orc_entry *orc_module_find(unsigned long ip)
{
struct module *mod;
mod = __module_address(ip);
if (!mod || !mod->arch.orc_unwind || !mod->arch.orc_unwind_ip)
return NULL;
return __orc_find(mod->arch.orc_unwind_ip, mod->arch.orc_unwind,
mod->arch.num_orcs, ip);
}
static struct orc_entry *orc_module_find(unsigned long ip)
{
return NULL;
}
static struct orc_entry *orc_find(unsigned long ip)
{
if (!orc_init)
return NULL;
if (ip >= LOOKUP_START_IP && ip < LOOKUP_STOP_IP) {
unsigned int idx, start, stop;
idx = (ip - LOOKUP_START_IP) / LOOKUP_BLOCK_SIZE;
if (unlikely((idx >= lookup_num_blocks-1))) {
orc_warn("WARNING: bad lookup idx: idx=%u num=%u ip=%pB\n",
idx, lookup_num_blocks, (void *)ip);
return NULL;
}
start = orc_lookup[idx];
stop = orc_lookup[idx + 1] + 1;
if (unlikely((__start_orc_unwind + start >= __stop_orc_unwind) ||
(__start_orc_unwind + stop > __stop_orc_unwind))) {
orc_warn("WARNING: bad lookup value: idx=%u num=%u start=%u stop=%u ip=%pB\n",
idx, lookup_num_blocks, start, stop, (void *)ip);
return NULL;
}
return __orc_find(__start_orc_unwind_ip + start,
__start_orc_unwind + start, stop - start, ip);
}
if (ip >= (unsigned long)_sinittext && ip < (unsigned long)_einittext)
return __orc_find(__start_orc_unwind_ip, __start_orc_unwind,
__stop_orc_unwind_ip - __start_orc_unwind_ip, ip);
return orc_module_find(ip);
}
static void orc_sort_swap(void *_a, void *_b, int size)
{
struct orc_entry *orc_a, *orc_b;
struct orc_entry orc_tmp;
int *a = _a, *b = _b, tmp;
int delta = _b - _a;
tmp = *a;
*a = *b + delta;
*b = tmp - delta;
orc_a = cur_orc_table + (a - cur_orc_ip_table);
orc_b = cur_orc_table + (b - cur_orc_ip_table);
orc_tmp = *orc_a;
*orc_a = *orc_b;
*orc_b = orc_tmp;
}
static int orc_sort_cmp(const void *_a, const void *_b)
{
struct orc_entry *orc_a;
const int *a = _a, *b = _b;
unsigned long a_val = orc_ip(a);
unsigned long b_val = orc_ip(b);
if (a_val > b_val)
return 1;
if (a_val < b_val)
return -1;
orc_a = cur_orc_table + (a - cur_orc_ip_table);
return orc_a->sp_reg == ORC_REG_UNDEFINED ? -1 : 1;
}
void unwind_module_init(struct module *mod, void *_orc_ip, size_t orc_ip_size,
void *_orc, size_t orc_size)
{
int *orc_ip = _orc_ip;
struct orc_entry *orc = _orc;
unsigned int num_entries = orc_ip_size / sizeof(int);
WARN_ON_ONCE(orc_ip_size % sizeof(int) != 0 ||
orc_size % sizeof(*orc) != 0 ||
num_entries != orc_size / sizeof(*orc));
mutex_lock(&sort_mutex);
cur_orc_ip_table = orc_ip;
cur_orc_table = orc;
sort(orc_ip, num_entries, sizeof(int), orc_sort_cmp, orc_sort_swap);
mutex_unlock(&sort_mutex);
mod->arch.orc_unwind_ip = orc_ip;
mod->arch.orc_unwind = orc;
mod->arch.num_orcs = num_entries;
}
void __init unwind_init(void)
{
size_t orc_ip_size = (void *)__stop_orc_unwind_ip - (void *)__start_orc_unwind_ip;
size_t orc_size = (void *)__stop_orc_unwind - (void *)__start_orc_unwind;
size_t num_entries = orc_ip_size / sizeof(int);
struct orc_entry *orc;
int i;
if (!num_entries || orc_ip_size % sizeof(int) != 0 ||
orc_size % sizeof(struct orc_entry) != 0 ||
num_entries != orc_size / sizeof(struct orc_entry)) {
orc_warn("WARNING: Bad or missing .orc_unwind table. Disabling unwinder.\n");
return;
}
sort(__start_orc_unwind_ip, num_entries, sizeof(int), orc_sort_cmp,
orc_sort_swap);
lookup_num_blocks = orc_lookup_end - orc_lookup;
for (i = 0; i < lookup_num_blocks-1; i++) {
orc = __orc_find(__start_orc_unwind_ip, __start_orc_unwind,
num_entries,
LOOKUP_START_IP + (LOOKUP_BLOCK_SIZE * i));
if (!orc) {
orc_warn("WARNING: Corrupt .orc_unwind table. Disabling unwinder.\n");
return;
}
orc_lookup[i] = orc - __start_orc_unwind;
}
orc = __orc_find(__start_orc_unwind_ip, __start_orc_unwind, num_entries,
LOOKUP_STOP_IP);
if (!orc) {
orc_warn("WARNING: Corrupt .orc_unwind table. Disabling unwinder.\n");
return;
}
orc_lookup[lookup_num_blocks-1] = orc - __start_orc_unwind;
orc_init = true;
}
unsigned long unwind_get_return_address(struct unwind_state *state)
{
if (unwind_done(state))
return 0;
return __kernel_text_address(state->ip) ? state->ip : 0;
}
unsigned long *unwind_get_return_address_ptr(struct unwind_state *state)
{
if (unwind_done(state))
return NULL;
if (state->regs)
return &state->regs->ip;
if (state->sp)
return (unsigned long *)state->sp - 1;
return NULL;
}
static bool stack_access_ok(struct unwind_state *state, unsigned long addr,
size_t len)
{
struct stack_info *info = &state->stack_info;
while (!on_stack(info, (void *)addr, len))
if (get_stack_info(info->next_sp, state->task, info,
&state->stack_mask))
return false;
return true;
}
static bool deref_stack_reg(struct unwind_state *state, unsigned long addr,
unsigned long *val)
{
if (!stack_access_ok(state, addr, sizeof(long)))
return false;
*val = READ_ONCE_NOCHECK(*(unsigned long *)addr);
return true;
}
static bool deref_stack_regs(struct unwind_state *state, unsigned long addr,
unsigned long *ip, unsigned long *sp, bool full)
{
size_t regs_size = full ? REGS_SIZE : IRET_REGS_SIZE;
size_t sp_offset = full ? SP_OFFSET : IRET_SP_OFFSET;
struct pt_regs *regs = (struct pt_regs *)(addr + regs_size - REGS_SIZE);
if (IS_ENABLED(CONFIG_X86_64)) {
if (!stack_access_ok(state, addr, regs_size))
return false;
*ip = regs->ip;
*sp = regs->sp;
return true;
}
if (!stack_access_ok(state, addr, sp_offset))
return false;
*ip = regs->ip;
if (user_mode(regs)) {
if (!stack_access_ok(state, addr + sp_offset,
REGS_SIZE - SP_OFFSET))
return false;
*sp = regs->sp;
} else
*sp = (unsigned long)&regs->sp;
return true;
}
bool unwind_next_frame(struct unwind_state *state)
{
unsigned long ip_p, sp, orig_ip, prev_sp = state->sp;
enum stack_type prev_type = state->stack_info.type;
struct orc_entry *orc;
struct pt_regs *ptregs;
bool indirect = false;
if (unwind_done(state))
return false;
preempt_disable();
if (state->regs && user_mode(state->regs))
goto done;
orc = orc_find(state->signal ? state->ip : state->ip - 1);
if (!orc || orc->sp_reg == ORC_REG_UNDEFINED)
goto done;
orig_ip = state->ip;
switch (orc->sp_reg) {
case ORC_REG_SP:
sp = state->sp + orc->sp_offset;
break;
case ORC_REG_BP:
sp = state->bp + orc->sp_offset;
break;
case ORC_REG_SP_INDIRECT:
sp = state->sp + orc->sp_offset;
indirect = true;
break;
case ORC_REG_BP_INDIRECT:
sp = state->bp + orc->sp_offset;
indirect = true;
break;
case ORC_REG_R10:
if (!state->regs || !state->full_regs) {
orc_warn("missing regs for base reg R10 at ip %pB\n",
(void *)state->ip);
goto done;
}
sp = state->regs->r10;
break;
case ORC_REG_R13:
if (!state->regs || !state->full_regs) {
orc_warn("missing regs for base reg R13 at ip %pB\n",
(void *)state->ip);
goto done;
}
sp = state->regs->r13;
break;
case ORC_REG_DI:
if (!state->regs || !state->full_regs) {
orc_warn("missing regs for base reg DI at ip %pB\n",
(void *)state->ip);
goto done;
}
sp = state->regs->di;
break;
case ORC_REG_DX:
if (!state->regs || !state->full_regs) {
orc_warn("missing regs for base reg DX at ip %pB\n",
(void *)state->ip);
goto done;
}
sp = state->regs->dx;
break;
default:
orc_warn("unknown SP base reg %d for ip %pB\n",
orc->sp_reg, (void *)state->ip);
goto done;
}
if (indirect) {
if (!deref_stack_reg(state, sp, &sp))
goto done;
}
switch (orc->type) {
case ORC_TYPE_CALL:
ip_p = sp - sizeof(long);
if (!deref_stack_reg(state, ip_p, &state->ip))
goto done;
state->ip = ftrace_graph_ret_addr(state->task, &state->graph_idx,
state->ip, (void *)ip_p);
state->sp = sp;
state->regs = NULL;
state->signal = false;
break;
case ORC_TYPE_REGS:
if (!deref_stack_regs(state, sp, &state->ip, &state->sp, true)) {
orc_warn("can't dereference registers at %p for ip %pB\n",
(void *)sp, (void *)orig_ip);
goto done;
}
state->regs = (struct pt_regs *)sp;
state->full_regs = true;
state->signal = true;
break;
case ORC_TYPE_REGS_IRET:
if (!deref_stack_regs(state, sp, &state->ip, &state->sp, false)) {
orc_warn("can't dereference iret registers at %p for ip %pB\n",
(void *)sp, (void *)orig_ip);
goto done;
}
ptregs = container_of((void *)sp, struct pt_regs, ip);
if ((unsigned long)ptregs >= prev_sp &&
on_stack(&state->stack_info, ptregs, REGS_SIZE)) {
state->regs = ptregs;
state->full_regs = false;
} else
state->regs = NULL;
state->signal = true;
break;
default:
orc_warn("unknown .orc_unwind entry type %d for ip %pB\n",
orc->type, (void *)orig_ip);
break;
}
switch (orc->bp_reg) {
case ORC_REG_UNDEFINED:
if (state->regs && state->full_regs)
state->bp = state->regs->bp;
break;
case ORC_REG_PREV_SP:
if (!deref_stack_reg(state, sp + orc->bp_offset, &state->bp))
goto done;
break;
case ORC_REG_BP:
if (!deref_stack_reg(state, state->bp + orc->bp_offset, &state->bp))
goto done;
break;
default:
orc_warn("unknown BP base reg %d for ip %pB\n",
orc->bp_reg, (void *)orig_ip);
goto done;
}
if (state->stack_info.type == prev_type &&
on_stack(&state->stack_info, (void *)state->sp, sizeof(long)) &&
state->sp <= prev_sp) {
orc_warn("stack going in the wrong direction? ip=%pB\n",
(void *)orig_ip);
goto done;
}
preempt_enable();
return true;
done:
preempt_enable();
state->stack_info.type = STACK_TYPE_UNKNOWN;
return false;
}
void __unwind_start(struct unwind_state *state, struct task_struct *task,
struct pt_regs *regs, unsigned long *first_frame)
{
memset(state, 0, sizeof(*state));
state->task = task;
if (task_on_another_cpu(task))
goto done;
if (regs) {
if (user_mode(regs))
goto done;
state->ip = regs->ip;
state->sp = kernel_stack_pointer(regs);
state->bp = regs->bp;
state->regs = regs;
state->full_regs = true;
state->signal = true;
} else if (task == current) {
asm volatile("lea (%%rip), %0\n\t"
"mov %%rsp, %1\n\t"
"mov %%rbp, %2\n\t"
: "=r" (state->ip), "=r" (state->sp),
"=r" (state->bp));
} else {
struct inactive_task_frame *frame = (void *)task->thread.sp;
state->sp = task->thread.sp;
state->bp = READ_ONCE_NOCHECK(frame->bp);
state->ip = READ_ONCE_NOCHECK(frame->ret_addr);
}
if (get_stack_info((unsigned long *)state->sp, state->task,
&state->stack_info, &state->stack_mask))
return;
if (regs) {
unwind_next_frame(state);
return;
}
while (!unwind_done(state) &&
(!on_stack(&state->stack_info, first_frame, sizeof(long)) ||
state->sp <= (unsigned long)first_frame))
unwind_next_frame(state);
return;
done:
state->stack_info.type = STACK_TYPE_UNKNOWN;
return;
}
