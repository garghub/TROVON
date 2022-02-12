static void JPAKE_ZKP_init(JPAKE_ZKP *zkp)
{
zkp->gr = BN_new();
zkp->b = BN_new();
}
static void JPAKE_ZKP_release(JPAKE_ZKP *zkp)
{
BN_free(zkp->b);
BN_free(zkp->gr);
}
void JPAKE_STEP_PART_init(JPAKE_STEP_PART *p)
{
p->gx = BN_new();
JPAKE_ZKP_init(&p->zkpx);
}
void JPAKE_STEP_PART_release(JPAKE_STEP_PART *p)
{
JPAKE_ZKP_release(&p->zkpx);
BN_free(p->gx);
}
void JPAKE_STEP1_init(JPAKE_STEP1 *s1)
{
JPAKE_STEP_PART_init(&s1->p1);
JPAKE_STEP_PART_init(&s1->p2);
}
void JPAKE_STEP1_release(JPAKE_STEP1 *s1)
{
JPAKE_STEP_PART_release(&s1->p2);
JPAKE_STEP_PART_release(&s1->p1);
}
static void JPAKE_CTX_init(JPAKE_CTX *ctx, const char *name,
const char *peer_name, const BIGNUM *p,
const BIGNUM *g, const BIGNUM *q,
const BIGNUM *secret)
{
ctx->p.name = OPENSSL_strdup(name);
ctx->p.peer_name = OPENSSL_strdup(peer_name);
ctx->p.p = BN_dup(p);
ctx->p.g = BN_dup(g);
ctx->p.q = BN_dup(q);
ctx->secret = BN_dup(secret);
ctx->p.gxc = BN_new();
ctx->p.gxd = BN_new();
ctx->xa = BN_new();
ctx->xb = BN_new();
ctx->key = BN_new();
ctx->ctx = BN_CTX_new();
}
static void JPAKE_CTX_release(JPAKE_CTX *ctx)
{
BN_CTX_free(ctx->ctx);
BN_clear_free(ctx->key);
BN_clear_free(ctx->xb);
BN_clear_free(ctx->xa);
BN_free(ctx->p.gxd);
BN_free(ctx->p.gxc);
BN_clear_free(ctx->secret);
BN_free(ctx->p.q);
BN_free(ctx->p.g);
BN_free(ctx->p.p);
OPENSSL_free(ctx->p.peer_name);
OPENSSL_free(ctx->p.name);
memset(ctx, '\0', sizeof *ctx);
}
JPAKE_CTX *JPAKE_CTX_new(const char *name, const char *peer_name,
const BIGNUM *p, const BIGNUM *g, const BIGNUM *q,
const BIGNUM *secret)
{
JPAKE_CTX *ctx = OPENSSL_malloc(sizeof *ctx);
JPAKE_CTX_init(ctx, name, peer_name, p, g, q, secret);
return ctx;
}
void JPAKE_CTX_free(JPAKE_CTX *ctx)
{
JPAKE_CTX_release(ctx);
OPENSSL_free(ctx);
}
static void hashlength(SHA_CTX *sha, size_t l)
{
unsigned char b[2];
OPENSSL_assert(l <= 0xffff);
b[0] = l >> 8;
b[1] = l & 0xff;
SHA1_Update(sha, b, 2);
}
static void hashstring(SHA_CTX *sha, const char *string)
{
size_t l = strlen(string);
hashlength(sha, l);
SHA1_Update(sha, string, l);
}
static void hashbn(SHA_CTX *sha, const BIGNUM *bn)
{
size_t l = BN_num_bytes(bn);
unsigned char *bin = OPENSSL_malloc(l);
hashlength(sha, l);
BN_bn2bin(bn, bin);
SHA1_Update(sha, bin, l);
OPENSSL_free(bin);
}
static void zkp_hash(BIGNUM *h, const BIGNUM *zkpg, const JPAKE_STEP_PART *p,
const char *proof_name)
{
unsigned char md[SHA_DIGEST_LENGTH];
SHA_CTX sha;
SHA1_Init(&sha);
hashbn(&sha, zkpg);
OPENSSL_assert(!BN_is_zero(p->zkpx.gr));
hashbn(&sha, p->zkpx.gr);
hashbn(&sha, p->gx);
hashstring(&sha, proof_name);
SHA1_Final(md, &sha);
BN_bin2bn(md, SHA_DIGEST_LENGTH, h);
}
static void generate_zkp(JPAKE_STEP_PART *p, const BIGNUM *x,
const BIGNUM *zkpg, JPAKE_CTX *ctx)
{
BIGNUM *r = BN_new();
BIGNUM *h = BN_new();
BIGNUM *t = BN_new();
BN_rand_range(r, ctx->p.q);
BN_mod_exp(p->zkpx.gr, zkpg, r, ctx->p.p, ctx->ctx);
zkp_hash(h, zkpg, p, ctx->p.name);
BN_mod_mul(t, x, h, ctx->p.q, ctx->ctx);
BN_mod_sub(p->zkpx.b, r, t, ctx->p.q, ctx->ctx);
BN_free(t);
BN_free(h);
BN_free(r);
}
static int verify_zkp(const JPAKE_STEP_PART *p, const BIGNUM *zkpg,
JPAKE_CTX *ctx)
{
BIGNUM *h = BN_new();
BIGNUM *t1 = BN_new();
BIGNUM *t2 = BN_new();
BIGNUM *t3 = BN_new();
int ret = 0;
zkp_hash(h, zkpg, p, ctx->p.peer_name);
BN_mod_exp(t1, zkpg, p->zkpx.b, ctx->p.p, ctx->ctx);
BN_mod_exp(t2, p->gx, h, ctx->p.p, ctx->ctx);
BN_mod_mul(t3, t1, t2, ctx->p.p, ctx->ctx);
if (BN_cmp(t3, p->zkpx.gr) == 0)
ret = 1;
else
JPAKEerr(JPAKE_F_VERIFY_ZKP, JPAKE_R_ZKP_VERIFY_FAILED);
BN_free(t3);
BN_free(t2);
BN_free(t1);
BN_free(h);
return ret;
}
static void generate_step_part(JPAKE_STEP_PART *p, const BIGNUM *x,
const BIGNUM *g, JPAKE_CTX *ctx)
{
BN_mod_exp(p->gx, g, x, ctx->p.p, ctx->ctx);
generate_zkp(p, x, g, ctx);
}
static void genrand(JPAKE_CTX *ctx)
{
BIGNUM *qm1;
BN_rand_range(ctx->xa, ctx->p.q);
qm1 = BN_new();
BN_copy(qm1, ctx->p.q);
BN_sub_word(qm1, 1);
BN_rand_range(ctx->xb, qm1);
BN_add_word(ctx->xb, 1);
BN_free(qm1);
}
int JPAKE_STEP1_generate(JPAKE_STEP1 *send, JPAKE_CTX *ctx)
{
genrand(ctx);
generate_step_part(&send->p1, ctx->xa, ctx->p.g, ctx);
generate_step_part(&send->p2, ctx->xb, ctx->p.g, ctx);
return 1;
}
static int is_legal(const BIGNUM *gx, const JPAKE_CTX *ctx)
{
BIGNUM *t;
int res;
if (BN_is_negative(gx) || BN_is_zero(gx) || BN_cmp(gx, ctx->p.p) >= 0)
return 0;
t = BN_new();
BN_mod_exp(t, gx, ctx->p.q, ctx->p.p, ctx->ctx);
res = BN_is_one(t);
BN_free(t);
return res;
}
int JPAKE_STEP1_process(JPAKE_CTX *ctx, const JPAKE_STEP1 *received)
{
if (!is_legal(received->p1.gx, ctx)) {
JPAKEerr(JPAKE_F_JPAKE_STEP1_PROCESS,
JPAKE_R_G_TO_THE_X3_IS_NOT_LEGAL);
return 0;
}
if (!is_legal(received->p2.gx, ctx)) {
JPAKEerr(JPAKE_F_JPAKE_STEP1_PROCESS,
JPAKE_R_G_TO_THE_X4_IS_NOT_LEGAL);
return 0;
}
if (!verify_zkp(&received->p1, ctx->p.g, ctx)) {
JPAKEerr(JPAKE_F_JPAKE_STEP1_PROCESS, JPAKE_R_VERIFY_X3_FAILED);
return 0;
}
if (!verify_zkp(&received->p2, ctx->p.g, ctx)) {
JPAKEerr(JPAKE_F_JPAKE_STEP1_PROCESS, JPAKE_R_VERIFY_X4_FAILED);
return 0;
}
if (BN_is_one(received->p2.gx)) {
JPAKEerr(JPAKE_F_JPAKE_STEP1_PROCESS, JPAKE_R_G_TO_THE_X4_IS_ONE);
return 0;
}
BN_copy(ctx->p.gxc, received->p1.gx);
BN_copy(ctx->p.gxd, received->p2.gx);
return 1;
}
int JPAKE_STEP2_generate(JPAKE_STEP2 *send, JPAKE_CTX *ctx)
{
BIGNUM *t1 = BN_new();
BIGNUM *t2 = BN_new();
BN_mod_exp(t1, ctx->p.g, ctx->xa, ctx->p.p, ctx->ctx);
BN_mod_mul(t2, t1, ctx->p.gxc, ctx->p.p, ctx->ctx);
BN_mod_mul(t1, t2, ctx->p.gxd, ctx->p.p, ctx->ctx);
BN_mod_mul(t2, ctx->xb, ctx->secret, ctx->p.q, ctx->ctx);
generate_step_part(send, t2, t1, ctx);
BN_free(t1);
BN_free(t2);
return 1;
}
static int compute_key(JPAKE_CTX *ctx, const BIGNUM *gx)
{
BIGNUM *t1 = BN_new();
BIGNUM *t2 = BN_new();
BIGNUM *t3 = BN_new();
BN_mod_exp(t1, ctx->p.gxd, ctx->xb, ctx->p.p, ctx->ctx);
BN_sub(t2, ctx->p.q, ctx->secret);
BN_mod_exp(t3, t1, t2, ctx->p.p, ctx->ctx);
BN_mod_mul(t1, gx, t3, ctx->p.p, ctx->ctx);
BN_mod_exp(ctx->key, t1, ctx->xb, ctx->p.p, ctx->ctx);
BN_free(t3);
BN_free(t2);
BN_free(t1);
return 1;
}
int JPAKE_STEP2_process(JPAKE_CTX *ctx, const JPAKE_STEP2 *received)
{
BIGNUM *t1 = BN_new();
BIGNUM *t2 = BN_new();
int ret = 0;
BN_mod_add(t1, ctx->xa, ctx->xb, ctx->p.q, ctx->ctx);
BN_mod_exp(t2, ctx->p.g, t1, ctx->p.p, ctx->ctx);
BN_mod_mul(t1, ctx->p.gxc, t2, ctx->p.p, ctx->ctx);
if (verify_zkp(received, t1, ctx))
ret = 1;
else
JPAKEerr(JPAKE_F_JPAKE_STEP2_PROCESS, JPAKE_R_VERIFY_B_FAILED);
compute_key(ctx, received->gx);
BN_free(t2);
BN_free(t1);
return ret;
}
static void quickhashbn(unsigned char *md, const BIGNUM *bn)
{
SHA_CTX sha;
SHA1_Init(&sha);
hashbn(&sha, bn);
SHA1_Final(md, &sha);
}
void JPAKE_STEP3A_init(JPAKE_STEP3A *s3a)
{
}
int JPAKE_STEP3A_generate(JPAKE_STEP3A *send, JPAKE_CTX *ctx)
{
quickhashbn(send->hhk, ctx->key);
SHA1(send->hhk, sizeof send->hhk, send->hhk);
return 1;
}
int JPAKE_STEP3A_process(JPAKE_CTX *ctx, const JPAKE_STEP3A *received)
{
unsigned char hhk[SHA_DIGEST_LENGTH];
quickhashbn(hhk, ctx->key);
SHA1(hhk, sizeof hhk, hhk);
if (memcmp(hhk, received->hhk, sizeof hhk)) {
JPAKEerr(JPAKE_F_JPAKE_STEP3A_PROCESS,
JPAKE_R_HASH_OF_HASH_OF_KEY_MISMATCH);
return 0;
}
return 1;
}
void JPAKE_STEP3A_release(JPAKE_STEP3A *s3a)
{
}
void JPAKE_STEP3B_init(JPAKE_STEP3B *s3b)
{
}
int JPAKE_STEP3B_generate(JPAKE_STEP3B *send, JPAKE_CTX *ctx)
{
quickhashbn(send->hk, ctx->key);
return 1;
}
int JPAKE_STEP3B_process(JPAKE_CTX *ctx, const JPAKE_STEP3B *received)
{
unsigned char hk[SHA_DIGEST_LENGTH];
quickhashbn(hk, ctx->key);
if (memcmp(hk, received->hk, sizeof hk)) {
JPAKEerr(JPAKE_F_JPAKE_STEP3B_PROCESS, JPAKE_R_HASH_OF_KEY_MISMATCH);
return 0;
}
return 1;
}
void JPAKE_STEP3B_release(JPAKE_STEP3B *s3b)
{
}
const BIGNUM *JPAKE_get_shared_key(JPAKE_CTX *ctx)
{
return ctx->key;
}
