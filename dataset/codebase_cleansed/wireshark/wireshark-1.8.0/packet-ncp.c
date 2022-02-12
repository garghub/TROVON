static gint
mncp_equal(gconstpointer v, gconstpointer v2)
{
const mncp_rhash_key *val1 = (const mncp_rhash_key*)v;
const mncp_rhash_key *val2 = (const mncp_rhash_key*)v2;
if (val1->conversation == val2->conversation && val1->nwconnection == val2->nwconnection && val1->nwtask == val2->nwtask) {
return 1;
}
return 0;
}
static guint
mncp_hash(gconstpointer v)
{
const mncp_rhash_key *mncp_key = (const mncp_rhash_key*)v;
return GPOINTER_TO_UINT(mncp_key->conversation)+mncp_key->nwconnection+mncp_key->nwtask;
}
static void
mncp_init_protocol(void)
{
if (mncp_rhash)
g_hash_table_destroy(mncp_rhash);
mncp_rhash = g_hash_table_new(mncp_hash, mncp_equal);
}
static void
mncp_postseq_cleanup(void)
{
}
static mncp_rhash_value*
mncp_hash_insert(conversation_t *conversation, guint32 nwconnection, guint8 nwtask, packet_info *pinfo)
{
mncp_rhash_key *key;
mncp_rhash_value *value;
key = se_alloc(sizeof(mncp_rhash_key));
key->conversation = conversation;
key->nwconnection = nwconnection;
key->nwtask = nwtask;
value = se_alloc(sizeof(mncp_rhash_value));
g_hash_table_insert(mncp_rhash, key, value);
if (ncp_echo_conn && nwconnection != 65535) {
expert_add_info_format(pinfo, NULL, PI_RESPONSE_CODE, PI_CHAT, "Detected New Server Session. Connection %d, Task %d", nwconnection, nwtask);
value->session_start_packet_num = pinfo->fd->num;
}
return value;
}
static mncp_rhash_value*
mncp_hash_lookup(conversation_t *conversation, guint32 nwconnection, guint8 nwtask)
{
mncp_rhash_key key;
key.conversation = conversation;
key.nwconnection = nwconnection;
key.nwtask = nwtask;
return g_hash_table_lookup(mncp_rhash, &key);
}
static void
dissect_ncp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean is_tcp)
{
proto_tree *ncp_tree = NULL;
proto_item *ti;
struct ncp_ip_header ncpiph;
struct ncp_ip_rqhdr ncpiphrq;
guint16 ncp_burst_seqno, ncp_ack_seqno;
guint16 flags = 0;
proto_tree *flags_tree = NULL;
int hdr_offset = 0;
int commhdr = 0;
int offset = 0;
gint length_remaining;
tvbuff_t *next_tvb;
guint32 testvar = 0, ncp_burst_command, burst_len, burst_off, burst_file;
guint8 subfunction;
guint32 nw_connection = 0, data_offset;
guint16 data_len = 0;
guint16 missing_fraglist_count = 0;
mncp_rhash_value *request_value = NULL;
conversation_t *conversation;
proto_item *expert_item;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NCP");
col_clear(pinfo->cinfo, COL_INFO);
ncp_hdr = &header;
ti = proto_tree_add_item(tree, proto_ncp, tvb, 0, -1, ENC_NA);
ncp_tree = proto_item_add_subtree(ti, ett_ncp);
if (is_tcp) {
if (tvb_get_ntohl(tvb, hdr_offset) != NCPIP_RQST && tvb_get_ntohl(tvb, hdr_offset) != NCPIP_RPLY)
commhdr += 1;
ncpiph.signature = tvb_get_ntohl(tvb, commhdr);
proto_tree_add_uint(ncp_tree, hf_ncp_ip_sig, tvb, commhdr, 4, ncpiph.signature);
ncpiph.length = (0x7fffffff & tvb_get_ntohl(tvb, commhdr+4));
proto_tree_add_uint(ncp_tree, hf_ncp_ip_length, tvb, commhdr+4, 4, ncpiph.length);
commhdr += 8;
if (ncpiph.signature == NCPIP_RQST) {
ncpiphrq.version = tvb_get_ntohl(tvb, commhdr);
proto_tree_add_uint(ncp_tree, hf_ncp_ip_ver, tvb, commhdr, 4, ncpiphrq.version);
commhdr += 4;
ncpiphrq.rplybufsize = tvb_get_ntohl(tvb, commhdr);
proto_tree_add_uint(ncp_tree, hf_ncp_ip_rplybufsize, tvb, commhdr, 4, ncpiphrq.rplybufsize);
commhdr += 4;
}
if (match_strval(tvb_get_ntohs(tvb, commhdr), ncp_type_vals)==NULL) {
if (match_strval(tvb_get_ntohs(tvb, commhdr+8), ncp_type_vals)!=NULL) {
proto_tree_add_item(ncp_tree, hf_ncp_ip_packetsig, tvb, commhdr, 8, ENC_NA);
commhdr += 8;
}
}
} else {
memset(&ncpiph, 0, sizeof(ncpiph));
}
header.type = tvb_get_ntohs(tvb, commhdr);
header.sequence = tvb_get_guint8(tvb, commhdr+2);
header.conn_low = tvb_get_guint8(tvb, commhdr+3);
header.task = tvb_get_guint8(tvb, commhdr+4);
header.conn_high = tvb_get_guint8(tvb, commhdr+5);
proto_tree_add_uint(ncp_tree, hf_ncp_type, tvb, commhdr, 2, header.type);
nw_connection = (header.conn_high*256)+header.conn_low;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_NCP, (guint32) pinfo->srcport, (guint32) pinfo->destport,
0);
if ((ncpiph.length & 0x80000000) || ncpiph.signature == NCPIP_RPLY) {
if (!pinfo->fd->flags.visited) {
if (conversation != NULL) {
request_value = mncp_hash_lookup(conversation, nw_connection, header.task);
if (request_value == NULL) {
mncp_hash_insert(conversation, nw_connection, header.task, pinfo);
}
} else {
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
&pinfo->dst, PT_NCP, (guint32) pinfo->srcport, (guint32) pinfo->destport, 0);
mncp_hash_insert(conversation, nw_connection, header.task, pinfo);
}
if (ncpiph.signature == NCPIP_RPLY) {
request_value = mncp_hash_lookup(conversation, nw_connection, header.task);
}
} else {
request_value = mncp_hash_lookup(conversation, nw_connection, header.task);
if (request_value) {
if ((request_value->session_start_packet_num == pinfo->fd->num) && ncp_echo_conn)
{
expert_add_info_format(pinfo, NULL, PI_RESPONSE_CODE, PI_CHAT, "Detected New Server Session. Connection %d, Task %d", nw_connection, header.task);
}
}
}
} else {
if (!pinfo->fd->flags.visited) {
if (conversation != NULL) {
request_value = mncp_hash_lookup(conversation, nw_connection, header.task);
if (request_value == NULL) {
mncp_hash_insert(conversation, nw_connection, header.task, pinfo);
}
} else {
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
&pinfo->dst, PT_NCP, (guint32) pinfo->srcport, (guint32) pinfo->destport, 0);
mncp_hash_insert(conversation, nw_connection, header.task, pinfo);
}
} else {
request_value = mncp_hash_lookup(conversation, nw_connection, header.task);
if (request_value) {
if ((request_value->session_start_packet_num == pinfo->fd->num) && ncp_echo_conn)
{
expert_add_info_format(pinfo, NULL, PI_RESPONSE_CODE, PI_CHAT, "Detected New Server Session. Connection %d, Task %d", nw_connection, header.task);
}
}
}
}
tap_queue_packet(ncp_tap.hdr, pinfo, ncp_hdr);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(header.type, ncp_type_vals, "Unknown type (0x%04x)"));
}
switch (header.type) {
case NCP_BROADCAST_SLOT:
proto_tree_add_uint(ncp_tree, hf_ncp_seq, tvb, commhdr + 2, 1, header.sequence);
proto_tree_add_uint(ncp_tree, hf_ncp_connection,tvb, commhdr + 3, 3, nw_connection);
proto_tree_add_item(ncp_tree, hf_ncp_task, tvb, commhdr + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_oplock_flag, tvb, commhdr + 9, 1, tvb_get_guint8(tvb, commhdr+9));
proto_tree_add_item(ncp_tree, hf_ncp_oplock_handle, tvb, commhdr + 10, 4, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, commhdr+9)==0x24) && ncp_echo_file)
{
expert_add_info_format(pinfo, NULL, PI_RESPONSE_CODE, PI_CHAT, "Server requesting station to clear oplock on handle - %08x", tvb_get_ntohl(tvb, commhdr+10));
}
break;
case NCP_LIP_ECHO:
proto_tree_add_item(ncp_tree, hf_lip_echo, tvb, commhdr, 13, ENC_ASCII|ENC_NA);
break;
case NCP_BURST_MODE_XFER:
flags = tvb_get_guint8(tvb, commhdr + 2);
ti = proto_tree_add_uint(ncp_tree, hf_ncp_system_flags,
tvb, commhdr + 2, 1, flags);
flags_tree = proto_item_add_subtree(ti, ett_ncp_system_flags);
proto_tree_add_item(flags_tree, hf_ncp_system_flags_abt,
tvb, commhdr + 2, 1, ENC_BIG_ENDIAN);
if (flags & ABT) {
proto_item_append_text(ti, " ABT");
}
flags&=(~( ABT ));
proto_tree_add_item(flags_tree, hf_ncp_system_flags_bsy,
tvb, commhdr + 2, 1, ENC_BIG_ENDIAN);
if (flags & BSY) {
proto_item_append_text(ti, " BSY");
}
flags&=(~( BSY ));
proto_tree_add_item(flags_tree, hf_ncp_system_flags_eob,
tvb, commhdr + 2, 1, ENC_BIG_ENDIAN);
if (flags & EOB) {
proto_item_append_text(ti, " EOB");
}
flags&=(~( EOB ));
proto_tree_add_item(flags_tree, hf_ncp_system_flags_lst,
tvb, commhdr + 2, 1, ENC_BIG_ENDIAN);
if (flags & LST) {
proto_item_append_text(ti, " LST");
}
flags&=(~( LST ));
proto_tree_add_item(flags_tree, hf_ncp_system_flags_sys,
tvb, commhdr + 2, 1, ENC_BIG_ENDIAN);
if (flags & SYS) {
proto_item_append_text(ti, " SYS");
}
flags&=(~( SYS ));
proto_tree_add_item(ncp_tree, hf_ncp_stream_type,
tvb, commhdr + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_src_connection,
tvb, commhdr + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_dst_connection,
tvb, commhdr + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_packet_seqno,
tvb, commhdr + 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_delay_time,
tvb, commhdr + 16, 4, ENC_BIG_ENDIAN);
ncp_burst_seqno = tvb_get_ntohs(tvb, commhdr+20);
proto_tree_add_item(ncp_tree, hf_ncp_burst_seqno,
tvb, commhdr + 20, 2, ENC_BIG_ENDIAN);
ncp_ack_seqno = tvb_get_ntohs(tvb, commhdr+22);
proto_tree_add_item(ncp_tree, hf_ncp_ack_seqno,
tvb, commhdr + 22, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_burst_len,
tvb, commhdr + 24, 4, ENC_BIG_ENDIAN);
data_offset = tvb_get_ntohl(tvb, commhdr + 28);
proto_tree_add_uint(ncp_tree, hf_ncp_data_offset,
tvb, commhdr + 28, 4, data_offset);
data_len = tvb_get_ntohs(tvb, commhdr + 32);
proto_tree_add_uint(ncp_tree, hf_ncp_data_bytes,
tvb, commhdr + 32, 2, data_len);
missing_fraglist_count = tvb_get_ntohs(tvb, commhdr + 34);
proto_tree_add_item(ncp_tree, hf_ncp_missing_fraglist_count,
tvb, commhdr + 34, 2, ENC_BIG_ENDIAN);
offset = commhdr + 36;
if (!(flags & SYS) && ncp_burst_seqno == ncp_ack_seqno &&
data_offset == 0) {
if (data_len < 4)
return;
ncp_burst_command = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(ncp_tree, hf_ncp_burst_command,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
data_len -= 4;
if (data_len < 4)
return;
burst_file = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(ncp_tree, hf_ncp_burst_file_handle,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
data_len -= 4;
if (data_len < 8)
return;
proto_tree_add_item(ncp_tree, hf_ncp_burst_reserved,
tvb, offset, 8, ENC_NA);
offset += 8;
data_len -= 8;
if (data_len < 4)
return;
burst_off = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(ncp_tree, hf_ncp_burst_offset,
tvb, offset, 4, burst_off);
offset += 4;
data_len -= 4;
if (data_len < 4)
return;
burst_len = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(ncp_tree, hf_ncp_burst_len,
tvb, offset, 4, burst_len);
offset += 4;
data_len -= 4;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s %d bytes starting at offset %d in file 0x%08x",
val_to_str(ncp_burst_command,
burst_command, "Unknown (0x%08x)"),
burst_len, burst_off, burst_file);
}
break;
} else {
if (tvb_get_guint8(tvb, commhdr + 2) & 0x10) {
col_set_str(pinfo->cinfo, COL_INFO, "End of Burst");
}
}
break;
case NCP_ALLOCATE_SLOT:
length_remaining = tvb_length_remaining(tvb, commhdr + 4);
if (length_remaining > 4) {
testvar = tvb_get_ntohl(tvb, commhdr+4);
if (testvar == 0x4c495020) {
proto_tree_add_item(ncp_tree, hf_lip_echo, tvb, commhdr+4, 13, ENC_ASCII|ENC_NA);
break;
}
}
case NCP_POSITIVE_ACK:
case NCP_SERVICE_REQUEST:
case NCP_SERVICE_REPLY:
case NCP_WATCHDOG:
case NCP_DEALLOCATE_SLOT:
default:
proto_tree_add_uint(ncp_tree, hf_ncp_seq, tvb, commhdr + 2, 1, header.sequence);
proto_tree_add_uint(ncp_tree, hf_ncp_connection,tvb, commhdr + 3, 3, nw_connection);
proto_tree_add_item(ncp_tree, hf_ncp_task, tvb, commhdr + 4, 1, ENC_BIG_ENDIAN);
break;
}
switch (header.type) {
case NCP_ALLOCATE_SLOT:
length_remaining = tvb_length_remaining(tvb, commhdr + 4);
if (length_remaining > 4) {
testvar = tvb_get_ntohl(tvb, commhdr+4);
if (testvar == 0x4c495020) {
proto_tree_add_text(ncp_tree, tvb, commhdr, -1,
"Lip Echo Packet");
}
}
next_tvb = tvb_new_subset_remaining(tvb, commhdr);
dissect_ncp_request(next_tvb, pinfo, nw_connection,
header.sequence, header.type, ncp_tree);
break;
case NCP_DEALLOCATE_SLOT:
next_tvb = tvb_new_subset_remaining(tvb, commhdr);
dissect_ncp_request(next_tvb, pinfo, nw_connection,
header.sequence, header.type, ncp_tree);
break;
case NCP_SERVICE_REQUEST:
case NCP_BROADCAST_SLOT:
next_tvb = tvb_new_subset_remaining(tvb, commhdr);
if (tvb_get_guint8(tvb, commhdr+6) == 0x68) {
subfunction = tvb_get_guint8(tvb, commhdr+7);
switch (subfunction) {
case 0x02:
dissect_nds_request(next_tvb, pinfo,
nw_connection, header.sequence,
header.type, ncp_tree);
break;
case 0x01:
dissect_ping_req(next_tvb, pinfo,
nw_connection, header.sequence,
header.type, ncp_tree);
break;
default:
dissect_ncp_request(next_tvb, pinfo,
nw_connection, header.sequence,
header.type, ncp_tree);
break;
}
} else {
dissect_ncp_request(next_tvb, pinfo, nw_connection,
header.sequence, header.type, ncp_tree);
}
break;
case NCP_SERVICE_REPLY:
next_tvb = tvb_new_subset_remaining(tvb, commhdr);
nds_defrag(next_tvb, pinfo, nw_connection, header.sequence,
header.type, ncp_tree, &ncp_tap);
break;
case NCP_POSITIVE_ACK:
next_tvb = tvb_new_subset_remaining(tvb, commhdr);
dissect_ncp_reply(next_tvb, pinfo, nw_connection,
header.sequence, header.type, ncp_tree, &ncp_tap);
break;
case NCP_WATCHDOG:
proto_tree_add_item(ncp_tree, hf_ncp_completion_code,
tvb, commhdr + 6, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_connection_status,
tvb, commhdr + 7, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_slot,
tvb, commhdr + 8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ncp_tree, hf_ncp_control_code,
tvb, commhdr + 9, 1, ENC_LITTLE_ENDIAN);
if (tvb_offset_exists(tvb, commhdr + 10)) {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, commhdr + 10),
pinfo, ncp_tree);
}
break;
case NCP_BURST_MODE_XFER:
if (flags & SYS) {
while (missing_fraglist_count != 0) {
proto_tree_add_item(ncp_tree, hf_ncp_missing_data_offset,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ncp_tree, hf_ncp_missing_data_count,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
missing_fraglist_count--;
}
} else {
length_remaining = tvb_length_remaining(tvb, offset);
if (length_remaining > data_len)
length_remaining = data_len;
if (data_len != 0) {
call_dissector(data_handle,
tvb_new_subset(tvb, offset,
length_remaining, data_len),
pinfo, ncp_tree);
}
}
break;
case NCP_LIP_ECHO:
proto_tree_add_text(ncp_tree, tvb, commhdr, -1,
"Lip Echo Packet");
break;
default:
expert_item = proto_tree_add_text(ncp_tree, tvb, commhdr + 6, -1,
"%s packets not supported yet",
val_to_str(header.type, ncp_type_vals,
"Unknown type (0x%04x)"));
if (ncp_echo_err) {
expert_add_info_format(pinfo, expert_item, PI_UNDECODED, PI_NOTE, "%s packets not supported yet", val_to_str(header.type, ncp_type_vals,
"Unknown type (0x%04x)"));
}
break;
}
}
static void
dissect_ncp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_ncp_common(tvb, pinfo, tree, FALSE);
}
static guint
get_ncp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 signature;
signature = tvb_get_ntohl(tvb, offset);
if (signature != NCPIP_RQST && signature != NCPIP_RPLY)
return tvb_length_remaining(tvb, offset);
return tvb_get_ntohl(tvb, offset + 4) & 0x7fffffff;
}
static void
dissect_ncp_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_ncp_common(tvb, pinfo, tree, TRUE);
}
static void
dissect_ncp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, ncp_desegment, 8, get_ncp_pdu_len,
dissect_ncp_tcp_pdu);
}
void
proto_register_ncp(void)
{
static hf_register_info hf[] = {
{ &hf_ncp_ip_sig,
{ "NCP over IP signature", "ncp.ip.signature",
FT_UINT32, BASE_HEX, VALS(ncp_ip_signature), 0x0,
NULL, HFILL }},
{ &hf_ncp_ip_length,
{ "NCP over IP length", "ncp.ip.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_ip_ver,
{ "NCP over IP Version", "ncp.ip.version",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_ip_rplybufsize,
{ "NCP over IP Reply Buffer Size", "ncp.ip.replybufsize",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_ip_packetsig,
{ "NCP over IP Packet Signature", "ncp.ip.packetsig",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_type,
{ "Type", "ncp.type",
FT_UINT16, BASE_HEX, VALS(ncp_type_vals), 0x0,
"NCP message type", HFILL }},
{ &hf_ncp_seq,
{ "Sequence Number", "ncp.seq",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_connection,
{ "Connection Number", "ncp.connection",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_task,
{ "Task Number", "ncp.task",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_oplock_flag,
{ "Broadcast Message Flag", "ncp.msg_flag",
FT_UINT8, BASE_HEX, VALS(ncp_oplock_vals), 0x0,
NULL, HFILL }},
{ &hf_ncp_oplock_handle,
{ "File Handle", "ncp.oplock_handle",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_stream_type,
{ "Stream Type", "ncp.stream_type",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Type of burst", HFILL }},
{ &hf_ncp_system_flags,
{ "System Flags", "ncp.system_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_system_flags_abt,
{ "ABT", "ncp.system_flags.abt",
FT_BOOLEAN, 8, NULL, ABT,
"Is this an abort request?", HFILL }},
{ &hf_ncp_system_flags_eob,
{ "EOB", "ncp.system_flags.eob",
FT_BOOLEAN, 8, NULL, EOB,
"Is this the last packet of the burst?", HFILL }},
{ &hf_ncp_system_flags_sys,
{ "SYS", "ncp.system_flags.sys",
FT_BOOLEAN, 8, NULL, SYS,
"Is this a system packet?", HFILL }},
{ &hf_ncp_system_flags_bsy,
{ "BSY", "ncp.system_flags.bsy",
FT_BOOLEAN, 8, NULL, BSY,
"Is the server busy?", HFILL }},
{ &hf_ncp_system_flags_lst,
{ "LST", "ncp.system_flags.lst",
FT_BOOLEAN, 8, NULL, LST,
"Return Fragment List?", HFILL }},
{ &hf_ncp_src_connection,
{ "Source Connection ID", "ncp.src_connection",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The workstation's connection identification number", HFILL }},
{ &hf_ncp_dst_connection,
{ "Destination Connection ID", "ncp.dst_connection",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The server's connection identification number", HFILL }},
{ &hf_ncp_packet_seqno,
{ "Packet Sequence Number", "ncp.packet_seqno",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Sequence number of this packet in a burst", HFILL }},
{ &hf_ncp_delay_time,
{ "Delay Time", "ncp.delay_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Delay time between consecutive packet sends (100 us increments)", HFILL }},
{ &hf_ncp_burst_seqno,
{ "Burst Sequence Number", "ncp.burst_seqno",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Sequence number of this packet in the burst", HFILL }},
{ &hf_ncp_ack_seqno,
{ "ACK Sequence Number", "ncp.ack_seqno",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Next expected burst sequence number", HFILL }},
{ &hf_ncp_burst_len,
{ "Burst Length", "ncp.burst_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total length of data in this burst", HFILL }},
{ &hf_ncp_burst_offset,
{ "Burst Offset", "ncp.burst_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Offset of data in the burst", HFILL }},
{ &hf_ncp_data_offset,
{ "Data Offset", "ncp.data_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Offset of this packet", HFILL }},
{ &hf_ncp_data_bytes,
{ "Data Bytes", "ncp.data_bytes",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of data bytes in this packet", HFILL }},
{ &hf_ncp_missing_fraglist_count,
{ "Missing Fragment List Count", "ncp.missing_fraglist_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of missing fragments reported", HFILL }},
{ &hf_ncp_missing_data_offset,
{ "Missing Data Offset", "ncp.missing_data_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Offset of beginning of missing data", HFILL }},
{ &hf_ncp_missing_data_count,
{ "Missing Data Count", "ncp.missing_data_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of bytes of missing data", HFILL }},
{ &hf_ncp_completion_code,
{ "Completion Code", "ncp.completion_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_connection_status,
{ "Connection Status", "ncp.connection_status",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_slot,
{ "Slot", "ncp.slot",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_control_code,
{ "Control Code", "ncp.control_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_fragment_handle,
{ "Fragment Handle", "ncp.fragger_hndl",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_lip_echo,
{ "Large Internet Packet Echo", "ncp.lip_echo",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ncp_burst_command,
{ "Burst Command", "ncp.burst_command",
FT_UINT32, BASE_HEX, VALS(burst_command), 0x0,
"Packet Burst Command", HFILL }},
{ &hf_ncp_burst_file_handle,
{ "Burst File Handle", "ncp.file_handle",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Packet Burst File Handle", HFILL }},
{ &hf_ncp_burst_reserved,
{ "Reserved", "ncp.burst_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_ncp,
&ett_ncp_system_flags,
&ett_nds,
&ett_nds_segments,
&ett_nds_segment,
};
module_t *ncp_module;
proto_ncp = proto_register_protocol("NetWare Core Protocol", "NCP", "ncp");
proto_register_field_array(proto_ncp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ncp_module = prefs_register_protocol(proto_ncp, NULL);
prefs_register_obsolete_preference(ncp_module, "initial_hash_size");
prefs_register_bool_preference(ncp_module, "desegment",
"Reassemble NCP-over-TCP messages spanning multiple TCP segments",
"Whether the NCP dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ncp_desegment);
prefs_register_bool_preference(ncp_module, "defragment_nds",
"Reassemble fragmented NDS messages spanning multiple reply packets",
"Whether the NCP dissector should defragment NDS messages spanning multiple reply packets.",
&nds_defragment);
prefs_register_bool_preference(ncp_module, "newstyle",
"Dissect New Netware Information Structure",
"Dissect the NetWare Information Structure as NetWare 5.x or higher or as older NetWare 3.x.",
&ncp_newstyle);
prefs_register_bool_preference(ncp_module, "eid_2_expert",
"Expert: EID to Name lookups?",
"Whether the NCP dissector should echo the NDS Entry ID to name resolves to the expert table.",
&nds_echo_eid);
prefs_register_bool_preference(ncp_module, "connection_2_expert",
"Expert: NCP Connections?",
"Whether the NCP dissector should echo NCP connection information to the expert table.",
&ncp_echo_conn);
prefs_register_bool_preference(ncp_module, "error_2_expert",
"Expert: NCP Errors?",
"Whether the NCP dissector should echo protocol errors to the expert table.",
&ncp_echo_err);
prefs_register_bool_preference(ncp_module, "server_2_expert",
"Expert: Server Information?",
"Whether the NCP dissector should echo server information to the expert table.",
&ncp_echo_server);
prefs_register_bool_preference(ncp_module, "file_2_expert",
"Expert: File Information?",
"Whether the NCP dissector should echo file open/close/oplock information to the expert table.",
&ncp_echo_file);
register_init_routine(&mncp_init_protocol);
ncp_tap.stat=register_tap("ncp_srt");
ncp_tap.hdr=register_tap("ncp_hdr");
register_postseq_cleanup_routine(&mncp_postseq_cleanup);
}
void
proto_reg_handoff_ncp(void)
{
dissector_handle_t ncp_handle;
dissector_handle_t ncp_tcp_handle;
ncp_handle = create_dissector_handle(dissect_ncp, proto_ncp);
ncp_tcp_handle = create_dissector_handle(dissect_ncp_tcp, proto_ncp);
dissector_add_uint("tcp.port", TCP_PORT_NCP, ncp_tcp_handle);
dissector_add_uint("udp.port", UDP_PORT_NCP, ncp_handle);
dissector_add_uint("ipx.packet_type", IPX_PACKET_TYPE_NCP, ncp_handle);
dissector_add_uint("ipx.socket", IPX_SOCKET_NCP, ncp_handle);
data_handle = find_dissector("data");
}
