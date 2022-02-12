static int
add_dtn_time_to_tree(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_dtn_time)
{
nstime_t dtn_time;
int sdnv_length, sdnv2_length;
int sdnv_value;
sdnv_value = evaluate_sdnv(tvb, offset, &sdnv_length);
if (sdnv_value < 0) {
return 0;
}
dtn_time.secs = (time_t)(sdnv_value + 946684800);
offset += sdnv_length;
dtn_time.nsecs = evaluate_sdnv(tvb, offset, &sdnv2_length);
if (dtn_time.nsecs < 0) {
return 0;
}
proto_tree_add_time(tree, hf_dtn_time, tvb, offset, sdnv_length + sdnv2_length, &dtn_time);
return (sdnv_length + sdnv2_length);
}
static int
add_sdnv_time_to_tree(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_sdnv_time)
{
nstime_t dtn_time;
int sdnv_length;
int sdnv_value;
sdnv_value = evaluate_sdnv(tvb, offset, &sdnv_length);
if (sdnv_value < 0) {
return 0;
}
dtn_time.secs = (time_t)(sdnv_value + 946684800);
dtn_time.nsecs = 0;
proto_tree_add_time(tree, hf_sdnv_time, tvb, offset, sdnv_length, &dtn_time);
return sdnv_length;
}
static int
add_sdnv_to_tree(proto_tree *tree, tvbuff_t *tvb, packet_info* pinfo, int offset, int hf_sdnv)
{
proto_item *ti;
int sdnv_length;
int sdnv_value;
sdnv_value = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(tree, hf_sdnv, tvb, offset, sdnv_length, sdnv_value);
if (sdnv_value < 0) {
expert_add_info(pinfo, ti, &ei_bundle_sdnv_length);
return 0;
}
return sdnv_length;
}
static int
dissect_dictionary(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, dictionary_data_t* dict_data,
guint8 pri_hdr_procflags, gchar **bundle_custodian)
{
proto_item *ti;
proto_tree *dict_tree;
int sdnv_length;
const gchar *src_node, *dst_node;
ti = proto_tree_add_text(tree, tvb, offset, dict_data->bundle_header_dict_length, "Dictionary");
dict_tree = proto_item_add_subtree(ti, ett_dictionary);
if (dict_data->bundle_header_dict_length == 0)
{
proto_tree_add_text(dict_tree, tvb, 0,
0, "Destination Scheme: %s",IPN_SCHEME_STR);
if (dict_data->dest_scheme_offset == 0 && dict_data->dest_ssp_offset == 0)
{
proto_tree_add_text(dict_tree, tvb, dict_data->dst_scheme_pos,
dict_data->dst_scheme_len + dict_data->dst_ssp_len, "Destination: Null");
}
else
{
proto_tree_add_text(dict_tree, tvb, dict_data->dst_scheme_pos,
dict_data->dst_scheme_len + dict_data->dst_ssp_len,
"Destination: %d.%d",dict_data->dest_scheme_offset,dict_data->dest_ssp_offset);
}
proto_tree_add_text(dict_tree, tvb, 0, 0, "Source Scheme: %s",IPN_SCHEME_STR);
if (dict_data->source_scheme_offset == 0 && dict_data->source_ssp_offset == 0)
{
proto_tree_add_text(dict_tree, tvb, dict_data->src_scheme_pos,
dict_data->src_scheme_len + dict_data->src_ssp_len, "Source: Null");
}
else
{
proto_tree_add_text(dict_tree, tvb, dict_data->src_scheme_pos,
dict_data->src_scheme_len + dict_data->src_ssp_len,
"Source: %d.%d", dict_data->source_scheme_offset, dict_data->source_ssp_offset);
}
proto_tree_add_text(dict_tree, tvb, 0, 0, "Report Scheme: %s",IPN_SCHEME_STR);
if (dict_data->report_scheme_offset == 0 && dict_data->report_ssp_offset == 0)
{
proto_tree_add_text(dict_tree, tvb, dict_data->rpt_scheme_pos,
dict_data->rpt_scheme_len + dict_data->rpt_ssp_len, "Report: Null");
}
else
{
proto_tree_add_text(dict_tree, tvb, dict_data->rpt_scheme_pos,
dict_data->rpt_scheme_len + dict_data->rpt_ssp_len,
"Report: %d.%d", dict_data->report_scheme_offset, dict_data->report_ssp_offset);
}
proto_tree_add_text(dict_tree, tvb, 0, 0, "Custodian Scheme: %s",IPN_SCHEME_STR);
if (dict_data->cust_scheme_offset == 0 && dict_data->cust_ssp_offset == 0)
{
proto_tree_add_text(dict_tree, tvb, dict_data->cust_scheme_pos,
dict_data->cust_scheme_len + dict_data->cust_ssp_len, "Custodian: Null");
}
else
{
proto_tree_add_text(dict_tree, tvb, dict_data->cust_scheme_pos,
dict_data->cust_scheme_len + dict_data->cust_ssp_len,
"Custodian: %d.%d", dict_data->cust_scheme_offset, dict_data->cust_ssp_offset);
}
if (dict_data->source_scheme_offset == 0 && dict_data->source_ssp_offset == 0)
{
src_node = "Null";
}
else
{
src_node = wmem_strdup_printf(wmem_packet_scope(), "%s:%d.%d", IPN_SCHEME_STR,
dict_data->source_scheme_offset, dict_data->source_ssp_offset);
}
if (dict_data->dest_scheme_offset == 0 && dict_data->dest_ssp_offset == 0)
{
dst_node = "Null";
}
else
{
dst_node = wmem_strdup_printf(wmem_packet_scope(), "%s:%d.%d", IPN_SCHEME_STR,
dict_data->dest_scheme_offset, dict_data->dest_ssp_offset);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s > %s", src_node, dst_node);
*bundle_custodian = wmem_strdup_printf(wmem_packet_scope(), "%s:%d.%d", IPN_SCHEME_STR,
dict_data->cust_scheme_offset, dict_data->cust_ssp_offset);
}
else
{
proto_tree_add_item(dict_tree, hf_bundle_dest_scheme,
tvb, offset + dict_data->dest_scheme_offset, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dict_tree, hf_bundle_dest_ssp,
tvb, offset + dict_data->dest_ssp_offset, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dict_tree, hf_bundle_source_scheme,
tvb, offset + dict_data->source_scheme_offset, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dict_tree, hf_bundle_source_ssp,
tvb, offset + dict_data->source_ssp_offset, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dict_tree, hf_bundle_report_scheme,
tvb, offset + dict_data->report_scheme_offset, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dict_tree, hf_bundle_report_ssp,
tvb, offset + dict_data->report_ssp_offset, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dict_tree, hf_bundle_custodian_scheme, tvb, offset + dict_data->cust_scheme_offset, -1, ENC_ASCII|ENC_NA);
proto_tree_add_item(dict_tree, hf_bundle_custodian_ssp, tvb, offset + dict_data->cust_ssp_offset, -1, ENC_ASCII|ENC_NA);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s:%s > %s:%s",
tvb_get_stringz(wmem_packet_scope(), tvb, offset + dict_data->source_scheme_offset, NULL),
tvb_get_stringz(wmem_packet_scope(), tvb, offset + dict_data->source_ssp_offset, NULL),
tvb_get_stringz(wmem_packet_scope(), tvb, offset + dict_data->dest_scheme_offset, NULL),
tvb_get_stringz(wmem_packet_scope(), tvb, offset + dict_data->dest_ssp_offset, NULL));
*bundle_custodian = wmem_strdup_printf(wmem_packet_scope(),
"%s:%s",
tvb_get_stringz(wmem_packet_scope(),
tvb, offset + dict_data->cust_scheme_offset,
NULL),
tvb_get_stringz(wmem_packet_scope(),
tvb, offset + dict_data->cust_ssp_offset,
NULL));
}
offset += dict_data->bundle_header_dict_length;
if (pri_hdr_procflags & BUNDLE_PROCFLAGS_FRAG_MASK) {
sdnv_length = add_sdnv_to_tree(tree, tvb, pinfo, offset, hf_bundle_primary_fragment_offset);
if (sdnv_length < 0) {
return 0;
}
offset += sdnv_length;
sdnv_length = add_sdnv_to_tree(tree, tvb, pinfo, offset, hf_bundle_primary_total_adu_len);
if (sdnv_length < 0) {
return 0;
}
offset += sdnv_length;
}
return offset;
}
static int
dissect_version_4_primary_header(packet_info *pinfo, proto_tree *primary_tree, tvbuff_t *tvb,
guint8* pri_hdr_procflags, gchar **bundle_custodian)
{
int bundle_header_length;
int offset = 1;
int sdnv_length;
dictionary_data_t dict_data;
proto_item *ti;
proto_tree *srr_flag_tree, *proc_flag_tree, *cos_flag_tree;
*pri_hdr_procflags = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(primary_tree, hf_bundle_procflags, tvb,
offset, 1, ENC_BIG_ENDIAN);
proc_flag_tree = proto_item_add_subtree(ti, ett_proc_flags);
proto_tree_add_item(proc_flag_tree, hf_bundle_procflags_fragment,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(proc_flag_tree, hf_bundle_procflags_admin,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(proc_flag_tree, hf_bundle_procflags_dont_fragment,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(proc_flag_tree, hf_bundle_procflags_cust_xfer_req,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(proc_flag_tree, hf_bundle_procflags_dest_singleton,
tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
ti = proto_tree_add_item(primary_tree, hf_bundle_cosflags, tvb,
offset, 1, ENC_BIG_ENDIAN);
cos_flag_tree = proto_item_add_subtree(ti, ett_cos_flags);
proto_tree_add_item(cos_flag_tree, hf_bundle_cosflags_priority,
tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
ti = proto_tree_add_item(primary_tree, hf_bundle_srrflags, tvb,
offset, 1, ENC_BIG_ENDIAN);
srr_flag_tree = proto_item_add_subtree(ti, ett_srr_flags);
proto_tree_add_item(srr_flag_tree, hf_bundle_srrflags_report_receipt,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(srr_flag_tree, hf_bundle_srrflags_report_cust_accept,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(srr_flag_tree, hf_bundle_srrflags_report_forward,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(srr_flag_tree, hf_bundle_srrflags_report_delivery,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(srr_flag_tree, hf_bundle_srrflags_report_deletion,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(srr_flag_tree, hf_bundle_srrflags_report_ack,
tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
bundle_header_length = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(primary_tree, hf_bundle_primary_header_len, tvb, offset, sdnv_length,
bundle_header_length);
if (bundle_header_length < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "Bundle Header Length Error");
return 0;
}
offset += sdnv_length;
memset(&dict_data, 0, sizeof(dict_data));
dict_data.dest_scheme_offset = tvb_get_ntohs(tvb, offset);
dict_data.dst_scheme_pos = offset;
dict_data.dst_scheme_len = 2;
proto_tree_add_item(primary_tree, hf_bundle_dest_scheme_offset_u16,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dict_data.dest_ssp_offset = tvb_get_ntohs(tvb, offset);
dict_data.dst_ssp_len = 2;
proto_tree_add_item(primary_tree, hf_bundle_dest_ssp_offset_u16,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dict_data.source_scheme_offset = tvb_get_ntohs(tvb, offset);
dict_data.src_scheme_pos = offset;
dict_data.src_scheme_len = 2;
proto_tree_add_item(primary_tree, hf_bundle_source_scheme_offset_u16,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dict_data.source_ssp_offset = tvb_get_ntohs(tvb, offset);
dict_data.src_ssp_len = 2;
proto_tree_add_item(primary_tree, hf_bundle_source_ssp_offset_u16,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dict_data.report_scheme_offset = tvb_get_ntohs(tvb, offset);
dict_data.rpt_scheme_pos = offset;
dict_data.rpt_scheme_len = 2;
proto_tree_add_item(primary_tree, hf_bundle_report_scheme_offset_u16,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dict_data.report_ssp_offset = tvb_get_ntohs(tvb, offset);
dict_data.rpt_ssp_len = 2;
proto_tree_add_item(primary_tree, hf_bundle_report_ssp_offset_u16,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dict_data.cust_scheme_offset = tvb_get_ntohs(tvb, offset);
dict_data.cust_scheme_pos = offset;
dict_data.cust_scheme_len = 2;
proto_tree_add_item(primary_tree, hf_bundle_cust_scheme_offset_u16,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dict_data.cust_ssp_offset = tvb_get_ntohs(tvb, offset);
dict_data.cust_ssp_len = 2;
proto_tree_add_item(primary_tree, hf_bundle_cust_ssp_offset_u16,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(primary_tree, hf_bundle_creation_timestamp,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(primary_tree, hf_bundle_lifetime, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
dict_data.bundle_header_dict_length = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(primary_tree, hf_bundle_primary_dictionary_len, tvb, offset, sdnv_length,
dict_data.bundle_header_dict_length);
if (dict_data.bundle_header_dict_length < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "Dictionary Header Length Error");
return 0;
}
offset += sdnv_length;
offset = dissect_dictionary(pinfo, primary_tree, tvb, offset, &dict_data, *pri_hdr_procflags, bundle_custodian);
return offset;
}
static int
dissect_version_5_and_6_primary_header(packet_info *pinfo,
proto_tree *primary_tree, tvbuff_t *tvb,
guint8* pri_hdr_procflags, gchar **bundle_custodian)
{
guint64 bundle_processing_control_flags;
guint8 cosflags;
int bundle_header_length;
int offset = 1;
int sdnv_length;
dictionary_data_t dict_data;
int timestamp_sequence;
guint8 srrflags;
proto_item *ti;
proto_tree *gen_flag_tree, *srr_flag_tree, *proc_flag_tree, *cos_flag_tree;
bundle_processing_control_flags = evaluate_sdnv_64(tvb, offset, &sdnv_length);
*pri_hdr_procflags = (guint8) (bundle_processing_control_flags & 0x7f);
if (sdnv_length < 1 || sdnv_length > 8) {
expert_add_info_format(pinfo, primary_tree, &ei_bundle_control_flags_length,
"Wrong bundle control flag length: %d", sdnv_length);
return 0;
}
ti = proto_tree_add_item(primary_tree, hf_bundle_control_flags, tvb,
offset, sdnv_length, ENC_BIG_ENDIAN);
proc_flag_tree = proto_item_add_subtree(ti, ett_proc_flags);
ti = proto_tree_add_uint(proc_flag_tree, hf_bundle_procflags_general, tvb, offset,
sdnv_length, *pri_hdr_procflags);
gen_flag_tree = proto_item_add_subtree(ti, ett_gen_flags);
proto_tree_add_boolean(gen_flag_tree, hf_bundle_procflags_fragment,
tvb, offset, sdnv_length, *pri_hdr_procflags);
proto_tree_add_boolean(gen_flag_tree, hf_bundle_procflags_admin,
tvb, offset, sdnv_length, *pri_hdr_procflags);
proto_tree_add_boolean(gen_flag_tree, hf_bundle_procflags_dont_fragment,
tvb, offset, sdnv_length, *pri_hdr_procflags);
proto_tree_add_boolean(gen_flag_tree, hf_bundle_procflags_cust_xfer_req,
tvb, offset, sdnv_length, *pri_hdr_procflags);
proto_tree_add_boolean(gen_flag_tree, hf_bundle_procflags_dest_singleton,
tvb, offset, sdnv_length, *pri_hdr_procflags);
proto_tree_add_boolean(gen_flag_tree, hf_bundle_procflags_application_ack,
tvb, offset, sdnv_length, *pri_hdr_procflags);
cosflags = (guint8) ((bundle_processing_control_flags >> 7) & 0x7f);
ti = proto_tree_add_uint(proc_flag_tree, hf_bundle_procflags_cos, tvb, offset,
sdnv_length, cosflags);
cos_flag_tree = proto_item_add_subtree(ti, ett_cos_flags);
proto_tree_add_uint(cos_flag_tree, hf_bundle_cosflags_priority, tvb, offset,
sdnv_length, cosflags);
srrflags = (guint8) ((bundle_processing_control_flags >> 14) & 0x7f);
ti = proto_tree_add_uint(proc_flag_tree, hf_bundle_procflags_status, tvb, offset,
sdnv_length, srrflags);
srr_flag_tree = proto_item_add_subtree(ti, ett_srr_flags);
proto_tree_add_boolean(srr_flag_tree, hf_bundle_srrflags_report_receipt,
tvb, offset, sdnv_length, srrflags);
proto_tree_add_boolean(srr_flag_tree, hf_bundle_srrflags_report_cust_accept,
tvb, offset, sdnv_length, srrflags);
proto_tree_add_boolean(srr_flag_tree, hf_bundle_srrflags_report_forward,
tvb, offset, sdnv_length, srrflags);
proto_tree_add_boolean(srr_flag_tree, hf_bundle_srrflags_report_delivery,
tvb, offset, sdnv_length, srrflags);
proto_tree_add_boolean(srr_flag_tree, hf_bundle_srrflags_report_deletion,
tvb, offset, sdnv_length, srrflags);
offset += sdnv_length;
bundle_header_length = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(primary_tree, hf_bundle_primary_header_len, tvb, offset, sdnv_length,
bundle_header_length);
if (bundle_header_length < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "Bundle Header Length Error");
return 0;
}
offset += sdnv_length;
memset(&dict_data, 0, sizeof(dict_data));
dict_data.dest_scheme_offset = evaluate_sdnv(tvb, offset, &sdnv_length);
dict_data.dst_scheme_pos = offset;
dict_data.dst_scheme_len = sdnv_length;
ti = proto_tree_add_int(primary_tree, hf_bundle_dest_scheme_offset_i32, tvb, offset, sdnv_length,
dict_data.dest_scheme_offset);
if ((dict_data.dest_scheme_offset < 0) || (dict_data.dest_scheme_offset > bundle_header_length)) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Destination Scheme Offset Error");
}
offset += sdnv_length;
dict_data.dest_ssp_offset = evaluate_sdnv(tvb, offset, &sdnv_length);
dict_data.dst_ssp_len = sdnv_length;
ti = proto_tree_add_int(primary_tree, hf_bundle_dest_ssp_offset_i32, tvb, offset, sdnv_length,
dict_data.dest_ssp_offset);
if ((dict_data.dest_ssp_offset < 0) || (dict_data.dest_ssp_offset > bundle_header_length)) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Destination SSP Offset Error");
}
offset += sdnv_length;
dict_data.source_scheme_offset = evaluate_sdnv(tvb, offset, &sdnv_length);
dict_data.src_scheme_pos = offset;
dict_data.src_scheme_len = sdnv_length;
ti = proto_tree_add_int(primary_tree, hf_bundle_source_scheme_offset_i32, tvb, offset, sdnv_length,
dict_data.source_scheme_offset);
if ((dict_data.source_scheme_offset < 0) || (dict_data.source_scheme_offset > bundle_header_length)) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Source Scheme Offset Error");
}
offset += sdnv_length;
dict_data.source_ssp_offset = evaluate_sdnv(tvb, offset, &sdnv_length);
dict_data.src_ssp_len = sdnv_length;
ti = proto_tree_add_int(primary_tree, hf_bundle_source_ssp_offset_i32, tvb, offset, sdnv_length,
dict_data.source_ssp_offset);
if ((dict_data.source_ssp_offset < 0) || (dict_data.source_ssp_offset > bundle_header_length)) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Source SSP Offset Error");
}
offset += sdnv_length;
dict_data.report_scheme_offset = evaluate_sdnv(tvb, offset, &sdnv_length);
dict_data.rpt_scheme_pos = offset;
dict_data.rpt_scheme_len = sdnv_length;
ti = proto_tree_add_int(primary_tree, hf_bundle_report_scheme_offset_i32, tvb, offset,
sdnv_length, dict_data.report_scheme_offset);
if ((dict_data.report_scheme_offset < 0) || (dict_data.report_scheme_offset > bundle_header_length)) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Report Scheme Offset Error");
}
offset += sdnv_length;
dict_data.report_ssp_offset = evaluate_sdnv(tvb, offset, &sdnv_length);
dict_data.rpt_ssp_len = sdnv_length;
ti = proto_tree_add_int(primary_tree, hf_bundle_report_ssp_offset_i32, tvb, offset, sdnv_length,
dict_data.report_ssp_offset);
if ((dict_data.report_ssp_offset < 0) || (dict_data.report_ssp_offset > bundle_header_length)) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Report SSP Offset Error");
}
offset += sdnv_length;
dict_data.cust_scheme_offset = evaluate_sdnv(tvb, offset, &sdnv_length);
dict_data.cust_scheme_pos = offset;
dict_data.cust_scheme_len = sdnv_length;
ti = proto_tree_add_int(primary_tree, hf_bundle_cust_scheme_offset_i32, tvb, offset, sdnv_length,
dict_data.cust_scheme_offset);
if ((dict_data.cust_scheme_offset < 0) || (dict_data.cust_scheme_offset > bundle_header_length)) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Custodian Scheme Offset Error");
}
offset += sdnv_length;
dict_data.cust_ssp_offset = evaluate_sdnv(tvb, offset, &sdnv_length);
dict_data.cust_ssp_len = sdnv_length;
ti = proto_tree_add_int(primary_tree, hf_bundle_cust_ssp_offset_i32, tvb, offset, sdnv_length,
dict_data.cust_ssp_offset);
if ((dict_data.cust_ssp_offset < 0) || (dict_data.cust_ssp_offset > bundle_header_length)) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Custodian SSP Offset Error");
}
offset += sdnv_length;
sdnv_length = add_sdnv_time_to_tree(primary_tree, tvb, offset, hf_bundle_primary_timestamp);
if (sdnv_length == 0)
return 0;
offset += sdnv_length;
timestamp_sequence = evaluate_sdnv(tvb, offset, &sdnv_length);
if (timestamp_sequence < 0) {
gint64 ts_seq = evaluate_sdnv_64(tvb, offset, &sdnv_length);
ti = proto_tree_add_int64(primary_tree, hf_bundle_primary_timestamp_seq_num64,
tvb, offset, sdnv_length, ts_seq);
if (ts_seq < 0) {
expert_add_info(pinfo, ti, &ei_bundle_timestamp_seq_num);
}
}
else {
proto_tree_add_int(primary_tree, hf_bundle_primary_timestamp_seq_num32,
tvb, offset, sdnv_length, timestamp_sequence);
}
offset += sdnv_length;
sdnv_length = add_sdnv_to_tree(primary_tree, tvb, pinfo, offset, hf_bundle_lifetime_sdnv);
offset += sdnv_length;
dict_data.bundle_header_dict_length = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(primary_tree, hf_bundle_primary_dictionary_len, tvb, offset, sdnv_length,
dict_data.bundle_header_dict_length);
if (dict_data.bundle_header_dict_length < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "Dictionary Header Length Error");
return 0;
}
offset += sdnv_length;
offset = dissect_dictionary(pinfo, primary_tree, tvb, offset, &dict_data, *pri_hdr_procflags, bundle_custodian);
return offset;
}
static int
dissect_payload_header(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, guint8 version,
guint8 pri_hdr_procflags, gboolean *lastheader)
{
proto_item *payload_item, *ti;
proto_tree *payload_tree;
int sdnv_length, payload_length;
payload_item = proto_tree_add_text(tree, tvb, offset, -1, "Payload Header");
payload_tree = proto_item_add_subtree(payload_item, ett_payload_hdr);
proto_tree_add_text(payload_tree, tvb, offset, 1, "Header Type: 1");
++offset;
if (version == 4) {
proto_item *proc_flag_item;
proto_tree *proc_flag_tree;
guint8 procflags;
procflags = tvb_get_guint8(tvb, offset);
if (procflags & HEADER_PROCFLAGS_LAST_HEADER) {
*lastheader = TRUE;
}
else {
*lastheader = FALSE;
}
proc_flag_item = proto_tree_add_item(payload_tree, hf_bundle_payload_flags, tvb,
offset, 1, ENC_BIG_ENDIAN);
proc_flag_tree = proto_item_add_subtree(proc_flag_item, ett_payload_flags);
proto_tree_add_item(proc_flag_tree, hf_bundle_payload_flags_replicate_hdr,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(proc_flag_tree, hf_bundle_payload_flags_xmit_report,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(proc_flag_tree, hf_bundle_payload_flags_discard_on_fail,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(proc_flag_tree, hf_bundle_payload_flags_last_header,
tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
}
else {
int control_flags;
proto_item *block_flag_item;
proto_tree *block_flag_tree;
control_flags = evaluate_sdnv(tvb, offset, &sdnv_length);
if (control_flags & BLOCK_CONTROL_LAST_BLOCK) {
*lastheader = TRUE;
}
else {
*lastheader = FALSE;
}
block_flag_item = proto_tree_add_item(payload_tree, hf_block_control_flags, tvb,
offset, sdnv_length, ENC_BIG_ENDIAN);
block_flag_tree = proto_item_add_subtree(block_flag_item, ett_block_flags);
proto_tree_add_item(block_flag_tree, hf_block_control_replicate,
tvb, offset, sdnv_length, ENC_BIG_ENDIAN);
proto_tree_add_item(block_flag_tree, hf_block_control_transmit_status,
tvb, offset, sdnv_length, ENC_BIG_ENDIAN);
proto_tree_add_item(block_flag_tree, hf_block_control_delete_bundle,
tvb, offset, sdnv_length, ENC_BIG_ENDIAN);
proto_tree_add_item(block_flag_tree, hf_block_control_last_block,
tvb, offset, sdnv_length, ENC_BIG_ENDIAN);
proto_tree_add_item(block_flag_tree, hf_block_control_discard_block,
tvb, offset, sdnv_length, ENC_BIG_ENDIAN);
proto_tree_add_item(block_flag_tree, hf_block_control_not_processed,
tvb, offset, sdnv_length, ENC_BIG_ENDIAN);
proto_tree_add_item(block_flag_tree, hf_block_control_eid_reference,
tvb, offset, sdnv_length, ENC_BIG_ENDIAN);
offset += sdnv_length;
}
payload_length = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(payload_tree, hf_bundle_payload_length, tvb, offset, sdnv_length, payload_length);
if (payload_length < 0) {
expert_add_info(pinfo, ti, &ei_bundle_payload_length);
*lastheader = TRUE;
return offset;
}
proto_item_set_len(payload_item, 2 + sdnv_length);
offset += sdnv_length;
if (pri_hdr_procflags & BUNDLE_PROCFLAGS_ADMIN_MASK) {
gboolean success = FALSE;
offset = dissect_admin_record(payload_tree, tvb, pinfo, offset, payload_length, &success);
if (!success) {
*lastheader = TRUE;
return offset;
}
}
return payload_length + offset;
}
static int
dissect_admin_record(proto_tree *primary_tree, tvbuff_t *tvb, packet_info *pinfo,
int offset, int payload_length, gboolean* success)
{
proto_item *admin_record_item, *ti;
proto_tree *admin_record_tree;
proto_item *timestamp_sequence_item;
guint8 record_type;
guint8 status;
int start_offset = offset;
int sdnv_length;
int timestamp_sequence;
int endpoint_length;
*success = FALSE;
admin_record_item = proto_tree_add_text(primary_tree, tvb, offset, -1, "Administrative Record");
admin_record_tree = proto_item_add_subtree(admin_record_item, ett_admin_record);
record_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(admin_record_tree, hf_bundle_admin_record_type, tvb, offset, 1, ENC_NA);
switch ((record_type >> 4) & 0xf)
{
case ADMIN_REC_TYPE_STATUS_REPORT:
{
proto_item *status_flag_item;
proto_tree *status_flag_tree;
proto_tree_add_item(admin_record_tree, hf_bundle_admin_record_fragment, tvb, offset, 1, ENC_NA);
++offset;
status = tvb_get_guint8(tvb, offset);
status_flag_item = proto_tree_add_item(admin_record_tree,
hf_bundle_admin_statflags, tvb, offset, 1, ENC_BIG_ENDIAN);
status_flag_tree = proto_item_add_subtree(status_flag_item,
ett_admin_rec_status);
proto_tree_add_item(status_flag_tree, hf_bundle_admin_rcvd,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(status_flag_tree, hf_bundle_admin_accepted,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(status_flag_tree, hf_bundle_admin_forwarded,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(status_flag_tree, hf_bundle_admin_delivered,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(status_flag_tree, hf_bundle_admin_deleted,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(status_flag_tree, hf_bundle_admin_acked,
tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
proto_tree_add_item(admin_record_tree, hf_bundle_status_report_reason_code, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
if (record_type & ADMIN_REC_FLAGS_FRAGMENT) {
sdnv_length = add_sdnv_to_tree(admin_record_tree, tvb, pinfo, offset, hf_bundle_admin_fragment_offset);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
sdnv_length = add_sdnv_to_tree(admin_record_tree, tvb, pinfo, offset, hf_bundle_admin_fragment_length);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
}
if (status & ADMIN_STATUS_FLAGS_RECEIVED) {
sdnv_length = add_dtn_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_receipt_time);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
}
if (status & ADMIN_STATUS_FLAGS_ACCEPTED) {
sdnv_length = add_dtn_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_accept_time);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
}
if (status & ADMIN_STATUS_FLAGS_FORWARDED) {
sdnv_length = add_dtn_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_forward_time);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
}
if (status & ADMIN_STATUS_FLAGS_DELIVERED) {
sdnv_length = add_dtn_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_delivery_time);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
}
if (status & ADMIN_STATUS_FLAGS_DELETED) {
sdnv_length = add_dtn_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_delete_time);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
}
if (status & ADMIN_STATUS_FLAGS_ACKNOWLEDGED) {
sdnv_length = add_dtn_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_ack_time);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
}
sdnv_length = add_sdnv_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_timestamp_copy);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
timestamp_sequence = evaluate_sdnv(tvb, offset, &sdnv_length);
if (timestamp_sequence < 0) {
gint64 ts_seq = evaluate_sdnv_64(tvb, offset, &sdnv_length);
timestamp_sequence_item = proto_tree_add_int64(admin_record_tree, hf_bundle_admin_timestamp_seq_num64,
tvb, offset, sdnv_length, ts_seq);
if (ts_seq < 0) {
expert_add_info(pinfo, timestamp_sequence_item, &ei_bundle_timestamp_seq_num);
return offset;
}
}
else {
proto_tree_add_int(admin_record_tree, hf_bundle_admin_timestamp_seq_num32,
tvb, offset, sdnv_length, timestamp_sequence);
}
offset += sdnv_length;
endpoint_length = evaluate_sdnv(tvb, offset, &sdnv_length);
if (endpoint_length < 0) {
return offset;
}
proto_tree_add_int(admin_record_tree, hf_bundle_admin_endpoint_length, tvb, offset, sdnv_length, endpoint_length);
offset += sdnv_length;
proto_tree_add_item(admin_record_tree, hf_bundle_admin_endpoint_id, tvb, offset, endpoint_length, ENC_NA|ENC_ASCII);
offset += endpoint_length;
break;
}
case ADMIN_REC_TYPE_CUSTODY_SIGNAL:
{
proto_tree_add_item(admin_record_tree, hf_bundle_admin_record_fragment, tvb, offset, 1, ENC_NA);
++offset;
proto_tree_add_item(admin_record_tree, hf_bundle_custody_trf_succ_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(admin_record_tree, hf_bundle_custody_signal_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
if (record_type & ADMIN_REC_FLAGS_FRAGMENT) {
sdnv_length = add_sdnv_to_tree(admin_record_tree, tvb, pinfo, offset, hf_bundle_admin_fragment_offset);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
sdnv_length = add_sdnv_to_tree(admin_record_tree, tvb, pinfo, offset, hf_bundle_admin_fragment_length);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
}
sdnv_length = add_dtn_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_signal_time);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
sdnv_length = add_sdnv_time_to_tree(admin_record_tree, tvb, offset, hf_bundle_admin_timestamp_copy);
if (sdnv_length <= 0) {
return offset;
}
offset += sdnv_length;
timestamp_sequence = evaluate_sdnv(tvb, offset, &sdnv_length);
if (timestamp_sequence < 0) {
gint64 ts_seq = evaluate_sdnv_64(tvb, offset, &sdnv_length);
timestamp_sequence_item = proto_tree_add_int64(admin_record_tree, hf_bundle_admin_timestamp_seq_num64,
tvb, offset, sdnv_length, ts_seq);
if (ts_seq < 0) {
expert_add_info(pinfo, timestamp_sequence_item, &ei_bundle_timestamp_seq_num);
return offset;
}
}
else {
proto_tree_add_int(admin_record_tree, hf_bundle_admin_timestamp_seq_num32,
tvb, offset, sdnv_length, timestamp_sequence);
}
offset += sdnv_length;
endpoint_length = evaluate_sdnv(tvb, offset, &sdnv_length);
if (endpoint_length < 0) {
return 0;
}
proto_tree_add_int(admin_record_tree, hf_bundle_admin_endpoint_length, tvb, offset, sdnv_length, endpoint_length);
offset += sdnv_length;
proto_tree_add_item(admin_record_tree, hf_bundle_admin_endpoint_id, tvb, offset, endpoint_length, ENC_NA|ENC_ASCII);
offset += endpoint_length;
break;
}
case ADMIN_REC_TYPE_AGGREGATE_CUSTODY_SIGNAL:
{
int payload_bytes_processed = 0;
int right_edge = -1;
int fill_start = -1;
int fill_gap = -1;
int fill_length = -1;
int sdnv_length_start = -1;
int sdnv_length_gap = -1;
int sdnv_length_length = -1;
proto_tree_add_item(admin_record_tree, hf_bundle_admin_record_fragment, tvb, offset, 1, ENC_NA);
++offset;
++payload_bytes_processed;
proto_tree_add_item(admin_record_tree, hf_bundle_custody_trf_succ_flg, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(admin_record_tree, hf_bundle_custody_signal_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
++payload_bytes_processed;
fill_start = evaluate_sdnv(tvb, offset, &sdnv_length_start);
ti = proto_tree_add_int(admin_record_tree, hf_bundle_custody_id_range_start, tvb, offset, sdnv_length_start, fill_start);
if (fill_start < 0 || sdnv_length_start < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "ACS: Unable to process CTEB Custody ID Range start SDNV");
return offset;
}
fill_length = evaluate_sdnv(tvb, offset + sdnv_length_start, &sdnv_length_length);
ti = proto_tree_add_int(admin_record_tree, hf_bundle_custody_id_range_end, tvb, offset,
sdnv_length_start + sdnv_length_length, fill_start + fill_length - 1);
if (fill_length < 0 || sdnv_length_length < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "ACS: Unable to process CTEB Custody ID Range length SDNV");
return offset;
}
right_edge = fill_start + fill_length;
offset += sdnv_length_start + sdnv_length_length;
payload_bytes_processed += sdnv_length_start + sdnv_length_length;
while (payload_bytes_processed < payload_length) {
fill_gap = evaluate_sdnv(tvb, offset, &sdnv_length_gap);
ti = proto_tree_add_int(admin_record_tree, hf_bundle_custody_id_range_start, tvb, offset, sdnv_length_gap, fill_gap);
if (fill_gap < 0 || sdnv_length_gap < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "ACS: Unable to process CTEB Custody ID Range gap SDNV");
return offset;
}
fill_length = evaluate_sdnv(tvb, offset + sdnv_length_gap, &sdnv_length_length);
ti = proto_tree_add_int(admin_record_tree, hf_bundle_custody_id_range_end, tvb, offset,
sdnv_length_gap + sdnv_length_length, right_edge + fill_gap + fill_length - 1);
if (fill_length < 0 || sdnv_length_length < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "ACS: Unable to process CTEB Custody ID Range length SDNV");
return offset;
}
right_edge += fill_gap + fill_length;
offset += sdnv_length_gap + sdnv_length_length;
payload_bytes_processed += sdnv_length_gap + sdnv_length_length;
}
if (payload_bytes_processed > payload_length) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "ACS: CTEB Custody ID Range data extends past payload length");
return offset;
}
break;
}
case ADMIN_REC_TYPE_ANNOUNCE_BUNDLE:
default:
offset++;
break;
}
proto_item_set_len(admin_record_item, offset - start_offset);
*success = TRUE;
return offset;
}
static int
display_metadata_block(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, int offset, gchar *bundle_custodian, gboolean *lastheader)
{
proto_item *block_item, *ti, *block_flag_replicate_item, *block_flag_eid_reference_item;
proto_tree *block_tree;
int sdnv_length;
int block_length;
guint8 type;
unsigned int control_flags;
proto_tree *block_flag_tree;
proto_item *block_flag_item;
type = tvb_get_guint8(tvb, offset);
block_item = proto_tree_add_text(tree, tvb, offset, -1, "Metadata Block");
block_tree = proto_item_add_subtree(block_item, ett_metadata_hdr);
proto_tree_add_item(block_tree, hf_bundle_block_type_code, tvb, offset, 1, ENC_BIG_ENDIAN);
++offset;
control_flags = (unsigned int)evaluate_sdnv(tvb, offset, &sdnv_length);
if (control_flags & BLOCK_CONTROL_LAST_BLOCK) {
*lastheader = TRUE;
} else {
*lastheader = FALSE;
}
block_flag_item = proto_tree_add_uint(block_tree, hf_block_control_flags_sdnv, tvb,
offset, sdnv_length, control_flags);
block_flag_tree = proto_item_add_subtree(block_flag_item, ett_block_flags);
block_flag_replicate_item = proto_tree_add_boolean(block_flag_tree, hf_block_control_replicate,
tvb, offset, sdnv_length, control_flags);
proto_tree_add_boolean(block_flag_tree, hf_block_control_transmit_status,
tvb, offset, sdnv_length, control_flags);
proto_tree_add_boolean(block_flag_tree, hf_block_control_delete_bundle,
tvb, offset, sdnv_length, control_flags);
proto_tree_add_boolean(block_flag_tree, hf_block_control_last_block,
tvb, offset, sdnv_length, control_flags);
proto_tree_add_boolean(block_flag_tree, hf_block_control_discard_block,
tvb, offset, sdnv_length, control_flags);
proto_tree_add_boolean(block_flag_tree, hf_block_control_not_processed,
tvb, offset, sdnv_length, control_flags);
block_flag_eid_reference_item = proto_tree_add_boolean(block_flag_tree, hf_block_control_eid_reference,
tvb, offset, sdnv_length, control_flags);
offset += sdnv_length;
if (control_flags & BLOCK_CONTROL_EID_REFERENCE) {
int i;
int num_eid_ref;
num_eid_ref = evaluate_sdnv(tvb, offset, &sdnv_length);
offset += sdnv_length;
for (i = 0; i < num_eid_ref; i++)
{
evaluate_sdnv(tvb, offset, &sdnv_length);
offset += sdnv_length;
evaluate_sdnv(tvb, offset, &sdnv_length);
offset += sdnv_length;
}
}
block_length = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(block_tree, hf_block_control_block_length, tvb, offset, sdnv_length, block_length);
if (block_length < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_offset_error, "Metadata Block Length Error");
*lastheader = TRUE;
return offset;
}
offset += sdnv_length;
proto_item_set_len(block_item, offset + block_length);
switch (type)
{
case BUNDLE_BLOCK_TYPE_AUTHENTICATION:
case BUNDLE_BLOCK_TYPE_INTEGRITY:
case BUNDLE_BLOCK_TYPE_CONFIDENTIALITY:
case BUNDLE_BLOCK_TYPE_PREVIOUS_HOP_INSERT:
case BUNDLE_BLOCK_TYPE_METADATA_EXTENSION:
case BUNDLE_BLOCK_TYPE_EXTENSION_SECURITY:
{
offset += block_length;
break;
}
case BUNDLE_BLOCK_TYPE_CUSTODY_TRANSFER:
{
int custody_id;
const char *cteb_creator_custodian_eid;
int cteb_creator_custodian_eid_length;
if ((control_flags & BLOCK_CONTROL_REPLICATE) != 0) {
expert_add_info_format(pinfo, block_flag_replicate_item, &ei_bundle_block_control_flags, "ERROR: Replicate must be clear for CTEB");
}
if ((control_flags & BLOCK_CONTROL_EID_REFERENCE) != 0) {
expert_add_info_format(pinfo, block_flag_eid_reference_item, &ei_bundle_block_control_flags, "ERROR: EID-Reference must be clear for CTEB");
}
custody_id = evaluate_sdnv(tvb, offset, &sdnv_length);
proto_tree_add_int(block_tree, hf_block_control_block_cteb_custody_id, tvb, offset, sdnv_length, custody_id);
offset += sdnv_length;
cteb_creator_custodian_eid_length = block_length - sdnv_length;
cteb_creator_custodian_eid = (char *) tvb_get_string(wmem_packet_scope(), tvb, offset, cteb_creator_custodian_eid_length);
ti = proto_tree_add_string(block_tree, hf_block_control_block_cteb_creator_custodian_eid, tvb, offset,
cteb_creator_custodian_eid_length, cteb_creator_custodian_eid);
if (bundle_custodian == NULL) {
expert_add_info_format(pinfo, ti, &ei_block_control_block_cteb_invalid,
"CTEB Is NOT Valid (Bundle Custodian NULL)");
}
else if (strlen(cteb_creator_custodian_eid) != strlen(bundle_custodian)) {
expert_add_info_format(pinfo, ti, &ei_block_control_block_cteb_invalid,
"CTEB Is NOT Valid (Bundle Custodian [%s] != CTEB Custodian [%s])",
bundle_custodian, cteb_creator_custodian_eid);
}
else if (memcmp(cteb_creator_custodian_eid, bundle_custodian, strlen(bundle_custodian)) != 0) {
expert_add_info_format(pinfo, ti, &ei_block_control_block_cteb_invalid,
"CTEB Is NOT Valid (Bundle Custodian [%s] != CTEB Custodian [%s])",
bundle_custodian, cteb_creator_custodian_eid);
}
else {
expert_add_info(pinfo, ti, &ei_block_control_block_cteb_valid);
}
offset += cteb_creator_custodian_eid_length;
break;
}
case BUNDLE_BLOCK_TYPE_EXTENDED_COS:
{
proto_item *ecos_flag_item;
proto_tree *ecos_flag_tree;
int flags, flow_label;
if ((control_flags & BLOCK_CONTROL_REPLICATE) == 0) {
expert_add_info_format(pinfo, block_flag_replicate_item, &ei_bundle_block_control_flags, "ERROR: Replicate must be set for ECOS");
}
if ((control_flags & BLOCK_CONTROL_EID_REFERENCE) != 0) {
expert_add_info_format(pinfo, block_flag_eid_reference_item, &ei_bundle_block_control_flags, "ERROR: EID-Reference must be clear for ECOS");
}
flags = (int)tvb_get_guint8(tvb, offset);
ecos_flag_item = proto_tree_add_item(block_tree, hf_ecos_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
ecos_flag_tree = proto_item_add_subtree(ecos_flag_item, ett_block_flags);
proto_tree_add_boolean(ecos_flag_tree, hf_ecos_flags_critical, tvb, offset, 1, flags);
proto_tree_add_boolean(ecos_flag_tree, hf_ecos_flags_streaming, tvb, offset, 1, flags);
proto_tree_add_boolean(ecos_flag_tree, hf_ecos_flags_ordinal, tvb, offset, 1, flags);
offset += 1;
proto_tree_add_item(block_tree, hf_ecos_ordinal, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if ((flags & ECOS_FLAGS_ORDINAL) != 0) {
flow_label = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(block_tree, hf_ecos_flow_label, tvb, offset, sdnv_length, flow_label);
if (flow_label < 0) {
expert_add_info_format(pinfo, ti, &ei_bundle_sdnv_length, "ECOS Flow Label Error");
*lastheader = TRUE;
return offset;
}
offset += sdnv_length;
}
break;
}
default:
{
offset += block_length;
break;
}
}
return offset;
}
int
evaluate_sdnv(tvbuff_t *tvb, int offset, int *bytecount)
{
int value = 0;
guint8 curbyte;
*bytecount = 0;
while ((curbyte = tvb_get_guint8(tvb, offset)) & ~SDNV_MASK) {
if (*bytecount >= (int) sizeof(int)) {
*bytecount = 0;
return -1;
}
value = value << 7;
value |= (curbyte & SDNV_MASK);
++offset;
++*bytecount;
}
value = value << 7;
value |= (curbyte & SDNV_MASK);
++*bytecount;
return value;
}
gint64
evaluate_sdnv_64(tvbuff_t *tvb, int offset, int *bytecount)
{
gint64 value = 0;
guint8 curbyte;
*bytecount = 0;
while ((curbyte = tvb_get_guint8(tvb, offset)) & ~SDNV_MASK) {
if (*bytecount >= (int) sizeof(gint64)) {
*bytecount = 0;
return -1;
}
value = value << 7;
value |= (curbyte & SDNV_MASK);
++offset;
++*bytecount;
}
value = value << 7;
value |= (curbyte & SDNV_MASK);
++*bytecount;
return value;
}
static guint
get_dtn_contact_header_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int len, bytecount;
len = evaluate_sdnv(tvb, offset+8, &bytecount);
if (len < 0)
return 0;
return len+bytecount+8;
}
static int
dissect_dtn_contact_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *conv_proto_tree, *conv_tree, *conv_flag_tree;
int eid_length, sdnv_length;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TCPCL");
col_clear(pinfo->cinfo,COL_INFO);
ti = proto_tree_add_item(tree, proto_tcp_conv, tvb, offset, -1, ENC_NA);
conv_proto_tree = proto_item_add_subtree(ti, ett_tcp_conv);
ti = proto_tree_add_text(conv_proto_tree, tvb, offset, -1, "Contact Header");
conv_tree = proto_item_add_subtree(ti, ett_tcp_conv);
proto_tree_add_item(conv_tree, hf_contact_hdr_magic, tvb, offset, 4, ENC_NA|ENC_ASCII);
offset += 4;
proto_tree_add_item(conv_tree, hf_contact_hdr_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ti = proto_tree_add_item(conv_tree, hf_contact_hdr_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
conv_flag_tree = proto_item_add_subtree(ti, ett_contact_hdr_flags);
proto_tree_add_item(conv_flag_tree, hf_contact_hdr_flags_ack_req, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(conv_flag_tree, hf_contact_hdr_flags_frag_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(conv_flag_tree, hf_contact_hdr_flags_nak, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(conv_tree, hf_contact_hdr_keep_alive, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
eid_length = evaluate_sdnv(tvb, offset, &sdnv_length);
ti = proto_tree_add_int(tree, hf_contact_hdr_local_eid_length, tvb, offset, sdnv_length, eid_length);
if (eid_length < 0) {
expert_add_info(pinfo, ti, &ei_bundle_sdnv_length);
return offset;
}
proto_tree_add_item(conv_tree, hf_contact_hdr_local_eid, tvb, sdnv_length + offset, eid_length, ENC_NA|ENC_ASCII);
return tvb_length(tvb);
}
static guint
get_tcpcl_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
int len, bytecount;
guint8 conv_hdr = tvb_get_guint8(tvb, offset);
switch (conv_hdr & TCP_CONVERGENCE_TYPE_MASK)
{
case TCP_CONVERGENCE_DATA_SEGMENT:
case TCP_CONVERGENCE_ACK_SEGMENT:
len = evaluate_sdnv(tvb, offset+1, &bytecount);
if (len < 0)
return 0;
return len+bytecount+1;
case TCP_CONVERGENCE_KEEP_ALIVE:
case TCP_CONVERGENCE_REFUSE_BUNDLE:
return 1;
case TCP_CONVERGENCE_SHUTDOWN:
len = 1;
if (conv_hdr & TCP_CONVERGENCE_SHUTDOWN_REASON) {
len += 1;
}
if (conv_hdr & TCP_CONVERGENCE_SHUTDOWN_DELAY) {
len += 2;
}
return len;
}
return 0;
}
static int
dissect_tcpcl_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 conv_hdr;
int offset = 0;
int sdnv_length, segment_length, convergence_hdr_size;
proto_item *ci, *conv_item, *sub_item;
proto_tree *conv_proto_tree, *conv_tree, *sub_tree;
fragment_head *frag_msg;
tvbuff_t *new_tvb;
gboolean more_frags;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TCPCL");
col_clear(pinfo->cinfo,COL_INFO);
ci = proto_tree_add_item(tree, proto_tcp_conv, tvb, offset, -1, ENC_NA);
conv_proto_tree = proto_item_add_subtree(ci, ett_tcp_conv);
conv_item = proto_tree_add_text(conv_proto_tree, tvb, 0, -1, "TCP Convergence Header");
conv_tree = proto_item_add_subtree(conv_item, ett_tcp_conv_hdr);
conv_hdr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(conv_tree, hf_tcp_convergence_pkt_type, tvb, offset, 1, ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const((conv_hdr>>4)&0xF, packet_type_vals, "Unknown"));
switch (conv_hdr & TCP_CONVERGENCE_TYPE_MASK)
{
case TCP_CONVERGENCE_DATA_SEGMENT:
sub_item = proto_tree_add_item(conv_tree, hf_tcp_convergence_data_procflags, tvb,
offset, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_conv_flags);
proto_tree_add_item(sub_tree, hf_tcp_convergence_data_procflags_start,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_tcp_convergence_data_procflags_end,
tvb, offset, 1, ENC_BIG_ENDIAN);
if ((conv_hdr & ~(TCP_CONVERGENCE_TYPE_MASK | TCP_CONVERGENCE_DATA_FLAGS)) != 0) {
expert_add_info(pinfo, sub_item, &ei_tcp_convergence_data_flags);
}
segment_length = evaluate_sdnv(tvb, 1, &sdnv_length);
sub_item = proto_tree_add_int(conv_tree, hf_tcp_convergence_data_segment_length, tvb, 1, sdnv_length, segment_length);
if (segment_length < 0) {
expert_add_info(pinfo, sub_item, &ei_tcp_convergence_segment_length);
return 1;
}
convergence_hdr_size = sdnv_length + 1;
new_tvb = NULL;
sub_tree = NULL;
if ((conv_hdr & TCP_CONVERGENCE_DATA_END_FLAG) == TCP_CONVERGENCE_DATA_END_FLAG) {
more_frags = FALSE;
}
else {
more_frags = TRUE;
}
frag_msg = fragment_add_seq_next(&msg_reassembly_table,
tvb, offset + convergence_hdr_size,
pinfo, 0, NULL,
segment_length, more_frags);
if (frag_msg && !more_frags) {
sub_item = proto_tree_add_item(tree, proto_bundle, tvb, offset, -1, ENC_NA);
sub_tree = proto_item_add_subtree(sub_item, ett_bundle);
new_tvb = process_reassembled_data(tvb, offset + convergence_hdr_size,
pinfo, "Reassembled DTN", frag_msg,
&msg_frag_items, NULL, sub_tree);
}
if (new_tvb) {
int bundle_size = call_dissector(bundle_handle, new_tvb, pinfo, sub_tree);
if (bundle_size == 0) {
call_dissector(data_handle, new_tvb, pinfo, sub_tree);
return tvb_length(tvb);
}
}
else {
col_set_str(pinfo->cinfo, COL_INFO, "[Reassembled Segment of a Bundle]");
}
break;
case TCP_CONVERGENCE_ACK_SEGMENT:
segment_length = evaluate_sdnv(tvb, offset+1, &sdnv_length);
sub_item = proto_tree_add_int(conv_tree, hf_tcp_convergence_ack_length, tvb, offset+1, sdnv_length, segment_length);
if (segment_length < 0) {
expert_add_info(pinfo, sub_item, &ei_tcp_convergence_ack_length);
}
break;
case TCP_CONVERGENCE_KEEP_ALIVE:
break;
case TCP_CONVERGENCE_SHUTDOWN:
sub_item = proto_tree_add_item(conv_tree, hf_tcp_convergence_shutdown_flags, tvb,
offset, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_item, ett_shutdown_flags);
proto_tree_add_item(sub_tree, hf_tcp_convergence_shutdown_flags_reason,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_tcp_convergence_shutdown_flags_delay,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (conv_hdr & TCP_CONVERGENCE_SHUTDOWN_REASON) {
proto_tree_add_item(conv_tree,
hf_tcp_convergence_shutdown_reason, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (conv_hdr & TCP_CONVERGENCE_SHUTDOWN_DELAY) {
proto_tree_add_item(conv_tree,
hf_tcp_convergence_shutdown_delay, tvb,
offset, 2, ENC_BIG_ENDIAN);
}
break;
case TCP_CONVERGENCE_REFUSE_BUNDLE:
break;
}
return tvb_length(tvb);
}
static int
dissect_tcpcl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint8 conv_hdr;
int offset, bytecount;
if (!tvb_bytes_exist(tvb, 0, 1))
return 0;
conv_hdr = tvb_get_guint8(tvb, 0);
switch (conv_hdr & TCP_CONVERGENCE_TYPE_MASK)
{
case TCP_CONVERGENCE_DATA_SEGMENT:
case TCP_CONVERGENCE_ACK_SEGMENT:
offset = 1;
bytecount = 1;
if (!tvb_bytes_exist(tvb, offset, 1))
return 0;
while (tvb_get_guint8(tvb, offset) & ~SDNV_MASK) {
if (bytecount > (int)sizeof(int)) {
return 0;
}
if (!tvb_bytes_exist(tvb, offset, 1))
return 0;
bytecount++;
offset++;
}
break;
case TCP_CONVERGENCE_KEEP_ALIVE:
case TCP_CONVERGENCE_REFUSE_BUNDLE:
break;
case TCP_CONVERGENCE_SHUTDOWN:
if ((conv_hdr &
~(TCP_CONVERGENCE_TYPE_MASK | TCP_CONVERGENCE_SHUTDOWN_FLAGS)) != 0) {
return 0;
}
break;
default:
if (conv_hdr == (guint8)magic[0]) {
if (!tvb_bytes_exist(tvb, 0, 4) || tvb_memeql(tvb, 0, magic, 4)) {
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 8, get_dtn_contact_header_len, dissect_dtn_contact_header, data);
return tvb_length(tvb);
}
return 0;
};
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 1, get_tcpcl_pdu_len, dissect_tcpcl_pdu, data);
return tvb_length(tvb);
}
static int
dissect_bundle(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *bundle_tree, *primary_tree;
int primary_header_size;
gboolean lastheader = FALSE;
int offset = 0;
guint8 version, pri_hdr_procflags;
gchar *bundle_custodian = NULL;
version = tvb_get_guint8(tvb, offset);
if ((version != 4) && (version != 5) && (version != 6)) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Bundle");
col_clear(pinfo->cinfo,COL_INFO);
ti = proto_tree_add_item(tree, proto_bundle, tvb, offset, -1, ENC_NA);
bundle_tree = proto_item_add_subtree(ti, ett_bundle);
ti = proto_tree_add_text(tree, tvb, offset, -1, "Primary Bundle Header");
primary_tree = proto_item_add_subtree(ti, ett_primary_hdr);
proto_tree_add_item(primary_tree, hf_bundle_pdu_version, tvb, offset, 1, ENC_BIG_ENDIAN);
if (version == 4) {
primary_header_size = dissect_version_4_primary_header(pinfo, primary_tree, tvb,
&pri_hdr_procflags, &bundle_custodian);
}
else {
primary_header_size = dissect_version_5_and_6_primary_header(pinfo, primary_tree, tvb,
&pri_hdr_procflags, &bundle_custodian);
}
if (primary_header_size == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "Protocol Error");
return(0);
}
proto_item_set_len(ti, primary_header_size);
offset = primary_header_size;
while (lastheader == FALSE) {
guint8 next_header_type;
next_header_type = tvb_get_guint8(tvb, offset);
if (next_header_type == BUNDLE_BLOCK_TYPE_PAYLOAD) {
offset = dissect_payload_header(bundle_tree, tvb, pinfo, offset, version, pri_hdr_procflags, &lastheader);
}
else {
offset = display_metadata_block(bundle_tree, tvb, pinfo, offset, bundle_custodian, &lastheader);
}
}
return(offset);
}
static void
bundle_defragment_init(void) {
reassembly_table_init(&msg_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_bundle(void)
{
static hf_register_info hf[] = {
{&hf_bundle_pdu_version,
{"Bundle Version", "bundle.version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_fragments,
{"Message Fragments", "bundle.msg.fragments",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_fragment,
{"Message Fragment", "bundle.msg.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_fragment_overlap,
{"Message fragment overlap", "bundle.msg.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"bundle.msg.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_fragment_multiple_tails,
{"Message has multiple tails", "bundle.msg.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_fragment_too_long_fragment,
{"Message fragment too long", "bundle.msg.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_fragment_error,
{"Message defragmentation error", "bundle.msg.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_fragment_count,
{"Message fragment count", "bundle.msg.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_reassembled_in,
{"Reassembled in", "bundle.msg.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_msg_reassembled_length,
{"Reassembled DTN length", "bundle.msg.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_procflags,
{"Primary Header Processing Flags", "bundle.primary.proc.flag",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_procflags_fragment,
{"Bundle is a Fragment", "bundle.primary.proc.frag",
FT_BOOLEAN, 8, NULL, BUNDLE_PROCFLAGS_FRAG_MASK, NULL, HFILL}
},
{&hf_bundle_procflags_admin,
{"Administrative Record", "bundle.primary.proc.admin",
FT_BOOLEAN, 8, NULL, BUNDLE_PROCFLAGS_ADMIN_MASK, NULL, HFILL}
},
{&hf_bundle_procflags_dont_fragment,
{"Do Not Fragment Bundle", "bundle.primary.proc.dontfrag",
FT_BOOLEAN, 8, NULL, BUNDLE_PROCFLAGS_DONTFRAG_MASK, NULL, HFILL}
},
{&hf_bundle_procflags_cust_xfer_req,
{"Request Custody Transfer", "bundle.primary.proc.xferreq",
FT_BOOLEAN, 8, NULL, BUNDLE_PROCFLAGS_XFERREQ_MASK, NULL, HFILL}
},
{&hf_bundle_procflags_dest_singleton,
{"Destination is Singleton", "bundle.primary.proc.single",
FT_BOOLEAN, 8, NULL, BUNDLE_PROCFLAGS_SINGLETON_MASK, NULL, HFILL}
},
{&hf_bundle_procflags_application_ack,
{"Request Acknowledgement by Application", "bundle.primary.proc.ack",
FT_BOOLEAN, 8, NULL, BUNDLE_PROCFLAGS_APP_ACK_MASK, NULL, HFILL}
},
{&hf_bundle_control_flags,
{"Bundle Processing Control Flags", "bundle.primary.proc.flag",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_procflags_general,
{"General Flags", "bundle.primary.proc.gen",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_procflags_cos,
{"Cloass of Service Flags", "bundle.primary.proc.cos",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_procflags_status,
{"Status Report Flags", "bundle.primary.proc.status",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_cosflags,
{"Primary Header COS Flags", "bundle.primary.cos.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_cosflags_priority,
{"Priority", "bundle.primary.cos.priority",
FT_UINT8, BASE_DEC, VALS(cosflags_priority_vals), BUNDLE_COSFLAGS_PRIORITY_MASK, NULL, HFILL}
},
{&hf_bundle_srrflags,
{"Primary Header Report Request Flags", "bundle.primary.srr.flag",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_srrflags_report_receipt,
{"Request Reception Report", "bundle.primary.srr.report",
FT_BOOLEAN, 8, NULL, BUNDLE_SRRFLAGS_REPORT_MASK, NULL, HFILL}
},
{&hf_bundle_srrflags_report_cust_accept,
{"Request Report of Custody Acceptance", "bundle.primary.srr.custaccept",
FT_BOOLEAN, 8, NULL, BUNDLE_SRRFLAGS_CUSTODY_MASK, NULL, HFILL}
},
{&hf_bundle_srrflags_report_forward,
{"Request Report of Bundle Forwarding", "bundle.primary.srr.forward",
FT_BOOLEAN, 8, NULL, BUNDLE_SRRFLAGS_FORWARD_MASK, NULL, HFILL}
},
{&hf_bundle_srrflags_report_delivery,
{"Request Report of Bundle Delivery", "bundle.primary.srr.delivery",
FT_BOOLEAN, 8, NULL, BUNDLE_SRRFLAGS_DELIVERY_MASK, NULL, HFILL}
},
{&hf_bundle_srrflags_report_deletion,
{"Request Report of Bundle Deletion", "bundle.primary.srr.delete",
FT_BOOLEAN, 8, NULL, BUNDLE_SRRFLAGS_DELETION_MASK, NULL, HFILL}
},
{&hf_bundle_srrflags_report_ack,
{"Request Report of Application Ack", "bundle.primary.srr.ack",
FT_BOOLEAN, 8, NULL, BUNDLE_SRRFLAGS_ACK_MASK, NULL, HFILL}
},
{&hf_bundle_primary_header_len,
{"Bundle Header Length", "bundle.primary.len",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_primary_dictionary_len,
{"Dictionary Length", "bundle.primary.dictionary_len",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_primary_fragment_offset,
{"Fragment Offset", "bundle.primary.fragment_offset",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_primary_total_adu_len,
{"Total Application Data Unit Length", "bundle.primary.total_adu_len",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_primary_timestamp_seq_num64,
{"Timestamp Sequence Number", "bundle.primary.timestamp_seq_num",
FT_INT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_primary_timestamp_seq_num32,
{"Timestamp Sequence Number", "bundle.primary.timestamp_seq_num",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_primary_timestamp,
{"Timestamp", "bundle.primary.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_dest_scheme_offset_u16,
{"Destination Scheme Offset", "bundle.primary.destschemeoff",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_dest_scheme_offset_i32,
{"Destination Scheme Offset", "bundle.primary.destschemeoff",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_dest_ssp_offset_u16,
{"Destination SSP Offset", "bundle.primary.destssspoff",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_dest_ssp_offset_i32,
{"Destination SSP Offset", "bundle.primary.destssspoff",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_source_scheme_offset_u16,
{"Source Scheme Offset", "bundle.primary.srcschemeoff",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_source_scheme_offset_i32,
{"Source Scheme Offset", "bundle.primary.srcschemeoff",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_source_ssp_offset_u16,
{"Source SSP Offset", "bundle.primary.srcsspoff",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_source_ssp_offset_i32,
{"Source SSP Offset", "bundle.primary.srcsspoff",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_report_scheme_offset_u16,
{"Report Scheme Offset", "bundle.primary.rptschemeoff",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_report_scheme_offset_i32,
{"Report Scheme Offset", "bundle.primary.rptschemeoff",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_report_ssp_offset_u16,
{"Report SSP Offset", "bundle.primary.rptsspoff",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_report_ssp_offset_i32,
{"Report SSP Offset", "bundle.primary.rptsspoff",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_cust_scheme_offset_u16,
{"Custodian Scheme Offset", "bundle.primary.custschemeoff",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_cust_scheme_offset_i32,
{"Custodian Scheme Offset", "bundle.primary.custschemeoff",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_cust_ssp_offset_u16,
{"Custodian SSP Offset", "bundle.primary.custsspoff",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_cust_ssp_offset_i32,
{"Custodian SSP Offset", "bundle.primary.custsspoff",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_dest_scheme,
{"Destination Scheme", "bundle.primary.destination_scheme",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_dest_ssp,
{"Destination", "bundle.primary.destination",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_source_scheme,
{"Source Scheme", "bundle.primary.source_scheme",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_source_ssp,
{"Source", "bundle.primary.source",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_report_scheme,
{"Report Scheme", "bundle.primary.report_scheme",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_report_ssp,
{"Report", "bundle.primary.report",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_custodian_scheme,
{"Custodian Scheme", "bundle.primary.custodian_scheme",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_custodian_ssp,
{"Custodian", "bundle.primary.custodian",
FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_creation_timestamp,
{"Creation Timestamp", "bundle.primary.timestamp",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_lifetime,
{"Lifetime", "bundle.primary.lifetime",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_lifetime_sdnv,
{"Lifetime", "bundle.primary.lifetime",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_payload_length,
{"Payload Length", "bundle.payload.length",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_payload_flags,
{"Payload Header Processing Flags", "bundle.payload.proc.flag",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_payload_flags_replicate_hdr,
{"Replicate Header in Every Fragment", "bundle.payload.proc.replicate",
FT_BOOLEAN, 8, NULL, PAYLOAD_PROCFLAGS_REPLICATE_MASK, NULL, HFILL}
},
{&hf_bundle_payload_flags_xmit_report,
{"Report if Can't Process Header", "bundle.payload.proc.report",
FT_BOOLEAN, 8, NULL, PAYLOAD_PROCFLAGS_XMIT_STATUS, NULL, HFILL}
},
{&hf_bundle_payload_flags_discard_on_fail,
{"Discard if Can't Process Header", "bundle.payload.proc.discard",
FT_BOOLEAN, 8, NULL, PAYLOAD_PROCFLAGS_DISCARD_FAILURE, NULL, HFILL}
},
{&hf_bundle_payload_flags_last_header,
{"Last Header", "bundle.payload.proc.lastheader",
FT_BOOLEAN, 8, NULL, PAYLOAD_PROCFLAGS_LAST_HEADER, NULL, HFILL}
},
{&hf_bundle_admin_record_type,
{"Administrative Record Type", "bundle.admin.record_type",
FT_UINT8, BASE_DEC, VALS(admin_record_type_vals), 0xF0, NULL, HFILL}
},
{&hf_bundle_admin_record_fragment,
{"Administrative Record Type", "bundle.admin.record_type",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), ADMIN_REC_FLAGS_FRAGMENT, NULL, HFILL}
},
{&hf_bundle_admin_statflags,
{"Administrative Record Status Flags", "bundle.admin.status.flag",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_rcvd,
{"Reporting Node Received Bundle", "bundle.admin.status.rcvd",
FT_BOOLEAN, 8, NULL, ADMIN_STATUS_FLAGS_RECEIVED, NULL, HFILL}
},
{&hf_bundle_admin_accepted,
{"Reporting Node Accepted Custody", "bundle.admin.status.accept",
FT_BOOLEAN, 8, NULL, ADMIN_STATUS_FLAGS_ACCEPTED, NULL, HFILL}
},
{&hf_bundle_admin_forwarded,
{"Reporting Node Forwarded Bundle", "bundle.admin.status.forward",
FT_BOOLEAN, 8, NULL, ADMIN_STATUS_FLAGS_FORWARDED, NULL, HFILL}
},
{&hf_bundle_admin_delivered,
{"Reporting Node Delivered Bundle", "bundle.admin.status.delivered",
FT_BOOLEAN, 8, NULL, ADMIN_STATUS_FLAGS_DELIVERED, NULL, HFILL}
},
{&hf_bundle_admin_deleted,
{"Reporting Node Deleted Bundle", "bundle.admin.status.delete",
FT_BOOLEAN, 8, NULL, ADMIN_STATUS_FLAGS_DELETED, NULL, HFILL}
},
{&hf_bundle_admin_acked,
{"Acknowledged by Application", "bundle.admin.status.ack",
FT_BOOLEAN, 8, NULL, ADMIN_STATUS_FLAGS_ACKNOWLEDGED, NULL, HFILL}
},
{&hf_bundle_admin_fragment_offset,
{"Fragment Offset", "bundle.admin.fragment_offset",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_fragment_length,
{"Fragment Length", "bundle.admin.fragment_length",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_timestamp_seq_num64,
{"Timestamp Sequence Number", "bundle.admin.timestamp_seq_num",
FT_INT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_timestamp_seq_num32,
{"Timestamp Sequence Number", "bundle.admin.timestamp_seq_num",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_endpoint_length,
{"Endpoint Length", "bundle.admin.endpoint_length",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_endpoint_id,
{"Bundle Endpoint ID", "bundle.admin.endpoint_id",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_receipt_time,
{"Bundle Received Time", "bundle.admin.status.receipttime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_accept_time,
{"Bundle Accepted Time", "bundle.admin.status.accepttime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_forward_time,
{"Bundle Forwarded Time", "bundle.admin.status.forwardtime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_delivery_time,
{"Bundle Delivered Time", "bundle.admin.status.deliverytime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_delete_time,
{"Bundle Deleted Time", "bundle.admin.status.deletetime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_ack_time,
{"Bundle Acknowledged Time", "bundle.admin.status.acktime",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_timestamp_copy,
{"Bundle Creation Timestamp", "bundle.admin.status.timecopy",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_admin_signal_time,
{"Bundle Signal Time", "bundle.admin.signal.time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}
},
{&hf_block_control_flags,
{"Block Processing Control Flags", "bundle.block.control.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_block_control_flags_sdnv,
{"Block Processing Control Flags", "bundle.block.control.flags",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_block_control_block_length,
{"Block Length", "bundle.block.length",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_block_control_block_cteb_custody_id,
{"CTEB Custody ID", "bundle.block.cteb_custody_id",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_block_control_block_cteb_creator_custodian_eid,
{"CTEB Creator Custodian EID", "bundle.block.cteb_creator_custodian_eid",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_block_control_replicate,
{"Replicate Block in Every Fragment", "bundle.block.control.replicate",
FT_BOOLEAN, 8, NULL, BLOCK_CONTROL_REPLICATE, NULL, HFILL}
},
{&hf_block_control_transmit_status,
{"Transmit Status if Block Can't be Processeed", "bundle.block.control.status",
FT_BOOLEAN, 8, NULL, BLOCK_CONTROL_TRANSMIT_STATUS, NULL, HFILL}
},
{&hf_block_control_delete_bundle,
{"Delete Bundle if Block Can't be Processeed", "bundle.block.control.delete",
FT_BOOLEAN, 8, NULL, BLOCK_CONTROL_DELETE_BUNDLE, NULL, HFILL}
},
{&hf_block_control_last_block,
{"Last Block", "bundle.block.control.last",
FT_BOOLEAN, 8, NULL, BLOCK_CONTROL_LAST_BLOCK, NULL, HFILL}
},
{&hf_block_control_discard_block,
{"Discard Block If Can't Process", "bundle.block.control.discard",
FT_BOOLEAN, 8, NULL, BLOCK_CONTROL_DISCARD_BLOCK, NULL, HFILL}
},
{&hf_block_control_not_processed,
{"Block Was Forwarded Without Processing", "bundle.block.control.process",
FT_BOOLEAN, 8, NULL, BLOCK_CONTROL_NOT_PROCESSED, NULL, HFILL}
},
{&hf_block_control_eid_reference,
{"Block Contains an EID-reference Field", "bundle.block.control.eid",
FT_BOOLEAN, 8, NULL, BLOCK_CONTROL_EID_REFERENCE, NULL, HFILL}
},
{&hf_bundle_status_report_reason_code,
{"Status Report Reason Code", "bundle.status_report_reason_code",
FT_UINT8, BASE_DEC, VALS(status_report_reason_codes), 0x0, NULL, HFILL}
},
{&hf_bundle_custody_trf_succ_flg,
{"Custody Transfer Succeeded Flag", "bundle.custody_trf_succ_flg",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}
},
{&hf_bundle_custody_signal_reason,
{"Custody Signal Reason Code", "bundle.custody_signal_reason_code",
FT_UINT8, BASE_DEC, VALS(custody_signal_reason_codes), ADMIN_REC_CUSTODY_REASON_MASK, NULL, HFILL}
},
{&hf_bundle_custody_id_range_start,
{"CTEB Custody ID Range Start", "bundle.custody_id_range_start",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_custody_id_range_end,
{"CTEB Custody ID Range End", "bundle.custody_id_range_end",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_bundle_block_type_code,
{"Non-Primary Bundle Block Type Code", "bundle.block_type_code",
FT_UINT8, BASE_DEC, VALS(bundle_block_type_codes), 0x0, NULL, HFILL}
},
{&hf_ecos_flags,
{"ECOS Flags", "bundle.block.ecos.flags",
FT_UINT8, BASE_HEX, VALS(ecos_flags), 0x0, NULL, HFILL}
},
{&hf_ecos_flags_critical,
{"ECOS Critical Flag", "bundle.block.ecos.flags.critical",
FT_BOOLEAN, 8, NULL, ECOS_FLAGS_CRITICAL, NULL, HFILL}
},
{&hf_ecos_flags_streaming,
{"ECOS Streaming Flag", "bundle.block.ecos.flags.streaming",
FT_BOOLEAN, 8, NULL, ECOS_FLAGS_STREAMING, NULL, HFILL}
},
{&hf_ecos_flags_ordinal,
{"ECOS Ordinal Flag", "bundle.block.ecos.flags.ordinal",
FT_BOOLEAN, 8, NULL, ECOS_FLAGS_ORDINAL, NULL, HFILL}
},
{&hf_ecos_flow_label,
{"ECOS Flow Label", "bundle.block.ecos.flow_label",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_ecos_ordinal,
{"ECOS Ordinal", "bundle.block.ecos.ordinal",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
};
static hf_register_info hf_tcpcl[] = {
{&hf_tcp_convergence_pkt_type,
{"Pkt Type", "tcpcl.pkt_type",
FT_UINT8, BASE_DEC, VALS(packet_type_vals), 0xF0, NULL, HFILL}
},
{&hf_tcp_convergence_data_procflags,
{"TCP Convergence Data Flags", "tcpcl.data.proc.flag",
FT_UINT8, BASE_HEX, NULL, TCP_CONVERGENCE_DATA_FLAGS, NULL, HFILL}
},
{&hf_tcp_convergence_data_procflags_start,
{"Segment contains start of bundle", "tcpcl.data.proc.start",
FT_BOOLEAN, 8, NULL, TCP_CONVERGENCE_DATA_START_FLAG, NULL, HFILL}
},
{&hf_tcp_convergence_data_procflags_end,
{"Segment contains end of Bundle", "tcpcl.data.proc.end",
FT_BOOLEAN, 8, NULL, TCP_CONVERGENCE_DATA_END_FLAG, NULL, HFILL}
},
{&hf_tcp_convergence_data_segment_length,
{"Segment Length", "tcpcl.data.length",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_tcp_convergence_shutdown_flags,
{"TCP Convergence Shutdown Flags", "tcpcl.shutdown.flags",
FT_UINT8, BASE_HEX, NULL, TCP_CONVERGENCE_SHUTDOWN_FLAGS, NULL, HFILL}
},
{&hf_tcp_convergence_shutdown_flags_reason,
{"Shutdown includes Reason Code", "tcpcl.shutdown.reason.flag",
FT_BOOLEAN, 8, NULL, TCP_CONVERGENCE_SHUTDOWN_REASON, NULL, HFILL}
},
{&hf_tcp_convergence_shutdown_flags_delay,
{"Shutdown includes Reconnection Delay", "tcpcl.shutdown.delay.flag",
FT_BOOLEAN, 8, NULL, TCP_CONVERGENCE_SHUTDOWN_DELAY, NULL, HFILL}
},
{&hf_tcp_convergence_shutdown_reason,
{"Shutdown Reason Code", "tcpcl.shutdown.reason",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_tcp_convergence_shutdown_delay,
{"Shutdown Reconnection Delay", "tcpcl.shutdown.delay",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_tcp_convergence_ack_length,
{"Ack Length", "tcpcl.ack.length",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_contact_hdr_version,
{"Version", "tcpcl.contact_hdr.version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_contact_hdr_flags,
{"Flags", "tcpcl.contact_hdr.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_contact_hdr_flags_ack_req,
{"Bundle Acks Requested", "tcpcl.contact_hdr.flags.ackreq",
FT_BOOLEAN, 8, NULL, TCP_CONV_BUNDLE_ACK_FLAG, NULL, HFILL}
},
{&hf_contact_hdr_flags_frag_enable,
{"Reactive Fragmentation Enabled", "tcpcl.contact_hdr.flags.fragen",
FT_BOOLEAN, 8, NULL, TCP_CONV_REACTIVE_FRAG_FLAG, NULL, HFILL}
},
{&hf_contact_hdr_flags_nak,
{"Support Negative Acknowledgements", "tcpcl.contact_hdr.flags.nak",
FT_BOOLEAN, 8, NULL, TCP_CONV_CONNECTOR_RCVR_FLAG, NULL, HFILL}
},
{&hf_contact_hdr_keep_alive,
{"Keep Alive", "tcpcl.contact_hdr.keep_alive",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_contact_hdr_magic,
{"Magic", "tcpcl.contact_hdr.magic",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_contact_hdr_local_eid,
{"Local EID", "tcpcl.contact_hdr.local_eid",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_contact_hdr_local_eid_length,
{"Local EID Length", "tcpcl.contact_hdr.local_eid_length",
FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
};
static gint *ett[] = {
&ett_bundle,
&ett_bundle_hdr,
&ett_primary_hdr,
&ett_proc_flags,
&ett_gen_flags,
&ett_cos_flags,
&ett_srr_flags,
&ett_dictionary,
&ett_payload_hdr,
&ett_payload_flags,
&ett_block_flags,
&ett_contact_hdr_flags,
&ett_conv_flags,
&ett_shutdown_flags,
&ett_admin_record,
&ett_admin_rec_status,
&ett_metadata_hdr
};
static gint *ett_tcpcl[] = {
&ett_tcp_conv,
&ett_tcp_conv_hdr,
&ett_msg_fragment,
&ett_msg_fragments,
};
static ei_register_info ei[] = {
{ &ei_bundle_control_flags_length,
{ "bundle.block.control.flags.length", PI_UNDECODED, PI_WARN, "Wrong bundle control flag length", EXPFILL }
},
{ &ei_bundle_payload_length,
{ "bundle.payload.length.invalid", PI_PROTOCOL, PI_ERROR, "Payload length error", EXPFILL }
},
{ &ei_bundle_sdnv_length,
{ "bundle.sdnv_length_invalid", PI_PROTOCOL, PI_ERROR, "SDNV length error", EXPFILL }
},
{ &ei_bundle_timestamp_seq_num,
{ "bundle.timestamp_seq_num_invalid", PI_PROTOCOL, PI_ERROR, "Timestamp Sequence Number error", EXPFILL }
},
{ &ei_bundle_offset_error,
{ "bundle.offset_error", PI_PROTOCOL, PI_WARN, "Offset field error", EXPFILL }
},
{ &ei_bundle_block_control_flags,
{ "bundle.block.control.flags.error", PI_PROTOCOL, PI_WARN, "Control flag error", EXPFILL }
},
{ &ei_block_control_block_cteb_invalid,
{ "bundle.block.control.cteb_invalid", PI_PROTOCOL, PI_WARN, "CTEB Is Invalid", EXPFILL }
},
{ &ei_block_control_block_cteb_valid,
{ "bundle.block.control.cteb_valid", PI_PROTOCOL, PI_NOTE, "CTEB Is Valid", EXPFILL }
},
};
static ei_register_info ei_tcpcl[] = {
{ &ei_tcp_convergence_data_flags,
{ "tcpcl.data.flags.invalid", PI_PROTOCOL, PI_WARN, "Invalid TCP CL Data Segment Flags", EXPFILL }
},
{ &ei_tcp_convergence_segment_length,
{ "tcpcl.data.length.invalid", PI_PROTOCOL, PI_ERROR, "Invalid Data Length", EXPFILL }
},
{ &ei_tcp_convergence_ack_length,
{ "tcpcl.ack.length.error", PI_PROTOCOL, PI_WARN, "Ack Length: Error", EXPFILL }
},
};
module_t *bundle_module;
expert_module_t *expert_bundle, *expert_tcpcl;
proto_bundle = proto_register_protocol("Bundle Protocol", "Bundle", "bundle");
bundle_handle = new_register_dissector("bundle", dissect_bundle, proto_bundle);
bundle_module = prefs_register_protocol(proto_bundle, proto_reg_handoff_bundle);
proto_tcp_conv = proto_register_protocol ("DTN TCP Convergence Layer Protocol", "TCPCL", "tcpcl");
prefs_register_uint_preference(bundle_module, "tcp.port",
"Bundle Protocol TCP Port",
"TCP Port to Accept Bundle Protocol Connections",
10,
&bundle_tcp_port);
prefs_register_uint_preference(bundle_module, "udp.port",
"Bundle Protocol UDP Port",
"UDP Port to Accept Bundle Protocol Connections",
10,
&bundle_udp_port);
proto_register_field_array(proto_bundle, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bundle = expert_register_protocol(proto_bundle);
expert_register_field_array(expert_bundle, ei, array_length(ei));
proto_register_field_array(proto_tcp_conv, hf_tcpcl, array_length(hf_tcpcl));
proto_register_subtree_array(ett_tcpcl, array_length(ett_tcpcl));
expert_tcpcl = expert_register_protocol(proto_tcp_conv);
expert_register_field_array(expert_tcpcl, ei_tcpcl, array_length(ei_tcpcl));
register_init_routine(bundle_defragment_init);
}
void
proto_reg_handoff_bundle(void)
{
static dissector_handle_t tcpcl_handle;
static guint tcp_port;
static guint udp_port;
static int Initialized = FALSE;
if (!Initialized) {
tcpcl_handle = new_create_dissector_handle(dissect_tcpcl, proto_bundle);
data_handle = find_dissector("data");
Initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", tcp_port, tcpcl_handle);
dissector_delete_uint("udp.port", udp_port, bundle_handle);
}
tcp_port = bundle_tcp_port;
udp_port = bundle_udp_port;
dissector_add_uint("tcp.port", tcp_port, tcpcl_handle);
dissector_add_uint("udp.port", udp_port, bundle_handle);
}
