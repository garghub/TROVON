static void msproxy_sub_dissector( tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree) {
guint32 *ptr;
redirect_entry_t *redirect_info;
conversation_t *conversation;
proto_tree *msp_tree;
proto_item *ti;
conversation = find_conversation( pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
DISSECTOR_ASSERT( conversation);
redirect_info = conversation_get_proto_data(conversation,
proto_msproxy);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MS Proxy");
if (check_col(pinfo->cinfo, COL_INFO))
col_set_str(pinfo->cinfo, COL_INFO,
(( redirect_info->proto == PT_TCP) ? "TCP stream" :
"UDP packets"));
if ( tree) {
ti = proto_tree_add_item( tree, proto_msproxy, tvb, 0, 0,
ENC_NA );
msp_tree = proto_item_add_subtree(ti, ett_msproxy);
proto_tree_add_uint( msp_tree, hf_msproxy_dstport, tvb, 0, 0,
redirect_info->remote_port);
proto_tree_add_ipv4( msp_tree, hf_msproxy_dstaddr, tvb, 0, 0,
redirect_info->remote_addr);
}
if ( pinfo->srcport == redirect_info->clnt_port)
ptr = &pinfo->destport;
else
ptr = &pinfo->srcport;
*ptr = redirect_info->remote_port;
if ( redirect_info->proto == PT_TCP)
decode_tcp_ports( tvb, 0, pinfo, tree, pinfo->srcport,
pinfo->destport, NULL);
else
decode_udp_ports( tvb, 0, pinfo, tree, pinfo->srcport,
pinfo->destport, -1);
*ptr = redirect_info->server_int_port;
}
static void add_msproxy_conversation( packet_info *pinfo,
hash_entry_t *hash_info){
conversation_t *conversation;
redirect_entry_t *new_conv_info;
if (pinfo->fd->flags.visited) {
return;
}
conversation = find_conversation( pinfo->fd->num, &pinfo->src,
&pinfo->dst, hash_info->proto, hash_info->server_int_port,
hash_info->clnt_port, 0);
if ( !conversation) {
conversation = conversation_new( pinfo->fd->num, &pinfo->src, &pinfo->dst,
hash_info->proto, hash_info->server_int_port,
hash_info->clnt_port, 0);
}
conversation_set_dissector(conversation, msproxy_sub_handle);
new_conv_info = se_alloc(sizeof(redirect_entry_t));
new_conv_info->remote_addr = hash_info->dst_addr;
new_conv_info->clnt_port = hash_info->clnt_port;
new_conv_info->remote_port = hash_info->dst_port;
new_conv_info->server_int_port = hash_info->server_int_port;
new_conv_info->proto = hash_info->proto;
conversation_add_proto_data(conversation, proto_msproxy,
new_conv_info);
}
static int display_application_name(tvbuff_t *tvb, int offset,
proto_tree *tree) {
int length;
length = tvb_strnlen( tvb, offset, 255);
proto_tree_add_text( tree, tvb, offset, length, "Application: %.*s",
length, tvb_get_ephemeral_string( tvb, offset, length));
return length;
}
static const char *get_msproxy_cmd_name( int cmd, int direction) {
switch (cmd){
case MSPROXY_HELLO_2:
case MSPROXY_HELLO: return "Hello";
case MSPROXY_USERINFO:
if ( direction == FROM_SERVER)
return "Hello Acknowledge";
else
return "User Info";
case MSPROXY_USERINFO_ACK: return "User Info Acknowledge";
case MSPROXY_AUTH: return "Authentication";
case MSPROXY_AUTH_1_ACK: return "Authentication Acknowledge";
case MSPROXY_AUTH_2: return "Authentication 2";
case MSPROXY_AUTH_2_ACK: return "Authentication 2 Acknowledge";
case MSPROXY_RESOLVE: return "Resolve";
case MSPROXY_RESOLVE_ACK: return "Resolve Acknowledge";
case MSPROXY_BIND: return "Bind";
case MSPROXY_TCP_BIND: return "TCP Bind";
case MSPROXY_TCP_BIND_ACK: return "TCP Bind Acknowledge";
case MSPROXY_LISTEN: return "Listen";
case MSPROXY_BINDINFO: return "Bind Info";
case MSPROXY_BINDINFO_ACK: return "Bind Info Acknowledge";
case MSPROXY_CONNECT: return "Connect";
case MSPROXY_CONNECT_ACK: return "Connect Acknowledge";
case MSPROXY_UDPASSOCIATE: return "UDP Associate";
case MSPROXY_UDP_BIND_REQ: return "UDP Bind";
case MSPROXY_UDPASSOCIATE_ACK: return "Bind or Associate Acknowledge";
case MSPROXY_CONNECTED: return "Connected";
case MSPROXY_SESSIONEND: return "Session End";
default: return "Unknown";
}
}
static void dissect_user_info_2(tvbuff_t *tvb, int offset,
proto_tree *tree) {
int length;
if ( tree) {
length = tvb_strnlen( tvb, offset, 255);
if (length == -1)
return;
proto_tree_add_text( tree, tvb, offset, length + 1,
"User name: %.*s", length,
tvb_get_ephemeral_string( tvb, offset, length));
offset += length + 2;
length = tvb_strnlen( tvb, offset, 255);
if (length == -1)
return;
proto_tree_add_text( tree, tvb, offset, length + 1,
"Application name: %.*s", length,
tvb_get_ephemeral_string( tvb, offset, length));
offset += length + 1;
length = tvb_strnlen( tvb, offset, 255);
if (length == -1)
return;
proto_tree_add_text( tree, tvb, offset, length + 1,
"Client computer name: %.*s", length,
tvb_get_ephemeral_string( tvb, offset, length));
}
}
static void dissect_msproxy_request_1(tvbuff_t *tvb, int offset,
proto_tree *tree) {
offset += 182;
dissect_user_info_2( tvb, offset, tree);
}
static void dissect_bind(tvbuff_t *tvb, int offset,
proto_tree *tree, hash_entry_t *conv_info) {
offset += 18;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_bindaddr, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_bindport, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 6;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_clntport, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
conv_info->clnt_port = tvb_get_ntohs( tvb, offset);
offset += 6;
if ( tree){
proto_tree_add_item( tree, hf_msproxy_boundport, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 82;
display_application_name( tvb, offset, tree);
}
}
static int dissect_auth(tvbuff_t *tvb, int offset,
proto_tree *tree) {
offset += 134;
if ( tree) {
proto_tree_add_text( tree, tvb, offset, 7, "NTLMSSP signature: %.7s",
tvb_get_ephemeral_string( tvb, offset, 7));
}
offset += 7;
return offset;
}
static void dissect_tcp_bind(tvbuff_t *tvb, int offset,
proto_tree *tree, hash_entry_t *conv_info) {
conv_info->proto = PT_TCP;
if ( tree) {
offset += 6;
proto_tree_add_item( tree, hf_msproxy_bind_id, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item( tree, hf_msproxy_boundport, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 96;
display_application_name( tvb, offset, tree);
}
}
static void dissect_request_connect(tvbuff_t *tvb, int offset,
proto_tree *tree, hash_entry_t *conv_info) {
conv_info->proto = PT_TCP;
offset += 20;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_dstport, tvb, offset, 2,
ENC_BIG_ENDIAN);
conv_info->dst_port = tvb_get_ntohs( tvb, offset);
offset += 2;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_dstaddr, tvb, offset, 4,
ENC_BIG_ENDIAN);
conv_info->dst_addr = tvb_get_ipv4( tvb, offset);
offset += 12;
conv_info->clnt_port = tvb_get_ntohs( tvb, offset);
if ( tree){
proto_tree_add_uint( tree, hf_msproxy_clntport, tvb, offset, 2,
conv_info->clnt_port);
offset += 84;
display_application_name( tvb, offset, tree);
}
}
static void dissect_bind_info_ack(tvbuff_t *tvb, int offset, proto_tree *tree) {
if ( tree){
offset += 6;
proto_tree_add_item( tree, hf_msproxy_bind_id, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 14;
proto_tree_add_item( tree, hf_msproxy_dstport, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item( tree, hf_msproxy_dstaddr, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 12;
proto_tree_add_item( tree, hf_msproxy_server_int_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item( tree, hf_msproxy_server_ext_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item( tree, hf_msproxy_server_ext_addr, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 78;
display_application_name( tvb, offset, tree);
}
}
static void dissect_request_resolve(tvbuff_t *tvb, int offset,
proto_tree *tree) {
proto_tree *name_tree;
proto_item *ti;
int length = tvb_get_guint8( tvb, offset);
if ( tree){
ti = proto_tree_add_text(tree, tvb, offset, length + 1,
"Host Name: %.*s", length,
tvb_get_ephemeral_string( tvb, offset + 18, length));
name_tree = proto_item_add_subtree(ti, ett_msproxy_name);
proto_tree_add_text( name_tree, tvb, offset, 1, "Length: %d",
length);
++offset;
offset += 17;
proto_tree_add_text( name_tree, tvb, offset, length, "String: %s",
tvb_get_ephemeral_string( tvb, offset, length));
}
}
static void dissect_udp_bind(tvbuff_t *tvb, int offset,
proto_tree *tree, hash_entry_t *conv_info) {
conv_info->proto = PT_UDP;
offset += 8;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_bind_id, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 12;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_dstport, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_dstaddr, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 96;
if ( tree)
display_application_name( tvb, offset, tree);
}
static void dissect_udp_assoc(tvbuff_t *tvb, int offset,
proto_tree *tree, hash_entry_t *conv_info) {
offset += 28;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_clntport, tvb, offset, 2,
ENC_BIG_ENDIAN);
conv_info->clnt_port = tvb_get_ntohs( tvb, offset);
offset += 90;
if ( tree)
display_application_name( tvb, offset, tree);
}
static void dissect_msproxy_request(tvbuff_t *tvb,
proto_tree *tree, hash_entry_t *conv_info) {
int offset = 0;
int cmd;
if ( tree) {
proto_tree_add_text( tree, tvb, offset, 4, "Client id: 0x%0x",
tvb_get_letohl( tvb, offset));
offset += 4;
proto_tree_add_text( tree, tvb, offset, 4, "Version: 0x%04x",
tvb_get_letohl( tvb, offset));
offset += 4;
proto_tree_add_text( tree, tvb, offset, 4, "Server id: 0x%0x",
tvb_get_letohl( tvb, offset));
offset += 4;
proto_tree_add_text( tree, tvb, offset, 1, "Server ack: %u",
tvb_get_guint8( tvb, offset));
offset += 4;
proto_tree_add_text( tree, tvb, offset, 1, "Sequence Number: %u",
tvb_get_guint8( tvb, offset));
offset += 8;
proto_tree_add_text( tree, tvb, offset, 4, "RWSP signature: %.4s",
tvb_get_ephemeral_string( tvb, offset, 4));
offset += 12;
}
else
offset += 36;
cmd = tvb_get_ntohs( tvb, offset);
if ( tree)
proto_tree_add_uint_format( tree, hf_msproxy_cmd, tvb, offset, 2,
cmd, "Command: 0x%02x (%s)", cmd,
get_msproxy_cmd_name( cmd, FROM_CLIENT));
offset += 2;
switch (cmd){
case MSPROXY_AUTH:
dissect_auth( tvb, offset, tree);
break;
case MSPROXY_BIND:
dissect_bind( tvb, offset, tree, conv_info);
break;
case MSPROXY_UDP_BIND_REQ:
dissect_udp_bind( tvb, offset, tree, conv_info);
break;
case MSPROXY_AUTH_2:
case MSPROXY_TCP_BIND:
dissect_tcp_bind( tvb, offset, tree, conv_info);
break;
case MSPROXY_RESOLVE:
dissect_request_resolve( tvb, offset, tree);
break;
case MSPROXY_CONNECT:
case MSPROXY_LISTEN:
dissect_request_connect( tvb, offset, tree,
conv_info);
break;
case MSPROXY_BINDINFO_ACK:
dissect_bind_info_ack( tvb, offset, tree);
break;
case MSPROXY_HELLO:
case MSPROXY_HELLO_2:
dissect_msproxy_request_1( tvb, offset, tree);
break;
case MSPROXY_UDPASSOCIATE:
dissect_udp_assoc( tvb, offset, tree, conv_info);
break;
default:
if ( tree)
proto_tree_add_text( tree, tvb, offset, 0,
"Unhandled request command (report this, please)");
}
}
static int dissect_hello_ack(tvbuff_t *tvb, int offset, proto_tree *tree) {
offset += 60;
if ( tree) {
proto_tree_add_item( tree, hf_msproxy_serverport, tvb, offset, 2,
ENC_BIG_ENDIAN);
}
offset += 2;
if ( tree) {
proto_tree_add_item( tree, hf_msproxy_serveraddr, tvb, offset, 4,
ENC_BIG_ENDIAN);
}
offset += 4;
return offset;
}
static int dissect_user_info_ack(tvbuff_t *tvb _U_, int offset,
proto_tree *tree _U_) {
offset += 18;
offset += 2;
return offset;
}
static void dissect_udpassociate_ack(tvbuff_t *tvb, int offset,
proto_tree *tree) {
offset += 6;
if ( tree) {
proto_tree_add_item( tree, hf_msproxy_bind_id, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 14;
proto_tree_add_item( tree, hf_msproxy_server_ext_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item( tree, hf_msproxy_server_ext_addr, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 96;
display_application_name( tvb, offset, tree);
}
}
static void dissect_auth_1_ack(tvbuff_t *tvb, int offset,
proto_tree *tree) {
offset += 134;
if ( tree) {
proto_tree_add_text( tree, tvb, offset, 7, "NTLMSSP signature: %.7s",
tvb_get_ephemeral_string( tvb, offset, 7));
offset += 48;
proto_tree_add_text( tree, tvb, offset, 255, "NT domain: %.255s",
tvb_get_ephemeral_string( tvb, offset, 255));
}
}
static int dissect_msproxy_response_4( tvbuff_t *tvb _U_, int offset,
proto_tree *tree _U_) {
offset += 134;
return offset;
}
static void dissect_connect_ack( tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, hash_entry_t *conv_info) {
offset += 20;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_server_int_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
conv_info->proto = PT_TCP;
conv_info->server_int_port = tvb_get_ntohs( tvb, offset);
offset += 2;
if ( tree){
proto_tree_add_item( tree, hf_msproxy_server_int_addr, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 14;
proto_tree_add_item( tree, hf_msproxy_server_ext_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item( tree, hf_msproxy_server_ext_addr, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 80;
display_application_name( tvb, offset, tree);
}
add_msproxy_conversation( pinfo, conv_info);
}
static void dissect_tcp_bind_ack( tvbuff_t *tvb, int offset, proto_tree *tree) {
if ( tree) {
offset += 6;
proto_tree_add_item( tree, hf_msproxy_bind_id, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item( tree, hf_msproxy_server_int_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 6;
proto_tree_add_item( tree, hf_msproxy_server_ext_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item( tree, hf_msproxy_server_ext_addr, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 88;
display_application_name( tvb, offset, tree);
}
}
static void dissect_bind_info( tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, hash_entry_t *conv_info) {
offset += 6;
if ( tree)
proto_tree_add_item( tree, hf_msproxy_bind_id, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 14;
conv_info->dst_port = tvb_get_ntohs( tvb, offset);
if ( tree)
proto_tree_add_uint( tree, hf_msproxy_dstport, tvb, offset, 2,
conv_info->dst_port);
offset += 2;
conv_info->dst_addr = tvb_get_ipv4( tvb, offset);
if ( tree)
proto_tree_add_item( tree, hf_msproxy_dstaddr, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 12;
conv_info->server_int_port = tvb_get_ntohs( tvb, offset);
if ( tree)
proto_tree_add_uint( tree, hf_msproxy_server_int_port, tvb,
offset, 2, conv_info->server_int_port);
offset += 4;
if ( tree) {
proto_tree_add_item( tree, hf_msproxy_server_ext_port, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item( tree, hf_msproxy_server_ext_addr, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 78;
display_application_name( tvb, offset, tree);
}
add_msproxy_conversation( pinfo, conv_info);
}
static void dissect_resolve(tvbuff_t *tvb, int offset, proto_tree *tree) {
if ( tree) {
int addr_offset;
addr_offset = tvb_get_guint8( tvb, offset);
proto_tree_add_text( tree, tvb, offset, 1, "Address offset: %d",
addr_offset);
++offset;
offset += 13;
offset += addr_offset;
proto_tree_add_item( tree, hf_msproxy_resolvaddr, tvb, offset, 4,
ENC_BIG_ENDIAN);
}
}
static void dissect_msproxy_response(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, hash_entry_t *conv_info) {
int offset = 0;
int cmd;
if ( tree) {
proto_tree_add_text( tree, tvb, offset, 4, "Client id: 0x%0x",
tvb_get_letohl( tvb, offset));
offset += 4;
proto_tree_add_text( tree, tvb, offset, 4, "Version: 0x%04x",
tvb_get_letohl( tvb, offset));
offset += 4;
proto_tree_add_text( tree, tvb, offset, 4, "Server id: 0x%04x",
tvb_get_letohl( tvb, offset));
offset += 4;
proto_tree_add_text( tree, tvb, offset, 1, "Client ack: 0x%02x",
tvb_get_guint8( tvb, offset));
offset += 4;
proto_tree_add_text( tree, tvb, offset, 1, "Sequence Number: 0x%02x",
tvb_get_guint8( tvb, offset));
offset += 8;
proto_tree_add_text( tree, tvb, offset, 4, "RWSP signature: %.4s",
tvb_get_ephemeral_string( tvb, offset, 4));
offset += 12;
}
else
offset += 36;
cmd = tvb_get_ntohs( tvb, offset);
if ( tree)
proto_tree_add_uint_format( tree, hf_msproxy_cmd, tvb, offset, 2,
cmd, "Command: 0x%02x (%s)", cmd,
get_msproxy_cmd_name( cmd, FROM_SERVER));
offset += 2;
switch (cmd) {
case MSPROXY_HELLO_ACK:
dissect_hello_ack( tvb, offset, tree);
break;
case MSPROXY_USERINFO_ACK:
dissect_user_info_ack( tvb, offset, tree);
break;
case MSPROXY_AUTH_1_ACK:
dissect_auth_1_ack( tvb, offset, tree);
break;
case MSPROXY_UDPASSOCIATE_ACK:
dissect_udpassociate_ack( tvb, offset, tree);
break;
case MSPROXY_AUTH_2_ACK:
case MSPROXY_AUTH_2_ACK2:
dissect_msproxy_response_4( tvb, offset, tree);
break;
case MSPROXY_TCP_BIND_ACK:
dissect_tcp_bind_ack( tvb, offset, tree);
break;
case MSPROXY_CONNECT_ACK:
dissect_connect_ack( tvb, offset, pinfo, tree,
conv_info);
break;
case MSPROXY_BINDINFO:
dissect_bind_info( tvb, offset, pinfo, tree, conv_info);
break;
case MSPROXY_RESOLVE_ACK:
dissect_resolve( tvb, offset, tree);
break;
case MSPROXY_CONNECT_AUTHFAILED:
case MSPROXY_BIND_AUTHFAILED:
proto_tree_add_text( tree, tvb, offset, 0, "No know information (help wanted)");
break;
default:
if (tree &&
(((cmd >> 8) == MSPROXY_CONNREFUSED) ||
((cmd >> 12) == MSPROXY_CONNREFUSED)))
proto_tree_add_text( tree, tvb, offset, 0,
"No know information (help wanted)");
else if ( tree)
proto_tree_add_text( tree, tvb, offset, 0,
"Unhandled response command (report this, please)");
}
}
static void dissect_msproxy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
proto_tree *msproxy_tree = NULL;
proto_item *ti;
unsigned int cmd;
hash_entry_t *hash_info;
conversation_t *conversation;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MSproxy");
col_clear(pinfo->cinfo, COL_INFO);
conversation = find_or_create_conversation(pinfo);
hash_info = conversation_get_proto_data(conversation, proto_msproxy);
if ( !hash_info) {
hash_info = se_alloc(sizeof(hash_entry_t));
conversation_add_proto_data(conversation, proto_msproxy,
hash_info);
}
if (check_col(pinfo->cinfo, COL_INFO)){
cmd = tvb_get_ntohs( tvb, 36);
if ( pinfo->srcport == UDP_PORT_MSPROXY)
col_add_fstr( pinfo->cinfo, COL_INFO, "Server message: %s",
get_msproxy_cmd_name( cmd, FROM_SERVER));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Client message: %s",
get_msproxy_cmd_name( cmd, FROM_CLIENT));
}
if (tree) {
ti = proto_tree_add_item( tree, proto_msproxy, tvb, 0, -1,
ENC_NA );
msproxy_tree = proto_item_add_subtree(ti, ett_msproxy);
}
if ( pinfo->srcport == UDP_PORT_MSPROXY)
dissect_msproxy_response( tvb, pinfo, msproxy_tree, hash_info);
else
dissect_msproxy_request( tvb, msproxy_tree, hash_info);
}
static void msproxy_reinit( void){
last_row = 0;
}
void
proto_register_msproxy( void){
static gint *ett[] = {
&ett_msproxy,
&ett_msproxy_name
};
static hf_register_info hf[] = {
{ &hf_msproxy_cmd,
{ "Command", "msproxy.command", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_dstaddr,
{ "Destination Address", "msproxy.dstaddr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_msproxy_srcport,
{ "Source Port", "msproxy.srcport", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_dstport,
{ "Destination Port", "msproxy.dstport", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_clntport,
{ "Client Port", "msproxy.clntport", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_server_ext_addr,
{ "Server External Address", "msproxy.server_ext_addr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_msproxy_server_ext_port,
{ "Server External Port", "msproxy.server_ext_port", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_server_int_addr,
{ "Server Internal Address", "msproxy.server_int_addr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_msproxy_server_int_port,
{ "Server Internal Port", "msproxy.server_int_port", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_serverport,
{ "Server Port", "msproxy.serverport", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_bindport,
{ "Bind Port", "msproxy.bindport", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_boundport,
{ "Bound Port", "msproxy.boundport", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_serveraddr,
{ "Server Address", "msproxy.serveraddr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_msproxy_bindaddr,
{ "Destination", "msproxy.bindaddr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL
}
},
{ &hf_msproxy_bind_id,
{ "Bound Port Id", "msproxy.bindid", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{ &hf_msproxy_resolvaddr,
{ "Address", "msproxy.resolvaddr", FT_IPv4, BASE_NONE, NULL,
0x0, NULL, HFILL
}
}
};
proto_msproxy = proto_register_protocol( "MS Proxy Protocol",
"MS Proxy", "msproxy");
proto_register_field_array(proto_msproxy, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine( &msproxy_reinit);
msproxy_sub_handle = create_dissector_handle(msproxy_sub_dissector,
proto_msproxy);
}
void
proto_reg_handoff_msproxy(void) {
dissector_handle_t msproxy_handle;
msproxy_handle = create_dissector_handle(dissect_msproxy,
proto_msproxy);
dissector_add_uint("udp.port", UDP_PORT_MSPROXY, msproxy_handle);
}
