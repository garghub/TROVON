static guint get_opcua_message_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
gint32 plen;
plen = tvb_get_letohl(tvb, offset + 4);
return plen;
}
static int dissect_opcua_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
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
fragment_head *frag_msg = NULL;
offset = 3;
chunkType = tvb_get_guint8(tvb, offset); offset += 1;
offset += 4;
offset += 4;
offset += 4;
opcua_num = tvb_get_letohl(tvb, offset); offset += 4;
opcua_seqid = tvb_get_letohl(tvb, offset); offset += 4;
if (chunkType == 'A')
{
fragment_delete(&opcua_reassembly_table, pinfo, opcua_seqid, NULL);
col_clear_fence(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_INFO, "Abort message");
offset = 0;
(*pfctParse)(transport_tree, tvb, pinfo, &offset);
parseAbort(transport_tree, tvb, pinfo, &offset);
return tvb_reported_length(tvb);
}
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
tvb_captured_length_remaining(tvb, offset),
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
iServiceId = (*pfctParse)(transport_tree, tvb, pinfo, &offset);
if (msgtype == MSG_MESSAGE && bParseService)
{
if (bIsLastFragment != FALSE)
{
offset = 0;
}
iServiceId = parseService(transport_tree, next_tvb, pinfo, &offset);
}
if (iServiceId != -1)
{
const gchar *szServiceName = val_to_str((guint32)iServiceId, g_requesttypes, "ServiceId %d");
if (bIsLastFragment == FALSE)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s", g_szMessageTypes[msgtype], szServiceName);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: %s (Message Reassembled)", g_szMessageTypes[msgtype], szServiceName);
}
}
}
return tvb_reported_length(tvb);
}
static int dissect_opcua(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, FRAME_HEADER_LEN,
get_opcua_message_len, dissect_opcua_message, data);
return tvb_reported_length(tvb);
}
void proto_register_opcua(void)
{
static hf_register_info hf[] =
{
{&hf_opcua_fragments, {"Message fragments", "opcua.fragments", FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_fragment, {"Message fragment", "opcua.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_fragment_overlap, {"Message fragment overlap", "opcua.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_fragment_overlap_conflicts, {"Message fragment overlapping with conflicting data", "opcua.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_fragment_multiple_tails, {"Message has multiple tail fragments", "opcua.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_fragment_too_long_fragment, {"Message fragment too long", "opcua.fragment.too_long_fragment", FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_fragment_error, {"Message defragmentation error", "opcua.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_fragment_count, {"Message fragment count", "opcua.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_reassembled_in, {"Reassembled in", "opcua.reassembled.in", FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL}},
{&hf_opcua_reassembled_length, {"Reassembled length", "opcua.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL}}
};
static gint *ett[] =
{
&ett_opcua_extensionobject,
&ett_opcua_nodeid,
&ett_opcua_transport,
&ett_opcua_fragment,
&ett_opcua_fragments
};
proto_opcua = proto_register_protocol("OpcUa Binary Protocol", "OpcUa", "opcua");
registerTransportLayerTypes(proto_opcua);
registerSecurityLayerTypes(proto_opcua);
registerApplicationLayerTypes(proto_opcua);
registerSimpleTypes(proto_opcua);
registerEnumTypes(proto_opcua);
registerComplexTypes();
registerServiceTypes();
registerFieldTypes(proto_opcua);
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_opcua, hf, array_length(hf));
reassembly_table_register(&opcua_reassembly_table,
&addresses_reassembly_table_functions);
}
void proto_reg_handoff_opcua(void)
{
opcua_handle = create_dissector_handle(dissect_opcua, proto_opcua);
dissector_add_uint_range_with_preference("tcp.port", OPCUA_PORT_RANGE, opcua_handle);
}
