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
dissect_zbee_nwk_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
ieee802154_packet *packet = (ieee802154_packet *)pinfo->private_data;
if (packet->src_addr_mode != IEEE802154_FCF_ADDR_SHORT) {
return FALSE;
}
if ( (packet->frame_type == IEEE802154_FCF_DATA) &&
(packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) ) {
dissect_zbee_nwk(tvb, pinfo, tree);
return TRUE;
}
if ( (packet->frame_type == IEEE802154_FCF_BEACON) &&
(tvb_get_guint8(tvb, 0) == ZBEE_NWK_BEACON_PROCOL_ID) ) {
dissect_zbee_beacon(tvb, pinfo, tree);
return TRUE;
}
return FALSE;
}
static void
dissect_zbee_nwk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *payload_tvb = NULL;
proto_item *proto_root = NULL;
proto_item *ti = NULL;
proto_tree *nwk_tree = NULL;
proto_tree *field_tree = NULL;
zbee_nwk_packet packet;
ieee802154_packet *ieee_packet = (ieee802154_packet *)pinfo->private_data;
guint offset = 0;
static gchar src_addr[32], dst_addr[32];
guint16 fcf;
ieee802154_short_addr addr16;
ieee802154_map_rec *map_rec;
ieee802154_hints_t *ieee_hints;
zbee_nwk_hints_t *nwk_hints;
gboolean unicast_src;
memset(&packet, 0, sizeof(packet));
if (!pinfo->fd->flags.visited) {
nwk_hints = se_new0(zbee_nwk_hints_t);
p_add_proto_data(pinfo->fd, proto_zbee_nwk, 0, nwk_hints);
} else {
nwk_hints = (zbee_nwk_hints_t *)p_get_proto_data(pinfo->fd, proto_zbee_nwk, 0);
}
ieee_hints = (ieee802154_hints_t *)p_get_proto_data(pinfo->fd,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_nwk, tvb, offset,
tvb_length(tvb), "ZigBee Network Layer");
nwk_tree = proto_item_add_subtree(proto_root, ett_zbee_nwk);
}
fcf = tvb_get_letohs(tvb, offset);
packet.type = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_FRAME_TYPE);
packet.version = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_VERSION);
packet.discovery = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_DISCOVER_ROUTE);
packet.security = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_SECURITY);
packet.multicast = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_MULTICAST);
packet.route = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_SOURCE_ROUTE);
packet.ext_dst = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_EXT_DEST);
packet.ext_src = zbee_get_bit_field(fcf, ZBEE_NWK_FCF_EXT_SOURCE);
pinfo->zbee_stack_vers = packet.version;
if (tree) {
ti = proto_tree_add_text(nwk_tree, tvb, offset, 2, "Frame Control Field: %s (0x%04x)",
val_to_str_const(packet.type, zbee_nwk_frame_types, "Unknown"), fcf);
field_tree = proto_item_add_subtree(ti, ett_zbee_nwk_fcf);
proto_tree_add_uint(field_tree, hf_zbee_nwk_frame_type, tvb, offset, 1,
fcf & ZBEE_NWK_FCF_FRAME_TYPE);
proto_tree_add_uint(field_tree, hf_zbee_nwk_proto_version, tvb, offset, 1,
fcf & ZBEE_NWK_FCF_VERSION);
proto_tree_add_uint(field_tree, hf_zbee_nwk_discover_route, tvb, offset, 1,
fcf & ZBEE_NWK_FCF_DISCOVER_ROUTE);
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
proto_tree_add_boolean(field_tree, hf_zbee_nwk_multicast, tvb, offset+1,
1, fcf & ZBEE_NWK_FCF_MULTICAST);
}
proto_tree_add_boolean(field_tree, hf_zbee_nwk_security, tvb, offset+1,
1, fcf & ZBEE_NWK_FCF_SECURITY);
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
proto_tree_add_boolean(field_tree, hf_zbee_nwk_source_route, tvb, offset+1,
1, fcf & ZBEE_NWK_FCF_SOURCE_ROUTE);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_ext_dst, tvb, offset+1,
1, fcf & ZBEE_NWK_FCF_EXT_DEST);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_ext_src, tvb, offset+1,
1, fcf & ZBEE_NWK_FCF_EXT_SOURCE);
}
}
offset += 2;
if (tree) {
proto_item_append_text(proto_root, " %s", val_to_str_const(packet.type, zbee_nwk_frame_types, "Unknown Type"));
}
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet.type, zbee_nwk_frame_types, "Reserved Frame Type"));
packet.dst = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(nwk_tree, hf_zbee_nwk_dst, tvb, offset, 2, packet.dst);
}
offset += 2;
if ( (packet.dst == ZBEE_BCAST_ALL)
|| (packet.dst == ZBEE_BCAST_ACTIVE)
|| (packet.dst == ZBEE_BCAST_ROUTERS)){
g_snprintf(dst_addr, 32, "Broadcast");
}
else {
g_snprintf(dst_addr, 32, "0x%04x", packet.dst);
}
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(dst_addr)+1, dst_addr);
SET_ADDRESS(&pinfo->net_dst, AT_STRINGZ, (int)strlen(dst_addr)+1, dst_addr);
if (tree) {
proto_item_append_text(proto_root, ", Dst: %s", dst_addr);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: %s", dst_addr);
packet.src = tvb_get_letohs(tvb, offset);
if (nwk_hints) nwk_hints->src = packet.src;
if (tree) {
proto_tree_add_uint(nwk_tree, hf_zbee_nwk_src, tvb, offset, 2, packet.src);
}
offset += 2;
if ( (packet.src == ZBEE_BCAST_ALL)
|| (packet.src == ZBEE_BCAST_ACTIVE)
|| (packet.src == ZBEE_BCAST_ROUTERS)){
g_snprintf(src_addr, 32, "Unexpected Source Broadcast");
unicast_src = FALSE;
}
else {
g_snprintf(src_addr, 32, "0x%04x", packet.src);
unicast_src = TRUE;
}
SET_ADDRESS(&pinfo->src, AT_STRINGZ, (int)strlen(src_addr)+1, src_addr);
SET_ADDRESS(&pinfo->net_src, AT_STRINGZ, (int)strlen(src_addr)+1, src_addr);
if (tree) {
proto_item_append_text(proto_root, ", Src: %s", src_addr);
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Src: %s", src_addr);
packet.radius = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(nwk_tree, hf_zbee_nwk_radius, tvb, offset, 1, packet.radius);
}
offset += 1;
packet.seqno = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(nwk_tree, hf_zbee_nwk_seqno, tvb, offset, 1, packet.seqno);
}
offset += 1;
if ((pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) && packet.multicast) {
guint8 mcast_control = tvb_get_guint8(tvb, offset);
packet.mcast_mode = zbee_get_bit_field(mcast_control, ZBEE_NWK_MCAST_MODE);
packet.mcast_radius = zbee_get_bit_field(mcast_control, ZBEE_NWK_MCAST_RADIUS);
packet.mcast_max_radius = zbee_get_bit_field(mcast_control, ZBEE_NWK_MCAST_MAX_RADIUS);
if (tree) {
ti = proto_tree_add_text(nwk_tree, tvb, offset, 1, "Multicast Control Field");
field_tree = proto_item_add_subtree(ti, ett_zbee_nwk_mcast);
ti = proto_tree_add_uint(field_tree, hf_zbee_nwk_mcast_mode, tvb, offset, 1,
mcast_control & ZBEE_NWK_MCAST_MODE);
proto_tree_add_uint(field_tree, hf_zbee_nwk_mcast_radius, tvb, offset, 1,
mcast_control & ZBEE_NWK_MCAST_RADIUS);
proto_tree_add_uint(field_tree, hf_zbee_nwk_mcast_max_radius, tvb, offset, 1,
mcast_control & ZBEE_NWK_MCAST_MAX_RADIUS);
}
offset += 1;
}
if ((pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) && packet.ext_dst) {
packet.dst64 = tvb_get_letoh64(tvb, offset);
if (tree) {
proto_tree_add_item(nwk_tree, hf_zbee_nwk_dst64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
}
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
addr16.pan = ieee_packet->src_pan;
if (packet.ext_src) {
packet.src64 = tvb_get_letoh64(tvb, offset);
if (tree) {
proto_tree_add_item(nwk_tree, hf_zbee_nwk_src64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (!pinfo->fd->flags.visited && nwk_hints) {
nwk_hints->src_pan = ieee_packet->src_pan;
if ( unicast_src ) {
nwk_hints->map_rec = ieee802154_addr_update(&zbee_nwk_map,
packet.src, addr16.pan, packet.src64, pinfo->current_proto, pinfo->fd->num);
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
if (tree && nwk_hints && nwk_hints->map_rec ) {
ti = proto_tree_add_eui64(nwk_tree, hf_zbee_nwk_src64, tvb, offset, 0,
nwk_hints->map_rec->addr64);
PROTO_ITEM_SET_GENERATED(ti);
if ( nwk_hints->map_rec->start_fnum ) {
ti = proto_tree_add_uint(nwk_tree, hf_zbee_nwk_src64_origin, tvb, 0, 0,
nwk_hints->map_rec->start_fnum);
}
else {
ti = proto_tree_add_text(nwk_tree, tvb, 0, 0, "Origin: Pre-configured");
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
if ((pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) && packet.route) {
guint8 relay_count;
guint8 relay_index;
guint16 relay_addr;
guint i;
if (tree) {
ti = proto_tree_add_text(nwk_tree, tvb, offset, 1, "Source Route");
field_tree = proto_item_add_subtree(ti, ett_zbee_nwk_route);
}
relay_count = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(field_tree, hf_zbee_nwk_relay_count, tvb, offset, 1, relay_count);
proto_item_append_text(ti, ", Length: %d", relay_count);
}
offset += 1;
if (tree) {
proto_item_set_len(ti, 1 + relay_count*2);
}
relay_index = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(field_tree, hf_zbee_nwk_relay_index, tvb, offset, 1, relay_index);
}
offset += 1;
for (i=0; i<relay_count; i++) {
relay_addr = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_text(field_tree, tvb, offset, 2, "Relay %d: 0x%04x", i+1, relay_addr);
}
offset += 2;
}
}
pinfo->private_data = (void *)&packet;
if (offset >= tvb_length(tvb)) {
expert_add_info_format(pinfo, proto_root, PI_MALFORMED, PI_ERROR, "Missing Payload");
THROW(BoundsError);
}
else if (packet.security) {
payload_tvb = dissect_zbee_secure(tvb, pinfo, nwk_tree, offset);
if (payload_tvb == NULL) {
return;
}
}
else {
payload_tvb = tvb_new_subset_remaining(tvb, offset);
}
if (packet.type == ZBEE_NWK_FCF_CMD) {
dissect_zbee_nwk_cmd(payload_tvb, pinfo, nwk_tree);
}
else if (packet.type == ZBEE_NWK_FCF_DATA) {
call_dissector(aps_handle, payload_tvb, pinfo, tree);
}
else {
call_dissector(data_handle, payload_tvb, pinfo, tree);
}
}
static void dissect_zbee_nwk_cmd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *cmd_tree = NULL;
proto_item *cmd_root = NULL;
zbee_nwk_packet *packet = (zbee_nwk_packet *)pinfo->private_data;
guint offset=0;
guint8 cmd_id = tvb_get_guint8(tvb, offset);
if (tree) {
cmd_root = proto_tree_add_text(tree, tvb, offset, tvb_length(tvb), "Command Frame: %s",
val_to_str_const(cmd_id, zbee_nwk_cmd_names, "Unknown"));
cmd_tree = proto_item_add_subtree(cmd_root, ett_zbee_nwk_cmd);
proto_tree_add_uint(cmd_tree, hf_zbee_nwk_cmd_id, tvb, offset, 1, cmd_id);
}
offset += 1;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(cmd_id, zbee_nwk_cmd_names, "Unknown Command"));
switch(cmd_id){
case ZBEE_NWK_CMD_ROUTE_REQ:
offset = dissect_zbee_nwk_route_req(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZBEE_NWK_CMD_ROUTE_REPLY:
offset = dissect_zbee_nwk_route_rep(tvb, pinfo, cmd_tree, offset);
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
default:
break;
}
if (offset < tvb_length(tvb)) {
guint leftover_len = tvb_length(tvb) - offset;
tvbuff_t *leftover_tvb = tvb_new_subset(tvb, offset, leftover_len, leftover_len);
proto_tree *root = NULL;
if (tree) {
root = proto_tree_get_root(tree);
proto_item_set_len(cmd_root, offset);
}
call_dissector(data_handle, leftover_tvb, pinfo, root);
}
}
static guint
dissect_zbee_nwk_route_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, zbee_nwk_packet * packet, guint offset)
{
proto_tree *field_tree;
proto_item *ti;
guint8 route_options;
guint8 route_id;
guint16 dest_addr;
guint8 path_cost;
route_options = tvb_get_guint8(tvb, offset);
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 1, "Command Options (0x%02x)", route_options);
field_tree = proto_item_add_subtree(ti, ett_zbee_nwk_cmd_options);
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_route_opt_multicast, tvb, offset,
1, route_options & ZBEE_NWK_CMD_ROUTE_OPTION_MCAST);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_route_opt_dest_ext, tvb, offset,
1, route_options & ZBEE_NWK_CMD_ROUTE_OPTION_DEST_EXT);
proto_tree_add_uint(field_tree, hf_zbee_nwk_cmd_route_opt_many_to_one, tvb, offset,
1, route_options & ZBEE_NWK_CMD_ROUTE_OPTION_MANY_MASK);
}
else {
proto_tree_add_boolean(tree, hf_zbee_nwk_cmd_route_opt_repair, tvb, offset, 1,
route_options & ZBEE_NWK_CMD_ROUTE_OPTION_REPAIR);
}
}
offset += 1;
route_id = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_id, tvb, offset, 1, route_id);
}
offset += 1;
dest_addr = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_dest, tvb, offset, 2, dest_addr);
}
offset += 2;
path_cost = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_cost, tvb, offset, 1, path_cost);
}
offset += 1;
if (route_options & ZBEE_NWK_CMD_ROUTE_OPTION_DEST_EXT) {
if (tree) {
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_dest_ext, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: 0x%04x, Src: 0x%04x", dest_addr, packet->src);
return offset;
}
static guint
dissect_zbee_nwk_route_rep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
proto_tree *field_tree;
proto_item *ti;
guint8 route_options;
guint8 route_id;
guint16 orig_addr;
guint16 resp_addr;
guint8 path_cost;
route_options = tvb_get_guint8(tvb, offset);
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 1, "Command Options (0x%02x)", route_options);
field_tree = proto_item_add_subtree(ti, ett_zbee_nwk_cmd_options);
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_route_opt_multicast, tvb, offset, 1, route_options & ZBEE_NWK_CMD_ROUTE_OPTION_MCAST);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_route_opt_resp_ext, tvb, offset, 1, route_options & ZBEE_NWK_CMD_ROUTE_OPTION_RESP_EXT);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_route_opt_orig_ext, tvb, offset, 1, route_options & ZBEE_NWK_CMD_ROUTE_OPTION_ORIG_EXT);
}
else {
proto_tree_add_boolean(tree, hf_zbee_nwk_cmd_route_opt_repair, tvb, offset, 1, route_options & ZBEE_NWK_CMD_ROUTE_OPTION_REPAIR);
}
}
offset += 1;
route_id = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_id, tvb, offset, 1, route_id);
}
offset += 1;
orig_addr = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_orig, tvb, offset, 2, orig_addr);
}
offset += 2;
resp_addr = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_resp, tvb, offset, 2, resp_addr);
}
offset += 2;
path_cost = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_cost, tvb, offset, 1, path_cost);
}
offset += 1;
if (route_options & ZBEE_NWK_CMD_ROUTE_OPTION_ORIG_EXT) {
if (tree) {
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_orig_ext, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
}
if (route_options & ZBEE_NWK_CMD_ROUTE_OPTION_RESP_EXT) {
if (tree) {
proto_tree_add_item(tree, hf_zbee_nwk_cmd_route_resp_ext, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: 0x%04x, Src: 0x%04x", resp_addr, orig_addr);
return offset;
}
static guint
dissect_zbee_nwk_status(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 status_code;
guint16 addr;
status_code = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_nwk_status, tvb, offset, 1, status_code);
}
offset += 1;
addr = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_route_dest, tvb, offset, 2, addr);
}
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", 0x%04x: %s", addr, val_to_str_const(status_code, zbee_nwk_status_codes, "Unknown Status Code"));
return offset;
}
static guint
dissect_zbee_nwk_leave(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
guint8 leave_options;
leave_options = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_boolean(tree, hf_zbee_nwk_cmd_leave_rejoin, tvb, offset, 1,
leave_options & ZBEE_NWK_CMD_LEAVE_OPTION_REJOIN);
proto_tree_add_boolean(tree, hf_zbee_nwk_cmd_leave_request, tvb, offset, 1,
leave_options & ZBEE_NWK_CMD_LEAVE_OPTION_REQUEST);
proto_tree_add_boolean(tree, hf_zbee_nwk_cmd_leave_children, tvb, offset, 1,
leave_options & ZBEE_NWK_CMD_LEAVE_OPTION_CHILDREN);
}
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
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_relay_count, tvb, offset, 1, relay_count);
}
offset += 1;
for (i=0; i<relay_count; i++) {
relay_addr = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2, "Relay Device %d: 0x%04x", i+1, relay_addr);
}
offset += 2;
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: 0x%04x", packet->dst);
return offset;
}
static guint
dissect_zbee_nwk_rejoin_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, zbee_nwk_packet * packet, guint offset)
{
proto_tree *field_tree;
proto_item *ti;
guint8 capabilities;
capabilities = tvb_get_guint8(tvb, offset);
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 1, "Capability Information");
field_tree = proto_item_add_subtree(ti, ett_zbee_nwk_cmd_cinfo);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_cinfo_alt_coord, tvb, offset, 1,
capabilities & ZBEE_CINFO_ALT_COORD);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_cinfo_type, tvb, offset, 1,
capabilities & ZBEE_CINFO_FFD);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_cinfo_power, tvb, offset, 1,
capabilities & ZBEE_CINFO_POWER);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_cinfo_idle_rx, tvb, offset, 1,
capabilities & ZBEE_CINFO_IDLE_RX);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_cinfo_security, tvb, offset, 1,
capabilities & ZBEE_CINFO_SECURITY);
proto_tree_add_boolean(field_tree, hf_zbee_nwk_cmd_cinfo_alloc, tvb, offset, 1,
capabilities & ZBEE_CINFO_ALLOC);
}
offset += 1;
col_append_fstr(pinfo->cinfo, COL_INFO, ", Device: 0x%04x", packet->src);
return offset;
}
static guint
dissect_zbee_nwk_rejoin_resp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, zbee_nwk_packet * packet, guint offset)
{
guint16 addr;
guint8 status;
addr = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_addr, tvb, offset, 2, addr);
}
offset += 2;
status = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_rejoin_status, tvb, offset, 1, status);
}
offset += 1;
if (status == IEEE802154_CMD_ASRSP_AS_SUCCESS) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Address: 0x%04x", packet->src);
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
guint16 addr;
int i, link_count;
options = tvb_get_guint8(tvb, offset);
link_count = options & ZBEE_NWK_CMD_LINK_OPTION_COUNT_MASK;
if (tree) {
proto_tree_add_boolean(tree, hf_zbee_nwk_cmd_link_last, tvb, offset, 1,
options & ZBEE_NWK_CMD_LINK_OPTION_LAST_FRAME);
proto_tree_add_boolean(tree, hf_zbee_nwk_cmd_link_first, tvb, offset, 1,
options & ZBEE_NWK_CMD_LINK_OPTION_FIRST_FRAME);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_link_count, tvb, offset, 1, link_count);
}
offset += 1;
for (i=0; i<link_count; i++) {
addr = tvb_get_letohs(tvb, offset);
options = tvb_get_guint8(tvb, offset+2);
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2+1,
"0x%04x, Incoming Cost: %d Outgoing Cost: %d", addr,
options & ZBEE_NWK_CMD_LINK_INCOMMING_COST_MASK,
(options & ZBEE_NWK_CMD_LINK_OUTGOING_COST_MASK)>>4);
}
offset += (2+1);
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
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_report_type, tvb, offset, 1, report_type);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_report_count, tvb, offset, 1, report_count);
}
offset += 1;
if (tree) {
proto_tree_add_item(tree, hf_zbee_nwk_cmd_epid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
if (report_type == ZBEE_NWK_CMD_NWK_REPORT_ID_PAN_CONFLICT) {
guint16 panId;
for (i=0; i<report_count; i++) {
panId = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2, "PANID: 0x%04x", panId);
}
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
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_update_type, tvb, offset, 1, update_type);
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_update_count, tvb, offset, 1, update_count);
}
offset += 1;
if (tree) {
proto_tree_add_item(tree, hf_zbee_nwk_cmd_epid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
update_id = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_nwk_cmd_update_id, tvb, offset, 1, update_id);
}
offset += 1;
if (update_type == ZBEE_NWK_CMD_NWK_UPDATE_ID_PAN_UPDATE) {
guint16 panId;
for (i=0; i<update_count; i++) {
panId = tvb_get_letohs(tvb, offset);
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2, "PANID: 0x%04x", panId);
}
offset += 2;
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", val_to_str_const(update_type, zbee_nwk_update_types, "Unknown Update Type"));
return offset;
}
static void dissect_zbee_beacon(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
ieee802154_packet *packet = (ieee802154_packet *)pinfo->private_data;
proto_item *beacon_root = NULL;
proto_tree *beacon_tree = NULL;
guint offset = 0;
guint8 temp;
guint8 version;
guint64 epid;
guint32 tx_offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee");
if (tree) {
beacon_root = proto_tree_add_protocol_format(tree, proto_zbee_nwk, tvb, 0, tvb_length(tvb), "ZigBee Beacon");
beacon_tree = proto_item_add_subtree(beacon_root, ett_zbee_beacon);
}
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "Beacon, Src: 0x%04x", packet->src16);
temp = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(beacon_tree, hf_zbee_beacon_protocol, tvb, offset, 1, temp);
}
offset += 1;
temp = tvb_get_guint8(tvb, offset);
pinfo->zbee_stack_vers = version = zbee_get_bit_field(temp, ZBEE_NWK_BEACON_PROTOCOL_VERSION);
if (tree) {
proto_tree_add_uint(beacon_tree, hf_zbee_beacon_stack_profile, tvb, offset, 1,
zbee_get_bit_field(temp, ZBEE_NWK_BEACON_STACK_PROFILE));
proto_tree_add_uint(beacon_tree, hf_zbee_beacon_version, tvb, offset, 1, version);
}
offset += 1;
temp = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_boolean(beacon_tree, hf_zbee_beacon_router_capacity, tvb, offset, 1,
zbee_get_bit_field(temp, ZBEE_NWK_BEACON_ROUTER_CAPACITY));
proto_tree_add_uint(beacon_tree, hf_zbee_beacon_depth, tvb, offset, 1,
zbee_get_bit_field(temp, ZBEE_NWK_BEACON_NETWORK_DEPTH));
proto_tree_add_boolean(beacon_tree, hf_zbee_beacon_end_device_capacity, tvb, offset, 1,
zbee_get_bit_field(temp, ZBEE_NWK_BEACON_END_DEVICE_CAPACITY));
}
offset += 1;
if (version >= ZBEE_VERSION_2007) {
epid = tvb_get_letoh64(tvb, offset);
if (tree) {
proto_tree_add_item(beacon_tree, hf_zbee_beacon_epid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
offset += 8;
col_append_fstr(pinfo->cinfo, COL_INFO, ", EPID: %s", get_eui64_name(epid));
if (tvb_bytes_exist(tvb, offset, 3)) {
tx_offset = tvb_get_letoh24(tvb, offset);
proto_tree_add_uint(beacon_tree, hf_zbee_beacon_tx_offset, tvb, offset, 3, tx_offset);
offset += 3;
if(tvb_length_remaining(tvb, offset)) {
temp = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(beacon_tree, hf_zbee_beacon_update_id, tvb, offset, 1, temp);
offset += 1;
}
}
}
else if (tvb_bytes_exist(tvb, offset, 3)) {
tx_offset = tvb_get_letoh24(tvb, offset);
if (tree) {
proto_tree_add_uint(beacon_tree, hf_zbee_beacon_tx_offset, tvb, offset, 3, tx_offset);
}
offset += 3;
col_append_fstr(pinfo->cinfo, COL_INFO, ", PAN: 0x%04x", packet->src_pan);
}
if (offset < tvb_length(tvb)) {
guint leftover_len = tvb_length(tvb) - offset;
tvbuff_t *leftover_tvb = tvb_new_subset(tvb, offset, leftover_len, leftover_len);
proto_tree *root = NULL;
if (tree) {
root = proto_tree_get_root(tree);
proto_item_set_len(beacon_root, offset);
}
call_dissector(data_handle, leftover_tvb, pinfo, root);
}
}
void proto_register_zbee_nwk(void)
{
static hf_register_info hf[] = {
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
{ &hf_zbee_nwk_cmd_epid,
{ "Extended PAN ID", "zbee_nwk.cmd.epid", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_beacon_protocol,
{ "Protocol ID", "zbee_beacon.protocol", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_beacon_stack_profile,
{ "Stack Profile", "zbee_beacon.profile", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_stack_profiles), 0x0, NULL, HFILL }},
{ &hf_zbee_beacon_version,
{ "Protocol Version", "zbee_beacon.version", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_beacon_router_capacity,
{ "Router Capacity", "zbee_beacon.router", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Whether the device can accept join requests from routing capable devices.", HFILL }},
{ &hf_zbee_beacon_depth,
{ "Device Depth", "zbee_beacon.depth", FT_UINT8, BASE_DEC, NULL, 0x0,
"The tree depth of the device, 0 indicates the network coordinator.", HFILL }},
{ &hf_zbee_beacon_end_device_capacity,
{ "End Device Capacity", "zbee_beacon.end_dev", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Whether the device can accept join requests from ZigBee end devices.", HFILL }},
{ &hf_zbee_beacon_epid,
{ "Extended PAN ID", "zbee_beacon.ext_panid", FT_EUI64, BASE_NONE, NULL, 0x0,
"Extended PAN identifier.", HFILL }},
{ &hf_zbee_beacon_tx_offset,
{ "Tx Offset", "zbee_beacon.tx_offset", FT_UINT32, BASE_DEC, NULL, 0x0,
"The time difference between a device and its parent's beacon.", HFILL }},
{ &hf_zbee_beacon_update_id,
{ "Update ID", "zbee_beacon.update_id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_zbee_nwk,
&ett_zbee_beacon,
&ett_zbee_nwk_fcf,
&ett_zbee_nwk_mcast,
&ett_zbee_nwk_route,
&ett_zbee_nwk_cmd,
&ett_zbee_nwk_cmd_options,
&ett_zbee_nwk_cmd_cinfo
};
register_init_routine(proto_init_zbee_nwk);
proto_zbee_nwk = proto_register_protocol("ZigBee Network Layer", "ZigBee NWK", ZBEE_PROTOABBREV_NWK);
proto_register_field_array(proto_zbee_nwk, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_NWK, dissect_zbee_nwk, proto_zbee_nwk);
register_dissector("zbee_beacon", dissect_zbee_beacon, proto_zbee_nwk);
zbee_security_register(NULL, proto_zbee_nwk);
}
void proto_reg_handoff_zbee_nwk(void)
{
data_handle = find_dissector("data");
aps_handle = find_dissector("zbee_aps");
heur_dissector_add(IEEE802154_PROTOABBREV_WPAN, dissect_zbee_nwk_heur, proto_zbee_nwk);
zbee_security_handoff();
}
static void free_keyring_val(gpointer a)
{
GSList **slist = (GSList **)a;
g_slist_free(*slist);
return;
}
static void
proto_init_zbee_nwk(void)
{
if (zbee_nwk_map.short_table) g_hash_table_destroy(zbee_nwk_map.short_table);
if (zbee_nwk_map.long_table) g_hash_table_destroy(zbee_nwk_map.long_table);
if (zbee_table_nwk_keyring) g_hash_table_destroy(zbee_table_nwk_keyring);
zbee_nwk_map.short_table = g_hash_table_new(ieee802154_short_addr_hash, ieee802154_short_addr_equal);
zbee_nwk_map.long_table = g_hash_table_new(ieee802154_long_addr_hash, ieee802154_long_addr_equal);
zbee_table_nwk_keyring = g_hash_table_new_full(g_int_hash, g_int_equal, NULL, free_keyring_val);
}
