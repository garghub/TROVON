static int dissect_nwmtp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NW MTP");
col_clear(pinfo->cinfo, COL_INFO);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
const gchar *type;
proto_item *ti;
proto_item *nwmtp_tree;
guint32 len;
tvbuff_t *next_tvb;
type = val_to_str_const(tvb_get_guint8(tvb, offset + 1),
nwmtp_data_type_vals, "Unknown");
col_set_str(pinfo->cinfo, COL_INFO, type);
len = tvb_get_ntohl(tvb, offset + 8);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_nwmtp,
tvb, offset, len + 12,
"NexusWare C7 UDP Protocol");
nwmtp_tree = proto_item_add_subtree(ti, ett_mwmtp);
proto_tree_add_item(nwmtp_tree, hf_nwmtp_transp_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nwmtp_tree, hf_nwmtp_data_type,
tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(nwmtp_tree, hf_nwmtp_data_index,
tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(nwmtp_tree, hf_nwmtp_user_context,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(nwmtp_tree, hf_nwmtp_data_length,
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_length(tvb, offset + 12, len);
if (tvb_reported_length(next_tvb) > 0)
call_dissector(mtp_handle, next_tvb, pinfo, tree);
DISSECTOR_ASSERT(len < G_MAXUINT32 - 11);
DISSECTOR_ASSERT((guint64)offset + len + 12 < G_MAXINT);
offset += len + 12;
}
return tvb_captured_length(tvb);
}
void proto_register_mwmtp(void)
{
static hf_register_info hf[] = {
{&hf_nwmtp_transp_type,
{"Transport Type", "nwmtp.transp_type",
FT_UINT8, BASE_DEC, VALS(nwmtp_transport_type_vals), 0x0,
"The Transport Type", HFILL}
},
{&hf_nwmtp_data_type,
{"Data Type", "nwmtp.data_type",
FT_UINT8, BASE_DEC, VALS(nwmtp_data_type_vals), 0x0,
"The Data Type", HFILL}
},
{&hf_nwmtp_data_index,
{"Link Index", "nwmtp.link_index",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_nwmtp_user_context,
{"User Context", "nwmtp.user_context",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Use Context", HFILL}
},
{&hf_nwmtp_data_length,
{"Length", "nwmtp.data_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Data Length", HFILL}
},
};
static gint *ett[] = {
&ett_mwmtp,
};
proto_nwmtp =
proto_register_protocol("NexusWare C7 MTP", "MTP over NW UDP", "nw_mtp");
proto_register_field_array(proto_nwmtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
nwmtp_handle = register_dissector("nw_mtp", dissect_nwmtp, proto_nwmtp);
}
void proto_reg_handoff_nwmtp(void)
{
dissector_add_for_decode_as_with_preference("udp.port", nwmtp_handle);
mtp_handle = find_dissector_add_dependency("mtp3", proto_nwmtp);
}
