static int
dissect_octet_string(tvbuff_t *tvb, proto_tree *tree, int offset, guint8 flags)
{
guint32 n_oct, p_noct;
NORLEL(flags, n_oct, tvb, offset);
p_noct = PADDING(n_oct);
proto_tree_add_uint(tree, hf_ostring_len, tvb, offset, 4, n_oct);
proto_tree_add_item(tree, hf_ostring, tvb, offset + 4, n_oct, ENC_ASCII|ENC_NA);
return p_noct + 4;
}
static int
convert_oid_to_str(guint32 *oid, int len, char* str, int slen, char prefix)
{
int i, tlen = 0;
if(!oid) return 0;
if(!str) return 0;
if(!len) return 0;
if(!slen) return 0;
if(slen < len) return 0;
if(prefix) {
tlen += g_snprintf(str, slen, ".1.3.6.1.%d", prefix);
}
for(i=0; i < len && tlen < slen; i++) {
tlen += g_snprintf(str+tlen, slen-tlen, ".%d", oid[i]);
}
return tlen;
}
static int
dissect_object_id(tvbuff_t *tvb, proto_tree *tree, int offset, guint8 flags, enum OID_USAGE oid_usage)
{
guint8 n_subid;
guint8 prefix;
guint8 include;
proto_item* item;
proto_tree* subtree;
guint32 oid[2048];
char str_oid[2048];
int i;
memset(oid, '\0', sizeof(oid));
memset(str_oid, '\0', sizeof(str_oid));
n_subid = tvb_get_guint8(tvb, offset);
prefix = tvb_get_guint8(tvb, offset + 1);
include = tvb_get_guint8(tvb, offset + 2);
tvb_get_guint8(tvb, offset + 3);
for(i=0; i<n_subid; i++) {
NORLEL(flags, oid[i], tvb, (offset+4) + (i*4));
}
if(!convert_oid_to_str(&oid[0], n_subid, &str_oid[0], 2048, prefix))
g_snprintf(&str_oid[0], 2048, "(null)");
if(tree) {
const char *range = "";
const char *inclusion = (include) ? " (Inclusive)" : " (Exclusive)";
switch (oid_usage) {
case OID_START_RANGE: range = "(Range Start) "; break;
case OID_END_RANGE: range = " (Range End) "; break;
default: inclusion = ""; break;
}
item = proto_tree_add_text(tree, tvb, offset, 4 + (n_subid * 4) ,
"Object Identifier: %s%s%s", range, str_oid, inclusion);
subtree = proto_item_add_subtree(item, ett_obj_ident);
} else
return offset;
proto_tree_add_uint(subtree, hf_oid_sub, tvb, offset, 1, n_subid);
proto_tree_add_uint(subtree, hf_oid_prefix, tvb, offset + 1, 1, prefix);
proto_tree_add_boolean(subtree, hf_oid_include, tvb, offset + 2, 1, include);
proto_tree_add_string(subtree, hf_oid_str, tvb, offset + 4, (n_subid * 4), str_oid);
return 4 + (n_subid * 4);
}
static int
dissect_search_range(tvbuff_t *tvb, proto_tree *tree, int start_offset, guint8 flags, guint8 pdu_type)
{
int offset = start_offset;
offset += dissect_object_id(tvb, tree, offset, flags, (pdu_type == AGENTX_GET_PDU) ? OID_EXACT : OID_START_RANGE);
offset += dissect_object_id(tvb, tree, offset, flags, (pdu_type == AGENTX_GET_PDU) ? OID_EXACT : OID_END_RANGE);
return (offset - start_offset);
}
static int
dissect_val64(tvbuff_t *tvb, proto_tree *tree, int offset, guint8 flags)
{
guint encoding = (flags & NETWORK_BYTE_ORDER) ? ENC_BIG_ENDIAN : ENC_LITTLE_ENDIAN;
proto_tree_add_item(tree, hf_val64, tvb, offset, 8, encoding);
return 8;
}
static int
dissect_val32(tvbuff_t *tvb, proto_tree *tree, int offset, guint8 flags)
{
guint encoding = (flags & NETWORK_BYTE_ORDER) ? ENC_BIG_ENDIAN : ENC_LITTLE_ENDIAN;
proto_tree_add_item(tree, hf_val32, tvb, offset, 4, encoding);
return 4;
}
static int
dissect_varbind(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
guint16 vtag;
int tlen;
proto_item* item;
proto_tree* subtree;
NORLES(flags, vtag, tvb, offset);
if(tree) {
item = proto_tree_add_text(tree, tvb, offset, len, "Value Representation");
subtree = proto_item_add_subtree(item, ett_valrep);
} else return len;
proto_tree_add_uint(subtree, hf_vtag, tvb, offset, 2, vtag);
tlen = dissect_object_id(tvb, subtree, offset + 4, flags, OID_EXACT);
switch(vtag)
{
case VB_OID:
tlen += dissect_object_id(tvb, subtree, offset + tlen + 4, flags, OID_EXACT);
break;
case VB_OPAQUE:
case VB_OSTR:
case VB_IPADDR:
tlen += dissect_octet_string(tvb, subtree, offset + tlen + 4, flags);
break;
case VB_TIMETICK:
case VB_COUNTER32:
case VB_INT:
case VB_GAUGE32:
tlen += dissect_val32(tvb, subtree, offset + tlen + 4, flags);
break;
case VB_COUNTER64:
tlen += dissect_val64(tvb, subtree, offset + tlen + 4, flags);
break;
case VB_NULL:
case VB_NOSUCHOBJ:
case VB_NOSUCHINST:
case VB_ENDOFMIB:
break;
}
return tlen + 4;
}
static void
dissect_response_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
guint encoding = (flags & NETWORK_BYTE_ORDER) ? ENC_BIG_ENDIAN : ENC_LITTLE_ENDIAN;
guint32 r_uptime;
item = proto_tree_add_text(tree, tvb, offset, len, "Response-PDU");
subtree = proto_item_add_subtree(item, ett_response);
NORLEL(flags, r_uptime, tvb, offset);
proto_tree_add_uint_format(subtree, hf_resp_uptime, tvb, offset, 4, r_uptime,
"sysUptime: %s", time_msecs_to_ep_str(r_uptime));
proto_tree_add_item(subtree, hf_resp_error, tvb, offset + 4, 2, encoding);
proto_tree_add_item(subtree, hf_resp_index, tvb, offset + 6, 2, encoding);
offset += 8;
len += PDU_HDR_LEN;
while(len > offset) {
offset += dissect_varbind(tvb, subtree, offset, len, flags);
}
}
static void
dissect_getnext_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "GetNext-PDU");
subtree = proto_item_add_subtree(item, ett_getnext);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
len += PDU_HDR_LEN;
while(len > offset) {
offset += dissect_search_range(tvb, subtree, offset, flags, 0);
}
}
static void
dissect_get_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "Get-PDU");
subtree = proto_item_add_subtree(item, ett_get);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
len += PDU_HDR_LEN;
while(len > offset) {
offset += dissect_search_range(tvb, subtree, offset, flags, AGENTX_GET_PDU);
}
}
static void
dissect_getbulk_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
guint encoding = (flags & NETWORK_BYTE_ORDER) ? ENC_BIG_ENDIAN : ENC_LITTLE_ENDIAN;
item = proto_tree_add_text(tree, tvb, offset, len, "GetBulk-PDU");
subtree = proto_item_add_subtree(item, ett_getbulk);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
proto_tree_add_item(subtree, hf_gbulk_nrepeat, tvb, offset, 2, encoding);
proto_tree_add_item(subtree, hf_gbulk_mrepeat, tvb, offset + 2, 2, encoding);
offset+=4;
while(len >= offset) {
offset += dissect_search_range(tvb, subtree, offset, flags, 0);
}
}
static int
dissect_open_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
guint8 timeout;
item = proto_tree_add_text(tree, tvb, offset, len, "Open-PDU");
subtree = proto_item_add_subtree(item, ett_open);
timeout = tvb_get_guint8(tvb, offset);
tvb_get_ntoh24(tvb, offset + 1);
proto_tree_add_uint(subtree, hf_open_timeout, tvb, offset, 1, timeout);
offset+=4;
offset += dissect_object_id(tvb, subtree, offset, flags, OID_EXACT);
offset += dissect_octet_string(tvb, subtree, offset, flags);
return offset;
}
static int
dissect_close_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len)
{
proto_item* item;
proto_tree* subtree;
guint8 reason;
item = proto_tree_add_text(tree, tvb, offset, len, "Close-PDU");
subtree = proto_item_add_subtree(item, ett_close);
reason = tvb_get_guint8(tvb, offset);
tvb_get_ntoh24(tvb, offset + 1);
proto_tree_add_uint(subtree, hf_close_reason, tvb, offset, 1, reason);
offset+=4;
return offset;
}
static int
dissect_register_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
guint encoding = (flags & NETWORK_BYTE_ORDER) ? ENC_BIG_ENDIAN : ENC_LITTLE_ENDIAN;
item = proto_tree_add_text(tree, tvb, offset, len, "Register-PDU");
subtree = proto_item_add_subtree(item, ett_register);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
proto_tree_add_item(subtree, hf_reg_timeout, tvb, offset, 1, encoding);
proto_tree_add_item(subtree, hf_reg_prio, tvb, offset+1, 1, encoding);
proto_tree_add_item(subtree, hf_reg_rsid, tvb, offset+2, 1, encoding);
offset+=4;
offset += dissect_object_id(tvb, subtree, offset, flags, OID_EXACT);
len += PDU_HDR_LEN;
if(len > offset) {
proto_tree_add_item(subtree, hf_reg_ubound, tvb, offset, 4, encoding);
offset += 4;
}
return offset;
}
static int
dissect_unregister_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
guint encoding = (flags & NETWORK_BYTE_ORDER) ? ENC_BIG_ENDIAN : ENC_LITTLE_ENDIAN;
item = proto_tree_add_text(tree, tvb, offset, len, "Unregister-PDU");
subtree = proto_item_add_subtree(item, ett_unregister);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
proto_tree_add_item(subtree, hf_unreg_timeout, tvb, offset, 1, encoding);
proto_tree_add_item(subtree, hf_unreg_prio, tvb, offset+1, 1, encoding);
proto_tree_add_item(subtree, hf_unreg_rsid, tvb, offset+2, 1, encoding);
offset+=4;
offset += dissect_object_id(tvb, subtree, offset, flags, OID_EXACT);
len += PDU_HDR_LEN;
if(len > offset) {
proto_tree_add_item(subtree, hf_unreg_ubound, tvb, offset, 4, encoding);
offset += 4;
}
return offset;
}
static void
dissect_testset_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "Testset-PDU");
subtree = proto_item_add_subtree(item, ett_testset);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
while(len > offset) {
offset += dissect_varbind(tvb, subtree, offset, len, flags);
}
}
static void
dissect_notify_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "Notify-PDU");
subtree = proto_item_add_subtree(item, ett_notify);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
while(len > offset) {
offset += dissect_varbind(tvb, subtree, offset, len, flags);
}
}
static int
dissect_ping_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "Ping-PDU");
subtree = proto_item_add_subtree(item, ett_ping);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
return offset;
}
static void
dissect_idx_alloc_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "IndexAllocate-PDU");
subtree = proto_item_add_subtree(item, ett_idxalloc);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
while(len > offset) {
offset += dissect_varbind(tvb, subtree, offset, len, flags);
}
}
static void
dissect_idx_dealloc_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "IndexDeallocate-PDU");
subtree = proto_item_add_subtree(item, ett_idxdalloc);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
while(len > offset) {
offset += dissect_varbind(tvb, subtree, offset, len, flags);
}
}
static int
dissect_add_caps_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "AddAgentCaps-PDU");
subtree = proto_item_add_subtree(item, ett_addcap);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
offset += dissect_object_id(tvb, subtree, offset, flags, OID_EXACT);
offset += dissect_octet_string(tvb, subtree, offset, flags);
return offset;
}
static int
dissect_rem_caps_pdu(tvbuff_t *tvb, proto_tree *tree, int offset, int len, guint8 flags)
{
proto_item* item;
proto_tree* subtree;
item = proto_tree_add_text(tree, tvb, offset, len, "RemoveAgentCaps-PDU");
subtree = proto_item_add_subtree(item, ett_remcap);
if(flags & NON_DEFAULT_CONTEXT) {
offset += dissect_octet_string(tvb, subtree, offset, flags);
}
offset += dissect_object_id(tvb, subtree, offset, flags, OID_EXACT);
return offset;
}
static guint
get_agentx_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint8 flags;
guint32 plen;
flags = tvb_get_guint8(tvb, offset + 2);
NORLEL(flags, plen, tvb, offset + 16);
if (plen > 0xFFFFFF)
plen = 0xFFFFFF;
return plen + 20;
}
static int
dissect_agentx_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_tree* agentx_tree, *pdu_hdr_tree, *flags_tree;
proto_item* pdu_item , *t_item;
guint8 version;
guint8 type;
guint8 flags;
guint32 session_id;
guint32 trans_id;
guint32 packet_id;
guint32 payload_len;
version = tvb_get_guint8(tvb, 0); offset+=1;
type = tvb_get_guint8(tvb, 1); offset+=1;
flags = tvb_get_guint8(tvb, 2); offset+=1;
offset+=1;
NORLEL(flags, session_id, tvb, 4); offset+=4;
NORLEL(flags, trans_id, tvb, 8); offset+=4;
NORLEL(flags, packet_id, tvb, 12); offset+=4;
NORLEL(flags, payload_len, tvb, 16); offset+=4;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AgentX");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s: sid=%d, tid=%d, packid=%d, plen=%d",
val_to_str_ext_const(type, &type_values_ext, "unknown"),
session_id, trans_id, packet_id, payload_len);
if(!tree)
return 0;
t_item = proto_tree_add_protocol_format(tree, proto_agentx, tvb, 0, -1,
"Agent Extensibility (AgentX) Protocol: %s, sid=%d, tid=%d, packid=%d, plen=%d",
val_to_str_ext_const(type, &type_values_ext, "unknown"),
session_id, trans_id, packet_id, payload_len);
agentx_tree = proto_item_add_subtree(t_item, ett_agentx);
pdu_item = proto_tree_add_text(agentx_tree, tvb, 0, PDU_HDR_LEN, "PDU Header: Type[%u], len=%d, sid=%d, tid=%d, packid=%d",
(char)type, payload_len, session_id, trans_id, packet_id);
pdu_hdr_tree = proto_item_add_subtree(pdu_item, ett_pdu_hdr);
proto_tree_add_uint(pdu_hdr_tree, hf_version, tvb, 0, 1, version);
proto_tree_add_uint(pdu_hdr_tree, hf_type, tvb, 1, 1, type);
t_item = proto_tree_add_text(pdu_hdr_tree, tvb, 2, 1, "Flags: 0x%02x", flags);
flags_tree = proto_item_add_subtree(t_item, ett_flags);
proto_tree_add_boolean(flags_tree, hf_flags_register, tvb, 2, 1, flags);
proto_tree_add_boolean(flags_tree, hf_flags_newindex, tvb, 2, 1, flags);
proto_tree_add_boolean(flags_tree, hf_flags_anyindex, tvb, 2, 1, flags);
proto_tree_add_boolean(flags_tree, hf_flags_context, tvb, 2, 1, flags);
proto_tree_add_boolean(flags_tree, hf_flags_byteorder, tvb, 2, 1, flags);
proto_tree_add_uint(pdu_hdr_tree, hf_session_id, tvb, 4, 4, session_id);
proto_tree_add_uint(pdu_hdr_tree, hf_trans_id, tvb, 8, 4, trans_id);
proto_tree_add_uint(pdu_hdr_tree, hf_packet_id, tvb, 12, 4, packet_id);
proto_tree_add_uint(pdu_hdr_tree, hf_payload_len, tvb, 16, 4, payload_len);
switch(type) {
case AGENTX_OPEN_PDU:
dissect_open_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_CLOSE_PDU:
dissect_close_pdu(tvb, agentx_tree, offset, payload_len);
break;
case AGENTX_REGISTER_PDU:
dissect_register_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_UNREGISTER_PDU:
dissect_unregister_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_GET_PDU:
dissect_get_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_GETNEXT_PDU:
dissect_getnext_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_GETBULK_PDU:
dissect_getbulk_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_TESTSET_PDU:
dissect_testset_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_COMMITSET_PDU:
case AGENTX_UNDOSET_PDU:
case AGENTX_CLEANUPSET_PDU:
break;
case AGENTX_NOTIFY_PDU:
dissect_notify_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_PING_PDU:
dissect_ping_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_INDEX_ALLOC_PDU:
dissect_idx_alloc_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_INDEX_DEALLOC_PDU:
dissect_idx_dealloc_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_ADD_AGENT_CAPS_PDU:
dissect_add_caps_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_REM_AGENT_CAPS_PDU:
dissect_rem_caps_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
case AGENTX_RESPONSE_PDU:
dissect_response_pdu(tvb, agentx_tree, offset, payload_len, flags);
break;
}
return tvb_length(tvb);
}
static int
dissect_agentx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 20, get_agentx_pdu_len,
dissect_agentx_pdu, data);
return tvb_length(tvb);
}
void
proto_register_agentx(void)
{
static hf_register_info hf[] = {
{ &hf_version,
{ "Version", "agentx.version", FT_UINT8, BASE_DEC, NULL, 0x0,
"header version", HFILL }},
{ &hf_type,
{ "Type", "agentx.type", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &type_values_ext, 0x0,
"header type", HFILL }},
#if 0
{ &hf_flags,
{ "Flags", "agentx.flags", FT_UINT8, BASE_DEC, NULL, 0x0,
"header type", HFILL }},
#endif
{ &hf_flags_register,
{ "Register", "agentx.flags.register", FT_BOOLEAN, 8, TFS(&tfs_agentx_register),
INSTANCE_REGISTRATION, "Instance Registration", HFILL }},
{ &hf_flags_newindex,
{ "New Index", "agentx.flags.newindex", FT_BOOLEAN, 8, TFS(&tfs_agentx_newindex),
NEW_INDEX, "New Index Requested", HFILL }},
{ &hf_flags_anyindex,
{ "Any Index", "agentx.flags.anyindex", FT_BOOLEAN, 8, TFS(&tfs_agentx_anyindex),
ANY_INDEX, "Any Index Requested", HFILL }},
{ &hf_flags_context,
{ "Non-default Context", "agentx.flags.context", FT_BOOLEAN, 8, TFS(&tfs_agentx_context),
NON_DEFAULT_CONTEXT, NULL, HFILL }},
{ &hf_flags_byteorder,
{ "Byte Order", "agentx.flags.byteorder", FT_BOOLEAN, 8, TFS(&tfs_agentx_byteorder),
NETWORK_BYTE_ORDER, NULL, HFILL }},
{ &hf_session_id,
{ "sessionID", "agentx.session_id", FT_UINT32, BASE_DEC, NULL, 0x0,
"Session ID", HFILL }},
{ &hf_trans_id,
{ "TransactionID", "agentx.transaction_id", FT_UINT32, BASE_DEC, NULL, 0x0,
"Transaction ID", HFILL }},
{ &hf_packet_id,
{ "PacketID", "agentx.packet_id", FT_UINT32, BASE_DEC, NULL, 0x0,
"Packet ID", HFILL }},
{ &hf_payload_len,
{ "Payload length", "agentx.payload_len", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ostring,
{ "Octet String", "agentx.ostring", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ostring_len,
{ "OString len", "agentx.ostring_len", FT_UINT32, BASE_DEC, NULL, 0x0,
"Octet String Length", HFILL }},
{ &hf_oid_sub,
{ "Number subids", "agentx.n_subid", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_oid_prefix,
{ "OID prefix", "agentx.oid_prefix", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_oid_include,
{ "OID include", "agentx.oid_include", FT_BOOLEAN, 8, TFS(&tfs_agentx_include),
OID_IS_INCLUSIVE, NULL, HFILL }},
{ &hf_oid_str,
{ "OID", "agentx.oid", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_resp_uptime,
{ "sysUpTime", "agentx.r.uptime", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_resp_error,
{ "Resp. error", "agentx.r.error", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &resp_errors_ext, 0x0,
"response error", HFILL }},
{ &hf_resp_index,
{ "Resp. index", "agentx.r.index", FT_UINT16, BASE_DEC, NULL, 0x0,
"response index", HFILL }},
{ &hf_vtag,
{ "Variable type", "agentx.v.tag", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &vtag_values_ext, 0x0,
"vtag", HFILL }},
{ &hf_val32,
{ "Value(32)", "agentx.v.val32", FT_UINT32, BASE_DEC, NULL, 0x0,
"val32", HFILL }},
{ &hf_val64,
{ "Value(64)", "agentx.v.val64", FT_UINT64, BASE_DEC, NULL, 0x0,
"val64", HFILL }},
{ &hf_open_timeout,
{ "Timeout", "agentx.o.timeout", FT_UINT8, BASE_DEC, NULL, 0x0,
"open timeout", HFILL }},
{ &hf_close_reason,
{ "Reason", "agentx.c.reason", FT_UINT8, BASE_DEC, VALS(close_reasons), 0x0,
"close reason", HFILL }},
{ &hf_reg_timeout,
{ "Timeout", "agentx.r.timeout", FT_UINT8, BASE_DEC, NULL, 0x0,
"Register timeout", HFILL }},
{ &hf_reg_prio,
{ "Priority", "agentx.r.priority", FT_UINT8, BASE_DEC, NULL, 0x0,
"Register Priority", HFILL }},
{ &hf_reg_rsid,
{ "Range_subid", "agentx.r.range_subid", FT_UINT8, BASE_DEC, NULL, 0x0,
"Register range_subid", HFILL }},
{ &hf_reg_ubound,
{ "Upper bound", "agentx.r.upper_bound", FT_UINT32, BASE_DEC, NULL, 0x0,
"Register upper bound", HFILL }},
{ &hf_unreg_timeout,
{ "Timeout", "agentx.u.timeout", FT_UINT8, BASE_DEC, NULL, 0x0,
"Unregister timeout", HFILL }},
{ &hf_unreg_prio,
{ "Priority", "agentx.u.priority", FT_UINT8, BASE_DEC, NULL, 0x0,
"Unregister Priority", HFILL }},
{ &hf_unreg_rsid,
{ "Range_subid", "agentx.u.range_subid", FT_UINT8, BASE_DEC, NULL, 0x0,
"Unregister range_subid", HFILL }},
{ &hf_unreg_ubound,
{ "Upper bound", "agentx.u.upper_bound", FT_UINT32, BASE_DEC, NULL, 0x0,
"Register upper bound", HFILL }},
{ &hf_gbulk_nrepeat,
{ "Repeaters", "agentx.gb.nrepeat", FT_UINT16, BASE_DEC, NULL, 0x0,
"getBulk Num. repeaters", HFILL }},
{ &hf_gbulk_mrepeat,
{ "Max Repetition", "agentx.gb.mrepeat", FT_UINT16, BASE_DEC, NULL, 0x0,
"getBulk Max repetition", HFILL }},
};
static gint *ett[] = {
&ett_agentx,
&ett_pdu_hdr,
&ett_get,
&ett_getnext,
&ett_search_range,
&ett_obj_ident,
&ett_response,
&ett_valrep,
&ett_open,
&ett_close,
&ett_register,
&ett_unregister,
&ett_getbulk,
&ett_testset,
&ett_commitset,
&ett_undoset,
&ett_cleanupset,
&ett_notify,
&ett_ping,
&ett_idxalloc,
&ett_idxdalloc,
&ett_addcap,
&ett_remcap,
&ett_flags,
};
module_t *agentx_module;
proto_agentx = proto_register_protocol("AgentX",
"AgentX", "agentx");
proto_register_field_array(proto_agentx, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
agentx_module = prefs_register_protocol(proto_agentx, proto_reg_handoff_agentx);
prefs_register_uint_preference(agentx_module, "tcp.agentx_port",
"AgentX listener TCP Port",
"Set the TCP port for AgentX"
"(if other than the default of 705)",
10, &global_agentx_tcp_port);
}
void
proto_reg_handoff_agentx(void)
{
static gboolean agentx_prefs_initialized = FALSE;
static dissector_handle_t agentx_handle;
static guint agentx_tcp_port;
if(!agentx_prefs_initialized) {
agentx_handle = new_create_dissector_handle(dissect_agentx, proto_agentx);
agentx_prefs_initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", agentx_tcp_port, agentx_handle);
}
agentx_tcp_port = global_agentx_tcp_port;
dissector_add_uint("tcp.port", agentx_tcp_port, agentx_handle);
}
