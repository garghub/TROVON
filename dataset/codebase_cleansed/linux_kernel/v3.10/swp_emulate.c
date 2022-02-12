static int proc_status_show(struct seq_file *m, void *v)
{
seq_printf(m, "Emulated SWP:\t\t%lu\n", swpcounter);
seq_printf(m, "Emulated SWPB:\t\t%lu\n", swpbcounter);
seq_printf(m, "Aborted SWP{B}:\t\t%lu\n", abtcounter);
if (previous_pid != 0)
seq_printf(m, "Last process:\t\t%d\n", previous_pid);
return 0;
}
static int proc_status_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_status_show, PDE_DATA(inode));
}
static void set_segfault(struct pt_regs *regs, unsigned long addr)
{
siginfo_t info;
down_read(&current->mm->mmap_sem);
if (find_vma(current->mm, addr) == NULL)
info.si_code = SEGV_MAPERR;
else
info.si_code = SEGV_ACCERR;
up_read(&current->mm->mmap_sem);
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_addr = (void *) instruction_pointer(regs);
pr_debug("SWP{B} emulation: access caused memory abort!\n");
arm_notify_die("Illegal memory access", regs, &info, 0, 0);
abtcounter++;
}
static int emulate_swpX(unsigned int address, unsigned int *data,
unsigned int type)
{
unsigned int res = 0;
if ((type != TYPE_SWPB) && (address & 0x3)) {
pr_debug("SWP instruction on unaligned pointer!\n");
return -EFAULT;
}
while (1) {
unsigned long temp;
smp_mb();
if (type == TYPE_SWPB)
__user_swpb_asm(*data, address, res, temp);
else
__user_swp_asm(*data, address, res, temp);
if (likely(res != -EAGAIN) || signal_pending(current))
break;
cond_resched();
}
if (res == 0) {
smp_mb();
if (type == TYPE_SWPB)
swpbcounter++;
else
swpcounter++;
}
return res;
}
static int swp_handler(struct pt_regs *regs, unsigned int instr)
{
unsigned int address, destreg, data, type;
unsigned int res = 0;
perf_sw_event(PERF_COUNT_SW_EMULATION_FAULTS, 1, regs, regs->ARM_pc);
res = arm_check_condition(instr, regs->ARM_cpsr);
switch (res) {
case ARM_OPCODE_CONDTEST_PASS:
break;
case ARM_OPCODE_CONDTEST_FAIL:
regs->ARM_pc += 4;
return 0;
case ARM_OPCODE_CONDTEST_UNCOND:
return -EFAULT;
default:
return -EINVAL;
}
if (current->pid != previous_pid) {
pr_debug("\"%s\" (%ld) uses deprecated SWP{B} instruction\n",
current->comm, (unsigned long)current->pid);
previous_pid = current->pid;
}
address = regs->uregs[EXTRACT_REG_NUM(instr, RN_OFFSET)];
data = regs->uregs[EXTRACT_REG_NUM(instr, RT2_OFFSET)];
destreg = EXTRACT_REG_NUM(instr, RT_OFFSET);
type = instr & TYPE_SWPB;
pr_debug("addr in r%d->0x%08x, dest is r%d, source in r%d->0x%08x)\n",
EXTRACT_REG_NUM(instr, RN_OFFSET), address,
destreg, EXTRACT_REG_NUM(instr, RT2_OFFSET), data);
if (!access_ok(VERIFY_WRITE, (address & ~3), 4)) {
pr_debug("SWP{B} emulation: access to %p not allowed!\n",
(void *)address);
res = -EFAULT;
} else {
res = emulate_swpX(address, &data, type);
}
if (res == 0) {
regs->ARM_pc += 4;
regs->uregs[destreg] = data;
} else if (res == -EFAULT) {
set_segfault(regs, address);
}
return 0;
}
static int __init swp_emulation_init(void)
{
#ifdef CONFIG_PROC_FS
if (!proc_create("cpu/swp_emulation", S_IRUGO, NULL, &proc_status_fops))
return -ENOMEM;
#endif
printk(KERN_NOTICE "Registering SWP/SWPB emulation handler\n");
register_undef_hook(&swp_hook);
return 0;
}
