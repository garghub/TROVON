static guint crc_calc (guint crc, guint val)
{
int indx;
guint ncrc;
indx = (((crc >> 8) ^ val) & 0xff);
ncrc = crc_table[indx] ^ ((crc << 8) & 0xffff);
return ncrc;
}
static gint sbus_equal(gconstpointer v, gconstpointer w)
{
sbus_request_key *v1 = (sbus_request_key *)v;
sbus_request_key *v2 = (sbus_request_key *)w;
if (v1->conversation == v2->conversation &&
v1->sequence == v2->sequence) {
return 1;
}
return 0;
}
static guint sbus_hash(gconstpointer v)
{
sbus_request_key *key = (sbus_request_key *)v;
guint val;
val = key->conversation + key->sequence;
return val;
}
static void sbus_init_protocol(void){
if (sbus_request_hash){
g_hash_table_destroy(sbus_request_hash);
}
sbus_request_hash = g_hash_table_new(sbus_hash, sbus_equal);
}
static gboolean
is_sbus_pdu(tvbuff_t *tvb)
{
guint32 length;
if(tvb_length(tvb)<8){
return FALSE;
}
length=tvb_get_ntohl(tvb, 0);
if ( (length<8) || (length>65535) ) {
return FALSE;
}
if (tvb_reported_length(tvb) != length) {
return FALSE;
}
if (tvb_get_ntohl(tvb, 0) < 12) {
return (FALSE);
}
if (tvb_get_guint8(tvb, 4) > 0x01) {
return (FALSE);
}
if ( tvb_get_guint8(tvb, 5) > 0x01 ) {
return (FALSE);
}
if (tvb_get_guint8(tvb, 8) > 0x02 ) {
return (FALSE);
}
return TRUE;
}
static int
dissect_sbus(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti, *et, *dt, *hi, *cs;
proto_tree *sbus_tree, *ethsbus_tree, *sbusdata_tree;
gint i;
gint j;
gint offset;
gint sbus_eth_len;
guint sbus_crc_calc;
guint8 sbus_attribut;
guint8 sbus_media_cnt;
guint8 sbus_fio_cnt;
guint8 sbus_cmd_code;
guint8 sbus_web_size;
guint8 sbus_web_aid;
guint8 sbus_web_seq;
guint8 sbus_rdwr_type;
guint8 sbus_rdwr_sequence;
guint8 sbus_rdwr_block_tlg;
guint8 sbus_rdwr_block_type;
guint8 sbus_rdwr_ack_nak;
guint8 sbus_quint8_helper0;
guint32 sbus_binarymasked;
guint32 sbus_binaries;
guint16 sbus_ack_code;
guint32 sbus_show_bin;
guint32 sbus_rdwr_length;
guint32 sbus_helper;
guint32 sbus_helper1;
guint32 sbus_helper2;
char *tmp_string;
nstime_t ns;
conversation_t *conversation = NULL;
sbus_request_key request_key, *new_request_key;
sbus_request_val *request_val = NULL;
if(!is_sbus_pdu(tvb)){
return 0;
}
conversation = find_or_create_conversation(pinfo);
request_key.conversation = conversation->index;
request_key.sequence = tvb_get_ntohs(tvb,6);
request_val = (sbus_request_val *) g_hash_table_lookup(sbus_request_hash,
&request_key);
sbus_attribut = tvb_get_guint8(tvb,8);
if (request_val && sbus_attribut == SBUS_REQUEST) {
if (request_val->req_frame < pinfo->fd->num){
request_val->retry_count +=1;
}
else {
request_val->retry_count = 0;
request_val->req_frame = pinfo->fd->num;
request_val->req_time = pinfo->fd->abs_ts;
}
}
if (request_val && (sbus_attribut == SBUS_RESPONSE ||
sbus_attribut == SBUS_ACKNAK)) {
request_val->resp_frame = pinfo->fd->num;
}
sbus_attribut = tvb_get_guint8(tvb,8);
if ( !request_val && sbus_attribut == 0 ) {
new_request_key = wmem_new(wmem_file_scope(), sbus_request_key);
*new_request_key = request_key;
request_val = wmem_new(wmem_file_scope(), sbus_request_val);
request_val->cmd_code=tvb_get_guint8(tvb,10);
request_val->retry_count=0;
request_val->req_frame = pinfo->fd->num;
request_val->req_time = pinfo->fd->abs_ts;
request_val->resp_frame = 0;
if (((request_val->cmd_code) == SBUS_RD_USER_EEPROM_REGISTER) ||
((request_val->cmd_code) == SBUS_WR_USER_EEPROM_REGISTER)) {
request_val->count=((tvb_get_guint8(tvb,12))+1);
} else {
request_val->count=((tvb_get_guint8(tvb,11))+1);
}
if ((request_val->cmd_code) == SBUS_RD_SYSTEM_INFORMATION) {
request_val->sysinfo=(tvb_get_guint8(tvb,12));
request_val->block_tlg=0x0;
} else if ((request_val->cmd_code) == SBUS_RD_WR_PCD_BLOCK) {
request_val->sysinfo=0x0;
request_val->block_tlg=(tvb_get_guint8(tvb,12));
} else {
request_val->sysinfo=0x0;
request_val->block_tlg=0x0;
}
g_hash_table_insert(sbus_request_hash, new_request_key, request_val);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "S-Bus");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
switch (sbus_attribut){
case SBUS_REQUEST:
sbus_cmd_code = tvb_get_guint8(tvb,10);
switch (sbus_cmd_code){
case SBUS_WEB_SERVER_SERIAL_COMM:
sbus_web_aid = tvb_get_guint8(tvb,12);
sbus_web_seq = tvb_get_guint8(tvb,13);
col_add_fstr(pinfo->cinfo, COL_INFO,
"Web Server Request: %s (Seq No: %d)",
val_to_str_const(sbus_web_aid,
webserver_aid_vals, "Unknown Request!"),
sbus_web_seq);
break;
case SBUS_RD_WR_PCD_BLOCK:
sbus_rdwr_type = tvb_get_guint8(tvb, 12);
col_add_fstr( pinfo->cinfo, COL_INFO,
"Request: %s", val_to_str_const( sbus_rdwr_type, rdwrblock_vals,
"This RD/WR block telegram is not implemented"));
if (sbus_rdwr_type == SBUS_WR_START_OF_STREAM) {
sbus_rdwr_block_type = tvb_get_guint8(tvb, 14);
if ((sbus_rdwr_block_type == SBUS_RD_WR_CONFIGURATION_FILE) ||
(sbus_rdwr_block_type == SBUS_RD_WR_PROGRAM_BLOCK_FILE)) {
sbus_quint8_helper0=0;
for (i=19; i<43; i++) {
if ((tvb_get_guint8(tvb, i)) == 0x00) {
break;
}
sbus_quint8_helper0 += 1;
}
tmp_string = tvb_get_string(wmem_packet_scope(), tvb , 19,
sbus_quint8_helper0);
col_append_fstr(pinfo->cinfo, COL_INFO,
": (File: %s)", tmp_string);
}
} else if (sbus_rdwr_type == SBUS_RD_BLOCK_START_OF_STREAM) {
sbus_rdwr_block_type = tvb_get_guint8(tvb, 14);
if ((sbus_rdwr_block_type == SBUS_RD_WR_CONFIGURATION_FILE) ||
(sbus_rdwr_block_type == SBUS_RD_WR_PROGRAM_BLOCK_FILE)) {
sbus_quint8_helper0=0;
for (i=15; i<39; i++) {
if ((tvb_get_guint8(tvb, i)) == 0x00) {
break;
}
sbus_quint8_helper0 += 1;
}
tmp_string = tvb_get_string(wmem_packet_scope(), tvb , 15,
sbus_quint8_helper0);
col_append_fstr(pinfo->cinfo, COL_INFO,
": (File: %s)", tmp_string);
}
}
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Request: %s", val_to_str_const(sbus_cmd_code,
sbus_command_vals, "Unknown Command!"));
break;
}
if (request_val->retry_count>0) {
col_append_str(pinfo->cinfo, COL_INFO,
" (Retry)");
}
break;
case SBUS_RESPONSE:
if (request_val && ((request_val->cmd_code) == SBUS_WEB_SERVER_SERIAL_COMM)) {
sbus_web_size = tvb_get_guint8(tvb,9);
sbus_web_aid = tvb_get_guint8(tvb,10);
col_add_fstr(pinfo->cinfo, COL_INFO,
"Response: %s",
val_to_str_const(sbus_web_aid,
webserver_aid_vals, "Unknown Request!"));
if (sbus_web_size > 1) {
sbus_web_seq = tvb_get_guint8(tvb,11);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Seq No: %d)",
sbus_web_seq);
}
} else if (request_val && ((request_val->cmd_code) == SBUS_RD_WR_PCD_BLOCK)) {
switch (request_val->block_tlg) {
case SBUS_WR_START_OF_STREAM:
case SBUS_WR_BLOCK_DATA_STREAM:
case SBUS_WR_BLOCK_END_OF_STREAM:
case SBUS_WR_ABORT_BLOCK_STREAM:
case SBUS_WR_BLOCK_DATA_BYTES:
case SBUS_DELETE_BLOCK:
case SBUS_RD_ABORT_BLOCK_STREAM:
sbus_rdwr_ack_nak = tvb_get_guint8(tvb, 10);
col_add_fstr( pinfo->cinfo, COL_INFO,
"Response: %s", val_to_str_const(sbus_rdwr_ack_nak,
rdwrblock_sts, "Unknown response!"));
break;
default:
sbus_rdwr_type = tvb_get_guint8(tvb, 9);
col_add_fstr( pinfo->cinfo, COL_INFO,
"Response: (%d byte)", sbus_rdwr_type);
break;
}
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Response");
}
break;
case SBUS_ACKNAK:
sbus_ack_code = tvb_get_ntohs(tvb,9);
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s", val_to_str_const(sbus_ack_code,
sbus_ack_nak_vals,
"Unknown NAK response code!"));
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown attribute");
break;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_sbus, tvb, offset, -1, ENC_NA);
sbus_tree = proto_item_add_subtree(ti, ett_sbus);
et = proto_tree_add_text(sbus_tree, tvb, offset, 8, "Ether-S-Bus header");
ethsbus_tree = proto_item_add_subtree(et, ett_sbus_ether);
sbus_eth_len = tvb_get_ntohl(tvb,offset);
proto_tree_add_item(ethsbus_tree,
hf_sbus_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ethsbus_tree,
hf_sbus_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ethsbus_tree,
hf_sbus_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ethsbus_tree,
hf_sbus_sequence, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
sbus_attribut = tvb_get_guint8(tvb,offset);
proto_tree_add_item(sbus_tree,
hf_sbus_attribut, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (sbus_attribut == SBUS_REQUEST) {
proto_tree_add_item(sbus_tree,
hf_sbus_dest, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sbus_cmd_code = tvb_get_guint8(tvb,offset);
proto_tree_add_item(sbus_tree,
hf_sbus_command, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (request_val && request_val->retry_count > 0) {
expert_add_info(pinfo, sbus_tree, &ei_sbus_retry);
nstime_delta(&ns, &pinfo->fd->abs_ts, &request_val->req_time);
proto_tree_add_time(sbus_tree, hf_sbus_timeout,
tvb, 0, 0, &ns);
proto_tree_add_uint(sbus_tree, hf_sbus_request_in, tvb, 0, 0,
request_val->req_frame);
}
if (request_val && request_val->resp_frame > pinfo->fd->num){
proto_tree_add_uint(sbus_tree, hf_sbus_response_in, tvb, 0, 0,
request_val->resp_frame);
}
switch (sbus_cmd_code) {
case SBUS_RD_COUNTER:
case SBUS_RD_REGISTER:
case SBUS_RD_TIMER:
sbus_media_cnt = (tvb_get_guint8(tvb,offset))+1;
proto_tree_add_uint(sbus_tree,
hf_sbus_rcount, tvb, offset, 1, sbus_media_cnt);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_rtc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case SBUS_RD_FLAG:
case SBUS_RD_INPUT:
case SBUS_RD_OUTPUT:
sbus_media_cnt = (tvb_get_guint8(tvb,offset))+1;
proto_tree_add_uint(sbus_tree,
hf_sbus_rcount, tvb, offset, 1, sbus_media_cnt);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_iof, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case SBUS_WR_COUNTER:
case SBUS_WR_REGISTER:
case SBUS_WR_TIMER:
sbus_media_cnt = (tvb_get_guint8(tvb,offset));
sbus_media_cnt = ((sbus_media_cnt - 1)/4);
proto_tree_add_uint(sbus_tree,
hf_sbus_wcount_calculated, tvb, offset,
1, sbus_media_cnt);
proto_tree_add_item(sbus_tree,
hf_sbus_wcount, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_rtc, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
dt = proto_tree_add_text(sbus_tree, tvb, offset,
((sbus_media_cnt) * 4),"Data");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=((sbus_media_cnt)); i>0; i--) {
proto_tree_add_item(sbusdata_tree,
hf_sbus_data_rtc, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case SBUS_WR_FLAG:
case SBUS_WR_OUTPUT:
sbus_media_cnt = (tvb_get_guint8(tvb,offset));
sbus_media_cnt = (sbus_media_cnt - 2);
proto_tree_add_uint(sbus_tree,
hf_sbus_wcount_calculated, tvb, offset,
1, sbus_media_cnt);
proto_tree_add_item(sbus_tree,
hf_sbus_wcount, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_iof, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
sbus_fio_cnt = (tvb_get_guint8(tvb,offset));
sbus_fio_cnt = ((sbus_fio_cnt + 1));
proto_tree_add_uint(sbus_tree,
hf_sbus_fio_count, tvb, offset, 1, sbus_fio_cnt);
offset += 1;
dt = proto_tree_add_text(sbus_tree, tvb, offset,
sbus_media_cnt,"Data");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=sbus_media_cnt; i>0; i--) {
sbus_helper = 1;
sbus_show_bin = 0;
sbus_binarymasked = 0x01;
sbus_binaries = tvb_get_guint8(tvb, offset);
for (j=0; j<8; j++) {
if ((sbus_binarymasked & sbus_binaries) != 0) {
sbus_show_bin = (sbus_show_bin + sbus_helper);
}
sbus_binarymasked = sbus_binarymasked<<1;
sbus_helper = 10 * sbus_helper;
}
proto_tree_add_uint_format(sbusdata_tree,
hf_sbus_data_iof, tvb, offset, 1, sbus_show_bin,
"Binary data: %08u", sbus_show_bin);
offset += 1;
}
break;
case SBUS_WR_RTC:
sbus_helper = tvb_get_guint8(tvb, (offset +5));
sbus_helper1 = tvb_get_guint8(tvb, (offset +6));
sbus_helper2 = tvb_get_guint8(tvb, (offset +7));
proto_tree_add_text(sbus_tree, tvb, (offset +5), 3,
"Time (HH:MM:SS): %02x:%02x:%02x", sbus_helper, sbus_helper1, sbus_helper2);
sbus_helper = tvb_get_guint8(tvb, (offset +2));
sbus_helper1 = tvb_get_guint8(tvb, (offset +3));
sbus_helper2 = tvb_get_guint8(tvb, (offset +4));
proto_tree_add_text(sbus_tree, tvb, (offset +2), 3,
"Date (YY/MM/DD): %02x/%02x/%02x", sbus_helper, sbus_helper1, sbus_helper2);
sbus_helper = tvb_get_guint8(tvb, (offset));
sbus_helper1 = tvb_get_guint8(tvb, (offset +1));
proto_tree_add_text(sbus_tree, tvb, offset, 2,
"Calendar week: %x, Week day: %x", sbus_helper, sbus_helper1);
dt = proto_tree_add_text(sbus_tree, tvb, offset,
8, "Clock data");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
proto_tree_add_item(sbusdata_tree,
hf_sbus_week_day, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sbusdata_tree,
hf_sbus_date, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(sbusdata_tree,
hf_sbus_time, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
break;
case SBUS_RD_USER_MEMORY:
case SBUS_RD_PROGRAM_LINE:
sbus_media_cnt = (tvb_get_guint8(tvb,offset))+1;
proto_tree_add_uint(sbus_tree,
hf_sbus_rcount, tvb, offset, 1, sbus_media_cnt);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_prog, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
break;
case SBUS_WR_USER_MEMORY:
sbus_media_cnt = (tvb_get_guint8(tvb,offset));
sbus_media_cnt = ((sbus_media_cnt - 2)/4);
proto_tree_add_uint(sbus_tree,
hf_sbus_wcount_calculated, tvb, offset,
1, sbus_media_cnt);
proto_tree_add_item(sbus_tree,
hf_sbus_wcount, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_68k, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
dt = proto_tree_add_text(sbus_tree, tvb, offset,
((sbus_media_cnt) * 4),"Program lines");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=((sbus_media_cnt)); i>0; i--) {
proto_tree_add_item(sbusdata_tree,
hf_sbus_data_rtc, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case SBUS_RD_BYTE:
sbus_media_cnt = (tvb_get_guint8(tvb,offset))+1;
proto_tree_add_uint(sbus_tree,
hf_sbus_rcount, tvb, offset, 1, sbus_media_cnt);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_68k, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
break;
case SBUS_WR_BYTE:
sbus_media_cnt = (tvb_get_guint8(tvb,offset));
sbus_media_cnt = (sbus_media_cnt - 2);
proto_tree_add_uint(sbus_tree,
hf_sbus_wcount_calculated, tvb, offset,
1, sbus_media_cnt);
proto_tree_add_item(sbus_tree,
hf_sbus_wcount, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_68k, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
dt = proto_tree_add_text(sbus_tree, tvb, offset,
((sbus_media_cnt) * 4),"Data (bytes)");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=sbus_media_cnt; i>0; i--) {
proto_tree_add_item(sbusdata_tree,
hf_sbus_data_byte, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case SBUS_RD_USER_EEPROM_REGISTER:
proto_tree_add_item(sbus_tree,
hf_sbus_command_extension, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
sbus_media_cnt = (tvb_get_guint8(tvb,offset))+1;
proto_tree_add_uint(sbus_tree,
hf_sbus_rcount, tvb, offset, 1, sbus_media_cnt);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_addr_eeprom, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case SBUS_RD_SYSTEM_INFORMATION:
proto_tree_add_item(sbus_tree,
hf_sbus_sysinfo_nr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_sysinfo_nr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case SBUS_WEB_SERVER_SERIAL_COMM:
sbus_web_size = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_web_size, tvb, offset,
1, sbus_web_size);
offset += 1;
sbus_web_aid = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_web_aid, tvb, offset,
1, sbus_web_aid);
offset += 1;
sbus_web_seq = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_web_seq, tvb, offset,
1, sbus_web_seq);
offset += 1;
if (sbus_web_size > 1) {
dt = proto_tree_add_text(sbus_tree, tvb, offset,
(sbus_web_size - 1),"Data (bytes)");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=sbus_web_size -1 ; i>0; i--) {
proto_tree_add_item(sbusdata_tree,
hf_sbus_data_byte, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case SBUS_RD_WR_PCD_BLOCK:
if (tvb_get_guint8(tvb,offset) == 0xff){
sbus_rdwr_length = ((tvb_get_ntohl(tvb,0))-15);
proto_tree_add_uint(sbus_tree,
hf_sbus_rdwr_block_length_ext, tvb, 0, 4, sbus_rdwr_length);
offset += 1;
} else {
sbus_rdwr_length = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_rdwr_block_length, tvb, offset,
1, sbus_rdwr_length);
offset += 1;
}
sbus_rdwr_type = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_rdwr_telegram_type, tvb, offset,
1, sbus_rdwr_type);
offset += 1;
switch(sbus_rdwr_type) {
case SBUS_WR_START_OF_STREAM:
sbus_rdwr_block_type = tvb_get_guint8(tvb, 14);
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_telegram_sequence, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_block_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
if ((sbus_rdwr_block_type == SBUS_RD_WR_CONFIGURATION_FILE) ||
(sbus_rdwr_block_type == SBUS_RD_WR_PROGRAM_BLOCK_FILE)) {
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_size, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
sbus_quint8_helper0=0;
for (i=19; i<43; i++) {
if ((tvb_get_guint8(tvb, i)) == 0x00) {
break;
}
sbus_quint8_helper0 += 1;
}
tmp_string = tvb_get_string(wmem_packet_scope(), tvb , 19, sbus_quint8_helper0);
proto_tree_add_string(sbus_tree,
hf_sbus_rdwr_file_name, tvb, offset,
sbus_quint8_helper0, tmp_string);
offset += sbus_quint8_helper0;
offset += (sbus_rdwr_length-6-sbus_quint8_helper0);
} else {
proto_tree_add_item(sbus_tree,
hf_sbus_block_nr, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_size, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
offset += (sbus_rdwr_length-8);
}
break;
case SBUS_WR_BLOCK_DATA_STREAM:
sbus_rdwr_sequence = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_rdwr_telegram_sequence, tvb, offset,
1, sbus_rdwr_sequence);
offset += 1;
offset += (sbus_rdwr_length-1);
break;
case SBUS_WR_BLOCK_END_OF_STREAM:
sbus_rdwr_sequence = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_rdwr_telegram_sequence, tvb, offset,
1, sbus_rdwr_sequence);
offset += 1;
offset += (sbus_rdwr_length-5);
offset += 4;
break;
case SBUS_WR_ABORT_BLOCK_STREAM:
case SBUS_RD_ABORT_BLOCK_STREAM:
break;
case SBUS_WR_BLOCK_DATA_BYTES:
sbus_rdwr_block_type = tvb_get_guint8(tvb, 14);
proto_tree_add_item(sbus_tree,
hf_sbus_block_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
if ((sbus_rdwr_block_type == SBUS_RD_WR_CONFIGURATION_FILE) ||
(sbus_rdwr_block_type == SBUS_RD_WR_PROGRAM_BLOCK_FILE)) {
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_addr, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
sbus_quint8_helper0=0;
for (i=19; i<43; i++) {
if ((tvb_get_guint8(tvb, i)) == 0x00) {
break;
}
sbus_quint8_helper0 += 1;
}
tmp_string = tvb_get_string(wmem_packet_scope(), tvb, 19, sbus_quint8_helper0);
proto_tree_add_string(sbus_tree,
hf_sbus_rdwr_file_name, tvb, offset,
sbus_quint8_helper0, tmp_string);
offset += sbus_quint8_helper0;
offset += (sbus_rdwr_length-6-sbus_quint8_helper0);
} else {
proto_tree_add_item(sbus_tree,
hf_sbus_block_nr, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_addr, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
offset += (sbus_rdwr_length-8);
}
break;
case SBUS_RD_BLOCK_START_OF_STREAM:
sbus_rdwr_block_type = tvb_get_guint8(tvb, 14);
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_telegram_sequence, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_block_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
if ((sbus_rdwr_block_type == SBUS_RD_WR_CONFIGURATION_FILE) ||
(sbus_rdwr_block_type == SBUS_RD_WR_PROGRAM_BLOCK_FILE)) {
sbus_quint8_helper0=0;
for (i=14; i<38; i++) {
if ((tvb_get_guint8(tvb, i)) == 0x00) {
break;
}
sbus_quint8_helper0 += 1;
}
tmp_string = tvb_get_string(wmem_packet_scope(), tvb, 14, sbus_quint8_helper0);
proto_tree_add_string(sbus_tree,
hf_sbus_rdwr_file_name, tvb, offset,
sbus_quint8_helper0, tmp_string);
offset += sbus_quint8_helper0;
} else {
proto_tree_add_item(sbus_tree,
hf_sbus_block_nr, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case SBUS_RD_BLOCK_DATA_STREAM:
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_telegram_sequence, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
break;
case SBUS_RD_BLOCK_DATA_BYTES:
sbus_rdwr_block_type = tvb_get_guint8(tvb, 13);
proto_tree_add_item(sbus_tree,
hf_sbus_block_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
if ((sbus_rdwr_block_type == SBUS_RD_WR_CONFIGURATION_FILE) ||
(sbus_rdwr_block_type == SBUS_RD_WR_PROGRAM_BLOCK_FILE)) {
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_addr, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_size, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
sbus_quint8_helper0=0;
for (i=22; i<46; i++) {
if ((tvb_get_guint8(tvb, i)) == 0x00) {
break;
}
sbus_quint8_helper0 += 1;
}
tmp_string = tvb_get_string(wmem_packet_scope(), tvb, 22, sbus_quint8_helper0);
proto_tree_add_string(sbus_tree,
hf_sbus_rdwr_file_name, tvb, offset,
sbus_quint8_helper0, tmp_string);
offset += sbus_quint8_helper0 + 1;
} else {
proto_tree_add_item(sbus_tree,
hf_sbus_block_nr, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_addr, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_size, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case SBUS_DELETE_BLOCK:
case SBUS_GET_BLOCK_SIZE:
sbus_rdwr_block_type = tvb_get_guint8(tvb, 13);
proto_tree_add_item(sbus_tree,
hf_sbus_block_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
if ((sbus_rdwr_block_type == SBUS_RD_WR_CONFIGURATION_FILE) ||
(sbus_rdwr_block_type == SBUS_RD_WR_PROGRAM_BLOCK_FILE)) {
sbus_quint8_helper0=0;
for (i=14; i<38; i++) {
if ((tvb_get_guint8(tvb, i)) == 0x00) {
break;
}
sbus_quint8_helper0 += 1;
}
tmp_string = tvb_get_string(wmem_packet_scope(), tvb, 14, sbus_quint8_helper0);
proto_tree_add_string(sbus_tree,
hf_sbus_rdwr_file_name, tvb, offset,
sbus_quint8_helper0, tmp_string);
offset += sbus_quint8_helper0 + 1;
} else {
proto_tree_add_item(sbus_tree,
hf_sbus_block_nr, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case SBUS_GET_PROGRAM_BLOCK_LIST:
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_list_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
break;
default:
break;
}
break;
default:
if (sbus_eth_len > 13) {
sbus_helper = sbus_eth_len - (offset + 2);
proto_tree_add_text(sbus_tree, tvb, offset, sbus_helper,
"This telegram isn't implemented in the dissector.");
offset = offset + sbus_helper;
}
break;
}
}
if (sbus_attribut == SBUS_RESPONSE && request_val) {
nstime_delta(&ns, &pinfo->fd->abs_ts, &request_val->req_time);
proto_tree_add_time(sbus_tree, hf_sbus_response_time,
tvb, 0, 0, &ns);
proto_tree_add_uint(sbus_tree, hf_sbus_response_to, tvb, 0, 0,
request_val->req_frame);
switch (request_val->cmd_code) {
case SBUS_RD_COUNTER:
case SBUS_RD_REGISTER:
case SBUS_RD_TIMER:
case SBUS_RD_USER_MEMORY:
case SBUS_RD_PROGRAM_LINE:
case SBUS_RD_USER_EEPROM_REGISTER:
dt = proto_tree_add_text(sbus_tree, tvb, offset,
((request_val->count) * 4),"Data");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=(request_val->count); i>0; i--) {
proto_tree_add_item(sbusdata_tree,
hf_sbus_data_rtc, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case SBUS_RD_DISPLAY_REGISTER:
proto_tree_add_item(sbus_tree,
hf_sbus_display_register, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case SBUS_RD_FLAG:
case SBUS_RD_INPUT:
case SBUS_RD_OUTPUT:
dt = proto_tree_add_text(sbus_tree, tvb, offset,
(((request_val->count) + 7) / 8), "Data");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=(((request_val->count) + 7) / 8); i>0; i--) {
sbus_helper = 1;
sbus_show_bin = 0;
sbus_binarymasked = 0x01;
sbus_binaries = tvb_get_guint8(tvb, offset);
for (j=0; j<8; j++){
if ((sbus_binarymasked & sbus_binaries) != 0) {
sbus_show_bin = (sbus_show_bin + sbus_helper);
}
sbus_binarymasked = sbus_binarymasked<<1;
sbus_helper = 10 * sbus_helper;
}
proto_tree_add_uint_format(sbusdata_tree,
hf_sbus_data_iof, tvb, offset, 1, sbus_show_bin,
"Binary data: %08u", sbus_show_bin);
offset += 1;
}
break;
case SBUS_RD_RTC:
sbus_helper = tvb_get_guint8(tvb, (offset +5));
sbus_helper1 = tvb_get_guint8(tvb, (offset +6));
sbus_helper2 = tvb_get_guint8(tvb, (offset +7));
proto_tree_add_text(sbus_tree, tvb, (offset +5), 3,
"Time (HH:MM:SS): %02x:%02x:%02x", sbus_helper, sbus_helper1, sbus_helper2);
sbus_helper = tvb_get_guint8(tvb, (offset +2));
sbus_helper1 = tvb_get_guint8(tvb, (offset +3));
sbus_helper2 = tvb_get_guint8(tvb, (offset +4));
proto_tree_add_text(sbus_tree, tvb, (offset +2), 3,
"Date (YY/MM/DD): %02x/%02x/%02x", sbus_helper, sbus_helper1, sbus_helper2);
sbus_helper = tvb_get_guint8(tvb, (offset));
sbus_helper1 = tvb_get_guint8(tvb, (offset +1));
proto_tree_add_text(sbus_tree, tvb, offset, 2,
"Calendar week: %x, Week day: %x", sbus_helper, sbus_helper1);
dt = proto_tree_add_text(sbus_tree, tvb, offset,
8, "Clock data");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
proto_tree_add_item(sbusdata_tree,
hf_sbus_week_day, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sbusdata_tree,
hf_sbus_date, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(sbusdata_tree,
hf_sbus_time, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
break;
case SBUS_RD_PCD_STATUS_CPU0:
case SBUS_RD_PCD_STATUS_CPU1:
case SBUS_RD_PCD_STATUS_CPU2:
case SBUS_RD_PCD_STATUS_CPU3:
case SBUS_RD_PCD_STATUS_CPU4:
case SBUS_RD_PCD_STATUS_CPU5:
case SBUS_RD_PCD_STATUS_CPU6:
case SBUS_RD_PCD_STATUS_OWN:
proto_tree_add_item(sbus_tree,
hf_sbus_cpu_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case SBUS_RD_SBUS_STN_NBR:
proto_tree_add_item(sbus_tree,
hf_sbus_address, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
case SBUS_RD_PROGRAM_VERSION:
tmp_string = tvb_get_string(wmem_packet_scope(), tvb , offset, 5);
proto_tree_add_string(sbus_tree,
hf_sbus_cpu_type, tvb, offset, 5, tmp_string);
offset += 5;
tmp_string = tvb_get_string(wmem_packet_scope(), tvb , offset, 3);
proto_tree_add_string(sbus_tree,
hf_sbus_fw_version, tvb, offset, 3, tmp_string);
offset += 4;
break;
case SBUS_RD_STATUSFLAG_ACCU:
dt = proto_tree_add_text(sbus_tree, tvb, offset,
1,"ACCU and arithmetic status");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
proto_tree_add_item(sbusdata_tree, hf_sbus_flags_accu,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbusdata_tree, hf_sbus_flags_error,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbusdata_tree, hf_sbus_flags_negative,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbusdata_tree, hf_sbus_flags_zero,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset +=1;
break;
case SBUS_RD_BYTE:
dt = proto_tree_add_text(sbus_tree, tvb, offset,
(request_val->count),"Data (bytes)");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=(request_val->count); i>0; i--) {
proto_tree_add_item(sbusdata_tree,
hf_sbus_data_byte, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case SBUS_RD_INDEX_REGISTER:
dt = proto_tree_add_text(sbus_tree, tvb, offset,
2,"Data (hex bytes)");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=0; i<2; i++) {
proto_tree_add_item(sbusdata_tree,
hf_sbus_data_byte_hex, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
case SBUS_RD_INSTRUCTION_POINTER:
proto_tree_add_item(sbus_tree,
hf_sbus_addr_prog, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
break;
case SBUS_FIND_HISTORY:
proto_tree_add_item(sbus_tree,
hf_sbus_addr_68k, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(sbus_tree,
hf_sbus_nbr_elements, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case SBUS_RD_CURRENT_BLOCK:
proto_tree_add_item(sbus_tree,
hf_sbus_block_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_block_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case SBUS_RD_SYSTEM_INFORMATION:
if (request_val->sysinfo == 0x00){
offset += 1;
dt = proto_tree_add_text(sbus_tree, tvb, offset,
1,"System info");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
proto_tree_add_item(sbusdata_tree, hf_sbus_sysinfo0_1,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbusdata_tree, hf_sbus_sysinfo0_2,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbusdata_tree, hf_sbus_sysinfo0_3,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbusdata_tree, hf_sbus_sysinfo0_4,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sbusdata_tree, hf_sbus_sysinfo0_5,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
} else {
offset = (tvb_get_guint8(tvb,9) + 10);
}
break;
case SBUS_WEB_SERVER_SERIAL_COMM:
sbus_web_size = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_web_size, tvb, offset,
1, sbus_web_size);
offset += 1;
sbus_web_aid = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_web_aid, tvb, offset,
1, sbus_web_aid);
offset += 1;
if (sbus_web_size > 1) {
sbus_web_seq = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_web_seq, tvb, offset,
1, sbus_web_seq);
offset += 1;
dt = proto_tree_add_text(sbus_tree, tvb, offset,
(sbus_web_size - 2),"Data (bytes)");
sbusdata_tree = proto_item_add_subtree(dt, ett_sbus_data);
for (i=sbus_web_size - 2; i>0; i--) {
proto_tree_add_item(sbusdata_tree,
hf_sbus_data_byte, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
}
}
break;
case SBUS_RD_WR_PCD_BLOCK:
sbus_rdwr_block_tlg = request_val->block_tlg;
sbus_rdwr_length = tvb_get_guint8(tvb,offset);
proto_tree_add_uint(sbus_tree,
hf_sbus_rdwr_block_length, tvb, offset,
1, sbus_rdwr_length);
offset += 1;
hi = proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_acknakcode, tvb, offset,
1, ENC_BIG_ENDIAN);
if ((tvb_get_guint8(tvb, offset) >= SBUS_RD_WR_NAK)&&
(tvb_get_guint8(tvb, offset) <= SBUS_RD_WR_NAK_INVALID_SIZE)) {
expert_add_info(pinfo, hi, &ei_sbus_telegram_not_acked);
}
offset += 1;
switch(sbus_rdwr_block_tlg) {
case SBUS_WR_START_OF_STREAM:
case SBUS_WR_BLOCK_DATA_STREAM:
case SBUS_WR_BLOCK_END_OF_STREAM:
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_telegram_sequence, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
break;
case SBUS_WR_ABORT_BLOCK_STREAM:
case SBUS_RD_ABORT_BLOCK_STREAM:
case SBUS_WR_BLOCK_DATA_BYTES:
case SBUS_DELETE_BLOCK:
break;
case SBUS_RD_BLOCK_START_OF_STREAM:
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_telegram_sequence, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_size, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
offset += (sbus_rdwr_length-6);
break;
case SBUS_RD_BLOCK_DATA_STREAM:
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_telegram_sequence, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
offset += (sbus_rdwr_length-2);
break;
case SBUS_RD_BLOCK_DATA_BYTES:
offset += (sbus_rdwr_length-1);
break;
case SBUS_GET_BLOCK_SIZE:
sbus_rdwr_block_type = tvb_get_guint8(tvb, 10);
if (sbus_rdwr_block_type == SBUS_RD_WR_UNKNOWN_BLOCK_TYPE) {
} else {
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_size, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
offset += 4;
}
break;
case SBUS_GET_PROGRAM_BLOCK_LIST:
proto_tree_add_item(sbus_tree,
hf_sbus_block_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sbus_tree,
hf_sbus_block_nr, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sbus_tree,
hf_sbus_rdwr_block_size, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
offset += (sbus_rdwr_length-8);
break;
default:
break;
}
break;
default:
sbus_helper = sbus_eth_len - (offset + 2);
proto_tree_add_text(sbus_tree, tvb, offset, sbus_helper,
"This telegram isn't implemented in the dissector.");
offset = offset + sbus_helper;
break;
}
} else if (sbus_attribut == SBUS_RESPONSE && (!request_val)) {
sbus_eth_len = tvb_get_ntohl(tvb,0);
sbus_helper = sbus_eth_len - 11;
proto_tree_add_text(sbus_tree, tvb, offset, sbus_helper,
"Not dissected, could not find request telegram");
offset = sbus_eth_len - 2;
}
if (sbus_attribut == SBUS_ACKNAK) {
if (request_val) {
nstime_delta(&ns, &pinfo->fd->abs_ts, &request_val->req_time);
proto_tree_add_time(sbus_tree, hf_sbus_response_time,
tvb, 0, 0, &ns);
proto_tree_add_uint(sbus_tree, hf_sbus_response_to, tvb, 0, 0,
request_val->req_frame);
}
hi = proto_tree_add_item(sbus_tree,
hf_sbus_acknackcode, tvb, offset, 2, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb, (offset+1)) > 0) {
expert_add_info(pinfo, hi, &ei_sbus_telegram_not_acked);
}
offset += 2;
}
sbus_crc_calc = 0;
for (i = 0; i < sbus_eth_len - 2; i++)
sbus_crc_calc = crc_calc (sbus_crc_calc, tvb_get_guint8(tvb, i));
sbus_helper = tvb_get_ntohs(tvb, offset);
if (sbus_helper == sbus_crc_calc) {
proto_tree_add_uint_format_value(sbus_tree,
hf_sbus_crc, tvb, offset, 2, sbus_helper,
"0x%04x (correct)", sbus_helper);
} else {
cs = proto_tree_add_uint_format_value(sbus_tree,
hf_sbus_crc, tvb, offset, 2, sbus_helper,
"0x%04x (NOT correct)", sbus_helper);
expert_add_info(pinfo, cs, &ei_sbus_crc_bad);
hi = proto_tree_add_boolean(sbus_tree,
hf_sbus_crc_bad, tvb, offset, 2, TRUE);
PROTO_ITEM_SET_HIDDEN(hi);
PROTO_ITEM_SET_GENERATED(hi);
}
offset += 2;
}
return offset;
}
void
proto_register_sbus(void)
{
static hf_register_info hf[] = {
{ &hf_sbus_length,
{ "Length (bytes)", "sbus.len",
FT_UINT32, BASE_DEC, NULL, 0,
"SAIA Ether-S-Bus telegram length", HFILL }
},
{ &hf_sbus_version,
{ "Version", "sbus.vers",
FT_UINT8, BASE_DEC, NULL, 0,
"SAIA Ether-S-Bus version", HFILL }
},
{ &hf_sbus_protocol,
{ "Protocol type", "sbus.proto",
FT_UINT8, BASE_DEC, NULL, 0,
"SAIA Ether-S-Bus protocol type", HFILL }
},
{ &hf_sbus_sequence,
{ "Sequence", "sbus.seq",
FT_UINT16, BASE_DEC, NULL, 0,
"SAIA Ether-S-Bus sequence number", HFILL }
},
{ &hf_sbus_attribut,
{ "Telegram attribute", "sbus.att",
FT_UINT8, BASE_HEX, VALS(sbus_att_vals), 0,
"SAIA Ether-S-Bus telegram attribute, indicating type of telegram", HFILL }
},
{ &hf_sbus_dest,
{ "Destination", "sbus.destination",
FT_UINT8, BASE_DEC, NULL, 0,
"SAIA S-Bus destination address", HFILL }
},
{ &hf_sbus_address,
{ "S-Bus address", "sbus.address",
FT_UINT8, BASE_DEC, NULL, 0,
"SAIA S-Bus station address", HFILL }
},
{ &hf_sbus_command,
{ "Command", "sbus.cmd",
FT_UINT8, BASE_HEX, VALS(sbus_command_vals), 0,
"SAIA S-Bus command", HFILL }
},
{ &hf_sbus_command_extension,
{ "Command extension", "sbus.cmd_extn",
FT_UINT8, BASE_HEX, NULL, 0,
"SAIA S-Bus command extension", HFILL }
},
{ &hf_sbus_rcount,
{ "R-count", "sbus.rcount",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of elements expected in response", HFILL }
},
{ &hf_sbus_wcount,
{ "W-count (raw)", "sbus.wcount",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of bytes to be written", HFILL }
},
{ &hf_sbus_wcount_calculated,
{ "W-count (32 bit values)", "sbus.wcount_calc",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of elements to be written", HFILL }
},
{ &hf_sbus_fio_count,
{ "FIO Count (amount of bits)", "sbus.fio_count",
FT_UINT8, BASE_DEC, NULL, 0,
"Number of binary elements to be written", HFILL }
},
{ &hf_sbus_addr_rtc,
{ "Base address RTC", "sbus.addr_RTC",
FT_UINT16, BASE_DEC, NULL, 0,
"Base address of 32 bit elements to read", HFILL }
},
{ &hf_sbus_addr_iof,
{ "Base address IOF", "sbus.addr_IOF",
FT_UINT16, BASE_DEC, NULL, 0,
"Base address of binary elements to read", HFILL }
},
{ &hf_sbus_addr_eeprom,
{ "Base address of EEPROM register", "sbus.addr_EEPROM",
FT_UINT16, BASE_DEC, NULL, 0,
"Base address of 32 bit EEPROM register to read or write", HFILL }
},
{ &hf_sbus_addr_prog,
{ "Base address of user memory or program lines", "sbus.addr_prog",
FT_UINT24, BASE_DEC, NULL, 0,
"Base address of the user memory or program lines (read or write)", HFILL }
},
{ &hf_sbus_addr_68k,
{ "Base address of bytes", "sbus.addr_68k",
FT_UINT24, BASE_HEX, NULL, 0,
"Base address of bytes to read or write (68k address)", HFILL }
},
{ &hf_sbus_block_type,
{ "Block type", "sbus.block_type",
FT_UINT8, BASE_HEX, VALS(sbus_block_types), 0,
"Program block type", HFILL }
},
{ &hf_sbus_block_nr,
{ "Block/Element nr", "sbus.block_nr",
FT_UINT16, BASE_DEC, NULL, 0,
"Program block / DatatBlock number", HFILL }
},
{ &hf_sbus_nbr_elements,
{ "Number of elements", "sbus.nbr_elements",
FT_UINT16, BASE_DEC, NULL, 0,
"Number of elements or characters", HFILL }
},
{ &hf_sbus_display_register,
{ "PCD Display register", "sbus.data_display_register",
FT_UINT32, BASE_DEC, NULL, 0,
"The PCD display register (32 bit value)", HFILL }
},
{ &hf_sbus_data_rtc,
{ "S-Bus 32-bit data", "sbus.data_rtc",
FT_UINT32, BASE_DEC, NULL, 0,
"One regiser/timer of counter (32 bit value)", HFILL }
},
{ &hf_sbus_data_byte,
{ "Data bytes", "sbus.data_byte",
FT_UINT8, BASE_DEC, NULL, 0,
"One byte from PCD", HFILL }
},
{ &hf_sbus_data_byte_hex,
{ "Data bytes (hex)", "sbus.data_byte_hex",
FT_UINT8, BASE_HEX, NULL, 0,
"One byte from PCD (hexadecimal)", HFILL }
},
{ &hf_sbus_data_iof,
{ "S-Bus binary data", "sbus.data_iof",
FT_UINT32, BASE_DEC, NULL, 0,
"8 binaries", HFILL }
},
{ &hf_sbus_cpu_type,
{ "PCD type", "sbus.pcd_type",
FT_STRING, BASE_NONE, NULL, 0,
"PCD type (short form)", HFILL }
},
{ &hf_sbus_fw_version,
{ "Firmware version", "sbus.fw_version",
FT_STRING, BASE_NONE, NULL, 0,
"Firmware version of the PCD or module", HFILL }
},
{ &hf_sbus_sysinfo_nr,
{ "System information number", "sbus.sysinfo",
FT_UINT8, BASE_HEX, NULL, 0,
"System information number (extension to command code)", HFILL }
},
{ &hf_sbus_sysinfo0_1,
{ "Mem size info", "sbus.sysinfo0.mem",
FT_BOOLEAN, 8, TFS(&tfs_sbus_present), F_MEMSIZE,
"Availability of memory size information", HFILL }
},
{ &hf_sbus_sysinfo0_2,
{ "Trace buffer", "sbus.sysinfo0.trace",
FT_BOOLEAN, 8, TFS(&tfs_sbus_present), F_TRACE,
"Availability of trace buffer feature", HFILL }
},
{ &hf_sbus_sysinfo0_3,
{ "Slot B1", "sbus.sysinfo0.b1",
FT_BOOLEAN, 8, TFS(&tfs_sbus_present), F_INFO_B1,
"Presence of EEPROM information on slot B1", HFILL }
},
{ &hf_sbus_sysinfo0_4,
{ "Slot B2", "sbus.sysinfo0.b2",
FT_BOOLEAN, 8, TFS(&tfs_sbus_present), F_INFO_B2,
"Presence of EEPROM information on slot B2", HFILL }
},
{ &hf_sbus_sysinfo0_5,
{ "PGU baud", "sbus.sysinfo0.pgubaud",
FT_BOOLEAN, 8, TFS(&tfs_sbus_present), F_PGU_BAUD,
"Availability of PGU baud switch feature", HFILL }
},
#if 0
{ &hf_sbus_sysinfo_length,
{ "System information length", "sbus.sysinfo_length",
FT_UINT8, BASE_HEX, NULL, 0,
"System information length in response", HFILL }
},
#endif
#if 0
{ &hf_sbus_f_module_type,
{ "F-module type", "sbus.fmodule_type",
FT_STRING, BASE_NONE, NULL, 0,
"Module type mounted on B1/2 slot", HFILL }
},
#endif
#if 0
{ &hf_sbus_harware_version,
{ "Hardware version", "sbus.hw_version",
FT_STRING, BASE_NONE, NULL, 0,
"Hardware version of the PCD or the module", HFILL }
},
#endif
#if 0
{ &hf_sbus_hardware_modification,
{ "Hardware modification", "sbus.hw_modification",
FT_UINT8, BASE_DEC, NULL, 0,
"Hardware modification of the PCD or module", HFILL }
},
#endif
#if 0
{ &hf_sbus_various,
{ "Various data", "sbus.various",
FT_NONE, BASE_NONE, NULL, 0,
"Various data contained in telegrams but nobody will search for it", HFILL }
},
#endif
{ &hf_sbus_acknackcode,
{ "ACK/NAK code", "sbus.nakcode",
FT_UINT16, BASE_HEX, VALS(sbus_ack_nak_vals), 0,
"SAIA S-Bus ACK/NAK response", HFILL }
},
{ &hf_sbus_cpu_status,
{ "CPU status", "sbus.CPU_status",
FT_UINT8, BASE_HEX, VALS(sbus_CPU_status), 0,
"SAIA PCD CPU status", HFILL }
},
{ &hf_sbus_week_day,
{ "RTC calendar week and week day", "sbus.rtc.week_day",
FT_UINT16, BASE_HEX, NULL, 0,
"Calendar week and week day number of the real time clock", HFILL }
},
{ &hf_sbus_date,
{ "RTC date (YYMMDD)", "sbus.rtc.date",
FT_UINT24, BASE_HEX, NULL, 0,
"Year, month and day of the real time clock", HFILL }
},
{ &hf_sbus_time,
{ "RTC time (HHMMSS)", "sbus.rtc.time",
FT_UINT24, BASE_HEX, NULL, 0,
"Time of the real time clock", HFILL }
},
{ &hf_sbus_web_size,
{ "Web server packet size", "sbus.web.size",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_sbus_web_aid,
{ "AID", "sbus.web.aid",
FT_UINT8, BASE_HEX, NULL, 0,
"Web server command/status code (AID)", HFILL }
},
{ &hf_sbus_web_seq,
{ "Sequence", "sbus.web.seq",
FT_UINT8, BASE_HEX, NULL, 0,
"Web server sequence nr (PACK_N)", HFILL }
},
{ &hf_sbus_rdwr_block_length,
{ "Read/write block telegram length", "sbus.block.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_sbus_rdwr_block_length_ext,
{ "Extended length (bytes)", "sbus.len_ext",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_sbus_rdwr_telegram_type,
{ "Read/write block telegram type", "sbus.block.tlgtype",
FT_UINT8, BASE_HEX, VALS(rdwrblock_vals), 0,
"Type of RD/WR block telegram", HFILL }
},
{ &hf_sbus_rdwr_telegram_sequence,
{ "Sequence", "sbus.block.seq",
FT_UINT8, BASE_DEC, NULL, 0,
"Sequence number of block data stream telegram", HFILL }
},
{ &hf_sbus_rdwr_block_size,
{ "Block size in bytes", "sbus.block.size",
FT_UINT32, BASE_DEC, NULL, 0,
"The size of the block in bytes", HFILL }
},
{ &hf_sbus_rdwr_block_addr,
{ "Address inside block", "sbus.block.addr",
FT_UINT32, BASE_DEC, NULL, 0,
"The address inside a block", HFILL }
},
{ &hf_sbus_rdwr_file_name,
{ "File name", "sbus.block.filename",
FT_STRING, BASE_NONE, NULL, 0,
"Name of file to in RD/WR block telegram", HFILL }
},
{ &hf_sbus_rdwr_list_type,
{ "Get program block list, command type", "sbus.block.getlisttype",
FT_UINT8, BASE_HEX, VALS(rdwrblock_list_type_vals), 0,
"Type of the Get Program Block list request", HFILL }
},
{ &hf_sbus_rdwr_acknakcode,
{ "ACK/NAK code", "sbus.block.nakcode",
FT_UINT8, BASE_HEX, VALS(rdwrblock_sts), 0,
"ACK/NAK response for block write requests", HFILL }
},
{ &hf_sbus_crc,
{ "Checksum", "sbus.crc",
FT_UINT16, BASE_HEX, NULL, 0,
"CRC 16", HFILL }
},
{ &hf_sbus_crc_bad,
{ "Bad Checksum", "sbus.crc_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"A bad checksum in the telegram", HFILL }},
{ &hf_sbus_flags_accu,
{ "ACCU", "sbus.flags.accu",
FT_BOOLEAN, 8, TFS(&tfs_sbus_flags), F_ACCU,
"PCD Accumulator", HFILL }
},
{ &hf_sbus_flags_error,
{ "Error flag", "sbus.flags.error",
FT_BOOLEAN, 8, TFS(&tfs_sbus_flags), F_ERROR,
"PCD error flag", HFILL }
},
{ &hf_sbus_flags_negative,
{ "N-flag", "sbus.flags.nflag",
FT_BOOLEAN, 8, TFS(&tfs_sbus_flags), F_NEGATIVE,
"Negative status flag", HFILL }
},
{ &hf_sbus_flags_zero,
{ "Z-flag", "sbus.flags.zflag",
FT_BOOLEAN, 8, TFS(&tfs_sbus_flags), F_ZERO,
"Zero status flag", HFILL }
},
{ &hf_sbus_response_in,
{ "Response in frame nr.", "sbus.response_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this Ether-S-Bus request is in this frame", HFILL }
},
{ &hf_sbus_response_to,
{ "Request in frame nr.", "sbus.response_to",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the Ether-S-Bus request in this frame", HFILL }
},
{ &hf_sbus_response_time,
{ "Response time", "sbus.response_time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the request and the response", HFILL }
},
{ &hf_sbus_timeout,
{ "Time passed since first request", "sbus.timeout",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the first (identical) request and the repetition", HFILL }
},
{ &hf_sbus_request_in,
{ "First request in frame nr.", "sbus.request_in",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The first request of this repeated request is in this frame", HFILL }
}
};
static gint *ett[] = {
&ett_sbus,
&ett_sbus_ether,
&ett_sbus_data
};
static ei_register_info ei[] = {
{ &ei_sbus_retry, { "sbus.retry", PI_SEQUENCE, PI_NOTE, "Repeated telegram (due to timeout?)", EXPFILL }},
{ &ei_sbus_telegram_not_acked, { "sbus.telegram_not_acked", PI_RESPONSE_CODE, PI_CHAT, "Telegram not acknowledged by PCD", EXPFILL }},
{ &ei_sbus_crc_bad, { "sbus.crc_bad.expert", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
};
expert_module_t* expert_sbus;
proto_sbus = proto_register_protocol("SAIA S-Bus", "SBUS", "sbus");
proto_register_field_array(proto_sbus, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sbus = expert_register_protocol(proto_sbus);
expert_register_field_array(expert_sbus, ei, array_length(ei));
register_init_routine(&sbus_init_protocol);
}
void
proto_reg_handoff_sbus(void)
{
dissector_handle_t sbus_handle;
sbus_handle = new_create_dissector_handle(dissect_sbus, proto_sbus);
dissector_add_uint("udp.port", 5050, sbus_handle);
}
