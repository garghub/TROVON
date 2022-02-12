static void unwind_dump(struct unwind_state *state)
{
static bool dumped_before = false;
bool prev_zero, zero = false;
unsigned long word, *sp;
struct stack_info stack_info = {0};
unsigned long visit_mask = 0;
if (dumped_before)
return;
dumped_before = true;
printk_deferred("unwind stack type:%d next_sp:%p mask:0x%lx graph_idx:%d\n",
state->stack_info.type, state->stack_info.next_sp,
state->stack_mask, state->graph_idx);
for (sp = state->orig_sp; sp; sp = PTR_ALIGN(stack_info.next_sp, sizeof(long))) {
if (get_stack_info(sp, state->task, &stack_info, &visit_mask))
break;
for (; sp < stack_info.end; sp++) {
word = READ_ONCE_NOCHECK(*sp);
prev_zero = zero;
zero = word == 0;
if (zero) {
if (!prev_zero)
printk_deferred("%p: %0*x ...\n",
sp, BITS_PER_LONG/4, 0);
continue;
}
printk_deferred("%p: %0*lx (%pB)\n",
sp, BITS_PER_LONG/4, word, (void *)word);
}
}
}
unsigned long unwind_get_return_address(struct unwind_state *state)
{
if (unwind_done(state))
return 0;
return __kernel_text_address(state->ip) ? state->ip : 0;
}
static size_t regs_size(struct pt_regs *regs)
{
if (IS_ENABLED(CONFIG_X86_32) && !user_mode(regs))
return sizeof(*regs) - 2*sizeof(long);
return sizeof(*regs);
}
static bool in_entry_code(unsigned long ip)
{
char *addr = (char *)ip;
if (addr >= __entry_text_start && addr < __entry_text_end)
return true;
#if defined(CONFIG_FUNCTION_GRAPH_TRACER) || defined(CONFIG_KASAN)
if (addr >= __irqentry_text_start && addr < __irqentry_text_end)
return true;
#endif
return false;
}
static inline unsigned long *last_frame(struct unwind_state *state)
{
return (unsigned long *)task_pt_regs(state->task) - 2;
}
static bool is_last_frame(struct unwind_state *state)
{
return state->bp == last_frame(state);
}
static inline unsigned long *last_aligned_frame(struct unwind_state *state)
{
return last_frame(state) - GCC_REALIGN_WORDS;
}
static bool is_last_aligned_frame(struct unwind_state *state)
{
unsigned long *last_bp = last_frame(state);
unsigned long *aligned_bp = last_aligned_frame(state);
return (state->bp == aligned_bp && *(aligned_bp + 1) == *(last_bp + 1));
}
static bool is_last_ftrace_frame(struct unwind_state *state)
{
unsigned long *last_bp = last_frame(state);
unsigned long *last_ftrace_bp = last_bp - 3;
return (state->bp == last_ftrace_bp &&
*state->bp == *(state->bp + 2) &&
*(state->bp + 1) == *(state->bp + 4));
}
static bool is_last_task_frame(struct unwind_state *state)
{
return is_last_frame(state) || is_last_aligned_frame(state) ||
is_last_ftrace_frame(state);
}
static struct pt_regs *decode_frame_pointer(unsigned long *bp)
{
unsigned long regs = (unsigned long)bp;
if (!(regs & 0x1))
return NULL;
return (struct pt_regs *)(regs & ~0x1);
}
static bool update_stack_state(struct unwind_state *state,
unsigned long *next_bp)
{
struct stack_info *info = &state->stack_info;
enum stack_type prev_type = info->type;
struct pt_regs *regs;
unsigned long *frame, *prev_frame_end, *addr_p, addr;
size_t len;
if (state->regs)
prev_frame_end = (void *)state->regs + regs_size(state->regs);
else
prev_frame_end = (void *)state->bp + FRAME_HEADER_SIZE;
regs = decode_frame_pointer(next_bp);
if (regs) {
frame = (unsigned long *)regs;
len = regs_size(regs);
state->got_irq = true;
} else {
frame = next_bp;
len = FRAME_HEADER_SIZE;
}
while (!on_stack(info, frame, len))
if (get_stack_info(info->next_sp, state->task, info,
&state->stack_mask))
return false;
if (state->orig_sp && state->stack_info.type == prev_type &&
frame < prev_frame_end)
return false;
if (regs) {
state->regs = regs;
state->bp = NULL;
} else {
state->bp = next_bp;
state->regs = NULL;
}
if (state->regs && user_mode(state->regs))
state->ip = 0;
else {
addr_p = unwind_get_return_address_ptr(state);
addr = READ_ONCE_TASK_STACK(state->task, *addr_p);
state->ip = ftrace_graph_ret_addr(state->task, &state->graph_idx,
addr, addr_p);
}
if (!state->orig_sp)
state->orig_sp = frame;
return true;
}
bool unwind_next_frame(struct unwind_state *state)
{
struct pt_regs *regs;
unsigned long *next_bp;
if (unwind_done(state))
return false;
if (state->regs && user_mode(state->regs))
goto the_end;
if (is_last_task_frame(state)) {
regs = task_pt_regs(state->task);
if (!user_mode(regs))
goto the_end;
state->regs = regs;
state->bp = NULL;
state->ip = 0;
return true;
}
if (state->regs)
next_bp = (unsigned long *)state->regs->bp;
else
next_bp = (unsigned long *)READ_ONCE_TASK_STACK(state->task, *state->bp);
if (!update_stack_state(state, next_bp))
goto bad_address;
return true;
bad_address:
state->error = true;
if (state->task != current)
goto the_end;
if (state->got_irq && in_entry_code(state->ip))
goto the_end;
if (state->regs &&
state->regs->sp >= (unsigned long)last_aligned_frame(state) &&
state->regs->sp < (unsigned long)task_pt_regs(state->task))
goto the_end;
if (state->regs) {
printk_deferred_once(KERN_WARNING
"WARNING: kernel stack regs at %p in %s:%d has bad 'bp' value %p\n",
state->regs, state->task->comm,
state->task->pid, next_bp);
unwind_dump(state);
} else {
printk_deferred_once(KERN_WARNING
"WARNING: kernel stack frame pointer at %p in %s:%d has bad value %p\n",
state->bp, state->task->comm,
state->task->pid, next_bp);
unwind_dump(state);
}
the_end:
state->stack_info.type = STACK_TYPE_UNKNOWN;
return false;
}
void __unwind_start(struct unwind_state *state, struct task_struct *task,
struct pt_regs *regs, unsigned long *first_frame)
{
unsigned long *bp;
memset(state, 0, sizeof(*state));
state->task = task;
state->got_irq = (regs);
if (regs && user_mode(regs)) {
state->stack_info.type = STACK_TYPE_UNKNOWN;
return;
}
bp = get_frame_pointer(task, regs);
get_stack_info(bp, state->task, &state->stack_info,
&state->stack_mask);
update_stack_state(state, bp);
while (!unwind_done(state) &&
(!on_stack(&state->stack_info, first_frame, sizeof(long)) ||
state->bp < first_frame))
unwind_next_frame(state);
}
