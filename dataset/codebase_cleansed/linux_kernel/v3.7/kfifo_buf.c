static inline int __iio_allocate_kfifo(struct iio_kfifo *buf,
int bytes_per_datum, int length)
{
if ((length == 0) || (bytes_per_datum == 0))
return -EINVAL;
__iio_update_buffer(&buf->buffer, bytes_per_datum, length);
return __kfifo_alloc((struct __kfifo *)&buf->kf, length,
bytes_per_datum, GFP_KERNEL);
}
static int iio_request_update_kfifo(struct iio_buffer *r)
{
int ret = 0;
struct iio_kfifo *buf = iio_to_kfifo(r);
if (!buf->update_needed)
goto error_ret;
kfifo_free(&buf->kf);
ret = __iio_allocate_kfifo(buf, buf->buffer.bytes_per_datum,
buf->buffer.length);
r->stufftoread = false;
error_ret:
return ret;
}
static int iio_get_length_kfifo(struct iio_buffer *r)
{
return r->length;
}
static int iio_get_bytes_per_datum_kfifo(struct iio_buffer *r)
{
return r->bytes_per_datum;
}
static int iio_mark_update_needed_kfifo(struct iio_buffer *r)
{
struct iio_kfifo *kf = iio_to_kfifo(r);
kf->update_needed = true;
return 0;
}
static int iio_set_bytes_per_datum_kfifo(struct iio_buffer *r, size_t bpd)
{
if (r->bytes_per_datum != bpd) {
r->bytes_per_datum = bpd;
iio_mark_update_needed_kfifo(r);
}
return 0;
}
static int iio_set_length_kfifo(struct iio_buffer *r, int length)
{
if (length < 2)
length = 2;
if (r->length != length) {
r->length = length;
iio_mark_update_needed_kfifo(r);
}
return 0;
}
static int iio_store_to_kfifo(struct iio_buffer *r,
u8 *data)
{
int ret;
struct iio_kfifo *kf = iio_to_kfifo(r);
ret = kfifo_in(&kf->kf, data, 1);
if (ret != 1)
return -EBUSY;
r->stufftoread = true;
wake_up_interruptible(&r->pollq);
return 0;
}
static int iio_read_first_n_kfifo(struct iio_buffer *r,
size_t n, char __user *buf)
{
int ret, copied;
struct iio_kfifo *kf = iio_to_kfifo(r);
if (n < r->bytes_per_datum || r->bytes_per_datum == 0)
return -EINVAL;
ret = kfifo_to_user(&kf->kf, buf, n, &copied);
if (ret < 0)
return ret;
if (kfifo_is_empty(&kf->kf))
r->stufftoread = false;
if (!kfifo_is_empty(&kf->kf))
r->stufftoread = true;
return copied;
}
struct iio_buffer *iio_kfifo_allocate(struct iio_dev *indio_dev)
{
struct iio_kfifo *kf;
kf = kzalloc(sizeof *kf, GFP_KERNEL);
if (!kf)
return NULL;
kf->update_needed = true;
iio_buffer_init(&kf->buffer);
kf->buffer.attrs = &iio_kfifo_attribute_group;
kf->buffer.access = &kfifo_access_funcs;
kf->buffer.length = 2;
return &kf->buffer;
}
void iio_kfifo_free(struct iio_buffer *r)
{
kfree(iio_to_kfifo(r));
}
