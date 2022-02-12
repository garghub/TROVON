static guint get_mqtt_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint64 msg_len;
guint len_offset;
len_offset = dissect_uleb128(tvb, (offset + MQTT_HDR_SIZE_BEFORE_LEN), &msg_len);
return (guint)(GET_MQTT_PDU_LEN(msg_len, len_offset));
}
static int dissect_mqtt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 mqtt_fixed_hdr;
guint8 mqtt_msg_type;
int offset = 0;
mqtt_fixed_hdr = tvb_get_guint8(tvb, offset);
mqtt_msg_type = mqtt_fixed_hdr >> 4;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MQTT");
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", val_to_str_ext(mqtt_msg_type, &mqtt_msgtype_vals_ext, "Unknown (0x%02x)"));
if(tree)
{
proto_item *ti;
proto_item *ti_mqtt;
proto_tree *mqtt_tree;
proto_tree *mqtt_flag_tree;
guint8 mqtt_con_flags;
guint64 msg_len = 0;
gint mqtt_msg_len = 0;
guint16 mqtt_str_len;
guint16 mqtt_len_offset;
ti = proto_tree_add_item(tree, proto_mqtt, tvb, 0, -1, ENC_NA);
mqtt_tree = proto_item_add_subtree(ti, ett_mqtt_hdr);
mqtt_len_offset = dissect_uleb128(tvb, (offset + MQTT_HDR_SIZE_BEFORE_LEN), &msg_len);
mqtt_msg_len = (gint) msg_len;
proto_item_append_text(mqtt_tree, ", %s", val_to_str_ext(mqtt_msg_type, &mqtt_msgtype_vals_ext, "Unknown (0x%02x)"));
ti_mqtt = proto_tree_add_uint_format_value(mqtt_tree, hf_mqtt_hdrflags, tvb, offset, 1, mqtt_fixed_hdr, "0x%02x (%s)",
mqtt_fixed_hdr, val_to_str_ext(mqtt_msg_type, &mqtt_msgtype_vals_ext, "Unknown (0x%02x)"));
mqtt_flag_tree = proto_item_add_subtree(ti_mqtt, ett_mqtt_hdr_flags);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_msg_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_dup_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_qos_level, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_retain, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint64(mqtt_tree, hf_mqtt_msg_len, tvb, offset, mqtt_len_offset, msg_len);
offset += mqtt_len_offset;
switch(mqtt_msg_type)
{
case MQTT_CONNECT:
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_proto_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_proto_name, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
offset += mqtt_str_len;
proto_tree_add_item(mqtt_tree, hf_mqtt_proto_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
mqtt_con_flags = tvb_get_guint8(tvb, offset);
ti_mqtt = proto_tree_add_item(mqtt_tree, hf_mqtt_conflags, tvb, offset, 1, ENC_BIG_ENDIAN);
mqtt_flag_tree = proto_item_add_subtree(ti_mqtt, ett_mqtt_con_flags);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conflag_user, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conflag_passwd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conflag_will_retain, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conflag_will_qos, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conflag_will_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conflag_clean_sess, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conflag_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mqtt_tree, hf_mqtt_keep_alive, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_client_id_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_client_id, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
offset += mqtt_str_len;
if(mqtt_con_flags & MQTT_CONMASK_WILLFLAG)
{
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_will_topic_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_will_topic, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
offset += mqtt_str_len;
}
if(mqtt_con_flags & MQTT_CONMASK_WILLFLAG)
{
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_will_msg_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_will_msg, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
offset += mqtt_str_len;
}
if((mqtt_con_flags & MQTT_CONMASK_USER) && (tvb_reported_length_remaining(tvb, offset) > 0))
{
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_username_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_username, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
offset += mqtt_str_len;
}
if((mqtt_con_flags & MQTT_CONMASK_PASSWD) && (tvb_reported_length_remaining(tvb, offset) > 0))
{
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_passwd_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_passwd, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
}
break;
case MQTT_CONNACK:
ti_mqtt = proto_tree_add_item(mqtt_tree, hf_mqtt_conack_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
mqtt_flag_tree = proto_item_add_subtree(ti_mqtt, ett_mqtt_conack_flags);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conackflag_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqtt_flag_tree, hf_mqtt_conackflag_sp, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mqtt_tree, hf_mqtt_conack_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MQTT_PUBLISH:
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_topic_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
mqtt_msg_len -= 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_topic, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
offset += mqtt_str_len;
mqtt_msg_len -= mqtt_str_len;
if(mqtt_fixed_hdr & MQTT_MASK_QOS)
{
proto_tree_add_item(mqtt_tree, hf_mqtt_msgid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
mqtt_msg_len -= 2;
}
proto_tree_add_item(mqtt_tree, hf_mqtt_pubmsg, tvb, offset, mqtt_msg_len, ENC_UTF_8|ENC_NA);
break;
case MQTT_SUBSCRIBE:
proto_tree_add_item(mqtt_tree, hf_mqtt_msgid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for(mqtt_msg_len -= 2; mqtt_msg_len > 0;)
{
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_topic_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
mqtt_msg_len -= 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_topic, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
offset += mqtt_str_len;
mqtt_msg_len -= mqtt_str_len;
proto_tree_add_item(mqtt_tree, hf_mqtt_sub_qos, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
mqtt_msg_len -= 1;
}
break;
case MQTT_UNSUBSCRIBE:
proto_tree_add_item(mqtt_tree, hf_mqtt_msgid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for(mqtt_msg_len -= 2; mqtt_msg_len > 0;)
{
mqtt_str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(mqtt_tree, hf_mqtt_topic_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
mqtt_msg_len -= 2;
proto_tree_add_item(mqtt_tree, hf_mqtt_topic, tvb, offset, mqtt_str_len, ENC_UTF_8|ENC_NA);
offset += mqtt_str_len;
mqtt_msg_len -= mqtt_str_len;
}
break;
case MQTT_SUBACK:
proto_tree_add_item(mqtt_tree, hf_mqtt_msgid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for(mqtt_msg_len -= 2; mqtt_msg_len > 0; mqtt_msg_len--)
{
proto_tree_add_item(mqtt_tree, hf_mqtt_suback_qos, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case MQTT_PUBACK:
case MQTT_PUBREC:
case MQTT_PUBREL:
case MQTT_PUBCOMP:
case MQTT_UNSUBACK:
proto_tree_add_item(mqtt_tree, hf_mqtt_msgid, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case MQTT_PINGREQ:
case MQTT_PINGRESP:
case MQTT_DISCONNECT:
break;
}
}
return tvb_captured_length(tvb);
}
static int dissect_mqtt_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree,
reassemble_mqtt_over_tcp,
2,
get_mqtt_pdu_len,
dissect_mqtt, data);
return tvb_captured_length(tvb);
}
void proto_register_mqtt(void)
{
static hf_register_info hf_mqtt[] = {
{ &hf_mqtt_msg_len,
{ "Msg Len", "mqtt.len",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_hdrflags,
{ "Header Flags", "mqtt.hdrflags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_msg_type,
{ "Message Type", "mqtt.msgtype",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &mqtt_msgtype_vals_ext, MQTT_MASK_MSG_TYPE,
NULL, HFILL }},
{ &hf_mqtt_dup_flag,
{ "DUP Flag", "mqtt.dupflag",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_MASK_DUP_FLAG,
NULL, HFILL }},
{ &hf_mqtt_qos_level,
{ "QoS Level", "mqtt.qos",
FT_UINT8, BASE_DEC, VALS(mqtt_qos_vals), MQTT_MASK_QOS,
NULL, HFILL }},
{ &hf_mqtt_retain,
{ "Retain", "mqtt.retain",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_MASK_RETAIN,
NULL, HFILL }},
{ &hf_mqtt_conack_flags,
{ "Acknowledge Flags", "mqtt.conack.flags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_conackflag_reserved,
{ "Reserved", "mqtt.conack.flags.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_CONACKMASK_RESERVED,
NULL, HFILL }},
{ &hf_mqtt_conackflag_sp,
{ "Session Present", "mqtt.conack.flags.sp",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_CONACKMASK_SP,
"Session Present (version 3.1.1)", HFILL }},
{ &hf_mqtt_conack_code,
{ "Return Code", "mqtt.conack.val",
FT_UINT8, BASE_DEC, VALS(mqtt_conack_vals), 0,
NULL, HFILL }},
{ &hf_mqtt_msgid,
{ "Message Identifier", "mqtt.msgid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_sub_qos,
{ "Requested QoS", "mqtt.sub.qos",
FT_UINT8, BASE_DEC, VALS(mqtt_qos_vals), 0,
NULL, HFILL }},
{ &hf_mqtt_suback_qos,
{ "Granted QoS", "mqtt.suback.qos",
FT_UINT8, BASE_DEC, VALS(mqtt_subqos_vals), 0,
NULL, HFILL }},
{ &hf_mqtt_topic_len,
{ "Topic Length", "mqtt.topic_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_topic,
{ "Topic", "mqtt.topic",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_will_topic_len,
{ "Will Topic Length", "mqtt.willtopic_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_will_topic,
{ "Will Topic", "mqtt.willtopic",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_will_msg,
{ "Will Message", "mqtt.willmsg",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_will_msg_len,
{ "Will Message Length", "mqtt.willmsg_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_username_len,
{ "User Name Length", "mqtt.username_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_username,
{ "User Name", "mqtt.username",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_passwd_len,
{ "Password Length", "mqtt.passwd_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_passwd,
{ "Password", "mqtt.passwd",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_pubmsg,
{ "Message", "mqtt.msg",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_proto_len,
{ "Protocol Name Length", "mqtt.proto_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_proto_name,
{ "Protocol Name", "mqtt.protoname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_client_id_len,
{ "Client ID Length", "mqtt.clientid_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_client_id,
{ "Client ID", "mqtt.clientid",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_proto_ver,
{ "Version", "mqtt.ver",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_conflags,
{ "Connect Flags", "mqtt.conflags",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_mqtt_conflag_user,
{ "User Name Flag", "mqtt.conflag.uname",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_CONMASK_USER,
NULL, HFILL }},
{ &hf_mqtt_conflag_passwd,
{ "Password Flag", "mqtt.conflag.passwd",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_CONMASK_PASSWD,
NULL, HFILL }},
{ &hf_mqtt_conflag_will_retain,
{ "Will Retain", "mqtt.conflag.retain",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_CONMASK_RETAIN,
NULL, HFILL }},
{ &hf_mqtt_conflag_will_qos,
{ "QoS Level", "mqtt.conflag.qos",
FT_UINT8, BASE_DEC, VALS(mqtt_qos_vals), MQTT_CONMASK_QOS,
NULL, HFILL }},
{ &hf_mqtt_conflag_will_flag,
{ "Will Flag", "mqtt.conflag.willflag",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_CONMASK_WILLFLAG,
NULL, HFILL }},
{ &hf_mqtt_conflag_clean_sess,
{ "Clean Session Flag", "mqtt.conflag.cleansess",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_CONMASK_CLEANSESS,
NULL, HFILL }},
{ &hf_mqtt_conflag_reserved,
{ "(Reserved)", "mqtt.conflag.reserved",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), MQTT_CONMASK_RESERVED,
NULL, HFILL }},
{ &hf_mqtt_keep_alive,
{ "Keep Alive", "mqtt.kalive",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }}
};
static gint* ett_mqtt[] = {
&ett_mqtt_hdr,
&ett_mqtt_msg,
&ett_mqtt_hdr_flags,
&ett_mqtt_con_flags,
&ett_mqtt_conack_flags
};
proto_mqtt = proto_register_protocol("MQ Telemetry Transport Protocol", "MQTT", "mqtt");
mqtt_handle = register_dissector("mqtt", dissect_mqtt_data, proto_mqtt);
proto_register_field_array(proto_mqtt, hf_mqtt, array_length(hf_mqtt));
proto_register_subtree_array(ett_mqtt, array_length(ett_mqtt));
}
void proto_reg_handoff_mqtt(void)
{
dissector_add_uint_with_preference("tcp.port", MQTT_DEFAULT_PORT, mqtt_handle);
ssl_dissector_add(MQTT_SSL_DEFAULT_PORT, mqtt_handle);
}
