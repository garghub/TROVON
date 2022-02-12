static guint16
de_auth_param_rand(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_dtap_rand, tvb, offset, 16, ENC_NA);
return(16);
}
static guint16
de_auth_param_autn(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
proto_tree *subtree;
item = proto_tree_add_item(tree, hf_gsm_a_dtap_autn, tvb, offset, len, ENC_NA);
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_AUTH_PARAM_AUTN]);
if(len == 16)
{
proto_tree_add_item(subtree, hf_gsm_a_dtap_autn_sqn_xor_ak, tvb, offset, 6, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_a_dtap_autn_amf, tvb, offset + 6, 2, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_a_dtap_autn_mac, tvb, offset + 8, 8, ENC_NA);
}
else
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_WARN,
"AUTN length not equal to 16");
return(len);
}
static guint16
de_auth_resp_param(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_dtap_sres, tvb, offset, 4, ENC_NA);
return(4);
}
static guint16
de_auth_resp_param_ext(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_dtap_xres, tvb, offset, len, ENC_NA);
return(len);
}
static guint16
de_auth_fail_param(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
proto_tree *subtree;
item = proto_tree_add_item(tree, hf_gsm_a_dtap_auts, tvb, offset, len, ENC_NA);
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_AUTH_FAIL_PARAM]);
if(len == 14)
{
proto_tree_add_item(subtree, hf_gsm_a_dtap_auts_sqn_ms_xor_ak, tvb, offset, 6, ENC_NA);
proto_tree_add_item(subtree, hf_gsm_a_dtap_auts_mac_s, tvb, offset + 6, 8, ENC_NA);
}
else
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_WARN,
"AUTS length not equal to 14");
return(len);
}
static guint16
de_network_name(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
guint8 coding_scheme, num_spare_bits;
guint32 num_chars, num_text_bits;
gchar *net_name = NULL;
GIConv cd;
GError *l_conv_error = NULL;
proto_item *item;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
coding_scheme = (oct & 0x70) >> 4;
switch (coding_scheme)
{
case 0x00: str = "Cell Broadcast data coding scheme, GSM default alphabet, language unspecified, defined in 3GPP TS 23.038"; break;
case 0x01: str = "UCS2 (16 bit)"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x70, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Coding Scheme: %s",
a_bigbuf,
str);
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Add CI: The MS should %s",
a_bigbuf,
(oct & 0x08) ?
"add the letters for the Country's Initials and a separator (e.g. a space) to the text string" :
"not add the letters for the Country's Initials to the text string");
num_spare_bits = oct & 0x07;
switch (num_spare_bits)
{
case 1: str = "bit 8 is spare and set to '0' in octet n"; break;
case 2: str = "bits 7 and 8 are spare and set to '0' in octet n"; break;
case 3: str = "bits 6 to 8(inclusive) are spare and set to '0' in octet n"; break;
case 4: str = "bits 5 to 8(inclusive) are spare and set to '0' in octet n"; break;
case 5: str = "bits 4 to 8(inclusive) are spare and set to '0' in octet n"; break;
case 6: str = "bits 3 to 8(inclusive) are spare and set to '0' in octet n"; break;
case 7: str = "bits 2 to 8(inclusive) are spare and set to '0' in octet n"; break;
default:
str = "this field carries no information about the number of spare bits in octet n";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
item = proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Number of spare bits in last octet: %s",
a_bigbuf,
str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
switch(coding_scheme)
{
case 0:
num_chars = gsm_sms_char_7bit_unpack(0, len - 1, sizeof(a_bigbuf),
tvb_get_ptr(tvb, curr_offset, len - 1), a_bigbuf);
num_text_bits = ((len - 1) << 3) - num_spare_bits;
if (num_spare_bits && (num_text_bits % 7))
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_WARN, "Value leads to a Text String whose length is not a multiple of 7 bits");
}
if (num_spare_bits == 7)
num_chars--;
a_bigbuf[num_chars] = '\0';
net_name = gsm_sms_chars_to_utf8(a_bigbuf, num_chars);
proto_tree_add_text(tree, tvb , curr_offset, len - 1, "Text String: %s", net_name);
break;
case 1:
if ((cd = g_iconv_open("UTF-8","UCS-2BE")) != (GIConv)-1)
{
net_name = g_convert_with_iconv(tvb_get_ptr(tvb, curr_offset, len - 1), len - 1, cd, NULL, NULL, &l_conv_error);
if(!l_conv_error){
proto_tree_add_text(tree, tvb, curr_offset, len - 1, "Text String: %s", net_name);
}else{
proto_tree_add_text(tree, tvb, curr_offset, len - 1, "Failed on UCS2 contact wireshark developers");
}
g_free(net_name);
g_iconv_close(cd);
}
else
{
net_name = tvb_get_ephemeral_unicode_string(tvb, curr_offset, (len - 1), ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, curr_offset, len - 1, "Text String: %s", net_name);
}
break;
default:
proto_tree_add_text(tree,
tvb, curr_offset, len - 1,
"Text string encoded according to an unknown Coding Scheme");
}
return(len);
}
guint16
de_rej_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
const gchar *str;
oct = tvb_get_guint8(tvb, offset);
str = try_rval_to_str(oct, gsm_a_dtap_rej_cause_vals);
if(!str)
{
if(is_uplink == IS_UPLINK_TRUE)
str = "Protocol error, unspecified";
else
str = "Service option temporarily out of order";
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_dtap_rej_cause, tvb,
offset, 1, oct, "%s (%u)", str, oct);
return(1);
}
guint16
de_time_zone(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
char sign;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
sign = (oct & 0x08)?'-':'+';
oct = (oct >> 4) + (oct & 0x07) * 10;
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Timezone: GMT %c %d hours %d minutes",
sign, oct / 4, oct % 4 * 15);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_time_zone_time(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct, oct2, oct3;
guint32 curr_offset;
char sign;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
oct2 = tvb_get_guint8(tvb, curr_offset+1);
oct3 = tvb_get_guint8(tvb, curr_offset+2);
proto_tree_add_text(tree,
tvb, curr_offset, 3,
"Year %u%u, Month %u%u, Day %u%u",
oct & 0x0f,
(oct & 0xf0) >> 4,
oct2 & 0x0f,
(oct2 & 0xf0) >> 4,
oct3 & 0x0f,
(oct3 & 0xf0) >> 4);
curr_offset += 3;
oct = tvb_get_guint8(tvb, curr_offset);
oct2 = tvb_get_guint8(tvb, curr_offset+1);
oct3 = tvb_get_guint8(tvb, curr_offset+2);
proto_tree_add_text(tree,
tvb, curr_offset, 3,
"Hour %u%u, Minutes %u%u, Seconds %u%u",
oct & 0x0f,
(oct & 0xf0) >> 4,
oct2 & 0x0f,
(oct2 & 0xf0) >> 4,
oct3 & 0x0f,
(oct3 & 0xf0) >> 4);
curr_offset += 3;
oct = tvb_get_guint8(tvb, curr_offset);
sign = (oct & 0x08)?'-':'+';
oct = (oct >> 4) + (oct & 0x07) * 10;
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Timezone: GMT %c %d hours %d minutes",
sign, oct / 4, oct % 4 * 15);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_lsa_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
if (len == 0){
proto_tree_add_text(tree,tvb, curr_offset, len,"LSA ID not included");
}else{
proto_tree_add_item(tree, hf_gsm_a_dtap_lsa_id, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
}
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_day_saving_time(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 6, ENC_BIG_ENDIAN);
switch (oct & 0x03)
{
case 0: str = "No adjustment for Daylight Saving Time"; break;
case 1: str = "+1 hour adjustment for Daylight Saving Time"; break;
case 2: str = "+2 hours adjustment for Daylight Saving Time"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x03, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = %s",
a_bigbuf,
str);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_emerg_num_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 en_len, oct, i;
guint8 count;
guint8 *poctets;
proto_tree *subtree;
proto_item *item;
gboolean malformed_number;
curr_offset = offset;
count = 1;
while ((curr_offset - offset) < len){
en_len = tvb_get_guint8(tvb, curr_offset);
item = proto_tree_add_text(tree,
tvb, curr_offset, en_len + 1,
"Emergency Number Information %u", count);
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_EMERGENCY_NUM_LIST]);
proto_tree_add_item(subtree, hf_gsm_a_dtap_emerg_num_info_length, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_serv_cat_b5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_serv_cat_b4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_serv_cat_b3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_serv_cat_b2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_serv_cat_b1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
en_len--;
poctets = tvb_get_ephemeral_string(tvb, curr_offset, en_len);
my_dgt_tbcd_unpack(a_bigbuf, poctets, en_len, &Dgt_mbcd);
item = proto_tree_add_string_format(subtree, hf_gsm_a_dtap_emergency_bcd_num,
tvb, curr_offset, en_len,
a_bigbuf,
"BCD Digits: %s",
a_bigbuf);
malformed_number = FALSE;
for(i = 0; i < en_len - 1; i++)
{
oct = poctets[i];
if (((oct & 0xf0) == 0xf0) || ((oct & 0x0f) == 0x0f))
{
malformed_number = TRUE;
break;
}
}
oct = poctets[en_len - 1];
if ((oct & 0x0f) == 0x0f)
malformed_number = TRUE;
if(malformed_number)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_WARN, "\'f\' end mark present in unexpected position");
curr_offset = curr_offset + en_len;
count++;
}
return(len);
}
static guint16
de_add_upd_params(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_csmo, tvb, (curr_offset<<3)+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_csmt, tvb, (curr_offset<<3)+7, 1, ENC_BIG_ENDIAN);
return(len);
}
static guint16
de_mm_timer(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint16 val;
const gchar *str;
proto_tree *subtree;
proto_item *item = NULL;
oct = tvb_get_guint8(tvb, offset);
val = oct&0x1f;
switch (oct>>5)
{
case 0: str = "sec"; val*=2; break;
case 1: str = "min"; break;
case 2: str = "min"; val*=6; break;
case 7: str = "";
item = proto_tree_add_text(tree, tvb, offset, 1,
"MM Timer: timer is deactivated");
break;
default: str = "min";
}
if (item == NULL) {
item = proto_tree_add_text(tree, tvb, offset, 1,
"MM Timer: %u %s", val, str);
}
subtree = proto_item_add_subtree(item, ett_mm_timer);
proto_tree_add_item(subtree, hf_gsm_a_dtap_mm_timer_unit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_mm_timer_value, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_aux_states(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+1, 3, ENC_BIG_ENDIAN);
switch ((oct & 0x0c) >> 2)
{
case 0: str = "Idle"; break;
case 1: str = "Hold request"; break;
case 2: str = "Call held"; break;
default:
str = "Retrieve request";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0c, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Hold auxiliary state: %s",
a_bigbuf,
str);
switch (oct & 0x03)
{
case 0: str = "Idle"; break;
case 1: str = "MPTY request"; break;
case 2: str = "Call in MPTY"; break;
default:
str = "Split request";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x03, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Multi party auxiliary state: %s",
a_bigbuf,
str);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
guint16
de_bearer_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 oct;
guint8 itc;
gboolean extended;
guint32 curr_offset;
guint32 saved_offset;
proto_tree *subtree;
proto_item *item;
const gchar *str;
#define DE_BC_ITC_SPEECH 0x00
#define DE_BC_ITC_UDI 0x01
#define DE_BC_ITC_EX_PLMN 0x02
#define DE_BC_ITC_FASC_G3 0x03
#define DE_BC_ITC_OTHER_ITC 0x05
#define DE_BC_ITC_RSVD_NET 0x07
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 3");
subtree = proto_item_add_subtree(item, ett_bc_oct_3);
extended = (oct & 0x80) ? FALSE : TRUE;
itc = oct & 0x07;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch (is_uplink)
{
case IS_UPLINK_FALSE:
str = "Spare";
break;
case IS_UPLINK_TRUE:
switch (itc)
{
case DE_BC_ITC_SPEECH:
if (extended)
{
switch ((oct & 0x60) >> 5)
{
case 1: str = "MS supports at least full rate speech version 1 but does not support half rate speech version 1"; break;
case 2: str = "MS supports at least full rate speech version 1 and half rate speech version 1. MS has a greater preference for half rate speech version 1 than for full rate speech version 1"; break;
case 3: str = "MS supports at least full rate speech version 1 and half rate speech version 1. MS has a greater preference for full rate speech version 1 than for half rate speech version 1"; break;
default:
str = "Reserved";
break;
}
}
else
{
switch ((oct & 0x60) >> 5)
{
case 1: str = "Full rate support only MS/fullrate speech version 1 supported"; break;
case 2: str = "Dual rate support MS/half rate speech version 1 preferred, full rate speech version 1 also supported"; break;
case 3: str = "Dual rate support MS/full rate speech version 1 preferred, half rate speech version 1 also supported"; break;
default:
str = "Reserved";
break;
}
}
break;
default:
switch ((oct & 0x60) >> 5)
{
case 1: str = "Full rate support only MS"; break;
case 2: str = "Dual rate support MS/half rate preferred"; break;
case 3: str = "Dual rate support MS/full rate preferred"; break;
default:
str = "Reserved";
break;
}
break;
}
break;
default:
str = "(dissect problem)";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Radio channel requirement: %s",
a_bigbuf,
str);
other_decode_bitfield_value(a_bigbuf, oct, 0x10, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Coding standard: %s",
a_bigbuf,
(oct & 0x10) ? "reserved" : "GSM standardized coding");
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Transfer mode: %s",
a_bigbuf,
(oct & 0x08) ? "packet" : "circuit");
proto_tree_add_item(subtree, hf_gsm_a_dtap_itc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (add_string)
g_snprintf(add_string, string_len, " - (%s)", str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
switch (itc)
{
case DE_BC_ITC_SPEECH:
item =
proto_tree_add_text(tree,
tvb, curr_offset, -1,
"Octets 3a - Speech Versions");
subtree = proto_item_add_subtree(item, ett_bc_oct_3a);
saved_offset = curr_offset;
do
{
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x40, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Coding: octet used for %s",
a_bigbuf,
(oct & 0x40) ? "other extension of octet 3" :
"extension of information transfer capability");
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_speech_vers_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
while (extended &&
((len - (curr_offset - offset)) > 0));
proto_item_set_len(item, curr_offset - saved_offset);
break;
default:
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 4");
subtree = proto_item_add_subtree(item, ett_bc_oct_4);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x40, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Compression: data compression %s%s",
a_bigbuf,
(oct & 0x40) ? "" : "not ",
is_uplink ? "allowed" : "possible");
switch ((oct & 0x30) >> 4)
{
case 0x00: str = "Service data unit integrity"; break;
case 0x03: str = "Unstructured"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x30, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Structure: %s",
a_bigbuf,
str);
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Duplex mode: %s",
a_bigbuf,
(oct & 0x08) ? "Full" : "Half");
other_decode_bitfield_value(a_bigbuf, oct, 0x04, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Configuration: %s",
a_bigbuf,
(oct & 0x04) ? "Reserved" : "Point-to-point");
other_decode_bitfield_value(a_bigbuf, oct, 0x02, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = NIRR: %s",
a_bigbuf,
(oct & 0x02) ?
"Data up to and including 4.8 kb/s, full rate, non-transparent, 6 kb/s radio interface rate is requested" :
"No meaning is associated with this value");
other_decode_bitfield_value(a_bigbuf, oct, 0x01, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Establishment: %s",
a_bigbuf,
(oct & 0x01) ? "Reserved" : "Demand");
curr_offset++;
NO_MORE_DATA_CHECK(len);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 5");
subtree = proto_item_add_subtree(item, ett_bc_oct_5);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Access Identity: %s",
a_bigbuf,
(oct & 0x60) ? "Reserved" : "Octet identifier");
switch ((oct & 0x18) >> 3)
{
case 0x00: str = "No rate adaption"; break;
case 0x01: str = "Rate adaptation according to ITU-T Rec. V.110 and ITU-T Rec. X.30"; break;
case 0x02: str = "Flag stuffing according to ITU-T Rec. X.31"; break;
default:
str = "Other rate adaption (see octet 5a)";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x18, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Rate Adaption: %s",
a_bigbuf,
str);
switch (oct & 0x07)
{
case 0x01: str = "According to ITU-T Rec. Q.920 and ITU-T Rec. Q.930"; break;
case 0x02: str = "Reserved: was allocated in earlier phases of the protocol"; break;
case 0x03: str = "Reserved: was allocated in earlier phases of the protocol"; break;
case 0x04: str = "Reserved: was allocated in earlier phases of the protocol"; break;
case 0x05: str = "Reserved: was allocated in earlier phases of the protocol"; break;
case 0x06: str = "Reserved: was allocated in earlier phases of the protocol"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Signalling Access Protocol: %s",
a_bigbuf,
str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_6;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 5a");
subtree = proto_item_add_subtree(item, ett_bc_oct_5a);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Other ITC: %s",
a_bigbuf,
(oct & 0x60) ? "Reserved" : "Restricted digital information");
switch ((oct & 0x18) >> 3)
{
case 0x00: str = "According to ITU-T Rec. V.120"; break;
case 0x01: str = "According to ITU-T Rec. H.223 and ITU-T Rec. H.245"; break;
case 0x02: str = "PIAFS"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x18, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Other Rate Adaption: %s",
a_bigbuf,
str);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+5, 3, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_6;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 5b");
subtree = proto_item_add_subtree(item, ett_bc_oct_5b);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x40, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Rate Adaption Header: %sincluded",
a_bigbuf,
(oct & 0x40) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x20, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Multiple frame establishment support in data link: %s",
a_bigbuf,
(oct & 0x20) ? "Supported" : "Not supported, only UI frames allowed");
other_decode_bitfield_value(a_bigbuf, oct, 0x10, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Mode of operation: %s",
a_bigbuf,
(oct & 0x10) ? "Protocol sensitive" : "Bit transparent");
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Logical link identifier negotiation: %s",
a_bigbuf,
(oct & 0x08) ? "Full protocol negotiation" : "Default, LLI=256 only");
other_decode_bitfield_value(a_bigbuf, oct, 0x04, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Assignor/Assignee: Message originator is '%s'",
a_bigbuf,
(oct & 0x04) ? "assignor only" : "default assignee");
other_decode_bitfield_value(a_bigbuf, oct, 0x02, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = In band/Out of band negotiation: Negotiation is done %s",
a_bigbuf,
(oct & 0x02) ?
"with USER INFORMATION messages on a temporary signalling connection" :
"in-band using logical link zero");
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+7, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
bc_octet_6:
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 6");
subtree = proto_item_add_subtree(item, ett_bc_oct_6);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Layer 1 Identity: %s",
a_bigbuf,
((oct & 0x60) == 0x20) ? "Octet identifier" : "Reserved");
other_decode_bitfield_value(a_bigbuf, oct, 0x1e, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = User information layer 1 protocol: %s",
a_bigbuf,
(oct & 0x1e) ? "Reserved" : "Default layer 1 protocol");
other_decode_bitfield_value(a_bigbuf, oct, 0x01, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Synchronous/asynchronous: %s",
a_bigbuf,
(oct & 0x01) ? "Asynchronous" : "Synchronous");
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_7;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 6a");
subtree = proto_item_add_subtree(item, ett_bc_oct_6a);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x40, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Number of Stop Bits: %s",
a_bigbuf,
(oct & 0x40) ? "2" : "1");
other_decode_bitfield_value(a_bigbuf, oct, 0x20, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Negotiation: %s",
a_bigbuf,
(oct & 0x20) ? "Reserved" : "In-band negotiation not possible");
other_decode_bitfield_value(a_bigbuf, oct, 0x10, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Number of data bits excluding parity bit if present: %s",
a_bigbuf,
(oct & 0x10) ? "8" : "7");
switch (oct & 0x0f)
{
case 0x01: str = "0.3 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x02: str = "1.2 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x03: str = "2.4 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x04: str = "4.8 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x05: str = "9.6 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x06: str = "12.0 kbit/s transparent (non compliance with ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x07: str = "Reserved: was allocated in earlier phases of the protocol"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = User rate: %s",
a_bigbuf,
str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_7;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 6b");
subtree = proto_item_add_subtree(item, ett_bc_oct_6b);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch ((oct & 0x60) >> 5)
{
case 0x02: str = "8 kbit/s"; break;
case 0x03: str = "16 kbit/s"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = V.110/X.30 rate adaptation Intermediate rate: %s",
a_bigbuf,
str);
other_decode_bitfield_value(a_bigbuf, oct, 0x10, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Network independent clock (NIC) on transmission (Tx): %s to send data with network independent clock",
a_bigbuf,
(oct & 0x10) ? "requires" : "does not require");
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Network independent clock (NIC) on reception (Rx): %s accept data with network independent clock",
a_bigbuf,
(oct & 0x08) ? "can" : "cannot");
switch (oct & 0x07)
{
case 0x00: str = "Odd"; break;
case 0x02: str = "Even"; break;
case 0x03: str = "None"; break;
case 0x04: str = "Forced to 0"; break;
case 0x05: str = "Forced to 1"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Parity information: %s",
a_bigbuf,
str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_7;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 6c");
subtree = proto_item_add_subtree(item, ett_bc_oct_6c);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch ((oct & 0x60) >> 5)
{
case 0x01: str = "Non transparent (RLP)"; break;
case 0x02: str = "Both, transparent preferred"; break;
case 0x03: str = "Both, non transparent preferred"; break;
default:
str = "Transparent";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Connection element: %s",
a_bigbuf,
str);
switch (oct & 0x1f)
{
case 0x00: str = "None"; break;
case 0x01: str = "According to ITU-T Rec. V.21"; break;
case 0x02: str = "According to ITU-T Rec. V.22"; break;
case 0x03: str = "According to ITU-T Rec. V.22 bis"; break;
case 0x04: str = "Reserved: was allocated in earlier phases of the protocol"; break;
case 0x05: str = "According to ITU-T Rec. V.26 ter"; break;
case 0x06: str = "According to ITU-T Rec. V.32"; break;
case 0x07: str = "Modem for undefined interface"; break;
case 0x08: str = "Autobauding type 1"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x1f, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Modem type: %s",
a_bigbuf,
str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_7;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 6d");
subtree = proto_item_add_subtree(item, ett_bc_oct_6d);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch ((oct & 0x60) >> 5)
{
case 0x00: str = "No other modem type specified in this field"; break;
case 0x02: str = "According to ITU-T Rec. V.34"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Other modem type: %s",
a_bigbuf,
str);
switch (oct & 0x1f)
{
case 0x00: str = "Fixed network user rate not applicable/No meaning is associated with this value"; break;
case 0x01: str = "9.6 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x02: str = "14.4 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x03: str = "19.2 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x04: str = "28.8 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x05: str = "38.4 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110)"; break;
case 0x06: str = "48.0 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110 (synch))"; break;
case 0x07: str = "56.0 kbit/s (according to ITU-T Rec. X.1 and ITU-T Rec. V.110 (synch) /bit transparent)"; break;
case 0x08: str = "64.0 kbit/s bit transparent"; break;
case 0x09: str = "33.6 kbit/s bit transparent"; break;
case 0x0a: str = "32.0 kbit/s (according to ITU-T Rec. I.460)"; break;
case 0x0b: str = "31.2 kbit/s (according to ITU-T Rec. V.34)"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x1f, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Fixed network user rate: %s",
a_bigbuf,
str);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_7;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 6e");
subtree = proto_item_add_subtree(item, ett_bc_oct_6e);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (is_uplink == IS_UPLINK_TRUE)
{
other_decode_bitfield_value(a_bigbuf, oct, 0x40, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings: TCH/F14.4 %sacceptable",
a_bigbuf,
(oct & 0x40) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x20, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings: Spare",
a_bigbuf);
other_decode_bitfield_value(a_bigbuf, oct, 0x10, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings: TCH/F9.6 %sacceptable",
a_bigbuf,
(oct & 0x10) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings: TCH/F4.8 %sacceptable",
a_bigbuf,
(oct & 0x08) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Maximum number of traffic channels: %u TCH",
a_bigbuf,
(oct & 0x07) + 1);
}
else
{
other_decode_bitfield_value(a_bigbuf, oct, 0x78, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings: Spare",
a_bigbuf);
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Maximum number of traffic channels: Spare",
a_bigbuf);
}
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_7;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 6f");
subtree = proto_item_add_subtree(item, ett_bc_oct_6f);
oct = tvb_get_guint8(tvb, curr_offset);
extended = (oct & 0x80) ? FALSE : TRUE;
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch ((oct & 0x70) >> 4)
{
case 0x00: str = "not allowed/required/applicable"; break;
case 0x01: str = "up to 1 TCH/F allowed/may be requested"; break;
case 0x02: str = "up to 2 TCH/F allowed/may be requested"; break;
case 0x03: str = "up to 3 TCH/F allowed/may be requested"; break;
case 0x04: str = "up to 4 TCH/F allowed/may be requested"; break;
default:
str = "up to 4 TCH/F may be requested";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x70, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = UIMI, User initiated modification indication: %s",
a_bigbuf,
str);
if (is_uplink == IS_UPLINK_TRUE)
{
switch (oct & 0x0f)
{
case 0x00: str = "Air interface user rate not applicable/No meaning associated with this value"; break;
case 0x01: str = "9.6 kbit/s"; break;
case 0x02: str = "14.4 kbit/s"; break;
case 0x03: str = "19.2 kbit/s"; break;
case 0x05: str = "28.8 kbit/s"; break;
case 0x06: str = "38.4 kbit/s"; break;
case 0x07: str = "43.2 kbit/s"; break;
case 0x08: str = "57.6 kbit/s"; break;
case 0x09: str = "interpreted by the network as 38.4 kbit/s in this version of the protocol"; break;
case 0x0a: str = "interpreted by the network as 38.4 kbit/s in this version of the protocol"; break;
case 0x0b: str = "interpreted by the network as 38.4 kbit/s in this version of the protocol"; break;
case 0x0c: str = "interpreted by the network as 38.4 kbit/s in this version of the protocol"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Wanted air interface user rate: %s",
a_bigbuf,
str);
}
else
{
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Wanted air interface user rate: Spare",
a_bigbuf);
}
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (!extended) goto bc_octet_7;
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 6g");
subtree = proto_item_add_subtree(item, ett_bc_oct_6g);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (is_uplink == IS_UPLINK_TRUE)
{
other_decode_bitfield_value(a_bigbuf, oct, 0x40, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings extended: TCH/F28.8 %sacceptable",
a_bigbuf,
(oct & 0x40) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x20, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings extended: TCH/F32.0 %sacceptable",
a_bigbuf,
(oct & 0x20) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x10, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings extended: TCH/F43.2 %sacceptable",
a_bigbuf,
(oct & 0x10) ? "" : "not ");
other_decode_bitfield_value(a_bigbuf, oct, 0x10, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Acceptable channel codings extended: TCH/F43.2 %sacceptable",
a_bigbuf,
(oct & 0x10) ? "" : "not ");
switch ((oct & 0x0c) >> 2)
{
case 0: str = "Channel coding symmetry preferred"; break;
case 2: str = "Downlink biased channel coding asymmetry is preferred"; break;
case 1: str = "Uplink biased channel coding asymmetry is preferred"; break;
default:
str = "Unused, treat as Channel coding symmetry preferred";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0c, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Channel Coding Asymmetry Indication: %s",
a_bigbuf,
str);
}
else
{
other_decode_bitfield_value(a_bigbuf, oct, 0x7c, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = EDGE Channel Codings: Spare",
a_bigbuf);
}
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+6, 2, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
bc_octet_7:
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Octet 7");
subtree = proto_item_add_subtree(item, ett_bc_oct_7);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Layer 2 Identity: %s",
a_bigbuf,
((oct & 0x60) == 0x40) ? "Octet identifier" : "Reserved");
switch (oct & 0x1f)
{
case 0x06: str = "Reserved: was allocated in earlier phases of the protocol"; break;
case 0x08: str = "According to ISO/IEC 6429, codeset 0 (DC1/DC3)"; break;
case 0x09: str = "Reserved: was allocated but never used in earlier phases of the protocol"; break;
case 0x0a: str = "Videotex profile 1"; break;
case 0x0c: str = "COPnoFlCt (Character oriented Protocol with no Flow Control mechanism)"; break;
case 0x0d: str = "Reserved: was allocated in earlier phases of the protocol"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x1f, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = User information layer 2 protocol: %s",
a_bigbuf,
str);
break;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
guint16
de_bearer_cap_uplink(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
is_uplink = IS_UPLINK_TRUE;
return de_bearer_cap(tvb, tree, pinfo, offset, len, add_string, string_len);
}
static guint16
de_cc_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_){
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
other_decode_bitfield_value(a_bigbuf, oct, 0xf0, 8);
switch ((oct & 0xf0) >> 4)
{
case 0:
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Maximum number of supported bearers: 1",
a_bigbuf);
break;
default:
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Maximum number of supported bearers: %u",
a_bigbuf,
(oct & 0xf0) >> 4);
break;
}
proto_tree_add_item(tree, hf_gsm_a_dtap_mcat, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_enicm, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x02, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = PCP: the mobile station %s the Prolonged Clearing Procedure",
a_bigbuf,
(oct & 0x02) ? "supports" : "does not support");
other_decode_bitfield_value(a_bigbuf, oct, 0x01, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = DTMF: %s",
a_bigbuf,
(oct & 0x01) ?
"the mobile station supports DTMF as specified in subclause 5.5.7 of TS 24.008" :
"reserved for earlier versions of the protocol");
curr_offset++;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Maximum number of speech bearers: %u",
a_bigbuf,
oct & 0x0f);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_call_state(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct, coding_standard, call_state;
proto_tree *subtree;
proto_item *item;
item =
proto_tree_add_text(tree,
tvb, offset, 1, "%s",
val_to_str_ext_const(DE_CALL_STATE, &gsm_dtap_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_CALL_STATE]);
proto_tree_add_item(subtree, hf_gsm_a_dtap_coding_standard, tvb, offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, offset);
coding_standard = (oct & 0xc0) >> 6;
call_state = oct & 0x3f;
switch (coding_standard)
{
case 0:
proto_tree_add_uint_format_value(subtree, hf_gsm_a_dtap_call_state, tvb,
offset, 1, call_state, "%s (%u)",
val_to_str_ext_const(call_state, &q931_call_state_vals_ext, "Reserved"),
call_state);
break;
case 1:
case 2:
proto_tree_add_item(subtree, hf_gsm_a_dtap_call_state, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_uint_format_value(subtree, hf_gsm_a_dtap_call_state, tvb,
offset, 1, call_state, "%s (%u)",
val_to_str_const(call_state, gsm_a_dtap_call_state_vals, "Reserved"),
call_state);
break;
}
return(1);
}
static guint16
de_bcd_num(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, int header_field, gboolean *address_extracted)
{
guint8 *poctets;
guint8 extension, oct;
guint32 curr_offset, i, num_string_len;
proto_item *item;
gboolean malformed_number;
*address_extracted = FALSE;
curr_offset = offset;
extension = tvb_get_guint8(tvb, curr_offset) & 0x80;
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_type_of_number, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_numbering_plan_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (!extension)
{
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_present_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+3, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_screening_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
NO_MORE_DATA_CHECK(len);
num_string_len = len - (curr_offset - offset);
poctets = tvb_get_ephemeral_string(tvb, curr_offset, num_string_len);
*address_extracted = TRUE;
my_dgt_tbcd_unpack(a_bigbuf, poctets, num_string_len,
&Dgt_mbcd);
item = proto_tree_add_string_format(tree, header_field,
tvb, curr_offset, num_string_len,
a_bigbuf,
"BCD Digits: %s",
a_bigbuf);
malformed_number = FALSE;
for(i = 0; i < num_string_len - 1; i++)
{
oct = poctets[i];
if (((oct & 0xf0) == 0xf0) || ((oct & 0x0f) == 0x0f))
{
malformed_number = TRUE;
break;
}
}
oct = poctets[num_string_len - 1];
if ((oct & 0x0f) == 0x0f)
malformed_number = TRUE;
if(malformed_number)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_WARN, "\'f\' end mark present in unexpected position");
return(len);
}
static guint16
de_sub_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gboolean *address_extracted)
{
guint32 curr_offset, ia5_string_len, i;
guint8 type_of_sub_addr, afi, dig1, dig2, oct;
gchar *ia5_string;
gboolean invalid_ia5_char;
proto_item *item;
curr_offset = offset;
*address_extracted = FALSE;
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_type_of_sub_addr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+5, 3, ENC_BIG_ENDIAN);
type_of_sub_addr = (tvb_get_guint8(tvb, curr_offset) & 0x70) >> 4;
curr_offset++;
NO_MORE_DATA_CHECK(len);
if(!type_of_sub_addr)
{
afi = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_dtap_afi, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
if (afi == 0x50)
{
ia5_string_len = len - (curr_offset - offset);
ia5_string = tvb_get_ephemeral_string(tvb, curr_offset, ia5_string_len);
invalid_ia5_char = FALSE;
for(i = 0; i < ia5_string_len; i++)
{
dig1 = (ia5_string[i] & 0xf0) >> 4;
dig2 = ia5_string[i] & 0x0f;
oct = (dig1 * 10) + dig2 + 32;
if (oct > 127)
invalid_ia5_char = TRUE;
ia5_string[i] = oct;
}
IA5_7BIT_decode(a_bigbuf, ia5_string, ia5_string_len);
*address_extracted = TRUE;
item = proto_tree_add_text(tree,
tvb, curr_offset, len - (curr_offset - offset),
"Subaddress: %s", a_bigbuf);
if(invalid_ia5_char)
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_WARN, "Invalid IA5 character(s) in string (value > 127)");
return(len);
}
}
proto_tree_add_text(tree,
tvb, curr_offset, len - (curr_offset - offset),
"Subaddress information");
return(len);
}
guint16
de_cld_party_bcd_num(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
gboolean addr_extr;
de_bcd_num(tvb, tree, pinfo, offset, len, hf_gsm_a_dtap_cld_party_bcd_num, &addr_extr);
if(addr_extr) {
if (sccp_assoc && ! sccp_assoc->called_party) {
sccp_assoc->called_party = se_strdup(a_bigbuf);
}
if (add_string)
g_snprintf(add_string, string_len, " - (%s)", a_bigbuf);
}
return(len);
}
static guint16
de_cld_party_sub_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
gboolean addr_extr;
de_sub_addr(tvb, tree, pinfo, offset, len, &addr_extr);
if (addr_extr && add_string)
g_snprintf(add_string, string_len, " - (%s)", a_bigbuf);
return(len);
}
static guint16
de_clg_party_bcd_num(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
gboolean addr_extr;
de_bcd_num(tvb, tree, pinfo, offset, len, hf_gsm_a_dtap_clg_party_bcd_num, &addr_extr);
if (addr_extr && add_string)
g_snprintf(add_string, string_len, " - (%s)", a_bigbuf);
return(len);
}
static guint16
de_clg_party_sub_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
gboolean addr_extr;
de_sub_addr(tvb, tree, pinfo, offset, len, &addr_extr);
if (addr_extr && add_string)
g_snprintf(add_string, string_len, " - (%s)", a_bigbuf);
return(len);
}
static guint16
de_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 oct;
guint8 cause;
guint32 curr_offset;
guint32 diag_length;
proto_tree *subtree;
proto_item *item;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch ((oct & 0x60) >> 5)
{
case 0: str = "Coding as specified in ITU-T Rec. Q.931"; break;
case 1: str = "Reserved for other international standards"; break;
case 2: str = "National standard"; break;
default:
str = "Standard defined for the GSM PLMNS";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x60, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Coding standard: %s",
a_bigbuf,
str);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+3, 1, ENC_BIG_ENDIAN);
switch (oct & 0x0f)
{
case 0: str = "User"; break;
case 1: str = "Private network serving the local user"; break;
case 2: str = "Public network serving the local user"; break;
case 3: str = "Transit network"; break;
case 4: str = "Public network serving the remote user"; break;
case 5: str = "Private network serving the remote user"; break;
case 7: str = "International network"; break;
case 10: str = "Network beyond interworking point"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Location: %s",
a_bigbuf,
str);
curr_offset++;
oct = tvb_get_guint8(tvb, curr_offset);
if (!(oct & 0x80))
{
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Recommendation",
a_bigbuf);
curr_offset++;
oct = tvb_get_guint8(tvb, curr_offset);
}
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
cause = oct & 0x7f;
switch (cause)
{
case 1: str = "Unassigned (unallocated) number"; break;
case 3: str = "No route to destination"; break;
case 6: str = "Channel unacceptable"; break;
case 8: str = "Operator determined barring"; break;
case 16: str = "Normal call clearing"; break;
case 17: str = "User busy"; break;
case 18: str = "No user responding"; break;
case 19: str = "User alerting, no answer"; break;
case 21: str = "Call rejected"; break;
case 22: str = "Call rejected due to feature at the destination"; break;
case 24: str = "Number changed"; break;
case 25: str = "Pre-emption"; break;
case 26: str = "Non selected user clearing"; break;
case 27: str = "Destination out of order"; break;
case 28: str = "Invalid number format (incomplete number)"; break;
case 29: str = "Facility rejected"; break;
case 30: str = "Response to STATUS ENQUIRY"; break;
case 31: str = "Normal, unspecified"; break;
case 34: str = "No circuit/channel available"; break;
case 38: str = "Network out of order"; break;
case 41: str = "Temporary failure"; break;
case 42: str = "Switching equipment congestion"; break;
case 43: str = "Access information discarded"; break;
case 44: str = "requested circuit/channel not available"; break;
case 47: str = "Resources unavailable, unspecified"; break;
case 49: str = "Quality of service unavailable"; break;
case 50: str = "Requested facility not subscribed"; break;
case 55: str = "Incoming calls barred within the CUG"; break;
case 57: str = "Bearer capability not authorized"; break;
case 58: str = "Bearer capability not presently available"; break;
case 63: str = "Service or option not available, unspecified"; break;
case 65: str = "Bearer service not implemented"; break;
case 68: str = "ACM equal to or greater than ACMmax"; break;
case 69: str = "Requested facility not implemented"; break;
case 70: str = "Only restricted digital information bearer capability is available"; break;
case 79: str = "Service or option not implemented, unspecified"; break;
case 81: str = "Invalid transaction identifier value"; break;
case 87: str = "User not member of CUG"; break;
case 88: str = "Incompatible destination"; break;
case 91: str = "Invalid transit network selection"; break;
case 95: str = "Semantically incorrect message"; break;
case 96: str = "Invalid mandatory information"; break;
case 97: str = "Message type non-existent or not implemented"; break;
case 98: str = "Message type not compatible with protocol state"; break;
case 99: str = "Information element non-existent or not implemented"; break;
case 100: str = "Conditional IE error"; break;
case 101: str = "Message not compatible with protocol state"; break;
case 102: str = "Recovery on timer expiry"; break;
case 111: str = "Protocol error, unspecified"; break;
case 127: str = "Interworking, unspecified"; break;
default:
if (cause <= 31) { str = "Treat as Normal, unspecified"; }
else if ((cause >= 32) && (cause <= 47)) { str = "Treat as Resources unavailable, unspecified"; }
else if ((cause >= 48) && (cause <= 63)) { str = "Treat as Service or option not available, unspecified"; }
else if ((cause >= 64) && (cause <= 79)) { str = "Treat as Service or option not implemented, unspecified"; }
else if ((cause >= 80) && (cause <= 95)) { str = "Treat as Semantically incorrect message"; }
else if ((cause >= 96) && (cause <= 111)) { str = "Treat as Protocol error, unspecified"; }
else if ((cause >= 112) && (cause <= 127)) { str = "Treat as Interworking, unspecified"; }
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
proto_tree_add_uint_format(tree, hf_gsm_a_dtap_cause,
tvb, curr_offset, 1, cause,
"%s = Cause: (%u) %s",
a_bigbuf,
cause,
str);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (%u) %s", cause, str);
NO_MORE_DATA_CHECK(len);
item = proto_tree_add_text(tree, tvb, curr_offset, len - (curr_offset - offset), "Diagnostics");
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_CAUSE]);
if ((cause == 17) || (cause == 29) || (cause == 34) || (cause == 50) ||
(cause == 55) || (cause == 69) || (cause == 87))
{
proto_tree_add_item(subtree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_cause_ss_diagnostics, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
else
{
diag_length = len - (curr_offset - offset);
proto_tree_add_text(subtree, tvb, curr_offset, diag_length,
"Data: %s", tvb_bytes_to_str(tvb, curr_offset, diag_length));
curr_offset += diag_length;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_conn_num(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
gboolean addr_extr;
de_bcd_num(tvb, tree, pinfo, offset, len, hf_gsm_a_dtap_conn_num, &addr_extr);
if (addr_extr && add_string)
g_snprintf(add_string, string_len, " - (%s)", a_bigbuf);
return(len);
}
static guint16
de_conn_sub_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
gboolean addr_extr;
de_sub_addr(tvb, tree, pinfo, offset, len, &addr_extr);
if (addr_extr && add_string)
g_snprintf(add_string, string_len, " - (%s)", a_bigbuf);
return(len);
}
static guint16
de_facility(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint fac_len, gchar *add_string _U_, int string_len _U_)
{
guint saved_offset;
gint8 appclass;
gboolean pc;
gboolean ind = FALSE;
guint32 component_len = 0;
guint32 header_end_offset;
guint32 header_len;
asn1_ctx_t asn1_ctx;
tvbuff_t *SS_tvb = NULL;
void *save_private_data;
static gint comp_type_tag;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
save_private_data= pinfo->private_data;
saved_offset = offset;
pinfo->private_data = NULL;
col_append_str(pinfo->cinfo, COL_PROTOCOL,"/");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
while ( fac_len > (offset - saved_offset)){
header_end_offset = get_ber_identifier(tvb, offset, &appclass, &pc, &comp_type_tag);
header_end_offset = get_ber_length(tvb, header_end_offset, &component_len, &ind);
header_len = header_end_offset - offset;
component_len = header_len + component_len;
SS_tvb = tvb_new_subset(tvb, offset, component_len, component_len);
col_append_str(pinfo->cinfo, COL_INFO,"(GSM MAP) ");
col_set_fence(pinfo->cinfo, COL_INFO);
call_dissector(gsm_map_handle, SS_tvb, pinfo, tree);
offset = offset + component_len;
}
pinfo->private_data = save_private_data;
return(fac_len);
}
static guint16
de_hlc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
dissect_q931_high_layer_compat_ie(tvb, offset, len, tree);
curr_offset = curr_offset + len;
return(curr_offset - offset);
}
static guint16
de_keypad_facility(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint8 oct, keypad_char;
guint32 curr_offset;
proto_item *item;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
keypad_char = oct & 0x7f;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x7f, 8);
item = proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = Keypad information: %c",
a_bigbuf,
keypad_char);
if (((keypad_char < '0') || (keypad_char > '9')) &&
((keypad_char < 'A') || (keypad_char > 'D')) &&
(keypad_char != '*') && (keypad_char != '#'))
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_WARN, "Keypad information contains character that is not a DTMF digit");
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - %c", keypad_char);
return(curr_offset - offset);
}
static guint16
de_llc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
dissect_q931_bearer_capability_ie(tvb, offset, len, tree);
curr_offset = curr_offset + len;
return(curr_offset - offset);
}
static guint16
de_notif_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_notification_description, tvb, offset, 1, ENC_BIG_ENDIAN);
return 1;
}
static guint16
de_prog_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct, coding_standard, progress_description;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
coding_standard = (oct & 0x60) >> 5;
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_prog_coding_standard, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3) + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_location, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
oct = tvb_get_guint8(tvb, curr_offset);
progress_description = oct & 0x7f;
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
switch (coding_standard)
{
case 0:
proto_tree_add_uint_format_value(tree, hf_gsm_a_dtap_progress_description, tvb,
curr_offset, 1, progress_description, "%s (%u)",
val_to_str_ext_const(progress_description, &q931_progress_description_vals_ext, "Reserved"),
progress_description);
break;
case 1:
case 2:
proto_tree_add_item(tree, hf_gsm_a_dtap_progress_description, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_uint_format_value(tree, hf_gsm_a_dtap_progress_description, tvb,
curr_offset, 1, progress_description, "%s (%u)",
val_to_str_const(progress_description, gsm_a_dtap_progress_description_vals, "Unspecific"),
progress_description);
break;
}
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_recall_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (offset<<3), 5, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_recall_type, tvb, offset, 1, ENC_BIG_ENDIAN);
return(1);
}
static guint16
de_red_party_bcd_num(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
gboolean addr_extr;
de_bcd_num(tvb, tree, pinfo, offset, len, hf_gsm_a_dtap_red_party_bcd_num, &addr_extr);
if (addr_extr && add_string)
g_snprintf(add_string, string_len, " - (%s)", a_bigbuf);
return(len);
}
static guint16
de_red_party_sub_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
gboolean addr_extr;
de_sub_addr(tvb, tree, pinfo, offset, len, &addr_extr);
if (addr_extr && add_string)
g_snprintf(add_string, string_len, " - (%s)", a_bigbuf);
return(len);
}
static guint16
de_repeat_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct & 0x0f)
{
case 1: str = "Circular for successive selection 'mode 1 alternate mode 2'"; break;
case 2: str = "Support of fallback mode 1 preferred, mode 2 selected if setup of mode 1 fails"; break;
case 3: str = "Reserved: was allocated in earlier phases of the protocol"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s = %s",
a_bigbuf,
str);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_setup_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
dtap_cc_setup(tvb, tree, pinfo, offset, len);
return (len);
}
static guint16
de_signal(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_dtap_signal_value, tvb, offset, 1, ENC_BIG_ENDIAN);
return 1;
}
static guint16
de_ss_ver_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0: str = "Phase 2 service, ellipsis notation, and phase 2 error handling is supported"; break;
case 1: str = "SS-Protocol version 3 is supported, and phase 2 error handling is supported"; break;
default:
str = "Reserved";
break;
}
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s",
str);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_u2u(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_dtap_u2u_prot_discr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
item = proto_tree_add_text(tree, tvb, curr_offset, len - 1, "User-user information");
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_USER_USER]);
proto_tree_add_text(subtree, tvb, curr_offset, len - 1,
"Data: %s", tvb_bytes_to_str(tvb, curr_offset, len - 1));
return(len);
}
static guint16
de_alert_pat(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_alerting_pattern, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(len);
}
static guint16
de_allowed_act(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_dtap_ccbs_activation, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3) + 1, 7, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(len);
}
static guint16
de_stream_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
{
proto_tree_add_uint_format(tree, hf_gsm_a_dtap_stream_identifier, tvb, curr_offset, 1, oct,
"Stream Identifier: No Bearer (%u)", oct);
if (add_string)
g_snprintf(add_string, string_len, " - (No Bearer)");
}
else
{
proto_tree_add_uint_format(tree, hf_gsm_a_dtap_stream_identifier, tvb, curr_offset, 1, oct,
"Stream Identifier: %u", oct);
if (add_string)
g_snprintf(add_string, string_len, " - (%u)", oct);
}
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(len);
}
static guint16
de_nw_call_ctrl_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3), 7, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_mcs, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(len);
}
static guint16
de_ca_of_no_cli(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format(tree, hf_gsm_a_dtap_cause_of_no_cli, tvb, curr_offset, 1, oct,
"Cause of no CLI: %s (%u)",
val_to_str_const(oct, gsm_a_cause_of_no_cli_values, "Unavailable"),
oct);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (%s)", val_to_str_const(oct, gsm_a_cause_of_no_cli_values, "Unavailable"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(len);
}
guint16
de_sup_codec_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 length;
proto_tree *subtree;
proto_item *item;
guint8 sysid_counter;
curr_offset = offset;
sysid_counter = 0;
while (len>(curr_offset-offset)){
sysid_counter++;
proto_tree_add_item(tree, hf_gsm_a_dtap_sysid, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_gsm_a_dtap_bitmap_length, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
length = tvb_get_guint8(tvb,curr_offset);
curr_offset++;
if (length > 0)
{
item = proto_tree_add_text(tree, tvb, curr_offset, length, "Codec Bitmap for SysID %u", sysid_counter);
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_SUP_CODEC_LIST]);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_tdma_efr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_umts_amr_2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_umts_amr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_hr_amr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_fr_amr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_gsm_efr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_gsm_hr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_gsm_fr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
length--;
if (length > 0)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, curr_offset << 3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_ohr_amr_wb, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_ofr_amr_wb, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_ohr_amr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_umts_amr_wb, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_fr_amr_wb, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_dtap_codec_pdc_efr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
length--;
}
}
curr_offset = curr_offset + length;
}
return(curr_offset-offset);
}
guint16
de_serv_cat(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_serv_cat_b7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_serv_cat_b6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_serv_cat_b5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_serv_cat_b4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_serv_cat_b3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_serv_cat_b2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_dtap_serv_cat_b1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return len;
}
static guint16
de_cp_user_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *rp_tvb;
curr_offset = offset;
proto_tree_add_text(tree, tvb, curr_offset, len,
"RPDU (not displayed)");
rp_tvb = tvb_new_subset(tvb, curr_offset, len, len);
call_dissector(rp_handle, rp_tvb, pinfo, g_tree);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(curr_offset - offset);
}
static guint16
de_cp_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len)
{
guint8 oct;
guint32 curr_offset;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 17: str = "Network failure"; break;
case 22: str = "Congestion"; break;
case 81: str = "Invalid Transaction Identifier value"; break;
case 95: str = "Semantically incorrect message"; break;
case 96: str = "Invalid mandatory information"; break;
case 97: str = "Message type non-existent or not implemented"; break;
case 98: str = "Message not compatible with the short message protocol state"; break;
case 99: str = "Information element non-existent or not implemented"; break;
case 111: str = "Protocol error, unspecified"; break;
default:
str = "Reserved, treat as Protocol error, unspecified";
break;
}
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Cause: (%u) %s",
oct,
str);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - (%u) %s", oct, str);
return(curr_offset - offset);
}
static guint16
de_tp_sub_channel(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset) & 0x3f;
if ((oct & 0x38) == 0x38)
str = "I";
else if ((oct & 0x38) == 0x18)
str = "F";
else if ((oct & 0x38) == 0x10)
str = "E";
else if ((oct & 0x38) == 0x08)
str = "D";
else if ((oct & 0x3c) == 0x04)
str = "C";
else if ((oct & 0x3e) == 0x02)
str = "B";
else if ((oct & 0x3e) == 0x00)
str = "A";
else
str = "unknown";
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Test Loop %s",str);
if (oct & 0x01)
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Only one TCH active or sub-channel 0 of two half rate channels is to be looped");
else
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"Sub-channel 1 of two half rate channels is to be looped");
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
if ((oct & 0xF0) == 0x80)
proto_tree_add_text(tree,tvb, curr_offset, 1, "Acknowledgment element: %d",oct&0x01);
else
proto_tree_add_text(tree,tvb, curr_offset, 1, "No acknowledgment element present");
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_loop_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct & 0x03)
{
case 0x00:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Channel coding not needed. The Burst-by-Burst loop is activated, type G");
break;
case 0x01:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Channel coding needed. Frame erasure is to be signalled, type H");
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Channel coding reserved (%d)",oct & 0x03);
break;
}
switch (oct & 0x1c)
{
case 0x00:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Multi-slot mechanism 1");
proto_tree_add_text(tree, tvb, curr_offset, 1, "Timeslot number %d",(oct & 0xe0)>>5);
break;
case 0x04:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Multi-slot mechanism 2");
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Loop mechanism reserved (%d)",(oct & 0x1c)>>2);
break;
}
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_loop_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct & 0x30)
{
case 0x00:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Channel coding not needed. The Burst-by-Burst loop is activated, type G");
break;
case 0x10:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Channel coding needed. Frame erasure is to be signalled, type H");
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Channel coding reserved (%d)",(oct & 0x30)>>4);
break;
}
switch (oct & 0x0e)
{
case 0x00:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Multi-slot mechanism 1");
break;
case 0x02:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Multi-slot mechanism 2");
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Loop mechanism reserved (%d)",(oct & 0x0e)>>1);
break;
}
if (oct & 0x01)
proto_tree_add_text(tree, tvb, curr_offset, 1, "Multi-slot TCH loop was not closed due to error");
else
proto_tree_add_text(tree, tvb, curr_offset, 1, "Multi-slot TCH loop was closed successfully");
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_tested_device(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Normal operation (no tested device via DAI)");
break;
case 1:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Test of speech decoder / DTX functions (downlink)");
break;
case 2:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Test of speech encoder / DTX functions (uplink)");
break;
case 4:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Test of acoustic devices and A/D & D/A");
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 1, "Tested device reserved (%d)",oct);
break;
}
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_pdu_description(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint16 value;
curr_offset = offset;
value = tvb_get_ntohs(tvb, curr_offset);
curr_offset += 2;
if (value & 0x8000)
{
if ((value & 0xfff) == 0)
proto_tree_add_text(tree, tvb, curr_offset, 1, "Infinite number of PDUs to be transmitted in the TBF");
else
proto_tree_add_text(tree, tvb, curr_offset, 1, "%d PDUs to be transmitted in the TBF",value & 0xfff);
}
else
proto_tree_add_text(tree, tvb, curr_offset, 1, "PDU description reserved");
return(curr_offset - offset);
}
static guint16
de_tp_mode_flag(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
if (oct & 0x01)
proto_tree_add_text(tree, tvb, curr_offset, 1, "MS shall select the loop back option");
else
proto_tree_add_text(tree, tvb, curr_offset, 1, "MS shall itself generate the pseudorandom data");
proto_tree_add_text(tree, tvb, curr_offset, 1, "Downlink Timeslot Offset: timeslot number %d",(oct & 0x0e)>>1);
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_egprs_mode_flag(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
if (oct & 0x01)
proto_tree_add_text(tree, tvb, curr_offset, 1, "MS loops back blocks on the uplink using GMSK modulation only");
else
proto_tree_add_text(tree, tvb, curr_offset, 1, "MS loops back blocks on the uplink using either GMSK or 8-PSK modulation following the detected received modulation");
proto_tree_add_text(tree, tvb, curr_offset, 1, "Downlink Timeslot Offset: timeslot number %d",(oct & 0x0e)>>1);
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_ms_positioning_technology(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0:
proto_tree_add_text(tree, tvb, curr_offset, 1, "AGPS");
break;
case 1:
proto_tree_add_text(tree, tvb, curr_offset, 1, "AGNSS");
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 1, "MS positioning technology reserved (%d)",oct);
break;
}
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_ue_test_loop_mode(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
guint8 lb_setup_length,i,j;
guint16 value;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset+= 1;
switch (oct & 0x03)
{
case 0:
{
proto_tree_add_text(tree, tvb, curr_offset, 1, "UE test loop mode 1 loop back (loopback of RLC SDUs or PDCP SDUs)");
lb_setup_length = tvb_get_guint8(tvb, curr_offset);
curr_offset += 1;
for (i=0,j=0; (i<lb_setup_length) && (j<4); i+=3,j++)
{
proto_tree_add_text(tree, tvb, curr_offset, 1, "LB setup RB IE %d",j+1);
value = tvb_get_ntohs(tvb, curr_offset);
curr_offset += 2;
proto_tree_add_text(tree, tvb, curr_offset, 1, "Uplink RLC SDU size is %d bits",value);
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset+= 1;
proto_tree_add_text(tree, tvb, curr_offset, 1, "Radio Bearer %d",oct & 0x1f);
}
break;
}
case 1:
proto_tree_add_text(tree, tvb, curr_offset, 1, "UE test loop mode 2 loop back (loopback of transport block data and CRC bits)");
break;
case 2:
proto_tree_add_text(tree, tvb, curr_offset, 1, "UE test loop mode 3 RLC SDU counting (counting of received RLC SDUs)");
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset+= 1;
proto_tree_add_text(tree, tvb, curr_offset, 1, "MBMS short transmission identity %d",(oct & 0x1f)+1);
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 1, "UE test loop mode reserved (%d)",oct & 0x03);
break;
}
return(curr_offset - offset);
}
static guint16
de_tp_ue_positioning_technology(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0:
proto_tree_add_text(tree, tvb, curr_offset, 1, "AGPS");
break;
case 1:
proto_tree_add_text(tree, tvb, curr_offset, 1, "AGNSS");
break;
default:
proto_tree_add_text(tree, tvb, curr_offset, 1, "UE positioning technology reserved (%d)",oct);
break;
}
curr_offset+= 1;
return(curr_offset - offset);
}
static guint16
de_tp_rlc_sdu_counter_value(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 value;
curr_offset = offset;
value = tvb_get_ntohl(tvb, curr_offset);
curr_offset+= 4;
proto_tree_add_text(tree, tvb, curr_offset, 1, "UE received RLC SDU counter value %d",value);
return(curr_offset - offset);
}
static guint16
de_tp_epc_ue_test_loop_mode(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 bit_offset;
curr_offset = offset;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_ue_tl_mode, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
epc_test_loop_mode = tvb_get_guint8(tvb, curr_offset) & 0x03;
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_tp_epc_ue_tl_a_lb_setup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 count, nb_lb;
proto_item *item = NULL;
proto_tree *lb_setup_tree = NULL;
curr_offset = offset;
count = 0;
nb_lb = len / 3;
proto_tree_add_text(tree, tvb, curr_offset, len, "Number of LB entities: %d", nb_lb);
while ((count < nb_lb) && (count < 8)){
item = proto_tree_add_text(tree, tvb, curr_offset, 3, "LB entity %d", count);
lb_setup_tree = proto_item_add_subtree(item, ett_epc_ue_tl_a_lb_setup);
proto_tree_add_bits_item(lb_setup_tree, hf_gsm_a_dtap_epc_ue_tl_a_ul_sdu_size, tvb, curr_offset<<3, 16, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_bits_item(lb_setup_tree, hf_gsm_a_dtap_epc_ue_tl_a_drb, tvb, (curr_offset<<3)+3, 5, ENC_BIG_ENDIAN);
curr_offset++;
count++;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
return(len);
}
static guint16
de_tp_epc_ue_tl_b_lb_setup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_ue_tl_b_ip_pdu_delay, tvb, curr_offset<<3, 8, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_tp_epc_ue_tl_c_setup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_ue_tl_c_mbsfn_area_id, tvb, curr_offset<<3, 8, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_ue_tl_c_mch_id, tvb, (curr_offset<<3)+4, 4, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_ue_tl_c_lcid, tvb, (curr_offset<<3)+3, 5, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_tp_epc_ue_positioning_technology(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_ue_positioning_technology, tvb, curr_offset<<3, 8, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_tp_epc_mbms_packet_counter_value(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_mbms_packet_counter_value, tvb, curr_offset<<3, 32, ENC_BIG_ENDIAN);
curr_offset += 4;
return(curr_offset - offset);
}
static guint16
de_tp_epc_ellipsoid_point_with_alt(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 longitude;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_latitude_sign, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_degrees_latitude, tvb, (curr_offset<<3)+1, 23, ENC_BIG_ENDIAN);
curr_offset += 3;
longitude = tvb_get_ntoh24(tvb, curr_offset);
proto_tree_add_int_format(tree, hf_gsm_a_dtap_epc_degrees_longitude, tvb, curr_offset, 3, longitude,
"%s = %s: %d", decode_bits_in_field(curr_offset<<3, 24, longitude),
proto_registrar_get_name(hf_gsm_a_dtap_epc_degrees_longitude), longitude-8388608);
curr_offset += 3;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_altitude_dir, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_altitude, tvb, (curr_offset<<3)+1, 15, ENC_BIG_ENDIAN);
curr_offset += 2;
return(curr_offset - offset);
}
static guint16
de_tp_epc_horizontal_velocity(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_bearing, tvb, curr_offset<<3, 9, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_horizontal_speed, tvb, (curr_offset<<3)+9, 11, ENC_BIG_ENDIAN);
curr_offset += 3;
return(curr_offset - offset);
}
static guint16
de_tp_epc_gnss_tod_msec(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_dtap_epc_gnss_tod_msec, tvb, (curr_offset<<3)+2, 22, ENC_BIG_ENDIAN);
curr_offset += 3;
return(curr_offset - offset);
}
static void
dtap_mm_auth_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
guint8 oct;
proto_tree *subtree;
proto_item *item;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_CIPH_KEY_SEQ_NUM, &gsm_common_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_CIPH_KEY_SEQ_NUM]);
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
switch (oct & 0x07)
{
case 0x07:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Ciphering Key Sequence Number: No key is available",
a_bigbuf);
break;
default:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Ciphering Key Sequence Number: %u",
a_bigbuf,
oct & 0x07);
break;
}
curr_offset++;
curr_len--;
if ((signed)curr_len <= 0) return;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_AUTH_PARAM_RAND, " - UMTS challenge or GSM challenge");
ELEM_OPT_TLV(0x20, GSM_A_PDU_TYPE_DTAP, DE_AUTH_PARAM_AUTN, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_auth_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_AUTH_RESP_PARAM, NULL);
ELEM_OPT_TLV(0x21, GSM_A_PDU_TYPE_DTAP, DE_AUTH_RESP_PARAM_EXT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_auth_fail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_REJ_CAUSE, NULL);
ELEM_OPT_TLV(0x22, GSM_A_PDU_TYPE_DTAP, DE_AUTH_FAIL_PARAM, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_cm_reestab_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
guint8 oct;
proto_tree *subtree;
proto_item *item;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_CIPH_KEY_SEQ_NUM, &gsm_common_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_CIPH_KEY_SEQ_NUM]);
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
switch (oct & 0x07)
{
case 0x07:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Ciphering Key Sequence Number: No key is available",
a_bigbuf);
break;
default:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Ciphering Key Sequence Number: %u",
a_bigbuf,
oct & 0x07);
break;
}
curr_offset++;
curr_len--;
if ((signed)curr_len <= 0) return;
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TV(0x13, GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_OPT_TV_SHORT(0xD0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_cm_srvc_prompt(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_PD_SAPI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_cm_srvc_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_REJ_CAUSE, NULL);
ELEM_OPT_TLV(0x36, GSM_A_PDU_TYPE_DTAP, DE_MM_TIMER, " - T3246 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_abort(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_REJ_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_cm_srvc_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
guint8 oct;
proto_tree *subtree;
proto_item *item;
const gchar *str;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
oct = tvb_get_guint8(tvb, curr_offset);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_CIPH_KEY_SEQ_NUM, &gsm_common_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_CIPH_KEY_SEQ_NUM]);
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x70, 8);
switch ((oct & 0x70) >> 4)
{
case 0x07:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Ciphering Key Sequence Number: No key is available",
a_bigbuf);
break;
default:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Ciphering Key Sequence Number: %u",
a_bigbuf,
(oct & 0x70) >> 4);
break;
}
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_CM_SRVC_TYPE, &gsm_dtap_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_CM_SRVC_TYPE]);
switch (oct & 0x0f)
{
case 0x01: str = "Mobile originating call establishment or packet mode connection establishment"; break;
case 0x02: str = "Emergency call establishment"; break;
case 0x04: str = "Short message service"; break;
case 0x08: str = "Supplementary service activation"; break;
case 0x09: str = "Voice group call establishment"; break;
case 0x0a: str = "Voice broadcast call establishment"; break;
case 0x0b: str = "Location Services"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Service Type: (%u) %s",
a_bigbuf,
oct & 0x0f,
str);
curr_offset++;
curr_len--;
if ((signed)curr_len <= 0) return;
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TV_SHORT(0x80, GSM_A_PDU_TYPE_COMMON, DE_PRIO, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_DTAP, DE_ADD_UPD_PARAMS, NULL);
ELEM_OPT_TV_SHORT(0xD0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_id_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint8 oct;
guint32 curr_offset;
guint curr_len;
proto_tree *subtree;
proto_item *item;
const gchar *str;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_ID_TYPE, &gsm_dtap_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_ID_TYPE]);
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 1, ENC_BIG_ENDIAN);
switch (oct & 0x07)
{
case 1: str = "IMSI"; break;
case 2: str = "IMEI"; break;
case 3: str = "IMEISV"; break;
case 4: str = "TMSI"; break;
case 5: str = "P-TMSI, RAI, P-TMSI signature"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Type of identity: %s",
a_bigbuf,
str);
curr_offset++;
curr_len--;
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_id_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TV_SHORT(0xE0, GSM_A_PDU_TYPE_GM, DE_PTMSI_TYPE, NULL);
ELEM_OPT_TLV( 0x1B, GSM_A_PDU_TYPE_GM, DE_RAI_2, " - Routing area identification");
ELEM_OPT_TLV( 0x19, GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG_2, " - P-TMSI signature");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_imsi_det_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_MS_CM_1, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_loc_upd_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_OPT_TLV(0x17, GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_T(0xa1, GSM_A_PDU_TYPE_DTAP, DE_FOP, NULL);
ELEM_OPT_T(0xa2, GSM_A_PDU_TYPE_DTAP, DE_CTS_PERM, NULL);
ELEM_OPT_TLV(0x4a, GSM_A_PDU_TYPE_COMMON, DE_PLMN_LIST, " Equivalent");
ELEM_OPT_TLV(0x34, GSM_A_PDU_TYPE_DTAP, DE_EMERGENCY_NUM_LIST, NULL);
ELEM_OPT_TLV(0x35, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - Per MS T3212");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_loc_upd_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_REJ_CAUSE, NULL);
ELEM_OPT_TLV(0x36, GSM_A_PDU_TYPE_DTAP, DE_MM_TIMER, " - T3246 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_loc_upd_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
guint8 oct;
proto_tree *subtree;
proto_item *item;
const gchar *str;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
oct = tvb_get_guint8(tvb, curr_offset);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_CIPH_KEY_SEQ_NUM, &gsm_common_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_CIPH_KEY_SEQ_NUM]);
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct, 0x70, 8);
switch ((oct & 0x70) >> 4)
{
case 0x07:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Ciphering Key Sequence Number: No key is available",
a_bigbuf);
break;
default:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Ciphering Key Sequence Number: %u",
a_bigbuf,
(oct & 0x70) >> 4);
break;
}
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_LOC_UPD_TYPE, &gsm_dtap_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_LOC_UPD_TYPE]);
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Follow-On Request (FOR): %s",
a_bigbuf,
(oct & 0x08) ? "Follow-on request pending" : "No follow-on request pending");
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+5, 1, ENC_BIG_ENDIAN);
switch (oct & 0x03)
{
case 0: str = "Normal"; break;
case 1: str = "Periodic"; break;
case 2: str = "IMSI attach"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x03, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Updating Type: %s",
a_bigbuf,
str);
proto_item_append_text(item, " - %s", str);
curr_offset++;
curr_len--;
if ((signed)curr_len <= 0) return;
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_MS_CM_1, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TLV(0x33, GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, " - Mobile station classmark for UMTS");
ELEM_OPT_TV_SHORT(0xc0, GSM_A_PDU_TYPE_DTAP, DE_ADD_UPD_PARAMS, NULL);
ELEM_OPT_TV_SHORT(0xD0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_COMMON, DE_MS_NET_FEAT_SUP, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
dtap_mm_mm_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_OPT_TLV(0x43, GSM_A_PDU_TYPE_DTAP, DE_NETWORK_NAME, " - Full Name");
ELEM_OPT_TLV(0x45, GSM_A_PDU_TYPE_DTAP, DE_NETWORK_NAME, " - Short Name");
ELEM_OPT_TV(0x46, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE, " - Local");
ELEM_OPT_TV(0x47, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE_TIME, " - Universal Time and Local Time Zone");
ELEM_OPT_TLV(0x48, GSM_A_PDU_TYPE_DTAP, DE_LSA_ID, NULL);
ELEM_OPT_TLV(0x49, GSM_A_PDU_TYPE_DTAP, DE_DAY_SAVING_TIME, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_mm_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_REJ_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_mm_tmsi_realloc_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_alerting(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_OPT_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x1e, GSM_A_PDU_TYPE_DTAP, DE_PROG_IND, NULL);
ELEM_OPT_TLV(0x7e, GSM_A_PDU_TYPE_DTAP, DE_USER_USER, NULL);
ELEM_OPT_TLV(0x7f, GSM_A_PDU_TYPE_DTAP, DE_SS_VER_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_call_conf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_OPT_TV_SHORT(0xd0, GSM_A_PDU_TYPE_DTAP, DE_REPEAT_IND, " BC repeat indicator");
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, " 1");
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, " 2");
ELEM_OPT_TLV(0x08, GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
ELEM_OPT_TLV(0x15, GSM_A_PDU_TYPE_DTAP, DE_CC_CAP, NULL);
ELEM_OPT_TLV(0x2d, GSM_A_PDU_TYPE_DTAP, DE_SI, NULL);
ELEM_OPT_TLV(0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_call_proceed(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_OPT_TV_SHORT(0xd0, GSM_A_PDU_TYPE_DTAP, DE_REPEAT_IND, " BC repeat indicator");
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, " 1");
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, " 2");
ELEM_OPT_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x1e, GSM_A_PDU_TYPE_DTAP, DE_PROG_IND, NULL);
ELEM_OPT_TV_SHORT(0x80, GSM_A_PDU_TYPE_COMMON, DE_PRIO, NULL);
ELEM_OPT_TLV(0x2f, GSM_A_PDU_TYPE_DTAP, DE_NET_CC_CAP, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_congestion_control(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
guint8 oct;
proto_tree *subtree;
proto_item *item;
const gchar *str;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 4, ENC_BIG_ENDIAN);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_CONGESTION, &gsm_dtap_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_dtap_elem[DE_CONGESTION]);
switch (oct & 0x0f)
{
case 0: str = "Receiver ready"; break;
case 15: str = "Receiver not ready"; break;
default:
str = "Reserved";
break;
}
other_decode_bitfield_value(a_bigbuf, oct, 0x0f, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s = Congestion level: %s",
a_bigbuf,
str);
curr_offset++;
curr_len--;
if ((signed)curr_len <= 0) return;
ELEM_OPT_TLV(0x08, GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_connect(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_OPT_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x1e, GSM_A_PDU_TYPE_DTAP, DE_PROG_IND, NULL);
ELEM_OPT_TLV(0x4c, GSM_A_PDU_TYPE_DTAP, DE_CONN_NUM, NULL);
ELEM_OPT_TLV(0x4d, GSM_A_PDU_TYPE_DTAP, DE_CONN_SUB_ADDR, NULL);
ELEM_OPT_TLV(0x7e, GSM_A_PDU_TYPE_DTAP, DE_USER_USER, NULL);
ELEM_OPT_TLV(0x7f, GSM_A_PDU_TYPE_DTAP, DE_SS_VER_IND, NULL);
ELEM_OPT_TLV(0x2d, GSM_A_PDU_TYPE_DTAP, DE_SI, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_disconnect(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
ELEM_OPT_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x1e, GSM_A_PDU_TYPE_DTAP, DE_PROG_IND, NULL);
ELEM_OPT_TLV(0x7e, GSM_A_PDU_TYPE_DTAP, DE_USER_USER, NULL);
ELEM_OPT_TLV(0x7b, GSM_A_PDU_TYPE_DTAP, DE_ALLOWED_ACTIONS, NULL);
ELEM_OPT_TLV(0x7f, GSM_A_PDU_TYPE_DTAP, DE_SS_VER_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_emerg_setup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, NULL);
ELEM_OPT_TLV(0x2d, GSM_A_PDU_TYPE_DTAP, DE_SI, NULL);
ELEM_OPT_TLV(0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, NULL);
ELEM_OPT_TLV(0x2e, GSM_A_PDU_TYPE_DTAP, DE_SERV_CAT, " - Emergency category");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_facility(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x7f, GSM_A_PDU_TYPE_DTAP, DE_SS_VER_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_hold_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_modify(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, NULL);
ELEM_OPT_TLV(0x7c, GSM_A_PDU_TYPE_DTAP, DE_LLC, NULL);
ELEM_OPT_TLV(0x7d, GSM_A_PDU_TYPE_DTAP, DE_HLC, NULL);
ELEM_OPT_T(0xa3, GSM_A_PDU_TYPE_DTAP, DE_REV_CALL_SETUP_DIR, NULL);
ELEM_OPT_T(0xa4, GSM_A_PDU_TYPE_DTAP, DE_NET_INIT_SERV_UPG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_modify_complete(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, NULL);
ELEM_OPT_TLV(0x7c, GSM_A_PDU_TYPE_DTAP, DE_LLC, NULL);
ELEM_OPT_TLV(0x7d, GSM_A_PDU_TYPE_DTAP, DE_HLC, NULL);
ELEM_OPT_T(0xa3, GSM_A_PDU_TYPE_DTAP, DE_REV_CALL_SETUP_DIR, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_modify_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
ELEM_OPT_TLV(0x7c, GSM_A_PDU_TYPE_DTAP, DE_LLC, NULL);
ELEM_OPT_TLV(0x7d, GSM_A_PDU_TYPE_DTAP, DE_HLC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_notify(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_NOT_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_progress(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_PROG_IND, NULL);
ELEM_OPT_TLV(0x7e, GSM_A_PDU_TYPE_DTAP, DE_USER_USER, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_cc_est(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_SETUP_CONTAINER, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_cc_est_conf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_OPT_TV_SHORT(0xd0, GSM_A_PDU_TYPE_DTAP, DE_REPEAT_IND, " Repeat indicator");
ELEM_MAND_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, " 1");
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, " 2");
ELEM_OPT_TLV(0x08, GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
ELEM_OPT_TLV(0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_release(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_OPT_TLV(0x08, GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
ELEM_OPT_TLV(0x08, GSM_A_PDU_TYPE_DTAP, DE_CAUSE, " 2");
ELEM_OPT_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x7e, GSM_A_PDU_TYPE_DTAP, DE_USER_USER, NULL);
ELEM_OPT_TLV(0x7f, GSM_A_PDU_TYPE_DTAP, DE_SS_VER_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_recall(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_RECALL_TYPE, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_release_complete(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_OPT_TLV(0x08, GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
ELEM_OPT_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x7e, GSM_A_PDU_TYPE_DTAP, DE_USER_USER, NULL);
ELEM_OPT_TLV(0x7f, GSM_A_PDU_TYPE_DTAP, DE_SS_VER_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_retrieve_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_setup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_OPT_TV_SHORT(0xd0, GSM_A_PDU_TYPE_DTAP, DE_REPEAT_IND, " BC repeat indicator");
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, " 1");
ELEM_OPT_TLV(0x04, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, " 2");
ELEM_OPT_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x1e, GSM_A_PDU_TYPE_DTAP, DE_PROG_IND, NULL);
ELEM_OPT_TV(0x34, GSM_A_PDU_TYPE_DTAP, DE_SIGNAL, NULL);
ELEM_OPT_TLV(0x5c, GSM_A_PDU_TYPE_DTAP, DE_CLG_PARTY_BCD_NUM, NULL);
ELEM_OPT_TLV(0x5d, GSM_A_PDU_TYPE_DTAP, DE_CLG_PARTY_SUB_ADDR, NULL);
ELEM_OPT_TLV(0x5e, GSM_A_PDU_TYPE_DTAP, DE_CLD_PARTY_BCD_NUM, NULL);
ELEM_OPT_TLV(0x6d, GSM_A_PDU_TYPE_DTAP, DE_CLD_PARTY_SUB_ADDR, NULL);
ELEM_OPT_TLV(0x74, GSM_A_PDU_TYPE_DTAP, DE_RED_PARTY_BCD_NUM, NULL);
ELEM_OPT_TLV(0x75, GSM_A_PDU_TYPE_DTAP, DE_RED_PARTY_SUB_ADDR, NULL);
ELEM_OPT_TV_SHORT(0xd0, GSM_A_PDU_TYPE_DTAP, DE_REPEAT_IND, " LLC repeat indicator");
ELEM_OPT_TLV(0x7c, GSM_A_PDU_TYPE_DTAP, DE_LLC, " 1");
ELEM_OPT_TLV(0x7c, GSM_A_PDU_TYPE_DTAP, DE_LLC, " 2");
ELEM_OPT_TV_SHORT(0xd0, GSM_A_PDU_TYPE_DTAP, DE_REPEAT_IND, " HLC repeat indicator");
ELEM_OPT_TLV(0x7d, GSM_A_PDU_TYPE_DTAP, DE_HLC, " 1");
ELEM_OPT_TLV(0x7d, GSM_A_PDU_TYPE_DTAP, DE_HLC, " 2");
ELEM_OPT_TLV(0x7e, GSM_A_PDU_TYPE_DTAP, DE_USER_USER, NULL);
ELEM_OPT_TV_SHORT(0x80, GSM_A_PDU_TYPE_COMMON, DE_PRIO, NULL);
ELEM_OPT_TLV(0x19, GSM_A_PDU_TYPE_DTAP, DE_ALERT_PATTERN, NULL);
ELEM_OPT_TLV(0x2f, GSM_A_PDU_TYPE_DTAP, DE_NET_CC_CAP, NULL);
ELEM_OPT_TLV(0x3a, GSM_A_PDU_TYPE_DTAP, DE_CAUSE_NO_CLI, NULL);
ELEM_OPT_TLV(0x41, GSM_A_PDU_TYPE_DTAP, DE_BEARER_CAP, NULL);
ELEM_OPT_TLV(0x7f, GSM_A_PDU_TYPE_DTAP, DE_SS_VER_IND, NULL);
ELEM_OPT_T(0xa1, GSM_A_PDU_TYPE_DTAP, DE_CLIR_SUP, NULL);
ELEM_OPT_T(0xa2, GSM_A_PDU_TYPE_DTAP, DE_CLIR_INV, NULL);
ELEM_OPT_TLV(0x15, GSM_A_PDU_TYPE_DTAP, DE_CC_CAP, NULL);
ELEM_OPT_TLV(0x1d, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, " $(CCBS)$ (advanced recall alignment)");
ELEM_OPT_TLV(0x1b, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, " (recall alignment Not essential) $(CCBS)$");
ELEM_OPT_TLV(0x2d, GSM_A_PDU_TYPE_DTAP, DE_SI, NULL);
ELEM_OPT_TLV(0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, NULL);
ELEM_OPT_T(0xA3, GSM_A_PDU_TYPE_DTAP, DE_REDIAL, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_start_cc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_OPT_TLV(0x15, GSM_A_PDU_TYPE_DTAP, DE_CC_CAP, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_start_dtmf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_TV(0x2c, GSM_A_PDU_TYPE_DTAP, DE_KEYPAD_FACILITY, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_start_dtmf_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_TV(0x2c, GSM_A_PDU_TYPE_DTAP, DE_KEYPAD_FACILITY, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_start_dtmf_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_FALSE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_CAUSE, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_CALL_STATE, NULL);
ELEM_OPT_TLV(0x24, GSM_A_PDU_TYPE_DTAP, DE_AUX_STATES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_cc_user_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_USER_USER, NULL);
ELEM_OPT_T(0xa0, GSM_A_PDU_TYPE_DTAP, DE_MORE_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_ss_register(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_TLV(0x1c, GSM_A_PDU_TYPE_DTAP, DE_FACILITY, NULL);
ELEM_OPT_TLV(0x7f, GSM_A_PDU_TYPE_DTAP, DE_SS_VER_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_sms_cp_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_CP_USER_DATA, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_sms_cp_error(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
is_uplink = IS_UPLINK_TRUE;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_CP_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_close_tch_loop_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_SUB_CHANNEL, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_open_loop_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
if (curr_len)
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_ACK, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_multi_slot_loop_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_LOOP_TYPE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_multi_slot_loop_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_LOOP_ACK, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_test_interface(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_TESTED_DEVICE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_gprs_test_mode_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_PDU_DESCRIPTION, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_MODE_FLAG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_egprs_start_radio_block_loopback_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EGPRS_MODE_FLAG, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_reset_ms_positioning_stored_information(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_MS_POSITIONING_TECHNOLOGY, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_close_ue_test_loop(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_UE_TEST_LOOP_MODE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_reset_ue_positioning_stored_information(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_UE_POSITIONING_TECHNOLOGY, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_ue_test_loop_mode_3_rlc_sdu_counter_response(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_RLC_SDU_COUNTER_VALUE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_epc_close_ue_test_loop(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_UE_TEST_LOOP_MODE, NULL);
switch (epc_test_loop_mode)
{
case 0:
ELEM_MAND_LV(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_UE_TL_A_LB_SETUP, NULL);
break;
case 1:
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_UE_TL_B_LB_SETUP, NULL);
break;
case 2:
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_UE_TL_C_SETUP, NULL);
break;
default:
break;
}
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_epc_activate_test_mode(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_UE_TEST_LOOP_MODE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_epc_reset_ue_positioning_stored_information(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_UE_POSITIONING_TECHNOLOGY, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_epc_test_loop_mode_c_mbms_packet_counter_response(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_MBMS_PACKET_COUNTER_VALUE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_tp_epc_update_ue_location_information(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_len = len;
curr_offset = offset;
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_ELLIPSOID_POINT_WITH_ALT, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_HORIZONTAL_VELOCITY, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_DTAP, DE_TP_EPC_GNSS_TOD_MSEC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dissect_dtap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
static gsm_a_tap_rec_t tap_rec[4];
static gsm_a_tap_rec_t *tap_p;
static guint tap_current = 0;
void (*dtap_msg_fcn)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len);
guint8 oct;
guint8 pd;
guint32 offset;
guint32 len;
guint32 oct_1, oct_2;
gint idx;
proto_item *dtap_item = NULL;
proto_tree *dtap_tree = NULL;
proto_item *oct_1_item = NULL;
proto_tree *pd_tree = NULL;
const gchar *msg_str;
gint ett_tree;
gint ti;
int hf_idx;
gboolean nsd;
len = tvb_length(tvb);
if (len < 2)
{
call_dissector(data_handle, tvb, pinfo, tree);
return;
}
col_append_str(pinfo->cinfo, COL_INFO, "(DTAP) ");
tap_current++;
if (tap_current >= 4)
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
offset = 0;
oct_2 = 0;
g_tree = tree;
oct_1 = tvb_get_guint8(tvb, offset++);
if ((((oct_1 & DTAP_TI_MASK) >> 4) & DTAP_TIE_PRES_MASK) == DTAP_TIE_PRES_MASK)
{
oct_2 = tvb_get_guint8(tvb, offset++);
}
oct = tvb_get_guint8(tvb, offset);
pd = oct_1 & DTAP_PD_MASK;
ti = -1;
msg_str = NULL;
ett_tree = -1;
hf_idx = -1;
dtap_msg_fcn = NULL;
nsd = FALSE;
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ",val_to_str_const(pd,gsm_a_pd_short_str_vals,"unknown"));
switch (pd)
{
case 3:
msg_str = try_val_to_str_idx((guint32) (oct & DTAP_CC_IEI_MASK), gsm_a_dtap_msg_cc_strings, &idx);
if (msg_str != NULL)
{
ett_tree = ett_gsm_dtap_msg_cc[idx];
dtap_msg_fcn = dtap_msg_cc_fcn[idx];
}
hf_idx = hf_gsm_a_dtap_msg_cc_type;
ti = (oct_1 & DTAP_TI_MASK) >> 4;
nsd = TRUE;
break;
case 5:
msg_str = try_val_to_str_idx((guint32) (oct & DTAP_MM_IEI_MASK), gsm_a_dtap_msg_mm_strings, &idx);
if (msg_str != NULL)
{
ett_tree = ett_gsm_dtap_msg_mm[idx];
dtap_msg_fcn = dtap_msg_mm_fcn[idx];
}
hf_idx = hf_gsm_a_dtap_msg_mm_type;
nsd = TRUE;
break;
case 6:
get_rr_msg_params(oct, &msg_str, &ett_tree, &hf_idx, &dtap_msg_fcn);
break;
case 8:
get_gmm_msg_params(oct, &msg_str, &ett_tree, &hf_idx, &dtap_msg_fcn);
break;
case 9:
msg_str = try_val_to_str_idx((guint32) (oct & DTAP_SMS_IEI_MASK), gsm_a_dtap_msg_sms_strings, &idx);
hf_idx = hf_gsm_a_dtap_msg_sms_type;
if (msg_str != NULL)
{
ett_tree = ett_gsm_dtap_msg_sms[idx];
dtap_msg_fcn = dtap_msg_sms_fcn[idx];
}
ti = (oct_1 & DTAP_TI_MASK) >> 4;
break;
case 10:
get_sm_msg_params(oct, &msg_str, &ett_tree, &hf_idx, &dtap_msg_fcn);
ti = (oct_1 & DTAP_TI_MASK) >> 4;
break;
case 11:
msg_str = try_val_to_str_idx((guint32) (oct & DTAP_SS_IEI_MASK), gsm_a_dtap_msg_ss_strings, &idx);
hf_idx = hf_gsm_a_dtap_msg_ss_type;
if (msg_str != NULL)
{
ett_tree = ett_gsm_dtap_msg_ss[idx];
dtap_msg_fcn = dtap_msg_ss_fcn[idx];
}
ti = (oct_1 & DTAP_TI_MASK) >> 4;
nsd = TRUE;
break;
case 15:
msg_str = try_val_to_str_idx((guint32) (oct & DTAP_TP_IEI_MASK), gsm_a_dtap_msg_tp_strings, &idx);
hf_idx = hf_gsm_a_dtap_msg_tp_type;
if (msg_str != NULL)
{
ett_tree = ett_gsm_dtap_msg_tp[idx];
dtap_msg_fcn = dtap_msg_tp_fcn[idx];
}
nsd = TRUE;
break;
default:
return;
}
sccp_msg = pinfo->sccp_info;
if (sccp_msg && sccp_msg->data.co.assoc) {
sccp_assoc = sccp_msg->data.co.assoc;
} else {
sccp_assoc = NULL;
sccp_msg = NULL;
}
if (msg_str == NULL)
{
dtap_item =
proto_tree_add_protocol_format(tree, proto_a_dtap, tvb, 0, len,
"GSM A-I/F DTAP - Unknown DTAP Message Type (0x%02x)",
oct);
dtap_tree = proto_item_add_subtree(dtap_item, ett_dtap_msg);
if (sccp_msg && !sccp_msg->data.co.label) {
sccp_msg->data.co.label = se_strdup_printf("DTAP (0x%02x)",oct);
}
}
else
{
dtap_item =
proto_tree_add_protocol_format(tree, proto_a_dtap, tvb, 0, -1,
"GSM A-I/F DTAP - %s",
msg_str);
dtap_tree = proto_item_add_subtree(dtap_item, ett_tree);
if (sccp_msg && !sccp_msg->data.co.label) {
sccp_msg->data.co.label = se_strdup(msg_str);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", msg_str);
col_set_fence(pinfo->cinfo, COL_INFO);
}
oct_1_item =
proto_tree_add_text(dtap_tree,
tvb, 0, 1,
"Protocol Discriminator: %s",
val_to_str(pd, protocol_discriminator_vals, "Unknown (%u)"));
pd_tree = proto_item_add_subtree(oct_1_item, ett_dtap_oct_1);
proto_tree_add_item(pd_tree, hf_gsm_a_L3_protocol_discriminator, tvb, 0, 1, ENC_BIG_ENDIAN);
if (ti == -1)
{
proto_tree_add_item(pd_tree, hf_gsm_a_skip_ind, tvb, 0, 1, ENC_BIG_ENDIAN);
}
else
{
other_decode_bitfield_value(a_bigbuf, oct_1, 0x80, 8);
proto_tree_add_text(pd_tree,
tvb, 0, 1,
"%s = TI flag: %s",
a_bigbuf,
((oct_1 & 0x80) ? "allocated by receiver" : "allocated by sender"));
if ((ti & DTAP_TIE_PRES_MASK) == DTAP_TIE_PRES_MASK)
{
other_decode_bitfield_value(a_bigbuf, oct_1, 0x70, 8);
proto_tree_add_text(pd_tree,
tvb, 0, 1,
"%s = TIO: The TI value is given by the TIE in octet 2",
a_bigbuf);
}
else
{
other_decode_bitfield_value(a_bigbuf, oct_1, 0x70, 8);
proto_tree_add_text(pd_tree,
tvb, 0, 1,
"%s = TIO: %u",
a_bigbuf,
ti & DTAP_TIE_PRES_MASK);
}
}
if ((ti != -1) &&
(ti & DTAP_TIE_PRES_MASK) == DTAP_TIE_PRES_MASK)
{
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, 1, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct_2, DTAP_TIE_MASK, 8);
proto_tree_add_text(pd_tree,
tvb, 1, 1,
"%s = TIE: %u",
a_bigbuf,
oct_2 & DTAP_TIE_MASK);
}
if ((pinfo->p2p_dir == P2P_DIR_RECV) &&
nsd)
{
}
if((pd==5)||(pd==3)||(pd==10)){
proto_tree_add_item(dtap_tree, hf_gsm_a_seq_no, tvb, offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(dtap_tree, hf_idx, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tap_p->pdu_type = GSM_A_PDU_TYPE_DTAP;
tap_p->message_type = (nsd ? (oct & 0x3f) : oct);
tap_p->protocol_disc = (gsm_a_pd_str_e)pd;
tap_queue_packet(gsm_a_tap, pinfo, tap_p);
if (msg_str == NULL) return;
if (offset >= len) return;
if (dtap_msg_fcn == NULL)
{
proto_tree_add_text(dtap_tree,
tvb, offset, len - offset,
"Message Elements");
}
else
{
(*dtap_msg_fcn)(tvb, dtap_tree, pinfo, offset, len - offset);
}
}
void
proto_register_gsm_a_dtap(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] =
{
{ &hf_gsm_a_seq_no,
{ "Sequence number", "gsm_a.dtap.seq_no",
FT_UINT8, BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_msg_mm_type,
{ "DTAP Mobility Management Message Type", "gsm_a.dtap.msg_mm_type",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_msg_mm_strings), 0x3f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_msg_cc_type,
{ "DTAP Call Control Message Type", "gsm_a.dtap.msg_cc_type",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_msg_cc_strings), 0x3f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_msg_sms_type,
{ "DTAP Short Message Service Message Type", "gsm_a.dtap.msg_sms_type",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_msg_sms_strings), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_msg_ss_type,
{ "DTAP Non call Supplementary Service Message Type", "gsm_a.dtap.msg_ss_type",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_msg_ss_strings), 0x3f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_msg_tp_type,
{ "DTAP Tests Procedures Message Type", "gsm_a.dtap.msg_tp_type",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_msg_tp_strings), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_elem_id,
{ "Element ID", "gsm_a.dtap.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_cld_party_bcd_num,
{ "Called Party BCD Number", "gsm_a.dtap.cld_party_bcd_num",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_clg_party_bcd_num,
{ "Calling Party BCD Number", "gsm_a.dtap.clg_party_bcd_num",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_conn_num,
{ "Connected Number", "gsm_a.dtap.conn_num",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_red_party_bcd_num,
{ "Redirecting Party BCD Number", "gsm_a.dtap.red_party_bcd_num",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_cause,
{ "DTAP Cause", "gsm_a.dtap.cause",
FT_UINT8, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_type_of_number,
{ "Type of number", "gsm_a.dtap.type_of_number",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_type_of_number_values), 0x70,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_numbering_plan_id,
{ "Numbering plan identification", "gsm_a.dtap.numbering_plan_id",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_numbering_plan_id_values), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_present_ind,
{ "Presentation indicator", "gsm_a.dtap.present_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_present_ind_values), 0x60,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_screening_ind,
{ "Screening indicator", "gsm_a.dtap.screening_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_screening_ind_values), 0x03,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_type_of_sub_addr,
{ "Type of subaddress", "gsm_a.dtap.type_of_sub_addr",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_type_of_sub_addr_values), 0x70,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_odd_even_ind,
{ "Odd/even indicator", "gsm_a.dtap.odd_even_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_odd_even_ind_values), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_lsa_id,
{ "LSA Identifier", "gsm_a.dtap.lsa_id",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_speech_vers_ind,
{ "Speech version indication", "gsm_a.dtap.speech_vers_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_speech_vers_ind_values), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_itc,
{ "Information transfer capability", "gsm_a.dtap.itc",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_itc_values), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_sysid,
{ "System Identification (SysID)", "gsm_a.dtap.sysid",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_sysid_values), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_bitmap_length,
{ "Bitmap Length", "gsm_a.dtap.bitmap_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_serv_cat_b7,
{ "Automatically initiated eCall", "gsm_a.dtap.serv_cat_b7",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_serv_cat_b6,
{ "Manually initiated eCall", "gsm_a.dtap.serv_cat_b6",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_serv_cat_b5,
{ "Mountain Rescue", "gsm_a.dtap.serv_cat_b5",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_serv_cat_b4,
{ "Marine Guard", "gsm_a.dtap.serv_cat_b4",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_serv_cat_b3,
{ "Fire Brigade", "gsm_a.dtap.serv_cat_b3",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_serv_cat_b2,
{ "Ambulance", "gsm_a.dtap.serv_cat_b2",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_serv_cat_b1,
{ "Police", "gsm_a.dtap.serv_cat_b1",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_csmo,
{ "CSMO", "gsm_a.dtap.csmo",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_dtap_csmo_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_csmt,
{ "CSMT", "gsm_a.dtap.csmt",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_dtap_csmt_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_mm_timer_unit,
{ "Unit", "gsm_a.dtap.mm_timer_unit",
FT_UINT8, BASE_DEC, VALS(gsm_a_dtap_mm_timer_unit_vals), 0xe0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_mm_timer_value,
{ "Timer value", "gsm_a.dtap.mm_timer_value",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_alerting_pattern,
{ "Alerting Pattern", "gsm_a.dtap.alerting_pattern",
FT_UINT8, BASE_DEC, VALS(gsm_a_alerting_pattern_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_ccbs_activation,
{ "CCBS Activation", "gsm_a.dtap.ccbs_activation",
FT_BOOLEAN, 8, TFS(&gsm_a_ccbs_activation_value), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_stream_identifier,
{ "Stream Identifier", "gsm_a.dtap.stream_identifier",
FT_UINT8, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_mcs,
{ "MCS", "gsm_a.dtap.mcs",
FT_BOOLEAN, 8, TFS(&gsm_a_mcs_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_cause_of_no_cli,
{ "Cause of no CLI", "gsm_a.dtap.cause_of_no_cli",
FT_UINT8, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_cause_ss_diagnostics,
{ "Supplementary Services Diagnostics", "gsm_a.dtap.cause_ss_diagnostics",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_cause_ss_diagnostics_vals), 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_tdma_efr,
{ "TDMA EFR", "gsm_a.dtap.codec.tdma_efr",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_umts_amr_2,
{ "UMTS AMR 2", "gsm_a.dtap.codec.umts_amr_2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_umts_amr,
{ "UMTS AMR", "gsm_a.dtap.codec.umts_amr",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_hr_amr,
{ "HR AMR", "gsm_a.dtap.codec.hr_amr",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_fr_amr,
{ "FR AMR", "gsm_a.dtap.codec.fr_amr",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_gsm_efr,
{ "GSM EFR", "gsm_a.dtap.codec.gsm_efr",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_gsm_hr,
{ "GSM HR", "gsm_a.dtap.codec.gsm_hr",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_gsm_fr,
{ "GSM FR", "gsm_a.dtap.codec.gsm_fr",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_ohr_amr_wb,
{ "OHR AMR-WB", "gsm_a.dtap.codec.ohr_amr_wb",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_ofr_amr_wb,
{ "OFR AMR-WB", "gsm_a.dtap.codec.ofr_amr_wb",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_ohr_amr,
{ "OHR AMR", "gsm_a.dtap.codec.ohr_amr",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_umts_amr_wb,
{ "UMTS AMR-WB", "gsm_a.dtap.codec.umts_amr_wb",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_fr_amr_wb,
{ "FR AMR-WB", "gsm_a.dtap.codec.fr_amr_wb",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_codec_pdc_efr,
{ "PDC EFR", "gsm_a.dtap.codec.pdc_efr",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_notification_description,
{ "Notification description", "gsm_a.dtap.notif_descr",
FT_UINT8, BASE_DEC, VALS(gsm_a_dtap_notification_description_vals), 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_emerg_num_info_length,
{ "Emergency Number Info length", "gsm_a.dtap.emerg_num_info_length",
FT_UINT8, BASE_DEC, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_emergency_bcd_num,
{ "Emergency BCD Number", "gsm_a.dtap.emergency_bcd_num",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_signal_value,
{ "Signal value", "gsm_a.dtap.signal_value",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_signal_value_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_recall_type,
{ "Recall type", "gsm_a.dtap.recall_type",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(gsm_a_dtap_recall_type_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_coding_standard,
{ "Coding standard", "gsm_a.dtap.coding_standard",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_coding_standard_vals), 0xc0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_call_state,
{ "Call state", "gsm_a.dtap.call_state",
FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_prog_coding_standard,
{ "Coding standard", "gsm_a.dtap.coding_standard",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_coding_standard_vals), 0x60,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_location,
{ "Location", "gsm_a.dtap.location",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_location_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_progress_description,
{ "Progress description", "gsm_a.dtap.progress_description",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_afi,
{ "Authority and Format Identifier", "gsm_a.dtap.afi",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &x213_afi_value_ext, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_rej_cause,
{ "Reject cause", "gsm_a.dtap.rej_cause",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_u2u_prot_discr,
{ "User-user protocol discriminator", "gsm_a.dtap.u2u_prot_discr",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(gsm_a_dtap_u2u_prot_discr_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_mcat,
{ "MCAT", "gsm_a.dtap.mcat",
FT_BOOLEAN, 8, TFS(&gsm_a_dtap_mcat_value), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_enicm,
{ "ENICM", "gsm_a.dtap.mcat",
FT_BOOLEAN, 8, TFS(&gsm_a_dtap_enicm_value), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_rand,
{ "RAND value", "gsm_a.dtap.rand",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_autn,
{ "AUTN value", "gsm_a.dtap.autn",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_sres,
{ "SRES value", "gsm_a.dtap.sres",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_xres,
{ "XRES value", "gsm_a.dtap.xres",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_auts,
{ "AUTS value", "gsm_a.dtap.auts",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_autn_sqn_xor_ak,
{ "SQN xor AK", "gsm_a.dtap.autn.sqn_xor_ak",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_autn_amf,
{ "AMF", "gsm_a.dtap.autn.amf",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_autn_mac,
{ "MAC", "gsm_a.dtap.autn.mac",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_auts_sqn_ms_xor_ak,
{ "SQN_MS xor AK", "gsm_a.dtap.auts.sqn_ms_xor_ak",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_auts_mac_s,
{ "MAC-S", "gsm_a.dtap.auts.mac_s",
FT_BYTES, FT_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_ue_tl_mode,
{ "UE test loop mode","gsm_a.dtap.epc.ue_tl_mode",
FT_UINT8,BASE_DEC, VALS(epc_ue_test_loop_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_ue_tl_a_ul_sdu_size,
{ "Uplink PDCP SDU size in bits","gsm_a.dtap.epc.ue_tl_a_ul_sdu_size",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_ue_tl_a_drb,
{ "Data Radio Bearer identity number","gsm_a.dtap.epc.ue_tl_a_drb",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_ue_tl_b_ip_pdu_delay,
{ "IP PDU delay in seconds","gsm_a.dtap.epc.ue_tl_b_ip_pdu_delay",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_ue_tl_c_mbsfn_area_id,
{ "MBSFN area identity","gsm_a.dtap.epc.ue_tl_c_mbsfn_area_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_ue_tl_c_mch_id,
{ "MCH identity","gsm_a.dtap.epc.ue_tl_c_mch_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_ue_tl_c_lcid,
{ "Logical channel identity","gsm_a.dtap.epc.ue_tl_c_lcid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_ue_positioning_technology,
{ "UE positioning technology","gsm_a.dtap.epc.ue_positioning_technology",
FT_UINT8, BASE_DEC, VALS(epc_ue_positioning_technology_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_mbms_packet_counter_value,
{ "MBMS packet counter value","gsm_a.dtap.epc.mbms_packet_counter_value",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_latitude_sign,
{ "Latitude Sign","gsm_a.dtap.epc.latitude_sign",
FT_BOOLEAN, BASE_NONE, TFS(&epc_latitude_sign_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_degrees_latitude,
{ "Degrees Latitude","gsm_a.dtap.epc.degrees_latitude",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_degrees_longitude,
{ "Degrees Longitude","gsm_a.dtap.epc.degrees_longitude",
FT_INT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_altitude_dir,
{ "Altitude Direction","gsm_a.dtap.epc.altitude_direction",
FT_BOOLEAN, BASE_NONE, TFS(&epc_altitude_dir_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_altitude,
{ "Altitude","gsm_a.dtap.epc.altitude",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_bearing,
{ "Bearing","gsm_a.dtap.epc.bearing",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_horizontal_speed,
{ "Horizontal Speed","gsm_a.dtap.epc.horizontal_speed",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_epc_gnss_tod_msec,
{ "GNSS-TOD-msec","gsm_a.dtap.epc.gnss_tod_msec",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
#define NUM_INDIVIDUAL_ELEMS 21
gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_GSM_DTAP_MSG_MM + NUM_GSM_DTAP_MSG_CC +
NUM_GSM_DTAP_MSG_SMS + NUM_GSM_DTAP_MSG_SS + NUM_GSM_DTAP_MSG_TP +
NUM_GSM_DTAP_ELEM];
ett[0] = &ett_dtap_msg;
ett[1] = &ett_dtap_oct_1;
ett[2] = &ett_cm_srvc_type;
ett[3] = &ett_gsm_enc_info;
ett[4] = &ett_bc_oct_3;
ett[5] = &ett_bc_oct_3a;
ett[6] = &ett_bc_oct_4;
ett[7] = &ett_bc_oct_5;
ett[8] = &ett_bc_oct_5a;
ett[9] = &ett_bc_oct_5b;
ett[10] = &ett_bc_oct_6;
ett[11] = &ett_bc_oct_6a;
ett[12] = &ett_bc_oct_6b;
ett[13] = &ett_bc_oct_6c;
ett[14] = &ett_bc_oct_6d;
ett[15] = &ett_bc_oct_6e;
ett[16] = &ett_bc_oct_6f;
ett[17] = &ett_bc_oct_6g;
ett[18] = &ett_bc_oct_7;
ett[19] = &ett_epc_ue_tl_a_lb_setup;
ett[20] = &ett_mm_timer;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_GSM_DTAP_MSG_MM; i++, last_offset++)
{
ett_gsm_dtap_msg_mm[i] = -1;
ett[last_offset] = &ett_gsm_dtap_msg_mm[i];
}
for (i=0; i < NUM_GSM_DTAP_MSG_CC; i++, last_offset++)
{
ett_gsm_dtap_msg_cc[i] = -1;
ett[last_offset] = &ett_gsm_dtap_msg_cc[i];
}
for (i=0; i < NUM_GSM_DTAP_MSG_SMS; i++, last_offset++)
{
ett_gsm_dtap_msg_sms[i] = -1;
ett[last_offset] = &ett_gsm_dtap_msg_sms[i];
}
for (i=0; i < NUM_GSM_DTAP_MSG_SS; i++, last_offset++)
{
ett_gsm_dtap_msg_ss[i] = -1;
ett[last_offset] = &ett_gsm_dtap_msg_ss[i];
}
for (i=0; i < NUM_GSM_DTAP_MSG_TP; i++, last_offset++)
{
ett_gsm_dtap_msg_tp[i] = -1;
ett[last_offset] = &ett_gsm_dtap_msg_tp[i];
}
for (i=0; i < NUM_GSM_DTAP_ELEM; i++, last_offset++)
{
ett_gsm_dtap_elem[i] = -1;
ett[last_offset] = &ett_gsm_dtap_elem[i];
}
proto_a_dtap =
proto_register_protocol("GSM A-I/F DTAP", "GSM DTAP", "gsm_a.dtap");
proto_register_field_array(proto_a_dtap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gsm_a_dtap", dissect_dtap, proto_a_dtap);
}
void
proto_reg_handoff_gsm_a_dtap(void)
{
dissector_handle_t dtap_handle;
dtap_handle = find_dissector("gsm_a_dtap");
dissector_add_uint("bssap.pdu_type", BSSAP_PDU_TYPE_DTAP, dtap_handle);
dissector_add_uint("ranap.nas_pdu", BSSAP_PDU_TYPE_DTAP, dtap_handle);
dissector_add_uint("llcgprs.sapi", 1 , dtap_handle);
dissector_add_uint("llcgprs.sapi", 7 , dtap_handle);
dissector_add_uint("lapdm.sapi", 0 , dtap_handle);
dissector_add_uint("lapdm.sapi", 3 , dtap_handle);
data_handle = find_dissector("data");
gsm_map_handle = find_dissector("gsm_map");
rp_handle = find_dissector("gsm_a_rp");
}
