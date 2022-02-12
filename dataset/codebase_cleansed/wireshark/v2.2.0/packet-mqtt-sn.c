static void dissect_mqttsn_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
int long_hdr_len = 0;
guint8 mqttsn_msg_type_id;
guint16 mqttsn_msg_len;
mqttsn_msg_len = tvb_get_guint8(tvb, offset);
if (mqttsn_msg_len == 1)
{
long_hdr_len = 1;
mqttsn_msg_len = tvb_get_ntohs(tvb, offset + 1);
}
mqttsn_msg_len += offset;
mqttsn_msg_type_id = tvb_get_guint8(tvb, offset + (long_hdr_len ? 3 : 1));
if (tree)
{
proto_item *ti = NULL;
proto_item *ti_mqttsn = NULL;
proto_tree *mqttsn_tree = NULL;
proto_tree *mqttsn_msg_tree = NULL;
proto_tree *mqttsn_flag_tree = NULL;
if (offset == 0)
{
ti = proto_tree_add_item(tree, proto_mqttsn, tvb, 0, -1, ENC_NA);
mqttsn_tree = proto_item_add_subtree(ti, ett_mqttsn_hdr);
}
else
{
mqttsn_tree = tree;
}
ti_mqttsn = proto_tree_add_item(mqttsn_tree, hf_mqttsn_msg, tvb, offset + (long_hdr_len ? 3 : 1), -1, ENC_NA);
mqttsn_msg_tree = proto_item_add_subtree(ti_mqttsn, ett_mqttsn_msg);
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_type, tvb, offset + (long_hdr_len ? 3 : 1), 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_len, tvb, offset - 1 + (long_hdr_len ? 1 : 0), (long_hdr_len ? 2 : 1), ENC_BIG_ENDIAN);
offset += (long_hdr_len ? 3 : 1);
switch (mqttsn_msg_type_id)
{
case MQTTSN_CONNECT:
mqttsn_flag_tree = proto_item_add_subtree(ti_mqttsn, ett_mqttsn_flags);
proto_tree_add_item(mqttsn_flag_tree, hf_mqttsn_will, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqttsn_flag_tree, hf_mqttsn_clean_session, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqttsn_flag_tree, hf_mqttsn_topic_id_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case MQTTSN_PUBLISH:
mqttsn_flag_tree = proto_item_add_subtree(ti_mqttsn, ett_mqttsn_flags);
proto_tree_add_item(mqttsn_flag_tree, hf_mqttsn_dup, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqttsn_flag_tree, hf_mqttsn_qos, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqttsn_flag_tree, hf_mqttsn_retain, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mqttsn_flag_tree, hf_mqttsn_topic_id_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case MQTTSN_WILLTOPIC:
case MQTTSN_SUBSCRIBE:
case MQTTSN_SUBACK:
case MQTTSN_UNSUBSCRIBE:
case MQTTSN_WILLTOPICUPD:
mqttsn_flag_tree = proto_item_add_subtree(ti_mqttsn, ett_mqttsn_flags);
proto_tree_add_item(mqttsn_flag_tree, hf_mqttsn_topic_id_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
default:
break;
}
switch (mqttsn_msg_type_id)
{
case MQTTSN_ADVERTISE:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_gw_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_adv_interv, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case MQTTSN_SEARCHGW:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_radius, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MQTTSN_GWINFO:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_gw_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (offset < mqttsn_msg_len)
{
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_gw_addr, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
}
break;
case MQTTSN_CONNECT:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_protocol_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_keep_alive, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_client_id, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
break;
case MQTTSN_CONNACK:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_return_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MQTTSN_WILLTOPICREQ:
case MQTTSN_WILLMSGREQ:
break;
case MQTTSN_WILLTOPIC:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_will_topic, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
break;
case MQTTSN_WILLMSG:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_will_msg, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
break;
case MQTTSN_REGISTER:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_topic_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_topic, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
break;
case MQTTSN_REGACK:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_topic_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_return_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MQTTSN_PUBLISH:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_topic_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_pub_msg, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
break;
case MQTTSN_PUBACK:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_topic_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_return_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MQTTSN_PUBCOMP:
case MQTTSN_PUBREC:
case MQTTSN_PUBREL:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case MQTTSN_SUBSCRIBE:
case MQTTSN_UNSUBSCRIBE:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_topic_name_or_id, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
break;
case MQTTSN_SUBACK:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_topic_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_return_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MQTTSN_UNSUBACK:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_msg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case MQTTSN_PINGREQ:
if (offset < mqttsn_msg_len)
{
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_client_id, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
}
break;
case MQTTSN_PINGRESP:
break;
case MQTTSN_DISCONNECT:
if (offset < mqttsn_msg_len)
{
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_sleep_timer, tvb, offset, 2, ENC_BIG_ENDIAN);
}
break;
case MQTTSN_WILLTOPICUPD:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_will_topic, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
break;
case MQTTSN_WILLMSGUPD:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_will_msg, tvb, offset, (mqttsn_msg_len - offset), ENC_ASCII|ENC_NA);
break;
case MQTTSN_WILLTOPICRESP:
case MQTTSN_WILLMSGRESP:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_return_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case MQTTSN_ENCAPSULATED_MSG:
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_control_info, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(mqttsn_msg_tree, hf_mqttsn_wireless_node_id, tvb, offset, (mqttsn_msg_len - offset), ENC_BIG_ENDIAN);
offset += (mqttsn_msg_len - offset);
if (tvb_reported_length_remaining(tvb, offset) > 0)
{
dissect_mqttsn_packet(tvb, pinfo, mqttsn_msg_tree, offset);
}
default:
break;
}
}
}
static int dissect_mqttsn(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
guint8 mqttsn_msg_type_id;
if (tvb_get_guint8(tvb, 0) != 1)
{
mqttsn_msg_type_id = tvb_get_guint8(tvb, 1);
}
else
{
mqttsn_msg_type_id = tvb_get_guint8(tvb, 3);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MQTT-SN");
col_clear(pinfo->cinfo, COL_INFO);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext(mqttsn_msg_type_id, &mqttsn_msgtype_vals_ext, "Unknown (0x%02x)"));
dissect_mqttsn_packet(tvb, pinfo, tree, offset);
return tvb_captured_length(tvb);
}
void proto_register_mqttsn(void)
{
static hf_register_info hf_mqttsn[] = {
{ &hf_mqttsn_msg,
{ "Message", "mqttsn.msg",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_mqttsn_msg_len,
{ "Message Length", "mqttsn.msg.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_msg_type,
{ "Message Type", "mqttsn.msg.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &mqttsn_msgtype_vals_ext, 0,
NULL, HFILL }
},
{ &hf_mqttsn_dup,
{ "DUP", "mqttsn.dup",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), MQTTSN_MASK_DUP_FLAG,
NULL, HFILL }
},
{ &hf_mqttsn_will,
{ "Will", "mqttsn.will",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), MQTTSN_MASK_WILL,
NULL, HFILL }
},
{ &hf_mqttsn_clean_session,
{ "Clean Session", "mqttsn.clean.session",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), MQTTSN_MASK_CLEAN,
NULL, HFILL }
},
{ &hf_mqttsn_topic_id_type,
{ "Topic ID Type", "mqttsn.topic.id.type",
FT_UINT8, BASE_HEX, VALS(mqttsn_typeid_vals), MQTTSN_MASK_TOPIC_ID_TYPE,
NULL, HFILL }
},
{ &hf_mqttsn_qos,
{ "QoS", "mqttsn.qos",
FT_UINT8, BASE_HEX, VALS(mqttsn_qos_vals), MQTTSN_MASK_QOS,
NULL, HFILL }
},
{ &hf_mqttsn_retain,
{ "Retain", "mqttsn.retain",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), MQTTSN_MASK_RETAIN,
NULL, HFILL }
},
{ &hf_mqttsn_return_code,
{ "Return Code", "mqttsn.return.code",
FT_UINT8, BASE_HEX, VALS(mqttsn_return_vals), 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_gw_id,
{ "Gateway ID", "mqttsn.gw.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_gw_addr,
{ "Gateway Address", "mqttsn.gw.addr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_adv_interv,
{ "Advertise Interval", "mqttsn.adv.interv",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_radius,
{ "Broadcast Radius", "mqttsn.radius",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_protocol_id,
{ "Protocol ID", "mqttsn.protocol.id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_topic_id,
{ "Topic ID", "mqttsn.topic.id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_msg_id,
{ "Message ID", "mqttsn.msg.id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_topic,
{ "Topic Name", "mqttsn.topic",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_topic_name_or_id,
{ "Topic Name/ID", "mqttsn.topic.name.or.id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_sleep_timer,
{ "Sleep Timer", "mqttsn.sleep.timer",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_will_topic,
{ "Will Topic", "mqttsn.will.topic",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_will_msg,
{ "Will Message", "mqttsn.will.msg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_pub_msg,
{ "Message", "mqttsn.pub.msg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_client_id,
{ "Client ID", "mqttsn.client.id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_keep_alive,
{ "Keep Alive", "mqttsn.keep.alive",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_mqttsn_control_info,
{ "Control", "mqttsn.control.info",
FT_UINT8, BASE_HEX, NULL, MQTTSN_MASK_CONTROL,
NULL, HFILL }
},
{ &hf_mqttsn_wireless_node_id,
{ "Wireless Node ID", "mqttsn.wireless.node.id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
}
};
static gint* ett_mqttsn[] = {
&ett_mqttsn_hdr,
&ett_mqttsn_msg,
&ett_mqttsn_flags
};
proto_mqttsn = proto_register_protocol("MQ Telemetry Transport Protocol for Sensor Networks", "MQTT-SN", "mqttsn");
mqttsn_handle = create_dissector_handle(dissect_mqttsn, proto_mqttsn);
proto_register_field_array(proto_mqttsn, hf_mqttsn, array_length(hf_mqttsn));
proto_register_subtree_array(ett_mqttsn, array_length(ett_mqttsn));
}
void proto_reg_handoff_mqttsn(void)
{
dissector_add_for_decode_as("udp.port", mqttsn_handle);
}
