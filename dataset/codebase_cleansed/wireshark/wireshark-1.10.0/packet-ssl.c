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
"%s" SSL_SEGMENT_DATA_TEXT " (%u %s)",
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
ssl_common_init(&ssl_session_hash, &ssl_decrypted_data, &ssl_compressed_data);
ssl_fragment_init();
ssl_debug_flush();
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
ep_stack_t tmp_stack;
SslAssociation *tmp_assoc;
guint i;
ssl_set_debug(ssl_debug_file_name);
if (ssl_key_hash)
{
g_hash_table_foreach(ssl_key_hash, ssl_private_key_free, NULL);
g_hash_table_destroy(ssl_key_hash);
}
tmp_stack = ep_stack_new();
g_tree_foreach(ssl_associations, ssl_assoc_from_key_list, tmp_stack);
while ((tmp_assoc = (SslAssociation *)ep_stack_pop(tmp_stack)) != NULL) {
ssl_association_remove(ssl_associations, tmp_assoc);
}
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
static void
dissect_ssl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
conversation_t *conversation;
void *conv_data;
proto_item *ti;
proto_tree *ssl_tree;
guint32 offset;
gboolean first_record_in_frame;
gboolean need_desegmentation;
SslDecryptSession *ssl_session;
guint *conv_version;
guint conv_cipher;
ti = NULL;
ssl_tree = NULL;
offset = 0;
first_record_in_frame = TRUE;
ssl_session = NULL;
ssl_debug_printf("\ndissect_ssl enter frame #%u (%s)\n", pinfo->fd->num, (pinfo->fd->flags.visited)?"already visited":"first time");
conversation = find_or_create_conversation(pinfo);
conv_data = conversation_get_proto_data(conversation, proto_ssl);
if (conv_data != NULL)
ssl_session = (SslDecryptSession *)conv_data;
else {
ssl_session = (SslDecryptSession *)se_alloc0(sizeof(SslDecryptSession));
ssl_session_init(ssl_session);
ssl_session->version = SSL_VER_UNKNOWN;
conversation_add_proto_data(conversation, proto_ssl, ssl_session);
}
conv_version =& ssl_session->version;
conv_cipher = ssl_session->cipher;
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
switch (*conv_version) {
case SSL_VER_SSLv2:
case SSL_VER_PCT:
offset = dissect_ssl2_record(tvb, pinfo, ssl_tree,
offset, conv_version,
&need_desegmentation,
ssl_session,
first_record_in_frame);
break;
case SSL_VER_SSLv3:
case SSL_VER_TLS:
if (ssl_is_v2_client_hello(tvb, offset))
{
offset = dissect_ssl2_record(tvb, pinfo, ssl_tree,
offset, conv_version,
&need_desegmentation,
ssl_session,
first_record_in_frame);
}
else
{
offset = dissect_ssl3_record(tvb, pinfo, ssl_tree,
offset, conv_version,
conv_cipher,
&need_desegmentation,
ssl_session,
first_record_in_frame);
}
break;
default:
if (ssl_looks_like_sslv2(tvb, offset))
{
offset = dissect_ssl2_record(tvb, pinfo, ssl_tree,
offset, conv_version,
&need_desegmentation,
ssl_session,
first_record_in_frame);
}
else if (ssl_looks_like_sslv3(tvb, offset))
{
offset = dissect_ssl3_record(tvb, pinfo, ssl_tree,
offset, conv_version,
conv_cipher,
&need_desegmentation,
ssl_session,
first_record_in_frame);
}
else
{
if (!first_record_in_frame) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
offset = tvb_length(tvb);
col_append_str(pinfo->cinfo, COL_INFO,
"Continuation Data");
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"));
}
break;
}
if (need_desegmentation) {
ssl_debug_printf(" need_desegmentation: offset = %d, reported_length_remaining = %d\n",
offset, tvb_reported_length_remaining(tvb, offset));
tap_queue_packet(ssl_tap, pinfo, GINT_TO_POINTER(proto_ssl));
return;
}
first_record_in_frame = FALSE;
}
col_set_fence(pinfo->cinfo, COL_INFO);
ssl_debug_flush();
tap_queue_packet(ssl_tap, pinfo, GINT_TO_POINTER(proto_ssl));
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
ssl_data_set(data_for_iv, (guchar*)tvb_get_ptr(tvb, offset + record_length - data_for_iv_len, data_for_iv_len), data_for_iv_len);
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
ssl_data_set(data_for_iv, (guchar*)tvb_get_ptr(tvb, offset + record_length - data_for_iv_len, data_for_iv_len), data_for_iv_len);
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
fragment_data *ipfd_head;
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
if ((msp = (struct tcp_multisegment_pdu *)se_tree_lookup32(flow->multisegment_pdus, seq))) {
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
msp = (struct tcp_multisegment_pdu *)se_tree_lookup32_le(flow->multisegment_pdus, seq-1);
if (msp && msp->seq <= seq && msp->nxtpdu > seq) {
int len;
if (!PINFO_FD_VISITED(pinfo)) {
msp->last_frame = pinfo->fd->num;
msp->last_frame_time = pinfo->fd->abs_ts;
}
if (msp->flags & MSP_FLAGS_REASSEMBLE_ENTIRE_SEGMENT) {
len = MAX(0, tvb_length_remaining(tvb, offset));
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
next_tvb = tvb_new_child_real_data(tvb, ipfd_head->data,
ipfd_head->datalen,
ipfd_head->datalen);
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
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (association && association->handle) {
ssl_debug_printf("dissect_ssl3_record found association %p\n", (void *)association);
if (dissector_try_heuristic(ssl_heur_subdissector_list, next_tvb,
pinfo, proto_tree_get_root(tree), NULL)) {
} else {
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
guint *conv_version, guint conv_cipher,
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
available_bytes = tvb_length_remaining(tvb, offset);
if ((*conv_version==SSL_VER_TLS || *conv_version==SSL_VER_TLSv1DOT1 || *conv_version==SSL_VER_TLSv1DOT2) &&
(available_bytes >=1 ) && !ssl_is_valid_content_type(tvb_get_guint8(tvb, offset))) {
proto_tree_add_text(tree, tvb, offset, available_bytes, "Ignored Unknown Record");
if (!first_record_in_frame) {
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
col_append_str(pinfo->cinfo, COL_INFO, "Ignored Unknown Record");
col_set_str(pinfo->cinfo, COL_PROTOCOL, val_to_str_const(*conv_version, ssl_version_short_names, "SSL"));
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
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"));
return offset + 5 + record_length;
}
if (tree)
{
tvb_ensure_bytes_exist(tvb, offset, 5 + record_length);
ti = proto_tree_add_item(tree, hf_ssl_record, tvb,
offset, 5 + record_length, ENC_NA);
ssl_record_tree = proto_item_add_subtree(ti, ett_ssl_record);
proto_tree_add_item(ssl_record_tree, hf_ssl_record_content_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;;
proto_tree_add_item(ssl_record_tree, hf_ssl_record_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_uint(ssl_record_tree, hf_ssl_record_length, tvb,
offset, 2, record_length);
offset += 2;
}
else
{
offset += 5;
}
next_byte = tvb_get_guint8(tvb, offset);
if (*conv_version == SSL_VER_UNKNOWN
&& ssl_is_authoritative_version_message(content_type, next_byte))
{
if (version == SSLV3_VERSION)
{
*conv_version = SSL_VER_SSLv3;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
ssl_debug_printf("dissect_ssl3_record found version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
}
}
else if (version == TLSV1_VERSION)
{
*conv_version = SSL_VER_TLS;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
ssl_debug_printf("dissect_ssl3_record found version 0x%04X(TLS 1.0) -> state 0x%02X\n", ssl->version_netorder, ssl->state);
}
}
else if (version == TLSV1DOT1_VERSION)
{
*conv_version = SSL_VER_TLSv1DOT1;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
ssl_debug_printf("dissect_ssl3_record found version 0x%04X(TLS 1.1) -> state 0x%02X\n", ssl->version_netorder, ssl->state);
}
}
else if (version == TLSV1DOT2_VERSION)
{
*conv_version = SSL_VER_TLSv1DOT2;
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
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"));
ssl_debug_printf("dissect_ssl3_record: content_type %d %s\n",content_type, val_to_str_const(content_type, ssl_31_content_type, "unknown"));
switch (content_type) {
case SSL_ID_CHG_CIPHER_SPEC:
ssl_debug_printf("dissect_ssl3_change_cipher_spec\n");
col_append_str(pinfo->cinfo, COL_INFO, "Change Cipher Spec");
dissect_ssl3_change_cipher_spec(tvb, ssl_record_tree,
offset, conv_version, content_type);
if (ssl) ssl_change_cipher(ssl, ssl_packet_from_server(ssl, ssl_associations, pinfo));
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
dissect_ssl3_alert(decrypted, pinfo, ssl_record_tree, 0, conv_version);
} else {
dissect_ssl3_alert(tvb, pinfo, ssl_record_tree, offset, conv_version);
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
tvb_length(decrypted), conv_version, conv_cipher, ssl, content_type);
} else {
dissect_ssl3_handshake(tvb, pinfo, ssl_record_tree, offset,
record_length, conv_version, conv_cipher, ssl, content_type);
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
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
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
dissect_ssl3_heartbeat(decrypted, pinfo, ssl_record_tree, 0, conv_version, record_length);
} else {
dissect_ssl3_heartbeat(tvb, pinfo, ssl_record_tree, offset, conv_version, record_length);
}
break;
}
default:
col_append_str(pinfo->cinfo, COL_INFO, "Bad SSLv3 Content Type");
break;
}
offset += record_length;
return offset;
}
static void
dissect_ssl3_change_cipher_spec(tvbuff_t *tvb,
proto_tree *tree, guint32 offset,
guint *conv_version, const guint8 content_type)
{
if (tree)
{
proto_item_set_text(tree,
"%s Record Layer: %s Protocol: Change Cipher Spec",
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"));
proto_tree_add_item(tree, hf_ssl_change_cipher_spec, tvb,
offset++, 1, ENC_NA);
}
}
static void
dissect_ssl3_alert(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
guint *conv_version)
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
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
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
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"));
proto_item_set_text(ssl_alert_tree,
"Alert Message: Encrypted Alert");
}
}
}
static void
dissect_ssl3_handshake(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
guint32 record_length, guint *conv_version, guint conv_cipher,
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
proto_tree *ti;
if (first_iteration)
{
proto_item_set_text(tree, "%s Record Layer: %s Protocol: %s",
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"),
(msg_type_str!=NULL) ? msg_type_str :
"Encrypted Handshake Message");
}
else
{
proto_item_set_text(tree, "%s Record Layer: %s Protocol: %s",
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
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
switch (msg_type) {
case SSL_HND_HELLO_REQUEST:
break;
case SSL_HND_CLIENT_HELLO:
dissect_ssl3_hnd_cli_hello(tvb, pinfo, ssl_hand_tree, offset, length, ssl);
break;
case SSL_HND_SERVER_HELLO:
dissect_ssl3_hnd_srv_hello(tvb, ssl_hand_tree, offset, length, ssl);
break;
case SSL_HND_NEWSESSION_TICKET:
dissect_ssl3_hnd_new_ses_ticket(tvb, ssl_hand_tree, offset, length);
break;
case SSL_HND_CERTIFICATE:
dissect_ssl3_hnd_cert(tvb, ssl_hand_tree, offset, pinfo);
break;
case SSL_HND_SERVER_KEY_EXCHG: {
switch (ssl_get_keyex_alg(conv_cipher)) {
case KEX_DH:
dissect_ssl3_hnd_srv_keyex_dh(tvb, ssl_hand_tree, offset, length);
break;
case KEX_RSA:
dissect_ssl3_hnd_srv_keyex_rsa(tvb, ssl_hand_tree, offset, length);
break;
case KEX_ECDH:
dissect_ssl3_hnd_srv_keyex_ecdh(tvb, ssl_hand_tree, offset, length);
break;
default:
break;
}
}
break;
case SSL_HND_CERT_REQUEST:
dissect_ssl3_hnd_cert_req(tvb, ssl_hand_tree, offset, pinfo, conv_version);
break;
case SSL_HND_SVR_HELLO_DONE:
break;
case SSL_HND_CERT_VERIFY:
break;
case SSL_HND_CLIENT_KEY_EXCHG:
switch (ssl_get_keyex_alg(conv_cipher)) {
case KEX_DH:
dissect_ssl3_hnd_cli_keyex_dh(tvb, ssl_hand_tree, offset, length);
break;
case KEX_RSA:
dissect_ssl3_hnd_cli_keyex_rsa(tvb, ssl_hand_tree, offset, length);
break;
case KEX_ECDH:
dissect_ssl3_hnd_cli_keyex_ecdh(tvb, ssl_hand_tree, offset, length);
break;
default:
break;
}
{
gint cipher_num;
if (!ssl)
break;
cipher_num = ssl->cipher;
if (cipher_num == 0x8a || cipher_num == 0x8b || cipher_num == 0x8c || cipher_num == 0x8d)
{
StringInfo pre_master_secret;
guint psk_len, pre_master_len;
int size;
unsigned char *out;
int i,j = 0;
char input[2];
if (!ssl_psk || (ssl_psk[0] == 0)) {
ssl_debug_printf("dissect_ssl3_handshake can't find pre-shared-key\n");
break;
}
size = (int)strlen(ssl_psk);
if (size < 0 || size > 32 || size % 2 != 0)
{
break;
}
out = (unsigned char*) ep_alloc(size > 0 ? size / 2 : 0);
for (i = 0; i < size; i+=2)
{
input[0] = ssl_psk[0 + i];
input[1] = ssl_psk[1 + i];
out[j++] = (unsigned int) strtoul((const char*)&input, NULL, 16);
}
ssl->psk = (guchar*) out;
psk_len = size > 0 ? size / 2 : 0;
pre_master_len = psk_len * 2 + 4;
pre_master_secret.data = (guchar *)se_alloc(pre_master_len);
pre_master_secret.data_len = pre_master_len;
pre_master_secret.data[0] = psk_len >> 8;
pre_master_secret.data[1] = psk_len & 0xFF;
memset(&pre_master_secret.data[2], 0, psk_len);
pre_master_secret.data[psk_len + 2] = psk_len >> 8;
pre_master_secret.data[psk_len + 3] = psk_len & 0xFF;
memcpy(&pre_master_secret.data[psk_len + 4], ssl->psk, psk_len);
ssl->pre_master_secret.data = pre_master_secret.data;
ssl->pre_master_secret.data_len = pre_master_len;
ssl->state &= ~(SSL_MASTER_SECRET|SSL_HAVE_SESSION_KEY);
ssl->state |= SSL_PRE_MASTER_SECRET;
}
else
{
StringInfo encrypted_pre_master;
gint ret;
guint encrlen, skip;
encrlen = length;
skip = 0;
if (ssl->cipher_suite.kex==KEX_RSA && (ssl->version == SSL_VER_TLS||ssl->version == SSL_VER_TLSv1DOT1||ssl->version == SSL_VER_TLSv1DOT2))
{
encrlen = tvb_get_ntohs(tvb, offset);
skip = 2;
if (encrlen > length - 2)
{
ssl_debug_printf("dissect_ssl3_handshake wrong encrypted length (%d max %d)\n",
encrlen, length);
break;
}
}
encrypted_pre_master.data = (guchar *)se_alloc(encrlen);
encrypted_pre_master.data_len = encrlen;
tvb_memcpy(tvb, encrypted_pre_master.data, offset+skip, encrlen);
if (ssl->private_key) {
ret = ssl_decrypt_pre_master_secret(ssl, &encrypted_pre_master, ssl->private_key);
if (ret < 0) {
ssl_debug_printf("dissect_ssl3_handshake can't decrypt pre master secret\n");
break;
}
} else {
if (ssl_keylog_lookup(ssl, ssl_keylog_filename, &encrypted_pre_master)<0)
break;
}
}
if (ssl_generate_keyring_material(ssl)<0) {
ssl_debug_printf("dissect_ssl3_handshake can't generate keyring material\n");
break;
}
ssl_save_session(ssl, ssl_session_hash);
ssl_debug_printf("dissect_ssl3_handshake session keys successfully generated\n");
}
break;
case SSL_HND_FINISHED:
dissect_ssl3_hnd_finished(tvb, ssl_hand_tree,
offset, conv_version);
break;
case SSL_HND_CERT_STATUS:
dissect_ssl3_hnd_cert_status(tvb, ssl_hand_tree, offset, pinfo);
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
guint *conv_version, guint32 record_length)
{
proto_tree *ti;
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
if (type && (payload_length <= record_length - 16 - 3)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "Heartbeat %s", type);
} else {
col_append_str(pinfo->cinfo, COL_INFO, "Encrypted Heartbeat");
}
if (tree) {
if (type && (payload_length <= record_length - 16 - 3)) {
proto_item_set_text(tree, "%s Record Layer: Heartbeat "
"%s",
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
type);
proto_tree_add_item(tls_heartbeat_tree, hf_ssl_heartbeat_message_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint(tls_heartbeat_tree, hf_ssl_heartbeat_message_payload_length,
tvb, offset, 2, payload_length);
offset += 2;
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
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"));
proto_item_set_text(tls_heartbeat_tree,
"Encrypted Heartbeat Message");
}
}
}
static gint
dissect_ssl3_hnd_hello_common(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, SslDecryptSession *ssl, gint from_server)
{
nstime_t gmt_unix_time;
guint8 session_id_length;
proto_item *ti_rnd;
proto_tree *ssl_rnd_tree;
session_id_length = 0;
if (ssl)
{
StringInfo *rnd;
if (from_server)
rnd = &ssl->server_random;
else
rnd = &ssl->client_random;
tvb_memcpy(tvb, rnd->data, offset, 32);
rnd->data_len = 32;
if (from_server)
ssl->state |= SSL_SERVER_RANDOM;
else
ssl->state |= SSL_CLIENT_RANDOM;
ssl_debug_printf("dissect_ssl3_hnd_hello_common found %s RANDOM -> state 0x%02X\n",
(from_server)?"SERVER":"CLIENT", ssl->state);
session_id_length = tvb_get_guint8(tvb, offset + 32);
if (from_server && (session_id_length == ssl->session_id.data_len) &&
(tvb_memeql(tvb, offset+33, ssl->session_id.data, session_id_length) == 0))
{
if (!ssl_restore_session(ssl, ssl_session_hash)) {
if (ssl_keylog_lookup(ssl, ssl_keylog_filename, NULL)) {
ssl_debug_printf(" cannot find master secret in keylog file either\n");
} else {
ssl_debug_printf(" found master secret in keylog file\n");
}
}
} else {
tvb_memcpy(tvb,ssl->session_id.data, offset+33, session_id_length);
ssl->session_id.data_len = session_id_length;
}
}
if (tree)
{
ti_rnd = proto_tree_add_text(tree, tvb, offset, 32, "Random");
ssl_rnd_tree = proto_item_add_subtree(ti_rnd, ett_ssl_random);
gmt_unix_time.secs = tvb_get_ntohl(tvb, offset);
gmt_unix_time.nsecs = 0;
proto_tree_add_time(ssl_rnd_tree, hf_ssl_handshake_random_time,
tvb, offset, 4, &gmt_unix_time);
offset += 4;
proto_tree_add_item(ssl_rnd_tree, hf_ssl_handshake_random_bytes,
tvb, offset, 28, ENC_NA);
offset += 28;
session_id_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ssl_handshake_session_id_len,
tvb, offset++, 1, ENC_BIG_ENDIAN);
if (session_id_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, session_id_length);
proto_tree_add_item(tree, hf_ssl_handshake_session_id,
tvb, offset, session_id_length, ENC_NA);
}
}
return session_id_length+33;
}
static gint
dissect_ssl3_hnd_hello_ext(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 left)
{
guint16 extension_length;
guint16 ext_type;
guint16 ext_len;
proto_item *pi;
proto_tree *ext_tree;
if (left < 2)
return offset;
extension_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_ssl_handshake_extensions_len,
tvb, offset, 2, extension_length);
offset += 2;
left -= 2;
while (left >= 4)
{
ext_type = tvb_get_ntohs(tvb, offset);
ext_len = tvb_get_ntohs(tvb, offset + 2);
pi = proto_tree_add_text(tree, tvb, offset, 4 + ext_len,
"Extension: %s",
val_to_str(ext_type,
tls_hello_extension_types,
"Unknown %u"));
ext_tree = proto_item_add_subtree(pi, ett_ssl_extension);
if (!ext_tree)
ext_tree = tree;
proto_tree_add_uint(ext_tree, hf_ssl_handshake_extension_type,
tvb, offset, 2, ext_type);
offset += 2;
proto_tree_add_uint(ext_tree, hf_ssl_handshake_extension_len,
tvb, offset, 2, ext_len);
offset += 2;
switch (ext_type) {
case SSL_HND_HELLO_EXT_ELLIPTIC_CURVES:
offset = dissect_ssl3_hnd_hello_ext_elliptic_curves(tvb, ext_tree, offset);
break;
case SSL_HND_HELLO_EXT_EC_POINT_FORMATS:
offset = dissect_ssl3_hnd_hello_ext_ec_point_formats(tvb, ext_tree, offset);
break;
case SSL_HND_HELLO_EXT_NPN:
offset = dissect_ssl3_hnd_hello_ext_npn(tvb, ext_tree, offset, ext_len);
break;
case SSL_HND_HELLO_EXT_RENEG_INFO:
offset = dissect_ssl3_hnd_hello_ext_reneg_info(tvb, ext_tree, offset, ext_len);
break;
case SSL_HND_HELLO_EXT_SERVER_NAME:
offset = dissect_ssl3_hnd_hello_ext_server_name(tvb, ext_tree, offset, ext_len);
break;
case SSL_HND_HELLO_EXT_HEARTBEAT:
proto_tree_add_item(ext_tree, hf_ssl_heartbeat_extension_mode,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += ext_len;
break;
default:
proto_tree_add_bytes_format(ext_tree, hf_ssl_handshake_extension_data,
tvb, offset, ext_len, NULL,
"Data (%u byte%s)",
ext_len, plurality(ext_len, "", "s"));
offset += ext_len;
break;
}
left -= 2 + 2 + ext_len;
}
return offset;
}
static gint
dissect_ssl3_hnd_hello_ext_npn(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 ext_len)
{
guint8 npn_length;
proto_tree *npn_tree, *ti;
if (ext_len == 0) {
return offset;
}
ti = proto_tree_add_text(tree, tvb, offset, ext_len, "Next Protocol Negotiation");
npn_tree = proto_item_add_subtree(ti, ett_ssl_extension_npn);
while (ext_len > 0) {
npn_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(npn_tree, hf_ssl_handshake_extension_npn_str_len,
tvb, offset, 1, ENC_NA);
offset++;
ext_len--;
if (npn_length > 0) {
tvb_ensure_bytes_exist(tvb, offset, npn_length);
proto_tree_add_item(npn_tree, hf_ssl_handshake_extension_npn_str,
tvb, offset, npn_length, ENC_ASCII|ENC_NA);
offset += npn_length;
ext_len -= npn_length;
}
}
return offset;
}
static gint
dissect_ssl3_hnd_hello_ext_reneg_info(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 ext_len)
{
guint8 reneg_info_length;
proto_tree *reneg_info_tree, *ti;
if (ext_len == 0) {
return offset;
}
ti = proto_tree_add_text(tree, tvb, offset, ext_len, "Renegotiation Info extension");
reneg_info_tree = proto_item_add_subtree(ti, ett_ssl_extension_reneg_info);
reneg_info_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(reneg_info_tree, hf_ssl_handshake_extension_reneg_info_len,
tvb, offset, 1, ENC_NA);
offset += 1;
if (reneg_info_length > 0) {
tvb_ensure_bytes_exist(tvb, offset, reneg_info_length);
proto_tree_add_text(reneg_info_tree, tvb, offset, reneg_info_length, "Renegotiation Info");
offset += reneg_info_length;
}
return offset;
}
static gint
dissect_ssl3_hnd_hello_ext_server_name(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 ext_len)
{
guint16 server_name_length;
proto_tree *server_name_tree, *ti;
if (ext_len == 0) {
return offset;
}
ti = proto_tree_add_text(tree, tvb, offset, ext_len, "Server Name Indication extension");
server_name_tree = proto_item_add_subtree(ti, ett_ssl_extension_server_name);
proto_tree_add_item(server_name_tree, hf_ssl_handshake_extension_server_name_list_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ext_len -= 2;
while (ext_len > 0) {
proto_tree_add_item(server_name_tree, hf_ssl_handshake_extension_server_name_type,
tvb, offset, 1, ENC_NA);
offset += 1;
ext_len -= 1;
server_name_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(server_name_tree, hf_ssl_handshake_extension_server_name_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ext_len -= 2;
if (server_name_length > 0) {
tvb_ensure_bytes_exist(tvb, offset, server_name_length);
proto_tree_add_item(server_name_tree, hf_ssl_handshake_extension_server_name,
tvb, offset, server_name_length, ENC_ASCII|ENC_NA);
offset += server_name_length;
ext_len -= server_name_length;
}
}
return offset;
}
static gint
dissect_ssl3_hnd_hello_ext_elliptic_curves(tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
guint16 curves_length;
proto_tree *curves_tree;
proto_tree *ti;
curves_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_ssl_handshake_extension_elliptic_curves_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tvb_ensure_bytes_exist(tvb, offset, curves_length);
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_extension_elliptic_curves,
tvb, offset, curves_length,
"Elliptic curves (%d curve%s)",
curves_length / 2,
plurality(curves_length/2, "", "s"));
curves_tree = proto_item_add_subtree(ti, ett_ssl_extension_curves);
while (curves_length > 0)
{
proto_tree_add_item(curves_tree, hf_ssl_handshake_extension_elliptic_curve, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
curves_length -= 2;
}
return offset;
}
static gint
dissect_ssl3_hnd_hello_ext_ec_point_formats(tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
guint8 ecpf_length;
proto_tree *ecpf_tree;
proto_tree *ti;
ecpf_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ssl_handshake_extension_ec_point_formats_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tvb_ensure_bytes_exist(tvb, offset, ecpf_length);
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_extension_elliptic_curves,
tvb, offset, ecpf_length,
"Elliptic curves point formats (%d)",
ecpf_length);
ecpf_tree = proto_item_add_subtree(ti, ett_ssl_extension_curves_point_formats);
while (ecpf_length > 0)
{
proto_tree_add_item(ecpf_tree, hf_ssl_handshake_extension_ec_point_format, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ecpf_length--;
}
return offset;
}
static void
dissect_ssl3_hnd_cli_hello(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 length,
SslDecryptSession*ssl)
{
proto_tree *ti;
proto_tree *cs_tree;
gint cipher_suite_length;
guint8 compression_methods_length;
guint8 compression_method;
guint16 start_offset;
start_offset = offset;
if (ssl) {
ssl_set_server(ssl, &pinfo->dst, pinfo->ptype, pinfo->destport);
ssl_find_private_key(ssl, ssl_key_hash, ssl_associations, pinfo);
}
if (tree || ssl)
{
if (tree)
proto_tree_add_item(tree, hf_ssl_handshake_client_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += dissect_ssl3_hnd_hello_common(tvb, tree, offset, ssl, 0);
cipher_suite_length = tvb_get_ntohs(tvb, offset);
if (!tree)
return;
proto_tree_add_uint(tree, hf_ssl_handshake_cipher_suites_len,
tvb, offset, 2, cipher_suite_length);
offset += 2;
if (cipher_suite_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, cipher_suite_length);
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_cipher_suites,
tvb, offset, cipher_suite_length,
"Cipher Suites (%d suite%s)",
cipher_suite_length / 2,
plurality(cipher_suite_length/2, "", "s"));
if (cipher_suite_length % 2) {
proto_tree_add_text(tree, tvb, offset, 2,
"Invalid cipher suite length: %d", cipher_suite_length);
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR,
"Cipher suite length (%d) must be a multiple of 2",
cipher_suite_length);
return;
}
cs_tree = proto_item_add_subtree(ti, ett_ssl_cipher_suites);
if (!cs_tree)
{
cs_tree = tree;
}
while (cipher_suite_length > 0)
{
proto_tree_add_item(cs_tree, hf_ssl_handshake_cipher_suite,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
cipher_suite_length -= 2;
}
}
compression_methods_length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ssl_handshake_comp_methods_len,
tvb, offset, 1, compression_methods_length);
offset += 1;
if (compression_methods_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, compression_methods_length);
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_comp_methods,
tvb, offset, compression_methods_length,
"Compression Methods (%u method%s)",
compression_methods_length,
plurality(compression_methods_length,
"", "s"));
cs_tree = proto_item_add_subtree(ti, ett_ssl_comp_methods);
if (!cs_tree)
{
cs_tree = tree;
}
while (compression_methods_length > 0)
{
compression_method = tvb_get_guint8(tvb, offset);
if (compression_method < 64)
proto_tree_add_uint(cs_tree, hf_ssl_handshake_comp_method,
tvb, offset, 1, compression_method);
else if (compression_method > 63 && compression_method < 193)
proto_tree_add_text(cs_tree, tvb, offset, 1,
"Compression Method: Reserved - to be assigned by IANA (%u)",
compression_method);
else
proto_tree_add_text(cs_tree, tvb, offset, 1,
"Compression Method: Private use range (%u)",
compression_method);
offset++;
compression_methods_length--;
}
}
if (length > offset - start_offset)
{
dissect_ssl3_hnd_hello_ext(tvb, tree, offset,
length - (offset - start_offset));
}
}
}
static void
dissect_ssl3_hnd_srv_hello(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 length, SslDecryptSession *ssl)
{
guint16 start_offset;
start_offset = offset;
if (tree || ssl)
{
if (tree)
proto_tree_add_item(tree, hf_ssl_handshake_server_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += dissect_ssl3_hnd_hello_common(tvb, tree, offset, ssl, 1);
if (ssl) {
ssl->cipher = tvb_get_ntohs(tvb, offset);
if (ssl_find_cipher(ssl->cipher,&ssl->cipher_suite) < 0) {
ssl_debug_printf("dissect_ssl3_hnd_srv_hello can't find cipher suite 0x%X\n", ssl->cipher);
goto no_cipher;
}
ssl->state |= SSL_CIPHER;
ssl_debug_printf("dissect_ssl3_hnd_srv_hello found CIPHER 0x%04X -> state 0x%02X\n",
ssl->cipher, ssl->state);
ssl_debug_printf("dissect_ssl3_hnd_srv_hello trying to generate keys\n");
if (ssl_generate_keyring_material(ssl)<0) {
ssl_debug_printf("dissect_ssl3_hnd_srv_hello can't generate keyring material\n");
goto no_cipher;
}
}
no_cipher:
proto_tree_add_item(tree, hf_ssl_handshake_cipher_suite,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (ssl) {
ssl->compression = tvb_get_guint8(tvb, offset);
}
proto_tree_add_item(tree, hf_ssl_handshake_comp_method,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (length > offset - start_offset)
{
dissect_ssl3_hnd_hello_ext(tvb, tree, offset,
length - (offset - start_offset));
}
}
}
static void
dissect_ssl3_hnd_new_ses_ticket(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 length)
{
guint nst_len;
proto_item *ti;
proto_tree *subtree;
nst_len = tvb_get_ntohs(tvb, offset+4);
if (6 + nst_len != length) {
return;
}
ti = proto_tree_add_text(tree, tvb, offset, 6+nst_len, "TLS Session Ticket");
subtree = proto_item_add_subtree(ti, ett_ssl_new_ses_ticket);
proto_tree_add_item(subtree, hf_ssl_handshake_session_ticket_lifetime_hint,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_uint(subtree, hf_ssl_handshake_session_ticket_len,
tvb, offset, 2, nst_len);
proto_tree_add_item(subtree, hf_ssl_handshake_session_ticket,
tvb, offset + 2, nst_len, ENC_NA);
}
static void
dissect_ssl3_hnd_cert(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, packet_info *pinfo)
{
guint32 certificate_list_length;
proto_tree *ti;
proto_tree *subtree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (tree)
{
certificate_list_length = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint(tree, hf_ssl_handshake_certificates_len,
tvb, offset, 3, certificate_list_length);
offset += 3;
if (certificate_list_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, certificate_list_length);
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_certificates,
tvb, offset, certificate_list_length,
"Certificates (%u byte%s)",
certificate_list_length,
plurality(certificate_list_length, "", "s"));
subtree = proto_item_add_subtree(ti, ett_ssl_certs);
if (!subtree)
{
subtree = tree;
}
while (certificate_list_length > 0)
{
guint32 cert_length;
cert_length = tvb_get_ntoh24(tvb, offset);
certificate_list_length -= 3 + cert_length;
proto_tree_add_item(subtree, hf_ssl_handshake_certificate_len,
tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
(void)dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, subtree, hf_ssl_handshake_certificate);
offset += cert_length;
}
}
}
}
static void
dissect_ssl3_hnd_cert_req(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, packet_info *pinfo,
const guint *conv_version)
{
proto_tree *ti;
proto_tree *subtree;
proto_tree *saved_subtree;
guint8 cert_types_count;
gint sh_alg_length;
guint16 sig_hash_alg;
gint dnames_length;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (tree)
{
cert_types_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_ssl_handshake_cert_types_count,
tvb, offset, 1, cert_types_count);
offset += 1;
if (cert_types_count > 0)
{
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_cert_types,
tvb, offset, cert_types_count,
"Certificate types (%u type%s)",
cert_types_count,
plurality(cert_types_count, "", "s"));
subtree = proto_item_add_subtree(ti, ett_ssl_cert_types);
if (!subtree)
{
subtree = tree;
}
while (cert_types_count > 0)
{
proto_tree_add_item(subtree, hf_ssl_handshake_cert_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
cert_types_count--;
}
}
switch (*conv_version) {
case SSL_VER_TLSv1DOT2:
sh_alg_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_ssl_handshake_sig_hash_alg_len,
tvb, offset, 2, sh_alg_length);
offset += 2;
if (sh_alg_length > 0)
{
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_sig_hash_algs,
tvb, offset, sh_alg_length,
"Signature Hash Algorithms (%u algorithm%s)",
sh_alg_length/2,
plurality(sh_alg_length/2, "", "s"));
subtree = proto_item_add_subtree(ti, ett_ssl_sig_hash_algs);
if (!subtree)
{
subtree = tree;
}
if (sh_alg_length % 2) {
proto_tree_add_text(tree, tvb, offset, 2,
"Invalid Signature Hash Algorithm length: %d", sh_alg_length);
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR,
"Signature Hash Algorithm length (%d) must be a multiple of 2",
sh_alg_length);
return;
}
while (sh_alg_length > 0)
{
saved_subtree = subtree;
sig_hash_alg = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_uint(subtree, hf_ssl_handshake_sig_hash_alg,
tvb, offset, 2, sig_hash_alg);
subtree = proto_item_add_subtree(ti, ett_ssl_sig_hash_alg);
if (!subtree)
{
subtree = saved_subtree;
}
proto_tree_add_item(subtree, hf_ssl_handshake_sig_hash_hash,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ssl_handshake_sig_hash_sig,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
subtree = saved_subtree;
offset += 2;
sh_alg_length -= 2;
}
}
break;
default:
break;
}
dnames_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_ssl_handshake_dnames_len,
tvb, offset, 2, dnames_length);
offset += 2;
if (dnames_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, dnames_length);
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_dnames,
tvb, offset, dnames_length,
"Distinguished Names (%d byte%s)",
dnames_length,
plurality(dnames_length, "", "s"));
subtree = proto_item_add_subtree(ti, ett_ssl_dnames);
if (!subtree)
{
subtree = tree;
}
while (dnames_length > 0)
{
guint16 name_length;
name_length = tvb_get_ntohs(tvb, offset);
dnames_length -= 2 + name_length;
proto_tree_add_item(subtree, hf_ssl_handshake_dname_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tvb_ensure_bytes_exist(tvb, offset, name_length);
(void)dissect_x509if_DistinguishedName(FALSE, tvb, offset, &asn1_ctx, subtree, hf_ssl_handshake_dname);
offset += name_length;
}
}
}
}
static void
dissect_ssl3_hnd_srv_keyex_ecdh(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 length)
{
gint curve_type, curve_type_offset;
gint named_curve, named_curve_offset;
gint point_len, point_len_offset;
gint sig_len, sig_len_offset;
proto_item *ti_ecdh;
proto_tree *ssl_ecdh_tree;
guint32 orig_offset;
orig_offset = offset;
curve_type_offset = offset;
curve_type = tvb_get_guint8(tvb, offset);
if (curve_type != 3)
return;
offset += 1;
if ((offset - orig_offset) > length) {
return;
}
named_curve_offset = offset;
named_curve = tvb_get_ntohs(tvb, offset);
offset += 2;
if ((offset - orig_offset) > length) {
return;
}
point_len_offset = offset;
point_len = tvb_get_guint8(tvb, offset);
if ((offset + point_len - orig_offset) > length) {
return;
}
offset += 1 + point_len;
sig_len_offset = offset;
sig_len = tvb_get_ntohs(tvb, offset);
offset += 2 + sig_len;
if ((offset - orig_offset) != length) {
return;
}
ti_ecdh = proto_tree_add_text(tree, tvb, orig_offset,
(offset - orig_offset), "EC Diffie-Hellman Server Params");
ssl_ecdh_tree = proto_item_add_subtree(ti_ecdh, ett_ssl_keyex_params);
proto_tree_add_uint(ssl_ecdh_tree, hf_ssl_handshake_server_keyex_curve_type,
tvb, curve_type_offset, 1, curve_type);
proto_tree_add_uint(ssl_ecdh_tree, hf_ssl_handshake_server_keyex_named_curve,
tvb, named_curve_offset, 2, named_curve);
proto_tree_add_uint(ssl_ecdh_tree, hf_ssl_handshake_server_keyex_point_len,
tvb, point_len_offset, 1, point_len);
proto_tree_add_item(ssl_ecdh_tree, hf_ssl_handshake_server_keyex_point,
tvb, point_len_offset+1, point_len, ENC_NA);
proto_tree_add_uint(ssl_ecdh_tree, hf_ssl_handshake_server_keyex_sig_len,
tvb, sig_len_offset, 2, sig_len);
proto_tree_add_item(ssl_ecdh_tree, hf_ssl_handshake_server_keyex_sig,
tvb, sig_len_offset + 2, sig_len, ENC_NA);
}
static void
dissect_ssl3_hnd_cli_keyex_ecdh(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 length)
{
gint point_len, point_len_offset;
proto_item *ti_ecdh;
proto_tree *ssl_ecdh_tree;
guint32 orig_offset;
orig_offset = offset;
point_len_offset = offset;
point_len = tvb_get_guint8(tvb, offset);
if ((offset + point_len - orig_offset) > length) {
return;
}
offset += 1 + point_len;
ti_ecdh = proto_tree_add_text(tree, tvb, orig_offset,
(offset - orig_offset), "EC Diffie-Hellman Client Params");
ssl_ecdh_tree = proto_item_add_subtree(ti_ecdh, ett_ssl_keyex_params);
proto_tree_add_uint(ssl_ecdh_tree, hf_ssl_handshake_client_keyex_point_len,
tvb, point_len_offset, 1, point_len);
proto_tree_add_item(ssl_ecdh_tree, hf_ssl_handshake_client_keyex_point,
tvb, point_len_offset+1, point_len, ENC_NA);
}
static void
dissect_ssl3_hnd_srv_keyex_dh(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 length)
{
gint p_len, p_len_offset;
gint g_len, g_len_offset;
gint ys_len, ys_len_offset;
gint sig_len, sig_len_offset;
proto_item *ti_dh;
proto_tree *ssl_dh_tree;
guint32 orig_offset;
orig_offset = offset;
p_len_offset = offset;
p_len = tvb_get_ntohs(tvb, offset);
offset += 2 + p_len;
if ((offset - orig_offset) > length) {
return;
}
g_len_offset = offset;
g_len = tvb_get_ntohs(tvb, offset);
offset += 2 + g_len;
if ((offset - orig_offset) > length) {
return;
}
ys_len_offset = offset;
ys_len = tvb_get_ntohs(tvb, offset);
offset += 2 + ys_len;
if ((offset - orig_offset) > length) {
return;
}
sig_len_offset = offset;
sig_len = tvb_get_ntohs(tvb, offset);
offset += 2 + sig_len;
if ((offset - orig_offset) != length) {
return;
}
ti_dh = proto_tree_add_text(tree, tvb, orig_offset,
(offset - orig_offset), "Diffie-Hellman Server Params");
ssl_dh_tree = proto_item_add_subtree(ti_dh, ett_ssl_keyex_params);
proto_tree_add_uint(ssl_dh_tree, hf_ssl_handshake_server_keyex_p_len,
tvb, p_len_offset, 2, p_len);
proto_tree_add_item(ssl_dh_tree, hf_ssl_handshake_server_keyex_p,
tvb, p_len_offset + 2, p_len, ENC_NA);
proto_tree_add_uint(ssl_dh_tree, hf_ssl_handshake_server_keyex_g_len,
tvb, g_len_offset, 2, g_len);
proto_tree_add_item(ssl_dh_tree, hf_ssl_handshake_server_keyex_g,
tvb, g_len_offset + 2, g_len, ENC_NA);
proto_tree_add_uint(ssl_dh_tree, hf_ssl_handshake_server_keyex_ys_len,
tvb, ys_len_offset, 2, ys_len);
proto_tree_add_item(ssl_dh_tree, hf_ssl_handshake_server_keyex_ys,
tvb, ys_len_offset + 2, ys_len, ENC_NA);
proto_tree_add_uint(ssl_dh_tree, hf_ssl_handshake_server_keyex_sig_len,
tvb, sig_len_offset, 2, sig_len);
proto_tree_add_item(ssl_dh_tree, hf_ssl_handshake_server_keyex_sig,
tvb, sig_len_offset + 2, sig_len, ENC_NA);
}
static void
dissect_ssl3_hnd_srv_keyex_rsa(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 length)
{
gint modulus_len, modulus_len_offset;
gint exponent_len, exponent_len_offset;
gint sig_len, sig_len_offset;
proto_item *ti_rsa;
proto_tree *ssl_rsa_tree;
guint32 orig_offset;
orig_offset = offset;
modulus_len_offset = offset;
modulus_len = tvb_get_ntohs(tvb, offset);
offset += 2 + modulus_len;
if ((offset - orig_offset) > length) {
return;
}
exponent_len_offset = offset;
exponent_len = tvb_get_ntohs(tvb, offset);
offset += 2 + exponent_len;
if ((offset - orig_offset) > length) {
return;
}
sig_len_offset = offset;
sig_len = tvb_get_ntohs(tvb, offset);
offset += 2 + sig_len;
if ((offset - orig_offset) != length) {
return;
}
ti_rsa = proto_tree_add_text(tree, tvb, orig_offset,
(offset - orig_offset), "RSA-EXPORT Server Params");
ssl_rsa_tree = proto_item_add_subtree(ti_rsa, ett_ssl_keyex_params);
proto_tree_add_uint(ssl_rsa_tree, hf_ssl_handshake_server_keyex_modulus_len,
tvb, modulus_len_offset, 2, modulus_len);
proto_tree_add_item(ssl_rsa_tree, hf_ssl_handshake_server_keyex_modulus,
tvb, modulus_len_offset + 2, modulus_len, ENC_NA);
proto_tree_add_uint(ssl_rsa_tree, hf_ssl_handshake_server_keyex_exponent_len,
tvb, exponent_len_offset, 2, exponent_len);
proto_tree_add_item(ssl_rsa_tree, hf_ssl_handshake_server_keyex_exponent,
tvb, exponent_len_offset + 2, exponent_len, ENC_NA);
proto_tree_add_uint(ssl_rsa_tree, hf_ssl_handshake_server_keyex_sig_len,
tvb, sig_len_offset, 2, sig_len);
proto_tree_add_item(ssl_rsa_tree, hf_ssl_handshake_server_keyex_sig,
tvb, sig_len_offset + 2, sig_len, ENC_NA);
}
static void
dissect_ssl3_hnd_cli_keyex_dh(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 length)
{
gint yc_len, yc_len_offset;
proto_item *ti_dh;
proto_tree *ssl_dh_tree;
guint32 orig_offset;
orig_offset = offset;
yc_len_offset = offset;
yc_len = tvb_get_ntohs(tvb, offset);
offset += 2 + yc_len;
if ((offset - orig_offset) != length) {
return;
}
ti_dh = proto_tree_add_text(tree, tvb, orig_offset,
(offset - orig_offset), "Diffie-Hellman Client Params");
ssl_dh_tree = proto_item_add_subtree(ti_dh, ett_ssl_keyex_params);
proto_tree_add_uint(ssl_dh_tree, hf_ssl_handshake_client_keyex_yc_len,
tvb, yc_len_offset, 2, yc_len);
proto_tree_add_item(ssl_dh_tree, hf_ssl_handshake_client_keyex_yc,
tvb, yc_len_offset + 2, yc_len, ENC_NA);
}
static void
dissect_ssl3_hnd_cli_keyex_rsa(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 length)
{
gint epms_len, epms_len_offset;
proto_item *ti_rsa;
proto_tree *ssl_rsa_tree;
guint32 orig_offset;
orig_offset = offset;
epms_len_offset = offset;
epms_len = tvb_get_ntohs(tvb, offset);
offset += 2 + epms_len;
if ((offset - orig_offset) != length) {
return;
}
ti_rsa = proto_tree_add_text(tree, tvb, orig_offset,
(offset - orig_offset), "RSA Encrypted PreMaster Secret");
ssl_rsa_tree = proto_item_add_subtree(ti_rsa, ett_ssl_keyex_params);
proto_tree_add_uint(ssl_rsa_tree, hf_ssl_handshake_client_keyex_epms_len,
tvb, epms_len_offset, 2, epms_len);
proto_tree_add_item(ssl_rsa_tree, hf_ssl_handshake_client_keyex_epms,
tvb, epms_len_offset + 2, epms_len, ENC_NA);
}
static void
dissect_ssl3_hnd_finished(tvbuff_t *tvb,
proto_tree *tree, const guint32 offset,
const guint *conv_version)
{
if (!tree)
{
return;
}
switch (*conv_version) {
case SSL_VER_TLS:
case SSL_VER_TLSv1DOT1:
case SSL_VER_TLSv1DOT2:
proto_tree_add_item(tree, hf_ssl_handshake_finished,
tvb, offset, 12, ENC_NA);
break;
case SSL_VER_SSLv3:
proto_tree_add_item(tree, hf_ssl_handshake_md5_hash,
tvb, offset, 16, ENC_NA);
proto_tree_add_item(tree, hf_ssl_handshake_sha_hash,
tvb, offset + 16, 20, ENC_NA);
break;
}
}
static void
dissect_ssl3_hnd_cert_status(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, packet_info *pinfo)
{
guint8 cert_status_type;
guint cert_status_len;
proto_tree *ti;
proto_tree *cert_status_tree;
if (tree)
{
cert_status_type = tvb_get_guint8(tvb, offset);
cert_status_len = tvb_get_ntoh24(tvb, offset+1);
tvb_ensure_bytes_exist(tvb, offset, cert_status_len+4);
ti = proto_tree_add_none_format(tree, hf_ssl_handshake_cert_status,
tvb, offset, cert_status_len+4,
"Certificate Status (%u byte%s)",
cert_status_len+4,
plurality(cert_status_len+4, "", "s"));
cert_status_tree = proto_item_add_subtree(ti, ett_ssl_cert_status);
proto_tree_add_item(cert_status_tree, hf_ssl_handshake_cert_status_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint(cert_status_tree, hf_ssl_handshake_cert_status_len,
tvb, offset, 3, cert_status_len);
offset += 3;
if (cert_status_len > 0)
{
switch (cert_status_type) {
case SSL_HND_CERT_STATUS_TYPE_OCSP:
{
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
break;
}
default:
break;
}
}
}
}
static gint
dissect_ssl2_record(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint32 offset, guint *conv_version,
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
proto_tree *ti;
proto_tree *ssl_record_tree;
initial_offset = offset;
record_length = 0;
is_escape = -1;
padding_length = -1;
msg_type_str = NULL;
ssl_record_tree = NULL;
byte = tvb_get_guint8(tvb, offset);
record_length_length = (byte & 0x80) ? 2 : 3;
available_bytes = tvb_length_remaining(tvb, offset);
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
if (*conv_version == SSL_VER_UNKNOWN)
{
if (ssl_looks_like_valid_pct_handshake(tvb,
(initial_offset +
record_length_length),
record_length)) {
*conv_version = SSL_VER_PCT;
}
else if (msg_type >= 2 && msg_type <= 8)
{
*conv_version = SSL_VER_SSLv2;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL,
(*conv_version == SSL_VER_PCT) ? "PCT" : "SSLv2");
msg_type_str = try_val_to_str(msg_type,
(*conv_version == SSL_VER_PCT)
? pct_msg_types : ssl_20_msg_types);
if (!msg_type_str
|| ((*conv_version != SSL_VER_PCT) &&
!ssl_looks_like_valid_v2_handshake(tvb, initial_offset
+ record_length_length,
record_length))
|| ((*conv_version == SSL_VER_PCT) &&
!ssl_looks_like_valid_pct_handshake(tvb, initial_offset
+ record_length_length,
record_length)))
{
if (ssl_record_tree)
{
proto_item_set_text(ssl_record_tree, "%s Record Layer: %s",
(*conv_version == SSL_VER_PCT)
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
(*conv_version == SSL_VER_PCT)
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
(*conv_version == SSL_VER_PCT)
? hf_pct_msg_type : hf_ssl2_msg_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
if (*conv_version != SSL_VER_PCT)
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
proto_tree *ti;
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
proto_tree_add_item(tree, hf_ssl_handshake_client_version, tvb,
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
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_ERROR,
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
ti = proto_tree_add_none_format(tree, hf_ssl_handshake_cipher_suites,
tvb, offset, cipher_spec_length,
"Cipher Specs (%u specs)",
cipher_spec_length/3);
cs_tree = proto_item_add_subtree(ti, ett_ssl_cipher_suites);
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
hf_ssl_handshake_session_id,
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
proto_tree *ti;
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
proto_tree_add_item(tree, hf_ssl_handshake_server_version,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
certificate_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_ssl_handshake_certificate_len,
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
(void)dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, tree, hf_ssl_handshake_certificate);
offset += certificate_length;
}
if (cipher_spec_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, cipher_spec_length);
ti = proto_tree_add_none_format(tree,
hf_ssl_handshake_cipher_suites,
tvb, offset, cipher_spec_length,
"Cipher Specs (%u spec%s)",
cipher_spec_length/3,
plurality(cipher_spec_length/3, "", "s"));
subtree = proto_item_add_subtree(ti, ett_ssl_cipher_suites);
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
ssl = (SslDecryptSession *)se_alloc0(sizeof(SslDecryptSession));
ssl_session_init(ssl);
ssl->version = SSL_VER_UNKNOWN;
conversation_add_proto_data(conversation, proto_ssl, ssl);
}
ssl_debug_printf(" conversation = %p, ssl_session = %p\n", (void *)conversation, (void *)ssl);
ssl_set_server(ssl, addr_srv, ptype, port_srv);
if ((ssl->version==SSL_VER_UNKNOWN) && (version!=SSL_VER_UNKNOWN)) {
switch (version) {
case SSL_VER_SSLv3:
ssl->version = SSL_VER_SSLv3;
ssl->version_netorder = SSLV3_VERSION;
ssl->state |= SSL_VERSION;
ssl_debug_printf("ssl_set_master_secret set version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
break;
case SSL_VER_TLS:
ssl->version = SSL_VER_TLS;
ssl->version_netorder = TLSV1_VERSION;
ssl->state |= SSL_VERSION;
ssl_debug_printf("ssl_set_master_secret set version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
break;
case SSL_VER_TLSv1DOT1:
ssl->version = SSL_VER_TLSv1DOT1;
ssl->version_netorder = TLSV1DOT1_VERSION;
ssl->state |= SSL_VERSION;
ssl_debug_printf("ssl_set_master_secret set version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
break;
case SSL_VER_TLSv1DOT2:
ssl->version = SSL_VER_TLSv1DOT2;
ssl->version_netorder = TLSV1DOT2_VERSION;
ssl->state |= SSL_VERSION;
ssl_debug_printf("ssl_set_master_secret set version 0x%04X -> state 0x%02X\n", ssl->version_netorder, ssl->state);
break;
}
}
if (cipher > 0) {
ssl->cipher = cipher;
if (ssl_find_cipher(ssl->cipher,&ssl->cipher_suite) < 0) {
ssl_debug_printf("ssl_set_master_secret can't find cipher suite 0x%X\n", ssl->cipher);
} else {
ssl->state |= SSL_CIPHER;
ssl_debug_printf("ssl_set_master_secret set CIPHER 0x%04X -> state 0x%02X\n", ssl->cipher, ssl->state);
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
ssl_is_valid_handshake_type(const guint8 type)
{
switch (type) {
case SSL_HND_HELLO_REQUEST:
case SSL_HND_CLIENT_HELLO:
case SSL_HND_SERVER_HELLO:
case SSL_HND_NEWSESSION_TICKET:
case SSL_HND_CERTIFICATE:
case SSL_HND_SERVER_KEY_EXCHG:
case SSL_HND_CERT_REQUEST:
case SSL_HND_SVR_HELLO_DONE:
case SSL_HND_CERT_VERIFY:
case SSL_HND_CLIENT_KEY_EXCHG:
case SSL_HND_FINISHED:
return 1;
}
return 0;
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
&& ssl_is_valid_handshake_type(next_byte))
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
static void
ssldecrypt_update_cb(void *r _U_, const char **err)
{
if (err)
*err = NULL;
return;
}
static void*
ssldecrypt_copy_cb(void *dest, const void *orig, size_t len _U_)
{
const ssldecrypt_assoc_t *o = (ssldecrypt_assoc_t *)orig;
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
{ &hf_ssl_handshake_client_version,
{ "Version", "ssl.handshake.version",
FT_UINT16, BASE_HEX, VALS(ssl_versions), 0x0,
"Maximum version supported by client", HFILL }
},
{ &hf_ssl_handshake_server_version,
{ "Version", "ssl.handshake.version",
FT_UINT16, BASE_HEX, VALS(ssl_versions), 0x0,
"Version selected by server", HFILL }
},
{ &hf_ssl_handshake_random_time,
{ "gmt_unix_time", "ssl.handshake.random_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Unix time field of random structure", HFILL }
},
{ &hf_ssl_handshake_random_bytes,
{ "random_bytes", "ssl.handshake.random_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Random challenge used to authenticate server", HFILL }
},
{ &hf_ssl_handshake_cipher_suites_len,
{ "Cipher Suites Length", "ssl.handshake.cipher_suites_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of cipher suites field", HFILL }
},
{ &hf_ssl_handshake_cipher_suites,
{ "Cipher Suites", "ssl.handshake.ciphersuites",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of cipher suites supported by client", HFILL }
},
{ &hf_ssl_handshake_cipher_suite,
{ "Cipher Suite", "ssl.handshake.ciphersuite",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &ssl_31_ciphersuite_ext, 0x0,
NULL, HFILL }
},
{ &hf_ssl2_handshake_cipher_spec,
{ "Cipher Spec", "ssl.handshake.cipherspec",
FT_UINT24, BASE_HEX|BASE_EXT_STRING, &ssl_20_cipher_suites_ext, 0x0,
"Cipher specification", HFILL }
},
{ &hf_ssl_handshake_session_id,
{ "Session ID", "ssl.handshake.session_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Identifies the SSL session, allowing later resumption", HFILL }
},
{ &hf_ssl_handshake_comp_methods_len,
{ "Compression Methods Length", "ssl.handshake.comp_methods_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of compression methods field", HFILL }
},
{ &hf_ssl_handshake_comp_methods,
{ "Compression Methods", "ssl.handshake.comp_methods",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of compression methods supported by client", HFILL }
},
{ &hf_ssl_handshake_comp_method,
{ "Compression Method", "ssl.handshake.comp_method",
FT_UINT8, BASE_DEC, VALS(ssl_31_compression_method), 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_extensions_len,
{ "Extensions Length", "ssl.handshake.extensions_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of hello extensions", HFILL }
},
{ &hf_ssl_handshake_extension_type,
{ "Type", "ssl.handshake.extension.type",
FT_UINT16, BASE_HEX, VALS(tls_hello_extension_types), 0x0,
"Hello extension type", HFILL }
},
{ &hf_ssl_handshake_extension_len,
{ "Length", "ssl.handshake.extension.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of a hello extension", HFILL }
},
{ &hf_ssl_handshake_extension_data,
{ "Data", "ssl.handshake.extension.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Hello Extension data", HFILL }
},
{ &hf_ssl_handshake_extension_elliptic_curves_len,
{ "Elliptic Curves Length", "ssl.handshake.extensions_elliptic_curves_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of elliptic curves field", HFILL }
},
{ &hf_ssl_handshake_extension_elliptic_curves,
{ "Elliptic Curves List", "ssl.handshake.extensions_elliptic_curves",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of elliptic curves supported", HFILL }
},
{ &hf_ssl_handshake_extension_elliptic_curve,
{ "Elliptic curve", "ssl.handshake.extensions_elliptic_curve",
FT_UINT16, BASE_HEX, VALS(ssl_extension_curves), 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_extension_ec_point_formats_len,
{ "EC point formats Length", "ssl.handshake.extensions_ec_point_formats_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of elliptic curves point formats field", HFILL }
},
{ &hf_ssl_handshake_extension_ec_point_format,
{ "EC point format", "ssl.handshake.extensions_ec_point_format",
FT_UINT8, BASE_DEC, VALS(ssl_extension_ec_point_formats), 0x0,
"Elliptic curves point format", HFILL }
},
{ &hf_ssl_handshake_extension_npn_str_len,
{ "Protocol string length", "ssl.handshake.extensions_npn_str_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of next protocol string", HFILL }
},
{ &hf_ssl_handshake_extension_npn_str,
{ "Next Protocol", "ssl.handshake.extensions_npn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_extension_reneg_info_len,
{ "Renegotiation info extension length", "ssl.handshake.extensions_reneg_info_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_extension_server_name_list_len,
{ "Server Name list length", "ssl.handshake.extensions_server_name_list_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of server name list", HFILL }
},
{ &hf_ssl_handshake_extension_server_name_len,
{ "Server Name length", "ssl.handshake.extensions_server_name_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of server name string", HFILL }
},
{ &hf_ssl_handshake_extension_server_name_type,
{ "Server Name Type", "ssl.handshake.extensions_server_name_type",
FT_UINT8, BASE_DEC, VALS(tls_hello_ext_server_name_type_vs), 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_extension_server_name,
{ "Server Name", "ssl.handshake.extensions_server_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_session_ticket_lifetime_hint,
{ "Session Ticket Lifetime Hint", "ssl.handshake.session_ticket_lifetime_hint",
FT_UINT32, BASE_DEC, NULL, 0x0,
"New TLS Session Ticket Lifetime Hint", HFILL }
},
{ &hf_ssl_handshake_session_ticket_len,
{ "Session Ticket Length", "ssl.handshake.session_ticket_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"New TLS Session Ticket Length", HFILL }
},
{ &hf_ssl_handshake_session_ticket,
{ "Session Ticket", "ssl.handshake.session_ticket",
FT_BYTES, BASE_NONE, NULL, 0x0,
"New TLS Session Ticket", HFILL }
},
{ &hf_ssl_handshake_certificates_len,
{ "Certificates Length", "ssl.handshake.certificates_length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length of certificates field", HFILL }
},
{ &hf_ssl_handshake_certificates,
{ "Certificates", "ssl.handshake.certificates",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of certificates", HFILL }
},
{ &hf_ssl_handshake_certificate,
{ "Certificate", "ssl.handshake.certificate",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_certificate_len,
{ "Certificate Length", "ssl.handshake.certificate_length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length of certificate", HFILL }
},
{ &hf_ssl_handshake_cert_types_count,
{ "Certificate types count", "ssl.handshake.cert_types_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Count of certificate types", HFILL }
},
{ &hf_ssl_handshake_cert_types,
{ "Certificate types", "ssl.handshake.cert_types",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of certificate types", HFILL }
},
{ &hf_ssl_handshake_cert_type,
{ "Certificate type", "ssl.handshake.cert_type",
FT_UINT8, BASE_DEC, VALS(ssl_31_client_certificate_type), 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_server_keyex_p_len,
{ "p Length", "ssl.handshake.p_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of p", HFILL }
},
{ &hf_ssl_handshake_server_keyex_g_len,
{ "g Length", "ssl.handshake.g_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of g", HFILL }
},
{ &hf_ssl_handshake_server_keyex_ys_len,
{ "Pubkey Length", "ssl.handshake.ys_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of server's Diffie-Hellman public key", HFILL }
},
{ &hf_ssl_handshake_client_keyex_yc_len,
{ "Pubkey Length", "ssl.handshake.yc_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of client's Diffie-Hellman public key", HFILL }
},
{ &hf_ssl_handshake_client_keyex_point_len,
{ "Pubkey Length", "ssl.handshake.client_point_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of client's EC Diffie-Hellman public key", HFILL }
},
{ &hf_ssl_handshake_server_keyex_point_len,
{ "Pubkey Length", "ssl.handshake.server_point_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of server's EC Diffie-Hellman public key", HFILL }
},
{ &hf_ssl_handshake_client_keyex_epms_len,
{ "Encrypted PreMaster length", "ssl.handshake.epms_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of encrypted PreMaster secret", HFILL }
},
{ &hf_ssl_handshake_client_keyex_epms,
{ "Encrypted PreMaster", "ssl.handshake.epms",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Encrypted PreMaster secret", HFILL }
},
{ &hf_ssl_handshake_server_keyex_modulus_len,
{ "modulus Length", "ssl.handshake.modulus_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of RSA-EXPORT modulus", HFILL }
},
{ &hf_ssl_handshake_server_keyex_exponent_len,
{ "exponent Length", "ssl.handshake.exponent_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of RSA-EXPORT exponent", HFILL }
},
{ &hf_ssl_handshake_server_keyex_sig_len,
{ "Signature Length", "ssl.handshake.sig_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of Signature", HFILL }
},
{ &hf_ssl_handshake_server_keyex_p,
{ "p", "ssl.handshake.p",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Diffie-Hellman p", HFILL }
},
{ &hf_ssl_handshake_server_keyex_g,
{ "g", "ssl.handshake.g",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Diffie-Hellman g", HFILL }
},
{ &hf_ssl_handshake_server_keyex_curve_type,
{ "curve_type", "ssl.handshake.server_curve_type",
FT_UINT8, BASE_HEX, VALS(ssl_curve_types), 0x0,
"Server curve_type", HFILL }
},
{ &hf_ssl_handshake_server_keyex_named_curve,
{ "named_curve", "ssl.handshake.server_named_curve",
FT_UINT16, BASE_HEX, VALS(ssl_extension_curves), 0x0,
"Server named_curve", HFILL }
},
{ &hf_ssl_handshake_server_keyex_ys,
{ "pubkey", "ssl.handshake.ys",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Diffie-Hellman server pubkey", HFILL }
},
{ &hf_ssl_handshake_client_keyex_yc,
{ "pubkey", "ssl.handshake.yc",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Diffie-Hellman client pubkey", HFILL }
},
{ &hf_ssl_handshake_server_keyex_point,
{ "pubkey", "ssl.handshake.server_point",
FT_BYTES, BASE_NONE, NULL, 0x0,
"EC Diffie-Hellman server pubkey", HFILL }
},
{ &hf_ssl_handshake_client_keyex_point,
{ "pubkey", "ssl.handshake.client_point",
FT_BYTES, BASE_NONE, NULL, 0x0,
"EC Diffie-Hellman client pubkey", HFILL }
},
{ &hf_ssl_handshake_server_keyex_modulus,
{ "modulus", "ssl.handshake.modulus",
FT_BYTES, BASE_NONE, NULL, 0x0,
"RSA-EXPORT modulus", HFILL }
},
{ &hf_ssl_handshake_server_keyex_exponent,
{ "exponent", "ssl.handshake.exponent",
FT_BYTES, BASE_NONE, NULL, 0x0,
"RSA-EXPORT exponent", HFILL }
},
{ &hf_ssl_handshake_server_keyex_sig,
{ "signature", "ssl.handshake.sig",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Diffie-Hellman server signature", HFILL }
},
{ &hf_ssl_handshake_sig_hash_alg_len,
{ "Signature Hash Algorithms Length", "ssl.handshake.sig_hash_alg_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of Signature Hash Algorithms", HFILL }
},
{ &hf_ssl_handshake_sig_hash_algs,
{ "Signature Hash Algorithms", "ssl.handshake.sig_hash_algs",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of Signature Hash Algorithms", HFILL }
},
{ &hf_ssl_handshake_sig_hash_alg,
{ "Signature Hash Algorithm", "ssl.handshake.sig_hash_alg",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_sig_hash_hash,
{ "Signature Hash Algorithm Hash", "ssl.handshake.sig_hash_hash",
FT_UINT8, BASE_DEC, VALS(tls_hash_algorithm), 0x0,
NULL, HFILL }
},
{ &hf_ssl_handshake_sig_hash_sig,
{ "Signature Hash Algorithm Signature", "ssl.handshake.sig_hash_sig",
FT_UINT8, BASE_DEC, VALS(tls_signature_algorithm), 0x0,
NULL, HFILL }
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
{ &hf_ssl_handshake_finished,
{ "Verify Data", "ssl.handshake.verify_data",
FT_NONE, BASE_NONE, NULL, 0x0,
"Opaque verification data", HFILL }
},
{ &hf_ssl_handshake_md5_hash,
{ "MD5 Hash", "ssl.handshake.md5_hash",
FT_NONE, BASE_NONE, NULL, 0x0,
"Hash of messages, master_secret, etc.", HFILL }
},
{ &hf_ssl_handshake_sha_hash,
{ "SHA-1 Hash", "ssl.handshake.sha_hash",
FT_NONE, BASE_NONE, NULL, 0x0,
"Hash of messages, master_secret, etc.", HFILL }
},
{ &hf_ssl_handshake_session_id_len,
{ "Session ID Length", "ssl.handshake.session_id_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of session ID field", HFILL }
},
{ &hf_ssl_handshake_dnames_len,
{ "Distinguished Names Length", "ssl.handshake.dnames_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of list of CAs that server trusts", HFILL }
},
{ &hf_ssl_handshake_dnames,
{ "Distinguished Names", "ssl.handshake.dnames",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of CAs that server trusts", HFILL }
},
{ &hf_ssl_handshake_dname_len,
{ "Distinguished Name Length", "ssl.handshake.dname_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of distinguished name", HFILL }
},
{ &hf_ssl_handshake_dname,
{ "Distinguished Name", "ssl.handshake.dname",
FT_NONE, BASE_NONE, NULL, 0x0,
"Distinguished name of a CA that server trusts", HFILL }
},
{ &hf_ssl_heartbeat_extension_mode,
{ "Mode", "ssl.handshake.extension.heartbeat.mode",
FT_UINT8, BASE_DEC, VALS(tls_heartbeat_mode), 0x0,
"Heartbeat extension mode", HFILL }
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
{ SSL_SEGMENT_DATA_TEXT, "ssl.segment.data",
FT_BYTES, BASE_NONE, NULL, 0x00,
"The payload of a single SSL segment", HFILL }},
};
static gint *ett[] = {
&ett_ssl,
&ett_ssl_record,
&ett_ssl_alert,
&ett_ssl_handshake,
&ett_ssl_heartbeat,
&ett_ssl_cipher_suites,
&ett_ssl_comp_methods,
&ett_ssl_extension,
&ett_ssl_extension_curves,
&ett_ssl_extension_curves_point_formats,
&ett_ssl_extension_npn,
&ett_ssl_extension_reneg_info,
&ett_ssl_extension_server_name,
&ett_ssl_certs,
&ett_ssl_cert_types,
&ett_ssl_sig_hash_algs,
&ett_ssl_sig_hash_alg,
&ett_ssl_dnames,
&ett_ssl_random,
&ett_ssl_new_ses_ticket,
&ett_ssl_keyex_params,
&ett_ssl_cert_status,
&ett_ssl_ocsp_resp,
&ett_pct_cipher_suites,
&ett_pct_hash_suites,
&ett_pct_cert_suites,
&ett_pct_exch_suites,
&ett_ssl_segments,
&ett_ssl_segment
};
proto_ssl = proto_register_protocol("Secure Sockets Layer",
"SSL", "ssl");
proto_register_field_array(proto_ssl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
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
(void**) &sslkeylist_uats,
&nssldecrypt,
UAT_AFFECTS_DISSECTION,
NULL,
ssldecrypt_copy_cb,
ssldecrypt_update_cb,
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
prefs_register_string_preference(ssl_module, "psk", "Pre-Shared-Key",
"Pre-Shared-Key as HEX string, should be 0 to 16 bytes",
&ssl_psk);
prefs_register_filename_preference(ssl_module, "keylog_file", "(Pre)-Master-Secret log filename",
"The filename of a file which contains a list of \n"
"(pre-)master secrets in one of the following formats:\n"
"\n"
"RSA <EPMS> <PMS>\n"
"RSA Session-ID:<SSLID> Master-Key:<MS>\n"
"\n"
"Where:\n"
"<EPMS> = First 8 bytes of the Encrypted PMS\n"
"<PMS> = The Pre-Master-Secret (PMS)\n"
"<SSLID> = The SSL Session ID\n"
"<MS> = The Master-Secret (MS)\n"
"\n"
"(All fields are in hex notation)",
&ssl_keylog_filename);
#endif
}
register_heur_dissector_list("ssl", &ssl_heur_subdissector_list);
register_dissector("ssl", dissect_ssl, proto_ssl);
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
