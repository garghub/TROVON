static void
dtls_init(void)
{
module_t *dtls_module = prefs_find_module("dtls");
pref_t *keys_list_pref;
ssl_common_init(&dtls_master_key_map, &dtls_keylog_file,
&dtls_decrypted_data, &dtls_compressed_data);
reassembly_table_init (&dtls_reassembly_table, &addresses_reassembly_table_functions);
if (dtls_module) {
keys_list_pref = prefs_find_preference(dtls_module, "keys_list");
if (! prefs_get_preference_obsolete(keys_list_pref)) {
prefs_set_preference_obsolete(keys_list_pref);
}
}
}
static void
dtls_parse_uat(void)
{
wmem_stack_t *tmp_stack;
guint i;
if (dtls_key_hash)
{
g_hash_table_foreach(dtls_key_hash, ssl_private_key_free, NULL);
g_hash_table_destroy(dtls_key_hash);
}
tmp_stack = wmem_stack_new(NULL);
g_tree_foreach(dtls_associations, ssl_assoc_from_key_list, tmp_stack);
while (wmem_stack_count(tmp_stack) > 0) {
ssl_association_remove(dtls_associations, (SslAssociation *)wmem_stack_pop(tmp_stack));
}
wmem_destroy_stack(tmp_stack);
dtls_key_hash = g_hash_table_new(ssl_private_key_hash, ssl_private_key_equal);
ssl_set_debug(dtls_debug_file_name);
if (ndtlsdecrypt > 0)
{
for (i = 0; i < ndtlsdecrypt; i++)
{
ssldecrypt_assoc_t *d = &(dtlskeylist_uats[i]);
ssl_parse_key_list(d, dtls_key_hash, dtls_associations, dtls_handle, FALSE);
}
}
dissector_add_for_decode_as("sctp.port", dtls_handle);
dissector_add_for_decode_as("udp.port", dtls_handle);
}
static void
dtls_parse_old_keys(void)
{
gchar **old_keys, **parts, *err;
guint i;
gchar *uat_entry;
if (dtlsdecrypt_uat && dtls_keys_list && dtls_keys_list[0]) {
old_keys = ep_strsplit(dtls_keys_list, ";", 0);
for (i = 0; old_keys[i] != NULL; i++) {
parts = ep_strsplit(old_keys[i], ",", 4);
if (parts[0] && parts[1] && parts[2] && parts[3]) {
uat_entry = ep_strdup_printf("\"%s\",\"%s\",\"%s\",\"%s\",\"\"",
parts[0], parts[1], parts[2], parts[3]);
if (!uat_load_str(dtlsdecrypt_uat, uat_entry, &err)) {
ssl_debug_printf("dtls_parse: Can't load UAT string %s: %s\n",
uat_entry, err);
}
}
}
}
}
static void
dissect_dtls(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
conversation_t *conversation;
void *conv_data;
proto_item *ti;
proto_tree *dtls_tree;
guint32 offset;
gboolean first_record_in_frame;
SslDecryptSession *ssl_session;
SslSession *session;
gint is_from_server;
Ssl_private_key_t *private_key;
ti = NULL;
dtls_tree = NULL;
offset = 0;
first_record_in_frame = TRUE;
ssl_session = NULL;
top_tree = tree;
conversation = find_or_create_conversation(pinfo);
conv_data = conversation_get_proto_data(conversation, proto_dtls);
if (conv_data != NULL)
ssl_session = (SslDecryptSession *)conv_data;
else {
SslService dummy;
ssl_session = wmem_new0(wmem_file_scope(), SslDecryptSession);
ssl_session_init(ssl_session);
ssl_session->session.version = SSL_VER_UNKNOWN;
conversation_add_proto_data(conversation, proto_dtls, ssl_session);
if (ssl_packet_from_server(ssl_session, dtls_associations, pinfo)) {
dummy.addr = pinfo->src;
dummy.port = pinfo->srcport;
}
else {
dummy.addr = pinfo->dst;
dummy.port = pinfo->destport;
}
ssl_debug_printf("dissect_dtls server %s:%d\n",
address_to_str(wmem_packet_scope(), &dummy.addr),dummy.port);
private_key = (Ssl_private_key_t *)g_hash_table_lookup(dtls_key_hash, &dummy);
if (!private_key) {
ssl_debug_printf("dissect_dtls can't find private key for this server!\n");
}
else {
ssl_session->private_key = private_key->sexp_pkey;
}
}
session = &ssl_session->session;
is_from_server = ssl_packet_from_server(ssl_session, dtls_associations, pinfo);
if (pinfo->fd->flags.visited)
ssl_session = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DTLS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_dtls, tvb, 0, -1, ENC_NA);
dtls_tree = proto_item_add_subtree(ti, ett_dtls);
while (tvb_reported_length_remaining(tvb, offset) != 0)
{
if (!first_record_in_frame)
{
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
switch(session->version) {
case SSL_VER_DTLS:
case SSL_VER_DTLS_OPENSSL:
offset = dissect_dtls_record(tvb, pinfo, dtls_tree,
offset, session, is_from_server,
ssl_session);
break;
case SSL_VER_DTLS1DOT2:
offset = dissect_dtls_record(tvb, pinfo, dtls_tree,
offset, session, is_from_server,
ssl_session);
break;
default:
if (looks_like_dtls(tvb, offset))
{
offset = dissect_dtls_record(tvb, pinfo, dtls_tree,
offset, session, is_from_server,
ssl_session);
}
else
{
offset = tvb_reported_length(tvb);
col_append_str(pinfo->cinfo, COL_INFO,
"Continuation Data");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DTLS");
}
break;
}
first_record_in_frame = FALSE;
}
tap_queue_packet(dtls_tap, pinfo, NULL);
}
static gboolean
dissect_dtls_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint length = tvb_captured_length(tvb);
guint offset = 0;
if (tvb_reported_length(tvb) == length) {
while (offset + 13 <= length && looks_like_dtls(tvb, offset)) {
offset += tvb_get_ntohs(tvb, offset + 11) + 13;
if (offset == length) {
dissect_dtls(tvb, pinfo, tree);
return TRUE;
}
}
if (pinfo->fragmented && offset >= 13) {
dissect_dtls(tvb, pinfo, tree);
return TRUE;
}
return FALSE;
}
while (tvb_captured_length_remaining(tvb, offset) >= 3) {
if (!looks_like_dtls(tvb, offset))
return FALSE;
offset += 3;
if (tvb_captured_length_remaining(tvb, offset) >= 10 ) {
offset += tvb_get_ntohs(tvb, offset + 8) + 10;
} else {
dissect_dtls(tvb, pinfo, tree);
return TRUE;
}
if (offset == length) {
dissect_dtls(tvb, pinfo, tree);
return TRUE;
}
}
if ((length >= 3) && (offset <= tvb_reported_length(tvb) || pinfo->fragmented)) {
dissect_dtls(tvb, pinfo, tree);
return TRUE;
}
return FALSE;
}
static gboolean
dtls_is_null_cipher(guint cipher )
{
switch(cipher) {
case 0x0000:
case 0x0001:
case 0x0002:
case 0x002c:
case 0x002d:
case 0x002e:
case 0x003b:
case 0x00b0:
case 0x00b1:
case 0x00b4:
case 0x00b5:
case 0x00b8:
case 0x00b9:
case 0xc001:
case 0xc006:
case 0xc00b:
case 0xc010:
case 0xc015:
case 0xc039:
case 0xc03a:
case 0xc03b:
return TRUE;
default:
return FALSE;
}
}
static gint
decrypt_dtls_record(tvbuff_t *tvb, packet_info *pinfo, guint32 offset,
guint32 record_length, guint8 content_type, SslDecryptSession* ssl,
gboolean save_plaintext)
{
gint ret;
SslDecoder *decoder;
ret = 0;
if (!ssl || (!save_plaintext && !(ssl->state & SSL_HAVE_SESSION_KEY))) {
ssl_debug_printf("decrypt_dtls_record: no session key\n");
return ret;
}
ssl_debug_printf("decrypt_dtls_record: app_data len %d, ssl state %X\n",
record_length, ssl->state);
if (ssl_packet_from_server(ssl, dtls_associations, pinfo) != 0) {
ssl_debug_printf("decrypt_dtls_record: using server decoder\n");
decoder = ssl->server;
}
else {
ssl_debug_printf("decrypt_dtls_record: using client decoder\n");
decoder = ssl->client;
}
if (!decoder && !dtls_is_null_cipher(ssl->session.cipher)) {
ssl_debug_printf("decrypt_dtls_record: no decoder available\n");
return ret;
}
if (record_length > dtls_decrypted_data.data_len)
{
ssl_debug_printf("decrypt_dtls_record: allocating %d bytes"
" for decrypt data (old len %d)\n",
record_length + 32, dtls_decrypted_data.data_len);
dtls_decrypted_data.data = (guchar *)g_realloc(dtls_decrypted_data.data,
record_length + 32);
dtls_decrypted_data.data_len = record_length + 32;
}
dtls_decrypted_data_avail = dtls_decrypted_data.data_len;
if (ssl->state & SSL_HAVE_SESSION_KEY) {
if (!decoder) {
ssl_debug_printf("decrypt_dtls_record: no decoder available\n");
return ret;
}
if (ssl_decrypt_record(ssl, decoder, content_type, tvb_get_ptr(tvb, offset, record_length), record_length,
&dtls_compressed_data, &dtls_decrypted_data, &dtls_decrypted_data_avail) == 0)
ret = 1;
}
else if (dtls_is_null_cipher(ssl->session.cipher)) {
memcpy(dtls_decrypted_data.data, tvb_get_ptr(tvb, offset, record_length), record_length);
dtls_decrypted_data_avail = dtls_decrypted_data.data_len = record_length;
ret = 1;
}
if (ret && save_plaintext) {
ssl_add_data_info(proto_dtls, pinfo, dtls_decrypted_data.data, dtls_decrypted_data_avail,
tvb_raw_offset(tvb)+offset, 0);
}
return ret;
}
static gint
dissect_dtls_record(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
SslSession *session, gint is_from_server,
SslDecryptSession* ssl)
{
guint32 record_length;
guint16 version;
guint16 epoch;
guint64 sequence_number;
guint8 content_type;
guint8 next_byte;
proto_tree *ti;
proto_tree *dtls_record_tree;
SslAssociation *association;
SslDataInfo *appl_data;
heur_dtbl_entry_t *hdtbl_entry;
content_type = tvb_get_guint8(tvb, offset);
version = tvb_get_ntohs(tvb, offset + 1);
epoch = tvb_get_ntohs(tvb, offset + 3);
sequence_number = tvb_get_ntoh48(tvb, offset + 5);
record_length = tvb_get_ntohs(tvb, offset + 11);
if(ssl){
if(ssl_packet_from_server(ssl, dtls_associations, pinfo)){
if (ssl->server) {
ssl->server->seq=(guint32)sequence_number;
ssl->server->epoch=epoch;
}
}
else{
if (ssl->client) {
ssl->client->seq=(guint32)sequence_number;
ssl->client->epoch=epoch;
}
}
}
if (!ssl_is_valid_content_type(content_type)) {
col_append_str(pinfo->cinfo, COL_INFO, "Continuation Data");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DTLS");
return offset + 13 + record_length;
}
ti = proto_tree_add_item(tree, hf_dtls_record, tvb,
offset, 13 + record_length, ENC_NA);
dtls_record_tree = proto_item_add_subtree(ti, ett_dtls_record);
proto_tree_add_item(dtls_record_tree, hf_dtls_record_content_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dtls_record_tree, hf_dtls_record_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_uint(dtls_record_tree, hf_dtls_record_epoch, tvb, offset, 2, epoch);
offset += 2;
proto_tree_add_uint64(dtls_record_tree, hf_dtls_record_sequence_number, tvb, offset, 6, sequence_number);
offset += 6;
proto_tree_add_uint(dtls_record_tree, hf_dtls_record_length, tvb,
offset, 2, record_length);
offset += 2;
next_byte = tvb_get_guint8(tvb, offset);
if (session->version == SSL_VER_UNKNOWN
&& dtls_is_authoritative_version_message(content_type, next_byte))
{
if (version == DTLSV1DOT0_VERSION ||
version == DTLSV1DOT0_VERSION_NOT ||
version == DTLSV1DOT2_VERSION)
{
if (version == DTLSV1DOT0_VERSION)
session->version = SSL_VER_DTLS;
if (version == DTLSV1DOT0_VERSION_NOT)
session->version = SSL_VER_DTLS_OPENSSL;
if (version == DTLSV1DOT2_VERSION)
session->version = SSL_VER_DTLS1DOT2;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
}
}
}
if (version == DTLSV1DOT0_VERSION)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(SSL_VER_DTLS, ssl_version_short_names, "SSL"));
}
else if (version == DTLSV1DOT0_VERSION_NOT)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(SSL_VER_DTLS_OPENSSL, ssl_version_short_names, "SSL"));
}
else if (version == DTLSV1DOT2_VERSION)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(SSL_VER_DTLS1DOT2, ssl_version_short_names, "SSL"));
}
else
{
col_set_str(pinfo->cinfo, COL_PROTOCOL,"DTLS");
}
ssl_debug_printf("dissect_dtls_record: content_type %d\n",content_type);
switch ((ContentType) content_type) {
case SSL_ID_CHG_CIPHER_SPEC:
col_append_str(pinfo->cinfo, COL_INFO, "Change Cipher Spec");
dissect_dtls_change_cipher_spec(tvb, dtls_record_tree,
offset, session, content_type);
if (ssl) {
ssl_load_keyfile(dtls_options.keylog_filename, &dtls_keylog_file,
&dtls_master_key_map);
ssl_finalize_decryption(ssl, &dtls_master_key_map);
ssl_change_cipher(ssl, ssl_packet_from_server(ssl, dtls_associations, pinfo));
}
break;
case SSL_ID_ALERT:
{
tvbuff_t* decrypted;
decrypted = 0;
if (ssl&&decrypt_dtls_record(tvb, pinfo, offset,
record_length, content_type, ssl, FALSE))
ssl_add_record_info(proto_dtls, pinfo, dtls_decrypted_data.data,
dtls_decrypted_data_avail, offset);
decrypted = ssl_get_record_info(tvb, proto_dtls, pinfo, offset);
if (decrypted) {
dissect_dtls_alert(decrypted, pinfo, dtls_record_tree, 0,
session);
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
} else {
dissect_dtls_alert(tvb, pinfo, dtls_record_tree, offset,
session);
}
break;
}
case SSL_ID_HANDSHAKE:
{
tvbuff_t* decrypted;
decrypted = 0;
if (ssl && decrypt_dtls_record(tvb, pinfo, offset,
record_length, content_type, ssl, FALSE))
ssl_add_record_info(proto_dtls, pinfo, dtls_decrypted_data.data,
dtls_decrypted_data_avail, offset);
decrypted = ssl_get_record_info(tvb, proto_dtls, pinfo, offset);
if (decrypted) {
dissect_dtls_handshake(decrypted, pinfo, dtls_record_tree, 0,
tvb_reported_length(decrypted), session, is_from_server,
ssl, content_type);
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
} else {
dissect_dtls_handshake(tvb, pinfo, dtls_record_tree, offset,
record_length, session, is_from_server, ssl,
content_type);
}
break;
}
case SSL_ID_APP_DATA:
if (ssl)
decrypt_dtls_record(tvb, pinfo, offset,
record_length, content_type, ssl, TRUE);
col_append_str(pinfo->cinfo, COL_INFO, "Application Data");
association = ssl_association_find(dtls_associations, pinfo->srcport, pinfo->ptype == PT_TCP);
association = association ? association : ssl_association_find(dtls_associations, pinfo->destport, pinfo->ptype == PT_TCP);
proto_item_set_text(dtls_record_tree,
"%s Record Layer: %s Protocol: %s",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"),
association?association->info:"Application Data");
appl_data = ssl_get_data_info(proto_dtls, pinfo, tvb_raw_offset(tvb)+offset);
if (appl_data && (appl_data->plain_data.data_len > 0))
{
tvbuff_t *next_tvb;
gboolean dissected;
ssl_debug_printf("dissect_dtls_record decrypted len %d\n",
appl_data->plain_data.data_len);
next_tvb = tvb_new_child_real_data(tvb,
appl_data->plain_data.data,
appl_data->plain_data.data_len,
appl_data->plain_data.data_len);
add_new_data_source(pinfo, next_tvb, "Decrypted DTLS data");
if (association && association->handle) {
ssl_debug_printf("dissect_dtls_record found association %p\n", (void *)association);
ssl_print_data("decrypted app data",appl_data->plain_data.data, appl_data->plain_data.data_len);
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
dissected = call_dissector_only(association->handle, next_tvb, pinfo, top_tree, NULL);
}
else {
dissected = dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, top_tree, &hdtbl_entry, NULL);
}
if (dissected)
break;
}
proto_tree_add_item(dtls_record_tree, hf_dtls_record_appdata, tvb,
offset, record_length, ENC_NA);
break;
case SSL_ID_HEARTBEAT:
{
tvbuff_t* decrypted;
if (ssl && decrypt_dtls_record(tvb, pinfo, offset,
record_length, content_type, ssl, FALSE))
ssl_add_record_info(proto_dtls, pinfo, dtls_decrypted_data.data,
dtls_decrypted_data_avail, offset);
decrypted = ssl_get_record_info(tvb, proto_dtls, pinfo, offset);
if (decrypted) {
dissect_dtls_heartbeat(decrypted, pinfo, dtls_record_tree, 0,
session, tvb_reported_length (decrypted), TRUE);
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
} else {
dissect_dtls_heartbeat(tvb, pinfo, dtls_record_tree, offset,
session, record_length, FALSE);
}
break;
}
}
offset += record_length;
return offset;
}
static void
dissect_dtls_change_cipher_spec(tvbuff_t *tvb,
proto_tree *tree, guint32 offset,
const SslSession *session, guint8 content_type)
{
if (tree)
{
proto_item_set_text(tree,
"%s Record Layer: %s Protocol: Change Cipher Spec",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"));
proto_tree_add_item(tree, hf_dtls_change_cipher_spec, tvb,
offset, 1, ENC_NA);
}
}
static void
dissect_dtls_alert(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
const SslSession *session)
{
proto_tree *ti;
proto_tree *ssl_alert_tree;
const gchar *level;
const gchar *desc;
guint8 byte;
ti = proto_tree_add_item(tree, hf_dtls_alert_message, tvb,
offset, 2, ENC_NA);
ssl_alert_tree = proto_item_add_subtree(ti, ett_dtls_alert);
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
proto_tree_add_item(ssl_alert_tree, hf_dtls_alert_message_level,
tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_alert_tree, hf_dtls_alert_message_description,
tvb, offset, 1, ENC_BIG_ENDIAN);
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
dissect_dtls_handshake(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
guint32 record_length, SslSession *session,
gint is_from_server,
SslDecryptSession* ssl, guint8 content_type)
{
proto_tree *ti, *length_item = NULL, *fragment_length_item = NULL;
proto_tree *ssl_hand_tree;
const gchar *msg_type_str;
guint8 msg_type;
guint32 length;
guint16 message_seq;
guint32 fragment_offset;
guint32 fragment_length;
gboolean first_iteration;
guint32 reassembled_length;
msg_type_str = NULL;
first_iteration = TRUE;
record_length += offset;
for (; offset < record_length; offset += fragment_length,
first_iteration = FALSE)
{
fragment_head *frag_msg = NULL;
tvbuff_t *new_tvb = NULL;
const gchar *frag_str = NULL;
gboolean fragmented;
ti = proto_tree_add_item(tree, hf_dtls_handshake_protocol, tvb, offset, -1, ENC_NA);
ssl_hand_tree = proto_item_add_subtree(ti, ett_dtls_handshake);
msg_type = tvb_get_guint8(tvb, offset);
fragment_length = tvb_get_ntoh24(tvb, offset + 9);
if (offset + fragment_length <= record_length)
msg_type_str = try_val_to_str(msg_type, ssl_31_handshake_type);
else
msg_type_str = NULL;
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
if (!msg_type_str)
return;
proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_type,
tvb, offset, 1, msg_type);
offset++;
length = tvb_get_ntoh24(tvb, offset);
length_item = proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_length,
tvb, offset, 3, length);
offset += 3;
message_seq = tvb_get_ntohs(tvb,offset);
proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_message_seq,
tvb, offset, 2, message_seq);
offset += 2;
fragment_offset = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_fragment_offset,
tvb, offset, 3, fragment_offset);
offset += 3;
fragment_length_item = proto_tree_add_uint(ssl_hand_tree,
hf_dtls_handshake_fragment_length,
tvb, offset, 3,
fragment_length);
offset += 3;
proto_item_set_len(ti, fragment_length + 12);
fragmented = FALSE;
if (fragment_length + fragment_offset > length)
{
if (fragment_offset == 0)
{
expert_add_info(pinfo, fragment_length_item, &ei_dtls_handshake_fragment_length_too_long);
}
else
{
fragmented = TRUE;
expert_add_info(pinfo, fragment_length_item, &ei_dtls_handshake_fragment_past_end_msg);
}
}
else if (fragment_length < length)
{
fragmented = TRUE;
if (ssl_is_valid_handshake_type(msg_type, TRUE))
{
pinfo->fragmented = TRUE;
tvb_ensure_bytes_exist(tvb, offset, fragment_length);
frag_msg = fragment_add(&dtls_reassembly_table,
tvb, offset, pinfo, message_seq, NULL,
fragment_offset, fragment_length, TRUE);
reassembled_length = fragment_get_tot_len(&dtls_reassembly_table,
pinfo, message_seq, NULL);
if (reassembled_length == 0)
{
fragment_set_tot_len(&dtls_reassembly_table,
pinfo, message_seq, NULL, length);
}
else
{
if (reassembled_length != length)
{
expert_add_info(pinfo, length_item, &ei_dtls_msg_len_diff_fragment);
}
}
if (frag_msg && (fragment_length + fragment_offset) == reassembled_length)
{
new_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled DTLS",
frag_msg,
&dtls_frag_items,
NULL, tree);
frag_str = " (Reassembled)";
}
else
{
frag_str = " (Fragment)";
}
col_append_str(pinfo->cinfo, COL_INFO, frag_str);
}
}
if (tree)
{
if (first_iteration)
{
proto_item_set_text(tree, "%s Record Layer: %s Protocol: %s%s",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"),
(msg_type_str!=NULL) ? msg_type_str :
"Encrypted Handshake Message",
(frag_str!=NULL) ? frag_str : "");
}
else
{
proto_item_set_text(tree, "%s Record Layer: %s Protocol: %s%s",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(content_type, ssl_31_content_type, "unknown"),
"Multiple Handshake Messages",
(frag_str!=NULL) ? frag_str : "");
}
if (ssl_hand_tree)
{
proto_item_set_text(ssl_hand_tree, "Handshake Protocol: %s%s",
(msg_type_str != NULL) ? msg_type_str :
"Encrypted Handshake Message",
(frag_str!=NULL) ? frag_str : "");
}
}
if (ssl_hand_tree || ssl)
{
tvbuff_t *sub_tvb = NULL;
if (fragmented && !new_tvb)
{
continue;
}
if (new_tvb)
{
sub_tvb = new_tvb;
}
else
{
sub_tvb = tvb_new_subset_length(tvb, offset, fragment_length);
}
switch ((HandshakeType) msg_type) {
case SSL_HND_HELLO_REQUEST:
break;
case SSL_HND_CLIENT_HELLO:
if (ssl) {
ssl_set_server(ssl, &pinfo->dst, pinfo->ptype, pinfo->destport);
ssl_find_private_key(ssl, dtls_key_hash, dtls_associations, pinfo);
}
ssl_dissect_hnd_cli_hello(&dissect_dtls_hf, sub_tvb, pinfo,
ssl_hand_tree, 0, length, session, ssl,
&dtls_hfs);
break;
case SSL_HND_SERVER_HELLO:
ssl_dissect_hnd_srv_hello(&dissect_dtls_hf, sub_tvb, ssl_hand_tree,
0, length, session, ssl);
break;
case SSL_HND_HELLO_VERIFY_REQUEST:
dissect_dtls_hnd_hello_verify_request(sub_tvb, ssl_hand_tree, 0, ssl);
break;
case SSL_HND_NEWSESSION_TICKET:
ssl_dissect_hnd_new_ses_ticket(&dissect_dtls_hf, sub_tvb,
ssl_hand_tree, 0, ssl,
dtls_master_key_map.session);
break;
case SSL_HND_CERTIFICATE:
ssl_dissect_hnd_cert(&dissect_dtls_hf, sub_tvb, ssl_hand_tree, 0, pinfo, session, is_from_server);
break;
case SSL_HND_SERVER_KEY_EXCHG:
ssl_dissect_hnd_srv_keyex(&dissect_dtls_hf, sub_tvb, ssl_hand_tree, 0, length, session);
break;
case SSL_HND_CERT_REQUEST:
ssl_dissect_hnd_cert_req(&dissect_dtls_hf, sub_tvb, ssl_hand_tree, 0, pinfo, session);
break;
case SSL_HND_SVR_HELLO_DONE:
break;
case SSL_HND_CERT_VERIFY:
break;
case SSL_HND_CLIENT_KEY_EXCHG:
ssl_dissect_hnd_cli_keyex(&dissect_dtls_hf, sub_tvb, ssl_hand_tree, 0, length, session);
if (!ssl)
break;
ssl_load_keyfile(dtls_options.keylog_filename, &dtls_keylog_file,
&dtls_master_key_map);
if (!ssl_generate_pre_master_secret(ssl, length, sub_tvb, 0,
dtls_options.psk,
&dtls_master_key_map)) {
ssl_debug_printf("dissect_dtls_handshake can't generate pre master secret\n");
}
break;
case SSL_HND_FINISHED:
ssl_dissect_hnd_finished(&dissect_dtls_hf, sub_tvb, ssl_hand_tree,
0, session, NULL);
break;
case SSL_HND_CERT_URL:
case SSL_HND_CERT_STATUS:
case SSL_HND_SUPPLEMENTAL_DATA:
case SSL_HND_ENCRYPTED_EXTS:
break;
}
}
}
}
static void
dissect_dtls_heartbeat(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
const SslSession *session, guint32 record_length,
gboolean decrypted)
{
proto_tree *ti;
proto_tree *dtls_heartbeat_tree;
const gchar *type;
guint8 byte;
guint16 payload_length;
guint16 padding_length;
ti = proto_tree_add_item(tree, hf_dtls_heartbeat_message, tvb,
offset, record_length - 32, ENC_NA);
dtls_heartbeat_tree = proto_item_add_subtree(ti, ett_dtls_heartbeat);
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
if (type && ((payload_length <= record_length - 16 - 3) || decrypted)) {
proto_item_set_text(tree, "%s Record Layer: Heartbeat "
"%s",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
type);
proto_tree_add_item(dtls_heartbeat_tree, hf_dtls_heartbeat_message_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_uint(dtls_heartbeat_tree, hf_dtls_heartbeat_message_payload_length,
tvb, offset, 2, payload_length);
offset += 2;
if (payload_length > record_length - 16 - 3) {
expert_add_info_format(pinfo, ti, &ei_dtls_heartbeat_payload_length,
"Invalid heartbeat payload length (%d)", payload_length);
payload_length = record_length - 16 - 3;
padding_length = 16;
proto_item_append_text (ti, " (invalid, using %u to decode payload)", payload_length);
}
proto_tree_add_bytes_format(dtls_heartbeat_tree, hf_dtls_heartbeat_message_payload,
tvb, offset, payload_length,
NULL, "Payload (%u byte%s)",
payload_length,
plurality(payload_length, "", "s"));
offset += payload_length;
proto_tree_add_bytes_format(dtls_heartbeat_tree, hf_dtls_heartbeat_message_padding,
tvb, offset, padding_length,
NULL, "Padding and HMAC (%u byte%s)",
padding_length,
plurality(padding_length, "", "s"));
} else {
proto_item_set_text(tree,
"%s Record Layer: Encrypted Heartbeat",
val_to_str_const(session->version, ssl_version_short_names, "SSL"));
proto_item_set_text(dtls_heartbeat_tree,
"Encrypted Heartbeat Message");
}
}
}
static int
dissect_dtls_hnd_hello_verify_request(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, SslDecryptSession* ssl _U_)
{
guint8 cookie_length;
proto_tree_add_item(tree, dissect_dtls_hf.hf.hs_server_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
cookie_length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, dtls_hfs.hf_dtls_handshake_cookie_len,
tvb, offset, 1, cookie_length);
offset ++;
if (cookie_length > 0)
{
proto_tree_add_bytes_format(tree, dtls_hfs.hf_dtls_handshake_cookie,
tvb, offset, cookie_length,
NULL, "Cookie (%u byte%s)",
cookie_length,
plurality(cookie_length, "", "s"));
offset += cookie_length;
}
return offset;
}
static gint
dtls_is_authoritative_version_message(guint8 content_type, guint8 next_byte)
{
if (content_type == SSL_ID_HANDSHAKE
&& ssl_is_valid_handshake_type(next_byte, TRUE))
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
looks_like_dtls(tvbuff_t *tvb, guint32 offset)
{
guint8 byte;
guint16 version;
byte = tvb_get_guint8(tvb, offset);
if (!ssl_is_valid_content_type(byte))
{
return 0;
}
version = tvb_get_ntohs(tvb, offset + 1);
if (version != DTLSV1DOT0_VERSION && version != DTLSV1DOT2_VERSION &&
version != DTLSV1DOT0_VERSION_NOT)
{
return 0;
}
return 1;
}
static void
dtlsdecrypt_free_cb(void* r)
{
ssldecrypt_assoc_t* h = (ssldecrypt_assoc_t*)r;
g_free(h->ipaddr);
g_free(h->port);
g_free(h->protocol);
g_free(h->keyfile);
g_free(h->password);
}
static void *
dtlsdecrypt_copy_cb(void* dest, const void* orig, size_t len _U_)
{
const ssldecrypt_assoc_t* o = (const ssldecrypt_assoc_t*)orig;
ssldecrypt_assoc_t* d = (ssldecrypt_assoc_t*)dest;
d->ipaddr = g_strdup(o->ipaddr);
d->port = g_strdup(o->port);
d->protocol = g_strdup(o->protocol);
d->keyfile = g_strdup(o->keyfile);
d->password = g_strdup(o->password);
return d;
}
void
proto_register_dtls(void)
{
static hf_register_info hf[] = {
{ &hf_dtls_record,
{ "Record Layer", "dtls.record",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dtls_record_content_type,
{ "Content Type", "dtls.record.content_type",
FT_UINT8, BASE_DEC, VALS(ssl_31_content_type), 0x0,
NULL, HFILL}
},
{ &hf_dtls_record_version,
{ "Version", "dtls.record.version",
FT_UINT16, BASE_HEX, VALS(ssl_versions), 0x0,
"Record layer version.", HFILL }
},
{ &hf_dtls_record_epoch,
{ "Epoch", "dtls.record.epoch",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dtls_record_sequence_number,
{ "Sequence Number", "dtls.record.sequence_number",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dtls_record_length,
{ "Length", "dtls.record.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of DTLS record data", HFILL }
},
{ &hf_dtls_record_appdata,
{ "Encrypted Application Data", "dtls.app_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Payload is encrypted application data", HFILL }
},
{ &hf_dtls_change_cipher_spec,
{ "Change Cipher Spec Message", "dtls.change_cipher_spec",
FT_NONE, BASE_NONE, NULL, 0x0,
"Signals a change in cipher specifications", HFILL }
},
{ & hf_dtls_alert_message,
{ "Alert Message", "dtls.alert_message",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ & hf_dtls_alert_message_level,
{ "Level", "dtls.alert_message.level",
FT_UINT8, BASE_DEC, VALS(ssl_31_alert_level), 0x0,
"Alert message level", HFILL }
},
{ &hf_dtls_alert_message_description,
{ "Description", "dtls.alert_message.desc",
FT_UINT8, BASE_DEC, VALS(ssl_31_alert_description), 0x0,
"Alert message description", HFILL }
},
{ &hf_dtls_handshake_protocol,
{ "Handshake Protocol", "dtls.handshake",
FT_NONE, BASE_NONE, NULL, 0x0,
"Handshake protocol message", HFILL}
},
{ &hf_dtls_handshake_type,
{ "Handshake Type", "dtls.handshake.type",
FT_UINT8, BASE_DEC, VALS(ssl_31_handshake_type), 0x0,
"Type of handshake message", HFILL}
},
{ &hf_dtls_handshake_length,
{ "Length", "dtls.handshake.length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length of handshake message", HFILL }
},
{ &hf_dtls_handshake_message_seq,
{ "Message Sequence", "dtls.handshake.message_seq",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Message sequence of handshake message", HFILL }
},
{ &hf_dtls_handshake_fragment_offset,
{ "Fragment Offset", "dtls.handshake.fragment_offset",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Fragment offset of handshake message", HFILL }
},
{ &hf_dtls_handshake_fragment_length,
{ "Fragment Length", "dtls.handshake.fragment_length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Fragment length of handshake message", HFILL }
},
{ &dtls_hfs.hf_dtls_handshake_cookie_len,
{ "Cookie Length", "dtls.handshake.cookie_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of the cookie field", HFILL }
},
{ &dtls_hfs.hf_dtls_handshake_cookie,
{ "Cookie", "dtls.handshake.cookie",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dtls_heartbeat_message,
{ "Heartbeat Message", "dtls.heartbeat_message",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dtls_heartbeat_message_type,
{ "Type", "dtls.heartbeat_message.type",
FT_UINT8, BASE_DEC, VALS(tls_heartbeat_type), 0x0,
"Heartbeat message type", HFILL }
},
{ &hf_dtls_heartbeat_message_payload_length,
{ "Payload Length", "dtls.heartbeat_message.payload_length",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_dtls_heartbeat_message_payload,
{ "Payload Length", "dtls.heartbeat_message.payload",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dtls_heartbeat_message_padding,
{ "Payload Length", "dtls.heartbeat_message.padding",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dtls_fragments,
{ "Message fragments", "dtls.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dtls_fragment,
{ "Message fragment", "dtls.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dtls_fragment_overlap,
{ "Message fragment overlap", "dtls.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_dtls_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data",
"dtls.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_dtls_fragment_multiple_tails,
{ "Message has multiple tail fragments",
"dtls.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_dtls_fragment_too_long_fragment,
{ "Message fragment too long", "dtls.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_dtls_fragment_error,
{ "Message defragmentation error", "dtls.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dtls_fragment_count,
{ "Message fragment count", "dtls.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
{ &hf_dtls_reassembled_in,
{ "Reassembled in", "dtls.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }
},
{ &hf_dtls_reassembled_length,
{ "Reassembled DTLS length", "dtls.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }
},
SSL_COMMON_HF_LIST(dissect_dtls_hf, "dtls")
};
static gint *ett[] = {
&ett_dtls,
&ett_dtls_record,
&ett_dtls_alert,
&ett_dtls_handshake,
&ett_dtls_heartbeat,
&ett_dtls_certs,
&ett_dtls_fragment,
&ett_dtls_fragments,
SSL_COMMON_ETT_LIST(dissect_dtls_hf)
};
static ei_register_info ei[] = {
{ &ei_dtls_handshake_fragment_length_too_long, { "dtls.handshake.fragment_length.too_long", PI_PROTOCOL, PI_ERROR, "Fragment length is larger than message length", EXPFILL }},
{ &ei_dtls_handshake_fragment_past_end_msg, { "dtls.handshake.fragment_past_end_msg", PI_PROTOCOL, PI_ERROR, "Fragment runs past the end of the message", EXPFILL }},
{ &ei_dtls_msg_len_diff_fragment, { "dtls.msg_len_diff_fragment", PI_PROTOCOL, PI_ERROR, "Message length differs from value in earlier fragment", EXPFILL }},
{ &ei_dtls_heartbeat_payload_length, {"dtls.heartbeat_message.payload_length.invalid", PI_MALFORMED, PI_ERROR, "Invalid heartbeat payload length", EXPFILL }},
SSL_COMMON_EI_LIST(dissect_dtls_hf, "dtls")
};
expert_module_t* expert_dtls;
proto_dtls = proto_register_protocol("Datagram Transport Layer Security",
"DTLS", "dtls");
proto_register_field_array(proto_dtls, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dtls = expert_register_protocol(proto_dtls);
expert_register_field_array(expert_dtls, ei, array_length(ei));
#ifdef HAVE_LIBGNUTLS
{
module_t *dtls_module = prefs_register_protocol(proto_dtls, proto_reg_handoff_dtls);
static uat_field_t dtlskeylist_uats_flds[] = {
UAT_FLD_CSTRING_OTHER(sslkeylist_uats, ipaddr, "IP address", ssldecrypt_uat_fld_ip_chk_cb, "IPv4 or IPv6 address"),
UAT_FLD_CSTRING_OTHER(sslkeylist_uats, port, "Port", ssldecrypt_uat_fld_port_chk_cb, "Port Number"),
UAT_FLD_CSTRING_OTHER(sslkeylist_uats, protocol, "Protocol", ssldecrypt_uat_fld_protocol_chk_cb, "Protocol"),
UAT_FLD_FILENAME_OTHER(sslkeylist_uats, keyfile, "Key File", ssldecrypt_uat_fld_fileopen_chk_cb, "Path to the keyfile."),
UAT_FLD_CSTRING_OTHER(sslkeylist_uats, password," Password (p12 file)", ssldecrypt_uat_fld_password_chk_cb, "Password"),
UAT_END_FIELDS
};
dtlsdecrypt_uat = uat_new("DTLS RSA Keylist",
sizeof(ssldecrypt_assoc_t),
"dtlsdecrypttablefile",
TRUE,
&dtlskeylist_uats,
&ndtlsdecrypt,
UAT_AFFECTS_DISSECTION,
"ChK12ProtocolsSection",
dtlsdecrypt_copy_cb,
NULL,
dtlsdecrypt_free_cb,
dtls_parse_uat,
dtlskeylist_uats_flds);
prefs_register_uat_preference(dtls_module, "cfg",
"RSA keys list",
"A table of RSA keys for DTLS decryption",
dtlsdecrypt_uat);
prefs_register_filename_preference(dtls_module, "debug_file", "DTLS debug file",
"redirect dtls debug to file name; leave empty to disable debug, "
"use \"" SSL_DEBUG_USE_STDERR "\" to redirect output to stderr\n",
&dtls_debug_file_name);
prefs_register_string_preference(dtls_module, "keys_list", "RSA keys list (deprecated)",
"Semicolon-separated list of private RSA keys used for DTLS decryption. "
"Used by versions of Wireshark prior to 1.6",
&dtls_keys_list);
ssl_common_register_options(dtls_module, &dtls_options);
}
#endif
register_dissector("dtls", dissect_dtls, proto_dtls);
dtls_handle = find_dissector("dtls");
dtls_associations = g_tree_new(ssl_association_cmp);
register_init_routine(dtls_init);
ssl_lib_init();
dtls_tap = register_tap("dtls");
ssl_debug_printf("proto_register_dtls: registered tap %s:%d\n",
"dtls", dtls_tap);
register_heur_dissector_list("dtls", &heur_subdissector_list);
}
void
proto_reg_handoff_dtls(void)
{
static gboolean initialized = FALSE;
dtls_parse_uat();
dtls_parse_old_keys();
exported_pdu_tap = find_tap_id(EXPORT_PDU_TAP_NAME_LAYER_7);
if (initialized == FALSE) {
heur_dissector_add("udp", dissect_dtls_heur, proto_dtls);
dissector_add_uint("sctp.ppi", DIAMETER_DTLS_PROTOCOL_ID, find_dissector("dtls"));
}
initialized = TRUE;
}
