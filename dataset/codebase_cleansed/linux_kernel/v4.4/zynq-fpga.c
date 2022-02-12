static inline void zynq_fpga_write(struct zynq_fpga_priv *priv, u32 offset,
u32 val)
{
writel(val, priv->io_base + offset);
}
static inline u32 zynq_fpga_read(const struct zynq_fpga_priv *priv,
u32 offset)
{
return readl(priv->io_base + offset);
}
static void zynq_fpga_mask_irqs(struct zynq_fpga_priv *priv)
{
u32 intr_mask;
intr_mask = zynq_fpga_read(priv, INT_MASK_OFFSET);
zynq_fpga_write(priv, INT_MASK_OFFSET,
intr_mask | IXR_DMA_DONE_MASK | IXR_ERROR_FLAGS_MASK);
}
static void zynq_fpga_unmask_irqs(struct zynq_fpga_priv *priv)
{
u32 intr_mask;
intr_mask = zynq_fpga_read(priv, INT_MASK_OFFSET);
zynq_fpga_write(priv, INT_MASK_OFFSET,
intr_mask
& ~(IXR_D_P_DONE_MASK | IXR_ERROR_FLAGS_MASK));
}
static irqreturn_t zynq_fpga_isr(int irq, void *data)
{
struct zynq_fpga_priv *priv = data;
zynq_fpga_mask_irqs(priv);
complete(&priv->dma_done);
return IRQ_HANDLED;
}
static int zynq_fpga_ops_write_init(struct fpga_manager *mgr, u32 flags,
const char *buf, size_t count)
{
struct zynq_fpga_priv *priv;
u32 ctrl, status;
int err;
priv = mgr->priv;
err = clk_enable(priv->clk);
if (err)
return err;
if (!(flags & FPGA_MGR_PARTIAL_RECONFIG)) {
regmap_write(priv->slcr, SLCR_FPGA_RST_CTRL_OFFSET,
FPGA_RST_ALL_MASK);
regmap_write(priv->slcr, SLCR_LVL_SHFTR_EN_OFFSET,
LVL_SHFTR_DISABLE_ALL_MASK);
regmap_write(priv->slcr, SLCR_LVL_SHFTR_EN_OFFSET,
LVL_SHFTR_ENABLE_PS_TO_PL);
ctrl = zynq_fpga_read(priv, CTRL_OFFSET);
ctrl |= CTRL_PCFG_PROG_B_MASK;
zynq_fpga_write(priv, CTRL_OFFSET, ctrl);
err = zynq_fpga_poll_timeout(priv, STATUS_OFFSET, status,
status & STATUS_PCFG_INIT_MASK,
INIT_POLL_DELAY,
INIT_POLL_TIMEOUT);
if (err) {
dev_err(priv->dev, "Timeout waiting for PCFG_INIT");
goto out_err;
}
ctrl = zynq_fpga_read(priv, CTRL_OFFSET);
ctrl &= ~CTRL_PCFG_PROG_B_MASK;
zynq_fpga_write(priv, CTRL_OFFSET, ctrl);
err = zynq_fpga_poll_timeout(priv, STATUS_OFFSET, status,
!(status & STATUS_PCFG_INIT_MASK),
INIT_POLL_DELAY,
INIT_POLL_TIMEOUT);
if (err) {
dev_err(priv->dev, "Timeout waiting for !PCFG_INIT");
goto out_err;
}
ctrl = zynq_fpga_read(priv, CTRL_OFFSET);
ctrl |= CTRL_PCFG_PROG_B_MASK;
zynq_fpga_write(priv, CTRL_OFFSET, ctrl);
err = zynq_fpga_poll_timeout(priv, STATUS_OFFSET, status,
status & STATUS_PCFG_INIT_MASK,
INIT_POLL_DELAY,
INIT_POLL_TIMEOUT);
if (err) {
dev_err(priv->dev, "Timeout waiting for PCFG_INIT");
goto out_err;
}
}
ctrl = zynq_fpga_read(priv, CTRL_OFFSET);
zynq_fpga_write(priv, CTRL_OFFSET,
(CTRL_PCAP_PR_MASK | CTRL_PCAP_MODE_MASK | ctrl));
status = zynq_fpga_read(priv, STATUS_OFFSET);
if (status & STATUS_DMA_Q_F) {
dev_err(priv->dev, "DMA command queue full");
err = -EBUSY;
goto out_err;
}
ctrl = zynq_fpga_read(priv, MCTRL_OFFSET);
zynq_fpga_write(priv, MCTRL_OFFSET, (~MCTRL_PCAP_LPBK_MASK & ctrl));
clk_disable(priv->clk);
return 0;
out_err:
clk_disable(priv->clk);
return err;
}
static int zynq_fpga_ops_write(struct fpga_manager *mgr,
const char *buf, size_t count)
{
struct zynq_fpga_priv *priv;
int err;
char *kbuf;
size_t in_count;
dma_addr_t dma_addr;
u32 transfer_length;
u32 intr_status;
in_count = count;
priv = mgr->priv;
kbuf = dma_alloc_coherent(priv->dev, count, &dma_addr, GFP_KERNEL);
if (!kbuf)
return -ENOMEM;
memcpy(kbuf, buf, count);
err = clk_enable(priv->clk);
if (err)
goto out_free;
zynq_fpga_write(priv, INT_STS_OFFSET, IXR_ALL_MASK);
reinit_completion(&priv->dma_done);
zynq_fpga_unmask_irqs(priv);
zynq_fpga_write(priv, DMA_SRC_ADDR_OFFSET, (u32)(dma_addr) + 1);
zynq_fpga_write(priv, DMA_DST_ADDR_OFFSET, (u32)DMA_INVALID_ADDRESS);
transfer_length = (count + 3) / 4;
zynq_fpga_write(priv, DMA_SRC_LEN_OFFSET, transfer_length);
zynq_fpga_write(priv, DMA_DEST_LEN_OFFSET, 0);
wait_for_completion(&priv->dma_done);
intr_status = zynq_fpga_read(priv, INT_STS_OFFSET);
zynq_fpga_write(priv, INT_STS_OFFSET, intr_status);
if (!((intr_status & IXR_D_P_DONE_MASK) == IXR_D_P_DONE_MASK)) {
dev_err(priv->dev, "Error configuring FPGA");
err = -EFAULT;
}
clk_disable(priv->clk);
out_free:
dma_free_coherent(priv->dev, in_count, kbuf, dma_addr);
return err;
}
static int zynq_fpga_ops_write_complete(struct fpga_manager *mgr, u32 flags)
{
struct zynq_fpga_priv *priv = mgr->priv;
int err;
u32 intr_status;
err = clk_enable(priv->clk);
if (err)
return err;
err = zynq_fpga_poll_timeout(priv, INT_STS_OFFSET, intr_status,
intr_status & IXR_PCFG_DONE_MASK,
INIT_POLL_DELAY,
INIT_POLL_TIMEOUT);
clk_disable(priv->clk);
if (err)
return err;
if (!(flags & FPGA_MGR_PARTIAL_RECONFIG)) {
regmap_write(priv->slcr, SLCR_LVL_SHFTR_EN_OFFSET,
LVL_SHFTR_ENABLE_PL_TO_PS);
regmap_write(priv->slcr, SLCR_FPGA_RST_CTRL_OFFSET,
FPGA_RST_NONE_MASK);
}
return 0;
}
static enum fpga_mgr_states zynq_fpga_ops_state(struct fpga_manager *mgr)
{
int err;
u32 intr_status;
struct zynq_fpga_priv *priv;
priv = mgr->priv;
err = clk_enable(priv->clk);
if (err)
return FPGA_MGR_STATE_UNKNOWN;
intr_status = zynq_fpga_read(priv, INT_STS_OFFSET);
clk_disable(priv->clk);
if (intr_status & IXR_PCFG_DONE_MASK)
return FPGA_MGR_STATE_OPERATING;
return FPGA_MGR_STATE_UNKNOWN;
}
static int zynq_fpga_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct zynq_fpga_priv *priv;
struct resource *res;
int err;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->io_base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->io_base))
return PTR_ERR(priv->io_base);
priv->slcr = syscon_regmap_lookup_by_phandle(dev->of_node,
"syscon");
if (IS_ERR(priv->slcr)) {
dev_err(dev, "unable to get zynq-slcr regmap");
return PTR_ERR(priv->slcr);
}
init_completion(&priv->dma_done);
priv->irq = platform_get_irq(pdev, 0);
if (priv->irq < 0) {
dev_err(dev, "No IRQ available");
return priv->irq;
}
err = devm_request_irq(dev, priv->irq, zynq_fpga_isr, 0,
dev_name(dev), priv);
if (err) {
dev_err(dev, "unable to request IRQ");
return err;
}
priv->clk = devm_clk_get(dev, "ref_clk");
if (IS_ERR(priv->clk)) {
dev_err(dev, "input clock not found");
return PTR_ERR(priv->clk);
}
err = clk_prepare_enable(priv->clk);
if (err) {
dev_err(dev, "unable to enable clock");
return err;
}
zynq_fpga_write(priv, UNLOCK_OFFSET, UNLOCK_MASK);
clk_disable(priv->clk);
err = fpga_mgr_register(dev, "Xilinx Zynq FPGA Manager",
&zynq_fpga_ops, priv);
if (err) {
dev_err(dev, "unable to register FPGA manager");
clk_unprepare(priv->clk);
return err;
}
return 0;
}
static int zynq_fpga_remove(struct platform_device *pdev)
{
struct zynq_fpga_priv *priv;
struct fpga_manager *mgr;
mgr = platform_get_drvdata(pdev);
priv = mgr->priv;
fpga_mgr_unregister(&pdev->dev);
clk_unprepare(priv->clk);
return 0;
}
