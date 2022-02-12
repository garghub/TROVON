int
handle_fpe(struct pt_regs *regs)
{
extern void printbinary(unsigned long x, int nbits);
struct siginfo si;
unsigned int orig_sw, sw;
int signalcode;
__u64 frcopy[36];
memcpy(frcopy, regs->fr, sizeof regs->fr);
frcopy[32] = 0;
memcpy(&orig_sw, frcopy, sizeof(orig_sw));
if (FPUDEBUG) {
printk(KERN_DEBUG "FP VZOUICxxxxCQCQCQCQCQCRMxxTDVZOUI ->\n ");
printbinary(orig_sw, 32);
printk(KERN_DEBUG "\n");
}
signalcode = decode_fpu(frcopy, 0x666);
memcpy(&sw, frcopy, sizeof(sw));
if (FPUDEBUG) {
printk(KERN_DEBUG "VZOUICxxxxCQCQCQCQCQCRMxxTDVZOUI decode_fpu returns %d|0x%x\n",
signalcode >> 24, signalcode & 0xffffff);
printbinary(sw, 32);
printk(KERN_DEBUG "\n");
}
memcpy(regs->fr, frcopy, sizeof regs->fr);
if (signalcode != 0) {
si.si_signo = signalcode >> 24;
si.si_errno = 0;
si.si_code = signalcode & 0xffffff;
si.si_addr = (void __user *) regs->iaoq[0];
force_sig_info(si.si_signo, &si, current);
return -1;
}
return signalcode ? -1 : 0;
}
