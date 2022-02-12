int ia_css_queue_load(
struct ia_css_queue *rdesc,
ia_css_circbuf_desc_t *cb_desc,
uint32_t ignore_desc_flags)
{
if (rdesc == NULL || cb_desc == NULL)
return EINVAL;
if (rdesc->location == IA_CSS_QUEUE_LOC_SP) {
assert(ignore_desc_flags <= QUEUE_IGNORE_DESC_FLAGS_MAX);
if (0 == (ignore_desc_flags & QUEUE_IGNORE_SIZE_FLAG)) {
cb_desc->size = sp_dmem_load_uint8(rdesc->proc_id,
rdesc->desc.remote.cb_desc_addr
+ offsetof(ia_css_circbuf_desc_t, size));
if (0 == cb_desc->size) {
return EDOM;
}
}
if (0 == (ignore_desc_flags & QUEUE_IGNORE_START_FLAG))
cb_desc->start = sp_dmem_load_uint8(rdesc->proc_id,
rdesc->desc.remote.cb_desc_addr
+ offsetof(ia_css_circbuf_desc_t, start));
if (0 == (ignore_desc_flags & QUEUE_IGNORE_END_FLAG))
cb_desc->end = sp_dmem_load_uint8(rdesc->proc_id,
rdesc->desc.remote.cb_desc_addr
+ offsetof(ia_css_circbuf_desc_t, end));
if (0 == (ignore_desc_flags & QUEUE_IGNORE_STEP_FLAG))
cb_desc->step = sp_dmem_load_uint8(rdesc->proc_id,
rdesc->desc.remote.cb_desc_addr
+ offsetof(ia_css_circbuf_desc_t, step));
} else if (rdesc->location == IA_CSS_QUEUE_LOC_HOST) {
mmgr_load(rdesc->desc.remote.cb_desc_addr,
(void *)cb_desc,
sizeof(ia_css_circbuf_desc_t));
} else if (rdesc->location == IA_CSS_QUEUE_LOC_ISP) {
return ENOTSUP;
}
return 0;
}
int ia_css_queue_store(
struct ia_css_queue *rdesc,
ia_css_circbuf_desc_t *cb_desc,
uint32_t ignore_desc_flags)
{
if (rdesc == NULL || cb_desc == NULL)
return EINVAL;
if (rdesc->location == IA_CSS_QUEUE_LOC_SP) {
assert(ignore_desc_flags <= QUEUE_IGNORE_DESC_FLAGS_MAX);
if (0 == (ignore_desc_flags & QUEUE_IGNORE_SIZE_FLAG))
sp_dmem_store_uint8(rdesc->proc_id,
rdesc->desc.remote.cb_desc_addr
+ offsetof(ia_css_circbuf_desc_t, size),
cb_desc->size);
if (0 == (ignore_desc_flags & QUEUE_IGNORE_START_FLAG))
sp_dmem_store_uint8(rdesc->proc_id,
rdesc->desc.remote.cb_desc_addr
+ offsetof(ia_css_circbuf_desc_t, start),
cb_desc->start);
if (0 == (ignore_desc_flags & QUEUE_IGNORE_END_FLAG))
sp_dmem_store_uint8(rdesc->proc_id,
rdesc->desc.remote.cb_desc_addr
+ offsetof(ia_css_circbuf_desc_t, end),
cb_desc->end);
if (0 == (ignore_desc_flags & QUEUE_IGNORE_STEP_FLAG))
sp_dmem_store_uint8(rdesc->proc_id,
rdesc->desc.remote.cb_desc_addr
+ offsetof(ia_css_circbuf_desc_t, step),
cb_desc->step);
} else if (rdesc->location == IA_CSS_QUEUE_LOC_HOST) {
mmgr_store(rdesc->desc.remote.cb_desc_addr,
(void *)cb_desc,
sizeof(ia_css_circbuf_desc_t));
} else if (rdesc->location == IA_CSS_QUEUE_LOC_ISP) {
return ENOTSUP;
}
return 0;
}
int ia_css_queue_item_load(
struct ia_css_queue *rdesc,
uint8_t position,
ia_css_circbuf_elem_t *item)
{
if (rdesc == NULL || item == NULL)
return EINVAL;
if (rdesc->location == IA_CSS_QUEUE_LOC_SP) {
sp_dmem_load(rdesc->proc_id,
rdesc->desc.remote.cb_elems_addr
+ position * sizeof(ia_css_circbuf_elem_t),
item,
sizeof(ia_css_circbuf_elem_t));
} else if (rdesc->location == IA_CSS_QUEUE_LOC_HOST) {
mmgr_load(rdesc->desc.remote.cb_elems_addr
+ position * sizeof(ia_css_circbuf_elem_t),
(void *)item,
sizeof(ia_css_circbuf_elem_t));
} else if (rdesc->location == IA_CSS_QUEUE_LOC_ISP) {
return ENOTSUP;
}
return 0;
}
int ia_css_queue_item_store(
struct ia_css_queue *rdesc,
uint8_t position,
ia_css_circbuf_elem_t *item)
{
if (rdesc == NULL || item == NULL)
return EINVAL;
if (rdesc->location == IA_CSS_QUEUE_LOC_SP) {
sp_dmem_store(rdesc->proc_id,
rdesc->desc.remote.cb_elems_addr
+ position * sizeof(ia_css_circbuf_elem_t),
item,
sizeof(ia_css_circbuf_elem_t));
} else if (rdesc->location == IA_CSS_QUEUE_LOC_HOST) {
mmgr_store(rdesc->desc.remote.cb_elems_addr
+ position * sizeof(ia_css_circbuf_elem_t),
(void *)item,
sizeof(ia_css_circbuf_elem_t));
} else if (rdesc->location == IA_CSS_QUEUE_LOC_ISP) {
return ENOTSUP;
}
return 0;
}
