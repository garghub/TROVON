gint
packet_mpeg_sect_mjd_to_utc_time(tvbuff_t *tvb, gint offset, nstime_t *utc_time)
{
gint bcd_time_offset;
guint8 hour, min, sec;
if (!utc_time)
return -1;
nstime_set_zero(utc_time);
utc_time->secs = (tvb_get_ntohs(tvb, offset) - 40587) * 86400;
bcd_time_offset = offset+2;
hour = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, bcd_time_offset));
min = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, bcd_time_offset+1));
sec = MPEG_SECT_BCD44_TO_DEC(tvb_get_guint8(tvb, bcd_time_offset+2));
if (hour>23 || min>59 || sec>59)
return -1;
utc_time->secs += hour*3600 + min*60 + sec;
return 5;
}
guint
packet_mpeg_sect_header(tvbuff_t *tvb, guint offset,
proto_tree *tree, guint *sect_len, gboolean *ssi)
{
return packet_mpeg_sect_header_extra(tvb, offset, tree, sect_len,
NULL, ssi, NULL);
}
guint
packet_mpeg_sect_header_extra(tvbuff_t *tvb, guint offset, proto_tree *tree,
guint *sect_len, guint *reserved, gboolean *ssi,
proto_item **items)
{
guint tmp;
guint len = 0;
proto_item *pi[PACKET_MPEG_SECT_PI__SIZE];
gint i;
for (i = 0; i < PACKET_MPEG_SECT_PI__SIZE; i++) {
pi[i] = NULL;
}
if (tree) {
pi[PACKET_MPEG_SECT_PI__TABLE_ID] =
proto_tree_add_item(tree, hf_mpeg_sect_table_id,
tvb, offset + len, 1, ENC_BIG_ENDIAN);
}
len++;
if (tree) {
pi[PACKET_MPEG_SECT_PI__SSI] =
proto_tree_add_item(tree, hf_mpeg_sect_syntax_indicator,
tvb, offset + len, 2, ENC_BIG_ENDIAN);
pi[PACKET_MPEG_SECT_PI__RESERVED] =
proto_tree_add_item(tree, hf_mpeg_sect_reserved, tvb,
offset + len, 2, ENC_BIG_ENDIAN);
pi[PACKET_MPEG_SECT_PI__LENGTH] =
proto_tree_add_item(tree, hf_mpeg_sect_length, tvb,
offset + len, 2, ENC_BIG_ENDIAN);
}
tmp = tvb_get_ntohs(tvb, offset + len);
if (sect_len)
*sect_len = MPEG_SECT_LENGTH_MASK & tmp;
if (reserved)
*reserved = (MPEG_SECT_RESERVED_MASK & tmp) >> 12;
if (ssi)
*ssi = (MPEG_SECT_SYNTAX_INDICATOR_MASK & tmp);
if (items) {
for (i = 0; i < PACKET_MPEG_SECT_PI__SIZE; i++) {
items[i] = pi[i];
}
}
len += 2;
return len;
}
guint
packet_mpeg_sect_crc(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint start, guint end)
{
guint32 crc, calculated_crc;
const char *label;
crc = tvb_get_ntohl(tvb, end);
calculated_crc = crc;
label = "Unverified";
if (mpeg_sect_check_crc) {
label = "Verified";
calculated_crc = crc32_mpeg2_tvb_offset(tvb, start, end);
}
if (calculated_crc == crc) {
proto_tree_add_uint_format( tree, hf_mpeg_sect_crc, tvb,
end, 4, crc, "CRC: 0x%08x [%s]", crc, label);
} else {
proto_item *msg_error;
msg_error = proto_tree_add_uint_format( tree, hf_mpeg_sect_crc, tvb,
end, 4, crc,
"CRC: 0x%08x [Failed Verification (Calculated: 0x%08x)]",
crc, calculated_crc );
PROTO_ITEM_SET_GENERATED(msg_error);
expert_add_info( pinfo, msg_error, &ei_mpeg_sect_crc);
}
return 4;
}
static int
dissect_mpeg_sect(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data _U_)
{
gint tvb_len;
gint offset = 0;
guint section_length = 0;
gboolean syntax_indicator = FALSE;
guint8 table_id;
proto_item *ti;
proto_tree *mpeg_sect_tree;
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len<MPEG_SECT_MIN_LEN || tvb_len>MPEG_SECT_MAX_LEN)
return 0;
table_id = tvb_get_guint8(tvb, offset);
if (dissector_try_uint(mpeg_sect_tid_dissector_table, table_id, tvb, pinfo, tree))
return tvb_len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MPEG SECT");
col_add_fstr(pinfo->cinfo, COL_INFO, "Table ID 0x%02x", table_id);
ti = proto_tree_add_item(tree, proto_mpeg_sect, tvb, offset, -1, ENC_NA);
mpeg_sect_tree = proto_item_add_subtree(ti, ett_mpeg_sect);
proto_item_append_text(ti, " Table_ID=0x%02x", table_id);
packet_mpeg_sect_header(tvb, offset, mpeg_sect_tree,
&section_length, &syntax_indicator);
if (syntax_indicator)
packet_mpeg_sect_crc(tvb, pinfo, mpeg_sect_tree, 0, (section_length-1));
return tvb_len;
}
void
proto_register_mpeg_sect(void)
{
static hf_register_info hf[] = {
{ &hf_mpeg_sect_table_id, {
"Table ID", "mpeg_sect.tid",
FT_UINT8, BASE_HEX, VALS(mpeg_sect_table_id_vals), 0, NULL, HFILL
} },
{ &hf_mpeg_sect_syntax_indicator, {
"Syntax indicator", "mpeg_sect.syntax_indicator",
FT_UINT16, BASE_DEC, NULL, MPEG_SECT_SYNTAX_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_mpeg_sect_reserved, {
"Reserved", "mpeg_sect.reserved",
FT_UINT16, BASE_HEX, NULL, MPEG_SECT_RESERVED_MASK, NULL, HFILL
} },
{ &hf_mpeg_sect_length, {
"Length", "mpeg_sect.len",
FT_UINT16, BASE_DEC, NULL, MPEG_SECT_LENGTH_MASK, NULL, HFILL
} },
{ &hf_mpeg_sect_crc, {
"CRC 32", "mpeg_sect.crc",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} }
};
static gint *ett[] = {
&ett_mpeg_sect
};
static ei_register_info ei[] = {
{ &ei_mpeg_sect_crc, { "mpeg_sect.crc.invalid", PI_CHECKSUM, PI_WARN, "Invalid CRC", EXPFILL }},
};
module_t *mpeg_sect_module;
expert_module_t* expert_mpeg_sect;
proto_mpeg_sect = proto_register_protocol("MPEG2 Section", "MPEG SECT", "mpeg_sect");
new_register_dissector("mpeg_sect", dissect_mpeg_sect, proto_mpeg_sect);
proto_register_field_array(proto_mpeg_sect, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mpeg_sect = expert_register_protocol(proto_mpeg_sect);
expert_register_field_array(expert_mpeg_sect, ei, array_length(ei));
mpeg_sect_module = prefs_register_protocol(proto_mpeg_sect, NULL);
prefs_register_bool_preference(mpeg_sect_module,
"verify_crc",
"Verify the section CRC",
"Whether the section dissector should verify the CRC",
&mpeg_sect_check_crc);
mpeg_sect_tid_dissector_table = register_dissector_table("mpeg_sect.tid",
"MPEG SECT Table ID",
FT_UINT8, BASE_HEX);
}
