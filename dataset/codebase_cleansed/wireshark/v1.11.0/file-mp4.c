static gint
dissect_mp4_mvhd_body(tvbuff_t *tvb, gint offset, gint len _U_,
packet_info *pinfo _U_, proto_tree *tree)
{
gint offset_start;
offset_start = offset;
proto_tree_add_item(tree, hf_mp4_full_box_ver,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 3;
return offset-offset_start;
}
static gint
dissect_mp4_mfhd_body(tvbuff_t *tvb, gint offset, gint len _U_,
packet_info *pinfo _U_, proto_tree *tree)
{
gint offset_start;
offset_start = offset;
proto_tree_add_item(tree, hf_mp4_full_box_ver,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 3;
proto_tree_add_item(tree, hf_mp4_mfhd_seq_num,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset-offset_start;
}
static gint
dissect_mp4_ftyp_body(tvbuff_t *tvb, gint offset, gint len,
packet_info *pinfo _U_, proto_tree *tree)
{
gint offset_start;
offset_start = offset;
proto_tree_add_item(tree, hf_mp4_ftyp_brand,
tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_mp4_ftyp_ver,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
while ((offset-offset_start) < len) {
proto_tree_add_item(tree, hf_mp4_ftyp_add_brand,
tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
}
return offset - offset_start;
}
static gint
dissect_mp4_box(guint32 parent_box_type _U_,
tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree)
{
gint offset_start;
guint64 box_size;
guint32 box_type;
guint8 *box_type_str;
proto_item *type_pi, *size_pi, *ext_size_pi = NULL;
proto_tree *box_tree;
gint ret;
gint body_size;
offset_start = offset;
box_size = (guint64)tvb_get_ntohl(tvb, offset);
if ((box_size != BOX_SIZE_EXTENDED) && (box_size < MIN_BOX_SIZE))
return -1;
box_type = tvb_get_ntohl(tvb, offset+4);
box_type_str = tvb_get_string(wmem_packet_scope(), tvb, offset+4, 4);
type_pi = proto_tree_add_text(tree, tvb, offset, -1, "%s (%s)",
val_to_str_const(box_type, box_types, "unknown"), box_type_str);
box_tree = proto_item_add_subtree(type_pi, ett_mp4_box);
size_pi = proto_tree_add_item(box_tree, hf_mp4_box_size,
tvb, offset, 4, ENC_BIG_ENDIAN);
if (box_size == BOX_SIZE_EXTENDED)
proto_item_append_text(size_pi, " (actual size is in largesize)");
offset += 4;
proto_tree_add_item(box_tree, hf_mp4_box_type_str,
tvb, offset, 4, ENC_ASCII|ENC_NA);
offset += 4;
if (box_size == BOX_SIZE_EXTENDED) {
box_size = tvb_get_ntoh64(tvb, offset);
ext_size_pi = proto_tree_add_item(box_tree, hf_mp4_box_largesize,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
}
if (box_size > G_MAXINT) {
expert_add_info(pinfo, ext_size_pi, &ei_mp4_box_too_large);
return -1;
}
proto_item_set_len(type_pi, (gint)box_size);
body_size = (gint)box_size - (offset-offset_start);
switch (box_type) {
case BOX_TYPE_FTYP:
dissect_mp4_ftyp_body(tvb, offset, body_size, pinfo, box_tree);
break;
case BOX_TYPE_MVHD:
dissect_mp4_mvhd_body(tvb, offset, body_size, pinfo, box_tree);
break;
case BOX_TYPE_MFHD:
dissect_mp4_mfhd_body(tvb, offset, body_size, pinfo, box_tree);
break;
case BOX_TYPE_MOOV:
case BOX_TYPE_MOOF:
case BOX_TYPE_STBL:
case BOX_TYPE_MDIA:
case BOX_TYPE_TRAK:
case BOX_TYPE_TRAF:
case BOX_TYPE_MINF:
case BOX_TYPE_MVEX:
case BOX_TYPE_DINF:
case BOX_TYPE_UDTA:
while (offset-offset_start < (gint)box_size) {
ret = dissect_mp4_box(box_type, tvb, offset, pinfo, box_tree);
if (ret <= 0)
break;
offset += ret;
}
break;
default:
break;
}
return (gint)box_size;
}
static int
dissect_mp4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
guint32 box_type;
proto_item *pi;
proto_tree *mp4_tree;
gint ret;
if (tvb_reported_length(tvb) < MIN_BOX_SIZE)
return 0;
box_type = tvb_get_ntohl(tvb, 4);
if (try_val_to_str(box_type, box_types) == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MP4");
col_clear(pinfo->cinfo, COL_INFO);
pi = proto_tree_add_protocol_format(tree, proto_mp4,
tvb, 0, (gint)tvb_reported_length(tvb), "MP4");
mp4_tree = proto_item_add_subtree(pi, ett_mp4);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
ret = dissect_mp4_box(BOX_TYPE_NONE, tvb, offset, pinfo, mp4_tree);
if (ret <= 0)
break;
offset += ret;
}
return offset;
}
void
proto_register_mp4(void)
{
static hf_register_info hf[] = {
{ &hf_mp4_box_size,
{ "Box size", "mp4.box.size", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL } },
{ &hf_mp4_box_type_str,
{ "Box type", "mp4.box.type_str", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_mp4_box_largesize,
{ "Box size (largesize)", "mp4.box.largesize", FT_UINT64, BASE_DEC,
NULL, 0, NULL, HFILL } },
{ &hf_mp4_full_box_ver,
{ "Box version", "mp4.full_box.version", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL } },
{ &hf_mp4_ftyp_brand,
{ "Brand", "mp4.ftyp.brand", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL } },
{ &hf_mp4_ftyp_ver,
{ "Version", "mp4.ftyp.version", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL } },
{ &hf_mp4_ftyp_add_brand,
{ "Additional brand", "mp4.ftyp.additional_brand", FT_STRING,
BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_mp4_mfhd_seq_num,
{ "Sequence number", "mp4.mfhd.sequence_number", FT_UINT32,
BASE_DEC, NULL, 0, NULL, HFILL } }
};
static gint *ett[] = {
&ett_mp4,
&ett_mp4_box
};
static ei_register_info ei[] = {
{ &ei_mp4_box_too_large,
{ "mp4.box_too_large", PI_PROTOCOL, PI_WARN,
"box size too large, dissection of this box is not supported", EXPFILL }}
};
expert_module_t *expert_mp4;
proto_mp4 = proto_register_protocol("MP4 / ISOBMFF file format", "mp4", "mp4");
proto_register_field_array(proto_mp4, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mp4 = expert_register_protocol(proto_mp4);
expert_register_field_array(expert_mp4, ei, array_length(ei));
}
void
proto_reg_handoff_mp4(void)
{
dissector_handle_t mp4_handle = new_create_dissector_handle(dissect_mp4, proto_mp4);
dissector_add_string("media_type", "video/mp4", mp4_handle);
}
