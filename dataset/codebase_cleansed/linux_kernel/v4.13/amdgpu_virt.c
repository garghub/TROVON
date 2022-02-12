int amdgpu_allocate_static_csa(struct amdgpu_device *adev)
{
int r;
void *ptr;
r = amdgpu_bo_create_kernel(adev, AMDGPU_CSA_SIZE, PAGE_SIZE,
AMDGPU_GEM_DOMAIN_VRAM, &adev->virt.csa_obj,
&adev->virt.csa_vmid0_addr, &ptr);
if (r)
return r;
memset(ptr, 0, AMDGPU_CSA_SIZE);
return 0;
}
int amdgpu_map_static_csa(struct amdgpu_device *adev, struct amdgpu_vm *vm)
{
int r;
struct amdgpu_bo_va *bo_va;
struct ww_acquire_ctx ticket;
struct list_head list;
struct amdgpu_bo_list_entry pd;
struct ttm_validate_buffer csa_tv;
INIT_LIST_HEAD(&list);
INIT_LIST_HEAD(&csa_tv.head);
csa_tv.bo = &adev->virt.csa_obj->tbo;
csa_tv.shared = true;
list_add(&csa_tv.head, &list);
amdgpu_vm_get_pd_bo(vm, &list, &pd);
r = ttm_eu_reserve_buffers(&ticket, &list, true, NULL);
if (r) {
DRM_ERROR("failed to reserve CSA,PD BOs: err=%d\n", r);
return r;
}
bo_va = amdgpu_vm_bo_add(adev, vm, adev->virt.csa_obj);
if (!bo_va) {
ttm_eu_backoff_reservation(&ticket, &list);
DRM_ERROR("failed to create bo_va for static CSA\n");
return -ENOMEM;
}
r = amdgpu_vm_alloc_pts(adev, bo_va->vm, AMDGPU_CSA_VADDR,
AMDGPU_CSA_SIZE);
if (r) {
DRM_ERROR("failed to allocate pts for static CSA, err=%d\n", r);
amdgpu_vm_bo_rmv(adev, bo_va);
ttm_eu_backoff_reservation(&ticket, &list);
return r;
}
r = amdgpu_vm_bo_map(adev, bo_va, AMDGPU_CSA_VADDR, 0,AMDGPU_CSA_SIZE,
AMDGPU_PTE_READABLE | AMDGPU_PTE_WRITEABLE |
AMDGPU_PTE_EXECUTABLE);
if (r) {
DRM_ERROR("failed to do bo_map on static CSA, err=%d\n", r);
amdgpu_vm_bo_rmv(adev, bo_va);
ttm_eu_backoff_reservation(&ticket, &list);
return r;
}
vm->csa_bo_va = bo_va;
ttm_eu_backoff_reservation(&ticket, &list);
return 0;
}
void amdgpu_virt_init_setting(struct amdgpu_device *adev)
{
adev->mode_info.num_crtc = 1;
adev->enable_virtual_display = true;
adev->cg_flags = 0;
adev->pg_flags = 0;
mutex_init(&adev->virt.lock_reset);
}
uint32_t amdgpu_virt_kiq_rreg(struct amdgpu_device *adev, uint32_t reg)
{
signed long r;
uint32_t val;
struct dma_fence *f;
struct amdgpu_kiq *kiq = &adev->gfx.kiq;
struct amdgpu_ring *ring = &kiq->ring;
BUG_ON(!ring->funcs->emit_rreg);
mutex_lock(&kiq->ring_mutex);
amdgpu_ring_alloc(ring, 32);
amdgpu_ring_emit_rreg(ring, reg);
amdgpu_fence_emit(ring, &f);
amdgpu_ring_commit(ring);
mutex_unlock(&kiq->ring_mutex);
r = dma_fence_wait_timeout(f, false, msecs_to_jiffies(MAX_KIQ_REG_WAIT));
dma_fence_put(f);
if (r < 1) {
DRM_ERROR("wait for kiq fence error: %ld.\n", r);
return ~0;
}
val = adev->wb.wb[adev->virt.reg_val_offs];
return val;
}
void amdgpu_virt_kiq_wreg(struct amdgpu_device *adev, uint32_t reg, uint32_t v)
{
signed long r;
struct dma_fence *f;
struct amdgpu_kiq *kiq = &adev->gfx.kiq;
struct amdgpu_ring *ring = &kiq->ring;
BUG_ON(!ring->funcs->emit_wreg);
mutex_lock(&kiq->ring_mutex);
amdgpu_ring_alloc(ring, 32);
amdgpu_ring_emit_wreg(ring, reg, v);
amdgpu_fence_emit(ring, &f);
amdgpu_ring_commit(ring);
mutex_unlock(&kiq->ring_mutex);
r = dma_fence_wait_timeout(f, false, msecs_to_jiffies(MAX_KIQ_REG_WAIT));
if (r < 1)
DRM_ERROR("wait for kiq fence error: %ld.\n", r);
dma_fence_put(f);
}
int amdgpu_virt_request_full_gpu(struct amdgpu_device *adev, bool init)
{
struct amdgpu_virt *virt = &adev->virt;
int r;
if (virt->ops && virt->ops->req_full_gpu) {
r = virt->ops->req_full_gpu(adev, init);
if (r)
return r;
adev->virt.caps &= ~AMDGPU_SRIOV_CAPS_RUNTIME;
}
return 0;
}
int amdgpu_virt_release_full_gpu(struct amdgpu_device *adev, bool init)
{
struct amdgpu_virt *virt = &adev->virt;
int r;
if (virt->ops && virt->ops->rel_full_gpu) {
r = virt->ops->rel_full_gpu(adev, init);
if (r)
return r;
adev->virt.caps |= AMDGPU_SRIOV_CAPS_RUNTIME;
}
return 0;
}
int amdgpu_virt_reset_gpu(struct amdgpu_device *adev)
{
struct amdgpu_virt *virt = &adev->virt;
int r;
if (virt->ops && virt->ops->reset_gpu) {
r = virt->ops->reset_gpu(adev);
if (r)
return r;
adev->virt.caps &= ~AMDGPU_SRIOV_CAPS_RUNTIME;
}
return 0;
}
int amdgpu_virt_alloc_mm_table(struct amdgpu_device *adev)
{
int r;
if (!amdgpu_sriov_vf(adev) || adev->virt.mm_table.gpu_addr)
return 0;
r = amdgpu_bo_create_kernel(adev, PAGE_SIZE, PAGE_SIZE,
AMDGPU_GEM_DOMAIN_VRAM,
&adev->virt.mm_table.bo,
&adev->virt.mm_table.gpu_addr,
(void *)&adev->virt.mm_table.cpu_addr);
if (r) {
DRM_ERROR("failed to alloc mm table and error = %d.\n", r);
return r;
}
memset((void *)adev->virt.mm_table.cpu_addr, 0, PAGE_SIZE);
DRM_INFO("MM table gpu addr = 0x%llx, cpu addr = %p.\n",
adev->virt.mm_table.gpu_addr,
adev->virt.mm_table.cpu_addr);
return 0;
}
void amdgpu_virt_free_mm_table(struct amdgpu_device *adev)
{
if (!amdgpu_sriov_vf(adev) || !adev->virt.mm_table.gpu_addr)
return;
amdgpu_bo_free_kernel(&adev->virt.mm_table.bo,
&adev->virt.mm_table.gpu_addr,
(void *)&adev->virt.mm_table.cpu_addr);
adev->virt.mm_table.gpu_addr = 0;
}
