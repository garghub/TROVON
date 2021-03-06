static void dump_tl1_traplog(struct tl1_traplog *p)
{
int i, limit;
printk(KERN_EMERG "TRAPLOG: Error at trap level 0x%lx, "
"dumping track stack.\n", p->tl);
limit = (tlb_type == hypervisor) ? 2 : 4;
for (i = 0; i < limit; i++) {
printk(KERN_EMERG
"TRAPLOG: Trap level %d TSTATE[%016lx] TPC[%016lx] "
"TNPC[%016lx] TT[%lx]\n",
i + 1,
p->trapstack[i].tstate, p->trapstack[i].tpc,
p->trapstack[i].tnpc, p->trapstack[i].tt);
printk("TRAPLOG: TPC<%pS>\n", (void *) p->trapstack[i].tpc);
}
}
void bad_trap(struct pt_regs *regs, long lvl)
{
char buffer[32];
siginfo_t info;
if (notify_die(DIE_TRAP, "bad trap", regs,
0, lvl, SIGTRAP) == NOTIFY_STOP)
return;
if (lvl < 0x100) {
sprintf(buffer, "Bad hw trap %lx at tl0\n", lvl);
die_if_kernel(buffer, regs);
}
lvl -= 0x100;
if (regs->tstate & TSTATE_PRIV) {
sprintf(buffer, "Kernel bad sw trap %lx", lvl);
die_if_kernel(buffer, regs);
}
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_ILLTRP;
info.si_addr = (void __user *)regs->tpc;
info.si_trapno = lvl;
force_sig_info(SIGILL, &info, current);
}
void bad_trap_tl1(struct pt_regs *regs, long lvl)
{
char buffer[32];
if (notify_die(DIE_TRAP_TL1, "bad trap tl1", regs,
0, lvl, SIGTRAP) == NOTIFY_STOP)
return;
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
sprintf (buffer, "Bad trap %lx at tl>0", lvl);
die_if_kernel (buffer, regs);
}
void do_BUG(const char *file, int line)
{
bust_spinlocks(1);
printk("kernel BUG at %s:%d!\n", file, line);
}
static int sprintf_dimm(int synd_code, unsigned long paddr, char *buf, int buflen)
{
unsigned long flags;
int ret = -ENODEV;
spin_lock_irqsave(&dimm_handler_lock, flags);
if (dimm_handler) {
ret = dimm_handler(synd_code, paddr, buf, buflen);
} else if (tlb_type == spitfire) {
if (prom_getunumber(synd_code, paddr, buf, buflen) == -1)
ret = -EINVAL;
else
ret = 0;
} else
ret = -ENODEV;
spin_unlock_irqrestore(&dimm_handler_lock, flags);
return ret;
}
int register_dimm_printer(dimm_printer_t func)
{
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&dimm_handler_lock, flags);
if (!dimm_handler)
dimm_handler = func;
else
ret = -EEXIST;
spin_unlock_irqrestore(&dimm_handler_lock, flags);
return ret;
}
void unregister_dimm_printer(dimm_printer_t func)
{
unsigned long flags;
spin_lock_irqsave(&dimm_handler_lock, flags);
if (dimm_handler == func)
dimm_handler = NULL;
spin_unlock_irqrestore(&dimm_handler_lock, flags);
}
void spitfire_insn_access_exception(struct pt_regs *regs, unsigned long sfsr, unsigned long sfar)
{
enum ctx_state prev_state = exception_enter();
siginfo_t info;
if (notify_die(DIE_TRAP, "instruction access exception", regs,
0, 0x8, SIGTRAP) == NOTIFY_STOP)
goto out;
if (regs->tstate & TSTATE_PRIV) {
printk("spitfire_insn_access_exception: SFSR[%016lx] "
"SFAR[%016lx], going.\n", sfsr, sfar);
die_if_kernel("Iax", regs);
}
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_code = SEGV_MAPERR;
info.si_addr = (void __user *)regs->tpc;
info.si_trapno = 0;
force_sig_info(SIGSEGV, &info, current);
out:
exception_exit(prev_state);
}
void spitfire_insn_access_exception_tl1(struct pt_regs *regs, unsigned long sfsr, unsigned long sfar)
{
if (notify_die(DIE_TRAP_TL1, "instruction access exception tl1", regs,
0, 0x8, SIGTRAP) == NOTIFY_STOP)
return;
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
spitfire_insn_access_exception(regs, sfsr, sfar);
}
void sun4v_insn_access_exception(struct pt_regs *regs, unsigned long addr, unsigned long type_ctx)
{
unsigned short type = (type_ctx >> 16);
unsigned short ctx = (type_ctx & 0xffff);
siginfo_t info;
if (notify_die(DIE_TRAP, "instruction access exception", regs,
0, 0x8, SIGTRAP) == NOTIFY_STOP)
return;
if (regs->tstate & TSTATE_PRIV) {
printk("sun4v_insn_access_exception: ADDR[%016lx] "
"CTX[%04x] TYPE[%04x], going.\n",
addr, ctx, type);
die_if_kernel("Iax", regs);
}
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_code = SEGV_MAPERR;
info.si_addr = (void __user *) addr;
info.si_trapno = 0;
force_sig_info(SIGSEGV, &info, current);
}
void sun4v_insn_access_exception_tl1(struct pt_regs *regs, unsigned long addr, unsigned long type_ctx)
{
if (notify_die(DIE_TRAP_TL1, "instruction access exception tl1", regs,
0, 0x8, SIGTRAP) == NOTIFY_STOP)
return;
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
sun4v_insn_access_exception(regs, addr, type_ctx);
}
void spitfire_data_access_exception(struct pt_regs *regs, unsigned long sfsr, unsigned long sfar)
{
enum ctx_state prev_state = exception_enter();
siginfo_t info;
if (notify_die(DIE_TRAP, "data access exception", regs,
0, 0x30, SIGTRAP) == NOTIFY_STOP)
goto out;
if (regs->tstate & TSTATE_PRIV) {
const struct exception_table_entry *entry;
entry = search_exception_tables(regs->tpc);
if (entry) {
#ifdef DEBUG_EXCEPTIONS
printk("Exception: PC<%016lx> faddr<UNKNOWN>\n", regs->tpc);
printk("EX_TABLE: insn<%016lx> fixup<%016lx>\n",
regs->tpc, entry->fixup);
#endif
regs->tpc = entry->fixup;
regs->tnpc = regs->tpc + 4;
goto out;
}
printk("spitfire_data_access_exception: SFSR[%016lx] "
"SFAR[%016lx], going.\n", sfsr, sfar);
die_if_kernel("Dax", regs);
}
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_code = SEGV_MAPERR;
info.si_addr = (void __user *)sfar;
info.si_trapno = 0;
force_sig_info(SIGSEGV, &info, current);
out:
exception_exit(prev_state);
}
void spitfire_data_access_exception_tl1(struct pt_regs *regs, unsigned long sfsr, unsigned long sfar)
{
if (notify_die(DIE_TRAP_TL1, "data access exception tl1", regs,
0, 0x30, SIGTRAP) == NOTIFY_STOP)
return;
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
spitfire_data_access_exception(regs, sfsr, sfar);
}
void sun4v_data_access_exception(struct pt_regs *regs, unsigned long addr, unsigned long type_ctx)
{
unsigned short type = (type_ctx >> 16);
unsigned short ctx = (type_ctx & 0xffff);
siginfo_t info;
if (notify_die(DIE_TRAP, "data access exception", regs,
0, 0x8, SIGTRAP) == NOTIFY_STOP)
return;
if (regs->tstate & TSTATE_PRIV) {
const struct exception_table_entry *entry;
entry = search_exception_tables(regs->tpc);
if (entry) {
#ifdef DEBUG_EXCEPTIONS
printk("Exception: PC<%016lx> faddr<UNKNOWN>\n", regs->tpc);
printk("EX_TABLE: insn<%016lx> fixup<%016lx>\n",
regs->tpc, entry->fixup);
#endif
regs->tpc = entry->fixup;
regs->tnpc = regs->tpc + 4;
return;
}
printk("sun4v_data_access_exception: ADDR[%016lx] "
"CTX[%04x] TYPE[%04x], going.\n",
addr, ctx, type);
die_if_kernel("Dax", regs);
}
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_code = SEGV_MAPERR;
info.si_addr = (void __user *) addr;
info.si_trapno = 0;
force_sig_info(SIGSEGV, &info, current);
}
void sun4v_data_access_exception_tl1(struct pt_regs *regs, unsigned long addr, unsigned long type_ctx)
{
if (notify_die(DIE_TRAP_TL1, "data access exception tl1", regs,
0, 0x8, SIGTRAP) == NOTIFY_STOP)
return;
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
sun4v_data_access_exception(regs, addr, type_ctx);
}
static void spitfire_clean_and_reenable_l1_caches(void)
{
unsigned long va;
if (tlb_type != spitfire)
BUG();
for (va = 0; va < (PAGE_SIZE << 1); va += 32) {
spitfire_put_icache_tag(va, 0x0);
spitfire_put_dcache_tag(va, 0x0);
}
__asm__ __volatile__("flush %%g6\n\t"
"membar #Sync\n\t"
"stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (LSU_CONTROL_IC | LSU_CONTROL_DC |
LSU_CONTROL_IM | LSU_CONTROL_DM),
"i" (ASI_LSU_CONTROL)
: "memory");
}
static void spitfire_enable_estate_errors(void)
{
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (ESTATE_ERR_ALL),
"i" (ASI_ESTATE_ERROR_EN));
}
static void spitfire_log_udb_syndrome(unsigned long afar, unsigned long udbh, unsigned long udbl, unsigned long bit)
{
unsigned short scode;
char memmod_str[64], *p;
if (udbl & bit) {
scode = ecc_syndrome_table[udbl & 0xff];
if (sprintf_dimm(scode, afar, memmod_str, sizeof(memmod_str)) < 0)
p = syndrome_unknown;
else
p = memmod_str;
printk(KERN_WARNING "CPU[%d]: UDBL Syndrome[%x] "
"Memory Module \"%s\"\n",
smp_processor_id(), scode, p);
}
if (udbh & bit) {
scode = ecc_syndrome_table[udbh & 0xff];
if (sprintf_dimm(scode, afar, memmod_str, sizeof(memmod_str)) < 0)
p = syndrome_unknown;
else
p = memmod_str;
printk(KERN_WARNING "CPU[%d]: UDBH Syndrome[%x] "
"Memory Module \"%s\"\n",
smp_processor_id(), scode, p);
}
}
static void spitfire_cee_log(unsigned long afsr, unsigned long afar, unsigned long udbh, unsigned long udbl, int tl1, struct pt_regs *regs)
{
printk(KERN_WARNING "CPU[%d]: Correctable ECC Error "
"AFSR[%lx] AFAR[%016lx] UDBL[%lx] UDBH[%lx] TL>1[%d]\n",
smp_processor_id(), afsr, afar, udbl, udbh, tl1);
spitfire_log_udb_syndrome(afar, udbh, udbl, UDBE_CE);
notify_die(DIE_TRAP, "Correctable ECC Error", regs,
0, TRAP_TYPE_CEE, SIGTRAP);
spitfire_enable_estate_errors();
}
static void spitfire_ue_log(unsigned long afsr, unsigned long afar, unsigned long udbh, unsigned long udbl, unsigned long tt, int tl1, struct pt_regs *regs)
{
siginfo_t info;
printk(KERN_WARNING "CPU[%d]: Uncorrectable Error AFSR[%lx] "
"AFAR[%lx] UDBL[%lx] UDBH[%ld] TT[%lx] TL>1[%d]\n",
smp_processor_id(), afsr, afar, udbl, udbh, tt, tl1);
spitfire_log_udb_syndrome(afar, udbh, udbl, UDBE_UE);
notify_die(DIE_TRAP, "Uncorrectable Error", regs,
0, tt, SIGTRAP);
if (regs->tstate & TSTATE_PRIV) {
if (tl1)
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("UE", regs);
}
spitfire_clean_and_reenable_l1_caches();
spitfire_enable_estate_errors();
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGBUS;
info.si_errno = 0;
info.si_code = BUS_OBJERR;
info.si_addr = (void *)0;
info.si_trapno = 0;
force_sig_info(SIGBUS, &info, current);
}
void spitfire_access_error(struct pt_regs *regs, unsigned long status_encoded, unsigned long afar)
{
unsigned long afsr, tt, udbh, udbl;
int tl1;
afsr = (status_encoded & SFSTAT_AFSR_MASK) >> SFSTAT_AFSR_SHIFT;
tt = (status_encoded & SFSTAT_TRAP_TYPE) >> SFSTAT_TRAP_TYPE_SHIFT;
tl1 = (status_encoded & SFSTAT_TL_GT_ONE) ? 1 : 0;
udbl = (status_encoded & SFSTAT_UDBL_MASK) >> SFSTAT_UDBL_SHIFT;
udbh = (status_encoded & SFSTAT_UDBH_MASK) >> SFSTAT_UDBH_SHIFT;
#ifdef CONFIG_PCI
if (tt == TRAP_TYPE_DAE &&
pci_poke_in_progress && pci_poke_cpu == smp_processor_id()) {
spitfire_clean_and_reenable_l1_caches();
spitfire_enable_estate_errors();
pci_poke_faulted = 1;
regs->tnpc = regs->tpc + 4;
return;
}
#endif
if (afsr & SFAFSR_UE)
spitfire_ue_log(afsr, afar, udbh, udbl, tt, tl1, regs);
if (tt == TRAP_TYPE_CEE) {
if (afsr & SFAFSR_UE) {
if (udbh & UDBE_CE) {
__asm__ __volatile__(
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (udbh & UDBE_CE),
"r" (0x0), "i" (ASI_UDB_ERROR_W));
}
if (udbl & UDBE_CE) {
__asm__ __volatile__(
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (udbl & UDBE_CE),
"r" (0x18), "i" (ASI_UDB_ERROR_W));
}
}
spitfire_cee_log(afsr, afar, udbh, udbl, tl1, regs);
}
}
void cheetah_enable_pcache(void)
{
unsigned long dcr;
printk("CHEETAH: Enabling P-Cache on cpu %d.\n",
smp_processor_id());
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dcr)
: "i" (ASI_DCU_CONTROL_REG));
dcr |= (DCU_PE | DCU_HPE | DCU_SPE | DCU_SL);
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (dcr), "i" (ASI_DCU_CONTROL_REG));
}
static inline struct cheetah_err_info *cheetah_get_error_log(unsigned long afsr)
{
struct cheetah_err_info *p;
int cpu = smp_processor_id();
if (!cheetah_error_log)
return NULL;
p = cheetah_error_log + (cpu * 2);
if ((afsr & CHAFSR_TL1) != 0UL)
p++;
return p;
}
void __init cheetah_ecache_flush_init(void)
{
unsigned long largest_size, smallest_linesize, order, ver;
int i, sz;
largest_size = 0UL;
smallest_linesize = ~0UL;
for (i = 0; i < NR_CPUS; i++) {
unsigned long val;
val = cpu_data(i).ecache_size;
if (!val)
continue;
if (val > largest_size)
largest_size = val;
val = cpu_data(i).ecache_line_size;
if (val < smallest_linesize)
smallest_linesize = val;
}
if (largest_size == 0UL || smallest_linesize == ~0UL) {
prom_printf("cheetah_ecache_flush_init: Cannot probe cpu E-cache "
"parameters.\n");
prom_halt();
}
ecache_flush_size = (2 * largest_size);
ecache_flush_linesize = smallest_linesize;
ecache_flush_physbase = find_ecache_flush_span(ecache_flush_size);
if (ecache_flush_physbase == ~0UL) {
prom_printf("cheetah_ecache_flush_init: Cannot find %ld byte "
"contiguous physical memory.\n",
ecache_flush_size);
prom_halt();
}
sz = NR_CPUS * (2 * sizeof(struct cheetah_err_info));
for (order = 0; order < MAX_ORDER; order++) {
if ((PAGE_SIZE << order) >= sz)
break;
}
cheetah_error_log = (struct cheetah_err_info *)
__get_free_pages(GFP_KERNEL, order);
if (!cheetah_error_log) {
prom_printf("cheetah_ecache_flush_init: Failed to allocate "
"error logging scoreboard (%d bytes).\n", sz);
prom_halt();
}
memset(cheetah_error_log, 0, PAGE_SIZE << order);
for (i = 0; i < 2 * NR_CPUS; i++)
cheetah_error_log[i].afsr = CHAFSR_INVALID;
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
if ((ver >> 32) == __JALAPENO_ID ||
(ver >> 32) == __SERRANO_ID) {
cheetah_error_table = &__jalapeno_error_table[0];
cheetah_afsr_errors = JPAFSR_ERRORS;
} else if ((ver >> 32) == 0x003e0015) {
cheetah_error_table = &__cheetah_plus_error_table[0];
cheetah_afsr_errors = CHPAFSR_ERRORS;
} else {
cheetah_error_table = &__cheetah_error_table[0];
cheetah_afsr_errors = CHAFSR_ERRORS;
}
memcpy(tl0_fecc, cheetah_fecc_trap_vector, (8 * 4));
memcpy(tl1_fecc, cheetah_fecc_trap_vector_tl1, (8 * 4));
memcpy(tl0_cee, cheetah_cee_trap_vector, (8 * 4));
memcpy(tl1_cee, cheetah_cee_trap_vector_tl1, (8 * 4));
memcpy(tl0_iae, cheetah_deferred_trap_vector, (8 * 4));
memcpy(tl1_iae, cheetah_deferred_trap_vector_tl1, (8 * 4));
memcpy(tl0_dae, cheetah_deferred_trap_vector, (8 * 4));
memcpy(tl1_dae, cheetah_deferred_trap_vector_tl1, (8 * 4));
if (tlb_type == cheetah_plus) {
memcpy(tl0_dcpe, cheetah_plus_dcpe_trap_vector, (8 * 4));
memcpy(tl1_dcpe, cheetah_plus_dcpe_trap_vector_tl1, (8 * 4));
memcpy(tl0_icpe, cheetah_plus_icpe_trap_vector, (8 * 4));
memcpy(tl1_icpe, cheetah_plus_icpe_trap_vector_tl1, (8 * 4));
}
flushi(PAGE_OFFSET);
}
static void cheetah_flush_ecache(void)
{
unsigned long flush_base = ecache_flush_physbase;
unsigned long flush_linesize = ecache_flush_linesize;
unsigned long flush_size = ecache_flush_size;
__asm__ __volatile__("1: subcc %0, %4, %0\n\t"
" bne,pt %%xcc, 1b\n\t"
" ldxa [%2 + %0] %3, %%g0\n\t"
: "=&r" (flush_size)
: "0" (flush_size), "r" (flush_base),
"i" (ASI_PHYS_USE_EC), "r" (flush_linesize));
}
static void cheetah_flush_ecache_line(unsigned long physaddr)
{
unsigned long alias;
physaddr &= ~(8UL - 1UL);
physaddr = (ecache_flush_physbase +
(physaddr & ((ecache_flush_size>>1UL) - 1UL)));
alias = physaddr + (ecache_flush_size >> 1UL);
__asm__ __volatile__("ldxa [%0] %2, %%g0\n\t"
"ldxa [%1] %2, %%g0\n\t"
"membar #Sync"
:
: "r" (physaddr), "r" (alias),
"i" (ASI_PHYS_USE_EC));
}
static void __cheetah_flush_icache(void)
{
unsigned int icache_size, icache_line_size;
unsigned long addr;
icache_size = local_cpu_data().icache_size;
icache_line_size = local_cpu_data().icache_line_size;
for (addr = 0; addr < icache_size; addr += icache_line_size) {
__asm__ __volatile__("stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (addr | (2 << 3)),
"i" (ASI_IC_TAG));
}
}
static void cheetah_flush_icache(void)
{
unsigned long dcu_save;
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
"or %0, %2, %%g1\n\t"
"stxa %%g1, [%%g0] %1\n\t"
"membar #Sync"
: "=r" (dcu_save)
: "i" (ASI_DCU_CONTROL_REG), "i" (DCU_IC)
: "g1");
__cheetah_flush_icache();
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
:
: "r" (dcu_save), "i" (ASI_DCU_CONTROL_REG));
}
static void cheetah_flush_dcache(void)
{
unsigned int dcache_size, dcache_line_size;
unsigned long addr;
dcache_size = local_cpu_data().dcache_size;
dcache_line_size = local_cpu_data().dcache_line_size;
for (addr = 0; addr < dcache_size; addr += dcache_line_size) {
__asm__ __volatile__("stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (addr), "i" (ASI_DCACHE_TAG));
}
}
static void cheetah_plus_zap_dcache_parity(void)
{
unsigned int dcache_size, dcache_line_size;
unsigned long addr;
dcache_size = local_cpu_data().dcache_size;
dcache_line_size = local_cpu_data().dcache_line_size;
for (addr = 0; addr < dcache_size; addr += dcache_line_size) {
unsigned long tag = (addr >> 14);
unsigned long line;
__asm__ __volatile__("membar #Sync\n\t"
"stxa %0, [%1] %2\n\t"
"membar #Sync"
:
: "r" (tag), "r" (addr),
"i" (ASI_DCACHE_UTAG));
for (line = addr; line < addr + dcache_line_size; line += 8)
__asm__ __volatile__("membar #Sync\n\t"
"stxa %%g0, [%0] %1\n\t"
"membar #Sync"
:
: "r" (line),
"i" (ASI_DCACHE_DATA));
}
}
static inline unsigned long cheetah_get_hipri(unsigned long afsr)
{
unsigned long tmp = 0;
int i;
for (i = 0; cheetah_error_table[i].mask; i++) {
if ((tmp = (afsr & cheetah_error_table[i].mask)) != 0UL)
return tmp;
}
return tmp;
}
static const char *cheetah_get_string(unsigned long bit)
{
int i;
for (i = 0; cheetah_error_table[i].mask; i++) {
if ((bit & cheetah_error_table[i].mask) != 0UL)
return cheetah_error_table[i].name;
}
return "???";
}
static void cheetah_log_errors(struct pt_regs *regs, struct cheetah_err_info *info,
unsigned long afsr, unsigned long afar, int recoverable)
{
unsigned long hipri;
char unum[256];
printk("%s" "ERROR(%d): Cheetah error trap taken afsr[%016lx] afar[%016lx] TL1(%d)\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
afsr, afar,
(afsr & CHAFSR_TL1) ? 1 : 0);
printk("%s" "ERROR(%d): TPC[%lx] TNPC[%lx] O7[%lx] TSTATE[%lx]\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
regs->tpc, regs->tnpc, regs->u_regs[UREG_I7], regs->tstate);
printk("%s" "ERROR(%d): ",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id());
printk("TPC<%pS>\n", (void *) regs->tpc);
printk("%s" "ERROR(%d): M_SYND(%lx), E_SYND(%lx)%s%s\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
(afsr & CHAFSR_M_SYNDROME) >> CHAFSR_M_SYNDROME_SHIFT,
(afsr & CHAFSR_E_SYNDROME) >> CHAFSR_E_SYNDROME_SHIFT,
(afsr & CHAFSR_ME) ? ", Multiple Errors" : "",
(afsr & CHAFSR_PRIV) ? ", Privileged" : "");
hipri = cheetah_get_hipri(afsr);
printk("%s" "ERROR(%d): Highest priority error (%016lx) \"%s\"\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
hipri, cheetah_get_string(hipri));
#define ESYND_ERRORS (CHAFSR_IVC | CHAFSR_IVU | \
CHAFSR_CPC | CHAFSR_CPU | \
CHAFSR_UE | CHAFSR_CE | \
CHAFSR_EDC | CHAFSR_EDU | \
CHAFSR_UCC | CHAFSR_UCU | \
CHAFSR_WDU | CHAFSR_WDC)
#define MSYND_ERRORS (CHAFSR_EMC | CHAFSR_EMU)
if (afsr & ESYND_ERRORS) {
int syndrome;
int ret;
syndrome = (afsr & CHAFSR_E_SYNDROME) >> CHAFSR_E_SYNDROME_SHIFT;
syndrome = cheetah_ecc_syntab[syndrome];
ret = sprintf_dimm(syndrome, afar, unum, sizeof(unum));
if (ret != -1)
printk("%s" "ERROR(%d): AFAR E-syndrome [%s]\n",
(recoverable ? KERN_WARNING : KERN_CRIT),
smp_processor_id(), unum);
} else if (afsr & MSYND_ERRORS) {
int syndrome;
int ret;
syndrome = (afsr & CHAFSR_M_SYNDROME) >> CHAFSR_M_SYNDROME_SHIFT;
syndrome = cheetah_mtag_syntab[syndrome];
ret = sprintf_dimm(syndrome, afar, unum, sizeof(unum));
if (ret != -1)
printk("%s" "ERROR(%d): AFAR M-syndrome [%s]\n",
(recoverable ? KERN_WARNING : KERN_CRIT),
smp_processor_id(), unum);
}
printk("%s" "ERROR(%d): D-cache idx[%x] tag[%016llx] utag[%016llx] stag[%016llx]\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
(int) info->dcache_index,
info->dcache_tag,
info->dcache_utag,
info->dcache_stag);
printk("%s" "ERROR(%d): D-cache data0[%016llx] data1[%016llx] data2[%016llx] data3[%016llx]\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
info->dcache_data[0],
info->dcache_data[1],
info->dcache_data[2],
info->dcache_data[3]);
printk("%s" "ERROR(%d): I-cache idx[%x] tag[%016llx] utag[%016llx] stag[%016llx] "
"u[%016llx] l[%016llx]\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
(int) info->icache_index,
info->icache_tag,
info->icache_utag,
info->icache_stag,
info->icache_upper,
info->icache_lower);
printk("%s" "ERROR(%d): I-cache INSN0[%016llx] INSN1[%016llx] INSN2[%016llx] INSN3[%016llx]\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
info->icache_data[0],
info->icache_data[1],
info->icache_data[2],
info->icache_data[3]);
printk("%s" "ERROR(%d): I-cache INSN4[%016llx] INSN5[%016llx] INSN6[%016llx] INSN7[%016llx]\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
info->icache_data[4],
info->icache_data[5],
info->icache_data[6],
info->icache_data[7]);
printk("%s" "ERROR(%d): E-cache idx[%x] tag[%016llx]\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
(int) info->ecache_index, info->ecache_tag);
printk("%s" "ERROR(%d): E-cache data0[%016llx] data1[%016llx] data2[%016llx] data3[%016llx]\n",
(recoverable ? KERN_WARNING : KERN_CRIT), smp_processor_id(),
info->ecache_data[0],
info->ecache_data[1],
info->ecache_data[2],
info->ecache_data[3]);
afsr = (afsr & ~hipri) & cheetah_afsr_errors;
while (afsr != 0UL) {
unsigned long bit = cheetah_get_hipri(afsr);
printk("%s" "ERROR: Multiple-error (%016lx) \"%s\"\n",
(recoverable ? KERN_WARNING : KERN_CRIT),
bit, cheetah_get_string(bit));
afsr &= ~bit;
}
if (!recoverable)
printk(KERN_CRIT "ERROR: This condition is not recoverable.\n");
}
static int cheetah_recheck_errors(struct cheetah_err_info *logp)
{
unsigned long afsr, afar;
int ret = 0;
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
: "=r" (afsr)
: "i" (ASI_AFSR));
if ((afsr & cheetah_afsr_errors) != 0) {
if (logp != NULL) {
__asm__ __volatile__("ldxa [%%g0] %1, %0\n\t"
: "=r" (afar)
: "i" (ASI_AFAR));
logp->afsr = afsr;
logp->afar = afar;
}
ret = 1;
}
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync\n\t"
: : "r" (afsr), "i" (ASI_AFSR));
return ret;
}
void cheetah_fecc_handler(struct pt_regs *regs, unsigned long afsr, unsigned long afar)
{
struct cheetah_err_info local_snapshot, *p;
int recoverable;
cheetah_flush_ecache();
p = cheetah_get_error_log(afsr);
if (!p) {
prom_printf("ERROR: Early Fast-ECC error afsr[%016lx] afar[%016lx]\n",
afsr, afar);
prom_printf("ERROR: CPU(%d) TPC[%016lx] TNPC[%016lx] TSTATE[%016lx]\n",
smp_processor_id(), regs->tpc, regs->tnpc, regs->tstate);
prom_halt();
}
memcpy(&local_snapshot, p, sizeof(local_snapshot));
if (p->afsr != afsr || p->afar != afar)
local_snapshot.afsr = CHAFSR_INVALID;
else
p->afsr = CHAFSR_INVALID;
cheetah_flush_icache();
cheetah_flush_dcache();
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
recoverable = 1;
if (afsr & (CHAFSR_PERR | CHAFSR_IERR | CHAFSR_ISAP))
recoverable = 0;
if (cheetah_recheck_errors(&local_snapshot)) {
unsigned long new_afsr = local_snapshot.afsr;
if (new_afsr & (CHAFSR_EMU | CHAFSR_EDU |
CHAFSR_WDU | CHAFSR_CPU |
CHAFSR_IVU | CHAFSR_UE |
CHAFSR_BERR | CHAFSR_TO))
recoverable = 0;
}
cheetah_log_errors(regs, &local_snapshot, afsr, afar, recoverable);
if (!recoverable)
panic("Irrecoverable Fast-ECC error trap.\n");
cheetah_flush_ecache();
}
static int cheetah_fix_ce(unsigned long physaddr)
{
unsigned long orig_estate;
unsigned long alias1, alias2;
int ret;
__asm__ __volatile__("ldxa [%%g0] %2, %0\n\t"
"andn %0, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %2\n\t"
"membar #Sync"
: "=&r" (orig_estate)
: "i" (ESTATE_ERROR_CEEN),
"i" (ASI_ESTATE_ERROR_EN)
: "g1");
physaddr &= ~(8UL - 1UL);
alias1 = (ecache_flush_physbase +
(physaddr & ((ecache_flush_size >> 1) - 1)));
alias2 = alias1 + (ecache_flush_size >> 1);
__asm__ __volatile__("ldxa [%0] %3, %%g0\n\t"
"ldxa [%1] %3, %%g0\n\t"
"casxa [%2] %3, %%g0, %%g0\n\t"
"ldxa [%0] %3, %%g0\n\t"
"ldxa [%1] %3, %%g0\n\t"
"membar #Sync"
:
: "r" (alias1), "r" (alias2),
"r" (physaddr), "i" (ASI_PHYS_USE_EC));
if (cheetah_recheck_errors(NULL)) {
__asm__ __volatile__("ldxa [%0] %1, %%g0\n\t"
"membar #Sync"
: : "r" (physaddr), "i" (ASI_PHYS_USE_EC));
if (cheetah_recheck_errors(NULL))
ret = 2;
else
ret = 1;
} else {
ret = 0;
}
__asm__ __volatile__("stxa %0, [%%g0] %1\n\t"
"membar #Sync"
: : "r" (orig_estate), "i" (ASI_ESTATE_ERROR_EN));
return ret;
}
static int cheetah_check_main_memory(unsigned long paddr)
{
unsigned long vaddr = PAGE_OFFSET + paddr;
if (vaddr > (unsigned long) high_memory)
return 0;
return kern_addr_valid(vaddr);
}
void cheetah_cee_handler(struct pt_regs *regs, unsigned long afsr, unsigned long afar)
{
struct cheetah_err_info local_snapshot, *p;
int recoverable, is_memory;
p = cheetah_get_error_log(afsr);
if (!p) {
prom_printf("ERROR: Early CEE error afsr[%016lx] afar[%016lx]\n",
afsr, afar);
prom_printf("ERROR: CPU(%d) TPC[%016lx] TNPC[%016lx] TSTATE[%016lx]\n",
smp_processor_id(), regs->tpc, regs->tnpc, regs->tstate);
prom_halt();
}
memcpy(&local_snapshot, p, sizeof(local_snapshot));
if (p->afsr != afsr || p->afar != afar)
local_snapshot.afsr = CHAFSR_INVALID;
else
p->afsr = CHAFSR_INVALID;
is_memory = cheetah_check_main_memory(afar);
if (is_memory && (afsr & CHAFSR_CE) != 0UL) {
cheetah_fix_ce(afar);
}
{
int flush_all, flush_line;
flush_all = flush_line = 0;
if ((afsr & CHAFSR_EDC) != 0UL) {
if ((afsr & cheetah_afsr_errors) == CHAFSR_EDC)
flush_line = 1;
else
flush_all = 1;
} else if ((afsr & CHAFSR_CPC) != 0UL) {
if ((afsr & cheetah_afsr_errors) == CHAFSR_CPC)
flush_line = 1;
else
flush_all = 1;
}
cheetah_flush_icache();
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_IC)
: "g1");
if (flush_all)
cheetah_flush_ecache();
else if (flush_line)
cheetah_flush_ecache_line(afar);
}
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_CEEN)
: "g1");
recoverable = 1;
if (afsr & (CHAFSR_PERR | CHAFSR_IERR | CHAFSR_ISAP))
recoverable = 0;
(void) cheetah_recheck_errors(&local_snapshot);
cheetah_log_errors(regs, &local_snapshot, afsr, afar, recoverable);
if (!recoverable)
panic("Irrecoverable Correctable-ECC error trap.\n");
}
void cheetah_deferred_handler(struct pt_regs *regs, unsigned long afsr, unsigned long afar)
{
struct cheetah_err_info local_snapshot, *p;
int recoverable, is_memory;
#ifdef CONFIG_PCI
if (pci_poke_in_progress && pci_poke_cpu == smp_processor_id()) {
cheetah_flush_icache();
cheetah_flush_dcache();
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
(void) cheetah_recheck_errors(NULL);
pci_poke_faulted = 1;
regs->tpc += 4;
regs->tnpc = regs->tpc + 4;
return;
}
#endif
p = cheetah_get_error_log(afsr);
if (!p) {
prom_printf("ERROR: Early deferred error afsr[%016lx] afar[%016lx]\n",
afsr, afar);
prom_printf("ERROR: CPU(%d) TPC[%016lx] TNPC[%016lx] TSTATE[%016lx]\n",
smp_processor_id(), regs->tpc, regs->tnpc, regs->tstate);
prom_halt();
}
memcpy(&local_snapshot, p, sizeof(local_snapshot));
if (p->afsr != afsr || p->afar != afar)
local_snapshot.afsr = CHAFSR_INVALID;
else
p->afsr = CHAFSR_INVALID;
is_memory = cheetah_check_main_memory(afar);
{
int flush_all, flush_line;
flush_all = flush_line = 0;
if ((afsr & CHAFSR_EDU) != 0UL) {
if ((afsr & cheetah_afsr_errors) == CHAFSR_EDU)
flush_line = 1;
else
flush_all = 1;
} else if ((afsr & CHAFSR_BERR) != 0UL) {
if ((afsr & cheetah_afsr_errors) == CHAFSR_BERR)
flush_line = 1;
else
flush_all = 1;
}
cheetah_flush_icache();
cheetah_flush_dcache();
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_IC | DCU_DC)
: "g1");
if (flush_all)
cheetah_flush_ecache();
else if (flush_line)
cheetah_flush_ecache_line(afar);
}
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_ESTATE_ERROR_EN),
"i" (ESTATE_ERROR_NCEEN | ESTATE_ERROR_CEEN)
: "g1");
recoverable = 1;
if (afsr & (CHAFSR_PERR | CHAFSR_IERR | CHAFSR_ISAP))
recoverable = 0;
if (cheetah_recheck_errors(&local_snapshot)) {
unsigned long new_afsr = local_snapshot.afsr;
if (new_afsr & (CHAFSR_EMU | CHAFSR_EDU |
CHAFSR_WDU | CHAFSR_CPU |
CHAFSR_IVU | CHAFSR_UE |
CHAFSR_BERR | CHAFSR_TO))
recoverable = 0;
}
cheetah_log_errors(regs, &local_snapshot, afsr, afar, recoverable);
if (recoverable && is_memory) {
if ((regs->tstate & TSTATE_PRIV) == 0UL) {
recoverable = 1;
} else {
const struct exception_table_entry *entry;
entry = search_exception_tables(regs->tpc);
if (entry) {
recoverable = 1;
} else {
recoverable = 0;
}
if (recoverable) {
if (pfn_valid(afar >> PAGE_SHIFT))
get_page(pfn_to_page(afar >> PAGE_SHIFT));
else
recoverable = 0;
if (recoverable) {
regs->tpc = entry->fixup;
regs->tnpc = regs->tpc + 4;
}
}
}
} else {
recoverable = 0;
}
if (!recoverable)
panic("Irrecoverable deferred error trap.\n");
}
void cheetah_plus_parity_error(int type, struct pt_regs *regs)
{
if (type & 0x1)
__cheetah_flush_icache();
else
cheetah_plus_zap_dcache_parity();
cheetah_flush_dcache();
__asm__ __volatile__("ldxa [%%g0] %0, %%g1\n\t"
"or %%g1, %1, %%g1\n\t"
"stxa %%g1, [%%g0] %0\n\t"
"membar #Sync"
:
: "i" (ASI_DCU_CONTROL_REG),
"i" (DCU_DC | DCU_IC)
: "g1");
if (type & 0x2) {
printk(KERN_EMERG "CPU[%d]: Cheetah+ %c-cache parity error at TPC[%016lx]\n",
smp_processor_id(),
(type & 0x1) ? 'I' : 'D',
regs->tpc);
printk(KERN_EMERG "TPC<%pS>\n", (void *) regs->tpc);
panic("Irrecoverable Cheetah+ parity error.");
}
printk(KERN_WARNING "CPU[%d]: Cheetah+ %c-cache parity error at TPC[%016lx]\n",
smp_processor_id(),
(type & 0x1) ? 'I' : 'D',
regs->tpc);
printk(KERN_WARNING "TPC<%pS>\n", (void *) regs->tpc);
}
static const char *sun4v_err_type_to_str(u8 type)
{
static const char *types[SUN4V_ERR_TYPE_NUM] = {
"undefined",
"uncorrected resumable",
"precise nonresumable",
"deferred nonresumable",
"shutdown request",
"dump core",
"SP state change",
};
if (type < SUN4V_ERR_TYPE_NUM)
return types[type];
return "unknown";
}
static void sun4v_emit_err_attr_strings(u32 attrs)
{
static const char *attr_names[] = {
"processor",
"memory",
"PIO",
"int-registers",
"fpu-registers",
"shutdown-request",
"ASR",
"ASI",
"priv-reg",
};
static const char *sp_states[] = {
"sp-faulted",
"sp-available",
"sp-not-present",
"sp-state-reserved",
};
static const char *modes[] = {
"mode-reserved0",
"user",
"priv",
"mode-reserved1",
};
u32 sp_state, mode;
int i;
for (i = 0; i < ARRAY_SIZE(attr_names); i++) {
if (attrs & (1U << i)) {
const char *s = attr_names[i];
pr_cont("%s ", s);
}
}
sp_state = ((attrs & SUN4V_ERR_ATTRS_SPSTATE_MSK) >>
SUN4V_ERR_ATTRS_SPSTATE_SHFT);
pr_cont("%s ", sp_states[sp_state]);
mode = ((attrs & SUN4V_ERR_ATTRS_MODE_MSK) >>
SUN4V_ERR_ATTRS_MODE_SHFT);
pr_cont("%s ", modes[mode]);
if (attrs & SUN4V_ERR_ATTRS_RES_QUEUE_FULL)
pr_cont("res-queue-full ");
}
static void sun4v_report_real_raddr(const char *pfx, struct pt_regs *regs)
{
unsigned int insn;
u64 addr;
if (!(regs->tstate & TSTATE_PRIV))
return;
insn = *(unsigned int *) regs->tpc;
addr = compute_effective_address(regs, insn, 0);
printk("%s: insn effective address [0x%016llx]\n",
pfx, addr);
}
static void sun4v_log_error(struct pt_regs *regs, struct sun4v_error_entry *ent,
int cpu, const char *pfx, atomic_t *ocnt)
{
u64 *raw_ptr = (u64 *) ent;
u32 attrs;
int cnt;
printk("%s: Reporting on cpu %d\n", pfx, cpu);
printk("%s: TPC [0x%016lx] <%pS>\n",
pfx, regs->tpc, (void *) regs->tpc);
printk("%s: RAW [%016llx:%016llx:%016llx:%016llx\n",
pfx, raw_ptr[0], raw_ptr[1], raw_ptr[2], raw_ptr[3]);
printk("%s: %016llx:%016llx:%016llx:%016llx]\n",
pfx, raw_ptr[4], raw_ptr[5], raw_ptr[6], raw_ptr[7]);
printk("%s: handle [0x%016llx] stick [0x%016llx]\n",
pfx, ent->err_handle, ent->err_stick);
printk("%s: type [%s]\n", pfx, sun4v_err_type_to_str(ent->err_type));
attrs = ent->err_attrs;
printk("%s: attrs [0x%08x] < ", pfx, attrs);
sun4v_emit_err_attr_strings(attrs);
pr_cont(">\n");
if (attrs & (SUN4V_ERR_ATTRS_MEMORY |
SUN4V_ERR_ATTRS_PIO |
SUN4V_ERR_ATTRS_ASI)) {
printk("%s: raddr [0x%016llx]\n", pfx, ent->err_raddr);
if (ent->err_raddr == ~(u64)0)
sun4v_report_real_raddr(pfx, regs);
}
if (attrs & (SUN4V_ERR_ATTRS_MEMORY | SUN4V_ERR_ATTRS_ASI))
printk("%s: size [0x%x]\n", pfx, ent->err_size);
if (attrs & (SUN4V_ERR_ATTRS_PROCESSOR |
SUN4V_ERR_ATTRS_INT_REGISTERS |
SUN4V_ERR_ATTRS_FPU_REGISTERS |
SUN4V_ERR_ATTRS_PRIV_REG))
printk("%s: cpu[%u]\n", pfx, ent->err_cpu);
if (attrs & SUN4V_ERR_ATTRS_ASI)
printk("%s: asi [0x%02x]\n", pfx, ent->err_asi);
if ((attrs & (SUN4V_ERR_ATTRS_INT_REGISTERS |
SUN4V_ERR_ATTRS_FPU_REGISTERS |
SUN4V_ERR_ATTRS_PRIV_REG)) &&
(ent->err_asr & SUN4V_ERR_ASR_VALID) != 0)
printk("%s: reg [0x%04x]\n",
pfx, ent->err_asr & ~SUN4V_ERR_ASR_VALID);
show_regs(regs);
if ((cnt = atomic_read(ocnt)) != 0) {
atomic_set(ocnt, 0);
wmb();
printk("%s: Queue overflowed %d times.\n",
pfx, cnt);
}
}
void sun4v_resum_error(struct pt_regs *regs, unsigned long offset)
{
enum ctx_state prev_state = exception_enter();
struct sun4v_error_entry *ent, local_copy;
struct trap_per_cpu *tb;
unsigned long paddr;
int cpu;
cpu = get_cpu();
tb = &trap_block[cpu];
paddr = tb->resum_kernel_buf_pa + offset;
ent = __va(paddr);
memcpy(&local_copy, ent, sizeof(struct sun4v_error_entry));
ent->err_handle = 0;
wmb();
put_cpu();
if (local_copy.err_type == SUN4V_ERR_TYPE_SHUTDOWN_RQST) {
pr_info("Shutdown request, %u seconds...\n",
local_copy.err_secs);
orderly_poweroff(true);
goto out;
}
sun4v_log_error(regs, &local_copy, cpu,
KERN_ERR "RESUMABLE ERROR",
&sun4v_resum_oflow_cnt);
out:
exception_exit(prev_state);
}
void sun4v_resum_overflow(struct pt_regs *regs)
{
atomic_inc(&sun4v_resum_oflow_cnt);
}
void sun4v_nonresum_error(struct pt_regs *regs, unsigned long offset)
{
struct sun4v_error_entry *ent, local_copy;
struct trap_per_cpu *tb;
unsigned long paddr;
int cpu;
cpu = get_cpu();
tb = &trap_block[cpu];
paddr = tb->nonresum_kernel_buf_pa + offset;
ent = __va(paddr);
memcpy(&local_copy, ent, sizeof(struct sun4v_error_entry));
ent->err_handle = 0;
wmb();
put_cpu();
#ifdef CONFIG_PCI
if (pci_poke_in_progress && pci_poke_cpu == cpu) {
pci_poke_faulted = 1;
regs->tpc += 4;
regs->tnpc = regs->tpc + 4;
return;
}
#endif
sun4v_log_error(regs, &local_copy, cpu,
KERN_EMERG "NON-RESUMABLE ERROR",
&sun4v_nonresum_oflow_cnt);
panic("Non-resumable error.");
}
void sun4v_nonresum_overflow(struct pt_regs *regs)
{
atomic_inc(&sun4v_nonresum_oflow_cnt);
}
void sun4v_itlb_error_report(struct pt_regs *regs, int tl)
{
if (tl > 1)
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
printk(KERN_EMERG "SUN4V-ITLB: Error at TPC[%lx], tl %d\n",
regs->tpc, tl);
printk(KERN_EMERG "SUN4V-ITLB: TPC<%pS>\n", (void *) regs->tpc);
printk(KERN_EMERG "SUN4V-ITLB: O7[%lx]\n", regs->u_regs[UREG_I7]);
printk(KERN_EMERG "SUN4V-ITLB: O7<%pS>\n",
(void *) regs->u_regs[UREG_I7]);
printk(KERN_EMERG "SUN4V-ITLB: vaddr[%lx] ctx[%lx] "
"pte[%lx] error[%lx]\n",
sun4v_err_itlb_vaddr, sun4v_err_itlb_ctx,
sun4v_err_itlb_pte, sun4v_err_itlb_error);
prom_halt();
}
void sun4v_dtlb_error_report(struct pt_regs *regs, int tl)
{
if (tl > 1)
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
printk(KERN_EMERG "SUN4V-DTLB: Error at TPC[%lx], tl %d\n",
regs->tpc, tl);
printk(KERN_EMERG "SUN4V-DTLB: TPC<%pS>\n", (void *) regs->tpc);
printk(KERN_EMERG "SUN4V-DTLB: O7[%lx]\n", regs->u_regs[UREG_I7]);
printk(KERN_EMERG "SUN4V-DTLB: O7<%pS>\n",
(void *) regs->u_regs[UREG_I7]);
printk(KERN_EMERG "SUN4V-DTLB: vaddr[%lx] ctx[%lx] "
"pte[%lx] error[%lx]\n",
sun4v_err_dtlb_vaddr, sun4v_err_dtlb_ctx,
sun4v_err_dtlb_pte, sun4v_err_dtlb_error);
prom_halt();
}
void hypervisor_tlbop_error(unsigned long err, unsigned long op)
{
printk(KERN_CRIT "SUN4V: TLB hv call error %lu for op %lu\n",
err, op);
}
void hypervisor_tlbop_error_xcall(unsigned long err, unsigned long op)
{
printk(KERN_CRIT "SUN4V: XCALL TLB hv call error %lu for op %lu\n",
err, op);
}
static void do_fpe_common(struct pt_regs *regs)
{
if (regs->tstate & TSTATE_PRIV) {
regs->tpc = regs->tnpc;
regs->tnpc += 4;
} else {
unsigned long fsr = current_thread_info()->xfsr[0];
siginfo_t info;
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGFPE;
info.si_errno = 0;
info.si_addr = (void __user *)regs->tpc;
info.si_trapno = 0;
info.si_code = __SI_FAULT;
if ((fsr & 0x1c000) == (1 << 14)) {
if (fsr & 0x10)
info.si_code = FPE_FLTINV;
else if (fsr & 0x08)
info.si_code = FPE_FLTOVF;
else if (fsr & 0x04)
info.si_code = FPE_FLTUND;
else if (fsr & 0x02)
info.si_code = FPE_FLTDIV;
else if (fsr & 0x01)
info.si_code = FPE_FLTRES;
}
force_sig_info(SIGFPE, &info, current);
}
}
void do_fpieee(struct pt_regs *regs)
{
enum ctx_state prev_state = exception_enter();
if (notify_die(DIE_TRAP, "fpu exception ieee", regs,
0, 0x24, SIGFPE) == NOTIFY_STOP)
goto out;
do_fpe_common(regs);
out:
exception_exit(prev_state);
}
void do_fpother(struct pt_regs *regs)
{
enum ctx_state prev_state = exception_enter();
struct fpustate *f = FPUSTATE;
int ret = 0;
if (notify_die(DIE_TRAP, "fpu exception other", regs,
0, 0x25, SIGFPE) == NOTIFY_STOP)
goto out;
switch ((current_thread_info()->xfsr[0] & 0x1c000)) {
case (2 << 14):
case (3 << 14):
ret = do_mathemu(regs, f, false);
break;
}
if (ret)
goto out;
do_fpe_common(regs);
out:
exception_exit(prev_state);
}
void do_tof(struct pt_regs *regs)
{
enum ctx_state prev_state = exception_enter();
siginfo_t info;
if (notify_die(DIE_TRAP, "tagged arithmetic overflow", regs,
0, 0x26, SIGEMT) == NOTIFY_STOP)
goto out;
if (regs->tstate & TSTATE_PRIV)
die_if_kernel("Penguin overflow trap from kernel mode", regs);
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGEMT;
info.si_errno = 0;
info.si_code = EMT_TAGOVF;
info.si_addr = (void __user *)regs->tpc;
info.si_trapno = 0;
force_sig_info(SIGEMT, &info, current);
out:
exception_exit(prev_state);
}
void do_div0(struct pt_regs *regs)
{
enum ctx_state prev_state = exception_enter();
siginfo_t info;
if (notify_die(DIE_TRAP, "integer division by zero", regs,
0, 0x28, SIGFPE) == NOTIFY_STOP)
goto out;
if (regs->tstate & TSTATE_PRIV)
die_if_kernel("TL0: Kernel divide by zero.", regs);
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGFPE;
info.si_errno = 0;
info.si_code = FPE_INTDIV;
info.si_addr = (void __user *)regs->tpc;
info.si_trapno = 0;
force_sig_info(SIGFPE, &info, current);
out:
exception_exit(prev_state);
}
static void instruction_dump(unsigned int *pc)
{
int i;
if ((((unsigned long) pc) & 3))
return;
printk("Instruction DUMP:");
for (i = -3; i < 6; i++)
printk("%c%08x%c",i?' ':'<',pc[i],i?' ':'>');
printk("\n");
}
static void user_instruction_dump(unsigned int __user *pc)
{
int i;
unsigned int buf[9];
if ((((unsigned long) pc) & 3))
return;
if (copy_from_user(buf, pc - 3, sizeof(buf)))
return;
printk("Instruction DUMP:");
for (i = 0; i < 9; i++)
printk("%c%08x%c",i==3?' ':'<',buf[i],i==3?' ':'>');
printk("\n");
}
void show_stack(struct task_struct *tsk, unsigned long *_ksp)
{
unsigned long fp, ksp;
struct thread_info *tp;
int count = 0;
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
int graph = 0;
#endif
ksp = (unsigned long) _ksp;
if (!tsk)
tsk = current;
tp = task_thread_info(tsk);
if (ksp == 0UL) {
if (tsk == current)
asm("mov %%fp, %0" : "=r" (ksp));
else
ksp = tp->ksp;
}
if (tp == current_thread_info())
flushw_all();
fp = ksp + STACK_BIAS;
printk("Call Trace:\n");
do {
struct sparc_stackf *sf;
struct pt_regs *regs;
unsigned long pc;
if (!kstack_valid(tp, fp))
break;
sf = (struct sparc_stackf *) fp;
regs = (struct pt_regs *) (sf + 1);
if (kstack_is_trap_frame(tp, regs)) {
if (!(regs->tstate & TSTATE_PRIV))
break;
pc = regs->tpc;
fp = regs->u_regs[UREG_I6] + STACK_BIAS;
} else {
pc = sf->callers_pc;
fp = (unsigned long)sf->fp + STACK_BIAS;
}
printk(" [%016lx] %pS\n", pc, (void *) pc);
#ifdef CONFIG_FUNCTION_GRAPH_TRACER
if ((pc + 8UL) == (unsigned long) &return_to_handler) {
int index = tsk->curr_ret_stack;
if (tsk->ret_stack && index >= graph) {
pc = tsk->ret_stack[index - graph].ret;
printk(" [%016lx] %pS\n", pc, (void *) pc);
graph++;
}
}
#endif
} while (++count < 16);
}
static inline struct reg_window *kernel_stack_up(struct reg_window *rw)
{
unsigned long fp = rw->ins[6];
if (!fp)
return NULL;
return (struct reg_window *) (fp + STACK_BIAS);
}
void die_if_kernel(char *str, struct pt_regs *regs)
{
static int die_counter;
int count = 0;
printk(
" \\|/ ____ \\|/\n"
" \"@'/ .. \\`@\"\n"
" /_| \\__/ |_\\\n"
" \\__U_/\n");
printk("%s(%d): %s [#%d]\n", current->comm, task_pid_nr(current), str, ++die_counter);
notify_die(DIE_OOPS, str, regs, 0, 255, SIGSEGV);
__asm__ __volatile__("flushw");
show_regs(regs);
add_taint(TAINT_DIE, LOCKDEP_NOW_UNRELIABLE);
if (regs->tstate & TSTATE_PRIV) {
struct thread_info *tp = current_thread_info();
struct reg_window *rw = (struct reg_window *)
(regs->u_regs[UREG_FP] + STACK_BIAS);
while (rw &&
count++ < 30 &&
kstack_valid(tp, (unsigned long) rw)) {
printk("Caller[%016lx]: %pS\n", rw->ins[7],
(void *) rw->ins[7]);
rw = kernel_stack_up(rw);
}
instruction_dump ((unsigned int *) regs->tpc);
} else {
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
user_instruction_dump ((unsigned int __user *) regs->tpc);
}
if (regs->tstate & TSTATE_PRIV)
do_exit(SIGKILL);
do_exit(SIGSEGV);
}
void do_illegal_instruction(struct pt_regs *regs)
{
enum ctx_state prev_state = exception_enter();
unsigned long pc = regs->tpc;
unsigned long tstate = regs->tstate;
u32 insn;
siginfo_t info;
if (notify_die(DIE_TRAP, "illegal instruction", regs,
0, 0x10, SIGILL) == NOTIFY_STOP)
goto out;
if (tstate & TSTATE_PRIV)
die_if_kernel("Kernel illegal instruction", regs);
if (test_thread_flag(TIF_32BIT))
pc = (u32)pc;
if (get_user(insn, (u32 __user *) pc) != -EFAULT) {
if ((insn & 0xc1ffc000) == 0x81700000) {
if (handle_popc(insn, regs))
goto out;
} else if ((insn & 0xc1580000) == 0xc1100000) {
if (handle_ldf_stq(insn, regs))
goto out;
} else if (tlb_type == hypervisor) {
if ((insn & VIS_OPCODE_MASK) == VIS_OPCODE_VAL) {
if (!vis_emul(regs, insn))
goto out;
} else {
struct fpustate *f = FPUSTATE;
if (do_mathemu(regs, f, true))
goto out;
}
}
}
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_ILLOPC;
info.si_addr = (void __user *)pc;
info.si_trapno = 0;
force_sig_info(SIGILL, &info, current);
out:
exception_exit(prev_state);
}
void mem_address_unaligned(struct pt_regs *regs, unsigned long sfar, unsigned long sfsr)
{
enum ctx_state prev_state = exception_enter();
siginfo_t info;
if (notify_die(DIE_TRAP, "memory address unaligned", regs,
0, 0x34, SIGSEGV) == NOTIFY_STOP)
goto out;
if (regs->tstate & TSTATE_PRIV) {
kernel_unaligned_trap(regs, *((unsigned int *)regs->tpc));
goto out;
}
info.si_signo = SIGBUS;
info.si_errno = 0;
info.si_code = BUS_ADRALN;
info.si_addr = (void __user *)sfar;
info.si_trapno = 0;
force_sig_info(SIGBUS, &info, current);
out:
exception_exit(prev_state);
}
void sun4v_do_mna(struct pt_regs *regs, unsigned long addr, unsigned long type_ctx)
{
siginfo_t info;
if (notify_die(DIE_TRAP, "memory address unaligned", regs,
0, 0x34, SIGSEGV) == NOTIFY_STOP)
return;
if (regs->tstate & TSTATE_PRIV) {
kernel_unaligned_trap(regs, *((unsigned int *)regs->tpc));
return;
}
info.si_signo = SIGBUS;
info.si_errno = 0;
info.si_code = BUS_ADRALN;
info.si_addr = (void __user *) addr;
info.si_trapno = 0;
force_sig_info(SIGBUS, &info, current);
}
void do_privop(struct pt_regs *regs)
{
enum ctx_state prev_state = exception_enter();
siginfo_t info;
if (notify_die(DIE_TRAP, "privileged operation", regs,
0, 0x11, SIGILL) == NOTIFY_STOP)
goto out;
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_PRVOPC;
info.si_addr = (void __user *)regs->tpc;
info.si_trapno = 0;
force_sig_info(SIGILL, &info, current);
out:
exception_exit(prev_state);
}
void do_privact(struct pt_regs *regs)
{
do_privop(regs);
}
void do_cee(struct pt_regs *regs)
{
exception_enter();
die_if_kernel("TL0: Cache Error Exception", regs);
}
void do_cee_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: Cache Error Exception", regs);
}
void do_dae_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: Data Access Exception", regs);
}
void do_iae_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: Instruction Access Exception", regs);
}
void do_div0_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: DIV0 Exception", regs);
}
void do_fpdis_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: FPU Disabled", regs);
}
void do_fpieee_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: FPU IEEE Exception", regs);
}
void do_fpother_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: FPU Other Exception", regs);
}
void do_ill_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: Illegal Instruction Exception", regs);
}
void do_irq_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: IRQ Exception", regs);
}
void do_lddfmna_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: LDDF Exception", regs);
}
void do_stdfmna_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: STDF Exception", regs);
}
void do_paw(struct pt_regs *regs)
{
exception_enter();
die_if_kernel("TL0: Phys Watchpoint Exception", regs);
}
void do_paw_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: Phys Watchpoint Exception", regs);
}
void do_vaw(struct pt_regs *regs)
{
exception_enter();
die_if_kernel("TL0: Virt Watchpoint Exception", regs);
}
void do_vaw_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: Virt Watchpoint Exception", regs);
}
void do_tof_tl1(struct pt_regs *regs)
{
exception_enter();
dump_tl1_traplog((struct tl1_traplog *)(regs + 1));
die_if_kernel("TL1: Tag Overflow Exception", regs);
}
void do_getpsr(struct pt_regs *regs)
{
regs->u_regs[UREG_I0] = tstate_to_psr(regs->tstate);
regs->tpc = regs->tnpc;
regs->tnpc += 4;
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
}
void notrace init_cur_cpu_trap(struct thread_info *t)
{
int cpu = hard_smp_processor_id();
struct trap_per_cpu *p = &trap_block[cpu];
p->thread = t;
p->pgd_paddr = 0;
}
void __init trap_init(void)
{
BUILD_BUG_ON(TI_TASK != offsetof(struct thread_info, task) ||
TI_FLAGS != offsetof(struct thread_info, flags) ||
TI_CPU != offsetof(struct thread_info, cpu) ||
TI_FPSAVED != offsetof(struct thread_info, fpsaved) ||
TI_KSP != offsetof(struct thread_info, ksp) ||
TI_FAULT_ADDR != offsetof(struct thread_info,
fault_address) ||
TI_KREGS != offsetof(struct thread_info, kregs) ||
TI_UTRAPS != offsetof(struct thread_info, utraps) ||
TI_EXEC_DOMAIN != offsetof(struct thread_info,
exec_domain) ||
TI_REG_WINDOW != offsetof(struct thread_info,
reg_window) ||
TI_RWIN_SPTRS != offsetof(struct thread_info,
rwbuf_stkptrs) ||
TI_GSR != offsetof(struct thread_info, gsr) ||
TI_XFSR != offsetof(struct thread_info, xfsr) ||
TI_PRE_COUNT != offsetof(struct thread_info,
preempt_count) ||
TI_NEW_CHILD != offsetof(struct thread_info, new_child) ||
TI_CURRENT_DS != offsetof(struct thread_info,
current_ds) ||
TI_RESTART_BLOCK != offsetof(struct thread_info,
restart_block) ||
TI_KUNA_REGS != offsetof(struct thread_info,
kern_una_regs) ||
TI_KUNA_INSN != offsetof(struct thread_info,
kern_una_insn) ||
TI_FPREGS != offsetof(struct thread_info, fpregs) ||
(TI_FPREGS & (64 - 1)));
BUILD_BUG_ON(TRAP_PER_CPU_THREAD != offsetof(struct trap_per_cpu,
thread) ||
(TRAP_PER_CPU_PGD_PADDR !=
offsetof(struct trap_per_cpu, pgd_paddr)) ||
(TRAP_PER_CPU_CPU_MONDO_PA !=
offsetof(struct trap_per_cpu, cpu_mondo_pa)) ||
(TRAP_PER_CPU_DEV_MONDO_PA !=
offsetof(struct trap_per_cpu, dev_mondo_pa)) ||
(TRAP_PER_CPU_RESUM_MONDO_PA !=
offsetof(struct trap_per_cpu, resum_mondo_pa)) ||
(TRAP_PER_CPU_RESUM_KBUF_PA !=
offsetof(struct trap_per_cpu, resum_kernel_buf_pa)) ||
(TRAP_PER_CPU_NONRESUM_MONDO_PA !=
offsetof(struct trap_per_cpu, nonresum_mondo_pa)) ||
(TRAP_PER_CPU_NONRESUM_KBUF_PA !=
offsetof(struct trap_per_cpu, nonresum_kernel_buf_pa)) ||
(TRAP_PER_CPU_FAULT_INFO !=
offsetof(struct trap_per_cpu, fault_info)) ||
(TRAP_PER_CPU_CPU_MONDO_BLOCK_PA !=
offsetof(struct trap_per_cpu, cpu_mondo_block_pa)) ||
(TRAP_PER_CPU_CPU_LIST_PA !=
offsetof(struct trap_per_cpu, cpu_list_pa)) ||
(TRAP_PER_CPU_TSB_HUGE !=
offsetof(struct trap_per_cpu, tsb_huge)) ||
(TRAP_PER_CPU_TSB_HUGE_TEMP !=
offsetof(struct trap_per_cpu, tsb_huge_temp)) ||
(TRAP_PER_CPU_IRQ_WORKLIST_PA !=
offsetof(struct trap_per_cpu, irq_worklist_pa)) ||
(TRAP_PER_CPU_CPU_MONDO_QMASK !=
offsetof(struct trap_per_cpu, cpu_mondo_qmask)) ||
(TRAP_PER_CPU_DEV_MONDO_QMASK !=
offsetof(struct trap_per_cpu, dev_mondo_qmask)) ||
(TRAP_PER_CPU_RESUM_QMASK !=
offsetof(struct trap_per_cpu, resum_qmask)) ||
(TRAP_PER_CPU_NONRESUM_QMASK !=
offsetof(struct trap_per_cpu, nonresum_qmask)) ||
(TRAP_PER_CPU_PER_CPU_BASE !=
offsetof(struct trap_per_cpu, __per_cpu_base)));
BUILD_BUG_ON((TSB_CONFIG_TSB !=
offsetof(struct tsb_config, tsb)) ||
(TSB_CONFIG_RSS_LIMIT !=
offsetof(struct tsb_config, tsb_rss_limit)) ||
(TSB_CONFIG_NENTRIES !=
offsetof(struct tsb_config, tsb_nentries)) ||
(TSB_CONFIG_REG_VAL !=
offsetof(struct tsb_config, tsb_reg_val)) ||
(TSB_CONFIG_MAP_VADDR !=
offsetof(struct tsb_config, tsb_map_vaddr)) ||
(TSB_CONFIG_MAP_PTE !=
offsetof(struct tsb_config, tsb_map_pte)));
atomic_inc(&init_mm.mm_count);
current->active_mm = &init_mm;
}
