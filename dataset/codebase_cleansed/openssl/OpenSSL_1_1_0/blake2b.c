static ossl_inline void blake2b_set_lastblock(BLAKE2B_CTX *S)
{
S->f[0] = -1;
}
static ossl_inline void blake2b_init0(BLAKE2B_CTX *S)
{
int i;
memset(S, 0, sizeof(BLAKE2B_CTX));
for (i = 0; i < 8; ++i) {
S->h[i] = blake2b_IV[i];
}
}
static void blake2b_init_param(BLAKE2B_CTX *S, const BLAKE2B_PARAM *P)
{
size_t i;
const uint8_t *p = (const uint8_t *)(P);
blake2b_init0(S);
assert(sizeof(BLAKE2B_PARAM) == 64);
for (i = 0; i < 8; ++i) {
S->h[i] ^= load64(p + sizeof(S->h[i]) * i);
}
}
int BLAKE2b_Init(BLAKE2B_CTX *c)
{
BLAKE2B_PARAM P[1];
P->digest_length = BLAKE2B_DIGEST_LENGTH;
P->key_length = 0;
P->fanout = 1;
P->depth = 1;
store32(P->leaf_length, 0);
store64(P->node_offset, 0);
P->node_depth = 0;
P->inner_length = 0;
memset(P->reserved, 0, sizeof(P->reserved));
memset(P->salt, 0, sizeof(P->salt));
memset(P->personal, 0, sizeof(P->personal));
blake2b_init_param(c, P);
return 1;
}
static void blake2b_compress(BLAKE2B_CTX *S,
const uint8_t *blocks,
size_t len)
{
uint64_t m[16];
uint64_t v[16];
int i;
size_t increment;
assert(len < BLAKE2B_BLOCKBYTES || len % BLAKE2B_BLOCKBYTES == 0);
increment = len < BLAKE2B_BLOCKBYTES ? len : BLAKE2B_BLOCKBYTES;
for (i = 0; i < 8; ++i) {
v[i] = S->h[i];
}
do {
for (i = 0; i < 16; ++i) {
m[i] = load64(blocks + i * sizeof(m[i]));
}
S->t[0] += increment;
S->t[1] += (S->t[0] < increment);
v[8] = blake2b_IV[0];
v[9] = blake2b_IV[1];
v[10] = blake2b_IV[2];
v[11] = blake2b_IV[3];
v[12] = S->t[0] ^ blake2b_IV[4];
v[13] = S->t[1] ^ blake2b_IV[5];
v[14] = S->f[0] ^ blake2b_IV[6];
v[15] = S->f[1] ^ blake2b_IV[7];
#define G(r,i,a,b,c,d) \
do { \
a = a + b + m[blake2b_sigma[r][2*i+0]]; \
d = rotr64(d ^ a, 32); \
c = c + d; \
b = rotr64(b ^ c, 24); \
a = a + b + m[blake2b_sigma[r][2*i+1]]; \
d = rotr64(d ^ a, 16); \
c = c + d; \
b = rotr64(b ^ c, 63); \
} while (0)
#define ROUND(r) \
do { \
G(r,0,v[ 0],v[ 4],v[ 8],v[12]); \
G(r,1,v[ 1],v[ 5],v[ 9],v[13]); \
G(r,2,v[ 2],v[ 6],v[10],v[14]); \
G(r,3,v[ 3],v[ 7],v[11],v[15]); \
G(r,4,v[ 0],v[ 5],v[10],v[15]); \
G(r,5,v[ 1],v[ 6],v[11],v[12]); \
G(r,6,v[ 2],v[ 7],v[ 8],v[13]); \
G(r,7,v[ 3],v[ 4],v[ 9],v[14]); \
} while (0)
#if defined(OPENSSL_SMALL_FOOTPRINT)
for (i = 0; i < 12; i++) {
ROUND(i);
}
#else
ROUND(0);
ROUND(1);
ROUND(2);
ROUND(3);
ROUND(4);
ROUND(5);
ROUND(6);
ROUND(7);
ROUND(8);
ROUND(9);
ROUND(10);
ROUND(11);
#endif
for (i = 0; i < 8; ++i) {
S->h[i] = v[i] ^= v[i + 8] ^ S->h[i];
}
#undef G
#undef ROUND
blocks += increment;
len -= increment;
} while (len);
}
int BLAKE2b_Update(BLAKE2B_CTX *c, const void *data, size_t datalen)
{
const uint8_t *in = data;
size_t fill;
fill = sizeof(c->buf) - c->buflen;
if (datalen > fill) {
if (c->buflen) {
memcpy(c->buf + c->buflen, in, fill);
blake2b_compress(c, c->buf, BLAKE2B_BLOCKBYTES);
c->buflen = 0;
in += fill;
datalen -= fill;
}
if (datalen > BLAKE2B_BLOCKBYTES) {
size_t stashlen = datalen % BLAKE2B_BLOCKBYTES;
stashlen = stashlen ? stashlen : BLAKE2B_BLOCKBYTES;
datalen -= stashlen;
blake2b_compress(c, in, datalen);
in += datalen;
datalen = stashlen;
}
}
assert(datalen <= BLAKE2B_BLOCKBYTES);
memcpy(c->buf + c->buflen, in, datalen);
c->buflen += datalen;
return 1;
}
int BLAKE2b_Final(unsigned char *md, BLAKE2B_CTX *c)
{
int i;
blake2b_set_lastblock(c);
memset(c->buf + c->buflen, 0, sizeof(c->buf) - c->buflen);
blake2b_compress(c, c->buf, c->buflen);
for (i = 0; i < 8; ++i) {
store64(md + sizeof(c->h[i]) * i, c->h[i]);
}
OPENSSL_cleanse(c, sizeof(BLAKE2B_CTX));
return 1;
}
