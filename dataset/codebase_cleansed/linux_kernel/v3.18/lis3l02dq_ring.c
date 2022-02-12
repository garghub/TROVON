static inline u16 combine_8_to_16(u8 lower, u8 upper)
{
u16 _lower = lower;
u16 _upper = upper;
return _lower | (_upper << 8);
}
irqreturn_t lis3l02dq_data_rdy_trig_poll(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct lis3l02dq_state *st = iio_priv(indio_dev);
if (st->trigger_on) {
iio_trigger_poll(st->trig);
return IRQ_HANDLED;
}
return IRQ_WAKE_THREAD;
}
static int lis3l02dq_read_all(struct iio_dev *indio_dev, u8 *rx_array)
{
struct lis3l02dq_state *st = iio_priv(indio_dev);
struct spi_transfer *xfers;
struct spi_message msg;
int ret, i, j = 0;
xfers = kcalloc(bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength) * 2,
sizeof(*xfers), GFP_KERNEL);
if (!xfers)
return -ENOMEM;
mutex_lock(&st->buf_lock);
for (i = 0; i < ARRAY_SIZE(read_all_tx_array)/4; i++)
if (test_bit(i, indio_dev->active_scan_mask)) {
xfers[j].tx_buf = st->tx + 2*j;
st->tx[2*j] = read_all_tx_array[i*4];
st->tx[2*j + 1] = 0;
if (rx_array)
xfers[j].rx_buf = rx_array + j*2;
xfers[j].bits_per_word = 8;
xfers[j].len = 2;
xfers[j].cs_change = 1;
j++;
xfers[j].tx_buf = st->tx + 2*j;
st->tx[2*j] = read_all_tx_array[i*4 + 2];
st->tx[2*j + 1] = 0;
if (rx_array)
xfers[j].rx_buf = rx_array + j*2;
xfers[j].bits_per_word = 8;
xfers[j].len = 2;
xfers[j].cs_change = 1;
j++;
}
spi_message_init(&msg);
for (j = 0; j < bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength) * 2; j++)
spi_message_add_tail(&xfers[j], &msg);
ret = spi_sync(st->us, &msg);
mutex_unlock(&st->buf_lock);
kfree(xfers);
return ret;
}
static int lis3l02dq_get_buffer_element(struct iio_dev *indio_dev,
u8 *buf)
{
int ret, i;
u8 *rx_array;
s16 *data = (s16 *)buf;
int scan_count = bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength);
rx_array = kzalloc(4 * scan_count, GFP_KERNEL);
if (rx_array == NULL)
return -ENOMEM;
ret = lis3l02dq_read_all(indio_dev, rx_array);
if (ret < 0) {
kfree(rx_array);
return ret;
}
for (i = 0; i < scan_count; i++)
data[i] = combine_8_to_16(rx_array[i*4+1],
rx_array[i*4+3]);
kfree(rx_array);
return i*sizeof(data[0]);
}
static irqreturn_t lis3l02dq_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
int len = 0;
char *data;
data = kmalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (data == NULL)
goto done;
if (!bitmap_empty(indio_dev->active_scan_mask, indio_dev->masklength))
len = lis3l02dq_get_buffer_element(indio_dev, data);
iio_push_to_buffers_with_timestamp(indio_dev, data, pf->timestamp);
kfree(data);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int
__lis3l02dq_write_data_ready_config(struct iio_dev *indio_dev, bool state)
{
int ret;
u8 valold;
bool currentlyset;
struct lis3l02dq_state *st = iio_priv(indio_dev);
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
&valold);
if (ret)
goto error_ret;
currentlyset
= valold & LIS3L02DQ_REG_CTRL_2_ENABLE_DATA_READY_GENERATION;
if (!state && currentlyset) {
valold &= ~LIS3L02DQ_REG_CTRL_2_ENABLE_DATA_READY_GENERATION;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
valold);
if (ret)
goto error_ret;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
valold);
if (ret)
goto error_ret;
st->trigger_on = false;
} else if (state && !currentlyset) {
ret = lis3l02dq_disable_all_events(indio_dev);
if (ret < 0)
goto error_ret;
valold = ret |
LIS3L02DQ_REG_CTRL_2_ENABLE_DATA_READY_GENERATION;
st->trigger_on = true;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_2_ADDR,
valold);
if (ret)
goto error_ret;
}
return 0;
error_ret:
return ret;
}
static int lis3l02dq_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
int ret = 0;
u8 t;
__lis3l02dq_write_data_ready_config(indio_dev, state);
if (!state) {
ret = lis3l02dq_read_all(indio_dev, NULL);
}
lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_WAKE_UP_SRC_ADDR,
&t);
return ret;
}
static int lis3l02dq_trig_try_reen(struct iio_trigger *trig)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct lis3l02dq_state *st = iio_priv(indio_dev);
int i;
for (i = 0; i < 5; i++)
if (gpio_get_value(st->gpio))
lis3l02dq_read_all(indio_dev, NULL);
else
break;
if (i == 5)
pr_info("Failed to clear the interrupt for lis3l02dq\n");
return 0;
}
int lis3l02dq_probe_trigger(struct iio_dev *indio_dev)
{
int ret;
struct lis3l02dq_state *st = iio_priv(indio_dev);
st->trig = iio_trigger_alloc("lis3l02dq-dev%d", indio_dev->id);
if (!st->trig) {
ret = -ENOMEM;
goto error_ret;
}
st->trig->dev.parent = &st->us->dev;
st->trig->ops = &lis3l02dq_trigger_ops;
iio_trigger_set_drvdata(st->trig, indio_dev);
ret = iio_trigger_register(st->trig);
if (ret)
goto error_free_trig;
return 0;
error_free_trig:
iio_trigger_free(st->trig);
error_ret:
return ret;
}
void lis3l02dq_remove_trigger(struct iio_dev *indio_dev)
{
struct lis3l02dq_state *st = iio_priv(indio_dev);
iio_trigger_unregister(st->trig);
iio_trigger_free(st->trig);
}
void lis3l02dq_unconfigure_buffer(struct iio_dev *indio_dev)
{
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_kfifo_free(indio_dev->buffer);
}
static int lis3l02dq_buffer_postenable(struct iio_dev *indio_dev)
{
u8 t;
int ret;
bool oneenabled = false;
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
&t);
if (ret)
goto error_ret;
if (test_bit(0, indio_dev->active_scan_mask)) {
t |= LIS3L02DQ_REG_CTRL_1_AXES_X_ENABLE;
oneenabled = true;
} else
t &= ~LIS3L02DQ_REG_CTRL_1_AXES_X_ENABLE;
if (test_bit(1, indio_dev->active_scan_mask)) {
t |= LIS3L02DQ_REG_CTRL_1_AXES_Y_ENABLE;
oneenabled = true;
} else
t &= ~LIS3L02DQ_REG_CTRL_1_AXES_Y_ENABLE;
if (test_bit(2, indio_dev->active_scan_mask)) {
t |= LIS3L02DQ_REG_CTRL_1_AXES_Z_ENABLE;
oneenabled = true;
} else
t &= ~LIS3L02DQ_REG_CTRL_1_AXES_Z_ENABLE;
if (!oneenabled)
return -EINVAL;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
t);
if (ret)
goto error_ret;
return iio_triggered_buffer_postenable(indio_dev);
error_ret:
return ret;
}
static int lis3l02dq_buffer_predisable(struct iio_dev *indio_dev)
{
u8 t;
int ret;
ret = iio_triggered_buffer_predisable(indio_dev);
if (ret)
goto error_ret;
ret = lis3l02dq_spi_read_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
&t);
if (ret)
goto error_ret;
t |= LIS3L02DQ_REG_CTRL_1_AXES_X_ENABLE |
LIS3L02DQ_REG_CTRL_1_AXES_Y_ENABLE |
LIS3L02DQ_REG_CTRL_1_AXES_Z_ENABLE;
ret = lis3l02dq_spi_write_reg_8(indio_dev,
LIS3L02DQ_REG_CTRL_1_ADDR,
t);
error_ret:
return ret;
}
int lis3l02dq_configure_buffer(struct iio_dev *indio_dev)
{
int ret;
struct iio_buffer *buffer;
buffer = iio_kfifo_allocate(indio_dev);
if (!buffer)
return -ENOMEM;
iio_device_attach_buffer(indio_dev, buffer);
buffer->scan_timestamp = true;
indio_dev->setup_ops = &lis3l02dq_buffer_setup_ops;
indio_dev->pollfunc = iio_alloc_pollfunc(&iio_pollfunc_store_time,
&lis3l02dq_trigger_handler,
0,
indio_dev,
"lis3l02dq_consumer%d",
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_iio_sw_rb_free;
}
indio_dev->modes |= INDIO_BUFFER_TRIGGERED;
return 0;
error_iio_sw_rb_free:
iio_kfifo_free(indio_dev->buffer);
return ret;
}
