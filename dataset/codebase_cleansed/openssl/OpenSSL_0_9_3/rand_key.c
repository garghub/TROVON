void des_random_seed(des_cblock *key)
{
memcpy(&init,key,sizeof(des_cblock));
seed=1;
}
void des_random_key(des_cblock *ret)
{
des_key_schedule ks;
static DES_LONG c=0;
static unsigned short pid=0;
static des_cblock data={0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef};
des_cblock key;
unsigned char *p;
DES_LONG t;
int i;
#ifdef MSDOS
pid=1;
#else
if (!pid) pid=getpid();
#endif
p=key;
if (seed)
{
for (i=0; i<8; i++)
{
data[i] ^= init[i];
init[i]=0;
}
seed=0;
}
t=(DES_LONG)time(NULL);
l2c(t,p);
t=(DES_LONG)((pid)|((c++)<<16));
l2c(t,p);
des_set_odd_parity(&data);
des_set_key(&data,ks);
des_cbc_cksum(key,&key,sizeof(key),ks,&data);
des_set_odd_parity(&key);
des_set_key(&key,ks);
des_cbc_cksum(key,&data,sizeof(key),ks,&key);
memcpy(ret,data,sizeof(key));
memset(key,0,sizeof(key));
memset(ks,0,sizeof(ks));
t=0;
}
