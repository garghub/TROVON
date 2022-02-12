static void mtk_desc_ring_link(struct mtk_cryp *cryp, u32 mask)
{
writel(MTK_DFSE_THR_CTRL_EN | mask, cryp->base + DFE_THR_CTRL);
writel(MTK_DFSE_THR_CTRL_EN | mask, cryp->base + DSE_THR_CTRL);
}
static void mtk_dfe_dse_buf_setup(struct mtk_cryp *cryp,
struct mtk_sys_cap *cap)
{
u32 width = MTK_HIA_DATA_WIDTH(cap->hia_opt) + 2;
u32 len = MTK_HIA_DMA_LENGTH(cap->hia_opt) - 1;
u32 ipbuf = min((u32)MTK_IN_DBUF_SIZE(cap->hw_opt) + width, len);
u32 opbuf = min((u32)MTK_OUT_DBUF_SIZE(cap->hw_opt) + width, len);
u32 itbuf = min((u32)MTK_IN_TBUF_SIZE(cap->hw_opt) + width, len);
writel(MTK_DFSE_MIN_DATA(ipbuf - 1) |
MTK_DFSE_MAX_DATA(ipbuf) |
MTK_DFE_MIN_CTRL(itbuf - 1) |
MTK_DFE_MAX_CTRL(itbuf),
cryp->base + DFE_CFG);
writel(MTK_DFSE_MIN_DATA(opbuf - 1) |
MTK_DFSE_MAX_DATA(opbuf),
cryp->base + DSE_CFG);
writel(MTK_IN_BUF_MIN_THRESH(ipbuf - 1) |
MTK_IN_BUF_MAX_THRESH(ipbuf),
cryp->base + PE_IN_DBUF_THRESH);
writel(MTK_IN_BUF_MIN_THRESH(itbuf - 1) |
MTK_IN_BUF_MAX_THRESH(itbuf),
cryp->base + PE_IN_TBUF_THRESH);
writel(MTK_OUT_BUF_MIN_THRESH(opbuf - 1) |
MTK_OUT_BUF_MAX_THRESH(opbuf),
cryp->base + PE_OUT_DBUF_THRESH);
writel(0, cryp->base + PE_OUT_TBUF_THRESH);
writel(0, cryp->base + PE_OUT_BUF_CTRL);
}
static int mtk_dfe_dse_state_check(struct mtk_cryp *cryp)
{
int ret = -EINVAL;
u32 val;
val = readl(cryp->base + DFE_THR_STAT);
if (MTK_DFSE_RING_ID(val) == MTK_DFSE_IDLE) {
val = readl(cryp->base + DSE_THR_STAT);
if (MTK_DFSE_RING_ID(val) == MTK_DFSE_IDLE)
ret = 0;
}
if (!ret) {
writel(0, cryp->base + DFE_THR_CTRL);
writel(0, cryp->base + DSE_THR_CTRL);
} else {
return -EBUSY;
}
return 0;
}
static int mtk_dfe_dse_reset(struct mtk_cryp *cryp)
{
int err;
writel(MTK_DFSE_THR_CTRL_RESET, cryp->base + DFE_THR_CTRL);
writel(0, cryp->base + DFE_PRIO_0);
writel(0, cryp->base + DFE_PRIO_1);
writel(0, cryp->base + DFE_PRIO_2);
writel(0, cryp->base + DFE_PRIO_3);
writel(MTK_DFSE_THR_CTRL_RESET, cryp->base + DSE_THR_CTRL);
writel(0, cryp->base + DSE_PRIO_0);
writel(0, cryp->base + DSE_PRIO_1);
writel(0, cryp->base + DSE_PRIO_2);
writel(0, cryp->base + DSE_PRIO_3);
err = mtk_dfe_dse_state_check(cryp);
if (err)
return err;
return 0;
}
static void mtk_cmd_desc_ring_setup(struct mtk_cryp *cryp,
int i, struct mtk_sys_cap *cap)
{
u32 count =
((1 << MTK_CMD_FIFO_SIZE(cap->hia_opt)) / MTK_DESC_SZ) - 1;
writel(0, cryp->base + CDR_CFG(i));
writel(MTK_CNT_RST, cryp->base + CDR_PREP_COUNT(i));
writel(MTK_CNT_RST, cryp->base + CDR_PROC_COUNT(i));
writel(0, cryp->base + CDR_PREP_PNTR(i));
writel(0, cryp->base + CDR_PROC_PNTR(i));
writel(0, cryp->base + CDR_DMA_CFG(i));
writel(0, cryp->base + CDR_BASE_ADDR_HI(i));
writel(cryp->ring[i]->cmd_dma, cryp->base + CDR_BASE_ADDR_LO(i));
writel(MTK_DESC_RING_SZ, cryp->base + CDR_RING_SIZE(i));
writel(MTK_CDR_STAT_CLR, cryp->base + CDR_STAT(i));
writel(MTK_DESC_SIZE(MTK_DESC_SZ) |
MTK_DESC_OFFSET(MTK_DESC_OFF) |
MTK_DESC_ATP_PRESENT,
cryp->base + CDR_DESC_SIZE(i));
writel(MTK_DESC_FETCH_SIZE(count * MTK_DESC_OFF) |
MTK_DESC_FETCH_THRESH(count * MTK_DESC_SZ),
cryp->base + CDR_CFG(i));
}
static void mtk_res_desc_ring_setup(struct mtk_cryp *cryp,
int i, struct mtk_sys_cap *cap)
{
u32 rndup = 2;
u32 count = ((1 << MTK_RES_FIFO_SIZE(cap->hia_opt)) / rndup) - 1;
writel(0, cryp->base + RDR_CFG(i));
writel(MTK_CNT_RST, cryp->base + RDR_PREP_COUNT(i));
writel(MTK_CNT_RST, cryp->base + RDR_PROC_COUNT(i));
writel(0, cryp->base + RDR_PREP_PNTR(i));
writel(0, cryp->base + RDR_PROC_PNTR(i));
writel(0, cryp->base + RDR_DMA_CFG(i));
writel(0, cryp->base + RDR_BASE_ADDR_HI(i));
writel(cryp->ring[i]->res_dma, cryp->base + RDR_BASE_ADDR_LO(i));
writel(MTK_DESC_RING_SZ, cryp->base + RDR_RING_SIZE(i));
writel(MTK_RDR_STAT_CLR, cryp->base + RDR_STAT(i));
writel(MTK_RDR_PROC_THRESH | MTK_RDR_PROC_MODE,
cryp->base + RDR_THRESH(i));
writel(MTK_DESC_SIZE(MTK_DESC_SZ) | MTK_DESC_OFFSET(MTK_DESC_OFF),
cryp->base + RDR_DESC_SIZE(i));
writel(MTK_DESC_FETCH_SIZE(count * MTK_DESC_OFF) |
MTK_DESC_FETCH_THRESH(count * rndup) |
MTK_DESC_OVL_IRQ_EN,
cryp->base + RDR_CFG(i));
}
static int mtk_packet_engine_setup(struct mtk_cryp *cryp)
{
struct mtk_sys_cap cap;
int i, err;
u32 val;
cap.hia_ver = readl(cryp->base + HIA_VERSION);
cap.hia_opt = readl(cryp->base + HIA_OPTIONS);
cap.hw_opt = readl(cryp->base + EIP97_OPTIONS);
if (!(((u16)cap.hia_ver) == MTK_HIA_SIGNATURE))
return -EINVAL;
writel(0, cryp->base + EIP97_MST_CTRL);
val = readl(cryp->base + HIA_MST_CTRL);
val &= ~MTK_BURST_SIZE_MSK;
val |= MTK_BURST_SIZE(5);
writel(val, cryp->base + HIA_MST_CTRL);
err = mtk_dfe_dse_reset(cryp);
if (err) {
dev_err(cryp->dev, "Failed to reset DFE and DSE.\n");
return err;
}
mtk_dfe_dse_buf_setup(cryp, &cap);
mtk_desc_ring_link(cryp, 0xf);
for (i = 0; i < MTK_RING_MAX; i++) {
mtk_cmd_desc_ring_setup(cryp, i, &cap);
mtk_res_desc_ring_setup(cryp, i, &cap);
}
writel(MTK_PE_TK_LOC_AVL | MTK_PE_PROC_HELD | MTK_PE_TK_TIMEOUT_EN,
cryp->base + PE_TOKEN_CTRL_STAT);
writel(MTK_AIC_G_CLR, cryp->base + AIC_G_ACK);
writel(MTK_PE_INPUT_DMA_ERR | MTK_PE_OUTPUT_DMA_ERR |
MTK_PE_PKT_PORC_ERR | MTK_PE_PKT_TIMEOUT |
MTK_PE_FATAL_ERR | MTK_PE_INPUT_DMA_ERR_EN |
MTK_PE_OUTPUT_DMA_ERR_EN | MTK_PE_PKT_PORC_ERR_EN |
MTK_PE_PKT_TIMEOUT_EN | MTK_PE_FATAL_ERR_EN |
MTK_PE_INT_OUT_EN,
cryp->base + PE_INTERRUPT_CTRL_STAT);
return 0;
}
static int mtk_aic_cap_check(struct mtk_cryp *cryp, int hw)
{
u32 val;
if (hw == MTK_RING_MAX)
val = readl(cryp->base + AIC_G_VERSION);
else
val = readl(cryp->base + AIC_VERSION(hw));
val &= MTK_AIC_VER_MSK;
if (val != MTK_AIC_VER11 && val != MTK_AIC_VER12)
return -ENXIO;
if (hw == MTK_RING_MAX)
val = readl(cryp->base + AIC_G_OPTIONS);
else
val = readl(cryp->base + AIC_OPTIONS(hw));
val &= MTK_AIC_INT_MSK;
if (!val || val > 32)
return -ENXIO;
return 0;
}
static int mtk_aic_init(struct mtk_cryp *cryp, int hw)
{
int err;
err = mtk_aic_cap_check(cryp, hw);
if (err)
return err;
if (hw == MTK_RING_MAX) {
writel(0, cryp->base + AIC_G_ENABLE_CTRL);
writel(0, cryp->base + AIC_G_POL_CTRL);
writel(0, cryp->base + AIC_G_TYPE_CTRL);
writel(0, cryp->base + AIC_G_ENABLE_SET);
} else {
writel(0, cryp->base + AIC_ENABLE_CTRL(hw));
writel(0, cryp->base + AIC_POL_CTRL(hw));
writel(0, cryp->base + AIC_TYPE_CTRL(hw));
writel(0, cryp->base + AIC_ENABLE_SET(hw));
}
return 0;
}
static int mtk_accelerator_init(struct mtk_cryp *cryp)
{
int i, err;
for (i = 0; i < MTK_IRQ_NUM; i++) {
err = mtk_aic_init(cryp, i);
if (err) {
dev_err(cryp->dev, "Failed to initialize AIC.\n");
return err;
}
}
err = mtk_packet_engine_setup(cryp);
if (err) {
dev_err(cryp->dev, "Failed to configure packet engine.\n");
return err;
}
return 0;
}
static void mtk_desc_dma_free(struct mtk_cryp *cryp)
{
int i;
for (i = 0; i < MTK_RING_MAX; i++) {
dma_free_coherent(cryp->dev, MTK_DESC_RING_SZ,
cryp->ring[i]->res_base,
cryp->ring[i]->res_dma);
dma_free_coherent(cryp->dev, MTK_DESC_RING_SZ,
cryp->ring[i]->cmd_base,
cryp->ring[i]->cmd_dma);
kfree(cryp->ring[i]);
}
}
static int mtk_desc_ring_alloc(struct mtk_cryp *cryp)
{
struct mtk_ring **ring = cryp->ring;
int i, err = ENOMEM;
for (i = 0; i < MTK_RING_MAX; i++) {
ring[i] = kzalloc(sizeof(**ring), GFP_KERNEL);
if (!ring[i])
goto err_cleanup;
ring[i]->cmd_base = dma_zalloc_coherent(cryp->dev,
MTK_DESC_RING_SZ,
&ring[i]->cmd_dma,
GFP_KERNEL);
if (!ring[i]->cmd_base)
goto err_cleanup;
ring[i]->res_base = dma_zalloc_coherent(cryp->dev,
MTK_DESC_RING_SZ,
&ring[i]->res_dma,
GFP_KERNEL);
if (!ring[i]->res_base)
goto err_cleanup;
ring[i]->cmd_next = ring[i]->cmd_base;
ring[i]->res_next = ring[i]->res_base;
}
return 0;
err_cleanup:
for (; i--; ) {
dma_free_coherent(cryp->dev, MTK_DESC_RING_SZ,
ring[i]->res_base, ring[i]->res_dma);
dma_free_coherent(cryp->dev, MTK_DESC_RING_SZ,
ring[i]->cmd_base, ring[i]->cmd_dma);
kfree(ring[i]);
}
return err;
}
static int mtk_crypto_probe(struct platform_device *pdev)
{
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct mtk_cryp *cryp;
int i, err;
cryp = devm_kzalloc(&pdev->dev, sizeof(*cryp), GFP_KERNEL);
if (!cryp)
return -ENOMEM;
cryp->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(cryp->base))
return PTR_ERR(cryp->base);
for (i = 0; i < MTK_IRQ_NUM; i++) {
cryp->irq[i] = platform_get_irq(pdev, i);
if (cryp->irq[i] < 0) {
dev_err(cryp->dev, "no IRQ:%d resource info\n", i);
return -ENXIO;
}
}
cryp->clk_cryp = devm_clk_get(&pdev->dev, "cryp");
if (IS_ERR(cryp->clk_cryp))
return -EPROBE_DEFER;
cryp->dev = &pdev->dev;
pm_runtime_enable(cryp->dev);
pm_runtime_get_sync(cryp->dev);
err = clk_prepare_enable(cryp->clk_cryp);
if (err)
goto err_clk_cryp;
err = mtk_desc_ring_alloc(cryp);
if (err) {
dev_err(cryp->dev, "Unable to allocate descriptor rings.\n");
goto err_resource;
}
err = mtk_accelerator_init(cryp);
if (err) {
dev_err(cryp->dev, "Failed to initialize cryptographic engine.\n");
goto err_engine;
}
err = mtk_cipher_alg_register(cryp);
if (err) {
dev_err(cryp->dev, "Unable to register cipher algorithm.\n");
goto err_cipher;
}
err = mtk_hash_alg_register(cryp);
if (err) {
dev_err(cryp->dev, "Unable to register hash algorithm.\n");
goto err_hash;
}
platform_set_drvdata(pdev, cryp);
return 0;
err_hash:
mtk_cipher_alg_release(cryp);
err_cipher:
mtk_dfe_dse_reset(cryp);
err_engine:
mtk_desc_dma_free(cryp);
err_resource:
clk_disable_unprepare(cryp->clk_cryp);
err_clk_cryp:
pm_runtime_put_sync(cryp->dev);
pm_runtime_disable(cryp->dev);
return err;
}
static int mtk_crypto_remove(struct platform_device *pdev)
{
struct mtk_cryp *cryp = platform_get_drvdata(pdev);
mtk_hash_alg_release(cryp);
mtk_cipher_alg_release(cryp);
mtk_desc_dma_free(cryp);
clk_disable_unprepare(cryp->clk_cryp);
pm_runtime_put_sync(cryp->dev);
pm_runtime_disable(cryp->dev);
platform_set_drvdata(pdev, NULL);
return 0;
}
