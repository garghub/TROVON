static int
messenger_dissect_send_message_rqst(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep)
{
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_ndr_char_cvstring, NDR_POINTER_REF,
"Server", hf_messenger_server);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_ndr_char_cvstring, NDR_POINTER_REF,
"Client", hf_messenger_client);
offset = dissect_ndr_pointer(tvb, offset, pinfo, tree, drep,
dissect_ndr_char_cvstring, NDR_POINTER_REF,
"Message", hf_messenger_message);
return offset;
}
static int
messenger_dissect_send_message_reply(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint8 *drep)
{
offset = dissect_ntstatus(tvb, offset, pinfo, tree, drep,
hf_messenger_rc, NULL);
return offset;
}
void
proto_register_dcerpc_messenger(void)
{
static hf_register_info hf[] = {
{ &hf_messenger_opnum,
{ "Operation", "messenger.opnum", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_messenger_rc,
{ "Return code", "messenger.rc", FT_UINT32, BASE_HEX, VALS (NT_errors), 0x0, NULL, HFILL }},
{ &hf_messenger_server, {
"Server", "messenger.server",
FT_STRING, BASE_NONE, NULL, 0, "Server to send the message to", HFILL }},
{ &hf_messenger_client, {
"Client", "messenger.client",
FT_STRING, BASE_NONE, NULL, 0, "Client that sent the message", HFILL }},
{ &hf_messenger_message, {
"Message", "messenger.message",
FT_STRING, BASE_NONE, NULL, 0, "The message being sent", HFILL }}
};
static gint *ett[] = {
&ett_dcerpc_messenger
};
proto_dcerpc_messenger = proto_register_protocol(
"Microsoft Messenger Service", "Messenger", "messenger");
proto_register_field_array (proto_dcerpc_messenger, hf, array_length (hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dcerpc_messenger(void)
{
dcerpc_init_uuid(proto_dcerpc_messenger, ett_dcerpc_messenger, &uuid_dcerpc_messenger,
ver_dcerpc_messenger, dcerpc_messenger_dissectors, hf_messenger_opnum);
}
