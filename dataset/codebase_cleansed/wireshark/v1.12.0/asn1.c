void
asn1_open(ASN1_SCK *asn1, tvbuff_t *tvb, int offset)
{
asn1->tvb = tvb;
asn1->offset = offset;
}
void
asn1_close(ASN1_SCK *asn1, int *offset)
{
*offset = asn1->offset;
}
int
asn1_octet_decode(ASN1_SCK *asn1, guchar *ch)
{
*ch = tvb_get_guint8(asn1->tvb, asn1->offset);
asn1->offset++;
return ASN1_ERR_NOERROR;
}
static int
asn1_tag_get(ASN1_SCK *asn1, guint *tag)
{
int ret;
guchar ch;
do {
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*tag <<= 7;
*tag |= ch & 0x7F;
} while ((ch & 0x80) == 0x80);
return ASN1_ERR_NOERROR;
}
int
asn1_tag_decode(ASN1_SCK *asn1, guint *tag)
{
*tag = 0;
return asn1_tag_get(asn1, tag);
}
int
asn1_id_decode(ASN1_SCK *asn1, guint *cls, guint *con, guint *tag)
{
int ret;
guchar ch;
*tag = 0;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*cls = (ch & 0xC0) >> 6;
*con = (ch & 0x20) >> 5;
*tag = (ch & 0x1F);
if (*tag == 0x1F) {
ret = asn1_tag_decode (asn1, tag);
if (ret != ASN1_ERR_NOERROR)
return ret;
}
return ASN1_ERR_NOERROR;
}
int
asn1_id_decode1(ASN1_SCK *asn1, guint *tag)
{
int ret;
guchar ch;
*tag = 0;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*tag = ch;
if ((*tag & 0x1F) == 0x1F) {
*tag = ch >> 5;
ret = asn1_tag_get (asn1, tag);
if (ret != ASN1_ERR_NOERROR)
return ret;
}
return ASN1_ERR_NOERROR;
}
int
asn1_length_decode(ASN1_SCK *asn1, gboolean *def, guint *len)
{
int ret;
guchar ch, cnt;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
if (ch == 0x80)
*def = FALSE;
else {
*def = TRUE;
if (ch < 0x80)
*len = ch;
else {
cnt = (guchar) (ch & 0x7F);
*len = 0;
while (cnt > 0) {
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*len <<= 8;
*len |= ch;
cnt--;
}
}
}
return ASN1_ERR_NOERROR;
}
int
asn1_header_decode(ASN1_SCK *asn1, guint *cls, guint *con, guint *tag,
gboolean *defp, guint *lenp)
{
int ret;
guint len = 0;
gboolean def;
ret = asn1_id_decode (asn1, cls, con, tag);
if (ret != ASN1_ERR_NOERROR)
return ret;
ret = asn1_length_decode (asn1, &def, &len);
if (ret != ASN1_ERR_NOERROR)
return ret;
*defp = def;
*lenp = len;
return ASN1_ERR_NOERROR;
}
gboolean
asn1_eoc ( ASN1_SCK *asn1, int eoc)
{
if (eoc == -1)
return (tvb_get_guint8(asn1->tvb, asn1->offset) == 0x00
&& tvb_get_guint8(asn1->tvb, asn1->offset + 1) == 0x00);
else
return (asn1->offset >= eoc);
}
int
asn1_eoc_decode (ASN1_SCK *asn1, int eoc)
{
int ret;
guchar ch;
if (eoc == -1) {
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
if (ch != 0x00)
return ASN1_ERR_EOC_MISMATCH;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
if (ch != 0x00)
return ASN1_ERR_EOC_MISMATCH;
return ASN1_ERR_NOERROR;
} else {
if (asn1->offset != eoc)
return ASN1_ERR_LENGTH_MISMATCH;
return ASN1_ERR_NOERROR;
}
}
int
asn1_null_decode ( ASN1_SCK *asn1, int enc_len)
{
int start_off = asn1->offset;
asn1->offset += enc_len;
if (asn1->offset < 0 || asn1->offset < start_off)
return ASN1_ERR_LENGTH_MISMATCH;
return ASN1_ERR_NOERROR;
}
int
asn1_bool_decode ( ASN1_SCK *asn1, int enc_len, gboolean *boolean)
{
int ret;
guchar ch;
if (enc_len != 1)
return ASN1_ERR_LENGTH_MISMATCH;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*boolean = ch ? TRUE : FALSE;
return ASN1_ERR_NOERROR;
}
int
asn1_int32_value_decode ( ASN1_SCK *asn1, int enc_len, gint32 *integer)
{
int ret;
int eoc;
guchar ch;
guint len;
eoc = asn1->offset + enc_len;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*integer = (gint) ch;
len = 1;
while (asn1->offset < eoc) {
if (++len > sizeof (gint32))
return ASN1_ERR_WRONG_LENGTH_FOR_TYPE;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*integer <<= 8;
*integer |= ch;
}
return ASN1_ERR_NOERROR;
}
int
asn1_int32_decode ( ASN1_SCK *asn1, gint32 *integer, guint *nbytes)
{
int ret;
int start;
guint cls;
guint con;
guint tag;
gboolean def;
guint enc_len;
start = asn1->offset;
ret = asn1_header_decode (asn1, &cls, &con, &tag, &def, &enc_len);
if (ret != ASN1_ERR_NOERROR)
goto done;
if (cls != ASN1_UNI || con != ASN1_PRI || tag != ASN1_INT) {
ret = ASN1_ERR_WRONG_TYPE;
goto done;
}
if (!def) {
ret = ASN1_ERR_LENGTH_NOT_DEFINITE;
goto done;
}
ret = asn1_int32_value_decode (asn1, enc_len, integer);
done:
*nbytes = asn1->offset - start;
return ret;
}
int
asn1_uint32_value_decode ( ASN1_SCK *asn1, int enc_len, guint32 *integer)
{
int ret;
int eoc;
guchar ch;
guint len;
eoc = asn1->offset + enc_len;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*integer = ch;
if (ch == 0)
len = 0;
else
len = 1;
while (asn1->offset < eoc) {
if (++len > sizeof (guint32))
return ASN1_ERR_WRONG_LENGTH_FOR_TYPE;
ret = asn1_octet_decode (asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*integer <<= 8;
*integer |= ch;
}
return ASN1_ERR_NOERROR;
}
int
asn1_uint32_decode ( ASN1_SCK *asn1, guint32 *integer, guint *nbytes)
{
int ret;
int start;
guint cls;
guint con;
guint tag;
gboolean def;
guint enc_len;
start = asn1->offset;
ret = asn1_header_decode (asn1, &cls, &con, &tag, &def, &enc_len);
if (ret != ASN1_ERR_NOERROR)
goto done;
if (cls != ASN1_UNI || con != ASN1_PRI || tag != ASN1_INT) {
ret = ASN1_ERR_WRONG_TYPE;
goto done;
}
if (!def) {
ret = ASN1_ERR_LENGTH_NOT_DEFINITE;
goto done;
}
ret = asn1_uint32_value_decode (asn1, enc_len, integer);
done:
*nbytes = asn1->offset - start;
return ret;
}
int
asn1_bits_decode ( ASN1_SCK *asn1, int enc_len, guchar **bits,
guint *len, guchar *unused)
{
int ret;
int eoc;
guchar *ptr;
eoc = asn1->offset + enc_len;
*bits = NULL;
ret = asn1_octet_decode (asn1, unused);
if (ret != ASN1_ERR_NOERROR)
return ret;
*len = 0;
if (enc_len != 0) {
tvb_ensure_bytes_exist(asn1->tvb, asn1->offset, enc_len);
*bits = (guchar *)g_malloc (enc_len);
} else {
*bits = (guchar *)g_malloc (1);
}
ptr = *bits;
while (asn1->offset < eoc) {
ret = asn1_octet_decode (asn1, (guchar *)ptr++);
if (ret != ASN1_ERR_NOERROR) {
g_free(*bits);
*bits = NULL;
return ret;
}
}
*len = (guint) (ptr - *bits);
return ASN1_ERR_NOERROR;
}
int
asn1_string_value_decode ( ASN1_SCK *asn1, int enc_len, guchar **octets)
{
int ret;
int eoc;
guchar *ptr;
if (enc_len != 0)
tvb_ensure_bytes_exist(asn1->tvb, asn1->offset, enc_len);
*octets = (guchar *)g_malloc (enc_len+1);
eoc = asn1->offset + enc_len;
ptr = *octets;
while (asn1->offset < eoc) {
ret = asn1_octet_decode (asn1, (guchar *)ptr++);
if (ret != ASN1_ERR_NOERROR) {
g_free(*octets);
*octets = NULL;
return ret;
}
}
*(guchar *)ptr = '\0';
return ASN1_ERR_NOERROR;
}
int
asn1_string_decode ( ASN1_SCK *asn1, guchar **octets, guint *str_len,
guint *nbytes, guint expected_tag)
{
int ret;
int start;
guint enc_len;
guint cls;
guint con;
guint tag;
gboolean def;
start = asn1->offset;
ret = asn1_header_decode (asn1, &cls, &con, &tag, &def, &enc_len);
if (ret != ASN1_ERR_NOERROR)
goto done;
if (cls != ASN1_UNI || con != ASN1_PRI || tag != expected_tag) {
ret = ASN1_ERR_WRONG_TYPE;
goto done;
}
if (!def) {
ret = ASN1_ERR_LENGTH_NOT_DEFINITE;
goto done;
}
ret = asn1_string_value_decode (asn1, enc_len, octets);
*str_len = enc_len;
done:
*nbytes = asn1->offset - start;
return ret;
}
int
asn1_octet_string_decode ( ASN1_SCK *asn1, guchar **octets, guint *str_len,
guint *nbytes)
{
return asn1_string_decode(asn1, octets, str_len, nbytes, ASN1_OTS);
}
int
asn1_subid_decode ( ASN1_SCK *asn1, subid_t *subid)
{
int ret;
guchar ch;
*subid = 0;
do {
ret = asn1_octet_decode(asn1, &ch);
if (ret != ASN1_ERR_NOERROR)
return ret;
*subid <<= 7;
*subid |= ch & 0x7F;
} while ((ch & 0x80) == 0x80);
return ASN1_ERR_NOERROR;
}
int
asn1_oid_value_decode ( ASN1_SCK *asn1, int enc_len, subid_t **oid, guint *len)
{
int ret;
int eoc;
subid_t subid;
guint size;
subid_t *optr;
if (enc_len < 1) {
*oid = NULL;
return ASN1_ERR_LENGTH_MISMATCH;
}
tvb_ensure_bytes_exist(asn1->tvb, asn1->offset, enc_len);
eoc = asn1->offset + enc_len;
size = enc_len + 1;
*oid = (guint32 *)g_malloc(size * sizeof(gulong));
optr = *oid;
ret = asn1_subid_decode (asn1, &subid);
if (ret != ASN1_ERR_NOERROR) {
g_free(*oid);
*oid = NULL;
return ret;
}
if (subid < 40) {
optr[0] = 0;
optr[1] = subid;
} else if (subid < 80) {
optr[0] = 1;
optr[1] = subid - 40;
} else {
optr[0] = 2;
optr[1] = subid - 80;
}
*len = 2;
optr += 2;
while (asn1->offset < eoc) {
if (++(*len) > size) {
g_free(*oid);
*oid = NULL;
return ASN1_ERR_WRONG_LENGTH_FOR_TYPE;
}
ret = asn1_subid_decode (asn1, optr++);
if (ret != ASN1_ERR_NOERROR) {
g_free(*oid);
*oid = NULL;
return ret;
}
}
return ASN1_ERR_NOERROR;
}
int
asn1_oid_decode ( ASN1_SCK *asn1, subid_t **oid, guint *len, guint *nbytes)
{
int ret;
int start;
guint cls;
guint con;
guint tag;
gboolean def;
guint enc_len;
start = asn1->offset;
ret = asn1_header_decode (asn1, &cls, &con, &tag, &def, &enc_len);
if (ret != ASN1_ERR_NOERROR)
goto done;
if (cls != ASN1_UNI || con != ASN1_PRI || tag != ASN1_OJI) {
ret = ASN1_ERR_WRONG_TYPE;
goto done;
}
if (!def) {
ret = ASN1_ERR_LENGTH_NOT_DEFINITE;
goto done;
}
ret = asn1_oid_value_decode (asn1, enc_len, oid, len);
done:
*nbytes = asn1->offset - start;
return ret;
}
int
asn1_sequence_decode ( ASN1_SCK *asn1, guint *seq_len, guint *nbytes)
{
int ret;
int start;
guint cls;
guint con;
guint tag;
gboolean def;
start = asn1->offset;
ret = asn1_header_decode(asn1, &cls, &con, &tag,
&def, seq_len);
if (ret != ASN1_ERR_NOERROR)
goto done;
if (cls != ASN1_UNI || con != ASN1_CON || tag != ASN1_SEQ) {
ret = ASN1_ERR_WRONG_TYPE;
goto done;
}
if (!def) {
ret = ASN1_ERR_LENGTH_NOT_DEFINITE;
goto done;
}
ret = ASN1_ERR_NOERROR;
done:
*nbytes = asn1->offset - start;
return ret;
}
const char *
asn1_err_to_str(int err)
{
const char *errstr;
char errstrbuf[14+1+1+11+1+1];
switch (err) {
case ASN1_ERR_EOC_MISMATCH:
errstr = "EOC mismatch";
break;
case ASN1_ERR_WRONG_TYPE:
errstr = "Wrong type for that item";
break;
case ASN1_ERR_LENGTH_NOT_DEFINITE:
errstr = "Length was indefinite";
break;
case ASN1_ERR_LENGTH_MISMATCH:
errstr = "Length mismatch";
break;
case ASN1_ERR_WRONG_LENGTH_FOR_TYPE:
errstr = "Wrong length for that item's type";
break;
default:
g_snprintf(errstrbuf, sizeof errstrbuf, "Unknown error (%d)", err);
errstr = ep_strdup(errstrbuf);
break;
}
return errstr;
}
