int i2d_DHparams(DH *a, unsigned char **pp)
{
BIGNUM *num[3];
ASN1_INTEGER bs;
unsigned int j,i,tot=0,len,max=0;
int t,ret= -1;
unsigned char *p;
if (a == NULL) return(0);
num[0]=a->p;
num[1]=a->g;
if (a->length != 0)
{
if ((num[2]=BN_new()) == NULL) goto err;
if (!BN_set_word(num[2],a->length)) goto err;
}
else
num[2]=NULL;
for (i=0; i<3; i++)
{
if (num[i] == NULL) continue;
j=BN_num_bits(num[i]);
len=((j == 0)?0:((j/8)+1));
if (len > max) max=len;
len=ASN1_object_size(0,len,
(num[i]->neg)?V_ASN1_NEG_INTEGER:V_ASN1_INTEGER);
tot+=len;
}
t=ASN1_object_size(1,tot,V_ASN1_SEQUENCE);
if (pp == NULL)
{
if (num[2] != NULL)
BN_free(num[2]);
return(t);
}
p= *pp;
ASN1_put_object(&p,1,tot,V_ASN1_SEQUENCE,V_ASN1_UNIVERSAL);
bs.type=V_ASN1_INTEGER;
bs.data=(unsigned char *)Malloc(max+4);
if (bs.data == NULL)
{
ASN1err(ASN1_F_I2D_DHPARAMS,ERR_R_MALLOC_FAILURE);
goto err;
}
for (i=0; i<3; i++)
{
if (num[i] == NULL) continue;
bs.length=BN_bn2bin(num[i],bs.data);
i2d_ASN1_INTEGER(&bs,&p);
}
Free(bs.data);
ret=t;
err:
if (num[2] != NULL) BN_free(num[2]);
*pp=p;
return(ret);
}
