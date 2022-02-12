static int
dissect_ossp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset = 0;
const gchar *str;
proto_item *oui_item, *ossp_item;
proto_tree *ossp_tree;
tvbuff_t *ossp_tvb;
const guint8 itu_oui[] = {ITU_OUI_0, ITU_OUI_1, ITU_OUI_2};
str = tvb_get_manuf_name(tvb, offset+1);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OSSP");
col_add_fstr(pinfo->cinfo, COL_INFO, "OUI: %s", str);
ossp_item = proto_tree_add_protocol_format(tree, proto_ossp, tvb, 0, -1,
"Organization Specific Slow Protocol");
ossp_tree = proto_item_add_subtree(ossp_item, ett_ossppdu);
oui_item = proto_tree_add_item(ossp_tree, hf_ossp_oui,
tvb, offset, OUI_SIZE, ENC_NA);
proto_item_append_text(oui_item, " (%s)", str);
offset += 3;
ossp_tvb = tvb_new_subset_remaining(tvb, offset);
if (tvb_memeql(tvb, 1, itu_oui, OUI_SIZE) == 0)
{
dissect_itu_ossp(ossp_tvb, pinfo, ossp_tree);
}
#if 0
else if (tvb_memeql(tvb, 1, xxx_oui, OUI_SIZE) == 0)
{
dissect_xxx_ossp(ossp_tvb, pinfo, ossp_tree);
}
else if (tvb_memeql(tvb, 1, yyy_oui, OUI_SIZE) == 0)
{
dissect_yyy_ossp(ossp_tvb, pinfo, ossp_tree);
}
#endif
else
{
proto_item_append_text(oui_item, " (Unknown OSSP organization)");
}
return tvb_captured_length(tvb);
}
static void
dissect_itu_ossp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 subtype;
proto_tree *itu_ossp_tree, *ti;
subtype = tvb_get_ntohs(tvb, 0);
ti = proto_tree_add_item(tree, hf_itu_subtype, tvb, 0, 2, ENC_BIG_ENDIAN);
itu_ossp_tree = proto_item_add_subtree(ti, ett_itu_ossp);
switch (subtype)
{
case ESMC_ITU_SUBTYPE:
dissect_esmc_pdu(tvb, pinfo, itu_ossp_tree);
break;
#if 0
case XXXX_ITU_SUBTYPE:
dissect_xxxx_pdu(tvb, pinfo, itu_ossp_tree);
break;
#endif
default:
proto_item_append_text(itu_ossp_tree, " (Unknown)");
}
}
static void
dissect_esmc_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *treex)
{
gint offset = 2;
gboolean event_flag;
gboolean malformed = FALSE;
gint ql = -1;
gboolean timestamp_valid_flag = FALSE;
gint32 timestamp = -1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESMC");
proto_item_append_text(treex, ": ESMC");
{
proto_tree *tree_a;
tree_a = proto_item_add_subtree(treex, ett_esmc);
{
proto_item *item_b;
item_b = proto_tree_add_item(tree_a, hf_esmc_version, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, offset) >> 4) != ESMC_VERSION_1)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_b, &ei_esmc_version_compliance, "Version must be 0x%.1x claim compliance with Version 1 of this protocol", ESMC_VERSION_1);
}
}
{
event_flag = ((tvb_get_guint8(tvb, offset) & 0x08) != 0);
proto_tree_add_item(tree_a, hf_esmc_event_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if (pref_decode_esmc_timestamp)
{
timestamp_valid_flag = ((tvb_get_guint8(tvb, offset) & 0x04) != 0);
proto_tree_add_item(tree_a, hf_esmc_timestamp_valid_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
}
{
proto_item *item_b;
guint32 reserved;
reserved = tvb_get_ntohl(tvb, offset)
& (pref_decode_esmc_timestamp ? 0x3ffffff : 0x7ffffff);
item_b = proto_tree_add_uint_format_value(tree_a, hf_esmc_reserved_32, tvb, offset, 4
, reserved, "0x%.7x", reserved);
if (reserved != 0x0)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_b, &ei_esmc_reserved_not_zero, "Reserved bits must be set to all zero on transmitter");
}
offset += 4;
}
proto_item_append_text(treex, ", Event:%s", event_flag ?
"Time-critical" : "Information");
{
proto_item *item_b;
guint8 type;
item_b = proto_tree_add_item(tree_a, hf_esmc_tlv, tvb, offset, 4, ENC_NA);
{
proto_tree *tree_b;
tree_b = proto_item_add_subtree(item_b, ett_esmc);
{
proto_item *item_c;
guint16 length;
guint8 unused;
type = tvb_get_guint8(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (type != ESMC_QL_TLV_TYPE)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_type_ql_type_not_first, "TLV Type must be == 0x%.2x (QL) because QL TLV must be first in the ESMC PDU", ESMC_QL_TLV_TYPE);
expert_add_info(pinfo, item_c, &ei_esmc_tlv_type_decoded_as_ql_type);
}
offset += 1;
length = tvb_get_ntohs(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_length, tvb, offset, 2, ENC_BIG_ENDIAN);
if (length != ESMC_QL_TLV_LENGTH)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_length_bad, "QL TLV Length must be == 0x%.4x", ESMC_QL_TLV_LENGTH);
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_type_decoded_as_ql_type, "Let's decode this TLV as if Length has valid value");
}
offset += 2;
unused = tvb_get_guint8(tvb, offset);
ql = unused & 0x0f;
unused &= 0xf0;
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_ql_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
if (unused != 0x00)
{
malformed = TRUE;
expert_add_info(pinfo, item_c, &ei_esmc_tlv_ql_unused_not_zero);
}
if (NULL != try_val_to_str(ql, esmc_quality_level_opt_1_vals))
{
proto_tree_add_item(tree_b, hf_esmc_quality_level_opt_1, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
item_c = proto_tree_add_item(tree_b, hf_esmc_quality_level_invalid, tvb, offset, 1, ENC_BIG_ENDIAN);
expert_add_info(pinfo, item_c, &ei_esmc_quality_level_invalid);
}
offset += 1;
}
}
proto_item_append_text(item_b, ", %s"
, val_to_str(ql, esmc_quality_level_opt_1_vals_short, "QL-INV%d"));
}
proto_item_append_text(treex, ", %s"
, val_to_str(ql, esmc_quality_level_opt_1_vals_short, "QL-INV%d"));
if (pref_decode_esmc_timestamp)
{
guint8 type;
type = tvb_get_guint8(tvb, offset);
if (timestamp_valid_flag || type == ESMC_TIMESTAMP_TLV_TYPE)
{
proto_item *item_b;
item_b = proto_tree_add_item(tree_a, hf_esmc_tlv, tvb, offset, 8, ENC_NA);
{
proto_tree *tree_b;
tree_b = proto_item_add_subtree(item_b, ett_esmc);
{
proto_item *item_c;
guint16 length;
guint8 reserved;
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (type != ESMC_TIMESTAMP_TLV_TYPE)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_type_not_timestamp, "TLV Type must be == 0x%.2x (Timestamp) because Timestamp Valid Flag is set", ESMC_TIMESTAMP_TLV_TYPE);
expert_add_info(pinfo, item_c, &ei_esmc_tlv_type_decoded_as_timestamp);
}
offset += 1;
length = tvb_get_ntohs(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_length, tvb, offset, 2, ENC_BIG_ENDIAN);
if (length != ESMC_TIMESTAMP_TLV_LENGTH)
{
malformed = TRUE;
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_length_bad, "Timestamp TLV Length must be == 0x%.4x", ESMC_TIMESTAMP_TLV_LENGTH);
expert_add_info_format(pinfo, item_c, &ei_esmc_tlv_type_decoded_as_timestamp, "Let's decode this TLV as if Length has valid value");
}
offset += 2;
timestamp = (gint32)tvb_get_ntohl(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
if (!timestamp_valid_flag) proto_item_append_text(item_c, " [invalid]");
offset += 4;
reserved = tvb_get_guint8(tvb, offset);
item_c = proto_tree_add_item(tree_b, hf_esmc_tlv_ts_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
if (reserved != 0x0)
{
expert_add_info(pinfo, item_c, &ei_esmc_reserved_not_zero);
}
offset += 1;
}
}
proto_item_append_text(item_b, ", Timestamp: %d ns", timestamp);
if (!timestamp_valid_flag) proto_item_append_text(item_b, " [invalid]");
}
}
if (timestamp_valid_flag)
{
proto_item_append_text(treex, ", Timestamp:%d", timestamp);
}
}
{
gint padding_size;
padding_size = tvb_captured_length_remaining(tvb, offset);
if (0 != padding_size)
{
proto_tree* tree_a;
tree_a = proto_item_add_subtree(treex, ett_esmc);
{
proto_item* item_b;
tvbuff_t* tvb_next;
tvb_next = tvb_new_subset_remaining(tvb, offset);
item_b = proto_tree_add_item(tree_a, hf_esmc_padding, tvb_next, 0, -1, ENC_NA);
proto_item_append_text(item_b, ", %d %s%s", padding_size
, "octet", plurality(padding_size,"","s"));
{
proto_tree* tree_b;
tree_b = proto_item_add_subtree(item_b, ett_esmc);
call_data_dissector(tvb_next, pinfo, tree_b);
}
}
}
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Event:%s", event_flag ?
"Time-critical" : "Information");
if (ql >= 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s"
, val_to_str(ql, esmc_quality_level_opt_1_vals_short, "QL-INVALID-%d"));
}
if (timestamp_valid_flag)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", TS:%d", timestamp);
}
if (malformed)
{
col_append_str(pinfo->cinfo, COL_INFO, ", Malformed PDU");
}
}
void
proto_register_ossp(void)
{
static hf_register_info hf[] = {
{ &hf_ossp_oui,
{ "OUI", "ossp.oui",
FT_BYTES, BASE_NONE, NULL, 0,
"IEEE assigned Organizationally Unique Identifier", HFILL }},
{ &hf_itu_subtype,
{ "ITU-T OSSP Subtype", "ossp.itu.subtype",
FT_UINT16, BASE_HEX, NULL, 0,
"Subtype assigned by the ITU-T", HFILL }},
{ &hf_esmc_version,
{ "Version", "ossp.esmc.version",
FT_UINT8, BASE_HEX, NULL, 0xf0,
"This field indicates the version of ITU-T SG15 Q13 OSSP frame format", HFILL }},
{ &hf_esmc_event_flag,
{ "Event Flag", "ossp.esmc.event_flag",
FT_UINT8, BASE_HEX, VALS(esmc_event_flag_vals), 0x08,
"This bit distinguishes the critical, time sensitive behaviour of the"
" ESMC Event PDU from the ESMC Information PDU", HFILL }},
{ &hf_esmc_timestamp_valid_flag,
{ "Timestamp Valid Flag", "ossp.esmc.timestamp_valid_flag",
FT_UINT8, BASE_HEX, VALS(esmc_timestamp_valid_flag_vals), 0x04,
"Indicates validity (i.e. presence) of the Timestamp TLV", HFILL }},
{ &hf_esmc_reserved_32,
{ "Reserved", "ossp.esmc.reserved",
FT_UINT32, BASE_HEX, NULL, 0,
"Reserved. Set to all zero at the transmitter and ignored by the receiver", HFILL }},
{ &hf_esmc_tlv,
{ "ESMC TLV", "ossp.esmc.tlv",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_esmc_tlv_type,
{ "TLV Type", "ossp.esmc.tlv_type",
FT_UINT8, BASE_HEX, VALS(esmc_tlv_type_vals), 0,
NULL, HFILL }},
{ &hf_esmc_tlv_length,
{ "TLV Length", "ossp.esmc.tlv_length",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_esmc_tlv_ql_unused,
{ "Unused", "ossp.esmc.tlv_ql_unused",
FT_UINT8, BASE_HEX, NULL, 0xf0,
"This field is not used in QL TLV", HFILL }},
{ &hf_esmc_quality_level_opt_1,
{ "SSM Code", "ossp.esmc.ql",
FT_UINT8, BASE_HEX, VALS(esmc_quality_level_opt_1_vals), 0x0f,
"Quality Level information", HFILL }},
#if 0
{ &hf_esmc_quality_level_opt_2,
{ "SSM Code", "ossp.esmc.ql",
FT_UINT8, BASE_HEX, VALS(esmc_quality_level_opt_2_vals), 0x0f,
"Quality Level information", HFILL }},
#endif
{ &hf_esmc_quality_level_invalid,
{ "SSM Code", "ossp.esmc.ql",
FT_UINT8, BASE_HEX, VALS(esmc_quality_level_invalid_vals), 0x0f,
"Quality Level information", HFILL }},
{ &hf_esmc_timestamp,
{ "Timestamp (ns)", "ossp.esmc.timestamp",
FT_INT32, BASE_DEC, NULL, 0,
"Timestamp according to the \"whole nanoseconds\" part of the IEEE 1588 originTimestamp", HFILL }},
{ &hf_esmc_tlv_ts_reserved,
{ "Reserved", "ossp.esmc.tlv_ts_reserved",
FT_UINT8, BASE_HEX, NULL, 0,
"Reserved. Set to all zero at the transmitter and ignored by the receiver", HFILL }},
{ &hf_esmc_padding,
{ "Padding", "ossp.esmc.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"This field contains necessary padding to achieve the minimum frame size of 64 bytes at least", HFILL }},
};
static gint *ett[] = {
&ett_esmc,
&ett_ossppdu,
&ett_itu_ossp
};
static ei_register_info ei[] = {
{ &ei_esmc_version_compliance, { "ossp.esmc.version.compliance", PI_MALFORMED, PI_ERROR, "Version must claim compliance with Version 1 of this protocol", EXPFILL }},
{ &ei_esmc_tlv_type_ql_type_not_first, { "ossp.esmc.tlv_type.ql_type_not_first", PI_MALFORMED, PI_ERROR, "TLV Type must be QL because QL TLV must be first in the ESMC PDU", EXPFILL }},
{ &ei_esmc_tlv_type_decoded_as_ql_type, { "ossp.esmc.tlv_type.decoded_as_ql_type", PI_UNDECODED, PI_NOTE, "Let's decode as if this is QL TLV", EXPFILL }},
{ &ei_esmc_tlv_length_bad, { "ossp.esmc.tlv_length.bad", PI_MALFORMED, PI_ERROR, "QL TLV Length must be X", EXPFILL }},
{ &ei_esmc_tlv_ql_unused_not_zero, { "ossp.esmc.tlv_ql_unused.not_zero", PI_MALFORMED, PI_WARN, "Unused bits of TLV must be all zeroes", EXPFILL }},
{ &ei_esmc_quality_level_invalid, { "ossp.esmc.ql.invalid", PI_UNDECODED, PI_WARN, "Invalid SSM message, unknown QL code", EXPFILL }},
{ &ei_esmc_tlv_type_not_timestamp, { "ossp.esmc.tlv_type.not_timestamp", PI_MALFORMED, PI_ERROR, "TLV Type must be == Timestamp because Timestamp Valid Flag is set", EXPFILL }},
{ &ei_esmc_tlv_type_decoded_as_timestamp, { "ossp.esmc.tlv_type.decoded_as_timestamp", PI_UNDECODED, PI_NOTE, "Let's decode as if this is Timestamp TLV", EXPFILL }},
{ &ei_esmc_reserved_not_zero, { "ossp.esmc.reserved_bits_must_be_set_to_all_zero", PI_PROTOCOL, PI_WARN, "Reserved bits must be set to all zero", EXPFILL }},
};
expert_module_t* expert_ossp;
proto_ossp = proto_register_protocol("OSSP", "Organization Specific Slow Protocol", "ossp");
proto_register_field_array(proto_ossp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ossp = expert_register_protocol(proto_ossp);
expert_register_field_array(expert_ossp, ei, array_length(ei));
}
void
proto_reg_handoff_ossp(void)
{
dissector_handle_t ossp_handle;
ossp_handle = create_dissector_handle(dissect_ossp_pdu, proto_ossp);
dissector_add_uint("slow.subtype", OSSP_SUBTYPE, ossp_handle);
}
