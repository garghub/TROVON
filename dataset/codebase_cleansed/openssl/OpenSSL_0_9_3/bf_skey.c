void BF_set_key(BF_KEY *key, int len, unsigned char *data)
{
int i;
BF_LONG *p,ri,in[2];
unsigned char *d,*end;
memcpy((char *)key,(char *)&bf_init,sizeof(BF_KEY));
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
