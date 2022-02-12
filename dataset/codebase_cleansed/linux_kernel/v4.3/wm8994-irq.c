static void wm8994_edge_irq_enable(struct irq_data *data)
{
}
static void wm8994_edge_irq_disable(struct irq_data *data)
{
}
static irqreturn_t wm8994_edge_irq(int irq, void *data)
{
struct wm8994 *wm8994 = data;
while (gpio_get_value_cansleep(wm8994->pdata.irq_gpio))
handle_nested_irq(irq_create_mapping(wm8994->edge_irq, 0));
return IRQ_HANDLED;
}
static int wm8994_edge_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct wm8994 *wm8994 = h->host_data;
irq_set_chip_data(virq, wm8994);
irq_set_chip_and_handler(virq, &wm8994_edge_irq_chip, handle_edge_irq);
irq_set_nested_thread(virq, 1);
irq_set_noprobe(virq);
return 0;
}
int wm8994_irq_init(struct wm8994 *wm8994)
{
int ret;
unsigned long irqflags;
struct wm8994_pdata *pdata = &wm8994->pdata;
if (!wm8994->irq) {
dev_warn(wm8994->dev,
"No interrupt specified, no interrupts\n");
wm8994->irq_base = 0;
return 0;
}
irqflags = IRQF_TRIGGER_HIGH | IRQF_ONESHOT;
if (pdata->irq_flags)
irqflags = pdata->irq_flags;
if (irqflags & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING)) {
if (gpio_to_irq(pdata->irq_gpio) != wm8994->irq) {
dev_warn(wm8994->dev, "IRQ %d is not GPIO %d (%d)\n",
wm8994->irq, pdata->irq_gpio,
gpio_to_irq(pdata->irq_gpio));
wm8994->irq = gpio_to_irq(pdata->irq_gpio);
}
ret = devm_gpio_request_one(wm8994->dev, pdata->irq_gpio,
GPIOF_IN, "WM8994 IRQ");
if (ret != 0) {
dev_err(wm8994->dev, "Failed to get IRQ GPIO: %d\n",
ret);
return ret;
}
wm8994->edge_irq = irq_domain_add_linear(NULL, 1,
&wm8994_edge_irq_ops,
wm8994);
ret = regmap_add_irq_chip(wm8994->regmap,
irq_create_mapping(wm8994->edge_irq,
0),
IRQF_ONESHOT,
wm8994->irq_base, &wm8994_irq_chip,
&wm8994->irq_data);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to get IRQ: %d\n",
ret);
return ret;
}
ret = request_threaded_irq(wm8994->irq,
NULL, wm8994_edge_irq,
irqflags,
"WM8994 edge", wm8994);
} else {
ret = regmap_add_irq_chip(wm8994->regmap, wm8994->irq,
irqflags,
wm8994->irq_base, &wm8994_irq_chip,
&wm8994->irq_data);
}
if (ret != 0) {
dev_err(wm8994->dev, "Failed to register IRQ chip: %d\n", ret);
return ret;
}
wm8994_reg_write(wm8994, WM8994_INTERRUPT_CONTROL, 0);
return 0;
}
void wm8994_irq_exit(struct wm8994 *wm8994)
{
regmap_del_irq_chip(wm8994->irq, wm8994->irq_data);
}
