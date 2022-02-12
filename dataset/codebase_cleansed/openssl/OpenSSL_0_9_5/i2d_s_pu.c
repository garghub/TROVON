int i2d_DSAPublicKey(DSA *a, unsigned char **pp)
{
BIGNUM *num[4];
ASN1_INTEGER bs;
unsigned int j,i,tot=0,len,max=0,t=0,all,n=1;
unsigned char *p;
if (a == NULL) return(0);
all=a->write_params;
num[0]=a->pub_key;
if (all)
{
num[1]=a->p;
num[2]=a->q;
num[3]=a->g;
n=4;
}
for (i=0; i<n; i++)
{
j=BN_num_bits(num[i]);
len=((j == 0)?0:((j/8)+1));
if (len > max) max=len;
len=ASN1_object_size(0,len,
(num[i]->neg)?V_ASN1_NEG_INTEGER:V_ASN1_INTEGER);
tot+=len;
}
if (all)
{
t=ASN1_object_size(1,tot,V_ASN1_SEQUENCE);
if (pp == NULL) return(t);
}
else
{
if (pp == NULL) return(tot);
}
p= *pp;
if (all)
ASN1_put_object(&p,1,tot,V_ASN1_SEQUENCE,V_ASN1_UNIVERSAL);
bs.type=V_ASN1_INTEGER;
bs.data=(unsigned char *)Malloc(max+4);
if (bs.data == NULL)
{
ASN1err(ASN1_F_I2D_DSAPUBLICKEY,ERR_R_MALLOC_FAILURE);
return(-1);
}
for (i=0; i<n; i++)
{
bs.length=BN_bn2bin(num[i],bs.data);
i2d_ASN1_INTEGER(&bs,&p);
}
Free(bs.data);
*pp=p;
if(all) return(t);
else return(tot);
}
