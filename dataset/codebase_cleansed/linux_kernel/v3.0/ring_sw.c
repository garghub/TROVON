static inline int __iio_allocate_sw_ring_buffer(struct iio_sw_ring_buffer *ring,
int bytes_per_datum, int length)
{
if ((length == 0) || (bytes_per_datum == 0))
return -EINVAL;
__iio_update_ring_buffer(&ring->buf, bytes_per_datum, length);
ring->data = kmalloc(length*ring->buf.bytes_per_datum, GFP_ATOMIC);
ring->read_p = NULL;
ring->write_p = NULL;
ring->last_written_p = NULL;
ring->half_p = NULL;
return ring->data ? 0 : -ENOMEM;
}
static inline void __iio_init_sw_ring_buffer(struct iio_sw_ring_buffer *ring)
{
spin_lock_init(&ring->use_lock);
}
static inline void __iio_free_sw_ring_buffer(struct iio_sw_ring_buffer *ring)
{
kfree(ring->data);
}
static void iio_mark_sw_rb_in_use(struct iio_ring_buffer *r)
{
struct iio_sw_ring_buffer *ring = iio_to_sw_ring(r);
spin_lock(&ring->use_lock);
ring->use_count++;
spin_unlock(&ring->use_lock);
}
static void iio_unmark_sw_rb_in_use(struct iio_ring_buffer *r)
{
struct iio_sw_ring_buffer *ring = iio_to_sw_ring(r);
spin_lock(&ring->use_lock);
ring->use_count--;
spin_unlock(&ring->use_lock);
}
static int iio_store_to_sw_ring(struct iio_sw_ring_buffer *ring,
unsigned char *data, s64 timestamp)
{
int ret = 0;
unsigned char *temp_ptr, *change_test_ptr;
if (unlikely(ring->write_p == NULL)) {
ring->write_p = ring->data;
ring->half_p = ring->data - ring->buf.length*ring->buf.bytes_per_datum/2;
}
memcpy(ring->write_p, data, ring->buf.bytes_per_datum);
barrier();
ring->last_written_p = ring->write_p;
barrier();
temp_ptr = ring->write_p + ring->buf.bytes_per_datum;
if (temp_ptr == ring->data + ring->buf.length*ring->buf.bytes_per_datum)
temp_ptr = ring->data;
ring->write_p = temp_ptr;
if (ring->read_p == NULL)
ring->read_p = ring->data;
else if (ring->write_p == ring->read_p) {
change_test_ptr = ring->read_p;
temp_ptr = change_test_ptr + ring->buf.bytes_per_datum;
if (temp_ptr
== ring->data + ring->buf.length*ring->buf.bytes_per_datum) {
temp_ptr = ring->data;
}
if (change_test_ptr == ring->read_p)
ring->read_p = temp_ptr;
}
ring->half_p += ring->buf.bytes_per_datum;
if (ring->half_p == ring->data + ring->buf.length*ring->buf.bytes_per_datum)
ring->half_p = ring->data;
if (ring->half_p == ring->read_p) {
ring->buf.stufftoread = true;
wake_up_interruptible(&ring->buf.pollq);
}
return ret;
}
static int iio_read_first_n_sw_rb(struct iio_ring_buffer *r,
size_t n, char __user *buf)
{
struct iio_sw_ring_buffer *ring = iio_to_sw_ring(r);
u8 *initial_read_p, *initial_write_p, *current_read_p, *end_read_p;
u8 *data;
int ret, max_copied, bytes_to_rip, dead_offset;
if (n % ring->buf.bytes_per_datum) {
ret = -EINVAL;
printk(KERN_INFO "Ring buffer read request not whole number of"
"samples: Request bytes %zd, Current bytes per datum %d\n",
n, ring->buf.bytes_per_datum);
goto error_ret;
}
bytes_to_rip = min((size_t)(ring->buf.bytes_per_datum*ring->buf.length),
n);
data = kmalloc(bytes_to_rip, GFP_KERNEL);
if (data == NULL) {
ret = -ENOMEM;
goto error_ret;
}
initial_read_p = ring->read_p;
if (unlikely(initial_read_p == NULL)) {
ret = 0;
goto error_free_data_cpy;
}
initial_write_p = ring->write_p;
while ((initial_read_p != ring->read_p)
|| (initial_write_p != ring->write_p)) {
initial_read_p = ring->read_p;
initial_write_p = ring->write_p;
}
if (initial_write_p == initial_read_p) {
ret = 0;
goto error_free_data_cpy;
}
if (initial_write_p >= initial_read_p + bytes_to_rip) {
max_copied = bytes_to_rip;
memcpy(data, initial_read_p, max_copied);
end_read_p = initial_read_p + max_copied;
} else if (initial_write_p > initial_read_p) {
max_copied = initial_write_p - initial_read_p;
memcpy(data, initial_read_p, max_copied);
end_read_p = initial_write_p;
} else {
max_copied = ring->data
+ ring->buf.length*ring->buf.bytes_per_datum - initial_read_p;
memcpy(data, initial_read_p, max_copied);
if (max_copied == bytes_to_rip)
end_read_p = ring->data;
else if (initial_write_p
> ring->data + bytes_to_rip - max_copied) {
memcpy(data + max_copied, ring->data,
bytes_to_rip - max_copied);
max_copied = bytes_to_rip;
end_read_p = ring->data + (bytes_to_rip - max_copied);
} else {
memcpy(data + max_copied, ring->data,
initial_write_p - ring->data);
max_copied += initial_write_p - ring->data;
end_read_p = initial_write_p;
}
}
current_read_p = ring->read_p;
if (initial_read_p <= current_read_p)
dead_offset = current_read_p - initial_read_p;
else
dead_offset = ring->buf.length*ring->buf.bytes_per_datum
- (initial_read_p - current_read_p);
if (max_copied - dead_offset < 0) {
ret = 0;
goto error_free_data_cpy;
}
while (ring->read_p != end_read_p)
ring->read_p = end_read_p;
ret = max_copied - dead_offset;
if (copy_to_user(buf, data + dead_offset, ret)) {
ret = -EFAULT;
goto error_free_data_cpy;
}
if (bytes_to_rip >= ring->buf.length*ring->buf.bytes_per_datum/2)
ring->buf.stufftoread = 0;
error_free_data_cpy:
kfree(data);
error_ret:
return ret;
}
static int iio_store_to_sw_rb(struct iio_ring_buffer *r,
u8 *data,
s64 timestamp)
{
struct iio_sw_ring_buffer *ring = iio_to_sw_ring(r);
return iio_store_to_sw_ring(ring, data, timestamp);
}
static int iio_read_last_from_sw_ring(struct iio_sw_ring_buffer *ring,
unsigned char *data)
{
unsigned char *last_written_p_copy;
iio_mark_sw_rb_in_use(&ring->buf);
again:
barrier();
last_written_p_copy = ring->last_written_p;
barrier();
if (last_written_p_copy == NULL)
return -EAGAIN;
memcpy(data, last_written_p_copy, ring->buf.bytes_per_datum);
if (unlikely(ring->last_written_p != last_written_p_copy))
goto again;
iio_unmark_sw_rb_in_use(&ring->buf);
return 0;
}
static int iio_read_last_from_sw_rb(struct iio_ring_buffer *r,
unsigned char *data)
{
return iio_read_last_from_sw_ring(iio_to_sw_ring(r), data);
}
static int iio_request_update_sw_rb(struct iio_ring_buffer *r)
{
int ret = 0;
struct iio_sw_ring_buffer *ring = iio_to_sw_ring(r);
r->stufftoread = false;
spin_lock(&ring->use_lock);
if (!ring->update_needed)
goto error_ret;
if (ring->use_count) {
ret = -EAGAIN;
goto error_ret;
}
__iio_free_sw_ring_buffer(ring);
ret = __iio_allocate_sw_ring_buffer(ring, ring->buf.bytes_per_datum,
ring->buf.length);
error_ret:
spin_unlock(&ring->use_lock);
return ret;
}
static int iio_get_bytes_per_datum_sw_rb(struct iio_ring_buffer *r)
{
struct iio_sw_ring_buffer *ring = iio_to_sw_ring(r);
return ring->buf.bytes_per_datum;
}
static int iio_set_bytes_per_datum_sw_rb(struct iio_ring_buffer *r, size_t bpd)
{
if (r->bytes_per_datum != bpd) {
r->bytes_per_datum = bpd;
if (r->access->mark_param_change)
r->access->mark_param_change(r);
}
return 0;
}
static int iio_get_length_sw_rb(struct iio_ring_buffer *r)
{
return r->length;
}
static int iio_set_length_sw_rb(struct iio_ring_buffer *r, int length)
{
if (r->length != length) {
r->length = length;
if (r->access->mark_param_change)
r->access->mark_param_change(r);
}
return 0;
}
static int iio_mark_update_needed_sw_rb(struct iio_ring_buffer *r)
{
struct iio_sw_ring_buffer *ring = iio_to_sw_ring(r);
ring->update_needed = true;
return 0;
}
static void iio_sw_rb_release(struct device *dev)
{
struct iio_ring_buffer *r = to_iio_ring_buffer(dev);
iio_ring_access_release(&r->dev);
kfree(iio_to_sw_ring(r));
}
struct iio_ring_buffer *iio_sw_rb_allocate(struct iio_dev *indio_dev)
{
struct iio_ring_buffer *buf;
struct iio_sw_ring_buffer *ring;
ring = kzalloc(sizeof *ring, GFP_KERNEL);
if (!ring)
return NULL;
ring->update_needed = true;
buf = &ring->buf;
iio_ring_buffer_init(buf, indio_dev);
__iio_init_sw_ring_buffer(ring);
buf->dev.type = &iio_sw_ring_type;
buf->dev.parent = &indio_dev->dev;
dev_set_drvdata(&buf->dev, (void *)buf);
return buf;
}
void iio_sw_rb_free(struct iio_ring_buffer *r)
{
if (r)
iio_put_ring_buffer(r);
}
