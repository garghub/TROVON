static inline unsigned long __kprobes thumb_probe_pc(struct kprobe *p)
{
return (unsigned long)p->addr - 1 + 4;
}
static void __kprobes
t32_simulate_table_branch(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p);
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
unsigned long rnv = (rn == 15) ? pc : regs->uregs[rn];
unsigned long rmv = regs->uregs[rm];
unsigned int halfwords;
if (insn & 0x10)
halfwords = ((u16 *)rnv)[rmv];
else
halfwords = ((u8 *)rnv)[rmv];
regs->ARM_pc = pc + 2 * halfwords;
}
static void __kprobes
t32_simulate_mrs(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rd = (insn >> 8) & 0xf;
unsigned long mask = 0xf8ff03df;
regs->uregs[rd] = regs->ARM_cpsr & mask;
}
static void __kprobes
t32_simulate_cond_branch(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p);
long offset = insn & 0x7ff;
offset += (insn & 0x003f0000) >> 5;
offset += (insn & 0x00002000) << 4;
offset += (insn & 0x00000800) << 7;
offset -= (insn & 0x04000000) >> 7;
regs->ARM_pc = pc + (offset * 2);
}
static enum kprobe_insn __kprobes
t32_decode_cond_branch(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
int cc = (insn >> 22) & 0xf;
asi->insn_check_cc = kprobe_condition_checks[cc];
asi->insn_handler = t32_simulate_cond_branch;
return INSN_GOOD_NO_SLOT;
}
static void __kprobes
t32_simulate_branch(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p);
long offset = insn & 0x7ff;
offset += (insn & 0x03ff0000) >> 5;
offset += (insn & 0x00002000) << 9;
offset += (insn & 0x00000800) << 10;
if (insn & 0x04000000)
offset -= 0x00800000;
else
offset ^= 0x00600000;
if (insn & (1 << 14)) {
regs->ARM_lr = (unsigned long)p->addr + 4;
if (!(insn & (1 << 12))) {
regs->ARM_cpsr &= ~PSR_T_BIT;
pc &= ~3;
}
}
regs->ARM_pc = pc + (offset * 2);
}
static void __kprobes
t32_simulate_ldr_literal(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long addr = thumb_probe_pc(p) & ~3;
int rt = (insn >> 12) & 0xf;
unsigned long rtv;
long offset = insn & 0xfff;
if (insn & 0x00800000)
addr += offset;
else
addr -= offset;
if (insn & 0x00400000) {
rtv = *(unsigned long *)addr;
if (rt == 15) {
bx_write_pc(rtv, regs);
return;
}
} else if (insn & 0x00200000) {
if (insn & 0x01000000)
rtv = *(s16 *)addr;
else
rtv = *(u16 *)addr;
} else {
if (insn & 0x01000000)
rtv = *(s8 *)addr;
else
rtv = *(u8 *)addr;
}
regs->uregs[rt] = rtv;
}
static enum kprobe_insn __kprobes
t32_decode_ldmstm(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
enum kprobe_insn ret = kprobe_decode_ldmstm(insn, asi);
insn = asi->insn[0];
((u16 *)asi->insn)[0] = insn >> 16;
((u16 *)asi->insn)[1] = insn & 0xffff;
return ret;
}
static void __kprobes
t32_emulate_ldrdstrd(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p) & ~3;
int rt1 = (insn >> 12) & 0xf;
int rt2 = (insn >> 8) & 0xf;
int rn = (insn >> 16) & 0xf;
register unsigned long rt1v asm("r0") = regs->uregs[rt1];
register unsigned long rt2v asm("r1") = regs->uregs[rt2];
register unsigned long rnv asm("r2") = (rn == 15) ? pc
: regs->uregs[rn];
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rt1v), "=r" (rt2v), "=r" (rnv)
: "0" (rt1v), "1" (rt2v), "2" (rnv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if (rn != 15)
regs->uregs[rn] = rnv;
regs->uregs[rt1] = rt1v;
regs->uregs[rt2] = rt2v;
}
static void __kprobes
t32_emulate_ldrstr(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rt = (insn >> 12) & 0xf;
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
register unsigned long rtv asm("r0") = regs->uregs[rt];
register unsigned long rnv asm("r2") = regs->uregs[rn];
register unsigned long rmv asm("r3") = regs->uregs[rm];
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rtv), "=r" (rnv)
: "0" (rtv), "1" (rnv), "r" (rmv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rn] = rnv;
if (rt == 15)
bx_write_pc(rtv, regs);
else
regs->uregs[rt] = rtv;
}
static void __kprobes
t32_emulate_rd8rn16rm0_rwflags(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rd = (insn >> 8) & 0xf;
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
register unsigned long rdv asm("r1") = regs->uregs[rd];
register unsigned long rnv asm("r2") = regs->uregs[rn];
register unsigned long rmv asm("r3") = regs->uregs[rm];
unsigned long cpsr = regs->ARM_cpsr;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"blx %[fn] \n\t"
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
t32_emulate_rd8pc16_noflags(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p);
int rd = (insn >> 8) & 0xf;
register unsigned long rdv asm("r1") = regs->uregs[rd];
register unsigned long rnv asm("r2") = pc & ~3;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdv)
: "0" (rdv), "r" (rnv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rd] = rdv;
}
static void __kprobes
t32_emulate_rd8rn16_noflags(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rd = (insn >> 8) & 0xf;
int rn = (insn >> 16) & 0xf;
register unsigned long rdv asm("r1") = regs->uregs[rd];
register unsigned long rnv asm("r2") = regs->uregs[rn];
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdv)
: "0" (rdv), "r" (rnv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rd] = rdv;
}
static void __kprobes
t32_emulate_rdlo12rdhi8rn16rm0_noflags(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rdlo = (insn >> 12) & 0xf;
int rdhi = (insn >> 8) & 0xf;
int rn = (insn >> 16) & 0xf;
int rm = insn & 0xf;
register unsigned long rdlov asm("r0") = regs->uregs[rdlo];
register unsigned long rdhiv asm("r1") = regs->uregs[rdhi];
register unsigned long rnv asm("r2") = regs->uregs[rn];
register unsigned long rmv asm("r3") = regs->uregs[rm];
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdlov), "=r" (rdhiv)
: "0" (rdlov), "1" (rdhiv), "r" (rnv), "r" (rmv),
[fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
regs->uregs[rdlo] = rdlov;
regs->uregs[rdhi] = rdhiv;
}
static void __kprobes
t16_simulate_bxblx(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p);
int rm = (insn >> 3) & 0xf;
unsigned long rmv = (rm == 15) ? pc : regs->uregs[rm];
if (insn & (1 << 7))
regs->ARM_lr = (unsigned long)p->addr + 2;
bx_write_pc(rmv, regs);
}
static void __kprobes
t16_simulate_ldr_literal(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long* base = (unsigned long *)(thumb_probe_pc(p) & ~3);
long index = insn & 0xff;
int rt = (insn >> 8) & 0x7;
regs->uregs[rt] = base[index];
}
static void __kprobes
t16_simulate_ldrstr_sp_relative(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long* base = (unsigned long *)regs->ARM_sp;
long index = insn & 0xff;
int rt = (insn >> 8) & 0x7;
if (insn & 0x800)
regs->uregs[rt] = base[index];
else
base[index] = regs->uregs[rt];
}
static void __kprobes
t16_simulate_reladr(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long base = (insn & 0x800) ? regs->ARM_sp
: (thumb_probe_pc(p) & ~3);
long offset = insn & 0xff;
int rt = (insn >> 8) & 0x7;
regs->uregs[rt] = base + offset * 4;
}
static void __kprobes
t16_simulate_add_sp_imm(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
long imm = insn & 0x7f;
if (insn & 0x80)
regs->ARM_sp -= imm * 4;
else
regs->ARM_sp += imm * 4;
}
static void __kprobes
t16_simulate_cbz(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
int rn = insn & 0x7;
kprobe_opcode_t nonzero = regs->uregs[rn] ? insn : ~insn;
if (nonzero & 0x800) {
long i = insn & 0x200;
long imm5 = insn & 0xf8;
unsigned long pc = thumb_probe_pc(p);
regs->ARM_pc = pc + (i >> 3) + (imm5 >> 2);
}
}
static void __kprobes
t16_simulate_it(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long cpsr = regs->ARM_cpsr;
cpsr &= ~PSR_IT_MASK;
cpsr |= (insn & 0xfc) << 8;
cpsr |= (insn & 0x03) << 25;
regs->ARM_cpsr = cpsr;
}
static void __kprobes
t16_singlestep_it(struct kprobe *p, struct pt_regs *regs)
{
regs->ARM_pc += 2;
t16_simulate_it(p, regs);
}
static enum kprobe_insn __kprobes
t16_decode_it(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
asi->insn_singlestep = t16_singlestep_it;
return INSN_GOOD_NO_SLOT;
}
static void __kprobes
t16_simulate_cond_branch(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p);
long offset = insn & 0x7f;
offset -= insn & 0x80;
regs->ARM_pc = pc + (offset * 2);
}
static enum kprobe_insn __kprobes
t16_decode_cond_branch(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
int cc = (insn >> 8) & 0xf;
asi->insn_check_cc = kprobe_condition_checks[cc];
asi->insn_handler = t16_simulate_cond_branch;
return INSN_GOOD_NO_SLOT;
}
static void __kprobes
t16_simulate_branch(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p);
long offset = insn & 0x3ff;
offset -= insn & 0x400;
regs->ARM_pc = pc + (offset * 2);
}
static unsigned long __kprobes
t16_emulate_loregs(struct kprobe *p, struct pt_regs *regs)
{
unsigned long oldcpsr = regs->ARM_cpsr;
unsigned long newcpsr;
__asm__ __volatile__ (
"msr cpsr_fs, %[oldcpsr] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"mrs %[newcpsr], cpsr \n\t"
: [newcpsr] "=r" (newcpsr)
: [oldcpsr] "r" (oldcpsr), [regs] "r" (regs),
[fn] "r" (p->ainsn.insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
"lr", "memory", "cc"
);
return (oldcpsr & ~APSR_MASK) | (newcpsr & APSR_MASK);
}
static void __kprobes
t16_emulate_loregs_rwflags(struct kprobe *p, struct pt_regs *regs)
{
regs->ARM_cpsr = t16_emulate_loregs(p, regs);
}
static void __kprobes
t16_emulate_loregs_noitrwflags(struct kprobe *p, struct pt_regs *regs)
{
unsigned long cpsr = t16_emulate_loregs(p, regs);
if (!in_it_block(cpsr))
regs->ARM_cpsr = cpsr;
}
static void __kprobes
t16_emulate_hiregs(struct kprobe *p, struct pt_regs *regs)
{
kprobe_opcode_t insn = p->opcode;
unsigned long pc = thumb_probe_pc(p);
int rdn = (insn & 0x7) | ((insn & 0x80) >> 4);
int rm = (insn >> 3) & 0xf;
register unsigned long rdnv asm("r1");
register unsigned long rmv asm("r0");
unsigned long cpsr = regs->ARM_cpsr;
rdnv = (rdn == 15) ? pc : regs->uregs[rdn];
rmv = (rm == 15) ? pc : regs->uregs[rm];
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"blx %[fn] \n\t"
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdnv), [cpsr] "=r" (cpsr)
: "0" (rdnv), "r" (rmv), "1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if (rdn == 15)
rdnv &= ~1;
regs->uregs[rdn] = rdnv;
regs->ARM_cpsr = (regs->ARM_cpsr & ~APSR_MASK) | (cpsr & APSR_MASK);
}
static enum kprobe_insn __kprobes
t16_decode_hiregs(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
insn &= ~0x00ff;
insn |= 0x001;
((u16 *)asi->insn)[0] = insn;
asi->insn_handler = t16_emulate_hiregs;
return INSN_GOOD;
}
static void __kprobes
t16_emulate_push(struct kprobe *p, struct pt_regs *regs)
{
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldr r8, [%[regs], #14*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"str r9, [%[regs], #13*4] \n\t"
:
: [regs] "r" (regs), [fn] "r" (p->ainsn.insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9",
"lr", "memory", "cc"
);
}
static enum kprobe_insn __kprobes
t16_decode_push(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
((u16 *)asi->insn)[0] = 0xe929;
((u16 *)asi->insn)[1] = insn & 0x1ff;
asi->insn_handler = t16_emulate_push;
return INSN_GOOD;
}
static void __kprobes
t16_emulate_pop_nopc(struct kprobe *p, struct pt_regs *regs)
{
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"str r9, [%[regs], #13*4] \n\t"
:
: [regs] "r" (regs), [fn] "r" (p->ainsn.insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r9",
"lr", "memory", "cc"
);
}
static void __kprobes
t16_emulate_pop_pc(struct kprobe *p, struct pt_regs *regs)
{
register unsigned long pc asm("r8");
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"str r9, [%[regs], #13*4] \n\t"
: "=r" (pc)
: [regs] "r" (regs), [fn] "r" (p->ainsn.insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r9",
"lr", "memory", "cc"
);
bx_write_pc(pc, regs);
}
static enum kprobe_insn __kprobes
t16_decode_pop(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
((u16 *)asi->insn)[0] = 0xe8b9;
((u16 *)asi->insn)[1] = insn & 0x1ff;
asi->insn_handler = insn & 0x100 ? t16_emulate_pop_pc
: t16_emulate_pop_nopc;
return INSN_GOOD;
}
static unsigned long __kprobes thumb_check_cc(unsigned long cpsr)
{
if (unlikely(in_it_block(cpsr)))
return kprobe_condition_checks[current_cond(cpsr)](cpsr);
return true;
}
static void __kprobes thumb16_singlestep(struct kprobe *p, struct pt_regs *regs)
{
regs->ARM_pc += 2;
p->ainsn.insn_handler(p, regs);
regs->ARM_cpsr = it_advance(regs->ARM_cpsr);
}
static void __kprobes thumb32_singlestep(struct kprobe *p, struct pt_regs *regs)
{
regs->ARM_pc += 4;
p->ainsn.insn_handler(p, regs);
regs->ARM_cpsr = it_advance(regs->ARM_cpsr);
}
enum kprobe_insn __kprobes
thumb16_kprobe_decode_insn(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
asi->insn_singlestep = thumb16_singlestep;
asi->insn_check_cc = thumb_check_cc;
return kprobe_decode_insn(insn, asi, kprobe_decode_thumb16_table, true);
}
enum kprobe_insn __kprobes
thumb32_kprobe_decode_insn(kprobe_opcode_t insn, struct arch_specific_insn *asi)
{
asi->insn_singlestep = thumb32_singlestep;
asi->insn_check_cc = thumb_check_cc;
return kprobe_decode_insn(insn, asi, kprobe_decode_thumb32_table, true);
}
