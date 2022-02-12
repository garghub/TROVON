static inline unsigned int davinci_nand_readl(struct davinci_nand_info *info,
int offset)
{
return __raw_readl(info->base + offset);
}
static inline void davinci_nand_writel(struct davinci_nand_info *info,
int offset, unsigned long value)
{
__raw_writel(value, info->base + offset);
}
static void nand_davinci_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct davinci_nand_info *info = to_davinci_nand(mtd);
uint32_t addr = info->current_cs;
struct nand_chip *nand = mtd->priv;
if (ctrl & NAND_CTRL_CHANGE) {
if ((ctrl & NAND_CTRL_CLE) == NAND_CTRL_CLE)
addr |= info->mask_cle;
else if ((ctrl & NAND_CTRL_ALE) == NAND_CTRL_ALE)
addr |= info->mask_ale;
nand->IO_ADDR_W = (void __iomem __force *)addr;
}
if (cmd != NAND_CMD_NONE)
iowrite8(cmd, nand->IO_ADDR_W);
}
static void nand_davinci_select_chip(struct mtd_info *mtd, int chip)
{
struct davinci_nand_info *info = to_davinci_nand(mtd);
uint32_t addr = info->ioaddr;
if (chip > 0)
addr |= info->mask_chipsel;
info->current_cs = addr;
info->chip.IO_ADDR_W = (void __iomem __force *)addr;
info->chip.IO_ADDR_R = info->chip.IO_ADDR_W;
}
static inline uint32_t nand_davinci_readecc_1bit(struct mtd_info *mtd)
{
struct davinci_nand_info *info = to_davinci_nand(mtd);
return davinci_nand_readl(info, NANDF1ECC_OFFSET
+ 4 * info->core_chipsel);
}
static void nand_davinci_hwctl_1bit(struct mtd_info *mtd, int mode)
{
struct davinci_nand_info *info;
uint32_t nandcfr;
unsigned long flags;
info = to_davinci_nand(mtd);
nand_davinci_readecc_1bit(mtd);
spin_lock_irqsave(&davinci_nand_lock, flags);
nandcfr = davinci_nand_readl(info, NANDFCR_OFFSET);
nandcfr |= BIT(8 + info->core_chipsel);
davinci_nand_writel(info, NANDFCR_OFFSET, nandcfr);
spin_unlock_irqrestore(&davinci_nand_lock, flags);
}
static int nand_davinci_calculate_1bit(struct mtd_info *mtd,
const u_char *dat, u_char *ecc_code)
{
unsigned int ecc_val = nand_davinci_readecc_1bit(mtd);
unsigned int ecc24 = (ecc_val & 0x0fff) | ((ecc_val & 0x0fff0000) >> 4);
ecc24 = ~ecc24;
ecc_code[0] = (u_char)(ecc24);
ecc_code[1] = (u_char)(ecc24 >> 8);
ecc_code[2] = (u_char)(ecc24 >> 16);
return 0;
}
static int nand_davinci_correct_1bit(struct mtd_info *mtd, u_char *dat,
u_char *read_ecc, u_char *calc_ecc)
{
struct nand_chip *chip = mtd->priv;
uint32_t eccNand = read_ecc[0] | (read_ecc[1] << 8) |
(read_ecc[2] << 16);
uint32_t eccCalc = calc_ecc[0] | (calc_ecc[1] << 8) |
(calc_ecc[2] << 16);
uint32_t diff = eccCalc ^ eccNand;
if (diff) {
if ((((diff >> 12) ^ diff) & 0xfff) == 0xfff) {
if ((diff >> (12 + 3)) < chip->ecc.size) {
dat[diff >> (12 + 3)] ^= BIT((diff >> 12) & 7);
return 1;
} else {
return -1;
}
} else if (!(diff & (diff - 1))) {
return 1;
} else {
return -1;
}
}
return 0;
}
static void nand_davinci_hwctl_4bit(struct mtd_info *mtd, int mode)
{
struct davinci_nand_info *info = to_davinci_nand(mtd);
unsigned long flags;
u32 val;
spin_lock_irqsave(&davinci_nand_lock, flags);
val = davinci_nand_readl(info, NANDFCR_OFFSET);
val &= ~(0x03 << 4);
val |= (info->core_chipsel << 4) | BIT(12);
davinci_nand_writel(info, NANDFCR_OFFSET, val);
info->is_readmode = (mode == NAND_ECC_READ);
spin_unlock_irqrestore(&davinci_nand_lock, flags);
}
static void
nand_davinci_readecc_4bit(struct davinci_nand_info *info, u32 code[4])
{
const u32 mask = 0x03ff03ff;
code[0] = davinci_nand_readl(info, NAND_4BIT_ECC1_OFFSET) & mask;
code[1] = davinci_nand_readl(info, NAND_4BIT_ECC2_OFFSET) & mask;
code[2] = davinci_nand_readl(info, NAND_4BIT_ECC3_OFFSET) & mask;
code[3] = davinci_nand_readl(info, NAND_4BIT_ECC4_OFFSET) & mask;
}
static int nand_davinci_calculate_4bit(struct mtd_info *mtd,
const u_char *dat, u_char *ecc_code)
{
struct davinci_nand_info *info = to_davinci_nand(mtd);
u32 raw_ecc[4], *p;
unsigned i;
if (info->is_readmode) {
davinci_nand_readl(info, NAND_4BIT_ECC1_OFFSET);
return 0;
}
nand_davinci_readecc_4bit(info, raw_ecc);
for (i = 0, p = raw_ecc; i < 2; i++, p += 2) {
*ecc_code++ = p[0] & 0xff;
*ecc_code++ = ((p[0] >> 8) & 0x03) | ((p[0] >> 14) & 0xfc);
*ecc_code++ = ((p[0] >> 22) & 0x0f) | ((p[1] << 4) & 0xf0);
*ecc_code++ = ((p[1] >> 4) & 0x3f) | ((p[1] >> 10) & 0xc0);
*ecc_code++ = (p[1] >> 18) & 0xff;
}
return 0;
}
static int nand_davinci_correct_4bit(struct mtd_info *mtd,
u_char *data, u_char *ecc_code, u_char *null)
{
int i;
struct davinci_nand_info *info = to_davinci_nand(mtd);
unsigned short ecc10[8];
unsigned short *ecc16;
u32 syndrome[4];
u32 ecc_state;
unsigned num_errors, corrected;
unsigned long timeo;
for (i = 0; i < 10; i++) {
if (ecc_code[i] != 0xff)
goto compare;
}
return 0;
compare:
if (WARN_ON(0x01 & (unsigned) ecc_code))
return -EINVAL;
ecc16 = (unsigned short *)ecc_code;
ecc10[0] = (ecc16[0] >> 0) & 0x3ff;
ecc10[1] = ((ecc16[0] >> 10) & 0x3f) | ((ecc16[1] << 6) & 0x3c0);
ecc10[2] = (ecc16[1] >> 4) & 0x3ff;
ecc10[3] = ((ecc16[1] >> 14) & 0x3) | ((ecc16[2] << 2) & 0x3fc);
ecc10[4] = (ecc16[2] >> 8) | ((ecc16[3] << 8) & 0x300);
ecc10[5] = (ecc16[3] >> 2) & 0x3ff;
ecc10[6] = ((ecc16[3] >> 12) & 0xf) | ((ecc16[4] << 4) & 0x3f0);
ecc10[7] = (ecc16[4] >> 6) & 0x3ff;
for (i = 7; i >= 0; i--)
davinci_nand_writel(info, NAND_4BIT_ECC_LOAD_OFFSET, ecc10[i]);
davinci_nand_readl(info, NANDFSR_OFFSET);
nand_davinci_readecc_4bit(info, syndrome);
if (!(syndrome[0] | syndrome[1] | syndrome[2] | syndrome[3]))
return 0;
davinci_nand_readl(info, NAND_ERR_ADD1_OFFSET);
davinci_nand_writel(info, NANDFCR_OFFSET,
davinci_nand_readl(info, NANDFCR_OFFSET) | BIT(13));
timeo = jiffies + usecs_to_jiffies(100);
do {
ecc_state = (davinci_nand_readl(info,
NANDFSR_OFFSET) >> 8) & 0x0f;
cpu_relax();
} while ((ecc_state < 4) && time_before(jiffies, timeo));
for (;;) {
u32 fsr = davinci_nand_readl(info, NANDFSR_OFFSET);
switch ((fsr >> 8) & 0x0f) {
case 0:
davinci_nand_readl(info, NAND_ERR_ERRVAL1_OFFSET);
return 0;
case 1:
davinci_nand_readl(info, NAND_ERR_ERRVAL1_OFFSET);
return -EIO;
case 2:
case 3:
num_errors = 1 + ((fsr >> 16) & 0x03);
goto correct;
default:
cpu_relax();
continue;
}
}
correct:
for (i = 0, corrected = 0; i < num_errors; i++) {
int error_address, error_value;
if (i > 1) {
error_address = davinci_nand_readl(info,
NAND_ERR_ADD2_OFFSET);
error_value = davinci_nand_readl(info,
NAND_ERR_ERRVAL2_OFFSET);
} else {
error_address = davinci_nand_readl(info,
NAND_ERR_ADD1_OFFSET);
error_value = davinci_nand_readl(info,
NAND_ERR_ERRVAL1_OFFSET);
}
if (i & 1) {
error_address >>= 16;
error_value >>= 16;
}
error_address &= 0x3ff;
error_address = (512 + 7) - error_address;
if (error_address < 512) {
data[error_address] ^= error_value;
corrected++;
}
}
return corrected;
}
static void nand_davinci_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct nand_chip *chip = mtd->priv;
if ((0x03 & ((unsigned)buf)) == 0 && (0x03 & len) == 0)
ioread32_rep(chip->IO_ADDR_R, buf, len >> 2);
else if ((0x01 & ((unsigned)buf)) == 0 && (0x01 & len) == 0)
ioread16_rep(chip->IO_ADDR_R, buf, len >> 1);
else
ioread8_rep(chip->IO_ADDR_R, buf, len);
}
static void nand_davinci_write_buf(struct mtd_info *mtd,
const uint8_t *buf, int len)
{
struct nand_chip *chip = mtd->priv;
if ((0x03 & ((unsigned)buf)) == 0 && (0x03 & len) == 0)
iowrite32_rep(chip->IO_ADDR_R, buf, len >> 2);
else if ((0x01 & ((unsigned)buf)) == 0 && (0x01 & len) == 0)
iowrite16_rep(chip->IO_ADDR_R, buf, len >> 1);
else
iowrite8_rep(chip->IO_ADDR_R, buf, len);
}
static int nand_davinci_dev_ready(struct mtd_info *mtd)
{
struct davinci_nand_info *info = to_davinci_nand(mtd);
return davinci_nand_readl(info, NANDFSR_OFFSET) & BIT(0);
}
static struct davinci_nand_pdata
*nand_davinci_get_pdata(struct platform_device *pdev)
{
if (!dev_get_platdata(&pdev->dev) && pdev->dev.of_node) {
struct davinci_nand_pdata *pdata;
const char *mode;
u32 prop;
pdata = devm_kzalloc(&pdev->dev,
sizeof(struct davinci_nand_pdata),
GFP_KERNEL);
pdev->dev.platform_data = pdata;
if (!pdata)
return ERR_PTR(-ENOMEM);
if (!of_property_read_u32(pdev->dev.of_node,
"ti,davinci-chipselect", &prop))
pdev->id = prop;
else
return ERR_PTR(-EINVAL);
if (!of_property_read_u32(pdev->dev.of_node,
"ti,davinci-mask-ale", &prop))
pdata->mask_ale = prop;
if (!of_property_read_u32(pdev->dev.of_node,
"ti,davinci-mask-cle", &prop))
pdata->mask_cle = prop;
if (!of_property_read_u32(pdev->dev.of_node,
"ti,davinci-mask-chipsel", &prop))
pdata->mask_chipsel = prop;
if (!of_property_read_string(pdev->dev.of_node,
"nand-ecc-mode", &mode) ||
!of_property_read_string(pdev->dev.of_node,
"ti,davinci-ecc-mode", &mode)) {
if (!strncmp("none", mode, 4))
pdata->ecc_mode = NAND_ECC_NONE;
if (!strncmp("soft", mode, 4))
pdata->ecc_mode = NAND_ECC_SOFT;
if (!strncmp("hw", mode, 2))
pdata->ecc_mode = NAND_ECC_HW;
}
if (!of_property_read_u32(pdev->dev.of_node,
"ti,davinci-ecc-bits", &prop))
pdata->ecc_bits = prop;
prop = of_get_nand_bus_width(pdev->dev.of_node);
if (0 < prop || !of_property_read_u32(pdev->dev.of_node,
"ti,davinci-nand-buswidth", &prop))
if (prop == 16)
pdata->options |= NAND_BUSWIDTH_16;
if (of_property_read_bool(pdev->dev.of_node,
"nand-on-flash-bbt") ||
of_property_read_bool(pdev->dev.of_node,
"ti,davinci-nand-use-bbt"))
pdata->bbt_options = NAND_BBT_USE_FLASH;
if (of_device_is_compatible(pdev->dev.of_node,
"ti,keystone-nand")) {
pdata->options |= NAND_NO_SUBPAGE_WRITE;
}
}
return dev_get_platdata(&pdev->dev);
}
static struct davinci_nand_pdata
*nand_davinci_get_pdata(struct platform_device *pdev)
{
return dev_get_platdata(&pdev->dev);
}
static int nand_davinci_probe(struct platform_device *pdev)
{
struct davinci_nand_pdata *pdata;
struct davinci_nand_info *info;
struct resource *res1;
struct resource *res2;
void __iomem *vaddr;
void __iomem *base;
int ret;
uint32_t val;
nand_ecc_modes_t ecc_mode;
pdata = nand_davinci_get_pdata(pdev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
if (!pdata)
return -ENODEV;
if (pdev->id < 0 || pdev->id > 3)
return -ENODEV;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
platform_set_drvdata(pdev, info);
res1 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
res2 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res1 || !res2) {
dev_err(&pdev->dev, "resource missing\n");
return -EINVAL;
}
vaddr = devm_ioremap_resource(&pdev->dev, res1);
if (IS_ERR(vaddr))
return PTR_ERR(vaddr);
base = devm_ioremap(&pdev->dev, res2->start, resource_size(res2));
if (!base) {
dev_err(&pdev->dev, "ioremap failed for resource %pR\n", res2);
return -EADDRNOTAVAIL;
}
info->dev = &pdev->dev;
info->base = base;
info->vaddr = vaddr;
info->mtd.priv = &info->chip;
info->mtd.name = dev_name(&pdev->dev);
info->mtd.owner = THIS_MODULE;
info->mtd.dev.parent = &pdev->dev;
info->chip.IO_ADDR_R = vaddr;
info->chip.IO_ADDR_W = vaddr;
info->chip.chip_delay = 0;
info->chip.select_chip = nand_davinci_select_chip;
info->chip.bbt_options = pdata->bbt_options;
info->chip.options = pdata->options;
info->chip.bbt_td = pdata->bbt_td;
info->chip.bbt_md = pdata->bbt_md;
info->timing = pdata->timing;
info->ioaddr = (uint32_t __force) vaddr;
info->current_cs = info->ioaddr;
info->core_chipsel = pdev->id;
info->mask_chipsel = pdata->mask_chipsel;
info->mask_ale = pdata->mask_ale ? : MASK_ALE;
info->mask_cle = pdata->mask_cle ? : MASK_CLE;
info->chip.cmd_ctrl = nand_davinci_hwcontrol;
info->chip.dev_ready = nand_davinci_dev_ready;
info->chip.read_buf = nand_davinci_read_buf;
info->chip.write_buf = nand_davinci_write_buf;
ecc_mode = pdata->ecc_mode;
ret = -EINVAL;
switch (ecc_mode) {
case NAND_ECC_NONE:
case NAND_ECC_SOFT:
pdata->ecc_bits = 0;
break;
case NAND_ECC_HW:
if (pdata->ecc_bits == 4) {
spin_lock_irq(&davinci_nand_lock);
if (ecc4_busy)
ret = -EBUSY;
else
ecc4_busy = true;
spin_unlock_irq(&davinci_nand_lock);
if (ret == -EBUSY)
return ret;
info->chip.ecc.calculate = nand_davinci_calculate_4bit;
info->chip.ecc.correct = nand_davinci_correct_4bit;
info->chip.ecc.hwctl = nand_davinci_hwctl_4bit;
info->chip.ecc.bytes = 10;
} else {
info->chip.ecc.calculate = nand_davinci_calculate_1bit;
info->chip.ecc.correct = nand_davinci_correct_1bit;
info->chip.ecc.hwctl = nand_davinci_hwctl_1bit;
info->chip.ecc.bytes = 3;
}
info->chip.ecc.size = 512;
info->chip.ecc.strength = pdata->ecc_bits;
break;
default:
return -EINVAL;
}
info->chip.ecc.mode = ecc_mode;
info->clk = devm_clk_get(&pdev->dev, "aemif");
if (IS_ERR(info->clk)) {
ret = PTR_ERR(info->clk);
dev_dbg(&pdev->dev, "unable to get AEMIF clock, err %d\n", ret);
return ret;
}
ret = clk_prepare_enable(info->clk);
if (ret < 0) {
dev_dbg(&pdev->dev, "unable to enable AEMIF clock, err %d\n",
ret);
goto err_clk_enable;
}
spin_lock_irq(&davinci_nand_lock);
val = davinci_nand_readl(info, NANDFCR_OFFSET);
val |= BIT(info->core_chipsel);
davinci_nand_writel(info, NANDFCR_OFFSET, val);
spin_unlock_irq(&davinci_nand_lock);
ret = nand_scan_ident(&info->mtd, pdata->mask_chipsel ? 2 : 1, NULL);
if (ret < 0) {
dev_dbg(&pdev->dev, "no NAND chip(s) found\n");
goto err;
}
if (pdata->ecc_bits == 4) {
int chunks = info->mtd.writesize / 512;
if (!chunks || info->mtd.oobsize < 16) {
dev_dbg(&pdev->dev, "too small\n");
ret = -EINVAL;
goto err;
}
if (chunks == 1) {
info->ecclayout = hwecc4_small;
info->ecclayout.oobfree[1].length =
info->mtd.oobsize - 16;
goto syndrome_done;
}
if (chunks == 4) {
info->ecclayout = hwecc4_2048;
info->chip.ecc.mode = NAND_ECC_HW_OOB_FIRST;
goto syndrome_done;
}
dev_warn(&pdev->dev, "no 4-bit ECC support yet "
"for 4KiB-page NAND\n");
ret = -EIO;
goto err;
syndrome_done:
info->chip.ecc.layout = &info->ecclayout;
}
ret = nand_scan_tail(&info->mtd);
if (ret < 0)
goto err;
if (pdata->parts)
ret = mtd_device_parse_register(&info->mtd, NULL, NULL,
pdata->parts, pdata->nr_parts);
else {
struct mtd_part_parser_data ppdata;
ppdata.of_node = pdev->dev.of_node;
ret = mtd_device_parse_register(&info->mtd, NULL, &ppdata,
NULL, 0);
}
if (ret < 0)
goto err;
val = davinci_nand_readl(info, NRCSR_OFFSET);
dev_info(&pdev->dev, "controller rev. %d.%d\n",
(val >> 8) & 0xff, val & 0xff);
return 0;
err:
clk_disable_unprepare(info->clk);
err_clk_enable:
spin_lock_irq(&davinci_nand_lock);
if (ecc_mode == NAND_ECC_HW_SYNDROME)
ecc4_busy = false;
spin_unlock_irq(&davinci_nand_lock);
return ret;
}
static int nand_davinci_remove(struct platform_device *pdev)
{
struct davinci_nand_info *info = platform_get_drvdata(pdev);
spin_lock_irq(&davinci_nand_lock);
if (info->chip.ecc.mode == NAND_ECC_HW_SYNDROME)
ecc4_busy = false;
spin_unlock_irq(&davinci_nand_lock);
nand_release(&info->mtd);
clk_disable_unprepare(info->clk);
return 0;
}
