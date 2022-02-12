int skein_ctx_prepare(struct skein_ctx *ctx, enum skein_size size)
{
skein_assert_ret(ctx && size, SKEIN_FAIL);
memset(ctx, 0, sizeof(struct skein_ctx));
ctx->skein_size = size;
return SKEIN_SUCCESS;
}
int skein_init(struct skein_ctx *ctx, size_t hash_bit_len)
{
int ret = SKEIN_FAIL;
size_t x_len = 0;
u64 *x = NULL;
u64 tree_info = SKEIN_CFG_TREE_INFO_SEQUENTIAL;
skein_assert_ret(ctx, SKEIN_FAIL);
x = ctx->m.s256.x;
x_len = ctx->skein_size / 8;
switch (ctx->skein_size) {
case SKEIN_256:
ret = skein_256_init_ext(&ctx->m.s256, hash_bit_len,
tree_info, NULL, 0);
break;
case SKEIN_512:
ret = skein_512_init_ext(&ctx->m.s512, hash_bit_len,
tree_info, NULL, 0);
break;
case SKEIN_1024:
ret = skein_1024_init_ext(&ctx->m.s1024, hash_bit_len,
tree_info, NULL, 0);
break;
}
if (ret == SKEIN_SUCCESS) {
memcpy(ctx->x_save, x, x_len);
}
return ret;
}
int skein_mac_init(struct skein_ctx *ctx, const u8 *key, size_t key_len,
size_t hash_bit_len)
{
int ret = SKEIN_FAIL;
u64 *x = NULL;
size_t x_len = 0;
u64 tree_info = SKEIN_CFG_TREE_INFO_SEQUENTIAL;
skein_assert_ret(ctx, SKEIN_FAIL);
x = ctx->m.s256.x;
x_len = ctx->skein_size / 8;
skein_assert_ret(hash_bit_len, SKEIN_BAD_HASHLEN);
switch (ctx->skein_size) {
case SKEIN_256:
ret = skein_256_init_ext(&ctx->m.s256, hash_bit_len,
tree_info,
(const u8 *)key, key_len);
break;
case SKEIN_512:
ret = skein_512_init_ext(&ctx->m.s512, hash_bit_len,
tree_info,
(const u8 *)key, key_len);
break;
case SKEIN_1024:
ret = skein_1024_init_ext(&ctx->m.s1024, hash_bit_len,
tree_info,
(const u8 *)key, key_len);
break;
}
if (ret == SKEIN_SUCCESS) {
memcpy(ctx->x_save, x, x_len);
}
return ret;
}
void skein_reset(struct skein_ctx *ctx)
{
size_t x_len = 0;
u64 *x;
x = ctx->m.s256.x;
x_len = ctx->skein_size / 8;
memcpy(x, ctx->x_save, x_len);
skein_start_new_type(&ctx->m, MSG);
}
int skein_update(struct skein_ctx *ctx, const u8 *msg,
size_t msg_byte_cnt)
{
int ret = SKEIN_FAIL;
skein_assert_ret(ctx, SKEIN_FAIL);
switch (ctx->skein_size) {
case SKEIN_256:
ret = skein_256_update(&ctx->m.s256, (const u8 *)msg,
msg_byte_cnt);
break;
case SKEIN_512:
ret = skein_512_update(&ctx->m.s512, (const u8 *)msg,
msg_byte_cnt);
break;
case SKEIN_1024:
ret = skein_1024_update(&ctx->m.s1024, (const u8 *)msg,
msg_byte_cnt);
break;
}
return ret;
}
int skein_update_bits(struct skein_ctx *ctx, const u8 *msg,
size_t msg_bit_cnt)
{
size_t length;
u8 mask;
u8 *up;
skein_assert_ret((ctx->m.h.T[1] & SKEIN_T1_FLAG_BIT_PAD) == 0 ||
msg_bit_cnt == 0, SKEIN_FAIL);
if ((msg_bit_cnt & 0x7) == 0)
return skein_update(ctx, msg, msg_bit_cnt >> 3);
skein_update(ctx, msg, (msg_bit_cnt >> 3) + 1);
up = (u8 *)ctx->m.s256.x + ctx->skein_size / 8;
skein_set_bit_pad_flag(ctx->m.h);
length = ctx->m.h.b_cnt;
skein_assert(length != 0);
mask = (u8) (1u << (7 - (msg_bit_cnt & 7)));
up[length - 1] = (u8)((up[length - 1] & (0 - mask)) | mask);
return SKEIN_SUCCESS;
}
int skein_final(struct skein_ctx *ctx, u8 *hash)
{
int ret = SKEIN_FAIL;
skein_assert_ret(ctx, SKEIN_FAIL);
switch (ctx->skein_size) {
case SKEIN_256:
ret = skein_256_final(&ctx->m.s256, (u8 *)hash);
break;
case SKEIN_512:
ret = skein_512_final(&ctx->m.s512, (u8 *)hash);
break;
case SKEIN_1024:
ret = skein_1024_final(&ctx->m.s1024, (u8 *)hash);
break;
}
return ret;
}
