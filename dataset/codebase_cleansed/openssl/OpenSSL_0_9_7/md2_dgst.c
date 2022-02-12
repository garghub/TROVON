const char *MD2_options(void)
{
if (sizeof(MD2_INT) == 1)
return("md2(char)");
else
return("md2(int)");
}
int MD2_Init(MD2_CTX *c)
{
c->num=0;
memset(c->state,0,sizeof c->state);
memset(c->cksm,0,sizeof c->cksm);
memset(c->data,0,sizeof c->data);
return 1;
}
int MD2_Update(MD2_CTX *c, const unsigned char *data, unsigned long len)
{
register UCHAR *p;
if (len == 0) return 1;
p=c->data;
if (c->num != 0)
{
if ((c->num+len) >= MD2_BLOCK)
{
memcpy(&(p[c->num]),data,MD2_BLOCK-c->num);
md2_block(c,c->data);
data+=(MD2_BLOCK - c->num);
len-=(MD2_BLOCK - c->num);
c->num=0;
}
else
{
memcpy(&(p[c->num]),data,(int)len);
c->num+=(int)len;
return 1;
}
}
while (len >= MD2_BLOCK)
{
md2_block(c,data);
data+=MD2_BLOCK;
len-=MD2_BLOCK;
}
memcpy(p,data,(int)len);
c->num=(int)len;
return 1;
}
static void md2_block(MD2_CTX *c, const unsigned char *d)
{
register MD2_INT t,*sp1,*sp2;
register int i,j;
MD2_INT state[48];
sp1=c->state;
sp2=c->cksm;
j=sp2[MD2_BLOCK-1];
for (i=0; i<16; i++)
{
state[i]=sp1[i];
state[i+16]=t=d[i];
state[i+32]=(t^sp1[i]);
j=sp2[i]^=S[t^j];
}
t=0;
for (i=0; i<18; i++)
{
for (j=0; j<48; j+=8)
{
t= state[j+ 0]^=S[t];
t= state[j+ 1]^=S[t];
t= state[j+ 2]^=S[t];
t= state[j+ 3]^=S[t];
t= state[j+ 4]^=S[t];
t= state[j+ 5]^=S[t];
t= state[j+ 6]^=S[t];
t= state[j+ 7]^=S[t];
}
t=(t+i)&0xff;
}
memcpy(sp1,state,16*sizeof(MD2_INT));
OPENSSL_cleanse(state,48*sizeof(MD2_INT));
}
int MD2_Final(unsigned char *md, MD2_CTX *c)
{
int i,v;
register UCHAR *cp;
register MD2_INT *p1,*p2;
cp=c->data;
p1=c->state;
p2=c->cksm;
v=MD2_BLOCK-c->num;
for (i=c->num; i<MD2_BLOCK; i++)
cp[i]=(UCHAR)v;
md2_block(c,cp);
for (i=0; i<MD2_BLOCK; i++)
cp[i]=(UCHAR)p2[i];
md2_block(c,cp);
for (i=0; i<16; i++)
md[i]=(UCHAR)(p1[i]&0xff);
memset((char *)&c,0,sizeof(c));
return 1;
}
