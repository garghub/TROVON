void engine_load_cryptodev_int(void)
{
return;
}
static int open_dev_crypto(void)
{
static int fd = -1;
if (fd == -1) {
if ((fd = open("/dev/crypto", O_RDWR, 0)) == -1)
return (-1);
if (fcntl(fd, F_SETFD, 1) == -1) {
close(fd);
fd = -1;
return (-1);
}
}
return (fd);
}
static int get_dev_crypto(void)
{
int fd, retfd;
if ((fd = open_dev_crypto()) == -1)
return (-1);
# ifndef CRIOGET_NOT_NEEDED
if (ioctl(fd, CRIOGET, &retfd) == -1)
return (-1);
if (fcntl(retfd, F_SETFD, 1) == -1) {
close(retfd);
return (-1);
}
# else
retfd = fd;
# endif
return (retfd);
}
static void put_dev_crypto(int fd)
{
# ifndef CRIOGET_NOT_NEEDED
close(fd);
# endif
}
static int get_asym_dev_crypto(void)
{
static int fd = -1;
if (fd == -1)
fd = get_dev_crypto();
return fd;
}
static int get_cryptodev_ciphers(const int **cnids)
{
static int nids[CRYPTO_ALGORITHM_MAX];
struct session_op sess;
int fd, i, count = 0;
if ((fd = get_dev_crypto()) < 0) {
*cnids = NULL;
return (0);
}
memset(&sess, 0, sizeof(sess));
sess.key = (caddr_t) "123456789abcdefghijklmno";
for (i = 0; ciphers[i].id && count < CRYPTO_ALGORITHM_MAX; i++) {
if (ciphers[i].nid == NID_undef)
continue;
sess.cipher = ciphers[i].id;
sess.keylen = ciphers[i].keylen;
sess.mac = 0;
if (ioctl(fd, CIOCGSESSION, &sess) != -1 &&
ioctl(fd, CIOCFSESSION, &sess.ses) != -1)
nids[count++] = ciphers[i].nid;
}
put_dev_crypto(fd);
if (count > 0)
*cnids = nids;
else
*cnids = NULL;
return (count);
}
static int get_cryptodev_digests(const int **cnids)
{
static int nids[CRYPTO_ALGORITHM_MAX];
struct session_op sess;
int fd, i, count = 0;
if ((fd = get_dev_crypto()) < 0) {
*cnids = NULL;
return (0);
}
memset(&sess, 0, sizeof(sess));
sess.mackey = (caddr_t) "123456789abcdefghijklmno";
for (i = 0; digests[i].id && count < CRYPTO_ALGORITHM_MAX; i++) {
if (digests[i].nid == NID_undef)
continue;
sess.mac = digests[i].id;
sess.mackeylen = digests[i].keylen;
sess.cipher = 0;
if (ioctl(fd, CIOCGSESSION, &sess) != -1 &&
ioctl(fd, CIOCFSESSION, &sess.ses) != -1)
nids[count++] = digests[i].nid;
}
put_dev_crypto(fd);
if (count > 0)
*cnids = nids;
else
*cnids = NULL;
return (count);
}
static int cryptodev_usable_ciphers(const int **nids)
{
return (get_cryptodev_ciphers(nids));
}
static int cryptodev_usable_digests(const int **nids)
{
# ifdef USE_CRYPTODEV_DIGESTS
return (get_cryptodev_digests(nids));
# else
*nids = NULL;
return (0);
# endif
}
static int
cryptodev_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
struct crypt_op cryp;
struct dev_crypto_state *state = EVP_CIPHER_CTX_get_cipher_data(ctx);
struct session_op *sess = &state->d_sess;
const void *iiv;
unsigned char save_iv[EVP_MAX_IV_LENGTH];
if (state->d_fd < 0)
return (0);
if (!inl)
return (1);
if ((inl % EVP_CIPHER_CTX_block_size(ctx)) != 0)
return (0);
memset(&cryp, 0, sizeof(cryp));
cryp.ses = sess->ses;
cryp.flags = 0;
cryp.len = inl;
cryp.src = (caddr_t) in;
cryp.dst = (caddr_t) out;
cryp.mac = 0;
cryp.op = EVP_CIPHER_CTX_encrypting(ctx) ? COP_ENCRYPT : COP_DECRYPT;
if (EVP_CIPHER_CTX_iv_length(ctx) > 0) {
cryp.iv = (caddr_t) EVP_CIPHER_CTX_iv(ctx);
if (!EVP_CIPHER_CTX_encrypting(ctx)) {
iiv = in + inl - EVP_CIPHER_CTX_iv_length(ctx);
memcpy(save_iv, iiv, EVP_CIPHER_CTX_iv_length(ctx));
}
} else
cryp.iv = NULL;
if (ioctl(state->d_fd, CIOCCRYPT, &cryp) == -1) {
return (0);
}
if (EVP_CIPHER_CTX_iv_length(ctx) > 0) {
if (EVP_CIPHER_CTX_encrypting(ctx))
iiv = out + inl - EVP_CIPHER_CTX_iv_length(ctx);
else
iiv = save_iv;
memcpy(EVP_CIPHER_CTX_iv_noconst(ctx), iiv,
EVP_CIPHER_CTX_iv_length(ctx));
}
return (1);
}
static int
cryptodev_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
struct dev_crypto_state *state = EVP_CIPHER_CTX_get_cipher_data(ctx);
struct session_op *sess = &state->d_sess;
int cipher = -1, i;
for (i = 0; ciphers[i].id; i++)
if (EVP_CIPHER_CTX_nid(ctx) == ciphers[i].nid &&
EVP_CIPHER_CTX_iv_length(ctx) <= ciphers[i].ivmax &&
EVP_CIPHER_CTX_key_length(ctx) == ciphers[i].keylen) {
cipher = ciphers[i].id;
break;
}
if (!ciphers[i].id) {
state->d_fd = -1;
return (0);
}
memset(sess, 0, sizeof(*sess));
if ((state->d_fd = get_dev_crypto()) < 0)
return (0);
sess->key = (caddr_t) key;
sess->keylen = EVP_CIPHER_CTX_key_length(ctx);
sess->cipher = cipher;
if (ioctl(state->d_fd, CIOCGSESSION, sess) == -1) {
put_dev_crypto(state->d_fd);
state->d_fd = -1;
return (0);
}
return (1);
}
static int cryptodev_cleanup(EVP_CIPHER_CTX *ctx)
{
int ret = 0;
struct dev_crypto_state *state = EVP_CIPHER_CTX_get_cipher_data(ctx);
struct session_op *sess = &state->d_sess;
if (state->d_fd < 0)
return (0);
if (ioctl(state->d_fd, CIOCFSESSION, &sess->ses) == -1) {
ret = 0;
} else {
ret = 1;
}
put_dev_crypto(state->d_fd);
state->d_fd = -1;
return (ret);
}
static const EVP_CIPHER *cryptodev_rc4(void)
{
if (rc4_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_rc4, 1, 16)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 0)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_VARIABLE_LENGTH)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
rc4_cipher = cipher;
}
return rc4_cipher;
}
static const EVP_CIPHER *cryptodev_des_cbc(void)
{
if (des_cbc_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_des_cbc, 8, 8)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 8)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CBC_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
des_cbc_cipher = cipher;
}
return des_cbc_cipher;
}
static const EVP_CIPHER *cryptodev_3des_cbc(void)
{
if (des3_cbc_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_des_ede3_cbc, 8, 24)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 8)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CBC_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
des3_cbc_cipher = cipher;
}
return des3_cbc_cipher;
}
static const EVP_CIPHER *cryptodev_bf_cbc(void)
{
if (bf_cbc_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_bf_cbc, 8, 16)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 8)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CBC_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
bf_cbc_cipher = cipher;
}
return bf_cbc_cipher;
}
static const EVP_CIPHER *cryptodev_cast_cbc(void)
{
if (cast_cbc_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_cast5_cbc, 8, 16)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 8)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CBC_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
cast_cbc_cipher = cipher;
}
return cast_cbc_cipher;
}
static const EVP_CIPHER *cryptodev_aes_cbc(void)
{
if (aes_cbc_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_aes_128_cbc, 16, 16)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 16)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CBC_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
aes_cbc_cipher = cipher;
}
return aes_cbc_cipher;
}
static const EVP_CIPHER *cryptodev_aes_192_cbc(void)
{
if (aes_192_cbc_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_aes_192_cbc, 16, 24)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 16)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CBC_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
aes_192_cbc_cipher = cipher;
}
return aes_192_cbc_cipher;
}
static const EVP_CIPHER *cryptodev_aes_256_cbc(void)
{
if (aes_256_cbc_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_aes_256_cbc, 16, 32)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 16)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CBC_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
aes_256_cbc_cipher = cipher;
}
return aes_256_cbc_cipher;
}
static const EVP_CIPHER *cryptodev_aes_ctr(void)
{
if (aes_ctr_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_aes_128_ctr, 16, 16)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 14)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CTR_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
aes_ctr_cipher = cipher;
}
return aes_ctr_cipher;
}
static const EVP_CIPHER *cryptodev_aes_192_ctr(void)
{
if (aes_192_ctr_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_aes_192_ctr, 16, 24)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 14)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CTR_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
aes_192_ctr_cipher = cipher;
}
return aes_192_ctr_cipher;
}
static const EVP_CIPHER *cryptodev_aes_256_ctr(void)
{
if (aes_256_ctr_cipher == NULL) {
EVP_CIPHER *cipher;
if ((cipher = EVP_CIPHER_meth_new(NID_aes_256_ctr, 16, 32)) == NULL
|| !EVP_CIPHER_meth_set_iv_length(cipher, 14)
|| !EVP_CIPHER_meth_set_flags(cipher, EVP_CIPH_CTR_MODE)
|| !EVP_CIPHER_meth_set_init(cipher, cryptodev_init_key)
|| !EVP_CIPHER_meth_set_do_cipher(cipher, cryptodev_cipher)
|| !EVP_CIPHER_meth_set_cleanup(cipher, cryptodev_cleanup)
|| !EVP_CIPHER_meth_set_impl_ctx_size(cipher, sizeof(struct dev_crypto_state))
|| !EVP_CIPHER_meth_set_set_asn1_params(cipher, EVP_CIPHER_set_asn1_iv)
|| !EVP_CIPHER_meth_set_get_asn1_params(cipher, EVP_CIPHER_get_asn1_iv)) {
EVP_CIPHER_meth_free(cipher);
cipher = NULL;
}
aes_256_ctr_cipher = cipher;
}
return aes_256_ctr_cipher;
}
static int
cryptodev_engine_ciphers(ENGINE *e, const EVP_CIPHER **cipher,
const int **nids, int nid)
{
if (!cipher)
return (cryptodev_usable_ciphers(nids));
switch (nid) {
case NID_rc4:
*cipher = cryptodev_rc4();
break;
case NID_des_ede3_cbc:
*cipher = cryptodev_3des_cbc();
break;
case NID_des_cbc:
*cipher = cryptodev_des_cbc();
break;
case NID_bf_cbc:
*cipher = cryptodev_bf_cbc();
break;
case NID_cast5_cbc:
*cipher = cryptodev_cast_cbc();
break;
case NID_aes_128_cbc:
*cipher = cryptodev_aes_cbc();
break;
case NID_aes_192_cbc:
*cipher = cryptodev_aes_192_cbc();
break;
case NID_aes_256_cbc:
*cipher = cryptodev_aes_256_cbc();
break;
# ifdef CRYPTO_AES_CTR
case NID_aes_128_ctr:
*cipher = cryptodev_aes_ctr();
break;
case NID_aes_192_ctr:
*cipher = cryptodev_aes_ctr_192();
break;
case NID_aes_256_ctr:
*cipher = cryptodev_aes_ctr_256();
break;
# endif
default:
*cipher = NULL;
break;
}
return (*cipher != NULL);
}
static int digest_nid_to_cryptodev(int nid)
{
int i;
for (i = 0; digests[i].id; i++)
if (digests[i].nid == nid)
return (digests[i].id);
return (0);
}
static int digest_key_length(int nid)
{
int i;
for (i = 0; digests[i].id; i++)
if (digests[i].nid == nid)
return digests[i].keylen;
return (0);
}
static int cryptodev_digest_init(EVP_MD_CTX *ctx)
{
struct dev_crypto_state *state = EVP_MD_CTX_md_data(ctx);
struct session_op *sess = &state->d_sess;
int digest;
if ((digest = digest_nid_to_cryptodev(EVP_MD_CTX_type(ctx))) == NID_undef) {
printf("cryptodev_digest_init: Can't get digest \n");
return (0);
}
memset(state, 0, sizeof(*state));
if ((state->d_fd = get_dev_crypto()) < 0) {
printf("cryptodev_digest_init: Can't get Dev \n");
return (0);
}
sess->mackey = state->dummy_mac_key;
sess->mackeylen = digest_key_length(EVP_MD_CTX_type(ctx));
sess->mac = digest;
if (ioctl(state->d_fd, CIOCGSESSION, sess) < 0) {
put_dev_crypto(state->d_fd);
state->d_fd = -1;
printf("cryptodev_digest_init: Open session failed\n");
return (0);
}
return (1);
}
static int cryptodev_digest_update(EVP_MD_CTX *ctx, const void *data,
size_t count)
{
struct crypt_op cryp;
struct dev_crypto_state *state = EVP_MD_CTX_md_data(ctx);
struct session_op *sess = &state->d_sess;
char *new_mac_data;
if (!data || state->d_fd < 0) {
printf("cryptodev_digest_update: illegal inputs \n");
return (0);
}
if (!count) {
return (0);
}
if (!EVP_MD_CTX_test_flags(ctx, EVP_MD_CTX_FLAG_ONESHOT)) {
new_mac_data =
OPENSSL_realloc(state->mac_data, state->mac_len + count);
if (!new_mac_data) {
printf("cryptodev_digest_update: realloc failed\n");
return (0);
}
state->mac_data = new_mac_data;
memcpy(state->mac_data + state->mac_len, data, count);
state->mac_len += count;
return (1);
}
memset(&cryp, 0, sizeof(cryp));
cryp.ses = sess->ses;
cryp.flags = 0;
cryp.len = count;
cryp.src = (caddr_t) data;
cryp.dst = NULL;
cryp.mac = (caddr_t) state->digest_res;
if (ioctl(state->d_fd, CIOCCRYPT, &cryp) < 0) {
printf("cryptodev_digest_update: digest failed\n");
return (0);
}
return (1);
}
static int cryptodev_digest_final(EVP_MD_CTX *ctx, unsigned char *md)
{
struct crypt_op cryp;
struct dev_crypto_state *state = EVP_MD_CTX_md_data(ctx);
struct session_op *sess = &state->d_sess;
int ret = 1;
if (!md || state->d_fd < 0) {
printf("cryptodev_digest_final: illegal input\n");
return (0);
}
if (!EVP_MD_CTX_test_flags(ctx, EVP_MD_CTX_FLAG_ONESHOT)) {
memset(&cryp, 0, sizeof(cryp));
cryp.ses = sess->ses;
cryp.flags = 0;
cryp.len = state->mac_len;
cryp.src = state->mac_data;
cryp.dst = NULL;
cryp.mac = (caddr_t) md;
if (ioctl(state->d_fd, CIOCCRYPT, &cryp) < 0) {
printf("cryptodev_digest_final: digest failed\n");
return (0);
}
return 1;
}
memcpy(md, state->digest_res, EVP_MD_CTX_size(ctx));
return (ret);
}
static int cryptodev_digest_cleanup(EVP_MD_CTX *ctx)
{
int ret = 1;
struct dev_crypto_state *state = EVP_MD_CTX_md_data(ctx);
struct session_op *sess = &state->d_sess;
if (state == NULL)
return 0;
if (state->d_fd < 0) {
printf("cryptodev_digest_cleanup: illegal input\n");
return (0);
}
OPENSSL_free(state->mac_data);
state->mac_data = NULL;
state->mac_len = 0;
if (ioctl(state->d_fd, CIOCFSESSION, &sess->ses) < 0) {
printf("cryptodev_digest_cleanup: failed to close session\n");
ret = 0;
} else {
ret = 1;
}
put_dev_crypto(state->d_fd);
state->d_fd = -1;
return (ret);
}
static int cryptodev_digest_copy(EVP_MD_CTX *to, const EVP_MD_CTX *from)
{
struct dev_crypto_state *fstate = EVP_MD_CTX_md_data(from);
struct dev_crypto_state *dstate = EVP_MD_CTX_md_data(to);
struct session_op *sess;
int digest;
if (dstate == NULL || fstate == NULL)
return 1;
memcpy(dstate, fstate, sizeof(struct dev_crypto_state));
sess = &dstate->d_sess;
digest = digest_nid_to_cryptodev(EVP_MD_CTX_type(to));
sess->mackey = dstate->dummy_mac_key;
sess->mackeylen = digest_key_length(EVP_MD_CTX_type(to));
sess->mac = digest;
dstate->d_fd = get_dev_crypto();
if (ioctl(dstate->d_fd, CIOCGSESSION, sess) < 0) {
put_dev_crypto(dstate->d_fd);
dstate->d_fd = -1;
printf("cryptodev_digest_copy: Open session failed\n");
return (0);
}
if (fstate->mac_len != 0) {
if (fstate->mac_data != NULL) {
dstate->mac_data = OPENSSL_malloc(fstate->mac_len);
if (dstate->mac_data == NULL) {
printf("cryptodev_digest_copy: mac_data allocation failed\n");
return (0);
}
memcpy(dstate->mac_data, fstate->mac_data, fstate->mac_len);
dstate->mac_len = fstate->mac_len;
}
}
return 1;
}
static const EVP_MD *cryptodev_sha1(void)
{
if (sha1_md == NULL) {
EVP_MD *md;
if ((md = EVP_MD_meth_new(NID_sha1, NID_undef)) == NULL
|| !EVP_MD_meth_set_result_size(md, SHA_DIGEST_LENGTH)
|| !EVP_MD_meth_set_flags(md, EVP_MD_FLAG_ONESHOT)
|| !EVP_MD_meth_set_input_blocksize(md, SHA_CBLOCK)
|| !EVP_MD_meth_set_app_datasize(md,
sizeof(struct dev_crypto_state))
|| !EVP_MD_meth_set_init(md, cryptodev_digest_init)
|| !EVP_MD_meth_set_update(md, cryptodev_digest_update)
|| !EVP_MD_meth_set_final(md, cryptodev_digest_final)
|| !EVP_MD_meth_set_copy(md, cryptodev_digest_copy)
|| !EVP_MD_meth_set_cleanup(md, cryptodev_digest_cleanup)) {
EVP_MD_meth_free(md);
md = NULL;
}
sha1_md = md;
}
return sha1_md;
}
static const EVP_MD *cryptodev_md5(void)
{
if (md5_md == NULL) {
EVP_MD *md;
if ((md = EVP_MD_meth_new(NID_md5, NID_undef)) == NULL
|| !EVP_MD_meth_set_result_size(md, 16 )
|| !EVP_MD_meth_set_flags(md, EVP_MD_FLAG_ONESHOT)
|| !EVP_MD_meth_set_input_blocksize(md, 64 )
|| !EVP_MD_meth_set_app_datasize(md,
sizeof(struct dev_crypto_state))
|| !EVP_MD_meth_set_init(md, cryptodev_digest_init)
|| !EVP_MD_meth_set_update(md, cryptodev_digest_update)
|| !EVP_MD_meth_set_final(md, cryptodev_digest_final)
|| !EVP_MD_meth_set_copy(md, cryptodev_digest_copy)
|| !EVP_MD_meth_set_cleanup(md, cryptodev_digest_cleanup)) {
EVP_MD_meth_free(md);
md = NULL;
}
md5_md = md;
}
return md5_md;
}
static int
cryptodev_engine_digests(ENGINE *e, const EVP_MD **digest,
const int **nids, int nid)
{
if (!digest)
return (cryptodev_usable_digests(nids));
switch (nid) {
# ifdef USE_CRYPTODEV_DIGESTS
case NID_md5:
*digest = cryptodev_md5();
break;
case NID_sha1:
*digest = cryptodev_sha1();
break;
default:
# endif
*digest = NULL;
break;
}
return (*digest != NULL);
}
static int cryptodev_engine_destroy(ENGINE *e)
{
EVP_CIPHER_meth_free(rc4_cipher);
rc4_cipher = NULL;
EVP_CIPHER_meth_free(des_cbc_cipher);
des_cbc_cipher = NULL;
EVP_CIPHER_meth_free(des3_cbc_cipher);
des3_cbc_cipher = NULL;
EVP_CIPHER_meth_free(bf_cbc_cipher);
bf_cbc_cipher = NULL;
EVP_CIPHER_meth_free(cast_cbc_cipher);
cast_cbc_cipher = NULL;
EVP_CIPHER_meth_free(aes_cbc_cipher);
aes_cbc_cipher = NULL;
EVP_CIPHER_meth_free(aes_192_cbc_cipher);
aes_192_cbc_cipher = NULL;
EVP_CIPHER_meth_free(aes_256_cbc_cipher);
aes_256_cbc_cipher = NULL;
# ifdef CRYPTO_AES_CTR
EVP_CIPHER_meth_free(aes_ctr_cipher);
aes_ctr_cipher = NULL;
EVP_CIPHER_meth_free(aes_192_ctr_cipher);
aes_192_ctr_cipher = NULL;
EVP_CIPHER_meth_free(aes_256_ctr_cipher);
aes_256_ctr_cipher = NULL;
# endif
# ifdef USE_CRYPTODEV_DIGESTS
EVP_MD_meth_free(sha1_md);
sha1_md = NULL;
EVP_MD_meth_free(md5_md);
md5_md = NULL;
# endif
RSA_meth_free(cryptodev_rsa);
cryptodev_rsa = NULL;
#ifndef OPENSSL_NO_DSA
DSA_meth_free(cryptodev_dsa);
cryptodev_dsa = NULL;
#endif
#ifndef OPENSSL_NO_DH
DH_meth_free(cryptodev_dh);
cryptodev_dh = NULL;
#endif
return 1;
}
static int bn2crparam(const BIGNUM *a, struct crparam *crp)
{
ssize_t bytes, bits;
u_char *b;
crp->crp_p = NULL;
crp->crp_nbits = 0;
bits = BN_num_bits(a);
bytes = BN_num_bytes(a);
b = OPENSSL_zalloc(bytes);
if (b == NULL)
return (1);
crp->crp_p = (caddr_t) b;
crp->crp_nbits = bits;
BN_bn2bin(a, b);
return (0);
}
static int crparam2bn(struct crparam *crp, BIGNUM *a)
{
u_int8_t *pd;
int i, bytes;
bytes = (crp->crp_nbits + 7) / 8;
if (bytes == 0)
return (-1);
if ((pd = OPENSSL_malloc(bytes)) == NULL)
return (-1);
for (i = 0; i < bytes; i++)
pd[i] = crp->crp_p[bytes - i - 1];
BN_bin2bn(pd, bytes, a);
free(pd);
return (0);
}
static void zapparams(struct crypt_kop *kop)
{
int i;
for (i = 0; i < kop->crk_iparams + kop->crk_oparams; i++) {
OPENSSL_free(kop->crk_param[i].crp_p);
kop->crk_param[i].crp_p = NULL;
kop->crk_param[i].crp_nbits = 0;
}
}
static int
cryptodev_asym(struct crypt_kop *kop, int rlen, BIGNUM *r, int slen,
BIGNUM *s)
{
int fd, ret = -1;
if ((fd = get_asym_dev_crypto()) < 0)
return ret;
if (r) {
kop->crk_param[kop->crk_iparams].crp_p = OPENSSL_zalloc(rlen);
if (kop->crk_param[kop->crk_iparams].crp_p == NULL)
return ret;
kop->crk_param[kop->crk_iparams].crp_nbits = rlen * 8;
kop->crk_oparams++;
}
if (s) {
kop->crk_param[kop->crk_iparams + 1].crp_p =
OPENSSL_zalloc(slen);
if (kop->crk_param[kop->crk_iparams+1].crp_p == NULL)
return ret;
kop->crk_param[kop->crk_iparams + 1].crp_nbits = slen * 8;
kop->crk_oparams++;
}
if (ioctl(fd, CIOCKEY, kop) == 0) {
if (r)
crparam2bn(&kop->crk_param[kop->crk_iparams], r);
if (s)
crparam2bn(&kop->crk_param[kop->crk_iparams + 1], s);
ret = 0;
}
return ret;
}
static int
cryptodev_bn_mod_exp(BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *in_mont)
{
struct crypt_kop kop;
int ret = 1;
if (cryptodev_asymfeat == 0) {
ret = BN_mod_exp(r, a, p, m, ctx);
return (ret);
}
memset(&kop, 0, sizeof(kop));
kop.crk_op = CRK_MOD_EXP;
if (bn2crparam(a, &kop.crk_param[0]))
goto err;
if (bn2crparam(p, &kop.crk_param[1]))
goto err;
if (bn2crparam(m, &kop.crk_param[2]))
goto err;
kop.crk_iparams = 3;
if (cryptodev_asym(&kop, BN_num_bytes(m), r, 0, NULL)) {
const RSA_METHOD *meth = RSA_PKCS1_OpenSSL();
printf("OCF asym process failed, Running in software\n");
ret = RSA_meth_get_bn_mod_exp(meth)(r, a, p, m, ctx, in_mont);
} else if (ECANCELED == kop.crk_status) {
const RSA_METHOD *meth = RSA_PKCS1_OpenSSL();
printf("OCF hardware operation cancelled. Running in Software\n");
ret = RSA_meth_get_bn_mod_exp(meth)(r, a, p, m, ctx, in_mont);
}
err:
zapparams(&kop);
return (ret);
}
static int
cryptodev_rsa_nocrt_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa,
BN_CTX *ctx)
{
int r;
const BIGNUM *n = NULL;
const BIGNUM *d = NULL;
ctx = BN_CTX_new();
RSA_get0_key(rsa, &n, NULL, &d);
r = cryptodev_bn_mod_exp(r0, I, d, n, ctx, NULL);
BN_CTX_free(ctx);
return (r);
}
static int
cryptodev_rsa_mod_exp(BIGNUM *r0, const BIGNUM *I, RSA *rsa, BN_CTX *ctx)
{
struct crypt_kop kop;
int ret = 1;
const BIGNUM *p = NULL;
const BIGNUM *q = NULL;
const BIGNUM *dmp1 = NULL;
const BIGNUM *dmq1 = NULL;
const BIGNUM *iqmp = NULL;
const BIGNUM *n = NULL;
RSA_get0_factors(rsa, &p, &q);
RSA_get0_crt_params(rsa, &dmp1, &dmq1, &iqmp);
RSA_get0_key(rsa, &n, NULL, NULL);
if (!p || !q || !dmp1 || !dmq1 || !iqmp) {
return (0);
}
memset(&kop, 0, sizeof(kop));
kop.crk_op = CRK_MOD_EXP_CRT;
if (bn2crparam(p, &kop.crk_param[0]))
goto err;
if (bn2crparam(q, &kop.crk_param[1]))
goto err;
if (bn2crparam(I, &kop.crk_param[2]))
goto err;
if (bn2crparam(dmp1, &kop.crk_param[3]))
goto err;
if (bn2crparam(dmq1, &kop.crk_param[4]))
goto err;
if (bn2crparam(iqmp, &kop.crk_param[5]))
goto err;
kop.crk_iparams = 6;
if (cryptodev_asym(&kop, BN_num_bytes(n), r0, 0, NULL)) {
const RSA_METHOD *meth = RSA_PKCS1_OpenSSL();
printf("OCF asym process failed, running in Software\n");
ret = RSA_meth_get_mod_exp(meth)(r0, I, rsa, ctx);
} else if (ECANCELED == kop.crk_status) {
const RSA_METHOD *meth = RSA_PKCS1_OpenSSL();
printf("OCF hardware operation cancelled. Running in Software\n");
ret = RSA_meth_get_mod_exp(meth)(r0, I, rsa, ctx);
}
err:
zapparams(&kop);
return (ret);
}
static int
cryptodev_dsa_bn_mod_exp(DSA *dsa, BIGNUM *r, const BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx, BN_MONT_CTX *m_ctx)
{
return cryptodev_bn_mod_exp(r, a, p, m, ctx, m_ctx);
}
static int
cryptodev_dsa_dsa_mod_exp(DSA *dsa, BIGNUM *t1, const BIGNUM *g,
const BIGNUM *u1, const BIGNUM *pub_key,
const BIGNUM *u2, const BIGNUM *p, BN_CTX *ctx,
BN_MONT_CTX *mont)
{
const BIGNUM *dsag, *dsap, *dsapub_key;
BIGNUM *t2;
int ret = 0;
const DSA_METHOD *meth;
int (*bn_mod_exp)(DSA *, BIGNUM *, const BIGNUM *, const BIGNUM *, const BIGNUM *,
BN_CTX *, BN_MONT_CTX *);
t2 = BN_new();
if (t2 == NULL)
goto err;
ret = 0;
DSA_get0_pqg(dsa, &dsap, NULL, &dsag);
DSA_get0_key(dsa, &dsapub_key, NULL);
meth = DSA_get_method(dsa);
if (meth == NULL)
goto err;
bn_mod_exp = DSA_meth_get_bn_mod_exp(meth);
if (bn_mod_exp == NULL)
goto err;
if (!bn_mod_exp(dsa, t1, dsag, u1, dsap, ctx, mont))
goto err;
if (!bn_mod_exp(dsa, t2, dsapub_key, u2, dsap, ctx, mont))
goto err;
if (!BN_mod_mul(t1, t1, t2, dsap, ctx))
goto err;
ret = 1;
err:
BN_free(t2);
return (ret);
}
static DSA_SIG *cryptodev_dsa_do_sign(const unsigned char *dgst, int dlen,
DSA *dsa)
{
struct crypt_kop kop;
BIGNUM *r, *s;
const BIGNUM *dsap = NULL, *dsaq = NULL, *dsag = NULL;
const BIGNUM *priv_key = NULL;
DSA_SIG *dsasig, *dsaret = NULL;
dsasig = DSA_SIG_new();
if (dsasig == NULL)
goto err;
memset(&kop, 0, sizeof(kop));
kop.crk_op = CRK_DSA_SIGN;
kop.crk_param[0].crp_p = (caddr_t) dgst;
kop.crk_param[0].crp_nbits = dlen * 8;
DSA_get0_pqg(dsa, &dsap, &dsaq, &dsag);
DSA_get0_key(dsa, NULL, &priv_key);
if (bn2crparam(dsap, &kop.crk_param[1]))
goto err;
if (bn2crparam(dsaq, &kop.crk_param[2]))
goto err;
if (bn2crparam(dsag, &kop.crk_param[3]))
goto err;
if (bn2crparam(priv_key, &kop.crk_param[4]))
goto err;
kop.crk_iparams = 5;
r = BN_new();
if (r == NULL)
goto err;
s = BN_new();
if (s == NULL)
goto err;
if (cryptodev_asym(&kop, BN_num_bytes(dsaq), r,
BN_num_bytes(dsaq), s) == 0) {
DSA_SIG_set0(dsasig, r, s);
dsaret = dsasig;
} else {
dsaret = DSA_meth_get_sign(DSA_OpenSSL())(dgst, dlen, dsa);
}
err:
if (dsaret != dsasig)
DSA_SIG_free(dsasig);
kop.crk_param[0].crp_p = NULL;
zapparams(&kop);
return dsaret;
}
static int
cryptodev_dsa_verify(const unsigned char *dgst, int dlen,
DSA_SIG *sig, DSA *dsa)
{
struct crypt_kop kop;
int dsaret = 1;
const BIGNUM *pr, *ps, *p = NULL, *q = NULL, *g = NULL, *pub_key = NULL;
memset(&kop, 0, sizeof(kop));
kop.crk_op = CRK_DSA_VERIFY;
kop.crk_param[0].crp_p = (caddr_t) dgst;
kop.crk_param[0].crp_nbits = dlen * 8;
DSA_get0_pqg(dsa, &p, &q, &g);
if (bn2crparam(p, &kop.crk_param[1]))
goto err;
if (bn2crparam(q, &kop.crk_param[2]))
goto err;
if (bn2crparam(g, &kop.crk_param[3]))
goto err;
DSA_get0_key(dsa, &pub_key, NULL);
if (bn2crparam(pub_key, &kop.crk_param[4]))
goto err;
DSA_SIG_get0(sig, &pr, &ps);
if (bn2crparam(pr, &kop.crk_param[5]))
goto err;
if (bn2crparam(ps, &kop.crk_param[6]))
goto err;
kop.crk_iparams = 7;
if (cryptodev_asym(&kop, 0, NULL, 0, NULL) == 0) {
if (0 != kop.crk_status)
dsaret = 0;
} else {
dsaret = DSA_meth_get_verify(DSA_OpenSSL())(dgst, dlen, sig, dsa);
}
err:
kop.crk_param[0].crp_p = NULL;
zapparams(&kop);
return (dsaret);
}
static int
cryptodev_mod_exp_dh(const DH *dh, BIGNUM *r, const BIGNUM *a,
const BIGNUM *p, const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return (cryptodev_bn_mod_exp(r, a, p, m, ctx, m_ctx));
}
static int
cryptodev_dh_compute_key(unsigned char *key, const BIGNUM *pub_key, DH *dh)
{
struct crypt_kop kop;
int dhret = 1;
int fd, keylen;
const BIGNUM *p = NULL;
const BIGNUM *priv_key = NULL;
if ((fd = get_asym_dev_crypto()) < 0) {
const DH_METHOD *meth = DH_OpenSSL();
return DH_meth_get_compute_key(meth)(key, pub_key, dh);
}
DH_get0_pqg(dh, &p, NULL, NULL);
DH_get0_key(dh, NULL, &priv_key);
keylen = BN_num_bits(p);
memset(&kop, 0, sizeof(kop));
kop.crk_op = CRK_DH_COMPUTE_KEY;
if (bn2crparam(priv_key, &kop.crk_param[0]))
goto err;
if (bn2crparam(pub_key, &kop.crk_param[1]))
goto err;
if (bn2crparam(p, &kop.crk_param[2]))
goto err;
kop.crk_iparams = 3;
kop.crk_param[3].crp_p = (caddr_t) key;
kop.crk_param[3].crp_nbits = keylen * 8;
kop.crk_oparams = 1;
if (ioctl(fd, CIOCKEY, &kop) == -1) {
const DH_METHOD *meth = DH_OpenSSL();
dhret = DH_meth_get_compute_key(meth)(key, pub_key, dh);
}
err:
kop.crk_param[3].crp_p = NULL;
zapparams(&kop);
return (dhret);
}
static int
cryptodev_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f) (void))
{
# ifdef HAVE_SYSLOG_R
struct syslog_data sd = SYSLOG_DATA_INIT;
# endif
switch (cmd) {
default:
# ifdef HAVE_SYSLOG_R
syslog_r(LOG_ERR, &sd, "cryptodev_ctrl: unknown command %d", cmd);
# else
syslog(LOG_ERR, "cryptodev_ctrl: unknown command %d", cmd);
# endif
break;
}
return (1);
}
void engine_load_cryptodev_int(void)
{
ENGINE *engine = ENGINE_new();
int fd;
if (engine == NULL)
return;
if ((fd = get_dev_crypto()) < 0) {
ENGINE_free(engine);
return;
}
if (ioctl(fd, CIOCASYMFEAT, &cryptodev_asymfeat) == -1) {
put_dev_crypto(fd);
ENGINE_free(engine);
return;
}
put_dev_crypto(fd);
if (!ENGINE_set_id(engine, "cryptodev") ||
!ENGINE_set_name(engine, "BSD cryptodev engine") ||
!ENGINE_set_destroy_function(engine, cryptodev_engine_destroy) ||
!ENGINE_set_ciphers(engine, cryptodev_engine_ciphers) ||
!ENGINE_set_digests(engine, cryptodev_engine_digests) ||
!ENGINE_set_ctrl_function(engine, cryptodev_ctrl) ||
!ENGINE_set_cmd_defns(engine, cryptodev_defns)) {
ENGINE_free(engine);
return;
}
cryptodev_rsa = RSA_meth_dup(RSA_PKCS1_OpenSSL());
if (cryptodev_rsa != NULL) {
RSA_meth_set1_name(cryptodev_rsa, "cryptodev RSA method");
RSA_meth_set_flags(cryptodev_rsa, 0);
if (ENGINE_set_RSA(engine, cryptodev_rsa)) {
if (cryptodev_asymfeat & CRF_MOD_EXP) {
RSA_meth_set_bn_mod_exp(cryptodev_rsa, cryptodev_bn_mod_exp);
if (cryptodev_asymfeat & CRF_MOD_EXP_CRT)
RSA_meth_set_mod_exp(cryptodev_rsa, cryptodev_rsa_mod_exp);
else
RSA_meth_set_mod_exp(cryptodev_rsa,
cryptodev_rsa_nocrt_mod_exp);
}
}
} else {
ENGINE_free(engine);
return;
}
#ifndef OPENSSL_NO_DSA
cryptodev_dsa = DSA_meth_dup(DSA_OpenSSL());
if (cryptodev_dsa != NULL) {
DSA_meth_set1_name(cryptodev_dsa, "cryptodev DSA method");
DSA_meth_set_flags(cryptodev_dsa, 0);
if (ENGINE_set_DSA(engine, cryptodev_dsa)) {
if (cryptodev_asymfeat & CRF_DSA_SIGN)
DSA_meth_set_sign(cryptodev_dsa, cryptodev_dsa_do_sign);
if (cryptodev_asymfeat & CRF_MOD_EXP) {
DSA_meth_set_bn_mod_exp(cryptodev_dsa,
cryptodev_dsa_bn_mod_exp);
DSA_meth_set_mod_exp(cryptodev_dsa, cryptodev_dsa_dsa_mod_exp);
}
if (cryptodev_asymfeat & CRF_DSA_VERIFY)
DSA_meth_set_verify(cryptodev_dsa, cryptodev_dsa_verify);
}
} else {
ENGINE_free(engine);
return;
}
#endif
#ifndef OPENSSL_NO_DH
cryptodev_dh = DH_meth_dup(DH_OpenSSL());
if (cryptodev_dh != NULL) {
DH_meth_set1_name(cryptodev_dh, "cryptodev DH method");
DH_meth_set_flags(cryptodev_dh, 0);
if (ENGINE_set_DH(engine, cryptodev_dh)) {
if (cryptodev_asymfeat & CRF_MOD_EXP) {
DH_meth_set_bn_mod_exp(cryptodev_dh, cryptodev_mod_exp_dh);
if (cryptodev_asymfeat & CRF_DH_COMPUTE_KEY)
DH_meth_set_compute_key(cryptodev_dh,
cryptodev_dh_compute_key);
}
}
} else {
ENGINE_free(engine);
return;
}
#endif
ENGINE_add(engine);
ENGINE_free(engine);
ERR_clear_error();
}
