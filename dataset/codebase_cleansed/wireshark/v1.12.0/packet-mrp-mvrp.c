static void
dissect_mvrp_common1(proto_tree *msg_tree, tvbuff_t *tvb, int msg_offset)
{
proto_tree_add_item(msg_tree, hf_mvrp_attribute_type, tvb,
MVRP_ATTRIBUTE_TYPE_OFFSET + msg_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msg_tree, hf_mvrp_attribute_length, tvb,
MVRP_ATTRIBUTE_LENGTH_OFFSET + msg_offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_mvrp_common2(proto_tree *vect_attr_tree, tvbuff_t *tvb, int msg_offset)
{
proto_tree_add_bitmask(vect_attr_tree, tvb, MVRP_VECTOR_HEADER_OFFSET + msg_offset,
hf_mvrp_vector_header, ett_vector_header, vector_header_fields, ENC_BIG_ENDIAN);
}
static guint
dissect_mvrp_three_packed_event(proto_tree *vect_attr_tree, tvbuff_t *tvb, guint offset, guint16 number_of_values)
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
proto_tree_add_uint(vect_attr_tree, hf_mvrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[0]);
counter++;
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_mvrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[1]);
counter++;
}
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_mvrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[2]);
counter++;
}
offset++;
}
return( offset );
}
static void
dissect_mvrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *msg_ti, *attr_list_ti, *vect_attr_ti, *first_value_ti;
proto_tree *mvrp_tree, *msg_tree, *attr_list_tree, *vect_attr_tree, *first_value_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MRP-MVRP");
col_set_str(pinfo->cinfo, COL_INFO, "Multiple VLAN Registration Protocol");
if (tree) {
guint8 attribute_type;
guint8 attribute_length;
guint16 number_of_values;
guint offset = 0;
int vect_attr_len;
int msg_offset;
int vect_offset;
ti = proto_tree_add_item(tree, proto_mvrp, tvb, 0, -1, ENC_NA);
mvrp_tree = proto_item_add_subtree(ti, ett_mvrp);
proto_tree_add_item(mvrp_tree, hf_mvrp_proto_id, tvb, MVRP_PROTOCOL_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
msg_offset = 0;
while (tvb_get_ntohs(tvb, MVRP_ATTRIBUTE_TYPE_OFFSET + msg_offset) != MVRP_END_MARK) {
attribute_type = tvb_get_guint8(tvb, MVRP_ATTRIBUTE_TYPE_OFFSET + msg_offset);
attribute_length = tvb_get_guint8(tvb, MVRP_ATTRIBUTE_LENGTH_OFFSET + msg_offset);
msg_ti = proto_tree_add_item(mvrp_tree, hf_mvrp_message, tvb,
MVRP_MESSAGE_GROUP_OFFSET + msg_offset,
-1, ENC_NA);
msg_tree = proto_item_add_subtree(msg_ti, ett_msg);
proto_item_append_text(msg_tree, ": %s (%d)",
val_to_str_const(attribute_type, attribute_type_vals, "<Unknown>"),
attribute_type);
dissect_mvrp_common1(msg_tree, tvb, msg_offset);
attr_list_ti = proto_tree_add_item(msg_tree, hf_mvrp_attribute_list, tvb,
MVRP_ATTRIBUTE_LIST_GROUP_OFFSET + msg_offset,
-1, ENC_NA);
attr_list_tree = proto_item_add_subtree(attr_list_ti, ett_attr_list);
vect_offset = 0;
while (tvb_get_ntohs(tvb, MVRP_VECTOR_HEADER_OFFSET + msg_offset + vect_offset) != MVRP_END_MARK) {
number_of_values = tvb_get_ntohs(tvb, MVRP_NUMBER_OF_VALUES_OFFSET + msg_offset + vect_offset)
& MVRP_NUMBER_OF_VALUES_MASK;
vect_attr_len = 2 + attribute_length + (number_of_values + 2)/3;
vect_attr_ti = proto_tree_add_item(attr_list_tree, hf_mvrp_vector_attribute, tvb,
MVRP_VECTOR_ATTRIBUTE_GROUP_OFFSET + msg_offset + vect_offset,
vect_attr_len, ENC_NA);
vect_attr_tree = proto_item_add_subtree(vect_attr_ti, ett_vect_attr);
dissect_mvrp_common2(vect_attr_tree, tvb, msg_offset + vect_offset);
if (attribute_type == MVRP_ATTRIBUTE_TYPE_VID) {
first_value_ti = proto_tree_add_item(vect_attr_tree, hf_mvrp_first_value, tvb,
MVRP_FIRST_VALUE_GROUP_OFFSET + msg_offset + vect_offset,
attribute_length, ENC_NA);
first_value_tree = proto_item_add_subtree(first_value_ti, ett_first_value);
proto_tree_add_item(first_value_tree, hf_mvrp_vid, tvb,
MVRP_FIRST_VALUE_GROUP_OFFSET + msg_offset + vect_offset, 2, ENC_BIG_ENDIAN);
offset = dissect_mvrp_three_packed_event(vect_attr_tree, tvb,
MVRP_VID_THREE_PACKED_OFFSET + msg_offset + vect_offset,
number_of_values);
}
vect_offset += vect_attr_len;
}
proto_tree_add_item(attr_list_tree, hf_mvrp_end_mark, tvb, offset, 2, ENC_NA);
proto_item_set_len(attr_list_ti, vect_offset);
msg_offset += vect_offset + 2;
proto_item_set_len(msg_ti, vect_offset + 2);
}
proto_tree_add_item(mvrp_tree, hf_mvrp_end_mark, tvb, offset+2, 2, ENC_NA);
}
}
void
proto_register_mrp_mvrp(void)
{
static hf_register_info hf[] = {
{ &hf_mvrp_proto_id,
{ "Protocol Version", "mrp-mvrp.protocol_version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_mvrp_message,
{ "Message", "mrp-mvrp.message",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_mvrp_attribute_type,
{ "Attribute Type", "mrp-mvrp.attribute_type",
FT_UINT8, BASE_DEC, VALS(attribute_type_vals), 0x0, NULL, HFILL }
},
{ &hf_mvrp_attribute_length,
{ "Attribute Length", "mrp-mvrp.attribute_length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_mvrp_attribute_list,
{ "Attribute List", "mrp-mvrp.attribute_list",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_mvrp_vector_attribute,
{ "Vector Attribute", "mrp-mvrp.vector_attribute",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_mvrp_vector_header,
{ "Vector Header", "mrp-mvrp.vector_header",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_mvrp_leave_all_event,
{ "Leave All Event", "mrp-mvrp.leave_all_event",
FT_UINT16, BASE_DEC, VALS(leave_all_vals), MVRP_LEAVE_ALL_EVENT_MASK, NULL, HFILL }
},
{ &hf_mvrp_number_of_values,
{ "Number of Values", "mrp-mvrp.number_of_values",
FT_UINT16, BASE_DEC, NULL, MVRP_NUMBER_OF_VALUES_MASK, NULL, HFILL }
},
{ &hf_mvrp_first_value,
{ "First Value", "mrp-mvrp.first_value",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_mvrp_vid,
{ "VLAN ID", "mrp-mvrp.vid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_mvrp_three_packed_event,
{ "Attribute Event", "mrp-msrp.three_packed_event",
FT_UINT8, BASE_DEC, VALS(three_packed_vals), 0x0, NULL, HFILL }
},
{ &hf_mvrp_end_mark,
{ "End Mark", "mrp-mvrp.end_mark",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_mvrp,
&ett_msg,
&ett_attr_list,
&ett_vect_attr,
&ett_vector_header,
&ett_first_value
};
proto_mvrp = proto_register_protocol("Multiple VLAN Registration Protocol",
"MRP-MVRP", "mrp-mvrp");
proto_register_field_array(proto_mvrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mrp_mvrp(void)
{
dissector_handle_t mvrp_handle;
mvrp_handle = create_dissector_handle(dissect_mvrp, proto_mvrp);
dissector_add_uint("ethertype", ETHERTYPE_MVRP, mvrp_handle);
}
