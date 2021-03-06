static inline void dec_ecc_be_ack(void)
{
*kn0x_erraddr = 0;
iob();
}
static int dec_ecc_be_backend(struct pt_regs *regs, int is_fixup, int invoker)
{
static const char excstr[] = "exception";
static const char intstr[] = "interrupt";
static const char cpustr[] = "CPU";
static const char dmastr[] = "DMA";
static const char readstr[] = "read";
static const char mreadstr[] = "memory read";
static const char writestr[] = "write";
static const char mwritstr[] = "partial memory write";
static const char timestr[] = "timeout";
static const char overstr[] = "overrun";
static const char eccstr[] = "ECC error";
const char *kind, *agent, *cycle, *event;
const char *status = "", *xbit = "", *fmt = "";
unsigned long address;
u16 syn = 0, sngl;
int i = 0;
u32 erraddr = *kn0x_erraddr;
u32 chksyn = *kn0x_chksyn;
int action = MIPS_BE_FATAL;
if ((erraddr & (KN0X_EAR_VALID | KN0X_EAR_ECCERR)) == KN0X_EAR_VALID)
dec_ecc_be_ack();
kind = invoker ? intstr : excstr;
if (!(erraddr & KN0X_EAR_VALID)) {
printk(KERN_ALERT "Unidentified bus error %s\n", kind);
return action;
}
agent = (erraddr & KN0X_EAR_CPU) ? cpustr : dmastr;
if (erraddr & KN0X_EAR_ECCERR) {
cycle = (erraddr & KN0X_EAR_WRITE) ? mwritstr : mreadstr;
event = eccstr;
} else {
cycle = (erraddr & KN0X_EAR_WRITE) ? writestr : readstr;
event = (erraddr & KN0X_EAR_CPU) ? timestr : overstr;
}
address = erraddr & KN0X_EAR_ADDRESS;
if ((erraddr & (KN0X_EAR_WRITE | KN0X_EAR_ECCERR)) == KN0X_EAR_ECCERR)
address = (address & ~0xfffLL) | ((address - 5) & 0xfffLL);
address <<= 2;
if (erraddr & KN0X_EAR_CPU && is_fixup)
action = MIPS_BE_FIXUP;
if (erraddr & KN0X_EAR_ECCERR) {
static const u8 data_sbit[32] = {
0x4f, 0x4a, 0x52, 0x54, 0x57, 0x58, 0x5b, 0x5d,
0x23, 0x25, 0x26, 0x29, 0x2a, 0x2c, 0x31, 0x34,
0x0e, 0x0b, 0x13, 0x15, 0x16, 0x19, 0x1a, 0x1c,
0x62, 0x64, 0x67, 0x68, 0x6b, 0x6d, 0x70, 0x75,
};
static const u8 data_mbit[25] = {
0x07, 0x0d, 0x1f,
0x2f, 0x32, 0x37, 0x38, 0x3b, 0x3d, 0x3e,
0x43, 0x45, 0x46, 0x49, 0x4c, 0x51, 0x5e,
0x61, 0x6e, 0x73, 0x76, 0x79, 0x7a, 0x7c, 0x7f,
};
static const char sbestr[] = "corrected single";
static const char dbestr[] = "uncorrectable double";
static const char mbestr[] = "uncorrectable multiple";
if (!(address & 0x4))
syn = chksyn;
else
syn = chksyn >> 16;
if (!(syn & KN0X_ESR_VLDLO)) {
dec_ecc_be_ack();
fmt = KERN_ALERT "%s" "invalid\n";
} else {
sngl = syn & KN0X_ESR_SNGLO;
syn &= KN0X_ESR_SYNLO;
for (i = 0; i < 25; i++)
if (syn == data_mbit[i])
break;
if (i < 25) {
status = mbestr;
} else if (!sngl) {
status = dbestr;
} else {
volatile u32 *ptr =
(void *)CKSEG1ADDR(address);
*ptr = *ptr;
iob();
status = sbestr;
action = MIPS_BE_DISCARD;
}
dec_ecc_be_ack();
if (syn && syn == (syn & -syn)) {
if (syn == 0x01) {
fmt = KERN_ALERT "%s"
"%#04x -- %s bit error "
"at check bit C%s\n";
xbit = "X";
} else {
fmt = KERN_ALERT "%s"
"%#04x -- %s bit error "
"at check bit C%s%u\n";
}
i = syn >> 2;
} else {
for (i = 0; i < 32; i++)
if (syn == data_sbit[i])
break;
if (i < 32)
fmt = KERN_ALERT "%s"
"%#04x -- %s bit error "
"at data bit D%s%u\n";
else
fmt = KERN_ALERT "%s"
"%#04x -- %s bit error\n";
}
}
}
if (action != MIPS_BE_FIXUP)
printk(KERN_ALERT "Bus error %s: %s %s %s at %#010lx\n",
kind, agent, cycle, event, address);
if (action != MIPS_BE_FIXUP && erraddr & KN0X_EAR_ECCERR)
printk(fmt, " ECC syndrome ", syn, status, xbit, i);
return action;
}
int dec_ecc_be_handler(struct pt_regs *regs, int is_fixup)
{
return dec_ecc_be_backend(regs, is_fixup, 0);
}
irqreturn_t dec_ecc_be_interrupt(int irq, void *dev_id)
{
struct pt_regs *regs = get_irq_regs();
int action = dec_ecc_be_backend(regs, 0, 1);
if (action == MIPS_BE_DISCARD)
return IRQ_HANDLED;
printk(KERN_ALERT "Fatal bus interrupt, epc == %08lx, ra == %08lx\n",
regs->cp0_epc, regs->regs[31]);
die("Unrecoverable bus error", regs);
}
static inline void dec_kn02_be_init(void)
{
volatile u32 *csr = (void *)CKSEG1ADDR(KN02_SLOT_BASE + KN02_CSR);
kn0x_erraddr = (void *)CKSEG1ADDR(KN02_SLOT_BASE + KN02_ERRADDR);
kn0x_chksyn = (void *)CKSEG1ADDR(KN02_SLOT_BASE + KN02_CHKSYN);
cached_kn02_csr = *csr | KN02_CSR_LEDS;
cached_kn02_csr &= ~(KN02_CSR_DIAGCHK | KN02_CSR_DIAGGEN);
cached_kn02_csr |= KN02_CSR_CORRECT;
*csr = cached_kn02_csr;
iob();
}
static inline void dec_kn03_be_init(void)
{
volatile u32 *mcr = (void *)CKSEG1ADDR(KN03_SLOT_BASE + IOASIC_MCR);
volatile u32 *mbcs = (void *)CKSEG1ADDR(KN4K_SLOT_BASE + KN4K_MB_CSR);
kn0x_erraddr = (void *)CKSEG1ADDR(KN03_SLOT_BASE + IOASIC_ERRADDR);
kn0x_chksyn = (void *)CKSEG1ADDR(KN03_SLOT_BASE + IOASIC_CHKSYN);
*mcr = (*mcr & ~(KN03_MCR_DIAGCHK | KN03_MCR_DIAGGEN)) |
KN03_MCR_CORRECT;
if (current_cpu_type() == CPU_R4400SC)
*mbcs |= KN4K_MB_CSR_EE;
fast_iob();
}
void __init dec_ecc_be_init(void)
{
if (mips_machtype == MACH_DS5000_200)
dec_kn02_be_init();
else
dec_kn03_be_init();
dec_ecc_be_ack();
}
