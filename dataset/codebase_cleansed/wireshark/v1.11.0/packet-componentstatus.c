static void
dissect_componentstatusprotocol_componentassociation_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
proto_tree_add_item(message_tree, hf_componentassociation_receiverid, message_tvb, COMPONENTASSOCIATION_RECEIVERID_OFFSET, COMPONENTASSOCIATION_RECEIVERID_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_componentassociation_duration, message_tvb, COMPONENTASSOCIATION_DURATION_OFFSET, COMPONENTASSOCIATION_DURATION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_componentassociation_flags, message_tvb, COMPONENTASSOCIATION_FLAGS_OFFSET, COMPONENTASSOCIATION_FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_componentassociation_protocolid, message_tvb, COMPONENTASSOCIATION_PROTOCOLID_OFFSET, COMPONENTASSOCIATION_PROTOCOLID_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_componentassociation_ppid, message_tvb, COMPONENTASSOCIATION_PPID_OFFSET, COMPONENTASSOCIATION_PPID_LENGTH, ENC_BIG_ENDIAN);
}
static void
dissect_componentstatusprotocol_componentstatusreport_message(tvbuff_t *message_tvb, proto_tree *message_tree)
{
tvbuff_t *association_tvb;
proto_item *association_item;
proto_tree *association_tree;
int i;
gint offset;
proto_tree_add_item(message_tree, hf_componentstatusreport_reportinterval, message_tvb, COMPONENTSTATUSREPORT_REPORTINTERVAL_OFFSET, COMPONENTSTATUSREPORT_REPORTINTERVAL_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_componentstatusreport_location, message_tvb, COMPONENTSTATUSREPORT_LOCATION_OFFSET, COMPONENTSTATUSREPORT_LOCATION_LENGTH, ENC_ASCII|ENC_NA);
proto_tree_add_item(message_tree, hf_componentstatusreport_status, message_tvb, COMPONENTSTATUSREPORT_STATUS_OFFSET, COMPONENTSTATUSREPORT_STATUS_LENGTH, ENC_ASCII|ENC_NA);
proto_tree_add_item(message_tree, hf_componentstatusreport_workload, message_tvb, COMPONENTSTATUSREPORT_WORKLOAD_OFFSET, COMPONENTSTATUSREPORT_WORKLOAD_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_componentstatusreport_associations, message_tvb, COMPONENTSTATUSREPORT_ASSOCIATIONS_OFFSET, COMPONENTSTATUSREPORT_ASSOCIATIONS_LENGTH, ENC_BIG_ENDIAN);
offset = COMPONENTSTATUSREPORT_ASSOCIATIONARRAY_OFFSET;
i = 1;
while(tvb_reported_length_remaining(message_tvb, offset) >= COMPONENTASSOCIATION_LENGTH) {
association_item = proto_tree_add_text(message_tree, message_tvb, offset, COMPONENTASSOCIATION_LENGTH,
"Association #%d", i++);
association_tree = proto_item_add_subtree(association_item, ett_association);
association_tvb = tvb_new_subset(message_tvb, offset,
MIN(COMPONENTASSOCIATION_LENGTH, tvb_length_remaining(message_tvb, offset)),
COMPONENTASSOCIATION_LENGTH);
dissect_componentstatusprotocol_componentassociation_message(association_tvb, association_tree);
offset += COMPONENTASSOCIATION_LENGTH;
}
}
static void
dissect_componentstatusprotocol_message(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *componentstatusprotocol_tree)
{
proto_item* flags_item;
proto_tree* flags_tree;
guint8 type;
type = tvb_get_guint8(message_tvb, MESSAGE_TYPE_OFFSET);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_const(type, message_type_values, "Unknown ComponentStatusProtocol type"));
proto_tree_add_item(componentstatusprotocol_tree, hf_message_type, message_tvb, MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH, ENC_BIG_ENDIAN);
flags_item = proto_tree_add_item(componentstatusprotocol_tree, hf_message_flags, message_tvb, MESSAGE_FLAGS_OFFSET, MESSAGE_FLAGS_LENGTH, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_message_flags);
proto_tree_add_item(flags_tree, hf_message_flags_final_bit, message_tvb, MESSAGE_FLAGS_OFFSET, MESSAGE_FLAGS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(componentstatusprotocol_tree, hf_message_length, message_tvb, MESSAGE_LENGTH_OFFSET, MESSAGE_LENGTH_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(componentstatusprotocol_tree, hf_message_version, message_tvb, MESSAGE_VERSION_OFFSET, MESSAGE_VERSION_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(componentstatusprotocol_tree, hf_message_senderid, message_tvb, MESSAGE_SENDERID_OFFSET, MESSAGE_SENDERID_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(componentstatusprotocol_tree, hf_message_sendertimestamp, message_tvb, MESSAGE_SENDERTIMESTAMP_OFFSET, MESSAGE_SENDERTIMESTAMP_LENGTH, ENC_BIG_ENDIAN);
switch (type) {
case COMPONENTSTATUS_COMPONENTSTATUSREPORT_MESSAGE_TYPE:
dissect_componentstatusprotocol_componentstatusreport_message(message_tvb, componentstatusprotocol_tree);
break;
}
}
static int
dissect_componentstatusprotocol(tvbuff_t *message_tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *componentstatusprotocol_item;
proto_tree *componentstatusprotocol_tree;
gint8 type;
gint32 version;
if (tvb_length(message_tvb) < (MESSAGE_VERSION_OFFSET + MESSAGE_VERSION_LENGTH))
return(0);
type = tvb_get_guint8(message_tvb, MESSAGE_TYPE_OFFSET);
if (type != COMPONENTSTATUS_COMPONENTSTATUSREPORT_MESSAGE_TYPE) {
return(0);
}
version = tvb_get_ntohl(message_tvb, MESSAGE_VERSION_OFFSET);
if (version != COMPONENTSTATUSPROTOCOL_VERSION) {
return(0);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ComponentStatusProtocol");
if (tree) {
componentstatusprotocol_item = proto_tree_add_item(tree, proto_componentstatusprotocol, message_tvb, 0, -1, ENC_NA);
componentstatusprotocol_tree = proto_item_add_subtree(componentstatusprotocol_item, ett_componentstatusprotocol);
} else {
componentstatusprotocol_tree = NULL;
};
dissect_componentstatusprotocol_message(message_tvb, pinfo, componentstatusprotocol_tree);
return(tvb_length(message_tvb));
}
void
proto_register_componentstatusprotocol(void)
{
static hf_register_info hf[] = {
{ &hf_message_type, { "Type", "componentstatusprotocol.message_type", FT_UINT8, BASE_DEC, VALS(message_type_values), 0x0, NULL, HFILL } },
{ &hf_message_flags, { "Flags", "componentstatusprotocol.message_flags", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_flags_final_bit, { "F-Bit", "componentstatusprotocol.message_final_bit", FT_BOOLEAN, 8, TFS(&message_flags_final_bit), CSPF_FINAL, NULL, HFILL } },
{ &hf_message_length, { "Length", "componentstatusprotocol.message_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_message_version, { "Version", "componentstatusprotocol.message_version", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_message_senderid, { "SenderID", "componentstatusprotocol.message_senderid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_message_sendertimestamp, { "SenderTimeStamp", "componentstatusprotocol.message_sendertimestamp", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_componentstatusreport_reportinterval, { "ReportInterval", "componentstatusprotocol.componentstatusreport_reportinterval", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_componentstatusreport_location, { "Location", "componentstatusprotocol.componentstatusreport_location", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_componentstatusreport_status, { "Status", "componentstatusprotocol.componentstatusreport_status", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_componentstatusreport_workload, { "Workload", "componentstatusprotocol.componentstatusreport_workload", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_componentstatusreport_associations, { "Associations", "componentstatusprotocol.componentstatusreport_associations", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
#if 0
{ &hf_componentstatusreport_associationarray, { "AssociationArray", "componentstatusprotocol.componentstatusreport_AssociationArray", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
#endif
{ &hf_componentassociation_receiverid, { "ReceiverID", "componentstatusprotocol.componentassociation_receiverid", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_componentassociation_duration, { "Duration", "componentstatusprotocol.componentassociation_duration", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_componentassociation_flags, { "Flags", "componentstatusprotocol.componentassociation_flags", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_componentassociation_protocolid, { "ProtocolID", "componentstatusprotocol.componentassociation_protocolid", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_componentassociation_ppid, { "PPID", "componentstatusprotocol.componentassociation_ppid", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_componentstatusprotocol,
&ett_message_flags,
&ett_association
};
proto_componentstatusprotocol = proto_register_protocol("Component Status Protocol", "ComponentStatusProtocol", "componentstatusprotocol");
proto_register_field_array(proto_componentstatusprotocol, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_componentstatusprotocol(void)
{
dissector_handle_t componentstatusprotocol_handle;
componentstatusprotocol_handle = new_create_dissector_handle(dissect_componentstatusprotocol, proto_componentstatusprotocol);
dissector_add_uint("udp.port", COMPONENTSTATUSPROTOCOL_PORT, componentstatusprotocol_handle);
}
