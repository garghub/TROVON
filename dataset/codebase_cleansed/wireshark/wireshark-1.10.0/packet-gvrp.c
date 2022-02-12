static void
dissect_gvrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *gvrp_tree;
guint16 protocol_id;
guint8 octet;
int msg_index;
int attr_index;
int offset = 0;
int length = tvb_reported_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GVRP");
col_set_str(pinfo->cinfo, COL_INFO, "GVRP");
if (tree)
{
ti = proto_tree_add_item(tree, proto_gvrp, tvb, 0, length, ENC_NA);
gvrp_tree = proto_item_add_subtree(ti, ett_gvrp);
protocol_id = tvb_get_ntohs(tvb, GARP_PROTOCOL_ID);
proto_tree_add_uint_format(gvrp_tree, hf_gvrp_proto_id, tvb,
GARP_PROTOCOL_ID, (int)sizeof(guint16),
protocol_id,
"Protocol Identifier: 0x%04x (%s)",
protocol_id,
protocol_id == GARP_DEFAULT_PROTOCOL_ID ?
"GARP VLAN Registration Protocol" :
"Unknown Protocol");
if (protocol_id != GARP_DEFAULT_PROTOCOL_ID)
{
proto_tree_add_text(gvrp_tree, tvb, GARP_PROTOCOL_ID, (int)sizeof(guint16),
" (Warning: this version of Wireshark only knows about protocol id = 1)");
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, GARP_PROTOCOL_ID + (int)sizeof(guint16)),
pinfo, tree);
return;
}
offset += (int)sizeof(guint16);
length -= (int)sizeof(guint16);
msg_index = 0;
while (length)
{
proto_item *msg_item;
int msg_start = offset;
octet = tvb_get_guint8(tvb, offset);
if (octet == GARP_END_OF_MARK)
{
if (msg_index)
{
proto_tree_add_text(gvrp_tree, tvb, offset, (int)sizeof(guint8),
"End of mark");
break;
}
else
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return;
}
}
offset += (int)sizeof(guint8);
length -= (int)sizeof(guint8);
msg_item = proto_tree_add_text(gvrp_tree, tvb, msg_start, -1,
"Message %d", msg_index + 1);
proto_tree_add_uint(gvrp_tree, hf_gvrp_attribute_type, tvb,
msg_start, (int)sizeof(guint8), octet);
if (octet != GVRP_ATTRIBUTE_TYPE)
{
call_dissector(data_handle, tvb_new_subset_remaining(tvb, offset),
pinfo, tree);
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
proto_tree_add_text(gvrp_tree, tvb, offset,
(int)sizeof(guint8), " End of mark");
offset += (int)sizeof(guint8);
length -= (int)sizeof(guint8);
proto_item_set_len(msg_item, offset - msg_start);
break;
}
else
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return;
}
}
else
{
guint8 event;
offset += (int)sizeof(guint8);
length -= (int)sizeof(guint8);
attr_item = proto_tree_add_text(gvrp_tree, tvb,
attr_start, -1, " Attribute %d", attr_index + 1);
proto_tree_add_uint(gvrp_tree, hf_gvrp_attribute_length,
tvb, attr_start, (int)sizeof(guint8), octet);
event = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(gvrp_tree, hf_gvrp_attribute_event,
tvb, offset, (int)sizeof(guint8), event);
offset += (int)sizeof(guint8);
length -= (int)sizeof(guint8);
switch (event) {
case GVRP_EVENT_LEAVEALL:
if (octet != GVRP_LENGTH_LEAVEALL)
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo,
tree);
return;
}
break;
case GVRP_EVENT_JOINEMPTY:
case GVRP_EVENT_JOININ:
case GVRP_EVENT_LEAVEEMPTY:
case GVRP_EVENT_LEAVEIN:
case GVRP_EVENT_EMPTY:
if (octet != GVRP_LENGTH_NON_LEAVEALL)
{
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset),pinfo,
tree);
return;
}
proto_tree_add_item(gvrp_tree, hf_gvrp_attribute_value,
tvb, offset, (int)sizeof(guint16), ENC_BIG_ENDIAN);
offset += (int)sizeof(guint16);
length -= (int)sizeof (guint16);
break;
default:
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return;
}
}
proto_item_set_len(attr_item, offset - attr_start);
attr_index++;
}
msg_index++;
}
}
}
void
proto_register_gvrp(void)
{
static hf_register_info hf[] = {
{ &hf_gvrp_proto_id,
{ "Protocol ID", "gvrp.protocol_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvrp_attribute_type,
{ "Type", "gvrp.attribute_type",
FT_UINT8, BASE_HEX, VALS(attribute_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_gvrp_attribute_length,
{ "Length", "gvrp.attribute_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvrp_attribute_event,
{ "Event", "gvrp.attribute_event",
FT_UINT8, BASE_DEC, VALS(event_vals), 0x0,
NULL, HFILL }
},
{ &hf_gvrp_attribute_value,
{ "Value", "gvrp.attribute_value",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gvrp
};
proto_gvrp = proto_register_protocol("GARP VLAN Registration Protocol",
"GVRP", "gvrp");
proto_register_field_array(proto_gvrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gvrp", dissect_gvrp, proto_gvrp);
}
void
proto_reg_handoff_gvrp(void){
data_handle = find_dissector("data");
}
