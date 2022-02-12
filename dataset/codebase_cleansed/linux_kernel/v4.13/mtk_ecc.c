static inline void mtk_ecc_wait_idle(struct mtk_ecc *ecc,
enum mtk_ecc_operation op)
{
struct device *dev = ecc->dev;
u32 val;
int ret;
ret = readl_poll_timeout_atomic(ecc->regs + ECC_IDLE_REG(op), val,
val & ECC_IDLE_MASK,
10, ECC_TIMEOUT);
if (ret)
dev_warn(dev, "%s NOT idle\n",
op == ECC_ENCODE ? "encoder" : "decoder");
}
static irqreturn_t mtk_ecc_irq(int irq, void *id)
{
struct mtk_ecc *ecc = id;
enum mtk_ecc_operation op;
u32 dec, enc;
dec = readw(ecc->regs + ECC_DECIRQ_STA) & ECC_IRQ_EN;
if (dec) {
op = ECC_DECODE;
dec = readw(ecc->regs + ECC_DECDONE);
if (dec & ecc->sectors) {
ecc->sectors = 0;
complete(&ecc->done);
} else {
return IRQ_HANDLED;
}
} else {
enc = readl(ecc->regs + ECC_ENCIRQ_STA) & ECC_IRQ_EN;
if (enc) {
op = ECC_ENCODE;
complete(&ecc->done);
} else {
return IRQ_NONE;
}
}
writel(0, ecc->regs + ECC_IRQ_REG(op));
return IRQ_HANDLED;
}
static int mtk_ecc_config(struct mtk_ecc *ecc, struct mtk_ecc_config *config)
{
u32 ecc_bit, dec_sz, enc_sz;
u32 reg, i;
for (i = 0; i < ecc->caps->num_ecc_strength; i++) {
if (ecc->caps->ecc_strength[i] == config->strength)
break;
}
if (i == ecc->caps->num_ecc_strength) {
dev_err(ecc->dev, "invalid ecc strength %d\n",
config->strength);
return -EINVAL;
}
ecc_bit = i;
if (config->op == ECC_ENCODE) {
enc_sz = config->len << 3;
reg = ecc_bit | (config->mode << ECC_MODE_SHIFT);
reg |= (enc_sz << ECC_MS_SHIFT);
writel(reg, ecc->regs + ECC_ENCCNFG);
if (config->mode != ECC_NFI_MODE)
writel(lower_32_bits(config->addr),
ecc->regs + ECC_ENCDIADDR);
} else {
dec_sz = (config->len << 3) +
config->strength * ECC_PARITY_BITS;
reg = ecc_bit | (config->mode << ECC_MODE_SHIFT);
reg |= (dec_sz << ECC_MS_SHIFT) | DEC_CNFG_CORRECT;
reg |= DEC_EMPTY_EN;
writel(reg, ecc->regs + ECC_DECCNFG);
if (config->sectors)
ecc->sectors = 1 << (config->sectors - 1);
}
return 0;
}
void mtk_ecc_get_stats(struct mtk_ecc *ecc, struct mtk_ecc_stats *stats,
int sectors)
{
u32 offset, i, err;
u32 bitflips = 0;
stats->corrected = 0;
stats->failed = 0;
for (i = 0; i < sectors; i++) {
offset = (i >> 2) << 2;
err = readl(ecc->regs + ECC_DECENUM0 + offset);
err = err >> ((i % 4) * 8);
err &= ecc->caps->err_mask;
if (err == ecc->caps->err_mask) {
stats->failed++;
continue;
}
stats->corrected += err;
bitflips = max_t(u32, bitflips, err);
}
stats->bitflips = bitflips;
}
void mtk_ecc_release(struct mtk_ecc *ecc)
{
clk_disable_unprepare(ecc->clk);
put_device(ecc->dev);
}
static void mtk_ecc_hw_init(struct mtk_ecc *ecc)
{
mtk_ecc_wait_idle(ecc, ECC_ENCODE);
writew(ECC_OP_DISABLE, ecc->regs + ECC_ENCCON);
mtk_ecc_wait_idle(ecc, ECC_DECODE);
writel(ECC_OP_DISABLE, ecc->regs + ECC_DECCON);
}
static struct mtk_ecc *mtk_ecc_get(struct device_node *np)
{
struct platform_device *pdev;
struct mtk_ecc *ecc;
pdev = of_find_device_by_node(np);
if (!pdev || !platform_get_drvdata(pdev))
return ERR_PTR(-EPROBE_DEFER);
get_device(&pdev->dev);
ecc = platform_get_drvdata(pdev);
clk_prepare_enable(ecc->clk);
mtk_ecc_hw_init(ecc);
return ecc;
}
struct mtk_ecc *of_mtk_ecc_get(struct device_node *of_node)
{
struct mtk_ecc *ecc = NULL;
struct device_node *np;
np = of_parse_phandle(of_node, "ecc-engine", 0);
if (np) {
ecc = mtk_ecc_get(np);
of_node_put(np);
}
return ecc;
}
int mtk_ecc_enable(struct mtk_ecc *ecc, struct mtk_ecc_config *config)
{
enum mtk_ecc_operation op = config->op;
u16 reg_val;
int ret;
ret = mutex_lock_interruptible(&ecc->lock);
if (ret) {
dev_err(ecc->dev, "interrupted when attempting to lock\n");
return ret;
}
mtk_ecc_wait_idle(ecc, op);
ret = mtk_ecc_config(ecc, config);
if (ret) {
mutex_unlock(&ecc->lock);
return ret;
}
if (config->mode != ECC_NFI_MODE || op != ECC_ENCODE) {
init_completion(&ecc->done);
reg_val = ECC_IRQ_EN;
if (ecc->caps->pg_irq_sel && config->mode == ECC_NFI_MODE)
reg_val |= ECC_PG_IRQ_SEL;
writew(reg_val, ecc->regs + ECC_IRQ_REG(op));
}
writew(ECC_OP_ENABLE, ecc->regs + ECC_CTL_REG(op));
return 0;
}
void mtk_ecc_disable(struct mtk_ecc *ecc)
{
enum mtk_ecc_operation op = ECC_ENCODE;
if (readw(ecc->regs + ECC_CTL_REG(op)) != ECC_OP_ENABLE)
op = ECC_DECODE;
mtk_ecc_wait_idle(ecc, op);
writew(0, ecc->regs + ECC_IRQ_REG(op));
writew(ECC_OP_DISABLE, ecc->regs + ECC_CTL_REG(op));
mutex_unlock(&ecc->lock);
}
int mtk_ecc_wait_done(struct mtk_ecc *ecc, enum mtk_ecc_operation op)
{
int ret;
ret = wait_for_completion_timeout(&ecc->done, msecs_to_jiffies(500));
if (!ret) {
dev_err(ecc->dev, "%s timeout - interrupt did not arrive)\n",
(op == ECC_ENCODE) ? "encoder" : "decoder");
return -ETIMEDOUT;
}
return 0;
}
int mtk_ecc_encode(struct mtk_ecc *ecc, struct mtk_ecc_config *config,
u8 *data, u32 bytes)
{
dma_addr_t addr;
u32 len;
int ret;
addr = dma_map_single(ecc->dev, data, bytes, DMA_TO_DEVICE);
ret = dma_mapping_error(ecc->dev, addr);
if (ret) {
dev_err(ecc->dev, "dma mapping error\n");
return -EINVAL;
}
config->op = ECC_ENCODE;
config->addr = addr;
ret = mtk_ecc_enable(ecc, config);
if (ret) {
dma_unmap_single(ecc->dev, addr, bytes, DMA_TO_DEVICE);
return ret;
}
ret = mtk_ecc_wait_done(ecc, ECC_ENCODE);
if (ret)
goto timeout;
mtk_ecc_wait_idle(ecc, ECC_ENCODE);
len = (config->strength * ECC_PARITY_BITS + 7) >> 3;
__ioread32_copy(ecc->eccdata,
ecc->regs + ecc->caps->encode_parity_reg0,
round_up(len, 4));
memcpy(data + bytes, ecc->eccdata, len);
timeout:
dma_unmap_single(ecc->dev, addr, bytes, DMA_TO_DEVICE);
mtk_ecc_disable(ecc);
return ret;
}
void mtk_ecc_adjust_strength(struct mtk_ecc *ecc, u32 *p)
{
const u8 *ecc_strength = ecc->caps->ecc_strength;
int i;
for (i = 0; i < ecc->caps->num_ecc_strength; i++) {
if (*p <= ecc_strength[i]) {
if (!i)
*p = ecc_strength[i];
else if (*p != ecc_strength[i])
*p = ecc_strength[i - 1];
return;
}
}
*p = ecc_strength[ecc->caps->num_ecc_strength - 1];
}
static int mtk_ecc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_ecc *ecc;
struct resource *res;
const struct of_device_id *of_ecc_id = NULL;
u32 max_eccdata_size;
int irq, ret;
ecc = devm_kzalloc(dev, sizeof(*ecc), GFP_KERNEL);
if (!ecc)
return -ENOMEM;
of_ecc_id = of_match_device(mtk_ecc_dt_match, &pdev->dev);
if (!of_ecc_id)
return -ENODEV;
ecc->caps = of_ecc_id->data;
max_eccdata_size = ecc->caps->num_ecc_strength - 1;
max_eccdata_size = ecc->caps->ecc_strength[max_eccdata_size];
max_eccdata_size = (max_eccdata_size * ECC_PARITY_BITS + 7) >> 3;
max_eccdata_size = round_up(max_eccdata_size, 4);
ecc->eccdata = devm_kzalloc(dev, max_eccdata_size, GFP_KERNEL);
if (!ecc->eccdata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ecc->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(ecc->regs)) {
dev_err(dev, "failed to map regs: %ld\n", PTR_ERR(ecc->regs));
return PTR_ERR(ecc->regs);
}
ecc->clk = devm_clk_get(dev, NULL);
if (IS_ERR(ecc->clk)) {
dev_err(dev, "failed to get clock: %ld\n", PTR_ERR(ecc->clk));
return PTR_ERR(ecc->clk);
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "failed to get irq\n");
return -EINVAL;
}
ret = dma_set_mask(dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(dev, "failed to set DMA mask\n");
return ret;
}
ret = devm_request_irq(dev, irq, mtk_ecc_irq, 0x0, "mtk-ecc", ecc);
if (ret) {
dev_err(dev, "failed to request irq\n");
return -EINVAL;
}
ecc->dev = dev;
mutex_init(&ecc->lock);
platform_set_drvdata(pdev, ecc);
dev_info(dev, "probed\n");
return 0;
}
static int mtk_ecc_suspend(struct device *dev)
{
struct mtk_ecc *ecc = dev_get_drvdata(dev);
clk_disable_unprepare(ecc->clk);
return 0;
}
static int mtk_ecc_resume(struct device *dev)
{
struct mtk_ecc *ecc = dev_get_drvdata(dev);
int ret;
ret = clk_prepare_enable(ecc->clk);
if (ret) {
dev_err(dev, "failed to enable clk\n");
return ret;
}
return 0;
}
