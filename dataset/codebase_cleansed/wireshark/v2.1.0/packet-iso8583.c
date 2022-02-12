static int ishex_str(const char* string, guint size)
{
char_cond(g_ascii_isxdigit(*c));
}
static int isnum_str(const char* string, unsigned int size)
{
char_cond( g_ascii_isdigit(*c) );
}
static int isalspec_str(const char* string, unsigned int size)
{
char_cond(g_ascii_isalpha(*c) || g_ascii_isspace(*c) || g_ascii_ispunct(*c));
}
static int isalpha_str(const char* string, unsigned int size)
{
char_cond( g_ascii_isalpha(*c));
}
static int isalnum_str(const char* string, unsigned int size)
{
char_cond( g_ascii_isalnum(*c));
}
static int isalnumspec_str(const char* string, unsigned int size)
{
char_cond(g_ascii_isalnum(*c) || g_ascii_isspace(*c) || g_ascii_ispunct(*c));
}
static int isnumspec_str(const char* string, unsigned int size)
{
char_cond(g_ascii_isdigit(*c) || g_ascii_isspace(*c) || g_ascii_ispunct(*c));
}
static int isspec_str(const char* string, unsigned int size)
{
char_cond(g_ascii_isspace(*c) || g_ascii_ispunct(*c));
}
static gboolean isstrtype_ok( int type, const char* string, unsigned int size)
{
switch(type)
{
case ISO_TA:
return isalpha_str(string, size);
case ISO_TN:
return isnum_str(string, size);
case ISO_TXN:
return ishex_str(string, size);
case ISO_TS:
return isspec_str(string, size);
case ISO_TAS:
return isalspec_str(string, size);
case ISO_TAN:
return isalnum_str(string, size);
case ISO_TANS:
return isalnumspec_str(string, size);
case ISO_TNS:
return isnumspec_str(string, size);
case ISO_TB:
return ishex_str(string, size);
case ISO_TZ:
if(charset_pref == ASCII_CHARSET)
return isalnumspec_str(string, size);
else
return ishex_str(string, size);
}
return 0;
}
static guint get_iso8583_msg_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
const guint enc = (len_byte_order == BIGEND)?ENC_BIG_ENDIAN:ENC_LITTLE_ENDIAN;
iso8583_len = tvb_get_guint16(tvb, offset, enc) + 2;
return iso8583_len;
}
static gchar* bin2hex(const guint8 *bin, enum bin2hex_enum type, guint32 len)
{
gchar* ret;
guint8 ch;
const guint8* str = bin;
guint32 size = len;
gchar* buff;
ret = (gchar *)wmem_alloc(wmem_packet_scope(), size + 1);
buff = ret;
if(type == TYPE_BCD)
{
if(size % 2)
{
ch = *str & 0x0f;
*buff = NIBBLE_2_ASCHEX(ch);
str++;
size--;
}
size = len/=2;
}
while(size-- > 0)
{
ch = (*str >> 4) & 0x0f;
*buff = NIBBLE_2_ASCHEX(ch);
ch = *str & 0x0f;
*buff = NIBBLE_2_ASCHEX(ch);
str++;
}
*buff = '\0';
return ret;
}
static guint64 hex2bin(const char* hexstr, int len)
{
char nibble;
int i;
guint64 bin= 0;
for(i=0; i< len && i<16; i++)
{
nibble = hexstr[i];
bin <<= 4;
if (g_ascii_isdigit(nibble))
bin |= nibble - 48;
else
bin |= g_ascii_toupper(nibble) - 55;
}
return bin;
}
static gchar *get_bit(guint ind, tvbuff_t *tvb, gint *off_set, proto_tree *tree, proto_item **exp, gint *length )
{
gchar aux[1024];
gchar* ret=NULL;
gint len;
gint offset = *off_set;
gboolean str_input = FALSE;
if(data_array[ind].varlen == 0)
len = data_array[ind].maxsize;
else
{
len = data_array[ind].varlen;
switch(charset_pref)
{
case ASCII_CHARSET:
{
gchar* sizestr;
checksize(len);
sizestr = (gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset,
len , ENC_ASCII);
if(!isnum_str(sizestr,len))
{
return NULL;
}
offset+=len;
len = atoi(sizestr);
break;
}
case NUM_NIBBLE_CHARSET:
{
gint sizestr =0;
gchar* tmp;
if(len%2)
len++;
tvb_memcpy(tvb, aux, offset, len);
tmp = aux;
checksize((len/2));
offset+=len/2;
while(len > 0)
{
sizestr = sizestr*100 + (((guint8)(*tmp)>>4) & 0x0f)*10 +
(((guint8)(*tmp)) & 0x0f);
len-=2;
tmp++;
}
len = sizestr;
break;
}
}
}
*off_set = offset;
if(len > 0)
{
if((guint)len > data_array[ind].maxsize)
return NULL;
if(data_array[ind].type == ISO_TN || data_array[ind].type == ISO_TXN)
{
if(charset_pref == ASCII_CHARSET)
{
checksize(len);
ret = (gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset,
len , ENC_ASCII);
*length = len;
}
else if(charset_pref == NUM_NIBBLE_CHARSET)
{
gint tlen = (len%2)? len/2 + 1 : len/2;
checksize(tlen);
tvb_memcpy(tvb, aux, offset, tlen);
if((ret = bin2hex((guint8 *)aux, TYPE_BCD, len)) == NULL)
return NULL;
*length = (gint)strlen(ret);
len = tlen;
str_input = TRUE;
}
}
else if(data_array[ind].type == ISO_TB || data_array[ind].type == ISO_TZ)
{
if( bin_encode_pref == BIN_ASCII_ENC)
{
if(data_array[ind].type == ISO_TB)
len*=2;
*length = len;
checksize(len);
ret = (gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset,
len, ENC_ASCII);
}
else
{
checksize(len);
tvb_memcpy(tvb, aux, offset, len);
if((ret = bin2hex((guint8 *)aux, TYPE_BIN, len)) == NULL)
return NULL;
*length = (gint)strlen(ret);
str_input = TRUE;
}
}
else
{
checksize(len);
ret = (gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset,
len , ENC_ASCII);
*length = len;
}
if(str_input && tree != NULL)
*exp = proto_tree_add_string(tree, iso8583_data_bit[ind], tvb, offset, len, ret);
else if (tree != NULL)
*exp = proto_tree_add_item(tree, iso8583_data_bit[ind], tvb,
offset, len, ENC_ASCII);
*off_set = offset + len;
}
else
{
*length = 0;
ret = "";
}
return ret;
}
static int get_bitmap(tvbuff_t *tvb, guint64* bitmap, gint offset, gint* nbitmaps)
{
gchar* hexbit;
gint i;
gboolean isbreak = FALSE;
*nbitmaps=0;
for(i=0; i<2; i++)
{
if(bin_encode_pref == BIN_BIN_ENC)
{
if((offset -2 + 8) > iso8583_len)
return -1;
(*nbitmaps)++;
bitmap[i] = tvb_get_bits64(tvb, offset*8, 64, ENC_BIG_ENDIAN);
offset+= BM_LEN;
}
else
{
gint len = BM_LEN*2;
if((offset -2 + len) > iso8583_len)
return -1;
(*nbitmaps)++;
hexbit = (gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len , ENC_ASCII);
offset+= len;
if(!ishex_str(hexbit, len))
return 0;
bitmap[i] = hex2bin(hexbit, len);
}
if(! (bitmap[i] & (((guint64)1) << 63)))
{
isbreak = TRUE;
break;
}
}
if(!isbreak)
(*nbitmaps)++;
return 0;
}
static int dissect_databits(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int nofbitmaps, guint64 *bitmap)
{
proto_item *exp;
gint nofbits = nofbitmaps*64, i;
guint64 bit;
gchar* cod;
gint len;
if(!pinfo)
return 0;
for(i=0; i < nofbits; i++)
{
exp = NULL;
bit = i%64;
if( !bit)
continue;
if(bitmap[i/64] & (((guint64)1)<< (63 -bit)))
{
cod = get_bit(i, tvb, &offset, tree, &exp, &len);
if(cod == NULL || ! isstrtype_ok(data_array[i].type, cod, len ))
{
if(!exp)
exp = proto_tree_add_string(tree, iso8583_data_bit[i], tvb, offset, 0, "");
expert_add_info(pinfo, exp, &ei_iso8583_MALFORMED);
return offset;
}
if( i == 2 || i == 69)
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s. cod: %s", ((i==2)?"Proc":"Net"), cod);
continue;
}
if(exp)
{
}
}
}
return tvb_captured_length(tvb);
}
static int dissect_iso8583_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *exp;
proto_tree *iso8583_tree;
guint offset = 0;
int len = 0;
gchar *msg_type, *msg_bitmap;
gchar aux[24];
guint64 bitmap[3]= {0,0,0};
int nofbitmaps=0;
guint ret;
if (tvb_reported_length(tvb) < iso8583_MIN_LENGTH)
{
return 0;
}
if(charset_pref == ASCII_CHARSET)
{
len = 4;
msg_type = (gchar*) tvb_get_string_enc(wmem_packet_scope(), tvb, 2, len, ENC_ASCII);
}
else
{
len = 2;
tvb_memcpy(tvb, aux, 2, len);
if((msg_type = bin2hex((guint8 *)aux, TYPE_BCD, len*2)) == NULL)
return 0;
}
if(strlen(msg_type) == 4 && !isnum_str(msg_type,4))
{
return 0;
}
if(bin_encode_pref == BIN_BIN_ENC)
msg_bitmap = (gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, 6, BM_LEN*2 , ENC_ASCII);
else
{
tvb_memcpy(tvb, aux, 6, BM_LEN);
if((msg_bitmap = bin2hex((guint8 *)aux, TYPE_BCD, BM_LEN)) == NULL)
return 0;
}
if(strlen(msg_bitmap) == 16 && !ishex_str(msg_bitmap, BM_LEN*2))
{
return 0;
}
if(msg_type[0] == '0')
data_array = iso_1987;
else if (msg_type[0] == '1')
data_array = iso_1993;
else
{
return 0;
}
col_clear(pinfo->cinfo, COL_PROTOCOL);
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "ISO 8583-1%s",
val_to_str((guint)msg_type[0], packetversionnames, " Unknown VERSION"));
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "Type %s - %s", msg_type,
val_to_str((guint)msg_type[1], packettypenames, "Unknown type"));
ti = proto_tree_add_item(tree, proto_iso8583, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ": Type %s - %s", msg_type,
val_to_str((guint)msg_type[1], packettypenames, "Unknown type"));
iso8583_tree = proto_item_add_subtree(ti, ett_iso8583);
len=2;
proto_tree_add_item(iso8583_tree, hf_iso8583_len, tvb,
offset, len, (len_byte_order == BIGEND)?ENC_BIG_ENDIAN:ENC_LITTLE_ENDIAN);
offset += len;
if(charset_pref == ASCII_CHARSET)
{
len=4;
proto_tree_add_item(iso8583_tree, hf_iso8583_mti, tvb,
offset, len, ENC_ASCII | ENC_NA);
}
else
{
len=2;
proto_tree_add_string(iso8583_tree, hf_iso8583_mti, tvb, offset, len, msg_type);
}
offset+=len;
get_bitmap(tvb, bitmap, offset, &nofbitmaps);
if(nofbitmaps == 0)
{
expert_add_info(pinfo, ti, &ei_iso8583_MALFORMED);
return offset;
}
if(bin_encode_pref == BIN_ASCII_ENC)
{
len = BM_LEN*2;
exp = proto_tree_add_item(iso8583_tree, hf_iso8583_bitmap1, tvb,
offset, len, ENC_ASCII|ENC_NA);
if(!ishex_str((gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len , ENC_ASCII), len))
{
expert_add_info(pinfo, exp, &ei_iso8583_MALFORMED);
return offset + len;
}
}
else
{
gchar* hexstr;
len = BM_LEN;
hexstr = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, len);
exp = proto_tree_add_string(iso8583_tree, hf_iso8583_bitmap1, tvb, offset, len, hexstr);
}
offset+=len;
if(nofbitmaps > 1)
{
if(bin_encode_pref == BIN_ASCII_ENC)
{
exp = proto_tree_add_item(iso8583_tree, hf_iso8583_bitmap2, tvb,
offset, len, ENC_ASCII|ENC_NA);
if(!ishex_str((gchar *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len , ENC_ASCII), len))
{
expert_add_info(pinfo, exp, &ei_iso8583_MALFORMED);
return offset + len;
}
}
else
{
gchar* hexstr = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, len);
exp = proto_tree_add_string(iso8583_tree, hf_iso8583_bitmap2, tvb, offset, len, hexstr);
}
offset+=len;
}
if(nofbitmaps > 2)
{
expert_add_info(pinfo, exp, &ei_iso8583_MALFORMED);
return offset;
}
ret = dissect_databits(tvb, pinfo, iso8583_tree, offset, nofbitmaps, bitmap);
return ret;
}
static int dissect_iso8583(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, FRAME_HEADER_LEN, get_iso8583_msg_len, dissect_iso8583_msg, data);
return tvb_captured_length(tvb);
}
void
proto_register_iso8583(void)
{
module_t *iso8583_module;
expert_module_t *expert_iso8583;
int i;
static hf_register_info hf[] = {
{ &hf_iso8583_len,
{ "Message length", "iso8583.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Message length field", HFILL }
},
{ &hf_iso8583_mti,
{ "MTI", "iso8583.mti",
FT_STRING, STR_ASCII, NULL , 0,
"Message Type Idicator (MTI)", HFILL }
},
{ &hf_iso8583_bitmap1,
{ "Bitmap 1", "iso8583.map1",
FT_STRING, STR_ASCII, NULL , 0,
"First Bitmap (hex representation)", HFILL }
},
{ &hf_iso8583_bitmap2,
{ "Bitmap 2", "iso8583.map2",
FT_STRING, STR_ASCII, NULL , 0,
"Second Bitmap (hex representation)", HFILL }
}
};
static hf_register_info hf_data[128];
static const char *hf_data_blurb[128] = {
"Second Bit map present",
"Primary account number (PAN)",
"Processing code",
"Amount, transaction",
"Amount, settlement",
"Amount, cardholder billing",
"Transmission date &amp",
"Amount, cardholder billing fee",
"Conversion rate, settlement",
"Conversion rate, cardholder billing",
"System trace audit number",
"Time, local transaction (hhmmss)",
"Date, local transaction (MMDD)",
"Date, expiration",
"Date, settlement",
"Date, conversion",
"Date, capture",
"Merchant type",
"Acquiring institution country code",
"PAN extended, country code",
"Forwarding institution. country code",
"Point of service entry mode",
"Application PAN sequence number",
"Function code (ISO 8583:1993)/Network International identifier (NII)",
"Point of service condition code",
"Point of service capture code",
"Authorizing identification response length",
"Amount, transaction fee",
"Amount, settlement fee",
"Amount, transaction processing fee",
"Amount, settlement processing fee",
"Acquiring institution identification code",
"Forwarding institution identification code",
"Primary account number, extended",
"Track 2 data",
"Track 3 data",
"Retrieval reference number",
"Authorization identification response",
"Response code",
"Service restriction code",
"Card acceptor terminal identification",
"Card acceptor identification code",
"Card acceptor name/location (1-23 address 24-36 city 37-38 state 39-40 country)",
"Additional response data",
"Track 1 data",
"Additional data - ISO",
"Additional data - national",
"Additional data - private",
"Currency code, transaction",
"Currency code, settlement",
"Currency code, cardholder billing",
"Personal identification number data",
"Security related control information",
"Additional amounts",
"Reserved ISO",
"Reserved ISO",
"Reserved national",
"Reserved national",
"Reserved national",
"Reserved national",
"Reserved private",
"Reserved private",
"Reserved private",
"Message authentication code (MAC)",
"Third Bitmap, extended",
"Settlement code",
"Extended payment code",
"Receiving institution country code",
"Settlement institution country code",
"Network management information code",
"Message number",
"Message number, last",
"Date, action (YYMMDD)",
"Credits, number",
"Credits, reversal number",
"Debits, number",
"Debits, reversal number",
"Transfer number",
"Transfer, reversal number",
"Inquiries number",
"Authorizations, number",
"Credits, processing fee amount",
"Credits, transaction fee amount",
"Debits, processing fee amount",
"Debits, transaction fee amount",
"Credits, amount",
"Credits, reversal amount",
"Debits, amount",
"Debits, reversal amount",
"Original data elements",
"File update code",
"File security code",
"Response indicator",
"Service indicator",
"Replacement amounts",
"Message security code",
"Amount, net settlement",
"Payee",
"Settlement institution identification code",
"Receiving institution identification code",
"File name",
"Account identification 1",
"Account identification 2",
"Transaction description",
"Reserved for ISO use",
"Reserved for ISO use",
"Reserved for ISO use",
"Reserved for ISO use",
"Reserved for ISO use",
"Reserved for ISO use",
"Reserved for ISO use",
"Reserved for national use",
"Reserved for national use",
"Reserved for national use",
"Reserved for national use",
"Reserved for national use",
"Reserved for national use",
"Reserved for national use",
"Reserved for national use",
"Reserved for private use",
"Reserved for private use",
"Reserved for private use",
"Reserved for private use",
"Reserved for private use",
"Reserved for private use",
"Reserved for private use",
"Reserved for private use",
"Message authentication code"
};
static gint *ett[] = {
&ett_iso8583
};
static ei_register_info ei[] = {
{ &ei_iso8583_MALFORMED,
{ "iso8583.MALFORMED", PI_MALFORMED, PI_ERROR,
"MALFORMED", EXPFILL }
}
};
proto_iso8583 = proto_register_protocol("ISO 8583-1", "ISO 8583", "iso8583");
proto_register_field_array(proto_iso8583, hf, array_length(hf));
for (i = 0; i < 128; i++) {
HFILL_INIT(hf_data[i]);
hf_data[i].p_id = &iso8583_data_bit[i];
hf_data[i].hfinfo.name = wmem_strdup_printf(wmem_epan_scope(), "Bit %d", i + 1);
hf_data[i].hfinfo.abbrev = wmem_strdup_printf(wmem_epan_scope(), "iso8583.bit%d", i + 1);
if(! i%64 )
{
hf_data[i].hfinfo.type = FT_BOOLEAN;
hf_data[i].hfinfo.display = 8;
}
else
{
hf_data[i].hfinfo.type = FT_STRING;
hf_data[i].hfinfo.display = STR_ASCII;
}
hf_data[i].hfinfo.strings = NULL;
hf_data[i].hfinfo.bitmask = 0;
hf_data[i].hfinfo.blurb = hf_data_blurb[i];
}
proto_register_field_array(proto_iso8583, hf_data, array_length(hf_data));
proto_register_subtree_array(ett, array_length(ett));
expert_iso8583 = expert_register_protocol(proto_iso8583);
expert_register_field_array(expert_iso8583, ei, array_length(ei));
iso8583_module = prefs_register_protocol(proto_iso8583,
proto_reg_handoff_iso8583);
prefs_register_enum_preference(iso8583_module, "len_endian",
"Length field endian",
"Endian of the length field. Big endian or Little endian",
&len_byte_order,
enumendians, TRUE);
prefs_register_uint_preference(iso8583_module, "tcp.port",
"iso8583 TCP Port",
" iso8583 TCP port",
10, &tcp_port_pref);
prefs_register_enum_preference(iso8583_module, "charset",
"Charset for numbers",
" charset for numbers",
&charset_pref, enum_charset, TRUE);
prefs_register_enum_preference(iso8583_module, "binencode",
"Binary encode",
" binary data representation",
&bin_encode_pref, enum_bin_encode, TRUE);
}
void proto_reg_handoff_iso8583(void)
{
static gboolean initialized = FALSE;
static dissector_handle_t iso8583_handle;
static int current_port;
if (!initialized) {
iso8583_handle = create_dissector_handle(dissect_iso8583,
proto_iso8583);
initialized = TRUE;
} else {
dissector_delete_uint("tcp.port", current_port, iso8583_handle);
}
current_port = tcp_port_pref;
dissector_add_uint("tcp.port", current_port, iso8583_handle);
}
