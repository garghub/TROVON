void BF_set_key(BF_KEY *key, int len, const unsigned char *data)
#ifdef OPENSSL_FIPS
{
fips_cipher_abort(BLOWFISH);
private_BF_set_key(key, len, data);
}
void private_BF_set_key(BF_KEY *key, int len, const unsigned char *data)
#endif
{
int i;
BF_LONG *p,ri,in[2];
const unsigned char *d,*end;
memcpy(key,&bf_init,sizeof(BF_KEY));
p=key->P;
if (len > ((BF_ROUNDS+2)*4)) len=(BF_ROUNDS+2)*4;
d=data;
end= &(data[len]);
for (i=0; i<(BF_ROUNDS+2); i++)
{
ri= *(d++);
if (d >= end) d=data;
ri<<=8;
ri|= *(d++);
if (d >= end) d=data;
ri<<=8;
ri|= *(d++);
if (d >= end) d=data;
ri<<=8;
ri|= *(d++);
if (d >= end) d=data;
p[i]^=ri;
}
in[0]=0L;
in[1]=0L;
for (i=0; i<(BF_ROUNDS+2); i+=2)
{
BF_encrypt(in,key);
p[i ]=in[0];
p[i+1]=in[1];
}
p=key->S;
for (i=0; i<4*256; i+=2)
{
BF_encrypt(in,key);
p[i ]=in[0];
p[i+1]=in[1];
}
}
