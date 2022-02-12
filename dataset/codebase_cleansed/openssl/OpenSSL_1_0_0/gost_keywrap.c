void keyDiversifyCryptoPro(gost_ctx *ctx,const unsigned char *inputKey, const unsigned char *ukm, unsigned char *outputKey)
{
u4 k,s1,s2;
int i,j,mask;
unsigned char S[8];
memcpy(outputKey,inputKey,32);
for (i=0;i<8;i++)
{
s1=0,s2=0;
for (j=0,mask=1;j<8;j++,mask<<=1)
{
k=((u4)outputKey[4*j])|(outputKey[4*j+1]<<8)|
(outputKey[4*j+2]<<16)|(outputKey[4*j+3]<<24);
if (mask & ukm[i])
{
s1+=k;
}
else
{
s2+=k;
}
}
S[0]=(unsigned char)(s1&0xff);
S[1]=(unsigned char)((s1>>8)&0xff);
S[2]=(unsigned char)((s1>>16)&0xff);
S[3]=(unsigned char)((s1>>24)&0xff);
S[4]=(unsigned char)(s2&0xff);
S[5]=(unsigned char)((s2>>8)&0xff);
S[6]=(unsigned char)((s2>>16)&0xff);
S[7]=(unsigned char)((s2>>24)&0xff);
gost_key(ctx,outputKey);
gost_enc_cfb(ctx,S,outputKey,outputKey,4);
}
}
int keyWrapCryptoPro(gost_ctx *ctx,const unsigned char *keyExchangeKey, const unsigned char *ukm,
const unsigned char *sessionKey, unsigned char *wrappedKey)
{
unsigned char kek_ukm[32];
keyDiversifyCryptoPro(ctx,keyExchangeKey,ukm,kek_ukm);
gost_key(ctx,kek_ukm);
memcpy(wrappedKey,ukm,8);
gost_enc(ctx,sessionKey,wrappedKey+8,4);
gost_mac_iv(ctx,32,ukm,sessionKey,32,wrappedKey+40);
return 1;
}
int keyUnwrapCryptoPro(gost_ctx *ctx,const unsigned char *keyExchangeKey,
const unsigned char *wrappedKey, unsigned char *sessionKey)
{
unsigned char kek_ukm[32],cek_mac[4];
keyDiversifyCryptoPro(ctx,keyExchangeKey,wrappedKey
,kek_ukm);
gost_key(ctx,kek_ukm);
gost_dec(ctx,wrappedKey+8,sessionKey,4);
gost_mac_iv(ctx,32,wrappedKey,sessionKey,32,cek_mac);
if (memcmp(cek_mac,wrappedKey+40,4))
{
return 0;
}
return 1;
}
