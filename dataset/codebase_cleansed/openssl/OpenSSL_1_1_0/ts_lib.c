int TS_ASN1_INTEGER_print_bio(BIO *bio, const ASN1_INTEGER *num)
{
BIGNUM *num_bn;
int result = 0;
char *hex;
num_bn = BN_new();
if (num_bn == NULL)
return -1;
ASN1_INTEGER_to_BN(num, num_bn);
if ((hex = BN_bn2hex(num_bn))) {
result = BIO_write(bio, "0x", 2) > 0;
result = result && BIO_write(bio, hex, strlen(hex)) > 0;
OPENSSL_free(hex);
}
BN_free(num_bn);
return result;
}
int TS_OBJ_print_bio(BIO *bio, const ASN1_OBJECT *obj)
{
char obj_txt[128];
OBJ_obj2txt(obj_txt, sizeof(obj_txt), obj, 0);
BIO_printf(bio, "%s\n", obj_txt);
return 1;
}
int TS_X509_ALGOR_print_bio(BIO *bio, const X509_ALGOR *alg)
{
int i = OBJ_obj2nid(alg->algorithm);
return BIO_printf(bio, "Hash Algorithm: %s\n",
(i == NID_undef) ? "UNKNOWN" : OBJ_nid2ln(i));
}
int TS_MSG_IMPRINT_print_bio(BIO *bio, TS_MSG_IMPRINT *a)
{
ASN1_OCTET_STRING *msg;
TS_X509_ALGOR_print_bio(bio, a->hash_algo);
BIO_printf(bio, "Message data:\n");
msg = a->hashed_msg;
BIO_dump_indent(bio, (const char *)ASN1_STRING_get0_data(msg),
ASN1_STRING_length(msg), 4);
return 1;
}
