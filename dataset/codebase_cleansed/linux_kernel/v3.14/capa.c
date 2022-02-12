static inline
unsigned int ll_crypto_tfm_alg_min_keysize(struct crypto_blkcipher *tfm)
{
return crypto_blkcipher_tfm(tfm)->__crt_alg->cra_blkcipher.min_keysize;
}
struct hlist_head *init_capa_hash(void)
{
struct hlist_head *hash;
int nr_hash, i;
OBD_ALLOC(hash, PAGE_CACHE_SIZE);
if (!hash)
return NULL;
nr_hash = PAGE_CACHE_SIZE / sizeof(struct hlist_head);
LASSERT(nr_hash > NR_CAPAHASH);
for (i = 0; i < NR_CAPAHASH; i++)
INIT_HLIST_HEAD(hash + i);
return hash;
}
static inline int capa_on_server(struct obd_capa *ocapa)
{
return ocapa->c_site == CAPA_SITE_SERVER;
}
static inline void capa_delete(struct obd_capa *ocapa)
{
LASSERT(capa_on_server(ocapa));
hlist_del_init(&ocapa->u.tgt.c_hash);
list_del_init(&ocapa->c_list);
capa_count[ocapa->c_site]--;
capa_put(ocapa);
}
void cleanup_capa_hash(struct hlist_head *hash)
{
int i;
struct hlist_node *next;
struct obd_capa *oc;
spin_lock(&capa_lock);
for (i = 0; i < NR_CAPAHASH; i++) {
hlist_for_each_entry_safe(oc, next, hash + i,
u.tgt.c_hash)
capa_delete(oc);
}
spin_unlock(&capa_lock);
OBD_FREE(hash, PAGE_CACHE_SIZE);
}
static inline int capa_hashfn(struct lu_fid *fid)
{
return (fid_oid(fid) ^ fid_ver(fid)) *
(unsigned long)(fid_seq(fid) + 1) % NR_CAPAHASH;
}
static inline int capa_is_to_expire(struct obd_capa *oc)
{
return cfs_time_before(cfs_time_sub(oc->c_expiry,
cfs_time_seconds(oc->c_capa.lc_timeout)*2/3),
cfs_time_current());
}
static struct obd_capa *find_capa(struct lustre_capa *capa,
struct hlist_head *head, int alive)
{
struct obd_capa *ocapa;
int len = alive ? offsetof(struct lustre_capa, lc_keyid):sizeof(*capa);
hlist_for_each_entry(ocapa, head, u.tgt.c_hash) {
if (memcmp(&ocapa->c_capa, capa, len))
continue;
if (alive && capa_is_to_expire(ocapa))
continue;
LASSERT(capa_on_server(ocapa));
DEBUG_CAPA(D_SEC, &ocapa->c_capa, "found");
return ocapa;
}
return NULL;
}
static inline void capa_delete_lru(struct list_head *head)
{
struct obd_capa *ocapa;
struct list_head *node = head->next;
int count = 0;
while (count++ < LRU_CAPA_DELETE_COUNT) {
ocapa = list_entry(node, struct obd_capa, c_list);
node = node->next;
if (atomic_read(&ocapa->c_refc))
continue;
DEBUG_CAPA(D_SEC, &ocapa->c_capa, "free lru");
capa_delete(ocapa);
}
}
struct obd_capa *capa_add(struct hlist_head *hash, struct lustre_capa *capa)
{
struct hlist_head *head = hash + capa_hashfn(&capa->lc_fid);
struct obd_capa *ocapa, *old = NULL;
struct list_head *list = &capa_list[CAPA_SITE_SERVER];
ocapa = alloc_capa(CAPA_SITE_SERVER);
if (IS_ERR(ocapa))
return NULL;
spin_lock(&capa_lock);
old = find_capa(capa, head, 0);
if (!old) {
ocapa->c_capa = *capa;
set_capa_expiry(ocapa);
hlist_add_head(&ocapa->u.tgt.c_hash, head);
list_add_tail(&ocapa->c_list, list);
capa_get(ocapa);
capa_count[CAPA_SITE_SERVER]++;
if (capa_count[CAPA_SITE_SERVER] > CAPA_HASH_SIZE)
capa_delete_lru(list);
spin_unlock(&capa_lock);
return ocapa;
} else {
capa_get(old);
spin_unlock(&capa_lock);
capa_put(ocapa);
return old;
}
}
struct obd_capa *capa_lookup(struct hlist_head *hash, struct lustre_capa *capa,
int alive)
{
struct obd_capa *ocapa;
spin_lock(&capa_lock);
ocapa = find_capa(capa, hash + capa_hashfn(&capa->lc_fid), alive);
if (ocapa) {
list_move_tail(&ocapa->c_list,
&capa_list[CAPA_SITE_SERVER]);
capa_get(ocapa);
}
spin_unlock(&capa_lock);
return ocapa;
}
static inline int ll_crypto_hmac(struct crypto_hash *tfm,
u8 *key, unsigned int *keylen,
struct scatterlist *sg,
unsigned int size, u8 *result)
{
struct hash_desc desc;
int rv;
desc.tfm = tfm;
desc.flags = 0;
rv = crypto_hash_setkey(desc.tfm, key, *keylen);
if (rv) {
CERROR("failed to hash setkey: %d\n", rv);
return rv;
}
return crypto_hash_digest(&desc, sg, size, result);
}
int capa_hmac(__u8 *hmac, struct lustre_capa *capa, __u8 *key)
{
struct crypto_hash *tfm;
struct capa_hmac_alg *alg;
int keylen;
struct scatterlist sl;
if (capa_alg(capa) != CAPA_HMAC_ALG_SHA1) {
CERROR("unknown capability hmac algorithm!\n");
return -EFAULT;
}
alg = &capa_hmac_algs[capa_alg(capa)];
tfm = crypto_alloc_hash(alg->ha_name, 0, 0);
if (IS_ERR(tfm)) {
CERROR("crypto_alloc_tfm failed, check whether your kernel"
"has crypto support!\n");
return PTR_ERR(tfm);
}
keylen = alg->ha_keylen;
sg_set_page(&sl, virt_to_page(capa),
offsetof(struct lustre_capa, lc_hmac),
(unsigned long)(capa) % PAGE_CACHE_SIZE);
ll_crypto_hmac(tfm, key, &keylen, &sl, sl.length, hmac);
crypto_free_hash(tfm);
return 0;
}
int capa_encrypt_id(__u32 *d, __u32 *s, __u8 *key, int keylen)
{
struct crypto_blkcipher *tfm;
struct scatterlist sd;
struct scatterlist ss;
struct blkcipher_desc desc;
unsigned int min;
int rc;
char alg[CRYPTO_MAX_ALG_NAME+1] = "aes";
tfm = crypto_alloc_blkcipher(alg, 0, 0 );
if (IS_ERR(tfm)) {
CERROR("failed to load transform for aes\n");
return PTR_ERR(tfm);
}
min = ll_crypto_tfm_alg_min_keysize(tfm);
if (keylen < min) {
CERROR("keylen at least %d bits for aes\n", min * 8);
GOTO(out, rc = -EINVAL);
}
rc = crypto_blkcipher_setkey(tfm, key, min);
if (rc) {
CERROR("failed to setting key for aes\n");
GOTO(out, rc);
}
sg_set_page(&sd, virt_to_page(d), 16,
(unsigned long)(d) % PAGE_CACHE_SIZE);
sg_set_page(&ss, virt_to_page(s), 16,
(unsigned long)(s) % PAGE_CACHE_SIZE);
desc.tfm = tfm;
desc.info = NULL;
desc.flags = 0;
rc = crypto_blkcipher_encrypt(&desc, &sd, &ss, 16);
if (rc) {
CERROR("failed to encrypt for aes\n");
GOTO(out, rc);
}
out:
crypto_free_blkcipher(tfm);
return rc;
}
int capa_decrypt_id(__u32 *d, __u32 *s, __u8 *key, int keylen)
{
struct crypto_blkcipher *tfm;
struct scatterlist sd;
struct scatterlist ss;
struct blkcipher_desc desc;
unsigned int min;
int rc;
char alg[CRYPTO_MAX_ALG_NAME+1] = "aes";
tfm = crypto_alloc_blkcipher(alg, 0, 0 );
if (IS_ERR(tfm)) {
CERROR("failed to load transform for aes\n");
return PTR_ERR(tfm);
}
min = ll_crypto_tfm_alg_min_keysize(tfm);
if (keylen < min) {
CERROR("keylen at least %d bits for aes\n", min * 8);
GOTO(out, rc = -EINVAL);
}
rc = crypto_blkcipher_setkey(tfm, key, min);
if (rc) {
CERROR("failed to setting key for aes\n");
GOTO(out, rc);
}
sg_set_page(&sd, virt_to_page(d), 16,
(unsigned long)(d) % PAGE_CACHE_SIZE);
sg_set_page(&ss, virt_to_page(s), 16,
(unsigned long)(s) % PAGE_CACHE_SIZE);
desc.tfm = tfm;
desc.info = NULL;
desc.flags = 0;
rc = crypto_blkcipher_decrypt(&desc, &sd, &ss, 16);
if (rc) {
CERROR("failed to decrypt for aes\n");
GOTO(out, rc);
}
out:
crypto_free_blkcipher(tfm);
return rc;
}
void capa_cpy(void *capa, struct obd_capa *ocapa)
{
spin_lock(&ocapa->c_lock);
*(struct lustre_capa *)capa = ocapa->c_capa;
spin_unlock(&ocapa->c_lock);
}
void _debug_capa(struct lustre_capa *c,
struct libcfs_debug_msg_data *msgdata,
const char *fmt, ... )
{
va_list args;
va_start(args, fmt);
libcfs_debug_vmsg2(msgdata, fmt, args,
" capability@%p fid "DFID" opc "LPX64" uid "LPU64
" gid "LPU64" flags %u alg %d keyid %u timeout %u "
"expiry %u\n", c, PFID(capa_fid(c)), capa_opc(c),
capa_uid(c), capa_gid(c), capa_flags(c),
capa_alg(c), capa_keyid(c), capa_timeout(c),
capa_expiry(c));
va_end(args);
}
