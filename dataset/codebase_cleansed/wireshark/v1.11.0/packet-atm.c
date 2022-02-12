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
td = proto_tree_add_text(tree, tvb, offset, 8, "%s LAN destination",
type);
dest_tree = proto_item_add_subtree(td, ett_atm_lane_lc_lan_dest);
tag = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(dest_tree, hf_atm_lan_destination_tag, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
switch (tag) {
case TAG_MAC_ADDRESS:
proto_tree_add_item(dest_tree, hf_atm_lan_destination_mac, tvb, offset, 6, ENC_NA);
break;
case TAG_ROUTE_DESCRIPTOR:
offset += 4;
proto_tree_add_item(dest_tree, hf_atm_lan_destination_route_desc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
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
proto_item *ttlv;
proto_tree *tlv_tree;
while (num_tlvs != 0) {
tlv_type = tvb_get_ntohl(tvb, offset);
tlv_length = tvb_get_guint8(tvb, offset+4);
ttlv = proto_tree_add_text(tree, tvb, offset, 5+tlv_length, "TLV type: %s",
val_to_str(tlv_type, le_tlv_type_vals, "Unknown (0x%08x)"));
tlv_tree = proto_item_add_subtree(ttlv, ett_atm_lane_lc_tlv);
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
offset += 2;
num_tlvs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_atm_le_registration_frame_num_tlvs, tvb, offset, 1, ENC_NA);
offset += 1;
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
offset += 2;
num_tlvs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_atm_le_arp_frame_num_tlvs, tvb, offset, 1, ENC_NA);
offset += 1;
offset += 1;
proto_tree_add_item(tree, hf_atm_target_atm, tvb, offset, 20, ENC_NA);
offset += 20;
offset += 32;
dissect_le_control_tlvs(tvb, offset, num_tlvs, tree);
}
static void
dissect_le_verify_frame(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint8 num_tlvs;
offset += 38;
num_tlvs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_atm_le_verify_frame_num_tlvs, tvb, offset, 1, ENC_NA);
offset += 1;
offset += 1;
proto_tree_add_item(tree, hf_atm_target_atm, tvb, offset, 20, ENC_NA);
offset += 20;
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
offset += 4;
proto_tree_add_item(tree, hf_atm_target_atm, tvb, offset, 20, ENC_NA);
offset += 20;
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
static void
capture_lane(const union wtap_pseudo_header *pseudo_header, const guchar *pd,
int len, packet_counts *ld)
{
switch (pseudo_header->atm.subtype) {
case TRAF_ST_LANE_802_3:
case TRAF_ST_LANE_802_3_MC:
capture_eth(pd, 2, len, ld);
break;
case TRAF_ST_LANE_802_5:
case TRAF_ST_LANE_802_5_MC:
capture_tr(pd, 2, len, ld);
break;
default:
ld->other++;
break;
}
}
static void
dissect_lane(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
tvbuff_t *next_tvb_le_client;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATM LANE");
switch (pinfo->pseudo_header->atm.subtype) {
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
call_dissector(data_handle,next_tvb, pinfo, tree);
break;
}
}
static void
dissect_ilmi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_snmp_pdu(tvb, 0, pinfo, tree, proto_ilmi, ett_ilmi, FALSE);
}
void
capture_atm(const union wtap_pseudo_header *pseudo_header, const guchar *pd,
int len, packet_counts *ld)
{
if (pseudo_header->atm.aal == AAL_5) {
switch (pseudo_header->atm.type) {
case TRAF_LLCMX:
capture_llc(pd, 0, len, ld);
break;
case TRAF_LANE:
capture_lane(pseudo_header, pd, len, ld);
break;
default:
ld->other++;
break;
}
} else
ld->other++;
}
static guint32
update_crc(guint32 crc_accum, const guint8 *data_blk_ptr, int data_blk_size)
{
register int i, j;
for (j = 0; j < data_blk_size; j++) {
i = ( (int) ( crc_accum >> 24) ^ *data_blk_ptr++ ) & 0xff;
crc_accum = ( crc_accum << 8 ) ^ crc_table[i];
}
return crc_accum;
}
static void
dissect_reassembled_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_item *atm_ti,
proto_tree *atm_tree, gboolean truncated)
{
guint length, reported_length;
guint16 aal5_length;
int pad_length;
tvbuff_t *next_tvb;
guint32 crc;
guint32 calc_crc;
gint type;
gboolean pseudowire_mode = (NULL != pinfo->private_data);
if (pinfo->pseudo_header->atm.aal == AAL_5) {
proto_tree_add_uint(atm_tree, hf_atm_traffic_type, tvb, 0, 0, pinfo->pseudo_header->atm.type);
switch (pinfo->pseudo_header->atm.type) {
case TRAF_VCMX:
proto_tree_add_uint(atm_tree, hf_atm_traffic_vcmx, tvb, 0, 0, pinfo->pseudo_header->atm.subtype);
break;
case TRAF_LANE:
proto_tree_add_uint(atm_tree, hf_atm_traffic_lane, tvb, 0, 0, pinfo->pseudo_header->atm.subtype);
break;
case TRAF_IPSILON:
proto_tree_add_uint(atm_tree, hf_atm_traffic_ipsilon, tvb, 0, 0, pinfo->pseudo_header->atm.subtype);
break;
}
}
if (!pseudowire_mode) {
proto_tree_add_uint(atm_tree, hf_atm_vpi, tvb, 0, 0,
pinfo->pseudo_header->atm.vpi);
proto_tree_add_uint(atm_tree, hf_atm_vci, tvb, 0, 0,
pinfo->pseudo_header->atm.vci);
col_append_fstr(pinfo->cinfo, COL_INFO, " VPI=%u, VCI=%u",
pinfo->pseudo_header->atm.vpi,
pinfo->pseudo_header->atm.vci);
}
next_tvb = tvb;
if (truncated) {
if (pinfo->pseudo_header->atm.cells != 0) {
if (tree) {
proto_tree_add_uint(atm_tree, hf_atm_cells, tvb, 0, 0, pinfo->pseudo_header->atm.cells);
proto_tree_add_uint(atm_tree, hf_atm_aal5_uu, tvb, 0, 0, pinfo->pseudo_header->atm.aal5t_u2u >> 8);
proto_tree_add_uint(atm_tree, hf_atm_aal5_cpi, tvb, 0, 0, pinfo->pseudo_header->atm.aal5t_u2u & 0xFF);
proto_tree_add_uint(atm_tree, hf_atm_aal5_len, tvb, 0, 0, pinfo->pseudo_header->atm.aal5t_len);
proto_tree_add_uint(atm_tree, hf_atm_aal5_crc, tvb, 0, 0, pinfo->pseudo_header->atm.aal5t_chksum);
}
}
} else {
length = tvb_length(tvb);
reported_length = tvb_reported_length(tvb);
if ((reported_length % 48) == 0) {
proto_tree_add_uint(atm_tree, hf_atm_cells, tvb, 0, 0, reported_length/48);
}
if ((pinfo->pseudo_header->atm.aal == AAL_5 ||
pinfo->pseudo_header->atm.aal == AAL_SIGNALLING) &&
length >= reported_length) {
aal5_length = tvb_get_ntohs(tvb, length - 6);
if (aal5_length > 0 && aal5_length <= length - 8) {
pad_length = length - aal5_length - 8;
if (pad_length <= 47) {
if (tree) {
proto_item *ti;
if (pad_length > 0) {
proto_tree_add_text(atm_tree, tvb, aal5_length, pad_length,
"Padding");
}
proto_tree_add_item(atm_tree, hf_atm_aal5_uu, tvb, length - 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(atm_tree, hf_atm_aal5_cpi, tvb, length - 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(atm_tree, hf_atm_aal5_len, tvb, length - 6, 2, ENC_BIG_ENDIAN);
crc = tvb_get_ntohl(tvb, length - 4);
calc_crc = update_crc(0xFFFFFFFF, tvb_get_ptr(tvb, 0, length),
length);
ti = proto_tree_add_uint(atm_tree, hf_atm_aal5_crc, tvb, length - 4, 4, crc);
proto_item_append_text(ti, (calc_crc == 0xC704DD7B) ? " (correct)" : " (incorrect)");
}
next_tvb = tvb_new_subset(tvb, 0, aal5_length, aal5_length);
}
}
}
}
switch (pinfo->pseudo_header->atm.aal) {
case AAL_SIGNALLING:
call_dissector(sscop_handle, next_tvb, pinfo, tree);
break;
case AAL_5:
switch (pinfo->pseudo_header->atm.type) {
case TRAF_SSCOP:
call_dissector(sscop_handle, next_tvb, pinfo, tree);
break;
case TRAF_FR:
call_dissector(fr_handle, next_tvb, pinfo, tree);
break;
case TRAF_LLCMX:
call_dissector(llc_handle, next_tvb, pinfo, tree);
break;
case TRAF_LANE:
call_dissector(lane_handle, next_tvb, pinfo, tree);
break;
case TRAF_ILMI:
call_dissector(ilmi_handle, next_tvb, pinfo, tree);
break;
case TRAF_GPRS_NS:
call_dissector(gprs_ns_handle, next_tvb, pinfo, tree);
break;
default:
{
gboolean decoded = FALSE;
if (tvb_length(next_tvb) > 7)
{
guint8 octet[8];
tvb_memcpy(next_tvb, octet, 0, sizeof(octet));
decoded = TRUE;
if (octet[0] == 0xaa
&& octet[1] == 0xaa
&& octet[2] == 0x03)
{
call_dissector(llc_handle, next_tvb, pinfo, tree);
}
else if ((pntohs(octet) & 0xff) == PPP_IP)
{
call_dissector(ppp_handle, next_tvb, pinfo, tree);
}
else if (pntohs(octet) == 0x00)
{
proto_tree_add_text(tree, tvb, 0, 2, "Pad: 0x0000");
next_tvb = tvb_new_subset_remaining(tvb, 2);
call_dissector(eth_handle, next_tvb, pinfo, tree);
}
else if (octet[2] == 0x03 &&
((octet[3] == 0xcc ||
octet[3] == 0x8e) ||
(octet[3] == 0x00 &&
octet[4] == 0x80)))
{
call_dissector(fr_handle, next_tvb, pinfo, tree);
}
else if (octet[4] == 0x03 &&
((octet[5] == 0xcc ||
octet[5] == 0x8e) ||
(octet[5] == 0x00 &&
octet[6] == 0x80)))
{
call_dissector(fr_handle, next_tvb, pinfo, tree);
}
else if (((octet[0] & 0xf0)== 0x40) ||
((octet[0] & 0xf0) == 0x60))
{
call_dissector(ip_handle, next_tvb, pinfo, tree);
}
else
{
decoded = FALSE;
}
}
if (tree && !decoded) {
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
break;
}
break;
case AAL_2:
proto_tree_add_uint(atm_tree, hf_atm_cid, tvb, 0, 0,
pinfo->pseudo_header->atm.aal2_cid);
proto_item_append_text(atm_ti, " (vpi=%u vci=%u cid=%u)",
pinfo->pseudo_header->atm.vpi,
pinfo->pseudo_header->atm.vci,
pinfo->pseudo_header->atm.aal2_cid);
if (pinfo->pseudo_header->atm.flags & ATM_AAL2_NOPHDR) {
next_tvb = tvb;
} else {
next_tvb = tvb_new_subset_remaining(tvb, 4);
}
type = pinfo->pseudo_header->atm.type;
if (type == TRAF_UNKNOWN) {
type = unknown_aal2_type;
}
switch (type) {
case TRAF_UMTS_FP:
call_dissector(fp_handle, next_tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
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
static guint16
update_crc10_by_bytes(guint16 crc10_accum, const guint8 *data_blk_ptr,
int data_blk_size)
{
register int i;
for (i = 0; i < data_blk_size; i++) {
crc10_accum = ((crc10_accum << 8) & 0x3ff)
^ byte_crc10_table[( crc10_accum >> 2) & 0xff]
^ *data_blk_ptr++;
}
return crc10_accum;
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
proto_tree *aal_tree;
proto_item *ti;
guint8 octet, pt;
int err;
guint16 vpi, vci, aal3_4_hdr, crc10;
gint length;
tvbuff_t *next_tvb;
const pwatm_private_data_t *pwpd = (const pwatm_private_data_t *)pinfo->private_data;
if (NULL == pwpd) {
if (!nni) {
octet = tvb_get_guint8(tvb, 0);
proto_tree_add_text(atm_tree, tvb, 0, 1, "GFC: 0x%x", octet >> 4);
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
err = get_header_err(tvb_get_ptr(tvb, 0, 5));
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
}
else
{
offset = 0;
pwpd = (const pwatm_private_data_t *)pinfo->private_data;
vci = pwpd->vci;
pt = pwpd->pti;
}
if (aal == AAL_USER || aal == AAL_UNKNOWN) {
if (atm_is_oam_cell(vci,pt)) {
aal = AAL_OAMCELL;
}
}
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
length = tvb_length_remaining(tvb, offset);
crc10 = update_crc10_by_bytes(0, tvb_get_ptr(tvb, offset, length),
length);
offset += 2;
proto_tree_add_item(aal_tree, hf_atm_aal3_4_information, tvb, offset, 44, ENC_NA);
offset += 44;
proto_tree_add_item(aal_tree, hf_atm_aal3_4_length_indicator, tvb, offset, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(aal_tree, hf_atm_aal3_4_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)", (crc10 == 0) ? " (correct)" : " (incorrect)");
break;
case AAL_OAMCELL:
if (NULL == pwpd || pwpd->enable_fill_columns_by_atm_dissector)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OAM AAL");
col_clear(pinfo->cinfo, COL_INFO);
}
ti = proto_tree_add_item(tree, proto_oamaal, tvb, offset, -1, ENC_NA);
aal_tree = proto_item_add_subtree(ti, ett_oamaal);
octet = tvb_get_guint8(tvb, offset);
if (NULL == pwpd || pwpd->enable_fill_columns_by_atm_dissector)
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
length = tvb_length_remaining(tvb, offset);
crc10 = update_crc10_by_bytes(0, tvb_get_ptr(tvb, offset, length),
length);
offset += 1;
proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_func_spec, tvb, offset, 45, ENC_NA);
offset += 45;
ti = proto_tree_add_item(aal_tree, hf_atm_aal_oamcell_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)", (crc10 == 0) ? " (correct)" : " (incorrect)");
break;
default:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
}
static void
dissect_atm_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean truncated)
{
proto_tree *atm_tree = NULL;
proto_item *atm_ti = NULL;
gboolean pseudowire_mode = (NULL != pinfo->private_data);
if ( pinfo->pseudo_header->atm.aal == AAL_5 &&
pinfo->pseudo_header->atm.type == TRAF_LANE &&
dissect_lanesscop ) {
pinfo->pseudo_header->atm.aal = AAL_SIGNALLING;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATM");
if (!pseudowire_mode) {
switch (pinfo->pseudo_header->atm.channel) {
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
if (pinfo->pseudo_header->atm.aal == AAL_5) {
col_add_fstr(pinfo->cinfo, COL_INFO, "AAL5 %s",
val_to_str(pinfo->pseudo_header->atm.type, aal5_hltype_vals,
"Unknown traffic type (%u)"));
} else {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(pinfo->pseudo_header->atm.aal, aal_vals,
"Unknown AAL (%u)"));
}
if (tree) {
atm_ti = proto_tree_add_item(tree, proto_atm, tvb, 0, -1, ENC_NA);
atm_tree = proto_item_add_subtree(atm_ti, ett_atm);
if (!pseudowire_mode) {
proto_tree_add_uint(atm_tree, hf_atm_channel, tvb, 0, 0, pinfo->pseudo_header->atm.channel);
}
proto_tree_add_uint_format_value(atm_tree, hf_atm_aal, tvb, 0, 0,
pinfo->pseudo_header->atm.aal,
"%s",
val_to_str(pinfo->pseudo_header->atm.aal, aal_vals,
"Unknown AAL (%u)"));
}
if (pinfo->pseudo_header->atm.flags & ATM_RAW_CELL) {
if (pinfo->pseudo_header->atm.flags & ATM_NO_HEC) {
proto_item_set_len(atm_ti, 4);
} else {
proto_item_set_len(atm_ti, 5);
}
dissect_atm_cell(tvb, pinfo, tree, atm_tree,
pinfo->pseudo_header->atm.aal, FALSE,
pinfo->pseudo_header->atm.flags & ATM_NO_HEC);
} else {
dissect_reassembled_pdu(tvb, pinfo, tree, atm_tree, atm_ti, truncated);
}
}
static void
dissect_atm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_atm_common(tvb, pinfo, tree, TRUE);
}
static void
dissect_atm_untruncated(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_atm_common(tvb, pinfo, tree, FALSE);
}
static void
dissect_atm_oam_cell(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *atm_tree = NULL;
proto_item *atm_ti = NULL;
gboolean pseudowire_mode = (NULL != pinfo->private_data);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ATM");
if (!pseudowire_mode) {
if (tree) {
atm_ti = proto_tree_add_protocol_format(tree, proto_atm, tvb, 0, 0, "ATM");
atm_tree = proto_item_add_subtree(atm_ti, ett_atm);
}
}
dissect_atm_cell(tvb, pinfo, tree, atm_tree, AAL_OAMCELL, FALSE, FALSE);
}
void
proto_register_atm(void)
{
static hf_register_info hf[] = {
{ &hf_atm_aal,
{ "AAL", "atm.aal", FT_UINT8, BASE_DEC, VALS(aal_vals), 0x0,
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
static const enum_val_t unknown_aal2_options[] = {
{ "raw", "Raw data", TRAF_UNKNOWN },
{ "umts_fp", "UMTS FP", TRAF_UMTS_FP },
{ NULL, NULL, 0 }
};
module_t *atm_module;
proto_atm = proto_register_protocol("Asynchronous Transfer Mode", "ATM", "atm");
proto_aal1 = proto_register_protocol("ATM AAL1", "AAL1", "aal1");
proto_aal3_4 = proto_register_protocol("ATM AAL3/4", "AAL3/4", "aal3_4");
proto_oamaal = proto_register_protocol("ATM OAM AAL", "OAM AAL", "oamaal");
proto_register_field_array(proto_atm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
proto_ilmi = proto_register_protocol("ILMI", "ILMI", "ilmi");
register_dissector("ilmi", dissect_ilmi, proto_ilmi);
proto_atm_lane = proto_register_protocol("ATM LAN Emulation",
"ATM LANE", "lane");
register_dissector("lane", dissect_lane, proto_atm_lane);
atm_handle = register_dissector("atm_truncated", dissect_atm, proto_atm);
atm_untruncated_handle = register_dissector("atm_untruncated", dissect_atm_untruncated, proto_atm);
register_dissector("atm_oam_cell", dissect_atm_oam_cell, proto_oamaal);
atm_module = prefs_register_protocol ( proto_atm, NULL );
prefs_register_bool_preference(atm_module, "dissect_lane_as_sscop", "Dissect LANE as SSCOP",
"Autodection between LANE and SSCOP is hard. As default LANE is preferred",
&dissect_lanesscop);
prefs_register_enum_preference(atm_module, "unknown_aal2_type",
"Decode unknown AAL2 traffic as",
"Type used to dissect unknown AAL2 traffic",
&unknown_aal2_type, unknown_aal2_options, FALSE);
}
void
proto_reg_handoff_atm(void)
{
eth_withoutfcs_handle = find_dissector("eth_withoutfcs");
tr_handle = find_dissector("tr");
fr_handle = find_dissector("fr");
llc_handle = find_dissector("llc");
sscop_handle = find_dissector("sscop");
lane_handle = find_dissector("lane");
ilmi_handle = find_dissector("ilmi");
ppp_handle = find_dissector("ppp");
eth_handle = find_dissector("eth");
ip_handle = find_dissector("ip");
data_handle = find_dissector("data");
fp_handle = find_dissector("fp");
gprs_ns_handle = find_dissector("gprs_ns");
dissector_add_uint("wtap_encap", WTAP_ENCAP_ATM_PDUS, atm_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_ATM_PDUS_UNTRUNCATED,
atm_untruncated_handle);
}
