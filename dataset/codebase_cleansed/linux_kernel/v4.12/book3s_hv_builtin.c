static int __init early_parse_kvm_cma_resv(char *p)
{
pr_debug("%s(%s)\n", __func__, p);
if (!p)
return -EINVAL;
return kstrtoul(p, 0, &kvm_cma_resv_ratio);
}
struct page *kvm_alloc_hpt_cma(unsigned long nr_pages)
{
VM_BUG_ON(order_base_2(nr_pages) < KVM_CMA_CHUNK_ORDER - PAGE_SHIFT);
return cma_alloc(kvm_cma, nr_pages, order_base_2(HPT_ALIGN_PAGES),
GFP_KERNEL);
}
void kvm_free_hpt_cma(struct page *page, unsigned long nr_pages)
{
cma_release(kvm_cma, page, nr_pages);
}
void __init kvm_cma_reserve(void)
{
unsigned long align_size;
struct memblock_region *reg;
phys_addr_t selected_size = 0;
if (!cpu_has_feature(CPU_FTR_HVMODE))
return;
for_each_memblock(memory, reg)
selected_size += memblock_region_memory_end_pfn(reg) -
memblock_region_memory_base_pfn(reg);
selected_size = (selected_size * kvm_cma_resv_ratio / 100) << PAGE_SHIFT;
if (selected_size) {
pr_debug("%s: reserving %ld MiB for global area\n", __func__,
(unsigned long)selected_size / SZ_1M);
align_size = HPT_ALIGN_PAGES << PAGE_SHIFT;
cma_declare_contiguous(0, selected_size, 0, align_size,
KVM_CMA_CHUNK_ORDER - PAGE_SHIFT, false, "kvm_cma",
&kvm_cma);
}
}
long int kvmppc_rm_h_confer(struct kvm_vcpu *vcpu, int target,
unsigned int yield_count)
{
struct kvmppc_vcore *vc = local_paca->kvm_hstate.kvm_vcore;
int ptid = local_paca->kvm_hstate.ptid;
int threads_running;
int threads_ceded;
int threads_conferring;
u64 stop = get_tb() + 10 * tb_ticks_per_usec;
int rv = H_SUCCESS;
set_bit(ptid, &vc->conferring_threads);
while ((get_tb() < stop) && !VCORE_IS_EXITING(vc)) {
threads_running = VCORE_ENTRY_MAP(vc);
threads_ceded = vc->napping_threads;
threads_conferring = vc->conferring_threads;
if ((threads_ceded | threads_conferring) == threads_running) {
rv = H_TOO_HARD;
break;
}
}
clear_bit(ptid, &vc->conferring_threads);
return rv;
}
void kvm_hv_vm_activated(void)
{
get_online_cpus();
atomic_inc(&hv_vm_count);
put_online_cpus();
}
void kvm_hv_vm_deactivated(void)
{
get_online_cpus();
atomic_dec(&hv_vm_count);
put_online_cpus();
}
bool kvm_hv_mode_active(void)
{
return atomic_read(&hv_vm_count) != 0;
}
int kvmppc_hcall_impl_hv_realmode(unsigned long cmd)
{
cmd /= 4;
if (cmd < hcall_real_table_end - hcall_real_table &&
hcall_real_table[cmd])
return 1;
return 0;
}
int kvmppc_hwrng_present(void)
{
return powernv_hwrng_present();
}
long kvmppc_h_random(struct kvm_vcpu *vcpu)
{
int r;
if (kvm_is_radix(vcpu->kvm) && (mfmsr() & MSR_IR))
r = powernv_get_random_long(&vcpu->arch.gpr[4]);
else
r = powernv_get_random_real_mode(&vcpu->arch.gpr[4]);
if (r)
return H_SUCCESS;
return H_HARDWARE;
}
void kvmhv_rm_send_ipi(int cpu)
{
void __iomem *xics_phys;
unsigned long msg = PPC_DBELL_TYPE(PPC_DBELL_SERVER);
if (cpu_has_feature(CPU_FTR_ARCH_300)) {
msg |= get_hard_smp_processor_id(cpu);
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
if (cpu_has_feature(CPU_FTR_ARCH_207S) &&
cpu_first_thread_sibling(cpu) ==
cpu_first_thread_sibling(raw_smp_processor_id())) {
msg |= cpu_thread_in_core(cpu);
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
if (WARN_ON_ONCE(xive_enabled()))
return;
xics_phys = paca[cpu].kvm_hstate.xics_phys;
if (xics_phys)
__raw_rm_writeb(IPI_PRIORITY, xics_phys + XICS_MFRR);
else
opal_int_set_mfrr(get_hard_smp_processor_id(cpu), IPI_PRIORITY);
}
static void kvmhv_interrupt_vcore(struct kvmppc_vcore *vc, int active)
{
int cpu = vc->pcpu;
smp_mb();
for (; active; active >>= 1, ++cpu)
if (active & 1)
kvmhv_rm_send_ipi(cpu);
}
void kvmhv_commence_exit(int trap)
{
struct kvmppc_vcore *vc = local_paca->kvm_hstate.kvm_vcore;
int ptid = local_paca->kvm_hstate.ptid;
struct kvm_split_mode *sip = local_paca->kvm_hstate.kvm_split_mode;
int me, ee, i;
me = 0x100 << ptid;
do {
ee = vc->entry_exit_map;
} while (cmpxchg(&vc->entry_exit_map, ee, ee | me) != ee);
if ((ee >> 8) != 0)
return;
if (trap != BOOK3S_INTERRUPT_HV_DECREMENTER)
kvmhv_interrupt_vcore(vc, ee & ~(1 << ptid));
if (!sip)
return;
for (i = 0; i < MAX_SUBCORES; ++i) {
vc = sip->master_vcs[i];
if (!vc)
break;
do {
ee = vc->entry_exit_map;
if ((ee >> 8) != 0)
break;
} while (cmpxchg(&vc->entry_exit_map, ee,
ee | VCORE_EXIT_REQ) != ee);
if ((ee >> 8) == 0)
kvmhv_interrupt_vcore(vc, ee);
}
}
static struct kvmppc_irq_map *get_irqmap(struct kvmppc_passthru_irqmap *pimap,
u32 xisr)
{
int i;
for (i = 0; i < pimap->n_mapped; i++) {
if (xisr == pimap->mapped[i].r_hwirq) {
smp_rmb();
return &pimap->mapped[i];
}
}
return NULL;
}
static int kvmppc_check_passthru(u32 xisr, __be32 xirr, bool *again)
{
struct kvmppc_passthru_irqmap *pimap;
struct kvmppc_irq_map *irq_map;
struct kvm_vcpu *vcpu;
vcpu = local_paca->kvm_hstate.kvm_vcpu;
if (!vcpu)
return 1;
pimap = kvmppc_get_passthru_irqmap(vcpu->kvm);
if (!pimap)
return 1;
irq_map = get_irqmap(pimap, xisr);
if (!irq_map)
return 1;
local_paca->kvm_hstate.saved_xirr = 0;
return kvmppc_deliver_irq_passthru(vcpu, xirr, irq_map, pimap, again);
}
static inline int kvmppc_check_passthru(u32 xisr, __be32 xirr, bool *again)
{
return 1;
}
long kvmppc_read_intr(void)
{
long ret = 0;
long rc;
bool again;
if (xive_enabled())
return 1;
do {
again = false;
rc = kvmppc_read_one_intr(&again);
if (rc && (ret == 0 || rc > ret))
ret = rc;
} while (again);
return ret;
}
static long kvmppc_read_one_intr(bool *again)
{
void __iomem *xics_phys;
u32 h_xirr;
__be32 xirr;
u32 xisr;
u8 host_ipi;
int64_t rc;
if (xive_enabled())
return 1;
host_ipi = local_paca->kvm_hstate.host_ipi;
if (host_ipi)
return 1;
xics_phys = local_paca->kvm_hstate.xics_phys;
rc = 0;
if (!xics_phys)
rc = opal_int_get_xirr(&xirr, false);
else
xirr = __raw_rm_readl(xics_phys + XICS_XIRR);
if (rc < 0)
return 1;
h_xirr = be32_to_cpu(xirr);
local_paca->kvm_hstate.saved_xirr = h_xirr;
xisr = h_xirr & 0xffffff;
smp_mb();
if (!xisr)
return 0;
if (xisr == XICS_IPI) {
rc = 0;
if (xics_phys) {
__raw_rm_writeb(0xff, xics_phys + XICS_MFRR);
__raw_rm_writel(xirr, xics_phys + XICS_XIRR);
} else {
opal_int_set_mfrr(hard_smp_processor_id(), 0xff);
rc = opal_int_eoi(h_xirr);
}
*again = rc > 0;
smp_mb();
host_ipi = local_paca->kvm_hstate.host_ipi;
if (unlikely(host_ipi != 0)) {
if (xics_phys)
__raw_rm_writeb(IPI_PRIORITY,
xics_phys + XICS_MFRR);
else
opal_int_set_mfrr(hard_smp_processor_id(),
IPI_PRIORITY);
smp_mb();
return 1;
}
local_paca->kvm_hstate.saved_xirr = 0;
return -1;
}
return kvmppc_check_passthru(xisr, xirr, again);
}
static inline bool is_rm(void)
{
return !(mfmsr() & MSR_DR);
}
unsigned long kvmppc_rm_h_xirr(struct kvm_vcpu *vcpu)
{
if (xive_enabled()) {
if (is_rm())
return xive_rm_h_xirr(vcpu);
if (unlikely(!__xive_vm_h_xirr))
return H_NOT_AVAILABLE;
return __xive_vm_h_xirr(vcpu);
} else
return xics_rm_h_xirr(vcpu);
}
unsigned long kvmppc_rm_h_xirr_x(struct kvm_vcpu *vcpu)
{
vcpu->arch.gpr[5] = get_tb();
if (xive_enabled()) {
if (is_rm())
return xive_rm_h_xirr(vcpu);
if (unlikely(!__xive_vm_h_xirr))
return H_NOT_AVAILABLE;
return __xive_vm_h_xirr(vcpu);
} else
return xics_rm_h_xirr(vcpu);
}
unsigned long kvmppc_rm_h_ipoll(struct kvm_vcpu *vcpu, unsigned long server)
{
if (xive_enabled()) {
if (is_rm())
return xive_rm_h_ipoll(vcpu, server);
if (unlikely(!__xive_vm_h_ipoll))
return H_NOT_AVAILABLE;
return __xive_vm_h_ipoll(vcpu, server);
} else
return H_TOO_HARD;
}
int kvmppc_rm_h_ipi(struct kvm_vcpu *vcpu, unsigned long server,
unsigned long mfrr)
{
if (xive_enabled()) {
if (is_rm())
return xive_rm_h_ipi(vcpu, server, mfrr);
if (unlikely(!__xive_vm_h_ipi))
return H_NOT_AVAILABLE;
return __xive_vm_h_ipi(vcpu, server, mfrr);
} else
return xics_rm_h_ipi(vcpu, server, mfrr);
}
int kvmppc_rm_h_cppr(struct kvm_vcpu *vcpu, unsigned long cppr)
{
if (xive_enabled()) {
if (is_rm())
return xive_rm_h_cppr(vcpu, cppr);
if (unlikely(!__xive_vm_h_cppr))
return H_NOT_AVAILABLE;
return __xive_vm_h_cppr(vcpu, cppr);
} else
return xics_rm_h_cppr(vcpu, cppr);
}
int kvmppc_rm_h_eoi(struct kvm_vcpu *vcpu, unsigned long xirr)
{
if (xive_enabled()) {
if (is_rm())
return xive_rm_h_eoi(vcpu, xirr);
if (unlikely(!__xive_vm_h_eoi))
return H_NOT_AVAILABLE;
return __xive_vm_h_eoi(vcpu, xirr);
} else
return xics_rm_h_eoi(vcpu, xirr);
}
