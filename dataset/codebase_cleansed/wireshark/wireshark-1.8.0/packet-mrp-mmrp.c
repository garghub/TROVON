static void
dissect_mmrp_common1(proto_tree *msg_tree, tvbuff_t *tvb, int msg_offset)
{
proto_tree_add_item(msg_tree, hf_mmrp_attribute_type, tvb,
MMRP_ATTRIBUTE_TYPE_OFFSET + msg_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msg_tree, hf_mmrp_attribute_length, tvb,
MMRP_ATTRIBUTE_LENGTH_OFFSET + msg_offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_mmrp_common2(proto_tree *vect_attr_tree, tvbuff_t *tvb, int msg_offset)
{
proto_tree_add_bitmask(vect_attr_tree, tvb, MMRP_VECTOR_HEADER_OFFSET + msg_offset,
hf_mmrp_vector_header, ett_vector_header, vector_header_fields, ENC_BIG_ENDIAN);
}
static guint
dissect_mmrp_three_packed_event(proto_tree *vect_attr_tree, tvbuff_t *tvb, guint offset, guint16 number_of_values)
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
proto_tree_add_uint(vect_attr_tree, hf_mmrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[0]);
counter++;
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_mmrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[1]);
counter++;
}
if ( counter < number_of_values ) {
proto_tree_add_uint(vect_attr_tree, hf_mmrp_three_packed_event, tvb, offset, sizeof(guint8),
three_packed_event[2]);
counter++;
}
offset++;
}
return( offset );
}
static void
dissect_mmrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *msg_ti, *attr_list_ti, *vect_attr_ti;
proto_tree *mmrp_tree, *msg_tree, *attr_list_tree, *vect_attr_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MRP-MMRP");
col_set_str(pinfo->cinfo, COL_INFO, "Multiple Mac Registration Protocol");
if (tree) {
guint8 attribute_type;
guint8 attribute_length;
guint16 number_of_values;
guint offset = 0;
int vect_attr_len;
int msg_offset;
int vect_offset;
ti = proto_tree_add_item(tree, proto_mmrp, tvb, 0, -1, ENC_NA);
mmrp_tree = proto_item_add_subtree(ti, ett_mmrp);
proto_tree_add_item(mmrp_tree, hf_mmrp_proto_id, tvb, MMRP_PROTOCOL_VERSION_OFFSET, 1, ENC_BIG_ENDIAN);
msg_offset = 0;
while (tvb_get_ntohs(tvb, MMRP_ATTRIBUTE_TYPE_OFFSET + msg_offset) != MMRP_END_MARK) {
attribute_type = tvb_get_guint8(tvb, MMRP_ATTRIBUTE_TYPE_OFFSET + msg_offset);
attribute_length = tvb_get_guint8(tvb, MMRP_ATTRIBUTE_LENGTH_OFFSET + msg_offset);
msg_ti = proto_tree_add_item(mmrp_tree, hf_mmrp_message, tvb,
MMRP_MESSAGE_GROUP_OFFSET + msg_offset,
-1, ENC_NA);
msg_tree = proto_item_add_subtree(msg_ti, ett_msg);
proto_item_append_text(msg_tree, ": %s (%d)", val_to_str(attribute_type,
attribute_type_vals, "<Unknown>"), attribute_type);
dissect_mmrp_common1(msg_tree, tvb, msg_offset);
attr_list_ti = proto_tree_add_item(msg_tree, hf_mmrp_attribute_list, tvb,
MMRP_ATTRIBUTE_LIST_GROUP_OFFSET + msg_offset,
-1, ENC_NA);
attr_list_tree = proto_item_add_subtree(attr_list_ti, ett_attr_list);
vect_offset = 0;
while (tvb_get_ntohs(tvb, MMRP_VECTOR_HEADER_OFFSET + msg_offset + vect_offset) != MMRP_END_MARK) {
number_of_values = tvb_get_ntohs(tvb, MMRP_NUMBER_OF_VALUES_OFFSET + msg_offset + vect_offset)
& MMRP_NUMBER_OF_VALUES_MASK;
vect_attr_len = 2 + attribute_length + (number_of_values + 2)/3;
vect_attr_ti = proto_tree_add_item(attr_list_tree, hf_mmrp_vector_attribute, tvb,
MMRP_VECTOR_ATTRIBUTE_GROUP_OFFSET + msg_offset + vect_offset,
vect_attr_len, ENC_NA);
vect_attr_tree = proto_item_add_subtree(vect_attr_ti, ett_vect_attr);
dissect_mmrp_common2(vect_attr_tree, tvb, msg_offset + vect_offset);
if (attribute_type == MMRP_ATTRIBUTE_TYPE_MAC) {
proto_tree_add_item(vect_attr_tree, hf_mmrp_first_value, tvb,
MMRP_FIRST_VALUE_GROUP_OFFSET + msg_offset + vect_offset,
attribute_length, ENC_NA);
offset = dissect_mmrp_three_packed_event(vect_attr_tree, tvb,
MMRP_MAC_THREE_PACKED_OFFSET + msg_offset + vect_offset,
number_of_values);
}
else if (attribute_type == MMRP_ATTRIBUTE_TYPE_SERVICE) {
proto_tree_add_item(vect_attr_tree, hf_mmrp_first_value, tvb,
MMRP_FIRST_VALUE_GROUP_OFFSET + msg_offset + vect_offset,
attribute_length, ENC_NA);
offset = dissect_mmrp_three_packed_event(vect_attr_tree, tvb,
MMRP_MAC_THREE_PACKED_OFFSET + msg_offset + vect_offset,
number_of_values);
}
vect_offset += vect_attr_len;
}
proto_tree_add_item(attr_list_tree, hf_mmrp_end_mark, tvb, offset, 2, ENC_NA);
proto_item_set_len(attr_list_ti, vect_offset);
msg_offset += vect_offset + 2;
proto_item_set_len(msg_ti, vect_offset + 2);
}
proto_tree_add_item(mmrp_tree, hf_mmrp_end_mark, tvb, offset+2, 2, ENC_NA);
}
}
void
proto_register_mrp_mmrp(void)
{
static hf_register_info hf[] = {
{ &hf_mmrp_proto_id,
{ "Protocol Version", "mrp-mmrp.protocol_version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_mmrp_message,
{ "Message", "mrp-mmrp.message",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_mmrp_attribute_type,
{ "Attribute Type", "mrp-mmrp.attribute_type",
FT_UINT8, BASE_DEC, VALS(attribute_type_vals), 0x0, NULL, HFILL }
},
{ &hf_mmrp_attribute_length,
{ "Attribute Length", "mrp-mmrp.attribute_length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_mmrp_attribute_list,
{ "Attribute List", "mrp-mmrp.attribute_list",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_mmrp_vector_attribute,
{ "Vector Attribute", "mrp-mmrp.vector_attribute",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_mmrp_vector_header,
{ "Vector Header", "mrp-mmrp.vector_header",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_mmrp_leave_all_event,
{ "Leave All Event", "mrp-mmrp.leave_all_event",
FT_UINT16, BASE_DEC, VALS(leave_all_vals), MMRP_LEAVE_ALL_EVENT_MASK, NULL, HFILL }
},
{ &hf_mmrp_number_of_values,
{ "Number of Values", "mrp-mmrp.number_of_values",
FT_UINT16, BASE_DEC, NULL, MMRP_NUMBER_OF_VALUES_MASK, NULL, HFILL }
},
{ &hf_mmrp_first_value,
{ "First Value", "mrp-mmrp.first_value",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_mmrp_three_packed_event,
{ "Attribute Event", "mrp-msrp.three_packed_event",
FT_UINT8, BASE_DEC, VALS(three_packed_vals), 0x0, NULL, HFILL }
},
{ &hf_mmrp_end_mark,
{ "End Mark", "mrp-mmrp.end_mark",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_mmrp,
&ett_msg,
&ett_attr_list,
&ett_vect_attr,
&ett_vector_header,
&ett_first_value
};
proto_mmrp = proto_register_protocol("Multiple Mac Registration Protocol",
"MRP-MMRP", "mrp-mmrp");
proto_register_field_array(proto_mmrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mrp_mmrp(void)
{
dissector_handle_t mmrp_handle;
mmrp_handle = create_dissector_handle(dissect_mmrp, proto_mmrp);
dissector_add_uint("ethertype", ETHERTYPE_MMRP, mmrp_handle);
}
