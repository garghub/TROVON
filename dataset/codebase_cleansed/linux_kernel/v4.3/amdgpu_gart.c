int amdgpu_gart_table_ram_alloc(struct amdgpu_device *adev)
{
void *ptr;
ptr = pci_alloc_consistent(adev->pdev, adev->gart.table_size,
&adev->gart.table_addr);
if (ptr == NULL) {
return -ENOMEM;
}
#ifdef CONFIG_X86
if (0) {
set_memory_uc((unsigned long)ptr,
adev->gart.table_size >> PAGE_SHIFT);
}
#endif
adev->gart.ptr = ptr;
memset((void *)adev->gart.ptr, 0, adev->gart.table_size);
return 0;
}
void amdgpu_gart_table_ram_free(struct amdgpu_device *adev)
{
if (adev->gart.ptr == NULL) {
return;
}
#ifdef CONFIG_X86
if (0) {
set_memory_wb((unsigned long)adev->gart.ptr,
adev->gart.table_size >> PAGE_SHIFT);
}
#endif
pci_free_consistent(adev->pdev, adev->gart.table_size,
(void *)adev->gart.ptr,
adev->gart.table_addr);
adev->gart.ptr = NULL;
adev->gart.table_addr = 0;
}
int amdgpu_gart_table_vram_alloc(struct amdgpu_device *adev)
{
int r;
if (adev->gart.robj == NULL) {
r = amdgpu_bo_create(adev, adev->gart.table_size,
PAGE_SIZE, true, AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_CPU_ACCESS_REQUIRED,
NULL, NULL, &adev->gart.robj);
if (r) {
return r;
}
}
return 0;
}
int amdgpu_gart_table_vram_pin(struct amdgpu_device *adev)
{
uint64_t gpu_addr;
int r;
r = amdgpu_bo_reserve(adev->gart.robj, false);
if (unlikely(r != 0))
return r;
r = amdgpu_bo_pin(adev->gart.robj,
AMDGPU_GEM_DOMAIN_VRAM, &gpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->gart.robj);
return r;
}
r = amdgpu_bo_kmap(adev->gart.robj, &adev->gart.ptr);
if (r)
amdgpu_bo_unpin(adev->gart.robj);
amdgpu_bo_unreserve(adev->gart.robj);
adev->gart.table_addr = gpu_addr;
return r;
}
void amdgpu_gart_table_vram_unpin(struct amdgpu_device *adev)
{
int r;
if (adev->gart.robj == NULL) {
return;
}
r = amdgpu_bo_reserve(adev->gart.robj, false);
if (likely(r == 0)) {
amdgpu_bo_kunmap(adev->gart.robj);
amdgpu_bo_unpin(adev->gart.robj);
amdgpu_bo_unreserve(adev->gart.robj);
adev->gart.ptr = NULL;
}
}
void amdgpu_gart_table_vram_free(struct amdgpu_device *adev)
{
if (adev->gart.robj == NULL) {
return;
}
amdgpu_bo_unref(&adev->gart.robj);
}
void amdgpu_gart_unbind(struct amdgpu_device *adev, unsigned offset,
int pages)
{
unsigned t;
unsigned p;
int i, j;
u64 page_base;
uint32_t flags = AMDGPU_PTE_SYSTEM;
if (!adev->gart.ready) {
WARN(1, "trying to unbind memory from uninitialized GART !\n");
return;
}
t = offset / AMDGPU_GPU_PAGE_SIZE;
p = t / (PAGE_SIZE / AMDGPU_GPU_PAGE_SIZE);
for (i = 0; i < pages; i++, p++) {
if (adev->gart.pages[p]) {
adev->gart.pages[p] = NULL;
adev->gart.pages_addr[p] = adev->dummy_page.addr;
page_base = adev->gart.pages_addr[p];
if (!adev->gart.ptr)
continue;
for (j = 0; j < (PAGE_SIZE / AMDGPU_GPU_PAGE_SIZE); j++, t++) {
amdgpu_gart_set_pte_pde(adev, adev->gart.ptr,
t, page_base, flags);
page_base += AMDGPU_GPU_PAGE_SIZE;
}
}
}
mb();
amdgpu_gart_flush_gpu_tlb(adev, 0);
}
int amdgpu_gart_bind(struct amdgpu_device *adev, unsigned offset,
int pages, struct page **pagelist, dma_addr_t *dma_addr,
uint32_t flags)
{
unsigned t;
unsigned p;
uint64_t page_base;
int i, j;
if (!adev->gart.ready) {
WARN(1, "trying to bind memory to uninitialized GART !\n");
return -EINVAL;
}
t = offset / AMDGPU_GPU_PAGE_SIZE;
p = t / (PAGE_SIZE / AMDGPU_GPU_PAGE_SIZE);
for (i = 0; i < pages; i++, p++) {
adev->gart.pages_addr[p] = dma_addr[i];
adev->gart.pages[p] = pagelist[i];
if (adev->gart.ptr) {
page_base = adev->gart.pages_addr[p];
for (j = 0; j < (PAGE_SIZE / AMDGPU_GPU_PAGE_SIZE); j++, t++) {
amdgpu_gart_set_pte_pde(adev, adev->gart.ptr, t, page_base, flags);
page_base += AMDGPU_GPU_PAGE_SIZE;
}
}
}
mb();
amdgpu_gart_flush_gpu_tlb(adev, 0);
return 0;
}
int amdgpu_gart_init(struct amdgpu_device *adev)
{
int r, i;
if (adev->gart.pages) {
return 0;
}
if (PAGE_SIZE < AMDGPU_GPU_PAGE_SIZE) {
DRM_ERROR("Page size is smaller than GPU page size!\n");
return -EINVAL;
}
r = amdgpu_dummy_page_init(adev);
if (r)
return r;
adev->gart.num_cpu_pages = adev->mc.gtt_size / PAGE_SIZE;
adev->gart.num_gpu_pages = adev->mc.gtt_size / AMDGPU_GPU_PAGE_SIZE;
DRM_INFO("GART: num cpu pages %u, num gpu pages %u\n",
adev->gart.num_cpu_pages, adev->gart.num_gpu_pages);
adev->gart.pages = vzalloc(sizeof(void *) * adev->gart.num_cpu_pages);
if (adev->gart.pages == NULL) {
amdgpu_gart_fini(adev);
return -ENOMEM;
}
adev->gart.pages_addr = vzalloc(sizeof(dma_addr_t) *
adev->gart.num_cpu_pages);
if (adev->gart.pages_addr == NULL) {
amdgpu_gart_fini(adev);
return -ENOMEM;
}
for (i = 0; i < adev->gart.num_cpu_pages; i++) {
adev->gart.pages_addr[i] = adev->dummy_page.addr;
}
return 0;
}
void amdgpu_gart_fini(struct amdgpu_device *adev)
{
if (adev->gart.pages && adev->gart.pages_addr && adev->gart.ready) {
amdgpu_gart_unbind(adev, 0, adev->gart.num_cpu_pages);
}
adev->gart.ready = false;
vfree(adev->gart.pages);
vfree(adev->gart.pages_addr);
adev->gart.pages = NULL;
adev->gart.pages_addr = NULL;
amdgpu_dummy_page_fini(adev);
}
