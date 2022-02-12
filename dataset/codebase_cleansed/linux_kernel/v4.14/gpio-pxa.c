static inline struct pxa_gpio_chip *chip_to_pxachip(struct gpio_chip *c)
{
struct pxa_gpio_chip *pxa_chip = gpiochip_get_data(c);
return pxa_chip;
}
static inline void __iomem *gpio_bank_base(struct gpio_chip *c, int gpio)
{
struct pxa_gpio_chip *p = gpiochip_get_data(c);
struct pxa_gpio_bank *bank = p->banks + (gpio / 32);
return bank->regbase;
}
static inline struct pxa_gpio_bank *gpio_to_pxabank(struct gpio_chip *c,
unsigned gpio)
{
return chip_to_pxachip(c)->banks + gpio / 32;
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
static inline int __gpio_is_occupied(struct pxa_gpio_chip *pchip, unsigned gpio)
{
void __iomem *base;
unsigned long gafr = 0, gpdr = 0;
int ret, af = 0, dir = 0;
base = gpio_bank_base(&pchip->chip, gpio);
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
int pxa_irq_to_gpio(int irq)
{
struct pxa_gpio_chip *pchip = pxa_gpio_chip;
int irq_gpio0;
irq_gpio0 = irq_find_mapping(pchip->irqdomain, 0);
if (irq_gpio0 > 0)
return irq - irq_gpio0;
return irq_gpio0;
}
static int pxa_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct pxa_gpio_chip *pchip = chip_to_pxachip(chip);
return irq_find_mapping(pchip->irqdomain, offset);
}
static int pxa_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
void __iomem *base = gpio_bank_base(chip, offset);
uint32_t value, mask = GPIO_bit(offset);
unsigned long flags;
int ret;
ret = pinctrl_gpio_direction_input(chip->base + offset);
if (!ret)
return 0;
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
void __iomem *base = gpio_bank_base(chip, offset);
uint32_t tmp, mask = GPIO_bit(offset);
unsigned long flags;
int ret;
writel_relaxed(mask, base + (value ? GPSR_OFFSET : GPCR_OFFSET));
ret = pinctrl_gpio_direction_output(chip->base + offset);
if (ret)
return ret;
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
void __iomem *base = gpio_bank_base(chip, offset);
u32 gplr = readl_relaxed(base + GPLR_OFFSET);
return !!(gplr & GPIO_bit(offset));
}
static void pxa_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
void __iomem *base = gpio_bank_base(chip, offset);
writel_relaxed(GPIO_bit(offset),
base + (value ? GPSR_OFFSET : GPCR_OFFSET));
}
static int pxa_gpio_of_xlate(struct gpio_chip *gc,
const struct of_phandle_args *gpiospec,
u32 *flags)
{
if (gpiospec->args[0] > pxa_last_gpio)
return -EINVAL;
if (flags)
*flags = gpiospec->args[1];
return gpiospec->args[0];
}
static int pxa_gpio_request(struct gpio_chip *chip, unsigned int offset)
{
return pinctrl_request_gpio(chip->base + offset);
}
static void pxa_gpio_free(struct gpio_chip *chip, unsigned int offset)
{
pinctrl_free_gpio(chip->base + offset);
}
static int pxa_init_gpio_chip(struct pxa_gpio_chip *pchip, int ngpio,
struct device_node *np, void __iomem *regbase)
{
int i, gpio, nbanks = DIV_ROUND_UP(ngpio, 32);
struct pxa_gpio_bank *bank;
pchip->banks = devm_kcalloc(pchip->dev, nbanks, sizeof(*pchip->banks),
GFP_KERNEL);
if (!pchip->banks)
return -ENOMEM;
pchip->chip.label = "gpio-pxa";
pchip->chip.direction_input = pxa_gpio_direction_input;
pchip->chip.direction_output = pxa_gpio_direction_output;
pchip->chip.get = pxa_gpio_get;
pchip->chip.set = pxa_gpio_set;
pchip->chip.to_irq = pxa_gpio_to_irq;
pchip->chip.ngpio = ngpio;
pchip->chip.request = pxa_gpio_request;
pchip->chip.free = pxa_gpio_free;
#ifdef CONFIG_OF_GPIO
pchip->chip.of_node = np;
pchip->chip.of_xlate = pxa_gpio_of_xlate;
pchip->chip.of_gpio_n_cells = 2;
#endif
for (i = 0, gpio = 0; i < nbanks; i++, gpio += 32) {
bank = pchip->banks + i;
bank->regbase = regbase + BANK_OFF(i);
}
return gpiochip_add_data(&pchip->chip, pchip);
}
static inline void update_edge_detect(struct pxa_gpio_bank *c)
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
struct pxa_gpio_chip *pchip = irq_data_get_irq_chip_data(d);
unsigned int gpio = irqd_to_hwirq(d);
struct pxa_gpio_bank *c = gpio_to_pxabank(&pchip->chip, gpio);
unsigned long gpdr, mask = GPIO_bit(gpio);
if (type == IRQ_TYPE_PROBE) {
if ((c->irq_edge_rise | c->irq_edge_fall) & GPIO_bit(gpio))
return 0;
if (__gpio_is_occupied(pchip, gpio))
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
static irqreturn_t pxa_gpio_demux_handler(int in_irq, void *d)
{
int loop, gpio, n, handled = 0;
unsigned long gedr;
struct pxa_gpio_chip *pchip = d;
struct pxa_gpio_bank *c;
do {
loop = 0;
for_each_gpio_bank(gpio, c, pchip) {
gedr = readl_relaxed(c->regbase + GEDR_OFFSET);
gedr = gedr & c->irq_mask;
writel_relaxed(gedr, c->regbase + GEDR_OFFSET);
for_each_set_bit(n, &gedr, BITS_PER_LONG) {
loop = 1;
generic_handle_irq(
irq_find_mapping(pchip->irqdomain,
gpio + n));
}
}
handled += loop;
} while (loop);
return handled ? IRQ_HANDLED : IRQ_NONE;
}
static irqreturn_t pxa_gpio_direct_handler(int in_irq, void *d)
{
struct pxa_gpio_chip *pchip = d;
if (in_irq == pchip->irq0) {
generic_handle_irq(irq_find_mapping(pchip->irqdomain, 0));
} else if (in_irq == pchip->irq1) {
generic_handle_irq(irq_find_mapping(pchip->irqdomain, 1));
} else {
pr_err("%s() unknown irq %d\n", __func__, in_irq);
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static void pxa_ack_muxed_gpio(struct irq_data *d)
{
struct pxa_gpio_chip *pchip = irq_data_get_irq_chip_data(d);
unsigned int gpio = irqd_to_hwirq(d);
void __iomem *base = gpio_bank_base(&pchip->chip, gpio);
writel_relaxed(GPIO_bit(gpio), base + GEDR_OFFSET);
}
static void pxa_mask_muxed_gpio(struct irq_data *d)
{
struct pxa_gpio_chip *pchip = irq_data_get_irq_chip_data(d);
unsigned int gpio = irqd_to_hwirq(d);
struct pxa_gpio_bank *b = gpio_to_pxabank(&pchip->chip, gpio);
void __iomem *base = gpio_bank_base(&pchip->chip, gpio);
uint32_t grer, gfer;
b->irq_mask &= ~GPIO_bit(gpio);
grer = readl_relaxed(base + GRER_OFFSET) & ~GPIO_bit(gpio);
gfer = readl_relaxed(base + GFER_OFFSET) & ~GPIO_bit(gpio);
writel_relaxed(grer, base + GRER_OFFSET);
writel_relaxed(gfer, base + GFER_OFFSET);
}
static int pxa_gpio_set_wake(struct irq_data *d, unsigned int on)
{
struct pxa_gpio_chip *pchip = irq_data_get_irq_chip_data(d);
unsigned int gpio = irqd_to_hwirq(d);
if (pchip->set_wake)
return pchip->set_wake(gpio, on);
else
return 0;
}
static void pxa_unmask_muxed_gpio(struct irq_data *d)
{
struct pxa_gpio_chip *pchip = irq_data_get_irq_chip_data(d);
unsigned int gpio = irqd_to_hwirq(d);
struct pxa_gpio_bank *c = gpio_to_pxabank(&pchip->chip, gpio);
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
irq_set_chip_data(irq, d->host_data);
irq_set_noprobe(irq);
return 0;
}
static int pxa_gpio_probe_dt(struct platform_device *pdev,
struct pxa_gpio_chip *pchip)
{
int nr_gpios;
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
irq_base = devm_irq_alloc_descs(&pdev->dev, -1, 0, nr_gpios, 0);
if (irq_base < 0) {
dev_err(&pdev->dev, "Failed to allocate IRQ numbers\n");
return irq_base;
}
return irq_base;
}
static int pxa_gpio_probe(struct platform_device *pdev)
{
struct pxa_gpio_chip *pchip;
struct pxa_gpio_bank *c;
struct resource *res;
struct clk *clk;
struct pxa_gpio_platform_data *info;
void __iomem *gpio_reg_base;
int gpio, ret;
int irq0 = 0, irq1 = 0, irq_mux, gpio_offset = 0;
pchip = devm_kzalloc(&pdev->dev, sizeof(*pchip), GFP_KERNEL);
if (!pchip)
return -ENOMEM;
pchip->dev = &pdev->dev;
info = dev_get_platdata(&pdev->dev);
if (info) {
irq_base = info->irq_base;
if (irq_base <= 0)
return -EINVAL;
pxa_last_gpio = pxa_gpio_nums(pdev);
pchip->set_wake = info->gpio_set_wake;
} else {
irq_base = pxa_gpio_probe_dt(pdev, pchip);
if (irq_base < 0)
return -EINVAL;
}
if (!pxa_last_gpio)
return -EINVAL;
pchip->irqdomain = irq_domain_add_legacy(pdev->dev.of_node,
pxa_last_gpio + 1, irq_base,
0, &pxa_irq_domain_ops, pchip);
if (!pchip->irqdomain)
return -ENOMEM;
irq0 = platform_get_irq_byname(pdev, "gpio0");
irq1 = platform_get_irq_byname(pdev, "gpio1");
irq_mux = platform_get_irq_byname(pdev, "gpio_mux");
if ((irq0 > 0 && irq1 <= 0) || (irq0 <= 0 && irq1 > 0)
|| (irq_mux <= 0))
return -EINVAL;
pchip->irq0 = irq0;
pchip->irq1 = irq1;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gpio_reg_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!gpio_reg_base)
return -EINVAL;
if (irq0 > 0)
gpio_offset = 2;
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Error %ld to get gpio clock\n",
PTR_ERR(clk));
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
clk_put(clk);
return ret;
}
ret = pxa_init_gpio_chip(pchip, pxa_last_gpio + 1, pdev->dev.of_node,
gpio_reg_base);
if (ret) {
clk_put(clk);
return ret;
}
for_each_gpio_bank(gpio, c, pchip) {
writel_relaxed(0, c->regbase + GFER_OFFSET);
writel_relaxed(0, c->regbase + GRER_OFFSET);
writel_relaxed(~0, c->regbase + GEDR_OFFSET);
if (gpio_is_mmp_type(gpio_type))
writel_relaxed(~0, c->regbase + ED_MASK_OFFSET);
}
if (irq0 > 0) {
ret = devm_request_irq(&pdev->dev,
irq0, pxa_gpio_direct_handler, 0,
"gpio-0", pchip);
if (ret)
dev_err(&pdev->dev, "request of gpio0 irq failed: %d\n",
ret);
}
if (irq1 > 0) {
ret = devm_request_irq(&pdev->dev,
irq1, pxa_gpio_direct_handler, 0,
"gpio-1", pchip);
if (ret)
dev_err(&pdev->dev, "request of gpio1 irq failed: %d\n",
ret);
}
ret = devm_request_irq(&pdev->dev,
irq_mux, pxa_gpio_demux_handler, 0,
"gpio-mux", pchip);
if (ret)
dev_err(&pdev->dev, "request of gpio-mux irq failed: %d\n",
ret);
pxa_gpio_chip = pchip;
return 0;
}
static int __init pxa_gpio_legacy_init(void)
{
if (of_have_populated_dt())
return 0;
return platform_driver_register(&pxa_gpio_driver);
}
static int __init pxa_gpio_dt_init(void)
{
if (of_have_populated_dt())
return platform_driver_register(&pxa_gpio_driver);
return 0;
}
static int pxa_gpio_suspend(void)
{
struct pxa_gpio_chip *pchip = pxa_gpio_chip;
struct pxa_gpio_bank *c;
int gpio;
for_each_gpio_bank(gpio, c, pchip) {
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
struct pxa_gpio_chip *pchip = pxa_gpio_chip;
struct pxa_gpio_bank *c;
int gpio;
for_each_gpio_bank(gpio, c, pchip) {
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
