void ucf64_raise_sigfpe(unsigned int sicode, struct pt_regs *regs)
{
siginfo_t info;
memset(&info, 0, sizeof(info));
info.si_signo = SIGFPE;
info.si_code = sicode;
info.si_addr = (void __user *)(instruction_pointer(regs) - 4);
current->thread.error_code = 0;
current->thread.trap_no = 6;
send_sig_info(SIGFPE, &info, current);
}
void ucf64_exchandler(u32 inst, u32 fpexc, struct pt_regs *regs)
{
u32 tmp = fpexc;
u32 exc = F64_EXCEPTION_ERROR & fpexc;
pr_debug("UniCore-F64: instruction %08x fpscr %08x\n",
inst, fpexc);
if (exc & FPSCR_CMPINSTR_BIT) {
if (exc & FPSCR_CON)
tmp |= FPSCR_CON;
else
tmp &= ~(FPSCR_CON);
exc &= ~(FPSCR_CMPINSTR_BIT | FPSCR_CON);
} else {
pr_debug(KERN_ERR "UniCore-F64 Error: unhandled exceptions\n");
pr_debug(KERN_ERR "UniCore-F64 FPSCR 0x%08x INST 0x%08x\n",
cff(FPSCR), inst);
ucf64_raise_sigfpe(0, regs);
return;
}
tmp &= ~(FPSCR_TRAP | FPSCR_IOS | FPSCR_OFS | FPSCR_UFS |
FPSCR_IXS | FPSCR_HIS | FPSCR_IOC | FPSCR_OFC |
FPSCR_UFC | FPSCR_IXC | FPSCR_HIC);
tmp |= exc;
ctf(FPSCR, tmp);
}
static int __init ucf64_init(void)
{
ctf(FPSCR, 0x0);
printk(KERN_INFO "Enable UniCore-F64 support.\n");
return 0;
}
