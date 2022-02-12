static void reassembly_reset(channel_sequence_analysis_status *status)
{
status->reassembly_info = wmem_new0(wmem_file_scope(), rlc_channel_reassembly_info);
}
static void reassembly_destroy(channel_sequence_analysis_status *status)
{
status->reassembly_info = NULL;
}
static void reassembly_add_segment(channel_sequence_analysis_status *status,
guint16 SN, guint32 frame,
tvbuff_t *tvb, gint offset, gint length)
{
int segment_number = status->reassembly_info->number_of_segments;
guint8 *segment_data;
if (segment_number >= (RLC_MAX_SEGMENTS-1)) {
reassembly_destroy(status);
return;
}
segment_data = (guint8 *)wmem_alloc(wmem_file_scope(), length);
memcpy(segment_data, tvb_get_ptr(tvb, offset, length), length);
status->reassembly_info->segments[segment_number].frameNum = frame;
status->reassembly_info->segments[segment_number].SN = SN;
status->reassembly_info->segments[segment_number].data = segment_data;
status->reassembly_info->segments[segment_number].length = length;
status->reassembly_info->number_of_segments++;
}
static void reassembly_record(channel_sequence_analysis_status *status, packet_info *pinfo,
guint16 SN, rlc_lte_info *p_rlc_lte_info)
{
g_hash_table_insert(reassembly_report_hash,
get_report_hash_key(SN, pinfo->fd->num, p_rlc_lte_info, TRUE),
status->reassembly_info);
}
static tvbuff_t* reassembly_get_reassembled_tvb(rlc_channel_reassembly_info *reassembly_info,
tvbuff_t *parent_tvb, packet_info *pinfo)
{
gint n;
guint combined_length = 0;
guint8 *combined_data;
guint combined_offset = 0;
tvbuff_t *reassembled_tvb;
for (n=0; n < reassembly_info->number_of_segments; n++) {
combined_length += reassembly_info->segments[n].length;
}
combined_data = (guint8 *)g_malloc(combined_length);
for (n=0; n < reassembly_info->number_of_segments; n++) {
guint8 *data = reassembly_info->segments[n].data;
int length = reassembly_info->segments[n].length;
memcpy(combined_data+combined_offset, data, length);
combined_offset += length;
}
reassembled_tvb = tvb_new_child_real_data(parent_tvb, combined_data, combined_offset, combined_offset);
tvb_set_free_cb(reassembled_tvb, g_free);
add_new_data_source(pinfo, reassembled_tvb, "Reassembled SDU");
return reassembled_tvb;
}
static void reassembly_show_source(rlc_channel_reassembly_info *reassembly_info,
proto_tree *tree, tvbuff_t *tvb, gint offset)
{
int n;
proto_item *source_ti, *ti;
proto_tree *source_tree;
proto_item *segment_ti;
proto_tree *segment_tree;
guint total_length=0;
source_ti = proto_tree_add_item(tree,
hf_rlc_lte_reassembly_source,
tvb, 0, 0, ENC_ASCII|ENC_NA);
source_tree = proto_item_add_subtree(source_ti, ett_rlc_lte_reassembly_source);
PROTO_ITEM_SET_GENERATED(source_ti);
for (n=0; n < reassembly_info->number_of_segments; n++) {
total_length += reassembly_info->segments[n].length;
}
proto_item_append_text(source_ti, " %u segments, %u bytes", reassembly_info->number_of_segments,
total_length);
ti = proto_tree_add_uint(source_tree,
hf_rlc_lte_reassembly_source_number_of_segments,
tvb, 0, 0, reassembly_info->number_of_segments);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(source_tree,
hf_rlc_lte_reassembly_source_total_length,
tvb, 0, 0, total_length);
PROTO_ITEM_SET_GENERATED(ti);
for (n=0; n < reassembly_info->number_of_segments; n++) {
rlc_segment *segment = &(reassembly_info->segments[n]);
proto_item_append_text(source_ti, " (SN=%u frame=%u len=%u)",
segment->SN, segment->frameNum, segment->length);
segment_ti = proto_tree_add_item(source_tree,
hf_rlc_lte_reassembly_source_segment,
tvb,
(n == reassembly_info->number_of_segments-1) ? offset : 0,
(n == reassembly_info->number_of_segments-1) ? segment->length : 0,
ENC_NA);
segment_tree = proto_item_add_subtree(segment_ti, ett_rlc_lte_reassembly_source_segment);
proto_item_append_text(segment_ti, " (SN=%u frame=%u length=%u)",
segment->SN, segment->frameNum, segment->length);
PROTO_ITEM_SET_GENERATED(segment_ti);
ti = proto_tree_add_uint(segment_tree, hf_rlc_lte_reassembly_source_segment_sn,
tvb, 0, 0, segment->SN);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(segment_tree, hf_rlc_lte_reassembly_source_segment_framenum,
tvb, 0, 0, segment->frameNum);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(segment_tree, hf_rlc_lte_reassembly_source_segment_length,
tvb, 0, 0, segment->length);
PROTO_ITEM_SET_GENERATED(ti);
}
}
static void write_pdu_label_and_info(proto_item *pdu_ti, proto_item *sub_ti,
packet_info *pinfo, const char *format, ...)
{
#define MAX_INFO_BUFFER 256
static char info_buffer[MAX_INFO_BUFFER];
va_list ap;
va_start(ap, format);
g_vsnprintf(info_buffer, MAX_INFO_BUFFER, format, ap);
va_end(ap);
col_append_str(pinfo->cinfo, COL_INFO, info_buffer);
proto_item_append_text(pdu_ti, "%s", info_buffer);
if (sub_ti != NULL) {
proto_item_append_text(sub_ti, "%s", info_buffer);
}
}
static void write_pdu_label_and_info_literal(proto_item *pdu_ti, proto_item *sub_ti,
packet_info *pinfo, const char *info_buffer)
{
col_append_str(pinfo->cinfo, COL_INFO, info_buffer);
proto_item_append_text(pdu_ti, "%s", info_buffer);
if (sub_ti != NULL) {
proto_item_append_text(sub_ti, "%s", info_buffer);
}
}
static int dissect_rlc_lte_extension_header(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree,
int offset)
{
guint8 isOdd;
guint64 extension = 1;
guint64 length;
s_number_of_extensions = 0;
while (extension && (s_number_of_extensions < MAX_RLC_SDUS)) {
proto_tree *extension_part_tree;
proto_item *extension_part_ti;
isOdd = (s_number_of_extensions % 2);
extension_part_ti = proto_tree_add_string_format(tree,
hf_rlc_lte_extension_part,
tvb, offset, 2,
"",
"Extension Part");
extension_part_tree = proto_item_add_subtree(extension_part_ti,
ett_rlc_lte_extension_part);
proto_tree_add_bits_ret_val(extension_part_tree, hf_rlc_lte_extension_e, tvb,
(offset*8) + ((isOdd) ? 4 : 0),
1,
&extension, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(extension_part_tree, hf_rlc_lte_extension_li, tvb,
(offset*8) + ((isOdd) ? 5 : 1),
11,
&length, ENC_BIG_ENDIAN);
proto_item_append_text(extension_part_tree, " (length=%u)", (guint16)length);
if (isOdd) {
offset += 2;
} else {
offset++;
}
s_lengths[s_number_of_extensions++] = (guint16)length;
}
isOdd = (s_number_of_extensions % 2);
if (isOdd) {
proto_tree_add_item(tree, hf_rlc_lte_extension_padding,
tvb, offset++, 1, ENC_BIG_ENDIAN);
}
return offset;
}
static void show_PDU_in_info(packet_info *pinfo,
proto_item *top_ti,
gint32 length,
gboolean first_includes_start,
gboolean last_includes_end)
{
if (length > 0) {
write_pdu_label_and_info(top_ti, NULL, pinfo,
" %s%u-byte%s%s",
(first_includes_start) ? "[" : "..",
length,
(length > 1) ? "s" : "",
(last_includes_end) ? "]" : "..");
}
else {
write_pdu_label_and_info(top_ti, NULL, pinfo,
" %sunknown-bytes%s",
(first_includes_start) ? "[" : "..",
(last_includes_end) ? "]" : "..");
}
}
static void show_PDU_in_tree(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, gint offset, gint length,
rlc_lte_info *rlc_info, gboolean whole_pdu, rlc_channel_reassembly_info *reassembly_info,
sequence_analysis_state state)
{
proto_item *data_ti = proto_tree_add_item(tree,
(rlc_info->rlcMode == RLC_AM_MODE) ?
hf_rlc_lte_am_data :
hf_rlc_lte_um_data,
tvb, offset, length, ENC_NA);
if (whole_pdu || (reassembly_info != NULL)) {
if (((global_rlc_lte_call_pdcp_for_srb) && (rlc_info->channelType == CHANNEL_TYPE_SRB)) ||
((global_rlc_lte_call_pdcp_for_drb != PDCP_drb_off) && (rlc_info->channelType == CHANNEL_TYPE_DRB))) {
static tvbuff_t *pdcp_tvb = NULL;
struct pdcp_lte_info *p_pdcp_lte_info;
if (reassembly_info == NULL) {
pdcp_tvb = tvb_new_subset(tvb, offset, length, length);
}
else {
pdcp_tvb = reassembly_get_reassembled_tvb(reassembly_info, tvb, pinfo);
reassembly_show_source(reassembly_info, tree, tvb, offset);
}
p_pdcp_lte_info = (pdcp_lte_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_pdcp_lte, 0);
if (p_pdcp_lte_info == NULL) {
p_pdcp_lte_info = wmem_new0(wmem_file_scope(), pdcp_lte_info);
p_add_proto_data(wmem_file_scope(), pinfo, proto_pdcp_lte, 0, p_pdcp_lte_info);
}
p_pdcp_lte_info->ueid = rlc_info->ueid;
p_pdcp_lte_info->channelType = Channel_DCCH;
p_pdcp_lte_info->channelId = rlc_info->channelId;
p_pdcp_lte_info->direction = rlc_info->direction;
p_pdcp_lte_info->is_retx = (state != SN_OK);
p_pdcp_lte_info->no_header_pdu = FALSE;
if (rlc_info->channelType == CHANNEL_TYPE_SRB) {
p_pdcp_lte_info->plane = SIGNALING_PLANE;
p_pdcp_lte_info->seqnum_length = 5;
}
else {
p_pdcp_lte_info->plane = USER_PLANE;
switch (global_rlc_lte_call_pdcp_for_drb) {
case PDCP_drb_SN_7:
p_pdcp_lte_info->seqnum_length = 7;
break;
case PDCP_drb_SN_12:
p_pdcp_lte_info->seqnum_length = 12;
break;
case PDCP_drb_SN_15:
p_pdcp_lte_info->seqnum_length = 15;
break;
case PDCP_drb_SN_signalled:
p_pdcp_lte_info->seqnum_length = signalled_pdcp_sn_bits;
break;
default:
DISSECTOR_ASSERT(FALSE);
break;
}
}
TRY {
call_dissector_only(pdcp_lte_handle, pdcp_tvb, pinfo, tree, NULL);
}
CATCH_ALL {
}
ENDTRY
PROTO_ITEM_SET_HIDDEN(data_ti);
}
else if (global_rlc_lte_call_rrc_for_mcch && (rlc_info->channelType == CHANNEL_TYPE_MCCH)) {
static tvbuff_t *rrc_tvb = NULL;
volatile dissector_handle_t protocol_handle;
if (reassembly_info == NULL) {
rrc_tvb = tvb_new_subset(tvb, offset, length, length);
}
else {
rrc_tvb = reassembly_get_reassembled_tvb(reassembly_info, tvb, pinfo);
reassembly_show_source(reassembly_info, tree, tvb, offset);
}
protocol_handle = find_dissector("lte_rrc.mcch");
TRY {
call_dissector_only(protocol_handle, rrc_tvb, pinfo, tree, NULL);
}
CATCH_ALL {
}
ENDTRY
PROTO_ITEM_SET_HIDDEN(data_ti);
}
else if (global_rlc_lte_call_ip_for_mtch && (rlc_info->channelType == CHANNEL_TYPE_MTCH)) {
static tvbuff_t *ip_tvb = NULL;
if (reassembly_info == NULL) {
ip_tvb = tvb_new_subset(tvb, offset, length, length);
}
else {
ip_tvb = reassembly_get_reassembled_tvb(reassembly_info, tvb, pinfo);
reassembly_show_source(reassembly_info, tree, tvb, offset);
}
TRY {
call_dissector_only(ip_handle, ip_tvb, pinfo, tree, NULL);
}
CATCH_ALL {
}
ENDTRY
PROTO_ITEM_SET_HIDDEN(data_ti);
}
}
}
static gint rlc_channel_equal(gconstpointer v, gconstpointer v2)
{
const channel_hash_key* val1 = (const channel_hash_key *)v;
const channel_hash_key* val2 = (const channel_hash_key *)v2;
return ((val1->ueId == val2->ueId) &&
(val1->channelType == val2->channelType) &&
(val1->channelId == val2->channelId) &&
(val1->direction == val2->direction));
}
static guint rlc_channel_hash_func(gconstpointer v)
{
const channel_hash_key* val1 = (const channel_hash_key *)v;
return ((val1->ueId * 1024) + (val1->channelType*64) + (val1->channelId*2) + val1->direction);
}
static gint rlc_result_hash_equal(gconstpointer v, gconstpointer v2)
{
const rlc_result_hash_key *val1 = (const rlc_result_hash_key *)v;
const rlc_result_hash_key *val2 = (const rlc_result_hash_key *)v2;
return (memcmp(val1, val2, sizeof(rlc_result_hash_key)) == 0);
}
static guint rlc_result_hash_func(gconstpointer v)
{
const rlc_result_hash_key* val1 = (const rlc_result_hash_key *)v;
return val1->frameNumber + val1->SN +
val1->channelType +
val1->channelId +
val1->direction;
}
static gpointer get_report_hash_key(guint16 SN, guint32 frameNumber,
rlc_lte_info *p_rlc_lte_info,
gboolean do_persist)
{
static rlc_result_hash_key key;
rlc_result_hash_key *p_key;
if (do_persist) {
p_key = wmem_new0(wmem_file_scope(), rlc_result_hash_key);
}
else {
memset(&key, 0, sizeof(rlc_result_hash_key));
p_key = &key;
}
p_key->frameNumber = frameNumber;
p_key->SN = SN;
p_key->channelType = p_rlc_lte_info->channelType;
p_key->channelId = p_rlc_lte_info->channelId;
p_key->direction = p_rlc_lte_info->direction;
return p_key;
}
static void checkFIconsistency(sequence_analysis_report *p,
rlc_lte_info *p_rlc_lte_info,
gboolean newSegmentStarted,
proto_tree *seqnum_tree,
packet_info *pinfo, tvbuff_t *tvb)
{
proto_item *ti;
if (p->previousSegmentIncomplete) {
if (newSegmentStarted) {
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_framing_info_correct,
tvb, 0, 0, FALSE);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_sequence_analysis_last_segment_not_continued,
"Last segment of previous PDU was not continued for UE %u (%s-%u)",
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
}
else {
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_framing_info_correct,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(ti);
}
}
else {
if (!newSegmentStarted) {
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_framing_info_correct,
tvb, 0, 0, FALSE);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_sequence_analysis_last_segment_complete,
"Last segment of previous PDU was complete, but new segment was not started on UE %u (%s-%u)",
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
}
else {
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_framing_info_correct,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_HIDDEN(ti);
}
}
PROTO_ITEM_SET_GENERATED(ti);
}
static void addChannelSequenceInfo(sequence_analysis_report *p,
gboolean isControlFrame,
rlc_lte_info *p_rlc_lte_info,
guint16 sequenceNumber,
gboolean newSegmentStarted,
rlc_lte_tap_info *tap_info,
packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb)
{
proto_tree *seqnum_tree;
proto_item *seqnum_ti;
proto_item *ti;
seqnum_ti = proto_tree_add_string_format(tree,
hf_rlc_lte_sequence_analysis,
tvb, 0, 0,
"", "Sequence Analysis");
seqnum_tree = proto_item_add_subtree(seqnum_ti,
ett_rlc_lte_sequence_analysis);
PROTO_ITEM_SET_GENERATED(seqnum_ti);
if (p->previousFrameNum != 0) {
ti = proto_tree_add_uint(seqnum_tree, hf_rlc_lte_sequence_analysis_previous_frame,
tvb, 0, 0, p->previousFrameNum);
PROTO_ITEM_SET_GENERATED(ti);
}
switch (p_rlc_lte_info->rlcMode) {
case RLC_AM_MODE:
switch (p->state) {
case SN_OK:
if (isControlFrame) {
return;
}
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
proto_item_append_text(seqnum_ti, " - OK");
if (p->nextFrameNum != 0) {
proto_tree_add_uint(seqnum_tree, hf_rlc_lte_sequence_analysis_next_frame,
tvb, 0, 0, p->nextFrameNum);
}
break;
case SN_MAC_Retx:
if (isControlFrame) {
return;
}
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_mac_retx,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_sequence_analysis_mac_retx,
"AM Frame retransmitted for %s on UE %u - due to MAC retx! (%s-%u)",
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, " - MAC retx of SN %u", p->firstSN);
break;
case SN_Retx:
if (isControlFrame) {
return;
}
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_retx,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_sequence_analysis_retx,
"AM Frame retransmitted for %s on UE %u - most likely in response to NACK (%s-%u)",
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, " - SN %u retransmitted", p->firstSN);
break;
case SN_Repeated:
if (isControlFrame) {
return;
}
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_repeated,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_sequence_analysis_repeated,
"AM SN Repeated for %s for UE %u - probably because didn't receive Status PDU? (%s-%u)",
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, "- SN %u Repeated", p->firstSN);
break;
case SN_Missing:
if (isControlFrame) {
return;
}
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_skipped,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
if (p->lastSN != p->firstSN) {
expert_add_info_format(pinfo, ti, &ei_rlc_lte_am_sn_missing,
"AM SNs (%u to %u) missing for %s on UE %u (%s-%u)",
p->firstSN, p->lastSN,
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, " - SNs missing (%u to %u)",
p->firstSN, p->lastSN);
tap_info->missingSNs = ((1024 + p->lastSN - p->firstSN) % 1024) + 1;
}
else {
expert_add_info_format(pinfo, ti, &ei_rlc_lte_am_sn_missing,
"AM SN (%u) missing for %s on UE %u (%s-%u)",
p->firstSN,
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, " - SN missing (%u)", p->firstSN);
tap_info->missingSNs = 1;
}
break;
case ACK_Out_of_Window:
if (!isControlFrame) {
return;
}
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ack_out_of_range,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(seqnum_tree, hf_rlc_lte_sequence_analysis_ack_out_of_range_opposite_frame,
tvb, 0, 0, p->previousFrameNum);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_sequence_analysis_ack_out_of_range_opposite_frame,
"AM ACK for SN %u - but last received SN in other direction is %u for UE %u (%s-%u)",
p->firstSN, p->sequenceExpected,
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, "- ACK SN %u Outside Rx Window - last received SN is %u",
p->firstSN, p->sequenceExpected);
break;
default:
return;
}
break;
case RLC_UM_MODE:
ti = proto_tree_add_uint(seqnum_tree, hf_rlc_lte_sequence_analysis_expected_sn,
tvb, 0, 0, p->sequenceExpected);
PROTO_ITEM_SET_GENERATED(ti);
if (p->sequenceExpectedCorrect) {
PROTO_ITEM_SET_HIDDEN(ti);
}
if (!p->sequenceExpectedCorrect) {
guint16 snLimit;
if (p_rlc_lte_info->UMSequenceNumberLength == 5) {
snLimit = 32;
}
else {
snLimit = 1024;
}
switch (p->state) {
case SN_Missing:
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_skipped,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
if (p->lastSN != p->firstSN) {
expert_add_info_format(pinfo, ti, &ei_rlc_lte_um_sn_missing,
"UM SNs (%u to %u) missing for %s on UE %u (%s-%u)",
p->firstSN, p->lastSN,
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, " - SNs missing (%u to %u)",
p->firstSN, p->lastSN);
tap_info->missingSNs = ((snLimit + p->lastSN - p->firstSN) % snLimit) + 1;
}
else {
expert_add_info_format(pinfo, ti, &ei_rlc_lte_um_sn_missing,
"UM SN (%u) missing for %s on UE %u (%s-%u)",
p->firstSN,
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, " - SN missing (%u)",
p->firstSN);
tap_info->missingSNs = 1;
}
break;
case SN_Repeated:
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_repeated,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_um_sn_repeated,
"UM SN (%u) repeated for %s for UE %u (%s-%u)",
p->firstSN,
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
proto_item_append_text(seqnum_ti, "- SN %u Repeated",
p->firstSN);
break;
case SN_MAC_Retx:
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_mac_retx,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_sequence_analysis_mac_retx,
"UM Frame retransmitted for %s on UE %u - due to MAC retx! (%s-%u)",
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
break;
default:
expert_add_info_format(pinfo, ti, &ei_rlc_lte_wrong_sequence_number,
"Wrong Sequence Number for %s on UE %u - got %u, expected %u (%s-%u)",
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid, sequenceNumber, p->sequenceExpected,
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
break;
}
}
else {
checkFIconsistency(p, p_rlc_lte_info, newSegmentStarted, seqnum_tree, pinfo, tvb);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
proto_item_append_text(seqnum_ti, " - OK");
}
if (p->nextFrameNum != 0) {
ti = proto_tree_add_uint(seqnum_tree, hf_rlc_lte_sequence_analysis_next_frame,
tvb, 0, 0, p->nextFrameNum);
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
static sequence_analysis_state checkChannelSequenceInfo(packet_info *pinfo, tvbuff_t *tvb,
rlc_lte_info *p_rlc_lte_info,
gboolean isControlFrame,
guint8 number_of_segments,
guint16 firstSegmentOffset,
guint16 firstSegmentLength,
guint16 lastSegmentOffset,
guint16 sequenceNumber,
gboolean first_includes_start, gboolean last_includes_end,
gboolean is_resegmented _U_,
rlc_lte_tap_info *tap_info,
proto_tree *tree)
{
channel_hash_key channel_key;
channel_hash_key *p_channel_key;
channel_sequence_analysis_status *p_channel_status;
sequence_analysis_report *p_report_in_frame = NULL;
gboolean createdChannel = FALSE;
guint16 expectedSequenceNumber = 0;
guint16 snLimit = 0;
if (pinfo->fd->flags.visited) {
p_report_in_frame = (sequence_analysis_report*)g_hash_table_lookup(sequence_analysis_report_hash,
get_report_hash_key(sequenceNumber,
pinfo->fd->num,
p_rlc_lte_info,
FALSE));
if (p_report_in_frame != NULL) {
addChannelSequenceInfo(p_report_in_frame, isControlFrame, p_rlc_lte_info,
sequenceNumber, first_includes_start,
tap_info, pinfo, tree, tvb);
return p_report_in_frame->state;
}
}
channel_key.ueId = p_rlc_lte_info->ueid;
channel_key.channelType = p_rlc_lte_info->channelType;
channel_key.channelId = p_rlc_lte_info->channelId;
channel_key.direction = p_rlc_lte_info->direction;
p_channel_status = (channel_sequence_analysis_status*)g_hash_table_lookup(sequence_analysis_channel_hash, &channel_key);
if (p_channel_status == NULL) {
createdChannel = TRUE;
p_channel_status = wmem_new0(wmem_file_scope(), channel_sequence_analysis_status);
p_channel_key = (channel_hash_key *)wmem_memdup(wmem_file_scope(), &channel_key, sizeof(channel_hash_key));
p_channel_status->rlcMode = p_rlc_lte_info->rlcMode;
g_hash_table_insert(sequence_analysis_channel_hash, p_channel_key, p_channel_status);
}
p_report_in_frame = wmem_new0(wmem_file_scope(), sequence_analysis_report);
switch (p_channel_status->rlcMode) {
case RLC_UM_MODE:
if (p_rlc_lte_info->UMSequenceNumberLength == 5) {
snLimit = 32;
}
else {
snLimit = 1024;
}
if (!createdChannel) {
expectedSequenceNumber = (p_channel_status->previousSequenceNumber + 1) % snLimit;
}
else {
expectedSequenceNumber = sequenceNumber;
}
if ((sequenceNumber == 0) &&
((p_rlc_lte_info->channelType == CHANNEL_TYPE_MCCH) || (p_rlc_lte_info->channelType == CHANNEL_TYPE_MTCH))) {
expectedSequenceNumber = 0;
}
p_report_in_frame->sequenceExpectedCorrect = (sequenceNumber == expectedSequenceNumber);
if (!p_report_in_frame->sequenceExpectedCorrect) {
if (is_mac_lte_frame_retx(pinfo, p_rlc_lte_info->direction)) {
p_report_in_frame->state = SN_MAC_Retx;
p_report_in_frame->firstSN = sequenceNumber;
break;
}
else if ((p_rlc_lte_info->channelType == CHANNEL_TYPE_MCCH) || (p_rlc_lte_info->channelType == CHANNEL_TYPE_MTCH) ||
(((snLimit + sequenceNumber - expectedSequenceNumber) % snLimit) < 10)) {
reassembly_destroy(p_channel_status);
p_report_in_frame->state = SN_Missing;
tap_info->missingSNs = (snLimit + sequenceNumber - expectedSequenceNumber) % snLimit;
p_report_in_frame->firstSN = expectedSequenceNumber;
p_report_in_frame->lastSN = (snLimit + sequenceNumber - 1) % snLimit;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
p_report_in_frame->previousSegmentIncomplete = p_channel_status->previousSegmentIncomplete;
p_channel_status->previousFrameNum = pinfo->fd->num;
p_channel_status->previousSequenceNumber = sequenceNumber;
p_channel_status->previousSegmentIncomplete = !last_includes_end;
}
else {
p_report_in_frame->state = SN_Repeated;
p_report_in_frame->firstSN = sequenceNumber;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
}
}
else {
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
p_report_in_frame->previousSegmentIncomplete = p_channel_status->previousSegmentIncomplete;
p_channel_status->previousFrameNum = pinfo->fd->num;
p_channel_status->previousSequenceNumber = sequenceNumber;
p_channel_status->previousSegmentIncomplete = !last_includes_end;
if (p_channel_status->reassembly_info) {
reassembly_add_segment(p_channel_status, sequenceNumber, pinfo->fd->num,
tvb, firstSegmentOffset, firstSegmentLength);
if (!first_includes_start &&
((number_of_segments > 1) || last_includes_end)) {
reassembly_record(p_channel_status, pinfo, sequenceNumber, p_rlc_lte_info);
reassembly_destroy(p_channel_status);
}
}
if (!last_includes_end &&
((number_of_segments > 1) || first_includes_start)) {
guint16 lastSegmentLength = tvb_reported_length(tvb)-lastSegmentOffset;
if (global_rlc_lte_reassembly) {
reassembly_reset(p_channel_status);
reassembly_add_segment(p_channel_status, sequenceNumber,
pinfo->fd->num,
tvb, lastSegmentOffset, lastSegmentLength);
}
}
if (p_report_in_frame->previousFrameNum != 0) {
sequence_analysis_report *p_previous_report;
if (p_rlc_lte_info->UMSequenceNumberLength == 5) {
snLimit = 32;
}
else {
snLimit = 1024;
}
p_previous_report = (sequence_analysis_report*)g_hash_table_lookup(sequence_analysis_report_hash,
get_report_hash_key((sequenceNumber+snLimit-1) % snLimit,
p_report_in_frame->previousFrameNum,
p_rlc_lte_info,
FALSE));
if (p_previous_report != NULL) {
p_previous_report->nextFrameNum = pinfo->fd->num;
}
}
}
break;
case RLC_AM_MODE:
if (!createdChannel) {
expectedSequenceNumber = (p_channel_status->previousSequenceNumber + 1) % 1024;
}
else {
expectedSequenceNumber = sequenceNumber;
}
if (is_mac_lte_frame_retx(pinfo, p_rlc_lte_info->direction)) {
p_report_in_frame->state = SN_MAC_Retx;
p_report_in_frame->firstSN = sequenceNumber;
break;
}
if (sequenceNumber != expectedSequenceNumber) {
if (((1024 + sequenceNumber - expectedSequenceNumber) % 1024) < 50) {
reassembly_destroy(p_channel_status);
}
}
if (sequenceNumber == expectedSequenceNumber) {
p_report_in_frame->sequenceExpectedCorrect = TRUE;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
p_report_in_frame->previousSegmentIncomplete = p_channel_status->previousSegmentIncomplete;
p_report_in_frame->state = SN_OK;
p_channel_status->previousSequenceNumber = sequenceNumber;
p_channel_status->previousFrameNum = pinfo->fd->num;
p_channel_status->previousSegmentIncomplete = !last_includes_end;
if (p_channel_status->reassembly_info) {
reassembly_add_segment(p_channel_status, sequenceNumber, pinfo->fd->num,
tvb, firstSegmentOffset, firstSegmentLength);
if (!first_includes_start &&
((number_of_segments > 1) || last_includes_end)) {
reassembly_record(p_channel_status, pinfo,
sequenceNumber, p_rlc_lte_info);
reassembly_destroy(p_channel_status);
}
}
if (!last_includes_end &&
((number_of_segments > 1) || first_includes_start)) {
guint16 lastSegmentLength = tvb_reported_length(tvb)-lastSegmentOffset;
if (global_rlc_lte_reassembly) {
reassembly_reset(p_channel_status);
reassembly_add_segment(p_channel_status, sequenceNumber,
pinfo->fd->num,
tvb, lastSegmentOffset, lastSegmentLength);
}
}
if (p_report_in_frame->previousFrameNum != 0) {
sequence_analysis_report *p_previous_report;
p_previous_report = (sequence_analysis_report*)g_hash_table_lookup(sequence_analysis_report_hash,
get_report_hash_key((sequenceNumber+1023) % 1024,
p_report_in_frame->previousFrameNum,
p_rlc_lte_info,
FALSE));
if (p_previous_report != NULL) {
p_previous_report->nextFrameNum = pinfo->fd->num;
}
}
}
else if (((sequenceNumber+1) % 1024) == expectedSequenceNumber) {
p_report_in_frame->state = SN_Repeated;
p_report_in_frame->sequenceExpectedCorrect = FALSE;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->firstSN = sequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
p_report_in_frame->previousSegmentIncomplete = p_channel_status->previousSegmentIncomplete;
p_channel_status->previousSequenceNumber = sequenceNumber;
p_channel_status->previousFrameNum = pinfo->fd->num;
p_channel_status->previousSegmentIncomplete = !last_includes_end;
}
else {
int delta = (1024 + expectedSequenceNumber - sequenceNumber) % 1024;
if (delta < 512) {
p_report_in_frame->state = SN_Retx;
p_report_in_frame->firstSN = sequenceNumber;
}
else {
p_report_in_frame->state = SN_Missing;
p_report_in_frame->firstSN = expectedSequenceNumber;
p_report_in_frame->lastSN = (1024 + sequenceNumber-1) % 1024;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_channel_status->previousSequenceNumber = sequenceNumber;
p_channel_status->previousFrameNum = pinfo->fd->num;
p_channel_status->previousSegmentIncomplete = !last_includes_end;
}
}
break;
default:
return SN_Error;
}
g_hash_table_insert(sequence_analysis_report_hash,
get_report_hash_key(sequenceNumber, pinfo->fd->num, p_rlc_lte_info, TRUE),
p_report_in_frame);
addChannelSequenceInfo(p_report_in_frame, isControlFrame, p_rlc_lte_info, sequenceNumber,
first_includes_start, tap_info, pinfo, tree, tvb);
return p_report_in_frame->state;
}
static void addChannelRepeatedNACKInfo(channel_repeated_nack_report *p,
rlc_lte_info *p_rlc_lte_info,
packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb)
{
proto_tree *seqnum_tree;
proto_item *seqnum_ti;
proto_item *ti;
gint n;
seqnum_ti = proto_tree_add_string_format(tree,
hf_rlc_lte_sequence_analysis,
tvb, 0, 0,
"", "Sequence Analysis");
seqnum_tree = proto_item_add_subtree(seqnum_ti,
ett_rlc_lte_sequence_analysis);
PROTO_ITEM_SET_GENERATED(seqnum_ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_rlc_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
for (n=0; n < p->noOfNACKsRepeated; n++) {
ti = proto_tree_add_uint(seqnum_tree, hf_rlc_lte_sequence_analysis_repeated_nack,
tvb, 0, 0, p->repeatedNACKs[n]);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti, &ei_rlc_lte_sequence_analysis_repeated_nack,
"Same SN (%u) NACKd for %s on UE %u in successive Status PDUs",
p->repeatedNACKs[n],
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid);
}
ti = proto_tree_add_uint(seqnum_tree, hf_rlc_lte_sequence_analysis_repeated_nack_original_frame,
tvb, 0, 0, p->previousFrameNum);
PROTO_ITEM_SET_GENERATED(ti);
proto_item_append_text(seqnum_ti, " - %u SNs repeated from previous Status PDU",
p->noOfNACKsRepeated);
}
static void checkChannelRepeatedNACKInfo(packet_info *pinfo,
rlc_lte_info *p_rlc_lte_info,
rlc_lte_tap_info *tap_info,
proto_tree *tree,
tvbuff_t *tvb)
{
channel_hash_key channel_key;
channel_hash_key *p_channel_key;
channel_repeated_nack_status *p_channel_status;
channel_repeated_nack_report *p_report_in_frame = NULL;
guint16 noOfNACKsRepeated = 0;
guint16 repeatedNACKs[MAX_NACKs];
gint n, i, j;
if (pinfo->fd->flags.visited) {
p_report_in_frame = (channel_repeated_nack_report*)g_hash_table_lookup(repeated_nack_report_hash,
get_report_hash_key(0, pinfo->fd->num,
p_rlc_lte_info, FALSE));
if (p_report_in_frame != NULL) {
addChannelRepeatedNACKInfo(p_report_in_frame, p_rlc_lte_info,
pinfo, tree, tvb);
return;
}
else {
return;
}
}
channel_key.ueId = p_rlc_lte_info->ueid;
channel_key.channelType = p_rlc_lte_info->channelType;
channel_key.channelId = p_rlc_lte_info->channelId;
channel_key.direction = p_rlc_lte_info->direction;
memset(repeatedNACKs, 0, sizeof(repeatedNACKs));
p_channel_status = (channel_repeated_nack_status*)g_hash_table_lookup(repeated_nack_channel_hash, &channel_key);
if (p_channel_status == NULL) {
p_channel_key = wmem_new(wmem_file_scope(), channel_hash_key);
p_channel_status = wmem_new0(wmem_file_scope(), channel_repeated_nack_status);
memcpy(p_channel_key, &channel_key, sizeof(channel_hash_key));
g_hash_table_insert(repeated_nack_channel_hash, p_channel_key, p_channel_status);
}
for (i=0; i < p_channel_status->noOfNACKs; i++) {
for (j=0; j < MIN(tap_info->noOfNACKs, MAX_NACKs); j++) {
if (tap_info->NACKs[j] == p_channel_status->NACKs[i]) {
if ((noOfNACKsRepeated == 0) ||
(repeatedNACKs[noOfNACKsRepeated-1] != p_channel_status->NACKs[i])) {
repeatedNACKs[noOfNACKsRepeated++] = p_channel_status->NACKs[i];
}
}
}
}
p_channel_status->noOfNACKs = 0;
for (n=0; n < MIN(tap_info->noOfNACKs, MAX_NACKs); n++) {
p_channel_status->NACKs[p_channel_status->noOfNACKs++] = tap_info->NACKs[n];
}
if (noOfNACKsRepeated >= 1) {
p_report_in_frame = wmem_new(wmem_file_scope(), channel_repeated_nack_report);
for (n=0; n < MIN(tap_info->noOfNACKs, MAX_NACKs); n++) {
p_report_in_frame->repeatedNACKs[n] = repeatedNACKs[n];
}
p_report_in_frame->noOfNACKsRepeated = noOfNACKsRepeated;
p_report_in_frame->previousFrameNum = p_channel_status->frameNum;
g_hash_table_insert(repeated_nack_report_hash,
get_report_hash_key(0, pinfo->fd->num,
p_rlc_lte_info, TRUE),
p_report_in_frame);
addChannelRepeatedNACKInfo(p_report_in_frame, p_rlc_lte_info,
pinfo, tree, tvb);
}
p_channel_status->frameNum = pinfo->fd->num;
}
static void checkChannelACKWindow(guint16 ack_sn,
packet_info *pinfo,
rlc_lte_info *p_rlc_lte_info,
rlc_lte_tap_info *tap_info,
proto_tree *tree,
tvbuff_t *tvb)
{
channel_hash_key channel_key;
channel_sequence_analysis_status *p_channel_status;
sequence_analysis_report *p_report_in_frame = NULL;
if (pinfo->fd->flags.visited) {
p_report_in_frame = (sequence_analysis_report*)g_hash_table_lookup(sequence_analysis_report_hash,
get_report_hash_key(0, pinfo->fd->num,
p_rlc_lte_info,
FALSE));
if (p_report_in_frame != NULL) {
addChannelSequenceInfo(p_report_in_frame, TRUE, p_rlc_lte_info,
0, FALSE,
tap_info, pinfo, tree, tvb);
return;
}
else {
return;
}
}
channel_key.ueId = p_rlc_lte_info->ueid;
channel_key.channelType = p_rlc_lte_info->channelType;
channel_key.channelId = p_rlc_lte_info->channelId;
channel_key.direction =
(p_rlc_lte_info->direction == DIRECTION_UPLINK) ? DIRECTION_DOWNLINK : DIRECTION_UPLINK;
p_channel_status = (channel_sequence_analysis_status*)g_hash_table_lookup(sequence_analysis_channel_hash, &channel_key);
if (p_channel_status == NULL) {
return;
}
if (((1024 + p_channel_status->previousSequenceNumber+1 - ack_sn) % 1024) > 512) {
p_report_in_frame = wmem_new0(wmem_file_scope(), sequence_analysis_report);
p_report_in_frame->state = ACK_Out_of_Window;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
p_report_in_frame->sequenceExpected = p_channel_status->previousSequenceNumber;
p_report_in_frame->firstSN = ack_sn;
g_hash_table_insert(sequence_analysis_report_hash,
get_report_hash_key(0, pinfo->fd->num,
p_rlc_lte_info, TRUE),
p_report_in_frame);
addChannelSequenceInfo(p_report_in_frame, TRUE, p_rlc_lte_info, 0,
FALSE, tap_info, pinfo, tree, tvb);
}
}
static void dissect_rlc_lte_tm(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree,
int offset,
rlc_lte_info *p_rlc_lte_info,
proto_item *top_ti)
{
proto_item *raw_tm_ti;
proto_item *tm_ti;
tm_ti = proto_tree_add_string_format(tree, hf_rlc_lte_tm,
tvb, offset, 0, "", "TM");
PROTO_ITEM_SET_HIDDEN(tm_ti);
raw_tm_ti = proto_tree_add_item(tree, hf_rlc_lte_tm_data, tvb, offset, -1, ENC_NA);
if (!global_rlc_lte_call_rrc_for_ccch) {
write_pdu_label_and_info(top_ti, NULL, pinfo,
" [%u-bytes]", tvb_reported_length_remaining(tvb, offset));
}
if (global_rlc_lte_call_rrc_for_ccch) {
tvbuff_t *rrc_tvb = tvb_new_subset_remaining(tvb, offset);
volatile dissector_handle_t protocol_handle = 0;
switch (p_rlc_lte_info->channelType) {
case CHANNEL_TYPE_CCCH:
if (p_rlc_lte_info->direction == DIRECTION_UPLINK) {
protocol_handle = find_dissector("lte_rrc.ul_ccch");
}
else {
protocol_handle = find_dissector("lte_rrc.dl_ccch");
}
break;
case CHANNEL_TYPE_BCCH_BCH:
protocol_handle = find_dissector("lte_rrc.bcch_bch");
break;
case CHANNEL_TYPE_BCCH_DL_SCH:
protocol_handle = find_dissector("lte_rrc.bcch_dl_sch");
break;
case CHANNEL_TYPE_PCCH:
protocol_handle = find_dissector("lte_rrc.pcch");
break;
case CHANNEL_TYPE_SRB:
case CHANNEL_TYPE_DRB:
case CHANNEL_TYPE_MCCH:
case CHANNEL_TYPE_MTCH:
default:
return;
}
PROTO_ITEM_SET_HIDDEN(raw_tm_ti);
TRY {
call_dissector_only(protocol_handle, rrc_tvb, pinfo, tree, NULL);
}
CATCH_ALL {
}
ENDTRY
}
}
static void dissect_rlc_lte_um(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree,
int offset,
rlc_lte_info *p_rlc_lte_info,
proto_item *top_ti,
rlc_lte_tap_info *tap_info)
{
guint64 framing_info;
gboolean first_includes_start;
gboolean last_includes_end;
guint64 fixed_extension;
guint64 sn;
gint start_offset = offset;
proto_item *um_ti;
proto_tree *um_header_tree;
proto_item *um_header_ti;
gboolean is_truncated = FALSE;
proto_item *truncated_ti;
rlc_channel_reassembly_info *reassembly_info = NULL;
sequence_analysis_state seq_anal_state = SN_OK;
um_ti = proto_tree_add_string_format(tree, hf_rlc_lte_um,
tvb, offset, 0, "", "UM");
PROTO_ITEM_SET_HIDDEN(um_ti);
um_header_ti = proto_tree_add_string_format(tree, hf_rlc_lte_um_header,
tvb, offset, 0,
"", "UM header");
um_header_tree = proto_item_add_subtree(um_header_ti,
ett_rlc_lte_um_header);
if (p_rlc_lte_info->UMSequenceNumberLength == UM_SN_LENGTH_5_BITS) {
proto_tree_add_bits_ret_val(um_header_tree, hf_rlc_lte_um_fi,
tvb, offset*8, 2,
&framing_info, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(um_header_tree, hf_rlc_lte_um_fixed_e, tvb,
(offset*8) + 2, 1,
&fixed_extension, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(um_header_tree, hf_rlc_lte_um_sn, tvb,
(offset*8) + 3, 5,
&sn, ENC_BIG_ENDIAN);
offset++;
}
else if (p_rlc_lte_info->UMSequenceNumberLength == UM_SN_LENGTH_10_BITS) {
guint8 reserved;
proto_item *ti;
reserved = (tvb_get_guint8(tvb, offset) & 0xe0) >> 5;
ti = proto_tree_add_item(um_header_tree, hf_rlc_lte_um_fixed_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
if (reserved != 0) {
expert_add_info_format(pinfo, ti, &ei_rlc_lte_reserved_bits_not_zero,
"RLC UM Fixed header Reserved bits not zero (found 0x%x)", reserved);
}
proto_tree_add_bits_ret_val(um_header_tree, hf_rlc_lte_um_fi,
tvb, (offset*8)+3, 2,
&framing_info, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(um_header_tree, hf_rlc_lte_um_fixed_e, tvb,
(offset*8) + 5, 1,
&fixed_extension, ENC_BIG_ENDIAN);
proto_tree_add_bits_ret_val(um_header_tree, hf_rlc_lte_um_sn, tvb,
(offset*8) + 6, 10,
&sn, ENC_BIG_ENDIAN);
offset += 2;
}
else {
proto_tree_add_expert_format(um_header_tree, pinfo, &ei_rlc_lte_um_sn, tvb, 0, 0,
"Invalid sequence number length (%u bits)",
p_rlc_lte_info->UMSequenceNumberLength);
return;
}
tap_info->sequenceNumber = (guint16)sn;
if ((p_rlc_lte_info->channelType == CHANNEL_TYPE_MCCH) || (p_rlc_lte_info->channelType == CHANNEL_TYPE_MTCH)) {
write_pdu_label_and_info(top_ti, um_header_ti, pinfo, " sn=%-4u", (guint16)sn);
}
else {
write_pdu_label_and_info(top_ti, um_header_ti, pinfo, " sn=%-4u", (guint16)sn);
}
proto_item_set_len(um_header_ti, offset-start_offset);
if (fixed_extension) {
offset = dissect_rlc_lte_extension_header(tvb, pinfo, um_header_tree, offset);
}
first_includes_start = ((guint8)framing_info & 0x02) == 0;
last_includes_end = ((guint8)framing_info & 0x01) == 0;
if (global_rlc_lte_headers_expected) {
is_truncated = (tvb_reported_length_remaining(tvb, offset) == 0);
truncated_ti = proto_tree_add_uint(tree, hf_rlc_lte_header_only, tvb, 0, 0,
is_truncated);
if (is_truncated) {
int n;
PROTO_ITEM_SET_GENERATED(truncated_ti);
expert_add_info(pinfo, truncated_ti, &ei_rlc_lte_header_only);
for (n=0; n < s_number_of_extensions; n++) {
show_PDU_in_info(pinfo, top_ti, s_lengths[n],
(n==0) ? first_includes_start : TRUE,
TRUE);
offset += s_lengths[n];
}
show_PDU_in_info(pinfo, top_ti, p_rlc_lte_info->pduLength - offset,
(s_number_of_extensions == 0) ? first_includes_start : TRUE,
last_includes_end);
}
else {
PROTO_ITEM_SET_HIDDEN(truncated_ti);
}
}
if (s_number_of_extensions > 0) {
proto_item_append_text(um_header_ti, " (%u extensions)", s_number_of_extensions);
}
if (((global_rlc_lte_um_sequence_analysis == SEQUENCE_ANALYSIS_MAC_ONLY) &&
(p_get_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0) != NULL)) ||
((global_rlc_lte_um_sequence_analysis == SEQUENCE_ANALYSIS_RLC_ONLY) &&
(p_get_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0) == NULL))) {
guint16 lastSegmentOffset = offset;
if (s_number_of_extensions >= 1) {
int n;
lastSegmentOffset = offset;
for (n=0; n < s_number_of_extensions; n++) {
lastSegmentOffset += s_lengths[n];
}
}
seq_anal_state = checkChannelSequenceInfo(pinfo, tvb, p_rlc_lte_info,
FALSE,
s_number_of_extensions+1,
offset,
s_number_of_extensions ?
s_lengths[0] :
p_rlc_lte_info->pduLength - offset,
lastSegmentOffset,
(guint16)sn, first_includes_start, last_includes_end,
FALSE,
tap_info, um_header_tree);
}
if (is_truncated) {
return;
}
reassembly_info = (rlc_channel_reassembly_info *)g_hash_table_lookup(reassembly_report_hash,
get_report_hash_key((guint16)sn, pinfo->fd->num,
p_rlc_lte_info, FALSE));
if (s_number_of_extensions > 0) {
int n;
for (n=0; n < s_number_of_extensions; n++) {
show_PDU_in_tree(pinfo, tree, tvb, offset, s_lengths[n], p_rlc_lte_info,
(n==0) ? first_includes_start : TRUE,
(n==0) ? reassembly_info : NULL,
seq_anal_state);
show_PDU_in_info(pinfo, top_ti, s_lengths[n],
(n==0) ? first_includes_start : TRUE,
TRUE);
tvb_ensure_bytes_exist(tvb, offset, s_lengths[n]);
offset += s_lengths[n];
}
}
show_PDU_in_tree(pinfo, tree, tvb, offset, tvb_reported_length_remaining(tvb, offset), p_rlc_lte_info,
((s_number_of_extensions == 0) ? first_includes_start : TRUE) && last_includes_end,
(s_number_of_extensions == 0) ? reassembly_info : NULL,
seq_anal_state);
show_PDU_in_info(pinfo, top_ti, (guint16)tvb_reported_length_remaining(tvb, offset),
(s_number_of_extensions == 0) ? first_includes_start : TRUE,
last_includes_end);
}
static void dissect_rlc_lte_am_status_pdu(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
proto_item *status_ti,
int offset,
proto_item *top_ti,
rlc_lte_info *p_rlc_lte_info,
rlc_lte_tap_info *tap_info)
{
guint8 cpt;
guint64 ack_sn, nack_sn;
guint16 nack_count = 0;
guint64 e1 = 0, e2 = 0;
guint64 so_start, so_end;
int bit_offset = offset * 8;
proto_item *ti;
cpt = (tvb_get_guint8(tvb, offset) & 0xf0) >> 4;
ti = proto_tree_add_item(tree, hf_rlc_lte_am_cpt, tvb, offset, 1, ENC_BIG_ENDIAN);
if (cpt != 0) {
expert_add_info_format(pinfo, ti, &ei_rlc_lte_am_cpt,
"RLC Control frame type %u not handled", cpt);
return;
}
bit_offset += 4;
proto_tree_add_bits_ret_val(tree, hf_rlc_lte_am_ack_sn, tvb,
bit_offset, 10, &ack_sn, ENC_BIG_ENDIAN);
bit_offset += 10;
write_pdu_label_and_info(top_ti, status_ti, pinfo, " ACK_SN=%-4u", (guint16)ack_sn);
tap_info->ACKNo = (guint16)ack_sn;
proto_tree_add_bits_ret_val(tree, hf_rlc_lte_am_e1, tvb,
bit_offset, 1, &e1, ENC_BIG_ENDIAN);
bit_offset++;
do {
if (e1) {
proto_item *nack_ti;
nack_ti = proto_tree_add_bits_ret_val(tree, hf_rlc_lte_am_nack_sn, tvb,
bit_offset, 10, &nack_sn, ENC_BIG_ENDIAN);
bit_offset += 10;
write_pdu_label_and_info(top_ti, NULL, pinfo, " NACK_SN=%-4u", (guint16)nack_sn);
if (nack_sn == ack_sn) {
expert_add_info_format(pinfo, nack_ti, &ei_rlc_lte_am_nack_sn_ack_same,
"Status PDU shouldn't ACK and NACK the same sequence number (%" G_GINT64_MODIFIER "u)",
ack_sn);
}
if ((1024 + ack_sn - nack_sn) % 1024 > 512) {
expert_add_info(pinfo, nack_ti, &ei_rlc_lte_am_nack_sn_ahead_ack);
}
if (nack_count < MAX_NACKs) {
tap_info->NACKs[nack_count++] = (guint16)nack_sn;
}
else {
nack_count++;
}
proto_tree_add_bits_ret_val(tree, hf_rlc_lte_am_e1, tvb,
bit_offset, 1, &e1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_ret_val(tree, hf_rlc_lte_am_e2, tvb,
bit_offset, 1, &e2, ENC_BIG_ENDIAN);
if (e2) {
expert_add_info_format(pinfo, nack_ti, &ei_rlc_lte_am_nack_sn_partial,
"Status PDU reports NACK (partial) on %s for UE %u",
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid);
}
else {
expert_add_info_format(pinfo, nack_ti, &ei_rlc_lte_am_nack_sn,
"Status PDU reports NACK on %s for UE %u",
val_to_str_const(p_rlc_lte_info->direction, direction_vals, "Unknown"),
p_rlc_lte_info->ueid);
}
bit_offset++;
}
if (e2) {
proto_tree_add_bits_ret_val(tree, hf_rlc_lte_am_so_start, tvb,
bit_offset, 15, &so_start, ENC_BIG_ENDIAN);
bit_offset += 15;
proto_tree_add_bits_ret_val(tree, hf_rlc_lte_am_so_end, tvb,
bit_offset, 15, &so_end, ENC_BIG_ENDIAN);
bit_offset += 15;
if ((guint16)so_end == 0x7fff) {
write_pdu_label_and_info(top_ti, NULL, pinfo,
" (SOstart=%u SOend=<END-OF_PDU>)",
(guint16)so_start);
}
else {
write_pdu_label_and_info(top_ti, NULL, pinfo,
" (SOstart=%u SOend=%u)",
(guint16)so_start, (guint16)so_end);
}
e2 = 0;
}
} while (e1 || e2);
if (nack_count > 0) {
proto_item *count_ti = proto_tree_add_uint(tree, hf_rlc_lte_am_nacks, tvb, 0, 1, nack_count);
PROTO_ITEM_SET_GENERATED(count_ti);
proto_item_append_text(status_ti, " (%u NACKs)", nack_count);
tap_info->noOfNACKs = nack_count;
}
offset = (bit_offset+7) / 8;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
expert_add_info_format(pinfo, status_ti, &ei_rlc_lte_bytes_after_status_pdu_complete,
"%cL %u bytes remaining after Status PDU complete",
(p_rlc_lte_info->direction == DIRECTION_UPLINK) ? 'U' : 'D',
tvb_reported_length_remaining(tvb, offset));
}
proto_item_set_len(status_ti, offset);
if (((global_rlc_lte_am_sequence_analysis == SEQUENCE_ANALYSIS_MAC_ONLY) &&
(p_get_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0) != NULL)) ||
((global_rlc_lte_am_sequence_analysis == SEQUENCE_ANALYSIS_RLC_ONLY) &&
(p_get_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0) == NULL))) {
if (!is_mac_lte_frame_retx(pinfo, p_rlc_lte_info->direction)) {
checkChannelRepeatedNACKInfo(pinfo, p_rlc_lte_info, tap_info, tree, tvb);
checkChannelACKWindow((guint16)ack_sn, pinfo, p_rlc_lte_info, tap_info, tree, tvb);
}
}
}
static void dissect_rlc_lte_am(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree,
int offset,
rlc_lte_info *p_rlc_lte_info,
proto_item *top_ti,
rlc_lte_tap_info *tap_info)
{
guint8 is_data;
guint8 is_resegmented;
guint8 polling;
guint8 fixed_extension;
guint8 framing_info;
gboolean first_includes_start;
gboolean last_includes_end;
proto_item *am_ti;
proto_tree *am_header_tree;
proto_item *am_header_ti;
gint start_offset = offset;
guint16 sn;
gboolean is_truncated = FALSE;
proto_item *truncated_ti;
rlc_channel_reassembly_info *reassembly_info = NULL;
sequence_analysis_state seq_anal_state = SN_OK;
am_ti = proto_tree_add_string_format(tree, hf_rlc_lte_am,
tvb, offset, 0, "", "AM");
PROTO_ITEM_SET_HIDDEN(am_ti);
am_header_ti = proto_tree_add_string_format(tree, hf_rlc_lte_am_header,
tvb, offset, 0,
"", "AM Header ");
am_header_tree = proto_item_add_subtree(am_header_ti,
ett_rlc_lte_am_header);
is_data = (tvb_get_guint8(tvb, offset) & 0x80) >> 7;
proto_tree_add_item(am_header_tree, hf_rlc_lte_am_data_control, tvb, offset, 1, ENC_BIG_ENDIAN);
tap_info->isControlPDU = !is_data;
if (!is_data) {
write_pdu_label_and_info_literal(top_ti, NULL, pinfo, " [CONTROL]");
dissect_rlc_lte_am_status_pdu(tvb, pinfo, am_header_tree, am_header_ti,
offset, top_ti,
p_rlc_lte_info, tap_info);
return;
}
is_resegmented = (tvb_get_guint8(tvb, offset) & 0x40) >> 6;
proto_tree_add_item(am_header_tree, hf_rlc_lte_am_rf, tvb, offset, 1, ENC_BIG_ENDIAN);
tap_info->isResegmented = is_resegmented;
write_pdu_label_and_info_literal(top_ti, NULL, pinfo,
(is_resegmented) ? " [DATA-SEGMENT]" : " [DATA]");
polling = (tvb_get_guint8(tvb, offset) & 0x20) >> 5;
proto_tree_add_item(am_header_tree, hf_rlc_lte_am_p, tvb, offset, 1, ENC_BIG_ENDIAN);
write_pdu_label_and_info_literal(top_ti, NULL, pinfo, (polling) ? " (P) " : " ");
if (polling) {
proto_item_append_text(am_header_ti, " (P) ");
}
framing_info = (tvb_get_guint8(tvb, offset) & 0x18) >> 3;
proto_tree_add_item(am_header_tree, hf_rlc_lte_am_fi, tvb, offset, 1, ENC_BIG_ENDIAN);
fixed_extension = (tvb_get_guint8(tvb, offset) & 0x04) >> 2;
proto_tree_add_item(am_header_tree, hf_rlc_lte_am_fixed_e, tvb, offset, 1, ENC_BIG_ENDIAN);
sn = tvb_get_ntohs(tvb, offset) & 0x03ff;
proto_tree_add_item(am_header_tree, hf_rlc_lte_am_fixed_sn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tap_info->sequenceNumber = sn;
write_pdu_label_and_info(top_ti, am_header_ti, pinfo, "sn=%-4u", sn);
if (is_resegmented) {
guint16 segmentOffset;
proto_tree_add_item(am_header_tree, hf_rlc_lte_am_segment_lsf, tvb, offset, 1, ENC_BIG_ENDIAN);
segmentOffset = tvb_get_ntohs(tvb, offset) & 0x7fff;
proto_tree_add_item(am_header_tree, hf_rlc_lte_am_segment_so, tvb, offset, 2, ENC_BIG_ENDIAN);
write_pdu_label_and_info(top_ti, am_header_ti, pinfo, " SO=%u ", segmentOffset);
offset += 2;
}
if (fixed_extension) {
offset = dissect_rlc_lte_extension_header(tvb, pinfo, am_header_tree, offset);
}
proto_item_set_len(am_header_ti, offset-start_offset);
if (s_number_of_extensions > 0) {
proto_item_append_text(am_header_ti, " (%u extensions)", s_number_of_extensions);
}
first_includes_start = (framing_info & 0x02) == 0;
last_includes_end = (framing_info & 0x01) == 0;
if (global_rlc_lte_headers_expected) {
is_truncated = (tvb_reported_length_remaining(tvb, offset) == 0);
truncated_ti = proto_tree_add_uint(tree, hf_rlc_lte_header_only, tvb, 0, 0,
is_truncated);
if (is_truncated) {
int n;
PROTO_ITEM_SET_GENERATED(truncated_ti);
expert_add_info(pinfo, truncated_ti, &ei_rlc_lte_header_only);
for (n=0; n < s_number_of_extensions; n++) {
show_PDU_in_info(pinfo, top_ti, s_lengths[n],
(n==0) ? first_includes_start : TRUE,
TRUE);
offset += s_lengths[n];
}
show_PDU_in_info(pinfo, top_ti, p_rlc_lte_info->pduLength - offset,
(s_number_of_extensions == 0) ? first_includes_start : TRUE,
last_includes_end);
}
else {
PROTO_ITEM_SET_HIDDEN(truncated_ti);
}
}
if (((global_rlc_lte_am_sequence_analysis == SEQUENCE_ANALYSIS_MAC_ONLY) &&
(p_get_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0) != NULL)) ||
((global_rlc_lte_am_sequence_analysis == SEQUENCE_ANALYSIS_RLC_ONLY) &&
(p_get_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0) == NULL))) {
guint16 firstSegmentLength;
guint16 lastSegmentOffset = offset;
if (s_number_of_extensions >= 1) {
int n;
for (n=0; n < s_number_of_extensions; n++) {
lastSegmentOffset += s_lengths[n];
}
firstSegmentLength = s_lengths[0];
}
else {
firstSegmentLength = tvb_reported_length_remaining(tvb, offset);
}
seq_anal_state = checkChannelSequenceInfo(pinfo, tvb, p_rlc_lte_info, FALSE,
s_number_of_extensions+1,
offset, firstSegmentLength,
lastSegmentOffset,
(guint16)sn,
first_includes_start, last_includes_end,
is_resegmented, tap_info, tree);
}
if (is_truncated) {
return;
}
if (!first_includes_start) {
reassembly_info = (rlc_channel_reassembly_info *)g_hash_table_lookup(reassembly_report_hash,
get_report_hash_key((guint16)sn, pinfo->fd->num,
p_rlc_lte_info, FALSE));
}
if (s_number_of_extensions > 0) {
int n;
for (n=0; n < s_number_of_extensions; n++) {
show_PDU_in_tree(pinfo, tree, tvb, offset, s_lengths[n], p_rlc_lte_info,
(n==0) ? first_includes_start : TRUE,
(n==0) ? reassembly_info : NULL,
seq_anal_state);
show_PDU_in_info(pinfo, top_ti, s_lengths[n],
(n==0) ? first_includes_start : TRUE,
TRUE);
tvb_ensure_bytes_exist(tvb, offset, s_lengths[n]);
offset += s_lengths[n];
}
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
show_PDU_in_tree(pinfo, tree, tvb, offset, tvb_reported_length_remaining(tvb, offset), p_rlc_lte_info,
((s_number_of_extensions == 0) ? first_includes_start : TRUE) && last_includes_end,
(s_number_of_extensions == 0) ? reassembly_info : NULL,
seq_anal_state);
show_PDU_in_info(pinfo, top_ti, (guint16)tvb_reported_length_remaining(tvb, offset),
(s_number_of_extensions == 0) ? first_includes_start : TRUE,
last_includes_end);
}
else {
if (!global_rlc_lte_headers_expected) {
if (s_number_of_extensions > 0) {
expert_add_info(pinfo, am_header_ti, &ei_rlc_lte_am_data_no_data_beyond_extensions);
}
else {
expert_add_info(pinfo, am_header_ti, &ei_rlc_lte_am_data_no_data);
}
}
}
}
static gboolean dissect_rlc_lte_heur(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data _U_)
{
gint offset = 0;
struct rlc_lte_info *p_rlc_lte_info;
tvbuff_t *rlc_tvb;
guint8 tag = 0;
gboolean infoAlreadySet = FALSE;
gboolean umSeqNumLengthTagPresent = FALSE;
if (!global_rlc_lte_heur) {
return FALSE;
}
if (tvb_captured_length_remaining(tvb, offset) < (gint)(strlen(RLC_LTE_START_STRING)+1+2)) {
return FALSE;
}
if (tvb_strneql(tvb, offset, RLC_LTE_START_STRING, (gint)strlen(RLC_LTE_START_STRING)) != 0) {
return FALSE;
}
offset += (gint)strlen(RLC_LTE_START_STRING);
p_rlc_lte_info = (rlc_lte_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_rlc_lte, 0);
if (p_rlc_lte_info == NULL) {
p_rlc_lte_info = wmem_new0(wmem_file_scope(), struct rlc_lte_info);
infoAlreadySet = FALSE;
}
else {
infoAlreadySet = TRUE;
}
p_rlc_lte_info->rlcMode = tvb_get_guint8(tvb, offset++);
while (tag != RLC_LTE_PAYLOAD_TAG) {
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case RLC_LTE_UM_SN_LENGTH_TAG:
p_rlc_lte_info->UMSequenceNumberLength = tvb_get_guint8(tvb, offset);
offset++;
umSeqNumLengthTagPresent = TRUE;
break;
case RLC_LTE_DIRECTION_TAG:
p_rlc_lte_info->direction = tvb_get_guint8(tvb, offset);
offset++;
break;
case RLC_LTE_PRIORITY_TAG:
p_rlc_lte_info->priority = tvb_get_guint8(tvb, offset);
offset++;
break;
case RLC_LTE_UEID_TAG:
p_rlc_lte_info->ueid = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case RLC_LTE_CHANNEL_TYPE_TAG:
p_rlc_lte_info->channelType = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case RLC_LTE_CHANNEL_ID_TAG:
p_rlc_lte_info->channelId = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case RLC_LTE_PAYLOAD_TAG:
p_rlc_lte_info->pduLength= tvb_reported_length_remaining(tvb, offset);
continue;
default:
return FALSE;
}
}
if ((p_rlc_lte_info->rlcMode == RLC_UM_MODE) && (umSeqNumLengthTagPresent == FALSE)) {
return FALSE;
}
if (!infoAlreadySet) {
p_add_proto_data(wmem_file_scope(), pinfo, proto_rlc_lte, 0, p_rlc_lte_info);
}
rlc_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_rlc_lte_common(rlc_tvb, pinfo, tree, TRUE);
return TRUE;
}
static void dissect_rlc_lte(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_rlc_lte_common(tvb, pinfo, tree, FALSE);
}
static void dissect_rlc_lte_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean is_udp_framing)
{
proto_tree *rlc_lte_tree;
proto_tree *context_tree;
proto_item *top_ti;
proto_item *context_ti;
proto_item *ti;
proto_item *mode_ti;
gint offset = 0;
struct rlc_lte_info *p_rlc_lte_info = NULL;
rlc_lte_tap_info *tap_info = wmem_new0(wmem_packet_scope(), rlc_lte_tap_info);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RLC-LTE");
top_ti = proto_tree_add_item(tree, proto_rlc_lte, tvb, offset, -1, ENC_NA);
rlc_lte_tree = proto_item_add_subtree(top_ti, ett_rlc_lte);
p_rlc_lte_info = (rlc_lte_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_rlc_lte, 0);
if (p_rlc_lte_info == NULL) {
ti = proto_tree_add_text(rlc_lte_tree, tvb, offset, -1,
"Can't dissect LTE RLC frame because no per-frame info was attached!");
PROTO_ITEM_SET_GENERATED(ti);
return;
}
if (is_udp_framing) {
col_clear(pinfo->cinfo, COL_INFO);
}
context_ti = proto_tree_add_string_format(rlc_lte_tree, hf_rlc_lte_context,
tvb, offset, 0, "", "Context");
context_tree = proto_item_add_subtree(context_ti, ett_rlc_lte_context);
PROTO_ITEM_SET_GENERATED(context_ti);
ti = proto_tree_add_uint(context_tree, hf_rlc_lte_context_direction,
tvb, 0, 0, p_rlc_lte_info->direction);
PROTO_ITEM_SET_GENERATED(ti);
mode_ti = proto_tree_add_uint(context_tree, hf_rlc_lte_context_mode,
tvb, 0, 0, p_rlc_lte_info->rlcMode);
PROTO_ITEM_SET_GENERATED(mode_ti);
if (p_rlc_lte_info->ueid != 0) {
ti = proto_tree_add_uint(context_tree, hf_rlc_lte_context_ueid,
tvb, 0, 0, p_rlc_lte_info->ueid);
PROTO_ITEM_SET_GENERATED(ti);
}
if ((p_rlc_lte_info->priority >= 1) && (p_rlc_lte_info->priority <=16)) {
ti = proto_tree_add_uint(context_tree, hf_rlc_lte_context_priority,
tvb, 0, 0, p_rlc_lte_info->priority);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_uint(context_tree, hf_rlc_lte_context_channel_type,
tvb, 0, 0, p_rlc_lte_info->channelType);
PROTO_ITEM_SET_GENERATED(ti);
if ((p_rlc_lte_info->channelType == CHANNEL_TYPE_SRB) ||
(p_rlc_lte_info->channelType == CHANNEL_TYPE_DRB) ||
(p_rlc_lte_info->channelType == CHANNEL_TYPE_MTCH)) {
ti = proto_tree_add_uint(context_tree, hf_rlc_lte_context_channel_id,
tvb, 0, 0, p_rlc_lte_info->channelId);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_uint(context_tree, hf_rlc_lte_context_pdu_length,
tvb, 0, 0, p_rlc_lte_info->pduLength);
PROTO_ITEM_SET_GENERATED(ti);
if (p_rlc_lte_info->rlcMode == RLC_UM_MODE) {
ti = proto_tree_add_uint(context_tree, hf_rlc_lte_context_um_sn_length,
tvb, 0, 0, p_rlc_lte_info->UMSequenceNumberLength);
PROTO_ITEM_SET_GENERATED(ti);
}
if (p_rlc_lte_info->ueid != 0) {
proto_item_append_text(top_ti, " UEId=%u", p_rlc_lte_info->ueid);
col_append_fstr(pinfo->cinfo, COL_INFO, "UEId=%-4u ", p_rlc_lte_info->ueid);
}
write_pdu_label_and_info(top_ti, NULL, pinfo,
" [%s] [%s] ",
(p_rlc_lte_info->direction == 0) ? "UL" : "DL",
val_to_str_const(p_rlc_lte_info->rlcMode, rlc_mode_short_vals, "Unknown"));
if (p_rlc_lte_info->channelId == 0) {
write_pdu_label_and_info(top_ti, NULL, pinfo, "%s ",
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"));
}
else {
write_pdu_label_and_info(top_ti, NULL, pinfo, "%s:%-2u",
val_to_str_const(p_rlc_lte_info->channelType, rlc_channel_type_vals, "Unknown"),
p_rlc_lte_info->channelId);
}
tap_info->rlcMode = p_rlc_lte_info->rlcMode;
tap_info->direction = p_rlc_lte_info->direction;
tap_info->priority = p_rlc_lte_info->priority;
tap_info->ueid = p_rlc_lte_info->ueid;
tap_info->channelType = p_rlc_lte_info->channelType;
tap_info->channelId = p_rlc_lte_info->channelId;
tap_info->pduLength = p_rlc_lte_info->pduLength;
tap_info->UMSequenceNumberLength = p_rlc_lte_info->UMSequenceNumberLength;
tap_info->loggedInMACFrame = (p_get_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0) != NULL);
tap_info->time = pinfo->fd->abs_ts;
s_number_of_extensions = 0;
switch (p_rlc_lte_info->rlcMode) {
case RLC_TM_MODE:
dissect_rlc_lte_tm(tvb, pinfo, rlc_lte_tree, offset, p_rlc_lte_info, top_ti);
break;
case RLC_UM_MODE:
dissect_rlc_lte_um(tvb, pinfo, rlc_lte_tree, offset, p_rlc_lte_info, top_ti,
tap_info);
break;
case RLC_AM_MODE:
dissect_rlc_lte_am(tvb, pinfo, rlc_lte_tree, offset, p_rlc_lte_info, top_ti,
tap_info);
break;
case RLC_PREDEF:
proto_tree_add_item(rlc_lte_tree, hf_rlc_lte_predefined_pdu, tvb, offset, -1, ENC_NA);
write_pdu_label_and_info(top_ti, NULL, pinfo, " [%u-bytes]",
tvb_reported_length_remaining(tvb, offset));
break;
default:
expert_add_info_format(pinfo, mode_ti, &ei_rlc_lte_context_mode,
"Unrecognised RLC Mode set (%u)", p_rlc_lte_info->rlcMode);
break;
}
tap_queue_packet(rlc_lte_tap, pinfo, tap_info);
}
static void
rlc_lte_init_protocol(void)
{
if (sequence_analysis_channel_hash) {
g_hash_table_destroy(sequence_analysis_channel_hash);
}
if (sequence_analysis_report_hash) {
g_hash_table_destroy(sequence_analysis_report_hash);
}
if (repeated_nack_channel_hash) {
g_hash_table_destroy(repeated_nack_channel_hash);
}
if (repeated_nack_report_hash) {
g_hash_table_destroy(repeated_nack_report_hash);
}
if (reassembly_report_hash) {
g_hash_table_destroy(reassembly_report_hash);
}
sequence_analysis_channel_hash = g_hash_table_new(rlc_channel_hash_func, rlc_channel_equal);
sequence_analysis_report_hash = g_hash_table_new(rlc_result_hash_func, rlc_result_hash_equal);
repeated_nack_channel_hash = g_hash_table_new(rlc_channel_hash_func, rlc_channel_equal);
repeated_nack_report_hash = g_hash_table_new(rlc_result_hash_func, rlc_result_hash_equal);
reassembly_report_hash = g_hash_table_new(rlc_result_hash_func, rlc_result_hash_equal);
}
void set_rlc_lte_drb_pdcp_seqnum_length(guint16 ueid _U_, guint8 drbid _U_,
guint8 userplane_seqnum_length)
{
signalled_pdcp_sn_bits = userplane_seqnum_length;
}
void proto_register_rlc_lte(void)
{
static hf_register_info hf[] =
{
{ &hf_rlc_lte_context,
{ "Context",
"rlc-lte.context", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_context_mode,
{ "RLC Mode",
"rlc-lte.mode", FT_UINT8, BASE_DEC, VALS(rlc_mode_vals), 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_context_direction,
{ "Direction",
"rlc-lte.direction", FT_UINT8, BASE_DEC, VALS(direction_vals), 0x0,
"Direction of message", HFILL
}
},
{ &hf_rlc_lte_context_priority,
{ "Priority",
"rlc-lte.priority", FT_UINT8, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_context_ueid,
{ "UEId",
"rlc-lte.ueid", FT_UINT16, BASE_DEC, 0, 0x0,
"User Equipment Identifier associated with message", HFILL
}
},
{ &hf_rlc_lte_context_channel_type,
{ "Channel Type",
"rlc-lte.channel-type", FT_UINT16, BASE_DEC, VALS(rlc_channel_type_vals), 0x0,
"Channel Type associated with message", HFILL
}
},
{ &hf_rlc_lte_context_channel_id,
{ "Channel ID",
"rlc-lte.channel-id", FT_UINT16, BASE_DEC, 0, 0x0,
"Channel ID associated with message", HFILL
}
},
{ &hf_rlc_lte_context_pdu_length,
{ "PDU Length",
"rlc-lte.pdu-length", FT_UINT16, BASE_DEC, 0, 0x0,
"Length of PDU (in bytes)", HFILL
}
},
{ &hf_rlc_lte_context_um_sn_length,
{ "UM Sequence number length",
"rlc-lte.um-seqnum-length", FT_UINT8, BASE_DEC, 0, 0x0,
"Length of UM sequence number in bits", HFILL
}
},
{ &hf_rlc_lte_tm,
{ "TM",
"rlc-lte.tm", FT_STRING, BASE_NONE, NULL, 0x0,
"Transparent Mode", HFILL
}
},
{ &hf_rlc_lte_tm_data,
{ "TM Data",
"rlc-lte.tm.data", FT_BYTES, BASE_NONE, 0, 0x0,
"Transparent Mode Data", HFILL
}
},
{ &hf_rlc_lte_um,
{ "UM",
"rlc-lte.um", FT_STRING, BASE_NONE, NULL, 0x0,
"Unacknowledged Mode", HFILL
}
},
{ &hf_rlc_lte_um_header,
{ "UM Header",
"rlc-lte.um.header", FT_STRING, BASE_NONE, NULL, 0x0,
"Unacknowledged Mode Header", HFILL
}
},
{ &hf_rlc_lte_um_fi,
{ "Framing Info",
"rlc-lte.um.fi", FT_UINT8, BASE_HEX, VALS(framing_info_vals), 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_um_fixed_e,
{ "Extension",
"rlc-lte.um.fixed.e", FT_UINT8, BASE_HEX, VALS(fixed_extension_vals), 0x0,
"Extension in fixed part of UM header", HFILL
}
},
{ &hf_rlc_lte_um_sn,
{ "Sequence number",
"rlc-lte.um.sn", FT_UINT8, BASE_DEC, 0, 0x0,
"Unacknowledged Mode Sequence Number", HFILL
}
},
{ &hf_rlc_lte_um_fixed_reserved,
{ "Reserved",
"rlc-lte.um.reserved", FT_UINT8, BASE_DEC, 0, 0xe0,
"Unacknowledged Mode Fixed header reserved bits", HFILL
}
},
{ &hf_rlc_lte_um_data,
{ "UM Data",
"rlc-lte.um.data", FT_BYTES, BASE_NONE, 0, 0x0,
"Unacknowledged Mode Data", HFILL
}
},
{ &hf_rlc_lte_extension_part,
{ "Extension Part",
"rlc-lte.extension-part", FT_STRING, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_extension_e,
{ "Extension",
"rlc-lte.extension.e", FT_UINT8, BASE_HEX, VALS(extension_extension_vals), 0x0,
"Extension in extended part of the header", HFILL
}
},
{ &hf_rlc_lte_extension_li,
{ "Length Indicator",
"rlc-lte.extension.li", FT_UINT16, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_extension_padding,
{ "Padding",
"rlc-lte.extension.padding", FT_UINT8, BASE_HEX, 0, 0x0f,
"Extension header padding", HFILL
}
},
{ &hf_rlc_lte_am,
{ "AM",
"rlc-lte.am", FT_STRING, BASE_NONE, NULL, 0x0,
"Acknowledged Mode", HFILL
}
},
{ &hf_rlc_lte_am_header,
{ "AM Header",
"rlc-lte.am.header", FT_STRING, BASE_NONE, NULL, 0x0,
"Acknowledged Mode Header", HFILL
}
},
{ &hf_rlc_lte_am_data_control,
{ "Frame type",
"rlc-lte.am.frame-type", FT_UINT8, BASE_HEX, VALS(data_or_control_vals), 0x80,
"AM Frame Type (Control or Data)", HFILL
}
},
{ &hf_rlc_lte_am_rf,
{ "Re-segmentation Flag",
"rlc-lte.am.rf", FT_UINT8, BASE_HEX, VALS(resegmentation_flag_vals), 0x40,
"AM Re-segmentation Flag", HFILL
}
},
{ &hf_rlc_lte_am_p,
{ "Polling Bit",
"rlc-lte.am.p", FT_UINT8, BASE_HEX, VALS(polling_bit_vals), 0x20,
NULL, HFILL
}
},
{ &hf_rlc_lte_am_fi,
{ "Framing Info",
"rlc-lte.am.fi", FT_UINT8, BASE_HEX, VALS(framing_info_vals), 0x18,
"AM Framing Info", HFILL
}
},
{ &hf_rlc_lte_am_fixed_e,
{ "Extension",
"rlc-lte.am.fixed.e", FT_UINT8, BASE_HEX, VALS(fixed_extension_vals), 0x04,
"Fixed Extension Bit", HFILL
}
},
{ &hf_rlc_lte_am_fixed_sn,
{ "Sequence Number",
"rlc-lte.am.fixed.sn", FT_UINT16, BASE_DEC, 0, 0x03ff,
"AM Fixed Sequence Number", HFILL
}
},
{ &hf_rlc_lte_am_segment_lsf,
{ "Last Segment Flag",
"rlc-lte.am.segment.lsf", FT_UINT8, BASE_HEX, VALS(lsf_vals), 0x80,
NULL, HFILL
}
},
{ &hf_rlc_lte_am_segment_so,
{ "Segment Offset",
"rlc-lte.am.segment.offset", FT_UINT16, BASE_DEC, 0, 0x7fff,
NULL, HFILL
}
},
{ &hf_rlc_lte_am_data,
{ "AM Data",
"rlc-lte.am.data", FT_BYTES, BASE_NONE, 0, 0x0,
"Acknowledged Mode Data", HFILL
}
},
{ &hf_rlc_lte_am_cpt,
{ "Control PDU Type",
"rlc-lte.am.cpt", FT_UINT8, BASE_HEX, VALS(control_pdu_type_vals), 0x70,
"AM Control PDU Type", HFILL
}
},
{ &hf_rlc_lte_am_ack_sn,
{ "ACK Sequence Number",
"rlc-lte.am.ack-sn", FT_UINT16, BASE_DEC, 0, 0x0,
"Sequence Number we expect to receive next", HFILL
}
},
{ &hf_rlc_lte_am_e1,
{ "Extension bit 1",
"rlc-lte.am.e1", FT_UINT8, BASE_HEX, VALS(am_e1_vals), 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_am_e2,
{ "Extension bit 2",
"rlc-lte.am.e2", FT_UINT8, BASE_HEX, VALS(am_e2_vals), 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_am_nacks,
{ "Number of NACKs",
"rlc-lte.am.nacks", FT_UINT16, BASE_DEC, 0, 0x0,
"Number of NACKs in this status PDU", HFILL
}
},
{ &hf_rlc_lte_am_nack_sn,
{ "NACK Sequence Number",
"rlc-lte.am.nack-sn", FT_UINT16, BASE_DEC, 0, 0x0,
"Negative Acknowledgement Sequence Number", HFILL
}
},
{ &hf_rlc_lte_am_so_start,
{ "SO Start",
"rlc-lte.am.so-start", FT_UINT16, BASE_DEC, 0, 0x0,
"Segment Offset Start byte index", HFILL
}
},
{ &hf_rlc_lte_am_so_end,
{ "SO End",
"rlc-lte.am.so-end", FT_UINT16, BASE_DEC, 0, 0x0,
"Segment Offset End byte index", HFILL
}
},
{ &hf_rlc_lte_predefined_pdu,
{ "Predefined data",
"rlc-lte.predefined-data", FT_BYTES, BASE_NONE, 0, 0x0,
"Predefined test data", HFILL
}
},
{ &hf_rlc_lte_sequence_analysis,
{ "Sequence Analysis",
"rlc-lte.sequence-analysis", FT_STRING, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_ok,
{ "OK",
"rlc-lte.sequence-analysis.ok", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_previous_frame,
{ "Previous frame for channel",
"rlc-lte.sequence-analysis.previous-frame", FT_FRAMENUM, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_next_frame,
{ "Next frame for channel",
"rlc-lte.sequence-analysis.next-frame", FT_FRAMENUM, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_expected_sn,
{ "Expected SN",
"rlc-lte.sequence-analysis.expected-sn", FT_UINT16, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_framing_info_correct,
{ "Frame info continued correctly",
"rlc-lte.sequence-analysis.framing-info-correct", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_mac_retx,
{ "Frame retransmitted by MAC",
"rlc-lte.sequence-analysis.mac-retx", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_retx,
{ "Retransmitted frame",
"rlc-lte.sequence-analysis.retx", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_skipped,
{ "Skipped frames",
"rlc-lte.sequence-analysis.skipped-frames", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_repeated,
{ "Repeated frame",
"rlc-lte.sequence-analysis.repeated-frame", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_repeated_nack,
{ "Repeated NACK",
"rlc-lte.sequence-analysis.repeated-nack", FT_UINT16, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_repeated_nack_original_frame,
{ "Frame with previous status PDU",
"rlc-lte.sequence-analysis.repeated-nack.original-frame", FT_FRAMENUM, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_ack_out_of_range,
{ "Out of range ACK",
"rlc-lte.sequence-analysis.ack-out-of-range", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_sequence_analysis_ack_out_of_range_opposite_frame,
{ "Frame with most recent SN",
"rlc-lte.sequence-analysis.ack-out-of-range.last-sn-frame", FT_FRAMENUM, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_reassembly_source,
{ "Reassembly Source",
"rlc-lte.reassembly-info", FT_STRING, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_reassembly_source_number_of_segments,
{ "Number of segments",
"rlc-lte.reassembly-info.number-of-segments", FT_UINT16, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_reassembly_source_total_length,
{ "Total length",
"rlc-lte.reassembly-info.total-length", FT_UINT16, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_reassembly_source_segment,
{ "Segment",
"rlc-lte.reassembly-info.segment", FT_NONE, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_reassembly_source_segment_sn,
{ "SN",
"rlc-lte.reassembly-info.segment.sn", FT_UINT16, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_reassembly_source_segment_framenum,
{ "Frame",
"rlc-lte.reassembly-info.segment.frame", FT_FRAMENUM, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_reassembly_source_segment_length,
{ "Length",
"rlc-lte.reassembly-info.segment.length", FT_UINT32, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_rlc_lte_header_only,
{ "RLC PDU Header only",
"rlc-lte.header-only", FT_UINT8, BASE_DEC, VALS(header_only_vals), 0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_rlc_lte,
&ett_rlc_lte_context,
&ett_rlc_lte_um_header,
&ett_rlc_lte_am_header,
&ett_rlc_lte_extension_part,
&ett_rlc_lte_sequence_analysis,
&ett_rlc_lte_reassembly_source,
&ett_rlc_lte_reassembly_source_segment
};
static ei_register_info ei[] = {
{ &ei_rlc_lte_sequence_analysis_last_segment_not_continued, { "rlc-lte.sequence-analysis.last-segment-not-continued", PI_SEQUENCE, PI_WARN, "Last segment of previous PDU was not continued for UE", EXPFILL }},
{ &ei_rlc_lte_sequence_analysis_last_segment_complete, { "rlc-lte.sequence-analysis.last-segment-complete", PI_SEQUENCE, PI_WARN, "Last segment of previous PDU was complete, but new segment was not started on UE", EXPFILL }},
{ &ei_rlc_lte_sequence_analysis_mac_retx, { "rlc-lte.sequence-analysis.mac-retx.expert", PI_SEQUENCE, PI_WARN, "AM Frame retransmitted due to MAC retx!", EXPFILL }},
{ &ei_rlc_lte_sequence_analysis_retx, { "rlc-lte.sequence-analysis.retx.expert", PI_SEQUENCE, PI_WARN, "AM Frame retransmitted most likely in response to NACK", EXPFILL }},
{ &ei_rlc_lte_sequence_analysis_repeated, { "rlc-lte.sequence-analysis.repeated-frame.expert", PI_SEQUENCE, PI_WARN, "AM SN Repeated - probably because didn't receive Status PDU?", EXPFILL }},
{ &ei_rlc_lte_am_sn_missing, { "rlc-lte.sequence-analysis.am-sn.missing", PI_SEQUENCE, PI_WARN, "AM SNs missing", EXPFILL }},
{ &ei_rlc_lte_sequence_analysis_ack_out_of_range_opposite_frame, { "rlc-lte.sequence-analysis.ack-out-of-range.last-sn-frame.expert", PI_SEQUENCE, PI_ERROR, "AM ACK for SN - but last received SN in other direction is X", EXPFILL }},
{ &ei_rlc_lte_um_sn_missing, { "rlc-lte.sequence-analysis.um-sn.missing", PI_SEQUENCE, PI_WARN, "UM SNs missing", EXPFILL }},
{ &ei_rlc_lte_um_sn_repeated, { "rlc-lte.sequence-analysis.um-sn.repeated", PI_SEQUENCE, PI_WARN, "UM SN repeated", EXPFILL }},
{ &ei_rlc_lte_wrong_sequence_number, { "rlc-lte.wrong-sequence-number", PI_SEQUENCE, PI_WARN, "Wrong Sequence Number", EXPFILL }},
{ &ei_rlc_lte_sequence_analysis_repeated_nack, { "rlc-lte.sequence-analysis.repeated-nack.expert", PI_SEQUENCE, PI_ERROR, "Same SN NACKd on successive Status PDUs", EXPFILL }},
{ &ei_rlc_lte_reserved_bits_not_zero, { "rlc-lte.reserved-bits-not-zero", PI_MALFORMED, PI_ERROR, "Reserved bits not zero", EXPFILL }},
{ &ei_rlc_lte_um_sn, { "rlc-lte.um.sn.invalid", PI_MALFORMED, PI_ERROR, "Invalid sequence number length", EXPFILL }},
{ &ei_rlc_lte_header_only, { "rlc-lte.header-only.expert", PI_SEQUENCE, PI_NOTE, "RLC PDU SDUs have been omitted", EXPFILL }},
{ &ei_rlc_lte_am_cpt, { "rlc-lte.am.cpt.invalid", PI_MALFORMED, PI_ERROR, "RLC Control frame type not handled", EXPFILL }},
{ &ei_rlc_lte_am_nack_sn_ack_same, { "rlc-lte.am.nack-sn.ack-same", PI_MALFORMED, PI_ERROR, "Status PDU shouldn't ACK and NACK the same sequence number", EXPFILL }},
{ &ei_rlc_lte_am_nack_sn_ahead_ack, { "rlc-lte.am.nack-sn.ahead-ack", PI_MALFORMED, PI_ERROR, "NACK must not be ahead of ACK in status PDU", EXPFILL }},
{ &ei_rlc_lte_am_nack_sn_partial, { "rlc-lte.am.nack-sn.partial", PI_SEQUENCE, PI_WARN, "Status PDU reports NACK (partial)", EXPFILL }},
{ &ei_rlc_lte_am_nack_sn, { "rlc-lte.am.nack-sn.expert", PI_SEQUENCE, PI_WARN, "Status PDU reports NACK", EXPFILL }},
{ &ei_rlc_lte_bytes_after_status_pdu_complete, { "rlc-lte.bytes-after-status-pdu-complete", PI_MALFORMED, PI_ERROR, "bytes remaining after Status PDU complete", EXPFILL }},
{ &ei_rlc_lte_am_data_no_data_beyond_extensions, { "rlc-lte.am-data.no-data-beyond-extensions", PI_MALFORMED, PI_ERROR, "AM data PDU doesn't contain any data beyond extensions", EXPFILL }},
{ &ei_rlc_lte_am_data_no_data, { "rlc-lte.am-data.no-data", PI_MALFORMED, PI_ERROR, "AM data PDU doesn't contain any data", EXPFILL }},
{ &ei_rlc_lte_context_mode, { "rlc-lte.mode.invalid", PI_MALFORMED, PI_ERROR, "Unrecognised RLC Mode set", EXPFILL }},
};
static const enum_val_t sequence_analysis_vals[] = {
{"no-analysis", "No-Analysis", FALSE},
{"mac-only", "Only-MAC-frames", SEQUENCE_ANALYSIS_MAC_ONLY},
{"rlc-only", "Only-RLC-frames", SEQUENCE_ANALYSIS_RLC_ONLY},
{NULL, NULL, -1}
};
module_t *rlc_lte_module;
expert_module_t* expert_rlc_lte;
proto_rlc_lte = proto_register_protocol("RLC-LTE", "RLC-LTE", "rlc-lte");
proto_register_field_array(proto_rlc_lte, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_rlc_lte = expert_register_protocol(proto_rlc_lte);
expert_register_field_array(expert_rlc_lte, ei, array_length(ei));
register_dissector("rlc-lte", dissect_rlc_lte, proto_rlc_lte);
rlc_lte_tap = register_tap("rlc-lte");
rlc_lte_module = prefs_register_protocol(proto_rlc_lte, NULL);
prefs_register_enum_preference(rlc_lte_module, "do_sequence_analysis_am",
"Do sequence analysis for AM channels",
"Attempt to keep track of PDUs for AM channels, and point out problems",
&global_rlc_lte_am_sequence_analysis, sequence_analysis_vals, FALSE);
prefs_register_enum_preference(rlc_lte_module, "do_sequence_analysis",
"Do sequence analysis for UM channels",
"Attempt to keep track of PDUs for UM channels, and point out problems",
&global_rlc_lte_um_sequence_analysis, sequence_analysis_vals, FALSE);
prefs_register_bool_preference(rlc_lte_module, "call_pdcp_for_srb",
"Call PDCP dissector for SRB PDUs",
"Call PDCP dissector for signalling PDUs. Note that without reassembly, it can"
"only be called for complete PDUs (i.e. not segmented over RLC)",
&global_rlc_lte_call_pdcp_for_srb);
prefs_register_enum_preference(rlc_lte_module, "call_pdcp_for_drb",
"Call PDCP dissector for DRB PDUs",
"Call PDCP dissector for user-plane PDUs. Note that without reassembly, it can"
"only be called for complete PDUs (i.e. not segmented over RLC)",
&global_rlc_lte_call_pdcp_for_drb, pdcp_drb_col_vals, FALSE);
prefs_register_bool_preference(rlc_lte_module, "call_rrc_for_ccch",
"Call RRC dissector for CCCH PDUs",
"Call RRC dissector for CCCH PDUs",
&global_rlc_lte_call_rrc_for_ccch);
prefs_register_bool_preference(rlc_lte_module, "call_rrc_for_mcch",
"Call RRC dissector for MCCH PDUs",
"Call RRC dissector for MCCH PDUs Note that without reassembly, it can"
"only be called for complete PDUs (i.e. not segmented over RLC)",
&global_rlc_lte_call_rrc_for_mcch);
prefs_register_bool_preference(rlc_lte_module, "call_ip_for_mtch",
"Call IP dissector for MTCH PDUs",
"Call ip dissector for MTCH PDUs Note that without reassembly, it can"
"only be called for complete PDUs (i.e. not segmented over RLC)",
&global_rlc_lte_call_ip_for_mtch);
prefs_register_bool_preference(rlc_lte_module, "heuristic_rlc_lte_over_udp",
"Try Heuristic LTE-RLC over UDP framing",
"When enabled, use heuristic dissector to find RLC-LTE frames sent with "
"UDP framing",
&global_rlc_lte_heur);
prefs_register_bool_preference(rlc_lte_module, "header_only_mode",
"May see RLC headers only",
"When enabled, if data is not present, don't report as an error, but instead "
"add expert info to indicate that headers were omitted",
&global_rlc_lte_headers_expected);
prefs_register_bool_preference(rlc_lte_module, "reassembly",
"Attempt SDU reassembly",
"When enabled, attempts to re-assemble upper-layer SDUs that are split over "
"more than one RLC PDU. Note: does not currently support out-of-order or "
"re-segmentation. N.B. sequence analysis must also be turned on in order "
"for reassembly to work",
&global_rlc_lte_reassembly);
register_init_routine(&rlc_lte_init_protocol);
}
void
proto_reg_handoff_rlc_lte(void)
{
heur_dissector_add("udp", dissect_rlc_lte_heur, proto_rlc_lte);
pdcp_lte_handle = find_dissector("pdcp-lte");
ip_handle = find_dissector("ip");
}
