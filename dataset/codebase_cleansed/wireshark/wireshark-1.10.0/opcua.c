void proto_register_opcua(void)
{
static hf_register_info hf[] =
{
{&hf_opcua_fragments,
{"Message fragments", "opcua.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_fragment,
{"Message fragment", "opcua.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_fragment_overlap,
{"Message fragment overlap", "opcua.fragment.overlap",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"opcua.fragment.overlap.conflicts",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_fragment_multiple_tails,
{"Message has multiple tail fragments",
"opcua.fragment.multiple_tails",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_fragment_too_long_fragment,
{"Message fragment too long", "opcua.fragment.too_long_fragment",
FT_BOOLEAN, 0, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_fragment_error,
{"Message defragmentation error", "opcua.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_fragment_count,
{"Message fragment count", "opcua.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_reassembled_in,
{"Reassembled in", "opcua.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_opcua_reassembled_length,
{"Reassembled length", "opcua.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } }
};
static gint *ett[] =
{
&ett_opcua_transport,
&ett_opcua_extensionobject,
&ett_opcua_nodeid,
&ett_opcua_fragment,
&ett_opcua_fragments
};
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
reassembly_table_init(&opcua_reassembly_table,
&addresses_reassembly_table_functions);
proto_register_field_array(proto_opcua, hf, array_length(hf));
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
if (pfctParse)
{
gint offset = 0;
int iServiceId = -1;
tvbuff_t *next_tvb = tvb;
gboolean bParseService = TRUE;
gboolean bIsLastFragment = FALSE;
proto_item *ti = NULL;
proto_tree *transport_tree = NULL;
ti = proto_tree_add_item(tree, proto_opcua, tvb, 0, -1, ENC_NA);
transport_tree = proto_item_add_subtree(ti, ett_opcua_transport);
if (msgtype == MSG_MESSAGE)
{
guint8 chunkType = 0;
guint32 opcua_seqid = 0;
guint32 opcua_num = 0;
guint32 opcua_seqnum = 0;
fragment_data *frag_msg = NULL;
offset = 3;
chunkType = tvb_get_guint8(tvb, offset); offset += 1;
offset += 4;
offset += 4;
offset += 4;
opcua_num = tvb_get_letohl(tvb, offset); offset += 4;
opcua_seqid = tvb_get_letohl(tvb, offset); offset += 4;
frag_msg = fragment_get(&opcua_reassembly_table, pinfo, opcua_seqid, NULL);
if (frag_msg == NULL)
{
frag_msg = fragment_get_reassembled_id(&opcua_reassembly_table, pinfo, opcua_seqid);
}
if (frag_msg != NULL || chunkType != 'F')
{
gboolean bSaveFragmented = pinfo->fragmented;
gboolean bMoreFragments = TRUE;
tvbuff_t *new_tvb = NULL;
pinfo->fragmented = TRUE;
if (frag_msg == NULL)
{
opcua_seqnum = 0;
}
else
{
while (frag_msg->next) {frag_msg = frag_msg->next;}
opcua_seqnum = frag_msg->offset + 1;
if (chunkType == 'F')
{
bMoreFragments = FALSE;
}
}
frag_msg = fragment_add_seq_check(&opcua_reassembly_table,
tvb,
offset,
pinfo,
opcua_seqid,
NULL,
opcua_seqnum,
tvb_length_remaining(tvb, offset),
bMoreFragments);
new_tvb = process_reassembled_data(tvb,
offset,
pinfo,
"Reassembled Message",
frag_msg,
&opcua_frag_items,
NULL,
transport_tree);
if (new_tvb)
{
bIsLastFragment = TRUE;
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, " (Message fragment %u)", opcua_num);
}
if (new_tvb)
{
next_tvb = new_tvb;
}
else
{
bParseService = FALSE;
next_tvb = tvb_new_subset_remaining(tvb, 0);
}
pinfo->fragmented = bSaveFragmented;
}
}
offset = 0;
iServiceId = (*pfctParse)(transport_tree, tvb, &offset);
if (msgtype == MSG_MESSAGE && bParseService)
{
if (bIsLastFragment != FALSE)
{
offset = 0;
}
iServiceId = parseService(transport_tree, next_tvb, &offset);
}
if (iServiceId != -1)
{
int indx = 0;
while (indx < g_NumServices)
{
if (g_requesttypes[indx].value == (guint32)iServiceId)
{
if (bIsLastFragment == FALSE)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s", g_szMessageTypes[msgtype], g_requesttypes[indx].strptr);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s (Message Reassembled)", g_szMessageTypes[msgtype], g_requesttypes[indx].strptr);
}
break;
}
indx++;
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
