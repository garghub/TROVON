void decode_address(char *buf, unsigned long address)
{
struct task_struct *p;
struct mm_struct *mm;
unsigned long offset;
struct rb_node *n;
#ifdef CONFIG_KALLSYMS
unsigned long symsize;
const char *symname;
char *modname;
char *delim = ":";
char namebuf[128];
#endif
buf += sprintf(buf, "<0x%08lx> ", address);
#ifdef CONFIG_KALLSYMS
symname = kallsyms_lookup(address, &symsize, &offset, &modname, namebuf);
if (symname) {
if (!modname)
modname = delim = "";
sprintf(buf, "{ %s%s%s%s + 0x%lx }",
delim, modname, delim, symname,
(unsigned long)offset);
return;
}
#endif
if (address >= FIXED_CODE_START && address < FIXED_CODE_END) {
strcat(buf, "/* Maybe fixed code section */");
return;
} else if (address < CONFIG_BOOT_LOAD) {
strcat(buf, "/* Maybe null pointer? */");
return;
} else if (address >= COREMMR_BASE) {
strcat(buf, "/* core mmrs */");
return;
} else if (address >= SYSMMR_BASE) {
strcat(buf, "/* system mmrs */");
return;
} else if (address >= L1_ROM_START && address < L1_ROM_START + L1_ROM_LENGTH) {
strcat(buf, "/* on-chip L1 ROM */");
return;
} else if (address >= L1_SCRATCH_START && address < L1_SCRATCH_START + L1_SCRATCH_LENGTH) {
strcat(buf, "/* on-chip scratchpad */");
return;
} else if (address >= physical_mem_end && address < ASYNC_BANK0_BASE) {
strcat(buf, "/* unconnected memory */");
return;
} else if (address >= ASYNC_BANK3_BASE + ASYNC_BANK3_SIZE && address < BOOT_ROM_START) {
strcat(buf, "/* reserved memory */");
return;
} else if (address >= L1_DATA_A_START && address < L1_DATA_A_START + L1_DATA_A_LENGTH) {
strcat(buf, "/* on-chip Data Bank A */");
return;
} else if (address >= L1_DATA_B_START && address < L1_DATA_B_START + L1_DATA_B_LENGTH) {
strcat(buf, "/* on-chip Data Bank B */");
return;
}
if (oops_in_progress) {
strcat(buf, "/* kernel dynamic memory (maybe user-space) */");
return;
}
read_lock(&tasklist_lock);
for_each_process(p) {
struct task_struct *t;
t = find_lock_task_mm(p);
if (!t)
continue;
mm = t->mm;
if (!down_read_trylock(&mm->mmap_sem))
goto __continue;
for (n = rb_first(&mm->mm_rb); n; n = rb_next(n)) {
struct vm_area_struct *vma;
vma = rb_entry(n, struct vm_area_struct, vm_rb);
if (address >= vma->vm_start && address < vma->vm_end) {
char _tmpbuf[256];
char *name = t->comm;
struct file *file = vma->vm_file;
if (file) {
char *d_name = d_path(&file->f_path, _tmpbuf,
sizeof(_tmpbuf));
if (!IS_ERR(d_name))
name = d_name;
}
if ((unsigned long)current >= FIXED_CODE_START &&
!((unsigned long)current & 0x3)) {
if (current->mm &&
(address > current->mm->start_code) &&
(address < current->mm->end_code))
offset = address - current->mm->start_code;
else
offset = (address - vma->vm_start) +
(vma->vm_pgoff << PAGE_SHIFT);
sprintf(buf, "[ %s + 0x%lx ]", name, offset);
} else
sprintf(buf, "[ %s vma:0x%lx-0x%lx]",
name, vma->vm_start, vma->vm_end);
up_read(&mm->mmap_sem);
task_unlock(t);
if (buf[0] == '\0')
sprintf(buf, "[ %s ] dynamic memory", name);
goto done;
}
}
up_read(&mm->mmap_sem);
__continue:
task_unlock(t);
}
sprintf(buf, "/* kernel dynamic memory */");
done:
read_unlock(&tasklist_lock);
}
bool get_mem16(unsigned short *val, unsigned short *address)
{
unsigned long addr = (unsigned long)address;
if (addr & 0x1)
return false;
switch (bfin_mem_access_type(addr, 2)) {
case BFIN_MEM_ACCESS_CORE:
case BFIN_MEM_ACCESS_CORE_ONLY:
*val = *address;
return true;
case BFIN_MEM_ACCESS_DMA:
dma_memcpy(val, address, 2);
return true;
case BFIN_MEM_ACCESS_ITEST:
isram_memcpy(val, address, 2);
return true;
default:
return false;
}
}
bool get_instruction(unsigned int *val, unsigned short *address)
{
unsigned long addr = (unsigned long)address;
unsigned short opcode0, opcode1;
if (addr & 0x1)
return false;
if (addr >= SYSMMR_BASE)
return false;
if (addr >= L1_SCRATCH_START && addr < L1_SCRATCH_START + L1_SCRATCH_LENGTH)
return false;
if (addr >= BOOT_ROM_START + BOOT_ROM_LENGTH && addr < L1_CODE_START)
return false;
if (!get_mem16(&opcode0, address))
return false;
if ((opcode0 & 0xc000) == 0xc000) {
if (!get_mem16(&opcode1, address + 1))
return false;
*val = (opcode0 << 16) + opcode1;
} else
*val = opcode0;
return true;
}
static void decode_ProgCtrl_0(unsigned int opcode)
{
int poprnd = ((opcode >> ProgCtrl_poprnd_bits) & ProgCtrl_poprnd_mask);
int prgfunc = ((opcode >> ProgCtrl_prgfunc_bits) & ProgCtrl_prgfunc_mask);
if (prgfunc == 0 && poprnd == 0)
pr_cont("NOP");
else if (prgfunc == 1 && poprnd == 0)
pr_cont("RTS");
else if (prgfunc == 1 && poprnd == 1)
pr_cont("RTI");
else if (prgfunc == 1 && poprnd == 2)
pr_cont("RTX");
else if (prgfunc == 1 && poprnd == 3)
pr_cont("RTN");
else if (prgfunc == 1 && poprnd == 4)
pr_cont("RTE");
else if (prgfunc == 2 && poprnd == 0)
pr_cont("IDLE");
else if (prgfunc == 2 && poprnd == 3)
pr_cont("CSYNC");
else if (prgfunc == 2 && poprnd == 4)
pr_cont("SSYNC");
else if (prgfunc == 2 && poprnd == 5)
pr_cont("EMUEXCPT");
else if (prgfunc == 3)
pr_cont("CLI R%i", poprnd);
else if (prgfunc == 4)
pr_cont("STI R%i", poprnd);
else if (prgfunc == 5)
pr_cont("JUMP (P%i)", poprnd);
else if (prgfunc == 6)
pr_cont("CALL (P%i)", poprnd);
else if (prgfunc == 7)
pr_cont("CALL (PC + P%i)", poprnd);
else if (prgfunc == 8)
pr_cont("JUMP (PC + P%i", poprnd);
else if (prgfunc == 9)
pr_cont("RAISE %i", poprnd);
else if (prgfunc == 10)
pr_cont("EXCPT %i", poprnd);
else
pr_cont("0x%04x", opcode);
}
static void decode_BRCC_0(unsigned int opcode)
{
int B = ((opcode >> BRCC_B_bits) & BRCC_B_mask);
int T = ((opcode >> BRCC_T_bits) & BRCC_T_mask);
pr_cont("IF %sCC JUMP pcrel %s", T ? "" : "!", B ? "(BP)" : "");
}
static void decode_CALLa_0(unsigned int opcode)
{
int S = ((opcode >> (CALLa_S_bits - 16)) & CALLa_S_mask);
if (S)
pr_cont("CALL pcrel");
else
pr_cont("JUMP.L");
}
static void decode_LoopSetup_0(unsigned int opcode)
{
int c = ((opcode >> LoopSetup_c_bits) & LoopSetup_c_mask);
int reg = ((opcode >> LoopSetup_reg_bits) & LoopSetup_reg_mask);
int rop = ((opcode >> LoopSetup_rop_bits) & LoopSetup_rop_mask);
pr_cont("LSETUP <> LC%i", c);
if ((rop & 1) == 1)
pr_cont("= P%i", reg);
if ((rop & 2) == 2)
pr_cont(" >> 0x1");
}
static void decode_dspLDST_0(unsigned int opcode)
{
int i = ((opcode >> DspLDST_i_bits) & DspLDST_i_mask);
int m = ((opcode >> DspLDST_m_bits) & DspLDST_m_mask);
int W = ((opcode >> DspLDST_W_bits) & DspLDST_W_mask);
int aop = ((opcode >> DspLDST_aop_bits) & DspLDST_aop_mask);
int reg = ((opcode >> DspLDST_reg_bits) & DspLDST_reg_mask);
if (W == 0) {
pr_cont("R%i", reg);
switch (m) {
case 0:
pr_cont(" = ");
break;
case 1:
pr_cont(".L = ");
break;
case 2:
pr_cont(".W = ");
break;
}
}
pr_cont("[ I%i", i);
switch (aop) {
case 0:
pr_cont("++ ]");
break;
case 1:
pr_cont("-- ]");
break;
}
if (W == 1) {
pr_cont(" = R%i", reg);
switch (m) {
case 1:
pr_cont(".L = ");
break;
case 2:
pr_cont(".W = ");
break;
}
}
}
static void decode_LDST_0(unsigned int opcode)
{
int Z = ((opcode >> LDST_Z_bits) & LDST_Z_mask);
int W = ((opcode >> LDST_W_bits) & LDST_W_mask);
int sz = ((opcode >> LDST_sz_bits) & LDST_sz_mask);
int aop = ((opcode >> LDST_aop_bits) & LDST_aop_mask);
int reg = ((opcode >> LDST_reg_bits) & LDST_reg_mask);
int ptr = ((opcode >> LDST_ptr_bits) & LDST_ptr_mask);
if (W == 0)
pr_cont("%s%i = ", (sz == 0 && Z == 1) ? "P" : "R", reg);
switch (sz) {
case 1:
pr_cont("W");
break;
case 2:
pr_cont("B");
break;
}
pr_cont("[P%i", ptr);
switch (aop) {
case 0:
pr_cont("++");
break;
case 1:
pr_cont("--");
break;
}
pr_cont("]");
if (W == 1)
pr_cont(" = %s%i ", (sz == 0 && Z == 1) ? "P" : "R", reg);
if (sz) {
if (Z)
pr_cont(" (X)");
else
pr_cont(" (Z)");
}
}
static void decode_LDSTii_0(unsigned int opcode)
{
int reg = ((opcode >> LDSTii_reg_bit) & LDSTii_reg_mask);
int ptr = ((opcode >> LDSTii_ptr_bit) & LDSTii_ptr_mask);
int offset = ((opcode >> LDSTii_offset_bit) & LDSTii_offset_mask);
int op = ((opcode >> LDSTii_op_bit) & LDSTii_op_mask);
int W = ((opcode >> LDSTii_W_bit) & LDSTii_W_mask);
if (W == 0) {
pr_cont("%s%i = %s[P%i + %i]", op == 3 ? "R" : "P", reg,
op == 1 || op == 2 ? "" : "W", ptr, offset);
if (op == 2)
pr_cont("(Z)");
if (op == 3)
pr_cont("(X)");
} else {
pr_cont("%s[P%i + %i] = %s%i", op == 0 ? "" : "W", ptr,
offset, op == 3 ? "P" : "R", reg);
}
}
static void decode_LDSTidxI_0(unsigned int opcode)
{
int Z = ((opcode >> LDSTidxI_Z_bits) & LDSTidxI_Z_mask);
int W = ((opcode >> LDSTidxI_W_bits) & LDSTidxI_W_mask);
int sz = ((opcode >> LDSTidxI_sz_bits) & LDSTidxI_sz_mask);
int reg = ((opcode >> LDSTidxI_reg_bits) & LDSTidxI_reg_mask);
int ptr = ((opcode >> LDSTidxI_ptr_bits) & LDSTidxI_ptr_mask);
int offset = ((opcode >> LDSTidxI_offset_bits) & LDSTidxI_offset_mask);
if (W == 0)
pr_cont("%s%i = ", sz == 0 && Z == 1 ? "P" : "R", reg);
if (sz == 1)
pr_cont("W");
if (sz == 2)
pr_cont("B");
pr_cont("[P%i + %s0x%x]", ptr, offset & 0x20 ? "-" : "",
(offset & 0x1f) << 2);
if (W == 0 && sz != 0) {
if (Z)
pr_cont("(X)");
else
pr_cont("(Z)");
}
if (W == 1)
pr_cont("= %s%i", (sz == 0 && Z == 1) ? "P" : "R", reg);
}
static void decode_opcode(unsigned int opcode)
{
#ifdef CONFIG_BUG
if (opcode == BFIN_BUG_OPCODE)
pr_cont("BUG");
else
#endif
if ((opcode & 0xffffff00) == ProgCtrl_opcode)
decode_ProgCtrl_0(opcode);
else if ((opcode & 0xfffff000) == BRCC_opcode)
decode_BRCC_0(opcode);
else if ((opcode & 0xfffff000) == 0x2000)
pr_cont("JUMP.S");
else if ((opcode & 0xfe000000) == CALLa_opcode)
decode_CALLa_0(opcode);
else if ((opcode & 0xff8000C0) == LoopSetup_opcode)
decode_LoopSetup_0(opcode);
else if ((opcode & 0xfffffc00) == DspLDST_opcode)
decode_dspLDST_0(opcode);
else if ((opcode & 0xfffff000) == LDST_opcode)
decode_LDST_0(opcode);
else if ((opcode & 0xffffe000) == LDSTii_opcode)
decode_LDSTii_0(opcode);
else if ((opcode & 0xfc000000) == LDSTidxI_opcode)
decode_LDSTidxI_0(opcode);
else if (opcode & 0xffff0000)
pr_cont("0x%08x", opcode);
else
pr_cont("0x%04x", opcode);
}
static void decode_instruction(unsigned short *address)
{
unsigned int opcode;
if (!get_instruction(&opcode, address))
return;
decode_opcode(opcode);
if ((opcode & 0xc0000000) == 0xc0000000 &&
(opcode & BIT_MULTI_INS) &&
(opcode & 0xe8000000) != 0xe8000000) {
pr_cont(" || ");
if (!get_instruction(&opcode, address + 2))
return;
decode_opcode(opcode);
pr_cont(" || ");
if (!get_instruction(&opcode, address + 3))
return;
decode_opcode(opcode);
}
}
void dump_bfin_trace_buffer(void)
{
#ifdef CONFIG_DEBUG_BFIN_HWTRACE_ON
int tflags, i = 0, fault = 0;
char buf[150];
unsigned short *addr;
unsigned int cpu = raw_smp_processor_id();
#ifdef CONFIG_DEBUG_BFIN_HWTRACE_EXPAND
int j, index;
#endif
trace_buffer_save(tflags);
pr_notice("Hardware Trace:\n");
#ifdef CONFIG_DEBUG_BFIN_HWTRACE_EXPAND
pr_notice("WARNING: Expanded trace turned on - can not trace exceptions\n");
#endif
if (likely(bfin_read_TBUFSTAT() & TBUFCNT)) {
for (; bfin_read_TBUFSTAT() & TBUFCNT; i++) {
addr = (unsigned short *)bfin_read_TBUF();
decode_address(buf, (unsigned long)addr);
pr_notice("%4i Target : %s\n", i, buf);
if (!fault && addr == ((unsigned short *)evt_ivhw)) {
addr = (unsigned short *)bfin_read_TBUF();
decode_address(buf, (unsigned long)addr);
pr_notice(" FAULT : %s ", buf);
decode_instruction(addr);
pr_cont("\n");
fault = 1;
continue;
}
if (!fault && addr == (unsigned short *)trap &&
(cpu_pda[cpu].seqstat & SEQSTAT_EXCAUSE) > VEC_EXCPT15) {
decode_address(buf, cpu_pda[cpu].icplb_fault_addr);
pr_notice(" FAULT : %s ", buf);
decode_instruction((unsigned short *)cpu_pda[cpu].icplb_fault_addr);
pr_cont("\n");
fault = 1;
}
addr = (unsigned short *)bfin_read_TBUF();
decode_address(buf, (unsigned long)addr);
pr_notice(" Source : %s ", buf);
decode_instruction(addr);
pr_cont("\n");
}
}
#ifdef CONFIG_DEBUG_BFIN_HWTRACE_EXPAND
if (trace_buff_offset)
index = trace_buff_offset / 4;
else
index = EXPAND_LEN;
j = (1 << CONFIG_DEBUG_BFIN_HWTRACE_EXPAND_LEN) * 128;
while (j) {
decode_address(buf, software_trace_buff[index]);
pr_notice("%4i Target : %s\n", i, buf);
index -= 1;
if (index < 0)
index = EXPAND_LEN;
decode_address(buf, software_trace_buff[index]);
pr_notice(" Source : %s ", buf);
decode_instruction((unsigned short *)software_trace_buff[index]);
pr_cont("\n");
index -= 1;
if (index < 0)
index = EXPAND_LEN;
j--;
i++;
}
#endif
trace_buffer_restore(tflags);
#endif
}
void dump_bfin_process(struct pt_regs *fp)
{
unsigned int context = bfin_read_IPEND();
if (oops_in_progress)
pr_emerg("Kernel OOPS in progress\n");
if (context & 0x0020 && (fp->seqstat & SEQSTAT_EXCAUSE) == VEC_HWERR)
pr_notice("HW Error context\n");
else if (context & 0x0020)
pr_notice("Deferred Exception context\n");
else if (context & 0x3FC0)
pr_notice("Interrupt context\n");
else if (context & 0x4000)
pr_notice("Deferred Interrupt context\n");
else if (context & 0x8000)
pr_notice("Kernel process context\n");
if ((unsigned long)current >= FIXED_CODE_START &&
!((unsigned long)current & 0x3) && current->pid) {
pr_notice("CURRENT PROCESS:\n");
if (current->comm >= (char *)FIXED_CODE_START)
pr_notice("COMM=%s PID=%d",
current->comm, current->pid);
else
pr_notice("COMM= invalid");
pr_cont(" CPU=%d\n", current_thread_info()->cpu);
if (!((unsigned long)current->mm & 0x3) &&
(unsigned long)current->mm >= FIXED_CODE_START) {
pr_notice("TEXT = 0x%p-0x%p DATA = 0x%p-0x%p\n",
(void *)current->mm->start_code,
(void *)current->mm->end_code,
(void *)current->mm->start_data,
(void *)current->mm->end_data);
pr_notice(" BSS = 0x%p-0x%p USER-STACK = 0x%p\n\n",
(void *)current->mm->end_data,
(void *)current->mm->brk,
(void *)current->mm->start_stack);
} else
pr_notice("invalid mm\n");
} else
pr_notice("No Valid process in current context\n");
}
void dump_bfin_mem(struct pt_regs *fp)
{
unsigned short *addr, *erraddr, val = 0, err = 0;
char sti = 0, buf[6];
erraddr = (void *)fp->pc;
pr_notice("return address: [0x%p]; contents of:", erraddr);
for (addr = (unsigned short *)((unsigned long)erraddr & ~0xF) - 0x10;
addr < (unsigned short *)((unsigned long)erraddr & ~0xF) + 0x10;
addr++) {
if (!((unsigned long)addr & 0xF))
pr_notice("0x%p: ", addr);
if (!get_mem16(&val, addr)) {
val = 0;
sprintf(buf, "????");
} else
sprintf(buf, "%04x", val);
if (addr == erraddr) {
pr_cont("[%s]", buf);
err = val;
} else
pr_cont(" %s ", buf);
if (addr <= erraddr &&
((val >= 0x0040 && val <= 0x0047) ||
val == 0x017b))
sti = 1;
}
pr_cont("\n");
if (unlikely(sti && (fp->seqstat & SEQSTAT_EXCAUSE) == VEC_HWERR &&
oops_in_progress)){
pr_notice("Looks like this was a deferred error - sorry\n");
#ifndef CONFIG_DEBUG_HWERR
pr_notice("The remaining message may be meaningless\n");
pr_notice("You should enable CONFIG_DEBUG_HWERR to get a better idea where it came from\n");
#else
if ((!(((fp)->ipend & ~0x30) & (((fp)->ipend & ~0x30) - 1))) &&
(current->pid && current->mm)) {
if ((fp + 1)->pc >= current->mm->start_code &&
(fp + 1)->pc <= current->mm->end_code) {
pr_notice("It might be better to look around here :\n");
pr_notice("-------------------------------------------\n");
show_regs(fp + 1);
pr_notice("-------------------------------------------\n");
}
}
#endif
}
}
void show_regs(struct pt_regs *fp)
{
char buf[150];
struct irqaction *action;
unsigned int i;
unsigned long flags = 0;
unsigned int cpu = raw_smp_processor_id();
unsigned char in_atomic = (bfin_read_IPEND() & 0x10) || in_atomic();
pr_notice("\n");
if (CPUID != bfin_cpuid())
pr_notice("Compiled for cpu family 0x%04x (Rev %d), "
"but running on:0x%04x (Rev %d)\n",
CPUID, bfin_compiled_revid(), bfin_cpuid(), bfin_revid());
pr_notice("ADSP-%s-0.%d",
CPU, bfin_compiled_revid());
if (bfin_compiled_revid() != bfin_revid())
pr_cont("(Detected 0.%d)", bfin_revid());
pr_cont(" %lu(MHz CCLK) %lu(MHz SCLK) (%s)\n",
get_cclk()/1000000, get_sclk()/1000000,
#ifdef CONFIG_MPU
"mpu on"
#else
"mpu off"
#endif
);
pr_notice("%s", linux_banner);
pr_notice("\nSEQUENCER STATUS:\t\t%s\n", print_tainted());
pr_notice(" SEQSTAT: %08lx IPEND: %04lx IMASK: %04lx SYSCFG: %04lx\n",
(long)fp->seqstat, fp->ipend, cpu_pda[raw_smp_processor_id()].ex_imask, fp->syscfg);
if (fp->ipend & EVT_IRPTEN)
pr_notice(" Global Interrupts Disabled (IPEND[4])\n");
if (!(cpu_pda[raw_smp_processor_id()].ex_imask & (EVT_IVG13 | EVT_IVG12 | EVT_IVG11 |
EVT_IVG10 | EVT_IVG9 | EVT_IVG8 | EVT_IVG7 | EVT_IVTMR)))
pr_notice(" Peripheral interrupts masked off\n");
if (!(cpu_pda[raw_smp_processor_id()].ex_imask & (EVT_IVG15 | EVT_IVG14)))
pr_notice(" Kernel interrupts masked off\n");
if ((fp->seqstat & SEQSTAT_EXCAUSE) == VEC_HWERR) {
pr_notice(" HWERRCAUSE: 0x%lx\n",
(fp->seqstat & SEQSTAT_HWERRCAUSE) >> 14);
#ifdef EBIU_ERRMST
if (bfin_read_EBIU_ERRMST() & CORE_ERROR) {
pr_notice(" EBIU Error Reason : 0x%04x\n",
bfin_read_EBIU_ERRMST());
pr_notice(" EBIU Error Address : 0x%08x\n",
bfin_read_EBIU_ERRADD());
}
#endif
}
pr_notice(" EXCAUSE : 0x%lx\n",
fp->seqstat & SEQSTAT_EXCAUSE);
for (i = 2; i <= 15 ; i++) {
if (fp->ipend & (1 << i)) {
if (i != 4) {
decode_address(buf, bfin_read32(EVT0 + 4*i));
pr_notice(" physical IVG%i asserted : %s\n", i, buf);
} else
pr_notice(" interrupts disabled\n");
}
}
if (fp->ipend & ~0x3F) {
for (i = 0; i < (NR_IRQS - 1); i++) {
struct irq_desc *desc = irq_to_desc(i);
if (!in_atomic)
raw_spin_lock_irqsave(&desc->lock, flags);
action = desc->action;
if (!action)
goto unlock;
decode_address(buf, (unsigned int)action->handler);
pr_notice(" logical irq %3d mapped : %s", i, buf);
for (action = action->next; action; action = action->next) {
decode_address(buf, (unsigned int)action->handler);
pr_cont(", %s", buf);
}
pr_cont("\n");
unlock:
if (!in_atomic)
raw_spin_unlock_irqrestore(&desc->lock, flags);
}
}
decode_address(buf, fp->rete);
pr_notice(" RETE: %s\n", buf);
decode_address(buf, fp->retn);
pr_notice(" RETN: %s\n", buf);
decode_address(buf, fp->retx);
pr_notice(" RETX: %s\n", buf);
decode_address(buf, fp->rets);
pr_notice(" RETS: %s\n", buf);
decode_address(buf, fp->pc);
pr_notice(" PC : %s\n", buf);
if (((long)fp->seqstat & SEQSTAT_EXCAUSE) &&
(((long)fp->seqstat & SEQSTAT_EXCAUSE) != VEC_HWERR)) {
decode_address(buf, cpu_pda[cpu].dcplb_fault_addr);
pr_notice("DCPLB_FAULT_ADDR: %s\n", buf);
decode_address(buf, cpu_pda[cpu].icplb_fault_addr);
pr_notice("ICPLB_FAULT_ADDR: %s\n", buf);
}
pr_notice("PROCESSOR STATE:\n");
pr_notice(" R0 : %08lx R1 : %08lx R2 : %08lx R3 : %08lx\n",
fp->r0, fp->r1, fp->r2, fp->r3);
pr_notice(" R4 : %08lx R5 : %08lx R6 : %08lx R7 : %08lx\n",
fp->r4, fp->r5, fp->r6, fp->r7);
pr_notice(" P0 : %08lx P1 : %08lx P2 : %08lx P3 : %08lx\n",
fp->p0, fp->p1, fp->p2, fp->p3);
pr_notice(" P4 : %08lx P5 : %08lx FP : %08lx SP : %08lx\n",
fp->p4, fp->p5, fp->fp, (long)fp);
pr_notice(" LB0: %08lx LT0: %08lx LC0: %08lx\n",
fp->lb0, fp->lt0, fp->lc0);
pr_notice(" LB1: %08lx LT1: %08lx LC1: %08lx\n",
fp->lb1, fp->lt1, fp->lc1);
pr_notice(" B0 : %08lx L0 : %08lx M0 : %08lx I0 : %08lx\n",
fp->b0, fp->l0, fp->m0, fp->i0);
pr_notice(" B1 : %08lx L1 : %08lx M1 : %08lx I1 : %08lx\n",
fp->b1, fp->l1, fp->m1, fp->i1);
pr_notice(" B2 : %08lx L2 : %08lx M2 : %08lx I2 : %08lx\n",
fp->b2, fp->l2, fp->m2, fp->i2);
pr_notice(" B3 : %08lx L3 : %08lx M3 : %08lx I3 : %08lx\n",
fp->b3, fp->l3, fp->m3, fp->i3);
pr_notice("A0.w: %08lx A0.x: %08lx A1.w: %08lx A1.x: %08lx\n",
fp->a0w, fp->a0x, fp->a1w, fp->a1x);
pr_notice("USP : %08lx ASTAT: %08lx\n",
rdusp(), fp->astat);
pr_notice("\n");
}
