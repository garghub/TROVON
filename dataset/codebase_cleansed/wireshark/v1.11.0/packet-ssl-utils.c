gint ssl_get_keyex_alg(gint cipher)
{
switch(cipher) {
case 0x0001:
case 0x0002:
case 0x0003:
case 0x0004:
case 0x0005:
case 0x0006:
case 0x0007:
case 0x0008:
case 0x0009:
case 0x000a:
case 0x002f:
case 0x0035:
case 0x003b:
case 0x003c:
case 0x003d:
case 0x0041:
case 0x0060:
case 0x0061:
case 0x0062:
case 0x0064:
case 0x0084:
case 0x0096:
case 0x009c:
case 0x009d:
case 0x00ba:
case 0x00c0:
case 0xfefe:
case 0xfeff:
case 0xffe0:
case 0xffe1:
return KEX_RSA;
case 0x000b:
case 0x000c:
case 0x000d:
case 0x000e:
case 0x000f:
case 0x0010:
case 0x0011:
case 0x0012:
case 0x0013:
case 0x0014:
case 0x0015:
case 0x0016:
case 0x0017:
case 0x0018:
case 0x0019:
case 0x001a:
case 0x001b:
case 0x002d:
case 0x0030:
case 0x0031:
case 0x0032:
case 0x0033:
case 0x0034:
case 0x0036:
case 0x0037:
case 0x0038:
case 0x0039:
case 0x003a:
case 0x003e:
case 0x003f:
case 0x0040:
case 0x0042:
case 0x0043:
case 0x0044:
case 0x0045:
case 0x0046:
case 0x0063:
case 0x0065:
case 0x0066:
case 0x0067:
case 0x0068:
case 0x0069:
case 0x006a:
case 0x006b:
case 0x006c:
case 0x006d:
case 0x0085:
case 0x0086:
case 0x0087:
case 0x0088:
case 0x0089:
case 0x008e:
case 0x008f:
case 0x0090:
case 0x0091:
case 0x0097:
case 0x0098:
case 0x0099:
case 0x009a:
case 0x009b:
case 0x009e:
case 0x009f:
case 0x00a0:
case 0x00a1:
case 0x00a2:
case 0x00a3:
case 0x00a4:
case 0x00a5:
case 0x00a6:
case 0x00a7:
case 0x00aa:
case 0x00ab:
case 0x00b2:
case 0x00b3:
case 0x00b4:
case 0x00b5:
case 0x00bb:
case 0x00bc:
case 0x00bd:
case 0x00be:
case 0x00bf:
case 0x00c1:
case 0x00c2:
case 0x00c3:
case 0x00c4:
case 0x00c5:
return KEX_DH;
case 0xc001:
case 0xc002:
case 0xc003:
case 0xc004:
case 0xc005:
case 0xc006:
case 0xc007:
case 0xc008:
case 0xc009:
case 0xc00a:
case 0xc00b:
case 0xc00c:
case 0xc00d:
case 0xc00e:
case 0xc00f:
case 0xc010:
case 0xc011:
case 0xc012:
case 0xc013:
case 0xc014:
case 0xc015:
case 0xc016:
case 0xc017:
case 0xc018:
case 0xc019:
case 0xc023:
case 0xc024:
case 0xc025:
case 0xc026:
case 0xc027:
case 0xc028:
case 0xc029:
case 0xc02a:
case 0xc02b:
case 0xc02c:
case 0xc02d:
case 0xc02e:
case 0xc02f:
case 0xc030:
case 0xc031:
case 0xc032:
case 0xc033:
case 0xc034:
case 0xc035:
case 0xc036:
case 0xc037:
case 0xc038:
case 0xc039:
case 0xc03a:
case 0xc03b:
return KEX_ECDH;
case 0x002C:
case 0x008A:
case 0x008B:
case 0x008C:
case 0x008D:
case 0x00A8:
case 0x00A9:
case 0x00AE:
case 0x00AF:
case 0x00B0:
case 0x00B1:
case 0xC064:
case 0xC065:
case 0xC06A:
case 0xC06B:
case 0xC08E:
case 0xC08F:
case 0xC094:
case 0xC095:
case 0xC0A4:
case 0xC0A5:
case 0xC0A8:
case 0xC0A9:
case 0xC0AA:
case 0xC0AB:
return KEX_PSK;
case 0x002E:
case 0x0092:
case 0x0093:
case 0x0094:
case 0x0095:
case 0x00AC:
case 0x00AD:
case 0x00B6:
case 0x00B7:
case 0x00B8:
case 0x00B9:
case 0xC068:
case 0xC069:
case 0xC06E:
case 0xC06F:
case 0xC092:
case 0xC093:
case 0xC098:
case 0xC099:
return KEX_RSA_PSK;
default:
break;
}
return 0;
}
static gint
ssl_data_alloc(StringInfo* str, size_t len)
{
str->data = (guchar *)g_malloc(len);
if (len > 0 && !str->data)
return -1;
str->data_len = (guint) len;
return 0;
}
void
ssl_data_set(StringInfo* str, const guchar* data, guint len)
{
memcpy(str->data, data, len);
str->data_len = len;
}
static inline gint
ssl_hmac_init(SSL_HMAC* md, const void * key, gint len, gint algo)
{
gcry_error_t err;
const char *err_str, *err_src;
err = gcry_md_open(md,algo, GCRY_MD_FLAG_HMAC);
if (err != 0) {
err_str = gcry_strerror(err);
err_src = gcry_strsource(err);
ssl_debug_printf("ssl_hmac_init(): gcry_md_open failed %s/%s", err_str, err_src);
return -1;
}
gcry_md_setkey (*(md), key, len);
return 0;
}
static inline void
ssl_hmac_update(SSL_HMAC* md, const void* data, gint len)
{
gcry_md_write(*(md), data, len);
}
static inline void
ssl_hmac_final(SSL_HMAC* md, guchar* data, guint* datalen)
{
gint algo;
guint len;
algo = gcry_md_get_algo (*(md));
len = gcry_md_get_algo_dlen(algo);
memcpy(data, gcry_md_read(*(md), algo), len);
*datalen = len;
}
static inline void
ssl_hmac_cleanup(SSL_HMAC* md)
{
gcry_md_close(*(md));
}
static inline gint
ssl_md_init(SSL_MD* md, gint algo)
{
gcry_error_t err;
const char *err_str, *err_src;
err = gcry_md_open(md,algo, 0);
if (err != 0) {
err_str = gcry_strerror(err);
err_src = gcry_strsource(err);
ssl_debug_printf("ssl_md_init(): gcry_md_open failed %s/%s", err_str, err_src);
return -1;
}
return 0;
}
static inline void
ssl_md_update(SSL_MD* md, guchar* data, gint len)
{
gcry_md_write(*(md), data, len);
}
static inline void
ssl_md_final(SSL_MD* md, guchar* data, guint* datalen)
{
gint algo;
gint len;
algo = gcry_md_get_algo (*(md));
len = gcry_md_get_algo_dlen (algo);
memcpy(data, gcry_md_read(*(md), algo), len);
*datalen = len;
}
static inline void
ssl_md_cleanup(SSL_MD* md)
{
gcry_md_close(*(md));
}
static inline void
ssl_sha_init(SSL_SHA_CTX* md)
{
gcry_md_open(md,GCRY_MD_SHA1, 0);
}
static inline void
ssl_sha_update(SSL_SHA_CTX* md, guchar* data, gint len)
{
gcry_md_write(*(md), data, len);
}
static inline void
ssl_sha_final(guchar* buf, SSL_SHA_CTX* md)
{
memcpy(buf, gcry_md_read(*(md), GCRY_MD_SHA1),
gcry_md_get_algo_dlen(GCRY_MD_SHA1));
}
static inline void
ssl_sha_cleanup(SSL_SHA_CTX* md)
{
gcry_md_close(*(md));
}
static inline gint
ssl_md5_init(SSL_MD5_CTX* md)
{
return gcry_md_open(md,GCRY_MD_MD5, 0);
}
static inline void
ssl_md5_update(SSL_MD5_CTX* md, guchar* data, gint len)
{
gcry_md_write(*(md), data, len);
}
static inline void
ssl_md5_final(guchar* buf, SSL_MD5_CTX* md)
{
memcpy(buf, gcry_md_read(*(md), GCRY_MD_MD5),
gcry_md_get_algo_dlen(GCRY_MD_MD5));
}
static inline void
ssl_md5_cleanup(SSL_MD5_CTX* md)
{
gcry_md_close(*(md));
}
gint
ssl_cipher_setiv(SSL_CIPHER_CTX *cipher, guchar* iv, gint iv_len)
{
gint ret;
#if 0
guchar *ivp;
gint i;
gcry_cipher_hd_t c;
c=(gcry_cipher_hd_t)*cipher;
#endif
ssl_debug_printf("--------------------------------------------------------------------");
#if 0
for(ivp=c->iv,i=0; i < iv_len; i++ )
{
ssl_debug_printf("%d ",ivp[i]);
i++;
}
#endif
ssl_debug_printf("--------------------------------------------------------------------");
ret = gcry_cipher_setiv(*(cipher), iv, iv_len);
#if 0
for(ivp=c->iv,i=0; i < iv_len; i++ )
{
ssl_debug_printf("%d ",ivp[i]);
i++;
}
#endif
ssl_debug_printf("--------------------------------------------------------------------");
return ret;
}
static gint
ssl_cipher_init(gcry_cipher_hd_t *cipher, gint algo, guchar* sk,
guchar* iv, gint mode)
{
gint gcry_modes[]={GCRY_CIPHER_MODE_STREAM,GCRY_CIPHER_MODE_CBC,GCRY_CIPHER_MODE_CTR};
gint err;
if (algo == -1) {
*(cipher) = (gcry_cipher_hd_t)-1;
return 0;
}
err = gcry_cipher_open(cipher, algo, gcry_modes[mode], 0);
if (err !=0)
return -1;
err = gcry_cipher_setkey(*(cipher), sk, gcry_cipher_get_algo_keylen (algo));
if (err != 0)
return -1;
err = gcry_cipher_setiv(*(cipher), iv, gcry_cipher_get_algo_blklen (algo));
if (err != 0)
return -1;
return 0;
}
static inline gint
ssl_cipher_decrypt(gcry_cipher_hd_t *cipher, guchar * out, gint outl,
const guchar * in, gint inl)
{
if ((*cipher) == (gcry_cipher_hd_t)-1)
{
if (in && inl)
memcpy(out, in, outl < inl ? outl : inl);
return 0;
}
return gcry_cipher_decrypt ( *(cipher), out, outl, in, inl);
}
static inline gint
ssl_get_digest_by_name(const gchar*name)
{
return gcry_md_map_name(name);
}
static inline gint
ssl_get_cipher_by_name(const gchar* name)
{
return gcry_cipher_map_name(name);
}
static inline void
ssl_cipher_cleanup(gcry_cipher_hd_t *cipher)
{
if ((*cipher) != (gcry_cipher_hd_t)-1)
gcry_cipher_close(*cipher);
*cipher = NULL;
}
static inline gint
ssl_get_key_len(SSL_PRIVATE_KEY* pk) {return gcry_pk_get_nbits (pk); }
const gchar*
ssl_private_key_to_str(SSL_PRIVATE_KEY* pk)
{
const gchar *str = "NULL";
size_t n;
gchar *buf;
if (!pk) return str;
#ifndef SSL_FAST
n = gcry_sexp_sprint(pk, GCRYSEXP_FMT_ADVANCED, NULL, 0);
buf = (gchar *)ep_alloc(n);
str = buf;
#else
str = "TO DO: dump mpi gcry_mpi_print()";
#endif
return str;
}
int
ssl_private_decrypt(guint len, guchar* encr_data, SSL_PRIVATE_KEY* pk)
{
gint rc;
size_t decr_len;
gcry_sexp_t s_data, s_plain;
gcry_mpi_t encr_mpi;
size_t i, encr_len;
guchar* decr_data_ptr;
gcry_mpi_t text;
decr_len = 0;
encr_len = len;
text = NULL;
rc = gcry_mpi_scan(&encr_mpi, GCRYMPI_FMT_USG,encr_data, encr_len, &encr_len);
if (rc != 0 ) {
ssl_debug_printf("pcry_private_decrypt: can't convert encr_data to mpi (size %d):%s\n",
len, gcry_strerror(rc));
return 0;
}
#ifndef SSL_FAST
rc = gcry_sexp_build(&s_data, NULL, "(enc-val(rsa(a%m)))", encr_mpi);
if (rc != 0) {
ssl_debug_printf("pcry_private_decrypt: can't build encr_sexp:%s \n",
gcry_strerror(rc));
return 0;
}
rc = gcry_pk_decrypt(&s_plain, s_data, pk);
gcry_sexp_release(s_data);
if (rc != 0)
{
ssl_debug_printf("pcry_private_decrypt: can't decrypt key:%s\n",
gcry_strerror(rc));
goto out;
}
text = gcry_sexp_nth_mpi(s_plain, 0, 0);
decr_len = len;
if (gcry_mpi_print(GCRYMPI_FMT_USG, NULL, decr_len, &decr_len, text) != 0) {
ssl_debug_printf("pcry_private_decrypt: can't compute decr size:%s\n",
gcry_strerror(rc));
decr_len = 0;
goto out;
}
if (decr_len > len) {
ssl_debug_printf("pcry_private_decrypt: decrypted data is too long ?!? (%" G_GSIZE_MODIFIER "u max %d)\n",
decr_len, len);
return 0;
}
decr_data_ptr = encr_data;
if (gcry_mpi_print( GCRYMPI_FMT_USG, decr_data_ptr, decr_len, &decr_len,
text) != 0) {
ssl_debug_printf("pcry_private_decrypt: can't print decr data to mpi (size %" G_GSIZE_MODIFIER "u):%s\n",
decr_len, gcry_strerror(rc));
g_free(decr_data_ptr);
decr_len = 0;
goto out;
}
rc = 0;
for (i = 1; i < decr_len; i++) {
if (decr_data_ptr[i] == 0) {
rc = (gint) i+1;
break;
}
}
ssl_debug_printf("pcry_private_decrypt: stripping %d bytes, decr_len %" G_GSIZE_MODIFIER "u\n",
rc, decr_len);
ssl_print_data("decrypted_unstrip_pre_master", decr_data_ptr, decr_len);
g_memmove(decr_data_ptr, &decr_data_ptr[rc], decr_len - rc);
decr_len -= rc;
out:
gcry_sexp_release(s_plain);
#else
rc = _gcry_rsa_decrypt(0, &text, &encr_mpi, pk,0);
gcry_mpi_print( GCRYMPI_FMT_USG, 0, 0, &decr_len, text);
if (decr_len > len) {
ssl_debug_printf("pcry_private_decrypt: decrypted data is too long ?!? (%d max %d)\n",
decr_len, len);
return 0;
}
decr_data_ptr = encr_data;
if (gcry_mpi_print( GCRYMPI_FMT_USG, decr_data_ptr, decr_len, &decr_len,
text) != 0) {
ssl_debug_printf("pcry_private_decrypt: can't print decr data to mpi (size %d):%s\n",
decr_len, gcry_strerror(rc));
return 0;
}
rc = 0;
for (i = 1; i < decr_len; i++) {
if (decr_data_ptr[i] == 0) {
rc = i+1;
break;
}
}
ssl_debug_printf("pcry_private_decrypt: stripping %d bytes, decr_len %d\n",
rc, decr_len);
ssl_print_data("decrypted_unstrip_pre_master", decr_data_ptr, decr_len);
g_memmove(decr_data_ptr, &decr_data_ptr[rc], decr_len - rc);
decr_len -= rc;
#endif
gcry_mpi_release(text);
return (int) decr_len;
}
static gint
ssl_data_realloc(StringInfo* str, guint len)
{
str->data = (guchar *)g_realloc(str->data, len);
if (!str->data)
return -1;
str->data_len = len;
return 0;
}
static gint
ssl_data_copy(StringInfo* dst, StringInfo* src)
{
if (dst->data_len < src->data_len) {
if (ssl_data_realloc(dst, src->data_len))
return -1;
}
memcpy(dst->data, src->data, src->data_len);
dst->data_len = src->data_len;
return 0;
}
static const SslDigestAlgo *
ssl_cipher_suite_dig(SslCipherSuite *cs) {
return &digests[cs->dig - DIG_MD5];
}
int
ssl_find_cipher(int num,SslCipherSuite* cs)
{
SslCipherSuite *c;
for(c=cipher_suites;c->number!=-1;c++){
if(c->number==num){
*cs=*c;
return 0;
}
}
return -1;
}
static gint
tls_hash(StringInfo* secret, StringInfo* seed, gint md, StringInfo* out)
{
guint8 *ptr;
guint left;
gint tocpy;
guint8 *A;
guint8 _A[48],tmp[48];
guint A_l,tmp_l;
SSL_HMAC hm;
ptr = out->data;
left = out->data_len;
ssl_print_string("tls_hash: hash secret", secret);
ssl_print_string("tls_hash: hash seed", seed);
A=seed->data;
A_l=seed->data_len;
while(left){
ssl_hmac_init(&hm,secret->data,secret->data_len,md);
ssl_hmac_update(&hm,A,A_l);
ssl_hmac_final(&hm,_A,&A_l);
ssl_hmac_cleanup(&hm);
A=_A;
ssl_hmac_init(&hm,secret->data,secret->data_len,md);
ssl_hmac_update(&hm,A,A_l);
ssl_hmac_update(&hm,seed->data,seed->data_len);
ssl_hmac_final(&hm,tmp,&tmp_l);
ssl_hmac_cleanup(&hm);
tocpy=MIN(left,tmp_l);
memcpy(ptr,tmp,tocpy);
ptr+=tocpy;
left-=tocpy;
}
ssl_print_string("hash out", out);
return (0);
}
static gint
tls_prf(StringInfo* secret, const gchar *usage,
StringInfo* rnd1, StringInfo* rnd2, StringInfo* out)
{
StringInfo seed, sha_out, md5_out;
guint8 *ptr;
StringInfo s1, s2;
guint i,s_l, r;
size_t usage_len;
r = -1;
usage_len = strlen(usage);
if (ssl_data_alloc(&sha_out, MAX(out->data_len,20)) < 0) {
ssl_debug_printf("tls_prf: can't allocate sha out\n");
return -1;
}
if (ssl_data_alloc(&md5_out, MAX(out->data_len,16)) < 0) {
ssl_debug_printf("tls_prf: can't allocate md5 out\n");
goto free_sha;
}
if (ssl_data_alloc(&seed, usage_len+rnd1->data_len+rnd2->data_len) < 0) {
ssl_debug_printf("tls_prf: can't allocate rnd %d\n",
(int) (usage_len+rnd1->data_len+rnd2->data_len));
goto free_md5;
}
ptr=seed.data;
memcpy(ptr,usage,usage_len);
ptr+=usage_len;
memcpy(ptr,rnd1->data,rnd1->data_len);
ptr+=rnd1->data_len;
memcpy(ptr,rnd2->data,rnd2->data_len);
s_l=secret->data_len/2 + secret->data_len%2;
if (ssl_data_alloc(&s1, s_l) < 0) {
ssl_debug_printf("tls_prf: can't allocate secret %d\n", s_l);
goto free_seed;
}
if (ssl_data_alloc(&s2, s_l) < 0) {
ssl_debug_printf("tls_prf: can't allocate secret(2) %d\n", s_l);
goto free_s1;
}
memcpy(s1.data,secret->data,s_l);
memcpy(s2.data,secret->data + (secret->data_len - s_l),s_l);
ssl_debug_printf("tls_prf: tls_hash(md5 secret_len %d seed_len %d )\n", s1.data_len, seed.data_len);
if(tls_hash(&s1,&seed,ssl_get_digest_by_name("MD5"),&md5_out) != 0)
goto free_all;
ssl_debug_printf("tls_prf: tls_hash(sha)\n");
if(tls_hash(&s2,&seed,ssl_get_digest_by_name("SHA1"),&sha_out) != 0)
goto free_all;
for(i=0;i<out->data_len;i++)
out->data[i]=md5_out.data[i] ^ sha_out.data[i];
r =0;
ssl_print_string("PRF out",out);
free_all:
g_free(s2.data);
free_s1:
g_free(s1.data);
free_seed:
g_free(seed.data);
free_md5:
g_free(md5_out.data);
free_sha:
g_free(sha_out.data);
return r;
}
static gint
tls12_prf(gint md, StringInfo* secret, const gchar* usage, StringInfo* rnd1, StringInfo* rnd2, StringInfo* out)
{
StringInfo label_seed;
size_t usage_len;
usage_len = strlen(usage);
if (ssl_data_alloc(&label_seed, usage_len+rnd1->data_len+rnd2->data_len) < 0) {
ssl_debug_printf("tls12_prf: can't allocate label_seed\n");
return -1;
}
memcpy(label_seed.data, usage, usage_len);
memcpy(label_seed.data+usage_len, rnd1->data, rnd1->data_len);
memcpy(label_seed.data+usage_len+rnd1->data_len, rnd2->data, rnd2->data_len);
ssl_debug_printf("tls12_prf: tls_hash(hash_alg %s secret_len %d seed_len %d )\n", gcry_md_algo_name(md), secret->data_len, label_seed.data_len);
if (tls_hash(secret, &label_seed, md, out) != 0){
g_free(label_seed.data);
return -1;
}
ssl_print_string("PRF out", out);
return 0;
}
static gint
ssl3_generate_export_iv(StringInfo* r1,
StringInfo* r2, StringInfo* out)
{
SSL_MD5_CTX md5;
guint8 tmp[16];
ssl_md5_init(&md5);
ssl_md5_update(&md5,r1->data,r1->data_len);
ssl_md5_update(&md5,r2->data,r2->data_len);
ssl_md5_final(tmp,&md5);
ssl_md5_cleanup(&md5);
memcpy(out->data,tmp,out->data_len);
ssl_print_string("export iv", out);
return(0);
}
static gint
ssl3_prf(StringInfo* secret, const gchar* usage,
StringInfo* r1,
StringInfo* r2,StringInfo* out)
{
SSL_MD5_CTX md5;
SSL_SHA_CTX sha;
StringInfo *rnd1,*rnd2;
guint off;
gint i = 0,j;
guint8 buf[20];
rnd1=r1; rnd2=r2;
for(off=0;off<out->data_len;off+=16){
guchar outbuf[16];
gint tocpy;
i++;
ssl_debug_printf("ssl3_prf: sha1_hash(%d)\n",i);
for(j=0;j<i;j++){
buf[j]=64+i;
}
ssl_sha_init(&sha);
ssl_sha_update(&sha,buf,i);
ssl_sha_update(&sha,secret->data,secret->data_len);
if(!strcmp(usage,"client write key") || !strcmp(usage,"server write key")){
ssl_sha_update(&sha,rnd2->data,rnd2->data_len);
ssl_sha_update(&sha,rnd1->data,rnd1->data_len);
}
else{
ssl_sha_update(&sha,rnd1->data,rnd1->data_len);
ssl_sha_update(&sha,rnd2->data,rnd2->data_len);
}
ssl_sha_final(buf,&sha);
ssl_sha_cleanup(&sha);
ssl_debug_printf("ssl3_prf: md5_hash(%d) datalen %d\n",i,
secret->data_len);
ssl_md5_init(&md5);
ssl_md5_update(&md5,secret->data,secret->data_len);
ssl_md5_update(&md5,buf,20);
ssl_md5_final(outbuf,&md5);
ssl_md5_cleanup(&md5);
tocpy=MIN(out->data_len-off,16);
memcpy(out->data+off,outbuf,tocpy);
}
return(0);
}
static gint prf(SslDecryptSession* ssl,StringInfo* secret,const gchar* usage,StringInfo* rnd1,StringInfo* rnd2,StringInfo* out)
{
gint ret;
if (ssl->version_netorder==SSLV3_VERSION){
ret = ssl3_prf(secret,usage,rnd1,rnd2,out);
}else if (ssl->version_netorder==TLSV1_VERSION || ssl->version_netorder==TLSV1DOT1_VERSION ||
ssl->version_netorder==DTLSV1DOT0_VERSION || ssl->version_netorder==DTLSV1DOT0_VERSION_NOT){
ret = tls_prf(secret,usage,rnd1,rnd2,out);
}else{
if (ssl->cipher_suite.dig == DIG_SHA384){
ret = tls12_prf(GCRY_MD_SHA384, secret, usage, rnd1, rnd2, out);
}else{
ret = tls12_prf(GCRY_MD_SHA256, secret, usage, rnd1, rnd2, out);
}
}
return ret;
}
static SslFlow*
ssl_create_flow(void)
{
SslFlow *flow;
flow = (SslFlow *)wmem_alloc(wmem_file_scope(), sizeof(SslFlow));
flow->byte_seq = 0;
flow->flags = 0;
flow->multisegment_pdus = wmem_tree_new(wmem_file_scope());
return flow;
}
static void* ssl_zalloc(void* opaque _U_, unsigned int no, unsigned int size)
{
return g_malloc0(no*size);
}
static void ssl_zfree(void* opaque _U_, void* addr)
{
g_free(addr);
}
static SslDecompress*
ssl_create_decompressor(gint compression)
{
SslDecompress *decomp;
#ifdef HAVE_LIBZ
int err;
#endif
if (compression == 0) return NULL;
ssl_debug_printf("ssl_create_decompressor: compression method %d\n", compression);
decomp = (SslDecompress *)wmem_alloc(wmem_file_scope(), sizeof(SslDecompress));
decomp->compression = compression;
switch (decomp->compression) {
#ifdef HAVE_LIBZ
case 1:
decomp->istream.zalloc = ssl_zalloc;
decomp->istream.zfree = ssl_zfree;
decomp->istream.opaque = Z_NULL;
decomp->istream.next_in = Z_NULL;
decomp->istream.next_out = Z_NULL;
decomp->istream.avail_in = 0;
decomp->istream.avail_out = 0;
err = inflateInit_(&decomp->istream, ZLIB_VERSION, sizeof(z_stream));
if (err != Z_OK) {
ssl_debug_printf("ssl_create_decompressor: inflateInit_() failed - %d\n", err);
return NULL;
}
break;
#endif
default:
ssl_debug_printf("ssl_create_decompressor: unsupported compression method %d\n", decomp->compression);
return NULL;
}
return decomp;
}
static SslDecoder*
ssl_create_decoder(SslCipherSuite *cipher_suite, gint compression,
guint8 *mk, guint8 *sk, guint8 *iv)
{
SslDecoder *dec;
gint ciph;
dec = (SslDecoder *)wmem_alloc0(wmem_file_scope(), sizeof(SslDecoder));
if(cipher_suite->enc!=ENC_NULL) {
ssl_debug_printf("ssl_create_decoder CIPHER: %s\n", ciphers[cipher_suite->enc-0x30]);
ciph=ssl_get_cipher_by_name(ciphers[cipher_suite->enc-0x30]);
} else {
ssl_debug_printf("ssl_create_decoder CIPHER: %s\n", "NULL");
ciph = -1;
}
if (ciph == 0) {
ssl_debug_printf("ssl_create_decoder can't find cipher %s\n",
ciphers[cipher_suite->enc > ENC_NULL ? ENC_NULL : (cipher_suite->enc-0x30)]);
return NULL;
}
dec->cipher_suite=cipher_suite;
dec->compression = compression;
if (mk == NULL) {
dec->write_iv.data = dec->_mac_key_or_write_iv;
ssl_data_set(&dec->write_iv, iv, cipher_suite->block);
} else {
dec->mac_key.data = dec->_mac_key_or_write_iv;
ssl_data_set(&dec->mac_key, mk, ssl_cipher_suite_dig(cipher_suite)->len);
}
dec->seq = 0;
dec->decomp = ssl_create_decompressor(compression);
dec->flow = ssl_create_flow();
if (dec->evp)
ssl_cipher_cleanup(&dec->evp);
if (ssl_cipher_init(&dec->evp,ciph,sk,iv,cipher_suite->mode) < 0) {
ssl_debug_printf("ssl_create_decoder: can't create cipher id:%d mode:%d\n",
ciph, cipher_suite->mode);
return NULL;
}
ssl_debug_printf("decoder initialized (digest len %d)\n", ssl_cipher_suite_dig(cipher_suite)->len);
return dec;
}
int
ssl_generate_keyring_material(SslDecryptSession*ssl_session)
{
StringInfo key_block;
guint8 _iv_c[MAX_BLOCK_SIZE],_iv_s[MAX_BLOCK_SIZE];
guint8 _key_c[MAX_KEY_SIZE],_key_s[MAX_KEY_SIZE];
gint needed;
guint8 *ptr,*c_wk,*s_wk,*c_mk,*s_mk,*c_iv = _iv_c,*s_iv = _iv_s;
guint need_all = SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION;
guint need_any = SSL_MASTER_SECRET | SSL_PRE_MASTER_SECRET;
if (((ssl_session->state & need_all) != need_all) || ((ssl_session->state & need_any) == 0)) {
ssl_debug_printf("ssl_generate_keyring_material not enough data to generate key "
"(0x%02X required 0x%02X or 0x%02X)\n", ssl_session->state,
need_all|SSL_MASTER_SECRET, need_all|SSL_PRE_MASTER_SECRET);
return -1;
}
if (!(ssl_session->state & SSL_MASTER_SECRET)) {
ssl_debug_printf("ssl_generate_keyring_material:PRF(pre_master_secret)\n");
ssl_print_string("pre master secret",&ssl_session->pre_master_secret);
ssl_print_string("client random",&ssl_session->client_random);
ssl_print_string("server random",&ssl_session->server_random);
if (prf(ssl_session,&ssl_session->pre_master_secret,"master secret",
&ssl_session->client_random,
&ssl_session->server_random, &ssl_session->master_secret)) {
ssl_debug_printf("ssl_generate_keyring_material can't generate master_secret\n");
return -1;
}
ssl_print_string("master secret",&ssl_session->master_secret);
ssl_session->state &= ~SSL_PRE_MASTER_SECRET;
ssl_session->state |= SSL_MASTER_SECRET;
}
needed=ssl_cipher_suite_dig(&ssl_session->cipher_suite)->len*2;
needed+=ssl_session->cipher_suite.bits / 4;
if(ssl_session->cipher_suite.block>1)
needed+=ssl_session->cipher_suite.block*2;
key_block.data_len = needed;
key_block.data = (guchar *)g_malloc(needed);
ssl_debug_printf("ssl_generate_keyring_material sess key generation\n");
if (prf(ssl_session,&ssl_session->master_secret,"key expansion",
&ssl_session->server_random,&ssl_session->client_random,
&key_block)) {
ssl_debug_printf("ssl_generate_keyring_material can't generate key_block\n");
goto fail;
}
ssl_print_string("key expansion", &key_block);
ptr=key_block.data;
if (ssl_session->cipher_suite.mode == SSL_CIPHER_MODE_GCM) {
c_mk = s_mk = NULL;
} else {
c_mk=ptr; ptr+=ssl_cipher_suite_dig(&ssl_session->cipher_suite)->len;
s_mk=ptr; ptr+=ssl_cipher_suite_dig(&ssl_session->cipher_suite)->len;
}
c_wk=ptr; ptr+=ssl_session->cipher_suite.eff_bits/8;
s_wk=ptr; ptr+=ssl_session->cipher_suite.eff_bits/8;
if(ssl_session->cipher_suite.block>1){
c_iv=ptr; ptr+=ssl_session->cipher_suite.block;
s_iv=ptr;
}
if (ssl_session->cipher_suite.eff_bits < ssl_session->cipher_suite.bits) {
StringInfo iv_c,iv_s;
StringInfo key_c,key_s;
StringInfo k;
if(ssl_session->cipher_suite.block>1){
if(ssl_session->cipher_suite.block>MAX_BLOCK_SIZE) {
ssl_debug_printf("ssl_generate_keyring_material cipher suite block must be at most %d nut is %d\n",
MAX_BLOCK_SIZE, ssl_session->cipher_suite.block);
goto fail;
}
iv_c.data = _iv_c;
iv_c.data_len = ssl_session->cipher_suite.block;
iv_s.data = _iv_s;
iv_s.data_len = ssl_session->cipher_suite.block;
if(ssl_session->version_netorder==SSLV3_VERSION){
ssl_debug_printf("ssl_generate_keyring_material ssl3_generate_export_iv\n");
if (ssl3_generate_export_iv(&ssl_session->client_random,
&ssl_session->server_random,&iv_c)) {
ssl_debug_printf("ssl_generate_keyring_material can't generate sslv3 client iv\n");
goto fail;
}
ssl_debug_printf("ssl_generate_keyring_material ssl3_generate_export_iv(2)\n");
if (ssl3_generate_export_iv(&ssl_session->server_random,
&ssl_session->client_random,&iv_s)) {
ssl_debug_printf("ssl_generate_keyring_material can't generate sslv3 server iv\n");
goto fail;
}
}
else{
guint8 _iv_block[MAX_BLOCK_SIZE * 2];
StringInfo iv_block;
StringInfo key_null;
guint8 _key_null;
key_null.data = &_key_null;
key_null.data_len = 0;
iv_block.data = _iv_block;
iv_block.data_len = ssl_session->cipher_suite.block*2;
ssl_debug_printf("ssl_generate_keyring_material prf(iv_block)\n");
if(prf(ssl_session,&key_null, "IV block",
&ssl_session->client_random,
&ssl_session->server_random,&iv_block)) {
ssl_debug_printf("ssl_generate_keyring_material can't generate tls31 iv block\n");
goto fail;
}
memcpy(_iv_c,iv_block.data,ssl_session->cipher_suite.block);
memcpy(_iv_s,iv_block.data+ssl_session->cipher_suite.block,
ssl_session->cipher_suite.block);
}
c_iv=_iv_c;
s_iv=_iv_s;
}
if (ssl_session->version_netorder==SSLV3_VERSION){
SSL_MD5_CTX md5;
ssl_debug_printf("ssl_generate_keyring_material MD5(client_random)\n");
ssl_md5_init(&md5);
ssl_md5_update(&md5,c_wk,ssl_session->cipher_suite.eff_bits/8);
ssl_md5_update(&md5,ssl_session->client_random.data,
ssl_session->client_random.data_len);
ssl_md5_update(&md5,ssl_session->server_random.data,
ssl_session->server_random.data_len);
ssl_md5_final(_key_c,&md5);
ssl_md5_cleanup(&md5);
c_wk=_key_c;
ssl_md5_init(&md5);
ssl_debug_printf("ssl_generate_keyring_material MD5(server_random)\n");
ssl_md5_update(&md5,s_wk,ssl_session->cipher_suite.eff_bits/8);
ssl_md5_update(&md5,ssl_session->server_random.data,
ssl_session->server_random.data_len);
ssl_md5_update(&md5,ssl_session->client_random.data,
ssl_session->client_random.data_len);
ssl_md5_final(_key_s,&md5);
ssl_md5_cleanup(&md5);
s_wk=_key_s;
}
else{
key_c.data = _key_c;
key_c.data_len = sizeof(_key_c);
key_s.data = _key_s;
key_s.data_len = sizeof(_key_s);
k.data = c_wk;
k.data_len = ssl_session->cipher_suite.eff_bits/8;
ssl_debug_printf("ssl_generate_keyring_material PRF(key_c)\n");
if (prf(ssl_session,&k,"client write key",
&ssl_session->client_random,
&ssl_session->server_random, &key_c)) {
ssl_debug_printf("ssl_generate_keyring_material can't generate tll31 server key \n");
goto fail;
}
c_wk=_key_c;
k.data = s_wk;
k.data_len = ssl_session->cipher_suite.eff_bits/8;
ssl_debug_printf("ssl_generate_keyring_material PRF(key_s)\n");
if(prf(ssl_session,&k,"server write key",
&ssl_session->client_random,
&ssl_session->server_random, &key_s)) {
ssl_debug_printf("ssl_generate_keyring_material can't generate tll31 client key \n");
goto fail;
}
s_wk=_key_s;
}
}
if (c_mk != NULL) {
ssl_print_data("Client MAC key",c_mk,ssl_cipher_suite_dig(&ssl_session->cipher_suite)->len);
ssl_print_data("Server MAC key",s_mk,ssl_cipher_suite_dig(&ssl_session->cipher_suite)->len);
}
ssl_print_data("Client Write key",c_wk,ssl_session->cipher_suite.bits/8);
ssl_print_data("Server Write key",s_wk,ssl_session->cipher_suite.bits/8);
if(ssl_session->cipher_suite.block>1) {
ssl_print_data("Client Write IV",c_iv,ssl_session->cipher_suite.block);
ssl_print_data("Server Write IV",s_iv,ssl_session->cipher_suite.block);
}
else {
ssl_print_data("Client Write IV",c_iv,8);
ssl_print_data("Server Write IV",s_iv,8);
}
ssl_debug_printf("ssl_generate_keyring_material ssl_create_decoder(client)\n");
ssl_session->client_new = ssl_create_decoder(&ssl_session->cipher_suite, ssl_session->compression, c_mk, c_wk, c_iv);
if (!ssl_session->client_new) {
ssl_debug_printf("ssl_generate_keyring_material can't init client decoder\n");
goto fail;
}
ssl_debug_printf("ssl_generate_keyring_material ssl_create_decoder(server)\n");
ssl_session->server_new = ssl_create_decoder(&ssl_session->cipher_suite, ssl_session->compression, s_mk, s_wk, s_iv);
if (!ssl_session->server_new) {
ssl_debug_printf("ssl_generate_keyring_material can't init client decoder\n");
goto fail;
}
ssl_debug_printf("ssl_generate_keyring_material: client seq %d, server seq %d\n",
ssl_session->client_new->seq, ssl_session->server_new->seq);
g_free(key_block.data);
ssl_session->state |= SSL_HAVE_SESSION_KEY;
return 0;
fail:
g_free(key_block.data);
return -1;
}
void
ssl_change_cipher(SslDecryptSession *ssl_session, gboolean server)
{
ssl_debug_printf("ssl_change_cipher %s\n", (server)?"SERVER":"CLIENT");
if (server) {
ssl_session->server = ssl_session->server_new;
ssl_session->server_new = NULL;
} else {
ssl_session->client = ssl_session->client_new;
ssl_session->client_new = NULL;
}
}
int
ssl_decrypt_pre_master_secret(SslDecryptSession*ssl_session,
StringInfo* encrypted_pre_master, SSL_PRIVATE_KEY *pk)
{
gint i;
if (!encrypted_pre_master)
return -1;
if(ssl_session->cipher_suite.kex == KEX_DH) {
ssl_debug_printf("ssl_decrypt_pre_master_secret session uses DH (%d) key exchange, which is impossible to decrypt\n",
KEX_DH);
return -1;
} else if(ssl_session->cipher_suite.kex != KEX_RSA) {
ssl_debug_printf("ssl_decrypt_pre_master_secret key exchange %d different from KEX_RSA (%d)\n",
ssl_session->cipher_suite.kex, KEX_RSA);
return -1;
}
ssl_print_string("pre master encrypted",encrypted_pre_master);
ssl_debug_printf("ssl_decrypt_pre_master_secret:RSA_private_decrypt\n");
i=ssl_private_decrypt(encrypted_pre_master->data_len,
encrypted_pre_master->data, pk);
if (i!=48) {
ssl_debug_printf("ssl_decrypt_pre_master_secret wrong "
"pre_master_secret length (%d, expected %d)\n", i, 48);
return -1;
}
ssl_session->pre_master_secret.data = encrypted_pre_master->data;
ssl_session->pre_master_secret.data_len=48;
ssl_print_string("pre master secret",&ssl_session->pre_master_secret);
ssl_session->state &= ~(SSL_MASTER_SECRET|SSL_HAVE_SESSION_KEY);
ssl_session->state |= SSL_PRE_MASTER_SECRET;
return 0;
}
static gint fmt_seq(guint32 num, guint8* buf)
{
guint32 netnum;
memset(buf,0,8);
netnum=g_htonl(num);
memcpy(buf+4,&netnum,4);
return(0);
}
static gint
tls_check_mac(SslDecoder*decoder, gint ct, gint ver, guint8* data,
guint32 datalen, guint8* mac)
{
SSL_HMAC hm;
gint md;
guint32 len;
guint8 buf[48];
gint16 temp;
md=ssl_get_digest_by_name(ssl_cipher_suite_dig(decoder->cipher_suite)->name);
ssl_debug_printf("tls_check_mac mac type:%s md %d\n",
ssl_cipher_suite_dig(decoder->cipher_suite)->name, md);
if (ssl_hmac_init(&hm,decoder->mac_key.data,decoder->mac_key.data_len,md) != 0)
return -1;
fmt_seq(decoder->seq,buf);
decoder->seq++;
ssl_hmac_update(&hm,buf,8);
buf[0]=ct;
ssl_hmac_update(&hm,buf,1);
temp = g_htons(ver);
memcpy(buf, &temp, 2);
ssl_hmac_update(&hm,buf,2);
temp = g_htons(datalen);
memcpy(buf, &temp, 2);
ssl_hmac_update(&hm,buf,2);
ssl_hmac_update(&hm,data,datalen);
ssl_hmac_final(&hm,buf,&len);
ssl_hmac_cleanup(&hm);
ssl_print_data("Mac", buf, len);
if(memcmp(mac,buf,len))
return -1;
return 0;
}
int
ssl3_check_mac(SslDecoder*decoder,int ct,guint8* data,
guint32 datalen, guint8* mac)
{
SSL_MD mc;
gint md;
guint32 len;
guint8 buf[64],dgst[20];
gint pad_ct;
gint16 temp;
pad_ct=(decoder->cipher_suite->dig==DIG_SHA)?40:48;
md=ssl_get_digest_by_name(ssl_cipher_suite_dig(decoder->cipher_suite)->name);
if (ssl_md_init(&mc,md) !=0)
return -1;
ssl_md_update(&mc,decoder->mac_key.data,decoder->mac_key.data_len);
memset(buf,0x36,pad_ct);
ssl_md_update(&mc,buf,pad_ct);
fmt_seq(decoder->seq,buf);
decoder->seq++;
ssl_md_update(&mc,buf,8);
buf[0]=ct;
ssl_md_update(&mc,buf,1);
temp = g_htons(datalen);
memcpy(buf, &temp, 2);
ssl_md_update(&mc,buf,2);
ssl_md_update(&mc,data,datalen);
ssl_md_final(&mc,dgst,&len);
ssl_md_cleanup(&mc);
ssl_md_init(&mc,md);
ssl_md_update(&mc,decoder->mac_key.data,decoder->mac_key.data_len);
memset(buf,0x5c,pad_ct);
ssl_md_update(&mc,buf,pad_ct);
ssl_md_update(&mc,dgst,len);
ssl_md_final(&mc,dgst,&len);
ssl_md_cleanup(&mc);
if(memcmp(mac,dgst,len))
return -1;
return(0);
}
static gint
dtls_check_mac(SslDecoder*decoder, gint ct,int ver, guint8* data,
guint32 datalen, guint8* mac)
{
SSL_HMAC hm;
gint md;
guint32 len;
guint8 buf[20];
gint16 temp;
md=ssl_get_digest_by_name(ssl_cipher_suite_dig(decoder->cipher_suite)->name);
ssl_debug_printf("dtls_check_mac mac type:%s md %d\n",
ssl_cipher_suite_dig(decoder->cipher_suite)->name, md);
if (ssl_hmac_init(&hm,decoder->mac_key.data,decoder->mac_key.data_len,md) != 0)
return -1;
ssl_debug_printf("dtls_check_mac seq: %d epoch: %d\n",decoder->seq,decoder->epoch);
fmt_seq(decoder->seq,buf);
buf[0]=decoder->epoch>>8;
buf[1]=(guint8)decoder->epoch;
ssl_hmac_update(&hm,buf,8);
buf[0]=ct;
ssl_hmac_update(&hm,buf,1);
temp = g_htons(ver);
memcpy(buf, &temp, 2);
ssl_hmac_update(&hm,buf,2);
temp = g_htons(datalen);
memcpy(buf, &temp, 2);
ssl_hmac_update(&hm,buf,2);
ssl_hmac_update(&hm,data,datalen);
ssl_hmac_final(&hm,buf,&len);
ssl_hmac_cleanup(&hm);
ssl_print_data("Mac", buf, len);
if(memcmp(mac,buf,len))
return -1;
return(0);
}
int
ssl_decompress_record(SslDecompress* decomp, const guchar* in, guint inl, StringInfo* out_str, guint* outl)
{
gint err;
switch (decomp->compression) {
case 1:
err = Z_OK;
if (out_str->data_len < 16384) {
ssl_data_realloc(out_str, 16384);
}
decomp->istream.next_in = (guchar*)in;
decomp->istream.avail_in = inl;
decomp->istream.next_out = out_str->data;
decomp->istream.avail_out = out_str->data_len;
if (inl > 0)
err = inflate(&decomp->istream, Z_SYNC_FLUSH);
if (err != Z_OK) {
ssl_debug_printf("ssl_decompress_record: inflate() failed - %d\n", err);
return -1;
}
*outl = out_str->data_len - decomp->istream.avail_out;
break;
default:
ssl_debug_printf("ssl_decompress_record: unsupported compression method %d\n", decomp->compression);
return -1;
}
return 0;
}
int
ssl_decompress_record(SslDecompress* decomp _U_, const guchar* in _U_, guint inl _U_, StringInfo* out_str _U_, guint* outl _U_)
{
ssl_debug_printf("ssl_decompress_record: unsupported compression method %d\n", decomp->compression);
return -1;
}
int
ssl_decrypt_record(SslDecryptSession*ssl,SslDecoder* decoder, gint ct,
const guchar* in, guint inl, StringInfo* comp_str, StringInfo* out_str, guint* outl)
{
guint pad, worklen, uncomplen;
guint8 *mac;
ssl_debug_printf("ssl_decrypt_record ciphertext len %d\n", inl);
ssl_print_data("Ciphertext",in, inl);
if (inl > out_str->data_len)
{
ssl_debug_printf("ssl_decrypt_record: allocating %d bytes for decrypt data (old len %d)\n",
inl + 32, out_str->data_len);
ssl_data_realloc(out_str, inl + 32);
}
if (decoder->cipher_suite->mode == SSL_CIPHER_MODE_CBC) {
switch (ssl->version_netorder) {
case TLSV1DOT1_VERSION:
case TLSV1DOT2_VERSION:
case DTLSV1DOT0_VERSION:
case DTLSV1DOT2_VERSION:
case DTLSV1DOT0_VERSION_NOT:
if ((gint)inl < decoder->cipher_suite->block) {
ssl_debug_printf("ssl_decrypt_record failed: input %d has no space for IV %d\n",
inl, decoder->cipher_suite->block);
return -1;
}
pad = gcry_cipher_setiv(decoder->evp, in, decoder->cipher_suite->block);
if (pad != 0) {
ssl_debug_printf("ssl_decrypt_record failed: failed to set IV: %s %s\n",
gcry_strsource (pad), gcry_strerror (pad));
}
inl -= decoder->cipher_suite->block;
in += decoder->cipher_suite->block;
break;
}
}
if (decoder->cipher_suite->mode == SSL_CIPHER_MODE_GCM) {
guchar gcm_nonce[16] = { 0 };
if ((gint)inl < SSL_EX_NONCE_LEN_GCM) {
ssl_debug_printf("ssl_decrypt_record failed: input %d has no space for nonce %d\n",
inl, SSL_EX_NONCE_LEN_GCM);
return -1;
}
memcpy(gcm_nonce, decoder->write_iv.data, decoder->write_iv.data_len);
memcpy(gcm_nonce + decoder->write_iv.data_len, in, SSL_EX_NONCE_LEN_GCM);
gcm_nonce[4 + SSL_EX_NONCE_LEN_GCM + 3] = 2;
pad = gcry_cipher_setctr (decoder->evp, gcm_nonce, sizeof (gcm_nonce));
if (pad != 0) {
ssl_debug_printf("ssl_decrypt_record failed: failed to set CTR: %s %s\n",
gcry_strsource (pad), gcry_strerror (pad));
return -1;
}
inl -= SSL_EX_NONCE_LEN_GCM;
in += SSL_EX_NONCE_LEN_GCM;
}
if ((pad = ssl_cipher_decrypt(&decoder->evp, out_str->data, out_str->data_len, in, inl))!= 0) {
ssl_debug_printf("ssl_decrypt_record failed: ssl_cipher_decrypt: %s %s\n", gcry_strsource (pad),
gcry_strerror (pad));
return -1;
}
ssl_print_data("Plaintext", out_str->data, inl);
worklen=inl;
if (decoder->cipher_suite->mode == SSL_CIPHER_MODE_GCM) {
if (worklen < 16) {
ssl_debug_printf("ssl_decrypt_record failed: missing tag, work %d\n", worklen);
return -1;
}
worklen -= 16;
}
if (decoder->cipher_suite->mode == SSL_CIPHER_MODE_CBC) {
pad=out_str->data[inl-1];
if (worklen <= pad) {
ssl_debug_printf("ssl_decrypt_record failed: padding %d too large for work %d\n",
pad, worklen);
return -1;
}
worklen-=(pad+1);
ssl_debug_printf("ssl_decrypt_record found padding %d final len %d\n",
pad, worklen);
}
if (decoder->cipher_suite->mode == SSL_CIPHER_MODE_STREAM ||
decoder->cipher_suite->mode == SSL_CIPHER_MODE_CBC) {
if (ssl_cipher_suite_dig(decoder->cipher_suite)->len > (gint)worklen) {
ssl_debug_printf("ssl_decrypt_record wrong record len/padding outlen %d\n work %d\n",*outl, worklen);
return -1;
}
worklen-=ssl_cipher_suite_dig(decoder->cipher_suite)->len;
mac = out_str->data + worklen;
} else {
goto skip_mac;
}
ssl_debug_printf("checking mac (len %d, version %X, ct %d seq %d)\n",
worklen, ssl->version_netorder, ct, decoder->seq);
if(ssl->version_netorder==SSLV3_VERSION){
if(ssl3_check_mac(decoder,ct,out_str->data,worklen,mac) < 0) {
if(ssl_ignore_mac_failed) {
ssl_debug_printf("ssl_decrypt_record: mac failed, but ignored for troubleshooting ;-)\n");
}
else{
ssl_debug_printf("ssl_decrypt_record: mac failed\n");
return -1;
}
}
else{
ssl_debug_printf("ssl_decrypt_record: mac ok\n");
}
}
else if(ssl->version_netorder==TLSV1_VERSION || ssl->version_netorder==TLSV1DOT1_VERSION || ssl->version_netorder==TLSV1DOT2_VERSION){
if(tls_check_mac(decoder,ct,ssl->version_netorder,out_str->data,worklen,mac)< 0) {
if(ssl_ignore_mac_failed) {
ssl_debug_printf("ssl_decrypt_record: mac failed, but ignored for troubleshooting ;-)\n");
}
else{
ssl_debug_printf("ssl_decrypt_record: mac failed\n");
return -1;
}
}
else{
ssl_debug_printf("ssl_decrypt_record: mac ok\n");
}
}
else if(ssl->version_netorder==DTLSV1DOT0_VERSION ||
ssl->version_netorder==DTLSV1DOT2_VERSION ||
ssl->version_netorder==DTLSV1DOT0_VERSION_NOT){
if(dtls_check_mac(decoder,ct,ssl->version_netorder,out_str->data,worklen,mac)>= 0) {
ssl_debug_printf("ssl_decrypt_record: mac ok\n");
}
else if(tls_check_mac(decoder,ct,TLSV1_VERSION,out_str->data,worklen,mac)>= 0) {
ssl_debug_printf("ssl_decrypt_record: dtls rfc-compliant mac failed, but old openssl's non-rfc-compliant mac ok\n");
}
else if(ssl_ignore_mac_failed) {
ssl_debug_printf("ssl_decrypt_record: mac failed, but ignored for troubleshooting ;-)\n");
}
else{
ssl_debug_printf("ssl_decrypt_record: mac failed\n");
return -1;
}
}
skip_mac:
*outl = worklen;
if (decoder->compression > 0) {
ssl_debug_printf("ssl_decrypt_record: compression method %d\n", decoder->compression);
ssl_data_copy(comp_str, out_str);
ssl_print_data("Plaintext compressed", comp_str->data, worklen);
if (!decoder->decomp) {
ssl_debug_printf("decrypt_ssl3_record: no decoder available\n");
return -1;
}
if (ssl_decompress_record(decoder->decomp, comp_str->data, worklen, out_str, &uncomplen) < 0) return -1;
ssl_print_data("Plaintext uncompressed", out_str->data, uncomplen);
*outl = uncomplen;
}
return 0;
}
SSL_PRIVATE_KEY*
ssl_privkey_to_sexp(struct gnutls_x509_privkey_int* priv_key)
{
gnutls_datum_t rsa_datum[RSA_PARS];
size_t tmp_size;
gcry_sexp_t rsa_priv_key = NULL;
gint i;
int ret;
size_t buf_len;
unsigned char buf_keyid[32];
#ifdef SSL_FAST
gcry_mpi_t* rsa_params = g_malloc(sizeof(gcry_mpi_t)*RSA_PARS);
#else
gcry_mpi_t rsa_params[RSA_PARS];
#endif
buf_len = sizeof(buf_keyid);
ret = gnutls_x509_privkey_get_key_id(priv_key, 0, buf_keyid, &buf_len);
if (ret != 0) {
ssl_debug_printf( "gnutls_x509_privkey_get_key_id(ssl_pkey, 0, buf_keyid, &buf_len) - %s\n", gnutls_strerror(ret));
} else {
ssl_debug_printf( "Private key imported: KeyID %s\n", bytes_to_str_punct(buf_keyid, (int) buf_len, ':'));
}
if (gnutls_x509_privkey_export_rsa_raw(priv_key,
&rsa_datum[0],
&rsa_datum[1],
&rsa_datum[2],
&rsa_datum[3],
&rsa_datum[4],
&rsa_datum[5]) != 0) {
ssl_debug_printf("ssl_load_key: can't export rsa param (is a rsa private key file ?!?)\n");
#ifdef SSL_FAST
g_free(rsa_params);
#endif
return NULL;
}
for(i=0; i<RSA_PARS; i++) {
if (gcry_mpi_scan(&rsa_params[i], GCRYMPI_FMT_USG, rsa_datum[i].data, rsa_datum[i].size,&tmp_size) != 0) {
ssl_debug_printf("ssl_load_key: can't convert m rsa param to int (size %d)\n", rsa_datum[i].size);
#ifdef SSL_FAST
g_free(rsa_params);
#endif
return NULL;
}
}
if (gcry_mpi_cmp(rsa_params[3], rsa_params[4]) > 0)
{
ssl_debug_printf("ssl_load_key: swapping p and q parameters and recomputing u\n");
gcry_mpi_swap(rsa_params[3], rsa_params[4]);
gcry_mpi_invm(rsa_params[5], rsa_params[3], rsa_params[4]);
}
if (gcry_sexp_build( &rsa_priv_key, NULL,
"(private-key(rsa((n%m)(e%m)(d%m)(p%m)(q%m)(u%m))))", rsa_params[0],
rsa_params[1], rsa_params[2], rsa_params[3], rsa_params[4],
rsa_params[5]) != 0) {
ssl_debug_printf("ssl_load_key: can't build rsa private key s-exp\n");
#ifdef SSL_FAST
g_free(rsa_params);
#endif
return NULL;
}
#ifdef SSL_FAST
return rsa_params;
#else
for (i=0; i< 6; i++)
gcry_mpi_release(rsa_params[i]);
return rsa_priv_key;
#endif
}
Ssl_private_key_t *
ssl_load_key(FILE* fp)
{
gnutls_x509_privkey_t priv_key;
gnutls_datum_t key;
long size;
gint ret;
guint bytes;
Ssl_private_key_t *private_key = (Ssl_private_key_t *)g_malloc0(sizeof(Ssl_private_key_t));
gnutls_x509_privkey_init(&priv_key);
if (fseek(fp, 0, SEEK_END) < 0) {
ssl_debug_printf("ssl_load_key: can't fseek file\n");
g_free(private_key);
return NULL;
}
if ((size = ftell(fp)) < 0) {
ssl_debug_printf("ssl_load_key: can't ftell file\n");
g_free(private_key);
return NULL;
}
if (fseek(fp, 0, SEEK_SET) < 0) {
ssl_debug_printf("ssl_load_key: can't re-fseek file\n");
g_free(private_key);
return NULL;
}
key.data = (unsigned char *)g_malloc(size);
key.size = (int)size;
bytes = (guint) fread(key.data, 1, key.size, fp);
if (bytes < key.size) {
ssl_debug_printf("ssl_load_key: can't read from file %d bytes, got %d\n",
key.size, bytes);
g_free(private_key);
g_free(key.data);
return NULL;
}
if ((ret = gnutls_x509_privkey_import(priv_key, &key, GNUTLS_X509_FMT_PEM)) != GNUTLS_E_SUCCESS) {
ssl_debug_printf("ssl_load_key: can't import pem data: %s\n", gnutls_strerror(ret));
g_free(private_key);
g_free(key.data);
return NULL;
}
if (gnutls_x509_privkey_get_pk_algorithm(priv_key) != GNUTLS_PK_RSA) {
ssl_debug_printf("ssl_load_key: private key public key algorithm isn't RSA\n");
g_free(private_key);
g_free(key.data);
return NULL;
}
g_free(key.data);
private_key->x509_pkey = priv_key;
private_key->sexp_pkey = ssl_privkey_to_sexp(priv_key);
if ( !private_key->sexp_pkey ) {
g_free(private_key);
return NULL;
}
return private_key;
}
static const char *
BAGTYPE(gnutls_pkcs12_bag_type_t x) {
switch (x) {
case GNUTLS_BAG_EMPTY: return "Empty";
case GNUTLS_BAG_PKCS8_ENCRYPTED_KEY: return "PKCS#8 Encrypted key";
case GNUTLS_BAG_PKCS8_KEY: return "PKCS#8 Key";
case GNUTLS_BAG_CERTIFICATE: return "Certificate";
case GNUTLS_BAG_CRL: return "CRL";
case GNUTLS_BAG_ENCRYPTED: return "Encrypted";
case GNUTLS_BAG_UNKNOWN: return "Unknown";
default: return "<undefined>";
}
}
static Ssl_private_key_t *
ssl_load_pkcs12(FILE* fp, const gchar *cert_passwd, const char** err) {
int i, j, ret;
int rest;
unsigned char *p;
gnutls_datum_t data;
gnutls_pkcs12_bag_t bag = NULL;
gnutls_pkcs12_bag_type_t bag_type;
size_t len, buf_len;
static char buf_name[256];
static char buf_email[128];
unsigned char buf_keyid[32];
gnutls_pkcs12_t ssl_p12 = NULL;
gnutls_x509_crt_t ssl_cert = NULL;
gnutls_x509_privkey_t ssl_pkey = NULL;
Ssl_private_key_t *private_key = (Ssl_private_key_t *)g_malloc0(sizeof(Ssl_private_key_t));
*err = NULL;
rest = 4096;
data.data = (unsigned char *)g_malloc(rest);
data.size = rest;
p = data.data;
while ((len = fread(p, 1, rest, fp)) > 0) {
p += len;
rest -= (int) len;
if (!rest) {
rest = 1024;
data.data = (unsigned char *)g_realloc(data.data, data.size + rest);
p = data.data + data.size;
data.size += rest;
}
}
data.size -= rest;
ssl_debug_printf("%d bytes read\n", data.size);
if (!feof(fp)) {
*err = "Error during certificate reading.";
ssl_debug_printf("%s\n", *err);
g_free(private_key);
g_free(data.data);
return 0;
}
ret = gnutls_pkcs12_init(&ssl_p12);
if (ret < 0) {
*err = wmem_strdup_printf(wmem_file_scope(), "gnutls_pkcs12_init(&st_p12) - %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
g_free(private_key);
g_free(data.data);
return 0;
}
ret = gnutls_pkcs12_import(ssl_p12, &data, GNUTLS_X509_FMT_DER, 0);
if (ret < 0) {
*err = wmem_strdup_printf(wmem_file_scope(), "could not load PKCS#12 in DER format: %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
ret = gnutls_pkcs12_import(ssl_p12, &data, GNUTLS_X509_FMT_PEM, 0);
if (ret < 0) {
*err = wmem_strdup_printf(wmem_file_scope(), "could not load PKCS#12 in PEM format: %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
} else {
*err = NULL;
}
}
g_free(data.data);
if (ret < 0) {
g_free(private_key);
return 0;
}
ssl_debug_printf( "PKCS#12 imported\n");
for (i=0; ret==0; i++) {
if (bag) { gnutls_pkcs12_bag_deinit(bag); bag = NULL; }
ret = gnutls_pkcs12_bag_init(&bag);
if (ret < 0) continue;
ret = gnutls_pkcs12_get_bag(ssl_p12, i, bag);
if (ret < 0) continue;
for (j=0; ret==0 && j<gnutls_pkcs12_bag_get_count(bag); j++) {
bag_type = gnutls_pkcs12_bag_get_type(bag, j);
if (bag_type >= GNUTLS_BAG_UNKNOWN) continue;
ssl_debug_printf( "Bag %d/%d: %s\n", i, j, BAGTYPE(bag_type));
if (bag_type == GNUTLS_BAG_ENCRYPTED) {
ret = gnutls_pkcs12_bag_decrypt(bag, cert_passwd);
if (ret == 0) {
bag_type = gnutls_pkcs12_bag_get_type(bag, j);
if (bag_type >= GNUTLS_BAG_UNKNOWN) continue;
ssl_debug_printf( "Bag %d/%d decrypted: %s\n", i, j, BAGTYPE(bag_type));
}
}
ret = gnutls_pkcs12_bag_get_data(bag, j, &data);
if (ret < 0) continue;
switch (bag_type) {
case GNUTLS_BAG_CERTIFICATE:
ret = gnutls_x509_crt_init(&ssl_cert);
if (ret < 0) {
*err = wmem_strdup_printf(wmem_file_scope(), "gnutls_x509_crt_init(&ssl_cert) - %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
g_free(private_key);
return 0;
}
ret = gnutls_x509_crt_import(ssl_cert, &data, GNUTLS_X509_FMT_DER);
if (ret < 0) {
*err = wmem_strdup_printf(wmem_file_scope(), "gnutls_x509_crt_import(ssl_cert, &data, GNUTLS_X509_FMT_DER) - %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
g_free(private_key);
return 0;
}
buf_len = sizeof(buf_name);
ret = gnutls_x509_crt_get_dn_by_oid(ssl_cert, GNUTLS_OID_X520_COMMON_NAME, 0, 0, buf_name, &buf_len);
if (ret < 0) { g_strlcpy(buf_name, "<ERROR>", 256); }
buf_len = sizeof(buf_email);
ret = gnutls_x509_crt_get_dn_by_oid(ssl_cert, GNUTLS_OID_PKCS9_EMAIL, 0, 0, buf_email, &buf_len);
if (ret < 0) { g_strlcpy(buf_email, "<ERROR>", 128); }
buf_len = sizeof(buf_keyid);
ret = gnutls_x509_crt_get_key_id(ssl_cert, 0, buf_keyid, &buf_len);
if (ret < 0) { g_strlcpy(buf_keyid, "<ERROR>", 32); }
private_key->x509_cert = ssl_cert;
ssl_debug_printf( "Certificate imported: %s <%s>, KeyID %s\n", buf_name, buf_email, bytes_to_str(buf_keyid, (int) buf_len));
break;
case GNUTLS_BAG_PKCS8_KEY:
case GNUTLS_BAG_PKCS8_ENCRYPTED_KEY:
ret = gnutls_x509_privkey_init(&ssl_pkey);
if (ret < 0) {
*err = wmem_strdup_printf(wmem_file_scope(), "gnutls_x509_privkey_init(&ssl_pkey) - %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
g_free(private_key);
return 0;
}
ret = gnutls_x509_privkey_import_pkcs8(ssl_pkey, &data, GNUTLS_X509_FMT_DER, cert_passwd,
(bag_type==GNUTLS_BAG_PKCS8_KEY) ? GNUTLS_PKCS_PLAIN : 0);
if (ret < 0) {
*err = wmem_strdup_printf(wmem_file_scope(), "Can not decrypt private key - %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
g_free(private_key);
return 0;
}
if (gnutls_x509_privkey_get_pk_algorithm(ssl_pkey) != GNUTLS_PK_RSA) {
*err = "ssl_load_pkcs12: private key public key algorithm isn't RSA";
ssl_debug_printf("%s\n", *err);
g_free(private_key);
return 0;
}
private_key->x509_pkey = ssl_pkey;
private_key->sexp_pkey = ssl_privkey_to_sexp(ssl_pkey);
if ( !private_key->sexp_pkey ) {
*err = "ssl_load_pkcs12: could not create sexp_pkey";
ssl_debug_printf("%s\n", *err);
g_free(private_key);
return NULL;
}
break;
default: ;
}
}
}
return private_key;
}
void ssl_free_key(Ssl_private_key_t* key)
{
#ifdef SSL_FAST
gint i;
for (i=0; i< 6; i++)
gcry_mpi_release(key->sexp_pkey[i]);
#else
gcry_sexp_release(key->sexp_pkey);
#endif
if (!key->x509_cert)
gnutls_x509_crt_deinit (key->x509_cert);
if (!key->x509_pkey)
gnutls_x509_privkey_deinit(key->x509_pkey);
g_free((Ssl_private_key_t*)key);
}
gint
ssl_find_private_key(SslDecryptSession *ssl_session, GHashTable *key_hash, GTree* associations, packet_info *pinfo) {
SslService dummy;
char ip_addr_any[] = {0,0,0,0};
guint32 port = 0;
Ssl_private_key_t * private_key;
if (!ssl_session) {
return 0;
}
if (ssl_packet_from_server(ssl_session, associations, pinfo)) {
dummy.addr = pinfo->src;
dummy.port = port = pinfo->srcport;
} else {
dummy.addr = pinfo->dst;
dummy.port = port = pinfo->destport;
}
ssl_debug_printf("ssl_find_private_key server %s:%u\n",
ep_address_to_str(&dummy.addr),dummy.port);
ssl_session->private_key = 0;
private_key = (Ssl_private_key_t *)g_hash_table_lookup(key_hash, &dummy);
if (!private_key) {
ssl_debug_printf("ssl_find_private_key can't find private key for this server! Try it again with universal port 0\n");
dummy.port = 0;
private_key = (Ssl_private_key_t *)g_hash_table_lookup(key_hash, &dummy);
}
if (!private_key) {
ssl_debug_printf("ssl_find_private_key can't find private key for this server (universal port)! Try it again with universal address 0.0.0.0\n");
dummy.addr.type = AT_IPv4;
dummy.addr.len = 4;
dummy.addr.data = ip_addr_any;
dummy.port = port;
private_key = (Ssl_private_key_t *)g_hash_table_lookup(key_hash, &dummy);
}
if (!private_key) {
ssl_debug_printf("ssl_find_private_key can't find any private key!\n");
} else {
ssl_session->private_key = private_key->sexp_pkey;
}
return 0;
}
void
ssl_lib_init(void)
{
ssl_debug_printf("gnutls version: %s\n", gnutls_check_version(NULL));
}
void
ssl_lib_init(void)
{
}
Ssl_private_key_t *
ssl_load_key(FILE* fp)
{
ssl_debug_printf("ssl_load_key: impossible without gnutls. fp %p\n",fp);
return NULL;
}
Ssl_private_key_t *
ssl_load_pkcs12(FILE* fp, const gchar *cert_passwd _U_, const char** err) {
*err = NULL;
ssl_debug_printf("ssl_load_pkcs12: impossible without gnutls. fp %p\n",fp);
return NULL;
}
void
ssl_free_key(Ssl_private_key_t* key _U_)
{
}
gint
ssl_find_private_key(SslDecryptSession *ssl_session _U_, GHashTable *key_hash _U_, GTree* associations _U_, packet_info *pinfo _U_)
{
return 0;
}
int
ssl_find_cipher(int num,SslCipherSuite* cs)
{
ssl_debug_printf("ssl_find_cipher: dummy without gnutls. num %d cs %p\n",
num,cs);
return 0;
}
int
ssl_generate_keyring_material(SslDecryptSession*ssl)
{
ssl_debug_printf("ssl_generate_keyring_material: impossible without gnutls. ssl %p\n",
ssl);
return 0;
}
void
ssl_change_cipher(SslDecryptSession *ssl_session, gboolean server)
{
ssl_debug_printf("ssl_change_cipher %s: makes no sense without gnutls. ssl %p\n",
(server)?"SERVER":"CLIENT", ssl_session);
}
int
ssl_decrypt_pre_master_secret(SslDecryptSession* ssl_session,
StringInfo* encrypted_pre_master, SSL_PRIVATE_KEY *pk)
{
ssl_debug_printf("ssl_decrypt_pre_master_secret: impossible without gnutls."
" ssl %p encrypted_pre_master %p pk %p\n", ssl_session,
encrypted_pre_master, pk);
return 0;
}
int
ssl_decrypt_record(SslDecryptSession*ssl, SslDecoder* decoder, gint ct,
const guchar* in, guint inl, StringInfo* comp_str _U_, StringInfo* out, guint* outl)
{
ssl_debug_printf("ssl_decrypt_record: impossible without gnutls. ssl %p"
"decoder %p ct %d, in %p inl %d out %p outl %p\n", ssl, decoder, ct,
in, inl, out, outl);
return 0;
}
gint
ssl_cipher_setiv(SSL_CIPHER_CTX *cipher _U_, guchar* iv _U_, gint iv_len _U_)
{
ssl_debug_printf("ssl_cipher_setiv: impossible without gnutls.\n");
return 0;
}
void
ssl_session_init(SslDecryptSession* ssl_session)
{
ssl_debug_printf("ssl_session_init: initializing ptr %p size %" G_GSIZE_MODIFIER "u\n",
(void *)ssl_session, sizeof(SslDecryptSession));
ssl_session->master_secret.data = ssl_session->_master_secret;
ssl_session->session_id.data = ssl_session->_session_id;
ssl_session->client_random.data = ssl_session->_client_random;
ssl_session->server_random.data = ssl_session->_server_random;
ssl_session->master_secret.data_len = 48;
ssl_session->server_data_for_iv.data_len = 0;
ssl_session->server_data_for_iv.data = ssl_session->_server_data_for_iv;
ssl_session->client_data_for_iv.data_len = 0;
ssl_session->client_data_for_iv.data = ssl_session->_client_data_for_iv;
ssl_session->app_data_segment.data=NULL;
ssl_session->app_data_segment.data_len=0;
SET_ADDRESS(&ssl_session->srv_addr, AT_NONE, 0, NULL);
ssl_session->srv_ptype = PT_NONE;
ssl_session->srv_port = 0;
}
void
ssl_set_server(SslDecryptSession* ssl, address *addr, port_type ptype, guint32 port)
{
SE_COPY_ADDRESS(&ssl->srv_addr, addr);
ssl->srv_ptype = ptype;
ssl->srv_port = port;
}
gint
ssl_equal (gconstpointer v, gconstpointer v2)
{
const StringInfo *val1;
const StringInfo *val2;
val1 = (const StringInfo *)v;
val2 = (const StringInfo *)v2;
if (val1->data_len == val2->data_len &&
!memcmp(val1->data, val2->data, val2->data_len)) {
return 1;
}
return 0;
}
guint
ssl_hash (gconstpointer v)
{
guint l,hash;
const StringInfo* id;
const guint* cur;
hash = 0;
id = (const StringInfo*) v;
cur = (const guint*)(void*) id->data;
for (l=4; (l < id->data_len); l+=4, cur++)
hash = hash ^ (*cur);
return hash;
}
gint
ssl_private_key_equal (gconstpointer v, gconstpointer v2)
{
const SslService *val1;
const SslService *val2;
val1 = (const SslService *)v;
val2 = (const SslService *)v2;
if ((val1->port == val2->port) &&
! CMP_ADDRESS(&val1->addr, &val2->addr)) {
return 1;
}
return 0;
}
guint
ssl_private_key_hash (gconstpointer v)
{
const SslService *key;
guint l, hash, len ;
const guint* cur;
key = (const SslService *)v;
hash = key->port;
len = key->addr.len;
cur = (const guint*) key->addr.data;
for (l=4; (l<len); l+=4, cur++)
hash = hash ^ (*cur);
return hash;
}
void
ssl_private_key_free(gpointer id, gpointer key, gpointer dummy _U_)
{
if (id != NULL) {
g_free(id);
ssl_free_key((Ssl_private_key_t*) key);
}
}
void
ssl_association_add(GTree* associations, dissector_handle_t handle, guint port, const gchar *protocol, gboolean tcp, gboolean from_key_list)
{
SslAssociation* assoc;
assoc = (SslAssociation *)g_malloc(sizeof(SslAssociation));
assoc->tcp = tcp;
assoc->ssl_port = port;
assoc->info=g_strdup(protocol);
assoc->handle = find_dissector(protocol);
assoc->from_key_list = from_key_list;
ssl_debug_printf("association_add %s port %d protocol %s handle %p\n",
(assoc->tcp)?"TCP":"UDP", port, protocol, (void *)(assoc->handle));
if (!assoc->handle) {
ssl_debug_printf("association_add could not find handle for protocol '%s', try to find 'data' dissector\n", protocol);
assoc->handle = find_dissector("data");
}
if (!assoc->handle) {
fprintf(stderr, "association_add() could not find handle for protocol:%s\n",protocol);
} else {
if (port) {
if (tcp)
dissector_add_uint("tcp.port", port, handle);
else
dissector_add_uint("udp.port", port, handle);
}
g_tree_insert(associations, assoc, assoc);
dissector_add_uint("sctp.port", port, handle);
}
}
void
ssl_association_remove(GTree* associations, SslAssociation *assoc)
{
ssl_debug_printf("ssl_association_remove removing %s %u - %s handle %p\n",
(assoc->tcp)?"TCP":"UDP", assoc->ssl_port, assoc->info, (void *)(assoc->handle));
if (assoc->handle)
dissector_delete_uint((assoc->tcp)?"tcp.port":"udp.port", assoc->ssl_port, assoc->handle);
g_free(assoc->info);
g_tree_remove(associations, assoc);
g_free(assoc);
}
gint
ssl_association_cmp(gconstpointer a, gconstpointer b)
{
const SslAssociation *assoc_a=(SslAssociation *)a, *assoc_b=(SslAssociation *)b;
if (assoc_a->tcp != assoc_b->tcp) return (assoc_a->tcp)?1:-1;
return assoc_a->ssl_port - assoc_b->ssl_port;
}
SslAssociation*
ssl_association_find(GTree * associations, guint port, gboolean tcp)
{
register SslAssociation* ret;
SslAssociation assoc_tmp;
assoc_tmp.tcp = tcp;
assoc_tmp.ssl_port = port;
ret = (SslAssociation *)g_tree_lookup(associations, &assoc_tmp);
ssl_debug_printf("association_find: %s port %d found %p\n", (tcp)?"TCP":"UDP", port, (void *)ret);
return ret;
}
gint
ssl_assoc_from_key_list(gpointer key _U_, gpointer data, gpointer user_data)
{
if (((SslAssociation*)data)->from_key_list)
ep_stack_push((ep_stack_t)user_data, data);
return FALSE;
}
int
ssl_packet_from_server(SslDecryptSession* ssl, GTree* associations, packet_info *pinfo)
{
gint ret;
if (ssl && (ssl->srv_ptype != PT_NONE)) {
ret = (ssl->srv_ptype == pinfo->ptype) && (ssl->srv_port == pinfo->srcport) && ADDRESSES_EQUAL(&ssl->srv_addr, &pinfo->src);
} else {
ret = ssl_association_find(associations, pinfo->srcport, pinfo->ptype == PT_TCP) != 0;
}
ssl_debug_printf("packet_from_server: is from server - %s\n", (ret)?"TRUE":"FALSE");
return ret;
}
void
ssl_add_record_info(gint proto, packet_info *pinfo, guchar* data, gint data_len, gint record_id)
{
guchar* real_data;
SslRecordInfo* rec;
SslPacketInfo* pi;
pi = (SslPacketInfo *)p_get_proto_data(pinfo->fd, proto, 0);
if (!pi)
{
pi = (SslPacketInfo *)wmem_alloc0(wmem_file_scope(), sizeof(SslPacketInfo));
p_add_proto_data(pinfo->fd, proto, 0, pi);
}
real_data = (guchar *)wmem_alloc(wmem_file_scope(), data_len);
memcpy(real_data, data, data_len);
rec = (SslRecordInfo *)wmem_alloc(wmem_file_scope(), sizeof(SslRecordInfo));
rec->id = record_id;
rec->real_data = real_data;
rec->data_len = data_len;
rec->next= pi->handshake_data;
pi->handshake_data = rec;
}
tvbuff_t*
ssl_get_record_info(tvbuff_t *parent_tvb, int proto, packet_info *pinfo, gint record_id)
{
SslRecordInfo* rec;
SslPacketInfo* pi;
pi = (SslPacketInfo *)p_get_proto_data(pinfo->fd, proto, 0);
if (!pi)
return NULL;
for (rec = pi->handshake_data; rec; rec = rec->next)
if (rec->id == record_id)
return tvb_new_child_real_data(parent_tvb, rec->real_data, rec->data_len, rec->data_len);
return NULL;
}
void
ssl_add_data_info(gint proto, packet_info *pinfo, guchar* data, gint data_len, gint key, SslFlow *flow)
{
SslDataInfo *rec, **prec;
SslPacketInfo *pi;
pi = (SslPacketInfo *)p_get_proto_data(pinfo->fd, proto, 0);
if (!pi)
{
pi = (SslPacketInfo *)wmem_alloc0(wmem_file_scope(), sizeof(SslPacketInfo));
p_add_proto_data(pinfo->fd, proto, 0, pi);
}
rec = (SslDataInfo *)wmem_alloc(wmem_file_scope(), sizeof(SslDataInfo)+data_len);
rec->key = key;
rec->plain_data.data = (guchar*)(rec + 1);
memcpy(rec->plain_data.data, data, data_len);
rec->plain_data.data_len = data_len;
if (flow)
{
rec->seq = flow->byte_seq;
rec->nxtseq = flow->byte_seq + data_len;
rec->flow = flow;
flow->byte_seq += data_len;
}
rec->next = NULL;
prec = &pi->appl_data;
while (*prec) prec = &(*prec)->next;
*prec = rec;
ssl_debug_printf("ssl_add_data_info: new data inserted data_len = %d, seq = %u, nxtseq = %u\n",
rec->plain_data.data_len, rec->seq, rec->nxtseq);
}
SslDataInfo*
ssl_get_data_info(int proto, packet_info *pinfo, gint key)
{
SslDataInfo* rec;
SslPacketInfo* pi;
pi = (SslPacketInfo *)p_get_proto_data(pinfo->fd, proto, 0);
if (!pi) return NULL;
rec = pi->appl_data;
while (rec) {
if (rec->key == key) return rec;
rec = rec->next;
}
return NULL;
}
void
ssl_common_init(GHashTable **session_hash, StringInfo *decrypted_data, StringInfo *compressed_data)
{
if (*session_hash)
g_hash_table_destroy(*session_hash);
*session_hash = g_hash_table_new(ssl_hash, ssl_equal);
g_free(decrypted_data->data);
ssl_data_alloc(decrypted_data, 32);
g_free(compressed_data->data);
ssl_data_alloc(compressed_data, 32);
}
void
ssl_parse_key_list(const ssldecrypt_assoc_t * uats, GHashTable *key_hash, GTree* associations, dissector_handle_t handle, gboolean tcp)
{
SslService* service;
Ssl_private_key_t* private_key, *tmp_private_key;
FILE* fp = NULL;
guint32 addr_data[4];
int addr_len, at;
address_type addr_type[2] = { AT_IPv4, AT_IPv6 };
fp = ws_fopen(uats->keyfile, "rb");
if (!fp) {
fprintf(stderr, "Can't open file %s\n",uats->keyfile);
return;
}
for (at = 0; at < 2; at++) {
memset(addr_data, 0, sizeof(addr_data));
addr_len = 0;
if(addr_type[at] == AT_IPv4) {
if (strcmp(uats->ipaddr, "any") == 0 || strcmp(uats->ipaddr, "anyipv4") == 0 ||
get_host_ipaddr(uats->ipaddr, &addr_data[0])) {
addr_len = 4;
}
} else {
if(strcmp(uats->ipaddr, "any") == 0 || strcmp(uats->ipaddr, "anyipv6") == 0 ||
get_host_ipaddr6(uats->ipaddr, (struct e_in6_addr *) addr_data)) {
addr_len = 16;
}
}
if (! addr_len) {
continue;
}
if ((gint)strlen(uats->password) == 0) {
private_key = ssl_load_key(fp);
} else {
const char *err = NULL;
private_key = ssl_load_pkcs12(fp, uats->password, &err);
if (err) {
fprintf(stderr, "%s\n", err);
}
}
if (!private_key) {
fprintf(stderr,"Can't load private key from %s\n", uats->keyfile);
fclose(fp);
return;
}
service = (SslService *)g_malloc(sizeof(SslService) + addr_len);
service->addr.type = addr_type[at];
service->addr.len = addr_len;
service->addr.data = ((guchar*)service) + sizeof(SslService);
memcpy((void*)service->addr.data, addr_data, addr_len);
if(strcmp(uats->port,"start_tls")==0) {
service->port = 0;
} else {
service->port = atoi(uats->port);
}
ssl_debug_printf("ssl_init %s addr '%s' (%s) port '%d' filename '%s' password(only for p12 file) '%s'\n",
(addr_type[at] == AT_IPv4) ? "IPv4" : "IPv6", uats->ipaddr, ep_address_to_str(&service->addr),
service->port, uats->keyfile, uats->password);
ssl_debug_printf("ssl_init private key file %s successfully loaded.\n", uats->keyfile);
tmp_private_key = (Ssl_private_key_t *)g_hash_table_lookup(key_hash, service);
if (tmp_private_key) {
g_hash_table_remove(key_hash, service);
ssl_free_key(tmp_private_key);
}
g_hash_table_insert(key_hash, service, private_key);
ssl_association_add(associations, handle, service->port, uats->protocol, tcp, TRUE);
}
fclose(fp);
}
void
ssl_save_session(SslDecryptSession* ssl, GHashTable *session_hash)
{
StringInfo* session_id;
StringInfo* master_secret;
session_id = (StringInfo *)wmem_alloc0(wmem_file_scope(), sizeof(StringInfo) + ssl->session_id.data_len);
master_secret = (StringInfo *)wmem_alloc0(wmem_file_scope(), 48 + sizeof(StringInfo));
master_secret->data = ((guchar*)master_secret+sizeof(StringInfo));
session_id->data = ((guchar*)session_id+sizeof(StringInfo));
ssl_data_set(session_id, ssl->session_id.data, ssl->session_id.data_len);
ssl_data_set(master_secret, ssl->master_secret.data, ssl->master_secret.data_len);
g_hash_table_insert(session_hash, session_id, master_secret);
ssl_print_string("ssl_save_session stored session id", session_id);
ssl_print_string("ssl_save_session stored master secret", master_secret);
}
gboolean
ssl_restore_session(SslDecryptSession* ssl, GHashTable *session_hash)
{
StringInfo* ms;
ms = (StringInfo *)g_hash_table_lookup(session_hash, &ssl->session_id);
if (!ms) {
ssl_debug_printf("ssl_restore_session can't find stored session\n");
return FALSE;
}
ssl_data_set(&ssl->master_secret, ms->data, ms->data_len);
ssl->state |= SSL_MASTER_SECRET;
ssl_debug_printf("ssl_restore_session master key retrieved\n");
return TRUE;
}
int
ssl_is_valid_content_type(guint8 type)
{
if ((type >= 0x14) && (type <= 0x18))
{
return 1;
}
return 0;
}
static guint8
from_hex_char(gchar c) {
if ((c >= '0') && (c <= '9'))
return c - '0';
if ((c >= 'A') && (c <= 'F'))
return c - 'A' + 10;
if ((c >= 'a') && (c <= 'f'))
return c - 'a' + 10;
return 16;
}
static gboolean from_hex(StringInfo* out, const char* in, gsize hex_len) {
gsize i;
if (hex_len & 1)
return FALSE;
out->data_len = (guint)hex_len/2;
out->data = (guchar *)wmem_alloc(wmem_file_scope(), out->data_len);
for (i = 0; i < out->data_len; i++) {
guint8 a = from_hex_char(in[i*2]);
guint8 b = from_hex_char(in[i*2 + 1]);
if (a == 16 || b == 16)
return FALSE;
out->data[i] = a << 4 | b;
}
return TRUE;
}
static gboolean
ssl_keylog_parse_session_id(const char* line,
SslDecryptSession* ssl_session)
{
gsize len = strlen(line);
unsigned int i;
if (ssl_session->session_id.data_len == 0)
return FALSE;
if (len < 15 || memcmp(line, "RSA Session-ID:", 15) != 0)
return FALSE;
line += 15;
len -= 15;
if (len < ssl_session->session_id.data_len*2)
return FALSE;
for (i = 0; i < ssl_session->session_id.data_len; i++) {
if (from_hex_char(line[2*i]) != (ssl_session->session_id.data[i] >> 4) ||
from_hex_char(line[2*i+1]) != (ssl_session->session_id.data[i] & 15)) {
ssl_debug_printf(" line does not match session id\n");
return FALSE;
}
}
line += 2*i;
len -= 2*i;
if (len != 12 + kRSAMasterSecretLength*2 ||
memcmp(line, " Master-Key:", 12) != 0) {
return FALSE;
}
line += 12;
len -= 12;
if (!from_hex(&ssl_session->master_secret, line, len))
return FALSE;
ssl_session->state &= ~(SSL_PRE_MASTER_SECRET|SSL_HAVE_SESSION_KEY);
ssl_session->state |= SSL_MASTER_SECRET;
ssl_debug_printf("found master secret in key log\n");
return TRUE;
}
static gboolean
ssl_keylog_parse_client_random(const char* line,
SslDecryptSession* ssl_session)
{
static const unsigned int kTLSRandomSize = 32;
gsize len = strlen(line);
unsigned int i;
if (len < 14 || memcmp(line, "CLIENT_RANDOM ", 14) != 0)
return FALSE;
line += 14;
len -= 14;
if (len < kTLSRandomSize*2 ||
ssl_session->client_random.data_len != kTLSRandomSize) {
return FALSE;
}
for (i = 0; i < kTLSRandomSize; i++) {
if (from_hex_char(line[2*i]) != (ssl_session->client_random.data[i] >> 4) ||
from_hex_char(line[2*i+1]) != (ssl_session->client_random.data[i] & 15)) {
ssl_debug_printf(" line does not match client random\n");
return FALSE;
}
}
line += 2*kTLSRandomSize;
len -= 2*kTLSRandomSize;
if (len != 1 + kRSAMasterSecretLength*2 || line[0] != ' ')
return FALSE;
line++;
len--;
if (!from_hex(&ssl_session->master_secret, line, len))
return FALSE;
ssl_session->state &= ~(SSL_PRE_MASTER_SECRET|SSL_HAVE_SESSION_KEY);
ssl_session->state |= SSL_MASTER_SECRET;
ssl_debug_printf("found master secret in key log\n");
return TRUE;
}
static gboolean
ssl_keylog_parse_rsa_premaster(const char* line,
SslDecryptSession* ssl_session,
StringInfo* encrypted_pre_master)
{
static const unsigned int kRSAPremasterLength = 48;
gsize len = strlen(line);
unsigned int i;
if (encrypted_pre_master == NULL)
return FALSE;
if (encrypted_pre_master->data_len < 8)
return FALSE;
if (len < 4 || memcmp(line, "RSA ", 4) != 0)
return FALSE;
line += 4;
len -= 4;
if (len < 16)
return FALSE;
for (i = 0; i < 8; i++) {
if (from_hex_char(line[2*i]) != (encrypted_pre_master->data[i] >> 4) ||
from_hex_char(line[2*i+1]) != (encrypted_pre_master->data[i] & 15)) {
ssl_debug_printf(" line does not match encrypted pre-master secret");
return FALSE;
}
}
line += 16;
len -= 16;
if (len != 1 + kRSAPremasterLength*2 || line[0] != ' ')
return FALSE;
line++;
len--;
if (!from_hex(&ssl_session->pre_master_secret, line, len))
return FALSE;
ssl_session->state &= ~(SSL_MASTER_SECRET|SSL_HAVE_SESSION_KEY);
ssl_session->state |= SSL_PRE_MASTER_SECRET;
ssl_debug_printf("found pre-master secret in key log\n");
return TRUE;
}
int
ssl_keylog_lookup(SslDecryptSession* ssl_session,
const gchar* ssl_keylog_filename,
StringInfo* encrypted_pre_master) {
FILE* ssl_keylog;
int ret = -1;
if (!ssl_keylog_filename)
return -1;
ssl_debug_printf("trying to use SSL keylog in %s\n", ssl_keylog_filename);
ssl_keylog = ws_fopen(ssl_keylog_filename, "r");
if (!ssl_keylog) {
ssl_debug_printf("failed to open SSL keylog\n");
return -1;
}
for (;;) {
char buf[512], *line;
gsize bytes_read;
line = fgets(buf, sizeof(buf), ssl_keylog);
if (!line)
break;
bytes_read = strlen(line);
if (bytes_read > 0) {
line[bytes_read - 1] = 0;
bytes_read--;
}
if (bytes_read > 0 && line[bytes_read - 1] == '\r') {
line[bytes_read - 1] = 0;
bytes_read--;
}
ssl_debug_printf(" checking keylog line: %s\n", line);
if (ssl_keylog_parse_session_id(line, ssl_session) ||
ssl_keylog_parse_rsa_premaster(line, ssl_session,
encrypted_pre_master) ||
ssl_keylog_parse_client_random(line, ssl_session)) {
ret = 1;
break;
} else {
ssl_debug_printf(" line does not match\n");
}
}
fclose(ssl_keylog);
return ret;
}
void
ssl_set_debug(const gchar* name)
{
static gint debug_file_must_be_closed;
gint use_stderr;
debug_file_must_be_closed = 0;
use_stderr = name?(strcmp(name, SSL_DEBUG_USE_STDERR) == 0):0;
if (debug_file_must_be_closed)
fclose(ssl_debug_file);
if (use_stderr)
ssl_debug_file = stderr;
else if (!name || (strcmp(name, "") ==0))
ssl_debug_file = NULL;
else
ssl_debug_file = ws_fopen(name, "w");
if (!use_stderr && ssl_debug_file)
debug_file_must_be_closed = 1;
ssl_debug_printf("Wireshark SSL debug log \n\n");
}
void
ssl_debug_flush(void)
{
if (ssl_debug_file)
fflush(ssl_debug_file);
}
void
ssl_debug_printf(const gchar* fmt, ...)
{
va_list ap;
if (!ssl_debug_file)
return;
va_start(ap, fmt);
vfprintf(ssl_debug_file, fmt, ap);
va_end(ap);
}
void
ssl_print_data(const gchar* name, const guchar* data, size_t len)
{
size_t i, j, k;
if (!ssl_debug_file)
return;
fprintf(ssl_debug_file,"%s[%d]:\n",name, (int) len);
for (i=0; i<len; i+=16) {
fprintf(ssl_debug_file,"| ");
for (j=i, k=0; k<16 && j<len; ++j, ++k)
fprintf(ssl_debug_file,"%.2x ",data[j]);
for (; k<16; ++k)
fprintf(ssl_debug_file," ");
fputc('|', ssl_debug_file);
for (j=i, k=0; k<16 && j<len; ++j, ++k) {
guchar c = data[j];
if (!isprint(c) || (c=='\t')) c = '.';
fputc(c, ssl_debug_file);
}
for (; k<16; ++k)
fputc(' ', ssl_debug_file);
fprintf(ssl_debug_file,"|\n");
}
}
void
ssl_print_string(const gchar* name, const StringInfo* data)
{
ssl_print_data(name, data->data, data->data_len);
}
gboolean
ssldecrypt_uat_fld_ip_chk_cb(void* r _U_, const char* p, guint len _U_, const void* u1 _U_, const void* u2 _U_, const char** err)
{
if (!p || strlen(p) == 0u) {
*err = ep_strdup_printf("No IP address given.");
return FALSE;
}
*err = NULL;
return TRUE;
}
gboolean
ssldecrypt_uat_fld_port_chk_cb(void* r _U_, const char* p, guint len _U_, const void* u1 _U_, const void* u2 _U_, const char** err)
{
if (!p || strlen(p) == 0u) {
*err = ep_strdup_printf("No Port given.");
return FALSE;
}
if (strcmp(p, "start_tls") != 0){
const gint i = atoi(p);
if (i < 0 || i > 65535) {
*err = ep_strdup_printf("Invalid port given.");
return FALSE;
}
}
*err = NULL;
return TRUE;
}
gboolean
ssldecrypt_uat_fld_protocol_chk_cb(void* r _U_, const char* p, guint len _U_, const void* u1 _U_, const void* u2 _U_, const char** err)
{
if (!p || strlen(p) == 0u) {
*err = ep_strdup_printf("No protocol given.");
return FALSE;
}
if (!find_dissector(p)) {
*err = ep_strdup_printf("Could not find dissector for: '%s'\nValid dissectors are:\n%s", p, ssl_association_info());
return FALSE;
}
*err = NULL;
return TRUE;
}
gboolean
ssldecrypt_uat_fld_fileopen_chk_cb(void* r _U_, const char* p, guint len _U_, const void* u1 _U_, const void* u2 _U_, const char** err)
{
ws_statb64 st;
if (!p || strlen(p) == 0u) {
*err = ep_strdup_printf("No filename given.");
return FALSE;
} else {
if (ws_stat64(p, &st) != 0) {
*err = ep_strdup_printf("File '%s' does not exist or access is denied.", p);
return FALSE;
}
}
*err = NULL;
return TRUE;
}
gboolean
ssldecrypt_uat_fld_password_chk_cb(void* r _U_, const char* p, guint len _U_, const void* u1 _U_, const void* u2 _U_, const char ** err)
{
ssldecrypt_assoc_t* f = (ssldecrypt_assoc_t *)r;
FILE *fp = NULL;
if (p && (strlen(p) > 0u)) {
fp = ws_fopen(f->keyfile, "rb");
if (fp) {
const char *msg = NULL;
if (!ssl_load_pkcs12(fp, p, &msg)) {
fclose(fp);
*err = ep_strdup_printf("Could not load PKCS#12 key file: %s", msg);
return FALSE;
}
fclose(fp);
} else {
*err = ep_strdup_printf("Leave this field blank if the keyfile is not PKCS#12.");
return FALSE;
}
}
*err = NULL;
return TRUE;
}
