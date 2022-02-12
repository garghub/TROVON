static void gpio_halt_wfn(struct work_struct *work)
{
orderly_poweroff(true);
}
static void gpio_halt_cb(void)
{
enum of_gpio_flags flags;
int trigger, gpio;
if (!halt_node)
return;
gpio = of_get_gpio_flags(halt_node, 0, &flags);
if (!gpio_is_valid(gpio))
return;
trigger = (flags == OF_GPIO_ACTIVE_LOW);
printk(KERN_INFO "gpio-halt: triggering GPIO.\n");
gpio_set_value(gpio, trigger);
}
static irqreturn_t gpio_halt_irq(int irq, void *__data)
{
printk(KERN_INFO "gpio-halt: shutdown due to power button IRQ.\n");
schedule_work(&gpio_halt_wq);
return IRQ_HANDLED;
}
static int gpio_halt_probe(struct platform_device *pdev)
{
enum of_gpio_flags flags;
struct device_node *node = pdev->dev.of_node;
int gpio, err, irq;
int trigger;
if (!node)
return -ENODEV;
halt_node = of_find_matching_node(node, child_match);
if (!halt_node)
return 0;
if (of_gpio_count(halt_node) != 1)
return -EINVAL;
gpio = of_get_gpio_flags(halt_node, 0, &flags);
if (!gpio_is_valid(gpio))
return -EINVAL;
err = gpio_request(gpio, "gpio-halt");
if (err) {
printk(KERN_ERR "gpio-halt: error requesting GPIO %d.\n",
gpio);
halt_node = NULL;
return err;
}
trigger = (flags == OF_GPIO_ACTIVE_LOW);
gpio_direction_output(gpio, !trigger);
irq = irq_of_parse_and_map(halt_node, 0);
err = request_irq(irq, gpio_halt_irq, IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING, "gpio-halt", halt_node);
if (err) {
printk(KERN_ERR "gpio-halt: error requesting IRQ %d for "
"GPIO %d.\n", irq, gpio);
gpio_free(gpio);
halt_node = NULL;
return err;
}
ppc_md.halt = gpio_halt_cb;
ppc_md.power_off = gpio_halt_cb;
printk(KERN_INFO "gpio-halt: registered GPIO %d (%d trigger, %d"
" irq).\n", gpio, trigger, irq);
return 0;
}
static int gpio_halt_remove(struct platform_device *pdev)
{
if (halt_node) {
int gpio = of_get_gpio(halt_node, 0);
int irq = irq_of_parse_and_map(halt_node, 0);
free_irq(irq, halt_node);
ppc_md.halt = NULL;
ppc_md.power_off = NULL;
gpio_free(gpio);
halt_node = NULL;
}
return 0;
}
