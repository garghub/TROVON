static inline u32 is_plgpio_set(void __iomem *base, u32 pin, u32 reg)
{
u32 offset = PIN_OFFSET(pin);
void __iomem *reg_off = REG_OFFSET(base, reg, pin);
u32 val = readl_relaxed(reg_off);
return !!(val & (1 << offset));
}
static inline void plgpio_reg_set(void __iomem *base, u32 pin, u32 reg)
{
u32 offset = PIN_OFFSET(pin);
void __iomem *reg_off = REG_OFFSET(base, reg, pin);
u32 val = readl_relaxed(reg_off);
writel_relaxed(val | (1 << offset), reg_off);
}
static inline void plgpio_reg_reset(void __iomem *base, u32 pin, u32 reg)
{
u32 offset = PIN_OFFSET(pin);
void __iomem *reg_off = REG_OFFSET(base, reg, pin);
u32 val = readl_relaxed(reg_off);
writel_relaxed(val & ~(1 << offset), reg_off);
}
static int plgpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct plgpio *plgpio = container_of(chip, struct plgpio, chip);
unsigned long flags;
if (plgpio->p2o && (plgpio->p2o_regs & PTO_DIR_REG)) {
offset = plgpio->p2o(offset);
if (offset == -1)
return -EINVAL;
}
spin_lock_irqsave(&plgpio->lock, flags);
plgpio_reg_set(plgpio->base, offset, plgpio->regs.dir);
spin_unlock_irqrestore(&plgpio->lock, flags);
return 0;
}
static int plgpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct plgpio *plgpio = container_of(chip, struct plgpio, chip);
unsigned long flags;
unsigned dir_offset = offset, wdata_offset = offset, tmp;
if (plgpio->p2o && (plgpio->p2o_regs & (PTO_DIR_REG | PTO_WDATA_REG))) {
tmp = plgpio->p2o(offset);
if (tmp == -1)
return -EINVAL;
if (plgpio->p2o_regs & PTO_DIR_REG)
dir_offset = tmp;
if (plgpio->p2o_regs & PTO_WDATA_REG)
wdata_offset = tmp;
}
spin_lock_irqsave(&plgpio->lock, flags);
if (value)
plgpio_reg_set(plgpio->base, wdata_offset,
plgpio->regs.wdata);
else
plgpio_reg_reset(plgpio->base, wdata_offset,
plgpio->regs.wdata);
plgpio_reg_reset(plgpio->base, dir_offset, plgpio->regs.dir);
spin_unlock_irqrestore(&plgpio->lock, flags);
return 0;
}
static int plgpio_get_value(struct gpio_chip *chip, unsigned offset)
{
struct plgpio *plgpio = container_of(chip, struct plgpio, chip);
if (offset >= chip->ngpio)
return -EINVAL;
if (plgpio->p2o && (plgpio->p2o_regs & PTO_RDATA_REG)) {
offset = plgpio->p2o(offset);
if (offset == -1)
return -EINVAL;
}
return is_plgpio_set(plgpio->base, offset, plgpio->regs.rdata);
}
static void plgpio_set_value(struct gpio_chip *chip, unsigned offset, int value)
{
struct plgpio *plgpio = container_of(chip, struct plgpio, chip);
if (offset >= chip->ngpio)
return;
if (plgpio->p2o && (plgpio->p2o_regs & PTO_WDATA_REG)) {
offset = plgpio->p2o(offset);
if (offset == -1)
return;
}
if (value)
plgpio_reg_set(plgpio->base, offset, plgpio->regs.wdata);
else
plgpio_reg_reset(plgpio->base, offset, plgpio->regs.wdata);
}
static int plgpio_request(struct gpio_chip *chip, unsigned offset)
{
struct plgpio *plgpio = container_of(chip, struct plgpio, chip);
int gpio = chip->base + offset;
unsigned long flags;
int ret = 0;
if (offset >= chip->ngpio)
return -EINVAL;
ret = pinctrl_request_gpio(gpio);
if (ret)
return ret;
if (!IS_ERR(plgpio->clk)) {
ret = clk_enable(plgpio->clk);
if (ret)
goto err0;
}
if (plgpio->regs.enb == -1)
return 0;
ret = plgpio_direction_input(chip, offset);
if (ret)
goto err1;
if (plgpio->p2o && (plgpio->p2o_regs & PTO_ENB_REG)) {
offset = plgpio->p2o(offset);
if (offset == -1) {
ret = -EINVAL;
goto err1;
}
}
spin_lock_irqsave(&plgpio->lock, flags);
plgpio_reg_set(plgpio->base, offset, plgpio->regs.enb);
spin_unlock_irqrestore(&plgpio->lock, flags);
return 0;
err1:
if (!IS_ERR(plgpio->clk))
clk_disable(plgpio->clk);
err0:
pinctrl_free_gpio(gpio);
return ret;
}
static void plgpio_free(struct gpio_chip *chip, unsigned offset)
{
struct plgpio *plgpio = container_of(chip, struct plgpio, chip);
int gpio = chip->base + offset;
unsigned long flags;
if (offset >= chip->ngpio)
return;
if (plgpio->regs.enb == -1)
goto disable_clk;
if (plgpio->p2o && (plgpio->p2o_regs & PTO_ENB_REG)) {
offset = plgpio->p2o(offset);
if (offset == -1)
return;
}
spin_lock_irqsave(&plgpio->lock, flags);
plgpio_reg_reset(plgpio->base, offset, plgpio->regs.enb);
spin_unlock_irqrestore(&plgpio->lock, flags);
disable_clk:
if (!IS_ERR(plgpio->clk))
clk_disable(plgpio->clk);
pinctrl_free_gpio(gpio);
}
static void plgpio_irq_disable(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct plgpio *plgpio = container_of(gc, struct plgpio, chip);
int offset = d->hwirq;
unsigned long flags;
if (plgpio->p2o && (plgpio->p2o_regs & PTO_IE_REG)) {
offset = plgpio->p2o(offset);
if (offset == -1)
return;
}
spin_lock_irqsave(&plgpio->lock, flags);
plgpio_reg_set(plgpio->base, offset, plgpio->regs.ie);
spin_unlock_irqrestore(&plgpio->lock, flags);
}
static void plgpio_irq_enable(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct plgpio *plgpio = container_of(gc, struct plgpio, chip);
int offset = d->hwirq;
unsigned long flags;
if (plgpio->p2o && (plgpio->p2o_regs & PTO_IE_REG)) {
offset = plgpio->p2o(offset);
if (offset == -1)
return;
}
spin_lock_irqsave(&plgpio->lock, flags);
plgpio_reg_reset(plgpio->base, offset, plgpio->regs.ie);
spin_unlock_irqrestore(&plgpio->lock, flags);
}
static int plgpio_irq_set_type(struct irq_data *d, unsigned trigger)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct plgpio *plgpio = container_of(gc, struct plgpio, chip);
int offset = d->hwirq;
void __iomem *reg_off;
unsigned int supported_type = 0, val;
if (offset >= plgpio->chip.ngpio)
return -EINVAL;
if (plgpio->regs.eit == -1)
supported_type = IRQ_TYPE_LEVEL_HIGH;
else
supported_type = IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING;
if (!(trigger & supported_type))
return -EINVAL;
if (plgpio->regs.eit == -1)
return 0;
reg_off = REG_OFFSET(plgpio->base, plgpio->regs.eit, offset);
val = readl_relaxed(reg_off);
offset = PIN_OFFSET(offset);
if (trigger & IRQ_TYPE_EDGE_RISING)
writel_relaxed(val | (1 << offset), reg_off);
else
writel_relaxed(val & ~(1 << offset), reg_off);
return 0;
}
static void plgpio_irq_handler(unsigned irq, struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct plgpio *plgpio = container_of(gc, struct plgpio, chip);
struct irq_chip *irqchip = irq_desc_get_chip(desc);
int regs_count, count, pin, offset, i = 0;
unsigned long pending;
count = plgpio->chip.ngpio;
regs_count = DIV_ROUND_UP(count, MAX_GPIO_PER_REG);
chained_irq_enter(irqchip, desc);
for (; i < regs_count; i++) {
pending = readl_relaxed(plgpio->base + plgpio->regs.mis +
i * sizeof(int *));
if (!pending)
continue;
writel_relaxed(~pending, plgpio->base + plgpio->regs.mis +
i * sizeof(int *));
count = count - i * MAX_GPIO_PER_REG;
if (count < MAX_GPIO_PER_REG)
pending &= (1 << count) - 1;
for_each_set_bit(offset, &pending, MAX_GPIO_PER_REG) {
if (plgpio->o2p && (plgpio->p2o_regs & PTO_MIS_REG)) {
pin = plgpio->o2p(offset);
if (pin == -1)
continue;
} else
pin = offset;
pin = i * MAX_GPIO_PER_REG + pin;
generic_handle_irq(
irq_find_mapping(gc->irqdomain, pin));
}
}
chained_irq_exit(irqchip, desc);
}
static int spear310_p2o(int pin)
{
int offset = pin;
if (pin <= 27)
offset += 4;
else if (pin <= 33)
offset = -1;
else if (pin <= 97)
offset -= 2;
else if (pin <= 101)
offset = 101 - pin;
else
offset = -1;
return offset;
}
static int spear310_o2p(int offset)
{
if (offset <= 3)
return 101 - offset;
else if (offset <= 31)
return offset - 4;
else
return offset + 2;
}
static int plgpio_probe_dt(struct platform_device *pdev, struct plgpio *plgpio)
{
struct device_node *np = pdev->dev.of_node;
int ret = -EINVAL;
u32 val;
if (of_machine_is_compatible("st,spear310")) {
plgpio->p2o = spear310_p2o;
plgpio->o2p = spear310_o2p;
plgpio->p2o_regs = PTO_WDATA_REG | PTO_DIR_REG | PTO_IE_REG |
PTO_RDATA_REG | PTO_MIS_REG;
}
if (!of_property_read_u32(np, "st-plgpio,ngpio", &val)) {
plgpio->chip.ngpio = val;
} else {
dev_err(&pdev->dev, "DT: Invalid ngpio field\n");
goto end;
}
if (!of_property_read_u32(np, "st-plgpio,enb-reg", &val))
plgpio->regs.enb = val;
else
plgpio->regs.enb = -1;
if (!of_property_read_u32(np, "st-plgpio,wdata-reg", &val)) {
plgpio->regs.wdata = val;
} else {
dev_err(&pdev->dev, "DT: Invalid wdata reg\n");
goto end;
}
if (!of_property_read_u32(np, "st-plgpio,dir-reg", &val)) {
plgpio->regs.dir = val;
} else {
dev_err(&pdev->dev, "DT: Invalid dir reg\n");
goto end;
}
if (!of_property_read_u32(np, "st-plgpio,ie-reg", &val)) {
plgpio->regs.ie = val;
} else {
dev_err(&pdev->dev, "DT: Invalid ie reg\n");
goto end;
}
if (!of_property_read_u32(np, "st-plgpio,rdata-reg", &val)) {
plgpio->regs.rdata = val;
} else {
dev_err(&pdev->dev, "DT: Invalid rdata reg\n");
goto end;
}
if (!of_property_read_u32(np, "st-plgpio,mis-reg", &val)) {
plgpio->regs.mis = val;
} else {
dev_err(&pdev->dev, "DT: Invalid mis reg\n");
goto end;
}
if (!of_property_read_u32(np, "st-plgpio,eit-reg", &val))
plgpio->regs.eit = val;
else
plgpio->regs.eit = -1;
return 0;
end:
return ret;
}
static int plgpio_probe(struct platform_device *pdev)
{
struct plgpio *plgpio;
struct resource *res;
int ret, irq;
plgpio = devm_kzalloc(&pdev->dev, sizeof(*plgpio), GFP_KERNEL);
if (!plgpio) {
dev_err(&pdev->dev, "memory allocation fail\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
plgpio->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(plgpio->base))
return PTR_ERR(plgpio->base);
ret = plgpio_probe_dt(pdev, plgpio);
if (ret) {
dev_err(&pdev->dev, "DT probe failed\n");
return ret;
}
plgpio->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(plgpio->clk))
dev_warn(&pdev->dev, "clk_get() failed, work without it\n");
#ifdef CONFIG_PM_SLEEP
plgpio->csave_regs = devm_kzalloc(&pdev->dev,
sizeof(*plgpio->csave_regs) *
DIV_ROUND_UP(plgpio->chip.ngpio, MAX_GPIO_PER_REG),
GFP_KERNEL);
if (!plgpio->csave_regs) {
dev_err(&pdev->dev, "csave registers memory allocation fail\n");
return -ENOMEM;
}
#endif
platform_set_drvdata(pdev, plgpio);
spin_lock_init(&plgpio->lock);
plgpio->chip.base = -1;
plgpio->chip.request = plgpio_request;
plgpio->chip.free = plgpio_free;
plgpio->chip.direction_input = plgpio_direction_input;
plgpio->chip.direction_output = plgpio_direction_output;
plgpio->chip.get = plgpio_get_value;
plgpio->chip.set = plgpio_set_value;
plgpio->chip.label = dev_name(&pdev->dev);
plgpio->chip.dev = &pdev->dev;
plgpio->chip.owner = THIS_MODULE;
plgpio->chip.of_node = pdev->dev.of_node;
if (!IS_ERR(plgpio->clk)) {
ret = clk_prepare(plgpio->clk);
if (ret) {
dev_err(&pdev->dev, "clk prepare failed\n");
return ret;
}
}
ret = gpiochip_add(&plgpio->chip);
if (ret) {
dev_err(&pdev->dev, "unable to add gpio chip\n");
goto unprepare_clk;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_info(&pdev->dev, "PLGPIO registered without IRQs\n");
return 0;
}
ret = gpiochip_irqchip_add(&plgpio->chip,
&plgpio_irqchip,
0,
handle_simple_irq,
IRQ_TYPE_NONE);
if (ret) {
dev_err(&pdev->dev, "failed to add irqchip to gpiochip\n");
goto remove_gpiochip;
}
gpiochip_set_chained_irqchip(&plgpio->chip,
&plgpio_irqchip,
irq,
plgpio_irq_handler);
dev_info(&pdev->dev, "PLGPIO registered with IRQs\n");
return 0;
remove_gpiochip:
dev_info(&pdev->dev, "Remove gpiochip\n");
gpiochip_remove(&plgpio->chip);
unprepare_clk:
if (!IS_ERR(plgpio->clk))
clk_unprepare(plgpio->clk);
return ret;
}
static int plgpio_suspend(struct device *dev)
{
struct plgpio *plgpio = dev_get_drvdata(dev);
int i, reg_count = DIV_ROUND_UP(plgpio->chip.ngpio, MAX_GPIO_PER_REG);
void __iomem *off;
for (i = 0; i < reg_count; i++) {
off = plgpio->base + i * sizeof(int *);
if (plgpio->regs.enb != -1)
plgpio->csave_regs[i].enb =
readl_relaxed(plgpio->regs.enb + off);
if (plgpio->regs.eit != -1)
plgpio->csave_regs[i].eit =
readl_relaxed(plgpio->regs.eit + off);
plgpio->csave_regs[i].wdata = readl_relaxed(plgpio->regs.wdata +
off);
plgpio->csave_regs[i].dir = readl_relaxed(plgpio->regs.dir +
off);
plgpio->csave_regs[i].ie = readl_relaxed(plgpio->regs.ie + off);
}
return 0;
}
static int plgpio_resume(struct device *dev)
{
struct plgpio *plgpio = dev_get_drvdata(dev);
int i, reg_count = DIV_ROUND_UP(plgpio->chip.ngpio, MAX_GPIO_PER_REG);
void __iomem *off;
u32 mask, tmp;
for (i = 0; i < reg_count; i++) {
off = plgpio->base + i * sizeof(int *);
if (i == reg_count - 1) {
mask = (1 << (plgpio->chip.ngpio - i *
MAX_GPIO_PER_REG)) - 1;
if (plgpio->regs.enb != -1)
plgpio_prepare_reg(enb, off, mask, tmp);
if (plgpio->regs.eit != -1)
plgpio_prepare_reg(eit, off, mask, tmp);
plgpio_prepare_reg(wdata, off, mask, tmp);
plgpio_prepare_reg(dir, off, mask, tmp);
plgpio_prepare_reg(ie, off, mask, tmp);
}
writel_relaxed(plgpio->csave_regs[i].wdata, plgpio->regs.wdata +
off);
writel_relaxed(plgpio->csave_regs[i].dir, plgpio->regs.dir +
off);
if (plgpio->regs.eit != -1)
writel_relaxed(plgpio->csave_regs[i].eit,
plgpio->regs.eit + off);
writel_relaxed(plgpio->csave_regs[i].ie, plgpio->regs.ie + off);
if (plgpio->regs.enb != -1)
writel_relaxed(plgpio->csave_regs[i].enb,
plgpio->regs.enb + off);
}
return 0;
}
static int __init plgpio_init(void)
{
return platform_driver_register(&plgpio_driver);
}
