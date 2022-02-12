int NETSCAPE_SPKI_print(BIO *out, NETSCAPE_SPKI *spki)
{
EVP_PKEY *pkey;
ASN1_IA5STRING *chal;
int i, n;
char *s;
BIO_printf(out, "Netscape SPKI:\n");
i = OBJ_obj2nid(spki->spkac->pubkey->algor->algorithm);
BIO_printf(out, " Public Key Algorithm: %s\n",
(i == NID_undef) ? "UNKNOWN" : OBJ_nid2ln(i));
pkey = X509_PUBKEY_get(spki->spkac->pubkey);
if (!pkey)
BIO_printf(out, " Unable to load public key\n");
else {
EVP_PKEY_print_public(out, pkey, 4, NULL);
EVP_PKEY_free(pkey);
}
chal = spki->spkac->challenge;
if (chal->length)
BIO_printf(out, " Challenge String: %s\n", chal->data);
i = OBJ_obj2nid(spki->sig_algor->algorithm);
BIO_printf(out, " Signature Algorithm: %s",
(i == NID_undef) ? "UNKNOWN" : OBJ_nid2ln(i));
n = spki->signature->length;
s = (char *)spki->signature->data;
for (i = 0; i < n; i++) {
if ((i % 18) == 0)
BIO_write(out, "\n ", 7);
BIO_printf(out, "%02x%s", (unsigned char)s[i],
((i + 1) == n) ? "" : ":");
}
BIO_write(out, "\n", 1);
return 1;
}
