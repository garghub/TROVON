static void dissect_s5066dts_eow_drc_request(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_eow_drc_request_data_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_drc_request_interleaving, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_drc_request_others, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void dissect_s5066dts_eow_drc_response(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_eow_drc_response_response, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_drc_response_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void dissect_s5066dts_eow_unrec_type(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_eow_unrec_type_response, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_unrec_type_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void dissect_s5066dts_eow_capability(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_eow_capability_adaptive, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_capability_stanag_4529, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_capability_mil_std_188_110a, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_capability_extended, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_capability_full_duplex, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_capability_split_frequency, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_capability_non_arcs_ale, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_capability_arcs, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void dissect_s5066dts_eow_alm_request(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_eow_alm_request_data_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_alm_request_interleaving, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_alm_request_others, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void dissect_s5066dts_eow_alm_response(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_eow_alm_response_response, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_alm_response_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void dissect_s5066dts_eow_hdr_drc_request(tvbuff_t *tvb, packet_info * pinfo, guint offset,
proto_tree *tree, guint pdu_type)
{
if (pdu_type != S5066_DPDU_MANAGEMENT)
{
expert_add_info(pinfo, tree, &ei_s5066dts_eow_hdr_drc_request_invalid);
return;
}
proto_tree_add_item(tree, hf_s5066dts_eow_hdr_drc_request_waveform, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_eow_hdr_drc_request_num_channels, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void dissect_s5066dts_eow_hftrp(tvbuff_t *tvb, packet_info * pinfo, guint offset,
proto_tree *tree, guint pdu_type)
{
if (pdu_type != S5066_DPDU_MANAGEMENT)
{
expert_add_info(pinfo, tree, &ei_s5066dts_eow_hftrp_invalid);
return;
}
proto_tree_add_item(tree, hf_s5066dts_eow_hftrp_hftrp_token, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static guint dissect_s5066dts_eow(tvbuff_t *tvb, packet_info * pinfo, guint offset, proto_tree *tree,
guint pdu_type)
{
proto_tree *eow_tree;
guint eow_type;
eow_type = tvb_get_guint8(tvb, offset) & 0x0F;
eow_tree = proto_tree_add_subtree(tree, tvb, offset, 2, ett_s5066dts_eow, NULL, "EOW Field");
proto_tree_add_item(eow_tree, hf_s5066dts_eow_type, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
switch (eow_type)
{
case S5066_EOW_RESERVED:
proto_tree_add_item(eow_tree, hf_s5066dts_eow_data, tvb, offset, 1, ENC_BIG_ENDIAN); break;
case S5066_EOW_DRC_REQUEST:
dissect_s5066dts_eow_drc_request(tvb, offset, eow_tree); break;
case S5066_EOW_DRC_RESPONSE:
dissect_s5066dts_eow_drc_response(tvb, offset, eow_tree); break;
case S5066_EOW_UNRECOGNIZED_TYPE:
dissect_s5066dts_eow_unrec_type(tvb, offset, eow_tree); break;
case S5066_EOW_CAPABILITY:
dissect_s5066dts_eow_capability(tvb, offset, eow_tree); break;
case S5066_EOW_ALM_REQUEST:
dissect_s5066dts_eow_alm_request(tvb, offset, eow_tree); break;
case S5066_EOW_ALM_RESPONSE:
dissect_s5066dts_eow_alm_response(tvb, offset, eow_tree); break;
case S5066_EOW_HDR_DRC_REQUEST:
dissect_s5066dts_eow_hdr_drc_request(tvb, pinfo, offset, eow_tree, pdu_type); break;
case S5066_EOW_HFTRP_TOKEN:
dissect_s5066dts_eow_hftrp(tvb, pinfo, offset, eow_tree, pdu_type); break;
}
return ++offset;
}
static void
s5066dts_address_format( gchar *result, guint32 address_value )
{
g_snprintf( result, ITEM_LABEL_LENGTH, "%d.%d.%d.%d",
address_value >> 24,
(address_value >> 16) & 0xFF,
(address_value >> 8) & 0xFF,
address_value & 0xFF);
}
static guint dissect_s5066dts_address(tvbuff_t *tvb, guint offset, proto_tree *tree, packet_info *pinfo,
guint addr_size)
{
guint32 source_address = 0, destination_address = 0;
proto_tree *address_tree;
unsigned int i;
for ( i = 0; i < addr_size; i++)
{
destination_address = (destination_address << 4) | ((!(i % 2)
? (tvb_get_guint8(tvb, offset + i / 2) >> 4)
: (tvb_get_guint8(tvb, offset + i / 2))) & 0x0F);
source_address = (source_address << 4) | ((!((i + addr_size) % 2)
? (tvb_get_guint8(tvb, offset + (i + addr_size) / 2) >> 4)
: (tvb_get_guint8(tvb, offset + (i + addr_size) / 2))) & 0x0F);
}
address_tree = proto_tree_add_subtree(tree, tvb, offset, addr_size, ett_s5066dts_address, NULL, "Destination & Source Addresses");
proto_tree_add_uint(address_tree, hf_s5066dts_dest_addr, tvb, offset, addr_size - addr_size / 2, destination_address);
proto_tree_add_uint(address_tree, hf_s5066dts_src_addr, tvb, offset + addr_size / 2, addr_size - addr_size / 2, source_address);
col_add_fstr(pinfo->cinfo, COL_DEF_SRC, "%d.%d.%d.%d",
source_address >> 24,
(source_address >> 16) & 0xFF,
(source_address >> 8) & 0xFF,
source_address & 0xFF);
col_add_fstr(pinfo->cinfo, COL_DEF_DST, "%d.%d.%d.%d",
destination_address >> 24,
(destination_address >> 16) & 0xFF,
(destination_address >> 8) & 0xFF,
destination_address & 0xFF);
offset += addr_size;
return offset;
}
static guint dissect_s5066dts_header_crc(tvbuff_t *tvb, guint offset, proto_tree *tree,
guint address_size, guint header_size)
{
guint16 header_crc;
proto_item *ti;
header_crc = crc16_0x9949_tvb_offset_seed(tvb, S5066_DPDU_SYNC_SEQUENCE_SIZE,
header_size + address_size - S5066_DPDU_SYNC_SEQUENCE_SIZE, 0);
ti = proto_tree_add_item(tree, hf_s5066dts_header_crc, tvb, offset, 2, ENC_BIG_ENDIAN);
if (header_crc == tvb_get_letohs(tvb, offset))
proto_item_append_text(ti, " (Correct)");
else
proto_item_append_text(ti, " (Incorrect, should be %x)", header_crc);
offset += 2;
return offset;
}
static guint dissect_s5066dts_cpdu_crc(tvbuff_t *tvb, guint offset, proto_tree *tree,
guint address_size, guint header_size, guint segmented_cpdu_size)
{
guint32 cpdu_crc;
proto_item *ti;
cpdu_crc = crc32_0x0AA725CF_tvb_offset_seed(tvb, header_size + address_size + S5066_DPDU_SYNC_SEQUENCE_SIZE,
segmented_cpdu_size, 0);
ti = proto_tree_add_item(tree, hf_s5066dts_cpdu_crc, tvb, offset, 4, ENC_BIG_ENDIAN);
if (cpdu_crc == tvb_get_letohl(tvb, offset))
proto_item_append_text(ti, " (Correct)");
else
proto_item_append_text(ti, " (Incorrect, should be %x)", cpdu_crc);
offset +=4;
return offset;
}
static guint dissect_s5066dts_data_only(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_data_only_cpdu_start, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_only_cpdu_end, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_only_deliver_in_order, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_only_drop_cpdu, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_only_tx_win_uwe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_only_tx_win_lwe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_only_segmented_cpdu_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_data_only_transmit_sequence_number, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
return offset;
}
static guint dissect_s5066dts_ack_only(tvbuff_t *tvb, guint offset, proto_tree *tree,
guint header_size)
{
guint ack_size;
ack_size = header_size - 7;
proto_tree_add_item(tree, hf_s5066dts_ack_only_rx_lwe, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
if (ack_size > 0){
proto_tree_add_item(tree, hf_s5066dts_ack_only_acks, tvb, offset, ack_size, ENC_NA); offset += ack_size;
}
return offset;
}
static guint dissect_s5066dts_data_ack(tvbuff_t *tvb, guint offset, proto_tree *tree,
guint header_size)
{
guint ack_size;
ack_size = header_size - 10;
proto_tree_add_item(tree, hf_s5066dts_data_ack_cpdu_start, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_ack_cpdu_end, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_ack_deliver_in_order, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_ack_drop_cpdu, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_ack_tx_win_uwe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_ack_tx_win_lwe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_data_ack_segmented_cpdu_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_data_ack_transmit_sequence_number, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066dts_data_ack_rx_lwe, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
if (ack_size > 0){
proto_tree_add_item(tree, hf_s5066dts_data_ack_acks, tvb, offset, ack_size, ENC_NA); offset += ack_size;
}
return offset;
}
static guint dissect_s5066dts_reset_win_resync(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_reset_win_resync_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_reset_win_resync_full_reset_command, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_reset_win_resync_reset_tx_win_rqst, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_reset_win_resync_reset_rx_win_cmnd, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_reset_win_resync_reset_ack, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066dts_reset_win_resync_new_rx_lwe, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066dts_reset_win_resync_reset_frame_id_number, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
return offset;
}
static guint dissect_s5066dts_exp_data_only(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_exp_data_only_cpdu_start, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_exp_data_only_cpdu_end, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_exp_data_only_cpdu_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_exp_data_only_segmented_cpdu_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_exp_data_only_transmit_sequence_number, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
return offset;
}
static guint dissect_s5066dts_exp_ack_only(tvbuff_t *tvb, guint offset, proto_tree *tree,
guint header_size)
{
guint ack_size;
ack_size = header_size - 7;
proto_tree_add_item(tree, hf_s5066dts_exp_ack_only_rx_lwe, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
if (ack_size > 0)
proto_tree_add_item(tree, hf_s5066dts_exp_ack_only_acks, tvb, offset, ack_size, ENC_NA);
offset += ack_size;
return offset;
}
static guint dissect_s5066dts_management(tvbuff_t *tvb, guint offset, proto_tree *tree, guint header_size)
{
guint8 eow_content;
proto_tree *hftrp_token_tree = NULL;
guint eow_type;
guint extended_message_size;
eow_type = tvb_get_guint8(tvb, offset) & 0x0F;
eow_content = tvb_get_guint8(tvb, S5066_DPDU_EOW_CONTENT_INDEX);
extended_message_size = header_size - 8;
proto_tree_add_item(tree, hf_s5066dts_management_unused, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_management_extended_message_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_management_message, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_management_ack, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066dts_management_management_frame_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (eow_type == S5066_EOW_HDR_DRC_REQUEST)
{
proto_tree_add_item(tree, hf_s5066dts_eow_hdr_drc_request_data_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s5066dts_eow_hdr_drc_request_interleaver_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else if (extended_message_size > 0)
{
if (eow_type == S5066_EOW_HFTRP_TOKEN)
{
hftrp_token_tree = proto_tree_add_subtree_format(tree, tvb, offset, extended_message_size,
ett_s5066dts_hftrp_token, NULL, "HFTRP Token (%s)",
val_to_str_const(eow_content, s5066dts_eow_hftrp_frame_control, "UNKNOWN_HFTRP_TOKEN"));
proto_tree_add_item(hftrp_token_tree,
hf_s5066dts_management_extended_message_hftrp_payload_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(hftrp_token_tree,
hf_s5066dts_management_extended_message_hftrp_ra, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(hftrp_token_tree,
hf_s5066dts_management_extended_message_hftrp_seq_id, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(hftrp_token_tree,
hf_s5066dts_management_extended_message_hftrp_gen_seq_id, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(hftrp_token_tree,
hf_s5066dts_management_extended_message_hftrp_new_successor_id, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(hftrp_token_tree,
hf_s5066dts_management_extended_message_hftrp_number_of_nodes, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
}
else
{
proto_tree_add_item(tree, hf_s5066dts_management_extended_message, tvb, offset, extended_message_size, ENC_NA);
offset += extended_message_size;
}
}
return offset;
}
static guint dissect_s5066dts_non_arq_data(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_non_arq_data_cpdu_id_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_non_arq_data_deliver_in_order, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_non_arq_data_group_address, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_non_arq_data_segmented_cpdu_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_non_arq_data_cpdu_id_2, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066dts_non_arq_data_cpdu_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_non_arq_data_cpdu_segment_offset, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_non_arq_data_cpdu_reception_window, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
return offset;
}
static guint dissect_s5066dts_exp_non_arq_data(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_exp_non_arq_data_cpdu_id_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_exp_non_arq_data_deliver_in_order, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_exp_non_arq_data_group_address, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_exp_non_arq_data_segmented_cpdu_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_exp_non_arq_data_cpdu_id_2, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(tree, hf_s5066dts_exp_non_arq_data_cpdu_size, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_exp_non_arq_data_cpdu_segment_offset, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
proto_tree_add_item(tree, hf_s5066dts_exp_non_arq_data_cpdu_reception_window, tvb, offset, 2, ENC_BIG_ENDIAN); offset +=2;
return offset;
}
static guint dissect_s5066dts_warning(tvbuff_t *tvb, guint offset, proto_tree *tree)
{
proto_tree_add_item(tree, hf_s5066dts_warning_frame_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s5066dts_warning_reason, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
return offset;
}
static guint calculate_s5066dts_dpdu_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset _U_, void *data _U_)
{
guint pdu_type;
guint address_size;
guint header_size;
guint pdu_size;
guint segmented_cpdu_size;
if (tvb_get_guint8(tvb, 0) != 0x90)
return 1;
else if (tvb_get_guint8(tvb, 1) != 0xEB)
return 2;
pdu_type = (tvb_get_guint8(tvb, 2) & 0xF0) >> 4;
address_size = (tvb_get_guint8(tvb, S5066_DPDU_SIZE_OF_ADDRESS_INDEX) & 0xE0) >> 5;
header_size = tvb_get_guint8(tvb, S5066_DPDU_SIZE_OF_HEADER_INDEX) & 0x1F;
pdu_size = header_size + address_size + S5066_DPDU_SYNC_SEQUENCE_SIZE;
if (pdu_type == S5066_DPDU_DATA_ONLY || pdu_type == S5066_DPDU_DATA_ACK ||
pdu_type == S5066_DPDU_EXP_DATA_ONLY || pdu_type == S5066_DPDU_NON_ARQ_DATA ||
pdu_type == S5066_DPDU_EXP_NON_ARQ_DATA)
{
segmented_cpdu_size = tvb_get_ntohs(tvb, 6 + address_size) & 0x03FF;
pdu_size += segmented_cpdu_size + 4;
}
return pdu_size;
}
static int dissect_s5066dts(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *s5066dts_tree = NULL, *pdu_tree = NULL;
proto_item *ti = NULL;
guint offset = 0;
guint pdu_type;
guint address_size;
guint header_size;
guint segmented_cpdu_size;
guint8 eow_type;
guint8 eow_content;
if (tvb_get_guint8(tvb, 0) != 0x90 || tvb_get_guint8(tvb, 1) != 0xEB) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, DISSECTOR_NAME);
pdu_type = (tvb_get_guint8(tvb, 2) & 0xF0) >> 4;
col_add_fstr(pinfo->cinfo, COL_INFO, "DpduType=%d (%s)", pdu_type, val_to_str(pdu_type, s5066dts_dpdu_type,
"Unknown (0x%02x)"));
address_size = (tvb_get_guint8(tvb, S5066_DPDU_SIZE_OF_ADDRESS_INDEX) & 0xE0) >> 5;
eow_type = tvb_get_guint8(tvb, S5066_DPDU_EOW_TYPE_INDEX) & 0x0F;
eow_content = tvb_get_guint8(tvb, S5066_DPDU_EOW_CONTENT_INDEX);
switch (eow_type)
{
case S5066_EOW_RESERVED:
col_append_fstr(pinfo->cinfo, COL_INFO, " EowType=RESERVED");
break;
case S5066_EOW_DRC_REQUEST:
case S5066_EOW_DRC_RESPONSE:
case S5066_EOW_UNRECOGNIZED_TYPE:
case S5066_EOW_CAPABILITY:
case S5066_EOW_ALM_REQUEST:
case S5066_EOW_ALM_RESPONSE:
case S5066_EOW_HDR_DRC_REQUEST:
col_append_fstr(pinfo->cinfo, COL_INFO, " EowType=%d (%s)", eow_type,
val_to_str_const(eow_type, s5066dts_eow_type, "UNKNOWN_EOW_TYPE"));
break;
case 8:
case 9:
case 10:
case 11:
case 12:
case 13:
case 14:
col_append_fstr(pinfo->cinfo, COL_INFO, " EowType=UNSPECIFIED");
break;
case S5066_EOW_HFTRP_TOKEN:
col_append_fstr(pinfo->cinfo, COL_INFO, " EowType=%d (%s:%s)", eow_type,
val_to_str_const(eow_type, s5066dts_eow_type, "UNKNOWN_EOW_TYPE"),
val_to_str_const(eow_content, s5066dts_eow_hftrp_frame_control_abbr, "UNKNOWN_HFTRP_TOKEN"));
break;
}
col_append_fstr(pinfo->cinfo, COL_INFO, " EOT=%d", tvb_get_guint8(tvb, S5066_DPDU_EOT_INDEX));
switch (pdu_type)
{
case S5066_DPDU_DATA_ONLY:
case S5066_DPDU_EXP_DATA_ONLY:
col_append_fstr(pinfo->cinfo, COL_INFO, " Seq=%d", tvb_get_guint8(tvb, 8 + address_size));
break;
case S5066_DPDU_ACK_ONLY:
case S5066_DPDU_EXP_ACK_ONLY:
col_append_fstr(pinfo->cinfo, COL_INFO, " RxLWE=%d", tvb_get_guint8(tvb, 6 + address_size));
break;
case S5066_DPDU_DATA_ACK:
col_append_fstr(pinfo->cinfo, COL_INFO, " Seq=%d RxLWE=%d",
tvb_get_guint8(tvb, 8 + address_size),
tvb_get_guint8(tvb, 9 + address_size));
break;
case S5066_DPDU_MANAGEMENT:
col_append_fstr(pinfo->cinfo, COL_INFO, " FrameID=%d", tvb_get_guint8(tvb, 7 + address_size));
break;
}
if (tree)
{
ti = proto_tree_add_protocol_format(tree, proto_s5066dts, tvb, 0, -1, "STANAG 5066 (DTS Layer)");
s5066dts_tree = proto_item_add_subtree(ti, ett_s5066dts);
proto_tree_add_item(s5066dts_tree, hf_s5066dts_sync_word, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(s5066dts_tree, hf_s5066dts_dpdu_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset = dissect_s5066dts_eow(tvb, pinfo, offset, s5066dts_tree, pdu_type);
proto_item_append_text(ti, ", DPDU Type %s ", val_to_str_const(pdu_type, s5066dts_dpdu_type, "UNKNOWN_DPDU_TYPE"));
proto_tree_add_item(s5066dts_tree, hf_s5066dts_eot, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
proto_tree_add_item(s5066dts_tree, hf_s5066dts_address_size, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(s5066dts_tree, hf_s5066dts_header_size, tvb, offset, 1, ENC_BIG_ENDIAN); offset++;
offset = dissect_s5066dts_address(tvb, offset, s5066dts_tree, pinfo, address_size);
header_size = tvb_get_guint8(tvb, S5066_DPDU_SIZE_OF_HEADER_INDEX) & 0x1F;
pdu_tree = proto_tree_add_subtree(s5066dts_tree, tvb, offset, header_size - 6, ett_s5066dts_pdu, NULL, "D_PDU Type Specific Header");
switch (pdu_type)
{
case S5066_DPDU_DATA_ONLY: offset = dissect_s5066dts_data_only(tvb, offset, pdu_tree); break;
case S5066_DPDU_ACK_ONLY: offset = dissect_s5066dts_ack_only(tvb, offset, pdu_tree, header_size); break;
case S5066_DPDU_DATA_ACK: offset = dissect_s5066dts_data_ack(tvb, offset, pdu_tree, header_size); break;
case S5066_DPDU_RESET_WIN_RESYNC: offset = dissect_s5066dts_reset_win_resync(tvb, offset, pdu_tree); break;
case S5066_DPDU_EXP_DATA_ONLY: offset = dissect_s5066dts_exp_data_only(tvb, offset, pdu_tree); break;
case S5066_DPDU_EXP_ACK_ONLY: offset = dissect_s5066dts_exp_ack_only(tvb, offset, pdu_tree, header_size); break;
case S5066_DPDU_MANAGEMENT: offset = dissect_s5066dts_management(tvb, offset, pdu_tree, header_size); break;
case S5066_DPDU_NON_ARQ_DATA: offset = dissect_s5066dts_non_arq_data(tvb, offset, pdu_tree); break;
case S5066_DPDU_EXP_NON_ARQ_DATA: offset = dissect_s5066dts_exp_non_arq_data(tvb, offset, pdu_tree); break;
case S5066_DPDU_WARNING: offset = dissect_s5066dts_warning(tvb, offset, pdu_tree); break;
}
offset = dissect_s5066dts_header_crc(tvb, offset, s5066dts_tree, address_size, header_size);
if (pdu_type == S5066_DPDU_DATA_ONLY || pdu_type == S5066_DPDU_DATA_ACK
|| pdu_type == S5066_DPDU_EXP_DATA_ONLY || pdu_type == S5066_DPDU_NON_ARQ_DATA
|| pdu_type == S5066_DPDU_EXP_NON_ARQ_DATA)
{
segmented_cpdu_size = tvb_get_ntohs(tvb, 6 + address_size) & 0x03FF;
proto_tree_add_item(s5066dts_tree, hf_s5066dts_segmented_cpdu, tvb, offset, segmented_cpdu_size, ENC_NA);
offset += segmented_cpdu_size;
dissect_s5066dts_cpdu_crc(tvb, offset, s5066dts_tree, address_size, header_size, segmented_cpdu_size);
}
}
return tvb_captured_length(tvb);
}
static int dissect_s5066dts_raw(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint b_length = tvb_captured_length(tvb);
if ( b_length < S5066_DPDU_FRAME_HEADER_LEN){
return 0;
}
if ((tvb_get_guint8(tvb, 0) != 0x90) || (tvb_get_guint8(tvb, 1) != 0xEB)) {
return 0;
}
calculate_s5066dts_dpdu_len(pinfo, tvb, 0, NULL);
dissect_s5066dts(tvb, pinfo, tree, NULL);
return b_length;
}
static int dissect_s5066dts_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint b_length = tvb_captured_length(tvb);
if ( b_length < S5066_DPDU_FRAME_HEADER_LEN){
return 0;
}
if ((tvb_get_guint8(tvb, 0) != 0x90) || (tvb_get_guint8(tvb, 1) != 0xEB)) {
return 0;
}
if ( pinfo->destport != config_s5066dts_port) {
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, config_proto_desegment, S5066_DPDU_FRAME_HEADER_LEN, calculate_s5066dts_dpdu_len,
dissect_s5066dts, data);
return b_length;
}
void proto_register_s5066dts (void)
{
module_t *s5066dts_module;
static hf_register_info hf[] = {
{ &hf_s5066dts_sync_word,
{ "Sync preamble", "s5066dts.sync", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_dpdu_type,
{ "D_PDU type", "s5066dts.type", FT_UINT8, BASE_DEC, VALS(s5066dts_dpdu_type), 0xF0, NULL, HFILL }
},
{ &hf_s5066dts_eow_type,
{ "EOW type", "s5066dts.eow.type", FT_UINT8, BASE_DEC, VALS(s5066dts_eow_type), 0x0F, NULL, HFILL }
},
{ &hf_s5066dts_eow_data,
{ "EOW data", "s5066dts.eow.data", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_eot,
{ "EOT", "s5066dts.eot", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_address_size,
{ "Address size (1/2 bytes)", "s5066dts.address.size", FT_UINT8, BASE_DEC, NULL, 0xE0, NULL, HFILL }
},
{ &hf_s5066dts_header_size,
{ "Header size", "s5066dts.header_size", FT_UINT8, BASE_DEC, NULL, 0x1F, NULL, HFILL }
},
{ &hf_s5066dts_segmented_cpdu,
{ "C_PDU Segment", "s5066dts.segmented_cpdu", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_dest_addr,
{ "Destination Address", "s5066dts.dest_addr", FT_UINT32, BASE_CUSTOM, CF_FUNC(s5066dts_address_format), 0x0, NULL, HFILL }
},
{ &hf_s5066dts_src_addr,
{ "Source Address", "s5066dts.src_addr", FT_UINT32, BASE_CUSTOM, CF_FUNC(s5066dts_address_format), 0x0, NULL, HFILL }
},
{ &hf_s5066dts_header_crc,
{ "CRC on header", "s5066dts.header_crc", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_cpdu_crc,
{ "CRC on C_PDU segment", "s5066dts.cpdu_crc", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_eow_drc_request_data_rate,
{ "Data Rate", "s5066dts.eow.drc_request.data_rate", FT_UINT8, BASE_DEC, VALS(s5066dts_eow_data_rate),
0xF0, NULL, HFILL }
},
{ &hf_s5066dts_eow_drc_request_interleaving,
{ "Interleaver parameter", "s5066dts.eow.drc_request.interleaving", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_interleaving), 0x0C, NULL, HFILL }
},
{ &hf_s5066dts_eow_drc_request_others,
{ "Other parameters", "s5066dts.eow.drc_request.others", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_others), 0x03, NULL, HFILL }
},
{ &hf_s5066dts_eow_drc_response_response,
{ "Response for DRC", "s5066dts.eow.drc_response.response", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_response), 0xE0, NULL, HFILL }
},
{ &hf_s5066dts_eow_drc_response_reason,
{ "Reason", "s5066dts.eow.drc_response.reason", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_reason), 0x1F, NULL, HFILL }
},
{ &hf_s5066dts_eow_unrec_type_response,
{ "This value should be set to 0", "s5066dts.eow.unrec_type.response", FT_UINT8, BASE_DEC,
NULL, 0xE0, NULL, HFILL }
},
{ &hf_s5066dts_eow_unrec_type_reason,
{ "Reason", "s5066dts.eow.unrec_type.reason", FT_UINT8, BASE_DEC, NULL, 0x1F, NULL, HFILL }
},
{ &hf_s5066dts_eow_capability_adaptive,
{ "Adaptive modem parameters capable", "s5066dts.eow.capability.adaptive", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }
},
{ &hf_s5066dts_eow_capability_stanag_4529,
{ "STANAG 4529 available", "s5066dts.eow.capability.stanag_4529", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }
},
{ &hf_s5066dts_eow_capability_mil_std_188_110a,
{ "MIL-STD-188-110A available", "s5066dts.eow.capability.mil_std_188_110a", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }
},
{ &hf_s5066dts_eow_capability_extended,
{ "Extended data rate available", "s5066dts.eow.capability.extended", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_s5066dts_eow_capability_full_duplex,
{ "Full duplex supported", "s5066dts.eow.capability.full_duplex", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_s5066dts_eow_capability_split_frequency,
{ "Split frequency supported", "s5066dts.eow.capability.split_frequency", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_s5066dts_eow_capability_non_arcs_ale,
{ "Non-ARCS ALE capable", "s5066dts.eow.capability.non_arcs_ale", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }
},
{ &hf_s5066dts_eow_capability_arcs,
{ "ARCS capable", "s5066dts.eow.capability.arcs", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }
},
{ &hf_s5066dts_eow_alm_request_data_rate,
{ "Data Rate", "s5066dts.eow.alm_request.data_rate", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_data_rate), 0xF0, NULL, HFILL }
},
{ &hf_s5066dts_eow_alm_request_interleaving,
{ "Interleaver parameter", "s5066dts.eow.alm_request.interleaving", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_interleaving), 0x0C, NULL, HFILL }
},
{ &hf_s5066dts_eow_alm_request_others,
{ "Other parameters", "s5066dts.eow.alm_request.others", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_others), 0x03, NULL, HFILL }
},
{ &hf_s5066dts_eow_alm_response_response,
{ "Response for DRC", "s5066dts.eow.alm_response.response", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_response), 0xE0, NULL, HFILL }
},
{ &hf_s5066dts_eow_alm_response_reason,
{ "Reason", "s5066dts.eow.alm_response.reason", FT_UINT8, BASE_DEC, VALS(s5066dts_alm_reason), 0x1F, NULL, HFILL }
},
{ &hf_s5066dts_eow_hdr_drc_request_waveform,
{ "Modem waveform", "s5066dts.eow.hdr_drc_request.waveform", FT_UINT8, BASE_DEC,
VALS(s5066dts_eow_waveform), 0xF8, NULL, HFILL }
},
{ &hf_s5066dts_eow_hdr_drc_request_num_channels,
{ "Number of channels", "s5066dts.eow.hdr_drc_request.num_channels", FT_UINT8, BASE_DEC, NULL, 0x07, NULL, HFILL }
},
{ &hf_s5066dts_eow_hdr_drc_request_data_rate,
{ "Requested data rate for each channel", "s5066dts.eow.hdr_drc_request.data_rate",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_eow_hdr_drc_request_interleaver_length,
{ "Interleaver length for each channel", "s5066dts.eow.hdr_drc_request.interleaver_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_eow_hftrp_hftrp_token,
{ "HFTRP Token Type", "s5066dts.eow.hftrp.token_type", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_s5066dts_data_only_cpdu_start,
{ "C_PDU Start", "s5066dts.data_only.cpdu_start", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }
},
{ &hf_s5066dts_data_only_cpdu_end,
{ "C_PDU End", "s5066dts.data_only.cpdu_end", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }
},
{ &hf_s5066dts_data_only_deliver_in_order,
{ "C_PDU Deliver-in-Order", "s5066dts.data_only.deliver_in_order", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }
},
{ &hf_s5066dts_data_only_drop_cpdu,
{ "Drop C_PDU", "s5066dts.data_only.drop_cpdu", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_s5066dts_data_only_tx_win_uwe,
{ "TX WIN UWE", "s5066dts.data_only.tx_win_uwe", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_s5066dts_data_only_tx_win_lwe,
{ "TX WIN LWE", "s5066dts.data_only.tx_win_lwe", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_s5066dts_data_only_segmented_cpdu_size,
{ "Size of segmented C_PDU", "s5066dts.data_only.segmented_cpdu_size", FT_UINT16, BASE_DEC,
NULL, 0x03FF, NULL, HFILL }
},
{ &hf_s5066dts_data_only_transmit_sequence_number,
{ "TX Frame Sequence Number", "s5066dts.data_only.transmit_sequence_number", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_ack_only_rx_lwe,
{ "RX LWE", "s5066dts.ack_only.rx_lwe", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_ack_only_acks,
{ "Selective ACK", "s5066dts.ack_only.acks", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_cpdu_start,
{ "C_PDU Start", "s5066dts.data_ack.cpdu_start", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_cpdu_end,
{ "C_PDU End", "s5066dts.data_ack.cpdu_end", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_deliver_in_order,
{ "C_PDU Deliver-in-Order", "s5066dts.data_ack.deliver_in_order", FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_drop_cpdu,
{ "Drop C_PDU", "s5066dts.data_ack.drop_cpdu", FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_tx_win_uwe,
{ "TX WIN UWE", "s5066dts.data_ack.tx_win_uwe", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_tx_win_lwe,
{ "TX WIN LWE", "s5066dts.data_ack.tx_win_lwe", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_segmented_cpdu_size,
{ "Size of segmented C_PDU", "s5066dts.data_ack.segmented_cpdu_size", FT_UINT16, BASE_DEC,
NULL, 0x03FF, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_transmit_sequence_number,
{ "TX frame sequence number", "s5066dts.data_ack.transmit_sequence_number", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_rx_lwe,
{ "RX LWE", "s5066dts.data_ack.rx_lwe", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_data_ack_acks,
{ "Selective ACK", "s5066dts.data_ack.acks", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_reset_win_resync_unused,
{ "Unused", "s5066dts.reset_win_resync.unused", FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066dts_reset_win_resync_full_reset_command,
{ "Full reset command", "s5066dts.reset_win_resync.full_reset", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_s5066dts_reset_win_resync_reset_tx_win_rqst,
{ "Reset TX-WIN request", "s5066dts.reset_win_resync.reset_tx_win", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_s5066dts_reset_win_resync_reset_rx_win_cmnd,
{ "Reset RX-WIN command", "s5066dts.reset_win_resync.reset_rx_win", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }
},
{ &hf_s5066dts_reset_win_resync_reset_ack,
{ "Reset acknowledgment", "s5066dts.reset_win_resync.reset_ack", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }
},
{ &hf_s5066dts_reset_win_resync_new_rx_lwe,
{ "New receiver ARQ RX-LWE", "s5066dts.reset_win_resync.new_rx_lwe", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_reset_win_resync_reset_frame_id_number,
{ "Reset frame ID number", "s5066dts.reset_win_resync.reset_frame_id", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_exp_data_only_cpdu_start,
{ "C_PDU Start", "s5066dts.exp_data_only.cpdu_start", FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }
},
{ &hf_s5066dts_exp_data_only_cpdu_end,
{ "C_PDU End", "s5066dts.exp_data_only.cpdu_end", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }
},
{ &hf_s5066dts_exp_data_only_cpdu_id,
{ "Segmented C_PDU ID", "s5066dts.exp_data_only.cpdu_id", FT_UINT8, BASE_DEC, NULL, 0x3C, NULL, HFILL }
},
{ &hf_s5066dts_exp_data_only_segmented_cpdu_size,
{ "Size of segmented C_PDU", "s5066dts.exp_data_only.segmented_cpdu_size", FT_UINT16, BASE_DEC, NULL, 0x03FF, NULL, HFILL }
},
{ &hf_s5066dts_exp_data_only_transmit_sequence_number,
{ "TX frame sequence number", "s5066dts.exp_data_only.transmit_sequence_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_exp_ack_only_rx_lwe,
{ "RX LWE", "s5066dts.exp_ack_only.rx_lwe", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_exp_ack_only_acks,
{ "Selective ACK", "s5066dts.exp_ack_only.acks", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_management_unused,
{ "Unused", "s5066dts.management.unused", FT_UINT8, BASE_HEX, NULL, 0xF8, NULL, HFILL }
},
{ &hf_s5066dts_management_extended_message_flag,
{ "Extended message flag", "s5066dts.management.extended_message_flag", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_s5066dts_management_message,
{ "Valid message", "s5066dts.management.message", FT_BOOLEAN, 8, NULL, 0x02, NULL, HFILL }
},
{ &hf_s5066dts_management_ack,
{ "Acknowledgment", "s5066dts.management.ack", FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }
},
{ &hf_s5066dts_management_management_frame_id,
{ "Management frame ID number", "s5066dts.management.manegement_frame_id", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_management_extended_message,
{ "Extended management message", "s5066dts.management.extended_message", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_management_extended_message_hftrp_payload_size,
{ "Payload Size", "s5066dts.management.extended_message.reserved", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_management_extended_message_hftrp_ra,
{ "Ring Address", "s5066dts.management.extended_message.ring_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_management_extended_message_hftrp_seq_id,
{ "Sequence ID", "s5066dts.management.extended_message.sequence_id", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_management_extended_message_hftrp_gen_seq_id,
{ "Generation Sequence ID", "s5066dts.management.extended_message.generation_sequence_id",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_management_extended_message_hftrp_new_successor_id,
{ "New Successor ID", "s5066dts.management.extended_message.new_successor_id", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_management_extended_message_hftrp_number_of_nodes,
{ "Number of Nodes", "s5066dts.management.extended_message.number_of_nodes", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_non_arq_data_cpdu_id_1,
{ "C_PDU ID number (field 1)", "s5066dts.non_arq_data.cpdu_id_1", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066dts_non_arq_data_deliver_in_order,
{ "C_PDU Deliver-in-Order", "s5066dts.non_arq_data.deliver_in_order", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_s5066dts_non_arq_data_group_address,
{ "Group Address", "s5066dts.non_arq_data.group_address", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_s5066dts_non_arq_data_cpdu_id_2,
{ "C_PDU ID number (field 2)", "s5066dts.non_arq_data.cpdu_id_2", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_non_arq_data_cpdu_size,
{ "C_PDU size", "s5066dts.non_arq_data.cpdu_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_non_arq_data_cpdu_segment_offset,
{ "Offset of segmented C_PDU", "s5066dts.non_arq_data.cpdu_segment_offset", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_non_arq_data_cpdu_reception_window,
{ "C_PDU reception window", "s5066dts.non_arq_data.cpdu_reception_window", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_non_arq_data_segmented_cpdu_size,
{ "Size of segmented C_PDU", "s5066dts.non_arq_data.segmented_cpdu_size", FT_UINT16, BASE_DEC,
NULL, 0x03FF, NULL, HFILL }
},
{ &hf_s5066dts_exp_non_arq_data_cpdu_id_1,
{ "C_PDU ID number (field 1)", "s5066dts.exp_non_arq_data.cpdu_id_1", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066dts_exp_non_arq_data_deliver_in_order,
{ "C_PDU Deliver-in-Order", "s5066dts.exp_non_arq_data.deliver_in_order", FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_s5066dts_exp_non_arq_data_group_address,
{ "Group Address", "s5066dts.exp_non_arq_data.group_address", FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_s5066dts_exp_non_arq_data_cpdu_id_2,
{ "C_PDU ID number (field 2)", "s5066dts.exp_non_arq_data.cpdu_id_2", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_exp_non_arq_data_cpdu_size,
{ "C_PDU size", "s5066dts.exp_non_arq_data.cpdu_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_exp_non_arq_data_cpdu_segment_offset,
{ "Offset of segmented C_PDU", "s5066dts.exp_non_arq_data.cpdu_segment_offset", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_exp_non_arq_data_cpdu_reception_window,
{ "C_PDU reception window", "s5066dts.exp_non_arq_data.cpdu_reception_window", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_s5066dts_exp_non_arq_data_segmented_cpdu_size,
{ "Size of segmented C_PDU", "s5066dts.exp_non_arq_data.segmented_cpdu_size", FT_UINT16, BASE_DEC,
NULL, 0x03FF, NULL, HFILL }
},
{ &hf_s5066dts_warning_frame_type,
{ "Received frame type", "s5066dts.warning.frame_type", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }
},
{ &hf_s5066dts_warning_reason,
{ "Reason warning sent", "s5066dts.warning.reason", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_s5066dts,
&ett_s5066dts_eow,
&ett_s5066dts_address,
&ett_s5066dts_pdu,
&ett_s5066dts_hftrp_token,
};
static ei_register_info ei[] = {
{ &ei_s5066dts_eow_hdr_drc_request_invalid, { "s5066dts.eow_hdr_drc_request.invalid", PI_MALFORMED, PI_ERROR,
"High data rate change request can only be made in Management D_PDU", EXPFILL }},
{ &ei_s5066dts_eow_hftrp_invalid, { "s5066dts.eow_hftrp.invalid", PI_MALFORMED, PI_ERROR,
"HFTRP tokens can only be carried with Management D_PDU", EXPFILL }},
};
expert_module_t* expert_s5066dts;
if (proto_s5066dts == -1)
{
proto_s5066dts = proto_register_protocol ("STANAG 5066(DTS layer)", "STANAG 5066 DTS", "s5066dts");
proto_register_field_array(proto_s5066dts, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_s5066dts = expert_register_protocol(proto_s5066dts);
expert_register_field_array(expert_s5066dts, ei, array_length(ei));
register_dissector(DISSECTOR_NAME, dissect_s5066dts_tcp, proto_s5066dts);
}
s5066dts_module = prefs_register_protocol(proto_s5066dts, proto_reg_handoff_s5066dts);
prefs_register_bool_preference(s5066dts_module, "proto_desegment",
"Reassemble STANAG 5066 DPDUs spanning multiple TCP segments",
"Whether the STANAG 5066 DTS Layer dissector should reassemble DPDUs spanning multiple TCP segments",
&config_proto_desegment);
prefs_register_uint_preference(s5066dts_module, "tcp.port",
"STANAG 5066 DTS Layer TCP Port",
"Set the port for STANAG 5066 DTS Layer. (If other than the default 5067.)",
10, &config_s5066dts_port);
}
void proto_reg_handoff_s5066dts(void)
{
static gint initialized = FALSE;
static dissector_handle_t s5066dts_handle;
static dissector_handle_t s5066dts_over_tcp_handle;
static int currentPort;
if (!initialized) {
s5066dts_handle = create_dissector_handle(dissect_s5066dts_raw, proto_s5066dts);
dissector_add_uint("wtap_encap", WTAP_ENCAP_STANAG_5066_D_PDU, s5066dts_handle);
s5066dts_over_tcp_handle = create_dissector_handle(dissect_s5066dts_tcp, proto_s5066dts);
initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", currentPort, s5066dts_over_tcp_handle);
}
currentPort = config_s5066dts_port;
dissector_add_uint("tcp.port", currentPort, s5066dts_over_tcp_handle);
}
