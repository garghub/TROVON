static unsigned long get_dr(int n)
{
struct perf_event *bp = current->thread.ptrace_bps[n];
return bp ? bp->hw.info.address : 0;
}
static void dump_thread32(struct pt_regs *regs, struct user32 *dump)
{
u32 fs, gs;
memset(dump, 0, sizeof(*dump));
dump->magic = CMAGIC;
dump->start_code = 0;
dump->start_stack = regs->sp & ~(PAGE_SIZE - 1);
dump->u_tsize = ((unsigned long) current->mm->end_code) >> PAGE_SHIFT;
dump->u_dsize = ((unsigned long)
(current->mm->brk + (PAGE_SIZE-1))) >> PAGE_SHIFT;
dump->u_dsize -= dump->u_tsize;
dump->u_debugreg[0] = get_dr(0);
dump->u_debugreg[1] = get_dr(1);
dump->u_debugreg[2] = get_dr(2);
dump->u_debugreg[3] = get_dr(3);
dump->u_debugreg[6] = current->thread.debugreg6;
dump->u_debugreg[7] = current->thread.ptrace_dr7;
if (dump->start_stack < 0xc0000000) {
unsigned long tmp;
tmp = (unsigned long) (0xc0000000 - dump->start_stack);
dump->u_ssize = tmp >> PAGE_SHIFT;
}
dump->regs.ebx = regs->bx;
dump->regs.ecx = regs->cx;
dump->regs.edx = regs->dx;
dump->regs.esi = regs->si;
dump->regs.edi = regs->di;
dump->regs.ebp = regs->bp;
dump->regs.eax = regs->ax;
dump->regs.ds = current->thread.ds;
dump->regs.es = current->thread.es;
savesegment(fs, fs);
dump->regs.fs = fs;
savesegment(gs, gs);
dump->regs.gs = gs;
dump->regs.orig_eax = regs->orig_ax;
dump->regs.eip = regs->ip;
dump->regs.cs = regs->cs;
dump->regs.eflags = regs->flags;
dump->regs.esp = regs->sp;
dump->regs.ss = regs->ss;
#if 1
dump->u_fpvalid = 0;
#else
dump->u_fpvalid = dump_fpu(regs, &dump->i387);
#endif
}
static int set_brk(unsigned long start, unsigned long end)
{
start = PAGE_ALIGN(start);
end = PAGE_ALIGN(end);
if (end <= start)
return 0;
return vm_brk(start, end - start);
}
static int aout_core_dump(struct coredump_params *cprm)
{
mm_segment_t fs;
int has_dumped = 0;
unsigned long dump_start, dump_size;
struct user32 dump;
fs = get_fs();
set_fs(KERNEL_DS);
has_dumped = 1;
strncpy(dump.u_comm, current->comm, sizeof(current->comm));
dump.u_ar0 = offsetof(struct user32, regs);
dump.signal = cprm->siginfo->si_signo;
dump_thread32(cprm->regs, &dump);
if ((dump.u_dsize + dump.u_ssize + 1) * PAGE_SIZE > cprm->limit)
dump.u_dsize = 0;
if ((dump.u_ssize + 1) * PAGE_SIZE > cprm->limit)
dump.u_ssize = 0;
set_fs(USER_DS);
if (!access_ok(VERIFY_READ, (void *) (unsigned long)START_DATA(dump),
dump.u_dsize << PAGE_SHIFT))
dump.u_dsize = 0;
if (!access_ok(VERIFY_READ, (void *) (unsigned long)START_STACK(dump),
dump.u_ssize << PAGE_SHIFT))
dump.u_ssize = 0;
set_fs(KERNEL_DS);
if (!dump_emit(cprm, &dump, sizeof(dump)))
goto end_coredump;
if (!dump_skip(cprm, PAGE_SIZE - sizeof(dump)))
goto end_coredump;
set_fs(USER_DS);
if (dump.u_dsize != 0) {
dump_start = START_DATA(dump);
dump_size = dump.u_dsize << PAGE_SHIFT;
if (!dump_emit(cprm, (void *)dump_start, dump_size))
goto end_coredump;
}
if (dump.u_ssize != 0) {
dump_start = START_STACK(dump);
dump_size = dump.u_ssize << PAGE_SHIFT;
if (!dump_emit(cprm, (void *)dump_start, dump_size))
goto end_coredump;
}
end_coredump:
set_fs(fs);
return has_dumped;
}
static u32 __user *create_aout_tables(char __user *p, struct linux_binprm *bprm)
{
u32 __user *argv, *envp, *sp;
int argc = bprm->argc, envc = bprm->envc;
sp = (u32 __user *) ((-(unsigned long)sizeof(u32)) & (unsigned long) p);
sp -= envc+1;
envp = sp;
sp -= argc+1;
argv = sp;
put_user((unsigned long) envp, --sp);
put_user((unsigned long) argv, --sp);
put_user(argc, --sp);
current->mm->arg_start = (unsigned long) p;
while (argc-- > 0) {
char c;
put_user((u32)(unsigned long)p, argv++);
do {
get_user(c, p++);
} while (c);
}
put_user(0, argv);
current->mm->arg_end = current->mm->env_start = (unsigned long) p;
while (envc-- > 0) {
char c;
put_user((u32)(unsigned long)p, envp++);
do {
get_user(c, p++);
} while (c);
}
put_user(0, envp);
current->mm->env_end = (unsigned long) p;
return sp;
}
static int load_aout_binary(struct linux_binprm *bprm)
{
unsigned long error, fd_offset, rlim;
struct pt_regs *regs = current_pt_regs();
struct exec ex;
int retval;
ex = *((struct exec *) bprm->buf);
if ((N_MAGIC(ex) != ZMAGIC && N_MAGIC(ex) != OMAGIC &&
N_MAGIC(ex) != QMAGIC && N_MAGIC(ex) != NMAGIC) ||
N_TRSIZE(ex) || N_DRSIZE(ex) ||
i_size_read(file_inode(bprm->file)) <
ex.a_text+ex.a_data+N_SYMSIZE(ex)+N_TXTOFF(ex)) {
return -ENOEXEC;
}
fd_offset = N_TXTOFF(ex);
rlim = rlimit(RLIMIT_DATA);
if (rlim >= RLIM_INFINITY)
rlim = ~0;
if (ex.a_data + ex.a_bss > rlim)
return -ENOMEM;
retval = flush_old_exec(bprm);
if (retval)
return retval;
set_personality(PER_LINUX);
set_personality_ia32(false);
setup_new_exec(bprm);
regs->cs = __USER32_CS;
regs->r8 = regs->r9 = regs->r10 = regs->r11 = regs->r12 =
regs->r13 = regs->r14 = regs->r15 = 0;
current->mm->end_code = ex.a_text +
(current->mm->start_code = N_TXTADDR(ex));
current->mm->end_data = ex.a_data +
(current->mm->start_data = N_DATADDR(ex));
current->mm->brk = ex.a_bss +
(current->mm->start_brk = N_BSSADDR(ex));
retval = setup_arg_pages(bprm, IA32_STACK_TOP, EXSTACK_DEFAULT);
if (retval < 0)
return retval;
install_exec_creds(bprm);
if (N_MAGIC(ex) == OMAGIC) {
unsigned long text_addr, map_size;
text_addr = N_TXTADDR(ex);
map_size = ex.a_text+ex.a_data;
error = vm_brk(text_addr & PAGE_MASK, map_size);
if (error)
return error;
error = read_code(bprm->file, text_addr, 32,
ex.a_text + ex.a_data);
if ((signed long)error < 0)
return error;
} else {
#ifdef WARN_OLD
static unsigned long error_time, error_time2;
if ((ex.a_text & 0xfff || ex.a_data & 0xfff) &&
(N_MAGIC(ex) != NMAGIC) &&
time_after(jiffies, error_time2 + 5*HZ)) {
printk(KERN_NOTICE "executable not page aligned\n");
error_time2 = jiffies;
}
if ((fd_offset & ~PAGE_MASK) != 0 &&
time_after(jiffies, error_time + 5*HZ)) {
printk(KERN_WARNING
"fd_offset is not page aligned. Please convert "
"program: %pD\n",
bprm->file);
error_time = jiffies;
}
#endif
if (!bprm->file->f_op->mmap || (fd_offset & ~PAGE_MASK) != 0) {
error = vm_brk(N_TXTADDR(ex), ex.a_text+ex.a_data);
if (error)
return error;
read_code(bprm->file, N_TXTADDR(ex), fd_offset,
ex.a_text+ex.a_data);
goto beyond_if;
}
error = vm_mmap(bprm->file, N_TXTADDR(ex), ex.a_text,
PROT_READ | PROT_EXEC,
MAP_FIXED | MAP_PRIVATE | MAP_DENYWRITE |
MAP_EXECUTABLE | MAP_32BIT,
fd_offset);
if (error != N_TXTADDR(ex))
return error;
error = vm_mmap(bprm->file, N_DATADDR(ex), ex.a_data,
PROT_READ | PROT_WRITE | PROT_EXEC,
MAP_FIXED | MAP_PRIVATE | MAP_DENYWRITE |
MAP_EXECUTABLE | MAP_32BIT,
fd_offset + ex.a_text);
if (error != N_DATADDR(ex))
return error;
}
beyond_if:
error = set_brk(current->mm->start_brk, current->mm->brk);
if (error)
return error;
set_binfmt(&aout_format);
current->mm->start_stack =
(unsigned long)create_aout_tables((char __user *)bprm->p, bprm);
loadsegment(fs, 0);
loadsegment(ds, __USER32_DS);
loadsegment(es, __USER32_DS);
load_gs_index(0);
(regs)->ip = ex.a_entry;
(regs)->sp = current->mm->start_stack;
(regs)->flags = 0x200;
(regs)->cs = __USER32_CS;
(regs)->ss = __USER32_DS;
regs->r8 = regs->r9 = regs->r10 = regs->r11 =
regs->r12 = regs->r13 = regs->r14 = regs->r15 = 0;
set_fs(USER_DS);
return 0;
}
static int load_aout_library(struct file *file)
{
unsigned long bss, start_addr, len, error;
int retval;
struct exec ex;
loff_t pos = 0;
retval = -ENOEXEC;
error = kernel_read(file, &ex, sizeof(ex), &pos);
if (error != sizeof(ex))
goto out;
if ((N_MAGIC(ex) != ZMAGIC && N_MAGIC(ex) != QMAGIC) || N_TRSIZE(ex) ||
N_DRSIZE(ex) || ((ex.a_entry & 0xfff) && N_MAGIC(ex) == ZMAGIC) ||
i_size_read(file_inode(file)) <
ex.a_text+ex.a_data+N_SYMSIZE(ex)+N_TXTOFF(ex)) {
goto out;
}
if (N_FLAGS(ex))
goto out;
start_addr = ex.a_entry & 0xfffff000;
if ((N_TXTOFF(ex) & ~PAGE_MASK) != 0) {
#ifdef WARN_OLD
static unsigned long error_time;
if (time_after(jiffies, error_time + 5*HZ)) {
printk(KERN_WARNING
"N_TXTOFF is not page aligned. Please convert "
"library: %pD\n",
file);
error_time = jiffies;
}
#endif
retval = vm_brk(start_addr, ex.a_text + ex.a_data + ex.a_bss);
if (retval)
goto out;
read_code(file, start_addr, N_TXTOFF(ex),
ex.a_text + ex.a_data);
retval = 0;
goto out;
}
error = vm_mmap(file, start_addr, ex.a_text + ex.a_data,
PROT_READ | PROT_WRITE | PROT_EXEC,
MAP_FIXED | MAP_PRIVATE | MAP_DENYWRITE | MAP_32BIT,
N_TXTOFF(ex));
retval = error;
if (error != start_addr)
goto out;
len = PAGE_ALIGN(ex.a_text + ex.a_data);
bss = ex.a_text + ex.a_data + ex.a_bss;
if (bss > len) {
retval = vm_brk(start_addr + len, bss - len);
if (retval)
goto out;
}
retval = 0;
out:
return retval;
}
static int __init init_aout_binfmt(void)
{
register_binfmt(&aout_format);
return 0;
}
static void __exit exit_aout_binfmt(void)
{
unregister_binfmt(&aout_format);
}
