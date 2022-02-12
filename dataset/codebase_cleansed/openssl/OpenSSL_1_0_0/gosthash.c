static void swap_bytes (byte *w, byte *k)
{
int i,j;
for (i=0;i<4;i++)
for (j=0;j<8;j++)
k[i+4*j]=w[8*i+j];
}
static void circle_xor8 (const byte *w, byte *k)
{
byte buf[8];
int i;
memcpy(buf,w,8);
memcpy(k,w+8,24);
for(i=0;i<8;i++)
k[i+24]=buf[i]^k[i];
}
static void transform_3 (byte *data)
{
unsigned short int acc;
acc=(data[0]^data[2]^data[4]^data[6]^data[24]^data[30])|
((data[1]^data[3]^data[5]^data[7]^data[25]^data[31])<<8);
memmove(data,data+2,30);
data[30]=acc&0xff;
data[31]=acc>>8;
}
static int add_blocks(int n,byte *left, const byte *right)
{
int i;
int carry=0;
int sum;
for (i=0;i<n;i++)
{
sum=(int)left[i]+(int)right[i]+carry;
left[i]=sum & 0xff;
carry=sum>>8;
}
return carry;
}
static void xor_blocks (byte *result,const byte *a,const byte *b,size_t len)
{
size_t i;
for (i=0;i<len;i++) result[i]=a[i]^b[i];
}
static int hash_step(gost_ctx *c,byte *H,const byte *M)
{
byte U[32],W[32],V[32],S[32],Key[32];
int i;
xor_blocks(W,H,M,32);
swap_bytes(W,Key);
gost_enc_with_key(c,Key,H,S);
circle_xor8(H,U);
circle_xor8(M,V);
circle_xor8(V,V);
xor_blocks(W,U,V,32);
swap_bytes(W,Key);
gost_enc_with_key(c,Key,H+8,S+8);
circle_xor8(U,U);
U[31]=~U[31]; U[29]=~U[29]; U[28]=~U[28]; U[24]=~U[24];
U[23]=~U[23]; U[20]=~U[20]; U[18]=~U[18]; U[17]=~U[17];
U[14]=~U[14]; U[12]=~U[12]; U[10]=~U[10]; U[ 8]=~U[ 8];
U[ 7]=~U[ 7]; U[ 5]=~U[ 5]; U[ 3]=~U[ 3]; U[ 1]=~U[ 1];
circle_xor8(V,V);
circle_xor8(V,V);
xor_blocks(W,U,V,32);
swap_bytes(W,Key);
gost_enc_with_key(c,Key,H+16,S+16);
circle_xor8(U,U);
circle_xor8(V,V);
circle_xor8(V,V);
xor_blocks(W,U,V,32);
swap_bytes(W,Key);
gost_enc_with_key(c,Key,H+24,S+24);
for (i=0;i<12;i++)
transform_3(S);
xor_blocks(S,S,M,32);
transform_3(S);
xor_blocks(S,S,H,32);
for (i=0;i<61;i++)
transform_3(S);
memcpy(H,S,32);
return 1;
}
int init_gost_hash_ctx(gost_hash_ctx *ctx, const gost_subst_block *subst_block)
{
memset(ctx,0,sizeof(gost_hash_ctx));
ctx->cipher_ctx = (gost_ctx *)MYALLOC(sizeof(gost_ctx));
if (!ctx->cipher_ctx)
{
return 0;
}
gost_init(ctx->cipher_ctx,subst_block);
return 1;
}
void done_gost_hash_ctx(gost_hash_ctx *ctx)
{
MYFREE(ctx->cipher_ctx);
}
int start_hash(gost_hash_ctx *ctx)
{
if (!ctx->cipher_ctx) return 0;
memset(&(ctx->H),0,32);
memset(&(ctx->S),0,32);
ctx->len = 0L;
ctx->left=0;
return 1;
}
int hash_block(gost_hash_ctx *ctx,const byte *block, size_t length)
{
const byte *curptr=block;
const byte *barrier=block+(length-32);
if (ctx->left)
{
unsigned int add_bytes = 32-ctx->left;
if (add_bytes>length)
{
add_bytes = length;
}
memcpy(&(ctx->remainder[ctx->left]),block,add_bytes);
ctx->left+=add_bytes;
if (ctx->left<32)
{
return 1;
}
curptr=block+add_bytes;
hash_step(ctx->cipher_ctx,ctx->H,ctx->remainder);
add_blocks(32,ctx->S,ctx->remainder);
ctx->len+=32;
ctx->left=0;
}
while (curptr<=barrier)
{
hash_step(ctx->cipher_ctx,ctx->H,curptr);
add_blocks(32,ctx->S,curptr);
ctx->len+=32;
curptr+=32;
}
if (curptr!=block+length)
{
ctx->left=block+length-curptr;
memcpy(ctx->remainder,curptr,ctx->left);
}
return 1;
}
int finish_hash(gost_hash_ctx *ctx,byte *hashval)
{
byte buf[32];
byte H[32];
byte S[32];
ghosthash_len fin_len=ctx->len;
byte *bptr;
memcpy(H,ctx->H,32);
memcpy(S,ctx->S,32);
if (ctx->left)
{
memset(buf,0,32);
memcpy(buf,ctx->remainder,ctx->left);
hash_step(ctx->cipher_ctx,H,buf);
add_blocks(32,S,buf);
fin_len+=ctx->left;
}
memset(buf,0,32);
bptr=buf;
fin_len<<=3;
while(fin_len>0)
{
*(bptr++)=(byte)(fin_len&0xFF);
fin_len>>=8;
};
hash_step(ctx->cipher_ctx,H,buf);
hash_step(ctx->cipher_ctx,H,S);
memcpy(hashval,H,32);
return 1;
}
