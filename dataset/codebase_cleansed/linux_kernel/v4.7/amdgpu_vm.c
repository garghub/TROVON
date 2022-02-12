static unsigned amdgpu_vm_num_pdes(struct amdgpu_device *adev)
{
return adev->vm_manager.max_pfn >> amdgpu_vm_block_size;
}
static unsigned amdgpu_vm_directory_size(struct amdgpu_device *adev)
{
return AMDGPU_GPU_PAGE_ALIGN(amdgpu_vm_num_pdes(adev) * 8);
}
void amdgpu_vm_get_pd_bo(struct amdgpu_vm *vm,
struct list_head *validated,
struct amdgpu_bo_list_entry *entry)
{
entry->robj = vm->page_directory;
entry->priority = 0;
entry->tv.bo = &vm->page_directory->tbo;
entry->tv.shared = true;
entry->user_pages = NULL;
list_add(&entry->tv.head, validated);
}
void amdgpu_vm_get_pt_bos(struct amdgpu_vm *vm, struct list_head *duplicates)
{
unsigned i;
for (i = 0; i <= vm->max_pde_used; ++i) {
struct amdgpu_bo_list_entry *entry = &vm->page_tables[i].entry;
if (!entry->robj)
continue;
list_add(&entry->tv.head, duplicates);
}
}
void amdgpu_vm_move_pt_bos_in_lru(struct amdgpu_device *adev,
struct amdgpu_vm *vm)
{
struct ttm_bo_global *glob = adev->mman.bdev.glob;
unsigned i;
spin_lock(&glob->lru_lock);
for (i = 0; i <= vm->max_pde_used; ++i) {
struct amdgpu_bo_list_entry *entry = &vm->page_tables[i].entry;
if (!entry->robj)
continue;
ttm_bo_move_to_lru_tail(&entry->robj->tbo);
}
spin_unlock(&glob->lru_lock);
}
int amdgpu_vm_grab_id(struct amdgpu_vm *vm, struct amdgpu_ring *ring,
struct amdgpu_sync *sync, struct fence *fence,
unsigned *vm_id, uint64_t *vm_pd_addr)
{
uint64_t pd_addr = amdgpu_bo_gpu_offset(vm->page_directory);
struct amdgpu_device *adev = ring->adev;
struct fence *updates = sync->last_vm_update;
struct amdgpu_vm_id *id;
unsigned i = ring->idx;
int r;
mutex_lock(&adev->vm_manager.lock);
do {
struct fence *flushed;
id = vm->ids[i++];
if (i == AMDGPU_MAX_RINGS)
i = 0;
if (!id)
continue;
if (atomic64_read(&id->owner) != vm->client_id)
continue;
if (pd_addr != id->pd_gpu_addr)
continue;
if (id->last_user != ring &&
(!id->last_flush || !fence_is_signaled(id->last_flush)))
continue;
flushed = id->flushed_updates;
if (updates && (!flushed || fence_is_later(updates, flushed)))
continue;
if (id->last_user == ring) {
r = amdgpu_sync_fence(ring->adev, sync,
id->first);
if (r)
goto error;
}
r = amdgpu_sync_fence(ring->adev, &id->active, fence);
if (r)
goto error;
list_move_tail(&id->list, &adev->vm_manager.ids_lru);
vm->ids[ring->idx] = id;
*vm_id = id - adev->vm_manager.ids;
*vm_pd_addr = AMDGPU_VM_NO_FLUSH;
trace_amdgpu_vm_grab_id(vm, ring->idx, *vm_id, *vm_pd_addr);
mutex_unlock(&adev->vm_manager.lock);
return 0;
} while (i != ring->idx);
id = list_first_entry(&adev->vm_manager.ids_lru,
struct amdgpu_vm_id,
list);
if (!amdgpu_sync_is_idle(&id->active)) {
struct list_head *head = &adev->vm_manager.ids_lru;
struct amdgpu_vm_id *tmp;
list_for_each_entry_safe(id, tmp, &adev->vm_manager.ids_lru,
list) {
if (amdgpu_sync_is_idle(&id->active)) {
list_move(&id->list, head);
head = &id->list;
}
}
id = list_first_entry(&adev->vm_manager.ids_lru,
struct amdgpu_vm_id,
list);
}
r = amdgpu_sync_cycle_fences(sync, &id->active, fence);
if (r)
goto error;
fence_put(id->first);
id->first = fence_get(fence);
fence_put(id->last_flush);
id->last_flush = NULL;
fence_put(id->flushed_updates);
id->flushed_updates = fence_get(updates);
id->pd_gpu_addr = pd_addr;
list_move_tail(&id->list, &adev->vm_manager.ids_lru);
id->last_user = ring;
atomic64_set(&id->owner, vm->client_id);
vm->ids[ring->idx] = id;
*vm_id = id - adev->vm_manager.ids;
*vm_pd_addr = pd_addr;
trace_amdgpu_vm_grab_id(vm, ring->idx, *vm_id, *vm_pd_addr);
error:
mutex_unlock(&adev->vm_manager.lock);
return r;
}
int amdgpu_vm_flush(struct amdgpu_ring *ring,
unsigned vm_id, uint64_t pd_addr,
uint32_t gds_base, uint32_t gds_size,
uint32_t gws_base, uint32_t gws_size,
uint32_t oa_base, uint32_t oa_size)
{
struct amdgpu_device *adev = ring->adev;
struct amdgpu_vm_id *id = &adev->vm_manager.ids[vm_id];
bool gds_switch_needed = ring->funcs->emit_gds_switch && (
id->gds_base != gds_base ||
id->gds_size != gds_size ||
id->gws_base != gws_base ||
id->gws_size != gws_size ||
id->oa_base != oa_base ||
id->oa_size != oa_size);
int r;
if (ring->funcs->emit_pipeline_sync && (
pd_addr != AMDGPU_VM_NO_FLUSH || gds_switch_needed ||
ring->type == AMDGPU_RING_TYPE_COMPUTE))
amdgpu_ring_emit_pipeline_sync(ring);
if (ring->funcs->emit_vm_flush &&
pd_addr != AMDGPU_VM_NO_FLUSH) {
struct fence *fence;
trace_amdgpu_vm_flush(pd_addr, ring->idx, vm_id);
amdgpu_ring_emit_vm_flush(ring, vm_id, pd_addr);
mutex_lock(&adev->vm_manager.lock);
if ((id->pd_gpu_addr == pd_addr) && (id->last_user == ring)) {
r = amdgpu_fence_emit(ring, &fence);
if (r) {
mutex_unlock(&adev->vm_manager.lock);
return r;
}
fence_put(id->last_flush);
id->last_flush = fence;
}
mutex_unlock(&adev->vm_manager.lock);
}
if (gds_switch_needed) {
id->gds_base = gds_base;
id->gds_size = gds_size;
id->gws_base = gws_base;
id->gws_size = gws_size;
id->oa_base = oa_base;
id->oa_size = oa_size;
amdgpu_ring_emit_gds_switch(ring, vm_id,
gds_base, gds_size,
gws_base, gws_size,
oa_base, oa_size);
}
return 0;
}
void amdgpu_vm_reset_id(struct amdgpu_device *adev, unsigned vm_id)
{
struct amdgpu_vm_id *id = &adev->vm_manager.ids[vm_id];
id->gds_base = 0;
id->gds_size = 0;
id->gws_base = 0;
id->gws_size = 0;
id->oa_base = 0;
id->oa_size = 0;
}
struct amdgpu_bo_va *amdgpu_vm_bo_find(struct amdgpu_vm *vm,
struct amdgpu_bo *bo)
{
struct amdgpu_bo_va *bo_va;
list_for_each_entry(bo_va, &bo->va, bo_list) {
if (bo_va->vm == vm) {
return bo_va;
}
}
return NULL;
}
static void amdgpu_vm_update_pages(struct amdgpu_device *adev,
struct amdgpu_vm_update_params
*vm_update_params,
uint64_t pe, uint64_t addr,
unsigned count, uint32_t incr,
uint32_t flags)
{
trace_amdgpu_vm_set_page(pe, addr, count, incr, flags);
if (vm_update_params->src) {
amdgpu_vm_copy_pte(adev, vm_update_params->ib,
pe, (vm_update_params->src + (addr >> 12) * 8), count);
} else if (vm_update_params->pages_addr) {
amdgpu_vm_write_pte(adev, vm_update_params->ib,
vm_update_params->pages_addr,
pe, addr, count, incr, flags);
} else if (count < 3) {
amdgpu_vm_write_pte(adev, vm_update_params->ib, NULL, pe, addr,
count, incr, flags);
} else {
amdgpu_vm_set_pte_pde(adev, vm_update_params->ib, pe, addr,
count, incr, flags);
}
}
static int amdgpu_vm_clear_bo(struct amdgpu_device *adev,
struct amdgpu_vm *vm,
struct amdgpu_bo *bo)
{
struct amdgpu_ring *ring;
struct fence *fence = NULL;
struct amdgpu_job *job;
struct amdgpu_vm_update_params vm_update_params;
unsigned entries;
uint64_t addr;
int r;
memset(&vm_update_params, 0, sizeof(vm_update_params));
ring = container_of(vm->entity.sched, struct amdgpu_ring, sched);
r = reservation_object_reserve_shared(bo->tbo.resv);
if (r)
return r;
r = ttm_bo_validate(&bo->tbo, &bo->placement, true, false);
if (r)
goto error;
addr = amdgpu_bo_gpu_offset(bo);
entries = amdgpu_bo_size(bo) / 8;
r = amdgpu_job_alloc_with_ib(adev, 64, &job);
if (r)
goto error;
vm_update_params.ib = &job->ibs[0];
amdgpu_vm_update_pages(adev, &vm_update_params, addr, 0, entries,
0, 0);
amdgpu_ring_pad_ib(ring, &job->ibs[0]);
WARN_ON(job->ibs[0].length_dw > 64);
r = amdgpu_job_submit(job, ring, &vm->entity,
AMDGPU_FENCE_OWNER_VM, &fence);
if (r)
goto error_free;
amdgpu_bo_fence(bo, fence, true);
fence_put(fence);
return 0;
error_free:
amdgpu_job_free(job);
error:
return r;
}
uint64_t amdgpu_vm_map_gart(const dma_addr_t *pages_addr, uint64_t addr)
{
uint64_t result;
if (pages_addr) {
result = pages_addr[addr >> PAGE_SHIFT];
result |= addr & (~PAGE_MASK);
} else {
result = addr;
}
result &= 0xFFFFFFFFFFFFF000ULL;
return result;
}
int amdgpu_vm_update_page_directory(struct amdgpu_device *adev,
struct amdgpu_vm *vm)
{
struct amdgpu_ring *ring;
struct amdgpu_bo *pd = vm->page_directory;
uint64_t pd_addr = amdgpu_bo_gpu_offset(pd);
uint32_t incr = AMDGPU_VM_PTE_COUNT * 8;
uint64_t last_pde = ~0, last_pt = ~0;
unsigned count = 0, pt_idx, ndw;
struct amdgpu_job *job;
struct amdgpu_vm_update_params vm_update_params;
struct fence *fence = NULL;
int r;
memset(&vm_update_params, 0, sizeof(vm_update_params));
ring = container_of(vm->entity.sched, struct amdgpu_ring, sched);
ndw = 64;
ndw += vm->max_pde_used * 6;
r = amdgpu_job_alloc_with_ib(adev, ndw * 4, &job);
if (r)
return r;
vm_update_params.ib = &job->ibs[0];
for (pt_idx = 0; pt_idx <= vm->max_pde_used; ++pt_idx) {
struct amdgpu_bo *bo = vm->page_tables[pt_idx].entry.robj;
uint64_t pde, pt;
if (bo == NULL)
continue;
pt = amdgpu_bo_gpu_offset(bo);
if (vm->page_tables[pt_idx].addr == pt)
continue;
vm->page_tables[pt_idx].addr = pt;
pde = pd_addr + pt_idx * 8;
if (((last_pde + 8 * count) != pde) ||
((last_pt + incr * count) != pt)) {
if (count) {
amdgpu_vm_update_pages(adev, &vm_update_params,
last_pde, last_pt,
count, incr,
AMDGPU_PTE_VALID);
}
count = 1;
last_pde = pde;
last_pt = pt;
} else {
++count;
}
}
if (count)
amdgpu_vm_update_pages(adev, &vm_update_params,
last_pde, last_pt,
count, incr, AMDGPU_PTE_VALID);
if (vm_update_params.ib->length_dw != 0) {
amdgpu_ring_pad_ib(ring, vm_update_params.ib);
amdgpu_sync_resv(adev, &job->sync, pd->tbo.resv,
AMDGPU_FENCE_OWNER_VM);
WARN_ON(vm_update_params.ib->length_dw > ndw);
r = amdgpu_job_submit(job, ring, &vm->entity,
AMDGPU_FENCE_OWNER_VM, &fence);
if (r)
goto error_free;
amdgpu_bo_fence(pd, fence, true);
fence_put(vm->page_directory_fence);
vm->page_directory_fence = fence_get(fence);
fence_put(fence);
} else {
amdgpu_job_free(job);
}
return 0;
error_free:
amdgpu_job_free(job);
return r;
}
static void amdgpu_vm_frag_ptes(struct amdgpu_device *adev,
struct amdgpu_vm_update_params
*vm_update_params,
uint64_t pe_start, uint64_t pe_end,
uint64_t addr, uint32_t flags)
{
uint64_t frag_flags = AMDGPU_PTE_FRAG_64KB;
uint64_t frag_align = 0x80;
uint64_t frag_start = ALIGN(pe_start, frag_align);
uint64_t frag_end = pe_end & ~(frag_align - 1);
unsigned count;
if (pe_start == pe_end)
return;
if (vm_update_params->src || vm_update_params->pages_addr ||
!(flags & AMDGPU_PTE_VALID) || (frag_start >= frag_end)) {
count = (pe_end - pe_start) / 8;
amdgpu_vm_update_pages(adev, vm_update_params, pe_start,
addr, count, AMDGPU_GPU_PAGE_SIZE,
flags);
return;
}
if (pe_start != frag_start) {
count = (frag_start - pe_start) / 8;
amdgpu_vm_update_pages(adev, vm_update_params, pe_start, addr,
count, AMDGPU_GPU_PAGE_SIZE, flags);
addr += AMDGPU_GPU_PAGE_SIZE * count;
}
count = (frag_end - frag_start) / 8;
amdgpu_vm_update_pages(adev, vm_update_params, frag_start, addr, count,
AMDGPU_GPU_PAGE_SIZE, flags | frag_flags);
if (frag_end != pe_end) {
addr += AMDGPU_GPU_PAGE_SIZE * count;
count = (pe_end - frag_end) / 8;
amdgpu_vm_update_pages(adev, vm_update_params, frag_end, addr,
count, AMDGPU_GPU_PAGE_SIZE, flags);
}
}
static void amdgpu_vm_update_ptes(struct amdgpu_device *adev,
struct amdgpu_vm_update_params
*vm_update_params,
struct amdgpu_vm *vm,
uint64_t start, uint64_t end,
uint64_t dst, uint32_t flags)
{
const uint64_t mask = AMDGPU_VM_PTE_COUNT - 1;
uint64_t last_pe_start = ~0, last_pe_end = ~0, last_dst = ~0;
uint64_t addr;
for (addr = start; addr < end; ) {
uint64_t pt_idx = addr >> amdgpu_vm_block_size;
struct amdgpu_bo *pt = vm->page_tables[pt_idx].entry.robj;
unsigned nptes;
uint64_t pe_start;
if ((addr & ~mask) == (end & ~mask))
nptes = end - addr;
else
nptes = AMDGPU_VM_PTE_COUNT - (addr & mask);
pe_start = amdgpu_bo_gpu_offset(pt);
pe_start += (addr & mask) * 8;
if (last_pe_end != pe_start) {
amdgpu_vm_frag_ptes(adev, vm_update_params,
last_pe_start, last_pe_end,
last_dst, flags);
last_pe_start = pe_start;
last_pe_end = pe_start + 8 * nptes;
last_dst = dst;
} else {
last_pe_end += 8 * nptes;
}
addr += nptes;
dst += nptes * AMDGPU_GPU_PAGE_SIZE;
}
amdgpu_vm_frag_ptes(adev, vm_update_params, last_pe_start,
last_pe_end, last_dst, flags);
}
static int amdgpu_vm_bo_update_mapping(struct amdgpu_device *adev,
uint64_t src,
dma_addr_t *pages_addr,
struct amdgpu_vm *vm,
uint64_t start, uint64_t last,
uint32_t flags, uint64_t addr,
struct fence **fence)
{
struct amdgpu_ring *ring;
void *owner = AMDGPU_FENCE_OWNER_VM;
unsigned nptes, ncmds, ndw;
struct amdgpu_job *job;
struct amdgpu_vm_update_params vm_update_params;
struct fence *f = NULL;
int r;
ring = container_of(vm->entity.sched, struct amdgpu_ring, sched);
memset(&vm_update_params, 0, sizeof(vm_update_params));
vm_update_params.src = src;
vm_update_params.pages_addr = pages_addr;
if (!(flags & AMDGPU_PTE_VALID))
owner = AMDGPU_FENCE_OWNER_UNDEFINED;
nptes = last - start + 1;
ncmds = (nptes >> min(amdgpu_vm_block_size, 11)) + 1;
ndw = 64;
if (vm_update_params.src) {
ndw += ncmds * 7;
} else if (vm_update_params.pages_addr) {
ndw += ncmds * 4;
ndw += nptes * 2;
} else {
ndw += ncmds * 10;
ndw += 2 * 10;
}
r = amdgpu_job_alloc_with_ib(adev, ndw * 4, &job);
if (r)
return r;
vm_update_params.ib = &job->ibs[0];
r = amdgpu_sync_resv(adev, &job->sync, vm->page_directory->tbo.resv,
owner);
if (r)
goto error_free;
r = reservation_object_reserve_shared(vm->page_directory->tbo.resv);
if (r)
goto error_free;
amdgpu_vm_update_ptes(adev, &vm_update_params, vm, start,
last + 1, addr, flags);
amdgpu_ring_pad_ib(ring, vm_update_params.ib);
WARN_ON(vm_update_params.ib->length_dw > ndw);
r = amdgpu_job_submit(job, ring, &vm->entity,
AMDGPU_FENCE_OWNER_VM, &f);
if (r)
goto error_free;
amdgpu_bo_fence(vm->page_directory, f, true);
if (fence) {
fence_put(*fence);
*fence = fence_get(f);
}
fence_put(f);
return 0;
error_free:
amdgpu_job_free(job);
return r;
}
static int amdgpu_vm_bo_split_mapping(struct amdgpu_device *adev,
uint32_t gtt_flags,
dma_addr_t *pages_addr,
struct amdgpu_vm *vm,
struct amdgpu_bo_va_mapping *mapping,
uint32_t flags, uint64_t addr,
struct fence **fence)
{
const uint64_t max_size = 64ULL * 1024ULL * 1024ULL / AMDGPU_GPU_PAGE_SIZE;
uint64_t src = 0, start = mapping->it.start;
int r;
if (!(mapping->flags & AMDGPU_PTE_READABLE))
flags &= ~AMDGPU_PTE_READABLE;
if (!(mapping->flags & AMDGPU_PTE_WRITEABLE))
flags &= ~AMDGPU_PTE_WRITEABLE;
trace_amdgpu_vm_bo_update(mapping);
if (pages_addr) {
if (flags == gtt_flags)
src = adev->gart.table_addr + (addr >> 12) * 8;
addr = 0;
}
addr += mapping->offset;
if (!pages_addr || src)
return amdgpu_vm_bo_update_mapping(adev, src, pages_addr, vm,
start, mapping->it.last,
flags, addr, fence);
while (start != mapping->it.last + 1) {
uint64_t last;
last = min((uint64_t)mapping->it.last, start + max_size - 1);
r = amdgpu_vm_bo_update_mapping(adev, src, pages_addr, vm,
start, last, flags, addr,
fence);
if (r)
return r;
start = last + 1;
addr += max_size * AMDGPU_GPU_PAGE_SIZE;
}
return 0;
}
int amdgpu_vm_bo_update(struct amdgpu_device *adev,
struct amdgpu_bo_va *bo_va,
struct ttm_mem_reg *mem)
{
struct amdgpu_vm *vm = bo_va->vm;
struct amdgpu_bo_va_mapping *mapping;
dma_addr_t *pages_addr = NULL;
uint32_t gtt_flags, flags;
uint64_t addr;
int r;
if (mem) {
struct ttm_dma_tt *ttm;
addr = (u64)mem->start << PAGE_SHIFT;
switch (mem->mem_type) {
case TTM_PL_TT:
ttm = container_of(bo_va->bo->tbo.ttm, struct
ttm_dma_tt, ttm);
pages_addr = ttm->dma_address;
break;
case TTM_PL_VRAM:
addr += adev->vm_manager.vram_base_offset;
break;
default:
break;
}
} else {
addr = 0;
}
flags = amdgpu_ttm_tt_pte_flags(adev, bo_va->bo->tbo.ttm, mem);
gtt_flags = (adev == bo_va->bo->adev) ? flags : 0;
spin_lock(&vm->status_lock);
if (!list_empty(&bo_va->vm_status))
list_splice_init(&bo_va->valids, &bo_va->invalids);
spin_unlock(&vm->status_lock);
list_for_each_entry(mapping, &bo_va->invalids, list) {
r = amdgpu_vm_bo_split_mapping(adev, gtt_flags, pages_addr, vm,
mapping, flags, addr,
&bo_va->last_pt_update);
if (r)
return r;
}
if (trace_amdgpu_vm_bo_mapping_enabled()) {
list_for_each_entry(mapping, &bo_va->valids, list)
trace_amdgpu_vm_bo_mapping(mapping);
list_for_each_entry(mapping, &bo_va->invalids, list)
trace_amdgpu_vm_bo_mapping(mapping);
}
spin_lock(&vm->status_lock);
list_splice_init(&bo_va->invalids, &bo_va->valids);
list_del_init(&bo_va->vm_status);
if (!mem)
list_add(&bo_va->vm_status, &vm->cleared);
spin_unlock(&vm->status_lock);
return 0;
}
int amdgpu_vm_clear_freed(struct amdgpu_device *adev,
struct amdgpu_vm *vm)
{
struct amdgpu_bo_va_mapping *mapping;
int r;
while (!list_empty(&vm->freed)) {
mapping = list_first_entry(&vm->freed,
struct amdgpu_bo_va_mapping, list);
list_del(&mapping->list);
r = amdgpu_vm_bo_split_mapping(adev, 0, NULL, vm, mapping,
0, 0, NULL);
kfree(mapping);
if (r)
return r;
}
return 0;
}
int amdgpu_vm_clear_invalids(struct amdgpu_device *adev,
struct amdgpu_vm *vm, struct amdgpu_sync *sync)
{
struct amdgpu_bo_va *bo_va = NULL;
int r = 0;
spin_lock(&vm->status_lock);
while (!list_empty(&vm->invalidated)) {
bo_va = list_first_entry(&vm->invalidated,
struct amdgpu_bo_va, vm_status);
spin_unlock(&vm->status_lock);
r = amdgpu_vm_bo_update(adev, bo_va, NULL);
if (r)
return r;
spin_lock(&vm->status_lock);
}
spin_unlock(&vm->status_lock);
if (bo_va)
r = amdgpu_sync_fence(adev, sync, bo_va->last_pt_update);
return r;
}
struct amdgpu_bo_va *amdgpu_vm_bo_add(struct amdgpu_device *adev,
struct amdgpu_vm *vm,
struct amdgpu_bo *bo)
{
struct amdgpu_bo_va *bo_va;
bo_va = kzalloc(sizeof(struct amdgpu_bo_va), GFP_KERNEL);
if (bo_va == NULL) {
return NULL;
}
bo_va->vm = vm;
bo_va->bo = bo;
bo_va->ref_count = 1;
INIT_LIST_HEAD(&bo_va->bo_list);
INIT_LIST_HEAD(&bo_va->valids);
INIT_LIST_HEAD(&bo_va->invalids);
INIT_LIST_HEAD(&bo_va->vm_status);
list_add_tail(&bo_va->bo_list, &bo->va);
return bo_va;
}
int amdgpu_vm_bo_map(struct amdgpu_device *adev,
struct amdgpu_bo_va *bo_va,
uint64_t saddr, uint64_t offset,
uint64_t size, uint32_t flags)
{
struct amdgpu_bo_va_mapping *mapping;
struct amdgpu_vm *vm = bo_va->vm;
struct interval_tree_node *it;
unsigned last_pfn, pt_idx;
uint64_t eaddr;
int r;
if (saddr & AMDGPU_GPU_PAGE_MASK || offset & AMDGPU_GPU_PAGE_MASK ||
size == 0 || size & AMDGPU_GPU_PAGE_MASK)
return -EINVAL;
eaddr = saddr + size - 1;
if ((saddr >= eaddr) || (offset + size > amdgpu_bo_size(bo_va->bo)))
return -EINVAL;
last_pfn = eaddr / AMDGPU_GPU_PAGE_SIZE;
if (last_pfn >= adev->vm_manager.max_pfn) {
dev_err(adev->dev, "va above limit (0x%08X >= 0x%08X)\n",
last_pfn, adev->vm_manager.max_pfn);
return -EINVAL;
}
saddr /= AMDGPU_GPU_PAGE_SIZE;
eaddr /= AMDGPU_GPU_PAGE_SIZE;
it = interval_tree_iter_first(&vm->va, saddr, eaddr);
if (it) {
struct amdgpu_bo_va_mapping *tmp;
tmp = container_of(it, struct amdgpu_bo_va_mapping, it);
dev_err(adev->dev, "bo %p va 0x%010Lx-0x%010Lx conflict with "
"0x%010lx-0x%010lx\n", bo_va->bo, saddr, eaddr,
tmp->it.start, tmp->it.last + 1);
r = -EINVAL;
goto error;
}
mapping = kmalloc(sizeof(*mapping), GFP_KERNEL);
if (!mapping) {
r = -ENOMEM;
goto error;
}
INIT_LIST_HEAD(&mapping->list);
mapping->it.start = saddr;
mapping->it.last = eaddr;
mapping->offset = offset;
mapping->flags = flags;
list_add(&mapping->list, &bo_va->invalids);
interval_tree_insert(&mapping->it, &vm->va);
saddr >>= amdgpu_vm_block_size;
eaddr >>= amdgpu_vm_block_size;
BUG_ON(eaddr >= amdgpu_vm_num_pdes(adev));
if (eaddr > vm->max_pde_used)
vm->max_pde_used = eaddr;
for (pt_idx = saddr; pt_idx <= eaddr; ++pt_idx) {
struct reservation_object *resv = vm->page_directory->tbo.resv;
struct amdgpu_bo_list_entry *entry;
struct amdgpu_bo *pt;
entry = &vm->page_tables[pt_idx].entry;
if (entry->robj)
continue;
r = amdgpu_bo_create(adev, AMDGPU_VM_PTE_COUNT * 8,
AMDGPU_GPU_PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_NO_CPU_ACCESS,
NULL, resv, &pt);
if (r)
goto error_free;
pt->parent = amdgpu_bo_ref(vm->page_directory);
r = amdgpu_vm_clear_bo(adev, vm, pt);
if (r) {
amdgpu_bo_unref(&pt);
goto error_free;
}
entry->robj = pt;
entry->priority = 0;
entry->tv.bo = &entry->robj->tbo;
entry->tv.shared = true;
entry->user_pages = NULL;
vm->page_tables[pt_idx].addr = 0;
}
return 0;
error_free:
list_del(&mapping->list);
interval_tree_remove(&mapping->it, &vm->va);
trace_amdgpu_vm_bo_unmap(bo_va, mapping);
kfree(mapping);
error:
return r;
}
int amdgpu_vm_bo_unmap(struct amdgpu_device *adev,
struct amdgpu_bo_va *bo_va,
uint64_t saddr)
{
struct amdgpu_bo_va_mapping *mapping;
struct amdgpu_vm *vm = bo_va->vm;
bool valid = true;
saddr /= AMDGPU_GPU_PAGE_SIZE;
list_for_each_entry(mapping, &bo_va->valids, list) {
if (mapping->it.start == saddr)
break;
}
if (&mapping->list == &bo_va->valids) {
valid = false;
list_for_each_entry(mapping, &bo_va->invalids, list) {
if (mapping->it.start == saddr)
break;
}
if (&mapping->list == &bo_va->invalids)
return -ENOENT;
}
list_del(&mapping->list);
interval_tree_remove(&mapping->it, &vm->va);
trace_amdgpu_vm_bo_unmap(bo_va, mapping);
if (valid)
list_add(&mapping->list, &vm->freed);
else
kfree(mapping);
return 0;
}
void amdgpu_vm_bo_rmv(struct amdgpu_device *adev,
struct amdgpu_bo_va *bo_va)
{
struct amdgpu_bo_va_mapping *mapping, *next;
struct amdgpu_vm *vm = bo_va->vm;
list_del(&bo_va->bo_list);
spin_lock(&vm->status_lock);
list_del(&bo_va->vm_status);
spin_unlock(&vm->status_lock);
list_for_each_entry_safe(mapping, next, &bo_va->valids, list) {
list_del(&mapping->list);
interval_tree_remove(&mapping->it, &vm->va);
trace_amdgpu_vm_bo_unmap(bo_va, mapping);
list_add(&mapping->list, &vm->freed);
}
list_for_each_entry_safe(mapping, next, &bo_va->invalids, list) {
list_del(&mapping->list);
interval_tree_remove(&mapping->it, &vm->va);
kfree(mapping);
}
fence_put(bo_va->last_pt_update);
kfree(bo_va);
}
void amdgpu_vm_bo_invalidate(struct amdgpu_device *adev,
struct amdgpu_bo *bo)
{
struct amdgpu_bo_va *bo_va;
list_for_each_entry(bo_va, &bo->va, bo_list) {
spin_lock(&bo_va->vm->status_lock);
if (list_empty(&bo_va->vm_status))
list_add(&bo_va->vm_status, &bo_va->vm->invalidated);
spin_unlock(&bo_va->vm->status_lock);
}
}
int amdgpu_vm_init(struct amdgpu_device *adev, struct amdgpu_vm *vm)
{
const unsigned align = min(AMDGPU_VM_PTB_ALIGN_SIZE,
AMDGPU_VM_PTE_COUNT * 8);
unsigned pd_size, pd_entries;
unsigned ring_instance;
struct amdgpu_ring *ring;
struct amd_sched_rq *rq;
int i, r;
for (i = 0; i < AMDGPU_MAX_RINGS; ++i)
vm->ids[i] = NULL;
vm->va = RB_ROOT;
vm->client_id = atomic64_inc_return(&adev->vm_manager.client_counter);
spin_lock_init(&vm->status_lock);
INIT_LIST_HEAD(&vm->invalidated);
INIT_LIST_HEAD(&vm->cleared);
INIT_LIST_HEAD(&vm->freed);
pd_size = amdgpu_vm_directory_size(adev);
pd_entries = amdgpu_vm_num_pdes(adev);
vm->page_tables = drm_calloc_large(pd_entries, sizeof(struct amdgpu_vm_pt));
if (vm->page_tables == NULL) {
DRM_ERROR("Cannot allocate memory for page table array\n");
return -ENOMEM;
}
ring_instance = atomic_inc_return(&adev->vm_manager.vm_pte_next_ring);
ring_instance %= adev->vm_manager.vm_pte_num_rings;
ring = adev->vm_manager.vm_pte_rings[ring_instance];
rq = &ring->sched.sched_rq[AMD_SCHED_PRIORITY_KERNEL];
r = amd_sched_entity_init(&ring->sched, &vm->entity,
rq, amdgpu_sched_jobs);
if (r)
return r;
vm->page_directory_fence = NULL;
r = amdgpu_bo_create(adev, pd_size, align, true,
AMDGPU_GEM_DOMAIN_VRAM,
AMDGPU_GEM_CREATE_NO_CPU_ACCESS,
NULL, NULL, &vm->page_directory);
if (r)
goto error_free_sched_entity;
r = amdgpu_bo_reserve(vm->page_directory, false);
if (r)
goto error_free_page_directory;
r = amdgpu_vm_clear_bo(adev, vm, vm->page_directory);
amdgpu_bo_unreserve(vm->page_directory);
if (r)
goto error_free_page_directory;
return 0;
error_free_page_directory:
amdgpu_bo_unref(&vm->page_directory);
vm->page_directory = NULL;
error_free_sched_entity:
amd_sched_entity_fini(&ring->sched, &vm->entity);
return r;
}
void amdgpu_vm_fini(struct amdgpu_device *adev, struct amdgpu_vm *vm)
{
struct amdgpu_bo_va_mapping *mapping, *tmp;
int i;
amd_sched_entity_fini(vm->entity.sched, &vm->entity);
if (!RB_EMPTY_ROOT(&vm->va)) {
dev_err(adev->dev, "still active bo inside vm\n");
}
rbtree_postorder_for_each_entry_safe(mapping, tmp, &vm->va, it.rb) {
list_del(&mapping->list);
interval_tree_remove(&mapping->it, &vm->va);
kfree(mapping);
}
list_for_each_entry_safe(mapping, tmp, &vm->freed, list) {
list_del(&mapping->list);
kfree(mapping);
}
for (i = 0; i < amdgpu_vm_num_pdes(adev); i++)
amdgpu_bo_unref(&vm->page_tables[i].entry.robj);
drm_free_large(vm->page_tables);
amdgpu_bo_unref(&vm->page_directory);
fence_put(vm->page_directory_fence);
}
void amdgpu_vm_manager_init(struct amdgpu_device *adev)
{
unsigned i;
INIT_LIST_HEAD(&adev->vm_manager.ids_lru);
for (i = 1; i < adev->vm_manager.num_ids; ++i) {
amdgpu_vm_reset_id(adev, i);
amdgpu_sync_create(&adev->vm_manager.ids[i].active);
list_add_tail(&adev->vm_manager.ids[i].list,
&adev->vm_manager.ids_lru);
}
atomic_set(&adev->vm_manager.vm_pte_next_ring, 0);
atomic64_set(&adev->vm_manager.client_counter, 0);
}
void amdgpu_vm_manager_fini(struct amdgpu_device *adev)
{
unsigned i;
for (i = 0; i < AMDGPU_NUM_VM; ++i) {
struct amdgpu_vm_id *id = &adev->vm_manager.ids[i];
fence_put(adev->vm_manager.ids[i].first);
amdgpu_sync_free(&adev->vm_manager.ids[i].active);
fence_put(id->flushed_updates);
}
}
