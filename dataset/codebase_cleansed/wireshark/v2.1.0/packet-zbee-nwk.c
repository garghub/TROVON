guint
zbee_get_bit_field(guint input, guint mask)
{
if (mask == 0) return 0;
while (!(mask & 0x1)) {
input >>= 1;
mask >>=1;
}
return (input & mask);
}
static gboolean
dissect_zbee_nwk_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
ieee802154_packet *packet = (ieee802154_packet *)data;
guint16 fcf;
guint ver;
if (packet == NULL) return FALSE;
if (packet->src_addr_mode != IEEE802154_FCF_ADDR_SHORT) return FALSE;
if (packet->dst_addr_mode != IEEE802154_FCF_ADDR_SHORT) return FALSE;
fcf = tvb_get_letohs(tvb, 0);
ver = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_VERSION);
if ((ver < ZBEE_VERSION_2004) || (ver > ZBEE_VERSION_2007)) return FALSE;
if (!try_val_to_str(zbee_get_bit_field(fcf, ZBEE_NWK_FCF_FRAME_TYPE), zbee_nwk_frame_types)) return FALSE;
dissect_zbee_nwk(tvb, pinfo, tree, packet);
return TRUE;
}
static int
dissect_zbee_nwk_full(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tvbuff_t *payload_tvb = NULL;
proto_item *proto_root;
proto_item *ti = NULL;
proto_tree *nwk_tree;
zbee_nwk_packet packet;
ieee802154_packet *ieee_packet;
guint offset = 0;
gchar *src_addr, *dst_addr;
guint16 fcf;
ieee802154_short_addr addr16;
ieee802154_map_rec *map_rec;
ieee802154_hints_t *ieee_hints;
zbee_nwk_hints_t *nwk_hints;
gboolean unicast_src;
static const int * fcf_flags_2007[] = {
&hf_zbee_nwk_frame_type,
&hf_zbee_nwk_proto_version,
&hf_zbee_nwk_discover_route,
&hf_zbee_nwk_multicast,
&hf_zbee_nwk_security,
&hf_zbee_nwk_source_route,
&hf_zbee_nwk_ext_dst,
&hf_zbee_nwk_ext_src,
&hf_zbee_nwk_end_device_initiator,
NULL
};
static const int * fcf_flags[] = {
&hf_zbee_nwk_frame_type,
&hf_zbee_nwk_proto_version,
&hf_zbee_nwk_discover_route,
&hf_zbee_nwk_security,
NULL
};
if (data == NULL)
return 0;
ieee_packet = (ieee802154_packet *)data;
memset(&packet, 0, sizeof(packet));
if (!pinfo->fd->flags.visited) {
nwk_hints = wmem_new0(wmem_file_scope(), zbee_nwk_hints_t);
p_add_proto_data(wmem_file_scope(), pinfo, proto_zbee_nwk, 0, nwk_hints);
} else {
nwk_hints = (zbee_nwk_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_zbee_nwk, 0);
}
ieee_hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee");
col_clear(pinfo->cinfo, COL_INFO);
proto_root = proto_tree_add_item(tree, proto_zbee_nwk, tvb, offset, -1, ENC_NA);
nwk_tree = proto_item_add_subtree(proto_root, ett_zbee_nwk);
fcf = tvb_get_letohs(tvb, offset);
packet.type = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_FRAME_TYPE);
packet.version = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_VERSION);
packet.discovery = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_DISCOVER_ROUTE);
packet.security = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_SECURITY);
packet.multicast = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_MULTICAST);
packet.route = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_SOURCE_ROUTE);
packet.ext_dst = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_EXT_DEST);
packet.ext_src = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_EXT_SOURCE);
if (packet.version >= ZBEE_VERSION_2007) {
ti = proto_tree_add_bitmask(nwk_tree, tvb, offset, hf_zbee_nwk_fcf, ett_zbee_nwk_fcf, fcf_flags_2007, ENC_LITTLE_ENDIAN);
} else {
ti = proto_tree_add_bitmask(nwk_tree, tvb, offset, hf_zbee_nwk_fcf, ett_zbee_nwk_fcf, fcf_flags, ENC_LITTLE_ENDIAN);
}
proto_item_append_text(ti, " %s", val_to_str_const(packet.type, zbee_nwk_frame_types, "Unknown"));
offset += 2;
proto_item_append_text(proto_root, " %s", val_to_str_const(packet.type, zbee_nwk_frame_types, "Unknown Type"));
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet.type, zbee_nwk_frame_types, "Reserved Frame Type"));
packet.dst = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(nwk_tree, hf_zbee_nwk_dst, tvb, offset, 2, packet.dst);
offset += 2;
if ( (packet.dst == ZBEE_BCAST_ALL)
|| (packet.dst == ZBEE_BCAST_ACTIVE)
|| (packet.dst == ZBEE_BCAST_ROUTERS)){
dst_addr = wmem_strdup(pinfo->pool, "Broadcast");
}
else {
dst_addr = wmem_strdup_printf(pinfo->pool, "0x%04x", packet.dst);
}
set_address(&pinfo->net_dst, AT_STRINGZ, (int)strlen(dst_addr)+1, dst_addr);
copy_address_shallow(&pinfo->dst, &pinfo->net_dst);
proto_item_append_text(proto_root, ", Dst: %s", dst_addr);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: %s", dst_addr);
packet.src = tvb_get_letohs(tvb, offset);
if (nwk_hints)
nwk_hints->src = packet.src;
proto_tree_add_uint(nwk_tree, hf_zbee_nwk_src, tvb, offset, 2, packet.src);
offset += 2;
if ( (packet.src == ZBEE_BCAST_ALL)
|| (packet.src == ZBEE_BCAST_ACTIVE)
|| (packet.src == ZBEE_BCAST_ROUTERS)){
src_addr = wmem_strdup(pinfo->pool, "Unexpected Source Broadcast");
unicast_src = FALSE;
}
else {
src_addr = wmem_strdup_printf(pinfo->pool, "0x%04x", packet.src);
unicast_src = TRUE;
}
set_address(&pinfo->net_src, AT_STRINGZ, (int)strlen(src_addr)+1, src_addr);
copy_address_shallow(&pinfo->src, &pinfo->net_src);
proto_item_append_text(proto_root, ", Src: %s", src_addr);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Src: %s", src_addr);
packet.radius = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(nwk_tree, hf_zbee_nwk_radius, tvb, offset, 1, packet.radius);
offset += 1;
packet.seqno = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(nwk_tree, hf_zbee_nwk_seqno, tvb, offset, 1, packet.seqno);
offset += 1;
if ((packet.version >= ZBEE_VERSION_2007) && packet.ext_dst) {
packet.dst64 = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(nwk_tree, hf_zbee_nwk_dst64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
}
if (packet.version >= ZBEE_VERSION_2007) {
addr16.pan = ieee_packet->src_pan;
if (packet.ext_src) {
packet.src64 = tvb_get_letoh64(tvb, offset);
proto_tree_add_item(nwk_tree, hf_zbee_nwk_src64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
if (!pinfo->fd->flags.visited && nwk_hints) {
nwk_hints->src_pan = ieee_packet->src_pan;
if ( unicast_src ) {
nwk_hints->map_rec = ieee802154_addr_update(&zbee_nwk_map,
packet.src, addr16.pan, packet.src64, pinfo->current_proto, pinfo->num);
}
}
}
else {
if (!pinfo->fd->flags.visited && nwk_hints) {
nwk_hints->src_pan = ieee_packet->src_pan;
addr16.addr = packet.src;
map_rec = (ieee802154_map_rec *) g_hash_table_lookup(zbee_nwk_map.short_table, &addr16);
if (map_rec) {
nwk_hints->map_rec = map_rec;
}
else {
map_rec = (ieee802154_map_rec *) g_hash_table_lookup(ieee_packet->short_table, &addr16);
if (map_rec) nwk_hints->map_rec = map_rec;
}
}
else {
if (nwk_hints && nwk_hints->map_rec ) {
ti = proto_tree_add_eui64(nwk_tree, hf_zbee_nwk_src64, tvb, offset, 0,
nwk_hints->map_rec->addr64);
PROTO_ITEM_SET_GENERATED(ti);
if ( nwk_hints->map_rec->start_fnum ) {
ti = proto_tree_add_uint(nwk_tree, hf_zbee_nwk_src64_origin, tvb, 0, 0,
nwk_hints->map_rec->start_fnum);
}
else {
ti = proto_tree_add_uint_format_value(nwk_tree, hf_zbee_nwk_src64_origin, tvb, 0, 0, 0, "Pre-configured");
}
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
if (!pinfo->fd->flags.visited) {
if ( (ieee_packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
ieee_hints && !ieee_hints->map_rec ) {
addr16.pan = ieee_packet->src_pan;
addr16.addr = ieee_packet->src16;
map_rec = (ieee802154_map_rec *) g_hash_table_lookup(zbee_nwk_map.short_table, &addr16);
if (map_rec) {
ieee_hints->map_rec = map_rec;
}
}
}
}
if ((packet.version >= ZBEE_VERSION_2007) && packet.multicast) {
static const int * multicast_flags[] = {
&hf_zbee_nwk_mcast_mode,
&hf_zbee_nwk_mcast_radius,
&hf_zbee_nwk_mcast_max_radius,
NULL
};
guint8 mcast_control = tvb_get_guint8(tvb, offset);
packet.mcast_mode = zbee_get_bit_field(mcast_control, ZBEE_NWK_MCAST_MODE);
packet.mcast_radius = zbee_get_bit_field(mcast_control, ZBEE_NWK_MCAST_RADIUS);
packet.mcast_max_radius = zbee_get_bit_field(mcast_control, ZBEE_NWK_MCAST_MAX_RADIUS);
proto_tree_add_bitmask(nwk_tree, tvb, offset, hf_zbee_nwk_mcast, ett_zbee_nwk_mcast, multicast_flags, ENC_NA);
offset += 1;
}
if ((packet.version >= ZBEE_VERSION_2007) && packet.route) {
proto_tree *field_tree;
guint8 relay_count;
guint16 relay_addr;
guint i;
field_tree = proto_tree_add_subtree(nwk_tree, tvb, offset, 1, ett_zbee_nwk_route, &ti, "Source Route");
relay_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(field_tree, hf_zbee_nwk_relay_count, tvb, offset, 1, relay_count);
proto_item_append_text(ti, ", Length: %d", relay_count);
offset += 1;
proto_item_set_len(ti, 1 + relay_count*2);
proto_tree_add_item(field_tree, hf_zbee_nwk_relay_index, tvb, offset, 1, ENC_NA);
offset += 1;
for (i=0; i<relay_count; i++) {
relay_addr = tvb_get_letohs(tvb, offset);
proto_tree_add_uint_format(field_tree, hf_zbee_nwk_relay, tvb, offset, 2, relay_addr, "Relay %d: 0x%04x", i+1, relay_addr);
offset += 2;
}
}
if (offset >= tvb_captured_length(tvb)) {
expert_add_info(pinfo, proto_root, &ei_zbee_nwk_missing_payload);
THROW(BoundsError);
}
else if (packet.security) {
payload_tvb = dissect_zbee_secure(tvb, pinfo, nwk_tree, offset);
if (payload_tvb == NULL) {
return tvb_captured_length(tvb);
}
}
else {
payload_tvb = tvb_new_subset_remaining(tvb, offset);
}
if (packet.type == ZBEE_NWK_FCF_CMD) {
dissect_zbee_nwk_cmd(payload_tvb, pinfo, nwk_tree, &packet);
}
else if (packet.type == ZBEE_NWK_FCF_DATA) {
call_dissector_with_data(aps_handle, payload_tvb, pinfo, tree, &packet);
}
else {
call_data_dissector(payload_tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static int
dissect_zbee_nwk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
guint8 fcf0;
guint8 proto_version;
fcf0 = tvb_get_guint8(tvb, 0);
proto_version = (fcf0 & ZBEE_NWK_FCF_VERSION) >> 2;
if (proto_version == ZBEE_VERSION_GREEN_POWER) {
call_dissector(zbee_gp_handle, tvb, pinfo, tree);
} else {
dissect_zbee_nwk_full(tvb, pinfo, tree, data);
}
return tvb_captured_length(tvb);
}
static void dissect_zbee_nwk_cmd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, zbee_nwk_packet* packet)
{
proto_tree *cmd_tree;
proto_item *cmd_root;
guint offset=0;
guint8 cmd_id = tvb_get_guint8(tvb, offset);
cmd_tree = proto_tree_add_subtree_format(tree, tvb, offset, -1, ett_zbee_nwk_cmd, &cmd_root, "Command Frame: %s",
val_to_str_const(cmd_id, zbee_nwk_cmd_names, "Unknown"));
proto_tree_add_uint(cmd_tree, hf_zbee_nwk_cmd_id, tvb, offset, 1, cmd_id);
offset += 1;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(cmd_id, zbee_nwk_cmd_names, "Unknown Command"));
switch(cmd_id){
case ZBEE_NWK_CMD_ROUTE_REQ:
offset = dissect_zbee_nwk_route_req(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZBEE_NWK_CMD_ROUTE_REPLY:
offset = dissect_zbee_nwk_route_rep(tvb, pinfo, cmd_tree, offset, packet->version);
break;
case ZBEE_NWK_CMD_NWK_STATUS:
offset = dissect_zbee_nwk_status(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_NWK_CMD_LEAVE:
offset = dissect_zbee_nwk_leave(tvb, cmd_tree, offset);
break;
case ZBEE_NWK_CMD_ROUTE_RECORD:
offset = dissect_zbee_nwk_route_rec(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZBEE_NWK_CMD_REJOIN_REQ:
offset = dissect_zbee_nwk_rejoin_req(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZBEE_NWK_CMD_REJOIN_RESP:
offset = dissect_zbee_nwk_rejoin_resp(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZBEE_NWK_CMD_LINK_STATUS:
offset = dissect_zbee_nwk_link_status(tvb, cmd_tree, offset);
break;
case ZBEE_NWK_CMD_NWK_REPORT:
offset = dissect_zbee_nwk_report(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_NWK_CMD_NWK_UPDATE:
offset = dissect_zbee_nwk_update(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_NWK_CMD_ED_TIMEOUT_REQUEST:
offset = dissect_zbee_nwk_ed_timeout_request(tvb, cmd_tree, offset);
break;
case ZBEE_NWK_CMD_ED_TIMEOUT_RESPONSE:
offset = dissect_zbee_nwk_ed_timeout_response(tvb, pinfo, cmd_tree, offset);
break;
case ZBEE_NWK_CMD_LINK_PWR_DELTA:
offset = dissect_zbee_nwk_link_pwr_delta(tvb, pinfo, cmd_tree, offset);
break;
default:
break;
}
if (offset < tvb_captured_length(tvb)) {
tvbuff_t *leftover_tvb = tvb_new_subset_remaining(tvb, offset);
proto_tree *root;
root = proto_tree_get_root(tree);
proto_item_set_len(cmd_root, offset);
call_data_dissector(leftover_tvb, pinfo, root);
}
}
static guint
dissect_zbee_nwk_route_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, zbee_nwk_packet * packet, guint offset)
{
guint8 route_options;
guint16 dest_addr;
static const int * nwk_route_command_options_2007[] = {
&hf_zbee_nwk_cmd_route_opt_multicast,
&hf_zbee_nwk_cmd_route_opt_dest_ext,
&hf_zbee_nwk_cmd_route_opt_many_to_one,
NULL
};
static const int * nwk_route_command_options[] = {
&hf_zbee_nwk_cmd_route_opt_repair,
NULL
};
route_options = tvb_get_guint8(tvb, offset);
if (packet->version >= ZBEE_VERSION_2007) {
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_cmd_route_options, ett_zbee_nwk_cmd_options, nwk_route_command_options_2007, ENC_NA);
} else {
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_cmd_route_options, ett_zbee_nwk_cmd_options, nwk_route_command_options, ENC_NA);
}
offset += 1;
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_id, tvb, offset, 1, ENC_NA);
offset += 1;
dest_addr = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_dest, tvb, offset, 2, dest_addr);
offset += 2;
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_cost, tvb, offset, 1, ENC_NA);
offset += 1;
if (route_options & ZBEE_NWK_CMD_ROUTE_OPTION_DEST_EXT) {
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_dest_ext, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: 0x%04x, Src: 0x%04x", dest_addr, packet->src);
return offset;
}
static guint
dissect_zbee_nwk_route_rep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint8 version)
{
guint8 route_options;
guint16 orig_addr;
guint16 resp_addr;
static const int * nwk_route_command_options_2007[] = {
&hf_zbee_nwk_cmd_route_opt_multicast,
&hf_zbee_nwk_cmd_route_opt_resp_ext,
&hf_zbee_nwk_cmd_route_opt_orig_ext,
NULL
};
static const int * nwk_route_command_options[] = {
&hf_zbee_nwk_cmd_route_opt_repair,
NULL
};
route_options = tvb_get_guint8(tvb, offset);
if (version >= ZBEE_VERSION_2007) {
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_cmd_route_options, ett_zbee_nwk_cmd_options, nwk_route_command_options_2007, ENC_NA);
} else {
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_cmd_route_options, ett_zbee_nwk_cmd_options, nwk_route_command_options, ENC_NA);
}
offset += 1;
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_id, tvb, offset, 1, ENC_NA);
offset += 1;
orig_addr = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_orig, tvb, offset, 2, orig_addr);
offset += 2;
resp_addr = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_resp, tvb, offset, 2, resp_addr);
offset += 2;
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_cost, tvb, offset, 1, ENC_NA);
offset += 1;
if (route_options & ZBEE_NWK_CMD_ROUTE_OPTION_ORIG_EXT) {
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_orig_ext, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
}
if (route_options & ZBEE_NWK_CMD_ROUTE_OPTION_RESP_EXT) {
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_resp_ext, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: 0x%04x, Src: 0x%04x", resp_addr, orig_addr);
return offset;
}
static guint
dissect_zbee_nwk_status(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 status_code;
guint8 command_id;
guint16 addr;
status_code = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_nwk_status, tvb, offset, 1, status_code);
offset += 1;
addr = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_dest, tvb, offset, 2, addr);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", 0x%04x: %s", addr, val_to_str_const(status_code, zbee_nwk_status_codes, "Unknown Status Code"));
if (status_code == ZBEE_NWK_STATUS_UNKNOWN_COMMAND) {
command_id = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_nwk_status_command_id, tvb, offset, 1, command_id);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Unknown Command ID 0x%02x (%s)", command_id,
val_to_str_const(command_id, zbee_nwk_cmd_names, "Unknown ID"));
offset++;
}
return offset;
}
static guint
dissect_zbee_nwk_leave(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
static const int * leave_options[] = {
&hf_zbee_nwk_cmd_leave_rejoin,
&hf_zbee_nwk_cmd_leave_request,
&hf_zbee_nwk_cmd_leave_children,
NULL
};
proto_tree_add_bitmask_list(tree, tvb, offset, 1, leave_options, ENC_NA);
offset += 1;
return offset;
}
static guint
dissect_zbee_nwk_route_rec(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, zbee_nwk_packet * packet, guint offset)
{
guint8 relay_count;
guint16 relay_addr;
guint i;
relay_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_relay_count, tvb, offset, 1, relay_count);
offset += 1;
for (i=0; i<relay_count; i++) {
relay_addr = tvb_get_letohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_zbee_nwk_cmd_relay_device, tvb, offset, 2, relay_addr,
"Relay Device %d: 0x%04x", i+1, relay_addr);
offset += 2;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: 0x%04x", packet->dst);
return offset;
}
static guint
dissect_zbee_nwk_rejoin_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, zbee_nwk_packet * packet, guint offset)
{
static const int * capabilities[] = {
&hf_zbee_nwk_cmd_cinfo_alt_coord,
&hf_zbee_nwk_cmd_cinfo_type,
&hf_zbee_nwk_cmd_cinfo_power,
&hf_zbee_nwk_cmd_cinfo_idle_rx,
&hf_zbee_nwk_cmd_cinfo_security,
&hf_zbee_nwk_cmd_cinfo_alloc,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_cmd_cinfo, ett_zbee_nwk_cmd_cinfo, capabilities, ENC_NA);
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Device: 0x%04x", packet->src);
return offset;
}
static guint
dissect_zbee_nwk_rejoin_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, zbee_nwk_packet * packet _U_, guint offset)
{
guint8 status;
guint16 new_address;
new_address = tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_zbee_nwk_cmd_addr, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
status = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_rejoin_status, tvb, offset, 1, status);
offset += 1;
if (status == IEEE802154_CMD_ASRSP_AS_SUCCESS) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", New Address: 0x%04x", new_address);
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str_const(status, zbee_nwk_rejoin_codes, "Unknown Rejoin Response"));
}
return offset;
}
static guint
dissect_zbee_nwk_link_status(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
guint8 options;
int i, link_count;
proto_tree *subtree;
static const int * link_options[] = {
&hf_zbee_nwk_cmd_link_last,
&hf_zbee_nwk_cmd_link_first,
&hf_zbee_nwk_cmd_link_count,
NULL
};
options = tvb_get_guint8(tvb, offset);
link_count = options & ZBEE_NWK_CMD_LINK_OPTION_COUNT_MASK;
proto_tree_add_bitmask_list(tree, tvb, offset, 1, link_options, ENC_NA);
offset += 1;
for (i=0; i<link_count; i++) {
subtree = proto_tree_add_subtree_format(tree, tvb, offset, 3, ett_zbee_nwk_cmd_link, NULL, "Link %d", i+1);
proto_tree_add_item(subtree, hf_zbee_nwk_cmd_link_address, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_zbee_nwk_cmd_link_incoming_cost, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(subtree, hf_zbee_nwk_cmd_link_outgoing_cost, tvb, offset+2, 1, ENC_NA);
offset += (2+1);
}
return offset;
}
static guint
dissect_zbee_nwk_ed_timeout_request(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree_add_item(tree, hf_zbee_nwk_cmd_end_device_timeout_request_enum, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_zbee_nwk_cmd_end_device_configuration, tvb, offset, 1, ENC_NA);
offset++;
return offset;
}
static guint
dissect_zbee_nwk_ed_timeout_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
static const int * end_device_parent_info[] = {
&hf_zbee_nwk_cmd_prnt_info_mac_data_poll_keepalive_supported,
&hf_zbee_nwk_cmd_prnt_info_ed_to_req_keepalive_supported,
NULL
};
guint status = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_zbee_nwk_cmd_end_device_timeout_resp_status, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_cmd_end_device_timeout_resp_parent_info, ett_zbee_nwk_cmd_ed_to_rsp_prnt_info, end_device_parent_info, ENC_NA);
offset++;
proto_item_append_text(tree, ", %s", val_to_str_const(status, zbee_nwk_end_device_timeout_resp_status, "Unknown Status"));
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str_const(status, zbee_nwk_end_device_timeout_resp_status, "Unknown Status"));
return offset;
}
static guint
dissect_zbee_nwk_link_pwr_delta(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
int i;
int count;
gint delta;
guint8 type;
guint16 addr;
proto_tree *subtree;
type = tvb_get_guint8(tvb, offset) & ZBEE_NWK_CMD_NWK_LINK_PWR_DELTA_TYPE_MASK;
proto_tree_add_item(tree, hf_zbee_nwk_cmd_link_pwr_type, tvb, offset, 1, ENC_NA);
offset++;
count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_zbee_nwk_cmd_link_pwr_list_count, tvb, offset, 1, ENC_NA);
offset++;
proto_item_append_text(tree, ": %s, Count %d", val_to_str_const(type, zbee_nwk_link_power_delta_types, "Unknown"), count);
for (i=0; i<count; i++) {
subtree = proto_tree_add_subtree(tree, tvb, count, 3, ett_zbee_nwk_cmd_link_pwr_struct, NULL, "Power Delta Structure");
addr = tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_zbee_nwk_cmd_link_pwr_device_address, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
delta = (char)tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_zbee_nwk_cmd_link_pwr_power_delta, tvb, offset, 1, ENC_NA);
offset++;
proto_item_append_text(subtree, ": Device Address 0x%04X, Power Delta %d dBm", addr, delta);
}
return offset;
}
static guint
dissect_zbee_nwk_report(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 options;
guint8 report_type;
int report_count;
int i;
options = tvb_get_guint8(tvb, offset);
report_count = options & ZBEE_NWK_CMD_NWK_REPORT_COUNT_MASK;
report_type = options & ZBEE_NWK_CMD_NWK_REPORT_ID_MASK;
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_report_type, tvb, offset, 1, report_type);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_report_count, tvb, offset, 1, report_count);
offset += 1;
proto_tree_add_item(tree, hf_zbee_nwk_cmd_epid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
if (report_type == ZBEE_NWK_CMD_NWK_REPORT_ID_PAN_CONFLICT) {
for (i=0; i<report_count; i++) {
proto_tree_add_item(tree, hf_zbee_nwk_panid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str_const(report_type, zbee_nwk_report_types, "Unknown Report Type"));
return offset;
}
static guint
dissect_zbee_nwk_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 options;
guint8 update_type;
guint8 update_id;
int update_count;
int i;
options = tvb_get_guint8(tvb, offset);
update_count = options & ZBEE_NWK_CMD_NWK_UPDATE_COUNT_MASK;
update_type = options & ZBEE_NWK_CMD_NWK_UPDATE_ID_MASK;
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_update_type, tvb, offset, 1, update_type);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_update_count, tvb, offset, 1, update_count);
offset += 1;
proto_tree_add_item(tree, hf_zbee_nwk_cmd_epid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
update_id = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_update_id, tvb, offset, 1, update_id);
offset += 1;
if (update_type == ZBEE_NWK_CMD_NWK_UPDATE_ID_PAN_UPDATE) {
for (i=0; i<update_count; i++) {
proto_tree_add_item(tree, hf_zbee_nwk_panid, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str_const(update_type, zbee_nwk_update_types, "Unknown Update Type"));
return offset;
}
static gboolean
dissect_zbee_beacon_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
ieee802154_packet *packet = (ieee802154_packet *)data;
if (!packet) return FALSE;
if (packet->src_addr_mode != IEEE802154_FCF_ADDR_SHORT) return FALSE;
if (tvb_get_guint8(tvb, 0) != ZBEE_NWK_BEACON_PROTOCOL_ID) return FALSE;
dissect_zbee_beacon(tvb, pinfo, tree, packet);
return TRUE;
}
static int dissect_zbee_beacon(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *beacon_root;
proto_tree *beacon_tree;
guint offset = 0;
guint8 version;
guint32 profile;
static const int * beacon_fields[] = {
&hf_zbee_beacon_stack_profile,
&hf_zbee_beacon_version,
&hf_zbee_beacon_router_capacity,
&hf_zbee_beacon_depth,
&hf_zbee_beacon_end_device_capacity,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee");
beacon_root = proto_tree_add_item(tree, proto_zbee_beacon, tvb, 0, -1, ENC_NA);
beacon_tree = proto_item_add_subtree(beacon_root, ett_zbee_nwk_beacon);
proto_tree_add_item(beacon_tree, hf_zbee_beacon_protocol, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_bitmask_text(beacon_tree, tvb, offset, 2, "Beacon: ", NULL , ett_zbee_nwk_beacon_bitfield, beacon_fields,
ENC_LITTLE_ENDIAN, BMT_NO_INT|BMT_NO_TFS);
version = (guint8)((tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN) & ZBEE_NWK_BEACON_PROTOCOL_VERSION) >> 4);
profile = (guint32)(tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN) & ZBEE_NWK_BEACON_STACK_PROFILE);
proto_item_append_text(beacon_root, ", %s", val_to_str_const(profile, zbee_nwk_stack_profiles, "Unknown Profile"));
offset += 2;
if (version >= ZBEE_VERSION_2007) {
proto_tree_add_item(beacon_tree, hf_zbee_beacon_epid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, ", EPID: %s", eui64_to_display(wmem_packet_scope(),
tvb_get_guint64(tvb, offset, ENC_LITTLE_ENDIAN)));
proto_item_append_text(beacon_root, ", EPID: %s", eui64_to_display(wmem_packet_scope(),
tvb_get_guint64(tvb, offset, ENC_LITTLE_ENDIAN)));
offset += 8;
if (tvb_bytes_exist(tvb, offset, 3)) {
proto_tree_add_item(beacon_tree, hf_zbee_beacon_tx_offset, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
if(tvb_captured_length_remaining(tvb, offset)) {
proto_tree_add_item(beacon_tree, hf_zbee_beacon_update_id, tvb, offset, 1, ENC_NA);
offset += 1;
}
}
}
else if (tvb_bytes_exist(tvb, offset, 3)) {
proto_tree_add_item(beacon_tree, hf_zbee_beacon_tx_offset, tvb, offset, 3, ENC_LITTLE_ENDIAN);
offset += 3;
}
return offset;
}
static gboolean
dissect_zbip_beacon_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
ieee802154_packet *packet = (ieee802154_packet *)data;
if (!packet) return FALSE;
if (packet->src_addr_mode != IEEE802154_FCF_ADDR_SHORT) return FALSE;
if (tvb_get_guint8(tvb, 0) != ZBEE_IP_BEACON_PROTOCOL_ID) return FALSE;
dissect_zbip_beacon(tvb, pinfo, tree, packet);
return TRUE;
}
static int dissect_zbip_beacon(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
ieee802154_packet *packet = (ieee802154_packet *)data;
proto_item *beacon_root;
proto_tree *beacon_tree;
guint offset = 0;
guint8 proto_id;
char *ssid;
if (!packet) return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee IP");
beacon_root = proto_tree_add_item(tree, proto_zbip_beacon, tvb, 0, -1, ENC_NA);
beacon_tree = proto_item_add_subtree(beacon_root, ett_zbee_nwk_beacon);
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "Beacon, Src: 0x%04x", packet->src16);
proto_id = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(beacon_tree, hf_zbee_beacon_protocol, tvb, offset, 1, proto_id);
offset += 1;
proto_tree_add_item(beacon_tree, hf_zbip_beacon_allow_join, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(beacon_tree, hf_zbip_beacon_router_capacity, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(beacon_tree, hf_zbip_beacon_host_capacity, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(beacon_tree, hf_zbip_beacon_unsecure, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(beacon_tree, hf_zbip_beacon_network_id, tvb, offset, 16, ENC_ASCII|ENC_NA);
ssid = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 16, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, ", SSID: %s", ssid);
offset += 16;
if (offset < tvb_captured_length(tvb)) {
tvbuff_t *leftover_tvb = tvb_new_subset_remaining(tvb, offset);
proto_tree *root;
root = proto_tree_get_root(tree);
proto_item_set_len(beacon_root, offset);
call_data_dissector(leftover_tvb, pinfo, root);
}
return tvb_captured_length(tvb);
}
static int
dissect_zbee_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_tree *subtree;
tvbuff_t *ie_tvb;
guint16 zigbee_ie;
guint16 id;
guint16 length;
guint pie_length;
guint offset = 0;
static const int * fields[] = {
&hf_ieee802154_zigbee_ie_id,
&hf_ieee802154_zigbee_ie_length,
NULL
};
pie_length = *(gint *)data;
do {
zigbee_ie = tvb_get_letohs(tvb, offset);
id = (zigbee_ie & ZBEE_ZIGBEE_IE_ID_MASK) >> 6;
length = zigbee_ie & ZBEE_ZIGBEE_IE_LENGTH_MASK;
subtree = proto_tree_add_subtree(tree, tvb, offset, 2+length, ett_zbee_nwk_header, NULL, "ZigBee IE");
proto_item_append_text(subtree, ", %s, Length: %d", val_to_str_const(id, ieee802154_zigbee_ie_names, "Unknown"), length);
proto_tree_add_bitmask(subtree, tvb, offset, hf_ieee802154_zigbee_ie,
ett_zbee_nwk_zigbee_ie_fields, fields, ENC_LITTLE_ENDIAN);
offset += 2;
switch (id) {
case ZBEE_ZIGBEE_IE_REJOIN:
dissect_ieee802154_zigbee_rejoin(tvb, pinfo, subtree, &offset);
break;
case ZBEE_ZIGBEE_IE_TX_POWER:
dissect_ieee802154_zigbee_txpower(tvb, pinfo, subtree, &offset);
break;
case ZBEE_ZIGBEE_IE_BEACON_PAYLOAD:
ie_tvb = tvb_new_subset_length(tvb, offset, ZBEE_NWK_BEACON_LENGTH);
offset += dissect_zbee_beacon(ie_tvb, pinfo, subtree, NULL);
dissect_ieee802154_superframe(tvb, pinfo, subtree, &offset);
proto_tree_add_item(subtree, hf_ieee802154_zigbee_ie_source_addr, tvb, offset, 2, ENC_NA);
offset += 2;
break;
default:
if (length > 0) {
call_data_dissector(tvb, pinfo, tree);
offset += length;
}
break;
}
} while (offset < pie_length);
return tvb_captured_length(tvb);
}
static void
dissect_ieee802154_zigbee_txpower(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
gint32 txpower;
txpower = (char)tvb_get_guint8(tvb, *offset);
proto_tree_add_item_ret_int(tree, hf_ieee802154_zigbee_ie_tx_power, tvb, *offset, 1, ENC_NA, &txpower);
proto_item_append_text(tree, ", TX Power %d dBm", txpower);
*offset += 1;
}
static void
dissect_ieee802154_zigbee_rejoin(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
proto_tree *subtree;
subtree = proto_tree_add_subtree(tree, tvb, *offset, 10, ett_zbee_nwk_ie_rejoin, NULL, "ZigBee Rejoin");
proto_tree_add_item(subtree, hf_ieee802154_zigbee_rejoin_epid, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
proto_item_append_text(tree, ", EPID %s", eui64_to_display(wmem_packet_scope(),
tvb_get_guint64(tvb, *offset, ENC_LITTLE_ENDIAN)));
*offset += 8;
proto_tree_add_item(subtree, hf_ieee802154_zigbee_rejoin_source_addr, tvb, *offset, 2, ENC_NA);
proto_item_append_text(tree, ", Src: 0x%04x",
tvb_get_guint16(tvb, *offset, ENC_LITTLE_ENDIAN));
*offset += 2;
}
void proto_register_zbee_nwk(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_nwk_fcf,
{ "Frame Control Field", "zbee_nwk.fcf", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_frame_type,
{ "Frame Type", "zbee_nwk.frame_type", FT_UINT16, BASE_HEX, VALS(zbee_nwk_frame_types),
ZBEE_NWK_FCF_FRAME_TYPE, NULL, HFILL }},
{ &hf_zbee_nwk_proto_version,
{ "Protocol Version", "zbee_nwk.proto_version", FT_UINT16, BASE_DEC, NULL, ZBEE_NWK_FCF_VERSION,
NULL, HFILL }},
{ &hf_zbee_nwk_discover_route,
{ "Discover Route", "zbee_nwk.discovery", FT_UINT16, BASE_HEX, VALS(zbee_nwk_discovery_modes),
ZBEE_NWK_FCF_DISCOVER_ROUTE,
"Determines how route discovery may be handled, if at all.", HFILL }},
{ &hf_zbee_nwk_multicast,
{ "Multicast", "zbee_nwk.multicast", FT_BOOLEAN, 16, NULL, ZBEE_NWK_FCF_MULTICAST,
NULL, HFILL }},
{ &hf_zbee_nwk_security,
{ "Security", "zbee_nwk.security", FT_BOOLEAN, 16, NULL, ZBEE_NWK_FCF_SECURITY,
"Whether or not security operations are performed on the network payload.", HFILL }},
{ &hf_zbee_nwk_source_route,
{ "Source Route", "zbee_nwk.src_route", FT_BOOLEAN, 16, NULL, ZBEE_NWK_FCF_SOURCE_ROUTE,
NULL, HFILL }},
{ &hf_zbee_nwk_ext_dst,
{ "Destination", "zbee_nwk.ext_dst", FT_BOOLEAN, 16, NULL, ZBEE_NWK_FCF_EXT_DEST,
NULL, HFILL }},
{ &hf_zbee_nwk_ext_src,
{ "Extended Source", "zbee_nwk.ext_src", FT_BOOLEAN, 16, NULL, ZBEE_NWK_FCF_EXT_SOURCE,
NULL, HFILL }},
{ &hf_zbee_nwk_end_device_initiator,
{ "End Device Initiator", "zbee_nwk.end_device_initiator", FT_BOOLEAN, 16, NULL, ZBEE_NWK_FCF_END_DEVICE_INITIATOR,
NULL, HFILL }},
{ &hf_zbee_nwk_dst,
{ "Destination", "zbee_nwk.dst", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_src,
{ "Source", "zbee_nwk.src", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_radius,
{ "Radius", "zbee_nwk.radius", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of hops remaining for a range-limited broadcast packet.", HFILL }},
{ &hf_zbee_nwk_seqno,
{ "Sequence Number", "zbee_nwk.seqno", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_mcast,
{ "Multicast Control Field", "zbee_nwk.multicast.cf", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_mcast_mode,
{ "Multicast Mode", "zbee_nwk.multicast.mode", FT_UINT8, BASE_DEC, NULL, ZBEE_NWK_MCAST_MODE,
"Controls whether this packet is permitted to be routed through non-members of the multicast group.",
HFILL }},
{ &hf_zbee_nwk_mcast_radius,
{ "Non-Member Radius", "zbee_nwk.multicast.radius", FT_UINT8, BASE_DEC, NULL, ZBEE_NWK_MCAST_RADIUS,
"Limits the range of multicast packets when being routed through non-members.", HFILL }},
{ &hf_zbee_nwk_mcast_max_radius,
{ "Max Non-Member Radius", "zbee_nwk.multicast.max_radius", FT_UINT8, BASE_DEC, NULL,
ZBEE_NWK_MCAST_MAX_RADIUS, NULL, HFILL }},
{ &hf_zbee_nwk_dst64,
{ "Destination", "zbee_nwk.dst64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_src64,
{ "Extended Source", "zbee_nwk.src64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_src64_origin,
{ "Origin", "zbee_nwk.src64.origin", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_relay_count,
{ "Relay Count", "zbee_nwk.relay.count", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of entries in the relay list.", HFILL }},
{ &hf_zbee_nwk_relay_index,
{ "Relay Index", "zbee_nwk.relay.index", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of relays required to route to the source device.", HFILL }},
{ &hf_zbee_nwk_relay,
{ "Relay", "zbee_nwk.relay", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_id,
{ "Command Identifier", "zbee_nwk.cmd.id", FT_UINT8, BASE_HEX, VALS(zbee_nwk_cmd_names), 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_addr,
{ "Address", "zbee_nwk.cmd.addr", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_id,
{ "Route ID", "zbee_nwk.cmd.route.id", FT_UINT8, BASE_DEC, NULL, 0x0,
"A sequence number for routing commands.", HFILL }},
{ &hf_zbee_nwk_cmd_route_dest,
{ "Destination", "zbee_nwk.cmd.route.dest", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_orig,
{ "Originator", "zbee_nwk.cmd.route.orig", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_resp,
{ "Responder", "zbee_nwk.cmd.route.resp", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_dest_ext,
{ "Extended Destination", "zbee_nwk.cmd.route.dest_ext", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_orig_ext,
{ "Extended Originator", "zbee_nwk.cmd.route.orig_ext", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_resp_ext,
{ "Extended Responder", "zbee_nwk.cmd.route.resp_ext", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_cost,
{ "Path Cost", "zbee_nwk.cmd.route.cost", FT_UINT8, BASE_DEC, NULL, 0x0,
"A value specifying the efficiency of this route.", HFILL }},
{ &hf_zbee_nwk_cmd_route_options,
{ "Command Options", "zbee_nwk.cmd.route.opts", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_opt_repair,
{ "Route Repair", "zbee_nwk.cmd.route.opts.repair", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_ROUTE_OPTION_REPAIR,
"Flag identifying whether the route request command was to repair a failed route.", HFILL }},
{ &hf_zbee_nwk_cmd_route_opt_multicast,
{ "Multicast", "zbee_nwk.cmd.route.opts.mcast", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_ROUTE_OPTION_MCAST,
"Flag identifying this as a multicast route request.", HFILL }},
{ &hf_zbee_nwk_cmd_route_opt_dest_ext,
{ "Extended Destination", "zbee_nwk.cmd.route.opts.dest_ext", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_ROUTE_OPTION_DEST_EXT, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_opt_resp_ext,
{ "Extended Responder", "zbee_nwk.cmd.route.opts.resp_ext", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_ROUTE_OPTION_RESP_EXT, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_opt_orig_ext,
{ "Extended Originator", "zbee_nwk.cmd.route.opts.orig_ext", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_ROUTE_OPTION_ORIG_EXT, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_route_opt_many_to_one,
{ "Many-to-One Discovery", "zbee_nwk.cmd.route.opts.many2one", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_cmd_route_many_modes), ZBEE_NWK_CMD_ROUTE_OPTION_MANY_MASK,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_nwk_status,
{ "Status Code", "zbee_nwk.cmd.status", FT_UINT8, BASE_HEX, VALS(zbee_nwk_status_codes), 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_nwk_status_command_id,
{ "Unknown Command ID", "zbee_nwk.cmd.status.unknown_command_id", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_cmd_names), 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_leave_rejoin,
{ "Rejoin", "zbee_nwk.cmd.leave.rejoin", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_LEAVE_OPTION_REJOIN, "Flag instructing the device to rejoin the network.", HFILL }},
{ &hf_zbee_nwk_cmd_leave_request,
{ "Request", "zbee_nwk.cmd.leave.request", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_LEAVE_OPTION_REQUEST,
"Flag identifying the direction of this command. 1=Request, 0=Indication", HFILL }},
{ &hf_zbee_nwk_cmd_leave_children,
{ "Remove Children", "zbee_nwk.cmd.leave.children", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_LEAVE_OPTION_CHILDREN,
"Flag instructing the device to remove its children in addition to itself.", HFILL }},
{ &hf_zbee_nwk_cmd_relay_count,
{ "Relay Count", "zbee_nwk.cmd.relay_count", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of relays required to route to the destination.", HFILL }},
{ &hf_zbee_nwk_cmd_relay_device,
{ "Relay Device", "zbee_nwk.cmd.relay_device", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_cinfo,
{ "Capability Information", "zbee_nwk.cmd.cinfo", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_cinfo_alt_coord,
{ "Alternate Coordinator", "zbee_nwk.cmd.cinfo.alt_coord", FT_BOOLEAN, 8, NULL,
IEEE802154_CMD_CINFO_ALT_PAN_COORD,
"Indicates that the device is able to operate as a PAN coordinator.", HFILL }},
{ &hf_zbee_nwk_cmd_cinfo_type,
{ "Full-Function Device", "zbee_nwk.cmd.cinfo.ffd", FT_BOOLEAN, 8, NULL,
IEEE802154_CMD_CINFO_DEVICE_TYPE, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_cinfo_power,
{ "AC Power", "zbee_nwk.cmd.cinfo.power", FT_BOOLEAN, 8, NULL,
IEEE802154_CMD_CINFO_POWER_SRC, "Indicates this device is using AC/Mains power.", HFILL }},
{ &hf_zbee_nwk_cmd_cinfo_idle_rx,
{ "Rx On When Idle", "zbee_nwk.cmd.cinfo.power", FT_BOOLEAN, 8, NULL,
IEEE802154_CMD_CINFO_IDLE_RX,
"Indicates the receiver is active when the device is idle.", HFILL }},
{ &hf_zbee_nwk_cmd_cinfo_security,
{ "Security Capability", "zbee_nwk.cmd.cinfo.security", FT_BOOLEAN, 8, NULL,
IEEE802154_CMD_CINFO_SEC_CAPABLE,
"Indicates this device is capable of performing encryption/decryption.", HFILL }},
{ &hf_zbee_nwk_cmd_cinfo_alloc,
{ "Allocate Short Address", "zbee_nwk.cmd.cinfo.alloc", FT_BOOLEAN, 8, NULL,
IEEE802154_CMD_CINFO_ALLOC_ADDR,
"Flag requesting the parent to allocate a short address for this device.", HFILL }},
{ &hf_zbee_nwk_cmd_rejoin_status,
{ "Status", "zbee_nwk.cmd.rejoin_status", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_rejoin_codes), 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_link_last,
{ "Last Frame", "zbee_nwk.cmd.link.last", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_LINK_OPTION_LAST_FRAME,
"Flag indicating the last in a series of link status commands.", HFILL }},
{ &hf_zbee_nwk_cmd_link_first,
{ "First Frame", "zbee_nwk.cmd.link.first", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_LINK_OPTION_FIRST_FRAME,
"Flag indicating the first in a series of link status commands.", HFILL }},
{ &hf_zbee_nwk_cmd_link_count,
{ "Link Status Count", "zbee_nwk.cmd.link.count", FT_UINT8, BASE_DEC, NULL,
ZBEE_NWK_CMD_LINK_OPTION_COUNT_MASK, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_link_address,
{ "Address", "zbee_nwk.cmd.link.address", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_link_incoming_cost,
{ "Incoming Cost", "zbee_nwk.cmd.link.incoming_cost", FT_UINT8, BASE_DEC, NULL,
ZBEE_NWK_CMD_LINK_INCOMMING_COST_MASK, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_link_outgoing_cost,
{ "Outgoing Cost", "zbee_nwk.cmd.link.outgoing_cost", FT_UINT8, BASE_DEC, NULL,
ZBEE_NWK_CMD_LINK_OUTGOING_COST_MASK, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_report_type,
{ "Report Type", "zbee_nwk.cmd.report.type", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_report_types), ZBEE_NWK_CMD_NWK_REPORT_ID_MASK, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_report_count,
{ "Report Information Count", "zbee_nwk.cmd.report.count", FT_UINT8, BASE_DEC, NULL,
ZBEE_NWK_CMD_NWK_REPORT_COUNT_MASK, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_update_type,
{ "Update Type", "zbee_nwk.cmd.update.type", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_update_types), ZBEE_NWK_CMD_NWK_UPDATE_ID_MASK, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_update_count,
{ "Update Information Count", "zbee_nwk.cmd.update.count", FT_UINT8, BASE_DEC, NULL,
ZBEE_NWK_CMD_NWK_UPDATE_COUNT_MASK, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_update_id,
{ "Update ID", "zbee_nwk.cmd.update.id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_panid,
{ "PAN ID", "zbee_nwk.panid", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_epid,
{ "Extended PAN ID", "zbee_nwk.cmd.epid", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_end_device_timeout_request_enum,
{ "Requested Timeout Enumeration", "zbee_nwk.cmd.ed_tmo_req", FT_UINT8, BASE_DEC,
VALS(zbee_nwk_end_device_timeout_request), 0, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_end_device_configuration,
{ "End Device Configuration", "zbee_nwk.cmd.ed_config", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_end_device_timeout_resp_status,
{ "Status", "zbee_nwk.cmd.ed_tmo_rsp_status", FT_UINT8, BASE_DEC,
VALS(zbee_nwk_end_device_timeout_resp_status), 0, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_end_device_timeout_resp_parent_info,
{ "Parent Information", "zbee_nwk.cmd.ed_prnt_info", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_prnt_info_mac_data_poll_keepalive_supported,
{ "MAC Data Poll Keepalive", "zbee_nwk.cmd.ed_prnt_info.mac_data_poll_keepalive", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_ED_TIMEO_RSP_PRNT_INFO_MAC_DATA_POLL_KEEPAL_SUPP,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_prnt_info_ed_to_req_keepalive_supported,
{ "End Device Timeout Request Keepalive", "zbee_nwk.cmd.ed_prnt_info.ed_tmo_req_keepalive", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_CMD_ED_TIMEO_RSP_PRNT_INFO_ED_TIMOU_REQ_KEEPAL_SUPP,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_link_pwr_type,
{ "Type", "zbee_nwk.cmd.link_pwr_delta.type", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_link_power_delta_types), ZBEE_NWK_CMD_NWK_LINK_PWR_DELTA_TYPE_MASK, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_link_pwr_list_count,
{ "Structure Count", "zbee_nwk.cmd.link_pwr_delta.list_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_nwk_cmd_link_pwr_device_address,
{ "Device Address", "zbee_nwk.cmd.link_pwr_delta.address", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_link_pwr_power_delta,
{ "Power Delta", "zbee_nwk.cmd.link_pwr_delta.power_delta", FT_INT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_beacon_protocol,
{ "Protocol ID", "zbee_beacon.protocol", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_beacon_stack_profile,
{ "Stack Profile", "zbee_beacon.profile", FT_UINT16, BASE_HEX,
VALS(zbee_nwk_stack_profiles), ZBEE_NWK_BEACON_STACK_PROFILE, NULL, HFILL }},
{ &hf_zbee_beacon_version,
{ "Protocol Version", "zbee_beacon.version", FT_UINT16, BASE_DEC, NULL, ZBEE_NWK_BEACON_PROTOCOL_VERSION,
NULL, HFILL }},
{ &hf_zbee_beacon_router_capacity,
{ "Router Capacity", "zbee_beacon.router", FT_BOOLEAN, 16, NULL, ZBEE_NWK_BEACON_ROUTER_CAPACITY,
"Whether the device can accept join requests from routing capable devices.", HFILL }},
{ &hf_zbee_beacon_depth,
{ "Device Depth", "zbee_beacon.depth", FT_UINT16, BASE_DEC, NULL, ZBEE_NWK_BEACON_NETWORK_DEPTH,
"The tree depth of the device, 0 indicates the network coordinator.", HFILL }},
{ &hf_zbee_beacon_end_device_capacity,
{ "End Device Capacity", "zbee_beacon.end_dev", FT_BOOLEAN, 16, NULL, ZBEE_NWK_BEACON_END_DEVICE_CAPACITY,
"Whether the device can accept join requests from ZigBee end devices.", HFILL }},
{ &hf_zbee_beacon_epid,
{ "Extended PAN ID", "zbee_beacon.ext_panid", FT_EUI64, BASE_NONE, NULL, 0x0,
"Extended PAN identifier.", HFILL }},
{ &hf_zbee_beacon_tx_offset,
{ "Tx Offset", "zbee_beacon.tx_offset", FT_UINT24, BASE_DEC, NULL, 0x0,
"The time difference between a device and its parent's beacon.", HFILL }},
{ &hf_zbee_beacon_update_id,
{ "Update ID", "zbee_beacon.update_id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbip_beacon_allow_join,
{ "Allow Join", "zbip_beacon.allow_join", FT_BOOLEAN, 8, NULL, ZBEE_IP_BEACON_ALLOW_JOIN,
NULL, HFILL }},
{ &hf_zbip_beacon_router_capacity,
{ "Router Capacity", "zbip_beacon.router", FT_BOOLEAN, 8, NULL, ZBEE_IP_BEACON_ROUTER_CAPACITY,
"Whether this device can accept new routers on the network.", HFILL }},
{ &hf_zbip_beacon_host_capacity,
{ "Host Capacity", "zbip_beacon.host", FT_BOOLEAN, 8, NULL, ZBEE_IP_BEACON_HOST_CAPACITY,
"Whether this device can accept new host on the network.", HFILL }},
{ &hf_zbip_beacon_unsecure,
{ "Unsecure Network", "zbip_beacon.unsecure", FT_BOOLEAN, 8, NULL, ZBEE_IP_BEACON_UNSECURE,
"Indicates that this network is not using link layer security.", HFILL }},
{ &hf_zbip_beacon_network_id,
{ "Network ID", "zbip_beacon.network_id", FT_STRING, BASE_NONE, NULL, 0x0,
"A string that uniquely identifies this network.", HFILL }},
{ &hf_ieee802154_zigbee_ie,
{ "IE header", "zbee_nwk.zigbee_ie", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ieee802154_zigbee_ie_id,
{ "Id", "zbee_nwk.zigbee_ie.id", FT_UINT16, BASE_HEX, VALS(ieee802154_zigbee_ie_names),
ZBEE_ZIGBEE_IE_ID_MASK, NULL, HFILL }},
{ &hf_ieee802154_zigbee_ie_length,
{ "Length", "zbee_nwk.zigbee_ie.length", FT_UINT16, BASE_DEC, NULL,
ZBEE_ZIGBEE_IE_LENGTH_MASK, NULL, HFILL }},
{ &hf_ieee802154_zigbee_ie_tx_power,
{ "Tx Power (dBm)", "zbee_nwk.zigbee_ie.tx_power", FT_INT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_ieee802154_zigbee_ie_source_addr,
{ "Source Address", "zbee_nwk.zigbee_ie.source_address", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_ieee802154_zigbee_rejoin_epid,
{ "Extended PAN ID", "zbee_nwk.zigbee_rejoin.ext_panid", FT_EUI64, BASE_NONE, NULL, 0x0,
"Extended PAN identifier", HFILL }},
{ &hf_ieee802154_zigbee_rejoin_source_addr,
{ "Source Address", "zbee_nwk.zigbee_rejoin.source_address", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_zbee_nwk,
&ett_zbee_nwk_beacon,
&ett_zbee_nwk_fcf,
&ett_zbee_nwk_fcf_ext,
&ett_zbee_nwk_mcast,
&ett_zbee_nwk_route,
&ett_zbee_nwk_cmd,
&ett_zbee_nwk_cmd_options,
&ett_zbee_nwk_cmd_cinfo,
&ett_zbee_nwk_cmd_link,
&ett_zbee_nwk_cmd_ed_to_rsp_prnt_info,
&ett_zbee_nwk_cmd_link_pwr_struct,
&ett_zbee_nwk_zigbee_ie_fields,
&ett_zbee_nwk_ie_rejoin,
&ett_zbee_nwk_header,
&ett_zbee_nwk_header_ie,
&ett_zbee_nwk_beacon_bitfield,
};
static ei_register_info ei[] = {
{ &ei_zbee_nwk_missing_payload, { "zbee_nwk.missing_payload", PI_MALFORMED, PI_ERROR, "Missing Payload", EXPFILL }},
};
expert_module_t* expert_zbee_nwk;
expert_zbee_nwk = expert_register_protocol(proto_zbee_nwk);
expert_register_field_array(expert_zbee_nwk, ei, array_length(ei));
register_init_routine(proto_init_zbee_nwk);
register_cleanup_routine(proto_cleanup_zbee_nwk);
proto_zbee_nwk = proto_register_protocol("ZigBee Network Layer", "ZigBee", ZBEE_PROTOABBREV_NWK);
proto_zbee_beacon = proto_register_protocol("ZigBee Beacon", "ZigBee Beacon", "zbee_beacon");
proto_zbip_beacon = proto_register_protocol("ZigBee IP Beacon", "ZigBee IP Beacon", "zbip_beacon");
proto_zbee_ie = proto_register_protocol("ZigBee IE", "ZigBee IE", "zbee_ie");
proto_register_field_array(proto_zbee_nwk, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_NWK, dissect_zbee_nwk, proto_zbee_nwk);
register_dissector("zbee_beacon", dissect_zbee_beacon, proto_zbee_beacon);
register_dissector("zbip_beacon", dissect_zbip_beacon, proto_zbip_beacon);
register_dissector("zbee_ie", dissect_zbee_ie, proto_zbee_ie);
zbee_security_register(NULL, proto_zbee_nwk);
}
void proto_reg_handoff_zbee_nwk(void)
{
aps_handle = find_dissector_add_dependency(ZBEE_PROTOABBREV_APS, proto_zbee_nwk);
zbee_gp_handle = find_dissector_add_dependency(ZBEE_PROTOABBREV_NWK_GP, proto_zbee_nwk);
dissector_add_for_decode_as(IEEE802154_PROTOABBREV_WPAN_PANID, find_dissector(ZBEE_PROTOABBREV_NWK));
heur_dissector_add(IEEE802154_PROTOABBREV_WPAN_BEACON, dissect_zbee_beacon_heur, "ZigBee Beacon", "zbee_wlan_beacon", proto_zbee_beacon, HEURISTIC_ENABLE);
heur_dissector_add(IEEE802154_PROTOABBREV_WPAN_BEACON, dissect_zbip_beacon_heur, "ZigBee IP Beacon", "zbip_wlan_beacon", proto_zbip_beacon, HEURISTIC_ENABLE);
heur_dissector_add(IEEE802154_PROTOABBREV_WPAN, dissect_zbee_nwk_heur, "ZigBee Network Layer over IEEE 802.15.4", "zbee_nwk_wlan", proto_zbee_nwk, HEURISTIC_ENABLE);
}
static void free_keyring_key(gpointer key)
{
g_free(key);
}
static void free_keyring_val(gpointer a)
{
GSList **slist = (GSList **)a;
#if GLIB_CHECK_VERSION(2, 28, 0)
g_slist_free_full(*slist, g_free);
#else
g_slist_foreach(*slist, (GFunc)g_free, NULL);
g_slist_free(*slist);
#endif
g_free(slist);
}
static void
proto_init_zbee_nwk(void)
{
zbee_nwk_map.short_table = g_hash_table_new(ieee802154_short_addr_hash, ieee802154_short_addr_equal);
zbee_nwk_map.long_table = g_hash_table_new(ieee802154_long_addr_hash, ieee802154_long_addr_equal);
zbee_table_nwk_keyring = g_hash_table_new_full(g_int_hash, g_int_equal, free_keyring_key, free_keyring_val);
}
static void
proto_cleanup_zbee_nwk(void)
{
g_hash_table_destroy(zbee_nwk_map.short_table);
g_hash_table_destroy(zbee_nwk_map.long_table);
g_hash_table_destroy(zbee_table_nwk_keyring);
}
