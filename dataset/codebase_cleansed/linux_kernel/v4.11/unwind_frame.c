static void unwind_dump(struct unwind_state *state, unsigned long *sp)
{
static bool dumped_before = false;
bool prev_zero, zero = false;
unsigned long word;
if (dumped_before)
return;
dumped_before = true;
printk_deferred("unwind stack type:%d next_sp:%p mask:%lx graph_idx:%d\n",
state->stack_info.type, state->stack_info.next_sp,
state->stack_mask, state->graph_idx);
for (sp = state->orig_sp; sp < state->stack_info.end; sp++) {
word = READ_ONCE_NOCHECK(*sp);
prev_zero = zero;
zero = word == 0;
if (zero) {
if (!prev_zero)
printk_deferred("%p: %016x ...\n", sp, 0);
continue;
}
printk_deferred("%p: %016lx (%pB)\n", sp, word, (void *)word);
}
}
unsigned long unwind_get_return_address(struct unwind_state *state)
{
unsigned long addr;
unsigned long *addr_p = unwind_get_return_address_ptr(state);
if (unwind_done(state))
return 0;
if (state->regs && user_mode(state->regs))
return 0;
addr = READ_ONCE_TASK_STACK(state->task, *addr_p);
addr = ftrace_graph_ret_addr(state->task, &state->graph_idx, addr,
addr_p);
return __kernel_text_address(addr) ? addr : 0;
}
static size_t regs_size(struct pt_regs *regs)
{
if (IS_ENABLED(CONFIG_X86_32) && !user_mode(regs))
return sizeof(*regs) - 2*sizeof(long);
return sizeof(*regs);
}
static bool is_last_task_frame(struct unwind_state *state)
{
unsigned long *last_bp = (unsigned long *)task_pt_regs(state->task) - 2;
unsigned long *aligned_bp = last_bp - GCC_REALIGN_WORDS;
return (state->bp == last_bp ||
(state->bp == aligned_bp && *(aligned_bp+1) == *(last_bp+1)));
}
static struct pt_regs *decode_frame_pointer(unsigned long *bp)
{
unsigned long regs = (unsigned long)bp;
if (!(regs & 0x1))
return NULL;
return (struct pt_regs *)(regs & ~0x1);
}
static bool update_stack_state(struct unwind_state *state, void *addr,
size_t len)
{
struct stack_info *info = &state->stack_info;
enum stack_type orig_type = info->type;
while (!on_stack(info, addr, len))
if (get_stack_info(info->next_sp, state->task, info,
&state->stack_mask))
return false;
if (!state->orig_sp || info->type != orig_type)
state->orig_sp = addr;
return true;
}
bool unwind_next_frame(struct unwind_state *state)
{
struct pt_regs *regs;
unsigned long *next_bp, *next_frame;
size_t next_len;
enum stack_type prev_type = state->stack_info.type;
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
return true;
}
if (state->regs)
next_bp = (unsigned long *)state->regs->bp;
else
next_bp = (unsigned long *)READ_ONCE_TASK_STACK(state->task,*state->bp);
regs = decode_frame_pointer(next_bp);
if (regs) {
next_frame = (unsigned long *)regs;
next_len = sizeof(*regs);
} else {
next_frame = next_bp;
next_len = FRAME_HEADER_SIZE;
}
if (!update_stack_state(state, next_frame, next_len)) {
if (state->regs)
goto the_end;
goto bad_address;
}
if (state->stack_info.type == prev_type) {
if (state->regs && (void *)next_frame < (void *)state->regs + regs_size(state->regs))
goto bad_address;
if (state->bp && (void *)next_frame < (void *)state->bp + FRAME_HEADER_SIZE)
goto bad_address;
}
if (regs) {
state->regs = regs;
state->bp = NULL;
} else {
state->bp = next_bp;
state->regs = NULL;
}
return true;
bad_address:
if (state->task != current)
goto the_end;
if (state->regs) {
printk_deferred_once(KERN_WARNING
"WARNING: kernel stack regs at %p in %s:%d has bad 'bp' value %p\n",
state->regs, state->task->comm,
state->task->pid, next_frame);
unwind_dump(state, (unsigned long *)state->regs);
} else {
printk_deferred_once(KERN_WARNING
"WARNING: kernel stack frame pointer at %p in %s:%d has bad value %p\n",
state->bp, state->task->comm,
state->task->pid, next_frame);
unwind_dump(state, state->bp);
}
the_end:
state->stack_info.type = STACK_TYPE_UNKNOWN;
return false;
}
void __unwind_start(struct unwind_state *state, struct task_struct *task,
struct pt_regs *regs, unsigned long *first_frame)
{
unsigned long *bp, *frame;
size_t len;
memset(state, 0, sizeof(*state));
state->task = task;
if (regs && user_mode(regs)) {
state->stack_info.type = STACK_TYPE_UNKNOWN;
return;
}
bp = get_frame_pointer(task, regs);
regs = decode_frame_pointer(bp);
if (regs) {
state->regs = regs;
frame = (unsigned long *)regs;
len = sizeof(*regs);
} else {
state->bp = bp;
frame = bp;
len = FRAME_HEADER_SIZE;
}
get_stack_info(frame, state->task, &state->stack_info,
&state->stack_mask);
update_stack_state(state, frame, len);
while (!unwind_done(state) &&
(!on_stack(&state->stack_info, first_frame, sizeof(long)) ||
state->bp < first_frame))
unwind_next_frame(state);
}
