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
struct kvmppc_linear_info *kvm_alloc_rma(void)
{
return kvm_alloc_linear(KVM_LINEAR_RMA);
}
void kvm_release_rma(struct kvmppc_linear_info *ri)
{
kvm_release_linear(ri);
}
static int __init early_parse_hpt_count(char *p)
{
if (!p)
return 1;
kvm_hpt_count = simple_strtoul(p, NULL, 0);
return 0;
}
struct kvmppc_linear_info *kvm_alloc_hpt(void)
{
return kvm_alloc_linear(KVM_LINEAR_HPT);
}
void kvm_release_hpt(struct kvmppc_linear_info *li)
{
kvm_release_linear(li);
}
static void __init kvm_linear_init_one(ulong size, int count, int type)
{
unsigned long i;
unsigned long j, npages;
void *linear;
struct page *pg;
const char *typestr;
struct kvmppc_linear_info *linear_info;
if (!count)
return;
typestr = (type == KVM_LINEAR_RMA) ? "RMA" : "HPT";
npages = size >> PAGE_SHIFT;
linear_info = alloc_bootmem(count * sizeof(struct kvmppc_linear_info));
for (i = 0; i < count; ++i) {
linear = alloc_bootmem_align(size, size);
pr_debug("Allocated KVM %s at %p (%ld MB)\n", typestr, linear,
size >> 20);
linear_info[i].base_virt = linear;
linear_info[i].base_pfn = __pa(linear) >> PAGE_SHIFT;
linear_info[i].npages = npages;
linear_info[i].type = type;
list_add_tail(&linear_info[i].list, &free_linears);
atomic_set(&linear_info[i].use_count, 0);
pg = pfn_to_page(linear_info[i].base_pfn);
for (j = 0; j < npages; ++j) {
atomic_inc(&pg->_count);
++pg;
}
}
}
static struct kvmppc_linear_info *kvm_alloc_linear(int type)
{
struct kvmppc_linear_info *ri, *ret;
ret = NULL;
spin_lock(&linear_lock);
list_for_each_entry(ri, &free_linears, list) {
if (ri->type != type)
continue;
list_del(&ri->list);
atomic_inc(&ri->use_count);
memset(ri->base_virt, 0, ri->npages << PAGE_SHIFT);
ret = ri;
break;
}
spin_unlock(&linear_lock);
return ret;
}
static void kvm_release_linear(struct kvmppc_linear_info *ri)
{
if (atomic_dec_and_test(&ri->use_count)) {
spin_lock(&linear_lock);
list_add_tail(&ri->list, &free_linears);
spin_unlock(&linear_lock);
}
}
void __init kvm_linear_init(void)
{
kvm_linear_init_one(1 << kvm_hpt_order, kvm_hpt_count, KVM_LINEAR_HPT);
if (!cpu_has_feature(CPU_FTR_HVMODE) ||
!cpu_has_feature(CPU_FTR_ARCH_201))
return;
if (!kvm_rma_size || !kvm_rma_count)
return;
if (lpcr_rmls(kvm_rma_size) < 0) {
pr_err("RMA size of 0x%lx not supported\n", kvm_rma_size);
return;
}
kvm_linear_init_one(kvm_rma_size, kvm_rma_count, KVM_LINEAR_RMA);
}
