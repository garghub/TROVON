static int amdgpu_ih_ring_alloc(struct amdgpu_device *adev)
{
int r;
if (adev->irq.ih.ring_obj == NULL) {
r = amdgpu_bo_create(adev, adev->irq.ih.ring_size,
PAGE_SIZE, true,
AMDGPU_GEM_DOMAIN_GTT, 0,
NULL, NULL, &adev->irq.ih.ring_obj);
if (r) {
DRM_ERROR("amdgpu: failed to create ih ring buffer (%d).\n", r);
return r;
}
r = amdgpu_bo_reserve(adev->irq.ih.ring_obj, false);
if (unlikely(r != 0))
return r;
r = amdgpu_bo_pin(adev->irq.ih.ring_obj,
AMDGPU_GEM_DOMAIN_GTT,
&adev->irq.ih.gpu_addr);
if (r) {
amdgpu_bo_unreserve(adev->irq.ih.ring_obj);
DRM_ERROR("amdgpu: failed to pin ih ring buffer (%d).\n", r);
return r;
}
r = amdgpu_bo_kmap(adev->irq.ih.ring_obj,
(void **)&adev->irq.ih.ring);
amdgpu_bo_unreserve(adev->irq.ih.ring_obj);
if (r) {
DRM_ERROR("amdgpu: failed to map ih ring buffer (%d).\n", r);
return r;
}
}
return 0;
}
int amdgpu_ih_ring_init(struct amdgpu_device *adev, unsigned ring_size,
bool use_bus_addr)
{
u32 rb_bufsz;
int r;
rb_bufsz = order_base_2(ring_size / 4);
ring_size = (1 << rb_bufsz) * 4;
adev->irq.ih.ring_size = ring_size;
adev->irq.ih.ptr_mask = adev->irq.ih.ring_size - 1;
adev->irq.ih.rptr = 0;
adev->irq.ih.use_bus_addr = use_bus_addr;
if (adev->irq.ih.use_bus_addr) {
if (!adev->irq.ih.ring) {
adev->irq.ih.ring = pci_alloc_consistent(adev->pdev,
adev->irq.ih.ring_size + 8,
&adev->irq.ih.rb_dma_addr);
if (adev->irq.ih.ring == NULL)
return -ENOMEM;
memset((void *)adev->irq.ih.ring, 0, adev->irq.ih.ring_size + 8);
adev->irq.ih.wptr_offs = (adev->irq.ih.ring_size / 4) + 0;
adev->irq.ih.rptr_offs = (adev->irq.ih.ring_size / 4) + 1;
}
return 0;
} else {
r = amdgpu_wb_get(adev, &adev->irq.ih.wptr_offs);
if (r) {
dev_err(adev->dev, "(%d) ih wptr_offs wb alloc failed\n", r);
return r;
}
r = amdgpu_wb_get(adev, &adev->irq.ih.rptr_offs);
if (r) {
amdgpu_wb_free(adev, adev->irq.ih.wptr_offs);
dev_err(adev->dev, "(%d) ih rptr_offs wb alloc failed\n", r);
return r;
}
return amdgpu_ih_ring_alloc(adev);
}
}
void amdgpu_ih_ring_fini(struct amdgpu_device *adev)
{
int r;
if (adev->irq.ih.use_bus_addr) {
if (adev->irq.ih.ring) {
pci_free_consistent(adev->pdev, adev->irq.ih.ring_size + 8,
(void *)adev->irq.ih.ring,
adev->irq.ih.rb_dma_addr);
adev->irq.ih.ring = NULL;
}
} else {
if (adev->irq.ih.ring_obj) {
r = amdgpu_bo_reserve(adev->irq.ih.ring_obj, false);
if (likely(r == 0)) {
amdgpu_bo_kunmap(adev->irq.ih.ring_obj);
amdgpu_bo_unpin(adev->irq.ih.ring_obj);
amdgpu_bo_unreserve(adev->irq.ih.ring_obj);
}
amdgpu_bo_unref(&adev->irq.ih.ring_obj);
adev->irq.ih.ring = NULL;
adev->irq.ih.ring_obj = NULL;
}
amdgpu_wb_free(adev, adev->irq.ih.wptr_offs);
amdgpu_wb_free(adev, adev->irq.ih.rptr_offs);
}
}
int amdgpu_ih_process(struct amdgpu_device *adev)
{
struct amdgpu_iv_entry entry;
u32 wptr;
if (!adev->irq.ih.enabled || adev->shutdown)
return IRQ_NONE;
wptr = amdgpu_ih_get_wptr(adev);
restart_ih:
if (atomic_xchg(&adev->irq.ih.lock, 1))
return IRQ_NONE;
DRM_DEBUG("%s: rptr %d, wptr %d\n", __func__, adev->irq.ih.rptr, wptr);
rmb();
while (adev->irq.ih.rptr != wptr) {
u32 ring_index = adev->irq.ih.rptr >> 2;
amdgpu_amdkfd_interrupt(adev,
(const void *) &adev->irq.ih.ring[ring_index]);
entry.iv_entry = (const uint32_t *)
&adev->irq.ih.ring[ring_index];
amdgpu_ih_decode_iv(adev, &entry);
adev->irq.ih.rptr &= adev->irq.ih.ptr_mask;
amdgpu_irq_dispatch(adev, &entry);
}
amdgpu_ih_set_rptr(adev);
atomic_set(&adev->irq.ih.lock, 0);
wptr = amdgpu_ih_get_wptr(adev);
if (wptr != adev->irq.ih.rptr)
goto restart_ih;
return IRQ_HANDLED;
}
