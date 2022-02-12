static void
dcm_init(void)
{
guint i;
if (dcm_uid_table == NULL) {
dcm_uid_table = g_hash_table_new(g_str_hash, g_str_equal);
for (i = 0; i < array_length(dcm_uid_data); i++) {
g_hash_table_insert(dcm_uid_table, (gpointer) dcm_uid_data[i].value,
(gpointer) &dcm_uid_data[i]);
}
}
if (dcm_tag_table == NULL) {
dcm_tag_table = g_hash_table_new(NULL, NULL);
for (i = 0; i < array_length(dcm_tag_data); i++) {
g_hash_table_insert(dcm_tag_table, GUINT_TO_POINTER(dcm_tag_data[i].tag),
(gpointer) &dcm_tag_data[i]);
}
}
if (dcm_status_table == NULL) {
dcm_status_table = g_hash_table_new(NULL, NULL);
for (i = 0; i < array_length(dcm_status_data); i++) {
g_hash_table_insert(dcm_status_table, GUINT_TO_POINTER((guint32)dcm_status_data[i].value),
(gpointer)&dcm_status_data[i]);
}
}
reassembly_table_init(&dcm_pdv_reassembly_table,
&addresses_reassembly_table_functions);
}
static dcm_state_t *
dcm_state_new(void)
{
dcm_state_t *ds;
ds = (dcm_state_t *) wmem_alloc0(wmem_file_scope(), sizeof(dcm_state_t));
return ds;
}
static dcm_state_t *
dcm_state_get(packet_info *pinfo, gboolean create)
{
conversation_t *conv=NULL;
dcm_state_t *dcm_data=NULL;
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
if (conv == NULL) {
conv = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
}
else {
dcm_data = (dcm_state_t *)conversation_get_proto_data(conv, proto_dcm);
}
if (dcm_data == NULL && create) {
dcm_data = dcm_state_new();
conversation_add_proto_data(conv, proto_dcm, dcm_data);
conversation_set_dissector(conv, dcm_handle);
}
return dcm_data;
}
static dcm_state_assoc_t *
dcm_state_assoc_new(dcm_state_t *dcm_data, guint32 packet_no)
{
dcm_state_assoc_t *assoc;
assoc = (dcm_state_assoc_t *) wmem_alloc0(wmem_file_scope(), sizeof(dcm_state_assoc_t));
assoc->packet_no = packet_no;
if (dcm_data->last_assoc) {
dcm_data->last_assoc->next = assoc;
assoc->prev = dcm_data->last_assoc;
}
else {
dcm_data->first_assoc = assoc;
}
dcm_data->last_assoc = assoc;
return assoc;
}
static dcm_state_assoc_t *
dcm_state_assoc_get(dcm_state_t *dcm_data, guint32 packet_no, gboolean create)
{
dcm_state_assoc_t *assoc = NULL;
assoc=dcm_data->first_assoc;
while (assoc) {
if (assoc->next) {
if ((assoc->packet_no <= packet_no) && (packet_no < assoc->next->packet_no))
break;
}
else {
if (assoc->packet_no <= packet_no)
break;
}
assoc = assoc->next;
}
if (assoc == NULL && create) {
assoc = dcm_state_assoc_new(dcm_data, packet_no);
}
return assoc;
}
static dcm_state_pctx_t *
dcm_state_pctx_new(dcm_state_assoc_t *assoc, guint8 pctx_id)
{
dcm_state_pctx_t *pctx=NULL;
pctx = (dcm_state_pctx_t *)wmem_alloc0(wmem_file_scope(), sizeof(dcm_state_pctx_t));
pctx->id = pctx_id;
pctx->syntax = DCM_UNK;
if (assoc->last_pctx) {
assoc->last_pctx->next = pctx;
pctx->prev = assoc->last_pctx;
}
else {
assoc->first_pctx = pctx;
}
assoc->last_pctx = pctx;
return pctx;
}
static dcm_state_pctx_t *
dcm_state_pctx_get(dcm_state_assoc_t *assoc, guint8 pctx_id, gboolean create)
{
dcm_state_pctx_t *pctx =NULL;
pctx = assoc->first_pctx;
while (pctx) {
if (pctx->id == pctx_id)
break;
pctx = pctx->next;
}
if (pctx == NULL && create) {
pctx = dcm_state_pctx_new(assoc, pctx_id);
}
return pctx;
}
static dcm_state_pdv_t*
dcm_state_pdv_new(dcm_state_pctx_t *pctx, guint32 packet_no, guint32 offset)
{
dcm_state_pdv_t *pdv = NULL;
pdv = (dcm_state_pdv_t *) wmem_alloc0(wmem_file_scope(), sizeof(dcm_state_pdv_t));
pdv->syntax = DCM_UNK;
pdv->is_last_fragment = TRUE;
pdv->packet_no = packet_no;
pdv->offset = offset;
if (pctx->last_pdv) {
pctx->last_pdv->next = pdv;
pdv->prev = pctx->last_pdv;
}
else {
pctx->first_pdv = pdv;
}
pctx->last_pdv = pdv;
return pdv;
}
static dcm_state_pdv_t*
dcm_state_pdv_get(dcm_state_pctx_t *pctx, guint32 packet_no, guint32 offset, gboolean create)
{
dcm_state_pdv_t *pdv = NULL;
pdv=pctx->first_pdv;
while (pdv) {
if ((pdv->packet_no == packet_no) && (pdv->offset == offset))
break;
pdv = pdv->next;
}
if (pdv == NULL && create) {
pdv = dcm_state_pdv_new(pctx, packet_no, offset);
}
return pdv;
}
static dcm_state_pdv_t*
dcm_state_pdv_get_obj_start(dcm_state_pdv_t *pdv_curr)
{
dcm_state_pdv_t *pdv_first=pdv_curr;
while (pdv_first->prev && !pdv_first->prev->is_last_fragment) {
pdv_first = pdv_first->prev;
}
return pdv_first;
}
static const char *
dcm_pdu2str(guint8 item)
{
const char *s = "";
switch (item) {
case 1: s = "ASSOC Request"; break;
case 2: s = "ASSOC Accept"; break;
case 3: s = "ASSOC Reject"; break;
case 4: s = "Data"; break;
case 5: s = "RELEASE Request"; break;
case 6: s = "RELEASE Response"; break;
case 7: s = "ABORT"; break;
default: break;
}
return s;
}
static const char *
dcm_cmd2str(guint16 us)
{
const char *s = "";
switch (us) {
case 0x0001: s = "C-STORE-RQ"; break;
case 0x8001: s = "C-STORE-RSP"; break;
case 0x0010: s = "C-GET-RQ"; break;
case 0x8010: s = "C-GET-RSP"; break;
case 0x0020: s = "C-FIND-RQ"; break;
case 0x8020: s = "C-FIND-RSP"; break;
case 0x0021: s = "C-MOVE-RQ"; break;
case 0x8021: s = "C-MOVE-RSP"; break;
case 0x0030: s = "C-ECHO-RQ"; break;
case 0x8030: s = "C-ECHO-RSP"; break;
case 0x0100: s = "N-EVENT-REPORT-RQ"; break;
case 0x8100: s = "N-EVENT-REPORT-RSP"; break;
case 0x0110: s = "N-GET-RQ"; break;
case 0x8110: s = "N-GET-RSP"; break;
case 0x0120: s = "N-SET-RQ"; break;
case 0x8120: s = "N-SET-RSP"; break;
case 0x0130: s = "N-ACTION-RQ"; break;
case 0x8130: s = "N-ACTION-RSP"; break;
case 0x0140: s = "N-CREATE-RQ"; break;
case 0x8140: s = "N-CREATE-RSP"; break;
case 0x0150: s = "N-DELETE-RQ"; break;
case 0x8150: s = "N-DELETE-RSP"; break;
case 0x0fff: s = "C-CANCEL-RQ"; break;
default: break;
}
return s;
}
static const gchar *
dcm_rsp2str(guint16 status_value)
{
dcm_status_t *status = NULL;
const gchar *s = "";
status = (dcm_status_t*) g_hash_table_lookup(dcm_status_table, GUINT_TO_POINTER((guint32)status_value));
if (status) {
s = status->description;
}
else {
if ((status_value & 0xFF00) == 0xA700) {
s = "Refused: Out of Resources";
}
else if ((status_value & 0xFF00) == 0xA900) {
s = "Error: Data Set does not match SOP Class";
}
else if ((status_value & 0xF000) == 0xC000) {
s = "Error: Cannot understand/Unable to Process";
}
else {
s = "Unknown";
}
}
return s;
}
static const gchar*
dcm_uid_or_desc(gchar *dcm_uid, gchar *dcm_desc)
{
return (dcm_desc == NULL ? (dcm_uid == NULL ? "Malformed Packet" : dcm_uid) : dcm_desc);
}
static void
dcm_set_syntax(dcm_state_pctx_t *pctx, gchar *xfer_uid, const gchar *xfer_desc)
{
if ((pctx == NULL) || (xfer_uid == NULL) || (xfer_desc == NULL))
return;
g_free(pctx->xfer_uid);
g_free(pctx->xfer_desc);
pctx->syntax = 0;
pctx->xfer_uid = g_strdup(xfer_uid);
pctx->xfer_desc = g_strdup(xfer_desc);
if (0 == strcmp(xfer_uid, "1.2.840.10008.1.2"))
pctx->syntax = DCM_ILE;
else if (0 == strcmp(xfer_uid, "1.2.840.10008.1.2.1"))
pctx->syntax = DCM_ELE;
else if (0 == strcmp(xfer_uid, "1.2.840.10008.1.2.2"))
pctx->syntax = DCM_EBE;
else if (0 == strcmp(xfer_uid, "1.2.840.113619.5.2"))
pctx->syntax = DCM_ILE;
else if (0 == strcmp(xfer_uid, "1.2.840.10008.1.2.4.70"))
pctx->syntax = DCM_ELE;
else if (0 == strncmp(xfer_uid, "1.2.840.10008.1.2.4", 18))
pctx->syntax = DCM_ELE;
else if (0 == strcmp(xfer_uid, "1.2.840.10008.1.2.1.99"))
pctx->syntax = DCM_ELE;
}
static void
dcm_guint16_to_le(guint8 *buffer, guint16 value)
{
buffer[0]=(guint8) (value & 0x00FF);
buffer[1]=(guint8)((value & 0xFF00) >> 8);
}
static void
dcm_guint32_to_le(guint8 *buffer, guint32 value)
{
buffer[0]=(guint8) (value & 0x000000FF);
buffer[1]=(guint8)((value & 0x0000FF00) >> 8);
buffer[2]=(guint8)((value & 0x00FF0000) >> 16);
buffer[3]=(guint8)((value & 0xFF000000) >> 24);
}
static guint32
dcm_export_create_tag_base(guint8 *buffer, guint32 bufflen, guint32 offset,
guint16 grp, guint16 elm, guint16 vr,
const guint8 *value_buffer, guint32 value_len)
{
if (offset + 6 > bufflen) return bufflen;
dcm_guint16_to_le(buffer + offset, grp);
offset += 2;
dcm_guint16_to_le(buffer + offset, elm);
offset += 2;
memmove(buffer + offset, dcm_tag_vr_lookup[vr], 2);
offset += 2;
switch (vr) {
case DCM_VR_OB:
case DCM_VR_OW:
case DCM_VR_OF:
case DCM_VR_SQ:
case DCM_VR_UT:
case DCM_VR_UN:
if (offset + 6 > bufflen) return bufflen;
dcm_guint16_to_le(buffer + offset, 0);
offset += 2;
dcm_guint32_to_le(buffer + offset, value_len);
offset += 4;
break;
default:
if (offset + 2 > bufflen) return bufflen;
dcm_guint16_to_le(buffer + offset, (guint16)value_len);
offset += 2;
}
if (offset + value_len > bufflen) return bufflen;
memmove(buffer + offset, value_buffer, value_len);
offset += value_len;
return offset;
}
static guint32
dcm_export_create_tag_guint16(guint8 *buffer, guint32 bufflen, guint32 offset,
guint16 grp, guint16 elm, guint16 vr, guint16 value)
{
return dcm_export_create_tag_base(buffer, bufflen, offset, grp, elm, vr, (guint8*)&value, 2);
}
static guint32
dcm_export_create_tag_guint32(guint8 *buffer, guint32 bufflen, guint32 offset,
guint16 grp, guint16 elm, guint16 vr, guint32 value)
{
return dcm_export_create_tag_base(buffer, bufflen, offset, grp, elm, vr, (guint8*)&value, 4);
}
static guint32
dcm_export_create_tag_str(guint8 *buffer, guint32 bufflen, guint32 offset,
guint16 grp, guint16 elm, guint16 vr,
const gchar *value)
{
guint32 len;
if (!value) {
return offset;
}
len=(int)strlen(value);
if ((len & 0x01) == 1) {
len += 1;
}
return dcm_export_create_tag_base(buffer, bufflen, offset, grp, elm, vr, (const guint8 *)value, len);
}
static guint8*
dcm_export_create_header(guint32 *dcm_header_len, const gchar *sop_class_uid, gchar *sop_instance_uid, gchar *xfer_uid)
{
guint8 *dcm_header=NULL;
guint32 offset=0;
guint32 offset_header_len=0;
#define DCM_HEADER_MAX 512
dcm_header=(guint8 *)wmem_alloc0(wmem_packet_scope(), DCM_HEADER_MAX);
offset=128;
memmove(dcm_header+offset, "DICM", 4);
offset+=4;
offset_header_len=offset;
offset+=12;
offset=dcm_export_create_tag_guint16(dcm_header, DCM_HEADER_MAX, offset,
0x0002, 0x0001, DCM_VR_OB, 0x0100);
offset=dcm_export_create_tag_str(dcm_header, DCM_HEADER_MAX, offset,
0x0002, 0x0002, DCM_VR_UI, sop_class_uid);
offset=dcm_export_create_tag_str(dcm_header, DCM_HEADER_MAX, offset,
0x0002, 0x0003, DCM_VR_UI, sop_instance_uid);
offset=dcm_export_create_tag_str(dcm_header, DCM_HEADER_MAX, offset,
0x0002, 0x0010, DCM_VR_UI, xfer_uid);
offset=dcm_export_create_tag_str(dcm_header, DCM_HEADER_MAX, offset,
0x0002, 0x0012, DCM_VR_UI, WIRESHARK_IMPLEMENTATION_UID);
offset=dcm_export_create_tag_str(dcm_header, DCM_HEADER_MAX, offset,
0x0002, 0x0013, DCM_VR_SH, WIRESHARK_IMPLEMENTATION_VERSION);
dcm_export_create_tag_guint32(dcm_header, DCM_HEADER_MAX, offset_header_len,
0x0002, 0x0000, DCM_VR_UL, offset-offset_header_len-12);
*dcm_header_len=offset;
return dcm_header;
}
static void
dcm_export_create_object(packet_info *pinfo, dcm_state_assoc_t *assoc, dcm_state_pdv_t *pdv)
{
dicom_eo_t *eo_info = NULL;
dcm_state_pdv_t *pdv_curr = NULL;
dcm_state_pdv_t *pdv_same_pkt = NULL;
dcm_state_pctx_t *pctx = NULL;
guint8 *pdv_combined = NULL;
guint8 *pdv_combined_curr = NULL;
guint8 *dcm_header = NULL;
guint32 pdv_combined_len = 0;
guint32 dcm_header_len = 0;
guint16 cnt_same_pkt = 1;
gchar *filename;
const gchar *hostname;
const gchar *sop_class_uid;
gchar *sop_instance_uid;
pdv_curr = pdv;
pdv_same_pkt = pdv;
pdv_combined_len=pdv_curr->data_len;
while (pdv_curr->prev && !pdv_curr->prev->is_last_fragment) {
pdv_curr = pdv_curr->prev;
pdv_combined_len += pdv_curr->data_len;
}
while (pdv_same_pkt->prev && (pdv_same_pkt->prev->packet_no == pdv_same_pkt->packet_no)) {
pdv_same_pkt = pdv_same_pkt->prev;
cnt_same_pkt += 1;
}
pctx=dcm_state_pctx_get(assoc, pdv_curr->pctx_id, FALSE);
if (strlen(assoc->ae_calling)>0 && strlen(assoc->ae_called)>0 ) {
hostname = wmem_strdup_printf(wmem_packet_scope(), "%s <-> %s", assoc->ae_calling, assoc->ae_called);
}
else {
hostname = "AE title(s) unknown";
}
if (pdv->is_storage &&
pdv_curr->sop_class_uid && strlen(pdv_curr->sop_class_uid)>0 &&
pdv_curr->sop_instance_uid && strlen(pdv_curr->sop_instance_uid)>0) {
sop_class_uid = wmem_strndup(wmem_packet_scope(), pdv_curr->sop_class_uid, MAX_BUF_LEN);
sop_instance_uid = wmem_strndup(wmem_packet_scope(), pdv_curr->sop_instance_uid, MAX_BUF_LEN);
filename = wmem_strdup_printf(wmem_packet_scope(), "%06d-%d-%s.dcm", pinfo->fd->num, cnt_same_pkt,
g_strcanon(pdv_curr->sop_instance_uid, G_CSET_A_2_Z G_CSET_a_2_z G_CSET_DIGITS "-.", '-'));
}
else {
sop_class_uid = wmem_strdup(wmem_packet_scope(), WIRESHARK_MEDIA_STORAGE_SOP_CLASS_UID);
sop_instance_uid = wmem_strdup_printf(wmem_packet_scope(), "%s.%d.%d",
WIRESHARK_MEDIA_STORAGE_SOP_INSTANCE_UID_PREFIX, pinfo->fd->num, cnt_same_pkt);
filename = wmem_strdup_printf(wmem_packet_scope(), "%06d-%d-%s.dcm", pinfo->fd->num, cnt_same_pkt,
g_strcanon(pdv->desc, G_CSET_A_2_Z G_CSET_a_2_z G_CSET_DIGITS "-.", '-'));
}
if (global_dcm_export_header) {
if (pctx && pctx->xfer_uid && strlen(pctx->xfer_uid)>0) {
dcm_header=dcm_export_create_header(&dcm_header_len, sop_class_uid, sop_instance_uid, pctx->xfer_uid);
}
else {
dcm_header=dcm_export_create_header(&dcm_header_len, sop_class_uid, sop_instance_uid, NULL);
}
}
if (dcm_header_len + pdv_combined_len >= global_dcm_export_minsize) {
pdv_combined = (guint8 *)g_malloc0(dcm_header_len + pdv_combined_len);
pdv_combined_curr = pdv_combined;
if (dcm_header_len != 0) {
memmove(pdv_combined, dcm_header, dcm_header_len);
pdv_combined_curr += dcm_header_len;
}
while (!pdv_curr->is_last_fragment) {
memmove(pdv_combined_curr, pdv_curr->data, pdv_curr->data_len);
g_free(pdv_curr->data);
pdv_combined_curr += pdv_curr->data_len;
pdv_curr = pdv_curr->next;
}
memmove(pdv_combined_curr, pdv->data, pdv->data_len);
g_free(pdv_curr->data);
eo_info = (dicom_eo_t *)g_malloc0(sizeof(dicom_eo_t));
eo_info->hostname = g_strdup(hostname);
eo_info->filename = g_strdup(filename);
eo_info->content_type = g_strdup(pdv->desc);
eo_info->payload_data = pdv_combined;
eo_info->payload_len = dcm_header_len + pdv_combined_len;
tap_queue_packet(dicom_eo_tap, pinfo, eo_info);
}
}
static guint32
dissect_dcm_assoc_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset, dcm_state_assoc_t *assoc,
guint8 pdu_type, guint32 pdu_len)
{
proto_item *assoc_header_pitem = NULL;
proto_tree *assoc_header_ptree = NULL;
guint16 assoc_ver;
const gchar *buf_desc = NULL;
const char *reject_result_desc = "";
const char *reject_source_desc = "";
const char *reject_reason_desc = "";
const char *abort_source_desc = "";
const char *abort_reason_desc = "";
guint8 reject_result;
guint8 reject_source;
guint8 reject_reason;
guint8 abort_source;
guint8 abort_reason;
assoc_header_pitem = proto_tree_add_text(tree, tvb, offset, pdu_len, "Association Header");
assoc_header_ptree = proto_item_add_subtree(assoc_header_pitem, ett_assoc_header);
switch (pdu_type) {
case 1:
assoc_ver = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(assoc_header_ptree, hf_dcm_assoc_version, tvb, offset, 2, assoc_ver);
offset += 2;
offset += 2;
tvb_memcpy(tvb, assoc->ae_called, offset, 16);
assoc->ae_called[AEEND] = 0;
proto_tree_add_string(assoc_header_ptree, hf_dcm_assoc_called, tvb, offset, 16, assoc->ae_called);
offset += 16;
tvb_memcpy(tvb, assoc->ae_calling, offset, 16);
assoc->ae_calling[AEEND] = 0;
proto_tree_add_string(assoc_header_ptree, hf_dcm_assoc_calling, tvb, offset, 16, assoc->ae_calling);
offset += 16;
offset += 32;
buf_desc = wmem_strdup_printf(wmem_packet_scope(), "A-ASSOCIATE request %s --> %s",
g_strstrip(assoc->ae_calling), g_strstrip(assoc->ae_called));
offset = dissect_dcm_assoc_detail(tvb, pinfo, assoc_header_ptree, assoc,
offset, pdu_len-offset);
break;
case 2:
assoc_ver = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_uint(assoc_header_ptree, hf_dcm_assoc_version, tvb, offset, 2, assoc_ver);
offset += 2;
offset += 2;
tvb_memcpy(tvb, assoc->ae_called_resp, offset, 16);
assoc->ae_called_resp[AEEND] = 0;
proto_tree_add_string(assoc_header_ptree, hf_dcm_assoc_called, tvb, offset, 16, assoc->ae_called_resp);
offset += 16;
tvb_memcpy(tvb, assoc->ae_calling_resp, offset, 16);
assoc->ae_calling_resp[AEEND] = 0;
proto_tree_add_string(assoc_header_ptree, hf_dcm_assoc_calling, tvb, offset, 16, assoc->ae_calling_resp);
offset += 16;
offset += 32;
buf_desc = wmem_strdup_printf(wmem_packet_scope(), "A-ASSOCIATE accept %s <-- %s",
g_strstrip(assoc->ae_calling_resp), g_strstrip(assoc->ae_called_resp));
offset = dissect_dcm_assoc_detail(tvb, pinfo, assoc_header_ptree, assoc,
offset, pdu_len-offset);
break;
case 3:
offset += 1;
reject_result = tvb_get_guint8(tvb, offset);
reject_source = tvb_get_guint8(tvb, offset+1);
reject_reason = tvb_get_guint8(tvb, offset+2);
switch (reject_result) {
case 1: reject_result_desc = "Reject Permanent"; break;
case 2: reject_result_desc = "Reject Transient"; break;
default: break;
}
switch (reject_source) {
case 1:
reject_source_desc = "User";
switch (reject_reason) {
case 1: reject_reason_desc = "No reason given"; break;
case 2: reject_reason_desc = "Application context name not supported"; break;
case 3: reject_reason_desc = "Calling AE title not recognized"; break;
case 7: reject_reason_desc = "Called AE title not recognized"; break;
}
break;
case 2:
reject_source_desc = "Provider (ACSE)";
switch (reject_reason) {
case 1: reject_reason_desc = "No reason given"; break;
case 2: reject_reason_desc = "Protocol version not supported"; break;
}
break;
case 3:
reject_source_desc = "Provider (Presentation)";
switch (reject_reason) {
case 1: reject_reason_desc = "Temporary congestion"; break;
case 2: reject_reason_desc = "Local limit exceeded"; break;
}
break;
}
proto_tree_add_uint_format_value(assoc_header_ptree, hf_dcm_assoc_reject_result, tvb,
offset , 1, reject_result, "%s", reject_result_desc);
proto_tree_add_uint_format_value(assoc_header_ptree, hf_dcm_assoc_reject_source, tvb,
offset+1, 1, reject_source, "%s", reject_source_desc);
proto_tree_add_uint_format_value(assoc_header_ptree, hf_dcm_assoc_reject_reason, tvb,
offset+2, 1, reject_reason, "%s", reject_reason_desc);
offset += 3;
buf_desc = wmem_strdup_printf(wmem_packet_scope(), "A-ASSOCIATE reject %s <-- %s (%s)",
g_strstrip(assoc->ae_calling), g_strstrip(assoc->ae_called), reject_reason_desc);
expert_add_info(pinfo, assoc_header_pitem, &ei_dcm_assoc_rejected);
break;
case 5:
offset += 2;
buf_desc="A-RELEASE request";
break;
case 6:
offset += 2;
buf_desc="A-RELEASE response";
break;
case 7:
offset += 2;
abort_source = tvb_get_guint8(tvb, offset);
abort_reason = tvb_get_guint8(tvb, offset+1);
switch (abort_source) {
case 0:
abort_source_desc = "User";
abort_reason_desc = "N/A";
break;
case 1:
break;
case 2:
abort_source_desc = "Provider";
switch (abort_reason) {
case 0: abort_reason_desc = "Not specified"; break;
case 1: abort_reason_desc = "Unrecognized PDU"; break;
case 2: abort_reason_desc = "Unexpected PDU"; break;
case 4: abort_reason_desc = "Unrecognized PDU parameter"; break;
case 5: abort_reason_desc = "Unexpected PDU parameter"; break;
case 6: abort_reason_desc = "Invalid PDU parameter value"; break;
}
break;
}
proto_tree_add_uint_format_value(assoc_header_ptree, hf_dcm_assoc_abort_source,
tvb, offset , 1, abort_source, "%s", abort_source_desc);
proto_tree_add_uint_format_value(assoc_header_ptree, hf_dcm_assoc_abort_reason,
tvb, offset+1, 1, abort_reason, "%s", abort_reason_desc);
offset += 2;
if (abort_source == 0) {
buf_desc = wmem_strdup_printf(wmem_packet_scope(), "ABORT %s --> %s",
g_strstrip(assoc->ae_calling), g_strstrip(assoc->ae_called));
}
else {
buf_desc = wmem_strdup_printf(wmem_packet_scope(), "ABORT %s <-- %s (%s)",
g_strstrip(assoc->ae_calling), g_strstrip(assoc->ae_called), abort_reason_desc);
}
expert_add_info(pinfo, assoc_header_pitem, &ei_dcm_assoc_aborted);
break;
}
proto_item_set_text(assoc_header_pitem, "%s", buf_desc);
col_append_str(pinfo->cinfo, COL_INFO, buf_desc);
col_set_str(pinfo->cinfo, COL_INFO, wmem_strdup(wmem_file_scope(), buf_desc));
proto_item_append_text(tree, ", %s", buf_desc);
return offset;
}
static void
dissect_dcm_assoc_item(tvbuff_t *tvb, proto_tree *tree, guint32 offset,
const gchar *pitem_prefix, int item_value_type,
gchar **item_value, const gchar **item_description,
int *hf_type, int *hf_len, int *hf_value, int ett_subtree)
{
proto_tree *assoc_item_ptree = NULL;
proto_item *assoc_item_pitem = NULL;
dcm_uid_t *uid = NULL;
guint32 item_number = 0;
guint8 item_type = 0;
guint16 item_len = 0;
gchar *buf_desc = NULL;
*item_value = NULL;
*item_description = NULL;
buf_desc = (gchar *)wmem_alloc0(wmem_packet_scope(), MAX_BUF_LEN);
item_type = tvb_get_guint8(tvb, offset);
item_len = tvb_get_ntohs(tvb, offset+2);
assoc_item_pitem = proto_tree_add_text(tree, tvb, offset, item_len+4, "%s", pitem_prefix);
assoc_item_ptree = proto_item_add_subtree(assoc_item_pitem, ett_subtree);
proto_tree_add_uint(assoc_item_ptree, *hf_type, tvb, offset, 1, item_type);
proto_tree_add_uint(assoc_item_ptree, *hf_len, tvb, offset+2, 2, item_len);
switch (item_value_type) {
case DCM_ITEM_VALUE_TYPE_UID:
*item_value = (gchar *)tvb_get_string(wmem_packet_scope(), tvb, offset+4, item_len);
uid = (dcm_uid_t *)g_hash_table_lookup(dcm_uid_table, (gpointer) *item_value);
if (uid) {
*item_description = uid->name;
g_snprintf(buf_desc, MAX_BUF_LEN, "%s (%s)", *item_description, *item_value);
}
else {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s", *item_value);
}
proto_item_append_text(assoc_item_pitem, "%s", buf_desc);
proto_tree_add_string(assoc_item_ptree, *hf_value, tvb, offset+4, item_len, buf_desc);
break;
case DCM_ITEM_VALUE_TYPE_STRING:
*item_value = (gchar *)tvb_get_string(wmem_packet_scope(), tvb, offset+4, item_len);
proto_item_append_text(assoc_item_pitem, "%s", *item_value);
proto_tree_add_string(assoc_item_ptree, *hf_value, tvb, offset+4, item_len, *item_value);
break;
case DCM_ITEM_VALUE_TYPE_UINT32:
item_number = tvb_get_ntohl(tvb, offset+4);
*item_value = (gchar *)wmem_alloc0(wmem_file_scope(), MAX_BUF_LEN);
g_snprintf(*item_value, MAX_BUF_LEN, "%d", item_number);
proto_item_append_text(assoc_item_pitem, "%s", *item_value);
proto_tree_add_item(assoc_item_ptree, *hf_value, tvb, offset+4, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
static void
dissect_dcm_assoc_sopclass_extneg(tvbuff_t *tvb, proto_tree *tree, guint32 offset)
{
proto_tree *assoc_item_extneg_tree = NULL;
proto_item *assoc_item_extneg_item = NULL;
guint16 item_len = 0;
guint16 sop_class_uid_len = 0;
gint32 cnt = 0;
gchar *buf_desc = NULL;
dcm_uid_t *sopclassuid=NULL;
gchar *sopclassuid_str = NULL;
buf_desc = (gchar *)wmem_alloc0(wmem_packet_scope(), MAX_BUF_LEN);
item_len = tvb_get_ntohs(tvb, offset+2);
sop_class_uid_len = tvb_get_ntohs(tvb, offset+4);
assoc_item_extneg_item = proto_tree_add_item(tree, hf_dcm_info_extneg, tvb, offset, item_len+4, ENC_NA);
proto_item_set_text(assoc_item_extneg_item, "Ext. Neg.: ");
assoc_item_extneg_tree = proto_item_add_subtree(assoc_item_extneg_item, ett_assoc_info_extneg);
proto_tree_add_item(assoc_item_extneg_tree, hf_dcm_assoc_item_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(assoc_item_extneg_tree, hf_dcm_assoc_item_len, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(assoc_item_extneg_tree, hf_dcm_info_extneg_sopclassuid_len, tvb, offset+4, 2, ENC_BIG_ENDIAN);
sopclassuid_str = (gchar *)tvb_get_string(wmem_packet_scope(), tvb, offset+6, sop_class_uid_len);
sopclassuid = (dcm_uid_t *)g_hash_table_lookup(dcm_uid_table, (gpointer) sopclassuid_str);
if (sopclassuid) {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s (%s)", sopclassuid->name, sopclassuid->value);
}
else {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s", sopclassuid_str);
}
proto_item_append_text(assoc_item_extneg_item, "%s", buf_desc);
proto_tree_add_string(assoc_item_extneg_tree, hf_dcm_info_extneg_sopclassuid, tvb, offset+6, sop_class_uid_len, buf_desc);
cnt = item_len - 2 - sop_class_uid_len;
if (0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_PATIENT_ROOT_QR_FIND) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_STUDY_ROOT_QR_FIND) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_PATIENT_STUDY_ONLY_QR_FIND) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_PATIENT_ROOT_QR_MOVE) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_STUDY_ROOT_QR_MOVE) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_PATIENT_STUDY_ONLY_QR_MOVE) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_PATIENT_ROOT_QR_GET) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_STUDY_ROOT_QR_GET) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_PATIENT_STUDY_ONLY_QR_GET))
{
if (cnt<=0)
{
return;
}
proto_tree_add_item(assoc_item_extneg_tree, hf_dcm_info_extneg_relational_query, tvb, offset+6+sop_class_uid_len, 1, ENC_NA);
--cnt;
}
if (0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_PATIENT_ROOT_QR_FIND) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_STUDY_ROOT_QR_FIND) ||
0 == strcmp(sopclassuid_str, DCM_UID_SOP_CLASS_PATIENT_STUDY_ONLY_QR_FIND))
{
if (cnt<=0)
{
return;
}
proto_tree_add_item(assoc_item_extneg_tree, hf_dcm_info_extneg_date_time_matching, tvb, offset+7+sop_class_uid_len, 1, ENC_NA);
--cnt;
if (cnt<=0)
{
return;
}
proto_tree_add_item(assoc_item_extneg_tree, hf_dcm_info_extneg_fuzzy_semantic_matching, tvb, offset+8+sop_class_uid_len, 1, ENC_NA);
--cnt;
if (cnt<=0)
{
return;
}
proto_tree_add_item(assoc_item_extneg_tree, hf_dcm_info_extneg_timezone_query_adjustment, tvb, offset+9+sop_class_uid_len, 1, ENC_NA);
--cnt;
}
}
static void
dissect_dcm_assoc_role_selection(tvbuff_t *tvb, proto_tree *tree, guint32 offset)
{
proto_tree *assoc_item_rolesel_tree;
proto_item *assoc_item_rolesel_item;
guint16 item_len, sop_class_uid_len;
guint8 scp_role, scu_role;
gchar *buf_desc = (gchar *)wmem_alloc0(wmem_packet_scope(), MAX_BUF_LEN);
dcm_uid_t *sopclassuid;
gchar *sopclassuid_str;
item_len = tvb_get_ntohs(tvb, offset+2);
sop_class_uid_len = tvb_get_ntohs(tvb, offset+4);
assoc_item_rolesel_item = proto_tree_add_item(tree, hf_dcm_info_rolesel, tvb, offset, item_len+4, ENC_NA);
proto_item_set_text(assoc_item_rolesel_item, "Role Selection: ");
assoc_item_rolesel_tree = proto_item_add_subtree(assoc_item_rolesel_item, ett_assoc_info_rolesel);
proto_tree_add_item(assoc_item_rolesel_tree, hf_dcm_assoc_item_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(assoc_item_rolesel_tree, hf_dcm_assoc_item_len, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(assoc_item_rolesel_tree, hf_dcm_info_rolesel_sopclassuid_len, tvb, offset+4, 2, ENC_BIG_ENDIAN);
sopclassuid_str = (gchar *)tvb_get_string(wmem_packet_scope(), tvb, offset+6, sop_class_uid_len);
sopclassuid = (dcm_uid_t *)g_hash_table_lookup(dcm_uid_table, (gpointer) sopclassuid_str);
scu_role = tvb_get_guint8(tvb, offset+6+sop_class_uid_len);
scp_role = tvb_get_guint8(tvb, offset+7+sop_class_uid_len);
if (scu_role) {
proto_item_append_text(assoc_item_rolesel_item, "%s", "SCU-role: yes");
}
else {
proto_item_append_text(assoc_item_rolesel_item, "%s", "SCU-role: no");
}
if (scp_role) {
proto_item_append_text(assoc_item_rolesel_item, ", %s", "SCP-role: yes");
}
else {
proto_item_append_text(assoc_item_rolesel_item, ", %s", "SCP-role: no");
}
if (sopclassuid) {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s (%s)", sopclassuid->name, sopclassuid->value);
}
else {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s", sopclassuid_str);
}
proto_tree_add_string(assoc_item_rolesel_tree, hf_dcm_info_rolesel_sopclassuid, tvb, offset+6, sop_class_uid_len, buf_desc);
proto_tree_add_item(assoc_item_rolesel_tree, hf_dcm_info_rolesel_scurole, tvb, offset+6+sop_class_uid_len, 1, ENC_NA);
proto_tree_add_item(assoc_item_rolesel_tree, hf_dcm_info_rolesel_scprole, tvb, offset+7+sop_class_uid_len, 1, ENC_NA);
}
static void
dissect_dcm_assoc_async_negotiation(tvbuff_t *tvb, proto_tree *tree, guint32 offset)
{
proto_tree *assoc_item_asyncneg_tree;
proto_item *assoc_item_asyncneg_item;
guint16 item_len, max_num_ops_inv, max_num_ops_per = 0;
item_len = tvb_get_ntohs(tvb, offset+2);
assoc_item_asyncneg_item = proto_tree_add_item(tree, hf_dcm_info_async_neg, tvb, offset, item_len+4, ENC_NA);
proto_item_set_text(assoc_item_asyncneg_item, "Async Negotiation: ");
assoc_item_asyncneg_tree = proto_item_add_subtree(assoc_item_asyncneg_item, ett_assoc_info_async_neg);
proto_tree_add_item(assoc_item_asyncneg_tree, hf_dcm_assoc_item_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(assoc_item_asyncneg_tree, hf_dcm_assoc_item_len, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(assoc_item_asyncneg_tree, hf_dcm_info_async_neg_max_num_ops_inv, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(assoc_item_asyncneg_tree, hf_dcm_info_async_neg_max_num_ops_per, tvb, offset+6, 2, ENC_BIG_ENDIAN);
max_num_ops_inv = tvb_get_ntohs(tvb, offset+4);
max_num_ops_per = tvb_get_ntohs(tvb, offset+6);
proto_item_append_text(assoc_item_asyncneg_item, "%s%d", "Maximum Number Operations Invoked: ", max_num_ops_inv);
if (max_num_ops_inv==0) proto_item_append_text(assoc_item_asyncneg_item, "%s", " (unlimited)");
proto_item_append_text(assoc_item_asyncneg_item, ", %s%d", "Maximum Number Operations Performed: ", max_num_ops_per);
if (max_num_ops_per==0) proto_item_append_text(assoc_item_asyncneg_item, "%s", " (unlimited)");
}
static void
dissect_dcm_pctx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dcm_state_assoc_t *assoc, guint32 offset, guint32 len,
const gchar *pitem_prefix, gboolean is_assoc_request)
{
proto_tree *pctx_ptree = NULL;
proto_item *pctx_pitem = NULL;
dcm_state_pctx_t *pctx = NULL;
guint8 item_type = 0;
guint16 item_len = 0;
guint8 pctx_id = 0;
guint8 pctx_result = 0;
const char *pctx_result_desc = "";
gchar *pctx_abss_uid = NULL;
const gchar *pctx_abss_desc = NULL;
gchar *pctx_xfer_uid = NULL;
const gchar *pctx_xfer_desc = NULL;
gchar *buf_desc = NULL;
guint32 endpos = 0;
int cnt_abbs = 0;
int cnt_xfer = 0;
buf_desc = (gchar *)wmem_alloc0(wmem_packet_scope(), MAX_BUF_LEN);
endpos = offset + len;
item_type = tvb_get_guint8(tvb, offset-4);
item_len = tvb_get_ntohs(tvb, offset-2);
pctx_pitem = proto_tree_add_text(tree, tvb, offset-4, item_len+4, "%s", pitem_prefix);
pctx_ptree = proto_item_add_subtree(pctx_pitem, ett_assoc_pctx);
pctx_id = tvb_get_guint8(tvb, offset);
pctx_result = tvb_get_guint8(tvb, 2 + offset);
pctx = dcm_state_pctx_get(assoc, pctx_id, TRUE);
if (pctx == NULL) {
return;
}
proto_tree_add_uint(pctx_ptree, hf_dcm_assoc_item_type, tvb, offset-4, 2, item_type);
proto_tree_add_uint(pctx_ptree, hf_dcm_assoc_item_len, tvb, offset-2, 2, item_len);
proto_tree_add_uint_format(pctx_ptree, hf_dcm_pctx_id, tvb, offset, 1, pctx_id, "Context ID: 0x%02x", pctx_id);
if (!is_assoc_request) {
switch (pctx_result) {
case 0: pctx_result_desc = "Accept"; break;
case 1: pctx_result_desc = "User Reject"; break;
case 2: pctx_result_desc = "No Reason"; break;
case 3: pctx_result_desc = "Abstract Syntax Unsupported"; break;
case 4: pctx_result_desc = "Transfer Syntax Unsupported"; break;
}
proto_tree_add_uint_format(pctx_ptree, hf_dcm_pctx_result, tvb, offset+2, 1,
pctx_result, "Result: %s (0x%x)", pctx_result_desc, pctx_result);
}
offset += 4;
while (offset < endpos) {
item_type = tvb_get_guint8(tvb, offset);
item_len = tvb_get_ntohs(tvb, 2 + offset);
offset += 4;
switch (item_type) {
case 0x30:
dissect_dcm_assoc_item(tvb, pctx_ptree, offset-4,
"Abstract Syntax: ", DCM_ITEM_VALUE_TYPE_UID, &pctx_abss_uid, &pctx_abss_desc,
&hf_dcm_assoc_item_type, &hf_dcm_assoc_item_len, &hf_dcm_pctx_abss_syntax, ett_assoc_pctx_abss);
cnt_abbs += 1;
offset += item_len;
break;
case 0x40:
dissect_dcm_assoc_item(tvb, pctx_ptree, offset-4,
"Transfer Syntax: ", DCM_ITEM_VALUE_TYPE_UID, &pctx_xfer_uid, &pctx_xfer_desc,
&hf_dcm_assoc_item_type, &hf_dcm_assoc_item_len, &hf_dcm_pctx_xfer_syntax, ett_assoc_pctx_xfer);
if (!is_assoc_request && pctx_result == 0) {
dcm_set_syntax(pctx, pctx_xfer_uid, pctx_xfer_desc);
}
cnt_xfer += 1;
offset += item_len;
break;
default:
offset += item_len;
break;
}
}
if (is_assoc_request) {
if (cnt_abbs<1) {
expert_add_info(pinfo, pctx_pitem, &ei_dcm_no_abstract_syntax);
return;
}
else if (cnt_abbs>1) {
expert_add_info(pinfo, pctx_pitem, &ei_dcm_multiple_abstract_syntax);
return;
}
if (cnt_xfer==0) {
expert_add_info(pinfo, pctx_pitem, &ei_dcm_no_transfer_syntax);
return;
}
if (pctx_abss_uid==NULL) {
expert_add_info(pinfo, pctx_pitem, &ei_dcm_no_abstract_syntax_uid);
return;
}
}
else {
if (cnt_xfer>1) {
expert_add_info(pinfo, pctx_pitem, &ei_dcm_multiple_transfer_syntax);
return;
}
}
if (pctx->abss_uid==NULL) {
pctx->abss_uid = wmem_strdup(wmem_file_scope(), pctx_abss_uid);
pctx->abss_desc = wmem_strdup(wmem_file_scope(), pctx_abss_desc);
}
if (is_assoc_request) {
if (pctx_abss_desc == NULL) {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s", pctx_abss_uid);
}
else {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s (%s)", pctx_abss_desc, pctx_abss_uid);
}
}
else
{
if (pctx_result==0) {
g_snprintf(buf_desc, MAX_BUF_LEN, "ID 0x%02x, %s, %s, %s",
pctx_id, pctx_result_desc,
dcm_uid_or_desc(pctx->xfer_uid, pctx->xfer_desc),
dcm_uid_or_desc(pctx->abss_uid, pctx->abss_desc));
}
else {
g_snprintf(buf_desc, MAX_BUF_LEN, "ID 0x%02x, %s, %s",
pctx_id, pctx_result_desc,
dcm_uid_or_desc(pctx->abss_uid, pctx->abss_desc));
}
}
proto_item_append_text(pctx_pitem, "%s", buf_desc);
}
static void
dissect_dcm_userinfo(tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint32 len, const gchar *pitem_prefix)
{
proto_item *userinfo_pitem = NULL;
proto_tree *userinfo_ptree = NULL;
guint8 item_type;
guint16 item_len;
gboolean first_item=TRUE;
gchar *info_max_pdu=NULL;
gchar *info_impl_uid=NULL;
gchar *info_impl_version=NULL;
const gchar *dummy=NULL;
guint32 endpos;
endpos = offset + len;
item_type = tvb_get_guint8(tvb, offset-4);
item_len = tvb_get_ntohs(tvb, offset-2);
userinfo_pitem = proto_tree_add_item(tree, hf_dcm_info, tvb, offset-4, item_len+4, ENC_NA);
proto_item_set_text(userinfo_pitem, "%s", pitem_prefix);
userinfo_ptree = proto_item_add_subtree(userinfo_pitem, ett_assoc_info);
proto_tree_add_uint(userinfo_ptree, hf_dcm_assoc_item_type, tvb, offset-4, 2, item_type);
proto_tree_add_uint(userinfo_ptree, hf_dcm_assoc_item_len, tvb, offset-2, 2, item_len);
while (offset < endpos) {
item_type = tvb_get_guint8(tvb, offset);
item_len = tvb_get_ntohs(tvb, 2 + offset);
offset += 4;
switch (item_type) {
case 0x51:
dissect_dcm_assoc_item(tvb, userinfo_ptree, offset-4,
"Max PDU Length: ", DCM_ITEM_VALUE_TYPE_UINT32, &info_max_pdu, &dummy,
&hf_dcm_assoc_item_type, &hf_dcm_assoc_item_len, &hf_dcm_pdu_maxlen, ett_assoc_info_uid);
if (!first_item) {
proto_item_append_text(userinfo_pitem, ", ");
}
proto_item_append_text(userinfo_pitem, "Max PDU Length %s", info_max_pdu);
first_item=FALSE;
offset += item_len;
break;
case 0x52:
dissect_dcm_assoc_item(tvb, userinfo_ptree, offset-4,
"Implementation UID: ", DCM_ITEM_VALUE_TYPE_STRING, &info_impl_uid, &dummy,
&hf_dcm_assoc_item_type, &hf_dcm_assoc_item_len, &hf_dcm_info_uid, ett_assoc_info_uid);
if (!first_item) {
proto_item_append_text(userinfo_pitem, ", ");
}
proto_item_append_text(userinfo_pitem, "Implementation UID %s", info_impl_uid);
first_item=FALSE;
offset += item_len;
break;
case 0x55:
dissect_dcm_assoc_item(tvb, userinfo_ptree, offset-4,
"Implementation Version: ", DCM_ITEM_VALUE_TYPE_STRING, &info_impl_version, &dummy,
&hf_dcm_assoc_item_type, &hf_dcm_assoc_item_len, &hf_dcm_info_version, ett_assoc_info_version);
if (!first_item) {
proto_item_append_text(userinfo_pitem, ", ");
}
proto_item_append_text(userinfo_pitem, "Version %s", info_impl_version);
first_item=FALSE;
offset += item_len;
break;
case 0x53:
dissect_dcm_assoc_async_negotiation(tvb, userinfo_ptree, offset-4);
offset += item_len;
break;
case 0x54:
dissect_dcm_assoc_role_selection(tvb, userinfo_ptree, offset-4);
offset += item_len;
break;
case 0x56:
dissect_dcm_assoc_sopclass_extneg(tvb, userinfo_ptree, offset-4);
offset += item_len;
break;
default:
offset += item_len;
break;
}
}
}
static guint32
dissect_dcm_assoc_detail(tvbuff_t *tvb, packet_info *pinfo, proto_item *ti,
dcm_state_assoc_t *assoc, guint32 offset, guint32 len)
{
proto_tree *assoc_tree = NULL;
guint8 item_type;
guint16 item_len;
guint32 endpos;
gchar *item_value = NULL;
const gchar *item_description = NULL;
endpos = offset + len;
assoc_tree = proto_item_add_subtree(ti, ett_assoc);
while (offset < endpos) {
item_type = tvb_get_guint8(tvb, offset);
item_len = tvb_get_ntohs(tvb, 2 + offset);
if (item_len == 0) {
expert_add_info(pinfo, ti, &ei_dcm_assoc_item_len);
return endpos;
}
offset += 4;
switch (item_type) {
case 0x10:
dissect_dcm_assoc_item(tvb, assoc_tree, offset-4,
"Application Context: ", DCM_ITEM_VALUE_TYPE_UID, &item_value, &item_description,
&hf_dcm_assoc_item_type, &hf_dcm_assoc_item_len, &hf_dcm_actx, ett_assoc_actx);
offset += item_len;
break;
case 0x20:
dissect_dcm_pctx(tvb, pinfo, assoc_tree, assoc, offset, item_len,
"Presentation Context: ", TRUE);
offset += item_len;
break;
case 0x21:
dissect_dcm_pctx(tvb, pinfo, assoc_tree, assoc, offset, item_len,
"Presentation Context: ", FALSE);
offset += item_len;
break;
case 0x50:
dissect_dcm_userinfo(tvb, assoc_tree, offset, item_len, "User Info: ");
offset += item_len;
break;
default:
offset += item_len;
break;
}
}
return offset;
}
static guint32
dissect_dcm_pdv_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dcm_state_assoc_t *assoc, guint32 offset, dcm_state_pdv_t **pdv)
{
proto_item *pdv_ctx_pitem = NULL;
proto_item *pdv_flags_pitem = NULL;
dcm_state_pctx_t *pctx = NULL;
dcm_state_pdv_t *pdv_first_data = NULL;
const gchar *desc_flag = NULL;
gchar *desc_header = NULL;
guint8 flags = 0;
guint8 pctx_id = 0;
pctx_id = tvb_get_guint8(tvb, offset);
pctx = dcm_state_pctx_get(assoc, pctx_id, FALSE);
if (pctx && pctx->xfer_uid) {
proto_tree_add_uint_format(tree, hf_dcm_pdv_ctx, tvb, offset, 1,
pctx_id, "Context: 0x%02x (%s, %s)", pctx_id,
dcm_uid_or_desc(pctx->xfer_uid, pctx->xfer_desc),
dcm_uid_or_desc(pctx->abss_uid, pctx->abss_desc));
}
else {
pdv_ctx_pitem=proto_tree_add_uint_format(tree, hf_dcm_pdv_ctx, tvb, offset, 1,
pctx_id, "Context: 0x%02x not found. A-ASSOCIATE request not found in capture.", pctx_id);
expert_add_info(pinfo, pdv_ctx_pitem, &ei_dcm_pdv_ctx);
if (pctx == NULL) {
pctx = dcm_state_pctx_new(assoc, pctx_id);
pctx->syntax = DCM_UNK;
}
}
offset +=1;
*pdv = dcm_state_pdv_get(pctx, pinfo->fd->num, tvb_raw_offset(tvb)+offset, TRUE);
if (*pdv == NULL) {
return 0;
}
flags = tvb_get_guint8(tvb, offset);
(*pdv)->pctx_id = pctx_id;
desc_header=(gchar *)wmem_alloc0(wmem_file_scope(), MAX_BUF_LEN);
switch (flags) {
case 0:
desc_flag = "Data, More Fragments";
(*pdv)->is_flagvalid = TRUE;
(*pdv)->is_command = FALSE;
(*pdv)->is_last_fragment = FALSE;
(*pdv)->syntax = pctx->syntax;
break;
case 2:
desc_flag = "Data, Last Fragment";
(*pdv)->is_flagvalid = TRUE;
(*pdv)->is_command = FALSE;
(*pdv)->is_last_fragment = TRUE;
(*pdv)->syntax = pctx->syntax;
break;
case 1:
desc_flag = "Command, More Fragments";
g_snprintf(desc_header, MAX_BUF_LEN, "Command");
(*pdv)->is_flagvalid = TRUE;
(*pdv)->is_command = TRUE;
(*pdv)->is_last_fragment = FALSE;
(*pdv)->syntax = DCM_ILE;
break;
case 3:
desc_flag = "Command, Last Fragment";
g_snprintf(desc_header, MAX_BUF_LEN, "Command");
(*pdv)->is_flagvalid = TRUE;
(*pdv)->is_command = TRUE;
(*pdv)->is_last_fragment = TRUE;
(*pdv)->syntax = DCM_ILE;
break;
default:
desc_flag = "Invalid Flags";
g_snprintf(desc_header, MAX_BUF_LEN, "Invalid Flags");
(*pdv)->is_flagvalid = FALSE;
(*pdv)->is_command = FALSE;
(*pdv)->is_last_fragment = FALSE;
(*pdv)->syntax = DCM_UNK;
}
if (flags == 0 || flags == 2) {
pdv_first_data = dcm_state_pdv_get_obj_start(*pdv);
if (pdv_first_data->prev && pdv_first_data->prev->is_command) {
if (pctx->abss_desc && g_str_has_suffix(pctx->abss_desc, "Storage")) {
if (flags == 0) {
g_snprintf(desc_header, MAX_BUF_LEN, "%s Fragment", pctx->abss_desc);
}
else {
g_snprintf(desc_header, MAX_BUF_LEN, "%s", pctx->abss_desc);
}
(*pdv)->is_storage = TRUE;
}
else {
g_snprintf(desc_header, MAX_BUF_LEN, "%s-DATA", pdv_first_data->prev->desc);
}
}
else {
g_snprintf(desc_header, MAX_BUF_LEN, "DATA");
}
}
(*pdv)->desc = desc_header;
pdv_flags_pitem = proto_tree_add_uint_format(tree, hf_dcm_pdv_flags, tvb, offset, 1,
flags, "Flags: 0x%02x (%s)", flags, desc_flag);
if (flags>3) {
expert_add_info(pinfo, pdv_flags_pitem, &ei_dcm_pdv_flags);
}
offset +=1;
return offset;
}
static guint32
dissect_dcm_tag_value(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, dcm_state_pdv_t *pdv,
guint32 offset, guint16 grp, guint16 elm,
guint32 vl, guint32 vl_max, const gchar* vr, gchar **tag_value)
{
proto_item *pitem = NULL;
gboolean is_little_endian;
if (pdv->syntax == DCM_EBE) is_little_endian = FALSE;
else is_little_endian = TRUE;
if ((strncmp(vr, "AE", 2) == 0) || (strncmp(vr, "AS", 2) == 0) || (strncmp(vr, "CS", 2) == 0) ||
(strncmp(vr, "DA", 2) == 0) || (strncmp(vr, "DS", 2) == 0) || (strncmp(vr, "DT", 2) == 0) ||
(strncmp(vr, "IS", 2) == 0) || (strncmp(vr, "LO", 2) == 0) || (strncmp(vr, "LT", 2) == 0) ||
(strncmp(vr, "PN", 2) == 0) || (strncmp(vr, "SH", 2) == 0) || (strncmp(vr, "ST", 2) == 0) ||
(strncmp(vr, "TM", 2) == 0) || (strncmp(vr, "UI", 2) == 0) || (strncmp(vr, "UT", 2) == 0) ) {
gchar *vals;
dcm_uid_t *uid = NULL;
guint8 val8;
val8 = tvb_get_guint8(tvb, offset + vl_max - 1);
if (val8 == 0x00) {
vals = tvb_format_text(tvb, offset, vl_max - 1);
}
else {
vals = tvb_format_text(tvb, offset, vl_max);
}
if ((strncmp(vr, "UI", 2) == 0)) {
uid = (dcm_uid_t *)g_hash_table_lookup(dcm_uid_table, (gpointer) vals);
if (uid) {
g_snprintf(*tag_value, MAX_BUF_LEN, "%s (%s)", vals, uid->name);
}
else {
g_snprintf(*tag_value, MAX_BUF_LEN, "%s", vals);
}
}
else {
if (strlen(vals) > 50) {
g_snprintf(*tag_value, MAX_BUF_LEN, "%-50.50s...", vals);
}
else {
g_snprintf(*tag_value, MAX_BUF_LEN, "%s", vals);
}
}
proto_tree_add_string_format(tree, hf_dcm_tag_value_str, tvb, offset, vl_max, *tag_value, "%-8.8s%s", "Value:", *tag_value);
if (grp == 0x0000 && elm == 0x0902) {
pdv->comment = wmem_strdup(wmem_file_scope(), g_strstrip(vals));
}
}
else if ((strncmp(vr, "OB", 2) == 0) || (strncmp(vr, "OF", 2) == 0) ||
(strncmp(vr, "OW", 2) == 0)) {
proto_tree_add_bytes_format(tree, hf_dcm_tag_value_byte, tvb, offset, vl_max,
NULL, "%-8.8s%s", "Value:", "(binary)");
g_snprintf(*tag_value, MAX_BUF_LEN, "(binary)");
}
else if (strncmp(vr, "UN", 2) == 0) {
guint8 val8;
gchar *vals;
guint32 i;
gboolean is_string = TRUE;
gboolean is_padded = FALSE;
for (i = 0; i < vl_max ; i++) {
val8 = tvb_get_guint8(tvb, offset + i);
if ((val8 == 0x09) || (val8 == 0x0A) || (val8 == 0x0D)) {
}
else if ((val8 >= 0x20) && (val8 <= 0x7E)) {
}
else if ((i == vl_max -1) && (val8 == 0x00)) {
is_padded = TRUE;
}
else {
is_string = FALSE;
}
}
if (is_string) {
vals = tvb_format_text(tvb, offset, (is_padded ? vl_max - 1 : vl_max));
proto_tree_add_string_format(tree, hf_dcm_tag_value_str, tvb, offset, vl_max,
vals, "%-8.8s%s", "Value:", vals);
g_snprintf(*tag_value, MAX_BUF_LEN, "%s", vals);
}
else {
proto_tree_add_bytes_format(tree, hf_dcm_tag_value_byte, tvb, offset, vl_max,
NULL, "%-8.8s%s", "Value:", "(binary)");
g_snprintf(*tag_value, MAX_BUF_LEN, "(binary)");
}
}
else if (strncmp(vr, "AT", 2) == 0) {
guint16 at_grp;
guint16 at_elm;
if (is_little_endian) at_grp = tvb_get_letohs(tvb, offset);
else at_grp = tvb_get_ntohs(tvb, offset);
if (is_little_endian) at_elm = tvb_get_letohs(tvb, offset);
else at_elm = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_dcm_tag_value_32u, tvb, offset, 4,
(at_grp << 16) | at_elm, "%-8.8s%04x,%04x", "Value:", at_grp, at_elm);
g_snprintf(*tag_value, MAX_BUF_LEN, "(%04x,%04x)", at_grp, at_elm);
}
else if (strncmp(vr, "FL", 2) == 0) {
gfloat valf;
if (is_little_endian) valf = tvb_get_letohieee_float(tvb, offset);
else valf = tvb_get_ntohieee_float(tvb, offset);
proto_tree_add_bytes_format(tree, hf_dcm_tag_value_byte, tvb, offset, 4,
NULL, "%-8.8s%f", "Value:", valf);
g_snprintf(*tag_value, MAX_BUF_LEN, "%f", valf);
}
else if (strncmp(vr, "FD", 2) == 0) {
gdouble vald;
if (is_little_endian) vald = tvb_get_letohieee_double(tvb, offset);
else vald = tvb_get_ntohieee_double(tvb, offset);
proto_tree_add_bytes_format(tree, hf_dcm_tag_value_byte, tvb, offset, 8,
NULL, "%-8.8s%f", "Value:", vald);
g_snprintf(*tag_value, MAX_BUF_LEN, "%f", vald);
}
else if (strncmp(vr, "SL", 2) == 0) {
gint32 val32;
if (is_little_endian) val32 = tvb_get_letohl(tvb, offset);
else val32 = tvb_get_ntohl(tvb, offset);
proto_tree_add_int_format(tree, hf_dcm_tag_value_32s, tvb, offset, 4,
val32, "%-8.8s%d", "Value:", val32);
g_snprintf(*tag_value, MAX_BUF_LEN, "%d", val32);
}
else if (strncmp(vr, "SS", 2) == 0) {
gint16 val16;
if (is_little_endian) val16 = tvb_get_letohs(tvb, offset);
else val16 = tvb_get_ntohs(tvb, offset);
proto_tree_add_int_format(tree, hf_dcm_tag_value_16s, tvb, offset, 2,
val16, "%-8.8s%d", "Value:", val16);
g_snprintf(*tag_value, MAX_BUF_LEN, "%d", val16);
}
else if (strncmp(vr, "UL", 2) == 0) {
guint32 val32;
if (is_little_endian) val32 = tvb_get_letohl(tvb, offset);
else val32 = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint_format(tree, hf_dcm_tag_value_32u, tvb, offset, 4,
val32, "%-8.8s%u", "Value:", val32);
g_snprintf(*tag_value, MAX_BUF_LEN, "%u", val32);
}
else if (strncmp(vr, "US", 2) == 0) {
const gchar *status_message = NULL;
guint16 val16;
if (is_little_endian) val16 = tvb_get_letohs(tvb, offset);
else val16 = tvb_get_ntohs(tvb, offset);
if (grp == 0x0000 && elm == 0x0100) {
g_snprintf(*tag_value, MAX_BUF_LEN, "%s", dcm_cmd2str(val16));
pdv->command = wmem_strdup(wmem_file_scope(), *tag_value);
}
else if (grp == 0x0000 && elm == 0x0900) {
status_message = dcm_rsp2str(val16);
g_snprintf(*tag_value, MAX_BUF_LEN, "%s (0x%02x)", status_message, val16);
if (val16 != 0x0000 && ((val16 & 0xFF00) != 0xFF00)) {
pdv->is_warning = TRUE;
}
pdv->status = wmem_strdup(wmem_file_scope(), status_message);
}
else {
g_snprintf(*tag_value, MAX_BUF_LEN, "%u", val16);
}
if (grp == 0x0000) {
if (elm == 0x0110) {
pdv->message_id = val16;
}
else if (elm == 0x0120) {
pdv->message_id_resp = val16;
}
else if (elm == 0x1020) {
pdv->no_remaining = val16;
}
else if (elm == 0x1021) {
pdv->no_completed = val16;
}
else if (elm == 0x1022) {
pdv->no_failed = val16;
}
else if (elm == 0x1023) {
pdv->no_warning = val16;
}
}
pitem = proto_tree_add_uint_format(tree, hf_dcm_tag_value_16u, tvb, offset, 2,
val16, "%-8.8s%s", "Value:", *tag_value);
if (pdv->is_warning && status_message) {
expert_add_info(pinfo, pitem, &ei_dcm_status_msg);
}
}
else {
proto_tree_add_bytes_format(tree, hf_dcm_tag_value_byte, tvb, offset, vl_max,
NULL, "%-8.8s%s", "Value:", (vl > vl_max ? "" : "(unknown VR)"));
g_snprintf(*tag_value, MAX_BUF_LEN, "(unknown VR)");
}
offset += vl_max;
return offset;
}
static gboolean
dcm_tag_is_open(dcm_state_pdv_t *pdv, guint32 startpos, guint32 offset, guint32 endpos, guint32 size_required)
{
if (offset + size_required > endpos) {
pdv->open_tag.is_header_fragmented = TRUE;
pdv->open_tag.len_decoded = endpos - startpos;
return TRUE;
}
else {
return FALSE;
}
}
static dcm_tag_t*
dcm_tag_lookup(guint16 grp, guint16 elm)
{
static dcm_tag_t *tag_def = NULL;
static dcm_tag_t tag_unknown = { 0x00000000, "(unknown)", "UN", "1", 0, 0};
static dcm_tag_t tag_private = { 0x00000000, "Private Tag", "UN", "1", 0, 0 };
static dcm_tag_t tag_private_grp_len = { 0x00000000, "Private Tag Group Length", "UL", "1", 0, 0 };
static dcm_tag_t tag_grp_length = { 0x00000000, "Group Length", "UL", "1", 0, 0 };
tag_def = (dcm_tag_t *)g_hash_table_lookup(dcm_tag_table, GUINT_TO_POINTER((grp << 16) | elm));
if (tag_def == NULL) {
if ((grp & 0x0001) && (elm == 0x0000)) {
tag_def = &tag_private_grp_len;
}
else if (grp & 0x0001) {
tag_def = &tag_private;
}
else if (elm == 0x0000) {
tag_def = &tag_grp_length;
}
else if (((grp & 0xFF00) == 0x5000) || ((grp & 0xFF00) == 0x6000) || ((grp & 0xFF00) == 0x7F00)) {
tag_def = (dcm_tag_t *)g_hash_table_lookup(dcm_tag_table, GUINT_TO_POINTER(((grp & 0xFF00) << 16) | elm));
}
else if ((grp == 0x0020) && ((elm & 0xFF00) == 0x3100)) {
tag_def = (dcm_tag_t *)g_hash_table_lookup(dcm_tag_table, GUINT_TO_POINTER((grp << 16) | (elm & 0xFF00)));
}
else if ((grp == 0x0028) && ((elm & 0xFF00) == 0x0400)) {
tag_def = (dcm_tag_t *)g_hash_table_lookup(dcm_tag_table, GUINT_TO_POINTER((grp << 16) | (elm & 0xFF0F) | 0x0010));
}
else if ((grp == 0x0028) && ((elm & 0xFF00) == 0x0800)) {
tag_def = (dcm_tag_t *)g_hash_table_lookup(dcm_tag_table, GUINT_TO_POINTER((grp << 16) | (elm & 0xFF0F)));
}
else if (grp == 0x1000) {
tag_def = (dcm_tag_t *)g_hash_table_lookup(dcm_tag_table, GUINT_TO_POINTER((grp << 16) | (elm & 0x000F)));
}
else if (grp == 0x1010) {
tag_def = (dcm_tag_t *)g_hash_table_lookup(dcm_tag_table, GUINT_TO_POINTER((grp << 16) | (elm & 0x0000)));
}
if (tag_def == NULL) {
tag_def = &tag_unknown;
}
}
return tag_def;
}
static gchar*
dcm_tag_summary(guint16 grp, guint16 elm, guint32 vl, const gchar *tag_desc, const gchar *vr,
gboolean is_retired, gboolean is_implicit)
{
gchar *desc_mod;
gchar *tag_vl;
gchar *tag_sum;
if (is_retired) {
desc_mod = wmem_strdup_printf(wmem_packet_scope(), "(Retired) %-35.35s", tag_desc);
}
else {
desc_mod = wmem_strdup_printf(wmem_packet_scope(), "%-45.45s", tag_desc);
}
if (vl == 0xFFFFFFFF) {
tag_vl = wmem_strdup_printf(wmem_packet_scope(), "%10.10s", "<udef>");
}
else {
tag_vl = wmem_strdup_printf(wmem_packet_scope(), "%10u", vl);
}
if (is_implicit) tag_sum = wmem_strdup_printf(wmem_packet_scope(), "(%04x,%04x) %s %s", grp, elm, tag_vl, desc_mod);
else tag_sum = wmem_strdup_printf(wmem_packet_scope(), "(%04x,%04x) %s %s [%s]", grp, elm, tag_vl, desc_mod, vr);
return tag_sum;
}
static guint32
dissect_dcm_tag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dcm_state_pdv_t *pdv, guint32 offset, guint32 endpos,
gboolean is_first_tag, const gchar **tag_description,
gboolean *end_of_seq_or_item)
{
proto_tree *tag_ptree = NULL;
proto_tree *seq_ptree = NULL;
proto_item *tag_pitem = NULL;
dcm_tag_t *tag_def = NULL;
const gchar *vr = NULL;
gchar *tag_value = NULL;
gchar *tag_summary;
guint32 vl = 0;
guint16 vl_1 = 0;
guint16 vl_2 = 0;
guint32 offset_tag = 0;
guint32 offset_vr = 0;
guint32 offset_vl = 0;
guint32 vl_max = 0;
guint16 grp = 0;
guint16 elm = 0;
guint32 len_decoded_remaing = 0;
gboolean is_little_endian = FALSE;
gboolean is_implicit = FALSE;
gboolean is_vl_long = FALSE;
gboolean is_sequence = FALSE;
gboolean is_item = FALSE;
*tag_description = NULL;
tag_value = (gchar *)wmem_alloc0(wmem_packet_scope(), MAX_BUF_LEN);
if (pdv->syntax == DCM_EBE) is_little_endian = FALSE;
else is_little_endian = TRUE;
if (pdv->syntax == DCM_ILE) is_implicit = TRUE;
else is_implicit = FALSE;
offset_tag = offset;
if (pdv->prev && is_first_tag) {
len_decoded_remaing = pdv->prev->open_tag.len_decoded;
}
if (len_decoded_remaing >= 2) {
grp = pdv->prev->open_tag.grp;
len_decoded_remaing -= 2;
}
else {
if (dcm_tag_is_open(pdv, offset_tag, offset, endpos, 2)) return endpos;
if (is_little_endian) grp = tvb_get_letohs(tvb, offset);
else grp = tvb_get_ntohs (tvb, offset);
offset += 2;
pdv->open_tag.grp = grp;
}
if (len_decoded_remaing >= 2) {
elm = pdv->prev->open_tag.elm;
len_decoded_remaing -= 2;
}
else {
if (dcm_tag_is_open(pdv, offset_tag, offset, endpos, 2)) return endpos;
if (is_little_endian) elm = tvb_get_letohs(tvb, offset);
else elm = tvb_get_ntohs (tvb, offset);
offset += 2;
pdv->open_tag.elm = elm;
}
tag_def = dcm_tag_lookup(grp, elm);
offset_vr = offset;
if ((grp == 0xFFFE) && (elm == 0xE000 || elm == 0xE00D || elm == 0xE0DD)) {
vr = "UL";
is_vl_long = TRUE;
}
else if (is_implicit) {
vr = wmem_strdup(wmem_packet_scope(), tag_def->vr);
is_vl_long = TRUE;
}
else {
if (len_decoded_remaing >= 2) {
vr = wmem_strdup(wmem_packet_scope(), pdv->prev->open_tag.vr);
len_decoded_remaing -= 2;
}
else {
if (dcm_tag_is_open(pdv, offset_tag, offset_vr, endpos, 2)) return endpos;
vr = (gchar *)tvb_get_string(wmem_packet_scope(), tvb, offset, 2);
offset += 2;
g_free(pdv->open_tag.vr);
pdv->open_tag.vr = g_strdup(vr);
}
if ((strcmp(vr, "OB") == 0) || (strcmp(vr, "OW") == 0) || (strcmp(vr, "OF") == 0) ||
(strcmp(vr, "SQ") == 0) || (strcmp(vr, "UT") == 0) || (strcmp(vr, "UN") == 0)) {
is_vl_long = TRUE;
if (len_decoded_remaing >= 2) {
len_decoded_remaing -= 2;
}
else {
if (dcm_tag_is_open(pdv, offset_tag, offset_vr, endpos, 2)) return endpos;
offset += 2;
}
}
else {
is_vl_long = FALSE;
}
}
offset_vl = offset;
if (len_decoded_remaing >= 2) {
vl_1 = pdv->prev->open_tag.vl_1;
len_decoded_remaing -= 2;
}
else {
if (dcm_tag_is_open(pdv, offset_tag, offset_vl, endpos, 2)) return endpos;
if (is_little_endian) vl_1 = tvb_get_letohs(tvb, offset);
else vl_1 = tvb_get_ntohs(tvb, offset);
offset += 2;
pdv->open_tag.vl_1 = vl_1;
}
if (is_vl_long) {
if (len_decoded_remaing >= 2) {
vl_2 = pdv->prev->open_tag.vl_2;
}
else {
if (dcm_tag_is_open(pdv, offset_tag, offset_vl+2, endpos, 2)) return endpos;
if (is_little_endian) vl_2 = tvb_get_letohs(tvb, offset);
else vl_2 = tvb_get_ntohs(tvb, offset);
offset += 2;
pdv->open_tag.vl_2 = vl_2;
}
if (is_little_endian) vl = (vl_2 << 16) + vl_1;
else vl = (vl_1 << 16) + vl_2;
}
else {
vl = vl_1;
}
tag_summary = dcm_tag_summary(grp, elm, vl, tag_def->description, vr, tag_def->is_retired, is_implicit);
if (vl == 0xFFFFFFFF) {
tag_pitem = proto_tree_add_text(tree, tvb, offset_tag, offset - offset_tag, "%s", tag_summary);
vl_max = 0;
}
else if (offset + vl <= endpos) {
tag_pitem = proto_tree_add_text(tree, tvb, offset_tag, offset + vl - offset_tag, "%s", tag_summary);
vl_max = vl;
}
else {
tag_pitem = proto_tree_add_text(tree, tvb, offset_tag, endpos - offset_tag, "%s", tag_summary);
vl_max = endpos - offset;
}
is_sequence = (strcmp(vr, "SQ") == 0) || (vl == 0xFFFFFFFF);
is_item = ((grp == 0xFFFE) && (elm == 0xE000));
if (is_sequence | is_item) {
if (global_dcm_seq_subtree) {
seq_ptree = proto_item_add_subtree(tag_pitem, (is_sequence ? ett_dcm_data_seq : ett_dcm_data_item));
if (global_dcm_tag_subtree) tag_ptree = seq_ptree;
else tag_ptree = NULL;
}
else {
seq_ptree = tree;
if (global_dcm_tag_subtree) {
tag_ptree = proto_item_add_subtree(tag_pitem, ett_dcm_data_tag);
}
else {
tag_ptree = NULL;
}
}
}
else {
if (global_dcm_tag_subtree) {
tag_ptree = proto_item_add_subtree(tag_pitem, ett_dcm_data_tag);
}
else {
tag_ptree = NULL;
}
}
proto_tree_add_uint_format_value(tag_ptree, hf_dcm_tag, tvb, offset_tag, 4,
(grp << 16) | elm, "%04x,%04x (%s)", grp, elm, tag_def->description);
if (!is_item) {
if (is_implicit) {
proto_tree_add_string_format(tag_ptree, hf_dcm_tag_vr, tvb, offset_tag, 4, vr, "%-8.8s%s", "VR:", vr);
}
else {
proto_tree_add_string_format(tag_ptree, hf_dcm_tag_vr, tvb, offset_vr, 2, vr, "%-8.8s%s", "VR:", vr);
}
}
proto_tree_add_uint_format(tag_ptree, hf_dcm_tag_vl, tvb, offset_vl, (is_vl_long ? 4 : 2), vl, "%-8.8s%u", "Length:", vl);
if ((is_sequence || is_item) && (vl > 0)) {
guint32 endpos_item = 0;
gboolean local_end_of_seq_or_item = FALSE;
gboolean is_first_desc = TRUE;
const gchar *item_description = NULL;
if (vl == 0xFFFFFFFF) {
while ((!local_end_of_seq_or_item) && (!pdv->open_tag.is_header_fragmented) && (offset < endpos)) {
offset = dissect_dcm_tag(tvb, pinfo, seq_ptree, pdv, offset, endpos, FALSE,
&item_description, &local_end_of_seq_or_item);
if (item_description && global_dcm_seq_subtree) {
proto_item_append_text(tag_pitem, (is_first_desc ? " %s" : ", %s"), item_description);
is_first_desc = FALSE;
}
}
}
else {
endpos_item = offset + vl_max;
while (offset < endpos_item) {
offset = dissect_dcm_tag(tvb, pinfo, seq_ptree, pdv, offset, endpos_item, FALSE,
&item_description, &local_end_of_seq_or_item);
if (item_description && global_dcm_seq_subtree) {
proto_item_append_text(tag_pitem, (is_first_desc ? " %s" : ", %s"), item_description);
is_first_desc = FALSE;
}
}
}
}
else if ((grp == 0xFFFE) && (elm == 0xE00D)) {
*end_of_seq_or_item = TRUE;
}
else if ((grp == 0xFFFE) && (elm == 0xE0DD)) {
*end_of_seq_or_item = TRUE;
}
else if (vl == 0) {
g_strlcpy(tag_value, "<Empty>", MAX_BUF_LEN);
}
else if (vl > vl_max) {
gchar *tag_desc;
proto_tree_add_bytes_format(tag_ptree, hf_dcm_tag_value_byte, tvb, offset, vl_max,
NULL, "%-8.8sBytes %d - %d [start]", "Value:", 1, vl_max);
g_snprintf(tag_value, MAX_BUF_LEN, "<Bytes %d - %d, start>", 1, vl_max);
offset += vl_max;
tag_desc = dcm_tag_summary(grp, elm, vl, tag_def->description, vr, tag_def->is_retired, is_implicit);
if (pdv->open_tag.desc == NULL) {
pdv->open_tag.is_value_fragmented = TRUE;
pdv->open_tag.desc = wmem_strdup(wmem_file_scope(), tag_desc);
pdv->open_tag.len_total = vl;
pdv->open_tag.len_remaining = vl - vl_max;
}
}
else {
offset = dissect_dcm_tag_value(tvb, pinfo, tag_ptree, pdv, offset, grp, elm, vl, vl_max, vr, &tag_value);
if (grp == 0x0008 && elm == 0x0016) {
dcm_state_pdv_get_obj_start(pdv)->sop_class_uid = wmem_strdup(wmem_file_scope(), tag_value);
}
else if (grp == 0x0008 && elm == 0x0018) {
dcm_state_pdv_get_obj_start(pdv)->sop_instance_uid = wmem_strdup(wmem_file_scope(), tag_value);
}
else if (grp == 0x0000 && elm == 0x0100) {
pdv->desc = wmem_strdup(wmem_file_scope(), tag_value);
}
}
proto_item_append_text(tag_pitem, " %s", tag_value);
if (tag_def->add_to_summary) {
*tag_description = wmem_strdup(wmem_packet_scope(), g_strstrip(tag_value));
}
return offset;
}
static guint32
dissect_dcm_tag_open(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dcm_state_pdv_t *pdv, guint32 offset, guint32 endpos, gboolean *is_first_tag)
{
proto_item *pitem = NULL;
guint32 tag_value_fragment_len = 0;
if ((pdv->prev) && (pdv->prev->open_tag.len_remaining > 0)) {
if (endpos - offset >= pdv->prev->open_tag.len_remaining) {
tag_value_fragment_len = pdv->prev->open_tag.len_remaining;
pdv->is_corrupt = FALSE;
}
else if (pdv->is_flagvalid && pdv->is_last_fragment) {
tag_value_fragment_len = endpos - offset;
pdv->is_corrupt = TRUE;
}
else {
tag_value_fragment_len = endpos - offset;
if (!pdv->open_tag.is_value_fragmented) {
pdv->open_tag.is_value_fragmented = TRUE;
pdv->open_tag.len_total = pdv->prev->open_tag.len_total;
pdv->open_tag.len_remaining = pdv->prev->open_tag.len_remaining - tag_value_fragment_len;
pdv->open_tag.desc = wmem_strdup(wmem_file_scope(), pdv->prev->open_tag.desc);
}
pdv->is_corrupt = FALSE;
}
if (pdv->is_corrupt) {
pitem = proto_tree_add_bytes_format(tree, hf_dcm_data_tag, tvb,
offset, tag_value_fragment_len, NULL,
"%s <incomplete>", pdv->prev->open_tag.desc);
expert_add_info(pinfo, pitem, &ei_dcm_data_tag);
}
else {
proto_tree_add_bytes_format(tree, hf_dcm_data_tag, tvb,
offset, tag_value_fragment_len, NULL,
"%s <Bytes %d - %d, %s>", pdv->prev->open_tag.desc,
pdv->prev->open_tag.len_total - pdv->prev->open_tag.len_remaining + 1,
pdv->prev->open_tag.len_total - pdv->prev->open_tag.len_remaining + tag_value_fragment_len,
(pdv->prev->open_tag.len_remaining > tag_value_fragment_len ? "continuation" : "end") );
}
offset += tag_value_fragment_len;
*is_first_tag = FALSE;
}
return offset;
}
static guint32
dissect_dcm_pdv_body(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dcm_state_pdv_t *pdv, guint32 offset, guint32 pdv_body_len,
gchar **pdv_description)
{
const gchar *tag_value = NULL;
gboolean dummy = FALSE;
guint32 endpos = 0;
endpos = offset + pdv_body_len;
if (pdv->syntax == DCM_UNK) {
proto_tree_add_bytes_format(tree, hf_dcm_data_tag, tvb,
offset, pdv_body_len, NULL,
"(%04x,%04x) %-8x Unparsed data", 0, 0, pdv_body_len);
}
else {
gboolean is_first_tag = TRUE;
offset = dissect_dcm_tag_open(tvb, pinfo, tree, pdv, offset, endpos, &is_first_tag);
while (offset < endpos) {
offset = dissect_dcm_tag(tvb, pinfo, tree, pdv, offset, endpos, is_first_tag, &tag_value, &dummy);
is_first_tag = FALSE;
}
}
if (pdv->is_command) {
*pdv_description = (gchar *)wmem_alloc0(wmem_file_scope(), MAX_BUF_LEN);
if (pdv->is_warning) {
if (pdv->comment) {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s (%s, %s)", pdv->desc, pdv->status, pdv->comment);
}
else {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s (%s)", pdv->desc, pdv->status);
}
}
else if (global_dcm_cmd_details) {
if (pdv->message_id > 0) {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s ID=%d", pdv->desc, pdv->message_id);
}
else if (pdv->message_id_resp > 0) {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s ID=%d", pdv->desc, pdv->message_id_resp);
if (pdv->no_completed > 0) {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s C=%d", *pdv_description, pdv->no_completed);
}
if (pdv->no_remaining > 0) {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s R=%d", *pdv_description, pdv->no_remaining);
}
if (pdv->no_warning > 0) {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s W=%d", *pdv_description, pdv->no_warning);
}
if (pdv->no_failed > 0) {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s F=%d", *pdv_description, pdv->no_failed);
}
}
else {
*pdv_description = pdv->desc;
}
}
else {
*pdv_description = pdv->desc;
}
}
else {
*pdv_description = pdv->desc;
}
return endpos;
}
static guint32
dissect_dcm_pdv_fragmented(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dcm_state_assoc_t *assoc, guint32 offset, guint32 pdv_len, gchar **pdv_description)
{
conversation_t *conv=NULL;
dcm_state_pdv_t *pdv = NULL;
tvbuff_t *next_tvb = NULL;
fragment_head *head = NULL;
guint32 reassembly_id;
guint32 pdv_body_len;
guint32 startpos;
startpos = offset;
pdv_body_len = pdv_len-2;
offset = dissect_dcm_pdv_header(tvb, pinfo, tree, assoc, offset, &pdv);
if (global_dcm_reassemble)
{
conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
reassembly_id = (((conv->index) & 0x00FFFFFF) << 8) + pdv->pctx_id;
head = fragment_add_seq_next(&dcm_pdv_reassembly_table,
tvb, offset, pinfo, reassembly_id, NULL,
pdv_body_len,
!(pdv->is_last_fragment));
if (head && (head->next == NULL)) {
offset = dissect_dcm_pdv_body(tvb, pinfo, tree, pdv, offset, pdv_body_len, pdv_description);
}
else {
next_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled PDV", head,
&dcm_pdv_fragment_items, NULL, tree);
if (next_tvb == NULL) {
*pdv_description = (gchar *)wmem_alloc0(wmem_file_scope(), MAX_BUF_LEN);
if (head && head->reassembled_in != pinfo->fd->num) {
if (pdv->desc) {
g_snprintf(*pdv_description, MAX_BUF_LEN, "%s (reassembled in #%u)", pdv->desc, head->reassembled_in);
}
else {
g_snprintf(*pdv_description, MAX_BUF_LEN, "PDV Fragment (reassembled in #%u)", head->reassembled_in);
}
}
else {
g_snprintf(*pdv_description, MAX_BUF_LEN, "PDV Fragment");
}
offset += pdv_body_len;
}
else {
guint next_tvb_length = tvb_length(next_tvb);
if (tree || have_tap_listener(dicom_eo_tap)) {
offset += dissect_dcm_pdv_body(next_tvb, pinfo, tree, pdv, 0, next_tvb_length, pdv_description);
}
if (have_tap_listener(dicom_eo_tap)) {
pdv->data = g_malloc(next_tvb_length);
tvb_memcpy(next_tvb, pdv->data, 0, next_tvb_length);
pdv->data_len = next_tvb_length;
dcm_export_create_object(pinfo, assoc, pdv);
}
}
}
}
else if (tree) {
offset = dissect_dcm_pdv_body(tvb, pinfo, tree, pdv, offset, pdv_body_len, pdv_description);
if (have_tap_listener(dicom_eo_tap)) {
pdv->data = g_malloc(pdv_body_len);
tvb_memcpy(tvb, pdv->data, startpos, pdv_body_len);
pdv->data_len = pdv_body_len;
if ((pdv_body_len > 0) && (pdv->is_last_fragment)) {
dcm_export_create_object(pinfo, assoc, pdv);
}
}
}
return offset;
}
static guint32
dissect_dcm_pdu_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dcm_state_assoc_t *assoc, guint32 offset, guint32 pdu_len, gchar **pdu_data_description)
{
proto_tree *pdv_ptree;
proto_item *pdv_pitem, *pdvlen_item;
gchar *buf_desc = NULL;
gchar *pdv_description = NULL;
gboolean first_pdv = TRUE;
guint32 endpos = 0;
guint32 pdv_len = 0;
endpos = offset + pdu_len;
buf_desc=(gchar *)wmem_alloc0(wmem_file_scope(), MAX_BUF_LEN);
while (offset < endpos) {
pdv_len = tvb_get_ntohl(tvb, offset);
pdv_pitem = proto_tree_add_text(tree, tvb, offset, pdv_len+4, "PDV");
pdv_ptree = proto_item_add_subtree(pdv_pitem, ett_dcm_data_pdv);
pdvlen_item = proto_tree_add_item(pdv_ptree, hf_dcm_pdv_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (pdv_len + 4 > pdu_len) {
expert_add_info_format(pinfo, pdvlen_item, &ei_dcm_pdv_len, "Invalid PDV length (too large)");
return endpos;
}
else if (pdv_len <= 2) {
expert_add_info_format(pinfo, pdvlen_item, &ei_dcm_pdv_len, "Invalid PDV length (too small)");
return endpos;
}
else if (((pdv_len >> 1) << 1) != pdv_len) {
expert_add_info_format(pinfo, pdvlen_item, &ei_dcm_pdv_len, "Invalid PDV length (not even)");
return endpos;
}
offset = dissect_dcm_pdv_fragmented(tvb, pinfo, pdv_ptree, assoc, offset, pdv_len, &pdv_description);
if (pdv_description) {
if (first_pdv) {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s", pdv_description);
}
else {
g_snprintf(buf_desc, MAX_BUF_LEN, "%s, %s", buf_desc, pdv_description);
}
}
proto_item_append_text(pdv_pitem, ", %s", pdv_description);
first_pdv=FALSE;
}
*pdu_data_description = buf_desc;
return offset;
}
static int
dissect_dcm_main(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean is_port_static)
{
guint8 pdu_type = 0;
guint32 pdu_start = 0;
guint32 pdu_len = 0;
guint16 vers = 0;
guint32 tlen = 0;
int offset = 0;
tlen = tvb_reported_length(tvb);
pdu_type = tvb_get_guint8(tvb, 0);
if (pdu_type == 0 || pdu_type > 7)
return 0;
if (is_port_static) {
if (tlen < 6) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return TRUE;
}
}
else {
if (tlen < 10) {
return 0;
}
pdu_len = tvb_get_ntohl(tvb, 2);
vers = tvb_get_ntohs(tvb, 6);
if (!(pdu_type == 1 && vers == 1)) {
return 0;
}
if (pdu_len+6 < tlen) {
return 0;
}
}
pdu_len = tvb_get_ntohl(tvb, 2);
if (pdu_len < 4)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DICOM");
while (pdu_start < tlen) {
guint32 old_pdu_start;
if ((pdu_len+6) > (tlen-offset)) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = (pdu_len+6) - (tlen-offset);
return TRUE;
}
offset=dissect_dcm_pdu(tvb, pinfo, tree, pdu_start);
old_pdu_start = pdu_start;
pdu_start = pdu_start + pdu_len + 6;
if (pdu_start <= old_pdu_start) {
expert_add_info_format(pinfo, NULL, &ei_dcm_invalid_pdu_length, "Invalid PDU length (%u)", pdu_len);
THROW(ReportedBoundsError);
}
if (pdu_start < tlen - 6) {
pdu_len = tvb_get_ntohl(tvb, pdu_start+2);
}
else {
pdu_len = 0;
}
}
return offset;
}
static int
dissect_dcm_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_dcm_main(tvb, pinfo, tree, TRUE);
}
static int
dissect_dcm_heuristic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_dcm_main(tvb, pinfo, tree, FALSE);
}
static guint32
dissect_dcm_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset)
{
proto_tree *dcm_ptree=NULL;
proto_item *dcm_pitem=NULL;
dcm_state_t *dcm_data=NULL;
dcm_state_assoc_t *assoc=NULL;
guint8 pdu_type=0;
guint32 pdu_len=0;
gchar *pdu_data_description=NULL;
dcm_data = dcm_state_get(pinfo, TRUE);
if (dcm_data == NULL) {
return offset;
}
dcm_pitem = proto_tree_add_item(tree, proto_dcm, tvb, offset, -1, ENC_NA);
dcm_ptree = proto_item_add_subtree(dcm_pitem, ett_dcm);
pdu_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(dcm_ptree, hf_dcm_pdu, tvb, offset, 2,
pdu_type, "PDU Type 0x%x (%s)", pdu_type, dcm_pdu2str(pdu_type));
offset += 2;
pdu_len = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(dcm_ptree, hf_dcm_pdu_len, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
assoc = dcm_state_assoc_get(dcm_data, pinfo->fd->num, TRUE);
if (assoc == NULL) {
return offset;
}
if (pdu_type == 4) {
col_set_str(pinfo->cinfo, COL_INFO, "P-DATA");
offset = dissect_dcm_pdu_data(tvb, pinfo, dcm_ptree, assoc, offset, pdu_len, &pdu_data_description);
if (pdu_data_description) {
proto_item_append_text(dcm_pitem, ", %s", pdu_data_description);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", pdu_data_description);
}
}
else {
offset = dissect_dcm_assoc_header(tvb, pinfo, dcm_ptree, offset, assoc, pdu_type, pdu_len);
}
return offset;
}
static void dcm_apply_settings(void) {
dissector_delete_uint_range("tcp.port", global_dcm_tcp_range_backup, dcm_handle);
g_free(global_dcm_tcp_range_backup);
heur_dissector_delete("tcp", dissect_dcm_heuristic, proto_dcm);
dissector_add_uint_range("tcp.port", global_dcm_tcp_range, dcm_handle);
global_dcm_tcp_range_backup = range_copy(global_dcm_tcp_range);
if (global_dcm_heuristic)
heur_dissector_add("tcp", dissect_dcm_heuristic, proto_dcm);
}
void
proto_register_dcm(void)
{
static hf_register_info hf[] = {
{ &hf_dcm_pdu, { "PDU Type", "dicom.pdu.type",
FT_UINT8, BASE_HEX, VALS(dcm_pdu_ids), 0, NULL, HFILL } },
{ &hf_dcm_pdu_len, { "PDU Length", "dicom.pdu.len",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
#if 0
{ &hf_dcm_pdu_type, { "PDU Detail", "dicom.pdu.detail",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
#endif
{ &hf_dcm_assoc_version, { "Protocol Version", "dicom.assoc.version",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_assoc_called, { "Called AE Title", "dicom.assoc.ae.called",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_assoc_calling, { "Calling AE Title", "dicom.assoc.ae.calling",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_assoc_reject_result, { "Result", "dicom.assoc.reject.result",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_assoc_reject_source, { "Source", "dicom.assoc.reject.source",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_assoc_reject_reason, { "Reason", "dicom.assoc.reject.reason",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_assoc_abort_source, { "Source", "dicom.assoc.abort.source",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_assoc_abort_reason, { "Reason", "dicom.assoc.abort.reason",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_assoc_item_type, { "Item Type", "dicom.assoc.item.type",
FT_UINT8, BASE_HEX, VALS(dcm_assoc_item_type), 0, NULL, HFILL } },
{ &hf_dcm_assoc_item_len, { "Item Length", "dicom.assoc.item.len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_actx, { "Application Context", "dicom.actx",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_pctx_id, { "Presentation Context ID", "dicom.pctx.id",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_dcm_pctx_result, { "Presentation Context Result", "dicom.pctx.id",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_dcm_pctx_abss_syntax, { "Abstract Syntax", "dicom.pctx.abss.syntax",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_pctx_xfer_syntax, { "Transfer Syntax", "dicom.pctx.xfer.syntax",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_info, { "User Info", "dicom.userinfo",
FT_NONE, BASE_NONE, NULL, 0, "This field contains the ACSE User Information Item of the A-ASSOCIATErequest.", HFILL } },
{ &hf_dcm_info_uid, { "Implementation Class UID", "dicom.userinfo.uid",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_info_version, { "Implementation Version", "dicom.userinfo.version",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_info_extneg, { "Extended Negotiation", "dicom.userinfo.extneg",
FT_NONE, BASE_NONE, NULL, 0, "This field contains the optional SOP Class Extended Negotiation Sub-Item of the ACSE User Information Item of the A-ASSOCIATE-RQ/RSP.", HFILL } },
{ &hf_dcm_info_extneg_sopclassuid_len, { "SOP Class UID Length", "dicom.userinfo.extneg.sopclassuid.len",
FT_UINT16, BASE_DEC, NULL, 0, "This field contains the length of the SOP Class UID in the Extended Negotiation Sub-Item.", HFILL } },
{ &hf_dcm_info_extneg_sopclassuid, { "SOP Class UID", "dicom.userinfo.extneg.sopclassuid",
FT_STRING, BASE_NONE, NULL, 0, "This field contains the SOP Class UID in the Extended Negotiation Sub-Item.", HFILL } },
{ &hf_dcm_info_extneg_relational_query, { "Relational-queries", "dicom.userinfo.extneg.relational",
FT_UINT8, BASE_HEX, NULL, 0, "This field indicates, if relational queries are supported.", HFILL } },
{ &hf_dcm_info_extneg_date_time_matching, { "Combined Date-Time matching", "dicom.userinfo.extneg.datetimematching",
FT_UINT8, BASE_HEX, NULL, 0, "This field indicates, if combined date-time matching is supported.", HFILL } },
{ &hf_dcm_info_extneg_fuzzy_semantic_matching, { "Fuzzy semantic matching", "dicom.userinfo.extneg.fuzzymatching",
FT_UINT8, BASE_HEX, NULL, 0, "This field indicates, if fuzzy semantic matching of person names is supported.", HFILL } },
{ &hf_dcm_info_extneg_timezone_query_adjustment, { "Timezone query adjustment", "dicom.userinfo.extneg.timezone",
FT_UINT8, BASE_HEX, NULL, 0, "This field indicates, if timezone query adjustment is supported.", HFILL } },
{ &hf_dcm_info_rolesel, { "SCP/SCU Role Selection", "dicom.userinfo.rolesel",
FT_NONE, BASE_NONE, NULL, 0, "This field contains the optional SCP/SCU Role Selection Sub-Item of the ACSE User Information Item of the A-ASSOCIATE-RQ/RSP.", HFILL } },
{ &hf_dcm_info_rolesel_sopclassuid_len, { "SOP Class UID Length", "dicom.userinfo.rolesel.sopclassuid.len",
FT_UINT16, BASE_DEC, NULL, 0, "This field contains the length of the SOP Class UID in the SCP/SCU Role Selection Sub-Item.", HFILL } },
{ &hf_dcm_info_rolesel_sopclassuid, { "SOP Class UID", "dicom.userinfo.rolesel.sopclassuid",
FT_STRING, BASE_NONE, NULL, 0, "This field contains the SOP Class UID in the SCP/SCU Role Selection Sub-Item.", HFILL } },
{ &hf_dcm_info_rolesel_scurole, { "SCU-role", "dicom.userinfo.rolesel.scurole",
FT_UINT8, BASE_HEX, NULL, 0, "This field contains the SCU-role as defined for the Association-requester.", HFILL } },
{ &hf_dcm_info_rolesel_scprole, { "SCP-role", "dicom.userinfo.rolesel.scprole",
FT_UINT8, BASE_HEX, NULL, 0, "This field contains the SCP-role as defined for the Association-requester.", HFILL } },
{ &hf_dcm_info_async_neg, { "Asynchronous Operations (and sub-operations) Window Negotiation", "dicom.userinfo.asyncneg",
FT_NONE, BASE_NONE, NULL, 0, "This field contains the optional Asynchronous Operations (and sub-operations) Window Negotiation Sub-Item of the ACSE User Information Item of the A-ASSOCIATE-RQ/RSP.", HFILL } },
{ &hf_dcm_info_async_neg_max_num_ops_inv, { "Maximum-number-operations-invoked", "dicom.userinfo.asyncneg.maxnumopsinv",
FT_UINT16, BASE_DEC, NULL, 0, "This field contains the maximum-number-operations-invoked in the Asynchronous Operations (and sub-operations) Window Negotiation Sub-Item.", HFILL } },
{ &hf_dcm_info_async_neg_max_num_ops_per, { "Maximum-number-operations-performed", "dicom.userinfo.asyncneg.maxnumopsper",
FT_UINT16, BASE_DEC, NULL, 0, "This field contains the maximum-number-operations-performed in the Asynchronous Operations (and sub-operations) Window Negotiation Sub-Item.", HFILL } },
{ &hf_dcm_pdu_maxlen, { "Max PDU Length", "dicom.max_pdu_len",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_pdv_len, { "PDV Length", "dicom.pdv.len",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_pdv_ctx, { "PDV Context", "dicom.pdv.ctx",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_pdv_flags, { "PDV Flags", "dicom.pdv.flags",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_dcm_data_tag, { "Tag", "dicom.data.tag",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag, { "Tag", "dicom.tag",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag_vr, { "VR", "dicom.tag.vr",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag_vl, { "Length", "dicom.tag.vl",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag_value_str, { "Value", "dicom.tag.value.str",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag_value_16s, { "Value", "dicom.tag.value.16s",
FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag_value_16u, { "Value", "dicom.tag.value.16u",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag_value_32s, { "Value", "dicom.tag.value.32s",
FT_INT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag_value_32u, { "Value", "dicom.tag.value.32u",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_dcm_tag_value_byte, { "Value", "dicom.tag.value.byte",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_dcm_pdv_fragments,
{ "Message fragments", "dicom.pdv.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_fragment,
{ "Message fragment", "dicom.pdv.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_fragment_overlap,
{ "Message fragment overlap", "dicom.pdv.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data",
"dicom.pdv.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_fragment_multiple_tails,
{ "Message has multiple tail fragments",
"dicom.pdv.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_fragment_too_long_fragment,
{ "Message fragment too long", "dicom.pdv.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_fragment_error,
{ "Message defragmentation error", "dicom.pdv.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_fragment_count,
{ "Message fragment count", "dicom.pdv.fragment_count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_reassembled_in,
{ "Reassembled in", "dicom.pdv.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{ &hf_dcm_pdv_reassembled_length,
{ "Reassembled PDV length", "dicom.pdv.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } }
};
static gint *ett[] = {
&ett_dcm,
&ett_assoc,
&ett_assoc_header,
&ett_assoc_actx,
&ett_assoc_pctx,
&ett_assoc_pctx_abss,
&ett_assoc_pctx_xfer,
&ett_assoc_info,
&ett_assoc_info_uid,
&ett_assoc_info_version,
&ett_assoc_info_extneg,
&ett_assoc_info_rolesel,
&ett_assoc_info_async_neg,
&ett_dcm_data,
&ett_dcm_data_pdv,
&ett_dcm_data_tag,
&ett_dcm_data_seq,
&ett_dcm_data_item,
&ett_dcm_pdv,
&ett_dcm_pdv_fragment,
&ett_dcm_pdv_fragments
};
static ei_register_info ei[] = {
{ &ei_dcm_assoc_rejected, { "dicom.assoc.reject", PI_RESPONSE_CODE, PI_WARN, "Association rejected", EXPFILL }},
{ &ei_dcm_assoc_aborted, { "dicom.assoc.abort", PI_RESPONSE_CODE, PI_WARN, "Association aborted", EXPFILL }},
{ &ei_dcm_no_abstract_syntax, { "dicom.no_abstract_syntax", PI_MALFORMED, PI_ERROR, "No Abstract Syntax provided for this Presentation Context", EXPFILL }},
{ &ei_dcm_multiple_abstract_syntax, { "dicom.multiple_abstract_syntax", PI_MALFORMED, PI_ERROR, "More than one Abstract Syntax provided for this Presentation Context", EXPFILL }},
{ &ei_dcm_no_transfer_syntax, { "dicom.no_transfer_syntax", PI_MALFORMED, PI_ERROR, "No Transfer Syntax provided for this Presentation Context", EXPFILL }},
{ &ei_dcm_no_abstract_syntax_uid, { "dicom.no_abstract_syntax_uid", PI_MALFORMED, PI_ERROR, "No Abstract Syntax UID found for this Presentation Context", EXPFILL }},
{ &ei_dcm_multiple_transfer_syntax, { "dicom.multiple_transfer_syntax", PI_MALFORMED, PI_ERROR, "Only one Transfer Syntax allowed in a Association Response", EXPFILL }},
{ &ei_dcm_assoc_item_len, { "dicom.assoc.item.len.invalid", PI_MALFORMED, PI_ERROR, "Invalid Association Item Length", EXPFILL }},
{ &ei_dcm_pdv_ctx, { "dicom.pdv.ctx.invalid", PI_MALFORMED, PI_ERROR, "Invalid Presentation Context ID", EXPFILL }},
{ &ei_dcm_pdv_flags, { "dicom.pdv.flags.invalid", PI_MALFORMED, PI_ERROR, "Invalid Flags", EXPFILL }},
{ &ei_dcm_status_msg, { "dicom.status_msg", PI_RESPONSE_CODE, PI_WARN, "%s", EXPFILL }},
{ &ei_dcm_data_tag, { "dicom.data.tag.missing", PI_MALFORMED, PI_ERROR, "Early termination of tag. Data is missing", EXPFILL }},
{ &ei_dcm_pdv_len, { "dicom.pdv.len.invalid", PI_MALFORMED, PI_ERROR, "Invalid PDV length", EXPFILL }},
{ &ei_dcm_invalid_pdu_length, { "dicom.pdu_length.invalid", PI_MALFORMED, PI_ERROR, "Invalid PDU length", EXPFILL }},
};
module_t *dcm_module;
expert_module_t* expert_dcm;
proto_dcm = proto_register_protocol("DICOM", "DICOM", "dicom");
proto_register_field_array(proto_dcm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dcm = expert_register_protocol(proto_dcm);
expert_register_field_array(expert_dcm, ei, array_length(ei));
dcm_module = prefs_register_protocol(proto_dcm, dcm_apply_settings);
range_convert_str(&global_dcm_tcp_range, DICOM_DEFAULT_RANGE, 65535);
global_dcm_tcp_range_backup = range_empty();
prefs_register_range_preference(dcm_module, "tcp.port",
"DICOM Ports", "DICOM Ports range", &global_dcm_tcp_range, 65535);
prefs_register_bool_preference(dcm_module, "heuristic",
"Search on any TCP Port (heuristic mode)",
"When enabled, the DICOM dissector will parse all TCP packets "
"not handled by any other dissector and look for an association request. "
"Disabled by default, to preserve resources for the non DICOM community.",
&global_dcm_heuristic);
prefs_register_bool_preference(dcm_module, "export_header",
"Create Meta Header on Export",
"Create DICOM File Meta Header according to PS 3.10 on export for PDUs. "
"If the captured PDV does not contain a SOP Class UID and SOP Instance UID "
"(e.g. for command PDVs), wireshark specific ones will be created.",
&global_dcm_export_header);
prefs_register_uint_preference(dcm_module, "export_minsize",
"Min. item size in bytes to export",
"Do not show items below this size in the export list. "
"Set it to 0, to see DICOM commands and responses in the list. "
"Set it higher, to just export DICOM IODs (i.e. CT Images, RT Structures).", 10,
&global_dcm_export_minsize);
prefs_register_bool_preference(dcm_module, "seq_tree",
"Create subtrees for Sequences and Items",
"Create a node for sequences and items, and show children in a hierarchy. "
"Deselect this option, if you prefer a flat display or e.g. "
"when using TShark to create a text output.",
&global_dcm_seq_subtree);
prefs_register_bool_preference(dcm_module, "tag_tree",
"Create subtrees for DICOM Tags",
"Create a node for a tag and show tag details as single elements. "
"This can be useful to debug a tag and to allow display filters on these attributes. "
"When using TShark to create a text output, it's better to have it disabled. ",
&global_dcm_tag_subtree);
prefs_register_bool_preference(dcm_module, "cmd_details",
"Show command details in header",
"Show message ID and number of completed, remaining, warned or failed operations in header and info column.",
&global_dcm_cmd_details);
prefs_register_bool_preference(dcm_module, "pdv_reassemble",
"Merge fragmented PDVs",
"Decode all DICOM tags in the last PDV. This will ensure the proper reassembly. "
"When not set, the decoding may fail and the exports may become corrupt.",
&global_dcm_reassemble);
dicom_eo_tap = register_tap("dicom_eo");
register_init_routine(&dcm_init);
}
void
proto_reg_handoff_dcm(void)
{
dcm_handle = new_create_dissector_handle(dissect_dcm_static, proto_dcm);
dcm_apply_settings();
}
