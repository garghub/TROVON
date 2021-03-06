static guchar hex_ascii_to_binary(gchar c)
{
if ((c >= '0') && (c <= '9')) {
return c - '0';
}
else if ((c >= 'a') && (c <= 'f')) {
return 10 + c - 'a';
}
else if ((c >= 'A') && (c <= 'F')) {
return 10 + c - 'A';
}
else
return 0;
}
static void* uat_ue_keys_record_copy_cb(void* n, const void* o, size_t siz _U_) {
uat_ue_keys_record_t* new_rec = (uat_ue_keys_record_t *)n;
const uat_ue_keys_record_t* old_rec = (const uat_ue_keys_record_t *)o;
new_rec->ueid = old_rec->ueid;
new_rec->rrcCipherKeyString = (old_rec->rrcCipherKeyString) ? g_strdup(old_rec->rrcCipherKeyString) : NULL;
new_rec->upCipherKeyString = (old_rec->upCipherKeyString) ? g_strdup(old_rec->upCipherKeyString) : NULL;
new_rec->rrcIntegrityKeyString = (old_rec->rrcIntegrityKeyString) ? g_strdup(old_rec->rrcIntegrityKeyString) : NULL;
return new_rec;
}
static gboolean check_valid_key_sring(const char* raw_string, char* checked_string)
{
guint n;
guint written = 0;
guint length = (gint)strlen(raw_string);
if (length < 32) {
return FALSE;
}
for (n=0; (n < length) && (written < 32); n++) {
char c = raw_string[n];
if ((c == ' ') || (c == '-')) {
continue;
}
if (((c >= '0') && (c <= '9')) ||
((c >= 'a') && (c <= 'f')) ||
((c >= 'A') && (c <= 'F'))) {
checked_string[written++] = c;
}
else {
return FALSE;
}
}
return (written == 32);
}
static void update_key_from_string(const char *stringKey, guint8 *binaryKey, gboolean *pKeyOK)
{
int n;
char cleanString[32];
if (!check_valid_key_sring(stringKey, cleanString)) {
*pKeyOK = FALSE;
}
else {
for (n=0; n < 32; n += 2) {
binaryKey[n/2] = (hex_ascii_to_binary(cleanString[n]) << 4) +
hex_ascii_to_binary(cleanString[n+1]);
}
*pKeyOK = TRUE;
}
}
static gboolean uat_ue_keys_record_update_cb(void* record, char** error _U_) {
uat_ue_keys_record_t* rec = (uat_ue_keys_record_t *)record;
update_key_from_string(rec->rrcCipherKeyString, rec->rrcCipherBinaryKey, &rec->rrcCipherKeyOK);
update_key_from_string(rec->upCipherKeyString, rec->upCipherBinaryKey, &rec->upCipherKeyOK);
update_key_from_string(rec->rrcIntegrityKeyString, rec->rrcIntegrityBinaryKey, &rec->rrcIntegrityKeyOK);
return TRUE;
}
static void uat_ue_keys_record_free_cb(void*r) {
uat_ue_keys_record_t* rec = (uat_ue_keys_record_t*)r;
g_free(rec->rrcCipherKeyString);
g_free(rec->upCipherKeyString);
g_free(rec->rrcIntegrityKeyString);
}
void set_pdcp_lte_rrc_ciphering_key(guint16 ueid, const char *key)
{
uat_ue_keys_record_t *key_record = (uat_ue_keys_record_t*)wmem_map_lookup(pdcp_security_key_hash,
GUINT_TO_POINTER((guint)ueid));
if (key_record == NULL) {
key_record = wmem_new0(wmem_file_scope(), uat_ue_keys_record_t);
key_record->ueid = ueid;
wmem_map_insert(pdcp_security_key_hash, GUINT_TO_POINTER((guint)ueid), key_record);
}
key_record->rrcCipherKeyString = g_strdup(key);
update_key_from_string(key_record->rrcCipherKeyString, key_record->rrcCipherBinaryKey, &key_record->rrcCipherKeyOK);}
void set_pdcp_lte_rrc_integrity_key(guint16 ueid, const char *key)
{
uat_ue_keys_record_t *key_record = (uat_ue_keys_record_t*)wmem_map_lookup(pdcp_security_key_hash,
GUINT_TO_POINTER((guint)ueid));
if (key_record == NULL) {
key_record = wmem_new0(wmem_file_scope(), uat_ue_keys_record_t);
key_record->ueid = ueid;
wmem_map_insert(pdcp_security_key_hash, GUINT_TO_POINTER((guint)ueid), key_record);
}
key_record->rrcIntegrityKeyString = g_strdup(key);
update_key_from_string(key_record->rrcIntegrityKeyString, key_record->rrcIntegrityBinaryKey, &key_record->rrcIntegrityKeyOK);
}
void set_pdcp_lte_up_ciphering_key(guint16 ueid, const char *key)
{
uat_ue_keys_record_t *key_record = (uat_ue_keys_record_t*)wmem_map_lookup(pdcp_security_key_hash,
GUINT_TO_POINTER((guint)ueid));
if (key_record == NULL) {
key_record = wmem_new0(wmem_file_scope(), uat_ue_keys_record_t);
key_record->ueid = ueid;
wmem_map_insert(pdcp_security_key_hash, GUINT_TO_POINTER((guint)ueid), key_record);
}
key_record->upCipherKeyString = g_strdup(key);
update_key_from_string(key_record->upCipherKeyString, key_record->upCipherBinaryKey, &key_record->upCipherKeyOK);
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
return val1->frameNumber + (val1->channelId<<7) +
(val1->plane<<12) +
(val1->SN<<14) +
(val1->direction<<6);
}
static gpointer get_channel_hash_key(pdcp_channel_hash_key *key)
{
guint asInt = 0;
memcpy(&asInt, key, sizeof(pdcp_channel_hash_key));
return GUINT_TO_POINTER(asInt);
}
static gpointer get_report_hash_key(guint32 SN, guint32 frameNumber,
pdcp_lte_info *p_pdcp_lte_info,
gboolean do_persist)
{
static pdcp_result_hash_key key;
pdcp_result_hash_key *p_key;
if (do_persist) {
p_key = wmem_new(wmem_file_scope(), pdcp_result_hash_key);
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
p_key->notUsed = 0;
return p_key;
}
static uat_ue_keys_record_t* look_up_keys_record(guint16 ueid)
{
unsigned int record_id;
uat_ue_keys_record_t* key_record = (uat_ue_keys_record_t*)wmem_map_lookup(pdcp_security_key_hash,
GUINT_TO_POINTER((guint)ueid));
if (key_record != NULL) {
return key_record;
}
for (record_id=0; record_id < num_ue_keys_uat; record_id++) {
if (uat_ue_keys_records[record_id].ueid == ueid) {
return &uat_ue_keys_records[record_id];
}
}
return NULL;
}
static void addChannelSequenceInfo(pdcp_sequence_report_in_frame *p,
pdcp_lte_info *p_pdcp_lte_info,
guint32 sequenceNumber,
packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb,
proto_tree *security_tree,
pdu_security_settings_t *pdu_security)
{
proto_tree *seqnum_tree;
proto_item *seqnum_ti;
proto_item *ti_expected_sn;
proto_item *ti;
uat_ue_keys_record_t *keys_record;
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
case PDCP_SN_LENGTH_15_BITS:
case PDCP_SN_LENGTH_18_BITS:
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
if ((pdu_security->ciphering != eea0) ||
(pdu_security->integrity != eia0)) {
guint32 hfn_multiplier;
guint32 count;
gchar *cipher_key = NULL;
gchar *integrity_key = NULL;
ti = proto_tree_add_uint(security_tree, hf_pdcp_lte_security_bearer,
tvb, 0, 0, p_pdcp_lte_info->channelId-1);
PROTO_ITEM_SET_GENERATED(ti);
pdu_security->bearer = p_pdcp_lte_info->channelId-1;
ti = proto_tree_add_uint(security_tree, hf_pdcp_lte_security_direction,
tvb, 0, 0, p_pdcp_lte_info->direction);
PROTO_ITEM_SET_GENERATED(ti);
switch (p_pdcp_lte_info->seqnum_length) {
case PDCP_SN_LENGTH_5_BITS:
hfn_multiplier = 32;
break;
case PDCP_SN_LENGTH_7_BITS:
hfn_multiplier = 128;
break;
case PDCP_SN_LENGTH_12_BITS:
hfn_multiplier = 4096;
break;
case PDCP_SN_LENGTH_15_BITS:
hfn_multiplier = 32768;
break;
case PDCP_SN_LENGTH_18_BITS:
hfn_multiplier = 262144;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
count = (p->hfn * hfn_multiplier) + sequenceNumber;
ti = proto_tree_add_uint(security_tree, hf_pdcp_lte_security_count,
tvb, 0, 0, count);
PROTO_ITEM_SET_GENERATED(ti);
pdu_security->count = count;
keys_record = look_up_keys_record(p_pdcp_lte_info->ueid);
if (keys_record != NULL) {
if (p_pdcp_lte_info->plane == SIGNALING_PLANE) {
if (keys_record->rrcCipherKeyOK) {
cipher_key = keys_record->rrcCipherKeyString;
pdu_security->cipherKey = &(keys_record->rrcCipherBinaryKey[0]);
pdu_security->cipherKeyValid = TRUE;
}
if (keys_record->rrcIntegrityKeyOK) {
integrity_key = keys_record->rrcIntegrityKeyString;
pdu_security->integrityKey = &(keys_record->rrcIntegrityBinaryKey[0]);
pdu_security->integrityKeyValid = TRUE;
}
}
else {
if (keys_record->upCipherKeyOK) {
cipher_key = keys_record->upCipherKeyString;
pdu_security->cipherKey = &(keys_record->upCipherBinaryKey[0]);
pdu_security->cipherKeyValid = TRUE;
}
}
if (cipher_key != NULL) {
ti = proto_tree_add_string(security_tree, hf_pdcp_lte_security_cipher_key,
tvb, 0, 0, cipher_key);
PROTO_ITEM_SET_GENERATED(ti);
}
if (integrity_key != NULL) {
ti = proto_tree_add_string(security_tree, hf_pdcp_lte_security_integrity_key,
tvb, 0, 0, integrity_key);
PROTO_ITEM_SET_GENERATED(ti);
}
pdu_security->direction = p_pdcp_lte_info->direction;
}
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
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_sequence_analysis_sn_missing,
"PDCP SNs (%u to %u) missing for %s on UE %u (%s-%u)",
p->firstSN, p->lastSN,
val_to_str_const(p_pdcp_lte_info->direction, direction_vals, "Unknown"),
p_pdcp_lte_info->ueid,
val_to_str_const(p_pdcp_lte_info->channelType, logical_channel_vals, "Unknown"),
p_pdcp_lte_info->channelId);
proto_item_append_text(seqnum_ti, " - SNs missing (%u to %u)",
p->firstSN, p->lastSN);
}
else {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_sequence_analysis_sn_missing,
"PDCP SN (%u) missing for %s on UE %u (%s-%u)",
p->firstSN,
val_to_str_const(p_pdcp_lte_info->direction, direction_vals, "Unknown"),
p_pdcp_lte_info->ueid,
val_to_str_const(p_pdcp_lte_info->channelType, logical_channel_vals, "Unknown"),
p_pdcp_lte_info->channelId);
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
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_sequence_analysis_sn_repeated,
"PDCP SN (%u) repeated for %s for UE %u (%s-%u)",
p->firstSN,
val_to_str_const(p_pdcp_lte_info->direction, direction_vals, "Unknown"),
p_pdcp_lte_info->ueid,
val_to_str_const(p_pdcp_lte_info->channelType, logical_channel_vals, "Unknown"),
p_pdcp_lte_info->channelId);
proto_item_append_text(seqnum_ti, "- SN %u Repeated",
p->firstSN);
break;
default:
expert_add_info_format(pinfo, ti_expected_sn, &ei_pdcp_lte_sequence_analysis_wrong_sequence_number,
"Wrong Sequence Number for %s on UE %u (%s-%u) - got %u, expected %u",
val_to_str_const(p_pdcp_lte_info->direction, direction_vals, "Unknown"),
p_pdcp_lte_info->ueid,
val_to_str_const(p_pdcp_lte_info->channelType, logical_channel_vals, "Unknown"),
p_pdcp_lte_info->channelId,
sequenceNumber, p->sequenceExpected);
break;
}
}
static void checkChannelSequenceInfo(packet_info *pinfo, tvbuff_t *tvb,
pdcp_lte_info *p_pdcp_lte_info,
guint32 sequenceNumber,
proto_tree *tree,
proto_tree *security_tree,
pdu_security_settings_t *pdu_security)
{
pdcp_channel_hash_key channel_key;
pdcp_channel_status *p_channel_status;
pdcp_sequence_report_in_frame *p_report_in_frame = NULL;
gboolean createdChannel = FALSE;
guint32 expectedSequenceNumber = 0;
guint32 snLimit = 0;
if (pinfo->fd->flags.visited) {
p_report_in_frame =
(pdcp_sequence_report_in_frame*)wmem_map_lookup(pdcp_lte_sequence_analysis_report_hash,
get_report_hash_key(sequenceNumber,
pinfo->num,
p_pdcp_lte_info, FALSE));
if (p_report_in_frame != NULL) {
addChannelSequenceInfo(p_report_in_frame, p_pdcp_lte_info,
sequenceNumber,
pinfo, tree, tvb, security_tree, pdu_security);
return;
}
else {
return;
}
}
channel_key.ueId = p_pdcp_lte_info->ueid;
channel_key.plane = p_pdcp_lte_info->plane;
channel_key.channelId = p_pdcp_lte_info->channelId;
channel_key.direction = p_pdcp_lte_info->direction;
channel_key.notUsed = 0;
p_channel_status = (pdcp_channel_status*)wmem_map_lookup(pdcp_sequence_analysis_channel_hash,
get_channel_hash_key(&channel_key));
if (p_channel_status == NULL) {
createdChannel = TRUE;
p_channel_status = wmem_new0(wmem_file_scope(), pdcp_channel_status);
wmem_map_insert(pdcp_sequence_analysis_channel_hash,
get_channel_hash_key(&channel_key), p_channel_status);
}
p_report_in_frame = wmem_new(wmem_file_scope(), pdcp_sequence_report_in_frame);
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
case PDCP_SN_LENGTH_15_BITS:
snLimit = 32768;
break;
case PDCP_SN_LENGTH_18_BITS:
snLimit = 262144;
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
p_report_in_frame->hfn = p_channel_status->hfn;
if (!p_report_in_frame->sequenceExpectedCorrect) {
if (((snLimit + expectedSequenceNumber - sequenceNumber) % snLimit) > 15) {
p_report_in_frame->state = SN_Missing;
p_report_in_frame->firstSN = expectedSequenceNumber;
p_report_in_frame->lastSN = (snLimit + sequenceNumber - 1) % snLimit;
p_report_in_frame->sequenceExpected = expectedSequenceNumber;
p_report_in_frame->previousFrameNum = p_channel_status->previousFrameNum;
p_channel_status->previousFrameNum = pinfo->num;
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
if (!createdChannel && (sequenceNumber == 0)) {
p_channel_status->hfn++;
p_report_in_frame->hfn = p_channel_status->hfn;
}
p_channel_status->previousFrameNum = pinfo->num;
p_channel_status->previousSequenceNumber = sequenceNumber;
if (p_report_in_frame->previousFrameNum != 0) {
pdcp_sequence_report_in_frame *p_previous_report;
p_previous_report = (pdcp_sequence_report_in_frame*)wmem_map_lookup(pdcp_lte_sequence_analysis_report_hash,
get_report_hash_key((sequenceNumber+262144) % 262144,
p_report_in_frame->previousFrameNum,
p_pdcp_lte_info,
FALSE));
if (p_previous_report != NULL) {
p_previous_report->nextFrameNum = pinfo->num;
}
}
}
wmem_map_insert(pdcp_lte_sequence_analysis_report_hash,
get_report_hash_key(sequenceNumber, pinfo->num,
p_pdcp_lte_info, TRUE),
p_report_in_frame);
addChannelSequenceInfo(p_report_in_frame, p_pdcp_lte_info, sequenceNumber,
pinfo, tree, tvb, security_tree, pdu_security);
}
static gint pdcp_lte_ueid_hash_equal(gconstpointer v, gconstpointer v2)
{
return (v == v2);
}
static guint pdcp_lte_ueid_hash_func(gconstpointer v)
{
return GPOINTER_TO_UINT(v);
}
static gpointer get_ueid_frame_hash_key(guint16 ueid, guint32 frameNumber,
gboolean do_persist)
{
static ueid_frame_t key;
ueid_frame_t *p_key;
if (do_persist) {
p_key = wmem_new(wmem_file_scope(), ueid_frame_t);
}
else {
memset(&key, 0, sizeof(ueid_frame_t));
p_key = &key;
}
p_key->framenum = frameNumber;
p_key->ueid = ueid;
return p_key;
}
static gint pdcp_lte_ueid_frame_hash_equal(gconstpointer v, gconstpointer v2)
{
const ueid_frame_t *ueid_frame_1 = (const ueid_frame_t *)v;
const ueid_frame_t *ueid_frame_2 = (const ueid_frame_t *)v2;
return ((ueid_frame_1->framenum == ueid_frame_2->framenum) && (ueid_frame_1->ueid == ueid_frame_2->ueid));
}
static guint pdcp_lte_ueid_frame_hash_func(gconstpointer v)
{
const ueid_frame_t *ueid_frame = (const ueid_frame_t *)v;
return ueid_frame->framenum + 100*ueid_frame->ueid;
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
p_pdcp_info->rohc.rohc_compression);
PROTO_ITEM_SET_GENERATED(ti);
if (p_pdcp_info->rohc.rohc_compression) {
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_rohc_mode, tvb, 0, 0,
p_pdcp_info->rohc.mode);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_rohc_rnd, tvb, 0, 0,
p_pdcp_info->rohc.rnd);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_rohc_udp_checksum_present, tvb, 0, 0,
p_pdcp_info->rohc.udp_checksum_present);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_rohc_profile, tvb, 0, 0,
p_pdcp_info->rohc.profile);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_cid_inclusion_info, tvb, 0, 0,
p_pdcp_info->rohc.cid_inclusion_info);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(configuration_tree, hf_pdcp_lte_large_cid_present, tvb, 0, 0,
p_pdcp_info->rohc.large_cid_present);
PROTO_ITEM_SET_GENERATED(ti);
}
proto_item_append_text(configuration_ti, "(direction=%s, plane=%s",
val_to_str_const(p_pdcp_info->direction, direction_vals, "Unknown"),
val_to_str_const(p_pdcp_info->plane, pdcp_plane_vals, "Unknown"));
if (p_pdcp_info->rohc.rohc_compression) {
const char *mode = val_to_str_const(p_pdcp_info->rohc.mode, rohc_mode_vals, "Error");
proto_item_append_text(configuration_ti, ", mode=%c, profile=%s",
mode[0],
val_to_str_const(p_pdcp_info->rohc.profile, rohc_profile_vals, "Unknown"));
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
rrc_handle = lte_rrc_ul_ccch;
}
else {
rrc_handle = lte_rrc_dl_ccch;
}
break;
case Channel_PCCH:
rrc_handle = lte_rrc_pcch;
break;
case Channel_BCCH:
switch (p_pdcp_info->BCCHTransport) {
case BCH_TRANSPORT:
rrc_handle = lte_rrc_bcch_bch;
break;
case DLSCH_TRANSPORT:
rrc_handle = lte_rrc_bcch_dl_sch;
break;
}
break;
case Channel_DCCH:
if (p_pdcp_info->direction == DIRECTION_UPLINK) {
rrc_handle = lte_rrc_ul_dcch;
}
else {
rrc_handle = lte_rrc_dl_dcch;
}
break;
case Channel_CCCH_NB:
if (p_pdcp_info->direction == DIRECTION_UPLINK) {
rrc_handle = lte_rrc_ul_ccch_nb;
}
else {
rrc_handle = lte_rrc_dl_ccch_nb;
}
break;
case Channel_PCCH_NB:
rrc_handle = lte_rrc_pcch_nb;
break;
case Channel_BCCH_NB:
switch (p_pdcp_info->BCCHTransport) {
case BCH_TRANSPORT:
rrc_handle = lte_rrc_bcch_bch_nb;
break;
case DLSCH_TRANSPORT:
rrc_handle = lte_rrc_bcch_dl_sch_nb;
break;
}
break;
case Channel_DCCH_NB:
if (p_pdcp_info->direction == DIRECTION_UPLINK) {
rrc_handle = lte_rrc_ul_dcch_nb;
}
else {
rrc_handle = lte_rrc_dl_dcch_nb;
}
break;
default:
break;
}
return rrc_handle;
}
static gboolean dissect_pdcp_lte_heur(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void *data _U_)
{
gint offset = 0;
struct pdcp_lte_info *p_pdcp_lte_info;
tvbuff_t *pdcp_tvb;
guint8 tag = 0;
gboolean infoAlreadySet = FALSE;
gboolean seqnumLengthTagPresent = FALSE;
if (tvb_captured_length_remaining(tvb, offset) < (gint)(strlen(PDCP_LTE_START_STRING)+3+2)) {
return FALSE;
}
if (tvb_strneql(tvb, offset, PDCP_LTE_START_STRING, strlen(PDCP_LTE_START_STRING)) != 0) {
return FALSE;
}
offset += (gint)strlen(PDCP_LTE_START_STRING);
p_pdcp_lte_info = (pdcp_lte_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_pdcp_lte, 0);
if (p_pdcp_lte_info == NULL) {
p_pdcp_lte_info = wmem_new0(wmem_file_scope(), pdcp_lte_info);
infoAlreadySet = FALSE;
}
else {
infoAlreadySet = TRUE;
}
p_pdcp_lte_info->no_header_pdu = (gboolean)tvb_get_guint8(tvb, offset++);
p_pdcp_lte_info->plane = (enum pdcp_plane)tvb_get_guint8(tvb, offset++);
if (p_pdcp_lte_info->plane == SIGNALING_PLANE) {
p_pdcp_lte_info->seqnum_length = PDCP_SN_LENGTH_5_BITS;
}
p_pdcp_lte_info->rohc.rohc_compression = (gboolean)tvb_get_guint8(tvb, offset++);
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
p_pdcp_lte_info->channelType = (LogicalChannelType)tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_BCCH_TRANSPORT_TYPE_TAG:
p_pdcp_lte_info->BCCHTransport = (BCCHTransportType)tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_IP_VERSION_TAG:
p_pdcp_lte_info->rohc.rohc_ip_version = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case PDCP_LTE_ROHC_CID_INC_INFO_TAG:
p_pdcp_lte_info->rohc.cid_inclusion_info = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_LARGE_CID_PRES_TAG:
p_pdcp_lte_info->rohc.large_cid_present = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_MODE_TAG:
p_pdcp_lte_info->rohc.mode = (enum rohc_mode)tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_RND_TAG:
p_pdcp_lte_info->rohc.rnd = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_UDP_CHECKSUM_PRES_TAG:
p_pdcp_lte_info->rohc.udp_checksum_present = tvb_get_guint8(tvb, offset);
offset++;
break;
case PDCP_LTE_ROHC_PROFILE_TAG:
p_pdcp_lte_info->rohc.profile = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case PDCP_LTE_CHANNEL_ID_TAG:
p_pdcp_lte_info->channelId = tvb_get_ntohs(tvb, offset);
offset += 2;
break;
case PDCP_LTE_UEID_TAG:
p_pdcp_lte_info->ueid = tvb_get_ntohs(tvb, offset);
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
p_add_proto_data(wmem_file_scope(), pinfo, proto_pdcp_lte, 0, p_pdcp_lte_info);
}
pdcp_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_pdcp_lte(pdcp_tvb, pinfo, tree, data);
return TRUE;
}
void set_pdcp_lte_security_algorithms(guint16 ueid, pdcp_security_info_t *security_info)
{
pdcp_security_info_t *p_frame_security;
if (global_pdcp_ignore_sec) {
return;
}
pdcp_security_info_t* ue_security =
(pdcp_security_info_t*)wmem_map_lookup(pdcp_security_hash,
GUINT_TO_POINTER((guint)ueid));
if (ue_security == NULL) {
ue_security = wmem_new(wmem_file_scope(), pdcp_security_info_t);
*ue_security = *security_info;
wmem_map_insert(pdcp_security_hash, GUINT_TO_POINTER((guint)ueid), ue_security);
}
else {
ue_security->previous_configuration_frame = ue_security->configuration_frame;
ue_security->previous_integrity = ue_security->integrity;
ue_security->previous_ciphering = ue_security->ciphering;
ue_security->configuration_frame = security_info->configuration_frame;
ue_security->integrity = security_info->integrity;
ue_security->ciphering = security_info->ciphering;
ue_security->seen_next_ul_pdu = FALSE;
}
p_frame_security = wmem_new(wmem_file_scope(), pdcp_security_info_t);
*p_frame_security = *ue_security;
wmem_map_insert(pdcp_security_result_hash,
get_ueid_frame_hash_key(ueid, ue_security->configuration_frame, TRUE),
p_frame_security);
}
void set_pdcp_lte_security_algorithms_failed(guint16 ueid)
{
pdcp_security_info_t* ue_security =
(pdcp_security_info_t*)wmem_map_lookup(pdcp_security_hash,
GUINT_TO_POINTER((guint)ueid));
if (ue_security != NULL) {
ue_security->configuration_frame = ue_security->previous_configuration_frame;
ue_security->integrity = ue_security->previous_integrity;
ue_security->ciphering = ue_security->previous_ciphering;
}
}
static tvbuff_t *decipher_payload(tvbuff_t *tvb, packet_info *pinfo, int *offset,
pdu_security_settings_t *pdu_security_settings,
struct pdcp_lte_info *p_pdcp_info, gboolean will_be_deciphered,
gboolean *deciphered)
{
guint8* decrypted_data = NULL;
gint payload_length = 0;
tvbuff_t *decrypted_tvb;
if (pdu_security_settings->ciphering == eea0) {
return tvb;
}
if (!pdu_security_settings->cipherKeyValid) {
return tvb;
}
if (pdu_security_settings->ciphering == eea1) {
#ifndef HAVE_SNOW3G
return tvb;
#endif
}
else
if (pdu_security_settings->ciphering != eea2) {
return tvb;
}
if (((p_pdcp_info->plane == SIGNALING_PLANE) && !global_pdcp_decipher_signalling) ||
((p_pdcp_info->plane == USER_PLANE) && !global_pdcp_decipher_userplane)) {
return tvb;
}
if ((p_pdcp_info->plane == USER_PLANE) && ((tvb_get_guint8(tvb, 0) & 0x80) == 0x00)) {
return tvb;
}
if ((p_pdcp_info->plane == SIGNALING_PLANE) && (p_pdcp_info->channelType != Channel_DCCH)) {
return tvb;
}
if (!will_be_deciphered) {
return tvb;
}
if (pdu_security_settings->ciphering == eea2) {
unsigned char ctr_block[16];
gcry_cipher_hd_t cypher_hd;
int gcrypt_err;
memset(ctr_block, 0, 16);
ctr_block[0] = (pdu_security_settings->count & 0xff000000) >> 24;
ctr_block[1] = (pdu_security_settings->count & 0x00ff0000) >> 16;
ctr_block[2] = (pdu_security_settings->count & 0x0000ff00) >> 8;
ctr_block[3] = (pdu_security_settings->count & 0x000000ff);
ctr_block[4] = (pdu_security_settings->bearer << 3) + (pdu_security_settings->direction << 2);
gcrypt_err = gcry_cipher_open(&cypher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CTR, 0);
if (gcrypt_err != 0) {
return tvb;
}
gcrypt_err = gcry_cipher_setkey(cypher_hd, pdu_security_settings->cipherKey, 16);
if (gcrypt_err != 0) {
gcry_cipher_close(cypher_hd);
return tvb;
}
gcrypt_err = gcry_cipher_setctr(cypher_hd, ctr_block, 16);
if (gcrypt_err != 0) {
gcry_cipher_close(cypher_hd);
return tvb;
}
payload_length = tvb_captured_length_remaining(tvb, *offset);
decrypted_data = (guint8 *)tvb_memdup(pinfo->pool, tvb, *offset, payload_length);
gcrypt_err = gcry_cipher_decrypt(cypher_hd,
decrypted_data, payload_length,
NULL, 0);
if (gcrypt_err != 0) {
gcry_cipher_close(cypher_hd);
return tvb;
}
gcry_cipher_close(cypher_hd);
}
#ifdef HAVE_SNOW3G
if (pdu_security_settings->ciphering == eea1) {
payload_length = tvb_captured_length_remaining(tvb, *offset);
decrypted_data = (guint8 *)tvb_memdup(pinfo->pool, tvb, *offset, payload_length);
snow3g_f8(pdu_security_settings->cipherKey,
pdu_security_settings->count,
pdu_security_settings->bearer,
pdu_security_settings->direction,
decrypted_data, payload_length*8);
}
#endif
decrypted_tvb = tvb_new_child_real_data(tvb, decrypted_data, payload_length, payload_length);
add_new_data_source(pinfo, decrypted_tvb, "Deciphered Payload");
*offset = 0;
*deciphered = TRUE;
return decrypted_tvb;
}
static guint32 calculate_digest(pdu_security_settings_t *pdu_security_settings, guint8 header _U_,
tvbuff_t *tvb _U_, gint offset _U_, gboolean *calculated)
{
*calculated = FALSE;
if (pdu_security_settings->integrity == eia0) {
*calculated = TRUE;
return 0;
}
if (!pdu_security_settings->integrityKeyValid) {
return 0;
}
if (!global_pdcp_check_integrity) {
return 0;
}
switch (pdu_security_settings->integrity) {
#ifdef HAVE_SNOW3G
case eia1:
{
guint8 *mac;
gint message_length = tvb_captured_length_remaining(tvb, offset) - 4;
guint8 *message_data = (guint8 *)wmem_alloc0(wmem_packet_scope(), message_length+5);
message_data[0] = header;
tvb_memcpy(tvb, message_data+1, offset, message_length);
mac = (u8*)snow3g_f9(pdu_security_settings->integrityKey,
pdu_security_settings->count,
pdu_security_settings->bearer << 27,
pdu_security_settings->direction,
message_data,
(message_length+1)*8);
*calculated = TRUE;
return ((mac[0] << 24) | (mac[1] << 16) | (mac[2] << 8) | mac[3]);
}
#endif
#if GCRYPT_VERSION_NUMBER >= 0x010600
case eia2:
{
gcry_mac_hd_t mac_hd;
int gcrypt_err;
gint message_length;
guint8 *message_data;
guint8 mac[4];
size_t read_digest_length = 4;
gcrypt_err = gcry_mac_open(&mac_hd, GCRY_MAC_CMAC_AES, 0, NULL);
if (gcrypt_err != 0) {
return 0;
}
gcrypt_err = gcry_mac_setkey(mac_hd, pdu_security_settings->integrityKey, 16);
if (gcrypt_err != 0) {
gcry_mac_close(mac_hd);
return 0;
}
message_length = tvb_captured_length_remaining(tvb, offset) - 4;
message_data = (guint8 *)wmem_alloc0(wmem_packet_scope(), message_length+9);
message_data[0] = (pdu_security_settings->count & 0xff000000) >> 24;
message_data[1] = (pdu_security_settings->count & 0x00ff0000) >> 16;
message_data[2] = (pdu_security_settings->count & 0x0000ff00) >> 8;
message_data[3] = (pdu_security_settings->count & 0x000000ff);
message_data[4] = (pdu_security_settings->bearer << 3) + (pdu_security_settings->direction << 2);
message_data[8] = header;
tvb_memcpy(tvb, message_data+9, offset, message_length);
gcrypt_err = gcry_mac_write(mac_hd, message_data, message_length+9);
if (gcrypt_err != 0) {
gcry_mac_close(mac_hd);
return 0;
}
gcrypt_err = gcry_mac_read(mac_hd, mac, &read_digest_length);
if (gcrypt_err != 0) {
gcry_mac_close(mac_hd);
return 0;
}
gcry_mac_close(mac_hd);
*calculated = TRUE;
return ((mac[0] << 24) | (mac[1] << 16) | (mac[2] << 8) | mac[3]);
}
#endif
default:
*calculated = FALSE;
return 0;
}
}
static int dissect_pdcp_lte(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
const char *mode;
proto_tree *pdcp_tree = NULL;
proto_item *root_ti = NULL;
gint offset = 0;
struct pdcp_lte_info *p_pdcp_info;
tvbuff_t *rohc_tvb = NULL;
pdcp_security_info_t *current_security = NULL;
pdcp_security_info_t *pdu_security;
proto_tree *security_tree = NULL;
proto_item *security_ti;
tvbuff_t *payload_tvb;
pdu_security_settings_t pdu_security_settings;
gboolean payload_deciphered = FALSE;
memset(&pdu_security_settings, 0, sizeof(pdu_security_settings));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PDCP-LTE");
p_pdcp_info = (struct pdcp_lte_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_pdcp_lte, 0);
if (p_pdcp_info == NULL) {
return 0;
}
if ((global_pdcp_lte_layer_to_show == ShowRLCLayer) &&
(p_get_proto_data(wmem_file_scope(), pinfo, proto_rlc_lte, 0) != NULL)) {
col_set_writable(pinfo->cinfo, COL_INFO, FALSE);
}
else {
col_clear(pinfo->cinfo, COL_INFO);
col_set_writable(pinfo->cinfo, COL_INFO, TRUE);
}
if (tree) {
root_ti = proto_tree_add_item(tree, proto_pdcp_lte, tvb, offset, -1, ENC_NA);
pdcp_tree = proto_item_add_subtree(root_ti, ett_pdcp);
}
mode = val_to_str_const(p_pdcp_info->rohc.mode, rohc_mode_vals, "Error");
if (pdcp_tree) {
show_pdcp_config(pinfo, tvb, pdcp_tree, p_pdcp_info);
}
if (p_pdcp_info->rohc.rohc_compression) {
col_append_fstr(pinfo->cinfo, COL_INFO, " (mode=%c)", mode[0]);
}
if (!pinfo->fd->flags.visited) {
current_security = (pdcp_security_info_t*)wmem_map_lookup(pdcp_security_hash,
GUINT_TO_POINTER((guint)p_pdcp_info->ueid));
if (current_security != NULL) {
pdcp_security_info_t *security_to_store = wmem_new(wmem_file_scope(), pdcp_security_info_t);
*security_to_store = *current_security;
wmem_map_insert(pdcp_security_result_hash,
get_ueid_frame_hash_key(p_pdcp_info->ueid, pinfo->num, TRUE),
security_to_store);
}
else {
if ((global_default_ciphering_algorithm != eea0) ||
(global_default_integrity_algorithm != eia0)) {
pdcp_security_info_t *security_to_store = wmem_new0(wmem_file_scope(), pdcp_security_info_t);
security_to_store->ciphering = global_default_ciphering_algorithm;
security_to_store->integrity = global_default_integrity_algorithm;
security_to_store->seen_next_ul_pdu = TRUE;
wmem_map_insert(pdcp_security_result_hash,
get_ueid_frame_hash_key(p_pdcp_info->ueid, pinfo->num, TRUE),
security_to_store);
}
}
}
pdu_security = (pdcp_security_info_t*)wmem_map_lookup(pdcp_security_result_hash, get_ueid_frame_hash_key(p_pdcp_info->ueid, pinfo->num, FALSE));
if (pdu_security != NULL) {
proto_item *ti;
security_ti = proto_tree_add_string_format(pdcp_tree,
hf_pdcp_lte_security,
tvb, 0, 0,
"", "UE Security");
security_tree = proto_item_add_subtree(security_ti, ett_pdcp_security);
PROTO_ITEM_SET_GENERATED(security_ti);
ti = proto_tree_add_uint(security_tree, hf_pdcp_lte_security_setup_frame,
tvb, 0, 0, pdu_security->configuration_frame);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(security_tree, hf_pdcp_lte_security_ciphering_algorithm,
tvb, 0, 0, pdu_security->ciphering);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(security_tree, hf_pdcp_lte_security_integrity_algorithm,
tvb, 0, 0, pdu_security->integrity);
PROTO_ITEM_SET_GENERATED(ti);
proto_item_append_text(security_ti, " (ciphering=%s, integrity=%s)",
val_to_str_const(pdu_security->ciphering, ciphering_algorithm_vals, "Unknown"),
val_to_str_const(pdu_security->integrity, integrity_algorithm_vals, "Unknown"));
pdu_security_settings.ciphering = pdu_security->ciphering;
pdu_security_settings.integrity = pdu_security->integrity;
}
if (!p_pdcp_info->no_header_pdu) {
guint32 seqnum = 0;
gboolean seqnum_set = FALSE;
guint8 first_byte = tvb_get_guint8(tvb, offset);
if (p_pdcp_info->plane == SIGNALING_PLANE) {
guint8 reserved = (first_byte & 0xe0) >> 5;
proto_item *ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_control_plane_reserved,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (reserved != 0) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"PDCP signalling header reserved bits not zero");
}
seqnum = first_byte & 0x1f;
seqnum_set = TRUE;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_seq_num_5, tvb, offset, 1, ENC_BIG_ENDIAN);
write_pdu_label_and_info(root_ti, pinfo, " sn=%-2u ", seqnum);
offset++;
if (tvb_captured_length_remaining(tvb, offset) == 0) {
return offset;
}
}
else if (p_pdcp_info->plane == USER_PLANE) {
gboolean pdu_type = (first_byte & 0x80) >> 7;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_data_control, tvb, offset, 1, ENC_BIG_ENDIAN);
if (pdu_type == 1) {
switch (p_pdcp_info->seqnum_length) {
case PDCP_SN_LENGTH_7_BITS:
seqnum = first_byte & 0x7f;
seqnum_set = TRUE;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_seq_num_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case PDCP_SN_LENGTH_12_BITS:
{
proto_item *ti;
guint8 reserved_value;
ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_reserved3, tvb, offset, 1, ENC_BIG_ENDIAN);
reserved_value = (first_byte & 0x70) >> 4;
if (reserved_value != 0) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x%x - should be 0x0",
reserved_value);
}
seqnum = tvb_get_ntohs(tvb, offset) & 0x0fff;
seqnum_set = TRUE;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_seq_num_12, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case PDCP_SN_LENGTH_15_BITS:
seqnum = tvb_get_ntohs(tvb, offset) & 0x7fff;
seqnum_set = TRUE;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_seq_num_15, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case PDCP_SN_LENGTH_18_BITS:
{
proto_item *ti;
guint8 reserved_value;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_polling, tvb, offset, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_reserved5, tvb, offset, 1, ENC_BIG_ENDIAN);
reserved_value = (first_byte & 0x3c) >> 2;
if (reserved_value != 0) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x%x - should be 0x0",
reserved_value);
}
seqnum = tvb_get_ntoh24(tvb, offset) & 0x03ffff;
seqnum_set = TRUE;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_seq_num_18, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
}
break;
default:
return 1;
}
write_pdu_label_and_info(root_ti, pinfo, " (SN=%u)", seqnum);
}
else {
guint8 control_pdu_type = (first_byte & 0x70) >> 4;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_control_pdu_type, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (control_pdu_type) {
case 0:
{
guint8 bits;
guint32 fms;
guint32 modulo;
guint not_received = 0;
guint sn, i, j, l;
guint32 len, bit_offset;
proto_tree *bitmap_tree;
proto_item *bitmap_ti = NULL;
gchar *buff = NULL;
#define BUFF_SIZE 57
if (p_pdcp_info->seqnum_length == PDCP_SN_LENGTH_12_BITS) {
fms = tvb_get_ntohs(tvb, offset) & 0x0fff;
sn = (fms + 1) % 4096;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_fms, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
modulo = 4096;
} else if (p_pdcp_info->seqnum_length == PDCP_SN_LENGTH_15_BITS) {
proto_item *ti;
guint8 reserved_value;
ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_reserved4, tvb, offset, 2, ENC_BIG_ENDIAN);
reserved_value = (tvb_get_ntohs(tvb, offset) & 0x0f80)>>7;
offset++;
if (reserved_value != 0) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x%x - should be 0x0",
reserved_value);
}
fms = tvb_get_ntohs(tvb, offset) & 0x7fff;
sn = (fms + 1) % 32768;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_fms2, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
modulo = 32768;
} else {
proto_item *ti;
guint8 reserved_value;
ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_reserved6, tvb, offset, 1, ENC_BIG_ENDIAN);
reserved_value = (tvb_get_guint8(tvb, offset) & 0x0c)>>2;
if (reserved_value != 0) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x%x - should be 0x0",
reserved_value);
}
fms = tvb_get_ntoh24(tvb, offset) & 0x3ffff;
sn = (fms + 1) % 262144;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_fms3, tvb,
offset, 3, ENC_BIG_ENDIAN);
offset += 3;
modulo = 262144;
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
bitmap_ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_bitmap, tvb,
offset, -1, ENC_NA);
bitmap_tree = proto_item_add_subtree(bitmap_ti, ett_pdcp_report_bitmap);
buff = (gchar *)wmem_alloc(wmem_packet_scope(), BUFF_SIZE);
len = tvb_reported_length_remaining(tvb, offset);
bit_offset = offset<<3;
for (i=0; i<len; i++) {
bits = tvb_get_bits8(tvb, bit_offset, 8);
for (l=0, j=0; l<8; l++) {
if ((bits << l) & 0x80) {
j += g_snprintf(&buff[j], BUFF_SIZE-j, "%6u,", (unsigned)(sn+(8*i)+l)%modulo);
} else {
j += g_snprintf(&buff[j], BUFF_SIZE-j, " ,");
not_received++;
}
}
proto_tree_add_uint_format(bitmap_tree, hf_pdcp_lte_bitmap_byte, tvb, bit_offset/8, 1, bits, "%s", buff);
bit_offset += 8;
}
}
if (bitmap_ti != NULL) {
proto_item_append_text(bitmap_ti, " (%u SNs not received)", not_received);
}
write_pdu_label_and_info(root_ti, pinfo, " Status Report (fms=%u) not-received=%u",
fms, not_received);
}
return 1;
case 1:
offset++;
break;
case 2:
{
guint32 fms;
guint32 nmp;
if (p_pdcp_info->seqnum_length == PDCP_SN_LENGTH_12_BITS) {
proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_fms, tvb,
offset, 2, ENC_BIG_ENDIAN, &fms);
offset += 2;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_hrw, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_nmp, tvb,
offset, 2, ENC_BIG_ENDIAN, &nmp);
offset += 2;
} else if (p_pdcp_info->seqnum_length == PDCP_SN_LENGTH_15_BITS) {
proto_item *ti;
guint32 reserved_value;
ti = proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_reserved4, tvb,
offset, 2, ENC_BIG_ENDIAN, &reserved_value);
offset++;
if (reserved_value != 0) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x%x - should be 0x0",
reserved_value);
}
proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_fms2, tvb,
offset, 2, ENC_BIG_ENDIAN, &fms);
offset += 2;
ti = proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_reserved7, tvb,
offset, 1, ENC_BIG_ENDIAN, &reserved_value);
if (reserved_value) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x1 - should be 0x0");
}
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_hrw2, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_reserved7, tvb,
offset, 1, ENC_BIG_ENDIAN, &reserved_value);
if (reserved_value) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x1 - should be 0x0");
}
proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_nmp2, tvb,
offset, 2, ENC_BIG_ENDIAN, &nmp);
offset += 2;
} else {
proto_item *ti;
guint32 reserved_value;
ti = proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_reserved6,
tvb, offset, 1, ENC_BIG_ENDIAN, &reserved_value);
if (reserved_value != 0) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x%x - should be 0x0",
reserved_value);
}
proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_fms3, tvb,
offset, 3, ENC_BIG_ENDIAN, &fms);
offset += 3;
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_hrw3, tvb,
offset, 3, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_reserved8,
tvb, offset, 1, ENC_BIG_ENDIAN, &reserved_value);
if (reserved_value != 0) {
expert_add_info_format(pinfo, ti, &ei_pdcp_lte_reserved_bits_not_zero,
"Reserved bits have value 0x%x - should be 0x0",
reserved_value);
}
proto_tree_add_item_ret_uint(pdcp_tree, hf_pdcp_lte_nmp3, tvb,
offset, 3, ENC_BIG_ENDIAN, &nmp);
offset += 3;
}
write_pdu_label_and_info(root_ti, pinfo, " LWA Status Report (fms=%u) not-received=%u",
fms, nmp);
}
return 1;
default:
return 1;
}
}
}
else {
write_pdu_label_and_info(root_ti, pinfo, " - INVALID PLANE (%u)",
p_pdcp_info->plane);
return 1;
}
if (seqnum_set) {
gboolean do_analysis = FALSE;
switch (global_pdcp_check_sequence_numbers) {
case FALSE:
break;
case SEQUENCE_ANALYSIS_RLC_ONLY:
if ((p_get_proto_data(wmem_file_scope(), pinfo, proto_rlc_lte, 0) != NULL) &&
!p_pdcp_info->is_retx) {
do_analysis = TRUE;
}
break;
case SEQUENCE_ANALYSIS_PDCP_ONLY:
if (p_get_proto_data(wmem_file_scope(), pinfo, proto_rlc_lte, 0) == NULL) {
do_analysis = TRUE;
}
break;
}
if (do_analysis) {
checkChannelSequenceInfo(pinfo, tvb, p_pdcp_info,
seqnum, pdcp_tree, security_tree,
&pdu_security_settings);
}
}
}
else {
write_pdu_label_and_info(root_ti, pinfo, " No-Header ");
}
payload_tvb = decipher_payload(tvb, pinfo, &offset, &pdu_security_settings, p_pdcp_info,
pdu_security ? pdu_security->seen_next_ul_pdu: FALSE, &payload_deciphered);
if (p_pdcp_info->plane == SIGNALING_PLANE) {
guint32 data_length;
guint32 mac;
proto_item *mac_ti;
guint32 calculated_digest = 0;
gboolean digest_was_calculated = FALSE;
data_length = tvb_reported_length_remaining(payload_tvb, offset) - ((p_pdcp_info->channelType == Channel_DCCH) ? 4 : 0);
if (global_pdcp_check_integrity && (p_pdcp_info->channelType == Channel_DCCH)) {
calculated_digest = calculate_digest(&pdu_security_settings, tvb_get_guint8(tvb, 0), payload_tvb,
offset, &digest_was_calculated);
}
if ((global_pdcp_dissect_signalling_plane_as_rrc) &&
((pdu_security == NULL) || (pdu_security->ciphering == eea0) || payload_deciphered || !pdu_security->seen_next_ul_pdu)) {
dissector_handle_t rrc_handle = lookup_rrc_dissector_handle(p_pdcp_info);
if (rrc_handle != 0) {
tvbuff_t *rrc_payload_tvb = tvb_new_subset_length(payload_tvb, offset, data_length);
gboolean was_writable = col_get_writable(pinfo->cinfo, COL_INFO);
col_set_writable(pinfo->cinfo, COL_INFO, TRUE);
call_dissector_only(rrc_handle, rrc_payload_tvb, pinfo, pdcp_tree, NULL);
col_set_writable(pinfo->cinfo, COL_INFO, was_writable);
}
else {
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_signalling_data, payload_tvb, offset,
data_length, ENC_NA);
}
if (!pinfo->fd->flags.visited &&
(current_security != NULL) && !current_security->seen_next_ul_pdu &&
p_pdcp_info->direction == DIRECTION_UPLINK)
{
current_security->seen_next_ul_pdu = TRUE;
}
}
else {
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_signalling_data, payload_tvb, offset,
data_length, ENC_NA);
}
offset += data_length;
if (p_pdcp_info->channelType == Channel_DCCH) {
mac = tvb_get_ntohl(payload_tvb, offset);
mac_ti = proto_tree_add_item(pdcp_tree, hf_pdcp_lte_mac, payload_tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (digest_was_calculated) {
if (mac != calculated_digest) {
expert_add_info_format(pinfo, mac_ti, &ei_pdcp_lte_digest_wrong,
"MAC-I Digest wrong expected %08x but found %08x",
calculated_digest, mac);
}
else {
proto_item_append_text(mac_ti, " [Matches calculated result]");
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, " MAC=0x%08x (%u bytes data)",
mac, data_length);
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "(%u bytes data)", data_length);
}
}
else if (tvb_captured_length_remaining(payload_tvb, offset)) {
if (!p_pdcp_info->rohc.rohc_compression) {
gint payload_length = tvb_reported_length_remaining(payload_tvb, offset);
if (payload_length > 0) {
if (p_pdcp_info->plane == USER_PLANE) {
if (global_pdcp_dissect_user_plane_as_ip &&
((pdu_security == NULL) || (pdu_security->ciphering == eea0) || payload_deciphered))
{
tvbuff_t *ip_payload_tvb = tvb_new_subset_remaining(payload_tvb, offset);
if (global_pdcp_lte_layer_to_show != ShowTrafficLayer) {
col_set_writable(pinfo->cinfo, COL_INFO, FALSE);
}
switch (tvb_get_guint8(ip_payload_tvb, 0) & 0xf0) {
case 0x40:
call_dissector_only(ip_handle, ip_payload_tvb, pinfo, pdcp_tree, NULL);
break;
case 0x60:
call_dissector_only(ipv6_handle, ip_payload_tvb, pinfo, pdcp_tree, NULL);
break;
default:
call_data_dissector(ip_payload_tvb, pinfo, pdcp_tree);
break;
}
if (global_pdcp_lte_layer_to_show == ShowTrafficLayer) {
col_set_writable(pinfo->cinfo, COL_INFO, FALSE);
}
}
else {
proto_tree_add_item(pdcp_tree, hf_pdcp_lte_user_plane_data, payload_tvb, offset, -1, ENC_NA);
}
}
write_pdu_label_and_info(root_ti, pinfo, "(%u bytes data)",
payload_length);
}
col_set_writable(pinfo->cinfo, COL_INFO, global_pdcp_lte_layer_to_show == ShowRLCLayer);
return tvb_captured_length(tvb);
}
else {
if (!global_pdcp_dissect_rohc) {
col_append_fstr(pinfo->cinfo, COL_PROTOCOL, "|ROHC(%s)",
val_to_str_const(p_pdcp_info->rohc.profile, rohc_profile_vals, "Unknown"));
return 1;
}
rohc_tvb = tvb_new_subset_remaining(payload_tvb, offset);
if (global_pdcp_lte_layer_to_show != ShowTrafficLayer) {
col_set_writable(pinfo->cinfo, COL_INFO, FALSE);
}
else {
col_clear(pinfo->cinfo, COL_INFO);
}
call_dissector_with_data(rohc_handle, rohc_tvb, pinfo, tree, &p_pdcp_info->rohc);
col_set_writable(pinfo->cinfo, COL_INFO, global_pdcp_lte_layer_to_show == ShowRLCLayer);
}
}
return tvb_captured_length(tvb);
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
{ &hf_pdcp_lte_seq_num_15,
{ "Seq Num",
"pdcp-lte.seq-num", FT_UINT16, BASE_DEC, NULL, 0x7fff,
"PDCP Seq num", HFILL
}
},
{ &hf_pdcp_lte_polling,
{ "Polling",
"pdcp-lte.polling", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL
}
},
{ &hf_pdcp_lte_reserved5,
{ "Reserved",
"pdcp-lte.reserved5", FT_UINT8, BASE_HEX, NULL, 0x3c,
"4 reserved bits", HFILL
}
},
{ &hf_pdcp_lte_seq_num_18,
{ "Seq Num",
"pdcp-lte.seq-num", FT_UINT24, BASE_DEC, NULL, 0x3ffff,
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
"pdcp-lte.mac", FT_UINT32, BASE_HEX, NULL, 0x0,
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
{ &hf_pdcp_lte_reserved4,
{ "Reserved",
"pdcp-lte.reserved4", FT_UINT16, BASE_HEX, NULL, 0x0f80,
"5 reserved bits", HFILL
}
},
{ &hf_pdcp_lte_fms2,
{ "First Missing Sequence Number",
"pdcp-lte.fms", FT_UINT16, BASE_DEC, NULL, 0x07fff,
"First Missing PDCP Sequence Number", HFILL
}
},
{ &hf_pdcp_lte_reserved6,
{ "Reserved",
"pdcp-lte.reserved6", FT_UINT8, BASE_HEX, NULL, 0x0c,
"2 reserved bits", HFILL
}
},
{ &hf_pdcp_lte_fms3,
{ "First Missing Sequence Number",
"pdcp-lte.fms", FT_UINT24, BASE_DEC, NULL, 0x03ffff,
"First Missing PDCP Sequence Number", HFILL
}
},
{ &hf_pdcp_lte_bitmap,
{ "Bitmap",
"pdcp-lte.bitmap", FT_NONE, BASE_NONE, NULL, 0x0,
"Status report bitmap (0=error, 1=OK)", HFILL
}
},
{ &hf_pdcp_lte_bitmap_byte,
{ "Bitmap byte",
"pdcp-lte.bitmap.byte", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_hrw,
{ "Highest Received Sequence Number on WLAN",
"pdcp-lte.hwr", FT_UINT16, BASE_DEC, NULL, 0xfff0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_nmp,
{ "Number of Missing PDCP PDUs",
"pdcp-lte.nmp", FT_UINT16, BASE_DEC, NULL, 0x0fff,
NULL, HFILL
}
},
{ &hf_pdcp_lte_reserved7,
{ "Reserved",
"pdcp-lte.reserved7", FT_UINT8, BASE_HEX, NULL, 0x80,
"1 reserved bit", HFILL
}
},
{ &hf_pdcp_lte_hrw2,
{ "Highest Received Sequence Number on WLAN",
"pdcp-lte.hwr", FT_UINT16, BASE_DEC, NULL, 0x7fff,
NULL, HFILL
}
},
{ &hf_pdcp_lte_nmp2,
{ "Number of Missing PDCP PDUs",
"pdcp-lte.nmp", FT_UINT16, BASE_DEC, NULL, 0x7fff,
NULL, HFILL
}
},
{ &hf_pdcp_lte_hrw3,
{ "Highest Received Sequence Number on WLAN",
"pdcp-lte.hwr", FT_UINT24, BASE_DEC, NULL, 0xffffc0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_reserved8,
{ "Reserved",
"pdcp-lte.reserved8", FT_UINT8, BASE_HEX, NULL, 0x3c,
"4 reserved bits", HFILL
}
},
{ &hf_pdcp_lte_nmp3,
{ "Number of Missing PDCP PDUs",
"pdcp-lte.nmp", FT_UINT24, BASE_DEC, NULL, 0x03ffff,
NULL, HFILL
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
"pdcp-lte.sequence-analysis.expected-sn", FT_UINT32, BASE_DEC, 0, 0x0,
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
{ &hf_pdcp_lte_security,
{ "Security Config",
"pdcp-lte.security-cofig", FT_STRING, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_security_setup_frame,
{ "Configuration frame",
"pdcp-lte.security-config.setup-frame", FT_FRAMENUM, BASE_NONE, 0, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_security_integrity_algorithm,
{ "Integrity Algorithm",
"pdcp-lte.security-config.integrity", FT_UINT16, BASE_DEC, VALS(integrity_algorithm_vals), 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_security_ciphering_algorithm,
{ "Ciphering Algorithm",
"pdcp-lte.security-config.ciphering", FT_UINT16, BASE_DEC, VALS(ciphering_algorithm_vals), 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_security_bearer,
{ "BEARER",
"pdcp-lte.security-config.bearer", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_security_direction,
{ "DIRECTION",
"pdcp-lte.security-config.direction", FT_UINT8, BASE_DEC, VALS(direction_vals), 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_security_count,
{ "COUNT",
"pdcp-lte.security-config.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_security_cipher_key,
{ "CIPHER KEY",
"pdcp-lte.security-config.cipher-key", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_pdcp_lte_security_integrity_key,
{ "INTEGRITY KEY",
"pdcp-lte.security-config.integrity-key", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_pdcp,
&ett_pdcp_configuration,
&ett_pdcp_packet,
&ett_pdcp_lte_sequence_analysis,
&ett_pdcp_report_bitmap,
&ett_pdcp_security
};
static ei_register_info ei[] = {
{ &ei_pdcp_lte_sequence_analysis_sn_missing, { "pdcp-lte.sequence-analysis.sn-missing", PI_SEQUENCE, PI_WARN, "PDCP SN missing", EXPFILL }},
{ &ei_pdcp_lte_sequence_analysis_sn_repeated, { "pdcp-lte.sequence-analysis.sn-repeated", PI_SEQUENCE, PI_WARN, "PDCP SN repeated", EXPFILL }},
{ &ei_pdcp_lte_sequence_analysis_wrong_sequence_number, { "pdcp-lte.sequence-analysis.wrong-sequence-number", PI_SEQUENCE, PI_WARN, "Wrong Sequence Number", EXPFILL }},
{ &ei_pdcp_lte_reserved_bits_not_zero, { "pdcp-lte.reserved-bits-not-zero", PI_MALFORMED, PI_ERROR, "Reserved bits not zero", EXPFILL }},
{ &ei_pdcp_lte_digest_wrong, { "pdcp-lte.maci-wrong", PI_SEQUENCE, PI_ERROR, "MAC-I doesn't match expected value", EXPFILL }}
};
static const enum_val_t sequence_analysis_vals[] = {
{"no-analysis", "No-Analysis", FALSE},
{"rlc-only", "Only-RLC-frames", SEQUENCE_ANALYSIS_RLC_ONLY},
{"pdcp-only", "Only-PDCP-frames", SEQUENCE_ANALYSIS_PDCP_ONLY},
{NULL, NULL, -1}
};
static const enum_val_t show_info_col_vals[] = {
{"show-rlc", "RLC Info", ShowRLCLayer},
{"show-pdcp", "PDCP Info", ShowPDCPLayer},
{"show-traffic", "Traffic Info", ShowTrafficLayer},
{NULL, NULL, -1}
};
static const enum_val_t default_ciphering_algorithm_vals[] = {
{"eea0", "EEA0 (NULL)", eea0},
{"eea1", "EEA1 (SNOW3G)", eea1},
{"eea2", "EEA2 (AES)", eea2},
{"eea3", "EEA3 (ZUC)", eea3},
{NULL, NULL, -1}
};
static const enum_val_t default_integrity_algorithm_vals[] = {
{"eia0", "EIA0 (NULL)", eia0},
{"eia1", "EIA1 (SNOW3G)", eia1},
{"eia2", "EIA2 (AES)", eia2},
{"eia3", "EIA3 (ZUC)", eia3},
{NULL, NULL, -1}
};
static uat_field_t ue_keys_uat_flds[] = {
UAT_FLD_DEC(uat_ue_keys_records, ueid, "UEId", "UE Identifier of UE associated with keys"),
UAT_FLD_CSTRING(uat_ue_keys_records, rrcCipherKeyString, "RRC Cipher Key", "Key for deciphering signalling messages"),
UAT_FLD_CSTRING(uat_ue_keys_records, upCipherKeyString, "User-Plane Cipher Key", "Key for deciphering user-plane messages"),
UAT_FLD_CSTRING(uat_ue_keys_records, rrcIntegrityKeyString, "RRC Integrity Key", "Key for deciphering user-plane messages"),
UAT_END_FIELDS
};
module_t *pdcp_lte_module;
expert_module_t* expert_pdcp_lte;
proto_pdcp_lte = proto_register_protocol("PDCP-LTE", "PDCP-LTE", "pdcp-lte");
proto_register_field_array(proto_pdcp_lte, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pdcp_lte = expert_register_protocol(proto_pdcp_lte);
expert_register_field_array(expert_pdcp_lte, ei, array_length(ei));
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
prefs_register_obsolete_preference(pdcp_lte_module, "heuristic_pdcp_lte_over_udp");
prefs_register_enum_preference(pdcp_lte_module, "layer_to_show",
"Which layer info to show in Info column",
"Can show RLC, PDCP or Traffic layer info in Info column",
&global_pdcp_lte_layer_to_show, show_info_col_vals, FALSE);
ue_keys_uat = uat_new("PDCP UE security keys",
sizeof(uat_ue_keys_record_t),
"pdcp_lte_ue_keys",
TRUE,
&uat_ue_keys_records,
&num_ue_keys_uat,
UAT_AFFECTS_DISSECTION,
NULL,
uat_ue_keys_record_copy_cb,
uat_ue_keys_record_update_cb,
uat_ue_keys_record_free_cb,
NULL,
NULL,
ue_keys_uat_flds);
prefs_register_uat_preference(pdcp_lte_module,
"ue_keys_table",
"PDCP UE Keys",
"Preconfigured PDCP keys",
ue_keys_uat);
prefs_register_enum_preference(pdcp_lte_module, "default_ciphering_algorithm",
"Ciphering algorithm to use if not signalled",
"If RRC Security Info not seen, e.g. in Handover",
(gint*)&global_default_ciphering_algorithm, default_ciphering_algorithm_vals, FALSE);
prefs_register_enum_preference(pdcp_lte_module, "default_integrity_algorithm",
"Integrity algorithm to use if not signalled",
"If RRC Security Info not seen, e.g. in Handover",
(gint*)&global_default_integrity_algorithm, default_integrity_algorithm_vals, FALSE);
prefs_register_bool_preference(pdcp_lte_module, "decipher_signalling",
"Attempt to decipher Signalling (RRC) SDUs",
"N.B. only possible if build with algorithm support, and have key available and configured",
&global_pdcp_decipher_signalling);
prefs_register_bool_preference(pdcp_lte_module, "decipher_userplane",
"Attempt to decipher User-plane (IP) SDUs",
"N.B. only possible if build with algorithm support, and have key available and configured",
&global_pdcp_decipher_userplane);
prefs_register_bool_preference(pdcp_lte_module, "verify_integrity",
"Attempt to check integrity calculation",
"N.B. only possible if build with algorithm support, and have key available and configured",
&global_pdcp_check_integrity);
prefs_register_bool_preference(pdcp_lte_module, "ignore_rrc_sec_params",
"Ignore RRC security parameters",
"Ignore the LTE RRC security algorithm configuration, to be used when PDCP is already deciphered in the capture",
&global_pdcp_ignore_sec);
pdcp_sequence_analysis_channel_hash = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), g_direct_hash, g_direct_equal);
pdcp_lte_sequence_analysis_report_hash = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), pdcp_result_hash_func, pdcp_result_hash_equal);
pdcp_security_hash = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), pdcp_lte_ueid_hash_func, pdcp_lte_ueid_hash_equal);
pdcp_security_result_hash = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), pdcp_lte_ueid_frame_hash_func, pdcp_lte_ueid_frame_hash_equal);
pdcp_security_key_hash = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), pdcp_lte_ueid_hash_func, pdcp_lte_ueid_hash_equal);
}
void proto_reg_handoff_pdcp_lte(void)
{
heur_dissector_add("udp", dissect_pdcp_lte_heur, "PDCP-LTE over UDP", "pdcp_lte_udp", proto_pdcp_lte, HEURISTIC_DISABLE);
ip_handle = find_dissector_add_dependency("ip", proto_pdcp_lte);
ipv6_handle = find_dissector_add_dependency("ipv6", proto_pdcp_lte);
rohc_handle = find_dissector_add_dependency("rohc", proto_pdcp_lte);
lte_rrc_ul_ccch = find_dissector_add_dependency("lte_rrc.ul_ccch", proto_pdcp_lte);
lte_rrc_dl_ccch = find_dissector_add_dependency("lte_rrc.dl_ccch", proto_pdcp_lte);
lte_rrc_pcch = find_dissector_add_dependency("lte_rrc.pcch", proto_pdcp_lte);
lte_rrc_bcch_bch = find_dissector_add_dependency("lte_rrc.bcch_bch", proto_pdcp_lte);
lte_rrc_bcch_dl_sch = find_dissector_add_dependency("lte_rrc.bcch_dl_sch", proto_pdcp_lte);
lte_rrc_ul_dcch = find_dissector_add_dependency("lte_rrc.ul_dcch", proto_pdcp_lte);
lte_rrc_dl_dcch = find_dissector_add_dependency("lte_rrc.dl_dcch", proto_pdcp_lte);
lte_rrc_ul_ccch_nb = find_dissector_add_dependency("lte_rrc.ul_ccch.nb", proto_pdcp_lte);
lte_rrc_dl_ccch_nb = find_dissector_add_dependency("lte_rrc.dl_ccch.nb", proto_pdcp_lte);
lte_rrc_pcch_nb = find_dissector_add_dependency("lte_rrc.pcch.nb", proto_pdcp_lte);
lte_rrc_bcch_bch_nb = find_dissector_add_dependency("lte_rrc.bcch_bch.nb", proto_pdcp_lte);
lte_rrc_bcch_dl_sch_nb = find_dissector_add_dependency("lte_rrc.bcch_dl_sch.nb", proto_pdcp_lte);
lte_rrc_ul_dcch_nb = find_dissector_add_dependency("lte_rrc.ul_dcch.nb", proto_pdcp_lte);
lte_rrc_dl_dcch_nb = find_dissector_add_dependency("lte_rrc.dl_dcch.nb", proto_pdcp_lte);
}
