int i2d_DSAPrivateKey(DSA *a, unsigned char **pp)
{
BIGNUM *num[6];
unsigned char data[1];
ASN1_INTEGER bs;
unsigned int j,i,tot,t,len,max=0;
unsigned char *p;
if (a == NULL) return(0);
num[1]=a->p;
num[2]=a->q;
num[3]=a->g;
num[4]=a->pub_key;
num[5]=a->priv_key;
bs.length=1;
bs.data=data;
bs.type=V_ASN1_INTEGER;
data[0]=a->version&0x7f;
tot=i2d_ASN1_INTEGER(&(bs),NULL);
for (i=1; i<6; i++)
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
i2d_ASN1_INTEGER(&bs,&p);
bs.data=(unsigned char *)OPENSSL_malloc(max+4);
if (bs.data == NULL)
{
ASN1err(ASN1_F_I2D_DSAPRIVATEKEY,ERR_R_MALLOC_FAILURE);
return(-1);
}
for (i=1; i<6; i++)
{
bs.length=BN_bn2bin(num[i],bs.data);
i2d_ASN1_INTEGER(&bs,&p);
}
OPENSSL_free(bs.data);
*pp=p;
return(t);
}
