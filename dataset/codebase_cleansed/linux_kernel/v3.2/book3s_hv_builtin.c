static int __init early_parse_rma_size(char *p)
{
if (!p)
return 1;
kvm_rma_size = memparse(p, &p);
return 0;
}
static int __init early_parse_rma_count(char *p)
{
if (!p)
return 1;
kvm_rma_count = simple_strtoul(p, NULL, 0);
return 0;
}
static inline int lpcr_rmls(unsigned long rma_size)
{
switch (rma_size) {
case 32ul << 20:
if (cpu_has_feature(CPU_FTR_ARCH_206))
return 8;
return -1;
case 64ul << 20:
return 3;
case 128ul << 20:
return 7;
case 256ul << 20:
return 4;
case 1ul << 30:
return 2;
case 16ul << 30:
return 1;
case 256ul << 30:
return 0;
default:
return -1;
}
}
void kvm_rma_init(void)
{
unsigned long i;
unsigned long j, npages;
void *rma;
struct page *pg;
if (!cpu_has_feature(CPU_FTR_HVMODE) ||
!cpu_has_feature(CPU_FTR_ARCH_201))
return;
if (!kvm_rma_size || !kvm_rma_count)
return;
if (lpcr_rmls(kvm_rma_size) < 0) {
pr_err("RMA size of 0x%lx not supported\n", kvm_rma_size);
return;
}
npages = kvm_rma_size >> PAGE_SHIFT;
rma_info = alloc_bootmem(kvm_rma_count * sizeof(struct kvmppc_rma_info));
for (i = 0; i < kvm_rma_count; ++i) {
rma = alloc_bootmem_align(kvm_rma_size, kvm_rma_size);
pr_info("Allocated KVM RMA at %p (%ld MB)\n", rma,
kvm_rma_size >> 20);
rma_info[i].base_virt = rma;
rma_info[i].base_pfn = __pa(rma) >> PAGE_SHIFT;
rma_info[i].npages = npages;
list_add_tail(&rma_info[i].list, &free_rmas);
atomic_set(&rma_info[i].use_count, 0);
pg = pfn_to_page(rma_info[i].base_pfn);
for (j = 0; j < npages; ++j) {
atomic_inc(&pg->_count);
++pg;
}
}
}
struct kvmppc_rma_info *kvm_alloc_rma(void)
{
struct kvmppc_rma_info *ri;
ri = NULL;
spin_lock(&rma_lock);
if (!list_empty(&free_rmas)) {
ri = list_first_entry(&free_rmas, struct kvmppc_rma_info, list);
list_del(&ri->list);
atomic_inc(&ri->use_count);
}
spin_unlock(&rma_lock);
return ri;
}
void kvm_release_rma(struct kvmppc_rma_info *ri)
{
if (atomic_dec_and_test(&ri->use_count)) {
spin_lock(&rma_lock);
list_add_tail(&ri->list, &free_rmas);
spin_unlock(&rma_lock);
}
}
