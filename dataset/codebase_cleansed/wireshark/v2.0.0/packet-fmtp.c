static int
dissect_fmtp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 packet_type;
guint16 packet_len;
tvbuff_t *next_tvb;
proto_item *ti = NULL;
proto_tree *fmtp_tree = NULL;
packet_type = tvb_get_guint8(tvb, 4);
packet_len = tvb_get_ntohs(tvb, 2);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FMTP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_fmtp, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", %s",
val_to_str(packet_type, packet_type_names, "Unknown (0x%02x)"));
switch (packet_type) {
case FMTP_TYP_IDENTIFICATION:
proto_item_append_text(ti, " (%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb, FMTP_HEADER_LEN, packet_len-FMTP_HEADER_LEN, ENC_ASCII));
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (%s)",
val_to_str(packet_type, packet_type_names, "Unknown (0x%02x)"),
tvb_get_string_enc(wmem_packet_scope(), tvb, FMTP_HEADER_LEN, packet_len-FMTP_HEADER_LEN, ENC_ASCII));
break;
case FMTP_TYP_SYSTEM:
proto_item_append_text(ti, " (%s)",
tvb_get_string_enc(wmem_packet_scope(), tvb, FMTP_HEADER_LEN, packet_len-FMTP_HEADER_LEN, ENC_ASCII));
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (%s)",
val_to_str(packet_type, packet_type_names, "Unknown (0x%02x)"),
val_to_str(tvb_get_ntohs(tvb, FMTP_HEADER_LEN), system_message_names, "Unknown (0x%02x)"));
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(packet_type, packet_type_names, "Unknown (0x%02x)"));
break;
}
if (tree) {
fmtp_tree = proto_item_add_subtree(ti, ett_fmtp);
proto_tree_add_item(fmtp_tree, hf_fmtp_pdu_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmtp_tree, hf_fmtp_pdu_reserved, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fmtp_tree, hf_fmtp_pdu_length, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fmtp_tree, hf_fmtp_pdu_type, tvb, 4, 1, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, FMTP_HEADER_LEN);
call_dissector(data_handle, next_tvb, pinfo, fmtp_tree);
}
return tvb_captured_length(tvb);
}
static guint
get_fmtp_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return (guint)tvb_get_ntohs(tvb, offset+2);
}
static gboolean
dissect_fmtp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (tvb_get_guint8(tvb, 0) != 0x02) return (FALSE);
if (tvb_get_guint8(tvb, 1) != 0x00) return (FALSE);
if (tvb_get_ntohs(tvb, 2) > FMTP_MAX_LEN) return (FALSE);
if ((tvb_get_guint8(tvb, 4) < 0x01) || (tvb_get_guint8(tvb, 4) > 0x04))
return (FALSE);
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, FMTP_HEADER_LEN,
get_fmtp_message_len, dissect_fmtp_message, data);
return (TRUE);
}
void
proto_register_fmtp(void)
{
static hf_register_info hf[] = {
{ &hf_fmtp_pdu_version,
{ "Version", "fmtp.version",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_fmtp_pdu_reserved,
{ "Reserved", "fmtp.reserved",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_fmtp_pdu_length,
{ "Length", "fmtp.length",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_fmtp_pdu_type,
{ "Type", "fmtp.type",
FT_UINT8, BASE_DEC,
VALS(packet_type_names), 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_fmtp
};
proto_fmtp = proto_register_protocol(
"Flight Message Transfer Protocol (FMTP)",
"FMTP",
"fmtp");
proto_register_field_array(proto_fmtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_fmtp(void)
{
heur_dissector_add("tcp", dissect_fmtp, "FMTP over TCP", "fmtp_tcp", proto_fmtp, HEURISTIC_ENABLE);
data_handle = find_dissector("data");
}
