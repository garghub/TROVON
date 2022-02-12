static int st_sensors_new_samples_available(struct iio_dev *indio_dev,
struct st_sensor_data *sdata)
{
u8 status;
int ret;
if (!sdata->sensor_settings->drdy_irq.addr_stat_drdy)
return -EINVAL;
if (!indio_dev->active_scan_mask)
return 0;
ret = sdata->tf->read_byte(&sdata->tb, sdata->dev,
sdata->sensor_settings->drdy_irq.addr_stat_drdy,
&status);
if (ret < 0) {
dev_err(sdata->dev,
"error checking samples available\n");
return ret;
}
status &= 0x07;
if (status & (u8)indio_dev->active_scan_mask[0])
return 1;
return 0;
}
static irqreturn_t st_sensors_irq_handler(int irq, void *p)
{
struct iio_trigger *trig = p;
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct st_sensor_data *sdata = iio_priv(indio_dev);
sdata->hw_timestamp = iio_get_time_ns(indio_dev);
return IRQ_WAKE_THREAD;
}
static irqreturn_t st_sensors_irq_thread(int irq, void *p)
{
struct iio_trigger *trig = p;
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct st_sensor_data *sdata = iio_priv(indio_dev);
if (sdata->hw_irq_trigger &&
st_sensors_new_samples_available(indio_dev, sdata)) {
iio_trigger_poll_chained(p);
} else {
dev_dbg(sdata->dev, "spurious IRQ\n");
return IRQ_NONE;
}
if (!sdata->edge_irq)
return IRQ_HANDLED;
while (sdata->hw_irq_trigger &&
st_sensors_new_samples_available(indio_dev, sdata)) {
dev_dbg(sdata->dev, "more samples came in during polling\n");
sdata->hw_timestamp = iio_get_time_ns(indio_dev);
iio_trigger_poll_chained(p);
}
return IRQ_HANDLED;
}
int st_sensors_allocate_trigger(struct iio_dev *indio_dev,
const struct iio_trigger_ops *trigger_ops)
{
int err, irq;
struct st_sensor_data *sdata = iio_priv(indio_dev);
unsigned long irq_trig;
sdata->trig = iio_trigger_alloc("%s-trigger", indio_dev->name);
if (sdata->trig == NULL) {
dev_err(&indio_dev->dev, "failed to allocate iio trigger.\n");
return -ENOMEM;
}
iio_trigger_set_drvdata(sdata->trig, indio_dev);
sdata->trig->ops = trigger_ops;
sdata->trig->dev.parent = sdata->dev;
irq = sdata->get_irq_data_ready(indio_dev);
irq_trig = irqd_get_trigger_type(irq_get_irq_data(irq));
switch(irq_trig) {
case IRQF_TRIGGER_FALLING:
case IRQF_TRIGGER_LOW:
if (!sdata->sensor_settings->drdy_irq.addr_ihl) {
dev_err(&indio_dev->dev,
"falling/low specified for IRQ "
"but hardware only support rising/high: "
"will request rising/high\n");
if (irq_trig == IRQF_TRIGGER_FALLING)
irq_trig = IRQF_TRIGGER_RISING;
if (irq_trig == IRQF_TRIGGER_LOW)
irq_trig = IRQF_TRIGGER_HIGH;
} else {
err = st_sensors_write_data_with_mask(indio_dev,
sdata->sensor_settings->drdy_irq.addr_ihl,
sdata->sensor_settings->drdy_irq.mask_ihl, 1);
if (err < 0)
goto iio_trigger_free;
dev_info(&indio_dev->dev,
"interrupts on the falling edge or "
"active low level\n");
}
break;
case IRQF_TRIGGER_RISING:
dev_info(&indio_dev->dev,
"interrupts on the rising edge\n");
break;
case IRQF_TRIGGER_HIGH:
dev_info(&indio_dev->dev,
"interrupts active high level\n");
break;
default:
dev_err(&indio_dev->dev,
"unsupported IRQ trigger specified (%lx), enforce "
"rising edge\n", irq_trig);
irq_trig = IRQF_TRIGGER_RISING;
}
if (irq_trig == IRQF_TRIGGER_FALLING ||
irq_trig == IRQF_TRIGGER_RISING)
sdata->edge_irq = true;
else
irq_trig |= IRQF_ONESHOT;
if (sdata->int_pin_open_drain &&
sdata->sensor_settings->drdy_irq.addr_stat_drdy)
irq_trig |= IRQF_SHARED;
err = request_threaded_irq(sdata->get_irq_data_ready(indio_dev),
st_sensors_irq_handler,
st_sensors_irq_thread,
irq_trig,
sdata->trig->name,
sdata->trig);
if (err) {
dev_err(&indio_dev->dev, "failed to request trigger IRQ.\n");
goto iio_trigger_free;
}
err = iio_trigger_register(sdata->trig);
if (err < 0) {
dev_err(&indio_dev->dev, "failed to register iio trigger.\n");
goto iio_trigger_register_error;
}
indio_dev->trig = iio_trigger_get(sdata->trig);
return 0;
iio_trigger_register_error:
free_irq(sdata->get_irq_data_ready(indio_dev), sdata->trig);
iio_trigger_free:
iio_trigger_free(sdata->trig);
return err;
}
void st_sensors_deallocate_trigger(struct iio_dev *indio_dev)
{
struct st_sensor_data *sdata = iio_priv(indio_dev);
iio_trigger_unregister(sdata->trig);
free_irq(sdata->get_irq_data_ready(indio_dev), sdata->trig);
iio_trigger_free(sdata->trig);
}
int st_sensors_validate_device(struct iio_trigger *trig,
struct iio_dev *indio_dev)
{
struct iio_dev *indio = iio_trigger_get_drvdata(trig);
if (indio != indio_dev)
return -EINVAL;
return 0;
}
