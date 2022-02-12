static bool a3xx_me_init(struct msm_gpu *gpu)
{
struct msm_ringbuffer *ring = gpu->rb;
OUT_PKT3(ring, CP_ME_INIT, 17);
OUT_RING(ring, 0x000003f7);
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000080);
OUT_RING(ring, 0x00000100);
OUT_RING(ring, 0x00000180);
OUT_RING(ring, 0x00006600);
OUT_RING(ring, 0x00000150);
OUT_RING(ring, 0x0000014e);
OUT_RING(ring, 0x00000154);
OUT_RING(ring, 0x00000001);
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000000);
OUT_RING(ring, 0x00000000);
gpu->funcs->flush(gpu);
return gpu->funcs->idle(gpu);
}
static int a3xx_hw_init(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a3xx_gpu *a3xx_gpu = to_a3xx_gpu(adreno_gpu);
uint32_t *ptr, len;
int i, ret;
DBG("%s", gpu->name);
if (adreno_is_a305(adreno_gpu)) {
gpu_write(gpu, REG_A3XX_VBIF_IN_RD_LIM_CONF0, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_IN_RD_LIM_CONF1, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_OUT_RD_LIM_CONF0, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_OUT_WR_LIM_CONF0, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_DDR_OUT_MAX_BURST, 0x0000303);
gpu_write(gpu, REG_A3XX_VBIF_IN_WR_LIM_CONF0, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_IN_WR_LIM_CONF1, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_GATE_OFF_WRREQ_EN, 0x0000ff);
gpu_write(gpu, REG_A3XX_VBIF_ARB_CTL, 0x00000030);
gpu_write(gpu, REG_A3XX_VBIF_OUT_AXI_AOOO_EN, 0x0000003c);
gpu_write(gpu, REG_A3XX_VBIF_OUT_AXI_AOOO, 0x003c003c);
} else if (adreno_is_a306(adreno_gpu)) {
gpu_write(gpu, REG_A3XX_VBIF_ROUND_ROBIN_QOS_ARB, 0x0003);
gpu_write(gpu, REG_A3XX_VBIF_OUT_RD_LIM_CONF0, 0x0000000a);
gpu_write(gpu, REG_A3XX_VBIF_OUT_WR_LIM_CONF0, 0x0000000a);
} else if (adreno_is_a320(adreno_gpu)) {
gpu_write(gpu, REG_A3XX_VBIF_IN_RD_LIM_CONF0, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_IN_RD_LIM_CONF1, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_OUT_RD_LIM_CONF0, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_OUT_WR_LIM_CONF0, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_DDR_OUT_MAX_BURST, 0x0000303);
gpu_write(gpu, REG_A3XX_VBIF_IN_WR_LIM_CONF0, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_IN_WR_LIM_CONF1, 0x10101010);
gpu_write(gpu, REG_A3XX_VBIF_GATE_OFF_WRREQ_EN, 0x0000ff);
gpu_write(gpu, REG_A3XX_VBIF_ARB_CTL, 0x00000030);
gpu_write(gpu, REG_A3XX_VBIF_OUT_AXI_AOOO_EN, 0x0000003c);
gpu_write(gpu, REG_A3XX_VBIF_OUT_AXI_AOOO, 0x003c003c);
gpu_write(gpu, REG_A3XX_VBIF_ABIT_SORT, 0x000000ff);
gpu_write(gpu, REG_A3XX_VBIF_ABIT_SORT_CONF, 0x000000a4);
} else if (adreno_is_a330v2(adreno_gpu)) {
gpu_write(gpu, REG_A3XX_VBIF_ABIT_SORT, 0x0001003f);
gpu_write(gpu, REG_A3XX_VBIF_ABIT_SORT_CONF, 0x000000a4);
gpu_write(gpu, REG_A3XX_VBIF_GATE_OFF_WRREQ_EN, 0x00003f);
gpu_write(gpu, REG_A3XX_VBIF_DDR_OUT_MAX_BURST, 0x0000303);
gpu_write(gpu, REG_A3XX_VBIF_ROUND_ROBIN_QOS_ARB, 0x0003);
} else if (adreno_is_a330(adreno_gpu)) {
gpu_write(gpu, REG_A3XX_VBIF_IN_RD_LIM_CONF0, 0x18181818);
gpu_write(gpu, REG_A3XX_VBIF_IN_RD_LIM_CONF1, 0x18181818);
gpu_write(gpu, REG_A3XX_VBIF_OUT_RD_LIM_CONF0, 0x18181818);
gpu_write(gpu, REG_A3XX_VBIF_OUT_WR_LIM_CONF0, 0x18181818);
gpu_write(gpu, REG_A3XX_VBIF_DDR_OUT_MAX_BURST, 0x0000303);
gpu_write(gpu, REG_A3XX_VBIF_IN_WR_LIM_CONF0, 0x18181818);
gpu_write(gpu, REG_A3XX_VBIF_IN_WR_LIM_CONF1, 0x18181818);
gpu_write(gpu, REG_A3XX_VBIF_GATE_OFF_WRREQ_EN, 0x00003f);
gpu_write(gpu, REG_A3XX_VBIF_ARB_CTL, 0x00000030);
gpu_write(gpu, REG_A3XX_VBIF_ROUND_ROBIN_QOS_ARB, 0x0001);
gpu_write(gpu, REG_A3XX_VBIF_OUT_AXI_AOOO_EN, 0x0000003f);
gpu_write(gpu, REG_A3XX_VBIF_OUT_AXI_AOOO, 0x003f003f);
gpu_write(gpu, REG_A3XX_VBIF_ABIT_SORT, 0x0001003f);
gpu_write(gpu, REG_A3XX_VBIF_ABIT_SORT_CONF, 0x000000a4);
gpu_write(gpu, REG_A3XX_VBIF_CLKON, 0x00000001);
} else {
BUG();
}
gpu_write(gpu, REG_A3XX_RBBM_GPU_BUSY_MASKED, 0xffffffff);
gpu_write(gpu, REG_A3XX_RBBM_SP_HYST_CNT, 0x10);
gpu_write(gpu, REG_A3XX_RBBM_WAIT_IDLE_CLOCKS_CTL, 0x10);
gpu_write(gpu, REG_A3XX_RBBM_AHB_CTL0, 0x00000001);
gpu_write(gpu, REG_A3XX_RBBM_AHB_CTL1, 0xa6ffffff);
gpu_write(gpu, REG_A3XX_RBBM_RBBM_CTL, 0x00030000);
gpu_write(gpu, REG_A3XX_RBBM_INTERFACE_HANG_INT_CTL, 0x00010fff);
gpu_write(gpu, REG_A3XX_UCHE_CACHE_MODE_CONTROL_REG, 0x00000001);
if (adreno_is_a306(adreno_gpu))
gpu_write(gpu, REG_A3XX_RBBM_CLOCK_CTL, 0xaaaaaaaa);
else if (adreno_is_a320(adreno_gpu))
gpu_write(gpu, REG_A3XX_RBBM_CLOCK_CTL, 0xbfffffff);
else if (adreno_is_a330v2(adreno_gpu))
gpu_write(gpu, REG_A3XX_RBBM_CLOCK_CTL, 0xaaaaaaaa);
else if (adreno_is_a330(adreno_gpu))
gpu_write(gpu, REG_A3XX_RBBM_CLOCK_CTL, 0xbffcffff);
if (adreno_is_a330v2(adreno_gpu))
gpu_write(gpu, REG_A3XX_RBBM_GPR0_CTL, 0x05515455);
else if (adreno_is_a330(adreno_gpu))
gpu_write(gpu, REG_A3XX_RBBM_GPR0_CTL, 0x00000000);
if (a3xx_gpu->ocmem_hdl) {
gpu_write(gpu, REG_A3XX_RB_GMEM_BASE_ADDR,
(unsigned int)(a3xx_gpu->ocmem_base >> 14));
}
gpu_write(gpu, REG_A3XX_RBBM_PERFCTR_CTL, 0x01);
for (i = 0; i < gpu->num_perfcntrs; i++) {
const struct msm_gpu_perfcntr *perfcntr = &gpu->perfcntrs[i];
gpu_write(gpu, perfcntr->select_reg, perfcntr->select_val);
}
gpu_write(gpu, REG_A3XX_RBBM_INT_0_MASK, A3XX_INT0_MASK);
ret = adreno_hw_init(gpu);
if (ret)
return ret;
gpu_write(gpu, REG_A3XX_CP_PROTECT_CTRL, 0x00000007);
gpu_write(gpu, REG_A3XX_CP_PROTECT(0), 0x63000040);
gpu_write(gpu, REG_A3XX_CP_PROTECT(1), 0x62000080);
gpu_write(gpu, REG_A3XX_CP_PROTECT(2), 0x600000cc);
gpu_write(gpu, REG_A3XX_CP_PROTECT(3), 0x60000108);
gpu_write(gpu, REG_A3XX_CP_PROTECT(4), 0x64000140);
gpu_write(gpu, REG_A3XX_CP_PROTECT(5), 0x66000400);
gpu_write(gpu, REG_A3XX_CP_PROTECT(6), 0x65000700);
gpu_write(gpu, REG_A3XX_CP_PROTECT(7), 0x610007d8);
gpu_write(gpu, REG_A3XX_CP_PROTECT(8), 0x620007e0);
gpu_write(gpu, REG_A3XX_CP_PROTECT(9), 0x61001178);
gpu_write(gpu, REG_A3XX_CP_PROTECT(10), 0x64001180);
gpu_write(gpu, REG_A3XX_CP_PROTECT(11), 0x60003300);
gpu_write(gpu, REG_A3XX_CP_PROTECT(12), 0x6b00c000);
ptr = (uint32_t *)(adreno_gpu->pm4->data);
len = adreno_gpu->pm4->size / 4;
DBG("loading PM4 ucode version: %x", ptr[1]);
gpu_write(gpu, REG_AXXX_CP_DEBUG,
AXXX_CP_DEBUG_DYNAMIC_CLK_DISABLE |
AXXX_CP_DEBUG_MIU_128BIT_WRITE_ENABLE);
gpu_write(gpu, REG_AXXX_CP_ME_RAM_WADDR, 0);
for (i = 1; i < len; i++)
gpu_write(gpu, REG_AXXX_CP_ME_RAM_DATA, ptr[i]);
ptr = (uint32_t *)(adreno_gpu->pfp->data);
len = adreno_gpu->pfp->size / 4;
DBG("loading PFP ucode version: %x", ptr[5]);
gpu_write(gpu, REG_A3XX_CP_PFP_UCODE_ADDR, 0);
for (i = 1; i < len; i++)
gpu_write(gpu, REG_A3XX_CP_PFP_UCODE_DATA, ptr[i]);
if (adreno_is_a305(adreno_gpu) || adreno_is_a306(adreno_gpu) ||
adreno_is_a320(adreno_gpu)) {
gpu_write(gpu, REG_AXXX_CP_QUEUE_THRESHOLDS,
AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB1_START(2) |
AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB2_START(6) |
AXXX_CP_QUEUE_THRESHOLDS_CSQ_ST_START(14));
} else if (adreno_is_a330(adreno_gpu)) {
gpu_write(gpu, REG_AXXX_CP_QUEUE_THRESHOLDS, 0x003e2008);
}
gpu_write(gpu, REG_AXXX_CP_ME_CNTL, 0);
return a3xx_me_init(gpu) ? 0 : -EINVAL;
}
static void a3xx_recover(struct msm_gpu *gpu)
{
int i;
adreno_dump_info(gpu);
for (i = 0; i < 8; i++) {
printk("CP_SCRATCH_REG%d: %u\n", i,
gpu_read(gpu, REG_AXXX_CP_SCRATCH_REG0 + i));
}
if (hang_debug)
a3xx_dump(gpu);
gpu_write(gpu, REG_A3XX_RBBM_SW_RESET_CMD, 1);
gpu_read(gpu, REG_A3XX_RBBM_SW_RESET_CMD);
gpu_write(gpu, REG_A3XX_RBBM_SW_RESET_CMD, 0);
adreno_recover(gpu);
}
static void a3xx_destroy(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a3xx_gpu *a3xx_gpu = to_a3xx_gpu(adreno_gpu);
DBG("%s", gpu->name);
adreno_gpu_cleanup(adreno_gpu);
#ifdef CONFIG_MSM_OCMEM
if (a3xx_gpu->ocmem_base)
ocmem_free(OCMEM_GRAPHICS, a3xx_gpu->ocmem_hdl);
#endif
kfree(a3xx_gpu);
}
static bool a3xx_idle(struct msm_gpu *gpu)
{
if (!adreno_idle(gpu))
return false;
if (spin_until(!(gpu_read(gpu, REG_A3XX_RBBM_STATUS) &
A3XX_RBBM_STATUS_GPU_BUSY))) {
DRM_ERROR("%s: timeout waiting for GPU to idle!\n", gpu->name);
return false;
}
return true;
}
static irqreturn_t a3xx_irq(struct msm_gpu *gpu)
{
uint32_t status;
status = gpu_read(gpu, REG_A3XX_RBBM_INT_0_STATUS);
DBG("%s: %08x", gpu->name, status);
gpu_write(gpu, REG_A3XX_RBBM_INT_CLEAR_CMD, status);
msm_gpu_retire(gpu);
return IRQ_HANDLED;
}
static void a3xx_show(struct msm_gpu *gpu, struct seq_file *m)
{
gpu->funcs->pm_resume(gpu);
seq_printf(m, "status: %08x\n",
gpu_read(gpu, REG_A3XX_RBBM_STATUS));
gpu->funcs->pm_suspend(gpu);
adreno_show(gpu, m);
}
static void a3xx_dump(struct msm_gpu *gpu)
{
printk("status: %08x\n",
gpu_read(gpu, REG_A3XX_RBBM_STATUS));
adreno_dump(gpu);
}
struct msm_gpu *a3xx_gpu_init(struct drm_device *dev)
{
struct a3xx_gpu *a3xx_gpu = NULL;
struct adreno_gpu *adreno_gpu;
struct msm_gpu *gpu;
struct msm_drm_private *priv = dev->dev_private;
struct platform_device *pdev = priv->gpu_pdev;
int ret;
if (!pdev) {
dev_err(dev->dev, "no a3xx device\n");
ret = -ENXIO;
goto fail;
}
a3xx_gpu = kzalloc(sizeof(*a3xx_gpu), GFP_KERNEL);
if (!a3xx_gpu) {
ret = -ENOMEM;
goto fail;
}
adreno_gpu = &a3xx_gpu->base;
gpu = &adreno_gpu->base;
a3xx_gpu->pdev = pdev;
gpu->perfcntrs = perfcntrs;
gpu->num_perfcntrs = ARRAY_SIZE(perfcntrs);
adreno_gpu->registers = a3xx_registers;
adreno_gpu->reg_offsets = a3xx_register_offsets;
ret = adreno_gpu_init(dev, pdev, adreno_gpu, &funcs);
if (ret)
goto fail;
if (adreno_is_a330(adreno_gpu)) {
#ifdef CONFIG_MSM_OCMEM
struct ocmem_buf *ocmem_hdl =
ocmem_allocate(OCMEM_GRAPHICS, adreno_gpu->gmem);
a3xx_gpu->ocmem_hdl = ocmem_hdl;
a3xx_gpu->ocmem_base = ocmem_hdl->addr;
adreno_gpu->gmem = ocmem_hdl->len;
DBG("using %dK of OCMEM at 0x%08x", adreno_gpu->gmem / 1024,
a3xx_gpu->ocmem_base);
#endif
}
if (!gpu->aspace) {
dev_err(dev->dev, "No memory protection without IOMMU\n");
ret = -ENXIO;
goto fail;
}
return gpu;
fail:
if (a3xx_gpu)
a3xx_destroy(&a3xx_gpu->base.base);
return ERR_PTR(ret);
}
