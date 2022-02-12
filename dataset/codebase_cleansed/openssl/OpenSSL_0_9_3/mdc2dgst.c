void MDC2_Init(MDC2_CTX *c)
{
c->num=0;
c->pad_type=1;
memset(&(c->h[0]),0x52,MDC2_BLOCK);
memset(&(c->hh[0]),0x25,MDC2_BLOCK);
}
void MDC2_Update(MDC2_CTX *c, register unsigned char *in, unsigned long len)
{
int i,j;
i=c->num;
if (i != 0)
{
if (i+len < MDC2_BLOCK)
{
memcpy(&(c->data[i]),in,(int)len);
c->num+=(int)len;
return;
}
else
{
j=MDC2_BLOCK-i;
memcpy(&(c->data[i]),in,j);
len-=j;
in+=j;
c->num=0;
mdc2_body(c,&(c->data[0]),MDC2_BLOCK);
}
}
i=(int)(len&(unsigned long)~(MDC2_BLOCK-1));
if (i > 0) mdc2_body(c,in,i);
j=(int)len-i;
if (j > 0)
{
memcpy(&(c->data[0]),&(in[i]),j);
c->num=j;
}
}
static void mdc2_body(MDC2_CTX *c, unsigned char *in, unsigned int len)
{
register DES_LONG tin0,tin1;
register DES_LONG ttin0,ttin1;
DES_LONG d[2],dd[2];
des_key_schedule k;
unsigned char *p;
unsigned int i;
for (i=0; i<len; i+=8)
{
c2l(in,tin0); d[0]=dd[0]=tin0;
c2l(in,tin1); d[1]=dd[1]=tin1;
c->h[0]=(c->h[0]&0x9f)|0x40;
c->hh[0]=(c->hh[0]&0x9f)|0x20;
des_set_odd_parity(&c->h);
des_set_key(&c->h,k);
des_encrypt(d,k,1);
des_set_odd_parity(&c->hh);
des_set_key(&c->hh,k);
des_encrypt(dd,k,1);
ttin0=tin0^dd[0];
ttin1=tin1^dd[1];
tin0^=d[0];
tin1^=d[1];
p=c->h;
l2c(tin0,p);
l2c(ttin1,p);
p=c->hh;
l2c(ttin0,p);
l2c(tin1,p);
}
}
void MDC2_Final(unsigned char *md, MDC2_CTX *c)
{
int i,j;
i=c->num;
j=c->pad_type;
if ((i > 0) || (j == 2))
{
if (j == 2)
c->data[i++]=0x80;
memset(&(c->data[i]),0,MDC2_BLOCK-i);
mdc2_body(c,c->data,MDC2_BLOCK);
}
memcpy(md,(char *)c->h,MDC2_BLOCK);
memcpy(&(md[MDC2_BLOCK]),(char *)c->hh,MDC2_BLOCK);
}
main()
{
unsigned char md[MDC2_DIGEST_LENGTH];
int i;
MDC2_CTX c;
static char *text="Now is the time for all ";
MDC2_Init(&c);
MDC2_Update(&c,text,strlen(text));
MDC2_Final(&(md[0]),&c);
for (i=0; i<MDC2_DIGEST_LENGTH; i++)
printf("%02X",md[i]);
printf("\n");
}
