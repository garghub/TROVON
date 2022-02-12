void des_string_to_key(const char *str, des_cblock *key)
{
des_key_schedule ks;
int i,length;
register unsigned char j;
memset(key,0,8);
length=strlen(str);
#ifdef OLD_STR_TO_KEY
for (i=0; i<length; i++)
(*key)[i%8]^=(str[i]<<1);
#else
for (i=0; i<length; i++)
{
j=str[i];
if ((i%16) < 8)
(*key)[i%8]^=(j<<1);
else
{
j=((j<<4)&0xf0)|((j>>4)&0x0f);
j=((j<<2)&0xcc)|((j>>2)&0x33);
j=((j<<1)&0xaa)|((j>>1)&0x55);
(*key)[7-(i%8)]^=j;
}
}
#endif
des_set_odd_parity(key);
i=des_check_key;
des_check_key=0;
des_set_key(key,ks);
des_check_key=i;
des_cbc_cksum((unsigned char*)str,key,length,ks,key);
memset(ks,0,sizeof(ks));
des_set_odd_parity(key);
}
void des_string_to_2keys(const char *str, des_cblock *key1, des_cblock *key2)
{
des_key_schedule ks;
int i,length;
register unsigned char j;
memset(key1,0,8);
memset(key2,0,8);
length=strlen(str);
#ifdef OLD_STR_TO_KEY
if (length <= 8)
{
for (i=0; i<length; i++)
{
(*key2)[i]=(*key1)[i]=(str[i]<<1);
}
}
else
{
for (i=0; i<length; i++)
{
if ((i/8)&1)
(*key2)[i%8]^=(str[i]<<1);
else
(*key1)[i%8]^=(str[i]<<1);
}
}
#else
for (i=0; i<length; i++)
{
j=str[i];
if ((i%32) < 16)
{
if ((i%16) < 8)
(*key1)[i%8]^=(j<<1);
else
(*key2)[i%8]^=(j<<1);
}
else
{
j=((j<<4)&0xf0)|((j>>4)&0x0f);
j=((j<<2)&0xcc)|((j>>2)&0x33);
j=((j<<1)&0xaa)|((j>>1)&0x55);
if ((i%16) < 8)
(*key1)[7-(i%8)]^=j;
else
(*key2)[7-(i%8)]^=j;
}
}
if (length <= 8) memcpy(key2,key1,8);
#endif
des_set_odd_parity(key1);
des_set_odd_parity(key2);
i=des_check_key;
des_check_key=0;
des_set_key(key1,ks);
des_cbc_cksum((unsigned char*)str,key1,length,ks,key1);
des_set_key(key2,ks);
des_cbc_cksum((unsigned char*)str,key2,length,ks,key2);
des_check_key=i;
memset(ks,0,sizeof(ks));
des_set_odd_parity(key1);
des_set_odd_parity(key2);
}
