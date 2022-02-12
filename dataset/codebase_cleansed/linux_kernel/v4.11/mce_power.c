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
if (radix_enabled())
flush_tlb_206(POWER9_TLB_SETS_RADIX, action);
flush_tlb_206(POWER9_TLB_SETS_HASH, action);
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
static int mce_handle_flush_derrors(uint64_t dsisr, uint64_t slb, uint64_t tlb, uint64_t erat)
{
if ((dsisr & slb) && mce_flush(MCE_FLUSH_SLB))
dsisr &= ~slb;
if ((dsisr & erat) && mce_flush(MCE_FLUSH_ERAT))
dsisr &= ~erat;
if ((dsisr & tlb) && mce_flush(MCE_FLUSH_TLB))
dsisr &= ~tlb;
if (dsisr)
return 0;
return 1;
}
static long mce_handle_derror(uint64_t dsisr, uint64_t slb_error_bits)
{
long handled = 1;
#ifdef CONFIG_PPC_STD_MMU_64
if (dsisr & slb_error_bits) {
flush_and_reload_slb();
dsisr &= ~(slb_error_bits);
}
if (dsisr & P7_DSISR_MC_TLB_MULTIHIT_MFTLB) {
if (cur_cpu_spec && cur_cpu_spec->flush_tlb)
cur_cpu_spec->flush_tlb(TLB_INVAL_SCOPE_GLOBAL);
dsisr &= ~P7_DSISR_MC_TLB_MULTIHIT_MFTLB;
}
#endif
if (dsisr & 0xffffffffUL)
handled = 0;
return handled;
}
static long mce_handle_derror_p7(uint64_t dsisr)
{
return mce_handle_derror(dsisr, P7_DSISR_MC_SLB_ERRORS);
}
static long mce_handle_common_ierror(uint64_t srr1)
{
long handled = 0;
switch (P7_SRR1_MC_IFETCH(srr1)) {
case 0:
break;
#ifdef CONFIG_PPC_STD_MMU_64
case P7_SRR1_MC_IFETCH_SLB_PARITY:
case P7_SRR1_MC_IFETCH_SLB_MULTIHIT:
flush_and_reload_slb();
handled = 1;
break;
case P7_SRR1_MC_IFETCH_TLB_MULTIHIT:
if (cur_cpu_spec && cur_cpu_spec->flush_tlb) {
cur_cpu_spec->flush_tlb(TLB_INVAL_SCOPE_GLOBAL);
handled = 1;
}
break;
#endif
default:
break;
}
return handled;
}
static long mce_handle_ierror_p7(uint64_t srr1)
{
long handled = 0;
handled = mce_handle_common_ierror(srr1);
#ifdef CONFIG_PPC_STD_MMU_64
if (P7_SRR1_MC_IFETCH(srr1) == P7_SRR1_MC_IFETCH_SLB_BOTH) {
flush_and_reload_slb();
handled = 1;
}
#endif
return handled;
}
static void mce_get_common_ierror(struct mce_error_info *mce_err, uint64_t srr1)
{
switch (P7_SRR1_MC_IFETCH(srr1)) {
case P7_SRR1_MC_IFETCH_SLB_PARITY:
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_PARITY;
break;
case P7_SRR1_MC_IFETCH_SLB_MULTIHIT:
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_MULTIHIT;
break;
case P7_SRR1_MC_IFETCH_TLB_MULTIHIT:
mce_err->error_type = MCE_ERROR_TYPE_TLB;
mce_err->u.tlb_error_type = MCE_TLB_ERROR_MULTIHIT;
break;
case P7_SRR1_MC_IFETCH_UE:
case P7_SRR1_MC_IFETCH_UE_IFU_INTERNAL:
mce_err->error_type = MCE_ERROR_TYPE_UE;
mce_err->u.ue_error_type = MCE_UE_ERROR_IFETCH;
break;
case P7_SRR1_MC_IFETCH_UE_TLB_RELOAD:
mce_err->error_type = MCE_ERROR_TYPE_UE;
mce_err->u.ue_error_type =
MCE_UE_ERROR_PAGE_TABLE_WALK_IFETCH;
break;
}
}
static void mce_get_ierror_p7(struct mce_error_info *mce_err, uint64_t srr1)
{
mce_get_common_ierror(mce_err, srr1);
if (P7_SRR1_MC_IFETCH(srr1) == P7_SRR1_MC_IFETCH_SLB_BOTH) {
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_INDETERMINATE;
}
}
static void mce_get_derror_p7(struct mce_error_info *mce_err, uint64_t dsisr)
{
if (dsisr & P7_DSISR_MC_UE) {
mce_err->error_type = MCE_ERROR_TYPE_UE;
mce_err->u.ue_error_type = MCE_UE_ERROR_LOAD_STORE;
} else if (dsisr & P7_DSISR_MC_UE_TABLEWALK) {
mce_err->error_type = MCE_ERROR_TYPE_UE;
mce_err->u.ue_error_type =
MCE_UE_ERROR_PAGE_TABLE_WALK_LOAD_STORE;
} else if (dsisr & P7_DSISR_MC_ERAT_MULTIHIT) {
mce_err->error_type = MCE_ERROR_TYPE_ERAT;
mce_err->u.erat_error_type = MCE_ERAT_ERROR_MULTIHIT;
} else if (dsisr & P7_DSISR_MC_SLB_MULTIHIT) {
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_MULTIHIT;
} else if (dsisr & P7_DSISR_MC_SLB_PARITY_MFSLB) {
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_PARITY;
} else if (dsisr & P7_DSISR_MC_TLB_MULTIHIT_MFTLB) {
mce_err->error_type = MCE_ERROR_TYPE_TLB;
mce_err->u.tlb_error_type = MCE_TLB_ERROR_MULTIHIT;
} else if (dsisr & P7_DSISR_MC_SLB_MULTIHIT_PARITY) {
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_INDETERMINATE;
}
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
long __machine_check_early_realmode_p7(struct pt_regs *regs)
{
uint64_t srr1, nip, addr;
long handled = 1;
struct mce_error_info mce_error_info = { 0 };
mce_error_info.severity = MCE_SEV_ERROR_SYNC;
mce_error_info.initiator = MCE_INITIATOR_CPU;
srr1 = regs->msr;
nip = regs->nip;
if (P7_SRR1_MC_LOADSTORE(srr1)) {
handled = mce_handle_derror_p7(regs->dsisr);
mce_get_derror_p7(&mce_error_info, regs->dsisr);
addr = regs->dar;
} else {
handled = mce_handle_ierror_p7(srr1);
mce_get_ierror_p7(&mce_error_info, srr1);
addr = regs->nip;
}
if (mce_error_info.error_type == MCE_ERROR_TYPE_UE)
handled = mce_handle_ue_error(regs);
save_mce_event(regs, handled, &mce_error_info, nip, addr);
return handled;
}
static void mce_get_ierror_p8(struct mce_error_info *mce_err, uint64_t srr1)
{
mce_get_common_ierror(mce_err, srr1);
if (P7_SRR1_MC_IFETCH(srr1) == P8_SRR1_MC_IFETCH_ERAT_MULTIHIT) {
mce_err->error_type = MCE_ERROR_TYPE_ERAT;
mce_err->u.erat_error_type = MCE_ERAT_ERROR_MULTIHIT;
}
}
static void mce_get_derror_p8(struct mce_error_info *mce_err, uint64_t dsisr)
{
mce_get_derror_p7(mce_err, dsisr);
if (dsisr & P8_DSISR_MC_ERAT_MULTIHIT_SEC) {
mce_err->error_type = MCE_ERROR_TYPE_ERAT;
mce_err->u.erat_error_type = MCE_ERAT_ERROR_MULTIHIT;
}
}
static long mce_handle_ierror_p8(uint64_t srr1)
{
long handled = 0;
handled = mce_handle_common_ierror(srr1);
#ifdef CONFIG_PPC_STD_MMU_64
if (P7_SRR1_MC_IFETCH(srr1) == P8_SRR1_MC_IFETCH_ERAT_MULTIHIT) {
flush_and_reload_slb();
handled = 1;
}
#endif
return handled;
}
static long mce_handle_derror_p8(uint64_t dsisr)
{
return mce_handle_derror(dsisr, P8_DSISR_MC_SLB_ERRORS);
}
long __machine_check_early_realmode_p8(struct pt_regs *regs)
{
uint64_t srr1, nip, addr;
long handled = 1;
struct mce_error_info mce_error_info = { 0 };
mce_error_info.severity = MCE_SEV_ERROR_SYNC;
mce_error_info.initiator = MCE_INITIATOR_CPU;
srr1 = regs->msr;
nip = regs->nip;
if (P7_SRR1_MC_LOADSTORE(srr1)) {
handled = mce_handle_derror_p8(regs->dsisr);
mce_get_derror_p8(&mce_error_info, regs->dsisr);
addr = regs->dar;
} else {
handled = mce_handle_ierror_p8(srr1);
mce_get_ierror_p8(&mce_error_info, srr1);
addr = regs->nip;
}
if (mce_error_info.error_type == MCE_ERROR_TYPE_UE)
handled = mce_handle_ue_error(regs);
save_mce_event(regs, handled, &mce_error_info, nip, addr);
return handled;
}
static int mce_handle_derror_p9(struct pt_regs *regs)
{
uint64_t dsisr = regs->dsisr;
return mce_handle_flush_derrors(dsisr,
P9_DSISR_MC_SLB_PARITY_MFSLB |
P9_DSISR_MC_SLB_MULTIHIT_MFSLB,
P9_DSISR_MC_TLB_MULTIHIT_MFTLB,
P9_DSISR_MC_ERAT_MULTIHIT);
}
static int mce_handle_ierror_p9(struct pt_regs *regs)
{
uint64_t srr1 = regs->msr;
switch (P9_SRR1_MC_IFETCH(srr1)) {
case P9_SRR1_MC_IFETCH_SLB_PARITY:
case P9_SRR1_MC_IFETCH_SLB_MULTIHIT:
return mce_flush(MCE_FLUSH_SLB);
case P9_SRR1_MC_IFETCH_TLB_MULTIHIT:
return mce_flush(MCE_FLUSH_TLB);
case P9_SRR1_MC_IFETCH_ERAT_MULTIHIT:
return mce_flush(MCE_FLUSH_ERAT);
default:
return 0;
}
}
static void mce_get_derror_p9(struct pt_regs *regs,
struct mce_error_info *mce_err, uint64_t *addr)
{
uint64_t dsisr = regs->dsisr;
mce_err->severity = MCE_SEV_ERROR_SYNC;
mce_err->initiator = MCE_INITIATOR_CPU;
if (dsisr & P9_DSISR_MC_USER_TLBIE)
*addr = regs->nip;
else
*addr = regs->dar;
if (dsisr & P9_DSISR_MC_UE) {
mce_err->error_type = MCE_ERROR_TYPE_UE;
mce_err->u.ue_error_type = MCE_UE_ERROR_LOAD_STORE;
} else if (dsisr & P9_DSISR_MC_UE_TABLEWALK) {
mce_err->error_type = MCE_ERROR_TYPE_UE;
mce_err->u.ue_error_type = MCE_UE_ERROR_PAGE_TABLE_WALK_LOAD_STORE;
} else if (dsisr & P9_DSISR_MC_LINK_LOAD_TIMEOUT) {
mce_err->error_type = MCE_ERROR_TYPE_LINK;
mce_err->u.link_error_type = MCE_LINK_ERROR_LOAD_TIMEOUT;
} else if (dsisr & P9_DSISR_MC_LINK_TABLEWALK_TIMEOUT) {
mce_err->error_type = MCE_ERROR_TYPE_LINK;
mce_err->u.link_error_type = MCE_LINK_ERROR_PAGE_TABLE_WALK_LOAD_STORE_TIMEOUT;
} else if (dsisr & P9_DSISR_MC_ERAT_MULTIHIT) {
mce_err->error_type = MCE_ERROR_TYPE_ERAT;
mce_err->u.erat_error_type = MCE_ERAT_ERROR_MULTIHIT;
} else if (dsisr & P9_DSISR_MC_TLB_MULTIHIT_MFTLB) {
mce_err->error_type = MCE_ERROR_TYPE_TLB;
mce_err->u.tlb_error_type = MCE_TLB_ERROR_MULTIHIT;
} else if (dsisr & P9_DSISR_MC_USER_TLBIE) {
mce_err->error_type = MCE_ERROR_TYPE_USER;
mce_err->u.user_error_type = MCE_USER_ERROR_TLBIE;
} else if (dsisr & P9_DSISR_MC_SLB_PARITY_MFSLB) {
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_PARITY;
} else if (dsisr & P9_DSISR_MC_SLB_MULTIHIT_MFSLB) {
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_MULTIHIT;
} else if (dsisr & P9_DSISR_MC_RA_LOAD) {
mce_err->error_type = MCE_ERROR_TYPE_RA;
mce_err->u.ra_error_type = MCE_RA_ERROR_LOAD;
} else if (dsisr & P9_DSISR_MC_RA_TABLEWALK) {
mce_err->error_type = MCE_ERROR_TYPE_RA;
mce_err->u.ra_error_type = MCE_RA_ERROR_PAGE_TABLE_WALK_LOAD_STORE;
} else if (dsisr & P9_DSISR_MC_RA_TABLEWALK_FOREIGN) {
mce_err->error_type = MCE_ERROR_TYPE_RA;
mce_err->u.ra_error_type = MCE_RA_ERROR_PAGE_TABLE_WALK_LOAD_STORE_FOREIGN;
} else if (dsisr & P9_DSISR_MC_RA_FOREIGN) {
mce_err->error_type = MCE_ERROR_TYPE_RA;
mce_err->u.ra_error_type = MCE_RA_ERROR_LOAD_STORE_FOREIGN;
}
}
static void mce_get_ierror_p9(struct pt_regs *regs,
struct mce_error_info *mce_err, uint64_t *addr)
{
uint64_t srr1 = regs->msr;
switch (P9_SRR1_MC_IFETCH(srr1)) {
case P9_SRR1_MC_IFETCH_RA_ASYNC_STORE:
case P9_SRR1_MC_IFETCH_LINK_ASYNC_STORE_TIMEOUT:
mce_err->severity = MCE_SEV_FATAL;
break;
default:
mce_err->severity = MCE_SEV_ERROR_SYNC;
break;
}
mce_err->initiator = MCE_INITIATOR_CPU;
*addr = regs->nip;
switch (P9_SRR1_MC_IFETCH(srr1)) {
case P9_SRR1_MC_IFETCH_UE:
mce_err->error_type = MCE_ERROR_TYPE_UE;
mce_err->u.ue_error_type = MCE_UE_ERROR_IFETCH;
break;
case P9_SRR1_MC_IFETCH_SLB_PARITY:
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_PARITY;
break;
case P9_SRR1_MC_IFETCH_SLB_MULTIHIT:
mce_err->error_type = MCE_ERROR_TYPE_SLB;
mce_err->u.slb_error_type = MCE_SLB_ERROR_MULTIHIT;
break;
case P9_SRR1_MC_IFETCH_ERAT_MULTIHIT:
mce_err->error_type = MCE_ERROR_TYPE_ERAT;
mce_err->u.erat_error_type = MCE_ERAT_ERROR_MULTIHIT;
break;
case P9_SRR1_MC_IFETCH_TLB_MULTIHIT:
mce_err->error_type = MCE_ERROR_TYPE_TLB;
mce_err->u.tlb_error_type = MCE_TLB_ERROR_MULTIHIT;
break;
case P9_SRR1_MC_IFETCH_UE_TLB_RELOAD:
mce_err->error_type = MCE_ERROR_TYPE_UE;
mce_err->u.ue_error_type = MCE_UE_ERROR_PAGE_TABLE_WALK_IFETCH;
break;
case P9_SRR1_MC_IFETCH_LINK_TIMEOUT:
mce_err->error_type = MCE_ERROR_TYPE_LINK;
mce_err->u.link_error_type = MCE_LINK_ERROR_IFETCH_TIMEOUT;
break;
case P9_SRR1_MC_IFETCH_LINK_TABLEWALK_TIMEOUT:
mce_err->error_type = MCE_ERROR_TYPE_LINK;
mce_err->u.link_error_type = MCE_LINK_ERROR_PAGE_TABLE_WALK_IFETCH_TIMEOUT;
break;
case P9_SRR1_MC_IFETCH_RA:
mce_err->error_type = MCE_ERROR_TYPE_RA;
mce_err->u.ra_error_type = MCE_RA_ERROR_IFETCH;
break;
case P9_SRR1_MC_IFETCH_RA_TABLEWALK:
mce_err->error_type = MCE_ERROR_TYPE_RA;
mce_err->u.ra_error_type = MCE_RA_ERROR_PAGE_TABLE_WALK_IFETCH;
break;
case P9_SRR1_MC_IFETCH_RA_ASYNC_STORE:
mce_err->error_type = MCE_ERROR_TYPE_RA;
mce_err->u.ra_error_type = MCE_RA_ERROR_STORE;
break;
case P9_SRR1_MC_IFETCH_LINK_ASYNC_STORE_TIMEOUT:
mce_err->error_type = MCE_ERROR_TYPE_LINK;
mce_err->u.link_error_type = MCE_LINK_ERROR_STORE_TIMEOUT;
break;
case P9_SRR1_MC_IFETCH_RA_TABLEWALK_FOREIGN:
mce_err->error_type = MCE_ERROR_TYPE_RA;
mce_err->u.ra_error_type = MCE_RA_ERROR_PAGE_TABLE_WALK_IFETCH_FOREIGN;
break;
default:
break;
}
}
long __machine_check_early_realmode_p9(struct pt_regs *regs)
{
uint64_t nip, addr;
long handled;
struct mce_error_info mce_error_info = { 0 };
nip = regs->nip;
if (P9_SRR1_MC_LOADSTORE(regs->msr)) {
handled = mce_handle_derror_p9(regs);
mce_get_derror_p9(regs, &mce_error_info, &addr);
} else {
handled = mce_handle_ierror_p9(regs);
mce_get_ierror_p9(regs, &mce_error_info, &addr);
}
if (mce_error_info.error_type == MCE_ERROR_TYPE_UE)
handled = mce_handle_ue_error(regs);
save_mce_event(regs, handled, &mce_error_info, nip, addr);
return handled;
}
