int i2d_ASN1_BOOLEAN(int a, unsigned char **pp)
{
int r;
unsigned char *p;
r=ASN1_object_size(0,1,V_ASN1_BOOLEAN);
if (pp == NULL) return(r);
p= *pp;
ASN1_put_object(&p,0,1,V_ASN1_BOOLEAN,V_ASN1_UNIVERSAL);
*(p++)= (unsigned char)a;
*pp=p;
return(r);
}
int d2i_ASN1_BOOLEAN(int *a, const unsigned char **pp, long length)
{
int ret= -1;
const unsigned char *p;
long len;
int inf,tag,xclass;
int i=0;
p= *pp;
inf=ASN1_get_object(&p,&len,&tag,&xclass,length);
if (inf & 0x80)
{
i=ASN1_R_BAD_OBJECT_HEADER;
goto err;
}
if (tag != V_ASN1_BOOLEAN)
{
i=ASN1_R_EXPECTING_A_BOOLEAN;
goto err;
}
if (len != 1)
{
i=ASN1_R_BOOLEAN_IS_WRONG_LENGTH;
goto err;
}
ret= (int)*(p++);
if (a != NULL) (*a)=ret;
*pp=p;
return(ret);
err:
ASN1err(ASN1_F_D2I_ASN1_BOOLEAN,i);
return(ret);
}
