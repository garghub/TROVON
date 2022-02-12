static int
dissect_marker(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *marker_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CISCO ERSPAN3 MARKER");
if (tree) {
guint32 offset = 20;
ti = proto_tree_add_item(tree, hfi_marker, tvb, 0, -1, ENC_NA);
marker_tree = proto_item_add_subtree(ti, ett_marker);
proto_tree_add_item(marker_tree, &cisco_erspan_prop_header, tvb, 0, 20, ENC_LITTLE_ENDIAN);
proto_tree_add_item(marker_tree, &cisco_erspan_info, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(marker_tree, &cisco_erspan_version, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(marker_tree, &cisco_erspan_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(marker_tree, &cisco_erspan_ssid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(marker_tree, &cisco_erspan_granularity, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(marker_tree, &cisco_erspan_utcoffset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+= 2;
proto_tree_add_item(marker_tree, &cisco_erspan_timestamp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(marker_tree, &cisco_erspan_utc_sec, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(marker_tree, &cisco_erspan_utc_usec, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(marker_tree, &cisco_erspan_sequence_number, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(marker_tree, &cisco_erspan_reserved, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(marker_tree, &cisco_erspan_tail, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
return tvb_captured_length(tvb);
}
void
proto_register_erpsan_marker(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&cisco_erspan_prop_header,
&cisco_erspan_info,
&cisco_erspan_version,
&cisco_erspan_type,
&cisco_erspan_ssid,
&cisco_erspan_granularity,
&cisco_erspan_utcoffset,
&cisco_erspan_timestamp,
&cisco_erspan_utc_sec,
&cisco_erspan_utc_usec,
&cisco_erspan_sequence_number,
&cisco_erspan_reserved,
&cisco_erspan_tail
};
#endif
static gint *ett[] = {
&ett_marker,
};
int proto_marker;
proto_marker = proto_register_protocol("CISCO ERSPAN3 Marker Packet", "CISCO3 ERSPAN MARKER", "cisco-erspan3-marker");
hfi_marker = proto_registrar_get_nth(proto_marker);
proto_register_fields(proto_marker, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
marker_handle = create_dissector_handle(dissect_marker, proto_marker);
}
void
proto_reg_handoff_erspan_marker(void)
{
dissector_add_for_decode_as("udp.port", marker_handle);
}
