void sha256_starts( sha256_context *ctx )
{
ctx->total = 0;
ctx->state[0] = 0x6A09E667UL;
ctx->state[1] = 0xBB67AE85UL;
ctx->state[2] = 0x3C6EF372UL;
ctx->state[3] = 0xA54FF53AUL;
ctx->state[4] = 0x510E527FUL;
ctx->state[5] = 0x9B05688CUL;
ctx->state[6] = 0x1F83D9ABUL;
ctx->state[7] = 0x5BE0CD19UL;
}
static void sha256_process( sha256_context *ctx, const guint8 *data )
{
guint32 i, temp1, temp2, W[64], A, B, C, D, E, F, G, H;
GET_UINT32( W[0], data, 0 );
GET_UINT32( W[1], data, 4 );
GET_UINT32( W[2], data, 8 );
GET_UINT32( W[3], data, 12 );
GET_UINT32( W[4], data, 16 );
GET_UINT32( W[5], data, 20 );
GET_UINT32( W[6], data, 24 );
GET_UINT32( W[7], data, 28 );
GET_UINT32( W[8], data, 32 );
GET_UINT32( W[9], data, 36 );
GET_UINT32( W[10], data, 40 );
GET_UINT32( W[11], data, 44 );
GET_UINT32( W[12], data, 48 );
GET_UINT32( W[13], data, 52 );
GET_UINT32( W[14], data, 56 );
GET_UINT32( W[15], data, 60 );
#define RR(x,n) ((x << (32 - n)) | ((x & 0xFFFFFFFF) >> n))
#define S0(x) (RR(x, 7) ^ RR(x, 18) ^ (x >> 3))
#define S1(x) (RR(x, 17) ^ RR(x, 19) ^ (x >> 10))
for (i = 16; i < 64 ; i++)
{
W[i] = W[i - 16] + S0(W[i - 15]) + W[i - 7] + S1(W[i - 2]);
}
A = ctx->state[0];
B = ctx->state[1];
C = ctx->state[2];
D = ctx->state[3];
E = ctx->state[4];
F = ctx->state[5];
G = ctx->state[6];
H = ctx->state[7];
#undef S0
#undef S1
#define S0(x) (RR(x, 2) ^ RR(x, 13) ^ RR(x, 22))
#define S1(x) (RR(x, 6) ^ RR(x, 11) ^ RR(x, 25))
#define CH(x,y,z) (z ^ (x & (y ^ z)))
#define MAJ(x,y,z) (((x | y) & z) | (x & y))
for (i = 0; i < 64; ++i) {
temp1 = H + S1(E) + CH(E, F, G) + K[i] + W[i];
temp2 = S0(A) + MAJ(A, B, C);
H = G;
G = F;
F = E;
E = D + temp1;
D = C;
C = B;
B = A;
A = temp1 + temp2;
}
ctx->state[0] += A;
ctx->state[1] += B;
ctx->state[2] += C;
ctx->state[3] += D;
ctx->state[4] += E;
ctx->state[5] += F;
ctx->state[6] += G;
ctx->state[7] += H;
}
void sha256_update( sha256_context *ctx, const guint8 *input, guint32 length )
{
guint32 left, fill;
if( ! length ) return;
left = (guint32)(ctx->total % SHA256_BLOCK_SIZE);
fill = SHA256_BLOCK_SIZE - left;
ctx->total += length;
if( left && length >= fill )
{
memcpy( (void *) (ctx->buffer + left),
(const void *) input, fill );
sha256_process( ctx, ctx->buffer );
length -= fill;
input += fill;
left = 0;
}
while( length >= SHA256_BLOCK_SIZE )
{
sha256_process( ctx, input );
length -= SHA256_BLOCK_SIZE;
input += SHA256_BLOCK_SIZE;
}
if( length )
{
memcpy( (void *) (ctx->buffer + left),
(const void *) input, length );
}
}
void sha256_finish( sha256_context *ctx, guint8 digest[SHA256_DIGEST_LEN] )
{
guint32 last, padn;
guint64 total_length;
guint8 msglen[8];
total_length = ctx->total * 8;
last = (guint32)(ctx->total % SHA256_BLOCK_SIZE);
padn = ( last < 56 ) ? ( 56 - last ) : ( 120 - last );
PUT_UINT32( total_length >> 32, msglen, 0 );
PUT_UINT32( total_length, msglen, 4 );
sha256_update( ctx, sha256_padding, padn );
sha256_update( ctx, msglen, 8 );
PUT_UINT32( ctx->state[0], digest, 0 );
PUT_UINT32( ctx->state[1], digest, 4 );
PUT_UINT32( ctx->state[2], digest, 8 );
PUT_UINT32( ctx->state[3], digest, 12 );
PUT_UINT32( ctx->state[4], digest, 16 );
PUT_UINT32( ctx->state[5], digest, 20 );
PUT_UINT32( ctx->state[6], digest, 24 );
PUT_UINT32( ctx->state[7], digest, 28 );
}
void sha256_hmac_starts( sha256_hmac_context *hctx, const guint8 *key, guint32 keylen )
{
guint32 i;
guint8 k_ipad[SHA256_BLOCK_SIZE];
guint8 key_compress[SHA256_DIGEST_LEN];
memset( k_ipad, 0x36, SHA256_BLOCK_SIZE );
memset( hctx->k_opad, 0x5C, SHA256_BLOCK_SIZE );
if (keylen > SHA256_BLOCK_SIZE)
{
sha256_starts( &hctx->ctx );
sha256_update( &hctx->ctx, key, keylen );
sha256_finish( &hctx->ctx, key_compress );
key = key_compress;
keylen = SHA256_DIGEST_LEN;
}
for( i = 0; i < keylen; i++ )
{
k_ipad[i] ^= key[i];
hctx->k_opad[i] ^= key[i];
}
sha256_starts( &hctx->ctx );
sha256_update( &hctx->ctx, k_ipad, SHA256_BLOCK_SIZE );
}
void sha256_hmac_update( sha256_hmac_context *hctx, const guint8 *buf, guint32 buflen )
{
sha256_update( &hctx->ctx, buf, buflen );
}
void sha256_hmac_finish( sha256_hmac_context *hctx, guint8 digest[SHA256_DIGEST_LEN] )
{
guint8 tmpbuf[SHA256_DIGEST_LEN];
sha256_finish( &hctx->ctx, tmpbuf );
sha256_starts( &hctx->ctx );
sha256_update( &hctx->ctx, hctx->k_opad, SHA256_BLOCK_SIZE );
sha256_update( &hctx->ctx, tmpbuf, SHA256_DIGEST_LEN );
sha256_finish( &hctx->ctx, digest );
}
void sha256_hmac( const guint8 *key, guint32 keylen, const guint8 *buf, guint32 buflen,
guint8 digest[SHA256_DIGEST_LEN] )
{
sha256_hmac_context hctx;
sha256_hmac_starts( &hctx, key, keylen );
sha256_hmac_update( &hctx, buf, buflen );
sha256_hmac_finish( &hctx, digest );
}
