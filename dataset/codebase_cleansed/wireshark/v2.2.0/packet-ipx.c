static const char* ipx_conv_get_filter_type(conv_item_t* conv, conv_filter_type_e filter)
{
if ((filter == CONV_FT_SRC_ADDRESS) && (conv->src_address.type == AT_IPX))
return "ipx.src";
if ((filter == CONV_FT_DST_ADDRESS) && (conv->dst_address.type == AT_IPX))
return "ipx.dst";
if ((filter == CONV_FT_ANY_ADDRESS) && (conv->src_address.type == AT_IPX))
return "ipx.addr";
return CONV_FILTER_INVALID;
}
static int
ipx_conversation_packet(void *pct, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pct;
const ipxhdr_t *ipxh=(const ipxhdr_t *)vip;
add_conversation_table_data(hash, &ipxh->ipx_src, &ipxh->ipx_dst, 0, 0, 1, pinfo->fd->pkt_len, &pinfo->rel_ts, &pinfo->abs_ts, &ipx_ct_dissector_info, PT_NONE);
return 1;
}
static const char* ipx_host_get_filter_type(hostlist_talker_t* host, conv_filter_type_e filter)
{
if ((filter == CONV_FT_ANY_ADDRESS) && (host->myaddress.type == AT_IPX))
return "ipx.addr";
return CONV_FILTER_INVALID;
}
static int
ipx_hostlist_packet(void *pit, packet_info *pinfo, epan_dissect_t *edt _U_, const void *vip)
{
conv_hash_t *hash = (conv_hash_t*) pit;
const ipxhdr_t *ipxh=(const ipxhdr_t *)vip;
add_hostlist_table_data(hash, &ipxh->ipx_src, 0, TRUE, 1, pinfo->fd->pkt_len, &ipx_host_dissector_info, PT_NONE);
add_hostlist_table_data(hash, &ipxh->ipx_dst, 0, FALSE, 1, pinfo->fd->pkt_len, &ipx_host_dissector_info, PT_NONE);
return 1;
}
gboolean
capture_ipx(const guchar *pd _U_, int offset _U_, int len _U_, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
capture_dissector_increment_count(cpinfo, proto_ipx);
return TRUE;
}
static int
dissect_ipx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t *next_tvb;
proto_tree *ipx_tree = NULL;
proto_item *ti = NULL, *hidden_item;
guint8 ipx_hops;
char *str;
guint16 first_socket, second_socket;
guint32 ipx_snet, ipx_dnet;
static ipxhdr_t ipxh_arr[4];
static int ipx_current=0;
ipxhdr_t *ipxh;
ipx_current++;
if(ipx_current==4){
ipx_current=0;
}
ipxh=&ipxh_arr[ipx_current];
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPX");
col_clear(pinfo->cinfo, COL_INFO);
ipxh->ipx_dsocket = tvb_get_ntohs(tvb, 16);
ipxh->ipx_ssocket = tvb_get_ntohs(tvb, 28);
ipxh->ipx_type = tvb_get_guint8(tvb, 5);
ipxh->ipx_length = tvb_get_ntohs(tvb, 2);
pinfo->ptype = PT_IPX;
pinfo->srcport = ipxh->ipx_ssocket;
pinfo->destport = ipxh->ipx_dsocket;
set_actual_length(tvb, ipxh->ipx_length);
set_address_tvb(&pinfo->net_src, AT_IPX, 10, tvb, 18);
copy_address_shallow(&pinfo->src, &pinfo->net_src);
copy_address_shallow(&ipxh->ipx_src, &pinfo->net_src);
set_address_tvb(&pinfo->net_dst, AT_IPX, 10, tvb, 6);
copy_address_shallow(&pinfo->dst, &pinfo->net_dst);
copy_address_shallow(&ipxh->ipx_dst, &pinfo->net_dst);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str_ext(ipxh->ipx_dsocket, &ipx_socket_vals_ext, "Unknown (0x%04x)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_ipx, tvb, 0, IPX_HEADER_LEN, ENC_NA);
ipx_tree = proto_item_add_subtree(ti, ett_ipx);
}
str=address_to_str(wmem_packet_scope(), &pinfo->net_src);
hidden_item = proto_tree_add_string(ipx_tree, hf_ipx_src, tvb, 0, 0, str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string(ipx_tree, hf_ipx_addr, tvb, 0, 0, str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
str=address_to_str(wmem_packet_scope(), &pinfo->net_dst);
hidden_item = proto_tree_add_string(ipx_tree, hf_ipx_dst, tvb, 0, 0, str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string(ipx_tree, hf_ipx_addr, tvb, 0, 0, str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_checksum(ipx_tree, tvb, 0, hf_ipx_checksum, -1, NULL, pinfo, 0, ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
proto_tree_add_uint_format_value(ipx_tree, hf_ipx_len, tvb, 2, 2, ipxh->ipx_length,
"%d bytes", ipxh->ipx_length);
ipx_hops = tvb_get_guint8(tvb, 4);
proto_tree_add_uint_format(ipx_tree, hf_ipx_hops, tvb, 4, 1, ipx_hops,
"Transport Control: %d hops", ipx_hops);
proto_tree_add_uint(ipx_tree, hf_ipx_packet_type, tvb, 5, 1, ipxh->ipx_type);
ipx_dnet = tvb_get_ntohl(tvb, 6);
proto_tree_add_ipxnet(ipx_tree, hf_ipx_dnet, tvb, 6, 4,
ipx_dnet);
hidden_item = proto_tree_add_ipxnet(ipx_tree, hf_ipx_net, tvb, 6, 4,
ipx_dnet);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(ipx_tree, hf_ipx_dnode, tvb, 10, 6, ENC_NA);
hidden_item = proto_tree_add_item(ipx_tree, hf_ipx_node, tvb, 10, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint(ipx_tree, hf_ipx_dsocket, tvb, 16, 2,
ipxh->ipx_dsocket);
hidden_item = proto_tree_add_uint(ipx_tree, hf_ipx_socket, tvb, 16, 2,
ipxh->ipx_dsocket);
PROTO_ITEM_SET_HIDDEN(hidden_item);
ipx_snet = tvb_get_ntohl(tvb, 18);
proto_tree_add_ipxnet(ipx_tree, hf_ipx_snet, tvb, 18, 4,
ipx_snet);
hidden_item = proto_tree_add_ipxnet(ipx_tree, hf_ipx_net, tvb, 18, 4,
ipx_snet);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(ipx_tree, hf_ipx_snode, tvb, 22, 6, ENC_NA);
hidden_item = proto_tree_add_item(ipx_tree, hf_ipx_node, tvb, 22, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint(ipx_tree, hf_ipx_ssocket, tvb, 28, 2,
ipxh->ipx_ssocket);
hidden_item = proto_tree_add_uint(ipx_tree, hf_ipx_socket, tvb, 28, 2,
ipxh->ipx_ssocket);
PROTO_ITEM_SET_HIDDEN(hidden_item);
next_tvb = tvb_new_subset_remaining(tvb, IPX_HEADER_LEN);
if (ipxh->ipx_ssocket > ipxh->ipx_dsocket) {
first_socket = ipxh->ipx_dsocket;
second_socket = ipxh->ipx_ssocket;
} else {
first_socket = ipxh->ipx_ssocket;
second_socket = ipxh->ipx_dsocket;
}
tap_queue_packet(ipx_tap, pinfo, ipxh);
if (second_socket != IPX_SOCKET_NWLINK_SMB_NAMEQUERY) {
if (dissector_try_uint_new(ipx_socket_dissector_table, first_socket,
next_tvb, pinfo, tree, FALSE, ipxh))
return tvb_captured_length(tvb);
}
if (dissector_try_uint_new(ipx_socket_dissector_table, second_socket,
next_tvb, pinfo, tree, FALSE, ipxh))
return tvb_captured_length(tvb);
if (dissector_try_uint_new(ipx_type_dissector_table, ipxh->ipx_type, next_tvb,
pinfo, tree, FALSE, ipxh))
return tvb_captured_length(tvb);
call_data_dissector(next_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static gint
spx_equal(gconstpointer v, gconstpointer v2)
{
const spx_hash_key *val1 = (const spx_hash_key*)v;
const spx_hash_key *val2 = (const spx_hash_key*)v2;
if (val1->conversation == val2->conversation &&
val1->spx_src == val2->spx_src &&
val1->spx_seq == val2->spx_seq) {
return 1;
}
return 0;
}
static guint
spx_hash_func(gconstpointer v)
{
const spx_hash_key *spx_key = (const spx_hash_key*)v;
return GPOINTER_TO_UINT(spx_key->conversation) + spx_key->spx_src;
}
static void
spx_init_protocol(void)
{
spx_hash = g_hash_table_new(spx_hash_func, spx_equal);
}
static void
spx_postseq_cleanup(void)
{
if (spx_hash) {
g_hash_table_destroy(spx_hash);
spx_hash = NULL;
}
}
static spx_hash_value*
spx_hash_insert(conversation_t *conversation, guint32 spx_src, guint16 spx_seq)
{
spx_hash_key *key;
spx_hash_value *value;
key = wmem_new(wmem_file_scope(), spx_hash_key);
key->conversation = conversation;
key->spx_src = spx_src;
key->spx_seq = spx_seq;
value = wmem_new0(wmem_file_scope(), spx_hash_value);
g_hash_table_insert(spx_hash, key, value);
return value;
}
static spx_hash_value*
spx_hash_lookup(conversation_t *conversation, guint32 spx_src, guint32 spx_seq)
{
spx_hash_key key;
key.conversation = conversation;
key.spx_src = spx_src;
key.spx_seq = spx_seq;
return (spx_hash_value *)g_hash_table_lookup(spx_hash, &key);
}
static const char*
spx_datastream(guint8 type)
{
switch (type) {
case 0xfe:
return "End-of-Connection";
case 0xff:
return "End-of-Connection Acknowledgment";
default:
return NULL;
}
}
static int
dissect_spx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *spx_tree;
proto_item *ti;
tvbuff_t *next_tvb;
guint8 conn_ctrl;
guint8 hdr_len = SPX_HEADER_LEN;
guint8 datastream_type;
const char *datastream_type_string;
guint16 spx_seq;
const char *spx_msg_string;
guint16 low_socket, high_socket;
guint32 src;
conversation_t *conversation;
spx_hash_value *pkt_value;
spx_rexmit_info *spx_rexmit_info_p;
spx_info spx_infox;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SPX");
col_set_str(pinfo->cinfo, COL_INFO, "SPX");
conn_ctrl = tvb_get_guint8(tvb, 0);
if ((conn_ctrl & SPX_VII_PACKET) && tvb_get_ntohs(tvb, 4) != 0xffff) {
hdr_len = SPX2_HEADER_LEN;
}
ti = proto_tree_add_item(tree, proto_spx, tvb, 0, hdr_len, ENC_NA);
spx_tree = proto_item_add_subtree(ti, ett_spx);
spx_msg_string = val_to_str_const((conn_ctrl & 0xf0), conn_vals, "Unknown" );
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", spx_msg_string);
if (tree) {
const int * spx_flags[] = {
&hf_spx_connection_control_sys,
&hf_spx_connection_control_send_ack,
&hf_spx_connection_control_attn,
&hf_spx_connection_control_eom,
NULL
};
const int * spx_vii_flags[] = {
&hf_spx_connection_control_sys,
&hf_spx_connection_control_send_ack,
&hf_spx_connection_control_attn,
&hf_spx_connection_control_eom,
&hf_spx_connection_control_v2,
&hf_spx_connection_control_neg_size,
&hf_spx_connection_control_reserved,
&hf_spx_connection_control_ext_header,
NULL
};
if (conn_ctrl & SPX_VII_PACKET) {
proto_tree_add_bitmask_with_flags(spx_tree, tvb, 0, hf_spx_connection_control,
ett_spx_connctrl, spx_vii_flags, ENC_NA, BMT_NO_APPEND);
} else {
proto_tree_add_bitmask_with_flags(spx_tree, tvb, 0, hf_spx_connection_control,
ett_spx_connctrl, spx_flags, ENC_NA, BMT_NO_APPEND);
}
}
datastream_type = tvb_get_guint8(tvb, 1);
datastream_type_string = spx_datastream(datastream_type);
if (datastream_type_string != NULL) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
datastream_type_string);
}
if (tree) {
if (datastream_type_string != NULL) {
proto_tree_add_uint_format_value(spx_tree, hf_spx_datastream_type, tvb,
1, 1, datastream_type,
"%s (0x%02X)",
datastream_type_string,
datastream_type);
} else {
proto_tree_add_uint_format_value(spx_tree, hf_spx_datastream_type, tvb,
1, 1, datastream_type,
"0x%02X",
datastream_type);
}
proto_tree_add_item(spx_tree, hf_spx_src_id, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(spx_tree, hf_spx_dst_id, tvb, 4, 2, ENC_BIG_ENDIAN);
}
spx_seq = tvb_get_ntohs(tvb, 6);
if (tree) {
proto_tree_add_uint(spx_tree, hf_spx_seq_nr, tvb, 6, 2, spx_seq);
proto_tree_add_item(spx_tree, hf_spx_ack_nr, tvb, 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(spx_tree, hf_spx_all_nr, tvb, 10, 2, ENC_BIG_ENDIAN);
if ((conn_ctrl & SPX_VII_PACKET) && tvb_get_ntohs(tvb, 4) != 0xffff) {
proto_tree_add_item(spx_tree, hf_spx_neg_size, tvb, 12, 2, ENC_BIG_ENDIAN);
}
}
if (conn_ctrl & SPX_SYS_PACKET) {
spx_rexmit_info_p = NULL;
} else {
if (!pinfo->fd->flags.visited) {
conversation = find_conversation(pinfo->num, &pinfo->src,
&pinfo->dst, PT_NCP, pinfo->srcport,
pinfo->srcport, 0);
if (conversation == NULL) {
conversation = conversation_new(pinfo->num, &pinfo->src,
&pinfo->dst, PT_NCP, pinfo->srcport,
pinfo->srcport, 0);
}
src = tvb_get_ntohs(tvb, 0)+tvb_get_ntohs(tvb, 2)+tvb_get_ntohs(tvb, 4)+tvb_get_ntohs(tvb, 6)+tvb_get_ntohs(tvb, 8);
pkt_value = spx_hash_lookup(conversation, src, spx_seq);
if (pkt_value == NULL) {
pkt_value = spx_hash_insert(conversation, src,
spx_seq);
pkt_value->spx_ack = tvb_get_ntohs(tvb, 8);
pkt_value->spx_all = tvb_get_ntohs(tvb, 10);
pkt_value->num = pinfo->num;
spx_rexmit_info_p = NULL;
} else {
spx_rexmit_info_p = wmem_new(wmem_file_scope(), spx_rexmit_info);
spx_rexmit_info_p->num = pkt_value->num;
p_add_proto_data(wmem_file_scope(), pinfo, proto_spx, 0,
spx_rexmit_info_p);
}
} else {
spx_rexmit_info_p = (spx_rexmit_info *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_spx, 0);
}
}
if (spx_rexmit_info_p != NULL) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"[Retransmission] Original Packet %u",
spx_rexmit_info_p->num);
if (tree) {
proto_tree_add_uint_format(spx_tree, hf_spx_rexmt_frame,
tvb, 0, 0, spx_rexmit_info_p->num,
"This is a retransmission of frame %u",
spx_rexmit_info_p->num);
if (tvb_reported_length_remaining(tvb, hdr_len) > 0) {
proto_tree_add_item(spx_tree, hf_spx_rexmt_data, tvb, hdr_len, -1, ENC_NA);
}
}
return tvb_captured_length(tvb);
}
if (tvb_reported_length_remaining(tvb, hdr_len) > 0) {
if (pinfo->srcport > pinfo->destport) {
low_socket = pinfo->destport;
high_socket = pinfo->srcport;
} else {
low_socket = pinfo->srcport;
high_socket = pinfo->destport;
}
spx_infox.eom = conn_ctrl & SPX_EOM;
spx_infox.datastream_type = datastream_type;
next_tvb = tvb_new_subset_remaining(tvb, hdr_len);
if (dissector_try_uint_new(spx_socket_dissector_table, low_socket,
next_tvb, pinfo, tree, FALSE, &spx_infox))
{
return tvb_captured_length(tvb);
}
if (dissector_try_uint_new(spx_socket_dissector_table, high_socket,
next_tvb, pinfo, tree, FALSE, &spx_infox))
{
return tvb_captured_length(tvb);
}
call_data_dissector(next_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static int
dissect_ipxmsg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *msg_tree;
proto_item *ti;
guint8 conn_number, sig_char;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPX MSG");
col_clear(pinfo->cinfo, COL_INFO);
conn_number = tvb_get_guint8(tvb, 0);
sig_char = tvb_get_guint8(tvb, 1);
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s, Connection %d",
val_to_str_const(sig_char, ipxmsg_sigchar_vals, "Unknown Signature Char"), conn_number);
if (tree) {
ti = proto_tree_add_item(tree, proto_ipxmsg, tvb, 0, -1, ENC_NA);
msg_tree = proto_item_add_subtree(ti, ett_ipxmsg);
proto_tree_add_uint(msg_tree, hf_msg_conn, tvb, 0, 1, conn_number);
proto_tree_add_uint(msg_tree, hf_msg_sigchar, tvb, 1, 1, sig_char);
}
return tvb_captured_length(tvb);
}
static int
dissect_ipxrip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *rip_tree;
proto_item *ti, *hidden_item;
guint16 operation, ticks;
int cursor;
int available_length;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPX RIP");
col_clear(pinfo->cinfo, COL_INFO);
operation = tvb_get_ntohs(tvb, 0);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(operation, ipxrip_packet_vals, "Unknown"));
if (tree) {
ti = proto_tree_add_item(tree, proto_ipxrip, tvb, 0, -1, ENC_NA);
rip_tree = proto_item_add_subtree(ti, ett_ipxrip);
proto_tree_add_item(rip_tree, hf_ipxrip_packet_type, tvb, 0, 2, ENC_BIG_ENDIAN);
switch(operation)
{
case IPX_RIP_REQUEST:
hidden_item = proto_tree_add_boolean(rip_tree,
hf_ipxrip_request,
tvb, 0, 2, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case IPX_RIP_RESPONSE:
hidden_item = proto_tree_add_boolean(rip_tree,
hf_ipxrip_response,
tvb, 0, 2, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
}
available_length = tvb_reported_length(tvb);
for (cursor = 2; cursor < available_length; cursor += 8) {
ticks = tvb_get_ntohs(tvb, cursor+6);
proto_tree_add_item(rip_tree, hf_ipxrip_route_vector, tvb, cursor, 4, ENC_NA);
proto_tree_add_item(rip_tree, hf_ipxrip_hops, tvb, cursor+4, 2, ENC_BIG_ENDIAN);
if (operation == IPX_RIP_REQUEST - 1) {
proto_tree_add_item(rip_tree, hf_ipxrip_ticks, tvb, cursor+6, 2, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_uint_format_value(rip_tree, hf_ipxrip_ticks, tvb, cursor+6, 2, ticks,
"%d ms", ticks * 1000 / 18);
}
}
}
return tvb_captured_length(tvb);
}
static int
dissect_serialization(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *ser_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NW_SERIAL");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_serialization, tvb, 0, -1,
ENC_NA);
ser_tree = proto_item_add_subtree(ti, ett_serialization);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Serial number %s",
tvb_bytes_to_str(wmem_packet_scope(), tvb, 0, 6));
proto_tree_add_item(ser_tree, hf_serial_number, tvb, 0, 6, ENC_NA);
return tvb_captured_length(tvb);
}
static int
dissect_ipxsap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *sap_tree, *s_tree;
proto_item *ti, *hidden_item;
int cursor;
struct sap_query query;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPX SAP");
col_clear(pinfo->cinfo, COL_INFO);
query.query_type = tvb_get_ntohs(tvb, 0);
query.server_type = tvb_get_ntohs(tvb, 2);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(query.query_type, ipxsap_packet_vals, "Unknown Packet Type"));
if (tree) {
ti = proto_tree_add_item(tree, proto_sap, tvb, 0, -1, ENC_NA);
sap_tree = proto_item_add_subtree(ti, ett_ipxsap);
proto_tree_add_item(sap_tree, hf_sap_packet_type, tvb, 0, 2, ENC_BIG_ENDIAN);
switch(query.query_type)
{
case IPX_SAP_GENERAL_QUERY:
case IPX_SAP_NEAREST_QUERY:
hidden_item = proto_tree_add_boolean(sap_tree,
hf_sap_response,
tvb, 0, 2, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
case IPX_SAP_GENERAL_RESPONSE:
case IPX_SAP_NEAREST_RESPONSE:
hidden_item = proto_tree_add_boolean(sap_tree,
hf_sap_request,
tvb, 0, 2, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
}
if (query.query_type == IPX_SAP_GENERAL_RESPONSE ||
query.query_type == IPX_SAP_NEAREST_RESPONSE) {
int available_length = tvb_reported_length(tvb);
for (cursor = 2; (cursor + 64) <= available_length; cursor += 64) {
ti = proto_tree_add_item(sap_tree, hf_sap_server_name, tvb, cursor+2, 48, ENC_ASCII|ENC_NA);
s_tree = proto_item_add_subtree(ti, ett_ipxsap_server);
proto_tree_add_item(s_tree, hf_sap_server_type, tvb, cursor, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(s_tree, hf_sap_network, tvb, cursor+50, 4, ENC_NA);
proto_tree_add_item(s_tree, hf_sap_node, tvb, cursor+54, 6, ENC_NA);
proto_tree_add_item(s_tree, hf_sap_socket, tvb, cursor+60, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(s_tree, hf_sap_intermediate_networks, tvb, cursor+62, 2, ENC_BIG_ENDIAN);
}
}
else {
proto_tree_add_item(sap_tree, hf_sap_server_type, tvb, 2, 2, ENC_BIG_ENDIAN);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_ipx(void)
{
static hf_register_info hf_ipx[] = {
{ &hf_ipx_checksum,
{ "Checksum", "ipx.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_src,
{ "Source Address", "ipx.src", FT_STRING, BASE_NONE, NULL, 0x0,
"Source IPX Address \"network.node\"", HFILL }},
{ &hf_ipx_dst,
{ "Destination Address", "ipx.dst", FT_STRING, BASE_NONE, NULL, 0x0,
"Destination IPX Address \"network.node\"", HFILL }},
{ &hf_ipx_addr,
{ "Src/Dst Address", "ipx.addr", FT_STRING, BASE_NONE, NULL, 0x0,
"Source or Destination IPX Address \"network.node\"", HFILL }},
{ &hf_ipx_len,
{ "Length", "ipx.len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_hops,
{ "Transport Control (Hops)", "ipx.hops", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_packet_type,
{ "Packet Type", "ipx.packet_type", FT_UINT8, BASE_HEX, VALS(ipx_packet_type_vals),
0x0,
NULL, HFILL }},
{ &hf_ipx_dnet,
{ "Destination Network","ipx.dst.net", FT_IPXNET, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_dnode,
{ "Destination Node", "ipx.dst.node", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_dsocket,
{ "Destination Socket", "ipx.dst.socket", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&ipx_socket_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_ipx_snet,
{ "Source Network","ipx.src.net", FT_IPXNET, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_snode,
{ "Source Node", "ipx.src.node", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_ssocket,
{ "Source Socket", "ipx.src.socket", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&ipx_socket_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_ipx_net,
{ "Source or Destination Network","ipx.net", FT_IPXNET, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_node,
{ "Source or Destination Node", "ipx.node", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipx_socket,
{ "Source or Destination Socket", "ipx.socket", FT_UINT16, BASE_HEX|BASE_EXT_STRING,
&ipx_socket_vals_ext, 0x0,
NULL, HFILL }},
};
static hf_register_info hf_spx[] = {
{ &hf_spx_connection_control,
{ "Connection Control", "spx.ctl",
FT_UINT8, BASE_HEX, VALS(conn_vals), 0xF0,
NULL, HFILL }},
{ &hf_spx_connection_control_sys,
{ "System Packet", "spx.ctl.sys",
FT_BOOLEAN, 8, NULL, SPX_SYS_PACKET,
NULL, HFILL }},
{ &hf_spx_connection_control_send_ack,
{ "Send Ack", "spx.ctl.send_ack",
FT_BOOLEAN, 8, NULL, SPX_SEND_ACK,
NULL, HFILL }},
{ &hf_spx_connection_control_attn,
{ "Attention", "spx.ctl.attn",
FT_BOOLEAN, 8, NULL, SPX_ATTN,
NULL, HFILL }},
{ &hf_spx_connection_control_eom,
{ "End of Message", "spx.ctl.eom",
FT_BOOLEAN, 8, NULL, SPX_EOM,
NULL, HFILL }},
{ &hf_spx_connection_control_v2,
{ "SPXII Packet", "spx.ctl.v2",
FT_BOOLEAN, 8, NULL, SPX_VII_PACKET,
NULL, HFILL }},
{ &hf_spx_connection_control_neg_size,
{ "Negotiate Size", "spx.ctl.neg_size",
FT_BOOLEAN, 8, NULL, SPX_NEG_SIZE,
NULL, HFILL }},
{ &hf_spx_connection_control_reserved,
{ "Reserved", "spx.ctl.reserved",
FT_BOOLEAN, 8, NULL, SPX_RESERVED,
NULL, HFILL }},
{ &hf_spx_connection_control_ext_header,
{ "Extended Header", "spx.ctl.ext_header",
FT_BOOLEAN, 8, NULL, SPX_EXT_HEADER,
NULL, HFILL }},
{ &hf_spx_datastream_type,
{ "Datastream Type", "spx.type",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_src_id,
{ "Source Connection ID", "spx.src",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_dst_id,
{ "Destination Connection ID", "spx.dst",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_seq_nr,
{ "Sequence Number", "spx.seq",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_ack_nr,
{ "Acknowledgment Number", "spx.ack",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_all_nr,
{ "Allocation Number", "spx.alloc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_neg_size,
{ "Negotiation Size", "spx.neg_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_rexmt_frame,
{ "Retransmitted Frame Number", "spx.rexmt_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_spx_rexmt_data,
{ "Retransmitted data", "spx.rexmt_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static hf_register_info hf_ipxrip[] = {
{ &hf_ipxrip_request,
{ "Request", "ipxrip.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if IPX RIP request", HFILL }},
{ &hf_ipxrip_response,
{ "Response", "ipxrip.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if IPX RIP response", HFILL }},
{ &hf_ipxrip_packet_type,
{ "RIP packet type", "ipxrip.packet_type",
FT_UINT16, BASE_DEC, VALS(ipxrip_packet_vals), 0x0,
NULL, HFILL }},
{ &hf_ipxrip_route_vector,
{ "Route Vector", "ipxrip.route_vector",
FT_IPXNET, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipxrip_hops,
{ "Hops", "ipxrip.hops",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ipxrip_ticks,
{ "Ticks", "ipxrip.ticks",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static hf_register_info hf_sap[] = {
{ &hf_sap_request,
{ "Request", "ipxsap.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if SAP request", HFILL }},
{ &hf_sap_response,
{ "Response", "ipxsap.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if SAP response", HFILL }},
{ &hf_sap_packet_type, { "SAP packet type", "ipxsap.packet_type", FT_UINT16, BASE_DEC, VALS(ipxsap_packet_vals), 0x0, NULL, HFILL }},
{ &hf_sap_server_name, { "Server Name", "ipxsap.server_name", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_server_type, { "Server Type", "ipxsap.server_type", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &novell_server_vals_ext, 0x0, NULL, HFILL }},
{ &hf_sap_network, { "Network", "ipxsap.network", FT_IPXNET, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_node, { "Node", "ipxsap.node", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sap_socket, { "Socket", "ipxsap.socket", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &ipx_socket_vals_ext, 0x0, NULL, HFILL }},
{ &hf_sap_intermediate_networks, { "Intermediate Networks", "ipxsap.intermediate_networks", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static hf_register_info hf_ipxmsg[] = {
{ &hf_msg_conn,
{ "Connection Number", "ipxmsg.conn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_msg_sigchar,
{ "Signature Char", "ipxmsg.sigchar",
FT_UINT8, BASE_DEC, VALS(ipxmsg_sigchar_vals), 0x0,
NULL, HFILL }}
};
static hf_register_info hf_serial[] = {
{ &hf_serial_number,
{ "Serial number", "nw_serial.serial_number",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_ipx,
&ett_spx,
&ett_spx_connctrl,
&ett_ipxmsg,
&ett_ipxrip,
&ett_serialization,
&ett_ipxsap,
&ett_ipxsap_server,
};
proto_ipx = proto_register_protocol("Internetwork Packet eXchange",
"IPX", "ipx");
proto_register_field_array(proto_ipx, hf_ipx, array_length(hf_ipx));
register_dissector("ipx", dissect_ipx, proto_ipx);
proto_spx = proto_register_protocol("Sequenced Packet eXchange",
"SPX", "spx");
proto_register_field_array(proto_spx, hf_spx, array_length(hf_spx));
proto_ipxrip = proto_register_protocol("IPX Routing Information Protocol",
"IPX RIP", "ipxrip");
proto_register_field_array(proto_ipxrip, hf_ipxrip, array_length(hf_ipxrip));
proto_serialization = proto_register_protocol("NetWare Serialization Protocol",
"NW_SERIAL", "nw_serial");
proto_register_field_array(proto_serialization, hf_serial, array_length(hf_serial));
proto_ipxmsg = proto_register_protocol("IPX Message", "IPX MSG",
"ipxmsg");
proto_register_field_array(proto_ipxmsg, hf_ipxmsg, array_length(hf_ipxmsg));
proto_sap = proto_register_protocol("Service Advertisement Protocol",
"IPX SAP", "ipxsap");
register_dissector("ipxsap", dissect_ipxsap, proto_sap);
proto_register_field_array(proto_sap, hf_sap, array_length(hf_sap));
proto_register_subtree_array(ett, array_length(ett));
ipx_type_dissector_table = register_dissector_table("ipx.packet_type",
"IPX packet type", proto_ipx, FT_UINT8, BASE_HEX);
ipx_socket_dissector_table = register_dissector_table("ipx.socket",
"IPX socket", proto_ipx, FT_UINT16, BASE_HEX);
spx_socket_dissector_table = register_dissector_table("spx.socket",
"SPX socket", proto_spx, FT_UINT16, BASE_HEX);
register_init_routine(&spx_init_protocol);
register_postseq_cleanup_routine(&spx_postseq_cleanup);
ipx_tap=register_tap("ipx");
register_conversation_table(proto_ipx, TRUE, ipx_conversation_packet, ipx_hostlist_packet);
}
void
proto_reg_handoff_ipx(void)
{
dissector_handle_t ipx_handle, spx_handle;
dissector_handle_t ipxsap_handle, ipxrip_handle;
dissector_handle_t serialization_handle, ipxmsg_handle;
ipx_handle = find_dissector("ipx");
dissector_add_uint("udp.port", UDP_PORT_IPX, ipx_handle);
dissector_add_uint("ethertype", ETHERTYPE_IPX, ipx_handle);
dissector_add_uint("chdlc.protocol", ETHERTYPE_IPX, ipx_handle);
dissector_add_uint("ppp.protocol", PPP_IPX, ipx_handle);
dissector_add_uint("llc.dsap", SAP_NETWARE1, ipx_handle);
dissector_add_uint("llc.dsap", SAP_NETWARE2, ipx_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_802_3, ipx_handle);
dissector_add_uint("null.type", BSD_AF_IPX, ipx_handle);
dissector_add_uint("gre.proto", ETHERTYPE_IPX, ipx_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_IPX, ipx_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_NOVELL_EC, ipx_handle);
spx_handle = create_dissector_handle(dissect_spx, proto_spx);
dissector_add_uint("ipx.packet_type", IPX_PACKET_TYPE_SPX, spx_handle);
ipxsap_handle = find_dissector("ipxsap");
dissector_add_uint("ipx.socket", IPX_SOCKET_SAP, ipxsap_handle);
ipxrip_handle = create_dissector_handle(dissect_ipxrip, proto_ipxrip);
dissector_add_uint("ipx.socket", IPX_SOCKET_IPXRIP, ipxrip_handle);
serialization_handle = create_dissector_handle(dissect_serialization,
proto_serialization);
dissector_add_uint("ipx.socket", IPX_SOCKET_SERIALIZATION,
serialization_handle);
ipxmsg_handle = create_dissector_handle(dissect_ipxmsg, proto_ipxmsg);
dissector_add_uint("ipx.socket", IPX_SOCKET_IPX_MESSAGE, ipxmsg_handle);
dissector_add_uint("ipx.socket", IPX_SOCKET_IPX_MESSAGE1, ipxmsg_handle);
register_capture_dissector("ethertype", ETHERTYPE_IPX, capture_ipx, proto_ipx);
register_capture_dissector("ppp_hdlc", PPP_IPX, capture_ipx, proto_ipx);
register_capture_dissector("sll.ltype", LINUX_SLL_P_802_3, capture_ipx, proto_ipx);
register_capture_dissector("llc.dsap", SAP_NETWARE1, capture_ipx, proto_ipx);
register_capture_dissector("llc.dsap", SAP_NETWARE2, capture_ipx, proto_ipx);
}
