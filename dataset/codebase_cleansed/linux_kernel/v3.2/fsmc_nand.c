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
struct fsmc_regs *regs = host->regs_va;
unsigned int bank = host->bank;
if (ctrl & NAND_CTRL_CHANGE) {
if (ctrl & NAND_CLE) {
this->IO_ADDR_R = (void __iomem *)host->cmd_va;
this->IO_ADDR_W = (void __iomem *)host->cmd_va;
} else if (ctrl & NAND_ALE) {
this->IO_ADDR_R = (void __iomem *)host->addr_va;
this->IO_ADDR_W = (void __iomem *)host->addr_va;
} else {
this->IO_ADDR_R = (void __iomem *)host->data_va;
this->IO_ADDR_W = (void __iomem *)host->data_va;
}
if (ctrl & NAND_NCE) {
writel(readl(&regs->bank_regs[bank].pc) | FSMC_ENABLE,
&regs->bank_regs[bank].pc);
} else {
writel(readl(&regs->bank_regs[bank].pc) & ~FSMC_ENABLE,
&regs->bank_regs[bank].pc);
}
}
mb();
if (cmd != NAND_CMD_NONE)
writeb(cmd, this->IO_ADDR_W);
}
static void __init fsmc_nand_setup(struct fsmc_regs *regs, uint32_t bank,
uint32_t busw)
{
uint32_t value = FSMC_DEVTYPE_NAND | FSMC_ENABLE | FSMC_WAITON;
if (busw)
writel(value | FSMC_DEVWID_16, &regs->bank_regs[bank].pc);
else
writel(value | FSMC_DEVWID_8, &regs->bank_regs[bank].pc);
writel(readl(&regs->bank_regs[bank].pc) | FSMC_TCLR_1 | FSMC_TAR_1,
&regs->bank_regs[bank].pc);
writel(FSMC_THIZ_1 | FSMC_THOLD_4 | FSMC_TWAIT_6 | FSMC_TSET_0,
&regs->bank_regs[bank].comm);
writel(FSMC_THIZ_1 | FSMC_THOLD_4 | FSMC_TWAIT_6 | FSMC_TSET_0,
&regs->bank_regs[bank].attrib);
}
static void fsmc_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
struct fsmc_regs *regs = host->regs_va;
uint32_t bank = host->bank;
writel(readl(&regs->bank_regs[bank].pc) & ~FSMC_ECCPLEN_256,
&regs->bank_regs[bank].pc);
writel(readl(&regs->bank_regs[bank].pc) & ~FSMC_ECCEN,
&regs->bank_regs[bank].pc);
writel(readl(&regs->bank_regs[bank].pc) | FSMC_ECCEN,
&regs->bank_regs[bank].pc);
}
static int fsmc_read_hwecc_ecc4(struct mtd_info *mtd, const uint8_t *data,
uint8_t *ecc)
{
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
struct fsmc_regs *regs = host->regs_va;
uint32_t bank = host->bank;
uint32_t ecc_tmp;
unsigned long deadline = jiffies + FSMC_BUSY_WAIT_TIMEOUT;
do {
if (readl(&regs->bank_regs[bank].sts) & FSMC_CODE_RDY)
break;
else
cond_resched();
} while (!time_after_eq(jiffies, deadline));
ecc_tmp = readl(&regs->bank_regs[bank].ecc1);
ecc[0] = (uint8_t) (ecc_tmp >> 0);
ecc[1] = (uint8_t) (ecc_tmp >> 8);
ecc[2] = (uint8_t) (ecc_tmp >> 16);
ecc[3] = (uint8_t) (ecc_tmp >> 24);
ecc_tmp = readl(&regs->bank_regs[bank].ecc2);
ecc[4] = (uint8_t) (ecc_tmp >> 0);
ecc[5] = (uint8_t) (ecc_tmp >> 8);
ecc[6] = (uint8_t) (ecc_tmp >> 16);
ecc[7] = (uint8_t) (ecc_tmp >> 24);
ecc_tmp = readl(&regs->bank_regs[bank].ecc3);
ecc[8] = (uint8_t) (ecc_tmp >> 0);
ecc[9] = (uint8_t) (ecc_tmp >> 8);
ecc[10] = (uint8_t) (ecc_tmp >> 16);
ecc[11] = (uint8_t) (ecc_tmp >> 24);
ecc_tmp = readl(&regs->bank_regs[bank].sts);
ecc[12] = (uint8_t) (ecc_tmp >> 16);
return 0;
}
static int fsmc_read_hwecc_ecc1(struct mtd_info *mtd, const uint8_t *data,
uint8_t *ecc)
{
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
struct fsmc_regs *regs = host->regs_va;
uint32_t bank = host->bank;
uint32_t ecc_tmp;
ecc_tmp = readl(&regs->bank_regs[bank].ecc1);
ecc[0] = (uint8_t) (ecc_tmp >> 0);
ecc[1] = (uint8_t) (ecc_tmp >> 8);
ecc[2] = (uint8_t) (ecc_tmp >> 16);
return 0;
}
static int fsmc_read_page_hwecc(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int page)
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
for (i = 0, s = 0; s < eccsteps; s++, i += eccbytes, p += eccsize) {
chip->cmdfunc(mtd, NAND_CMD_READ0, s * eccsize, page);
chip->ecc.hwctl(mtd, NAND_ECC_READ);
chip->read_buf(mtd, p, eccsize);
for (j = 0; j < eccbytes;) {
off = ecc_place->eccplace[group].offset;
len = ecc_place->eccplace[group].length;
group++;
len = roundup(len, 2);
chip->cmdfunc(mtd, NAND_CMD_READOOB, off, page);
chip->read_buf(mtd, oob + j, len);
j += len;
}
memcpy(&ecc_code[i], oob, 13);
chip->ecc.calculate(mtd, p, &ecc_calc[i]);
stat = chip->ecc.correct(mtd, p, &ecc_code[i], &ecc_calc[i]);
if (stat < 0)
mtd->ecc_stats.failed++;
else
mtd->ecc_stats.corrected += stat;
}
return 0;
}
static int fsmc_correct_data(struct mtd_info *mtd, uint8_t *dat,
uint8_t *read_ecc, uint8_t *calc_ecc)
{
struct fsmc_nand_data *host = container_of(mtd,
struct fsmc_nand_data, mtd);
struct fsmc_regs *regs = host->regs_va;
unsigned int bank = host->bank;
uint16_t err_idx[8];
uint64_t ecc_data[2];
uint32_t num_err, i;
memcpy(ecc_data, calc_ecc, 13);
for (i = 0; i < 8; i++) {
if (i == 4) {
err_idx[4] = ((ecc_data[1] & 0x1) << 12) | ecc_data[0];
ecc_data[1] >>= 1;
continue;
}
err_idx[i] = (ecc_data[i/4] & 0x1FFF);
ecc_data[i/4] >>= 13;
}
num_err = (readl(&regs->bank_regs[bank].sts) >> 10) & 0xF;
if (num_err == 0xF)
return -EBADMSG;
i = 0;
while (num_err--) {
change_bit(0, (unsigned long *)&err_idx[i]);
change_bit(1, (unsigned long *)&err_idx[i]);
if (err_idx[i] <= 512 * 8) {
change_bit(err_idx[i], (unsigned long *)dat);
i++;
}
}
return i;
}
static int __init fsmc_nand_probe(struct platform_device *pdev)
{
struct fsmc_nand_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct fsmc_nand_data *host;
struct mtd_info *mtd;
struct nand_chip *nand;
struct fsmc_regs *regs;
struct resource *res;
int ret = 0;
u32 pid;
int i;
if (!pdata) {
dev_err(&pdev->dev, "platform data is NULL\n");
return -EINVAL;
}
host = kzalloc(sizeof(*host), GFP_KERNEL);
if (!host) {
dev_err(&pdev->dev, "failed to allocate device structure\n");
return -ENOMEM;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "nand_data");
if (!res) {
ret = -EIO;
goto err_probe1;
}
host->resdata = request_mem_region(res->start, resource_size(res),
pdev->name);
if (!host->resdata) {
ret = -EIO;
goto err_probe1;
}
host->data_va = ioremap(res->start, resource_size(res));
if (!host->data_va) {
ret = -EIO;
goto err_probe1;
}
host->resaddr = request_mem_region(res->start + PLAT_NAND_ALE,
resource_size(res), pdev->name);
if (!host->resaddr) {
ret = -EIO;
goto err_probe1;
}
host->addr_va = ioremap(res->start + PLAT_NAND_ALE, resource_size(res));
if (!host->addr_va) {
ret = -EIO;
goto err_probe1;
}
host->rescmd = request_mem_region(res->start + PLAT_NAND_CLE,
resource_size(res), pdev->name);
if (!host->rescmd) {
ret = -EIO;
goto err_probe1;
}
host->cmd_va = ioremap(res->start + PLAT_NAND_CLE, resource_size(res));
if (!host->cmd_va) {
ret = -EIO;
goto err_probe1;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "fsmc_regs");
if (!res) {
ret = -EIO;
goto err_probe1;
}
host->resregs = request_mem_region(res->start, resource_size(res),
pdev->name);
if (!host->resregs) {
ret = -EIO;
goto err_probe1;
}
host->regs_va = ioremap(res->start, resource_size(res));
if (!host->regs_va) {
ret = -EIO;
goto err_probe1;
}
host->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(host->clk)) {
dev_err(&pdev->dev, "failed to fetch block clock\n");
ret = PTR_ERR(host->clk);
host->clk = NULL;
goto err_probe1;
}
ret = clk_enable(host->clk);
if (ret)
goto err_probe1;
for (pid = 0, i = 0; i < 4; i++)
pid |= (readl(host->regs_va + resource_size(res) - 0x20 + 4 * i) & 255) << (i * 8);
host->pid = pid;
dev_info(&pdev->dev, "FSMC device partno %03x, manufacturer %02x, "
"revision %02x, config %02x\n",
AMBA_PART_BITS(pid), AMBA_MANF_BITS(pid),
AMBA_REV_BITS(pid), AMBA_CONFIG_BITS(pid));
host->bank = pdata->bank;
host->select_chip = pdata->select_bank;
regs = host->regs_va;
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
if (pdata->width == FSMC_NAND_BW16)
nand->options |= NAND_BUSWIDTH_16;
fsmc_nand_setup(regs, host->bank, nand->options & NAND_BUSWIDTH_16);
if (AMBA_REV_BITS(host->pid) >= 8) {
nand->ecc.read_page = fsmc_read_page_hwecc;
nand->ecc.calculate = fsmc_read_hwecc_ecc4;
nand->ecc.correct = fsmc_correct_data;
nand->ecc.bytes = 13;
} else {
nand->ecc.calculate = fsmc_read_hwecc_ecc1;
nand->ecc.correct = nand_correct_data;
nand->ecc.bytes = 3;
}
if (nand_scan_ident(&host->mtd, 1, NULL)) {
ret = -ENXIO;
dev_err(&pdev->dev, "No NAND Device found!\n");
goto err_probe;
}
if (AMBA_REV_BITS(host->pid) >= 8) {
if (host->mtd.writesize == 512) {
nand->ecc.layout = &fsmc_ecc4_sp_layout;
host->ecc_place = &fsmc_ecc4_sp_place;
} else {
nand->ecc.layout = &fsmc_ecc4_lp_layout;
host->ecc_place = &fsmc_ecc4_lp_place;
}
} else {
nand->ecc.layout = &fsmc_ecc1_layout;
}
if (nand_scan_tail(&host->mtd)) {
ret = -ENXIO;
goto err_probe;
}
host->mtd.name = "nand";
ret = mtd_device_parse_register(&host->mtd, NULL, 0,
host->mtd.size <= 0x04000000 ?
partition_info_16KB_blk :
partition_info_128KB_blk,
host->mtd.size <= 0x04000000 ?
ARRAY_SIZE(partition_info_16KB_blk) :
ARRAY_SIZE(partition_info_128KB_blk));
if (ret)
goto err_probe;
platform_set_drvdata(pdev, host);
dev_info(&pdev->dev, "FSMC NAND driver registration successful\n");
return 0;
err_probe:
clk_disable(host->clk);
err_probe1:
if (host->clk)
clk_put(host->clk);
if (host->regs_va)
iounmap(host->regs_va);
if (host->resregs)
release_mem_region(host->resregs->start,
resource_size(host->resregs));
if (host->cmd_va)
iounmap(host->cmd_va);
if (host->rescmd)
release_mem_region(host->rescmd->start,
resource_size(host->rescmd));
if (host->addr_va)
iounmap(host->addr_va);
if (host->resaddr)
release_mem_region(host->resaddr->start,
resource_size(host->resaddr));
if (host->data_va)
iounmap(host->data_va);
if (host->resdata)
release_mem_region(host->resdata->start,
resource_size(host->resdata));
kfree(host);
return ret;
}
static int fsmc_nand_remove(struct platform_device *pdev)
{
struct fsmc_nand_data *host = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
if (host) {
nand_release(&host->mtd);
clk_disable(host->clk);
clk_put(host->clk);
iounmap(host->regs_va);
release_mem_region(host->resregs->start,
resource_size(host->resregs));
iounmap(host->cmd_va);
release_mem_region(host->rescmd->start,
resource_size(host->rescmd));
iounmap(host->addr_va);
release_mem_region(host->resaddr->start,
resource_size(host->resaddr));
iounmap(host->data_va);
release_mem_region(host->resdata->start,
resource_size(host->resdata));
kfree(host);
}
return 0;
}
static int fsmc_nand_suspend(struct device *dev)
{
struct fsmc_nand_data *host = dev_get_drvdata(dev);
if (host)
clk_disable(host->clk);
return 0;
}
static int fsmc_nand_resume(struct device *dev)
{
struct fsmc_nand_data *host = dev_get_drvdata(dev);
if (host)
clk_enable(host->clk);
return 0;
}
static int __init fsmc_nand_init(void)
{
return platform_driver_probe(&fsmc_nand_driver,
fsmc_nand_probe);
}
static void __exit fsmc_nand_exit(void)
{
platform_driver_unregister(&fsmc_nand_driver);
}
