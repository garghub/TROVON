static void iio_dummy_event_irqmask(struct irq_data *d)
{
struct irq_chip *chip = irq_data_get_irq_chip(d);
struct iio_dummy_eventgen *evgen =
container_of(chip, struct iio_dummy_eventgen, chip);
evgen->enabled[d->irq - evgen->base] = false;
}
static void iio_dummy_event_irqunmask(struct irq_data *d)
{
struct irq_chip *chip = irq_data_get_irq_chip(d);
struct iio_dummy_eventgen *evgen =
container_of(chip, struct iio_dummy_eventgen, chip);
evgen->enabled[d->irq - evgen->base] = true;
}
static int iio_dummy_evgen_create(void)
{
int ret, i;
iio_evgen = kzalloc(sizeof(*iio_evgen), GFP_KERNEL);
if (iio_evgen == NULL)
return -ENOMEM;
iio_evgen->base = irq_alloc_descs(-1, 0, IIO_EVENTGEN_NO, 0);
if (iio_evgen->base < 0) {
ret = iio_evgen->base;
kfree(iio_evgen);
return ret;
}
iio_evgen->chip.name = iio_evgen_name;
iio_evgen->chip.irq_mask = &iio_dummy_event_irqmask;
iio_evgen->chip.irq_unmask = &iio_dummy_event_irqunmask;
for (i = 0; i < IIO_EVENTGEN_NO; i++) {
irq_set_chip(iio_evgen->base + i, &iio_evgen->chip);
irq_set_handler(iio_evgen->base + i, &handle_simple_irq);
irq_modify_status(iio_evgen->base + i,
IRQ_NOREQUEST | IRQ_NOAUTOEN,
IRQ_NOPROBE);
}
mutex_init(&iio_evgen->lock);
return 0;
}
int iio_dummy_evgen_get_irq(void)
{
int i, ret = 0;
if (iio_evgen == NULL)
return -ENODEV;
mutex_lock(&iio_evgen->lock);
for (i = 0; i < IIO_EVENTGEN_NO; i++)
if (!iio_evgen->inuse[i]) {
ret = iio_evgen->base + i;
iio_evgen->inuse[i] = true;
break;
}
mutex_unlock(&iio_evgen->lock);
if (i == IIO_EVENTGEN_NO)
return -ENOMEM;
return ret;
}
int iio_dummy_evgen_release_irq(int irq)
{
mutex_lock(&iio_evgen->lock);
iio_evgen->inuse[irq - iio_evgen->base] = false;
mutex_unlock(&iio_evgen->lock);
return 0;
}
static void iio_dummy_evgen_free(void)
{
irq_free_descs(iio_evgen->base, IIO_EVENTGEN_NO);
kfree(iio_evgen);
}
static void iio_evgen_release(struct device *dev)
{
iio_dummy_evgen_free();
}
static ssize_t iio_evgen_poke(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
if (iio_evgen->enabled[this_attr->address])
handle_nested_irq(iio_evgen->base + this_attr->address);
return len;
}
static __init int iio_dummy_evgen_init(void)
{
int ret = iio_dummy_evgen_create();
if (ret < 0)
return ret;
device_initialize(&iio_evgen_dev);
dev_set_name(&iio_evgen_dev, "iio_evgen");
return device_add(&iio_evgen_dev);
}
static __exit void iio_dummy_evgen_exit(void)
{
device_unregister(&iio_evgen_dev);
}
