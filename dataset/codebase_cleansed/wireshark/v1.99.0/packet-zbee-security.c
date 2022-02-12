static void* uat_key_record_copy_cb(void* n, const void* o, size_t siz _U_) {
uat_key_record_t* new_key = (uat_key_record_t *)n;
const uat_key_record_t* old_key = (const uat_key_record_t *)o;
if (old_key->string) {
new_key->string = g_strdup(old_key->string);
} else {
new_key->string = NULL;
}
if (old_key->label) {
new_key->label = g_strdup(old_key->label);
} else {
new_key->label = NULL;
}
return new_key;
}
static void uat_key_record_update_cb(void* r, const char** err) {
uat_key_record_t* rec = (uat_key_record_t *)r;
if (rec->string == NULL) {
*err = g_strdup("Key can't be blank");
} else {
g_strstrip(rec->string);
if (rec->string[0] != 0) {
*err = NULL;
if ( !zbee_security_parse_key(rec->string, rec->key, rec->byte_order) ) {
*err = g_strdup_printf("Expecting %d hexadecimal bytes or\n"
"a %d character double-quoted string", ZBEE_SEC_CONST_KEYSIZE, ZBEE_SEC_CONST_KEYSIZE);
}
} else {
*err = g_strdup("Key can't be blank");
}
}
}
static void uat_key_record_free_cb(void*r) {
uat_key_record_t* key = (uat_key_record_t *)r;
if (key->string) g_free(key->string);
if (key->label) g_free(key->label);
}
void zbee_security_register(module_t *zbee_prefs, int proto)
{
static hf_register_info hf[] = {
{ &hf_zbee_sec_field,
{ "Security Control Field", "zbee.sec.field", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_sec_key_id,
{ "Key Id", "zbee.sec.key", FT_UINT8, BASE_HEX, VALS(zbee_sec_key_names),
ZBEE_SEC_CONTROL_KEY, NULL, HFILL }},
{ &hf_zbee_sec_nonce,
{ "Extended Nonce", "zbee.sec.ext_nonce", FT_BOOLEAN, 8, NULL, ZBEE_SEC_CONTROL_NONCE,
NULL, HFILL }},
{ &hf_zbee_sec_counter,
{ "Frame Counter", "zbee.sec.counter", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_sec_src64,
{ "Extended Source", "zbee.sec.src64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_sec_key_seqno,
{ "Key Sequence Number", "zbee.sec.key_seqno", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_sec_mic,
{ "Message Integrity Code", "zbee.sec.mic", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_sec_key_origin,
{ "Key Origin", "zbee.sec.key.origin", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_sec_decryption_key,
{ "Decryption Key", "zbee.sec.decryption_key", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_zbee_sec,
&ett_zbee_sec_control
};
static ei_register_info ei[] = {
{ &ei_zbee_sec_encrypted_payload, { "zbee_sec.encrypted_payload", PI_UNDECODED, PI_WARN, "Encrypted Payload", EXPFILL }},
{ &ei_zbee_sec_extended_source_unknown, { "zbee_sec.extended_source_unknown", PI_PROTOCOL, PI_NOTE, "Extended Source: Unknown", EXPFILL }},
};
expert_module_t* expert_zbee_sec;
static uat_field_t key_uat_fields[] = {
UAT_FLD_CSTRING(uat_key_records, string, "Key",
"A 16-byte key in hexadecimal with optional dash-,\n"
"colon-, or space-separator characters, or a\n"
"a 16-character string in double-quotes."),
UAT_FLD_VS(uat_key_records, byte_order, "Byte Order", byte_order_vals,
"Byte order of key."),
UAT_FLD_LSTRING(uat_key_records, label, "Label", "User label for key."),
UAT_END_FIELDS
};
if (zbee_prefs == NULL) {
zbee_prefs = prefs_register_protocol(proto, NULL);
}
prefs_register_enum_preference(zbee_prefs, "seclevel", "Security Level",
"Specifies the security level to use in the\n"
"decryption process. This value is ignored\n"
"for ZigBee 2004 and unsecured networks.",
&gPREF_zbee_sec_level, zbee_sec_level_enums, FALSE);
zbee_sec_key_table_uat = uat_new("Pre-configured Keys",
sizeof(uat_key_record_t),
"zigbee_pc_keys",
TRUE,
&uat_key_records,
&num_uat_key_records,
UAT_AFFECTS_DISSECTION,
NULL,
uat_key_record_copy_cb,
uat_key_record_update_cb,
uat_key_record_free_cb,
NULL,
key_uat_fields );
prefs_register_uat_preference(zbee_prefs,
"key_table",
"Pre-configured Keys",
"Pre-configured link or network keys.",
zbee_sec_key_table_uat);
proto_register_field_array(proto, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_zbee_sec = expert_register_protocol(proto);
expert_register_field_array(expert_zbee_sec, ei, array_length(ei));
register_init_routine(proto_init_zbee_security);
}
static gboolean
zbee_security_parse_key(const gchar *key_str, guint8 *key_buf, gboolean byte_order)
{
int i, j;
gchar temp;
gboolean string_mode = FALSE;
memset(key_buf, 0, ZBEE_SEC_CONST_KEYSIZE);
if (key_str == NULL) {
return FALSE;
}
if ( (temp = *key_str++) == '"') {
string_mode = TRUE;
temp = *key_str++;
}
j = byte_order?ZBEE_SEC_CONST_KEYSIZE-1:0;
for (i=ZBEE_SEC_CONST_KEYSIZE-1; i>=0; i--) {
if ( string_mode ) {
if ( g_ascii_isprint(temp) ) {
key_buf[j] = temp;
temp = *key_str++;
} else {
return FALSE;
}
}
else {
if ( (temp == ':') || (temp == '-') || (temp == ' ') ) temp = *(key_str++);
if ( g_ascii_isxdigit (temp) ) key_buf[j] = g_ascii_xdigit_value(temp)<<4;
else return FALSE;
temp = *(key_str++);
if ( g_ascii_isxdigit (temp) ) key_buf[j] |= g_ascii_xdigit_value(temp);
else return FALSE;
temp = *(key_str++);
}
if ( byte_order ) {
j--;
} else {
j++;
}
}
return TRUE;
}
void
zbee_security_handoff(void)
{
data_handle = find_dissector("data");
}
tvbuff_t *
dissect_zbee_secure(tvbuff_t *tvb, packet_info *pinfo, proto_tree* tree, guint offset)
{
proto_tree *sec_tree;
zbee_security_packet packet;
guint mic_len;
gint payload_len;
tvbuff_t *payload_tvb;
#ifdef HAVE_LIBGCRYPT
proto_item *ti;
guint8 *enc_buffer;
guint8 *dec_buffer;
gboolean decrypted;
GSList **nwk_keyring;
GSList *GSList_i;
key_record_t *key_rec = NULL;
#endif
zbee_nwk_hints_t *nwk_hints;
ieee802154_hints_t *ieee_hints;
ieee802154_map_rec *map_rec = NULL;
static const int * sec_flags[] = {
&hf_zbee_sec_key_id,
&hf_zbee_sec_nonce,
NULL
};
memset(&packet, 0, sizeof(zbee_security_packet));
nwk_hints = (zbee_nwk_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(ZBEE_PROTOABBREV_NWK), 0);
ieee_hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
sec_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_zbee_sec, NULL, "ZigBee Security Header");
packet.control = tvb_get_guint8(tvb, offset);
packet.control &= ~ZBEE_SEC_CONTROL_LEVEL;
packet.control |= (ZBEE_SEC_CONTROL_LEVEL & gPREF_zbee_sec_level);
#ifdef HAVE_LIBGCRYPT
enc_buffer = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, 0, tvb_length(tvb));
enc_buffer[offset] = packet.control;
#endif
packet.level = zbee_get_bit_field(packet.control, ZBEE_SEC_CONTROL_LEVEL);
packet.key_id = zbee_get_bit_field(packet.control, ZBEE_SEC_CONTROL_KEY);
packet.nonce = zbee_get_bit_field(packet.control, ZBEE_SEC_CONTROL_NONCE);
proto_tree_add_bitmask(sec_tree, tvb, offset, hf_zbee_sec_field, ett_zbee_sec_control, sec_flags, ENC_NA);
offset += 1;
packet.counter = tvb_get_letohl(tvb, offset);
if (tree) {
proto_tree_add_uint(sec_tree, hf_zbee_sec_counter, tvb, offset, 4, packet.counter);
}
offset += 4;
if (packet.nonce) {
packet.src64 = tvb_get_letoh64(tvb, offset);
if (tree) {
proto_tree_add_item(sec_tree, hf_zbee_sec_src64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
}
#if 1
if (!pinfo->fd->flags.visited) {
switch ( packet.key_id ) {
case ZBEE_SEC_KEY_LINK:
if (nwk_hints && ieee_hints) {
nwk_hints->map_rec = ieee802154_addr_update(&zbee_nwk_map, nwk_hints->src,
ieee_hints->src_pan, packet.src64, pinfo->current_proto, pinfo->fd->num);
}
break;
case ZBEE_SEC_KEY_NWK:
if (ieee_hints) {
ieee_hints->map_rec = ieee802154_addr_update(&zbee_nwk_map, ieee_hints->src16,
ieee_hints->src_pan, packet.src64, pinfo->current_proto, pinfo->fd->num);
}
break;
case ZBEE_SEC_KEY_TRANSPORT:
case ZBEE_SEC_KEY_LOAD:
break;
}
}
#endif
offset += 8;
}
else {
switch ( packet.key_id ) {
case ZBEE_SEC_KEY_NWK:
if ( ieee_hints && (map_rec = ieee_hints->map_rec) )
packet.src64 = map_rec->addr64;
else
proto_tree_add_expert(sec_tree, pinfo, &ei_zbee_sec_extended_source_unknown, tvb, 0, 0);
break;
default:
if ( nwk_hints && (map_rec = nwk_hints->map_rec) )
packet.src64 = map_rec->addr64;
else
proto_tree_add_expert(sec_tree, pinfo, &ei_zbee_sec_extended_source_unknown, tvb, 0, 0);
break;
}
}
if (packet.key_id == ZBEE_SEC_KEY_NWK) {
packet.key_seqno = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(sec_tree, hf_zbee_sec_key_seqno, tvb, offset, 1, packet.key_seqno);
}
offset += 1;
}
switch (packet.level) {
case ZBEE_SEC_ENC:
case ZBEE_SEC_NONE:
default:
mic_len=0;
break;
case ZBEE_SEC_ENC_MIC32:
case ZBEE_SEC_MIC32:
mic_len=4;
break;
case ZBEE_SEC_ENC_MIC64:
case ZBEE_SEC_MIC64:
mic_len=8;
break;
case ZBEE_SEC_ENC_MIC128:
case ZBEE_SEC_MIC128:
mic_len=16;
break;
}
if (mic_len) {
if (tree) {
proto_tree_add_item(sec_tree, hf_zbee_sec_mic, tvb, (gint)(tvb_length(tvb)-mic_len),
mic_len, ENC_NA);
}
}
if ( !(payload_len = tvb_reported_length_remaining(tvb, offset+mic_len)) ) {
return NULL;
} else if ( payload_len < 0 ) {
THROW(ReportedBoundsError);
}
if ((packet.level == ZBEE_SEC_NONE) ||
(packet.level == ZBEE_SEC_MIC32) ||
(packet.level == ZBEE_SEC_MIC64) ||
(packet.level == ZBEE_SEC_MIC128)) {
return tvb_new_subset_length(tvb, offset, payload_len);
}
#ifdef HAVE_LIBGCRYPT
dec_buffer = (guint8 *)g_malloc(payload_len);
decrypted = FALSE;
if ( packet.src64 ) {
if (pinfo->fd->flags.visited) {
if ( nwk_hints ) {
switch ( packet.key_id ) {
case ZBEE_SEC_KEY_NWK:
if ( (key_rec = nwk_hints->nwk) ) {
decrypted = zbee_sec_decrypt_payload( &packet, enc_buffer, offset, dec_buffer,
payload_len, mic_len, nwk_hints->nwk->key);
}
break;
default:
if ( (key_rec = nwk_hints->link) ) {
decrypted = zbee_sec_decrypt_payload( &packet, enc_buffer, offset, dec_buffer,
payload_len, mic_len, nwk_hints->link->key);
}
break;
}
}
}
else {
if ( nwk_hints ) {
nwk_keyring = (GSList **)g_hash_table_lookup(zbee_table_nwk_keyring, &nwk_hints->src_pan);
if ( nwk_keyring ) {
GSList_i = *nwk_keyring;
while ( GSList_i && !decrypted ) {
decrypted = zbee_sec_decrypt_payload( &packet, enc_buffer, offset, dec_buffer,
payload_len, mic_len, ((key_record_t *)(GSList_i->data))->key);
if (decrypted) {
switch (packet.key_id) {
case ZBEE_SEC_KEY_NWK:
key_rec = nwk_hints->nwk = (key_record_t *)(GSList_i->data);
break;
default:
key_rec = nwk_hints->link = (key_record_t *)(GSList_i->data);
break;
}
} else {
GSList_i = g_slist_next(GSList_i);
}
}
}
GSList_i = zbee_pc_keyring;
while ( GSList_i && !decrypted ) {
decrypted = zbee_sec_decrypt_payload( &packet, enc_buffer, offset, dec_buffer,
payload_len, mic_len, ((key_record_t *)(GSList_i->data))->key);
if (decrypted) {
switch (packet.key_id) {
case ZBEE_SEC_KEY_NWK:
key_rec = nwk_hints->nwk = (key_record_t *)(GSList_i->data);
break;
default:
key_rec = nwk_hints->link = (key_record_t *)(GSList_i->data);
break;
}
} else {
GSList_i = g_slist_next(GSList_i);
}
}
}
}
}
if ( decrypted ) {
if ( tree && key_rec ) {
if ( key_rec->frame_num == ZBEE_SEC_PC_KEY ) {
ti = proto_tree_add_string(sec_tree, hf_zbee_sec_decryption_key, tvb, 0, 0, key_rec->label);
} else {
ti = proto_tree_add_uint(sec_tree, hf_zbee_sec_key_origin, tvb, 0, 0,
key_rec->frame_num);
}
PROTO_ITEM_SET_GENERATED(ti);
}
payload_tvb = tvb_new_child_real_data(tvb, dec_buffer, payload_len, payload_len);
tvb_set_free_cb(payload_tvb, g_free);
add_new_data_source(pinfo, payload_tvb, "Decrypted ZigBee Payload");
return payload_tvb;
}
g_free(dec_buffer);
#endif
expert_add_info(pinfo, sec_tree, &ei_zbee_sec_encrypted_payload);
payload_tvb = tvb_new_subset(tvb, offset, payload_len, -1);
call_dissector(data_handle, payload_tvb, pinfo, tree);
return NULL;
}
static gboolean
zbee_sec_decrypt_payload(zbee_security_packet *packet, const gchar *enc_buffer, const gchar offset, guint8 *dec_buffer,
guint payload_len, guint mic_len, guint8 *key)
{
guint8 nonce[ZBEE_SEC_CONST_NONCE_LEN];
guint8 buffer[ZBEE_SEC_CONST_BLOCKSIZE+1];
guint8 *key_buffer = buffer;
switch (packet->key_id) {
case ZBEE_SEC_KEY_NWK:
case ZBEE_SEC_KEY_LINK:
key_buffer = key;
break;
case ZBEE_SEC_KEY_TRANSPORT:
zbee_sec_key_hash(key, 0x00, buffer);
key_buffer = buffer;
break;
case ZBEE_SEC_KEY_LOAD:
zbee_sec_key_hash(key, 0x02, buffer);
key_buffer = buffer;
break;
default:
break;
}
zbee_sec_make_nonce(packet, nonce);
if ( zbee_sec_ccm_decrypt(key_buffer,
nonce,
enc_buffer,
enc_buffer+offset,
dec_buffer,
offset,
payload_len,
mic_len) ) {
return TRUE;
}
else return FALSE;
}
static void
zbee_sec_make_nonce(zbee_security_packet *packet, guint8 *nonce)
{
*(nonce++) = (guint8)((packet->src64)>>0 & 0xff);
*(nonce++) = (guint8)((packet->src64)>>8 & 0xff);
*(nonce++) = (guint8)((packet->src64)>>16 & 0xff);
*(nonce++) = (guint8)((packet->src64)>>24 & 0xff);
*(nonce++) = (guint8)((packet->src64)>>32 & 0xff);
*(nonce++) = (guint8)((packet->src64)>>40 & 0xff);
*(nonce++) = (guint8)((packet->src64)>>48 & 0xff);
*(nonce++) = (guint8)((packet->src64)>>56 & 0xff);
*(nonce++) = (guint8)((packet->counter)>>0 & 0xff);
*(nonce++) = (guint8)((packet->counter)>>8 & 0xff);
*(nonce++) = (guint8)((packet->counter)>>16 & 0xff);
*(nonce++) = (guint8)((packet->counter)>>24 & 0xff);
*(nonce) = packet->control;
}
gboolean
zbee_sec_ccm_decrypt(const gchar *key,
const gchar *nonce,
const gchar *a,
const gchar *c,
gchar *m,
guint l_a,
guint l_m,
guint M)
{
guint8 cipher_in[ZBEE_SEC_CONST_BLOCKSIZE];
guint8 cipher_out[ZBEE_SEC_CONST_BLOCKSIZE];
guint8 decrypted_mic[ZBEE_SEC_CONST_BLOCKSIZE];
guint i, j;
gcry_cipher_hd_t cipher_hd;
if (M > ZBEE_SEC_CONST_BLOCKSIZE) return FALSE;
if ((1 + (l_a/ZBEE_SEC_CONST_BLOCKSIZE)) > (1<<(ZBEE_SEC_CONST_L*8))) return FALSE;
memset(cipher_in, 0, ZBEE_SEC_CONST_BLOCKSIZE);
cipher_in[0] = ZBEE_SEC_CCM_FLAG_L;
memcpy(cipher_in + 1, nonce, ZBEE_SEC_CONST_NONCE_LEN);
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CTR, 0)) {
return FALSE;
}
if (gcry_cipher_setkey(cipher_hd, key, ZBEE_SEC_CONST_KEYSIZE)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
if (gcry_cipher_setctr(cipher_hd, cipher_in, ZBEE_SEC_CONST_BLOCKSIZE)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
memset(decrypted_mic, 0, ZBEE_SEC_CONST_BLOCKSIZE);
memcpy(decrypted_mic, c + l_m, M);
if (gcry_cipher_encrypt(cipher_hd, decrypted_mic, ZBEE_SEC_CONST_BLOCKSIZE, decrypted_mic, ZBEE_SEC_CONST_BLOCKSIZE)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
if (gcry_cipher_encrypt(cipher_hd, m, l_m, c, l_m)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
gcry_cipher_close(cipher_hd);
if (M == 0) {
return TRUE;
}
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_ECB, 0)) {
return FALSE;
}
if (gcry_cipher_setkey(cipher_hd, key, ZBEE_SEC_CONST_KEYSIZE)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
cipher_in[0] = ZBEE_SEC_CCM_FLAG_M(M) |
ZBEE_SEC_CCM_FLAG_ADATA(l_a) |
ZBEE_SEC_CCM_FLAG_L;
memcpy(cipher_in+sizeof(gchar), nonce, ZBEE_SEC_CONST_NONCE_LEN);
for (i=0;i<ZBEE_SEC_CONST_L; i++) {
cipher_in[(ZBEE_SEC_CONST_BLOCKSIZE-1)-i] = (l_m >> (8*i)) & 0xff;
}
if (gcry_cipher_encrypt(cipher_hd, cipher_out, ZBEE_SEC_CONST_BLOCKSIZE, cipher_in, ZBEE_SEC_CONST_BLOCKSIZE)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
j = 0;
if (l_a > 0) {
cipher_in[j] = cipher_out[j] ^ ((l_a >> 8) & 0xff);
j++;
cipher_in[j] = cipher_out[j] ^ ((l_a >> 0) & 0xff);
j++;
for (i=0;i<l_a;i++,j++) {
if (j>=ZBEE_SEC_CONST_BLOCKSIZE) {
if (gcry_cipher_encrypt(cipher_hd, cipher_out, ZBEE_SEC_CONST_BLOCKSIZE, cipher_in,
ZBEE_SEC_CONST_BLOCKSIZE)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
j = 0;
}
cipher_in[j] = cipher_out[j] ^ a[i];
}
for (;j<ZBEE_SEC_CONST_BLOCKSIZE;j++)
cipher_in[j] = cipher_out[j];
}
for (i=0; i<l_m; i++, j++) {
if (j>=ZBEE_SEC_CONST_BLOCKSIZE) {
if (gcry_cipher_encrypt(cipher_hd, cipher_out, ZBEE_SEC_CONST_BLOCKSIZE, cipher_in,
ZBEE_SEC_CONST_BLOCKSIZE)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
j = 0;
}
cipher_in[j] = cipher_out[j] ^ m[i];
}
for (;j<ZBEE_SEC_CONST_BLOCKSIZE;j++)
cipher_in[j] = cipher_out[j];
if (gcry_cipher_encrypt(cipher_hd, cipher_out, ZBEE_SEC_CONST_BLOCKSIZE, cipher_in, ZBEE_SEC_CONST_BLOCKSIZE)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
gcry_cipher_close(cipher_hd);
return (memcmp(cipher_out, decrypted_mic, M) == 0);
}
static void
zbee_sec_hash(guint8 *input, guint input_len, guint8 *output)
{
guint8 cipher_in[ZBEE_SEC_CONST_BLOCKSIZE];
guint i, j;
gcry_cipher_hd_t cipher_hd;
memset(output, 0, ZBEE_SEC_CONST_BLOCKSIZE);
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_ECB, 0)) {
return;
}
i = 0;
j = 0;
while (i<input_len) {
cipher_in[j++] = input[i++];
if (j >= ZBEE_SEC_CONST_BLOCKSIZE) {
(void)gcry_cipher_setkey(cipher_hd, output, ZBEE_SEC_CONST_BLOCKSIZE);
(void)gcry_cipher_encrypt(cipher_hd, output, ZBEE_SEC_CONST_BLOCKSIZE, cipher_in, ZBEE_SEC_CONST_BLOCKSIZE);
for (j=0;j<ZBEE_SEC_CONST_BLOCKSIZE;j++) output[j] ^= cipher_in[j];
j = 0;
}
}
cipher_in[j++] = 0x80;
while (j!=(ZBEE_SEC_CONST_BLOCKSIZE-2)) {
if (j >= ZBEE_SEC_CONST_BLOCKSIZE) {
(void)gcry_cipher_setkey(cipher_hd, output, ZBEE_SEC_CONST_BLOCKSIZE);
(void)gcry_cipher_encrypt(cipher_hd, output, ZBEE_SEC_CONST_BLOCKSIZE, cipher_in, ZBEE_SEC_CONST_BLOCKSIZE);
for (j=0;j<ZBEE_SEC_CONST_BLOCKSIZE;j++) output[j] ^= cipher_in[j];
j = 0;
}
cipher_in[j++] = 0x00;
}
cipher_in[j++] = ((input_len * 8) >> 8) & 0xff;
cipher_in[j] = ((input_len * 8) >> 0) & 0xff;
(void)gcry_cipher_setkey(cipher_hd, output, ZBEE_SEC_CONST_BLOCKSIZE);
(void)gcry_cipher_encrypt(cipher_hd, output, ZBEE_SEC_CONST_BLOCKSIZE, cipher_in, ZBEE_SEC_CONST_BLOCKSIZE);
for (j=0;j<ZBEE_SEC_CONST_BLOCKSIZE;j++) output[j] ^= cipher_in[j];
gcry_cipher_close(cipher_hd);
}
static guint8 *
zbee_sec_key_hash(guint8 *key, guint8 input, guint8 *hash_out)
{
guint8 hash_in[2*ZBEE_SEC_CONST_BLOCKSIZE];
int i;
static const guint8 ipad = 0x36;
static const guint8 opad = 0x5c;
for (i=0; i<ZBEE_SEC_CONST_KEYSIZE; i++) hash_in[i] = key[i] ^ opad;
for (i=0; i<ZBEE_SEC_CONST_KEYSIZE; i++) hash_out[i] = key[i] ^ ipad;
hash_out[ZBEE_SEC_CONST_BLOCKSIZE] = input;
zbee_sec_hash(hash_out, ZBEE_SEC_CONST_BLOCKSIZE+1, hash_in+ZBEE_SEC_CONST_BLOCKSIZE);
zbee_sec_hash(hash_in, 2*ZBEE_SEC_CONST_BLOCKSIZE, hash_out);
return hash_out;
}
gboolean
zbee_sec_ccm_decrypt(const gchar *key _U_,
const gchar *nonce _U_,
const gchar *a _U_,
const gchar *c _U_,
gchar *m _U_,
guint l_a _U_,
guint l_m _U_,
guint M _U_)
{
return FALSE;
}
static void
proto_init_zbee_security(void)
{
guint i;
key_record_t key_record;
if (zbee_pc_keyring) {
g_slist_free(zbee_pc_keyring);
zbee_pc_keyring = NULL;
}
for (i=0; (uat_key_records) && (i<num_uat_key_records) ; i++) {
key_record.frame_num = ZBEE_SEC_PC_KEY;
key_record.label = g_strdup(uat_key_records[i].label);
memcpy(&key_record.key, &uat_key_records[i].key, ZBEE_SEC_CONST_KEYSIZE);
zbee_pc_keyring = g_slist_prepend(zbee_pc_keyring, g_memdup(&key_record, sizeof(key_record_t)));
}
}
