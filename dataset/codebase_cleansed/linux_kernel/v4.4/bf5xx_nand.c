static struct bf5xx_nand_info *mtd_to_nand_info(struct mtd_info *mtd)
{
return container_of(mtd, struct bf5xx_nand_info, mtd);
}
static struct bf5xx_nand_info *to_nand_info(struct platform_device *pdev)
{
return platform_get_drvdata(pdev);
}
static struct bf5xx_nand_platform *to_nand_plat(struct platform_device *pdev)
{
return dev_get_platdata(&pdev->dev);
}
static void bf5xx_nand_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
if (cmd == NAND_CMD_NONE)
return;
while (bfin_read_NFC_STAT() & WB_FULL)
cpu_relax();
if (ctrl & NAND_CLE)
bfin_write_NFC_CMD(cmd);
else if (ctrl & NAND_ALE)
bfin_write_NFC_ADDR(cmd);
SSYNC();
}
static int bf5xx_nand_devready(struct mtd_info *mtd)
{
unsigned short val = bfin_read_NFC_STAT();
if ((val & NBUSY) == NBUSY)
return 1;
else
return 0;
}
static int bf5xx_nand_correct_data_256(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct bf5xx_nand_info *info = mtd_to_nand_info(mtd);
u32 syndrome[5];
u32 calced, stored;
int i;
unsigned short failing_bit, failing_byte;
u_char data;
calced = calc_ecc[0] | (calc_ecc[1] << 8) | (calc_ecc[2] << 16);
stored = read_ecc[0] | (read_ecc[1] << 8) | (read_ecc[2] << 16);
syndrome[0] = (calced ^ stored);
if (!syndrome[0] || !calced || !stored)
return 0;
if (hweight32(syndrome[0]) == 1) {
dev_err(info->device, "ECC data was incorrect!\n");
return 1;
}
syndrome[1] = (calced & 0x7FF) ^ (stored & 0x7FF);
syndrome[2] = (calced & 0x7FF) ^ ((calced >> 11) & 0x7FF);
syndrome[3] = (stored & 0x7FF) ^ ((stored >> 11) & 0x7FF);
syndrome[4] = syndrome[2] ^ syndrome[3];
for (i = 0; i < 5; i++)
dev_info(info->device, "syndrome[%d] 0x%08x\n", i, syndrome[i]);
dev_info(info->device,
"calced[0x%08x], stored[0x%08x]\n",
calced, stored);
if (hweight32(syndrome[0]) == 11 && syndrome[4] == 0x7FF) {
dev_info(info->device,
"1-bit correctable error, correct it.\n");
dev_info(info->device,
"syndrome[1] 0x%08x\n", syndrome[1]);
failing_bit = syndrome[1] & 0x7;
failing_byte = syndrome[1] >> 0x3;
data = *(dat + failing_byte);
data = data ^ (0x1 << failing_bit);
*(dat + failing_byte) = data;
return 0;
}
dev_err(info->device,
"More than 1-bit error, non-correctable error.\n");
dev_err(info->device,
"Please discard data, mark bad block\n");
return 1;
}
static int bf5xx_nand_correct_data(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct nand_chip *chip = mtd->priv;
int ret;
ret = bf5xx_nand_correct_data_256(mtd, dat, read_ecc, calc_ecc);
if (chip->ecc.size == 512) {
dat += 256;
read_ecc += 3;
calc_ecc += 3;
ret |= bf5xx_nand_correct_data_256(mtd, dat, read_ecc, calc_ecc);
}
return ret;
}
static void bf5xx_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
return;
}
static int bf5xx_nand_calculate_ecc(struct mtd_info *mtd,
const u_char *dat, u_char *ecc_code)
{
struct bf5xx_nand_info *info = mtd_to_nand_info(mtd);
struct nand_chip *chip = mtd->priv;
u16 ecc0, ecc1;
u32 code[2];
u8 *p;
ecc0 = bfin_read_NFC_ECC0();
ecc1 = bfin_read_NFC_ECC1();
code[0] = (ecc0 & 0x7ff) | ((ecc1 & 0x7ff) << 11);
dev_dbg(info->device, "returning ecc 0x%08x\n", code[0]);
p = (u8 *) code;
memcpy(ecc_code, p, 3);
if (chip->ecc.size == 512) {
ecc0 = bfin_read_NFC_ECC2();
ecc1 = bfin_read_NFC_ECC3();
code[1] = (ecc0 & 0x7ff) | ((ecc1 & 0x7ff) << 11);
p = (u8 *) (code + 1);
memcpy((ecc_code + 3), p, 3);
dev_dbg(info->device, "returning ecc 0x%08x\n", code[1]);
}
return 0;
}
static void bf5xx_nand_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
int i;
unsigned short val;
for (i = 0; i < len; i++) {
while (bfin_read_NFC_STAT() & WB_FULL)
cpu_relax();
bfin_write_NFC_DATA_RD(0x0000);
SSYNC();
while ((bfin_read_NFC_IRQSTAT() & RD_RDY) != RD_RDY)
cpu_relax();
buf[i] = bfin_read_NFC_READ();
val = bfin_read_NFC_IRQSTAT();
val |= RD_RDY;
bfin_write_NFC_IRQSTAT(val);
SSYNC();
}
}
static uint8_t bf5xx_nand_read_byte(struct mtd_info *mtd)
{
uint8_t val;
bf5xx_nand_read_buf(mtd, &val, 1);
return val;
}
static void bf5xx_nand_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
int i;
for (i = 0; i < len; i++) {
while (bfin_read_NFC_STAT() & WB_FULL)
cpu_relax();
bfin_write_NFC_DATA_WR(buf[i]);
SSYNC();
}
}
static void bf5xx_nand_read_buf16(struct mtd_info *mtd, uint8_t *buf, int len)
{
int i;
u16 *p = (u16 *) buf;
len >>= 1;
bfin_write_NFC_DATA_RD(0x5555);
SSYNC();
for (i = 0; i < len; i++)
p[i] = bfin_read_NFC_READ();
}
static void bf5xx_nand_write_buf16(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
int i;
u16 *p = (u16 *) buf;
len >>= 1;
for (i = 0; i < len; i++)
bfin_write_NFC_DATA_WR(p[i]);
SSYNC();
}
static irqreturn_t bf5xx_nand_dma_irq(int irq, void *dev_id)
{
struct bf5xx_nand_info *info = dev_id;
clear_dma_irqstat(CH_NFC);
disable_dma(CH_NFC);
complete(&info->dma_completion);
return IRQ_HANDLED;
}
static void bf5xx_nand_dma_rw(struct mtd_info *mtd,
uint8_t *buf, int is_read)
{
struct bf5xx_nand_info *info = mtd_to_nand_info(mtd);
struct nand_chip *chip = mtd->priv;
unsigned short val;
dev_dbg(info->device, " mtd->%p, buf->%p, is_read %d\n",
mtd, buf, is_read);
if (is_read)
invalidate_dcache_range((unsigned int)buf,
(unsigned int)(buf + chip->ecc.size));
else
flush_dcache_range((unsigned int)buf,
(unsigned int)(buf + chip->ecc.size));
bfin_write_NFC_RST(ECC_RST);
SSYNC();
while (bfin_read_NFC_RST() & ECC_RST)
cpu_relax();
disable_dma(CH_NFC);
clear_dma_irqstat(CH_NFC);
set_dma_config(CH_NFC, 0x0);
set_dma_start_addr(CH_NFC, (unsigned long) buf);
#ifdef CONFIG_BF52x
set_dma_x_count(CH_NFC, (chip->ecc.size >> 1));
set_dma_x_modify(CH_NFC, 2);
val = DI_EN | WDSIZE_16;
#endif
#ifdef CONFIG_BF54x
set_dma_x_count(CH_NFC, (chip->ecc.size >> 2));
set_dma_x_modify(CH_NFC, 4);
val = DI_EN | WDSIZE_32;
#endif
if (is_read)
val |= WNR;
set_dma_config(CH_NFC, val);
enable_dma(CH_NFC);
if (is_read)
bfin_write_NFC_PGCTL(PG_RD_START);
else
bfin_write_NFC_PGCTL(PG_WR_START);
wait_for_completion(&info->dma_completion);
}
static void bf5xx_nand_dma_read_buf(struct mtd_info *mtd,
uint8_t *buf, int len)
{
struct bf5xx_nand_info *info = mtd_to_nand_info(mtd);
struct nand_chip *chip = mtd->priv;
dev_dbg(info->device, "mtd->%p, buf->%p, int %d\n", mtd, buf, len);
if (len == chip->ecc.size)
bf5xx_nand_dma_rw(mtd, buf, 1);
else
bf5xx_nand_read_buf(mtd, buf, len);
}
static void bf5xx_nand_dma_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
struct bf5xx_nand_info *info = mtd_to_nand_info(mtd);
struct nand_chip *chip = mtd->priv;
dev_dbg(info->device, "mtd->%p, buf->%p, len %d\n", mtd, buf, len);
if (len == chip->ecc.size)
bf5xx_nand_dma_rw(mtd, (uint8_t *)buf, 0);
else
bf5xx_nand_write_buf(mtd, buf, len);
}
static int bf5xx_nand_read_page_raw(struct mtd_info *mtd, struct nand_chip *chip,
uint8_t *buf, int oob_required, int page)
{
bf5xx_nand_read_buf(mtd, buf, mtd->writesize);
bf5xx_nand_read_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int bf5xx_nand_write_page_raw(struct mtd_info *mtd,
struct nand_chip *chip, const uint8_t *buf, int oob_required,
int page)
{
bf5xx_nand_write_buf(mtd, buf, mtd->writesize);
bf5xx_nand_write_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static int bf5xx_nand_dma_init(struct bf5xx_nand_info *info)
{
int ret;
if (!hardware_ecc)
return 0;
init_completion(&info->dma_completion);
ret = request_dma(CH_NFC, "BF5XX NFC driver");
if (ret < 0) {
dev_err(info->device, " unable to get DMA channel\n");
return ret;
}
#ifdef CONFIG_BF54x
bfin_write_DMAC1_PERIMUX(bfin_read_DMAC1_PERIMUX() & ~1);
SSYNC();
#endif
set_dma_callback(CH_NFC, bf5xx_nand_dma_irq, info);
disable_dma(CH_NFC);
return 0;
}
static void bf5xx_nand_dma_remove(struct bf5xx_nand_info *info)
{
if (hardware_ecc)
free_dma(CH_NFC);
}
static int bf5xx_nand_hw_init(struct bf5xx_nand_info *info)
{
int err = 0;
unsigned short val;
struct bf5xx_nand_platform *plat = info->platform;
dev_info(info->device,
"data_width=%d, wr_dly=%d, rd_dly=%d\n",
(plat->data_width ? 16 : 8),
plat->wr_dly, plat->rd_dly);
val = (1 << NFC_PG_SIZE_OFFSET) |
(plat->data_width << NFC_NWIDTH_OFFSET) |
(plat->rd_dly << NFC_RDDLY_OFFSET) |
(plat->wr_dly << NFC_WRDLY_OFFSET);
dev_dbg(info->device, "NFC_CTL is 0x%04x\n", val);
bfin_write_NFC_CTL(val);
SSYNC();
bfin_write_NFC_IRQMASK(0x0);
SSYNC();
val = bfin_read_NFC_IRQSTAT();
bfin_write_NFC_IRQSTAT(val);
SSYNC();
if (bf5xx_nand_dma_init(info))
err = -ENXIO;
return err;
}
static int bf5xx_nand_add_partition(struct bf5xx_nand_info *info)
{
struct mtd_info *mtd = &info->mtd;
struct mtd_partition *parts = info->platform->partitions;
int nr = info->platform->nr_partitions;
return mtd_device_register(mtd, parts, nr);
}
static int bf5xx_nand_remove(struct platform_device *pdev)
{
struct bf5xx_nand_info *info = to_nand_info(pdev);
nand_release(&info->mtd);
peripheral_free_list(bfin_nfc_pin_req);
bf5xx_nand_dma_remove(info);
return 0;
}
static int bf5xx_nand_scan(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
int ret;
ret = nand_scan_ident(mtd, 1, NULL);
if (ret)
return ret;
if (hardware_ecc) {
if (likely(mtd->writesize >= 512)) {
chip->ecc.size = 512;
chip->ecc.bytes = 6;
chip->ecc.strength = 2;
} else {
chip->ecc.size = 256;
chip->ecc.bytes = 3;
chip->ecc.strength = 1;
bfin_write_NFC_CTL(bfin_read_NFC_CTL() & ~(1 << NFC_PG_SIZE_OFFSET));
SSYNC();
}
}
return nand_scan_tail(mtd);
}
static int bf5xx_nand_probe(struct platform_device *pdev)
{
struct bf5xx_nand_platform *plat = to_nand_plat(pdev);
struct bf5xx_nand_info *info = NULL;
struct nand_chip *chip = NULL;
struct mtd_info *mtd = NULL;
int err = 0;
dev_dbg(&pdev->dev, "(%p)\n", pdev);
if (!plat) {
dev_err(&pdev->dev, "no platform specific information\n");
return -EINVAL;
}
if (peripheral_request_list(bfin_nfc_pin_req, DRV_NAME)) {
dev_err(&pdev->dev, "requesting Peripherals failed\n");
return -EFAULT;
}
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (info == NULL) {
err = -ENOMEM;
goto out_err;
}
platform_set_drvdata(pdev, info);
spin_lock_init(&info->controller.lock);
init_waitqueue_head(&info->controller.wq);
info->device = &pdev->dev;
info->platform = plat;
chip = &info->chip;
if (plat->data_width)
chip->options |= NAND_BUSWIDTH_16;
chip->options |= NAND_CACHEPRG | NAND_SKIP_BBTSCAN;
chip->read_buf = (plat->data_width) ?
bf5xx_nand_read_buf16 : bf5xx_nand_read_buf;
chip->write_buf = (plat->data_width) ?
bf5xx_nand_write_buf16 : bf5xx_nand_write_buf;
chip->read_byte = bf5xx_nand_read_byte;
chip->cmd_ctrl = bf5xx_nand_hwcontrol;
chip->dev_ready = bf5xx_nand_devready;
chip->priv = &info->mtd;
chip->controller = &info->controller;
chip->IO_ADDR_R = (void __iomem *) NFC_READ;
chip->IO_ADDR_W = (void __iomem *) NFC_DATA_WR;
chip->chip_delay = 0;
mtd = &info->mtd;
mtd->priv = chip;
mtd->dev.parent = &pdev->dev;
err = bf5xx_nand_hw_init(info);
if (err)
goto out_err;
if (hardware_ecc) {
#ifdef CONFIG_MTD_NAND_BF5XX_BOOTROM_ECC
chip->ecc.layout = &bootrom_ecclayout;
#endif
chip->read_buf = bf5xx_nand_dma_read_buf;
chip->write_buf = bf5xx_nand_dma_write_buf;
chip->ecc.calculate = bf5xx_nand_calculate_ecc;
chip->ecc.correct = bf5xx_nand_correct_data;
chip->ecc.mode = NAND_ECC_HW;
chip->ecc.hwctl = bf5xx_nand_enable_hwecc;
chip->ecc.read_page_raw = bf5xx_nand_read_page_raw;
chip->ecc.write_page_raw = bf5xx_nand_write_page_raw;
} else {
chip->ecc.mode = NAND_ECC_SOFT;
}
if (bf5xx_nand_scan(mtd)) {
err = -ENXIO;
goto out_err_nand_scan;
}
#ifdef CONFIG_MTD_NAND_BF5XX_BOOTROM_ECC
chip->badblockpos = 63;
#endif
bf5xx_nand_add_partition(info);
dev_dbg(&pdev->dev, "initialised ok\n");
return 0;
out_err_nand_scan:
bf5xx_nand_dma_remove(info);
out_err:
peripheral_free_list(bfin_nfc_pin_req);
return err;
}
