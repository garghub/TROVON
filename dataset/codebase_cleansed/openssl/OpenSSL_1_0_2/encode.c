void EVP_EncodeInit(EVP_ENCODE_CTX *ctx)
{
ctx->length = 48;
ctx->num = 0;
ctx->line_num = 0;
}
void EVP_EncodeUpdate(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl,
const unsigned char *in, int inl)
{
int i, j;
unsigned int total = 0;
*outl = 0;
if (inl == 0)
return;
OPENSSL_assert(ctx->length <= (int)sizeof(ctx->enc_data));
if ((ctx->num + inl) < ctx->length) {
memcpy(&(ctx->enc_data[ctx->num]), in, inl);
ctx->num += inl;
return;
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
while (inl >= ctx->length) {
j = EVP_EncodeBlock(out, in, ctx->length);
in += ctx->length;
inl -= ctx->length;
out += j;
*(out++) = '\n';
*out = '\0';
total += j + 1;
}
if (inl != 0)
memcpy(&(ctx->enc_data[0]), in, inl);
ctx->num = inl;
*outl = total;
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
ctx->length = 30;
ctx->num = 0;
ctx->line_num = 0;
ctx->expect_nl = 0;
}
int EVP_DecodeUpdate(EVP_ENCODE_CTX *ctx, unsigned char *out, int *outl,
const unsigned char *in, int inl)
{
int seof = -1, eof = 0, rv = -1, ret = 0, i, v, tmp, n, ln, exp_nl;
unsigned char *d;
n = ctx->num;
d = ctx->enc_data;
ln = ctx->line_num;
exp_nl = ctx->expect_nl;
if ((inl == 0) || ((n == 0) && (conv_ascii2bin(in[0]) == B64_EOF))) {
rv = 0;
goto end;
}
for (i = 0; i < inl; i++) {
if (ln >= 80) {
rv = -1;
goto end;
}
tmp = *(in++);
v = conv_ascii2bin(tmp);
if (!B64_NOT_BASE64(v)) {
OPENSSL_assert(n < (int)sizeof(ctx->enc_data));
d[n++] = tmp;
ln++;
} else if (v == B64_ERROR) {
rv = -1;
goto end;
}
if (tmp == '=') {
if (seof == -1)
seof = n;
eof++;
}
if (v == B64_CR) {
ln = 0;
if (exp_nl)
continue;
}
if (v == B64_EOLN) {
ln = 0;
if (exp_nl) {
exp_nl = 0;
continue;
}
}
exp_nl = 0;
if (((i + 1) == inl) && (((n & 3) == 0) || eof)) {
v = B64_EOF;
eof = 0;
if (d[n - 1] == '=')
eof++;
if (d[n - 2] == '=')
eof++;
}
if ((v == B64_EOF && (n & 3) == 0) || (n >= 64)) {
if ((v != B64_EOF) && (n >= 64))
exp_nl = 1;
if (n > 0) {
v = EVP_DecodeBlock(out, d, n);
n = 0;
if (v < 0) {
rv = 0;
goto end;
}
if (eof > v) {
rv = -1;
goto end;
}
ret += (v - eof);
} else {
eof = 1;
v = 0;
}
if ((v < ctx->length) && eof) {
rv = 0;
goto end;
} else
ctx->length = v;
if (seof >= 0) {
rv = 0;
goto end;
}
out += v;
}
}
rv = 1;
end:
*outl = ret;
ctx->num = n;
ctx->line_num = ln;
ctx->expect_nl = exp_nl;
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
int EVP_DecodeValid(unsigned char *buf, int len)
{
int i, num = 0, bad = 0;
if (len == 0)
return (-1);
while (conv_ascii2bin(*buf) == B64_WS) {
buf++;
len--;
if (len == 0)
return (-1);
}
for (i = len; i >= 4; i -= 4) {
if ((conv_ascii2bin(buf[0]) >= 0x40) ||
(conv_ascii2bin(buf[1]) >= 0x40) ||
(conv_ascii2bin(buf[2]) >= 0x40) ||
(conv_ascii2bin(buf[3]) >= 0x40))
return (-1);
buf += 4;
num += 1 + (buf[2] != '=') + (buf[3] != '=');
}
if ((i == 1) && (conv_ascii2bin(buf[0]) == B64_EOLN))
return (num);
if ((i == 2) && (conv_ascii2bin(buf[0]) == B64_EOLN) &&
(conv_ascii2bin(buf[0]) == B64_EOLN))
return (num);
return (1);
}
