STACK *i2v_GENERAL_NAME(X509V3_EXT_METHOD *method, GENERAL_NAME *gen,
STACK *ret)
{
char oline[256];
unsigned char *p;
switch (gen->type)
{
case GEN_OTHERNAME:
X509V3_add_value("othername","<unsupported>", &ret);
break;
case GEN_X400:
X509V3_add_value("X400Name","<unsupported>", &ret);
break;
case GEN_EDIPARTY:
X509V3_add_value("EdiPartyName","<unsupported>", &ret);
break;
case GEN_EMAIL:
X509V3_add_value_uchar("email",gen->d.ia5->data, &ret);
break;
case GEN_DNS:
X509V3_add_value_uchar("DNS",gen->d.ia5->data, &ret);
break;
case GEN_URI:
X509V3_add_value_uchar("URI",gen->d.ia5->data, &ret);
break;
case GEN_DIRNAME:
X509_NAME_oneline(gen->d.dirn, oline, 256);
X509V3_add_value("DirName",oline, &ret);
break;
case GEN_IPADD:
p = gen->d.ip->data;
if(gen->d.ip->length != 4) {
X509V3_add_value("IP Address","<invalid>", &ret);
break;
}
sprintf(oline, "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
X509V3_add_value("IP Address",oline, &ret);
break;
case GEN_RID:
i2t_ASN1_OBJECT(oline, 256, gen->d.rid);
X509V3_add_value("Registered ID",oline, &ret);
break;
}
return ret;
}
