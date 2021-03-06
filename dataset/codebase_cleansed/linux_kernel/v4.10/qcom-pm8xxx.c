static int pm8xxx_read_block_irq(struct pm_irq_chip *chip, unsigned int bp,
unsigned int *ip)
{
int rc;
spin_lock(&chip->pm_irq_lock);
rc = regmap_write(chip->regmap, SSBI_REG_ADDR_IRQ_BLK_SEL, bp);
if (rc) {
pr_err("Failed Selecting Block %d rc=%d\n", bp, rc);
goto bail;
}
rc = regmap_read(chip->regmap, SSBI_REG_ADDR_IRQ_IT_STATUS, ip);
if (rc)
pr_err("Failed Reading Status rc=%d\n", rc);
bail:
spin_unlock(&chip->pm_irq_lock);
return rc;
}
static int
pm8xxx_config_irq(struct pm_irq_chip *chip, unsigned int bp, unsigned int cp)
{
int rc;
spin_lock(&chip->pm_irq_lock);
rc = regmap_write(chip->regmap, SSBI_REG_ADDR_IRQ_BLK_SEL, bp);
if (rc) {
pr_err("Failed Selecting Block %d rc=%d\n", bp, rc);
goto bail;
}
cp |= PM_IRQF_WRITE;
rc = regmap_write(chip->regmap, SSBI_REG_ADDR_IRQ_CONFIG, cp);
if (rc)
pr_err("Failed Configuring IRQ rc=%d\n", rc);
bail:
spin_unlock(&chip->pm_irq_lock);
return rc;
}
static int pm8xxx_irq_block_handler(struct pm_irq_chip *chip, int block)
{
int pmirq, irq, i, ret = 0;
unsigned int bits;
ret = pm8xxx_read_block_irq(chip, block, &bits);
if (ret) {
pr_err("Failed reading %d block ret=%d", block, ret);
return ret;
}
if (!bits) {
pr_err("block bit set in master but no irqs: %d", block);
return 0;
}
for (i = 0; i < 8; i++) {
if (bits & (1 << i)) {
pmirq = block * 8 + i;
irq = irq_find_mapping(chip->irqdomain, pmirq);
generic_handle_irq(irq);
}
}
return 0;
}
static int pm8xxx_irq_master_handler(struct pm_irq_chip *chip, int master)
{
unsigned int blockbits;
int block_number, i, ret = 0;
ret = regmap_read(chip->regmap, SSBI_REG_ADDR_IRQ_M_STATUS1 + master,
&blockbits);
if (ret) {
pr_err("Failed to read master %d ret=%d\n", master, ret);
return ret;
}
if (!blockbits) {
pr_err("master bit set in root but no blocks: %d", master);
return 0;
}
for (i = 0; i < 8; i++)
if (blockbits & (1 << i)) {
block_number = master * 8 + i;
ret |= pm8xxx_irq_block_handler(chip, block_number);
}
return ret;
}
static void pm8xxx_irq_handler(struct irq_desc *desc)
{
struct pm_irq_chip *chip = irq_desc_get_handler_data(desc);
struct irq_chip *irq_chip = irq_desc_get_chip(desc);
unsigned int root;
int i, ret, masters = 0;
chained_irq_enter(irq_chip, desc);
ret = regmap_read(chip->regmap, SSBI_REG_ADDR_IRQ_ROOT, &root);
if (ret) {
pr_err("Can't read root status ret=%d\n", ret);
return;
}
masters = root >> 1;
for (i = 0; i < chip->num_masters; i++)
if (masters & (1 << i))
pm8xxx_irq_master_handler(chip, i);
chained_irq_exit(irq_chip, desc);
}
static void pm8821_irq_block_handler(struct pm_irq_chip *chip,
int master, int block)
{
int pmirq, irq, i, ret;
unsigned int bits;
ret = regmap_read(chip->regmap,
PM8821_SSBI_ADDR_IRQ_ROOT(master, block), &bits);
if (ret) {
pr_err("Reading block %d failed ret=%d", block, ret);
return;
}
block += (master * PM8821_BLOCKS_PER_MASTER) - 1;
for (i = 0; i < 8; i++) {
if (bits & BIT(i)) {
pmirq = block * 8 + i;
irq = irq_find_mapping(chip->irqdomain, pmirq);
generic_handle_irq(irq);
}
}
}
static inline void pm8821_irq_master_handler(struct pm_irq_chip *chip,
int master, u8 master_val)
{
int block;
for (block = 1; block < 8; block++)
if (master_val & BIT(block))
pm8821_irq_block_handler(chip, master, block);
}
static void pm8821_irq_handler(struct irq_desc *desc)
{
struct pm_irq_chip *chip = irq_desc_get_handler_data(desc);
struct irq_chip *irq_chip = irq_desc_get_chip(desc);
unsigned int master;
int ret;
chained_irq_enter(irq_chip, desc);
ret = regmap_read(chip->regmap,
PM8821_SSBI_REG_ADDR_IRQ_MASTER0, &master);
if (ret) {
pr_err("Failed to read master 0 ret=%d\n", ret);
goto done;
}
if (master & GENMASK(7, 1))
pm8821_irq_master_handler(chip, 0, master);
if (!(master & BIT(0)))
goto done;
ret = regmap_read(chip->regmap,
PM8821_SSBI_REG_ADDR_IRQ_MASTER1, &master);
if (ret) {
pr_err("Failed to read master 1 ret=%d\n", ret);
goto done;
}
pm8821_irq_master_handler(chip, 1, master);
done:
chained_irq_exit(irq_chip, desc);
}
static void pm8xxx_irq_mask_ack(struct irq_data *d)
{
struct pm_irq_chip *chip = irq_data_get_irq_chip_data(d);
unsigned int pmirq = irqd_to_hwirq(d);
u8 block, config;
block = pmirq / 8;
config = chip->config[pmirq] | PM_IRQF_MASK_ALL | PM_IRQF_CLR;
pm8xxx_config_irq(chip, block, config);
}
static void pm8xxx_irq_unmask(struct irq_data *d)
{
struct pm_irq_chip *chip = irq_data_get_irq_chip_data(d);
unsigned int pmirq = irqd_to_hwirq(d);
u8 block, config;
block = pmirq / 8;
config = chip->config[pmirq];
pm8xxx_config_irq(chip, block, config);
}
static int pm8xxx_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct pm_irq_chip *chip = irq_data_get_irq_chip_data(d);
unsigned int pmirq = irqd_to_hwirq(d);
int irq_bit;
u8 block, config;
block = pmirq / 8;
irq_bit = pmirq % 8;
chip->config[pmirq] = (irq_bit << PM_IRQF_BITS_SHIFT)
| PM_IRQF_MASK_ALL;
if (flow_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING)) {
if (flow_type & IRQF_TRIGGER_RISING)
chip->config[pmirq] &= ~PM_IRQF_MASK_RE;
if (flow_type & IRQF_TRIGGER_FALLING)
chip->config[pmirq] &= ~PM_IRQF_MASK_FE;
} else {
chip->config[pmirq] |= PM_IRQF_LVL_SEL;
if (flow_type & IRQF_TRIGGER_HIGH)
chip->config[pmirq] &= ~PM_IRQF_MASK_RE;
else
chip->config[pmirq] &= ~PM_IRQF_MASK_FE;
}
config = chip->config[pmirq] | PM_IRQF_CLR;
return pm8xxx_config_irq(chip, block, config);
}
static int pm8xxx_irq_get_irqchip_state(struct irq_data *d,
enum irqchip_irq_state which,
bool *state)
{
struct pm_irq_chip *chip = irq_data_get_irq_chip_data(d);
unsigned int pmirq = irqd_to_hwirq(d);
unsigned int bits;
int irq_bit;
u8 block;
int rc;
if (which != IRQCHIP_STATE_LINE_LEVEL)
return -EINVAL;
block = pmirq / 8;
irq_bit = pmirq % 8;
spin_lock(&chip->pm_irq_lock);
rc = regmap_write(chip->regmap, SSBI_REG_ADDR_IRQ_BLK_SEL, block);
if (rc) {
pr_err("Failed Selecting Block %d rc=%d\n", block, rc);
goto bail;
}
rc = regmap_read(chip->regmap, SSBI_REG_ADDR_IRQ_RT_STATUS, &bits);
if (rc) {
pr_err("Failed Reading Status rc=%d\n", rc);
goto bail;
}
*state = !!(bits & BIT(irq_bit));
bail:
spin_unlock(&chip->pm_irq_lock);
return rc;
}
static int pm8xxx_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct pm_irq_chip *chip = d->host_data;
irq_set_chip_and_handler(irq, &pm8xxx_irq_chip, handle_level_irq);
irq_set_chip_data(irq, chip);
irq_set_noprobe(irq);
return 0;
}
static void pm8821_irq_mask_ack(struct irq_data *d)
{
struct pm_irq_chip *chip = irq_data_get_irq_chip_data(d);
unsigned int pmirq = irqd_to_hwirq(d);
u8 block, master;
int irq_bit, rc;
block = pmirq / 8;
master = block / PM8821_BLOCKS_PER_MASTER;
irq_bit = pmirq % 8;
block %= PM8821_BLOCKS_PER_MASTER;
rc = regmap_update_bits(chip->regmap,
PM8821_SSBI_ADDR_IRQ_MASK(master, block),
BIT(irq_bit), BIT(irq_bit));
if (rc) {
pr_err("Failed to mask IRQ:%d rc=%d\n", pmirq, rc);
return;
}
rc = regmap_update_bits(chip->regmap,
PM8821_SSBI_ADDR_IRQ_CLEAR(master, block),
BIT(irq_bit), BIT(irq_bit));
if (rc)
pr_err("Failed to CLEAR IRQ:%d rc=%d\n", pmirq, rc);
}
static void pm8821_irq_unmask(struct irq_data *d)
{
struct pm_irq_chip *chip = irq_data_get_irq_chip_data(d);
unsigned int pmirq = irqd_to_hwirq(d);
int irq_bit, rc;
u8 block, master;
block = pmirq / 8;
master = block / PM8821_BLOCKS_PER_MASTER;
irq_bit = pmirq % 8;
block %= PM8821_BLOCKS_PER_MASTER;
rc = regmap_update_bits(chip->regmap,
PM8821_SSBI_ADDR_IRQ_MASK(master, block),
BIT(irq_bit), ~BIT(irq_bit));
if (rc)
pr_err("Failed to read/write unmask IRQ:%d rc=%d\n", pmirq, rc);
}
static int pm8821_irq_get_irqchip_state(struct irq_data *d,
enum irqchip_irq_state which,
bool *state)
{
struct pm_irq_chip *chip = irq_data_get_irq_chip_data(d);
int rc, pmirq = irqd_to_hwirq(d);
u8 block, irq_bit, master;
unsigned int bits;
block = pmirq / 8;
master = block / PM8821_BLOCKS_PER_MASTER;
irq_bit = pmirq % 8;
block %= PM8821_BLOCKS_PER_MASTER;
rc = regmap_read(chip->regmap,
PM8821_SSBI_ADDR_IRQ_RT_STATUS(master, block), &bits);
if (rc) {
pr_err("Reading Status of IRQ %d failed rc=%d\n", pmirq, rc);
return rc;
}
*state = !!(bits & BIT(irq_bit));
return rc;
}
static int pm8821_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct pm_irq_chip *chip = d->host_data;
irq_set_chip_and_handler(irq, &pm8821_irq_chip, handle_level_irq);
irq_set_chip_data(irq, chip);
irq_set_noprobe(irq);
return 0;
}
static int pm8xxx_probe(struct platform_device *pdev)
{
const struct pm_irq_data *data;
struct regmap *regmap;
int irq, rc;
unsigned int val;
u32 rev;
struct pm_irq_chip *chip;
data = of_device_get_match_data(&pdev->dev);
if (!data) {
dev_err(&pdev->dev, "No matching driver data found\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
regmap = devm_regmap_init(&pdev->dev, NULL, pdev->dev.parent,
&ssbi_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
rc = regmap_read(regmap, REG_HWREV, &val);
if (rc) {
pr_err("Failed to read hw rev reg %d:rc=%d\n", REG_HWREV, rc);
return rc;
}
pr_info("PMIC revision 1: %02X\n", val);
rev = val;
rc = regmap_read(regmap, REG_HWREV_2, &val);
if (rc) {
pr_err("Failed to read hw rev 2 reg %d:rc=%d\n",
REG_HWREV_2, rc);
return rc;
}
pr_info("PMIC revision 2: %02X\n", val);
rev |= val << BITS_PER_BYTE;
chip = devm_kzalloc(&pdev->dev, sizeof(*chip) +
sizeof(chip->config[0]) * data->num_irqs,
GFP_KERNEL);
if (!chip)
return -ENOMEM;
platform_set_drvdata(pdev, chip);
chip->regmap = regmap;
chip->num_irqs = data->num_irqs;
chip->num_blocks = DIV_ROUND_UP(chip->num_irqs, 8);
chip->num_masters = DIV_ROUND_UP(chip->num_blocks, 8);
spin_lock_init(&chip->pm_irq_lock);
chip->irqdomain = irq_domain_add_linear(pdev->dev.of_node,
data->num_irqs,
data->irq_domain_ops,
chip);
if (!chip->irqdomain)
return -ENODEV;
irq_set_chained_handler_and_data(irq, data->irq_handler, chip);
irq_set_irq_wake(irq, 1);
rc = of_platform_populate(pdev->dev.of_node, NULL, NULL, &pdev->dev);
if (rc) {
irq_set_chained_handler_and_data(irq, NULL, NULL);
irq_domain_remove(chip->irqdomain);
}
return rc;
}
static int pm8xxx_remove_child(struct device *dev, void *unused)
{
platform_device_unregister(to_platform_device(dev));
return 0;
}
static int pm8xxx_remove(struct platform_device *pdev)
{
int irq = platform_get_irq(pdev, 0);
struct pm_irq_chip *chip = platform_get_drvdata(pdev);
device_for_each_child(&pdev->dev, NULL, pm8xxx_remove_child);
irq_set_chained_handler_and_data(irq, NULL, NULL);
irq_domain_remove(chip->irqdomain);
return 0;
}
static int __init pm8xxx_init(void)
{
return platform_driver_register(&pm8xxx_driver);
}
static void __exit pm8xxx_exit(void)
{
platform_driver_unregister(&pm8xxx_driver);
}
