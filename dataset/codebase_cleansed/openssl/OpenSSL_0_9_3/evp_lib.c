int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c, ASN1_TYPE *type)
{
int ret;
if (c->cipher->set_asn1_parameters != NULL)
ret=c->cipher->set_asn1_parameters(c,type);
else
ret=1;
return(ret);
}
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *c, ASN1_TYPE *type)
{
int ret;
if (c->cipher->get_asn1_parameters != NULL)
ret=c->cipher->get_asn1_parameters(c,type);
else
ret=1;
return(ret);
}
int EVP_CIPHER_get_asn1_iv(EVP_CIPHER_CTX *c, ASN1_TYPE *type)
{
int i=0,l;
if (type != NULL)
{
l=EVP_CIPHER_CTX_iv_length(c);
i=ASN1_TYPE_get_octetstring(type,c->oiv,l);
if (i != l)
return(-1);
else if (i > 0)
memcpy(c->iv,c->oiv,l);
}
return(i);
}
int EVP_CIPHER_set_asn1_iv(EVP_CIPHER_CTX *c, ASN1_TYPE *type)
{
int i=0,j;
if (type != NULL)
{
j=EVP_CIPHER_CTX_iv_length(c);
i=ASN1_TYPE_set_octetstring(type,c->oiv,j);
}
return(i);
}
int EVP_CIPHER_type(const EVP_CIPHER *ctx)
{
int nid;
nid = EVP_CIPHER_nid(ctx);
switch(nid) {
case NID_rc2_cbc:
case NID_rc2_64_cbc:
case NID_rc2_40_cbc:
return NID_rc2_cbc;
case NID_rc4:
case NID_rc4_40:
return NID_rc4;
default:
return nid;
}
}
