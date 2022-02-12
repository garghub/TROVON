static void tonga_ih_enable_interrupts(struct amdgpu_device *adev)
{
u32 ih_rb_cntl = RREG32(mmIH_RB_CNTL);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RB_ENABLE, 1);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, ENABLE_INTR, 1);
WREG32(mmIH_RB_CNTL, ih_rb_cntl);
adev->irq.ih.enabled = true;
}
static void tonga_ih_disable_interrupts(struct amdgpu_device *adev)
{
u32 ih_rb_cntl = RREG32(mmIH_RB_CNTL);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RB_ENABLE, 0);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, ENABLE_INTR, 0);
WREG32(mmIH_RB_CNTL, ih_rb_cntl);
WREG32(mmIH_RB_RPTR, 0);
WREG32(mmIH_RB_WPTR, 0);
adev->irq.ih.enabled = false;
adev->irq.ih.rptr = 0;
}
static int tonga_ih_irq_init(struct amdgpu_device *adev)
{
int ret = 0;
int rb_bufsz;
u32 interrupt_cntl, ih_rb_cntl, ih_doorbell_rtpr;
u64 wptr_off;
tonga_ih_disable_interrupts(adev);
WREG32(mmINTERRUPT_CNTL2, adev->dummy_page.addr >> 8);
interrupt_cntl = RREG32(mmINTERRUPT_CNTL);
interrupt_cntl = REG_SET_FIELD(interrupt_cntl, INTERRUPT_CNTL, IH_DUMMY_RD_OVERRIDE, 0);
interrupt_cntl = REG_SET_FIELD(interrupt_cntl, INTERRUPT_CNTL, IH_REQ_NONSNOOP_EN, 0);
WREG32(mmINTERRUPT_CNTL, interrupt_cntl);
if (adev->irq.ih.use_bus_addr)
WREG32(mmIH_RB_BASE, adev->irq.ih.rb_dma_addr >> 8);
else
WREG32(mmIH_RB_BASE, adev->irq.ih.gpu_addr >> 8);
rb_bufsz = order_base_2(adev->irq.ih.ring_size / 4);
ih_rb_cntl = REG_SET_FIELD(0, IH_RB_CNTL, WPTR_OVERFLOW_CLEAR, 1);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RB_SIZE, rb_bufsz);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, WPTR_WRITEBACK_ENABLE, 1);
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, MC_VMID, 0);
if (adev->irq.msi_enabled)
ih_rb_cntl = REG_SET_FIELD(ih_rb_cntl, IH_RB_CNTL, RPTR_REARM, 1);
WREG32(mmIH_RB_CNTL, ih_rb_cntl);
if (adev->irq.ih.use_bus_addr)
wptr_off = adev->irq.ih.rb_dma_addr + (adev->irq.ih.wptr_offs * 4);
else
wptr_off = adev->wb.gpu_addr + (adev->irq.ih.wptr_offs * 4);
WREG32(mmIH_RB_WPTR_ADDR_LO, lower_32_bits(wptr_off));
WREG32(mmIH_RB_WPTR_ADDR_HI, upper_32_bits(wptr_off) & 0xFF);
WREG32(mmIH_RB_RPTR, 0);
WREG32(mmIH_RB_WPTR, 0);
ih_doorbell_rtpr = RREG32(mmIH_DOORBELL_RPTR);
if (adev->irq.ih.use_doorbell) {
ih_doorbell_rtpr = REG_SET_FIELD(ih_doorbell_rtpr, IH_DOORBELL_RPTR,
OFFSET, adev->irq.ih.doorbell_index);
ih_doorbell_rtpr = REG_SET_FIELD(ih_doorbell_rtpr, IH_DOORBELL_RPTR,
ENABLE, 1);
} else {
ih_doorbell_rtpr = REG_SET_FIELD(ih_doorbell_rtpr, IH_DOORBELL_RPTR,
ENABLE, 0);
}
WREG32(mmIH_DOORBELL_RPTR, ih_doorbell_rtpr);
pci_set_master(adev->pdev);
tonga_ih_enable_interrupts(adev);
return ret;
}
static void tonga_ih_irq_disable(struct amdgpu_device *adev)
{
tonga_ih_disable_interrupts(adev);
mdelay(1);
}
static u32 tonga_ih_get_wptr(struct amdgpu_device *adev)
{
u32 wptr, tmp;
if (adev->irq.ih.use_bus_addr)
wptr = le32_to_cpu(adev->irq.ih.ring[adev->irq.ih.wptr_offs]);
else
wptr = le32_to_cpu(adev->wb.wb[adev->irq.ih.wptr_offs]);
if (REG_GET_FIELD(wptr, IH_RB_WPTR, RB_OVERFLOW)) {
wptr = REG_SET_FIELD(wptr, IH_RB_WPTR, RB_OVERFLOW, 0);
dev_warn(adev->dev, "IH ring buffer overflow (0x%08X, 0x%08X, 0x%08X)\n",
wptr, adev->irq.ih.rptr, (wptr + 16) & adev->irq.ih.ptr_mask);
adev->irq.ih.rptr = (wptr + 16) & adev->irq.ih.ptr_mask;
tmp = RREG32(mmIH_RB_CNTL);
tmp = REG_SET_FIELD(tmp, IH_RB_CNTL, WPTR_OVERFLOW_CLEAR, 1);
WREG32(mmIH_RB_CNTL, tmp);
}
return (wptr & adev->irq.ih.ptr_mask);
}
static void tonga_ih_decode_iv(struct amdgpu_device *adev,
struct amdgpu_iv_entry *entry)
{
u32 ring_index = adev->irq.ih.rptr >> 2;
uint32_t dw[4];
dw[0] = le32_to_cpu(adev->irq.ih.ring[ring_index + 0]);
dw[1] = le32_to_cpu(adev->irq.ih.ring[ring_index + 1]);
dw[2] = le32_to_cpu(adev->irq.ih.ring[ring_index + 2]);
dw[3] = le32_to_cpu(adev->irq.ih.ring[ring_index + 3]);
entry->src_id = dw[0] & 0xff;
entry->src_data = dw[1] & 0xfffffff;
entry->ring_id = dw[2] & 0xff;
entry->vm_id = (dw[2] >> 8) & 0xff;
entry->pas_id = (dw[2] >> 16) & 0xffff;
adev->irq.ih.rptr += 16;
}
static void tonga_ih_set_rptr(struct amdgpu_device *adev)
{
if (adev->irq.ih.use_doorbell) {
if (adev->irq.ih.use_bus_addr)
adev->irq.ih.ring[adev->irq.ih.rptr_offs] = adev->irq.ih.rptr;
else
adev->wb.wb[adev->irq.ih.rptr_offs] = adev->irq.ih.rptr;
WDOORBELL32(adev->irq.ih.doorbell_index, adev->irq.ih.rptr);
} else {
WREG32(mmIH_RB_RPTR, adev->irq.ih.rptr);
}
}
static int tonga_ih_early_init(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
tonga_ih_set_interrupt_funcs(adev);
return 0;
}
static int tonga_ih_sw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = amdgpu_ih_ring_init(adev, 4 * 1024, true);
if (r)
return r;
adev->irq.ih.use_doorbell = true;
adev->irq.ih.doorbell_index = AMDGPU_DOORBELL_IH;
r = amdgpu_irq_init(adev);
return r;
}
static int tonga_ih_sw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
amdgpu_irq_fini(adev);
amdgpu_ih_ring_fini(adev);
return 0;
}
static int tonga_ih_hw_init(void *handle)
{
int r;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
r = tonga_ih_irq_init(adev);
if (r)
return r;
return 0;
}
static int tonga_ih_hw_fini(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
tonga_ih_irq_disable(adev);
return 0;
}
static int tonga_ih_suspend(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return tonga_ih_hw_fini(adev);
}
static int tonga_ih_resume(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
return tonga_ih_hw_init(adev);
}
static bool tonga_ih_is_idle(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 tmp = RREG32(mmSRBM_STATUS);
if (REG_GET_FIELD(tmp, SRBM_STATUS, IH_BUSY))
return false;
return true;
}
static int tonga_ih_wait_for_idle(void *handle)
{
unsigned i;
u32 tmp;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
for (i = 0; i < adev->usec_timeout; i++) {
tmp = RREG32(mmSRBM_STATUS);
if (!REG_GET_FIELD(tmp, SRBM_STATUS, IH_BUSY))
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static void tonga_ih_print_status(void *handle)
{
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
dev_info(adev->dev, "TONGA IH registers\n");
dev_info(adev->dev, " SRBM_STATUS=0x%08X\n",
RREG32(mmSRBM_STATUS));
dev_info(adev->dev, " SRBM_STATUS2=0x%08X\n",
RREG32(mmSRBM_STATUS2));
dev_info(adev->dev, " INTERRUPT_CNTL=0x%08X\n",
RREG32(mmINTERRUPT_CNTL));
dev_info(adev->dev, " INTERRUPT_CNTL2=0x%08X\n",
RREG32(mmINTERRUPT_CNTL2));
dev_info(adev->dev, " IH_CNTL=0x%08X\n",
RREG32(mmIH_CNTL));
dev_info(adev->dev, " IH_RB_CNTL=0x%08X\n",
RREG32(mmIH_RB_CNTL));
dev_info(adev->dev, " IH_RB_BASE=0x%08X\n",
RREG32(mmIH_RB_BASE));
dev_info(adev->dev, " IH_RB_WPTR_ADDR_LO=0x%08X\n",
RREG32(mmIH_RB_WPTR_ADDR_LO));
dev_info(adev->dev, " IH_RB_WPTR_ADDR_HI=0x%08X\n",
RREG32(mmIH_RB_WPTR_ADDR_HI));
dev_info(adev->dev, " IH_RB_RPTR=0x%08X\n",
RREG32(mmIH_RB_RPTR));
dev_info(adev->dev, " IH_RB_WPTR=0x%08X\n",
RREG32(mmIH_RB_WPTR));
}
static int tonga_ih_soft_reset(void *handle)
{
u32 srbm_soft_reset = 0;
struct amdgpu_device *adev = (struct amdgpu_device *)handle;
u32 tmp = RREG32(mmSRBM_STATUS);
if (tmp & SRBM_STATUS__IH_BUSY_MASK)
srbm_soft_reset = REG_SET_FIELD(srbm_soft_reset, SRBM_SOFT_RESET,
SOFT_RESET_IH, 1);
if (srbm_soft_reset) {
tonga_ih_print_status(adev);
tmp = RREG32(mmSRBM_SOFT_RESET);
tmp |= srbm_soft_reset;
dev_info(adev->dev, "SRBM_SOFT_RESET=0x%08X\n", tmp);
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
udelay(50);
tmp &= ~srbm_soft_reset;
WREG32(mmSRBM_SOFT_RESET, tmp);
tmp = RREG32(mmSRBM_SOFT_RESET);
udelay(50);
tonga_ih_print_status(adev);
}
return 0;
}
static int tonga_ih_set_clockgating_state(void *handle,
enum amd_clockgating_state state)
{
return 0;
}
static int tonga_ih_set_powergating_state(void *handle,
enum amd_powergating_state state)
{
return 0;
}
static void tonga_ih_set_interrupt_funcs(struct amdgpu_device *adev)
{
if (adev->irq.ih_funcs == NULL)
adev->irq.ih_funcs = &tonga_ih_funcs;
}
