int i2d_PKCS7(PKCS7 *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
if (a->asn1 != NULL)
{
if (pp == NULL)
return((int)a->length);
memcpy(*pp,a->asn1,(int)a->length);
*pp+=a->length;
return((int)a->length);
}
ret+=4;
M_ASN1_I2D_len(a->type,i2d_ASN1_OBJECT);
if (a->d.ptr != NULL)
{
ret+=4;
switch (OBJ_obj2nid(a->type))
{
case NID_pkcs7_data:
M_ASN1_I2D_len(a->d.data,i2d_ASN1_OCTET_STRING);
break;
case NID_pkcs7_signed:
M_ASN1_I2D_len(a->d.sign,i2d_PKCS7_SIGNED);
break;
case NID_pkcs7_enveloped:
M_ASN1_I2D_len(a->d.enveloped,i2d_PKCS7_ENVELOPE);
break;
case NID_pkcs7_signedAndEnveloped:
M_ASN1_I2D_len(a->d.signed_and_enveloped,
i2d_PKCS7_SIGN_ENVELOPE);
break;
case NID_pkcs7_digest:
M_ASN1_I2D_len(a->d.digest,i2d_PKCS7_DIGEST);
break;
case NID_pkcs7_encrypted:
M_ASN1_I2D_len(a->d.encrypted,i2d_PKCS7_ENCRYPT);
break;
default:
break;
}
}
r=ret;
if (pp == NULL) return(r);
p= *pp;
M_ASN1_I2D_INF_seq_start(V_ASN1_SEQUENCE,V_ASN1_UNIVERSAL);
M_ASN1_I2D_put(a->type,i2d_ASN1_OBJECT);
if (a->d.ptr != NULL)
{
M_ASN1_I2D_INF_seq_start(0,V_ASN1_CONTEXT_SPECIFIC);
switch (OBJ_obj2nid(a->type))
{
case NID_pkcs7_data:
M_ASN1_I2D_put(a->d.data,i2d_ASN1_OCTET_STRING);
break;
case NID_pkcs7_signed:
M_ASN1_I2D_put(a->d.sign,i2d_PKCS7_SIGNED);
break;
case NID_pkcs7_enveloped:
M_ASN1_I2D_put(a->d.enveloped,i2d_PKCS7_ENVELOPE);
break;
case NID_pkcs7_signedAndEnveloped:
M_ASN1_I2D_put(a->d.signed_and_enveloped,
i2d_PKCS7_SIGN_ENVELOPE);
break;
case NID_pkcs7_digest:
M_ASN1_I2D_put(a->d.digest,i2d_PKCS7_DIGEST);
break;
case NID_pkcs7_encrypted:
M_ASN1_I2D_put(a->d.encrypted,i2d_PKCS7_ENCRYPT);
break;
default:
break;
}
M_ASN1_I2D_INF_seq_end();
}
M_ASN1_I2D_INF_seq_end();
M_ASN1_I2D_finish();
}
PKCS7 *d2i_PKCS7(PKCS7 **a, unsigned char **pp, long length)
{
M_ASN1_D2I_vars(a,PKCS7 *,PKCS7_new);
if ((a != NULL) && ((*a) != NULL))
{
if ((*a)->asn1 != NULL)
{
Free((char *)(*a)->asn1);
(*a)->asn1=NULL;
}
(*a)->length=0;
}
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->type,d2i_ASN1_OBJECT);
if (!M_ASN1_D2I_end_sequence())
{
int Tinf,Ttag,Tclass;
long Tlen;
if (M_ASN1_next != (V_ASN1_CONSTRUCTED|
V_ASN1_CONTEXT_SPECIFIC|0))
{
c.error=ASN1_R_BAD_PKCS7_CONTENT;
c.line=__LINE__;
goto err;
}
ret->detached=0;
c.q=c.p;
Tinf=ASN1_get_object(&c.p,&Tlen,&Ttag,&Tclass,
(c.inf & 1)?(length+ *pp-c.q):c.slen);
if (Tinf & 0x80) { c.line=__LINE__; goto err; }
c.slen-=(c.p-c.q);
switch (OBJ_obj2nid(ret->type))
{
case NID_pkcs7_data:
M_ASN1_D2I_get(ret->d.data,d2i_ASN1_OCTET_STRING);
break;
case NID_pkcs7_signed:
M_ASN1_D2I_get(ret->d.sign,d2i_PKCS7_SIGNED);
if (ret->d.sign->contents->d.ptr == NULL)
ret->detached=1;
break;
case NID_pkcs7_enveloped:
M_ASN1_D2I_get(ret->d.enveloped,d2i_PKCS7_ENVELOPE);
break;
case NID_pkcs7_signedAndEnveloped:
M_ASN1_D2I_get(ret->d.signed_and_enveloped,
d2i_PKCS7_SIGN_ENVELOPE);
break;
case NID_pkcs7_digest:
M_ASN1_D2I_get(ret->d.digest,d2i_PKCS7_DIGEST);
break;
case NID_pkcs7_encrypted:
M_ASN1_D2I_get(ret->d.encrypted,d2i_PKCS7_ENCRYPT);
break;
default:
c.error=ASN1_R_BAD_PKCS7_TYPE;
c.line=__LINE__;
goto err;
}
if (Tinf == (1|V_ASN1_CONSTRUCTED))
{
if (!ASN1_check_infinite_end(&c.p,c.slen))
{
c.error=ERR_R_MISSING_ASN1_EOS;
c.line=__LINE__;
goto err;
}
}
}
else
ret->detached=1;
M_ASN1_D2I_Finish(a,PKCS7_free,ASN1_F_D2I_PKCS7);
}
PKCS7 *PKCS7_new(void)
{
PKCS7 *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,PKCS7);
ret->type=OBJ_nid2obj(NID_undef);
ret->asn1=NULL;
ret->length=0;
ret->detached=0;
ret->d.ptr=NULL;
return(ret);
M_ASN1_New_Error(ASN1_F_PKCS7_NEW);
}
void PKCS7_free(PKCS7 *a)
{
if (a == NULL) return;
PKCS7_content_free(a);
if (a->type != NULL)
{
ASN1_OBJECT_free(a->type);
}
Free((char *)(char *)a);
}
void PKCS7_content_free(PKCS7 *a)
{
if(a == NULL)
return;
if (a->asn1 != NULL) Free((char *)a->asn1);
if (a->d.ptr != NULL)
{
if (a->type == NULL) return;
switch (OBJ_obj2nid(a->type))
{
case NID_pkcs7_data:
ASN1_OCTET_STRING_free(a->d.data);
break;
case NID_pkcs7_signed:
PKCS7_SIGNED_free(a->d.sign);
break;
case NID_pkcs7_enveloped:
PKCS7_ENVELOPE_free(a->d.enveloped);
break;
case NID_pkcs7_signedAndEnveloped:
PKCS7_SIGN_ENVELOPE_free(a->d.signed_and_enveloped);
break;
case NID_pkcs7_digest:
PKCS7_DIGEST_free(a->d.digest);
break;
case NID_pkcs7_encrypted:
PKCS7_ENCRYPT_free(a->d.encrypted);
break;
default:
break;
}
}
a->d.ptr=NULL;
}
