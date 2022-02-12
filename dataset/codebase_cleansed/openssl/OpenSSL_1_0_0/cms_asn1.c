static int cms_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
ASN1_STREAM_ARG *sarg = exarg;
CMS_ContentInfo *cms = NULL;
if (pval)
cms = (CMS_ContentInfo *)*pval;
else
return 1;
switch(operation)
{
case ASN1_OP_STREAM_PRE:
if (CMS_stream(&sarg->boundary, cms) <= 0)
return 0;
case ASN1_OP_DETACHED_PRE:
sarg->ndef_bio = CMS_dataInit(cms, sarg->out);
if (!sarg->ndef_bio)
return 0;
break;
case ASN1_OP_STREAM_POST:
case ASN1_OP_DETACHED_POST:
if (CMS_dataFinal(cms, sarg->ndef_bio) <= 0)
return 0;
break;
}
return 1;
}
