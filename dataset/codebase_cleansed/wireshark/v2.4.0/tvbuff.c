tvbuff_t *
tvb_new(const struct tvb_ops *ops)
{
tvbuff_t *tvb;
gsize size = ops->tvb_size;
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
size = tvb->ops->tvb_size;
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
next_tvb = tvb->next;
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
static inline int
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
static inline int
compute_offset_and_remaining(const tvbuff_t *tvb, const gint offset, guint *offset_ptr, guint *rem_len)
{
int exception;
exception = compute_offset(tvb, offset, offset_ptr);
if (!exception)
*rem_len = tvb->length - *offset_ptr;
return exception;
}
static inline int
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
static inline void
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
DISSECTOR_ASSERT(tvb && tvb->initialized);
byte_offset = bit_offset >> 3;
left = bit_offset % 8;
right = 8 - left;
if (no_of_bits == -1) {
datalen = _tvb_captured_length_remaining(tvb, byte_offset);
remaining_bits = 0;
} else {
datalen = no_of_bits >> 3;
remaining_bits = no_of_bits % 8;
if (remaining_bits) {
datalen++;
}
}
if ((left == 0) && (remaining_bits == 0)) {
return tvb_new_subset_length_caplen(tvb, byte_offset, datalen, datalen);
}
DISSECTOR_ASSERT(datalen>0);
if (_tvb_captured_length_remaining(tvb, byte_offset) > datalen) {
data = ensure_contiguous(tvb, byte_offset, datalen + 1);
buf = (guint8 *)g_malloc(datalen);
for (i = 0; i < datalen; i++)
buf[i] = (data[i] << left) | (data[i+1] >> right);
} else {
data = ensure_contiguous(tvb, byte_offset, datalen);
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
guint8 *data;
DISSECTOR_ASSERT(tvb_bytes_exist(tvb, offset, len));
data = (guint8 *) g_malloc(len);
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
tvb_captured_length(const tvbuff_t *tvb)
{
DISSECTOR_ASSERT(tvb && tvb->initialized);
return tvb->length;
}
static inline gint
_tvb_captured_length_remaining(const tvbuff_t *tvb, const gint offset)
{
guint abs_offset, rem_length;
int exception;
exception = compute_offset_and_remaining(tvb, offset, &abs_offset, &rem_length);
if (exception)
return 0;
return rem_length;
}
gint
tvb_captured_length_remaining(const tvbuff_t *tvb, const gint offset)
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
tvb_ensure_captured_length_remaining(const tvbuff_t *tvb, const gint offset)
{
guint abs_offset = 0, rem_length = 0;
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
tvb_ensure_bytes_exist64(const tvbuff_t *tvb, const gint offset, const guint64 length)
{
if (length > G_MAXINT) {
THROW(ReportedBoundsError);
}
tvb_ensure_bytes_exist(tvb, offset, (gint)length);
}
void
tvb_ensure_bytes_exist(const tvbuff_t *tvb, const gint offset, const gint length)
{
guint real_offset, end_offset;
DISSECTOR_ASSERT(tvb && tvb->initialized);
if (length < 0) {
THROW(ReportedBoundsError);
}
if (offset >= 0) {
if ((guint) offset <= tvb->length) {
real_offset = offset;
} else if ((guint) offset <= tvb->reported_length) {
THROW(BoundsError);
} else if (tvb->flags & TVBUFF_FRAGMENT) {
THROW(FragmentBoundsError);
} else {
THROW(ReportedBoundsError);
}
}
else {
if ((guint) -offset <= tvb->length) {
real_offset = tvb->length + offset;
} else if ((guint) -offset <= tvb->reported_length) {
THROW(BoundsError);
} else if (tvb->flags & TVBUFF_FRAGMENT) {
THROW(FragmentBoundsError);
} else {
THROW(ReportedBoundsError);
}
}
end_offset = real_offset + length;
if (end_offset < real_offset)
THROW(BoundsError);
if (G_LIKELY(end_offset <= tvb->length))
return;
else if (end_offset <= tvb->reported_length)
THROW(BoundsError);
else if (tvb->flags & TVBUFF_FRAGMENT)
THROW(FragmentBoundsError);
else
THROW(ReportedBoundsError);
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
static inline const guint8*
ensure_contiguous_no_exception(tvbuff_t *tvb, const gint offset, const gint length, int *pexception)
{
guint abs_offset = 0, abs_length = 0;
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
static inline const guint8*
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
static inline const guint8*
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
void *
tvb_memcpy(tvbuff_t *tvb, void *target, const gint offset, size_t length)
{
guint abs_offset = 0, abs_length = 0;
DISSECTOR_ASSERT(tvb && tvb->initialized);
DISSECTOR_ASSERT(length <= 0x7FFFFFFF);
check_offset_length(tvb, offset, (gint) length, &abs_offset, &abs_length);
if (tvb->real_data) {
return memcpy(target, tvb->real_data + abs_offset, abs_length);
}
if (tvb->ops->tvb_memcpy)
return tvb->ops->tvb_memcpy(tvb, target, abs_offset, abs_length);
if (length != 0) {
DISSECTOR_ASSERT_NOT_REACHED();
}
return NULL;
}
void *
tvb_memdup(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, size_t length)
{
guint abs_offset = 0, abs_length = 0;
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
return pntoh16(ptr);
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
return pntoh32(ptr);
}
guint64
tvb_get_ntoh40(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 5);
return pntoh40(ptr);
}
gint64
tvb_get_ntohi40(tvbuff_t *tvb, const gint offset)
{
guint64 ret;
ret = ws_sign_ext64(tvb_get_ntoh40(tvb, offset), 40);
return (gint64)ret;
}
guint64
tvb_get_ntoh48(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 6);
return pntoh48(ptr);
}
gint64
tvb_get_ntohi48(tvbuff_t *tvb, const gint offset)
{
guint64 ret;
ret = ws_sign_ext64(tvb_get_ntoh48(tvb, offset), 48);
return (gint64)ret;
}
guint64
tvb_get_ntoh56(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 7);
return pntoh56(ptr);
}
gint64
tvb_get_ntohi56(tvbuff_t *tvb, const gint offset)
{
guint64 ret;
ret = ws_sign_ext64(tvb_get_ntoh56(tvb, offset), 56);
return (gint64)ret;
}
guint64
tvb_get_ntoh64(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, sizeof(guint64));
return pntoh64(ptr);
}
guint16
tvb_get_guint16(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letohs(tvb, offset);
} else {
return tvb_get_ntohs(tvb, offset);
}
}
guint32
tvb_get_guint24(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letoh24(tvb, offset);
} else {
return tvb_get_ntoh24(tvb, offset);
}
}
guint32
tvb_get_guint32(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letohl(tvb, offset);
} else {
return tvb_get_ntohl(tvb, offset);
}
}
guint64
tvb_get_guint40(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letoh40(tvb, offset);
} else {
return tvb_get_ntoh40(tvb, offset);
}
}
gint64
tvb_get_gint40(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letohi40(tvb, offset);
} else {
return tvb_get_ntohi40(tvb, offset);
}
}
guint64
tvb_get_guint48(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letoh48(tvb, offset);
} else {
return tvb_get_ntoh48(tvb, offset);
}
}
gint64
tvb_get_gint48(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letohi48(tvb, offset);
} else {
return tvb_get_ntohi48(tvb, offset);
}
}
guint64
tvb_get_guint56(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letoh56(tvb, offset);
} else {
return tvb_get_ntoh56(tvb, offset);
}
}
gint64
tvb_get_gint56(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letohi56(tvb, offset);
} else {
return tvb_get_ntohi56(tvb, offset);
}
}
guint64
tvb_get_guint64(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letoh64(tvb, offset);
} else {
return tvb_get_ntoh64(tvb, offset);
}
}
gfloat
tvb_get_ieee_float(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letohieee_float(tvb, offset);
} else {
return tvb_get_ntohieee_float(tvb, offset);
}
}
gdouble
tvb_get_ieee_double(tvbuff_t *tvb, const gint offset, const guint encoding) {
if (encoding & ENC_LITTLE_ENDIAN) {
return tvb_get_letohieee_double(tvb, offset);
} else {
return tvb_get_ntohieee_double(tvb, offset);
}
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
return pletoh16(ptr);
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
return pletoh32(ptr);
}
guint64
tvb_get_letoh40(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 5);
return pletoh40(ptr);
}
gint64
tvb_get_letohi40(tvbuff_t *tvb, const gint offset)
{
guint64 ret;
ret = ws_sign_ext64(tvb_get_letoh40(tvb, offset), 40);
return (gint64)ret;
}
guint64
tvb_get_letoh48(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 6);
return pletoh48(ptr);
}
gint64
tvb_get_letohi48(tvbuff_t *tvb, const gint offset)
{
guint64 ret;
ret = ws_sign_ext64(tvb_get_letoh48(tvb, offset), 48);
return (gint64)ret;
}
guint64
tvb_get_letoh56(tvbuff_t *tvb, const gint offset)
{
const guint8 *ptr;
ptr = fast_ensure_contiguous(tvb, offset, 7);
return pletoh56(ptr);
}
gint64
tvb_get_letohi56(tvbuff_t *tvb, const gint offset)
{
guint64 ret;
ret = ws_sign_ext64(tvb_get_letoh56(tvb, offset), 56);
return (gint64)ret;
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
static inline void
validate_single_byte_ascii_encoding(const guint encoding)
{
const guint enc = encoding & ~ENC_STR_MASK;
switch (enc) {
case ENC_UTF_16:
case ENC_UCS_2:
case ENC_UCS_4:
case ENC_3GPP_TS_23_038_7BITS:
case ENC_EBCDIC:
REPORT_DISSECTOR_BUG("Invalid string encoding type passed to tvb_get_string_XXX");
break;
default:
break;
}
if (enc == 0)
REPORT_DISSECTOR_BUG("No string encoding type passed to tvb_get_string_XXX");
}
GByteArray*
tvb_get_string_bytes(tvbuff_t *tvb, const gint offset, const gint length,
const guint encoding, GByteArray *bytes, gint *endoff)
{
const gchar *ptr = (gchar*) tvb_get_raw_string(wmem_packet_scope(), tvb, offset, length);
const gchar *begin = ptr;
const gchar *end = NULL;
GByteArray *retval = NULL;
errno = EDOM;
validate_single_byte_ascii_encoding(encoding);
if (endoff) *endoff = 0;
while (*begin == ' ') begin++;
if (*begin && bytes) {
if (hex_str_to_bytes_encoding(begin, bytes, &end, encoding, FALSE)) {
if (bytes->len > 0) {
if (endoff) *endoff = offset + (gint)(end - ptr);
errno = 0;
retval = bytes;
}
}
}
return retval;
}
nstime_t*
tvb_get_string_time(tvbuff_t *tvb, const gint offset, const gint length,
const guint encoding, nstime_t *ns, gint *endoff)
{
const gchar *begin = (gchar*) tvb_get_raw_string(wmem_packet_scope(), tvb, offset, length);
const gchar *ptr = begin;
const gchar *end = NULL;
struct tm tm;
nstime_t* retval = NULL;
char sign = '+';
int off_hr = 0;
int off_min = 0;
int num_chars = 0;
gboolean matched = FALSE;
errno = EDOM;
validate_single_byte_ascii_encoding(encoding);
DISSECTOR_ASSERT(ns);
memset(&tm, 0, sizeof(tm));
tm.tm_isdst = -1;
ns->secs = 0;
ns->nsecs = 0;
while (*ptr == ' ') ptr++;
if (*ptr) {
if ((encoding & ENC_ISO_8601_DATE_TIME) == ENC_ISO_8601_DATE_TIME) {
if (sscanf(ptr, "%d-%d-%d%*c%d:%d:%d%c%d:%d%n",
&tm.tm_year,
&tm.tm_mon,
&tm.tm_mday,
&tm.tm_hour,
&tm.tm_min,
&tm.tm_sec,
&sign,
&off_hr,
&off_min,
&num_chars) >= 9)
{
matched = TRUE;
}
else if (sscanf(ptr, "%d-%d-%d%*c%d:%d%c%d:%d%n",
&tm.tm_year,
&tm.tm_mon,
&tm.tm_mday,
&tm.tm_hour,
&tm.tm_min,
&sign,
&off_hr,
&off_min,
&num_chars) >= 8)
{
matched = TRUE;
}
else if (sscanf(ptr, "%d-%d-%d%*c%d:%d:%dZ%n",
&tm.tm_year,
&tm.tm_mon,
&tm.tm_mday,
&tm.tm_hour,
&tm.tm_min,
&tm.tm_sec,
&num_chars) >= 6)
{
matched = TRUE;
off_hr = 0;
off_min = 0;
}
else if (sscanf(ptr, "%d-%d-%d%*c%d:%dZ%n",
&tm.tm_year,
&tm.tm_mon,
&tm.tm_mday,
&tm.tm_hour,
&tm.tm_min,
&num_chars) >= 5)
{
matched = TRUE;
off_hr = 0;
off_min = 0;
}
if (matched) {
errno = 0;
end = ptr + num_chars;
tm.tm_mon--;
if (tm.tm_year > 1900) tm.tm_year -= 1900;
if (sign == '-') off_hr = -off_hr;
}
}
else if (encoding & ENC_ISO_8601_DATE) {
if (sscanf(ptr, "%d-%d-%d%n",
&tm.tm_year,
&tm.tm_mon,
&tm.tm_mday,
&num_chars) >= 3)
{
errno = 0;
end = ptr + num_chars;
tm.tm_mon--;
if (tm.tm_year > 1900) tm.tm_year -= 1900;
}
}
else if (encoding & ENC_ISO_8601_TIME) {
if (sscanf(ptr, "%d:%d:%d%n",
&tm.tm_hour,
&tm.tm_min,
&tm.tm_sec,
&num_chars) >= 2)
{
time_t time_now = time(NULL);
struct tm *tm_now = gmtime(&time_now);
if (tm_now != NULL) {
tm.tm_year = tm_now->tm_year;
tm.tm_mon = tm_now->tm_mon;
tm.tm_mday = tm_now->tm_mday;
} else {
tm.tm_year = 69;
tm.tm_mon = 12;
tm.tm_mday = 31;
}
end = ptr + num_chars;
errno = 0;
}
}
else if (encoding & ENC_RFC_822 || encoding & ENC_RFC_1123) {
if (encoding & ENC_RFC_822) {
end = strptime(ptr, "%a, %d %b %y %H:%M:%S", &tm);
if (!end) end = strptime(ptr, "%a, %d %b %y %H:%M", &tm);
if (!end) end = strptime(ptr, "%d %b %y %H:%M:%S", &tm);
if (!end) end = strptime(ptr, "%d %b %y %H:%M", &tm);
}
else if (encoding & ENC_RFC_1123) {
end = strptime(ptr, "%a, %d %b %Y %H:%M:%S", &tm);
if (!end) end = strptime(ptr, "%a, %d %b %Y %H:%M", &tm);
if (!end) end = strptime(ptr, "%d %b %Y %H:%M:%S", &tm);
if (!end) end = strptime(ptr, "%d %b %Y %H:%M", &tm);
}
if (end) {
errno = 0;
if (*end == ' ') end++;
if (g_ascii_strncasecmp(end, "UT", 2) == 0)
{
end += 2;
}
else if (g_ascii_strncasecmp(end, "GMT", 3) == 0)
{
end += 3;
}
else if (sscanf(end, "%c%2d%2d%n",
&sign,
&off_hr,
&off_min,
&num_chars) < 3)
{
errno = ERANGE;
}
if (sign == '-') off_hr = -off_hr;
}
}
}
if (errno == 0) {
ns->secs = mktime_utc (&tm);
if (off_hr > 0)
ns->secs += (off_hr * 3600) + (off_min * 60);
else if (off_hr < 0)
ns->secs -= ((-off_hr) * 3600) + (off_min * 60);
retval = ns;
if (endoff)
*endoff = (gint)(offset + (end - begin));
}
return retval;
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
const guint8 *ptr = ensure_contiguous(tvb, offset, GUID_LEN);
guid->data1 = pntoh32(ptr + 0);
guid->data2 = pntoh16(ptr + 4);
guid->data3 = pntoh16(ptr + 6);
memcpy(guid->data4, ptr + 8, sizeof guid->data4);
}
void
tvb_get_letohguid(tvbuff_t *tvb, const gint offset, e_guid_t *guid)
{
const guint8 *ptr = ensure_contiguous(tvb, offset, GUID_LEN);
guid->data1 = pletoh32(ptr + 0);
guid->data2 = pletoh16(ptr + 4);
guid->data3 = pletoh16(ptr + 6);
memcpy(guid->data4, ptr + 8, sizeof guid->data4);
}
void
tvb_get_guid(tvbuff_t *tvb, const gint offset, e_guid_t *guid, const guint encoding)
{
if (encoding) {
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
ptr = ensure_contiguous(tvb, abs_offset, limit);
result = (const guint8 *) memchr(ptr, needle, limit);
if (!result)
return -1;
return (gint) ((result - ptr) + abs_offset);
}
gint
tvb_find_guint8(tvbuff_t *tvb, const gint offset, const gint maxlength, const guint8 needle)
{
const guint8 *result;
guint abs_offset = 0;
guint limit = 0;
int exception;
DISSECTOR_ASSERT(tvb && tvb->initialized);
exception = compute_offset_and_remaining(tvb, offset, &abs_offset, &limit);
if (exception)
THROW(exception);
if (maxlength >= 0 && limit > (guint) maxlength) {
limit = (guint) maxlength;
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
gint
tvb_find_guint16(tvbuff_t *tvb, const gint offset, const gint maxlength,
const guint16 needle)
{
const guint8 needle1 = ((needle & 0xFF00) >> 8);
const guint8 needle2 = ((needle & 0x00FF) >> 0);
gint searched_bytes = 0;
gint pos = offset;
do {
gint offset1 =
tvb_find_guint8(tvb, pos, maxlength - searched_bytes, needle1);
gint offset2 = -1;
if (offset1 == -1) {
return -1;
}
searched_bytes = offset - pos + 1;
if ((maxlength != -1) && (searched_bytes >= maxlength)) {
return -1;
}
offset2 = tvb_find_guint8(tvb, offset1 + 1, 1, needle2);
searched_bytes += 1;
if (offset2 != -1) {
if ((maxlength != -1) && (searched_bytes > maxlength)) {
return -1;
}
return offset1;
}
pos = offset1 + 1;
} while (searched_bytes < maxlength);
return -1;
}
static inline gint
tvb_ws_mempbrk_guint8_generic(tvbuff_t *tvb, guint abs_offset, guint limit, const ws_mempbrk_pattern* pattern, guchar *found_needle)
{
const guint8 *ptr;
const guint8 *result;
ptr = ensure_contiguous(tvb, abs_offset, limit);
result = ws_mempbrk_exec(ptr, limit, pattern, found_needle);
if (!result)
return -1;
return (gint) ((result - ptr) + abs_offset);
}
gint
tvb_ws_mempbrk_pattern_guint8(tvbuff_t *tvb, const gint offset, const gint maxlength,
const ws_mempbrk_pattern* pattern, guchar *found_needle)
{
const guint8 *result;
guint abs_offset = 0;
guint limit = 0;
int exception;
DISSECTOR_ASSERT(tvb && tvb->initialized);
exception = compute_offset_and_remaining(tvb, offset, &abs_offset, &limit);
if (exception)
THROW(exception);
if (limit > (guint) maxlength) {
limit = maxlength;
}
if (tvb->real_data) {
result = ws_mempbrk_exec(tvb->real_data + abs_offset, limit, pattern, found_needle);
if (result == NULL) {
return -1;
}
else {
return (gint) (result - tvb->real_data);
}
}
if (tvb->ops->tvb_ws_mempbrk_pattern_guint8)
return tvb->ops->tvb_ws_mempbrk_pattern_guint8(tvb, abs_offset, limit, pattern, found_needle);
return tvb_ws_mempbrk_guint8_generic(tvb, abs_offset, limit, pattern, found_needle);
}
guint
tvb_strsize(tvbuff_t *tvb, const gint offset)
{
guint abs_offset = 0, junk_length;
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
guint abs_offset = 0, junk_length;
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
gchar *
tvb_format_text(tvbuff_t *tvb, const gint offset, const gint size)
{
const guint8 *ptr;
gint len;
len = (size > 0) ? size : 0;
ptr = ensure_contiguous(tvb, offset, size);
return format_text(wmem_packet_scope(), ptr, len);
}
gchar *
tvb_format_text_wsp(wmem_allocator_t* allocator, tvbuff_t *tvb, const gint offset, const gint size)
{
const guint8 *ptr;
gint len;
len = (size > 0) ? size : 0;
ptr = ensure_contiguous(tvb, offset, size);
return format_text_wsp(allocator, ptr, len);
}
gchar *
tvb_format_stringzpad(tvbuff_t *tvb, const gint offset, const gint size)
{
const guint8 *ptr, *p;
gint len;
gint stringlen;
len = (size > 0) ? size : 0;
ptr = ensure_contiguous(tvb, offset, size);
for (p = ptr, stringlen = 0; stringlen < len && *p != '\0'; p++, stringlen++)
;
return format_text(wmem_packet_scope(), ptr, stringlen);
}
gchar *
tvb_format_stringzpad_wsp(wmem_allocator_t* allocator, tvbuff_t *tvb, const gint offset, const gint size)
{
const guint8 *ptr, *p;
gint len;
gint stringlen;
len = (size > 0) ? size : 0;
ptr = ensure_contiguous(tvb, offset, size);
for (p = ptr, stringlen = 0; stringlen < len && *p != '\0'; p++, stringlen++)
;
return format_text_wsp(allocator, ptr, stringlen);
}
static guint8 *
tvb_get_ascii_string(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length)
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, length);
return get_ascii_string(scope, ptr, length);
}
static guint8 *
tvb_get_utf_8_string(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, const gint length)
{
guint8 *strbuf;
tvb_ensure_bytes_exist(tvb, offset, length);
strbuf = (guint8 *)wmem_alloc(scope, length + 1);
tvb_memcpy(tvb, strbuf, offset, length);
strbuf[length] = '\0';
return strbuf;
}
static inline guint8 *
tvb_get_raw_string(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, const gint length)
{
guint8 *strbuf;
gint abs_length = length;
DISSECTOR_ASSERT(offset >= 0);
DISSECTOR_ASSERT(abs_length >= -1);
if (abs_length < 0)
abs_length = tvb->length - offset;
tvb_ensure_bytes_exist(tvb, offset, abs_length);
strbuf = (guint8 *)wmem_alloc(scope, abs_length + 1);
tvb_memcpy(tvb, strbuf, offset, abs_length);
strbuf[abs_length] = '\0';
return strbuf;
}
static guint8 *
tvb_get_string_8859_1(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length)
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, length);
return get_8859_1_string(scope, ptr, length);
}
static guint8 *
tvb_get_string_unichar2(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length, const gunichar2 table[0x80])
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, length);
return get_unichar2_string(scope, ptr, length, table);
}
static guint8 *
tvb_get_ucs_2_string(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint length, const guint encoding)
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, length);
return get_ucs_2_string(scope, ptr, length, encoding);
}
static guint8 *
tvb_get_utf_16_string(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint length, const guint encoding)
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, length);
return get_utf_16_string(scope, ptr, length, encoding);
}
static gchar *
tvb_get_ucs_4_string(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint length, const guint encoding)
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, length);
return get_ucs_4_string(scope, ptr, length, encoding);
}
gchar *
tvb_get_ts_23_038_7bits_string(wmem_allocator_t *scope, tvbuff_t *tvb,
const gint bit_offset, gint no_of_chars)
{
gint in_offset = bit_offset >> 3;
gint length = ((no_of_chars + 1) * 7 + (bit_offset & 0x07)) >> 3;
const guint8 *ptr;
DISSECTOR_ASSERT(tvb && tvb->initialized);
ptr = ensure_contiguous(tvb, in_offset, length);
return get_ts_23_038_7bits_string(scope, ptr, bit_offset, no_of_chars);
}
gchar *
tvb_get_ascii_7bits_string(wmem_allocator_t *scope, tvbuff_t *tvb,
const gint bit_offset, gint no_of_chars)
{
gint in_offset = bit_offset >> 3;
gint length = ((no_of_chars + 1) * 7 + (bit_offset & 0x07)) >> 3;
const guint8 *ptr;
DISSECTOR_ASSERT(tvb && tvb->initialized);
ptr = ensure_contiguous(tvb, in_offset, length);
return get_ascii_7bits_string(scope, ptr, bit_offset, no_of_chars);
}
static guint8 *
tvb_get_nonascii_unichar2_string(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length, const gunichar2 table[256])
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, length);
return get_nonascii_unichar2_string(scope, ptr, length, table);
}
static guint8 *
tvb_get_t61_string(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length)
{
const guint8 *ptr;
ptr = ensure_contiguous(tvb, offset, length);
return get_t61_string(scope, ptr, length);
}
guint8 *
tvb_get_string_enc(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset,
const gint length, const guint encoding)
{
guint8 *strptr;
DISSECTOR_ASSERT(tvb && tvb->initialized);
if (length < 0) {
THROW(ReportedBoundsError);
}
switch (encoding & ENC_CHARENCODING_MASK) {
case ENC_ASCII:
default:
strptr = tvb_get_ascii_string(scope, tvb, offset, length);
break;
case ENC_UTF_8:
strptr = tvb_get_utf_8_string(scope, tvb, offset, length);
break;
case ENC_UTF_16:
strptr = tvb_get_utf_16_string(scope, tvb, offset, length,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_UCS_2:
strptr = tvb_get_ucs_2_string(scope, tvb, offset, length,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_UCS_4:
strptr = tvb_get_ucs_4_string(scope, tvb, offset, length,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_ISO_8859_1:
strptr = tvb_get_string_8859_1(scope, tvb, offset, length);
break;
case ENC_ISO_8859_2:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_2);
break;
case ENC_ISO_8859_3:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_3);
break;
case ENC_ISO_8859_4:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_4);
break;
case ENC_ISO_8859_5:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_5);
break;
case ENC_ISO_8859_6:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_6);
break;
case ENC_ISO_8859_7:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_7);
break;
case ENC_ISO_8859_8:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_8);
break;
case ENC_ISO_8859_9:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_9);
break;
case ENC_ISO_8859_10:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_10);
break;
case ENC_ISO_8859_11:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_11);
break;
case ENC_ISO_8859_13:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_13);
break;
case ENC_ISO_8859_14:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_14);
break;
case ENC_ISO_8859_15:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_15);
break;
case ENC_ISO_8859_16:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_iso_8859_16);
break;
case ENC_WINDOWS_1250:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_cp1250);
break;
case ENC_MAC_ROMAN:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_mac_roman);
break;
case ENC_CP437:
strptr = tvb_get_string_unichar2(scope, tvb, offset, length, charset_table_cp437);
break;
case ENC_3GPP_TS_23_038_7BITS:
{
gint bit_offset = offset << 3;
gint no_of_chars = (length << 3) / 7;
strptr = tvb_get_ts_23_038_7bits_string(scope, tvb, bit_offset, no_of_chars);
}
break;
case ENC_ASCII_7BITS:
{
gint bit_offset = offset << 3;
gint no_of_chars = (length << 3) / 7;
strptr = tvb_get_ascii_7bits_string(scope, tvb, bit_offset, no_of_chars);
}
break;
case ENC_EBCDIC:
strptr = tvb_get_nonascii_unichar2_string(scope, tvb, offset, length, charset_table_ebcdic);
break;
case ENC_EBCDIC_CP037:
strptr = tvb_get_nonascii_unichar2_string(scope, tvb, offset, length, charset_table_ebcdic_cp037);
break;
case ENC_T61:
strptr = tvb_get_t61_string(scope, tvb, offset, length);
break;
}
return strptr;
}
guint8 *
tvb_get_stringzpad(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset,
const gint length, const guint encoding)
{
return tvb_get_string_enc(scope, tvb, offset, length, encoding);
}
static guint8 *
tvb_get_ascii_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint *lengthp)
{
guint size;
const guint8 *ptr;
size = tvb_strsize(tvb, offset);
ptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return get_ascii_string(scope, ptr, size);
}
static guint8 *
tvb_get_utf_8_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint *lengthp)
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
static guint8 *
tvb_get_stringz_8859_1(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint *lengthp)
{
guint size;
const guint8 *ptr;
size = tvb_strsize(tvb, offset);
ptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return get_8859_1_string(scope, ptr, size);
}
static guint8 *
tvb_get_stringz_unichar2(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint *lengthp, const gunichar2 table[0x80])
{
guint size;
const guint8 *ptr;
size = tvb_strsize(tvb, offset);
ptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return get_unichar2_string(scope, ptr, size, table);
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
static gchar *
tvb_get_ucs_2_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint *lengthp, const guint encoding)
{
gint size;
const guint8 *ptr;
size = tvb_unicode_strsize(tvb, offset);
ptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return get_ucs_2_string(scope, ptr, size, encoding);
}
static gchar *
tvb_get_utf_16_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint *lengthp, const guint encoding)
{
gint size;
const guint8 *ptr;
size = tvb_unicode_strsize(tvb, offset);
ptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return get_utf_16_string(scope, ptr, size, encoding);
}
static gchar *
tvb_get_ucs_4_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint *lengthp, const guint encoding)
{
gint size;
gunichar uchar;
const guint8 *ptr;
size = 0;
do {
uchar = tvb_get_ntohl(tvb, offset + size);
size += 4;
} while(uchar != 0);
ptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return get_ucs_4_string(scope, ptr, size, encoding);
}
static guint8 *
tvb_get_nonascii_unichar2_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint *lengthp, const gunichar2 table[256])
{
guint size;
const guint8 *ptr;
size = tvb_strsize(tvb, offset);
ptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return get_nonascii_unichar2_string(scope, ptr, size, table);
}
static guint8 *
tvb_get_t61_stringz(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint *lengthp)
{
guint size;
const guint8 *ptr;
size = tvb_strsize(tvb, offset);
ptr = ensure_contiguous(tvb, offset, size);
if (lengthp)
*lengthp = size;
return get_t61_string(scope, ptr, size);
}
guint8 *
tvb_get_stringz_enc(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, gint *lengthp, const guint encoding)
{
guint8 *strptr;
DISSECTOR_ASSERT(tvb && tvb->initialized);
switch (encoding & ENC_CHARENCODING_MASK) {
case ENC_ASCII:
default:
strptr = tvb_get_ascii_stringz(scope, tvb, offset, lengthp);
break;
case ENC_UTF_8:
strptr = tvb_get_utf_8_stringz(scope, tvb, offset, lengthp);
break;
case ENC_UTF_16:
strptr = tvb_get_utf_16_stringz(scope, tvb, offset, lengthp,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_UCS_2:
strptr = tvb_get_ucs_2_stringz(scope, tvb, offset, lengthp,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_UCS_4:
strptr = tvb_get_ucs_4_stringz(scope, tvb, offset, lengthp,
encoding & ENC_LITTLE_ENDIAN);
break;
case ENC_ISO_8859_1:
strptr = tvb_get_stringz_8859_1(scope, tvb, offset, lengthp);
break;
case ENC_ISO_8859_2:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_2);
break;
case ENC_ISO_8859_3:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_3);
break;
case ENC_ISO_8859_4:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_4);
break;
case ENC_ISO_8859_5:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_5);
break;
case ENC_ISO_8859_6:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_6);
break;
case ENC_ISO_8859_7:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_7);
break;
case ENC_ISO_8859_8:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_8);
break;
case ENC_ISO_8859_9:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_9);
break;
case ENC_ISO_8859_10:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_10);
break;
case ENC_ISO_8859_11:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_11);
break;
case ENC_ISO_8859_13:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_13);
break;
case ENC_ISO_8859_14:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_14);
break;
case ENC_ISO_8859_15:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_15);
break;
case ENC_ISO_8859_16:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_iso_8859_16);
break;
case ENC_WINDOWS_1250:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_cp1250);
break;
case ENC_MAC_ROMAN:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_mac_roman);
break;
case ENC_CP437:
strptr = tvb_get_stringz_unichar2(scope, tvb, offset, lengthp, charset_table_cp437);
break;
case ENC_3GPP_TS_23_038_7BITS:
REPORT_DISSECTOR_BUG("TS 23.038 7bits has no null character and doesn't support null-terminated strings");
break;
case ENC_ASCII_7BITS:
REPORT_DISSECTOR_BUG("tvb_get_stringz_enc function with ENC_ASCII_7BITS not implemented yet");
break;
case ENC_EBCDIC:
strptr = tvb_get_nonascii_unichar2_stringz(scope, tvb, offset, lengthp, charset_table_ebcdic);
break;
case ENC_EBCDIC_CP037:
strptr = tvb_get_nonascii_unichar2_stringz(scope, tvb, offset, lengthp, charset_table_ebcdic_cp037);
break;
case ENC_T61:
strptr = tvb_get_t61_stringz(scope, tvb, offset, lengthp);
break;
}
return strptr;
}
static gint
_tvb_get_nstringz(tvbuff_t *tvb, const gint offset, const guint bufsize, guint8* buffer, gint *bytes_copied)
{
gint stringlen;
guint abs_offset = 0;
gint limit, len = 0;
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
tvb_get_nstringz(tvbuff_t *tvb, const gint offset, const guint bufsize, guint8 *buffer)
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
static gboolean compiled = FALSE;
DISSECTOR_ASSERT(tvb && tvb->initialized);
if (len == -1) {
len = _tvb_captured_length_remaining(tvb, offset);
}
eob_offset = offset + len;
if (!compiled) {
ws_mempbrk_compile(&pbrk_crlf, "\r\n");
compiled = TRUE;
}
eol_offset = tvb_ws_mempbrk_pattern_guint8(tvb, offset, len, &pbrk_crlf, &found_needle);
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
static gboolean compiled = FALSE;
DISSECTOR_ASSERT(tvb && tvb->initialized);
if (len == -1)
len = _tvb_captured_length_remaining(tvb, offset);
if (!compiled) {
ws_mempbrk_compile(&pbrk_crlf_dquote, "\r\n\"");
compiled = TRUE;
}
eob_offset = offset + len;
cur_offset = offset;
is_quoted = FALSE;
for (;;) {
if (is_quoted) {
char_offset = tvb_find_guint8(tvb, cur_offset, len,
'"');
} else {
char_offset = tvb_ws_mempbrk_pattern_guint8(tvb, cur_offset, len, &pbrk_crlf_dquote, &c);
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
DISSECTOR_ASSERT(tvb && tvb->initialized);
tvb_len = tvb->length;
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
int
tvb_skip_guint8(tvbuff_t *tvb, int offset, const int maxlength, const guint8 ch)
{
int end, tvb_len;
DISSECTOR_ASSERT(tvb && tvb->initialized);
tvb_len = tvb->length;
end = offset + maxlength;
if (end >= tvb_len)
end = tvb_len;
while (offset < end) {
guint8 tempch = tvb_get_guint8(tvb, offset);
if (tempch != ch)
break;
offset++;
}
return offset;
}
gchar *
tvb_bytes_to_str_punct(wmem_allocator_t *scope, tvbuff_t *tvb, const gint offset, const gint len, const gchar punct)
{
return bytestring_to_str(scope, ensure_contiguous(tvb, offset, len), len, punct);
}
const gchar *
tvb_bcd_dig_to_wmem_packet_str(tvbuff_t *tvb, const gint offset, const gint len, const dgt_set_t *dgt, gboolean skip_first)
{
int length;
guint8 octet;
int i = 0;
char *digit_str;
gint t_offset = offset;
DISSECTOR_ASSERT(tvb && tvb->initialized);
if (!dgt)
dgt = &Dgt1_9_bcd;
if (len == -1) {
length = tvb->length;
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
if (t_offset == length - 1 && octet == 0x0f) {
break;
}
digit_str[i] = dgt->out[octet & 0x0f];
i++;
t_offset++;
}
digit_str[i]= '\0';
return digit_str;
}
gchar *tvb_bytes_to_str(wmem_allocator_t *allocator, tvbuff_t *tvb,
const gint offset, const gint len)
{
return bytes_to_str(allocator, ensure_contiguous(tvb, offset, len), len);
}
gint
tvb_find_tvb(tvbuff_t *haystack_tvb, tvbuff_t *needle_tvb, const gint haystack_offset)
{
guint haystack_abs_offset = 0, haystack_abs_length = 0;
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
gint
tvb_raw_offset(tvbuff_t *tvb)
{
return ((tvb->raw_offset==-1) ? (tvb->raw_offset = tvb_offset_from_real_beginning(tvb)) : tvb->raw_offset);
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
