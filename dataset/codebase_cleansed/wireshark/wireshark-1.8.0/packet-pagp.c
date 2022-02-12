static void
dissect_pagp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 raw_word;
guint16 raw_half_word;
guint16 num_tlvs;
guint16 tlv;
guint16 len;
guint16 i;
guint16 offset = PAGP_FIRST_TLV;
guint8 raw_octet;
guint8 flags;
guchar *ch;
proto_tree *pagp_tree = NULL;
proto_item *pagp_item;
proto_tree *flags_tree;
proto_item *flags_item;
proto_tree *tlv_tree;
proto_item *tlv_item;
const char *sep;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PAGP");
col_clear(pinfo->cinfo, COL_INFO);
pinfo->current_proto = "PAGP";
raw_octet = tvb_get_guint8(tvb, PAGP_VERSION_NUMBER);
if (tree) {
pagp_item = proto_tree_add_protocol_format(tree, proto_pagp, tvb,
0, -1, "Port Aggregation Protocol");
pagp_tree = proto_item_add_subtree(pagp_item, ett_pagp);
proto_tree_add_uint(pagp_tree, hf_pagp_version_number, tvb,
PAGP_VERSION_NUMBER, 1, raw_octet);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(raw_octet, pdu_vers, "Unknown PDU version"));
}
if (raw_octet == PAGP_FLUSH_PDU) {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "; Local DevID: %s",
tvb_ether_to_str(tvb, PAGP_FLUSH_LOCAL_DEVICE_ID));
}
if (tree) {
proto_tree_add_item(pagp_tree, hf_pagp_flush_local_device_id, tvb,
PAGP_FLUSH_LOCAL_DEVICE_ID, 6, ENC_NA);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Partner DevID: %s",
tvb_ether_to_str(tvb, PAGP_FLUSH_PARTNER_DEVICE_ID));
}
if (tree) {
proto_tree_add_item(pagp_tree, hf_pagp_flush_partner_device_id, tvb,
PAGP_FLUSH_PARTNER_DEVICE_ID, 6, ENC_NA);
}
raw_word = tvb_get_ntohl(tvb, PAGP_FLUSH_TRANSACTION_ID);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO,
"; Transaction ID: 0x%x ", raw_word);
}
if (tree) {
proto_tree_add_uint(pagp_tree, hf_pagp_flush_transaction_id, tvb,
PAGP_FLUSH_TRANSACTION_ID, 4, raw_word);
}
return;
}
flags = tvb_get_guint8(tvb, PAGP_FLAGS);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "; Flags 0x%x", flags);
}
if (tree) {
flags_item = proto_tree_add_uint(pagp_tree, hf_pagp_flags, tvb,
PAGP_FLAGS, 1, flags);
flags_tree = proto_item_add_subtree(flags_item, ett_pagp_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & PAGP_FLAGS_SLOW_HELLO, flags_item, "%sSlow Hello");
proto_tree_add_boolean(flags_tree, hf_pagp_flags_slow_hello, tvb,
PAGP_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & PAGP_FLAGS_AUTO_MODE, flags_item, "%sAuto Mode");
proto_tree_add_boolean(flags_tree, hf_pagp_flags_auto_mode, tvb,
PAGP_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & PAGP_FLAGS_CONSISTENT_STATE, flags_item,
"%sConsistent State");
proto_tree_add_boolean(flags_tree, hf_pagp_flags_consistent_state, tvb,
PAGP_FLAGS, 1, flags);
sep = cont_sep;
if (sep != initial_sep) {
proto_item_append_text(flags_item, ")");
}
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "; Local DevID: %s",
tvb_ether_to_str(tvb, PAGP_LOCAL_DEVICE_ID));
}
if (tree) {
proto_tree_add_item(pagp_tree, hf_pagp_local_device_id, tvb,
PAGP_LOCAL_DEVICE_ID, 6, ENC_NA);
}
if (tree) {
raw_octet = tvb_get_guint8(tvb, PAGP_LOCAL_LEARN_CAP);
proto_tree_add_uint(pagp_tree, hf_pagp_local_learn_cap, tvb,
PAGP_LOCAL_LEARN_CAP, 1, raw_octet);
raw_octet = tvb_get_guint8(tvb, PAGP_LOCAL_PORT_PRIORITY);
proto_tree_add_uint(pagp_tree, hf_pagp_local_port_priority, tvb,
PAGP_LOCAL_PORT_PRIORITY, 1, raw_octet);
raw_word = tvb_get_ntohl(tvb, PAGP_LOCAL_SENT_PORT_IFINDEX);
proto_tree_add_uint(pagp_tree, hf_pagp_local_sent_port_ifindex, tvb,
PAGP_LOCAL_SENT_PORT_IFINDEX, 4, raw_word);
raw_word = tvb_get_ntohl(tvb, PAGP_LOCAL_GROUP_CAPABILITY);
proto_tree_add_uint(pagp_tree, hf_pagp_local_group_capability, tvb,
PAGP_LOCAL_GROUP_CAPABILITY, 4, raw_word);
raw_word = tvb_get_ntohl(tvb, PAGP_LOCAL_GROUP_IFINDEX);
proto_tree_add_uint(pagp_tree, hf_pagp_local_group_ifindex, tvb,
PAGP_LOCAL_GROUP_IFINDEX, 4, raw_word);
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Partner DevID: %s",
tvb_ether_to_str(tvb, PAGP_PARTNER_DEVICE_ID));
}
if (tree) {
proto_tree_add_item(pagp_tree, hf_pagp_partner_device_id, tvb,
PAGP_PARTNER_DEVICE_ID, 6, ENC_NA);
}
if (tree) {
raw_octet = tvb_get_guint8(tvb, PAGP_PARTNER_LEARN_CAP);
proto_tree_add_uint(pagp_tree, hf_pagp_partner_learn_cap, tvb,
PAGP_PARTNER_LEARN_CAP, 1, raw_octet);
raw_octet = tvb_get_guint8(tvb, PAGP_PARTNER_PORT_PRIORITY);
proto_tree_add_uint(pagp_tree, hf_pagp_partner_port_priority, tvb,
PAGP_PARTNER_PORT_PRIORITY, 1, raw_octet);
raw_word = tvb_get_ntohl(tvb, PAGP_PARTNER_SENT_PORT_IFINDEX);
proto_tree_add_uint(pagp_tree, hf_pagp_partner_sent_port_ifindex, tvb,
PAGP_PARTNER_SENT_PORT_IFINDEX, 4, raw_word);
raw_word = tvb_get_ntohl(tvb, PAGP_PARTNER_GROUP_CAPABILITY);
proto_tree_add_uint(pagp_tree, hf_pagp_partner_group_capability, tvb,
PAGP_PARTNER_GROUP_CAPABILITY, 4, raw_word);
raw_word = tvb_get_ntohl(tvb, PAGP_PARTNER_GROUP_IFINDEX);
proto_tree_add_uint(pagp_tree, hf_pagp_partner_group_ifindex, tvb,
PAGP_PARTNER_GROUP_IFINDEX, 4, raw_word);
raw_half_word = tvb_get_ntohs(tvb, PAGP_PARTNER_COUNT);
proto_tree_add_uint(pagp_tree, hf_pagp_partner_count, tvb,
PAGP_PARTNER_COUNT, 2, raw_half_word);
num_tlvs = tvb_get_ntohs(tvb, PAGP_NUM_TLVS);
proto_tree_add_uint(pagp_tree, hf_pagp_num_tlvs, tvb,
PAGP_NUM_TLVS, 2, num_tlvs);
for ( i = 1; i <= num_tlvs; i++ ) {
tlv = tvb_get_ntohs(tvb, offset);
len = tvb_get_ntohs(tvb, offset + 2);
if ( len == 0 ) {
proto_tree_add_text(pagp_tree, tvb, offset, -1,
"Unknown data - TLV len=0");
return;
}
tlv_item = proto_tree_add_text (pagp_tree, tvb, offset, len,
"TLV Entry #%d", i);
tlv_tree = proto_item_add_subtree (tlv_item, ett_pagp_tlvs);
proto_tree_add_uint_format (tlv_tree, hf_pagp_tlv, tvb,
offset,2,tlv,"Type = %d (%s)", tlv,
val_to_str(tlv,tlv_types, "Unknown")) ;
proto_tree_add_text (tlv_tree, tvb, offset+2, 2,
"Length = %u bytes (includes Type and Length)", len) ;
if ( tvb_reported_length_remaining(tvb, offset) < len ) {
proto_tree_add_text(tlv_tree, tvb, offset, -1,
"TLV length too large");
return;
}
switch (tlv) {
case PAGP_TLV_DEVICE_NAME:
ch = tvb_get_ephemeral_string(tvb, offset+4, len-4);
proto_tree_add_string(tlv_tree, hf_pagp_tlv_device_name,
tvb, offset+4, len-4, ch);
break;
case PAGP_TLV_PORT_NAME:
ch = tvb_get_ephemeral_string(tvb, offset+4, len-4);
proto_tree_add_string(tlv_tree, hf_pagp_tlv_port_name,
tvb, offset+4, len-4, ch);
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
}
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
{ "Entry", "pagp.tlv",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Type/Length/Value", HFILL }},
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
proto_pagp = proto_register_protocol("Port Aggregation Protocol", "PAGP", "pagp");
proto_register_field_array(proto_pagp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pagp(void)
{
dissector_handle_t pagp_handle;
pagp_handle = create_dissector_handle(dissect_pagp, proto_pagp);
dissector_add_uint("llc.cisco_pid", 0x0104, pagp_handle);
}
