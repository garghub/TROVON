static void
dtls_init(void)
{
module_t *dtls_module = prefs_find_module("dtls");
pref_t *keys_list_pref;
ssl_common_init(&dtls_session_hash, &dtls_decrypted_data, &dtls_compressed_data);
fragment_table_init (&dtls_fragment_table);
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
ep_stack_t tmp_stack;
SslAssociation *tmp_assoc;
guint i;
if (dtls_key_hash)
{
g_hash_table_foreach(dtls_key_hash, ssl_private_key_free, NULL);
g_hash_table_destroy(dtls_key_hash);
}
tmp_stack = ep_stack_new();
g_tree_foreach(dtls_associations, ssl_assoc_from_key_list, tmp_stack);
while ((tmp_assoc = ep_stack_pop(tmp_stack)) != NULL) {
ssl_association_remove(dtls_associations, tmp_assoc);
}
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
dissector_add_handle("sctp.port", dtls_handle);
dissector_add_handle("udp.port", dtls_handle);
}
static void
dtls_parse_old_keys(void)
{
gchar **old_keys, **parts, *err;
guint i;
GString *uat_entry = g_string_new("");
if (dtlsdecrypt_uat && dtls_keys_list && dtls_keys_list[0]) {
old_keys = g_strsplit(dtls_keys_list, ";", 0);
for (i = 0; old_keys[i] != NULL; i++) {
parts = g_strsplit(old_keys[i], ",", 4);
if (parts[0] && parts[1] && parts[2] && parts[3]) {
g_string_printf(uat_entry, "\"%s\",\"%s\",\"%s\",\"%s\",\"\"",
parts[0], parts[1], parts[2], parts[3]);
if (!uat_load_str(dtlsdecrypt_uat, uat_entry->str, &err)) {
ssl_debug_printf("dtls_parse: Can't load UAT string %s: %s\n",
uat_entry->str, err);
}
}
g_strfreev(parts);
}
g_strfreev(old_keys);
}
g_string_free(uat_entry, TRUE);
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
guint* conv_version;
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
ssl_session = conv_data;
else {
SslService dummy;
ssl_session = se_alloc0(sizeof(SslDecryptSession));
ssl_session_init(ssl_session);
ssl_session->version = SSL_VER_UNKNOWN;
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
ep_address_to_str(&dummy.addr),dummy.port);
private_key = g_hash_table_lookup(dtls_key_hash, &dummy);
if (!private_key) {
ssl_debug_printf("dissect_dtls can't find private key for this server!\n");
}
else {
ssl_session->private_key = private_key->sexp_pkey;
}
}
conv_version= & ssl_session->version;
if (pinfo->fd->flags.visited)
ssl_session = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DTLS");
col_clear(pinfo->cinfo, COL_INFO);
if (tree)
{
ti = proto_tree_add_item(tree, proto_dtls, tvb, 0, -1, ENC_NA);
dtls_tree = proto_item_add_subtree(ti, ett_dtls);
}
while (tvb_reported_length_remaining(tvb, offset) != 0)
{
if (!first_record_in_frame)
{
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
switch(*conv_version) {
case SSL_VER_DTLS:
offset = dissect_dtls_record(tvb, pinfo, dtls_tree,
offset, conv_version,
ssl_session);
break;
case SSL_VER_DTLS1DOT2:
offset = dissect_dtls_record(tvb, pinfo, dtls_tree,
offset, conv_version,
ssl_session);
break;
default:
if (looks_like_dtls(tvb, offset))
{
offset = dissect_dtls_record(tvb, pinfo, dtls_tree,
offset, conv_version,
ssl_session);
}
else
{
offset = tvb_length(tvb);
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
dissect_dtls_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint length = tvb_length(tvb);
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
while (tvb_length_remaining(tvb, offset) >= 3) {
if (!looks_like_dtls(tvb, offset))
return FALSE;
offset += 3;
if (tvb_length_remaining(tvb, offset) >= 10 ) {
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
static gint
decrypt_dtls_record(tvbuff_t *tvb, packet_info *pinfo, guint32 offset,
guint32 record_length, guint8 content_type, SslDecryptSession* ssl,
gboolean save_plaintext)
{
gint ret;
SslDecoder *decoder;
ret = 0;
ssl_debug_printf("decrypt_dtls_record: app_data len %d, ssl state %X\n",
record_length, ssl->state);
if (!ssl || (!save_plaintext && !(ssl->state & SSL_HAVE_SESSION_KEY))) {
ssl_debug_printf("decrypt_dtls_record: no session key\n");
return ret;
}
if (ssl_packet_from_server(ssl, dtls_associations, pinfo) != 0) {
ssl_debug_printf("decrypt_dtls_record: using server decoder\n");
decoder = ssl->server;
}
else {
ssl_debug_printf("decrypt_dtls_record: using client decoder\n");
decoder = ssl->client;
}
if (!decoder && ssl->cipher != 0x0001 && ssl->cipher != 0x0002) {
ssl_debug_printf("decrypt_dtls_record: no decoder available\n");
return ret;
}
if (record_length > dtls_decrypted_data.data_len)
{
ssl_debug_printf("decrypt_dtls_record: allocating %d bytes"
" for decrypt data (old len %d)\n",
record_length + 32, dtls_decrypted_data.data_len);
dtls_decrypted_data.data = g_realloc(dtls_decrypted_data.data,
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
else if (ssl->cipher == 0x0001 || ssl->cipher == 0x0002) {
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
guint *conv_version,
SslDecryptSession* ssl)
{
guint32 record_length;
guint16 version;
guint16 epoch;
gdouble sequence_number;
gint64 sequence_number_temp;
guint8 content_type;
guint8 next_byte;
proto_tree *ti;
proto_tree *dtls_record_tree;
SslAssociation *association;
SslDataInfo *appl_data;
ti = NULL;
dtls_record_tree = NULL;
content_type = tvb_get_guint8(tvb, offset);
version = tvb_get_ntohs(tvb, offset + 1);
epoch = tvb_get_ntohs(tvb, offset + 3);
sequence_number = tvb_get_ntohl(tvb, offset + 7);
sequence_number_temp = tvb_get_ntohs(tvb, offset + 5);
sequence_number_temp = sequence_number_temp<<32;
sequence_number += sequence_number_temp;
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
if (tree)
{
tvb_ensure_bytes_exist(tvb, offset, 13 + record_length);
ti = proto_tree_add_item(tree, hf_dtls_record, tvb,
offset, 13 + record_length, ENC_NA);
dtls_record_tree = proto_item_add_subtree(ti, ett_dtls_record);
}
if (dtls_record_tree)
{
proto_tree_add_item(dtls_record_tree, hf_dtls_record_content_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(dtls_record_tree, hf_dtls_record_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_uint(dtls_record_tree, hf_dtls_record_epoch, tvb, offset, 2, epoch);
offset += 2;
proto_tree_add_double(dtls_record_tree, hf_dtls_record_sequence_number, tvb, offset, 6, sequence_number);
offset += 6;
proto_tree_add_uint(dtls_record_tree, hf_dtls_record_length, tvb,
offset, 2, record_length);
offset += 2;
}
else
{
offset += 13;
}
next_byte = tvb_get_guint8(tvb, offset);
if (*conv_version == SSL_VER_UNKNOWN
&& dtls_is_authoritative_version_message(content_type, next_byte))
{
if (version == DTLSV1DOT0_VERSION ||
version == DTLSV1DOT0_VERSION_NOT)
{
*conv_version = SSL_VER_DTLS;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
}
}
if (version == DTLSV1DOT2_VERSION)
{
*conv_version = SSL_VER_DTLS1DOT2;
if (ssl) {
ssl->version_netorder = version;
ssl->state |= SSL_VERSION;
}
}
}
if (check_col(pinfo->cinfo, COL_PROTOCOL))
{
if (version == DTLSV1DOT0_VERSION)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(SSL_VER_DTLS, ssl_version_short_names, "SSL"));
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
}
ssl_debug_printf("dissect_dtls_record: content_type %d\n",content_type);
switch (content_type) {
case SSL_ID_CHG_CIPHER_SPEC:
col_append_str(pinfo->cinfo, COL_INFO, "Change Cipher Spec");
dissect_dtls_change_cipher_spec(tvb, dtls_record_tree,
offset, conv_version, content_type);
if (ssl) ssl_change_cipher(ssl, ssl_packet_from_server(ssl, dtls_associations, pinfo));
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
conv_version);
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
} else {
dissect_dtls_alert(tvb, pinfo, dtls_record_tree, offset,
conv_version);
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
tvb_length(decrypted), conv_version, ssl, content_type);
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
} else {
dissect_dtls_handshake(tvb, pinfo, dtls_record_tree, offset,
record_length, conv_version, ssl, content_type);
}
break;
}
case SSL_ID_APP_DATA:
if (ssl)
decrypt_dtls_record(tvb, pinfo, offset,
record_length, content_type, ssl, TRUE);
col_append_str(pinfo->cinfo, COL_INFO, "Application Data");
if (!dtls_record_tree)
break;
association = ssl_association_find(dtls_associations, pinfo->srcport, pinfo->ptype == PT_TCP);
association = association ? association : ssl_association_find(dtls_associations, pinfo->destport, pinfo->ptype == PT_TCP);
proto_item_set_text(dtls_record_tree,
"%s Record Layer: %s Protocol: %s",
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
val_to_str(content_type, ssl_31_content_type, "unknown"),
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
ssl_print_text_data("decrypted app data",appl_data->plain_data.data, appl_data->plain_data.data_len);
dissected = call_dissector_only(association->handle, next_tvb, pinfo, top_tree);
}
else {
dissected = dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, top_tree);
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
conv_version, record_length);
add_new_data_source(pinfo, decrypted, "Decrypted SSL record");
} else {
dissect_dtls_heartbeat(tvb, pinfo, dtls_record_tree, offset,
conv_version, record_length);
}
break;
}
default:
col_append_str(pinfo->cinfo, COL_INFO, "Bad DTLS Content Type");
break;
}
offset += record_length;
return offset;
}
static void
dissect_dtls_change_cipher_spec(tvbuff_t *tvb,
proto_tree *tree, guint32 offset,
guint* conv_version, guint8 content_type)
{
if (tree)
{
proto_item_set_text(tree,
"%s Record Layer: %s Protocol: Change Cipher Spec",
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
val_to_str(content_type, ssl_31_content_type, "unknown"));
proto_tree_add_item(tree, hf_dtls_change_cipher_spec, tvb,
offset, 1, ENC_NA);
}
}
static void
dissect_dtls_alert(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
guint* conv_version)
{
proto_tree *ti;
proto_tree *ssl_alert_tree;
const gchar *level;
const gchar *desc;
guint8 byte;
ssl_alert_tree = NULL;
if (tree)
{
ti = proto_tree_add_item(tree, hf_dtls_alert_message, tvb,
offset, 2, ENC_NA);
ssl_alert_tree = proto_item_add_subtree(ti, ett_dtls_alert);
}
byte = tvb_get_guint8(tvb, offset);
level = match_strval(byte, ssl_31_alert_level);
byte = tvb_get_guint8(tvb, offset+1);
desc = match_strval(byte, ssl_31_alert_description);
if (level && desc)
{
if (check_col(pinfo->cinfo, COL_INFO))
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
proto_tree_add_item(ssl_alert_tree, hf_dtls_alert_message_level,
tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_alert_tree, hf_dtls_alert_message_description,
tvb, offset, 1, ENC_BIG_ENDIAN);
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
dissect_dtls_handshake(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
guint32 record_length, guint *conv_version,
SslDecryptSession* ssl, guint8 content_type)
{
proto_tree *ti;
proto_tree *ssl_hand_tree;
const gchar *msg_type_str;
guint8 msg_type;
guint32 length;
guint16 message_seq;
guint32 fragment_offset;
guint32 fragment_length;
gboolean first_iteration;
ti = NULL;
ssl_hand_tree = NULL;
msg_type_str = NULL;
first_iteration = TRUE;
record_length += offset;
for (; offset < record_length; offset += fragment_length,
first_iteration = FALSE)
{
fragment_data *frag_msg = NULL;
tvbuff_t *new_tvb = NULL;
const gchar *frag_str = NULL;
gboolean fragmented;
msg_type = tvb_get_guint8(tvb, offset);
msg_type_str = match_strval(msg_type, ssl_31_handshake_type);
length = tvb_get_ntoh24(tvb, offset + 1);
message_seq = tvb_get_ntohs(tvb,offset + 4);
fragment_offset = tvb_get_ntoh24(tvb, offset + 6);
fragment_length = tvb_get_ntoh24(tvb, offset + 9);
fragmented = fragment_length != length;
if (!msg_type_str && !first_iteration)
{
return;
}
if (!first_iteration)
{
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
if (check_col(pinfo->cinfo, COL_INFO))
col_append_str(pinfo->cinfo, COL_INFO, (msg_type_str != NULL)
? msg_type_str : "Encrypted Handshake Message");
if (fragmented)
{
gboolean frag_hand;
switch (msg_type) {
case SSL_HND_HELLO_REQUEST:
case SSL_HND_CLIENT_HELLO:
case SSL_HND_HELLO_VERIFY_REQUEST:
case SSL_HND_NEWSESSION_TICKET:
case SSL_HND_SERVER_HELLO:
case SSL_HND_CERTIFICATE:
case SSL_HND_SERVER_KEY_EXCHG:
case SSL_HND_CERT_REQUEST:
case SSL_HND_SVR_HELLO_DONE:
case SSL_HND_CERT_VERIFY:
case SSL_HND_CLIENT_KEY_EXCHG:
case SSL_HND_FINISHED:
frag_hand = TRUE;
break;
default:
frag_hand = FALSE;
break;
}
if (frag_hand) {
pinfo->fragmented = TRUE;
tvb_ensure_bytes_exist(tvb, offset, fragment_length);
frag_msg = fragment_add(tvb, offset+12, pinfo, message_seq,
dtls_fragment_table,
fragment_offset, fragment_length, TRUE);
fragment_set_tot_len(pinfo, message_seq, dtls_fragment_table,
length);
if (frag_msg && (fragment_length + fragment_offset) == length)
{
new_tvb = process_reassembled_data(tvb, offset+12, pinfo,
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
if (check_col(pinfo->cinfo, COL_INFO))
col_append_str(pinfo->cinfo, COL_INFO, frag_str);
}
}
if (tree)
{
if (first_iteration)
{
proto_item_set_text(tree, "%s Record Layer: %s Protocol: %s%s",
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
val_to_str(content_type, ssl_31_content_type, "unknown"),
(msg_type_str!=NULL) ? msg_type_str :
"Encrypted Handshake Message",
(frag_str!=NULL) ? frag_str : "");
}
else
{
proto_item_set_text(tree, "%s Record Layer: %s Protocol: %s%s",
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"),
val_to_str(content_type, ssl_31_content_type, "unknown"),
"Multiple Handshake Messages",
(frag_str!=NULL) ? frag_str : "");
}
ti = proto_tree_add_item(tree, hf_dtls_handshake_protocol, tvb,
offset, fragment_length + 12, ENC_NA);
ssl_hand_tree = proto_item_add_subtree(ti, ett_dtls_handshake);
if (ssl_hand_tree)
{
proto_item_set_text(ssl_hand_tree, "Handshake Protocol: %s%s",
(msg_type_str != NULL) ? msg_type_str :
"Encrypted Handshake Message",
(frag_str!=NULL) ? frag_str : "");
}
}
if (!msg_type_str)
return;
if (ssl_hand_tree || ssl)
{
tvbuff_t *sub_tvb = NULL;
if (ssl_hand_tree)
proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_type,
tvb, offset, 1, msg_type);
offset++;
if (ssl_hand_tree)
proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_length,
tvb, offset, 3, length);
offset += 3;
if (ssl_hand_tree)
proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_message_seq,
tvb, offset, 2, message_seq);
offset += 2;
if (ssl_hand_tree)
proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_fragment_offset,
tvb, offset, 3, fragment_offset);
offset += 3;
if (ssl_hand_tree)
proto_tree_add_uint(ssl_hand_tree, hf_dtls_handshake_fragment_length,
tvb, offset, 3, fragment_length);
offset += 3;
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
sub_tvb = tvb_new_subset(tvb, offset, fragment_length,
fragment_length);
}
switch (msg_type) {
case SSL_HND_HELLO_REQUEST:
break;
case SSL_HND_CLIENT_HELLO:
dissect_dtls_hnd_cli_hello(sub_tvb, ssl_hand_tree, 0, length, ssl);
break;
case SSL_HND_SERVER_HELLO:
dissect_dtls_hnd_srv_hello(sub_tvb, ssl_hand_tree, 0, length, ssl);
break;
case SSL_HND_HELLO_VERIFY_REQUEST:
dissect_dtls_hnd_hello_verify_request(sub_tvb, ssl_hand_tree, 0, ssl);
break;
case SSL_HND_NEWSESSION_TICKET:
dissect_dtls_hnd_new_ses_ticket(sub_tvb, ssl_hand_tree, 0, length);
break;
case SSL_HND_CERTIFICATE:
dissect_dtls_hnd_cert(sub_tvb, ssl_hand_tree, 0, pinfo);
break;
case SSL_HND_SERVER_KEY_EXCHG:
break;
case SSL_HND_CERT_REQUEST:
dissect_dtls_hnd_cert_req(sub_tvb, ssl_hand_tree, 0);
break;
case SSL_HND_SVR_HELLO_DONE:
break;
case SSL_HND_CERT_VERIFY:
break;
case SSL_HND_CLIENT_KEY_EXCHG:
{
StringInfo encrypted_pre_master;
gint ret;
guint encrlen = length, skip;
skip = 0;
if (!ssl)
break;
ssl_debug_printf("dissect_dtls_handshake found SSL_HND_CLIENT_KEY_EXCHG, state %X\n",
ssl->state);
if ((ssl->state & (SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION)) !=
(SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION)) {
ssl_debug_printf("dissect_dtls_handshake not enough data to generate key (required state %X)\n",
(SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION));
break;
}
if (ssl->cipher_suite.kex==KEX_RSA && ssl->version_netorder != DTLSV1DOT0_VERSION_NOT) {
encrlen = tvb_get_ntohs(tvb, offset);
skip = 2;
if (encrlen > length - 2) {
ssl_debug_printf("dissect_dtls_handshake wrong encrypted length (%d max %d)\n", encrlen, length);
break;
}
}
encrypted_pre_master.data = se_alloc(encrlen);
encrypted_pre_master.data_len = encrlen;
tvb_memcpy(tvb, encrypted_pre_master.data, offset+skip, encrlen);
if (!ssl->private_key) {
ssl_debug_printf("dissect_dtls_handshake can't find private key\n");
break;
}
ret = ssl_decrypt_pre_master_secret(ssl, &encrypted_pre_master, ssl->private_key);
if (ret < 0) {
ssl_debug_printf("dissect_dtls_handshake can't decrypt pre master secret\n");
break;
}
if (ssl_generate_keyring_material(ssl)<0) {
ssl_debug_printf("dissect_dtls_handshake can't generate keyring material\n");
break;
}
ssl->state |= SSL_HAVE_SESSION_KEY;
ssl_save_session(ssl, dtls_session_hash);
ssl_debug_printf("dissect_dtls_handshake session keys successfully generated\n");
}
break;
case SSL_HND_FINISHED:
dissect_dtls_hnd_finished(sub_tvb, ssl_hand_tree,
0, conv_version);
break;
}
}
else{
offset += 12;
}
}
}
static void
dissect_dtls_heartbeat(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset,
guint* conv_version, guint32 record_length)
{
proto_tree *ti;
proto_tree *dtls_heartbeat_tree;
const gchar *type;
guint8 byte;
guint16 payload_length;
guint16 padding_length;
dtls_heartbeat_tree = NULL;
if (tree) {
ti = proto_tree_add_item(tree, hf_dtls_heartbeat_message, tvb,
offset, record_length - 32, ENC_NA);
dtls_heartbeat_tree = proto_item_add_subtree(ti, ett_dtls_heartbeat);
}
byte = tvb_get_guint8(tvb, offset);
type = match_strval(byte, tls_heartbeat_type);
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
proto_tree_add_item(dtls_heartbeat_tree, hf_dtls_heartbeat_message_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint(dtls_heartbeat_tree, hf_dtls_heartbeat_message_payload_length,
tvb, offset, 2, payload_length);
offset += 2;
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
val_to_str_const(*conv_version, ssl_version_short_names, "SSL"));
proto_item_set_text(dtls_heartbeat_tree,
"Encrypted Heartbeat Message");
}
}
}
static gint
dissect_dtls_hnd_hello_common(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, SslDecryptSession* ssl, gint from_server)
{
nstime_t gmt_unix_time;
guint8 session_id_length;
if (tree || ssl)
{
if (ssl)
{
StringInfo* rnd;
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
ssl_debug_printf("dissect_dtls_hnd_hello_common found random state %X\n",
ssl->state);
}
if (tree)
{
gmt_unix_time.secs = tvb_get_ntohl(tvb, offset);
gmt_unix_time.nsecs = 0;
proto_tree_add_time(tree, hf_dtls_handshake_random_time,
tvb, offset, 4, &gmt_unix_time);
}
offset += 4;
if (tree)
proto_tree_add_item(tree, hf_dtls_handshake_random_bytes,
tvb, offset, 28, ENC_NA);
offset += 28;
session_id_length = tvb_get_guint8(tvb, offset);
if (tree)
proto_tree_add_item(tree, hf_dtls_handshake_session_id_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (ssl)
{
if (from_server && (session_id_length == ssl->session_id.data_len) &&
(tvb_memeql(tvb, offset, ssl->session_id.data, session_id_length) == 0))
{
ssl_restore_session(ssl, dtls_session_hash);
}
else {
tvb_memcpy(tvb,ssl->session_id.data, offset, session_id_length);
ssl->session_id.data_len = session_id_length;
}
}
if (tree && session_id_length > 0)
proto_tree_add_bytes_format(tree, hf_dtls_handshake_session_id,
tvb, offset, session_id_length,
NULL, "Session ID (%u byte%s)",
session_id_length,
plurality(session_id_length, "", "s"));
offset += session_id_length;
}
return offset;
}
static gint
dissect_dtls_hnd_hello_ext(tvbuff_t *tvb,
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
proto_tree_add_uint(tree, hf_dtls_handshake_extensions_len,
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
ext_tree = proto_item_add_subtree(pi, ett_dtls_extension);
if (!ext_tree)
ext_tree = tree;
proto_tree_add_uint(ext_tree, hf_dtls_handshake_extension_type,
tvb, offset, 2, ext_type);
offset += 2;
proto_tree_add_uint(ext_tree, hf_dtls_handshake_extension_len,
tvb, offset, 2, ext_len);
offset += 2;
switch (ext_type) {
case SSL_HND_HELLO_EXT_HEARTBEAT:
proto_tree_add_item(ext_tree, hf_dtls_heartbeat_extension_mode,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += ext_len;
break;
default:
proto_tree_add_bytes_format(ext_tree, hf_dtls_handshake_extension_data,
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
static void
dissect_dtls_hnd_cli_hello(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 length,
SslDecryptSession*ssl)
{
proto_tree *ti;
proto_tree *cs_tree;
guint16 cipher_suite_length;
guint8 compression_methods_length;
guint8 compression_method;
guint16 start_offset = offset;
guint8 cookie_length;
if (tree || ssl)
{
if (tree)
proto_tree_add_item(tree, hf_dtls_handshake_client_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_dtls_hnd_hello_common(tvb, tree, offset, ssl, 0);
cookie_length = tvb_get_guint8(tvb, offset);
if (!tree)
return;
proto_tree_add_uint(tree, hf_dtls_handshake_cookie_len,
tvb, offset, 1, cookie_length);
offset ++;
if (cookie_length > 0)
{
proto_tree_add_bytes_format(tree, hf_dtls_handshake_cookie,
tvb, offset, cookie_length,
NULL, "Cookie (%u byte%s)",
cookie_length,
plurality(cookie_length, "", "s"));
offset += cookie_length;
}
cipher_suite_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_dtls_handshake_cipher_suites_len,
tvb, offset, 2, cipher_suite_length);
offset += 2;
if (cipher_suite_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, cipher_suite_length);
ti = proto_tree_add_none_format(tree,
hf_dtls_handshake_cipher_suites,
tvb, offset, cipher_suite_length,
"Cipher Suites (%u suite%s)",
cipher_suite_length / 2,
plurality(cipher_suite_length/2, "", "s"));
cs_tree = proto_item_add_subtree(ti, ett_dtls_cipher_suites);
if (!cs_tree)
{
cs_tree = tree;
}
while (cipher_suite_length > 0)
{
proto_tree_add_item(cs_tree, hf_dtls_handshake_cipher_suite,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
cipher_suite_length -= 2;
}
}
compression_methods_length = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_dtls_handshake_comp_methods_len,
tvb, offset, 1, compression_methods_length);
offset++;
if (compression_methods_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, compression_methods_length);
ti = proto_tree_add_none_format(tree,
hf_dtls_handshake_comp_methods,
tvb, offset, compression_methods_length,
"Compression Methods (%u method%s)",
compression_methods_length,
plurality(compression_methods_length,
"", "s"));
cs_tree = proto_item_add_subtree(ti, ett_dtls_comp_methods);
if (!cs_tree)
{
cs_tree = tree;
}
while (compression_methods_length > 0)
{
compression_method = tvb_get_guint8(tvb, offset);
if (compression_method < 64)
proto_tree_add_uint(cs_tree, hf_dtls_handshake_comp_method,
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
dissect_dtls_hnd_hello_ext(tvb, tree, offset,
length -
(offset - start_offset));
}
}
}
static int
dissect_dtls_hnd_srv_hello(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 length, SslDecryptSession* ssl)
{
guint16 start_offset;
start_offset = offset;
if (tree || ssl)
{
if (tree)
proto_tree_add_item(tree, hf_dtls_handshake_server_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_dtls_hnd_hello_common(tvb, tree, offset, ssl, 1);
if (ssl) {
ssl->cipher = tvb_get_ntohs(tvb, offset);
if (ssl_find_cipher(ssl->cipher,&ssl->cipher_suite) < 0) {
ssl_debug_printf("dissect_dtls_hnd_srv_hello can't find cipher suite %X\n", ssl->cipher);
goto no_cipher;
}
ssl->state |= SSL_CIPHER;
ssl_debug_printf("dissect_dtls_hnd_srv_hello found cipher %X, state %X\n",
ssl->cipher, ssl->state);
if ((ssl->state &
(SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION|SSL_MASTER_SECRET)) !=
(SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION|SSL_MASTER_SECRET)) {
ssl_debug_printf("dissect_dtls_hnd_srv_hello not enough data to generate key (required state %X)\n",
(SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION|SSL_MASTER_SECRET));
goto no_cipher;
}
ssl_debug_printf("dissect_dtls_hnd_srv_hello trying to generate keys\n");
if (ssl_generate_keyring_material(ssl)<0) {
ssl_debug_printf("dissect_dtls_hnd_srv_hello can't generate keyring material\n");
goto no_cipher;
}
ssl->state |= SSL_HAVE_SESSION_KEY;
}
no_cipher:
if (ssl) {
ssl->compression = tvb_get_guint8(tvb, offset+2);
}
if (!tree)
return offset;
proto_tree_add_item(tree, hf_dtls_handshake_cipher_suite,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dtls_handshake_comp_method,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (length > offset - start_offset)
{
offset = dissect_dtls_hnd_hello_ext(tvb, tree, offset,
length -
(offset - start_offset));
}
}
return offset;
}
static int
dissect_dtls_hnd_hello_verify_request(tvbuff_t *tvb, proto_tree *tree,
guint32 offset, SslDecryptSession* ssl)
{
guint8 cookie_length;
if (tree || ssl)
{
if (tree)
proto_tree_add_item(tree, hf_dtls_handshake_server_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
cookie_length = tvb_get_guint8(tvb, offset);
if (!tree)
return offset;
proto_tree_add_uint(tree, hf_dtls_handshake_cookie_len,
tvb, offset, 1, cookie_length);
offset ++;
if (cookie_length > 0)
{
proto_tree_add_bytes_format(tree, hf_dtls_handshake_cookie,
tvb, offset, cookie_length,
NULL, "Cookie (%u byte%s)",
cookie_length,
plurality(cookie_length, "", "s"));
offset += cookie_length;
}
}
return offset;
}
static void
dissect_dtls_hnd_new_ses_ticket(tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 length)
{
guint nst_len;
proto_item *ti;
proto_tree *subtree;
nst_len = tvb_get_ntohs(tvb, offset+4);
if (6 + nst_len != length) {
return;
}
ti = proto_tree_add_text(tree, tvb, offset, 6+nst_len, "TLS Session Ticket");
subtree = proto_item_add_subtree(ti, ett_dtls_new_ses_ticket);
proto_tree_add_item(subtree, hf_dtls_handshake_session_ticket_lifetime_hint,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_uint(subtree, hf_dtls_handshake_session_ticket_len,
tvb, offset, 2, nst_len);
proto_tree_add_item(subtree, hf_dtls_handshake_session_ticket,
tvb, offset + 2, nst_len, ENC_NA);
}
static void
dissect_dtls_hnd_cert(tvbuff_t *tvb,
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
proto_tree_add_uint(tree, hf_dtls_handshake_certificates_len,
tvb, offset, 3, certificate_list_length);
offset += 3;
if (certificate_list_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, certificate_list_length);
ti = proto_tree_add_none_format(tree,
hf_dtls_handshake_certificates,
tvb, offset, certificate_list_length,
"Certificates (%u byte%s)",
certificate_list_length,
plurality(certificate_list_length,
"", "s"));
subtree = proto_item_add_subtree(ti, ett_dtls_certs);
if (!subtree)
{
subtree = tree;
}
while (certificate_list_length > 0)
{
guint32 cert_length = tvb_get_ntoh24(tvb, offset);
certificate_list_length -= 3 + cert_length;
proto_tree_add_item(subtree, hf_dtls_handshake_certificate_len,
tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, subtree, hf_dtls_handshake_certificate);
offset += cert_length;
}
}
}
}
static void
dissect_dtls_hnd_cert_req(tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
proto_tree *ti;
proto_tree *subtree;
guint8 cert_types_count;
gint dnames_length;
if (tree)
{
cert_types_count = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_dtls_handshake_cert_types_count,
tvb, offset, 1, cert_types_count);
offset++;
if (cert_types_count > 0)
{
ti = proto_tree_add_none_format(tree,
hf_dtls_handshake_cert_types,
tvb, offset, cert_types_count,
"Certificate types (%u type%s)",
cert_types_count,
plurality(cert_types_count, "", "s"));
subtree = proto_item_add_subtree(ti, ett_dtls_cert_types);
if (!subtree)
{
subtree = tree;
}
while (cert_types_count > 0)
{
proto_tree_add_item(subtree, hf_dtls_handshake_cert_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
cert_types_count--;
}
}
dnames_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_dtls_handshake_dnames_len,
tvb, offset, 2, dnames_length);
offset += 2;
if (dnames_length > 0)
{
tvb_ensure_bytes_exist(tvb, offset, dnames_length);
ti = proto_tree_add_none_format(tree,
hf_dtls_handshake_dnames,
tvb, offset, dnames_length,
"Distinguished Names (%d byte%s)",
dnames_length,
plurality(dnames_length, "", "s"));
subtree = proto_item_add_subtree(ti, ett_dtls_dnames);
if (!subtree)
{
subtree = tree;
}
while (dnames_length > 0)
{
guint16 name_length = tvb_get_ntohs(tvb, offset);
dnames_length -= 2 + name_length;
proto_tree_add_item(subtree, hf_dtls_handshake_dname_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bytes_format(subtree,
hf_dtls_handshake_dname,
tvb, offset, name_length, NULL,
"Distinguished Name (%u byte%s)",
name_length,
plurality(name_length, "", "s"));
offset += name_length;
}
}
}
}
static void
dissect_dtls_hnd_finished(tvbuff_t *tvb, proto_tree *tree, guint32 offset,
guint* conv_version)
{
if (!tree)
{
return;
}
switch(*conv_version) {
case SSL_VER_DTLS:
proto_tree_add_item(tree, hf_dtls_handshake_finished,
tvb, offset, 12, ENC_NA);
break;
case SSL_VER_DTLS1DOT2:
proto_tree_add_item(tree, hf_dtls_handshake_finished,
tvb, offset, 12, ENC_NA);
break;
}
}
static gint
dtls_is_valid_handshake_type(guint8 type)
{
switch (type) {
case SSL_HND_HELLO_REQUEST:
case SSL_HND_CLIENT_HELLO:
case SSL_HND_SERVER_HELLO:
case SSL_HND_HELLO_VERIFY_REQUEST:
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
dtls_is_authoritative_version_message(guint8 content_type, guint8 next_byte)
{
if (content_type == SSL_ID_HANDSHAKE
&& dtls_is_valid_handshake_type(next_byte))
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
ssldecrypt_assoc_t* h = r;
g_free(h->ipaddr);
g_free(h->port);
g_free(h->protocol);
g_free(h->keyfile);
g_free(h->password);
}
static void *
dtlsdecrypt_copy_cb(void* dest, const void* orig, size_t len _U_)
{
const ssldecrypt_assoc_t* o = orig;
ssldecrypt_assoc_t* d = dest;
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
FT_DOUBLE, BASE_NONE, NULL, 0x0,
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
{ &hf_dtls_handshake_client_version,
{ "Version", "dtls.handshake.client_version",
FT_UINT16, BASE_HEX, VALS(ssl_versions), 0x0,
"Maximum version supported by client", HFILL }
},
{ &hf_dtls_handshake_server_version,
{ "Version", "dtls.handshake.server_version",
FT_UINT16, BASE_HEX, VALS(ssl_versions), 0x0,
"Version selected by server", HFILL }
},
{ &hf_dtls_handshake_random_time,
{ "Random.gmt_unix_time", "dtls.handshake.random_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Unix time field of random structure", HFILL }
},
{ &hf_dtls_handshake_random_bytes,
{ "Random.bytes", "dtls.handshake.random",
FT_NONE, BASE_NONE, NULL, 0x0,
"Random challenge used to authenticate server", HFILL }
},
{ &hf_dtls_handshake_cipher_suites_len,
{ "Cipher Suites Length", "dtls.handshake.cipher_suites_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of cipher suites field", HFILL }
},
{ &hf_dtls_handshake_cipher_suites,
{ "Cipher Suites", "dtls.handshake.ciphersuites",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of cipher suites supported by client", HFILL }
},
{ &hf_dtls_handshake_cipher_suite,
{ "Cipher Suite", "dtls.handshake.ciphersuite",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &ssl_31_ciphersuite_ext, 0x0,
NULL, HFILL }
},
{ &hf_dtls_handshake_cookie_len,
{ "Cookie Length", "dtls.handshake.cookie_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of the cookie field", HFILL }
},
{ &hf_dtls_handshake_cookie,
{ "Cookie", "dtls.handshake.cookie",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dtls_handshake_session_id,
{ "Session ID", "dtls.handshake.session_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Identifies the DTLS session, allowing later resumption", HFILL }
},
{ &hf_dtls_handshake_comp_methods_len,
{ "Compression Methods Length", "dtls.handshake.comp_methods_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of compression methods field", HFILL }
},
{ &hf_dtls_handshake_comp_methods,
{ "Compression Methods", "dtls.handshake.comp_methods",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of compression methods supported by client", HFILL }
},
{ &hf_dtls_handshake_comp_method,
{ "Compression Method", "dtls.handshake.comp_method",
FT_UINT8, BASE_DEC, VALS(ssl_31_compression_method), 0x0,
NULL, HFILL }
},
{ &hf_dtls_handshake_extensions_len,
{ "Extensions Length", "dtls.handshake.extensions_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of hello extensions", HFILL }
},
{ &hf_dtls_handshake_extension_type,
{ "Type", "dtls.handshake.extension.type",
FT_UINT16, BASE_HEX, VALS(tls_hello_extension_types), 0x0,
"Hello extension type", HFILL }
},
{ &hf_dtls_handshake_extension_len,
{ "Length", "dtls.handshake.extension.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of a hello extension", HFILL }
},
{ &hf_dtls_handshake_extension_data,
{ "Data", "dtls.handshake.extension.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Hello Extension data", HFILL }
},
{ &hf_dtls_handshake_session_ticket_lifetime_hint,
{ "Session Ticket Lifetime Hint", "dtls.handshake.session_ticket_lifetime_hint",
FT_UINT32, BASE_DEC, NULL, 0x0,
"New DTLS Session Ticket Lifetime Hint", HFILL }
},
{ &hf_dtls_handshake_session_ticket_len,
{ "Session Ticket Length", "dtls.handshake.session_ticket_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"New DTLS Session Ticket Length", HFILL }
},
{ &hf_dtls_handshake_session_ticket,
{ "Session Ticket", "dtls.handshake.session_ticket",
FT_BYTES, BASE_NONE, NULL, 0x0,
"New DTLS Session Ticket", HFILL }
},
{ &hf_dtls_handshake_certificates_len,
{ "Certificates Length", "dtls.handshake.certificates_length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length of certificates field", HFILL }
},
{ &hf_dtls_handshake_certificates,
{ "Certificates", "dtls.handshake.certificates",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of certificates", HFILL }
},
{ &hf_dtls_handshake_certificate,
{ "Certificate", "dtls.handshake.certificate",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dtls_handshake_certificate_len,
{ "Certificate Length", "dtls.handshake.certificate_length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length of certificate", HFILL }
},
{ &hf_dtls_handshake_cert_types_count,
{ "Certificate types count", "dtls.handshake.cert_types_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Count of certificate types", HFILL }
},
{ &hf_dtls_handshake_cert_types,
{ "Certificate types", "dtls.handshake.cert_types",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of certificate types", HFILL }
},
{ &hf_dtls_handshake_cert_type,
{ "Certificate type", "dtls.handshake.cert_type",
FT_UINT8, BASE_DEC, VALS(ssl_31_client_certificate_type), 0x0,
NULL, HFILL }
},
{ &hf_dtls_handshake_finished,
{ "Verify Data", "dtls.handshake.verify_data",
FT_NONE, BASE_NONE, NULL, 0x0,
"Opaque verification data", HFILL }
},
{ &hf_dtls_handshake_md5_hash,
{ "MD5 Hash", "dtls.handshake.md5_hash",
FT_NONE, BASE_NONE, NULL, 0x0,
"Hash of messages, master_secret, etc.", HFILL }
},
{ &hf_dtls_handshake_sha_hash,
{ "SHA-1 Hash", "dtls.handshake.sha_hash",
FT_NONE, BASE_NONE, NULL, 0x0,
"Hash of messages, master_secret, etc.", HFILL }
},
{ &hf_dtls_handshake_session_id_len,
{ "Session ID Length", "dtls.handshake.session_id_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of session ID field", HFILL }
},
{ &hf_dtls_handshake_dnames_len,
{ "Distinguished Names Length", "dtls.handshake.dnames_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of list of CAs that server trusts", HFILL }
},
{ &hf_dtls_handshake_dnames,
{ "Distinguished Names", "dtls.handshake.dnames",
FT_NONE, BASE_NONE, NULL, 0x0,
"List of CAs that server trusts", HFILL }
},
{ &hf_dtls_handshake_dname_len,
{ "Distinguished Name Length", "dtls.handshake.dname_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of distinguished name", HFILL }
},
{ &hf_dtls_handshake_dname,
{ "Distinguished Name", "dtls.handshake.dname",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Distinguished name of a CA that server trusts", HFILL }
},
{ &hf_dtls_heartbeat_extension_mode,
{ "Mode", "dtls.handshake.extension.heartbeat.mode",
FT_UINT8, BASE_DEC, VALS(tls_heartbeat_mode), 0x0,
"Heartbeat extension mode", HFILL }
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
};
static gint *ett[] = {
&ett_dtls,
&ett_dtls_record,
&ett_dtls_alert,
&ett_dtls_handshake,
&ett_dtls_heartbeat,
&ett_dtls_cipher_suites,
&ett_dtls_comp_methods,
&ett_dtls_extension,
&ett_dtls_new_ses_ticket,
&ett_dtls_certs,
&ett_dtls_cert_types,
&ett_dtls_dnames,
&ett_dtls_fragment,
&ett_dtls_fragments,
};
proto_dtls = proto_register_protocol("Datagram Transport Layer Security",
"DTLS", "dtls");
proto_register_field_array(proto_dtls, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
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
(void*) &dtlskeylist_uats,
&ndtlsdecrypt,
UAT_CAT_FFMT,
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
if (initialized == FALSE)
heur_dissector_add("udp", dissect_dtls_heur, proto_dtls);
initialized = TRUE;
}
