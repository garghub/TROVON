static void a3xx_me_init(struct msm_gpu *gpu)
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
if (adreno_is_a320(adreno_gpu))
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
if (adreno_is_a305(adreno_gpu) || adreno_is_a320(adreno_gpu)) {
gpu_write(gpu, REG_AXXX_CP_QUEUE_THRESHOLDS,
AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB1_START(2) |
AXXX_CP_QUEUE_THRESHOLDS_CSQ_IB2_START(6) |
AXXX_CP_QUEUE_THRESHOLDS_CSQ_ST_START(14));
} else if (adreno_is_a330(adreno_gpu)) {
gpu_write(gpu, REG_AXXX_CP_QUEUE_THRESHOLDS, 0x003e2008);
}
gpu_write(gpu, REG_AXXX_CP_ME_CNTL, 0);
a3xx_me_init(gpu);
return 0;
}
static void a3xx_recover(struct msm_gpu *gpu)
{
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
static void a3xx_idle(struct msm_gpu *gpu)
{
adreno_idle(gpu);
if (spin_until(!(gpu_read(gpu, REG_A3XX_RBBM_STATUS) &
A3XX_RBBM_STATUS_GPU_BUSY)))
DRM_ERROR("%s: timeout waiting for GPU to idle!\n", gpu->name);
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
struct drm_device *dev = gpu->dev;
int i;
adreno_show(gpu, m);
mutex_lock(&dev->struct_mutex);
gpu->funcs->pm_resume(gpu);
seq_printf(m, "status: %08x\n",
gpu_read(gpu, REG_A3XX_RBBM_STATUS));
seq_printf(m, "IO:region %s 00000000 00020000\n", gpu->name);
for (i = 0; i < ARRAY_SIZE(a3xx_registers); i += 2) {
uint32_t start = a3xx_registers[i];
uint32_t end = a3xx_registers[i+1];
uint32_t addr;
for (addr = start; addr <= end; addr++) {
uint32_t val = gpu_read(gpu, addr);
seq_printf(m, "IO:R %08x %08x\n", addr<<2, val);
}
}
gpu->funcs->pm_suspend(gpu);
mutex_unlock(&dev->struct_mutex);
}
static void a3xx_dump(struct msm_gpu *gpu)
{
int i;
adreno_dump(gpu);
printk("status: %08x\n",
gpu_read(gpu, REG_A3XX_RBBM_STATUS));
printk("IO:region %s 00000000 00020000\n", gpu->name);
for (i = 0; i < ARRAY_SIZE(a3xx_registers); i += 2) {
uint32_t start = a3xx_registers[i];
uint32_t end = a3xx_registers[i+1];
uint32_t addr;
for (addr = start; addr <= end; addr++) {
uint32_t val = gpu_read(gpu, addr);
printk("IO:R %08x %08x\n", addr<<2, val);
}
}
}
struct msm_gpu *a3xx_gpu_init(struct drm_device *dev)
{
struct a3xx_gpu *a3xx_gpu = NULL;
struct adreno_gpu *adreno_gpu;
struct msm_gpu *gpu;
struct msm_drm_private *priv = dev->dev_private;
struct platform_device *pdev = priv->gpu_pdev;
struct adreno_platform_config *config;
int ret;
if (!pdev) {
dev_err(dev->dev, "no a3xx device\n");
ret = -ENXIO;
goto fail;
}
config = pdev->dev.platform_data;
a3xx_gpu = kzalloc(sizeof(*a3xx_gpu), GFP_KERNEL);
if (!a3xx_gpu) {
ret = -ENOMEM;
goto fail;
}
adreno_gpu = &a3xx_gpu->base;
gpu = &adreno_gpu->base;
a3xx_gpu->pdev = pdev;
gpu->fast_rate = config->fast_rate;
gpu->slow_rate = config->slow_rate;
gpu->bus_freq = config->bus_freq;
#ifdef CONFIG_MSM_BUS_SCALING
gpu->bus_scale_table = config->bus_scale_table;
#endif
DBG("fast_rate=%u, slow_rate=%u, bus_freq=%u",
gpu->fast_rate, gpu->slow_rate, gpu->bus_freq);
gpu->perfcntrs = perfcntrs;
gpu->num_perfcntrs = ARRAY_SIZE(perfcntrs);
ret = adreno_gpu_init(dev, pdev, adreno_gpu, &funcs, config->rev);
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
if (!gpu->mmu) {
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
static void set_gpu_pdev(struct drm_device *dev,
struct platform_device *pdev)
{
struct msm_drm_private *priv = dev->dev_private;
priv->gpu_pdev = pdev;
}
static int a3xx_bind(struct device *dev, struct device *master, void *data)
{
static struct adreno_platform_config config = {};
#ifdef CONFIG_OF
struct device_node *child, *node = dev->of_node;
u32 val;
int ret;
ret = of_property_read_u32(node, "qcom,chipid", &val);
if (ret) {
dev_err(dev, "could not find chipid: %d\n", ret);
return ret;
}
config.rev = ADRENO_REV((val >> 24) & 0xff,
(val >> 16) & 0xff, (val >> 8) & 0xff, val & 0xff);
config.fast_rate = 0;
config.slow_rate = ~0;
for_each_child_of_node(node, child) {
if (of_device_is_compatible(child, "qcom,gpu-pwrlevels")) {
struct device_node *pwrlvl;
for_each_child_of_node(child, pwrlvl) {
ret = of_property_read_u32(pwrlvl, "qcom,gpu-freq", &val);
if (ret) {
dev_err(dev, "could not find gpu-freq: %d\n", ret);
return ret;
}
config.fast_rate = max(config.fast_rate, val);
config.slow_rate = min(config.slow_rate, val);
}
}
}
if (!config.fast_rate) {
dev_err(dev, "could not find clk rates\n");
return -ENXIO;
}
#else
struct kgsl_device_platform_data *pdata = dev->platform_data;
uint32_t version = socinfo_get_version();
if (cpu_is_apq8064ab()) {
config.fast_rate = 450000000;
config.slow_rate = 27000000;
config.bus_freq = 4;
config.rev = ADRENO_REV(3, 2, 1, 0);
} else if (cpu_is_apq8064()) {
config.fast_rate = 400000000;
config.slow_rate = 27000000;
config.bus_freq = 4;
if (SOCINFO_VERSION_MAJOR(version) == 2)
config.rev = ADRENO_REV(3, 2, 0, 2);
else if ((SOCINFO_VERSION_MAJOR(version) == 1) &&
(SOCINFO_VERSION_MINOR(version) == 1))
config.rev = ADRENO_REV(3, 2, 0, 1);
else
config.rev = ADRENO_REV(3, 2, 0, 0);
} else if (cpu_is_msm8960ab()) {
config.fast_rate = 400000000;
config.slow_rate = 320000000;
config.bus_freq = 4;
if (SOCINFO_VERSION_MINOR(version) == 0)
config.rev = ADRENO_REV(3, 2, 1, 0);
else
config.rev = ADRENO_REV(3, 2, 1, 1);
} else if (cpu_is_msm8930()) {
config.fast_rate = 400000000;
config.slow_rate = 27000000;
config.bus_freq = 3;
if ((SOCINFO_VERSION_MAJOR(version) == 1) &&
(SOCINFO_VERSION_MINOR(version) == 2))
config.rev = ADRENO_REV(3, 0, 5, 2);
else
config.rev = ADRENO_REV(3, 0, 5, 0);
}
# ifdef CONFIG_MSM_BUS_SCALING
config.bus_scale_table = pdata->bus_scale_table;
# endif
#endif
dev->platform_data = &config;
set_gpu_pdev(dev_get_drvdata(master), to_platform_device(dev));
return 0;
}
static void a3xx_unbind(struct device *dev, struct device *master,
void *data)
{
set_gpu_pdev(dev_get_drvdata(master), NULL);
}
static int a3xx_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &a3xx_ops);
}
static int a3xx_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &a3xx_ops);
return 0;
}
void __init a3xx_register(void)
{
platform_driver_register(&a3xx_driver);
}
void __exit a3xx_unregister(void)
{
platform_driver_unregister(&a3xx_driver);
}
