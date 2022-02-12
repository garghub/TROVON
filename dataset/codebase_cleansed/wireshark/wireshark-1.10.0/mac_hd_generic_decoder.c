void wimax_defragment_init(void)
{
gint i;
reassembly_table_init(&payload_reassembly_table,
&addresses_reassembly_table_functions);
for (i = 0; i < MAX_CID; i++)
{
cid_adjust[i] = 1;
cid_vernier[i] = 0;
}
cid_adj_array_size = 0;
if (cid_adj_array) {
g_free(cid_adj_array);
}
cid_adj_array = NULL;
if (frag_num_array) {
g_free(frag_num_array);
}
frag_num_array = NULL;
bs_address.len = 0;
seen_a_service_type = 0;
max_logical_bands = 12;
init_wimax_globals();
}
static guint decode_packing_subheader(tvbuff_t *payload_tvb, packet_info *pinfo, proto_tree *tree, guint payload_length _U_, guint payload_offset, proto_item *parent_item)
{
proto_item *generic_item = NULL;
proto_tree *generic_tree = NULL;
guint starting_offset = payload_offset;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Packing subhdr");
proto_item_append_text(parent_item, ", Packing Subheader");
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, payload_tvb, payload_offset, ((arq_enabled|extended_type)?3:2), "Packing subheader (%u bytes)", ((arq_enabled|extended_type)?3:2));
generic_tree = proto_item_add_subtree(generic_item, ett_mac_pkt_subheader_decoder);
frag_type = (tvb_get_guint8(payload_tvb, payload_offset) & FRAGMENT_TYPE_MASK) >> 6;
if (arq_fb_payload)
{
frag_len = ((tvb_get_ntohl(payload_tvb, payload_offset) & FRAG_LENGTH_MASK) >> 8);
seq_number = (tvb_get_ntohs(payload_tvb, payload_offset) & SEQ_NUMBER_MASK_11) >> 3;
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_fc_ext, payload_tvb, payload_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_bsn, payload_tvb, payload_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_len_ext, payload_tvb, payload_offset, 3, ENC_BIG_ENDIAN);
payload_offset += 3;
frag_len -= 3;
}
else
{
if (extended_type)
{
frag_len = ((tvb_get_ntohl(payload_tvb, payload_offset) & FRAG_LENGTH_MASK) >> 8);
seq_number = (tvb_get_ntohs(payload_tvb, payload_offset) & SEQ_NUMBER_MASK_11) >> 3;
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_fc_ext, payload_tvb, payload_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_fsn_ext, payload_tvb, payload_offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_len_ext, payload_tvb, payload_offset, 3, ENC_BIG_ENDIAN);
payload_offset += 3;
frag_len -= 3;
}
else
{
frag_len = (tvb_get_ntohs(payload_tvb, payload_offset) & PACKING_SUBHEADER_LENGTH_MASK);
seq_number = (tvb_get_guint8(payload_tvb, payload_offset) & SEQ_NUMBER_MASK) >> 3;
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_fc, payload_tvb, payload_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_fsn, payload_tvb, payload_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_packing_subhd_len, payload_tvb, payload_offset, 2, ENC_BIG_ENDIAN);
payload_offset += 2;
frag_len -= 2;
}
}
if ((gint)frag_len < 0)
frag_len = 0;
return payload_offset - starting_offset;
}
void dissect_mac_header_generic_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint payload_offset;
guint payload_length = 0;
static guint8 frag_number[MAX_CID];
static guint cid_list[MAX_CID];
static guint cid_base;
static const char reassem_str[] = "Reassembled Data transport PDU (%u bytes)";
static const char data_str[] = "Data transport PDU (%u bytes)";
const char *str_ptr;
gint length, i, cid_index;
guint tvb_len, ret_length, ubyte, new_tvb_len;
guint new_payload_len = 0;
guint mac_ec, mac_esf, mac_ci, mac_len, mac_cid, cid;
guint ffb_grant_mgmt_subheader, packing_subheader, fragment_subheader;
guint mesh_subheader;
guint packing_length;
guint32 mac_crc, calculated_crc;
proto_item *parent_item = NULL;
proto_item *generic_item = NULL;
proto_tree *generic_tree = NULL;
proto_item *child_item = NULL;
proto_tree *child_tree = NULL;
tvbuff_t *payload_tvb;
tvbuff_t *data_pdu_tvb;
fragment_data *payload_frag;
gboolean first_arq_fb_payload = TRUE;
dissector_handle_t mac_payload_handle;
proto_mac_header_generic_decoder = proto_wimax;
if (tree)
{
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "GMH");
#endif
tvb_len = tvb_reported_length(tvb);
if (tvb_len < WIMAX_MAC_HEADER_SIZE)
{
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, tvb_len, "Error: the size of Generic MAC Header tvb is too small! (%u bytes)", tvb_len);
generic_tree = proto_item_add_subtree(generic_item, ett_mac_header_generic_decoder);
proto_tree_add_item(generic_tree, hf_mac_header_generic_value_bytes, tvb, offset, tvb_len, ENC_NA);
return;
}
parent_item = proto_tree_get_parent(tree);
proto_item_append_text(parent_item, " - Generic MAC Header");
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, WIMAX_MAC_HEADER_SIZE, "Generic MAC Header (%u bytes)", WIMAX_MAC_HEADER_SIZE);
generic_tree = proto_item_add_subtree(generic_item, ett_mac_header_generic_decoder);
ubyte = tvb_get_guint8(tvb, offset);
mac_ec = ((ubyte & WIMAX_MAC_HEADER_GENERIC_EC_MASK)?1:0);
ffb_grant_mgmt_subheader = ((ubyte & GENERIC_SUB_TYPE_0)?1:0);
packing_subheader = ((ubyte & GENERIC_SUB_TYPE_1)?1:0);
fragment_subheader = ((ubyte & GENERIC_SUB_TYPE_2)?1:0);
extended_type = ((ubyte & GENERIC_SUB_TYPE_3)?1:0);
arq_fb_payload = ((ubyte & GENERIC_SUB_TYPE_4)?1:0);
mesh_subheader = ((ubyte & GENERIC_SUB_TYPE_5)?1:0);
ubyte = tvb_get_guint8(tvb, (offset+1));
mac_esf = ((ubyte & WIMAX_MAC_HEADER_GENERIC_ESF_MASK)?1:0);
mac_ci = ((ubyte & WIMAX_MAC_HEADER_GENERIC_CI_MASK)?1:0);
mac_len = (tvb_get_ntohs(tvb, (offset+1)) & WIMAX_MAC_HEADER_GENERIC_LEN);
mac_cid = tvb_get_ntohs(tvb, (offset+3));
proto_tree_add_item(generic_tree, hf_mac_header_generic_ht, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_ec, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_type_5, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_type_4, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_type_3, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_type_2, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_type_1, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_type_0, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_esf, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_ci, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_eks, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_rsv, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_len, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_cid, tvb, (offset+3), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_hcs, tvb, (offset+5), 1, ENC_BIG_ENDIAN);
length = mac_len - WIMAX_MAC_HEADER_SIZE;
#ifdef DEBUG
proto_item_append_text(parent_item, "tvb length=%u, mac length=%u, frame length=%u,", tvb_len, mac_len, length);
#endif
offset += WIMAX_MAC_HEADER_SIZE;
if (mac_ec)
{
if (mac_ci)
{
if (length >= (gint)sizeof(mac_crc))
{
length -= (int)sizeof(mac_crc);
}
}
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, length, "Encrypted PDU (%u bytes)", length);
generic_tree = proto_item_add_subtree(generic_item, ett_mac_data_pdu_decoder);
proto_tree_add_item(generic_tree, hf_mac_header_generic_value_bytes, tvb, offset, length, ENC_NA);
goto check_crc;
}
if (mac_esf)
{
proto_item_append_text(parent_item, ", Extended Subheader(s)");
ret_length = extended_subheader_decoder(tvb_new_subset(tvb, offset, length, length), pinfo, tree);
length -= ret_length;
offset += ret_length;
}
if (mesh_subheader)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Mesh subhdr");
proto_item_append_text(parent_item, ", Mesh Subheader");
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, length, "Mesh subheader (2 bytes)");
generic_tree = proto_item_add_subtree(generic_item, ett_mac_mesh_subheader_decoder);
proto_tree_add_item(generic_tree, hf_mac_header_generic_mesh_subheader, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
}
if (ffb_grant_mgmt_subheader)
{
if (is_down_link(pinfo))
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Fast-fb subhdr");
proto_item_append_text(parent_item, ", Fast-feedback Subheader");
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, length, "Fast-feedback allocation (DL) subheader (%u bytes)", length);
generic_tree = proto_item_add_subtree(generic_item, ett_mac_fast_fb_subheader_decoder);
proto_tree_add_item(generic_tree, hf_mac_header_generic_fast_fb_subhd_alloc_offset, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_fast_fb_subhd_fb_type, tvb, offset, 1, ENC_BIG_ENDIAN);
length -= 1;
offset += 1;
}
else
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Grant mgmt subhdr");
proto_item_append_text(parent_item, ", Grant Management Subheader");
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, 2, "Grant management (UL) subheader (2 bytes)");
generic_tree = proto_item_add_subtree(generic_item, ett_mac_grant_mgmt_subheader_decoder);
scheduling_service_type = get_service_type();
switch (scheduling_service_type)
{
case SCHEDULE_SERVICE_TYPE_UGS:
proto_item_append_text(generic_item, ": It looks like UGS is the correct Scheduling Service Type");
break;
case SCHEDULE_SERVICE_TYPE_EXT_RTPS:
proto_item_append_text(generic_item, ": It looks like Extended rtPS is the correct Scheduling Service Type");
break;
case -1:
proto_item_append_text(generic_item, ": Cannot determine the correct Scheduling Service Type");
break;
default:
proto_item_append_text(generic_item, ": It looks like Piggyback Request is the correct Scheduling Service Type");
break;
}
child_item = proto_tree_add_item(generic_tree, hf_mac_header_generic_grant_mgmt_ugs_tree, tvb, offset, 2, ENC_BIG_ENDIAN);
child_tree = proto_item_add_subtree(child_item, ett_mac_grant_mgmt_subheader_decoder);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_ugs_si, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_ugs_pm, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_ugs_fli, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_ugs_fl, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_ugs_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
child_item = proto_tree_add_item(generic_tree, hf_mac_header_generic_grant_mgmt_ext_rtps_tree, tvb, offset, 2, ENC_BIG_ENDIAN);
child_tree = proto_item_add_subtree(child_item, ett_mac_grant_mgmt_subheader_decoder);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_ext_pbr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_ext_fli, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_ext_fl, tvb, offset, 2, ENC_BIG_ENDIAN);
child_item = proto_tree_add_item(generic_tree, hf_mac_header_generic_grant_mgmt_ext_pbr_tree, tvb, offset, 2, ENC_BIG_ENDIAN);
child_tree = proto_item_add_subtree(child_item, ett_mac_grant_mgmt_subheader_decoder);
proto_tree_add_item(child_tree, hf_mac_header_generic_grant_mgmt_subhd_pbr, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
}
}
if (fragment_subheader)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Frag subhdr");
proto_item_append_text(parent_item, ", Frag Subheader");
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, ((arq_enabled|extended_type)?2:1), "Fragmentation subheader (%u bytes)", ((arq_enabled|extended_type)?2:1));
generic_tree = proto_item_add_subtree(generic_item, ett_mac_frag_subheader_decoder);
frag_type = (tvb_get_guint8(tvb, offset) & FRAGMENT_TYPE_MASK) >> 6;
if (arq_fb_payload)
{
seq_number = (tvb_get_ntohs(tvb, offset) & SEQ_NUMBER_MASK_11) >> 3;
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_fc_ext, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_bsn, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_rsv_ext, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
}
else
{
if (extended_type)
{
seq_number = (tvb_get_ntohs(tvb, offset) & SEQ_NUMBER_MASK_11) >> 3;
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_fc_ext, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_fsn_ext, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_rsv_ext, tvb, offset, 2, ENC_BIG_ENDIAN);
length -= 2;
offset += 2;
}
else
{
seq_number = (tvb_get_guint8(tvb, offset) & SEQ_NUMBER_MASK) >> 3;
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_fc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_fsn, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(generic_tree, hf_mac_header_generic_frag_subhd_rsv, tvb, offset, 1, ENC_BIG_ENDIAN);
length -= 1;
offset += 1;
}
}
frag_len = length;
}
else
{
frag_type = NO_FRAG;
}
if (mac_ci)
{
if (length < (gint)sizeof(mac_crc))
{
proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, length, "Error - the frame is too short (%u bytes)", length);
return;
}
length -= (int)sizeof(mac_crc);
}
while (length > 0)
{
frag_len = length;
if (packing_subheader)
{
packing_length = decode_packing_subheader(tvb, pinfo, tree, length, offset, parent_item);
length -= packing_length;
offset += packing_length;
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, frag_len, "Data transport PDU (%u bytes)", frag_len);
generic_tree = proto_item_add_subtree(generic_item, ett_mac_data_pdu_decoder);
proto_tree_add_item(generic_tree, hf_mac_header_generic_value_bytes, tvb, offset, frag_len, ENC_NA);
}
if (frag_type == NO_FRAG)
{
payload_tvb = tvb_new_subset(tvb, offset, frag_len, frag_len);
payload_length = frag_len;
new_payload_len = frag_len;
}
else
{
for (i = 0; i < MAX_CID; i++)
{
if (cid_list[i] == mac_cid)
{
cid_base = i * (0xFFFFFFFF / MAX_CID);
break;
}
if (cid_list[i] == 0)
{
cid_list[i] = mac_cid;
cid_base = i * (0xFFFFFFFF / MAX_CID);
break;
}
}
cid_index = i;
while (pinfo->fd->num > cid_adj_array_size)
{
cid_adj_array_size += 1024;
cid_adj_array = (guint *)g_realloc(cid_adj_array, (int)sizeof(guint) * cid_adj_array_size);
frag_num_array = (guint8 *)g_realloc(frag_num_array, (int)sizeof(guint8) * cid_adj_array_size);
memset(&cid_adj_array[cid_adj_array_size - 1024], 0, (int)sizeof(guint) * 1024);
}
if (first_gmh)
{
cid_adjust[cid_index] += cid_vernier[cid_index];
cid_vernier[cid_index] = 0;
}
frag_number[cid_index]++;
if (frag_type == FIRST_FRAG)
{
frag_number[cid_index] = 0;
}
if (cid_adj_array[pinfo->fd->num])
{
cid_adjust[cid_index] = cid_adj_array[pinfo->fd->num];
if (first_gmh)
{
frag_number[cid_index] = frag_num_array[pinfo->fd->num];
}
} else {
cid_adj_array[pinfo->fd->num] = cid_adjust[cid_index];
if (first_gmh)
{
frag_num_array[pinfo->fd->num] = frag_number[cid_index];
}
}
first_gmh = FALSE;
cid = cid_base + cid_adjust[cid_index] + cid_vernier[cid_index];
save_src = pinfo->src;
save_dst = pinfo->dst;
pinfo->src = pinfo->dl_src;
pinfo->dst = pinfo->dl_dst;
payload_frag = fragment_add_seq(&payload_reassembly_table, tvb, offset, pinfo, cid, NULL, frag_number[cid_index], frag_len, ((frag_type==LAST_FRAG)?0:1), 0);
pinfo->src = save_src;
pinfo->dst = save_dst;
if (frag_type == LAST_FRAG)
{
cid_vernier[cid_index]++;
}
proto_tree_add_text(tree, tvb, offset, frag_len, "Payload Fragment (%d bytes)", frag_len);
if (payload_frag && frag_type == LAST_FRAG)
{
payload_length = payload_frag->len;
payload_tvb = tvb_new_child_real_data(tvb, payload_frag->data, payload_length, payload_length);
add_new_data_source(pinfo, payload_tvb, "Reassembled WiMax MAC payload");
new_payload_len = payload_length;
}
else
{
payload_tvb = NULL;
#ifdef DEBUG
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Dropped the incomplete frame");
}
#endif
#if 0
if (frag_type == FIRST_FRAG)
{
payload_tvb = tvb_new_subset(tvb, offset, length, length);
payload_length = length;
frag_len = length;
}
#endif
}
}
if (payload_tvb)
{
payload_offset = 0;
if (payload_length > 0)
{
if (!new_payload_len)
continue;
if (first_arq_fb_payload && arq_fb_payload)
{
first_arq_fb_payload = FALSE;
#ifndef DEBUG
arq_feedback_payload_decoder(tvb_new_subset(payload_tvb, payload_offset, new_payload_len, new_payload_len), pinfo, generic_tree, parent_item);
#else
ret_length = arq_feedback_payload_decoder(tvb_new_subset(payload_tvb, payload_offset, new_payload_len, new_payload_len), pinfo, generic_tree, parent_item);
if (ret_length != new_payload_len)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "incorrect ARQ fb payload size");
}
#endif
}
else
{
if (mac_cid == cid_padding)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Padding CID");
generic_item = proto_tree_get_parent(tree);
proto_item_append_text(generic_item, ", Padding CID");
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, payload_tvb, payload_offset, new_payload_len, "Padding CID (%u bytes)", new_payload_len);
generic_tree = proto_item_add_subtree(generic_item, ett_mac_header_generic_decoder);
proto_tree_add_item(generic_tree, hf_mac_header_generic_value_bytes, payload_tvb, payload_offset, new_payload_len, ENC_NA);
}
else if ((mac_cid <= (2 * global_cid_max_basic)) || (mac_cid == cid_aas_ranging)
|| (mac_cid >= cid_normal_multicast))
{
dissect_mac_mgmt_msg_decoder(tvb_new_subset(payload_tvb, payload_offset, new_payload_len, new_payload_len), pinfo, tree);
}
else
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Data");
proto_item_append_text(parent_item, ", Data");
if ((new_payload_len + payload_offset) > payload_length)
{
new_tvb_len = new_payload_len - payload_offset;
}
else
{
new_tvb_len = new_payload_len;
}
if (frag_type == LAST_FRAG || frag_type == NO_FRAG)
{
if (frag_type == NO_FRAG)
{
str_ptr = data_str;
new_payload_len = frag_len;
}
else
{
str_ptr = reassem_str;
}
{
data_pdu_tvb = tvb_new_subset(payload_tvb, payload_offset, new_tvb_len, new_tvb_len);
generic_item = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, data_pdu_tvb, payload_offset, new_payload_len, str_ptr, new_payload_len);
generic_tree = proto_item_add_subtree(generic_item, ett_mac_data_pdu_decoder);
if (tvb_get_guint8(payload_tvb, payload_offset) == IP_HEADER_BYTE)
{
mac_payload_handle = find_dissector("ip");
if (mac_payload_handle)
call_dissector(mac_payload_handle, tvb_new_subset(payload_tvb, payload_offset, new_tvb_len, new_tvb_len), pinfo, generic_tree);
else
proto_tree_add_item(generic_tree, hf_mac_header_generic_value_bytes, payload_tvb, payload_offset, new_tvb_len, ENC_NA);
}
else
proto_tree_add_item(generic_tree, hf_mac_header_generic_value_bytes, payload_tvb, payload_offset, new_tvb_len, ENC_NA);
}
}
}
}
payload_length -= new_payload_len;
}
}
length -= frag_len;
offset += frag_len;
}
check_crc:
if (mac_ci)
{
proto_item_append_text(parent_item, ", CRC");
if (MIN(tvb_len, tvb_reported_length(tvb)) >= mac_len)
{
mac_crc = tvb_get_ntohl(tvb, mac_len - (int)sizeof(mac_crc));
calculated_crc = wimax_mac_calc_crc32(tvb_get_ptr(tvb, 0, mac_len - (int)sizeof(mac_crc)), mac_len - (int)sizeof(mac_crc));
generic_item = proto_tree_add_item(tree, hf_mac_header_generic_crc, tvb, mac_len - (int)sizeof(mac_crc), (int)sizeof(mac_crc), ENC_BIG_ENDIAN);
if (mac_crc != calculated_crc)
{
proto_item_append_text(generic_item, " - incorrect! (should be: 0x%x)", calculated_crc);
}
}
else
{
proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, 0, tvb_len, "CRC missing - the frame is too short (%u bytes)", tvb_len);
}
}
else
{
proto_item_append_text(parent_item, ", No CRC");
proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, 0, tvb_len, "CRC is not included in this frame!");
}
}
}
static gint extended_subheader_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0;
gint length, ext_length, ubyte, i;
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
proto_tree *ti_tree = NULL;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Ext subhdrs");
length = tvb_reported_length(tvb);
if (!length)
{
proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, length, "Error: extended subheader tvb is empty ! (%u bytes)", length);
return length;
}
ext_length = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, length, "Extended subheader group (%u bytes)", ext_length);
sub_tree = proto_item_add_subtree(ti, ett_mac_ext_subheader_decoder);
for (i=1; i<ext_length;)
{
ubyte = (tvb_get_guint8(tvb, (offset+i)) & EXTENDED_SUB_HEADER_TYPE_MASK);
proto_tree_add_item(sub_tree, hf_mac_header_generic_ext_subheader_rsv, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
if (is_down_link(pinfo))
{
ti = proto_tree_add_item(sub_tree, hf_mac_header_generic_ext_subheader_type_dl, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
ti_tree = proto_item_add_subtree(ti, ett_mac_ext_subheader_dl_decoder);
i++;
switch (ubyte)
{
case SDU_SN:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_sdu_sn, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
i++;
break;
case DL_SLEEP_CONTROL:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_dl_sleep_control_pscid, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_dl_sleep_control_op, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_dl_sleep_control_fswe, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_dl_sleep_control_fswb, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_dl_sleep_control_rsv, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
i += 3;
break;
case FEEDBACK_REQ:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_fb_req_uiuc, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_fb_req_fb_type, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_fb_req_ofdma_symbol_offset, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_fb_req_subchannel_offset, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_fb_req_slots, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_fb_req_frame_offset, tvb, (offset+i), 3, ENC_BIG_ENDIAN);
i += 3;
break;
case SN_REQ:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_sn_req_rep_ind_1, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_sn_req_rep_ind_2, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_sn_req_rsv, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
i++;
break;
case PDU_SN_SHORT_DL:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_pdu_sn_short, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
i++;
break;
case PDU_SN_LONG_DL:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_pdu_sn_long, tvb, (offset+i), 2, ENC_BIG_ENDIAN);
i += 2;
break;
default:
break;
}
}
else
{
ti = proto_tree_add_item(sub_tree, hf_mac_header_generic_ext_subheader_type_ul, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
ti_tree = proto_item_add_subtree(ti, ett_mac_ext_subheader_ul_decoder);
i++;
switch (ubyte)
{
case MIMO_MODE_FEEDBACK:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_mimo_mode_fb_type, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_mimo_fb_content, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
i++;
break;
case UL_TX_POWER_REPORT:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_ul_tx_pwr_rep, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
i++;
break;
case MINI_FEEDBACK:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_mini_fb_type, tvb, (offset+i), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_mini_fb_content, tvb, (offset+i), 2, ENC_BIG_ENDIAN);
i += 2;
break;
case PDU_SN_SHORT_UL:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_pdu_sn_short, tvb, (offset+i), 1, ENC_BIG_ENDIAN);
i++;
break;
case PDU_SN_LONG_UL:
proto_tree_add_item(ti_tree, hf_mac_header_generic_ext_subheader_pdu_sn_long, tvb, (offset+i), 2, ENC_BIG_ENDIAN);
i += 2;
break;
default:
break;
}
}
}
return ext_length;
}
static gint arq_feedback_payload_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_item *parent_item)
{
gint length, i;
gint offset;
gint last_ie = 0;
gint ack_type, num_maps, seq_format;
gint word2, word3;
proto_item *ti = NULL;
proto_item *sub_ti = NULL;
proto_tree *sub_tree = NULL;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "ARQ feedback payld");
proto_item_append_text(parent_item, ", ARQ feedback payload");
offset = 0;
length = tvb_reported_length(tvb);
if (!length)
{
proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, length, "Error: ARQ feedback payload tvb is empty ! (%u bytes)", length);
return length;
}
ti = proto_tree_add_protocol_format(tree, proto_mac_header_generic_decoder, tvb, offset, length, "ARQ feedback payload ");
sub_tree = proto_item_add_subtree(ti, ett_mac_arq_fb_payload_decoder);
while (!last_ie)
{
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_cid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
word2 = tvb_get_ntohs(tvb, offset);
last_ie = (word2 & ARQ_FB_IE_LAST_BIT_MASK);
ack_type = ((word2 & ARQ_FB_IE_ACK_TYPE_MASK) >> 13);
num_maps = (word2 & ARQ_FB_IE_NUM_MAPS_MASK) + 1;
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_last, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_ack_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_bsn, tvb, offset, 2, ENC_BIG_ENDIAN);
if (ack_type != 1)
{
sub_ti = proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_num_maps, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_item_append_text(sub_ti, " (%d map(s))", num_maps);
for (i = 0; i < num_maps; i++)
{
if (ack_type != 3)
{
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_sel_ack_map, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else
{
word3 = tvb_get_ntohs(tvb, offset);
seq_format = (word3 & ARQ_FB_IE_SEQ_FORMAT_MASK);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_seq_format, tvb, offset, 2, ENC_BIG_ENDIAN);
if (!seq_format)
{
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_seq_ack_map_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_seq1_length_6, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_seq2_length_6, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_seq_ack_map, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_seq1_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_seq2_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_mac_header_generic_arq_fb_ie_seq3_length, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
offset += 2;
}
}
else
{
proto_tree_add_item(sub_tree, hf_ack_type_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
proto_item_append_text(ti,"(%u bytes)", offset);
return offset;
}
void proto_register_mac_header_generic(void)
{
static hf_register_info hf[] =
{
{
&hf_mac_header_generic_value_bytes,
{
"Values", "wmx.genericValueBytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ht,
{
"MAC Header Type", "wmx.genericHt",
FT_UINT24, BASE_HEX, VALS(ht_msgs), WIMAX_MAC_HEADER_GENERIC_HT,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ec,
{
"MAC Encryption Control", "wmx.genericEc",
FT_UINT24, BASE_HEX, VALS(ec_msgs), WIMAX_MAC_HEADER_GENERIC_EC,
NULL, HFILL
}
},
{
&hf_mac_header_generic_type_0,
{
"MAC Sub-type Bit 0", "wmx.genericType0",
FT_UINT24, BASE_HEX, VALS(type_msg0), WIMAX_MAC_HEADER_GENERIC_TYPE_0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_type_1,
{
"MAC Sub-type Bit 1", "wmx.genericType1",
FT_UINT24, BASE_HEX, VALS(type_msg1), WIMAX_MAC_HEADER_GENERIC_TYPE_1,
NULL, HFILL
}
},
{
&hf_mac_header_generic_type_2,
{
"MAC Sub-type Bit 2", "wmx.genericType2",
FT_UINT24, BASE_HEX, VALS(type_msg2), WIMAX_MAC_HEADER_GENERIC_TYPE_2,
NULL, HFILL
}
},
{
&hf_mac_header_generic_type_3,
{
"MAC Sub-type Bit 3", "wmx.genericType3",
FT_UINT24, BASE_HEX, VALS(type_msg3), WIMAX_MAC_HEADER_GENERIC_TYPE_3,
NULL, HFILL
}
},
{
&hf_mac_header_generic_type_4,
{
"MAC Sub-type Bit 4", "wmx.genericType4",
FT_UINT24, BASE_HEX, VALS(type_msg4), WIMAX_MAC_HEADER_GENERIC_TYPE_4,
NULL, HFILL
}
},
{
&hf_mac_header_generic_type_5,
{
"MAC Sub-type Bit 5", "wmx.genericType5",
FT_UINT24, BASE_HEX, VALS(type_msg5), WIMAX_MAC_HEADER_GENERIC_TYPE_5,
NULL, HFILL
}
},
{
&hf_mac_header_generic_esf,
{
"Extended Sub-header Field", "wmx.genericEsf",
FT_UINT24, BASE_HEX, VALS(esf_msgs), WIMAX_MAC_HEADER_GENERIC_ESF,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ci,
{
"CRC Indicator", "wmx.genericCi",
FT_UINT24, BASE_HEX, VALS(ci_msgs), WIMAX_MAC_HEADER_GENERIC_CI,
NULL, HFILL
}
},
{
&hf_mac_header_generic_eks,
{
"Encryption Key Sequence", "wmx.genericEks",
FT_UINT24, BASE_HEX, NULL, WIMAX_MAC_HEADER_GENERIC_EKS,
NULL, HFILL
}
},
{
&hf_mac_header_generic_rsv,
{
"Reserved", "wmx.genericRsv",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_GENERIC_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_generic_len,
{
"Length", "wmx.genericLen",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_GENERIC_LEN,
NULL, HFILL
}
},
{
&hf_mac_header_generic_cid,
{
"Connection ID", "wmx.genericCid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_hcs,
{
"Header Check Sequence", "wmx.genericHcs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_crc,
{
"CRC", "wmx.genericCrc",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
}
};
static hf_register_info hf_ext[] =
{
{
&hf_mac_header_generic_ext_subheader_rsv,
{
"Reserved", "wmx.genericExtSubhd.Rsv",
FT_UINT8, BASE_DEC, NULL, EXTENDED_SUB_HEADER_RSV_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_type_dl,
{
"DL Extended Subheader Type", "wmx.genericExtSubhd.Dl",
FT_UINT8, BASE_DEC, VALS(dl_ext_sub_header_type), EXTENDED_SUB_HEADER_TYPE_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_type_ul,
{
"UL Extended Subheader Type", "wmx.genericExtSubhd.Ul",
FT_UINT8, BASE_DEC, VALS(ul_ext_sub_header_type), EXTENDED_SUB_HEADER_TYPE_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_sdu_sn,
{
"SDU Sequence Number", "wmx.genericExtSubhd.SduSn",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_dl_sleep_control_pscid,
{
"Power Saving Class ID", "wmx.genericExtSubhd.DlSleepCtrlPSCID",
FT_UINT24, BASE_DEC, NULL, DL_SLEEP_CONTROL_POWER_SAVING_CLASS_ID_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_dl_sleep_control_op,
{
"Operation", "wmx.genericExtSubhd.DlSleepCtrlOP",
FT_UINT24, BASE_HEX, VALS(dl_sleep_control_ops), DL_SLEEP_CONTROL_OPERATION_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_dl_sleep_control_fswe,
{
"Final Sleep Window Exponent", "wmx.genericExtSubhd.DlSleepCtrlFSWE",
FT_UINT24, BASE_DEC, NULL, DL_SLEEP_CONTROL_FINAL_SLEEP_WINDOW_EXPONENT_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_dl_sleep_control_fswb,
{
"Final Sleep Window Base", "wmx.genericExtSubhd.DlSleepCtrlFSWB",
FT_UINT24, BASE_DEC, NULL, DL_SLEEP_CONTROL_FINAL_SLEEP_WINDOW_BASE_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_dl_sleep_control_rsv,
{
"Reserved", "wmx.genericExtSubhd.DlSleepCtrlRsv",
FT_UINT24, BASE_DEC, NULL, DL_SLEEP_CONTROL_RESERVED_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_fb_req_uiuc,
{
"UIUC", "wmx.genericExtSubhd.FbReqUIUC",
FT_UINT24, BASE_HEX, VALS(uiuc_values), FEEDBACK_REQUEST_UIUC_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_fb_req_fb_type,
{
"Feedback Type", "wmx.genericExtSubhd.FbReqFbType",
FT_UINT24, BASE_HEX, VALS(fb_types), FEEDBACK_REQUEST_FEEDBACK_TYPE_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_fb_req_ofdma_symbol_offset,
{
"OFDMA Symbol Offset", "wmx.genericExtSubhd.FbReqOfdmaSymbolOffset",
FT_UINT24, BASE_HEX, NULL, FEEDBACK_REQUEST_OFDMA_SYMBOL_OFFSET_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_fb_req_subchannel_offset,
{
"Subchannel Offset", "wmx.genericExtSubhd.FbReqSubchannelOffset",
FT_UINT24, BASE_HEX, NULL, FEEDBACK_REQUEST_SUBCHANNEL_OFFSET_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_fb_req_slots,
{
"Number of Slots", "wmx.genericExtSubhd.FbReqSlots",
FT_UINT24, BASE_HEX, NULL, FEEDBACK_REQUEST_NUMBER_OF_SLOTS_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_fb_req_frame_offset,
{
"Frame Offset", "wmx.genericExtSubhd.FbReqFrameOffset",
FT_UINT24, BASE_HEX, NULL, FEEDBACK_REQUEST_FRAME_OFFSET_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_sn_req_rep_ind_1,
{
"First SN Report Indication", "wmx.genericExtSubhd.SnReqRepInd1",
FT_UINT8, BASE_DEC, VALS(sn_rep_msg), SN_REQUEST_SUBHEADER_SN_REPORT_INDICATION_1_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_sn_req_rep_ind_2,
{
"Second SN Report Indication", "wmx.genericExtSubhd.SnReqRepInd2",
FT_UINT8, BASE_DEC, VALS(sn_rep_msg), SN_REQUEST_SUBHEADER_SN_REPORT_INDICATION_2_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_sn_req_rsv,
{
"Reserved", "wmx.genericExtSubhd.SnReqRsv",
FT_UINT8, BASE_DEC, NULL, SN_REQUEST_SUBHEADER_RESERVED_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_mimo_mode_fb_type,
{
"Feedback Type", "wmx.genericExtSubhd.MimoFbType",
FT_UINT8, BASE_DEC, VALS(mimo_fb_types), MIMO_FEEDBACK_TYPE_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_mimo_fb_content,
{
"Feedback Content", "wmx.genericExtSubhd.MimoFbContent",
FT_UINT8, BASE_DEC, NULL, MIMO_FEEDBACK_CONTENT_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_ul_tx_pwr_rep,
{
"UL TX Power", "wmx.genericExtSubhd.UlTxPwr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_mini_fb_type,
{
"Feedback Type", "wmx.genericExtSubhd.MiniFbType",
FT_UINT16, BASE_DEC, VALS(fb_types), MINI_FEEDBACK_TYPE_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_mini_fb_content,
{
"Feedback Content", "wmx.genericExtSubhd.MiniFbContent",
FT_UINT16, BASE_DEC, NULL, MINI_FEEDBACK_CONTENT_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_pdu_sn_short,
{
"PDU Sequence Number", "wmx.genericExtSubhd.PduSnShort",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_ext_subheader_pdu_sn_long,
{
"PDU Sequence Number", "wmx.genericExtSubhd.PduSnLong",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
}
};
static hf_register_info hf_mesh[] =
{
{
&hf_mac_header_generic_mesh_subheader,
{
"Xmt Node Id", "wmx.genericMeshSubhd",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
}
};
static hf_register_info hf_frag[] =
{
{
&hf_mac_header_generic_frag_subhd_fc,
{
"Fragment Type", "wmx.genericFragSubhd.Fc",
FT_UINT8, BASE_DEC, VALS(frag_types), FRAGMENTATION_SUBHEADER_FC_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_frag_subhd_fc_ext,
{
"Fragment Type", "wmx.genericFragSubhd.FcExt",
FT_UINT16, BASE_DEC, VALS(frag_types), FRAGMENTATION_SUBHEADER_FC_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_frag_subhd_bsn,
{
"Block Sequence Number (BSN)", "wmx.genericFragSubhd.Bsn",
FT_UINT16, BASE_DEC, NULL, FRAGMENTATION_SUBHEADER_BSN_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_frag_subhd_fsn,
{
"Fragment Sequence Number (FSN)", "wmx.genericFragSubhd.Fsn",
FT_UINT8, BASE_DEC, NULL, FRAGMENTATION_SUBHEADER_FSN_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_frag_subhd_fsn_ext,
{
"Fragment Sequence Number (FSN)", "wmx.genericFragSubhd.FsnExt",
FT_UINT16, BASE_DEC, NULL, FRAGMENTATION_SUBHEADER_BSN_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_frag_subhd_rsv,
{
"Reserved", "wmx.genericFragSubhd.Rsv",
FT_UINT8, BASE_DEC, NULL, FRAGMENTATION_SUBHEADER_RSV_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_frag_subhd_rsv_ext,
{
"Reserved", "wmx.genericFragSubhd.RsvExt",
FT_UINT16, BASE_DEC, NULL, FRAGMENTATION_SUBHEADER_RSV_EXT_MASK,
NULL, HFILL
}
}
};
static hf_register_info hf_pack[] =
{
{
&hf_mac_header_generic_packing_subhd_fc,
{
"Fragment Type", "wmx.genericPackSubhd.Fc",
FT_UINT16, BASE_DEC, VALS(frag_types), PACKING_SUBHEADER_FC_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_packing_subhd_fc_ext,
{
"Fragment Type", "wmx.genericPackSubhd.FcExt",
FT_UINT24, BASE_HEX, VALS(frag_types), PACKING_SUBHEADER_FC_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_packing_subhd_bsn,
{
"First Block Sequence Number", "wmx.genericPackSubhd.Bsn",
FT_UINT24, BASE_DEC, NULL, PACKING_SUBHEADER_BSN_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_packing_subhd_fsn,
{
"Fragment Number", "wmx.genericPackSubhd.Fsn",
FT_UINT16, BASE_DEC, NULL, PACKING_SUBHEADER_FSN_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_packing_subhd_fsn_ext,
{
"Fragment Number", "wmx.genericPackSubhd.FsnExt",
FT_UINT24, BASE_DEC, NULL, PACKING_SUBHEADER_BSN_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_packing_subhd_len,
{
"Length", "wmx.genericPackSubhd.Len",
FT_UINT16, BASE_DEC, NULL, PACKING_SUBHEADER_LENGTH_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_packing_subhd_len_ext,
{
"Length", "wmx.genericPackSubhd.LenExt",
FT_UINT24, BASE_DEC, NULL, PACKING_SUBHEADER_LENGTH_EXT_MASK,
NULL, HFILL
}
}
};
static hf_register_info hf_fast[] =
{
{
&hf_mac_header_generic_fast_fb_subhd_alloc_offset,
{
"Allocation Offset", "wmx.genericFastFbSubhd.AllocOffset",
FT_UINT8, BASE_DEC, NULL, FAST_FEEDBACK_ALLOCATION_OFFSET_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_fast_fb_subhd_fb_type,
{
"Feedback Type", "wmx.genericFastFbSubhd.FbType",
FT_UINT8, BASE_DEC, VALS(fast_fb_types), FAST_FEEDBACK_FEEDBACK_TYPE_MASK,
NULL, HFILL
}
}
};
static hf_register_info hf_grant[] =
{
{
&hf_mac_header_generic_grant_mgmt_ext_pbr_tree,
{
"Scheduling Service Type (Default)",
"wimax.genericGrantSubhd.Default",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_pbr,
{
"PiggyBack Request", "wmx.genericGrantSubhd.Pbr",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_ugs_tree,
{
"Scheduling Service Type (UGS)", "wmx.genericGrantSubhd.UGS",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_ugs_si,
{
"Slip Indicator", "wmx.genericGrantSubhd.Si",
FT_UINT16, BASE_DEC, VALS(si_msgs), GRANT_MGMT_SUBHEADER_UGS_SI_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_ugs_pm,
{
"Poll-Me", "wmx.genericGrantSubhd.Pm",
FT_UINT16, BASE_DEC, VALS(pm_msgs), GRANT_MGMT_SUBHEADER_UGS_PM_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_ugs_fli,
{
"Frame Latency Indication", "wmx.genericGrantSubhd.Fli",
FT_UINT16, BASE_DEC, VALS(fli_msgs), GRANT_MGMT_SUBHEADER_UGS_FLI_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_ugs_fl,
{
"Frame Latency", "wmx.genericGrantSubhd.Fl",
FT_UINT16, BASE_DEC, NULL, GRANT_MGMT_SUBHEADER_UGS_FL_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_ugs_rsv,
{
"Reserved", "wmx.genericGrantSubhd.Rsv",
FT_UINT16, BASE_DEC, NULL, GRANT_MGMT_SUBHEADER_UGS_RSV_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_ext_rtps_tree,
{
"Scheduling Service Type (Extended rtPS)",
"wimax.genericGrantSubhd.ExtendedRTPS",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_ext_pbr,
{
"Extended PiggyBack Request", "wmx.genericGrantSubhd.ExtPbr",
FT_UINT16, BASE_DEC, NULL, GRANT_MGMT_SUBHEADER_EXT_PBR_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_ext_fli,
{
"Frame Latency Indication", "wmx.genericGrantSubhd.ExtFli",
FT_UINT16, BASE_DEC, VALS(fli_msgs), GRANT_MGMT_SUBHEADER_EXT_FLI_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_grant_mgmt_subhd_ext_fl,
{
"Frame Latency", "wmx.genericGrantSubhd.ExtFl",
FT_UINT16, BASE_DEC, NULL, GRANT_MGMT_SUBHEADER_EXT_FL_MASK,
NULL, HFILL
}
}
};
static hf_register_info hf_arq[] =
{
{
&hf_mac_header_generic_arq_fb_ie_cid,
{
"CID", "wmx.genericArq.FbIeCid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_last,
{
"Last IE", "wmx.genericArq.FbIeLast",
FT_UINT16, BASE_DEC, VALS(last_ie_msgs), ARQ_FB_IE_LAST_BIT_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_ack_type,
{
"ACK Type", "wmx.genericArq.FbIeAckType",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_ACK_TYPE_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_bsn,
{
"BSN", "wmx.genericArq.FbIeBsn",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_BSN_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_num_maps,
{
"Number of ACK Maps", "wmx.genericArq.FbIeMaps",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_NUM_MAPS_MASK,
NULL, HFILL
}
},
{
&hf_ack_type_reserved,
{
"Reserved", "wmx.genericArq.FbIeRsvd", FT_UINT16, BASE_DEC, NULL, 0x03, NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_sel_ack_map,
{
"Selective ACK Map", "wmx.genericArq.FbIeSelAckMap",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_seq_format,
{
"Sequence Format", "wmx.genericArq.FbIeSeqFmt",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_SEQ_FORMAT_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_seq_ack_map,
{
"Sequence ACK Map", "wmx.genericArq.FbIeSeqAckMap",
FT_UINT16, BASE_HEX, NULL, ARQ_FB_IE_SEQ_ACK_MAP_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_seq1_length,
{
"Sequence 1 Length", "wmx.genericArq.FbIeSeq1Len",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_SEQ1_LENGTH_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_seq2_length,
{
"Sequence 2 Length", "wmx.genericArq.FbIeSeq2Len",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_SEQ2_LENGTH_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_seq3_length,
{
"Sequence 3 Length", "wmx.genericArq.FbIeSeq3Len",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_SEQ3_LENGTH_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_seq_ack_map_2,
{
"Sequence ACK Map", "wmx.genericArq.FbIeSeqAckMap2",
FT_UINT16, BASE_HEX, NULL, ARQ_FB_IE_SEQ_ACK_MAP_2_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_seq1_length_6,
{
"Sequence 1 Length", "wmx.genericArq.FbIeSeq1Len",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_SEQ1_LENGTH_6_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_seq2_length_6,
{
"Sequence 2 Length", "wmx.genericArq.FbIeSeq2Len",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_SEQ2_LENGTH_6_MASK,
NULL, HFILL
}
},
{
&hf_mac_header_generic_arq_fb_ie_rsv,
{
"Reserved", "wmx.genericArq.FbIeRsv",
FT_UINT16, BASE_DEC, NULL, ARQ_FB_IE_RSV_MASK,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_header_generic_decoder,
&ett_mac_mesh_subheader_decoder,
&ett_mac_frag_subheader_decoder,
&ett_mac_grant_mgmt_subheader_decoder,
&ett_mac_pkt_subheader_decoder,
&ett_mac_fast_fb_subheader_decoder,
&ett_mac_ext_subheader_decoder,
&ett_mac_ext_subheader_dl_decoder,
&ett_mac_ext_subheader_ul_decoder,
&ett_mac_arq_fb_payload_decoder,
&ett_mac_data_pdu_decoder,
};
proto_mac_header_generic_decoder = proto_register_protocol (
"WiMax Generic/Type1/Type2 MAC Header Messages",
"WiMax Generic/Type1/Type2 MAC Header (hdr)",
"wmx.hdr"
);
proto_register_field_array(proto_mac_header_generic_decoder, hf, array_length(hf));
proto_register_field_array(proto_mac_header_generic_decoder, hf_ext, array_length(hf_ext));
proto_register_field_array(proto_mac_header_generic_decoder, hf_mesh, array_length(hf_mesh));
proto_register_field_array(proto_mac_header_generic_decoder, hf_frag, array_length(hf_frag));
proto_register_field_array(proto_mac_header_generic_decoder, hf_pack, array_length(hf_pack));
proto_register_field_array(proto_mac_header_generic_decoder, hf_fast, array_length(hf_fast));
proto_register_field_array(proto_mac_header_generic_decoder, hf_grant, array_length(hf_grant));
proto_register_field_array(proto_mac_header_generic_decoder, hf_arq, array_length(hf_arq));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mac_header_generic_handler", dissect_mac_header_generic_decoder, proto_mac_header_generic_decoder);
proto_register_mac_mgmt_msg();
register_init_routine(wimax_defragment_init);
}
