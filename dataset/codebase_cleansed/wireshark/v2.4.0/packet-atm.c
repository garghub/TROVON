static void
dissect_le_client(tvbuff_t *tvb, proto_tree *tree)
{
proto_item *ti;
proto_tree *lane_tree;
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_atm_lane, tvb, 0, 2, "ATM LANE");
lane_tree = proto_item_add_subtree(ti, ett_atm_lane);
proto_tree_add_item(lane_tree, hf_atm_le_client_client, tvb, 0, 2, ENC_BIG_ENDIAN );
}
}
static void
dissect_lan_destination(tvbuff_t *tvb, int offset, const char *type, proto_tree *tree)
{
proto_item *td;
proto_tree *dest_tree;
guint16 tag;
proto_tree *rd_tree;
dest_tree = proto_tree_add_subtree_format(tree, tvb, offset, 8,
ett_atm_lane_lc_lan_dest, NULL, "%s LAN destination", type);
tag = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(dest_tree, hf_atm_lan_destination_tag, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
switch (tag) {
case TAG_MAC_ADDRESS:
proto_tree_add_item(dest_tree, hf_atm_lan_destination_mac, tvb, offset, 6, ENC_NA);
break;
case TAG_ROUTE_DESCRIPTOR:
offset += 4;
td = proto_tree_add_item(dest_tree, hf_atm_lan_destination_route_desc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
rd_tree = proto_item_add_subtree(td, ett_atm_lane_lc_lan_dest_rd);
proto_tree_add_item(rd_tree, hf_atm_lan_destination_lan_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(rd_tree, hf_atm_lan_destination_bridge_num, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
}
}
static void
dissect_le_control_tlvs(tvbuff_t *tvb, int offset, guint num_tlvs,
proto_tree *tree)
{
guint32 tlv_type;
guint8 tlv_length;
proto_tree *tlv_tree;
while (num_tlvs != 0) {
tlv_type = tvb_get_ntohl(tvb, offset);
tlv_length = tvb_get_guint8(tvb, offset+4);
tlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, 5+tlv_length, ett_atm_lane_lc_tlv, NULL,
"TLV type: %s", val_to_str(tlv_type, le_tlv_type_vals, "Unknown (0x%08x)"));
proto_tree_add_item(tlv_tree, hf_atm_le_control_tlv_type, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_atm_le_control_tlv_length, tvb, offset+4, 1, ENC_BIG_ENDIAN);
offset += 5+tlv_length;
num_tlvs--;
}
}
static void
dissect_le_configure_join_frame(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 num_tlvs;
guint8 name_size;
dissect_lan_destination(tvb, offset, "Source", tree);
offset += 8;
dissect_lan_destination(tvb, offset, "Target", tree);
offset += 8;
proto_tree_add_item(tree, hf_atm_source_atm, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_atm_le_configure_join_frame_lan_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_atm_le_configure_join_frame_max_frame_size, tvb, offset, 1, ENC_NA);
offset += 1;
num_tlvs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_atm_le_configure_join_frame_num_tlvs, tvb, offset, 1, ENC_NA);
offset += 1;
name_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_atm_le_configure_join_frame_elan_name_size, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_atm_target_atm, tvb, offset, 20, ENC_NA);
offset += 20;
if (name_size > 32)
name_size = 32;
if (name_size != 0) {
proto_tree_add_item(tree, hf_atm_le_configure_join_frame_elan_name, tvb, offset, name_size, ENC_NA);
}
offset += 32;
dissect_le_control_tlvs(tvb, offset, num_tlvs, tree);
}
static void
dissect_le_registration_frame(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 num_tlvs;
dissect_lan_destination(tvb, offset, "Source", tree);
offset += 8;
dissect_lan_destination(tvb, offset, "Target", tree);
offset += 8;
proto_tree_add_item(tree, hf_atm_source_atm, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
num_tlvs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_atm_le_registration_frame_num_tlvs, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 53, ENC_NA);
offset += 53;
dissect_le_control_tlvs(tvb, offset, num_tlvs, tree);
}
static void
dissect_le_arp_frame(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 num_tlvs;
dissect_lan_destination(tvb, offset, "Source", tree);
offset += 8;
dissect_lan_destination(tvb, offset, "Target", tree);
offset += 8;
proto_tree_add_item(tree, hf_atm_source_atm, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
num_tlvs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_atm_le_arp_frame_num_tlvs, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_atm_target_atm, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 32, ENC_NA);
offset += 32;
dissect_le_control_tlvs(tvb, offset, num_tlvs, tree);
}
static void
dissect_le_verify_frame(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 num_tlvs;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 38, ENC_NA);
offset += 38;
num_tlvs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_atm_le_verify_frame_num_tlvs, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_atm_target_atm, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 32, ENC_NA);
offset += 32;
dissect_le_control_tlvs(tvb, offset, num_tlvs, tree);
}
static int
dissect_le_flush_frame(tvbuff_t *tvb, int offset, proto_tree *tree)
{
dissect_lan_destination(tvb, offset, "Source", tree);
offset += 8;
dissect_lan_destination(tvb, offset, "Target", tree);
offset += 8;
proto_tree_add_item(tree, hf_atm_source_atm, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_atm_target_atm, tvb, offset, 20, ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_atm_reserved, tvb, offset, 32, ENC_NA);
offset += 32;
return offset;
}
static void
dissect_le_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lane_tree = NULL;
int offset = 0;
proto_item *tf;
proto_tree *flags_tree;
guint16 opcode;
col_set_str(pinfo->cinfo, COL_INFO, "LE Control");
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_atm_lane, tvb, offset, 108, "ATM LANE");
lane_tree = proto_item_add_subtree(ti, ett_atm_lane);
proto_tree_add_item(lane_tree, hf_atm_le_control_marker, tvb, offset, 2, ENC_BIG_ENDIAN );
}
offset += 2;
if (tree) {
proto_tree_add_item(lane_tree, hf_atm_le_control_protocol, tvb, offset, 1, ENC_BIG_ENDIAN );
}
offset += 1;
if (tree) {
proto_tree_add_item(lane_tree, hf_atm_le_control_version, tvb, offset, 1, ENC_BIG_ENDIAN );
}
offset += 1;
opcode = tvb_get_ntohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str(opcode, le_control_opcode_vals,
"Unknown opcode (0x%04X)"));
if (tree) {
proto_tree_add_item(lane_tree, hf_atm_le_control_opcode, tvb, offset, 2, ENC_BIG_ENDIAN );
}
offset += 2;
if (opcode == READY_QUERY || opcode == READY_IND) {
return;
}
if (tree) {
if (opcode & 0x0100) {
proto_tree_add_item(lane_tree, hf_atm_le_control_status, tvb, offset, 2, ENC_BIG_ENDIAN );
}
offset += 2;
proto_tree_add_item(lane_tree, hf_atm_le_control_transaction_id, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item(lane_tree, hf_atm_le_control_requester_lecid, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
tf = proto_tree_add_item(lane_tree, hf_atm_le_control_flags, tvb, offset, 2, ENC_BIG_ENDIAN );
flags_tree = proto_item_add_subtree(tf, ett_atm_lane_lc_flags);
switch (opcode) {
case LE_CONFIGURE_REQUEST:
case LE_CONFIGURE_RESPONSE:
proto_tree_add_item(flags_tree, hf_atm_le_control_flag_v2_capable, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dissect_le_configure_join_frame(tvb, offset, lane_tree);
break;
case LE_JOIN_REQUEST:
case LE_JOIN_RESPONSE:
proto_tree_add_item(flags_tree, hf_atm_le_control_flag_v2_capable, tvb, offset, 2, ENC_BIG_ENDIAN);
if (opcode == LE_JOIN_REQUEST) {
proto_tree_add_item(flags_tree, hf_atm_le_control_flag_selective_multicast, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(flags_tree, hf_atm_le_control_flag_v2_required, tvb, offset, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(flags_tree, hf_atm_le_control_flag_proxy, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_atm_le_control_flag_exclude_explorer_frames, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dissect_le_configure_join_frame(tvb, offset, lane_tree);
break;
case LE_REGISTER_REQUEST:
case LE_REGISTER_RESPONSE:
case LE_UNREGISTER_REQUEST:
case LE_UNREGISTER_RESPONSE:
offset += 2;
dissect_le_registration_frame(tvb, offset, lane_tree);
break;
case LE_ARP_REQUEST:
case LE_ARP_RESPONSE:
case LE_NARP_REQUEST:
if (opcode != LE_NARP_REQUEST) {
proto_tree_add_item(flags_tree, hf_atm_le_control_flag_address, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
dissect_le_arp_frame(tvb, offset, lane_tree);
break;
case LE_TOPOLOGY_REQUEST:
proto_tree_add_item(flags_tree, hf_atm_le_control_topology_change, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(flags_tree, hf_atm_reserved, tvb, offset, 92, ENC_NA);
break;
case LE_VERIFY_REQUEST:
case LE_VERIFY_RESPONSE:
offset += 2;
dissect_le_verify_frame(tvb, offset, lane_tree);
break;
case LE_FLUSH_REQUEST:
case LE_FLUSH_RESPONSE:
offset += 2;
dissect_le_flush_frame(tvb, offset, lane_tree);
break;
}
}
}
static gboolean
capture_lane(const guchar *pd, int offset _U_,
int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header)
{
return try_capture_dissector("atm_lane", pseudo_header->atm.subtype, pd, 2, len, cpinfo, pseudo_header);
}
static int
dissect_lane(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct atm_phdr *atm_info = (struct atm_phdr *)data;
tvbuff_t *next_tvb;
tvbuff_t *next_tvb_le_client;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATM LANE");
switch (atm_info->subtype) {
case TRAF_ST_LANE_LE_CTRL:
dissect_le_control(tvb, pinfo, tree);
break;
case TRAF_ST_LANE_802_3:
case TRAF_ST_LANE_802_3_MC:
col_set_str(pinfo->cinfo, COL_INFO, "LE Client - Ethernet/802.3");
dissect_le_client(tvb, tree);
next_tvb_le_client = tvb_new_subset_remaining(tvb, 2);
call_dissector(eth_withoutfcs_handle, next_tvb_le_client, pinfo, tree);
break;
case TRAF_ST_LANE_802_5:
case TRAF_ST_LANE_802_5_MC:
col_set_str(pinfo->cinfo, COL_INFO, "LE Client - 802.5");
dissect_le_client(tvb, tree);
next_tvb_le_client = tvb_new_subset_remaining(tvb, 2);
call_dissector(tr_handle, next_tvb_le_client, pinfo, tree);
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown LANE traffic type");
next_tvb = tvb_new_subset_remaining(tvb, 0);
call_data_dissector(next_tvb, pinfo, tree);
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_ilmi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
return dissect_snmp_pdu(tvb, 0, pinfo, tree, proto_ilmi, ett_ilmi, FALSE);
}
static gboolean
capture_atm(const guchar *pd, int offset,
int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header)
{
if (pseudo_header->atm.aal == AAL_5) {
return try_capture_dissector("atm.aal5.type", pseudo_header->atm.type, pd, offset, len, cpinfo, pseudo_header);
}
return FALSE;
}
static void
dissect_reassembled_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_item *atm_ti, proto_tree *atm_tree, gboolean truncated,
struct atm_phdr *atm_info, gboolean pseudowire_mode)
{
guint length, reported_length;
guint16 aal5_length;
int pad_length;
tvbuff_t *next_tvb;
guint32 crc;
guint32 calc_crc;
gboolean decoded;
if (atm_info->aal == AAL_5) {
proto_tree_add_uint(atm_tree, hf_atm_traffic_type, tvb, 0, 0, atm_info->type);
switch (atm_info->type) {
case TRAF_VCMX:
proto_tree_add_uint(atm_tree, hf_atm_traffic_vcmx, tvb, 0, 0, atm_info->subtype);
break;
case TRAF_LANE:
proto_tree_add_uint(atm_tree, hf_atm_traffic_lane, tvb, 0, 0, atm_info->subtype);
break;
case TRAF_IPSILON:
proto_tree_add_uint(atm_tree, hf_atm_traffic_ipsilon, tvb, 0, 0, atm_info->subtype);
break;
}
}
if (!pseudowire_mode) {
proto_tree_add_uint(atm_tree, hf_atm_vpi, tvb, 0, 0, atm_info->vpi);
proto_tree_add_uint(atm_tree, hf_atm_vci, tvb, 0, 0, atm_info->vci);
col_append_fstr(pinfo->cinfo, COL_INFO, " VPI=%u, VCI=%u",
atm_info->vpi, atm_info->vci);
}
next_tvb = tvb;
if (truncated || atm_info->flags & ATM_REASSEMBLY_ERROR) {
if (atm_info->cells != 0) {
if (tree) {
proto_tree_add_uint(atm_tree, hf_atm_cells, tvb, 0, 0, atm_info->cells);
proto_tree_add_uint(atm_tree, hf_atm_aal5_uu, tvb, 0, 0, atm_info->aal5t_u2u >> 8);
proto_tree_add_uint(atm_tree, hf_atm_aal5_cpi, tvb, 0, 0, atm_info->aal5t_u2u & 0xFF);
proto_tree_add_uint(atm_tree, hf_atm_aal5_len, tvb, 0, 0, atm_info->aal5t_len);
proto_tree_add_uint(atm_tree, hf_atm_aal5_crc, tvb, 0, 0, atm_info->aal5t_chksum);
}
}
} else {
length = tvb_captured_length(tvb);
reported_length = tvb_reported_length(tvb);
if ((reported_length % 48) == 0) {
proto_tree_add_uint(atm_tree, hf_atm_cells, tvb, 0, 0, reported_length/48);
}
if ((atm_info->aal == AAL_5 || atm_info->aal == AAL_SIGNALLING) &&
length >= reported_length) {
aal5_length = tvb_get_ntohs(tvb, length - 6);
if (aal5_length > 0 && aal5_length <= length - 8) {
pad_length = length - aal5_length - 8;
if (pad_length <= 47) {
if (tree) {
proto_item *ti;
if (pad_length > 0) {
proto_tree_add_item(atm_tree, hf_atm_padding, tvb, aal5_length, pad_length, ENC_NA);
}
proto_tree_add_item(atm_tree, hf_atm_aal5_uu, tvb, length - 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(atm_tree, hf_atm_aal5_cpi, tvb, length - 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(atm_tree, hf_atm_aal5_len, tvb, length - 6, 2, ENC_BIG_ENDIAN);
crc = tvb_get_ntohl(tvb, length - 4);
calc_crc = crc32_mpeg2_tvb(tvb, length);
ti = proto_tree_add_uint(atm_tree, hf_atm_aal5_crc, tvb, length - 4, 4, crc);
proto_item_append_text(ti, (calc_crc == 0xC704DD7B) ? " (correct)" : " (incorrect)");
}
next_tvb = tvb_new_subset_length(tvb, 0, aal5_length);
}
}
}
}
decoded = FALSE;
switch (atm_info->aal) {
case AAL_SIGNALLING:
if (!(atm_info->flags & ATM_REASSEMBLY_ERROR)) {
call_dissector(sscop_handle, next_tvb, pinfo, tree);
decoded = TRUE;
}
break;
case AAL_5:
if (!(atm_info->flags & ATM_REASSEMBLY_ERROR)) {
if (dissector_try_uint_new(atm_type_aal5_table, atm_info->type, next_tvb, pinfo, tree, TRUE, atm_info))
{
decoded = TRUE;
}
else
{
if (tvb_reported_length(next_tvb) > 7)
{
guint8 octet[8];
tvb_memcpy(next_tvb, octet, 0, sizeof(octet));
if (octet[0] == 0xaa
&& octet[1] == 0xaa
&& octet[2] == 0x03)
{
call_dissector(llc_handle, next_tvb, pinfo, tree);
decoded = TRUE;
}
else if ((pntoh16(octet) & 0xff) == PPP_IP)
{
call_dissector(ppp_handle, next_tvb, pinfo, tree);
decoded = TRUE;
}
else if (pntoh16(octet) == 0x00)
{
proto_tree_add_item(tree, hf_atm_padding, tvb, 0, 2, ENC_NA);
next_tvb = tvb_new_subset_remaining(tvb, 2);
call_dissector(eth_maybefcs_handle, next_tvb, pinfo, tree);
decoded = TRUE;
}
else if (octet[2] == 0x03 &&
((octet[3] == 0xcc ||
octet[3] == 0x8e) ||
(octet[3] == 0x00 &&
octet[4] == 0x80)))
{
call_dissector(fr_handle, next_tvb, pinfo, tree);
decoded = TRUE;
}
else if (octet[4] == 0x03 &&
((octet[5] == 0xcc ||
octet[5] == 0x8e) ||
(octet[5] == 0x00 &&
octet[6] == 0x80)))
{
call_dissector(fr_handle, next_tvb, pinfo, tree);
decoded = TRUE;
}
else if (((octet[0] & 0xf0)== 0x40) ||
((octet[0] & 0xf0) == 0x60))
{
call_dissector(ip_handle, next_tvb, pinfo, tree);
decoded = TRUE;
}
}
}
break;
}
break;
case AAL_2:
proto_tree_add_uint(atm_tree, hf_atm_cid, tvb, 0, 0,
atm_info->aal2_cid);
proto_item_append_text(atm_ti, " (vpi=%u vci=%u cid=%u)",
atm_info->vpi,
atm_info->vci,
atm_info->aal2_cid);
if (!(atm_info->flags & ATM_REASSEMBLY_ERROR)) {
if (atm_info->flags & ATM_AAL2_NOPHDR) {
next_tvb = tvb;
} else {
next_tvb = tvb_new_subset_remaining(tvb, 4);
}
if (dissector_try_uint(atm_type_aal2_table, atm_info->type, next_tvb, pinfo, tree))
{
decoded = TRUE;
}
}
break;
default:
break;
}
if (!decoded) {
call_data_dissector(next_tvb, pinfo, tree);
}
}
static int
get_header_err(const guint8 *cell_header)
{
register guint8 syndrome;
register int i, err_posn;
syndrome = 0;
for (i = 0; i < 4; i++)
syndrome = syndrome_table[syndrome ^ cell_header[i]];
syndrome ^= cell_header[4] ^ COSET_LEADER;
err_posn = err_posn_table [syndrome];
if (err_posn < 0)
return NO_ERROR_DETECTED;
else if (err_posn < 40)
return err_posn;
else
return UNCORRECTIBLE_ERROR;
}
static void
dissect_atm_cell_payload(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, guint aal, gboolean fill_columns)
{
proto_tree *aal_tree;
proto_item *ti;
guint8 octet;
gint length;
guint16 aal3_4_hdr, crc10;
tvbuff_t *next_tvb;
switch (aal) {
case AAL_1:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AAL1");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_aal1, tvb, offset, -1, ENC_NA);
aal_tree = proto_item_add_subtree(ti, ett_aal1);
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(aal_tree, hf_atm_aa1_csi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aal_tree, hf_atm_aa1_seq_count, tvb, offset, 1, ENC_BIG_ENDIAN);
col_add_fstr(pinfo->cinfo, COL_INFO, "Sequence count = %u",
(octet >> 4) & 0x7);
proto_tree_add_item(aal_tree, hf_atm_aa1_crc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aal_tree, hf_atm_aa1_parity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(aal_tree, hf_atm_aa1_payload, tvb, offset, 47, ENC_NA);
break;
case AAL_3_4:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "AAL3/4");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_aal3_4, tvb, offset, -1, ENC_NA);
aal_tree = proto_item_add_subtree(ti, ett_aal3_4);
aal3_4_hdr = tvb_get_ntohs(tvb, offset);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, sequence number = %u",
val_to_str(aal3_4_hdr >> 14, st_vals, "Unknown (%u)"),
(aal3_4_hdr >> 10) & 0xF);
proto_tree_add_item(aal_tree, hf_atm_aal3_4_seg_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aal_tree, hf_atm_aal3_4_seq_num, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(aal_tree, hf_atm_aal3_4_multiplex_id, tvb, offset, 2, ENC_BIG_ENDIAN);
length = tvb_reported_length_remaining(tvb, offset);
crc10 = update_crc10_by_bytes_tvb(0, tvb, offset, length);
offset += 2;
proto_tree_add_item(aal_tree, hf_atm_aal3_4_information, tvb, offset, 44, ENC_NA);
offset += 44;
proto_tree_add_item(aal_tree, hf_atm_aal3_4_length_indicator, tvb, offset, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(aal_tree, hf_atm_aal3_4_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)", (crc10 == 0) ? " (correct)" : " (incorrect)");
break;
case AAL_OAMCELL:
if (fill_columns)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OAM AAL");
col_clear(pinfo->cinfo, COL_INFO);
}
ti = proto_tree_add_item(tree, proto_oamaal, tvb, offset, -1, ENC_NA);
aal_tree = proto_item_add_subtree(ti, ett_oamaal);
octet = tvb_get_guint8(tvb, offset);
if (fill_columns)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(octet >> 4, oam_type_vals, "Unknown (%u)"));
}
proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_type, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (octet >> 4) {
case OAM_TYPE_FM:
proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_type_fm, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case OAM_TYPE_PM:
proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_type_pm, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case OAM_TYPE_AD:
proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_type_ad, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_type_ft, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
length = tvb_reported_length_remaining(tvb, offset);
crc10 = update_crc10_by_bytes_tvb(0, tvb, offset, length);
offset += 1;
proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_func_spec, tvb, offset, 45, ENC_NA);
offset += 45;
ti = proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)", (crc10 == 0) ? " (correct)" : " (incorrect)");
break;
default:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_data_dissector(next_tvb, pinfo, tree);
break;
}
}
gboolean
atm_is_oam_cell(const guint16 vci, const guint8 pt)
{
return (((vci == 3 || vci == 4) && ((pt & 0x5) == 0))
|| ((pt & 0x6) == 0x4));
}
static void
dissect_atm_cell(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *atm_tree, guint aal, gboolean nni,
gboolean crc_stripped)
{
int offset;
proto_item *ti;
guint8 octet, pt;
int err;
guint16 vpi, vci;
if (!nni) {
octet = tvb_get_guint8(tvb, 0);
proto_tree_add_item(atm_tree, hf_atm_gfc, tvb, 0, 1, ENC_NA);
vpi = (octet & 0xF) << 4;
octet = tvb_get_guint8(tvb, 1);
vpi |= octet >> 4;
proto_tree_add_uint(atm_tree, hf_atm_vpi, tvb, 0, 2, vpi);
} else {
octet = tvb_get_guint8(tvb, 0);
vpi = octet << 4;
octet = tvb_get_guint8(tvb, 1);
vpi |= (octet & 0xF0) >> 4;
proto_tree_add_uint(atm_tree, hf_atm_vpi, tvb, 0, 2, vpi);
}
vci = (octet & 0x0F) << 12;
octet = tvb_get_guint8(tvb, 2);
vci |= octet << 4;
octet = tvb_get_guint8(tvb, 3);
vci |= octet >> 4;
proto_tree_add_uint(atm_tree, hf_atm_vci, tvb, 1, 3, vci);
pt = (octet >> 1) & 0x7;
proto_tree_add_item(atm_tree, hf_atm_payload_type, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(atm_tree, hf_atm_cell_loss_priority, tvb, 3, 1, ENC_BIG_ENDIAN);
if (!crc_stripped) {
ti = proto_tree_add_item(atm_tree, hf_atm_header_error_check, tvb, 4, 1, ENC_BIG_ENDIAN);
err = get_header_err((const guint8*)tvb_memdup(wmem_packet_scope(), tvb, 0, 5));
if (err == NO_ERROR_DETECTED)
proto_item_append_text(ti, " (correct)");
else if (err == UNCORRECTIBLE_ERROR)
proto_item_append_text(ti, " (uncorrectable error)");
else
proto_item_append_text(ti, " (error in bit %d)", err);
offset = 5;
} else {
offset = 4;
}
if (aal == AAL_USER || aal == AAL_UNKNOWN) {
if (atm_is_oam_cell(vci,pt)) {
aal = AAL_OAMCELL;
}
}
dissect_atm_cell_payload(tvb, offset, pinfo, tree, aal, TRUE);
}
static int
dissect_atm_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean truncated, struct atm_phdr *atm_info, gboolean pseudowire_mode)
{
proto_tree *atm_tree = NULL;
proto_item *atm_ti = NULL;
if ( atm_info->aal == AAL_5 && atm_info->type == TRAF_LANE &&
dissect_lanesscop ) {
atm_info->aal = AAL_SIGNALLING;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATM");
if (!pseudowire_mode) {
switch (atm_info->channel) {
case 0:
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "DCE");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "DTE");
break;
case 1:
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "DTE");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "DCE");
break;
}
}
if (atm_info->aal == AAL_5) {
col_add_fstr(pinfo->cinfo, COL_INFO, "AAL5 %s",
val_to_str(atm_info->type, aal5_hltype_vals,
"Unknown traffic type (%u)"));
} else {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(atm_info->aal, aal_vals,
"Unknown AAL (%u)"));
}
if (tree) {
atm_ti = proto_tree_add_item(tree, proto_atm, tvb, 0, -1, ENC_NA);
atm_tree = proto_item_add_subtree(atm_ti, ett_atm);
if (!pseudowire_mode) {
proto_tree_add_uint(atm_tree, hf_atm_channel, tvb, 0, 0, atm_info->channel);
if (atm_info->flags & ATM_REASSEMBLY_ERROR)
expert_add_info(pinfo, atm_ti, &ei_atm_reassembly_failed);
}
proto_tree_add_uint_format_value(atm_tree, hf_atm_aal, tvb, 0, 0,
atm_info->aal,
"%s",
val_to_str(atm_info->aal, aal_vals,
"Unknown AAL (%u)"));
}
if (atm_info->flags & ATM_RAW_CELL) {
if (atm_info->flags & ATM_NO_HEC) {
proto_item_set_len(atm_ti, 4);
} else {
proto_item_set_len(atm_ti, 5);
}
dissect_atm_cell(tvb, pinfo, tree, atm_tree,
atm_info->aal, FALSE,
atm_info->flags & ATM_NO_HEC);
} else {
dissect_reassembled_pdu(tvb, pinfo, tree, atm_tree, atm_ti, truncated,
atm_info, pseudowire_mode);
}
return tvb_reported_length(tvb);
}
static int
dissect_atm_truncated(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct atm_phdr *atm_info = (struct atm_phdr *)data;
DISSECTOR_ASSERT(atm_info != NULL);
return dissect_atm_common(tvb, pinfo, tree, TRUE, atm_info, FALSE);
}
static int
dissect_atm_pw_truncated(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct atm_phdr *atm_info = (struct atm_phdr *)data;
DISSECTOR_ASSERT(atm_info != NULL);
return dissect_atm_common(tvb, pinfo, tree, TRUE, atm_info, TRUE);
}
static int
dissect_atm_untruncated(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct atm_phdr *atm_info = (struct atm_phdr *)data;
DISSECTOR_ASSERT(atm_info != NULL);
return dissect_atm_common(tvb, pinfo, tree, FALSE, atm_info, FALSE);
}
static int
dissect_atm_pw_untruncated(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct atm_phdr *atm_info = (struct atm_phdr *)data;
DISSECTOR_ASSERT(atm_info != NULL);
return dissect_atm_common(tvb, pinfo, tree, FALSE, atm_info, TRUE);
}
static int
dissect_atm_oam_cell(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *atm_tree;
proto_item *atm_ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATM");
atm_ti = proto_tree_add_item(tree, proto_atm, tvb, 0, 0, ENC_NA);
atm_tree = proto_item_add_subtree(atm_ti, ett_atm);
dissect_atm_cell(tvb, pinfo, tree, atm_tree, AAL_OAMCELL, FALSE, FALSE);
return tvb_reported_length(tvb);
}
static int
dissect_atm_pw_oam_cell(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
const pwatm_private_data_t *pwpd = (const pwatm_private_data_t *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATM");
dissect_atm_cell_payload(tvb, 0, pinfo, tree, AAL_OAMCELL,
pwpd->enable_fill_columns_by_atm_dissector);
return tvb_reported_length(tvb);
}
static void atm_prompt(packet_info *pinfo _U_, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Decode AAL2 traffic as");
}
static gpointer atm_value(packet_info *pinfo)
{
return GUINT_TO_POINTER((guint)pinfo->pseudo_header->atm.type);
}
void
proto_register_atm(void)
{
static hf_register_info hf[] = {
{ &hf_atm_aal,
{ "AAL", "atm.aal", FT_UINT8, BASE_DEC, VALS(aal_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_gfc,
{ "GFC", "atm.GFC", FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{ &hf_atm_vpi,
{ "VPI", "atm.vpi", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_vci,
{ "VCI", "atm.vci", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_cid,
{ "CID", "atm.cid", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_reserved,
{ "Reserved", "atm.reserved", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_client_client,
{ "LE Client", "atm.le_client.client", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_lan_destination_tag,
{ "Tag", "atm.lan_destination.tag", FT_UINT16, BASE_HEX, VALS(le_control_landest_tag_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_lan_destination_mac,
{ "MAC address", "atm.lan_destination.mac", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_tlv_type,
{ "TLV Type", "atm.le_control.tlv_type", FT_UINT32, BASE_HEX, VALS(le_tlv_type_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_tlv_length,
{ "TLV Length", "atm.le_control.tlv_length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_lan_destination_route_desc,
{ "Route descriptor", "atm.lan_destination.route_desc", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_lan_destination_lan_id,
{ "LAN ID", "atm.lan_destination.lan_id", FT_UINT16, BASE_DEC, NULL, 0xFFF0,
NULL, HFILL }},
{ &hf_atm_lan_destination_bridge_num,
{ "Bridge number", "atm.lan_destination.bridge_num", FT_UINT16, BASE_DEC, NULL, 0x000F,
NULL, HFILL }},
{ &hf_atm_source_atm,
{ "Source ATM address", "atm.source_atm", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_target_atm,
{ "Target ATM address", "atm.target_atm", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_configure_join_frame_lan_type,
{ "LAN type", "atm.le_configure_join_frame.lan_type", FT_UINT8, BASE_HEX, VALS(le_control_lan_type_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_le_configure_join_frame_max_frame_size,
{ "Maximum frame size", "atm.le_configure_join_frame.max_frame_size", FT_UINT8, BASE_HEX, VALS(le_control_frame_size_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_le_configure_join_frame_num_tlvs,
{ "Number of TLVs", "atm.le_configure_join_frame.num_tlvs", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_configure_join_frame_elan_name_size,
{ "ELAN name size", "atm.le_configure_join_frame.elan_name_size", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_registration_frame_num_tlvs,
{ "Number of TLVs", "atm.le_registration_frame.num_tlvs", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_arp_frame_num_tlvs,
{ "Number of TLVs", "atm.le_arp_frame.num_tlvs", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_verify_frame_num_tlvs,
{ "Number of TLVs", "atm.le_verify_frame.num_tlvs", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_configure_join_frame_elan_name,
{ "ELAN name", "atm.le_configure_join_frame.elan_name", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_marker,
{ "Marker", "atm.le_control.marker", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_protocol,
{ "Protocol", "atm.le_control.protocol", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_version,
{ "Version", "atm.le_control.version", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_opcode,
{ "Opcode", "atm.le_control.opcode", FT_UINT16, BASE_HEX, VALS(le_control_opcode_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_status,
{ "Status", "atm.le_control.status", FT_UINT16, BASE_HEX, VALS(le_control_status_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_transaction_id,
{ "Transaction ID", "atm.le_control.transaction_id", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_requester_lecid,
{ "Requester LECID", "atm.le_control.requester_lecid", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_flags,
{ "Flags", "atm.le_control.flag", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_le_control_flag_v2_capable,
{ "V2 capable", "atm.le_control.flag.v2_capable", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0002,
NULL, HFILL }},
{ &hf_atm_le_control_flag_selective_multicast,
{ "Selective multicast", "atm.le_control.flag.selective_multicast", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0004,
NULL, HFILL }},
{ &hf_atm_le_control_flag_v2_required,
{ "V2 required", "atm.le_control.flag.v2_required", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0008,
NULL, HFILL }},
{ &hf_atm_le_control_flag_proxy,
{ "Proxy", "atm.le_control.flag.flag_proxy", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }},
{ &hf_atm_le_control_flag_exclude_explorer_frames,
{ "Exclude explorer frames", "atm.le_control.flag.exclude_explorer_frames", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0200,
NULL, HFILL }},
{ &hf_atm_le_control_flag_address,
{ "Address", "atm.le_control.flag.address", FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0001,
NULL, HFILL }},
{ &hf_atm_le_control_topology_change,
{ "Topology change", "atm.le_control.flag.topology_change", FT_BOOLEAN, 16, TFS(&tfs_remote_local), 0x0100,
NULL, HFILL }},
{ &hf_atm_traffic_type,
{ "Traffic type", "atm.traffic_type", FT_UINT8, BASE_DEC, VALS(aal5_hltype_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_traffic_vcmx,
{ "VC multiplexed traffic type", "atm.traffic.vcmx", FT_UINT8, BASE_DEC, VALS(vcmx_type_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_traffic_lane,
{ "LANE traffic type", "atm.traffic.lane", FT_UINT8, BASE_DEC, VALS(lane_type_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_traffic_ipsilon,
{ "Ipsilon traffic type", "atm.traffic.ipsilon", FT_UINT8, BASE_DEC, VALS(ipsilon_type_vals), 0x0,
NULL, HFILL }},
{ &hf_atm_cells,
{ "Cells", "atm.cells", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_aal5_uu,
{ "AAL5 UU", "atm.hf_atm.aal5t_uu", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_aal5_cpi,
{ "AAL5 CPI", "atm.hf_atm.aal5t_cpi", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_aal5_len,
{ "AAL5 len", "atm.aal5t_len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_aal5_crc,
{ "AAL5 CRC", "atm.aal5t_crc", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_payload_type,
{ "Payload Type", "atm.payload_type", FT_UINT8, BASE_DEC, NULL, 0x0E,
NULL, HFILL }},
{ &hf_atm_cell_loss_priority,
{ "Cell Loss Priority", "atm.cell_loss_priority", FT_BOOLEAN, 8, TFS(&tfs_low_high_priority), 0x01,
NULL, HFILL }},
{ &hf_atm_header_error_check,
{ "Header Error Check", "atm.header_error_check", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_atm_channel,
{ "Channel", "atm.channel", FT_UINT16, BASE_DEC, VALS(atm_channel_vals), 0,
NULL, HFILL }},
{ &hf_atm_aa1_csi,
{ "CSI", "atm.aa1.csi", FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }},
{ &hf_atm_aa1_seq_count,
{ "Sequence Count", "atm.aa1.seq_count", FT_UINT8, BASE_DEC, NULL, 0x70,
NULL, HFILL }},
{ &hf_atm_aa1_crc,
{ "CRC", "atm.aa1.crc", FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }},
{ &hf_atm_aa1_parity,
{ "Parity", "atm.aa1.parity", FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }},
{ &hf_atm_aa1_payload,
{ "Payload", "atm.aa1.payload", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_aal3_4_seg_type,
{ "Segment Type", "atm.aal3_4.seg_type", FT_UINT16, BASE_DEC, VALS(st_vals), 0xC000,
NULL, HFILL }},
{ &hf_atm_aal3_4_seq_num,
{ "Sequence Number", "atm.aal3_4.seq_num", FT_UINT16, BASE_DEC, NULL, 0x3C00,
NULL, HFILL }},
{ &hf_atm_aal3_4_multiplex_id,
{ "Multiplex ID", "atm.aal3_4.multiplex_id", FT_UINT16, BASE_DEC, NULL, 0x03FF,
NULL, HFILL }},
{ &hf_atm_aal3_4_information,
{ "Information", "atm.aal3_4.information", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_aal3_4_length_indicator,
{ "Length Indicator", "atm.aal3_4.length_indicator", FT_UINT16, BASE_DEC, VALS(st_vals), 0xFC00,
NULL, HFILL }},
{ &hf_atm_aal3_4_crc,
{ "CRC", "atm.aal3_4.crc", FT_UINT16, BASE_DEC, NULL, 0x03FF,
NULL, HFILL }},
{ &hf_atm_aal_oamcell_type,
{ "OAM Type", "atm.aal_oamcell.type", FT_UINT8, BASE_DEC, VALS(oam_type_vals), 0xF0,
NULL, HFILL }},
{ &hf_atm_aal_oamcell_type_fm,
{ "Function Type", "atm.aal_oamcell.type.fm", FT_UINT8, BASE_DEC, VALS(ft_fm_vals), 0x0F,
NULL, HFILL }},
{ &hf_atm_aal_oamcell_type_pm,
{ "Function Type", "atm.aal_oamcell.type.pm", FT_UINT8, BASE_DEC, VALS(ft_pm_vals), 0x0F,
NULL, HFILL }},
{ &hf_atm_aal_oamcell_type_ad,
{ "Function Type", "atm.aal_oamcell.type.ad", FT_UINT8, BASE_DEC, VALS(ft_ad_vals), 0x0F,
NULL, HFILL }},
{ &hf_atm_aal_oamcell_type_ft,
{ "Function Type", "atm.aal_oamcell.type.ft", FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{ &hf_atm_aal_oamcell_func_spec,
{ "Function-specific information", "atm.aal_oamcell.func_spec", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_atm_aal_oamcell_crc,
{ "CRC-10", "atm.aal_oamcell.crc", FT_UINT16, BASE_HEX, NULL, 0x3FF,
NULL, HFILL }},
{ &hf_atm_padding,
{ "Padding", "atm.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_atm,
&ett_ilmi,
&ett_aal1,
&ett_aal3_4,
&ett_oamaal,
&ett_atm_lane,
&ett_atm_lane_lc_lan_dest,
&ett_atm_lane_lc_lan_dest_rd,
&ett_atm_lane_lc_flags,
&ett_atm_lane_lc_tlv,
};
static ei_register_info ei[] = {
{ &ei_atm_reassembly_failed, { "atm.reassembly_failed", PI_REASSEMBLE, PI_ERROR, "PDU reassembly failed", EXPFILL }},
};
expert_module_t* expert_atm;
module_t *atm_module;
static build_valid_func atm_da_build_value[1] = {atm_value};
static decode_as_value_t atm_da_values = {atm_prompt, 1, atm_da_build_value};
static decode_as_t atm_da = {"atm", "Network", "atm.aal2.type", 1, 0, &atm_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
proto_atm = proto_register_protocol("Asynchronous Transfer Mode", "ATM", "atm");
proto_aal1 = proto_register_protocol("ATM AAL1", "AAL1", "aal1");
proto_aal3_4 = proto_register_protocol("ATM AAL3/4", "AAL3/4", "aal3_4");
proto_oamaal = proto_register_protocol("ATM OAM AAL", "OAM AAL", "oamaal");
proto_register_field_array(proto_atm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_atm = expert_register_protocol(proto_atm);
expert_register_field_array(expert_atm, ei, array_length(ei));
proto_ilmi = proto_register_protocol("ILMI", "ILMI", "ilmi");
proto_atm_lane = proto_register_protocol("ATM LAN Emulation", "ATM LANE", "lane");
atm_type_aal2_table = register_dissector_table("atm.aal2.type", "ATM AAL_2 type", proto_atm, FT_UINT32, BASE_DEC);
atm_type_aal5_table = register_dissector_table("atm.aal5.type", "ATM AAL_5 type", proto_atm, FT_UINT32, BASE_DEC);
register_capture_dissector_table("atm.aal5.type", "ATM AAL_5");
register_capture_dissector_table("atm_lane", "ATM LAN Emulation");
atm_handle = register_dissector("atm_truncated", dissect_atm_truncated, proto_atm);
register_dissector("atm_pw_truncated", dissect_atm_pw_truncated, proto_atm);
atm_untruncated_handle = register_dissector("atm_untruncated", dissect_atm_untruncated, proto_atm);
register_dissector("atm_pw_untruncated", dissect_atm_pw_untruncated, proto_atm);
register_dissector("atm_oam_cell", dissect_atm_oam_cell, proto_oamaal);
register_dissector("atm_pw_oam_cell", dissect_atm_pw_oam_cell, proto_oamaal);
atm_module = prefs_register_protocol ( proto_atm, NULL );
prefs_register_bool_preference(atm_module, "dissect_lane_as_sscop", "Dissect LANE as SSCOP",
"Autodection between LANE and SSCOP is hard. As default LANE is preferred",
&dissect_lanesscop);
prefs_register_obsolete_preference(atm_module, "unknown_aal2_type");
register_decode_as(&atm_da);
}
void
proto_reg_handoff_atm(void)
{
capture_dissector_handle_t atm_cap_handle;
eth_withoutfcs_handle = find_dissector_add_dependency("eth_withoutfcs", proto_atm_lane);
tr_handle = find_dissector_add_dependency("tr", proto_atm_lane);
fr_handle = find_dissector_add_dependency("fr", proto_atm);
llc_handle = find_dissector_add_dependency("llc", proto_atm);
sscop_handle = find_dissector_add_dependency("sscop", proto_atm);
ppp_handle = find_dissector_add_dependency("ppp", proto_atm);
eth_maybefcs_handle = find_dissector_add_dependency("eth_maybefcs", proto_atm);
ip_handle = find_dissector_add_dependency("ip", proto_atm);
dissector_add_uint("wtap_encap", WTAP_ENCAP_ATM_PDUS, atm_handle);
dissector_add_uint("atm.aal5.type", TRAF_LANE, create_dissector_handle(dissect_lane, proto_atm_lane));
dissector_add_uint("atm.aal5.type", TRAF_ILMI, create_dissector_handle(dissect_ilmi, proto_ilmi));
dissector_add_uint("wtap_encap", WTAP_ENCAP_ATM_PDUS_UNTRUNCATED,
atm_untruncated_handle);
atm_cap_handle = create_capture_dissector_handle(capture_atm, proto_atm);
capture_dissector_add_uint("wtap_encap", WTAP_ENCAP_ATM_PDUS, atm_cap_handle);
atm_cap_handle = create_capture_dissector_handle(capture_lane, proto_atm_lane);
capture_dissector_add_uint("atm.aal5.type", TRAF_LANE, atm_cap_handle);
}
