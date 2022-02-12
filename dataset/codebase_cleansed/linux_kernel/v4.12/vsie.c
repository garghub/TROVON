static int set_validity_icpt(struct kvm_s390_sie_block *scb,
__u16 reason_code)
{
scb->ipa = 0x1000;
scb->ipb = ((__u32) reason_code) << 16;
scb->icptcode = ICPT_VALIDITY;
return 1;
}
static void prefix_unmapped(struct vsie_page *vsie_page)
{
atomic_or(PROG_REQUEST, &vsie_page->scb_s.prog20);
}
static void prefix_unmapped_sync(struct vsie_page *vsie_page)
{
prefix_unmapped(vsie_page);
if (vsie_page->scb_s.prog0c & PROG_IN_SIE)
atomic_or(CPUSTAT_STOP_INT, &vsie_page->scb_s.cpuflags);
while (vsie_page->scb_s.prog0c & PROG_IN_SIE)
cpu_relax();
}
static void prefix_mapped(struct vsie_page *vsie_page)
{
atomic_andnot(PROG_REQUEST, &vsie_page->scb_s.prog20);
}
static int prefix_is_mapped(struct vsie_page *vsie_page)
{
return !(atomic_read(&vsie_page->scb_s.prog20) & PROG_REQUEST);
}
static void update_intervention_requests(struct vsie_page *vsie_page)
{
const int bits = CPUSTAT_STOP_INT | CPUSTAT_IO_INT | CPUSTAT_EXT_INT;
int cpuflags;
cpuflags = atomic_read(&vsie_page->scb_o->cpuflags);
atomic_andnot(bits, &vsie_page->scb_s.cpuflags);
atomic_or(cpuflags & bits, &vsie_page->scb_s.cpuflags);
}
static int prepare_cpuflags(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
struct kvm_s390_sie_block *scb_o = vsie_page->scb_o;
int newflags, cpuflags = atomic_read(&scb_o->cpuflags);
if (!(cpuflags & CPUSTAT_ZARCH))
return set_validity_icpt(scb_s, 0x0001U);
if (cpuflags & (CPUSTAT_RRF | CPUSTAT_MCDS))
return set_validity_icpt(scb_s, 0x0001U);
else if (cpuflags & (CPUSTAT_SLSV | CPUSTAT_SLSR))
return set_validity_icpt(scb_s, 0x0007U);
newflags = CPUSTAT_ZARCH;
if (cpuflags & CPUSTAT_GED && test_kvm_facility(vcpu->kvm, 8))
newflags |= CPUSTAT_GED;
if (cpuflags & CPUSTAT_GED2 && test_kvm_facility(vcpu->kvm, 78)) {
if (cpuflags & CPUSTAT_GED)
return set_validity_icpt(scb_s, 0x0001U);
newflags |= CPUSTAT_GED2;
}
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_GPERE))
newflags |= cpuflags & CPUSTAT_P;
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_GSLS))
newflags |= cpuflags & CPUSTAT_SM;
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_IBS))
newflags |= cpuflags & CPUSTAT_IBS;
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_KSS))
newflags |= cpuflags & CPUSTAT_KSS;
atomic_set(&scb_s->cpuflags, newflags);
return 0;
}
static int shadow_crycb(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
struct kvm_s390_sie_block *scb_o = vsie_page->scb_o;
u32 crycb_addr = scb_o->crycbd & 0x7ffffff8U;
unsigned long *b1, *b2;
u8 ecb3_flags;
scb_s->crycbd = 0;
if (!(scb_o->crycbd & vcpu->arch.sie_block->crycbd & CRYCB_FORMAT1))
return 0;
if (!test_kvm_facility(vcpu->kvm, 76))
return 0;
ecb3_flags = scb_o->ecb3 & vcpu->arch.sie_block->ecb3 &
(ECB3_AES | ECB3_DEA);
if (!ecb3_flags)
return 0;
if ((crycb_addr & PAGE_MASK) != ((crycb_addr + 128) & PAGE_MASK))
return set_validity_icpt(scb_s, 0x003CU);
else if (!crycb_addr)
return set_validity_icpt(scb_s, 0x0039U);
if (read_guest_real(vcpu, crycb_addr + 72, &vsie_page->crycb, 56))
return set_validity_icpt(scb_s, 0x0035U);
scb_s->ecb3 |= ecb3_flags;
scb_s->crycbd = ((__u32)(__u64) &vsie_page->crycb) | CRYCB_FORMAT1 |
CRYCB_FORMAT2;
b1 = (unsigned long *) vsie_page->crycb.dea_wrapping_key_mask;
b2 = (unsigned long *)
vcpu->kvm->arch.crypto.crycb->dea_wrapping_key_mask;
bitmap_xor(b1, b1, b2, BITS_PER_BYTE * 56);
return 0;
}
static void prepare_ibc(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
struct kvm_s390_sie_block *scb_o = vsie_page->scb_o;
__u64 min_ibc = (sclp.ibc >> 16) & 0x0fffU;
scb_s->ibc = 0;
if (vcpu->kvm->arch.model.ibc && (scb_o->ibc & 0x0fffU)) {
scb_s->ibc = scb_o->ibc & 0x0fffU;
if (scb_s->ibc < min_ibc)
scb_s->ibc = min_ibc;
if (scb_s->ibc > vcpu->kvm->arch.model.ibc)
scb_s->ibc = vcpu->kvm->arch.model.ibc;
}
}
static void unshadow_scb(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
struct kvm_s390_sie_block *scb_o = vsie_page->scb_o;
scb_o->icptcode = scb_s->icptcode;
scb_o->icptstatus = scb_s->icptstatus;
scb_o->ipa = scb_s->ipa;
scb_o->ipb = scb_s->ipb;
scb_o->gbea = scb_s->gbea;
scb_o->cputm = scb_s->cputm;
scb_o->ckc = scb_s->ckc;
scb_o->todpr = scb_s->todpr;
scb_o->gpsw = scb_s->gpsw;
scb_o->gg14 = scb_s->gg14;
scb_o->gg15 = scb_s->gg15;
memcpy(scb_o->gcr, scb_s->gcr, 128);
scb_o->pp = scb_s->pp;
switch (scb_s->icptcode) {
case ICPT_PROGI:
case ICPT_INSTPROGI:
case ICPT_EXTINT:
memcpy((void *)((u64)scb_o + 0xc0),
(void *)((u64)scb_s + 0xc0), 0xf0 - 0xc0);
break;
case ICPT_PARTEXEC:
memcpy((void *)((u64)scb_o + 0xc0),
(void *)((u64)scb_s + 0xc0), 0xd0 - 0xc0);
break;
}
if (scb_s->ihcpu != 0xffffU)
scb_o->ihcpu = scb_s->ihcpu;
}
static int shadow_scb(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_o = vsie_page->scb_o;
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
bool had_tx = scb_s->ecb & ECB_TE;
unsigned long new_mso = 0;
int rc;
scb_s->icptcode = 0;
scb_s->eca = 0;
scb_s->ecb = 0;
scb_s->ecb2 = 0;
scb_s->ecb3 = 0;
scb_s->ecd = 0;
scb_s->fac = 0;
rc = prepare_cpuflags(vcpu, vsie_page);
if (rc)
goto out;
scb_s->cputm = scb_o->cputm;
scb_s->ckc = scb_o->ckc;
scb_s->todpr = scb_o->todpr;
scb_s->epoch = scb_o->epoch;
scb_s->gpsw = scb_o->gpsw;
scb_s->gg14 = scb_o->gg14;
scb_s->gg15 = scb_o->gg15;
memcpy(scb_s->gcr, scb_o->gcr, 128);
scb_s->pp = scb_o->pp;
scb_s->gbea = scb_o->gbea;
scb_s->lctl = scb_o->lctl;
scb_s->svcc = scb_o->svcc;
scb_s->ictl = scb_o->ictl;
if (!(atomic_read(&scb_s->cpuflags) & CPUSTAT_KSS))
scb_s->ictl |= ICTL_ISKE | ICTL_SSKE | ICTL_RRBE;
scb_s->icpua = scb_o->icpua;
if (!(atomic_read(&scb_s->cpuflags) & CPUSTAT_SM))
new_mso = scb_o->mso & 0xfffffffffff00000UL;
if (scb_s->mso != new_mso || scb_s->prefix != scb_o->prefix)
prefix_unmapped(vsie_page);
scb_s->msl = scb_o->msl & 0xfffffffffff00000UL;
scb_s->mso = new_mso;
scb_s->prefix = scb_o->prefix;
if (scb_s->ihcpu != 0xffffU)
scb_s->ihcpu = scb_o->ihcpu;
scb_s->eca |= scb_o->eca & (ECA_MVPGI | ECA_PROTEXCI);
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_ESOP))
scb_s->ecb |= scb_o->ecb & ECB_HOSTPROTINT;
if (test_kvm_facility(vcpu->kvm, 73)) {
if ((scb_o->ecb & ECB_TE) && !had_tx)
prefix_unmapped(vsie_page);
scb_s->ecb |= scb_o->ecb & ECB_TE;
}
if (test_kvm_facility(vcpu->kvm, 129)) {
scb_s->eca |= scb_o->eca & ECA_VX;
scb_s->ecd |= scb_o->ecd & ECD_HOSTREGMGMT;
}
if (test_kvm_facility(vcpu->kvm, 64))
scb_s->ecb3 |= scb_o->ecb3 & ECB3_RI;
if (test_kvm_facility(vcpu->kvm, 130))
scb_s->ecb2 |= scb_o->ecb2 & ECB2_IEP;
if (test_kvm_facility(vcpu->kvm, 133)) {
scb_s->ecb |= scb_o->ecb & ECB_GS;
scb_s->ecd |= scb_o->ecd & ECD_HOSTREGMGMT;
}
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_SIIF))
scb_s->eca |= scb_o->eca & ECA_SII;
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_IB))
scb_s->eca |= scb_o->eca & ECA_IB;
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_CEI))
scb_s->eca |= scb_o->eca & ECA_CEI;
prepare_ibc(vcpu, vsie_page);
rc = shadow_crycb(vcpu, vsie_page);
out:
if (rc)
unshadow_scb(vcpu, vsie_page);
return rc;
}
void kvm_s390_vsie_gmap_notifier(struct gmap *gmap, unsigned long start,
unsigned long end)
{
struct kvm *kvm = gmap->private;
struct vsie_page *cur;
unsigned long prefix;
struct page *page;
int i;
if (!gmap_is_shadow(gmap))
return;
if (start >= 1UL << 31)
return;
for (i = 0; i < kvm->arch.vsie.page_count; i++) {
page = READ_ONCE(kvm->arch.vsie.pages[i]);
if (!page)
continue;
cur = page_to_virt(page);
if (READ_ONCE(cur->gmap) != gmap)
continue;
prefix = cur->scb_s.prefix << GUEST_PREFIX_SHIFT;
prefix += cur->scb_s.mso;
if (prefix <= end && start <= prefix + 2 * PAGE_SIZE - 1)
prefix_unmapped_sync(cur);
}
}
static int map_prefix(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
u64 prefix = scb_s->prefix << GUEST_PREFIX_SHIFT;
int rc;
if (prefix_is_mapped(vsie_page))
return 0;
prefix_mapped(vsie_page);
prefix += scb_s->mso;
rc = kvm_s390_shadow_fault(vcpu, vsie_page->gmap, prefix);
if (!rc && (scb_s->ecb & ECB_TE))
rc = kvm_s390_shadow_fault(vcpu, vsie_page->gmap,
prefix + PAGE_SIZE);
if (rc)
prefix_unmapped(vsie_page);
if (rc > 0 || rc == -EFAULT)
rc = set_validity_icpt(scb_s, 0x0037U);
return rc;
}
static int pin_guest_page(struct kvm *kvm, gpa_t gpa, hpa_t *hpa)
{
struct page *page;
hva_t hva;
int rc;
hva = gfn_to_hva(kvm, gpa_to_gfn(gpa));
if (kvm_is_error_hva(hva))
return -EINVAL;
rc = get_user_pages_fast(hva, 1, 1, &page);
if (rc < 0)
return rc;
else if (rc != 1)
return -ENOMEM;
*hpa = (hpa_t) page_to_virt(page) + (gpa & ~PAGE_MASK);
return 0;
}
static void unpin_guest_page(struct kvm *kvm, gpa_t gpa, hpa_t hpa)
{
struct page *page;
page = virt_to_page(hpa);
set_page_dirty_lock(page);
put_page(page);
mark_page_dirty(kvm, gpa_to_gfn(gpa));
}
static void unpin_blocks(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_o = vsie_page->scb_o;
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
hpa_t hpa;
gpa_t gpa;
hpa = (u64) scb_s->scaoh << 32 | scb_s->scaol;
if (hpa) {
gpa = scb_o->scaol & ~0xfUL;
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_64BSCAO))
gpa |= (u64) scb_o->scaoh << 32;
unpin_guest_page(vcpu->kvm, gpa, hpa);
scb_s->scaol = 0;
scb_s->scaoh = 0;
}
hpa = scb_s->itdba;
if (hpa) {
gpa = scb_o->itdba & ~0xffUL;
unpin_guest_page(vcpu->kvm, gpa, hpa);
scb_s->itdba = 0;
}
hpa = scb_s->gvrd;
if (hpa) {
gpa = scb_o->gvrd & ~0x1ffUL;
unpin_guest_page(vcpu->kvm, gpa, hpa);
scb_s->gvrd = 0;
}
hpa = scb_s->riccbd;
if (hpa) {
gpa = scb_o->riccbd & ~0x3fUL;
unpin_guest_page(vcpu->kvm, gpa, hpa);
scb_s->riccbd = 0;
}
hpa = scb_s->sdnxo;
if (hpa) {
gpa = scb_o->sdnxo;
unpin_guest_page(vcpu->kvm, gpa, hpa);
scb_s->sdnxo = 0;
}
}
static int pin_blocks(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_o = vsie_page->scb_o;
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
hpa_t hpa;
gpa_t gpa;
int rc = 0;
gpa = scb_o->scaol & ~0xfUL;
if (test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_64BSCAO))
gpa |= (u64) scb_o->scaoh << 32;
if (gpa) {
if (!(gpa & ~0x1fffUL))
rc = set_validity_icpt(scb_s, 0x0038U);
else if ((gpa & ~0x1fffUL) == kvm_s390_get_prefix(vcpu))
rc = set_validity_icpt(scb_s, 0x0011U);
else if ((gpa & PAGE_MASK) !=
((gpa + sizeof(struct bsca_block) - 1) & PAGE_MASK))
rc = set_validity_icpt(scb_s, 0x003bU);
if (!rc) {
rc = pin_guest_page(vcpu->kvm, gpa, &hpa);
if (rc == -EINVAL)
rc = set_validity_icpt(scb_s, 0x0034U);
}
if (rc)
goto unpin;
scb_s->scaoh = (u32)((u64)hpa >> 32);
scb_s->scaol = (u32)(u64)hpa;
}
gpa = scb_o->itdba & ~0xffUL;
if (gpa && (scb_s->ecb & ECB_TE)) {
if (!(gpa & ~0x1fffU)) {
rc = set_validity_icpt(scb_s, 0x0080U);
goto unpin;
}
rc = pin_guest_page(vcpu->kvm, gpa, &hpa);
if (rc == -EINVAL)
rc = set_validity_icpt(scb_s, 0x0080U);
if (rc)
goto unpin;
scb_s->itdba = hpa;
}
gpa = scb_o->gvrd & ~0x1ffUL;
if (gpa && (scb_s->eca & ECA_VX) && !(scb_s->ecd & ECD_HOSTREGMGMT)) {
if (!(gpa & ~0x1fffUL)) {
rc = set_validity_icpt(scb_s, 0x1310U);
goto unpin;
}
rc = pin_guest_page(vcpu->kvm, gpa, &hpa);
if (rc == -EINVAL)
rc = set_validity_icpt(scb_s, 0x1310U);
if (rc)
goto unpin;
scb_s->gvrd = hpa;
}
gpa = scb_o->riccbd & ~0x3fUL;
if (gpa && (scb_s->ecb3 & ECB3_RI)) {
if (!(gpa & ~0x1fffUL)) {
rc = set_validity_icpt(scb_s, 0x0043U);
goto unpin;
}
rc = pin_guest_page(vcpu->kvm, gpa, &hpa);
if (rc == -EINVAL)
rc = set_validity_icpt(scb_s, 0x0043U);
if (rc)
goto unpin;
scb_s->riccbd = hpa;
}
if ((scb_s->ecb & ECB_GS) && !(scb_s->ecd & ECD_HOSTREGMGMT)) {
unsigned long sdnxc;
gpa = scb_o->sdnxo & ~0xfUL;
sdnxc = scb_o->sdnxo & 0xfUL;
if (!gpa || !(gpa & ~0x1fffUL)) {
rc = set_validity_icpt(scb_s, 0x10b0U);
goto unpin;
}
if (sdnxc < 6 || sdnxc > 12) {
rc = set_validity_icpt(scb_s, 0x10b1U);
goto unpin;
}
if (gpa & ((1 << sdnxc) - 1)) {
rc = set_validity_icpt(scb_s, 0x10b2U);
goto unpin;
}
rc = pin_guest_page(vcpu->kvm, gpa, &hpa);
if (rc == -EINVAL)
rc = set_validity_icpt(scb_s, 0x10b0U);
if (rc)
goto unpin;
scb_s->sdnxo = hpa | sdnxc;
}
return 0;
unpin:
unpin_blocks(vcpu, vsie_page);
return rc;
}
static void unpin_scb(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page,
gpa_t gpa)
{
hpa_t hpa = (hpa_t) vsie_page->scb_o;
if (hpa)
unpin_guest_page(vcpu->kvm, gpa, hpa);
vsie_page->scb_o = NULL;
}
static int pin_scb(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page,
gpa_t gpa)
{
hpa_t hpa;
int rc;
rc = pin_guest_page(vcpu->kvm, gpa, &hpa);
if (rc == -EINVAL) {
rc = kvm_s390_inject_program_int(vcpu, PGM_ADDRESSING);
if (!rc)
rc = 1;
}
if (!rc)
vsie_page->scb_o = (struct kvm_s390_sie_block *) hpa;
return rc;
}
static int inject_fault(struct kvm_vcpu *vcpu, __u16 code, __u64 vaddr,
bool write_flag)
{
struct kvm_s390_pgm_info pgm = {
.code = code,
.trans_exc_code =
(vaddr & 0xfffffffffffff000UL) |
(((unsigned int) !write_flag) + 1) << 10,
.exc_access_id = 0,
.op_access_id = 0,
};
int rc;
if (code == PGM_PROTECTION)
pgm.trans_exc_code |= 0x4UL;
rc = kvm_s390_inject_prog_irq(vcpu, &pgm);
return rc ? rc : 1;
}
static int handle_fault(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
int rc;
if (current->thread.gmap_int_code == PGM_PROTECTION)
return inject_fault(vcpu, PGM_PROTECTION,
current->thread.gmap_addr, 1);
rc = kvm_s390_shadow_fault(vcpu, vsie_page->gmap,
current->thread.gmap_addr);
if (rc > 0) {
rc = inject_fault(vcpu, rc,
current->thread.gmap_addr,
current->thread.gmap_write_flag);
if (rc >= 0)
vsie_page->fault_addr = current->thread.gmap_addr;
}
return rc;
}
static void handle_last_fault(struct kvm_vcpu *vcpu,
struct vsie_page *vsie_page)
{
if (vsie_page->fault_addr)
kvm_s390_shadow_fault(vcpu, vsie_page->gmap,
vsie_page->fault_addr);
vsie_page->fault_addr = 0;
}
static inline void clear_vsie_icpt(struct vsie_page *vsie_page)
{
vsie_page->scb_s.icptcode = 0;
}
static void retry_vsie_icpt(struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
int ilen = insn_length(scb_s->ipa >> 8);
if (scb_s->icptstatus & 1) {
ilen = (scb_s->icptstatus >> 4) & 0x6;
if (!ilen)
ilen = 4;
}
scb_s->gpsw.addr = __rewind_psw(scb_s->gpsw, ilen);
clear_vsie_icpt(vsie_page);
}
static int handle_stfle(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
__u32 fac = vsie_page->scb_o->fac & 0x7ffffff8U;
if (fac && test_kvm_facility(vcpu->kvm, 7)) {
retry_vsie_icpt(vsie_page);
if (read_guest_real(vcpu, fac, &vsie_page->fac,
sizeof(vsie_page->fac)))
return set_validity_icpt(scb_s, 0x1090U);
scb_s->fac = (__u32)(__u64) &vsie_page->fac;
}
return 0;
}
static int do_vsie_run(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
struct kvm_s390_sie_block *scb_o = vsie_page->scb_o;
int rc;
handle_last_fault(vcpu, vsie_page);
if (need_resched())
schedule();
if (test_cpu_flag(CIF_MCCK_PENDING))
s390_handle_mcck();
srcu_read_unlock(&vcpu->kvm->srcu, vcpu->srcu_idx);
local_irq_disable();
guest_enter_irqoff();
local_irq_enable();
rc = sie64a(scb_s, vcpu->run->s.regs.gprs);
local_irq_disable();
guest_exit_irqoff();
local_irq_enable();
vcpu->srcu_idx = srcu_read_lock(&vcpu->kvm->srcu);
if (rc > 0)
rc = 0;
else if (rc == -EFAULT)
return handle_fault(vcpu, vsie_page);
switch (scb_s->icptcode) {
case ICPT_INST:
if (scb_s->ipa == 0xb2b0)
rc = handle_stfle(vcpu, vsie_page);
break;
case ICPT_STOP:
if (!(atomic_read(&scb_o->cpuflags) & CPUSTAT_STOP_INT))
clear_vsie_icpt(vsie_page);
break;
case ICPT_VALIDITY:
if ((scb_s->ipa & 0xf000) != 0xf000)
scb_s->ipa += 0x1000;
break;
}
return rc;
}
static void release_gmap_shadow(struct vsie_page *vsie_page)
{
if (vsie_page->gmap)
gmap_put(vsie_page->gmap);
WRITE_ONCE(vsie_page->gmap, NULL);
prefix_unmapped(vsie_page);
}
static int acquire_gmap_shadow(struct kvm_vcpu *vcpu,
struct vsie_page *vsie_page)
{
unsigned long asce;
union ctlreg0 cr0;
struct gmap *gmap;
int edat;
asce = vcpu->arch.sie_block->gcr[1];
cr0.val = vcpu->arch.sie_block->gcr[0];
edat = cr0.edat && test_kvm_facility(vcpu->kvm, 8);
edat += edat && test_kvm_facility(vcpu->kvm, 78);
if (vsie_page->gmap && gmap_shadow_valid(vsie_page->gmap, asce, edat))
return 0;
release_gmap_shadow(vsie_page);
gmap = gmap_shadow(vcpu->arch.gmap, asce, edat);
if (IS_ERR(gmap))
return PTR_ERR(gmap);
gmap->private = vcpu->kvm;
WRITE_ONCE(vsie_page->gmap, gmap);
return 0;
}
static void register_shadow_scb(struct kvm_vcpu *vcpu,
struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
WRITE_ONCE(vcpu->arch.vsie_block, &vsie_page->scb_s);
atomic_or(CPUSTAT_WAIT, &vcpu->arch.sie_block->cpuflags);
preempt_disable();
scb_s->epoch += vcpu->kvm->arch.epoch;
preempt_enable();
}
static void unregister_shadow_scb(struct kvm_vcpu *vcpu)
{
atomic_andnot(CPUSTAT_WAIT, &vcpu->arch.sie_block->cpuflags);
WRITE_ONCE(vcpu->arch.vsie_block, NULL);
}
static int vsie_run(struct kvm_vcpu *vcpu, struct vsie_page *vsie_page)
{
struct kvm_s390_sie_block *scb_s = &vsie_page->scb_s;
int rc = 0;
while (1) {
rc = acquire_gmap_shadow(vcpu, vsie_page);
if (!rc)
rc = map_prefix(vcpu, vsie_page);
if (!rc) {
gmap_enable(vsie_page->gmap);
update_intervention_requests(vsie_page);
rc = do_vsie_run(vcpu, vsie_page);
gmap_enable(vcpu->arch.gmap);
}
atomic_andnot(PROG_BLOCK_SIE, &scb_s->prog20);
if (rc == -EAGAIN)
rc = 0;
if (rc || scb_s->icptcode || signal_pending(current) ||
kvm_s390_vcpu_has_irq(vcpu, 0))
break;
}
if (rc == -EFAULT) {
scb_s->icptcode = ICPT_PROGI;
scb_s->iprcc = PGM_ADDRESSING;
scb_s->pgmilc = 4;
scb_s->gpsw.addr = __rewind_psw(scb_s->gpsw, 4);
}
return rc;
}
static struct vsie_page *get_vsie_page(struct kvm *kvm, unsigned long addr)
{
struct vsie_page *vsie_page;
struct page *page;
int nr_vcpus;
rcu_read_lock();
page = radix_tree_lookup(&kvm->arch.vsie.addr_to_page, addr >> 9);
rcu_read_unlock();
if (page) {
if (page_ref_inc_return(page) == 2)
return page_to_virt(page);
page_ref_dec(page);
}
nr_vcpus = atomic_read(&kvm->online_vcpus);
mutex_lock(&kvm->arch.vsie.mutex);
if (kvm->arch.vsie.page_count < nr_vcpus) {
page = alloc_page(GFP_KERNEL | __GFP_ZERO | GFP_DMA);
if (!page) {
mutex_unlock(&kvm->arch.vsie.mutex);
return ERR_PTR(-ENOMEM);
}
page_ref_inc(page);
kvm->arch.vsie.pages[kvm->arch.vsie.page_count] = page;
kvm->arch.vsie.page_count++;
} else {
while (true) {
page = kvm->arch.vsie.pages[kvm->arch.vsie.next];
if (page_ref_inc_return(page) == 2)
break;
page_ref_dec(page);
kvm->arch.vsie.next++;
kvm->arch.vsie.next %= nr_vcpus;
}
radix_tree_delete(&kvm->arch.vsie.addr_to_page, page->index >> 9);
}
page->index = addr;
if (radix_tree_insert(&kvm->arch.vsie.addr_to_page, addr >> 9, page)) {
page_ref_dec(page);
mutex_unlock(&kvm->arch.vsie.mutex);
return NULL;
}
mutex_unlock(&kvm->arch.vsie.mutex);
vsie_page = page_to_virt(page);
memset(&vsie_page->scb_s, 0, sizeof(struct kvm_s390_sie_block));
release_gmap_shadow(vsie_page);
vsie_page->fault_addr = 0;
vsie_page->scb_s.ihcpu = 0xffffU;
return vsie_page;
}
static void put_vsie_page(struct kvm *kvm, struct vsie_page *vsie_page)
{
struct page *page = pfn_to_page(__pa(vsie_page) >> PAGE_SHIFT);
page_ref_dec(page);
}
int kvm_s390_handle_vsie(struct kvm_vcpu *vcpu)
{
struct vsie_page *vsie_page;
unsigned long scb_addr;
int rc;
vcpu->stat.instruction_sie++;
if (!test_kvm_cpu_feat(vcpu->kvm, KVM_S390_VM_CPU_FEAT_SIEF2))
return -EOPNOTSUPP;
if (vcpu->arch.sie_block->gpsw.mask & PSW_MASK_PSTATE)
return kvm_s390_inject_program_int(vcpu, PGM_PRIVILEGED_OP);
BUILD_BUG_ON(sizeof(struct vsie_page) != 4096);
scb_addr = kvm_s390_get_base_disp_s(vcpu, NULL);
if (unlikely(scb_addr & 0x1ffUL))
return kvm_s390_inject_program_int(vcpu, PGM_SPECIFICATION);
if (signal_pending(current) || kvm_s390_vcpu_has_irq(vcpu, 0))
return 0;
vsie_page = get_vsie_page(vcpu->kvm, scb_addr);
if (IS_ERR(vsie_page))
return PTR_ERR(vsie_page);
else if (!vsie_page)
return 0;
rc = pin_scb(vcpu, vsie_page, scb_addr);
if (rc)
goto out_put;
rc = shadow_scb(vcpu, vsie_page);
if (rc)
goto out_unpin_scb;
rc = pin_blocks(vcpu, vsie_page);
if (rc)
goto out_unshadow;
register_shadow_scb(vcpu, vsie_page);
rc = vsie_run(vcpu, vsie_page);
unregister_shadow_scb(vcpu);
unpin_blocks(vcpu, vsie_page);
out_unshadow:
unshadow_scb(vcpu, vsie_page);
out_unpin_scb:
unpin_scb(vcpu, vsie_page, scb_addr);
out_put:
put_vsie_page(vcpu->kvm, vsie_page);
return rc < 0 ? rc : 0;
}
void kvm_s390_vsie_init(struct kvm *kvm)
{
mutex_init(&kvm->arch.vsie.mutex);
INIT_RADIX_TREE(&kvm->arch.vsie.addr_to_page, GFP_KERNEL);
}
void kvm_s390_vsie_destroy(struct kvm *kvm)
{
struct vsie_page *vsie_page;
struct page *page;
int i;
mutex_lock(&kvm->arch.vsie.mutex);
for (i = 0; i < kvm->arch.vsie.page_count; i++) {
page = kvm->arch.vsie.pages[i];
kvm->arch.vsie.pages[i] = NULL;
vsie_page = page_to_virt(page);
release_gmap_shadow(vsie_page);
radix_tree_delete(&kvm->arch.vsie.addr_to_page, page->index >> 9);
__free_page(page);
}
kvm->arch.vsie.page_count = 0;
mutex_unlock(&kvm->arch.vsie.mutex);
}
void kvm_s390_vsie_kick(struct kvm_vcpu *vcpu)
{
struct kvm_s390_sie_block *scb = READ_ONCE(vcpu->arch.vsie_block);
if (scb) {
atomic_or(PROG_BLOCK_SIE, &scb->prog20);
if (scb->prog0c & PROG_IN_SIE)
atomic_or(CPUSTAT_STOP_INT, &scb->cpuflags);
}
}
