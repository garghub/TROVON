static void
dissect_zbee_aps(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *payload_tvb = NULL;
dissector_handle_t profile_handle = NULL;
proto_tree *aps_tree = NULL;
proto_tree *field_tree = NULL;
proto_item *proto_root = NULL;
proto_item *ti;
zbee_aps_packet packet;
zbee_nwk_packet *nwk = (zbee_nwk_packet *)pinfo->private_data;
guint8 fcf;
guint8 offset = 0;
memset(&packet, 0, sizeof(zbee_aps_packet));
if(tree){
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_aps, tvb, offset, tvb_length(tvb), "ZigBee Application Support Layer");
aps_tree = proto_item_add_subtree(proto_root, ett_zbee_aps);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee");
fcf = tvb_get_guint8(tvb, offset);
packet.type = zbee_get_bit_field(fcf, ZBEE_APS_FCF_FRAME_TYPE);
packet.delivery = zbee_get_bit_field(fcf, ZBEE_APS_FCF_DELIVERY_MODE);
packet.indirect_mode = zbee_get_bit_field(fcf, ZBEE_APS_FCF_INDIRECT_MODE);
packet.ack_format = zbee_get_bit_field(fcf, ZBEE_APS_FCF_ACK_FORMAT);
packet.security = zbee_get_bit_field(fcf, ZBEE_APS_FCF_SECURITY);
packet.ack_req = zbee_get_bit_field(fcf, ZBEE_APS_FCF_ACK_REQ);
packet.ext_header = zbee_get_bit_field(fcf, ZBEE_APS_FCF_EXT_HEADER);
if (tree) {
proto_item_append_text(proto_root, " %s", val_to_str(packet.type, zbee_aps_frame_types, "Unknown Type"));
}
col_clear(pinfo->cinfo, COL_INFO);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(packet.type, zbee_aps_frame_types, "Unknown Frame Type"));
if (tree) {
ti = proto_tree_add_text(aps_tree, tvb, offset, 1, "Frame Control Field: %s (0x%02x)",
val_to_str(packet.type, zbee_aps_frame_types, "Unknown"), fcf);
field_tree = proto_item_add_subtree(ti, ett_zbee_aps_fcf);
proto_tree_add_uint(field_tree, hf_zbee_aps_fcf_frame_type, tvb, offset, 1, fcf & ZBEE_APS_FCF_FRAME_TYPE);
proto_tree_add_uint(field_tree, hf_zbee_aps_fcf_delivery, tvb, offset, 1, fcf & ZBEE_APS_FCF_DELIVERY_MODE);
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
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
}
offset += 1;
switch (packet.type) {
case ZBEE_APS_FCF_DATA:
break;
case ZBEE_APS_FCF_ACK:
if ((pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) && (packet.ack_format)) {
goto dissect_zbee_aps_no_endpt;
}
break;
default:
case ZBEE_APS_FCF_CMD:
goto dissect_zbee_aps_no_endpt;
}
if ((packet.delivery == ZBEE_APS_FCF_UNICAST) || (packet.delivery == ZBEE_APS_FCF_BCAST)) {
packet.dst_present = TRUE;
packet.src_present = TRUE;
}
else if ((packet.delivery == ZBEE_APS_FCF_INDIRECT) && (pinfo->zbee_stack_vers <= ZBEE_VERSION_2004)) {
packet.dst_present = (!packet.indirect_mode);
packet.src_present = (packet.indirect_mode);
}
else if ((packet.delivery == ZBEE_APS_FCF_GROUP) && (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007)) {
packet.dst_present = FALSE;
packet.src_present = TRUE;
}
else {
expert_add_info_format(pinfo, proto_root, PI_MALFORMED, PI_WARN, "Invalid Delivery Mode");
return;
}
if (packet.dst_present) {
packet.dst = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(aps_tree, hf_zbee_aps_dst, tvb, offset, 1, packet.dst);
proto_item_append_text(proto_root, ", Dst Endpt: %d", packet.dst);
}
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst Endpt: %d", packet.dst);
}
if (packet.delivery == ZBEE_APS_FCF_GROUP) {
packet.group = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(aps_tree, hf_zbee_aps_group, tvb, offset,2, packet.group);
proto_item_append_text(proto_root, ", Group: 0x%04x", packet.group);
}
offset +=2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Group: 0x%04x", packet.group);
}
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
pinfo->zbee_cluster_id = packet.cluster = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(aps_tree, hf_zbee_aps_cluster, tvb, offset,2, packet.cluster);
}
offset +=2;
}
else {
pinfo->zbee_cluster_id = packet.cluster = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint_format_value(aps_tree, hf_zbee_aps_cluster, tvb, offset,
1, packet.cluster, "0x%02x", packet.cluster);
}
offset += 1;
}
packet.profile = tvb_get_letohs(tvb, offset);
profile_handle = dissector_get_uint_handle(zbee_aps_dissector_table, packet.profile);
if (tree) {
proto_tree_add_uint(aps_tree, hf_zbee_aps_profile, tvb, offset,2,
packet.profile);
}
offset +=2;
if ((packet.delivery != ZBEE_APS_FCF_INDIRECT) || (!packet.indirect_mode)) {
packet.src = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(aps_tree, hf_zbee_aps_src, tvb, offset, 1, packet.src);
proto_item_append_text(proto_root, ", Src Endpt: %d", packet.src);
}
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Src Endpt: %d", packet.src);
}
if (packet.type == ZBEE_APS_FCF_DATA) {
col_append_fstr(pinfo->cinfo, COL_PROTOCOL, " %s",
rval_to_str(packet.profile, zbee_aps_apid_abbrs, ""));
}
dissect_zbee_aps_no_endpt:
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
packet.counter = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(aps_tree, hf_zbee_aps_counter, tvb, offset, 1, packet.counter);
}
offset += 1;
}
if (packet.ext_header) {
fcf = tvb_get_guint8(tvb, offset);
packet.fragmentation = fcf & ZBEE_APS_EXT_FCF_FRAGMENT;
if (tree) {
ti = proto_tree_add_text(aps_tree, tvb, offset, 1, "Extended Frame Control Field (0x%02x)", fcf);
field_tree = proto_item_add_subtree(ti, ett_zbee_aps_fcf);
proto_tree_add_uint(field_tree, hf_zbee_aps_fragmentation, tvb, offset, 1, packet.fragmentation);
}
offset += 1;
if (packet.fragmentation != ZBEE_APS_EXT_FCF_FRAGMENT_NONE) {
packet.block_number = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(field_tree, hf_zbee_aps_block_number, tvb, offset, 1, packet.block_number);
}
offset += 1;
}
if ((packet.fragmentation != ZBEE_APS_EXT_FCF_FRAGMENT_NONE) && (packet.type == ZBEE_APS_FCF_ACK)) {
packet.ack_bitfield = tvb_get_guint8(tvb, offset);
if (tree) {
int i, mask;
gchar tmp[16];
for (i=0; i<8; i++) {
mask = (1<<i);
decode_bitfield_value(tmp, packet.ack_bitfield, mask, 8);
proto_tree_add_text(field_tree, tvb, offset, 1, "%sBlock %d: %s",
tmp, packet.block_number+i, (packet.ack_bitfield & mask)?"Acknowledged":"Not Acknowledged");
}
}
offset += 1;
}
}
else {
packet.fragmentation = ZBEE_APS_EXT_FCF_FRAGMENT_NONE;
}
if ((offset < tvb_length(tvb)) && packet.security) {
payload_tvb = dissect_zbee_secure(tvb, pinfo, aps_tree, offset);
if (payload_tvb == NULL) {
return;
}
}
else if (offset < tvb_length(tvb)) {
payload_tvb = tvb_new_subset_remaining(tvb, offset);
}
if ((payload_tvb) && (packet.fragmentation != ZBEE_APS_EXT_FCF_FRAGMENT_NONE)) {
guint32 msg_id;
guint32 block_num;
fragment_data *frag_msg = NULL;
tvbuff_t *new_tvb;
pinfo->fragmented = TRUE;
msg_id = ((nwk->src)<<8) + packet.counter;
if (packet.fragmentation == ZBEE_APS_EXT_FCF_FRAGMENT_FIRST) {
fragment_set_tot_len(pinfo, msg_id, zbee_aps_fragment_table, packet.block_number);
block_num = 0;
}
else {
block_num = packet.block_number;
}
frag_msg = fragment_add_seq_check(payload_tvb, 0, pinfo, msg_id, zbee_aps_fragment_table,
zbee_aps_reassembled_table, block_num, tvb_length(payload_tvb), TRUE);
new_tvb = process_reassembled_data(payload_tvb, 0, pinfo, "Reassembled ZigBee APS" ,
frag_msg, &zbee_aps_frag_items, NULL, aps_tree);
if (frag_msg) col_append_str(pinfo->cinfo, COL_INFO, " (Message Reassembled)");
else col_append_fstr(pinfo->cinfo, COL_INFO, " (Message fragment %u)", packet.counter);
if (new_tvb) {
payload_tvb = new_tvb;
}
else {
call_dissector(data_handle, payload_tvb, pinfo, tree);
return;
}
}
switch (packet.type) {
case ZBEE_APS_FCF_DATA:
if (!payload_tvb) {
break;
}
if (pinfo->zbee_stack_vers <= ZBEE_VERSION_2004) {
pinfo->private_data = profile_handle;
profile_handle = zbee_apf_handle;
}
else if (profile_handle == NULL) {
break;
}
call_dissector(profile_handle, payload_tvb, pinfo, tree);
return;
case ZBEE_APS_FCF_CMD:
if (!payload_tvb) {
expert_add_info_format(pinfo, proto_root, PI_MALFORMED, PI_ERROR, "Missing Payload");
THROW(BoundsError);
return;
}
dissect_zbee_aps_cmd(payload_tvb, pinfo, aps_tree);
return;
case ZBEE_APS_FCF_ACK:
break;
default:
break;
}
if (payload_tvb) {
call_dissector(data_handle, payload_tvb, pinfo, tree);
}
}
static void dissect_zbee_aps_cmd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *cmd_root = NULL;
proto_tree *cmd_tree = NULL;
guint offset = 0;
guint8 cmd_id = tvb_get_guint8(tvb, offset);
if(tree){
cmd_root = proto_tree_add_text(tree, tvb, offset, tvb_length(tvb), "Command Frame: %s", val_to_str(cmd_id, zbee_aps_cmd_names, "Unknown"));
cmd_tree = proto_item_add_subtree(cmd_root, ett_zbee_aps_cmd);
proto_tree_add_uint(cmd_tree, hf_zbee_aps_cmd_id, tvb, offset, 1, cmd_id);
}
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
offset = dissect_zbee_aps_update_device(tvb, pinfo, cmd_tree, offset);
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
offset = dissect_zbee_aps_tunnel(tvb, pinfo, cmd_tree, offset);
break;
default:
break;
}
if (offset < tvb_length(tvb)) {
guint leftover_len = tvb_length(tvb) - offset;
proto_tree *root = NULL;
tvbuff_t *leftover_tvb = tvb_new_subset(tvb, offset, leftover_len, leftover_len);
if (tree) {
root = proto_tree_get_root(tree);
proto_item_set_len(cmd_root, offset);
}
call_dissector(data_handle, leftover_tvb, pinfo, root);
}
}
static guint
dissect_zbee_aps_skke_challenge(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_initiator, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_responder, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_challenge, tvb, offset, ZBEE_APS_CMD_SKKE_DATA_LENGTH, ENC_NA);
}
offset += ZBEE_APS_CMD_SKKE_DATA_LENGTH;
return offset;
}
static guint
dissect_zbee_aps_skke_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_initiator, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_responder, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_mac, tvb, offset, ZBEE_APS_CMD_SKKE_DATA_LENGTH, ENC_NA);
}
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
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_key_type, tvb, offset, 1, key_type);
}
offset += 1;
for (i=0; i<ZBEE_APS_CMD_KEY_LENGTH ; i++) {
key[i] = tvb_get_guint8(tvb, offset+i);
}
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_key, tvb, offset, ZBEE_APS_CMD_KEY_LENGTH, ENC_NA);
}
offset += ZBEE_APS_CMD_KEY_LENGTH;
if ( !pinfo->fd->flags.visited && (nwk_hints = (zbee_nwk_hints_t *)p_get_proto_data(pinfo->fd,
proto_get_id_by_filter_name(ZBEE_PROTOABBREV_NWK)))) {
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
key_record.frame_num = pinfo->fd->num;
key_record.label = NULL;
memcpy(&key_record.key, &key, ZBEE_APS_CMD_KEY_LENGTH);
*nwk_keyring = g_slist_prepend(*nwk_keyring, se_memdup(&key_record, sizeof(key_record_t)));
}
}
}
switch (key_type) {
case ZBEE_APS_CMD_KEY_STANDARD_NWK:
case ZBEE_APS_CMD_KEY_HIGH_SEC_NWK: {
guint8 seqno;
seqno = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_seqno, tvb, offset, 1, seqno);
}
offset += 1;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_dst, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_src, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
break;
}
case ZBEE_APS_CMD_KEY_TC_MASTER:
case ZBEE_APS_CMD_KEY_TC_LINK:{
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_dst, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_src, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
break;
}
case ZBEE_APS_CMD_KEY_APP_MASTER:
case ZBEE_APS_CMD_KEY_APP_LINK:{
guint8 initiator;
if (tree) {
proto_tree_add_eui64(tree, hf_zbee_aps_cmd_partner, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
initiator = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_boolean(tree, hf_zbee_aps_cmd_initiator_flag, tvb, offset, 1, initiator);
}
offset += 1;
break;
}
default:
break;
}
return offset;
}
static guint
dissect_zbee_aps_update_device(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint16 short_addr;
guint8 status;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_device, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
short_addr = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_short_addr, tvb, offset, 2, short_addr);
}
offset +=2;
}
status = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_device_status, tvb, offset, 1, status);
}
offset += 1;
return offset;
}
static guint
dissect_zbee_aps_remove_device(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
if(tree){
proto_tree_add_item(tree, hf_zbee_aps_cmd_device, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
return offset;
}
static guint
dissect_zbee_aps_request_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 key_type;
key_type = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_key_type, tvb, offset, 1, key_type);
}
offset += 1;
if (key_type == ZBEE_APS_CMD_KEY_APP_MASTER) {
if (tree) {
proto_tree_add_eui64(tree, hf_zbee_aps_cmd_partner, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
}
return offset;
}
static guint
dissect_zbee_aps_switch_key(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 seqno;
seqno = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_seqno, tvb, offset, 1, seqno);
}
offset += 1;
return offset;
}
static guint
dissect_zbee_aps_auth_challenge(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 key_type;
guint8 key_seqno;
key_type = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_ea_key_type, tvb, offset, 1, key_type);
}
offset += 1;
if (key_type == ZBEE_APS_CMD_EA_KEY_NWK) {
key_seqno = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_seqno, tvb, offset, 1, key_seqno);
}
offset += 1;
}
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_initiator, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_responder, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_challenge, tvb, offset, ZBEE_APS_CMD_EA_CHALLENGE_LENGTH, ENC_NA);
}
offset += ZBEE_APS_CMD_EA_CHALLENGE_LENGTH;
return offset;
}
static guint
dissect_zbee_aps_auth_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 data_type;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_mac, tvb, offset, ZBEE_APS_CMD_EA_MAC_LENGTH, ENC_NA);
}
offset += ZBEE_APS_CMD_EA_MAC_LENGTH;
data_type = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_aps_cmd_ea_key_type, tvb, offset, 1, data_type);
}
offset += 1;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_ea_data, tvb, offset, ZBEE_APS_CMD_EA_DATA_LENGTH, ENC_NA);
}
offset += ZBEE_APS_CMD_EA_DATA_LENGTH;
return offset;
}
static guint
dissect_zbee_aps_tunnel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
proto_tree *root = NULL;
tvbuff_t *tunnel_tvb;
if (tree) {
proto_tree_add_item(tree, hf_zbee_aps_cmd_dst, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
tunnel_tvb = tvb_new_subset(tvb, offset, tvb_length_remaining(tvb, offset),
tvb_reported_length_remaining(tvb, offset));
if (tree) root = proto_tree_get_root(tree);
call_dissector(zbee_aps_handle, tunnel_tvb, pinfo, root);
offset = tvb_length(tvb);
return offset;
}
static void dissect_zbee_apf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *apf_tree = NULL;
proto_item *proto_root;
guint8 count;
guint8 type;
guint offset = 0;
guint i;
tvbuff_t *app_tvb;
dissector_handle_t app_dissector = (dissector_handle_t)(pinfo->private_data);
if (tree) {
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_apf, tvb, 0,
tvb_length(tvb), "ZigBee Application Framework");
apf_tree = proto_item_add_subtree(proto_root, ett_zbee_apf);
}
count = zbee_get_bit_field(tvb_get_guint8(tvb, offset), ZBEE_APP_COUNT);
type = zbee_get_bit_field(tvb_get_guint8(tvb, offset), ZBEE_APP_TYPE);
if (tree) {
proto_tree_add_uint(apf_tree, hf_zbee_apf_count, tvb, offset, 1, count);
proto_tree_add_uint(apf_tree, hf_zbee_apf_type, tvb, offset, 1, type);
}
offset += 1;
if (app_dissector == NULL) {
goto dissect_app_end;
}
for (i=0; i<count; i++) {
guint length;
length = zbee_apf_transaction_len(tvb, offset, type);
app_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector(app_dissector, app_tvb, pinfo, tree);
offset += length;
}
dissect_app_end:
if (offset < tvb_length(tvb)) {
app_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, app_tvb, pinfo, tree);
}
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
kvp_len += sizeof(guint32);
break;
case ZBEE_APP_KVP_UINT16:
case ZBEE_APP_KVP_INT16:
case ZBEE_APP_KVP_FLOAT16:
kvp_len +=2;
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
{ "Frame Type", "zbee.aps.type", FT_UINT8, BASE_HEX, VALS(zbee_aps_frame_types), ZBEE_APS_FCF_FRAME_TYPE,
NULL, HFILL }},
{ &hf_zbee_aps_fcf_delivery,
{ "Delivery Mode", "zbee.aps.delivery", FT_UINT8, BASE_HEX, VALS(zbee_aps_delivery_modes), ZBEE_APS_FCF_DELIVERY_MODE,
NULL, HFILL }},
{ &hf_zbee_aps_fcf_indirect_mode,
{ "Indirect Address Mode", "zbee.aps.indirect_mode", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_INDIRECT_MODE,
NULL, HFILL }},
{ &hf_zbee_aps_fcf_ack_format,
{ "Acknowledgement Format", "zbee.aps.ack_format", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_ACK_FORMAT,
NULL, HFILL }},
{ &hf_zbee_aps_fcf_security,
{ "Security", "zbee.aps.security", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_SECURITY,
"Whether security operations are performed on the APS payload.", HFILL }},
{ &hf_zbee_aps_fcf_ack_req,
{ "Acknowledgement Request","zbee.aps.ack_req", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_ACK_REQ,
"Flag requesting an acknowledgement frame for this packet.", HFILL }},
{ &hf_zbee_aps_fcf_ext_header,
{ "Extended Header", "zbee.aps.ext_header", FT_BOOLEAN, 8, NULL, ZBEE_APS_FCF_EXT_HEADER,
NULL, HFILL }},
{ &hf_zbee_aps_dst,
{ "Destination Endpoint", "zbee.aps.dst", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_group,
{ "Group", "zbee.aps.group", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cluster,
{ "Cluster", "zbee.aps.cluster", FT_UINT16, BASE_HEX,
VALS(zbee_aps_cid_names), 0x0, NULL, HFILL }},
{ &hf_zbee_aps_profile,
{ "Profile", "zbee.aps.profile", FT_UINT16, BASE_HEX | BASE_RANGE_STRING,
RVALS(zbee_aps_apid_names), 0x0, NULL, HFILL }},
{ &hf_zbee_aps_src,
{ "Source Endpoint", "zbee.aps.src", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_counter,
{ "Counter", "zbee.aps.counter", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragmentation,
{ "Fragmentation", "zbee.aps.fragmentation", FT_UINT8, BASE_HEX, VALS(zbee_aps_fragmentation_modes), ZBEE_APS_EXT_FCF_FRAGMENT,
NULL, HFILL }},
{ &hf_zbee_aps_block_number,
{ "Block Number", "zbee.aps.block", FT_UINT8, BASE_DEC, NULL, 0x0,
"A block identifier within a fragmented transmission, or the number of expected blocks if the first block.", HFILL }},
{ &hf_zbee_aps_cmd_id,
{ "Command Identifier", "zbee.aps.cmd.id", FT_UINT8, BASE_HEX, VALS(zbee_aps_cmd_names), 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_initiator,
{ "Initiator Address", "zbee.aps.cmd.initiator", FT_EUI64, BASE_NONE, NULL, 0x0,
"The extended address of the device to initiate the SKKE procedure", HFILL }},
{ &hf_zbee_aps_cmd_responder,
{ "Responder Address", "zbee.aps.cmd.responder", FT_EUI64, BASE_NONE, NULL, 0x0,
"The extended address of the device responding to the SKKE procedure", HFILL }},
{ &hf_zbee_aps_cmd_partner,
{ "Partner Address", "zbee.aps.cmd.partner", FT_EUI64, BASE_NONE, NULL, 0x0,
"The partner to use this key with for link-level security.", HFILL }},
{ &hf_zbee_aps_cmd_initiator_flag,
{ "Initiator", "zbee.aps.cmd.init_flag", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Inidicates the destination of the transport-key command requested this key.", HFILL }},
{ &hf_zbee_aps_cmd_device,
{ "Device Address", "zbee.aps.cmd.device", FT_EUI64, BASE_NONE, NULL, 0x0,
"The device whose status is being updated.", HFILL }},
{ &hf_zbee_aps_cmd_challenge,
{ "Challenge", "zbee.aps.cmd.challenge", FT_BYTES, BASE_NONE, NULL, 0x0,
"Random challenge value used during SKKE and authentication.", HFILL }},
{ &hf_zbee_aps_cmd_mac,
{ "Message Authentication Code", "zbee.aps.cmd.mac", FT_BYTES, BASE_NONE, NULL, 0x0,
"Message authentication values used during SKKE and authentication.", HFILL }},
{ &hf_zbee_aps_cmd_key,
{ "Key", "zbee.aps.cmd.key", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_key_type,
{ "Key Type", "zbee.aps.cmd.key_type", FT_UINT8, BASE_HEX,
VALS(zbee_aps_key_names), 0x0, NULL, HFILL }},
{ &hf_zbee_aps_cmd_dst,
{ "Extended Destination", "zbee.aps.cmd.dst", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_src,
{ "Extended Source", "zbee.aps.cmd.src", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_seqno,
{ "Sequence Number", "zbee.aps.cmd.seqno", FT_UINT8, BASE_DEC, NULL, 0x0,
"The key sequence number associated with the network key.", HFILL }},
{ &hf_zbee_aps_cmd_short_addr,
{ "Device Address", "zbee.aps.cmd.addr", FT_UINT16, BASE_HEX, NULL, 0x0,
"The device whose status is being updated.", HFILL }},
{ &hf_zbee_aps_cmd_device_status,
{ "Device Status", "zbee.aps.cmd.status", FT_UINT8, BASE_HEX,
VALS(zbee_aps_update_status_names), 0x0,
"Update device status.", HFILL }},
{ &hf_zbee_aps_cmd_ea_key_type,
{ "Key Type", "zbee.aps.cmd.ea.key_type", FT_UINT8, BASE_HEX,
VALS(zbee_aps_ea_key_names), 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_cmd_ea_data,
{ "Data", "zbee.aps.cmd.ea.data", FT_BYTES, BASE_NONE, NULL, 0x0,
"Additional data used in entity authentication. Typically this will be the outgoing frame counter associated with the key used for entity authentication.", HFILL }},
{ &hf_zbee_aps_fragments,
{ "Message fragments", "zbee.aps.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment,
{ "Message fragment", "zbee.aps.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_overlap,
{ "Message fragment overlap", "zbee.aps.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "zbee.aps.fragment.overlap.conflicts", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_multiple_tails,
{ "Message has multiple tail fragments", "zbee.aps.fragment.multiple_tails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_too_long_fragment,
{ "Message fragment too long", "zbee.aps.fragment.too_long_fragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_error,
{ "Message defragmentation error", "zbee.aps.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_fragment_count,
{ "Message fragment count", "zbee.aps.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_reassembled_in,
{ "Reassembled in", "zbee.aps.reassembled.in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_aps_reassembled_length,
{ "Reassembled ZigBee APS length", "zbee.aps.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static hf_register_info hf_apf[] = {
{ &hf_zbee_apf_count,
{ "Count", "zbee.app.count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_apf_type,
{ "Type", "zbee.app.type", FT_UINT8, BASE_HEX,
VALS(zbee_apf_type_names), 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_zbee_aps,
&ett_zbee_aps_fcf,
&ett_zbee_aps_ext,
&ett_zbee_aps_cmd,
&ett_zbee_aps_fragment,
&ett_zbee_aps_fragments
};
static gint *ett_apf[] = {
&ett_zbee_apf
};
proto_zbee_aps = proto_register_protocol("ZigBee Application Support Layer", "ZigBee APS", ZBEE_PROTOABBREV_APS);
proto_register_field_array(proto_zbee_aps, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
zbee_aps_dissector_table = register_dissector_table("zbee.profile", "ZigBee Profile ID", FT_UINT16, BASE_HEX);
register_dissector(ZBEE_PROTOABBREV_APS, dissect_zbee_aps, proto_zbee_aps);
register_init_routine(proto_init_zbee_aps);
proto_zbee_apf = proto_register_protocol("ZigBee Application Framework", "ZigBee APF", ZBEE_PROTOABBREV_APF);
proto_register_field_array(proto_zbee_apf, hf_apf, array_length(hf_apf));
proto_register_subtree_array(ett_apf, array_length(ett_apf));
register_dissector(ZBEE_PROTOABBREV_APF, dissect_zbee_apf, proto_zbee_apf);
}
void proto_reg_handoff_zbee_aps(void)
{
data_handle = find_dissector("data");
zbee_aps_handle = find_dissector(ZBEE_PROTOABBREV_APS);
zbee_apf_handle = find_dissector(ZBEE_PROTOABBREV_APF);
}
static void proto_init_zbee_aps(void)
{
fragment_table_init(&zbee_aps_fragment_table);
reassembled_table_init(&zbee_aps_reassembled_table);
}
