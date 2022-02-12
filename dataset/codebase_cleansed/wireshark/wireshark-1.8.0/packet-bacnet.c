static const char*
bacnet_mesgtyp_name (guint8 bacnet_mesgtyp){
static const char *type_names[] = {
"Who-Is-Router-To-Network",
"I-Am-Router-To-Network",
"I-Could-Be-Router-To-Network",
"Reject-Message-To-Network",
"Router-Busy-To-Network",
"Router-Available-To-Network",
"Initialize-Routing-Table",
"Initialize-Routing-Table-Ack",
"Establish-Connection-To-Network",
"Disconnect-Connection-To-Network"
};
if(bacnet_mesgtyp < 0x0a) {
return type_names[bacnet_mesgtyp];
} else {
return (bacnet_mesgtyp < 0x80)? "Reserved for Use by ASHRAE" : "Vendor Proprietary Message";
}
}
static const char*
bacnet_rejectreason_name (guint8 bacnet_rejectreason) {
static const char *type_names[] = {
"Other error.",
"The router is not directly connected to DNET and cannot find a router to DNET on any directly connected network using Who-Is-Router-To-Network messages.",
"The router is busy and unable to accept messages for the specified DNET at the present time.",
"It is an unknown network layer message type.",
"The message is too long to be routed to this DNET.",
"The router is no longer directly connected to DNET but can reconnect if requested.",
"The router is no longer directly connected to DNET and cannot reconnect even if requested."
};
return (bacnet_rejectreason > 6)? "Invalid Rejection Reason.": type_names[bacnet_rejectreason];
}
static void
dissect_bacnet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_item *ct;
proto_tree *bacnet_tree;
proto_tree *control_tree;
gint offset;
guint8 bacnet_version;
guint8 bacnet_control;
guint8 bacnet_dlen;
guint8 bacnet_slen;
guint8 bacnet_mesgtyp;
guint8 bacnet_rejectreason;
guint8 bacnet_rportnum;
guint8 bacnet_pinfolen;
guint8 i;
tvbuff_t *next_tvb;
guint32 vendor_id;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BACnet-NPDU");
col_set_str(pinfo->cinfo, COL_INFO, "Building Automation and Control Network NPDU");
offset = 0;
bacnet_version = tvb_get_guint8(tvb, offset);
bacnet_control = tvb_get_guint8(tvb, offset+1);
ti = proto_tree_add_item(tree, proto_bacnet, tvb, 0, -1, ENC_NA);
bacnet_tree = proto_item_add_subtree(ti, ett_bacnet);
proto_tree_add_uint_format_value(bacnet_tree, hf_bacnet_version, tvb,
offset, 1,
bacnet_version,"0x%02x (%s)",bacnet_version,
(bacnet_version == 0x01)?"ASHRAE 135-1995":"unknown");
offset ++;
ct = proto_tree_add_uint(bacnet_tree, hf_bacnet_control,
tvb, offset, 1, bacnet_control);
control_tree = proto_item_add_subtree(ct, ett_bacnet_control);
proto_tree_add_boolean(control_tree, hf_bacnet_control_net,
tvb, offset, 1, bacnet_control);
proto_tree_add_boolean(control_tree, hf_bacnet_control_res1, tvb,
offset, 1, bacnet_control);
proto_tree_add_boolean(control_tree, hf_bacnet_control_dest, tvb,
offset, 1, bacnet_control);
proto_tree_add_boolean(control_tree, hf_bacnet_control_res2, tvb,
offset, 1, bacnet_control);
proto_tree_add_boolean(control_tree, hf_bacnet_control_src, tvb,
offset, 1, bacnet_control);
proto_tree_add_boolean(control_tree, hf_bacnet_control_expect, tvb,
offset, 1, bacnet_control);
proto_tree_add_boolean(control_tree, hf_bacnet_control_prio_high,
tvb, offset, 1, bacnet_control);
proto_tree_add_boolean(control_tree, hf_bacnet_control_prio_low,
tvb, offset, 1, bacnet_control);
offset ++;
if (bacnet_control & BAC_CONTROL_DEST) {
proto_tree_add_item(bacnet_tree, hf_bacnet_dnet,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
bacnet_dlen = tvb_get_guint8(tvb, offset);
if( bacnet_dlen == 0) {
proto_tree_add_uint_format_value(bacnet_tree,
hf_bacnet_dlen, tvb, offset, 1, bacnet_dlen,
"%d indicates Broadcast on Destination Network",
bacnet_dlen);
offset ++;
} else if (bacnet_dlen==6) {
proto_tree_add_uint(bacnet_tree, hf_bacnet_dlen,
tvb, offset, 1, bacnet_dlen);
offset ++;
proto_tree_add_item(bacnet_tree,
hf_bacnet_dadr_eth, tvb, offset,
bacnet_dlen, ENC_NA);
offset += bacnet_dlen;
} else if (bacnet_dlen==1) {
proto_tree_add_uint(bacnet_tree, hf_bacnet_dlen,
tvb, offset, 1, bacnet_dlen);
offset ++;
proto_tree_add_item(bacnet_tree,
hf_bacnet_dadr_mstp, tvb, offset,
bacnet_dlen, ENC_BIG_ENDIAN);
offset += bacnet_dlen;
} else if (bacnet_dlen<7) {
proto_tree_add_uint(bacnet_tree, hf_bacnet_dlen,
tvb, offset, 1, bacnet_dlen);
offset ++;
proto_tree_add_item(bacnet_tree,
hf_bacnet_dadr_tmp, tvb, offset,
bacnet_dlen, ENC_NA);
offset += bacnet_dlen;
} else {
proto_tree_add_uint_format_value(bacnet_tree,
hf_bacnet_dlen, tvb, offset, 1, bacnet_dlen,
"%d invalid!",
bacnet_dlen);
}
}
if (bacnet_control & BAC_CONTROL_SRC) {
proto_tree_add_uint(bacnet_tree, hf_bacnet_snet,
tvb, offset, 2, tvb_get_ntohs(tvb, offset));
offset += 2;
bacnet_slen = tvb_get_guint8(tvb, offset);
if( bacnet_slen == 0) {
proto_tree_add_uint_format_value(bacnet_tree,
hf_bacnet_slen, tvb, offset, 1, bacnet_slen,
"%d invalid!",
bacnet_slen);
offset ++;
} else if (bacnet_slen==6) {
proto_tree_add_uint(bacnet_tree, hf_bacnet_slen,
tvb, offset, 1, bacnet_slen);
offset ++;
proto_tree_add_item(bacnet_tree,
hf_bacnet_sadr_eth, tvb, offset,
bacnet_slen, ENC_NA);
offset += bacnet_slen;
} else if (bacnet_slen==1) {
proto_tree_add_uint(bacnet_tree, hf_bacnet_slen,
tvb, offset, 1, bacnet_slen);
offset ++;
proto_tree_add_item(bacnet_tree,
hf_bacnet_sadr_mstp, tvb, offset,
bacnet_slen, ENC_BIG_ENDIAN);
offset += bacnet_slen;
} else if (bacnet_slen<6) {
proto_tree_add_uint(bacnet_tree, hf_bacnet_slen,
tvb, offset, 1, bacnet_slen);
offset ++;
proto_tree_add_item(bacnet_tree,
hf_bacnet_sadr_tmp, tvb, offset,
bacnet_slen, ENC_NA);
offset += bacnet_slen;
} else {
proto_tree_add_uint_format_value(bacnet_tree,
hf_bacnet_slen, tvb, offset, 1, bacnet_slen,
"%d invalid!",
bacnet_slen);
offset ++;
}
}
if (bacnet_control & BAC_CONTROL_DEST) {
proto_tree_add_item(bacnet_tree, hf_bacnet_hopc,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
}
if (bacnet_control & BAC_CONTROL_NET) {
bacnet_mesgtyp = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(bacnet_tree,
hf_bacnet_mesgtyp, tvb, offset, 1, bacnet_mesgtyp,
"%02x (%s)", bacnet_mesgtyp,
bacnet_mesgtyp_name(bacnet_mesgtyp));
col_add_str(pinfo->cinfo, COL_INFO,
bacnet_mesgtyp_name(bacnet_mesgtyp));
offset ++;
if (bacnet_mesgtyp > 0x7f) {
next_tvb = tvb_new_subset_remaining(tvb, offset-1);
vendor_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(bacnet_tree, hf_bacnet_vendor, tvb,
offset, 2, vendor_id);
offset += 2;
if (dissector_try_uint(bacnet_dissector_table,
vendor_id, next_tvb, pinfo, bacnet_tree)) {
offset += tvb_length(next_tvb) -3;
}
}
if (bacnet_mesgtyp == BAC_NET_ICB_R) {
proto_tree_add_item(bacnet_tree, hf_bacnet_dnet,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(bacnet_tree, hf_bacnet_perf,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
}
if (bacnet_mesgtyp == BAC_NET_REJ) {
bacnet_rejectreason = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(bacnet_tree,
hf_bacnet_rejectreason,
tvb, offset, 1,
bacnet_rejectreason, "%d (%s)",
bacnet_rejectreason,
bacnet_rejectreason_name(bacnet_rejectreason));
offset ++;
proto_tree_add_item(bacnet_tree, hf_bacnet_dnet,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if ((bacnet_mesgtyp == BAC_NET_R_BUSY) ||
(bacnet_mesgtyp == BAC_NET_WHO_R) ||
(bacnet_mesgtyp == BAC_NET_R_AVA) ||
(bacnet_mesgtyp == BAC_NET_IAM_R) ) {
while(tvb_reported_length_remaining(tvb, offset) > 1 ) {
proto_tree_add_item(bacnet_tree, hf_bacnet_dnet,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
if ( (bacnet_mesgtyp == BAC_NET_INIT_RTAB) ||
(bacnet_mesgtyp == BAC_NET_INIT_RTAB_ACK) ) {
bacnet_rportnum = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(bacnet_tree, hf_bacnet_rportnum,
tvb, offset, 1, bacnet_rportnum);
offset ++;
for(i=0; i<bacnet_rportnum; i++) {
proto_tree_add_item(bacnet_tree, hf_bacnet_dnet,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(bacnet_tree, hf_bacnet_portid,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
bacnet_pinfolen = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(bacnet_tree, hf_bacnet_pinfolen,
tvb, offset, 1, bacnet_pinfolen);
offset ++;
proto_tree_add_text(bacnet_tree, tvb, offset,
bacnet_pinfolen, "Port Info: %s",
tvb_bytes_to_str(tvb, offset, bacnet_pinfolen));
offset += bacnet_pinfolen;
}
}
if (bacnet_mesgtyp == BAC_NET_EST_CON) {
proto_tree_add_item(bacnet_tree, hf_bacnet_dnet,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(bacnet_tree, hf_bacnet_term_time_value,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
}
if (bacnet_mesgtyp == BAC_NET_DISC_CON) {
proto_tree_add_item(bacnet_tree, hf_bacnet_dnet,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
proto_item_set_len(ti, offset);
next_tvb = tvb_new_subset_remaining(tvb,offset);
if (bacnet_control & BAC_CONTROL_NET) {
call_dissector(data_handle, next_tvb, pinfo, tree);
} else {
call_dissector(bacapp_handle, next_tvb, pinfo, tree);
}
}
void
proto_register_bacnet(void)
{
static hf_register_info hf[] = {
{ &hf_bacnet_version,
{ "Version", "bacnet.version",
FT_UINT8, BASE_DEC, NULL, 0,
"BACnet Version", HFILL }
},
{ &hf_bacnet_control,
{ "Control", "bacnet.control",
FT_UINT8, BASE_HEX, NULL, 0,
"BACnet Control", HFILL }
},
{ &hf_bacnet_control_net,
{ "NSDU contains",
"bacnet.control_net",
FT_BOOLEAN, 8, TFS(&control_net_set_high),
BAC_CONTROL_NET, "BACnet Control", HFILL }
},
{ &hf_bacnet_control_res1,
{ "Reserved",
"bacnet.control_res1",
FT_BOOLEAN, 8, TFS(&control_res_high),
BAC_CONTROL_RES1, "BACnet Control", HFILL }
},
{ &hf_bacnet_control_dest,
{ "Destination Specifier",
"bacnet.control_dest",
FT_BOOLEAN, 8, TFS(&control_dest_high),
BAC_CONTROL_DEST, "BACnet Control", HFILL }
},
{ &hf_bacnet_control_res2,
{ "Reserved",
"bacnet.control_res2",
FT_BOOLEAN, 8, TFS(&control_res_high),
BAC_CONTROL_RES2, "BACnet Control", HFILL }
},
{ &hf_bacnet_control_src,
{ "Source specifier",
"bacnet.control_src",
FT_BOOLEAN, 8, TFS(&control_src_high),
BAC_CONTROL_SRC, "BACnet Control", HFILL }
},
{ &hf_bacnet_control_expect,
{ "Expecting Reply",
"bacnet.control_expect",
FT_BOOLEAN, 8, TFS(&control_expect_high),
BAC_CONTROL_EXPECT, "BACnet Control", HFILL }
},
{ &hf_bacnet_control_prio_high,
{ "Priority",
"bacnet.control_prio_high",
FT_BOOLEAN, 8, TFS(&control_prio_high_high),
BAC_CONTROL_PRIO_HIGH, "BACnet Control", HFILL }
},
{ &hf_bacnet_control_prio_low,
{ "Priority",
"bacnet.control_prio_low",
FT_BOOLEAN, 8, TFS(&control_prio_low_high),
BAC_CONTROL_PRIO_LOW, "BACnet Control", HFILL }
},
{ &hf_bacnet_dnet,
{ "Destination Network Address", "bacnet.dnet",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_dlen,
{ "Destination MAC Layer Address Length", "bacnet.dlen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_dadr_eth,
{ "Destination ISO 8802-3 MAC Address", "bacnet.dadr_eth",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_dadr_mstp,
{ "DADR", "bacnet.dadr_mstp",
FT_UINT8, BASE_DEC, NULL, 0,
"Destination MS/TP or ARCNET MAC Address", HFILL }
},
{ &hf_bacnet_dadr_tmp,
{ "Unknown Destination MAC", "bacnet.dadr_tmp",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_snet,
{ "Source Network Address", "bacnet.snet",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_slen,
{ "Source MAC Layer Address Length", "bacnet.slen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_sadr_eth,
{ "SADR", "bacnet.sadr_eth",
FT_ETHER, BASE_NONE, NULL, 0,
"Source ISO 8802-3 MAC Address", HFILL }
},
{ &hf_bacnet_sadr_mstp,
{ "SADR", "bacnet.sadr_mstp",
FT_UINT8, BASE_DEC, NULL, 0,
"Source MS/TP or ARCNET MAC Address", HFILL }
},
{ &hf_bacnet_sadr_tmp,
{ "Unknown Source MAC", "bacnet.sadr_tmp",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_hopc,
{ "Hop Count", "bacnet.hopc",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_mesgtyp,
{ "Network Layer Message Type", "bacnet.mesgtyp",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_vendor,
{ "Vendor ID", "bacnet.vendor",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_perf,
{ "Performance Index", "bacnet.perf",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_rejectreason,
{ "Reject Reason", "bacnet.rejectreason",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_rportnum,
{ "Number of Port Mappings", "bacnet.rportnum",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_pinfolen,
{ "Port Info Length", "bacnet.pinfolen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_portid,
{ "Port ID", "bacnet.portid",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_bacnet_term_time_value,
{ "Termination Time Value (seconds)", "bacnet.term_time_value",
FT_UINT8, BASE_DEC, NULL, 0,
"Termination Time Value", HFILL }
}
};
static gint *ett[] = {
&ett_bacnet,
&ett_bacnet_control,
};
proto_bacnet = proto_register_protocol("Building Automation and Control Network NPDU",
"BACnet", "bacnet");
proto_register_field_array(proto_bacnet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("bacnet", dissect_bacnet, proto_bacnet);
bacnet_dissector_table = register_dissector_table("bacnet.vendor",
"BACnet Vendor Identifier",
FT_UINT8, BASE_HEX);
}
void
proto_reg_handoff_bacnet(void)
{
dissector_handle_t bacnet_handle;
bacnet_handle = find_dissector("bacnet");
dissector_add_uint("bvlc.function", 0x04, bacnet_handle);
dissector_add_uint("bvlc.function", 0x09, bacnet_handle);
dissector_add_uint("bvlc.function", 0x0a, bacnet_handle);
dissector_add_uint("bvlc.function", 0x0b, bacnet_handle);
dissector_add_uint("llc.dsap", SAP_BACNET, bacnet_handle);
bacapp_handle = find_dissector("bacapp");
data_handle = find_dissector("data");
}
