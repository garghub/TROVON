static void
dissect_wtls(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
char pdut;
guint count = 0;
guint offset_wtls = 0;
proto_item *ti;
proto_tree *wtls_tree;
proto_tree *wtls_rec_tree;
proto_tree *wtls_msg_type_tree;
switch ( pinfo->match_uint )
{
case UDP_PORT_WTLS_WSP:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WTLS+WSP" );
break;
case UDP_PORT_WTLS_WTP_WSP:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "WTLS+WTP+WSP" );
break;
}
col_set_str(pinfo->cinfo, COL_INFO, "WTLS");
if (tree) {
ti = proto_tree_add_item(tree, proto_wtls, tvb, offset_wtls,
-1, ENC_NA);
wtls_tree = proto_item_add_subtree(ti, ett_wtls);
for (offset_wtls=0; offset_wtls < (tvb_reported_length(tvb)-1);) {
pdut = tvb_get_guint8 (tvb, offset_wtls);
offset = offset_wtls+1;
if (pdut & WTLS_RECORD_TYPE_SEQUENCE) {
offset+=2;
}
if (pdut & WTLS_RECORD_TYPE_LENGTH) {
count = tvb_get_ntohs(tvb, offset);
offset+=2;
count += offset-offset_wtls;
}
else {
count = tvb_length_remaining (tvb, offset_wtls);
}
ti = proto_tree_add_uint(wtls_tree, hf_wtls_record, tvb, offset_wtls,
count, pdut);
wtls_rec_tree = proto_item_add_subtree(ti, ett_wtls_rec);
offset = offset_wtls;
proto_tree_add_item (wtls_rec_tree, hf_wtls_record_type,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
offset_wtls += count;
if (pdut & WTLS_RECORD_TYPE_SEQUENCE) {
proto_tree_add_item (wtls_rec_tree, hf_wtls_record_sequence,
tvb,offset,2,ENC_BIG_ENDIAN);
offset+=2;
}
if (pdut & WTLS_RECORD_TYPE_LENGTH) {
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_item (wtls_rec_tree, hf_wtls_record_length,
tvb,offset,2,ENC_BIG_ENDIAN);
offset+=2;
}
else {
count = tvb_length_remaining (tvb, offset);
}
if (pdut & WTLS_RECORD_TYPE_CIPHER_CUR) {
proto_tree_add_item (wtls_rec_tree, hf_wtls_record_ciphered,
tvb,offset,count,ENC_NA);
continue;
}
switch (pdut & WTLS_RECORD_CONTENT_TYPE) {
case WTLS_PLAIN_HANDSHAKE :
dissect_wtls_handshake(wtls_rec_tree,tvb,offset,count);
break;
case WTLS_ALERT :
ti = proto_tree_add_item(wtls_rec_tree, hf_wtls_alert, tvb, offset,
count, ENC_NA);
wtls_msg_type_tree = proto_item_add_subtree(ti, ett_wtls_msg_type);
proto_tree_add_item (wtls_msg_type_tree, hf_wtls_alert_level,
tvb,offset,1,ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item (wtls_msg_type_tree, hf_wtls_alert_description,
tvb,offset,1,ENC_BIG_ENDIAN);
break;
default:
break;
}
}
}
}
static int
add_text_identifier(tvbuff_t *tvb, int offset, int hf_charset,
int hf_size, int hf_str, proto_tree *tree)
{
guint8 size;
int client_size = 0;
proto_tree_add_item(tree, hf_charset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
size = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(tree, hf_size, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_str, tvb, offset, size, ENC_BIG_ENDIAN);
client_size+=size+3;
#ifdef DEBUG
fprintf(stderr, "text id size = %d, client_size = %d\n",
size, client_size);
#endif
return client_size;
}
static int
add_session_id(proto_tree *tree, int hf, int hf_str, tvbuff_t *tvb, int offset)
{
guint count;
guint i;
guint64 session_id;
header_field_info *hfinfo;
count = tvb_get_guint8(tvb, offset);
if (count == 0)
proto_tree_add_string (tree, hf_str, tvb, offset, count+1, "NULL");
else if (count <= 8) {
session_id = 0;
for (i = 0; i < count; i++)
session_id = (session_id << 8) | tvb_get_guint8(tvb, offset + i);
proto_tree_add_uint64 (tree, hf, tvb, offset, count+1, session_id);
} else {
hfinfo = proto_registrar_get_nth(hf);
proto_tree_add_text (tree, tvb, offset, count+1, "%s: %s",
hfinfo->name, tvb_bytes_to_str(tvb, offset+1, count));
}
return offset+1+count;
}
static void
dissect_wtls_handshake(proto_tree *tree, tvbuff_t *tvb, guint offset, guint count)
{
char pdu_msg_type;
nstime_t timeValue;
int client_size = 0;
guint value = 0;
int size = 0;
guint public_key = 0;
char valStr[1024];
const char *valBulk = NULL;
const char *valMac = NULL;
proto_item *ti;
proto_item *cli_key_item;
proto_tree *wtls_msg_type_tree;
proto_tree *wtls_msg_type_item_tree;
proto_tree *wtls_msg_type_item_sub_tree;
proto_tree *wtls_msg_type_item_sub_sub_tree;
pdu_msg_type = tvb_get_guint8 (tvb, offset);
ti = proto_tree_add_uint(tree, hf_wtls_hands, tvb, offset,count, pdu_msg_type);
wtls_msg_type_tree = proto_item_add_subtree(ti, ett_wtls_msg_type);
proto_tree_add_item (wtls_msg_type_tree, hf_wtls_hands_type,
tvb,offset,1,ENC_BIG_ENDIAN);
offset+=1;
count = tvb_get_ntohs (tvb, offset);
proto_tree_add_item (wtls_msg_type_tree, hf_wtls_hands_length,
tvb,offset,2,ENC_BIG_ENDIAN);
offset+=2;
switch(pdu_msg_type) {
case WTLS_HANDSHAKE_CLIENT_HELLO :
ti = proto_tree_add_item(wtls_msg_type_tree, hf_wtls_hands_cli_hello, tvb, offset,
count, ENC_NA);
wtls_msg_type_item_tree = proto_item_add_subtree(ti, ett_wtls_msg_type_item);
proto_tree_add_item (wtls_msg_type_item_tree, hf_wtls_hands_cli_hello_version,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
timeValue.secs = tvb_get_ntohl (tvb, offset);
timeValue.nsecs = 0;
proto_tree_add_time (wtls_msg_type_item_tree, hf_wtls_hands_cli_hello_gmt, tvb,
offset, 4, &timeValue);
offset+=4;
proto_tree_add_item (wtls_msg_type_item_tree, hf_wtls_hands_cli_hello_random,
tvb,offset,12,ENC_NA);
offset+=12;
offset = add_session_id (wtls_msg_type_item_tree,
hf_wtls_hands_cli_hello_session,
hf_wtls_hands_cli_hello_session_str,
tvb, offset);
count = tvb_get_ntohs (tvb, offset);
ti = proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_cli_hello_cli_key_id, tvb, offset,
count+2, ENC_NA);
wtls_msg_type_item_sub_tree = proto_item_add_subtree(ti, ett_wtls_msg_type_item_sub);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_cli_hello_cli_key_len,
tvb,offset,2,ENC_BIG_ENDIAN);
offset+=2;
for (;count > 0;count-=client_size) {
value = tvb_get_guint8 (tvb, offset);
cli_key_item = proto_tree_add_uint(wtls_msg_type_item_sub_tree,
hf_wtls_hands_cli_hello_key_exchange, tvb, offset,1,
value);
client_size=1;
wtls_msg_type_item_sub_sub_tree = proto_item_add_subtree(cli_key_item,
ett_wtls_msg_type_item_sub_sub);
proto_tree_add_uint(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_exchange_suite,
tvb,offset,1,value);
offset++;
#ifdef DEBUG
fprintf(stderr, "encryption suite = %d, client_size = %d\n", value, client_size);
#endif
value = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_parameter_index,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
client_size++;
#ifdef DEBUG
fprintf(stderr, "parameter index = %d, client_size = %d\n", value, client_size);
#endif
if (value == 0xff) {
size = tvb_get_ntohs (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_parameter_set,
tvb,offset,size+2,ENC_ASCII|ENC_NA);
offset+=size+2;
client_size+=size+2;
}
value = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier_type,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
client_size++;
#ifdef DEBUG
fprintf(stderr, "identifier type = %d, client_size = %d\n", value, client_size);
#endif
switch(value) {
case IDENTIFIER_TEXT :
size = add_text_identifier(
tvb, offset,
hf_wtls_hands_cli_hello_key_identifier_charset,
hf_wtls_hands_cli_hello_key_identifier_size,
hf_wtls_hands_cli_hello_key_identifier_str,
wtls_msg_type_item_sub_sub_tree);
offset += size;
client_size += size;
break;
case IDENTIFIER_BIN :
size = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier_size,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier,
tvb,offset,size,ENC_NA);
offset+=size;
client_size+=size+1;
#ifdef DEBUG
fprintf(stderr, "binary id size = %d, client_size = %d\n",
size, client_size);
#endif
break;
case IDENTIFIER_SHA_1 :
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier,
tvb,offset,20,ENC_NA);
offset+=20;
client_size+=20;
#ifdef DEBUG
fprintf(stderr, "SHA-1 hash size = 20, client_size = %d\n",
client_size);
#endif
break;
case IDENTIFIER_X509 :
size = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier_size,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier,
tvb,offset,size,ENC_NA);
offset+=size;
client_size+=size+1;
#ifdef DEBUG
fprintf(stderr, "X.509 name size = %d, client_size = %d\n",
size, client_size);
#endif
break;
}
proto_item_set_len(cli_key_item, client_size);
}
count = tvb_get_ntohs (tvb, offset);
ti = proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_cli_hello_trust_key_id, tvb, offset,
count+2, ENC_NA);
wtls_msg_type_item_sub_tree = proto_item_add_subtree(ti, ett_wtls_msg_type_item_sub);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_cli_hello_cli_key_len,
tvb,offset,2,ENC_BIG_ENDIAN);
offset+=2;
for (;count > 0;count-=client_size) {
value = tvb_get_guint8 (tvb, offset);
cli_key_item = proto_tree_add_uint(wtls_msg_type_item_sub_tree,
hf_wtls_hands_cli_hello_key_exchange, tvb, offset,1,
value);
client_size=1;
wtls_msg_type_item_sub_sub_tree = proto_item_add_subtree(cli_key_item,
ett_wtls_msg_type_item_sub_sub);
proto_tree_add_uint(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_exchange_suite,
tvb,offset,1,value);
offset++;
#ifdef DEBUG
fprintf(stderr, "encryption suite = %d, client_size = %d\n", value, client_size);
#endif
value = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_parameter_index,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
client_size++;
#ifdef DEBUG
fprintf(stderr, "parameter index = %d, client_size = %d\n", value, client_size);
#endif
if (value == 0xff) {
size = tvb_get_ntohs (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_parameter_set,
tvb,offset,size+2,ENC_ASCII|ENC_NA);
offset+=size+2;
client_size+=size+2;
}
value = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier_type,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
client_size++;
#ifdef DEBUG
fprintf(stderr, "identifier type = %d, client_size = %d\n", value, client_size);
#endif
switch (value) {
case IDENTIFIER_TEXT :
size = add_text_identifier(
tvb, offset,
hf_wtls_hands_cli_hello_key_identifier_charset,
hf_wtls_hands_cli_hello_key_identifier_size,
hf_wtls_hands_cli_hello_key_identifier_str,
wtls_msg_type_item_sub_sub_tree);
offset += size;
client_size += size;
break;
case IDENTIFIER_BIN :
size = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier_size,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier,
tvb,offset,size,ENC_NA);
offset+=size;
client_size+=size+1;
#ifdef DEBUG
fprintf(stderr, "binary id size = %d, client_size = %d\n",
size, client_size);
#endif
break;
case IDENTIFIER_SHA_1 :
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier,
tvb,offset,20,ENC_NA);
offset+=20;
client_size+=20;
#ifdef DEBUG
fprintf(stderr, "SHA-1 hash size = 20, client_size = %d\n",
client_size);
#endif
break;
case IDENTIFIER_X509 :
size = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier_size,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_sub_sub_tree,
hf_wtls_hands_cli_hello_key_identifier,
tvb,offset,size,ENC_NA);
offset+=size;
client_size+=size+1;
#ifdef DEBUG
fprintf(stderr, "X.509 name size = %d, client_size = %d\n",
size, client_size);
#endif
break;
}
proto_item_set_len(cli_key_item, client_size);
}
count = tvb_get_guint8 (tvb, offset);
ti = proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_cli_hello_cipher_suite, tvb, offset,
count+1, ENC_NA);
wtls_msg_type_item_sub_tree = proto_item_add_subtree(ti, ett_wtls_msg_type_item_sub);
offset+=1;
for (;count > 0;count-=client_size) {
value = tvb_get_guint8 (tvb, offset);
valBulk = try_val_to_str_ext(value, &wtls_vals_cipher_bulk_ext);
offset++;
client_size=1;
valMac = try_val_to_str_ext(tvb_get_guint8 (tvb, offset), &wtls_vals_cipher_mac_ext);
if (valBulk != NULL)
{
if (valMac != NULL)
{
g_snprintf(valStr,1024,"%s, %s",valBulk,valMac);
}
else
{
g_snprintf(valStr,1024,"%s, Unknown MAC (0x%02x)",valBulk,tvb_get_guint8 (tvb, offset));
}
}
else
{
if (valMac != NULL)
{
g_snprintf(valStr,1024,"Unknown Bulk (0x%02x), %s",value,valMac);
}
else
{
g_snprintf(valStr,1024,"Unknown Bulk (0x%02x), Unknown MAC (0x%02x)",value,
tvb_get_guint8 (tvb, offset));
}
}
offset++;
client_size++;
proto_tree_add_string(wtls_msg_type_item_sub_tree,
hf_wtls_hands_cli_hello_cipher_suite_item, tvb, offset-2,2,
valStr);
}
count = tvb_get_guint8 (tvb, offset);
ti = proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_cli_hello_compression_methods, tvb, offset,
count+1, ENC_NA);
wtls_msg_type_item_sub_tree = proto_item_add_subtree(ti, ett_wtls_msg_type_item_sub);
offset+=1;
for (;count > 0;count-=client_size) {
client_size=0;
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_cli_hello_compression, tvb, offset,1,
ENC_LITTLE_ENDIAN);
offset++;
client_size++;
}
proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_cli_hello_sequence_mode, tvb, offset,
1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_cli_hello_key_refresh, tvb, offset,
1, ENC_LITTLE_ENDIAN);
break;
case WTLS_HANDSHAKE_SERVER_HELLO :
ti = proto_tree_add_item(wtls_msg_type_tree, hf_wtls_hands_serv_hello, tvb, offset,
count, ENC_NA);
wtls_msg_type_item_tree = proto_item_add_subtree(ti, ett_wtls_msg_type_item);
proto_tree_add_item (wtls_msg_type_item_tree, hf_wtls_hands_serv_hello_version,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
timeValue.secs = tvb_get_ntohl (tvb, offset);
timeValue.nsecs = 0;
proto_tree_add_time (wtls_msg_type_item_tree, hf_wtls_hands_serv_hello_gmt, tvb,
offset, 4, &timeValue);
offset+=4;
proto_tree_add_item (wtls_msg_type_item_tree, hf_wtls_hands_serv_hello_random,
tvb,offset,12,ENC_NA);
offset+=12;
offset = add_session_id (wtls_msg_type_item_tree,
hf_wtls_hands_serv_hello_session,
hf_wtls_hands_serv_hello_session_str,
tvb, offset);
proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_serv_hello_cli_key_id,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
cli_key_item = proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_serv_hello_cipher_suite_item, tvb, offset,2,
ENC_NA);
wtls_msg_type_item_sub_tree = proto_item_add_subtree(cli_key_item,
ett_wtls_msg_type_item_sub);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_serv_hello_cipher_bulk,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_serv_hello_cipher_mac,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_serv_hello_compression, tvb, offset,1,
ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_serv_hello_sequence_mode, tvb, offset,
1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_serv_hello_key_refresh, tvb, offset,
1, ENC_LITTLE_ENDIAN);
offset++;
break;
case WTLS_HANDSHAKE_CERTIFICATE :
ti = proto_tree_add_item(wtls_msg_type_tree, hf_wtls_hands_certificates,
tvb, offset,count, ENC_NA);
wtls_msg_type_item_tree = proto_item_add_subtree(ti, ett_wtls_msg_type_item);
count = tvb_get_ntohs (tvb, offset);
offset+=2;
for (;count > 0;count-=client_size) {
cli_key_item = proto_tree_add_item(wtls_msg_type_item_tree,
hf_wtls_hands_certificate, tvb, offset,1,
ENC_NA);
client_size=0;
wtls_msg_type_item_sub_tree = proto_item_add_subtree(cli_key_item,
ett_wtls_msg_type_item_sub);
proto_item_set_len(cli_key_item, client_size);
value = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_type, tvb, offset,1,
ENC_LITTLE_ENDIAN);
offset++;
client_size++;
switch(value) {
case CERTIFICATE_WTLS:
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_version,
tvb, offset,1,
ENC_LITTLE_ENDIAN);
offset++;
client_size++;
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_signature_type,
tvb, offset,1,
ENC_LITTLE_ENDIAN);
offset++;
client_size++;
value = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_issuer_type,
tvb, offset,1,
ENC_LITTLE_ENDIAN);
offset++;
client_size++;
switch (value) {
case IDENTIFIER_NULL :
break;
case IDENTIFIER_TEXT :
value = add_text_identifier(tvb, offset,
hf_wtls_hands_certificate_wtls_issuer_charset,
hf_wtls_hands_certificate_wtls_issuer_size,
hf_wtls_hands_certificate_wtls_issuer_name,
wtls_msg_type_item_sub_tree);
offset += value;
client_size += value;
break;
case IDENTIFIER_BIN :
break;
case IDENTIFIER_SHA_1 :
break;
case IDENTIFIER_X509 :
break;
}
timeValue.secs = tvb_get_ntohl (tvb, offset);
timeValue.nsecs = 0;
proto_tree_add_time (wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_valid_not_before,
tvb, offset, 4, &timeValue);
offset+=4;
client_size+=4;
timeValue.secs = tvb_get_ntohl (tvb, offset);
timeValue.nsecs = 0;
proto_tree_add_time (wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_valid_not_after,
tvb, offset, 4, &timeValue);
offset+=4;
client_size+=4;
value = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_subject_type,
tvb, offset,1,
ENC_LITTLE_ENDIAN);
offset++;
client_size++;
switch (value) {
case IDENTIFIER_NULL :
break;
case IDENTIFIER_TEXT :
value = add_text_identifier(tvb, offset,
hf_wtls_hands_certificate_wtls_subject_charset,
hf_wtls_hands_certificate_wtls_subject_size,
hf_wtls_hands_certificate_wtls_subject_name,
wtls_msg_type_item_sub_tree);
offset += value;
client_size += value;
break;
case IDENTIFIER_BIN :
break;
case IDENTIFIER_SHA_1 :
break;
case IDENTIFIER_X509 :
break;
}
public_key = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_public_key_type,
tvb, offset,1,
ENC_LITTLE_ENDIAN);
offset++;
client_size++;
value = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_key_parameter_index,
tvb,offset,1,ENC_BIG_ENDIAN);
offset++;
client_size++;
if (value == 0xff) {
size = tvb_get_ntohs (tvb, offset);
proto_tree_add_item(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_key_parameter_set,
tvb,offset,size+2,ENC_ASCII|ENC_NA);
offset+=size+2;
client_size+=size+2;
}
switch (public_key) {
case PUBLIC_KEY_RSA :
value = tvb_get_ntohs (tvb, offset);
proto_tree_add_uint(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_rsa_exponent,
tvb,offset,value+2,value*8);
offset+=2+value;
client_size+=2+value;
value = tvb_get_ntohs (tvb, offset);
proto_tree_add_uint(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_rsa_modules,
tvb,offset,value+2,value*8);
offset+=2+value;
client_size+=2+value;
break;
case PUBLIC_KEY_ECDH :
break;
case PUBLIC_KEY_ECDSA :
break;
}
value = tvb_get_ntohs (tvb, offset);
proto_tree_add_uint(wtls_msg_type_item_sub_tree,
hf_wtls_hands_certificate_wtls_signature,
tvb,offset,2+value,value*8);
offset+=2+value;
client_size+=2+value;
break;
case CERTIFICATE_X509:
case CERTIFICATE_X968:
value = tvb_get_ntohs (tvb, offset);
offset+=2;
client_size+=2;
client_size += value;
offset += value;
break;
case CERTIFICATE_URL:
value = tvb_get_guint8 (tvb, offset);
offset++;
client_size++;
client_size += value;
offset += value;
break;
}
proto_item_set_len(cli_key_item, client_size);
}
break;
default:
break;
}
}
void
proto_register_wtls(void)
{
static hf_register_info hf[] = {
{ &hf_wtls_record,
{ "Record",
"wtls.record",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_record_type_ext, 0x0f,
NULL, HFILL
}
},
{ &hf_wtls_record_type,
{ "Record Type",
"wtls.rec_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_record_type_ext, 0x0f,
NULL, HFILL
}
},
{ &hf_wtls_record_length,
{ "Record Length",
"wtls.rec_length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_record_sequence,
{ "Record Sequence",
"wtls.rec_seq",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_record_ciphered,
{ "Record Ciphered",
"wtls.rec_cipher",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands,
{ "Handshake",
"wtls.handshake",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_handshake_type_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_type,
{ "Type",
"wtls.handshake.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_handshake_type_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_length,
{ "Length",
"wtls.handshake.length",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello,
{ "Client Hello",
"wtls.handshake.client_hello",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_version,
{ "Version",
"wtls.handshake.client_hello.version",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_gmt,
{ "Time GMT",
"wtls.handshake.client_hello.gmt",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_random,
{ "Random",
"wtls.handshake.client_hello.random",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_session,
{ "Session ID",
"wtls.handshake.client_hello.sessionid",
FT_UINT64, BASE_HEX_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_session_str,
{ "Session ID",
"wtls.handshake.client_hello.session.str",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_cli_key_id,
{ "Client Keys",
"wtls.handshake.client_hello.client_keys_id",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL , HFILL
}
},
{ &hf_wtls_hands_cli_hello_cli_key_len,
{ "Length",
"wtls.handshake.client_hello.client_keys_len",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL , HFILL
}
},
{ &hf_wtls_hands_cli_hello_trust_key_id,
{ "Trusted Keys",
"wtls.handshake.client_hello.trusted_keys_id",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL , HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_exchange,
{ "Key Exchange",
"wtls.handshake.client_hello.key.key_exchange",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_key_exchange_suite_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_exchange_suite,
{ "Suite",
"wtls.handshake.client_hello.key.key_exchange.suite",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_key_exchange_suite_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_parameter_index,
{ "Parameter Index",
"wtls.handshake.client_hello.parameter_index",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_parameter_set,
{ "Parameter Set",
"wtls.handshake.client_hello.parameter",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_identifier_type,
{ "Identifier Type",
"wtls.handshake.client_hello.ident_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_identifier_type_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_identifier_charset,
{ "Identifier CharSet",
"wtls.handshake.client_hello.ident_charset",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &wap_mib_enum_vals_character_sets_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_identifier_size,
{ "Identifier Size",
"wtls.handshake.client_hello.ident_size",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_identifier,
{ "Identifier",
"wtls.handshake.client_hello.identifier",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_identifier_str,
{ "Identifier Name",
"wtls.handshake.client_hello.ident_name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_cipher_suite,
{ "Cipher Suites",
"wtls.handshake.client_hello.ciphers",
FT_NONE, BASE_NONE, NULL, 0x00,
"Cipher Suite", HFILL
}
},
{ &hf_wtls_hands_cli_hello_cipher_suite_item,
{ "Cipher",
"wtls.handshake.client_hello.cipher",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_compression_methods,
{ "Compression Methods",
"wtls.handshake.client_hello.comp_methods",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_compression,
{ "Compression",
"wtls.handshake.client_hello.compression",
FT_UINT8, BASE_HEX, VALS ( wtls_vals_compression ), 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_sequence_mode,
{ "Sequence Mode",
"wtls.handshake.client_hello.sequence_mode",
FT_UINT8, BASE_DEC, VALS ( wtls_vals_sequence_mode ), 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_cli_hello_key_refresh,
{ "Refresh",
"wtls.handshake.client_hello.refresh",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello,
{ "Server Hello",
"wtls.handshake.server_hello",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_version,
{ "Version",
"wtls.handshake.server_hello.version",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_gmt,
{ "Time GMT",
"wtls.handshake.server_hello.gmt",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_random,
{ "Random",
"wtls.handshake.server_hello.random",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_session,
{ "Session ID",
"wtls.handshake.server_hello.sessionid",
FT_UINT64, BASE_HEX_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_session_str,
{ "Session ID",
"wtls.handshake.server_hello.session.str",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_cli_key_id,
{ "Client Key ID",
"wtls.handshake.server_hello.key",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_cipher_suite_item,
{ "Cipher",
"wtls.handshake.server_hello.cipher",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_cipher_bulk,
{ "Cipher Bulk",
"wtls.handshake.server_hello.cipher.bulk",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_cipher_bulk_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_cipher_mac,
{ "Cipher MAC",
"wtls.handshake.server_hello.cipher.mac",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_cipher_mac_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_compression,
{ "Compression",
"wtls.handshake.server_hello.compression",
FT_UINT8, BASE_HEX, VALS ( wtls_vals_compression ), 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_sequence_mode,
{ "Sequence Mode",
"wtls.handshake.server_hello.sequence_mode",
FT_UINT8, BASE_DEC, VALS ( wtls_vals_sequence_mode ), 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_serv_hello_key_refresh,
{ "Refresh",
"wtls.handshake.server_hello.refresh",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificates,
{ "Certificates",
"wtls.handshake.certificates",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate,
{ "Certificate",
"wtls.handshake.certificate",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_type,
{ "Type",
"wtls.handshake.certificate.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_certificate_type_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_version,
{ "Version",
"wtls.handshake.certificate.version",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_signature_type,
{ "Signature Type",
"wtls.handshake.certificate.signature.type",
FT_UINT8, BASE_DEC, VALS ( wtls_vals_certificate_signature ), 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_signature,
{ "Signature Size",
"wtls.handshake.certificate.signature.signature",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_issuer_type,
{ "Issuer",
"wtls.handshake.certificate.issuer.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_identifier_type_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_issuer_charset,
{ "Charset",
"wtls.handshake.certificate.issuer.charset",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &wap_mib_enum_vals_character_sets_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_issuer_size,
{ "Size",
"wtls.handshake.certificate.issuer.size",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_issuer_name,
{ "Name",
"wtls.handshake.certificate.issuer.name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_valid_not_before,
{ "Valid not before",
"wtls.handshake.certificate.before",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_valid_not_after,
{ "Valid not after",
"wtls.handshake.certificate.after",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_subject_type,
{ "Subject",
"wtls.handshake.certificate.subject.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_identifier_type_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_subject_charset,
{ "Charset",
"wtls.handshake.certificate.subject.charset",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &wap_mib_enum_vals_character_sets_ext, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_subject_size,
{ "Size",
"wtls.handshake.certificate.subject.size",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_subject_name,
{ "Name",
"wtls.handshake.certificate.subject.name",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_public_key_type,
{ "Public Key Type",
"wtls.handshake.certificate.public.type",
FT_UINT8, BASE_DEC, VALS ( wtls_vals_public_key_type ), 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_key_parameter_index,
{ "Parameter Index",
"wtls.handshake.certificate.parameter_index",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_key_parameter_set,
{ "Parameter Set",
"wtls.handshake.certificate.parameter",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_rsa_exponent,
{ "RSA Exponent Size",
"wtls.handshake.certificate.rsa.exponent",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_hands_certificate_wtls_rsa_modules,
{ "RSA Modulus Size",
"wtls.handshake.certificate.rsa.modules",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_alert,
{ "Alert",
"wtls.alert",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL
}
},
{ &hf_wtls_alert_level,
{ "Level",
"wtls.alert.level",
FT_UINT8, BASE_DEC, VALS ( wtls_vals_alert_level ), 0x00,
NULL, HFILL
}
},
{ &hf_wtls_alert_description,
{ "Description",
"wtls.alert.description",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &wtls_vals_alert_description_ext, 0x00,
NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_wtls,
&ett_wtls_rec,
&ett_wtls_msg_type,
&ett_wtls_msg_type_item,
&ett_wtls_msg_type_item_sub,
&ett_wtls_msg_type_item_sub_sub,
};
proto_wtls = proto_register_protocol(
"Wireless Transport Layer Security",
"WTLS",
"wtls"
);
proto_register_field_array(proto_wtls, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_wtls(void)
{
dissector_handle_t wtls_handle;
wtls_handle = create_dissector_handle(dissect_wtls, proto_wtls);
dissector_add_uint("udp.port", UDP_PORT_WTLS_WSP, wtls_handle);
dissector_add_uint("udp.port", UDP_PORT_WTLS_WTP_WSP, wtls_handle);
dissector_add_uint("udp.port", UDP_PORT_WTLS_WSP_PUSH,wtls_handle);
}
