static unsigned long ftrace_nop_replace(struct dyn_ftrace *rec)
{
return rec->arch.old_mcount ? OLD_NOP : NOP;
}
static unsigned long adjust_address(struct dyn_ftrace *rec, unsigned long addr)
{
if (!rec->arch.old_mcount)
return addr;
if (addr == MCOUNT_ADDR)
addr = OLD_MCOUNT_ADDR;
else if (addr == FTRACE_ADDR)
addr = OLD_FTRACE_ADDR;
return addr;
}
static unsigned long ftrace_nop_replace(struct dyn_ftrace *rec)
{
return NOP;
}
static unsigned long adjust_address(struct dyn_ftrace *rec, unsigned long addr)
{
return addr;
}
static unsigned long ftrace_gen_branch(unsigned long pc, unsigned long addr,
bool link)
{
unsigned long s, j1, j2, i1, i2, imm10, imm11;
unsigned long first, second;
long offset;
offset = (long)addr - (long)(pc + 4);
if (offset < -16777216 || offset > 16777214) {
WARN_ON_ONCE(1);
return 0;
}
s = (offset >> 24) & 0x1;
i1 = (offset >> 23) & 0x1;
i2 = (offset >> 22) & 0x1;
imm10 = (offset >> 12) & 0x3ff;
imm11 = (offset >> 1) & 0x7ff;
j1 = (!i1) ^ s;
j2 = (!i2) ^ s;
first = 0xf000 | (s << 10) | imm10;
second = 0x9000 | (j1 << 13) | (j2 << 11) | imm11;
if (link)
second |= 1 << 14;
return (second << 16) | first;
}
static unsigned long ftrace_gen_branch(unsigned long pc, unsigned long addr,
bool link)
{
unsigned long opcode = 0xea000000;
long offset;
if (link)
opcode |= 1 << 24;
offset = (long)addr - (long)(pc + 8);
if (unlikely(offset < -33554432 || offset > 33554428)) {
WARN_ON_ONCE(1);
return 0;
}
offset = (offset >> 2) & 0x00ffffff;
return opcode | offset;
}
static unsigned long ftrace_call_replace(unsigned long pc, unsigned long addr)
{
return ftrace_gen_branch(pc, addr, true);
}
static int ftrace_modify_code(unsigned long pc, unsigned long old,
unsigned long new)
{
unsigned long replaced;
if (probe_kernel_read(&replaced, (void *)pc, MCOUNT_INSN_SIZE))
return -EFAULT;
if (replaced != old)
return -EINVAL;
if (probe_kernel_write((void *)pc, &new, MCOUNT_INSN_SIZE))
return -EPERM;
flush_icache_range(pc, pc + MCOUNT_INSN_SIZE);
return 0;
}
int ftrace_update_ftrace_func(ftrace_func_t func)
{
unsigned long pc, old;
unsigned long new;
int ret;
pc = (unsigned long)&ftrace_call;
memcpy(&old, &ftrace_call, MCOUNT_INSN_SIZE);
new = ftrace_call_replace(pc, (unsigned long)func);
ret = ftrace_modify_code(pc, old, new);
#ifdef CONFIG_OLD_MCOUNT
if (!ret) {
pc = (unsigned long)&ftrace_call_old;
memcpy(&old, &ftrace_call_old, MCOUNT_INSN_SIZE);
new = ftrace_call_replace(pc, (unsigned long)func);
ret = ftrace_modify_code(pc, old, new);
}
#endif
return ret;
}
int ftrace_make_call(struct dyn_ftrace *rec, unsigned long addr)
{
unsigned long new, old;
unsigned long ip = rec->ip;
old = ftrace_nop_replace(rec);
new = ftrace_call_replace(ip, adjust_address(rec, addr));
return ftrace_modify_code(rec->ip, old, new);
}
int ftrace_make_nop(struct module *mod,
struct dyn_ftrace *rec, unsigned long addr)
{
unsigned long ip = rec->ip;
unsigned long old;
unsigned long new;
int ret;
old = ftrace_call_replace(ip, adjust_address(rec, addr));
new = ftrace_nop_replace(rec);
ret = ftrace_modify_code(ip, old, new);
#ifdef CONFIG_OLD_MCOUNT
if (ret == -EINVAL && addr == MCOUNT_ADDR) {
rec->arch.old_mcount = true;
old = ftrace_call_replace(ip, adjust_address(rec, addr));
new = ftrace_nop_replace(rec);
ret = ftrace_modify_code(ip, old, new);
}
#endif
return ret;
}
int __init ftrace_dyn_arch_init(void *data)
{
*(unsigned long *)data = 0;
return 0;
}
void prepare_ftrace_return(unsigned long *parent, unsigned long self_addr,
unsigned long frame_pointer)
{
unsigned long return_hooker = (unsigned long) &return_to_handler;
struct ftrace_graph_ent trace;
unsigned long old;
int err;
if (unlikely(atomic_read(&current->tracing_graph_pause)))
return;
old = *parent;
*parent = return_hooker;
err = ftrace_push_return_trace(old, self_addr, &trace.depth,
frame_pointer);
if (err == -EBUSY) {
*parent = old;
return;
}
trace.func = self_addr;
if (!ftrace_graph_entry(&trace)) {
current->curr_ret_stack--;
*parent = old;
}
}
static int __ftrace_modify_caller(unsigned long *callsite,
void (*func) (void), bool enable)
{
unsigned long caller_fn = (unsigned long) func;
unsigned long pc = (unsigned long) callsite;
unsigned long branch = ftrace_gen_branch(pc, caller_fn, false);
unsigned long nop = 0xe1a00000;
unsigned long old = enable ? nop : branch;
unsigned long new = enable ? branch : nop;
return ftrace_modify_code(pc, old, new);
}
static int ftrace_modify_graph_caller(bool enable)
{
int ret;
ret = __ftrace_modify_caller(&ftrace_graph_call,
ftrace_graph_caller,
enable);
#ifdef CONFIG_OLD_MCOUNT
if (!ret)
ret = __ftrace_modify_caller(&ftrace_graph_call_old,
ftrace_graph_caller_old,
enable);
#endif
return ret;
}
int ftrace_enable_ftrace_graph_caller(void)
{
return ftrace_modify_graph_caller(true);
}
int ftrace_disable_ftrace_graph_caller(void)
{
return ftrace_modify_graph_caller(false);
}
