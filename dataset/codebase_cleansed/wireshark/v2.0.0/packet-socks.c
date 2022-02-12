static const char *get_auth_method_name( guint Number){
if ( Number == 0) return "No authentication";
if ( Number == 1) return "GSSAPI";
if ( Number == 2) return "Username/Password";
if ( Number == 3) return "Chap";
if (( Number >= 4) && ( Number <= 0x7f))return "IANA assigned";
if (( Number >= 0x80) && ( Number <= 0xfe)) return "private method";
if ( Number == 0xff) return "no acceptable method";
return "Bad method number (not 0-0xff)";
}
static int display_address(tvbuff_t *tvb, int offset, proto_tree *tree) {
int a_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item( tree, hf_socks_address_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (a_type)
{
case 1:
proto_tree_add_item( tree, hf_socks_ip_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case 3:
{
guint8 len;
gchar* str;
len = tvb_get_guint8(tvb, offset);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+1, len, ENC_ASCII);
proto_tree_add_string(tree, hf_socks_remote_name, tvb, offset, len+1, str);
offset += (len+1);
}
break;
case 4:
proto_tree_add_item( tree, hf_socks_ip6_dst, tvb, offset, 16, ENC_NA);
offset += 16;
break;
}
return offset;
}
static int get_address_v5(tvbuff_t *tvb, int offset,
socks_hash_entry_t *hash_info) {
int a_type;
address addr;
a_type = tvb_get_guint8(tvb, offset);
offset += 1;
switch(a_type)
{
case 1:
if ( hash_info) {
TVB_SET_ADDRESS(&addr, AT_IPv4, tvb, offset, 4);
WMEM_COPY_ADDRESS(wmem_file_scope(), &hash_info->dst_addr, &addr);
}
offset += 4;
break;
case 4:
if ( hash_info) {
TVB_SET_ADDRESS(&addr, AT_IPv6, tvb, offset, 16);
WMEM_COPY_ADDRESS(wmem_file_scope(), &hash_info->dst_addr, &addr);
}
offset += 16;
break;
case 3:
offset += tvb_get_guint8(tvb, offset) + 1;
break;
}
return offset;
}
static void
socks_udp_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int offset = 0;
guint32 *ptr;
socks_hash_entry_t *hash_info;
conversation_t *conversation;
proto_tree *socks_tree;
proto_item *ti;
conversation = find_conversation( pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
DISSECTOR_ASSERT( conversation);
hash_info = (socks_hash_entry_t *)conversation_get_proto_data(conversation, proto_socks);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Socks");
col_set_str(pinfo->cinfo, COL_INFO, "Version: 5, UDP Associated packet");
if ( tree) {
ti = proto_tree_add_protocol_format( tree, proto_socks, tvb, offset, -1, "Socks" );
socks_tree = proto_item_add_subtree(ti, ett_socks);
proto_tree_add_item(socks_tree, hf_socks_reserved2, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(socks_tree, hf_socks_fragment_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset = display_address( tvb, offset, socks_tree);
hash_info->udp_remote_port = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint( socks_tree, hf_socks_dstport, tvb,
offset, 2, hash_info->udp_remote_port);
offset += 2;
}
else {
offset += 3;
offset = get_address_v5( tvb, offset, 0) + 2;
}
if ( pinfo->srcport == hash_info->port)
ptr = &pinfo->destport;
else
ptr = &pinfo->srcport;
*ptr = hash_info->udp_remote_port;
decode_udp_ports( tvb, offset, pinfo, tree, pinfo->srcport, pinfo->destport, -1);
*ptr = hash_info->udp_port;
}
static void
new_udp_conversation( socks_hash_entry_t *hash_info, packet_info *pinfo){
conversation_t *conversation = conversation_new( pinfo->fd->num, &pinfo->src, &pinfo->dst, PT_UDP,
hash_info->udp_port, hash_info->port, 0);
DISSECTOR_ASSERT( conversation);
conversation_add_proto_data(conversation, proto_socks, hash_info);
conversation_set_dissector(conversation, socks_udp_handle);
}
static void
save_client_state(packet_info *pinfo, enum ClientState state)
{
sock_state_t* state_info = (sock_state_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_socks, 0);
if ((state_info != NULL) && (state_info->client == clientNoInit)) {
state_info->client = state;
}
}
static void
save_server_state(packet_info *pinfo, enum ServerState state)
{
sock_state_t* state_info = (sock_state_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_socks, 0);
if ((state_info != NULL) && (state_info->server == serverNoInit)) {
state_info->server = state;
}
}
static void
display_socks_v4(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, socks_hash_entry_t *hash_info, sock_state_t* state_info) {
unsigned char ipaddr[4];
guint str_len;
if (state_info == NULL)
return;
if (hash_info->server_port == pinfo->destport) {
switch (state_info->client)
{
case clientStart:
proto_tree_add_item( tree, hf_socks_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( tree, hf_socks_cmd, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( tree, hf_socks_dstport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tvb_memcpy(tvb, ipaddr, offset, 4);
proto_tree_add_item( tree, hf_socks_ip_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
str_len = tvb_strsize(tvb, offset);
proto_tree_add_item( tree, hf_socks_username, tvb, offset, str_len, ENC_ASCII|ENC_NA);
offset += str_len;
if ( ipaddr[0] == 0 && ipaddr[1] == 0 &&
ipaddr[2] == 0 && ipaddr[3] != 0) {
str_len = tvb_strsize(tvb, offset);
proto_tree_add_item( tree, hf_v4a_dns_name, tvb, offset, str_len, ENC_ASCII|ENC_NA);
}
break;
default:
break;
}
} else {
switch (state_info->server)
{
case serverStart:
proto_tree_add_item( tree, hf_socks_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( tree, hf_socks_results_4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( tree, hf_socks_dstport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item( tree, hf_socks_ip_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
}
static void
client_display_socks_v5(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, socks_hash_entry_t *hash_info, sock_state_t* state_info) {
unsigned int i;
const char *AuthMethodStr;
sock_state_t new_state_info;
if (state_info == NULL)
return;
proto_tree_add_item( tree, hf_socks_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (state_info->client == clientStart)
{
proto_tree *AuthTree;
proto_item *ti;
guint8 num_auth_methods, auth;
AuthTree = proto_tree_add_subtree( tree, tvb, offset, -1, ett_socks_auth, &ti, "Client Authentication Methods");
num_auth_methods = tvb_get_guint8(tvb, offset);
proto_item_set_len(ti, num_auth_methods+1);
proto_tree_add_item( AuthTree, hf_client_auth_method_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for( i = 0; i < num_auth_methods; ++i) {
auth = tvb_get_guint8( tvb, offset);
AuthMethodStr = get_auth_method_name(auth);
proto_tree_add_uint_format(AuthTree, hf_client_auth_method, tvb, offset, 1, auth,
"Method[%u]: %u (%s)", i, auth, AuthMethodStr);
offset += 1;
}
if ((num_auth_methods == 1) &&
(tvb_bytes_exist(tvb, offset + 2, 1)) &&
(tvb_get_guint8(tvb, offset + 2) == 0) &&
(tvb_reported_length_remaining(tvb, offset + 2 + num_auth_methods) > 0)) {
new_state_info.client = clientV5Command;
client_display_socks_v5(tvb, offset, pinfo, tree, hash_info, &new_state_info);
}
}
else if (state_info->client == clientV5Command) {
proto_tree_add_item( tree, hf_socks_cmd, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( tree, hf_socks_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset = display_address(tvb, offset, tree);
proto_tree_add_item( tree, hf_client_port, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else if ((state_info->client == clientWaitForAuthReply) &&
(state_info->server == serverInitReply)) {
guint16 len;
gchar* str;
switch(hash_info->authentication_method)
{
case NO_AUTHENTICATION:
break;
case USER_NAME_AUTHENTICATION:
len = tvb_get_guint8(tvb, offset);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+1, len, ENC_ASCII);
proto_tree_add_string(tree, hf_socks_username, tvb, offset, len+1, str);
offset += (len+1);
len = tvb_get_guint8(tvb, offset);
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+1, len, ENC_ASCII);
proto_tree_add_string(tree, hf_socks_password, tvb, offset, len+1, str);
break;
case GSS_API_AUTHENTICATION:
proto_tree_add_item( tree, hf_gssapi_command, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( tree, hf_gssapi_length, tvb, offset+1, 2, ENC_BIG_ENDIAN);
len = tvb_get_ntohs(tvb, offset+1);
if (len > 0)
proto_tree_add_item( tree, hf_gssapi_payload, tvb, offset+3, len, ENC_NA);
break;
default:
break;
}
}
}
static void
server_display_socks_v5(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree, socks_hash_entry_t *hash_info _U_, sock_state_t* state_info) {
const char *AuthMethodStr;
guint8 auth, auth_status;
proto_item *ti;
if (state_info == NULL)
return;
proto_tree_add_item( tree, hf_socks_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch(state_info->server)
{
case serverStart:
auth = tvb_get_guint8( tvb, offset);
AuthMethodStr = get_auth_method_name(auth);
proto_tree_add_uint_format_value(tree, hf_server_accepted_auth_method, tvb, offset, 1, auth,
"0x%0x (%s)", auth, AuthMethodStr);
break;
case serverUserReply:
auth_status = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(tree, hf_server_auth_status, tvb, offset, 1, ENC_BIG_ENDIAN);
if(auth_status != 0)
proto_item_append_text(ti, " (failure)");
else
proto_item_append_text(ti, " (success)");
break;
case serverGssApiReply:
auth_status = tvb_get_guint8(tvb, offset);
proto_tree_add_item( tree, hf_gssapi_command, tvb, offset, 1, ENC_BIG_ENDIAN);
if (auth_status != 0xFF) {
guint16 len;
proto_tree_add_item( tree, hf_gssapi_length, tvb, offset+1, 2, ENC_BIG_ENDIAN);
len = tvb_get_ntohs(tvb, offset+1);
if (len > 0)
proto_tree_add_item( tree, hf_gssapi_payload, tvb, offset+3, len, ENC_NA);
}
break;
case serverCommandReply:
proto_tree_add_item( tree, hf_socks_results_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( tree, hf_socks_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset = display_address(tvb, offset, tree);
proto_tree_add_item( tree, hf_client_port, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case serverBindReply:
proto_tree_add_item( tree, hf_socks_results_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( tree, hf_socks_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset = display_address(tvb, offset, tree);
proto_tree_add_item( tree, hf_server_remote_host_port, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
static void
state_machine_v4( socks_hash_entry_t *hash_info, tvbuff_t *tvb,
int offset, packet_info *pinfo) {
address addr;
if (hash_info->clientState != clientDone)
save_client_state(pinfo, hash_info->clientState);
if (hash_info->serverState != serverDone)
save_server_state(pinfo, hash_info->serverState);
if (hash_info->server_port == pinfo->destport) {
col_append_str(pinfo->cinfo, COL_INFO, " Connect to server request");
hash_info->command = tvb_get_guint8(tvb, offset + 1);
if ( hash_info->command == CONNECT_COMMAND)
hash_info->port = tvb_get_ntohs(tvb, offset + 2);
TVB_SET_ADDRESS(&addr, AT_IPv4, tvb, offset, 4);
WMEM_COPY_ADDRESS(wmem_file_scope(), &hash_info->dst_addr, &addr);
hash_info->clientState = clientDone;
}
else {
col_append_str(pinfo->cinfo, COL_INFO, " Connect Response");
if (tvb_get_guint8(tvb, offset + 1) == 90)
hash_info->serverState = serverDone;
else
hash_info->serverState = serverError;
}
}
static void
client_state_machine_v5( socks_hash_entry_t *hash_info, tvbuff_t *tvb,
int offset, packet_info *pinfo, gboolean start_of_frame) {
if (start_of_frame)
save_client_state(pinfo, hash_info->clientState);
if (hash_info->clientState == clientStart)
{
guint8 num_auth_methods;
col_append_str(pinfo->cinfo, COL_INFO, " Connect to server request");
num_auth_methods = tvb_get_guint8(tvb, offset + 1);
if ((num_auth_methods == 0) ||
((num_auth_methods == 1) &&
(tvb_get_guint8(tvb, offset + 2) == 0))) {
hash_info->clientState = clientV5Command;
if (tvb_reported_length_remaining(tvb, offset + 2 + num_auth_methods) > 0) {
client_state_machine_v5(hash_info, tvb, offset + 2 + num_auth_methods, pinfo, FALSE);
}
} else {
hash_info->clientState = clientWaitForAuthReply;
}
} else if ((hash_info->clientState == clientWaitForAuthReply) &&
(hash_info->serverState == serverInitReply)) {
switch(hash_info->authentication_method)
{
case NO_AUTHENTICATION:
hash_info->clientState = clientV5Command;
hash_info->serverState = serverCommandReply;
break;
case USER_NAME_AUTHENTICATION:
hash_info->clientState = clientV5Command;
hash_info->serverState = serverUserReply;
break;
case GSS_API_AUTHENTICATION:
hash_info->clientState = clientV5Command;
hash_info->serverState = serverGssApiReply;
break;
default:
hash_info->clientState = clientError;
break;
}
} else if (hash_info->clientState == clientV5Command) {
hash_info->command = tvb_get_guint8(tvb, offset + 1);
col_append_fstr(pinfo->cinfo, COL_INFO, " Command Request - %s",
val_to_str_const(hash_info->command, cmd_strings, "Unknown"));
offset += 3;
offset = get_address_v5(tvb, offset, hash_info);
if (( hash_info->command == CONNECT_COMMAND) ||
( hash_info->command == UDP_ASSOCIATE_COMMAND))
hash_info->port = tvb_get_ntohs(tvb, offset);
hash_info->clientState = clientDone;
}
}
static void
server_state_machine_v5( socks_hash_entry_t *hash_info, tvbuff_t *tvb,
int offset, packet_info *pinfo, gboolean start_of_frame) {
if (start_of_frame)
save_server_state(pinfo, hash_info->serverState);
switch (hash_info->serverState) {
case serverStart:
col_append_str(pinfo->cinfo, COL_INFO, " Connect to server response");
hash_info->authentication_method = tvb_get_guint8(tvb, offset + 1);
hash_info->serverState = serverInitReply;
switch (hash_info->authentication_method)
{
case NO_AUTHENTICATION:
hash_info->serverState = serverCommandReply;
hash_info->clientState = clientV5Command;
break;
case USER_NAME_AUTHENTICATION:
hash_info->serverState = serverUserReply;
break;
case GSS_API_AUTHENTICATION:
hash_info->serverState = serverGssApiReply;
break;
default:
hash_info->serverState = serverError;
break;
}
break;
case serverUserReply:
col_append_str(pinfo->cinfo, COL_INFO, " User authentication reply");
break;
case serverGssApiReply:
if (tvb_get_guint8(tvb, offset+1) == 0xFF) {
col_append_str(pinfo->cinfo, COL_INFO, " GSSAPI Authentication failure");
hash_info->serverState = serverError;
} else {
col_append_str(pinfo->cinfo, COL_INFO, " GSSAPI Authentication reply");
if (tvb_get_ntohs(tvb, offset+2) == 0)
hash_info->serverState = serverCommandReply;
}
break;
case serverCommandReply:
col_append_fstr(pinfo->cinfo, COL_INFO, " Command Response - %s",
val_to_str_const(hash_info->command, cmd_strings, "Unknown"));
switch(hash_info->command)
{
case CONNECT_COMMAND:
case PING_COMMAND:
case TRACERT_COMMAND:
hash_info->serverState = serverDone;
break;
case BIND_COMMAND:
hash_info->serverState = serverBindReply;
if ((tvb_get_guint8(tvb, offset + 2) == 0) &&
(tvb_reported_length_remaining(tvb, offset) > 5)) {
offset = display_address(tvb, offset, NULL);
client_state_machine_v5(hash_info, tvb, offset, pinfo, FALSE);
}
break;
case UDP_ASSOCIATE_COMMAND:
offset += 3;
offset = get_address_v5(tvb, offset, hash_info);
hash_info->udp_port = tvb_get_ntohs(tvb, offset);
if (!pinfo->fd->flags.visited)
new_udp_conversation( hash_info, pinfo);
break;
}
break;
case serverBindReply:
col_append_str(pinfo->cinfo, COL_INFO, " Command Response: Bind remote host info");
break;
default:
break;
}
}
static void
display_ping_and_tracert(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, socks_hash_entry_t *hash_info) {
const guchar *data, *dataend;
const guchar *lineend, *eol;
int linelen;
if ( pinfo->destport == TCP_PORT_SOCKS){
col_append_str(pinfo->cinfo, COL_INFO, ", Terminate Request");
proto_tree_add_item(tree, (hash_info->command == PING_COMMAND) ? hf_socks_ping_end_command : hf_socks_traceroute_end_command, tvb, offset, 1, ENC_NA);
}
else {
col_append_str(pinfo->cinfo, COL_INFO, ", Results");
if ( tree){
proto_tree_add_item(tree, (hash_info->command == PING_COMMAND) ? hf_socks_ping_results : hf_socks_traceroute_results, tvb, offset, -1, ENC_NA);
data = tvb_get_ptr(tvb, offset, -1);
dataend = data + tvb_captured_length_remaining(tvb, offset);
while (data < dataend) {
lineend = find_line_end(data, dataend, &eol);
linelen = (int)(lineend - data);
proto_tree_add_format_text( tree, tvb, offset, linelen);
offset += linelen;
data = lineend;
}
}
}
}
static void clear_in_socks_dissector_flag(void *s)
{
sock_state_t* state_info = (sock_state_t*)s;
state_info->in_socks_dissector_flag = 0;
}
static void call_next_dissector(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, proto_tree *socks_tree,
socks_hash_entry_t *hash_info, sock_state_t* state_info, struct tcpinfo *tcpinfo)
{
guint32 *ptr;
guint16 save_can_desegment;
struct tcp_analysis *tcpd=NULL;
tcpd=get_tcp_conversation_data(NULL,pinfo);
if (( hash_info->command == PING_COMMAND) ||
( hash_info->command == TRACERT_COMMAND))
display_ping_and_tracert(tvb, offset, pinfo, tree, hash_info);
else {
if ( pinfo->destport == TCP_PORT_SOCKS)
ptr = &pinfo->destport;
else
ptr = &pinfo->srcport;
*ptr = hash_info->port;
state_info->in_socks_dissector_flag = 1;
CLEANUP_PUSH(clear_in_socks_dissector_flag, state_info);
save_can_desegment = pinfo->can_desegment;
pinfo->can_desegment = pinfo->saved_can_desegment;
dissect_tcp_payload(tvb, pinfo, offset, tcpinfo->seq,
tcpinfo->nxtseq, pinfo->srcport, pinfo->destport,
tree, socks_tree, tcpd, tcpinfo);
pinfo->can_desegment = save_can_desegment;
CLEANUP_CALL_AND_POP;
*ptr = TCP_PORT_SOCKS;
}
}
static int
dissect_socks(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data) {
int offset = 0;
proto_tree *socks_tree = NULL;
proto_item *ti;
socks_hash_entry_t *hash_info;
conversation_t *conversation;
sock_state_t* state_info;
guint8 version;
struct tcpinfo *tcpinfo = (struct tcpinfo*)data;
state_info = (sock_state_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_socks, 0);
if (state_info == NULL) {
state_info = wmem_new(wmem_file_scope(), sock_state_t);
state_info->in_socks_dissector_flag = 0;
state_info->client = clientNoInit;
state_info->server = serverNoInit;
p_add_proto_data(wmem_file_scope(), pinfo, proto_socks, 0, state_info);
}
if (state_info->in_socks_dissector_flag)
return 0;
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conversation == NULL) {
version = tvb_get_guint8(tvb, offset);
if ((version != 4) && (version != 5))
return 0;
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
}
hash_info = (socks_hash_entry_t *)conversation_get_proto_data(conversation,proto_socks);
if (hash_info == NULL){
hash_info = wmem_new0(wmem_file_scope(), socks_hash_entry_t);
hash_info->start_done_frame = G_MAXINT;
hash_info->clientState = clientStart;
hash_info->serverState = serverStart;
hash_info->server_port = pinfo->destport;
hash_info->port = 0;
hash_info->version = tvb_get_guint8(tvb, offset);
conversation_add_proto_data(conversation, proto_socks, hash_info);
conversation_set_dissector(conversation, socks_handle);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Socks");
if (( hash_info->version == 4) || ( hash_info->version == 5)){
col_add_fstr(pinfo->cinfo, COL_INFO, "Version: %d",
hash_info->version);
}
else
col_set_str(pinfo->cinfo, COL_INFO, "Unknown");
if ( hash_info->command == PING_COMMAND)
col_append_str(pinfo->cinfo, COL_INFO, ", Ping Req");
if ( hash_info->command == TRACERT_COMMAND)
col_append_str(pinfo->cinfo, COL_INFO, ", Traceroute Req");
if ( hash_info->port != 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Remote Port: %u",
hash_info->port);
if ((!pinfo->fd->flags.visited) &&
(!((hash_info->clientState == clientDone) &&
(hash_info->serverState == serverDone)))) {
if (hash_info->server_port == pinfo->destport) {
if ((hash_info->clientState != clientError) &&
(hash_info->clientState != clientDone))
{
if ( hash_info->version == 4) {
state_machine_v4( hash_info, tvb, offset, pinfo);
} else if ( hash_info->version == 5) {
client_state_machine_v5( hash_info, tvb, offset, pinfo, TRUE);
}
}
} else {
if ((hash_info->serverState != serverError) &&
(hash_info->serverState != serverDone)) {
if ( hash_info->version == 4) {
state_machine_v4( hash_info, tvb, offset, pinfo);
} else if ( hash_info->version == 5) {
server_state_machine_v5( hash_info, tvb, offset, pinfo, TRUE);
}
}
}
if ((hash_info->clientState == clientDone) &&
(hash_info->serverState == serverDone)) {
hash_info->start_done_frame = pinfo->fd->num;
}
}
if (tree) {
ti = proto_tree_add_item( tree, proto_socks, tvb, offset, -1, ENC_NA );
socks_tree = proto_item_add_subtree(ti, ett_socks);
if (hash_info->server_port == pinfo->destport) {
if ( hash_info->version == 4) {
display_socks_v4(tvb, offset, pinfo, socks_tree, hash_info, state_info);
} else if ( hash_info->version == 5) {
client_display_socks_v5(tvb, offset, pinfo, socks_tree, hash_info, state_info);
}
} else {
if ( hash_info->version == 4) {
display_socks_v4(tvb, offset, pinfo, socks_tree, hash_info, state_info);
} else if ( hash_info->version == 5) {
server_display_socks_v5(tvb, offset, pinfo, socks_tree, hash_info, state_info);
}
}
if ( pinfo->fd->num > hash_info->start_done_frame){
ti = proto_tree_add_uint( socks_tree, hf_socks_cmd, tvb, offset, 0, hash_info->command);
PROTO_ITEM_SET_GENERATED(ti);
if (hash_info->dst_addr.type == AT_IPv4) {
ti = proto_tree_add_ipv4( socks_tree, hf_socks_ip_dst, tvb,
offset, 0, *((const guint32*)hash_info->dst_addr.data));
PROTO_ITEM_SET_GENERATED(ti);
} else if (hash_info->dst_addr.type == AT_IPv6) {
ti = proto_tree_add_ipv6( socks_tree, hf_socks_ip6_dst, tvb,
offset, 0, (const struct e_in6_addr *)hash_info->dst_addr.data);
PROTO_ITEM_SET_GENERATED(ti);
}
if (( hash_info->command != PING_COMMAND) &&
( hash_info->command != TRACERT_COMMAND)){
ti = proto_tree_add_uint( socks_tree, hf_socks_dstport, tvb, offset, 0, hash_info->port);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
if ( pinfo->fd->num > hash_info->start_done_frame){
call_next_dissector(tvb, offset, pinfo, tree, socks_tree,
hash_info, state_info, tcpinfo);
}
return tvb_reported_length(tvb);
}
void
proto_register_socks( void){
static gint *ett[] = {
&ett_socks,
&ett_socks_auth,
&ett_socks_name
};
static hf_register_info hf[] = {
{ &hf_socks_ver,
{ "Version", "socks.version", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL
}
},
{ &hf_socks_ip_dst,
{ "Remote Address", "socks.dst", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_socks_ip6_dst,
{ "Remote Address(ipv6)", "socks.dstV6", FT_IPv6, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_gssapi_payload,
{ "GSSAPI data", "socks.gssapi.data", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_gssapi_command,
{ "SOCKS/GSSAPI command", "socks.gssapi.command", FT_UINT8, BASE_DEC,
VALS(gssapi_command_table), 0x0, NULL, HFILL
}
},
{ &hf_gssapi_length,
{ "SOCKS/GSSAPI data length", "socks.gssapi.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL
}
},
{ &hf_v4a_dns_name,
{ "SOCKS v4a Remote Domain Name", "socks.v4a_dns_name", FT_STRINGZ, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_dstport,
{ "Remote Port", "socks.dstport", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_cmd,
{ "Command", "socks.command", FT_UINT8,
BASE_DEC, VALS(cmd_strings), 0x0, NULL, HFILL
}
},
{ &hf_socks_results_4,
{ "Results(V4)", "socks.results", FT_UINT8,
BASE_DEC, VALS(reply_table_v4), 0x0, NULL, HFILL
}
},
{ &hf_socks_results_5,
{ "Results(V5)", "socks.results", FT_UINT8,
BASE_DEC, VALS(reply_table_v5), 0x0, NULL, HFILL
}
},
{ &hf_client_auth_method_count,
{ "Authentication Method Count", "socks.auth_method_count", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_client_auth_method,
{ "Method", "socks.auth_method", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_reserved,
{ "Reserved", "socks.reserved", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_reserved2,
{ "Reserved", "socks.reserved", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_client_port,
{ "Port", "socks.port", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_server_accepted_auth_method,
{ "Accepted Auth Method", "socks.auth_accepted_method", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_server_auth_status,
{ "Status", "socks.auth_status", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_server_remote_host_port,
{ "Remote Host Port", "socks.remote_host_port", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_username,
{ "User name", "socks.username", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_password,
{ "Password", "socks.password", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_remote_name,
{ "Remote name", "socks.remote_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_address_type,
{ "Address Type", "socks.address_type", FT_UINT8,
BASE_DEC, VALS(address_type_table), 0x0, NULL, HFILL
}
},
{ &hf_socks_fragment_number,
{ "Fragment Number", "socks.fragment_number", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_ping_end_command,
{ "Ping: End command", "socks.ping_end_command", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_ping_results,
{ "Ping Results", "socks.ping_results", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_traceroute_end_command,
{ "Traceroute: End command", "socks.traceroute_end_command", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{ &hf_socks_traceroute_results,
{ "Traceroute Results", "socks.traceroute_results", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
};
proto_socks = proto_register_protocol ( "Socks Protocol", "Socks", "socks");
proto_register_field_array(proto_socks, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_socks(void) {
socks_udp_handle = create_dissector_handle(socks_udp_dissector, proto_socks);
socks_handle = new_create_dissector_handle(dissect_socks, proto_socks);
dissector_add_uint("tcp.port", TCP_PORT_SOCKS, socks_handle);
}
