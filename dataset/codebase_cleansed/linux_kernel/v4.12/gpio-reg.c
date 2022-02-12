static int gpio_reg_get_direction(struct gpio_chip *gc, unsigned offset)
{
struct gpio_reg *r = to_gpio_reg(gc);
return r->direction & BIT(offset) ? 1 : 0;
}
static int gpio_reg_direction_output(struct gpio_chip *gc, unsigned offset,
int value)
{
struct gpio_reg *r = to_gpio_reg(gc);
if (r->direction & BIT(offset))
return -ENOTSUPP;
gc->set(gc, offset, value);
return 0;
}
static int gpio_reg_direction_input(struct gpio_chip *gc, unsigned offset)
{
struct gpio_reg *r = to_gpio_reg(gc);
return r->direction & BIT(offset) ? 0 : -ENOTSUPP;
}
static void gpio_reg_set(struct gpio_chip *gc, unsigned offset, int value)
{
struct gpio_reg *r = to_gpio_reg(gc);
unsigned long flags;
u32 val, mask = BIT(offset);
spin_lock_irqsave(&r->lock, flags);
val = r->out;
if (value)
val |= mask;
else
val &= ~mask;
r->out = val;
writel_relaxed(val, r->reg);
spin_unlock_irqrestore(&r->lock, flags);
}
static int gpio_reg_get(struct gpio_chip *gc, unsigned offset)
{
struct gpio_reg *r = to_gpio_reg(gc);
u32 val, mask = BIT(offset);
if (r->direction & mask) {
readl_relaxed(r->reg);
val = readl_relaxed(r->reg);
} else {
val = r->out;
}
return !!(val & mask);
}
static void gpio_reg_set_multiple(struct gpio_chip *gc, unsigned long *mask,
unsigned long *bits)
{
struct gpio_reg *r = to_gpio_reg(gc);
unsigned long flags;
spin_lock_irqsave(&r->lock, flags);
r->out = (r->out & ~*mask) | (*bits & *mask);
writel_relaxed(r->out, r->reg);
spin_unlock_irqrestore(&r->lock, flags);
}
static int gpio_reg_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct gpio_reg *r = to_gpio_reg(gc);
int irq = r->irqs[offset];
if (irq >= 0 && r->irqdomain)
irq = irq_find_mapping(r->irqdomain, irq);
return irq;
}
struct gpio_chip *gpio_reg_init(struct device *dev, void __iomem *reg,
int base, int num, const char *label, u32 direction, u32 def_out,
const char *const *names, struct irq_domain *irqdom, const int *irqs)
{
struct gpio_reg *r;
int ret;
if (dev)
r = devm_kzalloc(dev, sizeof(*r), GFP_KERNEL);
else
r = kzalloc(sizeof(*r), GFP_KERNEL);
if (!r)
return ERR_PTR(-ENOMEM);
spin_lock_init(&r->lock);
r->gc.label = label;
r->gc.get_direction = gpio_reg_get_direction;
r->gc.direction_input = gpio_reg_direction_input;
r->gc.direction_output = gpio_reg_direction_output;
r->gc.set = gpio_reg_set;
r->gc.get = gpio_reg_get;
r->gc.set_multiple = gpio_reg_set_multiple;
if (irqs)
r->gc.to_irq = gpio_reg_to_irq;
r->gc.base = base;
r->gc.ngpio = num;
r->gc.names = names;
r->direction = direction;
r->out = def_out;
r->reg = reg;
r->irqs = irqs;
if (dev)
ret = devm_gpiochip_add_data(dev, &r->gc, r);
else
ret = gpiochip_add_data(&r->gc, r);
return ret ? ERR_PTR(ret) : &r->gc;
}
int gpio_reg_resume(struct gpio_chip *gc)
{
struct gpio_reg *r = to_gpio_reg(gc);
unsigned long flags;
spin_lock_irqsave(&r->lock, flags);
writel_relaxed(r->out, r->reg);
spin_unlock_irqrestore(&r->lock, flags);
return 0;
}
