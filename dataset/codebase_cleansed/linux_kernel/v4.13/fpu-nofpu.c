asmlinkage
void unexpected_fpu_exception(struct pt_regs *regs, enum exception_code code)
{
panic("An FPU exception was received, but there's no FPU enabled.");
}
int dump_fpu(struct pt_regs *regs, elf_fpregset_t *fpreg)
{
return 0;
}
