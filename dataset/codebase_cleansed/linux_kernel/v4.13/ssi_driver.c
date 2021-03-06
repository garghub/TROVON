void dump_byte_array(const char *name, const u8 *the_array, unsigned long size)
{
int i, line_offset = 0, ret = 0;
const u8 *cur_byte;
char line_buf[80];
if (!the_array) {
SSI_LOG_ERR("cannot dump_byte_array - NULL pointer\n");
return;
}
ret = snprintf(line_buf, sizeof(line_buf), "%s[%lu]: ",
name, size);
if (ret < 0) {
SSI_LOG_ERR("snprintf returned %d . aborting buffer array dump\n", ret);
return;
}
line_offset = ret;
for (i = 0, cur_byte = the_array;
(i < size) && (line_offset < sizeof(line_buf)); i++, cur_byte++) {
ret = snprintf(line_buf + line_offset,
sizeof(line_buf) - line_offset,
"0x%02X ", *cur_byte);
if (ret < 0) {
SSI_LOG_ERR("snprintf returned %d . aborting buffer array dump\n", ret);
return;
}
line_offset += ret;
if (line_offset > 75) {
SSI_LOG_DEBUG("%s\n", line_buf);
line_offset = 0;
}
}
if (line_offset > 0)
SSI_LOG_DEBUG("%s\n", line_buf);
}
static irqreturn_t cc_isr(int irq, void *dev_id)
{
struct ssi_drvdata *drvdata = (struct ssi_drvdata *)dev_id;
void __iomem *cc_base = drvdata->cc_base;
u32 irr;
u32 imr;
irr = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IRR));
SSI_LOG_DEBUG("Got IRR=0x%08X\n", irr);
if (unlikely(irr == 0)) {
SSI_LOG_ERR("Got interrupt with empty IRR\n");
return IRQ_NONE;
}
imr = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IMR));
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_ICR), irr);
drvdata->irq = irr;
if (likely((irr & SSI_COMP_IRQ_MASK) != 0)) {
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IMR), imr | SSI_COMP_IRQ_MASK);
irr &= ~SSI_COMP_IRQ_MASK;
complete_request(drvdata);
}
#ifdef CC_SUPPORT_FIPS
if (likely((irr & SSI_GPR0_IRQ_MASK) != 0)) {
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IMR), imr | SSI_GPR0_IRQ_MASK);
irr &= ~SSI_GPR0_IRQ_MASK;
fips_handler(drvdata);
}
#endif
if (unlikely((irr & SSI_AXI_ERR_IRQ_MASK) != 0)) {
u32 axi_err;
axi_err = CC_HAL_READ_REGISTER(CC_REG_OFFSET(CRY_KERNEL, AXIM_MON_ERR));
SSI_LOG_DEBUG("AXI completion error: axim_mon_err=0x%08X\n", axi_err);
irr &= ~SSI_AXI_ERR_IRQ_MASK;
}
if (unlikely(irr != 0)) {
SSI_LOG_DEBUG("IRR includes unknown cause bits (0x%08X)\n", irr);
}
return IRQ_HANDLED;
}
int init_cc_regs(struct ssi_drvdata *drvdata, bool is_probe)
{
unsigned int val, cache_params;
void __iomem *cc_base = drvdata->cc_base;
val = CC_HAL_READ_REGISTER(CC_REG_OFFSET(CRY_KERNEL, AXIM_CFG));
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(CRY_KERNEL, AXIM_CFG), val & ~SSI_AXI_IRQ_MASK);
SSI_LOG_DEBUG("AXIM_CFG=0x%08X\n", CC_HAL_READ_REGISTER(CC_REG_OFFSET(CRY_KERNEL, AXIM_CFG)));
val = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IRR));
SSI_LOG_DEBUG("IRR=0x%08X\n", val);
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_ICR), val);
val = (~(SSI_COMP_IRQ_MASK | SSI_AXI_ERR_IRQ_MASK | SSI_GPR0_IRQ_MASK));
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IMR), val);
#ifdef DX_HOST_IRQ_TIMER_INIT_VAL_REG_OFFSET
#ifdef DX_IRQ_DELAY
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IRQ_TIMER_INIT_VAL),
DX_IRQ_DELAY);
#endif
if (CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IRQ_TIMER_INIT_VAL)) > 0) {
SSI_LOG_DEBUG("irq_delay=%d CC cycles\n",
CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_IRQ_TIMER_INIT_VAL)));
}
#endif
cache_params = (drvdata->coherent ? CC_COHERENT_CACHE_PARAMS : 0x0);
val = CC_HAL_READ_REGISTER(CC_REG_OFFSET(CRY_KERNEL, AXIM_CACHE_PARAMS));
if (is_probe)
SSI_LOG_INFO("Cache params previous: 0x%08X\n", val);
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(CRY_KERNEL, AXIM_CACHE_PARAMS),
cache_params);
val = CC_HAL_READ_REGISTER(CC_REG_OFFSET(CRY_KERNEL, AXIM_CACHE_PARAMS));
if (is_probe)
SSI_LOG_INFO("Cache params current: 0x%08X (expect: 0x%08X)\n",
val, cache_params);
return 0;
}
static int init_cc_resources(struct platform_device *plat_dev)
{
struct resource *req_mem_cc_regs = NULL;
void __iomem *cc_base = NULL;
bool irq_registered = false;
struct ssi_drvdata *new_drvdata = kzalloc(sizeof(struct ssi_drvdata), GFP_KERNEL);
struct device *dev = &plat_dev->dev;
struct device_node *np = dev->of_node;
u32 signature_val;
int rc = 0;
if (unlikely(!new_drvdata)) {
SSI_LOG_ERR("Failed to allocate drvdata");
rc = -ENOMEM;
goto init_cc_res_err;
}
new_drvdata->clk = of_clk_get(np, 0);
new_drvdata->coherent = of_dma_is_coherent(np);
new_drvdata->inflight_counter = 0;
dev_set_drvdata(&plat_dev->dev, new_drvdata);
new_drvdata->res_mem = platform_get_resource(plat_dev, IORESOURCE_MEM, 0);
if (unlikely(!new_drvdata->res_mem)) {
SSI_LOG_ERR("Failed getting IO memory resource\n");
rc = -ENODEV;
goto init_cc_res_err;
}
SSI_LOG_DEBUG("Got MEM resource (%s): start=0x%llX end=0x%llX\n",
new_drvdata->res_mem->name,
(unsigned long long)new_drvdata->res_mem->start,
(unsigned long long)new_drvdata->res_mem->end);
req_mem_cc_regs = request_mem_region(new_drvdata->res_mem->start, resource_size(new_drvdata->res_mem), "arm_cc7x_regs");
if (unlikely(!req_mem_cc_regs)) {
SSI_LOG_ERR("Couldn't allocate registers memory region at "
"0x%08X\n", (unsigned int)new_drvdata->res_mem->start);
rc = -EBUSY;
goto init_cc_res_err;
}
cc_base = ioremap(new_drvdata->res_mem->start, resource_size(new_drvdata->res_mem));
if (unlikely(!cc_base)) {
SSI_LOG_ERR("ioremap[CC](0x%08X,0x%08X) failed\n",
(unsigned int)new_drvdata->res_mem->start, (unsigned int)resource_size(new_drvdata->res_mem));
rc = -ENOMEM;
goto init_cc_res_err;
}
SSI_LOG_DEBUG("CC registers mapped from %pa to 0x%p\n", &new_drvdata->res_mem->start, cc_base);
new_drvdata->cc_base = cc_base;
new_drvdata->res_irq = platform_get_resource(plat_dev, IORESOURCE_IRQ, 0);
if (unlikely(!new_drvdata->res_irq)) {
SSI_LOG_ERR("Failed getting IRQ resource\n");
rc = -ENODEV;
goto init_cc_res_err;
}
rc = request_irq(new_drvdata->res_irq->start, cc_isr,
IRQF_SHARED, "arm_cc7x", new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("Could not register to interrupt %llu\n",
(unsigned long long)new_drvdata->res_irq->start);
goto init_cc_res_err;
}
init_completion(&new_drvdata->icache_setup_completion);
irq_registered = true;
SSI_LOG_DEBUG("Registered to IRQ (%s) %llu\n",
new_drvdata->res_irq->name,
(unsigned long long)new_drvdata->res_irq->start);
new_drvdata->plat_dev = plat_dev;
rc = cc_clk_on(new_drvdata);
if (rc)
goto init_cc_res_err;
if (!new_drvdata->plat_dev->dev.dma_mask)
{
new_drvdata->plat_dev->dev.dma_mask = &new_drvdata->plat_dev->dev.coherent_dma_mask;
}
if (!new_drvdata->plat_dev->dev.coherent_dma_mask)
{
new_drvdata->plat_dev->dev.coherent_dma_mask = DMA_BIT_MASK(DMA_BIT_MASK_LEN);
}
signature_val = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_SIGNATURE));
if (signature_val != DX_DEV_SIGNATURE) {
SSI_LOG_ERR("Invalid CC signature: SIGNATURE=0x%08X != expected=0x%08X\n",
signature_val, (u32)DX_DEV_SIGNATURE);
rc = -EINVAL;
goto init_cc_res_err;
}
SSI_LOG_DEBUG("CC SIGNATURE=0x%08X\n", signature_val);
SSI_LOG(KERN_INFO, "ARM CryptoCell %s Driver: HW version 0x%08X, Driver version %s\n", SSI_DEV_NAME_STR,
CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, HOST_VERSION)), DRV_MODULE_VERSION);
rc = init_cc_regs(new_drvdata, true);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("init_cc_regs failed\n");
goto init_cc_res_err;
}
#ifdef ENABLE_CC_SYSFS
rc = ssi_sysfs_init(&(plat_dev->dev.kobj), new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("init_stat_db failed\n");
goto init_cc_res_err;
}
#endif
rc = ssi_sram_mgr_init(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("ssi_sram_mgr_init failed\n");
goto init_cc_res_err;
}
new_drvdata->mlli_sram_addr =
ssi_sram_mgr_alloc(new_drvdata, MAX_MLLI_BUFF_SIZE);
if (unlikely(new_drvdata->mlli_sram_addr == NULL_SRAM_ADDR)) {
SSI_LOG_ERR("Failed to alloc MLLI Sram buffer\n");
rc = -ENOMEM;
goto init_cc_res_err;
}
rc = request_mgr_init(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("request_mgr_init failed\n");
goto init_cc_res_err;
}
rc = ssi_buffer_mgr_init(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("buffer_mgr_init failed\n");
goto init_cc_res_err;
}
rc = ssi_power_mgr_init(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("ssi_power_mgr_init failed\n");
goto init_cc_res_err;
}
rc = ssi_fips_init(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("SSI_FIPS_INIT failed 0x%x\n", rc);
goto init_cc_res_err;
}
rc = ssi_ivgen_init(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("ssi_ivgen_init failed\n");
goto init_cc_res_err;
}
rc = ssi_ablkcipher_alloc(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("ssi_ablkcipher_alloc failed\n");
goto init_cc_res_err;
}
rc = ssi_hash_alloc(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("ssi_hash_alloc failed\n");
goto init_cc_res_err;
}
rc = ssi_aead_alloc(new_drvdata);
if (unlikely(rc != 0)) {
SSI_LOG_ERR("ssi_aead_alloc failed\n");
goto init_cc_res_err;
}
return 0;
init_cc_res_err:
SSI_LOG_ERR("Freeing CC HW resources!\n");
if (new_drvdata) {
ssi_aead_free(new_drvdata);
ssi_hash_free(new_drvdata);
ssi_ablkcipher_free(new_drvdata);
ssi_ivgen_fini(new_drvdata);
ssi_power_mgr_fini(new_drvdata);
ssi_buffer_mgr_fini(new_drvdata);
request_mgr_fini(new_drvdata);
ssi_sram_mgr_fini(new_drvdata);
ssi_fips_fini(new_drvdata);
#ifdef ENABLE_CC_SYSFS
ssi_sysfs_fini();
#endif
if (req_mem_cc_regs) {
if (irq_registered) {
free_irq(new_drvdata->res_irq->start, new_drvdata);
new_drvdata->res_irq = NULL;
iounmap(cc_base);
new_drvdata->cc_base = NULL;
}
release_mem_region(new_drvdata->res_mem->start,
resource_size(new_drvdata->res_mem));
new_drvdata->res_mem = NULL;
}
kfree(new_drvdata);
dev_set_drvdata(&plat_dev->dev, NULL);
}
return rc;
}
void fini_cc_regs(struct ssi_drvdata *drvdata)
{
WRITE_REGISTER(drvdata->cc_base +
CC_REG_OFFSET(HOST_RGF, HOST_IMR), 0xFFFFFFFF);
}
static void cleanup_cc_resources(struct platform_device *plat_dev)
{
struct ssi_drvdata *drvdata =
(struct ssi_drvdata *)dev_get_drvdata(&plat_dev->dev);
ssi_aead_free(drvdata);
ssi_hash_free(drvdata);
ssi_ablkcipher_free(drvdata);
ssi_ivgen_fini(drvdata);
ssi_power_mgr_fini(drvdata);
ssi_buffer_mgr_fini(drvdata);
request_mgr_fini(drvdata);
ssi_sram_mgr_fini(drvdata);
ssi_fips_fini(drvdata);
#ifdef ENABLE_CC_SYSFS
ssi_sysfs_fini();
#endif
fini_cc_regs(drvdata);
cc_clk_off(drvdata);
free_irq(drvdata->res_irq->start, drvdata);
drvdata->res_irq = NULL;
if (drvdata->cc_base) {
iounmap(drvdata->cc_base);
release_mem_region(drvdata->res_mem->start,
resource_size(drvdata->res_mem));
drvdata->cc_base = NULL;
drvdata->res_mem = NULL;
}
kfree(drvdata);
dev_set_drvdata(&plat_dev->dev, NULL);
}
int cc_clk_on(struct ssi_drvdata *drvdata)
{
struct clk *clk = drvdata->clk;
int rc;
if (IS_ERR(clk))
return 0;
rc = clk_prepare_enable(clk);
if (rc)
return rc;
return 0;
}
void cc_clk_off(struct ssi_drvdata *drvdata)
{
struct clk *clk = drvdata->clk;
if (IS_ERR(clk))
return;
clk_disable_unprepare(clk);
}
static int cc7x_probe(struct platform_device *plat_dev)
{
int rc;
#if defined(CONFIG_ARM) && defined(CC_DEBUG)
u32 ctr, cacheline_size;
asm volatile("mrc p15, 0, %0, c0, c0, 1" : "=r" (ctr));
cacheline_size = 4 << ((ctr >> 16) & 0xf);
SSI_LOG_DEBUG("CP15(L1_CACHE_BYTES) = %u , Kconfig(L1_CACHE_BYTES) = %u\n",
cacheline_size, L1_CACHE_BYTES);
asm volatile("mrc p15, 0, %0, c0, c0, 0" : "=r" (ctr));
SSI_LOG_DEBUG("Main ID register (MIDR): Implementer 0x%02X, Arch 0x%01X,"
" Part 0x%03X, Rev r%dp%d\n",
(ctr >> 24), (ctr >> 16) & 0xF, (ctr >> 4) & 0xFFF, (ctr >> 20) & 0xF, ctr & 0xF);
#endif
rc = init_cc_resources(plat_dev);
if (rc != 0)
return rc;
SSI_LOG(KERN_INFO, "ARM cc7x_ree device initialized\n");
return 0;
}
static int cc7x_remove(struct platform_device *plat_dev)
{
SSI_LOG_DEBUG("Releasing cc7x resources...\n");
cleanup_cc_resources(plat_dev);
SSI_LOG(KERN_INFO, "ARM cc7x_ree device terminated\n");
return 0;
}
