static void vega10_ih_enable_interrupts(struct amdgpu_device *adev)
{
u32 ih_rb_cntl = RREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL));
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RB_ENABLE, 1);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, ENABLE_INTR, 1);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL), ih_rb_cntl);
adev->irq.ih.enabled = true;
}
static void vega10_ih_disable_interrupts(struct amdgpu_device *adev)
{
u32 ih_rb_cntl = RREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL));
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RB_ENABLE, 0);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, ENABLE_INTR, 0);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL), ih_rb_cntl);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_RPTR), 0);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_WPTR), 0);
adev->irq.ih.enabled = false;
adev->irq.ih.rptr = 0;
}
static int vega10_ih_irq_init(struct amdgpu_device *adev)
{
int ret = 0;
int rb_bufsz;
u32 ih_rb_cntl, ih_doorbell_rtpr;
u32 tmp;
u64 wptr_off;
vega10_ih_disable_interrupts(adev);
nbio_v6_1_ih_control(adev);
ih_rb_cntl = RREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL));
if (adev->irq.ih.use_bus_addr) {
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_BASE), adev->irq.ih.rb_dma_addr >> 8);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_BASE_HI), ((u64)adev->irq.ih.rb_dma_addr >> 40) & 0xff);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, MC_SPACE, 1);
} else {
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_BASE), adev->irq.ih.gpu_addr >> 8);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_BASE_HI), (adev->irq.ih.gpu_addr >> 40) & 0xff);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, MC_SPACE, 4);
}
rb_bufsz = order_base_2(adev->irq.ih.ring_size / 4);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, WPTR_OVERFLOW_CLEAR, 1);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, WPTR_OVERFLOW_ENABLE, 1);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RB_SIZE, rb_bufsz);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, WPTR_WRITEBACK_ENABLE, 1);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, MC_SNOOP, 1);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, MC_RO, 0);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, MC_VMID, 0);
if (adev->irq.msi_enabled)
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RPTR_REARM, 1);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL), ih_rb_cntl);
if (adev->irq.ih.use_bus_addr)
wptr_off = adev->irq.ih.rb_dma_addr + (adev->irq.ih.wptr_offs * 4);
else
wptr_off = adev->wb.gpu_addr + (adev->irq.ih.wptr_offs * 4);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_WPTR_ADDR_LO), lower_32_bits(wptr_off));
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_WPTR_ADDR_HI), upper_32_bits(wptr_off) & 0xFF);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_RPTR), 0);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_WPTR), 0);
ih_doorbell_rtpr = RREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_DOORBELL_RPTR));
if (adev->irq.ih.use_doorbell) {
ih_doorbell_rtpr = REG_SET_FIELD(ih_doorbell_rtpr, IH_DOORBELL_RPTR,
OFFSET, adev->irq.ih.doorbell_index);
ih_doorbell_rtpr = REG_SET_FIELD(ih_doorbell_rtpr, IH_DOORBELL_RPTR,
ENABLE, 1);
} else {
ih_doorbell_rtpr = REG_SET_FIELD(ih_doorbell_rtpr, IH_DOORBELL_RPTR,
ENABLE, 0);
}
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_DOORBELL_RPTR), ih_doorbell_rtpr);
nbio_v6_1_ih_doorbell_range(adev, adev->irq.ih.use_doorbell, adev->irq.ih.doorbell_index);
tmp = RREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_STORM_CLIENT_LIST_CNTL));
tmp = REG_SET_FIELD(tmp, IH_STORM_CLIENT_LIST_CNTL,
CLIENT18_IS_STORM_CLIENT, 1);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_STORM_CLIENT_LIST_CNTL), tmp);
tmp = RREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_INT_FLOOD_CNTL));
tmp = REG_SET_FIELD(tmp, IH_INT_FLOOD_CNTL, FLOOD_CNTL_ENABLE, 1);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_INT_FLOOD_CNTL), tmp);
pci_set_master(adev->pdev);
vega10_ih_enable_interrupts(adev);
return ret;
}
static void vega10_ih_irq_disable(struct amdgpu_device *adev)
{
vega10_ih_disable_interrupts(adev);
mdelay(1);
}
static u32 vega10_ih_get_wptr(struct amdgpu_device *adev)
{
u32 wptr, tmp;
if (adev->irq.ih.use_bus_addr)
wptr = le32_to_cpu(adev->irq.ih.ring[adev->irq.ih.wptr_offs]);
else
wptr = le32_to_cpu(adev->wb.wb[adev->irq.ih.wptr_offs]);
if (REG_GET_FIELD(wptr, IH_RB_WPTR, RB_OVERFLOW)) {
wptr = REG_SET_FIELD(wptr, IH_RB_WPTR, RB_OVERFLOW, 0);
tmp = (wptr + 32) & adev->irq.ih.ptr_mask;
dev_warn(adev->dev, "IH ring buffer overflow (0x%08X, 0x%08X, 0x%08X)\n",
wptr, adev->irq.ih.rptr, tmp);
adev->irq.ih.rptr = tmp;
tmp = RREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL));
tmp = REG_SET_FIELD(tmp, IH_RB_CNTL, WPTR_OVERFLOW_CLEAR, 1);
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_CNTL), tmp);
}
return (wptr & adev->irq.ih.ptr_mask);
}
static void vega10_ih_decode_iv(struct amdgpu_device *adev,
struct amdgpu_iv_entry *entry)
{
u32 ring_index = adev->irq.ih.rptr >> 2;
uint32_t dw[8];
dw[0] = le32_to_cpu(adev->irq.ih.ring[ring_index + 0]);
dw[1] = le32_to_cpu(adev->irq.ih.ring[ring_index + 1]);
dw[2] = le32_to_cpu(adev->irq.ih.ring[ring_index + 2]);
dw[3] = le32_to_cpu(adev->irq.ih.ring[ring_index + 3]);
dw[4] = le32_to_cpu(adev->irq.ih.ring[ring_index + 4]);
dw[5] = le32_to_cpu(adev->irq.ih.ring[ring_index + 5]);
dw[6] = le32_to_cpu(adev->irq.ih.ring[ring_index + 6]);
dw[7] = le32_to_cpu(adev->irq.ih.ring[ring_index + 7]);
entry->client_id = dw[0] & 0xff;
entry->src_id = (dw[0] >> 8) & 0xff;
entry->ring_id = (dw[0] >> 16) & 0xff;
entry->vm_id = (dw[0] >> 24) & 0xf;
entry->vm_id_src = (dw[0] >> 31);
entry->timestamp = dw[1] | ((u64)(dw[2] & 0xffff) << 32);
entry->timestamp_src = dw[2] >> 31;
entry->pas_id = dw[3] & 0xffff;
entry->pasid_src = dw[3] >> 31;
entry->src_data[0] = dw[4];
entry->src_data[1] = dw[5];
entry->src_data[2] = dw[6];
entry->src_data[3] = dw[7];
adev->irq.ih.rptr += 32;
}
static void vega10_ih_set_rptr(struct amdgpu_device *adev)
{
if (adev->irq.ih.use_doorbell) {
if (adev->irq.ih.use_bus_addr)
adev->irq.ih.ring[adev->irq.ih.rptr_offs] = adev->irq.ih.rptr;
else
adev->wb.wb[adev->irq.ih.rptr_offs] = adev->irq.ih.rptr;
WDOORBELL32(adev->irq.ih.doorbell_index, adev->irq.ih.rptr);
} else {
WREG32(SOC15_REG_OFFSET(OSSSYS, 0, mmIH_RB_RPTR), adev->irq.ih.rptr);
}
}
static int vega10_ih_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
vega10_ih_set_interrupt_funcs(adev);
return 0;
}
static int vega10_ih_sw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_ih_ring_init(adev, 256 * 1024, true);
if (r)
return r;
adev->irq.ih.use_doorbell = true;
adev->irq.ih.doorbell_index = AMDGPU_DOORBELL64_IH << 1;
r = amdgpu_irq_init(adev);
return r;
}
static int vega10_ih_sw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
amdgpu_irq_fini(adev);
amdgpu_ih_ring_fini(adev);
return 0;
}
static int vega10_ih_hw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = vega10_ih_irq_init(adev);
if (r)
return r;
return 0;
}
static int vega10_ih_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
vega10_ih_irq_disable(adev);
return 0;
}
static int vega10_ih_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return vega10_ih_hw_fini(adev);
}
static int vega10_ih_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return vega10_ih_hw_init(adev);
}
static bool vega10_ih_is_idle(void *handle)
{
return true;
}
static int vega10_ih_wait_for_idle(void *handle)
{
return -ETIMEDOUT;
}
static int vega10_ih_soft_reset(void *handle)
{
return 0;
}
static int vega10_ih_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static int vega10_ih_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
static void vega10_ih_set_interrupt_funcs(struct amdgpu_device *adev)
{
if (adev->irq.ih_funcs == NULL)
adev->irq.ih_funcs = &vega10_ih_funcs;
}
