static int __init early_parse_kvm_cma_resv(char *p)
{
pr_debug("%s(%s)\n", __func__, p);
if (!p)
return -EINVAL;
return kstrtoul(p, 0, &kvm_cma_resv_ratio);
}
struct page *kvm_alloc_hpt(unsigned long nr_pages)
{
VM_BUG_ON(order_base_2(nr_pages) < KVM_CMA_CHUNK_ORDER - PAGE_SHIFT);
return cma_alloc(kvm_cma, nr_pages, order_base_2(HPT_ALIGN_PAGES));
}
void kvm_release_hpt(struct page *page, unsigned long nr_pages)
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
KVM_CMA_CHUNK_ORDER - PAGE_SHIFT, false, &kvm_cma);
}
}
long int kvmppc_rm_h_confer(struct kvm_vcpu *vcpu, int target,
unsigned int yield_count)
{
struct kvmppc_vcore *vc = vcpu->arch.vcore;
int threads_running;
int threads_ceded;
int threads_conferring;
u64 stop = get_tb() + 10 * tb_ticks_per_usec;
int rv = H_SUCCESS;
set_bit(vcpu->arch.ptid, &vc->conferring_threads);
while ((get_tb() < stop) && !VCORE_IS_EXITING(vc)) {
threads_running = VCORE_ENTRY_MAP(vc);
threads_ceded = vc->napping_threads;
threads_conferring = vc->conferring_threads;
if ((threads_ceded | threads_conferring) == threads_running) {
rv = H_TOO_HARD;
break;
}
}
clear_bit(vcpu->arch.ptid, &vc->conferring_threads);
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
if (powernv_get_random_real_mode(&vcpu->arch.gpr[4]))
return H_SUCCESS;
return H_HARDWARE;
}
static inline void rm_writeb(unsigned long paddr, u8 val)
{
__asm__ __volatile__("stbcix %0,0,%1"
: : "r" (val), "r" (paddr) : "memory");
}
void kvmhv_rm_send_ipi(int cpu)
{
unsigned long xics_phys;
if (cpu_has_feature(CPU_FTR_ARCH_207S) &&
cpu_first_thread_sibling(cpu) ==
cpu_first_thread_sibling(raw_smp_processor_id())) {
unsigned long msg = PPC_DBELL_TYPE(PPC_DBELL_SERVER);
msg |= cpu_thread_in_core(cpu);
__asm__ __volatile__ (PPC_MSGSND(%0) : : "r" (msg));
return;
}
xics_phys = paca[cpu].kvm_hstate.xics_phys;
rm_writeb(xics_phys + XICS_MFRR, IPI_PRIORITY);
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
int me, ee;
me = 0x100 << ptid;
do {
ee = vc->entry_exit_map;
} while (cmpxchg(&vc->entry_exit_map, ee, ee | me) != ee);
if ((ee >> 8) != 0)
return;
if (trap != BOOK3S_INTERRUPT_HV_DECREMENTER)
kvmhv_interrupt_vcore(vc, ee & ~(1 << ptid));
}
