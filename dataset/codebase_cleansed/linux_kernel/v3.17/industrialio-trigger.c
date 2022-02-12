static ssize_t iio_trigger_read_name(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_trigger *trig = to_iio_trigger(dev);
return sprintf(buf, "%s\n", trig->name);
}
int iio_trigger_register(struct iio_trigger *trig_info)
{
int ret;
trig_info->id = ida_simple_get(&iio_trigger_ida, 0, 0, GFP_KERNEL);
if (trig_info->id < 0)
return trig_info->id;
dev_set_name(&trig_info->dev, "trigger%ld",
(unsigned long) trig_info->id);
ret = device_add(&trig_info->dev);
if (ret)
goto error_unregister_id;
mutex_lock(&iio_trigger_list_lock);
list_add_tail(&trig_info->list, &iio_trigger_list);
mutex_unlock(&iio_trigger_list_lock);
return 0;
error_unregister_id:
ida_simple_remove(&iio_trigger_ida, trig_info->id);
return ret;
}
void iio_trigger_unregister(struct iio_trigger *trig_info)
{
mutex_lock(&iio_trigger_list_lock);
list_del(&trig_info->list);
mutex_unlock(&iio_trigger_list_lock);
ida_simple_remove(&iio_trigger_ida, trig_info->id);
device_del(&trig_info->dev);
}
static struct iio_trigger *iio_trigger_find_by_name(const char *name,
size_t len)
{
struct iio_trigger *trig = NULL, *iter;
mutex_lock(&iio_trigger_list_lock);
list_for_each_entry(iter, &iio_trigger_list, list)
if (sysfs_streq(iter->name, name)) {
trig = iter;
break;
}
mutex_unlock(&iio_trigger_list_lock);
return trig;
}
void iio_trigger_poll(struct iio_trigger *trig)
{
int i;
if (!atomic_read(&trig->use_count)) {
atomic_set(&trig->use_count, CONFIG_IIO_CONSUMERS_PER_TRIGGER);
for (i = 0; i < CONFIG_IIO_CONSUMERS_PER_TRIGGER; i++) {
if (trig->subirqs[i].enabled)
generic_handle_irq(trig->subirq_base + i);
else
iio_trigger_notify_done(trig);
}
}
}
irqreturn_t iio_trigger_generic_data_rdy_poll(int irq, void *private)
{
iio_trigger_poll(private);
return IRQ_HANDLED;
}
void iio_trigger_poll_chained(struct iio_trigger *trig)
{
int i;
if (!atomic_read(&trig->use_count)) {
atomic_set(&trig->use_count, CONFIG_IIO_CONSUMERS_PER_TRIGGER);
for (i = 0; i < CONFIG_IIO_CONSUMERS_PER_TRIGGER; i++) {
if (trig->subirqs[i].enabled)
handle_nested_irq(trig->subirq_base + i);
else
iio_trigger_notify_done(trig);
}
}
}
void iio_trigger_notify_done(struct iio_trigger *trig)
{
if (atomic_dec_and_test(&trig->use_count) && trig->ops &&
trig->ops->try_reenable)
if (trig->ops->try_reenable(trig))
iio_trigger_poll(trig);
}
static int iio_trigger_get_irq(struct iio_trigger *trig)
{
int ret;
mutex_lock(&trig->pool_lock);
ret = bitmap_find_free_region(trig->pool,
CONFIG_IIO_CONSUMERS_PER_TRIGGER,
ilog2(1));
mutex_unlock(&trig->pool_lock);
if (ret >= 0)
ret += trig->subirq_base;
return ret;
}
static void iio_trigger_put_irq(struct iio_trigger *trig, int irq)
{
mutex_lock(&trig->pool_lock);
clear_bit(irq - trig->subirq_base, trig->pool);
mutex_unlock(&trig->pool_lock);
}
static int iio_trigger_attach_poll_func(struct iio_trigger *trig,
struct iio_poll_func *pf)
{
int ret = 0;
bool notinuse
= bitmap_empty(trig->pool, CONFIG_IIO_CONSUMERS_PER_TRIGGER);
__module_get(pf->indio_dev->info->driver_module);
pf->irq = iio_trigger_get_irq(trig);
ret = request_threaded_irq(pf->irq, pf->h, pf->thread,
pf->type, pf->name,
pf);
if (ret < 0) {
module_put(pf->indio_dev->info->driver_module);
return ret;
}
if (trig->ops && trig->ops->set_trigger_state && notinuse) {
ret = trig->ops->set_trigger_state(trig, true);
if (ret < 0)
module_put(pf->indio_dev->info->driver_module);
}
return ret;
}
static int iio_trigger_detach_poll_func(struct iio_trigger *trig,
struct iio_poll_func *pf)
{
int ret = 0;
bool no_other_users
= (bitmap_weight(trig->pool,
CONFIG_IIO_CONSUMERS_PER_TRIGGER)
== 1);
if (trig->ops && trig->ops->set_trigger_state && no_other_users) {
ret = trig->ops->set_trigger_state(trig, false);
if (ret)
return ret;
}
iio_trigger_put_irq(trig, pf->irq);
free_irq(pf->irq, pf);
module_put(pf->indio_dev->info->driver_module);
return ret;
}
irqreturn_t iio_pollfunc_store_time(int irq, void *p)
{
struct iio_poll_func *pf = p;
pf->timestamp = iio_get_time_ns();
return IRQ_WAKE_THREAD;
}
struct iio_poll_func
*iio_alloc_pollfunc(irqreturn_t (*h)(int irq, void *p),
irqreturn_t (*thread)(int irq, void *p),
int type,
struct iio_dev *indio_dev,
const char *fmt,
...)
{
va_list vargs;
struct iio_poll_func *pf;
pf = kmalloc(sizeof *pf, GFP_KERNEL);
if (pf == NULL)
return NULL;
va_start(vargs, fmt);
pf->name = kvasprintf(GFP_KERNEL, fmt, vargs);
va_end(vargs);
if (pf->name == NULL) {
kfree(pf);
return NULL;
}
pf->h = h;
pf->thread = thread;
pf->type = type;
pf->indio_dev = indio_dev;
return pf;
}
void iio_dealloc_pollfunc(struct iio_poll_func *pf)
{
kfree(pf->name);
kfree(pf);
}
static ssize_t iio_trigger_read_current(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
if (indio_dev->trig)
return sprintf(buf, "%s\n", indio_dev->trig->name);
return 0;
}
static ssize_t iio_trigger_write_current(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_trigger *oldtrig = indio_dev->trig;
struct iio_trigger *trig;
int ret;
mutex_lock(&indio_dev->mlock);
if (indio_dev->currentmode == INDIO_BUFFER_TRIGGERED) {
mutex_unlock(&indio_dev->mlock);
return -EBUSY;
}
mutex_unlock(&indio_dev->mlock);
trig = iio_trigger_find_by_name(buf, len);
if (oldtrig == trig)
return len;
if (trig && indio_dev->info->validate_trigger) {
ret = indio_dev->info->validate_trigger(indio_dev, trig);
if (ret)
return ret;
}
if (trig && trig->ops && trig->ops->validate_device) {
ret = trig->ops->validate_device(trig, indio_dev);
if (ret)
return ret;
}
indio_dev->trig = trig;
if (oldtrig)
iio_trigger_put(oldtrig);
if (indio_dev->trig)
iio_trigger_get(indio_dev->trig);
return len;
}
static void iio_trig_release(struct device *device)
{
struct iio_trigger *trig = to_iio_trigger(device);
int i;
if (trig->subirq_base) {
for (i = 0; i < CONFIG_IIO_CONSUMERS_PER_TRIGGER; i++) {
irq_modify_status(trig->subirq_base + i,
IRQ_NOAUTOEN,
IRQ_NOREQUEST | IRQ_NOPROBE);
irq_set_chip(trig->subirq_base + i,
NULL);
irq_set_handler(trig->subirq_base + i,
NULL);
}
irq_free_descs(trig->subirq_base,
CONFIG_IIO_CONSUMERS_PER_TRIGGER);
}
kfree(trig->name);
kfree(trig);
}
static void iio_trig_subirqmask(struct irq_data *d)
{
struct irq_chip *chip = irq_data_get_irq_chip(d);
struct iio_trigger *trig
= container_of(chip,
struct iio_trigger, subirq_chip);
trig->subirqs[d->irq - trig->subirq_base].enabled = false;
}
static void iio_trig_subirqunmask(struct irq_data *d)
{
struct irq_chip *chip = irq_data_get_irq_chip(d);
struct iio_trigger *trig
= container_of(chip,
struct iio_trigger, subirq_chip);
trig->subirqs[d->irq - trig->subirq_base].enabled = true;
}
static struct iio_trigger *viio_trigger_alloc(const char *fmt, va_list vargs)
{
struct iio_trigger *trig;
trig = kzalloc(sizeof *trig, GFP_KERNEL);
if (trig) {
int i;
trig->dev.type = &iio_trig_type;
trig->dev.bus = &iio_bus_type;
device_initialize(&trig->dev);
mutex_init(&trig->pool_lock);
trig->subirq_base
= irq_alloc_descs(-1, 0,
CONFIG_IIO_CONSUMERS_PER_TRIGGER,
0);
if (trig->subirq_base < 0) {
kfree(trig);
return NULL;
}
trig->name = kvasprintf(GFP_KERNEL, fmt, vargs);
if (trig->name == NULL) {
irq_free_descs(trig->subirq_base,
CONFIG_IIO_CONSUMERS_PER_TRIGGER);
kfree(trig);
return NULL;
}
trig->subirq_chip.name = trig->name;
trig->subirq_chip.irq_mask = &iio_trig_subirqmask;
trig->subirq_chip.irq_unmask = &iio_trig_subirqunmask;
for (i = 0; i < CONFIG_IIO_CONSUMERS_PER_TRIGGER; i++) {
irq_set_chip(trig->subirq_base + i,
&trig->subirq_chip);
irq_set_handler(trig->subirq_base + i,
&handle_simple_irq);
irq_modify_status(trig->subirq_base + i,
IRQ_NOREQUEST | IRQ_NOAUTOEN,
IRQ_NOPROBE);
}
get_device(&trig->dev);
}
return trig;
}
struct iio_trigger *iio_trigger_alloc(const char *fmt, ...)
{
struct iio_trigger *trig;
va_list vargs;
va_start(vargs, fmt);
trig = viio_trigger_alloc(fmt, vargs);
va_end(vargs);
return trig;
}
void iio_trigger_free(struct iio_trigger *trig)
{
if (trig)
put_device(&trig->dev);
}
static void devm_iio_trigger_release(struct device *dev, void *res)
{
iio_trigger_free(*(struct iio_trigger **)res);
}
static int devm_iio_trigger_match(struct device *dev, void *res, void *data)
{
struct iio_trigger **r = res;
if (!r || !*r) {
WARN_ON(!r || !*r);
return 0;
}
return *r == data;
}
struct iio_trigger *devm_iio_trigger_alloc(struct device *dev,
const char *fmt, ...)
{
struct iio_trigger **ptr, *trig;
va_list vargs;
ptr = devres_alloc(devm_iio_trigger_release, sizeof(*ptr),
GFP_KERNEL);
if (!ptr)
return NULL;
va_start(vargs, fmt);
trig = viio_trigger_alloc(fmt, vargs);
va_end(vargs);
if (trig) {
*ptr = trig;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return trig;
}
void devm_iio_trigger_free(struct device *dev, struct iio_trigger *iio_trig)
{
int rc;
rc = devres_release(dev, devm_iio_trigger_release,
devm_iio_trigger_match, iio_trig);
WARN_ON(rc);
}
void iio_device_register_trigger_consumer(struct iio_dev *indio_dev)
{
indio_dev->groups[indio_dev->groupcounter++] =
&iio_trigger_consumer_attr_group;
}
void iio_device_unregister_trigger_consumer(struct iio_dev *indio_dev)
{
if (indio_dev->trig)
iio_trigger_put(indio_dev->trig);
}
int iio_triggered_buffer_postenable(struct iio_dev *indio_dev)
{
return iio_trigger_attach_poll_func(indio_dev->trig,
indio_dev->pollfunc);
}
int iio_triggered_buffer_predisable(struct iio_dev *indio_dev)
{
return iio_trigger_detach_poll_func(indio_dev->trig,
indio_dev->pollfunc);
}
