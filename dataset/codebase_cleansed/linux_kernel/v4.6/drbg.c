static inline unsigned short drbg_sec_strength(drbg_flag_t flags)
{
switch (flags & DRBG_STRENGTH_MASK) {
case DRBG_STRENGTH128:
return 16;
case DRBG_STRENGTH192:
return 24;
case DRBG_STRENGTH256:
return 32;
default:
return 32;
}
}
static inline void drbg_cpu_to_be32(__u32 val, unsigned char *buf)
{
struct s {
__be32 conv;
};
struct s *conversion = (struct s *) buf;
conversion->conv = cpu_to_be32(val);
}
static int drbg_ctr_bcc(struct drbg_state *drbg,
unsigned char *out, const unsigned char *key,
struct list_head *in)
{
int ret = 0;
struct drbg_string *curr = NULL;
struct drbg_string data;
short cnt = 0;
drbg_string_fill(&data, out, drbg_blocklen(drbg));
list_for_each_entry(curr, in, list) {
const unsigned char *pos = curr->buf;
size_t len = curr->len;
while (len) {
if (drbg_blocklen(drbg) == cnt) {
cnt = 0;
ret = drbg_kcapi_sym(drbg, key, out, &data);
if (ret)
return ret;
}
out[cnt] ^= *pos;
pos++;
cnt++;
len--;
}
}
if (cnt)
ret = drbg_kcapi_sym(drbg, key, out, &data);
return ret;
}
static int drbg_ctr_df(struct drbg_state *drbg,
unsigned char *df_data, size_t bytes_to_return,
struct list_head *seedlist)
{
int ret = -EFAULT;
unsigned char L_N[8];
struct drbg_string S1, S2, S4, cipherin;
LIST_HEAD(bcc_list);
unsigned char *pad = df_data + drbg_statelen(drbg);
unsigned char *iv = pad + drbg_blocklen(drbg);
unsigned char *temp = iv + drbg_blocklen(drbg);
size_t padlen = 0;
unsigned int templen = 0;
unsigned int i = 0;
const unsigned char *K = (unsigned char *)
"\x00\x01\x02\x03\x04\x05\x06\x07"
"\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f"
"\x10\x11\x12\x13\x14\x15\x16\x17"
"\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f";
unsigned char *X;
size_t generated_len = 0;
size_t inputlen = 0;
struct drbg_string *seed = NULL;
memset(pad, 0, drbg_blocklen(drbg));
memset(iv, 0, drbg_blocklen(drbg));
if ((512/8) < bytes_to_return)
return -EINVAL;
list_for_each_entry(seed, seedlist, list)
inputlen += seed->len;
drbg_cpu_to_be32(inputlen, &L_N[0]);
drbg_cpu_to_be32(bytes_to_return, &L_N[4]);
padlen = (inputlen + sizeof(L_N) + 1) % (drbg_blocklen(drbg));
if (padlen)
padlen = drbg_blocklen(drbg) - padlen;
padlen++;
pad[0] = 0x80;
drbg_string_fill(&S1, iv, drbg_blocklen(drbg));
list_add_tail(&S1.list, &bcc_list);
drbg_string_fill(&S2, L_N, sizeof(L_N));
list_add_tail(&S2.list, &bcc_list);
list_splice_tail(seedlist, &bcc_list);
drbg_string_fill(&S4, pad, padlen);
list_add_tail(&S4.list, &bcc_list);
while (templen < (drbg_keylen(drbg) + (drbg_blocklen(drbg)))) {
drbg_cpu_to_be32(i, iv);
ret = drbg_ctr_bcc(drbg, temp + templen, K, &bcc_list);
if (ret)
goto out;
i++;
templen += drbg_blocklen(drbg);
}
X = temp + (drbg_keylen(drbg));
drbg_string_fill(&cipherin, X, drbg_blocklen(drbg));
while (generated_len < bytes_to_return) {
short blocklen = 0;
ret = drbg_kcapi_sym(drbg, temp, X, &cipherin);
if (ret)
goto out;
blocklen = (drbg_blocklen(drbg) <
(bytes_to_return - generated_len)) ?
drbg_blocklen(drbg) :
(bytes_to_return - generated_len);
memcpy(df_data + generated_len, X, blocklen);
generated_len += blocklen;
}
ret = 0;
out:
memset(iv, 0, drbg_blocklen(drbg));
memset(temp, 0, drbg_statelen(drbg) + drbg_blocklen(drbg));
memset(pad, 0, drbg_blocklen(drbg));
return ret;
}
static int drbg_ctr_update(struct drbg_state *drbg, struct list_head *seed,
int reseed)
{
int ret = -EFAULT;
unsigned char *temp = drbg->scratchpad;
unsigned char *df_data = drbg->scratchpad + drbg_statelen(drbg) +
drbg_blocklen(drbg);
unsigned char *temp_p, *df_data_p;
unsigned int len = 0;
struct drbg_string cipherin;
if (3 > reseed)
memset(df_data, 0, drbg_statelen(drbg));
if (seed) {
ret = drbg_ctr_df(drbg, df_data, drbg_statelen(drbg), seed);
if (ret)
goto out;
}
drbg_string_fill(&cipherin, drbg->V, drbg_blocklen(drbg));
while (len < (drbg_statelen(drbg))) {
crypto_inc(drbg->V, drbg_blocklen(drbg));
ret = drbg_kcapi_sym(drbg, drbg->C, temp + len, &cipherin);
if (ret)
goto out;
len += drbg_blocklen(drbg);
}
temp_p = temp;
df_data_p = df_data;
for (len = 0; len < drbg_statelen(drbg); len++) {
*temp_p ^= *df_data_p;
df_data_p++; temp_p++;
}
memcpy(drbg->C, temp, drbg_keylen(drbg));
memcpy(drbg->V, temp + drbg_keylen(drbg), drbg_blocklen(drbg));
ret = 0;
out:
memset(temp, 0, drbg_statelen(drbg) + drbg_blocklen(drbg));
if (2 != reseed)
memset(df_data, 0, drbg_statelen(drbg));
return ret;
}
static int drbg_ctr_generate(struct drbg_state *drbg,
unsigned char *buf, unsigned int buflen,
struct list_head *addtl)
{
int len = 0;
int ret = 0;
struct drbg_string data;
if (addtl && !list_empty(addtl)) {
ret = drbg_ctr_update(drbg, addtl, 2);
if (ret)
return 0;
}
crypto_inc(drbg->V, drbg_blocklen(drbg));
drbg_string_fill(&data, drbg->V, drbg_blocklen(drbg));
while (len < buflen) {
int outlen = 0;
ret = drbg_kcapi_sym(drbg, drbg->C, drbg->scratchpad, &data);
if (ret) {
len = ret;
goto out;
}
outlen = (drbg_blocklen(drbg) < (buflen - len)) ?
drbg_blocklen(drbg) : (buflen - len);
memcpy(buf + len, drbg->scratchpad, outlen);
len += outlen;
if (len < buflen)
crypto_inc(drbg->V, drbg_blocklen(drbg));
}
ret = drbg_ctr_update(drbg, NULL, 3);
if (ret)
len = ret;
out:
memset(drbg->scratchpad, 0, drbg_blocklen(drbg));
return len;
}
static int drbg_hmac_update(struct drbg_state *drbg, struct list_head *seed,
int reseed)
{
int ret = -EFAULT;
int i = 0;
struct drbg_string seed1, seed2, vdata;
LIST_HEAD(seedlist);
LIST_HEAD(vdatalist);
if (!reseed)
memset(drbg->V, 1, drbg_statelen(drbg));
drbg_string_fill(&seed1, drbg->V, drbg_statelen(drbg));
list_add_tail(&seed1.list, &seedlist);
drbg_string_fill(&seed2, NULL, 1);
list_add_tail(&seed2.list, &seedlist);
if (seed)
list_splice_tail(seed, &seedlist);
drbg_string_fill(&vdata, drbg->V, drbg_statelen(drbg));
list_add_tail(&vdata.list, &vdatalist);
for (i = 2; 0 < i; i--) {
unsigned char prefix = DRBG_PREFIX0;
if (1 == i)
prefix = DRBG_PREFIX1;
seed2.buf = &prefix;
ret = drbg_kcapi_hash(drbg, drbg->C, drbg->C, &seedlist);
if (ret)
return ret;
ret = drbg_kcapi_hash(drbg, drbg->C, drbg->V, &vdatalist);
if (ret)
return ret;
if (!seed)
return ret;
}
return 0;
}
static int drbg_hmac_generate(struct drbg_state *drbg,
unsigned char *buf,
unsigned int buflen,
struct list_head *addtl)
{
int len = 0;
int ret = 0;
struct drbg_string data;
LIST_HEAD(datalist);
if (addtl && !list_empty(addtl)) {
ret = drbg_hmac_update(drbg, addtl, 1);
if (ret)
return ret;
}
drbg_string_fill(&data, drbg->V, drbg_statelen(drbg));
list_add_tail(&data.list, &datalist);
while (len < buflen) {
unsigned int outlen = 0;
ret = drbg_kcapi_hash(drbg, drbg->C, drbg->V, &datalist);
if (ret)
return ret;
outlen = (drbg_blocklen(drbg) < (buflen - len)) ?
drbg_blocklen(drbg) : (buflen - len);
memcpy(buf + len, drbg->V, outlen);
len += outlen;
}
if (addtl && !list_empty(addtl))
ret = drbg_hmac_update(drbg, addtl, 1);
else
ret = drbg_hmac_update(drbg, NULL, 1);
if (ret)
return ret;
return len;
}
static inline void drbg_add_buf(unsigned char *dst, size_t dstlen,
const unsigned char *add, size_t addlen)
{
unsigned char *dstptr;
const unsigned char *addptr;
unsigned int remainder = 0;
size_t len = addlen;
dstptr = dst + (dstlen-1);
addptr = add + (addlen-1);
while (len) {
remainder += *dstptr + *addptr;
*dstptr = remainder & 0xff;
remainder >>= 8;
len--; dstptr--; addptr--;
}
len = dstlen - addlen;
while (len && remainder > 0) {
remainder = *dstptr + 1;
*dstptr = remainder & 0xff;
remainder >>= 8;
len--; dstptr--;
}
}
static int drbg_hash_df(struct drbg_state *drbg,
unsigned char *outval, size_t outlen,
struct list_head *entropylist)
{
int ret = 0;
size_t len = 0;
unsigned char input[5];
unsigned char *tmp = drbg->scratchpad + drbg_statelen(drbg);
struct drbg_string data;
input[0] = 1;
drbg_cpu_to_be32((outlen * 8), &input[1]);
drbg_string_fill(&data, input, 5);
list_add(&data.list, entropylist);
while (len < outlen) {
short blocklen = 0;
ret = drbg_kcapi_hash(drbg, NULL, tmp, entropylist);
if (ret)
goto out;
input[0]++;
blocklen = (drbg_blocklen(drbg) < (outlen - len)) ?
drbg_blocklen(drbg) : (outlen - len);
memcpy(outval + len, tmp, blocklen);
len += blocklen;
}
out:
memset(tmp, 0, drbg_blocklen(drbg));
return ret;
}
static int drbg_hash_update(struct drbg_state *drbg, struct list_head *seed,
int reseed)
{
int ret = 0;
struct drbg_string data1, data2;
LIST_HEAD(datalist);
LIST_HEAD(datalist2);
unsigned char *V = drbg->scratchpad;
unsigned char prefix = DRBG_PREFIX1;
if (!seed)
return -EINVAL;
if (reseed) {
memcpy(V, drbg->V, drbg_statelen(drbg));
drbg_string_fill(&data1, &prefix, 1);
list_add_tail(&data1.list, &datalist);
drbg_string_fill(&data2, V, drbg_statelen(drbg));
list_add_tail(&data2.list, &datalist);
}
list_splice_tail(seed, &datalist);
ret = drbg_hash_df(drbg, drbg->V, drbg_statelen(drbg), &datalist);
if (ret)
goto out;
prefix = DRBG_PREFIX0;
drbg_string_fill(&data1, &prefix, 1);
list_add_tail(&data1.list, &datalist2);
drbg_string_fill(&data2, drbg->V, drbg_statelen(drbg));
list_add_tail(&data2.list, &datalist2);
ret = drbg_hash_df(drbg, drbg->C, drbg_statelen(drbg), &datalist2);
out:
memset(drbg->scratchpad, 0, drbg_statelen(drbg));
return ret;
}
static int drbg_hash_process_addtl(struct drbg_state *drbg,
struct list_head *addtl)
{
int ret = 0;
struct drbg_string data1, data2;
LIST_HEAD(datalist);
unsigned char prefix = DRBG_PREFIX2;
if (!addtl || list_empty(addtl))
return 0;
drbg_string_fill(&data1, &prefix, 1);
drbg_string_fill(&data2, drbg->V, drbg_statelen(drbg));
list_add_tail(&data1.list, &datalist);
list_add_tail(&data2.list, &datalist);
list_splice_tail(addtl, &datalist);
ret = drbg_kcapi_hash(drbg, NULL, drbg->scratchpad, &datalist);
if (ret)
goto out;
drbg_add_buf(drbg->V, drbg_statelen(drbg),
drbg->scratchpad, drbg_blocklen(drbg));
out:
memset(drbg->scratchpad, 0, drbg_blocklen(drbg));
return ret;
}
static int drbg_hash_hashgen(struct drbg_state *drbg,
unsigned char *buf,
unsigned int buflen)
{
int len = 0;
int ret = 0;
unsigned char *src = drbg->scratchpad;
unsigned char *dst = drbg->scratchpad + drbg_statelen(drbg);
struct drbg_string data;
LIST_HEAD(datalist);
memcpy(src, drbg->V, drbg_statelen(drbg));
drbg_string_fill(&data, src, drbg_statelen(drbg));
list_add_tail(&data.list, &datalist);
while (len < buflen) {
unsigned int outlen = 0;
ret = drbg_kcapi_hash(drbg, NULL, dst, &datalist);
if (ret) {
len = ret;
goto out;
}
outlen = (drbg_blocklen(drbg) < (buflen - len)) ?
drbg_blocklen(drbg) : (buflen - len);
memcpy(buf + len, dst, outlen);
len += outlen;
if (len < buflen)
crypto_inc(src, drbg_statelen(drbg));
}
out:
memset(drbg->scratchpad, 0,
(drbg_statelen(drbg) + drbg_blocklen(drbg)));
return len;
}
static int drbg_hash_generate(struct drbg_state *drbg,
unsigned char *buf, unsigned int buflen,
struct list_head *addtl)
{
int len = 0;
int ret = 0;
union {
unsigned char req[8];
__be64 req_int;
} u;
unsigned char prefix = DRBG_PREFIX3;
struct drbg_string data1, data2;
LIST_HEAD(datalist);
ret = drbg_hash_process_addtl(drbg, addtl);
if (ret)
return ret;
len = drbg_hash_hashgen(drbg, buf, buflen);
drbg_string_fill(&data1, &prefix, 1);
list_add_tail(&data1.list, &datalist);
drbg_string_fill(&data2, drbg->V, drbg_statelen(drbg));
list_add_tail(&data2.list, &datalist);
ret = drbg_kcapi_hash(drbg, NULL, drbg->scratchpad, &datalist);
if (ret) {
len = ret;
goto out;
}
drbg_add_buf(drbg->V, drbg_statelen(drbg),
drbg->scratchpad, drbg_blocklen(drbg));
drbg_add_buf(drbg->V, drbg_statelen(drbg),
drbg->C, drbg_statelen(drbg));
u.req_int = cpu_to_be64(drbg->reseed_ctr);
drbg_add_buf(drbg->V, drbg_statelen(drbg), u.req, 8);
out:
memset(drbg->scratchpad, 0, drbg_blocklen(drbg));
return len;
}
static inline int __drbg_seed(struct drbg_state *drbg, struct list_head *seed,
int reseed)
{
int ret = drbg->d_ops->update(drbg, seed, reseed);
if (ret)
return ret;
drbg->seeded = true;
drbg->reseed_ctr = 1;
return ret;
}
static void drbg_async_seed(struct work_struct *work)
{
struct drbg_string data;
LIST_HEAD(seedlist);
struct drbg_state *drbg = container_of(work, struct drbg_state,
seed_work);
unsigned int entropylen = drbg_sec_strength(drbg->core->flags);
unsigned char entropy[32];
BUG_ON(!entropylen);
BUG_ON(entropylen > sizeof(entropy));
get_random_bytes(entropy, entropylen);
drbg_string_fill(&data, entropy, entropylen);
list_add_tail(&data.list, &seedlist);
mutex_lock(&drbg->drbg_mutex);
crypto_free_rng(drbg->jent);
drbg->jent = NULL;
drbg->seeded = false;
__drbg_seed(drbg, &seedlist, true);
if (drbg->seeded)
drbg->reseed_threshold = drbg_max_requests(drbg);
mutex_unlock(&drbg->drbg_mutex);
memzero_explicit(entropy, entropylen);
}
static int drbg_seed(struct drbg_state *drbg, struct drbg_string *pers,
bool reseed)
{
int ret;
unsigned char entropy[((32 + 16) * 2)];
unsigned int entropylen = drbg_sec_strength(drbg->core->flags);
struct drbg_string data1;
LIST_HEAD(seedlist);
if (pers && pers->len > (drbg_max_addtl(drbg))) {
pr_devel("DRBG: personalization string too long %zu\n",
pers->len);
return -EINVAL;
}
if (list_empty(&drbg->test_data.list)) {
drbg_string_fill(&data1, drbg->test_data.buf,
drbg->test_data.len);
pr_devel("DRBG: using test entropy\n");
} else {
BUG_ON(!entropylen);
if (!reseed)
entropylen = ((entropylen + 1) / 2) * 3;
BUG_ON((entropylen * 2) > sizeof(entropy));
get_random_bytes(entropy, entropylen);
if (!drbg->jent) {
drbg_string_fill(&data1, entropy, entropylen);
pr_devel("DRBG: (re)seeding with %u bytes of entropy\n",
entropylen);
} else {
ret = crypto_rng_get_bytes(drbg->jent,
entropy + entropylen,
entropylen);
if (ret) {
pr_devel("DRBG: jent failed with %d\n", ret);
return ret;
}
drbg_string_fill(&data1, entropy, entropylen * 2);
pr_devel("DRBG: (re)seeding with %u bytes of entropy\n",
entropylen * 2);
}
}
list_add_tail(&data1.list, &seedlist);
if (pers && pers->buf && 0 < pers->len) {
list_add_tail(&pers->list, &seedlist);
pr_devel("DRBG: using personalization string\n");
}
if (!reseed) {
memset(drbg->V, 0, drbg_statelen(drbg));
memset(drbg->C, 0, drbg_statelen(drbg));
}
ret = __drbg_seed(drbg, &seedlist, reseed);
memzero_explicit(entropy, entropylen * 2);
return ret;
}
static inline void drbg_dealloc_state(struct drbg_state *drbg)
{
if (!drbg)
return;
kzfree(drbg->V);
drbg->V = NULL;
kzfree(drbg->C);
drbg->C = NULL;
kzfree(drbg->scratchpad);
drbg->scratchpad = NULL;
drbg->reseed_ctr = 0;
drbg->d_ops = NULL;
drbg->core = NULL;
}
static inline int drbg_alloc_state(struct drbg_state *drbg)
{
int ret = -ENOMEM;
unsigned int sb_size = 0;
switch (drbg->core->flags & DRBG_TYPE_MASK) {
#ifdef CONFIG_CRYPTO_DRBG_HMAC
case DRBG_HMAC:
drbg->d_ops = &drbg_hmac_ops;
break;
#endif
#ifdef CONFIG_CRYPTO_DRBG_HASH
case DRBG_HASH:
drbg->d_ops = &drbg_hash_ops;
break;
#endif
#ifdef CONFIG_CRYPTO_DRBG_CTR
case DRBG_CTR:
drbg->d_ops = &drbg_ctr_ops;
break;
#endif
default:
ret = -EOPNOTSUPP;
goto err;
}
drbg->V = kmalloc(drbg_statelen(drbg), GFP_KERNEL);
if (!drbg->V)
goto err;
drbg->C = kmalloc(drbg_statelen(drbg), GFP_KERNEL);
if (!drbg->C)
goto err;
if (drbg->core->flags & DRBG_HMAC)
sb_size = 0;
else if (drbg->core->flags & DRBG_CTR)
sb_size = drbg_statelen(drbg) + drbg_blocklen(drbg) +
drbg_statelen(drbg) +
drbg_blocklen(drbg) +
drbg_blocklen(drbg) +
drbg_statelen(drbg) + drbg_blocklen(drbg);
else
sb_size = drbg_statelen(drbg) + drbg_blocklen(drbg);
if (0 < sb_size) {
drbg->scratchpad = kzalloc(sb_size, GFP_KERNEL);
if (!drbg->scratchpad)
goto err;
}
return 0;
err:
drbg_dealloc_state(drbg);
return ret;
}
static int drbg_generate(struct drbg_state *drbg,
unsigned char *buf, unsigned int buflen,
struct drbg_string *addtl)
{
int len = 0;
LIST_HEAD(addtllist);
if (!drbg->core) {
pr_devel("DRBG: not yet seeded\n");
return -EINVAL;
}
if (0 == buflen || !buf) {
pr_devel("DRBG: no output buffer provided\n");
return -EINVAL;
}
if (addtl && NULL == addtl->buf && 0 < addtl->len) {
pr_devel("DRBG: wrong format of additional information\n");
return -EINVAL;
}
len = -EINVAL;
if (buflen > (drbg_max_request_bytes(drbg))) {
pr_devel("DRBG: requested random numbers too large %u\n",
buflen);
goto err;
}
if (addtl && addtl->len > (drbg_max_addtl(drbg))) {
pr_devel("DRBG: additional information string too long %zu\n",
addtl->len);
goto err;
}
if (drbg->reseed_threshold < drbg->reseed_ctr)
drbg->seeded = false;
if (drbg->pr || !drbg->seeded) {
pr_devel("DRBG: reseeding before generation (prediction "
"resistance: %s, state %s)\n",
drbg->pr ? "true" : "false",
drbg->seeded ? "seeded" : "unseeded");
len = drbg_seed(drbg, addtl, true);
if (len)
goto err;
addtl = NULL;
}
if (addtl && 0 < addtl->len)
list_add_tail(&addtl->list, &addtllist);
len = drbg->d_ops->generate(drbg, buf, buflen, &addtllist);
drbg->reseed_ctr++;
if (0 >= len)
goto err;
#if 0
if (drbg->reseed_ctr && !(drbg->reseed_ctr % 4096)) {
int err = 0;
pr_devel("DRBG: start to perform self test\n");
if (drbg->core->flags & DRBG_HMAC)
err = alg_test("drbg_pr_hmac_sha256",
"drbg_pr_hmac_sha256", 0, 0);
else if (drbg->core->flags & DRBG_CTR)
err = alg_test("drbg_pr_ctr_aes128",
"drbg_pr_ctr_aes128", 0, 0);
else
err = alg_test("drbg_pr_sha256",
"drbg_pr_sha256", 0, 0);
if (err) {
pr_err("DRBG: periodical self test failed\n");
drbg_uninstantiate(drbg);
return 0;
} else {
pr_devel("DRBG: self test successful\n");
}
}
#endif
len = 0;
err:
return len;
}
static int drbg_generate_long(struct drbg_state *drbg,
unsigned char *buf, unsigned int buflen,
struct drbg_string *addtl)
{
unsigned int len = 0;
unsigned int slice = 0;
do {
int err = 0;
unsigned int chunk = 0;
slice = ((buflen - len) / drbg_max_request_bytes(drbg));
chunk = slice ? drbg_max_request_bytes(drbg) : (buflen - len);
mutex_lock(&drbg->drbg_mutex);
err = drbg_generate(drbg, buf + len, chunk, addtl);
mutex_unlock(&drbg->drbg_mutex);
if (0 > err)
return err;
len += chunk;
} while (slice > 0 && (len < buflen));
return 0;
}
static void drbg_schedule_async_seed(struct random_ready_callback *rdy)
{
struct drbg_state *drbg = container_of(rdy, struct drbg_state,
random_ready);
schedule_work(&drbg->seed_work);
}
static int drbg_prepare_hrng(struct drbg_state *drbg)
{
int err;
if (list_empty(&drbg->test_data.list))
return 0;
INIT_WORK(&drbg->seed_work, drbg_async_seed);
drbg->random_ready.owner = THIS_MODULE;
drbg->random_ready.func = drbg_schedule_async_seed;
err = add_random_ready_callback(&drbg->random_ready);
switch (err) {
case 0:
break;
case -EALREADY:
err = 0;
default:
drbg->random_ready.func = NULL;
return err;
}
drbg->jent = crypto_alloc_rng("jitterentropy_rng", 0, 0);
drbg->reseed_threshold = 50;
return err;
}
static int drbg_instantiate(struct drbg_state *drbg, struct drbg_string *pers,
int coreref, bool pr)
{
int ret;
bool reseed = true;
pr_devel("DRBG: Initializing DRBG core %d with prediction resistance "
"%s\n", coreref, pr ? "enabled" : "disabled");
mutex_lock(&drbg->drbg_mutex);
if (!drbg->core) {
drbg->core = &drbg_cores[coreref];
drbg->pr = pr;
drbg->seeded = false;
drbg->reseed_threshold = drbg_max_requests(drbg);
ret = drbg_alloc_state(drbg);
if (ret)
goto unlock;
ret = -EFAULT;
if (drbg->d_ops->crypto_init(drbg))
goto err;
ret = drbg_prepare_hrng(drbg);
if (ret)
goto free_everything;
if (IS_ERR(drbg->jent)) {
ret = PTR_ERR(drbg->jent);
drbg->jent = NULL;
if (fips_enabled || ret != -ENOENT)
goto free_everything;
pr_info("DRBG: Continuing without Jitter RNG\n");
}
reseed = false;
}
ret = drbg_seed(drbg, pers, reseed);
if (ret && !reseed)
goto free_everything;
mutex_unlock(&drbg->drbg_mutex);
return ret;
err:
drbg_dealloc_state(drbg);
unlock:
mutex_unlock(&drbg->drbg_mutex);
return ret;
free_everything:
mutex_unlock(&drbg->drbg_mutex);
drbg_uninstantiate(drbg);
return ret;
}
static int drbg_uninstantiate(struct drbg_state *drbg)
{
if (drbg->random_ready.func) {
del_random_ready_callback(&drbg->random_ready);
cancel_work_sync(&drbg->seed_work);
crypto_free_rng(drbg->jent);
drbg->jent = NULL;
}
if (drbg->d_ops)
drbg->d_ops->crypto_fini(drbg);
drbg_dealloc_state(drbg);
return 0;
}
static void drbg_kcapi_set_entropy(struct crypto_rng *tfm,
const u8 *data, unsigned int len)
{
struct drbg_state *drbg = crypto_rng_ctx(tfm);
mutex_lock(&drbg->drbg_mutex);
drbg_string_fill(&drbg->test_data, data, len);
mutex_unlock(&drbg->drbg_mutex);
}
static int drbg_init_hash_kernel(struct drbg_state *drbg)
{
struct sdesc *sdesc;
struct crypto_shash *tfm;
tfm = crypto_alloc_shash(drbg->core->backend_cra_name, 0, 0);
if (IS_ERR(tfm)) {
pr_info("DRBG: could not allocate digest TFM handle: %s\n",
drbg->core->backend_cra_name);
return PTR_ERR(tfm);
}
BUG_ON(drbg_blocklen(drbg) != crypto_shash_digestsize(tfm));
sdesc = kzalloc(sizeof(struct shash_desc) + crypto_shash_descsize(tfm),
GFP_KERNEL);
if (!sdesc) {
crypto_free_shash(tfm);
return -ENOMEM;
}
sdesc->shash.tfm = tfm;
sdesc->shash.flags = 0;
drbg->priv_data = sdesc;
return 0;
}
static int drbg_fini_hash_kernel(struct drbg_state *drbg)
{
struct sdesc *sdesc = (struct sdesc *)drbg->priv_data;
if (sdesc) {
crypto_free_shash(sdesc->shash.tfm);
kzfree(sdesc);
}
drbg->priv_data = NULL;
return 0;
}
static int drbg_kcapi_hash(struct drbg_state *drbg, const unsigned char *key,
unsigned char *outval, const struct list_head *in)
{
struct sdesc *sdesc = (struct sdesc *)drbg->priv_data;
struct drbg_string *input = NULL;
if (key)
crypto_shash_setkey(sdesc->shash.tfm, key, drbg_statelen(drbg));
crypto_shash_init(&sdesc->shash);
list_for_each_entry(input, in, list)
crypto_shash_update(&sdesc->shash, input->buf, input->len);
return crypto_shash_final(&sdesc->shash, outval);
}
static int drbg_init_sym_kernel(struct drbg_state *drbg)
{
int ret = 0;
struct crypto_cipher *tfm;
tfm = crypto_alloc_cipher(drbg->core->backend_cra_name, 0, 0);
if (IS_ERR(tfm)) {
pr_info("DRBG: could not allocate cipher TFM handle: %s\n",
drbg->core->backend_cra_name);
return PTR_ERR(tfm);
}
BUG_ON(drbg_blocklen(drbg) != crypto_cipher_blocksize(tfm));
drbg->priv_data = tfm;
return ret;
}
static int drbg_fini_sym_kernel(struct drbg_state *drbg)
{
struct crypto_cipher *tfm =
(struct crypto_cipher *)drbg->priv_data;
if (tfm)
crypto_free_cipher(tfm);
drbg->priv_data = NULL;
return 0;
}
static int drbg_kcapi_sym(struct drbg_state *drbg, const unsigned char *key,
unsigned char *outval, const struct drbg_string *in)
{
struct crypto_cipher *tfm =
(struct crypto_cipher *)drbg->priv_data;
crypto_cipher_setkey(tfm, key, (drbg_keylen(drbg)));
BUG_ON(in->len < drbg_blocklen(drbg));
crypto_cipher_encrypt_one(tfm, outval, in->buf);
return 0;
}
static inline void drbg_convert_tfm_core(const char *cra_driver_name,
int *coreref, bool *pr)
{
int i = 0;
size_t start = 0;
int len = 0;
*pr = true;
if (!memcmp(cra_driver_name, "drbg_nopr_", 10)) {
start = 10;
*pr = false;
} else if (!memcmp(cra_driver_name, "drbg_pr_", 8)) {
start = 8;
} else {
return;
}
len = strlen(cra_driver_name) - start;
for (i = 0; ARRAY_SIZE(drbg_cores) > i; i++) {
if (!memcmp(cra_driver_name + start, drbg_cores[i].cra_name,
len)) {
*coreref = i;
return;
}
}
}
static int drbg_kcapi_init(struct crypto_tfm *tfm)
{
struct drbg_state *drbg = crypto_tfm_ctx(tfm);
mutex_init(&drbg->drbg_mutex);
return 0;
}
static void drbg_kcapi_cleanup(struct crypto_tfm *tfm)
{
drbg_uninstantiate(crypto_tfm_ctx(tfm));
}
static int drbg_kcapi_random(struct crypto_rng *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int dlen)
{
struct drbg_state *drbg = crypto_rng_ctx(tfm);
struct drbg_string *addtl = NULL;
struct drbg_string string;
if (slen) {
drbg_string_fill(&string, src, slen);
addtl = &string;
}
return drbg_generate_long(drbg, dst, dlen, addtl);
}
static int drbg_kcapi_seed(struct crypto_rng *tfm,
const u8 *seed, unsigned int slen)
{
struct drbg_state *drbg = crypto_rng_ctx(tfm);
struct crypto_tfm *tfm_base = crypto_rng_tfm(tfm);
bool pr = false;
struct drbg_string string;
struct drbg_string *seed_string = NULL;
int coreref = 0;
drbg_convert_tfm_core(crypto_tfm_alg_driver_name(tfm_base), &coreref,
&pr);
if (0 < slen) {
drbg_string_fill(&string, seed, slen);
seed_string = &string;
}
return drbg_instantiate(drbg, seed_string, coreref, pr);
}
static inline int __init drbg_healthcheck_sanity(void)
{
int len = 0;
#define OUTBUFLEN 16
unsigned char buf[OUTBUFLEN];
struct drbg_state *drbg = NULL;
int ret = -EFAULT;
int rc = -EFAULT;
bool pr = false;
int coreref = 0;
struct drbg_string addtl;
size_t max_addtllen, max_request_bytes;
if (!fips_enabled)
return 0;
#ifdef CONFIG_CRYPTO_DRBG_CTR
drbg_convert_tfm_core("drbg_nopr_ctr_aes128", &coreref, &pr);
#elif defined CONFIG_CRYPTO_DRBG_HASH
drbg_convert_tfm_core("drbg_nopr_sha256", &coreref, &pr);
#else
drbg_convert_tfm_core("drbg_nopr_hmac_sha256", &coreref, &pr);
#endif
drbg = kzalloc(sizeof(struct drbg_state), GFP_KERNEL);
if (!drbg)
return -ENOMEM;
mutex_init(&drbg->drbg_mutex);
ret = drbg_instantiate(drbg, NULL, coreref, pr);
if (ret) {
rc = ret;
goto outbuf;
}
max_addtllen = drbg_max_addtl(drbg);
max_request_bytes = drbg_max_request_bytes(drbg);
drbg_string_fill(&addtl, buf, max_addtllen + 1);
len = drbg_generate(drbg, buf, OUTBUFLEN, &addtl);
BUG_ON(0 < len);
len = drbg_generate(drbg, buf, (max_request_bytes + 1), NULL);
BUG_ON(0 < len);
drbg_uninstantiate(drbg);
ret = drbg_instantiate(drbg, &addtl, coreref, pr);
BUG_ON(0 == ret);
rc = 0;
pr_devel("DRBG: Sanity tests for failure code paths successfully "
"completed\n");
drbg_uninstantiate(drbg);
outbuf:
kzfree(drbg);
return rc;
}
static inline void __init drbg_fill_array(struct rng_alg *alg,
const struct drbg_core *core, int pr)
{
int pos = 0;
static int priority = 200;
memcpy(alg->base.cra_name, "stdrng", 6);
if (pr) {
memcpy(alg->base.cra_driver_name, "drbg_pr_", 8);
pos = 8;
} else {
memcpy(alg->base.cra_driver_name, "drbg_nopr_", 10);
pos = 10;
}
memcpy(alg->base.cra_driver_name + pos, core->cra_name,
strlen(core->cra_name));
alg->base.cra_priority = priority;
priority++;
if (fips_enabled)
alg->base.cra_priority += 200;
alg->base.cra_ctxsize = sizeof(struct drbg_state);
alg->base.cra_module = THIS_MODULE;
alg->base.cra_init = drbg_kcapi_init;
alg->base.cra_exit = drbg_kcapi_cleanup;
alg->generate = drbg_kcapi_random;
alg->seed = drbg_kcapi_seed;
alg->set_ent = drbg_kcapi_set_entropy;
alg->seedsize = 0;
}
static int __init drbg_init(void)
{
unsigned int i = 0;
unsigned int j = 0;
int ret = -EFAULT;
ret = drbg_healthcheck_sanity();
if (ret)
return ret;
if (ARRAY_SIZE(drbg_cores) * 2 > ARRAY_SIZE(drbg_algs)) {
pr_info("DRBG: Cannot register all DRBG types"
"(slots needed: %zu, slots available: %zu)\n",
ARRAY_SIZE(drbg_cores) * 2, ARRAY_SIZE(drbg_algs));
return ret;
}
for (j = 0; ARRAY_SIZE(drbg_cores) > j; j++, i++)
drbg_fill_array(&drbg_algs[i], &drbg_cores[j], 1);
for (j = 0; ARRAY_SIZE(drbg_cores) > j; j++, i++)
drbg_fill_array(&drbg_algs[i], &drbg_cores[j], 0);
return crypto_register_rngs(drbg_algs, (ARRAY_SIZE(drbg_cores) * 2));
}
static void __exit drbg_exit(void)
{
crypto_unregister_rngs(drbg_algs, (ARRAY_SIZE(drbg_cores) * 2));
}
