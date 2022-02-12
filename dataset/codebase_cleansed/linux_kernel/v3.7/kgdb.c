char *dbg_get_reg(int regno, void *mem, struct pt_regs *regs)
{
if (regno >= DBG_MAX_REG_NUM || regno < 0)
return NULL;
*((unsigned long *) mem) = *((unsigned long *) ((void *)regs +
dbg_reg_def[regno].offset));
return dbg_reg_def[regno].name;
}
int dbg_set_reg(int regno, void *mem, struct pt_regs *regs)
{
if (regno >= DBG_MAX_REG_NUM || regno < 0)
return -EINVAL;
*((unsigned long *) ((void *)regs + dbg_reg_def[regno].offset)) =
*((unsigned long *) mem);
return 0;
}
void kgdb_arch_set_pc(struct pt_regs *regs, unsigned long pc)
{
instruction_pointer(regs) = pc;
}
static void hexagon_kgdb_nmi_hook(void *ignored)
{
kgdb_nmicallback(raw_smp_processor_id(), get_irq_regs());
}
void kgdb_roundup_cpus(unsigned long flags)
{
local_irq_enable();
smp_call_function(hexagon_kgdb_nmi_hook, NULL, 0);
local_irq_disable();
}
void sleeping_thread_to_gdb_regs(unsigned long *gdb_regs,
struct task_struct *task)
{
struct pt_regs *thread_regs;
if (task == NULL)
return;
memset(gdb_regs, 0, NUMREGBYTES);
thread_regs = task_pt_regs(task);
gdb_regs[0] = thread_regs->r00;
}
int kgdb_arch_handle_exception(int vector, int signo, int err_code,
char *remcom_in_buffer, char *remcom_out_buffer,
struct pt_regs *linux_regs)
{
switch (remcom_in_buffer[0]) {
case 's':
case 'c':
return 0;
}
return -1;
}
static int __kgdb_notify(struct die_args *args, unsigned long cmd)
{
if (atomic_read(&kgdb_active) != -1) {
kgdb_nmicallback(smp_processor_id(), args->regs);
return NOTIFY_STOP;
}
if (user_mode(args->regs))
return NOTIFY_DONE;
if (kgdb_handle_exception(args->trapnr & 0xff, args->signr, args->err,
args->regs))
return NOTIFY_DONE;
return NOTIFY_STOP;
}
static int
kgdb_notify(struct notifier_block *self, unsigned long cmd, void *ptr)
{
unsigned long flags;
int ret;
local_irq_save(flags);
ret = __kgdb_notify(ptr, cmd);
local_irq_restore(flags);
return ret;
}
int kgdb_arch_init(void)
{
return register_die_notifier(&kgdb_notifier);
}
void kgdb_arch_exit(void)
{
unregister_die_notifier(&kgdb_notifier);
}
