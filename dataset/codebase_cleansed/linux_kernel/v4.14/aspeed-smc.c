static int aspeed_smc_read_from_ahb(void *buf, void __iomem *src, size_t len)
{
size_t offset = 0;
if (IS_ALIGNED((uintptr_t)src, sizeof(uintptr_t)) &&
IS_ALIGNED((uintptr_t)buf, sizeof(uintptr_t))) {
ioread32_rep(src, buf, len >> 2);
offset = len & ~0x3;
len -= offset;
}
ioread8_rep(src, (u8 *)buf + offset, len);
return 0;
}
static int aspeed_smc_write_to_ahb(void __iomem *dst, const void *buf,
size_t len)
{
size_t offset = 0;
if (IS_ALIGNED((uintptr_t)dst, sizeof(uintptr_t)) &&
IS_ALIGNED((uintptr_t)buf, sizeof(uintptr_t))) {
iowrite32_rep(dst, buf, len >> 2);
offset = len & ~0x3;
len -= offset;
}
iowrite8_rep(dst, (const u8 *)buf + offset, len);
return 0;
}
static inline u32 aspeed_smc_chip_write_bit(struct aspeed_smc_chip *chip)
{
return BIT(chip->controller->info->we0 + chip->cs);
}
static void aspeed_smc_chip_check_config(struct aspeed_smc_chip *chip)
{
struct aspeed_smc_controller *controller = chip->controller;
u32 reg;
reg = readl(controller->regs + CONFIG_REG);
if (reg & aspeed_smc_chip_write_bit(chip))
return;
dev_dbg(controller->dev, "config write is not set ! @%p: 0x%08x\n",
controller->regs + CONFIG_REG, reg);
reg |= aspeed_smc_chip_write_bit(chip);
writel(reg, controller->regs + CONFIG_REG);
}
static void aspeed_smc_start_user(struct spi_nor *nor)
{
struct aspeed_smc_chip *chip = nor->priv;
u32 ctl = chip->ctl_val[smc_base];
aspeed_smc_chip_check_config(chip);
ctl |= CONTROL_COMMAND_MODE_USER |
CONTROL_CE_STOP_ACTIVE_CONTROL;
writel(ctl, chip->ctl);
ctl &= ~CONTROL_CE_STOP_ACTIVE_CONTROL;
writel(ctl, chip->ctl);
}
static void aspeed_smc_stop_user(struct spi_nor *nor)
{
struct aspeed_smc_chip *chip = nor->priv;
u32 ctl = chip->ctl_val[smc_read];
u32 ctl2 = ctl | CONTROL_COMMAND_MODE_USER |
CONTROL_CE_STOP_ACTIVE_CONTROL;
writel(ctl2, chip->ctl);
writel(ctl, chip->ctl);
}
static int aspeed_smc_prep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct aspeed_smc_chip *chip = nor->priv;
mutex_lock(&chip->controller->mutex);
return 0;
}
static void aspeed_smc_unprep(struct spi_nor *nor, enum spi_nor_ops ops)
{
struct aspeed_smc_chip *chip = nor->priv;
mutex_unlock(&chip->controller->mutex);
}
static int aspeed_smc_read_reg(struct spi_nor *nor, u8 opcode, u8 *buf, int len)
{
struct aspeed_smc_chip *chip = nor->priv;
aspeed_smc_start_user(nor);
aspeed_smc_write_to_ahb(chip->ahb_base, &opcode, 1);
aspeed_smc_read_from_ahb(buf, chip->ahb_base, len);
aspeed_smc_stop_user(nor);
return 0;
}
static int aspeed_smc_write_reg(struct spi_nor *nor, u8 opcode, u8 *buf,
int len)
{
struct aspeed_smc_chip *chip = nor->priv;
aspeed_smc_start_user(nor);
aspeed_smc_write_to_ahb(chip->ahb_base, &opcode, 1);
aspeed_smc_write_to_ahb(chip->ahb_base, buf, len);
aspeed_smc_stop_user(nor);
return 0;
}
static void aspeed_smc_send_cmd_addr(struct spi_nor *nor, u8 cmd, u32 addr)
{
struct aspeed_smc_chip *chip = nor->priv;
__be32 temp;
u32 cmdaddr;
switch (nor->addr_width) {
default:
WARN_ONCE(1, "Unexpected address width %u, defaulting to 3\n",
nor->addr_width);
case 3:
cmdaddr = addr & 0xFFFFFF;
cmdaddr |= cmd << 24;
temp = cpu_to_be32(cmdaddr);
aspeed_smc_write_to_ahb(chip->ahb_base, &temp, 4);
break;
case 4:
temp = cpu_to_be32(addr);
aspeed_smc_write_to_ahb(chip->ahb_base, &cmd, 1);
aspeed_smc_write_to_ahb(chip->ahb_base, &temp, 4);
break;
}
}
static ssize_t aspeed_smc_read_user(struct spi_nor *nor, loff_t from,
size_t len, u_char *read_buf)
{
struct aspeed_smc_chip *chip = nor->priv;
int i;
u8 dummy = 0xFF;
aspeed_smc_start_user(nor);
aspeed_smc_send_cmd_addr(nor, nor->read_opcode, from);
for (i = 0; i < chip->nor.read_dummy / 8; i++)
aspeed_smc_write_to_ahb(chip->ahb_base, &dummy, sizeof(dummy));
aspeed_smc_read_from_ahb(read_buf, chip->ahb_base, len);
aspeed_smc_stop_user(nor);
return len;
}
static ssize_t aspeed_smc_write_user(struct spi_nor *nor, loff_t to,
size_t len, const u_char *write_buf)
{
struct aspeed_smc_chip *chip = nor->priv;
aspeed_smc_start_user(nor);
aspeed_smc_send_cmd_addr(nor, nor->program_opcode, to);
aspeed_smc_write_to_ahb(chip->ahb_base, write_buf, len);
aspeed_smc_stop_user(nor);
return len;
}
static int aspeed_smc_unregister(struct aspeed_smc_controller *controller)
{
struct aspeed_smc_chip *chip;
int n;
for (n = 0; n < controller->info->nce; n++) {
chip = controller->chips[n];
if (chip)
mtd_device_unregister(&chip->nor.mtd);
}
return 0;
}
static int aspeed_smc_remove(struct platform_device *dev)
{
return aspeed_smc_unregister(platform_get_drvdata(dev));
}
static void __iomem *aspeed_smc_chip_base(struct aspeed_smc_chip *chip,
struct resource *res)
{
struct aspeed_smc_controller *controller = chip->controller;
u32 offset = 0;
u32 reg;
if (controller->info->nce > 1) {
reg = readl(SEGMENT_ADDR_REG(controller, chip->cs));
if (SEGMENT_ADDR_START(reg) >= SEGMENT_ADDR_END(reg))
return NULL;
offset = SEGMENT_ADDR_START(reg) - res->start;
}
return controller->ahb_base + offset;
}
static u32 aspeed_smc_ahb_base_phy(struct aspeed_smc_controller *controller)
{
u32 seg0_val = readl(SEGMENT_ADDR_REG(controller, 0));
return SEGMENT_ADDR_START(seg0_val);
}
static u32 chip_set_segment(struct aspeed_smc_chip *chip, u32 cs, u32 start,
u32 size)
{
struct aspeed_smc_controller *controller = chip->controller;
void __iomem *seg_reg;
u32 seg_oldval, seg_newval, ahb_base_phy, end;
ahb_base_phy = aspeed_smc_ahb_base_phy(controller);
seg_reg = SEGMENT_ADDR_REG(controller, cs);
seg_oldval = readl(seg_reg);
if (!size)
size = SEGMENT_ADDR_END(seg_oldval) - start;
if (start + size > ahb_base_phy + controller->ahb_window_size) {
size = ahb_base_phy + controller->ahb_window_size - start;
dev_warn(chip->nor.dev, "CE%d window resized to %dMB",
cs, size >> 20);
}
end = start + size;
seg_newval = SEGMENT_ADDR_VALUE(start, end);
writel(seg_newval, seg_reg);
if (seg_newval != readl(seg_reg)) {
dev_err(chip->nor.dev, "CE%d window invalid", cs);
writel(seg_oldval, seg_reg);
start = SEGMENT_ADDR_START(seg_oldval);
end = SEGMENT_ADDR_END(seg_oldval);
size = end - start;
}
dev_info(chip->nor.dev, "CE%d window [ 0x%.8x - 0x%.8x ] %dMB",
cs, start, end, size >> 20);
return size;
}
static u32 aspeed_smc_chip_set_segment(struct aspeed_smc_chip *chip)
{
struct aspeed_smc_controller *controller = chip->controller;
u32 ahb_base_phy, start;
u32 size = chip->nor.mtd.size;
if (size > controller->info->maxsize)
size = controller->info->maxsize;
if (controller->info == &spi_2400_info)
goto out;
if (chip->cs == 0 && controller->info == &spi_2500_info &&
size == SZ_128M) {
size = 120 << 20;
dev_info(chip->nor.dev,
"CE%d window resized to %dMB (AST2500 HW quirk)",
chip->cs, size >> 20);
}
ahb_base_phy = aspeed_smc_ahb_base_phy(controller);
if (chip->cs) {
u32 prev = readl(SEGMENT_ADDR_REG(controller, chip->cs - 1));
start = SEGMENT_ADDR_END(prev);
} else {
start = ahb_base_phy;
}
size = chip_set_segment(chip, chip->cs, start, size);
chip->ahb_base = controller->ahb_base + (start - ahb_base_phy);
if (chip->cs < controller->info->nce - 1)
chip_set_segment(chip, chip->cs + 1, start + size, 0);
out:
if (size < chip->nor.mtd.size)
dev_warn(chip->nor.dev,
"CE%d window too small for chip %dMB",
chip->cs, (u32)chip->nor.mtd.size >> 20);
return size;
}
static void aspeed_smc_chip_enable_write(struct aspeed_smc_chip *chip)
{
struct aspeed_smc_controller *controller = chip->controller;
u32 reg;
reg = readl(controller->regs + CONFIG_REG);
reg |= aspeed_smc_chip_write_bit(chip);
writel(reg, controller->regs + CONFIG_REG);
}
static void aspeed_smc_chip_set_type(struct aspeed_smc_chip *chip, int type)
{
struct aspeed_smc_controller *controller = chip->controller;
u32 reg;
chip->type = type;
reg = readl(controller->regs + CONFIG_REG);
reg &= ~(3 << (chip->cs * 2));
reg |= chip->type << (chip->cs * 2);
writel(reg, controller->regs + CONFIG_REG);
}
static void aspeed_smc_chip_set_4b(struct aspeed_smc_chip *chip)
{
struct aspeed_smc_controller *controller = chip->controller;
u32 reg;
reg = readl(controller->regs + CE_CONTROL_REG);
reg |= 1 << chip->cs;
writel(reg, controller->regs + CE_CONTROL_REG);
}
static void aspeed_smc_chip_set_4b_spi_2400(struct aspeed_smc_chip *chip)
{
chip->ctl_val[smc_base] |= CONTROL_IO_ADDRESS_4B;
chip->ctl_val[smc_read] |= CONTROL_IO_ADDRESS_4B;
}
static int aspeed_smc_chip_setup_init(struct aspeed_smc_chip *chip,
struct resource *res)
{
struct aspeed_smc_controller *controller = chip->controller;
const struct aspeed_smc_info *info = controller->info;
u32 reg, base_reg;
aspeed_smc_chip_enable_write(chip);
if (info->hastype)
aspeed_smc_chip_set_type(chip, smc_type_spi);
chip->ahb_base = aspeed_smc_chip_base(chip, res);
if (!chip->ahb_base) {
dev_warn(chip->nor.dev, "CE%d window closed", chip->cs);
return -EINVAL;
}
reg = readl(chip->ctl);
dev_dbg(controller->dev, "control register: %08x\n", reg);
base_reg = reg & CONTROL_KEEP_MASK;
if (base_reg != reg) {
dev_dbg(controller->dev,
"control register changed to: %08x\n",
base_reg);
}
chip->ctl_val[smc_base] = base_reg;
if ((reg & CONTROL_COMMAND_MODE_MASK) ==
CONTROL_COMMAND_MODE_NORMAL)
chip->ctl_val[smc_read] = reg;
else
chip->ctl_val[smc_read] = chip->ctl_val[smc_base] |
CONTROL_COMMAND_MODE_NORMAL;
dev_dbg(controller->dev, "default control register: %08x\n",
chip->ctl_val[smc_read]);
return 0;
}
static int aspeed_smc_chip_setup_finish(struct aspeed_smc_chip *chip)
{
struct aspeed_smc_controller *controller = chip->controller;
const struct aspeed_smc_info *info = controller->info;
u32 cmd;
if (chip->nor.addr_width == 4 && info->set_4b)
info->set_4b(chip);
chip->ahb_window_size = aspeed_smc_chip_set_segment(chip);
chip->ctl_val[smc_write] = chip->ctl_val[smc_base] |
chip->nor.program_opcode << CONTROL_COMMAND_SHIFT |
CONTROL_COMMAND_MODE_WRITE;
dev_dbg(controller->dev, "write control register: %08x\n",
chip->ctl_val[smc_write]);
if (chip->nor.read_proto == SNOR_PROTO_1_1_1) {
if (chip->nor.read_dummy == 0)
cmd = CONTROL_COMMAND_MODE_NORMAL;
else
cmd = CONTROL_COMMAND_MODE_FREAD;
} else {
dev_err(chip->nor.dev, "unsupported SPI read mode\n");
return -EINVAL;
}
chip->ctl_val[smc_read] |= cmd |
CONTROL_IO_DUMMY_SET(chip->nor.read_dummy / 8);
dev_dbg(controller->dev, "base control register: %08x\n",
chip->ctl_val[smc_read]);
return 0;
}
static int aspeed_smc_setup_flash(struct aspeed_smc_controller *controller,
struct device_node *np, struct resource *r)
{
const struct spi_nor_hwcaps hwcaps = {
.mask = SNOR_HWCAPS_READ |
SNOR_HWCAPS_READ_FAST |
SNOR_HWCAPS_PP,
};
const struct aspeed_smc_info *info = controller->info;
struct device *dev = controller->dev;
struct device_node *child;
unsigned int cs;
int ret = -ENODEV;
for_each_available_child_of_node(np, child) {
struct aspeed_smc_chip *chip;
struct spi_nor *nor;
struct mtd_info *mtd;
if (!of_device_is_compatible(child, "jedec,spi-nor"))
continue;
ret = of_property_read_u32(child, "reg", &cs);
if (ret) {
dev_err(dev, "Couldn't not read chip select.\n");
break;
}
if (cs >= info->nce) {
dev_err(dev, "Chip select %d out of range.\n",
cs);
ret = -ERANGE;
break;
}
if (controller->chips[cs]) {
dev_err(dev, "Chip select %d already in use by %s\n",
cs, dev_name(controller->chips[cs]->nor.dev));
ret = -EBUSY;
break;
}
chip = devm_kzalloc(controller->dev, sizeof(*chip), GFP_KERNEL);
if (!chip) {
ret = -ENOMEM;
break;
}
chip->controller = controller;
chip->ctl = controller->regs + info->ctl0 + cs * 4;
chip->cs = cs;
nor = &chip->nor;
mtd = &nor->mtd;
nor->dev = dev;
nor->priv = chip;
spi_nor_set_flash_node(nor, child);
nor->read = aspeed_smc_read_user;
nor->write = aspeed_smc_write_user;
nor->read_reg = aspeed_smc_read_reg;
nor->write_reg = aspeed_smc_write_reg;
nor->prepare = aspeed_smc_prep;
nor->unprepare = aspeed_smc_unprep;
ret = aspeed_smc_chip_setup_init(chip, r);
if (ret)
break;
ret = spi_nor_scan(nor, NULL, &hwcaps);
if (ret)
break;
ret = aspeed_smc_chip_setup_finish(chip);
if (ret)
break;
ret = mtd_device_register(mtd, NULL, 0);
if (ret)
break;
controller->chips[cs] = chip;
}
if (ret)
aspeed_smc_unregister(controller);
return ret;
}
static int aspeed_smc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct aspeed_smc_controller *controller;
const struct of_device_id *match;
const struct aspeed_smc_info *info;
struct resource *res;
int ret;
match = of_match_device(aspeed_smc_matches, &pdev->dev);
if (!match || !match->data)
return -ENODEV;
info = match->data;
controller = devm_kzalloc(&pdev->dev, sizeof(*controller) +
info->nce * sizeof(controller->chips[0]), GFP_KERNEL);
if (!controller)
return -ENOMEM;
controller->info = info;
controller->dev = dev;
mutex_init(&controller->mutex);
platform_set_drvdata(pdev, controller);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
controller->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(controller->regs))
return PTR_ERR(controller->regs);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
controller->ahb_base = devm_ioremap_resource(dev, res);
if (IS_ERR(controller->ahb_base))
return PTR_ERR(controller->ahb_base);
controller->ahb_window_size = resource_size(res);
ret = aspeed_smc_setup_flash(controller, np, res);
if (ret)
dev_err(dev, "Aspeed SMC probe failed %d\n", ret);
return ret;
}
