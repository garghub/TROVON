static void decode_packetcable_bcid (tvbuff_t *tvb, proto_tree *tree, int offset)
{
guint8 packetcable_buf[64];
proto_tree_add_item(tree, hf_packetcable_bcid_timestamp,
tvb, offset, 4, ENC_BIG_ENDIAN);
tvb_memcpy(tvb, packetcable_buf, offset + 4, 8); packetcable_buf[8] = '\0';
proto_tree_add_text(tree, tvb, offset + 4, 8,
"Element ID: %s", packetcable_buf);
tvb_memcpy(tvb, packetcable_buf, offset + 13, 7); packetcable_buf[7] = '\0';
proto_tree_add_text(tree, tvb, offset + 12, 8,
"Time Zone: DST: %c, Offset: %s", tvb_get_guint8(tvb, offset + 12),
packetcable_buf);
proto_tree_add_item(tree, hf_packetcable_bcid_event_counter,
tvb, offset + 20, 4, ENC_BIG_ENDIAN);
}
static const gchar* dissect_packetcable_em_hdr(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
guint8 packetcable_buf[64];
proto_item *ti;
proto_tree *obj_tree;
proto_tree_add_item(tree, hf_packetcable_em_header_version_id, tvb, 0, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_text(tree, tvb, 2, 24, "BCID");
obj_tree = proto_item_add_subtree(ti, ett_radius_vendor_packetcable_bcid);
decode_packetcable_bcid(tvb, obj_tree, 2);
proto_tree_add_item(tree, hf_packetcable_em_header_event_message_type, tvb, 26, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_em_header_element_type, tvb, 28, 2, ENC_BIG_ENDIAN);
tvb_memcpy(tvb, packetcable_buf, 30, 8); packetcable_buf[8] = '\0';
proto_tree_add_text(tree, tvb, 30, 8, "Element ID: %s", packetcable_buf );
tvb_memcpy(tvb, packetcable_buf, 39, 7); packetcable_buf[7] = '\0';
proto_tree_add_text(tree, tvb, 38, 8, "Time Zone: DST: %c, Offset: %s", tvb_get_guint8(tvb, 38), packetcable_buf);
proto_tree_add_item(tree, hf_packetcable_em_header_sequence_number, tvb, 46, 4, ENC_BIG_ENDIAN);
tvb_memcpy(tvb, packetcable_buf, 50, 18); packetcable_buf[18] = '\0';
proto_tree_add_text(tree, tvb, 50, 18, "Event Time: %s", packetcable_buf);
ti = proto_tree_add_item(tree, hf_packetcable_em_header_status, tvb, 68, 4, ENC_BIG_ENDIAN);
obj_tree = proto_item_add_subtree(ti, ett_radius_vendor_packetcable_status);
proto_tree_add_item(obj_tree, hf_packetcable_em_header_status_error_indicator, tvb, 68, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(obj_tree, hf_packetcable_em_header_status_event_origin, tvb, 68, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(obj_tree, hf_packetcable_em_header_status_event_message_proxied, tvb, 68, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_em_header_priority, tvb, 72, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_em_header_attribute_count, tvb, 73, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_em_header_event_object, tvb, 75, 1, ENC_BIG_ENDIAN);
return "";
}
static const gchar* dissect_packetcable_call_term_cause(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
proto_tree_add_item(tree, hf_packetcable_call_termination_cause_source_document,
tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_call_termination_cause_code,
tvb, 2, 4, ENC_BIG_ENDIAN);
return "";
}
static const gchar* dissect_packetcable_rel_call_billing_correlation(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
decode_packetcable_bcid(tvb, tree, 0);
return "";
}
static const gchar* dissect_packetcable_trunk_group_id(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
proto_tree_add_item(tree, hf_packetcable_trunk_group_id_trunk_type,
tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_trunk_group_id_trunk_number,
tvb, 2, 4, ENC_BIG_ENDIAN);
return "";
}
static const gchar* dissect_packetcable_qos_descriptor(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
guint8 packetcable_buf[64];
guint32 intval;
guint32 packetcable_qos_flags = tvb_get_ntohl(tvb, 0);
proto_item* ti = proto_tree_add_item(tree, hf_packetcable_qos_status, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree* obj_tree = proto_item_add_subtree(ti, ett_radius_vendor_packetcable_qos_status);
guint packetcable_qos_off = 20;
proto_tree_add_item(obj_tree, hf_packetcable_qos_status_indication, tvb, 0, 4, ENC_BIG_ENDIAN);
for (intval = 0; intval < PACKETCABLE_QOS_DESC_BITFIELDS; intval++) {
proto_tree_add_item(obj_tree, hf_packetcable_qos_desc_flags[intval], tvb, 0, 4, ENC_BIG_ENDIAN);
}
tvb_memcpy(tvb, packetcable_buf, 4, 16);
packetcable_buf[16] = '\0';
proto_tree_add_text(tree, tvb, 4, 16, "Service Class Name: %s", packetcable_buf);
for (intval = 0; intval < PACKETCABLE_QOS_DESC_BITFIELDS; intval++) {
if (packetcable_qos_flags & packetcable_qos_desc_mask[intval]) {
proto_tree_add_item(tree, hf_packetcable_qos_desc_fields[intval],
tvb, packetcable_qos_off, 4, ENC_BIG_ENDIAN);
packetcable_qos_off += 4;
}
}
return "";
}
static const gchar* dissect_packetcable_time_adjustment(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
proto_tree_add_item(tree, hf_packetcable_time_adjustment, tvb, 0, 8, ENC_BIG_ENDIAN);
return "";
}
static const gchar* dissect_packetcable_redirected_from_info(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
guint8 packetcable_buf[64];
tvb_memcpy(tvb, packetcable_buf, 0, 20); packetcable_buf[20] = '\0';
proto_tree_add_text(tree, tvb, 0, 20,
"Last-Redirecting-Party: %s", packetcable_buf);
tvb_memcpy(tvb, packetcable_buf, 20, 20); packetcable_buf[20] = '\0';
proto_tree_add_text(tree, tvb, 20, 20,
"Original-Called-Party: %s", packetcable_buf);
proto_tree_add_item(tree, hf_packetcable_redirected_from_info_number_of_redirections,
tvb, 40, 2, ENC_BIG_ENDIAN);
return "";
}
static const gchar* dissect_packetcable_time_electr_surv_ind(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
if (tvb_length(tvb) == 0)
return "None";
proto_tree_add_item(tree, hf_packetcable_electronic_surveillance_indication_df_cdc_address,
tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_electronic_surveillance_indication_df_ccc_address,
tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_electronic_surveillance_indication_cdc_port,
tvb, 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_packetcable_electronic_surveillance_indication_ccc_port,
tvb, 10, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, 12, tvb_length(tvb) - 12, "DF-DF-Key");
return "";
}
static const gchar* dissect_packetcable_surv_df_sec(proto_tree* tree _U_, tvbuff_t* tvb _U_, packet_info *pinfo _U_) {
return "";
}
static const gchar* dissect_packetcable_term_dsply_info(proto_tree* tree, tvbuff_t* tvb, packet_info *pinfo _U_) {
guint8 bitmask = tvb_get_guint8(tvb, 2);
guint intval = 1;
proto_item* ti = proto_tree_add_item(tree, hf_packetcable_terminal_display_info_terminal_display_status_bitmask,
tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree* obj_tree = proto_item_add_subtree(ti, ett_packetcable_term_dsply);
proto_tree_add_boolean(obj_tree, hf_packetcable_terminal_display_info_sbm_general_display,
tvb, 0, 1, bitmask);
proto_tree_add_boolean(obj_tree, hf_packetcable_terminal_display_info_sbm_calling_number,
tvb, 0, 1, bitmask);
proto_tree_add_boolean(obj_tree, hf_packetcable_terminal_display_info_sbm_calling_name,
tvb, 0, 1, bitmask);
proto_tree_add_boolean(obj_tree, hf_packetcable_terminal_display_info_sbm_message_waiting,
tvb, 0, 1, bitmask);
if (bitmask & PACKETCABLE_GENERAL_DISPLAY) {
proto_tree_add_item(obj_tree, hf_packetcable_terminal_display_info_general_display,
tvb, intval, 80, ENC_ASCII|ENC_NA);
intval += 80;
}
if (bitmask & PACKETCABLE_CALLING_NUMBER) {
proto_tree_add_item(obj_tree, hf_packetcable_terminal_display_info_calling_number,
tvb, intval, 40, ENC_ASCII|ENC_NA);
intval += 40;
}
if (bitmask & PACKETCABLE_CALLING_NAME) {
proto_tree_add_item(obj_tree, hf_packetcable_terminal_display_info_calling_name,
tvb, intval, 40, ENC_ASCII|ENC_NA);
intval += 40;
}
if (bitmask & PACKETCABLE_MESSAGE_WAITING) {
proto_tree_add_item(obj_tree, hf_packetcable_terminal_display_info_message_waiting,
tvb, intval, 40, ENC_ASCII|ENC_NA);
}
return "";
}
void proto_register_packetcable(void) {
static hf_register_info hf[] = {
{ &hf_packetcable_em_header_version_id,
{ "Event Message Version ID","packetcable_avps.emh.vid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"PacketCable Event Message header version ID", HFILL }
},
{ &hf_packetcable_bcid_timestamp,
{ "Timestamp","packetcable_avps.bcid.ts",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable Event Message BCID Timestamp", HFILL }
},
{ &hf_packetcable_bcid_event_counter,
{ "Event Counter","packetcable_avps.bcid.ec",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable Event Message BCID Event Counter", HFILL }
},
{ &hf_packetcable_em_header_event_message_type,
{ "Event Message Type","packetcable_avps.emh.emt",
FT_UINT16, BASE_DEC, radius_vendor_packetcable_event_message_vals, 0x0,
"PacketCable Event Message Type", HFILL }
},
{ &hf_packetcable_em_header_element_type,
{ "Element Type","packetcable_avps.emh.et",
FT_UINT16, BASE_DEC, packetcable_em_header_element_type_vals, 0x0,
"PacketCable Event Message Element Type", HFILL }
},
{ &hf_packetcable_em_header_sequence_number,
{ "Sequence Number","packetcable_avps.emh.sn",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable Event Message Sequence Number", HFILL }
},
{ &hf_packetcable_em_header_status,
{ "Status","packetcable_avps.emh.st",
FT_UINT32, BASE_HEX, NULL, 0x0,
"PacketCable Event Message Status", HFILL }
},
{ &hf_packetcable_em_header_status_error_indicator,
{ "Status","packetcable_avps.emh.st.ei",
FT_UINT32, BASE_HEX, packetcable_em_header_status_error_indicator_vals,
PACKETCABLE_EMHS_EI_MASK,
"PacketCable Event Message Status Error Indicator", HFILL }
},
{ &hf_packetcable_em_header_status_event_origin,
{ "Event Origin","packetcable_avps.emh.st.eo",
FT_UINT32, BASE_HEX, packetcable_em_header_status_event_origin_vals,
PACKETCABLE_EMHS_EO_MASK,
"PacketCable Event Message Status Event Origin", HFILL }
},
{ &hf_packetcable_em_header_status_event_message_proxied,
{ "Event Message Proxied","packetcable_avps.emh.st.emp",
FT_UINT32, BASE_HEX, packetcable_em_header_status_event_message_proxied_vals,
PACKETCABLE_EMHS_EMP_MASK,
"PacketCable Event Message Status Event Message Proxied", HFILL }
},
{ &hf_packetcable_em_header_priority,
{ "Priority","packetcable_avps.emh.priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
"PacketCable Event Message Priority", HFILL }
},
{ &hf_packetcable_em_header_attribute_count,
{ "Attribute Count","packetcable_avps.emh.ac",
FT_UINT16, BASE_DEC, NULL, 0x0,
"PacketCable Event Message Attribute Count", HFILL }
},
{ &hf_packetcable_em_header_event_object,
{ "Event Object","packetcable_avps.emh.eo",
FT_UINT8, BASE_DEC, NULL, 0x0,
"PacketCable Event Message Event Object", HFILL }
},
{ &hf_packetcable_call_termination_cause_source_document,
{ "Source Document","packetcable_avps.ctc.sd",
FT_UINT16, BASE_HEX, packetcable_call_termination_cause_vals, 0x0,
"PacketCable Call Termination Cause Source Document", HFILL }
},
{ &hf_packetcable_call_termination_cause_code,
{ "Event Object","packetcable_avps.ctc.cc",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable Call Termination Cause Code", HFILL }
},
{ &hf_packetcable_trunk_group_id_trunk_type,
{ "Trunk Type","packetcable_avps.tgid.tt",
FT_UINT16, BASE_HEX, packetcable_trunk_type_vals, 0x0,
"PacketCable Trunk Group ID Trunk Type", HFILL }
},
{ &hf_packetcable_trunk_group_id_trunk_number,
{ "Event Object","packetcable_avps.tgid.tn",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable Trunk Group ID Trunk Number", HFILL }
},
{ &hf_packetcable_qos_status,
{ "QoS Status","packetcable_avps.qs",
FT_UINT32, BASE_HEX, NULL, 0x0,
"PacketCable QoS Descriptor Attribute QoS Status", HFILL }
},
{ &hf_packetcable_qos_status_indication,
{ "Status Indication","packetcable_avps.qs.si",
FT_UINT32, BASE_DEC, packetcable_state_indication_vals, PACKETCABLE_QOS_STATE_INDICATION_MASK,
"PacketCable QoS Descriptor Attribute QoS State Indication", HFILL }
},
{ &hf_packetcable_qos_desc_flags[0],
{ "Service Flow Scheduling Type","packetcable_avps.qs.flags.sfst",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_SERVICE_FLOW_SCHEDULING_TYPE_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Service Flow Scheduling Type", HFILL }
},
{ &hf_packetcable_qos_desc_flags[1],
{ "Grant Interval","packetcable_avps.qs.flags.gi",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_NOMINAL_GRANT_INTERVAL_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Grant Interval", HFILL }
},
{ &hf_packetcable_qos_desc_flags[2],
{ "Tolerated Grant Jitter","packetcable_avps.qs.flags.tgj",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_TOLERATED_GRANT_JITTER_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Tolerated Grant Jitter", HFILL }
},
{ &hf_packetcable_qos_desc_flags[3],
{ "Grants Per Interval","packetcable_avps.qs.flags.gpi",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_GRANTS_PER_INTERVAL_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Grants Per Interval", HFILL }
},
{ &hf_packetcable_qos_desc_flags[4],
{ "Unsolicited Grant Size","packetcable_avps.qs.flags.ugs",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_UNSOLICITED_GRANT_SIZE_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Unsolicited Grant Size", HFILL }
},
{ &hf_packetcable_qos_desc_flags[5],
{ "Traffic Priority","packetcable_avps.qs.flags.tp",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_TRAFFIC_PRIORITY_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Traffic Priority", HFILL }
},
{ &hf_packetcable_qos_desc_flags[6],
{ "Maximum Sustained Rate","packetcable_avps.qs.flags.msr",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_MAXIMUM_SUSTAINED_RATE_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Maximum Sustained Rate", HFILL }
},
{ &hf_packetcable_qos_desc_flags[7],
{ "Maximum Traffic Burst","packetcable_avps.qs.flags.mtb",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_MAXIMUM_TRAFFIC_BURST_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Maximum Traffic Burst", HFILL }
},
{ &hf_packetcable_qos_desc_flags[8],
{ "Minimum Reserved Traffic Rate","packetcable_avps.qs.flags.mrtr",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_MINIMUM_RESERVED_TRAFFIC_RATE_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Minimum Reserved Traffic Rate", HFILL }
},
{ &hf_packetcable_qos_desc_flags[9],
{ "Minimum Packet Size","packetcable_avps.qs.flags.mps",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_MINIMUM_PACKET_SIZE_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Minimum Packet Size", HFILL }
},
{ &hf_packetcable_qos_desc_flags[10],
{ "Maximum Concatenated Burst","packetcable_avps.qs.flags.mcb",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_MAXIMUM_CONCATENATED_BURST_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Maximum Concatenated Burst", HFILL }
},
{ &hf_packetcable_qos_desc_flags[11],
{ "Status Request/Transmission Policy","packetcable_avps.qs.flags.srtp",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_REQUEST_TRANSMISSION_POLICY_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Status Request/Transmission Policy", HFILL }
},
{ &hf_packetcable_qos_desc_flags[12],
{ "Nominal Polling Interval","packetcable_avps.qs.flags.npi",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_NOMINAL_POLLING_INTERVAL_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Nominal Polling Interval", HFILL }
},
{ &hf_packetcable_qos_desc_flags[13],
{ "Tolerated Poll Jitter","packetcable_avps.qs.flags.tpj",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_TOLERATED_POLL_JITTER_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Tolerated Poll Jitter", HFILL }
},
{ &hf_packetcable_qos_desc_flags[14],
{ "Type of Service Override","packetcable_avps.qs.flags.toso",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_IP_TYPE_OF_SERVICE_OVERRIDE_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Type of Service Override", HFILL }
},
{ &hf_packetcable_qos_desc_flags[15],
{ "Maximum Downstream Latency","packetcable_avps.qs.flags.mdl",
FT_UINT32, BASE_DEC, NULL, PACKETCABLE_MAXIMUM_DOWNSTREAM_LATENCY_MASK,
"PacketCable QoS Descriptor Attribute Bitmask: Maximum Downstream Latency", HFILL }
},
{ &hf_packetcable_qos_desc_fields[0],
{ "Service Flow Scheduling Type","packetcable_avps.qs.sfst",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Service Flow Scheduling Type", HFILL }
},
{ &hf_packetcable_qos_desc_fields[1],
{ "Grant Interval","packetcable_avps.qs.gi",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Grant Interval", HFILL }
},
{ &hf_packetcable_qos_desc_fields[2],
{ "Tolerated Grant Jitter","packetcable_avps.qs.tgj",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Tolerated Grant Jitter", HFILL }
},
{ &hf_packetcable_qos_desc_fields[3],
{ "Grants Per Interval","packetcable_avps.qs.gpi",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Grants Per Interval", HFILL }
},
{ &hf_packetcable_qos_desc_fields[4],
{ "Unsolicited Grant Size","packetcable_avps.qs.ugs",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Unsolicited Grant Size", HFILL }
},
{ &hf_packetcable_qos_desc_fields[5],
{ "Traffic Priority","packetcable_avps.qs.tp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Traffic Priority", HFILL }
},
{ &hf_packetcable_qos_desc_fields[6],
{ "Maximum Sustained Rate","packetcable_avps.qs.msr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Maximum Sustained Rate", HFILL }
},
{ &hf_packetcable_qos_desc_fields[7],
{ "Maximum Traffic Burst","packetcable_avps.qs.mtb",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Maximum Traffic Burst", HFILL }
},
{ &hf_packetcable_qos_desc_fields[8],
{ "Minimum Reserved Traffic Rate","packetcable_avps.qs.mrtr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Minimum Reserved Traffic Rate", HFILL }
},
{ &hf_packetcable_qos_desc_fields[9],
{ "Minimum Packet Size","packetcable_avps.qs.mps",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Minimum Packet Size", HFILL }
},
{ &hf_packetcable_qos_desc_fields[10],
{ "Maximum Concatenated Burst","packetcable_avps.qs.mcb",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Maximum Concatenated Burst", HFILL }
},
{ &hf_packetcable_qos_desc_fields[11],
{ "Status Request/Transmission Policy","packetcable_avps.qs.srtp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Status Request/Transmission Policy", HFILL }
},
{ &hf_packetcable_qos_desc_fields[12],
{ "Nominal Polling Interval","packetcable_avps.qs.npi",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Nominal Polling Interval", HFILL }
},
{ &hf_packetcable_qos_desc_fields[13],
{ "Tolerated Poll Jitter","packetcable_avps.qs.tpj",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Tolerated Poll Jitter", HFILL }
},
{ &hf_packetcable_qos_desc_fields[14],
{ "Type of Service Override","packetcable_avps.qs.toso",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Type of Service Override", HFILL }
},
{ &hf_packetcable_qos_desc_fields[15],
{ "Maximum Downstream Latency","packetcable_avps.qs.mdl",
FT_UINT32, BASE_DEC, NULL, 0x0,
"PacketCable QoS Descriptor Attribute Maximum Downstream Latency", HFILL }
},
{ &hf_packetcable_time_adjustment,
{ "Time Adjustment","packetcable_avps.ti",
FT_UINT64, BASE_DEC, NULL, 0x0,
"PacketCable Time Adjustment", HFILL }
},
{ &hf_packetcable_redirected_from_info_number_of_redirections,
{ "Number-of-Redirections","packetcable_avps.rfi.nr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"PacketCable Redirected-From-Info Number-of-Redirections", HFILL }
},
{ &hf_packetcable_electronic_surveillance_indication_df_cdc_address,
{ "DF_CDC_Address","packetcable_avps.esi.dfcdca",
FT_IPv4, BASE_NONE, NULL, 0x0,
"PacketCable Electronic-Surveillance-Indication DF_CDC_Address", HFILL }
},
{ &hf_packetcable_electronic_surveillance_indication_df_ccc_address,
{ "DF_CDC_Address","packetcable_avps.esi.dfccca",
FT_IPv4, BASE_NONE, NULL, 0x0,
"PacketCable Electronic-Surveillance-Indication DF_CCC_Address", HFILL }
},
{ &hf_packetcable_electronic_surveillance_indication_cdc_port,
{ "CDC-Port","packetcable_avps.esi.cdcp",
FT_UINT16, BASE_DEC, NULL, 0x0,
"PacketCable Electronic-Surveillance-Indication CDC-Port", HFILL }
},
{ &hf_packetcable_electronic_surveillance_indication_ccc_port,
{ "CCC-Port","packetcable_avps.esi.cccp",
FT_UINT16, BASE_DEC, NULL, 0x0,
"PacketCable Electronic-Surveillance-Indication CCC-Port", HFILL }
},
{ &hf_packetcable_terminal_display_info_terminal_display_status_bitmask,
{ "Terminal_Display_Status_Bitmask","packetcable_avps.tdi.sbm",
FT_UINT8, BASE_HEX, NULL, 0xff,
"PacketCable Terminal_Display_Info Terminal_Display_Status_Bitmask", HFILL }
},
{ &hf_packetcable_terminal_display_info_sbm_general_display,
{ "General_Display","packetcable_avps.tdi.sbm.gd",
FT_BOOLEAN, 8, NULL, 0x01,
"PacketCable Terminal_Display_Info Terminal_Display_Status_Bitmask General_Display", HFILL }
},
{ &hf_packetcable_terminal_display_info_sbm_calling_number,
{ "Calling_Number","packetcable_avps.tdi.sbm.cnum",
FT_BOOLEAN, 8, NULL, 0x02,
"PacketCable Terminal_Display_Info Terminal_Display_Status_Bitmask Calling_Number", HFILL }
},
{ &hf_packetcable_terminal_display_info_sbm_calling_name,
{ "Calling_Name","packetcable_avps.tdi.sbm.cname",
FT_BOOLEAN, 8, NULL, 0x04,
"PacketCable Terminal_Display_Info Terminal_Display_Status_Bitmask Calling_Name", HFILL }
},
{ &hf_packetcable_terminal_display_info_sbm_message_waiting,
{ "Message_Waiting","packetcable_avps.tdi.sbm.mw",
FT_BOOLEAN, 8, NULL, 0x08,
"PacketCable Terminal_Display_Info Terminal_Display_Status_Bitmask Message_Waiting", HFILL }
},
{ &hf_packetcable_terminal_display_info_general_display,
{ "General_Display","packetcable_avps.tdi.gd",
FT_STRING, BASE_NONE, NULL, 0,
"PacketCable Terminal_Display_Info General_Display", HFILL }
},
{ &hf_packetcable_terminal_display_info_calling_number,
{ "Calling_Number","packetcable_avps.tdi.cnum",
FT_STRING, BASE_NONE, NULL, 0,
"PacketCable Terminal_Display_Info Calling_Number", HFILL }
},
{ &hf_packetcable_terminal_display_info_calling_name,
{ "Calling_Name","packetcable_avps.tdi.cname",
FT_STRING, BASE_NONE, NULL, 0,
"PacketCable Terminal_Display_Info Calling_Name", HFILL }
},
{ &hf_packetcable_terminal_display_info_message_waiting,
{ "Message_Waiting","packetcable_avps.tdi.mw",
FT_STRING, BASE_NONE, NULL, 0,
"PacketCable Terminal_Display_Info Message_Waiting", HFILL }
}
};
static gint *ett[] = {
&ett_radius_vendor_packetcable_bcid,
&ett_radius_vendor_packetcable_status,
&ett_radius_vendor_packetcable_qos_status,
&ett_packetcable_term_dsply
};
proto_packetcable = proto_register_protocol("PacketCable AVPs", "PACKETCABLE", "packetcable_avps");
proto_register_field_array(proto_packetcable, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_packetcable(void)
{
radius_register_avp_dissector(VENDOR_CABLELABS, 1, dissect_packetcable_em_hdr);
radius_register_avp_dissector(VENDOR_CABLELABS, 11, dissect_packetcable_call_term_cause);
radius_register_avp_dissector(VENDOR_CABLELABS, 13, dissect_packetcable_rel_call_billing_correlation);
radius_register_avp_dissector(VENDOR_CABLELABS, 24, dissect_packetcable_trunk_group_id);
radius_register_avp_dissector(VENDOR_CABLELABS, 32, dissect_packetcable_qos_descriptor);
radius_register_avp_dissector(VENDOR_CABLELABS, 38, dissect_packetcable_time_adjustment);
radius_register_avp_dissector(VENDOR_CABLELABS, 43, dissect_packetcable_redirected_from_info);
radius_register_avp_dissector(VENDOR_CABLELABS, 44, dissect_packetcable_time_electr_surv_ind);
radius_register_avp_dissector(VENDOR_CABLELABS, 47, dissect_packetcable_surv_df_sec);
radius_register_avp_dissector(VENDOR_CABLELABS, 54, dissect_packetcable_term_dsply_info);
}
