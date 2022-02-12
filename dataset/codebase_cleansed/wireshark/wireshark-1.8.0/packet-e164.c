void
dissect_e164_number(tvbuff_t *tvb, proto_tree *tree, int offset, int length,e164_info_t e164_info)
{
switch (e164_info.e164_number_type){
case CALLING_PARTY_NUMBER :
proto_tree_add_string(tree, hf_E164_calling_party_number, tvb, offset,
length, e164_info.E164_number_str);
break;
case CALLED_PARTY_NUMBER :
proto_tree_add_string(tree, hf_E164_called_party_number, tvb, offset,
length, e164_info.E164_number_str);
break;
default:
break;
}
}
void
dissect_e164_cc(tvbuff_t *tvb, proto_tree *tree, int offset, gboolean bcd_coded){
int cc_offset;
guint8 address_digit_pair;
guint16 id_code;
guint8 cc_length;
guint8 length;
guint16 cc;
cc_offset = offset;
address_digit_pair = tvb_get_guint8(tvb, cc_offset);
if(!bcd_coded){
while ( address_digit_pair == 0 ) {
cc_offset = cc_offset + 1;
address_digit_pair = tvb_get_guint8(tvb, cc_offset);
}
cc = tvb_get_ntohs(tvb, cc_offset);
if (( address_digit_pair & 0xf0 ) != 0 ){
cc = cc >> 4;
}
}else{
cc = address_digit_pair &0x0f;
cc = cc << 4;
cc = cc | (address_digit_pair &0xf0)>>4;
cc = cc << 4;
address_digit_pair = tvb_get_guint8(tvb, cc_offset+1);
cc = cc | (address_digit_pair &0x0f);
}
switch ( cc & 0x0f00 ) {
case 0x0:
cc_length = 1;
break;
case 0x0100:
cc_length = 1;
break;
case 0x0200:
switch ( cc & 0x00f0 ) {
case 0:
case 0x70 :
cc_length = 2;
break;
default :
cc_length = 3;
break;
}
break;
case 0x0300 :
switch ( cc & 0x00f0 ) {
case 0 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x60 :
case 0x90 :
cc_length = 2;
break;
default :
cc_length = 3;
break;
}
break;
case 0x0400 :
switch ( cc & 0x00f0 ) {
case 0x20 :
cc_length = 3;
break;
default :
cc_length = 2;
break;
}
break;
case 0x0500 :
switch ( cc & 0x00f0 ) {
case 0 :
case 0x90 :
cc_length = 3;
break;
default :
cc_length = 2;
break;
}
break;
case 0x0600 :
switch ( cc & 0x00f0 ) {
case 0x70 :
case 0x80 :
case 0x90 :
cc_length = 3;
break;
default :
cc_length = 2;
break;
}
break;
case 0x0700 :
cc_length = 1;
break;
case 0x0800 :
switch ( cc & 0x00f0 ) {
case 0x10:
case 0x20:
case 0x40:
case 0x60:
cc_length = 2;
break;
default :
cc_length = 3;
break;
}
break;
case 0x0900 :
switch ( cc & 0x00f0 ) {
case 0 :
case 0x10 :
case 0x20 :
case 0x30 :
case 0x40 :
case 0x50 :
case 0x80 :
cc_length = 2;
break;
default :
cc_length = 3;
break;
}
break;
default :
cc_length = 0;
break;
}
switch ( cc_length ) {
case 1 :
cc = cc >> 8;
length = 1;
break;
case 2 :
cc = cc >> 4;
length = 1;
break;
default:
length = 2;
break;
}
proto_tree_add_text(tree, tvb, cc_offset, length,"Country Code: %x %s (length %u)", cc,
val_to_str(cc,E164_country_code_value,"unknown (%x)"), cc_length);
switch ( cc ) {
case 0x882 :
id_code = tvb_get_ntohs(tvb, cc_offset + 1);
id_code = (id_code & 0x0fff) >> 4;
proto_tree_add_text(tree,tvb, (cc_offset + 1), 2,"Identification Code: %x %s ",id_code,
val_to_str(id_code,E164_International_Networks_vals,"unknown (%x)"));
break;
default:
break;
}
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
NULL, HFILL }}
};
proto_e164 = proto_register_protocol(
"ITU-T E.164 number",
"E.164",
"e164");
proto_register_field_array(proto_e164, hf, array_length(hf));
}
