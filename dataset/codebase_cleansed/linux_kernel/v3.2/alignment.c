static bool cpu_is_v6_unaligned(void)
{
return cpu_architecture() >= CPU_ARCH_ARMv6 && (cr_alignment & CR_U);
}
static int safe_usermode(int new_usermode, bool warn)
{
if (cpu_is_v6_unaligned() && !(new_usermode & (UM_FIXUP | UM_SIGNAL))) {
new_usermode |= UM_FIXUP;
if (warn)
printk(KERN_WARNING "alignment: ignoring faults is unsafe on this CPU. Defaulting to fixup mode.\n");
}
return new_usermode;
}
static int alignment_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "User:\t\t%lu\n", ai_user);
seq_printf(m, "System:\t\t%lu\n", ai_sys);
seq_printf(m, "Skipped:\t%lu\n", ai_skipped);
seq_printf(m, "Half:\t\t%lu\n", ai_half);
seq_printf(m, "Word:\t\t%lu\n", ai_word);
if (cpu_architecture() >= CPU_ARCH_ARMv5TE)
seq_printf(m, "DWord:\t\t%lu\n", ai_dword);
seq_printf(m, "Multi:\t\t%lu\n", ai_multi);
seq_printf(m, "User faults:\t%i (%s)\n", ai_usermode,
usermode_action[ai_usermode]);
return 0;
}
static int alignment_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, alignment_proc_show, NULL);
}
static ssize_t alignment_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
char mode;
if (count > 0) {
if (get_user(mode, buffer))
return -EFAULT;
if (mode >= '0' && mode <= '5')
ai_usermode = safe_usermode(mode - '0', true);
}
return count;
}
static void
do_alignment_finish_ldst(unsigned long addr, unsigned long instr, struct pt_regs *regs, union offset_union offset)
{
if (!LDST_U_BIT(instr))
offset.un = -offset.un;
if (!LDST_P_BIT(instr))
addr += offset.un;
if (!LDST_P_BIT(instr) || LDST_W_BIT(instr))
regs->uregs[RN_BITS(instr)] = addr;
}
static int
do_alignment_ldrhstrh(unsigned long addr, unsigned long instr, struct pt_regs *regs)
{
unsigned int rd = RD_BITS(instr);
ai_half += 1;
if (user_mode(regs))
goto user;
if (LDST_L_BIT(instr)) {
unsigned long val;
get16_unaligned_check(val, addr);
if (instr & 0x40)
val = (signed long)((signed short) val);
regs->uregs[rd] = val;
} else
put16_unaligned_check(regs->uregs[rd], addr);
return TYPE_LDST;
user:
if (LDST_L_BIT(instr)) {
unsigned long val;
get16t_unaligned_check(val, addr);
if (instr & 0x40)
val = (signed long)((signed short) val);
regs->uregs[rd] = val;
} else
put16t_unaligned_check(regs->uregs[rd], addr);
return TYPE_LDST;
fault:
return TYPE_FAULT;
}
static int
do_alignment_ldrdstrd(unsigned long addr, unsigned long instr,
struct pt_regs *regs)
{
unsigned int rd = RD_BITS(instr);
unsigned int rd2;
int load;
if ((instr & 0xfe000000) == 0xe8000000) {
rd2 = (instr >> 8) & 0xf;
load = !!(LDST_L_BIT(instr));
} else if (((rd & 1) == 1) || (rd == 14))
goto bad;
else {
load = ((instr & 0xf0) == 0xd0);
rd2 = rd + 1;
}
ai_dword += 1;
if (user_mode(regs))
goto user;
if (load) {
unsigned long val;
get32_unaligned_check(val, addr);
regs->uregs[rd] = val;
get32_unaligned_check(val, addr + 4);
regs->uregs[rd2] = val;
} else {
put32_unaligned_check(regs->uregs[rd], addr);
put32_unaligned_check(regs->uregs[rd2], addr + 4);
}
return TYPE_LDST;
user:
if (load) {
unsigned long val;
get32t_unaligned_check(val, addr);
regs->uregs[rd] = val;
get32t_unaligned_check(val, addr + 4);
regs->uregs[rd2] = val;
} else {
put32t_unaligned_check(regs->uregs[rd], addr);
put32t_unaligned_check(regs->uregs[rd2], addr + 4);
}
return TYPE_LDST;
bad:
return TYPE_ERROR;
fault:
return TYPE_FAULT;
}
static int
do_alignment_ldrstr(unsigned long addr, unsigned long instr, struct pt_regs *regs)
{
unsigned int rd = RD_BITS(instr);
ai_word += 1;
if ((!LDST_P_BIT(instr) && LDST_W_BIT(instr)) || user_mode(regs))
goto trans;
if (LDST_L_BIT(instr)) {
unsigned int val;
get32_unaligned_check(val, addr);
regs->uregs[rd] = val;
} else
put32_unaligned_check(regs->uregs[rd], addr);
return TYPE_LDST;
trans:
if (LDST_L_BIT(instr)) {
unsigned int val;
get32t_unaligned_check(val, addr);
regs->uregs[rd] = val;
} else
put32t_unaligned_check(regs->uregs[rd], addr);
return TYPE_LDST;
fault:
return TYPE_FAULT;
}
static int
do_alignment_ldmstm(unsigned long addr, unsigned long instr, struct pt_regs *regs)
{
unsigned int rd, rn, correction, nr_regs, regbits;
unsigned long eaddr, newaddr;
if (LDM_S_BIT(instr))
goto bad;
correction = 4;
regs->ARM_pc += correction;
ai_multi += 1;
nr_regs = hweight16(REGMASK_BITS(instr)) * 4;
rn = RN_BITS(instr);
newaddr = eaddr = regs->uregs[rn];
if (!LDST_U_BIT(instr))
nr_regs = -nr_regs;
newaddr += nr_regs;
if (!LDST_U_BIT(instr))
eaddr = newaddr;
if (LDST_P_EQ_U(instr))
eaddr += 4;
#if !(defined CONFIG_CPU_ARM922T) && !(defined CONFIG_CPU_ARM920T)
if (addr != eaddr) {
printk(KERN_ERR "LDMSTM: PC = %08lx, instr = %08lx, "
"addr = %08lx, eaddr = %08lx\n",
instruction_pointer(regs), instr, addr, eaddr);
show_regs(regs);
}
#endif
if (user_mode(regs)) {
for (regbits = REGMASK_BITS(instr), rd = 0; regbits;
regbits >>= 1, rd += 1)
if (regbits & 1) {
if (LDST_L_BIT(instr)) {
unsigned int val;
get32t_unaligned_check(val, eaddr);
regs->uregs[rd] = val;
} else
put32t_unaligned_check(regs->uregs[rd], eaddr);
eaddr += 4;
}
} else {
for (regbits = REGMASK_BITS(instr), rd = 0; regbits;
regbits >>= 1, rd += 1)
if (regbits & 1) {
if (LDST_L_BIT(instr)) {
unsigned int val;
get32_unaligned_check(val, eaddr);
regs->uregs[rd] = val;
} else
put32_unaligned_check(regs->uregs[rd], eaddr);
eaddr += 4;
}
}
if (LDST_W_BIT(instr))
regs->uregs[rn] = newaddr;
if (!LDST_L_BIT(instr) || !(REGMASK_BITS(instr) & (1 << 15)))
regs->ARM_pc -= correction;
return TYPE_DONE;
fault:
regs->ARM_pc -= correction;
return TYPE_FAULT;
bad:
printk(KERN_ERR "Alignment trap: not handling ldm with s-bit set\n");
return TYPE_ERROR;
}
static unsigned long
thumb2arm(u16 tinstr)
{
u32 L = (tinstr & (1<<11)) >> 11;
switch ((tinstr & 0xf800) >> 11) {
case 0x6000 >> 11:
case 0x6800 >> 11:
case 0x7000 >> 11:
case 0x7800 >> 11:
return 0xe5800000 |
((tinstr & (1<<12)) << (22-12)) |
(L<<20) |
((tinstr & (7<<0)) << (12-0)) |
((tinstr & (7<<3)) << (16-3)) |
((tinstr & (31<<6)) >>
(6 - ((tinstr & (1<<12)) ? 0 : 2)));
case 0x8000 >> 11:
case 0x8800 >> 11:
return 0xe1c000b0 |
(L<<20) |
((tinstr & (7<<0)) << (12-0)) |
((tinstr & (7<<3)) << (16-3)) |
((tinstr & (7<<6)) >> (6-1)) |
((tinstr & (3<<9)) >> (9-8));
case 0x5000 >> 11:
case 0x5800 >> 11:
{
static const u32 subset[8] = {
0xe7800000,
0xe18000b0,
0xe7c00000,
0xe19000d0,
0xe7900000,
0xe19000b0,
0xe7d00000,
0xe19000f0
};
return subset[(tinstr & (7<<9)) >> 9] |
((tinstr & (7<<0)) << (12-0)) |
((tinstr & (7<<3)) << (16-3)) |
((tinstr & (7<<6)) >> (6-0));
}
case 0x4800 >> 11:
return 0xe59f0000 |
((tinstr & (7<<8)) << (12-8)) |
((tinstr & 255) << (2-0));
case 0x9000 >> 11:
case 0x9800 >> 11:
return 0xe58d0000 |
(L<<20) |
((tinstr & (7<<8)) << (12-8)) |
((tinstr & 255) << 2);
case 0xc000 >> 11:
case 0xc800 >> 11:
{
u32 Rn = (tinstr & (7<<8)) >> 8;
u32 W = ((L<<Rn) & (tinstr&255)) ? 0 : 1<<21;
return 0xe8800000 | W | (L<<20) | (Rn<<16) |
(tinstr&255);
}
case 0xb000 >> 11:
case 0xb800 >> 11:
if ((tinstr & (3 << 9)) == 0x0400) {
static const u32 subset[4] = {
0xe92d0000,
0xe92d4000,
0xe8bd0000,
0xe8bd8000
};
return subset[(L<<1) | ((tinstr & (1<<8)) >> 8)] |
(tinstr & 255);
}
default:
return BAD_INSTR;
}
}
static void *
do_alignment_t32_to_handler(unsigned long *pinstr, struct pt_regs *regs,
union offset_union *poffset)
{
unsigned long instr = *pinstr;
u16 tinst1 = (instr >> 16) & 0xffff;
u16 tinst2 = instr & 0xffff;
poffset->un = 0;
switch (tinst1 & 0xffe0) {
case 0xe880:
case 0xe8a0:
case 0xe900:
case 0xe920:
return do_alignment_ldmstm;
case 0xf840:
if (RN_BITS(instr) == 13 && (tinst2 & 0x09ff) == 0x0904) {
u32 L = !!(LDST_L_BIT(instr));
const u32 subset[2] = {
0xe92d0000,
0xe8bd0000,
};
*pinstr = subset[L] | (1<<RD_BITS(instr));
return do_alignment_ldmstm;
}
break;
case 0xe860:
case 0xe960:
case 0xe8e0:
case 0xe9e0:
poffset->un = (tinst2 & 0xff) << 2;
case 0xe940:
case 0xe9c0:
return do_alignment_ldrdstrd;
default:
break;
}
return NULL;
}
static int
do_alignment(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
union offset_union offset;
unsigned long instr = 0, instrptr;
int (*handler)(unsigned long addr, unsigned long instr, struct pt_regs *regs);
unsigned int type;
mm_segment_t fs;
unsigned int fault;
u16 tinstr = 0;
int isize = 4;
int thumb2_32b = 0;
if (interrupts_enabled(regs))
local_irq_enable();
instrptr = instruction_pointer(regs);
fs = get_fs();
set_fs(KERNEL_DS);
if (thumb_mode(regs)) {
fault = __get_user(tinstr, (u16 *)(instrptr & ~1));
if (!fault) {
if (cpu_architecture() >= CPU_ARCH_ARMv7 &&
IS_T32(tinstr)) {
u16 tinst2 = 0;
fault = __get_user(tinst2, (u16 *)(instrptr+2));
instr = (tinstr << 16) | tinst2;
thumb2_32b = 1;
} else {
isize = 2;
instr = thumb2arm(tinstr);
}
}
} else
fault = __get_user(instr, (u32 *)instrptr);
set_fs(fs);
if (fault) {
type = TYPE_FAULT;
goto bad_or_fault;
}
if (user_mode(regs))
goto user;
ai_sys += 1;
fixup:
regs->ARM_pc += isize;
switch (CODING_BITS(instr)) {
case 0x00000000:
if (LDSTHD_I_BIT(instr))
offset.un = (instr & 0xf00) >> 4 | (instr & 15);
else
offset.un = regs->uregs[RM_BITS(instr)];
if ((instr & 0x000000f0) == 0x000000b0 ||
(instr & 0x001000f0) == 0x001000f0)
handler = do_alignment_ldrhstrh;
else if ((instr & 0x001000f0) == 0x000000d0 ||
(instr & 0x001000f0) == 0x000000f0)
handler = do_alignment_ldrdstrd;
else if ((instr & 0x01f00ff0) == 0x01000090)
goto swp;
else
goto bad;
break;
case 0x04000000:
offset.un = OFFSET_BITS(instr);
handler = do_alignment_ldrstr;
break;
case 0x06000000:
offset.un = regs->uregs[RM_BITS(instr)];
if (IS_SHIFT(instr)) {
unsigned int shiftval = SHIFT_BITS(instr);
switch(SHIFT_TYPE(instr)) {
case SHIFT_LSL:
offset.un <<= shiftval;
break;
case SHIFT_LSR:
offset.un >>= shiftval;
break;
case SHIFT_ASR:
offset.sn >>= shiftval;
break;
case SHIFT_RORRRX:
if (shiftval == 0) {
offset.un >>= 1;
if (regs->ARM_cpsr & PSR_C_BIT)
offset.un |= 1 << 31;
} else
offset.un = offset.un >> shiftval |
offset.un << (32 - shiftval);
break;
}
}
handler = do_alignment_ldrstr;
break;
case 0x08000000:
if (thumb2_32b)
handler = do_alignment_t32_to_handler(&instr, regs, &offset);
else
handler = do_alignment_ldmstm;
break;
default:
goto bad;
}
if (!handler)
goto bad;
type = handler(addr, instr, regs);
if (type == TYPE_ERROR || type == TYPE_FAULT) {
regs->ARM_pc -= isize;
goto bad_or_fault;
}
if (type == TYPE_LDST)
do_alignment_finish_ldst(addr, instr, regs, offset);
return 0;
bad_or_fault:
if (type == TYPE_ERROR)
goto bad;
do_bad_area(addr, fsr, regs);
return 0;
swp:
printk(KERN_ERR "Alignment trap: not handling swp instruction\n");
bad:
printk(KERN_ERR "Alignment trap: not handling instruction "
"%0*lx at [<%08lx>]\n",
isize << 1,
isize == 2 ? tinstr : instr, instrptr);
ai_skipped += 1;
return 1;
user:
ai_user += 1;
if (ai_usermode & UM_WARN)
printk("Alignment trap: %s (%d) PC=0x%08lx Instr=0x%0*lx "
"Address=0x%08lx FSR 0x%03x\n", current->comm,
task_pid_nr(current), instrptr,
isize << 1,
isize == 2 ? tinstr : instr,
addr, fsr);
if (ai_usermode & UM_FIXUP)
goto fixup;
if (ai_usermode & UM_SIGNAL) {
siginfo_t si;
si.si_signo = SIGBUS;
si.si_errno = 0;
si.si_code = BUS_ADRALN;
si.si_addr = (void __user *)addr;
force_sig_info(si.si_signo, &si, current);
} else {
raw_local_irq_disable();
if (!(current_thread_info()->flags & _TIF_WORK_MASK))
set_cr(cr_no_alignment);
}
return 0;
}
static int __init alignment_init(void)
{
#ifdef CONFIG_PROC_FS
struct proc_dir_entry *res;
res = proc_create("cpu/alignment", S_IWUSR | S_IRUGO, NULL,
&alignment_proc_fops);
if (!res)
return -ENOMEM;
#endif
if (cpu_is_v6_unaligned()) {
cr_alignment &= ~CR_A;
cr_no_alignment &= ~CR_A;
set_cr(cr_alignment);
ai_usermode = safe_usermode(ai_usermode, false);
}
hook_fault_code(1, do_alignment, SIGBUS, BUS_ADRALN,
"alignment exception");
if (cpu_architecture() <= CPU_ARCH_ARMv6) {
hook_fault_code(3, do_alignment, SIGBUS, BUS_ADRALN,
"alignment exception");
}
return 0;
}
