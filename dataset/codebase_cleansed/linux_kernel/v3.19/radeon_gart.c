int radeon_gart_table_ram_alloc(struct radeon_device *rdev)
{
void *ptr;
ptr = pci_alloc_consistent(rdev->pdev, rdev->gart.table_size,
&rdev->gart.table_addr);
if (ptr == NULL) {
return -ENOMEM;
}
#ifdef CONFIG_X86
if (rdev->family == CHIP_RS400 || rdev->family == CHIP_RS480 ||
rdev->family == CHIP_RS690 || rdev->family == CHIP_RS740) {
set_memory_uc((unsigned long)ptr,
rdev->gart.table_size >> PAGE_SHIFT);
}
#endif
rdev->gart.ptr = ptr;
memset((void *)rdev->gart.ptr, 0, rdev->gart.table_size);
return 0;
}
void radeon_gart_table_ram_free(struct radeon_device *rdev)
{
if (rdev->gart.ptr == NULL) {
return;
}
#ifdef CONFIG_X86
if (rdev->family == CHIP_RS400 || rdev->family == CHIP_RS480 ||
rdev->family == CHIP_RS690 || rdev->family == CHIP_RS740) {
set_memory_wb((unsigned long)rdev->gart.ptr,
rdev->gart.table_size >> PAGE_SHIFT);
}
#endif
pci_free_consistent(rdev->pdev, rdev->gart.table_size,
(void *)rdev->gart.ptr,
rdev->gart.table_addr);
rdev->gart.ptr = NULL;
rdev->gart.table_addr = 0;
}
int radeon_gart_table_vram_alloc(struct radeon_device *rdev)
{
int r;
if (rdev->gart.robj == NULL) {
r = radeon_bo_create(rdev, rdev->gart.table_size,
PAGE_SIZE, true, RADEON_GEM_DOMAIN_VRAM,
0, NULL, NULL, &rdev->gart.robj);
if (r) {
return r;
}
}
return 0;
}
int radeon_gart_table_vram_pin(struct radeon_device *rdev)
{
uint64_t gpu_addr;
int r;
r = radeon_bo_reserve(rdev->gart.robj, false);
if (unlikely(r != 0))
return r;
r = radeon_bo_pin(rdev->gart.robj,
RADEON_GEM_DOMAIN_VRAM, &gpu_addr);
if (r) {
radeon_bo_unreserve(rdev->gart.robj);
return r;
}
r = radeon_bo_kmap(rdev->gart.robj, &rdev->gart.ptr);
if (r)
radeon_bo_unpin(rdev->gart.robj);
radeon_bo_unreserve(rdev->gart.robj);
rdev->gart.table_addr = gpu_addr;
if (!r) {
int i;
for (i = 0; i < rdev->gart.num_gpu_pages; i++)
radeon_gart_set_page(rdev, i, rdev->gart.pages_entry[i]);
mb();
radeon_gart_tlb_flush(rdev);
}
return r;
}
void radeon_gart_table_vram_unpin(struct radeon_device *rdev)
{
int r;
if (rdev->gart.robj == NULL) {
return;
}
r = radeon_bo_reserve(rdev->gart.robj, false);
if (likely(r == 0)) {
radeon_bo_kunmap(rdev->gart.robj);
radeon_bo_unpin(rdev->gart.robj);
radeon_bo_unreserve(rdev->gart.robj);
rdev->gart.ptr = NULL;
}
}
void radeon_gart_table_vram_free(struct radeon_device *rdev)
{
if (rdev->gart.robj == NULL) {
return;
}
radeon_bo_unref(&rdev->gart.robj);
}
void radeon_gart_unbind(struct radeon_device *rdev, unsigned offset,
int pages)
{
unsigned t;
unsigned p;
int i, j;
if (!rdev->gart.ready) {
WARN(1, "trying to unbind memory from uninitialized GART !\n");
return;
}
t = offset / RADEON_GPU_PAGE_SIZE;
p = t / (PAGE_SIZE / RADEON_GPU_PAGE_SIZE);
for (i = 0; i < pages; i++, p++) {
if (rdev->gart.pages[p]) {
rdev->gart.pages[p] = NULL;
for (j = 0; j < (PAGE_SIZE / RADEON_GPU_PAGE_SIZE); j++, t++) {
rdev->gart.pages_entry[t] = rdev->dummy_page.entry;
if (rdev->gart.ptr) {
radeon_gart_set_page(rdev, t,
rdev->dummy_page.entry);
}
}
}
}
mb();
radeon_gart_tlb_flush(rdev);
}
int radeon_gart_bind(struct radeon_device *rdev, unsigned offset,
int pages, struct page **pagelist, dma_addr_t *dma_addr,
uint32_t flags)
{
unsigned t;
unsigned p;
uint64_t page_base, page_entry;
int i, j;
if (!rdev->gart.ready) {
WARN(1, "trying to bind memory to uninitialized GART !\n");
return -EINVAL;
}
t = offset / RADEON_GPU_PAGE_SIZE;
p = t / (PAGE_SIZE / RADEON_GPU_PAGE_SIZE);
for (i = 0; i < pages; i++, p++) {
rdev->gart.pages[p] = pagelist[i];
page_base = dma_addr[i];
for (j = 0; j < (PAGE_SIZE / RADEON_GPU_PAGE_SIZE); j++, t++) {
page_entry = radeon_gart_get_page_entry(page_base, flags);
rdev->gart.pages_entry[t] = page_entry;
if (rdev->gart.ptr) {
radeon_gart_set_page(rdev, t, page_entry);
}
page_base += RADEON_GPU_PAGE_SIZE;
}
}
mb();
radeon_gart_tlb_flush(rdev);
return 0;
}
int radeon_gart_init(struct radeon_device *rdev)
{
int r, i;
if (rdev->gart.pages) {
return 0;
}
if (PAGE_SIZE < RADEON_GPU_PAGE_SIZE) {
DRM_ERROR("Page size is smaller than GPU page size!\n");
return -EINVAL;
}
r = radeon_dummy_page_init(rdev);
if (r)
return r;
rdev->gart.num_cpu_pages = rdev->mc.gtt_size / PAGE_SIZE;
rdev->gart.num_gpu_pages = rdev->mc.gtt_size / RADEON_GPU_PAGE_SIZE;
DRM_INFO("GART: num cpu pages %u, num gpu pages %u\n",
rdev->gart.num_cpu_pages, rdev->gart.num_gpu_pages);
rdev->gart.pages = vzalloc(sizeof(void *) * rdev->gart.num_cpu_pages);
if (rdev->gart.pages == NULL) {
radeon_gart_fini(rdev);
return -ENOMEM;
}
rdev->gart.pages_entry = vmalloc(sizeof(uint64_t) *
rdev->gart.num_gpu_pages);
if (rdev->gart.pages_entry == NULL) {
radeon_gart_fini(rdev);
return -ENOMEM;
}
for (i = 0; i < rdev->gart.num_gpu_pages; i++)
rdev->gart.pages_entry[i] = rdev->dummy_page.entry;
return 0;
}
void radeon_gart_fini(struct radeon_device *rdev)
{
if (rdev->gart.ready) {
radeon_gart_unbind(rdev, 0, rdev->gart.num_cpu_pages);
}
rdev->gart.ready = false;
vfree(rdev->gart.pages);
vfree(rdev->gart.pages_entry);
rdev->gart.pages = NULL;
rdev->gart.pages_entry = NULL;
radeon_dummy_page_fini(rdev);
}
