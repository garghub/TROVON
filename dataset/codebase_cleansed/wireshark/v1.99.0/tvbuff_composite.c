static void
composite_free(tvbuff_t *tvb)
{
struct tvb_composite *composite_tvb = (struct tvb_composite *) tvb;
tvb_comp_t *composite = &composite_tvb->composite;
g_slist_free(composite->tvbs);
g_free(composite->start_offsets);
g_free(composite->end_offsets);
if (tvb->real_data) {
g_free((gpointer)tvb->real_data);
}
}
static guint
composite_offset(const tvbuff_t *tvb, const guint counter)
{
const struct tvb_composite *composite_tvb = (const struct tvb_composite *) tvb;
const tvbuff_t *member = (const tvbuff_t *)composite_tvb->composite.tvbs->data;
return tvb_offset_from_real_beginning_counter(member, counter);
}
static const guint8*
composite_get_ptr(tvbuff_t *tvb, guint abs_offset, guint abs_length)
{
struct tvb_composite *composite_tvb = (struct tvb_composite *) tvb;
guint i, num_members;
tvb_comp_t *composite;
tvbuff_t *member_tvb = NULL;
guint member_offset;
GSList *slist;
composite = &composite_tvb->composite;
num_members = g_slist_length(composite->tvbs);
for (i = 0; i < num_members; i++) {
if (abs_offset <= composite->end_offsets[i]) {
slist = g_slist_nth(composite->tvbs, i);
member_tvb = (tvbuff_t *)slist->data;
break;
}
}
if (!member_tvb) {
DISSECTOR_ASSERT(abs_offset == tvb->length && abs_length == 0);
return "";
}
member_offset = abs_offset - composite->start_offsets[i];
if (tvb_bytes_exist(member_tvb, member_offset, abs_length)) {
DISSECTOR_ASSERT(!tvb->real_data);
return tvb_get_ptr(member_tvb, member_offset, abs_length);
}
else {
tvb->real_data = (guint8 *)tvb_memdup(NULL, tvb, 0, -1);
return tvb->real_data + abs_offset;
}
DISSECTOR_ASSERT_NOT_REACHED();
}
static void *
composite_memcpy(tvbuff_t *tvb, void* _target, guint abs_offset, guint abs_length)
{
struct tvb_composite *composite_tvb = (struct tvb_composite *) tvb;
guint8 *target = (guint8 *) _target;
guint i, num_members;
tvb_comp_t *composite;
tvbuff_t *member_tvb = NULL;
guint member_offset, member_length;
GSList *slist;
composite = &composite_tvb->composite;
num_members = g_slist_length(composite->tvbs);
for (i = 0; i < num_members; i++) {
if (abs_offset <= composite->end_offsets[i]) {
slist = g_slist_nth(composite->tvbs, i);
member_tvb = (tvbuff_t *)slist->data;
break;
}
}
if (!member_tvb) {
DISSECTOR_ASSERT(abs_offset == tvb->length && abs_length == 0);
return target;
}
member_offset = abs_offset - composite->start_offsets[i];
if (tvb_bytes_exist(member_tvb, member_offset, abs_length)) {
DISSECTOR_ASSERT(!tvb->real_data);
return tvb_memcpy(member_tvb, target, member_offset, abs_length);
}
else {
member_length = tvb_length_remaining(member_tvb, member_offset);
DISSECTOR_ASSERT(member_length > 0);
tvb_memcpy(member_tvb, target, member_offset, member_length);
abs_offset += member_length;
abs_length -= member_length;
if (abs_length > 0) {
composite_memcpy(tvb, target + member_length, abs_offset, abs_length);
}
return target;
}
DISSECTOR_ASSERT_NOT_REACHED();
}
tvbuff_t *
tvb_new_composite(void)
{
tvbuff_t *tvb = tvb_new(&tvb_composite_ops);
struct tvb_composite *composite_tvb = (struct tvb_composite *) tvb;
tvb_comp_t *composite = &composite_tvb->composite;
composite->tvbs = NULL;
composite->start_offsets = NULL;
composite->end_offsets = NULL;
return tvb;
}
void
tvb_composite_append(tvbuff_t *tvb, tvbuff_t *member)
{
struct tvb_composite *composite_tvb = (struct tvb_composite *) tvb;
tvb_comp_t *composite;
DISSECTOR_ASSERT(tvb && !tvb->initialized);
DISSECTOR_ASSERT(tvb->ops == &tvb_composite_ops);
DISSECTOR_ASSERT(member->length);
composite = &composite_tvb->composite;
composite->tvbs = g_slist_append(composite->tvbs, member);
}
void
tvb_composite_prepend(tvbuff_t *tvb, tvbuff_t *member)
{
struct tvb_composite *composite_tvb = (struct tvb_composite *) tvb;
tvb_comp_t *composite;
DISSECTOR_ASSERT(tvb && !tvb->initialized);
DISSECTOR_ASSERT(tvb->ops == &tvb_composite_ops);
DISSECTOR_ASSERT(member->length);
composite = &composite_tvb->composite;
composite->tvbs = g_slist_prepend(composite->tvbs, member);
}
void
tvb_composite_finalize(tvbuff_t *tvb)
{
struct tvb_composite *composite_tvb = (struct tvb_composite *) tvb;
GSList *slist;
guint num_members;
tvbuff_t *member_tvb;
tvb_comp_t *composite;
int i = 0;
DISSECTOR_ASSERT(tvb && !tvb->initialized);
DISSECTOR_ASSERT(tvb->ops == &tvb_composite_ops);
DISSECTOR_ASSERT(tvb->length == 0);
DISSECTOR_ASSERT(tvb->reported_length == 0);
composite = &composite_tvb->composite;
num_members = g_slist_length(composite->tvbs);
DISSECTOR_ASSERT(num_members);
composite->start_offsets = g_new(guint, num_members);
composite->end_offsets = g_new(guint, num_members);
for (slist = composite->tvbs; slist != NULL; slist = slist->next) {
DISSECTOR_ASSERT((guint) i < num_members);
member_tvb = (tvbuff_t *)slist->data;
composite->start_offsets[i] = tvb->length;
tvb->length += member_tvb->length;
tvb->reported_length += member_tvb->reported_length;
composite->end_offsets[i] = tvb->length - 1;
i++;
}
DISSECTOR_ASSERT(composite->tvbs);
tvb_add_to_chain((tvbuff_t *)composite->tvbs->data, tvb);
tvb->initialized = TRUE;
}
