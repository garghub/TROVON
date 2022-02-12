static void
dissect_macmgmt (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint16 msg_len;
proto_item *mgt_hdr_it;
proto_tree *mgt_hdr_tree;
tvbuff_t *payload_tvb;
guint8 type;
col_set_str (pinfo->cinfo, COL_PROTOCOL, "DOCSIS MGMT");
col_clear(pinfo->cinfo, COL_INFO);
TVB_SET_ADDRESS (&pinfo->dl_src, AT_ETHER, tvb, 6, 6);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->dl_src);
TVB_SET_ADDRESS (&pinfo->dl_dst, AT_ETHER, tvb, 0, 6);
COPY_ADDRESS_SHALLOW(&pinfo->dst, &pinfo->dl_dst);
if (tree)
{
mgt_hdr_it =
proto_tree_add_protocol_format (tree, proto_docsis_mgmt, tvb, 0, 20,
"Mac Management");
mgt_hdr_tree = proto_item_add_subtree (mgt_hdr_it, ett_docsis_mgmt);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_dst_addr, tvb, 0, 6,
ENC_NA);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_src_addr, tvb, 6, 6,
ENC_NA);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_msg_len, tvb, 12, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_dsap, tvb, 14, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_ssap, tvb, 15, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_control, tvb, 16, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_version, tvb, 17, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_type, tvb, 18, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (mgt_hdr_tree, hf_docsis_mgt_rsvd, tvb, 19, 1,
ENC_BIG_ENDIAN);
}
type = tvb_get_guint8 (tvb, 18);
msg_len = tvb_get_ntohs (tvb, 12);
payload_tvb = tvb_new_subset_length (tvb, 20, msg_len - 6);
if (dissector_try_uint
(docsis_mgmt_dissector_table, type, payload_tvb, pinfo, tree))
return;
else
call_dissector (data_handle, payload_tvb, pinfo, tree);
}
void
proto_register_docsis_mgmt (void)
{
static hf_register_info hf[] = {
{&hf_docsis_mgt_dst_addr,
{"Destination Address", "docsis_mgmt.dst",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_src_addr,
{"Source Address", "docsis_mgmt.src",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_msg_len,
{"Message Length - DSAP to End (Bytes)", "docsis_mgmt.msglen",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Message Length", HFILL}
},
{&hf_docsis_mgt_dsap,
{"DSAP [0x00]", "docsis_mgmt.dsap",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Destination SAP", HFILL}
},
{&hf_docsis_mgt_ssap,
{"SSAP [0x00]", "docsis_mgmt.ssap",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Source SAP", HFILL}
},
{&hf_docsis_mgt_control,
{"Control [0x03]", "docsis_mgmt.control",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Control", HFILL}
},
{&hf_docsis_mgt_version,
{"Version", "docsis_mgmt.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_type,
{"Type", "docsis_mgmt.type",
FT_UINT8, BASE_DEC, VALS (mgmt_type_vals), 0x0,
NULL, HFILL}
},
{&hf_docsis_mgt_rsvd,
{"Reserved [0x00]", "docsis_mgmt.rsvd",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Reserved", HFILL}
},
};
static gint *ett[] = {
&ett_docsis_mgmt,
&ett_mgmt_pay,
};
docsis_mgmt_dissector_table = register_dissector_table ("docsis_mgmt",
"DOCSIS Mac Management",
FT_UINT8, BASE_DEC);
proto_docsis_mgmt = proto_register_protocol ("DOCSIS Mac Management",
"DOCSIS MAC MGMT",
"docsis_mgmt");
proto_register_field_array (proto_docsis_mgmt, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_mgmt", dissect_macmgmt, proto_docsis_mgmt);
}
void
proto_reg_handoff_docsis_mgmt (void)
{
#if 0
dissector_handle_t docsis_mgmt_handle;
docsis_mgmt_handle = find_dissector ("docsis_mgmt");
dissector_add_uint ("docsis", 0x03, docsis_mgmt_handle);
#endif
data_handle = find_dissector ("data");
}
