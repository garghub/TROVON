static struct platform_device *mtd_to_platdev(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
struct txx9ndfmc_priv *txx9_priv = chip->priv;
return txx9_priv->dev;
}
static void __iomem *ndregaddr(struct platform_device *dev, unsigned int reg)
{
struct txx9ndfmc_drvdata *drvdata = platform_get_drvdata(dev);
struct txx9ndfmc_platform_data *plat = dev_get_platdata(&dev->dev);
return drvdata->base + (reg << plat->shift);
}
static u32 txx9ndfmc_read(struct platform_device *dev, unsigned int reg)
{
return __raw_readl(ndregaddr(dev, reg));
}
static void txx9ndfmc_write(struct platform_device *dev,
u32 val, unsigned int reg)
{
__raw_writel(val, ndregaddr(dev, reg));
}
static uint8_t txx9ndfmc_read_byte(struct mtd_info *mtd)
{
struct platform_device *dev = mtd_to_platdev(mtd);
return txx9ndfmc_read(dev, TXX9_NDFDTR);
}
static void txx9ndfmc_write_buf(struct mtd_info *mtd, const uint8_t *buf,
int len)
{
struct platform_device *dev = mtd_to_platdev(mtd);
void __iomem *ndfdtr = ndregaddr(dev, TXX9_NDFDTR);
u32 mcr = txx9ndfmc_read(dev, TXX9_NDFMCR);
txx9ndfmc_write(dev, mcr | TXX9_NDFMCR_WE, TXX9_NDFMCR);
while (len--)
__raw_writel(*buf++, ndfdtr);
txx9ndfmc_write(dev, mcr, TXX9_NDFMCR);
}
static void txx9ndfmc_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct platform_device *dev = mtd_to_platdev(mtd);
void __iomem *ndfdtr = ndregaddr(dev, TXX9_NDFDTR);
while (len--)
*buf++ = __raw_readl(ndfdtr);
}
static void txx9ndfmc_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *chip = mtd->priv;
struct txx9ndfmc_priv *txx9_priv = chip->priv;
struct platform_device *dev = txx9_priv->dev;
struct txx9ndfmc_platform_data *plat = dev_get_platdata(&dev->dev);
if (ctrl & NAND_CTRL_CHANGE) {
u32 mcr = txx9ndfmc_read(dev, TXX9_NDFMCR);
mcr &= ~(TXX9_NDFMCR_CLE | TXX9_NDFMCR_ALE | TXX9_NDFMCR_CE);
mcr |= ctrl & NAND_CLE ? TXX9_NDFMCR_CLE : 0;
mcr |= ctrl & NAND_ALE ? TXX9_NDFMCR_ALE : 0;
mcr |= ctrl & NAND_NCE ? TXX9_NDFMCR_CE : 0;
if (txx9_priv->cs >= 0 && (ctrl & NAND_NCE)) {
mcr &= ~TXX9_NDFMCR_CS_MASK;
mcr |= TXX9_NDFMCR_CS(txx9_priv->cs);
}
txx9ndfmc_write(dev, mcr, TXX9_NDFMCR);
}
if (cmd != NAND_CMD_NONE)
txx9ndfmc_write(dev, cmd & 0xff, TXX9_NDFDTR);
if (plat->flags & NDFMC_PLAT_FLAG_DUMMYWRITE) {
if ((ctrl & NAND_CTRL_CHANGE) && cmd == NAND_CMD_NONE)
txx9ndfmc_write(dev, 0, TXX9_NDFDTR);
}
mmiowb();
}
static int txx9ndfmc_dev_ready(struct mtd_info *mtd)
{
struct platform_device *dev = mtd_to_platdev(mtd);
return !(txx9ndfmc_read(dev, TXX9_NDFSR) & TXX9_NDFSR_BUSY);
}
static int txx9ndfmc_calculate_ecc(struct mtd_info *mtd, const uint8_t *dat,
uint8_t *ecc_code)
{
struct platform_device *dev = mtd_to_platdev(mtd);
struct nand_chip *chip = mtd->priv;
int eccbytes;
u32 mcr = txx9ndfmc_read(dev, TXX9_NDFMCR);
mcr &= ~TXX9_NDFMCR_ECC_ALL;
txx9ndfmc_write(dev, mcr | TXX9_NDFMCR_ECC_OFF, TXX9_NDFMCR);
txx9ndfmc_write(dev, mcr | TXX9_NDFMCR_ECC_READ, TXX9_NDFMCR);
for (eccbytes = chip->ecc.bytes; eccbytes > 0; eccbytes -= 3) {
ecc_code[1] = txx9ndfmc_read(dev, TXX9_NDFDTR);
ecc_code[0] = txx9ndfmc_read(dev, TXX9_NDFDTR);
ecc_code[2] = txx9ndfmc_read(dev, TXX9_NDFDTR);
ecc_code += 3;
}
txx9ndfmc_write(dev, mcr | TXX9_NDFMCR_ECC_OFF, TXX9_NDFMCR);
return 0;
}
static int txx9ndfmc_correct_data(struct mtd_info *mtd, unsigned char *buf,
unsigned char *read_ecc, unsigned char *calc_ecc)
{
struct nand_chip *chip = mtd->priv;
int eccsize;
int corrected = 0;
int stat;
for (eccsize = chip->ecc.size; eccsize > 0; eccsize -= 256) {
stat = __nand_correct_data(buf, read_ecc, calc_ecc, 256);
if (stat < 0)
return stat;
corrected += stat;
buf += 256;
read_ecc += 3;
calc_ecc += 3;
}
return corrected;
}
static void txx9ndfmc_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct platform_device *dev = mtd_to_platdev(mtd);
u32 mcr = txx9ndfmc_read(dev, TXX9_NDFMCR);
mcr &= ~TXX9_NDFMCR_ECC_ALL;
txx9ndfmc_write(dev, mcr | TXX9_NDFMCR_ECC_RESET, TXX9_NDFMCR);
txx9ndfmc_write(dev, mcr | TXX9_NDFMCR_ECC_OFF, TXX9_NDFMCR);
txx9ndfmc_write(dev, mcr | TXX9_NDFMCR_ECC_ON, TXX9_NDFMCR);
}
static void txx9ndfmc_initialize(struct platform_device *dev)
{
struct txx9ndfmc_platform_data *plat = dev_get_platdata(&dev->dev);
struct txx9ndfmc_drvdata *drvdata = platform_get_drvdata(dev);
int tmout = 100;
if (plat->flags & NDFMC_PLAT_FLAG_NO_RSTR)
;
else {
txx9ndfmc_write(dev,
txx9ndfmc_read(dev, TXX9_NDFRSTR) |
TXX9_NDFRSTR_RST,
TXX9_NDFRSTR);
while (txx9ndfmc_read(dev, TXX9_NDFRSTR) & TXX9_NDFRSTR_RST) {
if (--tmout == 0) {
dev_err(&dev->dev, "reset failed.\n");
break;
}
udelay(1);
}
}
txx9ndfmc_write(dev, (drvdata->hold << 4) | drvdata->spw, TXX9_NDFSPR);
txx9ndfmc_write(dev,
(plat->flags & NDFMC_PLAT_FLAG_USE_BSPRT) ?
TXX9_NDFMCR_BSPRT : 0, TXX9_NDFMCR);
}
static int txx9ndfmc_nand_scan(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
int ret;
ret = nand_scan_ident(mtd, 1, NULL);
if (!ret) {
if (mtd->writesize >= 512) {
chip->ecc.size = 512;
chip->ecc.bytes = 6;
}
ret = nand_scan_tail(mtd);
}
return ret;
}
static int __init txx9ndfmc_probe(struct platform_device *dev)
{
struct txx9ndfmc_platform_data *plat = dev_get_platdata(&dev->dev);
int hold, spw;
int i;
struct txx9ndfmc_drvdata *drvdata;
unsigned long gbusclk = plat->gbus_clock;
struct resource *res;
drvdata = devm_kzalloc(&dev->dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
drvdata->base = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(drvdata->base))
return PTR_ERR(drvdata->base);
hold = plat->hold ?: 20;
spw = plat->spw ?: 90;
hold = TXX9NDFMC_NS_TO_CYC(gbusclk, hold);
spw = TXX9NDFMC_NS_TO_CYC(gbusclk, spw);
if (plat->flags & NDFMC_PLAT_FLAG_HOLDADD)
hold -= 2;
spw -= 1;
hold = clamp(hold, 1, 15);
drvdata->hold = hold;
spw = clamp(spw, 1, 15);
drvdata->spw = spw;
dev_info(&dev->dev, "CLK:%ldMHz HOLD:%d SPW:%d\n",
(gbusclk + 500000) / 1000000, hold, spw);
spin_lock_init(&drvdata->hw_control.lock);
init_waitqueue_head(&drvdata->hw_control.wq);
platform_set_drvdata(dev, drvdata);
txx9ndfmc_initialize(dev);
for (i = 0; i < MAX_TXX9NDFMC_DEV; i++) {
struct txx9ndfmc_priv *txx9_priv;
struct nand_chip *chip;
struct mtd_info *mtd;
if (!(plat->ch_mask & (1 << i)))
continue;
txx9_priv = kzalloc(sizeof(struct txx9ndfmc_priv),
GFP_KERNEL);
if (!txx9_priv)
continue;
chip = &txx9_priv->chip;
mtd = &txx9_priv->mtd;
mtd->dev.parent = &dev->dev;
mtd->priv = chip;
chip->read_byte = txx9ndfmc_read_byte;
chip->read_buf = txx9ndfmc_read_buf;
chip->write_buf = txx9ndfmc_write_buf;
chip->cmd_ctrl = txx9ndfmc_cmd_ctrl;
chip->dev_ready = txx9ndfmc_dev_ready;
chip->ecc.calculate = txx9ndfmc_calculate_ecc;
chip->ecc.correct = txx9ndfmc_correct_data;
chip->ecc.hwctl = txx9ndfmc_enable_hwecc;
chip->ecc.mode = NAND_ECC_HW;
chip->ecc.size = 256;
chip->ecc.bytes = 3;
chip->ecc.strength = 1;
chip->chip_delay = 100;
chip->controller = &drvdata->hw_control;
chip->priv = txx9_priv;
txx9_priv->dev = dev;
if (plat->ch_mask != 1) {
txx9_priv->cs = i;
txx9_priv->mtdname = kasprintf(GFP_KERNEL, "%s.%u",
dev_name(&dev->dev), i);
} else {
txx9_priv->cs = -1;
txx9_priv->mtdname = kstrdup(dev_name(&dev->dev),
GFP_KERNEL);
}
if (!txx9_priv->mtdname) {
kfree(txx9_priv);
dev_err(&dev->dev, "Unable to allocate MTD name.\n");
continue;
}
if (plat->wide_mask & (1 << i))
chip->options |= NAND_BUSWIDTH_16;
if (txx9ndfmc_nand_scan(mtd)) {
kfree(txx9_priv->mtdname);
kfree(txx9_priv);
continue;
}
mtd->name = txx9_priv->mtdname;
mtd_device_parse_register(mtd, NULL, NULL, NULL, 0);
drvdata->mtds[i] = mtd;
}
return 0;
}
static int __exit txx9ndfmc_remove(struct platform_device *dev)
{
struct txx9ndfmc_drvdata *drvdata = platform_get_drvdata(dev);
int i;
if (!drvdata)
return 0;
for (i = 0; i < MAX_TXX9NDFMC_DEV; i++) {
struct mtd_info *mtd = drvdata->mtds[i];
struct nand_chip *chip;
struct txx9ndfmc_priv *txx9_priv;
if (!mtd)
continue;
chip = mtd->priv;
txx9_priv = chip->priv;
nand_release(mtd);
kfree(txx9_priv->mtdname);
kfree(txx9_priv);
}
return 0;
}
static int txx9ndfmc_resume(struct platform_device *dev)
{
if (platform_get_drvdata(dev))
txx9ndfmc_initialize(dev);
return 0;
}
