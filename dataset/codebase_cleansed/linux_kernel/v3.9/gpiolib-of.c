static int of_gpiochip_find_and_xlate(struct gpio_chip *gc, void *data)
{
struct gg_data *gg_data = data;
int ret;
if ((gc->of_node != gg_data->gpiospec.np) ||
(gc->of_gpio_n_cells != gg_data->gpiospec.args_count) ||
(!gc->of_xlate))
return false;
ret = gc->of_xlate(gc, &gg_data->gpiospec, gg_data->flags);
if (ret < 0)
return false;
gg_data->out_gpio = ret + gc->base;
return true;
}
int of_get_named_gpio_flags(struct device_node *np, const char *propname,
int index, enum of_gpio_flags *flags)
{
struct gg_data gg_data = { .flags = flags, .out_gpio = -EPROBE_DEFER };
int ret;
if (flags)
*flags = 0;
ret = of_parse_phandle_with_args(np, propname, "#gpio-cells", index,
&gg_data.gpiospec);
if (ret) {
pr_debug("%s: can't parse gpios property\n", __func__);
return ret;
}
gpiochip_find(&gg_data, of_gpiochip_find_and_xlate);
of_node_put(gg_data.gpiospec.np);
pr_debug("%s exited with status %d\n", __func__, gg_data.out_gpio);
return gg_data.out_gpio;
}
int of_gpio_simple_xlate(struct gpio_chip *gc,
const struct of_phandle_args *gpiospec, u32 *flags)
{
if (gc->of_gpio_n_cells < 2) {
WARN_ON(1);
return -EINVAL;
}
if (WARN_ON(gpiospec->args_count < gc->of_gpio_n_cells))
return -EINVAL;
if (gpiospec->args[0] >= gc->ngpio)
return -EINVAL;
if (flags)
*flags = gpiospec->args[1];
return gpiospec->args[0];
}
int of_mm_gpiochip_add(struct device_node *np,
struct of_mm_gpio_chip *mm_gc)
{
int ret = -ENOMEM;
struct gpio_chip *gc = &mm_gc->gc;
gc->label = kstrdup(np->full_name, GFP_KERNEL);
if (!gc->label)
goto err0;
mm_gc->regs = of_iomap(np, 0);
if (!mm_gc->regs)
goto err1;
gc->base = -1;
if (mm_gc->save_regs)
mm_gc->save_regs(mm_gc);
mm_gc->gc.of_node = np;
ret = gpiochip_add(gc);
if (ret)
goto err2;
return 0;
err2:
iounmap(mm_gc->regs);
err1:
kfree(gc->label);
err0:
pr_err("%s: GPIO chip registration failed with status %d\n",
np->full_name, ret);
return ret;
}
static void of_gpiochip_add_pin_range(struct gpio_chip *chip)
{
struct device_node *np = chip->of_node;
struct of_phandle_args pinspec;
struct pinctrl_dev *pctldev;
int index = 0, ret;
if (!np)
return;
for (;; index++) {
ret = of_parse_phandle_with_args(np, "gpio-ranges",
"#gpio-range-cells", index, &pinspec);
if (ret)
break;
pctldev = of_pinctrl_get(pinspec.np);
if (!pctldev)
break;
ret = gpiochip_add_pin_range(chip,
pinctrl_dev_get_devname(pctldev),
0,
pinspec.args[0],
pinspec.args[1]);
if (ret)
break;
}
}
static void of_gpiochip_add_pin_range(struct gpio_chip *chip) {}
void of_gpiochip_add(struct gpio_chip *chip)
{
if ((!chip->of_node) && (chip->dev))
chip->of_node = chip->dev->of_node;
if (!chip->of_node)
return;
if (!chip->of_xlate) {
chip->of_gpio_n_cells = 2;
chip->of_xlate = of_gpio_simple_xlate;
}
of_gpiochip_add_pin_range(chip);
of_node_get(chip->of_node);
}
void of_gpiochip_remove(struct gpio_chip *chip)
{
gpiochip_remove_pin_ranges(chip);
if (chip->of_node)
of_node_put(chip->of_node);
}
