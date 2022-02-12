char *dbg_get_reg(int regno, void *mem, struct pt_regs *regs)
{
if (regno >= DBG_MAX_REG_NUM || regno < 0)
return NULL;
if (dbg_reg_def[regno].offset != -1)
memcpy(mem, (void *)regs + dbg_reg_def[regno].offset,
dbg_reg_def[regno].size);
else
memset(mem, 0, dbg_reg_def[regno].size);
return dbg_reg_def[regno].name;
}
int dbg_set_reg(int regno, void *mem, struct pt_regs *regs)
{
if (regno >= DBG_MAX_REG_NUM || regno < 0)
return -EINVAL;
if (dbg_reg_def[regno].offset != -1)
memcpy((void *)regs + dbg_reg_def[regno].offset, mem,
dbg_reg_def[regno].size);
return 0;
}
void sleeping_thread_to_gdb_regs(unsigned long *gdb_regs, struct task_struct *p)
{
memset((char *)gdb_regs, 0, NUMREGBYTES);
gdb_regs[GDB_SP] = p->thread.kregs->sp;
gdb_regs[GDB_PC] = p->thread.kregs->ea;
}
void kgdb_arch_set_pc(struct pt_regs *regs, unsigned long pc)
{
regs->ea = pc;
}
int kgdb_arch_handle_exception(int vector, int signo, int err_code,
char *remcom_in_buffer, char *remcom_out_buffer,
struct pt_regs *regs)
{
char *ptr;
unsigned long addr;
switch (remcom_in_buffer[0]) {
case 's':
case 'c':
ptr = &remcom_in_buffer[1];
if (kgdb_hex2long(&ptr, &addr))
regs->ea = addr;
return 0;
}
return -1;
}
asmlinkage void kgdb_breakpoint_c(struct pt_regs *regs)
{
if (!wait_for_remote_debugger)
regs->ea -= 4;
else
wait_for_remote_debugger = 0;
kgdb_handle_exception(30, SIGTRAP, 0, regs);
}
int kgdb_arch_init(void)
{
wait_for_remote_debugger = 1;
return 0;
}
void kgdb_arch_exit(void)
{
}
