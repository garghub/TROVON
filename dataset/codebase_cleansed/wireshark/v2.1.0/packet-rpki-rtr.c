static guint
get_rpkirtr_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint32 plen;
plen = tvb_get_ntohl(tvb, offset+4);
return plen;
}
static int dissect_rpkirtr_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti = NULL, *ti_flags, *ti_type;
proto_tree *rpkirtr_tree = NULL, *flags_tree = NULL;
int offset = 0;
guint8 pdu_type, version;
guint length;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
ti = proto_tree_add_item(tree, proto_rpkirtr, tvb, 0, -1, ENC_NA);
rpkirtr_tree = proto_item_add_subtree(ti, ett_rpkirtr);
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_version, tvb, offset, 1, ENC_BIG_ENDIAN);
version = tvb_get_guint8(tvb, offset);
offset += 1;
ti_type = proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_pdu_type, tvb, offset, 1, ENC_BIG_ENDIAN);
pdu_type = tvb_get_guint8(tvb, offset);
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, val_to_str(pdu_type, rtr_pdu_type_vals, "Unknown (%d)"));
proto_item_append_text(ti, " (%s)", val_to_str(pdu_type, rtr_pdu_type_vals, "Unknown %d"));
offset += 1;
length = tvb_get_ntohl(tvb, offset);
switch (pdu_type) {
case RPKI_RTR_SERIAL_NOTIFY_PDU:
case RPKI_RTR_SERIAL_QUERY_PDU:
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_session_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_serial_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case RPKI_RTR_RESET_QUERY_PDU:
case RPKI_RTR_CACHE_RESET_PDU:
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case RPKI_RTR_CACHE_RESPONSE_PDU:
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_session_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case RPKI_RTR_IPV4_PREFIX_PDU:
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ti_flags = proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti_flags, ett_flags);
proto_tree_add_item(flags_tree, hf_rpkirtr_flags_aw, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_max_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_ipv4_prefix, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_as_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case RPKI_RTR_IPV6_PREFIX_PDU:
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ti_flags = proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti_flags, ett_flags);
proto_tree_add_item(flags_tree, hf_rpkirtr_flags_aw, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_prefix_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_max_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_ipv6_prefix, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_as_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case RPKI_RTR_END_OF_DATA_PDU:
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_session_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_serial_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (version >= 1){
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_refresh_interval, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_retry_interval, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_expire_interval, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case RPKI_RTR_ROUTER_KEY:
if(version < 1){
expert_add_info(pinfo, ti_type, &ei_rpkirtr_wrong_version_router_key);
} else {
asn1_ctx_t asn1_ctx;
ti_flags = proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(ti_flags, ett_flags_nd);
proto_tree_add_item(flags_tree, hf_rpkirtr_flags_rk, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_reserved, tvb, offset, 2, ENC_NA);
offset += 1;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_subject_key_identifier, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_as_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509af_SubjectPublicKeyInfo(FALSE, tvb, offset, &asn1_ctx, rpkirtr_tree, hf_rpkirtr_subject_public_key_info);
}
break;
case RPKI_RTR_ERROR_REPORT_PDU:
{
guint32 len_pdu, len_text;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_error_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length_pdu, tvb, offset, 4, ENC_BIG_ENDIAN);
len_pdu = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_error_pdu, tvb, offset, len_pdu, ENC_NA);
offset += len_pdu;
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_length_text, tvb, offset, 4, ENC_BIG_ENDIAN);
len_text = tvb_get_ntohl(tvb, offset);
offset += 4,
proto_tree_add_item(rpkirtr_tree, hf_rpkirtr_error_text, tvb, offset, len_text, ENC_ASCII|ENC_NA);
offset += len_text;
}
break;
default:
offset += length;
break;
}
}
return tvb_reported_length(tvb);
}
static int
dissect_rpkirtr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RPKI-RTR");
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, 1, 8, get_rpkirtr_pdu_len, dissect_rpkirtr_pdu, data);
return tvb_reported_length(tvb);
}
void
proto_register_rpkirtr(void)
{
module_t *rpkirtr_module;
static hf_register_info hf[] = {
{ &hf_rpkirtr_version,
{ "Version", "rpki-rtr.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Denoting the version of this protocol (currently 0)", HFILL }
},
{ &hf_rpkirtr_pdu_type,
{ "PDU Type", "rpki-rtr.pdu_type",
FT_UINT8, BASE_DEC, VALS(rtr_pdu_type_vals), 0x0,
"Denoting the type of the PDU", HFILL }
},
{ &hf_rpkirtr_reserved,
{ "Reserved", "rpki-rtr.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Must be zero", HFILL }
},
{ &hf_rpkirtr_session_id,
{ "Session ID", "rpki-rtr.session_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_length,
{ "Length", "rpki-rtr.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Value the count of the bytes in the entire PDU, including the eight bytes of header that end with the length field", HFILL }
},
{ &hf_rpkirtr_serial_number,
{ "Serial Number", "rpki-rtr.serial_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_flags,
{ "Flags", "rpki-rtr.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_flags_aw,
{ "Flag AW", "rpki-rtr.flags.aw",
FT_BOOLEAN, 8, TFS(&tfs_flag_type_aw), 0x01,
NULL, HFILL }
},
{ &hf_rpkirtr_flags_rk,
{ "Flag Router Key", "rpki-rtr.flags.rk",
FT_BOOLEAN, 8, TFS(&tfs_flag_type_rk), 0x01,
NULL, HFILL }
},
{ &hf_rpkirtr_prefix_length,
{ "Prefix Length", "rpki-rtr.prefix_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Denoting the shortest prefix allowed for the prefix", HFILL }
},
{ &hf_rpkirtr_max_length,
{ "Max length", "rpki-rtr.max_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Denoting the longest prefix allowed by the prefix. This MUST NOT be less than the Prefix Length element", HFILL }
},
{ &hf_rpkirtr_ipv4_prefix,
{ "IPv4 Prefix", "rpki-rtr.ipv4_prefix",
FT_IPv4, BASE_NONE, NULL, 0x0,
"The IPv4 prefix of the ROA", HFILL }
},
{ &hf_rpkirtr_ipv6_prefix,
{ "IPv6 Prefix", "rpki-rtr.ipv6_prefix",
FT_IPv6, BASE_NONE, NULL, 0x0,
"The IPv6 prefix of the ROA", HFILL }
},
{ &hf_rpkirtr_as_number,
{ "AS Number", "rpki-rtr.as_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Autonomous System Number allowed to announce this prefix", HFILL }
},
{ &hf_rpkirtr_error_code,
{ "Error Code", "rpki-rtr.error_code",
FT_UINT16, BASE_DEC, VALS(rtr_error_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_length_pdu,
{ "Length of Encapsulated PDU", "rpki-rtr.length_pdu",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_error_pdu,
{ "Erroneous PDU", "rpki-rtr.error_pdu",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_length_text,
{ "Length of text", "rpki-rtr.length_text",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_error_text,
{ "Erroneous Text", "rpki-rtr.error_text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_refresh_interval,
{ "Refresh Interval", "rpki-rtr.refresh_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_retry_interval,
{ "Retry Interval", "rpki-rtr.retry_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_expire_interval,
{ "Expire Interval", "rpki-rtr.expire_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_subject_key_identifier,
{ "Subject Key Identifier", "rpki-rtr.subject_key_identifier",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rpkirtr_subject_public_key_info,
{ "Subject Public Key Info", "rpki-rtr.subject_public_key_info",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_rpkirtr,
&ett_flags,
&ett_flags_nd
};
static ei_register_info ei[] = {
{ &ei_rpkirtr_wrong_version_router_key, { "rpkirtr.router_key.wrong_version", PI_MALFORMED, PI_WARN, "Wrong version for Router Key type", EXPFILL }},
};
expert_module_t *expert_rpkirtr;
proto_rpkirtr = proto_register_protocol("RPKI-Router Protocol",
"RPKI-Router Protocol", "rpkirtr");
proto_register_field_array(proto_rpkirtr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
rpkirtr_module = prefs_register_protocol(proto_rpkirtr,
proto_reg_handoff_rpkirtr);
prefs_register_uint_preference(rpkirtr_module, "tcp.rpkirtr.port", "RPKI-RTR TCP Port",
"RPKI-Router Protocol TCP port if other than the default",
10, &g_port_rpkirtr);
prefs_register_uint_preference(rpkirtr_module, "tcp.rpkirtr_tls.port", "RPKI-RTR TCP TLS Port",
"RPKI-Router Protocol TCP TLS port if other than the default",
10, &g_port_rpkirtr_tls);
expert_rpkirtr = expert_register_protocol(proto_rpkirtr);
expert_register_field_array(expert_rpkirtr, ei, array_length(ei));
}
void
proto_reg_handoff_rpkirtr(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t rpkirtr_handle;
static dissector_handle_t ssl_handle;
static int rpki_rtr_port, rpki_rtr_tls_port;
if (!initialized) {
rpkirtr_handle = create_dissector_handle(dissect_rpkirtr,
proto_rpkirtr);
ssl_handle = find_dissector("ssl");
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", rpki_rtr_port, rpkirtr_handle);
dissector_delete_uint("tcp.port", rpki_rtr_tls_port, ssl_handle);
}
rpki_rtr_port = g_port_rpkirtr;
rpki_rtr_tls_port = g_port_rpkirtr_tls;
dissector_add_uint("tcp.port", rpki_rtr_port, rpkirtr_handle);
dissector_add_uint("tcp.port", rpki_rtr_tls_port, ssl_handle);
}
