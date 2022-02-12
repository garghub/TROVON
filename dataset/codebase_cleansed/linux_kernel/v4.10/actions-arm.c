static void __kprobes
emulate_ldrdstrd(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
unsigned long pc = regs->ARM_pc + 4;
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
[fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rt] = rtv;
regs->uregs[rt+1] = rt2v;
if (is_writeback(insn))
regs->uregs[rn] = rnv;
}
static void __kprobes
emulate_ldr(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
unsigned long pc = regs->ARM_pc + 4;
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
: "1" (rnv), "r" (rmv), [fn] "r" (asi->insn_fn)
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
emulate_str(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
unsigned long rtpc = regs->ARM_pc - 4 + str_pc_offset;
unsigned long rnpc = regs->ARM_pc + 4;
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
: "r" (rtv), "0" (rnv), "r" (rmv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
if (is_writeback(insn))
regs->uregs[rn] = rnv;
}
static void __kprobes
emulate_rd12rn16rm0rs8_rwflags(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
unsigned long pc = regs->ARM_pc + 4;
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
"1" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
if (rd == 15)
alu_write_pc(rdv, regs);
else
regs->uregs[rd] = rdv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
static void __kprobes
emulate_rd12rn16rm0_rwflags_nopc(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
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
"1" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rd] = rdv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
static void __kprobes
emulate_rd16rn12rm0rs8_rwflags_nopc(probes_opcode_t insn,
struct arch_probes_insn *asi,
struct pt_regs *regs)
{
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
"1" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rd] = rdv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
static void __kprobes
emulate_rd12rm0_noflags_nopc(probes_opcode_t insn,
struct arch_probes_insn *asi, struct pt_regs *regs)
{
int rd = (insn >> 12) & 0xf;
int rm = insn & 0xf;
register unsigned long rdv asm("r0") = regs->uregs[rd];
register unsigned long rmv asm("r3") = regs->uregs[rm];
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rdv)
: "0" (rdv), "r" (rmv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rd] = rdv;
}
static void __kprobes
emulate_rdlo12rdhi16rn0rm8_rwflags_nopc(probes_opcode_t insn,
struct arch_probes_insn *asi,
struct pt_regs *regs)
{
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
"2" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rdlo] = rdlov;
regs->uregs[rdhi] = rdhiv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
