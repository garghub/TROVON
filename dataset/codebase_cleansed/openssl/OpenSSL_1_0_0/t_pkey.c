int ASN1_bn_print(BIO *bp, const char *number, const BIGNUM *num,
unsigned char *buf, int off)
{
int n,i;
const char *neg;
if (num == NULL) return(1);
neg = (BN_is_negative(num))?"-":"";
if(!BIO_indent(bp,off,128))
return 0;
if (BN_is_zero(num))
{
if (BIO_printf(bp, "%s 0\n", number) <= 0)
return 0;
return 1;
}
if (BN_num_bytes(num) <= BN_BYTES)
{
if (BIO_printf(bp,"%s %s%lu (%s0x%lx)\n",number,neg,
(unsigned long)num->d[0],neg,(unsigned long)num->d[0])
<= 0) return(0);
}
else
{
buf[0]=0;
if (BIO_printf(bp,"%s%s",number,
(neg[0] == '-')?" (Negative)":"") <= 0)
return(0);
n=BN_bn2bin(num,&buf[1]);
if (buf[1] & 0x80)
n++;
else buf++;
for (i=0; i<n; i++)
{
if ((i%15) == 0)
{
if(BIO_puts(bp,"\n") <= 0
|| !BIO_indent(bp,off+4,128))
return 0;
}
if (BIO_printf(bp,"%02x%s",buf[i],((i+1) == n)?"":":")
<= 0) return(0);
}
if (BIO_write(bp,"\n",1) <= 0) return(0);
}
return(1);
}
