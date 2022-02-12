static int
dissect_pagp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint32 raw_word;
guint16 num_tlvs;
guint16 tlv;
guint16 len;
guint16 ii;
guint16 offset = PAGP_FIRST_TLV;
guint8 raw_octet;
guint8 flags;
proto_tree *pagp_tree = NULL;
proto_item *pagp_item, *len_item;
proto_tree *tlv_tree;
static const int * pagp_flags[] = {
&hf_pagp_flags_slow_hello,
&hf_pagp_flags_auto_mode,
&hf_pagp_flags_consistent_state,
NULL,
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PAGP");
col_clear(pinfo->cinfo, COL_INFO);
raw_octet = tvb_get_guint8(tvb, PAGP_VERSION_NUMBER);
if (tree) {
pagp_item = proto_tree_add_protocol_format(tree, proto_pagp, tvb,
0, -1, "Port Aggregation Protocol");
pagp_tree = proto_item_add_subtree(pagp_item, ett_pagp);
proto_tree_add_uint(pagp_tree, hf_pagp_version_number, tvb,
PAGP_VERSION_NUMBER, 1, raw_octet);
}
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str_const(raw_octet, pdu_vers, "Unknown PDU version"));
if (raw_octet == PAGP_FLUSH_PDU) {
col_append_fstr(pinfo->cinfo, COL_INFO, "; Local DevID: %s",
tvb_ether_to_str(tvb, PAGP_FLUSH_LOCAL_DEVICE_ID));
proto_tree_add_item(pagp_tree, hf_pagp_flush_local_device_id, tvb,
PAGP_FLUSH_LOCAL_DEVICE_ID, 6, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Partner DevID: %s",
tvb_ether_to_str(tvb, PAGP_FLUSH_PARTNER_DEVICE_ID));
proto_tree_add_item(pagp_tree, hf_pagp_flush_partner_device_id, tvb,
PAGP_FLUSH_PARTNER_DEVICE_ID, 6, ENC_NA);
raw_word = tvb_get_ntohl(tvb, PAGP_FLUSH_TRANSACTION_ID);
col_append_fstr(pinfo->cinfo, COL_INFO, "; Transaction ID: 0x%x ", raw_word);
proto_tree_add_uint(pagp_tree, hf_pagp_flush_transaction_id, tvb,
PAGP_FLUSH_TRANSACTION_ID, 4, raw_word);
return tvb_captured_length(tvb);
}
flags = tvb_get_guint8(tvb, PAGP_FLAGS);
col_append_fstr(pinfo->cinfo, COL_INFO, "; Flags 0x%x", flags);
proto_tree_add_bitmask(pagp_tree, tvb, PAGP_FLAGS, hf_pagp_flags, ett_pagp_flags, pagp_flags, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "; Local DevID: %s",
tvb_ether_to_str(tvb, PAGP_LOCAL_DEVICE_ID));
proto_tree_add_item(pagp_tree, hf_pagp_local_device_id, tvb,
PAGP_LOCAL_DEVICE_ID, 6, ENC_NA);
if (tree) {
proto_tree_add_item(pagp_tree, hf_pagp_local_learn_cap, tvb,
PAGP_LOCAL_LEARN_CAP, 1, ENC_NA);
proto_tree_add_item(pagp_tree, hf_pagp_local_port_priority, tvb,
PAGP_LOCAL_PORT_PRIORITY, 1, ENC_NA);
proto_tree_add_item(pagp_tree, hf_pagp_local_sent_port_ifindex, tvb,
PAGP_LOCAL_SENT_PORT_IFINDEX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pagp_tree, hf_pagp_local_group_capability, tvb,
PAGP_LOCAL_GROUP_CAPABILITY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pagp_tree, hf_pagp_local_group_ifindex, tvb,
PAGP_LOCAL_GROUP_IFINDEX, 4, ENC_BIG_ENDIAN);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Partner DevID: %s",
tvb_ether_to_str(tvb, PAGP_PARTNER_DEVICE_ID));
proto_tree_add_item(pagp_tree, hf_pagp_partner_device_id, tvb,
PAGP_PARTNER_DEVICE_ID, 6, ENC_NA);
proto_tree_add_item(pagp_tree, hf_pagp_partner_learn_cap, tvb,
PAGP_PARTNER_LEARN_CAP, 1, ENC_NA);
proto_tree_add_item(pagp_tree, hf_pagp_partner_port_priority, tvb,
PAGP_PARTNER_PORT_PRIORITY, 1, ENC_NA);
proto_tree_add_item(pagp_tree, hf_pagp_partner_sent_port_ifindex, tvb,
PAGP_PARTNER_SENT_PORT_IFINDEX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pagp_tree, hf_pagp_partner_group_capability, tvb,
PAGP_PARTNER_GROUP_CAPABILITY, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pagp_tree, hf_pagp_partner_group_ifindex, tvb,
PAGP_PARTNER_GROUP_IFINDEX, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pagp_tree, hf_pagp_partner_count, tvb,
PAGP_PARTNER_COUNT, 2, ENC_BIG_ENDIAN);
num_tlvs = tvb_get_ntohs(tvb, PAGP_NUM_TLVS);
proto_tree_add_uint(pagp_tree, hf_pagp_num_tlvs, tvb,
PAGP_NUM_TLVS, 2, num_tlvs);
for ( ii = 0; ii < num_tlvs; ii++ ) {
tlv = tvb_get_ntohs(tvb, offset);
len = tvb_get_ntohs(tvb, offset + 2);
tlv_tree = proto_tree_add_subtree_format(pagp_tree, tvb, offset, len,
ett_pagp_tlvs, NULL, "TLV Entry #%d", ii+1);
proto_tree_add_uint(tlv_tree, hf_pagp_tlv, tvb, offset, 2, tlv);
len_item = proto_tree_add_uint(tlv_tree, hf_pagp_tlv_length, tvb, offset+2, 2, len);
if ( len == 0 ) {
expert_add_info_format(pinfo, len_item, &ei_pagp_tlv_length,
"Unknown data - TLV len=0");
return offset;
}
if ( tvb_reported_length_remaining(tvb, offset) < len ) {
expert_add_info_format(pinfo, len_item, &ei_pagp_tlv_length,
"TLV length too large");
return offset;
}
switch (tlv) {
case PAGP_TLV_DEVICE_NAME:
proto_tree_add_item(tlv_tree, hf_pagp_tlv_device_name,
tvb, offset+4, len-4, ENC_NA|ENC_ASCII);
break;
case PAGP_TLV_PORT_NAME:
proto_tree_add_item(tlv_tree, hf_pagp_tlv_port_name,
tvb, offset+4, len-4, ENC_NA|ENC_ASCII);
break;
case PAGP_TLV_AGPORT_MAC:
proto_tree_add_item(tlv_tree, hf_pagp_tlv_agport_mac,
tvb, offset+4, 6, ENC_NA);
break;
case PAGP_TLV_RESERVED:
break;
}
offset += len;
}
return tvb_captured_length(tvb);
}
void
proto_register_pagp(void)
{
static hf_register_info hf[] = {
{ &hf_pagp_version_number,
{ "Version", "pagp.version",
FT_UINT8, BASE_HEX, VALS(pdu_vers), 0x0,
"Identifies the PAgP PDU version: 1 = Info, 2 = Flush", HFILL }},
{ &hf_pagp_flags,
{ "Flags", "pagp.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Information flags", HFILL }},
{ &hf_pagp_flags_slow_hello,
{ "Slow Hello", "pagp.flags.slowhello",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PAGP_FLAGS_SLOW_HELLO,
"1 = using Slow Hello, 0 = Slow Hello disabled", HFILL }},
{ &hf_pagp_flags_auto_mode,
{ "Auto Mode", "pagp.flags.automode",
FT_BOOLEAN, 8, TFS(&automode), PAGP_FLAGS_AUTO_MODE,
"1 = Auto Mode enabled, 0 = Desirable Mode", HFILL }},
{ &hf_pagp_flags_consistent_state,
{ "Consistent State", "pagp.flags.state",
FT_BOOLEAN, 8, NULL, PAGP_FLAGS_CONSISTENT_STATE,
"1 = Consistent State, 0 = Not Ready", HFILL }},
{ &hf_pagp_local_device_id,
{ "Local Device ID", "pagp.localdevid",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pagp_local_learn_cap,
{ "Local Learn Capability", "pagp.localearncap",
FT_UINT8, BASE_HEX, VALS(learn_cap), 0x0,
NULL, HFILL }},
{ &hf_pagp_local_port_priority,
{ "Local Port Hot Standby Priority", "pagp.localportpri",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The local hot standby priority assigned to this port", HFILL }},
{ &hf_pagp_local_sent_port_ifindex,
{ "Local Sent Port ifindex", "pagp.localsentportifindex",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The interface index of the local port used to send PDU", HFILL }},
{ &hf_pagp_local_group_capability,
{ "Local Group Capability", "pagp.localgroupcap",
FT_UINT32, BASE_HEX, NULL, 0x0,
"The local group capability", HFILL }},
{ &hf_pagp_local_group_ifindex,
{ "Local Group ifindex", "pagp.localgroupifindex",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The local group interface index", HFILL }},
{ &hf_pagp_partner_device_id,
{ "Partner Device ID", "pagp.partnerdevid",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Remote Device ID (MAC)", HFILL }},
{ &hf_pagp_partner_learn_cap,
{ "Partner Learn Capability", "pagp.partnerlearncap",
FT_UINT8, BASE_HEX, VALS(learn_cap), 0x0,
"Remote learn capability", HFILL }},
{ &hf_pagp_partner_port_priority,
{ "Partner Port Hot Standby Priority", "pagp.partnerportpri",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Remote port priority", HFILL }},
{ &hf_pagp_partner_sent_port_ifindex,
{ "Partner Sent Port ifindex", "pagp.partnersentportifindex",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Remote port interface index sent", HFILL }},
{ &hf_pagp_partner_group_capability,
{ "Partner Group Capability", "pagp.partnergroupcap",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Remote group capability", HFILL }},
{ &hf_pagp_partner_group_ifindex,
{ "Partner Group ifindex", "pagp.partnergroupifindex",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Remote group interface index", HFILL }},
{ &hf_pagp_partner_count,
{ "Partner Count", "pagp.partnercount",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pagp_num_tlvs,
{ "Number of TLVs", "pagp.numtlvs",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of TLVs following", HFILL }},
{ &hf_pagp_tlv,
{ "Type", "pagp.tlv",
FT_UINT16, BASE_DEC, VALS(tlv_types), 0x0,
"Type/Length/Value", HFILL }},
{ &hf_pagp_tlv_length,
{ "Length", "pagp.tlv_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pagp_tlv_device_name,
{ "Device Name", "pagp.tlvdevname",
FT_STRING, BASE_NONE, NULL, 0x0,
"sysName of device", HFILL }},
{ &hf_pagp_tlv_port_name,
{ "Physical Port Name", "pagp.tlvportname",
FT_STRING, BASE_NONE, NULL, 0x0,
"Name of port used to send PDU", HFILL }},
{ &hf_pagp_tlv_agport_mac,
{ "Agport MAC Address", "pagp.tlvagportmac",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Source MAC on frames for this aggregate", HFILL }},
{ &hf_pagp_flush_local_device_id,
{ "Flush Local Device ID", "pagp.flushlocaldevid",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pagp_flush_partner_device_id,
{ "Flush Partner Device ID", "pagp.flushpartnerdevid",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Flush remote device ID", HFILL }},
{ &hf_pagp_flush_transaction_id,
{ "Transaction ID", "pagp.transid",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Flush transaction ID", HFILL }},
};
static gint *ett[] = {
&ett_pagp,
&ett_pagp_flags,
&ett_pagp_tlvs,
};
static ei_register_info ei[] = {
{ &ei_pagp_tlv_length, { "pagp.tlv_length.invalid", PI_PROTOCOL, PI_WARN, "Invalid TLV length", EXPFILL }},
};
expert_module_t* expert_pagp;
proto_pagp = proto_register_protocol("Port Aggregation Protocol", "PAGP", "pagp");
proto_register_field_array(proto_pagp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pagp = expert_register_protocol(proto_pagp);
expert_register_field_array(expert_pagp, ei, array_length(ei));
}
void
proto_reg_handoff_pagp(void)
{
dissector_handle_t pagp_handle;
pagp_handle = create_dissector_handle(dissect_pagp, proto_pagp);
dissector_add_uint("llc.cisco_pid", 0x0104, pagp_handle);
}
