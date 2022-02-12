static void tbi_boing_init(void)
{
unsigned long size;
unsigned long offset;
char modname[MODULE_NAME_LEN];
char name[KSYM_NAME_LEN];
tbi_boing_addr = kallsyms_lookup_name("___TBIBoingVec");
if (!tbi_boing_addr)
tbi_boing_addr = 1;
else if (!lookup_symbol_attrs(tbi_boing_addr, &size,
&offset, modname, name))
tbi_boing_size = size;
}
int notrace unwind_frame(struct stackframe *frame)
{
struct metag_frame *fp = (struct metag_frame *)frame->fp;
unsigned long lr;
unsigned long fpnew;
if (frame->fp & 0x7)
return -EINVAL;
fpnew = fp->fp;
lr = fp->lr - 4;
#ifdef CONFIG_KALLSYMS
if (!tbi_boing_addr)
tbi_boing_init();
if (tbi_boing_size && lr >= tbi_boing_addr &&
lr < tbi_boing_addr + tbi_boing_size) {
struct pt_regs *regs = (struct pt_regs *)fpnew;
if (user_mode(regs))
return -EINVAL;
fpnew = regs->ctx.AX[1].U0;
lr = regs->ctx.DX[4].U1;
}
#endif
if (fpnew < (ALIGN_DOWN((unsigned long)fp, THREAD_SIZE) +
sizeof(struct thread_info)) || fpnew >= (unsigned long)fp)
return -EINVAL;
frame->fp = fpnew;
frame->pc = lr;
return 0;
}
int notrace unwind_frame(struct stackframe *frame)
{
struct metag_frame *sp = (struct metag_frame *)frame->sp;
if (frame->sp & 0x7)
return -EINVAL;
while (!kstack_end(sp)) {
unsigned long addr = sp->lr - 4;
sp--;
if (__kernel_text_address(addr)) {
frame->sp = (unsigned long)sp;
frame->pc = addr;
return 0;
}
}
return -EINVAL;
}
void notrace walk_stackframe(struct stackframe *frame,
int (*fn)(struct stackframe *, void *), void *data)
{
while (1) {
int ret;
if (fn(frame, data))
break;
ret = unwind_frame(frame);
if (ret < 0)
break;
}
}
static int save_trace(struct stackframe *frame, void *d)
{
struct stack_trace_data *data = d;
struct stack_trace *trace = data->trace;
unsigned long addr = frame->pc;
if (data->no_sched_functions && in_sched_functions(addr))
return 0;
if (data->skip) {
data->skip--;
return 0;
}
trace->entries[trace->nr_entries++] = addr;
return trace->nr_entries >= trace->max_entries;
}
void save_stack_trace_tsk(struct task_struct *tsk, struct stack_trace *trace)
{
struct stack_trace_data data;
struct stackframe frame;
data.trace = trace;
data.skip = trace->skip;
if (tsk != current) {
#ifdef CONFIG_SMP
if (trace->nr_entries < trace->max_entries)
trace->entries[trace->nr_entries++] = ULONG_MAX;
return;
#else
data.no_sched_functions = 1;
frame.fp = thread_saved_fp(tsk);
frame.sp = thread_saved_sp(tsk);
frame.lr = 0;
frame.pc = thread_saved_pc(tsk);
#endif
} else {
register unsigned long current_sp asm ("A0StP");
data.no_sched_functions = 0;
frame.fp = (unsigned long)__builtin_frame_address(0);
frame.sp = current_sp;
frame.lr = (unsigned long)__builtin_return_address(0);
frame.pc = (unsigned long)save_stack_trace_tsk;
}
walk_stackframe(&frame, save_trace, &data);
if (trace->nr_entries < trace->max_entries)
trace->entries[trace->nr_entries++] = ULONG_MAX;
}
void save_stack_trace(struct stack_trace *trace)
{
save_stack_trace_tsk(current, trace);
}
