static int pk7_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
ASN1_STREAM_ARG *sarg = exarg;
PKCS7 **pp7 = (PKCS7 **)pval;
switch (operation) {
case ASN1_OP_STREAM_PRE:
if (PKCS7_stream(&sarg->boundary, *pp7) <= 0)
return 0;
case ASN1_OP_DETACHED_PRE:
sarg->ndef_bio = PKCS7_dataInit(*pp7, sarg->out);
if (!sarg->ndef_bio)
return 0;
break;
case ASN1_OP_STREAM_POST:
case ASN1_OP_DETACHED_POST:
if (PKCS7_dataFinal(*pp7, sarg->ndef_bio) <= 0)
return 0;
break;
}
return 1;
}
