static char *showtaglist(guint level)
{
static char tagtxt[BUFLM];
guint i;
int idx;
idx = 0;
#ifdef ALLTAGS
for(i=0; i<= level; i++) {
switch(taglist[i].cls) {
case BER_CLASS_UNI:
idx += g_snprintf(&tagtxt[idx], BUFLM - idx, "U");
break;
case BER_CLASS_APP:
idx += g_snprintf(&tagtxt[idx], BUFLM - idx, "A");
break;
case BER_CLASS_CON:
idx += g_snprintf(&tagtxt[idx], BUFLM - idx, "C");
break;
case BER_CLASS_PRI:
idx += g_snprintf(&tagtxt[idx], BUFLM - idx, "P");
break;
default:
idx += g_snprintf(&tagtxt[idx], BUFLM - idx, "x");
break;
}
idx += g_snprintf(&tagtxt[idx], BUFLM - idx, "%d.", taglist[i].tag);
}
#else
idx += g_snprintf(&tagtxt[idx], BUFLM - idx, "C");
for(i=0; i<= level; i++) {
if (taglist[i].cls == BER_CLASS_CON) {
idx += g_snprintf(&tagtxt[idx], BUFLM - idx, "%d.", taglist[i].tag);
}
}
#endif
idx--;
tagtxt[idx] = '\0';
return tagtxt;
}
static guint
get_context(guint level)
{
guint ctx = 0;
guint i;
for(i=0; i<=level; i++) {
if (taglist[i].cls == BER_CLASS_CON)
ctx = (ctx << 8) | taglist[i].tag;
}
return ctx;
}
static const char *showbits(guchar *val, guint count)
{
static char str[BUFLM];
guint i;
char *p = str;
if (count > 32)
return "*too many bits*";
if (val != 0) {
for(i=0; i<count; i++) {
if (i && ((i & 7) == 0)) *p++ = ' ';
*p++ = (val[i>>3] & (0x80 >> (i & 7))) ? '1' : '0';
}
}
*p = 0;
return str;
}
static const char *
showbitnames(guchar *val, guint count, PDUprops *props, guint offset)
{
static char str[BUFLL];
guint i;
int idx;
if (props->flags & OUT_FLAG_noname)
return empty;
if (count > 32)
return "*too many bits, no names...*";
idx = 0;
if (val != NULL) {
for(i=0; i<count; i++) {
if (val[i>>3] & (0x80 >> (i & 7))) {
idx += g_snprintf(&str[idx], BUFLL-idx, "%s,", getPDUenum(props, offset, 0, 0, i));
}
}
if (idx > 0)
--idx;
}
str[idx] = '\0';
return str;
}
static char *showoid(subid_t *oid, guint len)
{
static char str[BUFLM];
guint i;
int idx;
idx = 0;
if (oid != NULL) {
for(i=0; i<len; i++) {
if (i)
idx += g_snprintf(&str[idx], BUFLM - idx, ".");
idx += g_snprintf(&str[idx], BUFLM - idx, "%lu", (unsigned long)oid[i]);
}
}
str[idx] = '\0';
return str;
}
static char *
showoctets(guchar *octets, guint len, guint hexlen)
{
guint dohex = 0;
guint i;
char *str;
int idx;
const char *endstr = empty;
if (len == 0) {
str = (char *)g_malloc(1);
str[0] = 0;
} else {
for (i=0; i<len; i++) {
if (!isprint(octets[i]))
dohex++;
}
if (len > MAX_OTSLEN) {
len = MAX_OTSLEN;
endstr = "....";
}
if (dohex) {
str = (char *)g_malloc(len*2 + 5);
idx = 0;
for (i=0; i<len; i++) {
idx += g_snprintf(&str[idx], len*2 - idx, "%2.2X", octets[i]);
}
g_snprintf(&str[idx], len*2 + 5 - idx, "%s", endstr);
} else {
if (len <= hexlen) {
str = (char *)g_malloc(len*3+2);
idx = 0;
for (i=0; i<len; i++) {
idx += g_snprintf(&str[idx], len*3 - idx, "%2.2X", octets[i]);
}
g_snprintf(&str[idx], len*3+2 - idx, " %s", octets);
} else {
str = (char *)g_malloc(len+5);
g_snprintf(str, len*3+5, " %s%s", octets, endstr);
}
}
}
return str;
}
static int
g_strcmp(gconstpointer a, gconstpointer b)
{
if (a == 0) a = empty;
if (b == 0) b = empty;
return strcmp((const char *)a, (const char *)b);
}
static int
checklength(int len, int def, int cls, int tag, char *lenstr, int strmax)
{
int newlen = len;
if ( ! def) {
g_snprintf(lenstr, strmax, "indefinite");
return len;
}
if (len < 0)
newlen = 4;
if (cls != BER_CLASS_UNI) {
if (len > 131071)
newlen = 64;
} else {
switch (tag) {
case BER_UNI_TAG_EOC:
case BER_UNI_TAG_NULL:
newlen = 0;
break;
case BER_UNI_TAG_BOOLEAN:
newlen = 1;
break;
case BER_UNI_TAG_INTEGER:
case BER_UNI_TAG_ENUMERATED:
if (len > 8)
newlen = 4;
break;
case BER_UNI_TAG_BITSTRING:
if (len > 8)
newlen = 4;
break;
case BER_UNI_TAG_OCTETSTRING:
case BER_UNI_TAG_NumericString:
case BER_UNI_TAG_PrintableString:
case BER_UNI_TAG_TeletexString:
case BER_UNI_TAG_VideotexString:
case BER_UNI_TAG_IA5String:
case BER_UNI_TAG_GraphicString:
case BER_UNI_TAG_VisibleString:
case BER_UNI_TAG_GeneralString:
if (len > 65535)
newlen = 32;
break;
case BER_UNI_TAG_OID:
case BER_UNI_TAG_ObjectDescriptor:
case ASN1_EXT:
if (len > 64)
newlen = 16;
break;
case BER_UNI_TAG_REAL:
if (len >16)
newlen = 8;
break;
case BER_UNI_TAG_SEQUENCE:
case BER_UNI_TAG_SET:
if (len > 65535)
newlen = 64;
break;
case BER_UNI_TAG_UTCTime:
case BER_UNI_TAG_GeneralizedTime:
if (len > 32)
newlen = 15;
break;
default:
if (len > 131071)
newlen = 64;
break;
}
}
if (newlen != len) {
g_snprintf(lenstr, strmax, "%d(changed from %d)", newlen, len);
} else {
g_snprintf(lenstr, strmax, "%d", len);
}
return newlen;
}
static void
dissect_asn1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
ASN1_SCK asn1;
guint cls, con, tag, len, offset, reassembled;
gboolean def;
char lenstr[BUFLS];
char tagstr[BUFLS];
char headstr[BUFLL];
char offstr[BUFLS];
const char *name, *tname;
volatile guint boffset;
volatile int i = 0;
proto_tree * volatile ti = 0, * volatile ti2 = 0, *asn1_tree, *tree2;
proto_item *hidden_item;
PDUprops props;
static guint lastseq;
struct tcpinfo *info;
gint delta;
pcount++;
boffset = 0;
reassembled = 1;
if (pinfo->ipproto == IP_PROTO_TCP) {
info = (struct tcpinfo *)pinfo->private_data;
delta = info->seq - lastseq;
reassembled = info->is_reassembled;
lastseq = info->seq;
if (asn1_verbose)
g_message("dissect_asn1: tcp - seq=%u, delta=%d, reassembled=%d",
info->seq, delta, reassembled);
} else {
if (asn1_verbose)
g_message("dissect_asn1: udp");
}
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "ASN.1 %s", current_pduname);
col_clear(pinfo->cinfo, COL_INFO);
offstr[0] = 0;
if ((first_pdu_offset > 0) && !reassembled) {
boffset = first_pdu_offset;
g_snprintf(offstr, sizeof(offstr), " at %d", boffset);
}
asn1_open(&asn1, tvb, boffset);
asn1_header_decode(&asn1, &cls, &con, &tag, &def, &len);
asn1_close(&asn1, &offset);
PDUreset(pcount, 0);
getPDUprops(&props, boffset, cls, tag, con);
name = props.name;
tname = props.asn1typename;
len = checklength(len, def, cls, tag, lenstr, sizeof(lenstr));
if (asn1_debug) {
g_snprintf(tagstr, sizeof(tagstr), "%ctag%d", tag_class[cls], tag);
g_snprintf(headstr, sizeof(headstr), "first%s: (%s)%s %d %s, %s, %s, len=%s, off=%d, size=%d ",
offstr,
tname,
name,
pcount,
asn1_cls[cls],
asn1_con[con],
((cls == BER_CLASS_UNI) && (tag < 32)) ? asn1_tag[tag] : tagstr,
lenstr,
boffset,
tvb_length(tvb)
);
} else {
if (props.flags & OUT_FLAG_noname) {
g_snprintf(tagstr, sizeof(tagstr), "%ctag%d", tag_class[cls], tag);
name = ((cls == BER_CLASS_UNI) && (tag < 32)) ? asn1_tag[tag] : tagstr;
}
g_snprintf(headstr, sizeof(headstr), "first pdu%s: (%s)%s ", offstr, tname, name );
}
col_add_str(pinfo->cinfo, COL_INFO, headstr );
TRY {
ti = proto_tree_add_protocol_format(tree, proto_asn1, tvb, boffset,
def? (int) (offset - boffset + len) : -1,
"ASN.1 %s", current_pduname);
tree2 = proto_item_add_subtree(ti, ett_asn1);
switch (((PDUinfo *)PDUtree->data)->type) {
case TBL_BOOLEAN:
case TBL_INTEGER:
case TBL_BITSTRING:
case TBL_REAL:
case TBL_ENUMERATED:
hidden_item = proto_tree_add_item(tree2, ((PDUinfo *)PDUtree->data)->value_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_LITTLE_ENDIAN);
break;
case TBL_OCTETSTRING:
hidden_item = proto_tree_add_item(tree2, ((PDUinfo *)PDUtree->data)->value_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_ASCII|ENC_NA);
break;
default:
hidden_item = proto_tree_add_item(tree2, ((PDUinfo *)PDUtree->data)->value_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset = boffset;
while((i < MAXPDU) && (tvb_length_remaining(tvb, offset) > 0)) {
ti2 = 0;
boffset = offset;
asn1_open(&asn1, tvb, offset);
asn1_header_decode(&asn1, &cls, &con, &tag, &def, &len);
asn1_close(&asn1, &offset);
PDUreset(pcount, i+1);
getPDUprops(&props, boffset, cls, tag, con);
name = props.name;
tname = props.asn1typename;
if (!def)
len = tvb_length_remaining(tvb, offset);
len = checklength(len, def, cls, tag, lenstr, sizeof(lenstr));
if (asn1_debug) {
g_snprintf(tagstr, sizeof(tagstr), "%ctag%d", tag_class[cls], tag);
g_snprintf(headstr, sizeof(headstr), "%s, %s, %s, len=%s, off=%d, remaining=%d",
asn1_cls[cls],
asn1_con[con],
((cls == BER_CLASS_UNI) && (tag < 32)) ? asn1_tag[tag] : tagstr,
lenstr,
boffset,
tvb_length_remaining(tvb, offset) );
if (props.value_id == -1)
ti2 = proto_tree_add_text(tree2, tvb, boffset,
def? (int) (offset - boffset + len) : -1,
"%s: (%s)%s %d-%d %s", current_pduname,
tname, name, pcount, i+1, headstr);
else {
ti2 = proto_tree_add_none_format(tree2, props.value_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1,
"%s: (%s)%s %d-%d %s ~", current_pduname,
tname, name, pcount, i+1, headstr);
if (props.type_id != -1){
switch (proto_registrar_get_ftype(props.type_id)) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_BOOLEAN:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IPv4:
hidden_item = proto_tree_add_item(tree2, props.type_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_LITTLE_ENDIAN);
break;
case FT_STRING:
case FT_STRINGZ:
hidden_item = proto_tree_add_item(tree2, props.type_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_ASCII|ENC_NA);
break;
default:
hidden_item = proto_tree_add_item(tree2, props.type_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if (props.flags & OUT_FLAG_noname) {
g_snprintf(tagstr, sizeof(tagstr), "%ctag%d", tag_class[cls], tag);
name = ((cls == BER_CLASS_UNI) && (tag < 32)) ? asn1_tag[tag] : tagstr;
}
if (props.value_id == -1)
ti2 = proto_tree_add_text(tree2, tvb, boffset,
def? (int) (offset - boffset + len) : -1,
"%s: (%s)%s", current_pduname, tname, name);
else {
ti2 = proto_tree_add_none_format(tree2, props.value_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1,
"%s: (%s)%s ~", current_pduname, tname, name);
if (props.type_id != -1){
switch (proto_registrar_get_ftype(props.type_id)) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_BOOLEAN:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IPv4:
hidden_item = proto_tree_add_item(tree2, props.type_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_LITTLE_ENDIAN);
break;
case FT_STRING:
case FT_STRINGZ:
hidden_item = proto_tree_add_item(tree2, props.type_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_ASCII|ENC_NA);
break;
default:
hidden_item = proto_tree_add_item(tree2, props.type_id, tvb, boffset,
def? (int) (offset - boffset + len) : -1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
asn1_tree = proto_item_add_subtree(ti2, ett_pdu[i]);
#ifdef NEST
taglist[0].cls = cls;
taglist[0].tag = tag;
#endif
if (!def) len++;
offset = decode_asn1_sequence(tvb, offset, len, asn1_tree, 1);
proto_item_set_len(ti2, offset - boffset);
i++;
if (ti2 && PDUerrcount && asn1_debug)
proto_item_append_text(ti2," (%d error%s)", PDUerrcount, (PDUerrcount>1)?"s":empty);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "[%d msg%s]", i, (i>1)?"s":empty);
if (ti)
proto_item_append_text(ti, ", %d msg%s", i, (i>1)?"s":empty);
}
CATCH(ReportedBoundsError) {
col_append_fstr(pinfo->cinfo, COL_INFO, "[%d+1 msg%s]", i, (i>0)?"s":empty);
if (ti)
proto_item_append_text(ti, ", %d+1 msg%s", i, (i>1)?"s":empty);
if (ti2)
proto_item_append_text(ti2, " (incomplete)");
if (asn1_desegment) {
pinfo->desegment_offset = boffset;
pinfo->desegment_len = 1;
if (asn1_verbose)
g_message("ReportedBoundsError: offset=%d len=%d can_desegment=%d",
boffset, 1, pinfo->can_desegment);
} else {
RETHROW;
}
}
ENDTRY;
if (asn1_verbose)
g_message("dissect_asn1 finished: desegment_offset=%d desegment_len=%d can_desegment=%d",
pinfo->desegment_offset, pinfo->desegment_len, pinfo->can_desegment);
}
static guint
decode_asn1_sequence(tvbuff_t *tvb, guint offset, guint tlen, proto_tree *pt, int level)
{
ASN1_SCK asn1;
guint ret, cls, con, tag, len, boffset, soffset, eos;
gboolean def;
guint value;
const char *clsstr, *constr, *tagstr;
char tagbuf[BUFLM];
char lenbuf[BUFLM];
char nnbuf[BUFLS];
proto_tree *ti, *pt2;
proto_item *hidden_item;
guchar *octets, *bits, unused;
subid_t *oid;
static char textfmt_d[] = "off=%d: [%s %s %s] (%s)%s: %d%s";
static char textfmt_e[] = "off=%d: [%s %s %s] (%s)%s: %d:%s%s";
static char textfmt_s[] = "off=%d: [%s %s %s] (%s)%s: '%s'%s";
static char textfmt_b[] = "off=%d: [%s %s %s] (%s)%s: %s:%s%s";
static char textfmt_c[] = "off=%d: [%s %s %s] (%s)%s%s%s";
static char matchind[] = " ~";
const char *name, *ename, *tname;
char *oname;
PDUprops props;
ti = 0;
soffset = offset;
eos = offset + tlen;
while (offset < eos) {
boffset = offset;
asn1_open(&asn1, tvb, offset);
ret = asn1_header_decode(&asn1, &cls, &con, &tag, &def, &len);
asn1_close(&asn1, &offset);
if (ret != ASN1_ERR_NOERROR) {
proto_tree_add_text(pt, tvb, offset, 1, "ASN1 ERROR: %s", asn1_err_to_str(ret) );
break;
}
getPDUprops(&props, boffset, cls, tag, con);
name = props.name;
tname = props.asn1typename;
if (asn1_full)
name = &props.fullname[pabbrev_pdu_len];
if (asn1_debug) {
g_snprintf(fieldname, sizeof(fieldname), "%s[%s]", props.name, props.fullname);
name = fieldname;
}
clsstr = asn1_cls[cls];
constr = asn1_con[con];
if ((cls == BER_CLASS_UNI) && ( tag < 32 )) {
tagstr = asn1_tag[tag];
} else {
g_snprintf(tagbuf, sizeof(tagbuf), "%ctag%d", tag_class[cls], tag);
tagstr = tagbuf;
}
len = checklength(len, def, cls, tag, lenbuf, sizeof(lenbuf));
if (def) {
g_snprintf(nnbuf, sizeof(nnbuf), "NN%d", len);
} else {
g_snprintf(nnbuf, sizeof(nnbuf), "NN-");
len = tvb_length_remaining(tvb, offset) + 1;
}
if ( ( ! asn1_debug) && (props.flags & OUT_FLAG_noname) ) {
tname = tagstr;
name = nnbuf;
}
#ifdef NEST
taglist[level].cls = cls;
taglist[level].tag = tag;
#endif
oname = 0;
if (level >= MAX_NEST) {
cls = BER_CLASS_UNI;
tag = BER_UNI_TAG_GeneralString;
oname = (char *)g_malloc(strlen(name) + 32);
g_snprintf(oname, (gulong)(strlen(name) + 32), "%s ** nesting cut off **", name);
name = oname;
}
switch(cls) {
case BER_CLASS_UNI:
switch(tag) {
case BER_UNI_TAG_INTEGER:
asn1_int32_value_decode(&asn1, len, &value);
asn1_close(&asn1, &offset);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset, textfmt_d, boffset,
clsstr, constr, tagstr, tname, name, value,
empty);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb, boffset,
offset - boffset, value, textfmt_d, boffset,
clsstr, constr, tagstr, tname, name, value,
matchind);
if (props.type_id != -1) {
hidden_item = proto_tree_add_uint(pt, props.type_id, tvb,
boffset, offset - boffset, value);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
"(%s)%s: %d", tname, name, value);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb, boffset,
offset - boffset, value,
"(%s)%s: %d ~", tname, name, value);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id, tvb,
boffset, offset - boffset, value);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
break;
case BER_UNI_TAG_ENUMERATED:
asn1_int32_value_decode(&asn1, len, &value);
asn1_close(&asn1, &offset);
ename = getPDUenum(&props, boffset, cls, tag, value);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
textfmt_e, boffset, clsstr, constr, tagstr,
tname, name, value, ename, empty);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb, boffset,
offset - boffset, value,
textfmt_e, boffset, clsstr, constr, tagstr,
tname, name, value, ename, matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id, tvb,
boffset, offset - boffset, value);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
"(%s)%s: %d:%s", tname, name, value, ename);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb, boffset,
offset - boffset, value,
"(%s)%s: %d:%s ~", tname, name, value, ename);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id, tvb,
boffset, offset - boffset, value);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
break;
case BER_UNI_TAG_BOOLEAN:
asn1_bool_decode(&asn1, len, (gboolean *)&value);
asn1_close(&asn1, (gint *)&offset);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_BOOLEAN) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
textfmt_s, boffset, clsstr, constr, tagstr,
tname, name, value? "true" : "false", empty);
else {
proto_tree_add_boolean_format(pt, props.value_id, tvb, boffset,
offset - boffset, value != 0,
textfmt_s, boffset, clsstr, constr, tagstr,
tname, name, value? "true" : "false", matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_boolean(pt, props.type_id, tvb,
boffset, offset - boffset, value != 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_BOOLEAN) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
"(%s)%s: %s", tname, name,
value? "true" : "false");
else {
proto_tree_add_boolean_format(pt, props.value_id, tvb, boffset,
offset - boffset, value != 0,
"(%s)%s: %s ~", tname, name,
value? "true" : "false");
if (props.type_id != -1){
hidden_item = proto_tree_add_boolean(pt, props.type_id, tvb,
boffset, offset - boffset, value != 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
break;
case BER_UNI_TAG_OCTETSTRING:
case BER_UNI_TAG_NumericString:
case BER_UNI_TAG_PrintableString:
case BER_UNI_TAG_TeletexString:
case BER_UNI_TAG_IA5String:
case BER_UNI_TAG_GeneralString:
case BER_UNI_TAG_UTCTime:
case BER_UNI_TAG_GeneralizedTime:
asn1_string_value_decode(&asn1, len, &octets);
asn1_close(&asn1, (gint *)&offset);
ename = showoctets(octets, len, (tag == BER_UNI_TAG_OCTETSTRING) ? 4 : 0 );
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_STRINGZ) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
textfmt_s, boffset, clsstr, constr, tagstr,
tname, name, ename, empty);
else {
proto_tree_add_string_format(pt, props.value_id, tvb, boffset,
offset - boffset, octets,
textfmt_s, boffset, clsstr, constr, tagstr,
tname, name, ename, matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_string(pt, props.type_id, tvb,
boffset, offset - boffset, octets);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_STRINGZ) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
"(%s)%s: %s", tname, name, ename);
else {
proto_tree_add_string_format(pt, props.value_id, tvb, boffset,
offset - boffset, octets,
"(%s)%s: %s ~", tname, name, ename);
if (props.type_id != -1){
hidden_item = proto_tree_add_string(pt, props.type_id, tvb,
boffset, offset - boffset, octets);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
g_free(octets);
g_free( (gpointer) ename);
break;
case BER_UNI_TAG_BITSTRING:
asn1_bits_decode(&asn1, len, &bits, &con, &unused);
asn1_close(&asn1, &offset);
ename = showbitnames(bits, (con*8)-unused, &props, offset);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
textfmt_b, boffset, clsstr, constr, tagstr,
tname, name,
showbits(bits, (con*8)-unused), ename, empty);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb, boffset,
offset - boffset, *bits,
textfmt_b, boffset, clsstr, constr, tagstr,
tname, name,
showbits(bits, (con*8)-unused),ename, matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id, tvb,
boffset, offset - boffset, *bits);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
"(%s)%s: %s:%s", tname, name,
showbits(bits, (con*8)-unused), ename);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb, boffset,
offset - boffset, *bits,
"(%s)%s: %s:%s ~", tname, name,
showbits(bits, (con*8)-unused), ename);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id, tvb,
boffset, offset - boffset, *bits);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
g_free(bits);
break;
case BER_UNI_TAG_SET:
case BER_UNI_TAG_SEQUENCE:
if (asn1_debug) {
ename = empty;
if ( (props.flags & OUT_FLAG_dontshow) || asn1_full)
ename = ", noshow";
if ( (props.flags & OUT_FLAG_constructed))
ename = ", unexpected constructed";
if (props.value_id == -1)
ti = proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
textfmt_c, boffset, clsstr, constr, tagstr,
tname, name, ename, empty);
else {
switch (props.type) {
case TBL_BOOLEAN:
case TBL_INTEGER:
case TBL_BITSTRING:
case TBL_REAL:
case TBL_ENUMERATED:
ti = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_LITTLE_ENDIAN);
break;
case TBL_OCTETSTRING:
ti = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_ASCII|ENC_NA);
break;
default:
ti = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_NA);
break;
}
proto_item_set_text(ti, textfmt_c, boffset, clsstr, constr,
tagstr, tname, name, ename, matchind);
if (props.type_id != -1){
switch (proto_registrar_get_ftype(props.type_id)) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_BOOLEAN:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IPv4:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_LITTLE_ENDIAN);
break;
case FT_STRING:
case FT_STRINGZ:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_ASCII|ENC_NA);
break;
default:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if (props.value_id == -1) {
if ( (! asn1_full) && ((props.flags & OUT_FLAG_dontshow) == 0) )
ti = proto_tree_add_text(pt, tvb, boffset,
offset - boffset + len,
"(%s)%s", tname, name);
} else {
if ( (! asn1_full) && ((props.flags & OUT_FLAG_dontshow) == 0) )
ti = proto_tree_add_none_format(pt, props.value_id, tvb,
boffset, offset - boffset + len,
"(%s)%s ~", tname, name);
else {
switch (props.type) {
case TBL_BOOLEAN:
case TBL_INTEGER:
case TBL_BITSTRING:
case TBL_REAL:
case TBL_ENUMERATED:
ti = hidden_item = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_LITTLE_ENDIAN);
break;
case TBL_OCTETSTRING:
ti = hidden_item = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_ASCII|ENC_NA);
break;
default:
ti = hidden_item = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (props.type_id != -1){
switch (proto_registrar_get_ftype(props.type_id)) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_BOOLEAN:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IPv4:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_LITTLE_ENDIAN);
break;
case FT_STRING:
case FT_STRINGZ:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_ASCII|ENC_NA);
break;
default:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
if (len == 0) return offset;
if ( ( ! asn1_full) && (asn1_debug || ((props.flags & OUT_FLAG_dontshow) == 0)))
pt2 = proto_item_add_subtree(ti, ett_seq[level]);
else
pt2 = pt;
offset = decode_asn1_sequence(tvb, offset, len, pt2, level+1);
if ( ( ! asn1_full) && (asn1_debug || ((props.flags & OUT_FLAG_dontshow) == 0)))
proto_item_set_len(ti, offset - boffset);
break;
case BER_UNI_TAG_EOC:
if (asn1_debug) {
proto_tree_add_text(pt, tvb, boffset, offset - boffset, textfmt_d,
boffset, clsstr, constr, tagstr, tname, name,
offset - soffset, empty);
}
getPDUprops(&props, soffset, ASN1_EOI, 1, 0);
return offset;
case BER_UNI_TAG_OID:
asn1_oid_value_decode(&asn1, len, &oid, &con);
asn1_close(&asn1, (gint *)&offset);
ename = showoid(oid, con);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_BYTES) )
proto_tree_add_text(pt, tvb, boffset, offset - boffset, textfmt_s,
boffset, clsstr, constr, tagstr, tname, name,
ename, empty);
else {
proto_tree_add_bytes_format(pt, props.value_id, tvb, boffset,
offset - boffset, ename,
"(%s)%s: %s ~", tname, name, ename);
if (props.type_id != -1){
hidden_item = proto_tree_add_bytes(pt, props.type_id, tvb,
boffset, offset - boffset, ename);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_BYTES) )
proto_tree_add_text(pt, tvb, boffset,
offset - boffset,
"(%s)%s: %s", tname, name, ename);
else {
proto_tree_add_bytes_format(pt, props.value_id, tvb, boffset,
offset - boffset, ename,
"(%s)%s: %s ~", tname, name, ename);
if (props.type_id != -1){
hidden_item = proto_tree_add_bytes(pt, props.type_id, tvb,
boffset, offset - boffset, ename);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
g_free(oid);
break;
case BER_UNI_TAG_NULL:
if (asn1_debug) {
proto_tree_add_text(pt, tvb, boffset, offset - boffset + len, textfmt_s,
boffset, clsstr, constr, tagstr, tname, name,
"[NULL]", empty);
} else {
proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
"(%s)%s: [NULL]", tname, name);
}
offset += len;
break;
case BER_UNI_TAG_ObjectDescriptor:
case ASN1_EXT:
case BER_UNI_TAG_REAL:
case BER_UNI_TAG_VideotexString:
case BER_UNI_TAG_GraphicString:
case BER_UNI_TAG_VisibleString:
default:
if (asn1_debug) {
ti = proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
textfmt_s, boffset, clsstr, constr, tagstr,
tname, name, lenbuf, empty);
} else {
ti = proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
"(%s)%s: %s bytes", tname, name, lenbuf);
}
proto_item_append_text(ti, " *");
offset += len;
break;
};
break;
case BER_CLASS_CON:
case BER_CLASS_APP:
case BER_CLASS_PRI:
if (def && !con) {
if (props.value_id == -1)
goto dostring;
switch(props.type) {
case TBL_INTEGER:
if (len > 4)
goto dostring;
asn1_int32_value_decode(&asn1, len, (gint32 *)&value);
asn1_close(&asn1, &offset);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb,
boffset, offset - boffset,
textfmt_d, boffset, clsstr, constr,
tagstr, tname, name, value, empty);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb,
boffset, offset - boffset, value,
textfmt_d, boffset, clsstr, constr,
tagstr, tname, name, value, matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id,
tvb, boffset, offset - boffset, value);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb,
boffset, offset - boffset,
"(%s)%s: %d", tname, name, value);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb,
boffset, offset - boffset, value,
"(%s)%s: %d ~", tname, name, value);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id,
tvb, boffset, offset - boffset, value);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
break;
case TBL_ENUMERATED:
if (len > 4)
goto dostring;
asn1_int32_value_decode(&asn1, len, &value);
asn1_close(&asn1, &offset);
ename = getPDUenum(&props, boffset, cls, tag, value);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb,
boffset, offset - boffset,
textfmt_e, boffset, clsstr, constr,
tagstr, tname, name, value, ename, empty);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb,
boffset, offset - boffset, value,
textfmt_e, boffset, clsstr, constr,
tagstr, tname, name, value, ename, matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id,
tvb, boffset, offset - boffset, value);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb,
boffset, offset - boffset,
"(%s)%s: %d:%s", tname, name, value, ename);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb,
boffset, offset - boffset, value,
"(%s)%s: %d:%s ~", tname, name, value, ename);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id,
tvb, boffset, offset - boffset, value);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
break;
case TBL_BITSTRING:
if (len > (1+4))
goto dostring;
asn1_bits_decode(&asn1, len, &bits, &con, &unused);
asn1_close(&asn1, (gint *)&offset);
ename = showbitnames(bits, (con*8)-unused, &props, offset);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb,
boffset, offset - boffset,
textfmt_b, boffset, clsstr, constr,
tagstr, tname, name,
showbits(bits, (con*8)-unused), ename,
empty);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb,
boffset, offset - boffset, *bits,
textfmt_b, boffset, clsstr, constr,
tagstr, tname, name,
showbits(bits, (con*8)-unused), ename,
matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id,
tvb, boffset, offset - boffset, *bits);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_UINT32) )
proto_tree_add_text(pt, tvb, boffset, offset - boffset,
"(%s)%s: %s:%s", tname, name,
showbits(bits, (con*8)-unused), ename);
else {
proto_tree_add_uint_format(pt, props.value_id, tvb,
boffset, offset - boffset, *bits,
"(%s)%s: %s:%s ~", tname, name,
showbits(bits, (con*8)-unused), ename);
if (props.type_id != -1){
hidden_item = proto_tree_add_uint(pt, props.type_id,
tvb, boffset, offset - boffset, *bits);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
g_free(bits);
break;
case TBL_BOOLEAN:
if (len > 1)
goto dostring;
asn1_bool_decode(&asn1, len, (gboolean *)&value);
asn1_close(&asn1, (gint *)&offset);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_BOOLEAN) )
proto_tree_add_text(pt, tvb,
boffset, offset - boffset,
textfmt_s, boffset, clsstr, constr,
tagstr, tname, name,
value? "true" : "false", empty);
else {
proto_tree_add_boolean_format(pt, props.value_id, tvb,
boffset, offset - boffset, value != 0,
textfmt_s, boffset, clsstr, constr,
tagstr, tname, name,
value? "true" : "false", matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_boolean(pt, props.type_id,
tvb, boffset, offset - boffset, value != 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_BOOLEAN) )
proto_tree_add_text(pt, tvb,
boffset, offset - boffset,
"(%s)%s: %s", tname, name,
value? "true" : "false");
else {
proto_tree_add_boolean_format(pt, props.value_id, tvb,
boffset, offset - boffset, value != 0,
"(%s)%s: %s ~", tname, name,
value? "true" : "false");
if (props.type_id != -1){
hidden_item = proto_tree_add_boolean(pt, props.type_id,
tvb, boffset, offset - boffset, value != 0);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
break;
case TBL_NULL:
if (len > 0)
goto dostring;
if (asn1_debug) {
proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
textfmt_s, boffset, clsstr, constr,
tagstr, tname, name, "[NULL]", empty);
} else {
proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
"(%s)%s: [NULL]", tname, name);
}
offset += len;
break;
default:
dostring:
props.value_id = -1;
case TBL_OCTETSTRING:
asn1_string_value_decode(&asn1, len, &octets);
asn1_close(&asn1, (gint *)&offset);
ename = showoctets(octets, len, 2);
if (asn1_debug) {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_STRINGZ) )
proto_tree_add_text(pt, tvb,
boffset, offset - boffset,
textfmt_s, boffset, clsstr, constr,
tagstr, tname, name, ename, empty);
else {
proto_tree_add_string_format(pt, props.value_id, tvb,
boffset, offset - boffset, (gchar *)octets,
textfmt_s, boffset, clsstr, constr,
tagstr, tname, name, ename, matchind);
if (props.type_id != -1){
hidden_item = proto_tree_add_string(pt, props.type_id,
tvb, boffset, offset - boffset, (gchar *)octets);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
if ( (props.value_id == -1) ||
(tbl_types_wireshark[props.type] != FT_STRINGZ) )
proto_tree_add_text(pt, tvb, boffset, offset - boffset,
"(%s)%s: %s", tname, name, ename);
else {
proto_tree_add_string_format(pt, props.value_id, tvb,
boffset, offset - boffset, (gchar *)octets,
"(%s)%s: %s ~", tname, name, ename);
if (props.type_id != -1){
hidden_item = proto_tree_add_string(pt, props.type_id,
tvb, boffset, offset - boffset, (gchar *)octets);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
g_free(octets);
g_free( (gpointer) ename);
break;
}
} else {
if (asn1_debug) {
ename = empty;
if ( (props.flags & OUT_FLAG_dontshow) || asn1_full)
ename = ", noshow";
if ( (props.flags & OUT_FLAG_constructed))
ename = ", unexpected constructed";
if (props.value_id == -1)
ti = proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
textfmt_c, boffset, clsstr, constr,
tagstr, tname, name, ename, empty);
else {
switch (props.type) {
case TBL_BOOLEAN:
case TBL_INTEGER:
case TBL_BITSTRING:
case TBL_REAL:
case TBL_ENUMERATED:
ti = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_LITTLE_ENDIAN);
break;
case TBL_OCTETSTRING:
ti = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_ASCII|ENC_NA);
break;
default:
ti = proto_tree_add_item(pt, props.value_id, tvb,
boffset, 1, ENC_NA);
break;
}
if (ti) {
proto_item_set_text(ti, textfmt_c, boffset, clsstr, constr,
tagstr, tname, name, ename, matchind);
if (props.type_id != -1){
switch (proto_registrar_get_ftype(props.type_id)) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_BOOLEAN:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IPv4:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_LITTLE_ENDIAN);
break;
case FT_STRING:
case FT_STRINGZ:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_ASCII|ENC_NA);
break;
default:
hidden_item = proto_tree_add_item(pt, props.type_id, tvb,
boffset, 1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
} else {
ti = proto_tree_add_text(pt, tvb, boffset,
offset - boffset + len,
textfmt_c, boffset, clsstr, constr,
tagstr, tname, name, ename, empty);
}
}
} else {
if (props.value_id == -1) {
if ( ( ! asn1_full) && ((props.flags & OUT_FLAG_dontshow) == 0))
ti = proto_tree_add_text(pt, tvb, boffset,
offset - boffset + len, "(%s)%s", tname, name);
} else {
if ( ( ! asn1_full) && ((props.flags & OUT_FLAG_dontshow) == 0))
ti = proto_tree_add_none_format(pt, props.value_id, tvb,
boffset, 1,
"(%s)%s ~", tname, name);
else {
switch (props.type) {
case TBL_BOOLEAN:
case TBL_INTEGER:
case TBL_BITSTRING:
case TBL_REAL:
case TBL_ENUMERATED:
ti = proto_tree_add_item(pt, props.value_id,
tvb, boffset, 1, ENC_LITTLE_ENDIAN);
break;
case TBL_OCTETSTRING:
ti = proto_tree_add_item(pt, props.value_id,
tvb, boffset, 1, ENC_ASCII|ENC_NA);
break;
default:
ti = proto_tree_add_item(pt, props.value_id,
tvb, boffset, 1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(ti);
}
if (props.type_id != -1){
switch (proto_registrar_get_ftype(props.type_id)) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_BOOLEAN:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IPv4:
hidden_item = proto_tree_add_item(pt, props.type_id,
tvb, boffset, 1, ENC_LITTLE_ENDIAN);
break;
case FT_STRING:
case FT_STRINGZ:
hidden_item = proto_tree_add_item(pt, props.type_id,
tvb, boffset, 1, ENC_ASCII|ENC_NA);
break;
default:
hidden_item = proto_tree_add_item(pt, props.type_id,
tvb, boffset, 1, ENC_NA);
break;
}
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
}
if (len == 0) return offset;
if ( ( ! asn1_full) && (asn1_debug || ((props.flags & OUT_FLAG_dontshow) == 0)))
pt2 = proto_item_add_subtree(ti, ett_seq[level]);
else
pt2 = pt;
offset = decode_asn1_sequence(tvb, offset, len, pt2, level+1);
if ( ( ! asn1_full) && (asn1_debug || ((props.flags & OUT_FLAG_dontshow) == 0)))
proto_item_set_len(ti, offset - boffset);
}
break;
default:
if (asn1_debug) {
ti = proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
textfmt_s, boffset, clsstr, constr, tagstr,
tname, name, lenbuf, empty);
} else {
ti = proto_tree_add_text(pt, tvb, boffset, offset - boffset + len,
"(%s)%s: %s bytes %s data", tname, name,
lenbuf, clsstr);
}
proto_item_append_text(ti, " *");
offset += len;
break;
}
g_free(oname);
}
getPDUprops(&props, soffset, ASN1_EOI, 0, 0);
return offset;
}
static guint
parse_tt3(tvbuff_t *tvb, guint offset, guint size, guint level, GNode *ptr)
{
ASN1_SCK asn1;
guint eos, cls, con, tag, len, value;
gboolean def;
guchar *octets, *bits, unused;
subid_t *oid;
GNode *cur_node = 0;
eos = offset + size;
if (level > lev_limit)
return eos;
while(offset < eos) {
if (ptr)
cur_node = g_node_append_data(ptr, GUINT_TO_POINTER(offset));
asn1_open(&asn1, tvb, offset);
asn1_header_decode(&asn1, &cls, &con, &tag, &def, &len);
asn1_close(&asn1, (gint *)&offset);
icount++;
if (!def) {
len = tvb_length_remaining(tvb, offset);
}
switch(cls) {
case BER_CLASS_UNI:
switch(tag) {
case BER_UNI_TAG_INTEGER:
case BER_UNI_TAG_ENUMERATED:
asn1_int32_value_decode(&asn1, len, (gint32 *)&value);
asn1_close(&asn1, (gint *)&offset);
break;
case BER_UNI_TAG_BOOLEAN:
asn1_bool_decode(&asn1, len, (gboolean *)&value);
asn1_close(&asn1, &offset);
break;
case BER_UNI_TAG_OCTETSTRING:
case BER_UNI_TAG_NumericString:
case BER_UNI_TAG_PrintableString:
case BER_UNI_TAG_TeletexString:
case BER_UNI_TAG_IA5String:
case BER_UNI_TAG_GeneralString:
case BER_UNI_TAG_UTCTime:
case BER_UNI_TAG_GeneralizedTime:
asn1_string_value_decode(&asn1, len, &octets);
asn1_close(&asn1, &offset);
g_free(octets);
break;
case BER_UNI_TAG_BITSTRING:
asn1_bits_decode(&asn1, len, &bits, &con, &unused);
asn1_close(&asn1, &offset);
g_free(bits);
break;
case BER_UNI_TAG_SET:
case BER_UNI_TAG_SEQUENCE:
if (len == 0)
return offset;
offset = parse_tt3(tvb, offset, len, level+1, cur_node);
break;
case BER_UNI_TAG_EOC:
return offset;
case BER_UNI_TAG_OID:
asn1_oid_value_decode(&asn1, len, &oid, &con);
asn1_close(&asn1, &offset);
g_free(oid);
break;
case BER_UNI_TAG_NULL:
offset += len;
break;
case BER_UNI_TAG_ObjectDescriptor:
case ASN1_EXT:
case BER_UNI_TAG_REAL:
case BER_UNI_TAG_VideotexString:
case BER_UNI_TAG_GraphicString:
case BER_UNI_TAG_VisibleString:
default:
if (asn1_verbose) g_message("%d skip1 %d", offset, len);
offset += len;
break;
};
break;
case BER_CLASS_CON:
if (def && !con) {
asn1_string_value_decode(&asn1, len, &octets);
asn1_close(&asn1, &offset);
g_free(octets);
} else {
if (len == 0)
return offset;
offset = parse_tt3(tvb, offset, len, level+1, cur_node);
}
break;
default:
if (asn1_verbose) g_message("%d skip2 %d", offset, len);
offset += len;
break;
}
}
return offset;
}
static void
tt_build_tree(void)
{
if (asn1_nodes)
g_node_destroy(asn1_nodes);
asn1_nodes = g_node_new(0);
icount = 0;
parse_tt3(asn1_desc, 0, tvb_length(asn1_desc), 0, asn1_nodes);
}
static guint
get_asn1_int(guint want_tag, guint offset)
{
ASN1_SCK asn1;
guint ret, cls, con, tag, len;
gboolean def;
guint value;
asn1_open(&asn1, asn1_desc, offset);
ret = asn1_header_decode(&asn1, &cls, &con, &tag, &def, &len);
if (ret == ASN1_ERR_NOERROR) {
if (con == ASN1_PRI && tag == want_tag) {
if (def) {
asn1_uint32_value_decode(&asn1, len, &value);
return value;
} else
ret = ASN1_ERR_LENGTH_NOT_DEFINITE;
} else
ret = ASN1_ERR_WRONG_TYPE;
}
g_warning("ASN.1 int mismatch at offset %d, %s", offset, asn1_err_to_str(ret));
return 0;
}
static subid_t *
get_asn1_oid(guint want_tag, guint offset)
{
ASN1_SCK asn1;
guint ret, cls, con, tag, len;
gboolean def;
subid_t *oid;
asn1_open(&asn1, asn1_desc, offset);
ret = asn1_header_decode(&asn1, &cls, &con, &tag, &def, &len);
if (ret == ASN1_ERR_NOERROR) {
if ((con == ASN1_PRI) && (tag == want_tag)) {
if (def) {
asn1_oid_value_decode(&asn1, len, &oid, &con);
oid = (subid_t *)g_realloc(oid, con + sizeof(guint));
memmove(&oid[1], oid, con*sizeof(guint));
oid[0] = con;
return oid;
} else
ret = ASN1_ERR_LENGTH_NOT_DEFINITE;
} else
ret = ASN1_ERR_WRONG_TYPE;
}
g_warning("ASN.1 oid mismatch at offset %d, %s", offset, asn1_err_to_str(ret));
return 0;
}
static guchar *
get_asn1_string(guint want_tag, guint offset)
{
ASN1_SCK asn1;
guint ret, cls, con, tag, len;
gboolean def;
guchar *octets;
asn1_open(&asn1, asn1_desc, offset);
ret = asn1_header_decode(&asn1, &cls, &con, &tag, &def, &len);
if (ret == ASN1_ERR_NOERROR) {
if ((con == ASN1_PRI) && (tag == want_tag)) {
if (def) {
asn1_string_value_decode(&asn1, len, &octets);
octets = (guchar *)g_realloc(octets, len+1);
octets[len] = 0;
return octets;
} else
ret = ASN1_ERR_LENGTH_NOT_DEFINITE;
} else
ret = ASN1_ERR_WRONG_TYPE;
}
g_warning("ASN.1 string mismatch at offset %d, %s", offset, asn1_err_to_str(ret));
return 0;
}
static guint
get_asn1_uint(guint offset)
{
ASN1_SCK asn1;
guint ret, len, value;
asn1_open(&asn1, asn1_desc, offset);
ret = asn1_uint32_decode(&asn1, &value, &len);
if (ret != ASN1_ERR_NOERROR) {
g_warning("ASN.1 uint mismatch at offset %d, %s", offset, asn1_err_to_str(ret));
value = 0;
}
return value;
}
static gboolean
check_tag(guint want_tag, guint offset)
{
ASN1_SCK asn1;
guint ret, cls, con, tag, len;
gboolean def;
asn1_open(&asn1, asn1_desc, offset);
ret = asn1_header_decode(&asn1, &cls, &con, &tag, &def, &len);
if (ret == ASN1_ERR_NOERROR) {
ret = (tag == want_tag) ? TRUE : FALSE;
return ret;
}
g_warning("ASN.1 check_tag at offset %d, %s", offset, asn1_err_to_str(ret));
return FALSE;
}
static void
define_constraint(GNode *p, GNode *q)
{
TBLRange *range = (TBLRange *)g_malloc(sizeof(TBLRange));
g_node_append_data(q, range);
range->type = TBLTYPE_Range;
p = g_node_first_child(p);
if (!p) {
return;
}
range->from = get_asn1_int(0, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) {
return;
}
range->to = get_asn1_int(1, GPOINTER_TO_UINT(p->data));
}
static void
define_namednumber(GNode *p, GNode *q)
{
TBLNamedNumber *num = (TBLNamedNumber *)g_malloc(sizeof(TBLNamedNumber));
g_node_append_data(q, num);
num->type = TBLTYPE_NamedNumber;
p = g_node_first_child(p);
if (!p) {
return;
}
num->name = get_asn1_string(0, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) {
return;
}
num->value = get_asn1_int(1, GPOINTER_TO_UINT(p->data));
}
static void
define_typeref(GNode *p, GNode *q)
{
TBLTypeRef *ref = (TBLTypeRef *)g_malloc(sizeof(TBLTypeRef));
g_node_append_data(q, ref);
ref->type = TBLTYPE_TypeRef;
p = g_node_first_child(p);
if (!p) {
return;
}
ref->typeDefId = get_asn1_uint(GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) {
return;
}
ref->implicit = get_asn1_int(BER_UNI_TAG_BOOLEAN, GPOINTER_TO_UINT(p->data));
}
static void
define_tag(GNode *p, GNode *q)
{
TBLTag *type = (TBLTag *)g_malloc(sizeof(TBLTag));
g_node_append_data(q, type);
type->type = TBLTYPE_Tag;
p = g_node_first_child(p);
if (!p) {
return;
}
type->tclass = get_asn1_int(BER_UNI_TAG_ENUMERATED, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) {
return;
}
type->code = get_asn1_int(BER_UNI_TAG_INTEGER, GPOINTER_TO_UINT(p->data));
}
static void
define_type(GNode *p, GNode *q)
{
GNode *r;
TBLType *type = (TBLType *)g_malloc(sizeof(TBLType));
GNode *t = g_node_append_data(q, type);
type->type = TBLTYPE_Type;
type->typeId = get_asn1_int(0, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
type->optional = get_asn1_int(1, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (check_tag(2, GPOINTER_TO_UINT(p->data))) {
r = g_node_first_child(p);
while (r) {
define_tag(r, t);
r = g_node_next_sibling(r);
}
p = g_node_next_sibling(p);
}
if (!check_tag(3, GPOINTER_TO_UINT(p->data))) {
g_warning("expect tag 3, ERROR");
}
r = g_node_first_child(p);
type->content = TBLTYPETYPE_None;
if (check_tag(0, GPOINTER_TO_UINT(r->data))) type->content = TBLTYPETYPE_Primitive;
if (check_tag(1, GPOINTER_TO_UINT(r->data))) type->content = TBLTYPETYPE_Elements;
if (check_tag(2, GPOINTER_TO_UINT(r->data))) type->content = TBLTYPETYPE_TypeRef;
switch(type->content) {
case TBLTYPETYPE_Primitive:
break;
case TBLTYPETYPE_Elements:
r = g_node_first_child(r);
while (r) {
define_type(g_node_first_child(r), t);
r = g_node_next_sibling(r);
}
break;
case TBLTYPETYPE_TypeRef:
define_typeref(r, t);
break;
case TBLTYPETYPE_None:
g_warning("expected a contents choice, error");
break;
}
p = g_node_next_sibling(p);
type->fieldName = 0;
type->anonymous = FALSE;
if (p && check_tag(4, GPOINTER_TO_UINT(p->data))) {
type->fieldName = get_asn1_string(4, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
} else {
type->anonymous = TRUE;
}
type->constraint = FALSE;
if (p && check_tag(5, GPOINTER_TO_UINT(p->data))) {
type->constraint = TRUE;
define_constraint(p, t);
p = g_node_next_sibling(p);
}
if (p && check_tag(6, GPOINTER_TO_UINT(p->data))) {
r = g_node_first_child(p);
while(r) {
define_namednumber(r, t);
r = g_node_next_sibling(r);
}
}
}
static void
define_typedef(GNode *p, GNode *q)
{
TBLTypeDef *type_def = (TBLTypeDef *)g_malloc(sizeof(TBLTypeDef));
GNode *t = g_node_append_data(q, type_def);
type_def->type = TBLTYPE_TypeDef;
p = g_node_first_child(p);
if (!p) {
return;
}
type_def->typeDefId = get_asn1_uint(GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) {
return;
}
type_def->typeName = get_asn1_string(BER_UNI_TAG_PrintableString, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) {
return;
}
define_type(g_node_first_child(p), t);
p = g_node_next_sibling(p);
type_def->isPdu = (p != 0);
}
static void
define_module(GNode *p, GNode *q)
{
TBLModule *module = (TBLModule *)g_malloc(sizeof(TBLModule));
GNode *m = g_node_append_data(q, module);
module->type = TBLTYPE_Module;
p = g_node_first_child(p);
if (!p) {
return;
}
module->name = get_asn1_string(0, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
module->id = 0;
if (check_tag(1, GPOINTER_TO_UINT(p->data))) {
module->id = get_asn1_oid(1, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
}
module->isUseful = get_asn1_int(2, GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
p = g_node_first_child(p);
while (p) {
define_typedef(p, m);
p = g_node_next_sibling(p);
}
}
static gboolean
is_typedef(GNode *node, gpointer data)
{
TBLTypeDef *d = (TBLTypeDef *)node->data;
SearchDef *s = (SearchDef *)data;
if (d == 0) return FALSE;
if (d->type != TBLTYPE_TypeDef) return FALSE;
if (strcmp(s->key, d->typeName) == 0) {
s->here = node;
return TRUE;
}
return FALSE;
}
static gboolean
is_named(GNode *node, gpointer data)
{
TBLNamedNumber *num = (TBLNamedNumber *)node->data;
NameDefs *n = (NameDefs *)data;
guint oldmax;
if (num == 0) return FALSE;
if (num->type != TBLTYPE_NamedNumber) return FALSE;
if (num->value >= n->max) {
oldmax = n->max;
n->max = num->value + ALLOC_INCR;
n->info = (TypeRef *)g_realloc(n->info, n->max * sizeof(TypeRef));
memset(&n->info[oldmax], 0, (n->max - oldmax) * sizeof(TypeRef));
}
if (num->value > n->used)
n->used = num->value;
n->info[num->value].name = num->name;
return FALSE;
}
static gboolean
index_typedef(GNode *node, gpointer data)
{
TBLTypeDef *d = (TBLTypeDef *)node->data;
NameDefs *n = (NameDefs *)data;
TypeRef *t;
TBLTag *tag;
guint oldmax;
if (d == 0) return FALSE;
if (d->type != TBLTYPE_TypeDef) return FALSE;
if (d->typeDefId >= n->max) {
oldmax = n->max;
n->max = d->typeDefId + ALLOC_INCR;
n->info = (TypeRef *)g_realloc(n->info, n->max * sizeof(TypeRef));
memset(&n->info[oldmax], 0, (n->max - oldmax) * sizeof(TypeRef));
}
if (d->typeDefId > n->used)
n->used = d->typeDefId;
t = &(n->info[d->typeDefId]);
t->name = d->typeName;
t->type = node;
t->refs = g_ptr_array_new();
node = g_node_first_child(node);
tag = (TBLTag *)node->data;
if ((tag->type == TBLTYPE_Type) && (((TBLType *)(void *)tag)->typeId == TBL_CHOICE)) {
t->defclass = 3;
t->deftag= 9999;
} else {
node = g_node_first_child(node);
tag = (TBLTag *)node->data;
switch(tag->type) {
case TBLTYPE_Tag:
t->defclass = tag->tclass;
t->deftag = tag->code;
break;
case TBLTYPE_TypeRef:
t->defclass = CLASSREF;
t->deftag = ((TBLTypeRef *)tag)->typeDefId;
break;
default:
g_warning("***** index_typedef: expecting a tag or typeref, found %s *****",
data_types[tag->type]);
t->defclass = 3;
t->deftag= 9998;
break;
}
}
return FALSE;
}
static gboolean
free_node_data(GNode *node, gpointer data _U_)
{
g_free(node->data);
return FALSE;
}
static void
get_values(void)
{
GNode *p;
SearchDef sd;
NameDefs nd;
guint i;
char X;
const char *t, *s, *E;
static char missing[] = " **missing** ";
if (asn1_verbose) g_message("interpreting tree");
typeDef_names = 0;
if (data_nodes) {
g_node_traverse(data_nodes, G_POST_ORDER, G_TRAVERSE_ALL, -1,
free_node_data, NULL);
g_node_destroy(data_nodes);
}
data_nodes = g_node_new(0);
p = g_node_first_child(asn1_nodes);
p = g_node_first_child(p);
if (!p) return;
TT.totalNumModules = get_asn1_uint(GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) return;
TT.totalNumTypeDefs = get_asn1_uint(GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) return;
TT.totalNumTypes = get_asn1_uint(GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) return;
TT.totalNumTags = get_asn1_uint(GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) return;
TT.totalNumStrings = get_asn1_uint(GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
if (!p) return;
TT.totalLenStrings = get_asn1_uint(GPOINTER_TO_UINT(p->data));
p = g_node_next_sibling(p);
p = g_node_first_child(p);
while (p) {
define_module(p, data_nodes);
p = g_node_next_sibling(p);
}
if (!tbl_types_verified) {
sd.key = "TBLTypeId";
sd.here = 0;
g_node_traverse(data_nodes, G_PRE_ORDER, G_TRAVERSE_ALL, -1, is_typedef, (gpointer)&sd);
if (asn1_verbose) g_message("%s %sfound, %p", sd.key, sd.here?empty:"not ", (void *)sd.here);
if (sd.here) {
nd.max = 8;
nd.used = 0;
nd.info = (TypeRef *)g_malloc0(nd.max * sizeof(TypeRef));
g_node_traverse(sd.here, G_PRE_ORDER, G_TRAVERSE_ALL, -1, is_named,
(gpointer)&nd);
if (asn1_verbose) g_message("tbltypenames: max=%d, info=%p", nd.max, (void *)nd.info);
E = empty;
for (i=0; i<=nd.used; i++) {
X = 'X';
t = TBLTYPE(i);
s = nd.info[i].name;
if (s == 0) s = missing;
if (g_strcmp(t, s) == 0) {
X = ' ';
t = empty;
} else {
E = ", X with errors X";
}
if (asn1_verbose) g_message(" %c %2d %s %s", X, i, s, t);
}
if (asn1_verbose) g_message("OK, TBLTypeId's index verified%s", E);
}
tbl_types_verified = TRUE;
}
nd.max = 8;
nd.used = 0;
nd.info = (TypeRef *)g_malloc0(nd.max * sizeof(TypeRef));
g_node_traverse(data_nodes, G_PRE_ORDER, G_TRAVERSE_ALL, -1, index_typedef, (gpointer)&nd);
if (asn1_verbose) g_message("tbltypedefs: max=%d, info=%p", nd.max, (void *)nd.info);
for (i=0; i<=nd.used; i++) {
TypeRef *ref = &(nd.info[i]);
t = ref->name;
if (t == 0) {
t = ref->name = missing;
if (asn1_verbose) g_message(" %3d %s", i, t);
} else {
if (asn1_verbose) g_message(" %3d %s, %c%d", i, t,
tag_class[ref->defclass], ref->deftag);
}
if (ref->pdu) {
if (asn1_verbose) g_message("* %3d %s pdu=%p", i, t, (void *)ref->pdu);
}
}
typeDef_names = nd.info;
numTypedefs = i;
if (asn1_verbose) g_message("OK, %d TBLTypeDef's index set up", numTypedefs);
}
static void
showGNode(GNode *p, int n)
{
const char *fn, *s = empty;
if (p == 0) return;
n *=2;
if (p->data) {
switch (((TBLTag *)p->data)->type) {
case TBLTYPE_Module: {
TBLModule *m = (TBLModule *)p->data;
if (asn1_verbose)
g_message("%*smodule %s%s", n, empty, m->name,
m->isUseful ? ", useful" : empty);
};
break;
case TBLTYPE_TypeDef: {
TBLTypeDef *t = (TBLTypeDef *)p->data;
if (asn1_verbose)
g_message("%*stypedef %d %s%s", n, empty, t->typeDefId, t->typeName,
t->isPdu ? ", isPDU" : empty);
};
break;
case TBLTYPE_Type: {
TBLType *t = (TBLType *)p->data;
if (t->fieldName)
s = t->fieldName;
fn = TBLTYPE(t->typeId);
if (asn1_verbose) g_message("%*stype %d[%s]%s [%s]", n, empty, t->typeId, fn,
t->optional ? " opt" : empty, s );
};
break;
case TBLTYPE_Tag: {
TBLTag *t = (TBLTag *)p->data;
if ((t->tclass == BER_CLASS_UNI) && (t->code < 32))
s = asn1_tag[t->code];
if (asn1_verbose) g_message("%*stag %c%d[%s]", n, empty,
tag_class[t->tclass], t->code, s);
};
break;
case TBLTYPE_NamedNumber: {
TBLNamedNumber *nn = (TBLNamedNumber *)p->data;
if (asn1_verbose) g_message("%*snamednumber %2d %s", n, empty,
nn->value, nn->name);
};
break;
case TBLTYPE_Range: {
TBLRange *r = (TBLRange *)p->data;
if (asn1_verbose) g_message("%*srange %d .. %d", n, empty,
r->from, r->to );
};
break;
case TBLTYPE_TypeRef: {
TBLTypeRef *r = (TBLTypeRef *)p->data;
if (typeDef_names)
s = typeDef_names[r->typeDefId].name;
if (asn1_verbose) g_message("%*styperef %d[%s]%s", n, empty,
r->typeDefId, s, r->implicit ? ", implicit" : empty );
};
break;
default: {
TBLTag *x = (TBLTag *)p->data;
if (asn1_verbose) g_message("%*s--default-- type=%d", n, empty, x->type);
};
break;
}
} else {
if (asn1_verbose)
g_message("%*snode=%p, data=%p, next=%p, prev=%p, parent=%p, child=%p",
n, empty, (void *)p, (void *)p->data, (void *)p->next, (void *)p->prev, (void *)p->parent, (void *)p->children);
}
}
static void
showGNodes(GNode *p, int n)
{
if (p == 0) return;
showGNode(p, n);
showGNodes(p->children, n+1);
showGNodes(p->next, n);
}
static void
debug_dump_TT(void)
{
if (asn1_verbose)
g_message("modules=%d, defs=%d, types=%d, tags=%d, strings=%d, lenstrings=%d",
TT.totalNumModules,
TT.totalNumTypeDefs,
TT.totalNumTypes,
TT.totalNumTags,
TT.totalNumStrings,
TT.totalLenStrings);
}
static void
my_log_handler(const gchar *log_domain, GLogLevelFlags log_level,
const gchar *message, gpointer user_data)
{
static FILE* logf = 0;
static char eol[] = "\r\n";
(void) log_domain; (void) log_level; (void) user_data;
if (logf == NULL && asn1_logfile) {
logf = ws_fopen(asn1_logfile, "w");
}
if (logf) {
fputs(message, logf);
fputs(eol, logf);
fflush(logf);
}
}
static void
read_asn1_type_table(const char *filename)
{
FILE *f;
int ret;
guint size = 0;
guchar *data;
struct stat file_stat;
static guint mylogh = 0;
if ((filename == 0) || (strlen(filename) == 0))
return;
f = ws_fopen(filename, "rb");
if (f == 0) {
#ifdef _WIN32
if (strcmp(filename, bad_separator_old_default_asn1_filename) != 0)
#endif
if ((strcmp(filename, old_default_asn1_filename) != 0) || errno != ENOENT)
report_open_failure(filename, errno, FALSE);
return;
}
ret = fstat(fileno(f), &file_stat);
if (ret!=-1)
size = (int)file_stat.st_size;
if (size == 0) {
if (asn1_verbose) g_message("file %s is empty or size is unknown, ignored", filename);
fclose(f);
return;
}
if (asn1_verbose) g_message("reading %d bytes from %s", size, filename);
data = (guchar *)g_malloc(size);
if (fread(data, size, 1, f) < 1) {
g_warning("error reading %s, %s", filename, g_strerror(errno));
}
fclose(f);
if (asn1_verbose) {
g_message("logging to file %s", asn1_logfile);
if (mylogh == 0) {
mylogh = g_log_set_handler (NULL, (GLogLevelFlags)(G_LOG_LEVEL_MASK | G_LOG_FLAG_FATAL
| G_LOG_FLAG_RECURSION), my_log_handler, NULL);
}
}
asn1_desc = tvb_new_real_data(data, size, size);
tt_build_tree();
if (asn1_verbose) g_message("read %d items from %s", icount, filename);
#if 0
list_modules();
#endif
get_values();
g_node_destroy(asn1_nodes);
asn1_nodes = NULL;
tvb_free(asn1_desc);
asn1_desc = NULL;
g_free(data);
data = NULL;
showGNodes(data_nodes, 0);
debug_dump_TT();
}
static void
save_reference(PDUinfo *p)
{
gint i = p->mytype;
if (i == -1)
i = p->basetype;
g_ptr_array_add(typeDef_names[i].refs, (gpointer)p);
}
static void
tbl_typeref(gint n, GNode *pdu, GNode *tree, guint fullindex)
{
GNode *q;
PDUinfo *p = (PDUinfo *)pdu->data, *p1;
guint nvals;
value_string *v;
char ss[128];
int i;
if (n > 40) {
g_warning("****tbl_typeref: n>40, return [recursion too deep] ****************");
return;
}
CHECKTYPE(tree, TBLTYPE_TypeDef);
if (asn1_verbose) g_message("%*s+tbl_typeref %s [%s, tag %c%d]", n*2, empty,
p->name, TBLTYPE(p->type), tag_class[p->tclass], p->tag);
p->typenum = ((TBLTypeDef *)tree->data)->typeDefId;
p->flags |= PDU_TYPEDEF;
tree = g_node_first_child(tree);
CHECKTYPE(tree, TBLTYPE_Type);
p->type = ((TBLType *)tree->data)->typeId;
q = g_node_first_child(tree);
if (((TBLTag *)q->data)->type == TBLTYPE_Tag) {
if ((p->flags & PDU_IMPLICIT) == 0) {
guint xcls, xtag;
xcls = p->tclass;
xtag = p->tag;
if ( ((xcls|xtag) == 0) || (xcls == CLASSREF) ||
(((TBLTag *)q->data)->tclass != BER_CLASS_UNI) ) {
p->tclass = ((TBLTag *)q->data)->tclass;
p->tag = ((TBLTag *)q->data)->code;
if (asn1_verbose)
g_message("%*s*change typeref tag from %c%d to %c%d",
n*2, empty,
tag_class[xcls],
xtag,
tag_class[p->tclass],
p->tag);
} else {
if (asn1_verbose)
g_message("%*sNOT changing tag from %c%d to %c%d",
n*2, empty,
tag_class[xcls],
xtag,
tag_class[((TBLTag *)q->data)->tclass],
((TBLTag *)q->data)->code);
}
}
} else {
ss[0] = 0;
if (p->tclass==CLASSREF)
g_snprintf(ss, 128, ", CLASSREF %d", p->tag);
if (asn1_verbose) g_message("%*sno typeref tag%s", n*2, empty, ss);
if (p->tclass==CLASSREF) {
TypeRef *tr;
i = p->basetype;
if (i == -1)
i = p->tag;
tr = &typeDef_names[i];
if (asn1_verbose)
g_message("%*s*refer2 to type#%d %s, %p", n*2, empty,
p->tag, tr->name, (void *)tr->pdu);
tbl_typeref(n+1, pdu, tr->type, fullindex);
return;
}
}
if (asn1_verbose)
g_message("%*sinclude typedef %d %s %s [%p:%s, tag %c%d]", n*2, empty, p->typenum,
p->name, p->asn1typename, (void *)p, TBLTYPE(p->type), tag_class[p->tclass], p->tag);
switch(p->type) {
case TBL_BITSTRING:
case TBL_ENUMERATED:
if (asn1_verbose) g_message("%*s*collection T %s", n*2, empty, p->name);
p->value_hf.hfinfo.type = tbl_types_wireshark[p->type];
p->value_hf.hfinfo.display = tbl_display_wireshark[p->type];
proto_register_field_array(proto_asn1, &(p->value_hf) , 1);
save_reference(p);
if (asn1_verbose)
g_message("regtype1: %3d %3d [%3d] F%2.2x (%s)%s %s %s -> id=%d",
p->mytype, p->typenum, p->basetype, p->flags, p->asn1typename,
p->name, p->fullname,
tbl_types_wireshark_txt[p->type], p->value_id);
p1 = p;
nvals = 0;
while((q = g_node_next_sibling(q))) {
CHECKTYPE(q, TBLTYPE_NamedNumber);
p = (PDUinfo *)g_malloc0(sizeof(PDUinfo));
nvals++;
p->type = TBL_ENUMERATED;
p->name = (((TBLNamedNumber *)q->data)->name);
p->tag = (((TBLNamedNumber *)q->data)->value);
p->flags = PDU_NAMEDNUM;
if (asn1_verbose) g_message("%*s %3d %s", n*2, empty, p->tag, p->name);
g_node_append_data(pdu, p);
}
p1->value_hf.hfinfo.strings = v = (value_string *)g_malloc0((nvals+1) * sizeof(value_string));
q = g_node_first_child(pdu);
nvals = 0;
while(q) {
p = (PDUinfo *)q->data;
v[nvals].value = p->tag;
v[nvals].strptr = p->name;
nvals++;
q = g_node_next_sibling(q);
}
break;
case TBL_CHOICE:
if (p->value_id == -1) {
p->value_hf.hfinfo.type = tbl_types_wireshark[p->type];
p->value_hf.hfinfo.display = tbl_display_wireshark[p->type];
proto_register_field_array(proto_asn1, &(p->value_hf) , 1);
save_reference(p);
if (asn1_verbose)
g_message("regtype2: %3d %3d [%3d] F%2.2x (%s)%s %s %s -> id=%d",
p->mytype, p->typenum, p->basetype, p->flags, p->asn1typename,
p->name, p->fullname,
tbl_types_wireshark_txt[p->type], p->value_id);
}
tbl_type(n, pdu, q, fullindex);
break;
default:
if (p->value_id == -1) {
p->value_hf.hfinfo.type = tbl_types_wireshark[p->type];
p->value_hf.hfinfo.display = tbl_display_wireshark[p->type];
proto_register_field_array(proto_asn1, &(p->value_hf) , 1);
save_reference(p);
if (asn1_verbose)
g_message("regtype3: %3d %3d [%3d] F%2.2x (%s)%s %s %s -> id=%d",
p->mytype, p->typenum, p->basetype, p->flags, p->asn1typename,
p->name, p->fullname,
tbl_types_wireshark_txt[p->type], p->value_id);
}
tbl_type(n, pdu, g_node_next_sibling(q), fullindex);
}
}
static void
tbl_type(gint n, GNode *pdu, GNode *list, guint fullindex)
{
GNode *q, *pdu1;
PDUinfo *p, *p1;
guint ni;
guint nvals;
value_string *v;
if (n > 40) {
g_warning("****tbl_type: n>40, return [recursion too deep] ****************");
return;
}
ni = fullindex;
pdu1 = pdu;
while (list) {
if (asn1_verbose)
g_message("%*s+handle a %s, list=%p", n*2, empty,
data_types[((TBLTag *)list->data)->type], (void *)list);
if (((TBLTag *)list->data)->type == TBLTYPE_Range) {
list = g_node_next_sibling(list);
if (asn1_verbose) g_message("%*s*skip range", n*2, empty);
if (list == 0)
break;
}
if (((TBLTag *)list->data)->type == TBLTYPE_Type) {
CHECKTYPE(list, TBLTYPE_Type);
p = (PDUinfo *)g_malloc0(sizeof(PDUinfo));
pdu = g_node_append_data(pdu1, p);
p->type = ((TBLType *)list->data)->typeId;
p->asn1typename = tbl_types_asn1[p->type];
p->typenum = -1;
p->mytype = -1;
p->basetype = ((PDUinfo *)pdu1->data)->typenum;
p->flags = PDUinfo_initflags;
p->flags |= (((TBLType *)list->data)->anonymous ? PDU_ANONYMOUS : 0);
p->flags |= (((TBLType *)list->data)->optional ? PDU_OPTIONAL : 0);
if (((TBLType *)list->data)->fieldName == 0) {
((TBLType *)list->data)->fieldName =
g_strdup_printf("anon%d", anonCount++);
}
p->name = ((TBLType *)list->data)->fieldName;
ni = fullindex;
ni += g_snprintf(&fieldname[ni], sizeof(fieldname) - ni, ".%s", p->name);
p->fullname = g_strdup(fieldname);
p->value_id = -1;
p->type_id = -1;
p->value_hf.p_id = &(p->value_id);
p->value_hf.hfinfo.name = p->fullname;
p->value_hf.hfinfo.abbrev = p->fullname;
p->value_hf.hfinfo.type = tbl_types_wireshark[p->type];
p->value_hf.hfinfo.display = tbl_display_wireshark[p->type];
p->value_hf.hfinfo.blurb = p->fullname;
if (p->type < TBL__SIMPLE) {
proto_register_field_array(proto_asn1, &(p->value_hf) , 1);
save_reference(p);
if (asn1_verbose)
g_message("register: %3d %3d [%3d] F%2.2x (%s)%s %s %s -> id=%d",
p->mytype, p->typenum, p->basetype, p->flags,
p->asn1typename, p->name, p->fullname,
tbl_types_wireshark_txt[p->type], p->value_id);
}
q = g_node_first_child(list);
} else {
p = (PDUinfo *)pdu->data;
q = list;
}
if (asn1_verbose) g_message("%*s*switch %s %s", n*2, empty, p->name, TBLTYPE(p->type));
switch (p->type) {
case TBL_BOOLEAN:
case TBL_INTEGER:
case TBL_OCTETSTRING:
case TBL_NULL:
case TBL_OID:
case TBL_REAL:
CHECKTYPE(q, TBLTYPE_Tag);
p->tclass = ((TBLTag *)q->data)->tclass;
p->tag = ((TBLTag *)q->data)->code;
break;
case TBL_BITSTRING:
case TBL_ENUMERATED:
CHECKTYPE(q, TBLTYPE_Tag);
p->tclass = ((TBLTag *)q->data)->tclass;
p->tag = ((TBLTag *)q->data)->code;
if (asn1_verbose) g_message("%*s*collection %s", n*2, empty, p->name);
nvals = 0;
p1 = p;
while((q = g_node_next_sibling(q))) {
CHECKTYPE(q, TBLTYPE_NamedNumber);
p = (PDUinfo *)g_malloc0(sizeof(PDUinfo));
nvals++;
p->type = TBL_ENUMERATED;
p->name = (gchar *)(((TBLNamedNumber *)q->data)->name);
p->tag = (((TBLNamedNumber *)q->data)->value);
p->flags = PDU_NAMEDNUM;
if (asn1_verbose) g_message("%*s %3d %s", n*2, empty, p->tag, p->name);
g_node_append_data(pdu, p);
}
p1->value_hf.hfinfo.strings = v = (value_string *)g_malloc0((nvals+1) * sizeof(value_string));
q = g_node_first_child(pdu);
nvals = 0;
while(q) {
p = (PDUinfo *)q->data;
v[nvals].value = p->tag;
v[nvals].strptr = p->name;
nvals++;
q = g_node_next_sibling(q);
}
break;
case TBL_SEQUENCE:
case TBL_SET:
case TBL_SEQUENCEOF:
case TBL_SETOF:
case TBL_CHOICE:
CHECKTYPE(q, TBLTYPE_Tag);
q = g_node_first_child(list);
tbl_type(n+1, pdu, q, ni);
break;
case TBL_TYPEREF: {
TypeRef *tr;
guint i;
if(!q){
break;
}
if ( ((TBLTag *)q->data)->type == TBLTYPE_Tag) {
if ((p->flags & PDU_IMPLICIT) == 0) {
p->tclass = ((TBLTag *)q->data)->tclass;
p->tag = ((TBLTag *)q->data)->code;
if (asn1_verbose)
g_message("%*s*insert type tag %c%d", n*2, empty,
tag_class[p->tclass], p->tag);
}
q = g_node_next_sibling(q);
} else {
tr = &typeDef_names[((TBLTypeRef *)q->data)->typeDefId];
if ((((p->flags & PDU_IMPLICIT) == 0) && (tr->defclass != BER_CLASS_UNI)) ||
((p->tclass | p->tag) == 0 )) {
p->tclass = tr->defclass;
p->tag = tr->deftag;
if (asn1_verbose) g_message("%*s*set tag %c%d", n*2, empty,
tag_class[p->tclass], p->tag);
}
}
CHECKTYPE(q, TBLTYPE_TypeRef);
i = ((TBLTypeRef *)q->data)->typeDefId;
p->mytype = i;
tr = &typeDef_names[i];
if (asn1_verbose)
g_message("%*s*type#%d %s, %p", n*2, empty, i, tr->name, (void *)tr->pdu);
p->asn1typename = tr->name;
if (tr->defclass == CLASSREF) {
if (tr->pdu == 0)
tr->pdu = pdu;
i = tr->deftag;
tr = &typeDef_names[i];
if (asn1_verbose)
g_message("%*s*refer to type#%d %s, %p", n*2, empty,
i, tr->name, (void *)tr->pdu);
}
if ((tr->pdu == 0) || (tr->level < type_recursion_level)) {
tr->level++;
if (tr->pdu == 0) {
tr->pdu = pdu;
}
p->flags |= ((TBLTypeRef *)q->data)->implicit? PDU_IMPLICIT : 0;
if (asn1_verbose)
g_message("%*s*typeref %s > %s%s at %p", n*2, empty,
p->name,
((TBLTypeRef *)q->data)->implicit?"implicit ":empty,
tr->name,
(void *)pdu);
tbl_typeref(n+1, pdu, tr->type, ni);
tr->level--;
} else {
if (asn1_verbose)
g_message("%*s*typeref %s > %s already at %p", n*2, empty,
p->name, tr->name, (void *)tr->pdu);
p->flags |= PDU_REFERENCE;
p->reference = tr->pdu;
}
};
break;
default:
g_warning("**** unknown tbl-type %d at line %d", p->type, __LINE__);
break;
}
if (asn1_verbose)
g_message("%*sinclude type %s %s [%p:%s, tag %c%d]",
n*2, empty, p->name, p->asn1typename, (void *)p, TBLTYPE(p->type),
tag_class[p->tclass], p->tag);
if (p->value_id == -1) {
proto_register_field_array(proto_asn1, &(p->value_hf) , 1);
save_reference(p);
if (asn1_verbose)
g_message("regist-2: %3d %3d [%3d] F%2.2x (%s)%s %s %s -> id=%d",
p->mytype, p->typenum, p->basetype, p->flags, p->asn1typename,
p->name, p->fullname,
tbl_types_wireshark_txt[p->type], p->value_id);
}
list = g_node_next_sibling(list);
}
}
static void
PDUtext(char *txt, gulong txt_size, PDUinfo *info)
{
PDUinfo *rinfo;
const char *tt, *nn, *tn, *fn, *oo, *ii, *an, *tr, *ty;
int idx;
idx = 0;
if (info) {
tt = TBLTYPE(info->type);
nn = info->name;
tn = info->asn1typename;
fn = info->fullname;
if (info->flags & PDU_NAMEDNUM)
g_snprintf(&txt[idx], txt_size - idx, "name: %2d %s", info->tag, nn);
else {
if (info->flags & PDU_TYPEDEF)
idx += g_snprintf(&txt[idx], txt_size - idx, "def %d: ", info->typenum);
else
idx += g_snprintf(&txt[idx], txt_size - idx, " ");
ty = (info->flags & PDU_TYPETREE) ? "typ" : "val";
idx += g_snprintf(&txt[idx], txt_size - idx, "%s %s (%s)%s [%s] tag %c%d hf=%d tf=%d",ty,tt, tn, nn, fn,
tag_class[info->tclass], info->tag, info->value_id, info->type_id);
idx += g_snprintf(&txt[idx], txt_size - idx, ", mt=%d, bt=%d", info->mytype, info->basetype);
oo = (info->flags & PDU_OPTIONAL) ? ", optional" : empty;
ii = (info->flags & PDU_IMPLICIT) ? ", implicit" : empty;
nn = (info->flags & PDU_NAMEDNUM) ? ", namednum" : empty;
an = (info->flags & PDU_ANONYMOUS) ? ", anonymous" : empty;
idx += g_snprintf(&txt[idx], txt_size - idx, "%s%s%s%s", oo, ii, nn, an);
if (info->flags & PDU_REFERENCE) {
rinfo = (PDUinfo *)((GNode *)(info->reference))->data;
tt = TBLTYPE(rinfo->type);
nn = rinfo->name;
tn = rinfo->asn1typename;
fn = rinfo->fullname;
idx += g_snprintf(&txt[idx], txt_size - idx, ", reference to %s (%s)%s [%s]", tt, tn, nn, fn);
if (rinfo->flags & PDU_TYPEDEF)
idx += g_snprintf(&txt[idx], txt_size - idx, " T%d", rinfo->typenum);
idx += g_snprintf(&txt[idx], txt_size - idx, " tag %c%d", tag_class[rinfo->tclass], rinfo->tag);
oo = (rinfo->flags & PDU_OPTIONAL) ? ", optional" : empty;
ii = (rinfo->flags & PDU_IMPLICIT) ? ", implicit" : empty;
nn = (rinfo->flags & PDU_NAMEDNUM) ? ", namednum" : empty;
tn = (rinfo->flags & PDU_REFERENCE) ? ", reference" : empty;
tt = (rinfo->flags & PDU_TYPEDEF) ? ", typedef" : empty;
an = (rinfo->flags & PDU_ANONYMOUS) ? ", anonymous" : empty;
tr = (rinfo->flags & PDU_TYPETREE) ? ", typetree" : empty;
g_snprintf(&txt[idx], txt_size - idx, "%s%s%s%s%s%s%s", oo, ii, nn, tn, tt, an, tr);
}
}
} else {
g_snprintf(&txt[idx], txt_size - idx, "no info available");
}
return;
}
static void
showPDUtree(GNode *p, int n)
{
PDUinfo *info;
char text[400];
while (p != 0) {
info = (PDUinfo *)p->data;
PDUtext(text, sizeof(text), info);
if (asn1_verbose) g_message("%*s%s", n*2, empty, text);
showPDUtree(g_node_first_child(p), n+1);
p = g_node_next_sibling(p);
}
return;
}
static gboolean
build_pdu_tree(const char *pduname)
{
SearchDef sd;
guint pdudef, i, tcount;
guint sav_len;
PDUinfo *info;
char text[400];
guint j, k;
gint defid;
PDUinfo *p, *q;
TypeRef *tr;
if (asn1_verbose) g_message("build msg tree from '%s' for '%s'", current_asn1, pduname);
if (!data_nodes) {
if (asn1_verbose) g_message("no data nodes");
return FALSE;
}
sd.key = pduname;
sd.here = 0;
g_node_traverse(data_nodes, G_PRE_ORDER, G_TRAVERSE_ALL, -1, is_typedef, (gpointer)&sd);
if (sd.here) {
pdudef = ((TBLTypeDef *)(sd.here->data))->typeDefId;
if (asn1_verbose) g_message("%s found, %p, typedef %d", sd.key, (void *)sd.here, pdudef);
} else {
if (asn1_verbose) g_message("%s not found, ignored", sd.key);
return FALSE;
}
if (PDUtree) {
g_node_traverse(PDUtree, G_POST_ORDER, G_TRAVERSE_ALL, -1,
free_node_data, NULL);
g_node_destroy(PDUtree);
}
info = (PDUinfo *)g_malloc0(sizeof(PDUinfo));
info->name = pduname;
info->asn1typename = pduname;
info->type = TBL_SEQUENCEOF;
info->fullname = g_strdup_printf("%s.%s", pabbrev, pduname);
info->flags = PDUinfo_initflags = 0;
info->value_id = -1;
info->type_id = -1;
info->basetype = -1;
info->mytype = pdudef;
info->value_hf.p_id = &(info->value_id);
info->value_hf.hfinfo.name = info->fullname;
info->value_hf.hfinfo.abbrev = info->fullname;
info->value_hf.hfinfo.type = tbl_types_wireshark[info->type];
info->value_hf.hfinfo.display = tbl_display_wireshark[info->type];
info->value_hf.hfinfo.blurb = info->fullname;
anonCount = 0;
PDUtree = g_node_new(info);
pabbrev_pdu_len = g_snprintf(fieldname, sizeof(fieldname), "%s.%s.", pabbrev, pduname);
sav_len = pabbrev_pdu_len;
if (asn1_verbose)
g_message("******** Define main type %d, %s", pdudef, pduname);
tbl_typeref(0, PDUtree, sd.here, pabbrev_pdu_len-1);
if (asn1_verbose)
g_message("%d anonymous types", anonCount);
if (asn1_verbose)
g_message("Define the types that are actually referenced through the top level PDU");
for (i=0, tcount=0; i<numTypedefs; i++) {
tr = &(typeDef_names[i]);
if (tr->pdu) {
tcount++;
if (i == pdudef)
g_warning("pdu %d %s defined twice, TopLevel & type", pdudef, pduname);
if (asn1_verbose)
g_message("******** Define type %d, %s", i, tr->name);
info = (PDUinfo *)g_malloc0(sizeof(PDUinfo));
info->name = tr->name;
info->asn1typename = tr->name;
info->tclass = tr->defclass;
info->tag = tr->deftag;
info->type = TBL_TYPEREF;
info->fullname = g_strdup_printf("%s.--.%s", pabbrev, tr->name);
info->flags = PDUinfo_initflags = PDU_TYPETREE;
info->value_id = -1;
info->type_id = -1;
info->basetype = -1;
info->mytype = i;
info->value_hf.p_id = &(info->value_id);
info->value_hf.hfinfo.name = info->fullname;
info->value_hf.hfinfo.abbrev = info->fullname;
info->value_hf.hfinfo.type = tbl_types_wireshark[info->type];
info->value_hf.hfinfo.display = tbl_display_wireshark[info->type];
info->value_hf.hfinfo.blurb = info->fullname;
tr->typetree = g_node_new(info);
pabbrev_pdu_len = g_snprintf(fieldname, sizeof(fieldname), "%s.--.%s.", pabbrev, tr->name);
tbl_typeref(0, tr->typetree, tr->type, pabbrev_pdu_len-1);
}
}
if (asn1_verbose)
g_message("%d types used", tcount);
pabbrev_pdu_len = sav_len;
if (asn1_verbose)
g_message("Type index:");
for (i=0; i<numTypedefs; i++) {
tr = &(typeDef_names[i]);
if (tr->pdu == 0)
continue;
if (asn1_verbose)
g_message(" %3d %s, %c%d, refs: %d",
i, tr->name, tag_class[tr->defclass], tr->deftag,
g_ptr_array_len(tr->refs));
defid = -1;
if (tr->typetree) {
p = (PDUinfo *)(tr->typetree->data);
defid = p->value_id;
if (asn1_verbose)
g_message(" -- defining id=%d", defid);
}
for(j=0; j < g_ptr_array_len(tr->refs); j++) {
p = (PDUinfo *)g_ptr_array_index(tr->refs, j);
if (p->mytype == (gint)i)
p->type_id = defid;
else {
if ((p->flags & PDU_TYPETREE) == 0) {
for(k=0; k < g_ptr_array_len(tr->refs); k++) {
q = (PDUinfo *)g_ptr_array_index(tr->refs, k);
if ((q->flags & PDU_TYPETREE) == 0)
continue;
if (q->type != p->type)
continue;
if (strcmp(q->name, p->name) == 0) {
p->type_id = q->value_id;
break;
}
}
}
}
if (asn1_verbose) {
PDUtext(text, sizeof(text), p);
g_message(" %s", text);
}
}
}
if (asn1_verbose)
g_message("The resulting PDU tree:");
showPDUtree(PDUtree, 0);
return TRUE;
}
static void
build_tree_view(GtkTreeStore *store, GNode *p, GtkTreeIter *iter)
{
GtkTreeIter iter2;
PDUinfo *info, *rinfo;
gint def, ref;
guchar *pb;
char text[400];
while (p != 0) {
info = (PDUinfo *)p->data;
gtk_tree_store_append (store, &iter2, iter);
PDUtext(text, sizeof(text), info);
def = ref = -1;
if (info->flags & PDU_TYPEDEF)
def = info->typenum;
if (info->flags & PDU_REFERENCE) {
rinfo = (PDUinfo *)((GNode *)(info->reference))->data;
ref = rinfo->typenum;
}
pb = GTK_STOCK_CANCEL;
if (G_NODE_IS_LEAF(p)) {
if (info->flags & PDU_NAMEDNUM)
pb = GTK_STOCK_BOLD;
else {
pb = GTK_STOCK_YES;
if (namelist)
fprintf(namelist, "%16s %s\n",
&(TBLTYPE(info->type)[4]), info->fullname);
}
} else {
switch (info->type) {
case TBL_ENUMERATED:
case TBL_BITSTRING:
pb = GTK_STOCK_ADD;
if (namelist)
fprintf(namelist, "%16s %s\n",
&(TBLTYPE(info->type)[4]), info->fullname);
break;
default:
break;
}
}
gtk_tree_store_set (store, &iter2,
TITLE_COLUMN, text,
DEF_COLUMN, def,
REF_COLUMN, ref,
VALUE_COLUMN, pb,
NAME_COLUMN, info->fullname,
-1);
build_tree_view(store, g_node_first_child(p), &iter2);
p = g_node_next_sibling(p);
}
return;
}
static void add_path(GtkTreePath *p)
{
if (pathstackp >= PATHSTACKMAX) {
gtk_tree_path_free(pathstack[0]);
memmove(&pathstack[0], &pathstack[1], (PATHSTACKMAX-1)*sizeof(GtkTreePath *));
pathstackp--;
}
pathstack[pathstackp++] = p;
}
static GtkTreePath *pop_path(void)
{
if (pathstackp > 0)
return pathstack[--pathstackp];
return 0;
}
static gboolean
find_definition(GtkTreeModel *model, GtkTreePath *path, GtkTreeIter *iter, gpointer data)
{
gint def;
struct DefFind *df = (struct DefFind *)data;
gtk_tree_model_get (model, iter, DEF_COLUMN, &def, -1);
if (def == df->def) {
df->path = gtk_tree_path_copy (path);
return TRUE;
}
return FALSE;
}
static void
my_signal_handler(GtkTreeView *treeview, GtkTreePath *spath, GtkTreeViewColumn *arg2, gpointer model)
{
GtkTreeIter iter;
GtkTreePath *path, *path2;
gchar *text, *oldpath, *newpath;
gint def, ref;
struct DefFind df;
(void) arg2;
path = gtk_tree_path_copy (spath);
gtk_tree_model_get_iter (model, &iter, path);
gtk_tree_model_get (model, &iter, TITLE_COLUMN, &text, DEF_COLUMN, &def, REF_COLUMN, &ref, -1);
oldpath = gtk_tree_path_to_string(path);
path2 = gtk_tree_path_copy (path);
add_path(gtk_tree_path_copy(path));
if (ref != -1) {
df.def = ref;
df.path = 0;
gtk_tree_model_foreach (model, find_definition, &df);
if (df.path) {
gtk_tree_path_free(path);
path = df.path;
}
} else {
gtk_tree_path_next(path2);
if (gtk_tree_model_get_iter (model, &iter, path2)) {
gtk_tree_path_free(path);
path = path2;
} else {
if (gtk_tree_path_get_depth (path) > 1)
gtk_tree_path_up (path);
}
}
if (path != path2)
gtk_tree_path_free (path2);
gtk_tree_view_expand_to_path (treeview, path);
gtk_tree_view_expand_row (treeview, path, FALSE);
gtk_tree_view_scroll_to_cell (treeview, path, NULL, TRUE, 0.2, 0.0);
gtk_tree_view_set_cursor (treeview, path, NULL, FALSE);
newpath = gtk_tree_path_to_string(path);
if (asn1_debug)
g_message("my_signal_handler: treeview=%p, moving from %s to %s",
treeview, oldpath, newpath);
g_free(text);
g_free(oldpath);
g_free(newpath);
}
static void
menuitem_cb (gpointer callback_data,
guint callback_action,
GtkWidget *widget)
{
GtkWidget *dialog;
GtkTreeModel *model;
GtkTreeView *treeview = gtk_item_factory_popup_data_from_widget(widget);
GtkTreeSelection *selection;
GtkTreeIter iter;
gchar *text, *name;
gint def, ref;
GtkTreePath *path;
gchar *oldpath, *newpath;
GtkTreeViewColumn *focus_column;
selection = gtk_tree_view_get_selection(treeview);
model = gtk_tree_view_get_model(treeview);
gtk_tree_view_get_cursor (treeview, &path, &focus_column);
if (gtk_tree_model_get_iter (model, &iter, path)) {
gtk_tree_model_get (model, &iter, TITLE_COLUMN, &text, DEF_COLUMN, &def, REF_COLUMN, &ref,
NAME_COLUMN, &name, -1);
oldpath = gtk_tree_path_to_string(path);
newpath = empty;
switch (callback_action) {
case 0:
gtk_tree_selection_select_path (selection, path);
break;
case 1:
path = pop_path();
if (path) {
gtk_tree_view_expand_to_path (treeview, path);
gtk_tree_view_expand_row (treeview, path, FALSE);
gtk_tree_view_scroll_to_cell (treeview, path, NULL, TRUE, 0.2, 0.0);
gtk_tree_view_set_cursor (treeview, path, NULL, FALSE);
newpath = gtk_tree_path_to_string(path);
gtk_tree_path_free(path);
} else
newpath = g_strdup("** no path **");
if (asn1_debug)
g_message("menueitem_cb: treeview=%p, moving from %s to %s",
treeview, oldpath, newpath);
break;
case 2:
default:
dialog = gtk_message_dialog_new (GTK_WINDOW (callback_data),
GTK_DIALOG_DESTROY_WITH_PARENT,
GTK_MESSAGE_INFO,
GTK_BUTTONS_CLOSE,
"You selected the menu item: \"%s\" [%d]\n%s\npath=%s, %s\nname='%s'",
gtk_item_factory_path_from_widget (widget),
callback_action, text, oldpath, newpath, name);
g_signal_connect (dialog,
"response",
G_CALLBACK (gtk_widget_destroy),
NULL);
gtk_widget_show (dialog);
break;
}
g_free(text);
g_free(name);
if (newpath != empty)
g_free(newpath);
g_free(oldpath);
} else
g_message("menuitem_cb: no iterator...");
}
static gint button_press_callback( GtkWidget *widget,
GdkEventButton *event,
gpointer data )
{
GtkTreeView *treeview = GTK_TREE_VIEW(widget);
if (event->button == 3) {
gtk_item_factory_popup_with_data ((GtkItemFactory *)data, treeview, NULL,
event->x_root,
event->y_root,
event->button,
event->time);
return TRUE;
}
return FALSE;
}
static void
create_message_window(void)
{
GtkCellRenderer *renderer;
GtkTreeStore *model;
GtkWidget *vbox;
GtkWidget *sw;
GtkWidget *treeview;
gchar *text;
GtkItemFactory *item_factory;
GtkAccelGroup *accel_group;
gint nmenu_items = sizeof (menu_items) / sizeof (menu_items[0]);
if ( ! window) {
window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), current_pduname);
g_signal_connect (window, "destroy",
G_CALLBACK (gtk_widget_destroyed), &window);
vbox = gtk_vbox_new (FALSE, 8);
gtk_container_set_border_width (GTK_CONTAINER (vbox), 4);
gtk_container_add (GTK_CONTAINER (window), vbox);
text = g_strdup_printf("ASN.1 message structure from %s, %s", current_asn1, current_pduname);
gtk_box_pack_start (GTK_BOX (vbox),
gtk_label_new (text),
FALSE, FALSE, 0);
g_free(text);
sw = gtk_scrolled_window_new (NULL, NULL);
gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (sw),
GTK_SHADOW_ETCHED_IN);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (sw),
GTK_POLICY_AUTOMATIC,
GTK_POLICY_AUTOMATIC);
gtk_box_pack_start (GTK_BOX (vbox), sw, TRUE, TRUE, 0);
model = gtk_tree_store_new(N_COLUMNS, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT,
G_TYPE_STRING, G_TYPE_STRING);
namelist = ws_fopen("namelist.txt", "w");
if (!namelist)
fprintf(stderr, "unable to open file: namelist.txt for writing!\n");
build_tree_view(model, PDUtree, NULL);
if (namelist) {
fclose(namelist);
namelist = 0;
}
treeview = gtk_tree_view_new_with_model (GTK_TREE_MODEL (model));
g_object_unref (model);
gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (treeview), TRUE);
gtk_tree_selection_set_mode (gtk_tree_view_get_selection (GTK_TREE_VIEW (treeview)),
GTK_SELECTION_MULTIPLE);
renderer = gtk_cell_renderer_text_new ();
#if 0
{
PangoAttribute* bg;
PangoAttrList* attr;
attr = pango_attr_list_new();
bg = pango_attr_background_new(50000,55000,50000);
bg->start_index = 0;
bg->end_index = 10000;
pango_attr_list_insert(attr, bg);
g_object_set(renderer, "attributes", attr, NULL);
}
#endif
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW(treeview),
TITLE_COLUMN, "asn1 entities", renderer,
"text", TITLE_COLUMN, NULL );
renderer = gtk_cell_renderer_pixbuf_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW(treeview),
VALUE_COLUMN, "value", renderer,
"stock_id", VALUE_COLUMN, NULL );
renderer = gtk_cell_renderer_text_new ();
gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW(treeview),
NAME_COLUMN, "fieldname", renderer,
"text", NAME_COLUMN, NULL );
gtk_container_add (GTK_CONTAINER (sw), treeview);
accel_group = gtk_accel_group_new ();
item_factory = gtk_item_factory_new (GTK_TYPE_MENU, "<menu>", accel_group);
gtk_item_factory_create_items (item_factory, nmenu_items, menu_items, NULL);
gtk_window_add_accel_group (GTK_WINDOW (window), accel_group);
g_signal_connect (treeview, "realize",
G_CALLBACK (gtk_tree_view_expand_all), NULL);
g_signal_connect (treeview, "row-activated",
G_CALLBACK (my_signal_handler), (gpointer)model);
g_signal_connect (treeview, "button_press_event",
G_CALLBACK (button_press_callback), item_factory);
gtk_window_set_default_size (GTK_WINDOW (window), 650, 400);
}
if (!GTK_WIDGET_VISIBLE (window))
gtk_widget_show_all (window);
else
{
gtk_widget_destroy (window);
window = NULL;
}
}
static const char *
getname(GNode *node) {
if (node == NULL || node->data == NULL)
THROW(ReportedBoundsError);
return ((PDUinfo *)node->data)->name;
}
static guint
gettype(GNode *node) {
if (node == NULL || node->data == NULL)
THROW(ReportedBoundsError);
return ((PDUinfo *)node->data)->type & TBL_TYPEmask;
}
static PDUinfo *
getinfo(GNode *node) {
if (node == NULL)
THROW(ReportedBoundsError);
return (PDUinfo *)node->data;
}
static void
showstack(statestack *pos, char *txt, int n)
{
char buf[1024];
const char *stype;
const char *rep, *chs, *done, *ref, *pop, *chr, *rch, *sch, *con;
int i, j;
statestack *p;
guint typef;
if ( ! asn1_verbose)
return;
if (n>PDUstatec)
n = PDUstatec;
if (n<0) {
g_message("==underflow");
return;
}
rep = chs = done = ref = pop = chr = rch = sch = con = empty;
#if 0
g = pos->node;
if (g) {
name = ((PDUinfo *)g->data)->name;
type = TBLTYPE(((PDUinfo *)g->data)->type);
} else {
name = "node<null>";
type = "?";
}
#endif
typef = pos->type;
stype = TBLTYPE(typef);
if (typef & TBL_REPEAT) rep = "[repeat]";
if (typef & TBL_CHOICE_made) chs = "[choice]";
if (typef & TBL_SEQUENCE_done) done = "[done]";
if (typef & TBL_REFERENCE) ref = "[ref]";
if (typef & TBL_REFERENCE_pop) pop = "[ref-pop]";
if (typef & TBL_CHOICE_repeat) chr = "[chs-rep]";
if (typef & TBL_REPEAT_choice) rch = "[rep-chs]";
if (typef & TBL_SEQUENCE_choice)sch = "[seq-chs]";
if (typef & TBL_CONSTRUCTED) con = "[constr]";
i = g_snprintf(buf, sizeof(buf), "%s sp=%d,pos=%p,%s%s%s%s%s%s%s%s%s%s:%s,%d", txt, PDUstatec,
(void *)pos->node, stype, rep, chs, done, ref, pop, chr, rch, sch, con,
pos->name, pos->offset);
for(j=1, n--; n>0; j++, n--) {
p = &PDUstate[PDUstatec-j];
typef = p->type;
stype = TBLTYPE(typef);
rep = (typef & TBL_REPEAT) ? "[repeat]" : empty;
chs = (typef & TBL_CHOICE_made) ? "[choice]" : empty;
done = (typef & TBL_SEQUENCE_done) ? "[done]" : empty;
ref = (typef & TBL_REFERENCE) ? "[ref]" : empty;
pop = (typef & TBL_REFERENCE_pop) ? "[ref-pop]" : empty;
chr = (typef & TBL_CHOICE_repeat) ? "[chs-rep]" : empty;
rch = (typef & TBL_REPEAT_choice) ? "[rep-chs]" : empty;
sch = (typef & TBL_SEQUENCE_choice)? "[seq-chs]" : empty;
con = (typef & TBL_CONSTRUCTED) ? "[constr]" : empty;
i += g_snprintf(&buf[i], sizeof(buf) - i, "| sp=%d,st=%p,%s%s%s%s%s%s%s%s%s%s:%s,%d", PDUstatec-j,
(void *)p->node, stype, rep, chs, done, ref, pop, chr, rch, sch, con,
p->name, p->offset);
}
g_message("%s", buf);
}
static void
PDUreset(int count, int count2)
{
statestack pos;
if (asn1_verbose) g_message("PDUreset %d-%d", count, count2);
PDUstatec = 0;
PDUerrcount = 0;
pos.node = NULL;
pos.name = "sentinel";
pos.type = TBL_SEQUENCEOF;
pos.offset = 0;
PUSHNODE(pos);
if (PDUtree) {
pos.node = PDUtree;
pos.name = getname(pos.node);
pos.type = gettype(pos.node) | TBL_REPEAT;
pos.offset = 0;
PUSHNODE(pos);
}
}
static GNode *
makechoice(GNode *p, guint cls, guint tag)
{
GNode *q;
PDUinfo *info;
p = g_node_first_child(p);
info = 0;
while (p) {
info = ((PDUinfo *)p->data);
if (info->type == TBL_CHOICE) {
if (asn1_verbose)
g_message(" using sub choice (%s)%s", info->asn1typename, info->name);
q = makechoice(p, cls, tag);
if (q) {
p = q;
info = ((PDUinfo *)p->data);
break;
}
} else {
if (asn1_verbose)
g_message(" have %c%d, found %c%d, %s", tag_class[cls], tag,
tag_class[info->tclass], info->tag, info->name);
if ((cls == info->tclass) && (tag == info->tag))
break;
}
p = g_node_next_sibling(p);
}
if (asn1_verbose) {
if (p) g_message(" OK, '%s:(%s)%s' chosen", tbl_types[info->type], info->asn1typename,
info->name);
else g_message(" ...no matching choice...");
}
return p;
}
static PDUprops *
getPDUprops(PDUprops *out, guint offset, guint cls, guint tag, guint cons)
{
statestack pos, pos2, save_pos;
PDUinfo *info;
const char *ret, *tmp;
int typeflags = 0, donext = 0, pushed = 0, cons_handled = 0;
static char namestr[64];
static char posstr[40];
static char noname[] = "*noname*";
static PDUprops constructed_save;
if (PDUstatec > 0)
pos = POPSTATE;
if ((PDUstatec > 0) && (pos.type & TBL_CONSTRUCTED)) {
g_snprintf(posstr, sizeof(posstr), "==off=%d %c%d%c", offset, tag_class[cls], tag, cons?'c':'p');
showstack(&pos, posstr, 3);
pos.offset = offset;
pos.type &= ~TBL_CONSTRUCTED;
PUSHNODE(pos);
PUSHNODE(pos);
*out = constructed_save;
if (asn1_verbose)
g_message(" return for constructed %s (%s)%s",
TBLTYPE(out->type), out->asn1typename, out->name);
return out;
}
save_pos = pos;
out->type = 0;
out->name = 0;
out->asn1typename = "*error*";
out->fullname = 0;
out->flags = 0;
out->data = 0;
out->value_id = -1;
out->type_id = -1;
if (PDUstatec <= 0) {
if (PDUstatec > -10) {
if (asn1_verbose)
g_message(">>off=%d stack underflow, return", offset);
}
if (PDUstatec == -10) {
if (asn1_verbose)
g_message(">>off=%d stack underflow, return, no more messages", offset);
}
out->name = "*underflow*";
out->flags |= OUT_FLAG_noname;
PDUerrcount++;
return out;
}
g_snprintf(posstr, sizeof(posstr), "==off=%d %c%d%c", offset, tag_class[cls], tag, cons?'c':'p');
showstack(&pos, posstr, 3);
if (cls == ASN1_EOI) {
if (pos.type & TBL_REFERENCE_pop) {
if (asn1_verbose) g_message(" EOI: reference pop");
pos = POPSTATE;
} else
switch(pos.type & TBL_TYPEmask) {
case TBL_TYPEREF:
if (asn1_verbose) g_message(" EOI: pop typeref");
pos = POPSTATE;
break;
case TBL_CHOICE_done:
if (asn1_verbose) g_message(" EOI: mark choice");
pos = POPSTATE;
pos.type |= TBL_CHOICE_made;
PUSHNODE(pos);
break;
default:
break;
}
pos = POPSTATE;
if (pos.node == NULL) {
if (asn1_verbose) g_message(" EOI, pos.node == NULL");
out->name = "*no-name-EOI*";
out->flags |= OUT_FLAG_noname;
PDUerrcount++;
return out;
}
info = getinfo(pos.node);
ret = info->name;
tmp = TBLTYPE(info->type);
if (offset != pos.offset) {
if (asn1_verbose)
g_message(" *EOI %s:%s mismatch, EOIoffset=%d, stack=%d",
tmp, ret, offset, pos.offset);
while ((offset < pos.offset) && (PDUstatec > 0)) {
pos = POPSTATE;
if (asn1_verbose)
g_message(" EOI extra pop, EOIoffset=%d, stack=%d",
offset, pos.offset);
}
if (offset != pos.offset)
PDUerrcount++;
} else {
if (asn1_verbose) g_message(" EOI %s:%s OK, offset=%d", tmp, ret, offset);
}
} else {
if ((cls == BER_CLASS_UNI) && (tag == BER_UNI_TAG_EOC)) {
PUSHNODE(pos);
ret = "explicit-EOC";
if (asn1_verbose) g_message(" return '%s', ignore", ret);
out->name = ret;
out->asn1typename = "ASN1";
return out;
}
if (pos.node == NULL) {
if (asn1_verbose) g_message(" pos.node == NULL");
out->name = "*no-name*";
out->flags |= OUT_FLAG_noname;
PDUerrcount++;
return out;
}
switch (pos.type & TBL_TYPEmask) {
case TBL_SEQUENCE:
case TBL_SET:
break;
default:
if (pos.type & TBL_CHOICE_made) {
if (asn1_verbose) g_message(" finish choice");
donext = 1;
}
break;
}
info = getinfo(pos.node);
if (pos.type & TBL_REPEAT) {
switch(pos.type & TBL_TYPEmask) {
case TBL_CHOICE:
if (asn1_verbose) g_message(" repeating choice");
break;
default:
if (asn1_verbose) g_message(" seqof: repeat start");
if (asn1_verbose) g_message(" seqof: first got %c%d, found %c%d",
tag_class[cls], tag,
tag_class[info->tclass], info->tag);
if ( MATCH ) {
PUSHNODE(pos);
ret = getname(pos.node);
if (asn1_verbose) g_message(" return for repeat '%s'", ret);
out->type = (pos.type & TBL_TYPEmask);
out->asn1typename = info->asn1typename;
out->name = ret;
out->value_id = info->value_id;
out->type_id = info->type_id;
if (ISANONYMOUS) {
if (asn1_verbose) g_message(" anonymous: dontshow");
if (asn1_debug)
out->flags |= OUT_FLAG_dontshow;
else
out->name = empty;
}
return out;
} else {
pos2 = pos;
CHILD;
if (pos.node) {
info = getinfo(pos.node);
if (asn1_verbose)
g_message(" seqof: child: got %c%d, found %c%d",
tag_class[cls], tag,
tag_class[info->tclass], info->tag);
}
if (pos2.type & TBL_CHOICE_repeat) {
pos = POPSTATE;
if (asn1_verbose)
g_message(" repeating a choice, %s",
getname(pos.node));
pos.type = TBL_CHOICE_immediate;
} else {
if ( pos.node && ! MATCH) {
donext = 1;
if (asn1_verbose)
g_message(" seqof: no repeat, force next");
}
pos = pos2;
}
}
break;
}
} else if (pos.type & TBL_REFERENCE_pop) {
if (asn1_verbose) g_message(" reference pop, donext");
pos = POPSTATE;
donext = 1;
} else if (pos.type & TBL_SEQUENCE_done) {
if (pos.type & TBL_SEQUENCE_choice) {
pos = POPSTATE;
} else {
donext = 1;
if (asn1_verbose) g_message(" sequence done, donext");
}
}
if (pos.type & TBL_REFERENCE) {
if (asn1_verbose) g_message(" reference change ref -> pop");
pos.type ^= (TBL_REFERENCE | TBL_REFERENCE_pop);
}
pos.offset = offset;
if (donext) {
if (asn1_verbose) g_message(" donext");
NEXT;
} else {
switch(pos.type & TBL_TYPEmask) {
case TBL_SETOF:
case TBL_SEQUENCEOF:
if ((pos.type & TBL_REPEAT) == 0) {
pos.type |= TBL_REPEAT;
PUSHNODE(pos);
CHILD;
pushed++;
typeflags |= TBL_REPEAT;
if (asn1_verbose)
g_message(" seqof: set repeat mark [push,child]");
} else {
if (asn1_verbose)
g_message(" seqof: end of repeat loop [next]");
NEXT;
}
break;
case TBL_SET:
case TBL_SEQUENCE:
pos.type |= TBL_SEQUENCE_done;
PUSHNODE(pos);
CHILD;
pushed++;
if (asn1_verbose) g_message(" seq [push,child]");
break;
case TBL_CHOICE:
pos.type = (TBL_CHOICE_done | (pos.type & ~TBL_TYPEmask));
PUSHNODE(pos);
pos.type = 0;
if (asn1_verbose)
g_message(" choice [push], %c%d, %s",
tag_class[info->tclass], info->tag, getname(pos.node));
pos.node = makechoice(pos.node, cls, tag);
if (pos.node == NULL) {
pos = POPSTATE;
out->flags |= OUT_FLAG_noname;
PDUerrcount++;
}
info = getinfo(pos.node);
ret = getname(pos.node);
if (asn1_verbose)
g_message(" '%s' %c%d will be used",
ret, tag_class[info->tclass], info->tag);
break;
case TBL_CHOICE_done:
NEXT;
break;
case TBL_TYPEREF:
pos = POPSTATE;
NEXT;
if (asn1_verbose) g_message(" typeref [pop,next]");
break;
case TBL_ENUMERATED:
case TBL_BITSTRING:
NEXT;
break;
case TBL_CHOICE_immediate:
if (asn1_verbose) g_message(" immediate choice [no next]");
break;
default:
NEXT;
break;
}
}
if (pos.node == NULL) {
ret = "*no-name-2*";
if (asn1_verbose) g_message(" return '%s'", ret);
out->name = ret;
out->flags |= OUT_FLAG_noname;
PDUerrcount++;
return out;
}
ret = pos.name = getname(pos.node);
pos.type = gettype(pos.node) | (pos.type & ~TBL_TYPEmask);
info = getinfo(pos.node);
if (asn1_verbose && info) g_message(" candidate %s '%s'%s%s, %c%d", TBLTYPE(pos.type), ret,
(ISOPTIONAL)?", optional":empty,
(ISIMPLICIT)?", implicit":empty,
tag_class[info->tclass], info->tag );
if (ISOPTIONAL) {
while(! MATCH) {
if (asn1_verbose && info)
g_message(" got %c%d, found %c%d", tag_class[cls], tag,
tag_class[info->tclass], info->tag);
NEXT;
if (pos.node == NULL) {
ret = "------";
if (cons) {
pos = save_pos;
pos.type |= TBL_SEQUENCE_done;
PUSHNODE(pos);
pos.type &= ~TBL_SEQUENCE_done;
cons_handled = 1;
out->flags |= OUT_FLAG_dontshow;
if (asn1_verbose)
g_message(" end of optional list, constructed, expect value next time");
} else {
PDUerrcount++;
out->flags |= OUT_FLAG_noname;
if (asn1_verbose)
g_message(" *end of optional list...");
info = NULL;
}
break;
}
info = getinfo(pos.node);
if (asn1_verbose) g_message(" optional, %s", getname(pos.node));
}
if (pos.node && ! cons_handled) {
ret = pos.name = getname(pos.node);
pos.type = gettype(pos.node);
}
}
if (pos.type == TBL_CHOICE) {
pos2 = pos;
if ( ! MATCH) {
if (! pushed) {
if (asn1_verbose)
g_message(" already pushed, skip next push");
PUSHNODE(pos);
typeflags &= ~TBL_CHOICE_made;
}
if (asn1_verbose && info)
g_message(" immediate choice [push], %c%d, %s",
tag_class[info->tclass], info->tag, getname(pos.node));
if (pos.node) {
pos.node = makechoice(pos.node, cls, tag);
}
if (pos.node == NULL) {
pos = POPSTATE;
PDUerrcount++;
}
info = getinfo(pos.node);
pos.type = gettype(pos.node);
out->type = (pos.type & TBL_TYPEmask);
out->flags |= OUT_FLAG_type;
g_snprintf(namestr, sizeof(namestr), "%s!%s", ret, getname(pos.node));
ret = namestr;
if (asn1_verbose)
g_message(" %s:%s will be used", TBLTYPE(pos.type), ret);
if (typeflags & TBL_REPEAT) {
pos2.type |= TBL_REPEAT | TBL_REPEAT_choice;
PUSHNODE(pos2);
pos.type |= TBL_SEQUENCE_choice;
PUSHNODE(pos);
if (asn1_verbose)
g_message(" return from immediate choice [%s] '%s'",
TBLTYPE(pos.type), ret);
out->data = pos.node;
out->type = (pos.type & TBL_TYPEmask);
out->name = ret;
if (info) {
out->asn1typename = info->asn1typename;
out->fullname = info->fullname;
out->value_id = info->value_id;
out->type_id = info->type_id;
}
return out;
} else {
typeflags |= TBL_CHOICE_made;
}
} else {
if (asn1_verbose) g_message(" matching choice '%s'", ret);
}
if ( ! cons ) {
pos = pos2;
}
}
if (asn1_verbose) {
if (info)
g_message(" using: %s '%s'%s%s, %c%d", TBLTYPE(pos.type), ret,
(ISOPTIONAL)?", optional":empty,
(ISIMPLICIT)?", implicit":empty,
tag_class[info->tclass], info->tag );
else
g_message(" using: unknown '%s'", ret);
}
if (pos.type == TBL_TYPEREF && info) {
out->asn1typename = info->asn1typename;
out->type_id = info->typenum;
out->flags |= OUT_FLAG_typename;
PUSHNODE(pos);
if (asn1_verbose) g_message(" typeref [push]");
typeflags |= TBL_REFERENCE;
if (info->reference == 0) {
pos.type = gettype(pos.node);
info = getinfo(pos.node);
tmp = "unknown tag";
if ((info->tclass == BER_CLASS_UNI) && (info->tag < 31)) {
tmp = asn1_tag[info->tag];
pos.type = asn1_uni_type[info->tag];
}
if (asn1_verbose && info)
g_message(" indirect typeref to %s:%s, %s [%c%d]",
TBLTYPE(pos.type), info->asn1typename, tmp,
tag_class[info->tclass], info->tag );
} else {
out->fullname = info->fullname;
donext = (ISANONYMOUS);
pos.node = info->reference;
pos.type = gettype(pos.node);
info = getinfo(pos.node);
if (asn1_verbose)
g_message(" typeref %s %s", TBLTYPE(pos.type), getname(pos.node));
if (donext)
ret = getname(pos.node);
out->type = (pos.type & TBL_TYPEmask);
out->flags |= OUT_FLAG_type;
out->data = pos.node;
out->flags |= OUT_FLAG_data;
if (asn1_verbose)
g_message(" typeref set named number list node %p", (void *)pos.node);
if ( ! cons) {
pos = POPSTATE;
pos.type = TBL_TYPEREF_nopop;
if (asn1_verbose) g_message(" typeref pop");
} else if ((pos.type == TBL_ENUMERATED) || (pos.type == TBL_BITSTRING)){
pos = POPSTATE;
pos.type = TBL_TYPEREF_nopop;
if (asn1_verbose) g_message(" typeref [pop]");
} else {
typeflags |= TBL_REFERENCE;
}
}
}
if (cons && ! cons_handled) {
switch(pos.type) {
case TBL_BOOLEAN:
case TBL_INTEGER:
case TBL_OCTETSTRING:
case TBL_NULL:
case TBL_OID:
case TBL_REAL:
case TBL_ENUMERATED:
case TBL_TYPEREF:
typeflags |= TBL_CONSTRUCTED;
out->flags |= (OUT_FLAG_dontshow | OUT_FLAG_constructed);
if (asn1_verbose) g_message(" dontshow and set constructed flag");
break;
default:
break;
}
}
}
if (ISANONYMOUS) {
if (asn1_verbose) g_message(" anonymous: dontshow");
if (asn1_debug)
out->flags |= OUT_FLAG_dontshow;
else
out->name = empty;
}
if (out->name != empty)
out->name = ret;
if ( ! (out->flags & OUT_FLAG_data))
out->data = pos.node;
pos.type |= typeflags;
PUSHNODE(pos);
if ( ! (out->flags & OUT_FLAG_type))
out->type = pos.type;
out->type &= TBL_TYPEmask;
if (ret == noname) {
PDUerrcount++;
out->flags |= OUT_FLAG_noname;
}
if (info && ((out->flags & OUT_FLAG_typename) == 0)) {
out->asn1typename = info->asn1typename;
out->type_id = info->typenum;
}
if (info && (out->value_id == -1)) {
out->value_id = info->value_id;
out->type_id = info->type_id;
}
if ((out->fullname == 0) && info)
out->fullname = info->fullname;
if (typeflags & TBL_CONSTRUCTED)
constructed_save = *out;
if (asn1_verbose)
g_message(" return [%s] '%s' vid=%d, tid=%d", TBLTYPE(out->type), out->name,
out->value_id, out->type_id);
return out;
}
static const char *
getPDUenum(PDUprops *props, guint offset, guint cls, guint tag, guint value)
{
GNode *list;
PDUinfo *info;
const char *ret, *name;
static char unnamed[] = "*unnamed*";
(void) cls; (void) tag;
if (props->flags & OUT_FLAG_noname)
return empty;
ret = unnamed;
list = (GNode *)props->data;
if (list == 0) {
if (asn1_verbose) g_message("--off=%d named number list not initialized", offset);
PDUerrcount++;
return "*list-still-0*";
}
if ((PDUinfo *)list->data)
name = ((PDUinfo *)list->data)->name;
else
name = ret;
for(list = g_node_first_child(list); list; list = g_node_next_sibling(list)) {
info = (PDUinfo *)list->data;
if (value == info->tag) {
ret = info->name;
break;
}
}
if (ret == unnamed)
PDUerrcount++;
if (asn1_verbose)
g_message("--off=%d namednumber %d=%s from list %s", offset, value, ret, name);
return ret;
}
void
proto_register_asn1(void) {
static const enum_val_t type_recursion_opts[] = {
{ "0", "0", 0 },
{ "1", "1", 1 },
{ "2", "2", 2 },
{ "3", "3", 3 },
{ "4", "4", 4 },
{ "4", "5", 5 },
{ "6", "6", 6 },
{ "7", "7", 7 },
{ "8", "8", 8 },
{ "9", "9", 9 },
{ NULL, NULL, -1},
};
gint *ett[1+MAX_NEST+MAXPDU];
module_t *asn1_module;
int i, j;
const char *orig_ptr;
asn1_logfile = get_tempfile_path(ASN1LOGFILE);
current_asn1 = g_strdup("");
asn1_filename = g_strdup(current_asn1);
current_pduname = g_strdup("ASN1");
asn1_pduname = g_strdup(current_pduname);
proto_asn1 = proto_register_protocol("ASN.1 decoding",
"ASN1", pabbrev);
ett[0] = &ett_asn1;
for (i=0, j=1; i<MAX_NEST; i++, j++) {
ett[j] = &ett_seq[i];
ett_seq[i] = -1;
}
for(i=0; i<MAXPDU; i++, j++) {
ett[j] = &ett_pdu[i];
ett_pdu[i] = -1;
}
proto_register_subtree_array(ett, array_length(ett));
asn1_module = prefs_register_protocol(proto_asn1,
proto_reg_handoff_asn1);
#ifdef JUST_ONE_PORT
prefs_register_uint_preference(asn1_module, "tcp_port",
"ASN.1 TCP Port",
"The TCP port on which "
"ASN.1 messages will be read",
10, &global_tcp_port_asn1);
prefs_register_uint_preference(asn1_module, "udp_port",
"ASN.1 UDP Port",
"The UDP port on which "
"ASN.1 messages will be read",
10, &global_udp_port_asn1);
prefs_register_uint_preference(asn1_module, "sctp_port",
"ASN.1 SCTP Port",
"The SCTP port on which "
"ASN.1 messages will be read",
10, &global_sctp_port_asn1);
#else
range_convert_str(&global_tcp_ports_asn1, ep_strdup_printf("%u", TCP_PORT_ASN1), 65535);
range_convert_str(&global_udp_ports_asn1, ep_strdup_printf("%u", UDP_PORT_ASN1), 65535);
range_convert_str(&global_sctp_ports_asn1, ep_strdup_printf("%u", SCTP_PORT_ASN1), 65535);
prefs_register_range_preference(asn1_module, "tcp_ports",
"ASN.1 TCP Ports",
"The TCP ports on which "
"ASN.1 messages will be read",
&global_tcp_ports_asn1, 65535);
prefs_register_range_preference(asn1_module, "udp_ports",
"ASN.1 UDP Ports",
"The UDP ports on which "
"ASN.1 messages will be read",
&global_udp_ports_asn1, 65535);
prefs_register_range_preference(asn1_module, "sctp_ports",
"ASN.1 SCTP Ports",
"The SCTP ports on which "
"ASN.1 messages will be read",
&global_sctp_ports_asn1, 65535);
#endif
prefs_register_bool_preference(asn1_module, "desegment_messages",
"Desegment TCP",
"Desegment ASN.1 messages that span TCP segments",
&asn1_desegment);
old_default_asn1_filename = get_datafile_path(OLD_DEFAULT_ASN1FILE);
#ifdef _WIN32
bad_separator_old_default_asn1_filename = get_datafile_path(BAD_SEPARATOR_OLD_DEFAULT_ASN1FILE);
#endif
orig_ptr = asn1_filename;
prefs_register_filename_preference(asn1_module, "file",
"ASN.1 type table file",
"Compiled ASN.1 description of ASN.1 types",
&asn1_filename);
g_free((char *)orig_ptr);
orig_ptr = asn1_pduname;
prefs_register_string_preference(asn1_module, "pdu_name",
"ASN.1 PDU name",
"Name of top level PDU",
&asn1_pduname);
g_free((char *)orig_ptr);
prefs_register_uint_preference(asn1_module, "first_pdu_offset",
"Offset to first PDU in first tcp packet",
"Offset for non-reassembled packets, "
"wrong if this happens on other than the first packet!",
10, &first_pdu_offset);
prefs_register_bool_preference(asn1_module, "flat",
"Show full names",
"Show full names for all values",
&asn1_full);
prefs_register_enum_preference(asn1_module, "type_recursion",
"Eliminate references to level",
"Allow this recursion level for eliminated type references",
&type_recursion_level,
type_recursion_opts, FALSE);
prefs_register_bool_preference(asn1_module, "debug",
"ASN.1 debug mode",
"Extra output useful for debugging",
&asn1_debug);
#if 0
prefs_register_bool_preference(asn1_module, "message_win",
"Show ASN.1 tree",
"show full message description",
&asn1_message_win);
#else
prefs_register_obsolete_preference(asn1_module, "message_win");
#endif
prefs_register_bool_preference(asn1_module, "verbose_log",
"Write very verbose log",
"log to file $TMP/" ASN1LOGFILE,
&asn1_verbose);
}
static void
register_tcp_port(guint32 port)
{
if (port != 0)
dissector_add_uint("tcp.port", port, asn1_handle);
}
static void
unregister_tcp_port(guint32 port)
{
if (port != 0)
dissector_delete_uint("tcp.port", port, asn1_handle);
}
static void
register_udp_port(guint32 port)
{
if (port != 0)
dissector_add_uint("udp.port", port, asn1_handle);
}
static void
unregister_udp_port(guint32 port)
{
if (port != 0)
dissector_delete_uint("udp.port", port, asn1_handle);
}
static void
register_sctp_port(guint32 port)
{
if (port != 0)
dissector_add_uint("sctp.port", port, asn1_handle);
}
static void
unregister_sctp_port(guint32 port)
{
if (port != 0)
dissector_delete_uint("sctp.port", port, asn1_handle);
}
void
proto_reg_handoff_asn1(void) {
static gboolean asn1_initialized = FALSE;
#ifdef JUST_ONE_PORT
static guint tcp_port_asn1 = 0;
static guint udp_port_asn1 = 0;
static guint sctp_port_asn1 = 0;
#else
static range_t *tcp_ports_asn1 = NULL;
static range_t *udp_ports_asn1 = NULL;
static range_t *sctp_ports_asn1 = NULL;
#endif
pcount = 0;
#ifdef JUST_ONE_PORT
if (asn1_verbose) g_message("prefs change: tcpport=%u, udpport=%u, sctpport=%u, desegment=%d, "
"asn1file=%s, pduname=%s, first_offset=%d, debug=%d, msg_win=%d, verbose=%d",
global_tcp_port_asn1, global_udp_port_asn1, global_sctp_port_asn1, asn1_desegment,
asn1_filename, asn1_pduname, first_pdu_offset, asn1_debug, asn1_message_win, asn1_verbose);
#else
if (asn1_verbose) {
char *tcp_ports_asn1_string, *udp_ports_asn1_string, *sctp_ports_asn1_string;
tcp_ports_asn1_string = range_convert_range(global_tcp_ports_asn1);
udp_ports_asn1_string = range_convert_range(global_udp_ports_asn1);
sctp_ports_asn1_string = range_convert_range(global_sctp_ports_asn1);
g_message("prefs change: tcpports=%s, udpports=%s, sctpports=%s, desegment=%d, "
"asn1file=%s, pduname=%s, first_offset=%d, debug=%d, msg_win=%d, verbose=%d",
tcp_ports_asn1_string, udp_ports_asn1_string, sctp_ports_asn1_string, asn1_desegment,
asn1_filename, asn1_pduname, first_pdu_offset, asn1_debug, asn1_message_win, asn1_verbose);
}
#endif
if(!asn1_initialized) {
asn1_handle = create_dissector_handle(dissect_asn1,proto_asn1);
asn1_initialized = TRUE;
} else {
#ifdef JUST_ONE_PORT
unregister_tcp_port(tcp_port_asn1);
unregister_udp_port(udp_port_asn1);
unregister_sctp_port(sctp_port_asn1);
#else
if (tcp_ports_asn1 != NULL) {
range_foreach(tcp_ports_asn1, unregister_tcp_port);
g_free(tcp_ports_asn1);
}
if (udp_ports_asn1 != NULL) {
range_foreach(udp_ports_asn1, unregister_udp_port);
g_free(udp_ports_asn1);
}
if (sctp_ports_asn1 != NULL) {
range_foreach(sctp_ports_asn1, unregister_sctp_port);
g_free(sctp_ports_asn1);
}
#endif
}
if (strcmp(asn1_filename, current_asn1) != 0) {
#ifdef READSYNTAX
read_asn1_type_table(asn1_filename);
#endif
g_free(current_asn1);
current_asn1 = g_strdup(asn1_filename);
}
if (!PDUtree ||
strcmp(asn1_pduname, current_pduname) != 0) {
if (build_pdu_tree(asn1_pduname)) {
g_free(current_pduname);
current_pduname = g_strdup(asn1_pduname);
}
}
#ifdef SHOWPDU
if (asn1_message_win) {
if (window) {
gtk_widget_destroy (window);
window = NULL;
}
create_message_window();
}
#endif
if (PDUtree) {
#ifdef JUST_ONE_PORT
tcp_port_asn1 = global_tcp_port_asn1;
udp_port_asn1 = global_udp_port_asn1;
sctp_port_asn1 = global_sctp_port_asn1;
register_tcp_port(tcp_port_asn1);
register_udp_port(udp_port_asn1);
register_sctp_port(sctp_port_asn1);
#else
tcp_ports_asn1 = range_copy(global_tcp_ports_asn1);
udp_ports_asn1 = range_copy(global_udp_ports_asn1);
sctp_ports_asn1 = range_copy(global_sctp_ports_asn1);
range_foreach(tcp_ports_asn1, register_tcp_port);
range_foreach(udp_ports_asn1, register_udp_port);
range_foreach(sctp_ports_asn1, register_sctp_port);
#endif
}
}
