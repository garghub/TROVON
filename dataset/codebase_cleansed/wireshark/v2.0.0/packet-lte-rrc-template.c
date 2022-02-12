static void
lte_rrc_timeConnFailure_r10_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%ums (%u)", 100*v, v);
}
static void
lte_rrc_m_r12_fmt(gchar *s, guint32 v)
{
if (v == 255) {
g_snprintf(s, ITEM_LABEL_LENGTH, "255 <= f(Nr) (255)");
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u <= f(Nr) < %u (%u)", v, v+1, v);
}
}
static void
lte_rrc_ue_RxTxTimeDiffResult_fmt(gchar *s, guint32 v)
{
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "T < 2Ts (0)");
} else if (v < 2048) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs <= T < %uTs (%u)", v*2, (v+1)*2, v);
} else if (v < 4095) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs <= T < %uTs (%u)", (v*8)-12288, ((v+1)*8)-12288, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "20472Ts <= T (4095)");
}
}
static void
lte_rrc_call_dissector(dissector_handle_t handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
TRY {
call_dissector(handle, tvb, pinfo, tree);
}
CATCH_BOUNDS_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
}
static lte_rrc_private_data_t* lte_rrc_get_private_data(asn1_ctx_t *actx)
{
if (actx->private_data != NULL) {
return (lte_rrc_private_data_t*)actx->private_data;
}
else {
lte_rrc_private_data_t* new_struct =
(lte_rrc_private_data_t*)wmem_alloc0(wmem_packet_scope(), sizeof(lte_rrc_private_data_t));
actx->private_data = new_struct;
return new_struct;
}
}
static drx_config_t* private_data_get_drx_config(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return &private_data->drx_config;
}
static drb_mapping_t* private_data_get_drb_mapping(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return &private_data->drb_mapping;
}
static guint8 private_data_get_rat_type(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return private_data->rat_type;
}
static void private_data_set_rat_type(asn1_ctx_t *actx, guint8 rat_type)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
private_data->rat_type = rat_type;
}
static guint8 private_data_get_rat_target_type(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return private_data->target_rat_type;
}
static void private_data_set_rat_target_type(asn1_ctx_t *actx, guint8 target_rat_type)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
private_data->target_rat_type = target_rat_type;
}
static guint8 private_data_get_si_or_psi_geran(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return private_data->si_or_psi_geran;
}
static void private_data_set_si_or_psi_geran(asn1_ctx_t *actx, guint8 si_or_psi_geran)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
private_data->si_or_psi_geran = si_or_psi_geran;
}
static guint16 private_data_get_message_identifier(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return private_data->message_identifier;
}
static void private_data_set_message_identifier(asn1_ctx_t *actx, guint16 message_identifier)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
private_data->message_identifier = message_identifier;
}
static guint16 private_data_get_warning_message_segment_type(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return private_data->warning_message_segment_type;
}
static void private_data_set_warning_message_segment_type(asn1_ctx_t *actx, guint8 segment_type)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
private_data->warning_message_segment_type = segment_type;
}
static guint16 private_data_get_warning_message_segment_number(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return private_data->warning_message_segment_number;
}
static void private_data_set_warning_message_segment_number(asn1_ctx_t *actx, guint8 segment_number)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
private_data->warning_message_segment_number = segment_number;
}
static guint8 private_data_get_ra_preambles(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return private_data->ra_preambles;
}
static void private_data_set_ra_preambles(asn1_ctx_t *actx, guint8 ra_preambles)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
private_data->ra_preambles = ra_preambles;
}
static pdcp_security_info_t* private_data_pdcp_security_algorithms(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return &private_data->pdcp_security;
}
static meas_capabilities_item_band_mappings_t* private_data_meas_capabilities_item_band_mappings(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return &private_data->meas_capabilities_item_band_mappings;
}
static void set_freq_band_indicator(guint32 value, asn1_ctx_t *actx)
{
meas_capabilities_item_band_mappings_t *mappings = private_data_meas_capabilities_item_band_mappings(actx);
if (mappings->number_of_bands_set < 256) {
mappings->band_by_item[mappings->number_of_bands_set++] = (guint16)value;
}
}
static void remove_last_freq_band_indicator(asn1_ctx_t *actx)
{
meas_capabilities_item_band_mappings_t *mappings = private_data_meas_capabilities_item_band_mappings(actx);
if ((mappings->number_of_bands_set > 0) && (mappings->number_of_bands_set < 256)) {
mappings->number_of_bands_set--;
}
}
static simult_pucch_pusch_cell_type private_data_get_simult_pucch_pusch_cell_type(asn1_ctx_t *actx)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
return private_data->cell_type;
}
static void private_data_set_simult_pucch_pusch_cell_type(asn1_ctx_t *actx, simult_pucch_pusch_cell_type cell_type)
{
lte_rrc_private_data_t *private_data = (lte_rrc_private_data_t*)lte_rrc_get_private_data(actx);
private_data->cell_type = cell_type;
}
static void
lte_rrc_localTimeOffset_fmt(gchar *s, guint32 v)
{
gint32 time_offset = (gint32) v;
g_snprintf(s, ITEM_LABEL_LENGTH, "UTC time %c %dhr %dmin (%d)",
(time_offset < 0) ? '-':'+', abs(time_offset) >> 2,
(abs(time_offset) & 0x03) * 15, time_offset);
}
static void
dissect_lte_rrc_warningMessageSegment(tvbuff_t *warning_msg_seg_tvb, proto_tree *tree, packet_info *pinfo, guint8 dataCodingScheme)
{
guint32 offset;
guint8 nb_of_pages, length, *str;
proto_item *ti;
tvbuff_t *cb_data_page_tvb, *cb_data_tvb;
int i;
nb_of_pages = tvb_get_guint8(warning_msg_seg_tvb, 0);
ti = proto_tree_add_uint(tree, hf_lte_rrc_warningMessageSegment_nb_pages, warning_msg_seg_tvb, 0, 1, nb_of_pages);
if (nb_of_pages > 15) {
expert_add_info_format(pinfo, ti, &ei_lte_rrc_number_pages_le15,
"Number of pages should be <=15 (found %u)", nb_of_pages);
nb_of_pages = 15;
}
for (i = 0, offset = 1; i < nb_of_pages; i++) {
length = tvb_get_guint8(warning_msg_seg_tvb, offset+82);
cb_data_page_tvb = tvb_new_subset_length(warning_msg_seg_tvb, offset, length);
cb_data_tvb = dissect_cbs_data(dataCodingScheme, cb_data_page_tvb, tree, pinfo, 0);
if (cb_data_tvb) {
str = tvb_get_string_enc(wmem_packet_scope(), cb_data_tvb, 0, tvb_reported_length(cb_data_tvb), ENC_UTF_8|ENC_NA);
proto_tree_add_string_format(tree, hf_lte_rrc_warningMessageSegment_decoded_page, warning_msg_seg_tvb, offset, 83,
str, "Decoded Page %u: %s", i+1, str);
}
offset += 83;
}
}
static void
dissect_lte_rrc_featureGroupIndicators(tvbuff_t *featureGroupIndicators_tvb, asn1_ctx_t *actx)
{
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lte_rrc_featureGroupIndicators);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_1, featureGroupIndicators_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_2, featureGroupIndicators_tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_3, featureGroupIndicators_tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_4, featureGroupIndicators_tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_5, featureGroupIndicators_tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_6, featureGroupIndicators_tvb, 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_7, featureGroupIndicators_tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_8, featureGroupIndicators_tvb, 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_9, featureGroupIndicators_tvb, 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_10, featureGroupIndicators_tvb, 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_11, featureGroupIndicators_tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_12, featureGroupIndicators_tvb, 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_13, featureGroupIndicators_tvb, 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_14, featureGroupIndicators_tvb, 13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_15, featureGroupIndicators_tvb, 14, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_16, featureGroupIndicators_tvb, 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_17, featureGroupIndicators_tvb, 16, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_18, featureGroupIndicators_tvb, 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_19, featureGroupIndicators_tvb, 18, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_20, featureGroupIndicators_tvb, 19, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_21, featureGroupIndicators_tvb, 20, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_22, featureGroupIndicators_tvb, 21, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_23, featureGroupIndicators_tvb, 22, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_24, featureGroupIndicators_tvb, 23, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_25, featureGroupIndicators_tvb, 24, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_26, featureGroupIndicators_tvb, 25, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_27, featureGroupIndicators_tvb, 26, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_28, featureGroupIndicators_tvb, 27, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_29, featureGroupIndicators_tvb, 28, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_30, featureGroupIndicators_tvb, 29, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_31, featureGroupIndicators_tvb, 30, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_32, featureGroupIndicators_tvb, 31, 1, ENC_BIG_ENDIAN);
}
static void
dissect_lte_rrc_featureGroupIndRel10(tvbuff_t *featureGroupIndRel10_tvb, asn1_ctx_t *actx)
{
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lte_rrc_featureGroupIndRel10);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_101, featureGroupIndRel10_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_102, featureGroupIndRel10_tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_103, featureGroupIndRel10_tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_104, featureGroupIndRel10_tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_105, featureGroupIndRel10_tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_106, featureGroupIndRel10_tvb, 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_107, featureGroupIndRel10_tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_108, featureGroupIndRel10_tvb, 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_109, featureGroupIndRel10_tvb, 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_110, featureGroupIndRel10_tvb, 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_111, featureGroupIndRel10_tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_112, featureGroupIndRel10_tvb, 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_113, featureGroupIndRel10_tvb, 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_114, featureGroupIndRel10_tvb, 13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_115, featureGroupIndRel10_tvb, 14, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_116, featureGroupIndRel10_tvb, 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_117, featureGroupIndRel10_tvb, 16, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_118, featureGroupIndRel10_tvb, 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_119, featureGroupIndRel10_tvb, 18, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_120, featureGroupIndRel10_tvb, 19, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_121, featureGroupIndRel10_tvb, 20, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_122, featureGroupIndRel10_tvb, 21, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_123, featureGroupIndRel10_tvb, 22, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_124, featureGroupIndRel10_tvb, 23, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_125, featureGroupIndRel10_tvb, 24, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_126, featureGroupIndRel10_tvb, 25, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_127, featureGroupIndRel10_tvb, 26, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_128, featureGroupIndRel10_tvb, 27, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_129, featureGroupIndRel10_tvb, 28, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_130, featureGroupIndRel10_tvb, 29, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_131, featureGroupIndRel10_tvb, 30, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_132, featureGroupIndRel10_tvb, 31, 1, ENC_BIG_ENDIAN);
}
static void
dissect_lte_rrc_featureGroupIndRel9Add(tvbuff_t *featureGroupIndRel9Add_tvb, asn1_ctx_t *actx)
{
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lte_rrc_featureGroupIndRel9Add);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_33, featureGroupIndRel9Add_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_34, featureGroupIndRel9Add_tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_35, featureGroupIndRel9Add_tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_36, featureGroupIndRel9Add_tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_37, featureGroupIndRel9Add_tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_38, featureGroupIndRel9Add_tvb, 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_39, featureGroupIndRel9Add_tvb, 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_40, featureGroupIndRel9Add_tvb, 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_41, featureGroupIndRel9Add_tvb, 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_42, featureGroupIndRel9Add_tvb, 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_43, featureGroupIndRel9Add_tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_44, featureGroupIndRel9Add_tvb, 11, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_45, featureGroupIndRel9Add_tvb, 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_46, featureGroupIndRel9Add_tvb, 13, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_47, featureGroupIndRel9Add_tvb, 14, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_48, featureGroupIndRel9Add_tvb, 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_49, featureGroupIndRel9Add_tvb, 16, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_50, featureGroupIndRel9Add_tvb, 17, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_51, featureGroupIndRel9Add_tvb, 18, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_52, featureGroupIndRel9Add_tvb, 19, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_53, featureGroupIndRel9Add_tvb, 20, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_54, featureGroupIndRel9Add_tvb, 21, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_55, featureGroupIndRel9Add_tvb, 22, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_56, featureGroupIndRel9Add_tvb, 23, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_57, featureGroupIndRel9Add_tvb, 24, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_58, featureGroupIndRel9Add_tvb, 25, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_59, featureGroupIndRel9Add_tvb, 26, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_60, featureGroupIndRel9Add_tvb, 27, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_61, featureGroupIndRel9Add_tvb, 28, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_62, featureGroupIndRel9Add_tvb, 29, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_63, featureGroupIndRel9Add_tvb, 30, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lte_rrc_eutra_cap_feat_group_ind_64, featureGroupIndRel9Add_tvb, 31, 1, ENC_BIG_ENDIAN);
}
static guint32 drx_lookup_onDurationTimer(guint32 idx)
{
static const guint32 vals[] = {1,2,3,4,5,6,8,10,20,30,40,50,60,80,100,200};
if (idx < (sizeof(vals)/sizeof(guint32))) {
return vals[idx];
}
return (sizeof(vals)/(sizeof(guint32)) - 1);
}
static guint32 drx_lookup_inactivityTimer(guint32 idx)
{
static const guint32 vals[] = {
1,2,3,4,5,6,8,10,20,30,40,50,60,80,100,200,300, 500,750,1280,1920,2560,0
};
if (idx < (sizeof(vals)/sizeof(guint32))) {
return vals[idx];
}
return (sizeof(vals)/(sizeof(guint32)) - 1);
}
static guint32 drx_lookup_retransmissionTimer(guint32 idx)
{
static const guint32 vals[] = {1,2,4,6,8,16,24,33};
if (idx < (sizeof(vals)/sizeof(guint32))) {
return vals[idx];
}
return (sizeof(vals)/(sizeof(guint32)) - 1);
}
static guint32 drx_lookup_longCycle(guint32 idx)
{
static const guint32 vals[] = {
10,20,32,40,64,80,128,160,256,320,512,640,1024,1280,2048,2560
};
if (idx < (sizeof(vals)/sizeof(guint32))) {
return vals[idx];
}
return (sizeof(vals)/(sizeof(guint32)) - 1);
}
static guint32 drx_lookup_longCycle_v1130(guint32 idx)
{
static const guint32 vals[] = {
60,70
};
if (idx < (sizeof(vals)/sizeof(guint32))) {
return vals[idx];
}
return (sizeof(vals)/(sizeof(guint32)) - 1);
}
static guint32 drx_lookup_shortCycle(guint32 idx)
{
static const guint32 vals[] = {
2,5,8,10,16,20,32,40,64,80,128,160,256,320,512,640
};
if (idx < (sizeof(vals)/sizeof(guint32))) {
return vals[idx];
}
return (sizeof(vals)/(sizeof(guint32)) - 1);
}
static void drx_check_config_sane(drx_config_t *config, asn1_ctx_t *actx)
{
if (config->onDurationTimer >= config->longCycle) {
expert_add_info_format(actx->pinfo, actx->created_item, &ei_lte_rrc_invalid_drx_config,
"OnDurationTimer (%u) should be less than long cycle (%u)",
config->onDurationTimer, config->longCycle);
}
if (config->shortCycleConfigured) {
if (config->shortCycle >= config->longCycle) {
expert_add_info_format(actx->pinfo, actx->created_item, &ei_lte_rrc_invalid_drx_config,
"Short DRX cycle (%u) must be shorter than long cycle (%u)",
config->shortCycle, config->longCycle);
}
else if (config->shortCycle && ((config->longCycle % config->shortCycle) != 0)) {
expert_add_info_format(actx->pinfo, actx->created_item, &ei_lte_rrc_invalid_drx_config,
"Short DRX cycle (%u) must divide the long cycle (%u) exactly",
config->shortCycle, config->longCycle);
}
if (config->onDurationTimer >= config->shortCycle) {
expert_add_info_format(actx->pinfo, actx->created_item, &ei_lte_rrc_invalid_drx_config,
"OnDurationTimer (%u) should not be longer than the short cycle (%u)",
config->onDurationTimer, config->shortCycle);
}
}
}
static void sr_lookup_configindex(guint32 config_index, guint16 *periodicity, guint16 *offset)
{
if (config_index < 5) {
*periodicity = 5;
*offset = config_index;
} else if (config_index < 15) {
*periodicity = 10;
*offset = config_index - 5;
}
else if (config_index < 35) {
*periodicity = 20;
*offset = config_index - 15;
}
else if (config_index < 75) {
*periodicity = 40;
*offset = config_index - 35;
}
else if (config_index < 155) {
*periodicity = 80;
*offset = config_index - 75;
}
else if (config_index < 157) {
*periodicity = 2;
*offset = config_index - 155;
}
else {
*periodicity = 1;
*offset = 0;
}
}
static void
dissect_lte_rrc_DL_CCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC DL_CCCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_DL_CCCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
dissect_lte_rrc_DL_DCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC DL_DCCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_DL_DCCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
dissect_lte_rrc_UL_CCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC UL_CCCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_UL_CCCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
dissect_lte_rrc_UL_DCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC UL_DCCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_UL_DCCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
dissect_lte_rrc_BCCH_BCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC BCCH_BCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_BCCH_BCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
dissect_lte_rrc_BCCH_DL_SCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC DL_SCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_BCCH_DL_SCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
dissect_lte_rrc_PCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC PCCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_PCCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
dissect_lte_rrc_MCCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC MCCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_MCCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
dissect_lte_rrc_Handover_Preparation_Info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE_HO_Prep_Info");
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_INFO, "HandoverPreparationInformation");
col_set_writable(pinfo->cinfo, FALSE);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_lte_rrc_HandoverPreparationInformation_PDU(tvb, pinfo, lte_rrc_tree, NULL);
col_set_writable(pinfo->cinfo, TRUE);
}
static void
dissect_lte_rrc_SBCCH_SL_BCH(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lte_rrc_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LTE RRC SBCCH_SL_BCH");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lte_rrc, tvb, 0, -1, ENC_NA);
lte_rrc_tree = proto_item_add_subtree(ti, ett_lte_rrc);
dissect_SBCCH_SL_BCH_Message_PDU(tvb, pinfo, lte_rrc_tree, NULL);
}
static void
lte_rrc_init_protocol(void)
{
lte_rrc_etws_cmas_dcs_hash = g_hash_table_new(g_direct_hash, g_direct_equal);
lte_rrc_system_info_value_changed_hash = g_hash_table_new(g_direct_hash, g_direct_equal);
reassembly_table_init(&lte_rrc_sib11_reassembly_table,
&addresses_reassembly_table_functions);
reassembly_table_init(&lte_rrc_sib12_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
lte_rrc_cleanup_protocol(void)
{
g_hash_table_destroy(lte_rrc_etws_cmas_dcs_hash);
g_hash_table_destroy(lte_rrc_system_info_value_changed_hash);
reassembly_table_destroy(&lte_rrc_sib11_reassembly_table);
reassembly_table_destroy(&lte_rrc_sib12_reassembly_table);
}
void proto_register_lte_rrc(void) {
static hf_register_info hf[] = {
#include "packet-lte-rrc-hfarr.c"
{ &hf_lte_rrc_eutra_cap_feat_group_ind_1,
{ "Indicator 1", "lte-rrc.eutra_cap_feat_group_ind_1",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_1_val), 0,
"EUTRA Feature Group Indicator 1", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_2,
{ "Indicator 2", "lte-rrc.eutra_cap_feat_group_ind_2",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_2_val), 0,
"EUTRA Feature Group Indicator 2", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_3,
{ "Indicator 3", "lte-rrc.eutra_cap_feat_group_ind_3",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_3_val), 0,
"EUTRA Feature Group Indicator 3", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_4,
{ "Indicator 4", "lte-rrc.eutra_cap_feat_group_ind_4",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_4_val), 0,
"EUTRA Feature Group Indicator 4", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_5,
{ "Indicator 5", "lte-rrc.eutra_cap_feat_group_ind_5",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_5_val), 0,
"EUTRA Feature Group Indicator 5", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_6,
{ "Indicator 6", "lte-rrc.eutra_cap_feat_group_ind_6",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_6_val), 0,
"EUTRA Feature Group Indicator 6", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_7,
{ "Indicator 7", "lte-rrc.eutra_cap_feat_group_ind_7",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_7_val), 0,
"EUTRA Feature Group Indicator 7", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_8,
{ "Indicator 8", "lte-rrc.eutra_cap_feat_group_ind_8",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_8_val), 0,
"EUTRA Feature Group Indicator 8", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_9,
{ "Indicator 9", "lte-rrc.eutra_cap_feat_group_ind_9",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_9_val), 0,
"EUTRA Feature Group Indicator 9", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_10,
{ "Indicator 10", "lte-rrc.eutra_cap_feat_group_ind_10",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_10_val), 0,
"EUTRA Feature Group Indicator 10", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_11,
{ "Indicator 11", "lte-rrc.eutra_cap_feat_group_ind_11",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_11_val), 0,
"EUTRA Feature Group Indicator 11", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_12,
{ "Indicator 12", "lte-rrc.eutra_cap_feat_group_ind_12",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_12_val), 0,
"EUTRA Feature Group Indicator 12", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_13,
{ "Indicator 13", "lte-rrc.eutra_cap_feat_group_ind_13",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_13_val), 0,
"EUTRA Feature Group Indicator", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_14,
{ "Indicator 14", "lte-rrc.eutra_cap_feat_group_ind_14",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_14_val), 0,
"EUTRA Feature Group Indicator 14", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_15,
{ "Indicator 15", "lte-rrc.eutra_cap_feat_group_ind_15",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_15_val), 0,
"EUTRA Feature Group Indicator 15", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_16,
{ "Indicator 16", "lte-rrc.eutra_cap_feat_group_ind_16",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_16_val), 0,
"EUTRA Feature Group Indicator 16", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_17,
{ "Indicator 17", "lte-rrc.eutra_cap_feat_group_ind_17",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_17_val), 0,
"EUTRA Feature Group Indicator 17", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_18,
{ "Indicator 18", "lte-rrc.eutra_cap_feat_group_ind_18",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_18_val), 0,
"EUTRA Feature Group Indicator 18", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_19,
{ "Indicator 19", "lte-rrc.eutra_cap_feat_group_ind_19",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_19_val), 0,
"EUTRA Feature Group Indicator 19", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_20,
{ "Indicator 20", "lte-rrc.eutra_cap_feat_group_ind_20",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_20_val), 0,
"EUTRA Feature Group Indicator 20", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_21,
{ "Indicator 21", "lte-rrc.eutra_cap_feat_group_ind_21",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_21_val), 0,
"EUTRA Feature Group Indicator 21", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_22,
{ "Indicator 22", "lte-rrc.eutra_cap_feat_group_ind_22",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_22_val), 0,
"EUTRA Feature Group Indicator 22", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_23,
{ "Indicator 23", "lte-rrc.eutra_cap_feat_group_ind_23",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_23_val), 0,
"EUTRA Feature Group Indicator 23", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_24,
{ "Indicator 24", "lte-rrc.eutra_cap_feat_group_ind_24",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_24_val), 0,
"EUTRA Feature Group Indicator 24", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_25,
{ "Indicator 25", "lte-rrc.eutra_cap_feat_group_ind_25",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_25_val), 0,
"EUTRA Feature Group Indicator 25", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_26,
{ "Indicator 26", "lte-rrc.eutra_cap_feat_group_ind_26",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_26_val), 0,
"EUTRA Feature Group Indicator 26", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_27,
{ "Indicator 27", "lte-rrc.eutra_cap_feat_group_ind_27",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_27_val), 0,
"EUTRA Feature Group Indicator 27", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_28,
{ "Indicator 28", "lte-rrc.eutra_cap_feat_group_ind_28",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_28_val), 0,
"EUTRA Feature Group Indicator 28", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_29,
{ "Indicator 29", "lte-rrc.eutra_cap_feat_group_ind_29",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_29_val), 0,
"EUTRA Feature Group Indicator 29", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_30,
{ "Indicator 30", "lte-rrc.eutra_cap_feat_group_ind_30",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_30_val), 0,
"EUTRA Feature Group Indicator 30", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_31,
{ "Indicator 31", "lte-rrc.eutra_cap_feat_group_ind_31",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_31_val), 0,
"EUTRA Feature Group Indicator 31", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_32,
{ "Indicator 32", "lte-rrc.eutra_cap_feat_group_ind_32",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_32_val), 0,
"EUTRA Feature Group Indicator 32", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_33,
{ "Indicator 33", "lte-rrc.eutra_cap_feat_group_ind_33",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_33_val), 0,
"EUTRA Feature Group Indicator 33", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_34,
{ "Indicator 34", "lte-rrc.eutra_cap_feat_group_ind_34",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_34_val), 0,
"EUTRA Feature Group Indicator 34", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_35,
{ "Indicator 35", "lte-rrc.eutra_cap_feat_group_ind_35",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_35_val), 0,
"EUTRA Feature Group Indicator 35", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_36,
{ "Indicator 36", "lte-rrc.eutra_cap_feat_group_ind_36",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_36_val), 0,
"EUTRA Feature Group Indicator 36", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_37,
{ "Indicator 37", "lte-rrc.eutra_cap_feat_group_ind_37",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_37_val), 0,
"EUTRA Feature Group Indicator 37", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_38,
{ "Indicator 38", "lte-rrc.eutra_cap_feat_group_ind_38",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_38_val), 0,
"EUTRA Feature Group Indicator 38", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_39,
{ "Indicator 39", "lte-rrc.eutra_cap_feat_group_ind_39",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_39_val), 0,
"EUTRA Feature Group Indicator 39", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_40,
{ "Indicator 40", "lte-rrc.eutra_cap_feat_group_ind_40",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_40_val), 0,
"EUTRA Feature Group Indicator 40", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_41,
{ "Indicator 41", "lte-rrc.eutra_cap_feat_group_ind_41",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_41_val), 0,
"EUTRA Feature Group Indicator 41", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_42,
{ "Indicator 42", "lte-rrc.eutra_cap_feat_group_ind_42",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_42_val), 0,
"EUTRA Feature Group Indicator 42", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_43,
{ "Indicator 43", "lte-rrc.eutra_cap_feat_group_ind_43",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_43_val), 0,
"EUTRA Feature Group Indicator 43", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_44,
{ "Indicator 44", "lte-rrc.eutra_cap_feat_group_ind_44",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_44_val), 0,
"EUTRA Feature Group Indicator 44", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_45,
{ "Indicator 45", "lte-rrc.eutra_cap_feat_group_ind_45",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_45_val), 0,
"EUTRA Feature Group Indicator 45", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_46,
{ "Indicator 46", "lte-rrc.eutra_cap_feat_group_ind_46",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_46_val), 0,
"EUTRA Feature Group Indicator 46", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_47,
{ "Indicator 47", "lte-rrc.eutra_cap_feat_group_ind_47",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_47_val), 0,
"EUTRA Feature Group Indicator 47", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_48,
{ "Indicator 48", "lte-rrc.eutra_cap_feat_group_ind_48",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_48_val), 0,
"EUTRA Feature Group Indicator 48", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_49,
{ "Indicator 49", "lte-rrc.eutra_cap_feat_group_ind_49",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_49_val), 0,
"EUTRA Feature Group Indicator 49", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_50,
{ "Indicator 50", "lte-rrc.eutra_cap_feat_group_ind_50",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_50_val), 0,
"EUTRA Feature Group Indicator 50", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_51,
{ "Indicator 51", "lte-rrc.eutra_cap_feat_group_ind_51",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_51_val), 0,
"EUTRA Feature Group Indicator 51", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_52,
{ "Indicator 52", "lte-rrc.eutra_cap_feat_group_ind_52",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_52_val), 0,
"EUTRA Feature Group Indicator 52", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_53,
{ "Indicator 53", "lte-rrc.eutra_cap_feat_group_ind_53",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_53_val), 0,
"EUTRA Feature Group Indicator 53", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_54,
{ "Indicator 54", "lte-rrc.eutra_cap_feat_group_ind_54",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_54_val), 0,
"EUTRA Feature Group Indicator 54", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_55,
{ "Indicator 55", "lte-rrc.eutra_cap_feat_group_ind_55",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_55_val), 0,
"EUTRA Feature Group Indicator 55", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_56,
{ "Indicator 56", "lte-rrc.eutra_cap_feat_group_ind_56",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_56_val), 0,
"EUTRA Feature Group Indicator 56", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_57,
{ "Indicator 57", "lte-rrc.eutra_cap_feat_group_ind_57",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_57_val), 0,
"EUTRA Feature Group Indicator 57", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_58,
{ "Indicator 58", "lte-rrc.eutra_cap_feat_group_ind_58",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_58_val), 0,
"EUTRA Feature Group Indicator 58", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_59,
{ "Indicator 59", "lte-rrc.eutra_cap_feat_group_ind_59",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_59_val), 0,
"EUTRA Feature Group Indicator 59", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_60,
{ "Indicator 60", "lte-rrc.eutra_cap_feat_group_ind_60",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_60_val), 0,
"EUTRA Feature Group Indicator 60", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_61,
{ "Indicator 61", "lte-rrc.eutra_cap_feat_group_ind_61",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_61_val), 0,
"EUTRA Feature Group Indicator 61", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_62,
{ "Indicator 62", "lte-rrc.eutra_cap_feat_group_ind_62",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_62_val), 0,
"EUTRA Feature Group Indicator 62", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_63,
{ "Indicator 63", "lte-rrc.eutra_cap_feat_group_ind_63",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_63_val), 0,
"EUTRA Feature Group Indicator 63", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_64,
{ "Indicator 64", "lte-rrc.eutra_cap_feat_group_ind_64",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_64_val), 0,
"EUTRA Feature Group Indicator 64", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_101,
{ "Indicator 101", "lte-rrc.eutra_cap_feat_group_ind_101",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_101_val), 0,
"EUTRA Feature Group Indicator 101", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_102,
{ "Indicator 102", "lte-rrc.eutra_cap_feat_group_ind_102",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_102_val), 0,
"EUTRA Feature Group Indicator 102", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_103,
{ "Indicator 103", "lte-rrc.eutra_cap_feat_group_ind_103",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_103_val), 0,
"EUTRA Feature Group Indicator 103", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_104,
{ "Indicator 104", "lte-rrc.eutra_cap_feat_group_ind_104",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_104_val), 0,
"EUTRA Feature Group Indicator 104", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_105,
{ "Indicator 105", "lte-rrc.eutra_cap_feat_group_ind_105",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_105_val), 0,
"EUTRA Feature Group Indicator 105", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_106,
{ "Indicator 106", "lte-rrc.eutra_cap_feat_group_ind_106",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_106_val), 0,
"EUTRA Feature Group Indicator 106", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_107,
{ "Indicator 107", "lte-rrc.eutra_cap_feat_group_ind_107",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_107_val), 0,
"EUTRA Feature Group Indicator 107", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_108,
{ "Indicator 108", "lte-rrc.eutra_cap_feat_group_ind_108",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_108_val), 0,
"EUTRA Feature Group Indicator 108", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_109,
{ "Indicator 109", "lte-rrc.eutra_cap_feat_group_ind_109",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_109_val), 0,
"EUTRA Feature Group Indicator 109", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_110,
{ "Indicator 110", "lte-rrc.eutra_cap_feat_group_ind_110",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_110_val), 0,
"EUTRA Feature Group Indicator 110", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_111,
{ "Indicator 111", "lte-rrc.eutra_cap_feat_group_ind_111",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_111_val), 0,
"EUTRA Feature Group Indicator 111", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_112,
{ "Indicator 112", "lte-rrc.eutra_cap_feat_group_ind_112",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_112_val), 0,
"EUTRA Feature Group Indicator 112", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_113,
{ "Indicator 113", "lte-rrc.eutra_cap_feat_group_ind_113",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_113_val), 0,
"EUTRA Feature Group Indicator 113", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_114,
{ "Indicator 114", "lte-rrc.eutra_cap_feat_group_ind_114",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_114_val), 0,
"EUTRA Feature Group Indicator 114", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_115,
{ "Indicator 115", "lte-rrc.eutra_cap_feat_group_ind_115",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_115_val), 0,
"EUTRA Feature Group Indicator 115", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_116,
{ "Indicator 116", "lte-rrc.eutra_cap_feat_group_ind_116",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_116_val), 0,
"EUTRA Feature Group Indicator 116", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_117,
{ "Indicator 117", "lte-rrc.eutra_cap_feat_group_ind_117",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_117_val), 0,
"EUTRA Feature Group Indicator 117", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_118,
{ "Indicator 118", "lte-rrc.eutra_cap_feat_group_ind_118",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_118_val), 0,
"EUTRA Feature Group Indicator 118", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_119,
{ "Indicator 119", "lte-rrc.eutra_cap_feat_group_ind_119",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_119_val), 0,
"EUTRA Feature Group Indicator 119", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_120,
{ "Indicator 120", "lte-rrc.eutra_cap_feat_group_ind_120",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_120_val), 0,
"EUTRA Feature Group Indicator 120", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_121,
{ "Indicator 121", "lte-rrc.eutra_cap_feat_group_ind_121",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_121_val), 0,
"EUTRA Feature Group Indicator 121", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_122,
{ "Indicator 122", "lte-rrc.eutra_cap_feat_group_ind_122",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_122_val), 0,
"EUTRA Feature Group Indicator 122", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_123,
{ "Indicator 123", "lte-rrc.eutra_cap_feat_group_ind_123",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_123_val), 0,
"EUTRA Feature Group Indicator 123", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_124,
{ "Indicator 124", "lte-rrc.eutra_cap_feat_group_ind_124",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_124_val), 0,
"EUTRA Feature Group Indicator 124", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_125,
{ "Indicator 125", "lte-rrc.eutra_cap_feat_group_ind_125",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_125_val), 0,
"EUTRA Feature Group Indicator 125", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_126,
{ "Indicator 126", "lte-rrc.eutra_cap_feat_group_ind_126",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_126_val), 0,
"EUTRA Feature Group Indicator 126", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_127,
{ "Indicator 127", "lte-rrc.eutra_cap_feat_group_ind_127",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_127_val), 0,
"EUTRA Feature Group Indicator 127", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_128,
{ "Indicator 128", "lte-rrc.eutra_cap_feat_group_ind_128",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_128_val), 0,
"EUTRA Feature Group Indicator 128", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_129,
{ "Indicator 129", "lte-rrc.eutra_cap_feat_group_ind_129",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_129_val), 0,
"EUTRA Feature Group Indicator 129", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_130,
{ "Indicator 130", "lte-rrc.eutra_cap_feat_group_ind_130",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_130_val), 0,
"EUTRA Feature Group Indicator 130", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_131,
{ "Indicator 131", "lte-rrc.eutra_cap_feat_group_ind_131",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_131_val), 0,
"EUTRA Feature Group Indicator 131", HFILL }},
{ &hf_lte_rrc_eutra_cap_feat_group_ind_132,
{ "Indicator 132", "lte-rrc.eutra_cap_feat_group_ind_132",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_eutra_cap_feat_group_ind_132_val), 0,
"EUTRA Feature Group Indicator 132", HFILL }},
{ &hf_lte_rrc_serialNumber_gs,
{ "Geographical Scope", "lte-rrc.serialNumber.gs",
FT_UINT16, BASE_DEC, VALS(lte_rrc_serialNumber_gs_vals), 0xc000,
NULL, HFILL }},
{ &hf_lte_rrc_serialNumber_msg_code,
{ "Message Code", "lte-rrc.serialNumber.msg_code",
FT_UINT16, BASE_DEC, NULL, 0x3ff0,
NULL, HFILL }},
{ &hf_lte_rrc_serialNumber_upd_nb,
{ "Update Number", "lte-rrc.serialNumber.upd_nb",
FT_UINT16, BASE_DEC, NULL, 0x000f,
NULL, HFILL }},
{ &hf_lte_rrc_warningType_value,
{ "Warning Type Value", "lte-rrc.warningType.value",
FT_UINT16, BASE_DEC, VALS(lte_rrc_warningType_vals), 0xfe00,
NULL, HFILL }},
{ &hf_lte_rrc_warningType_emergency_user_alert,
{ "Emergency User Alert", "lte-rrc.warningType.emergency_user_alert",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0100,
NULL, HFILL }},
{ &hf_lte_rrc_warningType_popup,
{ "Popup", "lte-rrc.warningType.popup",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0080,
NULL, HFILL }},
{ &hf_lte_rrc_warningMessageSegment_nb_pages,
{ "Number of Pages", "lte-rrc.warningMessageSegment.nb_pages",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_warningMessageSegment_decoded_page,
{ "Decoded Page", "lte-rrc.warningMessageSegment.decoded_page",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_interBandTDD_CA_WithDifferentConfig_bit1,
{ "Bit 1", "lte-rrc.interBandTDD_CA_WithDifferentConfig.bit1",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_interBandTDD_CA_WithDifferentConfig_bit1_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_interBandTDD_CA_WithDifferentConfig_bit2,
{ "Bit 2", "lte-rrc.interBandTDD_CA_WithDifferentConfig.bit2",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_interBandTDD_CA_WithDifferentConfig_bit2_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_tdd_FDD_CA_PCellDuplex_r12_bit1,
{ "Bit 1", "lte-rrc.tdd_FDD_CA_PCellDuplex_r12.bit1",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_tdd_FDD_CA_PCellDuplex_r12_bit1_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_tdd_FDD_CA_PCellDuplex_r12_bit2,
{ "Bit 2", "lte-rrc.tdd_FDD_CA_PCellDuplex_r12.bit2",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_tdd_FDD_CA_PCellDuplex_r12_bit2_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_sr_config_periodicity,
{ "Periodicity", "lte-rrc.sr_Periodicity",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_lte_rrc_sr_config_subframe_offset,
{ "Subframe Offset", "lte-rrc.sr_SubframeOffset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_lte_rrc_cdma_time,
{ "CDMA time", "lte-rrc.cdma_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL }},
{ &hf_lte_rrc_utc_time,
{ "UTC time", "lte-rrc.utc_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL }},
{ &hf_lte_rrc_local_time,
{ "Local time", "lte-rrc.local_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL }},
{ &hf_lte_rrc_absolute_time,
{ "Absolute time", "lte-rrc.absolute_time",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_lte_rrc_transmissionModeList_r12_tm1,
{ "TM1", "lte-rrc.transmissionModeList_r12.tm1",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_transmissionModeList_r12_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_transmissionModeList_r12_tm2,
{ "TM2", "lte-rrc.transmissionModeList_r12.tm2",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_transmissionModeList_r12_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_transmissionModeList_r12_tm3,
{ "TM3", "lte-rrc.transmissionModeList_r12.tm3",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_transmissionModeList_r12_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_transmissionModeList_r12_tm4,
{ "TM4", "lte-rrc.transmissionModeList_r12.tm4",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_transmissionModeList_r12_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_transmissionModeList_r12_tm6,
{ "TM6", "lte-rrc.transmissionModeList_r12.tm6",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_transmissionModeList_r12_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_transmissionModeList_r12_tm8,
{ "TM8", "lte-rrc.transmissionModeList_r12.tm8",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_transmissionModeList_r12_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_transmissionModeList_r12_tm9,
{ "TM9", "lte-rrc.transmissionModeList_r12.tm9",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_transmissionModeList_r12_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_transmissionModeList_r12_tm10,
{ "TM10", "lte-rrc.transmissionModeList_r12.tm10",
FT_BOOLEAN, BASE_NONE, TFS(&lte_rrc_transmissionModeList_r12_val), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_0,
{ "MPR/A-MPR behavior 0", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_1,
{ "MPR/A-MPR behavior 1", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_2,
{ "MPR/A-MPR behavior 2", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_2",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_3,
{ "MPR/A-MPR behavior 3", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_3",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_4,
{ "MPR/A-MPR behavior 4", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_4",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_5,
{ "MPR/A-MPR behavior 5", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_5",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_6,
{ "MPR/A-MPR behavior 6", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_6",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_7,
{ "MPR/A-MPR behavior 7", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_7",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_8,
{ "MPR/A-MPR behavior 8", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_8",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_9,
{ "MPR/A-MPR behavior 9", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_9",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_10,
{ "MPR/A-MPR behavior 10", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_10",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_11,
{ "MPR/A-MPR behavior 11", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_11",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_12,
{ "MPR/A-MPR behavior 12", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_12",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_13,
{ "MPR/A-MPR behavior 13", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_13",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_14,
{ "MPR/A-MPR behavior 14", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_14",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_15,
{ "MPR/A-MPR behavior 15", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_15",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_16,
{ "MPR/A-MPR behavior 16", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_16",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_17,
{ "MPR/A-MPR behavior 17", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_17",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_18,
{ "MPR/A-MPR behavior 18", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_18",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_19,
{ "MPR/A-MPR behavior 19", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_19",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_20,
{ "MPR/A-MPR behavior 20", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_20",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_21,
{ "MPR/A-MPR behavior 21", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_21",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_22,
{ "MPR/A-MPR behavior 22", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_22",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_23,
{ "MPR/A-MPR behavior 23", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_23",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_24,
{ "MPR/A-MPR behavior 24", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_24",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_25,
{ "MPR/A-MPR behavior 25", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_25",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_26,
{ "MPR/A-MPR behavior 26", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_26",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_27,
{ "MPR/A-MPR behavior 27", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_27",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_28,
{ "MPR/A-MPR behavior 28", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_28",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_29,
{ "MPR/A-MPR behavior 29", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_29",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_30,
{ "MPR/A-MPR behavior 30", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_30",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_modifiedMPR_Behavior_r10_mpr_ampr_31,
{ "MPR/A-MPR behavior 31", "lte-rrc.modifiedMPR_Behavior_r10.mpr_ampr_31",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_fragments,
{ "Fragments", "lte-rrc.warningMessageSegment.fragments",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_fragment,
{ "Fragment", "lte-rrc.warningMessageSegment.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_fragment_overlap,
{ "Fragment Overlap", "lte-rrc.warningMessageSegment.fragment_overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_fragment_overlap_conflict,
{ "Fragment Overlap Conflict", "lte-rrc.warningMessageSegment.fragment_overlap_conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_fragment_multiple_tails,
{ "Fragment Multiple Tails", "lte-rrc.warningMessageSegment.fragment_multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_fragment_too_long_fragment,
{ "Too Long Fragment", "lte-rrc.warningMessageSegment.fragment_too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_fragment_error,
{ "Fragment Error", "lte-rrc.warningMessageSegment.fragment_error",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_fragment_count,
{ "Fragment Count", "lte-rrc.warningMessageSegment.fragment_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_reassembled_in,
{ "Reassembled In", "lte-rrc.warningMessageSegment.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_reassembled_length,
{ "Reassembled Length", "lte-rrc.warningMessageSegment.reassembled_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib11_reassembled_data,
{ "Reassembled Data", "lte-rrc.warningMessageSegment.reassembled_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_fragments,
{ "Fragments", "lte-rrc.warningMessageSegment_r9.fragments",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_fragment,
{ "Fragment", "lte-rrc.warningMessageSegment_r9.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_fragment_overlap,
{ "Fragment Overlap", "lte-rrc.warningMessageSegment_r9.fragment_overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_fragment_overlap_conflict,
{ "Fragment Overlap Conflict", "lte-rrc.warningMessageSegment_r9.fragment_overlap_conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_fragment_multiple_tails,
{ "Fragment Multiple Tails", "lte-rrc.warningMessageSegment_r9.fragment_multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_fragment_too_long_fragment,
{ "Too Long Fragment", "lte-rrc.warningMessageSegment_r9.fragment_too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_fragment_error,
{ "Fragment Error", "lte-rrc.warningMessageSegment_r9.fragment_error",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_fragment_count,
{ "Fragment Count", "lte-rrc.warningMessageSegment_r9.fragment_count",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_reassembled_in,
{ "Reassembled In", "lte-rrc.warningMessageSegment_r9.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_reassembled_length,
{ "Reassembled Length", "lte-rrc.warningMessageSegment_r9.reassembled_length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lte_rrc_sib12_reassembled_data,
{ "Reassembled Data", "lte-rrc.warningMessageSegment_r9.reassembled_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_lte_rrc,
#include "packet-lte-rrc-ettarr.c"
&ett_lte_rrc_featureGroupIndicators,
&ett_lte_rrc_featureGroupIndRel9Add,
&ett_lte_rrc_featureGroupIndRel10,
&ett_lte_rrc_absTimeInfo,
&ett_lte_rrc_nas_SecurityParam,
&ett_lte_rrc_targetRAT_MessageContainer,
&ett_lte_rrc_siPsiSibContainer,
&ett_lte_rrc_dedicatedInfoNAS,
&ett_lte_rrc_timeInfo,
&ett_lte_rrc_serialNumber,
&ett_lte_rrc_warningType,
&ett_lte_rrc_dataCodingScheme,
&ett_lte_rrc_warningMessageSegment,
&ett_lte_rrc_interBandTDD_CA_WithDifferentConfig,
&ett_lte_rrc_tdd_FDD_CA_PCellDuplex_r12,
&ett_lte_rrc_sr_ConfigIndex,
&ett_lte_rrc_transmissionModeList_r12,
&ett_lte_rrc_modifiedMPR_Behavior_r10,
&ett_lte_rrc_sib11_fragment,
&ett_lte_rrc_sib11_fragments,
&ett_lte_rrc_sib12_fragment,
&ett_lte_rrc_sib12_fragments
};
static ei_register_info ei[] = {
{ &ei_lte_rrc_number_pages_le15, { "lte_rrc.number_pages_le15", PI_MALFORMED, PI_ERROR, "Number of pages should be <=15", EXPFILL }},
{ &ei_lte_rrc_si_info_value_changed, { "lte_rrc.si_info_value_changed", PI_SEQUENCE, PI_WARN, "SI Info Value changed", EXPFILL }},
{ &ei_lte_rrc_sibs_changing, { "lte_rrc.sibs_changing", PI_SEQUENCE, PI_WARN, "SIBs changing in next BCCH modification period - signalled in Paging message", EXPFILL }},
{ &ei_lte_rrc_earthquake_warning_sys, { "lte_rrc.earthquake_warning_sys", PI_SEQUENCE, PI_WARN, "Earthquake and Tsunami Warning System Indication!", EXPFILL }},
{ &ei_lte_rrc_commercial_mobile_alert_sys, { "lte_rrc.commercial_mobile_alert_sys", PI_SEQUENCE, PI_WARN, "Commercial Mobile Alert System Indication!", EXPFILL }},
{ &ei_lte_rrc_unexpected_type_value, { "lte_rrc.unexpected_type_value", PI_MALFORMED, PI_ERROR, "Unexpected type value", EXPFILL }},
{ &ei_lte_rrc_unexpected_length_value, { "lte_rrc.unexpected_length_value", PI_MALFORMED, PI_ERROR, "Unexpected type length", EXPFILL }},
{ &ei_lte_rrc_too_many_group_a_rapids, { "lte_rrc.too_many_groupa_rapids", PI_MALFORMED, PI_ERROR, "Too many group A RAPIDs", EXPFILL }},
{ &ei_lte_rrc_invalid_drx_config, { "lte_rrc.invalid_drx_config", PI_MALFORMED, PI_ERROR, "Invalid dedicated DRX config detected", EXPFILL }},
};
expert_module_t* expert_lte_rrc;
proto_lte_rrc = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("lte_rrc.dl_ccch", dissect_lte_rrc_DL_CCCH, proto_lte_rrc);
register_dissector("lte_rrc.dl_dcch", dissect_lte_rrc_DL_DCCH, proto_lte_rrc);
register_dissector("lte_rrc.ul_ccch", dissect_lte_rrc_UL_CCCH, proto_lte_rrc);
register_dissector("lte_rrc.ul_dcch", dissect_lte_rrc_UL_DCCH, proto_lte_rrc);
register_dissector("lte_rrc.bcch_bch", dissect_lte_rrc_BCCH_BCH, proto_lte_rrc);
register_dissector("lte_rrc.bcch_dl_sch", dissect_lte_rrc_BCCH_DL_SCH, proto_lte_rrc);
register_dissector("lte_rrc.pcch", dissect_lte_rrc_PCCH, proto_lte_rrc);
register_dissector("lte_rrc.mcch", dissect_lte_rrc_MCCH, proto_lte_rrc);
register_dissector("lte_rrc.handover_prep_info", dissect_lte_rrc_Handover_Preparation_Info, proto_lte_rrc);
register_dissector("lte_rrc.sbcch_sl_bch", dissect_lte_rrc_SBCCH_SL_BCH, proto_lte_rrc);
proto_register_field_array(proto_lte_rrc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_lte_rrc = expert_register_protocol(proto_lte_rrc);
expert_register_field_array(expert_lte_rrc, ei, array_length(ei));
#include "packet-lte-rrc-dis-reg.c"
register_init_routine(&lte_rrc_init_protocol);
register_cleanup_routine(&lte_rrc_cleanup_protocol);
}
void
proto_reg_handoff_lte_rrc(void)
{
static dissector_handle_t lte_rrc_dl_ccch_handle;
lte_rrc_dl_ccch_handle = find_dissector("lte_rrc.dl_ccch");
dissector_add_for_decode_as("udp.port", lte_rrc_dl_ccch_handle);
nas_eps_handle = find_dissector("nas-eps");
rrc_irat_ho_to_utran_cmd_handle = find_dissector("rrc.irat.ho_to_utran_cmd");
rrc_sys_info_cont_handle = find_dissector("rrc.sysinfo.cont");
gsm_a_dtap_handle = find_dissector("gsm_a_dtap");
gsm_rlcmac_dl_handle = find_dissector("gsm_rlcmac_dl");
}
