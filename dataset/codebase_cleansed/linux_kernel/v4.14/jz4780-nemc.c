unsigned int jz4780_nemc_num_banks(struct device *dev)
{
const __be32 *prop;
unsigned int bank, count = 0;
unsigned long referenced = 0;
int i = 0;
while ((prop = of_get_address(dev->of_node, i++, NULL, NULL))) {
bank = of_read_number(prop, 1);
if (!(referenced & BIT(bank))) {
referenced |= BIT(bank);
count++;
}
}
return count;
}
void jz4780_nemc_set_type(struct device *dev, unsigned int bank,
enum jz4780_nemc_bank_type type)
{
struct jz4780_nemc *nemc = dev_get_drvdata(dev->parent);
uint32_t nfcsr;
nfcsr = readl(nemc->base + NEMC_NFCSR);
switch (type) {
case JZ4780_NEMC_BANK_SRAM:
nfcsr &= ~(NEMC_NFCSR_TNFEn(bank) | NEMC_NFCSR_NFEn(bank));
break;
case JZ4780_NEMC_BANK_NAND:
nfcsr &= ~NEMC_NFCSR_TNFEn(bank);
nfcsr |= NEMC_NFCSR_NFEn(bank);
break;
}
writel(nfcsr, nemc->base + NEMC_NFCSR);
}
void jz4780_nemc_assert(struct device *dev, unsigned int bank, bool assert)
{
struct jz4780_nemc *nemc = dev_get_drvdata(dev->parent);
uint32_t nfcsr;
nfcsr = readl(nemc->base + NEMC_NFCSR);
if (assert)
nfcsr |= NEMC_NFCSR_NFCEn(bank);
else
nfcsr &= ~NEMC_NFCSR_NFCEn(bank);
writel(nfcsr, nemc->base + NEMC_NFCSR);
}
static uint32_t jz4780_nemc_clk_period(struct jz4780_nemc *nemc)
{
unsigned long rate;
rate = clk_get_rate(nemc->clk);
if (!rate)
return 0;
return div64_ul(1000000000000ull, rate);
}
static uint32_t jz4780_nemc_ns_to_cycles(struct jz4780_nemc *nemc, uint32_t ns)
{
return ((ns * 1000) + nemc->clk_period - 1) / nemc->clk_period;
}
static bool jz4780_nemc_configure_bank(struct jz4780_nemc *nemc,
unsigned int bank,
struct device_node *node)
{
uint32_t smcr, val, cycles;
static const uint32_t convert_tBP_tAW[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
11, 11,
12, 12, 12,
13, 13, 13, 13, 13,
14, 14, 14, 14, 14,
15, 15, 15, 15, 15, 15
};
smcr = readl(nemc->base + NEMC_SMCRn(bank));
smcr &= ~NEMC_SMCR_SMT;
if (!of_property_read_u32(node, "ingenic,nemc-bus-width", &val)) {
smcr &= ~NEMC_SMCR_BW_MASK;
switch (val) {
case 8:
smcr |= NEMC_SMCR_BW_8;
break;
default:
dev_err(nemc->dev, "unsupported bus width: %u\n", val);
return false;
}
}
if (of_property_read_u32(node, "ingenic,nemc-tAS", &val) == 0) {
smcr &= ~NEMC_SMCR_TAS_MASK;
cycles = jz4780_nemc_ns_to_cycles(nemc, val);
if (cycles > 15) {
dev_err(nemc->dev, "tAS %u is too high (%u cycles)\n",
val, cycles);
return false;
}
smcr |= cycles << NEMC_SMCR_TAS_SHIFT;
}
if (of_property_read_u32(node, "ingenic,nemc-tAH", &val) == 0) {
smcr &= ~NEMC_SMCR_TAH_MASK;
cycles = jz4780_nemc_ns_to_cycles(nemc, val);
if (cycles > 15) {
dev_err(nemc->dev, "tAH %u is too high (%u cycles)\n",
val, cycles);
return false;
}
smcr |= cycles << NEMC_SMCR_TAH_SHIFT;
}
if (of_property_read_u32(node, "ingenic,nemc-tBP", &val) == 0) {
smcr &= ~NEMC_SMCR_TBP_MASK;
cycles = jz4780_nemc_ns_to_cycles(nemc, val);
if (cycles > 31) {
dev_err(nemc->dev, "tBP %u is too high (%u cycles)\n",
val, cycles);
return false;
}
smcr |= convert_tBP_tAW[cycles] << NEMC_SMCR_TBP_SHIFT;
}
if (of_property_read_u32(node, "ingenic,nemc-tAW", &val) == 0) {
smcr &= ~NEMC_SMCR_TAW_MASK;
cycles = jz4780_nemc_ns_to_cycles(nemc, val);
if (cycles > 31) {
dev_err(nemc->dev, "tAW %u is too high (%u cycles)\n",
val, cycles);
return false;
}
smcr |= convert_tBP_tAW[cycles] << NEMC_SMCR_TAW_SHIFT;
}
if (of_property_read_u32(node, "ingenic,nemc-tSTRV", &val) == 0) {
smcr &= ~NEMC_SMCR_TSTRV_MASK;
cycles = jz4780_nemc_ns_to_cycles(nemc, val);
if (cycles > 63) {
dev_err(nemc->dev, "tSTRV %u is too high (%u cycles)\n",
val, cycles);
return false;
}
smcr |= cycles << NEMC_SMCR_TSTRV_SHIFT;
}
writel(smcr, nemc->base + NEMC_SMCRn(bank));
return true;
}
static int jz4780_nemc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct jz4780_nemc *nemc;
struct resource *res;
struct device_node *child;
const __be32 *prop;
unsigned int bank;
unsigned long referenced;
int i, ret;
nemc = devm_kzalloc(dev, sizeof(*nemc), GFP_KERNEL);
if (!nemc)
return -ENOMEM;
spin_lock_init(&nemc->lock);
nemc->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
nemc->base = devm_ioremap_resource(dev, res);
if (IS_ERR(nemc->base)) {
dev_err(dev, "failed to get I/O memory\n");
return PTR_ERR(nemc->base);
}
writel(0, nemc->base + NEMC_NFCSR);
nemc->clk = devm_clk_get(dev, NULL);
if (IS_ERR(nemc->clk)) {
dev_err(dev, "failed to get clock\n");
return PTR_ERR(nemc->clk);
}
ret = clk_prepare_enable(nemc->clk);
if (ret) {
dev_err(dev, "failed to enable clock: %d\n", ret);
return ret;
}
nemc->clk_period = jz4780_nemc_clk_period(nemc);
if (!nemc->clk_period) {
dev_err(dev, "failed to calculate clock period\n");
clk_disable_unprepare(nemc->clk);
return -EINVAL;
}
for_each_child_of_node(nemc->dev->of_node, child) {
referenced = 0;
i = 0;
while ((prop = of_get_address(child, i++, NULL, NULL))) {
bank = of_read_number(prop, 1);
if (bank < 1 || bank >= JZ4780_NEMC_NUM_BANKS) {
dev_err(nemc->dev,
"%pOF requests invalid bank %u\n",
child, bank);
referenced = 0;
break;
}
referenced |= BIT(bank);
}
if (!referenced) {
dev_err(nemc->dev, "%pOF has no addresses\n",
child);
continue;
} else if (nemc->banks_present & referenced) {
dev_err(nemc->dev, "%pOF conflicts with another node\n",
child);
continue;
}
for_each_set_bit(bank, &referenced, JZ4780_NEMC_NUM_BANKS) {
if (!jz4780_nemc_configure_bank(nemc, bank, child)) {
referenced = 0;
break;
}
}
if (referenced) {
if (of_platform_device_create(child, NULL, nemc->dev))
nemc->banks_present |= referenced;
}
}
platform_set_drvdata(pdev, nemc);
dev_info(dev, "JZ4780 NEMC initialised\n");
return 0;
}
static int jz4780_nemc_remove(struct platform_device *pdev)
{
struct jz4780_nemc *nemc = platform_get_drvdata(pdev);
clk_disable_unprepare(nemc->clk);
return 0;
}
static int __init jz4780_nemc_init(void)
{
return platform_driver_register(&jz4780_nemc_driver);
}
