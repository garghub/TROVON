int wm8994_irq_init(struct wm8994 *wm8994)
{
int ret;
unsigned long irqflags;
struct wm8994_pdata *pdata = wm8994->dev->platform_data;
if (!wm8994->irq) {
dev_warn(wm8994->dev,
"No interrupt specified, no interrupts\n");
wm8994->irq_base = 0;
return 0;
}
irqflags = IRQF_TRIGGER_HIGH | IRQF_ONESHOT;
if (pdata->irq_flags)
irqflags = pdata->irq_flags;
ret = regmap_add_irq_chip(wm8994->regmap, wm8994->irq,
irqflags,
wm8994->irq_base, &wm8994_irq_chip,
&wm8994->irq_data);
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
