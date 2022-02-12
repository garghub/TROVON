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
static int
dissect_kerberos_INTEGER_5(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_KerberosString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_Realm(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_kerberos_KerberosString(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_kerberos_NAME_TYPE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_SEQUENCE_OF_KerberosString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_KerberosString_sequence_of, hf_index, ett_kerberos_SEQUENCE_OF_KerberosString);
return offset;
}
static int
dissect_kerberos_PrincipalName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PrincipalName_sequence, hf_index, ett_kerberos_PrincipalName);
return offset;
}
static int
dissect_kerberos_ENCTYPE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 223 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&(private_data->etype));
return offset;
}
static int
dissect_kerberos_UInt32(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_T_encryptedTicketData_cipher(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 227 "../../asn1/kerberos/kerberos.cnf"
#ifdef HAVE_KERBEROS
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_index, dissect_krb5_decrypt_ticket_data);
#else
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#endif
return offset;
return offset;
}
static int
dissect_kerberos_EncryptedTicketData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedTicketData_sequence, hf_index, ett_kerberos_EncryptedTicketData);
return offset;
}
static int
dissect_kerberos_Ticket_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Ticket_U_sequence, hf_index, ett_kerberos_Ticket_U);
return offset;
}
static int
dissect_kerberos_Ticket(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 1, FALSE, dissect_kerberos_Ticket_U);
return offset;
}
static int
dissect_kerberos_CKSUMTYPE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 284 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&(private_data->checksum_type));
return offset;
}
static int
dissect_kerberos_T_checksum(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 288 "../../asn1/kerberos/kerberos.cnf"
tvbuff_t *next_tvb;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
switch(private_data->checksum_type){
case KRB5_CHKSUM_GSSAPI:
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_index, &next_tvb);
dissect_krb5_rfc1964_checksum(actx, tree, next_tvb);
break;
default:
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_index, NULL);
}
return offset;
return offset;
}
static int
dissect_kerberos_Checksum(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Checksum_sequence, hf_index, ett_kerberos_Checksum);
return offset;
}
static int
dissect_kerberos_Microseconds(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_KerberosTime(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_GeneralizedTime(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_kerberos_Int32(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_T_keytype(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 302 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&gbl_keytype);
private_data->key.keytype = gbl_keytype;
return offset;
}
static int
dissect_kerberos_T_keyvalue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 309 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
private_data->key.keylength = tvb_length_remaining(tvb, offset);
private_data->key.keyvalue = tvb_get_ptr(tvb, offset, private_data->key.keylength);
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_EncryptionKey(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 317 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptionKey_sequence, hf_index, ett_kerberos_EncryptionKey);
if (private_data->key.keytype != 0) {
#ifdef HAVE_KERBEROS
add_encryption_key(actx->pinfo, private_data->key.keytype, private_data->key.keylength, private_data->key.keyvalue, "key");
#endif
}
return offset;
}
static int
dissect_kerberos_T_ad_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 328 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&(private_data->ad_type));
return offset;
}
static int
dissect_kerberos_T_ad_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 333 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
switch(private_data->ad_type){
case KRB5_AD_IF_RELEVANT:
offset=dissect_ber_octet_string_wcb(implicit_tag, actx, tree, tvb, offset, hf_index, dissect_kerberos_AD_IF_RELEVANT);
break;
default:
offset=dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
}
return offset;
}
static int
dissect_kerberos_AuthorizationData_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AuthorizationData_item_sequence, hf_index, ett_kerberos_AuthorizationData_item);
return offset;
}
static int
dissect_kerberos_AuthorizationData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
AuthorizationData_sequence_of, hf_index, ett_kerberos_AuthorizationData);
return offset;
}
static int
dissect_kerberos_Authenticator_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Authenticator_U_sequence, hf_index, ett_kerberos_Authenticator_U);
return offset;
}
static int
dissect_kerberos_Authenticator(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 2, FALSE, dissect_kerberos_Authenticator_U);
return offset;
}
static int
dissect_kerberos_TicketFlags(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
TicketFlags_bits, hf_index, ett_kerberos_TicketFlags,
NULL);
return offset;
}
static int
dissect_kerberos_OCTET_STRING(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_TransitedEncoding(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
TransitedEncoding_sequence, hf_index, ett_kerberos_TransitedEncoding);
return offset;
}
static int
dissect_kerberos_ADDR_TYPE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 344 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&(private_data->addr_type));
return offset;
}
static int
dissect_kerberos_T_address(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 172 "../../asn1/kerberos/kerberos.cnf"
gint8 appclass;
gboolean pc;
gint32 tag;
guint32 len;
const char *address_str;
proto_item *it=NULL;
kerberos_private_data_t *private_data = kerberos_get_private_data(actx);
offset=dissect_ber_identifier(actx->pinfo, tree, tvb, offset, &appclass, &pc, &tag);
offset=dissect_ber_length(actx->pinfo, tree, tvb, offset, &len, NULL);
switch(private_data->addr_type){
case KERBEROS_ADDR_TYPE_IPV4:
it=proto_tree_add_item(tree, hf_krb_address_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
address_str = tvb_ip_to_str(tvb, offset);
break;
case KERBEROS_ADDR_TYPE_NETBIOS:
{
char netbios_name[(NETBIOS_NAME_LEN - 1)*4 + 1];
int netbios_name_type;
int netbios_name_len = (NETBIOS_NAME_LEN - 1)*4 + 1;
netbios_name_type = process_netbios_name(tvb_get_ptr(tvb, offset, 16), netbios_name, netbios_name_len);
address_str = wmem_strdup_printf(wmem_packet_scope(), "%s<%02x>", netbios_name, netbios_name_type);
it=proto_tree_add_string_format(tree, hf_krb_address_netbios, tvb, offset, 16, netbios_name, "NetBIOS Name: %s (%s)", address_str, netbios_name_type_descr(netbios_name_type));
}
break;
case KERBEROS_ADDR_TYPE_IPV6:
it=proto_tree_add_item(tree, hf_krb_address_ipv6, tvb, offset, INET6_ADDRLEN, ENC_NA);
address_str = tvb_ip6_to_str(tvb, offset);
break;
default:
proto_tree_add_expert(tree, actx->pinfo, &ei_kerberos_address, tvb, offset, len);
address_str = NULL;
}
if(it && address_str){
proto_item_append_text(proto_item_get_parent(it), " %s",address_str);
proto_item_append_text(proto_item_get_parent_nth(it, 2), " %s",address_str);
}
offset+=len;
return offset;
return offset;
}
static int
dissect_kerberos_HostAddress(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
HostAddress_sequence, hf_index, ett_kerberos_HostAddress);
return offset;
}
static int
dissect_kerberos_HostAddresses(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
HostAddresses_sequence_of, hf_index, ett_kerberos_HostAddresses);
return offset;
}
static int
dissect_kerberos_EncTicketPart_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncTicketPart_U_sequence, hf_index, ett_kerberos_EncTicketPart_U);
return offset;
}
static int
dissect_kerberos_EncTicketPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 3, FALSE, dissect_kerberos_EncTicketPart_U);
return offset;
}
static int
dissect_kerberos_MESSAGE_TYPE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 66 "../../asn1/kerberos/kerberos.cnf"
guint32 msgtype;
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&msgtype);
#line 71 "../../asn1/kerberos/kerberos.cnf"
if (gbl_do_col_info) {
col_add_str(actx->pinfo->cinfo, COL_INFO,
val_to_str(msgtype, krb5_msg_types,
"Unknown msg type %#x"));
}
gbl_do_col_info=FALSE;
#if 0
proto_item_append_text(tree, " %s", val_to_str(msgtype, krb5_msg_types, "Unknown:0x%x"));
#endif
return offset;
}
static int
dissect_kerberos_PADATA_TYPE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 119 "../../asn1/kerberos/kerberos.cnf"
kerberos_private_data_t* private_data = kerberos_get_private_data(actx);
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&(private_data->padata_type));
#line 122 "../../asn1/kerberos/kerberos.cnf"
if(tree){
proto_item_append_text(tree, " %s",
val_to_str(private_data->padata_type, krb5_preauthentication_types,
"Unknown:%d"));
}
return offset;
}
static int
dissect_kerberos_T_padata_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 129 "../../asn1/kerberos/kerberos.cnf"
proto_tree *sub_tree=tree;
kerberos_private_data_t* private_data = kerberos_get_private_data(actx);
if(actx->created_item){
sub_tree=proto_item_add_subtree(actx->created_item, ett_kerberos_PA_DATA);
}
switch(private_data->padata_type){
case KRB5_PA_TGS_REQ:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_kerberos_Applications);
break;
case KRB5_PA_PK_AS_REQ:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_pkinit_PaPkAsReq);
break;
case KRB5_PA_PK_AS_REP:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_pkinit_PaPkAsRep);
break;
case KRB5_PA_PAC_REQUEST:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_kerberos_KERB_PA_PAC_REQUEST);
break;
case KRB5_PA_S4U2SELF:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_kerberos_PA_S4U2Self);
break;
case KRB5_PA_PROV_SRV_LOCATION:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_krb5_PA_PROV_SRV_LOCATION);
break;
case KRB5_PA_ENC_TIMESTAMP:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_kerberos_PA_ENC_TIMESTAMP);
break;
case KRB5_PA_ENCTYPE_INFO:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_kerberos_ETYPE_INFO);
break;
case KRB5_PA_ENCTYPE_INFO2:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_kerberos_ETYPE_INFO2);
break;
case KRB5_PA_PW_SALT:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, dissect_krb5_PW_SALT);
break;
default:
offset=dissect_ber_octet_string_wcb(FALSE, actx, sub_tree, tvb, offset,hf_index, NULL);
}
return offset;
}
static int
dissect_kerberos_PA_DATA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PA_DATA_sequence, hf_index, ett_kerberos_PA_DATA);
return offset;
}
static int
dissect_kerberos_SEQUENCE_OF_PA_DATA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_PA_DATA_sequence_of, hf_index, ett_kerberos_SEQUENCE_OF_PA_DATA);
return offset;
}
static int
dissect_kerberos_KDCOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
KDCOptions_bits, hf_index, ett_kerberos_KDCOptions,
NULL);
return offset;
}
static int
dissect_kerberos_SEQUENCE_OF_ENCTYPE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ENCTYPE_sequence_of, hf_index, ett_kerberos_SEQUENCE_OF_ENCTYPE);
return offset;
}
static int
dissect_kerberos_T_encryptedAuthorizationData_cipher(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 235 "../../asn1/kerberos/kerberos.cnf"
#ifdef HAVE_KERBEROS
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_index, dissect_krb5_decrypt_authenticator_data);
#else
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#endif
return offset;
return offset;
}
static int
dissect_kerberos_EncryptedAuthorizationData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedAuthorizationData_sequence, hf_index, ett_kerberos_EncryptedAuthorizationData);
return offset;
}
static int
dissect_kerberos_SEQUENCE_OF_Ticket(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_Ticket_sequence_of, hf_index, ett_kerberos_SEQUENCE_OF_Ticket);
return offset;
}
static int
dissect_kerberos_KDC_REQ_BODY(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 348 "../../asn1/kerberos/kerberos.cnf"
conversation_t *conversation;
if (actx->pinfo->destport == UDP_PORT_KERBEROS && actx->pinfo->ptype == PT_UDP) {
conversation = find_conversation(actx->pinfo->fd->num, &actx->pinfo->src, &actx->pinfo->dst, PT_UDP,
actx->pinfo->srcport, 0, NO_PORT_B);
if (conversation == NULL) {
conversation = conversation_new(actx->pinfo->fd->num, &actx->pinfo->src, &actx->pinfo->dst, PT_UDP,
actx->pinfo->srcport, 0, NO_PORT2);
conversation_set_dissector(conversation, kerberos_handle_udp);
}
}
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KDC_REQ_BODY_sequence, hf_index, ett_kerberos_KDC_REQ_BODY);
return offset;
}
static int
dissect_kerberos_KDC_REQ(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KDC_REQ_sequence, hf_index, ett_kerberos_KDC_REQ);
return offset;
}
static int
dissect_kerberos_AS_REQ(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 10, FALSE, dissect_kerberos_KDC_REQ);
return offset;
}
static int
dissect_kerberos_T_encryptedKDCREPData_cipher(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 243 "../../asn1/kerberos/kerberos.cnf"
#ifdef HAVE_KERBEROS
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_index, dissect_krb5_decrypt_KDC_REP_data);
#else
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#endif
return offset;
return offset;
}
static int
dissect_kerberos_EncryptedKDCREPData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedKDCREPData_sequence, hf_index, ett_kerberos_EncryptedKDCREPData);
return offset;
}
static int
dissect_kerberos_KDC_REP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KDC_REP_sequence, hf_index, ett_kerberos_KDC_REP);
return offset;
}
static int
dissect_kerberos_AS_REP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 11, FALSE, dissect_kerberos_KDC_REP);
return offset;
}
static int
dissect_kerberos_TGS_REQ(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 12, FALSE, dissect_kerberos_KDC_REQ);
return offset;
}
static int
dissect_kerberos_TGS_REP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 13, FALSE, dissect_kerberos_KDC_REP);
return offset;
}
static int
dissect_kerberos_APOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
APOptions_bits, hf_index, ett_kerberos_APOptions,
NULL);
return offset;
}
static int
dissect_kerberos_AP_REQ_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AP_REQ_U_sequence, hf_index, ett_kerberos_AP_REQ_U);
return offset;
}
static int
dissect_kerberos_AP_REQ(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 14, FALSE, dissect_kerberos_AP_REQ_U);
return offset;
}
static int
dissect_kerberos_T_encryptedAPREPData_cipher(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 259 "../../asn1/kerberos/kerberos.cnf"
#ifdef HAVE_KERBEROS
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_index, dissect_krb5_decrypt_AP_REP_data);
#else
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#endif
return offset;
return offset;
}
static int
dissect_kerberos_EncryptedAPREPData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedAPREPData_sequence, hf_index, ett_kerberos_EncryptedAPREPData);
return offset;
}
static int
dissect_kerberos_AP_REP_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AP_REP_U_sequence, hf_index, ett_kerberos_AP_REP_U);
return offset;
}
static int
dissect_kerberos_AP_REP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 15, FALSE, dissect_kerberos_AP_REP_U);
return offset;
}
static int
dissect_kerberos_T_kRB_SAFE_BODY_user_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 371 "../../asn1/kerberos/kerberos.cnf"
tvbuff_t *new_tvb;
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
call_kerberos_callbacks(actx->pinfo, tree, new_tvb, KRB_CBTAG_SAFE_USER_DATA, (kerberos_callbacks*)actx->private_data);
}
return offset;
}
static int
dissect_kerberos_KRB_SAFE_BODY(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KRB_SAFE_BODY_sequence, hf_index, ett_kerberos_KRB_SAFE_BODY);
return offset;
}
static int
dissect_kerberos_KRB_SAFE_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KRB_SAFE_U_sequence, hf_index, ett_kerberos_KRB_SAFE_U);
return offset;
}
static int
dissect_kerberos_KRB_SAFE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 20, FALSE, dissect_kerberos_KRB_SAFE_U);
return offset;
}
static int
dissect_kerberos_T_encryptedKrbPrivData_cipher(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 267 "../../asn1/kerberos/kerberos.cnf"
#ifdef HAVE_KERBEROS
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_index, dissect_krb5_decrypt_PRIV_data);
#else
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#endif
return offset;
return offset;
}
static int
dissect_kerberos_EncryptedKrbPrivData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedKrbPrivData_sequence, hf_index, ett_kerberos_EncryptedKrbPrivData);
return offset;
}
static int
dissect_kerberos_KRB_PRIV_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KRB_PRIV_U_sequence, hf_index, ett_kerberos_KRB_PRIV_U);
return offset;
}
static int
dissect_kerberos_KRB_PRIV(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 21, FALSE, dissect_kerberos_KRB_PRIV_U);
return offset;
}
static int
dissect_kerberos_T_encryptedKrbCredData_cipher(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 275 "../../asn1/kerberos/kerberos.cnf"
#ifdef HAVE_KERBEROS
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_index, dissect_krb5_decrypt_CRED_data);
#else
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#endif
return offset;
return offset;
}
static int
dissect_kerberos_EncryptedKrbCredData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncryptedKrbCredData_sequence, hf_index, ett_kerberos_EncryptedKrbCredData);
return offset;
}
static int
dissect_kerberos_KRB_CRED_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KRB_CRED_U_sequence, hf_index, ett_kerberos_KRB_CRED_U);
return offset;
}
static int
dissect_kerberos_KRB_CRED(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 22, FALSE, dissect_kerberos_KRB_CRED_U);
return offset;
}
static int
dissect_kerberos_LR_TYPE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_LastReq_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
LastReq_item_sequence, hf_index, ett_kerberos_LastReq_item);
return offset;
}
static int
dissect_kerberos_LastReq(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
LastReq_sequence_of, hf_index, ett_kerberos_LastReq);
return offset;
}
static int
dissect_kerberos_METHOD_DATA(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
METHOD_DATA_sequence_of, hf_index, ett_kerberos_METHOD_DATA);
return offset;
}
static int
dissect_kerberos_EncKDCRepPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncKDCRepPart_sequence, hf_index, ett_kerberos_EncKDCRepPart);
return offset;
}
static int
dissect_kerberos_EncASRepPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 25, FALSE, dissect_kerberos_EncKDCRepPart);
return offset;
}
static int
dissect_kerberos_EncTGSRepPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 26, FALSE, dissect_kerberos_EncKDCRepPart);
return offset;
}
static int
dissect_kerberos_EncAPRepPart_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncAPRepPart_U_sequence, hf_index, ett_kerberos_EncAPRepPart_U);
return offset;
}
static int
dissect_kerberos_EncAPRepPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 27, FALSE, dissect_kerberos_EncAPRepPart_U);
return offset;
}
static int
dissect_kerberos_T_encKrbPrivPart_user_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 378 "../../asn1/kerberos/kerberos.cnf"
tvbuff_t *new_tvb;
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_index, &new_tvb);
if (new_tvb) {
call_kerberos_callbacks(actx->pinfo, tree, new_tvb, KRB_CBTAG_PRIV_USER_DATA, (kerberos_callbacks*)actx->private_data);
}
return offset;
}
static int
dissect_kerberos_EncKrbPrivPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncKrbPrivPart_sequence, hf_index, ett_kerberos_EncKrbPrivPart);
return offset;
}
static int
dissect_kerberos_ENC_KRB_PRIV_PART(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 28, FALSE, dissect_kerberos_EncKrbPrivPart);
return offset;
}
static int
dissect_kerberos_KrbCredInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KrbCredInfo_sequence, hf_index, ett_kerberos_KrbCredInfo);
return offset;
}
static int
dissect_kerberos_SEQUENCE_OF_KrbCredInfo(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_KrbCredInfo_sequence_of, hf_index, ett_kerberos_SEQUENCE_OF_KrbCredInfo);
return offset;
}
static int
dissect_kerberos_EncKrbCredPart_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EncKrbCredPart_U_sequence, hf_index, ett_kerberos_EncKrbCredPart_U);
return offset;
}
static int
dissect_kerberos_EncKrbCredPart(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 29, FALSE, dissect_kerberos_EncKrbCredPart_U);
return offset;
}
static int
dissect_kerberos_ERROR_CODE(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 84 "../../asn1/kerberos/kerberos.cnf"
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
&krb5_errorcode);
#line 87 "../../asn1/kerberos/kerberos.cnf"
if(krb5_errorcode) {
col_add_fstr(actx->pinfo->cinfo, COL_INFO,
"KRB Error: %s",
val_to_str(krb5_errorcode, krb5_error_codes,
"Unknown error code %#x"));
}
return offset;
return offset;
}
static int
dissect_kerberos_T_e_data(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 97 "../../asn1/kerberos/kerberos.cnf"
switch(krb5_errorcode){
case KRB5_ET_KRB5KDC_ERR_BADOPTION:
case KRB5_ET_KRB5KDC_ERR_CLIENT_REVOKED:
case KRB5_ET_KRB5KDC_ERR_KEY_EXP:
case KRB5_ET_KRB5KDC_ERR_POLICY:
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_kerberos_e_data, dissect_kerberos_PA_DATA);
break;
case KRB5_ET_KRB5KDC_ERR_PREAUTH_REQUIRED:
case KRB5_ET_KRB5KDC_ERR_PREAUTH_FAILED:
case KRB5_ET_KRB5KDC_ERR_ETYPE_NOSUPP:
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_kerberos_e_data, dissect_kerberos_SEQUENCE_OF_PA_DATA);
break;
default:
offset=dissect_ber_octet_string(FALSE, actx, tree, tvb, offset, hf_kerberos_e_data, NULL);
}
return offset;
}
static int
dissect_kerberos_KRB_ERROR_U(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KRB_ERROR_U_sequence, hf_index, ett_kerberos_KRB_ERROR_U);
return offset;
}
static int
dissect_kerberos_KRB_ERROR(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_tagged_type(implicit_tag, actx, tree, tvb, offset,
hf_index, BER_CLASS_APP, 30, FALSE, dissect_kerberos_KRB_ERROR_U);
return offset;
}
static int
dissect_kerberos_Applications(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Applications_choice, hf_index, ett_kerberos_Applications,
NULL);
return offset;
}
static int
dissect_kerberos_T_pA_ENC_TIMESTAMP_cipher(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 251 "../../asn1/kerberos/kerberos.cnf"
#ifdef HAVE_KERBEROS
offset=dissect_ber_octet_string_wcb(FALSE, actx, tree, tvb, offset, hf_index, dissect_krb5_decrypt_PA_ENC_TIMESTAMP);
#else
offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
#endif
return offset;
return offset;
}
static int
dissect_kerberos_PA_ENC_TIMESTAMP(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PA_ENC_TIMESTAMP_sequence, hf_index, ett_kerberos_PA_ENC_TIMESTAMP);
return offset;
}
static int
dissect_kerberos_ETYPE_INFO_ENTRY(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ETYPE_INFO_ENTRY_sequence, hf_index, ett_kerberos_ETYPE_INFO_ENTRY);
return offset;
}
static int
dissect_kerberos_ETYPE_INFO(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ETYPE_INFO_sequence_of, hf_index, ett_kerberos_ETYPE_INFO);
return offset;
}
static int
dissect_kerberos_ETYPE_INFO2_ENTRY(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ETYPE_INFO2_ENTRY_sequence, hf_index, ett_kerberos_ETYPE_INFO2_ENTRY);
return offset;
}
static int
dissect_kerberos_ETYPE_INFO2(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
ETYPE_INFO2_sequence_of, hf_index, ett_kerberos_ETYPE_INFO2);
return offset;
}
static int
dissect_kerberos_AD_IF_RELEVANT(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_kerberos_AuthorizationData(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_kerberos_GeneralString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_restricted_string(implicit_tag, BER_UNI_TAG_GeneralString,
actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_kerberos_PA_S4U2Self(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
PA_S4U2Self_sequence, hf_index, ett_kerberos_PA_S4U2Self);
return offset;
}
static int
dissect_kerberos_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_kerberos_KERB_PA_PAC_REQUEST(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
KERB_PA_PAC_REQUEST_sequence, hf_index, ett_kerberos_KERB_PA_PAC_REQUEST);
return offset;
}
int
dissect_kerberos_ChangePasswdData(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChangePasswdData_sequence, hf_index, ett_kerberos_ChangePasswdData);
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
#line 1 "../../asn1/kerberos/packet-kerberos-hfarr.c"
{ &hf_kerberos_ticket,
{ "ticket", "kerberos.ticket_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_authenticator,
{ "authenticator", "kerberos.authenticator_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_encTicketPart,
{ "encTicketPart", "kerberos.encTicketPart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_as_req,
{ "as-req", "kerberos.as_req_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_as_rep,
{ "as-rep", "kerberos.as_rep_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_tgs_req,
{ "tgs-req", "kerberos.tgs_req_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_tgs_rep,
{ "tgs-rep", "kerberos.tgs_rep_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_ap_req,
{ "ap-req", "kerberos.ap_req_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_ap_rep,
{ "ap-rep", "kerberos.ap_rep_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_krb_safe,
{ "krb-safe", "kerberos.krb_safe_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_krb_priv,
{ "krb-priv", "kerberos.krb_priv_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_krb_cred,
{ "krb-cred", "kerberos.krb_cred_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_encASRepPart,
{ "encASRepPart", "kerberos.encASRepPart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_encTGSRepPart,
{ "encTGSRepPart", "kerberos.encTGSRepPart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_encAPRepPart,
{ "encAPRepPart", "kerberos.encAPRepPart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_encKrbPrivPart,
{ "encKrbPrivPart", "kerberos.encKrbPrivPart_element",
FT_NONE, BASE_NONE, NULL, 0,
"ENC_KRB_PRIV_PART", HFILL }},
{ &hf_kerberos_encKrbCredPart,
{ "encKrbCredPart", "kerberos.encKrbCredPart_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_krb_error,
{ "krb-error", "kerberos.krb_error_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_name_type,
{ "name-type", "kerberos.name_type",
FT_INT32, BASE_DEC, VALS(kerberos_NAME_TYPE_vals), 0,
NULL, HFILL }},
{ &hf_kerberos_name_string,
{ "name-string", "kerberos.name_string",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_KerberosString", HFILL }},
{ &hf_kerberos_name_string_item,
{ "KerberosString", "kerberos.KerberosString",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_addr_type,
{ "addr-type", "kerberos.addr_type",
FT_INT32, BASE_DEC, VALS(kerberos_ADDR_TYPE_vals), 0,
NULL, HFILL }},
{ &hf_kerberos_address,
{ "address", "kerberos.address",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_HostAddresses_item,
{ "HostAddress", "kerberos.HostAddress_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_AuthorizationData_item,
{ "AuthorizationData item", "kerberos.AuthorizationData_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_ad_type,
{ "ad-type", "kerberos.ad_type",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_ad_data,
{ "ad-data", "kerberos.ad_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_padata_type,
{ "padata-type", "kerberos.padata_type",
FT_INT32, BASE_DEC, VALS(kerberos_PADATA_TYPE_vals), 0,
NULL, HFILL }},
{ &hf_kerberos_padata_value,
{ "padata-value", "kerberos.padata_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_keytype,
{ "keytype", "kerberos.keytype",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_keyvalue,
{ "keyvalue", "kerberos.keyvalue",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_cksumtype,
{ "cksumtype", "kerberos.cksumtype",
FT_INT32, BASE_DEC, VALS(kerberos_CKSUMTYPE_vals), 0,
NULL, HFILL }},
{ &hf_kerberos_checksum,
{ "checksum", "kerberos.checksum",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_etype,
{ "etype", "kerberos.etype",
FT_INT32, BASE_DEC, VALS(kerberos_ENCTYPE_vals), 0,
"ENCTYPE", HFILL }},
{ &hf_kerberos_kvno,
{ "kvno", "kerberos.kvno",
FT_UINT32, BASE_DEC, NULL, 0,
"UInt32", HFILL }},
{ &hf_kerberos_encryptedTicketData_cipher,
{ "cipher", "kerberos.cipher",
FT_BYTES, BASE_NONE, NULL, 0,
"T_encryptedTicketData_cipher", HFILL }},
{ &hf_kerberos_encryptedAuthorizationData_cipher,
{ "cipher", "kerberos.cipher",
FT_BYTES, BASE_NONE, NULL, 0,
"T_encryptedAuthorizationData_cipher", HFILL }},
{ &hf_kerberos_encryptedKDCREPData_cipher,
{ "cipher", "kerberos.cipher",
FT_BYTES, BASE_NONE, NULL, 0,
"T_encryptedKDCREPData_cipher", HFILL }},
{ &hf_kerberos_encryptedAPREPData_cipher,
{ "cipher", "kerberos.cipher",
FT_BYTES, BASE_NONE, NULL, 0,
"T_encryptedAPREPData_cipher", HFILL }},
{ &hf_kerberos_encryptedKrbPrivData_cipher,
{ "cipher", "kerberos.cipher",
FT_BYTES, BASE_NONE, NULL, 0,
"T_encryptedKrbPrivData_cipher", HFILL }},
{ &hf_kerberos_encryptedKrbCredData_cipher,
{ "cipher", "kerberos.cipher",
FT_BYTES, BASE_NONE, NULL, 0,
"T_encryptedKrbCredData_cipher", HFILL }},
{ &hf_kerberos_tkt_vno,
{ "tkt-vno", "kerberos.tkt_vno",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_5", HFILL }},
{ &hf_kerberos_realm,
{ "realm", "kerberos.realm",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_sname,
{ "sname", "kerberos.sname_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrincipalName", HFILL }},
{ &hf_kerberos_ticket_enc_part,
{ "enc-part", "kerberos.enc_part_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedTicketData", HFILL }},
{ &hf_kerberos_flags,
{ "flags", "kerberos.flags",
FT_BYTES, BASE_NONE, NULL, 0,
"TicketFlags", HFILL }},
{ &hf_kerberos_key,
{ "key", "kerberos.key_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptionKey", HFILL }},
{ &hf_kerberos_crealm,
{ "crealm", "kerberos.crealm",
FT_STRING, BASE_NONE, NULL, 0,
"Realm", HFILL }},
{ &hf_kerberos_cname,
{ "cname", "kerberos.cname_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrincipalName", HFILL }},
{ &hf_kerberos_transited,
{ "transited", "kerberos.transited_element",
FT_NONE, BASE_NONE, NULL, 0,
"TransitedEncoding", HFILL }},
{ &hf_kerberos_authtime,
{ "authtime", "kerberos.authtime",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_starttime,
{ "starttime", "kerberos.starttime",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_endtime,
{ "endtime", "kerberos.endtime",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_renew_till,
{ "renew-till", "kerberos.renew_till",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_caddr,
{ "caddr", "kerberos.caddr",
FT_UINT32, BASE_DEC, NULL, 0,
"HostAddresses", HFILL }},
{ &hf_kerberos_authorization_data,
{ "authorization-data", "kerberos.authorization_data",
FT_UINT32, BASE_DEC, NULL, 0,
"AuthorizationData", HFILL }},
{ &hf_kerberos_tr_type,
{ "tr-type", "kerberos.tr_type",
FT_INT32, BASE_DEC, NULL, 0,
"Int32", HFILL }},
{ &hf_kerberos_contents,
{ "contents", "kerberos.contents",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_kerberos_pvno,
{ "pvno", "kerberos.pvno",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_5", HFILL }},
{ &hf_kerberos_msg_type,
{ "msg-type", "kerberos.msg_type",
FT_INT32, BASE_DEC, VALS(kerberos_MESSAGE_TYPE_vals), 0,
"MESSAGE_TYPE", HFILL }},
{ &hf_kerberos_padata,
{ "padata", "kerberos.padata",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_PA_DATA", HFILL }},
{ &hf_kerberos_padata_item,
{ "PA-DATA", "kerberos.PA_DATA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_req_body,
{ "req-body", "kerberos.req_body_element",
FT_NONE, BASE_NONE, NULL, 0,
"KDC_REQ_BODY", HFILL }},
{ &hf_kerberos_kdc_options,
{ "kdc-options", "kerberos.kdc_options",
FT_BYTES, BASE_NONE, NULL, 0,
"KDCOptions", HFILL }},
{ &hf_kerberos_from,
{ "from", "kerberos.from",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_till,
{ "till", "kerberos.till",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_rtime,
{ "rtime", "kerberos.rtime",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_nonce,
{ "nonce", "kerberos.nonce",
FT_UINT32, BASE_DEC, NULL, 0,
"UInt32", HFILL }},
{ &hf_kerberos_kDC_REQ_BODY_etype,
{ "etype", "kerberos.etype",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ENCTYPE", HFILL }},
{ &hf_kerberos_kDC_REQ_BODY_etype_item,
{ "ENCTYPE", "kerberos.ENCTYPE",
FT_INT32, BASE_DEC, VALS(kerberos_ENCTYPE_vals), 0,
NULL, HFILL }},
{ &hf_kerberos_addresses,
{ "addresses", "kerberos.addresses",
FT_UINT32, BASE_DEC, NULL, 0,
"HostAddresses", HFILL }},
{ &hf_kerberos_enc_authorization_data,
{ "enc-authorization-data", "kerberos.enc_authorization_data_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedAuthorizationData", HFILL }},
{ &hf_kerberos_additional_tickets,
{ "additional-tickets", "kerberos.additional_tickets",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Ticket", HFILL }},
{ &hf_kerberos_additional_tickets_item,
{ "Ticket", "kerberos.Ticket_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_kDC_REP_enc_part,
{ "enc-part", "kerberos.enc_part_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedKDCREPData", HFILL }},
{ &hf_kerberos_last_req,
{ "last-req", "kerberos.last_req",
FT_UINT32, BASE_DEC, NULL, 0,
"LastReq", HFILL }},
{ &hf_kerberos_key_expiration,
{ "key-expiration", "kerberos.key_expiration",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_srealm,
{ "srealm", "kerberos.srealm",
FT_STRING, BASE_NONE, NULL, 0,
"Realm", HFILL }},
{ &hf_kerberos_encrypted_pa_data,
{ "encrypted-pa-data", "kerberos.encrypted_pa_data",
FT_UINT32, BASE_DEC, NULL, 0,
"METHOD_DATA", HFILL }},
{ &hf_kerberos_LastReq_item,
{ "LastReq item", "kerberos.LastReq_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_lr_type,
{ "lr-type", "kerberos.lr_type",
FT_INT32, BASE_DEC, VALS(kerberos_LR_TYPE_vals), 0,
NULL, HFILL }},
{ &hf_kerberos_lr_value,
{ "lr-value", "kerberos.lr_value",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_ap_options,
{ "ap-options", "kerberos.ap_options",
FT_BYTES, BASE_NONE, NULL, 0,
"APOptions", HFILL }},
{ &hf_kerberos_authenticator_01,
{ "authenticator", "kerberos.authenticator_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedAuthorizationData", HFILL }},
{ &hf_kerberos_authenticator_vno,
{ "authenticator-vno", "kerberos.authenticator_vno",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_5", HFILL }},
{ &hf_kerberos_cksum,
{ "cksum", "kerberos.cksum_element",
FT_NONE, BASE_NONE, NULL, 0,
"Checksum", HFILL }},
{ &hf_kerberos_cusec,
{ "cusec", "kerberos.cusec",
FT_UINT32, BASE_DEC, NULL, 0,
"Microseconds", HFILL }},
{ &hf_kerberos_ctime,
{ "ctime", "kerberos.ctime",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_subkey,
{ "subkey", "kerberos.subkey_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptionKey", HFILL }},
{ &hf_kerberos_seq_number,
{ "seq-number", "kerberos.seq_number",
FT_UINT32, BASE_DEC, NULL, 0,
"UInt32", HFILL }},
{ &hf_kerberos_aP_REP_enc_part,
{ "enc-part", "kerberos.enc_part_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedAPREPData", HFILL }},
{ &hf_kerberos_safe_body,
{ "safe-body", "kerberos.safe_body_element",
FT_NONE, BASE_NONE, NULL, 0,
"KRB_SAFE_BODY", HFILL }},
{ &hf_kerberos_kRB_SAFE_BODY_user_data,
{ "user-data", "kerberos.user_data",
FT_BYTES, BASE_NONE, NULL, 0,
"T_kRB_SAFE_BODY_user_data", HFILL }},
{ &hf_kerberos_timestamp,
{ "timestamp", "kerberos.timestamp",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_usec,
{ "usec", "kerberos.usec",
FT_UINT32, BASE_DEC, NULL, 0,
"Microseconds", HFILL }},
{ &hf_kerberos_s_address,
{ "s-address", "kerberos.s_address_element",
FT_NONE, BASE_NONE, NULL, 0,
"HostAddress", HFILL }},
{ &hf_kerberos_r_address,
{ "r-address", "kerberos.r_address_element",
FT_NONE, BASE_NONE, NULL, 0,
"HostAddress", HFILL }},
{ &hf_kerberos_kRB_PRIV_enc_part,
{ "enc-part", "kerberos.enc_part_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedKrbPrivData", HFILL }},
{ &hf_kerberos_encKrbPrivPart_user_data,
{ "user-data", "kerberos.user_data",
FT_BYTES, BASE_NONE, NULL, 0,
"T_encKrbPrivPart_user_data", HFILL }},
{ &hf_kerberos_tickets,
{ "tickets", "kerberos.tickets",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_Ticket", HFILL }},
{ &hf_kerberos_tickets_item,
{ "Ticket", "kerberos.Ticket_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_kRB_CRED_enc_part,
{ "enc-part", "kerberos.enc_part_element",
FT_NONE, BASE_NONE, NULL, 0,
"EncryptedKrbCredData", HFILL }},
{ &hf_kerberos_ticket_info,
{ "ticket-info", "kerberos.ticket_info",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_KrbCredInfo", HFILL }},
{ &hf_kerberos_ticket_info_item,
{ "KrbCredInfo", "kerberos.KrbCredInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_prealm,
{ "prealm", "kerberos.prealm",
FT_STRING, BASE_NONE, NULL, 0,
"Realm", HFILL }},
{ &hf_kerberos_pname,
{ "pname", "kerberos.pname_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrincipalName", HFILL }},
{ &hf_kerberos_stime,
{ "stime", "kerberos.stime",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosTime", HFILL }},
{ &hf_kerberos_susec,
{ "susec", "kerberos.susec",
FT_UINT32, BASE_DEC, NULL, 0,
"Microseconds", HFILL }},
{ &hf_kerberos_error_code,
{ "error-code", "kerberos.error_code",
FT_INT32, BASE_DEC, VALS(kerberos_ERROR_CODE_vals), 0,
NULL, HFILL }},
{ &hf_kerberos_e_text,
{ "e-text", "kerberos.e_text",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosString", HFILL }},
{ &hf_kerberos_e_data,
{ "e-data", "kerberos.e_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_e_checksum,
{ "e-checksum", "kerberos.e_checksum_element",
FT_NONE, BASE_NONE, NULL, 0,
"Checksum", HFILL }},
{ &hf_kerberos_METHOD_DATA_item,
{ "PA-DATA", "kerberos.PA_DATA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_pA_ENC_TIMESTAMP_cipher,
{ "cipher", "kerberos.cipher",
FT_BYTES, BASE_NONE, NULL, 0,
"T_pA_ENC_TIMESTAMP_cipher", HFILL }},
{ &hf_kerberos_salt,
{ "salt", "kerberos.salt",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_kerberos_ETYPE_INFO_item,
{ "ETYPE-INFO-ENTRY", "kerberos.ETYPE_INFO_ENTRY_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_salt_01,
{ "salt", "kerberos.salt",
FT_STRING, BASE_NONE, NULL, 0,
"KerberosString", HFILL }},
{ &hf_kerberos_s2kparams,
{ "s2kparams", "kerberos.s2kparams",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_kerberos_ETYPE_INFO2_item,
{ "ETYPE-INFO2-ENTRY", "kerberos.ETYPE_INFO2_ENTRY_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_kerberos_name,
{ "name", "kerberos.name_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrincipalName", HFILL }},
{ &hf_kerberos_auth,
{ "auth", "kerberos.auth",
FT_STRING, BASE_NONE, NULL, 0,
"GeneralString", HFILL }},
{ &hf_kerberos_include_pac,
{ "include-pac", "kerberos.include_pac",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_kerberos_newpasswd,
{ "newpasswd", "kerberos.newpasswd",
FT_BYTES, BASE_NONE, NULL, 0,
"OCTET_STRING", HFILL }},
{ &hf_kerberos_targname,
{ "targname", "kerberos.targname_element",
FT_NONE, BASE_NONE, NULL, 0,
"PrincipalName", HFILL }},
{ &hf_kerberos_targrealm,
{ "targrealm", "kerberos.targrealm",
FT_STRING, BASE_NONE, NULL, 0,
"Realm", HFILL }},
{ &hf_kerberos_APOptions_reserved,
{ "reserved", "kerberos.reserved",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_kerberos_APOptions_use_session_key,
{ "use-session-key", "kerberos.use-session-key",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_kerberos_APOptions_mutual_required,
{ "mutual-required", "kerberos.mutual-required",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_reserved,
{ "reserved", "kerberos.reserved",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_forwardable,
{ "forwardable", "kerberos.forwardable",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_forwarded,
{ "forwarded", "kerberos.forwarded",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_proxiable,
{ "proxiable", "kerberos.proxiable",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_proxy,
{ "proxy", "kerberos.proxy",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_may_postdate,
{ "may-postdate", "kerberos.may-postdate",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_postdated,
{ "postdated", "kerberos.postdated",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_invalid,
{ "invalid", "kerberos.invalid",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_renewable,
{ "renewable", "kerberos.renewable",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_initial,
{ "initial", "kerberos.initial",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_pre_authent,
{ "pre-authent", "kerberos.pre-authent",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_hw_authent,
{ "hw-authent", "kerberos.hw-authent",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_transited_policy_checked,
{ "transited-policy-checked", "kerberos.transited-policy-checked",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_ok_as_delegate,
{ "ok-as-delegate", "kerberos.ok-as-delegate",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_kerberos_TicketFlags_anonymous,
{ "anonymous", "kerberos.anonymous",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_reserved,
{ "reserved", "kerberos.reserved",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_forwardable,
{ "forwardable", "kerberos.forwardable",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_forwarded,
{ "forwarded", "kerberos.forwarded",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_proxiable,
{ "proxiable", "kerberos.proxiable",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_proxy,
{ "proxy", "kerberos.proxy",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_allow_postdate,
{ "allow-postdate", "kerberos.allow-postdate",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_postdated,
{ "postdated", "kerberos.postdated",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_unused7,
{ "unused7", "kerberos.unused7",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_renewable,
{ "renewable", "kerberos.renewable",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_unused9,
{ "unused9", "kerberos.unused9",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_unused10,
{ "unused10", "kerberos.unused10",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_opt_hardware_auth,
{ "opt-hardware-auth", "kerberos.opt-hardware-auth",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_request_anonymous,
{ "request-anonymous", "kerberos.request-anonymous",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_canonicalize,
{ "canonicalize", "kerberos.canonicalize",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_constrained_delegation,
{ "constrained-delegation", "kerberos.constrained-delegation",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_disable_transited_check,
{ "disable-transited-check", "kerberos.disable-transited-check",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_renewable_ok,
{ "renewable-ok", "kerberos.renewable-ok",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_enc_tkt_in_skey,
{ "enc-tkt-in-skey", "kerberos.enc-tkt-in-skey",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_renew,
{ "renew", "kerberos.renew",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_kerberos_KDCOptions_validate,
{ "validate", "kerberos.validate",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
#line 1957 "../../asn1/kerberos/packet-kerberos-template.c"
};
static gint *ett[] = {
&ett_kerberos,
&ett_krb_recordmark,
#line 1 "../../asn1/kerberos/packet-kerberos-ettarr.c"
&ett_kerberos_Applications,
&ett_kerberos_PrincipalName,
&ett_kerberos_SEQUENCE_OF_KerberosString,
&ett_kerberos_HostAddress,
&ett_kerberos_HostAddresses,
&ett_kerberos_AuthorizationData,
&ett_kerberos_AuthorizationData_item,
&ett_kerberos_PA_DATA,
&ett_kerberos_EncryptionKey,
&ett_kerberos_Checksum,
&ett_kerberos_EncryptedTicketData,
&ett_kerberos_EncryptedAuthorizationData,
&ett_kerberos_EncryptedKDCREPData,
&ett_kerberos_EncryptedAPREPData,
&ett_kerberos_EncryptedKrbPrivData,
&ett_kerberos_EncryptedKrbCredData,
&ett_kerberos_Ticket_U,
&ett_kerberos_EncTicketPart_U,
&ett_kerberos_TransitedEncoding,
&ett_kerberos_KDC_REQ,
&ett_kerberos_SEQUENCE_OF_PA_DATA,
&ett_kerberos_KDC_REQ_BODY,
&ett_kerberos_SEQUENCE_OF_ENCTYPE,
&ett_kerberos_SEQUENCE_OF_Ticket,
&ett_kerberos_KDC_REP,
&ett_kerberos_EncKDCRepPart,
&ett_kerberos_LastReq,
&ett_kerberos_LastReq_item,
&ett_kerberos_AP_REQ_U,
&ett_kerberos_Authenticator_U,
&ett_kerberos_AP_REP_U,
&ett_kerberos_EncAPRepPart_U,
&ett_kerberos_KRB_SAFE_U,
&ett_kerberos_KRB_SAFE_BODY,
&ett_kerberos_KRB_PRIV_U,
&ett_kerberos_EncKrbPrivPart,
&ett_kerberos_KRB_CRED_U,
&ett_kerberos_EncKrbCredPart_U,
&ett_kerberos_SEQUENCE_OF_KrbCredInfo,
&ett_kerberos_KrbCredInfo,
&ett_kerberos_KRB_ERROR_U,
&ett_kerberos_METHOD_DATA,
&ett_kerberos_PA_ENC_TIMESTAMP,
&ett_kerberos_ETYPE_INFO_ENTRY,
&ett_kerberos_ETYPE_INFO,
&ett_kerberos_ETYPE_INFO2_ENTRY,
&ett_kerberos_ETYPE_INFO2,
&ett_kerberos_APOptions,
&ett_kerberos_TicketFlags,
&ett_kerberos_KDCOptions,
&ett_kerberos_PA_S4U2Self,
&ett_kerberos_KERB_PA_PAC_REQUEST,
&ett_kerberos_ChangePasswdData,
#line 1964 "../../asn1/kerberos/packet-kerberos-template.c"
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
