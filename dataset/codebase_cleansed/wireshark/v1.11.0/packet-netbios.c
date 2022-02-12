void capture_netbios(packet_counts *ld)
{
ld->netbios++;
}
int
process_netbios_name(const guchar *name_ptr, char *name_ret, int name_ret_len)
{
int i;
int name_type = *(name_ptr + NETBIOS_NAME_LEN - 1);
guchar name_char;
static const char hex_digits[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
for (i = 0; i < NETBIOS_NAME_LEN - 1; i++) {
name_char = *name_ptr++;
if (name_char >= ' ' && name_char <= '~') {
if (--name_ret_len > 0)
*name_ret++ = name_char;
} else {
if (--name_ret_len > 0)
*name_ret++ = '<';
if (--name_ret_len > 0)
*name_ret++ = hex_digits[(name_char >> 4)];
if (--name_ret_len > 0)
*name_ret++ = hex_digits[(name_char & 0x0F)];
if (--name_ret_len > 0)
*name_ret++ = '>';
}
}
*name_ret = '\0';
name_ret--;
for (i = 0; i < NETBIOS_NAME_LEN - 1; i++) {
if (*name_ret != ' ') {
*(name_ret + 1) = 0;
break;
}
name_ret--;
}
return name_type;
}
int get_netbios_name( tvbuff_t *tvb, int offset, char *name_ret, int name_ret_len)
{
return process_netbios_name( tvb_get_ptr( tvb, offset, NETBIOS_NAME_LEN ), name_ret, name_ret_len);
}
const char *
netbios_name_type_descr(int name_type)
{
return val_to_str_const(name_type, nb_name_type_vals, "Unknown");
}
void netbios_add_name(const char* label, tvbuff_t *tvb, int offset,
proto_tree *tree)
{
proto_tree *field_tree;
proto_item *tf;
char name_str[(NETBIOS_NAME_LEN - 1)*4 + 1];
int name_type;
const char *name_type_str;
name_type = get_netbios_name( tvb, offset, name_str, (NETBIOS_NAME_LEN - 1)*4 + 1);
name_type_str = netbios_name_type_descr(name_type);
tf = proto_tree_add_text( tree, tvb, offset, NETBIOS_NAME_LEN,
"%s: %s<%02x> (%s)", label, name_str, name_type, name_type_str);
field_tree = proto_item_add_subtree( tf, ett_netb_name);
proto_tree_add_string_format( field_tree, hf_netb_nb_name, tvb, offset,
15, name_str, "%s", name_str);
proto_tree_add_uint_format( field_tree, hf_netb_nb_name_type, tvb, offset + 15, 1, name_type,
"0x%02x (%s)", name_type, name_type_str);
}
static void netbios_data_first_middle_flags( tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_item(tree, hf_netb_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_netb_flags);
proto_tree_add_item( field_tree, hf_netb_flags_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( field_tree, hf_netb_flags_ack_expected, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( field_tree, hf_netb_flags_recv_cont_req, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
static void netbios_data_only_flags( tvbuff_t *tvb, proto_tree *tree,
int offset)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_item(tree, hf_netb_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_netb_flags);
proto_tree_add_item( field_tree, hf_netb_flags_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( field_tree, hf_netb_flags_ack_with_data, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( field_tree, hf_netb_flags_ack_expected, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
static void netbios_add_ses_confirm_flags( tvbuff_t *tvb, proto_tree *tree,
int offset)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_item(tree, hf_netb_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
field_tree = proto_item_add_subtree( tf, ett_netb_flags);
proto_tree_add_item( field_tree, hf_netb_flags_send_no_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( field_tree, hf_netb_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
static void netbios_add_session_init_flags( tvbuff_t *tvb, proto_tree *tree,
int offset)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_item(tree, hf_netb_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_netb_flags);
proto_tree_add_item( field_tree, hf_netb_flags_send_no_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( field_tree, hf_netb_largest_frame, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item( field_tree, hf_netb_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
static void netbios_no_receive_flags( tvbuff_t *tvb, proto_tree *tree,
int offset)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_item(tree, hf_netbios_no_receive_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
field_tree = proto_item_add_subtree(tf, ett_netb_flags);
proto_tree_add_item(field_tree, hf_netbios_no_receive_flags_send_no_ack, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
static void nb_xmit_corrl( tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item( tree, hf_netb_xmit_corrl, tvb, offset + NB_XMIT_CORL,
2, ENC_LITTLE_ENDIAN);
}
static void nb_resp_corrl( tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item( tree, hf_netb_resp_corrl, tvb, offset + NB_RESP_CORL,
2, ENC_LITTLE_ENDIAN);
}
static void nb_call_name_type( tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item( tree, hf_netb_call_name_type, tvb, offset + NB_CALL_NAME_TYPE,
1, ENC_LITTLE_ENDIAN);
}
static guint8 nb_local_session( tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 local_session = tvb_get_guint8( tvb, offset + NB_LOCAL_SES);
proto_tree_add_uint( tree, hf_netb_local_ses_no, tvb, offset + NB_LOCAL_SES, 1,
local_session);
return local_session;
}
static guint8 nb_remote_session( tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 remote_session = tvb_get_guint8( tvb, offset + NB_RMT_SES);
proto_tree_add_uint( tree, hf_netb_remote_ses_no, tvb, offset + NB_RMT_SES, 1,
remote_session);
return remote_session;
}
static void nb_data1(int hf, tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item( tree, hf, tvb, offset + NB_DATA1, 1, ENC_LITTLE_ENDIAN);
}
static void nb_data2(int hf, tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_item( tree, hf, tvb, offset + NB_DATA2, 2, ENC_LITTLE_ENDIAN);
}
static void nb_resync_indicator( tvbuff_t *tvb, int offset, proto_tree *tree, const char *cmd_str)
{
guint16 resync_indicator = tvb_get_letohs( tvb, offset + NB_DATA2);
switch (resync_indicator) {
case 0x0000:
proto_tree_add_text(tree, tvb, offset + NB_DATA2, 2,
"Re-sync indicator: No re-sync");
break;
case 0x0001:
proto_tree_add_text(tree, tvb, offset + NB_DATA2, 2,
"Re-sync indicator: First '%s' following 'Receive Outstanding'", cmd_str);
break;
default:
proto_tree_add_text(tree, tvb, offset + NB_DATA2, 2,
"Re-sync indicator: 0x%04x", resync_indicator);
break;
}
}
static guint32
dissect_netb_unknown( tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree_add_text(tree, tvb, offset + NB_COMMAND + 1, -1,
"Unknown NetBIOS command data");
return 0;
}
static guint32
dissect_netb_add_group_name( tvbuff_t *tvb, int offset, proto_tree *tree)
{
nb_resp_corrl( tvb, offset, tree);
netbios_add_name("Group name to add", tvb, offset + NB_SENDER_NAME,
tree);
return 0;
}
static guint32
dissect_netb_add_name( tvbuff_t *tvb, int offset, proto_tree *tree)
{
nb_resp_corrl( tvb, offset, tree);
netbios_add_name("Name to add", tvb, offset + NB_SENDER_NAME, tree);
return 0;
}
static guint32
dissect_netb_name_in_conflict( tvbuff_t *tvb, int offset, proto_tree *tree)
{
netbios_add_name("Name In Conflict", tvb, offset + NB_RECVER_NAME,
tree);
netbios_add_name("Sender's Name", tvb, offset + NB_SENDER_NAME, tree);
return 0;
}
static guint32
dissect_netb_status_query( tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 status_request = tvb_get_guint8( tvb, offset + NB_DATA1);
switch (status_request) {
case 0:
proto_tree_add_text(tree, tvb, offset + NB_DATA1, 1,
"Status request: NetBIOS 1.x or 2.0");
break;
case 1:
proto_tree_add_text(tree, tvb, offset + NB_DATA1, 1,
"Status request: NetBIOS 2.1, initial status request");
break;
default:
proto_tree_add_text(tree, tvb, offset + NB_DATA1, 1,
"Status request: NetBIOS 2.1, %u names received so far",
status_request);
break;
}
nb_data2( hf_netb_status_buffer_len, tvb, offset, tree);
nb_resp_corrl( tvb, offset, tree);
netbios_add_name("Receiver's Name", tvb, offset + NB_RECVER_NAME, tree);
netbios_add_name("Sender's Name", tvb, offset + NB_SENDER_NAME, tree);
return 0;
}
static guint32
dissect_netb_terminate_trace( tvbuff_t *tvb _U_, int offset _U_, proto_tree *tree _U_)
{
return 0;
}
static guint32
dissect_netb_datagram( tvbuff_t *tvb, int offset, proto_tree *tree)
{
netbios_add_name("Receiver's Name", tvb, offset + NB_RECVER_NAME, tree);
if (tvb_memeql(tvb, offset + NB_SENDER_NAME, zeroes, 10) == 0) {
proto_tree_add_item(tree, hf_netb_datagram_mac,
tvb, offset + NB_SENDER_NAME + 10, 6, ENC_NA );
} else {
netbios_add_name("Sender's Name", tvb, offset + NB_SENDER_NAME,
tree);
}
return 0;
}
static guint32
dissect_netb_datagram_bcast( tvbuff_t *tvb, int offset, proto_tree *tree)
{
if (tvb_memeql(tvb, offset + NB_SENDER_NAME, zeroes, 10) == 0) {
proto_tree_add_item(tree, hf_netb_datagram_bcast_mac,
tvb, offset + NB_SENDER_NAME + 10, 6, ENC_NA );
} else {
netbios_add_name("Sender's Name", tvb, offset + NB_SENDER_NAME,
tree);
}
return 0;
}
static guint32
dissect_netb_name_query( tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 local_session_number = tvb_get_guint8( tvb, offset + NB_DATA2);
if (local_session_number == 0) {
proto_tree_add_text( tree, tvb, offset + NB_DATA2, 1,
"Local Session No.: 0 (FIND.NAME request)");
} else {
proto_tree_add_text( tree, tvb, offset + NB_DATA2, 1,
"Local Session No.: 0x%02x", local_session_number);
}
nb_call_name_type( tvb, offset, tree);
nb_resp_corrl( tvb, offset, tree);
netbios_add_name("Query Name", tvb, offset + NB_RECVER_NAME, tree);
if (local_session_number != 0) {
netbios_add_name("Sender's Name", tvb, offset + NB_SENDER_NAME,
tree);
}
return 0;
}
static guint32
dissect_netb_add_name_resp( tvbuff_t *tvb, int offset, proto_tree *tree)
{
nb_data1( hf_netb_status, tvb, offset, tree);
nb_data2( hf_netb_name_type, tvb, offset, tree);
nb_xmit_corrl( tvb, offset, tree);
netbios_add_name("Name to be added", tvb, offset + NB_RECVER_NAME,
tree);
netbios_add_name("Name to be added", tvb, offset + NB_SENDER_NAME,
tree);
return 0;
}
static guint32
dissect_netb_name_resp( tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 local_session_number = tvb_get_guint8( tvb, offset + NB_DATA2);
switch (local_session_number) {
case 0x00:
proto_tree_add_text( tree, tvb, offset + NB_DATA2, 1,
"State of name: No LISTEN pending, or FIND.NAME response");
break;
case 0xFF:
proto_tree_add_text( tree, tvb, offset + NB_DATA2, 1,
"State of name: LISTEN pending, but insufficient resources to establish session");
break;
default:
proto_tree_add_text( tree, tvb, offset + NB_DATA2, 1,
"Local Session No.: 0x%02x", local_session_number);
break;
}
nb_call_name_type( tvb, offset, tree);
nb_xmit_corrl( tvb, offset, tree);
if (local_session_number != 0x00 && local_session_number != 0xFF)
nb_resp_corrl(tvb, offset, tree);
netbios_add_name("Receiver's Name", tvb, offset + NB_RECVER_NAME, tree);
if (local_session_number != 0x00 && local_session_number != 0xFF) {
netbios_add_name("Sender's Name", tvb, offset + NB_SENDER_NAME,
tree);
}
return 0;
}
static guint32
dissect_netb_status_resp( tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 status_response = tvb_get_guint8( tvb, offset + NB_DATA1);
proto_item *td2;
proto_tree *data2_tree;
nb_call_name_type( tvb, offset, tree);
if (status_response == 0) {
proto_tree_add_text(tree, tvb, offset + NB_DATA1, 1,
"Status response: NetBIOS 1.x or 2.0");
} else {
proto_tree_add_text(tree, tvb, offset + NB_DATA1, 1,
"Status response: NetBIOS 2.1, %u names sent so far",
status_response);
}
td2 = proto_tree_add_item(tree, hf_netb_data2, tvb, offset + NB_DATA2, 2, ENC_LITTLE_ENDIAN);
data2_tree = proto_item_add_subtree(td2, ett_netb_status);
proto_tree_add_item(data2_tree, hf_netb_data2_frame, tvb, offset + NB_DATA2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(data2_tree, hf_netb_data2_user, tvb, offset + NB_DATA2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(data2_tree, hf_netb_data2_status, tvb, offset + NB_DATA2, 2, ENC_LITTLE_ENDIAN);
nb_xmit_corrl( tvb, offset, tree);
netbios_add_name("Receiver's Name", tvb, offset + NB_RECVER_NAME, tree);
netbios_add_name("Sender's Name", tvb, offset + NB_SENDER_NAME,
tree);
return 0;
}
static guint32
dissect_netb_data_ack( tvbuff_t* tvb, int offset, proto_tree *tree)
{
nb_xmit_corrl( tvb, offset, tree);
nb_remote_session( tvb, offset, tree);
nb_local_session( tvb, offset, tree);
return 0;
}
static guint32
dissect_netb_data_first_middle( tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 remote_session, local_session;
netbios_data_first_middle_flags( tvb, tree, offset + NB_FLAGS);
nb_resync_indicator( tvb, offset, tree, "DATA FIRST MIDDLE");
nb_xmit_corrl( tvb, offset, tree);
nb_resp_corrl( tvb, offset, tree);
remote_session = nb_remote_session( tvb, offset, tree);
local_session = nb_local_session( tvb, offset, tree);
return (remote_session << 8) + local_session;
}
static guint32
dissect_netb_data_only_last( tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 remote_session, local_session;
netbios_data_only_flags( tvb, tree, offset + NB_FLAGS);
nb_resync_indicator( tvb, offset, tree, "DATA ONLY LAST");
nb_xmit_corrl( tvb, offset, tree);
nb_resp_corrl( tvb, offset, tree);
remote_session = nb_remote_session( tvb, offset, tree);
local_session = nb_local_session( tvb, offset, tree);
return (remote_session << 8) + local_session;
}
static guint32
dissect_netb_session_confirm( tvbuff_t *tvb, int offset, proto_tree *tree)
{
netbios_add_ses_confirm_flags( tvb, tree, offset + NB_FLAGS);
nb_data2( hf_netb_max_data_recv_size, tvb, offset, tree);
nb_xmit_corrl( tvb, offset, tree);
nb_resp_corrl( tvb, offset, tree);
nb_remote_session( tvb, offset, tree);
nb_local_session( tvb, offset, tree);
return 0;
}
static guint32
dissect_netb_session_end( tvbuff_t *tvb, int offset, proto_tree *tree)
{
nb_data2( hf_netb_termination_indicator, tvb, offset, tree);
nb_remote_session( tvb, offset, tree);
nb_local_session( tvb, offset, tree);
return 0;
}
static guint32
dissect_netb_session_init( tvbuff_t *tvb, int offset, proto_tree *tree)
{
netbios_add_session_init_flags( tvb, tree, offset + NB_FLAGS);
nb_data2( hf_netb_max_data_recv_size, tvb, offset, tree);
nb_resp_corrl( tvb, offset, tree);
nb_xmit_corrl( tvb, offset, tree);
nb_remote_session( tvb, offset, tree);
nb_local_session( tvb, offset, tree);
return 0;
}
static guint32
dissect_netb_no_receive( tvbuff_t *tvb, int offset, proto_tree *tree)
{
netbios_no_receive_flags( tvb, tree, offset + NB_FLAGS);
nb_data2( hf_netb_num_data_bytes_accepted, tvb, offset, tree);
nb_remote_session( tvb, offset, tree);
nb_local_session( tvb, offset, tree);
return 0;
}
static guint32
dissect_netb_receive_outstanding( tvbuff_t *tvb, int offset, proto_tree *tree)
{
nb_data2( hf_netb_num_data_bytes_accepted, tvb, offset, tree);
nb_remote_session( tvb, offset, tree);
nb_local_session( tvb, offset, tree);
return 0;
}
static guint32
dissect_netb_receive_continue( tvbuff_t *tvb, int offset, proto_tree *tree)
{
nb_xmit_corrl( tvb, offset, tree);
nb_remote_session( tvb, offset, tree);
nb_local_session( tvb, offset, tree);
return 0;
}
static guint32
dissect_netb_session_alive( tvbuff_t *tvb, int offset, proto_tree *tree)
{
nb_remote_session( tvb, offset, tree);
nb_local_session( tvb, offset, tree);
return 0;
}
void
dissect_netbios_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!dissector_try_heuristic(netbios_heur_subdissector_list,
tvb, pinfo, tree, NULL))
call_dissector(data_handle,tvb, pinfo, tree);
}
static void
dissect_netbios(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *netb_tree = NULL;
proto_item *ti;
guint16 hdr_len, command;
const char *command_name;
char name[(NETBIOS_NAME_LEN - 1)*4 + 1];
int name_type;
guint16 session_id;
gboolean save_fragmented;
int len;
fragment_head *fd_head;
tvbuff_t *next_tvb;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NetBIOS");
if ( 0xefff != tvb_get_letohs(tvb, 2)){
++offset;
if ( 0xefff != tvb_get_letohs(tvb, 3)){
col_set_str( pinfo->cinfo, COL_INFO, "Bad packet, no 0xEFFF marker");
return;
}
}
hdr_len = tvb_get_letohs(tvb, offset + NB_LENGTH);
command = tvb_get_guint8( tvb, offset + NB_COMMAND);
command = MIN( command, sizeof( dissect_netb)/ sizeof(void *));
command_name = val_to_str(command, cmd_vals, "Unknown (0x%02x)");
switch ( command ) {
case NB_NAME_QUERY:
name_type = get_netbios_name( tvb, offset + 12, name, (NETBIOS_NAME_LEN - 1)*4 + 1);
col_add_fstr( pinfo->cinfo, COL_INFO, "%s for %s<%02x>", command_name, name, name_type);
break;
case NB_NAME_RESP:
case NB_ADD_NAME:
case NB_ADD_GROUP:
name_type = get_netbios_name( tvb, offset + 28, name, (NETBIOS_NAME_LEN - 1)*4 + 1);
col_add_fstr( pinfo->cinfo, COL_INFO, "%s - %s<%02x>", command_name, name, name_type);
break;
default:
col_add_str( pinfo->cinfo, COL_INFO, command_name);
break;
}
if ( tree) {
ti = proto_tree_add_item(tree, proto_netbios, tvb, 0, hdr_len, ENC_NA);
netb_tree = proto_item_add_subtree(ti, ett_netb);
proto_tree_add_uint_format(netb_tree, hf_netb_hdr_len, tvb, offset, 2, hdr_len,
"Length: %d bytes", hdr_len);
proto_tree_add_text(netb_tree, tvb, offset + 2, 2,
"Delimiter: EFFF (NetBIOS)");
proto_tree_add_uint(netb_tree, hf_netb_cmd, tvb, offset + NB_COMMAND, 1, command);
}
if ( command < sizeof( dissect_netb)/ sizeof(void *)) {
session_id = (dissect_netb[ command])( tvb, offset, netb_tree);
offset += hdr_len;
save_fragmented = pinfo->fragmented;
switch (command) {
case NB_DATAGRAM:
case NB_DATAGRAM_BCAST:
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_netbios_payload(next_tvb, pinfo, tree);
break;
case NB_DATA_FIRST_MIDDLE:
case NB_DATA_ONLY_LAST:
len = tvb_reported_length_remaining(tvb, offset);
if (netbios_defragment &&
tvb_bytes_exist(tvb, offset, len)) {
fd_head = fragment_add_seq_next(&netbios_reassembly_table,
tvb, offset,
pinfo, session_id, NULL,
len, command == NB_DATA_FIRST_MIDDLE);
if (fd_head != NULL) {
if (fd_head->next != NULL) {
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo,
next_tvb,
"Reassembled NetBIOS");
if (tree) {
proto_item *frag_tree_item;
show_fragment_seq_tree(fd_head,
&netbios_frag_items,
netb_tree, pinfo,
next_tvb, &frag_tree_item);
}
} else {
next_tvb = tvb_new_subset_remaining(tvb,
offset);
}
} else {
next_tvb = NULL;
}
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
}
if (next_tvb != NULL)
dissect_netbios_payload(next_tvb, pinfo, tree);
else {
next_tvb = tvb_new_subset_remaining (tvb, offset);
call_dissector(data_handle, next_tvb, pinfo,
tree);
}
break;
}
pinfo->fragmented = save_fragmented;
}
}
static void
netbios_init(void)
{
reassembly_table_init(&netbios_reassembly_table,
&addresses_reassembly_table_functions);
}
void proto_register_netbios(void)
{
static gint *ett[] = {
&ett_netb,
&ett_netb_name,
&ett_netb_flags,
&ett_netb_status,
&ett_netb_fragments,
&ett_netb_fragment,
};
static hf_register_info hf_netb[] = {
{ &hf_netb_cmd,
{ "Command", "netbios.command", FT_UINT8, BASE_HEX,
VALS(cmd_vals), 0x0, NULL, HFILL }},
{ &hf_netb_hdr_len,
{ "Header Length", "netbios.hdr_len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_xmit_corrl,
{ "Transmit Correlator", "netbios.xmit_corrl", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_resp_corrl,
{ "Response Correlator", "netbios.resp_corrl", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_call_name_type,
{ "Caller's Name Type", "netbios.call_name_type", FT_UINT8, BASE_HEX,
VALS(name_types), 0x0, NULL, HFILL }},
{ &hf_netb_nb_name_type,
{ "NetBIOS Name Type", "netbios.nb_name_type", FT_UINT8, BASE_HEX,
VALS(nb_name_type_vals), 0x0, NULL, HFILL }},
{ &hf_netb_nb_name,
{ "NetBIOS Name", "netbios.nb_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_version,
{ "NetBIOS Version", "netbios.version", FT_BOOLEAN, 8,
TFS( &netb_version_str), 0x01, NULL, HFILL }},
{ &hf_netbios_no_receive_flags,
{ "Flags", "netbios.no_receive_flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_netbios_no_receive_flags_send_no_ack,
{ "SEND.NO.ACK data received", "netbios.no_receive_flags.send_no_ack", FT_BOOLEAN, 8,
TFS( &tfs_no_yes), 0x02, NULL, HFILL }},
{ &hf_netb_largest_frame,
{ "Largest Frame", "netbios.largest_frame", FT_UINT8, BASE_DEC,
VALS(max_frame_size_vals), 0x0E, NULL, HFILL }},
{ &hf_netb_status_buffer_len,
{ "Length of status buffer", "netbios.status_buffer_len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_status,
{ "Status", "netbios.status", FT_UINT8, BASE_DEC,
VALS(status_vals), 0x0, NULL, HFILL }},
{ &hf_netb_name_type,
{ "Name type", "netbios.name_type", FT_UINT16, BASE_DEC,
VALS(name_types), 0x0, NULL, HFILL }},
{ &hf_netb_max_data_recv_size,
{ "Maximum data receive size", "netbios.max_data_recv_size", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_termination_indicator,
{ "Termination indicator", "netbios.termination_indicator", FT_UINT16, BASE_HEX,
VALS(termination_indicator_vals), 0x0, NULL, HFILL }},
{ &hf_netb_num_data_bytes_accepted,
{ "Number of data bytes accepted", "netbios.num_data_bytes_accepted", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_local_ses_no,
{ "Local Session No.", "netbios.local_session", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_remote_ses_no,
{ "Remote Session No.", "netbios.remote_session", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_flags,
{ "Flags", "netbios.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_flags_send_no_ack,
{ "Handle SEND.NO.ACK", "netbios.flags.send_no_ack", FT_BOOLEAN, 8,
TFS( &tfs_yes_no), 0x80, NULL, HFILL }},
{ &hf_netb_flags_ack,
{ "Acknowledge", "netbios.flags.ack", FT_BOOLEAN, 8,
TFS( &tfs_set_notset), 0x08, NULL, HFILL }},
{ &hf_netb_flags_ack_with_data,
{ "Acknowledge with data", "netbios.flags.ack_with_data", FT_BOOLEAN, 8,
TFS( &flags_allowed), 0x04, NULL, HFILL }},
{ &hf_netb_flags_ack_expected,
{ "Acknowledge expected", "netbios.flags.ack_expected", FT_BOOLEAN, 8,
TFS( &tfs_yes_no), 0x02, NULL, HFILL }},
{ &hf_netb_flags_recv_cont_req,
{ "RECEIVE_CONTINUE requested", "netbios.flags.recv_cont_req", FT_BOOLEAN, 8,
TFS( &tfs_yes_no), 0x01, NULL, HFILL }},
{ &hf_netb_data2,
{ "DATA2 value", "netbios.data2", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_data2_frame,
{ "Data length exceeds maximum frame size", "netbios.data2.frame", FT_BOOLEAN, 16,
TFS(&tfs_yes_no), 0x8000, NULL, HFILL }},
{ &hf_netb_data2_user,
{ "Data length exceeds user's buffer", "netbios.data2.user", FT_BOOLEAN, 16,
TFS(&tfs_yes_no), 0x4000, NULL, HFILL }},
{ &hf_netb_data2_status,
{ "Status data length", "netbios.data2.status", FT_UINT16, BASE_DEC,
NULL, 0x3FFF, NULL, HFILL }},
{ &hf_netb_datagram_mac,
{ "Sender's MAC Address", "netbios.datagram_mac", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_datagram_bcast_mac,
{ "Sender's Node Address", "netbios.datagram_bcast_mac", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_fragment_overlap,
{ "Fragment overlap", "netbios.fragment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment overlaps with other fragments", HFILL }},
{ &hf_netb_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "netbios.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Overlapping fragments contained conflicting data", HFILL }},
{ &hf_netb_fragment_multiple_tails,
{ "Multiple tail fragments found", "netbios.fragment.multipletails",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Several tails were found when defragmenting the packet", HFILL }},
{ &hf_netb_fragment_too_long_fragment,
{ "Fragment too long", "netbios.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment contained data past end of packet", HFILL }},
{ &hf_netb_fragment_error,
{ "Defragmentation error", "netbios.fragment.error", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "Defragmentation error due to illegal fragments", HFILL }},
{ &hf_netb_fragment_count,
{ "Fragment count", "netbios.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_fragment,
{ "NetBIOS Fragment", "netbios.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_fragments,
{ "NetBIOS Fragments", "netbios.fragments", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_netb_reassembled_length,
{"Reassembled NetBIOS length", "netbios.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x0, "The total length of the reassembled payload", HFILL }},
};
module_t *netbios_module;
proto_netbios = proto_register_protocol("NetBIOS", "NetBIOS", "netbios");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_netbios, hf_netb, array_length(hf_netb));
register_heur_dissector_list("netbios", &netbios_heur_subdissector_list);
netbios_module = prefs_register_protocol(proto_netbios, NULL);
prefs_register_bool_preference(netbios_module, "defragment",
"Reassemble fragmented NetBIOS messages spanning multiple frames",
"Whether the NetBIOS dissector should defragment messages spanning multiple frames",
&netbios_defragment);
register_init_routine(netbios_init);
}
void
proto_reg_handoff_netbios(void)
{
dissector_handle_t netbios_handle;
netbios_handle = create_dissector_handle(dissect_netbios,
proto_netbios);
dissector_add_uint("llc.dsap", SAP_NETBIOS, netbios_handle);
data_handle = find_dissector("data");
}
