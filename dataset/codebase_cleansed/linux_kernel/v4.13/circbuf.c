void
ia_css_circbuf_create(ia_css_circbuf_t *cb,
ia_css_circbuf_elem_t *elems,
ia_css_circbuf_desc_t *desc)
{
uint32_t i;
OP___assert(desc);
cb->desc = desc;
cb->desc->start = 0;
cb->desc->end = 0;
cb->desc->step = 0;
for (i = 0; i < cb->desc->size; i++)
ia_css_circbuf_elem_init(&elems[i]);
cb->elems = elems;
}
void ia_css_circbuf_destroy(ia_css_circbuf_t *cb)
{
cb->desc = NULL;
cb->elems = NULL;
}
uint32_t ia_css_circbuf_pop(ia_css_circbuf_t *cb)
{
uint32_t ret;
ia_css_circbuf_elem_t elem;
assert(!ia_css_circbuf_is_empty(cb));
elem = ia_css_circbuf_read(cb);
ret = ia_css_circbuf_elem_get_val(&elem);
return ret;
}
uint32_t ia_css_circbuf_extract(ia_css_circbuf_t *cb, int offset)
{
int max_offset;
uint32_t val;
uint32_t pos;
uint32_t src_pos;
uint32_t dest_pos;
max_offset = ia_css_circbuf_get_offset(cb, cb->desc->start, cb->desc->end);
max_offset--;
if (offset == 0) {
val = ia_css_circbuf_pop(cb);
return val;
}
if (offset > max_offset) {
val = 0;
return val;
}
pos = ia_css_circbuf_get_pos_at_offset(cb, cb->desc->start, offset);
val = ia_css_circbuf_elem_get_val(&cb->elems[pos]);
src_pos = ia_css_circbuf_get_pos_at_offset(cb, pos, -1);
dest_pos = pos;
ia_css_circbuf_shift_chunk(cb, src_pos, dest_pos);
return val;
}
uint32_t ia_css_circbuf_peek(ia_css_circbuf_t *cb, int offset)
{
int pos;
pos = ia_css_circbuf_get_pos_at_offset(cb, cb->desc->end, offset);
return cb->elems[pos].val;
}
uint32_t ia_css_circbuf_peek_from_start(ia_css_circbuf_t *cb, int offset)
{
int pos;
pos = ia_css_circbuf_get_pos_at_offset(cb, cb->desc->start, offset);
return cb->elems[pos].val;
}
bool ia_css_circbuf_increase_size(
ia_css_circbuf_t *cb,
unsigned int sz_delta,
ia_css_circbuf_elem_t *elems)
{
uint8_t curr_size;
uint8_t curr_end;
unsigned int i = 0;
if (!cb || sz_delta == 0)
return false;
curr_size = cb->desc->size;
curr_end = cb->desc->end;
if (((uint8_t)(cb->desc->size + (uint8_t)sz_delta) > cb->desc->size) && ((uint8_t)sz_delta == sz_delta))
cb->desc->size += (uint8_t)sz_delta;
else
return false;
if (elems) {
for (i = curr_size; i < cb->desc->size; i++)
cb->elems[i] = elems[i - curr_size];
}
if (curr_end < cb->desc->start) {
if (curr_end == 0) {
cb->desc->end = curr_size;
} else {
ia_css_circbuf_shift_chunk(cb,
curr_size - 1,
curr_size + sz_delta - 1);
}
}
return true;
}
static inline uint32_t
ia_css_circbuf_elem_get_val(ia_css_circbuf_elem_t *elem)
{
return elem->val;
}
static inline ia_css_circbuf_elem_t
ia_css_circbuf_read(ia_css_circbuf_t *cb)
{
ia_css_circbuf_elem_t elem;
elem = cb->elems[cb->desc->start];
ia_css_circbuf_elem_init(&cb->elems[cb->desc->start]);
cb->desc->start = ia_css_circbuf_get_pos_at_offset(cb, cb->desc->start, 1);
return elem;
}
static inline void
ia_css_circbuf_shift_chunk(ia_css_circbuf_t *cb,
uint32_t chunk_src, uint32_t chunk_dest)
{
int chunk_offset;
int chunk_sz;
int i;
chunk_offset = ia_css_circbuf_get_offset(cb,
chunk_src, chunk_dest);
chunk_sz = ia_css_circbuf_get_offset(cb, cb->desc->start, chunk_src) + 1;
for (i = 0; i < chunk_sz; i++) {
ia_css_circbuf_elem_cpy(&cb->elems[chunk_src],
&cb->elems[chunk_dest]);
ia_css_circbuf_elem_init(&cb->elems[chunk_src]);
chunk_src = ia_css_circbuf_get_pos_at_offset(cb, chunk_src, -1);
chunk_dest = ia_css_circbuf_get_pos_at_offset(cb, chunk_dest, -1);
}
cb->desc->start = ia_css_circbuf_get_pos_at_offset(cb, cb->desc->start, chunk_offset);
}
