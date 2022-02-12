int skein_256_init(struct skein_256_ctx *ctx, size_t hash_bit_len)
{
union {
u8 b[SKEIN_256_STATE_BYTES];
u64 w[SKEIN_256_STATE_WORDS];
} cfg;
skein_assert_ret(hash_bit_len > 0, SKEIN_BAD_HASHLEN);
ctx->h.hash_bit_len = hash_bit_len;
switch (hash_bit_len) {
case 256:
memcpy(ctx->x, SKEIN_256_IV_256, sizeof(ctx->x));
break;
case 224:
memcpy(ctx->x, SKEIN_256_IV_224, sizeof(ctx->x));
break;
case 160:
memcpy(ctx->x, SKEIN_256_IV_160, sizeof(ctx->x));
break;
case 128:
memcpy(ctx->x, SKEIN_256_IV_128, sizeof(ctx->x));
break;
default:
skein_start_new_type(ctx, CFG_FINAL);
cfg.w[0] = skein_swap64(SKEIN_SCHEMA_VER);
cfg.w[1] = skein_swap64(hash_bit_len);
cfg.w[2] = skein_swap64(SKEIN_CFG_TREE_INFO_SEQUENTIAL);
memset(&cfg.w[3], 0, sizeof(cfg) - 3*sizeof(cfg.w[0]));
memset(ctx->x, 0, sizeof(ctx->x));
skein_256_process_block(ctx, cfg.b, 1, SKEIN_CFG_STR_LEN);
break;
}
skein_start_new_type(ctx, MSG);
return SKEIN_SUCCESS;
}
int skein_256_init_ext(struct skein_256_ctx *ctx, size_t hash_bit_len,
u64 tree_info, const u8 *key, size_t key_bytes)
{
union {
u8 b[SKEIN_256_STATE_BYTES];
u64 w[SKEIN_256_STATE_WORDS];
} cfg;
skein_assert_ret(hash_bit_len > 0, SKEIN_BAD_HASHLEN);
skein_assert_ret(key_bytes == 0 || key, SKEIN_FAIL);
if (key_bytes == 0) {
memset(ctx->x, 0, sizeof(ctx->x));
} else {
skein_assert(sizeof(cfg.b) >= sizeof(ctx->x));
ctx->h.hash_bit_len = 8*sizeof(ctx->x);
skein_start_new_type(ctx, KEY);
memset(ctx->x, 0, sizeof(ctx->x));
skein_256_update(ctx, key, key_bytes);
skein_256_final_pad(ctx, cfg.b);
memcpy(ctx->x, cfg.b, sizeof(cfg.b));
}
ctx->h.hash_bit_len = hash_bit_len;
skein_start_new_type(ctx, CFG_FINAL);
memset(&cfg.w, 0, sizeof(cfg.w));
cfg.w[0] = skein_swap64(SKEIN_SCHEMA_VER);
cfg.w[1] = skein_swap64(hash_bit_len);
cfg.w[2] = skein_swap64(tree_info);
skein_256_process_block(ctx, cfg.b, 1, SKEIN_CFG_STR_LEN);
skein_start_new_type(ctx, MSG);
return SKEIN_SUCCESS;
}
int skein_256_update(struct skein_256_ctx *ctx, const u8 *msg,
size_t msg_byte_cnt)
{
size_t n;
skein_assert_ret(ctx->h.b_cnt <= SKEIN_256_BLOCK_BYTES, SKEIN_FAIL);
if (msg_byte_cnt + ctx->h.b_cnt > SKEIN_256_BLOCK_BYTES) {
if (ctx->h.b_cnt) {
n = SKEIN_256_BLOCK_BYTES - ctx->h.b_cnt;
if (n) {
skein_assert(n < msg_byte_cnt);
memcpy(&ctx->b[ctx->h.b_cnt], msg, n);
msg_byte_cnt -= n;
msg += n;
ctx->h.b_cnt += n;
}
skein_assert(ctx->h.b_cnt == SKEIN_256_BLOCK_BYTES);
skein_256_process_block(ctx, ctx->b, 1,
SKEIN_256_BLOCK_BYTES);
ctx->h.b_cnt = 0;
}
if (msg_byte_cnt > SKEIN_256_BLOCK_BYTES) {
n = (msg_byte_cnt-1) / SKEIN_256_BLOCK_BYTES;
skein_256_process_block(ctx, msg, n,
SKEIN_256_BLOCK_BYTES);
msg_byte_cnt -= n * SKEIN_256_BLOCK_BYTES;
msg += n * SKEIN_256_BLOCK_BYTES;
}
skein_assert(ctx->h.b_cnt == 0);
}
if (msg_byte_cnt) {
skein_assert(msg_byte_cnt + ctx->h.b_cnt <=
SKEIN_256_BLOCK_BYTES);
memcpy(&ctx->b[ctx->h.b_cnt], msg, msg_byte_cnt);
ctx->h.b_cnt += msg_byte_cnt;
}
return SKEIN_SUCCESS;
}
int skein_256_final(struct skein_256_ctx *ctx, u8 *hash_val)
{
size_t i, n, byte_cnt;
u64 x[SKEIN_256_STATE_WORDS];
skein_assert_ret(ctx->h.b_cnt <= SKEIN_256_BLOCK_BYTES, SKEIN_FAIL);
ctx->h.tweak[1] |= SKEIN_T1_FLAG_FINAL;
if (ctx->h.b_cnt < SKEIN_256_BLOCK_BYTES)
memset(&ctx->b[ctx->h.b_cnt], 0,
SKEIN_256_BLOCK_BYTES - ctx->h.b_cnt);
skein_256_process_block(ctx, ctx->b, 1, ctx->h.b_cnt);
byte_cnt = (ctx->h.hash_bit_len + 7) >> 3;
memset(ctx->b, 0, sizeof(ctx->b));
memcpy(x, ctx->x, sizeof(x));
for (i = 0; i*SKEIN_256_BLOCK_BYTES < byte_cnt; i++) {
((u64 *)ctx->b)[0] = skein_swap64((u64) i);
skein_start_new_type(ctx, OUT_FINAL);
skein_256_process_block(ctx, ctx->b, 1, sizeof(u64));
n = byte_cnt - i*SKEIN_256_BLOCK_BYTES;
if (n >= SKEIN_256_BLOCK_BYTES)
n = SKEIN_256_BLOCK_BYTES;
skein_put64_lsb_first(hash_val+i*SKEIN_256_BLOCK_BYTES, ctx->x,
n);
memcpy(ctx->x, x, sizeof(x));
}
return SKEIN_SUCCESS;
}
int skein_512_init(struct skein_512_ctx *ctx, size_t hash_bit_len)
{
union {
u8 b[SKEIN_512_STATE_BYTES];
u64 w[SKEIN_512_STATE_WORDS];
} cfg;
skein_assert_ret(hash_bit_len > 0, SKEIN_BAD_HASHLEN);
ctx->h.hash_bit_len = hash_bit_len;
switch (hash_bit_len) {
case 512:
memcpy(ctx->x, SKEIN_512_IV_512, sizeof(ctx->x));
break;
case 384:
memcpy(ctx->x, SKEIN_512_IV_384, sizeof(ctx->x));
break;
case 256:
memcpy(ctx->x, SKEIN_512_IV_256, sizeof(ctx->x));
break;
case 224:
memcpy(ctx->x, SKEIN_512_IV_224, sizeof(ctx->x));
break;
default:
skein_start_new_type(ctx, CFG_FINAL);
cfg.w[0] = skein_swap64(SKEIN_SCHEMA_VER);
cfg.w[1] = skein_swap64(hash_bit_len);
cfg.w[2] = skein_swap64(SKEIN_CFG_TREE_INFO_SEQUENTIAL);
memset(&cfg.w[3], 0, sizeof(cfg) - 3*sizeof(cfg.w[0]));
memset(ctx->x, 0, sizeof(ctx->x));
skein_512_process_block(ctx, cfg.b, 1, SKEIN_CFG_STR_LEN);
break;
}
skein_start_new_type(ctx, MSG);
return SKEIN_SUCCESS;
}
int skein_512_init_ext(struct skein_512_ctx *ctx, size_t hash_bit_len,
u64 tree_info, const u8 *key, size_t key_bytes)
{
union {
u8 b[SKEIN_512_STATE_BYTES];
u64 w[SKEIN_512_STATE_WORDS];
} cfg;
skein_assert_ret(hash_bit_len > 0, SKEIN_BAD_HASHLEN);
skein_assert_ret(key_bytes == 0 || key, SKEIN_FAIL);
if (key_bytes == 0) {
memset(ctx->x, 0, sizeof(ctx->x));
} else {
skein_assert(sizeof(cfg.b) >= sizeof(ctx->x));
ctx->h.hash_bit_len = 8*sizeof(ctx->x);
skein_start_new_type(ctx, KEY);
memset(ctx->x, 0, sizeof(ctx->x));
skein_512_update(ctx, key, key_bytes);
skein_512_final_pad(ctx, cfg.b);
memcpy(ctx->x, cfg.b, sizeof(cfg.b));
}
ctx->h.hash_bit_len = hash_bit_len;
skein_start_new_type(ctx, CFG_FINAL);
memset(&cfg.w, 0, sizeof(cfg.w));
cfg.w[0] = skein_swap64(SKEIN_SCHEMA_VER);
cfg.w[1] = skein_swap64(hash_bit_len);
cfg.w[2] = skein_swap64(tree_info);
skein_512_process_block(ctx, cfg.b, 1, SKEIN_CFG_STR_LEN);
skein_start_new_type(ctx, MSG);
return SKEIN_SUCCESS;
}
int skein_512_update(struct skein_512_ctx *ctx, const u8 *msg,
size_t msg_byte_cnt)
{
size_t n;
skein_assert_ret(ctx->h.b_cnt <= SKEIN_512_BLOCK_BYTES, SKEIN_FAIL);
if (msg_byte_cnt + ctx->h.b_cnt > SKEIN_512_BLOCK_BYTES) {
if (ctx->h.b_cnt) {
n = SKEIN_512_BLOCK_BYTES - ctx->h.b_cnt;
if (n) {
skein_assert(n < msg_byte_cnt);
memcpy(&ctx->b[ctx->h.b_cnt], msg, n);
msg_byte_cnt -= n;
msg += n;
ctx->h.b_cnt += n;
}
skein_assert(ctx->h.b_cnt == SKEIN_512_BLOCK_BYTES);
skein_512_process_block(ctx, ctx->b, 1,
SKEIN_512_BLOCK_BYTES);
ctx->h.b_cnt = 0;
}
if (msg_byte_cnt > SKEIN_512_BLOCK_BYTES) {
n = (msg_byte_cnt-1) / SKEIN_512_BLOCK_BYTES;
skein_512_process_block(ctx, msg, n,
SKEIN_512_BLOCK_BYTES);
msg_byte_cnt -= n * SKEIN_512_BLOCK_BYTES;
msg += n * SKEIN_512_BLOCK_BYTES;
}
skein_assert(ctx->h.b_cnt == 0);
}
if (msg_byte_cnt) {
skein_assert(msg_byte_cnt + ctx->h.b_cnt <=
SKEIN_512_BLOCK_BYTES);
memcpy(&ctx->b[ctx->h.b_cnt], msg, msg_byte_cnt);
ctx->h.b_cnt += msg_byte_cnt;
}
return SKEIN_SUCCESS;
}
int skein_512_final(struct skein_512_ctx *ctx, u8 *hash_val)
{
size_t i, n, byte_cnt;
u64 x[SKEIN_512_STATE_WORDS];
skein_assert_ret(ctx->h.b_cnt <= SKEIN_512_BLOCK_BYTES, SKEIN_FAIL);
ctx->h.tweak[1] |= SKEIN_T1_FLAG_FINAL;
if (ctx->h.b_cnt < SKEIN_512_BLOCK_BYTES)
memset(&ctx->b[ctx->h.b_cnt], 0,
SKEIN_512_BLOCK_BYTES - ctx->h.b_cnt);
skein_512_process_block(ctx, ctx->b, 1, ctx->h.b_cnt);
byte_cnt = (ctx->h.hash_bit_len + 7) >> 3;
memset(ctx->b, 0, sizeof(ctx->b));
memcpy(x, ctx->x, sizeof(x));
for (i = 0; i*SKEIN_512_BLOCK_BYTES < byte_cnt; i++) {
((u64 *)ctx->b)[0] = skein_swap64((u64) i);
skein_start_new_type(ctx, OUT_FINAL);
skein_512_process_block(ctx, ctx->b, 1, sizeof(u64));
n = byte_cnt - i*SKEIN_512_BLOCK_BYTES;
if (n >= SKEIN_512_BLOCK_BYTES)
n = SKEIN_512_BLOCK_BYTES;
skein_put64_lsb_first(hash_val+i*SKEIN_512_BLOCK_BYTES, ctx->x,
n);
memcpy(ctx->x, x, sizeof(x));
}
return SKEIN_SUCCESS;
}
int skein_1024_init(struct skein_1024_ctx *ctx, size_t hash_bit_len)
{
union {
u8 b[SKEIN_1024_STATE_BYTES];
u64 w[SKEIN_1024_STATE_WORDS];
} cfg;
skein_assert_ret(hash_bit_len > 0, SKEIN_BAD_HASHLEN);
ctx->h.hash_bit_len = hash_bit_len;
switch (hash_bit_len) {
case 512:
memcpy(ctx->x, SKEIN_1024_IV_512, sizeof(ctx->x));
break;
case 384:
memcpy(ctx->x, SKEIN_1024_IV_384, sizeof(ctx->x));
break;
case 1024:
memcpy(ctx->x, SKEIN_1024_IV_1024, sizeof(ctx->x));
break;
default:
skein_start_new_type(ctx, CFG_FINAL);
cfg.w[0] = skein_swap64(SKEIN_SCHEMA_VER);
cfg.w[1] = skein_swap64(hash_bit_len);
cfg.w[2] = skein_swap64(SKEIN_CFG_TREE_INFO_SEQUENTIAL);
memset(&cfg.w[3], 0, sizeof(cfg) - 3*sizeof(cfg.w[0]));
memset(ctx->x, 0, sizeof(ctx->x));
skein_1024_process_block(ctx, cfg.b, 1, SKEIN_CFG_STR_LEN);
break;
}
skein_start_new_type(ctx, MSG);
return SKEIN_SUCCESS;
}
int skein_1024_init_ext(struct skein_1024_ctx *ctx, size_t hash_bit_len,
u64 tree_info, const u8 *key, size_t key_bytes)
{
union {
u8 b[SKEIN_1024_STATE_BYTES];
u64 w[SKEIN_1024_STATE_WORDS];
} cfg;
skein_assert_ret(hash_bit_len > 0, SKEIN_BAD_HASHLEN);
skein_assert_ret(key_bytes == 0 || key, SKEIN_FAIL);
if (key_bytes == 0) {
memset(ctx->x, 0, sizeof(ctx->x));
} else {
skein_assert(sizeof(cfg.b) >= sizeof(ctx->x));
ctx->h.hash_bit_len = 8*sizeof(ctx->x);
skein_start_new_type(ctx, KEY);
memset(ctx->x, 0, sizeof(ctx->x));
skein_1024_update(ctx, key, key_bytes);
skein_1024_final_pad(ctx, cfg.b);
memcpy(ctx->x, cfg.b, sizeof(cfg.b));
}
ctx->h.hash_bit_len = hash_bit_len;
skein_start_new_type(ctx, CFG_FINAL);
memset(&cfg.w, 0, sizeof(cfg.w));
cfg.w[0] = skein_swap64(SKEIN_SCHEMA_VER);
cfg.w[1] = skein_swap64(hash_bit_len);
cfg.w[2] = skein_swap64(tree_info);
skein_1024_process_block(ctx, cfg.b, 1, SKEIN_CFG_STR_LEN);
skein_start_new_type(ctx, MSG);
return SKEIN_SUCCESS;
}
int skein_1024_update(struct skein_1024_ctx *ctx, const u8 *msg,
size_t msg_byte_cnt)
{
size_t n;
skein_assert_ret(ctx->h.b_cnt <= SKEIN_1024_BLOCK_BYTES, SKEIN_FAIL);
if (msg_byte_cnt + ctx->h.b_cnt > SKEIN_1024_BLOCK_BYTES) {
if (ctx->h.b_cnt) {
n = SKEIN_1024_BLOCK_BYTES - ctx->h.b_cnt;
if (n) {
skein_assert(n < msg_byte_cnt);
memcpy(&ctx->b[ctx->h.b_cnt], msg, n);
msg_byte_cnt -= n;
msg += n;
ctx->h.b_cnt += n;
}
skein_assert(ctx->h.b_cnt == SKEIN_1024_BLOCK_BYTES);
skein_1024_process_block(ctx, ctx->b, 1,
SKEIN_1024_BLOCK_BYTES);
ctx->h.b_cnt = 0;
}
if (msg_byte_cnt > SKEIN_1024_BLOCK_BYTES) {
n = (msg_byte_cnt-1) / SKEIN_1024_BLOCK_BYTES;
skein_1024_process_block(ctx, msg, n,
SKEIN_1024_BLOCK_BYTES);
msg_byte_cnt -= n * SKEIN_1024_BLOCK_BYTES;
msg += n * SKEIN_1024_BLOCK_BYTES;
}
skein_assert(ctx->h.b_cnt == 0);
}
if (msg_byte_cnt) {
skein_assert(msg_byte_cnt + ctx->h.b_cnt <=
SKEIN_1024_BLOCK_BYTES);
memcpy(&ctx->b[ctx->h.b_cnt], msg, msg_byte_cnt);
ctx->h.b_cnt += msg_byte_cnt;
}
return SKEIN_SUCCESS;
}
int skein_1024_final(struct skein_1024_ctx *ctx, u8 *hash_val)
{
size_t i, n, byte_cnt;
u64 x[SKEIN_1024_STATE_WORDS];
skein_assert_ret(ctx->h.b_cnt <= SKEIN_1024_BLOCK_BYTES, SKEIN_FAIL);
ctx->h.tweak[1] |= SKEIN_T1_FLAG_FINAL;
if (ctx->h.b_cnt < SKEIN_1024_BLOCK_BYTES)
memset(&ctx->b[ctx->h.b_cnt], 0,
SKEIN_1024_BLOCK_BYTES - ctx->h.b_cnt);
skein_1024_process_block(ctx, ctx->b, 1, ctx->h.b_cnt);
byte_cnt = (ctx->h.hash_bit_len + 7) >> 3;
memset(ctx->b, 0, sizeof(ctx->b));
memcpy(x, ctx->x, sizeof(x));
for (i = 0; i*SKEIN_1024_BLOCK_BYTES < byte_cnt; i++) {
((u64 *)ctx->b)[0] = skein_swap64((u64) i);
skein_start_new_type(ctx, OUT_FINAL);
skein_1024_process_block(ctx, ctx->b, 1, sizeof(u64));
n = byte_cnt - i*SKEIN_1024_BLOCK_BYTES;
if (n >= SKEIN_1024_BLOCK_BYTES)
n = SKEIN_1024_BLOCK_BYTES;
skein_put64_lsb_first(hash_val+i*SKEIN_1024_BLOCK_BYTES, ctx->x,
n);
memcpy(ctx->x, x, sizeof(x));
}
return SKEIN_SUCCESS;
}
int skein_256_final_pad(struct skein_256_ctx *ctx, u8 *hash_val)
{
skein_assert_ret(ctx->h.b_cnt <= SKEIN_256_BLOCK_BYTES, SKEIN_FAIL);
ctx->h.tweak[1] |= SKEIN_T1_FLAG_FINAL;
if (ctx->h.b_cnt < SKEIN_256_BLOCK_BYTES)
memset(&ctx->b[ctx->h.b_cnt], 0,
SKEIN_256_BLOCK_BYTES - ctx->h.b_cnt);
skein_256_process_block(ctx, ctx->b, 1, ctx->h.b_cnt);
skein_put64_lsb_first(hash_val, ctx->x, SKEIN_256_BLOCK_BYTES);
return SKEIN_SUCCESS;
}
int skein_512_final_pad(struct skein_512_ctx *ctx, u8 *hash_val)
{
skein_assert_ret(ctx->h.b_cnt <= SKEIN_512_BLOCK_BYTES, SKEIN_FAIL);
ctx->h.tweak[1] |= SKEIN_T1_FLAG_FINAL;
if (ctx->h.b_cnt < SKEIN_512_BLOCK_BYTES)
memset(&ctx->b[ctx->h.b_cnt], 0,
SKEIN_512_BLOCK_BYTES - ctx->h.b_cnt);
skein_512_process_block(ctx, ctx->b, 1, ctx->h.b_cnt);
skein_put64_lsb_first(hash_val, ctx->x, SKEIN_512_BLOCK_BYTES);
return SKEIN_SUCCESS;
}
int skein_1024_final_pad(struct skein_1024_ctx *ctx, u8 *hash_val)
{
skein_assert_ret(ctx->h.b_cnt <= SKEIN_1024_BLOCK_BYTES, SKEIN_FAIL);
ctx->h.tweak[1] |= SKEIN_T1_FLAG_FINAL;
if (ctx->h.b_cnt < SKEIN_1024_BLOCK_BYTES)
memset(&ctx->b[ctx->h.b_cnt], 0,
SKEIN_1024_BLOCK_BYTES - ctx->h.b_cnt);
skein_1024_process_block(ctx, ctx->b, 1, ctx->h.b_cnt);
skein_put64_lsb_first(hash_val, ctx->x, SKEIN_1024_BLOCK_BYTES);
return SKEIN_SUCCESS;
}
int skein_256_output(struct skein_256_ctx *ctx, u8 *hash_val)
{
size_t i, n, byte_cnt;
u64 x[SKEIN_256_STATE_WORDS];
skein_assert_ret(ctx->h.b_cnt <= SKEIN_256_BLOCK_BYTES, SKEIN_FAIL);
byte_cnt = (ctx->h.hash_bit_len + 7) >> 3;
memset(ctx->b, 0, sizeof(ctx->b));
memcpy(x, ctx->x, sizeof(x));
for (i = 0; i*SKEIN_256_BLOCK_BYTES < byte_cnt; i++) {
((u64 *)ctx->b)[0] = skein_swap64((u64) i);
skein_start_new_type(ctx, OUT_FINAL);
skein_256_process_block(ctx, ctx->b, 1, sizeof(u64));
n = byte_cnt - i*SKEIN_256_BLOCK_BYTES;
if (n >= SKEIN_256_BLOCK_BYTES)
n = SKEIN_256_BLOCK_BYTES;
skein_put64_lsb_first(hash_val+i*SKEIN_256_BLOCK_BYTES, ctx->x,
n);
memcpy(ctx->x, x, sizeof(x));
}
return SKEIN_SUCCESS;
}
int skein_512_output(struct skein_512_ctx *ctx, u8 *hash_val)
{
size_t i, n, byte_cnt;
u64 x[SKEIN_512_STATE_WORDS];
skein_assert_ret(ctx->h.b_cnt <= SKEIN_512_BLOCK_BYTES, SKEIN_FAIL);
byte_cnt = (ctx->h.hash_bit_len + 7) >> 3;
memset(ctx->b, 0, sizeof(ctx->b));
memcpy(x, ctx->x, sizeof(x));
for (i = 0; i*SKEIN_512_BLOCK_BYTES < byte_cnt; i++) {
((u64 *)ctx->b)[0] = skein_swap64((u64) i);
skein_start_new_type(ctx, OUT_FINAL);
skein_512_process_block(ctx, ctx->b, 1, sizeof(u64));
n = byte_cnt - i*SKEIN_512_BLOCK_BYTES;
if (n >= SKEIN_512_BLOCK_BYTES)
n = SKEIN_512_BLOCK_BYTES;
skein_put64_lsb_first(hash_val+i*SKEIN_512_BLOCK_BYTES, ctx->x,
n);
memcpy(ctx->x, x, sizeof(x));
}
return SKEIN_SUCCESS;
}
int skein_1024_output(struct skein_1024_ctx *ctx, u8 *hash_val)
{
size_t i, n, byte_cnt;
u64 x[SKEIN_1024_STATE_WORDS];
skein_assert_ret(ctx->h.b_cnt <= SKEIN_1024_BLOCK_BYTES, SKEIN_FAIL);
byte_cnt = (ctx->h.hash_bit_len + 7) >> 3;
memset(ctx->b, 0, sizeof(ctx->b));
memcpy(x, ctx->x, sizeof(x));
for (i = 0; i*SKEIN_1024_BLOCK_BYTES < byte_cnt; i++) {
((u64 *)ctx->b)[0] = skein_swap64((u64) i);
skein_start_new_type(ctx, OUT_FINAL);
skein_1024_process_block(ctx, ctx->b, 1, sizeof(u64));
n = byte_cnt - i*SKEIN_1024_BLOCK_BYTES;
if (n >= SKEIN_1024_BLOCK_BYTES)
n = SKEIN_1024_BLOCK_BYTES;
skein_put64_lsb_first(hash_val+i*SKEIN_1024_BLOCK_BYTES, ctx->x,
n);
memcpy(ctx->x, x, sizeof(x));
}
return SKEIN_SUCCESS;
}
