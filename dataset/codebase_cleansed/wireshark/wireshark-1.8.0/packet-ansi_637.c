static gboolean
char_is_escape(unsigned char value)
{
return (value == GN_CHAR_ESCAPE);
}
static gunichar
char_def_alphabet_ext_decode(unsigned char value)
{
switch (value)
{
case 0x0a: return 0x0c;
case 0x14: return '^';
case 0x28: return '{';
case 0x29: return '}';
case 0x2f: return '\\';
case 0x3c: return '[';
case 0x3d: return '~';
case 0x3e: return ']';
case 0x40: return '|';
case 0x65: return 0x20ac;
default: return '?';
}
}
static gunichar
char_def_alphabet_decode(unsigned char value)
{
if (value < GN_CHAR_ALPHABET_SIZE)
{
return gsm_default_alphabet[value];
}
else
{
return '?';
}
}
static void
gsm_sms_char_7bit_ascii_decode(unsigned char * dest, const unsigned char* src, int len)
{
int i, j;
gunichar buf;
for (i = 0, j = 0; j < len; j++)
{
if (char_is_escape(src[j])) {
buf = char_def_alphabet_ext_decode(src[++j]);
i += g_unichar_to_utf8(buf,&(dest[i]));
}
else {
buf = char_def_alphabet_decode(src[j]);
i += g_unichar_to_utf8(buf,&(dest[i]));
}
}
dest[i]=0;
return;
}
static int
decode_7_bits(tvbuff_t *tvb, guint32 *offset, guint8 num_fields, guint8 *last_oct, guint8 *last_bit, gchar *buf)
{
guint8 oct, oct2, bit;
guint32 i;
if (num_fields == 0)
{
return 0;
}
oct = oct2 = *last_oct;
bit = *last_bit;
if (bit == 1)
{
oct2 = tvb_get_guint8(tvb, *offset);
(*offset)++;
}
for (i=0; i < num_fields; i++)
{
if (bit != 1)
{
oct = oct2;
if (((i + 1) != num_fields) ||
((bit != 7) && (bit != 8)))
{
oct2 = tvb_get_guint8(tvb, *offset);
(*offset)++;
}
}
switch (bit)
{
case 1:
buf[i] = ((oct & 0x01) << 6) | ((oct2 & 0xfc) >> 2);
break;
case 2:
buf[i] = ((oct & 0x03) << 5) | ((oct2 & 0xf8) >> 3);
break;
case 3:
buf[i] = ((oct & 0x07) << 4) | ((oct2 & 0xf0) >> 4);
break;
case 4:
buf[i] = ((oct & 0x0f) << 3) | ((oct2 & 0xe0) >> 5);
break;
case 5:
buf[i] = ((oct & 0x1f) << 2) | ((oct2 & 0xc0) >> 6);
break;
case 6:
buf[i] = ((oct & 0x3f) << 1) | ((oct2 & 0x80) >> 7);
break;
case 7:
buf[i] = oct & 0x7f;
break;
case 8:
buf[i] = (oct & 0xfe) >> 1;
break;
}
bit = (bit % 8) + 1;
}
buf[i] = '\0';
*last_bit = bit;
*last_oct = (bit == 1) ? oct : oct2;
return i;
}
static void
tele_param_msg_id(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint32 octs;
EXACT_DATA_CHECK(len, 3);
octs = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint(tree, hf_ansi_637_tele_msg_type,
tvb, offset, 3, octs);
proto_tree_add_uint(tree, hf_ansi_637_tele_msg_id,
tvb, offset, 3, octs);
proto_tree_add_uint(tree, hf_ansi_637_tele_msg_rsvd,
tvb, offset, 3, octs);
}
static void
tele_param_msg_status(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
guint8 error_class;
guint8 msg_status_code;
const gchar *str = NULL;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ansi_637_tele_msg_status,tvb, offset, 1, ENC_BIG_ENDIAN);
error_class = ((oct & 0xc0) >> 6);
switch (error_class)
{
case 0x00: str = "No Error";break;
case 0x01: str = "Reserved";break;
case 0x02: str = "Temporary Condition";break;
case 0x03: str = "Permanent Condition";break;
default: str = "Reserved";break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xc0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Erorr Class: %s",
ansi_637_bigbuf,
str);
msg_status_code = (oct & 0x3f);
if (error_class == 0x00){
switch (msg_status_code)
{
case 0x00: str = "Message accepted";break;
case 0x01: str = "Message deposited to internet";break;
case 0x02: str = "Message delivered";break;
case 0x03: str = "Message cancelled";break;
default: str = "Reserved";break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Message status code: %s",
ansi_637_bigbuf,
str);
}
if (error_class == 0x02){
switch (msg_status_code)
{
case 0x04: str = "Network congestion";break;
case 0x05: str = "Network error";break;
case 0x1f: str = "Unknown error";break;
default: str = "Reserved";break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Message status code: %s",
ansi_637_bigbuf,
str);
}
if (error_class == 0x03){
switch (msg_status_code)
{
case 0x04: str = "Network congestion";break;
case 0x05: str = "Network error";break;
case 0x06: str = "Cancel failed";break;
case 0x07: str = "Blocked destination";break;
case 0x08: str = "Text too long";break;
case 0x09: str = "Duplicate message";break;
case 0x0a: str = "Invalid destination";break;
case 0x0d: str = "Message expired";break;
case 0x1f: str = "Unknown error";break;
default: str = "Reserved";break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Message status code: %s",
ansi_637_bigbuf,
str);
}
}
static void
tele_param_user_data(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, oct2;
guint8 encoding;
guint8 msg_type;
guint8 num_fields;
guint8 used;
guint8 bit;
guint32 required_octs;
guint32 saved_offset;
guint32 i , out_len;
const gchar *str = NULL;
gchar *utf8_text = NULL;
GIConv cd;
GError *l_conv_error = NULL;
SHORT_DATA_CHECK(len, 2);
oct = tvb_get_guint8(tvb, offset);
oct2 = 0;
msg_type = 0;
used = 0;
encoding = ((oct & 0xf8) >> 3);
switch (encoding)
{
case 0x00: str = "Octet, unspecified"; break;
case 0x01: str = "Extended Protocol Message";
oct2 = tvb_get_guint8(tvb, offset+1);
msg_type = ((oct & 0x07) << 5) | ((oct2 & 0xf8) >> 3);
break;
case 0x02: str = "7-bit ASCII"; break;
case 0x03: str = "IA5"; break;
case 0x04: str = "UNICODE"; break;
case 0x05: str = "Shift-JIS"; break;
case 0x06: str = "Korean"; break;
case 0x07: str = "Latin/Hebrew"; break;
case 0x08: str = "Latin"; break;
case 0x09: str = "GSM 7-bit default alphabet"; break;
default: str = "Reserved"; break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xf8, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Encoding: %s",
ansi_637_bigbuf,
str);
if (encoding == 0x01)
{
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x07, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Message type: see TIA/EIA/IS-91 (%d)",
ansi_637_bigbuf,
msg_type);
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0xf8, 8);
proto_tree_add_text(tree, tvb, offset+1, 1,
"%s : Message type",
ansi_637_bigbuf);
oct = oct2;
offset++;
used++;
}
offset++;
used++;
oct2 = tvb_get_guint8(tvb, offset);
num_fields = ((oct & 0x07) << 5) | ((oct2 & 0xf8) >> 3);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x07, 8);
proto_tree_add_text(tree, tvb, offset-1, 1,
"%s : Number of fields (MSB): %d",
ansi_637_bigbuf,
num_fields);
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0xf8, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Number of fields (LSB)",
ansi_637_bigbuf);
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0x07, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Most significant bits of first field",
ansi_637_bigbuf);
offset++;
used++;
oct = oct2;
if (len <= used) return;
if (encoding == 0x02)
{
i = (num_fields * 7) - 3;
required_octs = (i / 8) + ((i % 8) ? 1 : 0);
if (required_octs + used > len)
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(required_octs + used) - len);
return;
}
bit = 3;
saved_offset = offset;
decode_7_bits(tvb, &offset, num_fields, &oct, &bit, ansi_637_bigbuf);
proto_tree_add_text(tree, tvb, saved_offset, offset - saved_offset,
"Encoded user data: %s",
ansi_637_bigbuf);
switch (bit)
{
case 1: oct2 = 0x01; break;
case 2: oct2 = 0x03; break;
case 3: oct2 = 0x07; break;
case 4: oct2 = 0x0f; break;
case 5: oct2 = 0x1f; break;
case 6: oct2 = 0x3f; break;
case 7: oct2 = 0x7f; break;
}
if (bit != 8)
{
other_decode_bitfield_value(ansi_637_bigbuf, oct, oct2, 8);
proto_tree_add_text(tree, tvb, offset - 1, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
}
else if (encoding == 0x03)
{
i = (num_fields * 7) - 3;
required_octs = (i / 8) + ((i % 8) ? 1 : 0);
if (required_octs + used > len)
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(required_octs + used) - len);
return;
}
bit = 3;
saved_offset = offset;
out_len = decode_7_bits(tvb, &offset, num_fields, &oct, &bit, ansi_637_bigbuf);
IA5_7BIT_decode(ia5_637_bigbuf, ansi_637_bigbuf, out_len);
proto_tree_add_text(tree, tvb, saved_offset, offset - saved_offset,
"Encoded user data: %s",
ia5_637_bigbuf);
}
else if (encoding == 0x07)
{
saved_offset = offset - 1;
for (i=0; i < num_fields; i++)
{
oct = tvb_get_guint8(tvb, saved_offset);
oct2 = tvb_get_guint8(tvb, saved_offset + 1);
ansi_637_bigbuf[i] = ((oct & 0x07) << 5) | ((oct2 & 0xf8) >> 3);
saved_offset++;
}
if ((cd = g_iconv_open("UTF-8","iso-8859-8")) != (GIConv)-1)
{
utf8_text = g_convert_with_iconv(tvb_get_ptr(tvb, offset, num_fields), num_fields , cd , NULL , NULL , &l_conv_error);
if(!l_conv_error)
{
proto_tree_add_text(tree, tvb, offset, num_fields, "Encoded user data: %s", utf8_text);
}
else
{
proto_tree_add_text(tree, tvb, offset, num_fields, "%s", "Failed on iso-8859-8 contact Wireshark developers");
}
if(utf8_text)
g_free(utf8_text);
g_iconv_close(cd);
}
}
else if (encoding == 0x08)
{
saved_offset = offset - 1;
for (i=0; i < num_fields; i++)
{
oct = tvb_get_guint8(tvb, saved_offset);
oct2 = tvb_get_guint8(tvb, saved_offset + 1);
ansi_637_bigbuf[i] = ((oct & 0x07) << 5) | ((oct2 & 0xf8) >> 3);
saved_offset++;
}
if ((cd = g_iconv_open("UTF-8","iso-8859-1")) != (GIConv)-1)
{
utf8_text = g_convert_with_iconv(ansi_637_bigbuf , num_fields , cd , NULL , NULL , &l_conv_error);
if(!l_conv_error)
{
proto_tree_add_text(tree, tvb, offset, num_fields, "Encoded user data: %s", utf8_text);
}
else
{
proto_tree_add_text(tree, tvb, offset, num_fields, "%s", "Failed on iso-8859-1 contact Wireshark developers");
}
if(utf8_text)
g_free(utf8_text);
g_iconv_close(cd);
}
}
else if (encoding == 0x09)
{
i = (num_fields * 7) - 3;
required_octs = (i / 8) + ((i % 8) ? 1 : 0);
if (required_octs + used > len)
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(required_octs + used) - len);
return;
}
bit = 3;
saved_offset = offset;
out_len = decode_7_bits(tvb, &offset, num_fields, &oct, &bit, ansi_637_bigbuf);
gsm_sms_char_7bit_ascii_decode(gsm_637_bigbuf, ansi_637_bigbuf, out_len);
proto_tree_add_text(tree, tvb, saved_offset, offset - saved_offset,
"Encoded user data: %s",
gsm_637_bigbuf);
}
else
{
proto_tree_add_text(tree, tvb, offset, len - used,
"Encoded user data");
}
}
static void
tele_param_rsp_code(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Response code: %d",
oct);
}
static void
tele_param_timestamp(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, oct2, oct3;
EXACT_DATA_CHECK(len, 6);
oct = tvb_get_guint8(tvb, offset);
oct2 = tvb_get_guint8(tvb, offset+1);
oct3 = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset, 3,
"Year %d%d, Month %d%d, Day %d%d",
(oct & 0xf0) >> 4,
oct & 0x0f,
(oct2 & 0xf0) >> 4,
oct2 & 0x0f,
(oct3 & 0xf0) >> 4,
oct3 & 0x0f);
offset += 3;
oct = tvb_get_guint8(tvb, offset);
oct2 = tvb_get_guint8(tvb, offset+1);
oct3 = tvb_get_guint8(tvb, offset+2);
proto_tree_add_text(tree, tvb, offset, 3,
"Hour %d%d, Minutes %d%d, Seconds %d%d",
(oct & 0xf0) >> 4,
oct & 0x0f,
(oct2 & 0xf0) >> 4,
oct2 & 0x0f,
(oct3 & 0xf0) >> 4,
oct3 & 0x0f);
}
static void
tele_param_rel_timestamp(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
guint32 value = 0;
const gchar *str = NULL;
const gchar *str2 = NULL;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
switch (oct)
{
case 245: str = "Indefinite"; break;
case 246: str = "Immediate"; break;
case 247: str = "Valid until mobile becomes inactive/Deliver when mobile next becomes active"; break;
case 248: str = "Valid until registration area changes, discard if not registered" ; break;
default:
if (oct <= 143) { value = (oct + 1) * 5; str2 = "Minutes"; break; }
else if ((oct >= 144) && (oct <= 167)) { value = (oct - 143) * 30; str2 = "Minutes + 12 Hours"; break; }
else if ((oct >= 168) && (oct <= 196)) { value = oct - 166; str2 = "Days"; break; }
else if ((oct >= 197) && (oct <= 244)) { value = oct - 192; str2 = "Weeks"; break; }
else { str = "Reserved"; break; }
}
if (str == NULL)
{
proto_tree_add_text(tree, tvb, offset, 1,
"%s", str2);
}
else
{
proto_tree_add_text(tree, tvb, offset, 1,
"%d %s",
value, str2);
}
}
static void
tele_param_pri_ind(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
const gchar *str = NULL;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
str=val_to_str((oct&0xc0)>>6, tele_param_pri_ind_strings, "Unknown");
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xc0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : %s",
ansi_637_bigbuf,
str);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
static void
tele_param_priv_ind(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
const gchar *str = NULL;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
switch ((oct & 0xc0) >> 6)
{
case 0: str = "Not restricted (privacy level 0)"; break;
case 1: str = "Restricted (privacy level 1)"; break;
case 2: str = "Confidential (privacy level 2)"; break;
case 3: str = "Secret (privacy level 3)"; break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xc0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : %s",
ansi_637_bigbuf,
str);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
static void
tele_param_reply_opt(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x80, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : %s (manual) acknowledgment is requested",
ansi_637_bigbuf,
(oct & 0x80) ? "User" : "No user");
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x40, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : %s acknowledgment requested",
ansi_637_bigbuf,
(oct & 0x40) ? "Delivery" : "No delivery");
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
static void
tele_param_num_messages(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Number of voice mail messages: %d%d",
(oct & 0xf0) >> 4,
oct & 0x0f);
}
static void
tele_param_alert(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
const gchar *str = NULL;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
switch ((oct & 0xc0) >> 6)
{
case 0: str = "Use Mobile default alert"; break;
case 1: str = "Use Low-priority alert"; break;
case 2: str = "Use Medium-priority alert"; break;
case 3: str = "Use High-priority alert"; break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xc0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : %s",
ansi_637_bigbuf,
str);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
static void
tele_param_lang_ind(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
const gchar *str = NULL;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
switch (oct)
{
case 0x00: str = "Unknown or unspecified"; break;
case 0x01: str = "English"; break;
case 0x02: str = "French"; break;
case 0x03: str = "Spanish"; break;
case 0x04: str = "Japanese"; break;
case 0x05: str = "Korean"; break;
case 0x06: str = "Chinese"; break;
case 0x07: str = "Hebrew"; break;
default: str = "Reserved"; break;
}
proto_tree_add_text(tree, tvb, offset, 1,
"%s", str);
}
static void
tele_param_cb_num(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct, oct2, num_fields, odd;
guint32 saved_offset;
guint32 required_octs;
guint32 i;
SHORT_DATA_CHECK(len, 2);
oct = tvb_get_guint8(tvb, offset);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x80, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Digit mode: %s",
ansi_637_bigbuf,
(oct & 0x80) ? "8-bit ASCII" : "4-bit DTMF");
if (oct & 0x80)
{
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x70, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Type of number: (%d)",
ansi_637_bigbuf,
(oct & 0x70) >> 4);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Numbering plan: (%d)",
ansi_637_bigbuf,
oct & 0x0f);
offset++;
num_fields = tvb_get_guint8(tvb, offset);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xff, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Number of fields: (%d)",
ansi_637_bigbuf,
num_fields);
if (num_fields == 0) return;
if (num_fields > (len - 2))
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(num_fields + 2) - len);
return;
}
offset++;
i = 0;
while (i < num_fields)
{
ansi_637_bigbuf[i] = tvb_get_guint8(tvb, offset+i) & 0x7f;
i++;
}
ansi_637_bigbuf[i] = '\0';
proto_tree_add_text(tree, tvb, offset, num_fields,
"Number: %s",
ansi_637_bigbuf);
}
else
{
offset++;
num_fields = (oct & 0x7f) << 1;
oct2 = tvb_get_guint8(tvb, offset);
num_fields |= ((oct2 & 0x80) >> 7);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x7f, 8);
proto_tree_add_text(tree, tvb, offset-1, 1,
"%s : Number of fields (MBS): (%d)",
ansi_637_bigbuf,
num_fields);
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0x80, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Number of fields (LSB)",
ansi_637_bigbuf);
oct = oct2;
odd = FALSE;
if (num_fields > 0)
{
i = (num_fields - 1) * 4;
required_octs = (i / 8) + ((i % 8) ? 1 : 0);
if (required_octs + 2 > len)
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(required_octs + 2) - len);
return;
}
odd = num_fields & 0x01;
memset((void *) ansi_637_bigbuf, 0, sizeof(ansi_637_bigbuf));
saved_offset = offset;
offset++;
i = 0;
while (i < num_fields)
{
ansi_637_bigbuf[i] =
air_digits[(oct & 0x78) >> 3];
i++;
if (i >= num_fields) break;
oct2 = tvb_get_guint8(tvb, offset);
offset++;
ansi_637_bigbuf[i] =
air_digits[((oct & 0x07) << 1) | ((oct2 & 0x80) >> 7)];
oct = oct2;
i++;
}
proto_tree_add_text(tree, tvb, saved_offset, offset - saved_offset,
"Number: %s",
ansi_637_bigbuf);
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, odd ? 0x07: 0x7f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
}
static void
tele_param_disp_mode(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset)
{
guint8 oct;
const gchar *str = NULL;
EXACT_DATA_CHECK(len, 1);
oct = tvb_get_guint8(tvb, offset);
switch ((oct & 0xc0) >> 6)
{
case 0: str = "Immediate Display: The mobile station is to display the received message as soon as possible."; break;
case 1: str = "Mobile default setting: The mobile station is to display the received message based on a pre-defined mode in the mobile station."; break;
case 2: str = "User Invoke: The mobile station is to display the received message based on the mode selected by the user."; break;
case 3: str = "Reserved"; break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xc0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : %s",
ansi_637_bigbuf,
str);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
static void
trans_param_tele_id(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset, gchar *add_string, int string_len)
{
guint32 value;
const gchar *str = NULL;
EXACT_DATA_CHECK(len, 2);
value = tvb_get_ntohs(tvb, offset);
ansi_637_trans_tele_id = value;
str = match_strval(value, ansi_tele_id_strings);
if (NULL == str)
{
switch (value)
{
case 1:
str = "Reserved for maintenance";
break;
case 4102:
str = "CDMA Service Category Programming Teleservice (SCPT)";
break;
case 4103:
str = "CDMA Card Application Toolkit Protocol Teleservice (CATPT)";
break;
case 32513:
str = "TDMA Cellular Messaging Teleservice";
break;
case 32514:
str = "TDMA Cellular Paging Teleservice (CPT-136)";
break;
case 32515:
str = "TDMA Over-the-Air Activation Teleservice (OATS)";
break;
case 32520:
str = "TDMA System Assisted Mobile Positioning through Satellite (SAMPS)";
break;
case 32584:
str = "TDMA Segmented System Assisted Mobile Positioning Service";
break;
default:
if ((value >= 2) && (value <= 4095))
{
str = "Reserved for assignment by TIA-41";
}
else if ((value >= 4104) && (value <= 4113))
{
str = "Reserved for GSM1x Teleservice (CDMA)";
}
else if ((value >= 4114) && (value <= 32512))
{
str = "Reserved for assignment by TIA-41";
}
else if ((value >= 32521) && (value <= 32575))
{
str = "Reserved for assignment by this Standard for TDMA MS-based SMEs";
}
else if ((value >= 49152) && (value <= 65535))
{
str = "Reserved for carrier specific teleservices";
}
else
{
str = "Unrecognized Teleservice ID";
}
break;
}
}
proto_tree_add_text(tree, tvb, offset, 2,
"%s (%d)",
str,
value);
g_snprintf(add_string, string_len, " - %s (%d)", str, value);
}
static void
trans_param_srvc_cat(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset, gchar *add_string, int string_len)
{
guint32 value;
const gchar *str = NULL;
EXACT_DATA_CHECK(len, 2);
value = tvb_get_ntohs(tvb, offset);
str = val_to_str_const(value, ansi_srvc_cat_strings, "Reserved");
proto_tree_add_text(tree, tvb, offset, 2,
"%s", str);
g_snprintf(add_string, string_len, " - %s (%d)", str, value);
}
static void
trans_param_address(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset, gchar *add_string _U_, int string_len _U_)
{
guint8 oct, oct2, num_fields, odd;
gboolean email_addr;
guint32 saved_offset;
guint32 required_octs;
guint32 i;
const gchar *str;
SHORT_DATA_CHECK(len, 2);
email_addr = FALSE;
oct = tvb_get_guint8(tvb, offset);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x80, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Digit mode: %s",
ansi_637_bigbuf,
(oct & 0x80) ? "8-bit ASCII" : "4-bit DTMF");
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x40, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Number mode: %s",
ansi_637_bigbuf,
(oct & 0x40) ? "Data Network Address" : "ANSI T1.607");
if (oct & 0x80)
{
if (oct & 0x40)
{
switch ((oct & 0x38) >> 3)
{
case 0: str = "Unknown"; break;
case 1: str = "Internet Protocol (RFC 791)"; break;
case 2: str = "Internet Email Address (RFC 822)"; email_addr = TRUE; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x38, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Type of number: %s (%d)",
ansi_637_bigbuf,
str,
(oct & 0x38) >> 3);
offset++;
num_fields = (oct & 0x07) << 5;
oct2 = tvb_get_guint8(tvb, offset);
num_fields |= ((oct2 & 0xf8) >> 3);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x07, 8);
proto_tree_add_text(tree, tvb, offset-1, 1,
"%s : Number of fields (MSB): (%d)",
ansi_637_bigbuf,
num_fields);
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0xf8, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Number of fields (LSB)",
ansi_637_bigbuf);
if (num_fields == 0) return;
if (num_fields > (len - 2))
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(num_fields + 2) - len);
return;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0x07, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Most significant bits of first field",
ansi_637_bigbuf);
offset++;
oct = oct2;
i = 0;
while (i < num_fields)
{
ansi_637_bigbuf[i] = (oct & 0x07) << 5;
ansi_637_bigbuf[i] |= ((oct = tvb_get_guint8(tvb, offset+i)) & 0xf8) >> 3;
i++;
}
ansi_637_bigbuf[i] = '\0';
if (email_addr)
{
proto_tree_add_text(tree, tvb, offset, num_fields - 1,
"Number: %s",
ansi_637_bigbuf);
}
else
{
proto_tree_add_bytes(tree, hf_ansi_637_trans_bin_addr, tvb, offset, num_fields - 1,
(guint8*)ansi_637_bigbuf);
}
offset += (num_fields - 1);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xf8, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Least significant bits of last field",
ansi_637_bigbuf);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x07, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
else
{
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x38, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Type of number: (%d)",
ansi_637_bigbuf,
(oct & 0x38) >> 3);
oct2 = tvb_get_guint8(tvb, offset + 1);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x07, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Numbering plan (MSB): (%d)",
ansi_637_bigbuf,
((oct & 0x07) << 1) | ((oct2 & 0x80) >> 7));
offset++;
oct = oct2;
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x80, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Numbering plan (LSB)",
ansi_637_bigbuf);
offset++;
num_fields = (oct & 0x7f) << 1;
oct2 = tvb_get_guint8(tvb, offset);
num_fields |= ((oct2 & 0x80) >> 7);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x7f, 8);
proto_tree_add_text(tree, tvb, offset-1, 1,
"%s : Number of fields (MSB): (%d)",
ansi_637_bigbuf,
num_fields);
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0x80, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Number of fields (LSB)",
ansi_637_bigbuf);
if (num_fields == 0) return;
if (num_fields > (len - 3))
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(num_fields + 3) - len);
return;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0x7f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Most significant bits of first field",
ansi_637_bigbuf);
offset++;
oct = oct2;
i = 0;
while (i < num_fields)
{
ansi_637_bigbuf[i] = (oct & 0x7f) << 1;
ansi_637_bigbuf[i] |= ((oct = tvb_get_guint8(tvb, offset+i)) & 0x80) >> 7;
i++;
}
ansi_637_bigbuf[i] = '\0';
proto_tree_add_text(tree, tvb, offset, num_fields - 1,
"Number: %s",
ansi_637_bigbuf);
offset += (num_fields - 1);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x80, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Least significant bit of last field",
ansi_637_bigbuf);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x7f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
}
else
{
offset++;
num_fields = (oct & 0x3f) << 2;
oct2 = tvb_get_guint8(tvb, offset);
num_fields |= ((oct2 & 0xc0) >> 6);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x3f, 8);
proto_tree_add_text(tree, tvb, offset-1, 1,
"%s : Number of fields (MSB): (%d)",
ansi_637_bigbuf,
num_fields);
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0xc0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Number of fields (LSB)",
ansi_637_bigbuf);
oct = oct2;
odd = FALSE;
if (num_fields > 0)
{
i = (num_fields - 1) * 4;
required_octs = (i / 8) + ((i % 8) ? 1 : 0);
if (required_octs + 2 > len)
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(required_octs + 2) - len);
return;
}
odd = num_fields & 0x01;
memset((void *) ansi_637_bigbuf, 0, sizeof(ansi_637_bigbuf));
saved_offset = offset;
offset++;
i = 0;
while (i < num_fields)
{
ansi_637_bigbuf[i] =
air_digits[(oct & 0x3c) >> 2];
i++;
if (i >= num_fields) break;
oct2 = tvb_get_guint8(tvb, offset);
offset++;
ansi_637_bigbuf[i] =
air_digits[((oct & 0x03) << 2) | ((oct2 & 0xc0) >> 6)];
oct = oct2;
i++;
}
proto_tree_add_text(tree, tvb, saved_offset, offset - saved_offset,
"Number: %s",
ansi_637_bigbuf);
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, odd ? 0x03: 0x3f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
}
static void
trans_param_subaddress(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset, gchar *add_string _U_, int string_len _U_)
{
guint8 oct, oct2, num_fields;
guint32 i;
const gchar *str;
SHORT_DATA_CHECK(len, 2);
oct = tvb_get_guint8(tvb, offset);
switch ((oct & 0xe0) >> 5)
{
case 0: str = "NSAP (CCITT Recommendation X.213 or ISO 8348 AD2)"; break;
case 1: str = "User-specified"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xe0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Type: %s",
ansi_637_bigbuf,
str);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x10, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Odd",
ansi_637_bigbuf);
offset++;
num_fields = (oct & 0x0f) << 4;
oct2 = tvb_get_guint8(tvb, offset);
num_fields |= ((oct2 & 0xf0) >> 4);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(tree, tvb, offset-1, 1,
"%s : Number of fields (MSB): (%d)",
ansi_637_bigbuf,
num_fields);
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0xf0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Number of fields (LSB)",
ansi_637_bigbuf);
if (num_fields == 0) return;
if (num_fields > (len - 2))
{
proto_tree_add_text(tree, tvb, offset, 1,
"Missing %d octet(s) for number of fields",
(num_fields + 2) - len);
return;
}
other_decode_bitfield_value(ansi_637_bigbuf, oct2, 0x0f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Most significant bits of first field",
ansi_637_bigbuf);
offset++;
oct = oct2;
i = 0;
while (i < num_fields)
{
ansi_637_bigbuf[i] = (oct & 0x0f) << 4;
ansi_637_bigbuf[i] |= ((oct = tvb_get_guint8(tvb, offset+i)) & 0xf0) >> 4;
i++;
}
ansi_637_bigbuf[i] = '\0';
proto_tree_add_bytes(tree, hf_ansi_637_trans_bin_addr, tvb, offset, num_fields - 1,
(guint8*)ansi_637_bigbuf);
offset += (num_fields - 1);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xf0, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Least significant bits of last field",
ansi_637_bigbuf);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
static void
trans_param_bearer_reply_opt(tvbuff_t *tvb, proto_tree *tree, guint len _U_, guint32 offset, gchar *add_string, int string_len)
{
guint8 oct;
oct = tvb_get_guint8(tvb, offset);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xfc, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reply Sequence Number: %d",
ansi_637_bigbuf,
(oct & 0xfc) >> 2);
g_snprintf(add_string, string_len, " - Reply Sequence Number (%d)", (oct & 0xfc) >> 2);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x03, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reserved",
ansi_637_bigbuf);
}
static void
trans_param_cause_codes(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset, gchar *add_string, int string_len)
{
guint8 oct;
const gchar *str = NULL;
oct = tvb_get_guint8(tvb, offset);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0xfc, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Reply Sequence Number: %d",
ansi_637_bigbuf,
(oct & 0xfc) >> 2);
switch (oct & 0x03)
{
case 0x00: str = "No error"; break;
case 0x02: str = "Temporary Condition"; break;
case 0x03: str = "Permanent Condition"; break;
default:
str = "Reserved";
break;
}
g_snprintf(add_string, string_len, " - Reply Sequence Number (%d)", (oct & 0xfc) >> 2);
other_decode_bitfield_value(ansi_637_bigbuf, oct, 0x03, 8);
proto_tree_add_text(tree, tvb, offset, 1,
"%s : Error Class: %s",
ansi_637_bigbuf,
str);
offset++;
if (!(oct & 0x03)) return;
if (len == 1) return;
oct = tvb_get_guint8(tvb, offset);
switch (oct)
{
case 0: str = "Address vacant"; break;
case 1: str = "Address translation failure"; break;
case 2: str = "Network resource shortage"; break;
case 3: str = "Network failure"; break;
case 4: str = "Invalid Teleservice ID"; break;
case 5: str = "Other network problem"; break;
case 6: str = "Unsupported network interface"; break;
case 32: str = "No page response"; break;
case 33: str = "Destination busy"; break;
case 34: str = "No acknowledgement"; break;
case 35: str = "Destination resource shortage"; break;
case 36: str = "SMS delivery postponed"; break;
case 37: str = "Destination out of service"; break;
case 38: str = "Destination no longer at this address"; break;
case 39: str = "Other terminal problem"; break;
case 64: str = "Radio interface resource shortage"; break;
case 65: str = "Radio interface incompatibility"; break;
case 66: str = "Other radio interface problem"; break;
case 67: str = "Unsupported Base Station Capability"; break;
case 96: str = "Encoding problem"; break;
case 97: str = "Service origination denied"; break;
case 98: str = "Service termination denied"; break;
case 99: str = "Supplementary service not supported"; break;
case 100: str = "Service not supported"; break;
case 101: str = "Reserved"; break;
case 102: str = "Missing expected parameter"; break;
case 103: str = "Missing mandatory parameter"; break;
case 104: str = "Unrecognized parameter value"; break;
case 105: str = "Unexpected parameter value"; break;
case 106: str = "User Data size error"; break;
case 107: str = "Other general problems"; break;
case 108: str = "Session not active"; break;
default:
if ((oct >= 7) && (oct <= 31)) { str = "Reserved, treat as Other network problem"; }
else if ((oct >= 40) && (oct <= 47)) { str = "Reserved, treat as Other terminal problem"; }
else if ((oct >= 48) && (oct <= 63)) { str = "Reserved, treat as SMS delivery postponed"; }
else if ((oct >= 68) && (oct <= 95)) { str = "Reserved, treat as Other radio interface problem"; }
else if ((oct >= 109) && (oct <= 223)) { str = "Reserved, treat as Other general problems"; }
else { str = "Reserved for protocol extension, treat as Other general problems"; }
break;
}
proto_tree_add_text(tree, tvb, offset, 1,
"%s", str);
}
static void
trans_param_bearer_data(tvbuff_t *tvb, proto_tree *tree, guint len, guint32 offset, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *tele_tvb;
proto_tree_add_text(tree, tvb, offset, len,
"Bearer Data");
tele_tvb = tvb_new_subset(tvb, offset, len, len);
dissector_try_uint(tele_dissector_table, ansi_637_trans_tele_id,
tele_tvb, g_pinfo, g_tree);
}
static gboolean
dissect_ansi_637_tele_param(tvbuff_t *tvb, proto_tree *tree, guint32 *offset)
{
void (*param_fcn)(tvbuff_t *, proto_tree *, guint, guint32) = NULL;
guint8 oct;
guint8 len;
guint32 curr_offset;
gint ett_param_idx, idx;
proto_tree *subtree;
proto_item *item;
const gchar *str = NULL;
curr_offset = *offset;
oct = tvb_get_guint8(tvb, curr_offset);
str = match_strval_idx((guint32) oct, ansi_tele_param_strings, &idx);
if (NULL == str)
{
return(FALSE);
}
ett_param_idx = ett_ansi_637_tele_param[idx];
param_fcn = ansi_637_tele_param_fcn[idx];
item =
proto_tree_add_text(tree, tvb, curr_offset, -1, "%s", str);
subtree = proto_item_add_subtree(item, ett_param_idx);
proto_tree_add_uint(subtree, hf_ansi_637_tele_subparam_id,
tvb, curr_offset, 1, oct);
curr_offset++;
len = tvb_get_guint8(tvb, curr_offset);
proto_item_set_len(item, (curr_offset - *offset) + len + 1);
proto_tree_add_uint(subtree, hf_ansi_637_tele_length,
tvb, curr_offset, 1, len);
curr_offset++;
if (len > 0)
{
if (param_fcn == NULL)
{
proto_tree_add_text(subtree, tvb, curr_offset,
len, "Parameter Data");
}
else
{
(*param_fcn)(tvb, subtree, len, curr_offset);
}
curr_offset += len;
}
*offset = curr_offset;
return(TRUE);
}
static void
dissect_ansi_637_tele_message(tvbuff_t *tvb, proto_tree *ansi_637_tree)
{
guint8 len;
guint32 curr_offset;
curr_offset = 0;
len = tvb_length(tvb);
while ((len - curr_offset) > 0)
{
if (!dissect_ansi_637_tele_param(tvb, ansi_637_tree, &curr_offset))
{
proto_tree_add_text(ansi_637_tree, tvb, curr_offset, len - curr_offset,
"Unknown Parameter Data");
break;
}
}
}
static void
dissect_ansi_637_tele(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ansi_637_item;
proto_tree *ansi_637_tree = NULL;
const gchar *str = NULL;
guint32 value;
col_set_str(pinfo->cinfo, COL_PROTOCOL, ansi_proto_name_short);
if (tree)
{
value = pinfo->match_uint;
str = match_strval(value, ansi_tele_id_strings);
if (NULL == str)
{
switch (value)
{
case 1:
str = "Reserved for maintenance";
break;
case 4102:
str = "CDMA Service Category Programming Teleservice (SCPT)";
break;
case 4103:
str = "CDMA Card Application Toolkit Protocol Teleservice (CATPT)";
break;
case 32513:
str = "TDMA Cellular Messaging Teleservice";
break;
case 32514:
str = "TDMA Cellular Paging Teleservice (CPT-136)";
break;
case 32515:
str = "TDMA Over-the-Air Activation Teleservice (OATS)";
break;
case 32520:
str = "TDMA System Assisted Mobile Positioning through Satellite (SAMPS)";
break;
case 32584:
str = "TDMA Segmented System Assisted Mobile Positioning Service";
break;
default:
if ((value >= 2) && (value <= 4095))
{
str = "Reserved for assignment by TIA-41";
}
else if ((value >= 4104) && (value <= 4113))
{
str = "Reserved for GSM1x Teleservice (CDMA)";
}
else if ((value >= 4114) && (value <= 32512))
{
str = "Reserved for assignment by TIA-41";
}
else if ((value >= 32521) && (value <= 32575))
{
str = "Reserved for assignment by this Standard for TDMA MS-based SMEs";
}
else if ((value >= 49152) && (value < 65535))
{
str = "Reserved for carrier specific teleservices";
}
else if (value == 65535)
{
str = "(Reserved) Being used for Broadcast";
}
else
{
str = "Unrecognized Teleservice ID";
}
break;
}
}
ansi_637_item =
proto_tree_add_protocol_format(tree, proto_ansi_637_tele, tvb, 0, -1,
"%s - %s (%d)",
ansi_proto_name_tele,
str,
pinfo->match_uint);
ansi_637_tree =
proto_item_add_subtree(ansi_637_item, ett_ansi_637_tele);
dissect_ansi_637_tele_message(tvb, ansi_637_tree);
}
}
static gboolean
dissect_ansi_637_trans_param(tvbuff_t *tvb, proto_tree *tree, guint32 *offset)
{
void (*param_fcn)(tvbuff_t *, proto_tree *, guint, guint32, gchar *, int) = NULL;
guint8 oct;
guint8 len;
guint32 curr_offset;
gint ett_param_idx, idx;
proto_tree *subtree;
proto_item *item;
const gchar *str = NULL;
curr_offset = *offset;
oct = tvb_get_guint8(tvb, curr_offset);
str = match_strval_idx((guint32) oct, ansi_trans_param_strings, &idx);
if (NULL == str)
{
return(FALSE);
}
ett_param_idx = ett_ansi_637_trans_param[idx];
param_fcn = ansi_637_trans_param_fcn[idx];
item =
proto_tree_add_text(tree, tvb, curr_offset, -1, "%s", str);
subtree = proto_item_add_subtree(item, ett_param_idx);
proto_tree_add_uint(subtree, hf_ansi_637_trans_param_id,
tvb, curr_offset, 1, oct);
curr_offset++;
len = tvb_get_guint8(tvb, curr_offset);
proto_item_set_len(item, (curr_offset - *offset) + len + 1);
proto_tree_add_uint(subtree, hf_ansi_637_trans_length,
tvb, curr_offset, 1, len);
curr_offset++;
if (len > 0)
{
if (param_fcn == NULL)
{
proto_tree_add_text(subtree, tvb, curr_offset,
len, "Parameter Data");
}
else
{
gchar *ansi_637_add_string;
ansi_637_add_string = ep_alloc(1024);
ansi_637_add_string[0] = '\0';
(*param_fcn)(tvb, subtree, len, curr_offset, ansi_637_add_string, 1024);
if (ansi_637_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", ansi_637_add_string);
}
}
curr_offset += len;
}
*offset = curr_offset;
return(TRUE);
}
static void
dissect_ansi_637_trans(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ansi_637_item;
proto_tree *ansi_637_tree = NULL;
guint32 curr_offset;
gint idx;
const gchar *str = NULL;
guint8 oct;
guint8 len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, ansi_proto_name_short);
if (tree)
{
g_pinfo = pinfo;
g_tree = tree;
ansi_637_trans_tele_id = 0;
oct = tvb_get_guint8(tvb, 0);
str = match_strval_idx(oct, ansi_trans_msg_type_strings, &idx);
if (NULL == str)
{
ansi_637_item =
proto_tree_add_protocol_format(tree, proto_ansi_637_trans, tvb, 0, -1,
"%s - Unrecognized Transport Layer Message Type (%d)",
ansi_proto_name_trans,
oct);
ansi_637_tree =
proto_item_add_subtree(ansi_637_item, ett_ansi_637_trans);
}
else
{
ansi_637_item =
proto_tree_add_protocol_format(tree, proto_ansi_637_trans, tvb, 0, -1,
"%s - %s",
ansi_proto_name_trans,
str);
ansi_637_tree =
proto_item_add_subtree(ansi_637_item, ett_ansi_637_trans_msg[idx]);
if (oct == ANSI_TRANS_MSG_TYPE_BROADCAST)
{
ansi_637_trans_tele_id = 65535;
}
}
curr_offset = 1;
len = tvb_length(tvb);
while ((len - curr_offset) > 0)
{
if (!dissect_ansi_637_trans_param(tvb, ansi_637_tree, &curr_offset))
{
proto_tree_add_text(ansi_637_tree, tvb, curr_offset, len - curr_offset,
"Unknown Parameter Data");
break;
}
}
}
}
static void
dissect_ansi_637_trans_app(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL,"/");
col_set_fence(pinfo->cinfo, COL_INFO);
dissect_ansi_637_trans(tvb, pinfo, tree);
}
void
proto_register_ansi_637(void)
{
guint i;
static hf_register_info hf_trans[] =
{
{ &hf_ansi_637_trans_msg_type,
{ "Message Type",
"ansi_637_trans.msg_type",
FT_UINT24, BASE_DEC, VALS(ansi_trans_msg_type_strings), 0xf00000,
NULL, HFILL }},
{ &hf_ansi_637_trans_param_id,
{ "Transport Param ID", "ansi_637_trans.param_id",
FT_UINT8, BASE_DEC, VALS(ansi_trans_param_strings), 0,
NULL, HFILL }},
{ &hf_ansi_637_trans_length,
{ "Length", "ansi_637_trans.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_637_trans_bin_addr,
{ "Binary Address", "ansi_637_trans.bin_addr",
FT_BYTES, BASE_NONE, 0, 0,
NULL, HFILL }},
};
static hf_register_info hf_tele[] =
{
{ &hf_ansi_637_tele_msg_type,
{ "Message Type",
"ansi_637_tele.msg_type",
FT_UINT24, BASE_DEC, VALS(ansi_tele_msg_type_strings), 0xf00000,
NULL, HFILL }},
{ &hf_ansi_637_tele_msg_id,
{ "Message ID",
"ansi_637_tele.msg_id",
FT_UINT24, BASE_DEC, NULL, 0x0ffff0,
NULL, HFILL }},
{ &hf_ansi_637_tele_msg_status,
{ "Message Status",
"ansi_637_tele.msg_status",
FT_UINT8, BASE_DEC, VALS(ansi_tele_msg_status_strings), 0,
NULL, HFILL }},
{ &hf_ansi_637_tele_msg_rsvd,
{ "Reserved",
"ansi_637_tele.msg_rsvd",
FT_UINT24, BASE_DEC, NULL, 0x00000f,
NULL, HFILL }},
{ &hf_ansi_637_tele_length,
{ "Length", "ansi_637_tele.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_ansi_637_tele_subparam_id,
{ "Teleservice Subparam ID", "ansi_637_tele.subparam_id",
FT_UINT8, BASE_DEC, VALS(ansi_tele_param_strings), 0,
NULL, HFILL }},
};
#define NUM_INDIVIDUAL_PARAMS 3
gint *ett[NUM_INDIVIDUAL_PARAMS+NUM_TELE_PARAM+NUM_TRANS_MSG_TYPE+NUM_TRANS_PARAM];
memset((void *) ett, 0, sizeof(ett));
ett[0] = &ett_ansi_637_tele;
ett[1] = &ett_ansi_637_trans;
ett[2] = &ett_params;
for (i=0; i < NUM_TELE_PARAM; i++)
{
ett_ansi_637_tele_param[i] = -1;
ett[NUM_INDIVIDUAL_PARAMS+i] = &ett_ansi_637_tele_param[i];
}
for (i=0; i < NUM_TRANS_MSG_TYPE; i++)
{
ett_ansi_637_trans_msg[i] = -1;
ett[NUM_INDIVIDUAL_PARAMS+NUM_TELE_PARAM+i] = &ett_ansi_637_trans_msg[i];
}
for (i=0; i < NUM_TRANS_PARAM; i++)
{
ett_ansi_637_trans_param[i] = -1;
ett[NUM_INDIVIDUAL_PARAMS+NUM_TELE_PARAM+NUM_TRANS_MSG_TYPE+i] = &ett_ansi_637_trans_param[i];
}
proto_ansi_637_tele =
proto_register_protocol(ansi_proto_name_tele, "ANSI IS-637-A Teleservice", "ansi_637_tele");
proto_ansi_637_trans =
proto_register_protocol(ansi_proto_name_trans, "ANSI IS-637-A Transport", "ansi_637_trans");
register_dissector("ansi_637_tele", dissect_ansi_637_tele, proto_ansi_637_tele);
register_dissector("ansi_637_trans", dissect_ansi_637_trans, proto_ansi_637_trans);
proto_register_field_array(proto_ansi_637_tele, hf_tele, array_length(hf_tele));
proto_register_field_array(proto_ansi_637_trans, hf_trans, array_length(hf_trans));
proto_register_subtree_array(ett, array_length(ett));
tele_dissector_table =
register_dissector_table("ansi_637.tele_id",
"ANSI IS-637-A Teleservice ID", FT_UINT8, BASE_DEC);
}
void
proto_reg_handoff_ansi_637(void)
{
dissector_handle_t ansi_637_tele_handle;
dissector_handle_t ansi_637_trans_handle;
dissector_handle_t ansi_637_trans_app_handle;
guint i;
ansi_637_tele_handle = create_dissector_handle(dissect_ansi_637_tele, proto_ansi_637_tele);
ansi_637_trans_handle = create_dissector_handle(dissect_ansi_637_trans, proto_ansi_637_trans);
ansi_637_trans_app_handle = create_dissector_handle(dissect_ansi_637_trans_app, proto_ansi_637_trans);
dissector_add_string("media_type","application/vnd.3gpp2.sms", ansi_637_trans_app_handle);
for (i=0; i < ((sizeof(ansi_tele_id_strings)/sizeof(value_string))-1); i++)
{
dissector_add_uint("ansi_map.tele_id", ansi_tele_id_strings[i].value, ansi_637_tele_handle);
dissector_add_uint("ansi_637.tele_id", ansi_tele_id_strings[i].value, ansi_637_tele_handle);
}
dissector_add_uint("ansi_a.sms", 0, ansi_637_trans_handle);
}
