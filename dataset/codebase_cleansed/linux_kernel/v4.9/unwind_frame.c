unsigned long unwind_get_return_address(struct unwind_state *state)
{
unsigned long addr;
unsigned long *addr_p = unwind_get_return_address_ptr(state);
if (unwind_done(state))
return 0;
addr = ftrace_graph_ret_addr(state->task, &state->graph_idx, *addr_p,
addr_p);
return __kernel_text_address(addr) ? addr : 0;
}
static bool update_stack_state(struct unwind_state *state, void *addr,
size_t len)
{
struct stack_info *info = &state->stack_info;
while (!on_stack(info, addr, len))
if (get_stack_info(info->next_sp, state->task, info,
&state->stack_mask))
return false;
return true;
}
bool unwind_next_frame(struct unwind_state *state)
{
unsigned long *next_bp;
if (unwind_done(state))
return false;
next_bp = (unsigned long *)*state->bp;
if (!update_stack_state(state, next_bp, FRAME_HEADER_SIZE))
return false;
state->bp = next_bp;
return true;
}
void __unwind_start(struct unwind_state *state, struct task_struct *task,
struct pt_regs *regs, unsigned long *first_frame)
{
memset(state, 0, sizeof(*state));
state->task = task;
if (regs && user_mode(regs)) {
state->stack_info.type = STACK_TYPE_UNKNOWN;
return;
}
state->bp = get_frame_pointer(task, regs);
get_stack_info(state->bp, state->task, &state->stack_info,
&state->stack_mask);
update_stack_state(state, state->bp, FRAME_HEADER_SIZE);
while (!unwind_done(state) &&
(!on_stack(&state->stack_info, first_frame, sizeof(long)) ||
state->bp < first_frame))
unwind_next_frame(state);
}
