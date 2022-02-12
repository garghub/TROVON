static void rtmpt_debug(const char *fmt, ...)
{
va_list args;
va_start(args, fmt);
vprintf(fmt, args);
}
static void rtmpt_debug(const char *fmt, ...){ (void)fmt; }
static gint rtmpt_basic_header_length(gint id)
{
switch (id & 0x3f) {
case 0: return 2;
case 1: return 3;
default: return 1;
}
}
static gint rtmpt_message_header_length(gint id)
{
switch ((id>>6) & 3) {
case 0: return 11;
case 1: return 7;
case 2: return 3;
default: return 0;
}
}
static gint
rtmpt_get_amf_length(tvbuff_t *tvb, gint offset)
{
guint8 iObjType;
gint remain = tvb_reported_length_remaining(tvb, offset);
guint32 depth = 0;
gint itemlen = 0;
gint rv = 0;
while (rv == 0 || depth > 0) {
if (depth > 0) {
if (remain-rv < 2)
return remain;
itemlen = tvb_get_ntohs(tvb, offset+rv) + 2;
if (remain-rv<itemlen+1)
return remain;
rv += itemlen;
}
if (remain-rv < 1)
return remain;
iObjType = tvb_get_guint8(tvb, offset+rv);
if (depth > 0 && itemlen == 2 && iObjType == AMF0_END_OF_OBJECT) {
rv++;
depth--;
continue;
}
switch (iObjType) {
case AMF0_NUMBER:
itemlen = 9;
break;
case AMF0_BOOLEAN:
itemlen = 2;
break;
case AMF0_STRING:
if (remain-rv < 3)
return remain;
itemlen = tvb_get_ntohs(tvb, offset+rv+1) + 3;
break;
case AMF0_NULL:
case AMF0_UNDEFINED:
case AMF0_UNSUPPORTED:
itemlen= 1;
break;
case AMF0_DATE:
itemlen = 11;
break;
case AMF0_LONG_STRING:
case AMF0_XML:
if (remain-rv < 5)
return remain;
itemlen = tvb_get_ntohl(tvb, offset+rv+1) + 5;
break;
case AMF0_INT64:
itemlen = 9;
break;
case AMF0_OBJECT:
itemlen = 1;
depth++;
break;
case AMF0_ECMA_ARRAY:
itemlen = 5;
depth++;
break;
default:
return remain;
}
if (remain-rv < itemlen)
return remain;
rv += itemlen;
}
return rv;
}
static gchar *
rtmpt_get_amf_param(tvbuff_t *tvb, gint offset, gint param, const gchar *prop)
{
guint32 remain = tvb_reported_length_remaining(tvb, offset);
guint32 itemlen;
guint32 iStringLength;
while (remain > 0 && param > 0) {
itemlen = rtmpt_get_amf_length(tvb, offset);
offset += itemlen;
remain -= itemlen;
param--;
}
if (remain > 0 && param == 0) {
guint8 iObjType = tvb_get_guint8(tvb, offset);
if (!prop && iObjType == AMF0_STRING && remain >= 3) {
iStringLength = tvb_get_ntohs(tvb, offset+1);
if (remain >= iStringLength+3) {
return tvb_get_string_enc(wmem_packet_scope(), tvb, offset+3, iStringLength, ENC_ASCII);
}
}
if (prop && iObjType == AMF0_OBJECT) {
offset++;
remain--;
while (remain > 2) {
guint32 iPropLength = tvb_get_ntohs(tvb, offset);
if (remain < 2+iPropLength+3)
break;
if (tvb_strneql(tvb, offset+2, prop, strlen(prop)) == 0) {
if (tvb_get_guint8(tvb, offset+2+iPropLength) != AMF0_STRING)
break;
iStringLength = tvb_get_ntohs(tvb, offset+2+iPropLength+1);
if (remain < 2+iPropLength+3+iStringLength)
break;
return tvb_get_string_enc(wmem_packet_scope(), tvb, offset+2+iPropLength+3, iStringLength, ENC_ASCII);
}
itemlen = rtmpt_get_amf_length(tvb, offset+2+iPropLength);
offset += 2+iPropLength+itemlen;
remain -= 2+iPropLength+itemlen;
}
}
}
return NULL;
}
static guint32
rtmpt_get_amf_txid(tvbuff_t *tvb, gint offset)
{
guint32 remain = tvb_reported_length_remaining(tvb, offset);
if (remain > 0) {
guint32 itemlen = rtmpt_get_amf_length(tvb, offset);
if (remain<itemlen)
return 0;
offset += itemlen;
remain -= itemlen;
}
if (remain >= 9) {
guint8 iObjType = tvb_get_guint8(tvb, offset);
if (iObjType == AMF0_NUMBER) {
return (guint32)tvb_get_ntohieee_double(tvb, offset+1);
}
}
return 0;
}
static gchar *
rtmpt_get_packet_desc(tvbuff_t *tvb, guint32 offset, guint32 remain, rtmpt_conv_t *rconv, int cdir, rtmpt_packet_t *tp, gint *deschasopcode)
{
if (tp->cmd == RTMPT_TYPE_CHUNK_SIZE || tp->cmd == RTMPT_TYPE_ABORT_MESSAGE ||
tp->cmd == RTMPT_TYPE_ACKNOWLEDGEMENT || tp->cmd == RTMPT_TYPE_WINDOW) {
if (tp->len >= 4 && remain >= 4) {
*deschasopcode = TRUE;
return wmem_strdup_printf(wmem_packet_scope(), "%s %d",
val_to_str(tp->cmd, rtmpt_opcode_vals, "Unknown (0x%01x)"),
tvb_get_ntohl(tvb, offset));
}
} else if (tp->cmd == RTMPT_TYPE_PEER_BANDWIDTH) {
if (tp->len >= 5 && remain >= 5) {
*deschasopcode = TRUE;
return wmem_strdup_printf(wmem_packet_scope(), "%s %d,%s",
val_to_str(tp->cmd, rtmpt_opcode_vals, "Unknown (0x%01x)"),
tvb_get_ntohl(tvb, offset),
val_to_str(tvb_get_guint8(tvb, offset+4), rtmpt_limit_vals, "Unknown (%d)"));
}
} else if (tp->cmd == RTMPT_TYPE_UCM) {
guint16 iUCM = -1;
const gchar *sFunc;
const gchar *sParam = "";
if (tp->len < 2 || remain < 2)
return NULL;
iUCM = tvb_get_ntohs(tvb, offset);
sFunc = try_val_to_str(iUCM, rtmpt_ucm_vals);
if (sFunc == NULL) {
*deschasopcode = TRUE;
sFunc = wmem_strdup_printf(wmem_packet_scope(), "User Control Message 0x%01x", iUCM);
}
if (iUCM == RTMPT_UCM_STREAM_BEGIN || iUCM == RTMPT_UCM_STREAM_EOF ||
iUCM == RTMPT_UCM_STREAM_DRY || iUCM == RTMPT_UCM_STREAM_ISRECORDED) {
if (tp->len >= 6 && remain >= 6) {
sParam = wmem_strdup_printf(wmem_packet_scope(), " %d", tvb_get_ntohl(tvb, offset+2));
}
} else if (iUCM == RTMPT_UCM_SET_BUFFER) {
if (tp->len >= 10 && remain >= 10) {
sParam = wmem_strdup_printf(wmem_packet_scope(), " %d,%dms",
tvb_get_ntohl(tvb, offset+2),
tvb_get_ntohl(tvb, offset+6));
}
}
return wmem_strdup_printf(wmem_packet_scope(), "%s%s", sFunc, sParam);
} else if (tp->cmd == RTMPT_TYPE_COMMAND_AMF0 || tp->cmd == RTMPT_TYPE_COMMAND_AMF3 ||
tp->cmd == RTMPT_TYPE_DATA_AMF0 || tp->cmd == RTMPT_TYPE_DATA_AMF3) {
guint32 slen = 0;
guint32 soff = 0;
gchar *sFunc = NULL;
gchar *sParam = NULL;
if (tp->cmd == RTMPT_TYPE_COMMAND_AMF3 || tp->cmd == RTMPT_TYPE_DATA_AMF3) {
soff = 1;
}
if (tp->len >= 3+soff && remain >= 3+soff) {
slen = tvb_get_ntohs(tvb, offset+1+soff);
}
if (slen > 0) {
sFunc = tvb_get_string_enc(wmem_packet_scope(), tvb, offset+3+soff, slen, ENC_ASCII);
RTMPT_DEBUG("got function call '%s'\n", sFunc);
if (strcmp(sFunc, "connect") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 2, "app");
} else if (strcmp(sFunc, "play") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 3, NULL);
} else if (strcmp(sFunc, "play2") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 3, "streamName");
} else if (strcmp(sFunc, "releaseStream") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 3, NULL);
} else if (strcmp(sFunc, "FCPublish") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 3, NULL);
} else if (strcmp(sFunc, "publish") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 3, NULL);
} else if (strcmp(sFunc, "onStatus") == 0) {
if (tp->cmd == RTMPT_TYPE_COMMAND_AMF0 || tp->cmd == RTMPT_TYPE_COMMAND_AMF3) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 3, "code");
} else {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 1, "code");
}
} else if (strcmp(sFunc, "onPlayStatus") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 1, "code");
} else if (strcmp(sFunc, "_result") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 3, "code");
tp->isresponse = TRUE;
} else if (strcmp(sFunc, "_error") == 0) {
sParam = rtmpt_get_amf_param(tvb, offset+soff, 3, "code");
tp->isresponse = TRUE;
}
if (tp->txid != 0 && tp->otherframe == 0) {
tp->otherframe = GPOINTER_TO_INT(wmem_tree_lookup32(rconv->txids[cdir^1], tp->txid));
if (tp->otherframe) {
RTMPT_DEBUG("got otherframe=%d\n", tp->otherframe);
}
}
}
if (sFunc) {
if (sParam) {
return wmem_strdup_printf(wmem_packet_scope(), "%s('%s')", sFunc, sParam);
} else {
return wmem_strdup_printf(wmem_packet_scope(), "%s()", sFunc);
}
}
}
return NULL;
}
static void
dissect_rtmpt_body_scm(tvbuff_t *tvb, gint offset, proto_tree *rtmpt_tree, guint scm)
{
switch (scm) {
case RTMPT_TYPE_CHUNK_SIZE:
proto_tree_add_item(rtmpt_tree, hf_rtmpt_scm_chunksize, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case RTMPT_TYPE_ABORT_MESSAGE:
proto_tree_add_item(rtmpt_tree, hf_rtmpt_scm_csid, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case RTMPT_TYPE_ACKNOWLEDGEMENT:
proto_tree_add_item(rtmpt_tree, hf_rtmpt_scm_seq, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case RTMPT_TYPE_UCM:
proto_tree_add_item(rtmpt_tree, hf_rtmpt_ucm_eventtype, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case RTMPT_TYPE_WINDOW:
proto_tree_add_item(rtmpt_tree, hf_rtmpt_scm_was, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case RTMPT_TYPE_PEER_BANDWIDTH:
proto_tree_add_item(rtmpt_tree, hf_rtmpt_scm_was, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rtmpt_tree, hf_rtmpt_scm_limittype, tvb, offset+4, 1, ENC_BIG_ENDIAN);
break;
}
}
static gint
dissect_amf0_property_list(tvbuff_t *tvb, gint offset, proto_tree *tree, guint *countp, gboolean *amf3_encoding)
{
proto_item *prop_ti;
proto_tree *prop_tree;
proto_tree *name_tree;
guint iStringLength;
gchar *iStringValue;
guint count = 0;
for (;;) {
iStringLength = tvb_get_ntohs(tvb, offset);
if (iStringLength == 0 &&
tvb_get_guint8(tvb, offset + 2) == AMF0_END_OF_OBJECT)
break;
count++;
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 2, iStringLength, ENC_ASCII);
prop_tree = proto_tree_add_subtree_format(tree, tvb, offset, -1,
ett_amf_property, &prop_ti, "Property '%s'",
iStringValue);
name_tree = proto_tree_add_subtree_format(prop_tree, tvb,
offset, 2+iStringLength,
ett_amf_string, NULL, "Name: %s", iStringValue);
proto_tree_add_uint(name_tree, hf_amf_stringlength, tvb, offset, 2, iStringLength);
offset += 2;
proto_tree_add_item(name_tree, hf_amf_string, tvb, offset, iStringLength, ENC_UTF_8|ENC_NA);
offset += iStringLength;
offset = dissect_amf0_value_type(tvb, offset, prop_tree, amf3_encoding, prop_ti);
proto_item_set_end(prop_ti, tvb, offset);
}
proto_tree_add_item(tree, hf_amf_end_of_object_marker, tvb, offset, 3, ENC_NA);
offset += 3;
*countp = count;
return offset;
}
static gint
dissect_amf0_value_type(tvbuff_t *tvb, gint offset, proto_tree *tree, gboolean *amf3_encoding, proto_item *parent_ti)
{
guint8 iObjType;
proto_item *ti;
proto_tree *val_tree;
gint iValueOffset = offset;
guint32 iIntegerValue;
double iDoubleValue;
gboolean iBooleanValue;
guint iStringLength;
gchar *iStringValue;
guint iArrayLength;
guint i;
nstime_t t;
gint64 iInteger64Value;
guint count;
iObjType = tvb_get_guint8(tvb, offset);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " %s",
val_to_str_const(iObjType, amf0_type_vals, "Unknown"));
switch (iObjType) {
case AMF0_OBJECT:
ti = proto_tree_add_item(tree, hf_amf_object, tvb, offset, -1, ENC_NA);
val_tree = proto_item_add_subtree(ti, ett_amf_value);
break;
case AMF0_ECMA_ARRAY:
ti = proto_tree_add_item(tree, hf_amf_ecmaarray, tvb, offset, -1, ENC_NA);
val_tree = proto_item_add_subtree(ti, ett_amf_value);
break;
case AMF0_STRICT_ARRAY:
ti = proto_tree_add_item(tree, hf_amf_strictarray, tvb, offset, -1, ENC_NA);
val_tree = proto_item_add_subtree(ti, ett_amf_value);
break;
default:
val_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_amf_value, &ti,
val_to_str_const(iObjType, amf0_type_vals, "Unknown"));
break;
}
proto_tree_add_uint(val_tree, hf_amf_amf0_type, tvb, iValueOffset, 1, iObjType);
iValueOffset++;
switch (iObjType) {
case AMF0_NUMBER:
iDoubleValue = tvb_get_ntohieee_double(tvb, iValueOffset);
proto_tree_add_double(val_tree, hf_amf_number, tvb, iValueOffset, 8, iDoubleValue);
iValueOffset += 8;
proto_item_append_text(ti, " %." G_STRINGIFY(DBL_DIG) "g", iDoubleValue);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " %." G_STRINGIFY(DBL_DIG) "g", iDoubleValue);
break;
case AMF0_BOOLEAN:
iBooleanValue = tvb_get_guint8(tvb, iValueOffset);
proto_tree_add_boolean(val_tree, hf_amf_boolean, tvb, iValueOffset, 1, iBooleanValue);
iValueOffset += 1;
proto_item_append_text(ti, iBooleanValue ? " true" : " false");
if (parent_ti != NULL)
proto_item_append_text(parent_ti, iBooleanValue ? " true" : " false");
break;
case AMF0_STRING:
iStringLength = tvb_get_ntohs(tvb, iValueOffset);
proto_tree_add_uint(val_tree, hf_amf_stringlength, tvb, iValueOffset, 2, iStringLength);
iValueOffset += 2;
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, iValueOffset, iStringLength, ENC_UTF_8|ENC_NA);
if (iStringLength != 0)
proto_tree_add_string(val_tree, hf_amf_string, tvb, iValueOffset, iStringLength, iStringValue);
iValueOffset += iStringLength;
proto_item_append_text(ti, " '%s'", iStringValue);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " '%s'", iStringValue);
break;
case AMF0_OBJECT:
iValueOffset = dissect_amf0_property_list(tvb, iValueOffset, val_tree, &count, amf3_encoding);
proto_item_append_text(ti, " (%u items)", count);
break;
case AMF0_NULL:
case AMF0_UNDEFINED:
break;
case AMF0_REFERENCE:
iIntegerValue = tvb_get_ntohs(tvb, iValueOffset);
proto_tree_add_uint(val_tree, hf_amf_object_reference, tvb, iValueOffset, 2, iIntegerValue);
iValueOffset += 2;
proto_item_append_text(ti, " %d", iIntegerValue);
break;
case AMF0_ECMA_ARRAY:
iArrayLength = tvb_get_ntohl(tvb, iValueOffset);
proto_tree_add_uint(val_tree, hf_amf_arraylength, tvb, iValueOffset, 4, iArrayLength);
iValueOffset += 4;
iValueOffset = dissect_amf0_property_list(tvb, iValueOffset, val_tree, &count, amf3_encoding);
proto_item_append_text(ti, " (%u items)", count);
break;
case AMF0_END_OF_OBJECT:
proto_tree_add_item(tree, hf_amf_end_of_object_marker, tvb, iValueOffset, 3, ENC_NA);
iValueOffset += 3;
break;
case AMF0_STRICT_ARRAY:
iArrayLength = tvb_get_ntohl(tvb, iValueOffset);
proto_tree_add_uint(val_tree, hf_amf_arraylength, tvb, iValueOffset, 4, iArrayLength);
iValueOffset += 4;
for (i = 0; i < iArrayLength; i++)
iValueOffset = dissect_amf0_value_type(tvb, iValueOffset, val_tree, amf3_encoding, NULL);
proto_item_append_text(ti, " (%u items)", iArrayLength);
break;
case AMF0_DATE:
iDoubleValue = tvb_get_ntohieee_double(tvb, iValueOffset);
t.secs = (time_t)(iDoubleValue/1000);
t.nsecs = (int)((iDoubleValue - 1000*(double)t.secs) * 1000000);
proto_tree_add_time(val_tree, hf_amf_date, tvb, iValueOffset, 8, &t);
iValueOffset += 8;
proto_item_append_text(ti, " %s", abs_time_to_str(wmem_packet_scope(), &t, ABSOLUTE_TIME_LOCAL, TRUE));
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " %s", abs_time_to_str(wmem_packet_scope(), &t, ABSOLUTE_TIME_LOCAL, TRUE));
iValueOffset += 2;
break;
case AMF0_LONG_STRING:
case AMF0_XML:
iStringLength = tvb_get_ntohl(tvb, iValueOffset);
proto_tree_add_uint(val_tree, hf_amf_stringlength, tvb, iValueOffset, 2, iStringLength);
iValueOffset += 4;
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, iValueOffset, iStringLength, ENC_UTF_8|ENC_NA);
if (iStringLength != 0)
proto_tree_add_string(val_tree, (iObjType == AMF0_XML) ? hf_amf_xml_doc : hf_amf_longstring, tvb, iValueOffset, iStringLength, iStringValue);
iValueOffset += iStringLength;
proto_item_append_text(ti, " '%s'", iStringValue);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " '%s'", iStringValue);
break;
case AMF0_UNSUPPORTED:
break;
case AMF0_TYPED_OBJECT:
iStringLength = tvb_get_ntohs(tvb, iValueOffset);
proto_tree_add_uint(val_tree, hf_amf_stringlength, tvb, iValueOffset, 2, iStringLength);
iValueOffset += 2;
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, iValueOffset, iStringLength, ENC_UTF_8|ENC_NA);
proto_tree_add_string(val_tree, hf_amf_string, tvb, iValueOffset, iStringLength, iStringValue);
iValueOffset += iStringLength;
iValueOffset = dissect_amf0_property_list(tvb, iValueOffset, val_tree, &count, amf3_encoding);
break;
case AMF0_AMF3_MARKER:
*amf3_encoding = TRUE;
break;
case AMF0_INT64:
iInteger64Value = tvb_get_ntoh64(tvb, iValueOffset);
proto_tree_add_int64(val_tree, hf_amf_int64, tvb, iValueOffset, 8, iInteger64Value);
iValueOffset += 8;
proto_item_append_text(ti," %" G_GINT64_MODIFIER "d", iInteger64Value);
if (parent_ti != NULL)
proto_item_append_text(parent_ti," %" G_GINT64_MODIFIER "d", iInteger64Value);
break;
default:
iValueOffset = tvb_reported_length(tvb);
break;
}
proto_item_set_end(ti, tvb, iValueOffset);
return iValueOffset;
}
static guint32
amf_get_u29(tvbuff_t *tvb, int offset, guint *lenp)
{
guint len = 0;
guint8 iByte;
guint32 iValue;
iByte = tvb_get_guint8(tvb, offset);
iValue = (iByte & 0x7F);
offset++;
len++;
if (!(iByte & 0x80)) {
*lenp = len;
return iValue;
}
iByte = tvb_get_guint8(tvb, offset);
iValue = (iValue << 7) | (iByte & 0x7F);
offset++;
len++;
if (!(iByte & 0x80)) {
*lenp = len;
return iValue;
}
iByte = tvb_get_guint8(tvb, offset);
iValue = (iValue << 7) | (iByte & 0x7F);
offset++;
len++;
if (!(iByte & 0x80)) {
*lenp = len;
return iValue;
}
iByte = tvb_get_guint8(tvb, offset);
iValue = (iValue << 8) | iByte;
len++;
*lenp = len;
return iValue;
}
static gint
dissect_amf3_value_type(tvbuff_t *tvb, gint offset, proto_tree *tree, proto_item *parent_ti)
{
guint8 iObjType;
proto_item *ti;
proto_tree *val_tree;
gint iValueOffset = offset;
guint iValueLength;
guint32 iIntegerValue;
double iDoubleValue;
guint iStringLength;
gchar *iStringValue;
guint iArrayLength;
proto_item *subval_ti;
proto_tree *subval_tree;
guint i;
gboolean iTypeIsDynamic;
guint iTraitCount;
proto_item *traits_ti;
proto_tree *traits_tree;
proto_tree *name_tree;
proto_tree *member_tree;
guint8 *iByteArrayValue;
iObjType = tvb_get_guint8(tvb, offset);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " %s",
val_to_str_const(iObjType, amf3_type_vals, "Unknown"));
switch (iObjType) {
case AMF3_ARRAY:
ti = proto_tree_add_item(tree, hf_amf_array, tvb, offset, -1, ENC_NA);
val_tree = proto_item_add_subtree(ti, ett_amf_value);
break;
case AMF3_OBJECT:
ti = proto_tree_add_item(tree, hf_amf_object, tvb, offset, -1, ENC_NA);
val_tree = proto_item_add_subtree(ti, ett_amf_value);
break;
default:
val_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_amf_value, &ti,
val_to_str_const(iObjType, amf3_type_vals, "Unknown"));
break;
}
proto_tree_add_uint(val_tree, hf_amf_amf3_type, tvb, iValueOffset, 1, iObjType);
iValueOffset++;
switch (iObjType) {
case AMF3_UNDEFINED:
case AMF3_NULL:
break;
case AMF3_FALSE:
proto_tree_add_boolean(val_tree, hf_amf_boolean, tvb, 0, 0, FALSE);
proto_item_append_text(ti, " false");
break;
case AMF3_TRUE:
proto_tree_add_boolean(val_tree, hf_amf_boolean, tvb, 0, 0, TRUE);
proto_item_append_text(ti, " true");
break;
case AMF3_INTEGER:
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
proto_tree_add_uint(val_tree, hf_amf_integer, tvb, iValueOffset, iValueLength, iIntegerValue);
proto_item_append_text(ti, " %u", iIntegerValue);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " %u", iIntegerValue);
iValueOffset += iValueLength;
break;
case AMF3_DOUBLE:
iDoubleValue = tvb_get_ntohieee_double(tvb, iValueOffset);
proto_tree_add_double(val_tree, hf_amf_number, tvb, iValueOffset, 8, iDoubleValue);
iValueOffset += 8;
proto_item_append_text(ti, " %." G_STRINGIFY(DBL_DIG) "g", iDoubleValue);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " %." G_STRINGIFY(DBL_DIG) "g", iDoubleValue);
break;
case AMF3_STRING:
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
iStringLength = iIntegerValue >> 1;
proto_tree_add_uint(val_tree, hf_amf_stringlength, tvb, iValueOffset, iValueLength, iStringLength);
iValueOffset += iValueLength;
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, iValueOffset, iStringLength, ENC_UTF_8|ENC_NA);
if (iStringLength != 0)
proto_tree_add_string(val_tree, hf_amf_string, tvb, iValueOffset, iStringLength, iStringValue);
iValueOffset += iStringLength;
proto_item_append_text(ti, " '%s'", iStringValue);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " '%s'", iStringValue);
} else {
proto_tree_add_uint(val_tree, hf_amf_string_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
iValueOffset += iValueLength;
proto_item_append_text(ti, " reference %u", iIntegerValue >> 1);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " reference %u", iIntegerValue >> 1);
}
break;
case AMF3_DATE:
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
nstime_t t;
iValueOffset += iValueLength;
iDoubleValue = tvb_get_ntohieee_double(tvb, iValueOffset);
t.secs = (time_t)(iDoubleValue/1000);
t.nsecs = (int)((iDoubleValue - 1000*(double)t.secs) * 1000000);
proto_tree_add_time(val_tree, hf_amf_date, tvb, iValueOffset, 8, &t);
iValueOffset += 8;
proto_item_append_text(ti, "%s", abs_time_to_str(wmem_packet_scope(), &t, ABSOLUTE_TIME_LOCAL, TRUE));
if (parent_ti != NULL)
proto_item_append_text(parent_ti, "%s", abs_time_to_str(wmem_packet_scope(), &t, ABSOLUTE_TIME_LOCAL, TRUE));
} else {
proto_tree_add_uint(val_tree, hf_amf_object_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
iValueOffset += iValueLength;
proto_item_append_text(ti, " object reference %u", iIntegerValue >> 1);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " object reference %u", iIntegerValue >> 1);
}
break;
case AMF3_ARRAY:
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
iArrayLength = iIntegerValue >> 1;
proto_tree_add_uint(val_tree, hf_amf_arraydenselength, tvb, iValueOffset, iValueLength, iArrayLength);
iValueOffset += iValueLength;
for (;;) {
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
iStringLength = iIntegerValue >> 1;
if (iStringLength == 0) {
proto_tree_add_item(val_tree, hf_amf_end_of_associative_part, tvb, iValueOffset, iValueLength, ENC_NA);
iValueOffset += iValueLength;
break;
}
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, iValueOffset+iValueLength, iStringLength, ENC_UTF_8|ENC_NA);
subval_tree = proto_tree_add_subtree(val_tree, tvb, iValueOffset, iStringLength,
ett_amf_array_element, &subval_ti, iStringValue);
proto_tree_add_uint(subval_tree, hf_amf_stringlength, tvb, iValueOffset, iValueLength, iStringLength);
iValueOffset += iValueLength;
proto_tree_add_string(subval_tree, hf_amf_string, tvb, iValueOffset, iStringLength, iStringValue);
} else {
subval_tree = proto_tree_add_subtree_format(val_tree, tvb, iValueOffset, iValueLength,
ett_amf_array_element, &subval_ti, "Reference %u:", iIntegerValue >> 1);
proto_tree_add_uint(subval_tree, hf_amf_string_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
}
iObjType = tvb_get_guint8(tvb, offset);
proto_item_append_text(subval_ti, "%s",
val_to_str_const(iObjType, amf3_type_vals, "Unknown"));
iValueOffset = dissect_amf3_value_type(tvb, iValueOffset, subval_tree, subval_ti);
}
for (i = 0; i < iArrayLength; i++)
iValueOffset = dissect_amf3_value_type(tvb, iValueOffset, val_tree, NULL);
proto_item_set_end(ti, tvb, iValueOffset);
} else {
proto_tree_add_uint(val_tree, hf_amf_object_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
proto_item_append_text(ti, " reference %u", iIntegerValue >> 1);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " reference %u", iIntegerValue >> 1);
}
break;
case AMF3_OBJECT:
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
if (iIntegerValue & 0x00000002) {
if (iIntegerValue & 0x00000004) {
iValueOffset += iValueLength;
} else {
iTypeIsDynamic = (iIntegerValue & 0x00000008) ? TRUE : FALSE;
iTraitCount = iIntegerValue >> 4;
proto_tree_add_uint(val_tree, hf_amf_traitcount, tvb, iValueOffset, iValueLength, iTraitCount);
iValueOffset += iValueLength;
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
iStringLength = iIntegerValue >> 1;
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, iValueOffset+iValueLength, iStringLength, ENC_UTF_8|ENC_NA);
traits_tree = proto_tree_add_subtree_format(val_tree, tvb, iValueOffset, -1,
ett_amf_traits, &traits_ti, "Traits for class %s (%u member names)", iStringValue, iTraitCount);
name_tree = proto_tree_add_subtree_format(traits_tree, tvb,
iValueOffset,
iValueLength+iStringLength,
ett_amf_string, NULL, "Class name: %s",
iStringValue);
proto_tree_add_uint(name_tree, hf_amf_classnamelength, tvb, iValueOffset, iValueLength, iStringLength);
iValueOffset += iValueLength;
proto_tree_add_string(name_tree, hf_amf_classname, tvb, iValueOffset, iStringLength, iStringValue);
iValueOffset += iStringLength;
} else {
traits_tree = proto_tree_add_subtree_format(val_tree, tvb, iValueOffset, iValueLength,
ett_amf_traits, &traits_ti, "Traits for class (reference %u for name)", iIntegerValue >> 1);
proto_tree_add_uint(traits_tree, hf_amf_string_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
iValueOffset += iValueLength;
}
for (i = 0; i < iTraitCount; i++) {
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
iStringLength = iIntegerValue >> 1;
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, iValueOffset+iValueLength, iStringLength, ENC_UTF_8|ENC_NA);
member_tree = proto_tree_add_subtree_format(traits_tree, tvb, iValueOffset, iValueLength+iStringLength,
ett_amf_trait_member, NULL, "Member '%s'", iStringValue);
proto_tree_add_uint(member_tree, hf_amf_membernamelength, tvb, iValueOffset, iValueLength, iStringLength);
iValueOffset += iValueLength;
proto_tree_add_string(member_tree, hf_amf_membername, tvb, iValueOffset, iStringLength, iStringValue);
iValueOffset += iStringLength;
} else {
proto_tree_add_uint(traits_tree, hf_amf_string_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
iValueOffset += iValueLength;
}
}
for (i = 0; i < iTraitCount; i++)
iValueOffset = dissect_amf3_value_type(tvb, iValueOffset, traits_tree, NULL);
if (iTypeIsDynamic) {
for (;;) {
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
iStringLength = iIntegerValue >> 1;
if (iStringLength == 0) {
proto_tree_add_item(traits_tree, hf_amf_end_of_dynamic_members, tvb, iValueOffset, iValueLength, ENC_NA);
iValueOffset += iValueLength;
break;
}
iStringValue = tvb_get_string_enc(wmem_packet_scope(), tvb, iValueOffset+iValueLength, iStringLength, ENC_UTF_8|ENC_NA);
subval_tree = proto_tree_add_subtree_format(traits_tree, tvb, iValueOffset, -1,
ett_amf_array_element, &subval_ti, "%s:", iStringValue);
name_tree = proto_tree_add_subtree_format(subval_tree, tvb,
iValueOffset,
iValueLength+iStringLength,
ett_amf_string, NULL, "Member name: %s",
iStringValue);
proto_tree_add_uint(name_tree, hf_amf_membernamelength, tvb, iValueOffset, iValueLength, iStringLength);
iValueOffset += iValueLength;
proto_tree_add_string(name_tree, hf_amf_membername, tvb, iValueOffset, iStringLength, iStringValue);
iValueOffset += iStringLength;
} else {
subval_tree = proto_tree_add_subtree_format(traits_tree, tvb, iValueOffset, iValueLength,
ett_amf_array_element, &subval_ti, "Reference %u:", iIntegerValue >> 1);
proto_tree_add_uint(subval_tree, hf_amf_string_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
iValueOffset += iValueLength;
}
iValueOffset = dissect_amf3_value_type(tvb, iValueOffset, subval_tree, subval_ti);
proto_item_set_end(subval_ti, tvb, iValueOffset);
}
}
proto_item_set_end(traits_ti, tvb, iValueOffset);
}
} else {
proto_tree_add_uint(val_tree, hf_amf_trait_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 2);
iValueOffset += iValueLength;
}
} else {
proto_tree_add_uint(val_tree, hf_amf_object_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
proto_item_append_text(ti, " reference %u", iIntegerValue >> 1);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " reference %u", iIntegerValue >> 1);
}
break;
case AMF3_XML:
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
iStringLength = iIntegerValue >> 1;
proto_tree_add_uint(val_tree, hf_amf_xmllength, tvb, iValueOffset, iValueLength, iStringLength);
iValueOffset += iValueLength;
proto_tree_add_item(val_tree, hf_amf_xml, tvb, iValueOffset, iStringLength, ENC_UTF_8|ENC_NA);
} else {
proto_tree_add_uint(val_tree, hf_amf_object_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
proto_item_append_text(ti, " reference %u", iIntegerValue >> 1);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " reference %u", iIntegerValue >> 1);
}
break;
case AMF3_BYTEARRAY:
iIntegerValue = amf_get_u29(tvb, iValueOffset, &iValueLength);
if (iIntegerValue & 0x00000001) {
iArrayLength = iIntegerValue >> 1;
proto_tree_add_uint(val_tree, hf_amf_bytearraylength, tvb, iValueOffset, iValueLength, iArrayLength);
iValueOffset += iValueLength;
iByteArrayValue = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, iValueOffset, iArrayLength);
proto_tree_add_bytes(val_tree, hf_amf_bytearray, tvb, iValueOffset, iArrayLength, iByteArrayValue);
proto_item_append_text(ti, " %s", bytes_to_str(wmem_packet_scope(), iByteArrayValue, iArrayLength));
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " %s", bytes_to_str(wmem_packet_scope(), iByteArrayValue, iArrayLength));
} else {
proto_tree_add_uint(val_tree, hf_amf_object_reference, tvb, iValueOffset, iValueLength, iIntegerValue >> 1);
proto_item_append_text(ti, " reference %u", iIntegerValue >> 1);
if (parent_ti != NULL)
proto_item_append_text(parent_ti, " reference %u", iIntegerValue >> 1);
}
break;
default:
iValueOffset = tvb_reported_length(tvb);
break;
}
proto_item_set_end(ti, tvb, iValueOffset);
return iValueOffset;
}
static gint
dissect_rtmpt_body_command(tvbuff_t *tvb, gint offset, proto_tree *rtmpt_tree, gboolean amf3)
{
gboolean amf3_encoding = FALSE;
if (amf3) {
offset++;
}
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
if (amf3_encoding)
offset = dissect_amf3_value_type(tvb, offset, rtmpt_tree, NULL);
else
offset = dissect_amf0_value_type(tvb, offset, rtmpt_tree, &amf3_encoding, NULL);
}
return offset;
}
static void
dissect_rtmpt_body_audio(tvbuff_t *tvb, gint offset, proto_tree *rtmpt_tree)
{
guint8 iCtl;
proto_item *ai;
proto_tree *at;
iCtl = tvb_get_guint8(tvb, offset);
ai = proto_tree_add_uint_format(rtmpt_tree, hf_rtmpt_audio_control, tvb, offset, 1, iCtl,
"Control: 0x%02x (%s %s %s %s)", iCtl,
val_to_str_const((iCtl & 0xf0)>>4, rtmpt_audio_codecs, "Unknown codec"),
val_to_str_const((iCtl & 0x0c)>>2, rtmpt_audio_rates, "Unknown rate"),
val_to_str_const((iCtl & 0x02)>>1, rtmpt_audio_sizes, "Unknown sample size"),
val_to_str_const(iCtl & 0x01, rtmpt_audio_types, "Unknown channel count"));
at = proto_item_add_subtree(ai, ett_rtmpt_audio_control);
proto_tree_add_uint(at, hf_rtmpt_audio_format, tvb, offset, 1, iCtl);
proto_tree_add_uint(at, hf_rtmpt_audio_rate, tvb, offset, 1, iCtl);
proto_tree_add_uint(at, hf_rtmpt_audio_size, tvb, offset, 1, iCtl);
proto_tree_add_uint(at, hf_rtmpt_audio_type, tvb, offset, 1, iCtl);
proto_tree_add_item(rtmpt_tree, hf_rtmpt_audio_data, tvb, offset+1, -1, ENC_NA);
}
static void
dissect_rtmpt_body_video(tvbuff_t *tvb, gint offset, proto_tree *rtmpt_tree)
{
guint8 iCtl;
proto_item *vi;
proto_tree *vt;
iCtl = tvb_get_guint8(tvb, offset);
vi = proto_tree_add_uint_format(rtmpt_tree, hf_rtmpt_video_control, tvb, offset, 1, iCtl,
"Control: 0x%02x (%s %s)", iCtl,
val_to_str_const((iCtl & 0xf0)>>4, rtmpt_video_types, "Unknown frame type"),
val_to_str_const(iCtl & 0x0f, rtmpt_video_codecs, "Unknown codec"));
vt = proto_item_add_subtree(vi, ett_rtmpt_video_control);
proto_tree_add_uint(vt, hf_rtmpt_video_type, tvb, offset, 1, iCtl);
proto_tree_add_uint(vt, hf_rtmpt_video_format, tvb, offset, 1, iCtl);
proto_tree_add_item(rtmpt_tree, hf_rtmpt_video_data, tvb, offset+1, -1, ENC_NA);
}
static void
dissect_rtmpt_body_aggregate(tvbuff_t *tvb, gint offset, proto_tree *rtmpt_tree)
{
proto_tree *tag_tree;
proto_tree *data_tree;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint8 iTagType;
guint iDataSize;
iTagType = tvb_get_guint8(tvb, offset + 0);
iDataSize = tvb_get_ntoh24(tvb, offset + 1);
tag_tree = proto_tree_add_subtree(rtmpt_tree, tvb, offset, 11+iDataSize+4, ett_rtmpt_tag, NULL,
val_to_str_const(iTagType, rtmpt_tag_vals, "Unknown Tag"));
proto_tree_add_item(tag_tree, hf_rtmpt_tag_type, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tag_tree, hf_rtmpt_tag_datasize, tvb, offset+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tag_tree, hf_rtmpt_tag_timestamp, tvb, offset+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tag_tree, hf_rtmpt_tag_ets, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tag_tree, hf_rtmpt_tag_streamid, tvb, offset+8, 3, ENC_BIG_ENDIAN);
data_tree = proto_tree_add_subtree(tag_tree, tvb, offset+11, iDataSize, ett_rtmpt_tag_data, NULL, "Data");
switch (iTagType) {
case 8:
dissect_rtmpt_body_audio(tvb, offset + 11, data_tree);
break;
case 9:
dissect_rtmpt_body_video(tvb, offset + 11, data_tree);
break;
case 18:
dissect_rtmpt_body_command(tvb, offset + 11, data_tree, FALSE);
break;
default:
break;
}
proto_tree_add_item(tag_tree, hf_rtmpt_tag_tagsize, tvb, offset+11+iDataSize, 4, ENC_BIG_ENDIAN);
offset += 11 + iDataSize + 4;
}
}
static void
dissect_rtmpt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, rtmpt_conv_t *rconv, int cdir, rtmpt_packet_t *tp)
{
gint offset = 0;
gchar *sDesc = NULL;
gint deschasopcode = FALSE;
gboolean haveETS = FALSE;
guint32 iBodyOffset = 0;
guint32 iBodyRemain = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RTMP");
RTMPT_DEBUG("Dissect: frame=%u visited=%d len=%d tree=%p\n",
pinfo->num, pinfo->fd->flags.visited,
tvb_reported_length_remaining(tvb, offset), tree);
col_clear(pinfo->cinfo, COL_INFO);
if (tvb_reported_length_remaining(tvb, offset) < 1) return;
if (tp->id <= RTMPT_ID_MAX) {
if (tp->fmt < 3
&& tvb_reported_length_remaining(tvb, offset) >= tp->bhlen+3
&& tvb_get_ntoh24(tvb, offset+tp->bhlen) == 0xffffff) {
haveETS = TRUE;
}
iBodyOffset = offset + tp->bhlen + tp->mhlen;
iBodyRemain = tvb_reported_length_remaining(tvb, iBodyOffset);
if (tp->cmd == RTMPT_TYPE_CHUNK_SIZE && tp->len >= 4 && iBodyRemain >= 4) {
guint32 newchunksize = tvb_get_ntohl(tvb, iBodyOffset);
if (newchunksize < rtmpt_max_packet_size) {
wmem_tree_insert32(rconv->chunksize[cdir], tp->lastseq, GINT_TO_POINTER(newchunksize));
}
}
if (!PINFO_FD_VISITED(pinfo)) {
if (tp->cmd == RTMPT_TYPE_COMMAND_AMF0 || tp->cmd == RTMPT_TYPE_COMMAND_AMF3 ||
tp->cmd == RTMPT_TYPE_DATA_AMF0 || tp->cmd == RTMPT_TYPE_DATA_AMF3) {
guint32 soff = 0;
if (tp->cmd == RTMPT_TYPE_COMMAND_AMF3 || tp->cmd == RTMPT_TYPE_DATA_AMF3) {
soff = 1;
}
tp->txid = rtmpt_get_amf_txid(tvb, iBodyOffset+soff);
if (tp->txid != 0) {
RTMPT_DEBUG("got txid=%d\n", tp->txid);
wmem_tree_insert32(rconv->txids[cdir], tp->txid, GINT_TO_POINTER(pinfo->num));
}
}
}
}
if (tp->id <= RTMPT_ID_MAX)
{
sDesc = rtmpt_get_packet_desc(tvb, iBodyOffset, iBodyRemain, rconv, cdir, tp, &deschasopcode);
}
if (tp->id>RTMPT_ID_MAX) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, "|", "%s",
val_to_str(tp->id, rtmpt_handshake_vals, "Unknown (0x%01x)"));
col_set_fence(pinfo->cinfo, COL_INFO);
} else if (sDesc) {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, "|", "%s", sDesc);
col_set_fence(pinfo->cinfo, COL_INFO);
} else {
col_append_sep_fstr(pinfo->cinfo, COL_INFO, "|", "%s",
val_to_str(tp->cmd, rtmpt_opcode_vals, "Unknown (0x%01x)"));
col_set_fence(pinfo->cinfo, COL_INFO);
}
if (tree)
{
proto_tree *rtmpt_tree = NULL;
proto_tree *rtmptroot_tree = NULL;
proto_item *ti;
ti = proto_tree_add_item(tree, proto_rtmpt, tvb, offset, -1, ENC_NA);
if (tp->id > RTMPT_ID_MAX) {
proto_item_append_text(ti, " (%s)",
val_to_str(tp->id, rtmpt_handshake_vals, "Unknown (0x%01x)"));
rtmptroot_tree = proto_item_add_subtree(ti, ett_rtmpt);
rtmpt_tree = proto_tree_add_subtree(rtmptroot_tree, tvb, offset, -1, ett_rtmpt_handshake, NULL,
val_to_str(tp->id, rtmpt_handshake_vals, "Unknown (0x%01x)"));
if (tp->id == RTMPT_TYPE_HANDSHAKE_1)
{
proto_tree_add_item(rtmpt_tree, hf_rtmpt_handshake_c0, tvb, 0, 1, ENC_NA);
proto_tree_add_item(rtmpt_tree, hf_rtmpt_handshake_c1, tvb, 1, 1536, ENC_NA);
}
else if (tp->id == RTMPT_TYPE_HANDSHAKE_2)
{
proto_tree_add_item(rtmpt_tree, hf_rtmpt_handshake_s0, tvb, 0, 1, ENC_NA);
proto_tree_add_item(rtmpt_tree, hf_rtmpt_handshake_s1, tvb, 1, 1536, ENC_NA);
proto_tree_add_item(rtmpt_tree, hf_rtmpt_handshake_s2, tvb, 1537, 1536, ENC_NA);
}
else if (tp->id == RTMPT_TYPE_HANDSHAKE_3)
{
proto_tree_add_item(rtmpt_tree, hf_rtmpt_handshake_c2, tvb, 0, 1536, ENC_NA);
}
return;
}
if (sDesc && deschasopcode) {
proto_item_append_text(ti, " (%s)", sDesc);
} else if (sDesc) {
proto_item_append_text(ti, " (%s %s)",
val_to_str(tp->cmd, rtmpt_opcode_vals, "Unknown (0x%01x)"), sDesc);
} else {
proto_item_append_text(ti, " (%s)",
val_to_str(tp->cmd, rtmpt_opcode_vals, "Unknown (0x%01x)"));
}
rtmptroot_tree = proto_item_add_subtree(ti, ett_rtmpt);
if (tp->otherframe != 0) {
proto_tree_add_uint(rtmptroot_tree,
tp->isresponse ? hf_rtmpt_function_response : hf_rtmpt_function_call,
tvb, offset, tp->bhlen+tp->mhlen+tp->len,
tp->otherframe);
}
rtmpt_tree = proto_tree_add_subtree(rtmptroot_tree, tvb, offset, tp->bhlen+tp->mhlen, ett_rtmpt_header, NULL, RTMPT_TEXT_RTMP_HEADER);
if (tp->fmt <= 3) proto_tree_add_item(rtmpt_tree, hf_rtmpt_header_format, tvb, offset + 0, 1, ENC_BIG_ENDIAN);
if (tp->fmt <= 3) proto_tree_add_item(rtmpt_tree, hf_rtmpt_header_csid, tvb, offset + 0, tp->bhlen, ENC_BIG_ENDIAN);
if (tp->fmt <= 2) {
if (tp->fmt > 0) {
proto_tree_add_item(rtmpt_tree, hf_rtmpt_header_timestamp_delta, tvb, offset + tp->bhlen, 3, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(rtmpt_tree, hf_rtmpt_header_timestamp, tvb, offset + tp->bhlen, 3, ENC_BIG_ENDIAN);
}
if (haveETS) {
proto_tree_add_item(rtmpt_tree, hf_rtmpt_header_ets, tvb, offset + tp->bhlen + tp->mhlen - 4, 4, ENC_BIG_ENDIAN);
}
}
if ((tp->fmt>0 && !haveETS) || tp->fmt == 3) {
proto_tree_add_uint_format_value(rtmpt_tree, hf_rtmpt_header_timestamp, tvb, offset + tp->bhlen, 0, tp->ts, "%d (calculated)", tp->ts);
}
if (tp->fmt <= 1) proto_tree_add_item(rtmpt_tree, hf_rtmpt_header_body_size, tvb, offset + tp->bhlen + 3, 3, ENC_BIG_ENDIAN);
if (tp->fmt <= 1) proto_tree_add_item(rtmpt_tree, hf_rtmpt_header_typeid, tvb, offset + tp->bhlen + 6, 1, ENC_BIG_ENDIAN);
if (tp->fmt <= 0) proto_tree_add_item(rtmpt_tree, hf_rtmpt_header_streamid, tvb, offset + tp->bhlen + 7, 4, ENC_LITTLE_ENDIAN);
if (tp->len == 0) return;
offset = iBodyOffset;
rtmpt_tree = proto_tree_add_subtree(rtmptroot_tree, tvb, offset, -1, ett_rtmpt_body, NULL, RTMPT_TEXT_RTMP_BODY);
switch (tp->cmd) {
case RTMPT_TYPE_CHUNK_SIZE:
case RTMPT_TYPE_ABORT_MESSAGE:
case RTMPT_TYPE_ACKNOWLEDGEMENT:
case RTMPT_TYPE_UCM:
case RTMPT_TYPE_WINDOW:
case RTMPT_TYPE_PEER_BANDWIDTH:
dissect_rtmpt_body_scm(tvb, offset, rtmpt_tree, tp->cmd);
break;
case RTMPT_TYPE_COMMAND_AMF0:
case RTMPT_TYPE_DATA_AMF0:
dissect_rtmpt_body_command(tvb, offset, rtmpt_tree, FALSE);
break;
case RTMPT_TYPE_COMMAND_AMF3:
case RTMPT_TYPE_DATA_AMF3:
dissect_rtmpt_body_command(tvb, offset, rtmpt_tree, TRUE);
break;
case RTMPT_TYPE_AUDIO_DATA:
dissect_rtmpt_body_audio(tvb, offset, rtmpt_tree);
break;
case RTMPT_TYPE_VIDEO_DATA:
dissect_rtmpt_body_video(tvb, offset, rtmpt_tree);
break;
case RTMPT_TYPE_AGGREGATE:
dissect_rtmpt_body_aggregate(tvb, offset, rtmpt_tree);
break;
}
}
}
static void
dissect_rtmpt_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, rtmpt_conv_t *rconv, int cdir, guint32 seq, guint32 lastackseq)
{
int offset = 0;
int remain;
int want;
guint8 header_type;
int basic_hlen;
int message_hlen;
guint32 id;
guint32 ts = 0;
guint32 tsd = 0;
int body_len;
guint8 cmd;
guint32 src;
int chunk_size;
rtmpt_frag_t *tf;
rtmpt_id_t *ti;
rtmpt_packet_t *tp;
tvbuff_t *pktbuf;
remain = tvb_reported_length(tvb);
if (!remain)
return;
RTMPT_DEBUG("Segment: cdir=%d seq=%d-%d\n", cdir, seq, seq+remain-1);
if (pinfo->fd->flags.visited) {
wmem_stack_t *packets;
packets = wmem_stack_new(wmem_packet_scope());
wmem_stack_push(packets, 0);
tp = (rtmpt_packet_t *)wmem_tree_lookup32_le(rconv->packets[cdir], seq+remain-1);
while (tp && tp->lastseq >= seq) {
wmem_stack_push(packets, tp);
tp = (rtmpt_packet_t *)wmem_tree_lookup32_le(rconv->packets[cdir], tp->lastseq-1);
}
while ((tp=(rtmpt_packet_t *)wmem_stack_pop(packets)) != NULL) {
if (tp->resident) {
pktbuf = tvb_new_child_real_data(tvb, tp->data.p, tp->have, tp->have);
add_new_data_source(pinfo, pktbuf, "Unchunked RTMP");
} else {
pktbuf = tvb_new_subset_length(tvb, tp->data.offset, tp->have);
}
dissect_rtmpt(pktbuf, pinfo, tree, rconv, cdir, tp);
}
return;
}
while (remain>0) {
tf = NULL;
ti = NULL;
tp = NULL;
if (offset == 0) {
tf = (rtmpt_frag_t *)wmem_tree_lookup32_le(rconv->frags[cdir], seq+offset-1);
if (tf) {
RTMPT_DEBUG(" tf seq=%d lseq=%d h=%d l=%d\n", tf->seq, tf->lastseq, tf->have, tf->len);
if (tf->have >= tf->len || seq+offset < tf->seq || seq+offset > tf->lastseq+tf->len-tf->have) {
tf = NULL;
} else if (!tf->ishdr) {
ti = (rtmpt_id_t *)wmem_tree_lookup32(rconv->ids[cdir], tf->saved.id);
if (ti) {
tp = (rtmpt_packet_t *)wmem_tree_lookup32_le(ti->packets, seq+offset-1);
}
if (tp && tp->chunkwant) {
goto unchunk;
}
tf = NULL;
ti = NULL;
tp = NULL;
}
if (tf) {
want = tf->len - tf->have;
if (remain<want)
want = remain;
tvb_memcpy(tvb, tf->saved.d+tf->have, offset, want);
id = tf->saved.d[0];
header_type = (id>>6) & 3;
basic_hlen = rtmpt_basic_header_length(id);
if ((header_type < 3) && (tf->have < (basic_hlen+3)) && (tf->have+want >= (basic_hlen+3))) {
if (pntoh24(tf->saved.d+basic_hlen) == 0xffffff) {
tf->len += 4;
}
}
tf->have += want;
tf->lastseq = seq+want-1;
remain -= want;
offset += want;
if (tf->have < tf->len) {
return;
}
}
}
}
if (!tf) {
id = tvb_get_guint8(tvb, offset);
if (id == RTMPT_MAGIC && seq+offset == RTMPT_HANDSHAKE_OFFSET_1) {
header_type = 4;
basic_hlen = 1;
message_hlen = 0;
id = lastackseq == 1 ? RTMPT_TYPE_HANDSHAKE_1 : RTMPT_TYPE_HANDSHAKE_2;
} else if (seq+offset == RTMPT_HANDSHAKE_OFFSET_2) {
header_type = 4;
basic_hlen = 0;
message_hlen = 0;
id = RTMPT_TYPE_HANDSHAKE_3;
} else {
header_type = (id>>6) & 3;
basic_hlen = rtmpt_basic_header_length(id);
message_hlen = rtmpt_message_header_length(id);
if ((header_type < 3) && (remain >= (basic_hlen+3))) {
if (tvb_get_ntoh24(tvb, offset+basic_hlen) == 0xffffff) {
message_hlen += 4;
}
}
if (remain < (basic_hlen+message_hlen)) {
tf = wmem_new(wmem_file_scope(), rtmpt_frag_t);
tf->ishdr = 1;
tf->seq = seq + offset;
tf->lastseq = tf->seq + remain - 1;
tf->len = basic_hlen + message_hlen;
tvb_memcpy(tvb, tf->saved.d, offset, remain);
tf->have = remain;
wmem_tree_insert32(rconv->frags[cdir], seq+offset, tf);
return;
}
id = id & 0x3f;
if (id == 0)
id = tvb_get_guint8(tvb, offset+1) + 64;
else if (id == 1)
id = tvb_get_letohs(tvb, offset+1) + 64;
}
} else {
id = tf->saved.d[0];
header_type = (id>>6) & 3;
basic_hlen = rtmpt_basic_header_length(id);
message_hlen = tf->len - basic_hlen;
id = id & 0x3f;
if (id == 0)
id = tf->saved.d[1] + 64;
else if (id == 1)
id = pletoh16(tf->saved.d+1) + 64;
}
if (id <= RTMPT_ID_MAX)
ti = (rtmpt_id_t *)wmem_tree_lookup32(rconv->ids[cdir], id);
if (ti)
tp = (rtmpt_packet_t *)wmem_tree_lookup32_le(ti->packets, seq+offset-1);
if (header_type == 0)
src = tf ? pntoh32(tf->saved.d+basic_hlen+7) : tvb_get_ntohl(tvb, offset+basic_hlen+7);
else if (ti)
src = ti->src;
else src = 0;
if (header_type < 2)
cmd = tf ? tf->saved.d[basic_hlen+6] : tvb_get_guint8(tvb, offset+basic_hlen+6);
else if (ti)
cmd = ti->cmd;
else
cmd = 0;
if (id > RTMPT_ID_MAX) {
if (id == RTMPT_TYPE_HANDSHAKE_1)
chunk_size = body_len = 1536;
else if (id == RTMPT_TYPE_HANDSHAKE_2)
chunk_size = body_len = 3072;
else
chunk_size = body_len = 1536;
} else {
chunk_size = GPOINTER_TO_INT(wmem_tree_lookup32_le(rconv->chunksize[cdir], seq+offset-1));
if (!chunk_size)
chunk_size = RTMPT_DEFAULT_CHUNK_SIZE;
if (header_type < 2)
body_len = tf ? pntoh24(tf->saved.d+basic_hlen+3) : tvb_get_ntoh24(tvb, offset+basic_hlen+3);
else if (ti)
body_len = ti->len;
else
body_len = chunk_size;
if (body_len > (gint)rtmpt_max_packet_size) {
return;
}
}
if (!ti || !tp || header_type<3 || tp->have == tp->want || tp->chunkhave != tp->chunkwant) {
RTMPT_DEBUG("New packet cdir=%d seq=%d ti=%p tp=%p header_type=%d header_len=%d id=%d tph=%d tpw=%d len=%d cs=%d\n",
cdir, seq+offset,
ti, tp, header_type, basic_hlen+message_hlen, id, tp?tp->have:0, tp?tp->want:0, body_len, chunk_size);
if (!ti) {
ti = wmem_new(wmem_file_scope(), rtmpt_id_t);
ti->packets = wmem_tree_new(wmem_file_scope());
ti->ts = 0;
ti->tsd = 0;
wmem_tree_insert32(rconv->ids[cdir], id, ti);
}
if (header_type == 0) {
ts = tf ? pntoh24(tf->saved.d+basic_hlen) : tvb_get_ntoh24(tvb, offset+basic_hlen);
if (ts == 0xffffff) {
ts = tf ? pntoh32(tf->saved.d+basic_hlen+11) : tvb_get_ntohl(tvb, offset+basic_hlen+11);
}
tsd = ts - ti->ts;
} else if (header_type < 3) {
tsd = tf ? pntoh24(tf->saved.d+basic_hlen) : tvb_get_ntoh24(tvb, offset+basic_hlen);
if (tsd == 0xffffff) {
ts = tf ? pntoh32(tf->saved.d+basic_hlen+message_hlen-4) : tvb_get_ntohl(tvb, offset+basic_hlen+message_hlen-4);
tsd = ti->tsd;
} else {
ts = ti->ts + tsd;
}
} else {
ts = ti->ts + ti->tsd;
tsd = ti->tsd;
}
tp = wmem_new(wmem_file_scope(), rtmpt_packet_t);
tp->seq = tp->lastseq = tf ? tf->seq : seq+offset;
tp->have = 0;
tp->want = basic_hlen + message_hlen + body_len;
tp->chunkwant = 0;
tp->chunkhave = 0;
tp->bhlen = basic_hlen;
tp->mhlen = message_hlen;
tp->fmt = header_type;
tp->id = id;
tp->ts = ts;
tp->len = body_len;
if (id > RTMPT_ID_MAX)
tp->cmd = id;
else
tp->cmd = cmd & 0x7f;
tp->src = src;
tp->txid = 0;
tp->isresponse = FALSE;
tp->otherframe = 0;
ti->ts = ts;
ti->tsd = tsd;
ti->len = body_len;
ti->cmd = cmd;
ti->src = src;
wmem_tree_insert32(ti->packets, tp->seq, tp);
if (!tf && body_len <= chunk_size && tp->want <= remain) {
tp->resident = FALSE;
tp->data.offset = offset;
tp->lastseq = seq+offset+tp->want-1;
tp->have = tp->want;
wmem_tree_insert32(rconv->packets[cdir], tp->lastseq, tp);
pktbuf = tvb_new_subset_length(tvb, tp->data.offset, tp->have);
dissect_rtmpt(pktbuf, pinfo, tree, rconv, cdir, tp);
offset += tp->want;
remain -= tp->want;
continue;
} else {
tp->resident = TRUE;
tp->data.p = (guint8 *)wmem_alloc(wmem_file_scope(), tp->bhlen+tp->mhlen+tp->len);
if (tf && tf->ishdr) {
memcpy(tp->data.p, tf->saved.d, tf->len);
} else {
tvb_memcpy(tvb, tp->data.p, offset, basic_hlen+message_hlen);
offset += basic_hlen + message_hlen;
remain -= basic_hlen + message_hlen;
}
tp->lastseq = seq+offset-1;
tp->have = basic_hlen + message_hlen;
if (tp->have == tp->want) {
wmem_tree_insert32(rconv->packets[cdir], tp->lastseq, tp);
pktbuf = tvb_new_child_real_data(tvb, tp->data.p, tp->have, tp->have);
add_new_data_source(pinfo, pktbuf, "Unchunked RTMP");
dissect_rtmpt(pktbuf, pinfo, tree, rconv, cdir, tp);
continue;
}
tp->chunkwant = chunk_size;
if (tp->chunkwant > tp->want-tp->have)
tp->chunkwant = tp->want - tp->have;
}
} else {
RTMPT_DEBUG("Old packet cdir=%d seq=%d ti=%p tp=%p header_len=%d id=%d tph=%d tpw=%d len=%d cs=%d\n",
cdir, seq+offset,
ti, tp, basic_hlen+message_hlen, id, tp?tp->have:0, tp?tp->want:0, body_len, chunk_size);
tp->chunkwant = chunk_size;
if (tp->chunkwant > tp->want-tp->have)
tp->chunkwant = tp->want - tp->have;
offset += basic_hlen + message_hlen;
remain -= basic_hlen + message_hlen;
}
tf = NULL;
unchunk:
want = tp->chunkwant - tp->chunkhave;
if (want > remain)
want = remain;
RTMPT_DEBUG(" cw=%d ch=%d r=%d w=%d\n", tp->chunkwant, tp->chunkhave, remain, want);
tvb_memcpy(tvb, tp->data.p+tp->have, offset, want);
if (tf) {
tf->have += want;
tf->lastseq = seq+offset+want-1;
}
tp->lastseq = seq+offset+want-1;
tp->have += want;
tp->chunkhave += want;
offset += want;
remain -= want;
if (tp->chunkhave == tp->chunkwant) {
tp->chunkhave = 0;
tp->chunkwant = 0;
}
if (tp->have == tp->want) {
wmem_tree_insert32(rconv->packets[cdir], tp->lastseq, tp);
pktbuf = tvb_new_child_real_data(tvb, tp->data.p, tp->have, tp->have);
add_new_data_source(pinfo, pktbuf, "Unchunked RTMP");
dissect_rtmpt(pktbuf, pinfo, tree, rconv, cdir, tp);
} else if (tp->chunkhave < tp->chunkwant) {
rtmpt_frag_t *tf2 = wmem_new(wmem_file_scope(), rtmpt_frag_t);
tf2->ishdr = 0;
tf2->seq = seq + offset - want;
tf2->lastseq = tf2->seq + remain - 1 + want;
tf2->have = tp->chunkhave;
tf2->len = tp->chunkwant;
tf2->saved.id = tp->id;
RTMPT_DEBUG(" inserting tf @ %d\n", seq+offset-want-1);
wmem_tree_insert32(rconv->frags[cdir], seq+offset-want-1, tf2);
}
}
}
static rtmpt_conv_t *
rtmpt_init_rconv(conversation_t *conv)
{
rtmpt_conv_t *rconv = wmem_new(wmem_file_scope(), rtmpt_conv_t);
conversation_add_proto_data(conv, proto_rtmpt, rconv);
rconv->seqs[0] = wmem_tree_new(wmem_file_scope());
rconv->seqs[1] = wmem_tree_new(wmem_file_scope());
rconv->frags[0] = wmem_tree_new(wmem_file_scope());
rconv->frags[1] = wmem_tree_new(wmem_file_scope());
rconv->ids[0] = wmem_tree_new(wmem_file_scope());
rconv->ids[1] = wmem_tree_new(wmem_file_scope());
rconv->packets[0] = wmem_tree_new(wmem_file_scope());
rconv->packets[1] = wmem_tree_new(wmem_file_scope());
rconv->chunksize[0] = wmem_tree_new(wmem_file_scope());
rconv->chunksize[1] = wmem_tree_new(wmem_file_scope());
rconv->txids[0] = wmem_tree_new(wmem_file_scope());
rconv->txids[1] = wmem_tree_new(wmem_file_scope());
return rconv;
}
static int
dissect_rtmpt_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
conversation_t *conv;
rtmpt_conv_t *rconv;
int cdir;
struct tcpinfo *tcpinfo;
if (data == NULL) {
return 0;
}
tcpinfo = (struct tcpinfo*)data;
conv = find_or_create_conversation(pinfo);
rconv = (rtmpt_conv_t*)conversation_get_proto_data(conv, proto_rtmpt);
if (!rconv) {
rconv = rtmpt_init_rconv(conv);
}
cdir = (addresses_equal(&conv->key_ptr->addr1, &pinfo->src) &&
addresses_equal(&conv->key_ptr->addr2, &pinfo->dst) &&
conv->key_ptr->port1 == pinfo->srcport &&
conv->key_ptr->port2 == pinfo->destport) ? 0 : 1;
dissect_rtmpt_common(tvb, pinfo, tree, rconv, cdir, tcpinfo->seq, tcpinfo->lastackseq);
return tvb_reported_length(tvb);
}
static int
dissect_rtmpt_http(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
conversation_t *conv;
rtmpt_conv_t *rconv;
int cdir;
guint32 seq;
guint32 lastackseq;
guint32 offset;
gint remain;
offset = 0;
remain = tvb_reported_length_remaining(tvb, 0);
cdir = pinfo->srcport == pinfo->match_uint;
if (cdir) {
conv = find_conversation(pinfo->num, &pinfo->dst, &pinfo->src, pinfo->ptype, 0, pinfo->srcport, 0);
if (!conv) {
RTMPT_DEBUG("RTMPT new conversation\n");
conv = conversation_new(pinfo->num, &pinfo->dst, &pinfo->src, pinfo->ptype, 0, pinfo->srcport, 0);
}
} else {
conv = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst, pinfo->ptype, 0, pinfo->destport, 0);
if (!conv) {
RTMPT_DEBUG("RTMPT new conversation\n");
conv = conversation_new(pinfo->num, &pinfo->src, &pinfo->dst, pinfo->ptype, 0, pinfo->destport, 0);
}
}
rconv = (rtmpt_conv_t*)conversation_get_proto_data(conv, proto_rtmpt);
if (!rconv) {
rconv = rtmpt_init_rconv(conv);
}
lastackseq = GPOINTER_TO_INT(wmem_tree_lookup32_le(rconv->seqs[cdir ^ 1], pinfo->num))+1;
if (cdir == 1 && lastackseq < 2 && remain == 17) {
offset += 17;
remain -= 17;
} else if (cdir || remain == 1) {
offset++;
remain--;
}
seq = GPOINTER_TO_INT(wmem_tree_lookup32(rconv->seqs[cdir], pinfo->num));
if (seq == 0) {
seq = GPOINTER_TO_INT(wmem_tree_lookup32_le(rconv->seqs[cdir], pinfo->num));
seq += remain;
wmem_tree_insert32(rconv->seqs[cdir], pinfo->num, GINT_TO_POINTER(seq));
}
seq -= remain-1;
RTMPT_DEBUG("RTMPT f=%d cdir=%d seq=%d lastackseq=%d len=%d\n", pinfo->num, cdir, seq, lastackseq, remain);
if (remain < 1)
return offset;
if (offset > 0) {
tvbuff_t *tvbrtmp = tvb_new_subset_length(tvb, offset, remain);
dissect_rtmpt_common(tvbrtmp, pinfo, tree, rconv, cdir, seq, lastackseq);
} else {
dissect_rtmpt_common(tvb, pinfo, tree, rconv, cdir, seq, lastackseq);
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_rtmpt_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
conversation_t *conversation;
if (tvb_reported_length(tvb) >= 12)
{
struct tcpinfo *tcpinfo = (struct tcpinfo *)data;
if (tcpinfo->lastackseq == RTMPT_HANDSHAKE_OFFSET_2
&& tcpinfo->seq == RTMPT_HANDSHAKE_OFFSET_1
&& tvb_get_guint8(tvb, 0) == RTMPT_MAGIC)
{
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, rtmpt_tcp_handle);
dissect_rtmpt_tcp(tvb, pinfo, tree, data);
return TRUE;
}
}
return FALSE;
}
static int
dissect_amf(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *amf_tree, *headers_tree, *messages_tree;
int offset;
guint header_count, message_count, i;
guint string_length;
guint header_length, message_length;
gboolean amf3_encoding = FALSE;
ti = proto_tree_add_item(tree, proto_amf, tvb, 0, -1, ENC_NA);
amf_tree = proto_item_add_subtree(ti, ett_amf);
offset = 0;
proto_tree_add_item(amf_tree, hf_amf_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
header_count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(amf_tree, hf_amf_header_count, tvb, offset, 2, header_count);
offset += 2;
if (header_count != 0) {
headers_tree = proto_tree_add_subtree(amf_tree, tvb, offset, -1, ett_amf_headers, NULL, "Headers");
for (i = 0; i < header_count; i++) {
string_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(headers_tree, hf_amf_header_name, tvb, offset, 2, ENC_UTF_8|ENC_BIG_ENDIAN);
offset += 2 + string_length;
proto_tree_add_item(headers_tree, hf_amf_header_must_understand, tvb, offset, 1, ENC_NA);
offset += 1;
header_length = tvb_get_ntohl(tvb, offset);
if (header_length == 0xFFFFFFFF)
proto_tree_add_uint_format_value(headers_tree, hf_amf_header_length, tvb, offset, 4, header_length, "Unknown");
else
proto_tree_add_uint(headers_tree, hf_amf_header_length, tvb, offset, 4, header_length);
offset += 4;
if (amf3_encoding)
offset = dissect_amf3_value_type(tvb, offset, headers_tree, NULL);
else
offset = dissect_amf0_value_type(tvb, offset, headers_tree, &amf3_encoding, NULL);
}
}
message_count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(amf_tree, hf_amf_message_count, tvb, offset, 2, message_count);
offset += 2;
if (message_count != 0) {
messages_tree = proto_tree_add_subtree(amf_tree, tvb, offset, -1, ett_amf_messages, NULL, "Messages");
for (i = 0; i < message_count; i++) {
string_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(messages_tree, hf_amf_message_target_uri, tvb, offset, 2, ENC_UTF_8|ENC_BIG_ENDIAN);
offset += 2 + string_length;
string_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(messages_tree, hf_amf_message_response_uri, tvb, offset, 2, ENC_UTF_8|ENC_BIG_ENDIAN);
offset += 2 + string_length;
message_length = tvb_get_ntohl(tvb, offset);
if (message_length == 0xFFFFFFFF)
proto_tree_add_uint_format_value(messages_tree, hf_amf_message_length, tvb, offset, 4, message_length, "Unknown");
else
proto_tree_add_uint(messages_tree, hf_amf_message_length, tvb, offset, 4, message_length);
offset += 4;
offset = dissect_rtmpt_body_command(tvb, offset, messages_tree, FALSE);
}
}
return tvb_captured_length(tvb);
}
void
proto_register_rtmpt(void)
{
static hf_register_info hf[] = {
{ &hf_rtmpt_handshake_c0,
{ "Protocol version", "rtmpt.handshake.c0", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT Handshake C0", HFILL }},
{ &hf_rtmpt_handshake_s0,
{ "Protocol version", "rtmpt.handshake.s0", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT Handshake S0", HFILL }},
{ &hf_rtmpt_handshake_c1,
{ "Handshake data", "rtmpt.handshake.c1", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT Handshake C1", HFILL }},
{ &hf_rtmpt_handshake_s1,
{ "Handshake data", "rtmpt.handshake.s1", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT Handshake S1", HFILL }},
{ &hf_rtmpt_handshake_c2,
{ "Handshake data", "rtmpt.handshake.c2", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT Handshake C2", HFILL }},
{ &hf_rtmpt_handshake_s2,
{ "Handshake data", "rtmpt.handshake.s2", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT Handshake S2", HFILL }},
{ &hf_rtmpt_header_format,
{ "Format", "rtmpt.header.format", FT_UINT8, BASE_DEC,
NULL, 0xC0, "RTMPT Basic Header format", HFILL }},
{ &hf_rtmpt_header_csid,
{ "Chunk Stream ID", "rtmpt.header.csid", FT_UINT8, BASE_DEC,
NULL, 0x3F, "RTMPT Basic Header chunk stream ID", HFILL }},
{ &hf_rtmpt_header_timestamp,
{ "Timestamp", "rtmpt.header.timestamp", FT_UINT24, BASE_DEC,
NULL, 0x0, "RTMPT Message Header timestamp", HFILL }},
{ &hf_rtmpt_header_timestamp_delta,
{ "Timestamp delta", "rtmpt.header.timestampdelta", FT_UINT24, BASE_DEC,
NULL, 0x0, "RTMPT Message Header timestamp delta", HFILL }},
{ &hf_rtmpt_header_body_size,
{ "Body size", "rtmpt.header.bodysize", FT_UINT24, BASE_DEC,
NULL, 0x0, "RTMPT Message Header body size", HFILL }},
{ &hf_rtmpt_header_typeid,
{ "Type ID", "rtmpt.header.typeid", FT_UINT8, BASE_HEX,
VALS(rtmpt_opcode_vals), 0x0, "RTMPT Message Header type ID", HFILL }},
{ &hf_rtmpt_header_streamid,
{ "Stream ID", "rtmpt.header.streamid", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT Header stream ID", HFILL }},
{ &hf_rtmpt_header_ets,
{ "Extended timestamp", "rtmpt.header.ets", FT_UINT24, BASE_DEC,
NULL, 0x0, "RTMPT Message Header extended timestamp", HFILL }},
{ &hf_rtmpt_scm_chunksize,
{ "Chunk size", "rtmpt.scm.chunksize", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT SCM chunk size", HFILL }},
{ &hf_rtmpt_scm_csid,
{ "Chunk stream ID", "rtmpt.scm.csid", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT SCM chunk stream ID", HFILL }},
{ &hf_rtmpt_scm_seq,
{ "Sequence number", "rtmpt.scm.seq", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT SCM acknowledgement sequence number", HFILL }},
{ &hf_rtmpt_scm_was,
{ "Window acknowledgement size", "rtmpt.scm.was", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT SCM window acknowledgement size", HFILL }},
{ &hf_rtmpt_scm_limittype,
{ "Limit type", "rtmpt.scm.limittype", FT_UINT8, BASE_DEC,
VALS(rtmpt_limit_vals), 0x0, "RTMPT SCM window acknowledgement size", HFILL }},
{ &hf_rtmpt_ucm_eventtype,
{ "Event type", "rtmpt.ucm.eventtype", FT_UINT16, BASE_DEC,
VALS(rtmpt_ucm_vals), 0x0, "RTMPT UCM event type", HFILL }},
{ &hf_rtmpt_function_call,
{ "Response to this call in frame", "rtmpt.function.call", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "RTMPT function call", HFILL }},
{ &hf_rtmpt_function_response,
{ "Call for this response in frame", "rtmpt.function.response", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "RTMPT function response", HFILL }},
{ &hf_rtmpt_audio_control,
{ "Audio control", "rtmpt.audio.control", FT_UINT8, BASE_HEX,
NULL, 0x0, "RTMPT Audio control", HFILL }},
{ &hf_rtmpt_audio_format,
{ "Format", "rtmpt.audio.format", FT_UINT8, BASE_DEC,
VALS(rtmpt_audio_codecs), 0xf0, "RTMPT Audio format", HFILL }},
{ &hf_rtmpt_audio_rate,
{ "Sample rate", "rtmpt.audio.rate", FT_UINT8, BASE_DEC,
VALS(rtmpt_audio_rates), 0x0c, "RTMPT Audio sample rate", HFILL }},
{ &hf_rtmpt_audio_size,
{ "Sample size", "rtmpt.audio.size", FT_UINT8, BASE_DEC,
VALS(rtmpt_audio_sizes), 0x02, "RTMPT Audio sample size", HFILL }},
{ &hf_rtmpt_audio_type,
{ "Channels", "rtmpt.audio.type", FT_UINT8, BASE_DEC,
VALS(rtmpt_audio_types), 0x01, "RTMPT Audio channel count", HFILL }},
{ &hf_rtmpt_audio_data,
{ "Audio data", "rtmpt.audio.data", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT Audio data", HFILL }},
{ &hf_rtmpt_video_control,
{ "Video control", "rtmpt.video.control", FT_UINT8, BASE_HEX,
NULL, 0x0, "RTMPT Video control", HFILL }},
{ &hf_rtmpt_video_type,
{ "Type", "rtmpt.video.type", FT_UINT8, BASE_DEC,
VALS(rtmpt_video_types), 0xf0, "RTMPT Video type", HFILL }},
{ &hf_rtmpt_video_format,
{ "Format", "rtmpt.video.format", FT_UINT8, BASE_DEC,
VALS(rtmpt_video_codecs), 0x0f, "RTMPT Video format", HFILL }},
{ &hf_rtmpt_video_data,
{ "Video data", "rtmpt.video.data", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT Video data", HFILL }},
{ &hf_rtmpt_tag_type,
{ "Type", "rtmpt.tag.type", FT_UINT8, BASE_DEC,
VALS(rtmpt_tag_vals), 0x0, "RTMPT Aggregate tag type", HFILL }},
{ &hf_rtmpt_tag_datasize,
{ "Data size", "rtmpt.tag.datasize", FT_UINT24, BASE_DEC,
NULL, 0x0, "RTMPT Aggregate tag data size", HFILL }},
{ &hf_rtmpt_tag_timestamp,
{ "Timestamp", "rtmpt.tag.timestamp", FT_UINT24, BASE_DEC,
NULL, 0x0, "RTMPT Aggregate tag timestamp", HFILL }},
{ &hf_rtmpt_tag_ets,
{ "Timestamp Extended", "rtmpt.tag.ets", FT_UINT8, BASE_DEC,
NULL, 0x0, "RTMPT Aggregate tag timestamp extended", HFILL }},
{ &hf_rtmpt_tag_streamid,
{ "Stream ID", "rtmpt.tag.streamid", FT_UINT24, BASE_DEC,
NULL, 0x0, "RTMPT Aggregate tag stream ID", HFILL }},
{ &hf_rtmpt_tag_tagsize,
{ "Previous tag size", "rtmpt.tag.tagsize", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT Aggregate previous tag size", HFILL }}
};
static gint *ett[] = {
&ett_rtmpt,
&ett_rtmpt_handshake,
&ett_rtmpt_header,
&ett_rtmpt_body,
&ett_rtmpt_ucm,
&ett_rtmpt_audio_control,
&ett_rtmpt_video_control,
&ett_rtmpt_tag,
&ett_rtmpt_tag_data
};
module_t *rtmpt_module;
proto_rtmpt = proto_register_protocol("Real Time Messaging Protocol", "RTMPT", "rtmpt");
proto_register_field_array(proto_rtmpt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
rtmpt_module = prefs_register_protocol(proto_rtmpt, NULL);
prefs_register_bool_preference(rtmpt_module, "desegment",
"Reassemble RTMPT messages spanning multiple TCP segments",
"Whether the RTMPT dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\""
" in the TCP protocol settings.",
&rtmpt_desegment);
prefs_register_uint_preference(rtmpt_module, "max_packet_size",
"Maximum packet size",
"The largest acceptable packet size for reassembly",
10, &rtmpt_max_packet_size);
}
void
proto_register_amf(void)
{
static hf_register_info hf[] = {
{ &hf_amf_version,
{ "AMF version", "amf.version", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_header_count,
{ "Header count", "amf.header_count", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_header_name,
{ "Name", "amf.header.name", FT_UINT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_header_must_understand,
{ "Must understand", "amf.header.must_understand", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_header_length,
{ "Length", "amf.header.length", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_amf_header_value_type,
{ "Value type", "amf.header.value_type", FT_UINT32, BASE_HEX,
VALS(rtmpt_type_vals), 0x0, NULL, HFILL }},
#endif
{ &hf_amf_message_count,
{ "Message count", "amf.message_count", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_message_target_uri,
{ "Target URI", "amf.message.target_uri", FT_UINT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_message_response_uri,
{ "Response URI", "amf.message.response_uri", FT_UINT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_message_length,
{ "Length", "amf.message.length", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_amf0_type,
{ "AMF0 type", "amf.amf0_type", FT_UINT8, BASE_HEX,
VALS(amf0_type_vals), 0x0, NULL, HFILL }},
{ &hf_amf_amf3_type,
{ "AMF3 type", "amf.amf3_type", FT_UINT8, BASE_HEX,
VALS(amf3_type_vals), 0x0, NULL, HFILL }},
{ &hf_amf_number,
{ "Number", "amf.number", FT_DOUBLE, BASE_NONE,
NULL, 0x0, "AMF number", HFILL }},
{ &hf_amf_integer,
{ "Integer", "amf.integer", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT AMF3 integer", HFILL }},
{ &hf_amf_boolean,
{ "Boolean", "amf.boolean", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "AMF boolean", HFILL }},
{ &hf_amf_stringlength,
{ "String length", "amf.stringlength", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF string length", HFILL }},
{ &hf_amf_string,
{ "String", "amf.string", FT_STRING, BASE_NONE,
NULL, 0x0, "AMF string", HFILL }},
{ &hf_amf_string_reference,
{ "String reference", "amf.string_reference", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT AMF3 string reference", HFILL }},
{ &hf_amf_object_reference,
{ "Object reference", "amf.object_reference", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF object reference", HFILL }},
{ &hf_amf_date,
{ "Date", "amf.date", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0, "AMF date", HFILL }},
#if 0
{ &hf_amf_longstringlength,
{ "String length", "amf.longstringlength", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF long string length", HFILL }},
#endif
{ &hf_amf_longstring,
{ "Long string", "amf.longstring", FT_STRING, BASE_NONE,
NULL, 0x0, "AMF long string", HFILL }},
{ &hf_amf_xml_doc,
{ "XML document", "amf.xml_doc", FT_STRING, BASE_NONE,
NULL, 0x0, "AMF XML document", HFILL }},
{ &hf_amf_xmllength,
{ "XML text length", "amf.xmllength", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF E4X XML length", HFILL }},
{ &hf_amf_xml,
{ "XML", "amf.xml", FT_STRING, BASE_NONE,
NULL, 0x0, "AMF E4X XML", HFILL }},
{ &hf_amf_int64,
{ "Int64", "amf.int64", FT_INT64, BASE_DEC,
NULL, 0x0, "AMF int64", HFILL }},
{ &hf_amf_bytearraylength,
{ "ByteArray length", "amf.bytearraylength", FT_UINT32, BASE_DEC,
NULL, 0x0, "RTMPT AMF3 ByteArray length", HFILL }},
{ &hf_amf_bytearray,
{ "ByteArray", "amf.bytearray", FT_BYTES, BASE_NONE,
NULL, 0x0, "RTMPT AMF3 ByteArray", HFILL }},
{ &hf_amf_object,
{ "Object", "amf.object", FT_NONE, BASE_NONE,
NULL, 0x0, "AMF object", HFILL }},
{ &hf_amf_traitcount,
{ "Trait count", "amf.traitcount", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF count of traits for an object", HFILL }},
{ &hf_amf_classnamelength,
{ "Class name length", "amf.classnamelength", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF class name length", HFILL }},
{ &hf_amf_classname,
{ "Class name", "amf.classname", FT_STRING, BASE_NONE,
NULL, 0x0, "AMF class name", HFILL }},
{ &hf_amf_membernamelength,
{ "Member name length", "amf.membernamelength", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF member name length", HFILL }},
{ &hf_amf_membername,
{ "Member name", "amf.membername", FT_STRING, BASE_NONE,
NULL, 0x0, "AMF member name", HFILL }},
{ &hf_amf_trait_reference,
{ "Trait reference", "amf.trait_reference", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF trait reference", HFILL }},
{ &hf_amf_ecmaarray,
{ "ECMA array", "amf.ecmaarray", FT_NONE, BASE_NONE,
NULL, 0x0, "AMF ECMA array", HFILL }},
{ &hf_amf_strictarray,
{ "Strict array", "amf.strictarray", FT_NONE, BASE_NONE,
NULL, 0x0, "AMF strict array", HFILL }},
{ &hf_amf_array,
{ "Array", "amf.array", FT_NONE, BASE_NONE,
NULL, 0x0, "RTMPT AMF3 array", HFILL }},
{ &hf_amf_arraylength,
{ "Array length", "amf.arraylength", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF array length", HFILL }},
{ &hf_amf_arraydenselength,
{ "Length of dense portion", "amf.arraydenselength", FT_UINT32, BASE_DEC,
NULL, 0x0, "AMF length of dense portion of array", HFILL }},
{ &hf_amf_end_of_object_marker,
{ "End Of Object Marker", "amf.end_of_object_marker", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_end_of_associative_part,
{ "End of associative part", "amf.end_of_associative_part", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_amf_end_of_dynamic_members,
{ "End Of dynamic members", "amf.end_of_dynamic_members", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_amf,
&ett_amf_headers,
&ett_amf_messages,
&ett_amf_value,
&ett_amf_property,
&ett_amf_string,
&ett_amf_array_element,
&ett_amf_traits,
&ett_amf_trait_member,
};
proto_amf = proto_register_protocol("Action Message Format", "AMF", "amf");
proto_register_field_array(proto_amf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_rtmpt(void)
{
dissector_handle_t amf_handle;
heur_dissector_add("tcp", dissect_rtmpt_heur, "RTMPT over TCP", "rtmpt_tcp", proto_rtmpt, HEURISTIC_DISABLE);
rtmpt_tcp_handle = create_dissector_handle(dissect_rtmpt_tcp, proto_rtmpt);
dissector_add_uint("tcp.port", RTMP_PORT, rtmpt_tcp_handle);
rtmpt_http_handle = create_dissector_handle(dissect_rtmpt_http, proto_rtmpt);
dissector_add_string("media_type", "application/x-fcs", rtmpt_http_handle);
amf_handle = create_dissector_handle(dissect_amf, proto_amf);
dissector_add_string("media_type", "application/x-amf", amf_handle);
}
