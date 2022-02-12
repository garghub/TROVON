static inline u32 bm_ccsr_in(u32 offset)
{
return ioread32be(bm_ccsr_start + offset/4);
}
static inline void bm_ccsr_out(u32 offset, u32 val)
{
iowrite32be(val, bm_ccsr_start + offset/4);
}
static void bm_get_version(u16 *id, u8 *major, u8 *minor)
{
u32 v = bm_ccsr_in(REG_IP_REV_1);
*id = (v >> 16);
*major = (v >> 8) & 0xff;
*minor = v & 0xff;
}
static void bm_set_memory(u64 ba, u32 size)
{
u32 exp = ilog2(size);
DPAA_ASSERT(size >= 4096 && size <= 1024*1024*1024 &&
is_power_of_2(size));
DPAA_ASSERT(!(ba & (size - 1)));
bm_ccsr_out(REG_FBPR_BARE, upper_32_bits(ba));
bm_ccsr_out(REG_FBPR_BAR, lower_32_bits(ba));
bm_ccsr_out(REG_FBPR_AR, exp - 1);
}
static int bman_fbpr(struct reserved_mem *rmem)
{
fbpr_a = rmem->base;
fbpr_sz = rmem->size;
WARN_ON(!(fbpr_a && fbpr_sz));
return 0;
}
static irqreturn_t bman_isr(int irq, void *ptr)
{
u32 isr_val, ier_val, ecsr_val, isr_mask, i;
struct device *dev = ptr;
ier_val = bm_ccsr_in(REG_ERR_IER);
isr_val = bm_ccsr_in(REG_ERR_ISR);
ecsr_val = bm_ccsr_in(REG_ECSR);
isr_mask = isr_val & ier_val;
if (!isr_mask)
return IRQ_NONE;
for (i = 0; i < ARRAY_SIZE(bman_hwerr_txts); i++) {
if (bman_hwerr_txts[i].mask & isr_mask) {
dev_err_ratelimited(dev, "ErrInt: %s\n",
bman_hwerr_txts[i].txt);
if (bman_hwerr_txts[i].mask & ecsr_val) {
bm_ccsr_out(REG_ECSR, ecsr_val);
}
if (bman_hwerr_txts[i].mask & BMAN_ERRS_TO_DISABLE) {
dev_dbg(dev, "Disabling error 0x%x\n",
bman_hwerr_txts[i].mask);
ier_val &= ~bman_hwerr_txts[i].mask;
bm_ccsr_out(REG_ERR_IER, ier_val);
}
}
}
bm_ccsr_out(REG_ERR_ISR, isr_val);
return IRQ_HANDLED;
}
static int fsl_bman_probe(struct platform_device *pdev)
{
int ret, err_irq;
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct resource *res;
u16 id, bm_pool_cnt;
u8 major, minor;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "Can't get %s property 'IORESOURCE_MEM'\n",
node->full_name);
return -ENXIO;
}
bm_ccsr_start = devm_ioremap(dev, res->start,
res->end - res->start + 1);
if (!bm_ccsr_start)
return -ENXIO;
bm_get_version(&id, &major, &minor);
if (major == 1 && minor == 0) {
bman_ip_rev = BMAN_REV10;
bm_pool_cnt = BM_POOL_MAX;
} else if (major == 2 && minor == 0) {
bman_ip_rev = BMAN_REV20;
bm_pool_cnt = 8;
} else if (major == 2 && minor == 1) {
bman_ip_rev = BMAN_REV21;
bm_pool_cnt = BM_POOL_MAX;
} else {
dev_err(dev, "Unknown Bman version:%04x,%02x,%02x\n",
id, major, minor);
return -ENODEV;
}
bm_set_memory(fbpr_a, fbpr_sz);
err_irq = platform_get_irq(pdev, 0);
if (err_irq <= 0) {
dev_info(dev, "Can't get %s IRQ\n", node->full_name);
return -ENODEV;
}
ret = devm_request_irq(dev, err_irq, bman_isr, IRQF_SHARED, "bman-err",
dev);
if (ret) {
dev_err(dev, "devm_request_irq() failed %d for '%s'\n",
ret, node->full_name);
return ret;
}
bm_ccsr_out(REG_ERR_ISDR, BM_EIRQ_BSCN);
bm_ccsr_out(REG_ERR_ISR, 0xffffffff);
bm_ccsr_out(REG_ERR_IER, 0xffffffff);
bm_bpalloc = devm_gen_pool_create(dev, 0, -1, "bman-bpalloc");
if (IS_ERR(bm_bpalloc)) {
ret = PTR_ERR(bm_bpalloc);
dev_err(dev, "bman-bpalloc pool init failed (%d)\n", ret);
return ret;
}
ret = gen_pool_add(bm_bpalloc, DPAA_GENALLOC_OFF, bm_pool_cnt, -1);
if (ret) {
dev_err(dev, "Failed to seed BPID range [%d..%d] (%d)\n",
0, bm_pool_cnt - 1, ret);
return ret;
}
return 0;
}
