static struct page *pcpu_chunk_page(struct pcpu_chunk *chunk,
unsigned int cpu, int page_idx)
{
WARN_ON(chunk->immutable);
return vmalloc_to_page((void *)pcpu_chunk_addr(chunk, cpu, page_idx));
}
static struct page **pcpu_get_pages(void)
{
static struct page **pages;
size_t pages_size = pcpu_nr_units * pcpu_unit_pages * sizeof(pages[0]);
lockdep_assert_held(&pcpu_alloc_mutex);
if (!pages)
pages = pcpu_mem_zalloc(pages_size);
return pages;
}
static void pcpu_free_pages(struct pcpu_chunk *chunk,
struct page **pages, int page_start, int page_end)
{
unsigned int cpu;
int i;
for_each_possible_cpu(cpu) {
for (i = page_start; i < page_end; i++) {
struct page *page = pages[pcpu_page_idx(cpu, i)];
if (page)
__free_page(page);
}
}
}
static int pcpu_alloc_pages(struct pcpu_chunk *chunk,
struct page **pages, int page_start, int page_end)
{
const gfp_t gfp = GFP_KERNEL | __GFP_HIGHMEM | __GFP_COLD;
unsigned int cpu, tcpu;
int i;
for_each_possible_cpu(cpu) {
for (i = page_start; i < page_end; i++) {
struct page **pagep = &pages[pcpu_page_idx(cpu, i)];
*pagep = alloc_pages_node(cpu_to_node(cpu), gfp, 0);
if (!*pagep)
goto err;
}
}
return 0;
err:
while (--i >= page_start)
__free_page(pages[pcpu_page_idx(cpu, i)]);
for_each_possible_cpu(tcpu) {
if (tcpu == cpu)
break;
for (i = page_start; i < page_end; i++)
__free_page(pages[pcpu_page_idx(tcpu, i)]);
}
return -ENOMEM;
}
static void pcpu_pre_unmap_flush(struct pcpu_chunk *chunk,
int page_start, int page_end)
{
flush_cache_vunmap(
pcpu_chunk_addr(chunk, pcpu_low_unit_cpu, page_start),
pcpu_chunk_addr(chunk, pcpu_high_unit_cpu, page_end));
}
static void __pcpu_unmap_pages(unsigned long addr, int nr_pages)
{
unmap_kernel_range_noflush(addr, nr_pages << PAGE_SHIFT);
}
static void pcpu_unmap_pages(struct pcpu_chunk *chunk,
struct page **pages, int page_start, int page_end)
{
unsigned int cpu;
int i;
for_each_possible_cpu(cpu) {
for (i = page_start; i < page_end; i++) {
struct page *page;
page = pcpu_chunk_page(chunk, cpu, i);
WARN_ON(!page);
pages[pcpu_page_idx(cpu, i)] = page;
}
__pcpu_unmap_pages(pcpu_chunk_addr(chunk, cpu, page_start),
page_end - page_start);
}
}
static void pcpu_post_unmap_tlb_flush(struct pcpu_chunk *chunk,
int page_start, int page_end)
{
flush_tlb_kernel_range(
pcpu_chunk_addr(chunk, pcpu_low_unit_cpu, page_start),
pcpu_chunk_addr(chunk, pcpu_high_unit_cpu, page_end));
}
static int __pcpu_map_pages(unsigned long addr, struct page **pages,
int nr_pages)
{
return map_kernel_range_noflush(addr, nr_pages << PAGE_SHIFT,
PAGE_KERNEL, pages);
}
static int pcpu_map_pages(struct pcpu_chunk *chunk,
struct page **pages, int page_start, int page_end)
{
unsigned int cpu, tcpu;
int i, err;
for_each_possible_cpu(cpu) {
err = __pcpu_map_pages(pcpu_chunk_addr(chunk, cpu, page_start),
&pages[pcpu_page_idx(cpu, page_start)],
page_end - page_start);
if (err < 0)
goto err;
for (i = page_start; i < page_end; i++)
pcpu_set_page_chunk(pages[pcpu_page_idx(cpu, i)],
chunk);
}
return 0;
err:
for_each_possible_cpu(tcpu) {
if (tcpu == cpu)
break;
__pcpu_unmap_pages(pcpu_chunk_addr(chunk, tcpu, page_start),
page_end - page_start);
}
pcpu_post_unmap_tlb_flush(chunk, page_start, page_end);
return err;
}
static void pcpu_post_map_flush(struct pcpu_chunk *chunk,
int page_start, int page_end)
{
flush_cache_vmap(
pcpu_chunk_addr(chunk, pcpu_low_unit_cpu, page_start),
pcpu_chunk_addr(chunk, pcpu_high_unit_cpu, page_end));
}
static int pcpu_populate_chunk(struct pcpu_chunk *chunk,
int page_start, int page_end)
{
struct page **pages;
pages = pcpu_get_pages();
if (!pages)
return -ENOMEM;
if (pcpu_alloc_pages(chunk, pages, page_start, page_end))
return -ENOMEM;
if (pcpu_map_pages(chunk, pages, page_start, page_end)) {
pcpu_free_pages(chunk, pages, page_start, page_end);
return -ENOMEM;
}
pcpu_post_map_flush(chunk, page_start, page_end);
return 0;
}
static void pcpu_depopulate_chunk(struct pcpu_chunk *chunk,
int page_start, int page_end)
{
struct page **pages;
pages = pcpu_get_pages();
BUG_ON(!pages);
pcpu_pre_unmap_flush(chunk, page_start, page_end);
pcpu_unmap_pages(chunk, pages, page_start, page_end);
pcpu_free_pages(chunk, pages, page_start, page_end);
}
static struct pcpu_chunk *pcpu_create_chunk(void)
{
struct pcpu_chunk *chunk;
struct vm_struct **vms;
chunk = pcpu_alloc_chunk();
if (!chunk)
return NULL;
vms = pcpu_get_vm_areas(pcpu_group_offsets, pcpu_group_sizes,
pcpu_nr_groups, pcpu_atom_size);
if (!vms) {
pcpu_free_chunk(chunk);
return NULL;
}
chunk->data = vms;
chunk->base_addr = vms[0]->addr - pcpu_group_offsets[0];
pcpu_stats_chunk_alloc();
trace_percpu_create_chunk(chunk->base_addr);
return chunk;
}
static void pcpu_destroy_chunk(struct pcpu_chunk *chunk)
{
if (!chunk)
return;
pcpu_stats_chunk_dealloc();
trace_percpu_destroy_chunk(chunk->base_addr);
if (chunk->data)
pcpu_free_vm_areas(chunk->data, pcpu_nr_groups);
pcpu_free_chunk(chunk);
}
static struct page *pcpu_addr_to_page(void *addr)
{
return vmalloc_to_page(addr);
}
static int __init pcpu_verify_alloc_info(const struct pcpu_alloc_info *ai)
{
return 0;
}
