static void
ssl_proto_tree_add_segment_data(
proto_tree *tree,
tvbuff_t *tvb,
gint offset,
gint length,
const gchar *prefix)
{
proto_tree_add_bytes_format(
tree,
hf_ssl_segment_data,
tvb,
offset,
length,
NULL,
"%sSSL segment data (%u %s)",
prefix != NULL ? prefix : "",
length,
plurality(length, "byte", "bytes"));
}
static void
ssl_fragment_init(void)
{
reassembly_table_init(&ssl_reassembly_table,
&addresses_ports_reassembly_table_functions);
}
static void
ssl_init(void)
{
module_t *ssl_module = prefs_find_module("ssl");
pref_t *keys_list_pref;
ssl_common_init(&ssl_master_key_map, &ssl_keylog_file,
&ssl_decrypted_data, &ssl_compressed_data);
ssl_fragment_init();
ssl_debug_flush();
ssl_session_hash = ssl_master_key_map.session;
if (ssl_module) {
keys_list_pref = prefs_find_preference(ssl_module, "keys_list");
if (! prefs_get_preference_obsolete(keys_list_pref)) {
prefs_set_preference_obsolete(keys_list_pref);
}
}
}
static void
ssl_parse_uat(void)
{
wmem_stack_t *tmp_stack;
guint i;
ssl_set_debug(ssl_debug_file_name);
if (ssl_key_hash)
{
g_hash_table_foreach(ssl_key_hash, ssl_private_key_free, NULL);
g_hash_table_destroy(ssl_key_hash);
}
tmp_stack = wmem_stack_new(NULL);
g_tree_foreach(ssl_associations, ssl_assoc_from_key_list, tmp_stack);
while (wmem_stack_count(tmp_stack) > 0) {
ssl_association_remove(ssl_associations, (SslAssociation *)wmem_stack_pop(tmp_stack));
}
wmem_destroy_stack(tmp_stack);
ssl_key_hash = g_hash_table_new(ssl_private_key_hash,ssl_private_key_equal);
if (nssldecrypt > 0) {
for (i = 0; i < nssldecrypt; i++) {
ssldecrypt_assoc_t *ssl_uat = &(sslkeylist_uats[i]);
ssl_parse_key_list(ssl_uat, ssl_key_hash, ssl_associations, ssl_handle, TRUE);
}
}
ssl_debug_flush();
}
static void
ssl_parse_old_keys(void)
{
gchar **old_keys, **parts, *err;
gchar *uat_entry;
guint i;
if (ssldecrypt_uat && ssl_keys_list && ssl_keys_list[0]) {
old_keys = ep_strsplit(ssl_keys_list, ";", 0);
for (i = 0; old_keys[i] != NULL; i++) {
parts = ep_strsplit(old_keys[i], ",", 4);
if (parts[0] && parts[1] && parts[2] && parts[3]) {
uat_entry = ep_strdup_printf("\"%s\",\"%s\",\"%s\",\"%s\",\"\"",
parts[0], parts[1], parts[2], parts[3]);
if (!uat_load_str(ssldecrypt_uat, uat_entry, &err)) {
ssl_debug_printf("ssl_parse_old_keys: Can't load UAT string %s: %s\n",
uat_entry, err);
}
}
}
}
}
static gboolean
ssl_association_info_(gpointer key_ _U_, gpointer value_, gpointer s_)
{
SslAssociation *value = (SslAssociation *)value_;
gchar *s = (gchar *)s_;
const int l = (const int)strlen(s);
g_snprintf(s+l, SSL_ASSOC_MAX_LEN-l, "'%s' %s %i\n", value->info, value->tcp ? "TCP":"UDP", value->ssl_port);
return FALSE;
}
gchar*
ssl_association_info(void)
{
gchar *s = (gchar *)ep_alloc0(SSL_ASSOC_MAX_LEN);
g_tree_foreach(ssl_associations, ssl_association_info_, s);
return s;
}
static int
dissect_ssl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
conversation_t *conversation;
void *conv_data;
proto_item *ti;
proto_tree *ssl_tree;
guint32 offset;
gboolean first_record_in_frame;
gboolean need_desegmentation;
SslDecryptSession *ssl_session;
SslSession *session;
gint is_from_server;
ti = NULL;
ssl_tree = NULL;
offset = 0;
first_record_in_frame = TRUE;
ssl_session = NULL;
if (tvb_captured_length(tvb) > 4) {
const guint8 *tmp = tvb_get_ptr(tvb, 0, 4);
if (g_ascii_isprint(tmp[0]) &&
g_ascii_isprint(tmp[1]) &&
g_ascii_isprint(tmp[2]) &&
g_ascii_isprint(tmp[3])) {
return 0;
}
}
ssl_debug_printf("\ndissect_ssl enter frame #%u (%s)\n", pinfo->fd->num, (pinfo->fd->flags.visited)?"already visited":"first time");
conversation = find_or_create_conversation(pinfo);
conv_data = conversation_get_proto_data(conversation, proto_ssl);
if (conv_data != NULL)
ssl_session = (SslDecryptSession *)conv_data;
else {
ssl_session = (SslDecryptSession *)wmem_alloc0(wmem_file_scope(), sizeof(SslDecryptSession));
ssl_session_init(ssl_session);
ssl_session->session.version = SSL_VER_UNKNOWN;
conversation_add_proto_data(conversation, proto_ssl, ssl_session);
}
session = &ssl_session->session;
is_from_server = ssl_packet_from_server(ssl_session, ssl_associations, pinfo);
if (pinfo->fd->flags.visited)
ssl_session = NULL;
ssl_debug_printf(" conversation = %p, ssl_session = %p\n", (void *)conversation, (void *)ssl_session);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SSL");
col_clear(pinfo->cinfo, COL_INFO);
if (tree)
{
ti = proto_tree_add_item(tree, proto_ssl, tvb, 0, -1, ENC_NA);
ssl_tree = proto_item_add_subtree(ti, ett_ssl);
}
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
ssl_debug_printf(" record: offset = %d, reported_length_remaining = %d\n", offset, tvb_reported_length_remaining(tvb, offset));
need_desegmentation = FALSE;
switch (session->version) {
case SSL_VER_SSLv2:
case SSL_VER_PCT:
offset = dissect_ssl2_record(tvb, pinfo, ssl_tree,
offset, session,
&need_desegmentation,
ssl_session,
first_record_in_frame);
break;
case SSL_VER_SSLv3:
case SSL_VER_TLS:
if (ssl_is_v2_client_hello(tvb, offset))
{
offset = dissect_ssl2_record(tvb, pinfo, ssl_tree,
offset, session,
&need_desegmentation,
ssl_session,
first_record_in_frame);
}
else
{
offset = dissect_ssl3_record(tvb, pinfo, ssl_tree,
offset, session, is_from_server,
&need_desegmentation,
ssl_session,
first_record_in_frame);
}
break;
default:
if (ssl_looks_like_sslv2(tvb, offset))
{
offset = dissect_ssl2_record(tvb, pinfo, ssl_tree,
offset, session,
&need_desegmentation,
ssl_session,
first_record_in_frame);
}
else if (ssl_looks_like_sslv3(tvb, offset))
{
offset = dissect_ssl3_record(tvb, pinfo, ssl_tree,
offset, session, is_from_server,
&need_desegmentation,
ssl_session,
first_record_in_frame);
}
else
{
if (!first_record_in_frame) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
offset = tvb_reported_length(tvb);
col_append_str(pinfo->cinfo, COL_INFO,
"Continuation Data");
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(session->version, ssl_version_short_names, "SSL"));
}
break;
}
if (need_desegmentation) {
ssl_debug_printf(" need_desegmentation: offset = %d, reported_length_remaining = %d\n",
offset, tvb_reported_length_remaining(tvb, offset));
tap_queue_packet(ssl_tap, pinfo, GINT_TO_POINTER(proto_ssl));
return tvb_captured_length(tvb);
}
first_record_in_frame = FALSE;
}
col_set_fence(pinfo->cinfo, COL_INFO);
ssl_debug_flush();
tap_queue_packet(ssl_tap, pinfo, GINT_TO_POINTER(proto_ssl));
return tvb_captured_length(tvb);
}
static gint
decrypt_ssl3_record(tvbuff_t *tvb, packet_info *pinfo, guint32 offset,
guint32 record_length, guint8 content_type, SslDecryptSession *ssl,
gboolean save_plaintext)
{
gint ret;
gint direction;
StringInfo *data_for_iv;
gint data_for_iv_len;
SslDecoder *decoder;
ret = 0;
ssl_debug_printf("decrypt_ssl3_record: app_data len %d, ssl state 0x%02X\n",
record_length, ssl->state);
direction = ssl_packet_from_server(ssl, ssl_associations, pinfo);
if (direction != 0) {
ssl_debug_printf("decrypt_ssl3_record: using server decoder\n");
decoder = ssl->server;
}
else {
ssl_debug_printf("decrypt_ssl3_record: using client decoder\n");
decoder = ssl->client;
}
data_for_iv = (direction != 0) ? &ssl->server_data_for_iv : &ssl->client_data_for_iv;
data_for_iv_len = (record_length < 24) ? record_length : 24;
ssl_data_set(data_for_iv, (const guchar*)tvb_get_ptr(tvb, offset + record_length - data_for_iv_len, data_for_iv_len), data_for_iv_len);
if (!decoder) {
ssl_debug_printf("decrypt_ssl3_record: no decoder available\n");
return ret;
}
ssl_decrypted_data_avail = ssl_decrypted_data.data_len;
if (ssl_decrypt_record(ssl, decoder,
content_type, tvb_get_ptr(tvb, offset, record_length),
record_length, &ssl_compressed_data, &ssl_decrypted_data, &ssl_decrypted_data_avail) == 0)
ret = 1;
if (!ret) {
data_for_iv = (direction != 0) ? &ssl->server_data_for_iv : &ssl->client_data_for_iv;
data_for_iv_len = (record_length < 24) ? record_length : 24;
ssl_data_set(data_for_iv, (const guchar*)tvb_get_ptr(tvb, offset + record_length - data_for_iv_len, data_for_iv_len), data_for_iv_len);
}
if (ret && save_plaintext) {
ssl_add_data_info(proto_ssl, pinfo, ssl_decrypted_data.data, ssl_decrypted_data_avail, tvb_raw_offset(tvb)+offset, decoder->flow);
}
return ret;
}
static void
desegment_ssl(tvbuff_t *tvb, packet_info *pinfo, int offset,
guint32 seq, guint32 nxtseq,
SslAssociation *association,
proto_tree *root_tree, proto_tree *tree,
SslFlow *flow)
{
fragment_head *ipfd_head;
gboolean must_desegment;
gboolean called_dissector;
int another_pdu_follows;
int deseg_offset;
guint32 deseg_seq;
gint nbytes;
proto_item *item;
proto_item *frag_tree_item;
proto_item *ssl_tree_item;
struct tcp_multisegment_pdu *msp;
again:
ipfd_head = NULL;
must_desegment = FALSE;
called_dissector = FALSE;
another_pdu_follows = 0;
msp = NULL;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
deseg_offset = offset;
if ((msp = (struct tcp_multisegment_pdu *)wmem_tree_lookup32(flow->multisegment_pdus, seq))) {
const char *prefix;
if (msp->first_frame == PINFO_FD_NUM(pinfo)) {
prefix = "";
col_set_str(pinfo->cinfo, COL_INFO, "[SSL segment of a reassembled PDU]");
} else {
prefix = "Retransmitted ";
}
nbytes = tvb_reported_length_remaining(tvb, offset);
ssl_proto_tree_add_segment_data(tree, tvb, offset, nbytes, prefix);
return;
}
msp = (struct tcp_multisegment_pdu *)wmem_tree_lookup32_le(flow->multisegment_pdus, seq-1);
if (msp && msp->seq <= seq && msp->nxtpdu > seq) {
int len;
if (!PINFO_FD_VISITED(pinfo)) {
msp->last_frame = pinfo->fd->num;
msp->last_frame_time = pinfo->fd->abs_ts;
}
if (msp->flags & MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT) {
len = MAX(0, tvb_reported_length_remaining(tvb, offset));
} else {
len = MIN(nxtseq, msp->nxtpdu) - seq;
}
ipfd_head = fragment_add(&ssl_reassembly_table, tvb, offset,
pinfo, msp->first_frame, NULL,
seq - msp->seq,
len, (LT_SEQ (nxtseq,msp->nxtpdu)));
if (msp->flags & MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT) {
msp->flags &= (~MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT);
msp->nxtpdu = nxtseq;
}
if ( (msp->nxtpdu < nxtseq)
&& (msp->nxtpdu >= seq)
&& (len > 0)) {
another_pdu_follows = msp->nxtpdu - seq;
}
} else {
process_ssl_payload(tvb, offset, pinfo, tree, association);
called_dissector = TRUE;
if (pinfo->desegment_len) {
if (!PINFO_FD_VISITED(pinfo))
must_desegment = TRUE;
deseg_offset = offset + pinfo->desegment_offset;
}
ipfd_head = NULL;
}
if (ipfd_head) {
if (ipfd_head->reassembled_in == pinfo->fd->num) {
tvbuff_t *next_tvb;
int old_len;
next_tvb = tvb_new_chain(tvb, ipfd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled SSL");
process_ssl_payload(next_tvb, 0, pinfo, tree, association);
called_dissector = TRUE;
old_len = (int)(tvb_reported_length(next_tvb) - tvb_reported_length_remaining(tvb, offset));
if (pinfo->desegment_len && pinfo->desegment_offset <= old_len) {
fragment_set_partial_reassembly(&ssl_reassembly_table,
pinfo, msp->first_frame, NULL);
if (pinfo->desegment_len == DESEGMENT_ONE_MORE_SEGMENT) {
msp->nxtpdu = seq + tvb_reported_length_remaining(tvb, offset) + 1;
msp->flags |= MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT;
} else {
msp->nxtpdu = seq + tvb_reported_length_remaining(tvb, offset) + pinfo->desegment_len;
}
another_pdu_follows = 0;
} else {
nbytes = tvb_reported_length_remaining(tvb, offset);
ssl_proto_tree_add_segment_data(tree, tvb, offset, nbytes, NULL);
show_fragment_tree(ipfd_head, &ssl_segment_items,
root_tree, pinfo, next_tvb, &frag_tree_item);
ssl_tree_item = proto_tree_get_parent(tree);
if (frag_tree_item && ssl_tree_item) {
proto_tree_move_item(root_tree, ssl_tree_item, frag_tree_item);
}
if (pinfo->desegment_len) {
if (!PINFO_FD_VISITED(pinfo))
must_desegment = TRUE;
deseg_offset = ipfd_head->datalen - pinfo->desegment_offset;
deseg_offset = tvb_reported_length(tvb) - deseg_offset;
}
}
}
}
if (must_desegment) {
if (pinfo->desegment_len == DESEGMENT_UNTIL_FIN) {
flow->flags |= TCP_FLOW_REASSEMBLE_UNTIL_FIN;
}
deseg_seq = seq + (deseg_offset - offset);
if (((nxtseq - deseg_seq) <= 1024*1024)
&& (!PINFO_FD_VISITED(pinfo))) {
if (pinfo->desegment_len == DESEGMENT_ONE_MORE_SEGMENT) {
msp = pdu_store_sequencenumber_of_next_pdu(pinfo,
deseg_seq, nxtseq+1, flow->multisegment_pdus);
msp->flags |= MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT;
} else {
msp = pdu_store_sequencenumber_of_next_pdu(pinfo,
deseg_seq, nxtseq+pinfo->desegment_len, flow->multisegment_pdus);
}
fragment_add(&ssl_reassembly_table, tvb, deseg_offset,
pinfo, msp->first_frame, NULL,
0, nxtseq - deseg_seq,
LT_SEQ(nxtseq, msp->nxtpdu));
}
}
if (!called_dissector || pinfo->desegment_len != 0) {
if (ipfd_head != NULL && ipfd_head->reassembled_in != 0 &&
!(ipfd_head->flags & FD_PARTIAL_REASSEMBLY)) {
item=proto_tree_add_uint(tree, *ssl_segment_items.hf_reassembled_in,
tvb, 0, 0, ipfd_head->reassembled_in);
PROTO_ITEM_SET_GENERATED(item);
}
if (pinfo->desegment_offset == 0) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SSL");
col_set_str(pinfo->cinfo, COL_INFO, "[SSL segment of a reassembled PDU]");
}
nbytes = tvb_reported_length_remaining(tvb, deseg_offset);
ssl_proto_tree_add_segment_data(tree, tvb, deseg_offset, nbytes, NULL);
}
pinfo->can_desegment = 0;
pinfo->desegment_offset = 0;
pinfo->desegment_len = 0;
if (another_pdu_follows) {
pinfo->can_desegment=2;
col_set_fence(pinfo->cinfo, COL_INFO);
col_set_writable(pinfo->cinfo, FALSE);
offset += another_pdu_follows;
seq += another_pdu_follows;
goto again;
}
}
static void
process_ssl_payload(tvbuff_t *tvb, volatile int offset, packet_info *pinfo,
proto_tree *tree, SslAssociation *association)
{
tvbuff_t *next_tvb;
heur_dtbl_entry_t *hdtbl_entry;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (association && association->handle) {
ssl_debug_printf("dissect_ssl3_record found association %p\n", (void *)association);
if (dissector_try_heuristic(ssl_heur_subdissector_list, next_tvb,
pinfo, proto_tree_get_root(tree), &hdtbl_entry, NULL)) {
} else {
if (have_tap_listener(exported_pdu_tap)) {
exp_pdu_data_t *exp_pdu_data;
guint8 tags = EXP_PDU_TAG_IP_SRC_BIT | EXP_PDU_TAG_IP_DST_BIT | EXP_PDU_TAG_SRC_PORT_BIT |
EXP_PDU_TAG_DST_PORT_BIT | EXP_PDU_TAG_ORIG_FNO_BIT;
exp_pdu_data = load_export_pdu_tags(pinfo, dissector_handle_get_dissector_name(association->handle), -1,
&tags, 1);
exp_pdu_data->tvb_captured_length = tvb_captured_length(next_tvb);
exp_pdu_data->tvb_reported_length = tvb_reported_length(next_tvb);
exp_pdu_data->pdu_tvb = next_tvb;
tap_queue_packet(exported_pdu_tap, pinfo, exp_pdu_data);
}
call_dissector(association->handle, next_tvb, pinfo, proto_tree_get_root(tree));
}
}
}
static void
dissect_ssl_payload(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree, SslAssociation *association)
{
gboolean save_fragmented;
guint16 save_can_desegment;
SslDataInfo *appl_data;
tvbuff_t *next_tvb;
save_can_desegment = pinfo->can_desegment;
appl_data = ssl_get_data_info(proto_ssl, pinfo, tvb_raw_offset(tvb)+offset);
if (!appl_data || !appl_data->plain_data.data_len) return;
ssl_debug_printf("dissect_ssl3_record decrypted len %d\n", appl_data->plain_data.data_len);
ssl_print_data("decrypted app data fragment", appl_data->plain_data.data, appl_data->plain_data.data_len);
next_tvb = tvb_new_child_real_data(tvb, appl_data->plain_data.data, appl_data->plain_data.data_len, appl_data->plain_data.data_len);
add_new_data_source(pinfo, next_tvb, "Decrypted SSL data");
if (ssl_desegment_app_data) {
pinfo->can_desegment = 2;
desegment_ssl(next_tvb, pinfo, 0, appl_data->seq, appl_data->nxtseq, association, proto_tree_get_root(tree), tree, appl_data->flow);
} else if (association && association->handle) {
pinfo->can_desegment = 0;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
process_ssl_payload(next_tvb, 0, pinfo, tree, association);
pinfo->fragmented = save_fragmented;
}
pinfo->can_desegment = save_can_desegment;
}
static gint
dissect_ssl3_record(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
SslSession *session, gint is_from_server,
gboolean *need_desegmentation,
SslDecryptSession *ssl, const gboolean first_record_in_frame)
{
guint32 record_length;
guint16 version;
guint8 content_type;
guint8 next_byte;
proto_tree *ti;
proto_tree *ssl_record_tree;
SslAssociation *association;
guint32 available_bytes;
ti = NULL;
ssl_record_tree = NULL;
available_bytes = tvb_reported_length_remaining(tvb, offset);
if ((session->version==SSL_VER_TLS || session->version==SSL_VER_TLSv1DOT1 || session->version==SSL_VER_TLSv1DOT2) &&
(available_bytes >=1 ) && !ssl_is_valid_content_type(tvb_get_guint8(tvb, offset))) {
proto_tree_add_text(tree, tvb, offset, available_bytes, "Ignored Unknown Record");
if (!first_record_in_frame) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
col_append_str(pinfo->cinfo, COL_INFO, "Ignored Unknown Record");
col_set_str(pinfo->cinfo, COL_PROTOCOL, val_to_str_const(session->version, ssl_version_short_names, "SSL"));
return offset + available_bytes;
}
if (available_bytes < 5) {
if (ssl_desegment && pinfo->can_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
*need_desegmentation = TRUE;
return offset;
} else {
return offset + available_bytes;
}
}
content_type = tvb_get_guint8(tvb, offset);
version = tvb_get_ntohs(tvb, offset + 1);
record_length = tvb_get_ntohs(tvb, offset + 3);
if (ssl_is_valid_content_type(content_type)) {
if (available_bytes < record_length + 5) {
if (ssl_desegment && pinfo->can_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = (record_length + 5) - available_bytes;
*need_desegmentation = TRUE;
return offset;
} else {
return offset + available_bytes;
}
}
} else {
if (!first_record_in_frame) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
col_append_str(pinfo->cinfo, COL_INFO, "Continuation Data");
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(session->version, ssl_version_short_names, "SSL"));
return offset + 5 + record_length;
}
ti = proto_tree_add_item(tree, hf_ssl_record, tvb,
offset, 5 + record_length, ENC_NA);
ssl_record_tree = proto_item_add_subtree(ti, ett_ssl_record);
proto_tree_add_item(ssl_record_tree, hf_ssl_record_content_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ssl_record_tree, hf_ssl_record_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_uint(ssl_record_tree, hf_ssl_record_length, tvb,
offset, 2, record_length);
offset += 2;
next_byte = tvb_get_guint8(tvb, offset);
if (session->version == SSL_VER_UNKNOWN
&& ssl_is_authoritative_version_message(content_type, next_byte))
{
if (version == SSLV3_VERSION)
{
session->version = SSL_VER_SSLv3;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
ssl_debug_printf("dissect_ssl3_record found version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
}
}
else if (version == TLSV1_VERSION)
{
session->version = SSL_VER_TLS;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
ssl_debug_printf("dissect_ssl3_record found version 0x%04X(TLS 1.0) -> state 0x%02X\n", ssl->version_netorder, ssl->state);
}
}
else if (version == TLSV1DOT1_VERSION)
{
session->version = SSL_VER_TLSv1DOT1;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
ssl_debug_printf("dissect_ssl3_record found version 0x%04X(TLS 1.1) -> state 0x%02X\n", ssl->version_netorder, ssl->state);
}
}
else if (version == TLSV1DOT2_VERSION)
{
session->version = SSL_VER_TLSv1DOT2;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
ssl_debug_printf("dissect_ssl3_record found version 0x%04X(TLS 1.2) -> state 0x%02X\n", ssl->version_netorder, ssl->state);
}
}
}
if (!first_record_in_frame) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(session->version, ssl_version_short_names, "SSL"));
ssl_debug_printf("dissect_ssl3_record: content_type %d %s\n",content_type, val_to_str_const(content_type, ssl_31_content_type, "unknown"));
switch ((ContentType) content_type) {
case SSL_ID_CHG_CIPHER_SPEC:
ssl_debug_printf("dissect_ssl3_change_cipher_spec\n");
col_append_str(pinfo->cinfo, COL_INFO, "Change Cipher Spec");
dissect_ssl3_change_cipher_spec(tvb, ssl_record_tree,
offset, session, content_type);
if (ssl) {
ssl_load_keyfile(ssl_options.keylog_filename, &ssl_keylog_file,
&ssl_master_key_map);
ssl_finalize_decryption(ssl, &ssl_master_key_map);
ssl_change_cipher(ssl, ssl_packet_from_server(ssl, ssl_associations, pinfo));
}
break;
case SSL_ID_ALERT:
{
tvbuff_t *decrypted;
if (ssl&&decrypt_ssl3_record(tvb, pinfo, offset,
record_length, content_type, ssl, FALSE))
ssl_add_record_info(proto_ssl, pinfo, ssl_decrypted_data.data,
ssl_decrypted_data_avail, offset);
decrypted = ssl_get_record_info(tvb, proto_ssl, pinfo, offset);
if (decrypted) {
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
dissect_ssl3_alert(decrypted, pinfo, ssl_record_tree, 0, session);
} else {
dissect_ssl3_alert(tvb, pinfo, ssl_record_tree, offset, session);
}
break;
}
case SSL_ID_HANDSHAKE:
{
tvbuff_t *decrypted;
if (ssl && decrypt_ssl3_record(tvb, pinfo, offset,
record_length, content_type, ssl, FALSE))
ssl_add_record_info(proto_ssl, pinfo, ssl_decrypted_data.data,
ssl_decrypted_data_avail, offset);
decrypted = ssl_get_record_info(tvb, proto_ssl, pinfo, offset);
if (decrypted) {
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
dissect_ssl3_handshake(decrypted, pinfo, ssl_record_tree, 0,
tvb_reported_length(decrypted), session,
is_from_server, ssl, content_type);
} else {
dissect_ssl3_handshake(tvb, pinfo, ssl_record_tree, offset,
record_length, session, is_from_server, ssl,
content_type);
}
break;
}
case SSL_ID_APP_DATA:
if (ssl){
decrypt_ssl3_record(tvb, pinfo, offset,
record_length, content_type, ssl, TRUE);
}
col_append_str(pinfo->cinfo, COL_INFO, "Application Data");
association = ssl_association_find(ssl_associations, pinfo->srcport, pinfo->ptype == PT_TCP);
association = association ? association: ssl_association_find(ssl_associations, pinfo->destport, pinfo->ptype == PT_TCP);
association = association ? association: ssl_association_find(ssl_associations, 0, pinfo->ptype == PT_TCP);
proto_item_set_text(ssl_record_tree,
"%s Record Layer: %s Protocol: %s",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"),
association?association->info:"Application Data");
proto_tree_add_item(ssl_record_tree, hf_ssl_record_appdata, tvb,
offset, record_length, ENC_NA);
dissect_ssl_payload(tvb, pinfo, offset, tree, association);
break;
case SSL_ID_HEARTBEAT:
{
tvbuff_t *decrypted;
if (ssl && decrypt_ssl3_record(tvb, pinfo, offset,
record_length, content_type, ssl, FALSE))
ssl_add_record_info(proto_ssl, pinfo, ssl_decrypted_data.data,
ssl_decrypted_data_avail, offset);
decrypted = ssl_get_record_info(tvb, proto_ssl, pinfo, offset);
if (decrypted) {
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
dissect_ssl3_heartbeat(decrypted, pinfo, ssl_record_tree, 0, session, tvb_reported_length (decrypted), TRUE);
} else {
gboolean plaintext = TRUE;
if (ssl) {
if (ssl_packet_from_server(ssl, ssl_associations, pinfo)) {
plaintext = ssl->server == NULL;
} else {
plaintext = ssl->client == NULL;
}
}
dissect_ssl3_heartbeat(tvb, pinfo, ssl_record_tree, offset, session, record_length, plaintext);
}
break;
}
}
offset += record_length;
return offset;
}
static void
dissect_ssl3_change_cipher_spec(tvbuff_t *tvb,
proto_tree *tree, guint32 offset,
const SslSession *session, const guint8 content_type)
{
if (tree)
{
proto_item_set_text(tree,
"%s Record Layer: %s Protocol: Change Cipher Spec",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"));
proto_tree_add_item(tree, hf_ssl_change_cipher_spec, tvb,
offset++, 1, ENC_NA);
}
}
static void
dissect_ssl3_alert(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
const SslSession *session)
{
proto_tree *ti;
proto_tree *ssl_alert_tree;
const gchar *level;
const gchar *desc;
guint8 byte;
ssl_alert_tree = NULL;
if (tree)
{
ti = proto_tree_add_item(tree, hf_ssl_alert_message, tvb,
offset, 2, ENC_NA);
ssl_alert_tree = proto_item_add_subtree(ti, ett_ssl_alert);
}
byte = tvb_get_guint8(tvb, offset);
level = try_val_to_str(byte, ssl_31_alert_level);
byte = tvb_get_guint8(tvb, offset+1);
desc = try_val_to_str(byte, ssl_31_alert_description);
if (level && desc)
{
col_append_fstr(pinfo->cinfo, COL_INFO,
"Alert (Level: %s, Description: %s)",
level, desc);
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, "Encrypted Alert");
}
if (tree)
{
if (level && desc)
{
proto_item_set_text(tree, "%s Record Layer: Alert "
"(Level: %s, Description: %s)",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
level, desc);
proto_tree_add_item(ssl_alert_tree, hf_ssl_alert_message_level,
tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_alert_tree, hf_ssl_alert_message_description,
tvb, offset++, 1, ENC_BIG_ENDIAN);
}
else
{
proto_item_set_text(tree,
"%s Record Layer: Encrypted Alert",
val_to_str_const(session->version, ssl_version_short_names, "SSL"));
proto_item_set_text(ssl_alert_tree,
"Alert Message: Encrypted Alert");
}
}
}
static void
dissect_ssl3_handshake(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
guint32 record_length, SslSession *session,
gint is_from_server,
SslDecryptSession *ssl, const guint8 content_type)
{
proto_tree *ssl_hand_tree;
const gchar *msg_type_str;
guint8 msg_type;
guint32 length;
gboolean first_iteration;
ssl_hand_tree = NULL;
first_iteration = TRUE;
record_length += offset;
while (offset < record_length)
{
msg_type = tvb_get_guint8(tvb, offset);
length = tvb_get_ntoh24(tvb, offset + 1);
if (offset + length <= record_length)
msg_type_str = try_val_to_str(msg_type, ssl_31_handshake_type);
else
msg_type_str = NULL;
ssl_debug_printf("dissect_ssl3_handshake iteration %d type %d offset %d length %d "
"bytes, remaining %d \n", first_iteration, msg_type, offset, length, record_length);
if (!msg_type_str && !first_iteration)
{
return;
}
if (!first_iteration)
{
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
col_append_str(pinfo->cinfo, COL_INFO, (msg_type_str != NULL)
? msg_type_str : "Encrypted Handshake Message");
if (tree)
{
proto_item *ti;
if (first_iteration)
{
proto_item_set_text(tree, "%s Record Layer: %s Protocol: %s",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"),
(msg_type_str!=NULL) ? msg_type_str :
"Encrypted Handshake Message");
}
else
{
proto_item_set_text(tree, "%s Record Layer: %s Protocol: %s",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"),
"Multiple Handshake Messages");
}
ti = proto_tree_add_item(tree, hf_ssl_handshake_protocol, tvb,
offset, length + 4, ENC_NA);
ssl_hand_tree = proto_item_add_subtree(ti, ett_ssl_handshake);
if (ssl_hand_tree)
{
proto_item_set_text(ssl_hand_tree, "Handshake Protocol: %s",
(msg_type_str != NULL) ? msg_type_str :
"Encrypted Handshake Message");
}
}
if (!msg_type_str)
return;
if (ssl_hand_tree || ssl)
{
if (ssl_hand_tree)
proto_tree_add_uint(ssl_hand_tree, hf_ssl_handshake_type,
tvb, offset, 1, msg_type);
offset += 1;
if (ssl_hand_tree)
proto_tree_add_uint(ssl_hand_tree, hf_ssl_handshake_length,
tvb, offset, 3, length);
offset += 3;
switch ((HandshakeType) msg_type) {
case SSL_HND_HELLO_REQUEST:
break;
case SSL_HND_CLIENT_HELLO:
if (ssl) {
ssl_set_server(ssl, &pinfo->dst, pinfo->ptype, pinfo->destport);
ssl_find_private_key(ssl, ssl_key_hash, ssl_associations, pinfo);
}
ssl_dissect_hnd_cli_hello(&dissect_ssl3_hf, tvb, pinfo,
ssl_hand_tree, offset, length, session, ssl,
NULL);
break;
case SSL_HND_SERVER_HELLO:
ssl_dissect_hnd_srv_hello(&dissect_ssl3_hf, tvb, ssl_hand_tree,
offset, length, session, ssl);
break;
case SSL_HND_HELLO_VERIFY_REQUEST:
break;
case SSL_HND_NEWSESSION_TICKET:
ssl_dissect_hnd_new_ses_ticket(&dissect_ssl3_hf, tvb,
ssl_hand_tree, offset, ssl,
ssl_master_key_map.session);
break;
case SSL_HND_CERTIFICATE:
ssl_dissect_hnd_cert(&dissect_ssl3_hf, tvb, ssl_hand_tree, offset, pinfo, session, is_from_server);
break;
case SSL_HND_SERVER_KEY_EXCHG:
ssl_dissect_hnd_srv_keyex(&dissect_ssl3_hf, tvb, ssl_hand_tree, offset, length, session);
break;
case SSL_HND_CERT_REQUEST:
ssl_dissect_hnd_cert_req(&dissect_ssl3_hf, tvb, ssl_hand_tree, offset, pinfo, session);
break;
case SSL_HND_SVR_HELLO_DONE:
break;
case SSL_HND_CERT_VERIFY:
dissect_ssl3_hnd_cli_cert_verify(tvb, ssl_hand_tree, offset, length);
break;
case SSL_HND_CLIENT_KEY_EXCHG:
ssl_dissect_hnd_cli_keyex(&dissect_ssl3_hf, tvb, ssl_hand_tree, offset, length, session);
if (!ssl)
break;
ssl_load_keyfile(ssl_options.keylog_filename, &ssl_keylog_file,
&ssl_master_key_map);
if (!ssl_generate_pre_master_secret(ssl, length, tvb, offset,
ssl_options.psk,
&ssl_master_key_map)) {
ssl_debug_printf("dissect_ssl3_handshake can't generate pre master secret\n");
}
break;
case SSL_HND_FINISHED:
ssl_dissect_hnd_finished(&dissect_ssl3_hf, tvb, ssl_hand_tree,
offset, session, &ssl_hfs);
break;
case SSL_HND_CERT_URL:
ssl_dissect_hnd_cert_url(&dissect_ssl3_hf, tvb, ssl_hand_tree, offset);
break;
case SSL_HND_CERT_STATUS:
dissect_ssl3_hnd_cert_status(tvb, ssl_hand_tree, offset, pinfo);
break;
case SSL_HND_SUPPLEMENTAL_DATA:
break;
case SSL_HND_ENCRYPTED_EXTS:
dissect_ssl3_hnd_encrypted_exts(tvb, ssl_hand_tree, offset);
break;
}
}
else
offset += 4;
offset += length;
first_iteration = FALSE;
}
}
static void
dissect_ssl3_heartbeat(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
const SslSession *session, guint32 record_length,
gboolean decrypted)
{
proto_item *ti;
proto_tree *tls_heartbeat_tree;
const gchar *type;
guint8 byte;
guint16 payload_length;
guint16 padding_length;
tls_heartbeat_tree = NULL;
if (tree) {
ti = proto_tree_add_item(tree, hf_ssl_heartbeat_message, tvb,
offset, record_length - 32, ENC_NA);
tls_heartbeat_tree = proto_item_add_subtree(ti, ett_ssl_heartbeat);
}
byte = tvb_get_guint8(tvb, offset);
type = try_val_to_str(byte, tls_heartbeat_type);
payload_length = tvb_get_ntohs(tvb, offset + 1);
padding_length = record_length - 3 - payload_length;
if (type && ((payload_length <= record_length - 16 - 3) || decrypted)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "Heartbeat %s", type);
} else {
col_append_str(pinfo->cinfo, COL_INFO, "Encrypted Heartbeat");
}
if (tree) {
if (type && ((payload_length <= record_length - 16 - 3) || decrypted)) {
proto_item_set_text(tree, "%s Record Layer: Heartbeat "
"%s",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
type);
proto_tree_add_item(tls_heartbeat_tree, hf_ssl_heartbeat_message_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_uint(tls_heartbeat_tree, hf_ssl_heartbeat_message_payload_length,
tvb, offset, 2, payload_length);
offset += 2;
if (payload_length > record_length - 16 - 3) {
expert_add_info_format(pinfo, ti, &ei_ssl3_heartbeat_payload_length,
"Invalid payload heartbeat length (%d)", payload_length);
payload_length = record_length - 16 - 3;
padding_length = 16;
proto_item_append_text (ti, " (invalid, using %u to decode payload)", payload_length);
}
proto_tree_add_bytes_format(tls_heartbeat_tree, hf_ssl_heartbeat_message_payload,
tvb, offset, payload_length,
NULL, "Payload (%u byte%s)",
payload_length,
plurality(payload_length, "", "s"));
offset += payload_length;
proto_tree_add_bytes_format(tls_heartbeat_tree, hf_ssl_heartbeat_message_padding,
tvb, offset, padding_length,
NULL, "Padding and HMAC (%u byte%s)",
padding_length,
plurality(padding_length, "", "s"));
} else {
proto_item_set_text(tree,
"%s Record Layer: Encrypted Heartbeat",
val_to_str_const(session->version, ssl_version_short_names, "SSL"));
proto_item_set_text(tls_heartbeat_tree,
"Encrypted Heartbeat Message");
}
}
}
static void
dissect_ssl3_hnd_cli_cert_verify(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 length)
{
proto_tree *ssl_sig_tree;
ssl_sig_tree = proto_tree_add_subtree(tree, tvb, offset, length,
ett_ssl_cli_sig, NULL, "Signature with client's private key");
proto_tree_add_item(ssl_sig_tree, hf_ssl_handshake_client_cert_vrfy_sig_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_sig_tree, hf_ssl_handshake_client_cert_vrfy_sig,
tvb, offset+2, length-2, ENC_NA);
}
static guint
dissect_ssl3_ocsp_response(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, packet_info *pinfo)
{
guint cert_status_len;
proto_item *ti;
proto_tree *cert_status_tree;
cert_status_len = tvb_get_ntoh24(tvb, offset);
ti = proto_tree_add_item(tree, hf_ssl_handshake_cert_status,
tvb, offset, cert_status_len + 3,
ENC_NA);
cert_status_tree = proto_item_add_subtree(ti, ett_ssl_cert_status);
proto_tree_add_item(cert_status_tree, hf_ssl_handshake_cert_status_len,
tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
if (cert_status_len > 0) {
proto_item *ocsp_resp;
proto_tree *ocsp_resp_tree;
asn1_ctx_t asn1_ctx;
ocsp_resp = proto_tree_add_item(cert_status_tree,
proto_ocsp, tvb, offset,
cert_status_len, ENC_BIG_ENDIAN);
proto_item_set_text(ocsp_resp, "OCSP Response");
ocsp_resp_tree = proto_item_add_subtree(ocsp_resp,
ett_ssl_ocsp_resp);
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ocsp_OCSPResponse(FALSE, tvb, offset, &asn1_ctx,
ocsp_resp_tree, -1);
offset += cert_status_len;
}
return offset;
}
static void
dissect_ssl3_hnd_cert_status(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, packet_info *pinfo)
{
guint8 cert_status_type;
cert_status_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ssl_handshake_cert_status_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (cert_status_type) {
case SSL_HND_CERT_STATUS_TYPE_OCSP:
dissect_ssl3_ocsp_response(tvb, tree, offset, pinfo);
break;
case SSL_HND_CERT_STATUS_TYPE_OCSP_MULTI:
{
guint list_len;
list_len = tvb_get_ntoh24(tvb, offset);
offset += 3;
while (list_len-- > 0)
offset = dissect_ssl3_ocsp_response(tvb, tree, offset, pinfo);
break;
}
}
}
static void
dissect_ssl3_hnd_encrypted_exts(tvbuff_t *tvb, proto_tree *tree,
guint32 offset)
{
guint8 selected_protocol_len;
guint8 padding_len;
selected_protocol_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ssl_handshake_npn_selected_protocol_len,
tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_ssl_handshake_npn_selected_protocol,
tvb, offset, selected_protocol_len, ENC_ASCII|ENC_NA);
offset += selected_protocol_len;
padding_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ssl_handshake_npn_padding_len,
tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_ssl_handshake_npn_padding,
tvb, offset, padding_len, ENC_NA);
}
static gint
dissect_ssl2_record(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint32 offset, SslSession *session,
gboolean *need_desegmentation,
SslDecryptSession *ssl, gboolean first_record_in_frame)
{
guint32 initial_offset;
guint8 byte;
guint8 record_length_length;
guint32 record_length;
gint is_escape;
gint16 padding_length;
guint8 msg_type;
const gchar *msg_type_str;
guint32 available_bytes;
proto_item *ti;
proto_tree *ssl_record_tree;
initial_offset = offset;
record_length = 0;
is_escape = -1;
padding_length = -1;
msg_type_str = NULL;
ssl_record_tree = NULL;
byte = tvb_get_guint8(tvb, offset);
record_length_length = (byte & 0x80) ? 2 : 3;
available_bytes = tvb_reported_length_remaining(tvb, offset);
if (available_bytes < record_length_length) {
if (ssl_desegment && pinfo->can_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
*need_desegmentation = TRUE;
return offset;
} else {
return offset + available_bytes;
}
}
switch (record_length_length) {
case 2:
record_length = (byte & 0x7f) << 8;
byte = tvb_get_guint8(tvb, offset + 1);
record_length += byte;
break;
case 3:
is_escape = (byte & 0x40) ? TRUE : FALSE;
record_length = (byte & 0x3f) << 8;
byte = tvb_get_guint8(tvb, offset + 1);
record_length += byte;
byte = tvb_get_guint8(tvb, offset + 2);
padding_length = byte;
}
if (available_bytes < (record_length_length + record_length)) {
if (ssl_desegment && pinfo->can_desegment) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = (record_length_length + record_length)
- available_bytes;
*need_desegmentation = TRUE;
return offset;
} else {
return offset + available_bytes;
}
}
offset += record_length_length;
if (!first_record_in_frame) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
ti = proto_tree_add_item(tree, hf_ssl2_record, tvb, initial_offset,
record_length_length + record_length, ENC_NA);
ssl_record_tree = proto_item_add_subtree(ti, ett_ssl_record);
msg_type = tvb_get_guint8(tvb, initial_offset + record_length_length);
if (session->version == SSL_VER_UNKNOWN)
{
if (ssl_looks_like_valid_pct_handshake(tvb,
(initial_offset +
record_length_length),
record_length)) {
session->version = SSL_VER_PCT;
}
else if (msg_type >= 2 && msg_type <= 8)
{
session->version = SSL_VER_SSLv2;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL,
(session->version == SSL_VER_PCT) ? "PCT" : "SSLv2");
msg_type_str = try_val_to_str(msg_type,
(session->version == SSL_VER_PCT)
? pct_msg_types : ssl_20_msg_types);
if (!msg_type_str
|| ((session->version != SSL_VER_PCT) &&
!ssl_looks_like_valid_v2_handshake(tvb, initial_offset
+ record_length_length,
record_length))
|| ((session->version == SSL_VER_PCT) &&
!ssl_looks_like_valid_pct_handshake(tvb, initial_offset
+ record_length_length,
record_length)))
{
if (ssl_record_tree)
{
proto_item_set_text(ssl_record_tree, "%s Record Layer: %s",
(session->version == SSL_VER_PCT)
? "PCT" : "SSLv2",
"Encrypted Data");
ti = proto_tree_add_uint(ssl_record_tree,
hf_ssl_record_version, tvb,
initial_offset, 0, 0x0002);
PROTO_ITEM_SET_GENERATED(ti);
}
col_append_str(pinfo->cinfo, COL_INFO, "Encrypted Data");
return initial_offset + record_length_length + record_length;
}
else
{
col_append_str(pinfo->cinfo, COL_INFO, msg_type_str);
if (ssl_record_tree)
{
proto_item_set_text(ssl_record_tree, "%s Record Layer: %s",
(session->version == SSL_VER_PCT)
? "PCT" : "SSLv2",
msg_type_str);
}
}
if (ssl_record_tree)
{
ti = proto_tree_add_uint(ssl_record_tree,
hf_ssl_record_version, tvb,
initial_offset, 0, 0x0002);
PROTO_ITEM_SET_GENERATED(ti);
tvb_ensure_bytes_exist(tvb, offset, record_length_length);
proto_tree_add_uint (ssl_record_tree,
hf_ssl_record_length, tvb,
initial_offset, record_length_length,
record_length);
}
if (ssl_record_tree && is_escape != -1)
{
proto_tree_add_boolean(ssl_record_tree,
hf_ssl2_record_is_escape, tvb,
initial_offset, 1, is_escape);
}
if (ssl_record_tree && padding_length != -1)
{
proto_tree_add_uint(ssl_record_tree,
hf_ssl2_record_padding_length, tvb,
initial_offset + 2, 1, padding_length);
}
offset = initial_offset + record_length_length;
if (ssl_record_tree)
{
proto_tree_add_item(ssl_record_tree,
(session->version == SSL_VER_PCT)
? hf_pct_msg_type : hf_ssl2_msg_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
if (session->version != SSL_VER_PCT)
{
switch (msg_type) {
case SSL2_HND_CLIENT_HELLO:
dissect_ssl2_hnd_client_hello(tvb, pinfo, ssl_record_tree, offset, ssl);
break;
case SSL2_HND_CLIENT_MASTER_KEY:
dissect_ssl2_hnd_client_master_key(tvb, ssl_record_tree, offset);
break;
case SSL2_HND_SERVER_HELLO:
dissect_ssl2_hnd_server_hello(tvb, ssl_record_tree, offset, pinfo);
break;
case SSL2_HND_ERROR:
case SSL2_HND_CLIENT_FINISHED:
case SSL2_HND_SERVER_VERIFY:
case SSL2_HND_SERVER_FINISHED:
case SSL2_HND_REQUEST_CERTIFICATE:
case SSL2_HND_CLIENT_CERTIFICATE:
break;
default:
break;
}
}
else
{
switch (msg_type) {
case PCT_MSG_CLIENT_HELLO:
dissect_pct_msg_client_hello(tvb, ssl_record_tree, offset);
break;
case PCT_MSG_SERVER_HELLO:
dissect_pct_msg_server_hello(tvb, ssl_record_tree, offset, pinfo);
break;
case PCT_MSG_CLIENT_MASTER_KEY:
dissect_pct_msg_client_master_key(tvb, ssl_record_tree, offset);
break;
case PCT_MSG_SERVER_VERIFY:
dissect_pct_msg_server_verify(tvb, ssl_record_tree, offset);
break;
case PCT_MSG_ERROR:
dissect_pct_msg_error(tvb, ssl_record_tree, offset);
break;
default:
break;
}
}
return (initial_offset + record_length_length + record_length);
}
static void
dissect_ssl2_hnd_client_hello(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
SslDecryptSession *ssl)
{
guint16 version;
guint16 cipher_spec_length;
guint16 session_id_length;
guint16 challenge_length;
proto_item *ti;
proto_tree *cs_tree;
cs_tree=0;
version = tvb_get_ntohs(tvb, offset);
if (!ssl_is_valid_ssl_version(version))
{
return;
}
if (ssl) {
ssl_set_server(ssl, &pinfo->dst, pinfo->ptype, pinfo->destport);
ssl_find_private_key(ssl, ssl_key_hash, ssl_associations, pinfo);
}
if (tree || ssl)
{
if (tree)
proto_tree_add_item(tree, dissect_ssl3_hf.hf.hs_client_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
cipher_spec_length = tvb_get_ntohs(tvb, offset);
if (tree)
proto_tree_add_item(tree, hf_ssl2_handshake_cipher_spec_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
session_id_length = tvb_get_ntohs(tvb, offset);
if (tree)
proto_tree_add_item(tree, hf_ssl2_handshake_session_id_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
if (session_id_length > SSLV2_MAX_SESSION_ID_LENGTH_IN_BYTES) {
proto_tree_add_text(tree, tvb, offset, 2,
"Invalid session ID length: %d", session_id_length);
expert_add_info_format(pinfo, NULL, &ei_ssl2_handshake_session_id_len_error,
"Session ID length (%u) must be less than %u.",
session_id_length, SSLV2_MAX_SESSION_ID_LENGTH_IN_BYTES);
return;
}
offset += 2;
challenge_length = tvb_get_ntohs(tvb, offset);
if (tree)
proto_tree_add_item(tree, hf_ssl2_handshake_challenge_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (tree)
{
tvb_ensure_bytes_exist(tvb, offset, cipher_spec_length);
ti = proto_tree_add_none_format(tree, dissect_ssl3_hf.hf.hs_cipher_suites,
tvb, offset, cipher_spec_length,
"Cipher Specs (%u specs)",
cipher_spec_length/3);
cs_tree = proto_item_add_subtree(ti, dissect_ssl3_hf.ett.cipher_suites);
if (!cs_tree)
{
cs_tree = tree;
}
}
while (cipher_spec_length > 0)
{
if (cs_tree)
proto_tree_add_item(cs_tree, hf_ssl2_handshake_cipher_spec,
tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
cipher_spec_length -= 3;
}
if (session_id_length > 0)
{
if (tree)
{
tvb_ensure_bytes_exist(tvb, offset, session_id_length);
proto_tree_add_bytes_format(tree,
dissect_ssl3_hf.hf.hs_session_id,
tvb, offset, session_id_length,
NULL, "Session ID (%u byte%s)",
session_id_length,
plurality(session_id_length, "", "s"));
}
if (ssl)
{
tvb_memcpy(tvb,ssl->session_id.data, offset, session_id_length);
ssl->session_id.data_len = session_id_length;
ssl->state &= ~(SSL_HAVE_SESSION_KEY|SSL_MASTER_SECRET|SSL_PRE_MASTER_SECRET|
SSL_CIPHER|SSL_SERVER_RANDOM);
}
offset += session_id_length;
}
if (challenge_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, challenge_length);
if (tree)
proto_tree_add_item(tree, hf_ssl2_handshake_challenge,
tvb, offset, challenge_length, ENC_NA);
if (ssl)
{
gint max;
max = challenge_length > 32? 32: challenge_length;
ssl_debug_printf("client random len: %d padded to 32\n", challenge_length);
memset(ssl->client_random.data, 0, 32 - max);
tvb_memcpy(tvb, &ssl->client_random.data[32 - max], offset, max);
ssl->client_random.data_len = 32;
ssl->state |= SSL_CLIENT_RANDOM;
ssl_debug_printf("dissect_ssl2_hnd_client_hello found CLIENT RANDOM -> state 0x%02X\n", ssl->state);
}
}
}
}
static void
dissect_pct_msg_client_hello(tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
guint16 CH_CLIENT_VERSION, CH_OFFSET, CH_CIPHER_SPECS_LENGTH, CH_HASH_SPECS_LENGTH, CH_CERT_SPECS_LENGTH, CH_EXCH_SPECS_LENGTH, CH_KEY_ARG_LENGTH;
proto_item *CH_CIPHER_SPECS_ti, *CH_HASH_SPECS_ti, *CH_CERT_SPECS_ti, *CH_EXCH_SPECS_ti;
proto_tree *CH_CIPHER_SPECS_tree, *CH_HASH_SPECS_tree, *CH_CERT_SPECS_tree, *CH_EXCH_SPECS_tree;
gint i;
CH_CLIENT_VERSION = tvb_get_ntohs(tvb, offset);
if (CH_CLIENT_VERSION != PCT_VERSION_1)
proto_tree_add_text(tree, tvb, offset, 2, "Client Version, should be %x in PCT version 1", PCT_VERSION_1);
else
proto_tree_add_text(tree, tvb, offset, 2, "Client Version (%x)", PCT_VERSION_1);
offset += 2;
proto_tree_add_text(tree, tvb, offset, 1, "PAD");
offset += 1;
proto_tree_add_text(tree, tvb, offset, 32, "Client Session ID Data (32 bytes)");
offset += 32;
proto_tree_add_text(tree, tvb, offset, 32, "Challenge Data(32 bytes)");
offset += 32;
CH_OFFSET = tvb_get_ntohs(tvb, offset);
if (CH_OFFSET != PCT_CH_OFFSET_V1)
proto_tree_add_text(tree, tvb, offset, 2, "CH_OFFSET: %d, should be %d in PCT version 1", CH_OFFSET, PCT_CH_OFFSET_V1);
else
proto_tree_add_text(tree, tvb, offset, 2, "CH_OFFSET: %d", CH_OFFSET);
offset += 2;
CH_CIPHER_SPECS_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "CIPHER_SPECS Length: %d", CH_CIPHER_SPECS_LENGTH);
offset += 2;
CH_HASH_SPECS_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "HASH_SPECS Length: %d", CH_HASH_SPECS_LENGTH);
offset += 2;
CH_CERT_SPECS_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "CERT_SPECS Length: %d", CH_CERT_SPECS_LENGTH);
offset += 2;
CH_EXCH_SPECS_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "EXCH_SPECS Length: %d", CH_EXCH_SPECS_LENGTH);
offset += 2;
CH_KEY_ARG_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "IV Length: %d", CH_KEY_ARG_LENGTH);
offset += 2;
if (CH_CIPHER_SPECS_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CH_CIPHER_SPECS_LENGTH);
CH_CIPHER_SPECS_ti = proto_tree_add_item(tree, hf_pct_handshake_cipher_spec, tvb, offset, CH_CIPHER_SPECS_LENGTH, ENC_NA);
CH_CIPHER_SPECS_tree = proto_item_add_subtree(CH_CIPHER_SPECS_ti, ett_pct_cipher_suites);
for(i=0; i<(CH_CIPHER_SPECS_LENGTH/4); i++) {
proto_tree_add_item(CH_CIPHER_SPECS_tree, hf_pct_handshake_cipher, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_text(CH_CIPHER_SPECS_tree, tvb, offset, 1, "Encryption key length: %d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_text(CH_CIPHER_SPECS_tree, tvb, offset, 1, "MAC key length in bits: %d", tvb_get_guint8(tvb, offset) + 64);
offset += 1;
}
}
if (CH_HASH_SPECS_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CH_HASH_SPECS_LENGTH);
CH_HASH_SPECS_ti = proto_tree_add_item(tree, hf_pct_handshake_hash_spec, tvb, offset, CH_HASH_SPECS_LENGTH, ENC_NA);
CH_HASH_SPECS_tree = proto_item_add_subtree(CH_HASH_SPECS_ti, ett_pct_hash_suites);
for(i=0; i<(CH_HASH_SPECS_LENGTH/2); i++) {
proto_tree_add_item(CH_HASH_SPECS_tree, hf_pct_handshake_hash, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
if (CH_CERT_SPECS_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CH_CERT_SPECS_LENGTH);
CH_CERT_SPECS_ti = proto_tree_add_item(tree, hf_pct_handshake_cert_spec, tvb, offset, CH_CERT_SPECS_LENGTH, ENC_NA);
CH_CERT_SPECS_tree = proto_item_add_subtree(CH_CERT_SPECS_ti, ett_pct_cert_suites);
for(i=0; i< (CH_CERT_SPECS_LENGTH/2); i++) {
proto_tree_add_item(CH_CERT_SPECS_tree, hf_pct_handshake_cert, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
if (CH_EXCH_SPECS_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CH_EXCH_SPECS_LENGTH);
CH_EXCH_SPECS_ti = proto_tree_add_item(tree, hf_pct_handshake_exch_spec, tvb, offset, CH_EXCH_SPECS_LENGTH, ENC_NA);
CH_EXCH_SPECS_tree = proto_item_add_subtree(CH_EXCH_SPECS_ti, ett_pct_exch_suites);
for(i=0; i<(CH_EXCH_SPECS_LENGTH/2); i++) {
proto_tree_add_item(CH_EXCH_SPECS_tree, hf_pct_handshake_exch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
}
if (CH_KEY_ARG_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CH_KEY_ARG_LENGTH);
proto_tree_add_text(tree, tvb, offset, CH_KEY_ARG_LENGTH, "IV data (%d bytes)", CH_KEY_ARG_LENGTH);
}
}
static void
dissect_pct_msg_server_hello(tvbuff_t *tvb, proto_tree *tree, guint32 offset, packet_info *pinfo)
{
guint16 SH_SERVER_VERSION, SH_CERT_LENGTH, SH_CERT_SPECS_LENGTH, SH_CLIENT_SIG_LENGTH, SH_RESPONSE_LENGTH;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
proto_tree_add_text(tree, tvb, offset, 1, "PAD");
offset += 1;
SH_SERVER_VERSION = tvb_get_ntohs(tvb, offset);
if (SH_SERVER_VERSION != PCT_VERSION_1)
proto_tree_add_text(tree, tvb, offset, 2, "Server Version, should be %x in PCT version 1", PCT_VERSION_1);
else
proto_tree_add_text(tree, tvb, offset, 2, "Server Version (%x)", PCT_VERSION_1);
offset += 2;
proto_tree_add_text(tree, tvb, offset, 1, "SH_RESTART_SESSION_OK flag");
offset += 1;
proto_tree_add_text(tree, tvb, offset, 1, "SH_CLIENT_AUTH_REQ flag");
offset += 1;
proto_tree_add_item(tree, hf_pct_handshake_cipher, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_text(tree, tvb, offset, 1, "Encryption key length: %d", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_text(tree, tvb, offset, 1, "MAC key length in bits: %d", tvb_get_guint8(tvb, offset) + 64);
offset += 1;
proto_tree_add_item(tree, hf_pct_handshake_hash, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_pct_handshake_cert, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_pct_handshake_exch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_text(tree, tvb, offset, 32, "Connection ID Data (32 bytes)");
offset += 32;
SH_CERT_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Server Certificate Length: %d", SH_CERT_LENGTH);
offset += 2;
SH_CERT_SPECS_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Client CERT_SPECS Length: %d", SH_CERT_SPECS_LENGTH);
offset += 2;
SH_CLIENT_SIG_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Client SIG_SPECS Length: %d", SH_CLIENT_SIG_LENGTH);
offset += 2;
SH_RESPONSE_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Response Length: %d", SH_RESPONSE_LENGTH);
offset += 2;
if (SH_CERT_LENGTH) {
dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_pct_handshake_server_cert);
offset += SH_CERT_LENGTH;
}
if (SH_CERT_SPECS_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, SH_CERT_SPECS_LENGTH);
proto_tree_add_text(tree, tvb, offset, SH_CERT_SPECS_LENGTH, "Client CERT_SPECS (%d bytes)", SH_CERT_SPECS_LENGTH);
offset += SH_CERT_SPECS_LENGTH;
}
if (SH_CLIENT_SIG_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, SH_CLIENT_SIG_LENGTH);
proto_tree_add_text(tree, tvb, offset, SH_CLIENT_SIG_LENGTH, "Client Signature (%d bytes)", SH_CLIENT_SIG_LENGTH);
offset += SH_CLIENT_SIG_LENGTH;
}
if (SH_RESPONSE_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, SH_RESPONSE_LENGTH);
proto_tree_add_text(tree, tvb, offset, SH_RESPONSE_LENGTH, "Server Response (%d bytes)", SH_RESPONSE_LENGTH);
}
}
static void
dissect_pct_msg_client_master_key(tvbuff_t *tvb, proto_tree *tree, guint32 offset)
{
guint16 CMK_CLEAR_KEY_LENGTH, CMK_ENCRYPTED_KEY_LENGTH, CMK_KEY_ARG_LENGTH, CMK_VERIFY_PRELUDE, CMK_CLIENT_CERT_LENGTH, CMK_RESPONSE_LENGTH;
proto_tree_add_text(tree, tvb, offset, 1, "PAD");
offset += 1;
proto_tree_add_item(tree, hf_pct_handshake_cert, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_pct_handshake_sig, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
CMK_CLEAR_KEY_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Clear Key Length: %d",CMK_CLEAR_KEY_LENGTH);
offset += 2;
CMK_ENCRYPTED_KEY_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Encrypted Key Length: %d",CMK_ENCRYPTED_KEY_LENGTH);
offset += 2;
CMK_KEY_ARG_LENGTH= tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "IV Length: %d",CMK_KEY_ARG_LENGTH);
offset += 2;
CMK_VERIFY_PRELUDE = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Verify Prelude Length: %d",CMK_VERIFY_PRELUDE);
offset += 2;
CMK_CLIENT_CERT_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Client Cert Length: %d",CMK_CLIENT_CERT_LENGTH);
offset += 2;
CMK_RESPONSE_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Response Length: %d",CMK_RESPONSE_LENGTH);
offset += 2;
if (CMK_CLEAR_KEY_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CMK_CLEAR_KEY_LENGTH);
proto_tree_add_text(tree, tvb, offset, CMK_CLEAR_KEY_LENGTH, "Clear Key data (%d bytes)", CMK_CLEAR_KEY_LENGTH);
offset += CMK_CLEAR_KEY_LENGTH;
}
if (CMK_ENCRYPTED_KEY_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CMK_ENCRYPTED_KEY_LENGTH);
proto_tree_add_text(tree, tvb, offset, CMK_ENCRYPTED_KEY_LENGTH, "Encrypted Key data (%d bytes)", CMK_ENCRYPTED_KEY_LENGTH);
offset += CMK_ENCRYPTED_KEY_LENGTH;
}
if (CMK_KEY_ARG_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CMK_KEY_ARG_LENGTH);
proto_tree_add_text(tree, tvb, offset, CMK_KEY_ARG_LENGTH, "IV data (%d bytes)", CMK_KEY_ARG_LENGTH);
offset += CMK_KEY_ARG_LENGTH;
}
if (CMK_VERIFY_PRELUDE) {
tvb_ensure_bytes_exist(tvb, offset, CMK_VERIFY_PRELUDE);
proto_tree_add_text(tree, tvb, offset, CMK_VERIFY_PRELUDE, "Verify Prelude data (%d bytes)", CMK_VERIFY_PRELUDE);
offset += CMK_VERIFY_PRELUDE;
}
if (CMK_CLIENT_CERT_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CMK_CLIENT_CERT_LENGTH);
proto_tree_add_text(tree, tvb, offset, CMK_CLIENT_CERT_LENGTH, "Client Certificate data (%d bytes)", CMK_CLIENT_CERT_LENGTH);
offset += CMK_CLIENT_CERT_LENGTH;
}
if (CMK_RESPONSE_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, CMK_RESPONSE_LENGTH);
proto_tree_add_text(tree, tvb, offset, CMK_RESPONSE_LENGTH, "Response data (%d bytes)", CMK_RESPONSE_LENGTH);
}
}
static void
dissect_pct_msg_server_verify(tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
guint16 SV_RESPONSE_LENGTH;
proto_tree_add_text(tree, tvb, offset, 1, "PAD");
offset += 1;
proto_tree_add_text(tree, tvb, offset, 32, "Server Session ID data (32 bytes)");
offset += 32;
SV_RESPONSE_LENGTH = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Server Response Length: %d", SV_RESPONSE_LENGTH);
offset += 2;
if (SV_RESPONSE_LENGTH) {
tvb_ensure_bytes_exist(tvb, offset, SV_RESPONSE_LENGTH);
proto_tree_add_text(tree, tvb, offset, SV_RESPONSE_LENGTH, "Server Response (%d bytes)", SV_RESPONSE_LENGTH);
}
}
static void
dissect_pct_msg_error(tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
guint16 ERROR_CODE, INFO_LEN;
ERROR_CODE = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_pct_msg_error_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
INFO_LEN = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2, "Error Information Length: %d", INFO_LEN);
offset += 2;
if (ERROR_CODE == PCT_ERR_SPECS_MISMATCH && INFO_LEN == 6)
{
proto_tree_add_text(tree, tvb, offset, 1, "SPECS_MISMATCH_CIPHER");
offset += 1;
proto_tree_add_text(tree, tvb, offset, 1, "SPECS_MISMATCH_HASH");
offset += 1;
proto_tree_add_text(tree, tvb, offset, 1, "SPECS_MISMATCH_CERT");
offset += 1;
proto_tree_add_text(tree, tvb, offset, 1, "SPECS_MISMATCH_EXCH");
offset += 1;
proto_tree_add_text(tree, tvb, offset, 1, "SPECS_MISMATCH_CLIENT_CERT");
offset += 1;
proto_tree_add_text(tree, tvb, offset, 1, "SPECS_MISMATCH_CLIENT_SIG");
}
else if (INFO_LEN) {
proto_tree_add_text(tree, tvb, offset, INFO_LEN, "Error Information data (%d bytes)", INFO_LEN);
}
}
static void
dissect_ssl2_hnd_client_master_key(tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
guint16 clear_key_length;
guint16 encrypted_key_length;
guint16 key_arg_length;
if (!tree)
{
return;
}
proto_tree_add_item(tree, hf_ssl2_handshake_cipher_spec,
tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
clear_key_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_ssl2_handshake_clear_key_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
encrypted_key_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_ssl2_handshake_enc_key_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
key_arg_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_ssl2_handshake_key_arg_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (clear_key_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, clear_key_length);
proto_tree_add_item(tree, hf_ssl2_handshake_clear_key,
tvb, offset, clear_key_length, ENC_NA);
offset += clear_key_length;
}
if (encrypted_key_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, encrypted_key_length);
proto_tree_add_item(tree, hf_ssl2_handshake_enc_key,
tvb, offset, encrypted_key_length, ENC_NA);
offset += encrypted_key_length;
}
if (key_arg_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, key_arg_length);
proto_tree_add_item(tree, hf_ssl2_handshake_key_arg,
tvb, offset, key_arg_length, ENC_NA);
}
}
static void
dissect_ssl2_hnd_server_hello(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, packet_info *pinfo)
{
guint16 certificate_length;
guint16 cipher_spec_length;
guint16 connection_id_length;
guint16 version;
proto_item *ti;
proto_tree *subtree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (!tree)
{
return;
}
version = tvb_get_ntohs(tvb, offset + 2);
if (!ssl_is_valid_ssl_version(version))
{
return;
}
proto_tree_add_item(tree, hf_ssl2_handshake_session_id_hit,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_ssl2_handshake_cert_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, dissect_ssl3_hf.hf.hs_server_version,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
certificate_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, dissect_ssl3_hf.hf.hs_certificate_len,
tvb, offset, 2, certificate_length);
offset += 2;
cipher_spec_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_ssl2_handshake_cipher_spec_len,
tvb, offset, 2, cipher_spec_length);
offset += 2;
connection_id_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_ssl2_handshake_connection_id_len,
tvb, offset, 2, connection_id_length);
offset += 2;
if (certificate_length > 0)
{
(void)dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, dissect_ssl3_hf.hf.hs_certificate);
offset += certificate_length;
}
if (cipher_spec_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, cipher_spec_length);
ti = proto_tree_add_none_format(tree,
dissect_ssl3_hf.hf.hs_cipher_suites,
tvb, offset, cipher_spec_length,
"Cipher Specs (%u spec%s)",
cipher_spec_length/3,
plurality(cipher_spec_length/3, "", "s"));
subtree = proto_item_add_subtree(ti, dissect_ssl3_hf.ett.cipher_suites);
if (!subtree)
{
subtree = tree;
}
while (cipher_spec_length > 0)
{
proto_tree_add_item(subtree, hf_ssl2_handshake_cipher_spec,
tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
cipher_spec_length -= 3;
}
}
if (connection_id_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, connection_id_length);
proto_tree_add_item(tree, hf_ssl2_handshake_connection_id,
tvb, offset, connection_id_length, ENC_NA);
}
}
void ssl_set_master_secret(guint32 frame_num, address *addr_srv, address *addr_cli,
port_type ptype, guint32 port_srv, guint32 port_cli,
guint32 version, gint cipher, const guchar *_master_secret,
const guchar *_client_random, const guchar *_server_random,
guint32 client_seq, guint32 server_seq)
{
conversation_t *conversation;
void *conv_data;
SslDecryptSession *ssl;
guint iv_len;
ssl_debug_printf("\nssl_set_master_secret enter frame #%u\n", frame_num);
conversation = find_conversation(frame_num, addr_srv, addr_cli, ptype, port_srv, port_cli, 0);
if (!conversation) {
conversation = conversation_new(frame_num, addr_srv, addr_cli, ptype, port_srv, port_cli, 0);
ssl_debug_printf(" new conversation = %p created\n", (void *)conversation);
}
conv_data = conversation_get_proto_data(conversation, proto_ssl);
if (conv_data) {
ssl = (SslDecryptSession *)conv_data;
} else {
ssl = (SslDecryptSession *)wmem_alloc0(wmem_file_scope(), sizeof(SslDecryptSession));
ssl_session_init(ssl);
ssl->session.version = SSL_VER_UNKNOWN;
conversation_add_proto_data(conversation, proto_ssl, ssl);
}
ssl_debug_printf(" conversation = %p, ssl_session = %p\n", (void *)conversation, (void *)ssl);
ssl_set_server(ssl, addr_srv, ptype, port_srv);
if ((ssl->session.version==SSL_VER_UNKNOWN) && (version!=SSL_VER_UNKNOWN)) {
switch (version) {
case SSL_VER_SSLv3:
ssl->session.version = SSL_VER_SSLv3;
ssl->version_netorder = SSLV3_VERSION;
ssl->state |= SSL_VERSION;
ssl_debug_printf("ssl_set_master_secret set version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
break;
case SSL_VER_TLS:
ssl->session.version = SSL_VER_TLS;
ssl->version_netorder = TLSV1_VERSION;
ssl->state |= SSL_VERSION;
ssl_debug_printf("ssl_set_master_secret set version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
break;
case SSL_VER_TLSv1DOT1:
ssl->session.version = SSL_VER_TLSv1DOT1;
ssl->version_netorder = TLSV1DOT1_VERSION;
ssl->state |= SSL_VERSION;
ssl_debug_printf("ssl_set_master_secret set version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
break;
case SSL_VER_TLSv1DOT2:
ssl->session.version = SSL_VER_TLSv1DOT2;
ssl->version_netorder = TLSV1DOT2_VERSION;
ssl->state |= SSL_VERSION;
ssl_debug_printf("ssl_set_master_secret set version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
break;
}
}
if (cipher > 0) {
ssl->session.cipher = cipher;
if (ssl_find_cipher(ssl->session.cipher,&ssl->cipher_suite) < 0) {
ssl_debug_printf("ssl_set_master_secret can't find cipher suite 0x%X\n", ssl->session.cipher);
} else {
ssl->state |= SSL_CIPHER;
ssl_debug_printf("ssl_set_master_secret set CIPHER 0x%04X -> state 0x%02X\n", ssl->session.cipher, ssl->state);
}
}
if (_client_random) {
ssl_data_set(&ssl->client_random, _client_random, 32);
ssl->state |= SSL_CLIENT_RANDOM;
ssl_debug_printf("ssl_set_master_secret set CLIENT RANDOM -> state 0x%02X\n", ssl->state);
}
if (_server_random) {
ssl_data_set(&ssl->server_random, _server_random, 32);
ssl->state |= SSL_SERVER_RANDOM;
ssl_debug_printf("ssl_set_master_secret set SERVER RANDOM -> state 0x%02X\n", ssl->state);
}
if (_master_secret) {
ssl_data_set(&ssl->master_secret, _master_secret, 48);
ssl->state |= SSL_MASTER_SECRET;
ssl_debug_printf("ssl_set_master_secret set MASTER SECRET -> state 0x%02X\n", ssl->state);
}
ssl_debug_printf("ssl_set_master_secret trying to generate keys\n");
if (ssl_generate_keyring_material(ssl)<0) {
ssl_debug_printf("ssl_set_master_secret can't generate keyring material\n");
return;
}
ssl_change_cipher(ssl, TRUE);
ssl_change_cipher(ssl, FALSE);
if (ssl->client && (client_seq != (guint32)-1)) {
ssl->client->seq = client_seq;
ssl_debug_printf("ssl_set_master_secret client->seq updated to %u\n", ssl->client->seq);
}
if (ssl->server && (server_seq != (guint32)-1)) {
ssl->server->seq = server_seq;
ssl_debug_printf("ssl_set_master_secret server->seq updated to %u\n", ssl->server->seq);
}
iv_len = (ssl->cipher_suite.block>1) ? ssl->cipher_suite.block : 8;
if (ssl->client && ((ssl->client->seq > 0) || (ssl->client_data_for_iv.data_len > iv_len))) {
ssl_cipher_setiv(&ssl->client->evp, ssl->client_data_for_iv.data + ssl->client_data_for_iv.data_len - iv_len, iv_len);
ssl_print_data("ssl_set_master_secret client IV updated",ssl->client_data_for_iv.data + ssl->client_data_for_iv.data_len - iv_len, iv_len);
}
if (ssl->server && ((ssl->server->seq > 0) || (ssl->server_data_for_iv.data_len > iv_len))) {
ssl_cipher_setiv(&ssl->server->evp, ssl->server_data_for_iv.data + ssl->server_data_for_iv.data_len - iv_len, iv_len);
ssl_print_data("ssl_set_master_secret server IV updated",ssl->server_data_for_iv.data + ssl->server_data_for_iv.data_len - iv_len, iv_len);
}
}
static gint
ssl_is_valid_ssl_version(const guint16 version)
{
const gchar *version_str;
version_str = try_val_to_str(version, ssl_versions);
return version_str != NULL;
}
static gint
ssl_is_authoritative_version_message(const guint8 content_type,
const guint8 next_byte)
{
if (content_type == SSL_ID_HANDSHAKE
&& ssl_is_valid_handshake_type(next_byte, FALSE))
{
return (next_byte != SSL_HND_CLIENT_HELLO);
}
else if (ssl_is_valid_content_type(content_type)
&& content_type != SSL_ID_HANDSHAKE)
{
return 1;
}
return 0;
}
static gint
ssl_is_v2_client_hello(tvbuff_t *tvb, const guint32 offset)
{
guint8 byte;
byte = tvb_get_guint8(tvb, offset);
if (byte != 0x80)
{
return 0;
}
byte = tvb_get_guint8(tvb, offset+2);
if (byte != 0x01)
{
return 0;
}
return 1;
}
static gint
ssl_looks_like_sslv2(tvbuff_t *tvb, const guint32 offset)
{
guint8 byte;
byte = tvb_get_guint8(tvb, offset);
if (byte < 0x80)
{
return 0;
}
byte = tvb_get_guint8(tvb, offset + 2);
switch (byte) {
case SSL2_HND_ERROR:
case SSL2_HND_CLIENT_HELLO:
case SSL2_HND_CLIENT_MASTER_KEY:
case SSL2_HND_SERVER_HELLO:
case PCT_MSG_CLIENT_MASTER_KEY:
case PCT_MSG_ERROR:
return 1;
}
return 0;
}
static gint
ssl_looks_like_sslv3(tvbuff_t *tvb, const guint32 offset)
{
guint8 byte;
guint16 version;
byte = tvb_get_guint8(tvb, offset);
if (!ssl_is_valid_content_type(byte))
{
return 0;
}
version = tvb_get_ntohs(tvb, offset + 1);
switch (version) {
case SSLV3_VERSION:
case TLSV1_VERSION:
case TLSV1DOT1_VERSION:
case TLSV1DOT2_VERSION:
return 1;
}
return 0;
}
static gint
ssl_looks_like_valid_v2_handshake(tvbuff_t *tvb, const guint32 offset,
const guint32 record_length)
{
guint8 msg_type;
guint16 version;
guint32 sum;
gint ret = 0;
msg_type = tvb_get_guint8(tvb, offset);
switch (msg_type) {
case SSL2_HND_CLIENT_HELLO:
version = tvb_get_ntohs(tvb, offset+1);
ret = ssl_is_valid_ssl_version(version);
break;
case SSL2_HND_SERVER_HELLO:
version = tvb_get_ntohs(tvb, offset+3);
ret = ssl_is_valid_ssl_version(version);
break;
case SSL2_HND_CLIENT_MASTER_KEY:
sum = tvb_get_ntohs(tvb, offset + 4);
sum += tvb_get_ntohs(tvb, offset + 6);
sum += tvb_get_ntohs(tvb, offset + 8);
if (sum <= record_length) {
ret = 1;
}
break;
default:
break;
}
return ret;
}
static gint
ssl_looks_like_valid_pct_handshake(tvbuff_t *tvb, const guint32 offset,
const guint32 record_length)
{
guint8 msg_type;
guint16 version;
guint32 sum;
gint ret = 0;
msg_type = tvb_get_guint8(tvb, offset);
switch (msg_type) {
case PCT_MSG_CLIENT_HELLO:
version = tvb_get_ntohs(tvb, offset+1);
ret = (version == PCT_VERSION_1);
break;
case PCT_MSG_SERVER_HELLO:
version = tvb_get_ntohs(tvb, offset+2);
ret = (version == PCT_VERSION_1);
break;
case PCT_MSG_CLIENT_MASTER_KEY:
sum = tvb_get_ntohs(tvb, offset + 6);
sum += tvb_get_ntohs(tvb, offset + 8);
sum += tvb_get_ntohs(tvb, offset + 10);
sum += tvb_get_ntohs(tvb, offset + 12);
sum += tvb_get_ntohs(tvb, offset + 14);
sum += tvb_get_ntohs(tvb, offset + 16);
if (sum <= record_length) {
ret = 1;
}
break;
case PCT_MSG_SERVER_VERIFY:
sum = tvb_get_ntohs(tvb, offset + 34);
if ((sum + 36) == record_length) {
ret = 1;
}
break;
default:
break;
}
return ret;
}
static void
ssldecrypt_free_cb(void *r)
{
ssldecrypt_assoc_t *h = (ssldecrypt_assoc_t *)r;
g_free(h->ipaddr);
g_free(h->port);
g_free(h->protocol);
g_free(h->keyfile);
g_free(h->password);
}
static void*
ssldecrypt_copy_cb(void *dest, const void *orig, size_t len _U_)
{
const ssldecrypt_assoc_t *o = (const ssldecrypt_assoc_t *)orig;
ssldecrypt_assoc_t *d = (ssldecrypt_assoc_t *)dest;
d->ipaddr = g_strdup(o->ipaddr);
d->port = g_strdup(o->port);
d->protocol = g_strdup(o->protocol);
d->keyfile = g_strdup(o->keyfile);
d->password = g_strdup(o->password);
return d;
}
void
proto_register_ssl(void)
{
static hf_register_info hf[] = {
{ &hf_ssl_record,
{ "Record Layer", "ssl.record",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_record_content_type,
{ "Content Type", "ssl.record.content_type",
FT_UINT8, BASE_DEC, VALS(ssl_31_content_type), 0x0,
NULL, HFILL}
},
{ &hf_ssl2_msg_type,
{ "Handshake Message Type", "ssl.handshake.type",
FT_UINT8, BASE_DEC, VALS(ssl_20_msg_types), 0x0,
"SSLv2 handshake message type", HFILL}
},
{ &hf_pct_msg_type,
{ "Handshake Message Type", "ssl.pct_handshake.type",
FT_UINT8, BASE_DEC, VALS(pct_msg_types), 0x0,
"PCT handshake message type", HFILL}
},
{ &hf_ssl_record_version,
{ "Version", "ssl.record.version",
FT_UINT16, BASE_HEX, VALS(ssl_versions), 0x0,
"Record layer version", HFILL }
},
{ &hf_ssl_record_length,
{ "Length", "ssl.record.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of SSL record data", HFILL }
},
{ &hf_ssl_record_appdata,
{ "Encrypted Application Data", "ssl.app_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Payload is encrypted application data", HFILL }
},
{ &hf_ssl2_record,
{ "SSLv2/PCT Record Header", "ssl.record",
FT_NONE, BASE_NONE, NULL, 0x0,
"SSLv2/PCT record data", HFILL }
},
{ &hf_ssl2_record_is_escape,
{ "Is Escape", "ssl.record.is_escape",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Indicates a security escape", HFILL}
},
{ &hf_ssl2_record_padding_length,
{ "Padding Length", "ssl.record.padding_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of padding at end of record", HFILL }
},
{ &hf_ssl_change_cipher_spec,
{ "Change Cipher Spec Message", "ssl.change_cipher_spec",
FT_NONE, BASE_NONE, NULL, 0x0,
"Signals a change in cipher specifications", HFILL }
},
{ &hf_ssl_alert_message,
{ "Alert Message", "ssl.alert_message",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_alert_message_level,
{ "Level", "ssl.alert_message.level",
FT_UINT8, BASE_DEC, VALS(ssl_31_alert_level), 0x0,
"Alert message level", HFILL }
},
{ &hf_ssl_alert_message_description,
{ "Description", "ssl.alert_message.desc",
FT_UINT8, BASE_DEC, VALS(ssl_31_alert_description), 0x0,
"Alert message description", HFILL }
},
{ &hf_ssl_handshake_protocol,
{ "Handshake Protocol", "ssl.handshake",
FT_NONE, BASE_NONE, NULL, 0x0,
"Handshake protocol message", HFILL}
},
{ &hf_ssl_handshake_type,
{ "Handshake Type", "ssl.handshake.type",
FT_UINT8, BASE_DEC, VALS(ssl_31_handshake_type), 0x0,
"Type of handshake message", HFILL}
},
{ &hf_ssl_handshake_length,
{ "Length", "ssl.handshake.length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length of handshake message", HFILL }
},
{ &hf_ssl2_handshake_cipher_spec,
{ "Cipher Spec", "ssl.handshake.cipherspec",
FT_UINT24, BASE_HEX|BASE_EXT_STRING, &ssl_20_cipher_suites_ext, 0x0,
"Cipher specification", HFILL }
},
{ &hf_ssl_handshake_client_cert_vrfy_sig_len,
{ "Signature length", "ssl.handshake.client_cert_vrfy.sig_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of CertificateVerify's signature", HFILL }
},
{ &hf_ssl_handshake_client_cert_vrfy_sig,
{ "Signature", "ssl.handshake.client_cert_vrfy.sig",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CertificateVerify's signature", HFILL }
},
{ &hf_ssl_handshake_cert_status,
{ "Certificate Status", "ssl.handshake.cert_status",
FT_NONE, BASE_NONE, NULL, 0x0,
"Certificate Status Data", HFILL }
},
{ &hf_ssl_handshake_cert_status_type,
{ "Certificate Status Type", "ssl.handshake.cert_status_type",
FT_UINT8, BASE_DEC, VALS(tls_cert_status_type), 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_cert_status_len,
{ "Certificate Status Length", "ssl.handshake.cert_status_len",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length of certificate status", HFILL }
},
{ &hf_ssl_handshake_npn_selected_protocol_len,
{ "Selected Protocol Length", "ssl.handshake.npn_selected_protocol_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_npn_selected_protocol,
{ "Selected Protocol", "ssl.handshake.npn_selected_protocol",
FT_STRING, BASE_NONE, NULL, 0x0,
"Protocol to be used for connection", HFILL }
},
{ &hf_ssl_handshake_npn_padding_len,
{ "Padding Length", "ssl.handshake.npn_padding_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_npn_padding,
{ "Padding", "ssl.handshake.npn_padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &ssl_hfs.hs_md5_hash,
{ "MD5 Hash", "ssl.handshake.md5_hash",
FT_NONE, BASE_NONE, NULL, 0x0,
"Hash of messages, master_secret, etc.", HFILL }
},
{ &ssl_hfs.hs_sha_hash,
{ "SHA-1 Hash", "ssl.handshake.sha_hash",
FT_NONE, BASE_NONE, NULL, 0x0,
"Hash of messages, master_secret, etc.", HFILL }
},
{ &hf_ssl_heartbeat_message,
{ "Heartbeat Message", "ssl.heartbeat_message",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_heartbeat_message_type,
{ "Type", "ssl.heartbeat_message.type",
FT_UINT8, BASE_DEC, VALS(tls_heartbeat_type), 0x0,
"Heartbeat message type", HFILL }
},
{ &hf_ssl_heartbeat_message_payload_length,
{ "Payload Length", "ssl.heartbeat_message.payload_length",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_ssl_heartbeat_message_payload,
{ "Payload Length", "ssl.heartbeat_message.payload",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_ssl_heartbeat_message_padding,
{ "Payload Length", "ssl.heartbeat_message.padding",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_ssl2_handshake_challenge,
{ "Challenge", "ssl.handshake.challenge",
FT_NONE, BASE_NONE, NULL, 0x0,
"Challenge data used to authenticate server", HFILL }
},
{ &hf_ssl2_handshake_cipher_spec_len,
{ "Cipher Spec Length", "ssl.handshake.cipher_spec_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of cipher specs field", HFILL }
},
{ &hf_ssl2_handshake_session_id_len,
{ "Session ID Length", "ssl.handshake.session_id_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of session ID field", HFILL }
},
{ &hf_ssl2_handshake_challenge_len,
{ "Challenge Length", "ssl.handshake.challenge_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of challenge field", HFILL }
},
{ &hf_ssl2_handshake_clear_key_len,
{ "Clear Key Data Length", "ssl.handshake.clear_key_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of clear key data", HFILL }
},
{ &hf_ssl2_handshake_enc_key_len,
{ "Encrypted Key Data Length", "ssl.handshake.encrypted_key_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of encrypted key data", HFILL }
},
{ &hf_ssl2_handshake_key_arg_len,
{ "Key Argument Length", "ssl.handshake.key_arg_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of key argument", HFILL }
},
{ &hf_ssl2_handshake_clear_key,
{ "Clear Key Data", "ssl.handshake.clear_key_data",
FT_NONE, BASE_NONE, NULL, 0x0,
"Clear portion of MASTER-KEY", HFILL }
},
{ &hf_ssl2_handshake_enc_key,
{ "Encrypted Key", "ssl.handshake.encrypted_key",
FT_NONE, BASE_NONE, NULL, 0x0,
"Secret portion of MASTER-KEY encrypted to server", HFILL }
},
{ &hf_ssl2_handshake_key_arg,
{ "Key Argument", "ssl.handshake.key_arg",
FT_NONE, BASE_NONE, NULL, 0x0,
"Key Argument (e.g., Initialization Vector)", HFILL }
},
{ &hf_ssl2_handshake_session_id_hit,
{ "Session ID Hit", "ssl.handshake.session_id_hit",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Did the server find the client's Session ID?", HFILL }
},
{ &hf_ssl2_handshake_cert_type,
{ "Certificate Type", "ssl.handshake.cert_type",
FT_UINT8, BASE_DEC, VALS(ssl_20_certificate_type), 0x0,
NULL, HFILL }
},
{ &hf_ssl2_handshake_connection_id_len,
{ "Connection ID Length", "ssl.handshake.connection_id_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of connection ID", HFILL }
},
{ &hf_ssl2_handshake_connection_id,
{ "Connection ID", "ssl.handshake.connection_id",
FT_NONE, BASE_NONE, NULL, 0x0,
"Server's challenge to client", HFILL }
},
{ &hf_pct_handshake_cipher_spec,
{ "Cipher Spec", "pct.handshake.cipherspec",
FT_NONE, BASE_NONE, NULL, 0x0,
"PCT Cipher specification", HFILL }
},
{ &hf_pct_handshake_cipher,
{ "Cipher", "pct.handshake.cipher",
FT_UINT16, BASE_HEX, VALS(pct_cipher_type), 0x0,
"PCT Ciper", HFILL }
},
{ &hf_pct_handshake_hash_spec,
{ "Hash Spec", "pct.handshake.hashspec",
FT_NONE, BASE_NONE, NULL, 0x0,
"PCT Hash specification", HFILL }
},
{ &hf_pct_handshake_hash,
{ "Hash", "pct.handshake.hash",
FT_UINT16, BASE_HEX, VALS(pct_hash_type), 0x0,
"PCT Hash", HFILL }
},
{ &hf_pct_handshake_cert_spec,
{ "Cert Spec", "pct.handshake.certspec",
FT_NONE, BASE_NONE, NULL, 0x0,
"PCT Certificate specification", HFILL }
},
{ &hf_pct_handshake_cert,
{ "Cert", "pct.handshake.cert",
FT_UINT16, BASE_HEX, VALS(pct_cert_type), 0x0,
"PCT Certificate", HFILL }
},
{ &hf_pct_handshake_exch_spec,
{ "Exchange Spec", "pct.handshake.exchspec",
FT_NONE, BASE_NONE, NULL, 0x0,
"PCT Exchange specification", HFILL }
},
{ &hf_pct_handshake_exch,
{ "Exchange", "pct.handshake.exch",
FT_UINT16, BASE_HEX, VALS(pct_exch_type), 0x0,
"PCT Exchange", HFILL }
},
{ &hf_pct_handshake_sig,
{ "Sig Spec", "pct.handshake.sig",
FT_UINT16, BASE_HEX, VALS(pct_sig_type), 0x0,
"PCT Signature", HFILL }
},
{ &hf_pct_msg_error_type,
{ "PCT Error Code", "pct.msg_error_code",
FT_UINT16, BASE_HEX, VALS(pct_error_code), 0x0,
NULL, HFILL }
},
{ &hf_pct_handshake_server_cert,
{ "Server Cert", "pct.handshake.server_cert",
FT_NONE, BASE_NONE, NULL , 0x0,
"PCT Server Certificate", HFILL }
},
{ &hf_ssl_segment_overlap,
{ "Segment overlap", "ssl.segment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment overlaps with other segments", HFILL }},
{ &hf_ssl_segment_overlap_conflict,
{ "Conflicting data in segment overlap", "ssl.segment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping segments contained conflicting data", HFILL }},
{ &hf_ssl_segment_multiple_tails,
{ "Multiple tail segments found", "ssl.segment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when reassembling the pdu", HFILL }},
{ &hf_ssl_segment_too_long_fragment,
{ "Segment too long", "ssl.segment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment contained data past end of the pdu", HFILL }},
{ &hf_ssl_segment_error,
{ "Reassembling error", "ssl.segment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Reassembling error due to illegal segments", HFILL }},
{ &hf_ssl_segment_count,
{ "Segment count", "ssl.segment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ssl_segment,
{ "SSL segment", "ssl.segment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ssl_segments,
{ "Reassembled SSL segments", "ssl.segments",
FT_NONE, BASE_NONE, NULL, 0x0,
"SSL Segments", HFILL }},
{ &hf_ssl_reassembled_in,
{ "Reassembled PDU in frame", "ssl.reassembled_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The PDU that doesn't end in this segment is reassembled in this frame", HFILL }},
{ &hf_ssl_reassembled_length,
{ "Reassembled PDU length", "ssl.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_ssl_reassembled_data,
{ "Reassembled PDU data", "ssl.reassembled.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
"The payload of multiple reassembled SSL segments", HFILL }},
{ &hf_ssl_segment_data,
{ "SSL segment data", "ssl.segment.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
"The payload of a single SSL segment", HFILL }
},
SSL_COMMON_HF_LIST(dissect_ssl3_hf, "ssl")
};
static gint *ett[] = {
&ett_ssl,
&ett_ssl_record,
&ett_ssl_alert,
&ett_ssl_handshake,
&ett_ssl_heartbeat,
&ett_ssl_certs,
&ett_ssl_cli_sig,
&ett_ssl_cert_status,
&ett_ssl_ocsp_resp,
&ett_pct_cipher_suites,
&ett_pct_hash_suites,
&ett_pct_cert_suites,
&ett_pct_exch_suites,
&ett_ssl_segments,
&ett_ssl_segment,
SSL_COMMON_ETT_LIST(dissect_ssl3_hf)
};
static ei_register_info ei[] = {
{ &ei_ssl2_handshake_session_id_len_error, { "ssl.handshake.session_id_length.error", PI_MALFORMED, PI_ERROR, "Session ID length error", EXPFILL }},
{ &ei_ssl3_heartbeat_payload_length, {"ssl.heartbeat_message.payload_length.invalid", PI_MALFORMED, PI_ERROR, "Invalid heartbeat payload length", EXPFILL }},
SSL_COMMON_EI_LIST(dissect_ssl3_hf, "ssl")
};
expert_module_t* expert_ssl;
proto_ssl = proto_register_protocol("Secure Sockets Layer",
"SSL", "ssl");
proto_register_field_array(proto_ssl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ssl = expert_register_protocol(proto_ssl);
expert_register_field_array(expert_ssl, ei, array_length(ei));
{
module_t *ssl_module = prefs_register_protocol(proto_ssl, proto_reg_handoff_ssl);
#ifdef HAVE_LIBGNUTLS
static uat_field_t sslkeylist_uats_flds[] = {
UAT_FLD_CSTRING_OTHER(sslkeylist_uats, ipaddr, "IP address", ssldecrypt_uat_fld_ip_chk_cb, "IPv4 or IPv6 address"),
UAT_FLD_CSTRING_OTHER(sslkeylist_uats, port, "Port", ssldecrypt_uat_fld_port_chk_cb, "Port Number"),
UAT_FLD_CSTRING_OTHER(sslkeylist_uats, protocol, "Protocol", ssldecrypt_uat_fld_protocol_chk_cb, "Protocol"),
UAT_FLD_FILENAME_OTHER(sslkeylist_uats, keyfile, "Key File", ssldecrypt_uat_fld_fileopen_chk_cb, "Private keyfile."),
UAT_FLD_CSTRING_OTHER(sslkeylist_uats, password,"Password", ssldecrypt_uat_fld_password_chk_cb, "Password (for PCKS#12 keyfile)"),
UAT_END_FIELDS
};
ssldecrypt_uat = uat_new("SSL Decrypt",
sizeof(ssldecrypt_assoc_t),
"ssl_keys",
TRUE,
&sslkeylist_uats,
&nssldecrypt,
UAT_AFFECTS_DISSECTION,
NULL,
ssldecrypt_copy_cb,
NULL,
ssldecrypt_free_cb,
ssl_parse_uat,
sslkeylist_uats_flds);
prefs_register_uat_preference(ssl_module, "key_table",
"RSA keys list",
"A table of RSA keys for SSL decryption",
ssldecrypt_uat);
prefs_register_filename_preference(ssl_module, "debug_file", "SSL debug file",
"Redirect SSL debug to file name; leave empty to disable debugging, "
"or use \"" SSL_DEBUG_USE_STDERR "\" to redirect output to stderr\n",
&ssl_debug_file_name);
prefs_register_string_preference(ssl_module, "keys_list", "RSA keys list (deprecated)",
"Semicolon-separated list of private RSA keys used for SSL decryption. "
"Used by versions of Wireshark prior to 1.6",
&ssl_keys_list);
#endif
prefs_register_bool_preference(ssl_module,
"desegment_ssl_records",
"Reassemble SSL records spanning multiple TCP segments",
"Whether the SSL dissector should reassemble SSL records spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&ssl_desegment);
prefs_register_bool_preference(ssl_module,
"desegment_ssl_application_data",
"Reassemble SSL Application Data spanning multiple SSL records",
"Whether the SSL dissector should reassemble SSL Application Data spanning multiple SSL records. ",
&ssl_desegment_app_data);
prefs_register_bool_preference(ssl_module,
"ignore_ssl_mac_failed",
"Message Authentication Code (MAC), ignore \"mac failed\"",
"For troubleshooting ignore the mac check result and decrypt also if the Message Authentication Code (MAC) fails.",
&ssl_ignore_mac_failed);
#ifdef HAVE_LIBGNUTLS
ssl_common_register_options(ssl_module, &ssl_options);
#endif
}
register_heur_dissector_list("ssl", &ssl_heur_subdissector_list);
new_register_dissector("ssl", dissect_ssl, proto_ssl);
ssl_handle = find_dissector("ssl");
ssl_associations = g_tree_new(ssl_association_cmp);
register_init_routine(ssl_init);
ssl_lib_init();
ssl_tap = register_tap("ssl");
ssl_debug_printf("proto_register_ssl: registered tap %s:%d\n",
"ssl", ssl_tap);
}
void
proto_reg_handoff_ssl(void)
{
ssl_parse_uat();
ssl_parse_old_keys();
exported_pdu_tap = find_tap_id(EXPORT_PDU_TAP_NAME_LAYER_7);
}
void
ssl_dissector_add(guint port, const gchar *protocol, gboolean tcp)
{
SslAssociation *assoc;
assoc = ssl_association_find(ssl_associations, port, tcp);
if (assoc) {
ssl_association_remove(ssl_associations, assoc);
}
ssl_association_add(ssl_associations, ssl_handle, port, protocol, tcp, FALSE);
}
void
ssl_dissector_delete(guint port, const gchar *protocol, gboolean tcp)
{
SslAssociation *assoc;
assoc = ssl_association_find(ssl_associations, port, tcp);
if (assoc && (assoc->handle == find_dissector(protocol))) {
ssl_association_remove(ssl_associations, assoc);
}
}
