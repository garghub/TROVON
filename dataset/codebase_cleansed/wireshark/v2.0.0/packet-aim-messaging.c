static int
dissect_aim_tlv_value_rendezvous(proto_item *ti, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo)
{
int offset = 0;
proto_tree *entry = proto_item_add_subtree(ti, ett_aim_rendezvous_data);
proto_tree_add_item(entry, hf_aim_rendezvous_msg_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(entry, hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA);
offset += 8;
offset = dissect_aim_capability(entry, tvb, offset);
return dissect_aim_tlv_sequence(tvb, pinfo, offset, entry,
aim_rendezvous_tlvs);
}
static int
dissect_aim_msg_outgoing(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
const aim_tlv *aim_ch_tlvs = NULL;
guint16 channel_id;
guint8 *buddyname;
int buddyname_length;
proto_tree_add_item(msg_tree, hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA);
offset += 8;
channel_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(msg_tree, hf_aim_message_channel_id, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
buddyname_length = aim_get_buddyname(&buddyname, tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " to: %s",
format_text(buddyname, buddyname_length));
offset = dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
switch(channel_id) {
case ICBM_CHANNEL_IM: aim_ch_tlvs = aim_messaging_incoming_ch1_tlvs; break;
case ICBM_CHANNEL_RENDEZVOUS: aim_ch_tlvs = aim_messaging_incoming_ch2_tlvs; break;
default: return offset;
}
return dissect_aim_tlv_sequence(tvb, pinfo, offset, msg_tree, aim_ch_tlvs);
}
static int
dissect_aim_msg_incoming(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
const aim_tlv *aim_ch_tlvs;
guint16 channel_id;
proto_tree_add_item(msg_tree, hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(msg_tree, hf_aim_message_channel_id, tvb, offset, 2,
ENC_BIG_ENDIAN);
channel_id = tvb_get_ntohs(tvb, offset);
offset += 2;
offset = dissect_aim_userinfo(tvb, pinfo, offset, msg_tree);
switch(channel_id) {
case ICBM_CHANNEL_IM: aim_ch_tlvs = aim_messaging_incoming_ch1_tlvs; break;
case ICBM_CHANNEL_RENDEZVOUS: aim_ch_tlvs = aim_messaging_incoming_ch2_tlvs; break;
default: return offset;
}
return dissect_aim_tlv_sequence(tvb, pinfo, offset, msg_tree, aim_ch_tlvs);
}
static int
dissect_aim_msg_params(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree, hf_aim_icbm_channel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_msg_flags, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(msg_tree, hf_aim_icbm_max_snac_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_max_sender_warnlevel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_max_receiver_warnlevel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_min_msg_interval, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
return offset;
}
static int
dissect_aim_msg_evil_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree, hf_aim_icbm_evil, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
return dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
}
static int
dissect_aim_msg_evil_repl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree, hf_aim_evil_warn_level, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_evil_new_warn_level, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
return offset;
}
static int
dissect_aim_msg_minityping(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree,hf_aim_icbm_notification_cookie, tvb, offset, 8, ENC_NA); offset+=8;
proto_tree_add_item(msg_tree,hf_aim_icbm_notification_channel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
offset = dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
proto_tree_add_item(msg_tree,hf_aim_icbm_notification_type, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
return offset;
}
static const
aim_client_plugin *aim_find_plugin ( e_guid_t uuid)
{
int i;
for(i = 0; known_client_plugins[i].name; i++)
{
const aim_client_plugin *plugin = &(known_client_plugins[i]);
if(memcmp(&(plugin->uuid), &uuid, sizeof(e_guid_t)) == 0)
return plugin;
}
return NULL;
}
static int
dissect_aim_plugin(proto_tree *entry, tvbuff_t *tvb, int offset, e_guid_t* out_plugin_uuid)
{
const aim_client_plugin *plugin = NULL;
e_guid_t uuid;
proto_item* ti;
uuid.data1 = tvb_get_ntohl(tvb, offset);
uuid.data2 = tvb_get_ntohs(tvb, offset+4);
uuid.data3 = tvb_get_ntohs(tvb, offset+6);
tvb_memcpy(tvb, uuid.data4, offset+8, 8);
if (out_plugin_uuid)
*out_plugin_uuid = uuid;
plugin = aim_find_plugin(uuid);
ti = proto_tree_add_item(entry, hf_aim_messaging_plugin, tvb, offset, 16, ENC_NA);
proto_item_append_text(ti, " (%s)", plugin ? plugin->name:"Unknown");
return offset+16;
}
static int
dissect_aim_rendezvous_extended_message(tvbuff_t *tvb, proto_tree *msg_tree)
{
int offset = 0;
guint32 text_length;
static const int * flags[] = {
&hf_aim_rendezvous_extended_data_message_flags_normal,
&hf_aim_rendezvous_extended_data_message_flags_auto,
&hf_aim_rendezvous_extended_data_message_flags_multi,
NULL
};
proto_tree_add_item(msg_tree, hf_aim_rendezvous_extended_data_message_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset+=1;
proto_tree_add_bitmask(msg_tree, tvb, offset, hf_aim_rendezvous_extended_data_message_flags,
ett_aim_extended_data_message_flags, flags, ENC_NA);
offset+=1;
proto_tree_add_item(msg_tree, hf_aim_rendezvous_extended_data_message_status_code, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_rendezvous_extended_data_message_priority_code, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
text_length = tvb_get_letohs(tvb, offset);
proto_tree_add_item_ret_uint(msg_tree, hf_aim_rendezvous_extended_data_message_text_length, tvb, offset, 2, ENC_BIG_ENDIAN, &text_length); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_rendezvous_extended_data_message_text, tvb, offset, text_length, ENC_ASCII|ENC_NA);
offset = tvb_reported_length(tvb);
return offset;
}
static int
is_uuid_null(e_guid_t uuid)
{
return (uuid.data1 == 0) &&
(uuid.data2 == 0) &&
(uuid.data3 == 0) &&
(uuid.data4[0] == 0) &&
(uuid.data4[1] == 0) &&
(uuid.data4[2] == 0) &&
(uuid.data4[3] == 0) &&
(uuid.data4[4] == 0) &&
(uuid.data4[5] == 0) &&
(uuid.data4[6] == 0) &&
(uuid.data4[7] == 0);
}
static int
dissect_aim_tlv_value_extended_data(proto_tree *entry, guint16 valueid _U_, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int offset = 0;
guint16 length;
int start_offset;
e_guid_t plugin_uuid;
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(entry, hf_aim_icbm_client_err_length, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset+=2;
start_offset = offset;
proto_tree_add_item(entry, hf_aim_icbm_client_err_protocol_version, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
offset = dissect_aim_plugin(entry, tvb, offset, &plugin_uuid);
proto_tree_add_item(entry, hf_aim_messaging_unknown, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(entry, hf_aim_icbm_client_err_client_caps_flags, tvb, offset, 4, ENC_BIG_ENDIAN); offset+=4;
proto_tree_add_item(entry, hf_aim_messaging_unknown, tvb, offset, 1, ENC_NA); offset += 1;
proto_tree_add_item(entry, hf_aim_icbm_client_err_downcounter, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset = start_offset + length;
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(entry, hf_aim_icbm_client_err_length, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset+=2;
start_offset = offset;
proto_tree_add_item(entry, hf_aim_icbm_client_err_downcounter, tvb, offset, 2, ENC_LITTLE_ENDIAN); offset += 2;
proto_tree_add_item(entry, hf_aim_messaging_unknown_data, tvb, offset, length-2, ENC_NA);
offset = start_offset + length;
if (is_uuid_null(plugin_uuid))
{
tvbuff_t *subtvb = tvb_new_subset_remaining(tvb, offset);
dissect_aim_rendezvous_extended_message(subtvb, entry);
}
else
{
proto_tree_add_item(entry, hf_aim_messaging_plugin_specific_data, tvb, offset, -1, ENC_NA);
}
offset = tvb_reported_length(tvb);
return offset;
}
static int
dissect_aim_msg_ack(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
proto_tree_add_item(msg_tree,hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA); offset+=8;
proto_tree_add_item(msg_tree, hf_aim_message_channel_id, tvb, offset, 2,
ENC_BIG_ENDIAN); offset += 2;
offset = dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
return offset;
}
static int
dissect_aim_msg_client_err(tvbuff_t *tvb, packet_info *pinfo, proto_tree *msg_tree)
{
int offset = 0;
guint16 channel, reason;
proto_tree_add_item(msg_tree,hf_aim_icbm_cookie, tvb, offset, 8, ENC_NA); offset+=8;
channel = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(msg_tree,hf_aim_icbm_channel, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
offset = dissect_aim_buddyname(tvb, pinfo, offset, msg_tree);
reason = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(msg_tree, hf_aim_icbm_client_err_reason, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
if (reason == CLIENT_ERR__REASON_CHANNEL_SPECIFIC && tvb_reported_length_remaining(tvb, offset) > 0)
{
switch (channel)
{
case ICBM_CHANNEL_RENDEZVOUS:
proto_tree_add_item(msg_tree, hf_aim_icbm_rendezvous_nak_length, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
proto_tree_add_item(msg_tree, hf_aim_icbm_rendezvous_nak, tvb, offset, 2, ENC_BIG_ENDIAN); offset+=2;
break;
default:
{
tvbuff_t *subtvb = tvb_new_subset_remaining(tvb, offset);
proto_tree *extended_tree = proto_tree_add_subtree(msg_tree, tvb, offset, -1, ett_aim_extended_data, NULL, "Extended Data");
dissect_aim_tlv_value_extended_data(extended_tree, 0, subtvb, pinfo);
break;
}
}
}
return offset;
}
void
proto_register_aim_messaging(void)
{
static hf_register_info hf[] = {
{ &hf_aim_icbm_channel,
{ "Channel", "aim_messaging.icbm.channel",
FT_UINT16, BASE_HEX, VALS(icbm_channel_types), 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_msg_flags,
{ "Message Flags", "aim_messaging.icbm.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_max_snac_size,
{ "Max SNAC Size", "aim_messaging.icbm.max_snac",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_max_sender_warnlevel,
{ "Max sender warn level", "aim_messaging.icbm.max_sender_warn-level",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_max_receiver_warnlevel,
{ "max receiver warn level", "aim_messaging.icbm.max_receiver_warnlevel",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_min_msg_interval,
{ "Minimum message interval (milliseconds)", "aim_messaging.icbm.min_msg_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_cookie,
{ "ICBM Cookie", "aim_messaging.icbmcookie",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_message_channel_id,
{ "Message Channel ID", "aim_messaging.channelid",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_evil,
{ "Send Evil Bit As", "aim_messaging.evilreq.origin",
FT_UINT16, BASE_DEC, VALS(evil_origins), 0x0,
NULL, HFILL }
},
{ &hf_aim_evil_warn_level,
{ "Old warning level", "aim_messaging.evil.warn_level",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_evil_new_warn_level,
{ "New warning level", "aim_messaging.evil.new_warn_level",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_notification_cookie,
{ "Notification Cookie", "aim_messaging.notification.cookie",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_notification_channel,
{ "Notification Channel", "aim_messaging.notification.channel",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_notification_type,
{ "Notification Type", "aim_messaging.notification.type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_rendezvous_nak,
{ "Rendezvous NAK reason", "aim_messaging.rendezvous_nak",
FT_UINT16, BASE_HEX, VALS(rendezvous_nak_reason_types), 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_rendezvous_nak_length,
{ "Rendezvous NAK reason length", "aim_messaging.rendezvous_nak_length",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_rendezvous_msg_type,
{ "Message Type", "aim_messaging.rendezvous.msg_type",
FT_UINT16, BASE_HEX, VALS(rendezvous_msg_types), 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_client_err_reason,
{ "Reason", "aim_messaging.clienterr.reason",
FT_UINT16, BASE_DEC, VALS(client_err_reason_types), 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_client_err_protocol_version,
{ "Version", "aim_messaging.clienterr.protocol_version",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_icbm_client_err_client_caps_flags,
{ "Client Capabilities Flags", "aim_messaging.clienterr.client_caps_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_type,
{ "Message Type", "aim_messaging.icbm.extended_data.message.type",
FT_UINT8, BASE_HEX, VALS(extended_data_message_types), 0x0,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_flags,
{ "Message Flags", "aim_messaging.icbm.extended_data.message.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_flags_normal,
{ "Normal Message", "aim_messaging.icbm.extended_data.message.flags.normal",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EXTENDED_DATA_MFLAG_NORMAL,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_flags_auto,
{ "Auto Message", "aim_messaging.icbm.extended_data.message.flags.auto",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EXTENDED_DATA_MFLAG_AUTO,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_flags_multi,
{ "Multiple Recipients Message", "aim_messaging.icbm.rendezvous.extended_data.message.flags.multi",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), EXTENDED_DATA_MFLAG_MULTI,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_status_code,
{ "Status Code", "aim_messaging.icbm.extended_data.message.status_code",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_priority_code,
{ "Priority Code", "aim_messaging.icbm.extended_data.message.priority_code",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_text_length,
{ "Text Length", "aim_messaging.icbm.extended_data.message.text_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_rendezvous_extended_data_message_text,
{ "Text", "aim_messaging.icbm.extended_data.message.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_aim_messaging_plugin, { "Plugin", "aim_messaging.plugin", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_icbm_client_err_length, { "Length", "aim_messaging.clienterr.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_messaging_unknown, { "Unknown", "aim_messaging.unknown", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_icbm_client_err_downcounter, { "Downcounter?", "aim_messaging.clienterr.downcounter", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_messaging_unknown_data, { "Unknown", "aim_messaging.unknown_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_aim_messaging_plugin_specific_data, { "Plugin-specific data", "aim_messaging.plugin_specific_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_aim_messaging,
&ett_aim_rendezvous_data,
&ett_aim_extended_data,
&ett_aim_extended_data_message_flags
};
proto_aim_messaging = proto_register_protocol("AIM Messaging", "AIM Messaging", "aim_messaging");
proto_register_field_array(proto_aim_messaging, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_messaging(void)
{
aim_init_family(proto_aim_messaging, ett_aim_messaging, FAMILY_MESSAGING, aim_fnac_family_messaging);
}
