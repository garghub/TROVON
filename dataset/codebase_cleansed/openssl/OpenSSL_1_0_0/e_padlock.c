void ENGINE_load_padlock (void)
{
#ifdef COMPILE_HW_PADLOCK
ENGINE *toadd = ENGINE_padlock ();
if (!toadd) return;
ENGINE_add (toadd);
ENGINE_free (toadd);
ERR_clear_error ();
#endif
}
static int
padlock_bind_helper(ENGINE *e)
{
padlock_available();
#if 1
padlock_use_rng=0;
#endif
BIO_snprintf(padlock_name, sizeof(padlock_name),
"VIA PadLock (%s, %s)",
padlock_use_rng ? "RNG" : "no-RNG",
padlock_use_ace ? "ACE" : "no-ACE");
if (!ENGINE_set_id(e, padlock_id) ||
!ENGINE_set_name(e, padlock_name) ||
!ENGINE_set_init_function(e, padlock_init) ||
#ifndef OPENSSL_NO_AES
(padlock_use_ace && !ENGINE_set_ciphers (e, padlock_ciphers)) ||
#endif
(padlock_use_rng && !ENGINE_set_RAND (e, &padlock_rand))) {
return 0;
}
return 1;
}
static ENGINE *
ENGINE_padlock(void)
{
ENGINE *eng = ENGINE_new();
if (!eng) {
return NULL;
}
if (!padlock_bind_helper(eng)) {
ENGINE_free(eng);
return NULL;
}
return eng;
}
static int
padlock_init(ENGINE *e)
{
return (padlock_use_rng || padlock_use_ace);
}
static int
padlock_bind_fn(ENGINE *e, const char *id)
{
if (id && (strcmp(id, padlock_id) != 0)) {
return 0;
}
if (!padlock_bind_helper(e)) {
return 0;
}
return 1;
}
static int
padlock_insn_cpuid_available(void)
{
int result = -1;
asm volatile (
"pushf\n"
"popl %%eax\n"
"xorl $0x200000, %%eax\n"
"movl %%eax, %%ecx\n"
"andl $0x200000, %%ecx\n"
"pushl %%eax\n"
"popf\n"
"pushf\n"
"popl %%eax\n"
"andl $0x200000, %%eax\n"
"xorl %%eax, %%ecx\n"
"movl %%ecx, %0\n"
: "=r" (result) : : "eax", "ecx");
return (result == 0);
}
static int
padlock_available(void)
{
char vendor_string[16];
unsigned int eax, edx;
if (! padlock_insn_cpuid_available())
return 0;
eax = 0x00000000;
vendor_string[12] = 0;
asm volatile (
"pushl %%ebx\n"
"cpuid\n"
"movl %%ebx,(%%edi)\n"
"movl %%edx,4(%%edi)\n"
"movl %%ecx,8(%%edi)\n"
"popl %%ebx"
: "+a"(eax) : "D"(vendor_string) : "ecx", "edx");
if (strcmp(vendor_string, "CentaurHauls") != 0)
return 0;
eax = 0xC0000000;
asm volatile ("pushl %%ebx; cpuid; popl %%ebx"
: "+a"(eax) : : "ecx", "edx");
if (eax < 0xC0000001)
return 0;
eax = 0xC0000001;
asm volatile ("pushl %%ebx; cpuid; popl %%ebx"
: "+a"(eax), "=d"(edx) : : "ecx");
padlock_use_ace = ((edx & (0x3<<6)) == (0x3<<6));
padlock_use_rng = ((edx & (0x3<<2)) == (0x3<<2));
return padlock_use_ace + padlock_use_rng;
}
static inline void
padlock_bswapl(AES_KEY *ks)
{
size_t i = sizeof(ks->rd_key)/sizeof(ks->rd_key[0]);
unsigned int *key = ks->rd_key;
while (i--) {
asm volatile ("bswapl %0" : "+r"(*key));
key++;
}
}
static inline void
padlock_reload_key(void)
{
asm volatile ("pushfl; popfl");
}
static inline void
padlock_verify_context(struct padlock_cipher_data *cdata)
{
asm volatile (
"pushfl\n"
" btl $30,(%%esp)\n"
" jnc 1f\n"
" cmpl %2,%1\n"
" je 1f\n"
" popfl\n"
" subl $4,%%esp\n"
"1: addl $4,%%esp\n"
" movl %2,%0"
:"+m"(padlock_saved_context)
: "r"(padlock_saved_context), "r"(cdata) : "cc");
}
static inline unsigned int
padlock_xstore(void *addr, unsigned int edx_in)
{
unsigned int eax_out;
asm volatile (".byte 0x0f,0xa7,0xc0"
: "=a"(eax_out),"=m"(*(unsigned *)addr)
: "D"(addr), "d" (edx_in)
);
return eax_out;
}
static inline unsigned char *
padlock_memcpy(void *dst,const void *src,size_t n)
{
long *d=dst;
const long *s=src;
n /= sizeof(*d);
do { *d++ = *s++; } while (--n);
return dst;
}
static int __fastcall
padlock_xstore(void *outp,unsigned int code)
{ _asm mov edi,ecx
_asm _emit 0x0f _asm _emit 0xa7 _asm _emit 0xc0
}
static void __fastcall
padlock_reload_key(void)
{ _asm pushfd _asm popfd }
static void __fastcall
padlock_verify_context(void *cdata)
{ _asm {
pushfd
bt DWORD PTR[esp],30
jnc skip
cmp ecx,padlock_saved_context
je skip
popfd
sub esp,4
skip: add esp,4
mov padlock_saved_context,ecx
}
}
static int
padlock_available(void)
{ _asm {
pushfd
pop eax
mov ecx,eax
xor eax,1<<21
push eax
popfd
pushfd
pop eax
xor eax,ecx
bt eax,21
jnc noluck
mov eax,0
cpuid
xor eax,eax
cmp ebx,'tneC'
jne noluck
cmp edx,'Hrua'
jne noluck
cmp ecx,'slua'
jne noluck
mov eax,0xC0000000
cpuid
mov edx,eax
xor eax,eax
cmp edx,0xC0000001
jb noluck
mov eax,0xC0000001
cpuid
xor eax,eax
bt edx,6
jnc skip_a
bt edx,7
jnc skip_a
mov padlock_use_ace,1
inc eax
skip_a: bt edx,2
jnc skip_r
bt edx,3
jnc skip_r
mov padlock_use_rng,1
inc eax
skip_r:
noluck:
}
}
static void __fastcall
padlock_bswapl(void *key)
{ _asm {
pushfd
cld
mov esi,ecx
mov edi,ecx
mov ecx,60
up: lodsd
bswap eax
stosd
loop up
popfd
}
}
static int
padlock_ciphers (ENGINE *e, const EVP_CIPHER **cipher, const int **nids, int nid)
{
if (!cipher) {
*nids = padlock_cipher_nids;
return padlock_cipher_nids_num;
}
switch (nid) {
case NID_aes_128_ecb:
*cipher = &padlock_aes_128_ecb;
break;
case NID_aes_128_cbc:
*cipher = &padlock_aes_128_cbc;
break;
case NID_aes_128_cfb:
*cipher = &padlock_aes_128_cfb;
break;
case NID_aes_128_ofb:
*cipher = &padlock_aes_128_ofb;
break;
case NID_aes_192_ecb:
*cipher = &padlock_aes_192_ecb;
break;
case NID_aes_192_cbc:
*cipher = &padlock_aes_192_cbc;
break;
case NID_aes_192_cfb:
*cipher = &padlock_aes_192_cfb;
break;
case NID_aes_192_ofb:
*cipher = &padlock_aes_192_ofb;
break;
case NID_aes_256_ecb:
*cipher = &padlock_aes_256_ecb;
break;
case NID_aes_256_cbc:
*cipher = &padlock_aes_256_cbc;
break;
case NID_aes_256_cfb:
*cipher = &padlock_aes_256_cfb;
break;
case NID_aes_256_ofb:
*cipher = &padlock_aes_256_ofb;
break;
default:
*cipher = NULL;
return 0;
}
return 1;
}
static int
padlock_aes_init_key (EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
struct padlock_cipher_data *cdata;
int key_len = EVP_CIPHER_CTX_key_length(ctx) * 8;
if (key==NULL) return 0;
cdata = ALIGNED_CIPHER_DATA(ctx);
memset(cdata, 0, sizeof(struct padlock_cipher_data));
if (EVP_CIPHER_CTX_mode(ctx) == EVP_CIPH_OFB_MODE)
cdata->cword.b.encdec = 0;
else
cdata->cword.b.encdec = (ctx->encrypt == 0);
cdata->cword.b.rounds = 10 + (key_len - 128) / 32;
cdata->cword.b.ksize = (key_len - 128) / 64;
switch(key_len) {
case 128:
memcpy(cdata->ks.rd_key, key, AES_KEY_SIZE_128);
cdata->cword.b.keygen = 0;
break;
case 192:
case 256:
if (EVP_CIPHER_CTX_mode(ctx) == EVP_CIPH_CFB_MODE ||
EVP_CIPHER_CTX_mode(ctx) == EVP_CIPH_OFB_MODE ||
enc)
AES_set_encrypt_key(key, key_len, &cdata->ks);
else
AES_set_decrypt_key(key, key_len, &cdata->ks);
#ifndef AES_ASM
padlock_bswapl(&cdata->ks);
#endif
cdata->cword.b.keygen = 1;
break;
default:
return 0;
}
padlock_reload_key ();
return 1;
}
static int
padlock_aes_cipher_omnivorous(EVP_CIPHER_CTX *ctx, unsigned char *out_arg,
const unsigned char *in_arg, size_t nbytes)
{
struct padlock_cipher_data *cdata;
void *iv;
cdata = ALIGNED_CIPHER_DATA(ctx);
padlock_verify_context(cdata);
switch (EVP_CIPHER_CTX_mode(ctx)) {
case EVP_CIPH_ECB_MODE:
padlock_xcrypt_ecb(nbytes/AES_BLOCK_SIZE, cdata, out_arg, in_arg);
break;
case EVP_CIPH_CBC_MODE:
memcpy(cdata->iv, ctx->iv, AES_BLOCK_SIZE);
iv = padlock_xcrypt_cbc(nbytes/AES_BLOCK_SIZE, cdata, out_arg, in_arg);
memcpy(ctx->iv, iv, AES_BLOCK_SIZE);
break;
case EVP_CIPH_CFB_MODE:
memcpy(cdata->iv, ctx->iv, AES_BLOCK_SIZE);
iv = padlock_xcrypt_cfb(nbytes/AES_BLOCK_SIZE, cdata, out_arg, in_arg);
memcpy(ctx->iv, iv, AES_BLOCK_SIZE);
break;
case EVP_CIPH_OFB_MODE:
memcpy(cdata->iv, ctx->iv, AES_BLOCK_SIZE);
padlock_xcrypt_ofb(nbytes/AES_BLOCK_SIZE, cdata, out_arg, in_arg);
memcpy(ctx->iv, cdata->iv, AES_BLOCK_SIZE);
break;
default:
return 0;
}
memset(cdata->iv, 0, AES_BLOCK_SIZE);
return 1;
}
static int
padlock_aes_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out_arg,
const unsigned char *in_arg, size_t nbytes)
{
struct padlock_cipher_data *cdata;
const void *inp;
unsigned char *out;
void *iv;
int inp_misaligned, out_misaligned, realign_in_loop;
size_t chunk, allocated=0;
if ((chunk = ctx->num)) {
unsigned char *ivp=ctx->iv;
switch (EVP_CIPHER_CTX_mode(ctx)) {
case EVP_CIPH_CFB_MODE:
if (chunk >= AES_BLOCK_SIZE)
return 0;
if (ctx->encrypt)
while (chunk<AES_BLOCK_SIZE && nbytes!=0) {
ivp[chunk] = *(out_arg++) = *(in_arg++) ^ ivp[chunk];
chunk++, nbytes--;
}
else while (chunk<AES_BLOCK_SIZE && nbytes!=0) {
unsigned char c = *(in_arg++);
*(out_arg++) = c ^ ivp[chunk];
ivp[chunk++] = c, nbytes--;
}
ctx->num = chunk%AES_BLOCK_SIZE;
break;
case EVP_CIPH_OFB_MODE:
if (chunk >= AES_BLOCK_SIZE)
return 0;
while (chunk<AES_BLOCK_SIZE && nbytes!=0) {
*(out_arg++) = *(in_arg++) ^ ivp[chunk];
chunk++, nbytes--;
}
ctx->num = chunk%AES_BLOCK_SIZE;
break;
}
}
if (nbytes == 0)
return 1;
#if 0
if (nbytes % AES_BLOCK_SIZE)
return 0;
#else
#endif
if (!padlock_aes_align_required && (nbytes%AES_BLOCK_SIZE)==0)
return padlock_aes_cipher_omnivorous(ctx, out_arg, in_arg, nbytes);
inp_misaligned = (((size_t)in_arg) & 0x0F);
out_misaligned = (((size_t)out_arg) & 0x0F);
realign_in_loop = out_misaligned|inp_misaligned;
if (!realign_in_loop && (nbytes%AES_BLOCK_SIZE)==0)
return padlock_aes_cipher_omnivorous(ctx, out_arg, in_arg, nbytes);
chunk = nbytes;
chunk %= PADLOCK_CHUNK;
if (chunk==0) chunk = PADLOCK_CHUNK;
if (out_misaligned) {
allocated = (chunk<nbytes?PADLOCK_CHUNK:nbytes);
out = alloca(0x10 + allocated);
out = NEAREST_ALIGNED(out);
}
else
out = out_arg;
cdata = ALIGNED_CIPHER_DATA(ctx);
padlock_verify_context(cdata);
switch (EVP_CIPHER_CTX_mode(ctx)) {
case EVP_CIPH_ECB_MODE:
do {
if (inp_misaligned)
inp = padlock_memcpy(out, in_arg, chunk);
else
inp = in_arg;
in_arg += chunk;
padlock_xcrypt_ecb(chunk/AES_BLOCK_SIZE, cdata, out, inp);
if (out_misaligned)
out_arg = padlock_memcpy(out_arg, out, chunk) + chunk;
else
out = out_arg+=chunk;
nbytes -= chunk;
chunk = PADLOCK_CHUNK;
} while (nbytes);
break;
case EVP_CIPH_CBC_MODE:
memcpy(cdata->iv, ctx->iv, AES_BLOCK_SIZE);
goto cbc_shortcut;
do {
if (iv != cdata->iv)
memcpy(cdata->iv, iv, AES_BLOCK_SIZE);
chunk = PADLOCK_CHUNK;
cbc_shortcut:
if (inp_misaligned)
inp = padlock_memcpy(out, in_arg, chunk);
else
inp = in_arg;
in_arg += chunk;
iv = padlock_xcrypt_cbc(chunk/AES_BLOCK_SIZE, cdata, out, inp);
if (out_misaligned)
out_arg = padlock_memcpy(out_arg, out, chunk) + chunk;
else
out = out_arg+=chunk;
} while (nbytes -= chunk);
memcpy(ctx->iv, iv, AES_BLOCK_SIZE);
break;
case EVP_CIPH_CFB_MODE:
memcpy (iv = cdata->iv, ctx->iv, AES_BLOCK_SIZE);
chunk &= ~(AES_BLOCK_SIZE-1);
if (chunk) goto cfb_shortcut;
else goto cfb_skiploop;
do {
if (iv != cdata->iv)
memcpy(cdata->iv, iv, AES_BLOCK_SIZE);
chunk = PADLOCK_CHUNK;
cfb_shortcut:
if (inp_misaligned)
inp = padlock_memcpy(out, in_arg, chunk);
else
inp = in_arg;
in_arg += chunk;
iv = padlock_xcrypt_cfb(chunk/AES_BLOCK_SIZE, cdata, out, inp);
if (out_misaligned)
out_arg = padlock_memcpy(out_arg, out, chunk) + chunk;
else
out = out_arg+=chunk;
nbytes -= chunk;
} while (nbytes >= AES_BLOCK_SIZE);
cfb_skiploop:
if (nbytes) {
unsigned char *ivp = cdata->iv;
if (iv != ivp) {
memcpy(ivp, iv, AES_BLOCK_SIZE);
iv = ivp;
}
ctx->num = nbytes;
if (cdata->cword.b.encdec) {
cdata->cword.b.encdec=0;
padlock_reload_key();
padlock_xcrypt_ecb(1,cdata,ivp,ivp);
cdata->cword.b.encdec=1;
padlock_reload_key();
while(nbytes) {
unsigned char c = *(in_arg++);
*(out_arg++) = c ^ *ivp;
*(ivp++) = c, nbytes--;
}
}
else { padlock_reload_key();
padlock_xcrypt_ecb(1,cdata,ivp,ivp);
padlock_reload_key();
while (nbytes) {
*ivp = *(out_arg++) = *(in_arg++) ^ *ivp;
ivp++, nbytes--;
}
}
}
memcpy(ctx->iv, iv, AES_BLOCK_SIZE);
break;
case EVP_CIPH_OFB_MODE:
memcpy(cdata->iv, ctx->iv, AES_BLOCK_SIZE);
chunk &= ~(AES_BLOCK_SIZE-1);
if (chunk) do {
if (inp_misaligned)
inp = padlock_memcpy(out, in_arg, chunk);
else
inp = in_arg;
in_arg += chunk;
padlock_xcrypt_ofb(chunk/AES_BLOCK_SIZE, cdata, out, inp);
if (out_misaligned)
out_arg = padlock_memcpy(out_arg, out, chunk) + chunk;
else
out = out_arg+=chunk;
nbytes -= chunk;
chunk = PADLOCK_CHUNK;
} while (nbytes >= AES_BLOCK_SIZE);
if (nbytes) {
unsigned char *ivp = cdata->iv;
ctx->num = nbytes;
padlock_reload_key();
padlock_xcrypt_ecb(1,cdata,ivp,ivp);
padlock_reload_key();
while (nbytes) {
*(out_arg++) = *(in_arg++) ^ *ivp;
ivp++, nbytes--;
}
}
memcpy(ctx->iv, cdata->iv, AES_BLOCK_SIZE);
break;
default:
return 0;
}
if (out_misaligned) {
volatile unsigned long *p=(void *)out;
size_t n = allocated/sizeof(*p);
while (n--) *p++=0;
}
memset(cdata->iv, 0, AES_BLOCK_SIZE);
return 1;
}
static int
padlock_rand_bytes(unsigned char *output, int count)
{
unsigned int eax, buf;
while (count >= 8) {
eax = padlock_xstore(output, 0);
if (!(eax&(1<<6))) return 0;
if (eax&(0x1F<<10)) return 0;
if ((eax&0x1F)==0) continue;
if ((eax&0x1F)!=8) return 0;
output += 8;
count -= 8;
}
while (count > 0) {
eax = padlock_xstore(&buf, 3);
if (!(eax&(1<<6))) return 0;
if (eax&(0x1F<<10)) return 0;
if ((eax&0x1F)==0) continue;
if ((eax&0x1F)!=1) return 0;
*output++ = (unsigned char)buf;
count--;
}
*(volatile unsigned int *)&buf=0;
return 1;
}
static int
padlock_rand_status(void)
{
return 1;
}
OPENSSL_EXPORT
int bind_engine(ENGINE *e, const char *id, const dynamic_fns *fns) { return 0; }
