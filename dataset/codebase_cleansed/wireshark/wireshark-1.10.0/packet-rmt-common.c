void rmt_ext_parse(GArray *a, tvbuff_t *tvb, guint *offset, guint offset_max)
{
struct _ext e;
while (*offset < offset_max)
{
memset(&e, 0, sizeof(struct _ext));
e.offset = *offset;
e.het = tvb_get_guint8(tvb, *offset);
if (e.het <= 127) {
e.hel = tvb_get_guint8(tvb, *offset+1);
e.hec_offset = *offset + 2;
e.hec_size = e.hel * 4 - 2;
e.length = e.hel * 4;
} else {
e.hel = 1;
e.hec_offset = *offset + 1;
e.hec_size = 3;
e.length = 4;
}
if (e.length == 0)
break;
g_array_append_val(a, e);
*offset += e.length;
}
}
void rmt_ext_decode_default_header(struct _ext *e, tvbuff_t *tvb, proto_tree *tree)
{
if (tree)
{
proto_tree_add_text(tree, tvb, e->offset, 1, "Header Extension Type (HET): %u", e->het);
if (e->het <= 127)
proto_tree_add_text(tree, tvb, e->offset+1, 1, "Header Extension Length (HEL): %u", e->hel);
}
}
void rmt_ext_decode_default_subtree(struct _ext *e, tvbuff_t *tvb, proto_item *ti, gint ett)
{
proto_tree *ext_tree;
ext_tree = proto_item_add_subtree(ti, ett);
rmt_ext_decode_default_header(e, tvb, ext_tree);
if (ext_tree)
proto_tree_add_text(ext_tree, tvb, e->hec_offset, e->hec_size,
"Header Extension Content (HEC): %s", tvb_bytes_to_str(tvb, e->hec_offset, e->hec_size));
}
void rmt_ext_decode_default(struct _ext *e, tvbuff_t *tvb, proto_tree *tree, gint ett)
{
proto_item *ti;
if (tree)
{
ti = proto_tree_add_text(tree, tvb, e->offset, e->length,
"Unknown extension (%u)", e->het);
rmt_ext_decode_default_subtree(e, tvb, ti, ett);
}
}
