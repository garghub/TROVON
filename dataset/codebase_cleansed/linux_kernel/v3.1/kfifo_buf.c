static inline int __iio_allocate_kfifo(struct iio_kfifo *buf,
int bytes_per_datum, int length)
{
if ((length == 0) || (bytes_per_datum == 0))
return -EINVAL;
__iio_update_ring_buffer(&buf->ring, bytes_per_datum, length);
return kfifo_alloc(&buf->kf, bytes_per_datum*length, GFP_KERNEL);
}
static int iio_request_update_kfifo(struct iio_ring_buffer *r)
{
int ret = 0;
struct iio_kfifo *buf = iio_to_kfifo(r);
mutex_lock(&buf->use_lock);
if (!buf->update_needed)
goto error_ret;
if (buf->use_count) {
ret = -EAGAIN;
goto error_ret;
}
kfifo_free(&buf->kf);
ret = __iio_allocate_kfifo(buf, buf->ring.bytes_per_datum,
buf->ring.length);
error_ret:
mutex_unlock(&buf->use_lock);
return ret;
}
static void iio_mark_kfifo_in_use(struct iio_ring_buffer *r)
{
struct iio_kfifo *buf = iio_to_kfifo(r);
mutex_lock(&buf->use_lock);
buf->use_count++;
mutex_unlock(&buf->use_lock);
}
static void iio_unmark_kfifo_in_use(struct iio_ring_buffer *r)
{
struct iio_kfifo *buf = iio_to_kfifo(r);
mutex_lock(&buf->use_lock);
buf->use_count--;
mutex_unlock(&buf->use_lock);
}
static int iio_get_length_kfifo(struct iio_ring_buffer *r)
{
return r->length;
}
static inline void __iio_init_kfifo(struct iio_kfifo *kf)
{
mutex_init(&kf->use_lock);
}
static void iio_kfifo_release(struct device *dev)
{
struct iio_ring_buffer *r = to_iio_ring_buffer(dev);
struct iio_kfifo *kf = iio_to_kfifo(r);
kfifo_free(&kf->kf);
kfree(kf);
}
struct iio_ring_buffer *iio_kfifo_allocate(struct iio_dev *indio_dev)
{
struct iio_kfifo *kf;
kf = kzalloc(sizeof *kf, GFP_KERNEL);
if (!kf)
return NULL;
kf->update_needed = true;
iio_ring_buffer_init(&kf->ring, indio_dev);
__iio_init_kfifo(kf);
kf->ring.dev.type = &iio_kfifo_type;
kf->ring.dev.parent = &indio_dev->dev;
dev_set_drvdata(&kf->ring.dev, (void *)&(kf->ring));
return &kf->ring;
}
static int iio_get_bytes_per_datum_kfifo(struct iio_ring_buffer *r)
{
return r->bytes_per_datum;
}
static int iio_set_bytes_per_datum_kfifo(struct iio_ring_buffer *r, size_t bpd)
{
if (r->bytes_per_datum != bpd) {
r->bytes_per_datum = bpd;
if (r->access->mark_param_change)
r->access->mark_param_change(r);
}
return 0;
}
static int iio_mark_update_needed_kfifo(struct iio_ring_buffer *r)
{
struct iio_kfifo *kf = iio_to_kfifo(r);
kf->update_needed = true;
return 0;
}
static int iio_set_length_kfifo(struct iio_ring_buffer *r, int length)
{
if (r->length != length) {
r->length = length;
if (r->access->mark_param_change)
r->access->mark_param_change(r);
}
return 0;
}
void iio_kfifo_free(struct iio_ring_buffer *r)
{
if (r)
iio_put_ring_buffer(r);
}
static int iio_store_to_kfifo(struct iio_ring_buffer *r,
u8 *data,
s64 timestamp)
{
int ret;
struct iio_kfifo *kf = iio_to_kfifo(r);
u8 *datal = kmalloc(r->bytes_per_datum, GFP_KERNEL);
memcpy(datal, data, r->bytes_per_datum - sizeof(timestamp));
memcpy(datal + r->bytes_per_datum - sizeof(timestamp),
&timestamp, sizeof(timestamp));
ret = kfifo_in(&kf->kf, data, r->bytes_per_datum);
if (ret != r->bytes_per_datum) {
kfree(datal);
return -EBUSY;
}
kfree(datal);
return 0;
}
static int iio_read_first_n_kfifo(struct iio_ring_buffer *r,
size_t n, char __user *buf)
{
int ret, copied;
struct iio_kfifo *kf = iio_to_kfifo(r);
ret = kfifo_to_user(&kf->kf, buf, r->bytes_per_datum*n, &copied);
return copied;
}
