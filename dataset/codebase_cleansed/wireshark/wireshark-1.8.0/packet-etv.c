static void
dissect_etv_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int proto,
int hf_filter_info, int hf_reserved )
{
tvbuff_t *sub_tvb;
guint offset = 0;
proto_item *ti = NULL;
proto_item *pi = NULL;
proto_tree *etv_tree = NULL;
proto_item *items[PACKET_MPEG_SECT_PI__SIZE];
gboolean ssi;
guint reserved;
guint8 reserved2;
guint16 filter_info;
guint sect_len;
ti = proto_tree_add_item(tree, proto, tvb, offset, -1, ENC_NA);
etv_tree = proto_item_add_subtree(ti, ett_etv);
offset += packet_mpeg_sect_header_extra(tvb, offset, etv_tree, &sect_len,
&reserved, &ssi, items);
if (FALSE != ssi) {
proto_item *msg_error;
msg_error = items[PACKET_MPEG_SECT_PI__SSI];
PROTO_ITEM_SET_GENERATED(msg_error);
expert_add_info_format(pinfo, msg_error, PI_MALFORMED, PI_ERROR,
"Invalid section_syntax_indicator (should be 0)");
}
if (4 != reserved) {
proto_item *msg_error;
msg_error = items[PACKET_MPEG_SECT_PI__RESERVED];
PROTO_ITEM_SET_GENERATED(msg_error);
expert_add_info_format(pinfo, msg_error, PI_MALFORMED, PI_ERROR,
"Invalid reserved1 bits (should all be 100)");
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Length: %u", sect_len);
proto_item_append_text(ti, " Length=%u", sect_len);
if (1021 < sect_len) {
proto_item *msg_error;
msg_error = items[PACKET_MPEG_SECT_PI__LENGTH];
PROTO_ITEM_SET_GENERATED(msg_error);
expert_add_info_format(pinfo, msg_error, PI_MALFORMED, PI_ERROR,
"Invalid section_length (must not exceed 1021)");
}
filter_info = tvb_get_ntohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Filter: 0x%x", filter_info);
proto_item_append_text(ti, " Filter=0x%x", filter_info);
pi = proto_tree_add_item(etv_tree, hf_filter_info, tvb, offset, 2, ENC_BIG_ENDIAN);
if ((proto_etv_dii == proto) && (0xFBFB != filter_info)) {
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Invalid filter_info value (must be 0xFBFB)");
} else if ((proto_etv_ddb == proto) &&
((filter_info < 1) || (0xfbef < filter_info)))
{
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Invalid filter_info value (must be [0x0001-0xFBEF] inclusive)");
}
offset += 2;
reserved2 = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(etv_tree, hf_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
if (0 != reserved2) {
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Invalid reserved2 bits (should all be 0)");
}
offset++;
sub_tvb = tvb_new_subset(tvb, offset, sect_len-7, sect_len-7);
call_dissector(dsmcc_handle, sub_tvb, pinfo, tree);
sect_len += 3 - 4;
packet_mpeg_sect_crc(tvb, pinfo, etv_tree, 0, sect_len);
}
static void
dissect_etv_ddb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_clear(pinfo->cinfo, COL_PROTOCOL);
col_set_str(pinfo->cinfo, COL_INFO, "ETV DDB");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ETV-DDB");
dissect_etv_common(tvb, pinfo, tree, proto_etv_ddb, hf_etv_ddb_filter_info,
hf_etv_ddb_reserved);
}
static void
dissect_etv_dii(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_clear(pinfo->cinfo, COL_PROTOCOL);
col_set_str(pinfo->cinfo, COL_INFO, "ETV DII");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ETV-DII");
dissect_etv_common(tvb, pinfo, tree, proto_etv_dii, hf_etv_dii_filter_info,
hf_etv_dii_reserved);
}
void
proto_register_etv(void)
{
static hf_register_info hf_ddb[] = {
{ &hf_etv_ddb_filter_info, {
"Filter Info", "etv-ddb.filter_info",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_etv_ddb_reserved, {
"Reserved", "etv-ddb.reserved",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} }
};
static hf_register_info hf_dii[] = {
{ &hf_etv_dii_filter_info, {
"Filter Info", "etv-dii.filter_info",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_etv_dii_reserved, {
"Reserved", "etv-dii.reserved",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} }
};
static gint *ett[] = {
&ett_etv,
&ett_etv_payload
};
proto_etv_dii = proto_register_protocol("ETV-AM DII Section", "ETV-AM DII", "etv-dii");
proto_etv_ddb = proto_register_protocol("ETV-AM DDB Section", "ETV-AM DDB", "etv-ddb");
proto_register_field_array(proto_etv_dii, hf_dii, array_length(hf_dii));
proto_register_field_array(proto_etv_ddb, hf_ddb, array_length(hf_ddb));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_etv(void)
{
dissector_handle_t etv_dii_handle;
dissector_handle_t etv_ddb_handle;
etv_dii_handle = create_dissector_handle(dissect_etv_dii, proto_etv_dii);
etv_ddb_handle = create_dissector_handle(dissect_etv_ddb, proto_etv_ddb);
dissector_add_uint("mpeg_sect.tid", ETV_TID_DII_SECTION, etv_dii_handle);
dissector_add_uint("mpeg_sect.tid", ETV_TID_DDB_SECTION, etv_ddb_handle);
dsmcc_handle = find_dissector("mp2t-dsmcc");
data_handle = find_dissector("data");
}
