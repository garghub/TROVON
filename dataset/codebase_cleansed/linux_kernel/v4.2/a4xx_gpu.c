static void a4xx_enable_hwcg(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
unsigned int i;
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL_TP(i), 0x02222202);
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL2_TP(i), 0x00002222);
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_HYST_TP(i), 0x0E739CE7);
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_TP(i), 0x00111111);
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL_SP(i), 0x22222222);
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL2_SP(i), 0x00222222);
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_HYST_SP(i), 0x00000104);
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_SP(i), 0x00000081);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL_UCHE, 0x22222222);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL2_UCHE, 0x02222222);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL3_UCHE, 0x00000000);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL4_UCHE, 0x00000000);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_HYST_UCHE, 0x00004444);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_UCHE, 0x00001112);
for (i = 0; i < 4; i++)
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL_RB(i), 0x22222222);
for (i = 0; i < 4; i++) {
if (adreno_is_a420(adreno_gpu)) {
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL2_RB(i),
0x00002020);
} else {
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL2_RB(i),
0x00022020);
}
}
for (i = 0; i < 4; i++) {
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL_MARB_CCU(i),
0x00000922);
}
for (i = 0; i < 4; i++) {
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_HYST_RB_MARB_CCU(i),
0x00000000);
}
for (i = 0; i < 4; i++) {
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_RB_MARB_CCU_L1(i),
0x00000001);
}
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_MODE_GPC, 0x02222222);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_HYST_GPC, 0x04100104);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_GPC, 0x00022222);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL_COM_DCOM, 0x00000022);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_HYST_COM_DCOM, 0x0000010F);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_COM_DCOM, 0x00000022);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL_TSE_RAS_RBBM, 0x00222222);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_HYST_TSE_RAS_RBBM, 0x00004104);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_TSE_RAS_RBBM, 0x00000222);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL_HLSQ , 0x00000000);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_HYST_HLSQ, 0x00000000);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_HLSQ, 0x00020000);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL, 0xAAAAAAAA);
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_CTL2, 0);
}
static void a4xx_me_init(struct msm_gpu *gpu)
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
gpu->funcs->idle(gpu);
}
static int a4xx_hw_init(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a4xx_gpu *a4xx_gpu = to_a4xx_gpu(adreno_gpu);
uint32_t *ptr, len;
int i, ret;
if (adreno_is_a4xx(adreno_gpu)) {
gpu_write(gpu, REG_A4XX_VBIF_ABIT_SORT, 0x0001001F);
gpu_write(gpu, REG_A4XX_VBIF_ABIT_SORT_CONF, 0x000000A4);
gpu_write(gpu, REG_A4XX_VBIF_GATE_OFF_WRREQ_EN, 0x00000001);
gpu_write(gpu, REG_A4XX_VBIF_IN_RD_LIM_CONF0, 0x18181818);
gpu_write(gpu, REG_A4XX_VBIF_IN_RD_LIM_CONF1, 0x00000018);
gpu_write(gpu, REG_A4XX_VBIF_IN_WR_LIM_CONF0, 0x18181818);
gpu_write(gpu, REG_A4XX_VBIF_IN_WR_LIM_CONF1, 0x00000018);
gpu_write(gpu, REG_A4XX_VBIF_ROUND_ROBIN_QOS_ARB, 0x00000003);
} else {
BUG();
}
gpu_write(gpu, REG_A4XX_RBBM_GPU_BUSY_MASKED, 0xffffffff);
gpu_write(gpu, REG_A4XX_RBBM_SP_HYST_CNT, 0x10);
gpu_write(gpu, REG_A4XX_RBBM_WAIT_IDLE_CLOCKS_CTL, 0x10);
gpu_write(gpu, REG_A4XX_RBBM_AHB_CTL0, 0x00000001);
gpu_write(gpu, REG_A4XX_RBBM_AHB_CTL1, 0xa6ffffff);
gpu_write(gpu, REG_A4XX_RBBM_RBBM_CTL, 0x00000030);
gpu_write(gpu, REG_A4XX_RBBM_INTERFACE_HANG_INT_CTL,
(1 << 30) | 0xFFFF);
gpu_write(gpu, REG_A4XX_RB_GMEM_BASE_ADDR,
(unsigned int)(a4xx_gpu->ocmem_base >> 14));
gpu_write(gpu, REG_A4XX_RBBM_PERFCTR_CTL, 0x01);
gpu_write(gpu, REG_A4XX_UCHE_TRAP_BASE_LO, 0xffff0000);
gpu_write(gpu, REG_A4XX_UCHE_TRAP_BASE_HI, 0xffff0000);
gpu_write(gpu, REG_A4XX_CP_DEBUG, (1 << 25) |
(adreno_is_a420(adreno_gpu) ? (1 << 29) : 0));
a4xx_enable_hwcg(gpu);
if (adreno_is_a420(adreno_gpu)) {
unsigned int val;
val = gpu_read(gpu, REG_A4XX_RBBM_CLOCK_DELAY_HLSQ);
val &= ~A4XX_CGC_HLSQ_EARLY_CYC__MASK;
val |= 2 << A4XX_CGC_HLSQ_EARLY_CYC__SHIFT;
gpu_write(gpu, REG_A4XX_RBBM_CLOCK_DELAY_HLSQ, val);
}
ret = adreno_hw_init(gpu);
if (ret)
return ret;
gpu_write(gpu, REG_A4XX_CP_PROTECT_CTRL, 0x00000007);
gpu_write(gpu, REG_A4XX_CP_PROTECT(0), 0x62000010);
gpu_write(gpu, REG_A4XX_CP_PROTECT(1), 0x63000020);
gpu_write(gpu, REG_A4XX_CP_PROTECT(2), 0x64000040);
gpu_write(gpu, REG_A4XX_CP_PROTECT(3), 0x65000080);
gpu_write(gpu, REG_A4XX_CP_PROTECT(4), 0x66000100);
gpu_write(gpu, REG_A4XX_CP_PROTECT(5), 0x64000200);
gpu_write(gpu, REG_A4XX_CP_PROTECT(6), 0x67000800);
gpu_write(gpu, REG_A4XX_CP_PROTECT(7), 0x64001600);
gpu_write(gpu, REG_A4XX_CP_PROTECT(8), 0x60003300);
gpu_write(gpu, REG_A4XX_CP_PROTECT(9), 0x60003800);
gpu_write(gpu, REG_A4XX_CP_PROTECT(10), 0x61003980);
gpu_write(gpu, REG_A4XX_CP_PROTECT(11), 0x6e010000);
gpu_write(gpu, REG_A4XX_RBBM_INT_0_MASK, A4XX_INT0_MASK);
ret = adreno_hw_init(gpu);
if (ret)
return ret;
ptr = (uint32_t *)(adreno_gpu->pm4->data);
len = adreno_gpu->pm4->size / 4;
DBG("loading PM4 ucode version: %u", ptr[0]);
gpu_write(gpu, REG_A4XX_CP_ME_RAM_WADDR, 0);
for (i = 1; i < len; i++)
gpu_write(gpu, REG_A4XX_CP_ME_RAM_DATA, ptr[i]);
ptr = (uint32_t *)(adreno_gpu->pfp->data);
len = adreno_gpu->pfp->size / 4;
DBG("loading PFP ucode version: %u", ptr[0]);
gpu_write(gpu, REG_A4XX_CP_PFP_UCODE_ADDR, 0);
for (i = 1; i < len; i++)
gpu_write(gpu, REG_A4XX_CP_PFP_UCODE_DATA, ptr[i]);
gpu_write(gpu, REG_A4XX_CP_ME_CNTL, 0);
a4xx_me_init(gpu);
return 0;
}
static void a4xx_recover(struct msm_gpu *gpu)
{
adreno_dump_info(gpu);
if (hang_debug)
a4xx_dump(gpu);
gpu_write(gpu, REG_A4XX_RBBM_SW_RESET_CMD, 1);
gpu_read(gpu, REG_A4XX_RBBM_SW_RESET_CMD);
gpu_write(gpu, REG_A4XX_RBBM_SW_RESET_CMD, 0);
adreno_recover(gpu);
}
static void a4xx_destroy(struct msm_gpu *gpu)
{
struct adreno_gpu *adreno_gpu = to_adreno_gpu(gpu);
struct a4xx_gpu *a4xx_gpu = to_a4xx_gpu(adreno_gpu);
DBG("%s", gpu->name);
adreno_gpu_cleanup(adreno_gpu);
#ifdef CONFIG_MSM_OCMEM
if (a4xx_gpu->ocmem_base)
ocmem_free(OCMEM_GRAPHICS, a4xx_gpu->ocmem_hdl);
#endif
kfree(a4xx_gpu);
}
static void a4xx_idle(struct msm_gpu *gpu)
{
adreno_idle(gpu);
if (spin_until(!(gpu_read(gpu, REG_A4XX_RBBM_STATUS) &
A4XX_RBBM_STATUS_GPU_BUSY)))
DRM_ERROR("%s: timeout waiting for GPU to idle!\n", gpu->name);
}
static irqreturn_t a4xx_irq(struct msm_gpu *gpu)
{
uint32_t status;
status = gpu_read(gpu, REG_A4XX_RBBM_INT_0_STATUS);
DBG("%s: Int status %08x", gpu->name, status);
gpu_write(gpu, REG_A4XX_RBBM_INT_CLEAR_CMD, status);
msm_gpu_retire(gpu);
return IRQ_HANDLED;
}
static void a4xx_show(struct msm_gpu *gpu, struct seq_file *m)
{
gpu->funcs->pm_resume(gpu);
seq_printf(m, "status: %08x\n",
gpu_read(gpu, REG_A4XX_RBBM_STATUS));
gpu->funcs->pm_suspend(gpu);
adreno_show(gpu, m);
}
static void a4xx_dump(struct msm_gpu *gpu)
{
printk("status: %08x\n",
gpu_read(gpu, REG_A4XX_RBBM_STATUS));
adreno_dump(gpu);
}
struct msm_gpu *a4xx_gpu_init(struct drm_device *dev)
{
struct a4xx_gpu *a4xx_gpu = NULL;
struct adreno_gpu *adreno_gpu;
struct msm_gpu *gpu;
struct msm_drm_private *priv = dev->dev_private;
struct platform_device *pdev = priv->gpu_pdev;
int ret;
if (!pdev) {
dev_err(dev->dev, "no a4xx device\n");
ret = -ENXIO;
goto fail;
}
a4xx_gpu = kzalloc(sizeof(*a4xx_gpu), GFP_KERNEL);
if (!a4xx_gpu) {
ret = -ENOMEM;
goto fail;
}
adreno_gpu = &a4xx_gpu->base;
gpu = &adreno_gpu->base;
a4xx_gpu->pdev = pdev;
gpu->perfcntrs = NULL;
gpu->num_perfcntrs = 0;
adreno_gpu->registers = a4xx_registers;
adreno_gpu->reg_offsets = a4xx_register_offsets;
ret = adreno_gpu_init(dev, pdev, adreno_gpu, &funcs);
if (ret)
goto fail;
if (adreno_is_a4xx(adreno_gpu)) {
#ifdef CONFIG_MSM_OCMEM
struct ocmem_buf *ocmem_hdl =
ocmem_allocate(OCMEM_GRAPHICS, adreno_gpu->gmem);
a4xx_gpu->ocmem_hdl = ocmem_hdl;
a4xx_gpu->ocmem_base = ocmem_hdl->addr;
adreno_gpu->gmem = ocmem_hdl->len;
DBG("using %dK of OCMEM at 0x%08x", adreno_gpu->gmem / 1024,
a4xx_gpu->ocmem_base);
#endif
}
if (!gpu->mmu) {
dev_err(dev->dev, "No memory protection without IOMMU\n");
ret = -ENXIO;
goto fail;
}
return gpu;
fail:
if (a4xx_gpu)
a4xx_destroy(&a4xx_gpu->base.base);
return ERR_PTR(ret);
}
