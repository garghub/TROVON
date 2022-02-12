static void
dissect_nsrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *nsrp_tree = NULL;
gint offset = 0;
guint8 msgtype = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NSRP");
col_set_str(pinfo->cinfo, COL_INFO, "NSRP Protocol");
if (tree) {
ti = proto_tree_add_item(tree, proto_nsrp, tvb, 0, -1, ENC_NA);
nsrp_tree = proto_item_add_subtree(ti, ett_nsrp);
proto_tree_add_item(nsrp_tree, hf_nsrp_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
msgtype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(nsrp_tree, hf_nsrp_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_clust_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_msg_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_ha_port, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_not_used, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_dst_unit, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(nsrp_tree, hf_nsrp_src_unit, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if ( msgtype == 0x00 ) {
proto_tree_add_item(nsrp_tree, hf_nsrp_msgtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_wst_group, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_hst_group, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_msgflag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_msglen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_encflag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_not_used, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_total_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(nsrp_tree, hf_nsrp_ns, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_no_used, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_checksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_data, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
if ( msgtype == 0x02 ) {
proto_tree_add_item(nsrp_tree, hf_nsrp_msgtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_wst_group, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_hst_group, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_msgflag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_msglen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_authflag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_not_used, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_dummy, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_authchecksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_data, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
if ( msgtype == 0x03 ) {
proto_tree_add_item(nsrp_tree, hf_nsrp_msgtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_wst_group, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_hst_group, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_msgflag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_msglen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nsrp_tree, hf_nsrp_ifnum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_not_used, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nsrp_tree, hf_nsrp_total_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(nsrp_tree, hf_nsrp_data, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
}
void
proto_register_nsrp(void)
{
static hf_register_info hf[] = {
{ &hf_nsrp_version,
{ "Version", "nsrp.version",
FT_UINT8, BASE_DEC, NULL, 0,
"NSRP Version", HFILL }
},
{ &hf_nsrp_msg_type,
{ "Type", "nsrp.type",
FT_UINT8, BASE_DEC, nsrp_msg_type_vals, 0,
"NSRP Message Type", HFILL }
},
{ &hf_nsrp_clust_id,
{ "Clust ID", "nsrp.clustid",
FT_UINT8, BASE_DEC, NULL, 0,
"NSRP CLUST ID", HFILL }
},
{ &hf_nsrp_msg_flag,
{ "Flag", "nsrp.flag",
FT_UINT8, BASE_DEC, NULL, 0,
"NSRP FLAG", HFILL }
},
{ &hf_nsrp_len,
{ "Length", "nsrp.length",
FT_UINT16, BASE_DEC, NULL, 0,
"NSRP Length", HFILL }
},
{ &hf_nsrp_ha_port,
{ "Port", "nsrp.haport",
FT_UINT8, BASE_DEC, NULL, 0,
"NSRP HA Port", HFILL }
},
{ &hf_nsrp_not_used,
{ "Not used", "nsrp.notused",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nsrp_dst_unit,
{ "Destination", "nsrp.dst",
FT_UINT32, BASE_DEC, NULL, 0,
"DESTINATION UNIT INFORMATION", HFILL }
},
{ &hf_nsrp_src_unit,
{ "Source", "nsrp.src",
FT_UINT32, BASE_DEC, NULL, 0,
"SOURCE UNIT INFORMATION", HFILL }
},
{ &hf_nsrp_msgtype,
{ "MsgType", "nsrp.msgtype",
FT_UINT8, BASE_DEC, VALS(nsrp_msgtype_vals), 0,
"Message Type", HFILL }
},
{ &hf_nsrp_wst_group,
{ "Wst group", "nsrp.wst",
FT_UINT8, BASE_DEC, NULL, 0,
"NSRP WST GROUP", HFILL }
},
{ &hf_nsrp_hst_group,
{ "Hst group", "nsrp.hst",
FT_UINT8, BASE_DEC, NULL, 0,
"NSRP HST GROUP", HFILL }
},
{ &hf_nsrp_msgflag,
{ "Msgflag", "nsrp.msgflag",
FT_UINT8, BASE_DEC, VALS(nsrp_flag_vals), 0,
"NSRP MSG FLAG", HFILL }
},
{ &hf_nsrp_msglen,
{ "Msg Length", "nsrp.msglen",
FT_UINT16, BASE_DEC, NULL, 0,
"NSRP MESSAGE LENGTH", HFILL }
},
{ &hf_nsrp_encflag,
{ "Enc Flag", "nsrp.encflag",
FT_UINT8, BASE_DEC, VALS(nsrp_encflag_vals), 0,
"NSRP ENCRYPT FLAG", HFILL }
},
#if 0
{ &hf_nsrp_notused,
{ "Not Used", "nsrp.notused",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
#endif
{ &hf_nsrp_total_size,
{ "Total Size", "nsrp.totalsize",
FT_UINT32, BASE_DEC, NULL, 0,
"NSRP MSG TOTAL MESSAGE", HFILL }
},
{ &hf_nsrp_ns,
{ "Ns", "nsrp.ns",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nsrp_nr,
{ "Nr", "nsrp.nr",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nsrp_no_used,
{ "Reserved", "nsrp.reserved",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_nsrp_checksum,
{ "Checksum", "nsrp.checksum",
FT_UINT16, BASE_HEX, NULL, 0,
"NSRP PACKET CHECKSUM", HFILL }
},
{ &hf_nsrp_authflag,
{ "AuthFlag", "nsrp.authflag",
FT_UINT8, BASE_HEX, NULL, 0,
"NSRP Auth Flag", HFILL }
},
{ &hf_nsrp_priority,
{ "Priority", "nsrp.priority",
FT_UINT8, BASE_HEX, NULL, 0,
"NSRP Priority", HFILL }
},
{ &hf_nsrp_dummy,
{ "Dummy", "nsrp.dummy",
FT_UINT8, BASE_HEX, NULL, 0,
"NSRP Dummy", HFILL }
},
{ &hf_nsrp_authchecksum,
{ "Checksum", "nsrp.authchecksum",
FT_UINT16, BASE_HEX, NULL, 0,
"NSRP AUTH CHECKSUM", HFILL }
},
{ &hf_nsrp_ifnum,
{ "Ifnum", "nsrp.ifnum",
FT_UINT16, BASE_HEX, NULL, 0,
"NSRP IfNum", HFILL }
},
{ &hf_nsrp_data,
{ "Data", "nsrp.data",
FT_STRING, BASE_NONE, NULL, 0,
"PADDING", HFILL }
}
};
static gint *ett[] = {
&ett_nsrp
};
proto_nsrp = proto_register_protocol("Juniper Netscreen Redundant Protocol",
"NSRP", "nsrp");
proto_register_field_array(proto_nsrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nsrp(void)
{
dissector_handle_t nsrp_handle;
nsrp_handle = create_dissector_handle(dissect_nsrp, proto_nsrp);
dissector_add_uint("ethertype", ETHERTYPE_NSRP, nsrp_handle);
}
