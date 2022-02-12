static void tango_cmd_ctrl(struct mtd_info *mtd, int dat, unsigned int ctrl)
{
struct tango_chip *tchip = to_tango_chip(mtd_to_nand(mtd));
if (ctrl & NAND_CLE)
writeb_relaxed(dat, tchip->base + PBUS_CMD);
if (ctrl & NAND_ALE)
writeb_relaxed(dat, tchip->base + PBUS_ADDR);
}
static int tango_dev_ready(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct tango_nfc *nfc = to_tango_nfc(chip->controller);
return readl_relaxed(nfc->pbus_base + PBUS_CS_CTRL) & PBUS_IORDY;
}
static u8 tango_read_byte(struct mtd_info *mtd)
{
struct tango_chip *tchip = to_tango_chip(mtd_to_nand(mtd));
return readb_relaxed(tchip->base + PBUS_DATA);
}
static void tango_read_buf(struct mtd_info *mtd, u8 *buf, int len)
{
struct tango_chip *tchip = to_tango_chip(mtd_to_nand(mtd));
ioread8_rep(tchip->base + PBUS_DATA, buf, len);
}
static void tango_write_buf(struct mtd_info *mtd, const u8 *buf, int len)
{
struct tango_chip *tchip = to_tango_chip(mtd_to_nand(mtd));
iowrite8_rep(tchip->base + PBUS_DATA, buf, len);
}
static void tango_select_chip(struct mtd_info *mtd, int idx)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct tango_nfc *nfc = to_tango_nfc(chip->controller);
struct tango_chip *tchip = to_tango_chip(chip);
if (idx < 0)
return;
writel_relaxed(tchip->timing1, nfc->reg_base + NFC_TIMING1);
writel_relaxed(tchip->timing2, nfc->reg_base + NFC_TIMING2);
writel_relaxed(tchip->xfer_cfg, nfc->reg_base + NFC_XFER_CFG);
writel_relaxed(tchip->pkt_0_cfg, nfc->reg_base + NFC_PKT_0_CFG);
writel_relaxed(tchip->pkt_n_cfg, nfc->reg_base + NFC_PKT_N_CFG);
writel_relaxed(tchip->bb_cfg, nfc->reg_base + NFC_BB_CFG);
}
static int check_erased_page(struct nand_chip *chip, u8 *buf)
{
struct mtd_info *mtd = nand_to_mtd(chip);
u8 *meta = chip->oob_poi + BBM_SIZE;
u8 *ecc = chip->oob_poi + BBM_SIZE + METADATA_SIZE;
const int ecc_size = chip->ecc.bytes;
const int pkt_size = chip->ecc.size;
int i, res, meta_len, bitflips = 0;
for (i = 0; i < chip->ecc.steps; ++i) {
meta_len = i ? 0 : METADATA_SIZE;
res = nand_check_erased_ecc_chunk(buf, pkt_size, ecc, ecc_size,
meta, meta_len,
chip->ecc.strength);
if (res < 0)
mtd->ecc_stats.failed++;
bitflips = max(res, bitflips);
buf += pkt_size;
ecc += ecc_size;
}
return bitflips;
}
static int decode_error_report(struct tango_nfc *nfc)
{
u32 status, res;
status = readl_relaxed(nfc->reg_base + NFC_XFER_STATUS);
if (status & PAGE_IS_EMPTY)
return 0;
res = readl_relaxed(nfc->mem_base + ERROR_REPORT);
if (DECODE_OK_PKT_0(res) && DECODE_OK_PKT_N(res))
return max(ERR_COUNT_PKT_0(res), ERR_COUNT_PKT_N(res));
return -EBADMSG;
}
static void tango_dma_callback(void *arg)
{
complete(arg);
}
static int do_dma(struct tango_nfc *nfc, int dir, int cmd, const void *buf,
int len, int page)
{
void __iomem *addr = nfc->reg_base + NFC_STATUS;
struct dma_chan *chan = nfc->chan;
struct dma_async_tx_descriptor *desc;
struct scatterlist sg;
struct completion tx_done;
int err = -EIO;
u32 res, val;
sg_init_one(&sg, buf, len);
if (dma_map_sg(chan->device->dev, &sg, 1, dir) != 1)
return -EIO;
desc = dmaengine_prep_slave_sg(chan, &sg, 1, dir, DMA_PREP_INTERRUPT);
if (!desc)
goto dma_unmap;
desc->callback = tango_dma_callback;
desc->callback_param = &tx_done;
init_completion(&tx_done);
writel_relaxed(MODE_NFC, nfc->pbus_base + PBUS_PAD_MODE);
writel_relaxed(page, nfc->reg_base + NFC_ADDR_PAGE);
writel_relaxed(0, nfc->reg_base + NFC_ADDR_OFFSET);
writel_relaxed(cmd, nfc->reg_base + NFC_FLASH_CMD);
dmaengine_submit(desc);
dma_async_issue_pending(chan);
res = wait_for_completion_timeout(&tx_done, HZ);
if (res > 0)
err = readl_poll_timeout(addr, val, val & CMD_READY, 0, 1000);
writel_relaxed(MODE_RAW, nfc->pbus_base + PBUS_PAD_MODE);
dma_unmap:
dma_unmap_sg(chan->device->dev, &sg, 1, dir);
return err;
}
static int tango_read_page(struct mtd_info *mtd, struct nand_chip *chip,
u8 *buf, int oob_required, int page)
{
struct tango_nfc *nfc = to_tango_nfc(chip->controller);
int err, res, len = mtd->writesize;
if (oob_required)
chip->ecc.read_oob(mtd, chip, page);
err = do_dma(nfc, DMA_FROM_DEVICE, NFC_READ, buf, len, page);
if (err)
return err;
res = decode_error_report(nfc);
if (res < 0) {
chip->ecc.read_oob_raw(mtd, chip, page);
res = check_erased_page(chip, buf);
}
return res;
}
static int tango_write_page(struct mtd_info *mtd, struct nand_chip *chip,
const u8 *buf, int oob_required, int page)
{
struct tango_nfc *nfc = to_tango_nfc(chip->controller);
int err, len = mtd->writesize;
if (oob_required)
return -ENOTSUPP;
writel_relaxed(0xffffffff, nfc->mem_base + METADATA);
err = do_dma(nfc, DMA_TO_DEVICE, NFC_WRITE, buf, len, page);
if (err)
return err;
return 0;
}
static void aux_read(struct nand_chip *chip, u8 **buf, int len, int *pos)
{
struct mtd_info *mtd = nand_to_mtd(chip);
*pos += len;
if (!*buf) {
chip->cmdfunc(mtd, NAND_CMD_RNDOUT, *pos, -1);
} else {
tango_read_buf(mtd, *buf, len);
*buf += len;
}
}
static void aux_write(struct nand_chip *chip, const u8 **buf, int len, int *pos)
{
struct mtd_info *mtd = nand_to_mtd(chip);
*pos += len;
if (!*buf) {
chip->cmdfunc(mtd, NAND_CMD_SEQIN, *pos, -1);
} else {
tango_write_buf(mtd, *buf, len);
*buf += len;
}
}
static void raw_read(struct nand_chip *chip, u8 *buf, u8 *oob)
{
struct mtd_info *mtd = nand_to_mtd(chip);
u8 *oob_orig = oob;
const int page_size = mtd->writesize;
const int ecc_size = chip->ecc.bytes;
const int pkt_size = chip->ecc.size;
int pos = 0;
int rem = page_size;
if (oob)
oob += BBM_SIZE;
aux_read(chip, &oob, METADATA_SIZE, &pos);
while (rem > pkt_size) {
aux_read(chip, &buf, pkt_size, &pos);
aux_read(chip, &oob, ecc_size, &pos);
rem = page_size - pos;
}
aux_read(chip, &buf, rem, &pos);
aux_read(chip, &oob_orig, BBM_SIZE, &pos);
aux_read(chip, &buf, pkt_size - rem, &pos);
aux_read(chip, &oob, ecc_size, &pos);
}
static void raw_write(struct nand_chip *chip, const u8 *buf, const u8 *oob)
{
struct mtd_info *mtd = nand_to_mtd(chip);
const u8 *oob_orig = oob;
const int page_size = mtd->writesize;
const int ecc_size = chip->ecc.bytes;
const int pkt_size = chip->ecc.size;
int pos = 0;
int rem = page_size;
if (oob)
oob += BBM_SIZE;
aux_write(chip, &oob, METADATA_SIZE, &pos);
while (rem > pkt_size) {
aux_write(chip, &buf, pkt_size, &pos);
aux_write(chip, &oob, ecc_size, &pos);
rem = page_size - pos;
}
aux_write(chip, &buf, rem, &pos);
aux_write(chip, &oob_orig, BBM_SIZE, &pos);
aux_write(chip, &buf, pkt_size - rem, &pos);
aux_write(chip, &oob, ecc_size, &pos);
}
static int tango_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
u8 *buf, int oob_required, int page)
{
chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);
raw_read(chip, buf, chip->oob_poi);
return 0;
}
static int tango_write_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
const u8 *buf, int oob_required, int page)
{
chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0, page);
raw_write(chip, buf, chip->oob_poi);
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
return 0;
}
static int tango_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
chip->cmdfunc(mtd, NAND_CMD_READ0, 0, page);
raw_read(chip, NULL, chip->oob_poi);
return 0;
}
static int tango_write_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
chip->cmdfunc(mtd, NAND_CMD_SEQIN, 0, page);
raw_write(chip, NULL, chip->oob_poi);
chip->cmdfunc(mtd, NAND_CMD_PAGEPROG, -1, -1);
chip->waitfunc(mtd, chip);
return 0;
}
static int oob_ecc(struct mtd_info *mtd, int idx, struct mtd_oob_region *res)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct nand_ecc_ctrl *ecc = &chip->ecc;
if (idx >= ecc->steps)
return -ERANGE;
res->offset = BBM_SIZE + METADATA_SIZE + ecc->bytes * idx;
res->length = ecc->bytes;
return 0;
}
static int oob_free(struct mtd_info *mtd, int idx, struct mtd_oob_region *res)
{
return -ERANGE;
}
static u32 to_ticks(int kHz, int ps)
{
return DIV_ROUND_UP_ULL((u64)kHz * ps, NSEC_PER_SEC);
}
static int tango_set_timings(struct mtd_info *mtd,
const struct nand_data_interface *conf,
bool check_only)
{
const struct nand_sdr_timings *sdr = nand_get_sdr_timings(conf);
struct nand_chip *chip = mtd_to_nand(mtd);
struct tango_nfc *nfc = to_tango_nfc(chip->controller);
struct tango_chip *tchip = to_tango_chip(chip);
u32 Trdy, Textw, Twc, Twpw, Tacc, Thold, Trpw, Textr;
int kHz = nfc->freq_kHz;
if (IS_ERR(sdr))
return PTR_ERR(sdr);
if (check_only)
return 0;
Trdy = to_ticks(kHz, sdr->tCEA_max - sdr->tREA_max);
Textw = to_ticks(kHz, sdr->tWB_max);
Twc = to_ticks(kHz, sdr->tWC_min);
Twpw = to_ticks(kHz, sdr->tWC_min - sdr->tWP_min);
Tacc = to_ticks(kHz, sdr->tREA_max);
Thold = to_ticks(kHz, sdr->tREH_min);
Trpw = to_ticks(kHz, sdr->tRC_min - sdr->tREH_min);
Textr = to_ticks(kHz, sdr->tRHZ_max);
tchip->timing1 = TIMING(Trdy, Textw, Twc, Twpw);
tchip->timing2 = TIMING(Tacc, Thold, Trpw, Textr);
return 0;
}
static int chip_init(struct device *dev, struct device_node *np)
{
u32 cs;
int err, res;
struct mtd_info *mtd;
struct nand_chip *chip;
struct tango_chip *tchip;
struct nand_ecc_ctrl *ecc;
struct tango_nfc *nfc = dev_get_drvdata(dev);
tchip = devm_kzalloc(dev, sizeof(*tchip), GFP_KERNEL);
if (!tchip)
return -ENOMEM;
res = of_property_count_u32_elems(np, "reg");
if (res < 0)
return res;
if (res != 1)
return -ENOTSUPP;
err = of_property_read_u32_index(np, "reg", 0, &cs);
if (err)
return err;
if (cs >= MAX_CS)
return -EINVAL;
chip = &tchip->nand_chip;
ecc = &chip->ecc;
mtd = nand_to_mtd(chip);
chip->read_byte = tango_read_byte;
chip->write_buf = tango_write_buf;
chip->read_buf = tango_read_buf;
chip->select_chip = tango_select_chip;
chip->cmd_ctrl = tango_cmd_ctrl;
chip->dev_ready = tango_dev_ready;
chip->setup_data_interface = tango_set_timings;
chip->options = NAND_USE_BOUNCE_BUFFER |
NAND_NO_SUBPAGE_WRITE |
NAND_WAIT_TCCS;
chip->controller = &nfc->hw;
tchip->base = nfc->pbus_base + (cs * 256);
nand_set_flash_node(chip, np);
mtd_set_ooblayout(mtd, &tango_nand_ooblayout_ops);
mtd->dev.parent = dev;
err = nand_scan_ident(mtd, 1, NULL);
if (err)
return err;
ecc->mode = NAND_ECC_HW;
ecc->algo = NAND_ECC_BCH;
ecc->bytes = DIV_ROUND_UP(ecc->strength * FIELD_ORDER, BITS_PER_BYTE);
ecc->read_page_raw = tango_read_page_raw;
ecc->write_page_raw = tango_write_page_raw;
ecc->read_page = tango_read_page;
ecc->write_page = tango_write_page;
ecc->read_oob = tango_read_oob;
ecc->write_oob = tango_write_oob;
ecc->options = NAND_ECC_CUSTOM_PAGE_ACCESS;
err = nand_scan_tail(mtd);
if (err)
return err;
tchip->xfer_cfg = XFER_CFG(cs, 1, ecc->steps, METADATA_SIZE);
tchip->pkt_0_cfg = PKT_CFG(ecc->size + METADATA_SIZE, ecc->strength);
tchip->pkt_n_cfg = PKT_CFG(ecc->size, ecc->strength);
tchip->bb_cfg = BB_CFG(mtd->writesize, BBM_SIZE);
err = mtd_device_register(mtd, NULL, 0);
if (err)
return err;
nfc->chips[cs] = tchip;
return 0;
}
static int tango_nand_remove(struct platform_device *pdev)
{
int cs;
struct tango_nfc *nfc = platform_get_drvdata(pdev);
dma_release_channel(nfc->chan);
for (cs = 0; cs < MAX_CS; ++cs) {
if (nfc->chips[cs])
nand_release(nand_to_mtd(&nfc->chips[cs]->nand_chip));
}
return 0;
}
static int tango_nand_probe(struct platform_device *pdev)
{
int err;
struct clk *clk;
struct resource *res;
struct tango_nfc *nfc;
struct device_node *np;
nfc = devm_kzalloc(&pdev->dev, sizeof(*nfc), GFP_KERNEL);
if (!nfc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nfc->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(nfc->reg_base))
return PTR_ERR(nfc->reg_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
nfc->mem_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(nfc->mem_base))
return PTR_ERR(nfc->mem_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
nfc->pbus_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(nfc->pbus_base))
return PTR_ERR(nfc->pbus_base);
writel_relaxed(MODE_RAW, nfc->pbus_base + PBUS_PAD_MODE);
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
nfc->chan = dma_request_chan(&pdev->dev, "rxtx");
if (IS_ERR(nfc->chan))
return PTR_ERR(nfc->chan);
platform_set_drvdata(pdev, nfc);
nand_hw_control_init(&nfc->hw);
nfc->freq_kHz = clk_get_rate(clk) / 1000;
for_each_child_of_node(pdev->dev.of_node, np) {
err = chip_init(&pdev->dev, np);
if (err) {
tango_nand_remove(pdev);
return err;
}
}
return 0;
}
