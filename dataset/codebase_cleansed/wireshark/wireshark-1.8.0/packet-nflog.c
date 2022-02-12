static int
nflog_tvb_test_order(tvbuff_t *tvb, int offset, guint16 (*val16_get)(tvbuff_t *, int))
{
while (tvb_length_remaining(tvb, offset) > 4) {
guint16 tlv_len = val16_get(tvb, offset + 0);
guint16 tlv_type;
if (tlv_len < 4)
return 0;
tlv_type = (val16_get(tvb, offset + 2) & 0x7fff);
if (tlv_type >= 0x100)
break;
if (tlv_type)
return 1;
offset += ((tlv_len + 3) & ~3);
}
return 0;
}
static int
nflog_tvb_byte_order(tvbuff_t *tvb, int tlv_offset)
{
switch (nflog_byte_order) {
case BYTE_ORDER_BE:
return ENC_BIG_ENDIAN;
case BYTE_ORDER_LE:
return ENC_LITTLE_ENDIAN;
case BYTE_ORDER_HOST:
return (G_BYTE_ORDER == G_LITTLE_ENDIAN) ?
ENC_LITTLE_ENDIAN :
ENC_BIG_ENDIAN;
}
if (nflog_tvb_test_order(tvb, tlv_offset, tvb_get_ntohs))
return ENC_BIG_ENDIAN;
if (nflog_tvb_test_order(tvb, tlv_offset, tvb_get_letohs))
return ENC_LITTLE_ENDIAN;
return ENC_NA;
}
static void
dissect_nflog(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const int start_tlv_offset = 4;
proto_tree *nflog_tree = NULL;
proto_item *ti;
int offset = 0;
tvbuff_t *next_tvb = NULL;
int aftype;
int enc;
guint16 (*val16_get)(tvbuff_t *, int);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NFLOG");
col_clear(pinfo->cinfo, COL_INFO);
aftype = tvb_get_guint8(tvb, 0);
enc = nflog_tvb_byte_order(tvb, start_tlv_offset);
switch (enc) {
case ENC_LITTLE_ENDIAN:
val16_get = tvb_get_letohs;
break;
case ENC_BIG_ENDIAN:
default:
val16_get = tvb_get_ntohs;
break;
}
if (proto_field_is_referenced(tree, proto_nflog)) {
ti = proto_tree_add_item(tree, proto_nflog, tvb, 0, -1, ENC_NA);
nflog_tree = proto_item_add_subtree(ti, ett_nflog);
proto_tree_add_item(nflog_tree, hf_nflog_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(nflog_tree, hf_nflog_version, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(nflog_tree, hf_nflog_resid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_uint(nflog_tree, hf_nflog_encoding,
tvb, offset, tvb_length_remaining(tvb, offset), enc);
PROTO_ITEM_SET_GENERATED(ti);
}
offset = start_tlv_offset;
while (tvb_length_remaining(tvb, offset) >= 4) {
guint16 tlv_len = val16_get(tvb, offset + 0);
guint16 tlv_type;
guint16 value_len;
proto_tree *tlv_tree;
if (tlv_len < 4)
return;
value_len = tlv_len - 4;
tlv_type = (val16_get(tvb, offset + 2) & 0x7fff);
if (nflog_tree) {
gboolean handled = FALSE;
ti = proto_tree_add_bytes_format(nflog_tree, hf_nflog_tlv,
tvb, offset, tlv_len, NULL,
"TLV Type: %s (%u), Length: %u",
val_to_str_const(tlv_type, nflog_tlv_vals, "Unknown"),
tlv_type, tlv_len);
tlv_tree = proto_item_add_subtree(ti, ett_nflog_tlv);
proto_tree_add_item(tlv_tree, hf_nflog_tlv_length, tvb, offset + 0, 2, enc);
proto_tree_add_item(tlv_tree, hf_nflog_tlv_type, tvb, offset + 2, 2, enc);
switch (tlv_type) {
case WS_NFULA_PAYLOAD:
handled = TRUE;
break;
case WS_NFULA_PREFIX:
if (value_len >= 1) {
proto_tree_add_item(tlv_tree, hf_nflog_tlv_prefix,
tvb, offset + 4, value_len, ENC_NA);
handled = TRUE;
}
break;
case WS_NFULA_UID:
if (value_len == 4) {
proto_tree_add_item(tlv_tree, hf_nflog_tlv_uid,
tvb, offset + 4, value_len, ENC_BIG_ENDIAN);
handled = TRUE;
}
break;
case WS_NFULA_GID:
if (value_len == 4) {
proto_tree_add_item(tlv_tree, hf_nflog_tlv_gid,
tvb, offset + 4, value_len, ENC_BIG_ENDIAN);
handled = TRUE;
}
break;
case WS_NFULA_TIMESTAMP:
if (value_len == 16) {
nstime_t ts;
ts.secs = tvb_get_ntoh64(tvb, offset + 4);
ts.nsecs = (int)tvb_get_ntoh64(tvb, offset + 12);
proto_tree_add_time(tlv_tree, hf_nflog_tlv_timestamp,
tvb, offset + 4, value_len, &ts);
handled = TRUE;
}
break;
}
if (!handled)
proto_tree_add_item(tlv_tree, hf_nflog_tlv_unknown,
tvb, offset + 4, value_len, ENC_NA);
}
if (tlv_type == WS_NFULA_PAYLOAD)
next_tvb = tvb_new_subset(tvb, offset + 4, value_len, value_len);
offset += ((tlv_len + 3) & ~3);
}
if (next_tvb) {
switch (aftype) {
case LINUX_AF_INET:
call_dissector(ip_handle, next_tvb, pinfo, tree);
break;
case LINUX_AF_INET6:
call_dissector(ip6_handle, next_tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
}
}
void
proto_register_nflog(void)
{
static hf_register_info hf[] = {
{ &hf_nflog_family,
{ "Family", "nflog.family", FT_UINT8, BASE_DEC, VALS(_linux_family_vals), 0x00, NULL, HFILL }
},
{ &hf_nflog_version,
{ "Version", "nflog.version", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_nflog_resid,
{ "Resource id", "nflog.res_id", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_nflog_encoding,
{ "Encoding", "nflog.encoding", FT_UINT32, BASE_HEX, VALS(_encoding_vals), 0x00, NULL, HFILL }
},
{ &hf_nflog_tlv,
{ "TLV", "nflog.tlv", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_nflog_tlv_length,
{ "Length", "nflog.tlv_length", FT_UINT16, BASE_DEC, NULL, 0x00, "TLV Length", HFILL }
},
{ &hf_nflog_tlv_type,
{ "Type", "nflog.tlv_type", FT_UINT16, BASE_DEC, VALS(nflog_tlv_vals), 0x7fff, "TLV Type", HFILL }
},
{ &hf_nflog_tlv_prefix,
{ "Prefix", "nflog.prefix", FT_STRINGZ, BASE_NONE, NULL, 0x00, "TLV Prefix Value", HFILL }
},
{ &hf_nflog_tlv_uid,
{ "UID", "nflog.uid", FT_INT32, BASE_DEC, NULL, 0x00, "TLV UID Value", HFILL }
},
{ &hf_nflog_tlv_gid,
{ "GID", "nflog.gid", FT_INT32, BASE_DEC, NULL, 0x00, "TLV GID Value", HFILL }
},
{ &hf_nflog_tlv_timestamp,
{ "Timestamp", "nflog.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00, "TLV Timestamp Value", HFILL }
},
{ &hf_nflog_tlv_unknown,
{ "Value", "nflog.tlv_value", FT_BYTES, BASE_NONE, NULL, 0x00, "TLV Value", HFILL }
},
};
static gint *ett[] = {
&ett_nflog,
&ett_nflog_tlv
};
module_t *pref;
proto_nflog = proto_register_protocol("Linux Netfilter NFLOG", "NFLOG", "nflog");
pref = prefs_register_protocol(proto_nflog, NULL);
prefs_register_enum_preference(pref, "byte_order_type", "Byte Order", "Byte Order",
&nflog_byte_order, byte_order_types, FALSE);
register_dissector("nflog", dissect_nflog, proto_nflog);
proto_register_field_array(proto_nflog, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nflog(void)
{
dissector_handle_t nflog_handle;
ip_handle = find_dissector("ip");
ip6_handle = find_dissector("ipv6");
data_handle = find_dissector("data");
nflog_handle = find_dissector("nflog");
dissector_add_uint("wtap_encap", WTAP_ENCAP_NFLOG, nflog_handle);
}
