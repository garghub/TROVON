static int skip_asn1(unsigned char **pp, long *plen, int exptag)
{
const unsigned char *q = *pp;
int i, tag, xclass;
long tmplen;
i = ASN1_get_object(&q, &tmplen, &tag, &xclass, *plen);
if (i & 0x80)
return 0;
if (tag != exptag || xclass != V_ASN1_UNIVERSAL)
return 0;
if (tag == V_ASN1_OBJECT)
q += tmplen;
*plen -= q - *pp;
*pp = (unsigned char *)q;
return 1;
}
static int dh_sharedinfo_encode(unsigned char **pder, unsigned char **pctr,
ASN1_OBJECT *key_oid, size_t outlen,
const unsigned char *ukm, size_t ukmlen)
{
unsigned char *p;
int derlen;
long tlen;
static unsigned char ctr[4] = { 0xF3, 0x17, 0x22, 0x53 };
X509_ALGOR atmp;
ASN1_OCTET_STRING ctr_oct, ukm_oct, *pukm_oct;
ASN1_TYPE ctr_atype;
if (ukmlen > DH_KDF_MAX || outlen > DH_KDF_MAX)
return 0;
ctr_oct.data = ctr;
ctr_oct.length = 4;
ctr_oct.flags = 0;
ctr_oct.type = V_ASN1_OCTET_STRING;
ctr_atype.type = V_ASN1_OCTET_STRING;
ctr_atype.value.octet_string = &ctr_oct;
atmp.algorithm = key_oid;
atmp.parameter = &ctr_atype;
if (ukm) {
ukm_oct.type = V_ASN1_OCTET_STRING;
ukm_oct.flags = 0;
ukm_oct.data = (unsigned char *)ukm;
ukm_oct.length = ukmlen;
pukm_oct = &ukm_oct;
} else
pukm_oct = NULL;
derlen = CMS_SharedInfo_encode(pder, &atmp, pukm_oct, outlen);
if (derlen <= 0)
return 0;
p = *pder;
tlen = derlen;
if (!skip_asn1(&p, &tlen, V_ASN1_SEQUENCE))
return 0;
if (!skip_asn1(&p, &tlen, V_ASN1_SEQUENCE))
return 0;
if (!skip_asn1(&p, &tlen, V_ASN1_OBJECT))
return 0;
if (!skip_asn1(&p, &tlen, V_ASN1_OCTET_STRING))
return 0;
if (CRYPTO_memcmp(p, ctr, 4))
return 0;
*pctr = p;
return derlen;
}
int DH_KDF_X9_42(unsigned char *out, size_t outlen,
const unsigned char *Z, size_t Zlen,
ASN1_OBJECT *key_oid,
const unsigned char *ukm, size_t ukmlen, const EVP_MD *md)
{
EVP_MD_CTX mctx;
int rv = 0;
unsigned int i;
size_t mdlen;
unsigned char *der = NULL, *ctr;
int derlen;
if (Zlen > DH_KDF_MAX)
return 0;
mdlen = EVP_MD_size(md);
EVP_MD_CTX_init(&mctx);
derlen = dh_sharedinfo_encode(&der, &ctr, key_oid, outlen, ukm, ukmlen);
if (derlen == 0)
goto err;
for (i = 1;; i++) {
unsigned char mtmp[EVP_MAX_MD_SIZE];
EVP_DigestInit_ex(&mctx, md, NULL);
if (!EVP_DigestUpdate(&mctx, Z, Zlen))
goto err;
ctr[3] = i & 0xFF;
ctr[2] = (i >> 8) & 0xFF;
ctr[1] = (i >> 16) & 0xFF;
ctr[0] = (i >> 24) & 0xFF;
if (!EVP_DigestUpdate(&mctx, der, derlen))
goto err;
if (outlen >= mdlen) {
if (!EVP_DigestFinal(&mctx, out, NULL))
goto err;
outlen -= mdlen;
if (outlen == 0)
break;
out += mdlen;
} else {
if (!EVP_DigestFinal(&mctx, mtmp, NULL))
goto err;
memcpy(out, mtmp, outlen);
OPENSSL_cleanse(mtmp, mdlen);
break;
}
}
rv = 1;
err:
if (der)
OPENSSL_free(der);
EVP_MD_CTX_cleanup(&mctx);
return rv;
}
