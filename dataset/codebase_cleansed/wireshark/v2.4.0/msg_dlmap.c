gint RCID_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb, gint RCID_Type_lcl)
{
gint bit = offset;
proto_item *ti = NULL;
proto_tree *tree = NULL;
gint Prefix = 0;
gint cid = 0;
if (RCID_Type_lcl == 0)
length = 16;
else {
Prefix = TVB_BIT_BIT(bit, tvb);
if (Prefix == 1) length = 12;
else if (RCID_Type_lcl == 1) length = 12;
else if (RCID_Type_lcl == 2) length = 8;
else if (RCID_Type_lcl == 3) length = 4;
}
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, length), ett_286j, &ti, "RCID_IE");
if (RCID_Type_lcl == 0) {
XBIT_HF_VALUE(cid, 16, hf_dlmap_rcid_ie_cid);
} else {
XBIT_HF_VALUE(Prefix, 1, hf_dlmap_rcid_ie_prefix);
if (Prefix == 1) {
XBIT_HF_VALUE(cid, 11, hf_dlmap_rcid_ie_cid11);
} else {
if (RCID_Type_lcl == 1) {
XBIT_HF_VALUE(cid, 11, hf_dlmap_rcid_ie_cid11);
} else if (RCID_Type_lcl == 2) {
XBIT_HF_VALUE(cid, 7, hf_dlmap_rcid_ie_cid7);
} else if (RCID_Type_lcl == 3) {
XBIT_HF_VALUE(cid, 3, hf_dlmap_rcid_ie_cid3);
}
}
}
proto_item_append_text(ti, " (CID = %d)", cid);
return length;
}
static gint Dedicated_DL_Control_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint nibble;
proto_tree *tree;
gint len;
nib = offset;
length = TVB_NIB_NIBBLE(nib, tvb);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(nib, length+1), ett_286i, NULL, "Dedicated_DL_Control_IE");
VNIB(length, 1, hf_dlmap_dedicated_dl_control_length);
VNIB(nibble, 1, hf_dlmap_dedicated_dl_control_control_header);
if ((nibble & 1) == 1) {
nibble = TVB_NIB_NIBBLE(nib, tvb);
proto_tree_add_uint(tree, hf_dlmap_dedicated_dl_control_num_sdma_layers, tvb, NIBHI(nib,1), (nibble >> 2) & 0x3);
if ((nib*4)+2 < (offset+length)*4) {
len = ((offset + length - nib) * 4) - 2;
proto_tree_add_bytes_format(tree, hf_reserved, tvb, BITHI(nib*4, len), NULL, "Reserved bits");
}
} else {
if (nib < offset+length) {
len = (offset + length) - nib;
proto_tree_add_bytes_format(tree, hf_reserved, tvb, NIBHI(nib,len), NULL, "Reserved bits");
}
}
return (length + 1);
}
static gint Dedicated_MIMO_DL_Control_IE(proto_tree *diuc_tree, gint offset, gint length _U_, tvbuff_t *tvb)
{
gint bit;
proto_tree *tree;
gint mci, cqi, cmi, matrix = 0, pad, CQICH_num, mimo_mode;
gint j;
bit = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, 1), ett_286t, NULL, "Dedicated MIMO DL Control IE");
XBIT_HF_VALUE(length, 5, hf_dlmap_dedicated_mimo_dl_control_length);
XBIT_HF_VALUE(mci, 1, hf_dlmap_dedicated_mimo_dl_control_control_header_mimo_control_info);
XBIT_HF_VALUE(cqi, 1, hf_dlmap_dedicated_mimo_dl_control_control_header_cqi_control_info);
XBIT_HF_VALUE(cmi, 1, hf_dlmap_dedicated_mimo_dl_control_control_header_closed_mimo_control_info);
XBIT_HF_VALUE(N_layer, 2, hf_dlmap_dedicated_mimo_dl_control_n_layer);
if (mci == 1) {
XBIT_HF_VALUE(matrix, 2, hf_dlmap_dedicated_mimo_dl_control_matrix);
if (STC_Zone_Dedicated_Pilots == 1) {
XBIT_HF(2, hf_dlmap_dedicated_mimo_dl_control_num_beamformed_streams);
}
}
if (cqi == 1) {
XBIT_HF(3, hf_dlmap_dedicated_mimo_dl_control_period);
XBIT_HF(3, hf_dlmap_dedicated_mimo_dl_control_frame_offset);
XBIT_HF(4, hf_dlmap_dedicated_mimo_dl_control_duration);
for (j = 0; j < N_layer; j++) {
XBIT_HF(6, hf_dlmap_dedicated_mimo_dl_control_allocation_index);
}
XBIT_HF_VALUE(CQICH_num, 2, hf_dlmap_dedicated_mimo_dl_control_cqich_num);
for (j = 0; j < CQICH_num; j++) {
XBIT_HF(3, hf_dlmap_dedicated_mimo_dl_control_feedback_type);
XBIT_HF(6, hf_dlmap_dedicated_mimo_dl_control_allocation_index);
}
}
if (cmi == 1) {
if (mci == 1) {
mimo_mode = matrix;
} else {
mimo_mode = STC_Zone_Matrix;
}
if (mimo_mode == 0 || mimo_mode == 1) {
XBIT_HF(3, hf_dlmap_dedicated_mimo_dl_control_antenna_grouping_index);
} else if (mimo_mode == 2) {
XBIT_HF(2, hf_dlmap_dedicated_mimo_dl_control_num_stream);
XBIT_HF(3, hf_dlmap_dedicated_mimo_dl_control_antenna_selection_index);
} else if (mimo_mode == 3) {
XBIT_HF(2, hf_dlmap_dedicated_mimo_dl_control_num_stream);
XBIT_HF(6, hf_dlmap_dedicated_mimo_dl_control_codebook_precoding_index);
}
}
pad = BIT_PADDING(bit,4);
if(pad){
proto_tree_add_bytes_format_value(tree, hf_padding, tvb, BITHI(bit,pad), NULL, "%d bits", pad);
bit += pad;
}
return (bit - offset);
}
static gint DL_HARQ_Chase_sub_burst_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
proto_tree *tree;
gint nsub, ddci, dur, sbi;
gint j;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, length), ett_286m, NULL, "DL_HARQ_Chase_sub_burst_IE");
XBIT_HF_VALUE(nsub, 4, hf_dlmap_n_sub_burst_isi);
XBIT_HF(4, hf_dlmap_harq_chase_n_ack_channel);
nsub += 1;
for (j = 0; j < nsub; j++) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
XBIT_HF_VALUE(dur, 10, hf_dlmap_harq_chase_duration);
XBIT_HF_VALUE(sbi, 1, hf_dlmap_harq_chase_sub_burst_diuc_indicator);
XBIT_HF(1, hf_dlmap_reserved_uint);
if (sbi == 1) {
XBIT_HF(4, hf_dlmap_harq_chase_diuc);
XBIT_HF(2, hf_dlmap_harq_chase_repetition_coding_indication);
XBIT_HF(2, hf_dlmap_reserved_uint);
}
XBIT_HF(4, hf_dlmap_harq_chase_acid);
XBIT_HF(1, hf_dlmap_harq_chase_ai_sn);
XBIT_HF(1, hf_dlmap_harq_chase_ack_disable);
XBIT_HF_VALUE(ddci, 2, hf_dlmap_harq_chase_dedicated_dl_control_indicator);
if ((ddci & 1) == 1) {
XBIT_HF_VALUE(dur, 4, hf_dlmap_harq_chase_duration);
if (dur != 0) {
XBIT_HF(6, hf_dlmap_harq_chase_allocation_index);
XBIT_HF(3, hf_dlmap_harq_chase_period);
XBIT_HF(3, hf_dlmap_harq_chase_frame_offset);
}
}
if ((ddci & 2) == 2) {
bit += Dedicated_DL_Control_IE(tree, BIT_TO_NIB(bit), length, tvb) * 4;
}
}
return (BIT_TO_NIB(bit) - offset);
}
static gint DL_HARQ_IR_CTC_sub_burst_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
proto_tree *tree;
gint nsub, ddci, dur;
gint j;
guint32 calculated_crc;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, 4), ett_286n, NULL, "DL HARQ IR CTC sub-burst IE");
XBIT_HF_VALUE(nsub, 4, hf_dlmap_n_sub_burst_isi);
XBIT_HF(4, hf_dlmap_harq_ir_ctc_n_ack_channel);
nsub += 1;
for (j = 0; j < nsub; j++) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
XBIT_HF(4, hf_dlmap_harq_ir_ctc_nep);
XBIT_HF(4, hf_dlmap_harq_ir_ctc_nsch);
XBIT_HF(2, hf_dlmap_harq_ir_ctc_spid);
XBIT_HF(4, hf_dlmap_harq_ir_ctc_acid);
XBIT_HF(1, hf_dlmap_harq_ir_ctc_ai_sn);
XBIT_HF(1, hf_dlmap_harq_ir_ctc_ack_disable);
XBIT_HF(2, hf_dlmap_reserved_uint);
XBIT_HF_VALUE(ddci, 2, hf_dlmap_harq_ir_ctc_dedicated_dl_control_indicator);
if ((ddci & 1) == 1) {
XBIT_HF_VALUE(dur, 4, hf_dlmap_harq_ir_ctc_duration);
if (dur != 0) {
XBIT_HF(6, hf_dlmap_harq_ir_ctc_allocation_index);
XBIT_HF(3, hf_dlmap_harq_ir_ctc_period);
XBIT_HF(3, hf_dlmap_harq_ir_ctc_frame_offset);
}
}
if ((ddci & 2) == 2) {
bit += Dedicated_DL_Control_IE(tree, BIT_TO_NIB(bit), length, tvb);
}
}
if (include_cor2_changes)
{
calculated_crc = wimax_mac_calc_crc16(tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
proto_tree_add_checksum(tree, tvb, BIT_ADDR(bit), hf_crc16, hf_crc16_status, &ei_crc16, pinfo, calculated_crc,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
bit += 16;
}
return (BIT_TO_NIB(bit) - offset);
}
static gint DL_HARQ_IR_CC_sub_burst_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
proto_tree *tree;
gint nsub, sbdi, ddci, dur;
gint j;
guint16 calculated_crc;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, 4), ett_286o, NULL, "DL HARQ IR CC sub-burst IE");
XBIT_HF_VALUE(nsub, 4, hf_dlmap_n_sub_burst_isi);
XBIT_HF(4, hf_dlmap_harq_ir_cc_n_ack_channel);
nsub += 1;
for (j = 0; j < nsub; j++) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type) / 4;
XBIT_HF(10, hf_dlmap_harq_ir_cc_duration);
XBIT_HF_VALUE(sbdi, 1, hf_dlmap_harq_ir_cc_sub_burst_diuc_indicator);
XBIT_HF(1, hf_dlmap_reserved_uint);
if (sbdi) {
XBIT_HF(4, hf_dlmap_harq_ir_cc_diuc);
XBIT_HF(2, hf_dlmap_harq_ir_cc_repetition_coding_indication);
XBIT_HF(2, hf_dlmap_reserved_uint);
}
XBIT_HF(4, hf_dlmap_harq_ir_cc_acid);
XBIT_HF(1, hf_dlmap_harq_ir_cc_ai_sn);
XBIT_HF(2, hf_dlmap_harq_ir_cc_spid);
XBIT_HF(1, hf_dlmap_harq_ir_cc_ack_disable);
XBIT_HF_VALUE(ddci, 2, hf_dlmap_harq_ir_cc_dedicated_dl_control_indicator);
XBIT_HF(2, hf_dlmap_reserved_uint);
if (ddci & 1) {
XBIT_HF_VALUE(dur, 4, hf_dlmap_harq_ir_cc_duration);
if (dur != 0) {
XBIT_HF(6, hf_dlmap_harq_ir_cc_allocation_index);
XBIT_HF(3, hf_dlmap_harq_ir_cc_period);
XBIT_HF(3, hf_dlmap_harq_ir_cc_frame_offset);
}
}
if ((ddci & 2) == 2) {
bit += Dedicated_DL_Control_IE(tree, BIT_TO_NIB(bit), length, tvb);
}
}
if (include_cor2_changes)
{
calculated_crc = wimax_mac_calc_crc16(tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
proto_tree_add_checksum(tree, tvb, BIT_ADDR(bit), hf_crc16, hf_crc16_status, &ei_crc16, pinfo, calculated_crc,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
bit += 16;
}
return (BIT_TO_NIB(bit) - offset);
}
static gint MIMO_DL_Chase_HARQ_sub_burst_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
gint nsub, mui, dci, akd;
gint i, j;
guint16 calculated_crc;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, 1), ett_286p, NULL, "MIMO DL Chase HARQ sub-burst IE");
XBIT_HF_VALUE(nsub, 4, hf_dlmap_n_sub_burst_isi);
XBIT_HF(6, hf_dlmap_mimo_dl_chase_harq_n_ack_channel);
nsub += 1;
for (j = 0; j < nsub; j++) {
XBIT_HF_VALUE(mui, 1, hf_dlmap_mimo_dl_chase_harq_mu_indicator);
XBIT_HF_VALUE(dci, 1, hf_dlmap_mimo_dl_chase_harq_dedicated_mimo_dl_control_indicator);
XBIT_HF_VALUE(akd, 1, hf_dlmap_mimo_dl_chase_harq_ack_disable);
if (mui == 0) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
}
if (dci == 1) {
bit += Dedicated_MIMO_DL_Control_IE(tree, bit, length, tvb);
}
XBIT_HF(10, hf_dlmap_mimo_dl_chase_harq_duration);
for (i = 0; i < N_layer; i++) {
if (mui == 1) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
}
XBIT_HF(4, hf_dlmap_mimo_dl_chase_harq_diuc);
XBIT_HF(2, hf_dlmap_mimo_dl_chase_harq_repetition_coding_indication);
if (akd == 0) {
XBIT_HF(4, hf_dlmap_mimo_dl_chase_harq_acid);
XBIT_HF(1, hf_dlmap_mimo_dl_chase_harq_ai_sn);
}
}
}
data = BIT_PADDING(bit, 4);
if (data) {
proto_tree_add_bytes_format_value(tree, hf_padding, tvb, BITHI(bit,data), NULL, "%d bits", data);
bit += data;
}
if (include_cor2_changes)
{
calculated_crc = wimax_mac_calc_crc16(tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
proto_tree_add_checksum(tree, tvb, BIT_ADDR(bit), hf_crc16, hf_crc16_status, &ei_crc16, pinfo, calculated_crc,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
bit += 16;
}
return (BIT_TO_NIB(bit) - offset);
}
static gint MIMO_DL_IR_HARQ_sub_burst_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
proto_tree *tree;
gint nsub, mui, dci, akd;
gint i, j;
guint16 calculated_crc;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, 4), ett_286q, NULL, "MIMO DL IR HARQ sub-burst IE");
XBIT_HF_VALUE(nsub, 4, hf_dlmap_n_sub_burst_isi);
XBIT_HF(6, hf_dlmap_mimo_dl_ir_harq_n_ack_channel);
nsub += 1;
for (j = 0; j < nsub; j++) {
XBIT_HF_VALUE(mui, 1, hf_dlmap_mimo_dl_ir_harq_mu_indicator);
XBIT_HF_VALUE(dci, 1, hf_dlmap_mimo_dl_ir_harq_dedicated_mimo_dl_control_indicator);
XBIT_HF_VALUE(akd, 1, hf_dlmap_mimo_dl_ir_harq_ack_disable);
if (mui == 0) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
}
if (dci == 1) {
bit += Dedicated_MIMO_DL_Control_IE(tree, bit, length, tvb);
}
XBIT_HF(4, hf_dlmap_mimo_dl_ir_harq_nsch);
for (i = 0; i < N_layer; i++) {
if (mui == 1) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
}
XBIT_HF(4, hf_dlmap_mimo_dl_ir_harq_nep);
if (akd) {
XBIT_HF(2, hf_dlmap_mimo_dl_ir_harq_spid);
XBIT_HF(4, hf_dlmap_mimo_dl_ir_harq_acid);
XBIT_HF(1, hf_dlmap_mimo_dl_ir_harq_ai_sn);
}
}
}
if (include_cor2_changes)
{
calculated_crc = wimax_mac_calc_crc16(tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
proto_tree_add_checksum(tree, tvb, BIT_ADDR(bit), hf_crc16, hf_crc16_status, &ei_crc16, pinfo, calculated_crc,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
bit += 16;
}
return (BIT_TO_NIB(bit) - offset);
}
static gint MIMO_DL_IR_HARQ_for_CC_sub_burst_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
proto_tree *tree;
gint nsub, mui, dci, akd;
gint i, j;
guint16 calculated_crc;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, 1), ett_286r, NULL, "MIMO DL IR HARQ for CC sub-burst IE");
XBIT_HF_VALUE(nsub, 4, hf_dlmap_n_sub_burst_isi);
XBIT_HF(6, hf_dlmap_mimo_dl_ir_harq_cc_n_ack_channel);
nsub += 1;
for (j = 0; j < nsub; j++) {
XBIT_HF_VALUE(mui, 1, hf_dlmap_mimo_dl_ir_harq_cc_mu_indicator);
XBIT_HF_VALUE(dci, 1, hf_dlmap_mimo_dl_ir_harq_cc_dedicated_mimo_dl_control_indicator);
XBIT_HF_VALUE(akd, 1, hf_dlmap_mimo_dl_ir_harq_cc_ack_disable);
if (mui == 0) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
}
if (dci == 1) {
bit += Dedicated_MIMO_DL_Control_IE(tree, bit, length, tvb);
}
XBIT_HF(10, hf_dlmap_mimo_dl_ir_harq_cc_duration);
for (i = 0; i < N_layer; i++) {
if (mui == 1) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
}
XBIT_HF(4, hf_dlmap_mimo_dl_ir_harq_cc_diuc);
XBIT_HF(2, hf_dlmap_mimo_dl_ir_harq_cc_repetition_coding_indication);
if (akd == 0) {
XBIT_HF(4, hf_dlmap_mimo_dl_ir_harq_cc_acid);
XBIT_HF(1, hf_dlmap_mimo_dl_ir_harq_cc_ai_sn);
XBIT_HF(2, hf_dlmap_mimo_dl_ir_harq_cc_spid);
}
}
}
if (include_cor2_changes)
{
calculated_crc = wimax_mac_calc_crc16(tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
proto_tree_add_checksum(tree, tvb, BIT_ADDR(bit), hf_crc16, hf_crc16_status, &ei_crc16, pinfo, calculated_crc,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
bit += 16;
}
return (BIT_TO_NIB(bit) - offset);
}
static gint MIMO_DL_STC_HARQ_sub_burst_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
proto_tree *tree;
gint nsub, sbi, txc, akd, dmci;
gint j;
guint16 calculated_crc;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, BITHI(bit, 1), ett_286s, NULL, "MIMO DL STC HARQ sub-burst IE");
XBIT_HF_VALUE(nsub, 4, hf_dlmap_n_sub_burst_isi);
XBIT_HF(6, hf_dlmap_mimo_dl_stc_harq_n_ack_channel);
nsub += 1;
for (j = 0; j < nsub; j++) {
XBIT_HF_VALUE(txc, 2, hf_dlmap_mimo_dl_stc_harq_tx_count);
XBIT_HF(10, hf_dlmap_mimo_dl_stc_harq_duration);
XBIT_HF_VALUE(sbi, 1, hf_dlmap_mimo_dl_stc_harq_sub_burst_offset_indication);
XBIT_HF(3, hf_dlmap_reserved_uint);
if (sbi == 1) {
XBIT_HF(8, hf_dlmap_mimo_dl_stc_harq_sub_burst_offset);
}
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
XBIT_HF_VALUE(akd, 1, hf_dlmap_mimo_dl_stc_harq_ack_disable);
if (txc == 0) {
XBIT_HF_VALUE(dmci, 1, hf_dlmap_mimo_dl_stc_harq_dedicated_mimo_dl_control_indicator);
if (dmci == 1) {
bit += Dedicated_MIMO_DL_Control_IE(tree, bit, length, tvb);
}
XBIT_HF(4, hf_dlmap_mimo_dl_stc_harq_diuc);
XBIT_HF(2, hf_dlmap_mimo_dl_stc_harq_repetition_coding_indication);
}
if (akd == 0) {
XBIT_HF(4, hf_dlmap_mimo_dl_stc_harq_acid);
}
}
if (include_cor2_changes)
{
calculated_crc = wimax_mac_calc_crc16(tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
proto_tree_add_checksum(tree, tvb, BIT_ADDR(bit), hf_crc16, hf_crc16_status, &ei_crc16, pinfo, calculated_crc,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
bit += 16;
}
return (BIT_TO_NIB(bit) - offset);
}
static gint MBS_MAP_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
gint mde, dci, s3i;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286a, NULL, "MBS_MAP_IE");
XBIT_HF(4, hf_dlmap_mbs_map_extended_2_diuc);
VBIT(data, 8, hf_dlmap_ie_length);
XBIT_HF(7, hf_dlmap_mbs_map_mbs_zone_identifier);
XBIT_HF_VALUE(mde, 1, hf_dlmap_mbs_map_macro_diversity_enhanced);
if (mde == 1)
{
XBIT_HF(2, hf_dlmap_mbs_map_permutation);
XBIT_HF(5, hf_dlmap_mbs_map_dl_permbase);
XBIT_HF(2, hf_dlmap_mbs_map_prbs_id);
XBIT_HF(7, hf_dlmap_mbs_map_ofdma_symbol_offset);
XBIT_HF_VALUE(dci, 1, hf_dlmap_mbs_map_diuc_change_indication);
XBIT_HF(3, hf_dlmap_reserved_uint);
if (dci == 1) {
XBIT_HF(3, hf_dlmap_reserved_uint);
XBIT_HF(3, hf_dlmap_mbs_map_boosting);
XBIT_HF(4, hf_dlmap_mbs_map_diuc);
XBIT_HF(6, hf_dlmap_mbs_map_num_subchannels);
XBIT_HF(6, hf_dlmap_mbs_map_num_ofdma_symbols);
XBIT_HF(2, hf_dlmap_mbs_map_repetition_coding_indication);
}
} else {
XBIT_HF(4, hf_dlmap_mbs_map_diuc);
XBIT_HF(16, hf_dlmap_mbs_map_cid);
XBIT_HF(8, hf_dlmap_mbs_map_ofdma_symbols_offset);
XBIT_HF(6, hf_dlmap_mbs_map_subchannel_offset);
XBIT_HF(3, hf_dlmap_mbs_map_boosting);
XBIT_HF_VALUE(s3i, 1, hf_dlmap_mbs_map_slc_3_indication);
XBIT_HF(6, hf_dlmap_mbs_map_num_ofdma_symbols);
XBIT_HF(6, hf_dlmap_mbs_map_num_subchannels);
XBIT_HF(2, hf_dlmap_mbs_map_repetition_coding_indication);
if (s3i == 1) {
XBIT_HF(8, hf_dlmap_mbs_map_next_mbs_map_ie_frame_offset);
}
}
data = BIT_PADDING(bit, 4);
if (data) {
proto_tree_add_bytes_format_value(tree, hf_padding, tvb, BITHI(bit,data), NULL, "%d bits", data);
bit += data;
}
return BIT_TO_NIB(bit);
}
static gint HO_Anchor_Active_DL_MAP_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286c, NULL, "HO_Anchor_Active_DL_MAP_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_expert(diuc_tree, pinfo, &ei_dlmap_not_implemented, tvb, NIBHI(nib, length-3));
return nib;
}
static gint HO_Active_Anchor_DL_MAP_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286d, NULL, "HO_Active_Anchor_DL_MAP_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_expert(diuc_tree, pinfo, &ei_dlmap_not_implemented, tvb, NIBHI(nib, length-3));
return nib;
}
static gint HO_CID_Translation_MAP_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286e, NULL, "CID_Translation_MAP_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_expert(diuc_tree, pinfo, &ei_dlmap_not_implemented, tvb, NIBHI(nib, length-3));
return nib;
}
static gint MIMO_in_another_BS_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286f, NULL, "MIMO_in_another_BS_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_expert(diuc_tree, pinfo, &ei_dlmap_not_implemented, tvb, NIBHI(nib, length-3));
return nib;
}
static gint Macro_MIMO_DL_Basic_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286g, NULL, "Macro_MIMO_DL_Basic_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_expert(diuc_tree, pinfo, &ei_dlmap_not_implemented, tvb, NIBHI(nib, length-3));
return nib;
}
static gint Skip_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286k, NULL, "Skip_IE");
XBIT_HF(4, hf_dlmap_skip_extended_2_diuc);
VBIT(data, 8, hf_dlmap_ie_length);
XBIT_HF(1, hf_dlmap_skip_mode);
XBIT_HF(7, hf_dlmap_reserved_uint);
return BIT_TO_NIB(bit);
}
static gint HARQ_DL_MAP_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
proto_tree *tree;
gint len, lastbit, rui, mode, sub_len, pad;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286l, NULL, "HARQ_DL_MAP_IE");
XBIT_HF(4, hf_dlmap_harq_dl_map_extended_2_diuc);
VBIT(len, 2, hf_dlmap_ie_length);
XBIT_HF_VALUE(RCID_Type, 2, hf_dlmap_harq_dl_map_rcid_type);
XBIT_HF(2, hf_dlmap_reserved_uint);
length = NIB_TO_BIT(length);
lastbit = bit + BYTE_TO_BIT(len) - 14 - 4;
while (bit < lastbit) {
XBIT_HF(3, hf_dlmap_harq_dl_map_boosting);
XBIT_HF_VALUE(rui, 1, hf_dlmap_harq_dl_map_region_id_use_indicator);
if (rui == 0) {
XBIT_HF(8, hf_dlmap_harq_dl_map_ofdma_symbol_offset);
XBIT_HF(7, hf_dlmap_harq_dl_map_subchannel_offset);
XBIT_HF(7, hf_dlmap_harq_dl_map_number_of_ofdma_symbols);
XBIT_HF(7, hf_dlmap_harq_dl_map_number_of_subchannels);
if (include_cor2_changes)
{
XBIT_HF(1, hf_dlmap_harq_dl_map_rectangular_sub_burst_indicator);
XBIT_HF(2, hf_dlmap_reserved_uint);
}
else
{
XBIT_HF(3, hf_dlmap_reserved_uint);
}
} else {
XBIT_HF(8, hf_dlmap_harq_dl_map_region_id);
}
XBIT_HF_VALUE(mode, 4, hf_dlmap_harq_dl_map_mode);
XBIT_HF_VALUE(sub_len, 8, hf_dlmap_harq_dl_map_sub_burst_ie_length);
if (mode == 0) {
DL_HARQ_Chase_sub_burst_IE(tree, BIT_TO_NIB(bit), length, tvb);
} else if (mode == 1) {
DL_HARQ_IR_CTC_sub_burst_IE(tree, pinfo, BIT_TO_NIB(bit), length, tvb);
} else if (mode == 2) {
DL_HARQ_IR_CC_sub_burst_IE(tree, pinfo, BIT_TO_NIB(bit), length, tvb);
} else if (mode == 3) {
MIMO_DL_Chase_HARQ_sub_burst_IE(tree, pinfo, BIT_TO_NIB(bit), length, tvb);
} else if (mode == 4) {
MIMO_DL_IR_HARQ_sub_burst_IE(tree, pinfo, BIT_TO_NIB(bit), length, tvb);
} else if (mode == 5) {
MIMO_DL_IR_HARQ_for_CC_sub_burst_IE(tree, pinfo, BIT_TO_NIB(bit), length, tvb);
} else if (mode == 6) {
MIMO_DL_STC_HARQ_sub_burst_IE(tree, pinfo, BIT_TO_NIB(bit), length, tvb);
} else {
proto_tree_add_bits_item(tree, hf_dlmap_harq_dl_map_reserved_mode, tvb, bit, 1, ENC_BIG_ENDIAN);
break;
}
bit += NIB_TO_BIT(sub_len);
}
pad = NIB_TO_BIT(offset) + length - bit;
if (pad) {
proto_tree_add_bytes_format_value(tree, hf_padding, tvb, BITHI(bit,pad), NULL, "%d bits",pad);
bit += pad;
}
return BIT_TO_NIB(bit);
}
static gint HARQ_ACK_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint data;
gint nib;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286u, NULL, "HARQ_ACK_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_item(diuc_tree, hf_dlmap_harq_ack_bitmap_data, tvb, NIBHI(nib,length-3), ENC_NA);
return nib;
}
static gint Enhanced_DL_MAP_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
gint numass, n_cid;
gint i, n;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286v, NULL, "Enhanced_DL-MAP_IE");
XBIT_HF(4, hf_dlmap_enhanced_dl_map_extended_2_diuc);
VBIT(data, 8, hf_dlmap_ie_length);
XBIT_HF_VALUE(numass, 4, hf_dlmap_enhanced_dl_map_num_assignment);
for (i = 0; i < numass; i++) {
if (INC_CID == 1) {
XBIT_HF_VALUE(n_cid, 8, hf_dlmap_enhanced_dl_map_n_cid);
for (n = 0; n < n_cid; n++) {
XBIT_HF(16, hf_dlmap_enhanced_dl_map_cid);
}
}
XBIT_HF(4, hf_dlmap_enhanced_dl_map_diuc);
XBIT_HF(3, hf_dlmap_enhanced_dl_map_boosting);
XBIT_HF(2, hf_dlmap_enhanced_dl_map_repetition_coding_indication);
XBIT_HF(8, hf_dlmap_enhanced_dl_map_region_id);
XBIT_HF(3, hf_dlmap_reserved_uint);
}
return BIT_TO_NIB(bit);
}
static gint Closed_loop_MIMO_DL_Enhanced_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286w, NULL, "CL_MIMO_DL_Enhanced_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_expert(diuc_tree, pinfo, &ei_dlmap_not_implemented, tvb, NIBHI(nib, length-3));
return nib;
}
static gint AAS_SDMA_DL_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
gint num_region, num_users, pilot_pattern, encoding_mode, ackch_alloc, cqich_alloc;
gint aas_preamble = 1;
gint zone_permut = 0;
gint i, j;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286y, NULL, "AAS_SDMA_DL_IE");
XBIT_HF(4, hf_dlmap_aas_sdma_dl_extended_2_diuc);
VBIT(data, 8, hf_dlmap_ie_length);
XBIT_HF_VALUE(RCID_Type, 2, hf_dlmap_aas_sdma_dl_rcid_type);
XBIT_HF_VALUE(num_region, 4, hf_dlmap_aas_sdma_dl_num_burst_region);
XBIT_HF(2, hf_dlmap_reserved_uint);
for (i = 0; i < num_region; i++) {
XBIT_HF(8, hf_dlmap_aas_sdma_dl_ofdma_symbol_offset);
if (zone_permut == 0) {
XBIT_HF(8, hf_dlmap_aas_sdma_dl_subchannel_offset);
XBIT_HF(5, hf_dlmap_aas_sdma_dl_num_ofdma_triple_symbols);
XBIT_HF(6, hf_dlmap_aas_sdma_dl_num_subchannels);
} else {
XBIT_HF(6, hf_dlmap_aas_sdma_dl_subchannel_offset);
XBIT_HF(7, hf_dlmap_aas_sdma_dl_num_ofdma_triple_symbols);
XBIT_HF(6, hf_dlmap_aas_sdma_dl_num_subchannels);
}
XBIT_HF_VALUE(num_users, 3, hf_dlmap_aas_sdma_dl_number_of_users);
XBIT_HF(2, hf_dlmap_reserved_uint);
for (j = 0; j < num_users; j++) {
bit += RCID_IE(tree, bit, length, tvb, RCID_Type);
XBIT_HF_VALUE(encoding_mode, 2, hf_dlmap_aas_sdma_dl_encoding_mode);
XBIT_HF_VALUE(cqich_alloc, 1, hf_dlmap_aas_sdma_dl_cqich_allocation);
XBIT_HF_VALUE(ackch_alloc, 1, hf_dlmap_aas_sdma_dl_ackch_allocation);
XBIT_HF_VALUE(pilot_pattern, 1, hf_dlmap_aas_sdma_dl_pilot_pattern_modifier);
if (aas_preamble) {
XBIT_HF(4, hf_dlmap_aas_sdma_dl_preamble_modifier_index);
}
if (pilot_pattern) {
XBIT_HF(2, hf_dlmap_aas_sdma_dl_pilot_pattern);
XBIT_HF(1, hf_dlmap_reserved_uint);
} else {
XBIT_HF(3, hf_dlmap_reserved_uint);
}
if (encoding_mode == 0x0) {
XBIT_HF(4, hf_dlmap_aas_sdma_dl_diuc);
XBIT_HF(2, hf_dlmap_aas_sdma_dl_repetition_coding_indication);
XBIT_HF(2, hf_dlmap_reserved_uint);
}
if (encoding_mode == 0x1) {
if (ackch_alloc) {
XBIT_HF(5, hf_dlmap_aas_sdma_dl_ack_ch_index);
} else {
XBIT_HF(1, hf_dlmap_reserved_uint);
}
XBIT_HF(4, hf_dlmap_aas_sdma_dl_diuc);
XBIT_HF(2, hf_dlmap_aas_sdma_dl_repetition_coding_indication);
XBIT_HF(4, hf_dlmap_aas_sdma_dl_acid);
XBIT_HF(1, hf_dlmap_aas_sdma_dl_ai_sn);
}
if (encoding_mode == 0x2) {
if (ackch_alloc) {
XBIT_HF(5, hf_dlmap_aas_sdma_dl_ack_ch_index);
} else {
XBIT_HF(1, hf_dlmap_reserved_uint);
}
XBIT_HF(4, hf_dlmap_aas_sdma_dl_nep);
XBIT_HF(4, hf_dlmap_aas_sdma_dl_nsch);
XBIT_HF(2, hf_dlmap_aas_sdma_dl_spid);
XBIT_HF(4, hf_dlmap_aas_sdma_dl_acid);
XBIT_HF(1, hf_dlmap_aas_sdma_dl_ai_sn);
}
if (encoding_mode == 0x3) {
if (ackch_alloc) {
XBIT_HF(5, hf_dlmap_aas_sdma_dl_ack_ch_index);
XBIT_HF(2, hf_dlmap_reserved_uint);
} else {
XBIT_HF(3, hf_dlmap_reserved_uint);
}
XBIT_HF(4, hf_dlmap_aas_sdma_dl_diuc);
XBIT_HF(2, hf_dlmap_aas_sdma_dl_repetition_coding_indication);
XBIT_HF(2, hf_dlmap_aas_sdma_dl_spid);
XBIT_HF(4, hf_dlmap_aas_sdma_dl_acid);
XBIT_HF(1, hf_dlmap_aas_sdma_dl_ai_sn);
}
if (cqich_alloc) {
XBIT_HF(6, hf_dlmap_aas_sdma_dl_allocation_index);
XBIT_HF(3, hf_dlmap_aas_sdma_dl_period);
XBIT_HF(3, hf_dlmap_aas_sdma_dl_frame_offset);
XBIT_HF(4, hf_dlmap_aas_sdma_dl_duration);
}
}
}
data = BIT_PADDING(bit,4);
proto_tree_add_bytes_format_value(tree, hf_padding, tvb, BITHI(bit,data), NULL, "%d bits", data);
bit += data;
return BIT_TO_NIB(bit);
}
static gint Channel_Measurement_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_280, NULL, "Channel_Measurement_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext);
VNIB(data, 1, hf_dlmap_ie_length);
VNIB(data, 2, hf_dlmap_channel_measurement_channel_nr);
VNIB(data, 2, hf_dlmap_channel_measurement_ofdma_symbol_offset);
VNIB(data, 4, hf_dlmap_channel_measurement_cid);
return nib;
}
static gint STC_Zone_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_279, NULL, "STC_Zone_IE");
VBIT(data, 4, hf_dlmap_ie_diuc_ext);
VBIT(data, 4, hf_dlmap_ie_length);
XBIT_HF(8, hf_dlmap_stc_zone_ofdma_symbol_offset);
XBIT_HF(2, hf_dlmap_stc_zone_permutations);
XBIT_HF(1, hf_dlmap_stc_zone_use_all_sc_indicator);
XBIT_HF(2, hf_dlmap_stc_zone_stc);
XBIT_HF_VALUE(STC_Zone_Matrix, 2, hf_dlmap_stc_zone_matrix_indicator);
XBIT_HF(5, hf_dlmap_stc_zone_dl_permbase);
XBIT_HF(2, hf_dlmap_stc_zone_prbs_id);
XBIT_HF(2, hf_dlmap_stc_zone_amc_type);
XBIT_HF(1, hf_dlmap_stc_zone_midamble_presence);
XBIT_HF(1, hf_dlmap_stc_zone_midamble_boosting);
XBIT_HF(1, hf_dlmap_stc_zone_2_3_antenna_select);
XBIT_HF_VALUE(STC_Zone_Dedicated_Pilots, 1, hf_dlmap_stc_zone_dedicated_pilots);
XBIT_HF(4, hf_dlmap_reserved_uint);
return BIT_TO_NIB(bit);
}
static gint AAS_DL_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_278, NULL, "AAS_DL_IE");
VBIT(data, 4, hf_dlmap_ie_diuc_ext);
VBIT(data, 4, hf_dlmap_ie_length);
XBIT_HF(8, hf_dlmap_aas_dl_ofdma_symbol_offset);
XBIT_HF(3, hf_dlmap_aas_dl_permutation);
XBIT_HF(6, hf_dlmap_aas_dl_dl_permbase);
XBIT_HF(2, hf_dlmap_aas_dl_downlink_preamble_config);
XBIT_HF(1, hf_dlmap_aas_dl_preamble_type);
XBIT_HF(2, hf_dlmap_aas_dl_prbs_id);
XBIT_HF(1, hf_dlmap_aas_dl_diversity_map);
XBIT_HF(1, hf_dlmap_reserved_uint);
return BIT_TO_NIB(bit);
}
static gint Data_location_in_another_BS_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_281, NULL, "Data location in another BS IE");
VBIT(data, 4, hf_dlmap_ie_diuc_ext);
VBIT(data, 4, hf_dlmap_ie_length);
XBIT_HF(2, hf_dlmap_data_location_another_bs_segment);
XBIT_HF(6, hf_dlmap_data_location_another_bs_used_subchannels);
XBIT_HF(4, hf_dlmap_data_location_another_bs_diuc);
XBIT_HF(3, hf_dlmap_data_location_another_bs_frame_advance);
XBIT_HF(1, hf_dlmap_reserved_uint);
XBIT_HF(8, hf_dlmap_data_location_another_bs_ofdma_symbol_offset);
XBIT_HF(6, hf_dlmap_data_location_another_bs_subchannel_offset);
XBIT_HF(3, hf_dlmap_data_location_another_bs_boosting);
XBIT_HF(7, hf_dlmap_data_location_another_bs_preamble_index);
XBIT_HF(8, hf_dlmap_data_location_another_bs_num_ofdma_symbols);
XBIT_HF(6, hf_dlmap_data_location_another_bs_num_subchannels);
XBIT_HF(2, hf_dlmap_data_location_another_bs_repetition_coding_indication);
XBIT_HF(16, hf_dlmap_data_location_another_bs_cid);
return BIT_TO_NIB(bit);
}
static gint CID_Switch_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
INC_CID = INC_CID ? 0 : 1;
tree = proto_tree_add_subtree_format(diuc_tree, tvb, NIBHI(offset, length), ett_282, NULL, "CID_Switch_IE (INC_CID = %d)", INC_CID);
VNIB(data, 1, hf_dlmap_ie_diuc_ext);
VNIB(data, 1, hf_dlmap_ie_length);
return nib;
}
static gint MIMO_DL_Basic_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_283, NULL, "MIMO_DL_Basic_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_expert(diuc_tree, pinfo, &ei_dlmap_not_implemented, tvb, NIBHI(nib, length-2));
return nib;
}
static gint MIMO_DL_Enhanced_IE(proto_tree *diuc_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
gint nib;
gint data;
proto_tree *tree;
nib = offset;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_284, NULL, "MIMO_DL_Enhanced_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext2);
VNIB(data, 2, hf_dlmap_ie_length);
proto_tree_add_expert(diuc_tree, pinfo, &ei_dlmap_not_implemented, tvb, NIBHI(nib, length-2));
return nib;
}
static gint HARQ_Map_Pointer_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
gint length_in_bits, map, mask_len;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_285, NULL, "HARQ_Map_Pointer_IE");
VBIT(data, 4, hf_dlmap_ie_diuc_ext);
VBIT(data, 4, hf_dlmap_ie_length);
length_in_bits = NIB_TO_BIT(length-1);
while (bit < length_in_bits) {
XBIT_HF(4, hf_dlmap_harq_map_pointer_diuc);
XBIT_HF(8, hf_dlmap_harq_map_pointer_num_slots);
XBIT_HF(2, hf_dlmap_harq_map_pointer_repetition_coding_indication);
XBIT_HF_VALUE(map, 2, hf_dlmap_harq_map_pointer_map_version);
if (map == 2) {
XBIT_HF(1, hf_dlmap_harq_map_pointer_idle_users);
XBIT_HF(1, hf_dlmap_harq_map_pointer_sleep_users);
XBIT_HF_VALUE(mask_len, 2, hf_dlmap_harq_map_pointer_cid_mask_length);
if (mask_len == 0) {
proto_tree_add_bytes_format_value(diuc_tree, hf_cid_mask, tvb, BITHI(bit,12), NULL, "12 bits");
bit += 12;
} else if (mask_len == 1) {
proto_tree_add_bytes_format_value(diuc_tree, hf_cid_mask, tvb, BITHI(bit,20), NULL, "20 bits");
bit += 20;
} else if (mask_len == 2) {
proto_tree_add_bytes_format_value(diuc_tree, hf_cid_mask, tvb, BITHI(bit,36), NULL, "36 bits");
bit += 36;
} else if (mask_len == 3) {
proto_tree_add_bytes_format_value(diuc_tree, hf_cid_mask, tvb, BITHI(bit,52), NULL, "52 bits");
bit += 52;
}
}
}
return BIT_TO_NIB(bit);
}
static gint PHYMOD_DL_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
gint pmt;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286, NULL, "PHYMOD_DL_IE");
VBIT(data, 4, hf_dlmap_ie_diuc_ext);
VBIT(data, 4, hf_dlmap_ie_length);
XBIT_HF_VALUE(pmt, 1, hf_dlmap_phymod_dl_preamble_modifier_type);
if (pmt == 0) {
XBIT_HF(4, hf_dlmap_phymod_dl_preamble_frequency_shift_index);
} else {
XBIT_HF(4, hf_dlmap_phymod_dl_preamble_time_shift_index);
}
XBIT_HF(1, hf_dlmap_phymod_dl_pilot_pattern_modifier);
XBIT_HF(2, hf_dlmap_phymod_dl_pilot_pattern_index);
return BIT_TO_NIB(bit);
}
static gint Broadcast_Control_Pointer_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
gint skip;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286x, NULL, "Broadcast Control Pointer IE");
VBIT(data, 4, hf_dlmap_ie_diuc_ext);
VBIT(data, 4, hf_dlmap_ie_length);
XBIT_HF(7, hf_dlmap_broadcast_ctrl_ptr_dcd_ucd_transmission_frame);
XBIT_HF_VALUE(skip, 1, hf_dlmap_broadcast_ctrl_ptr_skip_broadcast_system_update);
if (skip == 0) {
XBIT_HF(1, hf_dlmap_broadcast_ctrl_ptr_broadcast_system_update_type);
XBIT_HF(7, hf_dlmap_broadcast_ctrl_ptr_broadcast_system_update_transmission_frame);
}
return BIT_TO_NIB(bit);
}
static gint DL_PUSC_Burst_Allocation_in_Other_Segment_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286b, NULL, "DL_PUSC_Burst_Allocation_in_Other_Segment_IE");
VBIT(data, 4, hf_dlmap_ie_diuc_ext);
VBIT(data, 4, hf_dlmap_ie_length);
XBIT_HF(16, hf_dlmap_dl_pusc_burst_allocation_cid);
XBIT_HF(4, hf_dlmap_dl_pusc_burst_allocation_diuc);
XBIT_HF(2, hf_dlmap_dl_pusc_burst_allocation_segment);
XBIT_HF(3, hf_dlmap_dl_pusc_burst_allocation_boosting);
XBIT_HF(5, hf_dlmap_dl_pusc_burst_allocation_idcell);
XBIT_HF(5, hf_dlmap_dl_pusc_burst_allocation_dl_permbase);
XBIT_HF(2, hf_dlmap_dl_pusc_burst_allocation_prbs_id);
XBIT_HF(2, hf_dlmap_dl_pusc_burst_allocation_repetition_coding_indication);
XBIT_HF(6, hf_dlmap_dl_pusc_burst_allocation_used_subchannels);
XBIT_HF(8, hf_dlmap_dl_pusc_burst_allocation_ofdma_symbol_offset);
XBIT_HF(1, hf_dlmap_reserved_uint);
XBIT_HF(7, hf_dlmap_dl_pusc_burst_allocation_num_ofdma_symbols);
XBIT_HF(6, hf_dlmap_dl_pusc_burst_allocation_subchannel_offset);
XBIT_HF(6, hf_dlmap_dl_pusc_burst_allocation_num_subchannels);
XBIT_HF(7, hf_dlmap_reserved_uint);
return BIT_TO_NIB(bit);
}
static gint PUSC_ASCA_Alloc_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
gint bit;
gint data;
proto_tree *tree;
bit = NIB_TO_BIT(offset);
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286z, NULL, "PUSC_ASCA_Alloc_IE");
VBIT(data, 4, hf_dlmap_ie_diuc_ext);
VBIT(data, 4, hf_dlmap_ie_length);
XBIT_HF(4, hf_dlmap_pusc_asca_alloc_diuc);
XBIT_HF(12, hf_dlmap_pusc_asca_alloc_short_basic_cid);
XBIT_HF(8, hf_dlmap_pusc_asca_alloc_ofdma_symbol_offset);
XBIT_HF(6, hf_dlmap_pusc_asca_alloc_subchannel_offset);
XBIT_HF(7, hf_dlmap_pusc_asca_alloc_num_ofdma_symbols);
XBIT_HF(6, hf_dlmap_pusc_asca_alloc_num_symbols);
XBIT_HF(2, hf_dlmap_pusc_asca_alloc_repetition_coding_information);
XBIT_HF(4, hf_dlmap_pusc_asca_alloc_permutation_id);
XBIT_HF(7, hf_dlmap_reserved_uint);
return BIT_TO_NIB(bit);
}
static gint UL_interference_and_noise_level_IE(proto_tree *diuc_tree, gint offset, gint length, tvbuff_t *tvb)
{
proto_tree *tree;
gint nib = offset;
gint bitmap, data;
tree = proto_tree_add_subtree(diuc_tree, tvb, NIBHI(offset, length), ett_286h, NULL, "UL_interference_and_noise_level_IE");
VNIB(data, 1, hf_dlmap_ie_diuc_ext);
VNIB(data, 1, hf_dlmap_ie_length);
VNIB(bitmap, 2, hf_dlmap_ie_bitmap);
if (bitmap & 0x01) {
VNIB(data, 2, hf_dlmap_ie_bitmap_cqi);
}
if (bitmap & 0x02) {
VNIB(data, 2, hf_dlmap_ie_bitmap_pusc);
}
if (bitmap & 0x04) {
VNIB(data, 2, hf_dlmap_ie_bitmap_opt_pusc);
}
if (bitmap & 0x08) {
VNIB(data, 2, hf_dlmap_ie_bitmap_amc);
}
if (bitmap & 0x10) {
VNIB(data, 2, hf_dlmap_ie_bitmap_aas);
}
if (bitmap & 0x20) {
VNIB(data, 2, hf_dlmap_ie_bitmap_periodic_ranging);
}
if (bitmap & 0x40) {
VNIB(data, 2, hf_dlmap_ie_bitmap_sounding);
}
if (bitmap & 0x80) {
VNIB(data, 2, hf_dlmap_ie_bitmap_mimo);
}
return nib;
}
static gint dissect_dlmap_ie(proto_tree *ie_tree, packet_info *pinfo, gint offset, gint length, tvbuff_t *tvb)
{
proto_item *ti = NULL;
proto_tree *tree = NULL;
gint nibble = offset;
gint diuc;
gint ext2_diuc;
gint len;
gint ext_diuc;
gint alt_format = 0;
guint data = 0;
gint i;
gint ie_len = 9;
gint n_cid;
diuc = TVB_NIB_NIBBLE(nibble, tvb);
if (diuc == 14)
{
ext2_diuc = TVB_NIB_NIBBLE(1+nibble, tvb);
len = TVB_NIB_BYTE(1+nibble+1, tvb);
ti = proto_tree_add_uint(ie_tree, hf_dlmap_ie_diuc, tvb, NIBHI(nibble, 1+3+len*2), diuc);
proto_item_append_text(ti, " (Extended-2)");
tree = proto_item_add_subtree(ti, ett_277b);
nibble++;
len = 3 + BYTE_TO_NIB(len);
switch (ext2_diuc)
{
case 0x00:
nibble = MBS_MAP_IE(tree, nibble, len, tvb);
break;
case 0x01:
nibble = HO_Anchor_Active_DL_MAP_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x02:
nibble = HO_Active_Anchor_DL_MAP_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x03:
nibble = HO_CID_Translation_MAP_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x04:
nibble = MIMO_in_another_BS_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x05:
nibble = Macro_MIMO_DL_Basic_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x06:
nibble = Skip_IE(tree, nibble, len, tvb);
break;
case 0x07:
nibble = HARQ_DL_MAP_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x08:
nibble = HARQ_ACK_IE(tree, nibble, len, tvb);
break;
case 0x09:
nibble = Enhanced_DL_MAP_IE(tree, nibble, len, tvb);
break;
case 0x0a:
nibble = Closed_loop_MIMO_DL_Enhanced_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x0b:
nibble = MIMO_DL_Basic_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x0c:
nibble = MIMO_DL_Enhanced_IE(tree, pinfo, nibble, len, tvb);
break;
case 0x0e:
nibble = AAS_SDMA_DL_IE(tree, nibble, len, tvb);
break;
default:
proto_tree_add_bytes_format(tree, hf_dlmap_ie_reserved_extended2_duic, tvb, NIBHI(nibble,len), NULL, "(reserved Extended-2 DIUC: %d)", ext2_diuc);
nibble += len;
break;
}
}
else if (diuc == 15)
{
ext_diuc = TVB_NIB_NIBBLE(1+nibble, tvb);
len = TVB_NIB_NIBBLE(1+nibble+1, tvb);
ti = proto_tree_add_uint(ie_tree, hf_dlmap_ie_diuc, tvb, NIBHI(nibble, 1+2+len*2), diuc);
proto_item_append_text(ti, " (Extended)");
tree = proto_item_add_subtree(ti, ett_277);
nibble++;
len = 2 + BYTE_TO_NIB(len);
switch (ext_diuc)
{
case 0x00:
nibble = Channel_Measurement_IE(tree, nibble, len, tvb);
break;
case 0x01:
nibble = STC_Zone_IE(tree, nibble, len, tvb);
break;
case 0x02:
nibble = AAS_DL_IE(tree, nibble, len, tvb);
break;
case 0x03:
nibble = Data_location_in_another_BS_IE(tree, nibble, len, tvb);
break;
case 0x04:
nibble = CID_Switch_IE(tree, nibble, len, tvb);
break;
case 0x07:
nibble = HARQ_Map_Pointer_IE(tree, nibble, len, tvb);
break;
case 0x08:
nibble = PHYMOD_DL_IE(tree, nibble, len, tvb);
break;
case 0x0a:
nibble = Broadcast_Control_Pointer_IE(tree, nibble, len, tvb);
break;
case 0x0b:
nibble = DL_PUSC_Burst_Allocation_in_Other_Segment_IE(tree, nibble, len, tvb);
break;
case 0x0c:
nibble = PUSC_ASCA_Alloc_IE(tree, nibble, len, tvb);
break;
case 0x0f:
nibble = UL_interference_and_noise_level_IE(tree, nibble, len, tvb);
break;
default:
proto_tree_add_bytes_format(tree, hf_dlmap_ie_reserved_extended_duic, tvb, NIBHI(nibble,len), NULL, "(reserved Extended DIUC: %d)", ext_diuc);
nibble += len;
break;
}
}
else
{
alt_format = 0;
ie_len = 9;
if (INC_CID && !sub_dl_ul_map) {
ie_len += 2 + (TVB_NIB_BYTE(nibble+1, tvb) * 4);
}
ti = proto_tree_add_uint(ie_tree, hf_dlmap_ie_diuc, tvb, NIBHI(nibble, ie_len), diuc);
tree = proto_item_add_subtree(ti, ett_275_1);
nibble += 1;
if (diuc == 13) {
proto_item_append_text(ti, " (Gap/PAPR Reduction)");
}
if (INC_CID)
{
n_cid = TVB_NIB_BYTE(nibble, tvb);
proto_tree_add_uint(tree, hf_dlmap_ie_ncid, tvb, NIBHI(nibble, 2), n_cid);
nibble += 2;
for (i = 0; i < n_cid; i++)
{
if (sub_dl_ul_map) {
nibble += RCID_IE(tree, nibble*4, length, tvb, RCID_Type) / 4;
} else {
data = TVB_NIB_WORD(nibble, tvb);
proto_tree_add_uint(tree, hf_dlmap_ie_cid, tvb, NIBHI(nibble, 4), data);
nibble += 4;
}
}
}
data = TVB_NIB_LONG(nibble, tvb);
if (alt_format) {
proto_tree_add_uint(tree, hf_dlmap_ie_offsym2, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_offsub2, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_boosting2, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_numsym2, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_numsub2, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_rep2, tvb, NIBHI(nibble, 8), data);
} else {
proto_tree_add_uint(tree, hf_dlmap_ie_offsym, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_offsub, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_boosting, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_numsym, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_numsub, tvb, NIBHI(nibble, 8), data);
proto_tree_add_uint(tree, hf_dlmap_ie_rep, tvb, NIBHI(nibble, 8), data);
}
nibble += 8;
}
return (nibble - offset);
}
static int dissect_mac_mgmt_msg_dlmap_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *base_tree, void* data _U_)
{
guint offset = 0;
gint length, nib, pad;
proto_item *ti = NULL;
proto_tree *dlmap_tree = NULL;
proto_tree *ie_tree = NULL;
proto_tree *phy_tree = NULL;
gint tvb_len = tvb_reported_length(tvb);
INC_CID = 0;
ti = proto_tree_add_protocol_format(base_tree, proto_mac_mgmt_msg_dlmap_decoder, tvb, offset, -1, "DL-MAP");
dlmap_tree = proto_item_add_subtree(ti, ett_dlmap);
{
phy_tree = proto_tree_add_subtree(dlmap_tree, tvb, offset, 4, ett_275_phy, NULL, "Phy Synchronization Field");
proto_tree_add_item(phy_tree, hf_dlmap_phy_fdur_ms, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_dlmap_phy_fdur_per_sec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_dlmap_phy_fdur, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(phy_tree, hf_dlmap_phy_fnum, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
}
proto_tree_add_item(dlmap_tree, hf_dlmap_dcd, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dlmap_tree, hf_dlmap_bsid, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(dlmap_tree, hf_dlmap_ofdma_sym, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_len - offset;
ie_tree = proto_tree_add_subtree_format(dlmap_tree, tvb, offset, length, ett_dlmap_ie, NULL, "DL-MAP IEs (%d bytes)", length);
nib = BYTE_TO_NIB(offset);
while (nib < ((tvb_len*2)-1)) {
nib += dissect_dlmap_ie(ie_tree, pinfo, nib, tvb_len * 2, tvb);
}
pad = NIB_PADDING(nib);
if (pad) {
proto_tree_add_bytes_format(dlmap_tree, hf_padding, tvb, NIBHI(nib,1), NULL, "Padding nibble");
nib++;
}
return tvb_captured_length(tvb);
}
gint wimax_decode_dlmapc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *base_tree)
{
guint offset = 0;
proto_item *ti = NULL;
proto_item *ti_phy = NULL;
proto_item *ti_dlmap_ies = NULL;
proto_tree *tree = NULL;
proto_tree *ie_tree = NULL;
proto_tree *phy_tree = NULL;
gint ulmap_appended;
guint length, lennib, pad;
guint mac_len, dl_ie_count;
guint tvb_len = tvb_reported_length(tvb);
guint nib = 0;
guint32 mac_crc, calculated_crc;
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Compressed DL-MAP");
INC_CID = 0;
length = tvb_get_ntohs(tvb, offset) & 0x07FF;
mac_len = length;
lennib = BYTE_TO_NIB(length);
ulmap_appended = (tvb_get_guint8(tvb, offset) >> 4) & 1;
ti = proto_tree_add_protocol_format(base_tree, proto_mac_mgmt_msg_dlmap_decoder, tvb, offset, length, "Compressed DL-MAP (%u bytes)", length);
tree = proto_item_add_subtree(ti, ett_305);
proto_tree_add_item(tree, hf_dlmapc_compr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dlmapc_ulmap, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dlmapc_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dlmapc_len, tvb, offset, 2, ENC_BIG_ENDIAN);
{
phy_tree = proto_tree_add_subtree(tree, tvb, offset+2, 4, ett_275_phy, &ti_phy, "Phy Synchronization Field");
proto_tree_add_item(phy_tree, hf_dlmap_phy_fdur_ms, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_dlmap_phy_fdur_per_sec, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(phy_tree, hf_dlmap_phy_fnum, tvb, offset+3, 3, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_dlmap_dcd, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dlmapc_opid, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dlmapc_secid, tvb, offset+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dlmap_ofdma_sym, tvb, offset+9, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dlmapc_count, tvb, offset+10,1, ENC_BIG_ENDIAN);
dl_ie_count = tvb_get_guint8(tvb, offset + 10);
offset += 11;
nib = BYTE_TO_NIB(offset);
length -= 15;
if (dl_ie_count) {
ie_tree = proto_tree_add_subtree_format(tree, tvb, offset, length, ett_dlmap_ie, &ti_dlmap_ies, "DL-MAP IEs (%d bytes)", length);
while (dl_ie_count--) {
nib += dissect_dlmap_ie(ie_tree, pinfo, nib, tvb_len * 2, tvb);
}
pad = NIB_PADDING(nib);
if (pad) {
proto_tree_add_bytes_format(tree, hf_padding, tvb, NIBHI(nib,1), NULL, "Padding nibble");
nib++;
}
}
if (ulmap_appended) {
proto_item_set_text(ti, "Compressed DL-MAP (%u bytes)", NIB_ADDR(nib));
proto_item_set_text(ti_dlmap_ies, "DL-MAP IEs (%u bytes)",NIB_ADDR(nib)- offset);
proto_item_set_end(ti_dlmap_ies, tvb, NIB_ADDR(nib));
proto_item_set_end(ti, tvb, NIB_ADDR(nib));
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Compressed UL-MAP");
wimax_decode_ulmapc(base_tree, pinfo, nib, lennib - 8, tvb);
}
if (MIN(tvb_len, tvb_reported_length(tvb)) >= mac_len)
{
calculated_crc = wimax_mac_calc_crc32(tvb_get_ptr(tvb, 0, mac_len - (int)sizeof(mac_crc)), mac_len - (int)sizeof(mac_crc));
proto_tree_add_checksum(base_tree, tvb, mac_len - (int)sizeof(mac_crc), hf_mac_header_compress_dlmap_crc, hf_mac_header_compress_dlmap_crc_status, &ei_mac_header_compress_dlmap_crc,
pinfo, calculated_crc, ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
else
{
proto_tree_add_protocol_format(base_tree, proto_mac_mgmt_msg_dlmap_decoder, tvb, 0, tvb_len, "CRC missing - the frame is too short (%u bytes)", tvb_len);
}
return mac_len;
}
gint wimax_decode_dlmap_reduced_aas(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *base_tree)
{
guint offset = 0;
proto_item *ti = NULL;
proto_tree *tree = NULL;
gint ulmap_appended;
gint length;
gint tvb_len = tvb_reported_length(tvb);
gint bit = 0;
guint data, pad, mult;
gint numie = 1;
gint i;
guint16 calculated_crc;
gint smcs,cidi,dcdi,phyi,cqci;
length = tvb_len;
ti = proto_tree_add_protocol_format(base_tree, proto_mac_mgmt_msg_dlmap_decoder, tvb, offset, length, "Reduced_AAS_Private_DL-MAP");
tree = proto_item_add_subtree(ti, ett_308a);
VBIT(data, 3, hf_308a_cmi);
VBIT(ulmap_appended, 1, hf_308a_ulmap);
VBIT(data, 2, hf_308a_type);
VBIT(mult, 1, hf_308a_mult);
VBIT(data, 1, hf_308a_rsv);
if (mult) {
XBIT_HF_VALUE(numie, 8, hf_dlmap_reduced_aas_num_ie);
}
for (i = 0; i < numie; i++) {
XBIT_HF(2, hf_dlmap_reduced_aas_periodicity);
XBIT_HF_VALUE(cidi, 1, hf_dlmap_reduced_aas_cid_included);
XBIT_HF_VALUE(dcdi, 1, hf_dlmap_reduced_aas_dcd_count_included);
XBIT_HF_VALUE(phyi, 1, hf_dlmap_reduced_aas_phy_modification_included);
XBIT_HF_VALUE(cqci, 1, hf_dlmap_reduced_aas_cqich_control_indicator);
XBIT_HF(2, hf_dlmap_reduced_aas_encoding_mode);
XBIT_HF_VALUE(smcs, 1, hf_dlmap_reduced_aas_separate_mcs_enabled);
if (smcs) {
XBIT_HF(10, hf_dlmap_reduced_aas_duration);
XBIT_HF(4, hf_dlmap_reduced_aas_diuc);
XBIT_HF(2, hf_dlmap_reduced_aas_repetition_coding_indication);
}
if (cidi) {
XBIT_HF(16, hf_dlmap_reduced_aas_cid);
}
if (cqci) {
XBIT_HF(6, hf_dlmap_reduced_aas_allocation_index);
XBIT_HF(3, hf_dlmap_reduced_aas_report_period);
XBIT_HF(3, hf_dlmap_reduced_aas_frame_offset);
XBIT_HF(4, hf_dlmap_reduced_aas_report_duration);
XBIT_HF(2, hf_dlmap_reduced_aas_cqi_measurement_type);
XBIT_HF(2, hf_dlmap_reserved_uint);
}
if (dcdi) {
XBIT_HF(8, hf_dlmap_reduced_aas_dcd_count);
}
if (phyi) {
XBIT_HF(1, hf_dlmap_reduced_aas_preamble_select);
XBIT_HF(4, hf_dlmap_reduced_aas_preamble_shift_index);
XBIT_HF(1, hf_dlmap_reduced_aas_pilot_pattern_modifier);
XBIT_HF(2, hf_dlmap_reduced_aas_pilot_pattern_index);
}
XBIT_HF(3, hf_dlmap_reduced_aas_dl_frame_offset);
if (fusc) {
XBIT_HF(8, hf_dlmap_reduced_aas_zone_symbol_offset);
}
XBIT_HF(8, hf_dlmap_reduced_aas_ofdma_symbol_offset);
if (tusc) {
XBIT_HF(8, hf_dlmap_reduced_aas_subchannel_offset);
XBIT_HF(5, hf_dlmap_reduced_aas_num_ofdma_triple_symbol);
XBIT_HF(6, hf_dlmap_reduced_aas_num_subchannels);
} else {
XBIT_HF(6, hf_dlmap_reduced_aas_subchannel_offset);
XBIT_HF(7, hf_dlmap_reduced_aas_num_ofdma_symbols);
XBIT_HF(6, hf_dlmap_reduced_aas_num_subchannels);
}
XBIT_HF(4, hf_dlmap_reduced_aas_diuc_nep);
if (harq) {
XBIT_HF(1, hf_dlmap_reduced_aas_dl_harq_ack_bitmap);
XBIT_HF(6, hf_dlmap_reduced_aas_ack_allocation_index);
XBIT_HF(4, hf_dlmap_reduced_aas_acid);
XBIT_HF(1, hf_dlmap_reduced_aas_ai_sn);
if (ir_type) {
XBIT_HF(4, hf_dlmap_reduced_aas_nsch);
XBIT_HF(2, hf_dlmap_reduced_aas_spid);
XBIT_HF(2, hf_dlmap_reserved_uint);
}
}
XBIT_HF(2, hf_dlmap_reduced_aas_repetition_coding_indication);
if (ulmap_appended) {
bit += wimax_decode_ulmap_reduced_aas(tree, offset, length*8, tvb);
}
XBIT_HF(3, hf_dlmap_reserved_uint);
}
pad = BIT_PADDING(bit,8);
if (pad) {
proto_tree_add_bytes_format_value(tree, hf_padding, tvb, BITHI(bit,pad), NULL, "%d bits",pad);
bit += pad;
}
calculated_crc = wimax_mac_calc_crc16(tvb_get_ptr(tvb, 0, BIT_TO_BYTE(bit)), BIT_TO_BYTE(bit));
proto_tree_add_checksum(tree, tvb, BIT_ADDR(bit), hf_crc16, hf_crc16_status, &ei_crc16, pinfo, calculated_crc,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY);
bit += 16;
return BIT_TO_BYTE(bit) - offset;
}
void proto_register_mac_mgmt_msg_dlmap(void)
{
static hf_register_info hf[] =
{
{
&hf_dlmap_bsid,
{
"Base Station ID", "wmx.dlmap.bsid",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_dcd,
{
"DCD Count", "wmx.dlmap.dcd",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#if 0
{
&hf_dlmap_fch_expected,
{
"FCH Expected", "wmx.dlmap.fch_expected",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie,
{
"DL-MAP IE", "wmx.dlmap.ie",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#endif
{
&hf_dlmap_ie_boosting,
{
"Boosting", "wmx.dlmap.ie.boosting",
FT_UINT32, BASE_DEC, VALS(boost_msgs), 0x00038000, NULL, HFILL
}
},
{
&hf_dlmap_ie_boosting2,
{
"Boosting", "wmx.dlmap.ie.boosting",
FT_UINT32, BASE_DEC, VALS(boost_msgs), 0x0000E000, NULL, HFILL
}
},
{
&hf_dlmap_ie_cid,
{
"CID", "wmx.dlmap.ie.cid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_diuc,
{
"DIUC", "wmx.dlmap.ie.diuc",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_diuc_ext,
{
"Extended DIUC", "wmx.dlmap.ie.ext_diuc",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_diuc_ext2,
{
"Extended-2 DIUC", "wmx.dlmap.ie.ext2_diuc",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_reserved_extended2_duic,
{
"Reserved Extended-2 DIUC", "wmx.dlmap.ie.ext2_diuc_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_reserved_extended_duic,
{
"Reserved Extended DIUC", "wmx.dlmap.ie.ext_diuc_reserved",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_length,
{
"Length", "wmx.dlmap.ie.length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap,
{
"Bitmap", "wmx.dlmap.ie.bitmap",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap_cqi,
{
"CQI/ACK/Periodic Ranging region NI", "wmx.dlmap.ie.bitmap.cqi",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap_pusc,
{
"PUSC region NI", "wmx.dlmap.ie.bitmap.pusc",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap_opt_pusc,
{
"Optional PUSC region NI", "wmx.dlmap.ie.bitmap.opt_pusc",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap_amc,
{
"AMC region NI", "wmx.dlmap.ie.bitmap.amc",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap_aas,
{
"AAS region NI", "wmx.dlmap.ie.bitmap.aas",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap_periodic_ranging,
{
"Periodic Ranging region NI", "wmx.dlmap.ie.bitmap.periodic_ranging",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap_sounding,
{
"Sounding region NI", "wmx.dlmap.ie.bitmap.sounding",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_bitmap_mimo,
{
"MIMO region NI", "wmx.dlmap.ie.bitmap.mimo",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_ncid,
{
"N_CID", "wmx.dlmap.ie.ncid",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_ie_numsub,
{
"Number of Subchannels", "wmx.dlmap.ie.numsub",
FT_UINT32, BASE_DEC, NULL, 0x000000FC, NULL, HFILL
}
},
{
&hf_dlmap_ie_numsym,
{
"Number of OFDMA Symbols", "wmx.dlmap.ie.numsym",
FT_UINT32, BASE_DEC, NULL, 0x00007F00, NULL, HFILL
}
},
{
&hf_dlmap_ie_numsub2,
{
"Number of Subchannels", "wmx.dlmap.ie.numsub",
FT_UINT32, BASE_DEC, NULL, 0x000000FC, NULL, HFILL
}
},
{
&hf_dlmap_ie_numsym2,
{
"Number of OFDMA Symbols", "wmx.dlmap.ie.numsym",
FT_UINT32, BASE_DEC, NULL, 0x00001F00, NULL, HFILL
}
},
{
&hf_dlmap_ie_offsub,
{
"Subchannel Offset", "wmx.dlmap.ie.offsub",
FT_UINT32, BASE_DEC, NULL, 0x00FC0000, NULL, HFILL
}
},
{
&hf_dlmap_ie_offsym,
{
"OFDMA Symbol Offset", "wmx.dlmap.ie.offsym",
FT_UINT32, BASE_DEC, NULL, 0xFF000000, NULL, HFILL
}
},
{
&hf_dlmap_ie_offsub2,
{
"Subchannel Offset", "wmx.dlmap.ie.offsub",
FT_UINT32, BASE_DEC, NULL, 0x00FF0000, NULL, HFILL
}
},
{
&hf_dlmap_ie_offsym2,
{
"OFDMA Symbol Offset", "wmx.dlmap.ie.offsym",
FT_UINT32, BASE_DEC, NULL, 0xFF000000, NULL, HFILL
}
},
{
&hf_dlmap_ie_rep,
{
"Repetition Coding Indication", "wmx.dlmap.ie.rep",
FT_UINT32, BASE_DEC, VALS(rep_msgs), 0x00000003, NULL, HFILL
}
},
{
&hf_dlmap_ie_rep2,
{
"Repetition Coding Indication", "wmx.dlmap.ie.rep",
FT_UINT32, BASE_DEC, VALS(rep_msgs), 0x00000003, NULL, HFILL
}
},
{
&hf_dlmap_ofdma_sym,
{
"Num OFDMA Symbols", "wmx.dlmap.ofdma_sym",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_phy_fdur,
{
"Frame Duration Code", "wmx.dlmap.phy_fdur",
FT_UINT8, BASE_HEX, NULL, 0x00, NULL, HFILL
}
},
{
&hf_dlmap_phy_fdur_ms,
{
"Frame Duration", "wmx.dlmap.phy_fdur",
FT_UINT8, BASE_HEX, VALS(frame_duration), 0x00, NULL, HFILL
}
},
{
&hf_dlmap_phy_fdur_per_sec,
{
"Frames per second", "wmx.dlmap.phy_fdur",
FT_UINT8, BASE_HEX, VALS(frames_per_second), 0x00, NULL, HFILL
}
},
{
&hf_dlmap_phy_fnum,
{
"Frame Number", "wmx.dlmap.phy_fnum",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmapc_compr,
{
"Compressed map indicator", "wmx.dlmapc.compr",
FT_UINT16, BASE_DEC, NULL, 0xe000, NULL, HFILL
}
},
{
&hf_dlmapc_count,
{
"DL IE Count", "wmx.dlmapc.count",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmapc_len,
{
"Map message length", "wmx.dlmapc.len",
FT_UINT16, BASE_DEC, NULL, 0x07FF, NULL, HFILL
}
},
{
&hf_dlmapc_opid,
{
"Operator ID", "wmx.dlmapc.opid",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmapc_rsv,
{
"Reserved", "wmx.dlmapc.rsv",
FT_UINT16, BASE_DEC, NULL, 0x0800, NULL, HFILL
}
},
{
&hf_dlmapc_secid,
{
"Sector ID", "wmx.dlmapc.secid",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#if 0
{
&hf_dlmapc_sync,
{
"PHY Synchronization Field", "wmx.dlmapc.sync",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#endif
{
&hf_dlmapc_ulmap,
{
"UL-MAP appended", "wmx.dlmapc.ulmap",
FT_UINT16, BASE_DEC, NULL, 0x1000, NULL, HFILL
}
},
#if 0
{
&hf_dlmap_xie_diuc,
{
"Extended DIUC", "wmx.dlmapc.xie_diuc",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_dlmap_xie_len,
{
"Length", "wmx.dlmapc.xie_len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_109x_cmi,
{
"SUB-DL-UL-MAP map indicator", "wmx.dlul.cmi",
FT_UINT16, BASE_DEC, NULL, 0xE000, NULL, HFILL
}
},
{
&hf_109x_dl,
{
"DL HARQ ACK offset", "wmx.dlul.dl",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_109x_dlie,
{
"DL IE Count", "wmx.dlul.dlie",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_109x_haoi,
{
"HARQ ACK offset indicator", "wmx.dlul.haoi",
FT_UINT16, BASE_DEC, NULL, 0x0001, NULL, HFILL
}
},
{
&hf_109x_len,
{
"Map message length - The length is limited to 735 bytes at most", "wmx.dlul.len",
FT_UINT16, BASE_DEC, NULL, 0x1FF8, NULL, HFILL
}
},
{
&hf_109x_rcid,
{
"RCID_Type", "wmx.dlul.rcid",
FT_UINT16, BASE_DEC, NULL, 0x0006, NULL, HFILL
}
},
{
&hf_109x_subofs,
{
"Subchannel offset", "wmx.dlul.subofs",
FT_UINT8, BASE_DEC, NULL, 0xFE, NULL, HFILL
}
},
{
&hf_109x_symofs,
{
"OFDMA Symbol offset of subsequent sub-bursts "
"in this Sub-DL-UL-MAP message with reference to "
"the start of UL sub-frame.", "wmx.dlul.symofs",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
{
&hf_109x_rsv,
{
"Reserved", "wmx.dlul.rsv",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL
}
},
{
&hf_109x_ul,
{
"UL HARQ ACK offset", "wmx.dlul.ul",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
}
},
#endif
{
&hf_308a_cmi,
{
"Compressed map indicator", "wmx.dlmap.reduced_aas_private.cmi",
FT_UINT8, BASE_DEC, NULL, 0xe0, NULL, HFILL
}
},
{
&hf_308a_mult,
{
"Multiple IE", "wmx.dlmap.reduced_aas_private.mult",
FT_UINT8, BASE_DEC, NULL, 0x02, NULL, HFILL
}
},
{
&hf_308a_rsv,
{
"Reserved", "wmx.dlmap.reduced_aas_private.rsv",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL
}
},
{
&hf_308a_type,
{
"Compressed Map Type", "wmx.dlmap.reduced_aas_private.type",
FT_UINT8, BASE_DEC, NULL, 0x0d, NULL, HFILL
}
},
{
&hf_308a_ulmap,
{
"UL-MAP appended", "wmx.dlmap.reduced_aas_private.ulmap",
FT_UINT8, BASE_DEC, NULL, 0x10, NULL, HFILL
}
},
{
&hf_mac_header_compress_dlmap_crc,
{
"CRC", "wmx.compress_dlmap_crc",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_mac_header_compress_dlmap_crc_status,
{
"CRC Status", "wmx.compress_dlmap_crc.status",
FT_UINT8, BASE_NONE, VALS(plugin_proto_checksum_vals), 0x0, NULL, HFILL
}
},
{
&hf_crc16,
{
"CRC-16", "wmx.dlmap.crc16",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL
}
},
{
&hf_crc16_status,
{
"CRC-16 Status", "wmx.dlmap.crc16.status",
FT_UINT8, BASE_NONE, VALS(plugin_proto_checksum_vals), 0x0, NULL, HFILL
}
},
{
&hf_padding,
{
"Padding", "wmx.dlmap.padding",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_cid_mask,
{
"CID Mask", "wmx.dlmap.cid_mask",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{
&hf_reserved,
{
"Reserved", "wmx.dlmap.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
}
},
{ &hf_dlmap_rcid_ie_cid, { "CID", "wmx.dlmap.rcid_ie.cid", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_rcid_ie_prefix, { "Prefix", "wmx.dlmap.rcid_ie.prefix", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_rcid_ie_cid11, { "CID11", "wmx.dlmap.rcid_ie.cid11", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_rcid_ie_cid7, { "CID7", "wmx.dlmap.rcid_ie.cid7", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_rcid_ie_cid3, { "CID3", "wmx.dlmap.rcid_ie.cid3", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_dl_control_length, { "Length", "wmx.dlmap.dedicated_dl_control.length", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_dl_control_control_header, { "Control Header", "wmx.dlmap.dedicated_dl_control.control_header", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_dl_control_num_sdma_layers, { "Num SDMA Layers", "wmx.dlmap.dedicated_dl_control.num_sdma_layers", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_length, { "Length (nibbles)", "wmx.dlmap.dedicated_mimo_dl_control.length", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_control_header_mimo_control_info, { "Control Header (MIMO Control Info)", "wmx.dlmap.dedicated_mimo_dl_control.control_header_mimo_control_info", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_control_header_cqi_control_info, { "Control Header (CQI Control Info)", "wmx.dlmap.dedicated_mimo_dl_control.control_header_cqi_control_info", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_control_header_closed_mimo_control_info, { "Control Header (Closed MIMO Control Info)", "wmx.dlmap.dedicated_mimo_dl_control.control_header_closed_mimo_control_info", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_n_layer, { "N_layer", "wmx.dlmap.dedicated_mimo_dl_control.n_layer", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_matrix, { "Matrix", "wmx.dlmap.dedicated_mimo_dl_control.matrix", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_num_beamformed_streams, { "Num_Beamformed_Streams", "wmx.dlmap.dedicated_mimo_dl_control.num_beamformed_streams", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_period, { "Period", "wmx.dlmap.dedicated_mimo_dl_control.period", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_frame_offset, { "Frame Offset", "wmx.dlmap.dedicated_mimo_dl_control.frame_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_duration, { "Duration", "wmx.dlmap.dedicated_mimo_dl_control.duration", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_allocation_index, { "Allocation Index", "wmx.dlmap.dedicated_mimo_dl_control.allocation_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_cqich_num, { "CQICH_Num", "wmx.dlmap.dedicated_mimo_dl_control.cqich_num", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_feedback_type, { "Feedback type", "wmx.dlmap.dedicated_mimo_dl_control.feedback_type", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_antenna_grouping_index, { "Antenna Grouping Index", "wmx.dlmap.dedicated_mimo_dl_control.antenna_grouping_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_num_stream, { "Num_stream", "wmx.dlmap.dedicated_mimo_dl_control.num_stream", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_antenna_selection_index, { "Antenna Selection Index", "wmx.dlmap.dedicated_mimo_dl_control.antenna_selection_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dedicated_mimo_dl_control_codebook_precoding_index, { "Codebook Precoding Index", "wmx.dlmap.dedicated_mimo_dl_control.codebook_precoding_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_n_sub_burst_isi, { "N sub burst[ISI]", "wmx.dlmap.n_sub_burst_isi", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_n_ack_channel, { "N ACK channel", "wmx.dlmap.harq_chase.n_ack_channel", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_duration, { "Duration", "wmx.dlmap.harq_chase.duration", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_sub_burst_diuc_indicator, { "Sub-Burst DIUC Indicator", "wmx.dlmap.harq_chase.sub_burst_diuc_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reserved_uint, { "Reserved", "wmx.dlmap.reserved.uint", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_diuc, { "DIUC", "wmx.dlmap.harq_chase.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.harq_chase.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_acid, { "ACID", "wmx.dlmap.harq_chase.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_ai_sn, { "AI_SN", "wmx.dlmap.harq_chase.ai_sn", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_ack_disable, { "ACK disable", "wmx.dlmap.harq_chase.ack_disable", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_dedicated_dl_control_indicator, { "Dedicated DL Control Indicator", "wmx.dlmap.harq_chase.dedicated_dl_control_indicator", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_allocation_index, { "Allocation Index", "wmx.dlmap.harq_chase.allocation_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_period, { "Period (p)", "wmx.dlmap.harq_chase.period", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_chase_frame_offset, { "Frame offset", "wmx.dlmap.harq_chase.frame_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_n_ack_channel, { "N ACK channel", "wmx.dlmap.harq_ir_ctc.n_ack_channel", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_nep, { "N(EP)", "wmx.dlmap.harq_ir_ctc.n_ep", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_nsch, { "N(SCH)", "wmx.dlmap.harq_ir_ctc.n_sch", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_spid, { "SPID", "wmx.dlmap.harq_ir_ctc.spid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_acid, { "ACID", "wmx.dlmap.harq_ir_ctc.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_ai_sn, { "AI_SN", "wmx.dlmap.harq_ir_ctc.ai_sn", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_ack_disable, { "ACK disable", "wmx.dlmap.harq_ir_ctc.ack_disable", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_dedicated_dl_control_indicator, { "Dedicated DL Control Indicator", "wmx.dlmap.harq_ir_ctc.dedicated_dl_control_indicator", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_duration, { "Duration (d)", "wmx.dlmap.harq_ir_ctc.duration", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_allocation_index, { "Allocation Index", "wmx.dlmap.harq_ir_ctc.allocation_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_period, { "Period (p)", "wmx.dlmap.harq_ir_ctc.period", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_ctc_frame_offset, { "Frame offset", "wmx.dlmap.harq_ir_ctc.frame_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_n_ack_channel, { "N ACK channel", "wmx.dlmap.harq_ir_cc.n_ack_channel", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_duration, { "Duration", "wmx.dlmap.harq_ir_cc.duration", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_sub_burst_diuc_indicator, { "Sub-Burst DIUC Indicator", "wmx.dlmap.harq_ir_cc.sub_burst_diuc_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_diuc, { "DIUC", "wmx.dlmap.harq_ir_cc.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.harq_ir_cc.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_acid, { "ACID", "wmx.dlmap.harq_ir_cc.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_ai_sn, { "AI_SN", "wmx.dlmap.harq_ir_cc.ai_sn", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_spid, { "SPID", "wmx.dlmap.harq_ir_cc.spid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_ack_disable, { "ACK disable", "wmx.dlmap.harq_ir_cc.ack_disable", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_dedicated_dl_control_indicator, { "Dedicated DL Control Indicator", "wmx.dlmap.harq_ir_cc.dedicated_dl_control_indicator", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_allocation_index, { "Allocation Index", "wmx.dlmap.harq_ir_cc.allocation_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_period, { "Period (p)", "wmx.dlmap.harq_ir_cc.period", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ir_cc_frame_offset, { "Frame offset", "wmx.dlmap.harq_ir_cc.frame_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_n_ack_channel, { "N ACK channel", "wmx.dlmap.mimo_dl_chase_harq.n_ack_channel", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_mu_indicator, { "MU Indicator", "wmx.dlmap.mimo_dl_chase_harq.mu_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_dedicated_mimo_dl_control_indicator, { "Dedicated MIMO DL Control Indicator", "wmx.dlmap.mimo_dl_chase_harq.dedicated_mimo_dl_control_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_ack_disable, { "ACK Disable", "wmx.dlmap.mimo_dl_chase_harq.ack_disable", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_duration, { "Duration", "wmx.dlmap.mimo_dl_chase_harq.duration", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_diuc, { "DIUC", "wmx.dlmap.mimo_dl_chase_harq.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.mimo_dl_chase_harq.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_acid, { "ACID", "wmx.dlmap.mimo_dl_chase_harq.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_chase_harq_ai_sn, { "AI_SN", "wmx.dlmap.mimo_dl_chase_harq.ai_sn", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_n_ack_channel, { "N ACK channel", "wmx.dlmap.mimo_dl_ir_harq.n_ack_channel", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_mu_indicator, { "MU Indicator", "wmx.dlmap.mimo_dl_ir_harq.mu_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_dedicated_mimo_dl_control_indicator, { "Dedicated MIMO DL Control Indicator", "wmx.dlmap.mimo_dl_ir_harq.dedicated_mimo_dl_control_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_ack_disable, { "ACK Disable", "wmx.dlmap.mimo_dl_ir_harq.ack_disable", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_nsch, { "N(SCH)", "wmx.dlmap.mimo_dl_ir_harq.n_sch", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_nep, { "N(EP)", "wmx.dlmap.mimo_dl_ir_harq.n_ep", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_spid, { "SPID", "wmx.dlmap.mimo_dl_ir_harq.spid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_acid, { "ACID", "wmx.dlmap.mimo_dl_ir_harq.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_ai_sn, { "AI_SN", "wmx.dlmap.mimo_dl_ir_harq.ai_sn", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_n_ack_channel, { "N ACK channel", "wmx.dlmap.mimo_dl_ir_harq_cc.n_ack_channel", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_mu_indicator, { "MU Indicator", "wmx.dlmap.mimo_dl_ir_harq_cc.mu_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_dedicated_mimo_dl_control_indicator, { "Dedicated MIMO DL Control Indicator", "wmx.dlmap.mimo_dl_ir_harq_cc.dedicated_mimo_dl_control_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_ack_disable, { "ACK Disable", "wmx.dlmap.mimo_dl_ir_harq_cc.ack_disable", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_duration, { "Duration", "wmx.dlmap.mimo_dl_ir_harq_cc.duration", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_diuc, { "DIUC", "wmx.dlmap.mimo_dl_ir_harq_cc.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.mimo_dl_ir_harq_cc.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_acid, { "ACID", "wmx.dlmap.mimo_dl_ir_harq_cc.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_ai_sn, { "AI_SN", "wmx.dlmap.mimo_dl_ir_harq_cc.ai_sn", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_ir_harq_cc_spid, { "SPID", "wmx.dlmap.mimo_dl_ir_harq_cc.spid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_n_ack_channel, { "N ACK channel", "wmx.dlmap.mimo_dl_stc_harq.n_ack_channel", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_tx_count, { "TX Count", "wmx.dlmap.mimo_dl_stc_harq.tx_count", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_duration, { "Duration", "wmx.dlmap.mimo_dl_stc_harq.duration", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_sub_burst_offset_indication, { "Sub-burst offset indication", "wmx.dlmap.mimo_dl_stc_harq.sub_burst_offset_indication", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_sub_burst_offset, { "Sub-burst offset", "wmx.dlmap.mimo_dl_stc_harq.sub_burst_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_ack_disable, { "ACK Disable", "wmx.dlmap.mimo_dl_stc_harq.ack_disable", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_dedicated_mimo_dl_control_indicator, { "Dedicated MIMO DL Control Indicator", "wmx.dlmap.mimo_dl_stc_harq.dedicated_mimo_dl_control_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_diuc, { "DIUC", "wmx.dlmap.mimo_dl_stc_harq.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_repetition_coding_indication, { "Repetition coding Indication", "wmx.dlmap.mimo_dl_stc_harq.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mimo_dl_stc_harq_acid, { "ACID", "wmx.dlmap.mimo_dl_stc_harq.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_extended_2_diuc, { "Extended-2 DIUC", "wmx.dlmap.mbs_map.extended_2_diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_mbs_zone_identifier, { "MBS Zone identifier", "wmx.dlmap.mbs_map.mbs_zone_identifier", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_macro_diversity_enhanced, { "Macro diversity enhanced", "wmx.dlmap.mbs_map.macro_diversity_enhanced", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_permutation, { "Permutation", "wmx.dlmap.mbs_map.permutation", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_dl_permbase, { "DL_PermBase", "wmx.dlmap.mbs_map.dl_permbase", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_prbs_id, { "PRBS_ID", "wmx.dlmap.mbs_map.prbs_id", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_ofdma_symbol_offset, { "OFDMA_Symbol_Offset", "wmx.dlmap.mbs_map.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_diuc_change_indication, { "DIUC_change_indication", "wmx.dlmap.mbs_map.diuc_change_indication", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_boosting, { "Boosting", "wmx.dlmap.mbs_map.boosting", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_diuc, { "DIUC", "wmx.dlmap.mbs_map.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_num_subchannels, { "No. Subchannels", "wmx.dlmap.mbs_map.num_subchannels", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_num_ofdma_symbols, { "No. OFDMA Symbols", "wmx.dlmap.mbs_map.num_ofdma_symbols", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.mbs_map.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_cid, { "CID", "wmx.dlmap.mbs_map.cid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_ofdma_symbols_offset, { "OFDMA Symbols Offset", "wmx.dlmap.mbs_map.ofdma_symbols_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_subchannel_offset, { "Subchannel offset", "wmx.dlmap.mbs_map.subchannel_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_slc_3_indication, { "SLC_3_indication", "wmx.dlmap.mbs_map.slc_3_indication", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_mbs_map_next_mbs_map_ie_frame_offset, { "Next MBS_MAP_IE frame offset", "wmx.dlmap.mbs_map.next_mbs_map_ie_frame_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_skip_extended_2_diuc, { "Extended-2 DIUC", "wmx.dlmap.skip.extended_2_diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_skip_mode, { "Mode", "wmx.dlmap.skip.mode", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_extended_2_diuc, { "Extended-2 DIUC", "wmx.dlmap.harq_dl_map.extended_2_diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_rcid_type, { "RCID_Type", "wmx.dlmap.harq_dl_map.rcid_type", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_boosting, { "Boosting", "wmx.dlmap.harq_dl_map.boosting", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_region_id_use_indicator, { "Region_ID use indicator", "wmx.dlmap.harq_dl_map.region_id_use_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_ofdma_symbol_offset, { "OFDMA symbol offset", "wmx.dlmap.harq_dl_map.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_subchannel_offset, { "Subchannel offset", "wmx.dlmap.harq_dl_map.subchannel_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_number_of_ofdma_symbols, { "Number of OFDMA symbols", "wmx.dlmap.harq_dl_map.number_of_ofdma_symbols", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_number_of_subchannels, { "Number of subchannels", "wmx.dlmap.harq_dl_map.number_of_subchannels", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_rectangular_sub_burst_indicator, { "Rectangular Sub-Burst Indicator", "wmx.dlmap.harq_dl_map.rectangular_sub_burst_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_region_id, { "Region_ID", "wmx.dlmap.harq_dl_map.region_id", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_mode, { "Mode", "wmx.dlmap.harq_dl_map.mode", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_sub_burst_ie_length, { "Sub-burst IE Length", "wmx.dlmap.harq_dl_map.sub_burst_ie_length", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_dl_map_reserved_mode, { "Reserved Mode", "wmx.dlmap.harq_dl_map.reserved_mode", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_ack_bitmap_data, { "Bitmap data", "wmx.dlmap.harq_ack.bitmap_data", FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_enhanced_dl_map_extended_2_diuc, { "Extended-2 DIUC", "wmx.dlmap.enhanced_dl_map.extended_2_diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_enhanced_dl_map_num_assignment, { "Num_Assignment", "wmx.dlmap.enhanced_dl_map.num_assignment", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_enhanced_dl_map_n_cid, { "N_CID", "wmx.dlmap.enhanced_dl_map.n_cid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_enhanced_dl_map_cid, { "CID", "wmx.dlmap.enhanced_dl_map.cid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_enhanced_dl_map_diuc, { "DIUC", "wmx.dlmap.enhanced_dl_map.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_enhanced_dl_map_boosting, { "Boosting", "wmx.dlmap.enhanced_dl_map.boosting", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_enhanced_dl_map_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.enhanced_dl_map.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_enhanced_dl_map_region_id, { "Region_ID", "wmx.dlmap.enhanced_dl_map.region_id", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_extended_2_diuc, { "Extended-2 DIUC", "wmx.dlmap.aas_sdma_dl.extended_2_diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_rcid_type, { "RCID_Type", "wmx.dlmap.aas_sdma_dl.rcid_type", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_num_burst_region, { "Num_Burst_Region", "wmx.dlmap.aas_sdma_dl.num_burst_region", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_ofdma_symbol_offset, { "OFDMA Symbol Offset", "wmx.dlmap.aas_sdma_dl.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_subchannel_offset, { "Subchannel offset", "wmx.dlmap.aas_sdma_dl.subchannel_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_num_ofdma_triple_symbols, { "No. OFDMA triple symbols", "wmx.dlmap.aas_sdma_dl.num_ofdma_triple_symbols", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_num_subchannels, { "No. subchannels", "wmx.dlmap.aas_sdma_dl.num_subchannels", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_number_of_users, { "Number of Users", "wmx.dlmap.aas_sdma_dl.number_of_users", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_encoding_mode, { "Encoding Mode", "wmx.dlmap.aas_sdma_dl.encoding_mode", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_cqich_allocation, { "CQICH Allocation", "wmx.dlmap.aas_sdma_dl.cqich_allocation", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_ackch_allocation, { "ACKCH Allocation", "wmx.dlmap.aas_sdma_dl.ackch_allocation", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_pilot_pattern_modifier, { "Pilot Pattern Modifier", "wmx.dlmap.aas_sdma_dl.pilot_pattern_modifier", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_preamble_modifier_index, { "Preamble Modifier Index", "wmx.dlmap.aas_sdma_dl.preamble_modifier_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_pilot_pattern, { "Pilot Pattern", "wmx.dlmap.aas_sdma_dl.pilot_pattern", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_diuc, { "DIUC", "wmx.dlmap.aas_sdma_dl.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.aas_sdma_dl.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_ack_ch_index, { "ACK CH Index", "wmx.dlmap.aas_sdma_dl.ack_ch_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_acid, { "ACID", "wmx.dlmap.aas_sdma_dl.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_ai_sn, { "AI_SN", "wmx.dlmap.aas_sdma_dl.ai_sn", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_nep, { "N(EP)", "wmx.dlmap.aas_sdma_dl.n_ep", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_nsch, { "N(SCH)", "wmx.dlmap.aas_sdma_dl.n_sch", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_spid, { "SPID", "wmx.dlmap.aas_sdma_dl.spid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_allocation_index, { "Allocation Index", "wmx.dlmap.aas_sdma_dl.allocation_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_period, { "Period (p)", "wmx.dlmap.aas_sdma_dl.period", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_frame_offset, { "Frame offset", "wmx.dlmap.aas_sdma_dl.frame_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_sdma_dl_duration, { "Duration (d)", "wmx.dlmap.aas_sdma_dl.duration", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_channel_measurement_channel_nr, { "Channel Nr", "wmx.dlmap.channel_measurement.channel_nr", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_channel_measurement_ofdma_symbol_offset, { "OFDMA Symbol Offset", "wmx.dlmap.channel_measurement.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_channel_measurement_cid, { "CID", "wmx.dlmap.channel_measurement.cid", FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_ofdma_symbol_offset, { "OFDMA Symbol Offset", "wmx.dlmap.stc_zone.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_permutations, { "Permutations", "wmx.dlmap.stc_zone.permutations", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_use_all_sc_indicator, { "Use All SC indicator", "wmx.dlmap.stc_zone.use_all_sc_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_stc, { "STC", "wmx.dlmap.stc_zone.stc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_matrix_indicator, { "Matrix indicator", "wmx.dlmap.stc_zone.matrix_indicator", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_dl_permbase, { "DL_PermBase", "wmx.dlmap.stc_zone.dl_permbase", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_prbs_id, { "PRBS_ID", "wmx.dlmap.stc_zone.prbs_id", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_amc_type, { "AMC type", "wmx.dlmap.stc_zone.amc_type", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_midamble_presence, { "Midamble Presence", "wmx.dlmap.stc_zone.midamble_presence", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_midamble_boosting, { "Midamble Boosting", "wmx.dlmap.stc_zone.midamble_boosting", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_2_3_antenna_select, { "2/3 antenna select", "wmx.dlmap.stc_zone.2_3_antenna_select", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_stc_zone_dedicated_pilots, { "Dedicated Pilots", "wmx.dlmap.stc_zone.dedicated_pilots", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_dl_ofdma_symbol_offset, { "OFDMA Symbol Offset", "wmx.dlmap.aas_dl.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_dl_permutation, { "Permutation", "wmx.dlmap.aas_dl.permutation", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_dl_dl_permbase, { "DL_PermBase", "wmx.dlmap.aas_dl.dl_permbase", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_dl_downlink_preamble_config, { "Downlink_preamble_config", "wmx.dlmap.aas_dl.downlink_preamble_config", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_dl_preamble_type, { "Preamble type", "wmx.dlmap.aas_dl.preamble_type", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_dl_prbs_id, { "PRBS_ID", "wmx.dlmap.aas_dl.prbs_id", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_aas_dl_diversity_map, { "Diversity Map", "wmx.dlmap.aas_dl.diversity_map", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_segment, { "Segment", "wmx.dlmap.data_location_another_bs.segment", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_used_subchannels, { "Used subchannels", "wmx.dlmap.data_location_another_bs.used_subchannels", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_diuc, { "DIUC", "wmx.dlmap.data_location_another_bs.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_frame_advance, { "Frame Advance", "wmx.dlmap.data_location_another_bs.frame_advance", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_ofdma_symbol_offset, { "OFDMA Symbol Offset", "wmx.dlmap.data_location_another_bs.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_subchannel_offset, { "Subchannel Offset", "wmx.dlmap.data_location_another_bs.subchannel_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_boosting, { "Boosting", "wmx.dlmap.data_location_another_bs.boosting", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_preamble_index, { "Preamble Index", "wmx.dlmap.data_location_another_bs.preamble_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_num_ofdma_symbols, { "No. OFDMA Symbols", "wmx.dlmap.data_location_another_bs.num_ofdma_symbols", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_num_subchannels, { "No. Subchannels", "wmx.dlmap.data_location_another_bs.num_subchannels", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.data_location_another_bs.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_data_location_another_bs_cid, { "CID", "wmx.dlmap.data_location_another_bs.cid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_map_pointer_diuc, { "DIUC", "wmx.dlmap.harq_map_pointer.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_map_pointer_num_slots, { "No. Slots", "wmx.dlmap.harq_map_pointer.num_slots", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_map_pointer_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.harq_map_pointer.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_map_pointer_map_version, { "Map Version", "wmx.dlmap.harq_map_pointer.map_version", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_map_pointer_idle_users, { "Idle users", "wmx.dlmap.harq_map_pointer.idle_users", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_map_pointer_sleep_users, { "Sleep users", "wmx.dlmap.harq_map_pointer.sleep_users", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_harq_map_pointer_cid_mask_length, { "CID Mask Length", "wmx.dlmap.harq_map_pointer.cid_mask_length", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_phymod_dl_preamble_modifier_type, { "Preamble Modifier Type", "wmx.dlmap.phymod_dl.preamble_modifier_type", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_phymod_dl_preamble_frequency_shift_index, { "Preamble frequency shift index", "wmx.dlmap.phymod_dl.preamble_frequency_shift_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_phymod_dl_preamble_time_shift_index, { "Preamble Time Shift Index", "wmx.dlmap.phymod_dl.preamble_time_shift_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_phymod_dl_pilot_pattern_modifier, { "Pilot Pattern Modifier", "wmx.dlmap.phymod_dl.pilot_pattern_modifier", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_phymod_dl_pilot_pattern_index, { "Pilot Pattern Index", "wmx.dlmap.phymod_dl.pilot_pattern_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_broadcast_ctrl_ptr_dcd_ucd_transmission_frame, { "DCD_UCD Transmission Frame", "wmx.dlmap.broadcast_ctrl_ptr.dcd_ucd_transmission_frame", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_broadcast_ctrl_ptr_skip_broadcast_system_update, { "Skip Broadcast_System_Update", "wmx.dlmap.broadcast_ctrl_ptr.skip_broadcast_system_update", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_broadcast_ctrl_ptr_broadcast_system_update_type, { "Broadcast_System_Update_Type", "wmx.dlmap.broadcast_ctrl_ptr.broadcast_system_update_type", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_broadcast_ctrl_ptr_broadcast_system_update_transmission_frame, { "Broadcast_System_Update_Transmission_Frame", "wmx.dlmap.broadcast_ctrl_ptr.broadcast_system_update_transmission_frame", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_cid, { "CID", "wmx.dlmap.dl_pusc_burst_allocation.cid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_diuc, { "DIUC", "wmx.dlmap.dl_pusc_burst_allocation.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_segment, { "Segment", "wmx.dlmap.dl_pusc_burst_allocation.segment", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_boosting, { "Boosting", "wmx.dlmap.dl_pusc_burst_allocation.boosting", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_idcell, { "IDcell", "wmx.dlmap.dl_pusc_burst_allocation.idcell", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_dl_permbase, { "DL_PermBase", "wmx.dlmap.dl_pusc_burst_allocation.dl_permbase", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_prbs_id, { "PRBS_ID", "wmx.dlmap.dl_pusc_burst_allocation.prbs_id", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_repetition_coding_indication, { "Repetition coding indication", "wmx.dlmap.dl_pusc_burst_allocation.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_used_subchannels, { "Used Subchannels", "wmx.dlmap.dl_pusc_burst_allocation.used_subchannels", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_ofdma_symbol_offset, { "OFDMA symbol offset", "wmx.dlmap.dl_pusc_burst_allocation.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_num_ofdma_symbols, { "# OFDMA symbols", "wmx.dlmap.dl_pusc_burst_allocation.num_ofdma_symbols", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_subchannel_offset, { "Subchannel offset", "wmx.dlmap.dl_pusc_burst_allocation.subchannel_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_dl_pusc_burst_allocation_num_subchannels, { "# subchannels", "wmx.dlmap.dl_pusc_burst_allocation.num_subchannels", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_pusc_asca_alloc_diuc, { "DIUC", "wmx.dlmap.pusc_asca_alloc.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_pusc_asca_alloc_short_basic_cid, { "Short Basic CID", "wmx.dlmap.pusc_asca_alloc.short_basic_cid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_pusc_asca_alloc_ofdma_symbol_offset, { "OFDMA Symbol offset", "wmx.dlmap.pusc_asca_alloc.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_pusc_asca_alloc_subchannel_offset, { "Subchannel offset", "wmx.dlmap.pusc_asca_alloc.subchannel_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_pusc_asca_alloc_num_ofdma_symbols, { "# OFDMA Symbols", "wmx.dlmap.pusc_asca_alloc.num_ofdma_symbols", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_pusc_asca_alloc_num_symbols, { "# Symbols", "wmx.dlmap.pusc_asca_alloc.num_symbols", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_pusc_asca_alloc_repetition_coding_information, { "Repetition Coding Information", "wmx.dlmap.pusc_asca_alloc.repetition_coding_information", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_pusc_asca_alloc_permutation_id, { "Permutation ID", "wmx.dlmap.pusc_asca_alloc.permutation_id", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_num_ie, { "NUM IE", "wmx.dlmap.reduced_aas.num_ie", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_periodicity, { "Periodicity", "wmx.dlmap.reduced_aas.periodicity", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_cid_included, { "CID Included", "wmx.dlmap.reduced_aas.cid_included", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_dcd_count_included, { "DCD Count Included", "wmx.dlmap.reduced_aas.dcd_count_included", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_phy_modification_included, { "PHY modification included", "wmx.dlmap.reduced_aas.phy_modification_included", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_cqich_control_indicator, { "CQICH control indicator", "wmx.dlmap.reduced_aas.cqich_control_indicator", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_encoding_mode, { "Encoding Mode", "wmx.dlmap.reduced_aas.encoding_mode", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_separate_mcs_enabled, { "Separate MCS Enabled", "wmx.dlmap.reduced_aas.separate_mcs_enabled", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_duration, { "Duration", "wmx.dlmap.reduced_aas.duration", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_diuc, { "DIUC", "wmx.dlmap.reduced_aas.diuc", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_repetition_coding_indication, { "Repetition Coding Indication", "wmx.dlmap.reduced_aas.repetition_coding_indication", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_cid, { "CID", "wmx.dlmap.reduced_aas.cid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_allocation_index, { "Allocation Index", "wmx.dlmap.reduced_aas.allocation_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_report_period, { "Report Period", "wmx.dlmap.reduced_aas.report_period", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_frame_offset, { "Frame Offset", "wmx.dlmap.reduced_aas.frame_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_report_duration, { "Report Duration", "wmx.dlmap.reduced_aas.report_duration", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_cqi_measurement_type, { "CQI Measurement Type", "wmx.dlmap.reduced_aas.cqi_measurement_type", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_dcd_count, { "DCD Count", "wmx.dlmap.reduced_aas.dcd_count", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_preamble_select, { "Preamble Select", "wmx.dlmap.reduced_aas.preamble_select", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_preamble_shift_index, { "Preamble Shift Index", "wmx.dlmap.reduced_aas.preamble_shift_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_pilot_pattern_modifier, { "Pilot Pattern Modifier", "wmx.dlmap.reduced_aas.pilot_pattern_modifier", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_pilot_pattern_index, { "Pilot Pattern Index", "wmx.dlmap.reduced_aas.pilot_pattern_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_dl_frame_offset, { "DL Frame Offset", "wmx.dlmap.reduced_aas.dl_frame_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_zone_symbol_offset, { "Zone Symbol Offset", "wmx.dlmap.reduced_aas.zone_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_ofdma_symbol_offset, { "OFDMA Symbol Offset", "wmx.dlmap.reduced_aas.ofdma_symbol_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_subchannel_offset, { "Subchannel Offset", "wmx.dlmap.reduced_aas.subchannel_offset", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_num_ofdma_triple_symbol, { "No. OFDMA triple symbol", "wmx.dlmap.reduced_aas.num_ofdma_triple_symbol", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_num_subchannels, { "No. subchannels", "wmx.dlmap.reduced_aas.num_subchannels", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_num_ofdma_symbols, { "No. OFDMA symbols", "wmx.dlmap.reduced_aas.num_ofdma_symbols", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_diuc_nep, { "DIUC/N(EP)", "wmx.dlmap.reduced_aas.diuc_nep", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_dl_harq_ack_bitmap, { "DL HARQ ACK bitmap", "wmx.dlmap.reduced_aas.dl_harq_ack_bitmap", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_ack_allocation_index, { "ACK Allocation Index", "wmx.dlmap.reduced_aas.ack_allocation_index", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_acid, { "ACID", "wmx.dlmap.reduced_aas.acid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_ai_sn, { "AI_SN", "wmx.dlmap.reduced_aas.ai_sn", FT_UINT8, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_nsch, { "N(SCH)", "wmx.dlmap.reduced_aas.nsch", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
{ &hf_dlmap_reduced_aas_spid, { "SPID", "wmx.dlmap.reduced_aas.spid", FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }},
};
static gint *ett[] =
{
&ett_dlmap,
&ett_dlmap_ie,
&ett_109x,
&ett_109x_dl,
&ett_109x_ul,
&ett_275_phy,
&ett_275_1,
&ett_277,
&ett_277b,
&ett_278,
&ett_279,
&ett_280,
&ett_281,
&ett_282,
&ett_283,
&ett_284,
&ett_285,
&ett_286,
&ett_286a,
&ett_286b,
&ett_286c,
&ett_286d,
&ett_286e,
&ett_286f,
&ett_286g,
&ett_286h,
&ett_286i,
&ett_286j,
&ett_286k,
&ett_286l,
&ett_286m,
&ett_286n,
&ett_286o,
&ett_286p,
&ett_286q,
&ett_286r,
&ett_286s,
&ett_286t,
&ett_286u,
&ett_286v,
&ett_286w,
&ett_286x,
&ett_286y,
&ett_286z,
&ett_305,
&ett_308a,
};
static ei_register_info ei[] = {
{ &ei_dlmap_not_implemented, { "wmx.dlmap.not_implemented", PI_UNDECODED, PI_WARN, "Not implemented", EXPFILL }},
{ &ei_crc16, { "wmx.dlmap.bad_checksum", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
{ &ei_mac_header_compress_dlmap_crc, { "wmx.compress_dlmap.bad_checksum", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
};
expert_module_t* expert_mac_mgmt_msg_dlmap;
proto_mac_mgmt_msg_dlmap_decoder = proto_register_protocol (
"WiMax DLMAP Messages",
"WiMax DLMAP",
"wmx.dlmap"
);
proto_register_field_array(proto_mac_mgmt_msg_dlmap_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mac_mgmt_msg_dlmap = expert_register_protocol(proto_mac_mgmt_msg_dlmap_decoder);
expert_register_field_array(expert_mac_mgmt_msg_dlmap, ei, array_length(ei));
}
void proto_reg_handoff_mac_mgmt_msg_dlmap(void)
{
dissector_handle_t dlmap_handle;
dlmap_handle = create_dissector_handle(dissect_mac_mgmt_msg_dlmap_decoder, proto_mac_mgmt_msg_dlmap_decoder);
dissector_add_uint("wmx.mgmtmsg", MAC_MGMT_MSG_DL_MAP, dlmap_handle);
}
