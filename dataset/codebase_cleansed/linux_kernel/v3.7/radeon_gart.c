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
NULL, &rdev->gart.robj);
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
radeon_gart_table_vram_unpin(rdev);
radeon_bo_unref(&rdev->gart.robj);
}
void radeon_gart_unbind(struct radeon_device *rdev, unsigned offset,
int pages)
{
unsigned t;
unsigned p;
int i, j;
u64 page_base;
if (!rdev->gart.ready) {
WARN(1, "trying to unbind memory from uninitialized GART !\n");
return;
}
t = offset / RADEON_GPU_PAGE_SIZE;
p = t / (PAGE_SIZE / RADEON_GPU_PAGE_SIZE);
for (i = 0; i < pages; i++, p++) {
if (rdev->gart.pages[p]) {
rdev->gart.pages[p] = NULL;
rdev->gart.pages_addr[p] = rdev->dummy_page.addr;
page_base = rdev->gart.pages_addr[p];
for (j = 0; j < (PAGE_SIZE / RADEON_GPU_PAGE_SIZE); j++, t++) {
if (rdev->gart.ptr) {
radeon_gart_set_page(rdev, t, page_base);
}
page_base += RADEON_GPU_PAGE_SIZE;
}
}
}
mb();
radeon_gart_tlb_flush(rdev);
}
int radeon_gart_bind(struct radeon_device *rdev, unsigned offset,
int pages, struct page **pagelist, dma_addr_t *dma_addr)
{
unsigned t;
unsigned p;
uint64_t page_base;
int i, j;
if (!rdev->gart.ready) {
WARN(1, "trying to bind memory to uninitialized GART !\n");
return -EINVAL;
}
t = offset / RADEON_GPU_PAGE_SIZE;
p = t / (PAGE_SIZE / RADEON_GPU_PAGE_SIZE);
for (i = 0; i < pages; i++, p++) {
rdev->gart.pages_addr[p] = dma_addr[i];
rdev->gart.pages[p] = pagelist[i];
if (rdev->gart.ptr) {
page_base = rdev->gart.pages_addr[p];
for (j = 0; j < (PAGE_SIZE / RADEON_GPU_PAGE_SIZE); j++, t++) {
radeon_gart_set_page(rdev, t, page_base);
page_base += RADEON_GPU_PAGE_SIZE;
}
}
}
mb();
radeon_gart_tlb_flush(rdev);
return 0;
}
void radeon_gart_restore(struct radeon_device *rdev)
{
int i, j, t;
u64 page_base;
if (!rdev->gart.ptr) {
return;
}
for (i = 0, t = 0; i < rdev->gart.num_cpu_pages; i++) {
page_base = rdev->gart.pages_addr[i];
for (j = 0; j < (PAGE_SIZE / RADEON_GPU_PAGE_SIZE); j++, t++) {
radeon_gart_set_page(rdev, t, page_base);
page_base += RADEON_GPU_PAGE_SIZE;
}
}
mb();
radeon_gart_tlb_flush(rdev);
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
rdev->gart.pages_addr = vzalloc(sizeof(dma_addr_t) *
rdev->gart.num_cpu_pages);
if (rdev->gart.pages_addr == NULL) {
radeon_gart_fini(rdev);
return -ENOMEM;
}
for (i = 0; i < rdev->gart.num_cpu_pages; i++) {
rdev->gart.pages_addr[i] = rdev->dummy_page.addr;
}
return 0;
}
void radeon_gart_fini(struct radeon_device *rdev)
{
if (rdev->gart.pages && rdev->gart.pages_addr && rdev->gart.ready) {
radeon_gart_unbind(rdev, 0, rdev->gart.num_cpu_pages);
}
rdev->gart.ready = false;
vfree(rdev->gart.pages);
vfree(rdev->gart.pages_addr);
rdev->gart.pages = NULL;
rdev->gart.pages_addr = NULL;
radeon_dummy_page_fini(rdev);
}
static unsigned radeon_vm_num_pdes(struct radeon_device *rdev)
{
return rdev->vm_manager.max_pfn >> RADEON_VM_BLOCK_SIZE;
}
static unsigned radeon_vm_directory_size(struct radeon_device *rdev)
{
return RADEON_GPU_PAGE_ALIGN(radeon_vm_num_pdes(rdev) * 8);
}
int radeon_vm_manager_init(struct radeon_device *rdev)
{
struct radeon_vm *vm;
struct radeon_bo_va *bo_va;
int r;
unsigned size;
if (!rdev->vm_manager.enabled) {
size = radeon_vm_directory_size(rdev);
size += rdev->vm_manager.max_pfn * 8;
size *= 2;
r = radeon_sa_bo_manager_init(rdev, &rdev->vm_manager.sa_manager,
RADEON_GPU_PAGE_ALIGN(size),
RADEON_GEM_DOMAIN_VRAM);
if (r) {
dev_err(rdev->dev, "failed to allocate vm bo (%dKB)\n",
(rdev->vm_manager.max_pfn * 8) >> 10);
return r;
}
r = radeon_asic_vm_init(rdev);
if (r)
return r;
rdev->vm_manager.enabled = true;
r = radeon_sa_bo_manager_start(rdev, &rdev->vm_manager.sa_manager);
if (r)
return r;
}
list_for_each_entry(vm, &rdev->vm_manager.lru_vm, list) {
if (vm->page_directory == NULL)
continue;
list_for_each_entry(bo_va, &vm->va, vm_list) {
bo_va->valid = false;
}
}
return 0;
}
static void radeon_vm_free_pt(struct radeon_device *rdev,
struct radeon_vm *vm)
{
struct radeon_bo_va *bo_va;
int i;
if (!vm->page_directory)
return;
list_del_init(&vm->list);
radeon_sa_bo_free(rdev, &vm->page_directory, vm->fence);
list_for_each_entry(bo_va, &vm->va, vm_list) {
bo_va->valid = false;
}
if (vm->page_tables == NULL)
return;
for (i = 0; i < radeon_vm_num_pdes(rdev); i++)
radeon_sa_bo_free(rdev, &vm->page_tables[i], vm->fence);
kfree(vm->page_tables);
}
void radeon_vm_manager_fini(struct radeon_device *rdev)
{
struct radeon_vm *vm, *tmp;
int i;
if (!rdev->vm_manager.enabled)
return;
mutex_lock(&rdev->vm_manager.lock);
list_for_each_entry_safe(vm, tmp, &rdev->vm_manager.lru_vm, list) {
mutex_lock(&vm->mutex);
radeon_vm_free_pt(rdev, vm);
mutex_unlock(&vm->mutex);
}
for (i = 0; i < RADEON_NUM_VM; ++i) {
radeon_fence_unref(&rdev->vm_manager.active[i]);
}
radeon_asic_vm_fini(rdev);
mutex_unlock(&rdev->vm_manager.lock);
radeon_sa_bo_manager_suspend(rdev, &rdev->vm_manager.sa_manager);
radeon_sa_bo_manager_fini(rdev, &rdev->vm_manager.sa_manager);
rdev->vm_manager.enabled = false;
}
static int radeon_vm_evict(struct radeon_device *rdev, struct radeon_vm *vm)
{
struct radeon_vm *vm_evict;
if (list_empty(&rdev->vm_manager.lru_vm))
return -ENOMEM;
vm_evict = list_first_entry(&rdev->vm_manager.lru_vm,
struct radeon_vm, list);
if (vm_evict == vm)
return -ENOMEM;
mutex_lock(&vm_evict->mutex);
radeon_vm_free_pt(rdev, vm_evict);
mutex_unlock(&vm_evict->mutex);
return 0;
}
int radeon_vm_alloc_pt(struct radeon_device *rdev, struct radeon_vm *vm)
{
unsigned pd_size, pts_size;
u64 *pd_addr;
int r;
if (vm == NULL) {
return -EINVAL;
}
if (vm->page_directory != NULL) {
return 0;
}
retry:
pd_size = RADEON_GPU_PAGE_ALIGN(radeon_vm_directory_size(rdev));
r = radeon_sa_bo_new(rdev, &rdev->vm_manager.sa_manager,
&vm->page_directory, pd_size,
RADEON_GPU_PAGE_SIZE, false);
if (r == -ENOMEM) {
r = radeon_vm_evict(rdev, vm);
if (r)
return r;
goto retry;
} else if (r) {
return r;
}
vm->pd_gpu_addr = radeon_sa_bo_gpu_addr(vm->page_directory);
pd_addr = radeon_sa_bo_cpu_addr(vm->page_directory);
memset(pd_addr, 0, pd_size);
pts_size = radeon_vm_num_pdes(rdev) * sizeof(struct radeon_sa_bo *);
vm->page_tables = kzalloc(pts_size, GFP_KERNEL);
if (vm->page_tables == NULL) {
DRM_ERROR("Cannot allocate memory for page table array\n");
radeon_sa_bo_free(rdev, &vm->page_directory, vm->fence);
return -ENOMEM;
}
return 0;
}
void radeon_vm_add_to_lru(struct radeon_device *rdev, struct radeon_vm *vm)
{
list_del_init(&vm->list);
list_add_tail(&vm->list, &rdev->vm_manager.lru_vm);
}
struct radeon_fence *radeon_vm_grab_id(struct radeon_device *rdev,
struct radeon_vm *vm, int ring)
{
struct radeon_fence *best[RADEON_NUM_RINGS] = {};
unsigned choices[2] = {};
unsigned i;
if (vm->fence && vm->fence == rdev->vm_manager.active[vm->id])
return NULL;
radeon_fence_unref(&vm->last_flush);
for (i = 1; i < rdev->vm_manager.nvm; ++i) {
struct radeon_fence *fence = rdev->vm_manager.active[i];
if (fence == NULL) {
vm->id = i;
return NULL;
}
if (radeon_fence_is_earlier(fence, best[fence->ring])) {
best[fence->ring] = fence;
choices[fence->ring == ring ? 0 : 1] = i;
}
}
for (i = 0; i < 2; ++i) {
if (choices[i]) {
vm->id = choices[i];
return rdev->vm_manager.active[choices[i]];
}
}
BUG();
return NULL;
}
void radeon_vm_fence(struct radeon_device *rdev,
struct radeon_vm *vm,
struct radeon_fence *fence)
{
radeon_fence_unref(&rdev->vm_manager.active[vm->id]);
rdev->vm_manager.active[vm->id] = radeon_fence_ref(fence);
radeon_fence_unref(&vm->fence);
vm->fence = radeon_fence_ref(fence);
}
struct radeon_bo_va *radeon_vm_bo_find(struct radeon_vm *vm,
struct radeon_bo *bo)
{
struct radeon_bo_va *bo_va;
list_for_each_entry(bo_va, &bo->va, bo_list) {
if (bo_va->vm == vm) {
return bo_va;
}
}
return NULL;
}
struct radeon_bo_va *radeon_vm_bo_add(struct radeon_device *rdev,
struct radeon_vm *vm,
struct radeon_bo *bo)
{
struct radeon_bo_va *bo_va;
bo_va = kzalloc(sizeof(struct radeon_bo_va), GFP_KERNEL);
if (bo_va == NULL) {
return NULL;
}
bo_va->vm = vm;
bo_va->bo = bo;
bo_va->soffset = 0;
bo_va->eoffset = 0;
bo_va->flags = 0;
bo_va->valid = false;
bo_va->ref_count = 1;
INIT_LIST_HEAD(&bo_va->bo_list);
INIT_LIST_HEAD(&bo_va->vm_list);
mutex_lock(&vm->mutex);
list_add(&bo_va->vm_list, &vm->va);
list_add_tail(&bo_va->bo_list, &bo->va);
mutex_unlock(&vm->mutex);
return bo_va;
}
int radeon_vm_bo_set_addr(struct radeon_device *rdev,
struct radeon_bo_va *bo_va,
uint64_t soffset,
uint32_t flags)
{
uint64_t size = radeon_bo_size(bo_va->bo);
uint64_t eoffset, last_offset = 0;
struct radeon_vm *vm = bo_va->vm;
struct radeon_bo_va *tmp;
struct list_head *head;
unsigned last_pfn;
if (soffset) {
eoffset = soffset + size;
if (soffset >= eoffset) {
return -EINVAL;
}
last_pfn = eoffset / RADEON_GPU_PAGE_SIZE;
if (last_pfn > rdev->vm_manager.max_pfn) {
dev_err(rdev->dev, "va above limit (0x%08X > 0x%08X)\n",
last_pfn, rdev->vm_manager.max_pfn);
return -EINVAL;
}
} else {
eoffset = last_pfn = 0;
}
mutex_lock(&vm->mutex);
head = &vm->va;
last_offset = 0;
list_for_each_entry(tmp, &vm->va, vm_list) {
if (bo_va == tmp) {
continue;
}
if (soffset >= last_offset && eoffset <= tmp->soffset) {
break;
}
if (eoffset > tmp->soffset && soffset < tmp->eoffset) {
dev_err(rdev->dev, "bo %p va 0x%08X conflict with (bo %p 0x%08X 0x%08X)\n",
bo_va->bo, (unsigned)bo_va->soffset, tmp->bo,
(unsigned)tmp->soffset, (unsigned)tmp->eoffset);
mutex_unlock(&vm->mutex);
return -EINVAL;
}
last_offset = tmp->eoffset;
head = &tmp->vm_list;
}
bo_va->soffset = soffset;
bo_va->eoffset = eoffset;
bo_va->flags = flags;
bo_va->valid = false;
list_move(&bo_va->vm_list, head);
mutex_unlock(&vm->mutex);
return 0;
}
uint64_t radeon_vm_map_gart(struct radeon_device *rdev, uint64_t addr)
{
uint64_t result;
result = rdev->gart.pages_addr[addr >> PAGE_SHIFT];
result |= addr & (~PAGE_MASK);
return result;
}
static int radeon_vm_update_pdes(struct radeon_device *rdev,
struct radeon_vm *vm,
uint64_t start, uint64_t end)
{
static const uint32_t incr = RADEON_VM_PTE_COUNT * 8;
uint64_t last_pde = ~0, last_pt = ~0;
unsigned count = 0;
uint64_t pt_idx;
int r;
start = (start / RADEON_GPU_PAGE_SIZE) >> RADEON_VM_BLOCK_SIZE;
end = (end / RADEON_GPU_PAGE_SIZE) >> RADEON_VM_BLOCK_SIZE;
for (pt_idx = start; pt_idx <= end; ++pt_idx) {
uint64_t pde, pt;
if (vm->page_tables[pt_idx])
continue;
retry:
r = radeon_sa_bo_new(rdev, &rdev->vm_manager.sa_manager,
&vm->page_tables[pt_idx],
RADEON_VM_PTE_COUNT * 8,
RADEON_GPU_PAGE_SIZE, false);
if (r == -ENOMEM) {
r = radeon_vm_evict(rdev, vm);
if (r)
return r;
goto retry;
} else if (r) {
return r;
}
pde = vm->pd_gpu_addr + pt_idx * 8;
pt = radeon_sa_bo_gpu_addr(vm->page_tables[pt_idx]);
if (((last_pde + 8 * count) != pde) ||
((last_pt + incr * count) != pt)) {
if (count) {
radeon_asic_vm_set_page(rdev, last_pde,
last_pt, count, incr,
RADEON_VM_PAGE_VALID);
}
count = 1;
last_pde = pde;
last_pt = pt;
} else {
++count;
}
}
if (count) {
radeon_asic_vm_set_page(rdev, last_pde, last_pt, count,
incr, RADEON_VM_PAGE_VALID);
}
return 0;
}
static void radeon_vm_update_ptes(struct radeon_device *rdev,
struct radeon_vm *vm,
uint64_t start, uint64_t end,
uint64_t dst, uint32_t flags)
{
static const uint64_t mask = RADEON_VM_PTE_COUNT - 1;
uint64_t last_pte = ~0, last_dst = ~0;
unsigned count = 0;
uint64_t addr;
start = start / RADEON_GPU_PAGE_SIZE;
end = end / RADEON_GPU_PAGE_SIZE;
for (addr = start; addr < end; ) {
uint64_t pt_idx = addr >> RADEON_VM_BLOCK_SIZE;
unsigned nptes;
uint64_t pte;
if ((addr & ~mask) == (end & ~mask))
nptes = end - addr;
else
nptes = RADEON_VM_PTE_COUNT - (addr & mask);
pte = radeon_sa_bo_gpu_addr(vm->page_tables[pt_idx]);
pte += (addr & mask) * 8;
if ((last_pte + 8 * count) != pte) {
if (count) {
radeon_asic_vm_set_page(rdev, last_pte,
last_dst, count,
RADEON_GPU_PAGE_SIZE,
flags);
}
count = nptes;
last_pte = pte;
last_dst = dst;
} else {
count += nptes;
}
addr += nptes;
dst += nptes * RADEON_GPU_PAGE_SIZE;
}
if (count) {
radeon_asic_vm_set_page(rdev, last_pte, last_dst, count,
RADEON_GPU_PAGE_SIZE, flags);
}
}
int radeon_vm_bo_update_pte(struct radeon_device *rdev,
struct radeon_vm *vm,
struct radeon_bo *bo,
struct ttm_mem_reg *mem)
{
unsigned ridx = rdev->asic->vm.pt_ring_index;
struct radeon_ring *ring = &rdev->ring[ridx];
struct radeon_semaphore *sem = NULL;
struct radeon_bo_va *bo_va;
unsigned nptes, npdes, ndw;
uint64_t addr;
int r;
if (vm->page_directory == NULL)
return 0;
bo_va = radeon_vm_bo_find(vm, bo);
if (bo_va == NULL) {
dev_err(rdev->dev, "bo %p not in vm %p\n", bo, vm);
return -EINVAL;
}
if (!bo_va->soffset) {
dev_err(rdev->dev, "bo %p don't has a mapping in vm %p\n",
bo, vm);
return -EINVAL;
}
if ((bo_va->valid && mem) || (!bo_va->valid && mem == NULL))
return 0;
bo_va->flags &= ~RADEON_VM_PAGE_VALID;
bo_va->flags &= ~RADEON_VM_PAGE_SYSTEM;
if (mem) {
addr = mem->start << PAGE_SHIFT;
if (mem->mem_type != TTM_PL_SYSTEM) {
bo_va->flags |= RADEON_VM_PAGE_VALID;
bo_va->valid = true;
}
if (mem->mem_type == TTM_PL_TT) {
bo_va->flags |= RADEON_VM_PAGE_SYSTEM;
} else {
addr += rdev->vm_manager.vram_base_offset;
}
} else {
addr = 0;
bo_va->valid = false;
}
if (vm->fence && radeon_fence_signaled(vm->fence)) {
radeon_fence_unref(&vm->fence);
}
if (vm->fence && vm->fence->ring != ridx) {
r = radeon_semaphore_create(rdev, &sem);
if (r) {
return r;
}
}
nptes = radeon_bo_ngpu_pages(bo);
npdes = (nptes >> RADEON_VM_BLOCK_SIZE) + 2;
ndw = 32;
if (RADEON_VM_BLOCK_SIZE > 11)
ndw += (nptes >> 11) * 4;
else
ndw += (nptes >> RADEON_VM_BLOCK_SIZE) * 4;
ndw += nptes * 2;
ndw += (npdes >> 11) * 4;
ndw += npdes * 2;
r = radeon_ring_lock(rdev, ring, ndw);
if (r) {
return r;
}
if (sem && radeon_fence_need_sync(vm->fence, ridx)) {
radeon_semaphore_sync_rings(rdev, sem, vm->fence->ring, ridx);
radeon_fence_note_sync(vm->fence, ridx);
}
r = radeon_vm_update_pdes(rdev, vm, bo_va->soffset, bo_va->eoffset);
if (r) {
radeon_ring_unlock_undo(rdev, ring);
return r;
}
radeon_vm_update_ptes(rdev, vm, bo_va->soffset, bo_va->eoffset,
addr, bo_va->flags);
radeon_fence_unref(&vm->fence);
r = radeon_fence_emit(rdev, &vm->fence, ridx);
if (r) {
radeon_ring_unlock_undo(rdev, ring);
return r;
}
radeon_ring_unlock_commit(rdev, ring);
radeon_semaphore_free(rdev, &sem, vm->fence);
radeon_fence_unref(&vm->last_flush);
return 0;
}
int radeon_vm_bo_rmv(struct radeon_device *rdev,
struct radeon_bo_va *bo_va)
{
int r;
mutex_lock(&rdev->vm_manager.lock);
mutex_lock(&bo_va->vm->mutex);
r = radeon_vm_bo_update_pte(rdev, bo_va->vm, bo_va->bo, NULL);
mutex_unlock(&rdev->vm_manager.lock);
list_del(&bo_va->vm_list);
mutex_unlock(&bo_va->vm->mutex);
list_del(&bo_va->bo_list);
kfree(bo_va);
return r;
}
void radeon_vm_bo_invalidate(struct radeon_device *rdev,
struct radeon_bo *bo)
{
struct radeon_bo_va *bo_va;
BUG_ON(!atomic_read(&bo->tbo.reserved));
list_for_each_entry(bo_va, &bo->va, bo_list) {
bo_va->valid = false;
}
}
void radeon_vm_init(struct radeon_device *rdev, struct radeon_vm *vm)
{
vm->id = 0;
vm->fence = NULL;
mutex_init(&vm->mutex);
INIT_LIST_HEAD(&vm->list);
INIT_LIST_HEAD(&vm->va);
}
void radeon_vm_fini(struct radeon_device *rdev, struct radeon_vm *vm)
{
struct radeon_bo_va *bo_va, *tmp;
int r;
mutex_lock(&rdev->vm_manager.lock);
mutex_lock(&vm->mutex);
radeon_vm_free_pt(rdev, vm);
mutex_unlock(&rdev->vm_manager.lock);
if (!list_empty(&vm->va)) {
dev_err(rdev->dev, "still active bo inside vm\n");
}
list_for_each_entry_safe(bo_va, tmp, &vm->va, vm_list) {
list_del_init(&bo_va->vm_list);
r = radeon_bo_reserve(bo_va->bo, false);
if (!r) {
list_del_init(&bo_va->bo_list);
radeon_bo_unreserve(bo_va->bo);
kfree(bo_va);
}
}
radeon_fence_unref(&vm->fence);
radeon_fence_unref(&vm->last_flush);
mutex_unlock(&vm->mutex);
}
