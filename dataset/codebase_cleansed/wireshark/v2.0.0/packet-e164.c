void
dissect_e164_number(tvbuff_t *tvb, proto_tree *tree, int offset, int length, e164_info_t e164_info)
{
proto_item *pi;
switch (e164_info.e164_number_type) {
case CALLING_PARTY_NUMBER:
proto_tree_add_string(tree, hf_E164_calling_party_number, tvb, offset,
length, e164_info.E164_number_str);
break;
case CALLED_PARTY_NUMBER:
proto_tree_add_string(tree, hf_E164_called_party_number, tvb, offset,
length, e164_info.E164_number_str);
break;
default:
break;
}
if (e164_info.nature_of_address == E164_NA_INTERNATIONAL_NUMBER) {
pi = proto_tree_add_string(tree, hf_E164_number, tvb, offset, length, e164_info.E164_number_str);
PROTO_ITEM_SET_HIDDEN(pi);
}
}
static gboolean
convert_bcd_to_dec(guint16 bcd, guint16 * dec)
{
gboolean rok = TRUE;
guint16 result = 0;
guint16 mult = 1;
while (bcd) {
if ((bcd & 0x0f) > 9)
rok = FALSE;
result += (bcd & 0x0f) * mult;
bcd >>= 4;
mult *= 10;
}
*dec = result;
return rok;
}
void
dissect_e164_cc(tvbuff_t *tvb, proto_tree *tree, int offset, e164_encoding_t encoding)
{
int cc_offset;
guint8 address_digit_pair;
guint16 id_code = 0;
guint8 cc_length;
guint8 length;
guint16 cc = 0;
gboolean bcd_ok = FALSE;
proto_item *item = NULL;
cc_offset = offset;
address_digit_pair = tvb_get_guint8(tvb, cc_offset);
switch (encoding) {
case E164_ENC_BINARY:
while (address_digit_pair == 0) {
cc_offset = cc_offset + 1;
address_digit_pair = tvb_get_guint8(tvb, cc_offset);
}
cc = tvb_get_ntohs(tvb, cc_offset);
if ((address_digit_pair & 0xf0) != 0) {
cc = cc >> 4;
}
break;
case E164_ENC_BCD:
cc = address_digit_pair &0x0f;
cc = cc << 4;
cc = cc | (address_digit_pair &0xf0)>>4;
cc = cc << 4;
if (tvb_bytes_exist(tvb, cc_offset+1, 1)) {
address_digit_pair = tvb_get_guint8(tvb, cc_offset+1);
cc = cc | (address_digit_pair &0x0f);
}
break;
case E164_ENC_UTF8:
cc = (tvb_get_guint8(tvb, cc_offset) - '0') << 8;
cc |= (tvb_get_guint8(tvb, cc_offset+1) - '0') << 4;
cc |= (tvb_get_guint8(tvb, cc_offset+2) - '0');
break;
}
switch (cc & 0x0f00) {
case 0x0:
cc_length = 1;
break;
case 0x0100:
cc_length = 1;
break;
case 0x0200:
switch (cc & 0x00f0) {
case 0:
case 0x70:
cc_length = 2;
break;
default:
cc_length = 3;
break;
}
break;
case 0x0300:
switch (cc & 0x00f0) {
case 0:
case 0x10:
case 0x20:
case 0x30:
case 0x40:
case 0x60:
case 0x90:
cc_length = 2;
break;
default:
cc_length = 3;
break;
}
break;
case 0x0400:
switch (cc & 0x00f0) {
case 0x20:
cc_length = 3;
break;
default:
cc_length = 2;
break;
}
break;
case 0x0500:
switch (cc & 0x00f0) {
case 0:
case 0x90:
cc_length = 3;
break;
default:
cc_length = 2;
break;
}
break;
case 0x0600:
switch (cc & 0x00f0) {
case 0x70:
case 0x80:
case 0x90:
cc_length = 3;
break;
default:
cc_length = 2;
break;
}
break;
case 0x0700:
cc_length = 1;
break;
case 0x0800:
switch (cc & 0x00f0) {
case 0x10:
case 0x20:
case 0x40:
case 0x60:
cc_length = 2;
break;
default:
cc_length = 3;
break;
}
break;
case 0x0900:
switch (cc & 0x00f0) {
case 0:
case 0x10:
case 0x20:
case 0x30:
case 0x40:
case 0x50:
case 0x80:
cc_length = 2;
break;
default:
cc_length = 3;
break;
}
break;
default:
cc_length = 0;
break;
}
switch (cc_length) {
case 1:
cc = cc >> 8;
length = 1;
break;
case 2:
cc = cc >> 4;
length = 1;
break;
default:
length = 2;
break;
}
bcd_ok = convert_bcd_to_dec(cc, &cc);
if (encoding == E164_ENC_UTF8)
item = proto_tree_add_uint(tree, hf_E164_country_code, tvb, cc_offset, cc_length, cc);
else
item = proto_tree_add_uint(tree, hf_E164_country_code, tvb, cc_offset, length, cc);
if (!bcd_ok) {
expert_add_info(NULL, item, &ei_E164_country_code_non_decimal);
}
switch (cc) {
case 881:
switch (encoding) {
case E164_ENC_BINARY:
id_code = tvb_get_guint8(tvb, cc_offset + 1) & 0x0f;
break;
case E164_ENC_BCD:
id_code = (tvb_get_guint8(tvb, cc_offset + 1) & 0xf0) >> 4;
break;
case E164_ENC_UTF8:
id_code = tvb_get_guint8(tvb, cc_offset + cc_length) - '0';
break;
}
bcd_ok = (id_code <= 9);
item = proto_tree_add_uint_format_value(tree, hf_E164_identification_code, tvb, (cc_offset + 1), 1,
id_code, "%d %s", id_code, val_to_str_const(id_code, E164_GMSS_vals, "Unknown"));
if (!bcd_ok) {
expert_add_info(NULL, item, &ei_E164_identification_code_non_decimal);
}
break;
case 882:
switch (encoding) {
case E164_ENC_BINARY:
id_code = tvb_get_ntohs(tvb, cc_offset + 1);
id_code = (id_code & 0x0ff0) >> 4;
break;
case E164_ENC_BCD:
id_code = tvb_get_guint8(tvb, cc_offset + 1) & 0xf0;
id_code |= tvb_get_guint8(tvb, cc_offset + 2) & 0x0f;
break;
case E164_ENC_UTF8:
id_code = (tvb_get_guint8(tvb, cc_offset+cc_length) - '0') << 4;
id_code |= (tvb_get_guint8(tvb, cc_offset+cc_length+1) - '0');
break;
}
bcd_ok = convert_bcd_to_dec(id_code, &id_code);
item = proto_tree_add_uint_format_value(tree, hf_E164_identification_code, tvb, (cc_offset + 1), 2,
id_code, "%d %s", id_code, val_to_str_ext_const(id_code, &E164_International_Networks_882_vals_ext, "Unknown"));
if (!bcd_ok) {
expert_add_info(NULL, item, &ei_E164_identification_code_non_decimal);
}
break;
case 883:
switch (encoding) {
case E164_ENC_BINARY:
id_code = tvb_get_ntohs(tvb, cc_offset + 1);
id_code = id_code & 0x0fff;
break;
case E164_ENC_BCD:
id_code = (tvb_get_guint8(tvb, cc_offset + 1) & 0xf0) << 4;
id_code |= (tvb_get_guint8(tvb, cc_offset + 2) & 0x0f) << 4;
id_code |= (tvb_get_guint8(tvb, cc_offset + 2) & 0xf0) >> 4;
break;
case E164_ENC_UTF8:
id_code = (tvb_get_guint8(tvb, cc_offset+cc_length) - '0') << 8;
id_code |= (tvb_get_guint8(tvb, cc_offset+cc_length+1) - '0') << 4;
id_code |= (tvb_get_guint8(tvb, cc_offset+cc_length+2) - '0');
break;
}
if ((id_code & 0x0ff0) == 0x510) {
switch (encoding) {
case E164_ENC_BINARY:
id_code = (id_code << 4) | ((tvb_get_guint8(tvb, cc_offset + 3) & 0xf0) >> 4);
break;
case E164_ENC_BCD:
id_code = (id_code << 4) | (tvb_get_guint8(tvb, cc_offset + 3) & 0x0f);
break;
case E164_ENC_UTF8:
id_code = (id_code << 4) | (tvb_get_guint8(tvb, cc_offset + cc_length + 3) - '0');
break;
}
bcd_ok = convert_bcd_to_dec(id_code, &id_code);
item = proto_tree_add_uint_format_value(tree, hf_E164_identification_code, tvb, (cc_offset + 1), 3,
id_code, "%d %s", id_code, val_to_str_const(id_code, E164_International_Networks_883_vals, "Unknown"));
if (!bcd_ok) {
expert_add_info(NULL, item, &ei_E164_identification_code_non_decimal);
}
} else {
bcd_ok = convert_bcd_to_dec(id_code, &id_code);
item = proto_tree_add_uint_format_value(tree, hf_E164_identification_code, tvb, (cc_offset + 1), 2,
id_code, "%d %s", id_code, val_to_str_const(id_code, E164_International_Networks_883_vals, "Unknown"));
if (!bcd_ok) {
expert_add_info(NULL, item, &ei_E164_identification_code_non_decimal);
}
}
break;
default:
break;
}
}
const gchar *
dissect_e164_msisdn(tvbuff_t *tvb, proto_tree *tree, int offset, int length, e164_encoding_t encoding)
{
proto_item *pi;
proto_tree *subtree;
const gchar *msisdn_str;
switch (encoding) {
case E164_ENC_UTF8:
msisdn_str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_UTF_8);
break;
case E164_ENC_BCD:
msisdn_str = tvb_bcd_dig_to_wmem_packet_str(tvb, offset, length, NULL, FALSE);
break;
case E164_ENC_BINARY:
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
pi = proto_tree_add_string(tree, hf_E164_number, tvb, offset, length, msisdn_str);
subtree = proto_item_add_subtree(pi, ett_e164_msisdn);
dissect_e164_cc(tvb, subtree, offset, encoding);
return msisdn_str;
}
void
proto_register_e164(void)
{
static hf_register_info hf[] = {
{ &hf_E164_calling_party_number,
{ "E.164 Calling party number digits", "e164.calling_party_number.digits",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_E164_called_party_number,
{ "E.164 Called party number digits", "e164.called_party_number.digits",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_E164_number,
{ "E.164 number (MSISDN)", "e164.msisdn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_E164_identification_code,
{ "Identification Code", "e164.identification_code",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_E164_country_code,
{ "Country Code", "e164.country_code",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &E164_country_code_value_ext, 0x0,
NULL, HFILL }},
};
static gint *ett_e164_array[] = {
&ett_e164_msisdn,
};
static ei_register_info ei[] = {
{ &ei_E164_country_code_non_decimal, { "e164.country_code.non_decimal", PI_MALFORMED, PI_WARN, "Country Code contains non-decimal digits", EXPFILL }},
{ &ei_E164_identification_code_non_decimal, { "e164.identification_code.non_decimal", PI_MALFORMED, PI_WARN, "Identification Code contains non-decimal digits", EXPFILL }},
};
expert_module_t* expert_e164;
proto_e164 = proto_register_protocol("ITU-T E.164 number", "E.164", "e164");
proto_register_field_array(proto_e164, hf, array_length(hf));
proto_register_subtree_array(ett_e164_array, array_length(ett_e164_array));
expert_e164 = expert_register_protocol(proto_e164);
expert_register_field_array(expert_e164, ei, array_length(ei));
}
