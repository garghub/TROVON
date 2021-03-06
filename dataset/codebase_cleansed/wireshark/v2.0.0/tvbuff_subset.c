static guint
subset_offset(const tvbuff_t *tvb, const guint counter)
{
const struct tvb_subset *subset_tvb = (const struct tvb_subset *) tvb;
const tvbuff_t *member = subset_tvb->subset.tvb;
return tvb_offset_from_real_beginning_counter(member, counter + subset_tvb->subset.offset);
}
static void *
subset_memcpy(tvbuff_t *tvb, void *target, guint abs_offset, guint abs_length)
{
struct tvb_subset *subset_tvb = (struct tvb_subset *) tvb;
return tvb_memcpy(subset_tvb->subset.tvb, target, subset_tvb->subset.offset + abs_offset, abs_length);
}
static const guint8 *
subset_get_ptr(tvbuff_t *tvb, guint abs_offset, guint abs_length)
{
struct tvb_subset *subset_tvb = (struct tvb_subset *) tvb;
return tvb_get_ptr(subset_tvb->subset.tvb, subset_tvb->subset.offset + abs_offset, abs_length);
}
static gint
subset_find_guint8(tvbuff_t *tvb, guint abs_offset, guint limit, guint8 needle)
{
struct tvb_subset *subset_tvb = (struct tvb_subset *) tvb;
return tvb_find_guint8(subset_tvb->subset.tvb, subset_tvb->subset.offset + abs_offset, limit, needle);
}
static gint
subset_pbrk_guint8(tvbuff_t *tvb, guint abs_offset, guint limit, const ws_mempbrk_pattern* pattern, guchar *found_needle)
{
struct tvb_subset *subset_tvb = (struct tvb_subset *) tvb;
return tvb_ws_mempbrk_pattern_guint8(subset_tvb->subset.tvb, subset_tvb->subset.offset + abs_offset, limit, pattern, found_needle);
}
static tvbuff_t *
subset_clone(tvbuff_t *tvb, guint abs_offset, guint abs_length)
{
struct tvb_subset *subset_tvb = (struct tvb_subset *) tvb;
return tvb_clone_offset_len(subset_tvb->subset.tvb, subset_tvb->subset.offset + abs_offset, abs_length);
}
static tvbuff_t *
tvb_new_with_subset(tvbuff_t *backing, const gint reported_length,
const guint subset_tvb_offset, const guint subset_tvb_length)
{
tvbuff_t *tvb = tvb_new(&tvb_subset_ops);
struct tvb_subset *subset_tvb = (struct tvb_subset *) tvb;
subset_tvb->subset.offset = subset_tvb_offset;
subset_tvb->subset.length = subset_tvb_length;
subset_tvb->subset.tvb = backing;
tvb->length = subset_tvb_length;
tvb->flags = backing->flags;
if (reported_length == -1) {
tvb->reported_length = backing->reported_length - subset_tvb_offset;
}
else {
tvb->reported_length = reported_length;
}
tvb->initialized = TRUE;
if (backing->real_data != NULL) {
tvb->real_data = backing->real_data + subset_tvb_offset;
}
tvb->ds_tvb = backing->ds_tvb;
return tvb;
}
tvbuff_t *
tvb_new_subset(tvbuff_t *backing, const gint backing_offset, const gint backing_length, const gint reported_length)
{
tvbuff_t *tvb;
guint subset_tvb_offset;
guint subset_tvb_length;
DISSECTOR_ASSERT(backing && backing->initialized);
THROW_ON(reported_length < -1, ReportedBoundsError);
tvb_check_offset_length(backing, backing_offset, backing_length,
&subset_tvb_offset,
&subset_tvb_length);
tvb = tvb_new_with_subset(backing, reported_length,
subset_tvb_offset, subset_tvb_length);
tvb_add_to_chain(backing, tvb);
return tvb;
}
tvbuff_t *
tvb_new_subset_length(tvbuff_t *backing, const gint backing_offset, const gint backing_length)
{
gint captured_length;
tvbuff_t *tvb;
guint subset_tvb_offset;
guint subset_tvb_length;
DISSECTOR_ASSERT(backing && backing->initialized);
THROW_ON(backing_length < 0, ReportedBoundsError);
captured_length = tvb_captured_length_remaining(backing, backing_offset);
THROW_ON(captured_length < 0, BoundsError);
if (captured_length > backing_length)
captured_length = backing_length;
tvb_check_offset_length(backing, backing_offset, captured_length,
&subset_tvb_offset,
&subset_tvb_length);
tvb = tvb_new_with_subset(backing, backing_length,
subset_tvb_offset, subset_tvb_length);
tvb_add_to_chain(backing, tvb);
return tvb;
}
tvbuff_t *
tvb_new_subset_remaining(tvbuff_t *backing, const gint backing_offset)
{
tvbuff_t *tvb;
guint subset_tvb_offset;
guint subset_tvb_length;
tvb_check_offset_length(backing, backing_offset, -1 ,
&subset_tvb_offset,
&subset_tvb_length);
tvb = tvb_new_with_subset(backing, -1 ,
subset_tvb_offset, subset_tvb_length);
tvb_add_to_chain(backing, tvb);
return tvb;
}
tvbuff_t *
tvb_new_proxy(tvbuff_t *backing)
{
tvbuff_t *tvb;
if (backing)
tvb = tvb_new_with_subset(backing, backing->reported_length, 0, backing->length);
else
tvb = tvb_new_real_data(NULL, 0, 0);
tvb->ds_tvb = tvb;
return tvb;
}
