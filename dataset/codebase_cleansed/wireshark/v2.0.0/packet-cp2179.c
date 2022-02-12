static tvbuff_t *
clean_telnet_iac(packet_info *pinfo, tvbuff_t *tvb, int offset, int len)
{
tvbuff_t *telnet_tvb;
guint8 *buf;
const guint8 *spos;
guint8 *dpos;
int skip_byte, len_remaining;
spos=tvb_get_ptr(tvb, offset, len);
buf=(guint8 *)g_malloc(len);
dpos=buf;
skip_byte = 0;
len_remaining = len;
while(len_remaining > 0){
if (len_remaining > 1) {
if((spos[0]==0xff) && (spos[1]==0xff)){
skip_byte++;
len_remaining -= 2;
*(dpos++)=0xff;
spos+=2;
continue;
}
}
*(dpos++)=*(spos++);
len_remaining--;
}
telnet_tvb = tvb_new_child_real_data(tvb, buf, len-skip_byte, len-skip_byte);
tvb_set_free_cb(telnet_tvb, g_free);
add_new_data_source(pinfo, telnet_tvb, "Processed Telnet Data");
return telnet_tvb;
}
static int
dissect_request_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, guint16 packet_type )
{
proto_tree *cp2179_proto_tree = NULL;
proto_tree *cp2179_addr_tree = NULL;
proto_tree *cp2179_fc_tree = NULL;
proto_item *cp2179_proto_item = NULL;
guint8 req_command_code = 0;
guint8 function_code = 0;
guint16 address_word = -1;
guint16 requestnumberofcharacters = 0;
cp2179_proto_item = proto_tree_add_item(tree, proto_cp2179, tvb, 0, -1, ENC_NA);
cp2179_proto_tree = proto_item_add_subtree(cp2179_proto_item, ett_cp2179_header);
address_word = tvb_get_letohs(tvb, offset);
cp2179_addr_tree = proto_tree_add_subtree_format(cp2179_proto_tree, tvb, offset, 2, ett_cp2179_addr, NULL,
"RTU Address: %d, Master Address: %d", (address_word & 0x7FF), ((address_word & 0xF800) >> 11) );
proto_tree_add_item(cp2179_addr_tree, hf_cp2179_rtu_address, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp2179_addr_tree, hf_cp2179_master_address, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
function_code = tvb_get_guint8(tvb, offset) & 0x3f;
cp2179_fc_tree = proto_tree_add_subtree_format(cp2179_proto_tree, tvb, offset, 1, ett_cp2179_fc, NULL,
"Function Code: %s (0x%02x)", val_to_str_const(function_code, FunctionCodenames, "Unknown Function Code"), function_code);
proto_tree_add_item(cp2179_fc_tree, hf_cp2179_function_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp2179_fc_tree, hf_cp2179_reserved, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
switch(packet_type)
{
case INIT_RTU_REQUEST:
case RESET_ACC_REQUEST:
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_command_code_fc20 , tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case BASIC_SCAN_QUERY_PACKET:
case SCAN_INCLUSIVE_16_ANALOG_REQUEST:
req_command_code = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " [ %s ]", val_to_str_ext_const(req_command_code, &cp2179_CommandCodeNames_ext, "Unknown Command Code"));
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_command_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_command_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
}
offset += 1;
requestnumberofcharacters = tvb_get_letohs(tvb, 4);
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_number_characters, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if ( requestnumberofcharacters > 0 ){
switch (packet_type)
{
case SBO_SELECT_REQUEST:
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_sbo_request_point, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case RESET_ACC_REQUEST:
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_resetacc_request_point, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
break;
case SPECIAL_CALC_REQUEST_RANGE:
do{
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_speccalc_request_point, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
break;
case SCAN_INCLUSIVE_16_ANALOG_REQUEST:
do{
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_scaninc_startreq_point, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_scaninc_stopreq_point, tvb, offset+1, 1, ENC_LITTLE_ENDIAN);
offset += 2;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
break;
}
}
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_crc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
return tvb_reported_length(tvb);
}
static int
dissect_bs_response_frame(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, guint16 packet_type)
{
proto_item *bs_response_item = NULL;
proto_item *cp2179_proto_item = NULL;
proto_item *cp2179_subdata_item = NULL;
proto_tree *cp2179_proto_tree = NULL;
proto_tree *cp2179_addr_tree = NULL;
proto_tree *cp2179_fc_tree = NULL;
proto_tree *cp2179_data_tree = NULL;
cp2179_conversation *conv;
guint32 req_frame_num;
guint16 req_address_word;
guint8 req_command_code;
gboolean request_found = FALSE;
bs_request_frame *request_data;
gint analogtestvalue = 0;
gint analog16_num = 0;
gint point_num = 0;
guint function_code;
guint simplestatusseq = 0x30;
guint16 address_word = 0;
guint16 numberofcharacters = -1;
gfloat specialcalvalue = 0;
cp2179_proto_item = proto_tree_add_item(tree, proto_cp2179, tvb, 0, -1, ENC_NA);
cp2179_proto_tree = proto_item_add_subtree(cp2179_proto_item, ett_cp2179_header);
address_word = tvb_get_letohs(tvb, offset);
cp2179_addr_tree = proto_tree_add_subtree_format(cp2179_proto_tree, tvb, offset, 2, ett_cp2179_addr, NULL,
"RTU Address: %d, Master Address: %d", (address_word & 0x7FF), ((address_word & 0xF800) >> 11) );
proto_tree_add_item(cp2179_addr_tree, hf_cp2179_rtu_address, tvb, 0, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp2179_addr_tree, hf_cp2179_master_address, tvb, 0, 2, ENC_LITTLE_ENDIAN);
offset += 2;
function_code = tvb_get_guint8(tvb, offset) & 0x3f;
cp2179_fc_tree = proto_tree_add_subtree_format(cp2179_proto_tree, tvb, offset, 1, ett_cp2179_fc, NULL,
"Function Code: %s (0x%02x)", val_to_str_const(function_code, FunctionCodenames, "Unknown Function Code"), function_code);
proto_tree_add_item(cp2179_fc_tree, hf_cp2179_function_code, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp2179_fc_tree, hf_cp2179_nop_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cp2179_fc_tree, hf_cp2179_rst_flag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_status_byte, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_port_status_byte, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
numberofcharacters = tvb_get_letohs(tvb, 5);
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_number_characters, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
conv = (cp2179_conversation *)p_get_proto_data(wmem_file_scope(), pinfo, proto_cp2179, 0);
if (conv) {
wmem_list_frame_t *frame = wmem_list_head(conv->bs_request_frame_data);
while (frame && !request_found) {
request_data = (bs_request_frame *)wmem_list_frame_data(frame);
req_frame_num = request_data->fnum;
req_command_code = request_data->commmand_code;
req_address_word = request_data->address_word;
if ((pinfo->fd->num > req_frame_num) && (req_address_word == address_word)) {
bs_response_item = proto_tree_add_uint(cp2179_proto_tree, hf_cp2179_request_frame, tvb, 0, 0, req_frame_num);
PROTO_ITEM_SET_GENERATED(bs_response_item);
request_found = TRUE;
}
frame = wmem_list_frame_next(frame);
}
if (request_found)
{
switch (packet_type)
{
case SBO_SELECT_RESPONSE:
case SBO_OPERATE_RESPONSE:
case RESET_ACC_RESPONSE:
case INIT_RTU_RESPONSE:
if ( numberofcharacters > 0 ){
if ( packet_type == SBO_SELECT_RESPONSE ){
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_sbo_request_point, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
if ( packet_type == RESET_ACC_RESPONSE ){
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_resetacc_request_point, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
}
break;
case SPECIAL_CALC_RESPONSE:
cp2179_data_tree = proto_tree_add_subtree(cp2179_proto_tree, tvb, offset, numberofcharacters, ett_cp2179_data, NULL, "CP2179 Data Field");
if (req_command_code == SPECIAL_CALC_ALL ){
do{
specialcalvalue = tvb_get_letohieee_float(tvb, offset );
proto_tree_add_float_format(cp2179_data_tree, hf_cp2179_specialcalc, tvb, offset, 4, specialcalvalue,
"Special Calculation %u : %f", point_num, specialcalvalue);
point_num += 1;
offset += 4;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
}
else if (req_command_code == SPECIAL_CALC_RANGE ){
do{
specialcalvalue = tvb_get_letohieee_float(tvb, offset );
proto_tree_add_float_format(cp2179_data_tree, hf_cp2179_specialcalc, tvb, offset, 4, specialcalvalue,
"Special Calculation %u : %f", request_data->requested_points[point_num], specialcalvalue);
point_num += 1;
offset += 4;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
}
break;
case SCAN_INCLUSIVE_16_ANALOG_RESPONSE:
cp2179_data_tree = proto_tree_add_subtree(cp2179_proto_tree, tvb, offset, numberofcharacters, ett_cp2179_data, NULL, "CP2179 Data Field");
col_append_fstr(pinfo->cinfo, COL_INFO, " [ %s ]", val_to_str_ext_const(req_command_code, &cp2179_CommandCodeNames_ext, "Unknown Command Code"));
do{
analogtestvalue = (gint16)tvb_get_letohs(tvb, offset);
proto_tree_add_uint_format(cp2179_data_tree, hf_cp2179_analog_16bit, tvb, offset, 2, request_data->requested_points[point_num],
"Analog (16 bit) %u : %i", request_data->requested_points[point_num], analogtestvalue);
point_num += 1;
offset += 2;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
break;
case BASIC_SCAN_RESPONSE_PACKET:
{
cp2179_data_tree = proto_tree_add_subtree(cp2179_proto_tree, tvb, offset, numberofcharacters, ett_cp2179_data, NULL, "CP2179 Data Field");
col_append_fstr(pinfo->cinfo, COL_INFO, " [ %s ]", val_to_str_ext_const(req_command_code, &cp2179_CommandCodeNames_ext, "Unknown Command Code"));
switch (req_command_code)
{
case ACCUMULATOR_16_BIT:
do{
analogtestvalue = tvb_get_letohs(tvb, offset);
proto_tree_add_uint_format(cp2179_data_tree, hf_cp2179_accumulator, tvb, offset, 2, analog16_num,
"Accumulator %u : %u", analog16_num, analogtestvalue);
analog16_num += 1;
offset += 2;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
break;
case ANALOG_16_BIT:
do{
analogtestvalue =(gint16)tvb_get_letohs(tvb, offset);
proto_tree_add_uint_format(cp2179_data_tree, hf_cp2179_analog_16bit, tvb, offset, 2, analog16_num,
"Analog (16 bit) %u : %i", analog16_num, analogtestvalue);
analog16_num += 1;
offset += 2;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
break;
case SIMPLE_STATUS_DATA:
do{
cp2179_subdata_item = proto_tree_add_bitmask(cp2179_data_tree, tvb, offset, hf_cp2179_simplestatusbit,
ett_cp2179_subdata, cp2179_simplestatus_bits, ENC_LITTLE_ENDIAN);
proto_item_set_text(cp2179_subdata_item, "Simple Status Point 0x%x", simplestatusseq);
simplestatusseq += 1;
offset += 2;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
break;
case TWO_BIT_STATUS:
do{
cp2179_subdata_item = proto_tree_add_bitmask(cp2179_data_tree, tvb, offset, hf_cp2179_2bitstatus,
ett_cp2179_subdata, cp2179_2bitstatus_bits, ENC_LITTLE_ENDIAN);
proto_item_set_text(cp2179_subdata_item, "2 Bit Status Point 0x%x", simplestatusseq);
simplestatusseq += 1;
offset += 2;
}while(tvb_reported_length_remaining(tvb, offset) > 2);
break;
}
}
break;
}
proto_tree_add_item(cp2179_proto_tree, hf_cp2179_crc, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
}
if (!request_found) {
proto_item_append_text(bs_response_item, ", No Request found");
return 0;
}
return tvb_reported_length(tvb);
}
static bs_request_frame* copy_bs_request_frame(tvbuff_t *tvb )
{
guint offset = 0;
guint8 idx=0 ;
bs_request_frame *frame;
guint16 num_objects=0;
frame = wmem_new(wmem_file_scope(), bs_request_frame);
frame->address_word = tvb_get_letohs(tvb, offset); offset +=2;
frame->function_code = tvb_get_guint8(tvb, offset); offset +=1;
frame->commmand_code = tvb_get_guint8(tvb, offset); offset +=1;
frame->numberofcharacters = tvb_get_letohs(tvb, offset);offset +=2;
if (frame->function_code == SCAN_INCLUSIVE) {
guint8 startpt, endpt;
startpt = tvb_get_guint8(tvb, offset);
endpt = tvb_get_guint8(tvb, offset+1);
num_objects = (endpt - startpt) + 1;
frame->requested_points = (guint8 *)wmem_alloc(wmem_file_scope(), num_objects * sizeof(guint8));
for (idx = 0; idx < num_objects; idx++) {
frame->requested_points[idx] = startpt;
startpt++;
}
}
else {
num_objects = frame->numberofcharacters;
frame->requested_points = (guint8 *)wmem_alloc(wmem_file_scope(), num_objects * sizeof(guint8));
for (idx = 0; idx < num_objects; idx++) {
frame->requested_points[idx] = tvb_get_guint8(tvb, offset);
offset += 1;
}
}
return frame;
}
static int
classify_packet_type(tvbuff_t *tvb)
{
int packet_type = -1;
guint8 function_code;
guint8 command_code;
guint16 requestnumberofcharacters = 0;
guint16 responsenumberofcharacters = 0;
guint16 packet_length = 0;
packet_length = tvb_reported_length(tvb);
function_code = tvb_get_guint8(tvb, 2);
command_code = tvb_get_guint8(tvb, 3);
requestnumberofcharacters = tvb_get_letohs(tvb, 4);
responsenumberofcharacters = tvb_get_letohs(tvb, 5);
function_code = function_code & 0x3f ;
switch (function_code ){
case BASIC_SCAN:
if ( (requestnumberofcharacters == 0) && (packet_length == BASIC_SCAN_REQ_LEN) ) {
packet_type = BASIC_SCAN_QUERY_PACKET ;
}
else if ( (responsenumberofcharacters > 0) && (packet_length > BASIC_SCAN_REQ_LEN) ) {
packet_type = BASIC_SCAN_RESPONSE_PACKET;
}
break;
case SUPERVISORY_CONTROL:
if ( (requestnumberofcharacters == 1) && (packet_length == SBO_SELECT_REQ_LEN) ) {
packet_type = SBO_SELECT_REQUEST;
}
else if ( (responsenumberofcharacters == 1) && (packet_length == SBO_SELECT_REPLY_LEN) ) {
packet_type = SBO_SELECT_RESPONSE;
}
else if (requestnumberofcharacters == 0) {
if ( (packet_length == SBO_OPERATE_REQ_LEN) && (command_code == SBO_OPERATE) ) {
packet_type = SBO_OPERATE_REQUEST;
}
}
else if (responsenumberofcharacters == 0) {
if (packet_length == SBO_OPERATE_REPLY_LEN) {
packet_type = SBO_OPERATE_RESPONSE;
}
}
break;
case SCAN_FOR_SPECIAL_CALC:
if ( (requestnumberofcharacters == 0) && (command_code == SPECIAL_CALC_ALL ) ) {
packet_type = SPECIAL_CALC_REQUEST_ALL;
}
else if ( (requestnumberofcharacters > 0) && (command_code == SPECIAL_CALC_RANGE ) ) {
packet_type = SPECIAL_CALC_REQUEST_RANGE;
}
else if ( (responsenumberofcharacters > 0) && (packet_length == (responsenumberofcharacters + 9) ) ) {
packet_type = SPECIAL_CALC_RESPONSE;
}
break;
case SCAN_INCLUSIVE:
if ( (responsenumberofcharacters > 0) ) {
packet_type = SCAN_INCLUSIVE_16_ANALOG_RESPONSE;
}
if( (command_code == ANALOG_16_BIT) && (requestnumberofcharacters == 2) ) {
packet_type = SCAN_INCLUSIVE_16_ANALOG_REQUEST;
}
break;
case RTU_CONFIG:
if (responsenumberofcharacters == 0) {
packet_type = INIT_RTU_RESPONSE;
}
if ( (requestnumberofcharacters == 0) && (command_code == INIT_RTU_CONFIGURATION) ) {
packet_type = INIT_RTU_REQUEST;
}
if (responsenumberofcharacters == 1) {
packet_type = RESET_ACC_RESPONSE;
}
if ( (requestnumberofcharacters == 1) && (command_code == RESET_ACCUMULATOR) ) {
packet_type = RESET_ACC_REQUEST;
}
break;
default :
packet_type = -99;
break;
}
return packet_type;
}
static int
dissect_cp2179_pdu(tvbuff_t *cp2179_tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
gint16 packet_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CP2179");
col_clear(pinfo->cinfo,COL_INFO);
packet_type = classify_packet_type(cp2179_tvb);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext_const(packet_type, &cp2179_packettype_vals_ext, "Unknown Packet Type"));
if (!pinfo->fd->flags.visited){
conversation_t *conversation = NULL;
cp2179_conversation *bs_conv_data = NULL;
conversation = find_or_create_conversation(pinfo);
bs_conv_data = (cp2179_conversation *)conversation_get_proto_data(conversation, proto_cp2179);
if (bs_conv_data == NULL){
bs_conv_data = wmem_new(wmem_file_scope(), cp2179_conversation);
bs_conv_data->bs_request_frame_data = wmem_list_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_cp2179, (void *)bs_conv_data);
}
p_add_proto_data(wmem_file_scope(), pinfo, proto_cp2179, 0, bs_conv_data);
if ((packet_type == BASIC_SCAN_QUERY_PACKET) || (packet_type == SBO_SELECT_REQUEST)
||(packet_type == SPECIAL_CALC_REQUEST_ALL)||(packet_type == SBO_OPERATE_REQUEST)
||(packet_type == SPECIAL_CALC_REQUEST_RANGE)||(packet_type == INIT_RTU_REQUEST)
||(packet_type == RESET_ACC_REQUEST)||(packet_type == SCAN_INCLUSIVE_16_ANALOG_REQUEST)) {
bs_request_frame *frame_ptr = NULL;
frame_ptr = copy_bs_request_frame(cp2179_tvb);
frame_ptr->fnum = pinfo->fd->num;
wmem_list_prepend(bs_conv_data->bs_request_frame_data, frame_ptr);
}
}
if (tvb_reported_length_remaining(cp2179_tvb, offset) > 0){
switch (packet_type){
case BASIC_SCAN_QUERY_PACKET:
case SBO_SELECT_REQUEST:
case SBO_OPERATE_REQUEST:
case SPECIAL_CALC_REQUEST_ALL:
case SPECIAL_CALC_REQUEST_RANGE:
case SCAN_INCLUSIVE_16_ANALOG_REQUEST:
case RESET_ACC_REQUEST:
case INIT_RTU_REQUEST:
dissect_request_frame(cp2179_tvb, tree, pinfo, offset, packet_type);
break;
case BASIC_SCAN_RESPONSE_PACKET:
case SBO_SELECT_RESPONSE:
case SBO_OPERATE_RESPONSE:
case SPECIAL_CALC_RESPONSE:
case SCAN_INCLUSIVE_16_ANALOG_RESPONSE:
case INIT_RTU_RESPONSE:
case RESET_ACC_RESPONSE:
dissect_bs_response_frame(cp2179_tvb, tree, pinfo, offset, packet_type);
break;
default:
break;
}
}
return tvb_reported_length(cp2179_tvb);
}
static int
dissect_cp2179(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tvbuff_t *cp2179_tvb;
gint length = tvb_reported_length(tvb);
if(length < CP2179_MIN_LENGTH){
return 0;
}
if((pinfo->srcport) && cp2179_telnet_clean){
cp2179_tvb = clean_telnet_iac(pinfo, tvb, 0, length);
}
else{
cp2179_tvb = tvb_new_subset_length( tvb, 0, length);
}
dissect_cp2179_pdu(cp2179_tvb, pinfo, tree, data);
return length;
}
void
proto_register_cp2179(void)
{
static hf_register_info hf[] =
{
{ &hf_cp2179_request_frame,
{ "Request Frame", "cp2179.request_frame",
FT_FRAMENUM, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_rtu_address,
{ "RTU Address", "cp2179.RTUAddress",
FT_UINT16, BASE_DEC,
NULL, 0x7FF,
NULL, HFILL }
},
{ &hf_cp2179_master_address,
{ "Master Address", "cp2179.MasterAddress",
FT_UINT16, BASE_DEC,
NULL, 0xF800,
NULL, HFILL }
},
{ &hf_cp2179_function_code,
{ "Function Code", "cp2179.functioncode",
FT_UINT8, BASE_HEX,
VALS(FunctionCodenames), 0x3F,
NULL, HFILL }
},
{ &hf_cp2179_nop_flag,
{ "NOP Flag", "cp2179.nop_flag",
FT_UINT8, BASE_DEC,
NULL, 0x40,
NULL, HFILL }
},
{ &hf_cp2179_rst_flag,
{ "RST Flag", "cp2179.rst_flag",
FT_UINT8, BASE_DEC,
NULL, 0x80,
NULL, HFILL }
},
{ &hf_cp2179_reserved,
{ "Reserved Bits", "cp2179.Reserved",
FT_UINT8, BASE_DEC,
NULL, 0xC0,
NULL, HFILL }
},
{ &hf_cp2179_command_code,
{ "Command Code", "cp2179.commandcode",
FT_UINT8, BASE_HEX,
VALS(cp2179_CommandCodeNames), 0x0,
NULL, HFILL }
},
{ &hf_cp2179_command_code_fc20,
{ "Command Code (FC 0x20)", "cp2179.commandcodeinitrtu",
FT_UINT8, BASE_HEX,
VALS(cp2179_FC20_CommandCodeNames), 0x0,
NULL, HFILL }
},
{ &hf_cp2179_status_byte,
{ "RTU Status", "cp2179.rtustatus",
FT_UINT8, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_port_status_byte,
{ "Port Status", "cp2179.portstatus",
FT_UINT8, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_sbo_request_point,
{ "SBO Request Point", "cp2179.sbo_requestpoint",
FT_UINT8, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_resetacc_request_point,
{ "Reset Accumulator Request Point", "cp2179.resetacc_requestpoint",
FT_UINT8, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_speccalc_request_point,
{ "Special Calc Request Point", "cp2179.speccalc_requestpoint",
FT_UINT8, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_scaninc_startreq_point,
{ "Start Request Point", "cp2179.scaninc_startreq_point",
FT_UINT8, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_scaninc_stopreq_point,
{ "Stop Request Point", "cp2179.scaninc_stopreq_point",
FT_UINT8, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_number_characters,
{ "Number of Characters", "cp2179.numberofcharacters",
FT_UINT16, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_crc,
{ "CRC", "cp2179.crc",
FT_UINT16, BASE_HEX,
0x0, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_cp2179_data_field,
{ "Data Field", "cp2179.datafield",
FT_UINT8, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
#endif
{ &hf_cp2179_accumulator,
{ "Accumulator", "cp2179.accumulator",
FT_UINT16, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_specialcalc,
{ "Special Calc", "cp2179.specialcalc",
FT_FLOAT, BASE_NONE,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_analog_16bit,
{ "Analog 16-bit", "cp2179.analogdata",
FT_UINT16, BASE_DEC,
0x0, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit,
{ "Simple Status Bit", "cp2179.simplestatusbit",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit0,
{ "Simple Status bit 0", "cp2179.simplestatusbit0",
FT_BOOLEAN, 16,
NULL, 0x0001,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit1,
{ "Simple Status bit 1", "cp2179.simplestatusbit1",
FT_BOOLEAN, 16,
NULL, 0x0002,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit2,
{ "Simple Status bit 2", "cp2179.simplestatusbit2",
FT_BOOLEAN, 16,
NULL, 0x0004,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit3,
{ "Simple Status bit 3", "cp2179.simplestatusbit3",
FT_BOOLEAN, 16,
NULL, 0x0008,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit4,
{ "Simple Status bit 4", "cp2179.simplestatusbit4",
FT_BOOLEAN, 16,
NULL, 0x0010,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit5,
{ "Simple Status bit 5", "cp2179.simplestatusbit5",
FT_BOOLEAN, 16,
NULL, 0x0020,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit6,
{ "Simple Status bit 6", "cp2179.simplestatusbit6",
FT_BOOLEAN, 16,
NULL, 0x0040,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit7,
{ "Simple Status bit 7", "cp2179.simplestatusbit7",
FT_BOOLEAN, 16,
NULL, 0x0080,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit8,
{ "Simple Status bit 8", "cp2179.simplestatusbit8",
FT_BOOLEAN, 16,
NULL, 0x0100,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit9,
{ "Simple Status bit 9", "cp2179.simplestatusbit9",
FT_BOOLEAN, 16,
NULL, 0x0200,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit10,
{ "Simple Status bit 10", "cp2179.simplestatusbit10",
FT_BOOLEAN, 16,
NULL, 0x0400,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit11,
{ "Simple Status bit 11", "cp2179.simplestatusbit11",
FT_BOOLEAN, 16,
NULL, 0x0800,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit12,
{ "Simple Status bit 12", "cp2179.simplestatusbit12",
FT_BOOLEAN, 16,
NULL, 0x1000,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit13,
{ "Simple Status bit 13", "cp2179.simplestatusbit13",
FT_BOOLEAN, 16,
NULL, 0x2000,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit14,
{ "Simple Status bit 14", "cp2179.simplestatusbit14",
FT_BOOLEAN, 16,
NULL, 0x4000,
NULL, HFILL }
},
{ &hf_cp2179_simplestatusbit15,
{ "Simple Status bit 15", "cp2179.simplestatusbit15",
FT_BOOLEAN, 16,
NULL, 0x8000,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatus,
{ "2 Bit Status", "cp2179.twobitstatus",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatuschg0,
{ "2 Bit Status Change 0", "cp2179.twobitstatuschg0",
FT_BOOLEAN, 16,
NULL, 0x0001,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatuschg1,
{ "2 Bit Status Change 1", "cp2179.twobitstatuschg1",
FT_BOOLEAN, 16,
NULL, 0x0002,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatuschg2,
{ "2 Bit Status Change 2", "cp2179.twobitstatuschg2",
FT_BOOLEAN, 16,
NULL, 0x0004,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatuschg3,
{ "2 Bit Status Change 3", "cp2179.twobitstatuschg3",
FT_BOOLEAN, 16,
NULL, 0x0008,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatuschg4,
{ "2 Bit Status Change 4", "cp2179.twobitstatuschg4",
FT_BOOLEAN, 16,
NULL, 0x0010,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatuschg5,
{ "2 Bit Status Change 5", "cp2179.twobitstatuschg5",
FT_BOOLEAN, 16,
NULL, 0x0020,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatuschg6,
{ "2 Bit Status Change 6", "cp2179.twobitstatuschg6",
FT_BOOLEAN, 16,
NULL, 0x0040,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatuschg7,
{ "2 Bit Status Change 7", "cp2179.twobitstatuschg7",
FT_BOOLEAN, 16,
NULL, 0x0080,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatusstatus0,
{ "2 Bit Status bit 0", "cp2179.twobitstatusbit0",
FT_BOOLEAN, 16,
NULL, 0x0100,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatusstatus1,
{ "2 Bit Status bit 1", "cp2179.twobitstatusbit1",
FT_BOOLEAN, 16,
NULL, 0x0200,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatusstatus2,
{ "2 Bit Status bit 2", "cp2179.twobitstatusbit2",
FT_BOOLEAN, 16,
NULL, 0x0400,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatusstatus3,
{ "2 Bit Status bit 3", "cp2179.twobitstatusbit3",
FT_BOOLEAN, 16,
NULL, 0x0800,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatusstatus4,
{ "2 Bit Status bit 4", "cp2179.twobitstatusbit4",
FT_BOOLEAN, 16,
NULL, 0x1000,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatusstatus5,
{ "2 Bit Status bit 5", "cp2179.twobitstatusbit5",
FT_BOOLEAN, 16,
NULL, 0x2000,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatusstatus6,
{ "2 Bit Status bit 6", "cp2179.twobitstatusbit6",
FT_BOOLEAN, 16,
NULL, 0x4000,
NULL, HFILL }
},
{ &hf_cp2179_2bitstatusstatus7,
{ "2 Bit Status bit 7", "cp2179.twobitstatusbit7",
FT_BOOLEAN, 16,
NULL, 0x8000,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_cp2179,
&ett_cp2179_header,
&ett_cp2179_addr,
&ett_cp2179_fc,
&ett_cp2179_data,
&ett_cp2179_subdata
};
module_t *cp2179_module;
proto_cp2179 = proto_register_protocol ("CP2179 Protocol", "CP2179", "cp2179");
new_register_dissector("cp2179", dissect_cp2179, proto_cp2179);
proto_register_field_array(proto_cp2179, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
cp2179_module = prefs_register_protocol(proto_cp2179, proto_reg_handoff_cp2179);
prefs_register_uint_preference(cp2179_module, "tcp.port", "CP 2179 Protocol Port",
"Set the TCP port for CP 2179 Protocol packets (if other"
" than the default of 0)",
10, &global_cp2179_tcp_port);
prefs_register_bool_preference(cp2179_module, "telnetclean",
"Enable Automatic pre-processing of Telnet-encapsulated data to remove extra 0xFF (IAC) bytes",
"Whether the SEL Protocol dissector should automatically pre-process Telnet data to remove IAC bytes",
&cp2179_telnet_clean);
}
void
proto_reg_handoff_cp2179(void)
{
static int cp2179_prefs_initialized = FALSE;
static dissector_handle_t cp2179_handle;
static unsigned int cp2179_port;
if (!cp2179_prefs_initialized){
cp2179_handle = new_create_dissector_handle(dissect_cp2179, proto_cp2179);
cp2179_prefs_initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", cp2179_port, cp2179_handle);
}
cp2179_port = global_cp2179_tcp_port;
dissector_add_uint("tcp.port", cp2179_port, cp2179_handle);
dissector_add_for_decode_as("rtacser.data", cp2179_handle);
}
