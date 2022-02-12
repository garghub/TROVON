int TS_REQ_print_bio(BIO *bio, TS_REQ *a)
{
int v;
ASN1_OBJECT *policy_id;
const ASN1_INTEGER *nonce;
if (a == NULL)
return 0;
v = TS_REQ_get_version(a);
BIO_printf(bio, "Version: %d\n", v);
TS_MSG_IMPRINT_print_bio(bio, TS_REQ_get_msg_imprint(a));
BIO_printf(bio, "Policy OID: ");
policy_id = TS_REQ_get_policy_id(a);
if (policy_id == NULL)
BIO_printf(bio, "unspecified\n");
else
TS_OBJ_print_bio(bio, policy_id);
BIO_printf(bio, "Nonce: ");
nonce = TS_REQ_get_nonce(a);
if (nonce == NULL)
BIO_printf(bio, "unspecified");
else
TS_ASN1_INTEGER_print_bio(bio, nonce);
BIO_write(bio, "\n", 1);
BIO_printf(bio, "Certificate required: %s\n",
TS_REQ_get_cert_req(a) ? "yes" : "no");
TS_ext_print_bio(bio, TS_REQ_get_exts(a));
return 1;
}
