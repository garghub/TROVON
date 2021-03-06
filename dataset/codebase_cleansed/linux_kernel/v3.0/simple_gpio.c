static struct u8_gpio_chip *to_u8_gpio_chip(struct of_mm_gpio_chip *mm_gc)
{
return container_of(mm_gc, struct u8_gpio_chip, mm_gc);
}
static u8 u8_pin2mask(unsigned int pin)
{
return 1 << (8 - 1 - pin);
}
static int u8_gpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
return in_8(mm_gc->regs) & u8_pin2mask(gpio);
}
static void u8_gpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct u8_gpio_chip *u8_gc = to_u8_gpio_chip(mm_gc);
unsigned long flags;
spin_lock_irqsave(&u8_gc->lock, flags);
if (val)
u8_gc->data |= u8_pin2mask(gpio);
else
u8_gc->data &= ~u8_pin2mask(gpio);
out_8(mm_gc->regs, u8_gc->data);
spin_unlock_irqrestore(&u8_gc->lock, flags);
}
static int u8_gpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
return 0;
}
static int u8_gpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
u8_gpio_set(gc, gpio, val);
return 0;
}
static void u8_gpio_save_regs(struct of_mm_gpio_chip *mm_gc)
{
struct u8_gpio_chip *u8_gc = to_u8_gpio_chip(mm_gc);
u8_gc->data = in_8(mm_gc->regs);
}
static int __init u8_simple_gpiochip_add(struct device_node *np)
{
int ret;
struct u8_gpio_chip *u8_gc;
struct of_mm_gpio_chip *mm_gc;
struct gpio_chip *gc;
u8_gc = kzalloc(sizeof(*u8_gc), GFP_KERNEL);
if (!u8_gc)
return -ENOMEM;
spin_lock_init(&u8_gc->lock);
mm_gc = &u8_gc->mm_gc;
gc = &mm_gc->gc;
mm_gc->save_regs = u8_gpio_save_regs;
gc->ngpio = 8;
gc->direction_input = u8_gpio_dir_in;
gc->direction_output = u8_gpio_dir_out;
gc->get = u8_gpio_get;
gc->set = u8_gpio_set;
ret = of_mm_gpiochip_add(np, mm_gc);
if (ret)
goto err;
return 0;
err:
kfree(u8_gc);
return ret;
}
void __init simple_gpiochip_init(const char *compatible)
{
struct device_node *np;
for_each_compatible_node(np, NULL, compatible) {
int ret;
struct resource r;
ret = of_address_to_resource(np, 0, &r);
if (ret)
goto err;
switch (resource_size(&r)) {
case 1:
ret = u8_simple_gpiochip_add(np);
if (ret)
goto err;
break;
default:
ret = -ENOSYS;
goto err;
}
continue;
err:
pr_err("%s: registration failed, status %d\n",
np->full_name, ret);
}
}
