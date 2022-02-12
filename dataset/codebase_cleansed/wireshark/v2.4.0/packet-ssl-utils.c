gint ssl_get_keyex_alg(gint cipher)
{
switch(cipher) {
case 0x0017:
case 0x0018:
case 0x0019:
case 0x001a:
case 0x001b:
case 0x0034:
case 0x003a:
case 0x0046:
case 0x006c:
case 0x006d:
case 0x0089:
case 0x009b:
case 0x00a6:
case 0x00a7:
case 0x00bf:
case 0x00c5:
case 0xc084:
case 0xc085:
return KEX_DH_ANON;
case 0x000b:
case 0x000c:
case 0x000d:
case 0x0030:
case 0x0036:
case 0x003e:
case 0x0042:
case 0x0068:
case 0x0085:
case 0x0097:
case 0x00a4:
case 0x00a5:
case 0x00bb:
case 0x00c1:
case 0xc082:
case 0xc083:
return KEX_DH_DSS;
case 0x000e:
case 0x000f:
case 0x0010:
case 0x0031:
case 0x0037:
case 0x003f:
case 0x0043:
case 0x0069:
case 0x0086:
case 0x0098:
case 0x00a0:
case 0x00a1:
case 0x00bc:
case 0x00c2:
case 0xc07e:
case 0xc07f:
return KEX_DH_RSA;
case 0x0011:
case 0x0012:
case 0x0013:
case 0x0032:
case 0x0038:
case 0x0040:
case 0x0044:
case 0x0063:
case 0x0065:
case 0x0066:
case 0x006a:
case 0x0087:
case 0x0099:
case 0x00a2:
case 0x00a3:
case 0x00bd:
case 0x00c3:
case 0xc080:
case 0xc081:
return KEX_DHE_DSS;
case 0x002d:
case 0x008e:
case 0x008f:
case 0x0090:
case 0x0091:
case 0x00aa:
case 0x00ab:
case 0x00b2:
case 0x00b3:
case 0x00b4:
case 0x00b5:
case 0xc090:
case 0xc091:
case 0xc096:
case 0xc097:
case 0xc0a6:
case 0xc0a7:
case 0xc0aa:
case 0xc0ab:
case 0xccad:
case 0xe41c:
case 0xe41d:
return KEX_DHE_PSK;
case 0x0014:
case 0x0015:
case 0x0016:
case 0x0033:
case 0x0039:
case 0x0045:
case 0x0067:
case 0x006b:
case 0x0088:
case 0x009a:
case 0x009e:
case 0x009f:
case 0x00be:
case 0x00c4:
case 0xc07c:
case 0xc07d:
case 0xc09e:
case 0xc09f:
case 0xc0a2:
case 0xc0a3:
case 0xccaa:
case 0xe41e:
case 0xe41f:
return KEX_DHE_RSA;
case 0xc015:
case 0xc016:
case 0xc017:
case 0xc018:
case 0xc019:
return KEX_ECDH_ANON;
case 0xc001:
case 0xc002:
case 0xc003:
case 0xc004:
case 0xc005:
case 0xc025:
case 0xc026:
case 0xc02d:
case 0xc02e:
case 0xc074:
case 0xc075:
case 0xc088:
case 0xc089:
return KEX_ECDH_ECDSA;
case 0xc00b:
case 0xc00c:
case 0xc00d:
case 0xc00e:
case 0xc00f:
case 0xc029:
case 0xc02a:
case 0xc031:
case 0xc032:
case 0xc078:
case 0xc079:
case 0xc08c:
case 0xc08d:
return KEX_ECDH_RSA;
case 0xc006:
case 0xc007:
case 0xc008:
case 0xc009:
case 0xc00a:
case 0xc023:
case 0xc024:
case 0xc02b:
case 0xc02c:
case 0xc072:
case 0xc073:
case 0xc086:
case 0xc087:
case 0xc0ac:
case 0xc0ad:
case 0xc0ae:
case 0xc0af:
case 0xcca9:
case 0xe414:
case 0xe415:
return KEX_ECDHE_ECDSA;
case 0xc033:
case 0xc034:
case 0xc035:
case 0xc036:
case 0xc037:
case 0xc038:
case 0xc039:
case 0xc03a:
case 0xc03b:
case 0xc09a:
case 0xc09b:
case 0xccac:
case 0xe418:
case 0xe419:
return KEX_ECDHE_PSK;
case 0xc010:
case 0xc011:
case 0xc012:
case 0xc013:
case 0xc014:
case 0xc027:
case 0xc028:
case 0xc02f:
case 0xc030:
case 0xc076:
case 0xc077:
case 0xc08a:
case 0xc08b:
case 0xcca8:
case 0xe412:
case 0xe413:
return KEX_ECDHE_RSA;
case 0x001e:
case 0x001f:
case 0x0020:
case 0x0021:
case 0x0022:
case 0x0023:
case 0x0024:
case 0x0025:
case 0x0026:
case 0x0027:
case 0x0028:
case 0x0029:
case 0x002a:
case 0x002b:
return KEX_KRB5;
case 0x002c:
case 0x008a:
case 0x008b:
case 0x008c:
case 0x008d:
case 0x00a8:
case 0x00a9:
case 0x00ae:
case 0x00af:
case 0x00b0:
case 0x00b1:
case 0xc064:
case 0xc065:
case 0xc08e:
case 0xc08f:
case 0xc094:
case 0xc095:
case 0xc0a4:
case 0xc0a5:
case 0xc0a8:
case 0xc0a9:
case 0xccab:
case 0xe416:
case 0xe417:
return KEX_PSK;
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
case 0xc07a:
case 0xc07b:
case 0xc09c:
case 0xc09d:
case 0xc0a0:
case 0xc0a1:
case 0xe410:
case 0xe411:
case 0xfefe:
case 0xfeff:
case 0xffe0:
case 0xffe1:
return KEX_RSA;
case 0x002e:
case 0x0092:
case 0x0093:
case 0x0094:
case 0x0095:
case 0x00ac:
case 0x00ad:
case 0x00b6:
case 0x00b7:
case 0x00b8:
case 0x00b9:
case 0xc092:
case 0xc093:
case 0xc098:
case 0xc099:
case 0xccae:
case 0xe41a:
case 0xe41b:
return KEX_RSA_PSK;
case 0xc01a:
case 0xc01d:
case 0xc020:
return KEX_SRP_SHA;
case 0xc01c:
case 0xc01f:
case 0xc022:
return KEX_SRP_SHA_DSS;
case 0xc01b:
case 0xc01e:
case 0xc021:
return KEX_SRP_SHA_RSA;
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
DISSECTOR_ASSERT(data);
memcpy(str->data, data, len);
str->data_len = len;
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
static StringInfo *
ssl_data_clone(StringInfo *str)
{
StringInfo *cloned_str;
cloned_str = (StringInfo *) wmem_alloc0(wmem_file_scope(),
sizeof(StringInfo) + str->data_len);
cloned_str->data = (guchar *) (cloned_str + 1);
ssl_data_set(cloned_str, str->data, str->data_len);
return cloned_str;
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
static gboolean from_hex(StringInfo* out, const char* in, gsize hex_len) {
gsize i;
if (hex_len & 1)
return FALSE;
out->data = (guchar *)wmem_alloc(wmem_file_scope(), hex_len / 2);
for (i = 0; i < hex_len / 2; i++) {
int a = ws_xton(in[i*2]);
int b = ws_xton(in[i*2 + 1]);
if (a == -1 || b == -1)
return FALSE;
out->data[i] = a << 4 | b;
}
out->data_len = (guint)hex_len / 2;
return TRUE;
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
DISSECTOR_ASSERT(len <= *datalen);
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
gint gcry_modes[] = {
GCRY_CIPHER_MODE_STREAM,
GCRY_CIPHER_MODE_CBC,
#ifdef HAVE_LIBGCRYPT_AEAD
GCRY_CIPHER_MODE_GCM,
GCRY_CIPHER_MODE_CCM,
GCRY_CIPHER_MODE_CCM,
#else
GCRY_CIPHER_MODE_CTR,
GCRY_CIPHER_MODE_CTR,
GCRY_CIPHER_MODE_CTR,
#endif
#ifdef HAVE_LIBGCRYPT_CHACHA20_POLY1305
GCRY_CIPHER_MODE_POLY1305,
#else
-1,
#endif
};
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
if (mode == MODE_CBC) {
err = gcry_cipher_setiv(*(cipher), iv, gcry_cipher_get_algo_blklen(algo));
if (err != 0)
return -1;
}
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
static int
ssl_private_decrypt(const guint len, guchar* data, gcry_sexp_t pk)
{
gint rc = 0;
size_t decr_len = 0, i = 0;
gcry_sexp_t s_data = NULL, s_plain = NULL;
gcry_mpi_t encr_mpi = NULL, text = NULL;
rc = gcry_mpi_scan(&encr_mpi, GCRYMPI_FMT_USG, data, len, NULL);
if (rc != 0 ) {
ssl_debug_printf("pcry_private_decrypt: can't convert data to mpi (size %d):%s\n",
len, gcry_strerror(rc));
return 0;
}
rc = gcry_sexp_build(&s_data, NULL, "(enc-val(rsa(a%m)))", encr_mpi);
if (rc != 0) {
ssl_debug_printf("pcry_private_decrypt: can't build encr_sexp:%s\n",
gcry_strerror(rc));
decr_len = 0;
goto out;
}
rc = gcry_pk_decrypt(&s_plain, s_data, pk);
if (rc != 0)
{
ssl_debug_printf("pcry_private_decrypt: can't decrypt key:%s\n",
gcry_strerror(rc));
decr_len = 0;
goto out;
}
text = gcry_sexp_nth_mpi(s_plain, 0, 0);
if (! text) {
ssl_debug_printf("pcry_private_decrypt: can't convert sexp to mpi\n");
decr_len = 0;
goto out;
}
rc = gcry_mpi_print(GCRYMPI_FMT_USG, NULL, 0, &decr_len, text);
if (rc != 0) {
ssl_debug_printf("pcry_private_decrypt: can't compute decr size:%s\n",
gcry_strerror(rc));
decr_len = 0;
goto out;
}
if (decr_len > len) {
ssl_debug_printf("pcry_private_decrypt: decrypted data is too long ?!? (%" G_GSIZE_MODIFIER "u max %d)\n", decr_len, len);
decr_len = 0;
goto out;
}
rc = gcry_mpi_print(GCRYMPI_FMT_USG, data, len, &decr_len, text);
if (rc != 0) {
ssl_debug_printf("pcry_private_decrypt: can't print decr data to mpi (size %" G_GSIZE_MODIFIER "u):%s\n", decr_len, gcry_strerror(rc));
decr_len = 0;
goto out;
}
ssl_print_data("decrypted_unstrip_pre_master", data, decr_len);
rc = 0;
for (i = 1; i < decr_len; i++) {
if (data[i] == 0) {
rc = (gint) i+1;
break;
}
}
ssl_debug_printf("pcry_private_decrypt: stripping %d bytes, decr_len %" G_GSIZE_MODIFIER "u\n", rc, decr_len);
decr_len -= rc;
memmove(data, data+rc, decr_len);
out:
gcry_sexp_release(s_data);
gcry_sexp_release(s_plain);
gcry_mpi_release(encr_mpi);
gcry_mpi_release(text);
return (int) decr_len;
}
static const SslDigestAlgo *
ssl_cipher_suite_dig(const SslCipherSuite *cs) {
return &digests[cs->dig - DIG_MD5];
}
const SslCipherSuite *
ssl_find_cipher(int num)
{
const SslCipherSuite *c;
for(c=cipher_suites;c->number!=-1;c++){
if(c->number==num){
return c;
}
}
return NULL;
}
guint
ssl_get_cipher_blocksize(const SslCipherSuite *cipher_suite)
{
gint cipher_algo;
if (cipher_suite->mode != MODE_CBC) return 0;
cipher_algo = ssl_get_cipher_by_name(ciphers[cipher_suite->enc - 0x30]);
return (guint)gcry_cipher_get_algo_blklen(cipher_algo);
}
static guint
ssl_get_cipher_export_keymat_size(int cipher_suite_num)
{
switch (cipher_suite_num) {
case 0x0003:
case 0x0006:
case 0x0008:
case 0x000B:
case 0x000E:
case 0x0011:
case 0x0014:
case 0x0017:
case 0x0019:
return 5;
case 0x0060:
case 0x0061:
return 7;
case 0x0062:
case 0x0063:
case 0x0064:
case 0x0065:
return 7;
default:
return 0;
}
}
static void
tls_hash(StringInfo *secret, StringInfo *seed, gint md,
StringInfo *out, guint out_len)
{
guint8 *ptr;
guint left, tocpy;
guint8 *A;
guint8 _A[DIGEST_MAX_SIZE], tmp[DIGEST_MAX_SIZE];
guint A_l, tmp_l;
SSL_HMAC hm;
ptr = out->data;
left = out_len;
ssl_print_string("tls_hash: hash secret", secret);
ssl_print_string("tls_hash: hash seed", seed);
A = seed->data;
A_l = seed->data_len;
while (left) {
ssl_hmac_init(&hm, secret->data, secret->data_len, md);
ssl_hmac_update(&hm, A, A_l);
A_l = sizeof(_A);
ssl_hmac_final(&hm, _A, &A_l);
ssl_hmac_cleanup(&hm);
A = _A;
ssl_hmac_init(&hm, secret->data, secret->data_len, md);
ssl_hmac_update(&hm, A, A_l);
ssl_hmac_update(&hm, seed->data, seed->data_len);
tmp_l = sizeof(tmp);
ssl_hmac_final(&hm, tmp, &tmp_l);
ssl_hmac_cleanup(&hm);
tocpy = MIN(left, tmp_l);
memcpy(ptr, tmp, tocpy);
ptr += tocpy;
left -= tocpy;
}
out->data_len = out_len;
ssl_print_string("hash out", out);
}
static gboolean
tls_prf(StringInfo* secret, const gchar *usage,
StringInfo* rnd1, StringInfo* rnd2, StringInfo* out, guint out_len)
{
StringInfo seed, sha_out, md5_out;
guint8 *ptr;
StringInfo s1, s2;
guint i,s_l;
size_t usage_len, rnd2_len;
gboolean success = FALSE;
usage_len = strlen(usage);
rnd2_len = rnd2 ? rnd2->data_len : 0;
if (ssl_data_alloc(&sha_out, MAX(out_len, 20)) < 0) {
ssl_debug_printf("tls_prf: can't allocate sha out\n");
return FALSE;
}
if (ssl_data_alloc(&md5_out, MAX(out_len, 16)) < 0) {
ssl_debug_printf("tls_prf: can't allocate md5 out\n");
goto free_sha;
}
if (ssl_data_alloc(&seed, usage_len+rnd1->data_len+rnd2_len) < 0) {
ssl_debug_printf("tls_prf: can't allocate rnd %d\n",
(int) (usage_len+rnd1->data_len+rnd2_len));
goto free_md5;
}
ptr=seed.data;
memcpy(ptr,usage,usage_len);
ptr+=usage_len;
memcpy(ptr,rnd1->data,rnd1->data_len);
if (rnd2_len > 0) {
ptr+=rnd1->data_len;
memcpy(ptr,rnd2->data,rnd2->data_len);
}
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
tls_hash(&s1, &seed, ssl_get_digest_by_name("MD5"), &md5_out, out_len);
ssl_debug_printf("tls_prf: tls_hash(sha)\n");
tls_hash(&s2, &seed, ssl_get_digest_by_name("SHA1"), &sha_out, out_len);
for (i = 0; i < out_len; i++)
out->data[i] = md5_out.data[i] ^ sha_out.data[i];
out->data_len = out_len;
success = TRUE;
ssl_print_string("PRF out",out);
g_free(s2.data);
free_s1:
g_free(s1.data);
free_seed:
g_free(seed.data);
free_md5:
g_free(md5_out.data);
free_sha:
g_free(sha_out.data);
return success;
}
static gboolean
tls12_prf(gint md, StringInfo* secret, const gchar* usage,
StringInfo* rnd1, StringInfo* rnd2, StringInfo* out, guint out_len)
{
StringInfo label_seed;
size_t usage_len, rnd2_len;
rnd2_len = rnd2 ? rnd2->data_len : 0;
usage_len = strlen(usage);
if (ssl_data_alloc(&label_seed, usage_len+rnd1->data_len+rnd2_len) < 0) {
ssl_debug_printf("tls12_prf: can't allocate label_seed\n");
return FALSE;
}
memcpy(label_seed.data, usage, usage_len);
memcpy(label_seed.data+usage_len, rnd1->data, rnd1->data_len);
if (rnd2_len > 0)
memcpy(label_seed.data+usage_len+rnd1->data_len, rnd2->data, rnd2->data_len);
ssl_debug_printf("tls12_prf: tls_hash(hash_alg %s secret_len %d seed_len %d )\n", gcry_md_algo_name(md), secret->data_len, label_seed.data_len);
tls_hash(secret, &label_seed, md, out, out_len);
g_free(label_seed.data);
ssl_print_string("PRF out", out);
return TRUE;
}
static void
ssl3_generate_export_iv(StringInfo *r1, StringInfo *r2,
StringInfo *out, guint out_len)
{
SSL_MD5_CTX md5;
guint8 tmp[16];
ssl_md5_init(&md5);
ssl_md5_update(&md5,r1->data,r1->data_len);
ssl_md5_update(&md5,r2->data,r2->data_len);
ssl_md5_final(tmp,&md5);
ssl_md5_cleanup(&md5);
DISSECTOR_ASSERT(out_len <= sizeof(tmp));
ssl_data_set(out, tmp, out_len);
ssl_print_string("export iv", out);
}
static gboolean
ssl3_prf(StringInfo* secret, const gchar* usage,
StringInfo* rnd1, StringInfo* rnd2, StringInfo* out, guint out_len)
{
SSL_MD5_CTX md5;
SSL_SHA_CTX sha;
guint off;
gint i = 0,j;
guint8 buf[20];
for (off = 0; off < out_len; off += 16) {
guchar outbuf[16];
i++;
ssl_debug_printf("ssl3_prf: sha1_hash(%d)\n",i);
for(j=0;j<i;j++){
buf[j]=64+i;
}
ssl_sha_init(&sha);
ssl_sha_update(&sha,buf,i);
ssl_sha_update(&sha,secret->data,secret->data_len);
if(!strcmp(usage,"client write key") || !strcmp(usage,"server write key")){
if (rnd2)
ssl_sha_update(&sha,rnd2->data,rnd2->data_len);
ssl_sha_update(&sha,rnd1->data,rnd1->data_len);
}
else{
ssl_sha_update(&sha,rnd1->data,rnd1->data_len);
if (rnd2)
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
memcpy(out->data + off, outbuf, MIN(out_len - off, 16));
}
out->data_len = out_len;
return TRUE;
}
static gboolean
prf(SslDecryptSession *ssl, StringInfo *secret, const gchar *usage,
StringInfo *rnd1, StringInfo *rnd2, StringInfo *out, guint out_len)
{
switch (ssl->session.version) {
case SSLV3_VERSION:
return ssl3_prf(secret, usage, rnd1, rnd2, out, out_len);
case TLSV1_VERSION:
case TLSV1DOT1_VERSION:
case DTLSV1DOT0_VERSION:
case DTLSV1DOT0_OPENSSL_VERSION:
return tls_prf(secret, usage, rnd1, rnd2, out, out_len);
default:
switch (ssl->cipher_suite->dig) {
case DIG_SHA384:
return tls12_prf(GCRY_MD_SHA384, secret, usage, rnd1, rnd2,
out, out_len);
default:
return tls12_prf(GCRY_MD_SHA256, secret, usage, rnd1, rnd2,
out, out_len);
}
}
}
static gint tls_handshake_hash(SslDecryptSession* ssl, StringInfo* out)
{
SSL_MD5_CTX md5;
SSL_SHA_CTX sha;
if (ssl_data_alloc(out, 36) < 0)
return -1;
ssl_md5_init(&md5);
ssl_md5_update(&md5,ssl->handshake_data.data,ssl->handshake_data.data_len);
ssl_md5_final(out->data,&md5);
ssl_md5_cleanup(&md5);
ssl_sha_init(&sha);
ssl_sha_update(&sha,ssl->handshake_data.data,ssl->handshake_data.data_len);
ssl_sha_final(out->data+16,&sha);
ssl_sha_cleanup(&sha);
return 0;
}
static gint tls12_handshake_hash(SslDecryptSession* ssl, gint md, StringInfo* out)
{
SSL_MD mc;
guint8 tmp[48];
guint len;
ssl_md_init(&mc, md);
ssl_md_update(&mc,ssl->handshake_data.data,ssl->handshake_data.data_len);
ssl_md_final(&mc, tmp, &len);
ssl_md_cleanup(&mc);
if (ssl_data_alloc(out, len) < 0)
return -1;
memcpy(out->data, tmp, len);
return 0;
}
static gboolean
tls13_hkdf_expand_label(guchar draft_version,
int md, const StringInfo *secret, const char *label, const char *hash_value,
guint16 out_len, guchar **out)
{
guchar lastoutput[DIGEST_MAX_SIZE];
gcry_md_hd_t h;
gcry_error_t err;
const guint label_length = (guint) strlen(label);
const guint hash_value_length = (guint) strlen(hash_value);
const guint hash_len = gcry_md_get_algo_dlen(md);
DISSECTOR_ASSERT(out_len > 0 && out_len <= 255 * hash_len);
DISSECTOR_ASSERT(label_length > 0 && label_length <= 255 - 6);
DISSECTOR_ASSERT(hash_value_length <= 255);
DISSECTOR_ASSERT(hash_len > 0 && hash_len <= DIGEST_MAX_SIZE);
err = gcry_md_open(&h, md, GCRY_MD_FLAG_HMAC);
if (err) {
ssl_debug_printf("%s failed to invoke hash func %d: %s\n", G_STRFUNC, md, gcry_strerror(err));
return FALSE;
}
*out = (guchar *)wmem_alloc(NULL, out_len);
for (guint offset = 0; offset < out_len; offset += hash_len) {
gcry_md_reset(h);
gcry_md_setkey(h, secret->data, secret->data_len);
if (offset > 0) {
gcry_md_write(h, lastoutput, hash_len);
}
gcry_md_putc(h, out_len >> 8);
gcry_md_putc(h, (guint8) out_len);
if (draft_version && draft_version < 20) {
gcry_md_putc(h, 9 + label_length);
gcry_md_write(h, "TLS 1.3, ", 9);
} else {
gcry_md_putc(h, 6 + label_length);
gcry_md_write(h, "tls13 ", 6);
}
gcry_md_write(h, label, label_length);
gcry_md_putc(h, hash_value_length);
gcry_md_write(h, hash_value, hash_value_length);
gcry_md_putc(h, (guint8) (offset / hash_len + 1));
memcpy(lastoutput, gcry_md_read(h, md), hash_len);
memcpy(*out + offset, lastoutput, MIN(hash_len, out_len - offset));
}
gcry_md_close(h);
return TRUE;
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
#ifdef HAVE_ZLIB
int err;
#endif
if (compression == 0) return NULL;
ssl_debug_printf("ssl_create_decompressor: compression method %d\n", compression);
decomp = (SslDecompress *)wmem_alloc(wmem_file_scope(), sizeof(SslDecompress));
decomp->compression = compression;
switch (decomp->compression) {
#ifdef HAVE_ZLIB
case 1:
decomp->istream.zalloc = ssl_zalloc;
decomp->istream.zfree = ssl_zfree;
decomp->istream.opaque = Z_NULL;
decomp->istream.next_in = Z_NULL;
decomp->istream.next_out = Z_NULL;
decomp->istream.avail_in = 0;
decomp->istream.avail_out = 0;
err = inflateInit(&decomp->istream);
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
static int
ssl_decompress_record(SslDecompress* decomp, const guchar* in, guint inl, StringInfo* out_str, guint* outl)
{
gint err;
switch (decomp->compression) {
case 1:
err = Z_OK;
if (out_str->data_len < 16384) {
ssl_data_realloc(out_str, 16384);
}
#ifdef z_const
decomp->istream.next_in = in;
#else
DIAG_OFF(cast-qual)
decomp->istream.next_in = (Bytef *)in;
DIAG_ON(cast-qual)
#endif
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
static SslDecoder*
ssl_create_decoder(const SslCipherSuite *cipher_suite, gint cipher_algo,
gint compression, guint8 *mk, guint8 *sk, guint8 *iv, guint iv_length)
{
SslDecoder *dec;
ssl_cipher_mode_t mode = cipher_suite->mode;
dec = (SslDecoder *)wmem_alloc0(wmem_file_scope(), sizeof(SslDecoder));
dec->cipher_suite=cipher_suite;
dec->compression = compression;
if ((mode == MODE_STREAM && mk != NULL) || mode == MODE_CBC) {
dec->mac_key.data = dec->_mac_key_or_write_iv;
ssl_data_set(&dec->mac_key, mk, ssl_cipher_suite_dig(cipher_suite)->len);
} else if (mode == MODE_GCM || mode == MODE_CCM || mode == MODE_CCM_8 || mode == MODE_POLY1305) {
DISSECTOR_ASSERT(iv_length <= sizeof(dec->_mac_key_or_write_iv));
dec->write_iv.data = dec->_mac_key_or_write_iv;
ssl_data_set(&dec->write_iv, iv, iv_length);
}
dec->seq = 0;
dec->decomp = ssl_create_decompressor(compression);
wmem_register_callback(wmem_file_scope(), ssl_decoder_destroy_cb, dec);
if (ssl_cipher_init(&dec->evp,cipher_algo,sk,iv,cipher_suite->mode) < 0) {
ssl_debug_printf("%s: can't create cipher id:%d mode:%d\n", G_STRFUNC,
cipher_algo, cipher_suite->mode);
return NULL;
}
ssl_debug_printf("decoder initialized (digest len %d)\n", ssl_cipher_suite_dig(cipher_suite)->len);
return dec;
}
static gboolean
ssl_decoder_destroy_cb(wmem_allocator_t *allocator _U_, wmem_cb_event_t event _U_, void *user_data)
{
SslDecoder *dec = (SslDecoder *) user_data;
if (dec->evp)
ssl_cipher_cleanup(&dec->evp);
#ifdef HAVE_ZLIB
if (dec->decomp != NULL && dec->decomp->compression == 1 )
inflateEnd(&dec->decomp->istream);
#endif
return FALSE;
}
gboolean
ssl_generate_pre_master_secret(SslDecryptSession *ssl_session,
guint32 length, tvbuff_t *tvb, guint32 offset,
const gchar *ssl_psk,
const ssl_master_key_map_t *mk_map)
{
ssl_debug_printf("%s: found SSL_HND_CLIENT_KEY_EXCHG, state %X\n",
G_STRFUNC, ssl_session->state);
if ((ssl_session->state & (SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION)) !=
(SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION)) {
ssl_debug_printf("%s: not enough data to generate key (required state %X)\n", G_STRFUNC,
(SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION));
return FALSE;
}
if (ssl_session->session.version == TLSV1DOT3_VERSION) {
ssl_debug_printf("%s: detected TLS 1.3 which has no pre-master secrets\n", G_STRFUNC);
return FALSE;
}
if (ssl_restore_master_key(ssl_session, "Unencrypted pre-master secret", TRUE,
mk_map->pms, &ssl_session->client_random)) {
return TRUE;
}
if (ssl_session->cipher_suite->kex == KEX_PSK)
{
StringInfo pre_master_secret;
guint psk_len, pre_master_len;
if (!ssl_psk || (ssl_psk[0] == 0)) {
ssl_debug_printf("%s: can't find pre-shared-key\n", G_STRFUNC);
return FALSE;
}
if (!from_hex(&ssl_session->psk, ssl_psk, strlen(ssl_psk))) {
ssl_debug_printf("%s: ssl.psk/dtls.psk contains invalid hex\n",
G_STRFUNC);
return FALSE;
}
psk_len = ssl_session->psk.data_len;
if (psk_len >= (2 << 15)) {
ssl_debug_printf("%s: ssl.psk/dtls.psk must not be larger than 2^15 - 1\n",
G_STRFUNC);
return FALSE;
}
pre_master_len = psk_len * 2 + 4;
pre_master_secret.data = (guchar *)wmem_alloc(wmem_file_scope(), pre_master_len);
pre_master_secret.data_len = pre_master_len;
pre_master_secret.data[0] = psk_len >> 8;
pre_master_secret.data[1] = psk_len & 0xFF;
memset(&pre_master_secret.data[2], 0, psk_len);
pre_master_secret.data[psk_len + 2] = psk_len >> 8;
pre_master_secret.data[psk_len + 3] = psk_len & 0xFF;
memcpy(&pre_master_secret.data[psk_len + 4], ssl_session->psk.data, psk_len);
ssl_session->pre_master_secret.data = pre_master_secret.data;
ssl_session->pre_master_secret.data_len = pre_master_len;
ssl_session->state &= ~(SSL_MASTER_SECRET|SSL_HAVE_SESSION_KEY);
ssl_session->state |= SSL_PRE_MASTER_SECRET;
return TRUE;
}
else
{
StringInfo encrypted_pre_master;
guint encrlen, skip;
encrlen = length;
skip = 0;
if (ssl_session->cipher_suite->kex == KEX_RSA &&
(ssl_session->session.version == TLSV1_VERSION ||
ssl_session->session.version == TLSV1DOT1_VERSION ||
ssl_session->session.version == TLSV1DOT2_VERSION ||
ssl_session->session.version == DTLSV1DOT0_VERSION ||
ssl_session->session.version == DTLSV1DOT2_VERSION))
{
encrlen = tvb_get_ntohs(tvb, offset);
skip = 2;
if (encrlen > length - 2)
{
ssl_debug_printf("%s: wrong encrypted length (%d max %d)\n",
G_STRFUNC, encrlen, length);
return FALSE;
}
}
if (encrlen < 8) {
ssl_debug_printf("%s: invalid encrypted pre-master key length %d\n",
G_STRFUNC, encrlen);
return FALSE;
}
encrypted_pre_master.data = (guchar *)wmem_alloc(wmem_file_scope(), encrlen);
encrypted_pre_master.data_len = encrlen;
tvb_memcpy(tvb, encrypted_pre_master.data, offset+skip, encrlen);
#ifdef HAVE_LIBGNUTLS
if (ssl_session->private_key) {
if (ssl_decrypt_pre_master_secret(ssl_session,
&encrypted_pre_master, ssl_session->private_key))
return TRUE;
ssl_debug_printf("%s: can't decrypt pre-master secret\n",
G_STRFUNC);
}
#endif
encrypted_pre_master.data_len = 8;
if (ssl_restore_master_key(ssl_session, "Encrypted pre-master secret",
TRUE, mk_map->pre_master, &encrypted_pre_master))
return TRUE;
}
return FALSE;
}
int
ssl_generate_keyring_material(SslDecryptSession*ssl_session)
{
StringInfo key_block = { NULL, 0 };
guint8 _iv_c[MAX_BLOCK_SIZE],_iv_s[MAX_BLOCK_SIZE];
guint8 _key_c[MAX_KEY_SIZE],_key_s[MAX_KEY_SIZE];
gint needed;
gint cipher_algo = -1;
guint encr_key_len, write_iv_len = 0;
gboolean is_export_cipher;
guint8 *ptr, *c_iv = NULL, *s_iv = NULL;
guint8 *c_wk = NULL, *s_wk = NULL, *c_mk = NULL, *s_mk = NULL;
const SslCipherSuite *cipher_suite = ssl_session->cipher_suite;
if (ssl_session->session.version == TLSV1DOT3_VERSION) {
ssl_debug_printf("%s: detected TLS 1.3. Should not have been called!\n", G_STRFUNC);
return -1;
}
guint need_all = SSL_CIPHER|SSL_CLIENT_RANDOM|SSL_SERVER_RANDOM|SSL_VERSION;
guint need_any = SSL_MASTER_SECRET | SSL_PRE_MASTER_SECRET;
if (((ssl_session->state & need_all) != need_all) || ((ssl_session->state & need_any) == 0)) {
ssl_debug_printf("ssl_generate_keyring_material not enough data to generate key "
"(0x%02X required 0x%02X or 0x%02X)\n", ssl_session->state,
need_all|SSL_MASTER_SECRET, need_all|SSL_PRE_MASTER_SECRET);
need_all = SSL_CIPHER|SSL_VERSION;
if ((ssl_session->state & need_all) == need_all &&
cipher_suite->enc == ENC_NULL) {
ssl_debug_printf("%s NULL cipher found, will create a decoder but "
"skip MAC validation as keys are missing.\n", G_STRFUNC);
goto create_decoders;
}
return -1;
}
if (!(ssl_session->state & SSL_MASTER_SECRET)) {
if ((ssl_session->state & SSL_EXTENDED_MASTER_SECRET_MASK) == SSL_EXTENDED_MASTER_SECRET_MASK) {
StringInfo handshake_hashed_data;
gint ret;
handshake_hashed_data.data = NULL;
handshake_hashed_data.data_len = 0;
ssl_debug_printf("%s:PRF(pre_master_secret_extended)\n", G_STRFUNC);
ssl_print_string("pre master secret",&ssl_session->pre_master_secret);
DISSECTOR_ASSERT(ssl_session->handshake_data.data_len > 0);
switch(ssl_session->session.version) {
case TLSV1_VERSION:
case TLSV1DOT1_VERSION:
case DTLSV1DOT0_VERSION:
case DTLSV1DOT0_OPENSSL_VERSION:
ret = tls_handshake_hash(ssl_session, &handshake_hashed_data);
break;
default:
switch (cipher_suite->dig) {
case DIG_SHA384:
ret = tls12_handshake_hash(ssl_session, GCRY_MD_SHA384, &handshake_hashed_data);
break;
default:
ret = tls12_handshake_hash(ssl_session, GCRY_MD_SHA256, &handshake_hashed_data);
break;
}
break;
}
if (ret) {
ssl_debug_printf("%s can't generate handshake hash\n", G_STRFUNC);
return -1;
}
wmem_free(wmem_file_scope(), ssl_session->handshake_data.data);
ssl_session->handshake_data.data = NULL;
ssl_session->handshake_data.data_len = 0;
if (!prf(ssl_session, &ssl_session->pre_master_secret, "extended master secret",
&handshake_hashed_data,
NULL, &ssl_session->master_secret,
SSL_MASTER_SECRET_LENGTH)) {
ssl_debug_printf("%s can't generate master_secret\n", G_STRFUNC);
g_free(handshake_hashed_data.data);
return -1;
}
g_free(handshake_hashed_data.data);
} else {
ssl_debug_printf("%s:PRF(pre_master_secret)\n", G_STRFUNC);
ssl_print_string("pre master secret",&ssl_session->pre_master_secret);
ssl_print_string("client random",&ssl_session->client_random);
ssl_print_string("server random",&ssl_session->server_random);
if (!prf(ssl_session, &ssl_session->pre_master_secret, "master secret",
&ssl_session->client_random,
&ssl_session->server_random, &ssl_session->master_secret,
SSL_MASTER_SECRET_LENGTH)) {
ssl_debug_printf("%s can't generate master_secret\n", G_STRFUNC);
return -1;
}
}
ssl_print_string("master secret",&ssl_session->master_secret);
ssl_session->state &= ~SSL_PRE_MASTER_SECRET;
ssl_session->state |= SSL_MASTER_SECRET;
}
if (cipher_suite->enc != ENC_NULL) {
const char *cipher_name = ciphers[cipher_suite->enc-0x30];
ssl_debug_printf("%s CIPHER: %s\n", G_STRFUNC, cipher_name);
cipher_algo = ssl_get_cipher_by_name(cipher_name);
if (cipher_algo == 0) {
ssl_debug_printf("%s can't find cipher %s\n", G_STRFUNC, cipher_name);
return -1;
}
}
encr_key_len = ssl_get_cipher_export_keymat_size(cipher_suite->number);
is_export_cipher = encr_key_len > 0;
if (!is_export_cipher && cipher_suite->enc != ENC_NULL) {
encr_key_len = (guint)gcry_cipher_get_algo_keylen(cipher_algo);
}
if (cipher_suite->mode == MODE_CBC) {
write_iv_len = (guint)gcry_cipher_get_algo_blklen(cipher_algo);
} else if (cipher_suite->mode == MODE_GCM || cipher_suite->mode == MODE_CCM || cipher_suite->mode == MODE_CCM_8) {
write_iv_len = 4;
} else if (cipher_suite->mode == MODE_POLY1305) {
write_iv_len = 12;
}
needed = ssl_cipher_suite_dig(cipher_suite)->len*2;
needed += 2 * encr_key_len;
needed += 2 * write_iv_len;
key_block.data = (guchar *)g_malloc(needed);
ssl_debug_printf("%s sess key generation\n", G_STRFUNC);
if (!prf(ssl_session, &ssl_session->master_secret, "key expansion",
&ssl_session->server_random,&ssl_session->client_random,
&key_block, needed)) {
ssl_debug_printf("%s can't generate key_block\n", G_STRFUNC);
goto fail;
}
ssl_print_string("key expansion", &key_block);
ptr=key_block.data;
if (cipher_suite->mode == MODE_STREAM || cipher_suite->mode == MODE_CBC) {
c_mk=ptr; ptr+=ssl_cipher_suite_dig(cipher_suite)->len;
s_mk=ptr; ptr+=ssl_cipher_suite_dig(cipher_suite)->len;
}
c_wk=ptr; ptr += encr_key_len;
s_wk=ptr; ptr += encr_key_len;
if (write_iv_len > 0) {
c_iv=ptr; ptr += write_iv_len;
s_iv=ptr;
}
if (is_export_cipher) {
if (cipher_suite->mode == MODE_CBC) {
if (write_iv_len > MAX_BLOCK_SIZE) {
ssl_debug_printf("%s cipher suite block must be at most %d nut is %d\n",
G_STRFUNC, MAX_BLOCK_SIZE, write_iv_len);
goto fail;
}
if(ssl_session->session.version==SSLV3_VERSION){
StringInfo iv_c, iv_s;
iv_c.data = _iv_c;
iv_s.data = _iv_s;
ssl_debug_printf("%s ssl3_generate_export_iv\n", G_STRFUNC);
ssl3_generate_export_iv(&ssl_session->client_random,
&ssl_session->server_random, &iv_c, write_iv_len);
ssl_debug_printf("%s ssl3_generate_export_iv(2)\n", G_STRFUNC);
ssl3_generate_export_iv(&ssl_session->server_random,
&ssl_session->client_random, &iv_s, write_iv_len);
}
else{
guint8 _iv_block[MAX_BLOCK_SIZE * 2];
StringInfo iv_block;
StringInfo key_null;
guint8 _key_null;
key_null.data = &_key_null;
key_null.data_len = 0;
iv_block.data = _iv_block;
ssl_debug_printf("%s prf(iv_block)\n", G_STRFUNC);
if (!prf(ssl_session, &key_null, "IV block",
&ssl_session->client_random,
&ssl_session->server_random, &iv_block,
write_iv_len * 2)) {
ssl_debug_printf("%s can't generate tls31 iv block\n", G_STRFUNC);
goto fail;
}
memcpy(_iv_c, iv_block.data, write_iv_len);
memcpy(_iv_s, iv_block.data + write_iv_len, write_iv_len);
}
c_iv=_iv_c;
s_iv=_iv_s;
}
if (ssl_session->session.version==SSLV3_VERSION){
SSL_MD5_CTX md5;
ssl_debug_printf("%s MD5(client_random)\n", G_STRFUNC);
ssl_md5_init(&md5);
ssl_md5_update(&md5,c_wk,encr_key_len);
ssl_md5_update(&md5,ssl_session->client_random.data,
ssl_session->client_random.data_len);
ssl_md5_update(&md5,ssl_session->server_random.data,
ssl_session->server_random.data_len);
ssl_md5_final(_key_c,&md5);
ssl_md5_cleanup(&md5);
c_wk=_key_c;
ssl_md5_init(&md5);
ssl_debug_printf("%s MD5(server_random)\n", G_STRFUNC);
ssl_md5_update(&md5,s_wk,encr_key_len);
ssl_md5_update(&md5,ssl_session->server_random.data,
ssl_session->server_random.data_len);
ssl_md5_update(&md5,ssl_session->client_random.data,
ssl_session->client_random.data_len);
ssl_md5_final(_key_s,&md5);
ssl_md5_cleanup(&md5);
s_wk=_key_s;
}
else{
StringInfo key_c, key_s, k;
key_c.data = _key_c;
key_s.data = _key_s;
k.data = c_wk;
k.data_len = encr_key_len;
ssl_debug_printf("%s PRF(key_c)\n", G_STRFUNC);
if (!prf(ssl_session, &k, "client write key",
&ssl_session->client_random,
&ssl_session->server_random, &key_c, sizeof(_key_c))) {
ssl_debug_printf("%s can't generate tll31 server key \n", G_STRFUNC);
goto fail;
}
c_wk=_key_c;
k.data = s_wk;
k.data_len = encr_key_len;
ssl_debug_printf("%s PRF(key_s)\n", G_STRFUNC);
if (!prf(ssl_session, &k, "server write key",
&ssl_session->client_random,
&ssl_session->server_random, &key_s, sizeof(_key_s))) {
ssl_debug_printf("%s can't generate tll31 client key \n", G_STRFUNC);
goto fail;
}
s_wk=_key_s;
}
}
if (c_mk != NULL) {
ssl_print_data("Client MAC key",c_mk,ssl_cipher_suite_dig(cipher_suite)->len);
ssl_print_data("Server MAC key",s_mk,ssl_cipher_suite_dig(cipher_suite)->len);
}
ssl_print_data("Client Write key", c_wk, encr_key_len);
ssl_print_data("Server Write key", s_wk, encr_key_len);
if (write_iv_len > 0) {
ssl_print_data("Client Write IV", c_iv, write_iv_len);
ssl_print_data("Server Write IV", s_iv, write_iv_len);
}
create_decoders:
ssl_debug_printf("%s ssl_create_decoder(client)\n", G_STRFUNC);
ssl_session->client_new = ssl_create_decoder(cipher_suite, cipher_algo, ssl_session->session.compression, c_mk, c_wk, c_iv, write_iv_len);
if (!ssl_session->client_new) {
ssl_debug_printf("%s can't init client decoder\n", G_STRFUNC);
goto fail;
}
ssl_debug_printf("%s ssl_create_decoder(server)\n", G_STRFUNC);
ssl_session->server_new = ssl_create_decoder(cipher_suite, cipher_algo, ssl_session->session.compression, s_mk, s_wk, s_iv, write_iv_len);
if (!ssl_session->server_new) {
ssl_debug_printf("%s can't init client decoder\n", G_STRFUNC);
goto fail;
}
ssl_session->client_new->flow = ssl_session->client ? ssl_session->client->flow : ssl_create_flow();
ssl_session->server_new->flow = ssl_session->server ? ssl_session->server->flow : ssl_create_flow();
ssl_debug_printf("%s: client seq %" G_GUINT64_FORMAT ", server seq %" G_GUINT64_FORMAT "\n",
G_STRFUNC, ssl_session->client_new->seq, ssl_session->server_new->seq);
g_free(key_block.data);
ssl_session->state |= SSL_HAVE_SESSION_KEY;
return 0;
fail:
g_free(key_block.data);
return -1;
}
static gboolean
tls13_generate_keys(SslDecryptSession *ssl_session, const StringInfo *secret, gboolean is_from_server)
{
gboolean success = FALSE;
guchar *write_key = NULL, *write_iv = NULL;
SslDecoder *decoder;
guint key_length, iv_length;
int hash_algo;
const SslCipherSuite *cipher_suite = ssl_session->cipher_suite;
int cipher_algo;
if (ssl_session->session.version != TLSV1DOT3_VERSION) {
ssl_debug_printf("%s only usable for TLS 1.3, not %#x!\n", G_STRFUNC,
ssl_session->session.version);
return FALSE;
}
if (cipher_suite == NULL) {
ssl_debug_printf("%s Unknown cipher\n", G_STRFUNC);
return FALSE;
}
if (cipher_suite->kex != KEX_TLS13) {
ssl_debug_printf("%s Invalid cipher suite 0x%04x spotted!\n", G_STRFUNC, cipher_suite->number);
return FALSE;
}
const char *cipher_name = ciphers[cipher_suite->enc-0x30];
ssl_debug_printf("%s CIPHER: %s\n", G_STRFUNC, cipher_name);
cipher_algo = ssl_get_cipher_by_name(cipher_name);
if (cipher_algo == 0) {
ssl_debug_printf("%s can't find cipher %s\n", G_STRFUNC, cipher_name);
return FALSE;
}
const char *hash_name = ssl_cipher_suite_dig(cipher_suite)->name;
hash_algo = ssl_get_digest_by_name(hash_name);
if (!hash_algo) {
ssl_debug_printf("%s can't find hash function %s\n", G_STRFUNC, hash_name);
return FALSE;
}
key_length = (guint) gcry_cipher_get_algo_keylen(cipher_algo);
iv_length = 12;
ssl_debug_printf("%s key_length %u iv_length %u\n", G_STRFUNC, key_length, iv_length);
if (!tls13_hkdf_expand_label(ssl_session->session.tls13_draft_version, hash_algo, secret, "key", "", key_length, &write_key)) {
ssl_debug_printf("%s write_key expansion failed\n", G_STRFUNC);
return FALSE;
}
if (!tls13_hkdf_expand_label(ssl_session->session.tls13_draft_version, hash_algo, secret, "iv", "", iv_length, &write_iv)) {
ssl_debug_printf("%s write_iv expansion failed\n", G_STRFUNC);
goto end;
}
ssl_print_data(is_from_server ? "Server Write Key" : "Client Write Key", write_key, key_length);
ssl_print_data(is_from_server ? "Server Write IV" : "Client Write IV", write_iv, iv_length);
ssl_debug_printf("%s ssl_create_decoder(%s)\n", G_STRFUNC, is_from_server ? "server" : "client");
decoder = ssl_create_decoder(cipher_suite, cipher_algo, 0, NULL, write_key, write_iv, iv_length);
if (!decoder) {
ssl_debug_printf("%s can't init %s decoder\n", G_STRFUNC, is_from_server ? "server" : "client");
goto end;
}
if (is_from_server) {
decoder->flow = ssl_session->server ? ssl_session->server->flow : ssl_create_flow();
ssl_session->server = decoder;
} else {
decoder->flow = ssl_session->client ? ssl_session->client->flow : ssl_create_flow();
ssl_session->client = decoder;
}
ssl_debug_printf("%s %s ready using cipher suite 0x%04x (cipher %s hash %s)\n", G_STRFUNC,
is_from_server ? "Server" : "Client", cipher_suite->number, cipher_name, hash_name);
success = TRUE;
end:
wmem_free(NULL, write_key);
wmem_free(NULL, write_iv);
return success;
}
static gboolean
ssl_decrypt_pre_master_secret(SslDecryptSession*ssl_session,
StringInfo* encrypted_pre_master, gcry_sexp_t pk)
{
gint i;
if (!encrypted_pre_master)
return FALSE;
if (KEX_IS_DH(ssl_session->cipher_suite->kex)) {
ssl_debug_printf("%s: session uses Diffie-Hellman key exchange "
"(cipher suite 0x%04X %s) and cannot be decrypted "
"using a RSA private key file.\n",
G_STRFUNC, ssl_session->session.cipher,
val_to_str_ext_const(ssl_session->session.cipher,
&ssl_31_ciphersuite_ext, "unknown"));
return FALSE;
} else if(ssl_session->cipher_suite->kex != KEX_RSA) {
ssl_debug_printf("%s key exchange %d different from KEX_RSA (%d)\n",
G_STRFUNC, ssl_session->cipher_suite->kex, KEX_RSA);
return FALSE;
}
ssl_print_string("pre master encrypted",encrypted_pre_master);
ssl_debug_printf("%s: RSA_private_decrypt\n", G_STRFUNC);
i=ssl_private_decrypt(encrypted_pre_master->data_len,
encrypted_pre_master->data, pk);
if (i!=48) {
ssl_debug_printf("%s wrong pre_master_secret length (%d, expected "
"%d)\n", G_STRFUNC, i, 48);
return FALSE;
}
ssl_session->pre_master_secret.data = encrypted_pre_master->data;
ssl_session->pre_master_secret.data_len=48;
ssl_print_string("pre master secret",&ssl_session->pre_master_secret);
ssl_session->state &= ~(SSL_MASTER_SECRET|SSL_HAVE_SESSION_KEY);
ssl_session->state |= SSL_PRE_MASTER_SECRET;
return TRUE;
}
static gint
tls_check_mac(SslDecoder*decoder, gint ct, gint ver, guint8* data,
guint32 datalen, guint8* mac)
{
SSL_HMAC hm;
gint md;
guint32 len;
guint8 buf[DIGEST_MAX_SIZE];
gint16 temp;
md=ssl_get_digest_by_name(ssl_cipher_suite_dig(decoder->cipher_suite)->name);
ssl_debug_printf("tls_check_mac mac type:%s md %d\n",
ssl_cipher_suite_dig(decoder->cipher_suite)->name, md);
if (ssl_hmac_init(&hm,decoder->mac_key.data,decoder->mac_key.data_len,md) != 0)
return -1;
phton64(buf, decoder->seq);
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
len = sizeof(buf);
ssl_hmac_final(&hm,buf,&len);
ssl_hmac_cleanup(&hm);
ssl_print_data("Mac", buf, len);
if(memcmp(mac,buf,len))
return -1;
return 0;
}
static int
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
phton64(buf, decoder->seq);
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
guint8 buf[DIGEST_MAX_SIZE];
gint16 temp;
md=ssl_get_digest_by_name(ssl_cipher_suite_dig(decoder->cipher_suite)->name);
ssl_debug_printf("dtls_check_mac mac type:%s md %d\n",
ssl_cipher_suite_dig(decoder->cipher_suite)->name, md);
if (ssl_hmac_init(&hm,decoder->mac_key.data,decoder->mac_key.data_len,md) != 0)
return -1;
ssl_debug_printf("dtls_check_mac seq: %" G_GUINT64_FORMAT " epoch: %d\n",decoder->seq,decoder->epoch);
phton64(buf, decoder->seq);
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
len = sizeof(buf);
ssl_hmac_final(&hm,buf,&len);
ssl_hmac_cleanup(&hm);
ssl_print_data("Mac", buf, len);
if(memcmp(mac,buf,len))
return -1;
return(0);
}
static gboolean
tls_decrypt_aead_record(SslDecryptSession *ssl, SslDecoder *decoder,
#ifdef HAVE_LIBGCRYPT_AEAD
guint8 ct, guint16 record_version,
#else
guint8 ct _U_, guint16 record_version _U_,
#endif
const guchar *in, guint16 inl, StringInfo *out_str, guint *outl)
{
const guint16 version = ssl->session.version;
const gboolean is_v12 = version == TLSV1DOT2_VERSION || version == DTLSV1DOT2_VERSION;
gcry_error_t err;
const guchar *explicit_nonce = NULL, *ciphertext;
guint ciphertext_len, auth_tag_len;
guchar nonce[12];
const ssl_cipher_mode_t cipher_mode = decoder->cipher_suite->mode;
#ifdef HAVE_LIBGCRYPT_AEAD
const guchar *auth_tag_wire;
guchar auth_tag_calc[16];
#else
guchar nonce_with_counter[16] = { 0 };
#endif
switch (cipher_mode) {
case MODE_GCM:
case MODE_CCM:
case MODE_POLY1305:
auth_tag_len = 16;
break;
case MODE_CCM_8:
auth_tag_len = 8;
break;
default:
ssl_debug_printf("%s unsupported cipher!\n", G_STRFUNC);
return FALSE;
}
if (is_v12 && cipher_mode != MODE_POLY1305) {
if (inl < EXPLICIT_NONCE_LEN + auth_tag_len) {
ssl_debug_printf("%s input %d is too small for explicit nonce %d and auth tag %d\n",
G_STRFUNC, inl, EXPLICIT_NONCE_LEN, auth_tag_len);
return FALSE;
}
explicit_nonce = in;
ciphertext = explicit_nonce + EXPLICIT_NONCE_LEN;
ciphertext_len = inl - EXPLICIT_NONCE_LEN - auth_tag_len;
} else if (version == TLSV1DOT3_VERSION || cipher_mode == MODE_POLY1305) {
if (inl < auth_tag_len) {
ssl_debug_printf("%s input %d has no space for auth tag %d\n", G_STRFUNC, inl, auth_tag_len);
return FALSE;
}
ciphertext = in;
ciphertext_len = inl - auth_tag_len;
} else {
ssl_debug_printf("%s Unexpected TLS version %#x\n", G_STRFUNC, version);
return FALSE;
}
#ifdef HAVE_LIBGCRYPT_AEAD
auth_tag_wire = ciphertext + ciphertext_len;
#endif
if (is_v12 && cipher_mode != MODE_POLY1305) {
DISSECTOR_ASSERT(decoder->write_iv.data_len == IMPLICIT_NONCE_LEN);
memcpy(nonce, decoder->write_iv.data, IMPLICIT_NONCE_LEN);
memcpy(nonce + IMPLICIT_NONCE_LEN, explicit_nonce, EXPLICIT_NONCE_LEN);
#ifndef HAVE_LIBGCRYPT_AEAD
if (cipher_mode == MODE_GCM) {
memcpy(nonce_with_counter, nonce, IMPLICIT_NONCE_LEN + EXPLICIT_NONCE_LEN);
nonce_with_counter[IMPLICIT_NONCE_LEN + EXPLICIT_NONCE_LEN + 3] = 2;
} else if (cipher_mode == MODE_CCM || cipher_mode == MODE_CCM_8) {
nonce_with_counter[0] = 3 - 1;
memcpy(nonce_with_counter + 1, nonce, IMPLICIT_NONCE_LEN + EXPLICIT_NONCE_LEN);
nonce_with_counter[IMPLICIT_NONCE_LEN + EXPLICIT_NONCE_LEN + 3] = 1;
} else {
g_assert_not_reached();
}
#endif
} else if (version == TLSV1DOT3_VERSION || cipher_mode == MODE_POLY1305) {
const guint nonce_len = 12;
DISSECTOR_ASSERT(decoder->write_iv.data_len == nonce_len);
memcpy(nonce, decoder->write_iv.data, decoder->write_iv.data_len);
phton64(nonce + nonce_len - 8, pntoh64(nonce + nonce_len - 8) ^ decoder->seq);
ssl_debug_printf("%s seq %" G_GUINT64_FORMAT "\n", G_STRFUNC, decoder->seq);
if (!is_v12) {
decoder->seq++;
}
}
#ifdef HAVE_LIBGCRYPT_AEAD
gcry_cipher_reset(decoder->evp);
ssl_print_data("nonce", nonce, 12);
err = gcry_cipher_setiv(decoder->evp, nonce, 12);
if (err) {
ssl_debug_printf("%s failed to set nonce: %s\n", G_STRFUNC, gcry_strerror(err));
return FALSE;
}
if (decoder->cipher_suite->mode == MODE_CCM || decoder->cipher_suite->mode == MODE_CCM_8) {
guint64 lengths[3] = { ciphertext_len, is_v12 ? 13 : 0, auth_tag_len };
gcry_cipher_ctl(decoder->evp, GCRYCTL_SET_CCM_LENGTHS, lengths, sizeof(lengths));
}
if (is_v12) {
guchar aad[13];
phton64(aad, decoder->seq);
if (version == TLSV1DOT2_VERSION) {
decoder->seq++;
} else {
phton16(aad, decoder->epoch);
}
aad[8] = ct;
phton16(aad + 9, record_version);
phton16(aad + 11, ciphertext_len);
ssl_print_data("AAD", aad, sizeof(aad));
err = gcry_cipher_authenticate(decoder->evp, aad, sizeof(aad));
if (err) {
ssl_debug_printf("%s failed to set AAD: %s\n", G_STRFUNC, gcry_strerror(err));
return FALSE;
}
}
#else
err = gcry_cipher_setctr(decoder->evp, nonce_with_counter, 16);
if (err) {
ssl_debug_printf("%s failed: failed to set CTR: %s\n", G_STRFUNC, gcry_strerror(err));
return FALSE;
}
#endif
err = gcry_cipher_decrypt(decoder->evp, out_str->data, out_str->data_len, ciphertext, ciphertext_len);
if (err) {
ssl_debug_printf("%s decrypt failed: %s\n", G_STRFUNC, gcry_strerror(err));
return FALSE;
}
#ifdef HAVE_LIBGCRYPT_AEAD
err = gcry_cipher_gettag(decoder->evp, auth_tag_calc, auth_tag_len);
if (err == 0 && !memcmp(auth_tag_calc, auth_tag_wire, auth_tag_len)) {
ssl_print_data("auth_tag(OK)", auth_tag_calc, auth_tag_len);
} else {
if (err) {
ssl_debug_printf("%s cannot obtain tag: %s\n", G_STRFUNC, gcry_strerror(err));
} else {
ssl_debug_printf("%s auth tag mismatch\n", G_STRFUNC);
ssl_print_data("auth_tag(expect)", auth_tag_calc, auth_tag_len);
ssl_print_data("auth_tag(actual)", auth_tag_wire, auth_tag_len);
}
if (ssl_ignore_mac_failed) {
ssl_debug_printf("%s: auth check failed, but ignored for troubleshooting ;-)\n", G_STRFUNC);
} else {
return FALSE;
}
}
#else
ssl_debug_printf("Libgcrypt is older than 1.6, unable to verify auth tag!\n");
#endif
ssl_print_data("Plaintext", out_str->data, ciphertext_len);
*outl = ciphertext_len;
return TRUE;
}
int
ssl_decrypt_record(SslDecryptSession *ssl, SslDecoder *decoder, guint8 ct, guint16 record_version,
const guchar *in, guint16 inl, StringInfo *comp_str, StringInfo *out_str, guint *outl)
{
guint pad, worklen, uncomplen, maclen, mac_fraglen = 0;
guint8 *mac = NULL, *mac_frag = NULL;
ssl_debug_printf("ssl_decrypt_record ciphertext len %d\n", inl);
ssl_print_data("Ciphertext",in, inl);
if ((ssl->session.version == TLSV1DOT3_VERSION) != (decoder->cipher_suite->kex == KEX_TLS13)) {
ssl_debug_printf("%s Invalid cipher suite for the protocol version!\n", G_STRFUNC);
return -1;
}
if (inl > out_str->data_len)
{
ssl_debug_printf("ssl_decrypt_record: allocating %d bytes for decrypt data (old len %d)\n",
inl + 32, out_str->data_len);
ssl_data_realloc(out_str, inl + 32);
}
if (decoder->cipher_suite->mode == MODE_GCM ||
decoder->cipher_suite->mode == MODE_CCM ||
decoder->cipher_suite->mode == MODE_CCM_8 ||
decoder->cipher_suite->mode == MODE_POLY1305 ||
ssl->session.version == TLSV1DOT3_VERSION) {
if (!tls_decrypt_aead_record(ssl, decoder, ct, record_version, in, inl, out_str, &worklen)) {
return -1;
}
goto skip_mac;
}
maclen = ssl_cipher_suite_dig(decoder->cipher_suite)->len;
if (decoder->cipher_suite->mode == MODE_CBC) {
guint blocksize = 0;
switch (ssl->session.version) {
case TLSV1DOT1_VERSION:
case TLSV1DOT2_VERSION:
case DTLSV1DOT0_VERSION:
case DTLSV1DOT2_VERSION:
case DTLSV1DOT0_OPENSSL_VERSION:
blocksize = ssl_get_cipher_blocksize(decoder->cipher_suite);
if (inl < blocksize) {
ssl_debug_printf("ssl_decrypt_record failed: input %d has no space for IV %d\n",
inl, blocksize);
return -1;
}
pad = gcry_cipher_setiv(decoder->evp, in, blocksize);
if (pad != 0) {
ssl_debug_printf("ssl_decrypt_record failed: failed to set IV: %s %s\n",
gcry_strsource (pad), gcry_strerror (pad));
}
inl -= blocksize;
in += blocksize;
break;
}
if (ssl->state & SSL_ENCRYPT_THEN_MAC) {
if (inl < maclen) {
ssl_debug_printf("%s failed: input %d has no space for MAC %d\n",
G_STRFUNC, inl, maclen);
return -1;
}
inl -= maclen;
mac = (guint8 *)in + inl;
mac_frag = (guint8 *)in - blocksize;
mac_fraglen = blocksize + inl;
}
}
if ((pad = ssl_cipher_decrypt(&decoder->evp, out_str->data, out_str->data_len, in, inl)) != 0) {
ssl_debug_printf("ssl_decrypt_record failed: ssl_cipher_decrypt: %s %s\n", gcry_strsource (pad),
gcry_strerror (pad));
return -1;
}
ssl_print_data("Plaintext", out_str->data, inl);
worklen=inl;
if (decoder->cipher_suite->mode == MODE_CBC) {
if (inl < 1) {
ssl_debug_printf("ssl_decrypt_record failed: input length %d too small\n", inl);
return -1;
}
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
if (!mac) {
if (worklen < maclen) {
ssl_debug_printf("%s wrong record len/padding outlen %d\n work %d\n", G_STRFUNC, *outl, worklen);
return -1;
}
worklen -= maclen;
mac = out_str->data + worklen;
mac_frag = out_str->data;
mac_fraglen = worklen;
}
if (decoder->cipher_suite->mode == MODE_STREAM &&
decoder->cipher_suite->enc == ENC_NULL &&
!(ssl->state & SSL_MASTER_SECRET)) {
ssl_debug_printf("MAC check skipped due to missing keys\n");
goto skip_mac;
}
ssl_debug_printf("checking mac (len %d, version %X, ct %d seq %" G_GUINT64_FORMAT ")\n",
worklen, ssl->session.version, ct, decoder->seq);
if(ssl->session.version==SSLV3_VERSION){
if(ssl3_check_mac(decoder,ct,mac_frag,mac_fraglen,mac) < 0) {
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
else if(ssl->session.version==TLSV1_VERSION || ssl->session.version==TLSV1DOT1_VERSION || ssl->session.version==TLSV1DOT2_VERSION){
if(tls_check_mac(decoder,ct,ssl->session.version,mac_frag,mac_fraglen,mac)< 0) {
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
else if(ssl->session.version==DTLSV1DOT0_VERSION ||
ssl->session.version==DTLSV1DOT2_VERSION ||
ssl->session.version==DTLSV1DOT0_OPENSSL_VERSION){
if(dtls_check_mac(decoder,ct,ssl->session.version,mac_frag,mac_fraglen,mac)>= 0) {
ssl_debug_printf("ssl_decrypt_record: mac ok\n");
}
else if(tls_check_mac(decoder,ct,TLSV1_VERSION,mac_frag,mac_fraglen,mac)>= 0) {
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
static gcry_sexp_t
ssl_privkey_to_sexp(gnutls_x509_privkey_t priv_key)
{
gnutls_datum_t rsa_datum[RSA_PARS];
size_t tmp_size;
gcry_error_t gret;
gcry_sexp_t rsa_priv_key = NULL;
gint i;
gcry_mpi_t rsa_params[RSA_PARS];
if (gnutls_x509_privkey_export_rsa_raw(priv_key,
&rsa_datum[0],
&rsa_datum[1],
&rsa_datum[2],
&rsa_datum[3],
&rsa_datum[4],
&rsa_datum[5]) != 0) {
ssl_debug_printf("ssl_load_key: can't export rsa param (is a rsa private key file ?!?)\n");
return NULL;
}
for(i=0; i<RSA_PARS; i++) {
gret = gcry_mpi_scan(&rsa_params[i], GCRYMPI_FMT_USG, rsa_datum[i].data, rsa_datum[i].size,&tmp_size);
g_free(rsa_datum[i].data);
if (gret != 0) {
ssl_debug_printf("ssl_load_key: can't convert m rsa param to int (size %d)\n", rsa_datum[i].size);
return NULL;
}
}
if (gcry_mpi_cmp(rsa_params[3], rsa_params[4]) > 0)
{
ssl_debug_printf("ssl_load_key: swapping p and q parameters and recomputing u\n");
gcry_mpi_swap(rsa_params[3], rsa_params[4]);
}
gcry_mpi_invm(rsa_params[5], rsa_params[3], rsa_params[4]);
if (gcry_sexp_build( &rsa_priv_key, NULL,
"(private-key(rsa((n%m)(e%m)(d%m)(p%m)(q%m)(u%m))))", rsa_params[0],
rsa_params[1], rsa_params[2], rsa_params[3], rsa_params[4],
rsa_params[5]) != 0) {
ssl_debug_printf("ssl_load_key: can't build rsa private key s-exp\n");
return NULL;
}
for (i=0; i< 6; i++)
gcry_mpi_release(rsa_params[i]);
return rsa_priv_key;
}
static gnutls_x509_privkey_t
ssl_load_key(FILE* fp)
{
gnutls_x509_privkey_t priv_key;
gnutls_datum_t key;
ws_statb64 statbuf;
gint ret;
guint bytes;
if (ws_fstat64(ws_fileno(fp), &statbuf) == -1) {
ssl_debug_printf("ssl_load_key: can't ws_fstat64 file\n");
return NULL;
}
if (S_ISDIR(statbuf.st_mode)) {
ssl_debug_printf("ssl_load_key: file is a directory\n");
errno = EISDIR;
return NULL;
}
if (S_ISFIFO(statbuf.st_mode)) {
ssl_debug_printf("ssl_load_key: file is a named pipe\n");
errno = EINVAL;
return NULL;
}
if (!S_ISREG(statbuf.st_mode)) {
ssl_debug_printf("ssl_load_key: file is not a regular file\n");
errno = EINVAL;
return NULL;
}
key.data = (unsigned char *)g_malloc((size_t)statbuf.st_size);
key.size = (int)statbuf.st_size;
bytes = (guint) fread(key.data, 1, key.size, fp);
if (bytes < key.size) {
ssl_debug_printf("ssl_load_key: can't read from file %d bytes, got %d\n",
key.size, bytes);
g_free(key.data);
return NULL;
}
gnutls_x509_privkey_init(&priv_key);
if ((ret = gnutls_x509_privkey_import(priv_key, &key, GNUTLS_X509_FMT_PEM)) != GNUTLS_E_SUCCESS) {
ssl_debug_printf("ssl_load_key: can't import pem data: %s\n", gnutls_strerror(ret));
g_free(key.data);
return NULL;
}
if (gnutls_x509_privkey_get_pk_algorithm(priv_key) != GNUTLS_PK_RSA) {
ssl_debug_printf("ssl_load_key: private key public key algorithm isn't RSA\n");
g_free(key.data);
return NULL;
}
g_free(key.data);
return priv_key;
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
static gnutls_x509_privkey_t
ssl_load_pkcs12(FILE* fp, const gchar *cert_passwd, char** err) {
int i, j, ret;
int rest;
unsigned char *p;
gnutls_datum_t data;
gnutls_pkcs12_bag_t bag = NULL;
gnutls_pkcs12_bag_type_t bag_type;
size_t len;
gnutls_pkcs12_t ssl_p12 = NULL;
gnutls_x509_privkey_t ssl_pkey = NULL;
gnutls_x509_privkey_t priv_key = NULL;
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
*err = g_strdup("Error during certificate reading.");
ssl_debug_printf("%s\n", *err);
g_free(data.data);
return 0;
}
ret = gnutls_pkcs12_init(&ssl_p12);
if (ret < 0) {
*err = g_strdup_printf("gnutls_pkcs12_init(&st_p12) - %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
g_free(data.data);
return 0;
}
ret = gnutls_pkcs12_import(ssl_p12, &data, GNUTLS_X509_FMT_DER, 0);
if (ret < 0) {
*err = g_strdup_printf("could not load PKCS#12 in DER format: %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
g_free(*err);
ret = gnutls_pkcs12_import(ssl_p12, &data, GNUTLS_X509_FMT_PEM, 0);
if (ret < 0) {
*err = g_strdup_printf("could not load PKCS#12 in PEM format: %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
} else {
*err = NULL;
}
}
g_free(data.data);
if (ret < 0) {
return 0;
}
ssl_debug_printf( "PKCS#12 imported\n");
for (i=0; ; i++) {
ret = gnutls_pkcs12_bag_init(&bag);
if (ret < 0) break;
ret = gnutls_pkcs12_get_bag(ssl_p12, i, bag);
if (ret < 0) break;
for (j=0; j<gnutls_pkcs12_bag_get_count(bag); j++) {
ret = gnutls_pkcs12_bag_get_type(bag, j);
if (ret < 0) goto done;
bag_type = (gnutls_pkcs12_bag_type_t)ret;
if (bag_type >= GNUTLS_BAG_UNKNOWN) goto done;
ssl_debug_printf( "Bag %d/%d: %s\n", i, j, BAGTYPE(bag_type));
if (bag_type == GNUTLS_BAG_ENCRYPTED) {
ret = gnutls_pkcs12_bag_decrypt(bag, cert_passwd);
if (ret == 0) {
ret = gnutls_pkcs12_bag_get_type(bag, j);
if (ret < 0) goto done;
bag_type = (gnutls_pkcs12_bag_type_t)ret;
if (bag_type >= GNUTLS_BAG_UNKNOWN) goto done;
ssl_debug_printf( "Bag %d/%d decrypted: %s\n", i, j, BAGTYPE(bag_type));
}
}
ret = gnutls_pkcs12_bag_get_data(bag, j, &data);
if (ret < 0) goto done;
switch (bag_type) {
case GNUTLS_BAG_PKCS8_KEY:
case GNUTLS_BAG_PKCS8_ENCRYPTED_KEY:
ret = gnutls_x509_privkey_init(&ssl_pkey);
if (ret < 0) {
*err = g_strdup_printf("gnutls_x509_privkey_init(&ssl_pkey) - %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
goto done;
}
ret = gnutls_x509_privkey_import_pkcs8(ssl_pkey, &data, GNUTLS_X509_FMT_DER, cert_passwd,
(bag_type==GNUTLS_BAG_PKCS8_KEY) ? GNUTLS_PKCS_PLAIN : 0);
if (ret < 0) {
*err = g_strdup_printf("Can not decrypt private key - %s", gnutls_strerror(ret));
ssl_debug_printf("%s\n", *err);
goto done;
}
if (gnutls_x509_privkey_get_pk_algorithm(ssl_pkey) != GNUTLS_PK_RSA) {
*err = g_strdup("ssl_load_pkcs12: private key public key algorithm isn't RSA");
ssl_debug_printf("%s\n", *err);
goto done;
}
priv_key = ssl_pkey;
goto done;
default: ;
}
}
if (bag) { gnutls_pkcs12_bag_deinit(bag); bag = NULL; }
}
done:
if (!priv_key && ssl_pkey)
gnutls_x509_privkey_deinit(ssl_pkey);
if (bag)
gnutls_pkcs12_bag_deinit(bag);
return priv_key;
}
void
ssl_private_key_free(gpointer key)
{
gcry_sexp_release((gcry_sexp_t) key);
}
static void
ssl_find_private_key_by_pubkey(SslDecryptSession *ssl, GHashTable *key_hash,
gnutls_datum_t *subjectPublicKeyInfo)
{
gnutls_pubkey_t pubkey = NULL;
guchar key_id[20];
size_t key_id_len = sizeof(key_id);
int r;
if (!subjectPublicKeyInfo->size) {
ssl_debug_printf("%s: could not find SubjectPublicKeyInfo\n", G_STRFUNC);
return;
}
r = gnutls_pubkey_init(&pubkey);
if (r < 0) {
ssl_debug_printf("%s: failed to init pubkey: %s\n",
G_STRFUNC, gnutls_strerror(r));
return;
}
r = gnutls_pubkey_import(pubkey, subjectPublicKeyInfo, GNUTLS_X509_FMT_DER);
if (r < 0) {
ssl_debug_printf("%s: failed to import pubkey from handshake: %s\n",
G_STRFUNC, gnutls_strerror(r));
goto end;
}
r = gnutls_pubkey_get_key_id(pubkey, 0, key_id, &key_id_len);
if (r < 0) {
ssl_debug_printf("%s: failed to extract key id from pubkey: %s\n",
G_STRFUNC, gnutls_strerror(r));
goto end;
}
ssl_print_data("lookup(KeyID)", key_id, key_id_len);
ssl->private_key = (gcry_sexp_t)g_hash_table_lookup(key_hash, key_id);
ssl_debug_printf("%s: lookup result: %p\n", G_STRFUNC, (void *) ssl->private_key);
end:
gnutls_pubkey_deinit(pubkey);
}
void
ssl_private_key_free(gpointer key _U_)
{
}
SslDecryptSession *
ssl_get_session(conversation_t *conversation, dissector_handle_t ssl_handle)
{
void *conv_data;
SslDecryptSession *ssl_session;
int proto_ssl;
proto_ssl = dissector_handle_get_protocol_index(ssl_handle);
conv_data = conversation_get_proto_data(conversation, proto_ssl);
if (conv_data != NULL)
return (SslDecryptSession *)conv_data;
ssl_session = wmem_new0(wmem_file_scope(), SslDecryptSession);
ssl_session->master_secret.data_len = 0;
ssl_session->master_secret.data = ssl_session->_master_secret;
ssl_session->session_id.data_len = 0;
ssl_session->session_id.data = ssl_session->_session_id;
ssl_session->client_random.data_len = 0;
ssl_session->client_random.data = ssl_session->_client_random;
ssl_session->server_random.data_len = 0;
ssl_session->server_random.data = ssl_session->_server_random;
ssl_session->session_ticket.data_len = 0;
ssl_session->session_ticket.data = NULL;
ssl_session->server_data_for_iv.data_len = 0;
ssl_session->server_data_for_iv.data = ssl_session->_server_data_for_iv;
ssl_session->client_data_for_iv.data_len = 0;
ssl_session->client_data_for_iv.data = ssl_session->_client_data_for_iv;
ssl_session->app_data_segment.data = NULL;
ssl_session->app_data_segment.data_len = 0;
ssl_session->handshake_data.data=NULL;
ssl_session->handshake_data.data_len=0;
ssl_session->session.version = SSL_VER_UNKNOWN;
clear_address(&ssl_session->session.srv_addr);
ssl_session->session.srv_ptype = PT_NONE;
ssl_session->session.srv_port = 0;
conversation_add_proto_data(conversation, proto_ssl, ssl_session);
return ssl_session;
}
static void ssl_reset_session(SslSession *session, SslDecryptSession *ssl, gboolean is_client)
{
if (ssl) {
gint clear_flags = SSL_HAVE_SESSION_KEY | SSL_MASTER_SECRET | SSL_PRE_MASTER_SECRET;
if (is_client) {
clear_flags |= SSL_CLIENT_EXTENDED_MASTER_SECRET;
ssl->session_id.data_len = 0;
ssl->session_ticket.data_len = 0;
ssl->master_secret.data_len = 0;
ssl->client_random.data_len = 0;
ssl->has_early_data = FALSE;
} else {
clear_flags |= SSL_SERVER_EXTENDED_MASTER_SECRET | SSL_NEW_SESSION_TICKET;
ssl->server_random.data_len = 0;
ssl->pre_master_secret.data_len = 0;
#if defined(HAVE_LIBGNUTLS)
ssl->private_key = NULL;
#endif
ssl->psk.data_len = 0;
}
if (ssl->state & clear_flags) {
ssl_debug_printf("%s detected renegotiation, clearing 0x%02x (%s side)\n",
G_STRFUNC, ssl->state & clear_flags, is_client ? "client" : "server");
ssl->state &= ~clear_flags;
}
}
if (is_client) {
session->client_cert_type = 0;
} else {
session->compression = 0;
session->server_cert_type = 0;
}
}
static guint32
ssl_starttls(dissector_handle_t ssl_handle, packet_info *pinfo,
dissector_handle_t app_handle, guint32 last_nontls_frame)
{
conversation_t *conversation;
SslSession *session;
if (!ssl_handle)
return 0;
DISSECTOR_ASSERT(app_handle);
conversation = find_or_create_conversation(pinfo);
session = &ssl_get_session(conversation, ssl_handle)->session;
ssl_debug_printf("%s: old frame %d, app_handle=%p (%s)\n", G_STRFUNC,
session->last_nontls_frame,
(void *)session->app_handle,
dissector_handle_get_dissector_name(session->app_handle));
ssl_debug_printf("%s: current frame %d, app_handle=%p (%s)\n", G_STRFUNC,
pinfo->num, (void *)app_handle,
dissector_handle_get_dissector_name(app_handle));
if (session->last_nontls_frame) {
ssl_debug_printf("%s: not overriding previous app handle!\n", G_STRFUNC);
return session->last_nontls_frame;
}
session->app_handle = app_handle;
conversation_set_dissector(conversation, ssl_handle);
session->last_nontls_frame = last_nontls_frame;
return 0;
}
guint32
ssl_starttls_ack(dissector_handle_t ssl_handle, packet_info *pinfo,
dissector_handle_t app_handle)
{
return ssl_starttls(ssl_handle, pinfo, app_handle, pinfo->num);
}
guint32
ssl_starttls_post_ack(dissector_handle_t ssl_handle, packet_info *pinfo,
dissector_handle_t app_handle)
{
return ssl_starttls(ssl_handle, pinfo, app_handle, pinfo->num - 1);
}
dissector_handle_t
ssl_find_appdata_dissector(const char *name)
{
if (!strcmp(name, "http"))
name = "http-over-tls";
return find_dissector(name);
}
static gint
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
static guint
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
gboolean
ssl_private_key_equal (gconstpointer v, gconstpointer v2)
{
return !memcmp(v, v2, 20);
}
guint
ssl_private_key_hash (gconstpointer v)
{
guint l, hash = 0;
const guint8 *cur = (const guint8 *)v;
for (l = 0; l < 20; l += 4, cur += 4)
hash ^= pntoh32(cur);
return hash;
}
void
ssl_association_add(const char* dissector_table_name, dissector_handle_t main_handle, dissector_handle_t subdissector_handle, guint port, gboolean tcp)
{
DISSECTOR_ASSERT(main_handle);
DISSECTOR_ASSERT(subdissector_handle);
DISSECTOR_ASSERT_HINT(dissector_handle_get_dissector_name(subdissector_handle),
"SSL appdata dissectors must register with register_dissector()!");
ssl_debug_printf("association_add %s port %d handle %p\n", dissector_table_name, port, (void *)subdissector_handle);
if (port) {
dissector_add_uint(dissector_table_name, port, subdissector_handle);
if (tcp)
dissector_add_uint("tcp.port", port, main_handle);
else
dissector_add_uint("udp.port", port, main_handle);
dissector_add_uint("sctp.port", port, main_handle);
} else {
dissector_add_for_decode_as(dissector_table_name, subdissector_handle);
}
}
void
ssl_association_remove(const char* dissector_table_name, dissector_handle_t main_handle, dissector_handle_t subdissector_handle, guint port, gboolean tcp)
{
ssl_debug_printf("ssl_association_remove removing %s %u - handle %p\n",
tcp?"TCP":"UDP", port, (void *)subdissector_handle);
if (main_handle) {
dissector_delete_uint(tcp?"tcp.port":"udp.port", port, main_handle);
dissector_delete_uint("sctp.port", port, main_handle);
}
if (port) {
dissector_delete_uint(dissector_table_name, port, subdissector_handle);
}
}
void
ssl_set_server(SslSession *session, address *addr, port_type ptype, guint32 port)
{
copy_address_wmem(wmem_file_scope(), &session->srv_addr, addr);
session->srv_ptype = ptype;
session->srv_port = port;
}
int
ssl_packet_from_server(SslSession *session, dissector_table_t table, packet_info *pinfo)
{
gint ret;
if (session->srv_addr.type != AT_NONE) {
ret = (session->srv_ptype == pinfo->ptype) &&
(session->srv_port == pinfo->srcport) &&
addresses_equal(&session->srv_addr, &pinfo->src);
} else {
ret = (dissector_get_uint_handle(table, pinfo->srcport) != 0);
}
ssl_debug_printf("packet_from_server: is from server - %s\n", (ret)?"TRUE":"FALSE");
return ret;
}
void
ssl_add_record_info(gint proto, packet_info *pinfo, const guchar *data, gint data_len, gint record_id, SslFlow *flow, ContentType type)
{
SslRecordInfo* rec, **prec;
SslPacketInfo* pi;
pi = (SslPacketInfo *)p_get_proto_data(wmem_file_scope(), pinfo, proto, pinfo->curr_layer_num);
if (!pi)
{
pi = wmem_new0(wmem_file_scope(), SslPacketInfo);
pi->srcport = pinfo->srcport;
pi->destport = pinfo->destport;
p_add_proto_data(wmem_file_scope(), pinfo, proto, pinfo->curr_layer_num, pi);
}
rec = wmem_new(wmem_file_scope(), SslRecordInfo);
rec->plain_data = (guchar *)wmem_memdup(wmem_file_scope(), data, data_len);
rec->data_len = data_len;
rec->id = record_id;
rec->type = type;
rec->next = NULL;
if (flow && type == SSL_ID_APP_DATA) {
rec->seq = flow->byte_seq;
rec->flow = flow;
flow->byte_seq += data_len;
ssl_debug_printf("%s stored decrypted record seq=%d nxtseq=%d flow=%p\n",
G_STRFUNC, rec->seq, rec->seq + data_len, (void*)flow);
}
prec = &pi->records;
while (*prec) prec = &(*prec)->next;
*prec = rec;
}
tvbuff_t*
ssl_get_record_info(tvbuff_t *parent_tvb, int proto, packet_info *pinfo, gint record_id, SslRecordInfo **matched_record)
{
SslRecordInfo* rec;
SslPacketInfo* pi;
pi = (SslPacketInfo *)p_get_proto_data(wmem_file_scope(), pinfo, proto, pinfo->curr_layer_num);
if (!pi)
return NULL;
for (rec = pi->records; rec; rec = rec->next)
if (rec->id == record_id) {
*matched_record = rec;
return tvb_new_child_real_data(parent_tvb, rec->plain_data, rec->data_len, rec->data_len);
}
return NULL;
}
void
ssl_common_init(ssl_master_key_map_t *mk_map,
StringInfo *decrypted_data, StringInfo *compressed_data)
{
mk_map->session = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->tickets = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->crandom = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->pre_master = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->pms = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->tls13_client_early = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->tls13_client_handshake = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->tls13_server_handshake = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->tls13_client_appdata = g_hash_table_new(ssl_hash, ssl_equal);
mk_map->tls13_server_appdata = g_hash_table_new(ssl_hash, ssl_equal);
ssl_data_alloc(decrypted_data, 32);
ssl_data_alloc(compressed_data, 32);
}
void
ssl_common_cleanup(ssl_master_key_map_t *mk_map, FILE **ssl_keylog_file,
StringInfo *decrypted_data, StringInfo *compressed_data)
{
g_hash_table_destroy(mk_map->session);
g_hash_table_destroy(mk_map->tickets);
g_hash_table_destroy(mk_map->crandom);
g_hash_table_destroy(mk_map->pre_master);
g_hash_table_destroy(mk_map->pms);
g_hash_table_destroy(mk_map->tls13_client_early);
g_hash_table_destroy(mk_map->tls13_client_handshake);
g_hash_table_destroy(mk_map->tls13_server_handshake);
g_hash_table_destroy(mk_map->tls13_client_appdata);
g_hash_table_destroy(mk_map->tls13_server_appdata);
g_free(decrypted_data->data);
g_free(compressed_data->data);
if (*ssl_keylog_file) {
fclose(*ssl_keylog_file);
*ssl_keylog_file = NULL;
}
}
void
ssl_parse_key_list(const ssldecrypt_assoc_t *uats, GHashTable *key_hash, const char* dissector_table_name, dissector_handle_t main_handle, gboolean tcp)
{
gnutls_x509_privkey_t priv_key;
gcry_sexp_t private_key;
FILE* fp = NULL;
int ret;
size_t key_id_len = 20;
guchar *key_id = NULL;
dissector_handle_t handle;
fp = ws_fopen(uats->keyfile, "rb");
if (!fp) {
report_open_failure(uats->keyfile, errno, FALSE);
return;
}
if ((gint)strlen(uats->password) == 0) {
priv_key = ssl_load_key(fp);
} else {
char *err = NULL;
priv_key = ssl_load_pkcs12(fp, uats->password, &err);
if (err) {
report_failure("%s\n", err);
g_free(err);
}
}
fclose(fp);
if (!priv_key) {
report_failure("Can't load private key from %s\n", uats->keyfile);
return;
}
key_id = (guchar *) g_malloc0(key_id_len);
ret = gnutls_x509_privkey_get_key_id(priv_key, 0, key_id, &key_id_len);
if (ret < 0) {
report_failure("Can't calculate public key ID for %s: %s",
uats->keyfile, gnutls_strerror(ret));
goto end;
}
ssl_print_data("KeyID", key_id, key_id_len);
private_key = ssl_privkey_to_sexp(priv_key);
if (!private_key) {
report_failure("Can't extract private key parameters for %s", uats->keyfile);
goto end;
}
g_hash_table_replace(key_hash, key_id, private_key);
key_id = NULL;
ssl_debug_printf("ssl_init private key file %s successfully loaded.\n", uats->keyfile);
handle = ssl_find_appdata_dissector(uats->protocol);
if (handle) {
guint16 port = 0;
if (ws_strtou16(uats->port, NULL, &port)) {
if (port > 0) {
ssl_debug_printf("ssl_init port '%d' filename '%s' password(only for p12 file) '%s'\n",
port, uats->keyfile, uats->password);
ssl_association_add(dissector_table_name, main_handle, handle, port, tcp);
}
} else {
if (strcmp(uats->port, "start_tls"))
ssl_debug_printf("invalid ssl_init_port: %s\n", uats->port);
}
}
end:
gnutls_x509_privkey_deinit(priv_key);
g_free(key_id);
}
void
ssl_parse_key_list(const ssldecrypt_assoc_t *uats _U_, GHashTable *key_hash _U_, const char* dissector_table_name _U_, dissector_handle_t main_handle _U_, gboolean tcp _U_)
{
report_failure("Can't load private key files, support is not compiled in.");
}
static void
ssl_save_master_key(const char *label, GHashTable *ht, StringInfo *key,
StringInfo *mk)
{
StringInfo *ht_key, *master_secret;
if (key->data_len == 0) {
ssl_debug_printf("%s: not saving empty %s!\n", G_STRFUNC, label);
return;
}
if (mk->data_len == 0) {
ssl_debug_printf("%s not saving empty (pre-)master secret for %s!\n",
G_STRFUNC, label);
return;
}
ht_key = ssl_data_clone(key);
master_secret = ssl_data_clone(mk);
g_hash_table_insert(ht, ht_key, master_secret);
ssl_debug_printf("%s inserted (pre-)master secret for %s\n", G_STRFUNC, label);
ssl_print_string("stored key", ht_key);
ssl_print_string("stored (pre-)master secret", master_secret);
}
static gboolean
ssl_restore_master_key(SslDecryptSession *ssl, const char *label,
gboolean is_pre_master, GHashTable *ht, StringInfo *key)
{
StringInfo *ms;
if (key->data_len == 0) {
ssl_debug_printf("%s can't restore %smaster secret using an empty %s\n",
G_STRFUNC, is_pre_master ? "pre-" : "", label);
return FALSE;
}
ms = (StringInfo *)g_hash_table_lookup(ht, key);
if (!ms) {
ssl_debug_printf("%s can't find %smaster secret by %s\n", G_STRFUNC,
is_pre_master ? "pre-" : "", label);
return FALSE;
}
ssl->state &= ~(SSL_MASTER_SECRET | SSL_PRE_MASTER_SECRET |
SSL_HAVE_SESSION_KEY);
if (is_pre_master) {
ssl->pre_master_secret.data = (guchar *) wmem_alloc(wmem_file_scope(),
ms->data_len);
ssl_data_set(&ssl->pre_master_secret, ms->data, ms->data_len);
ssl->state |= SSL_PRE_MASTER_SECRET;
} else {
ssl_data_set(&ssl->master_secret, ms->data, ms->data_len);
ssl->state |= SSL_MASTER_SECRET;
}
ssl_debug_printf("%s %smaster secret retrieved using %s\n", G_STRFUNC,
is_pre_master ? "pre-" : "", label);
ssl_print_string(label, key);
ssl_print_string("(pre-)master secret", ms);
return TRUE;
}
void
ssl_finalize_decryption(SslDecryptSession *ssl, ssl_master_key_map_t *mk_map)
{
if (ssl->session.version == TLSV1DOT3_VERSION) {
return;
}
ssl_debug_printf("%s state = 0x%02X\n", G_STRFUNC, ssl->state);
if (ssl->state & SSL_HAVE_SESSION_KEY) {
ssl_debug_printf(" session key already available, nothing to do.\n");
return;
}
if (!(ssl->state & SSL_CIPHER)) {
ssl_debug_printf(" Cipher suite (Server Hello) is missing!\n");
return;
}
if (!(ssl->state & (SSL_MASTER_SECRET | SSL_PRE_MASTER_SECRET)) &&
!ssl_restore_master_key(ssl, "Session ID", FALSE,
mk_map->session, &ssl->session_id) &&
(!ssl->session.is_session_resumed ||
!ssl_restore_master_key(ssl, "Session Ticket", FALSE,
mk_map->tickets, &ssl->session_ticket)) &&
!ssl_restore_master_key(ssl, "Client Random", FALSE,
mk_map->crandom, &ssl->client_random)) {
if (ssl->cipher_suite->enc != ENC_NULL) {
ssl_debug_printf(" Cannot find master secret\n");
return;
} else {
ssl_debug_printf(" Cannot find master secret, continuing anyway "
"because of a NULL cipher\n");
}
}
if (ssl_generate_keyring_material(ssl) < 0) {
ssl_debug_printf("%s can't generate keyring material\n", G_STRFUNC);
return;
}
ssl_save_master_key("Client Random", mk_map->crandom,
&ssl->client_random, &ssl->master_secret);
ssl_save_master_key("Session ID", mk_map->session,
&ssl->session_id, &ssl->master_secret);
if (ssl->state & SSL_NEW_SESSION_TICKET) {
ssl_save_master_key("Session Ticket", mk_map->tickets,
&ssl->session_ticket, &ssl->master_secret);
}
}
void
tls13_change_key(SslDecryptSession *ssl, ssl_master_key_map_t *mk_map,
gboolean is_from_server, TLSRecordType type)
{
GHashTable *key_map;
const char *label;
if (ssl->session.version != TLSV1DOT3_VERSION) {
ssl_debug_printf("%s TLS version %#x is not 1.3\n", G_STRFUNC, ssl->session.version);
return;
}
if (ssl->client_random.data_len == 0) {
ssl_debug_printf("%s missing Client Random\n", G_STRFUNC);
return;
}
switch (type) {
case TLS_SECRET_0RTT_APP:
DISSECTOR_ASSERT(!is_from_server);
label = "CLIENT_EARLY_TRAFFIC_SECRET";
key_map = mk_map->tls13_client_early;
break;
case TLS_SECRET_HANDSHAKE:
if (is_from_server) {
label = "SERVER_HANDSHAKE_TRAFFIC_SECRET";
key_map = mk_map->tls13_server_handshake;
} else {
label = "CLIENT_HANDSHAKE_TRAFFIC_SECRET";
key_map = mk_map->tls13_client_handshake;
}
break;
case TLS_SECRET_APP:
if (is_from_server) {
label = "SERVER_TRAFFIC_SECRET_0";
key_map = mk_map->tls13_server_appdata;
} else {
label = "CLIENT_TRAFFIC_SECRET_0";
key_map = mk_map->tls13_client_appdata;
}
break;
default:
g_assert_not_reached();
}
ssl_debug_printf("%s transitioning to new key, old state 0x%02x\n", G_STRFUNC, ssl->state);
ssl->state &= ~(SSL_MASTER_SECRET | SSL_PRE_MASTER_SECRET | SSL_HAVE_SESSION_KEY);
StringInfo *secret = (StringInfo *)g_hash_table_lookup(key_map, &ssl->client_random);
if (!secret) {
ssl_debug_printf("%s Cannot find %s, decryption impossible\n", G_STRFUNC, label);
if (is_from_server) {
ssl->server = NULL;
} else {
ssl->client = NULL;
}
return;
}
ssl_debug_printf("%s Retrieved TLS 1.3 traffic secret.\n", G_STRFUNC);
ssl_print_string("Client Random", &ssl->client_random);
ssl_print_string(label, secret);
if (tls13_generate_keys(ssl, secret, is_from_server)) {
SslDecoder *decoder = is_from_server ? ssl->server : ssl->client;
StringInfo *app_secret = &decoder->app_traffic_secret;
if (type == TLS_SECRET_APP) {
app_secret->data = (guchar *) wmem_realloc(wmem_file_scope(),
app_secret->data,
secret->data_len);
ssl_data_set(app_secret, secret->data, secret->data_len);
} else {
wmem_free(wmem_file_scope(), app_secret->data);
app_secret->data = NULL;
app_secret->data_len = 0;
}
}
}
void
tls13_key_update(SslDecryptSession *ssl, gboolean is_from_server)
{
const SslCipherSuite *cipher_suite = ssl->cipher_suite;
SslDecoder *decoder = is_from_server ? ssl->server : ssl->client;
StringInfo *app_secret = decoder ? &decoder->app_traffic_secret : NULL;
if (!cipher_suite || !app_secret || app_secret->data_len == 0) {
ssl_debug_printf("%s Cannot perform Key Update due to missing info\n", G_STRFUNC);
return;
}
const char *hash_name = ssl_cipher_suite_dig(cipher_suite)->name;
int hash_algo = ssl_get_digest_by_name(hash_name);
const guint hash_len = app_secret->data_len;
guchar *new_secret;
if (!tls13_hkdf_expand_label(ssl->session.tls13_draft_version,
hash_algo, app_secret, "application traffic secret", "",
hash_len, &new_secret)) {
ssl_debug_printf("%s traffic_secret_N+1 expansion failed\n", G_STRFUNC);
return;
}
ssl_data_set(app_secret, new_secret, hash_len);
wmem_free(NULL, new_secret);
tls13_generate_keys(ssl, app_secret, is_from_server);
}
static GRegex *
ssl_compile_keyfile_regex(void)
{
#define OCTET "(?:[[:xdigit:]]{2})"
const gchar *pattern =
"(?:"
"PMS_CLIENT_RANDOM (?<client_random_pms>" OCTET "{32}) "
"|RSA (?<encrypted_pmk>" OCTET "{8}) "
")(?<pms>" OCTET "+)"
"|(?:"
"RSA Session-ID:(?<session_id>" OCTET "+) Master-Key:"
"|CLIENT_RANDOM (?<client_random>" OCTET "{32}) "
")(?<master_secret>" OCTET "{" G_STRINGIFY(SSL_MASTER_SECRET_LENGTH) "})"
"|(?"
":CLIENT_EARLY_TRAFFIC_SECRET (?<client_early>" OCTET "{32})"
"|CLIENT_HANDSHAKE_TRAFFIC_SECRET (?<client_handshake>" OCTET "{32})"
"|SERVER_HANDSHAKE_TRAFFIC_SECRET (?<server_handshake>" OCTET "{32})"
"|CLIENT_TRAFFIC_SECRET_0 (?<client_appdata>" OCTET "{32})"
"|SERVER_TRAFFIC_SECRET_0 (?<server_appdata>" OCTET "{32})"
") (?<derived_secret>" OCTET "+)";
#undef OCTET
static GRegex *regex = NULL;
GError *gerr = NULL;
if (!regex) {
regex = g_regex_new(pattern,
(GRegexCompileFlags)(G_REGEX_OPTIMIZE | G_REGEX_ANCHORED),
G_REGEX_MATCH_ANCHORED, &gerr);
if (gerr) {
ssl_debug_printf("%s failed to compile regex: %s\n", G_STRFUNC,
gerr->message);
g_error_free(gerr);
regex = NULL;
}
}
return regex;
}
static gboolean
file_needs_reopen(FILE *fp, const char *filename)
{
ws_statb64 open_stat, current_stat;
if (0 != ws_fstat64(ws_fileno(fp), &open_stat))
return TRUE;
if (0 != ws_stat64(filename, &current_stat))
return TRUE;
return open_stat.st_dev != current_stat.st_dev ||
open_stat.st_ino != current_stat.st_ino ||
open_stat.st_size > current_stat.st_size;
}
void
ssl_load_keyfile(const gchar *ssl_keylog_filename, FILE **keylog_file,
const ssl_master_key_map_t *mk_map)
{
unsigned i;
GRegex *regex;
ssl_master_key_match_group_t mk_groups[] = {
{ "encrypted_pmk", mk_map->pre_master },
{ "session_id", mk_map->session },
{ "client_random", mk_map->crandom },
{ "client_random_pms", mk_map->pms },
{ "client_early", mk_map->tls13_client_early },
{ "client_handshake", mk_map->tls13_client_handshake },
{ "server_handshake", mk_map->tls13_server_handshake },
{ "client_appdata", mk_map->tls13_client_appdata },
{ "server_appdata", mk_map->tls13_server_appdata },
};
if (!ssl_keylog_filename || !*ssl_keylog_filename) {
ssl_debug_printf("%s dtls/ssl.keylog_file is not configured!\n",
G_STRFUNC);
return;
}
regex = ssl_compile_keyfile_regex();
if (!regex)
return;
ssl_debug_printf("trying to use SSL keylog in %s\n", ssl_keylog_filename);
if (*keylog_file && file_needs_reopen(*keylog_file, ssl_keylog_filename)) {
ssl_debug_printf("%s file got deleted, trying to re-open\n", G_STRFUNC);
fclose(*keylog_file);
*keylog_file = NULL;
}
if (*keylog_file == NULL) {
*keylog_file = ws_fopen(ssl_keylog_filename, "r");
if (!*keylog_file) {
ssl_debug_printf("%s failed to open SSL keylog\n", G_STRFUNC);
return;
}
}
for (;;) {
char buf[512], *line;
gsize bytes_read;
GMatchInfo *mi;
line = fgets(buf, sizeof(buf), *keylog_file);
if (!line)
break;
bytes_read = strlen(line);
if (bytes_read > 0 && line[bytes_read - 1] == '\n') {
line[bytes_read - 1] = 0;
bytes_read--;
}
if (bytes_read > 0 && line[bytes_read - 1] == '\r') {
line[bytes_read - 1] = 0;
bytes_read--;
}
ssl_debug_printf(" checking keylog line: %s\n", line);
if (g_regex_match(regex, line, G_REGEX_MATCH_ANCHORED, &mi)) {
gchar *hex_key, *hex_pre_ms_or_ms;
StringInfo *key = wmem_new(wmem_file_scope(), StringInfo);
StringInfo *pre_ms_or_ms = NULL;
GHashTable *ht = NULL;
hex_pre_ms_or_ms = g_match_info_fetch_named(mi, "master_secret");
if (hex_pre_ms_or_ms == NULL || !*hex_pre_ms_or_ms) {
g_free(hex_pre_ms_or_ms);
hex_pre_ms_or_ms = g_match_info_fetch_named(mi, "pms");
}
if (hex_pre_ms_or_ms == NULL || !*hex_pre_ms_or_ms) {
g_free(hex_pre_ms_or_ms);
hex_pre_ms_or_ms = g_match_info_fetch_named(mi, "derived_secret");
}
DISSECTOR_ASSERT(hex_pre_ms_or_ms && strlen(hex_pre_ms_or_ms));
pre_ms_or_ms = wmem_new(wmem_file_scope(), StringInfo);
from_hex(pre_ms_or_ms, hex_pre_ms_or_ms, strlen(hex_pre_ms_or_ms));
g_free(hex_pre_ms_or_ms);
for (i = 0; i < G_N_ELEMENTS(mk_groups); i++) {
ssl_master_key_match_group_t *g = &mk_groups[i];
hex_key = g_match_info_fetch_named(mi, g->re_group_name);
if (hex_key && *hex_key) {
ssl_debug_printf(" matched %s\n", g->re_group_name);
ht = g->master_key_ht;
from_hex(key, hex_key, strlen(hex_key));
g_free(hex_key);
break;
}
g_free(hex_key);
}
DISSECTOR_ASSERT(ht);
g_hash_table_insert(ht, key, pre_ms_or_ms);
} else {
ssl_debug_printf(" unrecognized line\n");
}
g_match_info_free(mi);
}
}
void
ssl_set_debug(const gchar* name)
{
static gint debug_file_must_be_closed;
gint use_stderr;
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
else
debug_file_must_be_closed = 0;
ssl_debug_printf("Wireshark SSL debug log \n\n");
ssl_debug_printf("Wireshark version: %s\n", get_ws_vcs_version_info());
#ifdef HAVE_LIBGNUTLS
ssl_debug_printf("GnuTLS version: %s\n", gnutls_check_version(NULL));
#endif
ssl_debug_printf("Libgcrypt version: %s\n", gcry_check_version(NULL));
ssl_debug_printf("\n");
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
if (!g_ascii_isprint(c) || (c=='\t')) c = '.';
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
ssldecrypt_uat_fld_ip_chk_cb(void* r _U_, const char* p _U_, guint len _U_, const void* u1 _U_, const void* u2 _U_, char** err)
{
*err = NULL;
return TRUE;
}
gboolean
ssldecrypt_uat_fld_port_chk_cb(void* r _U_, const char* p, guint len _U_, const void* u1 _U_, const void* u2 _U_, char** err)
{
if (!p || strlen(p) == 0u) {
*err = NULL;
return TRUE;
}
if (strcmp(p, "start_tls") != 0){
guint16 port;
if (!ws_strtou16(p, NULL, &port)) {
*err = g_strdup("Invalid port given.");
return FALSE;
}
}
*err = NULL;
return TRUE;
}
gboolean
ssldecrypt_uat_fld_fileopen_chk_cb(void* r _U_, const char* p, guint len _U_, const void* u1 _U_, const void* u2 _U_, char** err)
{
ws_statb64 st;
if (!p || strlen(p) == 0u) {
*err = g_strdup("No filename given.");
return FALSE;
} else {
if (ws_stat64(p, &st) != 0) {
*err = g_strdup_printf("File '%s' does not exist or access is denied.", p);
return FALSE;
}
}
*err = NULL;
return TRUE;
}
gboolean
ssldecrypt_uat_fld_password_chk_cb(void *r _U_, const char *p _U_, guint len _U_, const void *u1 _U_, const void *u2 _U_, char **err)
{
#if defined(HAVE_LIBGNUTLS)
ssldecrypt_assoc_t* f = (ssldecrypt_assoc_t *)r;
FILE *fp = NULL;
if (p && (strlen(p) > 0u)) {
fp = ws_fopen(f->keyfile, "rb");
if (fp) {
char *msg = NULL;
gnutls_x509_privkey_t priv_key = ssl_load_pkcs12(fp, p, &msg);
if (!priv_key) {
fclose(fp);
*err = g_strdup_printf("Could not load PKCS#12 key file: %s", msg);
g_free(msg);
return FALSE;
}
g_free(msg);
gnutls_x509_privkey_deinit(priv_key);
fclose(fp);
} else {
*err = g_strdup_printf("Leave this field blank if the keyfile is not PKCS#12.");
return FALSE;
}
}
*err = NULL;
return TRUE;
#else
*err = g_strdup("Cannot load key files, support is not compiled in.");
return FALSE;
#endif
}
static void
ssl_association_info_(const gchar *table _U_, gpointer handle, gpointer user_data)
{
ssl_association_info_callback_data_t* data = (ssl_association_info_callback_data_t*)user_data;
const int l = (const int)strlen(data->str);
g_snprintf(data->str+l, SSL_ASSOC_MAX_LEN-l, "'%s' %s\n", dissector_handle_get_short_name((dissector_handle_t)handle), data->table_protocol);
}
gchar*
ssl_association_info(const char* dissector_table_name, const char* table_protocol)
{
ssl_association_info_callback_data_t data;
data.str = (gchar *)g_malloc0(SSL_ASSOC_MAX_LEN);
data.table_protocol = table_protocol;
dissector_table_foreach_handle(dissector_table_name, ssl_association_info_, &data);
return data.str;
}
gboolean
ssl_add_vector(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint offset_end, guint32 *ret_length,
int hf_length, guint32 min_value, guint32 max_value)
{
guint veclen_size;
guint32 veclen_value;
proto_item *pi;
DISSECTOR_ASSERT(offset <= offset_end);
DISSECTOR_ASSERT(min_value <= max_value);
if (max_value > 0xffffff) {
veclen_size = 4;
} else if (max_value > 0xffff) {
veclen_size = 3;
} else if (max_value > 0xff) {
veclen_size = 2;
} else {
veclen_size = 1;
}
if (offset_end - offset < veclen_size) {
proto_tree_add_expert_format(tree, pinfo, &hf->ei.malformed_buffer_too_small,
tvb, offset, offset_end - offset,
"No more room for vector of length %u",
veclen_size);
*ret_length = 0;
return FALSE;
}
pi = proto_tree_add_item_ret_uint(tree, hf_length, tvb, offset, veclen_size, ENC_BIG_ENDIAN, &veclen_value);
offset += veclen_size;
if (veclen_value < min_value) {
expert_add_info_format(pinfo, pi, &hf->ei.malformed_vector_length,
"Vector length %u is smaller than minimum %u",
veclen_value, min_value);
} else if (veclen_value > max_value) {
expert_add_info_format(pinfo, pi, &hf->ei.malformed_vector_length,
"Vector length %u is larger than maximum %u",
veclen_value, max_value);
}
if (offset_end - offset < veclen_value) {
expert_add_info_format(pinfo, pi, &hf->ei.malformed_buffer_too_small,
"Vector length %u is too large, truncating it to %u",
veclen_value, offset_end - offset);
*ret_length = offset_end - offset;
return FALSE;
}
*ret_length = veclen_value;
return TRUE;
}
gboolean
ssl_end_vector(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint offset_end)
{
if (offset < offset_end) {
guint trailing = offset_end - offset;
proto_tree_add_expert_format(tree, pinfo, &hf->ei.malformed_trailing_data,
tvb, offset, trailing,
"%u trailing byte%s unprocessed",
trailing, plurality(trailing, " was", "s were"));
return FALSE;
} else if (offset > offset_end) {
guint excess = offset - offset_end;
proto_tree_add_expert_format(tree, pinfo, &hf->ei.malformed_buffer_too_small,
tvb, offset_end, excess,
"Dissector processed too much data (%u byte%s)",
excess, plurality(excess, "", "s"));
return FALSE;
}
return TRUE;
}
void
ssl_dissect_change_cipher_spec(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree,
guint32 offset, SslSession *session,
gboolean is_from_server,
const SslDecryptSession *ssl)
{
proto_item *ti;
proto_item_set_text(tree,
"%s Record Layer: %s Protocol: Change Cipher Spec",
val_to_str_const(session->version, ssl_version_short_names, "SSL"),
val_to_str_const(SSL_ID_CHG_CIPHER_SPEC, ssl_31_content_type, "unknown"));
ti = proto_tree_add_item(tree, hf->hf.change_cipher_spec, tvb, offset, 1, ENC_NA);
if (is_from_server && ssl) {
if (session->is_session_resumed) {
const char *resumed = NULL;
if (ssl->session_ticket.data_len) {
resumed = "Session Ticket";
} else if (ssl->session_id.data_len) {
resumed = "Session ID";
}
if (resumed) {
ssl_debug_printf("%s Session resumption using %s\n", G_STRFUNC, resumed);
} else {
ssl_debug_printf("%s No Session resumption, missing packets?\n", G_STRFUNC);
}
} else {
ssl_debug_printf("%s Not using Session resumption\n", G_STRFUNC);
}
}
if (is_from_server && session->is_session_resumed)
expert_add_info(pinfo, ti, &hf->ei.resumed);
}
static gint
ssl_dissect_hash_alg_list(ssl_common_dissect_t *hf, tvbuff_t *tvb, proto_tree *tree,
packet_info* pinfo, guint32 offset, guint32 offset_end)
{
proto_tree *subtree, *alg_tree;
proto_item *ti;
guint sh_alg_length;
guint32 next_offset;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &sh_alg_length,
hf->hf.hs_sig_hash_alg_len, 2, G_MAXUINT16 - 1)) {
return offset_end;
}
offset += 2;
next_offset = offset + sh_alg_length;
ti = proto_tree_add_none_format(tree, hf->hf.hs_sig_hash_algs, tvb, offset, sh_alg_length,
"Signature Hash Algorithms (%u algorithm%s)",
sh_alg_length / 2, plurality(sh_alg_length / 2, "", "s"));
subtree = proto_item_add_subtree(ti, hf->ett.hs_sig_hash_algs);
while (offset + 2 <= next_offset) {
ti = proto_tree_add_item(subtree, hf->hf.hs_sig_hash_alg,
tvb, offset, 2, ENC_BIG_ENDIAN);
alg_tree = proto_item_add_subtree(ti, hf->ett.hs_sig_hash_alg);
proto_tree_add_item(alg_tree, hf->hf.hs_sig_hash_hash,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(alg_tree, hf->hf.hs_sig_hash_sig,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
}
if (!ssl_end_vector(hf, tvb, pinfo, subtree, offset, next_offset)) {
offset = next_offset;
}
return offset;
}
static guint32
tls_dissect_certificate_authorities(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end)
{
proto_item *ti;
proto_tree *subtree;
guint32 dnames_length, next_offset;
asn1_ctx_t asn1_ctx;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &dnames_length,
hf->hf.hs_dnames_len, 0, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
next_offset = offset + dnames_length;
if (dnames_length > 0) {
ti = proto_tree_add_none_format(tree,
hf->hf.hs_dnames,
tvb, offset, dnames_length,
"Distinguished Names (%d byte%s)",
dnames_length,
plurality(dnames_length, "", "s"));
subtree = proto_item_add_subtree(ti, hf->ett.dnames);
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
while (offset < next_offset) {
guint32 name_length;
if (!ssl_add_vector(hf, tvb, pinfo, subtree, offset, next_offset, &name_length,
hf->hf.hs_dname_len, 1, G_MAXUINT16)) {
return next_offset;
}
offset += 2;
dissect_x509if_DistinguishedName(FALSE, tvb, offset, &asn1_ctx,
subtree, hf->hf.hs_dname);
offset += name_length;
}
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_sig_hash_algs(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, packet_info* pinfo, guint32 offset, guint32 offset_end)
{
return ssl_dissect_hash_alg_list(hf, tvb, tree, pinfo, offset, offset_end);
}
static gint
ssl_dissect_hnd_hello_ext_alpn(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree,
guint32 offset, guint32 offset_end,
guint8 hnd_type, SslSession *session)
{
proto_tree *alpn_tree;
proto_item *ti;
guint32 next_offset, alpn_length, name_length;
guint8 *proto_name = NULL;
guint32 proto_name_length = 0;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &alpn_length,
hf->hf.hs_ext_alpn_len, 2, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
next_offset = offset + alpn_length;
ti = proto_tree_add_item(tree, hf->hf.hs_ext_alpn_list,
tvb, offset, alpn_length, ENC_NA);
alpn_tree = proto_item_add_subtree(ti, hf->ett.hs_ext_alpn);
while (offset < next_offset) {
if (!ssl_add_vector(hf, tvb, pinfo, alpn_tree, offset, next_offset, &name_length,
hf->hf.hs_ext_alpn_str_len, 1, G_MAXUINT8)) {
return next_offset;
}
offset++;
proto_tree_add_item(alpn_tree, hf->hf.hs_ext_alpn_str,
tvb, offset, name_length, ENC_ASCII|ENC_NA);
if (hnd_type == SSL_HND_SERVER_HELLO || hnd_type == SSL_HND_ENCRYPTED_EXTENSIONS) {
proto_name_length = name_length;
proto_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset,
proto_name_length, ENC_ASCII);
}
offset += name_length;
}
if (proto_name) {
for (size_t i = 0; i < G_N_ELEMENTS(ssl_alpn_protocols); i++) {
const ssl_alpn_protocol_t *alpn_proto = &ssl_alpn_protocols[i];
if ((alpn_proto->match_exact &&
proto_name_length == strlen(alpn_proto->proto_name) &&
!strcmp(proto_name, alpn_proto->proto_name)) ||
(!alpn_proto->match_exact && g_str_has_prefix(proto_name, alpn_proto->proto_name))) {
dissector_handle_t handle;
handle = ssl_find_appdata_dissector(alpn_proto->dissector_name);
ssl_debug_printf("%s: changing handle %p to %p (%s)", G_STRFUNC,
(void *)session->app_handle,
(void *)handle, alpn_proto->dissector_name);
if (handle)
session->app_handle = handle;
break;
}
}
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_npn(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree,
guint32 offset, guint32 offset_end)
{
guint32 npn_length;
proto_tree *npn_tree;
if (offset == offset_end) {
return offset;
}
npn_tree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset, hf->ett.hs_ext_npn, NULL, "Next Protocol Negotiation");
while (offset < offset_end) {
if (!ssl_add_vector(hf, tvb, pinfo, npn_tree, offset, offset_end, &npn_length,
hf->hf.hs_ext_npn_str_len, 1, G_MAXUINT8)) {
return offset_end;
}
offset++;
proto_tree_add_item(npn_tree, hf->hf.hs_ext_npn_str,
tvb, offset, npn_length, ENC_ASCII|ENC_NA);
offset += npn_length;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_reneg_info(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree,
guint32 offset, guint32 offset_end)
{
proto_tree *reneg_info_tree;
guint32 reneg_info_length;
reneg_info_tree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset, hf->ett.hs_ext_reneg_info, NULL, "Renegotiation Info extension");
if (!ssl_add_vector(hf, tvb, pinfo, reneg_info_tree, offset, offset_end, &reneg_info_length,
hf->hf.hs_ext_reneg_info_len, 0, 255)) {
return offset_end;
}
offset++;
if (reneg_info_length > 0) {
proto_tree_add_item(reneg_info_tree, hf->hf.hs_ext_reneg_info, tvb, offset, reneg_info_length, ENC_NA);
offset += reneg_info_length;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_key_share_entry(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end)
{
guint32 key_exchange_length, group;
proto_tree *ks_tree;
ks_tree = proto_tree_add_subtree(tree, tvb, offset, 4, hf->ett.hs_ext_key_share_ks, NULL, "Key Share Entry");
proto_tree_add_item_ret_uint(ks_tree, hf->hf.hs_ext_key_share_group, tvb, offset, 2, ENC_BIG_ENDIAN, &group);
offset += 2;
proto_item_append_text(ks_tree, ": Group: %s", val_to_str(group, ssl_extension_curves, "Unknown (%u)"));
if (!ssl_add_vector(hf, tvb, pinfo, ks_tree, offset, offset_end, &key_exchange_length,
hf->hf.hs_ext_key_share_key_exchange_length, 1, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
proto_item_set_len(ks_tree, 2 + 2 + key_exchange_length);
proto_item_append_text(ks_tree, ", Key Exchange length: %u", key_exchange_length);
proto_tree_add_item(ks_tree, hf->hf.hs_ext_key_share_key_exchange, tvb, offset, key_exchange_length, ENC_NA);
offset += key_exchange_length;
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_key_share(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
guint8 hnd_type)
{
proto_tree *key_share_tree;
guint32 next_offset;
guint32 client_shares_length;
if (offset_end <= offset) {
return offset;
}
key_share_tree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset, hf->ett.hs_ext_key_share, NULL, "Key Share extension");
switch(hnd_type){
case SSL_HND_CLIENT_HELLO:
if (!ssl_add_vector(hf, tvb, pinfo, key_share_tree, offset, offset_end, &client_shares_length,
hf->hf.hs_ext_key_share_client_length, 0, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
next_offset = offset + client_shares_length;
while (offset + 4 <= next_offset) {
offset = ssl_dissect_hnd_hello_ext_key_share_entry(hf, tvb, pinfo, key_share_tree, offset, next_offset);
}
if (!ssl_end_vector(hf, tvb, pinfo, key_share_tree, offset, next_offset)) {
return next_offset;
}
break;
case SSL_HND_SERVER_HELLO:
offset = ssl_dissect_hnd_hello_ext_key_share_entry(hf, tvb, pinfo, key_share_tree, offset, offset_end);
break;
case SSL_HND_HELLO_RETRY_REQUEST:
proto_tree_add_item(key_share_tree, hf->hf.hs_ext_key_share_selected_group, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
break;
default:
break;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_pre_shared_key(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
guint8 hnd_type)
{
proto_tree *psk_tree;
psk_tree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset, hf->ett.hs_ext_pre_shared_key, NULL, "Pre-Shared Key extension");
switch (hnd_type){
case SSL_HND_CLIENT_HELLO: {
guint32 identities_length, identities_end, binders_length;
if (!ssl_add_vector(hf, tvb, pinfo, psk_tree, offset, offset_end, &identities_length,
hf->hf.hs_ext_psk_identities_length, 7, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
identities_end = offset + identities_length;
while (offset < identities_end) {
guint32 identity_length;
proto_tree *identity_tree;
identity_tree = proto_tree_add_subtree(psk_tree, tvb, offset, 4, hf->ett.hs_ext_psk_identity, NULL, "PSK Identity (");
if (!ssl_add_vector(hf, tvb, pinfo, identity_tree, offset, identities_end, &identity_length,
hf->hf.hs_ext_psk_identity_identity_length, 1, G_MAXUINT16)) {
return identities_end;
}
offset += 2;
proto_item_append_text(identity_tree, "length: %u)", identity_length);
proto_tree_add_item(identity_tree, hf->hf.hs_ext_psk_identity_identity, tvb, offset, identity_length, ENC_BIG_ENDIAN);
offset += identity_length;
proto_tree_add_item(identity_tree, hf->hf.hs_ext_psk_identity_obfuscated_ticket_age, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_item_set_len(identity_tree, 2 + identity_length + 4);
}
if (!ssl_end_vector(hf, tvb, pinfo, psk_tree, offset, identities_end)) {
offset = identities_end;
}
if (!ssl_add_vector(hf, tvb, pinfo, psk_tree, offset, offset_end, &binders_length,
hf->hf.hs_ext_psk_binders_length, 33, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
proto_tree_add_item(psk_tree, hf->hf.hs_ext_psk_binders, tvb, offset, binders_length, ENC_NA);
offset += binders_length;
}
break;
case SSL_HND_SERVER_HELLO: {
proto_tree_add_item(psk_tree, hf->hf.hs_ext_psk_identity_selected, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
default:
break;
}
return offset;
}
static guint32
ssl_dissect_hnd_hello_ext_early_data(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint32 offset, guint32 offset_end _U_,
guint8 hnd_type, SslDecryptSession *ssl)
{
switch (hnd_type) {
case SSL_HND_CLIENT_HELLO:
if (ssl) {
ssl_debug_printf("%s found early_data extension\n", G_STRFUNC);
ssl->has_early_data = TRUE;
}
break;
case SSL_HND_NEWSESSION_TICKET:
proto_tree_add_item(tree, hf->hf.hs_ext_max_early_data_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
default:
break;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_supported_versions(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end)
{
guint32 versions_length, next_offset;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &versions_length,
hf->hf.hs_ext_supported_versions_len, 2, 254)) {
return offset_end;
}
offset++;
next_offset = offset + versions_length;
while (offset + 2 <= next_offset) {
proto_tree_add_item(tree, hf->hf.hs_ext_supported_versions, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (!ssl_end_vector(hf, tvb, pinfo, tree, offset, next_offset)) {
offset = next_offset;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_cookie(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree,
guint32 offset, guint32 offset_end)
{
guint32 cookie_length;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &cookie_length,
hf->hf.hs_ext_cookie_len, 1, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
proto_tree_add_item(tree, hf->hf.hs_ext_cookie, tvb, offset, cookie_length, ENC_NA);
offset += cookie_length;
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_psk_key_exchange_modes(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end)
{
guint32 ke_modes_length, next_offset;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &ke_modes_length,
hf->hf.hs_ext_psk_ke_modes_length, 1, 255)) {
return offset_end;
}
offset++;
next_offset = offset + ke_modes_length;
while (offset < next_offset) {
proto_tree_add_item(tree, hf->hf.hs_ext_psk_ke_mode, tvb, offset, 1, ENC_NA);
offset++;
}
return offset;
}
static guint32
ssl_dissect_hnd_hello_ext_certificate_authorities(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end)
{
return tls_dissect_certificate_authorities(hf, tvb, pinfo, tree, offset, offset_end);
}
static gint
ssl_dissect_hnd_hello_ext_oid_filters(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end)
{
proto_tree *subtree;
guint32 filters_length, oid_length, values_length, value_offset;
asn1_ctx_t asn1_ctx;
const char *oid, *name;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &filters_length,
hf->hf.hs_ext_psk_ke_modes_length, 0, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
offset_end = offset + filters_length;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
while (offset < offset_end) {
subtree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset,
hf->ett.hs_ext_oid_filter, NULL, "OID Filter");
if (!ssl_add_vector(hf, tvb, pinfo, subtree, offset, offset_end, &oid_length,
hf->hf.hs_ext_oid_filters_oid_length, 1, G_MAXUINT8)) {
return offset_end;
}
offset++;
dissect_ber_object_identifier_str(FALSE, &asn1_ctx, subtree, tvb, offset,
hf->hf.hs_ext_oid_filters_oid, &oid);
offset += oid_length;
name = oid_resolved_from_string(wmem_packet_scope(), oid);
proto_item_append_text(subtree, " (%s)", name ? name : oid);
if (!ssl_add_vector(hf, tvb, pinfo, subtree, offset, offset_end, &values_length,
hf->hf.hs_ext_oid_filters_values_length, 0, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
proto_item_set_len(subtree, 1 + oid_length + 2 + values_length);
if (values_length > 0) {
value_offset = offset;
value_offset = dissect_ber_identifier(pinfo, subtree, tvb, value_offset, NULL, NULL, NULL);
value_offset = dissect_ber_length(pinfo, subtree, tvb, value_offset, NULL, NULL);
call_ber_oid_callback(oid, tvb, value_offset, pinfo, subtree, NULL);
}
offset += values_length;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_server_name(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree,
guint32 offset, guint32 offset_end)
{
proto_tree *server_name_tree;
guint32 list_length, server_name_length, next_offset;
if (offset == offset_end) {
return offset;
}
server_name_tree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset, hf->ett.hs_ext_server_name, NULL, "Server Name Indication extension");
if (!ssl_add_vector(hf, tvb, pinfo, server_name_tree, offset, offset_end, &list_length,
hf->hf.hs_ext_server_name_list_len, 1, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
next_offset = offset + list_length;
while (offset < next_offset) {
proto_tree_add_item(server_name_tree, hf->hf.hs_ext_server_name_type,
tvb, offset, 1, ENC_NA);
offset++;
if (!ssl_add_vector(hf, tvb, pinfo, server_name_tree, offset, next_offset, &server_name_length,
hf->hf.hs_ext_server_name_len, 1, G_MAXUINT16)) {
return next_offset;
}
offset += 2;
proto_tree_add_item(server_name_tree, hf->hf.hs_ext_server_name,
tvb, offset, server_name_length, ENC_ASCII|ENC_NA);
offset += server_name_length;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_session_ticket(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 offset_end, guint8 hnd_type, SslDecryptSession *ssl)
{
guint ext_len = offset_end - offset;
if (hnd_type == SSL_HND_CLIENT_HELLO && ssl && ext_len != 0) {
tvb_ensure_bytes_exist(tvb, offset, ext_len);
ssl->session_ticket.data = (guchar*)wmem_realloc(wmem_file_scope(),
ssl->session_ticket.data, ext_len);
ssl->session_ticket.data_len = ext_len;
tvb_memcpy(tvb,ssl->session_ticket.data, offset, ext_len);
}
proto_tree_add_bytes_format(tree, hf->hf.hs_ext_data,
tvb, offset, ext_len, NULL,
"Data (%u byte%s)",
ext_len, plurality(ext_len, "", "s"));
return offset + ext_len;
}
static gint
ssl_dissect_hnd_hello_ext_cert_type(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 offset_end,
guint8 hnd_type, guint16 ext_type, SslSession *session)
{
guint8 cert_list_length;
guint8 cert_type;
proto_tree *cert_list_tree;
proto_item *ti;
switch(hnd_type){
case SSL_HND_CLIENT_HELLO:
cert_list_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf->hf.hs_ext_cert_types_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (offset_end - offset != (guint32)cert_list_length)
return offset;
ti = proto_tree_add_item(tree, hf->hf.hs_ext_cert_types, tvb, offset,
cert_list_length, cert_list_length);
proto_item_append_text(ti, " (%d)", cert_list_length);
cert_list_tree = proto_item_add_subtree(ti, hf->ett.hs_ext_cert_types);
while (cert_list_length > 0)
{
proto_tree_add_item(cert_list_tree, hf->hf.hs_ext_cert_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
cert_list_length--;
}
break;
case SSL_HND_SERVER_HELLO:
case SSL_HND_ENCRYPTED_EXTENSIONS:
case SSL_HND_CERTIFICATE:
cert_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf->hf.hs_ext_cert_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (ext_type == SSL_HND_HELLO_EXT_CERT_TYPE || ext_type == SSL_HND_HELLO_EXT_CLIENT_CERT_TYPE) {
session->client_cert_type = cert_type;
}
if (ext_type == SSL_HND_HELLO_EXT_CERT_TYPE || ext_type == SSL_HND_HELLO_EXT_SERVER_CERT_TYPE) {
session->server_cert_type = cert_type;
}
break;
default:
break;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_common(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset,
SslSession *session, SslDecryptSession *ssl,
gboolean from_server)
{
nstime_t gmt_unix_time;
guint8 sessid_length;
proto_tree *rnd_tree;
proto_tree *ti_rnd;
ssl_reset_session(session, ssl, !from_server);
if (ssl) {
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
ssl_debug_printf("%s found %s RANDOM -> state 0x%02X\n", G_STRFUNC,
from_server ? "SERVER" : "CLIENT", ssl->state);
}
ti_rnd = proto_tree_add_item(tree, hf->hf.hs_random, tvb, offset, 32, ENC_NA);
if (session->version != TLSV1DOT3_VERSION) {
rnd_tree = proto_item_add_subtree(ti_rnd, hf->ett.hs_random);
gmt_unix_time.secs = tvb_get_ntohl(tvb, offset);
gmt_unix_time.nsecs = 0;
proto_tree_add_time(rnd_tree, hf->hf.hs_random_time,
tvb, offset, 4, &gmt_unix_time);
offset += 4;
proto_tree_add_item(rnd_tree, hf->hf.hs_random_bytes,
tvb, offset, 28, ENC_NA);
offset += 28;
} else {
offset += 32;
}
if (from_server == 0 || session->version != TLSV1DOT3_VERSION) {
sessid_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf->hf.hs_session_id_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (ssl) {
if (from_server && sessid_length <= 32) {
tvb_memcpy(tvb, ssl->session_id.data, offset, sessid_length);
ssl->session_id.data_len = sessid_length;
}
}
if (sessid_length > 0) {
proto_tree_add_item(tree, hf->hf.hs_session_id,
tvb, offset, sessid_length, ENC_NA);
offset += sessid_length;
}
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_status_request(ssl_common_dissect_t *hf, tvbuff_t *tvb, proto_tree *tree,
guint32 offset, gboolean has_length)
{
guint cert_status_type;
cert_status_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf->hf.hs_ext_cert_status_type,
tvb, offset, 1, ENC_NA);
offset++;
if (has_length) {
proto_tree_add_item(tree, hf->hf.hs_ext_cert_status_request_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
switch (cert_status_type) {
case SSL_HND_CERT_STATUS_TYPE_OCSP:
case SSL_HND_CERT_STATUS_TYPE_OCSP_MULTI:
{
guint16 responder_id_list_len;
guint16 request_extensions_len;
proto_item *responder_id;
proto_item *request_extensions;
responder_id_list_len = tvb_get_ntohs(tvb, offset);
responder_id =
proto_tree_add_item(tree,
hf->hf.hs_ext_cert_status_responder_id_list_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (responder_id_list_len != 0) {
expert_add_info_format(NULL, responder_id,
&hf->ei.hs_ext_cert_status_undecoded,
"Responder ID list is not implemented, contact Wireshark"
" developers if you want this to be supported");
break;
}
request_extensions_len = tvb_get_ntohs(tvb, offset);
request_extensions =
proto_tree_add_item(tree,
hf->hf.hs_ext_cert_status_request_extensions_len, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
if (request_extensions_len != 0)
expert_add_info_format(NULL, request_extensions,
&hf->ei.hs_ext_cert_status_undecoded,
"Request Extensions are not implemented, contact"
" Wireshark developers if you want this to be supported");
break;
}
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_status_request_v2(ssl_common_dissect_t *hf, tvbuff_t *tvb, proto_tree *tree,
guint32 offset)
{
gint32 list_len;
list_len = tvb_get_ntohs(tvb, offset);
offset += 2;
while (list_len > 0) {
guint32 prev_offset = offset;
offset = ssl_dissect_hnd_hello_ext_status_request(hf, tvb, tree, offset, TRUE);
list_len -= (offset - prev_offset);
}
return offset;
}
static guint
ssl_dissect_hnd_hello_ext_supported_groups(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end)
{
guint32 groups_length, next_offset;
proto_tree *groups_tree;
proto_item *ti;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &groups_length,
hf->hf.hs_ext_supported_groups_len, 2, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
next_offset = offset + groups_length;
ti = proto_tree_add_none_format(tree,
hf->hf.hs_ext_supported_groups,
tvb, offset, groups_length,
"Supported Groups (%d group%s)",
groups_length / 2,
plurality(groups_length/2, "", "s"));
groups_tree = proto_item_add_subtree(ti, hf->ett.hs_ext_groups);
while (offset + 2 <= offset_end) {
proto_tree_add_item(groups_tree, hf->hf.hs_ext_supported_group, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (!ssl_end_vector(hf, tvb, pinfo, groups_tree, offset, next_offset)) {
offset = next_offset;
}
return offset;
}
static gint
ssl_dissect_hnd_hello_ext_ec_point_formats(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
guint8 ecpf_length;
proto_tree *ecpf_tree;
proto_item *ti;
ecpf_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf->hf.hs_ext_ec_point_formats_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_none_format(tree,
hf->hf.hs_ext_ec_point_formats,
tvb, offset, ecpf_length,
"Elliptic curves point formats (%d)",
ecpf_length);
ecpf_tree = proto_item_add_subtree(ti, hf->ett.hs_ext_curves_point_formats);
while (ecpf_length > 0)
{
proto_tree_add_item(ecpf_tree, hf->hf.hs_ext_ec_point_format, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
ecpf_length--;
}
return offset;
}
static guint32
tls_dissect_sct(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint32 offset, guint32 offset_end, guint16 version)
{
guint64 sct_timestamp_ms;
nstime_t sct_timestamp;
guint32 exts_len;
const gchar *log_name;
proto_tree_add_item(tree, hf->hf.sct_sct_version, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf->hf.sct_sct_logid, tvb, offset, 32, ENC_BIG_ENDIAN);
log_name = bytesval_to_str(tvb_get_ptr(tvb, offset, 32), 32, ct_logids, "Unknown Log");
proto_item_append_text(tree, " (%s)", log_name);
offset += 32;
sct_timestamp_ms = tvb_get_ntoh64(tvb, offset);
sct_timestamp.secs = (time_t)(sct_timestamp_ms / 1000);
sct_timestamp.nsecs = (int)((sct_timestamp_ms % 1000) * 1000000);
proto_tree_add_time(tree, hf->hf.sct_sct_timestamp, tvb, offset, 8, &sct_timestamp);
offset += 8;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &exts_len,
hf->hf.sct_sct_extensions_length, 0, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
if (exts_len > 0) {
proto_tree_add_item(tree, hf->hf.sct_sct_extensions, tvb, offset, exts_len, ENC_BIG_ENDIAN);
offset += exts_len;
}
offset = ssl_dissect_digitally_signed(hf, tvb, pinfo, tree, offset, offset_end, version,
hf->hf.sct_sct_signature_length,
hf->hf.sct_sct_signature);
return offset;
}
guint32
tls_dissect_sct_list(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint32 offset, guint32 offset_end, guint16 version)
{
guint32 list_length, sct_length, next_offset;
proto_tree *subtree;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &list_length,
hf->hf.sct_scts_length, 1, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
while (offset < offset_end) {
subtree = proto_tree_add_subtree(tree, tvb, offset, 2, hf->ett.sct, NULL, "Signed Certificate Timestamp");
if (!ssl_add_vector(hf, tvb, pinfo, subtree, offset, offset_end, &sct_length,
hf->hf.sct_sct_length, 1, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
next_offset = offset + sct_length;
proto_item_set_len(subtree, 2 + sct_length);
offset = tls_dissect_sct(hf, tvb, pinfo, subtree, offset, next_offset, version);
if (!ssl_end_vector(hf, tvb, pinfo, subtree, offset, next_offset)) {
offset = next_offset;
}
}
return offset;
}
gboolean
ssl_is_valid_content_type(guint8 type)
{
switch ((ContentType) type) {
case SSL_ID_CHG_CIPHER_SPEC:
case SSL_ID_ALERT:
case SSL_ID_HANDSHAKE:
case SSL_ID_APP_DATA:
case SSL_ID_HEARTBEAT:
return TRUE;
}
return FALSE;
}
gboolean
ssl_is_valid_handshake_type(guint8 hs_type, gboolean is_dtls)
{
switch ((HandshakeType) hs_type) {
case SSL_HND_HELLO_VERIFY_REQUEST:
return is_dtls;
case SSL_HND_HELLO_REQUEST:
case SSL_HND_CLIENT_HELLO:
case SSL_HND_SERVER_HELLO:
case SSL_HND_NEWSESSION_TICKET:
case SSL_HND_END_OF_EARLY_DATA:
case SSL_HND_HELLO_RETRY_REQUEST:
case SSL_HND_ENCRYPTED_EXTENSIONS:
case SSL_HND_CERTIFICATE:
case SSL_HND_SERVER_KEY_EXCHG:
case SSL_HND_CERT_REQUEST:
case SSL_HND_SVR_HELLO_DONE:
case SSL_HND_CERT_VERIFY:
case SSL_HND_CLIENT_KEY_EXCHG:
case SSL_HND_FINISHED:
case SSL_HND_CERT_URL:
case SSL_HND_CERT_STATUS:
case SSL_HND_SUPPLEMENTAL_DATA:
case SSL_HND_KEY_UPDATE:
case SSL_HND_ENCRYPTED_EXTS:
return TRUE;
}
return FALSE;
}
static gboolean
ssl_is_authoritative_version_message(guint8 content_type, guint8 handshake_type,
gboolean is_dtls)
{
return (content_type == SSL_ID_HANDSHAKE &&
ssl_is_valid_handshake_type(handshake_type, is_dtls) &&
handshake_type != SSL_HND_CLIENT_HELLO) ||
(content_type != SSL_ID_HANDSHAKE &&
ssl_is_valid_content_type(content_type));
}
void
ssl_try_set_version(SslSession *session, SslDecryptSession *ssl,
guint8 content_type, guint8 handshake_type,
gboolean is_dtls, guint16 version)
{
if (!ssl_is_authoritative_version_message(content_type, handshake_type,
is_dtls))
return;
switch (version) {
case SSLV3_VERSION:
case TLSV1_VERSION:
case TLSV1DOT1_VERSION:
case TLSV1DOT2_VERSION:
case TLSV1DOT3_VERSION:
if (is_dtls)
return;
break;
case DTLSV1DOT0_VERSION:
case DTLSV1DOT0_OPENSSL_VERSION:
case DTLSV1DOT2_VERSION:
if (!is_dtls)
return;
break;
default:
return;
}
session->version = version;
if (ssl) {
ssl->state |= SSL_VERSION;
ssl_debug_printf("%s found version 0x%04X -> state 0x%02X\n", G_STRFUNC, version, ssl->state);
}
}
void
ssl_check_record_length(ssl_common_dissect_t *hf, packet_info *pinfo,
guint record_length, proto_item *length_pi,
guint16 version, tvbuff_t *decrypted_tvb)
{
guint max_expansion;
if (version == TLSV1DOT3_VERSION) {
max_expansion = 256;
} else {
max_expansion = 2048;
}
if (record_length > TLS_MAX_RECORD_LENGTH + max_expansion) {
expert_add_info_format(pinfo, length_pi, &hf->ei.record_length_invalid,
"TLSCiphertext length MUST NOT exceed 2^14 + %u", max_expansion);
}
if (decrypted_tvb && tvb_captured_length(decrypted_tvb) > TLS_MAX_RECORD_LENGTH) {
expert_add_info_format(pinfo, length_pi, &hf->ei.record_length_invalid,
"TLSPlaintext length MUST NOT exceed 2^14");
}
}
static void
ssl_set_cipher(SslDecryptSession *ssl, guint16 cipher)
{
ssl->session.cipher = cipher;
if (!(ssl->cipher_suite = ssl_find_cipher(cipher))) {
ssl->state &= ~SSL_CIPHER;
ssl_debug_printf("%s can't find cipher suite 0x%04X\n", G_STRFUNC, cipher);
} else {
ssl->state |= SSL_CIPHER;
ssl_debug_printf("%s found CIPHER 0x%04X %s -> state 0x%02X\n", G_STRFUNC, cipher,
val_to_str_ext_const(cipher, &ssl_31_ciphersuite_ext, "unknown"),
ssl->state);
}
}
void
ssl_dissect_hnd_cli_hello(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info *pinfo, proto_tree *tree, guint32 offset,
guint32 offset_end, SslSession *session,
SslDecryptSession *ssl, dtls_hfs_t *dtls_hfs)
{
proto_item *ti;
proto_tree *cs_tree;
guint32 cipher_suite_length;
guint32 compression_methods_length;
guint8 compression_method;
guint32 next_offset;
proto_tree_add_item(tree, hf->hf.hs_client_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = ssl_dissect_hnd_hello_common(hf, tvb, tree, offset, session, ssl, FALSE);
if (dtls_hfs != NULL) {
guint32 cookie_length;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &cookie_length,
dtls_hfs->hf_dtls_handshake_cookie_len, 0, 32)) {
return;
}
offset++;
if (cookie_length > 0) {
proto_tree_add_item(tree, dtls_hfs->hf_dtls_handshake_cookie,
tvb, offset, cookie_length, ENC_NA);
offset += cookie_length;
}
}
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &cipher_suite_length,
hf->hf.hs_cipher_suites_len, 2, G_MAXUINT16)) {
return;
}
offset += 2;
next_offset = offset + cipher_suite_length;
if (ssl && cipher_suite_length == 2) {
ssl_set_cipher(ssl, tvb_get_ntohs(tvb, offset));
}
ti = proto_tree_add_none_format(tree,
hf->hf.hs_cipher_suites,
tvb, offset, cipher_suite_length,
"Cipher Suites (%d suite%s)",
cipher_suite_length / 2,
plurality(cipher_suite_length/2, "", "s"));
cs_tree = proto_item_add_subtree(ti, hf->ett.cipher_suites);
while (offset + 2 <= next_offset) {
proto_tree_add_item(cs_tree, hf->hf.hs_cipher_suite, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (!ssl_end_vector(hf, tvb, pinfo, cs_tree, offset, next_offset)) {
offset = next_offset;
}
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &compression_methods_length,
hf->hf.hs_comp_methods_len, 1, G_MAXUINT8)) {
return;
}
offset++;
next_offset = offset + compression_methods_length;
ti = proto_tree_add_none_format(tree,
hf->hf.hs_comp_methods,
tvb, offset, compression_methods_length,
"Compression Methods (%u method%s)",
compression_methods_length,
plurality(compression_methods_length,
"", "s"));
cs_tree = proto_item_add_subtree(ti, hf->ett.comp_methods);
while (offset < next_offset) {
compression_method = tvb_get_guint8(tvb, offset);
if (compression_method < 64)
proto_tree_add_uint(cs_tree, hf->hf.hs_comp_method,
tvb, offset, 1, compression_method);
else if (compression_method > 63 && compression_method < 193)
proto_tree_add_uint_format_value(cs_tree, hf->hf.hs_comp_method, tvb, offset, 1,
compression_method, "Reserved - to be assigned by IANA (%u)",
compression_method);
else
proto_tree_add_uint_format_value(cs_tree, hf->hf.hs_comp_method, tvb, offset, 1,
compression_method, "Private use range (%u)",
compression_method);
offset++;
}
if (offset < offset_end) {
ssl_dissect_hnd_extension(hf, tvb, tree, pinfo, offset,
offset_end, SSL_HND_CLIENT_HELLO,
session, ssl, dtls_hfs != NULL);
}
}
void
ssl_dissect_hnd_srv_hello(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info* pinfo, proto_tree *tree, guint32 offset, guint32 offset_end,
SslSession *session, SslDecryptSession *ssl,
gboolean is_dtls)
{
guint16 server_version;
server_version = tvb_get_ntohs(tvb, offset);
if((server_version & 0xFF00) == 0x7f00) {
session->tls13_draft_version = server_version & 0xff;
server_version = TLSV1DOT3_VERSION;
} else {
session->tls13_draft_version = 0;
}
ssl_try_set_version(session, ssl, SSL_ID_HANDSHAKE, SSL_HND_SERVER_HELLO,
is_dtls, server_version);
col_set_str(pinfo->cinfo, COL_PROTOCOL,
val_to_str_const(server_version, ssl_version_short_names, "SSL"));
session->is_session_resumed = TRUE;
proto_tree_add_item(tree, hf->hf.hs_server_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = ssl_dissect_hnd_hello_common(hf, tvb, tree, offset, session, ssl, TRUE);
if (ssl) {
ssl_set_cipher(ssl, tvb_get_ntohs(tvb, offset));
}
proto_tree_add_item(tree, hf->hf.hs_cipher_suite,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (session->version != TLSV1DOT3_VERSION) {
if (ssl) {
ssl->session.compression = tvb_get_guint8(tvb, offset);
}
proto_tree_add_item(tree, hf->hf.hs_comp_method,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
if (offset < offset_end) {
ssl_dissect_hnd_extension(hf, tvb, tree, pinfo, offset,
offset_end, SSL_HND_SERVER_HELLO,
session, ssl, is_dtls);
}
}
void
ssl_dissect_hnd_new_ses_ticket(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
SslSession *session, SslDecryptSession *ssl,
gboolean is_dtls, GHashTable *session_hash)
{
proto_tree *subtree;
guint32 ticket_len;
gboolean is_tls13 = session->version == TLSV1DOT3_VERSION;
guchar draft_version = session->tls13_draft_version;
subtree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset,
hf->ett.session_ticket, NULL,
"TLS Session Ticket");
proto_tree_add_item(subtree, hf->hf.hs_session_ticket_lifetime_hint,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (is_tls13) {
proto_tree_add_item(subtree, hf->hf.hs_session_ticket_age_add,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (draft_version == 0 || draft_version >= 21) {
guint32 ticket_nonce_len;
if (!ssl_add_vector(hf, tvb, pinfo, subtree, offset, offset_end, &ticket_nonce_len,
hf->hf.hs_session_ticket_nonce_len, 1, 255)) {
return;
}
offset++;
proto_tree_add_item(subtree, hf->hf.hs_session_ticket_nonce, tvb, offset, ticket_nonce_len, ENC_NA);
offset += ticket_nonce_len;
}
}
if (!ssl_add_vector(hf, tvb, pinfo, subtree, offset, offset_end, &ticket_len,
hf->hf.hs_session_ticket_len, is_tls13 ? 1 : 0, G_MAXUINT16)) {
return;
}
offset += 2;
proto_tree_add_item(subtree, hf->hf.hs_session_ticket,
tvb, offset, ticket_len, ENC_NA);
if (ssl && !is_tls13) {
tvb_ensure_bytes_exist(tvb, offset, ticket_len);
ssl->session_ticket.data = (guchar*)wmem_realloc(wmem_file_scope(),
ssl->session_ticket.data, ticket_len);
ssl->session_ticket.data_len = ticket_len;
tvb_memcpy(tvb, ssl->session_ticket.data, offset, ticket_len);
ssl_save_master_key("Session Ticket", session_hash,
&ssl->session_ticket, &ssl->master_secret);
ssl->state |= SSL_NEW_SESSION_TICKET;
}
offset += ticket_len;
if (is_tls13) {
ssl_dissect_hnd_extension(hf, tvb, subtree, pinfo, offset,
offset_end, SSL_HND_NEWSESSION_TICKET,
session, ssl, is_dtls);
}
}
void
ssl_dissect_hnd_hello_retry_request(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info* pinfo, proto_tree *tree, guint32 offset, guint32 offset_end,
SslSession *session, SslDecryptSession *ssl,
gboolean is_dtls)
{
proto_tree_add_item(tree, hf->hf.hs_server_version, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf->hf.hs_cipher_suite,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ssl_dissect_hnd_extension(hf, tvb, tree, pinfo, offset,
offset_end, SSL_HND_HELLO_RETRY_REQUEST,
session, ssl, is_dtls);
}
void
ssl_dissect_hnd_encrypted_extensions(ssl_common_dissect_t *hf, tvbuff_t *tvb,
packet_info* pinfo, proto_tree *tree, guint32 offset, guint32 offset_end,
SslSession *session, SslDecryptSession *ssl,
gboolean is_dtls)
{
ssl_dissect_hnd_extension(hf, tvb, tree, pinfo, offset,
offset_end, SSL_HND_ENCRYPTED_EXTENSIONS,
session, ssl, is_dtls);
}
void
ssl_dissect_hnd_cert(ssl_common_dissect_t *hf, tvbuff_t *tvb, proto_tree *tree,
guint32 offset, guint32 offset_end, packet_info *pinfo,
SslSession *session, SslDecryptSession *ssl _U_,
GHashTable *key_hash _U_, gboolean is_from_server, gboolean is_dtls)
{
enum { CERT_X509, CERT_RPK } cert_type;
asn1_ctx_t asn1_ctx;
#if defined(HAVE_LIBGNUTLS)
gnutls_datum_t subjectPublicKeyInfo = { NULL, 0 };
#endif
guint32 next_offset, certificate_list_length, cert_length;
proto_tree *subtree = tree;
guint certificate_index = 0;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if ((is_from_server && session->server_cert_type == SSL_HND_CERT_TYPE_RAW_PUBLIC_KEY) ||
(!is_from_server && session->client_cert_type == SSL_HND_CERT_TYPE_RAW_PUBLIC_KEY)) {
cert_type = CERT_RPK;
} else {
cert_type = CERT_X509;
}
#if defined(HAVE_LIBGNUTLS)
if (ssl)
asn1_ctx.private_data = &subjectPublicKeyInfo;
#endif
if (session->version == TLSV1DOT3_VERSION) {
guint32 context_length;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &context_length,
hf->hf.hs_certificate_request_context_length, 0, G_MAXUINT8)) {
return;
}
offset++;
if (context_length > 0) {
proto_tree_add_item(tree, hf->hf.hs_certificate_request_context,
tvb, offset, context_length, ENC_NA);
offset += context_length;
}
}
if (session->version != TLSV1DOT3_VERSION && cert_type == CERT_RPK) {
certificate_list_length = offset_end - offset;
next_offset = offset_end;
} else {
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &certificate_list_length,
hf->hf.hs_certificates_len, 0, G_MAXUINT24)) {
return;
}
offset += 3;
next_offset = offset + certificate_list_length;
}
if (certificate_list_length > 0 && cert_type == CERT_X509) {
proto_item *ti;
ti = proto_tree_add_none_format(tree,
hf->hf.hs_certificates,
tvb, offset, certificate_list_length,
"Certificates (%u bytes)",
certificate_list_length);
subtree = proto_item_add_subtree(ti, hf->ett.certificates);
}
while (offset < next_offset) {
switch (cert_type) {
case CERT_RPK:
if (!ssl_add_vector(hf, tvb, pinfo, subtree, offset, next_offset, &cert_length,
hf->hf.hs_certificate_len, 1, G_MAXUINT24)) {
return;
}
offset += 3;
dissect_x509af_SubjectPublicKeyInfo(FALSE, tvb, offset, &asn1_ctx, subtree, hf->hf.hs_certificate);
offset += cert_length;
break;
case CERT_X509:
if (!ssl_add_vector(hf, tvb, pinfo, subtree, offset, next_offset, &cert_length,
hf->hf.hs_certificate_len, 1, G_MAXUINT24)) {
return;
}
offset += 3;
dissect_x509af_Certificate(FALSE, tvb, offset, &asn1_ctx, subtree, hf->hf.hs_certificate);
#if defined(HAVE_LIBGNUTLS)
if (is_from_server && ssl && certificate_index == 0) {
ssl_find_private_key_by_pubkey(ssl, key_hash, &subjectPublicKeyInfo);
asn1_ctx.private_data = NULL;
}
#endif
offset += cert_length;
break;
}
if (session->version == TLSV1DOT3_VERSION) {
offset = ssl_dissect_hnd_extension(hf, tvb, subtree, pinfo, offset,
next_offset, SSL_HND_CERTIFICATE,
session, ssl, is_dtls);
}
certificate_index++;
}
}
void
ssl_dissect_hnd_cert_req(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
SslSession *session, gboolean is_dtls)
{
proto_item *ti;
proto_tree *subtree;
guint32 next_offset;
asn1_ctx_t asn1_ctx;
if (!tree)
return;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (session->version == TLSV1DOT3_VERSION) {
guint32 context_length;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &context_length,
hf->hf.hs_certificate_request_context_length, 0, G_MAXUINT8)) {
return;
}
offset++;
if (context_length > 0) {
proto_tree_add_item(tree, hf->hf.hs_certificate_request_context,
tvb, offset, context_length, ENC_NA);
offset += context_length;
}
} else {
guint32 cert_types_count;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &cert_types_count,
hf->hf.hs_cert_types_count, 1, G_MAXUINT8)) {
return;
}
offset++;
next_offset = offset + cert_types_count;
ti = proto_tree_add_none_format(tree,
hf->hf.hs_cert_types,
tvb, offset, cert_types_count,
"Certificate types (%u type%s)",
cert_types_count,
plurality(cert_types_count, "", "s"));
subtree = proto_item_add_subtree(ti, hf->ett.cert_types);
while (offset < next_offset) {
proto_tree_add_item(subtree, hf->hf.hs_cert_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
}
switch (session->version) {
case TLSV1DOT2_VERSION:
case DTLSV1DOT2_VERSION:
offset = ssl_dissect_hash_alg_list(hf, tvb, tree, pinfo, offset, offset_end);
break;
default:
break;
}
if (session->version == TLSV1DOT3_VERSION) {
ssl_dissect_hnd_extension(hf, tvb, tree, pinfo, offset,
offset_end, SSL_HND_CERT_REQUEST,
session, NULL, is_dtls);
} else {
tls_dissect_certificate_authorities(hf, tvb, pinfo, tree, offset, offset_end);
}
}
void
ssl_dissect_hnd_cli_cert_verify(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end, guint16 version)
{
ssl_dissect_digitally_signed(hf, tvb, pinfo, tree, offset, offset_end, version,
hf->hf.hs_client_cert_vrfy_sig_len,
hf->hf.hs_client_cert_vrfy_sig);
}
void
ssl_dissect_hnd_finished(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 offset_end,
const SslSession *session, ssl_hfs_t *ssl_hfs)
{
if (!tree)
return;
if (session->version == SSLV3_VERSION) {
if (ssl_hfs != NULL) {
proto_tree_add_item(tree, ssl_hfs->hs_md5_hash,
tvb, offset, 16, ENC_NA);
proto_tree_add_item(tree, ssl_hfs->hs_sha_hash,
tvb, offset + 16, 20, ENC_NA);
}
} else {
proto_tree_add_item(tree, hf->hf.hs_finished,
tvb, offset, offset_end - offset, ENC_NA);
}
}
void
ssl_dissect_hnd_cert_url(ssl_common_dissect_t *hf, tvbuff_t *tvb, proto_tree *tree, guint32 offset)
{
guint16 url_hash_len;
proto_tree_add_item(tree, hf->hf.hs_ext_cert_url_type,
tvb, offset, 1, ENC_NA);
offset++;
url_hash_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf->hf.hs_ext_cert_url_url_hash_list_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (url_hash_len-- > 0) {
proto_item *urlhash_item;
proto_tree *urlhash_tree;
guint16 url_len;
urlhash_item = proto_tree_add_item(tree, hf->hf.hs_ext_cert_url_item,
tvb, offset, -1, ENC_NA);
urlhash_tree = proto_item_add_subtree(urlhash_item, hf->ett.urlhash);
url_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(urlhash_tree, hf->hf.hs_ext_cert_url_url_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(urlhash_tree, hf->hf.hs_ext_cert_url_url,
tvb, offset, url_len, ENC_ASCII|ENC_NA);
offset += url_len;
proto_tree_add_item(urlhash_tree, hf->hf.hs_ext_cert_url_padding,
tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(urlhash_tree, hf->hf.hs_ext_cert_url_sha1,
tvb, offset, 20, ENC_NA);
offset += 20;
}
}
static gint
ssl_dissect_hnd_extension(ssl_common_dissect_t *hf, tvbuff_t *tvb, proto_tree *tree,
packet_info* pinfo, guint32 offset, guint32 offset_end, guint8 hnd_type,
SslSession *session, SslDecryptSession *ssl,
gboolean is_dtls)
{
guint32 exts_len;
guint16 ext_type;
guint32 ext_len;
guint32 next_offset;
proto_tree *ext_tree;
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &exts_len,
hf->hf.hs_exts_len, 0, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
offset_end = offset + exts_len;
while (offset_end - offset >= 4)
{
ext_type = tvb_get_ntohs(tvb, offset);
ext_len = tvb_get_ntohs(tvb, offset + 2);
ext_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4 + ext_len, hf->ett.hs_ext, NULL,
"Extension: %s (len=%u)", val_to_str(ext_type,
tls_hello_extension_types,
"Unknown type %u"), ext_len);
proto_tree_add_uint(ext_tree, hf->hf.hs_ext_type,
tvb, offset, 2, ext_type);
offset += 2;
if (!ssl_add_vector(hf, tvb, pinfo, ext_tree, offset, offset_end, &ext_len,
hf->hf.hs_ext_len, 0, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
next_offset = offset + ext_len;
switch (ext_type) {
case SSL_HND_HELLO_EXT_SERVER_NAME:
offset = ssl_dissect_hnd_hello_ext_server_name(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_STATUS_REQUEST:
if (hnd_type == SSL_HND_CLIENT_HELLO)
offset = ssl_dissect_hnd_hello_ext_status_request(hf, tvb, ext_tree, offset, FALSE);
break;
case SSL_HND_HELLO_EXT_CERT_TYPE:
offset = ssl_dissect_hnd_hello_ext_cert_type(hf, tvb, ext_tree,
offset, next_offset,
hnd_type, ext_type,
session);
break;
case SSL_HND_HELLO_EXT_SUPPORTED_GROUPS:
offset = ssl_dissect_hnd_hello_ext_supported_groups(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_EC_POINT_FORMATS:
offset = ssl_dissect_hnd_hello_ext_ec_point_formats(hf, tvb, ext_tree, offset);
break;
case SSL_HND_HELLO_EXT_SIGNATURE_ALGORITHMS:
offset = ssl_dissect_hnd_hello_ext_sig_hash_algs(hf, tvb, ext_tree, pinfo, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_USE_SRTP:
if (is_dtls) {
offset = dtls_dissect_hnd_hello_ext_use_srtp(tvb, ext_tree, offset, next_offset);
} else {
}
break;
case SSL_HND_HELLO_EXT_HEARTBEAT:
proto_tree_add_item(ext_tree, hf->hf.hs_ext_heartbeat_mode,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case SSL_HND_HELLO_EXT_ALPN:
offset = ssl_dissect_hnd_hello_ext_alpn(hf, tvb, pinfo, ext_tree, offset, next_offset, hnd_type, session);
break;
case SSL_HND_HELLO_EXT_STATUS_REQUEST_V2:
if (hnd_type == SSL_HND_CLIENT_HELLO)
offset = ssl_dissect_hnd_hello_ext_status_request_v2(hf, tvb, ext_tree, offset);
break;
case SSL_HND_HELLO_EXT_SIGNED_CERTIFICATE_TIMESTAMP:
if (hnd_type == SSL_HND_SERVER_HELLO || hnd_type == SSL_HND_ENCRYPTED_EXTENSIONS)
offset = tls_dissect_sct_list(hf, tvb, pinfo, ext_tree, offset, next_offset, session->version);
break;
case SSL_HND_HELLO_EXT_CLIENT_CERT_TYPE:
case SSL_HND_HELLO_EXT_SERVER_CERT_TYPE:
offset = ssl_dissect_hnd_hello_ext_cert_type(hf, tvb, ext_tree,
offset, next_offset,
hnd_type, ext_type,
session);
break;
case SSL_HND_HELLO_EXT_PADDING:
proto_tree_add_item(ext_tree, hf->hf.hs_ext_padding_data, tvb, offset, ext_len, ENC_NA);
offset += ext_len;
break;
case SSL_HND_HELLO_EXT_ENCRYPT_THEN_MAC:
if (ssl && hnd_type == SSL_HND_SERVER_HELLO) {
ssl_debug_printf("%s enabling Encrypt-then-MAC\n", G_STRFUNC);
ssl->state |= SSL_ENCRYPT_THEN_MAC;
}
break;
case SSL_HND_HELLO_EXT_EXTENDED_MASTER_SECRET:
if (ssl) {
switch (hnd_type) {
case SSL_HND_CLIENT_HELLO:
ssl->state |= SSL_CLIENT_EXTENDED_MASTER_SECRET;
break;
case SSL_HND_SERVER_HELLO:
ssl->state |= SSL_SERVER_EXTENDED_MASTER_SECRET;
break;
default:
break;
}
}
break;
case SSL_HND_HELLO_EXT_SESSION_TICKET_TLS:
offset = ssl_dissect_hnd_hello_ext_session_ticket(hf, tvb, ext_tree, offset, next_offset, hnd_type, ssl);
break;
case SSL_HND_HELLO_EXT_KEY_SHARE:
offset = ssl_dissect_hnd_hello_ext_key_share(hf, tvb, pinfo, ext_tree, offset, next_offset, hnd_type);
break;
case SSL_HND_HELLO_EXT_PRE_SHARED_KEY:
offset = ssl_dissect_hnd_hello_ext_pre_shared_key(hf, tvb, pinfo, ext_tree, offset, next_offset, hnd_type);
break;
case SSL_HND_HELLO_EXT_EARLY_DATA:
offset = ssl_dissect_hnd_hello_ext_early_data(hf, tvb, pinfo, ext_tree, offset, next_offset, hnd_type, ssl);
break;
case SSL_HND_HELLO_EXT_SUPPORTED_VERSIONS:
offset = ssl_dissect_hnd_hello_ext_supported_versions(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_COOKIE:
offset = ssl_dissect_hnd_hello_ext_cookie(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_PSK_KEY_EXCHANGE_MODES:
offset = ssl_dissect_hnd_hello_ext_psk_key_exchange_modes(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_CERTIFICATE_AUTHORITIES:
offset = ssl_dissect_hnd_hello_ext_certificate_authorities(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_OID_FILTERS:
offset = ssl_dissect_hnd_hello_ext_oid_filters(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_POST_HANDSHAKE_AUTH:
break;
case SSL_HND_HELLO_EXT_NPN:
offset = ssl_dissect_hnd_hello_ext_npn(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_RENEGOTIATION_INFO:
offset = ssl_dissect_hnd_hello_ext_reneg_info(hf, tvb, pinfo, ext_tree, offset, next_offset);
break;
case SSL_HND_HELLO_EXT_DRAFT_VERSION_TLS13:
proto_tree_add_item(ext_tree, hf->hf.hs_ext_draft_version_tls13,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
default:
proto_tree_add_item(ext_tree, hf->hf.hs_ext_data,
tvb, offset, ext_len, ENC_NA);
offset += ext_len;
break;
}
if (!ssl_end_vector(hf, tvb, pinfo, ext_tree, offset, next_offset)) {
offset = next_offset;
}
}
if (!ssl_end_vector(hf, tvb, pinfo, tree, offset, offset_end)) {
offset = offset_end;
}
return offset;
}
static void
dissect_ssl3_hnd_cli_keyex_ecdh(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset,
guint32 length)
{
gint point_len;
proto_tree *ssl_ecdh_tree;
ssl_ecdh_tree = proto_tree_add_subtree(tree, tvb, offset, length,
hf->ett.keyex_params, NULL, "EC Diffie-Hellman Client Params");
point_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ssl_ecdh_tree, hf->hf.hs_client_keyex_point_len, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_ecdh_tree, hf->hf.hs_client_keyex_point, tvb,
offset + 1, point_len, ENC_NA);
}
static void
dissect_ssl3_hnd_cli_keyex_dh(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 length)
{
gint yc_len;
proto_tree *ssl_dh_tree;
ssl_dh_tree = proto_tree_add_subtree(tree, tvb, offset, length,
hf->ett.keyex_params, NULL, "Diffie-Hellman Client Params");
yc_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_dh_tree, hf->hf.hs_client_keyex_yc_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_dh_tree, hf->hf.hs_client_keyex_yc, tvb,
offset + 2, yc_len, ENC_NA);
}
static void
dissect_ssl3_hnd_cli_keyex_rsa(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset,
guint32 length, const SslSession *session)
{
gint epms_len;
proto_tree *ssl_rsa_tree;
ssl_rsa_tree = proto_tree_add_subtree(tree, tvb, offset, length,
hf->ett.keyex_params, NULL, "RSA Encrypted PreMaster Secret");
switch (session->version) {
case SSLV2_VERSION:
case SSLV3_VERSION:
case DTLSV1DOT0_OPENSSL_VERSION:
epms_len = length;
break;
default:
epms_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_rsa_tree, hf->hf.hs_client_keyex_epms_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
}
proto_tree_add_item(ssl_rsa_tree, hf->hf.hs_client_keyex_epms, tvb,
offset, epms_len, ENC_NA);
}
static void
dissect_ssl3_hnd_cli_keyex_psk(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 length)
{
guint identity_len;
proto_tree *ssl_psk_tree;
ssl_psk_tree = proto_tree_add_subtree(tree, tvb, offset, length,
hf->ett.keyex_params, NULL, "PSK Client Params");
identity_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_psk_tree, hf->hf.hs_client_keyex_identity_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_psk_tree, hf->hf.hs_client_keyex_identity, tvb,
offset + 2, identity_len, ENC_NA);
}
static void
dissect_ssl3_hnd_cli_keyex_rsa_psk(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset,
guint32 length)
{
gint identity_len, epms_len;
proto_tree *ssl_psk_tree;
ssl_psk_tree = proto_tree_add_subtree(tree, tvb, offset, length,
hf->ett.keyex_params, NULL, "RSA PSK Client Params");
identity_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_psk_tree, hf->hf.hs_client_keyex_identity_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_psk_tree, hf->hf.hs_client_keyex_identity,
tvb, offset + 2, identity_len, ENC_NA);
offset += 2 + identity_len;
epms_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_psk_tree, hf->hf.hs_client_keyex_epms_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_psk_tree, hf->hf.hs_client_keyex_epms, tvb,
offset + 2, epms_len, ENC_NA);
}
static guint32
ssl_dissect_digitally_signed(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
guint16 version, gint hf_sig_len, gint hf_sig)
{
guint32 sig_len;
proto_item *ti_algo;
proto_tree *ssl_algo_tree;
switch (version) {
case TLSV1DOT2_VERSION:
case DTLSV1DOT2_VERSION:
case TLSV1DOT3_VERSION:
ti_algo = proto_tree_add_item(tree, hf->hf.hs_sig_hash_alg, tvb,
offset, 2, ENC_BIG_ENDIAN);
ssl_algo_tree = proto_item_add_subtree(ti_algo, hf->ett.hs_sig_hash_alg);
proto_tree_add_item(ssl_algo_tree, hf->hf.hs_sig_hash_hash, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_algo_tree, hf->hf.hs_sig_hash_sig, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
offset += 2;
break;
default:
break;
}
if (!ssl_add_vector(hf, tvb, pinfo, tree, offset, offset_end, &sig_len,
hf_sig_len, 0, G_MAXUINT16)) {
return offset_end;
}
offset += 2;
proto_tree_add_item(tree, hf_sig, tvb, offset, sig_len, ENC_NA);
offset += sig_len;
return offset;
}
static void
dissect_ssl3_hnd_srv_keyex_sig(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
guint16 version)
{
ssl_dissect_digitally_signed(hf, tvb, pinfo, tree, offset, offset_end, version,
hf->hf.hs_server_keyex_sig_len,
hf->hf.hs_server_keyex_sig);
}
static void
dissect_ssl3_hnd_srv_keyex_ecdh(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
guint16 version, gboolean anon)
{
gint curve_type;
gint point_len;
proto_tree *ssl_ecdh_tree;
ssl_ecdh_tree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset,
hf->ett.keyex_params, NULL, "EC Diffie-Hellman Server Params");
curve_type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ssl_ecdh_tree, hf->hf.hs_server_keyex_curve_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
if (curve_type != 3)
return;
proto_tree_add_item(ssl_ecdh_tree, hf->hf.hs_server_keyex_named_curve, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
point_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ssl_ecdh_tree, hf->hf.hs_server_keyex_point_len, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_ecdh_tree, hf->hf.hs_server_keyex_point, tvb,
offset + 1, point_len, ENC_NA);
offset += 1 + point_len;
if (!anon) {
dissect_ssl3_hnd_srv_keyex_sig(hf, tvb, pinfo, ssl_ecdh_tree, offset, offset_end, version);
}
}
static void
dissect_ssl3_hnd_srv_keyex_dhe(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
guint16 version, gboolean anon)
{
gint p_len, g_len, ys_len;
proto_tree *ssl_dh_tree;
ssl_dh_tree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset,
hf->ett.keyex_params, NULL, "Diffie-Hellman Server Params");
p_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_dh_tree, hf->hf.hs_server_keyex_p_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_dh_tree, hf->hf.hs_server_keyex_p, tvb,
offset + 2, p_len, ENC_NA);
offset += 2 + p_len;
g_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_dh_tree, hf->hf.hs_server_keyex_g_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_dh_tree, hf->hf.hs_server_keyex_g, tvb,
offset + 2, g_len, ENC_NA);
offset += 2 + g_len;
ys_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(ssl_dh_tree, hf->hf.hs_server_keyex_ys_len, tvb,
offset, 2, ys_len);
proto_tree_add_item(ssl_dh_tree, hf->hf.hs_server_keyex_ys, tvb,
offset + 2, ys_len, ENC_NA);
offset += 2 + ys_len;
if (!anon) {
dissect_ssl3_hnd_srv_keyex_sig(hf, tvb, pinfo, ssl_dh_tree, offset, offset_end, version);
}
}
static void
dissect_ssl3_hnd_srv_keyex_rsa(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
guint16 version)
{
gint modulus_len, exponent_len;
proto_tree *ssl_rsa_tree;
ssl_rsa_tree = proto_tree_add_subtree(tree, tvb, offset, offset_end - offset,
hf->ett.keyex_params, NULL, "RSA-EXPORT Server Params");
modulus_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_rsa_tree, hf->hf.hs_server_keyex_modulus_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_rsa_tree, hf->hf.hs_server_keyex_modulus, tvb,
offset + 2, modulus_len, ENC_NA);
offset += 2 + modulus_len;
exponent_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ssl_rsa_tree, hf->hf.hs_server_keyex_exponent_len,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_rsa_tree, hf->hf.hs_server_keyex_exponent,
tvb, offset + 2, exponent_len, ENC_NA);
offset += 2 + exponent_len;
dissect_ssl3_hnd_srv_keyex_sig(hf, tvb, pinfo, ssl_rsa_tree, offset, offset_end, version);
}
static void
dissect_ssl3_hnd_srv_keyex_psk(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 length)
{
guint hint_len;
proto_tree *ssl_psk_tree;
hint_len = tvb_get_ntohs(tvb, offset);
if ((2 + hint_len) != length) {
return;
}
ssl_psk_tree = proto_tree_add_subtree(tree, tvb, offset, length,
hf->ett.keyex_params, NULL, "PSK Server Params");
proto_tree_add_item(ssl_psk_tree, hf->hf.hs_server_keyex_hint_len, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ssl_psk_tree, hf->hf.hs_server_keyex_hint, tvb,
offset + 2, hint_len, ENC_NA);
}
void
ssl_dissect_hnd_cli_keyex(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset, guint32 length,
const SslSession *session)
{
switch (ssl_get_keyex_alg(session->cipher)) {
case KEX_DH_ANON:
case KEX_DH_DSS:
case KEX_DH_RSA:
case KEX_DHE_DSS:
case KEX_DHE_RSA:
dissect_ssl3_hnd_cli_keyex_dh(hf, tvb, tree, offset, length);
break;
case KEX_DHE_PSK:
break;
case KEX_ECDH_ANON:
case KEX_ECDH_ECDSA:
case KEX_ECDH_RSA:
case KEX_ECDHE_ECDSA:
case KEX_ECDHE_RSA:
dissect_ssl3_hnd_cli_keyex_ecdh(hf, tvb, tree, offset, length);
break;
case KEX_ECDHE_PSK:
break;
case KEX_KRB5:
break;
case KEX_PSK:
dissect_ssl3_hnd_cli_keyex_psk(hf, tvb, tree, offset, length);
break;
case KEX_RSA:
dissect_ssl3_hnd_cli_keyex_rsa(hf, tvb, tree, offset, length, session);
break;
case KEX_RSA_PSK:
dissect_ssl3_hnd_cli_keyex_rsa_psk(hf, tvb, tree, offset, length);
break;
case KEX_SRP_SHA:
case KEX_SRP_SHA_DSS:
case KEX_SRP_SHA_RSA:
break;
default:
break;
}
}
void
ssl_dissect_hnd_srv_keyex(ssl_common_dissect_t *hf, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint32 offset, guint32 offset_end,
const SslSession *session)
{
switch (ssl_get_keyex_alg(session->cipher)) {
case KEX_DH_ANON:
dissect_ssl3_hnd_srv_keyex_dhe(hf, tvb, pinfo, tree, offset, offset_end, session->version, TRUE);
break;
case KEX_DH_DSS:
case KEX_DH_RSA:
break;
case KEX_DHE_DSS:
case KEX_DHE_RSA:
dissect_ssl3_hnd_srv_keyex_dhe(hf, tvb, pinfo, tree, offset, offset_end, session->version, FALSE);
break;
case KEX_DHE_PSK:
break;
case KEX_ECDH_ANON:
dissect_ssl3_hnd_srv_keyex_ecdh(hf, tvb, pinfo, tree, offset, offset_end, session->version, TRUE);
break;
case KEX_ECDHE_PSK:
break;
case KEX_ECDH_ECDSA:
case KEX_ECDH_RSA:
case KEX_ECDHE_ECDSA:
case KEX_ECDHE_RSA:
dissect_ssl3_hnd_srv_keyex_ecdh(hf, tvb, pinfo, tree, offset, offset_end, session->version, FALSE);
break;
case KEX_KRB5:
break;
case KEX_PSK:
case KEX_RSA_PSK:
dissect_ssl3_hnd_srv_keyex_psk(hf, tvb, tree, offset, offset_end - offset);
break;
case KEX_RSA:
dissect_ssl3_hnd_srv_keyex_rsa(hf, tvb, pinfo, tree, offset, offset_end, session->version);
break;
case KEX_SRP_SHA:
case KEX_SRP_SHA_DSS:
case KEX_SRP_SHA_RSA:
break;
default:
break;
}
}
void
tls13_dissect_hnd_key_update(ssl_common_dissect_t *hf, tvbuff_t *tvb,
proto_tree *tree, guint32 offset)
{
proto_tree_add_item(tree, hf->hf.hs_key_update_request_update, tvb, offset, 1, ENC_NA);
}
void
ssl_common_register_options(module_t *module, ssl_common_options_t *options)
{
prefs_register_string_preference(module, "psk", "Pre-Shared-Key",
"Pre-Shared-Key as HEX string. Should be 0 to 16 bytes.",
&(options->psk));
prefs_register_filename_preference(module, "keylog_file", "(Pre)-Master-Secret log filename",
"The name of a file which contains a list of \n"
"(pre-)master secrets in one of the following formats:\n"
"\n"
"RSA <EPMS> <PMS>\n"
"RSA Session-ID:<SSLID> Master-Key:<MS>\n"
"CLIENT_RANDOM <CRAND> <MS>\n"
"PMS_CLIENT_RANDOM <CRAND> <PMS>\n"
"\n"
"Where:\n"
"<EPMS> = First 8 bytes of the Encrypted PMS\n"
"<PMS> = The Pre-Master-Secret (PMS) used to derive the MS\n"
"<SSLID> = The SSL Session ID\n"
"<MS> = The Master-Secret (MS)\n"
"<CRAND> = The Client's random number from the ClientHello message\n"
"\n"
"(All fields are in hex notation)",
&(options->keylog_filename), FALSE);
}
void
ssl_calculate_handshake_hash(SslDecryptSession *ssl_session, tvbuff_t *tvb, guint32 offset, guint32 length)
{
if (ssl_session && ssl_session->session.version != TLSV1DOT3_VERSION && !(ssl_session->state & SSL_MASTER_SECRET)) {
guint32 old_length = ssl_session->handshake_data.data_len;
ssl_debug_printf("Calculating hash with offset %d %d\n", offset, length);
ssl_session->handshake_data.data = (guchar *)wmem_realloc(wmem_file_scope(), ssl_session->handshake_data.data, old_length + length);
if (tvb) {
tvb_memcpy(tvb, ssl_session->handshake_data.data + old_length, offset, length);
} else {
memset(ssl_session->handshake_data.data + old_length, 0, length);
}
ssl_session->handshake_data.data_len += length;
}
}
