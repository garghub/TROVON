static void
dissect_nflog(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const int start_tlv_offset = 4;
proto_tree *nflog_tree = NULL;
proto_item *ti;
int offset = 0;
tvbuff_t *next_tvb = NULL;
int aftype;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NFLOG");
col_clear(pinfo->cinfo, COL_INFO);
aftype = tvb_get_guint8(tvb, 0);
if (proto_field_is_referenced(tree, hfi_nflog->id)) {
ti = proto_tree_add_item(tree, hfi_nflog, tvb, 0, -1, ENC_NA);
nflog_tree = proto_item_add_subtree(ti, ett_nflog);
proto_tree_add_item(nflog_tree, &hfi_nflog_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(nflog_tree, &hfi_nflog_version, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(nflog_tree, &hfi_nflog_resid, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset = start_tlv_offset;
while (tvb_reported_length_remaining(tvb, offset) >= 4) {
guint16 tlv_len = tvb_get_h_guint16(tvb, offset + 0);
guint16 tlv_type;
guint16 value_len;
proto_tree *tlv_tree;
if (tlv_len < 4)
return;
value_len = tlv_len - 4;
tlv_type = (tvb_get_h_guint16(tvb, offset + 2) & 0x7fff);
if (nflog_tree) {
gboolean handled = FALSE;
ti = proto_tree_add_bytes_format(nflog_tree, hfi_nflog_tlv.id,
tvb, offset, tlv_len, NULL,
"TLV Type: %s (%u), Length: %u",
val_to_str_const(tlv_type, nflog_tlv_vals, "Unknown"),
tlv_type, tlv_len);
tlv_tree = proto_item_add_subtree(ti, ett_nflog_tlv);
proto_tree_add_item(tlv_tree, &hfi_nflog_tlv_length, tvb, offset + 0, 2, ENC_HOST_ENDIAN);
proto_tree_add_item(tlv_tree, &hfi_nflog_tlv_type, tvb, offset + 2, 2, ENC_HOST_ENDIAN);
switch (tlv_type) {
case WS_NFULA_PAYLOAD:
handled = TRUE;
break;
case WS_NFULA_PREFIX:
if (value_len >= 1) {
proto_tree_add_item(tlv_tree, &hfi_nflog_tlv_prefix,
tvb, offset + 4, value_len, ENC_NA);
handled = TRUE;
}
break;
case WS_NFULA_UID:
if (value_len == 4) {
proto_tree_add_item(tlv_tree, &hfi_nflog_tlv_uid,
tvb, offset + 4, value_len, ENC_BIG_ENDIAN);
handled = TRUE;
}
break;
case WS_NFULA_GID:
if (value_len == 4) {
proto_tree_add_item(tlv_tree, &hfi_nflog_tlv_gid,
tvb, offset + 4, value_len, ENC_BIG_ENDIAN);
handled = TRUE;
}
break;
case WS_NFULA_TIMESTAMP:
if (value_len == 16) {
nstime_t ts;
ts.secs = (time_t)tvb_get_ntoh64(tvb, offset + 4);
ts.nsecs = (int)tvb_get_ntoh64(tvb, offset + 12);
proto_tree_add_time(tlv_tree, &hfi_nflog_tlv_timestamp,
tvb, offset + 4, value_len, &ts);
handled = TRUE;
}
break;
}
if (!handled)
proto_tree_add_item(tlv_tree, &hfi_nflog_tlv_unknown,
tvb, offset + 4, value_len, ENC_NA);
}
if (tlv_type == WS_NFULA_PAYLOAD)
next_tvb = tvb_new_subset_length(tvb, offset + 4, value_len);
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
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_nflog_family,
&hfi_nflog_version,
&hfi_nflog_resid,
&hfi_nflog_tlv,
&hfi_nflog_tlv_length,
&hfi_nflog_tlv_type,
&hfi_nflog_tlv_prefix,
&hfi_nflog_tlv_uid,
&hfi_nflog_tlv_gid,
&hfi_nflog_tlv_timestamp,
&hfi_nflog_tlv_unknown,
};
#endif
static gint *ett[] = {
&ett_nflog,
&ett_nflog_tlv
};
int proto_nflog;
proto_nflog = proto_register_protocol("Linux Netfilter NFLOG", "NFLOG", "nflog");
hfi_nflog = proto_registrar_get_nth(proto_nflog);
register_dissector("nflog", dissect_nflog, proto_nflog);
proto_register_fields(proto_nflog, hfi, array_length(hfi));
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
