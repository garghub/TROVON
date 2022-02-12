static void
dissect_msrp_common1(proto_tree *msg_tree, tvbuff_t *tvb, int msg_offset)
{
proto_tree_add_item(msg_tree, hf_msrp_attribute_type, tvb,
MSRP_ATTRIBUTE_TYPE_OFFSET + msg_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msg_tree, hf_msrp_attribute_length, tvb,
MSRP_ATTRIBUTE_LENGTH_OFFSET + msg_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msg_tree, hf_msrp_attribute_list_length, tvb,
MSRP_ATTRIBUTE_LIST_LENGTH_OFFSET + msg_offset, 2, ENC_BIG_ENDIAN);
}
static void
dissect_msrp_common2(proto_tree *vect_attr_tree, tvbuff_t *tvb, int msg_offset)
{
proto_tree_add_bitmask(vect_attr_tree, tvb, MSRP_VECTOR_HEADER_OFFSET + msg_offset,
hf_msrp_vector_header, ett_vector_header, vector_header_fields, ENC_BIG_ENDIAN);
}
static void
dissect_msrp_talker_common(proto_tree *first_value_tree, tvbuff_t *tvb, int msg_offset)
{
proto_tree_add_item(first_value_tree, hf_msrp_stream_da, tvb,
MSRP_STREAM_DA_OFFSET + msg_offset, 6, ENC_NA);
proto_tree_add_item(first_value_tree, hf_msrp_vlan_id, tvb,
MSRP_VLAN_ID_OFFSET + msg_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(first_value_tree, hf_msrp_tspec_max_frame_size, tvb,
MSRP_TSPEC_MAX_FRAME_SIZE_OFFSET + msg_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(first_value_tree, hf_msrp_tspec_max_interval_frames, tvb,
MSRP_TSPEC_MAX_INTERVAL_FRAMES_OFFSET + msg_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(first_value_tree, tvb, MSRP_PRIORITY_AND_RANK_OFFSET + msg_offset,
hf_msrp_priority_and_rank, ett_priority_and_rank, priority_and_rank_fields, ENC_BIG_ENDIAN);
proto_tree_add_item(first_value_tree, hf_msrp_accumulated_latency, tvb,
MSRP_ACCUMULATED_LATENCY_OFFSET + msg_offset, 4, ENC_BIG_ENDIAN);
}
static void
dissect_msrp_talker_failed(proto_tree *first_value_tree, tvbuff_t *tvb, int msg_offset)
{
proto_tree_add_item(first_value_tree, hf_msrp_failure_bridge_id, tvb,
MSRP_FAILURE_BRIDGE_ID_OFFSET + msg_offset, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(first_value_tree, hf_msrp_failure_code, tvb,
MSRP_FAILURE_CODE_OFFSET + msg_offset, 1, ENC_BIG_ENDIAN);
}
static guint
dissect_msrp_three_packed_event(proto_tree *vect_attr_tree, tvbuff_t *tvb, guint offset, guint16 number_of_values)
{
guint counter;
for ( counter = 0; counter < number_of_values; ) {
guint8 value;
guint8 three_packed_event[3];
value = tvb_get_guint8(tvb, offset);
three_packed_event[0] = value / 36;
value -= 36 * three_packed_event[0];
three_packed_event[1] = value / 6;
value -= 6 * three_packed_event[1];
three_packed_event[2] = value;
proto_tree_add_uint(vect_attr_tree, hf_msrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[0]);
counter++;
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_msrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[1]);
counter++;
}
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_msrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[2]);
counter++;
}
offset++;
}
return( offset );
}
static guint
dissect_msrp_four_packed_event(proto_tree *vect_attr_tree, tvbuff_t *tvb, guint offset, guint16 number_of_values)
{
guint counter;
for ( counter = 0; counter < number_of_values; ) {
guint8 value;
guint8 four_packed_event[4];
value = tvb_get_guint8(tvb, offset);
four_packed_event[0] = (value & 0xc0) >> 6;
four_packed_event[1] = (value & 0x30) >> 4;
four_packed_event[2] = (value & 0x0c) >> 2;
four_packed_event[3] = (value & 0x03);
proto_tree_add_uint(vect_attr_tree, hf_msrp_four_packed_event, tvb, offset, sizeof(guint8),
four_packed_event[0]);
counter++;
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_msrp_four_packed_event, tvb, offset, sizeof(guint8),
four_packed_event[1]);
counter++;
}
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_msrp_four_packed_event, tvb, offset, sizeof(guint8),
four_packed_event[2]);
counter++;
}
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_msrp_four_packed_event, tvb, offset, sizeof(guint8),
four_packed_event[3]);
counter++;
}
offset++;
}
return( offset );
}
static void
dissect_msrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *msg_ti, *attr_list_ti, *vect_attr_ti, *first_value_ti;
proto_tree *msrp_tree, *msg_tree, *attr_list_tree, *vect_attr_tree, *first_value_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MRP-MSRP");
col_set_str(pinfo->cinfo, COL_INFO, "Multiple Stream Reservation Protocol");
if (tree) {
guint8 attribute_type;
guint8 attribute_length;
guint16 number_of_values;
guint16 attribute_list_length;
guint offset = 0;
int vect_attr_len;
int msg_length;
int msg_offset;
int vect_offset;
ti = proto_tree_add_item(tree, proto_msrp, tvb, 0, -1, ENC_NA);
msrp_tree = proto_item_add_subtree(ti, ett_msrp);
proto_tree_add_item(msrp_tree, hf_msrp_proto_id, tvb, MSRP_PROTOCOL_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
msg_offset = 0;
while (tvb_get_ntohs(tvb, MSRP_ATTRIBUTE_TYPE_OFFSET + msg_offset) != MSRP_END_MARK) {
attribute_type = tvb_get_guint8(tvb, MSRP_ATTRIBUTE_TYPE_OFFSET + msg_offset);
attribute_length = tvb_get_guint8(tvb, MSRP_ATTRIBUTE_LENGTH_OFFSET + msg_offset);
attribute_list_length = tvb_get_ntohs(tvb, MSRP_ATTRIBUTE_LIST_LENGTH_OFFSET + msg_offset);
msg_length = 1 + 1 + 2 + attribute_list_length;
msg_ti = proto_tree_add_item(msrp_tree, hf_msrp_message, tvb,
MSRP_MESSAGE_GROUP_OFFSET + msg_offset,
msg_length, ENC_NA);
msg_tree = proto_item_add_subtree(msg_ti, ett_msg);
proto_item_append_text(msg_tree, ": %s (%d)", val_to_str(attribute_type,
attribute_type_vals, "<Unknown>"), attribute_type);
dissect_msrp_common1(msg_tree, tvb, msg_offset);
attr_list_ti = proto_tree_add_item(msg_tree, hf_msrp_attribute_list, tvb,
MSRP_ATTRIBUTE_LIST_GROUP_OFFSET + msg_offset,
attribute_list_length, ENC_NA);
attr_list_tree = proto_item_add_subtree(attr_list_ti, ett_attr_list);
vect_offset = 0;
while (tvb_get_ntohs(tvb, MSRP_VECTOR_HEADER_OFFSET + msg_offset + vect_offset) != MSRP_END_MARK) {
number_of_values = tvb_get_ntohs(tvb, MSRP_NUMBER_OF_VALUES_OFFSET + msg_offset + vect_offset)
& MSRP_NUMBER_OF_VALUES_MASK;
vect_attr_len = 2 + attribute_length + (number_of_values + 2)/3;
if (attribute_type == MSRP_ATTRIBUTE_TYPE_LISTENER)
vect_attr_len += (number_of_values + 3)/4;
vect_attr_ti = proto_tree_add_item(attr_list_tree, hf_msrp_vector_attribute, tvb,
MSRP_VECTOR_ATTRIBUTE_GROUP_OFFSET + msg_offset + vect_offset,
vect_attr_len, ENC_NA);
vect_attr_tree = proto_item_add_subtree(vect_attr_ti, ett_vect_attr);
dissect_msrp_common2(vect_attr_tree, tvb, msg_offset + vect_offset);
if(attribute_type == MSRP_ATTRIBUTE_TYPE_DOMAIN) {
first_value_ti = proto_tree_add_item(vect_attr_tree, hf_msrp_first_value, tvb,
MSRP_FIRST_VALUE_GROUP_OFFSET + msg_offset + vect_offset,
attribute_length, ENC_NA);
first_value_tree = proto_item_add_subtree(first_value_ti, ett_first_value);
proto_tree_add_item(first_value_tree, hf_msrp_sr_class_id, tvb,
MSRP_FIRST_VALUE_GROUP_OFFSET + msg_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(first_value_tree, hf_msrp_sr_class_priority, tvb,
MSRP_FIRST_VALUE_GROUP_OFFSET + msg_offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(first_value_tree, hf_msrp_sr_class_vid, tvb,
MSRP_FIRST_VALUE_GROUP_OFFSET + msg_offset + 2, 2, ENC_BIG_ENDIAN);
offset = dissect_msrp_three_packed_event(vect_attr_tree, tvb,
MSRP_DOMAIN_THREE_PACKED_OFFSET + msg_offset + vect_offset,
number_of_values);
}
else {
first_value_ti = proto_tree_add_item(vect_attr_tree, hf_msrp_first_value, tvb,
MSRP_FIRST_VALUE_GROUP_OFFSET + msg_offset + vect_offset,
attribute_length, ENC_NA);
first_value_tree = proto_item_add_subtree(first_value_ti, ett_first_value);
proto_tree_add_item(first_value_tree, hf_msrp_stream_id, tvb,
MSRP_STREAM_ID_OFFSET + msg_offset + vect_offset, 8, ENC_BIG_ENDIAN);
switch ( attribute_type ) {
case MSRP_ATTRIBUTE_TYPE_LISTENER:
offset = dissect_msrp_three_packed_event(vect_attr_tree, tvb,
MSRP_LISTENER_THREE_PACKED_OFFSET + msg_offset + vect_offset,
number_of_values);
offset = dissect_msrp_four_packed_event(vect_attr_tree, tvb, offset, number_of_values);
break;
case MSRP_ATTRIBUTE_TYPE_TALKER_ADVERTISE:
dissect_msrp_talker_common(first_value_tree, tvb, msg_offset + vect_offset);
offset = dissect_msrp_three_packed_event(vect_attr_tree, tvb,
MSRP_TALKER_ADVERTISE_THREE_PACKED_OFFSET + msg_offset + vect_offset,
number_of_values);
break;
case MSRP_ATTRIBUTE_TYPE_TALKER_FAILED:
dissect_msrp_talker_common(first_value_tree, tvb, msg_offset + vect_offset);
dissect_msrp_talker_failed(first_value_tree, tvb, msg_offset + vect_offset);
offset = dissect_msrp_three_packed_event(vect_attr_tree, tvb,
MSRP_TALKER_FAILED_THREE_PACKED_OFFSET + msg_offset + vect_offset,
number_of_values);
break;
default:
proto_tree_add_text(first_value_tree, tvb, msg_offset + vect_offset, vect_attr_len, "Unknown Attribute");
break;
}
}
vect_offset += vect_attr_len;
}
proto_tree_add_item(attr_list_tree, hf_msrp_end_mark, tvb, offset, 2, ENC_BIG_ENDIAN);
msg_offset += msg_length;
}
proto_tree_add_item(msrp_tree, hf_msrp_end_mark, tvb, offset+2, 2, ENC_BIG_ENDIAN);
}
}
void
proto_register_mrp_msrp(void)
{
static hf_register_info hf[] = {
{ &hf_msrp_proto_id,
{ "Protocol Version", "mrp-msrp.protocol_version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_message,
{ "Message", "mrp-msrp.message",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_attribute_type,
{ "Attribute Type", "mrp-msrp.attribute_type",
FT_UINT8, BASE_DEC, VALS(attribute_type_vals), 0x0, NULL, HFILL }
},
{ &hf_msrp_attribute_length,
{ "Attribute Length", "mrp-msrp.attribute_length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_attribute_list_length,
{ "Attribute List Length", "mrp-msrp.attribute_list_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_attribute_list,
{ "Attribute List", "mrp-msrp.attribute_list",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_vector_attribute,
{ "Vector Attribute", "mrp-msrp.vector_attribute",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_vector_header,
{ "Vector Header", "mrp-msrp.vector_header",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_leave_all_event,
{ "Leave All Event", "mrp-msrp.leave_all_event",
FT_UINT16, BASE_DEC, VALS(leave_all_vals), MSRP_LEAVE_ALL_EVENT_MASK, NULL, HFILL }
},
{ &hf_msrp_number_of_values,
{ "Number of Values", "mrp-msrp.number_of_values",
FT_UINT16, BASE_DEC, NULL, MSRP_NUMBER_OF_VALUES_MASK, NULL, HFILL }
},
{ &hf_msrp_first_value,
{ "First Value", "mrp-msrp.first_value",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_stream_id,
{ "Stream ID", "mrp-msrp.stream_id",
FT_UINT64, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_msrp_stream_da,
{ "Stream DA", "mrp-msrp.stream_da",
FT_ETHER, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_msrp_vlan_id,
{ "VLAN ID", "mrp-msrp.vlan_id",
FT_UINT16, BASE_HEX, NULL, 0x00, NULL, HFILL }
},
{ &hf_msrp_tspec_max_frame_size,
{ "TSpec Max Frame Size", "mrp-msrp.tspec_max_frame_size",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_msrp_tspec_max_interval_frames,
{ "TSpec Max Frame Interval", "mrp-msrp.tspec_max_interval_frames",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_msrp_priority_and_rank,
{ "Priority and Rank", "mrp-msrp.priority_and_rank",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_priority,
{ "Priority", "mrp-msrp.priority",
FT_UINT8, BASE_DEC, VALS(priority_vals), MSRP_PRIORITY_MASK, NULL, HFILL }
},
{ &hf_msrp_rank,
{ "Rank", "mrp-msrp.rank",
FT_UINT8, BASE_DEC, VALS(rank_vals), MSRP_RANK_MASK, NULL, HFILL }
},
{ &hf_msrp_reserved,
{ "Reserved", "mrp-msrp.reserved",
FT_UINT8, BASE_DEC, VALS(reserved_vals), MSRP_RESERVED_MASK, NULL, HFILL }
},
{ &hf_msrp_accumulated_latency,
{ "Accumulated Latency", "mrp-msrp.accumulated_latency",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_failure_bridge_id,
{ "Failure Bridge ID", "mrp-msrp.failure_bridge_id",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_failure_code,
{ "Failure Code", "mrp-msrp.failure_code",
FT_UINT8, BASE_DEC, VALS(failure_vals), 0x0, NULL, HFILL }
},
{ &hf_msrp_sr_class_id,
{ "SR Class ID", "mrp-msrp.sr_class_id",
FT_UINT8, BASE_DEC, VALS(sr_class_vals), 0x0, NULL, HFILL }
},
{ &hf_msrp_sr_class_priority,
{ "SR Class Priority", "mrp-msrp.sr_class_priority",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_sr_class_vid,
{ "SR Class VID", "mrp-msrp.sr_class_vid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msrp_three_packed_event,
{ "Attribute Event", "mrp-msrp.three_packed_event",
FT_UINT8, BASE_DEC, VALS(three_packed_vals), 0x0, NULL, HFILL }
},
{ &hf_msrp_four_packed_event,
{ "Declaration Type", "mrp-msrp.four_packed_event",
FT_UINT8, BASE_DEC, VALS(four_packed_vals), 0x0, NULL, HFILL }
},
{ &hf_msrp_end_mark,
{ "End Mark", "mrp-msrp.end_mark",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_msrp,
&ett_msg,
&ett_attr_list,
&ett_vect_attr,
&ett_vector_header,
&ett_first_value,
&ett_priority_and_rank
};
proto_msrp = proto_register_protocol("Multiple Stream Reservation Protocol",
"MRP-MSRP", "mrp-msrp");
proto_register_field_array(proto_msrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mrp_msrp(void)
{
dissector_handle_t msrp_handle;
msrp_handle = create_dissector_handle(dissect_msrp, proto_msrp);
dissector_add_uint("ethertype", ETHERTYPE_MSRP, msrp_handle);
}
