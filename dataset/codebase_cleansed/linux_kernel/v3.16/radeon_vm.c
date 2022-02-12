static unsigned radeon_vm_num_pdes(struct radeon_device *rdev)
{
return rdev->vm_manager.max_pfn >> radeon_vm_block_size;
}
static unsigned radeon_vm_directory_size(struct radeon_device *rdev)
{
return RADEON_GPU_PAGE_ALIGN(radeon_vm_num_pdes(rdev) * 8);
}
int radeon_vm_manager_init(struct radeon_device *rdev)
{
int r;
if (!rdev->vm_manager.enabled) {
r = radeon_asic_vm_init(rdev);
if (r)
return r;
rdev->vm_manager.enabled = true;
}
return 0;
}
void radeon_vm_manager_fini(struct radeon_device *rdev)
{
int i;
if (!rdev->vm_manager.enabled)
return;
for (i = 0; i < RADEON_NUM_VM; ++i)
radeon_fence_unref(&rdev->vm_manager.active[i]);
radeon_asic_vm_fini(rdev);
rdev->vm_manager.enabled = false;
}
struct radeon_cs_reloc *radeon_vm_get_bos(struct radeon_device *rdev,
struct radeon_vm *vm,
struct list_head *head)
{
struct radeon_cs_reloc *list;
unsigned i, idx;
list = kmalloc_array(vm->max_pde_used + 2,
sizeof(struct radeon_cs_reloc), GFP_KERNEL);
if (!list)
return NULL;
list[0].gobj = NULL;
list[0].robj = vm->page_directory;
list[0].prefered_domains = RADEON_GEM_DOMAIN_VRAM;
list[0].allowed_domains = RADEON_GEM_DOMAIN_VRAM;
list[0].tv.bo = &vm->page_directory->tbo;
list[0].tiling_flags = 0;
list[0].handle = 0;
list_add(&list[0].tv.head, head);
for (i = 0, idx = 1; i <= vm->max_pde_used; i++) {
if (!vm->page_tables[i].bo)
continue;
list[idx].gobj = NULL;
list[idx].robj = vm->page_tables[i].bo;
list[idx].prefered_domains = RADEON_GEM_DOMAIN_VRAM;
list[idx].allowed_domains = RADEON_GEM_DOMAIN_VRAM;
list[idx].tv.bo = &list[idx].robj->tbo;
list[idx].tiling_flags = 0;
list[idx].handle = 0;
list_add(&list[idx++].tv.head, head);
}
return list;
}
struct radeon_fence *radeon_vm_grab_id(struct radeon_device *rdev,
struct radeon_vm *vm, int ring)
{
struct radeon_fence *best[RADEON_NUM_RINGS] = {};
unsigned choices[2] = {};
unsigned i;
if (vm->last_id_use && vm->last_id_use == rdev->vm_manager.active[vm->id])
return NULL;
radeon_fence_unref(&vm->last_flush);
for (i = 1; i < rdev->vm_manager.nvm; ++i) {
struct radeon_fence *fence = rdev->vm_manager.active[i];
if (fence == NULL) {
vm->id = i;
trace_radeon_vm_grab_id(vm->id, ring);
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
trace_radeon_vm_grab_id(vm->id, ring);
return rdev->vm_manager.active[choices[i]];
}
}
BUG();
return NULL;
}
void radeon_vm_flush(struct radeon_device *rdev,
struct radeon_vm *vm,
int ring)
{
uint64_t pd_addr = radeon_bo_gpu_offset(vm->page_directory);
if (!vm->last_flush || true || pd_addr != vm->pd_gpu_addr) {
vm->pd_gpu_addr = pd_addr;
radeon_ring_vm_flush(rdev, ring, vm);
}
}
void radeon_vm_fence(struct radeon_device *rdev,
struct radeon_vm *vm,
struct radeon_fence *fence)
{
radeon_fence_unref(&vm->fence);
vm->fence = radeon_fence_ref(fence);
radeon_fence_unref(&rdev->vm_manager.active[vm->id]);
rdev->vm_manager.active[vm->id] = radeon_fence_ref(fence);
radeon_fence_unref(&vm->last_id_use);
vm->last_id_use = radeon_fence_ref(fence);
if (!vm->last_flush)
vm->last_flush = radeon_fence_ref(fence);
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
INIT_LIST_HEAD(&bo_va->vm_status);
mutex_lock(&vm->mutex);
list_add(&bo_va->vm_list, &vm->va);
list_add_tail(&bo_va->bo_list, &bo->va);
mutex_unlock(&vm->mutex);
return bo_va;
}
static int radeon_vm_clear_bo(struct radeon_device *rdev,
struct radeon_bo *bo)
{
struct ttm_validate_buffer tv;
struct ww_acquire_ctx ticket;
struct list_head head;
struct radeon_ib ib;
unsigned entries;
uint64_t addr;
int r;
memset(&tv, 0, sizeof(tv));
tv.bo = &bo->tbo;
INIT_LIST_HEAD(&head);
list_add(&tv.head, &head);
r = ttm_eu_reserve_buffers(&ticket, &head);
if (r)
return r;
r = ttm_bo_validate(&bo->tbo, &bo->placement, true, false);
if (r)
goto error;
addr = radeon_bo_gpu_offset(bo);
entries = radeon_bo_size(bo) / 8;
r = radeon_ib_get(rdev, R600_RING_TYPE_DMA_INDEX, &ib,
NULL, entries * 2 + 64);
if (r)
goto error;
ib.length_dw = 0;
radeon_asic_vm_set_page(rdev, &ib, addr, 0, entries, 0, 0);
r = radeon_ib_schedule(rdev, &ib, NULL);
if (r)
goto error;
ttm_eu_fence_buffer_objects(&ticket, &head, ib.fence);
radeon_ib_free(rdev, &ib);
return 0;
error:
ttm_eu_backoff_reservation(&ticket, &head);
return r;
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
unsigned last_pfn, pt_idx;
int r;
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
if (bo_va->soffset) {
tmp = kzalloc(sizeof(struct radeon_bo_va), GFP_KERNEL);
if (!tmp) {
mutex_unlock(&vm->mutex);
return -ENOMEM;
}
tmp->soffset = bo_va->soffset;
tmp->eoffset = bo_va->eoffset;
tmp->vm = vm;
list_add(&tmp->vm_status, &vm->freed);
}
bo_va->soffset = soffset;
bo_va->eoffset = eoffset;
bo_va->flags = flags;
bo_va->valid = false;
list_move(&bo_va->vm_list, head);
soffset = (soffset / RADEON_GPU_PAGE_SIZE) >> radeon_vm_block_size;
eoffset = (eoffset / RADEON_GPU_PAGE_SIZE) >> radeon_vm_block_size;
BUG_ON(eoffset >= radeon_vm_num_pdes(rdev));
if (eoffset > vm->max_pde_used)
vm->max_pde_used = eoffset;
radeon_bo_unreserve(bo_va->bo);
for (pt_idx = soffset; pt_idx <= eoffset; ++pt_idx) {
struct radeon_bo *pt;
if (vm->page_tables[pt_idx].bo)
continue;
mutex_unlock(&vm->mutex);
r = radeon_bo_create(rdev, RADEON_VM_PTE_COUNT * 8,
RADEON_GPU_PAGE_SIZE, true,
RADEON_GEM_DOMAIN_VRAM, NULL, &pt);
if (r)
return r;
r = radeon_vm_clear_bo(rdev, pt);
if (r) {
radeon_bo_unref(&pt);
radeon_bo_reserve(bo_va->bo, false);
return r;
}
mutex_lock(&vm->mutex);
if (vm->page_tables[pt_idx].bo) {
mutex_unlock(&vm->mutex);
radeon_bo_unref(&pt);
mutex_lock(&vm->mutex);
continue;
}
vm->page_tables[pt_idx].addr = 0;
vm->page_tables[pt_idx].bo = pt;
}
mutex_unlock(&vm->mutex);
return radeon_bo_reserve(bo_va->bo, false);
}
uint64_t radeon_vm_map_gart(struct radeon_device *rdev, uint64_t addr)
{
uint64_t result;
result = rdev->gart.pages_addr[addr >> PAGE_SHIFT];
result |= addr & (~PAGE_MASK);
return result;
}
static uint32_t radeon_vm_page_flags(uint32_t flags)
{
uint32_t hw_flags = 0;
hw_flags |= (flags & RADEON_VM_PAGE_VALID) ? R600_PTE_VALID : 0;
hw_flags |= (flags & RADEON_VM_PAGE_READABLE) ? R600_PTE_READABLE : 0;
hw_flags |= (flags & RADEON_VM_PAGE_WRITEABLE) ? R600_PTE_WRITEABLE : 0;
if (flags & RADEON_VM_PAGE_SYSTEM) {
hw_flags |= R600_PTE_SYSTEM;
hw_flags |= (flags & RADEON_VM_PAGE_SNOOPED) ? R600_PTE_SNOOPED : 0;
}
return hw_flags;
}
int radeon_vm_update_page_directory(struct radeon_device *rdev,
struct radeon_vm *vm)
{
struct radeon_bo *pd = vm->page_directory;
uint64_t pd_addr = radeon_bo_gpu_offset(pd);
uint32_t incr = RADEON_VM_PTE_COUNT * 8;
uint64_t last_pde = ~0, last_pt = ~0;
unsigned count = 0, pt_idx, ndw;
struct radeon_ib ib;
int r;
ndw = 64;
ndw += vm->max_pde_used * 16;
if (ndw > 0xfffff)
return -ENOMEM;
r = radeon_ib_get(rdev, R600_RING_TYPE_DMA_INDEX, &ib, NULL, ndw * 4);
if (r)
return r;
ib.length_dw = 0;
for (pt_idx = 0; pt_idx <= vm->max_pde_used; ++pt_idx) {
struct radeon_bo *bo = vm->page_tables[pt_idx].bo;
uint64_t pde, pt;
if (bo == NULL)
continue;
pt = radeon_bo_gpu_offset(bo);
if (vm->page_tables[pt_idx].addr == pt)
continue;
vm->page_tables[pt_idx].addr = pt;
pde = pd_addr + pt_idx * 8;
if (((last_pde + 8 * count) != pde) ||
((last_pt + incr * count) != pt)) {
if (count) {
radeon_asic_vm_set_page(rdev, &ib, last_pde,
last_pt, count, incr,
R600_PTE_VALID);
}
count = 1;
last_pde = pde;
last_pt = pt;
} else {
++count;
}
}
if (count)
radeon_asic_vm_set_page(rdev, &ib, last_pde, last_pt, count,
incr, R600_PTE_VALID);
if (ib.length_dw != 0) {
radeon_semaphore_sync_to(ib.semaphore, pd->tbo.sync_obj);
radeon_semaphore_sync_to(ib.semaphore, vm->last_id_use);
r = radeon_ib_schedule(rdev, &ib, NULL);
if (r) {
radeon_ib_free(rdev, &ib);
return r;
}
radeon_fence_unref(&vm->fence);
vm->fence = radeon_fence_ref(ib.fence);
radeon_fence_unref(&vm->last_flush);
}
radeon_ib_free(rdev, &ib);
return 0;
}
static void radeon_vm_frag_ptes(struct radeon_device *rdev,
struct radeon_ib *ib,
uint64_t pe_start, uint64_t pe_end,
uint64_t addr, uint32_t flags)
{
uint64_t frag_flags = rdev->family == CHIP_CAYMAN ?
R600_PTE_FRAG_256KB : R600_PTE_FRAG_64KB;
uint64_t frag_align = rdev->family == CHIP_CAYMAN ? 0x200 : 0x80;
uint64_t frag_start = ALIGN(pe_start, frag_align);
uint64_t frag_end = pe_end & ~(frag_align - 1);
unsigned count;
if ((flags & R600_PTE_SYSTEM) || !(flags & R600_PTE_VALID) ||
(frag_start >= frag_end)) {
count = (pe_end - pe_start) / 8;
radeon_asic_vm_set_page(rdev, ib, pe_start, addr, count,
RADEON_GPU_PAGE_SIZE, flags);
return;
}
if (pe_start != frag_start) {
count = (frag_start - pe_start) / 8;
radeon_asic_vm_set_page(rdev, ib, pe_start, addr, count,
RADEON_GPU_PAGE_SIZE, flags);
addr += RADEON_GPU_PAGE_SIZE * count;
}
count = (frag_end - frag_start) / 8;
radeon_asic_vm_set_page(rdev, ib, frag_start, addr, count,
RADEON_GPU_PAGE_SIZE, flags | frag_flags);
if (frag_end != pe_end) {
addr += RADEON_GPU_PAGE_SIZE * count;
count = (pe_end - frag_end) / 8;
radeon_asic_vm_set_page(rdev, ib, frag_end, addr, count,
RADEON_GPU_PAGE_SIZE, flags);
}
}
static void radeon_vm_update_ptes(struct radeon_device *rdev,
struct radeon_vm *vm,
struct radeon_ib *ib,
uint64_t start, uint64_t end,
uint64_t dst, uint32_t flags)
{
uint64_t mask = RADEON_VM_PTE_COUNT - 1;
uint64_t last_pte = ~0, last_dst = ~0;
unsigned count = 0;
uint64_t addr;
start = start / RADEON_GPU_PAGE_SIZE;
end = end / RADEON_GPU_PAGE_SIZE;
for (addr = start; addr < end; ) {
uint64_t pt_idx = addr >> radeon_vm_block_size;
struct radeon_bo *pt = vm->page_tables[pt_idx].bo;
unsigned nptes;
uint64_t pte;
radeon_semaphore_sync_to(ib->semaphore, pt->tbo.sync_obj);
if ((addr & ~mask) == (end & ~mask))
nptes = end - addr;
else
nptes = RADEON_VM_PTE_COUNT - (addr & mask);
pte = radeon_bo_gpu_offset(pt);
pte += (addr & mask) * 8;
if ((last_pte + 8 * count) != pte) {
if (count) {
radeon_vm_frag_ptes(rdev, ib, last_pte,
last_pte + 8 * count,
last_dst, flags);
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
radeon_vm_frag_ptes(rdev, ib, last_pte,
last_pte + 8 * count,
last_dst, flags);
}
}
int radeon_vm_bo_update(struct radeon_device *rdev,
struct radeon_bo_va *bo_va,
struct ttm_mem_reg *mem)
{
struct radeon_vm *vm = bo_va->vm;
struct radeon_ib ib;
unsigned nptes, ndw;
uint64_t addr;
int r;
if (!bo_va->soffset) {
dev_err(rdev->dev, "bo %p don't has a mapping in vm %p\n",
bo_va->bo, vm);
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
trace_radeon_vm_bo_update(bo_va);
nptes = (bo_va->eoffset - bo_va->soffset) / RADEON_GPU_PAGE_SIZE;
ndw = 64;
if (radeon_vm_block_size > 11)
ndw += (nptes >> 11) * 4;
else
ndw += (nptes >> radeon_vm_block_size) * 4;
ndw += nptes * 2;
if (ndw > 0xfffff)
return -ENOMEM;
r = radeon_ib_get(rdev, R600_RING_TYPE_DMA_INDEX, &ib, NULL, ndw * 4);
if (r)
return r;
ib.length_dw = 0;
radeon_vm_update_ptes(rdev, vm, &ib, bo_va->soffset, bo_va->eoffset,
addr, radeon_vm_page_flags(bo_va->flags));
radeon_semaphore_sync_to(ib.semaphore, vm->fence);
r = radeon_ib_schedule(rdev, &ib, NULL);
if (r) {
radeon_ib_free(rdev, &ib);
return r;
}
radeon_fence_unref(&vm->fence);
vm->fence = radeon_fence_ref(ib.fence);
radeon_ib_free(rdev, &ib);
radeon_fence_unref(&vm->last_flush);
return 0;
}
int radeon_vm_clear_freed(struct radeon_device *rdev,
struct radeon_vm *vm)
{
struct radeon_bo_va *bo_va, *tmp;
int r;
list_for_each_entry_safe(bo_va, tmp, &vm->freed, vm_status) {
list_del(&bo_va->vm_status);
r = radeon_vm_bo_update(rdev, bo_va, NULL);
kfree(bo_va);
if (r)
return r;
}
return 0;
}
void radeon_vm_bo_rmv(struct radeon_device *rdev,
struct radeon_bo_va *bo_va)
{
struct radeon_vm *vm = bo_va->vm;
list_del(&bo_va->bo_list);
mutex_lock(&vm->mutex);
list_del(&bo_va->vm_list);
if (bo_va->soffset) {
bo_va->bo = NULL;
list_add(&bo_va->vm_status, &vm->freed);
} else {
kfree(bo_va);
}
mutex_unlock(&vm->mutex);
}
void radeon_vm_bo_invalidate(struct radeon_device *rdev,
struct radeon_bo *bo)
{
struct radeon_bo_va *bo_va;
list_for_each_entry(bo_va, &bo->va, bo_list) {
bo_va->valid = false;
}
}
int radeon_vm_init(struct radeon_device *rdev, struct radeon_vm *vm)
{
const unsigned align = min(RADEON_VM_PTB_ALIGN_SIZE,
RADEON_VM_PTE_COUNT * 8);
unsigned pd_size, pd_entries, pts_size;
int r;
vm->id = 0;
vm->ib_bo_va = NULL;
vm->fence = NULL;
vm->last_flush = NULL;
vm->last_id_use = NULL;
mutex_init(&vm->mutex);
INIT_LIST_HEAD(&vm->va);
INIT_LIST_HEAD(&vm->freed);
pd_size = radeon_vm_directory_size(rdev);
pd_entries = radeon_vm_num_pdes(rdev);
pts_size = pd_entries * sizeof(struct radeon_vm_pt);
vm->page_tables = kzalloc(pts_size, GFP_KERNEL);
if (vm->page_tables == NULL) {
DRM_ERROR("Cannot allocate memory for page table array\n");
return -ENOMEM;
}
r = radeon_bo_create(rdev, pd_size, align, true,
RADEON_GEM_DOMAIN_VRAM, NULL,
&vm->page_directory);
if (r)
return r;
r = radeon_vm_clear_bo(rdev, vm->page_directory);
if (r) {
radeon_bo_unref(&vm->page_directory);
vm->page_directory = NULL;
return r;
}
return 0;
}
void radeon_vm_fini(struct radeon_device *rdev, struct radeon_vm *vm)
{
struct radeon_bo_va *bo_va, *tmp;
int i, r;
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
list_for_each_entry_safe(bo_va, tmp, &vm->freed, vm_status)
kfree(bo_va);
for (i = 0; i < radeon_vm_num_pdes(rdev); i++)
radeon_bo_unref(&vm->page_tables[i].bo);
kfree(vm->page_tables);
radeon_bo_unref(&vm->page_directory);
radeon_fence_unref(&vm->fence);
radeon_fence_unref(&vm->last_flush);
radeon_fence_unref(&vm->last_id_use);
mutex_destroy(&vm->mutex);
}
