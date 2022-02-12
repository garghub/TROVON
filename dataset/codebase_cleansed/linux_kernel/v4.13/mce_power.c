static void flush_tlb_206(unsigned int num_sets, unsigned int action)
{
unsigned long rb;
unsigned int i;
switch (action) {
case TLB_INVAL_SCOPE_GLOBAL:
rb = TLBIEL_INVAL_SET;
break;
case TLB_INVAL_SCOPE_LPID:
rb = TLBIEL_INVAL_SET_LPID;
break;
default:
BUG();
break;
}
asm volatile("ptesync" : : : "memory");
for (i = 0; i < num_sets; i++) {
asm volatile("tlbiel %0" : : "r" (rb));
rb += 1 << TLBIEL_INVAL_SET_SHIFT;
}
asm volatile("ptesync" : : : "memory");
}
static void flush_tlb_300(unsigned int num_sets, unsigned int action)
{
unsigned long rb;
unsigned int i;
unsigned int r;
switch (action) {
case TLB_INVAL_SCOPE_GLOBAL:
rb = TLBIEL_INVAL_SET;
break;
case TLB_INVAL_SCOPE_LPID:
rb = TLBIEL_INVAL_SET_LPID;
break;
default:
BUG();
break;
}
asm volatile("ptesync" : : : "memory");
if (early_radix_enabled())
r = 1;
else
r = 0;
asm volatile(PPC_TLBIEL(%0, %1, %2, %3, %4) : :
"r"(rb), "r"(0), "i"(2), "i"(0), "r"(r));
for (i = 1; i < num_sets; i++) {
unsigned long set = i * (1<<TLBIEL_INVAL_SET_SHIFT);
asm volatile(PPC_TLBIEL(%0, %1, %2, %3, %4) : :
"r"(rb+set), "r"(0), "i"(2), "i"(0), "r"(r));
}
asm volatile(PPC_TLBIEL(%0, %1, %2, %3, %4) : :
"r"(rb), "r"(0), "i"(2), "i"(1), "r"(r));
if (early_radix_enabled()) {
for (i = 1; i < num_sets; i++) {
unsigned long set = i * (1<<TLBIEL_INVAL_SET_SHIFT);
asm volatile(PPC_TLBIEL(%0, %1, %2, %3, %4) : :
"r"(rb+set), "r"(0), "i"(2), "i"(1), "r"(r));
}
}
asm volatile("ptesync" : : : "memory");
}
void __flush_tlb_power7(unsigned int action)
{
flush_tlb_206(POWER7_TLB_SETS, action);
}
void __flush_tlb_power8(unsigned int action)
{
flush_tlb_206(POWER8_TLB_SETS, action);
}
void __flush_tlb_power9(unsigned int action)
{
unsigned int num_sets;
if (radix_enabled())
num_sets = POWER9_TLB_SETS_RADIX;
else
num_sets = POWER9_TLB_SETS_HASH;
flush_tlb_300(num_sets, action);
}
static void flush_and_reload_slb(void)
{
struct slb_shadow *slb;
unsigned long i, n;
asm volatile("slbmte %0,%0; slbia" : : "r" (0));
#ifdef CONFIG_KVM_BOOK3S_HANDLER
if (get_paca()->kvm_hstate.in_guest)
return;
#endif
slb = get_slb_shadow();
if (!slb)
return;
n = min_t(u32, be32_to_cpu(slb->persistent), SLB_MIN_SIZE);
for (i = 0; i < n; i++) {
unsigned long rb = be64_to_cpu(slb->save_area[i].esid);
unsigned long rs = be64_to_cpu(slb->save_area[i].vsid);
rb = (rb & ~0xFFFul) | i;
asm volatile("slbmte %0,%1" : : "r" (rs), "r" (rb));
}
}
static void flush_erat(void)
{
asm volatile(PPC_INVALIDATE_ERAT : : :"memory");
}
static int mce_flush(int what)
{
#ifdef CONFIG_PPC_STD_MMU_64
if (what == MCE_FLUSH_SLB) {
flush_and_reload_slb();
return 1;
}
#endif
if (what == MCE_FLUSH_ERAT) {
flush_erat();
return 1;
}
if (what == MCE_FLUSH_TLB) {
if (cur_cpu_spec && cur_cpu_spec->flush_tlb) {
cur_cpu_spec->flush_tlb(TLB_INVAL_SCOPE_GLOBAL);
return 1;
}
}
return 0;
}
static int mce_handle_ierror(struct pt_regs *regs,
const struct mce_ierror_table table[],
struct mce_error_info *mce_err, uint64_t *addr)
{
uint64_t srr1 = regs->msr;
int handled = 0;
int i;
*addr = 0;
for (i = 0; table[i].srr1_mask; i++) {
if ((srr1 & table[i].srr1_mask) != table[i].srr1_value)
continue;
switch (table[i].error_type) {
case MCE_ERROR_TYPE_SLB:
handled = mce_flush(MCE_FLUSH_SLB);
break;
case MCE_ERROR_TYPE_ERAT:
handled = mce_flush(MCE_FLUSH_ERAT);
break;
case MCE_ERROR_TYPE_TLB:
handled = mce_flush(MCE_FLUSH_TLB);
break;
}
mce_err->error_type = table[i].error_type;
switch (table[i].error_type) {
case MCE_ERROR_TYPE_UE:
mce_err->u.ue_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_SLB:
mce_err->u.slb_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_ERAT:
mce_err->u.erat_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_TLB:
mce_err->u.tlb_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_USER:
mce_err->u.user_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_RA:
mce_err->u.ra_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_LINK:
mce_err->u.link_error_type = table[i].error_subtype;
break;
}
mce_err->severity = table[i].severity;
mce_err->initiator = table[i].initiator;
if (table[i].nip_valid)
*addr = regs->nip;
return handled;
}
mce_err->error_type = MCE_ERROR_TYPE_UNKNOWN;
mce_err->severity = MCE_SEV_ERROR_SYNC;
mce_err->initiator = MCE_INITIATOR_CPU;
return 0;
}
static int mce_handle_derror(struct pt_regs *regs,
const struct mce_derror_table table[],
struct mce_error_info *mce_err, uint64_t *addr)
{
uint64_t dsisr = regs->dsisr;
int handled = 0;
int found = 0;
int i;
*addr = 0;
for (i = 0; table[i].dsisr_value; i++) {
if (!(dsisr & table[i].dsisr_value))
continue;
switch (table[i].error_type) {
case MCE_ERROR_TYPE_SLB:
if (mce_flush(MCE_FLUSH_SLB))
handled = 1;
break;
case MCE_ERROR_TYPE_ERAT:
if (mce_flush(MCE_FLUSH_ERAT))
handled = 1;
break;
case MCE_ERROR_TYPE_TLB:
if (mce_flush(MCE_FLUSH_TLB))
handled = 1;
break;
}
if (found)
continue;
mce_err->error_type = table[i].error_type;
switch (table[i].error_type) {
case MCE_ERROR_TYPE_UE:
mce_err->u.ue_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_SLB:
mce_err->u.slb_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_ERAT:
mce_err->u.erat_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_TLB:
mce_err->u.tlb_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_USER:
mce_err->u.user_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_RA:
mce_err->u.ra_error_type = table[i].error_subtype;
break;
case MCE_ERROR_TYPE_LINK:
mce_err->u.link_error_type = table[i].error_subtype;
break;
}
mce_err->severity = table[i].severity;
mce_err->initiator = table[i].initiator;
if (table[i].dar_valid)
*addr = regs->dar;
found = 1;
}
if (found)
return handled;
mce_err->error_type = MCE_ERROR_TYPE_UNKNOWN;
mce_err->severity = MCE_SEV_ERROR_SYNC;
mce_err->initiator = MCE_INITIATOR_CPU;
return 0;
}
static long mce_handle_ue_error(struct pt_regs *regs)
{
long handled = 0;
if (ppc_md.mce_check_early_recovery) {
if (ppc_md.mce_check_early_recovery(regs))
handled = 1;
}
return handled;
}
static long mce_handle_error(struct pt_regs *regs,
const struct mce_derror_table dtable[],
const struct mce_ierror_table itable[])
{
struct mce_error_info mce_err = { 0 };
uint64_t addr;
uint64_t srr1 = regs->msr;
long handled;
if (SRR1_MC_LOADSTORE(srr1))
handled = mce_handle_derror(regs, dtable, &mce_err, &addr);
else
handled = mce_handle_ierror(regs, itable, &mce_err, &addr);
if (!handled && mce_err.error_type == MCE_ERROR_TYPE_UE)
handled = mce_handle_ue_error(regs);
save_mce_event(regs, handled, &mce_err, regs->nip, addr);
return handled;
}
long __machine_check_early_realmode_p7(struct pt_regs *regs)
{
regs->dsisr &= 0x0000ffff;
return mce_handle_error(regs, mce_p7_derror_table, mce_p7_ierror_table);
}
long __machine_check_early_realmode_p8(struct pt_regs *regs)
{
return mce_handle_error(regs, mce_p8_derror_table, mce_p8_ierror_table);
}
long __machine_check_early_realmode_p9(struct pt_regs *regs)
{
return mce_handle_error(regs, mce_p9_derror_table, mce_p9_ierror_table);
}
