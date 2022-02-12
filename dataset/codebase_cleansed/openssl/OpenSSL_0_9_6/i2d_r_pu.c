int i2d_RSAPublicKey(RSA *a, unsigned char **pp)
{
BIGNUM *num[2];
ASN1_INTEGER bs;
unsigned int j,i,tot=0,len,max=0,t;
unsigned char *p;
if (a == NULL) return(0);
num[0]=a->n;
num[1]=a->e;
for (i=0; i<2; i++)
{
j=BN_num_bits(num[i]);
len=((j == 0)?0:((j/8)+1));
if (len > max) max=len;
len=ASN1_object_size(0,len,
(num[i]->neg)?V_ASN1_NEG_INTEGER:V_ASN1_INTEGER);
tot+=len;
}
t=ASN1_object_size(1,tot,V_ASN1_SEQUENCE);
if (pp == NULL) return(t);
p= *pp;
ASN1_put_object(&p,1,tot,V_ASN1_SEQUENCE,V_ASN1_UNIVERSAL);
bs.type=V_ASN1_INTEGER;
bs.data=(unsigned char *)OPENSSL_malloc(max+4);
if (bs.data == NULL)
{
ASN1err(ASN1_F_I2D_RSAPUBLICKEY,ERR_R_MALLOC_FAILURE);
return(-1);
}
for (i=0; i<2; i++)
{
bs.length=BN_bn2bin(num[i],bs.data);
i2d_ASN1_INTEGER(&bs,&p);
}
OPENSSL_free(bs.data);
*pp=p;
return(t);
}
