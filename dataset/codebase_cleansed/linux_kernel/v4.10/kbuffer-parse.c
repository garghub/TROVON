static void *zmalloc(size_t size)
{
return calloc(1, size);
}
static int host_is_bigendian(void)
{
unsigned char str[] = { 0x1, 0x2, 0x3, 0x4 };
unsigned int *ptr;
ptr = (unsigned int *)str;
return *ptr == 0x01020304;
}
static int do_swap(struct kbuffer *kbuf)
{
return ((kbuf->flags & KBUFFER_FL_HOST_BIG_ENDIAN) + kbuf->flags) &
ENDIAN_MASK;
}
static unsigned long long __read_8(void *ptr)
{
unsigned long long data = *(unsigned long long *)ptr;
return data;
}
static unsigned long long __read_8_sw(void *ptr)
{
unsigned long long data = *(unsigned long long *)ptr;
unsigned long long swap;
swap = ((data & 0xffULL) << 56) |
((data & (0xffULL << 8)) << 40) |
((data & (0xffULL << 16)) << 24) |
((data & (0xffULL << 24)) << 8) |
((data & (0xffULL << 32)) >> 8) |
((data & (0xffULL << 40)) >> 24) |
((data & (0xffULL << 48)) >> 40) |
((data & (0xffULL << 56)) >> 56);
return swap;
}
static unsigned int __read_4(void *ptr)
{
unsigned int data = *(unsigned int *)ptr;
return data;
}
static unsigned int __read_4_sw(void *ptr)
{
unsigned int data = *(unsigned int *)ptr;
unsigned int swap;
swap = ((data & 0xffULL) << 24) |
((data & (0xffULL << 8)) << 8) |
((data & (0xffULL << 16)) >> 8) |
((data & (0xffULL << 24)) >> 24);
return swap;
}
static unsigned long long read_8(struct kbuffer *kbuf, void *ptr)
{
return kbuf->read_8(ptr);
}
static unsigned int read_4(struct kbuffer *kbuf, void *ptr)
{
return kbuf->read_4(ptr);
}
static unsigned long long __read_long_8(struct kbuffer *kbuf, void *ptr)
{
return kbuf->read_8(ptr);
}
static unsigned long long __read_long_4(struct kbuffer *kbuf, void *ptr)
{
return kbuf->read_4(ptr);
}
static unsigned long long read_long(struct kbuffer *kbuf, void *ptr)
{
return kbuf->read_long(kbuf, ptr);
}
static int calc_index(struct kbuffer *kbuf, void *ptr)
{
return (unsigned long)ptr - (unsigned long)kbuf->data;
}
struct kbuffer *
kbuffer_alloc(enum kbuffer_long_size size, enum kbuffer_endian endian)
{
struct kbuffer *kbuf;
int flags = 0;
switch (size) {
case KBUFFER_LSIZE_4:
break;
case KBUFFER_LSIZE_8:
flags |= KBUFFER_FL_LONG_8;
break;
default:
return NULL;
}
switch (endian) {
case KBUFFER_ENDIAN_LITTLE:
break;
case KBUFFER_ENDIAN_BIG:
flags |= KBUFFER_FL_BIG_ENDIAN;
break;
default:
return NULL;
}
kbuf = zmalloc(sizeof(*kbuf));
if (!kbuf)
return NULL;
kbuf->flags = flags;
if (host_is_bigendian())
kbuf->flags |= KBUFFER_FL_HOST_BIG_ENDIAN;
if (do_swap(kbuf)) {
kbuf->read_8 = __read_8_sw;
kbuf->read_4 = __read_4_sw;
} else {
kbuf->read_8 = __read_8;
kbuf->read_4 = __read_4;
}
if (kbuf->flags & KBUFFER_FL_LONG_8)
kbuf->read_long = __read_long_8;
else
kbuf->read_long = __read_long_4;
kbuf->next_event = __next_event;
return kbuf;
}
void kbuffer_free(struct kbuffer *kbuf)
{
free(kbuf);
}
static unsigned int type4host(struct kbuffer *kbuf,
unsigned int type_len_ts)
{
if (kbuf->flags & KBUFFER_FL_BIG_ENDIAN)
return (type_len_ts >> 29) & 3;
else
return type_len_ts & 3;
}
static unsigned int len4host(struct kbuffer *kbuf,
unsigned int type_len_ts)
{
if (kbuf->flags & KBUFFER_FL_BIG_ENDIAN)
return (type_len_ts >> 27) & 7;
else
return (type_len_ts >> 2) & 7;
}
static unsigned int type_len4host(struct kbuffer *kbuf,
unsigned int type_len_ts)
{
if (kbuf->flags & KBUFFER_FL_BIG_ENDIAN)
return (type_len_ts >> 27) & ((1 << 5) - 1);
else
return type_len_ts & ((1 << 5) - 1);
}
static unsigned int ts4host(struct kbuffer *kbuf,
unsigned int type_len_ts)
{
if (kbuf->flags & KBUFFER_FL_BIG_ENDIAN)
return type_len_ts & ((1 << 27) - 1);
else
return type_len_ts >> 5;
}
static unsigned int old_update_pointers(struct kbuffer *kbuf)
{
unsigned long long extend;
unsigned int type_len_ts;
unsigned int type;
unsigned int len;
unsigned int delta;
unsigned int length;
void *ptr = kbuf->data + kbuf->curr;
type_len_ts = read_4(kbuf, ptr);
ptr += 4;
type = type4host(kbuf, type_len_ts);
len = len4host(kbuf, type_len_ts);
delta = ts4host(kbuf, type_len_ts);
switch (type) {
case OLD_RINGBUF_TYPE_PADDING:
kbuf->next = kbuf->size;
return 0;
case OLD_RINGBUF_TYPE_TIME_EXTEND:
extend = read_4(kbuf, ptr);
extend <<= TS_SHIFT;
extend += delta;
delta = extend;
ptr += 4;
break;
case OLD_RINGBUF_TYPE_TIME_STAMP:
kbuf->curr = kbuf->size;
kbuf->next = kbuf->size;
kbuf->index = kbuf->size;
return -1;
default:
if (len)
length = len * 4;
else {
length = read_4(kbuf, ptr);
length -= 4;
ptr += 4;
}
break;
}
kbuf->timestamp += delta;
kbuf->index = calc_index(kbuf, ptr);
kbuf->next = kbuf->index + length;
return type;
}
static int __old_next_event(struct kbuffer *kbuf)
{
int type;
do {
kbuf->curr = kbuf->next;
if (kbuf->next >= kbuf->size)
return -1;
type = old_update_pointers(kbuf);
} while (type == OLD_RINGBUF_TYPE_TIME_EXTEND || type == OLD_RINGBUF_TYPE_PADDING);
return 0;
}
static unsigned int
translate_data(struct kbuffer *kbuf, void *data, void **rptr,
unsigned long long *delta, int *length)
{
unsigned long long extend;
unsigned int type_len_ts;
unsigned int type_len;
type_len_ts = read_4(kbuf, data);
data += 4;
type_len = type_len4host(kbuf, type_len_ts);
*delta = ts4host(kbuf, type_len_ts);
switch (type_len) {
case KBUFFER_TYPE_PADDING:
*length = read_4(kbuf, data);
break;
case KBUFFER_TYPE_TIME_EXTEND:
extend = read_4(kbuf, data);
data += 4;
extend <<= TS_SHIFT;
extend += *delta;
*delta = extend;
*length = 0;
break;
case KBUFFER_TYPE_TIME_STAMP:
data += 12;
*length = 0;
break;
case 0:
*length = read_4(kbuf, data) - 4;
*length = (*length + 3) & ~3;
data += 4;
break;
default:
*length = type_len * 4;
break;
}
*rptr = data;
return type_len;
}
static unsigned int update_pointers(struct kbuffer *kbuf)
{
unsigned long long delta;
unsigned int type_len;
int length;
void *ptr = kbuf->data + kbuf->curr;
type_len = translate_data(kbuf, ptr, &ptr, &delta, &length);
kbuf->timestamp += delta;
kbuf->index = calc_index(kbuf, ptr);
kbuf->next = kbuf->index + length;
return type_len;
}
void *kbuffer_translate_data(int swap, void *data, unsigned int *size)
{
unsigned long long delta;
struct kbuffer kbuf;
int type_len;
int length;
void *ptr;
if (swap) {
kbuf.read_8 = __read_8_sw;
kbuf.read_4 = __read_4_sw;
kbuf.flags = host_is_bigendian() ? 0 : KBUFFER_FL_BIG_ENDIAN;
} else {
kbuf.read_8 = __read_8;
kbuf.read_4 = __read_4;
kbuf.flags = host_is_bigendian() ? KBUFFER_FL_BIG_ENDIAN: 0;
}
type_len = translate_data(&kbuf, data, &ptr, &delta, &length);
switch (type_len) {
case KBUFFER_TYPE_PADDING:
case KBUFFER_TYPE_TIME_EXTEND:
case KBUFFER_TYPE_TIME_STAMP:
return NULL;
};
*size = length;
return ptr;
}
static int __next_event(struct kbuffer *kbuf)
{
int type;
do {
kbuf->curr = kbuf->next;
if (kbuf->next >= kbuf->size)
return -1;
type = update_pointers(kbuf);
} while (type == KBUFFER_TYPE_TIME_EXTEND || type == KBUFFER_TYPE_PADDING);
return 0;
}
static int next_event(struct kbuffer *kbuf)
{
return kbuf->next_event(kbuf);
}
void *kbuffer_next_event(struct kbuffer *kbuf, unsigned long long *ts)
{
int ret;
if (!kbuf || !kbuf->subbuffer)
return NULL;
ret = next_event(kbuf);
if (ret < 0)
return NULL;
if (ts)
*ts = kbuf->timestamp;
return kbuf->data + kbuf->index;
}
int kbuffer_load_subbuffer(struct kbuffer *kbuf, void *subbuffer)
{
unsigned long long flags;
void *ptr = subbuffer;
if (!kbuf || !subbuffer)
return -1;
kbuf->subbuffer = subbuffer;
kbuf->timestamp = read_8(kbuf, ptr);
ptr += 8;
kbuf->curr = 0;
if (kbuf->flags & KBUFFER_FL_LONG_8)
kbuf->start = 16;
else
kbuf->start = 12;
kbuf->data = subbuffer + kbuf->start;
flags = read_long(kbuf, ptr);
kbuf->size = (unsigned int)flags & COMMIT_MASK;
if (flags & MISSING_EVENTS) {
if (flags & MISSING_STORED) {
ptr = kbuf->data + kbuf->size;
kbuf->lost_events = read_long(kbuf, ptr);
} else
kbuf->lost_events = -1;
} else
kbuf->lost_events = 0;
kbuf->index = 0;
kbuf->next = 0;
next_event(kbuf);
return 0;
}
void *kbuffer_read_event(struct kbuffer *kbuf, unsigned long long *ts)
{
if (!kbuf || !kbuf->subbuffer)
return NULL;
if (kbuf->curr >= kbuf->size)
return NULL;
if (ts)
*ts = kbuf->timestamp;
return kbuf->data + kbuf->index;
}
unsigned long long kbuffer_timestamp(struct kbuffer *kbuf)
{
return kbuf->timestamp;
}
void *kbuffer_read_at_offset(struct kbuffer *kbuf, int offset,
unsigned long long *ts)
{
void *data;
if (offset < kbuf->start)
offset = 0;
else
offset -= kbuf->start;
kbuffer_load_subbuffer(kbuf, kbuf->subbuffer);
data = kbuffer_read_event(kbuf, ts);
while (kbuf->curr < offset) {
data = kbuffer_next_event(kbuf, ts);
if (!data)
break;
}
return data;
}
int kbuffer_subbuffer_size(struct kbuffer *kbuf)
{
return kbuf->size;
}
int kbuffer_curr_index(struct kbuffer *kbuf)
{
return kbuf->curr;
}
int kbuffer_curr_offset(struct kbuffer *kbuf)
{
return kbuf->curr + kbuf->start;
}
int kbuffer_event_size(struct kbuffer *kbuf)
{
return kbuf->next - kbuf->index;
}
int kbuffer_curr_size(struct kbuffer *kbuf)
{
return kbuf->next - kbuf->curr;
}
int kbuffer_missed_events(struct kbuffer *kbuf)
{
if (kbuf->curr)
return 0;
return kbuf->lost_events;
}
void kbuffer_set_old_format(struct kbuffer *kbuf)
{
kbuf->flags |= KBUFFER_FL_OLD_FORMAT;
kbuf->next_event = __old_next_event;
}
int kbuffer_start_of_data(struct kbuffer *kbuf)
{
return kbuf->start;
}
