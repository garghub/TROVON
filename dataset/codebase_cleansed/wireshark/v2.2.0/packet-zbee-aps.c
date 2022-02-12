static int
dissect_zbee_aps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tvbuff_t *payload_tvb = NULL;
dissector_handle_t profile_handle = NULL;
dissector_handle_t zcl_handle = NULL;
proto_tree *aps_tree;
proto_tree *field_tree;
proto_item *proto_root;
zbee_aps_packet packet;
zbee_nwk_packet *nwk;
guint8 fcf;
guint8 offset = 0;
static const int * frag_ack_flags[] = {
&hf_zbee_aps_block_ack1,
&hf_zbee_aps_block_ack2,
&hf_zbee_aps_block_ack3,
&hf_zbee_aps_block_ack4,
&hf_zbee_aps_block_ack5,
&hf_zbee_aps_block_ack6,
&hf_zbee_aps_block_ack7,
&hf_zbee_aps_block_ack8,
NULL
};
if (data == NULL)
return 0;
nwk = (zbee_nwk_packet *)data;
memset(&packet, 0, sizeof(zbee_aps_packet));
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_aps, tvb, offset, tvb_captured_length(tvb), "ZigBee Application Support Layer");
aps_tree = proto_item_add_subtree(proto_root, ett_zbee_aps);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee");
fcf = tvb_get_guint8(tvb, offset);
packet.type = zbee_get_bit_field(fcf, ZBEE_APS_FCF_FRAME_TYPE);
packet.delivery = zbee_get_bit_field(fcf, ZBEE_APS_FCF_DELIVERY_MODE);
packet.indirect_mode = zbee_get_bit_field(fcf, ZBEE_APS_FCF_INDIRECT_MODE);
packet.ack_format = zbee_get_bit_field(fcf, ZBEE_APS_FCF_ACK_FORMAT);
packet.security = zbee_get_bit_field(fcf, ZBEE_APS_FCF_SECURITY);
packet.ack_req = zbee_get_bit_field(fcf, ZBEE_APS_FCF_ACK_REQ);
packet.ext_header = zbee_get_bit_field(fcf, ZBEE_APS_FCF_EXT_HEADER);
proto_item_append_text(proto_root, " %s", val_to_str_const(packet.type, zbee_aps_frame_types, "Unknown Type"));
col_set_str(pinfo->cinfo, COL_INFO, "APS: ");
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet.type, zbee_aps_frame_types, "Unknown Frame Type"));
field_tree = proto_tree_add_subtree_format(aps_tree, tvb, offset, 1, ett_zbee_aps_fcf, NULL, "Frame Control Field: %s (0x%02x)",
val_to_str_const(packet.type, zbee_aps_frame_types, "Unknown"), fcf);
proto_tree_add_uint(field_tree, hf_zbee_aps_fcf_frame_type, tvb, offset, 1, fcf & ZBEE_APS_FCF_FRAME_TYPE);
proto_tree_add_uint(field_tree, hf_zbee_aps_fcf_delivery, tvb, offset, 1, fcf & ZBEE_APS_FCF_DELIVERY_MODE);
if (nwk->version >= ZBEE_VERSION_2007) {
if (packet.type == ZBEE_APS_FCF_ACK) {
proto_tree_add_boolean(field_tree, hf_zbee_aps_fcf_ack_format, tvb, offset, 1,
fcf & ZBEE_APS_FCF_ACK_FORMAT);
}
}
else {
if (packet.delivery == ZBEE_APS_FCF_INDIRECT) {
proto_tree_add_boolean(field_tree, hf_zbee_aps_fcf_indirect_mode, tvb, offset, 1,
fcf & ZBEE_APS_FCF_INDIRECT_MODE);
}
}
proto_tree_add_boolean(field_tree, hf_zbee_aps_fcf_security, tvb, offset, 1, fcf & ZBEE_APS_FCF_SECURITY);
proto_tree_add_boolean(field_tree, hf_zbee_aps_fcf_ack_req, tvb, offset, 1, fcf & ZBEE_APS_FCF_ACK_REQ);
proto_tree_add_boolean(field_tree, hf_zbee_aps_fcf_ext_header, tvb, offset, 1, fcf & ZBEE_APS_FCF_EXT_HEADER);
offset += 1;
switch (packet.type) {
case ZBEE_APS_FCF_DATA:
break;
case ZBEE_APS_FCF_ACK:
if ((nwk->version >= ZBEE_VERSION_2007) && (packet.ack_format)) {
goto dissect_zbee_aps_no_endpt;
}
break;
case ZBEE_APS_FCF_INTERPAN:
packet.dst_present = FALSE;
packet.src_present = FALSE;
break;
default:
case ZBEE_APS_FCF_CMD:
goto dissect_zbee_aps_no_endpt;
}
if (packet.type != ZBEE_APS_FCF_INTERPAN) {
if ((packet.delivery == ZBEE_APS_FCF_UNICAST) || (packet.delivery == ZBEE_APS_FCF_BCAST)) {
packet.dst_present = TRUE;
packet.src_present = TRUE;
}
else if ((packet.delivery == ZBEE_APS_FCF_INDIRECT) && (nwk->version <= ZBEE_VERSION_2004)) {
packet.dst_present = (!packet.indirect_mode);
packet.src_present = (packet.indirect_mode);
}
else if ((packet.delivery == ZBEE_APS_FCF_GROUP) && (nwk->version >= ZBEE_VERSION_2007)) {
packet.dst_present = FALSE;
packet.src_present = TRUE;
}
else {
expert_add_info(pinfo, proto_root, &ei_zbee_aps_invalid_delivery_mode);
return tvb_captured_length(tvb);
}
if (packet.dst_present) {
packet.dst = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(aps_tree, hf_zbee_aps_dst, tvb, offset, 1, packet.dst);
proto_item_append_text(proto_root, ", Dst Endpt: %d", packet.dst);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst Endpt: %d", packet.dst);
}
}
if (packet.delivery == ZBEE_APS_FCF_GROUP) {
packet.group = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(aps_tree, hf_zbee_aps_group, tvb, offset,2, packet.group);
proto_item_append_text(proto_root, ", Group: 0x%04x", packet.group);
offset +=2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Group: 0x%04x", packet.group);
}
if (nwk->version >= ZBEE_VERSION_2007) {
nwk->cluster_id = tvb_get_letohs(tvb, offset);
switch (tvb_get_letohs(tvb, offset + 2)) {
case ZBEE_DEVICE_PROFILE:
proto_tree_add_uint_format(aps_tree, hf_zbee_aps_zdp_cluster, tvb, offset, 2, nwk->cluster_id,
"%s (Cluster ID: 0x%04x)", val_to_str(nwk->cluster_id, zbee_zdp_cluster_names,
"Unknown Device Profile Cluster"), nwk->cluster_id);
break;
case ZBEE_PROFILE_T2:
proto_tree_add_item(aps_tree, hf_zbee_aps_t2_cluster, tvb, offset, 2, ENC_LITTLE_ENDIAN);
if (packet.type == ZBEE_APS_FCF_DATA)
{
col_set_str(pinfo->cinfo, COL_INFO,
val_to_str_const(nwk->cluster_id, zbee_aps_t2_cid_names, "Unknown T2 cluster"));
}
break;
default:
proto_tree_add_item(aps_tree, hf_zbee_aps_cluster, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
}
offset += 2;
}
else {
nwk->cluster_id = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(aps_tree, hf_zbee_aps_cluster, tvb, offset,
1, nwk->cluster_id, "0x%02x", nwk->cluster_id);
offset += 1;
}
packet.profile = tvb_get_letohs(tvb, offset);
profile_handle = dissector_get_uint_handle(zbee_aps_dissector_table, packet.profile);
proto_tree_add_uint(aps_tree, hf_zbee_aps_profile, tvb, offset,2,
packet.profile);
offset +=2;
if (packet.type != ZBEE_APS_FCF_INTERPAN &&
((packet.delivery != ZBEE_APS_FCF_INDIRECT) || (!packet.indirect_mode))) {
packet.src = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(aps_tree, hf_zbee_aps_src, tvb, offset, 1, packet.src);
proto_item_append_text(proto_root, ", Src Endpt: %d", packet.src);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Src Endpt: %d", packet.src);
}
if (packet.type == ZBEE_APS_FCF_DATA) {
col_append_fstr(pinfo->cinfo, COL_PROTOCOL, " %s",
rval_to_str_const(packet.profile, zbee_aps_apid_abbrs, ""));
}
dissect_zbee_aps_no_endpt:
if (nwk->version >= ZBEE_VERSION_2007 && packet.type != ZBEE_APS_FCF_INTERPAN) {
packet.counter = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(aps_tree, hf_zbee_aps_counter, tvb, offset, 1, packet.counter);
offset += 1;
}
if (packet.ext_header) {
fcf = tvb_get_guint8(tvb, offset);
packet.fragmentation = fcf & ZBEE_APS_EXT_FCF_FRAGMENT;
field_tree = proto_tree_add_subtree_format(aps_tree, tvb, offset, 1, ett_zbee_aps_fcf, NULL, "Extended Frame Control Field (0x%02x)", fcf);
proto_tree_add_uint(field_tree, hf_zbee_aps_fragmentation, tvb, offset, 1, packet.fragmentation);
offset += 1;
if (packet.fragmentation != ZBEE_APS_EXT_FCF_FRAGMENT_NONE) {
packet.block_number = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(field_tree, hf_zbee_aps_block_number, tvb, offset, 1, packet.block_number);
offset += 1;
}
if ((packet.fragmentation != ZBEE_APS_EXT_FCF_FRAGMENT_NONE) && (packet.type == ZBEE_APS_FCF_ACK)) {
proto_tree_add_bitmask(field_tree, tvb, offset, hf_zbee_aps_block_ack, ett_zbee_aps_frag_ack, frag_ack_flags, ENC_NA);
offset += 1;
}
}
else {
packet.fragmentation = ZBEE_APS_EXT_FCF_FRAGMENT_NONE;
}
if ((offset < tvb_captured_length(tvb)) && packet.security) {
payload_tvb = dissect_zbee_secure(tvb, pinfo, aps_tree, offset);
if (payload_tvb == NULL) {
return tvb_captured_length(tvb);
}
}
else if (offset < tvb_captured_length(tvb)) {
payload_tvb = tvb_new_subset_remaining(tvb, offset);
}
if ((payload_tvb) && (packet.fragmentation != ZBEE_APS_EXT_FCF_FRAGMENT_NONE)) {
guint32 msg_id;
guint32 block_num;
guint32 num_blocks = -1;
fragment_head *frag_msg = NULL;
tvbuff_t *new_tvb;
pinfo->fragmented = TRUE;
msg_id = ((nwk->src)<<8) + packet.counter;
if (packet.fragmentation == ZBEE_APS_EXT_FCF_FRAGMENT_FIRST) {
num_blocks = packet.block_number - 1;
block_num = 0;
}
else {
block_num = packet.block_number;
}
frag_msg = fragment_add_seq_check(&zbee_aps_reassembly_table,
payload_tvb, 0, pinfo, msg_id, NULL,
block_num, tvb_captured_length(payload_tvb), TRUE);
if (num_blocks > 0) {
fragment_set_tot_len(&zbee_aps_reassembly_table, pinfo, msg_id, NULL, num_blocks);
}
new_tvb = process_reassembled_data(payload_tvb, 0, pinfo, "Reassembled ZigBee APS" ,
frag_msg, &zbee_aps_frag_items, NULL, aps_tree);
if (new_tvb) {
payload_tvb = new_tvb;
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, " (fragment %d)", block_num);
call_data_dissector(payload_tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
}
switch (packet.type) {
case ZBEE_APS_FCF_DATA:
case ZBEE_APS_FCF_INTERPAN:
if (!payload_tvb) {
break;
}
if (nwk->version <= ZBEE_VERSION_2004) {
nwk->private_data = profile_handle;
profile_handle = zbee_apf_handle;
}
else if (profile_handle == NULL) {
if (payload_tvb && (packet.profile == ZBEE_PROFILE_T2)) {
payload_tvb = tvb_new_subset_remaining(payload_tvb, dissect_zbee_t2(payload_tvb, aps_tree, nwk->cluster_id));
}
else {
zcl_handle = find_dissector(ZBEE_PROTOABBREV_ZCL);
}
if (zcl_handle) {
call_dissector_with_data(zcl_handle, payload_tvb, pinfo, tree, nwk);
}
break;
}
call_dissector_with_data(profile_handle, payload_tvb, pinfo, tree, nwk);
return tvb_captured_length(tvb);
case ZBEE_APS_FCF_CMD:
if (!payload_tvb) {
expert_add_info(pinfo, proto_root, &ei_zbee_aps_missing_payload);
return tvb_captured_length(tvb);
}
dissect_zbee_aps_cmd(payload_tvb, pinfo, aps_tree, nwk->version, data);
return tvb_captured_length(tvb);
case ZBEE_APS_FCF_ACK:
break;
default:
break;
}
if (payload_tvb) {
call_data_dissector(payload_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static void dissect_zbee_aps_cmd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version, void *data)
{
proto_item *cmd_root;
proto_tree *cmd_tree;
guint offset = 0;
guint8 cmd_id = tvb_get_guint8(tvb, offset);
cmd_tree = proto_tree_add_subtree_format(tree, tvb, offset, -1, ett_zbee_aps_cmd, &cmd_root,
"Command Frame: %s", val_to_str_const(cmd_id, zbee_aps_cmd_names, "Unknown"));
proto_tree_add_uint(cmd_tree, hf_zbee_aps_cmd_id, tvb, offset, 1, cmd_id);
offset += 1;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(cmd_id, zbee_aps_cmd_names, "Unknown Command"));
switch(cmd_id){
case ZBEE_APS_CMD_SKKE1:
case ZBEE_APS_CMD_SKKE2:
offset = dissect_zbee_aps_skke_challenge(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_SKKE3:
case ZBEE_APS_CMD_SKKE4:
offset = dissect_zbee_aps_skke_data(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_TRANSPORT_KEY:
offset = dissect_zbee_aps_transport_key(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_UPDATE_DEVICE:
offset = dissect_zbee_aps_update_device(tvb, pinfo, cmd_tree, offset, version);
break;
case ZBEE_APS_CMD_REMOVE_DEVICE:
offset = dissect_zbee_aps_remove_device(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_REQUEST_KEY:
offset = dissect_zbee_aps_request_key(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_SWITCH_KEY:
offset = dissect_zbee_aps_switch_key(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_EA_INIT_CHLNG:
case ZBEE_APS_CMD_EA_RESP_CHLNG:
offset = dissect_zbee_aps_auth_challenge(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_EA_INIT_MAC_DATA:
case ZBEE_APS_CMD_EA_RESP_MAC_DATA:
offset = dissect_zbee_aps_auth_data(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_TUNNEL:
offset = dissect_zbee_aps_tunnel(tvb, pinfo, cmd_tree, offset, data);
break;
case ZBEE_APS_CMD_VERIFY_KEY:
offset = dissect_zbee_aps_verify_key(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_APS_CMD_CONFIRM_KEY:
offset = dissect_zbee_aps_confirm_key(tvb, pinfo, cmd_tree, offset);
break;
default:
break;
}
if (offset < tvb_captured_length(tvb)) {
proto_tree *root;
tvbuff_t *leftover_tvb = tvb_new_subset_remaining(tvb, offset);
root = proto_tree_get_root(tree);
proto_item_set_len(cmd_root, offset);
call_data_dissector(leftover_tvb, pinfo, root);
}
}
static guint
dissect_zbee_aps_skke_challenge(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_zbee_aps_cmd_initiator, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_responder, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_challenge, tvb, offset, ZBEE_APS_CMD_SKKE_DATA_LENGTH, ENC_NA);
offset += ZBEE_APS_CMD_SKKE_DATA_LENGTH;
return offset;
}
static guint
dissect_zbee_aps_skke_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_zbee_aps_cmd_initiator, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_responder, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_mac, tvb, offset, ZBEE_APS_CMD_SKKE_DATA_LENGTH, ENC_NA);
offset += ZBEE_APS_CMD_SKKE_DATA_LENGTH;
return offset;
}
static guint
dissect_zbee_aps_transport_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 key_type;
guint8 key[ZBEE_APS_CMD_KEY_LENGTH];
GSList **nwk_keyring;
key_record_t key_record;
zbee_nwk_hints_t *nwk_hints;
guint i;
key_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_aps_cmd_key_type, tvb, offset, 1, key_type);
offset += 1;
for (i=0; i<ZBEE_APS_CMD_KEY_LENGTH ; i++) {
key[i] = tvb_get_guint8(tvb, offset+i);
}
proto_tree_add_item(tree, hf_zbee_aps_cmd_key, tvb, offset, ZBEE_APS_CMD_KEY_LENGTH, ENC_NA);
offset += ZBEE_APS_CMD_KEY_LENGTH;
if ( !pinfo->fd->flags.visited && (nwk_hints = (zbee_nwk_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(ZBEE_PROTOABBREV_NWK), 0))) {
nwk_keyring = (GSList **)g_hash_table_lookup(zbee_table_nwk_keyring, &nwk_hints->src_pan);
if ( !nwk_keyring ) {
nwk_keyring = (GSList **)g_malloc0(sizeof(GSList*));
g_hash_table_insert(zbee_table_nwk_keyring,
g_memdup(&nwk_hints->src_pan, sizeof(nwk_hints->src_pan)), nwk_keyring);
}
if ( nwk_keyring ) {
if ( !*nwk_keyring ||
memcmp( ((key_record_t *)((GSList *)(*nwk_keyring))->data)->key, &key,
ZBEE_APS_CMD_KEY_LENGTH) ) {
key_record.frame_num = pinfo->num;
key_record.label = NULL;
memcpy(&key_record.key, &key, ZBEE_APS_CMD_KEY_LENGTH);
*nwk_keyring = g_slist_prepend(*nwk_keyring, g_memdup(&key_record, sizeof(key_record_t)));
}
}
}
switch (key_type) {
case ZBEE_APS_CMD_KEY_STANDARD_NWK:
case ZBEE_APS_CMD_KEY_HIGH_SEC_NWK:
{
guint8 seqno;
seqno = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_aps_cmd_seqno, tvb, offset, 1, seqno);
offset += 1;
proto_tree_add_item(tree, hf_zbee_aps_cmd_dst, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_src, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
break;
}
case ZBEE_APS_CMD_KEY_TC_MASTER:
case ZBEE_APS_CMD_KEY_TC_LINK:
{
proto_tree_add_item(tree, hf_zbee_aps_cmd_dst, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_src, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
break;
}
case ZBEE_APS_CMD_KEY_APP_MASTER:
case ZBEE_APS_CMD_KEY_APP_LINK:
{
guint8 initiator;
proto_tree_add_item(tree, hf_zbee_aps_cmd_partner, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
initiator = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_zbee_aps_cmd_initiator_flag, tvb, offset, 1, initiator);
offset += 1;
break;
}
default:
break;
}
return offset;
}
static guint
dissect_zbee_aps_verify_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_zbee_aps_cmd_key_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_zbee_aps_cmd_src, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_key_hash, tvb, offset, ZBEE_APS_CMD_KEY_LENGTH, ENC_NA);
offset += ZBEE_APS_CMD_KEY_LENGTH;
return offset;
}
static guint
dissect_zbee_aps_confirm_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint status = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_zbee_aps_cmd_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_zbee_aps_cmd_key_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_zbee_aps_cmd_dst, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_item_append_text(tree, ", %s", val_to_str_const(status, zbee_aps_status_names, "Unknown Status"));
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str_const(status, zbee_aps_status_names, "Unknown Status"));
return offset;
}
static guint
dissect_zbee_aps_update_device(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset, guint8 version)
{
proto_tree_add_item(tree, hf_zbee_aps_cmd_device, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
if (version >= ZBEE_VERSION_2007) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_short_addr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
}
proto_tree_add_item(tree, hf_zbee_aps_cmd_device_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static guint
dissect_zbee_aps_remove_device(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_zbee_aps_cmd_device, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
return offset;
}
static guint
dissect_zbee_aps_request_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 key_type;
key_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_aps_cmd_key_type, tvb, offset, 1, key_type);
offset += 1;
if (key_type == ZBEE_APS_CMD_KEY_APP_MASTER) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_partner, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
}
return offset;
}
static guint
dissect_zbee_aps_switch_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 seqno;
seqno = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_aps_cmd_seqno, tvb, offset, 1, seqno);
offset += 1;
return offset;
}
static guint
dissect_zbee_aps_auth_challenge(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 key_type;
guint8 key_seqno;
key_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_aps_cmd_ea_key_type, tvb, offset, 1, key_type);
offset += 1;
if (key_type == ZBEE_APS_CMD_EA_KEY_NWK) {
key_seqno = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_aps_cmd_seqno, tvb, offset, 1, key_seqno);
offset += 1;
}
proto_tree_add_item(tree, hf_zbee_aps_cmd_initiator, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_responder, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_zbee_aps_cmd_challenge, tvb, offset, ZBEE_APS_CMD_EA_CHALLENGE_LENGTH, ENC_NA);
offset += ZBEE_APS_CMD_EA_CHALLENGE_LENGTH;
return offset;
}
static guint
dissect_zbee_aps_auth_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 data_type;
proto_tree_add_item(tree, hf_zbee_aps_cmd_mac, tvb, offset, ZBEE_APS_CMD_EA_MAC_LENGTH, ENC_NA);
offset += ZBEE_APS_CMD_EA_MAC_LENGTH;
data_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_aps_cmd_ea_key_type, tvb, offset, 1, data_type);
offset += 1;
proto_tree_add_item(tree, hf_zbee_aps_cmd_ea_data, tvb, offset, ZBEE_APS_CMD_EA_DATA_LENGTH, ENC_NA);
offset += ZBEE_APS_CMD_EA_DATA_LENGTH;
return offset;
}
static guint
dissect_zbee_aps_tunnel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, void *data)
{
proto_tree *root;
tvbuff_t *tunnel_tvb;
proto_tree_add_item(tree, hf_zbee_aps_cmd_dst, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
tunnel_tvb = tvb_new_subset_remaining(tvb, offset);
root = proto_tree_get_root(tree);
call_dissector_with_data(zbee_aps_handle, tunnel_tvb, pinfo, root, data);
offset = tvb_captured_length(tvb);
return offset;
}
static int dissect_zbee_apf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *apf_tree;
proto_item *proto_root;
guint8 count;
guint8 type;
guint offset = 0;
guint i;
tvbuff_t *app_tvb;
dissector_handle_t app_dissector = NULL;
zbee_nwk_packet *nwk = (zbee_nwk_packet *)data;
if (nwk != NULL)
app_dissector = (dissector_handle_t)(nwk->private_data);
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_apf, tvb, 0,
tvb_captured_length(tvb), "ZigBee Application Framework");
apf_tree = proto_item_add_subtree(proto_root, ett_zbee_apf);
count = zbee_get_bit_field(tvb_get_guint8(tvb, offset), ZBEE_APP_COUNT);
type = zbee_get_bit_field(tvb_get_guint8(tvb, offset), ZBEE_APP_TYPE);
proto_tree_add_uint(apf_tree, hf_zbee_apf_count, tvb, offset, 1, count);
proto_tree_add_uint(apf_tree, hf_zbee_apf_type, tvb, offset, 1, type);
offset += 1;
if (app_dissector == NULL) {
goto dissect_app_end;
}
for (i=0; i<count; i++) {
guint length;
length = zbee_apf_transaction_len(tvb, offset, type);
app_tvb = tvb_new_subset_length(tvb, offset, length);
call_dissector_with_data(app_dissector, app_tvb, pinfo, tree, data);
offset += length;
}
dissect_app_end:
if (offset < tvb_captured_length(tvb)) {
app_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(app_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static guint
dissect_zbee_t2(tvbuff_t *tvb, proto_tree *tree, guint16 cluster_id)
{
guint offset = 0;
guint8 payload_length;
proto_tree *t2_tree;
t2_tree = proto_tree_add_subtree(tree, tvb, 0, -1, ett_zbee_aps_t2, NULL, "ZigBee Test Profile #2");
switch (cluster_id) {
case ZBEE_APS_T2_CID_BTRES:
payload_length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(t2_tree, hf_zbee_aps_t2_btres_octet_sequence_length_requested, tvb, offset, 1,
payload_length);
offset += 1;
proto_tree_add_item(t2_tree, hf_zbee_aps_t2_btres_status, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(t2_tree, hf_zbee_aps_t2_btres_octet_sequence, tvb, offset, payload_length, ENC_NA);
offset += payload_length;
break;
case ZBEE_APS_T2_CID_BTREQ:
payload_length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(t2_tree, hf_zbee_aps_t2_btreq_octet_sequence_length, tvb, offset, 1, payload_length);
offset += 1;
proto_tree_add_item(t2_tree, hf_zbee_aps_t2_btreq_octet_sequence, tvb, offset, payload_length, ENC_NA);
offset += payload_length;
break;
}
return offset;
}
static guint
zbee_apf_transaction_len(tvbuff_t *tvb, guint offset, guint8 type)
{
if (type == ZBEE_APP_TYPE_KVP) {
guint8 kvp_cmd = zbee_get_bit_field(tvb_get_guint8(tvb, offset+1), ZBEE_APP_KVP_CMD);
guint8 kvp_type = zbee_get_bit_field(tvb_get_guint8(tvb, offset+1), ZBEE_APP_KVP_TYPE);
guint kvp_len = ZBEE_APP_KVP_OVERHEAD;
switch (kvp_cmd) {
case ZBEE_APP_KVP_SET_RESP:
case ZBEE_APP_KVP_EVENT_RESP:
kvp_len += 1;
return kvp_len;
case ZBEE_APP_KVP_GET_RESP:
kvp_len += 1;
break;
case ZBEE_APP_KVP_SET:
case ZBEE_APP_KVP_SET_ACK:
case ZBEE_APP_KVP_EVENT:
case ZBEE_APP_KVP_EVENT_ACK:
break;
case ZBEE_APP_KVP_GET_ACK:
default:
return kvp_len;
}
switch (kvp_type) {
case ZBEE_APP_KVP_ABS_TIME:
case ZBEE_APP_KVP_REL_TIME:
kvp_len += 4;
break;
case ZBEE_APP_KVP_UINT16:
case ZBEE_APP_KVP_INT16:
case ZBEE_APP_KVP_FLOAT16:
kvp_len += 2;
break;
case ZBEE_APP_KVP_UINT8:
case ZBEE_APP_KVP_INT8:
kvp_len += 1;
break;
case ZBEE_APP_KVP_CHAR_STRING:
case ZBEE_APP_KVP_OCT_STRING:
kvp_len += tvb_get_guint8(tvb, offset+kvp_len)+1;
break;
case ZBEE_APP_KVP_NO_DATA:
default:
break;
}
return kvp_len;
}
else {
return (tvb_get_guint8(tvb, offset+1) + 2);
}
}
void proto_register_zbee_aps(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_aps_fcf_frame_type,
{ "Frame Type", "zbee_aps.type", FT_UINT8, BASE_HEX, VALS(zbee_aps_frame_types), ZBEE_APS_FCF_FRAME_TYPE,
NULL, HFILL }},
{ &hf_zbee_aps_fcf_delivery,
{ "Delivery Mode", "zbee_aps.delivery", FT_UINT8, BASE_HEX, VALS(zbee_aps_delivery_modes), ZBEE_APS_FCF_DELIVERY_MODE,
NULL, HFILL }},
{ &hf_zbee_aps_fcf_indirect_mode,
{ "Indirect Address Mode", "zbee_aps.indirect_mode", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_INDIRECT_MODE,
NULL, HFILL }},
{ &hf_zbee_aps_fcf_ack_format,
{ "Acknowledgement Format", "zbee_aps.ack_format", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_ACK_FORMAT,
NULL, HFILL }},
{ &hf_zbee_aps_fcf_security,
{ "Security", "zbee_aps.security", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_SECURITY,
"Whether security operations are performed on the APS payload.", HFILL }},
{ &hf_zbee_aps_fcf_ack_req,
{ "Acknowledgement Request","zbee_aps.ack_req", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_ACK_REQ,
"Flag requesting an acknowledgement frame for this packet.", HFILL }},
{ &hf_zbee_aps_fcf_ext_header,
{ "Extended Header", "zbee_aps.ext_header", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_EXT_HEADER,
NULL, HFILL }},
{ &hf_zbee_aps_dst,
{ "Destination Endpoint", "zbee_aps.dst", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_group,
{ "Group", "zbee_aps.group", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cluster,
{ "Cluster", "zbee_aps.cluster", FT_UINT16, BASE_HEX,
VALS(zbee_aps_cid_names), 0x0, NULL, HFILL }},
{ &hf_zbee_aps_profile,
{ "Profile", "zbee_aps.profile", FT_UINT16, BASE_HEX | BASE_RANGE_STRING,
RVALS(zbee_aps_apid_names), 0x0, NULL, HFILL }},
{ &hf_zbee_aps_src,
{ "Source Endpoint", "zbee_aps.src", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_counter,
{ "Counter", "zbee_aps.counter", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragmentation,
{ "Fragmentation", "zbee_aps.fragmentation", FT_UINT8, BASE_HEX, VALS(zbee_aps_fragmentation_modes), ZBEE_APS_EXT_FCF_FRAGMENT,
NULL, HFILL }},
{ &hf_zbee_aps_block_number,
{ "Block Number", "zbee_aps.block", FT_UINT8, BASE_DEC, NULL, 0x0,
"A block identifier within a fragmented transmission, or the number of expected blocks if the first block.", HFILL }},
{ &hf_zbee_aps_block_ack,
{ "Block Acknowledgements", "zbee_aps.block_acks", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_aps_block_ack1,
{ "Block 1", "zbee_aps.block1_ack", FT_BOOLEAN, 8, TFS(&tfs_acknowledged_not_acknowledged),
ZBEE_APS_FRAG_BLOCK1_ACK, NULL, HFILL }},
{ &hf_zbee_aps_block_ack2,
{ "Block 2", "zbee_aps.block2_ack", FT_BOOLEAN, 8, TFS(&tfs_acknowledged_not_acknowledged),
ZBEE_APS_FRAG_BLOCK2_ACK, NULL, HFILL }},
{ &hf_zbee_aps_block_ack3,
{ "Block 3", "zbee_aps.block3_ack", FT_BOOLEAN, 8, TFS(&tfs_acknowledged_not_acknowledged),
ZBEE_APS_FRAG_BLOCK3_ACK, NULL, HFILL }},
{ &hf_zbee_aps_block_ack4,
{ "Block 4", "zbee_aps.block4_ack", FT_BOOLEAN, 8, TFS(&tfs_acknowledged_not_acknowledged),
ZBEE_APS_FRAG_BLOCK4_ACK, NULL, HFILL }},
{ &hf_zbee_aps_block_ack5,
{ "Block 5", "zbee_aps.block5_ack", FT_BOOLEAN, 8, TFS(&tfs_acknowledged_not_acknowledged),
ZBEE_APS_FRAG_BLOCK5_ACK, NULL, HFILL }},
{ &hf_zbee_aps_block_ack6,
{ "Block 6", "zbee_aps.block6_ack", FT_BOOLEAN, 8, TFS(&tfs_acknowledged_not_acknowledged),
ZBEE_APS_FRAG_BLOCK6_ACK, NULL, HFILL }},
{ &hf_zbee_aps_block_ack7,
{ "Block 7", "zbee_aps.block7_ack", FT_BOOLEAN, 8, TFS(&tfs_acknowledged_not_acknowledged),
ZBEE_APS_FRAG_BLOCK7_ACK, NULL, HFILL }},
{ &hf_zbee_aps_block_ack8,
{ "Block 8", "zbee_aps.block8_ack", FT_BOOLEAN, 8, TFS(&tfs_acknowledged_not_acknowledged),
ZBEE_APS_FRAG_BLOCK8_ACK, NULL, HFILL }},
{ &hf_zbee_aps_cmd_id,
{ "Command Identifier", "zbee_aps.cmd.id", FT_UINT8, BASE_HEX, VALS(zbee_aps_cmd_names), 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_initiator,
{ "Initiator Address", "zbee_aps.cmd.initiator", FT_EUI64, BASE_NONE, NULL, 0x0,
"The extended address of the device to initiate the SKKE procedure", HFILL }},
{ &hf_zbee_aps_cmd_responder,
{ "Responder Address", "zbee_aps.cmd.responder", FT_EUI64, BASE_NONE, NULL, 0x0,
"The extended address of the device responding to the SKKE procedure", HFILL }},
{ &hf_zbee_aps_cmd_partner,
{ "Partner Address", "zbee_aps.cmd.partner", FT_EUI64, BASE_NONE, NULL, 0x0,
"The partner to use this key with for link-level security.", HFILL }},
{ &hf_zbee_aps_cmd_initiator_flag,
{ "Initiator", "zbee_aps.cmd.init_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Indicates the destination of the transport-key command requested this key.", HFILL }},
{ &hf_zbee_aps_cmd_device,
{ "Device Address", "zbee_aps.cmd.device", FT_EUI64, BASE_NONE, NULL, 0x0,
"The device whose status is being updated.", HFILL }},
{ &hf_zbee_aps_cmd_challenge,
{ "Challenge", "zbee_aps.cmd.challenge", FT_BYTES, BASE_NONE, NULL, 0x0,
"Random challenge value used during SKKE and authentication.", HFILL }},
{ &hf_zbee_aps_cmd_mac,
{ "Message Authentication Code", "zbee_aps.cmd.mac", FT_BYTES, BASE_NONE, NULL, 0x0,
"Message authentication values used during SKKE and authentication.", HFILL }},
{ &hf_zbee_aps_cmd_key,
{ "Key", "zbee_aps.cmd.key", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_key_hash,
{ "Key Hash", "zbee_aps.cmd.key_hash", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_key_type,
{ "Key Type", "zbee_aps.cmd.key_type", FT_UINT8, BASE_HEX,
VALS(zbee_aps_key_names), 0x0, NULL, HFILL }},
{ &hf_zbee_aps_cmd_dst,
{ "Extended Destination", "zbee_aps.cmd.dst", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_src,
{ "Extended Source", "zbee_aps.cmd.src", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_seqno,
{ "Sequence Number", "zbee_aps.cmd.seqno", FT_UINT8, BASE_DEC, NULL, 0x0,
"The key sequence number associated with the network key.", HFILL }},
{ &hf_zbee_aps_cmd_short_addr,
{ "Device Address", "zbee_aps.cmd.addr", FT_UINT16, BASE_HEX, NULL, 0x0,
"The device whose status is being updated.", HFILL }},
{ &hf_zbee_aps_cmd_device_status,
{ "Device Status", "zbee_aps.cmd.update_status", FT_UINT8, BASE_HEX,
VALS(zbee_aps_update_status_names), 0x0,
"Update device status.", HFILL }},
{ &hf_zbee_aps_cmd_status,
{ "Status", "zbee_aps.cmd.status", FT_UINT8, BASE_HEX,
VALS(zbee_aps_status_names), 0x0,
"APS status.", HFILL }},
{ &hf_zbee_aps_cmd_ea_key_type,
{ "Key Type", "zbee_aps.cmd.ea.key_type", FT_UINT8, BASE_HEX,
VALS(zbee_aps_ea_key_names), 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_ea_data,
{ "Data", "zbee_aps.cmd.ea.data", FT_BYTES, BASE_NONE, NULL, 0x0,
"Additional data used in entity authentication. Typically this will be the outgoing frame counter associated with the key used for entity authentication.", HFILL }},
{ &hf_zbee_aps_fragments,
{ "Message fragments", "zbee_aps.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment,
{ "Message fragment", "zbee_aps.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_overlap,
{ "Message fragment overlap", "zbee_aps.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "zbee_aps.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_multiple_tails,
{ "Message has multiple tail fragments", "zbee_aps.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_too_long_fragment,
{ "Message fragment too long", "zbee_aps.fragment.too_long_fragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_error,
{ "Message defragmentation error", "zbee_aps.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_count,
{ "Message fragment count", "zbee_aps.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_reassembled_in,
{ "Reassembled in", "zbee_aps.reassembled.in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_reassembled_length,
{ "Reassembled ZigBee APS length", "zbee_aps.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_t2_cluster,
{ "Cluster", "zbee_aps.t2.cluster", FT_UINT16, BASE_HEX, VALS(zbee_aps_t2_cid_names), 0x0, NULL,
HFILL }},
{ &hf_zbee_aps_t2_btres_octet_sequence,
{ "Octet Sequence", "zbee_aps.t2.btres.octet_sequence", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_aps_t2_btres_octet_sequence_length_requested,
{ "Octet Sequence Length Requested", "zbee_aps.t2.btres.octet_sequence_length_requested", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_aps_t2_btres_status,
{ "Status", "zbee_aps.t2.btres.status", FT_UINT8, BASE_HEX, VALS(zbee_aps_t2_btres_status_names), 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_t2_btreq_octet_sequence,
{ "Octet Sequence", "zbee_aps.t2.btreq.octet_sequence", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_aps_t2_btreq_octet_sequence_length,
{ "Octet Sequence Length", "zbee_aps.t2.btreq.octet_sequence_length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_zdp_cluster,
{ "Cluster", "zbee_aps.zdp_cluster", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info hf_apf[] = {
{ &hf_zbee_apf_count,
{ "Count", "zbee_apf.count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_apf_type,
{ "Type", "zbee_apf.type", FT_UINT8, BASE_HEX,
VALS(zbee_apf_type_names), 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_zbee_aps,
&ett_zbee_aps_fcf,
&ett_zbee_aps_ext,
&ett_zbee_aps_cmd,
&ett_zbee_aps_fragment,
&ett_zbee_aps_fragments,
&ett_zbee_aps_t2,
&ett_zbee_aps_frag_ack
};
static gint *ett_apf[] = {
&ett_zbee_apf
};
static ei_register_info ei[] = {
{ &ei_zbee_aps_invalid_delivery_mode, { "zbee_aps.invalid_delivery_mode", PI_PROTOCOL, PI_WARN, "Invalid Delivery Mode", EXPFILL }},
{ &ei_zbee_aps_missing_payload, { "zbee_aps.missing_payload", PI_MALFORMED, PI_ERROR, "Missing Payload", EXPFILL }},
};
expert_module_t* expert_zbee_aps;
proto_zbee_aps = proto_register_protocol("ZigBee Application Support Layer", "ZigBee APS", ZBEE_PROTOABBREV_APS);
proto_register_field_array(proto_zbee_aps, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_zbee_aps = expert_register_protocol(proto_zbee_aps);
expert_register_field_array(expert_zbee_aps, ei, array_length(ei));
zbee_aps_dissector_table = register_dissector_table("zbee.profile", "ZigBee Profile ID", proto_zbee_aps, FT_UINT16, BASE_HEX);
zbee_aps_handle = register_dissector(ZBEE_PROTOABBREV_APS, dissect_zbee_aps, proto_zbee_aps);
register_init_routine(proto_init_zbee_aps);
register_cleanup_routine(proto_cleanup_zbee_aps);
proto_zbee_apf = proto_register_protocol("ZigBee Application Framework", "ZigBee APF", "zbee_apf");
proto_register_field_array(proto_zbee_apf, hf_apf, array_length(hf_apf));
proto_register_subtree_array(ett_apf, array_length(ett_apf));
zbee_apf_handle = register_dissector("zbee_apf", dissect_zbee_apf, proto_zbee_apf);
}
static void proto_init_zbee_aps(void)
{
reassembly_table_init(&zbee_aps_reassembly_table,
&addresses_reassembly_table_functions);
}
static void proto_cleanup_zbee_aps(void)
{
reassembly_table_destroy(&zbee_aps_reassembly_table);
}
