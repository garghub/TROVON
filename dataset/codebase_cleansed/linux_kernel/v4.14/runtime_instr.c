static void disable_runtime_instr(void)
{
struct pt_regs *regs = task_pt_regs(current);
load_runtime_instr_cb(&runtime_instr_empty_cb);
regs->psw.mask &= ~PSW_MASK_RI;
}
static void init_runtime_instr_cb(struct runtime_instr_cb *cb)
{
cb->buf_limit = 0xfff;
cb->pstate = 1;
cb->pstate_set_buf = 1;
cb->pstate_sample = 1;
cb->pstate_collect = 1;
cb->key = PAGE_DEFAULT_KEY;
cb->valid = 1;
}
void exit_thread_runtime_instr(void)
{
struct task_struct *task = current;
if (!task->thread.ri_cb)
return;
disable_runtime_instr();
kfree(task->thread.ri_cb);
task->thread.ri_cb = NULL;
}
