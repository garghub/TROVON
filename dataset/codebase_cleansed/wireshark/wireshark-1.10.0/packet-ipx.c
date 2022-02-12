static const char*
socket_text(guint16 socket)
{
return val_to_str_ext_const(socket, &ipx_socket_vals_ext, "Unknown");
}
void
capture_ipx(packet_counts *ld)
{
ld->ipx++;
}
static void
dissect_ipx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_tree *ipx_tree = NULL;
proto_item *ti = NULL, *hidden_item;
const guint8 *src_net_node, *dst_net_node;
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
src_net_node = tvb_get_ptr(tvb, 18, 10);
dst_net_node = tvb_get_ptr(tvb, 6, 10);
SET_ADDRESS(&pinfo->net_src, AT_IPX, 10, src_net_node);
SET_ADDRESS(&pinfo->src, AT_IPX, 10, src_net_node);
SET_ADDRESS(&ipxh->ipx_src, AT_IPX, 10, src_net_node);
SET_ADDRESS(&pinfo->net_dst, AT_IPX, 10, dst_net_node);
SET_ADDRESS(&pinfo->dst, AT_IPX, 10, dst_net_node);
SET_ADDRESS(&ipxh->ipx_dst, AT_IPX, 10, dst_net_node);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (0x%04x)",
socket_text(ipxh->ipx_dsocket), ipxh->ipx_dsocket);
if (tree) {
ti = proto_tree_add_item(tree, proto_ipx, tvb, 0, IPX_HEADER_LEN, ENC_NA);
ipx_tree = proto_item_add_subtree(ti, ett_ipx);
}
str=ep_address_to_str(&pinfo->net_src);
hidden_item = proto_tree_add_string(ipx_tree, hf_ipx_src, tvb, 0, 0, str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string(ipx_tree, hf_ipx_addr, tvb, 0, 0, str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
str=ep_address_to_str(&pinfo->net_dst);
hidden_item = proto_tree_add_string(ipx_tree, hf_ipx_dst, tvb, 0, 0, str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_string(ipx_tree, hf_ipx_addr, tvb, 0, 0, str);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(ipx_tree, hf_ipx_checksum, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(ipx_tree, hf_ipx_len, tvb, 2, 2, ipxh->ipx_length,
"Length: %d bytes", ipxh->ipx_length);
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
pinfo->ipxptype = ipxh->ipx_type;
if (ipxh->ipx_ssocket > ipxh->ipx_dsocket) {
first_socket = ipxh->ipx_dsocket;
second_socket = ipxh->ipx_ssocket;
} else {
first_socket = ipxh->ipx_ssocket;
second_socket = ipxh->ipx_dsocket;
}
tap_queue_packet(ipx_tap, pinfo, ipxh);
if (second_socket != IPX_SOCKET_NWLINK_SMB_NAMEQUERY) {
if (dissector_try_uint(ipx_socket_dissector_table, first_socket,
next_tvb, pinfo, tree))
return;
}
if (dissector_try_uint(ipx_socket_dissector_table, second_socket,
next_tvb, pinfo, tree))
return;
if (dissector_try_uint(ipx_type_dissector_table, ipxh->ipx_type, next_tvb,
pinfo, tree))
return;
call_dissector(data_handle,next_tvb, pinfo, tree);
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
if (spx_hash)
g_hash_table_destroy(spx_hash);
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
key = se_new(spx_hash_key);
key->conversation = conversation;
key->spx_src = spx_src;
key->spx_seq = spx_seq;
value = se_new0(spx_hash_value);
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
spx_conn_ctrl(guint8 ctrl)
{
const char *p;
static const value_string conn_vals[] = {
{ 0x00, "Data, No Ack Required" },
{ SPX_EOM, "End-of-Message" },
{ SPX_ATTN, "Attention" },
{ SPX_SEND_ACK, "Acknowledgment Required"},
{ SPX_SEND_ACK|SPX_EOM, "Send Ack: End Message"},
{ SPX_SYS_PACKET, "System Packet"},
{ SPX_SYS_PACKET|SPX_SEND_ACK, "System Packet: Send Ack"},
{ 0x00, NULL }
};
p = try_val_to_str((ctrl & 0xf0), conn_vals );
if (p) {
return p;
}
else {
return "Unknown";
}
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
static void
dissect_spx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *spx_tree = NULL;
proto_item *ti;
tvbuff_t *next_tvb;
guint8 conn_ctrl;
proto_tree *cc_tree;
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
if (tree) {
ti = proto_tree_add_item(tree, proto_spx, tvb, 0, SPX_HEADER_LEN, ENC_NA);
spx_tree = proto_item_add_subtree(ti, ett_spx);
}
conn_ctrl = tvb_get_guint8(tvb, 0);
spx_msg_string = spx_conn_ctrl(conn_ctrl);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", spx_msg_string);
if (tree) {
ti = proto_tree_add_uint_format(spx_tree, hf_spx_connection_control, tvb,
0, 1, conn_ctrl,
"Connection Control: %s (0x%02X)",
spx_msg_string, conn_ctrl);
cc_tree = proto_item_add_subtree(ti, ett_spx_connctrl);
proto_tree_add_boolean(cc_tree, hf_spx_connection_control_sys, tvb,
0, 1, conn_ctrl);
proto_tree_add_boolean(cc_tree, hf_spx_connection_control_send_ack, tvb,
0, 1, conn_ctrl);
proto_tree_add_boolean(cc_tree, hf_spx_connection_control_attn, tvb,
0, 1, conn_ctrl);
proto_tree_add_boolean(cc_tree, hf_spx_connection_control_eom, tvb,
0, 1, conn_ctrl);
}
datastream_type = tvb_get_guint8(tvb, 1);
datastream_type_string = spx_datastream(datastream_type);
if (datastream_type_string != NULL) {
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)",
datastream_type_string);
}
if (tree) {
if (datastream_type_string != NULL) {
proto_tree_add_uint_format(spx_tree, hf_spx_datastream_type, tvb,
1, 1, datastream_type,
"Datastream Type: %s (0x%02X)",
datastream_type_string,
datastream_type);
} else {
proto_tree_add_uint_format(spx_tree, hf_spx_datastream_type, tvb,
1, 1, datastream_type,
"Datastream Type: 0x%02X",
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
}
if (conn_ctrl & SPX_SYS_PACKET) {
spx_rexmit_info_p = NULL;
} else {
if (!pinfo->fd->flags.visited) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src,
&pinfo->dst, PT_NCP, pinfo->srcport,
pinfo->srcport, 0);
if (conversation == NULL) {
conversation = conversation_new(pinfo->fd->num, &pinfo->src,
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
pkt_value->num = pinfo->fd->num;
spx_rexmit_info_p = NULL;
} else {
spx_rexmit_info_p = se_new(spx_rexmit_info);
spx_rexmit_info_p->num = pkt_value->num;
p_add_proto_data(pinfo->fd, proto_spx, 0,
spx_rexmit_info_p);
}
} else {
spx_rexmit_info_p = (spx_rexmit_info *)p_get_proto_data(pinfo->fd,
proto_spx, 0);
}
}
if (spx_rexmit_info_p != NULL) {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"[Retransmission] Original Packet %u",
spx_rexmit_info_p->num);
}
if (tree) {
proto_tree_add_uint_format(spx_tree, hf_spx_rexmt_frame,
tvb, 0, 0, spx_rexmit_info_p->num,
"This is a retransmission of frame %u",
spx_rexmit_info_p->num);
if (tvb_length_remaining(tvb, SPX_HEADER_LEN) > 0) {
proto_tree_add_text(spx_tree, tvb,
SPX_HEADER_LEN, -1,
"Retransmitted data");
}
}
return;
}
if (tvb_reported_length_remaining(tvb, SPX_HEADER_LEN) > 0) {
void* pd_save;
if (pinfo->srcport > pinfo->destport) {
low_socket = pinfo->destport;
high_socket = pinfo->srcport;
} else {
low_socket = pinfo->srcport;
high_socket = pinfo->destport;
}
spx_infox.eom = conn_ctrl & SPX_EOM;
spx_infox.datastream_type = datastream_type;
pd_save = pinfo->private_data;
pinfo->private_data = &spx_infox;
next_tvb = tvb_new_subset_remaining(tvb, SPX_HEADER_LEN);
if (dissector_try_uint(spx_socket_dissector_table, low_socket,
next_tvb, pinfo, tree))
{
pinfo->private_data = pd_save;
return;
}
if (dissector_try_uint(spx_socket_dissector_table, high_socket,
next_tvb, pinfo, tree))
{
pinfo->private_data = pd_save;
return;
}
call_dissector(data_handle, next_tvb, pinfo, tree);
pinfo->private_data = pd_save;
}
}
static void
dissect_ipxmsg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *msg_tree;
proto_item *ti;
guint8 conn_number, sig_char;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPX MSG");
col_clear(pinfo->cinfo, COL_INFO);
conn_number = tvb_get_guint8(tvb, 0);
sig_char = tvb_get_guint8(tvb, 1);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s, Connection %d",
val_to_str_const(sig_char, ipxmsg_sigchar_vals, "Unknown Signature Char"), conn_number);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_ipxmsg, tvb, 0, -1, ENC_NA);
msg_tree = proto_item_add_subtree(ti, ett_ipxmsg);
proto_tree_add_uint(msg_tree, hf_msg_conn, tvb, 0, 1, conn_number);
proto_tree_add_uint(msg_tree, hf_msg_sigchar, tvb, 1, 1, sig_char);
}
}
static void
dissect_ipxrip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *rip_tree;
proto_item *ti, *hidden_item;
guint16 operation;
ipx_rt_def_t route;
int cursor;
int available_length;
static const char *rip_type[3] = { "Request", "Response", "Unknown" };
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPX RIP");
col_clear(pinfo->cinfo, COL_INFO);
operation = tvb_get_ntohs(tvb, 0) - 1;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_set_str(pinfo->cinfo, COL_INFO, rip_type[MIN(operation, 2)]);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_ipxrip, tvb, 0, -1, ENC_NA);
rip_tree = proto_item_add_subtree(ti, ett_ipxrip);
if (operation < 2) {
proto_tree_add_text(rip_tree, tvb, 0, 2,
"RIP packet type: %s", rip_type[operation]);
if (operation == 0) {
hidden_item = proto_tree_add_boolean(rip_tree,
hf_ipxrip_request,
tvb, 0, 2, 1);
} else {
hidden_item = proto_tree_add_boolean(rip_tree,
hf_ipxrip_response,
tvb, 0, 2, 1);
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
else {
proto_tree_add_text(rip_tree, tvb, 0, 2, "Unknown RIP packet type");
}
available_length = tvb_reported_length(tvb);
for (cursor = 2; cursor < available_length; cursor += 8) {
tvb_memcpy(tvb, (guint8 *)&route.network, cursor, 4);
route.hops = tvb_get_ntohs(tvb, cursor+4);
route.ticks = tvb_get_ntohs(tvb, cursor+6);
if (operation == IPX_RIP_REQUEST - 1) {
proto_tree_add_text(rip_tree, tvb, cursor, 8,
"Route Vector: %s, %d hop%s, %d tick%s",
ipxnet_to_string((guint8*)&route.network),
route.hops, route.hops == 1 ? "" : "s",
route.ticks, route.ticks == 1 ? "" : "s");
}
else {
proto_tree_add_text(rip_tree, tvb, cursor, 8,
"Route Vector: %s, %d hop%s, %d tick%s (%d ms)",
ipxnet_to_string((guint8*)&route.network),
route.hops, route.hops == 1 ? "" : "s",
route.ticks, route.ticks == 1 ? "" : "s",
route.ticks * 1000 / 18);
}
}
}
}
static void
dissect_serialization(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
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
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Serial number %s",
tvb_bytes_to_str(tvb, 0, 6));
}
if (tree) {
proto_tree_add_text(ser_tree, tvb, 0, 6,
"Serial number: %s", tvb_bytes_to_str(tvb, 0, 6));
}
}
static void
dissect_ipxsap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *sap_tree, *s_tree;
proto_item *ti, *hidden_item;
int cursor;
struct sap_query query;
guint16 server_type;
gchar *server_name;
guint16 server_port;
guint16 intermediate_network;
static const char *sap_type[4] = { "General Query", "General Response",
"Nearest Query", "Nearest Response" };
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPX SAP");
col_clear(pinfo->cinfo, COL_INFO);
query.query_type = tvb_get_ntohs(tvb, 0);
query.server_type = tvb_get_ntohs(tvb, 2);
if (check_col(pinfo->cinfo, COL_INFO)) {
if (query.query_type >= 1 && query.query_type <= 4) {
col_set_str(pinfo->cinfo, COL_INFO, sap_type[query.query_type - 1]);
}
else {
col_set_str(pinfo->cinfo, COL_INFO, "Unknown Packet Type");
}
}
if (tree) {
ti = proto_tree_add_item(tree, proto_sap, tvb, 0, -1, ENC_NA);
sap_tree = proto_item_add_subtree(ti, ett_ipxsap);
if (query.query_type >= 1 && query.query_type <= 4) {
proto_tree_add_text(sap_tree, tvb, 0, 2, "%s", sap_type[query.query_type - 1]);
if ((query.query_type - 1) % 2) {
hidden_item = proto_tree_add_boolean(sap_tree,
hf_sap_response,
tvb, 0, 2, 1);
} else {
hidden_item = proto_tree_add_boolean(sap_tree,
hf_sap_request,
tvb, 0, 2, 1);
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
else {
proto_tree_add_text(sap_tree, tvb, 0, 2,
"Unknown SAP Packet Type %d", query.query_type);
}
if (query.query_type == IPX_SAP_GENERAL_RESPONSE ||
query.query_type == IPX_SAP_NEAREST_RESPONSE) {
int available_length = tvb_reported_length(tvb);
for (cursor = 2; (cursor + 64) <= available_length; cursor += 64) {
server_type = tvb_get_ntohs(tvb, cursor);
server_name = tvb_format_stringzpad(tvb, cursor+2, 48);
ti = proto_tree_add_text(sap_tree, tvb, cursor+2, 48,
"Server Name: %s", server_name);
s_tree = proto_item_add_subtree(ti, ett_ipxsap_server);
proto_tree_add_text(s_tree, tvb, cursor, 2, "Server Type: %s (0x%04X)",
val_to_str_ext_const(server_type, &novell_server_vals_ext, "Unknown"),
server_type);
proto_tree_add_text(s_tree, tvb, cursor+50, 4, "Network: %s",
ipxnet_to_string(tvb_get_ptr(tvb, cursor+50, 4)));
proto_tree_add_text(s_tree, tvb, cursor+54, 6, "Node: %s",
tvb_ether_to_str(tvb, cursor+54));
server_port = tvb_get_ntohs(tvb, cursor+60);
proto_tree_add_text(s_tree, tvb, cursor+60, 2, "Socket: %s (0x%04x)",
socket_text(server_port),
server_port);
intermediate_network = tvb_get_ntohs(tvb, cursor+62);
proto_tree_add_text(s_tree, tvb, cursor+62, 2,
"Intermediate Networks: %d",
intermediate_network);
}
}
else {
proto_tree_add_text(sap_tree, tvb, 2, 2, "Server Type: %s (0x%04X)",
val_to_str_ext_const(query.server_type, &novell_server_vals_ext, "Unknown"),
query.server_type);
}
}
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
FT_UINT8, BASE_HEX, NULL, 0x0,
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
{ &hf_spx_datastream_type,
{ "Datastream type", "spx.type",
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
{ &hf_spx_rexmt_frame,
{ "Retransmitted Frame Number", "spx.rexmt_frame",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
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
"TRUE if IPX RIP response", HFILL }}
};
static hf_register_info hf_sap[] = {
{ &hf_sap_request,
{ "Request", "ipxsap.request",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if SAP request", HFILL }},
{ &hf_sap_response,
{ "Response", "ipxsap.response",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"TRUE if SAP response", HFILL }}
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
proto_ipxmsg = proto_register_protocol("IPX Message", "IPX MSG",
"ipxmsg");
proto_register_field_array(proto_ipxmsg, hf_ipxmsg, array_length(hf_ipxmsg));
proto_sap = proto_register_protocol("Service Advertisement Protocol",
"IPX SAP", "ipxsap");
register_dissector("ipxsap", dissect_ipxsap, proto_sap);
proto_register_field_array(proto_sap, hf_sap, array_length(hf_sap));
proto_register_subtree_array(ett, array_length(ett));
ipx_type_dissector_table = register_dissector_table("ipx.packet_type",
"IPX packet type", FT_UINT8, BASE_HEX);
ipx_socket_dissector_table = register_dissector_table("ipx.socket",
"IPX socket", FT_UINT16, BASE_HEX);
spx_socket_dissector_table = register_dissector_table("spx.socket",
"SPX socket", FT_UINT16, BASE_HEX);
register_init_routine(&spx_init_protocol);
register_postseq_cleanup_routine(&spx_postseq_cleanup);
ipx_tap=register_tap("ipx");
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
dissector_add_uint("chdlctype", ETHERTYPE_IPX, ipx_handle);
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
data_handle = find_dissector("data");
}
