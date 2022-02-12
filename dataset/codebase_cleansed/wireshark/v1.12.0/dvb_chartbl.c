static dvb_encoding_e
dvb_analyze_string_charset0(guint8 byte0)
{
switch (byte0) {
case 0x01:
return DVB_ENCODING_ISO_8859_5;
case 0x02:
return DVB_ENCODING_ISO_8859_6;
case 0x03:
return DVB_ENCODING_ISO_8859_7;
case 0x04:
return DVB_ENCODING_ISO_8859_8;
case 0x05:
return DVB_ENCODING_ISO_8859_9;
case 0x06:
return DVB_ENCODING_ISO_8859_10;
case 0x07:
return DVB_ENCODING_ISO_8859_11;
case 0x08:
return DVB_ENCODING_RESERVED;
case 0x09:
return DVB_ENCODING_ISO_8859_13;
case 0x0A:
return DVB_ENCODING_ISO_8859_14;
case 0x0B:
return DVB_ENCODING_ISO_8859_15;
case 0x11:
return DVB_ENCODING_ISO_10646_BMP;
case 0x12:
return DVB_ENCODING_KSX_1001;
case 0x13:
return DVB_ENCODING_GB_2312;
case 0x14:
return DVB_ENCODING_ISO_10646_BIG5;
case 0x15:
return DVB_ENCODING_ISO_10646_UTF8_BMP;
default:
return DVB_ENCODING_UNKNOWN;
}
}
static dvb_encoding_e
dvb_analyze_string_charset0_10(guint16 byte12)
{
switch (byte12) {
case 0x0000:
return DVB_ENCODING_RESERVED;
case 0x0001:
return DVB_ENCODING_ISO_8859_1;
case 0x0002:
return DVB_ENCODING_ISO_8859_2;
case 0x0003:
return DVB_ENCODING_ISO_8859_3;
case 0x0004:
return DVB_ENCODING_ISO_8859_4;
case 0x0005:
return DVB_ENCODING_ISO_8859_5;
case 0x0006:
return DVB_ENCODING_ISO_8859_6;
case 0x0007:
return DVB_ENCODING_ISO_8859_7;
case 0x0008:
return DVB_ENCODING_ISO_8859_8;
case 0x0009:
return DVB_ENCODING_ISO_8859_9;
case 0x000A:
return DVB_ENCODING_ISO_8859_10;
case 0x000B:
return DVB_ENCODING_ISO_8859_11;
case 0x000C:
return DVB_ENCODING_RESERVED;
case 0x000D:
return DVB_ENCODING_ISO_8859_13;
case 0x000E:
return DVB_ENCODING_ISO_8859_14;
case 0x000F:
return DVB_ENCODING_ISO_8859_15;
default:
return DVB_ENCODING_UNKNOWN;
}
}
static dvb_encoding_e
dvb_analyze_string_charset0_1F(guint8 byte1)
{
switch (byte1) {
case 0x00:
return DVB_ENCODING_RESERVED;
case 0x01:
case 0x02:
case 0x03:
case 0x04:
return DVB_ENCODING_RESERVED;
case 0x05:
case 0x06:
return DVB_ENCODING_RESERVED;
default:
return DVB_ENCODING_RESERVED;
}
}
guint
dvb_analyze_string_charset(tvbuff_t *tvb, int offset, int length, dvb_encoding_e *encoding)
{
if (length >= 1) {
guint8 byte0 = tvb_get_guint8(tvb, offset + 0);
if (byte0 >= 0x20) {
*encoding = DVB_ENCODING_LATIN;
return 0;
} else if (byte0 == 0x1F) {
if (length >= 2) {
*encoding = dvb_analyze_string_charset0_1F(tvb_get_guint8(tvb, offset + 1));
return 2;
}
*encoding = DVB_ENCODING_INVALID;
return 1;
} else if (byte0 >= 0x16) {
*encoding = DVB_ENCODING_RESERVED;
return 1;
} else if (byte0 == 0x10) {
if (length >= 3) {
*encoding = dvb_analyze_string_charset0_10(tvb_get_ntohs(tvb, offset + 1));
return 3;
}
*encoding = DVB_ENCODING_INVALID;
return 1;
} else if ((byte0 >= 0x0C && byte0 <= 0x0F)) {
*encoding = DVB_ENCODING_RESERVED;
return 1;
} else {
*encoding = dvb_analyze_string_charset0(byte0);
return 1;
}
} else
*encoding = DVB_ENCODING_LATIN;
return 0;
}
guint
dvb_enc_to_item_enc(dvb_encoding_e encoding)
{
switch (encoding) {
case DVB_ENCODING_ISO_8859_1:
return ENC_ISO_8859_1 | ENC_NA;
case DVB_ENCODING_ISO_8859_2:
return ENC_ISO_8859_2 | ENC_NA;
case DVB_ENCODING_ISO_8859_3:
return ENC_ISO_8859_3 | ENC_NA;
case DVB_ENCODING_ISO_8859_4:
return ENC_ISO_8859_4 | ENC_NA;
case DVB_ENCODING_ISO_8859_5:
return ENC_ISO_8859_5 | ENC_NA;
case DVB_ENCODING_ISO_8859_6:
return ENC_ISO_8859_6 | ENC_NA;
case DVB_ENCODING_ISO_8859_7:
return ENC_ISO_8859_7 | ENC_NA;
case DVB_ENCODING_ISO_8859_8:
return ENC_ISO_8859_8 | ENC_NA;
case DVB_ENCODING_ISO_8859_9:
return ENC_ISO_8859_9 | ENC_NA;
case DVB_ENCODING_ISO_8859_10:
return ENC_ISO_8859_10 | ENC_NA;
case DVB_ENCODING_ISO_8859_11:
return ENC_ISO_8859_11 | ENC_NA;
case DVB_ENCODING_ISO_8859_13:
return ENC_ISO_8859_13 | ENC_NA;
case DVB_ENCODING_ISO_8859_14:
return ENC_ISO_8859_14 | ENC_NA;
case DVB_ENCODING_ISO_8859_15:
return ENC_ISO_8859_15 | ENC_NA;
case DVB_ENCODING_ISO_10646_UTF8_BMP:
return ENC_UTF_8 | ENC_NA;
default:
return ENC_ASCII | ENC_NA;
}
}
void
dvb_add_chartbl(proto_tree *tree, int hf,
tvbuff_t *tvb, gint offset, gint length, dvb_encoding_e encoding)
{
if (length==0) {
proto_item *pi;
pi = proto_tree_add_text(tree, NULL, 0, 0,
"Default character table (Latin)");
PROTO_ITEM_SET_GENERATED(pi);
}
else {
proto_tree_add_bytes_format_value(tree, hf,
tvb, offset, length, NULL, "%s (%s)",
val_to_str_const(encoding, dvb_string_encoding_vals, "Unknown"),
bytes_to_ep_str_punct(
tvb_get_ptr(tvb, offset, length), length, ' '));
}
}
