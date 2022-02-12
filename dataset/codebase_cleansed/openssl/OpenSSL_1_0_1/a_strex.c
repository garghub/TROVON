static int send_bio_chars(void *arg, const void *buf, int len)
{
if(!arg) return 1;
if(BIO_write(arg, buf, len) != len) return 0;
return 1;
}
static int send_fp_chars(void *arg, const void *buf, int len)
{
if(!arg) return 1;
if(fwrite(buf, 1, len, arg) != (unsigned int)len) return 0;
return 1;
}
static int do_esc_char(unsigned long c, unsigned char flags, char *do_quotes, char_io *io_ch, void *arg)
{
unsigned char chflgs, chtmp;
char tmphex[HEX_SIZE(long)+3];
if(c > 0xffffffffL)
return -1;
if(c > 0xffff) {
BIO_snprintf(tmphex, sizeof tmphex, "\\W%08lX", c);
if(!io_ch(arg, tmphex, 10)) return -1;
return 10;
}
if(c > 0xff) {
BIO_snprintf(tmphex, sizeof tmphex, "\\U%04lX", c);
if(!io_ch(arg, tmphex, 6)) return -1;
return 6;
}
chtmp = (unsigned char)c;
if(chtmp > 0x7f) chflgs = flags & ASN1_STRFLGS_ESC_MSB;
else chflgs = char_type[chtmp] & flags;
if(chflgs & CHARTYPE_BS_ESC) {
if(chflgs & ASN1_STRFLGS_ESC_QUOTE) {
if(do_quotes) *do_quotes = 1;
if(!io_ch(arg, &chtmp, 1)) return -1;
return 1;
}
if(!io_ch(arg, "\\", 1)) return -1;
if(!io_ch(arg, &chtmp, 1)) return -1;
return 2;
}
if(chflgs & (ASN1_STRFLGS_ESC_CTRL|ASN1_STRFLGS_ESC_MSB)) {
BIO_snprintf(tmphex, 11, "\\%02X", chtmp);
if(!io_ch(arg, tmphex, 3)) return -1;
return 3;
}
if (chtmp == '\\' && flags & ESC_FLAGS) {
if(!io_ch(arg, "\\\\", 2)) return -1;
return 2;
}
if(!io_ch(arg, &chtmp, 1)) return -1;
return 1;
}
static int do_buf(unsigned char *buf, int buflen,
int type, unsigned char flags, char *quotes, char_io *io_ch, void *arg)
{
int i, outlen, len;
unsigned char orflags, *p, *q;
unsigned long c;
p = buf;
q = buf + buflen;
outlen = 0;
while(p != q) {
if(p == buf && flags & ASN1_STRFLGS_ESC_2253) orflags = CHARTYPE_FIRST_ESC_2253;
else orflags = 0;
switch(type & BUF_TYPE_WIDTH_MASK) {
case 4:
c = ((unsigned long)*p++) << 24;
c |= ((unsigned long)*p++) << 16;
c |= ((unsigned long)*p++) << 8;
c |= *p++;
break;
case 2:
c = ((unsigned long)*p++) << 8;
c |= *p++;
break;
case 1:
c = *p++;
break;
case 0:
i = UTF8_getc(p, buflen, &c);
if(i < 0) return -1;
p += i;
break;
default:
return -1;
}
if (p == q && flags & ASN1_STRFLGS_ESC_2253) orflags = CHARTYPE_LAST_ESC_2253;
if(type & BUF_TYPE_CONVUTF8) {
unsigned char utfbuf[6];
int utflen;
utflen = UTF8_putc(utfbuf, sizeof utfbuf, c);
for(i = 0; i < utflen; i++) {
len = do_esc_char(utfbuf[i], (unsigned char)(flags | orflags), quotes, io_ch, arg);
if(len < 0) return -1;
outlen += len;
}
} else {
len = do_esc_char(c, (unsigned char)(flags | orflags), quotes, io_ch, arg);
if(len < 0) return -1;
outlen += len;
}
}
return outlen;
}
static int do_hex_dump(char_io *io_ch, void *arg, unsigned char *buf, int buflen)
{
static const char hexdig[] = "0123456789ABCDEF";
unsigned char *p, *q;
char hextmp[2];
if(arg) {
p = buf;
q = buf + buflen;
while(p != q) {
hextmp[0] = hexdig[*p >> 4];
hextmp[1] = hexdig[*p & 0xf];
if(!io_ch(arg, hextmp, 2)) return -1;
p++;
}
}
return buflen << 1;
}
static int do_dump(unsigned long lflags, char_io *io_ch, void *arg, ASN1_STRING *str)
{
ASN1_TYPE t;
unsigned char *der_buf, *p;
int outlen, der_len;
if(!io_ch(arg, "#", 1)) return -1;
if(!(lflags & ASN1_STRFLGS_DUMP_DER)) {
outlen = do_hex_dump(io_ch, arg, str->data, str->length);
if(outlen < 0) return -1;
return outlen + 1;
}
t.type = str->type;
t.value.ptr = (char *)str;
der_len = i2d_ASN1_TYPE(&t, NULL);
der_buf = OPENSSL_malloc(der_len);
if(!der_buf) return -1;
p = der_buf;
i2d_ASN1_TYPE(&t, &p);
outlen = do_hex_dump(io_ch, arg, der_buf, der_len);
OPENSSL_free(der_buf);
if(outlen < 0) return -1;
return outlen + 1;
}
static int do_print_ex(char_io *io_ch, void *arg, unsigned long lflags, ASN1_STRING *str)
{
int outlen, len;
int type;
char quotes;
unsigned char flags;
quotes = 0;
flags = (unsigned char)(lflags & ESC_FLAGS);
type = str->type;
outlen = 0;
if(lflags & ASN1_STRFLGS_SHOW_TYPE) {
const char *tagname;
tagname = ASN1_tag2str(type);
outlen += strlen(tagname);
if(!io_ch(arg, tagname, outlen) || !io_ch(arg, ":", 1)) return -1;
outlen++;
}
if(lflags & ASN1_STRFLGS_DUMP_ALL) type = -1;
else if(lflags & ASN1_STRFLGS_IGNORE_TYPE) type = 1;
else {
if((type > 0) && (type < 31)) type = tag2nbyte[type];
else type = -1;
if((type == -1) && !(lflags & ASN1_STRFLGS_DUMP_UNKNOWN)) type = 1;
}
if(type == -1) {
len = do_dump(lflags, io_ch, arg, str);
if(len < 0) return -1;
outlen += len;
return outlen;
}
if(lflags & ASN1_STRFLGS_UTF8_CONVERT) {
if(!type) type = 1;
else type |= BUF_TYPE_CONVUTF8;
}
len = do_buf(str->data, str->length, type, flags, &quotes, io_ch, NULL);
if(len < 0) return -1;
outlen += len;
if(quotes) outlen += 2;
if(!arg) return outlen;
if(quotes && !io_ch(arg, "\"", 1)) return -1;
if(do_buf(str->data, str->length, type, flags, NULL, io_ch, arg) < 0)
return -1;
if(quotes && !io_ch(arg, "\"", 1)) return -1;
return outlen;
}
static int do_indent(char_io *io_ch, void *arg, int indent)
{
int i;
for(i = 0; i < indent; i++)
if(!io_ch(arg, " ", 1)) return 0;
return 1;
}
static int do_name_ex(char_io *io_ch, void *arg, X509_NAME *n,
int indent, unsigned long flags)
{
int i, prev = -1, orflags, cnt;
int fn_opt, fn_nid;
ASN1_OBJECT *fn;
ASN1_STRING *val;
X509_NAME_ENTRY *ent;
char objtmp[80];
const char *objbuf;
int outlen, len;
char *sep_dn, *sep_mv, *sep_eq;
int sep_dn_len, sep_mv_len, sep_eq_len;
if(indent < 0) indent = 0;
outlen = indent;
if(!do_indent(io_ch, arg, indent)) return -1;
switch (flags & XN_FLAG_SEP_MASK)
{
case XN_FLAG_SEP_MULTILINE:
sep_dn = "\n";
sep_dn_len = 1;
sep_mv = " + ";
sep_mv_len = 3;
break;
case XN_FLAG_SEP_COMMA_PLUS:
sep_dn = ",";
sep_dn_len = 1;
sep_mv = "+";
sep_mv_len = 1;
indent = 0;
break;
case XN_FLAG_SEP_CPLUS_SPC:
sep_dn = ", ";
sep_dn_len = 2;
sep_mv = " + ";
sep_mv_len = 3;
indent = 0;
break;
case XN_FLAG_SEP_SPLUS_SPC:
sep_dn = "; ";
sep_dn_len = 2;
sep_mv = " + ";
sep_mv_len = 3;
indent = 0;
break;
default:
return -1;
}
if(flags & XN_FLAG_SPC_EQ) {
sep_eq = " = ";
sep_eq_len = 3;
} else {
sep_eq = "=";
sep_eq_len = 1;
}
fn_opt = flags & XN_FLAG_FN_MASK;
cnt = X509_NAME_entry_count(n);
for(i = 0; i < cnt; i++) {
if(flags & XN_FLAG_DN_REV)
ent = X509_NAME_get_entry(n, cnt - i - 1);
else ent = X509_NAME_get_entry(n, i);
if(prev != -1) {
if(prev == ent->set) {
if(!io_ch(arg, sep_mv, sep_mv_len)) return -1;
outlen += sep_mv_len;
} else {
if(!io_ch(arg, sep_dn, sep_dn_len)) return -1;
outlen += sep_dn_len;
if(!do_indent(io_ch, arg, indent)) return -1;
outlen += indent;
}
}
prev = ent->set;
fn = X509_NAME_ENTRY_get_object(ent);
val = X509_NAME_ENTRY_get_data(ent);
fn_nid = OBJ_obj2nid(fn);
if(fn_opt != XN_FLAG_FN_NONE) {
int objlen, fld_len;
if((fn_opt == XN_FLAG_FN_OID) || (fn_nid==NID_undef) ) {
OBJ_obj2txt(objtmp, sizeof objtmp, fn, 1);
fld_len = 0;
objbuf = objtmp;
} else {
if(fn_opt == XN_FLAG_FN_SN) {
fld_len = FN_WIDTH_SN;
objbuf = OBJ_nid2sn(fn_nid);
} else if(fn_opt == XN_FLAG_FN_LN) {
fld_len = FN_WIDTH_LN;
objbuf = OBJ_nid2ln(fn_nid);
} else {
fld_len = 0;
objbuf = "";
}
}
objlen = strlen(objbuf);
if(!io_ch(arg, objbuf, objlen)) return -1;
if ((objlen < fld_len) && (flags & XN_FLAG_FN_ALIGN)) {
if (!do_indent(io_ch, arg, fld_len - objlen)) return -1;
outlen += fld_len - objlen;
}
if(!io_ch(arg, sep_eq, sep_eq_len)) return -1;
outlen += objlen + sep_eq_len;
}
if((fn_nid == NID_undef) && (flags & XN_FLAG_DUMP_UNKNOWN_FIELDS))
orflags = ASN1_STRFLGS_DUMP_ALL;
else orflags = 0;
len = do_print_ex(io_ch, arg, flags | orflags, val);
if(len < 0) return -1;
outlen += len;
}
return outlen;
}
int X509_NAME_print_ex(BIO *out, X509_NAME *nm, int indent, unsigned long flags)
{
if(flags == XN_FLAG_COMPAT)
return X509_NAME_print(out, nm, indent);
return do_name_ex(send_bio_chars, out, nm, indent, flags);
}
int X509_NAME_print_ex_fp(FILE *fp, X509_NAME *nm, int indent, unsigned long flags)
{
if(flags == XN_FLAG_COMPAT)
{
BIO *btmp;
int ret;
btmp = BIO_new_fp(fp, BIO_NOCLOSE);
if(!btmp) return -1;
ret = X509_NAME_print(btmp, nm, indent);
BIO_free(btmp);
return ret;
}
return do_name_ex(send_fp_chars, fp, nm, indent, flags);
}
int ASN1_STRING_print_ex(BIO *out, ASN1_STRING *str, unsigned long flags)
{
return do_print_ex(send_bio_chars, out, flags, str);
}
int ASN1_STRING_print_ex_fp(FILE *fp, ASN1_STRING *str, unsigned long flags)
{
return do_print_ex(send_fp_chars, fp, flags, str);
}
int ASN1_STRING_to_UTF8(unsigned char **out, ASN1_STRING *in)
{
ASN1_STRING stmp, *str = &stmp;
int mbflag, type, ret;
if(!in) return -1;
type = in->type;
if((type < 0) || (type > 30)) return -1;
mbflag = tag2nbyte[type];
if(mbflag == -1) return -1;
mbflag |= MBSTRING_FLAG;
stmp.data = NULL;
ret = ASN1_mbstring_copy(&str, in->data, in->length, mbflag, B_ASN1_UTF8STRING);
if(ret < 0) return ret;
*out = stmp.data;
return stmp.length;
}
