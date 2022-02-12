static inline void __iomem *gpio_chip_base(struct gpio_chip *c)
{
return container_of(c, struct pxa_gpio_chip, chip)->regbase;
}
static inline struct pxa_gpio_chip *gpio_to_pxachip(unsigned gpio)
{
return &pxa_gpio_chips[gpio_to_bank(gpio)];
}
static inline int gpio_is_pxa_type(int type)
{
return (type & MMP_GPIO) == 0;
}
static inline int gpio_is_mmp_type(int type)
{
return (type & MMP_GPIO) != 0;
}
static inline int __gpio_is_inverted(int gpio)
{
if ((gpio_type == PXA26X_GPIO) && (gpio > 85))
return 1;
return 0;
}
static inline int __gpio_is_occupied(unsigned gpio)
{
struct pxa_gpio_chip *pxachip;
void __iomem *base;
unsigned long gafr = 0, gpdr = 0;
int ret, af = 0, dir = 0;
pxachip = gpio_to_pxachip(gpio);
base = gpio_chip_base(&pxachip->chip);
gpdr = readl_relaxed(base + GPDR_OFFSET);
switch (gpio_type) {
case PXA25X_GPIO:
case PXA26X_GPIO:
case PXA27X_GPIO:
gafr = readl_relaxed(base + GAFR_OFFSET);
af = (gafr >> ((gpio & 0xf) * 2)) & 0x3;
dir = gpdr & GPIO_bit(gpio);
if (__gpio_is_inverted(gpio))
ret = (af != 1) || (dir == 0);
else
ret = (af != 0) || (dir != 0);
break;
default:
ret = gpdr & GPIO_bit(gpio);
break;
}
return ret;
}
static int pxa_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
return chip->base + offset + irq_base;
}
int pxa_irq_to_gpio(int irq)
{
return irq - irq_base;
}
static int pxa_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
void __iomem *base = gpio_chip_base(chip);
uint32_t value, mask = 1 << offset;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
value = readl_relaxed(base + GPDR_OFFSET);
if (__gpio_is_inverted(chip->base + offset))
value |= mask;
else
value &= ~mask;
writel_relaxed(value, base + GPDR_OFFSET);
spin_unlock_irqrestore(&gpio_lock, flags);
return 0;
}
static int pxa_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
void __iomem *base = gpio_chip_base(chip);
uint32_t tmp, mask = 1 << offset;
unsigned long flags;
writel_relaxed(mask, base + (value ? GPSR_OFFSET : GPCR_OFFSET));
spin_lock_irqsave(&gpio_lock, flags);
tmp = readl_relaxed(base + GPDR_OFFSET);
if (__gpio_is_inverted(chip->base + offset))
tmp &= ~mask;
else
tmp |= mask;
writel_relaxed(tmp, base + GPDR_OFFSET);
spin_unlock_irqrestore(&gpio_lock, flags);
return 0;
}
static int pxa_gpio_get(struct gpio_chip *chip, unsigned offset)
{
u32 gplr = readl_relaxed(gpio_chip_base(chip) + GPLR_OFFSET);
return !!(gplr & (1 << offset));
}
static void pxa_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
writel_relaxed(1 << offset, gpio_chip_base(chip) +
(value ? GPSR_OFFSET : GPCR_OFFSET));
}
static int pxa_gpio_of_xlate(struct gpio_chip *gc,
const struct of_phandle_args *gpiospec,
u32 *flags)
{
if (gpiospec->args[0] > pxa_last_gpio)
return -EINVAL;
if (gc != &pxa_gpio_chips[gpiospec->args[0] / 32].chip)
return -EINVAL;
if (flags)
*flags = gpiospec->args[1];
return gpiospec->args[0] % 32;
}
static int pxa_init_gpio_chip(int gpio_end,
int (*set_wake)(unsigned int, unsigned int))
{
int i, gpio, nbanks = gpio_to_bank(gpio_end) + 1;
struct pxa_gpio_chip *chips;
chips = kzalloc(nbanks * sizeof(struct pxa_gpio_chip), GFP_KERNEL);
if (chips == NULL) {
pr_err("%s: failed to allocate GPIO chips\n", __func__);
return -ENOMEM;
}
for (i = 0, gpio = 0; i < nbanks; i++, gpio += 32) {
struct gpio_chip *c = &chips[i].chip;
sprintf(chips[i].label, "gpio-%d", i);
chips[i].regbase = gpio_reg_base + BANK_OFF(i);
chips[i].set_wake = set_wake;
c->base = gpio;
c->label = chips[i].label;
c->direction_input = pxa_gpio_direction_input;
c->direction_output = pxa_gpio_direction_output;
c->get = pxa_gpio_get;
c->set = pxa_gpio_set;
c->to_irq = pxa_gpio_to_irq;
#ifdef CONFIG_OF_GPIO
c->of_node = pxa_gpio_of_node;
c->of_xlate = pxa_gpio_of_xlate;
c->of_gpio_n_cells = 2;
#endif
c->ngpio = (gpio + 31 > gpio_end) ? (gpio_end - gpio + 1) : 32;
gpiochip_add(c);
}
pxa_gpio_chips = chips;
return 0;
}
static inline void update_edge_detect(struct pxa_gpio_chip *c)
{
uint32_t grer, gfer;
grer = readl_relaxed(c->regbase + GRER_OFFSET) & ~c->irq_mask;
gfer = readl_relaxed(c->regbase + GFER_OFFSET) & ~c->irq_mask;
grer |= c->irq_edge_rise & c->irq_mask;
gfer |= c->irq_edge_fall & c->irq_mask;
writel_relaxed(grer, c->regbase + GRER_OFFSET);
writel_relaxed(gfer, c->regbase + GFER_OFFSET);
}
static int pxa_gpio_irq_type(struct irq_data *d, unsigned int type)
{
struct pxa_gpio_chip *c;
int gpio = pxa_irq_to_gpio(d->irq);
unsigned long gpdr, mask = GPIO_bit(gpio);
c = gpio_to_pxachip(gpio);
if (type == IRQ_TYPE_PROBE) {
if ((c->irq_edge_rise | c->irq_edge_fall) & GPIO_bit(gpio))
return 0;
if (__gpio_is_occupied(gpio))
return 0;
type = IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING;
}
gpdr = readl_relaxed(c->regbase + GPDR_OFFSET);
if (__gpio_is_inverted(gpio))
writel_relaxed(gpdr | mask, c->regbase + GPDR_OFFSET);
else
writel_relaxed(gpdr & ~mask, c->regbase + GPDR_OFFSET);
if (type & IRQ_TYPE_EDGE_RISING)
c->irq_edge_rise |= mask;
else
c->irq_edge_rise &= ~mask;
if (type & IRQ_TYPE_EDGE_FALLING)
c->irq_edge_fall |= mask;
else
c->irq_edge_fall &= ~mask;
update_edge_detect(c);
pr_debug("%s: IRQ%d (GPIO%d) - edge%s%s\n", __func__, d->irq, gpio,
((type & IRQ_TYPE_EDGE_RISING) ? " rising" : ""),
((type & IRQ_TYPE_EDGE_FALLING) ? " falling" : ""));
return 0;
}
static void pxa_gpio_demux_handler(unsigned int irq, struct irq_desc *desc)
{
struct pxa_gpio_chip *c;
int loop, gpio, gpio_base, n;
unsigned long gedr;
struct irq_chip *chip = irq_desc_get_chip(desc);
chained_irq_enter(chip, desc);
do {
loop = 0;
for_each_gpio_chip(gpio, c) {
gpio_base = c->chip.base;
gedr = readl_relaxed(c->regbase + GEDR_OFFSET);
gedr = gedr & c->irq_mask;
writel_relaxed(gedr, c->regbase + GEDR_OFFSET);
for_each_set_bit(n, &gedr, BITS_PER_LONG) {
loop = 1;
generic_handle_irq(gpio_to_irq(gpio_base + n));
}
}
} while (loop);
chained_irq_exit(chip, desc);
}
static void pxa_ack_muxed_gpio(struct irq_data *d)
{
int gpio = pxa_irq_to_gpio(d->irq);
struct pxa_gpio_chip *c = gpio_to_pxachip(gpio);
writel_relaxed(GPIO_bit(gpio), c->regbase + GEDR_OFFSET);
}
static void pxa_mask_muxed_gpio(struct irq_data *d)
{
int gpio = pxa_irq_to_gpio(d->irq);
struct pxa_gpio_chip *c = gpio_to_pxachip(gpio);
uint32_t grer, gfer;
c->irq_mask &= ~GPIO_bit(gpio);
grer = readl_relaxed(c->regbase + GRER_OFFSET) & ~GPIO_bit(gpio);
gfer = readl_relaxed(c->regbase + GFER_OFFSET) & ~GPIO_bit(gpio);
writel_relaxed(grer, c->regbase + GRER_OFFSET);
writel_relaxed(gfer, c->regbase + GFER_OFFSET);
}
static int pxa_gpio_set_wake(struct irq_data *d, unsigned int on)
{
int gpio = pxa_irq_to_gpio(d->irq);
struct pxa_gpio_chip *c = gpio_to_pxachip(gpio);
if (c->set_wake)
return c->set_wake(gpio, on);
else
return 0;
}
static void pxa_unmask_muxed_gpio(struct irq_data *d)
{
int gpio = pxa_irq_to_gpio(d->irq);
struct pxa_gpio_chip *c = gpio_to_pxachip(gpio);
c->irq_mask |= GPIO_bit(gpio);
update_edge_detect(c);
}
static int pxa_gpio_nums(struct platform_device *pdev)
{
const struct platform_device_id *id = platform_get_device_id(pdev);
struct pxa_gpio_id *pxa_id = (struct pxa_gpio_id *)id->driver_data;
int count = 0;
switch (pxa_id->type) {
case PXA25X_GPIO:
case PXA26X_GPIO:
case PXA27X_GPIO:
case PXA3XX_GPIO:
case PXA93X_GPIO:
case MMP_GPIO:
case MMP2_GPIO:
case PXA1928_GPIO:
gpio_type = pxa_id->type;
count = pxa_id->gpio_nums - 1;
break;
default:
count = -EINVAL;
break;
}
return count;
}
static int pxa_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(irq, &pxa_muxed_gpio_chip,
handle_edge_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
return 0;
}
static int pxa_gpio_probe_dt(struct platform_device *pdev)
{
int ret = 0, nr_gpios;
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(pxa_gpio_dt_ids, &pdev->dev);
const struct pxa_gpio_id *gpio_id;
if (!of_id || !of_id->data) {
dev_err(&pdev->dev, "Failed to find gpio controller\n");
return -EFAULT;
}
gpio_id = of_id->data;
gpio_type = gpio_id->type;
nr_gpios = gpio_id->gpio_nums;
pxa_last_gpio = nr_gpios - 1;
irq_base = irq_alloc_descs(-1, 0, nr_gpios, 0);
if (irq_base < 0) {
dev_err(&pdev->dev, "Failed to allocate IRQ numbers\n");
ret = irq_base;
goto err;
}
domain = irq_domain_add_legacy(np, nr_gpios, irq_base, 0,
&pxa_irq_domain_ops, NULL);
pxa_gpio_of_node = np;
return 0;
err:
iounmap(gpio_reg_base);
return ret;
}
static int pxa_gpio_probe(struct platform_device *pdev)
{
struct pxa_gpio_chip *c;
struct resource *res;
struct clk *clk;
struct pxa_gpio_platform_data *info;
int gpio, irq, ret, use_of = 0;
int irq0 = 0, irq1 = 0, irq_mux, gpio_offset = 0;
info = dev_get_platdata(&pdev->dev);
if (info) {
irq_base = info->irq_base;
if (irq_base <= 0)
return -EINVAL;
pxa_last_gpio = pxa_gpio_nums(pdev);
} else {
irq_base = 0;
use_of = 1;
ret = pxa_gpio_probe_dt(pdev);
if (ret < 0)
return -EINVAL;
}
if (!pxa_last_gpio)
return -EINVAL;
irq0 = platform_get_irq_byname(pdev, "gpio0");
irq1 = platform_get_irq_byname(pdev, "gpio1");
irq_mux = platform_get_irq_byname(pdev, "gpio_mux");
if ((irq0 > 0 && irq1 <= 0) || (irq0 <= 0 && irq1 > 0)
|| (irq_mux <= 0))
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
gpio_reg_base = ioremap(res->start, resource_size(res));
if (!gpio_reg_base)
return -EINVAL;
if (irq0 > 0)
gpio_offset = 2;
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Error %ld to get gpio clock\n",
PTR_ERR(clk));
iounmap(gpio_reg_base);
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
clk_put(clk);
iounmap(gpio_reg_base);
return ret;
}
pxa_init_gpio_chip(pxa_last_gpio, info ? info->gpio_set_wake : NULL);
for_each_gpio_chip(gpio, c) {
writel_relaxed(0, c->regbase + GFER_OFFSET);
writel_relaxed(0, c->regbase + GRER_OFFSET);
writel_relaxed(~0, c->regbase + GEDR_OFFSET);
if (gpio_is_mmp_type(gpio_type))
writel_relaxed(~0, c->regbase + ED_MASK_OFFSET);
}
if (!use_of) {
if (irq0 > 0) {
irq = gpio_to_irq(0);
irq_set_chip_and_handler(irq, &pxa_muxed_gpio_chip,
handle_edge_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
if (irq1 > 0) {
irq = gpio_to_irq(1);
irq_set_chip_and_handler(irq, &pxa_muxed_gpio_chip,
handle_edge_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
for (irq = gpio_to_irq(gpio_offset);
irq <= gpio_to_irq(pxa_last_gpio); irq++) {
irq_set_chip_and_handler(irq, &pxa_muxed_gpio_chip,
handle_edge_irq);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
}
if (irq0 > 0)
irq_set_chained_handler(irq0, pxa_gpio_demux_handler);
if (irq1 > 0)
irq_set_chained_handler(irq1, pxa_gpio_demux_handler);
irq_set_chained_handler(irq_mux, pxa_gpio_demux_handler);
return 0;
}
static int __init pxa_gpio_init(void)
{
return platform_driver_register(&pxa_gpio_driver);
}
static int pxa_gpio_suspend(void)
{
struct pxa_gpio_chip *c;
int gpio;
for_each_gpio_chip(gpio, c) {
c->saved_gplr = readl_relaxed(c->regbase + GPLR_OFFSET);
c->saved_gpdr = readl_relaxed(c->regbase + GPDR_OFFSET);
c->saved_grer = readl_relaxed(c->regbase + GRER_OFFSET);
c->saved_gfer = readl_relaxed(c->regbase + GFER_OFFSET);
writel_relaxed(0xffffffff, c->regbase + GEDR_OFFSET);
}
return 0;
}
static void pxa_gpio_resume(void)
{
struct pxa_gpio_chip *c;
int gpio;
for_each_gpio_chip(gpio, c) {
writel_relaxed(c->saved_gplr, c->regbase + GPSR_OFFSET);
writel_relaxed(~c->saved_gplr, c->regbase + GPCR_OFFSET);
writel_relaxed(c->saved_grer, c->regbase + GRER_OFFSET);
writel_relaxed(c->saved_gfer, c->regbase + GFER_OFFSET);
writel_relaxed(c->saved_gpdr, c->regbase + GPDR_OFFSET);
}
}
static int __init pxa_gpio_sysinit(void)
{
register_syscore_ops(&pxa_gpio_syscore_ops);
return 0;
}
