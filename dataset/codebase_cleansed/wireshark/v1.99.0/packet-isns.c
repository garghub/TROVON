static int
dissect_isns_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint16 function_id;
guint packet_len;
proto_item *ti;
proto_tree *isns_tree;
guint16 flags;
proto_tree *tt = NULL;
proto_item *tpayload;
static const int * isns_flags[] = {
&hf_isns_client,
&hf_isns_server,
&hf_isns_auth,
&hf_isns_replace,
&hf_isns_last_pdu,
&hf_isns_first_pdu,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "iSNS");
col_clear(pinfo->cinfo, COL_INFO);
function_id = tvb_get_ntohs(tvb, offset + 2);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str_ext(function_id, &isns_function_ids_ext,
"Unknown function ID 0x%04x"));
ti = proto_tree_add_item(tree, proto_isns, tvb, 0, -1, ENC_NA);
isns_tree = proto_item_add_subtree(ti, ett_isns);
proto_tree_add_item(isns_tree, hf_isns_version, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(isns_tree, hf_isns_function_id, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(isns_tree, hf_isns_pdu_length, tvb, offset+4, 2, ENC_BIG_ENDIAN);
flags = tvb_get_ntohs(tvb, offset + 6);
proto_tree_add_bitmask(isns_tree, tvb, offset+6, hf_isns_flags, ett_isns_flags, isns_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(isns_tree, hf_isns_transaction_id, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(isns_tree, hf_isns_sequence_id, tvb, offset+10, 2, ENC_BIG_ENDIAN);
tpayload = proto_tree_add_item(isns_tree, hf_isns_payload, tvb, offset+12, -1, ENC_NA);
tt = proto_item_add_subtree(tpayload, ett_isns_payload);
offset += ISNS_HEADER_SIZE;
switch (function_id)
{
case ISNS_FUNC_HEARTBEAT:
proto_tree_add_item(tt,hf_isns_heartbeat_ipv6_addr, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tt,hf_isns_heartbeat_tcp_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tt,hf_isns_heartbeat_udp_port, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tt,hf_isns_heartbeat_interval, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tt,hf_isns_heartbeat_counter, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case ISNS_FUNC_RSP_DEVATTRREG:
case ISNS_FUNC_RSP_DEVATTRQRY:
case ISNS_FUNC_RSP_DEVGETNEXT:
case ISNS_FUNC_RSP_DEREGDEV:
case ISNS_FUNC_RSP_SCNREG:
case ISNS_FUNC_RSP_SCNDEREG:
case ISNS_FUNC_RSP_SCNEVENT:
case ISNS_FUNC_RSP_SCN:
case ISNS_FUNC_RSP_DDREG:
case ISNS_FUNC_RSP_DDDEREG:
case ISNS_FUNC_RSP_DDSREG:
case ISNS_FUNC_RSP_DDSDEREG:
case ISNS_FUNC_RSP_ESI:
case ISNS_FUNC_RSP_RQSTDOMID:
case ISNS_FUNC_RSP_RLSEDOMID:
case ISNS_FUNC_RSP_GETDOMID:
if(flags&ISNS_FLAGS_FIRST_PDU){
proto_tree_add_item(tt,hf_isns_resp_errorcode, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (tvb_reported_length_remaining(tvb, offset) == 0)
return tvb_length(tvb);
case ISNS_FUNC_DEVATTRREG:
case ISNS_FUNC_DEVATTRQRY:
case ISNS_FUNC_DEVGETNEXT:
case ISNS_FUNC_DEREGDEV:
case ISNS_FUNC_SCNREG:
case ISNS_FUNC_SCNDEREG:
case ISNS_FUNC_SCNEVENT:
case ISNS_FUNC_SCN:
case ISNS_FUNC_DDREG:
case ISNS_FUNC_DDDEREG:
case ISNS_FUNC_DDSREG:
case ISNS_FUNC_DDSDEREG:
case ISNS_FUNC_ESI:
case ISNS_FUNC_RQSTDOMID:
case ISNS_FUNC_RLSEDOMID:
case ISNS_FUNC_GETDOMID:
default:
if(!(flags&ISNS_FLAGS_FIRST_PDU)){
proto_tree_add_expert(tt, pinfo, &ei_isns_not_first_pdu, tvb, offset, -1);
return tvb_length(tvb);
}
packet_len = tvb_reported_length(tvb);
while( offset < packet_len )
{
offset = AddAttribute(pinfo, tvb, tt, offset, function_id);
}
}
return tvb_length(tvb);
}
static guint
get_isns_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 isns_len;
isns_len = tvb_get_ntohs(tvb, offset+4);
return (isns_len+ISNS_HEADER_SIZE);
}
static int
dissect_isns_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint length = tvb_length(tvb);
guint16 isns_protocol_version;
guint16 function_id;
if (length < ISNS_HEADER_SIZE) {
return 0;
}
isns_protocol_version = tvb_get_ntohs(tvb, 0);
if (isns_protocol_version != ISNS_PROTO_VER)
return 0;
function_id = tvb_get_ntohs(tvb, 2);
if (try_val_to_str_ext(function_id, &isns_function_ids_ext) == NULL) {
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, isns_desegment, ISNS_HEADER_SIZE, get_isns_pdu_len,
dissect_isns_pdu, data);
return length;
}
static int
dissect_isns_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint length = tvb_length(tvb);
guint16 isns_protocol_version;
guint16 function_id;
if (length < ISNS_HEADER_SIZE) {
return 0;
}
isns_protocol_version = tvb_get_ntohs(tvb, 0);
if (isns_protocol_version != ISNS_PROTO_VER)
return 0;
function_id = tvb_get_ntohs(tvb, 2);
if (try_val_to_str_ext(function_id, &isns_function_ids_ext) == NULL) {
return 0;
}
dissect_isns_pdu(tvb, pinfo, tree, data);
return length;
}
static guint
dissect_isns_attr_ip_address(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len)
{
if(parent_tree) {
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset + 8, len, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_isns_attribute);
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return offset+8+len;
}
static guint
dissect_isns_attr_string(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len)
{
if(parent_tree){
proto_item *item;
proto_tree *tree;
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset + 8, len, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_isns_attribute);
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return offset+8+len;
}
static guint
dissect_isns_attr_integer(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len, guint16 function_id)
{
if (parent_tree){
proto_item *item;
proto_tree *tree;
if(len){
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset + 8, len, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_isns_attribute);
} else if((tag==ISNS_ATTR_TAG_PORTAL_GROUP_TAG)&&((function_id==ISNS_FUNC_DEVATTRREG)||(function_id==ISNS_FUNC_RSP_DEVATTRREG))){
item = proto_tree_add_uint_format_value(parent_tree, hf_isns_portal_group_tag, tvb, offset, 8, 0, "<NULL>");
tree = proto_item_add_subtree(item, ett_isns_attribute);
} else {
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 8, ett_isns_attribute, NULL, "Oops, you surprised me here. a 0 byte integer.");
}
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return offset+8+len;
}
static guint
dissect_isns_attr_port(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len,
guint16 isns_port_type, packet_info *pinfo)
{
guint16 port = tvb_get_ntohs(tvb, offset + 10);
guint16 isudp = tvb_get_ntohs(tvb, offset + 8)&0x01;
conversation_t *conversation;
if(parent_tree){
proto_item *tree;
proto_item *item;
item = proto_tree_add_uint(parent_tree, hf_index, tvb, offset+8, 4, port);
tree = proto_item_add_subtree(item, ett_isns_port);
proto_tree_add_boolean(tree, hf_isns_port_type, tvb, offset+8, 2, isudp);
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
if ((isns_port_type == ISNS_ESI_PORT) || (isns_port_type == ISNS_SCN_PORT)) {
if (isudp) {
conversation = find_conversation (pinfo->fd->num, &pinfo->src, &pinfo->dst, PT_UDP,
port, 0, NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new (pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_UDP, port, 0, NO_PORT2_FORCE);
conversation_set_dissector (conversation, isns_udp_handle);
}
}
else {
conversation = find_conversation (pinfo->fd->num, &pinfo->src, &pinfo->dst, PT_TCP,
port, 0, NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new (pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_TCP, port, 0, NO_PORT2_FORCE);
conversation_set_dissector (conversation, isns_tcp_handle);
}
}
}
return offset+8+len;
}
static guint
dissect_isns_attr_none(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len)
{
if(parent_tree){
proto_item *tree;
proto_item *item;
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset, 8, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_isns_port);
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return offset+8+len;
}
static guint
dissect_isns_attr_not_decoded_yet(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len)
{
if(parent_tree){
proto_item *tree;
proto_item *item;
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset + 8, len, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_isns_port);
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return offset+8+len;
}
static guint
dissect_isns_attr_iscsi_node_type(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len)
{
if(parent_tree){
proto_item *item;
proto_tree *tree;
guint32 node_type = tvb_get_ntohl(tvb, offset + 8);
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset + 8, len, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_isns_attribute);
proto_tree_add_boolean(tree, hf_isns_isnt_control, tvb, offset+8, 4, node_type);
if(node_type&0x00000004){
proto_item_append_text(item, " Control");
}
proto_tree_add_boolean(tree, hf_isns_isnt_initiator, tvb, offset+8, 4, node_type);
if(node_type&0x00000002){
proto_item_append_text(item, " Initiator");
}
proto_tree_add_boolean(tree, hf_isns_isnt_target, tvb, offset+8, 4, node_type);
if(node_type&0x00000001){
proto_item_append_text(item, " Target");
}
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return offset+8+len;
}
static guint
dissect_isns_attr_portal_security_bitmap(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len)
{
if(parent_tree){
proto_item *item;
proto_tree *tree;
guint32 psb = tvb_get_ntohl(tvb, offset + 8);
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset + 8, len, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_isns_attribute);
proto_tree_add_boolean(tree, hf_isns_psb_tunnel_mode, tvb, offset+8, 4, psb);
proto_tree_add_boolean(tree, hf_isns_psb_transport_mode, tvb, offset+8, 4, psb);
proto_tree_add_boolean(tree, hf_isns_psb_pfs, tvb, offset+8, 4, psb);
proto_tree_add_boolean(tree, hf_isns_psb_aggressive_mode, tvb, offset+8, 4, psb);
proto_tree_add_boolean(tree, hf_isns_psb_main_mode, tvb, offset+8, 4, psb);
proto_tree_add_boolean(tree, hf_isns_psb_ike_ipsec, tvb, offset+8, 4, psb);
proto_tree_add_boolean(tree, hf_isns_psb_bitmap, tvb, offset+8, 4, psb);
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return offset+8+len;
}
static guint
dissect_isns_attr_scn_bitmap(tvbuff_t *tvb, guint offset, proto_tree *parent_tree, int hf_index, guint32 tag, guint32 len)
{
if(parent_tree){
proto_item *item;
proto_tree *tree;
guint32 scn_bitmap = tvb_get_ntohl(tvb, offset + 8);
item = proto_tree_add_item(parent_tree, hf_index, tvb, offset + 8, len, ENC_BIG_ENDIAN);
tree = proto_item_add_subtree(item, ett_isns_attribute);
proto_tree_add_boolean(tree, hf_isns_scn_bitmap_initiator_and_self_information_only, tvb, offset+8, 4, scn_bitmap);
proto_tree_add_boolean(tree, hf_isns_scn_bitmap_target_and_self_information_only, tvb, offset+8, 4, scn_bitmap);
proto_tree_add_boolean(tree, hf_isns_scn_bitmap_management_registration_scn, tvb, offset+8, 4, scn_bitmap);
proto_tree_add_boolean(tree, hf_isns_scn_bitmap_object_removed, tvb, offset+8, 4, scn_bitmap);
proto_tree_add_boolean(tree, hf_isns_scn_bitmap_object_added, tvb, offset+8, 4, scn_bitmap);
proto_tree_add_boolean(tree, hf_isns_scn_bitmap_object_updated, tvb, offset+8, 4, scn_bitmap);
proto_tree_add_boolean(tree, hf_isns_scn_bitmap_dd_dds_member_removed, tvb, offset+8, 4, scn_bitmap);
proto_tree_add_boolean(tree, hf_isns_scn_bitmap_dd_dds_member_added, tvb, offset+8, 4, scn_bitmap);
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return offset+8+len;
}
static guint
AddAttribute(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree, guint offset,
guint16 function_id)
{
guint32 tag,len;
tag = tvb_get_ntohl(tvb, offset);
len = tvb_get_ntohl(tvb, offset + 4);
if (len == 0) {
if (tree) {
proto_tree_add_uint(tree, hf_isns_attr_tag, tvb, offset, 4, tag);
proto_tree_add_uint(tree, hf_isns_attr_len, tvb, offset+4, 4, len);
}
return (offset+8);
}
tvb_ensure_bytes_exist(tvb, offset, len+8);
switch( tag )
{
case ISNS_ATTR_TAG_DELIMITER:
dissect_isns_attr_none(tvb, offset, tree, hf_isns_delimiter, tag, len);
break;
case ISNS_ATTR_TAG_ENTITY_IDENTIFIER:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_entity_identifier, tag, len);
break;
case ISNS_ATTR_TAG_ENTITY_PROTOCOL:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_entity_protocol, tag, len, function_id);
break;
case ISNS_ATTR_TAG_MGMT_IP_ADDRESS:
if(len != 16) THROW(ReportedBoundsError);
dissect_isns_attr_ip_address(tvb, offset, tree, hf_isns_mgmt_ip_addr, tag, len);
break;
case ISNS_ATTR_TAG_TIMESTAMP:
if(len != 8) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_timestamp, tag, len, function_id);
break;
case ISNS_ATTR_TAG_PROTOCOL_VERSION_RANGE:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_REGISTRATION_PERIOD:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_registration_period, tag, len, function_id);
break;
case ISNS_ATTR_TAG_ENTITY_INDEX:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_entity_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_ENTITY_NEXT_INDEX:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_entity_next_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_ENTITY_ISAKMP_PHASE_1:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_ENTITY_CERTIFICATE:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_PORTAL_IP_ADDRESS:
switch(len){
case 64:
proto_tree_add_expert(tree, pinfo, &ei_isns_portal_ip_addr, tvb, offset, -1);
case 16:
dissect_isns_attr_ip_address(tvb, offset, tree, hf_isns_portal_ip_addr, tag, 16);
break;
default:
THROW(ReportedBoundsError);
}
break;
case ISNS_ATTR_TAG_PORTAL_PORT:
dissect_isns_attr_port(tvb, offset, tree, hf_isns_portal_port, tag, len, ISNS_OTHER_PORT, pinfo);
break;
case ISNS_ATTR_TAG_PORTAL_SYMBOLIC_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_portal_symbolic_name, tag, len);
break;
case ISNS_ATTR_TAG_ESI_INTERVAL:
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_esi_interval, tag, len, function_id);
break;
case ISNS_ATTR_TAG_ESI_PORT:
dissect_isns_attr_port(tvb, offset, tree, hf_isns_esi_port, tag, len, ISNS_ESI_PORT, pinfo);
break;
case ISNS_ATTR_TAG_PORTAL_INDEX:
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_portal_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_SCN_PORT:
dissect_isns_attr_port(tvb, offset, tree, hf_isns_scn_port, tag, len, ISNS_SCN_PORT, pinfo);
break;
case ISNS_ATTR_TAG_PORTAL_NEXT_INDEX:
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_portal_next_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_PORTAL_SECURITY_BITMAP:
dissect_isns_attr_portal_security_bitmap(tvb, offset, tree, hf_isns_psb, tag, len);
break;
case ISNS_ATTR_TAG_PORTAL_ISAKMP_PHASE_1:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_PORTAL_ISAKMP_PHASE_2:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_PORTAL_CERTIFICATE:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_ISCSI_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_iscsi_name, tag, len);
break;
case ISNS_ATTR_TAG_ISCSI_NODE_TYPE:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_iscsi_node_type(tvb, offset, tree, hf_isns_iscsi_node_type, tag, len);
break;
case ISNS_ATTR_TAG_ISCSI_ALIAS:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_iscsi_alias, tag, len);
break;
case ISNS_ATTR_TAG_ISCSI_SCN_BITMAP:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_scn_bitmap(tvb, offset, tree, hf_isns_scn_bitmap, tag, len);
break;
case ISNS_ATTR_TAG_ISCSI_NODE_INDEX:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_node_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_WWNN_TOKEN:
if(len != 8) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_wwnn_token, tag, len, function_id);
break;
case ISNS_ATTR_TAG_ISCSI_NODE_NEXT_INDEX:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_node_next_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_ISCSI_AUTH_METHOD:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_iscsi_auth_method, tag, len);
break;
case ISNS_ATTR_TAG_PG_ISCSI_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_pg_iscsi_name, tag, len);
break;
case ISNS_ATTR_TAG_PG_PORTAL_IP_ADDR:
switch(len){
case 64:
proto_tree_add_expert_format(tree, pinfo, &ei_isns_portal_ip_addr, tvb, offset, -1,
"Broken iSNS implementation. The PG_PORTAL_IP_ADDRESS tag should be 16 bytes in length");
case 16:
dissect_isns_attr_ip_address(tvb, offset, tree, hf_isns_pg_portal_ip_addr, tag, 16);
break;
default:
THROW(ReportedBoundsError);
}
break;
case ISNS_ATTR_TAG_PG_PORTAL_PORT:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_port(tvb, offset, tree, hf_isns_pg_portal_port, tag, len, ISNS_OTHER_PORT, pinfo);
break;
case ISNS_ATTR_TAG_PORTAL_GROUP_TAG:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_portal_group_tag, tag, len, function_id);
break;
case ISNS_ATTR_TAG_PORTAL_GROUP_INDEX:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_pg_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_PORTAL_GROUP_NEXT_INDEX:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_pg_next_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_FC_PORT_NAME_WWPN:
if(len != 8) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_fc_port_name_wwpn, tag, len, function_id);
break;
case ISNS_ATTR_TAG_PORT_ID:
if(len != 3) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_port_id, tag, len, function_id);
break;
case ISNS_ATTR_TAG_FC_PORT_TYPE:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_SYMBOLIC_PORT_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_symbolic_port_name, tag, len);
break;
case ISNS_ATTR_TAG_FABRIC_PORT_NAME:
if(len != 8) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_fabric_port_name, tag, len, function_id);
break;
case ISNS_ATTR_TAG_HARD_ADDRESS:
if(len != 3) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_hard_address, tag, len, function_id);
break;
case ISNS_ATTR_TAG_PORT_IP_ADDRESS:
if(len != 16) THROW(ReportedBoundsError);
dissect_isns_attr_ip_address(tvb, offset, tree, hf_isns_port_ip_addr, tag, len);
break;
case ISNS_ATTR_TAG_CLASS_OF_SERVICE:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_FC4_TYPES:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_FC4_DESCRIPTOR:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_fc4_descriptor, tag, len);
break;
case ISNS_ATTR_TAG_FC4_FEATURES:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_IFCP_SCN_BITMAP:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_PORT_ROLE:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_PERMANENT_PORT_NAME:
if(len != 8) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_permanent_port_name, tag, len, function_id);
break;
case ISNS_ATTR_TAG_FC4_TYPE_CODE:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_FC_NODE_NAME_WWNN:
if(len != 8) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_fc_node_name_wwnn, tag, len, function_id);
break;
case ISNS_ATTR_TAG_SYMBOLIC_NODE_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_symbolic_node_name, tag, len);
break;
case ISNS_ATTR_TAG_NODE_IP_ADDRESS:
if(len != 16) THROW(ReportedBoundsError);
dissect_isns_attr_ip_address(tvb, offset, tree, hf_isns_node_ip_addr, tag, len);
break;
case ISNS_ATTR_TAG_NODE_IPA:
if(len != 8) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_node_ipa, tag, len, function_id);
break;
case ISNS_ATTR_TAG_PROXY_ISCSI_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_proxy_iscsi_name, tag, len);
break;
case ISNS_ATTR_TAG_SWITCH_NAME:
if(len != 8) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_switch_name, tag, len, function_id);
break;
case ISNS_ATTR_TAG_PREFERRED_ID:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_preferred_id, tag, len, function_id);
break;
case ISNS_ATTR_TAG_ASSIGNED_ID:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_assigned_id, tag, len, function_id);
break;
case ISNS_ATTR_TAG_VIRTUAL_FABRIC_ID:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_virtual_fabric_id, tag, len);
break;
case ISNS_ATTR_TAG_VENDOR_OUI:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_vendor_oui, tag, len, function_id);
break;
case ISNS_ATTR_TAG_DD_SET_ID:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_dd_set_id, tag, len, function_id);
break;
case ISNS_ATTR_TAG_DD_SET_SYMBOLIC_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_dd_set_symbolic_name, tag, len);
break;
case ISNS_ATTR_TAG_DD_SET_STATUS:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_DD_SET_NEXT_ID:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_dd_set_next_id, tag, len, function_id);
break;
case ISNS_ATTR_TAG_DD_ID:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_dd_id, tag, len, function_id);
break;
case ISNS_ATTR_TAG_DD_SYMBOLIC_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_dd_symbolic_name, tag, len);
break;
case ISNS_ATTR_TAG_DD_MEMBER_ISCSI_INDEX:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_member_iscsi_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_DD_MEMBER_ISCSI_NAME:
dissect_isns_attr_string(tvb, offset, tree, hf_isns_dd_member_iscsi_name, tag, len);
break;
case ISNS_ATTR_TAG_DD_MEMBER_FC_PORT_NAME:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_member_fc_port_name, tag, len, function_id);
break;
case ISNS_ATTR_TAG_DD_MEMBER_PORTAL_INDEX:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_member_portal_index, tag, len, function_id);
break;
case ISNS_ATTR_TAG_DD_MEMBER_PORTAL_IP_ADDRESS:
if(len != 16) THROW(ReportedBoundsError);
dissect_isns_attr_ip_address(tvb, offset, tree, hf_isns_dd_member_portal_ip_addr, tag, len);
break;
case ISNS_ATTR_TAG_DD_MEMBER_PORTAL_PORT:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_port(tvb, offset, tree, hf_isns_dd_member_portal_port,
tag, len, ISNS_OTHER_PORT, pinfo);
break;
case ISNS_ATTR_TAG_DD_FEATURES:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
break;
case ISNS_ATTR_TAG_DD_ID_NEXT_ID:
if(len != 4) THROW(ReportedBoundsError);
dissect_isns_attr_integer(tvb, offset, tree, hf_isns_dd_id_next_id, tag, len, function_id);
break;
default:
dissect_isns_attr_not_decoded_yet(tvb, offset, tree, hf_isns_not_decoded_yet, tag, len);
}
return offset+len+8;
}
void proto_register_isns(void)
{
static hf_register_info hf[] = {
{ &hf_isns_version,
{ "iSNSP Version", "isns.PVer",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isns_function_id,
{ "Function ID", "isns.functionid",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &isns_function_ids_ext, 0,
NULL, HFILL}
},
{ &hf_isns_pdu_length,
{ "PDU Length", "isns.pdulength",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isns_flags,
{ "Flags", "isns.flags",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL}
},
{ &hf_isns_client,
{ "Client", "isns.flags.client",
FT_BOOLEAN, 16, TFS(&tfs_isns_flag_client), ISNS_FLAGS_CLIENT,
NULL, HFILL}
},
{ &hf_isns_server,
{ "Server", "isns.flags.server",
FT_BOOLEAN, 16, TFS(&tfs_isns_flag_server), ISNS_FLAGS_SERVER,
NULL, HFILL}
},
{ &hf_isns_auth,
{ "Auth", "isns.flags.authentication_block",
FT_BOOLEAN, 16, TFS(&tfs_isns_flag_auth), ISNS_FLAGS_AUTH,
"is iSNS Authentication Block present?", HFILL}
},
{ &hf_isns_replace,
{ "Replace", "isns.flags.replace",
FT_BOOLEAN, 16, TFS(&tfs_isns_flag_replace), ISNS_FLAGS_REPLACE,
NULL, HFILL}
},
{ &hf_isns_last_pdu,
{ "Last PDU", "isns.flags.lastpdu",
FT_BOOLEAN, 16, TFS(&tfs_isns_flag_last_pdu), ISNS_FLAGS_LAST_PDU,
NULL, HFILL}
},
{ &hf_isns_first_pdu,
{ "First PDU", "isns.flags.firstpdu",
FT_BOOLEAN, 16, TFS(&tfs_isns_flag_first_pdu), ISNS_FLAGS_FIRST_PDU,
NULL, HFILL }
},
{ &hf_isns_transaction_id,
{ "Transaction ID", "isns.transactionid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isns_sequence_id,
{ "Sequence ID", "isns.sequenceid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isns_entity_protocol,
{ "Entity Protocol", "isns.entity_protocol",
FT_UINT32, BASE_DEC, VALS(isns_entity_protocol), 0,
NULL, HFILL}
},
{ &hf_isns_dd_member_portal_port,
{ "DD Member Portal Port", "isns.dd_member_portal_port",
FT_UINT32, BASE_DEC, NULL, 0,
"TCP/UDP DD Member Portal Port", HFILL }
},
{ &hf_isns_iscsi_node_type,
{ "iSCSI Node Type", "isns.iscsi.node_type",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_isns_esi_port,
{ "ESI Port", "isns.esi_port",
FT_UINT32, BASE_DEC, NULL, 0,
"TCP/UDP ESI Port", HFILL }
},
{ &hf_isns_scn_port,
{ "SCN Port", "isns.scn_port",
FT_UINT32, BASE_DEC, NULL, 0,
"TCP/UDP SCN Port", HFILL }
},
{ &hf_isns_portal_port,
{ "Portal Port", "isns.portal_port",
FT_UINT32, BASE_DEC, NULL, 0,
"TCP/UDP Portal Port", HFILL }
},
{ &hf_isns_pg_portal_port,
{ "PG Portal Port", "isns.pg.portal_port",
FT_UINT32, BASE_DEC, NULL, 0,
"PG Portal TCP/UDP Port", HFILL }
},
{ &hf_isns_port_type,
{ "Port Type", "isns.port.port_type",
FT_BOOLEAN, 16, TFS(&tfs_isns_port_type), 0x01,
NULL, HFILL }
},
{ &hf_isns_psb,
{ "Portal Security Bitmap", "isns.psb",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_isns_psb_tunnel_mode,
{ "Tunnel Mode", "isns.psb.tunnel",
FT_BOOLEAN, 32, TFS(&tfs_isns_psb_tunnel_mode), 0x0040,
"Tunnel Mode Preferred", HFILL }
},
{ &hf_isns_psb_transport_mode,
{ "Transport Mode", "isns.psb.transport",
FT_BOOLEAN, 32, TFS(&tfs_isns_psb_transport_mode), 0x0020,
NULL, HFILL }
},
{ &hf_isns_psb_pfs,
{ "PFS", "isns.psb.pfs",
FT_BOOLEAN, 32, TFS(&tfs_isns_psb_pfs), 0x0010,
NULL, HFILL }
},
{ &hf_isns_psb_aggressive_mode,
{ "Aggressive Mode", "isns.psb.aggressive_mode",
FT_BOOLEAN, 32, TFS(&tfs_isns_psb_aggressive_mode), 0x0008,
NULL, HFILL }
},
{ &hf_isns_psb_main_mode,
{ "Main Mode", "isns.psb.main_mode",
FT_BOOLEAN, 32, TFS(&tfs_isns_psb_main_mode), 0x0004,
NULL, HFILL }
},
{ &hf_isns_psb_ike_ipsec,
{ "IKE/IPSec", "isns.psb.ike_ipsec",
FT_BOOLEAN, 32, TFS(&tfs_isns_psb_ike_ipsec), 0x0002,
NULL, HFILL }
},
{ &hf_isns_psb_bitmap,
{ "Bitmap", "isns.psb.bitmap",
FT_BOOLEAN, 32, TFS(&tfs_isns_psb_bitmap), 0x0001,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap,
{ "iSCSI SCN Bitmap", "isns.scn_bitmap",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap_initiator_and_self_information_only,
{ "Initiator And Self Information Only", "isns.scn_bitmap.initiator_and_self_information_only",
FT_BOOLEAN, 32, TFS(&tfs_isns_scn_bitmap_initiator_and_self_information_only), 0x0080,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap_target_and_self_information_only,
{ "Target And Self Information Only", "isns.scn_bitmap.target_and_self_information_only",
FT_BOOLEAN, 32, TFS(&tfs_isns_scn_bitmap_target_and_self_information_only), 0x0040,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap_management_registration_scn,
{ "Management Registration/SCN", "isns.scn_bitmap.management_registration_scn",
FT_BOOLEAN, 32, TFS(&tfs_isns_scn_bitmap_management_registration_scn), 0x0020,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap_object_removed,
{ "Object Removed", "isns.scn_bitmap.object_removed",
FT_BOOLEAN, 32, TFS(&tfs_isns_scn_bitmap_object_removed), 0x0010,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap_object_added,
{ "Object Added", "isns.scn_bitmap.object_added",
FT_BOOLEAN, 32, TFS(&tfs_isns_scn_bitmap_object_added), 0x0008,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap_object_updated,
{ "Object Updated", "isns.scn_bitmap.object_updated",
FT_BOOLEAN, 32, TFS(&tfs_isns_scn_bitmap_object_updated), 0x0004,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap_dd_dds_member_removed,
{ "DD/DDS Member Removed (Mgmt Reg/SCN only)", "isns.scn_bitmap.dd_dds_member_removed",
FT_BOOLEAN, 32, TFS(&tfs_isns_scn_bitmap_dd_dds_member_removed), 0x0002,
NULL, HFILL }
},
{ &hf_isns_scn_bitmap_dd_dds_member_added,
{ "DD/DDS Member Added (Mgmt Reg/SCN only)", "isns.scn_bitmap.dd_dds_member_added",
FT_BOOLEAN, 32, TFS(&tfs_isns_scn_bitmap_dd_dds_member_added), 0x0001,
NULL, HFILL }
},
{ &hf_isns_isnt_control,
{ "Control", "isns.isnt.control",
FT_BOOLEAN, 32, TFS(&tfs_isns_isnt_control), 0x0004,
NULL, HFILL }
},
{ &hf_isns_isnt_initiator,
{ "Initiator", "isns.isnt.initiator",
FT_BOOLEAN, 32, TFS(&tfs_isns_isnt_initiator), 0x0002,
NULL, HFILL }
},
{ &hf_isns_isnt_target,
{ "Target", "isns.isnt.target",
FT_BOOLEAN, 32, TFS(&tfs_isns_isnt_target), 0x0001,
NULL, HFILL }
},
{ &hf_isns_resp_errorcode,
{ "ErrorCode", "isns.errorcode",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &isns_errorcode_ext, 0,
"iSNS Response Error Code", HFILL}
},
{ &hf_isns_attr_tag,
{ "Attribute Tag", "isns.attr.tag",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &isns_attribute_tags_ext, 0,
NULL, HFILL}
},
{ &hf_isns_attr_len,
{ "Attribute Length", "isns.attr.len",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_isns_delimiter,
{ "Delimiter", "isns.delimiter",
FT_NONE, BASE_NONE, NULL,0,
NULL, HFILL}
},
{ &hf_isns_not_decoded_yet,
{ "Not Decoded Yet", "isns.not_decoded_yet",
FT_NONE, BASE_NONE, NULL, 0,
"This tag is not yet decoded by Wireshark", HFILL}
},
{ &hf_isns_heartbeat_ipv6_addr,
{ "Heartbeat Address (ipv6)", "isns.heartbeat.address",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Server IPv6 Address", HFILL }},
{ &hf_isns_heartbeat_tcp_port,
{ "Heartbeat TCP Port", "isns.heartbeat.tcpport",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Server TCP Port", HFILL }},
{ &hf_isns_heartbeat_udp_port,
{ "Heartbeat UDP Port", "isns.heartbeat.udpport",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Server UDP Port", HFILL }},
{ &hf_isns_heartbeat_interval,
{ "Heartbeat Interval (secs)", "isns.heartbeat.interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Server Heartbeat interval", HFILL }},
{ &hf_isns_heartbeat_counter,
{ "Heartbeat counter", "isns.heartbeat.counter",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Server Heartbeat Counter", HFILL }},
{ &hf_isns_iscsi_name,
{ "iSCSI Name", "isns.iscsi_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"iSCSI Name of device", HFILL }},
{ &hf_isns_dd_member_iscsi_name,
{ "DD Member iSCSI Name", "isns.dd_member.iscsi_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"DD Member iSCSI Name of device", HFILL }},
{ &hf_isns_virtual_fabric_id,
{ "Virtual Fabric ID", "isns.virtual_fabric_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_proxy_iscsi_name,
{ "Proxy iSCSI Name", "isns.proxy_iscsi_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_fc4_descriptor,
{ "FC4 Descriptor", "isns.fc4_descriptor",
FT_STRING, BASE_NONE, NULL, 0x0,
"FC4 Descriptor of this device", HFILL }},
{ &hf_isns_iscsi_auth_method,
{ "iSCSI Auth Method", "isns.iscsi_auth_method",
FT_STRING, BASE_NONE, NULL, 0x0,
"Authentication Method required by this device", HFILL }},
{ &hf_isns_iscsi_alias,
{ "iSCSI Alias", "isns.iscsi_alias",
FT_STRING, BASE_NONE, NULL, 0x0,
"iSCSI Alias of device", HFILL }},
{ &hf_isns_portal_symbolic_name,
{ "Portal Symbolic Name", "isns.portal.symbolic_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Symbolic name of this portal", HFILL }},
{ &hf_isns_dd_set_symbolic_name,
{ "DD Set Symbolic Name", "isns.dd_set.symbolic_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Symbolic name of this DD Set", HFILL }},
{ &hf_isns_dd_symbolic_name,
{ "DD Symbolic Name", "isns.dd.symbolic_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Symbolic name of this DD", HFILL }},
{ &hf_isns_symbolic_port_name,
{ "Symbolic Port Name", "isns.port.symbolic_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Symbolic name of this port", HFILL }},
{ &hf_isns_symbolic_node_name,
{ "Symbolic Node Name", "isns.node.symbolic_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Symbolic name of this node", HFILL }},
{ &hf_isns_entity_identifier,
{ "Entity Identifier", "isns.entity_identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
"Entity Identifier of this object", HFILL }},
{ &hf_isns_mgmt_ip_addr,
{ "Management IP Address", "isns.mgmt.ip_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Management IPv4/IPv6 Address", HFILL }},
{ &hf_isns_node_ip_addr,
{ "Node IP Address", "isns.node.ip_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Node IPv4/IPv6 Address", HFILL }},
{ &hf_isns_port_ip_addr,
{ "Port IP Address", "isns.port.ip_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Port IPv4/IPv6 Address", HFILL }},
{ &hf_isns_portal_ip_addr,
{ "Portal IP Address", "isns.portal.ip_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Portal IPv4/IPv6 Address", HFILL }},
{ &hf_isns_dd_member_portal_ip_addr,
{ "DD Member Portal IP Address", "isns.dd.member_portal.ip_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
"DD Member Portal IPv4/IPv6 Address", HFILL }},
{ &hf_isns_pg_iscsi_name,
{ "PG iSCSI Name", "isns.pg_iscsi_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_pg_portal_ip_addr,
{ "PG Portal IP Address", "isns.pg_portal.ip_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
"PG Portal IPv4/IPv6 Address", HFILL }},
{ &hf_isns_pg_index,
{ "PG Index", "isns.pg_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_pg_next_index,
{ "PG Next Index", "isns.pg_next_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_dd_id_next_id,
{ "DD ID Next ID", "isns.dd_id_next_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_member_iscsi_index,
{ "Member iSCSI Index", "isns.member_iscsi_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_member_portal_index,
{ "Member Portal Index", "isns.member_portal_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_member_fc_port_name,
{ "Member FC Port Name", "isns.member_fc_port_name",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_vendor_oui,
{ "Vendor OUI", "isns.vendor_oui",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_preferred_id,
{ "Preferred ID", "isns.preferred_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_dd_set_id,
{ "DD Set ID", "isns.dd_set_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_dd_id,
{ "DD ID", "isns.dd_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_port_id,
{ "Port ID", "isns.port_id",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_hard_address,
{ "Hard Address", "isns.hard_address",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_wwnn_token,
{ "WWNN Token", "isns.wwnn_token",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_fc_port_name_wwpn,
{ "FC Port Name WWPN", "isns.fc_port_name_wwpn",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_fc_node_name_wwnn,
{ "FC Node Name WWNN", "isns.fc_node_name_wwnn",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_node_ipa,
{ "Node IPA", "isns.node_ipa",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_fabric_port_name,
{ "Fabric Port Name", "isns.fabric_port_name",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_permanent_port_name,
{ "Permanent Port Name", "isns.permanent_port_name",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_switch_name,
{ "Switch Name", "isns.switch_name",
FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_dd_set_next_id,
{ "DD Set Next ID", "isns.dd_set_next_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_assigned_id,
{ "Assigned ID", "isns.assigned_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_node_index,
{ "Node Index", "isns.node.index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_node_next_index,
{ "Node Next Index", "isns.node.next_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Node INext index", HFILL }},
{ &hf_isns_portal_index,
{ "Portal Index", "isns.portal.index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_portal_next_index,
{ "Portal Next Index", "isns.portal.next_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_entity_index,
{ "Entity Index", "isns.entity.index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_isns_entity_next_index,
{ "Entity Next Index", "isns.entity.next_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Next Entity Index", HFILL }},
{ &hf_isns_timestamp,
{ "Timestamp", "isns.timestamp",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Timestamp in Seconds", HFILL }},
{ &hf_isns_esi_interval,
{ "ESI Interval", "isns.esi_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
"ESI Interval in Seconds", HFILL }},
{ &hf_isns_registration_period,
{ "Registration Period", "isns.registration_period",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Registration Period in Seconds", HFILL }},
{ &hf_isns_portal_group_tag,
{ "PG Tag", "isns.portal_group_tag",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Portal Group Tag", HFILL }},
{ &hf_isns_payload,
{ "Payload", "isns.payload",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
}
};
static gint *ett[] = {
&ett_isns,
&ett_isns_flags,
&ett_isns_payload,
&ett_isns_attribute,
&ett_isns_port,
&ett_isns_isnt
};
static ei_register_info ei[] = {
{ &ei_isns_portal_ip_addr,
{ "isns.portal.ip_address.malformed",
PI_MALFORMED, PI_ERROR,
"Broken iSNS implementation. The PORTAL_IP_ADDRESS tag should be 16 bytes in length", EXPFILL }},
{ &ei_isns_not_first_pdu,
{ "isns.not_first_pdu",
PI_PROTOCOL, PI_WARN,
"This is not the first PDU. The attributes are not decoded", EXPFILL }},
};
module_t *isns_module;
expert_module_t* expert_isns;
proto_isns = proto_register_protocol("iSNS",
"iSNS", "isns");
proto_register_field_array(proto_isns, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isns = expert_register_protocol(proto_isns);
expert_register_field_array(expert_isns, ei, array_length(ei));
isns_module = prefs_register_protocol(proto_isns, NULL);
prefs_register_bool_preference(
isns_module, "desegment",
"Reassemble iSNS messages spanning multiple TCP segments",
"Whether the iSNS dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&isns_desegment);
}
void
proto_reg_handoff_isns(void)
{
isns_tcp_handle = new_create_dissector_handle(dissect_isns_tcp,proto_isns);
isns_udp_handle = new_create_dissector_handle(dissect_isns_udp,proto_isns);
dissector_add_uint("tcp.port",ISNS_TCP_PORT,isns_tcp_handle);
dissector_add_uint("udp.port",ISNS_UDP_PORT,isns_udp_handle);
}
