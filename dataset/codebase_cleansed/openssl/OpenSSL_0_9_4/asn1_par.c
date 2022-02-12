static int asn1_print_info(BIO *bp, int tag, int xclass, int constructed,
int indent)
{
static const char fmt[]="%-18s";
static const char fmt2[]="%2d %-15s";
char str[128];
const char *p,*p2=NULL;
if (constructed & V_ASN1_CONSTRUCTED)
p="cons: ";
else
p="prim: ";
if (BIO_write(bp,p,6) < 6) goto err;
if (indent)
{
if (indent > 128) indent=128;
memset(str,' ',indent);
if (BIO_write(bp,str,indent) < indent) goto err;
}
p=str;
if ((xclass & V_ASN1_PRIVATE) == V_ASN1_PRIVATE)
sprintf(str,"priv [ %d ] ",tag);
else if ((xclass & V_ASN1_CONTEXT_SPECIFIC) == V_ASN1_CONTEXT_SPECIFIC)
sprintf(str,"cont [ %d ]",tag);
else if ((xclass & V_ASN1_APPLICATION) == V_ASN1_APPLICATION)
sprintf(str,"appl [ %d ]",tag);
else if ((tag == V_ASN1_EOC) )
p="EOC";
else if (tag == V_ASN1_BOOLEAN)
p="BOOLEAN";
else if (tag == V_ASN1_INTEGER)
p="INTEGER";
else if (tag == V_ASN1_ENUMERATED)
p="ENUMERATED";
else if (tag == V_ASN1_BIT_STRING)
p="BIT STRING";
else if (tag == V_ASN1_OCTET_STRING)
p="OCTET STRING";
else if (tag == V_ASN1_NULL)
p="NULL";
else if (tag == V_ASN1_OBJECT)
p="OBJECT";
else if (tag == V_ASN1_SEQUENCE)
p="SEQUENCE";
else if (tag == V_ASN1_SET)
p="SET";
else if (tag == V_ASN1_PRINTABLESTRING)
p="PRINTABLESTRING";
else if (tag == V_ASN1_T61STRING)
p="T61STRING";
else if (tag == V_ASN1_IA5STRING)
p="IA5STRING";
else if (tag == V_ASN1_UTCTIME)
p="UTCTIME";
else if (tag == V_ASN1_NUMERICSTRING)
p="NUMERICSTRING";
else if (tag == V_ASN1_VIDEOTEXSTRING)
p="VIDEOTEXSTRING";
else if (tag == V_ASN1_GENERALIZEDTIME)
p="GENERALIZEDTIME";
else if (tag == V_ASN1_GRAPHICSTRING)
p="GRAPHICSTRING";
else if (tag == V_ASN1_VISIBLESTRING)
p="VISIBLESTRING";
else if (tag == V_ASN1_GENERALSTRING)
p="GENERALSTRING";
else if (tag == V_ASN1_UNIVERSALSTRING)
p="UNIVERSALSTRING";
else if (tag == V_ASN1_BMPSTRING)
p="BMPSTRING";
else
p2="(unknown)";
if (p2 != NULL)
{
if (BIO_printf(bp,fmt2,tag,p2) <= 0) goto err;
}
else
{
if (BIO_printf(bp,fmt,p) <= 0) goto err;
}
return(1);
err:
return(0);
}
int ASN1_parse(BIO *bp, unsigned char *pp, long len, int indent)
{
return(asn1_parse2(bp,&pp,len,0,0,indent));
}
static int asn1_parse2(BIO *bp, unsigned char **pp, long length, int offset,
int depth, int indent)
{
unsigned char *p,*ep,*tot,*op,*opp;
long len;
int tag,xclass,ret=0;
int nl,hl,j,r;
ASN1_OBJECT *o=NULL;
ASN1_OCTET_STRING *os=NULL;
p= *pp;
tot=p+length;
op=p-1;
while ((p < tot) && (op < p))
{
op=p;
j=ASN1_get_object(&p,&len,&tag,&xclass,length);
#ifdef LINT
j=j;
#endif
if (j & 0x80)
{
if (BIO_write(bp,"Error in encoding\n",18) <= 0)
goto end;
ret=0;
goto end;
}
hl=(p-op);
length-=hl;
if (BIO_printf(bp,"%5ld:",(long)offset+(long)(op- *pp))
<= 0) goto end;
if (j != (V_ASN1_CONSTRUCTED | 1))
{
if (BIO_printf(bp,"d=%-2d hl=%ld l=%4ld ",
depth,(long)hl,len) <= 0)
goto end;
}
else
{
if (BIO_printf(bp,"d=%-2d hl=%ld l=inf ",
depth,(long)hl) <= 0)
goto end;
}
if (!asn1_print_info(bp,tag,xclass,j,(indent)?depth:0))
goto end;
if (j & V_ASN1_CONSTRUCTED)
{
ep=p+len;
if (BIO_write(bp,"\n",1) <= 0) goto end;
if (len > length)
{
BIO_printf(bp,
"length is greater than %ld\n",length);
ret=0;
goto end;
}
if ((j == 0x21) && (len == 0))
{
for (;;)
{
r=asn1_parse2(bp,&p,(long)(tot-p),
offset+(p - *pp),depth+1,
indent);
if (r == 0) { ret=0; goto end; }
if ((r == 2) || (p >= tot)) break;
}
}
else
while (p < ep)
{
r=asn1_parse2(bp,&p,(long)len,
offset+(p - *pp),depth+1,
indent);
if (r == 0) { ret=0; goto end; }
}
}
else if (xclass != 0)
{
p+=len;
if (BIO_write(bp,"\n",1) <= 0) goto end;
}
else
{
nl=0;
if ( (tag == V_ASN1_PRINTABLESTRING) ||
(tag == V_ASN1_T61STRING) ||
(tag == V_ASN1_IA5STRING) ||
(tag == V_ASN1_VISIBLESTRING) ||
(tag == V_ASN1_UTCTIME) ||
(tag == V_ASN1_GENERALIZEDTIME))
{
if (BIO_write(bp,":",1) <= 0) goto end;
if ((len > 0) &&
BIO_write(bp,(char *)p,(int)len)
!= (int)len)
goto end;
}
else if (tag == V_ASN1_OBJECT)
{
opp=op;
if (d2i_ASN1_OBJECT(&o,&opp,len+hl) != NULL)
{
if (BIO_write(bp,":",1) <= 0) goto end;
i2a_ASN1_OBJECT(bp,o);
}
else
{
if (BIO_write(bp,":BAD OBJECT",11) <= 0)
goto end;
}
}
else if (tag == V_ASN1_BOOLEAN)
{
int ii;
opp=op;
ii=d2i_ASN1_BOOLEAN(NULL,&opp,len+hl);
if (ii < 0)
{
if (BIO_write(bp,"Bad boolean\n",12))
goto end;
}
BIO_printf(bp,":%d",ii);
}
else if (tag == V_ASN1_BMPSTRING)
{
}
else if (tag == V_ASN1_OCTET_STRING)
{
int i,printable=1;
opp=op;
os=d2i_ASN1_OCTET_STRING(NULL,&opp,len+hl);
if (os != NULL)
{
opp=os->data;
for (i=0; i<os->length; i++)
{
if (( (opp[i] < ' ') &&
(opp[i] != '\n') &&
(opp[i] != '\r') &&
(opp[i] != '\t')) ||
(opp[i] > '~'))
{
printable=0;
break;
}
}
if (printable && (os->length > 0))
{
if (BIO_write(bp,":",1) <= 0)
goto end;
if (BIO_write(bp,(char *)opp,
os->length) <= 0)
goto end;
}
ASN1_OCTET_STRING_free(os);
os=NULL;
}
}
else if (tag == V_ASN1_INTEGER)
{
ASN1_INTEGER *bs;
int i;
opp=op;
bs=d2i_ASN1_INTEGER(NULL,&opp,len+hl);
if (bs != NULL)
{
if (BIO_write(bp,":",1) <= 0) goto end;
if (bs->type == V_ASN1_NEG_INTEGER)
if (BIO_write(bp,"-",1) <= 0)
goto end;
for (i=0; i<bs->length; i++)
{
if (BIO_printf(bp,"%02X",
bs->data[i]) <= 0)
goto end;
}
if (bs->length == 0)
{
if (BIO_write(bp,"00",2) <= 0)
goto end;
}
}
else
{
if (BIO_write(bp,"BAD INTEGER",11) <= 0)
goto end;
}
ASN1_INTEGER_free(bs);
}
else if (tag == V_ASN1_ENUMERATED)
{
ASN1_ENUMERATED *bs;
int i;
opp=op;
bs=d2i_ASN1_ENUMERATED(NULL,&opp,len+hl);
if (bs != NULL)
{
if (BIO_write(bp,":",1) <= 0) goto end;
if (bs->type == V_ASN1_NEG_ENUMERATED)
if (BIO_write(bp,"-",1) <= 0)
goto end;
for (i=0; i<bs->length; i++)
{
if (BIO_printf(bp,"%02X",
bs->data[i]) <= 0)
goto end;
}
if (bs->length == 0)
{
if (BIO_write(bp,"00",2) <= 0)
goto end;
}
}
else
{
if (BIO_write(bp,"BAD ENUMERATED",11) <= 0)
goto end;
}
ASN1_ENUMERATED_free(bs);
}
if (!nl)
{
if (BIO_write(bp,"\n",1) <= 0) goto end;
}
p+=len;
if ((tag == V_ASN1_EOC) && (xclass == 0))
{
ret=2;
goto end;
}
}
length-=len;
}
ret=1;
end:
if (o != NULL) ASN1_OBJECT_free(o);
if (os != NULL) ASN1_OCTET_STRING_free(os);
*pp=p;
return(ret);
}
