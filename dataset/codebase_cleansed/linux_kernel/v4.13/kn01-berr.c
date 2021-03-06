static inline void dec_kn01_be_ack(void)
{
volatile u16 *csr = (void *)CKSEG1ADDR(KN01_SLOT_BASE + KN01_CSR);
unsigned long flags;
raw_spin_lock_irqsave(&kn01_lock, flags);
*csr = cached_kn01_csr | KN01_CSR_MEMERR;
iob();
raw_spin_unlock_irqrestore(&kn01_lock, flags);
}
static int dec_kn01_be_backend(struct pt_regs *regs, int is_fixup, int invoker)
{
volatile u32 *kn01_erraddr = (void *)CKSEG1ADDR(KN01_SLOT_BASE +
KN01_ERRADDR);
static const char excstr[] = "exception";
static const char intstr[] = "interrupt";
static const char cpustr[] = "CPU";
static const char mreadstr[] = "memory read";
static const char readstr[] = "read";
static const char writestr[] = "write";
static const char timestr[] = "timeout";
static const char paritystr[] = "parity error";
int data = regs->cp0_cause & 4;
unsigned int __user *pc = (unsigned int __user *)regs->cp0_epc +
((regs->cp0_cause & CAUSEF_BD) != 0);
union mips_instruction insn;
unsigned long entrylo, offset;
long asid, entryhi, vaddr;
const char *kind, *agent, *cycle, *event;
unsigned long address;
u32 erraddr = *kn01_erraddr;
int action = MIPS_BE_FATAL;
dec_kn01_be_ack();
kind = invoker ? intstr : excstr;
agent = cpustr;
if (invoker)
address = erraddr;
else {
if (data) {
__get_user(insn.word, pc);
vaddr = regs->regs[insn.i_format.rs] +
insn.i_format.simmediate;
} else
vaddr = (long)pc;
if (KSEGX(vaddr) == CKSEG0 || KSEGX(vaddr) == CKSEG1)
address = CPHYSADDR(vaddr);
else {
asid = read_c0_entryhi();
entryhi = asid & (PAGE_SIZE - 1);
entryhi |= vaddr & ~(PAGE_SIZE - 1);
write_c0_entryhi(entryhi);
BARRIER;
tlb_probe();
tlb_read();
entrylo = read_c0_entrylo0();
write_c0_entryhi(asid);
offset = vaddr & (PAGE_SIZE - 1);
address = (entrylo & ~(PAGE_SIZE - 1)) | offset;
}
}
if (address < 0x10000000) {
cycle = mreadstr;
event = paritystr;
} else {
cycle = invoker ? writestr : readstr;
event = timestr;
}
if (is_fixup)
action = MIPS_BE_FIXUP;
if (action != MIPS_BE_FIXUP)
printk(KERN_ALERT "Bus error %s: %s %s %s at %#010lx\n",
kind, agent, cycle, event, address);
return action;
}
int dec_kn01_be_handler(struct pt_regs *regs, int is_fixup)
{
return dec_kn01_be_backend(regs, is_fixup, 0);
}
irqreturn_t dec_kn01_be_interrupt(int irq, void *dev_id)
{
volatile u16 *csr = (void *)CKSEG1ADDR(KN01_SLOT_BASE + KN01_CSR);
struct pt_regs *regs = get_irq_regs();
int action;
if (!(*csr & KN01_CSR_MEMERR))
return IRQ_NONE;
action = dec_kn01_be_backend(regs, 0, 1);
if (action == MIPS_BE_DISCARD)
return IRQ_HANDLED;
printk(KERN_ALERT "Fatal bus interrupt, epc == %08lx, ra == %08lx\n",
regs->cp0_epc, regs->regs[31]);
die("Unrecoverable bus error", regs);
}
void __init dec_kn01_be_init(void)
{
volatile u16 *csr = (void *)CKSEG1ADDR(KN01_SLOT_BASE + KN01_CSR);
unsigned long flags;
raw_spin_lock_irqsave(&kn01_lock, flags);
cached_kn01_csr = *csr;
cached_kn01_csr &= KN01_CSR_STATUS | KN01_CSR_PARDIS | KN01_CSR_TXDIS;
cached_kn01_csr |= KN01_CSR_LEDS;
cached_kn01_csr &= ~KN01_CSR_PARDIS;
*csr = cached_kn01_csr;
iob();
raw_spin_unlock_irqrestore(&kn01_lock, flags);
dec_kn01_be_ack();
}
