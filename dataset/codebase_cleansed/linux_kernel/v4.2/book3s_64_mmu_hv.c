long kvmppc_alloc_hpt(struct kvm *kvm, u32 *htab_orderp)
{
unsigned long hpt = 0;
struct revmap_entry *rev;
struct page *page = NULL;
long order = KVM_DEFAULT_HPT_ORDER;
if (htab_orderp) {
order = *htab_orderp;
if (order < PPC_MIN_HPT_ORDER)
order = PPC_MIN_HPT_ORDER;
}
kvm->arch.hpt_cma_alloc = 0;
page = kvm_alloc_hpt(1ul << (order - PAGE_SHIFT));
if (page) {
hpt = (unsigned long)pfn_to_kaddr(page_to_pfn(page));
memset((void *)hpt, 0, (1ul << order));
kvm->arch.hpt_cma_alloc = 1;
}
while (!hpt && order > PPC_MIN_HPT_ORDER) {
hpt = __get_free_pages(GFP_KERNEL|__GFP_ZERO|__GFP_REPEAT|
__GFP_NOWARN, order - PAGE_SHIFT);
if (!hpt)
--order;
}
if (!hpt)
return -ENOMEM;
kvm->arch.hpt_virt = hpt;
kvm->arch.hpt_order = order;
kvm->arch.hpt_npte = 1ul << (order - 4);
kvm->arch.hpt_mask = (1ul << (order - 7)) - 1;
rev = vmalloc(sizeof(struct revmap_entry) * kvm->arch.hpt_npte);
if (!rev) {
pr_err("kvmppc_alloc_hpt: Couldn't alloc reverse map array\n");
goto out_freehpt;
}
kvm->arch.revmap = rev;
kvm->arch.sdr1 = __pa(hpt) | (order - 18);
pr_info("KVM guest htab at %lx (order %ld), LPID %x\n",
hpt, order, kvm->arch.lpid);
if (htab_orderp)
*htab_orderp = order;
return 0;
out_freehpt:
if (kvm->arch.hpt_cma_alloc)
kvm_release_hpt(page, 1 << (order - PAGE_SHIFT));
else
free_pages(hpt, order - PAGE_SHIFT);
return -ENOMEM;
}
long kvmppc_alloc_reset_hpt(struct kvm *kvm, u32 *htab_orderp)
{
long err = -EBUSY;
long order;
mutex_lock(&kvm->lock);
if (kvm->arch.hpte_setup_done) {
kvm->arch.hpte_setup_done = 0;
smp_mb();
if (atomic_read(&kvm->arch.vcpus_running)) {
kvm->arch.hpte_setup_done = 1;
goto out;
}
}
if (kvm->arch.hpt_virt) {
order = kvm->arch.hpt_order;
memset((void *)kvm->arch.hpt_virt, 0, 1ul << order);
kvmppc_rmap_reset(kvm);
cpumask_setall(&kvm->arch.need_tlb_flush);
*htab_orderp = order;
err = 0;
} else {
err = kvmppc_alloc_hpt(kvm, htab_orderp);
order = *htab_orderp;
}
out:
mutex_unlock(&kvm->lock);
return err;
}
void kvmppc_free_hpt(struct kvm *kvm)
{
kvmppc_free_lpid(kvm->arch.lpid);
vfree(kvm->arch.revmap);
if (kvm->arch.hpt_cma_alloc)
kvm_release_hpt(virt_to_page(kvm->arch.hpt_virt),
1 << (kvm->arch.hpt_order - PAGE_SHIFT));
else
free_pages(kvm->arch.hpt_virt,
kvm->arch.hpt_order - PAGE_SHIFT);
}
static inline unsigned long hpte0_pgsize_encoding(unsigned long pgsize)
{
return (pgsize > 0x1000) ? HPTE_V_LARGE : 0;
}
static inline unsigned long hpte1_pgsize_encoding(unsigned long pgsize)
{
return (pgsize == 0x10000) ? 0x1000 : 0;
}
void kvmppc_map_vrma(struct kvm_vcpu *vcpu, struct kvm_memory_slot *memslot,
unsigned long porder)
{
unsigned long i;
unsigned long npages;
unsigned long hp_v, hp_r;
unsigned long addr, hash;
unsigned long psize;
unsigned long hp0, hp1;
unsigned long idx_ret;
long ret;
struct kvm *kvm = vcpu->kvm;
psize = 1ul << porder;
npages = memslot->npages >> (porder - PAGE_SHIFT);
if (npages > 1ul << (40 - porder))
npages = 1ul << (40 - porder);
if (npages > kvm->arch.hpt_mask + 1)
npages = kvm->arch.hpt_mask + 1;
hp0 = HPTE_V_1TB_SEG | (VRMA_VSID << (40 - 16)) |
HPTE_V_BOLTED | hpte0_pgsize_encoding(psize);
hp1 = hpte1_pgsize_encoding(psize) |
HPTE_R_R | HPTE_R_C | HPTE_R_M | PP_RWXX;
for (i = 0; i < npages; ++i) {
addr = i << porder;
hash = (i ^ (VRMA_VSID ^ (VRMA_VSID << 25))) & kvm->arch.hpt_mask;
hash = (hash << 3) + 7;
hp_v = hp0 | ((addr >> 16) & ~0x7fUL);
hp_r = hp1 | addr;
ret = kvmppc_virtmode_do_h_enter(kvm, H_EXACT, hash, hp_v, hp_r,
&idx_ret);
if (ret != H_SUCCESS) {
pr_err("KVM: map_vrma at %lx failed, ret=%ld\n",
addr, ret);
break;
}
}
}
int kvmppc_mmu_hv_init(void)
{
unsigned long host_lpid, rsvd_lpid;
if (!cpu_has_feature(CPU_FTR_HVMODE))
return -EINVAL;
host_lpid = mfspr(SPRN_LPID);
rsvd_lpid = LPID_RSVD;
kvmppc_init_lpid(rsvd_lpid + 1);
kvmppc_claim_lpid(host_lpid);
kvmppc_claim_lpid(rsvd_lpid);
return 0;
}
static void kvmppc_mmu_book3s_64_hv_reset_msr(struct kvm_vcpu *vcpu)
{
unsigned long msr = vcpu->arch.intr_msr;
if (MSR_TM_TRANSACTIONAL(vcpu->arch.shregs.msr))
msr |= MSR_TS_S;
else
msr |= vcpu->arch.shregs.msr & MSR_TS_MASK;
kvmppc_set_msr(vcpu, msr);
}
long kvmppc_virtmode_do_h_enter(struct kvm *kvm, unsigned long flags,
long pte_index, unsigned long pteh,
unsigned long ptel, unsigned long *pte_idx_ret)
{
long ret;
rcu_read_lock_sched();
ret = kvmppc_do_h_enter(kvm, flags, pte_index, pteh, ptel,
current->mm->pgd, false, pte_idx_ret);
rcu_read_unlock_sched();
if (ret == H_TOO_HARD) {
pr_err("KVM: Oops, kvmppc_h_enter returned too hard!\n");
ret = H_RESOURCE;
}
return ret;
}
static struct kvmppc_slb *kvmppc_mmu_book3s_hv_find_slbe(struct kvm_vcpu *vcpu,
gva_t eaddr)
{
u64 mask;
int i;
for (i = 0; i < vcpu->arch.slb_nr; i++) {
if (!(vcpu->arch.slb[i].orige & SLB_ESID_V))
continue;
if (vcpu->arch.slb[i].origv & SLB_VSID_B_1T)
mask = ESID_MASK_1T;
else
mask = ESID_MASK;
if (((vcpu->arch.slb[i].orige ^ eaddr) & mask) == 0)
return &vcpu->arch.slb[i];
}
return NULL;
}
static unsigned long kvmppc_mmu_get_real_addr(unsigned long v, unsigned long r,
unsigned long ea)
{
unsigned long ra_mask;
ra_mask = hpte_page_size(v, r) - 1;
return (r & HPTE_R_RPN & ~ra_mask) | (ea & ra_mask);
}
static int kvmppc_mmu_book3s_64_hv_xlate(struct kvm_vcpu *vcpu, gva_t eaddr,
struct kvmppc_pte *gpte, bool data, bool iswrite)
{
struct kvm *kvm = vcpu->kvm;
struct kvmppc_slb *slbe;
unsigned long slb_v;
unsigned long pp, key;
unsigned long v, gr;
__be64 *hptep;
int index;
int virtmode = vcpu->arch.shregs.msr & (data ? MSR_DR : MSR_IR);
if (virtmode) {
slbe = kvmppc_mmu_book3s_hv_find_slbe(vcpu, eaddr);
if (!slbe)
return -EINVAL;
slb_v = slbe->origv;
} else {
slb_v = vcpu->kvm->arch.vrma_slb_v;
}
preempt_disable();
index = kvmppc_hv_find_lock_hpte(kvm, eaddr, slb_v,
HPTE_V_VALID | HPTE_V_ABSENT);
if (index < 0) {
preempt_enable();
return -ENOENT;
}
hptep = (__be64 *)(kvm->arch.hpt_virt + (index << 4));
v = be64_to_cpu(hptep[0]) & ~HPTE_V_HVLOCK;
gr = kvm->arch.revmap[index].guest_rpte;
unlock_hpte(hptep, v);
preempt_enable();
gpte->eaddr = eaddr;
gpte->vpage = ((v & HPTE_V_AVPN) << 4) | ((eaddr >> 12) & 0xfff);
pp = gr & (HPTE_R_PP0 | HPTE_R_PP);
key = (vcpu->arch.shregs.msr & MSR_PR) ? SLB_VSID_KP : SLB_VSID_KS;
key &= slb_v;
gpte->may_read = hpte_read_permission(pp, key);
gpte->may_write = hpte_write_permission(pp, key);
gpte->may_execute = gpte->may_read && !(gr & (HPTE_R_N | HPTE_R_G));
if (data && virtmode) {
int amrfield = hpte_get_skey_perm(gr, vcpu->arch.amr);
if (amrfield & 1)
gpte->may_read = 0;
if (amrfield & 2)
gpte->may_write = 0;
}
gpte->raddr = kvmppc_mmu_get_real_addr(v, gr, eaddr);
return 0;
}
static int instruction_is_store(unsigned int instr)
{
unsigned int mask;
mask = 0x10000000;
if ((instr & 0xfc000000) == 0x7c000000)
mask = 0x100;
return (instr & mask) != 0;
}
static int kvmppc_hv_emulate_mmio(struct kvm_run *run, struct kvm_vcpu *vcpu,
unsigned long gpa, gva_t ea, int is_store)
{
u32 last_inst;
if (kvmppc_get_last_inst(vcpu, INST_GENERIC, &last_inst) !=
EMULATE_DONE)
return RESUME_GUEST;
if (instruction_is_store(last_inst) != !!is_store)
return RESUME_GUEST;
vcpu->arch.paddr_accessed = gpa;
vcpu->arch.vaddr_accessed = ea;
return kvmppc_emulate_mmio(run, vcpu);
}
int kvmppc_book3s_hv_page_fault(struct kvm_run *run, struct kvm_vcpu *vcpu,
unsigned long ea, unsigned long dsisr)
{
struct kvm *kvm = vcpu->kvm;
unsigned long hpte[3], r;
__be64 *hptep;
unsigned long mmu_seq, psize, pte_size;
unsigned long gpa_base, gfn_base;
unsigned long gpa, gfn, hva, pfn;
struct kvm_memory_slot *memslot;
unsigned long *rmap;
struct revmap_entry *rev;
struct page *page, *pages[1];
long index, ret, npages;
unsigned long is_io;
unsigned int writing, write_ok;
struct vm_area_struct *vma;
unsigned long rcbits;
if (ea != vcpu->arch.pgfault_addr)
return RESUME_GUEST;
index = vcpu->arch.pgfault_index;
hptep = (__be64 *)(kvm->arch.hpt_virt + (index << 4));
rev = &kvm->arch.revmap[index];
preempt_disable();
while (!try_lock_hpte(hptep, HPTE_V_HVLOCK))
cpu_relax();
hpte[0] = be64_to_cpu(hptep[0]) & ~HPTE_V_HVLOCK;
hpte[1] = be64_to_cpu(hptep[1]);
hpte[2] = r = rev->guest_rpte;
unlock_hpte(hptep, hpte[0]);
preempt_enable();
if (hpte[0] != vcpu->arch.pgfault_hpte[0] ||
hpte[1] != vcpu->arch.pgfault_hpte[1])
return RESUME_GUEST;
psize = hpte_page_size(hpte[0], r);
gpa_base = r & HPTE_R_RPN & ~(psize - 1);
gfn_base = gpa_base >> PAGE_SHIFT;
gpa = gpa_base | (ea & (psize - 1));
gfn = gpa >> PAGE_SHIFT;
memslot = gfn_to_memslot(kvm, gfn);
trace_kvm_page_fault_enter(vcpu, hpte, memslot, ea, dsisr);
if (!memslot || (memslot->flags & KVM_MEMSLOT_INVALID))
return kvmppc_hv_emulate_mmio(run, vcpu, gpa, ea,
dsisr & DSISR_ISSTORE);
if (gfn_base < memslot->base_gfn)
return -EFAULT;
mmu_seq = kvm->mmu_notifier_seq;
smp_rmb();
ret = -EFAULT;
is_io = 0;
pfn = 0;
page = NULL;
pte_size = PAGE_SIZE;
writing = (dsisr & DSISR_ISSTORE) != 0;
write_ok = writing;
hva = gfn_to_hva_memslot(memslot, gfn);
npages = get_user_pages_fast(hva, 1, writing, pages);
if (npages < 1) {
down_read(&current->mm->mmap_sem);
vma = find_vma(current->mm, hva);
if (vma && vma->vm_start <= hva && hva + psize <= vma->vm_end &&
(vma->vm_flags & VM_PFNMAP)) {
pfn = vma->vm_pgoff +
((hva - vma->vm_start) >> PAGE_SHIFT);
pte_size = psize;
is_io = hpte_cache_bits(pgprot_val(vma->vm_page_prot));
write_ok = vma->vm_flags & VM_WRITE;
}
up_read(&current->mm->mmap_sem);
if (!pfn)
goto out_put;
} else {
page = pages[0];
pfn = page_to_pfn(page);
if (PageHuge(page)) {
page = compound_head(page);
pte_size <<= compound_order(page);
}
if (!writing && hpte_is_writable(r)) {
pte_t *ptep, pte;
unsigned long flags;
local_irq_save(flags);
ptep = find_linux_pte_or_hugepte(current->mm->pgd,
hva, NULL);
if (ptep) {
pte = kvmppc_read_update_linux_pte(ptep, 1);
if (pte_write(pte))
write_ok = 1;
}
local_irq_restore(flags);
}
}
if (psize > pte_size)
goto out_put;
if (!hpte_cache_flags_ok(r, is_io)) {
if (is_io)
goto out_put;
r = (r & ~(HPTE_R_W|HPTE_R_I|HPTE_R_G)) | HPTE_R_M;
}
if (psize < PAGE_SIZE)
psize = PAGE_SIZE;
r = (r & ~(HPTE_R_PP0 - psize)) | ((pfn << PAGE_SHIFT) & ~(psize - 1));
if (hpte_is_writable(r) && !write_ok)
r = hpte_make_readonly(r);
ret = RESUME_GUEST;
preempt_disable();
while (!try_lock_hpte(hptep, HPTE_V_HVLOCK))
cpu_relax();
if ((be64_to_cpu(hptep[0]) & ~HPTE_V_HVLOCK) != hpte[0] ||
be64_to_cpu(hptep[1]) != hpte[1] ||
rev->guest_rpte != hpte[2])
goto out_unlock;
hpte[0] = (hpte[0] & ~HPTE_V_ABSENT) | HPTE_V_VALID;
rmap = &memslot->arch.rmap[gfn_base - memslot->base_gfn];
lock_rmap(rmap);
ret = RESUME_GUEST;
if (mmu_notifier_retry(vcpu->kvm, mmu_seq)) {
unlock_rmap(rmap);
goto out_unlock;
}
rcbits = *rmap >> KVMPPC_RMAP_RC_SHIFT;
r &= rcbits | ~(HPTE_R_R | HPTE_R_C);
if (be64_to_cpu(hptep[0]) & HPTE_V_VALID) {
unlock_rmap(rmap);
hptep[0] |= cpu_to_be64(HPTE_V_ABSENT);
kvmppc_invalidate_hpte(kvm, hptep, index);
r |= be64_to_cpu(hptep[1]) & (HPTE_R_R | HPTE_R_C);
} else {
kvmppc_add_revmap_chain(kvm, rev, rmap, index, 0);
}
hptep[1] = cpu_to_be64(r);
eieio();
__unlock_hpte(hptep, hpte[0]);
asm volatile("ptesync" : : : "memory");
preempt_enable();
if (page && hpte_is_writable(r))
SetPageDirty(page);
out_put:
trace_kvm_page_fault_exit(vcpu, hpte, ret);
if (page) {
put_page(pages[0]);
}
return ret;
out_unlock:
__unlock_hpte(hptep, be64_to_cpu(hptep[0]));
preempt_enable();
goto out_put;
}
static void kvmppc_rmap_reset(struct kvm *kvm)
{
struct kvm_memslots *slots;
struct kvm_memory_slot *memslot;
int srcu_idx;
srcu_idx = srcu_read_lock(&kvm->srcu);
slots = kvm_memslots(kvm);
kvm_for_each_memslot(memslot, slots) {
memset(memslot->arch.rmap, 0,
memslot->npages * sizeof(*memslot->arch.rmap));
}
srcu_read_unlock(&kvm->srcu, srcu_idx);
}
static int kvm_handle_hva_range(struct kvm *kvm,
unsigned long start,
unsigned long end,
int (*handler)(struct kvm *kvm,
unsigned long *rmapp,
unsigned long gfn))
{
int ret;
int retval = 0;
struct kvm_memslots *slots;
struct kvm_memory_slot *memslot;
slots = kvm_memslots(kvm);
kvm_for_each_memslot(memslot, slots) {
unsigned long hva_start, hva_end;
gfn_t gfn, gfn_end;
hva_start = max(start, memslot->userspace_addr);
hva_end = min(end, memslot->userspace_addr +
(memslot->npages << PAGE_SHIFT));
if (hva_start >= hva_end)
continue;
gfn = hva_to_gfn_memslot(hva_start, memslot);
gfn_end = hva_to_gfn_memslot(hva_end + PAGE_SIZE - 1, memslot);
for (; gfn < gfn_end; ++gfn) {
gfn_t gfn_offset = gfn - memslot->base_gfn;
ret = handler(kvm, &memslot->arch.rmap[gfn_offset], gfn);
retval |= ret;
}
}
return retval;
}
static int kvm_handle_hva(struct kvm *kvm, unsigned long hva,
int (*handler)(struct kvm *kvm, unsigned long *rmapp,
unsigned long gfn))
{
return kvm_handle_hva_range(kvm, hva, hva + 1, handler);
}
static int kvm_unmap_rmapp(struct kvm *kvm, unsigned long *rmapp,
unsigned long gfn)
{
struct revmap_entry *rev = kvm->arch.revmap;
unsigned long h, i, j;
__be64 *hptep;
unsigned long ptel, psize, rcbits;
for (;;) {
lock_rmap(rmapp);
if (!(*rmapp & KVMPPC_RMAP_PRESENT)) {
unlock_rmap(rmapp);
break;
}
i = *rmapp & KVMPPC_RMAP_INDEX;
hptep = (__be64 *) (kvm->arch.hpt_virt + (i << 4));
if (!try_lock_hpte(hptep, HPTE_V_HVLOCK)) {
unlock_rmap(rmapp);
while (be64_to_cpu(hptep[0]) & HPTE_V_HVLOCK)
cpu_relax();
continue;
}
j = rev[i].forw;
if (j == i) {
*rmapp &= ~(KVMPPC_RMAP_PRESENT | KVMPPC_RMAP_INDEX);
} else {
h = rev[i].back;
rev[h].forw = j;
rev[j].back = h;
rev[i].forw = rev[i].back = i;
*rmapp = (*rmapp & ~KVMPPC_RMAP_INDEX) | j;
}
ptel = rev[i].guest_rpte;
psize = hpte_page_size(be64_to_cpu(hptep[0]), ptel);
if ((be64_to_cpu(hptep[0]) & HPTE_V_VALID) &&
hpte_rpn(ptel, psize) == gfn) {
hptep[0] |= cpu_to_be64(HPTE_V_ABSENT);
kvmppc_invalidate_hpte(kvm, hptep, i);
rcbits = be64_to_cpu(hptep[1]) & (HPTE_R_R | HPTE_R_C);
*rmapp |= rcbits << KVMPPC_RMAP_RC_SHIFT;
if (rcbits & ~rev[i].guest_rpte) {
rev[i].guest_rpte = ptel | rcbits;
note_hpte_modification(kvm, &rev[i]);
}
}
unlock_rmap(rmapp);
__unlock_hpte(hptep, be64_to_cpu(hptep[0]));
}
return 0;
}
int kvm_unmap_hva_hv(struct kvm *kvm, unsigned long hva)
{
kvm_handle_hva(kvm, hva, kvm_unmap_rmapp);
return 0;
}
int kvm_unmap_hva_range_hv(struct kvm *kvm, unsigned long start, unsigned long end)
{
kvm_handle_hva_range(kvm, start, end, kvm_unmap_rmapp);
return 0;
}
void kvmppc_core_flush_memslot_hv(struct kvm *kvm,
struct kvm_memory_slot *memslot)
{
unsigned long *rmapp;
unsigned long gfn;
unsigned long n;
rmapp = memslot->arch.rmap;
gfn = memslot->base_gfn;
for (n = memslot->npages; n; --n) {
if (*rmapp & KVMPPC_RMAP_PRESENT)
kvm_unmap_rmapp(kvm, rmapp, gfn);
++rmapp;
++gfn;
}
}
static int kvm_age_rmapp(struct kvm *kvm, unsigned long *rmapp,
unsigned long gfn)
{
struct revmap_entry *rev = kvm->arch.revmap;
unsigned long head, i, j;
__be64 *hptep;
int ret = 0;
retry:
lock_rmap(rmapp);
if (*rmapp & KVMPPC_RMAP_REFERENCED) {
*rmapp &= ~KVMPPC_RMAP_REFERENCED;
ret = 1;
}
if (!(*rmapp & KVMPPC_RMAP_PRESENT)) {
unlock_rmap(rmapp);
return ret;
}
i = head = *rmapp & KVMPPC_RMAP_INDEX;
do {
hptep = (__be64 *) (kvm->arch.hpt_virt + (i << 4));
j = rev[i].forw;
if (!(be64_to_cpu(hptep[1]) & HPTE_R_R))
continue;
if (!try_lock_hpte(hptep, HPTE_V_HVLOCK)) {
unlock_rmap(rmapp);
while (be64_to_cpu(hptep[0]) & HPTE_V_HVLOCK)
cpu_relax();
goto retry;
}
if ((be64_to_cpu(hptep[0]) & HPTE_V_VALID) &&
(be64_to_cpu(hptep[1]) & HPTE_R_R)) {
kvmppc_clear_ref_hpte(kvm, hptep, i);
if (!(rev[i].guest_rpte & HPTE_R_R)) {
rev[i].guest_rpte |= HPTE_R_R;
note_hpte_modification(kvm, &rev[i]);
}
ret = 1;
}
__unlock_hpte(hptep, be64_to_cpu(hptep[0]));
} while ((i = j) != head);
unlock_rmap(rmapp);
return ret;
}
int kvm_age_hva_hv(struct kvm *kvm, unsigned long start, unsigned long end)
{
return kvm_handle_hva_range(kvm, start, end, kvm_age_rmapp);
}
static int kvm_test_age_rmapp(struct kvm *kvm, unsigned long *rmapp,
unsigned long gfn)
{
struct revmap_entry *rev = kvm->arch.revmap;
unsigned long head, i, j;
unsigned long *hp;
int ret = 1;
if (*rmapp & KVMPPC_RMAP_REFERENCED)
return 1;
lock_rmap(rmapp);
if (*rmapp & KVMPPC_RMAP_REFERENCED)
goto out;
if (*rmapp & KVMPPC_RMAP_PRESENT) {
i = head = *rmapp & KVMPPC_RMAP_INDEX;
do {
hp = (unsigned long *)(kvm->arch.hpt_virt + (i << 4));
j = rev[i].forw;
if (be64_to_cpu(hp[1]) & HPTE_R_R)
goto out;
} while ((i = j) != head);
}
ret = 0;
out:
unlock_rmap(rmapp);
return ret;
}
int kvm_test_age_hva_hv(struct kvm *kvm, unsigned long hva)
{
return kvm_handle_hva(kvm, hva, kvm_test_age_rmapp);
}
void kvm_set_spte_hva_hv(struct kvm *kvm, unsigned long hva, pte_t pte)
{
kvm_handle_hva(kvm, hva, kvm_unmap_rmapp);
}
static int vcpus_running(struct kvm *kvm)
{
return atomic_read(&kvm->arch.vcpus_running) != 0;
}
static int kvm_test_clear_dirty_npages(struct kvm *kvm, unsigned long *rmapp)
{
struct revmap_entry *rev = kvm->arch.revmap;
unsigned long head, i, j;
unsigned long n;
unsigned long v, r;
__be64 *hptep;
int npages_dirty = 0;
retry:
lock_rmap(rmapp);
if (*rmapp & KVMPPC_RMAP_CHANGED) {
*rmapp &= ~KVMPPC_RMAP_CHANGED;
npages_dirty = 1;
}
if (!(*rmapp & KVMPPC_RMAP_PRESENT)) {
unlock_rmap(rmapp);
return npages_dirty;
}
i = head = *rmapp & KVMPPC_RMAP_INDEX;
do {
unsigned long hptep1;
hptep = (__be64 *) (kvm->arch.hpt_virt + (i << 4));
j = rev[i].forw;
hptep1 = be64_to_cpu(hptep[1]);
if (!(hptep1 & HPTE_R_C) &&
(!hpte_is_writable(hptep1) || vcpus_running(kvm)))
continue;
if (!try_lock_hpte(hptep, HPTE_V_HVLOCK)) {
unlock_rmap(rmapp);
while (hptep[0] & cpu_to_be64(HPTE_V_HVLOCK))
cpu_relax();
goto retry;
}
if (!(hptep[0] & cpu_to_be64(HPTE_V_VALID))) {
__unlock_hpte(hptep, be64_to_cpu(hptep[0]));
continue;
}
hptep[0] |= cpu_to_be64(HPTE_V_ABSENT);
kvmppc_invalidate_hpte(kvm, hptep, i);
v = be64_to_cpu(hptep[0]);
r = be64_to_cpu(hptep[1]);
if (r & HPTE_R_C) {
hptep[1] = cpu_to_be64(r & ~HPTE_R_C);
if (!(rev[i].guest_rpte & HPTE_R_C)) {
rev[i].guest_rpte |= HPTE_R_C;
note_hpte_modification(kvm, &rev[i]);
}
n = hpte_page_size(v, r);
n = (n + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (n > npages_dirty)
npages_dirty = n;
eieio();
}
v &= ~HPTE_V_ABSENT;
v |= HPTE_V_VALID;
__unlock_hpte(hptep, v);
} while ((i = j) != head);
unlock_rmap(rmapp);
return npages_dirty;
}
static void harvest_vpa_dirty(struct kvmppc_vpa *vpa,
struct kvm_memory_slot *memslot,
unsigned long *map)
{
unsigned long gfn;
if (!vpa->dirty || !vpa->pinned_addr)
return;
gfn = vpa->gpa >> PAGE_SHIFT;
if (gfn < memslot->base_gfn ||
gfn >= memslot->base_gfn + memslot->npages)
return;
vpa->dirty = false;
if (map)
__set_bit_le(gfn - memslot->base_gfn, map);
}
long kvmppc_hv_get_dirty_log(struct kvm *kvm, struct kvm_memory_slot *memslot,
unsigned long *map)
{
unsigned long i, j;
unsigned long *rmapp;
struct kvm_vcpu *vcpu;
preempt_disable();
rmapp = memslot->arch.rmap;
for (i = 0; i < memslot->npages; ++i) {
int npages = kvm_test_clear_dirty_npages(kvm, rmapp);
if (npages && map)
for (j = i; npages; ++j, --npages)
__set_bit_le(j, map);
++rmapp;
}
kvm_for_each_vcpu(i, vcpu, kvm) {
spin_lock(&vcpu->arch.vpa_update_lock);
harvest_vpa_dirty(&vcpu->arch.vpa, memslot, map);
harvest_vpa_dirty(&vcpu->arch.dtl, memslot, map);
spin_unlock(&vcpu->arch.vpa_update_lock);
}
preempt_enable();
return 0;
}
void *kvmppc_pin_guest_page(struct kvm *kvm, unsigned long gpa,
unsigned long *nb_ret)
{
struct kvm_memory_slot *memslot;
unsigned long gfn = gpa >> PAGE_SHIFT;
struct page *page, *pages[1];
int npages;
unsigned long hva, offset;
int srcu_idx;
srcu_idx = srcu_read_lock(&kvm->srcu);
memslot = gfn_to_memslot(kvm, gfn);
if (!memslot || (memslot->flags & KVM_MEMSLOT_INVALID))
goto err;
hva = gfn_to_hva_memslot(memslot, gfn);
npages = get_user_pages_fast(hva, 1, 1, pages);
if (npages < 1)
goto err;
page = pages[0];
srcu_read_unlock(&kvm->srcu, srcu_idx);
offset = gpa & (PAGE_SIZE - 1);
if (nb_ret)
*nb_ret = PAGE_SIZE - offset;
return page_address(page) + offset;
err:
srcu_read_unlock(&kvm->srcu, srcu_idx);
return NULL;
}
void kvmppc_unpin_guest_page(struct kvm *kvm, void *va, unsigned long gpa,
bool dirty)
{
struct page *page = virt_to_page(va);
struct kvm_memory_slot *memslot;
unsigned long gfn;
unsigned long *rmap;
int srcu_idx;
put_page(page);
if (!dirty)
return;
gfn = gpa >> PAGE_SHIFT;
srcu_idx = srcu_read_lock(&kvm->srcu);
memslot = gfn_to_memslot(kvm, gfn);
if (memslot) {
rmap = &memslot->arch.rmap[gfn - memslot->base_gfn];
lock_rmap(rmap);
*rmap |= KVMPPC_RMAP_CHANGED;
unlock_rmap(rmap);
}
srcu_read_unlock(&kvm->srcu, srcu_idx);
}
static int hpte_dirty(struct revmap_entry *revp, __be64 *hptp)
{
unsigned long rcbits_unset;
if (revp->guest_rpte & HPTE_GR_MODIFIED)
return 1;
rcbits_unset = ~revp->guest_rpte & (HPTE_R_R | HPTE_R_C);
if ((be64_to_cpu(hptp[0]) & HPTE_V_VALID) &&
(be64_to_cpu(hptp[1]) & rcbits_unset))
return 1;
return 0;
}
static long record_hpte(unsigned long flags, __be64 *hptp,
unsigned long *hpte, struct revmap_entry *revp,
int want_valid, int first_pass)
{
unsigned long v, r;
unsigned long rcbits_unset;
int ok = 1;
int valid, dirty;
dirty = hpte_dirty(revp, hptp);
if (!first_pass && !dirty)
return 0;
valid = 0;
if (be64_to_cpu(hptp[0]) & (HPTE_V_VALID | HPTE_V_ABSENT)) {
valid = 1;
if ((flags & KVM_GET_HTAB_BOLTED_ONLY) &&
!(be64_to_cpu(hptp[0]) & HPTE_V_BOLTED))
valid = 0;
}
if (valid != want_valid)
return 0;
v = r = 0;
if (valid || dirty) {
preempt_disable();
while (!try_lock_hpte(hptp, HPTE_V_HVLOCK))
cpu_relax();
v = be64_to_cpu(hptp[0]);
valid = !!(v & HPTE_V_VALID);
dirty = !!(revp->guest_rpte & HPTE_GR_MODIFIED);
rcbits_unset = ~revp->guest_rpte & (HPTE_R_R | HPTE_R_C);
if (valid && (rcbits_unset & be64_to_cpu(hptp[1]))) {
revp->guest_rpte |= (be64_to_cpu(hptp[1]) &
(HPTE_R_R | HPTE_R_C)) | HPTE_GR_MODIFIED;
dirty = 1;
}
if (v & HPTE_V_ABSENT) {
v &= ~HPTE_V_ABSENT;
v |= HPTE_V_VALID;
valid = 1;
}
if ((flags & KVM_GET_HTAB_BOLTED_ONLY) && !(v & HPTE_V_BOLTED))
valid = 0;
r = revp->guest_rpte;
if (valid == want_valid && dirty) {
r &= ~HPTE_GR_MODIFIED;
revp->guest_rpte = r;
}
unlock_hpte(hptp, be64_to_cpu(hptp[0]));
preempt_enable();
if (!(valid == want_valid && (first_pass || dirty)))
ok = 0;
}
hpte[0] = cpu_to_be64(v);
hpte[1] = cpu_to_be64(r);
return ok;
}
static ssize_t kvm_htab_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct kvm_htab_ctx *ctx = file->private_data;
struct kvm *kvm = ctx->kvm;
struct kvm_get_htab_header hdr;
__be64 *hptp;
struct revmap_entry *revp;
unsigned long i, nb, nw;
unsigned long __user *lbuf;
struct kvm_get_htab_header __user *hptr;
unsigned long flags;
int first_pass;
unsigned long hpte[2];
if (!access_ok(VERIFY_WRITE, buf, count))
return -EFAULT;
first_pass = ctx->first_pass;
flags = ctx->flags;
i = ctx->index;
hptp = (__be64 *)(kvm->arch.hpt_virt + (i * HPTE_SIZE));
revp = kvm->arch.revmap + i;
lbuf = (unsigned long __user *)buf;
nb = 0;
while (nb + sizeof(hdr) + HPTE_SIZE < count) {
hptr = (struct kvm_get_htab_header __user *)buf;
hdr.n_valid = 0;
hdr.n_invalid = 0;
nw = nb;
nb += sizeof(hdr);
lbuf = (unsigned long __user *)(buf + sizeof(hdr));
if (!first_pass) {
while (i < kvm->arch.hpt_npte &&
!hpte_dirty(revp, hptp)) {
++i;
hptp += 2;
++revp;
}
}
hdr.index = i;
while (i < kvm->arch.hpt_npte &&
hdr.n_valid < 0xffff &&
nb + HPTE_SIZE < count &&
record_hpte(flags, hptp, hpte, revp, 1, first_pass)) {
++hdr.n_valid;
if (__put_user(hpte[0], lbuf) ||
__put_user(hpte[1], lbuf + 1))
return -EFAULT;
nb += HPTE_SIZE;
lbuf += 2;
++i;
hptp += 2;
++revp;
}
while (i < kvm->arch.hpt_npte &&
hdr.n_invalid < 0xffff &&
record_hpte(flags, hptp, hpte, revp, 0, first_pass)) {
++hdr.n_invalid;
++i;
hptp += 2;
++revp;
}
if (hdr.n_valid || hdr.n_invalid) {
if (__copy_to_user(hptr, &hdr, sizeof(hdr)))
return -EFAULT;
nw = nb;
buf = (char __user *)lbuf;
} else {
nb = nw;
}
if (i >= kvm->arch.hpt_npte) {
i = 0;
ctx->first_pass = 0;
break;
}
}
ctx->index = i;
return nb;
}
static ssize_t kvm_htab_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct kvm_htab_ctx *ctx = file->private_data;
struct kvm *kvm = ctx->kvm;
struct kvm_get_htab_header hdr;
unsigned long i, j;
unsigned long v, r;
unsigned long __user *lbuf;
__be64 *hptp;
unsigned long tmp[2];
ssize_t nb;
long int err, ret;
int hpte_setup;
if (!access_ok(VERIFY_READ, buf, count))
return -EFAULT;
mutex_lock(&kvm->lock);
hpte_setup = kvm->arch.hpte_setup_done;
if (hpte_setup) {
kvm->arch.hpte_setup_done = 0;
smp_mb();
if (atomic_read(&kvm->arch.vcpus_running)) {
kvm->arch.hpte_setup_done = 1;
mutex_unlock(&kvm->lock);
return -EBUSY;
}
}
err = 0;
for (nb = 0; nb + sizeof(hdr) <= count; ) {
err = -EFAULT;
if (__copy_from_user(&hdr, buf, sizeof(hdr)))
break;
err = 0;
if (nb + hdr.n_valid * HPTE_SIZE > count)
break;
nb += sizeof(hdr);
buf += sizeof(hdr);
err = -EINVAL;
i = hdr.index;
if (i >= kvm->arch.hpt_npte ||
i + hdr.n_valid + hdr.n_invalid > kvm->arch.hpt_npte)
break;
hptp = (__be64 *)(kvm->arch.hpt_virt + (i * HPTE_SIZE));
lbuf = (unsigned long __user *)buf;
for (j = 0; j < hdr.n_valid; ++j) {
__be64 hpte_v;
__be64 hpte_r;
err = -EFAULT;
if (__get_user(hpte_v, lbuf) ||
__get_user(hpte_r, lbuf + 1))
goto out;
v = be64_to_cpu(hpte_v);
r = be64_to_cpu(hpte_r);
err = -EINVAL;
if (!(v & HPTE_V_VALID))
goto out;
lbuf += 2;
nb += HPTE_SIZE;
if (be64_to_cpu(hptp[0]) & (HPTE_V_VALID | HPTE_V_ABSENT))
kvmppc_do_h_remove(kvm, 0, i, 0, tmp);
err = -EIO;
ret = kvmppc_virtmode_do_h_enter(kvm, H_EXACT, i, v, r,
tmp);
if (ret != H_SUCCESS) {
pr_err("kvm_htab_write ret %ld i=%ld v=%lx "
"r=%lx\n", ret, i, v, r);
goto out;
}
if (!hpte_setup && is_vrma_hpte(v)) {
unsigned long psize = hpte_base_page_size(v, r);
unsigned long senc = slb_pgsize_encoding(psize);
unsigned long lpcr;
kvm->arch.vrma_slb_v = senc | SLB_VSID_B_1T |
(VRMA_VSID << SLB_VSID_SHIFT_1T);
lpcr = senc << (LPCR_VRMASD_SH - 4);
kvmppc_update_lpcr(kvm, lpcr, LPCR_VRMASD);
hpte_setup = 1;
}
++i;
hptp += 2;
}
for (j = 0; j < hdr.n_invalid; ++j) {
if (be64_to_cpu(hptp[0]) & (HPTE_V_VALID | HPTE_V_ABSENT))
kvmppc_do_h_remove(kvm, 0, i, 0, tmp);
++i;
hptp += 2;
}
err = 0;
}
out:
smp_wmb();
kvm->arch.hpte_setup_done = hpte_setup;
mutex_unlock(&kvm->lock);
if (err)
return err;
return nb;
}
static int kvm_htab_release(struct inode *inode, struct file *filp)
{
struct kvm_htab_ctx *ctx = filp->private_data;
filp->private_data = NULL;
if (!(ctx->flags & KVM_GET_HTAB_WRITE))
atomic_dec(&ctx->kvm->arch.hpte_mod_interest);
kvm_put_kvm(ctx->kvm);
kfree(ctx);
return 0;
}
int kvm_vm_ioctl_get_htab_fd(struct kvm *kvm, struct kvm_get_htab_fd *ghf)
{
int ret;
struct kvm_htab_ctx *ctx;
int rwflag;
if (ghf->flags & ~(KVM_GET_HTAB_BOLTED_ONLY | KVM_GET_HTAB_WRITE))
return -EINVAL;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
kvm_get_kvm(kvm);
ctx->kvm = kvm;
ctx->index = ghf->start_index;
ctx->flags = ghf->flags;
ctx->first_pass = 1;
rwflag = (ghf->flags & KVM_GET_HTAB_WRITE) ? O_WRONLY : O_RDONLY;
ret = anon_inode_getfd("kvm-htab", &kvm_htab_fops, ctx, rwflag | O_CLOEXEC);
if (ret < 0) {
kvm_put_kvm(kvm);
return ret;
}
if (rwflag == O_RDONLY) {
mutex_lock(&kvm->slots_lock);
atomic_inc(&kvm->arch.hpte_mod_interest);
synchronize_srcu_expedited(&kvm->srcu);
mutex_unlock(&kvm->slots_lock);
}
return ret;
}
static int debugfs_htab_open(struct inode *inode, struct file *file)
{
struct kvm *kvm = inode->i_private;
struct debugfs_htab_state *p;
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p)
return -ENOMEM;
kvm_get_kvm(kvm);
p->kvm = kvm;
mutex_init(&p->mutex);
file->private_data = p;
return nonseekable_open(inode, file);
}
static int debugfs_htab_release(struct inode *inode, struct file *file)
{
struct debugfs_htab_state *p = file->private_data;
kvm_put_kvm(p->kvm);
kfree(p);
return 0;
}
static ssize_t debugfs_htab_read(struct file *file, char __user *buf,
size_t len, loff_t *ppos)
{
struct debugfs_htab_state *p = file->private_data;
ssize_t ret, r;
unsigned long i, n;
unsigned long v, hr, gr;
struct kvm *kvm;
__be64 *hptp;
ret = mutex_lock_interruptible(&p->mutex);
if (ret)
return ret;
if (p->chars_left) {
n = p->chars_left;
if (n > len)
n = len;
r = copy_to_user(buf, p->buf + p->buf_index, n);
n -= r;
p->chars_left -= n;
p->buf_index += n;
buf += n;
len -= n;
ret = n;
if (r) {
if (!n)
ret = -EFAULT;
goto out;
}
}
kvm = p->kvm;
i = p->hpt_index;
hptp = (__be64 *)(kvm->arch.hpt_virt + (i * HPTE_SIZE));
for (; len != 0 && i < kvm->arch.hpt_npte; ++i, hptp += 2) {
if (!(be64_to_cpu(hptp[0]) & (HPTE_V_VALID | HPTE_V_ABSENT)))
continue;
preempt_disable();
while (!try_lock_hpte(hptp, HPTE_V_HVLOCK))
cpu_relax();
v = be64_to_cpu(hptp[0]) & ~HPTE_V_HVLOCK;
hr = be64_to_cpu(hptp[1]);
gr = kvm->arch.revmap[i].guest_rpte;
unlock_hpte(hptp, v);
preempt_enable();
if (!(v & (HPTE_V_VALID | HPTE_V_ABSENT)))
continue;
n = scnprintf(p->buf, sizeof(p->buf),
"%6lx %.16lx %.16lx %.16lx\n",
i, v, hr, gr);
p->chars_left = n;
if (n > len)
n = len;
r = copy_to_user(buf, p->buf, n);
n -= r;
p->chars_left -= n;
p->buf_index = n;
buf += n;
len -= n;
ret += n;
if (r) {
if (!ret)
ret = -EFAULT;
goto out;
}
}
p->hpt_index = i;
out:
mutex_unlock(&p->mutex);
return ret;
}
ssize_t debugfs_htab_write(struct file *file, const char __user *buf,
size_t len, loff_t *ppos)
{
return -EACCES;
}
void kvmppc_mmu_debugfs_init(struct kvm *kvm)
{
kvm->arch.htab_dentry = debugfs_create_file("htab", 0400,
kvm->arch.debugfs_dir, kvm,
&debugfs_htab_fops);
}
void kvmppc_mmu_book3s_hv_init(struct kvm_vcpu *vcpu)
{
struct kvmppc_mmu *mmu = &vcpu->arch.mmu;
vcpu->arch.slb_nr = 32;
mmu->xlate = kvmppc_mmu_book3s_64_hv_xlate;
mmu->reset_msr = kvmppc_mmu_book3s_64_hv_reset_msr;
vcpu->arch.hflags |= BOOK3S_HFLAG_SLB;
}
