int PKCS7_add_attrib_smimecap(PKCS7_SIGNER_INFO *si, STACK *cap)
{
ASN1_STRING *seq;
unsigned char *p, *pp;
int len;
len=i2d_ASN1_SET(cap,NULL,i2d_X509_ALGOR, V_ASN1_SEQUENCE,
V_ASN1_UNIVERSAL, IS_SEQUENCE);
if(!(pp=(unsigned char *)Malloc(len))) {
PKCS7err(PKCS7_F_PKCS7_ADD_ATTRIB_SMIMECAP,ERR_R_MALLOC_FAILURE);
return 0;
}
p=pp;
i2d_ASN1_SET(cap,&p,i2d_X509_ALGOR, V_ASN1_SEQUENCE,
V_ASN1_UNIVERSAL, IS_SEQUENCE);
if(!(seq = ASN1_STRING_new())) {
PKCS7err(PKCS7_F_PKCS7_ADD_ATTRIB_SMIMECAP,ERR_R_MALLOC_FAILURE);
return 0;
}
if(!ASN1_STRING_set (seq, pp, len)) {
PKCS7err(PKCS7_F_PKCS7_ADD_ATTRIB_SMIMECAP,ERR_R_MALLOC_FAILURE);
return 0;
}
Free (pp);
return PKCS7_add_signed_attribute(si, NID_SMIMECapabilities,
V_ASN1_SEQUENCE, seq);
}
STACK *PKCS7_get_smimecap(PKCS7_SIGNER_INFO *si)
{
ASN1_TYPE *cap;
unsigned char *p;
cap = PKCS7_get_signed_attribute(si, NID_SMIMECapabilities);
if (!cap) return NULL;
p = cap->value.sequence->data;
return d2i_ASN1_SET (NULL, &p, cap->value.sequence->length,
(char *(*)())d2i_X509_ALGOR, X509_ALGOR_free, V_ASN1_SEQUENCE,
V_ASN1_UNIVERSAL);
}
int PKCS7_simple_smimecap(STACK *sk, int nid, int arg)
{
X509_ALGOR *alg;
if(!(alg = X509_ALGOR_new())) {
PKCS7err(PKCS7_F_PKCS7_SIMPLE_SMIMECAP,ERR_R_MALLOC_FAILURE);
return 0;
}
ASN1_OBJECT_free(alg->algorithm);
alg->algorithm = OBJ_nid2obj (nid);
if (arg > 0) {
ASN1_INTEGER *nbit;
if(!(alg->parameter = ASN1_TYPE_new())) {
PKCS7err(PKCS7_F_PKCS7_SIMPLE_SMIMECAP,ERR_R_MALLOC_FAILURE);
return 0;
}
if(!(nbit = ASN1_INTEGER_new())) {
PKCS7err(PKCS7_F_PKCS7_SIMPLE_SMIMECAP,ERR_R_MALLOC_FAILURE);
return 0;
}
if(!ASN1_INTEGER_set (nbit, arg)) {
PKCS7err(PKCS7_F_PKCS7_SIMPLE_SMIMECAP,ERR_R_MALLOC_FAILURE);
return 0;
}
alg->parameter->value.integer = nbit;
alg->parameter->type = V_ASN1_INTEGER;
}
sk_push (sk, (char *)alg);
return 1;
}
