COMP_METHOD *COMP_rle(void)
{
return(&rle_method);
}
static int rle_compress_block(COMP_CTX *ctx, unsigned char *out,
unsigned int olen, unsigned char *in, unsigned int ilen)
{
if (olen < (ilen+1))
{
return(-1);
}
*(out++)=0;
memcpy(out,in,ilen);
return(ilen+1);
}
static int rle_expand_block(COMP_CTX *ctx, unsigned char *out,
unsigned int olen, unsigned char *in, unsigned int ilen)
{
int i;
if (olen < (ilen-1))
{
return(-1);
}
i= *(in++);
if (i == 0)
{
memcpy(out,in,ilen-1);
}
return(ilen-1);
}
