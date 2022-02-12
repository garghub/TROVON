char *des_fcrypt(const char *buf, const char *salt, char *ret)
{
unsigned int i,j,x,y;
DES_LONG Eswap0,Eswap1;
DES_LONG out[2],ll;
des_cblock key;
des_key_schedule ks;
unsigned char bb[9];
unsigned char *b=bb;
unsigned char c,u;
x=ret[0]=((salt[0] == '\0')?'A':salt[0]);
Eswap0=con_salt[x]<<2;
x=ret[1]=((salt[1] == '\0')?'A':salt[1]);
Eswap1=con_salt[x]<<6;
for (i=0; i<8; i++)
{
c= *(buf++);
if (!c) break;
key[i]=(c<<1);
}
for (; i<8; i++)
key[i]=0;
des_set_key(&key,ks);
fcrypt_body(&(out[0]),ks,Eswap0,Eswap1);
ll=out[0]; l2c(ll,b);
ll=out[1]; l2c(ll,b);
y=0;
u=0x80;
bb[8]=0;
for (i=2; i<13; i++)
{
c=0;
for (j=0; j<6; j++)
{
c<<=1;
if (bb[y] & u) c|=1;
u>>=1;
if (!u)
{
y++;
u=0x80;
}
}
ret[i]=cov_2char[c];
}
ret[13]='\0';
return(ret);
}
