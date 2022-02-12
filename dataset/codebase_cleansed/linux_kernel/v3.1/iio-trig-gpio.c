static irqreturn_t iio_gpio_trigger_poll(int irq, void *private)
{
iio_trigger_poll(private, 0);
return IRQ_HANDLED;
}
static int iio_gpio_trigger_probe(struct platform_device *pdev)
{
struct iio_gpio_trigger_info *trig_info;
struct iio_trigger *trig, *trig2;
unsigned long irqflags;
struct resource *irq_res;
int irq, ret = 0, irq_res_cnt = 0;
do {
irq_res = platform_get_resource(pdev,
IORESOURCE_IRQ, irq_res_cnt);
if (irq_res == NULL) {
if (irq_res_cnt == 0)
dev_err(&pdev->dev, "No GPIO IRQs specified");
break;
}
irqflags = (irq_res->flags & IRQF_TRIGGER_MASK) | IRQF_SHARED;
for (irq = irq_res->start; irq <= irq_res->end; irq++) {
trig = iio_allocate_trigger("irqtrig%d", irq);
if (!trig) {
ret = -ENOMEM;
goto error_free_completed_registrations;
}
trig_info = kzalloc(sizeof(*trig_info), GFP_KERNEL);
if (!trig_info) {
ret = -ENOMEM;
goto error_put_trigger;
}
trig->private_data = trig_info;
trig_info->irq = irq;
trig->owner = THIS_MODULE;
ret = request_irq(irq, iio_gpio_trigger_poll,
irqflags, trig->name, trig);
if (ret) {
dev_err(&pdev->dev,
"request IRQ-%d failed", irq);
goto error_free_trig_info;
}
ret = iio_trigger_register(trig);
if (ret)
goto error_release_irq;
list_add_tail(&trig->alloc_list,
&iio_gpio_trigger_list);
}
irq_res_cnt++;
} while (irq_res != NULL);
return 0;
error_release_irq:
free_irq(irq, trig);
error_free_trig_info:
kfree(trig_info);
error_put_trigger:
iio_put_trigger(trig);
error_free_completed_registrations:
list_for_each_entry_safe(trig,
trig2,
&iio_gpio_trigger_list,
alloc_list) {
trig_info = trig->private_data;
free_irq(gpio_to_irq(trig_info->irq), trig);
kfree(trig_info);
iio_trigger_unregister(trig);
}
return ret;
}
static int iio_gpio_trigger_remove(struct platform_device *pdev)
{
struct iio_trigger *trig, *trig2;
struct iio_gpio_trigger_info *trig_info;
mutex_lock(&iio_gpio_trigger_list_lock);
list_for_each_entry_safe(trig,
trig2,
&iio_gpio_trigger_list,
alloc_list) {
trig_info = trig->private_data;
iio_trigger_unregister(trig);
free_irq(trig_info->irq, trig);
kfree(trig_info);
iio_put_trigger(trig);
}
mutex_unlock(&iio_gpio_trigger_list_lock);
return 0;
}
static int __init iio_gpio_trig_init(void)
{
return platform_driver_register(&iio_gpio_trigger_driver);
}
static void __exit iio_gpio_trig_exit(void)
{
platform_driver_unregister(&iio_gpio_trigger_driver);
}
