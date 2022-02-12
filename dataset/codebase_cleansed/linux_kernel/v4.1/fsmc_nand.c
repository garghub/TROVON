static void fsmc_select_chip(struct mtd_info *mtd, int chipnr)
{
struct nand_chip *chip = mtd->priv;
struct fsmc_nand_data *host;
host = container_of(mtd, struct fsmc_nand_data, mtd);
switch (chipnr) {
case -1:
chip->cmd_ctrl(mtd, NAND_CMD_NONE, 0 | NAND_CTRL_CHANGE);
break;
case 0:
case 1:
case 2:
case 3:
if (host->select_chip)
host->select_chip(chipnr,
chip->options & NAND_BUSWIDTH_16);
break;
default:
BUG();
}
}
static void fsmc_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
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
static void fsmc_nand_setup(void __iomem *regs, uint32_t bank,
uint32_t busw, struct fsmc_nand_timings *timings)
{
uint32_t value = FSMC_DEVTYPE_NAND | FSMC_ENABLE | FSMC_WAITON;
uint32_t tclr, tar, thiz, thold, twait, tset;
struct fsmc_nand_timings *tims;
struct fsmc_nand_timings default_timings = {
.tclr = FSMC_TCLR_1,
.tar = FSMC_TAR_1,
.thiz = FSMC_THIZ_1,
.thold = FSMC_THOLD_4,
.twait = FSMC_TWAIT_6,
.tset = FSMC_TSET_0,
};
if (timings)
tims = timings;
else
tims = &default_timings;
tclr = (tims->tclr & FSMC_TCLR_MASK) << FSMC_TCLR_SHIFT;
tar = (tims->tar & FSMC_TAR_MASK) << FSMC_TAR_SHIFT;
thiz = (tims->thiz & FSMC_THIZ_MASK) << FSMC_THIZ_SHIFT;
thold = (tims->thold & FSMC_THOLD_MASK) << FSMC_THOLD_SHIFT;
twait = (tims->twait & FSMC_TWAIT_MASK) << FSMC_TWAIT_SHIFT;
tset = (tims->tset & FSMC_TSET_MASK) << FSMC_TSET_SHIFT;
if (busw)
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
static void fsmc_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
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
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
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
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
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
ret =
wait_for_completion_timeout(&host->dma_access_complete,
msecs_to_jiffies(3000));
if (ret <= 0) {
dmaengine_terminate_all(chan);
dev_err(host->dev, "wait_for_completion_timeout\n");
if (!ret)
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
struct nand_chip *chip = mtd->priv;
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
struct nand_chip *chip = mtd->priv;
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
struct fsmc_nand_data *host;
host = container_of(mtd, struct fsmc_nand_data, mtd);
dma_xfer(host, buf, len, DMA_FROM_DEVICE);
}
static void fsmc_write_buf_dma(struct mtd_info *mtd, const uint8_t *buf,
int len)
{
struct fsmc_nand_data *host;
host = container_of(mtd, struct fsmc_nand_data, mtd);
dma_xfer(host, (void *)buf, len, DMA_TO_DEVICE);
}
static int fsmc_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
struct fsmc_eccplace *ecc_place = host->ecc_place;
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
off = ecc_place->eccplace[group].offset;
len = ecc_place->eccplace[group].length;
group++;
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
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
struct nand_chip *chip = mtd->priv;
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
struct device_node *np)
{
struct fsmc_nand_platform_data *pdata = dev_get_platdata(&pdev->dev);
u32 val;
int ret;
pdata->width = 8;
if (!of_property_read_u32(np, "bank-width", &val)) {
if (val == 2) {
pdata->width = 16;
} else if (val != 1) {
dev_err(&pdev->dev, "invalid bank-width %u\n", val);
return -EINVAL;
}
}
if (of_get_property(np, "nand-skip-bbtscan", NULL))
pdata->options = NAND_SKIP_BBTSCAN;
pdata->nand_timings = devm_kzalloc(&pdev->dev,
sizeof(*pdata->nand_timings), GFP_KERNEL);
if (!pdata->nand_timings)
return -ENOMEM;
ret = of_property_read_u8_array(np, "timings", (u8 *)pdata->nand_timings,
sizeof(*pdata->nand_timings));
if (ret) {
dev_info(&pdev->dev, "No timings in dts specified, using default timings!\n");
pdata->nand_timings = NULL;
}
pdata->bank = 0;
if (!of_property_read_u32(np, "bank", &val)) {
if (val > 3) {
dev_err(&pdev->dev, "invalid bank %u\n", val);
return -EINVAL;
}
pdata->bank = val;
}
return 0;
}
static int fsmc_nand_probe_config_dt(struct platform_device *pdev,
struct device_node *np)
{
return -ENOSYS;
}
static int __init fsmc_nand_probe(struct platform_device *pdev)
{
struct fsmc_nand_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct device_node __maybe_unused *np = pdev->dev.of_node;
struct mtd_part_parser_data ppdata = {};
struct fsmc_nand_data *host;
struct mtd_info *mtd;
struct nand_chip *nand;
struct resource *res;
dma_cap_mask_t mask;
int ret = 0;
u32 pid;
int i;
if (np) {
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
pdev->dev.platform_data = pdata;
ret = fsmc_nand_probe_config_dt(pdev, np);
if (ret) {
dev_err(&pdev->dev, "no platform data\n");
return -ENODEV;
}
}
if (!pdata) {
dev_err(&pdev->dev, "platform data is NULL\n");
return -EINVAL;
}
host = devm_kzalloc(&pdev->dev, sizeof(*host), GFP_KERNEL);
if (!host)
return -ENOMEM;
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
host->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(host->clk)) {
dev_err(&pdev->dev, "failed to fetch block clock\n");
return PTR_ERR(host->clk);
}
ret = clk_prepare_enable(host->clk);
if (ret)
goto err_clk_prepare_enable;
for (pid = 0, i = 0; i < 4; i++)
pid |= (readl(host->regs_va + resource_size(res) - 0x20 + 4 * i) & 255) << (i * 8);
host->pid = pid;
dev_info(&pdev->dev, "FSMC device partno %03x, manufacturer %02x, "
"revision %02x, config %02x\n",
AMBA_PART_BITS(pid), AMBA_MANF_BITS(pid),
AMBA_REV_BITS(pid), AMBA_CONFIG_BITS(pid));
host->bank = pdata->bank;
host->select_chip = pdata->select_bank;
host->partitions = pdata->partitions;
host->nr_partitions = pdata->nr_partitions;
host->dev = &pdev->dev;
host->dev_timings = pdata->nand_timings;
host->mode = pdata->mode;
if (host->mode == USE_DMA_ACCESS)
init_completion(&host->dma_access_complete);
mtd = &host->mtd;
nand = &host->nand;
mtd->priv = nand;
nand->priv = host;
host->mtd.owner = THIS_MODULE;
nand->IO_ADDR_R = host->data_va;
nand->IO_ADDR_W = host->data_va;
nand->cmd_ctrl = fsmc_cmd_ctrl;
nand->chip_delay = 30;
nand->ecc.mode = NAND_ECC_HW;
nand->ecc.hwctl = fsmc_enable_hwecc;
nand->ecc.size = 512;
nand->options = pdata->options;
nand->select_chip = fsmc_select_chip;
nand->badblockbits = 7;
if (pdata->width == FSMC_NAND_BW16)
nand->options |= NAND_BUSWIDTH_16;
switch (host->mode) {
case USE_DMA_ACCESS:
dma_cap_zero(mask);
dma_cap_set(DMA_MEMCPY, mask);
host->read_dma_chan = dma_request_channel(mask, filter,
pdata->read_dma_priv);
if (!host->read_dma_chan) {
dev_err(&pdev->dev, "Unable to get read dma channel\n");
goto err_req_read_chnl;
}
host->write_dma_chan = dma_request_channel(mask, filter,
pdata->write_dma_priv);
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
fsmc_nand_setup(host->regs_va, host->bank,
nand->options & NAND_BUSWIDTH_16,
host->dev_timings);
if (AMBA_REV_BITS(host->pid) >= 8) {
nand->ecc.read_page = fsmc_read_page_hwecc;
nand->ecc.calculate = fsmc_read_hwecc_ecc4;
nand->ecc.correct = fsmc_bch8_correct_data;
nand->ecc.bytes = 13;
nand->ecc.strength = 8;
} else {
nand->ecc.calculate = fsmc_read_hwecc_ecc1;
nand->ecc.correct = nand_correct_data;
nand->ecc.bytes = 3;
nand->ecc.strength = 1;
}
if (nand_scan_ident(&host->mtd, 1, NULL)) {
ret = -ENXIO;
dev_err(&pdev->dev, "No NAND Device found!\n");
goto err_scan_ident;
}
if (AMBA_REV_BITS(host->pid) >= 8) {
switch (host->mtd.oobsize) {
case 16:
nand->ecc.layout = &fsmc_ecc4_16_layout;
host->ecc_place = &fsmc_ecc4_sp_place;
break;
case 64:
nand->ecc.layout = &fsmc_ecc4_64_layout;
host->ecc_place = &fsmc_ecc4_lp_place;
break;
case 128:
nand->ecc.layout = &fsmc_ecc4_128_layout;
host->ecc_place = &fsmc_ecc4_lp_place;
break;
case 224:
nand->ecc.layout = &fsmc_ecc4_224_layout;
host->ecc_place = &fsmc_ecc4_lp_place;
break;
case 256:
nand->ecc.layout = &fsmc_ecc4_256_layout;
host->ecc_place = &fsmc_ecc4_lp_place;
break;
default:
dev_warn(&pdev->dev, "No oob scheme defined for oobsize %d\n",
mtd->oobsize);
BUG();
}
} else {
switch (host->mtd.oobsize) {
case 16:
nand->ecc.layout = &fsmc_ecc1_16_layout;
break;
case 64:
nand->ecc.layout = &fsmc_ecc1_64_layout;
break;
case 128:
nand->ecc.layout = &fsmc_ecc1_128_layout;
break;
default:
dev_warn(&pdev->dev, "No oob scheme defined for oobsize %d\n",
mtd->oobsize);
BUG();
}
}
if (nand_scan_tail(&host->mtd)) {
ret = -ENXIO;
goto err_probe;
}
host->mtd.name = "nand";
ppdata.of_node = np;
ret = mtd_device_parse_register(&host->mtd, NULL, &ppdata,
host->partitions, host->nr_partitions);
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
err_clk_prepare_enable:
clk_put(host->clk);
return ret;
}
static int fsmc_nand_remove(struct platform_device *pdev)
{
struct fsmc_nand_data *host = platform_get_drvdata(pdev);
if (host) {
nand_release(&host->mtd);
if (host->mode == USE_DMA_ACCESS) {
dma_release_channel(host->write_dma_chan);
dma_release_channel(host->read_dma_chan);
}
clk_disable_unprepare(host->clk);
clk_put(host->clk);
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
fsmc_nand_setup(host->regs_va, host->bank,
host->nand.options & NAND_BUSWIDTH_16,
host->dev_timings);
}
return 0;
}
