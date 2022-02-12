int BN_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
unsigned char *buf=NULL;
int ret=0,bit,bytes,mask;
time_t tim;
bytes=(bits+7)/8;
bit=(bits-1)%8;
mask=0xff<<bit;
buf=(unsigned char *)Malloc(bytes);
if (buf == NULL)
{
BNerr(BN_F_BN_RAND,ERR_R_MALLOC_FAILURE);
goto err;
}
time(&tim);
RAND_seed(&tim,sizeof(tim));
RAND_bytes(buf,(int)bytes);
if (top)
{
if (bit == 0)
{
buf[0]=1;
buf[1]|=0x80;
}
else
{
buf[0]|=(3<<(bit-1));
buf[0]&= ~(mask<<1);
}
}
else
{
buf[0]|=(1<<bit);
buf[0]&= ~(mask<<1);
}
if (bottom)
buf[bytes-1]|=1;
if (!BN_bin2bn(buf,bytes,rnd)) goto err;
ret=1;
err:
if (buf != NULL)
{
memset(buf,0,bytes);
Free(buf);
}
return(ret);
}
