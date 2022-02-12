tvbuff_t *
tvb_new(const struct tvb_ops *ops)
{
tvbuff_t *tvb;
gsize size = ops->tvb_size ? ops->tvb_size : sizeof(*tvb);
g_assert(size >= sizeof(*tvb));
tvb = (tvbuff_t *) g_slice_alloc(size);
tvb->next = NULL;
tvb->ops = ops;
tvb->initialized = FALSE;
tvb->flags = 0;
tvb->length = 0;
tvb->reported_length = 0;
tvb->real_data = NULL;
tvb->raw_offset = -1;
tvb->ds_tvb = NULL;
return tvb;
}
static void
tvb_free_internal(tvbuff_t *tvb)
{
gsize size;
DISSECTOR_ASSERT(tvb);
if (tvb->ops->tvb_free)
tvb->ops->tvb_free(tvb);
size = (tvb->ops->tvb_size) ? tvb->ops->tvb_size : sizeof(*tvb);
g_slice_free1(size, tvb);
}
void
tvb_free(tvbuff_t *tvb)
{
tvb_free_chain(tvb);
}
void
tvb_free_chain(tvbuff_t *tvb)
{
tvbuff_t *next_tvb;
DISSECTOR_ASSERT(tvb);
while (tvb) {
next_tvb=tvb->next;
tvb_free_internal(tvb);
tvb = next_tvb;
}
}
tvbuff_t *
tvb_new_chain(tvbuff_t *parent, tvbuff_t *backing)
{
tvbuff_t *tvb = tvb_new_proxy(backing);
tvb_add_to_chain(parent, tvb);
return tvb;
}
void
tvb_add_to_chain(tvbuff_t *parent, tvbuff_t *child)
{
tvbuff_t *tmp = child;
DISSECTOR_ASSERT(parent);
DISSECTOR_ASSERT(child);
while (child) {
tmp = child;
child = child->next;
tmp->next = parent->next;
parent->next = tmp;
}
}
static inline int
validate_offset(const tvbuff_t *tvb, const guint abs_offset)
{
if (G_LIKELY(abs_offset <= tvb->length))
return 0;
else if (abs_offset <= tvb->reported_length)
return BoundsError;
else if (tvb->flags & TVBUFF_FRAGMENT)
return FragmentBoundsError;
else
return ReportedBoundsError;
}
static int
compute_offset(const tvbuff_t *tvb, const gint offset, guint *offset_ptr)
{
if (offset >= 0) {
if ((guint) offset <= tvb->length) {
*offset_ptr = offset;
} else if ((guint) offset <= tvb->reported_length) {
return BoundsError;
} else if (tvb->flags & TVBUFF_FRAGMENT) {
return FragmentBoundsError;
} else {
return ReportedBoundsError;
}
}
else {
if ((guint) -offset <= tvb->length) {
*offset_ptr = tvb->length + offset;
} else if ((guint) -offset <= tvb->reported_length) {
return BoundsError;
} else if (tvb->flags & TVBUFF_FRAGMENT) {
return FragmentBoundsError;
} else {
return ReportedBoundsError;
}
}
return 0;
}
static int
compute_offset_and_remaining(const tvbuff_t *tvb, const gint offset, guint *offset_ptr, guint *rem_len)
{
int exception;
exception = compute_offset(tvb, offset, offset_ptr);
if (!exception)
*rem_len = tvb->length - *offset_ptr;
return exception;
}
static int
check_offset_length_no_exception(const tvbuff_t *tvb,
const gint offset, gint const length_val,
guint *offset_ptr, guint *length_ptr)
{
guint end_offset;
int exception;
DISSECTOR_ASSERT(offset_ptr);
DISSECTOR_ASSERT(length_ptr);
exception = compute_offset(tvb, offset, offset_ptr);
if (exception)
return exception;
if (length_val < -1) {
return BoundsError;
}
if (length_val == -1)
*length_ptr = tvb->length - *offset_ptr;
else
*length_ptr = length_val;
end_offset = *offset_ptr + *length_ptr;
if (end_offset < *offset_ptr)
return BoundsError;
return validate_offset(tvb, end_offset);
}
static void
check_offset_length(const tvbuff_t *tvb,
const gint offset, gint const length_val,
guint *offset_ptr, guint *length_ptr)
{
int exception;
exception = check_offset_length_no_exception(tvb, offset, length_val, offset_ptr, length_ptr);
if (exception)
THROW(exception);
}
void
tvb_check_offset_length(const tvbuff_t *tvb,
const gint offset, gint const length_val,
guint *offset_ptr, guint *length_ptr)
{
check_offset_length(tvb, offset, length_val, offset_ptr, length_ptr);
}
tvbuff_t *
tvb_new_octet_aligned(tvbuff_t *tvb, guint32 bit_offset, gint32 no_of_bits)
{
tvbuff_t *sub_tvb = NULL;
guint32 byte_offset;
gint32 datalen, i;
guint8 left, right, remaining_bits, *buf;
const guint8 *data;
byte_offset = bit_offset >> 3;
left = bit_offset % 8;
right = 8 - left;
if (no_of_bits == -1) {
datalen = tvb_length_remaining(tvb, byte_offset);
remaining_bits = 0;
} else {
datalen = no_of_bits >> 3;
remaining_bits = no_of_bits % 8;
if (remaining_bits) {
datalen++;
}
}
if ((left == 0) && (remaining_bits == 0)) {
return tvb_new_subset(tvb, byte_offset, datalen, -1);
}
DISSECTOR_ASSERT(datalen>0);
if (tvb_length_remaining(tvb, byte_offset) > datalen) {
data = tvb_get_ptr(tvb, byte_offset, datalen + 1);
buf = (guint8 *)g_malloc(datalen);
for (i = 0; i < datalen; i++)
buf[i] = (data[i] << left) | (data[i+1] >> right);
} else {
data = tvb_get_ptr(tvb, byte_offset, datalen);
buf = (guint8 *)g_malloc(datalen);
for (i = 0; i < (datalen-1); i++)
buf[i] = (data[i] << left) | (data[i+1] >> right);
buf[datalen-1] = data[datalen-1] << left;
}
buf[datalen-1] &= left_aligned_bitmask[remaining_bits];
sub_tvb = tvb_new_child_real_data(tvb, buf, datalen, datalen);
tvb_set_free_cb(sub_tvb, g_free);
return sub_tvb;
}
static tvbuff_t *
tvb_generic_clone_offset_len(tvbuff_t *tvb, guint offset, guint len)
{
tvbuff_t *cloned_tvb;
guint8 *data = (guint8 *) g_malloc(len);
tvb_memcpy(tvb, data, offset, len);
cloned_tvb = tvb_new_real_data(data, len, len);
tvb_set_free_cb(cloned_tvb, g_free);
return cloned_tvb;
}
tvbuff_t *
tvb_clone_offset_len(tvbuff_t *tvb, guint offset, guint len)
{
if (tvb->ops->tvb_clone) {
tvbuff_t *cloned_tvb;
cloned_tvb = tvb->ops->tvb_clone(tvb, offset, len);
if (cloned_tvb)
return cloned_tvb;
}
return tvb_generic_clone_offset_len(tvb, offset, len);
}
tvbuff_t *
tvb_clone(tvbuff_t *tvb)
{
return tvb_clone_offset_len(tvb, 0, tvb->length);
}
guint
tvb_length(const tvbuff_t *tvb)
{
DISSECTOR_ASSERT(tvb && tvb->initialized);
return tvb->length;
}
gint
tvb_length_remaining(const tvbuff_t *tvb, const gint offset)
{
guint abs_offset, rem_length;
int exception;
DISSECTOR_ASSERT(tvb && tvb->initialized);
exception = compute_offset_and_remaining(tvb, offset, &abs_offset, &rem_length);
if (exception)
return 0;
return rem_length;
}
guint
tvb_ensure_length_remaining(const tvbuff_t *tvb, const gint offset)
{
guint abs_offset, rem_length;
int exception;
DISSECTOR_ASSERT(tvb && tvb->initialized);
exception = compute_offset_and_remaining(tvb, offset, &abs_offset, &rem_length);
if (exception)
THROW(exception);
if (rem_length == 0) {
if (abs_offset >= tvb->reported_length) {
if (tvb->flags & TVBUFF_FRAGMENT) {
THROW(FragmentBoundsError);
} else {
THROW(ReportedBoundsError);
}
} else
THROW(BoundsError);
}
return rem_length;
}
gboolean
tvb_bytes_exist(const tvbuff_t *tvb, const gint offset, const gint length)
{
guint abs_offset, abs_length;
int exception;
DISSECTOR_ASSERT(tvb && tvb->initialized);
exception = check_offset_length_no_exception(tvb, offset, length, &abs_offset, &abs_length);
if (exception)
return FALSE;
return TRUE;
}
void
tvb_ensure_bytes_exist(const tvbuff_t *tvb, const gint offset, const gint length)
{
guint abs_offset, abs_length;
DISSECTOR_ASSERT(tvb && tvb->initialized);
if (length < 0) {
THROW(ReportedBoundsError);
}
check_offset_length(tvb, offset, length, &abs_offset, &abs_length);
}
gboolean
tvb_offset_exists(const tvbuff_t *tvb, const gint offset)
{
guint abs_offset;
int exception;
DISSECTOR_ASSERT(tvb && tvb->initialized);
exception = compute_offset(tvb, offset, &abs_offset);
if (exception)
return FALSE;
if (abs_offset < tvb->length) {
return TRUE;
}
else {
return FALSE;
}
}
void
tvb_ensure_offset_exists(const tvbuff_t *tvb, const gint offset)
{
guint abs_offset;
int exception;
DISSECTOR_ASSERT(tvb && tvb->initialized);
exception = compute_offset(tvb, offset, &abs_offset);
if (exception)
THROW(exception);
}
guint
tvb_reported_length(const tvbuff_t *tvb)
{
DISSECTOR_ASSERT(tvb && tvb->initialized);
return tvb->reported_length;
}
gint
tvb_reported_length_remaining(const tvbuff_t *tvb, const gint offset)
{
guint abs_offset;
int exception;
DISSECTOR_ASSERT(tvb && tvb->initialized);
exception = compute_offset(tvb, offset, &abs_offset);
if (exception)
return 0;
if (tvb->reported_length >= abs_offset)
return tvb->reported_length - abs_offset;
else
return 0;
}
void
tvb_set_reported_length(tvbuff_t *tvb, const guint reported_length)
{
DISSECTOR_ASSERT(tvb && tvb->initialized);
if (reported_length > tvb->reported_length)
THROW(ReportedBoundsError);
tvb->reported_length = reported_length;
if (reported_length < tvb->length)
tvb->length = reported_length;
}
guint
tvb_offset_from_real_beginning_counter(const tvbuff_t *tvb, const guint counter)
{
if (tvb->ops->tvb_offset)
return tvb->ops->tvb_offset(tvb, counter);
DISSECTOR_ASSERT_NOT_REACHED();
return 0;
}
guint
tvb_offset_from_real_beginning(const tvbuff_t *tvb)
{
return tvb_offset_from_real_beginning_counter(tvb, 0);
}
static const guint8*
ensure_contiguous_no_exception(tvbuff_t *tvb, const gint offset, const gint length, int *pexception)
{
guint abs_offset, abs_length;
int exception;
exception = check_offset_length_no_exception(tvb, offset, length, &abs_offset, &abs_length);
if (exception) {
if (pexception)
*pexception = exception;
return NULL;
}
if (tvb->real_data)
return tvb->real_data + abs_offset;
if (tvb->ops->tvb_get_ptr)
return tvb->ops->tvb_get_ptr(tvb, abs_offset, abs_length);
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
}
static const guint8*
ensure_contiguous(tvbuff_t *tvb, const gint offset, const gint length)
{
int exception = 0;
const guint8 *p;
p = ensure_contiguous_no_exception(tvb, offset, length, &exception);
if (p == NULL) {
DISSECTOR_ASSERT(exception > 0);
THROW(exception);
}
return p;
}
static const guint8*
fast_ensure_contiguous(tvbuff_t *tvb, const gint offset, const guint length)
{
guint end_offset;
guint u_offset;
DISSECTOR_ASSERT(tvb && tvb->initialized);
DISSECTOR_ASSERT(length <= 8);
if (offset < 0 || !tvb->real_data) {
return ensure_contiguous(tvb, offset, length);
}
u_offset = offset;
end_offset = u_offset + length;
if (end_offset <= tvb->length) {
return tvb->real_data + u_offset;
}
if (end_offset > tvb->reported_length) {
if (tvb->flags & TVBUFF_FRAGMENT) {
THROW(FragmentBoundsError);
} else {
THROW(ReportedBoundsError);
}
}
THROW(BoundsError);
return NULL;
}
static const guint8*
guint8_pbrk(const guint8* haystack, size_t haystacklen, const guint8 *needles, guchar *found_needle)
{
gchar tmp[256] = { 0 };
const guint8 *haystack_end;
while (*needles)
tmp[*needles++] = 1;
haystack_end = haystack + haystacklen;
while (haystack < haystack_end) {
if (tmp[*haystack]) {
if (found_needle)
*found_needle = *haystack;
return haystack;
}
haystack++;
}
return NULL;
}
void *
tvb_memcpy(tvbuff_t *tvb, void *target, const gint offset, size_t length)
{
guint abs_offset, abs_length;
DISSECTOR_ASSERT(tvb && tvb->initialized);
DISSECTOR_ASSERT(length <= 0x7FFFFFFF);
check_offset_length(tvb, offset, (gint) length, &abs_offset, &abs_length);
if (tvb->real_data) {
return memcpy(target, tvb->real_data + abs_offset, abs_length);
}
if (tvb->ops->tvb_memcpy)
return tvb->ops->tvb_memcpy(tvb, target, abs_offset, abs_length);
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
}
void *
tvb_memdup(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, size_t length)
{
guint abs_offset, abs_length;
void *duped;
DISSECTOR_ASSERT(tvb && tvb->initialized);
check_offset_length(tvb, offset, (gint) length, &abs_offset, &abs_length);
duped = wmem_alloc(scope, abs_length);
return tvb_memcpy(tvb, duped, abs_offset, abs_length);
}
const guint8*
tvb_get_ptr(tvbuff_t *tvb, const gint offset, const gint length)
{
return ensure_contiguous(tvb, offset, length);
}
guint8
tvb_get_guint8(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint8));
return *ptr;
}
guint16
tvb_get_ntohs(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint16));
return pntohs(ptr);
}
guint32
tvb_get_ntoh24(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 3);
return pntoh24(ptr);
}
guint32
tvb_get_ntohl(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint32));
return pntohl(ptr);
}
guint64
tvb_get_ntoh40(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 5);
return pntoh40(ptr);
}
guint64
tvb_get_ntoh48(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 6);
return pntoh48(ptr);
}
guint64
tvb_get_ntoh56(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 7);
return pntoh56(ptr);
}
guint64
tvb_get_ntoh64(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint64));
return pntoh64(ptr);
}
static int
ieee_float_is_zero(const guint32 w)
{
return ((w & ~IEEE_SP_SIGN_MASK) == 0);
}
static gfloat
get_ieee_float(const guint32 w)
{
long sign;
long exponent;
long mantissa;
sign = w & IEEE_SP_SIGN_MASK;
exponent = w & IEEE_SP_EXPONENT_MASK;
mantissa = w & IEEE_SP_MANTISSA_MASK;
if (ieee_float_is_zero(w)) {
return 0.0;
}
#if 0
if (IEEE_SP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
exponent = ((exponent >> IEEE_SP_MANTISSA_WIDTH) - IEEE_SP_BIAS) -
IEEE_SP_MANTISSA_WIDTH;
mantissa |= IEEE_SP_IMPLIED_BIT;
if (sign)
return -mantissa * pow(2, exponent);
else
return mantissa * pow(2, exponent);
}
static int
ieee_double_is_zero(const guint64 w)
{
return ((w & ~IEEE_SP_SIGN_MASK) == 0);
}
static gdouble
get_ieee_double(const guint64 w)
{
gint64 sign;
gint64 exponent;
gint64 mantissa;
sign = w & IEEE_DP_SIGN_MASK;
exponent = w & IEEE_DP_EXPONENT_MASK;
mantissa = w & IEEE_DP_MANTISSA_MASK;
if (ieee_double_is_zero(w)) {
return 0.0;
}
#if 0
if (IEEE_DP_INFINITY == exponent) {
return (sign? MINUS_INFINITY: PLUS_INFINITY);
}
#endif
exponent = ((exponent >> IEEE_DP_MANTISSA_WIDTH) - IEEE_DP_BIAS) -
IEEE_DP_MANTISSA_WIDTH;
mantissa |= IEEE_DP_IMPLIED_BIT;
if (sign)
return -mantissa * pow(2, exponent);
else
return mantissa * pow(2, exponent);
}
gfloat
tvb_get_ntohieee_float(tvbuff_t *tvb, const int offset)
{
#if defined(vax)
return get_ieee_float(tvb_get_ntohl(tvb, offset));
#else
union {
gfloat f;
guint32 w;
} ieee_fp_union;
ieee_fp_union.w = tvb_get_ntohl(tvb, offset);
return ieee_fp_union.f;
#endif
}
gdouble
tvb_get_ntohieee_double(tvbuff_t *tvb, const int offset)
{
#if defined(vax)
union {
guint32 w[2];
guint64 dw;
} ieee_fp_union;
#else
union {
gdouble d;
guint32 w[2];
} ieee_fp_union;
#endif
#ifdef WORDS_BIGENDIAN
ieee_fp_union.w[0] = tvb_get_ntohl(tvb, offset);
ieee_fp_union.w[1] = tvb_get_ntohl(tvb, offset+4);
#else
ieee_fp_union.w[0] = tvb_get_ntohl(tvb, offset+4);
ieee_fp_union.w[1] = tvb_get_ntohl(tvb, offset);
#endif
#if defined(vax)
return get_ieee_double(ieee_fp_union.dw);
#else
return ieee_fp_union.d;
#endif
}
guint16
tvb_get_letohs(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint16));
return pletohs(ptr);
}
guint32
tvb_get_letoh24(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 3);
return pletoh24(ptr);
}
guint32
tvb_get_letohl(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint32));
return pletohl(ptr);
}
guint64
tvb_get_letoh40(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 5);
return pletoh40(ptr);
}
guint64
tvb_get_letoh48(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 6);
return pletoh48(ptr);
}
guint64
tvb_get_letoh56(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 7);
return pletoh56(ptr);
}
guint64
tvb_get_letoh64(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint64));
return pletoh64(ptr);
}
gfloat
tvb_get_letohieee_float(tvbuff_t *tvb, const int offset)
{
#if defined(vax)
return get_ieee_float(tvb_get_letohl(tvb, offset));
#else
union {
gfloat f;
guint32 w;
} ieee_fp_union;
ieee_fp_union.w = tvb_get_letohl(tvb, offset);
return ieee_fp_union.f;
#endif
}
gdouble
tvb_get_letohieee_double(tvbuff_t *tvb, const int offset)
{
#if defined(vax)
union {
guint32 w[2];
guint64 dw;
} ieee_fp_union;
#else
union {
gdouble d;
guint32 w[2];
} ieee_fp_union;
#endif
#ifdef WORDS_BIGENDIAN
ieee_fp_union.w[0] = tvb_get_letohl(tvb, offset+4);
ieee_fp_union.w[1] = tvb_get_letohl(tvb, offset);
#else
ieee_fp_union.w[0] = tvb_get_letohl(tvb, offset);
ieee_fp_union.w[1] = tvb_get_letohl(tvb, offset+4);
#endif
#if defined(vax)
return get_ieee_double(ieee_fp_union.dw);
#else
return ieee_fp_union.d;
#endif
}
guint32
tvb_get_ipv4(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
guint32 addr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint32));
memcpy(&addr, ptr, sizeof addr);
return addr;
}
void
tvb_get_ipv6(tvbuff_t *tvb, const gint offset, struct e_in6_addr *addr)
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, sizeof(*addr));
memcpy(addr, ptr, sizeof *addr);
}
void
tvb_get_ntohguid(tvbuff_t *tvb, const gint offset, e_guid_t *guid)
{
ensure_contiguous(tvb, offset, sizeof(*guid));
guid->data1 = tvb_get_ntohl(tvb, offset);
guid->data2 = tvb_get_ntohs(tvb, offset + 4);
guid->data3 = tvb_get_ntohs(tvb, offset + 6);
tvb_memcpy(tvb, guid->data4, offset + 8, sizeof guid->data4);
}
void
tvb_get_letohguid(tvbuff_t *tvb, const gint offset, e_guid_t *guid)
{
ensure_contiguous(tvb, offset, sizeof(*guid));
guid->data1 = tvb_get_letohl(tvb, offset);
guid->data2 = tvb_get_letohs(tvb, offset + 4);
guid->data3 = tvb_get_letohs(tvb, offset + 6);
tvb_memcpy(tvb, guid->data4, offset + 8, sizeof guid->data4);
}
void
tvb_get_guid(tvbuff_t *tvb, const gint offset, e_guid_t *guid, const guint representation)
{
if (representation) {
tvb_get_letohguid(tvb, offset, guid);
} else {
tvb_get_ntohguid(tvb, offset, guid);
}
}
guint8
tvb_get_bits8(tvbuff_t *tvb, guint bit_offset, const gint no_of_bits)
{
return (guint8)_tvb_get_bits64(tvb, bit_offset, no_of_bits);
}
void
tvb_get_bits_buf(tvbuff_t *tvb, guint bit_offset, gint no_of_bits, guint8 *buf, gboolean lsb0)
{
guint8 bit_mask, bit_shift;
gint offset = bit_offset >> 3;
bit_offset = bit_offset & 0x7;
bit_mask = (lsb0) ? 0xff : inverse_bit_mask8[bit_offset];
bit_shift = (lsb0) ? bit_offset : (8 - bit_offset);
if (G_LIKELY(bit_offset != 0)) {
guint16 value = (guint16) tvb_get_guint8(tvb, offset);
while (no_of_bits >= 8) {
offset++;
value = ((value & bit_mask) << 8) | tvb_get_guint8(tvb, offset);
if (lsb0)
*buf++ = (guint8) (GUINT16_SWAP_LE_BE(value) >> bit_shift);
else
*buf++ = (guint8) (value >> bit_shift);
no_of_bits -= 8;
}
if (no_of_bits > 0) {
guint8 tot_no_bits = bit_offset+no_of_bits;
if (tot_no_bits > 8) {
offset++;
value = ((value & bit_mask) << 8) | tvb_get_guint8(tvb, offset);
}
if (lsb0) {
if (tot_no_bits > 8)
value = (GUINT16_SWAP_LE_BE(value) >> bit_offset) & (bit_mask8[no_of_bits]);
else
value = (value >> bit_offset) & (bit_mask8[no_of_bits]);
} else {
if (tot_no_bits > 8)
value = value >> (16 - tot_no_bits);
else
value = (value & bit_mask) >> (8-tot_no_bits);
}
*buf = (guint8) value;
}
} else {
while (no_of_bits >= 8) {
*buf++ = tvb_get_guint8(tvb, offset);
offset++;
no_of_bits -= 8;
}
if (no_of_bits > 0) {
if (lsb0)
*buf = tvb_get_guint8(tvb, offset) & bit_mask8[no_of_bits];
else
*buf = tvb_get_guint8(tvb, offset) >> (8-no_of_bits);
}
}
}
guint8 *
wmem_packet_tvb_get_bits(tvbuff_t *tvb, guint bit_offset, gint no_of_bits, gboolean lsb0)
{
gint no_of_bytes;
guint8 *buf;
if (no_of_bits < 0) {
DISSECTOR_ASSERT_NOT_REACHED();
}
no_of_bytes = (no_of_bits >> 3) + ((no_of_bits & 0x7) != 0);
buf = (guint8 *)wmem_alloc(wmem_packet_scope(), no_of_bytes);
tvb_get_bits_buf(tvb, bit_offset, no_of_bits, buf, lsb0);
return buf;
}
guint16
tvb_get_bits16(tvbuff_t *tvb, guint bit_offset, const gint no_of_bits,const guint encoding _U_)
{
return (guint16)_tvb_get_bits64(tvb, bit_offset, no_of_bits);
}
guint32
tvb_get_bits32(tvbuff_t *tvb, guint bit_offset, const gint no_of_bits, const guint encoding _U_)
{
return (guint32)_tvb_get_bits64(tvb, bit_offset, no_of_bits);
}
guint64
tvb_get_bits64(tvbuff_t *tvb, guint bit_offset, const gint no_of_bits, const guint encoding _U_)
{
return _tvb_get_bits64(tvb, bit_offset, no_of_bits);
}
static guint64
_tvb_get_bits64(tvbuff_t *tvb, guint bit_offset, const gint total_no_of_bits)
{
guint64 value;
guint octet_offset = bit_offset >> 3;
guint8 required_bits_in_first_octet = 8 - (bit_offset % 8);
if(required_bits_in_first_octet > total_no_of_bits)
{
guint8 right_shift = required_bits_in_first_octet - total_no_of_bits;
value = (tvb_get_guint8(tvb, octet_offset) >> right_shift) & bit_mask8[total_no_of_bits % 8];
}
else
{
guint8 remaining_bit_length = total_no_of_bits;
value = 0;
required_bits_in_first_octet %= 8;
if(required_bits_in_first_octet != 0)
{
value = tvb_get_guint8(tvb, octet_offset) & bit_mask8[required_bits_in_first_octet];
remaining_bit_length -= required_bits_in_first_octet;
octet_offset ++;
}
while (remaining_bit_length > 7)
{
switch (remaining_bit_length >> 4)
{
case 0:
value <<= 8;
value += tvb_get_guint8(tvb, octet_offset);
remaining_bit_length -= 8;
octet_offset ++;
break;
case 1:
value <<= 16;
value += tvb_get_ntohs(tvb, octet_offset);
remaining_bit_length -= 16;
octet_offset += 2;
break;
case 2:
case 3:
value <<= 32;
value += tvb_get_ntohl(tvb, octet_offset);
remaining_bit_length -= 32;
octet_offset += 4;
break;
default:
value = tvb_get_ntoh64(tvb, octet_offset);
remaining_bit_length -= 64;
octet_offset += 8;
break;
}
}
if(remaining_bit_length)
{
value <<= remaining_bit_length;
value += (tvb_get_guint8(tvb, octet_offset) >> (8 - remaining_bit_length));
}
}
return value;
}
guint32
tvb_get_bits(tvbuff_t *tvb, const guint bit_offset, const gint no_of_bits, const guint encoding _U_)
{
return (guint32)_tvb_get_bits64(tvb, bit_offset, no_of_bits);
}
static gint
tvb_find_guint8_generic(tvbuff_t *tvb, guint abs_offset, guint limit, guint8 needle)
{
const guint8 *ptr;
const guint8 *result;
ptr = tvb_get_ptr(tvb, abs_offset, limit);
result = (const guint8 *) memchr(ptr, needle, limit);
if (!result)
return -1;
return (gint) ((result - ptr) + abs_offset);
}
gint
tvb_find_guint8(tvbuff_t *tvb, const gint offset, const gint maxlength, const guint8 needle)
{
const guint8 *result;
guint abs_offset;
guint tvbufflen;
guint limit;
DISSECTOR_ASSERT(tvb && tvb->initialized);
check_offset_length(tvb, offset, -1, &abs_offset, &tvbufflen);
if (maxlength == -1) {
limit = tvbufflen;
}
else if (tvbufflen < (guint) maxlength) {
limit = tvbufflen;
}
else {
limit = maxlength;
}
if (tvb->real_data) {
result = (const guint8 *)memchr(tvb->real_data + abs_offset, needle, limit);
if (result == NULL) {
return -1;
}
else {
return (gint) (result - tvb->real_data);
}
}
if (tvb->ops->tvb_find_guint8)
return tvb->ops->tvb_find_guint8(tvb, abs_offset, limit, needle);
return tvb_find_guint8_generic(tvb, offset, limit, needle);
}
static gint
tvb_pbrk_guint8_generic(tvbuff_t *tvb, guint abs_offset, guint limit, const guint8 *needles, guchar *found_needle)
{
const guint8 *ptr;
const guint8 *result;
ptr = tvb_get_ptr(tvb, abs_offset, limit);
result = guint8_pbrk(ptr, limit, needles, found_needle);
if (!result)
return -1;
return (gint) ((result - ptr) + abs_offset);
}
gint
tvb_pbrk_guint8(tvbuff_t *tvb, const gint offset, const gint maxlength, const guint8 *needles, guchar *found_needle)
{
const guint8 *result;
guint abs_offset;
guint tvbufflen;
guint limit;
DISSECTOR_ASSERT(tvb && tvb->initialized);
check_offset_length(tvb, offset, -1, &abs_offset, &tvbufflen);
if (maxlength == -1) {
limit = tvbufflen;
}
else if (tvbufflen < (guint) maxlength) {
limit = tvbufflen;
}
else {
limit = maxlength;
}
if (tvb->real_data) {
result = guint8_pbrk(tvb->real_data + abs_offset, limit, needles, found_needle);
if (result == NULL) {
return -1;
}
else {
return (gint) (result - tvb->real_data);
}
}
if (tvb->ops->tvb_pbrk_guint8)
return tvb->ops->tvb_pbrk_guint8(tvb, abs_offset, limit, needles, found_needle);
return tvb_pbrk_guint8_generic(tvb, abs_offset, limit, needles, found_needle);
}
guint
tvb_strsize(tvbuff_t *tvb, const gint offset)
{
guint abs_offset, junk_length;
gint nul_offset;
DISSECTOR_ASSERT(tvb && tvb->initialized);
check_offset_length(tvb, offset, 0, &abs_offset, &junk_length);
nul_offset = tvb_find_guint8(tvb, abs_offset, -1, 0);
if (nul_offset == -1) {
if (tvb->length < tvb->reported_length) {
THROW(BoundsError);
} else {
if (tvb->flags & TVBUFF_FRAGMENT) {
THROW(FragmentBoundsError);
} else {
THROW(ReportedBoundsError);
}
}
}
return (nul_offset - abs_offset) + 1;
}
guint
tvb_unicode_strsize(tvbuff_t *tvb, const gint offset)
{
guint i = 0;
gunichar2 uchar;
DISSECTOR_ASSERT(tvb && tvb->initialized);
do {
uchar = tvb_get_ntohs(tvb, offset + i);
i += 2;
} while(uchar != 0);
return i;
}
gint
tvb_strnlen(tvbuff_t *tvb, const gint offset, const guint maxlength)
{
gint result_offset;
guint abs_offset, junk_length;
DISSECTOR_ASSERT(tvb && tvb->initialized);
check_offset_length(tvb, offset, 0, &abs_offset, &junk_length);
result_offset = tvb_find_guint8(tvb, abs_offset, maxlength, 0);
if (result_offset == -1) {
return -1;
}
else {
return result_offset - abs_offset;
}
}
gint
tvb_strneql(tvbuff_t *tvb, const gint offset, const gchar *str, const size_t size)
{
const guint8 *ptr;
ptr = ensure_contiguous_no_exception(tvb, offset, (gint)size, NULL);
if (ptr) {
int cmp = strncmp((const char *)ptr, str, size);
return (cmp == 0 ? 0 : -1);
} else {
return -1;
}
}
gint
tvb_strncaseeql(tvbuff_t *tvb, const gint offset, const gchar *str, const size_t size)
{
const guint8 *ptr;
ptr = ensure_contiguous_no_exception(tvb, offset, (gint)size, NULL);
if (ptr) {
int cmp = g_ascii_strncasecmp((const char *)ptr, str, size);
return (cmp == 0 ? 0 : -1);
} else {
return -1;
}
}
gint
tvb_memeql(tvbuff_t *tvb, const gint offset, const guint8 *str, size_t size)
{
const guint8 *ptr;
ptr = ensure_contiguous_no_exception(tvb, offset, (gint) size, NULL);
if (ptr) {
int cmp = memcmp(ptr, str, size);
return (cmp == 0 ? 0 : -1);
} else {
return -1;
}
}
char *
tvb_get_faked_unicode(wmem_allocator_t *scope, tvbuff_t *tvb, int offset,
const int len, const gboolean little_endian)
{
char *buffer;
int i;
guint16 character;
tvb_ensure_bytes_exist(tvb, offset, 2*len);
buffer = (char *)wmem_alloc(scope, len + 1);
for (i = 0; i < len; i++) {
character = little_endian ? tvb_get_letohs(tvb, offset)
: tvb_get_ntohs(tvb, offset);
buffer[i] = character < 256 ? character : '.';
offset += 2;
}
buffer[len] = 0;
return buffer;
}
gchar *
tvb_format_text(tvbuff_t *tvb, const gint offset, const gint size)
{
const guint8 *ptr;
gint len;
len = (size > 0) ? size : 0;
if ((ptr = ensure_contiguous(tvb, offset, size)) == NULL) {
len = tvb_length_remaining(tvb, offset);
ptr = ensure_contiguous(tvb, offset, len);
}
return format_text(ptr, len);
}
gchar *
tvb_format_text_wsp(tvbuff_t *tvb, const gint offset, const gint size)
{
const guint8 *ptr;
gint len;
len = (size > 0) ? size : 0;
if ((ptr = ensure_contiguous(tvb, offset, size)) == NULL) {
len = tvb_length_remaining(tvb, offset);
ptr = ensure_contiguous(tvb, offset, len);
}
return format_text_wsp(ptr, len);
}
gchar *
tvb_format_stringzpad(tvbuff_t *tvb, const gint offset, const gint size)
{
const guint8 *ptr, *p;
gint len;
gint stringlen;
len = (size > 0) ? size : 0;
if ((ptr = ensure_contiguous(tvb, offset, size)) == NULL) {
len = tvb_length_remaining(tvb, offset);
ptr = ensure_contiguous(tvb, offset, len);
}
for (p = ptr, stringlen = 0; stringlen < len && *p != '\0'; p++, stringlen++)
;
return format_text(ptr, stringlen);
}
gchar *
tvb_format_stringzpad_wsp(tvbuff_t *tvb, const gint offset, const gint size)
{
const guint8 *ptr, *p;
gint len;
gint stringlen;
len = (size > 0) ? size : 0;
if ((ptr = ensure_contiguous(tvb, offset, size)) == NULL) {
len = tvb_length_remaining(tvb, offset);
ptr = ensure_contiguous(tvb, offset, len);
}
for (p = ptr, stringlen = 0; stringlen < len && *p != '\0'; p++, stringlen++)
;
return format_text_wsp(ptr, stringlen);
}
guint8 *
tvb_get_string(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, const gint length)
{
guint8 *strbuf;
tvb_ensure_bytes_exist(tvb, offset, length);
strbuf = (guint8 *)wmem_alloc(scope, length + 1);
tvb_memcpy(tvb, strbuf, offset, length);
strbuf[length] = '\0';
return strbuf;
}
gchar *
tvb_get_unicode_string(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint length, const guint encoding)
{
gunichar2 uchar;
gint i;
wmem_strbuf_t *strbuf;
tvb_ensure_bytes_exist(tvb, offset, length);
strbuf = wmem_strbuf_new(scope, NULL);
for(i = 0; i < length; i += 2) {
if (encoding == ENC_BIG_ENDIAN)
uchar = tvb_get_ntohs(tvb, offset + i);
else
uchar = tvb_get_letohs(tvb, offset + i);
wmem_strbuf_append_unichar(strbuf, uchar);
}
return (gchar*)wmem_strbuf_get_str(strbuf);
}
guint8 *
tvb_get_string_enc(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset,
const gint length, const guint encoding)
{
const guint8 *ptr;
guint8 *strbuf;
switch (encoding & ENC_CHARENCODING_MASK) {
case ENC_ASCII:
default:
strbuf = tvb_get_string(scope, tvb, offset, length);
break;
case ENC_UTF_8:
strbuf = tvb_get_string(scope, tvb, offset, length);
break;
case ENC_UTF_16:
strbuf = tvb_get_unicode_string(scope, tvb, offset, length,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_UCS_2:
strbuf = tvb_get_unicode_string(scope, tvb, offset, length,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_EBCDIC:
tvb_ensure_bytes_exist(tvb, offset, length);
strbuf = (guint8 *)wmem_alloc(scope, length + 1);
if (length != 0) {
ptr = ensure_contiguous(tvb, offset, length);
memcpy(strbuf, ptr, length);
EBCDIC_to_ASCII(strbuf, length);
}
strbuf[length] = '\0';
break;
}
return strbuf;
}
guint8 *
tvb_get_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint *lengthp)
{
guint size;
guint8 *strptr;
size = tvb_strsize(tvb, offset);
strptr = (guint8 *)wmem_alloc(scope, size);
tvb_memcpy(tvb, strptr, offset, size);
if (lengthp)
*lengthp = size;
return strptr;
}
guint8 *
tvb_get_stringz_enc(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint *lengthp, const guint encoding)
{
guint size;
guint8 *strptr;
switch (encoding & ENC_CHARENCODING_MASK) {
case ENC_ASCII:
default:
strptr = tvb_get_stringz(scope, tvb, offset, lengthp);
break;
case ENC_UTF_8:
strptr = tvb_get_stringz(scope, tvb, offset, lengthp);
break;
case ENC_UTF_16:
strptr = tvb_get_unicode_stringz(scope, tvb, offset, lengthp,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_UCS_2:
strptr = tvb_get_unicode_stringz(scope, tvb, offset, lengthp,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_EBCDIC:
size = tvb_strsize(tvb, offset);
strptr = (guint8 *)wmem_alloc(scope, size);
tvb_memcpy(tvb, strptr, offset, size);
EBCDIC_to_ASCII(strptr, size);
if (lengthp)
*lengthp = size;
break;
}
return strptr;
}
const guint8 *
tvb_get_const_stringz(tvbuff_t *tvb, const gint offset, gint *lengthp)
{
guint size;
const guint8 *strptr;
size = tvb_strsize(tvb, offset);
strptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return strptr;
}
gchar *
tvb_get_unicode_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint *lengthp, const guint encoding)
{
gunichar2 uchar;
gint size;
gint i;
wmem_strbuf_t *strbuf;
size = tvb_unicode_strsize(tvb, offset);
strbuf = wmem_strbuf_new(scope, NULL);
for(i = 0; i < size; i += 2) {
if (encoding == ENC_BIG_ENDIAN)
uchar = tvb_get_ntohs(tvb, offset + i);
else
uchar = tvb_get_letohs(tvb, offset + i);
wmem_strbuf_append_unichar(strbuf, uchar);
}
if (lengthp)
*lengthp = i;
return (gchar*)wmem_strbuf_get_str(strbuf);
}
static gint
_tvb_get_nstringz(tvbuff_t *tvb, const gint offset, const guint bufsize, guint8* buffer, gint *bytes_copied)
{
gint stringlen;
guint abs_offset;
gint limit, len;
gboolean decreased_max = FALSE;
check_offset_length(tvb, offset, -1, &abs_offset, &len);
DISSECTOR_ASSERT(bufsize != 0);
if (bufsize == 1) {
buffer[0] = 0;
*bytes_copied = 1;
return 0;
}
if (len == 0) {
THROW(ReportedBoundsError);
}
DISSECTOR_ASSERT(len != -1);
DISSECTOR_ASSERT(bufsize <= G_MAXINT);
if ((guint)len < bufsize) {
limit = len;
decreased_max = TRUE;
}
else {
limit = bufsize;
}
stringlen = tvb_strnlen(tvb, abs_offset, limit - 1);
if (stringlen == -1) {
tvb_memcpy(tvb, buffer, abs_offset, limit);
if (decreased_max) {
buffer[limit] = 0;
*bytes_copied = limit + 1;
}
else {
*bytes_copied = limit;
}
return -1;
}
tvb_memcpy(tvb, buffer, abs_offset, stringlen + 1);
*bytes_copied = stringlen + 1;
return stringlen;
}
gint
tvb_get_nstringz(tvbuff_t *tvb, const gint offset, const guint bufsize, guint8* buffer)
{
gint bytes_copied;
DISSECTOR_ASSERT(tvb && tvb->initialized);
return _tvb_get_nstringz(tvb, offset, bufsize, buffer, &bytes_copied);
}
gint
tvb_get_nstringz0(tvbuff_t *tvb, const gint offset, const guint bufsize, guint8* buffer)
{
gint len, bytes_copied;
DISSECTOR_ASSERT(tvb && tvb->initialized);
len = _tvb_get_nstringz(tvb, offset, bufsize, buffer, &bytes_copied);
if (len == -1) {
buffer[bufsize - 1] = 0;
return bytes_copied - 1;
}
else {
return len;
}
}
gint
tvb_find_line_end(tvbuff_t *tvb, const gint offset, int len, gint *next_offset, const gboolean desegment)
{
gint eob_offset;
gint eol_offset;
int linelen;
guchar found_needle = 0;
if (len == -1)
len = tvb_length_remaining(tvb, offset);
eob_offset = offset + len;
eol_offset = tvb_pbrk_guint8(tvb, offset, len, "\r\n", &found_needle);
if (eol_offset == -1) {
if (desegment) {
return -1;
} else {
linelen = eob_offset - offset;
if (next_offset)
*next_offset = eob_offset;
}
} else {
linelen = eol_offset - offset;
if (found_needle == '\r') {
if (eol_offset + 1 >= eob_offset) {
if (desegment) {
return -1;
}
} else {
if (tvb_get_guint8(tvb, eol_offset + 1) == '\n') {
eol_offset++;
}
}
}
if (next_offset)
*next_offset = eol_offset + 1;
}
return linelen;
}
gint
tvb_find_line_end_unquoted(tvbuff_t *tvb, const gint offset, int len, gint *next_offset)
{
gint cur_offset, char_offset;
gboolean is_quoted;
guchar c = 0;
gint eob_offset;
int linelen;
if (len == -1)
len = tvb_length_remaining(tvb, offset);
eob_offset = offset + len;
cur_offset = offset;
is_quoted = FALSE;
for (;;) {
if (is_quoted) {
char_offset = tvb_find_guint8(tvb, cur_offset, len,
'"');
} else {
char_offset = tvb_pbrk_guint8(tvb, cur_offset, len, "\r\n\"", &c);
}
if (char_offset == -1) {
linelen = eob_offset - offset;
if (next_offset)
*next_offset = eob_offset;
break;
}
if (is_quoted) {
is_quoted = FALSE;
} else {
if (c == '"') {
is_quoted = TRUE;
} else {
linelen = char_offset - offset;
if (c == '\r') {
if (char_offset + 1 < eob_offset &&
tvb_get_guint8(tvb, char_offset + 1)
== '\n') {
char_offset++;
}
}
if (next_offset)
*next_offset = char_offset + 1;
break;
}
}
cur_offset = char_offset + 1;
if (cur_offset >= eob_offset) {
linelen = eob_offset - offset;
if (next_offset)
*next_offset = eob_offset;
break;
}
}
return linelen;
}
gint
tvb_skip_wsp(tvbuff_t *tvb, const gint offset, const gint maxlength)
{
gint counter = offset;
gint end, tvb_len;
guint8 tempchar;
tvb_len = tvb_length(tvb);
end = offset + maxlength;
if (end >= tvb_len)
{
end = tvb_len;
}
for (counter = offset;
counter < end &&
((tempchar = tvb_get_guint8(tvb,counter)) == ' ' ||
tempchar == '\t' || tempchar == '\r' || tempchar == '\n');
counter++);
return (counter);
}
gint
tvb_skip_wsp_return(tvbuff_t *tvb, const gint offset) {
gint counter = offset;
guint8 tempchar;
for(counter = offset; counter > 0 &&
((tempchar = tvb_get_guint8(tvb,counter)) == ' ' ||
tempchar == '\t' || tempchar == '\n' || tempchar == '\r'); counter--);
counter++;
return (counter);
}
gchar *
tvb_bytes_to_str_punct(tvbuff_t *tvb, const gint offset, const gint len, const gchar punct)
{
return bytes_to_str_punct(ensure_contiguous(tvb, offset, len), len, punct);
}
const gchar *
tvb_bcd_dig_to_wmem_packet_str(tvbuff_t *tvb, const gint offset, const gint len, dgt_set_t *dgt, gboolean skip_first)
{
int length;
guint8 octet;
int i = 0;
char *digit_str;
gint t_offset = offset;
if (!dgt)
dgt = &Dgt1_9_bcd;
if (len == -1) {
length = tvb_length(tvb);
if (length < offset) {
return "";
}
} else {
length = offset + len;
}
digit_str = (char *)wmem_alloc(wmem_packet_scope(), (length - offset)*2+1);
while (t_offset < length) {
octet = tvb_get_guint8(tvb,t_offset);
if (!skip_first) {
digit_str[i] = dgt->out[octet & 0x0f];
i++;
}
skip_first = FALSE;
octet = octet >> 4;
if (octet == 0x0f)
break;
digit_str[i] = dgt->out[octet & 0x0f];
i++;
t_offset++;
}
digit_str[i]= '\0';
return digit_str;
}
gchar *
tvb_bytes_to_str(tvbuff_t *tvb, const gint offset, const gint len)
{
return bytes_to_str(ensure_contiguous(tvb, offset, len), len);
}
gint
tvb_find_tvb(tvbuff_t *haystack_tvb, tvbuff_t *needle_tvb, const gint haystack_offset)
{
guint haystack_abs_offset, haystack_abs_length;
const guint8 *haystack_data;
const guint8 *needle_data;
const guint needle_len = needle_tvb->length;
const guint8 *location;
DISSECTOR_ASSERT(haystack_tvb && haystack_tvb->initialized);
if (haystack_tvb->length < 1 || needle_tvb->length < 1) {
return -1;
}
haystack_data = ensure_contiguous(haystack_tvb, 0, -1);
needle_data = ensure_contiguous(needle_tvb, 0, -1);
check_offset_length(haystack_tvb, haystack_offset, -1,
&haystack_abs_offset, &haystack_abs_length);
location = epan_memmem(haystack_data + haystack_abs_offset, haystack_abs_length,
needle_data, needle_len);
if (location) {
return (gint) (location - haystack_data);
}
return -1;
}
tvbuff_t *
tvb_uncompress(tvbuff_t *tvb, const int offset, int comprlen)
{
gint err = Z_OK;
guint bytes_out = 0;
guint8 *compr = NULL;
guint8 *uncompr = NULL;
tvbuff_t *uncompr_tvb = NULL;
z_streamp strm = NULL;
Bytef *strmbuf = NULL;
guint inits_done = 0;
gint wbits = MAX_WBITS;
guint8 *next = NULL;
guint bufsiz = TVB_Z_MIN_BUFSIZ;
#ifdef TVB_Z_DEBUG
guint inflate_passes = 0;
guint bytes_in = tvb_length_remaining(tvb, offset);
#endif
if (tvb == NULL) {
return NULL;
}
compr = (guint8 *)tvb_memdup(NULL, tvb, offset, comprlen);
if (!compr)
return NULL;
bufsiz = tvb_length_remaining(tvb, offset) * 2;
bufsiz = CLAMP(bufsiz, TVB_Z_MIN_BUFSIZ, TVB_Z_MAX_BUFSIZ);
#ifdef TVB_Z_DEBUG
printf("bufsiz: %u bytes\n", bufsiz);
#endif
next = compr;
strm = g_new0(z_stream, 1);
strm->next_in = next;
strm->avail_in = comprlen;
strmbuf = (Bytef *)g_malloc0(bufsiz);
strm->next_out = strmbuf;
strm->avail_out = bufsiz;
err = inflateInit2(strm, wbits);
inits_done = 1;
if (err != Z_OK) {
inflateEnd(strm);
g_free(strm);
g_free(compr);
g_free(strmbuf);
return NULL;
}
while (1) {
memset(strmbuf, '\0', bufsiz);
strm->next_out = strmbuf;
strm->avail_out = bufsiz;
err = inflate(strm, Z_SYNC_FLUSH);
if (err == Z_OK || err == Z_STREAM_END) {
guint bytes_pass = bufsiz - strm->avail_out;
#ifdef TVB_Z_DEBUG
++inflate_passes;
#endif
if (uncompr == NULL) {
uncompr = (guint8 *)((bytes_pass || err != Z_STREAM_END) ?
g_memdup(strmbuf, bytes_pass) :
g_strdup(""));
} else {
guint8 *new_data = (guint8 *)g_malloc0(bytes_out + bytes_pass);
memcpy(new_data, uncompr, bytes_out);
memcpy(new_data + bytes_out, strmbuf, bytes_pass);
g_free(uncompr);
uncompr = new_data;
}
bytes_out += bytes_pass;
if (err == Z_STREAM_END) {
inflateEnd(strm);
g_free(strm);
g_free(strmbuf);
break;
}
} else if (err == Z_BUF_ERROR) {
inflateEnd(strm);
g_free(strm);
g_free(strmbuf);
if (uncompr != NULL) {
break;
} else {
g_free(compr);
return NULL;
}
} else if (err == Z_DATA_ERROR && inits_done == 1
&& uncompr == NULL && (*compr == 0x1f) &&
(*(compr + 1) == 0x8b)) {
Bytef *c = compr + 2;
Bytef flags = 0;
if (*c == Z_DEFLATED) {
c++;
} else {
inflateEnd(strm);
g_free(strm);
g_free(compr);
g_free(strmbuf);
return NULL;
}
flags = *c;
c += 7;
if (flags & (1 << 2)) {
gint xsize = (gint)(*c |
(*(c + 1) << 8));
c += xsize;
}
if (flags & (1 << 3)) {
while ((c - compr) < comprlen && *c != '\0') {
c++;
}
c++;
}
if (flags & (1 << 4)) {
while ((c - compr) < comprlen && *c != '\0') {
c++;
}
c++;
}
inflateReset(strm);
next = c;
strm->next_in = next;
if (c - compr > comprlen) {
inflateEnd(strm);
g_free(strm);
g_free(compr);
g_free(strmbuf);
return NULL;
}
comprlen -= (int) (c - compr);
inflateEnd(strm);
inflateInit2(strm, wbits);
inits_done++;
} else if (err == Z_DATA_ERROR && uncompr == NULL &&
inits_done <= 3) {
wbits = -MAX_WBITS;
inflateReset(strm);
strm->next_in = next;
strm->avail_in = comprlen;
inflateEnd(strm);
memset(strmbuf, '\0', bufsiz);
strm->next_out = strmbuf;
strm->avail_out = bufsiz;
err = inflateInit2(strm, wbits);
inits_done++;
if (err != Z_OK) {
g_free(strm);
g_free(strmbuf);
g_free(compr);
g_free(uncompr);
return NULL;
}
} else {
inflateEnd(strm);
g_free(strm);
g_free(strmbuf);
if (uncompr == NULL) {
g_free(compr);
return NULL;
}
break;
}
}
#ifdef TVB_Z_DEBUG
printf("inflate() total passes: %u\n", inflate_passes);
printf("bytes in: %u\nbytes out: %u\n\n", bytes_in, bytes_out);
#endif
if (uncompr != NULL) {
uncompr_tvb = tvb_new_real_data((guint8*) uncompr, bytes_out, bytes_out);
tvb_set_free_cb(uncompr_tvb, g_free);
}
g_free(compr);
return uncompr_tvb;
}
tvbuff_t *
tvb_uncompress(tvbuff_t *tvb _U_, const int offset _U_, int comprlen _U_)
{
return NULL;
}
tvbuff_t *
tvb_child_uncompress(tvbuff_t *parent, tvbuff_t *tvb, const int offset, int comprlen)
{
tvbuff_t *new_tvb = tvb_uncompress(tvb, offset, comprlen);
if (new_tvb)
tvb_set_child_real_data_tvbuff (parent, new_tvb);
return new_tvb;
}
gint
tvb_raw_offset(tvbuff_t *tvb)
{
return ((tvb->raw_offset==-1)?(tvb->raw_offset = tvb_offset_from_real_beginning(tvb)):tvb->raw_offset);
}
void
tvb_set_fragment(tvbuff_t *tvb)
{
tvb->flags |= TVBUFF_FRAGMENT;
}
struct tvbuff *
tvb_get_ds_tvb(tvbuff_t *tvb)
{
return(tvb->ds_tvb);
}
