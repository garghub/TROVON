static void __kprobes simulate_bbl(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
long iaddr = (long)p->addr;
int disp = branch_displacement(insn);
if (insn & (1 << 24))
regs->ARM_lr = iaddr + 4;
regs->ARM_pc = iaddr + 8 + disp;
}
static void __kprobes simulate_blx1(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
long iaddr = (long)p->addr;
int disp = branch_displacement(insn);
regs->ARM_lr = iaddr + 4;
regs->ARM_pc = iaddr + 8 + disp + ((insn >> 23) & 0x2);
regs->ARM_cpsr |= PSR_T_BIT;
}
static void __kprobes simulate_blx2bx(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rm = insn & 0xf;
long rmv = regs->uregs[rm];
if (insn & (1 << 5))
regs->ARM_lr = (long)p->addr + 4;
regs->ARM_pc = rmv & ~0x1;
regs->ARM_cpsr &= ~PSR_T_BIT;
if (rmv & 0x1)
regs->ARM_cpsr |= PSR_T_BIT;
}
static void __kprobes simulate_mrs(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rd = (insn >> 12) & 0xf;
unsigned long mask = 0xf8ff03df;
regs->uregs[rd] = regs->ARM_cpsr & mask;
}
static void __kprobes simulate_mov_ipsp(struct kprobe *p, struct pt_regs *regs)
{
regs->uregs[12] = regs->uregs[13];
}
static void __kprobes
emulate_ldrdstrd(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = (unsigned long)p->addr + 8;
int rt = (insn >> 12) & 0xf;
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
register unsigned long rtv asm("r0") = regs->uregs[rt];
register unsigned long rt2v asm("r1") = regs->uregs[rt+1];
register unsigned long rnv asm("r2") = (rn == 15) ? pc
: regs->uregs[rn];
register unsigned long rmv asm("r3") = regs->uregs[rm];
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rtv), "=r" (rt2v), "=r" (rnv)
: "0" (rtv), "1" (rt2v), "2" (rnv), "r" (rmv),
[fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rt] = rtv;
regs->uregs[rt+1] = rt2v;
if (is_writeback(insn))
regs->uregs[rn] = rnv;
}
static void __kprobes
emulate_ldr(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = (unsigned long)p->addr + 8;
int rt = (insn >> 12) & 0xf;
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
register unsigned long rtv asm("r0");
register unsigned long rnv asm("r2") = (rn == 15) ? pc
: regs->uregs[rn];
register unsigned long rmv asm("r3") = regs->uregs[rm];
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rtv), "=r" (rnv)
: "1" (rnv), "r" (rmv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if (rt == 15)
load_write_pc(rtv, regs);
else
regs->uregs[rt] = rtv;
if (is_writeback(insn))
regs->uregs[rn] = rnv;
}
static void __kprobes
emulate_str(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long rtpc = (unsigned long)p->addr + str_pc_offset;
unsigned long rnpc = (unsigned long)p->addr + 8;
int rt = (insn >> 12) & 0xf;
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
register unsigned long rtv asm("r0") = (rt == 15) ? rtpc
: regs->uregs[rt];
register unsigned long rnv asm("r2") = (rn == 15) ? rnpc
: regs->uregs[rn];
register unsigned long rmv asm("r3") = regs->uregs[rm];
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rnv)
: "r" (rtv), "0" (rnv), "r" (rmv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if (is_writeback(insn))
regs->uregs[rn] = rnv;
}
static void __kprobes
emulate_rd12rn16rm0rs8_rwflags(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = (unsigned long)p->addr + 8;
int rd = (insn >> 12) & 0xf;
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
int rs = (insn >> 8) & 0xf;
register unsigned long rdv asm("r0") = regs->uregs[rd];
register unsigned long rnv asm("r2") = (rn == 15) ? pc
: regs->uregs[rn];
register unsigned long rmv asm("r3") = (rm == 15) ? pc
: regs->uregs[rm];
register unsigned long rsv asm("r1") = regs->uregs[rs];
unsigned long cpsr = regs->ARM_cpsr;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv), "r" (rsv),
"1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if (rd == 15)
alu_write_pc(rdv, regs);
else
regs->uregs[rd] = rdv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
static void __kprobes
emulate_rd12rn16rm0_rwflags_nopc(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rd = (insn >> 12) & 0xf;
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
register unsigned long rdv asm("r0") = regs->uregs[rd];
register unsigned long rnv asm("r2") = regs->uregs[rn];
register unsigned long rmv asm("r3") = regs->uregs[rm];
unsigned long cpsr = regs->ARM_cpsr;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv),
"1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rd] = rdv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
static void __kprobes
emulate_rd16rn12rm0rs8_rwflags_nopc(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rd = (insn >> 16) & 0xf;
int rn = (insn >> 12) & 0xf;
int rm = insn & 0xf;
int rs = (insn >> 8) & 0xf;
register unsigned long rdv asm("r2") = regs->uregs[rd];
register unsigned long rnv asm("r0") = regs->uregs[rn];
register unsigned long rmv asm("r3") = regs->uregs[rm];
register unsigned long rsv asm("r1") = regs->uregs[rs];
unsigned long cpsr = regs->ARM_cpsr;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv), "r" (rsv),
"1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rd] = rdv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
static void __kprobes
emulate_rd12rm0_noflags_nopc(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rd = (insn >> 12) & 0xf;
int rm = insn & 0xf;
register unsigned long rdv asm("r0") = regs->uregs[rd];
register unsigned long rmv asm("r3") = regs->uregs[rm];
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rdv)
: "0" (rdv), "r" (rmv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rd] = rdv;
}
static void __kprobes
emulate_rdlo12rdhi16rn0rm8_rwflags_nopc(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rdlo = (insn >> 12) & 0xf;
int rdhi = (insn >> 16) & 0xf;
int rn = insn & 0xf;
int rm = (insn >> 8) & 0xf;
register unsigned long rdlov asm("r0") = regs->uregs[rdlo];
register unsigned long rdhiv asm("r2") = regs->uregs[rdhi];
register unsigned long rnv asm("r3") = regs->uregs[rn];
register unsigned long rmv asm("r1") = regs->uregs[rm];
unsigned long cpsr = regs->ARM_cpsr;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdlov), "=r" (rdhiv), [cpsr] "=r" (cpsr)
: "0" (rdlov), "1" (rdhiv), "r" (rnv), "r" (rmv),
"2" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rdlo] = rdlov;
regs->uregs[rdhi] = rdhiv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
static void __kprobes arm_singlestep(struct kprobe *p, struct pt_regs *regs)
{
regs->ARM_pc += 4;
p->ainsn.insn_handler(p, regs);
}
enum kprobe_insn __kprobes
arm_kprobe_decode_insn(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
asi->insn_singlestep = arm_singlestep;
asi->insn_check_cc = kprobe_condition_checks[insn>>28];
return kprobe_decode_insn(insn, asi, kprobe_decode_arm_table, false);
}
