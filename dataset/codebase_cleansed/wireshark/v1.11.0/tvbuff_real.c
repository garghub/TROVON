static void
real_free(tvbuff_t *tvb)
{
struct tvb_real *real_tvb = (struct tvb_real *) tvb;
if (real_tvb->free_cb) {
real_tvb->free_cb((gpointer)tvb->real_data);
}
}
static guint
real_offset(const tvbuff_t *tvb _U_, const guint counter)
{
return counter;
}
tvbuff_t *
tvb_new_real_data(const guint8* data, const guint length, const gint reported_length)
{
tvbuff_t *tvb;
struct tvb_real *real_tvb;
THROW_ON(reported_length < -1, ReportedBoundsError);
tvb = tvb_new(&tvb_real_ops);
tvb->real_data = data;
tvb->length = length;
tvb->reported_length = reported_length;
tvb->initialized = TRUE;
tvb->ds_tvb = tvb;
real_tvb = (struct tvb_real *) tvb;
real_tvb->free_cb = NULL;
return tvb;
}
void
tvb_set_free_cb(tvbuff_t *tvb, const tvbuff_free_cb_t func)
{
struct tvb_real *real_tvb = (struct tvb_real *) tvb;
DISSECTOR_ASSERT(tvb);
DISSECTOR_ASSERT(tvb->ops == &tvb_real_ops);
real_tvb->free_cb = func;
}
void
tvb_set_child_real_data_tvbuff(tvbuff_t *parent, tvbuff_t *child)
{
DISSECTOR_ASSERT(parent && child);
DISSECTOR_ASSERT(parent->initialized);
DISSECTOR_ASSERT(child->initialized);
DISSECTOR_ASSERT(child->ops == &tvb_real_ops);
tvb_add_to_chain(parent, child);
}
tvbuff_t *
tvb_new_child_real_data(tvbuff_t *parent, const guint8* data, const guint length, const gint reported_length)
{
tvbuff_t *tvb = tvb_new_real_data(data, length, reported_length);
tvb_set_child_real_data_tvbuff(parent, tvb);
return tvb;
}
