static int rinf_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
X509_REQ_INFO *rinf = (X509_REQ_INFO *)*pval;
if (operation == ASN1_OP_NEW_POST) {
rinf->attributes = sk_X509_ATTRIBUTE_new_null();
if (!rinf->attributes)
return 0;
}
return 1;
}
