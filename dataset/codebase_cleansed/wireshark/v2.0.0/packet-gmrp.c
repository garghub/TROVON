static void
dissect_gmrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *gmrp_tree, *msg_tree, *attr_tree;
guint16 protocol_id;
guint8 octet;
guint8 attribute_type;
int msg_index, attr_index, offset = 0, length = tvb_reported_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GMRP");
col_set_str(pinfo->cinfo, COL_INFO, "GMRP");
ti = proto_tree_add_item(tree, proto_gmrp, tvb, 0, -1, ENC_NA);
gmrp_tree = proto_item_add_subtree(ti, ett_gmrp);
protocol_id = tvb_get_ntohs(tvb, GARP_PROTOCOL_ID);
ti = proto_tree_add_uint_format_value(gmrp_tree, hf_gmrp_proto_id, tvb,
GARP_PROTOCOL_ID, 2, protocol_id,
"0x%04x (%s)", protocol_id,
protocol_id == GARP_DEFAULT_PROTOCOL_ID ?
"GARP Multicast Registration Protocol" :
"Unknown Protocol");
if (protocol_id != GARP_DEFAULT_PROTOCOL_ID)
{
expert_add_info(pinfo, ti, &ei_gmrp_proto_id);
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, GARP_PROTOCOL_ID + 2),
pinfo, tree);
return;
}
offset += 2;
length -= 2;
msg_index = 0;
while (length)
{
proto_item *msg_item;
int msg_start = offset;
attribute_type = octet = tvb_get_guint8(tvb, offset);
if (octet == GARP_END_OF_MARK)
{
if (msg_index)
{
proto_tree_add_uint_format(gmrp_tree, hf_gmrp_end_of_mark, tvb, offset, 1, octet, "End of pdu");
break;
}
else
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
return;
}
}
offset += 1;
length -= 1;
msg_tree = proto_tree_add_subtree_format(gmrp_tree, tvb, msg_start, -1,
ett_gmrp_message, &msg_item, "Message %d", msg_index + 1);
proto_tree_add_uint(msg_tree, hf_gmrp_attribute_type, tvb,
msg_start, 1, octet);
if ( (octet != GMRP_ATTRIBUTE_TYPE_GROUP_MEMBERSHIP) && (octet != GMRP_ATTRIBUTE_TYPE_SERVICE_REQUIREMENT) )
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo,
tree);
return;
}
attr_index = 0;
while (length)
{
int attr_start = offset;
proto_item *attr_item;
octet = tvb_get_guint8(tvb, offset);
if (octet == GARP_END_OF_MARK)
{
if (attr_index)
{
proto_tree_add_uint_format(msg_tree, hf_gmrp_end_of_mark, tvb, offset,
1, octet, " End of mark");
offset += 1;
length -= 1;
proto_item_set_len(msg_item, offset - msg_start);
break;
}
else
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
return;
}
}
else
{
guint8 event;
offset += 1;
length -= 1;
attr_tree = proto_tree_add_subtree_format(msg_tree, tvb, attr_start, -1,
ett_gmrp_attribute_list, &attr_item, " Attribute %d", attr_index + 1);
proto_tree_add_uint(attr_tree, hf_gmrp_attribute_length,
tvb, attr_start, 1, octet);
event = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(attr_tree, hf_gmrp_attribute_event,
tvb, offset, 1, event);
offset += 1;
length -= 1;
switch (event) {
case GMRP_EVENT_LEAVEALL:
if (octet != GMRP_LENGTH_LEAVEALL)
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
return;
}
break;
case GMRP_EVENT_JOINEMPTY:
case GMRP_EVENT_JOININ:
case GMRP_EVENT_LEAVEEMPTY:
case GMRP_EVENT_LEAVEIN:
case GMRP_EVENT_EMPTY:
if ( (octet != GMRP_GROUP_MEMBERSHIP_NON_LEAVEALL) &&
(octet != GMRP_SERVICE_REQUIREMENT_NON_LEAVEALL) )
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
return;
}
if ( GMRP_ATTRIBUTE_TYPE_GROUP_MEMBERSHIP == attribute_type )
{
proto_tree_add_item(attr_tree, hf_gmrp_attribute_value_group_membership,
tvb, offset, 6, ENC_NA);
offset += 6;
length -= 6;
}
else
if ( GMRP_ATTRIBUTE_TYPE_SERVICE_REQUIREMENT == attribute_type )
{
proto_tree_add_item(attr_tree, hf_gmrp_attribute_value_service_requirement,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
}
else
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
return;
}
break;
default:
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
return;
}
}
proto_item_set_len(attr_item, offset - attr_start);
attr_index++;
}
msg_index++;
}
}
void
proto_register_gmrp(void)
{
static hf_register_info hf[] = {
{ &hf_gmrp_proto_id,
{ "Protocol Identifier", "gmrp.protocol_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL , HFILL }
},
{ &hf_gmrp_attribute_type,
{ "Type", "gmrp.attribute_type",
FT_UINT8, BASE_HEX, VALS(attribute_type_vals), 0x0,
NULL , HFILL }
},
{ &hf_gmrp_attribute_length,
{ "Length", "gmrp.attribute_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL , HFILL }
},
{ &hf_gmrp_attribute_event,
{ "Event", "gmrp.attribute_event",
FT_UINT8, BASE_DEC, VALS(event_vals), 0x0,
NULL , HFILL }
},
{ &hf_gmrp_attribute_value_group_membership,
{ "Value", "gmrp.attribute_value_group_membership",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL , HFILL }
},
{ &hf_gmrp_attribute_value_service_requirement,
{ "Value", "gmrp.attribute_value_service_requirement",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL , HFILL }
},
{ &hf_gmrp_end_of_mark,
{ "End of mark", "gmrp.end_of_mark",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL , HFILL }
}
};
static gint *ett[] = {
&ett_gmrp,
&ett_gmrp_message,
&ett_gmrp_attribute_list
};
static ei_register_info ei[] = {
{ &ei_gmrp_proto_id, { "gmrp.protocol_id.not_gmrp", PI_UNDECODED, PI_WARN, "This version of Wireshark only knows about protocol id = 1", EXPFILL }},
};
expert_module_t* expert_gmrp;
proto_gmrp = proto_register_protocol("GARP Multicast Registration Protocol", "GMRP", "gmrp");
proto_register_field_array(proto_gmrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gmrp = expert_register_protocol(proto_gmrp);
expert_register_field_array(expert_gmrp, ei, array_length(ei));
register_dissector("gmrp", dissect_gmrp, proto_gmrp);
}
void
proto_reg_handoff_gmrp(void){
data_handle = find_dissector("data");
}
