static void printnbyte(const guint8* tab, int nb, const char* txt, const char* txt2)
{
int i;
fprintf(stderr, "%s ", txt);
for (i=0; i<nb; i++)
{
fprintf(stderr, "%02X ", *(tab+i));
}
fprintf(stderr, "%s", txt2);
}
static void printnbyte(const guint8* tab _U_, int nb _U_, const char* txt _U_, const char* txt2 _U_)
{
}
static int
crypt_des_ecb_long(guint8 *response,
const guint8 *key,
const guint8 *data)
{
guint8 pw21[21];
memset(pw21, 0, sizeof(pw21));
memcpy(pw21, key, 16);
memset(response, 0, 24);
crypt_des_ecb(response, data, pw21, 1);
crypt_des_ecb(response + 8, data, pw21 + 7, 1);
crypt_des_ecb(response + 16, data, pw21 + 14, 1);
return 1;
}
static int
ntlmssp_generate_challenge_response(guint8 *response,
const guint8 *passhash,
const guint8 *challenge)
{
guint8 pw21[21];
memset(pw21, 0x0, sizeof(pw21));
memcpy(pw21, passhash, 16);
memset(response, 0, 24);
crypt_des_ecb(response, challenge, pw21, 1);
crypt_des_ecb(response + 8, challenge, pw21 + 7, 1);
crypt_des_ecb(response + 16, challenge, pw21 + 14, 1);
return 1;
}
static void
str_to_unicode(const char *nt_password, char *nt_password_unicode)
{
size_t password_len;
size_t i;
password_len = strlen(nt_password);
if (nt_password_unicode != NULL) {
for (i=0; i<(password_len); i++) {
nt_password_unicode[i*2]=nt_password[i];
nt_password_unicode[i*2+1]=0;
}
nt_password_unicode[2*password_len]='\0';
}
}
static void
get_keyexchange_key(unsigned char keyexchangekey[NTLMSSP_KEY_LEN], const unsigned char sessionbasekey[NTLMSSP_KEY_LEN], const unsigned char lm_challenge_response[24], int flags)
{
guint8 basekey[NTLMSSP_KEY_LEN];
guint8 zeros[24];
memset(keyexchangekey, 0, NTLMSSP_KEY_LEN);
memset(basekey, 0, NTLMSSP_KEY_LEN);
memcpy(basekey, sessionbasekey, 8);
memset(basekey, 0xBD, 8);
if (flags&NTLMSSP_NEGOTIATE_LM_KEY) {
crypt_des_ecb(keyexchangekey, lm_challenge_response, basekey, 1);
crypt_des_ecb(keyexchangekey+8, lm_challenge_response, basekey+7, 1);
}
else {
if (flags&NTLMSSP_REQUEST_NON_NT_SESSION) {
memset(zeros, 0, 24);
crypt_des_ecb(keyexchangekey, zeros, basekey, 3);
crypt_des_ecb(keyexchangekey+8, zeros, basekey+7, 1);
}
else {
memcpy(keyexchangekey, sessionbasekey, NTLMSSP_KEY_LEN);
}
}
}
static guint32
get_md4pass_list(md4_pass** p_pass_list, const char* nt_password)
{
guint32 nb_pass = 0;
enc_key_t *ek;
unsigned char nt_password_hash[NTLMSSP_KEY_LEN];
char nt_password_unicode[256];
md4_pass* pass_list;
int i;
*p_pass_list = NULL;
if (!krb_decrypt) {
return 0;
}
read_keytab_file_from_preferences();
for (ek=enc_key_list; ek; ek=ek->next) {
if (ek->keylength == NTLMSSP_KEY_LEN) {
nb_pass++;
}
}
memset(nt_password_unicode, 0, sizeof(nt_password_unicode));
memset(nt_password_hash, 0, NTLMSSP_KEY_LEN);
if ((nt_password[0] != '\0') && (strlen(nt_password) < 129)) {
int password_len;
nb_pass++;
password_len = (int)strlen(nt_password);
str_to_unicode(nt_password, nt_password_unicode);
crypt_md4(nt_password_hash, nt_password_unicode, password_len*2);
}
if (nb_pass == 0) {
return 0;
}
i = 0;
*p_pass_list = (md4_pass *)wmem_alloc(wmem_packet_scope(), nb_pass*sizeof(md4_pass));
pass_list = *p_pass_list;
if (memcmp(nt_password_hash, gbl_zeros, NTLMSSP_KEY_LEN) != 0) {
memcpy(pass_list[i].md4, nt_password_hash, NTLMSSP_KEY_LEN);
i = 1;
}
for (ek=enc_key_list; ek; ek=ek->next) {
if (ek->keylength == NTLMSSP_KEY_LEN) {
memcpy(pass_list[i].md4, ek->keyvalue, NTLMSSP_KEY_LEN);
i++;
}
}
return nb_pass;
}
static void
create_ntlmssp_v2_key(const char *nt_password _U_, const guint8 *serverchallenge , const guint8 *clientchallenge ,
guint8 *sessionkey , const guint8 *encryptedsessionkey , int flags ,
const ntlmssp_blob *ntlm_response, const ntlmssp_blob *lm_response _U_, ntlmssp_header_t *ntlmssph)
{
#define DOMAIN_NAME_BUF_SIZE 512
#define USER_BUF_SIZE 256
#define BUF_SIZE (DOMAIN_NAME_BUF_SIZE + USER_BUF_SIZE)
char domain_name_unicode[DOMAIN_NAME_BUF_SIZE];
char user_uppercase[USER_BUF_SIZE];
char buf[BUF_SIZE];
unsigned char nt_password_hash[NTLMSSP_KEY_LEN];
unsigned char nt_proof[NTLMSSP_KEY_LEN];
unsigned char ntowf[NTLMSSP_KEY_LEN];
guint8 sessionbasekey[NTLMSSP_KEY_LEN];
guint8 keyexchangekey[NTLMSSP_KEY_LEN];
guint8 lm_challenge_response[24];
guint32 i;
guint32 j;
rc4_state_struct rc4state;
size_t user_len;
size_t domain_len;
md4_pass *pass_list = NULL;
guint32 nb_pass = 0;
gboolean found = FALSE;
memset(sessionkey, 0, NTLMSSP_KEY_LEN);
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
nb_pass = get_md4pass_list(&pass_list, nt_password);
#endif
i = 0;
memset(user_uppercase, 0, USER_BUF_SIZE);
user_len = strlen(ntlmssph->acct_name);
if (user_len < USER_BUF_SIZE / 2) {
memset(buf, 0, BUF_SIZE);
str_to_unicode(ntlmssph->acct_name, buf);
for (j = 0; j < (2*user_len); j++) {
if (buf[j] != '\0') {
user_uppercase[j] = g_ascii_toupper(buf[j]);
}
}
}
else {
return;
}
domain_len = strlen(ntlmssph->domain_name);
if (domain_len < DOMAIN_NAME_BUF_SIZE / 2) {
str_to_unicode(ntlmssph->domain_name, domain_name_unicode);
}
else {
return;
}
while (i < nb_pass) {
#ifdef DEBUG_NTLMSSP
fprintf(stderr, "Turn %d, ", i);
#endif
memcpy(nt_password_hash, pass_list[i].md4, NTLMSSP_KEY_LEN);
printnbyte(nt_password_hash, NTLMSSP_KEY_LEN, "Current NT password hash: ", "\n");
i++;
memset(buf, 0, BUF_SIZE);
memcpy(buf, user_uppercase, user_len*2);
memcpy(buf+user_len*2, domain_name_unicode, domain_len*2);
md5_hmac(buf, domain_len*2+user_len*2, nt_password_hash, NTLMSSP_KEY_LEN, ntowf);
printnbyte(ntowf, NTLMSSP_KEY_LEN, "NTOWF: ", "\n");
memset(buf, 0, BUF_SIZE);
memcpy(buf, serverchallenge, 8);
memcpy(buf+8, clientchallenge, 8);
md5_hmac(buf, NTLMSSP_KEY_LEN, ntowf, NTLMSSP_KEY_LEN, lm_challenge_response);
memcpy(lm_challenge_response+NTLMSSP_KEY_LEN, clientchallenge, 8);
printnbyte(lm_challenge_response, 24, "LM Response: ", "\n");
memset(buf, 0, BUF_SIZE);
memcpy(buf, serverchallenge, 8);
memcpy(buf+8, ntlm_response->contents+NTLMSSP_KEY_LEN, MIN(BUF_SIZE - 8, ntlm_response->length-NTLMSSP_KEY_LEN));
md5_hmac(buf, ntlm_response->length-8, ntowf, NTLMSSP_KEY_LEN, nt_proof);
printnbyte(nt_proof, NTLMSSP_KEY_LEN, "NT proof: ", "\n");
if (!memcmp(nt_proof, ntlm_response->contents, NTLMSSP_KEY_LEN)) {
found = TRUE;
break;
}
}
if (!found) {
return;
}
md5_hmac(nt_proof, NTLMSSP_KEY_LEN, ntowf, NTLMSSP_KEY_LEN, sessionbasekey);
get_keyexchange_key(keyexchangekey, sessionbasekey, lm_challenge_response, flags);
if (flags & NTLMSSP_NEGOTIATE_KEY_EXCH)
{
memcpy(sessionkey, encryptedsessionkey, NTLMSSP_KEY_LEN);
crypt_rc4_init(&rc4state, keyexchangekey, NTLMSSP_KEY_LEN);
crypt_rc4(&rc4state, sessionkey, NTLMSSP_KEY_LEN);
}
else
{
memcpy(sessionkey, keyexchangekey, NTLMSSP_KEY_LEN);
}
memcpy(ntlmssph->session_key, sessionkey, NTLMSSP_KEY_LEN);
}
static void
create_ntlmssp_v1_key(const char *nt_password, const guint8 *serverchallenge, const guint8 *clientchallenge,
guint8 *sessionkey, const guint8 *encryptedsessionkey, int flags,
const guint8 *ref_nt_challenge_response, const guint8 *ref_lm_challenge_response,
ntlmssp_header_t *ntlmssph)
{
unsigned char lm_password_upper[NTLMSSP_KEY_LEN];
unsigned char lm_password_hash[NTLMSSP_KEY_LEN];
unsigned char nt_password_hash[NTLMSSP_KEY_LEN];
unsigned char challenges_hash[NTLMSSP_KEY_LEN];
unsigned char challenges_hash_first8[8];
unsigned char challenges[NTLMSSP_KEY_LEN];
guint8 md4[NTLMSSP_KEY_LEN];
guint8 nb_pass = 0;
guint8 sessionbasekey[NTLMSSP_KEY_LEN];
guint8 keyexchangekey[NTLMSSP_KEY_LEN];
guint8 lm_challenge_response[24];
guint8 nt_challenge_response[24];
rc4_state_struct rc4state;
md5_state_t md5state;
char nt_password_unicode[256];
size_t password_len;
unsigned int i;
gboolean found = FALSE;
md4_pass *pass_list = NULL;
static const unsigned char lmhash_key[] =
{0x4b, 0x47, 0x53, 0x21, 0x40, 0x23, 0x24, 0x25};
memset(sessionkey, 0, NTLMSSP_KEY_LEN);
memset(lm_password_upper, 0, sizeof(lm_password_upper));
if (nt_password[0] != '\0') {
password_len = strlen(nt_password);
str_to_unicode(nt_password, nt_password_unicode);
crypt_md4(nt_password_hash, nt_password_unicode, password_len*2);
if (password_len > NTLMSSP_KEY_LEN)
password_len = NTLMSSP_KEY_LEN;
for (i = 0; i < password_len; i++) {
lm_password_upper[i] = g_ascii_toupper(nt_password[i]);
}
}
else
{
if (!(flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY)) {
return;
}
}
if ((flags & NTLMSSP_NEGOTIATE_LM_KEY && !(flags & NTLMSSP_NEGOTIATE_NT_ONLY)) || !(flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY) || !(flags & NTLMSSP_NEGOTIATE_NTLM)) {
crypt_des_ecb(lm_password_hash, lmhash_key, lm_password_upper, 1);
crypt_des_ecb(lm_password_hash+8, lmhash_key, lm_password_upper+7, 1);
ntlmssp_generate_challenge_response(lm_challenge_response,
lm_password_hash, serverchallenge);
memcpy(sessionbasekey, lm_password_hash, NTLMSSP_KEY_LEN);
}
else {
memset(lm_challenge_response, 0, 24);
if (flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY) {
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
nb_pass = get_md4pass_list(&pass_list, nt_password);
#endif
i = 0;
while (i < nb_pass) {
memcpy(nt_password_hash, pass_list[i].md4, NTLMSSP_KEY_LEN);
i++;
if(clientchallenge){
memcpy(lm_challenge_response, clientchallenge, 8);
}
md5_init(&md5state);
md5_append(&md5state, serverchallenge, 8);
md5_append(&md5state, clientchallenge, 8);
md5_finish(&md5state, challenges_hash);
memcpy(challenges_hash_first8, challenges_hash, 8);
crypt_des_ecb_long(nt_challenge_response, nt_password_hash, challenges_hash_first8);
if (ref_nt_challenge_response && !memcmp(ref_nt_challenge_response, nt_challenge_response, 24)) {
found = TRUE;
break;
}
}
}
else {
crypt_des_ecb_long(nt_challenge_response, nt_password_hash, serverchallenge);
if (flags & NTLMSSP_NEGOTIATE_NT_ONLY) {
memcpy(lm_challenge_response, nt_challenge_response, 24);
}
else {
crypt_des_ecb_long(lm_challenge_response, lm_password_hash, serverchallenge);
}
if (ref_nt_challenge_response &&
!memcmp(ref_nt_challenge_response, nt_challenge_response, 24) &&
ref_lm_challenge_response &&
!memcmp(ref_lm_challenge_response, lm_challenge_response, 24))
{
found = TRUE;
}
}
crypt_md4(md4, nt_password_hash, NTLMSSP_KEY_LEN);
if (flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY) {
memcpy(challenges, serverchallenge, 8);
if(clientchallenge){
memcpy(challenges+8, clientchallenge, 8);
}
md5_hmac(challenges, NTLMSSP_KEY_LEN, md4, NTLMSSP_KEY_LEN, sessionbasekey);
}
else {
memcpy(sessionbasekey, md4, NTLMSSP_KEY_LEN);
}
}
if (!found) {
return;
}
get_keyexchange_key(keyexchangekey, sessionbasekey, lm_challenge_response, flags);
memset(sessionkey, 0, NTLMSSP_KEY_LEN);
if (flags & NTLMSSP_NEGOTIATE_KEY_EXCH)
{
if(encryptedsessionkey){
memcpy(sessionkey, encryptedsessionkey, NTLMSSP_KEY_LEN);
}
crypt_rc4_init(&rc4state, keyexchangekey, NTLMSSP_KEY_LEN);
crypt_rc4(&rc4state, sessionkey, NTLMSSP_KEY_LEN);
}
else
{
memcpy(sessionkey, keyexchangekey, NTLMSSP_KEY_LEN);
}
memcpy(ntlmssph->session_key, sessionkey, NTLMSSP_KEY_LEN);
}
static void
get_siging_key(guint8 *sign_key_server, guint8* sign_key_client, const guint8 key[NTLMSSP_KEY_LEN], int keylen)
{
md5_state_t md5state;
md5_state_t md5state2;
memset(sign_key_client, 0, NTLMSSP_KEY_LEN);
memset(sign_key_server, 0, NTLMSSP_KEY_LEN);
md5_init(&md5state);
md5_append(&md5state, key, keylen);
md5_append(&md5state, CLIENT_SIGN_TEXT, strlen(CLIENT_SIGN_TEXT)+1);
md5_finish(&md5state, sign_key_client);
md5_init(&md5state2);
md5_append(&md5state2, key, keylen);
md5_append(&md5state2, SERVER_SIGN_TEXT, strlen(SERVER_SIGN_TEXT)+1);
md5_finish(&md5state2, sign_key_server);
}
static void
get_sealing_rc4key(const guint8 exportedsessionkey[NTLMSSP_KEY_LEN] , const int flags , int *keylen ,
guint8 *clientsealkey , guint8 *serversealkey)
{
md5_state_t md5state;
md5_state_t md5state2;
memset(clientsealkey, 0, NTLMSSP_KEY_LEN);
memset(serversealkey, 0, NTLMSSP_KEY_LEN);
memcpy(clientsealkey, exportedsessionkey, NTLMSSP_KEY_LEN);
if (flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY)
{
if (flags & NTLMSSP_NEGOTIATE_128)
{
*keylen = 16;
}
else
{
if (flags & NTLMSSP_NEGOTIATE_56)
{
memset(clientsealkey+7, 0, 9);
*keylen = 7;
}
else
{
memset(clientsealkey+5, 0, 11);
*keylen = 5;
}
}
memcpy(serversealkey, clientsealkey, NTLMSSP_KEY_LEN);
md5_init(&md5state);
md5_append(&md5state, clientsealkey,*keylen);
md5_append(&md5state, CLIENT_SEAL_TEXT, strlen(CLIENT_SEAL_TEXT)+1);
md5_finish(&md5state, clientsealkey);
md5_init(&md5state2);
md5_append(&md5state2, serversealkey,*keylen);
md5_append(&md5state2, SERVER_SEAL_TEXT, strlen(SERVER_SEAL_TEXT)+1);
md5_finish(&md5state2, serversealkey);
}
else
{
if (flags & NTLMSSP_NEGOTIATE_128)
{
*keylen = 16;
}
else
{
*keylen = 8;
if (flags & NTLMSSP_NEGOTIATE_56)
{
memset(clientsealkey+7, 0, 9);
}
else
{
memset(clientsealkey+5, 0, 11);
clientsealkey[5]=0xe5;
clientsealkey[6]=0x38;
clientsealkey[7]=0xb0;
}
}
memcpy(serversealkey, clientsealkey,*keylen);
}
}
static int
dissect_ntlmssp_string (tvbuff_t *tvb, int offset,
proto_tree *ntlmssp_tree,
gboolean unicode_strings,
int string_hf, int *start, int *end,
const char **stringp)
{
proto_tree *tree = NULL;
proto_item *tf = NULL;
gint16 string_length = tvb_get_letohs(tvb, offset);
gint16 string_maxlen = tvb_get_letohs(tvb, offset+2);
gint32 string_offset = tvb_get_letohl(tvb, offset+4);
const char *string_text = NULL;
int result_length;
guint16 bc;
*start = (string_offset > offset+8 ? string_offset : (signed)tvb_reported_length(tvb));
if (0 == string_length) {
*end = *start;
if (ntlmssp_tree)
proto_tree_add_string(ntlmssp_tree, string_hf, tvb,
offset, 8, "NULL");
if (stringp != NULL)
*stringp = "";
return offset+8;
}
bc = result_length = string_length;
string_text = get_unicode_or_ascii_string(tvb, &string_offset,
unicode_strings, &result_length,
FALSE, TRUE, &bc);
if (stringp != NULL) {
if (!string_text) string_text = "";
*stringp = string_text;
}
if (ntlmssp_tree) {
tf = proto_tree_add_string(ntlmssp_tree, string_hf, tvb,
string_offset, result_length, string_text);
tree = proto_item_add_subtree(tf, ett_ntlmssp_string);
}
proto_tree_add_uint(tree, hf_ntlmssp_string_len,
tvb, offset, 2, string_length);
offset += 2;
proto_tree_add_uint(tree, hf_ntlmssp_string_maxlen,
tvb, offset, 2, string_maxlen);
offset += 2;
proto_tree_add_uint(tree, hf_ntlmssp_string_offset,
tvb, offset, 4, string_offset);
offset += 4;
*end = string_offset + string_length;
return offset;
}
static int
dissect_ntlmssp_blob (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *ntlmssp_tree, int offset,
int blob_hf, int *end, ntlmssp_blob *result)
{
proto_item *tf = NULL;
proto_tree *tree = NULL;
guint16 blob_length = tvb_get_letohs(tvb, offset);
guint16 blob_maxlen = tvb_get_letohs(tvb, offset+2);
guint32 blob_offset = tvb_get_letohl(tvb, offset+4);
if (0 == blob_length) {
*end = (blob_offset > ((guint)offset)+8 ? blob_offset : ((guint)offset)+8);
proto_tree_add_bytes_format_value(ntlmssp_tree, blob_hf, tvb, offset, 8, NULL, "Empty");
result->length = 0;
result->contents = NULL;
return offset+8;
}
if (ntlmssp_tree) {
tf = proto_tree_add_item (ntlmssp_tree, blob_hf, tvb,
blob_offset, blob_length, ENC_NA);
tree = proto_item_add_subtree(tf, ett_ntlmssp_blob);
}
proto_tree_add_uint(tree, hf_ntlmssp_blob_len,
tvb, offset, 2, blob_length);
offset += 2;
proto_tree_add_uint(tree, hf_ntlmssp_blob_maxlen,
tvb, offset, 2, blob_maxlen);
offset += 2;
proto_tree_add_uint(tree, hf_ntlmssp_blob_offset,
tvb, offset, 4, blob_offset);
offset += 4;
*end = blob_offset + blob_length;
if (blob_length < MAX_BLOB_SIZE) {
result->length = blob_length;
result->contents = (guint8 *)tvb_memdup(wmem_file_scope(), tvb, blob_offset, blob_length);
} else {
expert_add_info_format(pinfo, tf, &ei_ntlmssp_v2_key_too_long,
"NTLM v2 key is %d bytes long, too big for our %d buffer", blob_length, MAX_BLOB_SIZE);
result->length = 0;
result->contents = NULL;
}
if (blob_hf == hf_ntlmssp_auth_lmresponse) {
if (tvb_memeql(tvb, blob_offset+8, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", NTLMSSP_KEY_LEN) == 0) {
proto_tree_add_item (ntlmssp_tree,
hf_ntlmssp_ntlm_client_challenge,
tvb, blob_offset, 8, ENC_NA);
}
} else if (blob_hf == hf_ntlmssp_auth_ntresponse) {
if (blob_length > 24) {
dissect_ntlmv2_response(tvb, pinfo, tree, blob_offset, blob_length);
}
}
return offset;
}
static int
dissect_ntlmssp_version(tvbuff_t *tvb, int offset,
proto_tree *ntlmssp_tree)
{
if (ntlmssp_tree) {
proto_item *tf;
proto_tree *version_tree;
tf = proto_tree_add_none_format(ntlmssp_tree, hf_ntlmssp_version, tvb, offset, 8,
"Version %u.%u (Build %u); NTLM Current Revision %u",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset+1),
tvb_get_letohs(tvb, offset+2),
tvb_get_guint8(tvb, offset+7));
version_tree = proto_item_add_subtree (tf, ett_ntlmssp_version);
proto_tree_add_item(version_tree, hf_ntlmssp_version_major , tvb, offset , 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(version_tree, hf_ntlmssp_version_minor , tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(version_tree, hf_ntlmssp_version_build_number , tvb, offset+2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(version_tree, hf_ntlmssp_version_ntlm_current_revision, tvb, offset+7, 1, ENC_LITTLE_ENDIAN);
}
return offset+8;
}
static int
dissect_ntlmssp_target_info_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint32 target_info_offset, guint16 target_info_length,
tif_t *tif_p)
{
guint32 item_offset;
guint16 item_type = ~0;
guint16 item_length;
item_offset = target_info_offset;
while (item_offset < (target_info_offset + target_info_length) && (item_type != NTLM_TARGET_INFO_END)) {
proto_item *target_info_tf;
proto_tree *target_info_tree;
guint32 content_offset;
guint16 content_length;
guint32 type_offset;
guint32 len_offset;
const gchar *text = NULL;
int **hf_array_p = tif_p->hf_attr_array_p;
type_offset = item_offset;
item_type = tvb_get_letohs(tvb, type_offset);
len_offset = type_offset + 2;
content_length = tvb_get_letohs(tvb, len_offset);
content_offset = len_offset + 2;
item_length = content_length + 4;
target_info_tree = proto_tree_add_subtree_format(tree, tvb, item_offset, item_length, *tif_p->ett, &target_info_tf,
"Attribute: %s", val_to_str_ext(item_type, &ntlm_name_types_ext, "Unknown (%d)"));
proto_tree_add_item (target_info_tree, *tif_p->hf_item_type, tvb, type_offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item (target_info_tree, *tif_p->hf_item_length, tvb, len_offset, 2, ENC_LITTLE_ENDIAN);
if (content_length > 0) {
switch (item_type) {
case NTLM_TARGET_INFO_NB_COMPUTER_NAME:
case NTLM_TARGET_INFO_NB_DOMAIN_NAME:
case NTLM_TARGET_INFO_DNS_COMPUTER_NAME:
case NTLM_TARGET_INFO_DNS_DOMAIN_NAME:
case NTLM_TARGET_INFO_DNS_TREE_NAME:
case NTLM_TARGET_INFO_TARGET_NAME:
text = tvb_get_string_enc(wmem_packet_scope(), tvb, content_offset, content_length, ENC_UTF_16|ENC_LITTLE_ENDIAN);
proto_tree_add_string(target_info_tree, *hf_array_p[item_type], tvb, content_offset, content_length, text);
proto_item_append_text(target_info_tf, ": %s", text);
break;
case NTLM_TARGET_INFO_FLAGS:
proto_tree_add_item(target_info_tree, *hf_array_p[item_type], tvb, content_offset, content_length, ENC_LITTLE_ENDIAN);
break;
case NTLM_TARGET_INFO_TIMESTAMP:
dissect_nt_64bit_time(tvb, target_info_tree, content_offset, *hf_array_p[item_type]);
break;
case NTLM_TARGET_INFO_RESTRICTIONS:
case NTLM_TARGET_INFO_CHANNEL_BINDINGS:
proto_tree_add_item(target_info_tree, *hf_array_p[item_type], tvb, content_offset, content_length, ENC_NA);
break;
default:
proto_tree_add_expert(target_info_tree, pinfo, &ei_ntlmssp_target_info_attr,
tvb, content_offset, content_length);
break;
}
}
item_offset += item_length;
}
return item_offset;
}
int
dissect_ntlmv2_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int len)
{
proto_item *ntlmv2_item = NULL;
proto_tree *ntlmv2_tree = NULL;
const int orig_offset = offset;
if (tree) {
ntlmv2_item = proto_tree_add_item(
tree, hf_ntlmssp_ntlmv2_response, tvb,
offset, len, ENC_NA);
ntlmv2_tree = proto_item_add_subtree(
ntlmv2_item, ett_ntlmssp_ntlmv2_response);
}
proto_tree_add_item(
ntlmv2_tree, hf_ntlmssp_ntlmv2_response_ntproofstr, tvb,
offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(ntlmv2_tree, hf_ntlmssp_ntlmv2_response_rversion, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ntlmv2_tree, hf_ntlmssp_ntlmv2_response_hirversion, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(ntlmv2_tree, hf_ntlmssp_ntlmv2_response_z, tvb, offset, 6, ENC_NA);
offset += 6;
offset = dissect_nt_64bit_time(
tvb, ntlmv2_tree, offset, hf_ntlmssp_ntlmv2_response_time);
proto_tree_add_item(
ntlmv2_tree, hf_ntlmssp_ntlmv2_response_chal, tvb,
offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(ntlmv2_tree, hf_ntlmssp_ntlmv2_response_z, tvb, offset, 4, ENC_NA);
offset += 4;
offset = dissect_ntlmssp_target_info_list(tvb, pinfo, ntlmv2_tree, offset, len - (offset - orig_offset), &ntlmssp_ntlmv2_response_tif);
if ((offset - orig_offset) < len) {
proto_tree_add_item(ntlmv2_tree, hf_ntlmssp_ntlmv2_response_z, tvb, offset, 4, ENC_NA);
offset += 4;
}
if ((offset - orig_offset) < len) {
proto_tree_add_item(ntlmv2_tree, hf_ntlmssp_ntlmv2_response_pad, tvb, offset, len - (offset - orig_offset), ENC_NA);
}
return offset+len;
}
static int
dissect_ntlmssp_negotiate (tvbuff_t *tvb, int offset, proto_tree *ntlmssp_tree, ntlmssp_header_t *ntlmssph _U_)
{
guint32 negotiate_flags;
int data_start;
int data_end;
int item_start;
int item_end;
negotiate_flags = tvb_get_letohl (tvb, offset);
proto_tree_add_bitmask(ntlmssp_tree, tvb, offset, hf_ntlmssp_negotiate_flags, ett_ntlmssp_negotiate_flags, ntlmssp_negotiate_flags, ENC_LITTLE_ENDIAN);
offset += 4;
offset = dissect_ntlmssp_string(tvb, offset, ntlmssp_tree, FALSE,
hf_ntlmssp_negotiate_domain,
&data_start, &data_end, NULL);
offset = dissect_ntlmssp_string(tvb, offset, ntlmssp_tree, FALSE,
hf_ntlmssp_negotiate_workstation,
&item_start, &item_end, NULL);
data_start = MIN(data_start, item_start);
data_end = MAX(data_end, item_end);
if (offset < data_start) {
if (negotiate_flags & NTLMSSP_NEGOTIATE_VERSION)
dissect_ntlmssp_version(tvb, offset, ntlmssp_tree);
}
return data_end;
}
static int
dissect_ntlmssp_challenge_target_info_blob (packet_info *pinfo, tvbuff_t *tvb, int offset,
proto_tree *ntlmssp_tree,
int *end)
{
guint16 challenge_target_info_length = tvb_get_letohs(tvb, offset);
guint16 challenge_target_info_maxlen = tvb_get_letohs(tvb, offset+2);
guint32 challenge_target_info_offset = tvb_get_letohl(tvb, offset+4);
proto_item *tf = NULL;
proto_tree *challenge_target_info_tree = NULL;
if (0 == challenge_target_info_length) {
*end = (challenge_target_info_offset > ((guint)offset)+8 ? challenge_target_info_offset : ((guint)offset)+8);
proto_tree_add_none_format(ntlmssp_tree, hf_ntlmssp_challenge_target_info, tvb, offset, 8,
"Target Info List: Empty");
return offset+8;
}
if (ntlmssp_tree) {
tf = proto_tree_add_item (ntlmssp_tree, hf_ntlmssp_challenge_target_info, tvb,
challenge_target_info_offset, challenge_target_info_length, ENC_NA);
challenge_target_info_tree = proto_item_add_subtree(tf, ett_ntlmssp_challenge_target_info);
}
proto_tree_add_uint(challenge_target_info_tree, hf_ntlmssp_challenge_target_info_len,
tvb, offset, 2, challenge_target_info_length);
offset += 2;
proto_tree_add_uint(challenge_target_info_tree, hf_ntlmssp_challenge_target_info_maxlen,
tvb, offset, 2, challenge_target_info_maxlen);
offset += 2;
proto_tree_add_uint(challenge_target_info_tree, hf_ntlmssp_challenge_target_info_offset,
tvb, offset, 4, challenge_target_info_offset);
offset += 4;
dissect_ntlmssp_target_info_list(tvb, pinfo, challenge_target_info_tree,
challenge_target_info_offset, challenge_target_info_length,
&ntlmssp_challenge_target_info_tif);
*end = challenge_target_info_offset + challenge_target_info_length;
return offset;
}
static int
dissect_ntlmssp_challenge (tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *ntlmssp_tree, ntlmssp_header_t *ntlmssph _U_)
{
guint32 negotiate_flags;
int item_start, item_end;
int data_start, data_end;
guint8 clientkey[NTLMSSP_KEY_LEN];
guint8 serverkey[NTLMSSP_KEY_LEN];
ntlmssp_info *conv_ntlmssp_info = NULL;
conversation_t *conversation;
gboolean unicode_strings = FALSE;
guint8 tmp[8];
guint8 sspkey[NTLMSSP_KEY_LEN];
int ssp_key_len;
negotiate_flags = tvb_get_letohl (tvb, offset+8);
if (negotiate_flags & NTLMSSP_NEGOTIATE_UNICODE)
unicode_strings = TRUE;
offset = dissect_ntlmssp_string(tvb, offset, ntlmssp_tree, unicode_strings,
hf_ntlmssp_challenge_target_name,
&item_start, &item_end, NULL);
data_start = item_start;
data_end = item_end;
proto_tree_add_bitmask(ntlmssp_tree, tvb, offset, hf_ntlmssp_negotiate_flags, ett_ntlmssp_negotiate_flags, ntlmssp_negotiate_flags, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (ntlmssp_tree,
hf_ntlmssp_ntlm_server_challenge,
tvb, offset, 8, ENC_NA);
conversation = find_or_create_conversation(pinfo);
tvb_memcpy(tvb, tmp, offset, 8);
conv_ntlmssp_info = (ntlmssp_info *)conversation_get_proto_data(conversation, proto_ntlmssp);
if (!conv_ntlmssp_info || memcmp(tmp, conv_ntlmssp_info->server_challenge, 8) != 0) {
conv_ntlmssp_info = wmem_new0(wmem_file_scope(), ntlmssp_info);
conv_ntlmssp_info->flags = negotiate_flags;
tvb_memcpy(tvb, conv_ntlmssp_info->server_challenge, offset, 8);
conv_ntlmssp_info->is_auth_ntlm_v2 = 0;
if (!(conv_ntlmssp_info->flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY))
{
conv_ntlmssp_info->rc4_state_initialized = 0;
conv_ntlmssp_info->ntlm_response.contents = (guint8 *)wmem_alloc0(wmem_file_scope(), 24);
conv_ntlmssp_info->lm_response.contents = (guint8 *)wmem_alloc0(wmem_file_scope(), 24);
create_ntlmssp_v1_key(gbl_nt_password, conv_ntlmssp_info->server_challenge, NULL, sspkey, NULL, conv_ntlmssp_info->flags, conv_ntlmssp_info->ntlm_response.contents, conv_ntlmssp_info->lm_response.contents, ntlmssph);
if (memcmp(sspkey, gbl_zeros, NTLMSSP_KEY_LEN) != 0) {
get_sealing_rc4key(sspkey, conv_ntlmssp_info->flags, &ssp_key_len, clientkey, serverkey);
crypt_rc4_init(&conv_ntlmssp_info->rc4_state_client, sspkey, ssp_key_len);
crypt_rc4_init(&conv_ntlmssp_info->rc4_state_server, sspkey, ssp_key_len);
conv_ntlmssp_info->server_dest_port = pinfo->destport;
conv_ntlmssp_info->rc4_state_initialized = 1;
}
}
conversation_add_proto_data(conversation, proto_ntlmssp, conv_ntlmssp_info);
}
offset += 8;
if (offset >= data_start) {
return data_end;
}
proto_tree_add_item (ntlmssp_tree, hf_ntlmssp_reserved,
tvb, offset, 8, ENC_NA);
offset += 8;
if (offset < data_start) {
offset = dissect_ntlmssp_challenge_target_info_blob(pinfo, tvb, offset, ntlmssp_tree, &item_end);
data_end = MAX(data_end, item_end);
}
if (offset < data_start) {
if (negotiate_flags & NTLMSSP_NEGOTIATE_VERSION)
offset = dissect_ntlmssp_version(tvb, offset, ntlmssp_tree);
}
return MAX(offset, data_end);
}
static int
dissect_ntlmssp_auth (tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *ntlmssp_tree, ntlmssp_header_t *ntlmssph)
{
int item_start, item_end;
int data_start, data_end = 0;
guint32 negotiate_flags;
guint8 sspkey[NTLMSSP_KEY_LEN];
guint8 clientkey[NTLMSSP_KEY_LEN];
guint8 serverkey[NTLMSSP_KEY_LEN];
guint8 encryptedsessionkey[NTLMSSP_KEY_LEN];
ntlmssp_blob sessionblob;
gboolean unicode_strings = FALSE;
ntlmssp_info *conv_ntlmssp_info;
conversation_t *conversation;
int ssp_key_len;
conv_ntlmssp_info = (ntlmssp_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ntlmssp, NTLMSSP_CONV_INFO_KEY);
if (conv_ntlmssp_info == NULL) {
conversation = find_or_create_conversation(pinfo);
conv_ntlmssp_info = (ntlmssp_info *)conversation_get_proto_data(conversation, proto_ntlmssp);
if (conv_ntlmssp_info == NULL) {
conv_ntlmssp_info = wmem_new0(wmem_file_scope(), ntlmssp_info);
conversation_add_proto_data(conversation, proto_ntlmssp, conv_ntlmssp_info);
}
p_add_proto_data(wmem_file_scope(), pinfo, proto_ntlmssp, NTLMSSP_CONV_INFO_KEY, conv_ntlmssp_info);
}
if (conv_ntlmssp_info != NULL) {
if (conv_ntlmssp_info->flags & NTLMSSP_NEGOTIATE_UNICODE)
unicode_strings = TRUE;
}
data_start = tvb_get_letohl(tvb, offset+4);
offset = dissect_ntlmssp_blob(tvb, pinfo, ntlmssp_tree, offset,
hf_ntlmssp_auth_lmresponse,
&item_end,
conv_ntlmssp_info == NULL ? NULL :
&conv_ntlmssp_info->lm_response);
data_end = MAX(data_end, item_end);
item_start = tvb_get_letohl(tvb, offset+4);
offset = dissect_ntlmssp_blob(tvb, pinfo, ntlmssp_tree, offset,
hf_ntlmssp_auth_ntresponse,
&item_end,
conv_ntlmssp_info == NULL ? NULL :
&conv_ntlmssp_info->ntlm_response);
data_start = MIN(data_start, item_start);
data_end = MAX(data_end, item_end);
if (conv_ntlmssp_info != NULL)
{
if (conv_ntlmssp_info->ntlm_response.length > 24)
{
conv_ntlmssp_info->is_auth_ntlm_v2 = 1;
if (conv_ntlmssp_info->ntlm_response.length >= 32) {
memcpy(conv_ntlmssp_info->client_challenge, conv_ntlmssp_info->ntlm_response.contents+24, 8);
}
}
else
{
conv_ntlmssp_info->is_auth_ntlm_v2 = 0;
}
}
item_start = tvb_get_letohl(tvb, offset+4);
offset = dissect_ntlmssp_string(tvb, offset, ntlmssp_tree,
unicode_strings,
hf_ntlmssp_auth_domain,
&item_start, &item_end, &(ntlmssph->domain_name));
data_start = MIN(data_start, item_start);
data_end = MAX(data_end, item_end);
item_start = tvb_get_letohl(tvb, offset+4);
offset = dissect_ntlmssp_string(tvb, offset, ntlmssp_tree,
unicode_strings,
hf_ntlmssp_auth_username,
&item_start, &item_end, &(ntlmssph->acct_name));
data_start = MIN(data_start, item_start);
data_end = MAX(data_end, item_end);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ", "User: %s\\%s",
ntlmssph->domain_name, ntlmssph->acct_name);
item_start = tvb_get_letohl(tvb, offset+4);
offset = dissect_ntlmssp_string(tvb, offset, ntlmssp_tree,
unicode_strings,
hf_ntlmssp_auth_hostname,
&item_start, &item_end, &(ntlmssph->host_name));
data_start = MIN(data_start, item_start);
data_end = MAX(data_end, item_end);
sessionblob.length = 0;
if (offset < data_start) {
offset = dissect_ntlmssp_blob(tvb, pinfo, ntlmssp_tree, offset,
hf_ntlmssp_auth_sesskey,
&item_end, &sessionblob);
data_end = MAX(data_end, item_end);
}
if (offset < data_start) {
negotiate_flags = tvb_get_letohl (tvb, offset);
proto_tree_add_bitmask(ntlmssp_tree, tvb, offset, hf_ntlmssp_negotiate_flags, ett_ntlmssp_negotiate_flags, ntlmssp_negotiate_flags, ENC_LITTLE_ENDIAN);
offset += 4;
if ((conv_ntlmssp_info != NULL) && (conv_ntlmssp_info->flags == 0)) {
conv_ntlmssp_info->flags = negotiate_flags;
}
} else
negotiate_flags = 0;
if (offset < data_start) {
if (negotiate_flags & NTLMSSP_NEGOTIATE_VERSION)
offset = dissect_ntlmssp_version(tvb, offset, ntlmssp_tree);
}
if (offset < data_start) {
proto_tree_add_item(ntlmssp_tree, hf_ntlmssp_message_integrity_code, tvb, offset, 16, ENC_NA);
offset += 16;
}
if (sessionblob.length > NTLMSSP_KEY_LEN) {
expert_add_info_format(pinfo, NULL, &ei_ntlmssp_blob_len_too_long, "Session blob length too long: %u", sessionblob.length);
} else if (sessionblob.length != 0) {
memcpy(encryptedsessionkey, sessionblob.contents, sessionblob.length);
if (conv_ntlmssp_info) {
if ((conv_ntlmssp_info->flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY))
{
conv_ntlmssp_info->rc4_state_initialized = 0;
if (conv_ntlmssp_info->is_auth_ntlm_v2) {
create_ntlmssp_v2_key(gbl_nt_password, conv_ntlmssp_info->server_challenge, conv_ntlmssp_info->client_challenge, sspkey, encryptedsessionkey, conv_ntlmssp_info->flags, &conv_ntlmssp_info->ntlm_response, &conv_ntlmssp_info->lm_response, ntlmssph);
}
else
{
if (conv_ntlmssp_info->lm_response.contents == NULL || conv_ntlmssp_info->lm_response.length < 8) {
memset(conv_ntlmssp_info->client_challenge, 0, 8);
} else {
memcpy(conv_ntlmssp_info->client_challenge, conv_ntlmssp_info->lm_response.contents, 8);
}
create_ntlmssp_v1_key(gbl_nt_password, conv_ntlmssp_info->server_challenge, conv_ntlmssp_info->client_challenge, sspkey, encryptedsessionkey, conv_ntlmssp_info->flags, conv_ntlmssp_info->ntlm_response.contents, conv_ntlmssp_info->lm_response.contents, ntlmssph);
}
if (memcmp(sspkey, gbl_zeros, NTLMSSP_KEY_LEN) != 0) {
get_sealing_rc4key(sspkey, conv_ntlmssp_info->flags, &ssp_key_len, clientkey, serverkey);
get_siging_key((guint8*)&conv_ntlmssp_info->sign_key_server, (guint8*)&conv_ntlmssp_info->sign_key_client, sspkey, ssp_key_len);
crypt_rc4_init(&conv_ntlmssp_info->rc4_state_server, serverkey, ssp_key_len);
crypt_rc4_init(&conv_ntlmssp_info->rc4_state_client, clientkey, ssp_key_len);
conv_ntlmssp_info->server_dest_port = pinfo->destport;
conv_ntlmssp_info->rc4_state_initialized = 1;
}
}
}
}
return MAX(offset, data_end);
}
static guint8*
get_sign_key(packet_info *pinfo, int cryptpeer)
{
conversation_t *conversation;
ntlmssp_info *conv_ntlmssp_info;
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation == NULL) {
return NULL;
}
else {
conv_ntlmssp_info = (ntlmssp_info *)conversation_get_proto_data(conversation,
proto_ntlmssp);
if (conv_ntlmssp_info == NULL) {
return NULL;
}
else {
if (cryptpeer == 1) {
return (guint8*)&conv_ntlmssp_info->sign_key_client;
} else {
return (guint8*)&conv_ntlmssp_info->sign_key_server;
}
}
}
}
static rc4_state_struct *
get_encrypted_state(packet_info *pinfo, int cryptpeer)
{
conversation_t *conversation;
ntlmssp_info *conv_ntlmssp_info;
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation == NULL) {
return NULL;
}
else {
conv_ntlmssp_info = (ntlmssp_info *)conversation_get_proto_data(conversation,
proto_ntlmssp);
if (conv_ntlmssp_info == NULL) {
return NULL;
}
else {
if (cryptpeer == 1) {
return &conv_ntlmssp_info->rc4_state_client;
} else {
return &conv_ntlmssp_info->rc4_state_server;
}
}
}
}
static int
dissect_ntlmssp_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
volatile int offset = 0;
proto_tree *volatile ntlmssp_tree = NULL;
proto_item *tf = NULL;
guint32 length;
guint32 encrypted_block_length;
guint8 key[NTLMSSP_KEY_LEN];
guint32 ntlm_magic_size = 4;
guint32 ntlm_signature_size = 8;
guint32 ntlm_seq_size = 4;
length = tvb_captured_length (tvb);
encrypted_block_length = length - ntlm_magic_size;
if (encrypted_block_length < (ntlm_signature_size + ntlm_seq_size)) {
return offset + length;
}
if (tree) {
tf = proto_tree_add_item (tree,
hf_ntlmssp_verf,
tvb, offset, -1, ENC_NA);
ntlmssp_tree = proto_item_add_subtree (tf,
ett_ntlmssp);
}
TRY {
proto_tree_add_item (ntlmssp_tree, hf_ntlmssp_verf_vers,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (ntlmssp_tree, hf_ntlmssp_verf_body,
tvb, offset, ntlm_signature_size + ntlm_seq_size, ENC_NA);
memset(key, 0, sizeof(key));
tvb_memcpy(tvb, key, offset, ntlm_signature_size + ntlm_seq_size);
decrypt_data_payload (tvb, offset+(ntlm_signature_size + ntlm_seq_size), encrypted_block_length-(ntlm_signature_size + ntlm_seq_size), pinfo, ntlmssp_tree, key);
decrypt_verifier (tvb, offset, ntlm_signature_size + ntlm_seq_size, pinfo, ntlmssp_tree, key);
offset += 12;
} CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
return offset;
}
static tvbuff_t*
decrypt_data_payload(tvbuff_t *tvb, int offset, guint32 encrypted_block_length,
packet_info *pinfo, proto_tree *tree _U_, gpointer key)
{
tvbuff_t *decr_tvb;
ntlmssp_packet_info *packet_ntlmssp_info;
ntlmssp_packet_info *stored_packet_ntlmssp_info = NULL;
packet_ntlmssp_info = (ntlmssp_packet_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ntlmssp, NTLMSSP_PACKET_INFO_KEY);
if (packet_ntlmssp_info == NULL) {
packet_ntlmssp_info = wmem_new0(wmem_file_scope(), ntlmssp_packet_info);
p_add_proto_data(wmem_file_scope(), pinfo, proto_ntlmssp, NTLMSSP_PACKET_INFO_KEY, packet_ntlmssp_info);
}
if (!packet_ntlmssp_info->payload_decrypted) {
conversation_t *conversation;
ntlmssp_info *conv_ntlmssp_info;
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation == NULL) {
return NULL;
}
conv_ntlmssp_info = (ntlmssp_info *)conversation_get_proto_data(conversation,
proto_ntlmssp);
if (conv_ntlmssp_info == NULL) {
return NULL;
}
if (conv_ntlmssp_info->rc4_state_initialized != 1) {
return NULL;
}
if (key != NULL) {
stored_packet_ntlmssp_info = (ntlmssp_packet_info *)g_hash_table_lookup(hash_packet, key);
}
if (stored_packet_ntlmssp_info != NULL && stored_packet_ntlmssp_info->payload_decrypted == TRUE) {
memcpy(packet_ntlmssp_info, stored_packet_ntlmssp_info, sizeof(ntlmssp_packet_info));
}
else {
rc4_state_struct *rc4_state;
rc4_state_struct *rc4_state_peer;
if (conv_ntlmssp_info->server_dest_port == pinfo->destport) {
rc4_state = get_encrypted_state(pinfo, 1);
rc4_state_peer = get_encrypted_state(pinfo, 0);
} else {
rc4_state = get_encrypted_state(pinfo, 0);
rc4_state_peer = get_encrypted_state(pinfo, 1);
}
if (rc4_state == NULL) {
return NULL;
}
packet_ntlmssp_info->decrypted_payload = (guint8 *)tvb_memdup(wmem_file_scope(), tvb, offset,
encrypted_block_length);
packet_ntlmssp_info->payload_len = encrypted_block_length;
decrypted_payloads = g_slist_prepend(decrypted_payloads,
packet_ntlmssp_info->decrypted_payload);
if (key != NULL) {
g_hash_table_insert(hash_packet, key, packet_ntlmssp_info);
}
crypt_rc4(rc4_state, packet_ntlmssp_info->decrypted_payload,
encrypted_block_length);
if (!(NTLMSSP_NEGOTIATE_KEY_EXCH & conv_ntlmssp_info->flags)) {
guint8 *peer_block;
peer_block = (guint8 *)wmem_memdup(wmem_packet_scope(), packet_ntlmssp_info->decrypted_payload, encrypted_block_length);
crypt_rc4(rc4_state_peer, peer_block, encrypted_block_length);
}
packet_ntlmssp_info->payload_decrypted = TRUE;
}
}
decr_tvb = tvb_new_child_real_data(tvb, packet_ntlmssp_info->decrypted_payload,
encrypted_block_length,
encrypted_block_length);
add_new_data_source(pinfo, decr_tvb,
"Decrypted data");
return decr_tvb;
}
static int
dissect_ntlmssp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
volatile int offset = 0;
proto_tree *volatile ntlmssp_tree = NULL;
proto_item *tf, *type_item;
ntlmssp_header_t *ntlmssph;
ntlmssph = wmem_new(wmem_packet_scope(), ntlmssp_header_t);
ntlmssph->type = 0;
ntlmssph->domain_name = NULL;
ntlmssph->acct_name = NULL;
ntlmssph->host_name = NULL;
memset(ntlmssph->session_key, 0, NTLMSSP_KEY_LEN);
tf = proto_tree_add_item (tree,
proto_ntlmssp,
tvb, offset, -1, ENC_NA);
ntlmssp_tree = proto_item_add_subtree (tf, ett_ntlmssp);
TRY {
proto_tree_add_item (ntlmssp_tree, hf_ntlmssp_auth,
tvb, offset, 8, ENC_ASCII|ENC_NA);
offset += 8;
type_item = proto_tree_add_item (ntlmssp_tree, hf_ntlmssp_message_type,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
ntlmssph->type = tvb_get_letohl (tvb, offset);
offset += 4;
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ", ", "%s",
val_to_str_const(ntlmssph->type,
ntlmssp_message_types,
"Unknown NTLMSSP message type"));
switch (ntlmssph->type) {
case NTLMSSP_NEGOTIATE:
dissect_ntlmssp_negotiate (tvb, offset, ntlmssp_tree, ntlmssph);
break;
case NTLMSSP_CHALLENGE:
dissect_ntlmssp_challenge (tvb, pinfo, offset, ntlmssp_tree, ntlmssph);
break;
case NTLMSSP_AUTH:
dissect_ntlmssp_auth (tvb, pinfo, offset, ntlmssp_tree, ntlmssph);
break;
default:
expert_add_info(pinfo, type_item, &ei_ntlmssp_message_type);
break;
}
} CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
tap_queue_packet(ntlmssp_tap, pinfo, ntlmssph);
return tvb_captured_length(tvb);
}
static gboolean
dissect_ntlmssp_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
if (tvb_memeql(tvb, 0, "NTLMSSP", 8) == 0) {
dissect_ntlmssp(tvb, pinfo, parent_tree, data);
return TRUE;
}
return FALSE;
}
static void
decrypt_verifier(tvbuff_t *tvb, int offset, guint32 encrypted_block_length,
packet_info *pinfo, proto_tree *tree, gpointer key)
{
proto_tree *decr_tree;
conversation_t *conversation;
guint8* sign_key;
rc4_state_struct *rc4_state;
rc4_state_struct *rc4_state_peer;
tvbuff_t *decr_tvb;
guint8 *peer_block;
guint8 *check_buf;
guint8 calculated_md5[NTLMSSP_KEY_LEN];
ntlmssp_info *conv_ntlmssp_info;
ntlmssp_packet_info *packet_ntlmssp_info;
int decrypted_offset = 0;
int sequence = 0;
ntlmssp_packet_info *stored_packet_ntlmssp_info = NULL;
packet_ntlmssp_info = (ntlmssp_packet_info *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ntlmssp, NTLMSSP_PACKET_INFO_KEY);
if (packet_ntlmssp_info == NULL) {
return;
}
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation == NULL) {
return;
}
conv_ntlmssp_info = (ntlmssp_info *)conversation_get_proto_data(conversation,
proto_ntlmssp);
if (conv_ntlmssp_info == NULL) {
return;
}
if (key != NULL) {
stored_packet_ntlmssp_info = (ntlmssp_packet_info *)g_hash_table_lookup(hash_packet, key);
}
if (stored_packet_ntlmssp_info != NULL && stored_packet_ntlmssp_info->verifier_decrypted == TRUE) {
packet_ntlmssp_info = stored_packet_ntlmssp_info;
}
else {
if (!packet_ntlmssp_info->verifier_decrypted) {
if (conv_ntlmssp_info->rc4_state_initialized != 1) {
return;
}
if (conv_ntlmssp_info->server_dest_port == pinfo->destport) {
rc4_state = get_encrypted_state(pinfo, 1);
sign_key = get_sign_key(pinfo, 1);
rc4_state_peer = get_encrypted_state(pinfo, 0);
} else {
rc4_state = get_encrypted_state(pinfo, 0);
sign_key = get_sign_key(pinfo, 0);
rc4_state_peer = get_encrypted_state(pinfo, 1);
}
if (rc4_state == NULL || rc4_state_peer == NULL) {
return;
}
tvb_memcpy(tvb, packet_ntlmssp_info->verifier,
offset, MIN(encrypted_block_length, sizeof(packet_ntlmssp_info->verifier)));
if (conv_ntlmssp_info->flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY) {
if ((NTLMSSP_NEGOTIATE_KEY_EXCH & conv_ntlmssp_info->flags)) {
crypt_rc4(rc4_state, packet_ntlmssp_info->verifier, 8);
}
if (sign_key != NULL) {
check_buf = (guint8 *)wmem_alloc(wmem_packet_scope(), packet_ntlmssp_info->payload_len+4);
tvb_memcpy(tvb, &sequence, offset+8, 4);
memcpy(check_buf, &sequence, 4);
memcpy(check_buf+4, packet_ntlmssp_info->decrypted_payload, packet_ntlmssp_info->payload_len);
md5_hmac(check_buf, (int)(packet_ntlmssp_info->payload_len+4), sign_key, NTLMSSP_KEY_LEN, calculated_md5);
}
}
else {
crypt_rc4(rc4_state, packet_ntlmssp_info->verifier,
encrypted_block_length);
}
if (!(NTLMSSP_NEGOTIATE_KEY_EXCH & conv_ntlmssp_info->flags) && !(NTLMSSP_NEGOTIATE_EXTENDED_SECURITY & conv_ntlmssp_info->flags)) {
peer_block = (guint8 *)wmem_memdup(wmem_packet_scope(), packet_ntlmssp_info->verifier, encrypted_block_length);
crypt_rc4(rc4_state_peer, peer_block, encrypted_block_length);
}
packet_ntlmssp_info->verifier_decrypted = TRUE;
}
}
decr_tvb = tvb_new_child_real_data(tvb, packet_ntlmssp_info->verifier,
encrypted_block_length,
encrypted_block_length);
add_new_data_source(pinfo, decr_tvb,
"Decrypted NTLMSSP Verifier");
decr_tree = proto_tree_add_subtree_format(tree, decr_tvb, 0, -1,
ett_ntlmssp, NULL,
"Decrypted Verifier (%d byte%s)",
encrypted_block_length,
plurality(encrypted_block_length, "", "s"));
if (( conv_ntlmssp_info->flags & NTLMSSP_NEGOTIATE_EXTENDED_SECURITY)) {
proto_tree_add_item (decr_tree, hf_ntlmssp_verf_hmacmd5,
decr_tvb, decrypted_offset, 8, ENC_NA);
decrypted_offset += 8;
proto_tree_add_item (decr_tree, hf_ntlmssp_verf_sequence,
decr_tvb, decrypted_offset, 4, ENC_NA);
}
else {
proto_tree_add_item (decr_tree, hf_ntlmssp_verf_randompad,
decr_tvb, decrypted_offset, 4, ENC_LITTLE_ENDIAN);
decrypted_offset += 4;
proto_tree_add_item (decr_tree, hf_ntlmssp_verf_crc32,
decr_tvb, decrypted_offset, 4, ENC_LITTLE_ENDIAN);
decrypted_offset += 4;
proto_tree_add_item (decr_tree, hf_ntlmssp_verf_sequence,
decr_tvb, decrypted_offset, 4, ENC_NA);
}
}
static int
dissect_ntlmssp_payload_only(tvbuff_t *tvb, packet_info *pinfo, _U_ proto_tree *tree, void *data)
{
volatile int offset = 0;
proto_tree *volatile ntlmssp_tree = NULL;
guint32 encrypted_block_length;
tvbuff_t *volatile decr_tvb;
tvbuff_t** ret_decr_tvb = (tvbuff_t**)data;
if (ret_decr_tvb)
*ret_decr_tvb = NULL;
encrypted_block_length = tvb_captured_length (tvb);
#if 0
if (tree) {
tf = proto_tree_add_item (tree,
hf_ntlmssp_verf,
tvb, offset, -1, ENC_NA);
ntlmssp_tree = proto_item_add_subtree (tf,
ett_ntlmssp);
}
#endif
TRY {
decr_tvb = decrypt_data_payload (tvb, offset, encrypted_block_length, pinfo, ntlmssp_tree, NULL);
if (ret_decr_tvb)
*ret_decr_tvb = decr_tvb;
} CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
return offset;
}
static int
dissect_ntlmssp_verf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
volatile int offset = 0;
proto_tree *volatile ntlmssp_tree = NULL;
proto_item *tf = NULL;
guint32 verifier_length;
guint32 encrypted_block_length;
verifier_length = tvb_captured_length (tvb);
encrypted_block_length = verifier_length - 4;
if (encrypted_block_length < 12) {
return offset + verifier_length;
}
if (tree) {
tf = proto_tree_add_item (tree,
hf_ntlmssp_verf,
tvb, offset, -1, ENC_NA);
ntlmssp_tree = proto_item_add_subtree (tf,
ett_ntlmssp);
}
TRY {
proto_tree_add_item (ntlmssp_tree, hf_ntlmssp_verf_vers,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item (ntlmssp_tree, hf_ntlmssp_verf_body,
tvb, offset, encrypted_block_length, ENC_NA);
decrypt_verifier (tvb, offset, encrypted_block_length, pinfo, ntlmssp_tree, NULL);
offset += 12;
offset += encrypted_block_length;
} CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
return offset;
}
static tvbuff_t *
wrap_dissect_ntlmssp_payload_only(tvbuff_t *tvb, tvbuff_t *auth_tvb _U_,
int offset, packet_info *pinfo, dcerpc_auth_info *auth_info _U_)
{
tvbuff_t *data_tvb, *decrypted_tvb;
data_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_ntlmssp_payload_only(data_tvb, pinfo, NULL, &decrypted_tvb);
return decrypted_tvb;
}
static guint
header_hash(gconstpointer pointer)
{
guint32 crc = ~crc32c_calculate(pointer, NTLMSSP_KEY_LEN, CRC32C_PRELOAD);
return crc;
}
static gboolean
header_equal(gconstpointer pointer1, gconstpointer pointer2)
{
if (!memcmp(pointer1, pointer2, 16)) {
return TRUE;
}
else {
return FALSE;
}
}
static void
ntlmssp_init_protocol(void)
{
hash_packet = g_hash_table_new(header_hash, header_equal);
}
static void
ntlmssp_cleanup_protocol(void)
{
if (decrypted_payloads != NULL) {
g_slist_free(decrypted_payloads);
decrypted_payloads = NULL;
}
g_hash_table_destroy(hash_packet);
}
static int
wrap_dissect_ntlmssp(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di _U_, guint8 *drep _U_)
{
tvbuff_t *auth_tvb;
auth_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_ntlmssp(auth_tvb, pinfo, tree, NULL);
return tvb_captured_length_remaining(tvb, offset);
}
static int
wrap_dissect_ntlmssp_verf(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di _U_, guint8 *drep _U_)
{
tvbuff_t *auth_tvb;
auth_tvb = tvb_new_subset_remaining(tvb, offset);
return dissect_ntlmssp_verf(auth_tvb, pinfo, tree, NULL);
}
void
proto_register_ntlmssp(void)
{
static hf_register_info hf[] = {
{ &hf_ntlmssp_auth,
{ "NTLMSSP identifier", "ntlmssp.identifier",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_message_type,
{ "NTLM Message Type", "ntlmssp.messagetype",
FT_UINT32, BASE_HEX, VALS(ntlmssp_message_types), 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags,
{ "Negotiate Flags", "ntlmssp.negotiateflags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_01,
{ "Negotiate UNICODE", "ntlmssp.negotiateunicode",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_UNICODE,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_02,
{ "Negotiate OEM", "ntlmssp.negotiateoem",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_OEM,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_04,
{ "Request Target", "ntlmssp.requesttarget",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_REQUEST_TARGET,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_08,
{ "Request 0x00000008", "ntlmssp.negotiate00000008",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_00000008,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_10,
{ "Negotiate Sign", "ntlmssp.negotiatesign",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_SIGN,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_20,
{ "Negotiate Seal", "ntlmssp.negotiateseal",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_SEAL,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_40,
{ "Negotiate Datagram", "ntlmssp.negotiatedatagram",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_DATAGRAM,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_80,
{ "Negotiate Lan Manager Key", "ntlmssp.negotiatelmkey",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_LM_KEY,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_100,
{ "Negotiate 0x00000100", "ntlmssp.negotiate00000100",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_00000100,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_200,
{ "Negotiate NTLM key", "ntlmssp.negotiatentlm",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_NTLM,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_400,
{ "Negotiate NT Only", "ntlmssp.negotiatentonly",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_NT_ONLY,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_800,
{ "Negotiate Anonymous", "ntlmssp.negotiateanonymous",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_ANONYMOUS,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_1000,
{ "Negotiate OEM Domain Supplied", "ntlmssp.negotiateoemdomainsupplied",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_OEM_DOMAIN_SUPPLIED,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_2000,
{ "Negotiate OEM Workstation Supplied", "ntlmssp.negotiateoemworkstationsupplied",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_OEM_WORKSTATION_SUPPLIED,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_4000,
{ "Negotiate 0x00004000", "ntlmssp.negotiate00004000",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_00004000,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_8000,
{ "Negotiate Always Sign", "ntlmssp.negotiatealwayssign",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_ALWAYS_SIGN,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_10000,
{ "Target Type Domain", "ntlmssp.targettypedomain",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_TARGET_TYPE_DOMAIN,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_20000,
{ "Target Type Server", "ntlmssp.targettypeserver",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_TARGET_TYPE_SERVER,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_40000,
{ "Target Type Share", "ntlmssp.targettypeshare",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_TARGET_TYPE_SHARE,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_80000,
{ "Negotiate Extended Security", "ntlmssp.negotiatentlm2",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_EXTENDED_SECURITY,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_100000,
{ "Negotiate Identify", "ntlmssp.negotiateidentify",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_IDENTIFY,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_200000,
{ "Negotiate 0x00200000", "ntlmssp.negotiatent00200000",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_00200000,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_400000,
{ "Request Non-NT Session", "ntlmssp.requestnonntsession",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_REQUEST_NON_NT_SESSION,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_800000,
{ "Negotiate Target Info", "ntlmssp.negotiatetargetinfo",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_TARGET_INFO,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_1000000,
{ "Negotiate 0x01000000", "ntlmssp.negotiatent01000000",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_01000000,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_2000000,
{ "Negotiate Version", "ntlmssp.negotiateversion",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_VERSION,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_4000000,
{ "Negotiate 0x04000000", "ntlmssp.negotiatent04000000",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_04000000,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_8000000,
{ "Negotiate 0x08000000", "ntlmssp.negotiatent08000000",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_08000000,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_10000000,
{ "Negotiate 0x10000000", "ntlmssp.negotiatent10000000",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_10000000,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_20000000,
{ "Negotiate 128", "ntlmssp.negotiate128",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_128,
"128-bit encryption is supported", HFILL }
},
{ &hf_ntlmssp_negotiate_flags_40000000,
{ "Negotiate Key Exchange", "ntlmssp.negotiatekeyexch",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_KEY_EXCH,
NULL, HFILL }
},
{ &hf_ntlmssp_negotiate_flags_80000000,
{ "Negotiate 56", "ntlmssp.negotiate56",
FT_BOOLEAN, 32, TFS (&tfs_set_notset), NTLMSSP_NEGOTIATE_56,
"56-bit encryption is supported", HFILL }
},
#if 0
{ &hf_ntlmssp_negotiate_workstation_strlen,
{ "Calling workstation name length", "ntlmssp.negotiate.callingworkstation.strlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
#if 0
{ &hf_ntlmssp_negotiate_workstation_maxlen,
{ "Calling workstation name max length", "ntlmssp.negotiate.callingworkstation.maxlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
#if 0
{ &hf_ntlmssp_negotiate_workstation_buffer,
{ "Calling workstation name buffer", "ntlmssp.negotiate.callingworkstation.buffer",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_ntlmssp_negotiate_workstation,
{ "Calling workstation name", "ntlmssp.negotiate.callingworkstation",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_ntlmssp_negotiate_domain_strlen,
{ "Calling workstation domain length", "ntlmssp.negotiate.domain.strlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
#if 0
{ &hf_ntlmssp_negotiate_domain_maxlen,
{ "Calling workstation domain max length", "ntlmssp.negotiate.domain.maxlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#endif
#if 0
{ &hf_ntlmssp_negotiate_domain_buffer,
{ "Calling workstation domain buffer", "ntlmssp.negotiate.domain.buffer",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_ntlmssp_negotiate_domain,
{ "Calling workstation domain", "ntlmssp.negotiate.domain",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlm_client_challenge,
{ "LMv2 Client Challenge", "ntlmssp.ntlmclientchallenge",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The 8-byte LMv2 challenge message generated by the client", HFILL }
},
{ &hf_ntlmssp_ntlm_server_challenge,
{ "NTLM Server Challenge", "ntlmssp.ntlmserverchallenge",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_reserved,
{ "Reserved", "ntlmssp.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_name,
{ "Target Name", "ntlmssp.challenge.target_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_auth_domain,
{ "Domain name", "ntlmssp.auth.domain",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_auth_username,
{ "User name", "ntlmssp.auth.username",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_auth_hostname,
{ "Host name", "ntlmssp.auth.hostname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_auth_lmresponse,
{ "Lan Manager Response", "ntlmssp.auth.lmresponse",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_auth_ntresponse,
{ "NTLM Response", "ntlmssp.auth.ntresponse",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_auth_sesskey,
{ "Session Key", "ntlmssp.auth.sesskey",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_string_len,
{ "Length", "ntlmssp.string.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_string_maxlen,
{ "Maxlen", "ntlmssp.string.maxlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_string_offset,
{ "Offset", "ntlmssp.string.offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_blob_len,
{ "Length", "ntlmssp.blob.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_blob_maxlen,
{ "Maxlen", "ntlmssp.blob.maxlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_blob_offset,
{ "Offset", "ntlmssp.blob.offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_version,
{ "Version", "ntlmssp.version",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_version_major,
{ "Major Version", "ntlmssp.version.major",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_version_minor,
{ "Minor Version", "ntlmssp.version.minor",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_version_build_number,
{ "Build Number", "ntlmssp.version.build_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_version_ntlm_current_revision,
{ "NTLM Current Revision", "ntlmssp.version.ntlm_current_revision",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_challenge_target_info,
{ "Target Info", "ntlmssp.challenge.target_info",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_challenge_target_info_len,
{ "Length", "ntlmssp.challenge.target_info.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_challenge_target_info_maxlen,
{ "Maxlen", "ntlmssp.challenge.target_info.maxlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_challenge_target_info_offset,
{ "Offset", "ntlmssp.challenge.target_info.offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_challenge_target_info_item_type,
{ "Target Info Item Type", "ntlmssp.challenge.target_info.item.type",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &ntlm_name_types_ext, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_item_len,
{ "Target Info Item Length", "ntlmssp.challenge.target_info.item.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_challenge_target_info_end,
{ "List End", "ntlmssp.challenge.target_info.end",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_nb_computer_name,
{ "NetBIOS Computer Name", "ntlmssp.challenge.target_info.nb_computer_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Server NetBIOS Computer Name", HFILL }
},
{ &hf_ntlmssp_challenge_target_info_nb_domain_name,
{ "NetBIOS Domain Name", "ntlmssp.challenge.target_info.nb_domain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Server NetBIOS Domain Name", HFILL }
},
{ &hf_ntlmssp_challenge_target_info_dns_computer_name,
{ "DNS Computer Name", "ntlmssp.challenge.target_info.dns_computer_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_dns_domain_name,
{ "DNS Domain Name", "ntlmssp.challenge.target_info.dns_domain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_dns_tree_name,
{ "DNS Tree Name", "ntlmssp.challenge.target_info.dns_tree_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_flags,
{ "Flags", "ntlmssp.challenge.target_info.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_timestamp,
{ "Timestamp", "ntlmssp.challenge.target_info.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_restrictions,
{ "Restrictions", "ntlmssp.challenge.target_info.restrictions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_target_name,
{ "Target Name", "ntlmssp.challenge.target_info.target_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_challenge_target_info_channel_bindings,
{ "Channel Bindings", "ntlmssp.challenge.target_info.channel_bindings",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_item_type,
{ "NTLMV2 Response Item Type", "ntlmssp.ntlmv2_response.item.type",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &ntlm_name_types_ext, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_item_len,
{ "NTLMV2 Response Item Length", "ntlmssp.ntlmv2_response.item.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_ntlmssp_ntlmv2_response_end,
{ "List End", "ntlmssp.ntlmv2_response.end",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_nb_computer_name,
{ "NetBIOS Computer Name", "ntlmssp.ntlmv2_response.nb_computer_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Server NetBIOS Computer Name", HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_nb_domain_name,
{ "NetBIOS Domain Name", "ntlmssp.ntlmv2_response.nb_domain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Server NetBIOS Domain Name", HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_dns_computer_name,
{ "DNS Computer Name", "ntlmssp.ntlmv2_response.dns_computer_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_dns_domain_name,
{ "DNS Domain Name", "ntlmssp.ntlmv2_response.dns_domain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_dns_tree_name,
{ "DNS Tree Name", "ntlmssp.ntlmv2_response.dns_tree_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_flags,
{ "Flags", "ntlmssp.ntlmv2_response.flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_timestamp,
{ "Timestamp", "ntlmssp.ntlmv2_response.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_restrictions,
{ "Restrictions", "ntlmssp.ntlmv2_response.restrictions",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_target_name,
{ "Target Name", "ntlmssp.ntlmv2_response.target_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_channel_bindings,
{ "Channel Bindings", "ntlmssp.ntlmv2_response.channel_bindings",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_message_integrity_code,
{ "MIC", "ntlmssp.authenticate.mic",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Message Integrity Code", HFILL}
},
{ &hf_ntlmssp_verf,
{ "NTLMSSP Verifier", "ntlmssp.verf",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_verf_vers,
{ "Version Number", "ntlmssp.verf.vers",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_verf_body,
{ "Verifier Body", "ntlmssp.verf.body",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_ntlmssp_decrypted_payload,
{ "NTLM Decrypted Payload", "ntlmssp.decrypted_payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_ntlmssp_verf_randompad,
{ "Random Pad", "ntlmssp.verf.randompad",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_verf_crc32,
{ "Verifier CRC32", "ntlmssp.verf.crc32",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_verf_hmacmd5,
{ "HMAC MD5", "ntlmssp.verf.hmacmd5",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_verf_sequence,
{ "Sequence", "ntlmssp.verf.sequence",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response,
{ "NTLMv2 Response", "ntlmssp.ntlmv2_response",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_ntproofstr,
{ "NTProofStr", "ntlmssp.ntlmv2_response.ntproofstr",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The HMAC-MD5 of the challenge", HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_rversion,
{ "Response Version", "ntlmssp.ntlmv2_response.rversion",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The 1-byte response version, currently set to 1", HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_hirversion,
{ "Hi Response Version", "ntlmssp.ntlmv2_response.hirversion",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The 1-byte highest response version understood by the client, currently set to 1", HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_z,
{ "Z", "ntlmssp.ntlmv2_response.z",
FT_BYTES, BASE_NONE, NULL, 0x0,
"byte array of zero bytes", HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_pad,
{ "padding", "ntlmssp.ntlmv2_response.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_time,
{ "Time", "ntlmssp.ntlmv2_response.time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"The 8-byte little-endian time in UTC", HFILL }
},
{ &hf_ntlmssp_ntlmv2_response_chal,
{ "NTLMv2 Client Challenge", "ntlmssp.ntlmv2_response.chal",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The 8-byte NTLMv2 challenge message generated by the client", HFILL }
},
};
static gint *ett[] = {
&ett_ntlmssp,
&ett_ntlmssp_negotiate_flags,
&ett_ntlmssp_string,
&ett_ntlmssp_blob,
&ett_ntlmssp_version,
&ett_ntlmssp_challenge_target_info,
&ett_ntlmssp_challenge_target_info_item,
&ett_ntlmssp_ntlmv2_response,
&ett_ntlmssp_ntlmv2_response_item,
};
static ei_register_info ei[] = {
{ &ei_ntlmssp_v2_key_too_long, { "ntlmssp.v2_key_too_long", PI_UNDECODED, PI_WARN, "NTLM v2 key is too long", EXPFILL }},
{ &ei_ntlmssp_blob_len_too_long, { "ntlmssp.blob.length.too_long", PI_UNDECODED, PI_WARN, "Session blob length too long", EXPFILL }},
{ &ei_ntlmssp_target_info_attr, { "ntlmssp.target_info_attr.unknown", PI_UNDECODED, PI_WARN, "unknown NTLMSSP Target Info Attribute", EXPFILL }},
{ &ei_ntlmssp_message_type, { "ntlmssp.messagetype.unknown", PI_PROTOCOL, PI_WARN, "Unrecognized NTLMSSP Message", EXPFILL }},
};
module_t *ntlmssp_module;
expert_module_t* expert_ntlmssp;
proto_ntlmssp = proto_register_protocol (
"NTLM Secure Service Provider",
"NTLMSSP",
"ntlmssp"
);
proto_register_field_array (proto_ntlmssp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_ntlmssp = expert_register_protocol(proto_ntlmssp);
expert_register_field_array(expert_ntlmssp, ei, array_length(ei));
register_init_routine(&ntlmssp_init_protocol);
register_cleanup_routine(&ntlmssp_cleanup_protocol);
ntlmssp_module = prefs_register_protocol(proto_ntlmssp, NULL);
prefs_register_string_preference(ntlmssp_module, "nt_password",
"NT Password",
"NT Password (used to decrypt payloads)",
&gbl_nt_password);
register_dissector("ntlmssp", dissect_ntlmssp, proto_ntlmssp);
register_dissector("ntlmssp_payload", dissect_ntlmssp_payload, proto_ntlmssp);
register_dissector("ntlmssp_data_only", dissect_ntlmssp_payload_only, proto_ntlmssp);
register_dissector("ntlmssp_verf", dissect_ntlmssp_verf, proto_ntlmssp);
}
void
proto_reg_handoff_ntlmssp(void)
{
dissector_handle_t ntlmssp_handle, ntlmssp_wrap_handle;
ntlmssp_handle = find_dissector("ntlmssp");
ntlmssp_wrap_handle = find_dissector("ntlmssp_verf");
gssapi_init_oid("1.3.6.1.4.1.311.2.2.10", proto_ntlmssp, ett_ntlmssp,
ntlmssp_handle, ntlmssp_wrap_handle,
"NTLMSSP - Microsoft NTLM Security Support Provider");
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_CONNECT,
DCE_C_RPC_AUTHN_PROTOCOL_NTLMSSP,
&ntlmssp_sign_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT,
DCE_C_RPC_AUTHN_PROTOCOL_NTLMSSP,
&ntlmssp_sign_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_INTEGRITY,
DCE_C_RPC_AUTHN_PROTOCOL_NTLMSSP,
&ntlmssp_sign_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_PRIVACY,
DCE_C_RPC_AUTHN_PROTOCOL_NTLMSSP,
&ntlmssp_seal_fns);
ntlmssp_tap = register_tap("ntlmssp");
heur_dissector_add("credssp", dissect_ntlmssp_heur, "NTLMSSP over CredSSP", "ntlmssp_credssp", proto_ntlmssp, HEURISTIC_ENABLE);
}
