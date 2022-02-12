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
unsigned long kvm_rma_size;
pr_debug("%s(%s)\n", __func__, p);
if (!p)
return -EINVAL;
kvm_rma_size = memparse(p, &p);
if (lpcr_rmls(kvm_rma_size) < 0) {
pr_err("RMA size of 0x%lx not supported\n", kvm_rma_size);
return -EINVAL;
}
kvm_rma_pages = kvm_rma_size >> PAGE_SHIFT;
return 0;
}
struct kvm_rma_info *kvm_alloc_rma()
{
struct page *page;
struct kvm_rma_info *ri;
ri = kmalloc(sizeof(struct kvm_rma_info), GFP_KERNEL);
if (!ri)
return NULL;
page = kvm_alloc_cma(kvm_rma_pages, kvm_rma_pages);
if (!page)
goto err_out;
atomic_set(&ri->use_count, 1);
ri->base_pfn = page_to_pfn(page);
return ri;
err_out:
kfree(ri);
return NULL;
}
void kvm_release_rma(struct kvm_rma_info *ri)
{
if (atomic_dec_and_test(&ri->use_count)) {
kvm_release_cma(pfn_to_page(ri->base_pfn), kvm_rma_pages);
kfree(ri);
}
}
static int __init early_parse_kvm_cma_resv(char *p)
{
pr_debug("%s(%s)\n", __func__, p);
if (!p)
return -EINVAL;
return kstrtoul(p, 0, &kvm_cma_resv_ratio);
}
struct page *kvm_alloc_hpt(unsigned long nr_pages)
{
unsigned long align_pages = HPT_ALIGN_PAGES;
if (!cpu_has_feature(CPU_FTR_ARCH_206))
align_pages = nr_pages;
return kvm_alloc_cma(nr_pages, align_pages);
}
void kvm_release_hpt(struct page *page, unsigned long nr_pages)
{
kvm_release_cma(page, nr_pages);
}
void __init kvm_cma_reserve(void)
{
unsigned long align_size;
struct memblock_region *reg;
phys_addr_t selected_size = 0;
for_each_memblock(memory, reg)
selected_size += memblock_region_memory_end_pfn(reg) -
memblock_region_memory_base_pfn(reg);
selected_size = (selected_size * kvm_cma_resv_ratio / 100) << PAGE_SHIFT;
if (selected_size) {
pr_debug("%s: reserving %ld MiB for global area\n", __func__,
(unsigned long)selected_size / SZ_1M);
if (!cpu_has_feature(CPU_FTR_ARCH_206))
align_size = __rounddown_pow_of_two(selected_size);
else
align_size = HPT_ALIGN_PAGES << PAGE_SHIFT;
align_size = max(kvm_rma_pages << PAGE_SHIFT, align_size);
kvm_cma_declare_contiguous(selected_size, align_size);
}
}
