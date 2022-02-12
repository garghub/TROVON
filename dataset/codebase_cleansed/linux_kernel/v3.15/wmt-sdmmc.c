static void wmt_set_sd_power(struct wmt_mci_priv *priv, int enable)
{
u32 reg_tmp = readb(priv->sdmmc_base + SDMMC_BUSMODE);
if (enable ^ priv->power_inverted)
reg_tmp &= ~BM_SD_OFF;
else
reg_tmp |= BM_SD_OFF;
writeb(reg_tmp, priv->sdmmc_base + SDMMC_BUSMODE);
}
static void wmt_mci_read_response(struct mmc_host *mmc)
{
struct wmt_mci_priv *priv;
int idx1, idx2;
u8 tmp_resp;
u32 response;
priv = mmc_priv(mmc);
for (idx1 = 0; idx1 < 4; idx1++) {
response = 0;
for (idx2 = 0; idx2 < 4; idx2++) {
if ((idx1 == 3) && (idx2 == 3))
tmp_resp = readb(priv->sdmmc_base + SDMMC_RSP);
else
tmp_resp = readb(priv->sdmmc_base + SDMMC_RSP +
(idx1*4) + idx2 + 1);
response |= (tmp_resp << (idx2 * 8));
}
priv->cmd->resp[idx1] = cpu_to_be32(response);
}
}
static void wmt_mci_start_command(struct wmt_mci_priv *priv)
{
u32 reg_tmp;
reg_tmp = readb(priv->sdmmc_base + SDMMC_CTLR);
writeb(reg_tmp | CTLR_CMD_START, priv->sdmmc_base + SDMMC_CTLR);
}
static int wmt_mci_send_command(struct mmc_host *mmc, u8 command, u8 cmdtype,
u32 arg, u8 rsptype)
{
struct wmt_mci_priv *priv;
u32 reg_tmp;
priv = mmc_priv(mmc);
writeb(command, priv->sdmmc_base + SDMMC_CMD);
writel(arg, priv->sdmmc_base + SDMMC_ARG);
writeb(rsptype, priv->sdmmc_base + SDMMC_RSPTYPE);
reg_tmp = readb(priv->sdmmc_base + SDMMC_CTLR);
writeb(reg_tmp | CTLR_FIFO_RESET, priv->sdmmc_base + SDMMC_CTLR);
wmt_set_sd_power(priv, WMT_SD_POWER_ON);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS0);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS1);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS2);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS3);
reg_tmp = readb(priv->sdmmc_base + SDMMC_CTLR);
writeb((reg_tmp & 0x0F) | (cmdtype << 4),
priv->sdmmc_base + SDMMC_CTLR);
return 0;
}
static void wmt_mci_disable_dma(struct wmt_mci_priv *priv)
{
writel(DMA_ISR_INT_STS, priv->sdmmc_base + SDDMA_ISR);
writel(0, priv->sdmmc_base + SDDMA_IER);
}
static void wmt_complete_data_request(struct wmt_mci_priv *priv)
{
struct mmc_request *req;
req = priv->req;
req->data->bytes_xfered = req->data->blksz * req->data->blocks;
if (req->data->flags & MMC_DATA_WRITE)
dma_unmap_sg(mmc_dev(priv->mmc), req->data->sg,
req->data->sg_len, DMA_TO_DEVICE);
else
dma_unmap_sg(mmc_dev(priv->mmc), req->data->sg,
req->data->sg_len, DMA_FROM_DEVICE);
if ((req->cmd->error) || (req->data->error))
mmc_request_done(priv->mmc, req);
else {
wmt_mci_read_response(priv->mmc);
if (!req->data->stop) {
mmc_request_done(priv->mmc, req);
} else {
priv->comp_cmd = &priv->cmdcomp;
init_completion(priv->comp_cmd);
priv->cmd = req->data->stop;
wmt_mci_send_command(priv->mmc, req->data->stop->opcode,
7, req->data->stop->arg, 9);
wmt_mci_start_command(priv);
}
}
}
static irqreturn_t wmt_mci_dma_isr(int irq_num, void *data)
{
struct wmt_mci_priv *priv;
int status;
priv = (struct wmt_mci_priv *)data;
status = readl(priv->sdmmc_base + SDDMA_CCR) & 0x0F;
if (status != DMA_CCR_EVT_SUCCESS) {
dev_err(priv->dev, "DMA Error: Status = %d\n", status);
priv->req->data->error = -ETIMEDOUT;
complete(priv->comp_dma);
return IRQ_HANDLED;
}
priv->req->data->error = 0;
wmt_mci_disable_dma(priv);
complete(priv->comp_dma);
if (priv->comp_cmd) {
if (completion_done(priv->comp_cmd)) {
wmt_complete_data_request(priv);
}
}
return IRQ_HANDLED;
}
static irqreturn_t wmt_mci_regular_isr(int irq_num, void *data)
{
struct wmt_mci_priv *priv;
u32 status0;
u32 status1;
u32 status2;
u32 reg_tmp;
int cmd_done;
priv = (struct wmt_mci_priv *)data;
cmd_done = 0;
status0 = readb(priv->sdmmc_base + SDMMC_STS0);
status1 = readb(priv->sdmmc_base + SDMMC_STS1);
status2 = readb(priv->sdmmc_base + SDMMC_STS2);
reg_tmp = readb(priv->sdmmc_base + SDMMC_INTMASK0);
if ((reg_tmp & INT0_DI_INT_EN) && (status0 & STS0_DEVICE_INS)) {
mmc_detect_change(priv->mmc, 0);
if (priv->cmd)
priv->cmd->error = -ETIMEDOUT;
if (priv->comp_cmd)
complete(priv->comp_cmd);
if (priv->comp_dma) {
wmt_mci_disable_dma(priv);
complete(priv->comp_dma);
}
writeb(STS0_DEVICE_INS, priv->sdmmc_base + SDMMC_STS0);
return IRQ_HANDLED;
}
if ((!priv->req->data) ||
((priv->req->data->stop) && (priv->cmd == priv->req->data->stop))) {
if (status1 & STS1_CMDRSP_DONE) {
priv->cmd->error = 0;
cmd_done = 1;
} else if ((status1 & STS1_RSP_TIMEOUT) ||
(status1 & STS1_DATA_TIMEOUT)) {
priv->cmd->error = -ETIMEDOUT;
cmd_done = 1;
}
if (cmd_done) {
priv->comp_cmd = NULL;
if (!priv->cmd->error)
wmt_mci_read_response(priv->mmc);
priv->cmd = NULL;
mmc_request_done(priv->mmc, priv->req);
}
} else {
if (status1 & STS1_CMDRSP_DONE) {
if (priv->cmd)
priv->cmd->error = 0;
if (priv->comp_cmd)
complete(priv->comp_cmd);
}
if ((status1 & STS1_RSP_TIMEOUT) ||
(status1 & STS1_DATA_TIMEOUT)) {
if (priv->cmd)
priv->cmd->error = -ETIMEDOUT;
if (priv->comp_cmd)
complete(priv->comp_cmd);
if (priv->comp_dma) {
wmt_mci_disable_dma(priv);
complete(priv->comp_dma);
}
}
if (priv->comp_dma) {
if (completion_done(priv->comp_dma))
wmt_complete_data_request(priv);
}
}
writeb(status0, priv->sdmmc_base + SDMMC_STS0);
writeb(status1, priv->sdmmc_base + SDMMC_STS1);
writeb(status2, priv->sdmmc_base + SDMMC_STS2);
return IRQ_HANDLED;
}
static void wmt_reset_hardware(struct mmc_host *mmc)
{
struct wmt_mci_priv *priv;
u32 reg_tmp;
priv = mmc_priv(mmc);
reg_tmp = readb(priv->sdmmc_base + SDMMC_BUSMODE);
writeb(reg_tmp | BM_SOFT_RESET, priv->sdmmc_base + SDMMC_BUSMODE);
reg_tmp = readb(priv->sdmmc_base + SDMMC_CTLR);
writeb(reg_tmp | CTLR_FIFO_RESET, priv->sdmmc_base + SDMMC_CTLR);
writew(BLKL_INT_ENABLE | BLKL_GPI_CD, priv->sdmmc_base + SDMMC_BLKLEN);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS0);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS1);
writeb(INT0_CD_INT_EN | INT0_DI_INT_EN, priv->sdmmc_base +
SDMMC_INTMASK0);
writeb(INT1_DATA_TOUT_INT_EN | INT1_CMD_RES_TRAN_DONE_INT_EN |
INT1_CMD_RES_TOUT_INT_EN, priv->sdmmc_base + SDMMC_INTMASK1);
writew(8191, priv->sdmmc_base + SDMMC_DMATIMEOUT);
reg_tmp = readb(priv->sdmmc_base + SDMMC_STS2);
writeb(reg_tmp | STS2_DIS_FORCECLK, priv->sdmmc_base + SDMMC_STS2);
clk_set_rate(priv->clk_sdmmc, 400000);
}
static int wmt_dma_init(struct mmc_host *mmc)
{
struct wmt_mci_priv *priv;
priv = mmc_priv(mmc);
writel(DMA_GCR_SOFT_RESET, priv->sdmmc_base + SDDMA_GCR);
writel(DMA_GCR_DMA_EN, priv->sdmmc_base + SDDMA_GCR);
if ((readl(priv->sdmmc_base + SDDMA_GCR) & DMA_GCR_DMA_EN) != 0)
return 0;
else
return 1;
}
static void wmt_dma_init_descriptor(struct wmt_dma_descriptor *desc,
u16 req_count, u32 buffer_addr, u32 branch_addr, int end)
{
desc->flags = 0x40000000 | req_count;
if (end)
desc->flags |= 0x80000000;
desc->data_buffer_addr = buffer_addr;
desc->branch_addr = branch_addr;
}
static void wmt_dma_config(struct mmc_host *mmc, u32 descaddr, u8 dir)
{
struct wmt_mci_priv *priv;
u32 reg_tmp;
priv = mmc_priv(mmc);
writel(DMA_IER_INT_EN, priv->sdmmc_base + SDDMA_IER);
writel(descaddr, priv->sdmmc_base + SDDMA_DESPR);
writel(0x00, priv->sdmmc_base + SDDMA_CCR);
if (dir == PDMA_WRITE) {
reg_tmp = readl(priv->sdmmc_base + SDDMA_CCR);
writel(reg_tmp & DMA_CCR_IF_TO_PERIPHERAL, priv->sdmmc_base +
SDDMA_CCR);
} else {
reg_tmp = readl(priv->sdmmc_base + SDDMA_CCR);
writel(reg_tmp | DMA_CCR_PERIPHERAL_TO_IF, priv->sdmmc_base +
SDDMA_CCR);
}
}
static void wmt_dma_start(struct wmt_mci_priv *priv)
{
u32 reg_tmp;
reg_tmp = readl(priv->sdmmc_base + SDDMA_CCR);
writel(reg_tmp | DMA_CCR_RUN, priv->sdmmc_base + SDDMA_CCR);
}
static void wmt_mci_request(struct mmc_host *mmc, struct mmc_request *req)
{
struct wmt_mci_priv *priv;
struct wmt_dma_descriptor *desc;
u8 command;
u8 cmdtype;
u32 arg;
u8 rsptype;
u32 reg_tmp;
struct scatterlist *sg;
int i;
int sg_cnt;
int offset;
u32 dma_address;
int desc_cnt;
priv = mmc_priv(mmc);
priv->req = req;
priv->cmd = req->cmd;
command = req->cmd->opcode;
arg = req->cmd->arg;
rsptype = mmc_resp_type(req->cmd);
cmdtype = 0;
if (rsptype == 7)
rsptype = 2;
if (rsptype == 21)
rsptype = 9;
if (!req->data) {
wmt_mci_send_command(mmc, command, cmdtype, arg, rsptype);
wmt_mci_start_command(priv);
}
if (req->data) {
priv->comp_cmd = &priv->cmdcomp;
init_completion(priv->comp_cmd);
wmt_dma_init(mmc);
reg_tmp = readw(priv->sdmmc_base + SDMMC_BLKLEN);
writew((reg_tmp & 0xF800) | (req->data->blksz - 1),
priv->sdmmc_base + SDMMC_BLKLEN);
writew(req->data->blocks, priv->sdmmc_base + SDMMC_BLKCNT);
desc = (struct wmt_dma_descriptor *)priv->dma_desc_buffer;
if (req->data->flags & MMC_DATA_WRITE) {
sg_cnt = dma_map_sg(mmc_dev(mmc), req->data->sg,
req->data->sg_len, DMA_TO_DEVICE);
cmdtype = 1;
if (req->data->blocks > 1)
cmdtype = 3;
} else {
sg_cnt = dma_map_sg(mmc_dev(mmc), req->data->sg,
req->data->sg_len, DMA_FROM_DEVICE);
cmdtype = 2;
if (req->data->blocks > 1)
cmdtype = 4;
}
dma_address = priv->dma_desc_device_addr + 16;
desc_cnt = 0;
for_each_sg(req->data->sg, sg, sg_cnt, i) {
offset = 0;
while (offset < sg_dma_len(sg)) {
wmt_dma_init_descriptor(desc, req->data->blksz,
sg_dma_address(sg)+offset,
dma_address, 0);
desc++;
desc_cnt++;
offset += req->data->blksz;
dma_address += 16;
if (desc_cnt == req->data->blocks)
break;
}
}
desc--;
desc->flags |= 0x80000000;
if (req->data->flags & MMC_DATA_WRITE)
wmt_dma_config(mmc, priv->dma_desc_device_addr,
PDMA_WRITE);
else
wmt_dma_config(mmc, priv->dma_desc_device_addr,
PDMA_READ);
wmt_mci_send_command(mmc, command, cmdtype, arg, rsptype);
priv->comp_dma = &priv->datacomp;
init_completion(priv->comp_dma);
wmt_dma_start(priv);
wmt_mci_start_command(priv);
}
}
static void wmt_mci_set_ios(struct mmc_host *mmc, struct mmc_ios *ios)
{
struct wmt_mci_priv *priv;
u32 reg_tmp;
priv = mmc_priv(mmc);
if (ios->power_mode == MMC_POWER_UP) {
wmt_reset_hardware(mmc);
wmt_set_sd_power(priv, WMT_SD_POWER_ON);
}
if (ios->power_mode == MMC_POWER_OFF)
wmt_set_sd_power(priv, WMT_SD_POWER_OFF);
if (ios->clock != 0)
clk_set_rate(priv->clk_sdmmc, ios->clock);
switch (ios->bus_width) {
case MMC_BUS_WIDTH_8:
reg_tmp = readb(priv->sdmmc_base + SDMMC_EXTCTRL);
writeb(reg_tmp | 0x04, priv->sdmmc_base + SDMMC_EXTCTRL);
break;
case MMC_BUS_WIDTH_4:
reg_tmp = readb(priv->sdmmc_base + SDMMC_BUSMODE);
writeb(reg_tmp | BM_FOURBIT_MODE, priv->sdmmc_base +
SDMMC_BUSMODE);
reg_tmp = readb(priv->sdmmc_base + SDMMC_EXTCTRL);
writeb(reg_tmp & 0xFB, priv->sdmmc_base + SDMMC_EXTCTRL);
break;
case MMC_BUS_WIDTH_1:
reg_tmp = readb(priv->sdmmc_base + SDMMC_BUSMODE);
writeb(reg_tmp & BM_ONEBIT_MASK, priv->sdmmc_base +
SDMMC_BUSMODE);
reg_tmp = readb(priv->sdmmc_base + SDMMC_EXTCTRL);
writeb(reg_tmp & 0xFB, priv->sdmmc_base + SDMMC_EXTCTRL);
break;
}
}
static int wmt_mci_get_ro(struct mmc_host *mmc)
{
struct wmt_mci_priv *priv = mmc_priv(mmc);
return !(readb(priv->sdmmc_base + SDMMC_STS0) & STS0_WRITE_PROTECT);
}
static int wmt_mci_get_cd(struct mmc_host *mmc)
{
struct wmt_mci_priv *priv = mmc_priv(mmc);
u32 cd = (readb(priv->sdmmc_base + SDMMC_STS0) & STS0_CD_GPI) >> 3;
return !(cd ^ priv->cd_inverted);
}
static int wmt_mci_probe(struct platform_device *pdev)
{
struct mmc_host *mmc;
struct wmt_mci_priv *priv;
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(wmt_mci_dt_ids, &pdev->dev);
const struct wmt_mci_caps *wmt_caps;
int ret;
int regular_irq, dma_irq;
if (!of_id || !of_id->data) {
dev_err(&pdev->dev, "Controller capabilities data missing\n");
return -EFAULT;
}
wmt_caps = of_id->data;
if (!np) {
dev_err(&pdev->dev, "Missing SDMMC description in devicetree\n");
return -EFAULT;
}
regular_irq = irq_of_parse_and_map(np, 0);
dma_irq = irq_of_parse_and_map(np, 1);
if (!regular_irq || !dma_irq) {
dev_err(&pdev->dev, "Getting IRQs failed!\n");
ret = -ENXIO;
goto fail1;
}
mmc = mmc_alloc_host(sizeof(struct wmt_mci_priv), &pdev->dev);
if (!mmc) {
dev_err(&pdev->dev, "Failed to allocate mmc_host\n");
ret = -ENOMEM;
goto fail1;
}
mmc->ops = &wmt_mci_ops;
mmc->f_min = wmt_caps->f_min;
mmc->f_max = wmt_caps->f_max;
mmc->ocr_avail = wmt_caps->ocr_avail;
mmc->caps = wmt_caps->caps;
mmc->max_seg_size = wmt_caps->max_seg_size;
mmc->max_segs = wmt_caps->max_segs;
mmc->max_blk_size = wmt_caps->max_blk_size;
mmc->max_req_size = (16*512*mmc->max_segs);
mmc->max_blk_count = mmc->max_req_size / 512;
priv = mmc_priv(mmc);
priv->mmc = mmc;
priv->dev = &pdev->dev;
priv->power_inverted = 0;
priv->cd_inverted = 0;
if (of_get_property(np, "sdon-inverted", NULL))
priv->power_inverted = 1;
if (of_get_property(np, "cd-inverted", NULL))
priv->cd_inverted = 1;
priv->sdmmc_base = of_iomap(np, 0);
if (!priv->sdmmc_base) {
dev_err(&pdev->dev, "Failed to map IO space\n");
ret = -ENOMEM;
goto fail2;
}
priv->irq_regular = regular_irq;
priv->irq_dma = dma_irq;
ret = request_irq(regular_irq, wmt_mci_regular_isr, 0, "sdmmc", priv);
if (ret) {
dev_err(&pdev->dev, "Register regular IRQ fail\n");
goto fail3;
}
ret = request_irq(dma_irq, wmt_mci_dma_isr, 32, "sdmmc", priv);
if (ret) {
dev_err(&pdev->dev, "Register DMA IRQ fail\n");
goto fail4;
}
priv->dma_desc_buffer = dma_alloc_coherent(&pdev->dev,
mmc->max_blk_count * 16,
&priv->dma_desc_device_addr,
208);
if (!priv->dma_desc_buffer) {
dev_err(&pdev->dev, "DMA alloc fail\n");
ret = -EPERM;
goto fail5;
}
platform_set_drvdata(pdev, mmc);
priv->clk_sdmmc = of_clk_get(np, 0);
if (IS_ERR(priv->clk_sdmmc)) {
dev_err(&pdev->dev, "Error getting clock\n");
ret = PTR_ERR(priv->clk_sdmmc);
goto fail5;
}
clk_prepare_enable(priv->clk_sdmmc);
wmt_reset_hardware(mmc);
mmc_add_host(mmc);
dev_info(&pdev->dev, "WMT SDHC Controller initialized\n");
return 0;
fail5:
free_irq(dma_irq, priv);
fail4:
free_irq(regular_irq, priv);
fail3:
iounmap(priv->sdmmc_base);
fail2:
mmc_free_host(mmc);
fail1:
return ret;
}
static int wmt_mci_remove(struct platform_device *pdev)
{
struct mmc_host *mmc;
struct wmt_mci_priv *priv;
struct resource *res;
u32 reg_tmp;
mmc = platform_get_drvdata(pdev);
priv = mmc_priv(mmc);
reg_tmp = readb(priv->sdmmc_base + SDMMC_BUSMODE);
writel(reg_tmp | BM_SOFT_RESET, priv->sdmmc_base + SDMMC_BUSMODE);
reg_tmp = readw(priv->sdmmc_base + SDMMC_BLKLEN);
writew(reg_tmp & ~(0xA000), priv->sdmmc_base + SDMMC_BLKLEN);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS0);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS1);
dma_free_coherent(&pdev->dev, priv->mmc->max_blk_count * 16,
priv->dma_desc_buffer, priv->dma_desc_device_addr);
mmc_remove_host(mmc);
free_irq(priv->irq_regular, priv);
free_irq(priv->irq_dma, priv);
iounmap(priv->sdmmc_base);
clk_disable_unprepare(priv->clk_sdmmc);
clk_put(priv->clk_sdmmc);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
mmc_free_host(mmc);
dev_info(&pdev->dev, "WMT MCI device removed\n");
return 0;
}
static int wmt_mci_suspend(struct device *dev)
{
u32 reg_tmp;
struct platform_device *pdev = to_platform_device(dev);
struct mmc_host *mmc = platform_get_drvdata(pdev);
struct wmt_mci_priv *priv;
if (!mmc)
return 0;
priv = mmc_priv(mmc);
reg_tmp = readb(priv->sdmmc_base + SDMMC_BUSMODE);
writeb(reg_tmp | BM_SOFT_RESET, priv->sdmmc_base +
SDMMC_BUSMODE);
reg_tmp = readw(priv->sdmmc_base + SDMMC_BLKLEN);
writew(reg_tmp & 0x5FFF, priv->sdmmc_base + SDMMC_BLKLEN);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS0);
writeb(0xFF, priv->sdmmc_base + SDMMC_STS1);
clk_disable(priv->clk_sdmmc);
return 0;
}
static int wmt_mci_resume(struct device *dev)
{
u32 reg_tmp;
struct platform_device *pdev = to_platform_device(dev);
struct mmc_host *mmc = platform_get_drvdata(pdev);
struct wmt_mci_priv *priv;
if (mmc) {
priv = mmc_priv(mmc);
clk_enable(priv->clk_sdmmc);
reg_tmp = readb(priv->sdmmc_base + SDMMC_BUSMODE);
writeb(reg_tmp | BM_SOFT_RESET, priv->sdmmc_base +
SDMMC_BUSMODE);
reg_tmp = readw(priv->sdmmc_base + SDMMC_BLKLEN);
writew(reg_tmp | (BLKL_GPI_CD | BLKL_INT_ENABLE),
priv->sdmmc_base + SDMMC_BLKLEN);
reg_tmp = readb(priv->sdmmc_base + SDMMC_INTMASK0);
writeb(reg_tmp | INT0_DI_INT_EN, priv->sdmmc_base +
SDMMC_INTMASK0);
}
return 0;
}
