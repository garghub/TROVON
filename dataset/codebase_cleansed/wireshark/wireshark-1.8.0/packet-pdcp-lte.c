static gint pdcp_channel_equal(gconstpointer v, gconstpointer v2)
{
const pdcp_channel_hash_key* val1 = (const pdcp_channel_hash_key *)v;
const pdcp_channel_hash_key* val2 = (const pdcp_channel_hash_key *)v2;
return (memcmp(val1, val2, sizeof(pdcp_channel_hash_key)) == 0);
}
static guint pdcp_channel_hash_func(gconstpointer v)
{
const pdcp_channel_hash_key* val1 = (const pdcp_channel_hash_key *)v;
return val1->ueId + val1->plane + val1->channelId + val1->direction;
}
static gint pdcp_result_hash_equal(gconstpointer v, gconstpointer v2)
{
const pdcp_result_hash_key* val1 = (const pdcp_result_hash_key *)v;
const pdcp_result_hash_key* val2 = (const pdcp_result_hash_key *)v2;
return (memcmp(val1, val2, sizeof(pdcp_result_hash_key)) == 0);
}
static guint pdcp_result_hash_func(gconstpointer v)
{
const pdcp_result_hash_key* val1 = (const pdcp_result_hash_key *)v;
return val1->frameNumber + (val1->channelId<<13) +
(val1->plane<<5) +
(val1->SN<<18) +
(val1->direction<<9);
}
static gpointer get_report_hash_key(guint16 SN, guint32 frameNumber,
pdcp_lte_info *p_pdcp_lte_info,
gboolean do_persist)
{
static pdcp_result_hash_key key;
pdcp_result_hash_key *p_key;
if (do_persist) {
p_key = se_new0(pdcp_result_hash_key);
}
else {
memset(&key, 0, sizeof(pdcp_result_hash_key));
p_key = &key;
}
p_key->frameNumber = frameNumber;
p_key->SN = SN;
p_key->plane = (guint8)p_pdcp_lte_info->plane;
p_key->channelId = p_pdcp_lte_info->channelId;
p_key->direction = p_pdcp_lte_info->direction;
return p_key;
}
static void addChannelSequenceInfo(pdcp_sequence_report_in_frame *p,
pdcp_lte_info *p_pdcp_lte_info,
guint16 sequenceNumber,
packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb)
{
proto_tree *seqnum_tree;
proto_item *seqnum_ti;
proto_item *ti_expected_sn;
proto_item *ti;
seqnum_ti = proto_tree_add_string_format(tree,
hf_pdcp_lte_sequence_analysis,
tvb, 0, 0,
"", "Sequence Analysis");
seqnum_tree = proto_item_add_subtree(seqnum_ti,
ett_pdcp_lte_sequence_analysis);
PROTO_ITEM_SET_GENERATED(seqnum_ti);
if (p->previousFrameNum != 0) {
proto_tree_add_uint(seqnum_tree, hf_pdcp_lte_sequence_analysis_previous_frame,
tvb, 0, 0, p->previousFrameNum);
}
ti_expected_sn = proto_tree_add_uint(seqnum_tree, hf_pdcp_lte_sequence_analysis_expected_sn,
tvb, 0, 0, p->sequenceExpected);
PROTO_ITEM_SET_GENERATED(ti_expected_sn);
switch (p_pdcp_lte_info->seqnum_length) {
case PDCP_SN_LENGTH_5_BITS:
case PDCP_SN_LENGTH_7_BITS:
case PDCP_SN_LENGTH_12_BITS:
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
switch (p->state) {
case SN_OK:
PROTO_ITEM_SET_HIDDEN(ti_expected_sn);
ti = proto_tree_add_boolean(seqnum_tree, hf_pdcp_lte_sequence_analysis_ok,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
proto_item_append_text(seqnum_ti, " - OK");
if (p->nextFrameNum != 0) {
proto_tree_add_uint(seqnum_tree, hf_pdcp_lte_sequence_analysis_next_frame,
tvb, 0, 0, p->nextFrameNum);
}
break;
case SN_Missing:
ti = proto_tree_add_boolean(seqnum_tree, hf_pdcp_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_pdcp_lte_sequence_analysis_skipped,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
if (p->lastSN != p->firstSN) {
expert_add_info_format(pinfo, ti, PI_SEQUENCE, PI_WARN,
"PDCP SNs (%u to %u) missing for %s on UE %u",
p->firstSN, p->lastSN,
val_to_str_const(p_pdcp_lte_info->direction, direction_vals, "Unknown"),
p_pdcp_lte_info->ueid);
proto_item_append_text(seqnum_ti, " - SNs missing (%u to %u)",
p->firstSN, p->lastSN);
}
else {
expert_add_info_format(pinfo, ti, PI_SEQUENCE, PI_WARN,
"PDCP SN (%u) missing for %s on UE %u",
p->firstSN,
val_to_str_const(p_pdcp_lte_info->direction, direction_vals, "Unknown"),
p_pdcp_lte_info->ueid);
proto_item_append_text(seqnum_ti, " - SN missing (%u)",
p->firstSN);
}
break;
case SN_Repeated:
ti = proto_tree_add_boolean(seqnum_tree, hf_pdcp_lte_sequence_analysis_ok,
tvb, 0, 0, FALSE);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_boolean(seqnum_tree, hf_pdcp_lte_sequence_analysis_repeated,
tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(ti);
expert_add_info_format(pinfo, ti, PI_SEQUENCE, PI_WARN,
"PDCP SN (%u) repeated for %s for UE %u",
p->firstSN,
val_to_str_const(p_pdcp_lte_info->direction, direction_vals, "Unknown"),
p_pdcp_lte_info->ueid);
proto_item_append_text(seqnum_ti, "- SN %u Repeated",
p->firstSN);
break;
default:
expert_add_info_format(pinfo, ti_expected_sn, PI_SEQUENCE, PI_WARN,
"Wrong Sequence Number for %s on UE %u - got %u, expected %u",
val_to_str_const(p_pdcp_lte_info->direction, direction_vals, "Unknown"),
p_pdcp_lte_info->ueid, sequenceNumber, p->sequenceExpected);
break;
}
}
static void checkChannelSequenceInfo(packet_info *pinfo, tvbuff_t *tvb,
pdcp_lte_info *p_pdcp_lte_info,
guint16 sequenceNumber,
proto_tree *tree)
{
pdcp_channel_hash_key channel_key;
pdcp_channel_hash_key *p_channel_key;
pdcp_channel_status *p_channel_status;
pdcp_sequence_report_in_frame *p_report_in_frame = NULL;
gboolean createdChannel = FALSE;
guint16 expectedSequenceNumber = 0;
guint16 snLimit = 0;
if (pinfo->fd->flags.visited) {
p_report_in_frame =
(pdcp_sequence_report_in_frame*)g_hash_table_lookup(pdcp_lte_sequence_analysis_report_hash,
get_report_hash_key(sequenceNumber,
pinfo->fd->num,
p_pdcp_lte_info, FALSE));
if (p_report_in_frame != NULL) {
addChannelSequenceInfo(p_report_in_frame, p_pdcp_lte_info,
sequenceNumber,
pinfo, tree, tvb);
return;
}
else {
return;
}
}
memset(&channel_key, 0, sizeof(channel_key));
channel_key.ueId = p_pdcp_lte_info->ueid;
channel_key.plane = p_pdcp_lte_info->plane;
channel_key.channelId = p_pdcp_lte_info->channelId;
channel_key.direction = p_pdcp_lte_info->direction;
p_channel_status = (pdcp_channel_status*)g_hash_table_lookup(pdcp_sequence_analysis_channel_hash, &channel_key);
if (p_channel_status == NULL) {
createdChannel = TRUE;
p_channel_status = se_new0(pdcp_channel_status);
p_channel_key = se_memdup(&channel_key, sizeof(pdcp_channel_hash_key));
g_hash_table_insert(pdcp_sequence_analysis_channel_hash, p_channel_key, p_channel_status);
}
p_report_in_frame = se_new(pdcp_sequence_report_in_frame);
p_report_in_frame->nextFrameNum = 0;
switch (p_pdcp_lte_info->seqnum_length) {
case PDCP_SN_LENGTH_5_BITS:
snLimit = 32;
break;
case PDCP_SN_LENGTH_7_BITS:
snLimit = 128;
break;
case PDCP_SN_LENGTH_12_BITS:
snLimit = 4096;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
if (!createdChannel) {
expectedSequenceNumber = (p_channel_status->previousSequenceNumber + 1) % snLimit;
}
else {
expectedSequenceNumber = sequenceNumber;
}
p_report_in_frame->sequenceExpectedCorrect = (sequenceNumber == expectedSequenceNumber);
if (!p_report_in_frame->sequenceExpectedCorrect) {
if (((snLimit + expectedSequenceNumber - sequenceNumber) % snLimit) > 15) {
p_report_in_frame->state = SN_Missing;
p_report_in_frame->firstSN = expectedSequenceNumber;
p_report_in_frame->lastSN = (snLimit + sequenceNumber - 1) % snLimit;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
p_channel_status->previousFrameNum = pinfo->fd->num;
p_channel_status->previousSequenceNumber = sequenceNumber;
}
else {
p_report_in_frame->state = SN_Repeated;
p_report_in_frame->firstSN = sequenceNumber;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
}
}
else {
p_report_in_frame->state = SN_OK;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
p_channel_status->previousFrameNum = pinfo->fd->num;
p_channel_status->previousSequenceNumber = sequenceNumber;
if (p_report_in_frame->previousFrameNum != 0) {
pdcp_sequence_report_in_frame *p_previous_report;
p_previous_report = (pdcp_sequence_report_in_frame*)g_hash_table_lookup(pdcp_lte_sequence_analysis_report_hash,
get_report_hash_key((sequenceNumber+4095) % 4096,
p_report_in_frame->previousFrameNum,
p_pdcp_lte_info,
FALSE));
if (p_previous_report != NULL) {
p_previous_report->nextFrameNum = pinfo->fd->num;
}
}
}
g_hash_table_insert(pdcp_lte_sequence_analysis_report_hash,
get_report_hash_key(sequenceNumber, pinfo->fd->num,
p_pdcp_lte_info, TRUE),
p_report_in_frame);
addChannelSequenceInfo(p_report_in_frame, p_pdcp_lte_info, sequenceNumber,
pinfo, tree, tvb);
}
static void write_pdu_label_and_info(proto_item *pdu_ti,
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
}
static void show_pdcp_config(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree,
pdcp_lte_info *p_pdcp_info)
{
proto_item *ti;
proto_tree *configuration_tree;
proto_item *configuration_ti = proto_tree_add_item(tree,
hf_pdcp_lte_configuration,
tvb, 0, 0, ENC_ASCII|ENC_NA);
configuration_tree = proto_item_add_subtree(configuration_ti, ett_pdcp_configuration);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_direction, tvb, 0, 0,
p_pdcp_info->direction);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_plane, tvb, 0, 0,
p_pdcp_info->plane);
PROTO_ITEM_SET_GENERATED(ti);
if (p_pdcp_info->ueid != 0) {
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_ueid, tvb, 0, 0,
p_pdcp_info->ueid);
PROTO_ITEM_SET_GENERATED(ti);
}
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_channel_type, tvb, 0, 0,
p_pdcp_info->channelType);
PROTO_ITEM_SET_GENERATED(ti);
if (p_pdcp_info->channelId != 0) {
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_channel_id, tvb, 0, 0,
p_pdcp_info->channelId);
PROTO_ITEM_SET_GENERATED(ti);
}
if (p_pdcp_info->plane == USER_PLANE) {
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_no_header_pdu, tvb, 0, 0,
p_pdcp_info->no_header_pdu);
PROTO_ITEM_SET_GENERATED(ti);
if (!p_pdcp_info->no_header_pdu) {
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_seqnum_length, tvb, 0, 0,
p_pdcp_info->seqnum_length);
PROTO_ITEM_SET_GENERATED(ti);
}
}
ti = proto_tree_add_boolean(configuration_tree, hf_pdcp_lte_rohc_compression, tvb, 0, 0,
p_pdcp_info->rohc_compression);
PROTO_ITEM_SET_GENERATED(ti);
if (p_pdcp_info->rohc_compression) {
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_rohc_mode, tvb, 0, 0,
p_pdcp_info->mode);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_rohc_rnd, tvb, 0, 0,
p_pdcp_info->rnd);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_rohc_udp_checksum_present, tvb, 0, 0,
p_pdcp_info->udp_checkum_present);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_rohc_profile, tvb, 0, 0,
p_pdcp_info->profile);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_cid_inclusion_info, tvb, 0, 0,
p_pdcp_info->cid_inclusion_info);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_large_cid_present, tvb, 0, 0,
p_pdcp_info->large_cid_present);
PROTO_ITEM_SET_GENERATED(ti);
}
proto_item_append_text(configuration_ti, "(direction=%s, plane=%s",
val_to_str_const(p_pdcp_info->direction, direction_vals, "Unknown"),
val_to_str_const(p_pdcp_info->plane, pdcp_plane_vals, "Unknown"));
if (p_pdcp_info->rohc_compression) {
const char *mode = val_to_str_const(p_pdcp_info->mode, rohc_mode_vals, "Error");
proto_item_append_text(configuration_ti, ", mode=%c, profile=%s",
mode[0],
val_to_str_const(p_pdcp_info->profile, rohc_profile_vals, "Unknown"));
}
proto_item_append_text(configuration_ti, ")");
PROTO_ITEM_SET_GENERATED(configuration_ti);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s: ",
val_to_str_const(p_pdcp_info->plane, pdcp_plane_vals, "Unknown"));
}
static dissector_handle_t lookup_rrc_dissector_handle(struct pdcp_lte_info *p_pdcp_info)
{
dissector_handle_t rrc_handle = 0;
switch (p_pdcp_info->channelType)
{
case Channel_CCCH:
if (p_pdcp_info->direction == DIRECTION_UPLINK) {
rrc_handle = find_dissector("lte_rrc.ul_ccch");
}
else {
rrc_handle = find_dissector("lte_rrc.dl_ccch");
}
break;
case Channel_PCCH:
rrc_handle = find_dissector("lte-rrc.pcch");
break;
case Channel_BCCH:
switch (p_pdcp_info->BCCHTransport) {
case BCH_TRANSPORT:
rrc_handle = find_dissector("lte_rrc.bcch_bch");
break;
case DLSCH_TRANSPORT:
rrc_handle = find_dissector("lte_rrc.bcch_dl_sch");
break;
}
break;
case Channel_DCCH:
if (p_pdcp_info->direction == DIRECTION_UPLINK) {
rrc_handle = find_dissector("lte_rrc.ul_dcch");
}
else {
rrc_handle = find_dissector("lte_rrc.dl_dcch");
}
break;
default:
break;
}
return rrc_handle;
}
static gboolean dissect_pdcp_lte_heur(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
gint offset = 0;
struct pdcp_lte_info *p_pdcp_lte_info;
tvbuff_t *pdcp_tvb;
guint8 tag = 0;
gboolean infoAlreadySet = FALSE;
gboolean seqnumLengthTagPresent = FALSE;
if (!global_pdcp_lte_heur) {
return FALSE;
}
if ((size_t)tvb_length_remaining(tvb, offset) < (strlen(PDCP_LTE_START_STRING)+3+2)) {
return FALSE;
}
if (tvb_strneql(tvb, offset, PDCP_LTE_START_STRING, strlen(PDCP_LTE_START_STRING)) != 0) {
return FALSE;
}
offset += (gint)strlen(PDCP_LTE_START_STRING);
p_pdcp_lte_info = (pdcp_lte_info *)p_get_proto_data(pinfo->fd, proto_pdcp_lte);
if (p_pdcp_lte_info == NULL) {
p_pdcp_lte_info = se_new0(pdcp_lte_info);
infoAlreadySet = FALSE;
}
else {
infoAlreadySet = TRUE;
}
p_pdcp_lte_info->no_header_pdu = tvb_get_guint8(tvb, offset++);
p_pdcp_lte_info->plane = tvb_get_guint8(tvb, offset++);
p_pdcp_lte_info->rohc_compression = tvb_get_guint8(tvb, offset++);
while (tag != PDCP_LTE_PAYLOAD_TAG) {
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case PDCP_LTE_SEQNUM_LENGTH_TAG:
p_pdcp_lte_info->seqnum_length = tvb_get_guint8(tvb, offset);
offset++;
seqnumLengthTagPresent = TRUE;
break;
case PDCP_LTE_DIRECTION_TAG:
p_pdcp_lte_info->direction = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_LOG_CHAN_TYPE_TAG:
p_pdcp_lte_info->channelType = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_BCCH_TRANSPORT_TYPE_TAG:
p_pdcp_lte_info->BCCHTransport = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_IP_VERSION_TAG:
p_pdcp_lte_info->rohc_ip_version = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case PDCP_LTE_ROHC_CID_INC_INFO_TAG:
p_pdcp_lte_info->cid_inclusion_info = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_LARGE_CID_PRES_TAG:
p_pdcp_lte_info->large_cid_present = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_MODE_TAG:
p_pdcp_lte_info->mode = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_RND_TAG:
p_pdcp_lte_info->rnd = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_UDP_CHECKSUM_PRES_TAG:
p_pdcp_lte_info->udp_checkum_present = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_PROFILE_TAG:
p_pdcp_lte_info->profile = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case PDCP_LTE_PAYLOAD_TAG:
continue;
default:
return FALSE;
}
}
if ((p_pdcp_lte_info->plane == USER_PLANE) && (seqnumLengthTagPresent == FALSE)) {
return FALSE;
}
if (!infoAlreadySet) {
p_add_proto_data(pinfo->fd, proto_pdcp_lte, p_pdcp_lte_info);
}
pdcp_tvb = tvb_new_subset(tvb, offset, -1, tvb_reported_length(tvb)-offset);
dissect_pdcp_lte(pdcp_tvb, pinfo, tree);
return TRUE;
}
static void dissect_pdcp_lte(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
const char *mode;
proto_tree *pdcp_tree = NULL;
proto_item *root_ti = NULL;
gint offset = 0;
gint rohc_offset;
struct pdcp_lte_info *p_pdcp_info;
rohc_info *p_rohc_info = NULL;
tvbuff_t *rohc_tvb = NULL;
#if 0
proto_tree *rohc_tree = NULL;
proto_item *rohc_ti = NULL;
guint8 base_header_byte;
gboolean udp_checksum_needed = TRUE;
gboolean ip_id_needed = TRUE;
#endif
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PDCP-LTE");
if ((global_pdcp_lte_layer_to_show == ShowRLCLayer) &&
(p_get_proto_data(pinfo->fd, proto_rlc_lte) != NULL)) {
col_set_writable(pinfo->cinfo, FALSE);
}
else {
col_clear(pinfo->cinfo, COL_INFO);
col_set_writable(pinfo->cinfo, TRUE);
}
if (tree) {
root_ti = proto_tree_add_item(tree, proto_pdcp_lte, tvb, offset, -1, ENC_NA);
pdcp_tree = proto_item_add_subtree(root_ti, ett_pdcp);
}
p_pdcp_info = p_get_proto_data(pinfo->fd, proto_pdcp_lte);
if (p_pdcp_info == NULL) {
return;
}
mode = val_to_str_const(p_pdcp_info->mode, rohc_mode_vals, "Error");
if (pdcp_tree) {
show_pdcp_config(pinfo, tvb, pdcp_tree, p_pdcp_info);
}
if (p_pdcp_info->rohc_compression) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (mode=%c)", mode[0]);
}
if (!p_pdcp_info->no_header_pdu) {
guint16 seqnum = 0;
gboolean seqnum_set = FALSE;
if (p_pdcp_info->plane == SIGNALING_PLANE) {
guint32 mac;
guint32 data_length;
guint8 reserved = (tvb_get_guint8(tvb, offset) & 0xe0) >> 5;
proto_item *ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_control_plane_reserved,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (reserved != 0) {
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR,
"PDCP signalling header reserved bits not zero");
}
seqnum = tvb_get_guint8(tvb, offset) & 0x1f;
seqnum_set = TRUE;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_seq_num_5, tvb, offset, 1, ENC_BIG_ENDIAN);
write_pdu_label_and_info(root_ti, pinfo, " sn=%-2u ", seqnum);
offset++;
if (global_pdcp_dissect_signalling_plane_as_rrc) {
dissector_handle_t rrc_handle = lookup_rrc_dissector_handle(p_pdcp_info);
if (rrc_handle != 0) {
tvbuff_t *payload_tvb = tvb_new_subset(tvb, offset,
tvb_length_remaining(tvb, offset) - 4,
tvb_length_remaining(tvb, offset) - 4);
gboolean was_writable = col_get_writable(pinfo->cinfo);
col_set_writable(pinfo->cinfo, TRUE);
call_dissector_only(rrc_handle, payload_tvb, pinfo, pdcp_tree);
col_set_writable(pinfo->cinfo, was_writable);
}
else {
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_signalling_data, tvb, offset,
tvb_length_remaining(tvb, offset) - 4, ENC_NA);
}
}
else {
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_signalling_data, tvb, offset,
tvb_length_remaining(tvb, offset) - 4, ENC_NA);
}
data_length = tvb_length_remaining(tvb, offset) - 4;
offset += data_length;
mac = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_mac, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
col_append_fstr(pinfo->cinfo, COL_INFO, " MAC=0x%08x (%u bytes data)",
mac, data_length);
}
else if (p_pdcp_info->plane == USER_PLANE) {
gboolean pdu_type = (tvb_get_guint8(tvb, offset) & 0x80) >> 7;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_data_control, tvb, offset, 1, ENC_BIG_ENDIAN);
if (pdu_type == 1) {
if (p_pdcp_info->seqnum_length == PDCP_SN_LENGTH_7_BITS) {
seqnum = tvb_get_guint8(tvb, offset) & 0x7f;
seqnum_set = TRUE;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_seq_num_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
else if (p_pdcp_info->seqnum_length == PDCP_SN_LENGTH_12_BITS) {
proto_item *ti;
guint8 reserved_value;
ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_reserved3, tvb, offset, 1, ENC_BIG_ENDIAN);
reserved_value = (tvb_get_guint8(tvb, offset) & 0x70) >> 4;
if (reserved_value != 0) {
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR,
"Reserved bits have value 0x%x - should be 0x0",
reserved_value);
}
seqnum = tvb_get_ntohs(tvb, offset) & 0x0fff;
seqnum_set = TRUE;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_seq_num_12, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else {
return;
}
write_pdu_label_and_info(root_ti, pinfo, " (SN=%u)", seqnum);
}
else {
guint8 control_pdu_type = (tvb_get_guint8(tvb, offset) & 0x70) >> 4;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_control_pdu_type, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (control_pdu_type) {
case 0:
{
guint16 fms;
guint not_received = 0;
guint sn;
proto_tree *bitmap_tree;
proto_item *bitmap_ti = NULL;
fms = tvb_get_ntohs(tvb, offset) & 0x0fff;
sn = (fms + 1) % 4096;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_fms, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tvb_length_remaining(tvb, offset) > 0) {
bitmap_ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_bitmap, tvb,
offset, -1, ENC_NA);
bitmap_tree = proto_item_add_subtree(bitmap_ti, ett_pdcp_rohc_report_bitmap);
for ( ; tvb_length_remaining(tvb, offset); offset++) {
guint bit_offset = 0;
for ( ; bit_offset < 8; bit_offset++) {
if ((tvb_get_guint8(tvb, offset) >> (7-bit_offset) & 0x1) == 0) {
proto_tree_add_boolean_bits_format_value(bitmap_tree, hf_pdcp_lte_bitmap_not_received, tvb, offset*8 + bit_offset,
1, 0, " (SN=%u)", sn);
not_received++;
}
sn = (sn + 1) % 4096;
}
}
}
if (bitmap_ti != NULL) {
proto_item_append_text(bitmap_ti, " (%u SNs not received)", not_received);
}
write_pdu_label_and_info(root_ti, pinfo, " Status Report (fms=%u) not-received=%u",
fms, not_received);
}
return;
case 1:
offset++;
break;
default:
return;
}
}
}
else {
write_pdu_label_and_info(root_ti, pinfo, " - INVALID PLANE (%u)",
p_pdcp_info->plane);
return;
}
if (seqnum_set) {
gboolean do_analysis = FALSE;
switch (global_pdcp_check_sequence_numbers) {
case FALSE:
break;
case SEQUENCE_ANALYSIS_RLC_ONLY:
if ((p_get_proto_data(pinfo->fd, proto_rlc_lte) != NULL) &&
!p_pdcp_info->is_retx) {
do_analysis = TRUE;
}
break;
case SEQUENCE_ANALYSIS_PDCP_ONLY:
if (p_get_proto_data(pinfo->fd, proto_rlc_lte) == NULL) {
do_analysis = TRUE;
}
break;
}
if (do_analysis) {
checkChannelSequenceInfo(pinfo, tvb, p_pdcp_info,
(guint16)seqnum, pdcp_tree);
}
}
}
else {
write_pdu_label_and_info(root_ti, pinfo, " No-Header ");
}
if (!p_pdcp_info->rohc_compression) {
if (tvb_length_remaining(tvb, offset) > 0) {
if (p_pdcp_info->plane == USER_PLANE) {
if (global_pdcp_dissect_user_plane_as_ip) {
tvbuff_t *payload_tvb = tvb_new_subset_remaining(tvb, offset);
if (global_pdcp_lte_layer_to_show != ShowTrafficLayer) {
col_set_writable(pinfo->cinfo, FALSE);
}
switch (tvb_get_guint8(tvb, offset) & 0xf0) {
case 0x40:
call_dissector_only(ip_handle, payload_tvb, pinfo, pdcp_tree);
break;
case 0x60:
call_dissector_only(ipv6_handle, payload_tvb, pinfo, pdcp_tree);
break;
default:
call_dissector_only(data_handle, payload_tvb, pinfo, pdcp_tree);
break;
}
if (global_pdcp_lte_layer_to_show == ShowTrafficLayer) {
col_set_writable(pinfo->cinfo, FALSE);
}
}
else {
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_user_plane_data, tvb, offset, -1, ENC_NA);
}
}
else {
if (global_pdcp_dissect_signalling_plane_as_rrc) {
dissector_handle_t rrc_handle = lookup_rrc_dissector_handle(p_pdcp_info);
if (rrc_handle != 0) {
tvbuff_t *payload_tvb = tvb_new_subset(tvb, offset,
tvb_length_remaining(tvb, offset),
tvb_length_remaining(tvb, offset));
call_dissector_only(rrc_handle, payload_tvb, pinfo, pdcp_tree);
}
else {
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_signalling_data, tvb, offset,
tvb_length_remaining(tvb, offset), ENC_NA);
}
}
else {
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_signalling_data, tvb, offset, -1, ENC_NA);
}
}
write_pdu_label_and_info(root_ti, pinfo, "(%u bytes data)",
tvb_length_remaining(tvb, offset));
}
col_set_writable(pinfo->cinfo, global_pdcp_lte_layer_to_show == ShowRLCLayer);
return;
}
if (!global_pdcp_dissect_rohc) {
col_append_fstr(pinfo->cinfo, COL_PROTOCOL, "|ROHC(%s)",
val_to_str_const(p_pdcp_info->profile, rohc_profile_vals, "Unknown"));
return;
}
#if 0
if (pdcp_tree) {
rohc_ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_rohc, tvb, offset, -1, ENC_NA);
rohc_tree = proto_item_add_subtree(rohc_ti, ett_pdcp_rohc);
}
#endif
rohc_offset = offset;
rohc_tvb = tvb_new_subset_remaining(tvb, rohc_offset);
p_rohc_info = ep_new(rohc_info);
p_rohc_info->rohc_compression = p_pdcp_info->rohc_compression;
p_rohc_info->rohc_ip_version = p_pdcp_info->rohc_ip_version;
p_rohc_info->cid_inclusion_info = p_pdcp_info->cid_inclusion_info;
p_rohc_info->large_cid_present = p_pdcp_info->large_cid_present;
p_rohc_info->mode = p_pdcp_info->mode;
p_rohc_info->rnd = p_pdcp_info->rnd;
p_rohc_info->udp_checkum_present = p_pdcp_info->udp_checkum_present;
p_rohc_info->profile = p_pdcp_info->profile;
p_rohc_info->last_created_item = NULL;
pinfo->private_data = p_rohc_info;
if (global_pdcp_lte_layer_to_show != ShowTrafficLayer) {
col_set_writable(pinfo->cinfo, FALSE);
}
else {
col_clear(pinfo->cinfo, COL_INFO);
}
call_dissector(rohc_handle, rohc_tvb, pinfo, tree);
col_set_writable(pinfo->cinfo, global_pdcp_lte_layer_to_show == ShowRLCLayer);
return;
#if 0
while (tvb_get_guint8(tvb, offset) == 0xe0) {
offset++;
}
if (offset > rohc_offset) {
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_padding, tvb, rohc_offset,
offset-rohc_offset, ENC_NA);
}
cid = 0;
if ((p_pdcp_info->cid_inclusion_info == CID_IN_ROHC_PACKET) &&
!p_pdcp_info->large_cid_present)
{
if (((tvb_get_guint8(tvb, offset) >> 4) & 0x0f) == 0x0e) {
cid = tvb_get_guint8(tvb, offset) & 0x0f;
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_add_cid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
else {
proto_item *ti = proto_tree_add_uint(rohc_tree, hf_pdcp_lte_rohc_add_cid, tvb, offset, 0, 0);
PROTO_ITEM_SET_GENERATED(ti);
}
}
base_header_byte = tvb_get_guint8(tvb, offset);
if ((base_header_byte & 0xfe) == 0xfc) {
p_rohc_info = ep_new(rohc_info);
p_rohc_info->rohc_compression = p_pdcp_info->rohc_compression;
p_rohc_info->rohc_ip_version = p_pdcp_info->rohc_ip_version;
p_rohc_info->cid_inclusion_info = p_pdcp_info->cid_inclusion_info;
p_rohc_info->large_cid_present = p_pdcp_info->large_cid_present;
p_rohc_info->mode = p_pdcp_info->mode;
p_rohc_info->rnd = p_pdcp_info->rnd;
p_rohc_info->udp_checkum_present = p_pdcp_info->udp_checkum_present;
p_rohc_info->profile = p_pdcp_info->profile;
p_rohc_info->last_created_item = NULL;
offset = dissect_rohc_ir_packet(tvb, rohc_tree, pinfo, offset, cid, TRUE, p_rohc_info);
udp_checksum_needed = FALSE;
ip_id_needed = FALSE;
}
else if (base_header_byte == 0xf8) {
p_rohc_info = ep_new(rohc_info);
p_rohc_info->rohc_compression = p_pdcp_info->rohc_compression;
p_rohc_info->rohc_ip_version = p_pdcp_info->rohc_ip_version;
p_rohc_info->cid_inclusion_info = p_pdcp_info->cid_inclusion_info;
p_rohc_info->large_cid_present = p_pdcp_info->large_cid_present;
p_rohc_info->mode = p_pdcp_info->mode;
p_rohc_info->rnd = p_pdcp_info->rnd;
p_rohc_info->udp_checkum_present = p_pdcp_info->udp_checkum_present;
p_rohc_info->profile = p_pdcp_info->profile;
p_rohc_info->last_created_item = NULL;
offset = dissect_rohc_ir_dyn_packet(tvb, rohc_tree, pinfo, offset, cid, TRUE, p_rohc_info);
udp_checksum_needed = FALSE;
ip_id_needed = FALSE;
}
else if (((base_header_byte & 0xf8) >> 3) == 0x1e) {
offset = dissect_pdcp_feedback_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
return;
}
else if ((base_header_byte & 0x80) == 0) {
if (((base_header_byte & 0xc0) == 0) &&
(p_pdcp_info->mode == RELIABLE_BIDIRECTIONAL)) {
offset = dissect_pdcp_r_0_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
else if ((((base_header_byte & 0x40) >> 6) == 1) &&
(p_pdcp_info->mode == RELIABLE_BIDIRECTIONAL)) {
offset = dissect_pdcp_r_0_crc_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
else {
offset = dissect_pdcp_uo_0_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
}
else if (((base_header_byte & 0xc0) >> 6) == 2) {
switch (p_pdcp_info->mode) {
case RELIABLE_BIDIRECTIONAL:
if (!((p_pdcp_info->rohc_ip_version == 4) &&
(!p_pdcp_info->rnd))) {
offset = dissect_pdcp_r_1_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
return;
}
else {
dissect_pdcp_r_1_ts_or_id_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
return;
}
break;
case UNIDIRECTIONAL:
case OPTIMISTIC_BIDIRECTIONAL:
if (!((p_pdcp_info->rohc_ip_version == 4) &&
(!p_pdcp_info->rnd))) {
dissect_pdcp_uo_1_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
} else {
dissect_pdcp_uo_1_ts_or_id_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
return;
}
}
else if (((base_header_byte & 0xe0) >> 5) == 6) {
if (!((p_pdcp_info->rohc_ip_version == 4) &&
(!p_pdcp_info->rnd))) {
dissect_pdcp_uor_2_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
}
else {
dissect_pdcp_uor_2_ts_or_id_packet(rohc_tree, rohc_ti, tvb, offset, p_pdcp_info, pinfo);
return;
}
}
else if ((base_header_byte & 0xfe) == 0xfe) {
return;
}
if (p_pdcp_info->rnd && ip_id_needed) {
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_ip_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (p_pdcp_info->udp_checkum_present && udp_checksum_needed) {
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_udp_checksum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(rohc_tree, hf_pdcp_lte_rohc_payload, tvb, offset, -1, ENC_NA);
}
#endif
}
static void pdcp_lte_init_protocol(void)
{
if (pdcp_sequence_analysis_channel_hash) {
g_hash_table_destroy(pdcp_sequence_analysis_channel_hash);
}
if (pdcp_lte_sequence_analysis_report_hash) {
g_hash_table_destroy(pdcp_lte_sequence_analysis_report_hash);
}
pdcp_sequence_analysis_channel_hash = g_hash_table_new(pdcp_channel_hash_func, pdcp_channel_equal);
pdcp_lte_sequence_analysis_report_hash = g_hash_table_new(pdcp_result_hash_func, pdcp_result_hash_equal);
}
void proto_register_pdcp(void)
{
static hf_register_info hf[] =
{
{ &hf_pdcp_lte_configuration,
{ "Configuration",
"pdcp-lte.configuration", FT_STRING, BASE_NONE, NULL, 0x0,
"Configuration info passed into dissector", HFILL
}
},
{ &hf_pdcp_lte_rohc_compression,
{ "ROHC Compression",
"pdcp-lte.rohc.compression", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_mode,
{ "ROHC Mode",
"pdcp-lte.rohc.mode", FT_UINT8, BASE_DEC, VALS(rohc_mode_vals), 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_rnd,
{ "RND",
"pdcp-lte.rohc.rnd", FT_UINT8, BASE_DEC, NULL, 0x0,
"RND of outer ip header", HFILL
}
},
{ &hf_pdcp_lte_rohc_udp_checksum_present,
{ "UDP Checksum",
"pdcp-lte.rohc.checksum-present", FT_UINT8, BASE_DEC, NULL, 0x0,
"UDP Checksum present", HFILL
}
},
{ &hf_pdcp_lte_direction,
{ "Direction",
"pdcp-lte.direction", FT_UINT8, BASE_DEC, VALS(direction_vals), 0x0,
"Direction of message", HFILL
}
},
{ &hf_pdcp_lte_ueid,
{ "UE",
"pdcp-lte.ueid", FT_UINT16, BASE_DEC, 0, 0x0,
"UE Identifier", HFILL
}
},
{ &hf_pdcp_lte_channel_type,
{ "Channel type",
"pdcp-lte.channel-type", FT_UINT8, BASE_DEC, VALS(logical_channel_vals), 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_channel_id,
{ "Channel Id",
"pdcp-lte.channel-id", FT_UINT8, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_profile,
{ "ROHC profile",
"pdcp-lte.rohc.profile", FT_UINT8, BASE_DEC, VALS(rohc_profile_vals), 0x0,
"ROHC Mode", HFILL
}
},
{ &hf_pdcp_lte_no_header_pdu,
{ "No Header PDU",
"pdcp-lte.no-header_pdu", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_plane,
{ "Plane",
"pdcp-lte.plane", FT_UINT8, BASE_DEC, VALS(pdcp_plane_vals), 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_seqnum_length,
{ "Seqnum length",
"pdcp-lte.seqnum_length", FT_UINT8, BASE_DEC, NULL, 0x0,
"Sequence Number Length", HFILL
}
},
{ &hf_pdcp_lte_cid_inclusion_info,
{ "CID Inclusion Info",
"pdcp-lte.cid-inclusion-info", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_large_cid_present,
{ "Large CID Present",
"pdcp-lte.large-cid-present", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_control_plane_reserved,
{ "Reserved",
"pdcp-lte.reserved", FT_UINT8, BASE_DEC, NULL, 0xe0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_seq_num_5,
{ "Seq Num",
"pdcp-lte.seq-num", FT_UINT8, BASE_DEC, NULL, 0x1f,
"PDCP Seq num", HFILL
}
},
{ &hf_pdcp_lte_seq_num_7,
{ "Seq Num",
"pdcp-lte.seq-num", FT_UINT8, BASE_DEC, NULL, 0x7f,
"PDCP Seq num", HFILL
}
},
{ &hf_pdcp_lte_reserved3,
{ "Reserved",
"pdcp-lte.reserved3", FT_UINT8, BASE_HEX, NULL, 0x70,
"3 reserved bits", HFILL
}
},
{ &hf_pdcp_lte_seq_num_12,
{ "Seq Num",
"pdcp-lte.seq-num", FT_UINT16, BASE_DEC, NULL, 0x0fff,
"PDCP Seq num", HFILL
}
},
{ &hf_pdcp_lte_signalling_data,
{ "Signalling Data",
"pdcp-lte.signalling-data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_mac,
{ "MAC",
"pdcp-lte.mac", FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_data_control,
{ "PDU Type",
"pdcp-lte.pdu-type", FT_UINT8, BASE_HEX, VALS(pdu_type_vals), 0x80,
NULL, HFILL
}
},
{ &hf_pdcp_lte_user_plane_data,
{ "User-Plane Data",
"pdcp-lte.user-data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_control_pdu_type,
{ "Control PDU Type",
"pdcp-lte.control-pdu-type", FT_UINT8, BASE_HEX, VALS(control_pdu_type_vals), 0x70,
NULL, HFILL
}
},
{ &hf_pdcp_lte_fms,
{ "First Missing Sequence Number",
"pdcp-lte.fms", FT_UINT16, BASE_DEC, NULL, 0x0fff,
"First Missing PDCP Sequence Number", HFILL
}
},
{ &hf_pdcp_lte_bitmap,
{ "Bitmap",
"pdcp-lte.bitmap", FT_NONE, BASE_NONE, NULL, 0x0,
"Status report bitmap (0=error, 1=OK)", HFILL
}
},
{ &hf_pdcp_lte_bitmap_not_received,
{ "Not Received",
"pdcp-lte.bitmap.error", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Status report PDU error", HFILL
}
},
{ &hf_pdcp_lte_sequence_analysis,
{ "Sequence Analysis",
"pdcp-lte.sequence-analysis", FT_STRING, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_sequence_analysis_ok,
{ "OK",
"pdcp-lte.sequence-analysis.ok", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_sequence_analysis_previous_frame,
{ "Previous frame for channel",
"pdcp-lte.sequence-analysis.previous-frame", FT_FRAMENUM, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_sequence_analysis_next_frame,
{ "Next frame for channel",
"pdcp-lte.sequence-analysis.next-frame", FT_FRAMENUM, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_sequence_analysis_expected_sn,
{ "Expected SN",
"pdcp-lte.sequence-analysis.expected-sn", FT_UINT16, BASE_DEC, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_sequence_analysis_skipped,
{ "Skipped frames",
"pdcp-lte.sequence-analysis.skipped-frames", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_sequence_analysis_repeated,
{ "Repeated frame",
"pdcp-lte.sequence-analysis.repeated-frame", FT_BOOLEAN, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
#if 0
{ &hf_pdcp_lte_rohc,
{ "ROHC Message",
"pdcp-lte.rohc", FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_padding,
{ "Padding",
"pdcp-lte.rohc.padding", FT_NONE, BASE_NONE, NULL, 0,
"ROHC Padding", HFILL
}
},
{ &hf_pdcp_lte_rohc_r_0_crc,
{ "R-0-CRC Packet",
"pdcp-lte.r-0-crc", FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback,
{ "Feedback",
"pdcp-lte.rohc.feedback", FT_NONE, BASE_NONE, NULL, 0,
"Feedback Packet", HFILL
}
},
{ &hf_pdcp_lte_rohc_type0_t,
{ "T",
"pdcp-lte.rohc.t0.t", FT_UINT8, BASE_HEX, VALS(t_vals), 0x20,
"Indicates whether frame type is TS (1) or ID (0)", HFILL
}
},
{ &hf_pdcp_lte_rohc_type1_t,
{ "T",
"pdcp-lte.rohc.t1.t", FT_UINT8, BASE_HEX, VALS(t_vals), 0x80,
"Indicates whether frame type is TS (1) or ID (0)", HFILL
}
},
{ &hf_pdcp_lte_rohc_type2_t,
{ "T",
"pdcp-lte.rohc.t2.t", FT_UINT8, BASE_HEX, VALS(t_vals), 0x80,
"Indicates whether frame type is TS (1) or ID (0)", HFILL
}
},
{ &hf_pdcp_lte_rohc_d,
{ "D",
"pdcp-lte.rohc.d", FT_UINT8, BASE_HEX, NULL, 0x01,
"Indicates whether Dynamic chain is present", HFILL
}
},
{ &hf_pdcp_lte_rohc_ir_crc,
{ "CRC",
"pdcp-lte.rohc.ir.crc", FT_UINT8, BASE_HEX, NULL, 0x0,
"8-bit CRC", HFILL
}
},
{ &hf_pdcp_lte_rohc_static_ipv4,
{ "Static IPv4 chain",
"pdcp-lte.rohc.static.ipv4", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_version,
{ "IP Version",
"pdcp-lte.rohc.ip-version", FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_protocol,
{ "IP Protocol",
"pdcp-lte.rohc.ip-protocol", FT_UINT8, BASE_DEC, VALS(ip_protocol_vals), 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_src,
{ "IP Source address",
"pdcp-lte.rohc.ip-src", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_dst,
{ "IP Destination address",
"pdcp-lte.rohc.ip-dst", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_udp,
{ "Static UDP chain",
"pdcp-lte.rohc.static.udp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_udp_src_port,
{ "Static UDP source port",
"pdcp-lte.rohc.static.udp.src-port", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_udp_dst_port,
{ "Static UDP destination port",
"pdcp-lte.rohc.static.udp.dst-port", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_rtp,
{ "Static RTP chain",
"pdcp-lte.rohc.static.rtp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_static_rtp_ssrc,
{ "SSRC",
"pdcp-lte.rohc.static.rtp.ssrc", FT_UINT32, BASE_DEC_HEX, NULL, 0x0,
"Static RTP chain SSRC", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4,
{ "Dynamic IPv4 chain",
"pdcp-lte.rohc.dynamic.ipv4", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_tos,
{ "ToS",
"pdcp-lte.rohc.ip.tos", FT_UINT8, BASE_HEX, NULL, 0x0,
"IP Type of Service", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_ttl,
{ "TTL",
"pdcp-lte.rohc.ip.ttl", FT_UINT8, BASE_HEX, NULL, 0x0,
"IP Time To Live", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_id,
{ "IP-ID",
"pdcp-lte.rohc.ip.id", FT_UINT16, BASE_HEX, NULL, 0x0,
"IP ID", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_df,
{ "Don't Fragment",
"pdcp-lte.rohc.ip.df", FT_UINT8, BASE_HEX, NULL, 0x80,
"IP Don't Fragment flag", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_rnd,
{ "Random IP-ID field",
"pdcp-lte.rohc.ip.rnd", FT_UINT8, BASE_HEX, NULL, 0x40,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_ipv4_nbo,
{ "Network Byte Order IP-ID field",
"pdcp-lte.rohc.ip.nbo", FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_udp,
{ "Dynamic UDP chain",
"pdcp-lte.rohc.dynamic.udp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_udp_checksum,
{ "UDP Checksum",
"pdcp-lte.rohc.dynamic.udp.checksum", FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_udp_seqnum,
{ "UDP Sequence Number",
"pdcp-lte.rohc.dynamic.udp.seqnum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp,
{ "Dynamic RTP chain",
"pdcp-lte.rohc.dynamic.rtp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_rx,
{ "RX",
"pdcp-lte.rohc.dynamic.rtp.rx", FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_cc,
{ "Contributing CSRCs",
"pdcp-lte.rohc.dynamic.rtp.cc", FT_UINT8, BASE_DEC, NULL, 0x0f,
"Dynamic RTP chain CCs", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_seqnum,
{ "RTP Sequence Number",
"pdcp-lte.rohc.dynamic.rtp.seqnum", FT_UINT16, BASE_DEC, NULL, 0x0,
"Dynamic RTP chain Sequence Number", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_timestamp,
{ "RTP Timestamp",
"pdcp-lte.rohc.dynamic.rtp.timestamp", FT_UINT32, BASE_DEC, NULL, 0x0,
"Dynamic RTP chain Timestamp", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_reserved3,
{ "Reserved",
"pdcp-lte.rohc.dynamic.rtp.reserved3", FT_UINT8, BASE_HEX, NULL, 0xc0,
"Reserved bits", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_x,
{ "X",
"pdcp-lte.rohc.dynamic.rtp.x", FT_UINT8, BASE_DEC, NULL, 0x10,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_mode,
{ "Mode",
"pdcp-lte.rohc.dynamic.rtp.mode", FT_UINT8, BASE_HEX, VALS(rohc_mode_vals), 0x0c,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_tis,
{ "TIS",
"pdcp-lte.rohc.dynamic.rtp.tis", FT_UINT8, BASE_HEX, NULL, 0x02,
"Dynamic RTP chain TIS (indicates time_stride present)", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_tss,
{ "TSS",
"pdcp-lte.rohc.dynamic.rtp.tss", FT_UINT8, BASE_HEX, NULL, 0x01,
"Dynamic RTP chain TSS (indicates TS_stride present)", HFILL
}
},
{ &hf_pdcp_lte_rohc_dynamic_rtp_ts_stride,
{ "TS Stride",
"pdcp-lte.rohc.dynamic.rtp.ts-stride", FT_UINT32, BASE_DEC, NULL, 0x0,
"Dynamic RTP chain TS Stride", HFILL
}
},
{ &hf_pdcp_lte_rohc_ts,
{ "TS",
"pdcp-lte.rohc.ts", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_m,
{ "M",
"pdcp-lte.rohc.m", FT_UINT8, BASE_DEC, NULL, 0x40,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_uor2_sn,
{ "SN",
"pdcp-lte.rohc.uor2.sn", FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_uor2_x,
{ "X",
"pdcp-lte.rohc.uor2.x", FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_add_cid,
{ "Add-CID",
"pdcp-lte.rohc.add-cid", FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_large_cid,
{ "Large-CID",
"pdcp-lte.rohc.large-cid", FT_UINT16, BASE_DEC, NULL, 0x07ff,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_uo0_sn,
{ "SN",
"pdcp-lte.rohc.uo0.sn", FT_UINT8, BASE_DEC, NULL, 0x78,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_uo0_crc,
{ "CRC",
"pdcp-lte.rohc.uo0.crc", FT_UINT8, BASE_DEC, NULL, 0x07,
"3-bit CRC", HFILL
}
},
{ &hf_pdcp_lte_rohc_r0_sn,
{ "SN",
"pdcp-lte.rohc.r0.sn", FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_r0_crc_sn,
{ "SN",
"pdcp-lte.rohc.r0-crc.sn", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_r0_crc_crc,
{ "CRC7",
"pdcp-lte.rohc.r0-crc.crc", FT_UINT8, BASE_DEC, NULL, 0x7f,
"CRC 7", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_code,
{ "Code",
"pdcp-lte.rohc.feedback-code", FT_UINT8, BASE_DEC, NULL, 0x07,
"Feedback options length (if > 0)", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_size,
{ "Size",
"pdcp-lte.rohc.feedback-size", FT_UINT8, BASE_DEC, NULL, 0x0,
"Feedback options length", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_feedback1,
{ "FEEDBACK-1 (SN)",
"pdcp-lte.rohc.feedback.feedback1", FT_UINT8, BASE_DEC, NULL, 0x0,
"Feedback-1", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_feedback2,
{ "FEEDBACK-2",
"pdcp-lte.rohc.feedback.feedback2", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_ack_type,
{ "Acktype",
"pdcp-lte.rohc.feedback-acktype", FT_UINT8, BASE_DEC, VALS(feedback_ack_vals), 0xc0,
"Feedback-2 ack type", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_mode,
{ "mode",
"pdcp-lte.rohc.feedback-mode", FT_UINT8, BASE_DEC, VALS(rohc_mode_vals), 0x30,
"Feedback mode", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_sn,
{ "SN",
"pdcp-lte.rohc.feedback-sn", FT_UINT16, BASE_DEC, NULL, 0x0fff,
"Feedback sequence number", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_option,
{ "Option",
"pdcp-lte.rohc.feedback-option", FT_UINT8, BASE_DEC, VALS(feedback_option_vals), 0xf0,
"Feedback option", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_length,
{ "Length",
"pdcp-lte.rohc.feedback-length", FT_UINT8, BASE_DEC, NULL, 0x0f,
"Feedback length", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_crc,
{ "CRC",
"pdcp-lte.rohc.feedback-crc", FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
"Feedback CRC", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_option_sn,
{ "SN",
"pdcp-lte.rohc.feedback-option-sn", FT_UINT8, BASE_DEC, NULL, 0x0,
"Feedback Option SN", HFILL
}
},
{ &hf_pdcp_lte_rohc_feedback_option_clock,
{ "Clock",
"pdcp-lte.rohc.feedback-option-clock", FT_UINT8, BASE_DEC, NULL, 0x0,
"Feedback Option Clock", HFILL
}
},
{ &hf_pdcp_lte_rohc_ip_id,
{ "IP-ID",
"pdcp-lte.rohc.ip-id", FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_udp_checksum,
{ "UDP Checksum",
"pdcp-lte.rohc.udp-checksum", FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_rohc_payload,
{ "Payload",
"pdcp-lte.rohc.payload", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
#endif
};
static gint *ett[] =
{
&ett_pdcp,
&ett_pdcp_configuration,
&ett_pdcp_packet,
&ett_pdcp_lte_sequence_analysis,
&ett_pdcp_rohc,
&ett_pdcp_rohc_static_ipv4,
&ett_pdcp_rohc_static_udp,
&ett_pdcp_rohc_static_rtp,
&ett_pdcp_rohc_dynamic_ipv4,
&ett_pdcp_rohc_dynamic_udp,
&ett_pdcp_rohc_dynamic_rtp,
&ett_pdcp_rohc_report_bitmap
};
static enum_val_t sequence_analysis_vals[] = {
{"no-analysis", "No-Analysis", FALSE},
{"rlc-only", "Only-RLC-frames", SEQUENCE_ANALYSIS_RLC_ONLY},
{"pdcp-only", "Only-PDCP-frames", SEQUENCE_ANALYSIS_PDCP_ONLY},
{NULL, NULL, -1}
};
static enum_val_t show_info_col_vals[] = {
{"show-rlc", "RLC Info", ShowRLCLayer},
{"show-pdcp", "PDCP Info", ShowPDCPLayer},
{"show-traffic", "Traffic Info", ShowTrafficLayer},
{NULL, NULL, -1}
};
module_t *pdcp_lte_module;
proto_pdcp_lte = proto_register_protocol("PDCP-LTE", "PDCP-LTE", "pdcp-lte");
proto_register_field_array(proto_pdcp_lte, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("pdcp-lte", dissect_pdcp_lte, proto_pdcp_lte);
pdcp_lte_module = prefs_register_protocol(proto_pdcp_lte, NULL);
prefs_register_obsolete_preference(pdcp_lte_module, "show_feedback_option_tag_length");
prefs_register_bool_preference(pdcp_lte_module, "show_user_plane_as_ip",
"Show uncompressed User-Plane data as IP",
"Show uncompressed User-Plane data as IP",
&global_pdcp_dissect_user_plane_as_ip);
prefs_register_bool_preference(pdcp_lte_module, "show_signalling_plane_as_rrc",
"Show unciphered Signalling-Plane data as RRC",
"Show unciphered Signalling-Plane data as RRC",
&global_pdcp_dissect_signalling_plane_as_rrc);
prefs_register_enum_preference(pdcp_lte_module, "check_sequence_numbers",
"Do sequence number analysis",
"Do sequence number analysis",
&global_pdcp_check_sequence_numbers, sequence_analysis_vals, FALSE);
prefs_register_bool_preference(pdcp_lte_module, "dissect_rohc",
"Attempt to decode ROHC data",
"Attempt to decode ROHC data",
&global_pdcp_dissect_rohc);
prefs_register_bool_preference(pdcp_lte_module, "heuristic_pdcp_lte_over_udp",
"Try Heuristic LTE-PDCP over UDP framing",
"When enabled, use heuristic dissector to find PDCP-LTE frames sent with "
"UDP framing",
&global_pdcp_lte_heur);
prefs_register_enum_preference(pdcp_lte_module, "layer_to_show",
"Which layer info to show in Info column",
"Can show RLC, PDCP or Traffic layer info in Info column",
&global_pdcp_lte_layer_to_show, show_info_col_vals, FALSE);
register_init_routine(&pdcp_lte_init_protocol);
}
void proto_reg_handoff_pdcp_lte(void)
{
heur_dissector_add("udp", dissect_pdcp_lte_heur, proto_pdcp_lte);
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
rohc_handle = find_dissector("rohc");
data_handle = find_dissector("data");
}
