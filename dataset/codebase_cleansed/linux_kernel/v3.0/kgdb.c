int dbg_set_reg(int regno, void *mem, struct pt_regs *regs)
{
int fp_reg;
if (regno < 0 || regno >= DBG_MAX_REG_NUM)
return -EINVAL;
if (dbg_reg_def[regno].offset != -1 && regno < 38) {
memcpy((void *)regs + dbg_reg_def[regno].offset, mem,
dbg_reg_def[regno].size);
} else if (current && dbg_reg_def[regno].offset != -1 && regno < 72) {
if (!(regs->cp0_status & ST0_CU1))
return 0;
if (regno == 70) {
memcpy((void *)&current->thread.fpu.fcr31, mem,
dbg_reg_def[regno].size);
goto out_save;
} else if (regno == 71) {
goto out_save;
}
fp_reg = dbg_reg_def[regno].offset;
memcpy((void *)&current->thread.fpu.fpr[fp_reg], mem,
dbg_reg_def[regno].size);
out_save:
restore_fp(current);
}
return 0;
}
char *dbg_get_reg(int regno, void *mem, struct pt_regs *regs)
{
int fp_reg;
if (regno >= DBG_MAX_REG_NUM || regno < 0)
return NULL;
if (dbg_reg_def[regno].offset != -1 && regno < 38) {
memcpy(mem, (void *)regs + dbg_reg_def[regno].offset,
dbg_reg_def[regno].size);
} else if (current && dbg_reg_def[regno].offset != -1 && regno < 72) {
if (!(regs->cp0_status & ST0_CU1))
goto out;
save_fp(current);
if (regno == 70) {
memcpy(mem, (void *)&current->thread.fpu.fcr31,
dbg_reg_def[regno].size);
goto out;
} else if (regno == 71) {
memset(mem, 0, dbg_reg_def[regno].size);
goto out;
}
fp_reg = dbg_reg_def[regno].offset;
memcpy(mem, (void *)&current->thread.fpu.fpr[fp_reg],
dbg_reg_def[regno].size);
}
out:
return dbg_reg_def[regno].name;
}
void arch_kgdb_breakpoint(void)
{
__asm__ __volatile__(
".globl breakinst\n\t"
".set\tnoreorder\n\t"
"nop\n"
"breakinst:\tbreak\n\t"
"nop\n\t"
".set\treorder");
}
static void kgdb_call_nmi_hook(void *ignored)
{
kgdb_nmicallback(raw_smp_processor_id(), NULL);
}
void kgdb_roundup_cpus(unsigned long flags)
{
local_irq_enable();
smp_call_function(kgdb_call_nmi_hook, NULL, 0);
local_irq_disable();
}
static int compute_signal(int tt)
{
struct hard_trap_info *ht;
for (ht = hard_trap_info; ht->tt && ht->signo; ht++)
if (ht->tt == tt)
return ht->signo;
return SIGHUP;
}
void sleeping_thread_to_gdb_regs(unsigned long *gdb_regs, struct task_struct *p)
{
int reg;
struct thread_info *ti = task_thread_info(p);
unsigned long ksp = (unsigned long)ti + THREAD_SIZE - 32;
struct pt_regs *regs = (struct pt_regs *)ksp - 1;
#if (KGDB_GDB_REG_SIZE == 32)
u32 *ptr = (u32 *)gdb_regs;
#else
u64 *ptr = (u64 *)gdb_regs;
#endif
for (reg = 0; reg < 16; reg++)
*(ptr++) = regs->regs[reg];
for (reg = 16; reg < 24; reg++)
*(ptr++) = regs->regs[reg];
for (reg = 24; reg < 28; reg++)
*(ptr++) = 0;
for (reg = 28; reg < 32; reg++)
*(ptr++) = regs->regs[reg];
*(ptr++) = regs->cp0_status;
*(ptr++) = regs->lo;
*(ptr++) = regs->hi;
*(ptr++) = regs->cp0_badvaddr;
*(ptr++) = regs->cp0_cause;
*(ptr++) = regs->cp0_epc;
}
void kgdb_arch_set_pc(struct pt_regs *regs, unsigned long pc)
{
regs->cp0_epc = pc;
}
static int kgdb_mips_notify(struct notifier_block *self, unsigned long cmd,
void *ptr)
{
struct die_args *args = (struct die_args *)ptr;
struct pt_regs *regs = args->regs;
int trap = (regs->cp0_cause & 0x7c) >> 2;
if (user_mode(regs))
return NOTIFY_DONE;
if (atomic_read(&kgdb_active) != -1)
kgdb_nmicallback(smp_processor_id(), regs);
if (kgdb_handle_exception(trap, compute_signal(trap), cmd, regs))
return NOTIFY_DONE;
if (atomic_read(&kgdb_setting_breakpoint))
if ((trap == 9) && (regs->cp0_epc == (unsigned long)breakinst))
regs->cp0_epc += 4;
local_irq_enable();
__flush_cache_all();
return NOTIFY_STOP;
}
int kgdb_ll_trap(int cmd, const char *str,
struct pt_regs *regs, long err, int trap, int sig)
{
struct die_args args = {
.regs = regs,
.str = str,
.err = err,
.trapnr = trap,
.signr = sig,
};
if (!kgdb_io_module_registered)
return NOTIFY_DONE;
return kgdb_mips_notify(NULL, cmd, &args);
}
int kgdb_arch_handle_exception(int vector, int signo, int err_code,
char *remcom_in_buffer, char *remcom_out_buffer,
struct pt_regs *regs)
{
char *ptr;
unsigned long address;
switch (remcom_in_buffer[0]) {
case 'c':
ptr = &remcom_in_buffer[1];
if (kgdb_hex2long(&ptr, &address))
regs->cp0_epc = address;
return 0;
}
return -1;
}
int kgdb_arch_init(void)
{
union mips_instruction insn = {
.r_format = {
.opcode = spec_op,
.func = break_op,
}
};
memcpy(arch_kgdb_ops.gdb_bpt_instr, insn.byte, BREAK_INSTR_SIZE);
register_die_notifier(&kgdb_notifier);
return 0;
}
void kgdb_arch_exit(void)
{
unregister_die_notifier(&kgdb_notifier);
}
