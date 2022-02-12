static int fsmc_ecc1_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (section >= chip->ecc.steps)
return -ERANGE;
oobregion->offset = (section * 16) + 2;
oobregion->length = 3;
return 0;
}
static int fsmc_ecc1_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (section >= chip->ecc.steps)
return -ERANGE;
oobregion->offset = (section * 16) + 8;
if (section < chip->ecc.steps - 1)
oobregion->length = 8;
else
oobregion->length = mtd->oobsize - oobregion->offset;
return 0;
}
static int fsmc_ecc4_ooblayout_ecc(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (section >= chip->ecc.steps)
return -ERANGE;
oobregion->length = chip->ecc.bytes;
if (!section && mtd->writesize <= 512)
oobregion->offset = 0;
else
oobregion->offset = (section * 16) + 2;
return 0;
}
static int fsmc_ecc4_ooblayout_free(struct mtd_info *mtd, int section,
struct mtd_oob_region *oobregion)
{
struct nand_chip *chip = mtd_to_nand(mtd);
if (section >= chip->ecc.steps)
return -ERANGE;
oobregion->offset = (section * 16) + 15;
if (section < chip->ecc.steps - 1)
oobregion->length = 3;
else
oobregion->length = mtd->oobsize - oobregion->offset;
return 0;
}
static inline struct fsmc_nand_data *mtd_to_fsmc(struct mtd_info *mtd)
{
return container_of(mtd_to_nand(mtd), struct fsmc_nand_data, nand);
}
static void fsmc_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *this = mtd_to_nand(mtd);
struct fsmc_nand_data *host = mtd_to_fsmc(mtd);
void __iomem *regs = host->regs_va;
unsigned int bank = host->bank;
if (ctrl & NAND_CTRL_CHANGE) {
u32 pc;
if (ctrl & NAND_CLE) {
this->IO_ADDR_R = host->cmd_va;
this->IO_ADDR_W = host->cmd_va;
} else if (ctrl & NAND_ALE) {
this->IO_ADDR_R = host->addr_va;
this->IO_ADDR_W = host->addr_va;
} else {
this->IO_ADDR_R = host->data_va;
this->IO_ADDR_W = host->data_va;
}
pc = readl(FSMC_NAND_REG(regs, bank, PC));
if (ctrl & NAND_NCE)
pc |= FSMC_ENABLE;
else
pc &= ~FSMC_ENABLE;
writel_relaxed(pc, FSMC_NAND_REG(regs, bank, PC));
}
mb();
if (cmd != NAND_CMD_NONE)
writeb_relaxed(cmd, this->IO_ADDR_W);
}
static void fsmc_nand_setup(struct fsmc_nand_data *host,
struct fsmc_nand_timings *tims)
{
uint32_t value = FSMC_DEVTYPE_NAND | FSMC_ENABLE | FSMC_WAITON;
uint32_t tclr, tar, thiz, thold, twait, tset;
unsigned int bank = host->bank;
void __iomem *regs = host->regs_va;
tclr = (tims->tclr & FSMC_TCLR_MASK) << FSMC_TCLR_SHIFT;
tar = (tims->tar & FSMC_TAR_MASK) << FSMC_TAR_SHIFT;
thiz = (tims->thiz & FSMC_THIZ_MASK) << FSMC_THIZ_SHIFT;
thold = (tims->thold & FSMC_THOLD_MASK) << FSMC_THOLD_SHIFT;
twait = (tims->twait & FSMC_TWAIT_MASK) << FSMC_TWAIT_SHIFT;
tset = (tims->tset & FSMC_TSET_MASK) << FSMC_TSET_SHIFT;
if (host->nand.options & NAND_BUSWIDTH_16)
writel_relaxed(value | FSMC_DEVWID_16,
FSMC_NAND_REG(regs, bank, PC));
else
writel_relaxed(value | FSMC_DEVWID_8,
FSMC_NAND_REG(regs, bank, PC));
writel_relaxed(readl(FSMC_NAND_REG(regs, bank, PC)) | tclr | tar,
FSMC_NAND_REG(regs, bank, PC));
writel_relaxed(thiz | thold | twait | tset,
FSMC_NAND_REG(regs, bank, COMM));
writel_relaxed(thiz | thold | twait | tset,
FSMC_NAND_REG(regs, bank, ATTRIB));
}
static int fsmc_calc_timings(struct fsmc_nand_data *host,
const struct nand_sdr_timings *sdrt,
struct fsmc_nand_timings *tims)
{
unsigned long hclk = clk_get_rate(host->clk);
unsigned long hclkn = NSEC_PER_SEC / hclk;
uint32_t thiz, thold, twait, tset;
if (sdrt->tRC_min < 30000)
return -EOPNOTSUPP;
tims->tar = DIV_ROUND_UP(sdrt->tAR_min / 1000, hclkn) - 1;
if (tims->tar > FSMC_TAR_MASK)
tims->tar = FSMC_TAR_MASK;
tims->tclr = DIV_ROUND_UP(sdrt->tCLR_min / 1000, hclkn) - 1;
if (tims->tclr > FSMC_TCLR_MASK)
tims->tclr = FSMC_TCLR_MASK;
thiz = sdrt->tCS_min - sdrt->tWP_min;
tims->thiz = DIV_ROUND_UP(thiz / 1000, hclkn);
thold = sdrt->tDH_min;
if (thold < sdrt->tCH_min)
thold = sdrt->tCH_min;
if (thold < sdrt->tCLH_min)
thold = sdrt->tCLH_min;
if (thold < sdrt->tWH_min)
thold = sdrt->tWH_min;
if (thold < sdrt->tALH_min)
thold = sdrt->tALH_min;
if (thold < sdrt->tREH_min)
thold = sdrt->tREH_min;
tims->thold = DIV_ROUND_UP(thold / 1000, hclkn);
if (tims->thold == 0)
tims->thold = 1;
else if (tims->thold > FSMC_THOLD_MASK)
tims->thold = FSMC_THOLD_MASK;
twait = max(sdrt->tRP_min, sdrt->tWP_min);
tims->twait = DIV_ROUND_UP(twait / 1000, hclkn) - 1;
if (tims->twait == 0)
tims->twait = 1;
else if (tims->twait > FSMC_TWAIT_MASK)
tims->twait = FSMC_TWAIT_MASK;
tset = max(sdrt->tCS_min - sdrt->tWP_min,
sdrt->tCEA_max - sdrt->tREA_max);
tims->tset = DIV_ROUND_UP(tset / 1000, hclkn) - 1;
if (tims->tset == 0)
tims->tset = 1;
else if (tims->tset > FSMC_TSET_MASK)
tims->tset = FSMC_TSET_MASK;
return 0;
}
static int fsmc_setup_data_interface(struct mtd_info *mtd, int csline,
const struct nand_data_interface *conf)
{
struct nand_chip *nand = mtd_to_nand(mtd);
struct fsmc_nand_data *host = nand_get_controller_data(nand);
struct fsmc_nand_timings tims;
const struct nand_sdr_timings *sdrt;
int ret;
sdrt = nand_get_sdr_timings(conf);
if (IS_ERR(sdrt))
return PTR_ERR(sdrt);
ret = fsmc_calc_timings(host, sdrt, &tims);
if (ret)
return ret;
if (csline == NAND_DATA_IFACE_CHECK_ONLY)
return 0;
fsmc_nand_setup(host, &tims);
return 0;
}
static void fsmc_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct fsmc_nand_data *host = mtd_to_fsmc(mtd);
void __iomem *regs = host->regs_va;
uint32_t bank = host->bank;
writel_relaxed(readl(FSMC_NAND_REG(regs, bank, PC)) & ~FSMC_ECCPLEN_256,
FSMC_NAND_REG(regs, bank, PC));
writel_relaxed(readl(FSMC_NAND_REG(regs, bank, PC)) & ~FSMC_ECCEN,
FSMC_NAND_REG(regs, bank, PC));
writel_relaxed(readl(FSMC_NAND_REG(regs, bank, PC)) | FSMC_ECCEN,
FSMC_NAND_REG(regs, bank, PC));
}
static int fsmc_read_hwecc_ecc4(struct mtd_info *mtd, const uint8_t *data,
uint8_t *ecc)
{
struct fsmc_nand_data *host = mtd_to_fsmc(mtd);
void __iomem *regs = host->regs_va;
uint32_t bank = host->bank;
uint32_t ecc_tmp;
unsigned long deadline = jiffies + FSMC_BUSY_WAIT_TIMEOUT;
do {
if (readl_relaxed(FSMC_NAND_REG(regs, bank, STS)) & FSMC_CODE_RDY)
break;
else
cond_resched();
} while (!time_after_eq(jiffies, deadline));
if (time_after_eq(jiffies, deadline)) {
dev_err(host->dev, "calculate ecc timed out\n");
return -ETIMEDOUT;
}
ecc_tmp = readl_relaxed(FSMC_NAND_REG(regs, bank, ECC1));
ecc[0] = (uint8_t) (ecc_tmp >> 0);
ecc[1] = (uint8_t) (ecc_tmp >> 8);
ecc[2] = (uint8_t) (ecc_tmp >> 16);
ecc[3] = (uint8_t) (ecc_tmp >> 24);
ecc_tmp = readl_relaxed(FSMC_NAND_REG(regs, bank, ECC2));
ecc[4] = (uint8_t) (ecc_tmp >> 0);
ecc[5] = (uint8_t) (ecc_tmp >> 8);
ecc[6] = (uint8_t) (ecc_tmp >> 16);
ecc[7] = (uint8_t) (ecc_tmp >> 24);
ecc_tmp = readl_relaxed(FSMC_NAND_REG(regs, bank, ECC3));
ecc[8] = (uint8_t) (ecc_tmp >> 0);
ecc[9] = (uint8_t) (ecc_tmp >> 8);
ecc[10] = (uint8_t) (ecc_tmp >> 16);
ecc[11] = (uint8_t) (ecc_tmp >> 24);
ecc_tmp = readl_relaxed(FSMC_NAND_REG(regs, bank, STS));
ecc[12] = (uint8_t) (ecc_tmp >> 16);
return 0;
}
static int fsmc_read_hwecc_ecc1(struct mtd_info *mtd, const uint8_t *data,
uint8_t *ecc)
{
struct fsmc_nand_data *host = mtd_to_fsmc(mtd);
void __iomem *regs = host->regs_va;
uint32_t bank = host->bank;
uint32_t ecc_tmp;
ecc_tmp = readl_relaxed(FSMC_NAND_REG(regs, bank, ECC1));
ecc[0] = (uint8_t) (ecc_tmp >> 0);
ecc[1] = (uint8_t) (ecc_tmp >> 8);
ecc[2] = (uint8_t) (ecc_tmp >> 16);
return 0;
}
static int count_written_bits(uint8_t *buff, int size, int max_bits)
{
int k, written_bits = 0;
for (k = 0; k < size; k++) {
written_bits += hweight8(~buff[k]);
if (written_bits > max_bits)
break;
}
return written_bits;
}
static void dma_complete(void *param)
{
struct fsmc_nand_data *host = param;
complete(&host->dma_access_complete);
}
static int dma_xfer(struct fsmc_nand_data *host, void *buffer, int len,
enum dma_data_direction direction)
{
struct dma_chan *chan;
struct dma_device *dma_dev;
struct dma_async_tx_descriptor *tx;
dma_addr_t dma_dst, dma_src, dma_addr;
dma_cookie_t cookie;
unsigned long flags = DMA_CTRL_ACK | DMA_PREP_INTERRUPT;
int ret;
unsigned long time_left;
if (direction == DMA_TO_DEVICE)
chan = host->write_dma_chan;
else if (direction == DMA_FROM_DEVICE)
chan = host->read_dma_chan;
else
return -EINVAL;
dma_dev = chan->device;
dma_addr = dma_map_single(dma_dev->dev, buffer, len, direction);
if (direction == DMA_TO_DEVICE) {
dma_src = dma_addr;
dma_dst = host->data_pa;
} else {
dma_src = host->data_pa;
dma_dst = dma_addr;
}
tx = dma_dev->device_prep_dma_memcpy(chan, dma_dst, dma_src,
len, flags);
if (!tx) {
dev_err(host->dev, "device_prep_dma_memcpy error\n");
ret = -EIO;
goto unmap_dma;
}
tx->callback = dma_complete;
tx->callback_param = host;
cookie = tx->tx_submit(tx);
ret = dma_submit_error(cookie);
if (ret) {
dev_err(host->dev, "dma_submit_error %d\n", cookie);
goto unmap_dma;
}
dma_async_issue_pending(chan);
time_left =
wait_for_completion_timeout(&host->dma_access_complete,
msecs_to_jiffies(3000));
if (time_left == 0) {
dmaengine_terminate_all(chan);
dev_err(host->dev, "wait_for_completion_timeout\n");
ret = -ETIMEDOUT;
goto unmap_dma;
}
ret = 0;
unmap_dma:
dma_unmap_single(dma_dev->dev, dma_addr, len, direction);
return ret;
}
static void fsmc_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
int i;
struct nand_chip *chip = mtd_to_nand(mtd);
if (IS_ALIGNED((uint32_t)buf, sizeof(uint32_t)) &&
IS_ALIGNED(len, sizeof(uint32_t))) {
uint32_t *p = (uint32_t *)buf;
len = len >> 2;
for (i = 0; i < len; i++)
writel_relaxed(p[i], chip->IO_ADDR_W);
} else {
for (i = 0; i < len; i++)
writeb_relaxed(buf[i], chip->IO_ADDR_W);
}
}
static void fsmc_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
int i;
struct nand_chip *chip = mtd_to_nand(mtd);
if (IS_ALIGNED((uint32_t)buf, sizeof(uint32_t)) &&
IS_ALIGNED(len, sizeof(uint32_t))) {
uint32_t *p = (uint32_t *)buf;
len = len >> 2;
for (i = 0; i < len; i++)
p[i] = readl_relaxed(chip->IO_ADDR_R);
} else {
for (i = 0; i < len; i++)
buf[i] = readb_relaxed(chip->IO_ADDR_R);
}
}
static void fsmc_read_buf_dma(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct fsmc_nand_data *host = mtd_to_fsmc(mtd);
dma_xfer(host, buf, len, DMA_FROM_DEVICE);
}
static void fsmc_write_buf_dma(struct mtd_info *mtd, const uint8_t *buf,
int len)
{
struct fsmc_nand_data *host = mtd_to_fsmc(mtd);
dma_xfer(host, (void *)buf, len, DMA_TO_DEVICE);
}
static int fsmc_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
int i, j, s, stat, eccsize = chip->ecc.size;
int eccbytes = chip->ecc.bytes;
int eccsteps = chip->ecc.steps;
uint8_t *p = buf;
uint8_t *ecc_calc = chip->buffers->ecccalc;
uint8_t *ecc_code = chip->buffers->ecccode;
int off, len, group = 0;
uint16_t ecc_oob[7];
uint8_t *oob = (uint8_t *)&ecc_oob[0];
unsigned int max_bitflips = 0;
for (i = 0, s = 0; s < eccsteps; s++, i += eccbytes, p += eccsize) {
chip->cmdfunc(mtd, NAND_CMD_READ0, s * eccsize, page);
chip->ecc.hwctl(mtd, NAND_ECC_READ);
chip->read_buf(mtd, p, eccsize);
for (j = 0; j < eccbytes;) {
struct mtd_oob_region oobregion;
int ret;
ret = mtd_ooblayout_ecc(mtd, group++, &oobregion);
if (ret)
return ret;
off = oobregion.offset;
len = oobregion.length;
if (chip->options & NAND_BUSWIDTH_16)
len = roundup(len, 2);
chip->cmdfunc(mtd, NAND_CMD_READOOB, off, page);
chip->read_buf(mtd, oob + j, len);
j += len;
}
memcpy(&ecc_code[i], oob, chip->ecc.bytes);
chip->ecc.calculate(mtd, p, &ecc_calc[i]);
stat = chip->ecc.correct(mtd, p, &ecc_code[i], &ecc_calc[i]);
if (stat < 0) {
mtd->ecc_stats.failed++;
} else {
mtd->ecc_stats.corrected += stat;
max_bitflips = max_t(unsigned int, max_bitflips, stat);
}
}
return max_bitflips;
}
static int fsmc_bch8_correct_data(struct mtd_info *mtd, uint8_t *dat,
uint8_t *read_ecc, uint8_t *calc_ecc)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct fsmc_nand_data *host = mtd_to_fsmc(mtd);
void __iomem *regs = host->regs_va;
unsigned int bank = host->bank;
uint32_t err_idx[8];
uint32_t num_err, i;
uint32_t ecc1, ecc2, ecc3, ecc4;
num_err = (readl_relaxed(FSMC_NAND_REG(regs, bank, STS)) >> 10) & 0xF;
if (likely(num_err == 0))
return 0;
if (unlikely(num_err > 8)) {
int bits_ecc = count_written_bits(read_ecc, chip->ecc.bytes, 8);
int bits_data = count_written_bits(dat, chip->ecc.size, 8);
if ((bits_ecc + bits_data) <= 8) {
if (bits_data)
memset(dat, 0xff, chip->ecc.size);
return bits_data;
}
return -EBADMSG;
}
ecc1 = readl_relaxed(FSMC_NAND_REG(regs, bank, ECC1));
ecc2 = readl_relaxed(FSMC_NAND_REG(regs, bank, ECC2));
ecc3 = readl_relaxed(FSMC_NAND_REG(regs, bank, ECC3));
ecc4 = readl_relaxed(FSMC_NAND_REG(regs, bank, STS));
err_idx[0] = (ecc1 >> 0) & 0x1FFF;
err_idx[1] = (ecc1 >> 13) & 0x1FFF;
err_idx[2] = (((ecc2 >> 0) & 0x7F) << 6) | ((ecc1 >> 26) & 0x3F);
err_idx[3] = (ecc2 >> 7) & 0x1FFF;
err_idx[4] = (((ecc3 >> 0) & 0x1) << 12) | ((ecc2 >> 20) & 0xFFF);
err_idx[5] = (ecc3 >> 1) & 0x1FFF;
err_idx[6] = (ecc3 >> 14) & 0x1FFF;
err_idx[7] = (((ecc4 >> 16) & 0xFF) << 5) | ((ecc3 >> 27) & 0x1F);
i = 0;
while (num_err--) {
change_bit(0, (unsigned long *)&err_idx[i]);
change_bit(1, (unsigned long *)&err_idx[i]);
if (err_idx[i] < chip->ecc.size * 8) {
change_bit(err_idx[i], (unsigned long *)dat);
i++;
}
}
return i;
}
static bool filter(struct dma_chan *chan, void *slave)
{
chan->private = slave;
return true;
}
static int fsmc_nand_probe_config_dt(struct platform_device *pdev,
struct fsmc_nand_data *host,
struct nand_chip *nand)
{
struct device_node *np = pdev->dev.of_node;
u32 val;
int ret;
nand->options = 0;
if (!of_property_read_u32(np, "bank-width", &val)) {
if (val == 2) {
nand->options |= NAND_BUSWIDTH_16;
} else if (val != 1) {
dev_err(&pdev->dev, "invalid bank-width %u\n", val);
return -EINVAL;
}
}
if (of_get_property(np, "nand-skip-bbtscan", NULL))
nand->options |= NAND_SKIP_BBTSCAN;
host->dev_timings = devm_kzalloc(&pdev->dev,
sizeof(*host->dev_timings), GFP_KERNEL);
if (!host->dev_timings)
return -ENOMEM;
ret = of_property_read_u8_array(np, "timings", (u8 *)host->dev_timings,
sizeof(*host->dev_timings));
if (ret)
host->dev_timings = NULL;
host->bank = 0;
if (!of_property_read_u32(np, "bank", &val)) {
if (val > 3) {
dev_err(&pdev->dev, "invalid bank %u\n", val);
return -EINVAL;
}
host->bank = val;
}
return 0;
}
static int __init fsmc_nand_probe(struct platform_device *pdev)
{
struct fsmc_nand_data *host;
struct mtd_info *mtd;
struct nand_chip *nand;
struct resource *res;
dma_cap_mask_t mask;
int ret = 0;
u32 pid;
int i;
host = devm_kzalloc(&pdev->dev, sizeof(*host), GFP_KERNEL);
if (!host)
return -ENOMEM;
nand = &host->nand;
ret = fsmc_nand_probe_config_dt(pdev, host, nand);
if (ret)
return ret;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand_data");
host->data_va = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->data_va))
return PTR_ERR(host->data_va);
host->data_pa = (dma_addr_t)res->start;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand_addr");
host->addr_va = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->addr_va))
return PTR_ERR(host->addr_va);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand_cmd");
host->cmd_va = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->cmd_va))
return PTR_ERR(host->cmd_va);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "fsmc_regs");
host->regs_va = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->regs_va))
return PTR_ERR(host->regs_va);
host->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(host->clk)) {
dev_err(&pdev->dev, "failed to fetch block clock\n");
return PTR_ERR(host->clk);
}
ret = clk_prepare_enable(host->clk);
if (ret)
return ret;
for (pid = 0, i = 0; i < 4; i++)
pid |= (readl(host->regs_va + resource_size(res) - 0x20 + 4 * i) & 255) << (i * 8);
host->pid = pid;
dev_info(&pdev->dev, "FSMC device partno %03x, manufacturer %02x, "
"revision %02x, config %02x\n",
AMBA_PART_BITS(pid), AMBA_MANF_BITS(pid),
AMBA_REV_BITS(pid), AMBA_CONFIG_BITS(pid));
host->dev = &pdev->dev;
if (host->mode == USE_DMA_ACCESS)
init_completion(&host->dma_access_complete);
mtd = nand_to_mtd(&host->nand);
nand_set_controller_data(nand, host);
nand_set_flash_node(nand, pdev->dev.of_node);
mtd->dev.parent = &pdev->dev;
nand->IO_ADDR_R = host->data_va;
nand->IO_ADDR_W = host->data_va;
nand->cmd_ctrl = fsmc_cmd_ctrl;
nand->chip_delay = 30;
nand->ecc.mode = NAND_ECC_HW;
nand->ecc.hwctl = fsmc_enable_hwecc;
nand->ecc.size = 512;
nand->badblockbits = 7;
switch (host->mode) {
case USE_DMA_ACCESS:
dma_cap_zero(mask);
dma_cap_set(DMA_MEMCPY, mask);
host->read_dma_chan = dma_request_channel(mask, filter, NULL);
if (!host->read_dma_chan) {
dev_err(&pdev->dev, "Unable to get read dma channel\n");
goto err_req_read_chnl;
}
host->write_dma_chan = dma_request_channel(mask, filter, NULL);
if (!host->write_dma_chan) {
dev_err(&pdev->dev, "Unable to get write dma channel\n");
goto err_req_write_chnl;
}
nand->read_buf = fsmc_read_buf_dma;
nand->write_buf = fsmc_write_buf_dma;
break;
default:
case USE_WORD_ACCESS:
nand->read_buf = fsmc_read_buf;
nand->write_buf = fsmc_write_buf;
break;
}
if (host->dev_timings)
fsmc_nand_setup(host, host->dev_timings);
else
nand->setup_data_interface = fsmc_setup_data_interface;
if (AMBA_REV_BITS(host->pid) >= 8) {
nand->ecc.read_page = fsmc_read_page_hwecc;
nand->ecc.calculate = fsmc_read_hwecc_ecc4;
nand->ecc.correct = fsmc_bch8_correct_data;
nand->ecc.bytes = 13;
nand->ecc.strength = 8;
}
ret = nand_scan_ident(mtd, 1, NULL);
if (ret) {
dev_err(&pdev->dev, "No NAND Device found!\n");
goto err_scan_ident;
}
if (AMBA_REV_BITS(host->pid) >= 8) {
switch (mtd->oobsize) {
case 16:
case 64:
case 128:
case 224:
case 256:
break;
default:
dev_warn(&pdev->dev, "No oob scheme defined for oobsize %d\n",
mtd->oobsize);
ret = -EINVAL;
goto err_probe;
}
mtd_set_ooblayout(mtd, &fsmc_ecc4_ooblayout_ops);
} else {
switch (nand->ecc.mode) {
case NAND_ECC_HW:
dev_info(&pdev->dev, "Using 1-bit HW ECC scheme\n");
nand->ecc.calculate = fsmc_read_hwecc_ecc1;
nand->ecc.correct = nand_correct_data;
nand->ecc.bytes = 3;
nand->ecc.strength = 1;
break;
case NAND_ECC_SOFT:
if (nand->ecc.algo == NAND_ECC_BCH) {
dev_info(&pdev->dev, "Using 4-bit SW BCH ECC scheme\n");
break;
}
case NAND_ECC_ON_DIE:
break;
default:
dev_err(&pdev->dev, "Unsupported ECC mode!\n");
goto err_probe;
}
if (nand->ecc.mode == NAND_ECC_HW) {
switch (mtd->oobsize) {
case 16:
case 64:
case 128:
mtd_set_ooblayout(mtd,
&fsmc_ecc1_ooblayout_ops);
break;
default:
dev_warn(&pdev->dev,
"No oob scheme defined for oobsize %d\n",
mtd->oobsize);
ret = -EINVAL;
goto err_probe;
}
}
}
ret = nand_scan_tail(mtd);
if (ret)
goto err_probe;
mtd->name = "nand";
ret = mtd_device_register(mtd, NULL, 0);
if (ret)
goto err_probe;
platform_set_drvdata(pdev, host);
dev_info(&pdev->dev, "FSMC NAND driver registration successful\n");
return 0;
err_probe:
err_scan_ident:
if (host->mode == USE_DMA_ACCESS)
dma_release_channel(host->write_dma_chan);
err_req_write_chnl:
if (host->mode == USE_DMA_ACCESS)
dma_release_channel(host->read_dma_chan);
err_req_read_chnl:
clk_disable_unprepare(host->clk);
return ret;
}
static int fsmc_nand_remove(struct platform_device *pdev)
{
struct fsmc_nand_data *host = platform_get_drvdata(pdev);
if (host) {
nand_release(nand_to_mtd(&host->nand));
if (host->mode == USE_DMA_ACCESS) {
dma_release_channel(host->write_dma_chan);
dma_release_channel(host->read_dma_chan);
}
clk_disable_unprepare(host->clk);
}
return 0;
}
static int fsmc_nand_suspend(struct device *dev)
{
struct fsmc_nand_data *host = dev_get_drvdata(dev);
if (host)
clk_disable_unprepare(host->clk);
return 0;
}
static int fsmc_nand_resume(struct device *dev)
{
struct fsmc_nand_data *host = dev_get_drvdata(dev);
if (host) {
clk_prepare_enable(host->clk);
if (host->dev_timings)
fsmc_nand_setup(host, host->dev_timings);
}
return 0;
}
