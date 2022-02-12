static unsigned char conv_ascii2bin(unsigned char a)
{
if (a & 0x80)
return B64_ERROR;
return data_ascii2bin[a];
}
static unsigned char conv_ascii2bin(unsigned char a)
{
a = os_toascii[a];
if (a & 0x80)
return B64_ERROR;
return data_ascii2bin[a];
}
EVP_ENCODE_CTX *EVP_ENCODE_CTX_new(void)
{
return OPENSSL_zalloc(sizeof(EVP_ENCODE_CTX));
}
void EVP_ENCODE_CTX_free(EVP_ENCODE_CTX *ctx)
{
OPENSSL_free(ctx);
}
int EVP_ENCODE_CTX_copy(EVP_ENCODE_CTX *dctx, EVP_ENCODE_CTX *sctx)
{
memcpy(dctx, sctx, sizeof(EVP_ENCODE_CTX));
return 1;
}
int EVP_ENCODE_CTX_num(EVP_ENCODE_CTX *ctx)
{
return ctx->num;
}
void EVP_EncodeInit(EVP_ENCODE_CTX *ctx)
{
ctx->length = 48;
ctx->num = 0;
ctx->line_num = 0;
}
int EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl,
const unsigned char *in, int inl)
{
int i, j;
size_t total = 0;
*outl = 0;
if (inl <= 0)
return 0;
OPENSSL_assert(ctx->length <= (int)sizeof(ctx->enc_data));
if (ctx->length - ctx->num > inl) {
memcpy(&(ctx->enc_data[ctx->num]), in, inl);
ctx->num += inl;
return 1;
}
if (ctx->num != 0) {
i = ctx->length - ctx->num;
memcpy(&(ctx->enc_data[ctx->num]), in, i);
in += i;
inl -= i;
j = EVP_EncodeBlock(out, ctx->enc_data, ctx->length);
ctx->num = 0;
out += j;
*(out++) = '\n';
*out = '\0';
total = j + 1;
}
while (inl >= ctx->length && total <= INT_MAX) {
j = EVP_EncodeBlock(out, in, ctx->length);
in += ctx->length;
inl -= ctx->length;
out += j;
*(out++) = '\n';
*out = '\0';
total += j + 1;
}
if (total > INT_MAX) {
*outl = 0;
return 0;
}
if (inl != 0)
memcpy(&(ctx->enc_data[0]), in, inl);
ctx->num = inl;
*outl = total;
return 1;
}
void EVP_EncodeFinal(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl)
{
unsigned int ret = 0;
if (ctx->num != 0) {
ret = EVP_EncodeBlock(out, ctx->enc_data, ctx->num);
out[ret++] = '\n';
out[ret] = '\0';
ctx->num = 0;
}
*outl = ret;
}
int EVP_EncodeBlock(unsigned char *t, const unsigned char *f, int dlen)
{
int i, ret = 0;
unsigned long l;
for (i = dlen; i > 0; i -= 3) {
if (i >= 3) {
l = (((unsigned long)f[0]) << 16L) |
(((unsigned long)f[1]) << 8L) | f[2];
*(t++) = conv_bin2ascii(l >> 18L);
*(t++) = conv_bin2ascii(l >> 12L);
*(t++) = conv_bin2ascii(l >> 6L);
*(t++) = conv_bin2ascii(l);
} else {
l = ((unsigned long)f[0]) << 16L;
if (i == 2)
l |= ((unsigned long)f[1] << 8L);
*(t++) = conv_bin2ascii(l >> 18L);
*(t++) = conv_bin2ascii(l >> 12L);
*(t++) = (i == 1) ? '=' : conv_bin2ascii(l >> 6L);
*(t++) = '=';
}
ret += 4;
f += 3;
}
*t = '\0';
return (ret);
}
void EVP_DecodeInit(EVP_ENCODE_CTX *ctx)
{
ctx->num = 0;
ctx->length = 0;
ctx->line_num = 0;
ctx->expect_nl = 0;
}
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl,
const unsigned char *in, int inl)
{
int seof = 0, eof = 0, rv = -1, ret = 0, i, v, tmp, n, decoded_len;
unsigned char *d;
n = ctx->num;
d = ctx->enc_data;
if (n > 0 && d[n - 1] == '=') {
eof++;
if (n > 1 && d[n - 2] == '=')
eof++;
}
if (inl == 0) {
rv = 0;
goto end;
}
for (i = 0; i < inl; i++) {
tmp = *(in++);
v = conv_ascii2bin(tmp);
if (v == B64_ERROR) {
rv = -1;
goto end;
}
if (tmp == '=') {
eof++;
} else if (eof > 0 && B64_BASE64(v)) {
rv = -1;
goto end;
}
if (eof > 2) {
rv = -1;
goto end;
}
if (v == B64_EOF) {
seof = 1;
goto tail;
}
if (B64_BASE64(v)) {
if (n >= 64) {
rv = -1;
goto end;
}
OPENSSL_assert(n < (int)sizeof(ctx->enc_data));
d[n++] = tmp;
}
if (n == 64) {
decoded_len = EVP_DecodeBlock(out, d, n);
n = 0;
if (decoded_len < 0 || eof > decoded_len) {
rv = -1;
goto end;
}
ret += decoded_len - eof;
out += decoded_len - eof;
}
}
tail:
if (n > 0) {
if ((n & 3) == 0) {
decoded_len = EVP_DecodeBlock(out, d, n);
n = 0;
if (decoded_len < 0 || eof > decoded_len) {
rv = -1;
goto end;
}
ret += (decoded_len - eof);
} else if (seof) {
rv = -1;
goto end;
}
}
rv = seof || (n == 0 && eof) ? 0 : 1;
end:
*outl = ret;
ctx->num = n;
return (rv);
}
int EVP_DecodeBlock(unsigned char *t, const unsigned char *f, int n)
{
int i, ret = 0, a, b, c, d;
unsigned long l;
while ((conv_ascii2bin(*f) == B64_WS) && (n > 0)) {
f++;
n--;
}
while ((n > 3) && (B64_NOT_BASE64(conv_ascii2bin(f[n - 1]))))
n--;
if (n % 4 != 0)
return (-1);
for (i = 0; i < n; i += 4) {
a = conv_ascii2bin(*(f++));
b = conv_ascii2bin(*(f++));
c = conv_ascii2bin(*(f++));
d = conv_ascii2bin(*(f++));
if ((a & 0x80) || (b & 0x80) || (c & 0x80) || (d & 0x80))
return (-1);
l = ((((unsigned long)a) << 18L) |
(((unsigned long)b) << 12L) |
(((unsigned long)c) << 6L) | (((unsigned long)d)));
*(t++) = (unsigned char)(l >> 16L) & 0xff;
*(t++) = (unsigned char)(l >> 8L) & 0xff;
*(t++) = (unsigned char)(l) & 0xff;
ret += 3;
}
return (ret);
}
int EVP_DecodeFinal(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl)
{
int i;
*outl = 0;
if (ctx->num != 0) {
i = EVP_DecodeBlock(out, ctx->enc_data, ctx->num);
if (i < 0)
return (-1);
ctx->num = 0;
*outl = i;
return (1);
} else
return (1);
}
