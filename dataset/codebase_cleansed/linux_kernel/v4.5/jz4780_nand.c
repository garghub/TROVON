static inline struct jz4780_nand_chip *to_jz4780_nand_chip(struct mtd_info *mtd)
{
return container_of(mtd_to_nand(mtd), struct jz4780_nand_chip, chip);
}
static inline struct jz4780_nand_controller *to_jz4780_nand_controller(struct nand_hw_control *ctrl)
{
return container_of(ctrl, struct jz4780_nand_controller, controller);
}
static void jz4780_nand_select_chip(struct mtd_info *mtd, int chipnr)
{
struct jz4780_nand_chip *nand = to_jz4780_nand_chip(mtd);
struct jz4780_nand_controller *nfc = to_jz4780_nand_controller(nand->chip.controller);
struct jz4780_nand_cs *cs;
if (chipnr == -1 && nfc->selected >= 0) {
cs = &nfc->cs[nfc->selected];
jz4780_nemc_assert(nfc->dev, cs->bank, false);
}
nfc->selected = chipnr;
}
static void jz4780_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct jz4780_nand_chip *nand = to_jz4780_nand_chip(mtd);
struct jz4780_nand_controller *nfc = to_jz4780_nand_controller(nand->chip.controller);
struct jz4780_nand_cs *cs;
if (WARN_ON(nfc->selected < 0))
return;
cs = &nfc->cs[nfc->selected];
jz4780_nemc_assert(nfc->dev, cs->bank, ctrl & NAND_NCE);
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_ALE)
writeb(cmd, cs->base + OFFSET_ADDR);
else if (ctrl & NAND_CLE)
writeb(cmd, cs->base + OFFSET_CMD);
}
static int jz4780_nand_dev_ready(struct mtd_info *mtd)
{
struct jz4780_nand_chip *nand = to_jz4780_nand_chip(mtd);
return !gpiod_get_value_cansleep(nand->busy_gpio);
}
static void jz4780_nand_ecc_hwctl(struct mtd_info *mtd, int mode)
{
struct jz4780_nand_chip *nand = to_jz4780_nand_chip(mtd);
nand->reading = (mode == NAND_ECC_READ);
}
static int jz4780_nand_ecc_calculate(struct mtd_info *mtd, const u8 *dat,
u8 *ecc_code)
{
struct jz4780_nand_chip *nand = to_jz4780_nand_chip(mtd);
struct jz4780_nand_controller *nfc = to_jz4780_nand_controller(nand->chip.controller);
struct jz4780_bch_params params;
if (nand->reading)
return 0;
params.size = nand->chip.ecc.size;
params.bytes = nand->chip.ecc.bytes;
params.strength = nand->chip.ecc.strength;
return jz4780_bch_calculate(nfc->bch, &params, dat, ecc_code);
}
static int jz4780_nand_ecc_correct(struct mtd_info *mtd, u8 *dat,
u8 *read_ecc, u8 *calc_ecc)
{
struct jz4780_nand_chip *nand = to_jz4780_nand_chip(mtd);
struct jz4780_nand_controller *nfc = to_jz4780_nand_controller(nand->chip.controller);
struct jz4780_bch_params params;
params.size = nand->chip.ecc.size;
params.bytes = nand->chip.ecc.bytes;
params.strength = nand->chip.ecc.strength;
return jz4780_bch_correct(nfc->bch, &params, dat, read_ecc);
}
static int jz4780_nand_init_ecc(struct jz4780_nand_chip *nand, struct device *dev)
{
struct nand_chip *chip = &nand->chip;
struct mtd_info *mtd = nand_to_mtd(chip);
struct jz4780_nand_controller *nfc = to_jz4780_nand_controller(chip->controller);
struct nand_ecclayout *layout = &nand->ecclayout;
u32 start, i;
chip->ecc.bytes = fls((1 + 8) * chip->ecc.size) *
(chip->ecc.strength / 8);
switch (chip->ecc.mode) {
case NAND_ECC_HW:
if (!nfc->bch) {
dev_err(dev, "HW BCH selected, but BCH controller not found\n");
return -ENODEV;
}
chip->ecc.hwctl = jz4780_nand_ecc_hwctl;
chip->ecc.calculate = jz4780_nand_ecc_calculate;
chip->ecc.correct = jz4780_nand_ecc_correct;
case NAND_ECC_SOFT:
case NAND_ECC_SOFT_BCH:
dev_info(dev, "using %s (strength %d, size %d, bytes %d)\n",
(nfc->bch) ? "hardware BCH" : "software ECC",
chip->ecc.strength, chip->ecc.size, chip->ecc.bytes);
break;
case NAND_ECC_NONE:
dev_info(dev, "not using ECC\n");
break;
default:
dev_err(dev, "ECC mode %d not supported\n", chip->ecc.mode);
return -EINVAL;
}
if (chip->ecc.mode != NAND_ECC_HW)
return 0;
layout->eccbytes = mtd->writesize / chip->ecc.size * chip->ecc.bytes;
if (layout->eccbytes > mtd->oobsize - 2) {
dev_err(dev,
"invalid ECC config: required %d ECC bytes, but only %d are available",
layout->eccbytes, mtd->oobsize - 2);
return -EINVAL;
}
start = mtd->oobsize - layout->eccbytes;
for (i = 0; i < layout->eccbytes; i++)
layout->eccpos[i] = start + i;
layout->oobfree[0].offset = 2;
layout->oobfree[0].length = mtd->oobsize - layout->eccbytes - 2;
chip->ecc.layout = layout;
return 0;
}
static int jz4780_nand_init_chip(struct platform_device *pdev,
struct jz4780_nand_controller *nfc,
struct device_node *np,
unsigned int chipnr)
{
struct device *dev = &pdev->dev;
struct jz4780_nand_chip *nand;
struct jz4780_nand_cs *cs;
struct resource *res;
struct nand_chip *chip;
struct mtd_info *mtd;
const __be32 *reg;
int ret = 0;
cs = &nfc->cs[chipnr];
reg = of_get_property(np, "reg", NULL);
if (!reg)
return -EINVAL;
cs->bank = be32_to_cpu(*reg);
jz4780_nemc_set_type(nfc->dev, cs->bank, JZ4780_NEMC_BANK_NAND);
res = platform_get_resource(pdev, IORESOURCE_MEM, chipnr);
cs->base = devm_ioremap_resource(dev, res);
if (IS_ERR(cs->base))
return PTR_ERR(cs->base);
nand = devm_kzalloc(dev, sizeof(*nand), GFP_KERNEL);
if (!nand)
return -ENOMEM;
nand->busy_gpio = devm_gpiod_get_optional(dev, "rb", GPIOD_IN);
if (IS_ERR(nand->busy_gpio)) {
ret = PTR_ERR(nand->busy_gpio);
dev_err(dev, "failed to request busy GPIO: %d\n", ret);
return ret;
} else if (nand->busy_gpio) {
nand->chip.dev_ready = jz4780_nand_dev_ready;
}
nand->wp_gpio = devm_gpiod_get_optional(dev, "wp", GPIOD_OUT_LOW);
if (IS_ERR(nand->wp_gpio)) {
ret = PTR_ERR(nand->wp_gpio);
dev_err(dev, "failed to request WP GPIO: %d\n", ret);
return ret;
}
chip = &nand->chip;
mtd = nand_to_mtd(chip);
mtd->name = devm_kasprintf(dev, GFP_KERNEL, "%s.%d", dev_name(dev),
cs->bank);
if (!mtd->name)
return -ENOMEM;
mtd->dev.parent = dev;
chip->IO_ADDR_R = cs->base + OFFSET_DATA;
chip->IO_ADDR_W = cs->base + OFFSET_DATA;
chip->chip_delay = RB_DELAY_US;
chip->options = NAND_NO_SUBPAGE_WRITE;
chip->select_chip = jz4780_nand_select_chip;
chip->cmd_ctrl = jz4780_nand_cmd_ctrl;
chip->ecc.mode = NAND_ECC_HW;
chip->controller = &nfc->controller;
nand_set_flash_node(chip, np);
ret = nand_scan_ident(mtd, 1, NULL);
if (ret)
return ret;
ret = jz4780_nand_init_ecc(nand, dev);
if (ret)
return ret;
ret = nand_scan_tail(mtd);
if (ret)
return ret;
ret = mtd_device_register(mtd, NULL, 0);
if (ret) {
nand_release(mtd);
return ret;
}
list_add_tail(&nand->chip_list, &nfc->chips);
return 0;
}
static void jz4780_nand_cleanup_chips(struct jz4780_nand_controller *nfc)
{
struct jz4780_nand_chip *chip;
while (!list_empty(&nfc->chips)) {
chip = list_first_entry(&nfc->chips, struct jz4780_nand_chip, chip_list);
nand_release(nand_to_mtd(&chip->chip));
list_del(&chip->chip_list);
}
}
static int jz4780_nand_init_chips(struct jz4780_nand_controller *nfc,
struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np;
int i = 0;
int ret;
int num_chips = of_get_child_count(dev->of_node);
if (num_chips > nfc->num_banks) {
dev_err(dev, "found %d chips but only %d banks\n", num_chips, nfc->num_banks);
return -EINVAL;
}
for_each_child_of_node(dev->of_node, np) {
ret = jz4780_nand_init_chip(pdev, nfc, np, i);
if (ret) {
jz4780_nand_cleanup_chips(nfc);
return ret;
}
i++;
}
return 0;
}
static int jz4780_nand_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
unsigned int num_banks;
struct jz4780_nand_controller *nfc;
int ret;
num_banks = jz4780_nemc_num_banks(dev);
if (num_banks == 0) {
dev_err(dev, "no banks found\n");
return -ENODEV;
}
nfc = devm_kzalloc(dev, sizeof(*nfc) + (sizeof(nfc->cs[0]) * num_banks), GFP_KERNEL);
if (!nfc)
return -ENOMEM;
nfc->bch = of_jz4780_bch_get(dev->of_node);
if (IS_ERR(nfc->bch))
return PTR_ERR(nfc->bch);
nfc->dev = dev;
nfc->num_banks = num_banks;
spin_lock_init(&nfc->controller.lock);
INIT_LIST_HEAD(&nfc->chips);
init_waitqueue_head(&nfc->controller.wq);
ret = jz4780_nand_init_chips(nfc, pdev);
if (ret) {
if (nfc->bch)
jz4780_bch_release(nfc->bch);
return ret;
}
platform_set_drvdata(pdev, nfc);
return 0;
}
static int jz4780_nand_remove(struct platform_device *pdev)
{
struct jz4780_nand_controller *nfc = platform_get_drvdata(pdev);
if (nfc->bch)
jz4780_bch_release(nfc->bch);
jz4780_nand_cleanup_chips(nfc);
return 0;
}
