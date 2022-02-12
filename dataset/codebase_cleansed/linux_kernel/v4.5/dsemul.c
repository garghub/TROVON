int mips_dsemul(struct pt_regs *regs, mips_instruction ir, unsigned long cpc)
{
int isa16 = get_isa16_mode(regs->cp0_epc);
mips_instruction break_math;
struct emuframe __user *fr;
int err;
if (ir == 0)
return -1;
if (isa16) {
union mips_instruction insn = { .word = ir };
if ((ir >> 16) == MM_NOP16)
return -1;
if (insn.mm_a_format.opcode == mm_addiupc_op) {
unsigned int rs;
s32 v;
rs = (((insn.mm_a_format.rs + 0x1e) & 0xf) + 2);
v = regs->cp0_epc & ~3;
v += insn.mm_a_format.simmediate << 2;
regs->regs[rs] = (long)v;
return -1;
}
}
pr_debug("dsemul %lx %lx\n", regs->cp0_epc, cpc);
break_math = BREAK_MATH(isa16);
fr = (struct emuframe __user *)
((regs->regs[29] - sizeof(struct emuframe)) & ~0x7);
if (unlikely(!access_ok(VERIFY_WRITE, fr, sizeof(struct emuframe))))
return SIGBUS;
if (isa16) {
err = __put_user(ir >> 16,
(u16 __user *)(&fr->emul));
err |= __put_user(ir & 0xffff,
(u16 __user *)((long)(&fr->emul) + 2));
err |= __put_user(break_math >> 16,
(u16 __user *)(&fr->badinst));
err |= __put_user(break_math & 0xffff,
(u16 __user *)((long)(&fr->badinst) + 2));
} else {
err = __put_user(ir, &fr->emul);
err |= __put_user(break_math, &fr->badinst);
}
err |= __put_user((mips_instruction)BD_COOKIE, &fr->cookie);
err |= __put_user(cpc, &fr->epc);
if (unlikely(err)) {
MIPS_FPU_EMU_INC_STATS(errors);
return SIGBUS;
}
regs->cp0_epc = (unsigned long)&fr->emul | isa16;
flush_cache_sigtramp((unsigned long)&fr->emul);
return 0;
}
int do_dsemulret(struct pt_regs *xcp)
{
int isa16 = get_isa16_mode(xcp->cp0_epc);
struct emuframe __user *fr;
unsigned long epc;
u32 insn, cookie;
int err = 0;
u16 instr[2];
fr = (struct emuframe __user *)
(msk_isa16_mode(xcp->cp0_epc) - sizeof(mips_instruction));
if (!access_ok(VERIFY_READ, fr, sizeof(struct emuframe)))
return 0;
if (isa16) {
err = __get_user(instr[0],
(u16 __user *)(&fr->badinst));
err |= __get_user(instr[1],
(u16 __user *)((long)(&fr->badinst) + 2));
insn = (instr[0] << 16) | instr[1];
} else {
err = __get_user(insn, &fr->badinst);
}
err |= __get_user(cookie, &fr->cookie);
if (unlikely(err ||
insn != BREAK_MATH(isa16) || cookie != BD_COOKIE)) {
MIPS_FPU_EMU_INC_STATS(errors);
return 0;
}
pr_debug("dsemulret\n");
if (__get_user(epc, &fr->epc)) {
force_sig(SIGBUS, current);
return 0;
}
xcp->cp0_epc = epc;
MIPS_FPU_EMU_INC_STATS(ds_emul);
return 1;
}
