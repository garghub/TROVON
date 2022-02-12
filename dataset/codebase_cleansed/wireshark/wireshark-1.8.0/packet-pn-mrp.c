static int
dissect_PNMRP_Common(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint16 sequence_id;
e_uuid_t uuid;
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_sequence_id, &sequence_id);
offset = dissect_pn_uuid(tvb, offset, pinfo, tree, hf_pn_mrp_domain_uuid, &uuid);
col_append_str(pinfo->cinfo, COL_INFO, "Common");
proto_item_append_text(item, "Common");
return offset;
}
static int
dissect_PNMRP_LinkUp(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint8 mac[6];
guint16 port_role;
guint16 interval;
guint16 blocked;
offset = dissect_pn_mac(tvb, offset, pinfo, tree, hf_pn_mrp_sa, mac);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_port_role, &port_role);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_interval, &interval);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_blocked, &blocked);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
col_append_str(pinfo->cinfo, COL_INFO, "LinkUp");
proto_item_append_text(item, "LinkUp");
return offset;
}
static int
dissect_PNMRP_LinkDown(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint8 mac[6];
guint16 port_role;
guint16 interval;
guint16 blocked;
offset = dissect_pn_mac(tvb, offset, pinfo, tree, hf_pn_mrp_sa, mac);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_port_role, &port_role);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_interval, &interval);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_blocked, &blocked);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
col_append_str(pinfo->cinfo, COL_INFO, "LinkDown");
proto_item_append_text(item, "LinkDown");
return offset;
}
static int
dissect_PNMRP_Test(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint16 prio;
guint8 mac[6];
guint16 port_role;
guint16 ring_state;
guint16 transition;
guint16 time_stamp;
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_prio, &prio);
offset = dissect_pn_mac(tvb, offset, pinfo, tree, hf_pn_mrp_sa, mac);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_port_role, &port_role);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_ring_state, &ring_state);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_transition, &transition);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_time_stamp, &time_stamp);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
col_append_str(pinfo->cinfo, COL_INFO, "Test");
proto_item_append_text(item, "Test");
return offset;
}
static int
dissect_PNMRP_TopologyChange(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint16 prio;
guint8 mac[6];
guint16 interval;
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_prio, &prio);
offset = dissect_pn_mac(tvb, offset, pinfo, tree, hf_pn_mrp_sa, mac);
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_interval, &interval);
col_append_str(pinfo->cinfo, COL_INFO, "TopologyChange");
proto_item_append_text(item, "TopologyChange");
return offset;
}
static int
dissect_PNMRP_Option(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item, guint8 length)
{
guint32 oui;
offset = dissect_pn_oid(tvb, offset, pinfo,tree, hf_pn_mrp_oui, &oui);
length -= 3;
switch (oui)
{
case OUI_SIEMENS:
proto_item_append_text(item, "Option(SIEMENS)");
if (offset % 4) {
length -= 4 - (offset % 4);
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
}
if(length != 0) {
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, length);
}
col_append_str(pinfo->cinfo, COL_INFO, "Option(Siemens)");
break;
default:
proto_item_append_text(item, "Option(Unknown-OUI)");
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, length);
col_append_str(pinfo->cinfo, COL_INFO, "Option");
}
offset += length;
offset = dissect_pn_align4(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_PNMRP_PDU(tvbuff_t *tvb, int offset,
packet_info *pinfo, proto_tree *tree, proto_item *item)
{
guint16 version;
guint8 type;
guint8 length;
gint i;
tvbuff_t *new_tvb;
offset = dissect_pn_uint16(tvb, offset, pinfo, tree, hf_pn_mrp_version, &version);
new_tvb = tvb_new_subset_remaining(tvb, offset);
offset = 0;
for(i=0; tvb_length_remaining(tvb, offset) > 0; i++) {
offset = dissect_pn_uint8(new_tvb, offset, pinfo, tree, hf_pn_mrp_type, &type);
offset = dissect_pn_uint8(new_tvb, offset, pinfo, tree, hf_pn_mrp_length, &length);
if(i != 0) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
proto_item_append_text(item, ", ");
}
switch(type) {
case(0x00):
col_append_str(pinfo->cinfo, COL_INFO, "End");
proto_item_append_text(item, "End");
return offset;
break;
case(0x01):
offset = dissect_PNMRP_Common(new_tvb, offset, pinfo, tree, item);
break;
case(0x02):
offset = dissect_PNMRP_Test(new_tvb, offset, pinfo, tree, item);
break;
case(0x03):
offset = dissect_PNMRP_TopologyChange(new_tvb, offset, pinfo, tree, item);
break;
case(0x04):
offset = dissect_PNMRP_LinkDown(new_tvb, offset, pinfo, tree, item);
break;
case(0x05):
offset = dissect_PNMRP_LinkUp(new_tvb, offset, pinfo, tree, item);
break;
case(0x7f):
offset = dissect_PNMRP_Option(new_tvb, offset, pinfo, tree, item, length);
break;
default:
offset = dissect_pn_undecoded(tvb, offset, pinfo, tree, length);
col_append_fstr(pinfo->cinfo, COL_INFO, "Unknown TLVType 0x%x", type);
proto_item_append_text(item, "Unknown TLVType 0x%x", type);
}
}
return offset;
}
static void
dissect_PNMRP(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *mrp_tree = NULL;
guint32 offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PN-MRP");
col_clear(pinfo->cinfo, COL_INFO);
if (tree)
{
ti = proto_tree_add_item(tree, proto_pn_mrp, tvb, offset, -1, ENC_NA);
mrp_tree = proto_item_add_subtree(ti, ett_pn_mrp);
}
dissect_PNMRP_PDU(tvb, offset, pinfo, mrp_tree, ti);
}
void
proto_register_pn_mrp (void)
{
static hf_register_info hf[] = {
{ &hf_pn_mrp_type,
{ "Type", "pn_mrp.type", FT_UINT8, BASE_HEX, VALS(pn_mrp_block_type_vals), 0x0, NULL, HFILL }},
{ &hf_pn_mrp_length,
{ "Length", "pn_mrp.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_mrp_version,
{ "Version", "pn_mrp.version", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_mrp_sequence_id,
{ "SequenceID", "pn_mrp.sequence_id", FT_UINT16, BASE_HEX, NULL, 0x0, "Unique sequence number to each outstanding service request", HFILL }},
{ &hf_pn_mrp_sa,
{ "SA", "pn_mrp.sa", FT_ETHER, BASE_NONE, 0x0, 0x0, NULL, HFILL }},
{ &hf_pn_mrp_prio,
{ "Prio", "pn_mrp.prio", FT_UINT16, BASE_HEX, VALS(pn_mrp_prio_vals), 0x0, NULL, HFILL }},
{ &hf_pn_mrp_port_role,
{ "PortRole", "pn_mrp.port_role", FT_UINT16, BASE_HEX, VALS(pn_mrp_port_role_vals), 0x0, NULL, HFILL }},
{ &hf_pn_mrp_ring_state,
{ "RingState", "pn_mrp.ring_state", FT_UINT16, BASE_HEX, VALS(pn_mrp_ring_state_vals), 0x0, NULL, HFILL }},
{ &hf_pn_mrp_interval,
{ "Interval", "pn_mrp.interval", FT_UINT16, BASE_DEC, NULL, 0x0, "Interval for next topology change event (in ms)", HFILL }},
{ &hf_pn_mrp_transition,
{ "Transition", "pn_mrp.transition", FT_UINT16, BASE_HEX, NULL, 0x0, "Number of transitions between media redundancy lost and ok states", HFILL }},
{ &hf_pn_mrp_time_stamp,
{ "TimeStamp", "pn_mrp.time_stamp", FT_UINT16, BASE_HEX, NULL, 0x0, "Actual counter value of 1ms counter", HFILL }},
{ &hf_pn_mrp_blocked,
{ "Blocked", "pn_mrp.blocked", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_mrp_manufacturer_oui,
{ "ManufacturerOUI", "pn_mrp.manufacturer_oui", FT_UINT24, BASE_HEX, VALS(pn_mrp_oui_vals), 0x0, NULL, HFILL }},
{ &hf_pn_mrp_domain_uuid,
{ "DomainUUID", "pn_mrp.domain_uuid", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pn_mrp_oui,
{ "Organizationally Unique Identifier", "pn_mrp.oui", FT_UINT24, BASE_HEX,
VALS(pn_mrp_oui_vals), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_pn_mrp
};
proto_pn_mrp = proto_register_protocol ("PROFINET MRP", "PN-MRP", "pn_mrp");
proto_register_field_array (proto_pn_mrp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_pn_mrp (void)
{
dissector_handle_t mrp_handle;
mrp_handle = create_dissector_handle(dissect_PNMRP,proto_pn_mrp);
dissector_add_uint("ethertype", ETHERTYPE_MRP, mrp_handle);
}
