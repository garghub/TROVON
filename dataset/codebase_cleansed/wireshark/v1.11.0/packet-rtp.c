static void
rtp_fragment_init(void)
{
reassembly_table_init(&rtp_reassembly_table,
&addresses_reassembly_table_functions);
}
void
rtp_free_hash_dyn_payload(GHashTable *rtp_dyn_payload)
{
if (rtp_dyn_payload == NULL) return;
g_hash_table_destroy(rtp_dyn_payload);
rtp_dyn_payload = NULL;
}
void
srtp_add_address(packet_info *pinfo, address *addr, int port, int other_port,
const gchar *setup_method, guint32 setup_frame_number,
gboolean is_video _U_, GHashTable *rtp_dyn_payload,
struct srtp_info *srtp_info)
{
address null_addr;
conversation_t* p_conv;
struct _rtp_conversation_info *p_conv_data = NULL;
if (pinfo->fd->flags.visited)
{
return;
}
#ifdef DEBUG
printf("#%u: %srtp_add_address(%s, %u, %u, %s, %u\n",
pinfo->fd->num, (srtp_info)?"s":"", ep_address_to_str(addr), port,
other_port, setup_method, setup_frame_number);
#endif
SET_ADDRESS(&null_addr, AT_NONE, 0, NULL);
p_conv = find_conversation(setup_frame_number, addr, &null_addr, PT_UDP, port, other_port,
NO_ADDR_B | (!other_port ? NO_PORT_B : 0));
if (!p_conv || p_conv->setup_frame != setup_frame_number) {
p_conv = conversation_new(setup_frame_number, addr, &null_addr, PT_UDP,
(guint32)port, (guint32)other_port,
NO_ADDR2 | (!other_port ? NO_PORT2 : 0));
}
conversation_set_dissector(p_conv, rtp_handle);
p_conv_data = (struct _rtp_conversation_info *)conversation_get_proto_data(p_conv, proto_rtp);
if (! p_conv_data) {
p_conv_data = wmem_new(wmem_file_scope(), struct _rtp_conversation_info);
p_conv_data->rtp_dyn_payload = NULL;
p_conv_data->extended_seqno = 0x10000;
p_conv_data->rtp_conv_info = wmem_new(wmem_file_scope(), rtp_private_conv_info);
p_conv_data->rtp_conv_info->multisegment_pdus = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(p_conv, proto_rtp, p_conv_data);
}
rtp_free_hash_dyn_payload(p_conv_data->rtp_dyn_payload);
g_strlcpy(p_conv_data->method, setup_method, MAX_RTP_SETUP_METHOD_SIZE+1);
p_conv_data->frame_number = setup_frame_number;
p_conv_data->is_video = is_video;
p_conv_data->rtp_dyn_payload = rtp_dyn_payload;
p_conv_data->srtp_info = srtp_info;
}
void
rtp_add_address(packet_info *pinfo, address *addr, int port, int other_port,
const gchar *setup_method, guint32 setup_frame_number,
gboolean is_video , GHashTable *rtp_dyn_payload)
{
srtp_add_address(pinfo, addr, port, other_port, setup_method, setup_frame_number, is_video, rtp_dyn_payload, NULL);
}
static gboolean
dissect_rtp_heur_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean check_destport)
{
guint8 octet1;
unsigned int version;
unsigned int offset = 0;
if (! global_rtp_heur)
return FALSE;
octet1 = tvb_get_guint8( tvb, offset );
version = RTP_VERSION( octet1 );
if (version == 0) {
if (!(tvb_memeql(tvb, 4, "ZRTP", 4)))
{
call_dissector_only(zrtp_handle, tvb, pinfo, tree, NULL);
return TRUE;
} else {
switch (global_rtp_version0_type) {
case RTP0_STUN:
return call_dissector_only(stun_heur_handle, tvb, pinfo, tree, NULL);
case RTP0_CLASSICSTUN:
return call_dissector_only(classicstun_heur_handle, tvb, pinfo, tree, NULL);
case RTP0_T38:
call_dissector_only(t38_handle, tvb, pinfo, tree, NULL);
return TRUE;
case RTP0_SPRT:
call_dissector_only(sprt_handle, tvb, pinfo, tree, NULL);
return TRUE;
case RTP0_INVALID:
default:
return FALSE;
}
}
} else if (version != 2) {
return FALSE;
}
if (check_destport && ((pinfo->destport % 2) != 0)) {
return FALSE;
}
dissect_rtp( tvb, pinfo, tree );
return TRUE;
}
static gboolean
dissect_rtp_heur_udp( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ )
{
return dissect_rtp_heur_common(tvb, pinfo, tree, TRUE);
}
static gboolean
dissect_rtp_heur_stun( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ )
{
return dissect_rtp_heur_common(tvb, pinfo, tree, FALSE);
}
static void
process_rtp_payload(tvbuff_t *newtvb, packet_info *pinfo, proto_tree *tree,
proto_tree *rtp_tree,
unsigned int payload_type)
{
struct _rtp_conversation_info *p_conv_data = NULL;
gboolean found_match = FALSE;
int payload_len;
struct srtp_info *srtp_info;
int offset=0;
payload_len = tvb_length_remaining(newtvb, offset);
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(pinfo->fd, proto_rtp, 0);
if (p_conv_data && p_conv_data->srtp_info) {
srtp_info = p_conv_data->srtp_info;
payload_len -= srtp_info->mki_len + srtp_info->auth_tag_len;
#if 0
#error Currently the srtp_info structure contains no cipher data, see packet-sdp.c adding dummy_srtp_info structure
if (p_conv_data->srtp_info->encryption_algorithm==SRTP_ENC_ALG_NULL) {
if (rtp_tree)
proto_tree_add_text(rtp_tree, newtvb, offset, payload_len, "SRTP Payload with NULL encryption");
}
else
#endif
{
if (rtp_tree)
proto_tree_add_item(rtp_tree, hf_srtp_encrypted_payload, newtvb, offset, payload_len, ENC_NA);
found_match = TRUE;
}
offset += payload_len;
if (srtp_info->mki_len) {
proto_tree_add_item(rtp_tree, hf_srtp_mki, newtvb, offset, srtp_info->mki_len, ENC_NA);
offset += srtp_info->mki_len;
}
if (srtp_info->auth_tag_len) {
proto_tree_add_item(rtp_tree, hf_srtp_auth_tag, newtvb, offset, srtp_info->auth_tag_len, ENC_NA);
}
}
else if ( (payload_type >= PT_UNDF_96 && payload_type <= PT_UNDF_127) ) {
if (p_conv_data && p_conv_data->rtp_dyn_payload) {
gchar *payload_type_str = NULL;
encoding_name_and_rate_t *encoding_name_and_rate_pt = NULL;
encoding_name_and_rate_pt = (encoding_name_and_rate_t *)g_hash_table_lookup(p_conv_data->rtp_dyn_payload, &payload_type);
if (encoding_name_and_rate_pt) {
payload_type_str = encoding_name_and_rate_pt->encoding_name;
}
if (payload_type_str){
found_match = dissector_try_string(rtp_dyn_pt_dissector_table,
payload_type_str, newtvb, pinfo, tree);
if(found_match==FALSE)
proto_tree_add_item( rtp_tree, hf_rtp_data, newtvb, 0, -1, ENC_NA );
return;
}
}
}
if (!found_match && !dissector_try_uint(rtp_pt_dissector_table, payload_type, newtvb, pinfo, tree))
proto_tree_add_item( rtp_tree, hf_rtp_data, newtvb, 0, -1, ENC_NA );
}
static void
dissect_rtp_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *rtp_tree, int offset, unsigned int data_len,
unsigned int data_reported_len,
unsigned int payload_type)
{
tvbuff_t *newtvb;
struct _rtp_conversation_info *p_conv_data= NULL;
gboolean must_desegment = FALSE;
rtp_private_conv_info *finfo = NULL;
rtp_multisegment_pdu *msp = NULL;
guint32 seqno;
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(pinfo->fd, proto_rtp, 0);
if(p_conv_data != NULL)
finfo = p_conv_data->rtp_conv_info;
if(finfo == NULL || !desegment_rtp) {
newtvb=tvb_new_subset(tvb,offset,data_len,data_reported_len);
process_rtp_payload(newtvb, pinfo, tree, rtp_tree, payload_type);
return;
}
seqno = p_conv_data->extended_seqno;
pinfo->can_desegment = 2;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
#ifdef DEBUG_FRAGMENTS
g_debug("%d: RTP Part of convo %d(%p); seqno %d",
pinfo->fd->num,
p_conv_data->frame_number, p_conv_data,
seqno
);
#endif
msp = (rtp_multisegment_pdu *)wmem_tree_lookup32_le(finfo->multisegment_pdus,seqno-1);
if(msp && msp->startseq < seqno && msp->endseq >= seqno) {
guint32 fid = msp->startseq;
fragment_head *fd_head;
#ifdef DEBUG_FRAGMENTS
g_debug("\tContinues fragment %d", fid);
#endif
fd_head = fragment_add_seq(&rtp_reassembly_table,
tvb, offset, pinfo, fid, NULL,
seqno-msp->startseq, data_len,
FALSE, 0);
newtvb = process_reassembled_data(tvb,offset, pinfo, "Reassembled RTP", fd_head,
&rtp_fragment_items, NULL, tree);
#ifdef DEBUG_FRAGMENTS
g_debug("\tFragment Coalesced; fd_head=%p, newtvb=%p (len %d)",fd_head, newtvb,
newtvb?tvb_reported_length(newtvb):0);
#endif
if(newtvb != NULL) {
process_rtp_payload(newtvb, pinfo, tree, rtp_tree, payload_type);
if( pinfo->desegment_len && pinfo->desegment_offset == 0 )
{
#ifdef DEBUG_FRAGMENTS
g_debug("\tNo complete pdus in payload" );
#endif
fragment_set_partial_reassembly(&rtp_reassembly_table,
pinfo, fid, NULL);
msp->endseq = MIN(msp->endseq,seqno) + 1;
}
else
{
if(pinfo->desegment_len)
{
must_desegment = TRUE;
}
}
}
}
else
{
#ifdef DEBUG_FRAGMENTS
g_debug("\tRTP non-fragment payload");
#endif
newtvb = tvb_new_subset( tvb, offset, data_len, data_reported_len );
process_rtp_payload(newtvb, pinfo, tree, rtp_tree, payload_type);
if(pinfo->desegment_len) {
must_desegment = TRUE;
}
}
if(must_desegment)
{
guint32 deseg_offset = pinfo->desegment_offset;
guint32 frag_len = tvb_reported_length_remaining(newtvb, deseg_offset);
fragment_head *fd_head = NULL;
#ifdef DEBUG_FRAGMENTS
g_debug("\tRTP Must Desegment: tvb_len=%d ds_len=%d %d frag_len=%d ds_off=%d",
tvb_reported_length(newtvb),
pinfo->desegment_len,
pinfo->fd->flags.visited,
frag_len,
deseg_offset);
#endif
msp = wmem_new(wmem_file_scope(), rtp_multisegment_pdu);
msp->startseq = seqno;
msp->endseq = seqno+1;
wmem_tree_insert32(finfo->multisegment_pdus,seqno,msp);
fd_head = fragment_add_seq(&rtp_reassembly_table,
newtvb, deseg_offset, pinfo, seqno, NULL, 0, frag_len,
TRUE, 0);
if(fd_head != NULL)
{
if( fd_head->reassembled_in != 0 && !(fd_head->flags & FD_PARTIAL_REASSEMBLY) )
{
proto_item *rtp_tree_item;
rtp_tree_item = proto_tree_add_uint( tree, hf_rtp_reassembled_in,
newtvb, deseg_offset, tvb_reported_length_remaining(newtvb,deseg_offset),
fd_head->reassembled_in);
PROTO_ITEM_SET_GENERATED(rtp_tree_item);
#ifdef DEBUG_FRAGMENTS
g_debug("\tReassembled in %d", fd_head->reassembled_in);
#endif
}
else
{
#ifdef DEBUG_FRAGMENTS
g_debug("\tUnfinished fragment");
#endif
proto_tree_add_text( tree, tvb, deseg_offset, -1,"RTP fragment, unfinished");
}
}
else
{
#ifdef DEBUG_FRAGMENTS
g_debug("\tnew pdu");
#endif
}
if( pinfo->desegment_offset == 0 )
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTP");
col_set_str(pinfo->cinfo, COL_INFO, "[RTP segment of a reassembled PDU]");
}
}
pinfo->can_desegment = 0;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
}
static void
dissect_rtp_rfc2198(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 octet1;
int cnt;
gboolean hdr_follow = TRUE;
proto_item *ti = NULL;
proto_tree *rfc2198_tree = NULL;
proto_tree *rfc2198_hdr_tree = NULL;
rfc2198_hdr *hdr_last, *hdr_new;
rfc2198_hdr *hdr_chain = NULL;
struct _rtp_conversation_info *p_conv_data= NULL;
gchar *payload_type_str;
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(pinfo->fd, proto_rtp, 0);
ti = proto_tree_add_text(tree, tvb, offset, -1, "RFC 2198: Redundant Audio Data");
rfc2198_tree = proto_item_add_subtree(ti, ett_rtp_rfc2198);
hdr_last = NULL;
cnt = 0;
while (hdr_follow) {
cnt++;
payload_type_str = NULL;
hdr_new = wmem_new(wmem_packet_scope(), rfc2198_hdr);
hdr_new->next = NULL;
octet1 = tvb_get_guint8(tvb, offset);
hdr_new->pt = RTP_PAYLOAD_TYPE(octet1);
hdr_follow = (octet1 & 0x80);
if ((hdr_new->pt > 95) && (hdr_new->pt < 128)) {
if (p_conv_data && p_conv_data->rtp_dyn_payload){
encoding_name_and_rate_t *encoding_name_and_rate_pt = NULL;
encoding_name_and_rate_pt = (encoding_name_and_rate_t *)g_hash_table_lookup(p_conv_data->rtp_dyn_payload, &hdr_new->pt);
if (encoding_name_and_rate_pt) {
payload_type_str = encoding_name_and_rate_pt->encoding_name;
}
}
}
ti = proto_tree_add_text(rfc2198_tree, tvb, offset, (hdr_follow)?4:1, "Header %u", cnt);
rfc2198_hdr_tree = proto_item_add_subtree(ti, ett_rtp_rfc2198_hdr);
proto_tree_add_item(rfc2198_hdr_tree, hf_rtp_rfc2198_follow, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_uint_format_value(rfc2198_hdr_tree, hf_rtp_payload_type, tvb,
offset, 1, octet1, "%s (%u)",
payload_type_str ? payload_type_str : val_to_str_ext_const(hdr_new->pt, &rtp_payload_type_vals_ext, "Unknown"),
hdr_new->pt);
proto_item_append_text(ti, ": PT=%s",
payload_type_str ? payload_type_str :
val_to_str_ext(hdr_new->pt, &rtp_payload_type_vals_ext, "Unknown (%u)"));
offset += 1;
if (hdr_follow) {
proto_tree_add_item(rfc2198_hdr_tree, hf_rtp_rfc2198_tm_off, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item(rfc2198_hdr_tree, hf_rtp_rfc2198_bl_len, tvb, offset + 1, 2, ENC_BIG_ENDIAN );
hdr_new->len = tvb_get_ntohs(tvb, offset + 1) & 0x03FF;
proto_item_append_text(ti, ", len=%u", hdr_new->len);
offset += 3;
} else {
hdr_new->len = -1;
hdr_follow = FALSE;
}
if (hdr_last) {
hdr_last->next = hdr_new;
} else {
hdr_chain = hdr_new;
}
hdr_last = hdr_new;
}
hdr_last = hdr_chain;
while (hdr_last) {
hdr_last->offset = offset;
if (!hdr_last->next) {
hdr_last->len = tvb_reported_length_remaining(tvb, offset);
}
dissect_rtp_data(tvb, pinfo, tree, rfc2198_tree, hdr_last->offset, hdr_last->len, hdr_last->len, hdr_last->pt);
offset += hdr_last->len;
hdr_last = hdr_last->next;
}
}
static void
dissect_rtp_hext_rfc5215_onebyte( tvbuff_t *tvb, packet_info *pinfo,
proto_tree *rtp_hext_tree )
{
proto_item *ti = NULL;
proto_tree *rtp_hext_rfc5285_tree = NULL;
guint ext_offset = 0, start_ext_offset;
while (ext_offset < tvb_length (tvb)) {
guint8 ext_hdr_hdr;
guint8 ext_id;
guint8 ext_length;
tvbuff_t *subtvb = NULL;
start_ext_offset = ext_offset;
while (tvb_get_guint8 (tvb, ext_offset) == 0) {
ext_offset ++;
if (ext_offset >= tvb_length (tvb))
return;
}
if (ext_offset > start_ext_offset)
proto_tree_add_item(rtp_hext_tree, hf_rtp_padding_data, tvb, ext_offset, ext_offset-start_ext_offset, ENC_NA );
ext_hdr_hdr = tvb_get_guint8 (tvb, ext_offset);
ext_id = ext_hdr_hdr >> 4;
if (ext_id == 15)
return;
ext_length = (ext_hdr_hdr & 0x0F) + 1;
if (rtp_hext_tree) {
ti = proto_tree_add_text(rtp_hext_tree, tvb, ext_offset, ext_length + 1, "RFC 5285 Header Extension (One-Byte Header)");
rtp_hext_rfc5285_tree = proto_item_add_subtree( ti, ett_hdr_ext_rfc5285);
proto_tree_add_uint( rtp_hext_rfc5285_tree, hf_rtp_ext_rfc5285_id, tvb, ext_offset, 1, ext_id);
proto_tree_add_uint( rtp_hext_rfc5285_tree, hf_rtp_ext_rfc5285_length, tvb, ext_offset, 1, ext_length);
}
ext_offset ++;
subtvb = tvb_new_subset(tvb, ext_offset, ext_length, ext_length);
if (!dissector_try_uint (rtp_hdr_ext_rfc5285_dissector_table, ext_id, subtvb, pinfo, rtp_hext_rfc5285_tree)) {
if (rtp_hext_tree)
proto_tree_add_item(rtp_hext_rfc5285_tree, hf_rtp_ext_rfc5285_data, subtvb, 0, ext_length, ENC_NA );
}
ext_offset += ext_length;
}
}
static void
dissect_rtp_hext_rfc5215_twobytes(tvbuff_t *parent_tvb, guint id_offset,
guint8 id, tvbuff_t *tvb, packet_info *pinfo, proto_tree *rtp_hext_tree)
{
proto_item *ti = NULL;
proto_tree *rtp_hext_rfc5285_tree = NULL;
guint ext_offset = 0, start_ext_offset;
while (ext_offset + 2 < tvb_length (tvb)) {
guint8 ext_id;
guint8 ext_length;
tvbuff_t *subtvb = NULL;
start_ext_offset = ext_offset;
while (tvb_get_guint8 (tvb, ext_offset) == 0) {
if (ext_offset + 2 >= tvb_length (tvb))
return;
ext_offset ++;
}
if (ext_offset > start_ext_offset)
proto_tree_add_item(rtp_hext_tree, hf_rtp_padding_data, tvb, ext_offset, ext_offset-start_ext_offset, ENC_NA );
ext_id = tvb_get_guint8 (tvb, ext_offset);
ext_length = tvb_get_guint8 (tvb, ext_offset + 1);
if (rtp_hext_tree) {
ti = proto_tree_add_text(rtp_hext_tree, tvb, ext_offset, ext_length + 2, "RFC 5285 Header Extension (Two-Byte Header)");
rtp_hext_rfc5285_tree = proto_item_add_subtree( ti, ett_hdr_ext_rfc5285);
proto_tree_add_uint( rtp_hext_rfc5285_tree, hf_rtp_ext_rfc5285_appbits, parent_tvb, id_offset + 1, 1, id & 0x000F);
proto_tree_add_uint( rtp_hext_rfc5285_tree, hf_rtp_ext_rfc5285_id, tvb, ext_offset, 1, ext_id);
proto_tree_add_uint( rtp_hext_rfc5285_tree, hf_rtp_ext_rfc5285_length, tvb, ext_offset + 1, 1, ext_length);
}
ext_offset += 2;
subtvb = tvb_new_subset(tvb, ext_offset, ext_length, ext_length);
if (ext_length && !dissector_try_uint (rtp_hdr_ext_rfc5285_dissector_table, ext_id, subtvb, pinfo, rtp_hext_rfc5285_tree)) {
proto_tree_add_item(rtp_hext_rfc5285_tree, hf_rtp_ext_rfc5285_data, subtvb, 0, ext_length, ENC_NA );
}
ext_offset += ext_length;
}
}
static void
dissect_rtp( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
proto_item *ti = NULL;
proto_tree *volatile rtp_tree = NULL;
proto_tree *rtp_csrc_tree = NULL;
proto_tree *rtp_hext_tree = NULL;
guint8 octet1, octet2;
unsigned int version;
gboolean padding_set;
gboolean extension_set;
unsigned int csrc_count;
gboolean marker_set;
unsigned int payload_type;
gchar *payload_type_str = NULL;
gboolean is_srtp = FALSE;
unsigned int i = 0;
unsigned int hdr_extension_len= 0;
unsigned int hdr_extension_id = 0;
volatile unsigned int padding_count;
gint length, reported_length;
int data_len;
volatile unsigned int offset = 0;
guint16 seq_num;
guint32 timestamp;
guint32 sync_src;
guint32 csrc_item;
struct _rtp_conversation_info *p_conv_data = NULL;
unsigned int hdrext_offset = 0;
tvbuff_t *newtvb = NULL;
static struct _rtp_info rtp_info_arr[4];
static int rtp_info_current=0;
struct _rtp_info *rtp_info;
rtp_info_current++;
if (rtp_info_current==4) {
rtp_info_current=0;
}
rtp_info = &rtp_info_arr[rtp_info_current];
octet1 = tvb_get_guint8( tvb, offset );
version = RTP_VERSION( octet1 );
if (version == 0) {
switch (global_rtp_version0_type) {
case RTP0_STUN:
call_dissector(stun_handle, tvb, pinfo, tree);
return;
case RTP0_CLASSICSTUN:
call_dissector(classicstun_handle, tvb, pinfo, tree);
return;
case RTP0_T38:
call_dissector(t38_handle, tvb, pinfo, tree);
return;
case RTP0_SPRT:
call_dissector(sprt_handle, tvb, pinfo, tree);
return;
case RTP0_INVALID:
if (!(tvb_memeql(tvb, 4, "ZRTP", 4)))
{
call_dissector(zrtp_handle,tvb,pinfo,tree);
return;
}
default:
;
}
}
rtp_info->info_version = version;
if (version != 2) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTP");
col_add_fstr( pinfo->cinfo, COL_INFO,
"Unknown RTP version %u", version);
if ( tree ) {
ti = proto_tree_add_item( tree, proto_rtp, tvb, offset, -1, ENC_NA );
rtp_tree = proto_item_add_subtree( ti, ett_rtp );
proto_tree_add_uint( rtp_tree, hf_rtp_version, tvb,
offset, 1, octet1);
}
return;
}
padding_set = RTP_PADDING( octet1 );
extension_set = RTP_EXTENSION( octet1 );
csrc_count = RTP_CSRC_COUNT( octet1 );
octet2 = tvb_get_guint8( tvb, offset + 1 );
marker_set = RTP_MARKER( octet2 );
payload_type = RTP_PAYLOAD_TYPE( octet2 );
seq_num = tvb_get_ntohs( tvb, offset + 2 );
timestamp = tvb_get_ntohl( tvb, offset + 4 );
sync_src = tvb_get_ntohl( tvb, offset + 8 );
rtp_info->info_padding_set = padding_set;
rtp_info->info_padding_count = 0;
rtp_info->info_marker_set = marker_set;
rtp_info->info_is_video = FALSE;
rtp_info->info_payload_type = payload_type;
rtp_info->info_seq_num = seq_num;
rtp_info->info_timestamp = timestamp;
rtp_info->info_sync_src = sync_src;
rtp_info->info_is_srtp = FALSE;
rtp_info->info_setup_frame_num = 0;
rtp_info->info_payload_type_str = NULL;
rtp_info->info_payload_rate = 0;
length = tvb_length_remaining(tvb, offset);
reported_length = tvb_reported_length_remaining(tvb, offset);
if (reported_length >= 0 && length >= reported_length) {
rtp_info->info_all_data_present = TRUE;
rtp_info->info_data_len = reported_length;
rtp_info->info_data = tvb_get_ptr(tvb, 0, -1);
} else {
rtp_info->info_all_data_present = FALSE;
rtp_info->info_data_len = 0;
rtp_info->info_data = NULL;
}
get_conv_info(pinfo, rtp_info);
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(pinfo->fd, proto_rtp, 0);
if (p_conv_data)
rtp_info->info_is_video = p_conv_data->is_video;
if (p_conv_data && p_conv_data->srtp_info) is_srtp = TRUE;
rtp_info->info_is_srtp = is_srtp;
col_set_str( pinfo->cinfo, COL_PROTOCOL, (is_srtp) ? "SRTP" : "RTP" );
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(pinfo->fd, proto_rtp, 0);
#if 0
if (p_conv_data && p_conv_data->srtp_info) {
srtp_info = p_conv_data->srtp_info;
if (rtp_info->info_all_data_present) {
srtp_offset = rtp_info->info_data_len - srtp_info->mki_len - srtp_info->auth_tag_len;
}
}
#endif
if ( (payload_type>95) && (payload_type<128) ) {
if (p_conv_data && p_conv_data->rtp_dyn_payload){
encoding_name_and_rate_t *encoding_name_and_rate_pt = NULL;
encoding_name_and_rate_pt = (encoding_name_and_rate_t *)g_hash_table_lookup(p_conv_data->rtp_dyn_payload, &payload_type);
if (encoding_name_and_rate_pt) {
rtp_info->info_payload_type_str = payload_type_str = encoding_name_and_rate_pt->encoding_name;
rtp_info->info_payload_rate = encoding_name_and_rate_pt->sample_rate;
}
}
}
col_add_fstr( pinfo->cinfo, COL_INFO,
"PT=%s, SSRC=0x%X, Seq=%u, Time=%u%s",
payload_type_str ? payload_type_str : val_to_str_ext( payload_type, &rtp_payload_type_vals_ext,"Unknown (%u)" ),
sync_src,
seq_num,
timestamp,
marker_set ? ", Mark" : "");
if ( tree ) {
proto_tree *item;
ti = proto_tree_add_item(tree, proto_rtp, tvb, offset, -1, ENC_NA );
rtp_tree = proto_item_add_subtree(ti, ett_rtp );
if (global_rtp_show_setup_info)
{
show_setup_info(tvb, pinfo, rtp_tree);
}
proto_tree_add_uint( rtp_tree, hf_rtp_version, tvb,
offset, 1, octet1 );
proto_tree_add_boolean( rtp_tree, hf_rtp_padding, tvb,
offset, 1, octet1 );
proto_tree_add_boolean( rtp_tree, hf_rtp_extension, tvb,
offset, 1, octet1 );
proto_tree_add_uint( rtp_tree, hf_rtp_csrc_count, tvb,
offset, 1, octet1 );
offset++;
proto_tree_add_boolean( rtp_tree, hf_rtp_marker, tvb, offset,
1, octet2 );
proto_tree_add_uint_format_value( rtp_tree, hf_rtp_payload_type, tvb,
offset, 1, octet2, "%s (%u)",
payload_type_str ? payload_type_str : val_to_str_ext_const( payload_type, &rtp_payload_type_vals_ext,"Unknown"),
payload_type);
offset++;
proto_tree_add_uint( rtp_tree, hf_rtp_seq_nr, tvb, offset, 2, seq_num );
if(p_conv_data != NULL) {
item = proto_tree_add_uint( rtp_tree, hf_rtp_ext_seq_nr, tvb, offset, 2, p_conv_data->extended_seqno );
PROTO_ITEM_SET_GENERATED(item);
}
offset += 2;
proto_tree_add_uint( rtp_tree, hf_rtp_timestamp, tvb, offset, 4, timestamp );
offset += 4;
proto_tree_add_uint( rtp_tree, hf_rtp_ssrc, tvb, offset, 4, sync_src );
offset += 4;
} else {
offset += 12;
}
if ( csrc_count > 0 ) {
ti = proto_tree_add_item(rtp_tree, hf_rtp_csrc_items, tvb, offset,
csrc_count * 4, ENC_NA);
proto_item_append_text(ti, " (%u items)", csrc_count);
rtp_csrc_tree = proto_item_add_subtree( ti, ett_csrc_list );
for (i = 0; i < csrc_count; i++ ) {
csrc_item = tvb_get_ntohl( tvb, offset );
proto_tree_add_uint_format( rtp_csrc_tree,
hf_rtp_csrc_item, tvb, offset, 4,
csrc_item,
"CSRC item %d: 0x%X",
i, csrc_item );
offset += 4;
}
}
if ( extension_set ) {
hdr_extension_id = tvb_get_ntohs( tvb, offset );
if ( tree ) proto_tree_add_uint( rtp_tree, hf_rtp_prof_define, tvb, offset, 2, hdr_extension_id );
offset += 2;
hdr_extension_len = tvb_get_ntohs( tvb, offset );
if ( tree ) proto_tree_add_uint( rtp_tree, hf_rtp_length, tvb, offset, 2, hdr_extension_len);
offset += 2;
if ( hdr_extension_len > 0 ) {
if ( tree ) {
ti = proto_tree_add_item(rtp_tree, hf_rtp_hdr_exts, tvb, offset, hdr_extension_len * 4, ENC_NA);
rtp_hext_tree = proto_item_add_subtree( ti, ett_hdr_ext );
}
newtvb = tvb_new_subset(tvb, offset, hdr_extension_len * 4, hdr_extension_len * 4);
if (hdr_extension_id == RTP_RFC5215_ONE_BYTE_SIG) {
dissect_rtp_hext_rfc5215_onebyte (newtvb, pinfo, rtp_hext_tree);
}
else if ((hdr_extension_id & RTP_RFC5215_TWO_BYTE_MASK) == RTP_RFC5215_TWO_BYTE_SIG) {
dissect_rtp_hext_rfc5215_twobytes(tvb,
offset - 4, hdr_extension_id, newtvb,
pinfo, rtp_hext_tree);
}
else {
if ( !(dissector_try_uint(rtp_hdr_ext_dissector_table, hdr_extension_id, newtvb, pinfo, rtp_hext_tree)) ) {
hdrext_offset = offset;
for ( i = 0; i < hdr_extension_len; i++ ) {
if ( tree ) proto_tree_add_uint( rtp_hext_tree, hf_rtp_hdr_ext, tvb, hdrext_offset, 4, tvb_get_ntohl( tvb, hdrext_offset ) );
hdrext_offset += 4;
}
}
}
}
offset += hdr_extension_len * 4;
}
if ( padding_set ) {
if (tvb_length(tvb) < tvb_reported_length(tvb)) {
if ( tree ) proto_tree_add_text(rtp_tree, tvb, 0, 0,
"Frame has padding, but not all the frame data was captured");
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset),
pinfo, rtp_tree);
return;
}
padding_count = tvb_get_guint8( tvb,
tvb_reported_length( tvb ) - 1 );
data_len =
tvb_reported_length_remaining( tvb, offset ) - padding_count;
rtp_info->info_payload_offset = offset;
rtp_info->info_payload_len = tvb_length_remaining(tvb, offset);
rtp_info->info_padding_count = padding_count;
if (data_len > 0) {
TRY {
dissect_rtp_data( tvb, pinfo, tree, rtp_tree,
offset,
data_len,
data_len,
payload_type );
} CATCH_ALL {
if (!pinfo->flags.in_error_pkt)
tap_queue_packet(rtp_tap, pinfo, rtp_info);
RETHROW;
}
ENDTRY;
offset += data_len;
} else if (data_len < 0) {
padding_count =
tvb_reported_length_remaining(tvb, offset);
}
if (padding_count > 1) {
if ( tree ) proto_tree_add_item( rtp_tree, hf_rtp_padding_data,
tvb, offset, padding_count - 1, ENC_NA );
offset += padding_count - 1;
}
if ( tree ) proto_tree_add_item( rtp_tree, hf_rtp_padding_count,
tvb, offset, 1, ENC_BIG_ENDIAN );
}
else {
if (tvb_reported_length_remaining(tvb, offset) > 0) {
TRY {
dissect_rtp_data( tvb, pinfo, tree, rtp_tree, offset,
tvb_length_remaining( tvb, offset ),
tvb_reported_length_remaining( tvb, offset ),
payload_type );
} CATCH_ALL {
if (!pinfo->flags.in_error_pkt)
tap_queue_packet(rtp_tap, pinfo, rtp_info);
RETHROW;
}
ENDTRY;
}
rtp_info->info_payload_offset = offset;
rtp_info->info_payload_len = tvb_length_remaining(tvb, offset);
}
if (!pinfo->flags.in_error_pkt)
tap_queue_packet(rtp_tap, pinfo, rtp_info);
}
static void
dissect_rtp_hdr_ext_ed137(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
unsigned int offset = 0;
unsigned int hdr_extension_len = 0;
proto_item *ti = NULL;
proto_item *ti2 = NULL;
proto_tree *rtp_hext_tree = NULL;
proto_tree *rtp_hext_tree2 = NULL;
unsigned int i;
guint32 ext_value;
unsigned int ft_type = 0;
unsigned int bss_qidx = 0;
unsigned int bss_qidx_ml = 0;
hdr_extension_len = tvb_reported_length(tvb)/4;
if ( hdr_extension_len > 0 ) {
unsigned int hdrext_offset = 0;
if ( tree ) {
ti = proto_tree_add_item(tree, hf_rtp_hdr_ed137s, tvb, offset, hdr_extension_len * 4, ENC_NA);
rtp_hext_tree = proto_item_add_subtree( ti, ett_hdr_ext_ed137s );
}
for(i=0; i<hdr_extension_len; i++) {
if ( tree ) {
ti2 = proto_tree_add_item(rtp_hext_tree, hf_rtp_hdr_ed137, tvb, hdrext_offset, 4, ENC_NA);
rtp_hext_tree2 = proto_item_add_subtree( ti2, ett_hdr_ext_ed137 );
ext_value=tvb_get_ntohl( tvb, hdrext_offset );
if (RTP_ED137_ptt_mask(ext_value)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", PTT");
}
if (RTP_ED137_squ_mask(ext_value)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", SQU");
}
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ptt_type, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_squ, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ptt_id, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_sct, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_x, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
if (RTP_ED137_extended_information(ext_value)) {
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ft_type, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ft_len, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
ft_type=RTP_ED137_feature_type(ext_value);
switch (ft_type) {
case RTP_ED137_feature_bss_type:
bss_qidx=RTP_ED137_feature_bss_qidx(ext_value);
bss_qidx_ml=RTP_ED137_feature_bss_qidx_ml(ext_value);
if (0==bss_qidx_ml) {
if (bss_qidx<=15) {
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ft_bss_rssi_qidx, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ft_bss_qidx, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
}
}
else {
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ft_bss_qidx, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ft_bss_qidx_ml, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ft_bss_nu, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_ft_value, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
break;
}
}
else {
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_x_nu, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137_vf, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
}
hdrext_offset += 4;
}
}
}
static void
dissect_rtp_hdr_ext_ed137a(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
unsigned int offset = 0;
unsigned int hdr_extension_len = 0;
proto_item *ti = NULL;
proto_item *ti2 = NULL;
proto_tree *rtp_hext_tree = NULL;
proto_tree *rtp_hext_tree2 = NULL;
unsigned int i;
guint32 ext_value;
unsigned int ft_type = 0;
hdr_extension_len = tvb_reported_length(tvb)/4;
if ( hdr_extension_len > 0 ) {
unsigned int hdrext_offset = 0;
if ( tree ) {
ti = proto_tree_add_item(tree, hf_rtp_hdr_ed137s, tvb, offset, hdr_extension_len * 4, ENC_NA);
rtp_hext_tree = proto_item_add_subtree( ti, ett_hdr_ext_ed137s );
}
for(i=0; i<hdr_extension_len; i++) {
if ( tree ) {
ti2 = proto_tree_add_item(rtp_hext_tree, hf_rtp_hdr_ed137a, tvb, hdrext_offset, 4, ENC_NA);
rtp_hext_tree2 = proto_item_add_subtree( ti2, ett_hdr_ext_ed137a );
ext_value=tvb_get_ntohl( tvb, hdrext_offset );
if (RTP_ED137A_ptt_mask(ext_value)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", PTT");
}
if (RTP_ED137A_squ_mask(ext_value)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", SQU");
}
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_ptt_type, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_squ, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_ptt_id, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_pm, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_ptts, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_sct, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_reserved, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_x, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
if (RTP_ED137A_extended_information(ext_value)) {
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_ft_type, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_ft_len, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
ft_type=RTP_ED137A_feature_type(ext_value);
switch (ft_type) {
default:
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_ft_value, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
break;
}
}
else {
proto_tree_add_item( rtp_hext_tree2, hf_rtp_hdr_ed137a_x_nu, tvb, hdrext_offset, 4, ENC_BIG_ENDIAN);
}
}
hdrext_offset += 4;
}
}
}
static guint32
calculate_extended_seqno(guint32 previous_seqno, guint16 raw_seqno)
{
guint32 seqno = (previous_seqno & 0xffff0000) | raw_seqno;
if(seqno + 0x8000 < previous_seqno) {
seqno += 0x10000;
} else if(previous_seqno + 0x8000 < seqno) {
seqno -= 0x10000;
}
return seqno;
}
static void
get_conv_info(packet_info *pinfo, struct _rtp_info *rtp_info)
{
conversation_t *p_conv = NULL;
struct _rtp_conversation_info *p_conv_data = NULL;
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(pinfo->fd, proto_rtp, 0);
if (!p_conv_data)
{
p_conv = find_conversation(pinfo->fd->num, &pinfo->net_dst, &pinfo->net_src,
pinfo->ptype,
pinfo->destport, pinfo->srcport, NO_ADDR_B);
if (p_conv)
{
struct _rtp_conversation_info *p_conv_packet_data;
p_conv_data = (struct _rtp_conversation_info *)conversation_get_proto_data(p_conv, proto_rtp);
if (p_conv_data) {
guint32 seqno;
p_conv_packet_data = wmem_new(wmem_file_scope(), struct _rtp_conversation_info);
g_strlcpy(p_conv_packet_data->method, p_conv_data->method, MAX_RTP_SETUP_METHOD_SIZE+1);
p_conv_packet_data->frame_number = p_conv_data->frame_number;
p_conv_packet_data->is_video = p_conv_data->is_video;
p_conv_packet_data->rtp_dyn_payload = p_conv_data->rtp_dyn_payload;
p_conv_packet_data->rtp_conv_info = p_conv_data->rtp_conv_info;
p_conv_packet_data->srtp_info = p_conv_data->srtp_info;
p_add_proto_data(pinfo->fd, proto_rtp, 0, p_conv_packet_data);
seqno = calculate_extended_seqno(p_conv_data->extended_seqno,
rtp_info->info_seq_num);
p_conv_packet_data->extended_seqno = seqno;
p_conv_data->extended_seqno = seqno;
}
}
}
if (p_conv_data) rtp_info->info_setup_frame_num = p_conv_data->frame_number;
}
static void
show_setup_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
struct _rtp_conversation_info *p_conv_data = NULL;
proto_tree *rtp_setup_tree;
proto_item *ti;
p_conv_data = (struct _rtp_conversation_info *)p_get_proto_data(pinfo->fd, proto_rtp, 0);
if (!p_conv_data) return;
ti = proto_tree_add_string_format(tree, hf_rtp_setup, tvb, 0, 0,
"", "Stream setup by %s (frame %u)",
p_conv_data->method,
p_conv_data->frame_number);
PROTO_ITEM_SET_GENERATED(ti);
rtp_setup_tree = proto_item_add_subtree(ti, ett_rtp_setup);
if (rtp_setup_tree)
{
proto_item* item = proto_tree_add_uint(rtp_setup_tree, hf_rtp_setup_frame,
tvb, 0, 0, p_conv_data->frame_number);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_string(rtp_setup_tree, hf_rtp_setup_method,
tvb, 0, 0, p_conv_data->method);
PROTO_ITEM_SET_GENERATED(item);
}
}
static void
dissect_pkt_ccc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *pkt_ccc_tree = NULL;
if ( tree ) {
ti = proto_tree_add_item(tree, proto_pkt_ccc, tvb, 0, 12, ENC_NA);
pkt_ccc_tree = proto_item_add_subtree(ti, ett_pkt_ccc);
proto_tree_add_item(pkt_ccc_tree, hf_pkt_ccc_id, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pkt_ccc_tree, hf_pkt_ccc_ts, tvb, 4, 8,
ENC_TIME_NTP|ENC_BIG_ENDIAN);
}
dissect_rtp(tvb, pinfo, tree);
}
void
proto_register_pkt_ccc(void)
{
static hf_register_info hf[] =
{
{
&hf_pkt_ccc_id,
{
"PacketCable CCC Identifier",
"pkt_ccc.ccc_id",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_pkt_ccc_ts,
{
"PacketCable CCC Timestamp",
"pkt_ccc.ts",
FT_ABSOLUTE_TIME,
ABSOLUTE_TIME_UTC,
NULL,
0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_pkt_ccc,
};
module_t *pkt_ccc_module;
proto_pkt_ccc = proto_register_protocol("PacketCable Call Content Connection",
"PKT CCC", "pkt_ccc");
proto_register_field_array(proto_pkt_ccc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("pkt_ccc", dissect_pkt_ccc, proto_pkt_ccc);
pkt_ccc_module = prefs_register_protocol(proto_pkt_ccc, proto_reg_handoff_pkt_ccc);
prefs_register_uint_preference(pkt_ccc_module, "udp_port",
"UDP port",
"Decode packets on this UDP port as PacketCable CCC",
10, &global_pkt_ccc_udp_port);
}
void
proto_reg_handoff_pkt_ccc(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t pkt_ccc_handle;
static guint saved_pkt_ccc_udp_port;
if (!initialized) {
pkt_ccc_handle = find_dissector("pkt_ccc");
dissector_add_handle("udp.port", pkt_ccc_handle);
initialized = TRUE;
} else {
if (saved_pkt_ccc_udp_port != 0) {
dissector_delete_uint("udp.port", saved_pkt_ccc_udp_port, pkt_ccc_handle);
}
}
if (global_pkt_ccc_udp_port != 0) {
dissector_add_uint("udp.port", global_pkt_ccc_udp_port, pkt_ccc_handle);
}
saved_pkt_ccc_udp_port = global_pkt_ccc_udp_port;
}
void
proto_register_rtp(void)
{
static hf_register_info hf[] =
{
{
&hf_rtp_version,
{
"Version",
"rtp.version",
FT_UINT8,
BASE_DEC,
VALS(rtp_version_vals),
0xC0,
NULL, HFILL
}
},
{
&hf_rtp_padding,
{
"Padding",
"rtp.padding",
FT_BOOLEAN,
8,
NULL,
0x20,
NULL, HFILL
}
},
{
&hf_rtp_extension,
{
"Extension",
"rtp.ext",
FT_BOOLEAN,
8,
NULL,
0x10,
NULL, HFILL
}
},
{
&hf_rtp_csrc_count,
{
"Contributing source identifiers count",
"rtp.cc",
FT_UINT8,
BASE_DEC,
NULL,
0x0F,
NULL, HFILL
}
},
{
&hf_rtp_marker,
{
"Marker",
"rtp.marker",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_rtp_payload_type,
{
"Payload type",
"rtp.p_type",
FT_UINT8,
BASE_DEC,
NULL,
0x7F,
NULL, HFILL
}
},
{
&hf_rtp_seq_nr,
{
"Sequence number",
"rtp.seq",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_ext_seq_nr,
{
"Extended sequence number",
"rtp.extseq",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_timestamp,
{
"Timestamp",
"rtp.timestamp",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_ssrc,
{
"Synchronization Source identifier",
"rtp.ssrc",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_prof_define,
{
"Defined by profile",
"rtp.ext.profile",
FT_UINT16,
BASE_HEX_DEC,
VALS(rtp_ext_profile_vals),
0x0,
NULL, HFILL
}
},
{
&hf_rtp_length,
{
"Extension length",
"rtp.ext.len",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_csrc_items,
{
"Contributing Source identifiers",
"rtp.csrc.items",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_csrc_item,
{
"CSRC item",
"rtp.csrc.item",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_hdr_exts,
{
"Header extensions",
"rtp.hdr_exts",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137s,
{
"ED137 extensions",
"rtp.ext.ed137s",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137,
{
"ED137 extension",
"rtp.ext.ed137",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ptt_type,
{
"PTT Type",
"rtp.ext.ed137.ptt_type",
FT_UINT32,
BASE_DEC,
VALS(rtp_ext_ed137_ptt_type),
0xE0000000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_squ,
{
"SQU",
"rtp.ext.ed137.squ",
FT_UINT32,
BASE_DEC,
VALS(rtp_ext_ed137_squ),
0x10000000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ptt_id,
{
"PTT-id",
"rtp.ext.ed137.ptt_id",
FT_UINT32,
BASE_DEC,
NULL,
0x0F000000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_sct,
{
"Simultaneous Call Transmissions",
"rtp.ext.ed137.sct",
FT_UINT32,
BASE_DEC,
NULL,
0x00800000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_x,
{
"X",
"rtp.ext.ed137.x",
FT_UINT32,
BASE_DEC,
NULL,
0x00400000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_x_nu,
{
"Not used",
"rtp.ext.ed137.x-nu",
FT_UINT32,
BASE_DEC,
NULL,
0x003FFFFE,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ft_type,
{
"Feature type",
"rtp.ext.ed137.ft.type",
FT_UINT32,
BASE_HEX_DEC,
VALS(rtp_ext_ed137_ft_type),
0x003C0000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ft_len,
{
"Feature length",
"rtp.ext.ed137.ft.len",
FT_UINT32,
BASE_DEC,
NULL,
0x0003C000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ft_value,
{
"Feature value",
"rtp.ext.ed137.ft.value",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x00003FFE,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_vf,
{
"VF",
"rtp.ext.ed137.vf",
FT_UINT32,
BASE_DEC,
VALS(rtp_ext_ed137_vf),
0x00000001,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ft_bss_qidx,
{
"BSS Quality Index",
"rtp.ext.ed137.ft.bss.qidx",
FT_UINT32,
BASE_DEC,
NULL,
0x00003FC0,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ft_bss_rssi_qidx,
{
"BSS Quality Index",
"rtp.ext.ed137.ft.bss.qidx",
FT_UINT32,
BASE_DEC,
VALS(rtp_ext_ed137_ft_bss_rssi_qidx),
0x00003FC0,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ft_bss_qidx_ml,
{
"BSS Quality Index Method",
"rtp.ext.ed137.ft.bss.qidx-ml",
FT_UINT32,
BASE_DEC,
VALS(rtp_ext_ed137_ft_bss_qidx_ml),
0x00000038,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137_ft_bss_nu,
{
"Not used",
"rtp.ext.ed137.ft.bss-nu",
FT_UINT32,
BASE_DEC,
NULL,
0x00000006,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a,
{
"ED137A extension",
"rtp.ext.ed137A",
FT_NONE,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_ptt_type,
{
"PTT Type",
"rtp.ext.ed137A.ptt_type",
FT_UINT32,
BASE_DEC,
VALS(rtp_ext_ed137a_ptt_type),
0xE0000000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_squ,
{
"SQU",
"rtp.ext.ed137A.squ",
FT_UINT32,
BASE_DEC,
VALS(rtp_ext_ed137a_squ),
0x10000000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_ptt_id,
{
"PTT-id",
"rtp.ext.ed137A.ptt_id",
FT_UINT32,
BASE_DEC,
NULL,
0x0FC00000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_pm,
{
"PTT Mute",
"rtp.ext.ed137A.pm",
FT_UINT32,
BASE_DEC,
NULL,
0x00200000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_ptts,
{
"PTT Summation",
"rtp.ext.ed137A.ptts",
FT_UINT32,
BASE_DEC,
NULL,
0x00100000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_sct,
{
"Simultaneous Call Transmissions",
"rtp.ext.ed137a.sct",
FT_UINT32,
BASE_DEC,
NULL,
0x00080000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_reserved,
{
"Reserved",
"rtp.ext.ed137A.reserved",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x00060000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_x,
{
"X",
"rtp.ext.ed137A.x",
FT_UINT32,
BASE_DEC,
NULL,
0x00010000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_x_nu,
{
"Not used",
"rtp.ext.ed137A.x-nu",
FT_UINT32,
BASE_DEC,
NULL,
0x0000FFFF,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_ft_type,
{
"Feature type",
"rtp.ext.ed137A.ft.type",
FT_UINT32,
BASE_HEX_DEC,
VALS(rtp_ext_ed137a_ft_type),
0x0000F000,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_ft_len,
{
"Feature length",
"rtp.ext.ed137A.ft.len",
FT_UINT32,
BASE_DEC,
NULL,
0x00000F00,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ed137a_ft_value,
{
"Feature value",
"rtp.ext.ed137A.ft.value",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x000000FF,
NULL, HFILL
}
},
{
&hf_rtp_hdr_ext,
{
"Header extension",
"rtp.hdr_ext",
FT_UINT32,
BASE_HEX_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_data,
{
"Payload",
"rtp.payload",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_padding_data,
{
"Padding data",
"rtp.padding.data",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_padding_count,
{
"Padding count",
"rtp.padding.count",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_setup,
{
"Stream setup",
"rtp.setup",
FT_STRING,
BASE_NONE,
NULL,
0x0,
"Stream setup, method and frame number", HFILL
}
},
{
&hf_rtp_setup_frame,
{
"Setup frame",
"rtp.setup-frame",
FT_FRAMENUM,
BASE_NONE,
NULL,
0x0,
"Frame that set up this stream", HFILL
}
},
{
&hf_rtp_setup_method,
{
"Setup Method",
"rtp.setup-method",
FT_STRING,
BASE_NONE,
NULL,
0x0,
"Method used to set up this stream", HFILL
}
},
{
&hf_rtp_rfc2198_follow,
{
"Follow",
"rtp.follow",
FT_BOOLEAN,
8,
TFS(&tfs_set_notset),
0x80,
"Next header follows", HFILL
}
},
{
&hf_rtp_rfc2198_tm_off,
{
"Timestamp offset",
"rtp.timestamp-offset",
FT_UINT16,
BASE_DEC,
NULL,
0xFFFC,
NULL, HFILL
}
},
{
&hf_rtp_rfc2198_bl_len,
{
"Block length",
"rtp.block-length",
FT_UINT16,
BASE_DEC,
NULL,
0x03FF,
NULL, HFILL
}
},
{
&hf_rtp_ext_rfc5285_id,
{
"Identifier",
"rtp.ext.rfc5285.id",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"RFC 5285 Header Extension Identifier",
HFILL
}
},
{
&hf_rtp_ext_rfc5285_length,
{
"Length",
"rtp.ext.rfc5285.len",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"RFC 5285 Header Extension length",
HFILL
}
},
{
&hf_rtp_ext_rfc5285_appbits,
{
"Application Bits",
"rtp.ext.rfc5285.appbits",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"RFC 5285 2-bytes header application bits",
HFILL
}
},
{
&hf_rtp_ext_rfc5285_data,
{
"Extension Data",
"rtp.ext.rfc5285.data",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
"RFC 5285 Extension Data",
HFILL
}
},
{&hf_rtp_fragments,
{"RTP Fragments", "rtp.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rtp_fragment,
{"RTP Fragment data", "rtp.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_rtp_fragment_overlap,
{"Fragment overlap", "rtp.fragment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment overlaps with other fragments", HFILL }
},
{&hf_rtp_fragment_overlap_conflict,
{"Conflicting data in fragment overlap", "rtp.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }
},
{&hf_rtp_fragment_multiple_tails,
{"Multiple tail fragments found", "rtp.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }
},
{&hf_rtp_fragment_too_long_fragment,
{"Fragment too long", "rtp.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }
},
{&hf_rtp_fragment_error,
{"Defragmentation error", "rtp.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }
},
{&hf_rtp_fragment_count,
{"Fragment count", "rtp.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{&hf_rtp_reassembled_in,
{"RTP fragment, reassembled in frame", "rtp.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This RTP packet is reassembled in this frame", HFILL }
},
{&hf_rtp_reassembled_length,
{"Reassembled RTP length", "rtp.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }
},
{&hf_srtp_encrypted_payload,
{"SRTP Encrypted Payload", "srtp.enc_payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_srtp_mki,
{"SRTP MKI", "srtp.mki",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SRTP Master Key Index", HFILL }
},
{&hf_srtp_auth_tag,
{"SRTP Auth Tag", "srtp.auth_tag",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SRTP Authentication Tag", HFILL }
}
};
static gint *ett[] =
{
&ett_rtp,
&ett_csrc_list,
&ett_hdr_ext,
&ett_hdr_ext_rfc5285,
&ett_hdr_ext_ed137s,
&ett_hdr_ext_ed137,
&ett_hdr_ext_ed137a,
&ett_rtp_setup,
&ett_rtp_rfc2198,
&ett_rtp_rfc2198_hdr,
&ett_rtp_fragment,
&ett_rtp_fragments
};
module_t *rtp_module;
proto_rtp = proto_register_protocol("Real-Time Transport Protocol",
"RTP", "rtp");
proto_register_field_array(proto_rtp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("rtp", dissect_rtp, proto_rtp);
register_dissector("rtp.rfc2198", dissect_rtp_rfc2198, proto_rtp);
rtp_tap = register_tap("rtp");
rtp_pt_dissector_table = register_dissector_table("rtp.pt",
"RTP payload type", FT_UINT8, BASE_DEC);
rtp_dyn_pt_dissector_table = register_dissector_table("rtp_dyn_payload_type",
"Dynamic RTP payload type", FT_STRING, BASE_NONE);
rtp_hdr_ext_dissector_table = register_dissector_table("rtp.hdr_ext",
"RTP header extension", FT_UINT32, BASE_HEX);
rtp_hdr_ext_rfc5285_dissector_table = register_dissector_table("rtp.ext.rfc5285.id",
"RTP Generic header extension (RFC 5285)", FT_UINT8, BASE_DEC);
register_dissector("rtp.ext.ed137", dissect_rtp_hdr_ext_ed137, proto_rtp);
register_dissector("rtp.ext.ed137a", dissect_rtp_hdr_ext_ed137a, proto_rtp);
rtp_module = prefs_register_protocol(proto_rtp, proto_reg_handoff_rtp);
prefs_register_bool_preference(rtp_module, "show_setup_info",
"Show stream setup information",
"Where available, show which protocol and frame caused "
"this RTP stream to be created",
&global_rtp_show_setup_info);
prefs_register_bool_preference(rtp_module, "heuristic_rtp",
"Try to decode RTP outside of conversations",
"If call control SIP/H323/RTSP/.. messages are missing in the trace, "
"RTP isn't decoded without this",
&global_rtp_heur);
prefs_register_bool_preference(rtp_module, "desegment_rtp_streams",
"Allow subdissector to reassemble RTP streams",
"Whether subdissector can request RTP streams to be reassembled",
&desegment_rtp);
prefs_register_enum_preference(rtp_module, "version0_type",
"Treat RTP version 0 packets as",
"If an RTP version 0 packet is encountered, it can be treated as "
"an invalid or ZRTP packet, a CLASSIC-STUN packet, or a T.38 packet",
&global_rtp_version0_type,
rtp_version0_types, FALSE);
prefs_register_uint_preference(rtp_module,
"rfc2198_payload_type", "Payload Type for RFC2198",
"Payload Type for RFC2198 Redundant Audio Data",
10,
&rtp_rfc2198_pt);
register_init_routine(rtp_fragment_init);
}
void
proto_reg_handoff_rtp(void)
{
static gboolean rtp_prefs_initialized = FALSE;
static dissector_handle_t rtp_rfc2198_handle;
static dissector_handle_t rtp_hdr_ext_ed137_handle;
static dissector_handle_t rtp_hdr_ext_ed137a_handle;
static guint rtp_saved_rfc2198_pt;
if (!rtp_prefs_initialized) {
rtp_handle = find_dissector("rtp");
rtp_rfc2198_handle = find_dissector("rtp.rfc2198");
dissector_add_handle("udp.port", rtp_handle);
dissector_add_string("rtp_dyn_payload_type", "red", rtp_rfc2198_handle);
heur_dissector_add( "udp", dissect_rtp_heur_udp, proto_rtp);
heur_dissector_add("stun", dissect_rtp_heur_stun, proto_rtp);
rtp_hdr_ext_ed137_handle = find_dissector("rtp.ext.ed137");
rtp_hdr_ext_ed137a_handle = find_dissector("rtp.ext.ed137a");
dissector_add_uint("rtp.hdr_ext", RTP_ED137_SIG, rtp_hdr_ext_ed137_handle);
dissector_add_uint("rtp.hdr_ext", RTP_ED137A_SIG, rtp_hdr_ext_ed137a_handle);
data_handle = find_dissector("data");
stun_handle = find_dissector("stun-udp");
classicstun_handle = find_dissector("classicstun");
classicstun_heur_handle = find_dissector("classicstun-heur");
stun_heur_handle = find_dissector("stun-heur");
t38_handle = find_dissector("t38");
zrtp_handle = find_dissector("zrtp");
sprt_handle = find_dissector("sprt");
v150fw_handle = find_dissector("v150fw");
dissector_add_string("rtp_dyn_payload_type", "v150fw", v150fw_handle);
rtp_prefs_initialized = TRUE;
} else {
dissector_delete_uint("rtp.pt", rtp_saved_rfc2198_pt, rtp_rfc2198_handle);
}
dissector_add_uint("rtp.pt", rtp_rfc2198_pt, rtp_rfc2198_handle);
rtp_saved_rfc2198_pt = rtp_rfc2198_pt;
}
