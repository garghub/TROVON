void proto_register_opcua(void)
{
module_t *opcua_module;
proto_opcua = proto_register_protocol(
"OpcUa Binary Protocol",
"OpcUa",
"opcua"
);
registerTransportLayerTypes(proto_opcua);
registerSecurityLayerTypes(proto_opcua);
registerApplicationLayerTypes(proto_opcua);
registerSimpleTypes(proto_opcua);
registerEnumTypes(proto_opcua);
registerComplexTypes();
registerServiceTypes();
registerFieldTypes(proto_opcua);
proto_register_subtree_array(ett, array_length(ett));
range_convert_str(&global_tcp_ports_opcua, ep_strdup_printf("%u", OPCUA_PORT), 65535);
opcua_module = prefs_register_protocol(proto_opcua, proto_reg_handoff_opcua);
prefs_register_range_preference(opcua_module, "tcp_ports",
"OPC UA TCP Ports",
"The TCP ports for the OPC UA TCP Binary Protocol",
&global_tcp_ports_opcua, 65535);
}
static guint get_opcua_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
gint32 plen;
plen = tvb_get_letohl(tvb, offset + 4);
return plen;
}
static void dissect_opcua(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, FRAME_HEADER_LEN,
get_opcua_message_len, dissect_opcua_message);
}
static void dissect_opcua_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
FctParse pfctParse = NULL;
enum MessageType msgtype = MSG_INVALID;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OpcUa");
if (tvb_memeql(tvb, 0, "HEL", 3) == 0)
{
msgtype = MSG_HELLO;
pfctParse = parseHello;
}
else if (tvb_memeql(tvb, 0, "ACK", 3) == 0)
{
msgtype = MSG_ACKNOWLEDGE;
pfctParse = parseAcknowledge;
}
else if (tvb_memeql(tvb, 0, "ERR", 3) == 0)
{
msgtype = MSG_ERROR;
pfctParse = parseError;
}
else if (tvb_memeql(tvb, 0, "MSG", 3) == 0)
{
msgtype = MSG_MESSAGE;
pfctParse = parseMessage;
}
else if (tvb_memeql(tvb, 0, "OPN", 3) == 0)
{
msgtype = MSG_OPENSECURECHANNEL;
pfctParse = parseOpenSecureChannel;
}
else if (tvb_memeql(tvb, 0, "CLO", 3) == 0)
{
msgtype = MSG_CLOSESECURECHANNEL;
pfctParse = parseCloseSecureChannel;
}
else
{
msgtype = MSG_INVALID;
}
col_set_str(pinfo->cinfo, COL_INFO, g_szMessageTypes[msgtype]);
if (tree && pfctParse)
{
gint offset = 0;
int iServiceId = -1;
proto_item *ti = NULL;
proto_tree *transport_tree = NULL;
ti = proto_tree_add_item(tree, proto_opcua, tvb, 0, -1, ENC_NA);
transport_tree = proto_item_add_subtree(ti, ett_opcua_transport);
iServiceId = (*pfctParse)(transport_tree, tvb, &offset);
if (iServiceId != -1)
{
int index = 0;
while (index < g_NumServices)
{
if (g_requesttypes[index].value == (guint32)iServiceId)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s", g_szMessageTypes[msgtype], g_requesttypes[index].strptr);
break;
}
index++;
}
}
}
}
static void register_tcp_port(guint32 port)
{
if (port != 0)
dissector_add_uint("tcp.port", port, opcua_handle);
}
static void unregister_tcp_port(guint32 port)
{
if (port != 0)
dissector_delete_uint("tcp.port", port, opcua_handle);
}
void proto_reg_handoff_opcua(void)
{
static gboolean opcua_initialized = FALSE;
static range_t *tcp_ports_opcua = NULL;
if(!opcua_initialized)
{
opcua_handle = create_dissector_handle(dissect_opcua, proto_opcua);
opcua_initialized = TRUE;
}
else
{
if (tcp_ports_opcua != NULL)
{
range_foreach(tcp_ports_opcua, unregister_tcp_port);
g_free(tcp_ports_opcua);
}
}
tcp_ports_opcua = range_copy(global_tcp_ports_opcua);
range_foreach(tcp_ports_opcua, register_tcp_port);
}
