int i2d_ASN1_NULL(ASN1_NULL *a, unsigned char **pp)
{
if(!a) return 0;
if (pp) ASN1_put_object(pp,0,0,V_ASN1_NULL,V_ASN1_UNIVERSAL);
return 2;
}
ASN1_NULL *d2i_ASN1_NULL(ASN1_NULL **a, unsigned char **pp, long length)
{
ASN1_NULL *ret = NULL;
unsigned char *p;
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
if (tag != V_ASN1_NULL)
{
i=ASN1_R_EXPECTING_A_NULL;
goto err;
}
if (len != 0)
{
i=ASN1_R_NULL_IS_WRONG_LENGTH;
goto err;
}
ret=(ASN1_NULL *)1;
if (a != NULL) (*a)=ret;
*pp=p;
return(ret);
err:
ASN1err(ASN1_F_D2I_ASN1_NULL,i);
return(ret);
}
ASN1_NULL *ASN1_NULL_new(void)
{
return (ASN1_NULL *)1;
}
void ASN1_NULL_free(ASN1_NULL *a)
{
return;
}
