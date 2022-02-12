void asic3_write_register(struct asic3 *asic, unsigned int reg, u32 value)
{
iowrite16(value, asic->mapping +
(reg >> asic->bus_shift));
}
u32 asic3_read_register(struct asic3 *asic, unsigned int reg)
{
return ioread16(asic->mapping +
(reg >> asic->bus_shift));
}
static void asic3_set_register(struct asic3 *asic, u32 reg, u32 bits, bool set)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&asic->lock, flags);
val = asic3_read_register(asic, reg);
if (set)
val |= bits;
else
val &= ~bits;
asic3_write_register(asic, reg, val);
spin_unlock_irqrestore(&asic->lock, flags);
}
static void asic3_irq_flip_edge(struct asic3 *asic,
u32 base, int bit)
{
u16 edge;
unsigned long flags;
spin_lock_irqsave(&asic->lock, flags);
edge = asic3_read_register(asic,
base + ASIC3_GPIO_EDGE_TRIGGER);
edge ^= bit;
asic3_write_register(asic,
base + ASIC3_GPIO_EDGE_TRIGGER, edge);
spin_unlock_irqrestore(&asic->lock, flags);
}
static void asic3_irq_demux(unsigned int irq, struct irq_desc *desc)
{
struct asic3 *asic = irq_desc_get_handler_data(desc);
struct irq_data *data = irq_desc_get_irq_data(desc);
int iter, i;
unsigned long flags;
data->chip->irq_ack(data);
for (iter = 0 ; iter < MAX_ASIC_ISR_LOOPS; iter++) {
u32 status;
int bank;
spin_lock_irqsave(&asic->lock, flags);
status = asic3_read_register(asic,
ASIC3_OFFSET(INTR, P_INT_STAT));
spin_unlock_irqrestore(&asic->lock, flags);
if ((status & 0x3ff) == 0)
break;
for (bank = 0; bank < ASIC3_NUM_GPIO_BANKS; bank++) {
if (status & (1 << bank)) {
unsigned long base, istat;
base = ASIC3_GPIO_A_BASE
+ bank * ASIC3_GPIO_BASE_INCR;
spin_lock_irqsave(&asic->lock, flags);
istat = asic3_read_register(asic,
base +
ASIC3_GPIO_INT_STATUS);
asic3_write_register(asic,
base +
ASIC3_GPIO_INT_STATUS, 0);
spin_unlock_irqrestore(&asic->lock, flags);
for (i = 0; i < ASIC3_GPIOS_PER_BANK; i++) {
int bit = (1 << i);
unsigned int irqnr;
if (!(istat & bit))
continue;
irqnr = asic->irq_base +
(ASIC3_GPIOS_PER_BANK * bank)
+ i;
generic_handle_irq(irqnr);
if (asic->irq_bothedge[bank] & bit)
asic3_irq_flip_edge(asic, base,
bit);
}
}
}
for (i = ASIC3_NUM_GPIOS; i < ASIC3_NR_IRQS; i++) {
if (status & (1 << (i - ASIC3_NUM_GPIOS + 4)))
generic_handle_irq(asic->irq_base + i);
}
}
if (iter >= MAX_ASIC_ISR_LOOPS)
dev_err(asic->dev, "interrupt processing overrun\n");
}
static inline int asic3_irq_to_bank(struct asic3 *asic, int irq)
{
int n;
n = (irq - asic->irq_base) >> 4;
return (n * (ASIC3_GPIO_B_BASE - ASIC3_GPIO_A_BASE));
}
static inline int asic3_irq_to_index(struct asic3 *asic, int irq)
{
return (irq - asic->irq_base) & 0xf;
}
static void asic3_mask_gpio_irq(struct irq_data *data)
{
struct asic3 *asic = irq_data_get_irq_chip_data(data);
u32 val, bank, index;
unsigned long flags;
bank = asic3_irq_to_bank(asic, data->irq);
index = asic3_irq_to_index(asic, data->irq);
spin_lock_irqsave(&asic->lock, flags);
val = asic3_read_register(asic, bank + ASIC3_GPIO_MASK);
val |= 1 << index;
asic3_write_register(asic, bank + ASIC3_GPIO_MASK, val);
spin_unlock_irqrestore(&asic->lock, flags);
}
static void asic3_mask_irq(struct irq_data *data)
{
struct asic3 *asic = irq_data_get_irq_chip_data(data);
int regval;
unsigned long flags;
spin_lock_irqsave(&asic->lock, flags);
regval = asic3_read_register(asic,
ASIC3_INTR_BASE +
ASIC3_INTR_INT_MASK);
regval &= ~(ASIC3_INTMASK_MASK0 <<
(data->irq - (asic->irq_base + ASIC3_NUM_GPIOS)));
asic3_write_register(asic,
ASIC3_INTR_BASE +
ASIC3_INTR_INT_MASK,
regval);
spin_unlock_irqrestore(&asic->lock, flags);
}
static void asic3_unmask_gpio_irq(struct irq_data *data)
{
struct asic3 *asic = irq_data_get_irq_chip_data(data);
u32 val, bank, index;
unsigned long flags;
bank = asic3_irq_to_bank(asic, data->irq);
index = asic3_irq_to_index(asic, data->irq);
spin_lock_irqsave(&asic->lock, flags);
val = asic3_read_register(asic, bank + ASIC3_GPIO_MASK);
val &= ~(1 << index);
asic3_write_register(asic, bank + ASIC3_GPIO_MASK, val);
spin_unlock_irqrestore(&asic->lock, flags);
}
static void asic3_unmask_irq(struct irq_data *data)
{
struct asic3 *asic = irq_data_get_irq_chip_data(data);
int regval;
unsigned long flags;
spin_lock_irqsave(&asic->lock, flags);
regval = asic3_read_register(asic,
ASIC3_INTR_BASE +
ASIC3_INTR_INT_MASK);
regval |= (ASIC3_INTMASK_MASK0 <<
(data->irq - (asic->irq_base + ASIC3_NUM_GPIOS)));
asic3_write_register(asic,
ASIC3_INTR_BASE +
ASIC3_INTR_INT_MASK,
regval);
spin_unlock_irqrestore(&asic->lock, flags);
}
static int asic3_gpio_irq_type(struct irq_data *data, unsigned int type)
{
struct asic3 *asic = irq_data_get_irq_chip_data(data);
u32 bank, index;
u16 trigger, level, edge, bit;
unsigned long flags;
bank = asic3_irq_to_bank(asic, data->irq);
index = asic3_irq_to_index(asic, data->irq);
bit = 1<<index;
spin_lock_irqsave(&asic->lock, flags);
level = asic3_read_register(asic,
bank + ASIC3_GPIO_LEVEL_TRIGGER);
edge = asic3_read_register(asic,
bank + ASIC3_GPIO_EDGE_TRIGGER);
trigger = asic3_read_register(asic,
bank + ASIC3_GPIO_TRIGGER_TYPE);
asic->irq_bothedge[(data->irq - asic->irq_base) >> 4] &= ~bit;
if (type == IRQ_TYPE_EDGE_RISING) {
trigger |= bit;
edge |= bit;
} else if (type == IRQ_TYPE_EDGE_FALLING) {
trigger |= bit;
edge &= ~bit;
} else if (type == IRQ_TYPE_EDGE_BOTH) {
trigger |= bit;
if (asic3_gpio_get(&asic->gpio, data->irq - asic->irq_base))
edge &= ~bit;
else
edge |= bit;
asic->irq_bothedge[(data->irq - asic->irq_base) >> 4] |= bit;
} else if (type == IRQ_TYPE_LEVEL_LOW) {
trigger &= ~bit;
level &= ~bit;
} else if (type == IRQ_TYPE_LEVEL_HIGH) {
trigger &= ~bit;
level |= bit;
} else {
dev_notice(asic->dev, "irq type not changed\n");
}
asic3_write_register(asic, bank + ASIC3_GPIO_LEVEL_TRIGGER,
level);
asic3_write_register(asic, bank + ASIC3_GPIO_EDGE_TRIGGER,
edge);
asic3_write_register(asic, bank + ASIC3_GPIO_TRIGGER_TYPE,
trigger);
spin_unlock_irqrestore(&asic->lock, flags);
return 0;
}
static int asic3_gpio_irq_set_wake(struct irq_data *data, unsigned int on)
{
struct asic3 *asic = irq_data_get_irq_chip_data(data);
u32 bank, index;
u16 bit;
bank = asic3_irq_to_bank(asic, data->irq);
index = asic3_irq_to_index(asic, data->irq);
bit = 1<<index;
asic3_set_register(asic, bank + ASIC3_GPIO_SLEEP_MASK, bit, !on);
return 0;
}
static int __init asic3_irq_probe(struct platform_device *pdev)
{
struct asic3 *asic = platform_get_drvdata(pdev);
unsigned long clksel = 0;
unsigned int irq, irq_base;
int ret;
ret = platform_get_irq(pdev, 0);
if (ret < 0)
return ret;
asic->irq_nr = ret;
clksel |= CLOCK_SEL_CX;
asic3_write_register(asic, ASIC3_OFFSET(CLOCK, SEL),
clksel);
irq_base = asic->irq_base;
for (irq = irq_base; irq < irq_base + ASIC3_NR_IRQS; irq++) {
if (irq < asic->irq_base + ASIC3_NUM_GPIOS)
irq_set_chip(irq, &asic3_gpio_irq_chip);
else
irq_set_chip(irq, &asic3_irq_chip);
irq_set_chip_data(irq, asic);
irq_set_handler(irq, handle_level_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
asic3_write_register(asic, ASIC3_OFFSET(INTR, INT_MASK),
ASIC3_INTMASK_GINTMASK);
irq_set_chained_handler(asic->irq_nr, asic3_irq_demux);
irq_set_irq_type(asic->irq_nr, IRQ_TYPE_EDGE_RISING);
irq_set_handler_data(asic->irq_nr, asic);
return 0;
}
static void asic3_irq_remove(struct platform_device *pdev)
{
struct asic3 *asic = platform_get_drvdata(pdev);
unsigned int irq, irq_base;
irq_base = asic->irq_base;
for (irq = irq_base; irq < irq_base + ASIC3_NR_IRQS; irq++) {
set_irq_flags(irq, 0);
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
irq_set_chained_handler(asic->irq_nr, NULL);
}
static int asic3_gpio_direction(struct gpio_chip *chip,
unsigned offset, int out)
{
u32 mask = ASIC3_GPIO_TO_MASK(offset), out_reg;
unsigned int gpio_base;
unsigned long flags;
struct asic3 *asic;
asic = container_of(chip, struct asic3, gpio);
gpio_base = ASIC3_GPIO_TO_BASE(offset);
if (gpio_base > ASIC3_GPIO_D_BASE) {
dev_err(asic->dev, "Invalid base (0x%x) for gpio %d\n",
gpio_base, offset);
return -EINVAL;
}
spin_lock_irqsave(&asic->lock, flags);
out_reg = asic3_read_register(asic, gpio_base + ASIC3_GPIO_DIRECTION);
if (out)
out_reg |= mask;
else
out_reg &= ~mask;
asic3_write_register(asic, gpio_base + ASIC3_GPIO_DIRECTION, out_reg);
spin_unlock_irqrestore(&asic->lock, flags);
return 0;
}
static int asic3_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
return asic3_gpio_direction(chip, offset, 0);
}
static int asic3_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
return asic3_gpio_direction(chip, offset, 1);
}
static int asic3_gpio_get(struct gpio_chip *chip,
unsigned offset)
{
unsigned int gpio_base;
u32 mask = ASIC3_GPIO_TO_MASK(offset);
struct asic3 *asic;
asic = container_of(chip, struct asic3, gpio);
gpio_base = ASIC3_GPIO_TO_BASE(offset);
if (gpio_base > ASIC3_GPIO_D_BASE) {
dev_err(asic->dev, "Invalid base (0x%x) for gpio %d\n",
gpio_base, offset);
return -EINVAL;
}
return asic3_read_register(asic, gpio_base + ASIC3_GPIO_STATUS) & mask;
}
static void asic3_gpio_set(struct gpio_chip *chip,
unsigned offset, int value)
{
u32 mask, out_reg;
unsigned int gpio_base;
unsigned long flags;
struct asic3 *asic;
asic = container_of(chip, struct asic3, gpio);
gpio_base = ASIC3_GPIO_TO_BASE(offset);
if (gpio_base > ASIC3_GPIO_D_BASE) {
dev_err(asic->dev, "Invalid base (0x%x) for gpio %d\n",
gpio_base, offset);
return;
}
mask = ASIC3_GPIO_TO_MASK(offset);
spin_lock_irqsave(&asic->lock, flags);
out_reg = asic3_read_register(asic, gpio_base + ASIC3_GPIO_OUT);
if (value)
out_reg |= mask;
else
out_reg &= ~mask;
asic3_write_register(asic, gpio_base + ASIC3_GPIO_OUT, out_reg);
spin_unlock_irqrestore(&asic->lock, flags);
return;
}
static int asic3_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct asic3 *asic = container_of(chip, struct asic3, gpio);
return asic->irq_base + offset;
}
static __init int asic3_gpio_probe(struct platform_device *pdev,
u16 *gpio_config, int num)
{
struct asic3 *asic = platform_get_drvdata(pdev);
u16 alt_reg[ASIC3_NUM_GPIO_BANKS];
u16 out_reg[ASIC3_NUM_GPIO_BANKS];
u16 dir_reg[ASIC3_NUM_GPIO_BANKS];
int i;
memset(alt_reg, 0, ASIC3_NUM_GPIO_BANKS * sizeof(u16));
memset(out_reg, 0, ASIC3_NUM_GPIO_BANKS * sizeof(u16));
memset(dir_reg, 0, ASIC3_NUM_GPIO_BANKS * sizeof(u16));
asic3_write_register(asic, ASIC3_GPIO_OFFSET(A, MASK), 0xffff);
asic3_write_register(asic, ASIC3_GPIO_OFFSET(B, MASK), 0xffff);
asic3_write_register(asic, ASIC3_GPIO_OFFSET(C, MASK), 0xffff);
asic3_write_register(asic, ASIC3_GPIO_OFFSET(D, MASK), 0xffff);
for (i = 0; i < num; i++) {
u8 alt, pin, dir, init, bank_num, bit_num;
u16 config = gpio_config[i];
pin = ASIC3_CONFIG_GPIO_PIN(config);
alt = ASIC3_CONFIG_GPIO_ALT(config);
dir = ASIC3_CONFIG_GPIO_DIR(config);
init = ASIC3_CONFIG_GPIO_INIT(config);
bank_num = ASIC3_GPIO_TO_BANK(pin);
bit_num = ASIC3_GPIO_TO_BIT(pin);
alt_reg[bank_num] |= (alt << bit_num);
out_reg[bank_num] |= (init << bit_num);
dir_reg[bank_num] |= (dir << bit_num);
}
for (i = 0; i < ASIC3_NUM_GPIO_BANKS; i++) {
asic3_write_register(asic,
ASIC3_BANK_TO_BASE(i) +
ASIC3_GPIO_DIRECTION,
dir_reg[i]);
asic3_write_register(asic,
ASIC3_BANK_TO_BASE(i) + ASIC3_GPIO_OUT,
out_reg[i]);
asic3_write_register(asic,
ASIC3_BANK_TO_BASE(i) +
ASIC3_GPIO_ALT_FUNCTION,
alt_reg[i]);
}
return gpiochip_add(&asic->gpio);
}
static int asic3_gpio_remove(struct platform_device *pdev)
{
struct asic3 *asic = platform_get_drvdata(pdev);
return gpiochip_remove(&asic->gpio);
}
static void asic3_clk_enable(struct asic3 *asic, struct asic3_clk *clk)
{
unsigned long flags;
u32 cdex;
spin_lock_irqsave(&asic->lock, flags);
if (clk->enabled++ == 0) {
cdex = asic3_read_register(asic, ASIC3_OFFSET(CLOCK, CDEX));
cdex |= clk->cdex;
asic3_write_register(asic, ASIC3_OFFSET(CLOCK, CDEX), cdex);
}
spin_unlock_irqrestore(&asic->lock, flags);
}
static void asic3_clk_disable(struct asic3 *asic, struct asic3_clk *clk)
{
unsigned long flags;
u32 cdex;
WARN_ON(clk->enabled == 0);
spin_lock_irqsave(&asic->lock, flags);
if (--clk->enabled == 0) {
cdex = asic3_read_register(asic, ASIC3_OFFSET(CLOCK, CDEX));
cdex &= ~clk->cdex;
asic3_write_register(asic, ASIC3_OFFSET(CLOCK, CDEX), cdex);
}
spin_unlock_irqrestore(&asic->lock, flags);
}
static int ds1wm_enable(struct platform_device *pdev)
{
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_EX0]);
asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_EX1]);
asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_OWM]);
msleep(1);
asic3_set_register(asic, ASIC3_OFFSET(EXTCF, RESET),
ASIC3_EXTCF_OWM_RESET, 1);
msleep(1);
asic3_set_register(asic, ASIC3_OFFSET(EXTCF, RESET),
ASIC3_EXTCF_OWM_RESET, 0);
msleep(1);
asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
ASIC3_EXTCF_OWM_EN, 1);
msleep(1);
return 0;
}
static int ds1wm_disable(struct platform_device *pdev)
{
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
ASIC3_EXTCF_OWM_EN, 0);
asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_OWM]);
asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_EX0]);
asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_EX1]);
return 0;
}
static void asic3_mmc_pwr(struct platform_device *pdev, int state)
{
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
tmio_core_mmc_pwr(asic->tmio_cnf, 1 - asic->bus_shift, state);
}
static void asic3_mmc_clk_div(struct platform_device *pdev, int state)
{
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
tmio_core_mmc_clk_div(asic->tmio_cnf, 1 - asic->bus_shift, state);
}
static int asic3_mmc_enable(struct platform_device *pdev)
{
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
ASIC3_SDHWCTRL_LEVCD, 1);
asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
ASIC3_SDHWCTRL_LEVWP, 1);
asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
ASIC3_SDHWCTRL_SUSPEND, 0);
asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
ASIC3_SDHWCTRL_PCLR, 0);
asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_EX0]);
asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_EX1]);
msleep(1);
asic3_write_register(asic, ASIC3_OFFSET(CLOCK, SEL),
CLOCK_SEL_CX | CLOCK_SEL_SD_HCLK_SEL);
asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_SD_HOST]);
asic3_clk_enable(asic, &asic->clocks[ASIC3_CLOCK_SD_BUS]);
msleep(1);
asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
ASIC3_EXTCF_SD_MEM_ENABLE, 1);
asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
ASIC3_SDHWCTRL_SDPWR, 1);
tmio_core_mmc_enable(asic->tmio_cnf, 1 - asic->bus_shift,
ASIC3_SD_CTRL_BASE >> 1);
return 0;
}
static int asic3_mmc_disable(struct platform_device *pdev)
{
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
asic3_set_register(asic, ASIC3_OFFSET(SDHWCTRL, SDCONF),
ASIC3_SDHWCTRL_SUSPEND, 1);
asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_SD_HOST]);
asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_SD_BUS]);
asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_EX0]);
asic3_clk_disable(asic, &asic->clocks[ASIC3_CLOCK_EX1]);
return 0;
}
static int asic3_leds_enable(struct platform_device *pdev)
{
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
asic3_clk_enable(asic, &asic->clocks[clock_ledn[cell->id]]);
return 0;
}
static int asic3_leds_disable(struct platform_device *pdev)
{
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
asic3_clk_disable(asic, &asic->clocks[clock_ledn[cell->id]]);
return 0;
}
static int asic3_leds_suspend(struct platform_device *pdev)
{
const struct mfd_cell *cell = mfd_get_cell(pdev);
struct asic3 *asic = dev_get_drvdata(pdev->dev.parent);
while (asic3_gpio_get(&asic->gpio, ASIC3_GPIO(C, cell->id)) != 0)
msleep(1);
asic3_clk_disable(asic, &asic->clocks[clock_ledn[cell->id]]);
return 0;
}
static int __init asic3_mfd_probe(struct platform_device *pdev,
struct asic3_platform_data *pdata,
struct resource *mem)
{
struct asic3 *asic = platform_get_drvdata(pdev);
struct resource *mem_sdio;
int irq, ret;
mem_sdio = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!mem_sdio)
dev_dbg(asic->dev, "no SDIO MEM resource\n");
irq = platform_get_irq(pdev, 1);
if (irq < 0)
dev_dbg(asic->dev, "no SDIO IRQ resource\n");
asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
ASIC3_EXTCF_OWM_SMB, 0);
ds1wm_resources[0].start >>= asic->bus_shift;
ds1wm_resources[0].end >>= asic->bus_shift;
asic->tmio_cnf = ioremap((ASIC3_SD_CONFIG_BASE >> asic->bus_shift) +
mem_sdio->start,
ASIC3_SD_CONFIG_SIZE >> asic->bus_shift);
if (!asic->tmio_cnf) {
ret = -ENOMEM;
dev_dbg(asic->dev, "Couldn't ioremap SD_CONFIG\n");
goto out;
}
asic3_mmc_resources[0].start >>= asic->bus_shift;
asic3_mmc_resources[0].end >>= asic->bus_shift;
if (pdata->clock_rate) {
ds1wm_pdata.clock_rate = pdata->clock_rate;
ret = mfd_add_devices(&pdev->dev, pdev->id,
&asic3_cell_ds1wm, 1, mem, asic->irq_base, NULL);
if (ret < 0)
goto out;
}
if (mem_sdio && (irq >= 0)) {
ret = mfd_add_devices(&pdev->dev, pdev->id,
&asic3_cell_mmc, 1, mem_sdio, irq, NULL);
if (ret < 0)
goto out;
}
ret = 0;
if (pdata->leds) {
int i;
for (i = 0; i < ASIC3_NUM_LEDS; ++i) {
asic3_cell_leds[i].platform_data = &pdata->leds[i];
asic3_cell_leds[i].pdata_size = sizeof(pdata->leds[i]);
}
ret = mfd_add_devices(&pdev->dev, 0,
asic3_cell_leds, ASIC3_NUM_LEDS, NULL, 0, NULL);
}
out:
return ret;
}
static void asic3_mfd_remove(struct platform_device *pdev)
{
struct asic3 *asic = platform_get_drvdata(pdev);
mfd_remove_devices(&pdev->dev);
iounmap(asic->tmio_cnf);
}
static int __init asic3_probe(struct platform_device *pdev)
{
struct asic3_platform_data *pdata = pdev->dev.platform_data;
struct asic3 *asic;
struct resource *mem;
unsigned long clksel;
int ret = 0;
asic = kzalloc(sizeof(struct asic3), GFP_KERNEL);
if (asic == NULL) {
printk(KERN_ERR "kzalloc failed\n");
return -ENOMEM;
}
spin_lock_init(&asic->lock);
platform_set_drvdata(pdev, asic);
asic->dev = &pdev->dev;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
ret = -ENOMEM;
dev_err(asic->dev, "no MEM resource\n");
goto out_free;
}
asic->mapping = ioremap(mem->start, resource_size(mem));
if (!asic->mapping) {
ret = -ENOMEM;
dev_err(asic->dev, "Couldn't ioremap\n");
goto out_free;
}
asic->irq_base = pdata->irq_base;
asic->bus_shift = 2 - (resource_size(mem) >> 12);
clksel = 0;
asic3_write_register(asic, ASIC3_OFFSET(CLOCK, SEL), clksel);
ret = asic3_irq_probe(pdev);
if (ret < 0) {
dev_err(asic->dev, "Couldn't probe IRQs\n");
goto out_unmap;
}
asic->gpio.label = "asic3";
asic->gpio.base = pdata->gpio_base;
asic->gpio.ngpio = ASIC3_NUM_GPIOS;
asic->gpio.get = asic3_gpio_get;
asic->gpio.set = asic3_gpio_set;
asic->gpio.direction_input = asic3_gpio_direction_input;
asic->gpio.direction_output = asic3_gpio_direction_output;
asic->gpio.to_irq = asic3_gpio_to_irq;
ret = asic3_gpio_probe(pdev,
pdata->gpio_config,
pdata->gpio_config_num);
if (ret < 0) {
dev_err(asic->dev, "GPIO probe failed\n");
goto out_irq;
}
memcpy(asic->clocks, asic3_clk_init, sizeof(asic3_clk_init));
asic3_mfd_probe(pdev, pdata, mem);
asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
(ASIC3_EXTCF_CF0_BUF_EN|ASIC3_EXTCF_CF0_PWAIT_EN), 1);
dev_info(asic->dev, "ASIC3 Core driver\n");
return 0;
out_irq:
asic3_irq_remove(pdev);
out_unmap:
iounmap(asic->mapping);
out_free:
kfree(asic);
return ret;
}
static int __devexit asic3_remove(struct platform_device *pdev)
{
int ret;
struct asic3 *asic = platform_get_drvdata(pdev);
asic3_set_register(asic, ASIC3_OFFSET(EXTCF, SELECT),
(ASIC3_EXTCF_CF0_BUF_EN|ASIC3_EXTCF_CF0_PWAIT_EN), 0);
asic3_mfd_remove(pdev);
ret = asic3_gpio_remove(pdev);
if (ret < 0)
return ret;
asic3_irq_remove(pdev);
asic3_write_register(asic, ASIC3_OFFSET(CLOCK, SEL), 0);
iounmap(asic->mapping);
kfree(asic);
return 0;
}
static void asic3_shutdown(struct platform_device *pdev)
{
}
static int __init asic3_init(void)
{
int retval = 0;
retval = platform_driver_probe(&asic3_device_driver, asic3_probe);
return retval;
}
