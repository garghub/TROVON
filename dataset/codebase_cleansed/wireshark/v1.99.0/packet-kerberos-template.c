static void
call_kerberos_callbacks(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int tag, kerberos_callbacks *cb)
{
if(!cb){
return;
}
while(cb->tag){
if(cb->tag==tag){
cb->callback(pinfo, tvb, tree);
return;
}
cb++;
}
return;
}
static kerberos_private_data_t*
kerberos_get_private_data(asn1_ctx_t *actx)
{
if (!actx->private_data) {
actx->private_data = wmem_new0(wmem_packet_scope(), kerberos_private_data_t);
}
return (kerberos_private_data_t *)(actx->private_data);
}
void
read_keytab_file_from_preferences(void)
{
static char *last_keytab = NULL;
if (!krb_decrypt) {
return;
}
if (keytab_filename == NULL) {
return;
}
if (last_keytab && !strcmp(last_keytab, keytab_filename)) {
return;
}
if (last_keytab != NULL) {
g_free(last_keytab);
last_keytab = NULL;
}
last_keytab = g_strdup(keytab_filename);
read_keytab_file(last_keytab);
}
void
read_keytab_file_from_preferences(void)
{
}
static void
add_encryption_key(packet_info *pinfo, int keytype, int keylength, const char *keyvalue, const char *origin)
{
enc_key_t *new_key;
if(pinfo->fd->flags.visited){
return;
}
printf("added key in %u keytype:%d len:%d\n",pinfo->fd->num, keytype, keylength);
new_key=(enc_key_t *)g_malloc(sizeof(enc_key_t));
g_snprintf(new_key->key_origin, KRB_MAX_ORIG_LEN, "%s learnt from frame %u",origin,pinfo->fd->num);
new_key->fd_num = pinfo->fd->num;
new_key->next=enc_key_list;
enc_key_list=new_key;
new_key->keytype=keytype;
new_key->keylength=keylength;
new_key->keyvalue=(char *)g_memdup(keyvalue, keylength);
}
void
read_keytab_file(const char *filename _U_)
{
}
USES_APPLE_DEPRECATED_API
void
read_keytab_file(const char *filename)
{
krb5_keytab keytab;
krb5_error_code ret;
krb5_keytab_entry key;
krb5_kt_cursor cursor;
enc_key_t *new_key;
static gboolean first_time=TRUE;
if (filename == NULL || filename[0] == 0) {
return;
}
if(first_time){
first_time=FALSE;
ret = krb5_init_context(&krb5_ctx);
if(ret && ret != KRB5_CONFIG_CANTOPEN){
return;
}
}
ret = krb5_kt_resolve(krb5_ctx, filename, &keytab);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Badly formatted keytab filename :%s\n",filename);
return;
}
ret = krb5_kt_start_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Could not open or could not read from keytab file :%s\n",filename);
return;
}
do{
new_key=(enc_key_t *)g_malloc(sizeof(enc_key_t));
new_key->fd_num = -1;
new_key->next=enc_key_list;
ret = krb5_kt_next_entry(krb5_ctx, keytab, &key, &cursor);
if(ret==0){
int i;
char *pos;
pos=new_key->key_origin;
pos+=MIN(KRB_MAX_ORIG_LEN,
g_snprintf(pos, KRB_MAX_ORIG_LEN, "keytab principal "));
for(i=0;i<key.principal->length;i++){
pos+=MIN(KRB_MAX_ORIG_LEN-(pos-new_key->key_origin),
g_snprintf(pos, KRB_MAX_ORIG_LEN-(pos-new_key->key_origin), "%s%s",(i?"/":""),(key.principal->data[i]).data));
}
pos+=MIN(KRB_MAX_ORIG_LEN-(pos-new_key->key_origin),
g_snprintf(pos, KRB_MAX_ORIG_LEN-(pos-new_key->key_origin), "@%s",key.principal->realm.data));
*pos=0;
new_key->keytype=key.key.enctype;
new_key->keylength=key.key.length;
new_key->keyvalue=(char *)g_memdup(key.key.contents, key.key.length);
enc_key_list=new_key;
}
}while(ret==0);
ret = krb5_kt_end_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
krb5_kt_close(krb5_ctx, keytab);
}
}
guint8 *
decrypt_krb5_data(proto_tree *tree _U_, packet_info *pinfo,
int usage,
tvbuff_t *cryptotvb,
int keytype,
int *datalen)
{
krb5_error_code ret;
enc_key_t *ek;
krb5_data data = {0,0,NULL};
krb5_keytab_entry key;
int length = tvb_captured_length(cryptotvb);
const guint8 *cryptotext = tvb_get_ptr(cryptotvb, 0, length);
if(!krb_decrypt || length < 1){
return NULL;
}
if (tvb_captured_length(cryptotvb) < tvb_reported_length(cryptotvb)) {
return NULL;
}
read_keytab_file_from_preferences();
data.data = (char *)g_malloc(length);
data.length = length;
for(ek=enc_key_list;ek;ek=ek->next){
krb5_enc_data input;
if((keytype != -1) && (ek->keytype != keytype)) {
continue;
}
input.enctype = ek->keytype;
input.ciphertext.length = length;
input.ciphertext.data = (guint8 *)cryptotext;
key.key.enctype=ek->keytype;
key.key.length=ek->keylength;
key.key.contents=ek->keyvalue;
ret = krb5_c_decrypt(krb5_ctx, &(key.key), usage, 0, &input, &data);
if(ret == 0){
char *user_data;
expert_add_info_format(pinfo, NULL, &ei_kerberos_decrypted_keytype,
"Decrypted keytype %d in frame %u using %s",
ek->keytype, pinfo->fd->num, ek->key_origin);
user_data=data.data;
if (datalen) {
*datalen = data.length;
}
return user_data;
}
}
g_free(data.data);
return NULL;
}
USES_APPLE_DEPRECATED_API
void
read_keytab_file(const char *filename)
{
krb5_keytab keytab;
krb5_error_code ret;
krb5_keytab_entry key;
krb5_kt_cursor cursor;
enc_key_t *new_key;
static gboolean first_time=TRUE;
if (filename == NULL || filename[0] == 0) {
return;
}
if(first_time){
first_time=FALSE;
ret = krb5_init_context(&krb5_ctx);
if(ret){
return;
}
}
ret = krb5_kt_resolve(krb5_ctx, filename, &keytab);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Could not open keytab file :%s\n",filename);
return;
}
ret = krb5_kt_start_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
fprintf(stderr, "KERBEROS ERROR: Could not read from keytab file :%s\n",filename);
return;
}
do{
new_key=g_malloc(sizeof(enc_key_t));
new_key->fd_num = -1;
new_key->next=enc_key_list;
ret = krb5_kt_next_entry(krb5_ctx, keytab, &key, &cursor);
if(ret==0){
unsigned int i;
char *pos;
pos=new_key->key_origin;
pos+=MIN(KRB_MAX_ORIG_LEN,
g_snprintf(pos, KRB_MAX_ORIG_LEN, "keytab principal "));
for(i=0;i<key.principal->name.name_string.len;i++){
pos+=MIN(KRB_MAX_ORIG_LEN-(pos-new_key->key_origin),
g_snprintf(pos, KRB_MAX_ORIG_LEN-(pos-new_key->key_origin), "%s%s",(i?"/":""),key.principal->name.name_string.val[i]));
}
pos+=MIN(KRB_MAX_ORIG_LEN-(pos-new_key->key_origin),
g_snprintf(pos, KRB_MAX_ORIG_LEN-(pos-new_key->key_origin), "@%s",key.principal->realm));
*pos=0;
new_key->keytype=key.keyblock.keytype;
new_key->keylength=key.keyblock.keyvalue.length;
new_key->keyvalue=g_memdup(key.keyblock.keyvalue.data, key.keyblock.keyvalue.length);
enc_key_list=new_key;
}
}while(ret==0);
ret = krb5_kt_end_seq_get(krb5_ctx, keytab, &cursor);
if(ret){
krb5_kt_close(krb5_ctx, keytab);
}
}
USES_APPLE_RST
guint8 *
decrypt_krb5_data(proto_tree *tree, packet_info *pinfo,
int usage,
tvbuff_t *cryptotvb,
int keytype,
int *datalen)
{
krb5_error_code ret;
krb5_data data;
enc_key_t *ek;
int length = tvb_captured_length(cryptotvb);
const guint8 *cryptotext = tvb_get_ptr(cryptotvb, 0, length);
if(!krb_decrypt){
return NULL;
}
if (tvb_captured_length(cryptotvb) < tvb_reported_length(cryptotvb)) {
return NULL;
}
read_keytab_file_from_preferences();
for(ek=enc_key_list;ek;ek=ek->next){
krb5_keytab_entry key;
krb5_crypto crypto;
guint8 *cryptocopy;
if((keytype != -1) && (ek->keytype != keytype)) {
continue;
}
key.keyblock.keytype=ek->keytype;
key.keyblock.keyvalue.length=ek->keylength;
key.keyblock.keyvalue.data=ek->keyvalue;
ret = krb5_crypto_init(krb5_ctx, &(key.keyblock), 0, &crypto);
if(ret){
return NULL;
}
cryptocopy=g_memdup(cryptotext, length);
ret = krb5_decrypt_ivec(krb5_ctx, crypto, usage,
cryptocopy, length,
&data,
NULL);
g_free(cryptocopy);
if((ret == 0) && (length>0)){
char *user_data;
expert_add_info_format(pinfo, NULL, &ei_kerberos_decrypted_keytype,
"Decrypted keytype %d in frame %u using %s",
ek->keytype, pinfo->fd->num, ek->key_origin);
krb5_crypto_destroy(krb5_ctx, crypto);
user_data=g_memdup(data.data, data.length);
if (datalen) {
*datalen = data.length;
}
return user_data;
}
krb5_crypto_destroy(krb5_ctx, crypto);
}
return NULL;
}
static void
add_encryption_key(packet_info *pinfo, int keytype, int keylength, const char *keyvalue, const char *origin)
{
service_key_t *new_key;
if(pinfo->fd->flags.visited){
return;
}
printf("added key in %u\n",pinfo->fd->num);
new_key = g_malloc(sizeof(service_key_t));
new_key->kvno = 0;
new_key->keytype = keytype;
new_key->length = keylength;
new_key->contents = g_memdup(keyvalue, keylength);
g_snprintf(new_key->origin, KRB_MAX_ORIG_LEN, "%s learnt from frame %u", origin, pinfo->fd->num);
service_key_list = g_slist_append(service_key_list, (gpointer) new_key);
}
static void
clear_keytab(void) {
GSList *ske;
service_key_t *sk;
for(ske = service_key_list; ske != NULL; ske = g_slist_next(ske)){
sk = (service_key_t *) ske->data;
if (sk) {
g_free(sk->contents);
g_free(sk);
}
}
g_slist_free(service_key_list);
service_key_list = NULL;
}
static void
read_keytab_file(const char *service_key_file)
{
FILE *skf;
ws_statb64 st;
service_key_t *sk;
unsigned char buf[SERVICE_KEY_SIZE];
int newline_skip = 0, count = 0;
if (service_key_file != NULL && ws_stat64 (service_key_file, &st) == 0) {
if (st.st_size > SERVICE_KEY_SIZE) {
if ( (st.st_size % (SERVICE_KEY_SIZE + 1) == 0) ||
(st.st_size % (SERVICE_KEY_SIZE + 1) == SERVICE_KEY_SIZE) ) {
newline_skip = 1;
} else if ( (st.st_size % (SERVICE_KEY_SIZE + 2) == 0) ||
(st.st_size % (SERVICE_KEY_SIZE + 2) == SERVICE_KEY_SIZE) ) {
newline_skip = 2;
}
}
skf = ws_fopen(service_key_file, "rb");
if (! skf) return;
while (fread(buf, SERVICE_KEY_SIZE, 1, skf) == 1) {
sk = g_malloc(sizeof(service_key_t));
sk->kvno = buf[0] << 8 | buf[1];
sk->keytype = KEYTYPE_DES3_CBC_MD5;
sk->length = DES3_KEY_SIZE;
sk->contents = g_memdup(buf + 2, DES3_KEY_SIZE);
g_snprintf(sk->origin, KRB_MAX_ORIG_LEN, "3DES service key file, key #%d, offset %ld", count, ftell(skf));
service_key_list = g_slist_append(service_key_list, (gpointer) sk);
fseek(skf, newline_skip, SEEK_CUR);
count++;
g_warning("added key: %s", sk->origin);
}
fclose(skf);
}
}
guint8 *
decrypt_krb5_data(proto_tree *tree, packet_info *pinfo,
int _U_ usage,
tvbuff_t *cryptotvb,
int keytype,
int *datalen)
{
tvbuff_t *encr_tvb;
guint8 *decrypted_data = NULL, *plaintext = NULL;
guint8 cls;
gboolean pc;
guint32 tag, item_len, data_len;
int id_offset, offset;
guint8 key[DES3_KEY_SIZE];
guint8 initial_vector[DES_BLOCK_SIZE];
md5_state_t md5s;
md5_byte_t digest[16];
md5_byte_t zero_fill[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
md5_byte_t confounder[8];
gboolean ind;
GSList *ske;
service_key_t *sk;
struct des3_ctx ctx;
int length = tvb_captured_length(cryptotvb);
const guint8 *cryptotext = tvb_get_ptr(cryptotvb, 0, length);
if(!krb_decrypt){
return NULL;
}
if (tvb_captured_length(cryptotvb) < tvb_reported_length(cryptotvb)) {
return NULL;
}
if (keytype != KEYTYPE_DES3_CBC_MD5 || service_key_list == NULL) {
return NULL;
}
decrypted_data = g_malloc(length);
for(ske = service_key_list; ske != NULL; ske = g_slist_next(ske)){
gboolean do_continue = FALSE;
sk = (service_key_t *) ske->data;
des_fix_parity(DES3_KEY_SIZE, key, sk->contents);
md5_init(&md5s);
memset(initial_vector, 0, DES_BLOCK_SIZE);
des3_set_key(&ctx, key);
cbc_decrypt(&ctx, des3_decrypt, DES_BLOCK_SIZE, initial_vector,
length, decrypted_data, cryptotext);
encr_tvb = tvb_new_real_data(decrypted_data, length, length);
tvb_memcpy(encr_tvb, confounder, 0, 8);
TRY {
id_offset = get_ber_identifier(encr_tvb, CONFOUNDER_PLUS_CHECKSUM, &cls, &pc, &tag);
offset = get_ber_length(encr_tvb, id_offset, &item_len, &ind);
}
CATCH_BOUNDS_ERRORS {
tvb_free(encr_tvb);
do_continue = TRUE;
}
ENDTRY;
if (do_continue) continue;
data_len = item_len + offset - CONFOUNDER_PLUS_CHECKSUM;
if ((int) item_len + offset > length) {
tvb_free(encr_tvb);
continue;
}
md5_append(&md5s, confounder, 8);
md5_append(&md5s, zero_fill, 16);
md5_append(&md5s, decrypted_data + CONFOUNDER_PLUS_CHECKSUM, data_len);
md5_finish(&md5s, digest);
if (tvb_memeql (encr_tvb, 8, digest, 16) == 0) {
g_warning("woohoo decrypted keytype:%d in frame:%u\n", keytype, pinfo->fd->num);
plaintext = g_malloc(data_len);
tvb_memcpy(encr_tvb, plaintext, CONFOUNDER_PLUS_CHECKSUM, data_len);
tvb_free(encr_tvb);
if (datalen) {
*datalen = data_len;
}
g_free(decrypted_data);
return(plaintext);
}
tvb_free(encr_tvb);
}
g_free(decrypted_data);
return NULL;
}
static int
dissect_krb5_decrypt_ticket_data (gboolean imp_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
proto_tree *tree, int hf_index _U_)
{
guint8 *plaintext;
int length;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_captured_length_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 2, next_tvb, private_data->etype, NULL);
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext, length, length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_kerberos_Applications(FALSE, child_tvb, 0, actx , tree, -1);
}
return offset;
}
static int
dissect_krb5_decrypt_authenticator_data (gboolean imp_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
proto_tree *tree, int hf_index _U_)
{
guint8 *plaintext;
int length;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_captured_length_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 7, next_tvb, private_data->etype, NULL);
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 11, next_tvb, private_data->etype, NULL);
}
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext, length, length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_kerberos_Applications(FALSE, child_tvb, 0, actx , tree, -1);
}
return offset;
}
static int
dissect_krb5_decrypt_KDC_REP_data (gboolean imp_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
proto_tree *tree, int hf_index _U_)
{
guint8 *plaintext;
int length;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_captured_length_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 3, next_tvb, private_data->etype, NULL);
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 8, next_tvb, private_data->etype, NULL);
}
if(!plaintext){
plaintext=decrypt_krb5_data(tree, actx->pinfo, 9, next_tvb, private_data->etype, NULL);
}
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext, length, length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_kerberos_Applications(FALSE, child_tvb, 0, actx , tree, -1);
}
return offset;
}
static int
dissect_krb5_decrypt_PA_ENC_TIMESTAMP (gboolean imp_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
proto_tree *tree, int hf_index _U_)
{
guint8 *plaintext;
int length;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_captured_length_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 1, next_tvb, private_data->etype, NULL);
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext, length, length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_kerberos_Applications(FALSE, child_tvb, 0, actx , tree, -1);
}
return offset;
}
static int
dissect_krb5_decrypt_AP_REP_data (gboolean imp_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
proto_tree *tree, int hf_index _U_)
{
guint8 *plaintext;
int length;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_captured_length_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 12, next_tvb, private_data->etype, NULL);
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext, length, length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_kerberos_Applications(FALSE, child_tvb, 0, actx , tree, -1);
}
return offset;
}
static int
dissect_krb5_decrypt_PRIV_data (gboolean imp_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
proto_tree *tree, int hf_index _U_)
{
guint8 *plaintext;
int length;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_captured_length_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 13, next_tvb, private_data->etype, NULL);
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext, length, length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_kerberos_Applications(FALSE, child_tvb, 0, actx , tree, -1);
}
return offset;
}
static int
dissect_krb5_decrypt_CRED_data (gboolean imp_tag _U_, tvbuff_t *tvb, int offset, asn1_ctx_t *actx,
proto_tree *tree, int hf_index _U_)
{
guint8 *plaintext;
int length;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
tvbuff_t *next_tvb;
next_tvb=tvb_new_subset_remaining(tvb, offset);
length=tvb_captured_length_remaining(tvb, offset);
plaintext=decrypt_krb5_data(tree, actx->pinfo, 14, next_tvb, private_data->etype, NULL);
if(plaintext){
tvbuff_t *child_tvb;
child_tvb = tvb_new_child_real_data(tvb, plaintext, length, length);
tvb_set_free_cb(child_tvb, g_free);
add_new_data_source(actx->pinfo, child_tvb, "Decrypted Krb5");
offset=dissect_kerberos_Applications(FALSE, child_tvb, 0, actx , tree, -1);
}
return offset;
}
static int
dissect_krb5_rfc1964_checksum(asn1_ctx_t *actx _U_, proto_tree *tree, tvbuff_t *tvb)
{
int offset=0;
guint32 len;
guint16 dlglen;
len=tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_krb_gssapi_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_krb_gssapi_bnd, tvb, offset, len, ENC_NA);
offset += len;
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_dce_style, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_integ, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_conf, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_sequence, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_replay, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_mutual, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_krb_gssapi_c_flag_deleg, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if(tvb_reported_length_remaining(tvb, offset)<2){
return offset;
}
proto_tree_add_item(tree, hf_krb_gssapi_dlgopt, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(tvb_reported_length_remaining(tvb, offset)<2){
return offset;
}
dlglen=tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_krb_gssapi_dlglen, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(dlglen!=tvb_reported_length_remaining(tvb, offset)){
proto_tree_add_expert_format(tree, actx->pinfo, &ei_krb_gssapi_dlglen, tvb, 0, 0,
"Error: DlgLen:%d is not the same as number of bytes remaining:%d", dlglen, tvb_captured_length_remaining(tvb, offset));
return offset;
}
offset=dissect_kerberos_Applications(FALSE, tvb, offset, actx, tree, -1);
return offset;
}
static int
dissect_krb5_PA_PROV_SRV_LOCATION(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_)
{
offset=dissect_ber_GeneralString(actx, tree, tvb, offset, hf_krb_provsrv_location, NULL, 0);
return offset;
}
static int
dissect_krb5_PW_SALT(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_)
{
guint32 nt_status;
proto_tree_add_item(tree, hf_krb_smb_nt_status, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
nt_status=tvb_get_letohl(tvb, offset);
if(nt_status) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO,
" NT Status: %s",
val_to_str(nt_status, NT_errors,
"Unknown error code %#x"));
}
offset += 4;
proto_tree_add_item(tree, hf_krb_smb_unknown, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_krb_smb_unknown, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
return offset;
}
int
dissect_krb5_Checksum(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
return dissect_kerberos_Checksum(FALSE, tvb, offset, actx, tree, hf_kerberos_cksum);
}
int
dissect_krb5_ctime(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
return dissect_kerberos_KerberosTime(FALSE, tvb, offset, actx, tree, hf_kerberos_ctime);
}
int
dissect_krb5_cname(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
return dissect_kerberos_PrincipalName(FALSE, tvb, offset, actx, tree, hf_kerberos_cname);
}
int
dissect_krb5_realm(proto_tree *tree, tvbuff_t *tvb, int offset, asn1_ctx_t *actx _U_)
{
return dissect_kerberos_Realm(FALSE, tvb, offset, actx, tree, hf_kerberos_realm);
}
static gint
dissect_kerberos_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean dci, gboolean do_col_protocol, gboolean have_rm,
kerberos_callbacks *cb)
{
volatile int offset = 0;
proto_tree *volatile kerberos_tree = NULL;
proto_item *volatile item = NULL;
asn1_ctx_t asn1_ctx;
guint32 krb_rm = 0;
gint krb_reclen = 0;
gbl_do_col_info=dci;
if (have_rm) {
krb_rm = tvb_get_ntohl(tvb, offset);
krb_reclen = kerberos_rm_to_reclen(krb_rm);
if (krb_reclen > 10 * 1024 * 1024) {
return (-1);
}
if (do_col_protocol) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KRB5");
}
if (tree) {
item = proto_tree_add_item(tree, proto_kerberos, tvb, 0, -1, ENC_NA);
kerberos_tree = proto_item_add_subtree(item, ett_kerberos);
}
show_krb_recordmark(kerberos_tree, tvb, offset, krb_rm);
offset += 4;
} else {
gint8 tmp_class;
gboolean tmp_pc;
gint32 tmp_tag;
get_ber_identifier(tvb, offset, &tmp_class, &tmp_pc, &tmp_tag);
if(tmp_class!=BER_CLASS_APP){
return 0;
}
switch(tmp_tag){
case KRB5_MSG_TICKET:
case KRB5_MSG_AUTHENTICATOR:
case KRB5_MSG_ENC_TICKET_PART:
case KRB5_MSG_AS_REQ:
case KRB5_MSG_AS_REP:
case KRB5_MSG_TGS_REQ:
case KRB5_MSG_TGS_REP:
case KRB5_MSG_AP_REQ:
case KRB5_MSG_AP_REP:
case KRB5_MSG_ENC_AS_REP_PART:
case KRB5_MSG_ENC_TGS_REP_PART:
case KRB5_MSG_ENC_AP_REP_PART:
case KRB5_MSG_ENC_KRB_PRIV_PART:
case KRB5_MSG_ENC_KRB_CRED_PART:
case KRB5_MSG_SAFE:
case KRB5_MSG_PRIV:
case KRB5_MSG_ERROR:
break;
default:
return 0;
}
if (do_col_protocol) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KRB5");
}
if (gbl_do_col_info) {
col_clear(pinfo->cinfo, COL_INFO);
}
if (tree) {
item = proto_tree_add_item(tree, proto_kerberos, tvb, 0, -1, ENC_NA);
kerberos_tree = proto_item_add_subtree(item, ett_kerberos);
}
}
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
asn1_ctx.private_data = cb;
TRY {
offset=dissect_kerberos_Applications(FALSE, tvb, offset, &asn1_ctx , kerberos_tree, -1);
} CATCH_BOUNDS_ERRORS {
RETHROW;
} ENDTRY;
proto_item_set_len(item, offset);
return offset;
}
void
show_krb_recordmark(proto_tree *tree, tvbuff_t *tvb, gint start, guint32 krb_rm)
{
gint rec_len;
proto_tree *rm_tree;
if (tree == NULL)
return;
rec_len = kerberos_rm_to_reclen(krb_rm);
rm_tree = proto_tree_add_subtree_format(tree, tvb, start, 4, ett_krb_recordmark, NULL,
"Record Mark: %u %s", rec_len, plurality(rec_len, "byte", "bytes"));
proto_tree_add_boolean(rm_tree, hf_krb_rm_reserved, tvb, start, 4, krb_rm);
proto_tree_add_uint(rm_tree, hf_krb_rm_reclen, tvb, start, 4, krb_rm);
}
gint
dissect_kerberos_main(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int do_col_info, kerberos_callbacks *cb)
{
return (dissect_kerberos_common(tvb, pinfo, tree, do_col_info, FALSE, FALSE, cb));
}
guint32
kerberos_output_keytype(void)
{
return gbl_keytype;
}
static gint
dissect_kerberos_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if(tvb_captured_length(tvb) >= 1 && tvb_get_guint8(tvb, 0)<=0x10){
if(krb4_handle){
gboolean res;
res=call_dissector_only(krb4_handle, tvb, pinfo, tree, NULL);
return res;
}else{
return 0;
}
}
return dissect_kerberos_common(tvb, pinfo, tree, TRUE, TRUE, FALSE, NULL);
}
gint
kerberos_rm_to_reclen(guint krb_rm)
{
return (krb_rm & KRB_RM_RECLEN);
}
guint
get_krb_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint krb_rm;
gint pdulen;
krb_rm = tvb_get_ntohl(tvb, offset);
pdulen = kerberos_rm_to_reclen(krb_rm);
return (pdulen + 4);
}
static void
kerberos_prefs_apply_cb(void) {
#ifdef HAVE_LIBNETTLE
clear_keytab();
read_keytab_file(keytab_filename);
#endif
}
static int
dissect_kerberos_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
pinfo->fragmented = TRUE;
if (dissect_kerberos_common(tvb, pinfo, tree, TRUE, TRUE, TRUE, NULL) < 0) {
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
}
return tvb_captured_length(tvb);
}
static int
dissect_kerberos_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KRB5");
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, krb_desegment, 4, get_krb_pdu_len,
dissect_kerberos_tcp_pdu, data);
return tvb_captured_length(tvb);
}
void proto_register_kerberos(void) {
static hf_register_info hf[] = {
{ &hf_krb_rm_reserved, {
"Reserved", "kerberos.rm.reserved", FT_BOOLEAN, 32,
TFS(&tfs_set_notset), KRB_RM_RESERVED, "Record mark reserved bit", HFILL }},
{ &hf_krb_rm_reclen, {
"Record Length", "kerberos.rm.length", FT_UINT32, BASE_DEC,
NULL, KRB_RM_RECLEN, NULL, HFILL }},
{ &hf_krb_provsrv_location, {
"PROVSRV Location", "kerberos.provsrv_location", FT_STRING, BASE_NONE,
NULL, 0, "PacketCable PROV SRV Location", HFILL }},
{ &hf_krb_smb_nt_status,
{ "NT Status", "kerberos.smb.nt_status", FT_UINT32, BASE_HEX,
VALS(NT_errors), 0, "NT Status code", HFILL }},
{ &hf_krb_smb_unknown,
{ "Unknown", "kerberos.smb.unknown", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_krb_address_ip, {
"IP Address", "kerberos.addr_ip", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_address_ipv6, {
"IPv6 Address", "kerberos.addr_ipv6", FT_IPv6, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_krb_address_netbios, {
"NetBIOS Address", "kerberos.addr_nb", FT_STRING, BASE_NONE,
NULL, 0, "NetBIOS Address and type", HFILL }},
{ &hf_krb_gssapi_len, {
"Length", "kerberos.gssapi.len", FT_UINT32, BASE_DEC,
NULL, 0, "Length of GSSAPI Bnd field", HFILL }},
{ &hf_krb_gssapi_bnd, {
"Bnd", "kerberos.gssapi.bdn", FT_BYTES, BASE_NONE,
NULL, 0, "GSSAPI Bnd field", HFILL }},
{ &hf_krb_gssapi_c_flag_deleg, {
"Deleg", "kerberos.gssapi.checksum.flags.deleg", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_deleg), KRB5_GSS_C_DELEG_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_mutual, {
"Mutual", "kerberos.gssapi.checksum.flags.mutual", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_mutual), KRB5_GSS_C_MUTUAL_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_replay, {
"Replay", "kerberos.gssapi.checksum.flags.replay", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_replay), KRB5_GSS_C_REPLAY_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_sequence, {
"Sequence", "kerberos.gssapi.checksum.flags.sequence", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_sequence), KRB5_GSS_C_SEQUENCE_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_conf, {
"Conf", "kerberos.gssapi.checksum.flags.conf", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_conf), KRB5_GSS_C_CONF_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_integ, {
"Integ", "kerberos.gssapi.checksum.flags.integ", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_integ), KRB5_GSS_C_INTEG_FLAG, NULL, HFILL }},
{ &hf_krb_gssapi_c_flag_dce_style, {
"DCE-style", "kerberos.gssapi.checksum.flags.dce-style", FT_BOOLEAN, 32,
TFS(&tfs_gss_flags_dce_style), KRB5_GSS_C_DCE_STYLE, NULL, HFILL }},
{ &hf_krb_gssapi_dlgopt, {
"DlgOpt", "kerberos.gssapi.dlgopt", FT_UINT16, BASE_DEC,
NULL, 0, "GSSAPI DlgOpt", HFILL }},
{ &hf_krb_gssapi_dlglen, {
"DlgLen", "kerberos.gssapi.dlglen", FT_UINT16, BASE_DEC,
NULL, 0, "GSSAPI DlgLen", HFILL }},
#include "packet-kerberos-hfarr.c"
};
static gint *ett[] = {
&ett_kerberos,
&ett_krb_recordmark,
#include "packet-kerberos-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_kerberos_decrypted_keytype, { "kerberos.decrypted_keytype", PI_SECURITY, PI_CHAT, "Decryted keytype", EXPFILL }},
{ &ei_kerberos_address, { "kerberos.address.unknown", PI_UNDECODED, PI_WARN, "KRB Address: I don't know how to parse this type of address yet", EXPFILL }},
{ &ei_krb_gssapi_dlglen, { "kerberos.gssapi.dlglen.error", PI_MALFORMED, PI_ERROR, "DlgLen is not the same as number of bytes remaining", EXPFILL }},
};
expert_module_t* expert_krb;
module_t *krb_module;
proto_kerberos = proto_register_protocol("Kerberos", "KRB5", "kerberos");
proto_register_field_array(proto_kerberos, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_krb = expert_register_protocol(proto_kerberos);
expert_register_field_array(expert_krb, ei, array_length(ei));
krb_module = prefs_register_protocol(proto_kerberos, kerberos_prefs_apply_cb);
prefs_register_bool_preference(krb_module, "desegment",
"Reassemble Kerberos over TCP messages spanning multiple TCP segments",
"Whether the Kerberos dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&krb_desegment);
#ifdef HAVE_KERBEROS
prefs_register_bool_preference(krb_module, "decrypt",
"Try to decrypt Kerberos blobs",
"Whether the dissector should try to decrypt "
"encrypted Kerberos blobs. This requires that the proper "
"keytab file is installed as well.", &krb_decrypt);
prefs_register_filename_preference(krb_module, "file",
"Kerberos keytab file",
"The keytab file containing all the secrets",
&keytab_filename);
#endif
}
static int wrap_dissect_gss_kerb(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di _U_,guint8 *drep _U_)
{
tvbuff_t *auth_tvb;
auth_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_kerberos_main(auth_tvb, pinfo, tree, FALSE, NULL);
return tvb_captured_length_remaining(tvb, offset);
}
void
proto_reg_handoff_kerberos(void)
{
dissector_handle_t kerberos_handle_tcp;
krb4_handle = find_dissector("krb4");
kerberos_handle_udp = new_create_dissector_handle(dissect_kerberos_udp,
proto_kerberos);
kerberos_handle_tcp = new_create_dissector_handle(dissect_kerberos_tcp,
proto_kerberos);
dissector_add_uint("udp.port", UDP_PORT_KERBEROS, kerberos_handle_udp);
dissector_add_uint("tcp.port", TCP_PORT_KERBEROS, kerberos_handle_tcp);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_CONNECT,
DCE_C_RPC_AUTHN_PROTOCOL_GSS_KERBEROS,
&gss_kerb_auth_connect_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_INTEGRITY,
DCE_C_RPC_AUTHN_PROTOCOL_GSS_KERBEROS,
&gss_kerb_auth_sign_fns);
register_dcerpc_auth_subdissector(DCE_C_AUTHN_LEVEL_PKT_PRIVACY,
DCE_C_RPC_AUTHN_PROTOCOL_GSS_KERBEROS,
&gss_kerb_auth_seal_fns);
}
