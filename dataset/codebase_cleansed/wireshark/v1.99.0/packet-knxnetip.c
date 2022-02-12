static void dissect_hpai(tvbuff_t *tvb, guint32 *offset, proto_tree *insert_tree, const char *append_text) {
proto_item *hpai_item = NULL;
proto_item *slength = NULL;
proto_tree *hpai_tree = NULL;
hpai_item = proto_tree_add_item( insert_tree, hf_knxnetip_hpai, tvb, *offset, 8, ENC_NA );
hpai_tree = proto_item_add_subtree(hpai_item, ett_knxnetip_hpai);
proto_item_append_text(hpai_item, "%s", append_text);
slength= proto_tree_add_item(hpai_tree, hf_knxnetip_hpai_structure_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(slength, " octets");
*offset+=1;
proto_tree_add_item(hpai_tree, hf_knxnetip_hpai_host_protocol, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(hpai_tree, hf_knxnetip_hpai_ip_address, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_item(hpai_tree, hf_knxnetip_hpai_port, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
}
static gboolean dissect_dib(tvbuff_t *tvb, guint32 *offset, proto_tree *insert_tree) {
proto_item *dib_item = NULL;
proto_item *struct_length = NULL;
proto_item *projectid_item = NULL;
proto_item *service_item = NULL;
proto_tree *dib_tree = NULL;
proto_tree *projectid_tree = NULL;
proto_tree *service_tree = NULL;
guint8 i;
guint8 dib_type;
guint8 length;
guint16 knx_address;
guint16 install_id;
length = tvb_get_guint8(tvb, *offset);
dib_item = proto_tree_add_item(insert_tree, hf_knxnetip_dib, tvb, *offset, length, ENC_NA);
dib_tree = proto_item_add_subtree(dib_item, ett_knxnetip_dib);
struct_length= proto_tree_add_item(dib_tree, hf_knxnetip_structure_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(struct_length, " octets");
*offset+=1;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_type, tvb, *offset, 1, ENC_BIG_ENDIAN);
dib_type = tvb_get_guint8(tvb, *offset);
proto_item_append_text(dib_item, ": %s", val_to_str_const(dib_type, knxnetip_dib_description_type_codes, "Unknown Type"));
*offset+=1;
switch (dib_type){
case(DIB_DEVICE_INFO):
proto_tree_add_item(dib_tree, hf_knxnetip_dib_medium, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_bitmask(dib_tree, tvb, *offset, hf_knxnetip_dib_status, ett_knxnetip_dib_status, dib_device_status_flags, ENC_BIG_ENDIAN);
*offset+=1;
knx_address = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint_format(dib_tree, hf_knxnetip_knxaddress, tvb, *offset, 2, knx_address, "KNX Address %d.%d.%d", ((knx_address & 0xF000)>>12),((knx_address & 0x0F00)>>8),(knx_address & 0xFF));
*offset+=2;
projectid_item = proto_tree_add_item(dib_tree, hf_knxnetip_dib_projectid, tvb, *offset, 2, ENC_BIG_ENDIAN);
projectid_tree = proto_item_add_subtree(projectid_item, ett_knxnetip_dib_projectid);
install_id = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint_format(projectid_tree, hf_knxnetip_projectnumber, tvb, *offset, 2, install_id, "Project number %d", (install_id & 0xFFF0)>>4);
proto_tree_add_uint_format(projectid_tree, hf_knxnetip_installnumber, tvb, *offset, 2, install_id, "Installation number %d", (install_id & 0xF));
*offset+=2;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_serialnumber, tvb, *offset, 6, ENC_NA);
*offset+=6;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_multicast_address, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_item(dib_tree, hf_knxnetip_mac_address, tvb, *offset, 6, ENC_NA);
*offset+=6;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_friendly, tvb, *offset, 30, ENC_ASCII|ENC_NA );
*offset+=30;
break;
case(DIB_SUPP_SVC):
if (length > 4) {
length-=4;
} else {
return TRUE;
}
for (i = 0; i <= length; i+=2) {
service_item = proto_tree_add_item(dib_tree, hf_knxnetip_dib_service, tvb, *offset, 1, ENC_BIG_ENDIAN);
service_tree = proto_item_add_subtree(service_item, ett_knxnetip_dib_service);
*offset+=1;
proto_tree_add_item(service_tree, hf_knxnetip_dib_svc_version, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
}
break;
case(DIB_IP_CONF):
proto_tree_add_item(dib_tree, hf_knxnetip_dib_ipaddress, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_subnet, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_gateway, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_bitmask(dib_tree, tvb, *offset, hf_knxnetip_dib_ipcapa, ett_knxnetip_dib_ipcapa, dib_ipcapabilities_flags, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_ipassign, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
break;
case(DIB_IP_CURRENT):
proto_tree_add_item(dib_tree, hf_knxnetip_dib_ipaddress, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_subnet, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_gateway, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_dhcp, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_ipassign, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(dib_tree, hf_knxnetip_reserved, tvb, *offset, 1, ENC_NA);
*offset+=1;
break;
case(DIB_KNX_ADDRESS):
if (length > 4) {
length-=4;
} else {
return TRUE;
}
for (i = 0; i <= length; i+=2) {
knx_address = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint_format(dib_tree, hf_knxnetip_knxaddress, tvb, *offset, 2, knx_address, "KNX Address %d.%d.%d", ((knx_address & 0xF000)>>12),((knx_address & 0x0F00)>>8),(knx_address & 0xFF));
*offset+=2;
}
break;
case(DIB_MFR_DATA):
if (length > 4) {
length-=4;
} else {
return TRUE;
}
proto_tree_add_item(dib_tree, hf_knxnetip_dib_manuid, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
proto_tree_add_item(dib_tree, hf_knxnetip_dib_manudata, tvb, *offset, length, ENC_ASCII|ENC_NA);
*offset+=length;
break;
}
return FALSE;
}
static guint dissect_cri(tvbuff_t *tvb, guint32 offset, proto_tree *insert_tree) {
proto_item *cri_item = NULL;
proto_item *cri_length = NULL;
proto_tree *cri_tree = NULL;
guint8 length;
length = tvb_get_guint8(tvb ,offset);
cri_item = proto_tree_add_item(insert_tree, hf_knxnetip_cri, tvb, offset, length, ENC_NA);
cri_tree = proto_item_add_subtree(cri_item, ett_knxnetip_cri);
cri_length= proto_tree_add_item(cri_tree, hf_knxnetip_structure_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(cri_length, " octets");
offset+=1;
proto_tree_add_item(cri_tree, hf_knxnetip_connection_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if (tvb_get_guint8(tvb,offset-1)== KNX_TUNNEL_CONNECTION ){
proto_tree_add_item(cri_tree, hf_knxnetip_knxlayer, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(cri_tree, hf_knxnetip_reserved, tvb, offset, 1, ENC_NA);
offset+=1;
}
else if (length > 2) {
proto_tree_add_item(cri_tree, hf_knxnetip_cri_protocol_data, tvb, offset, (length-2), ENC_NA);
offset+=(length-2);
}
return offset;
}
static void dissect_crd(tvbuff_t *tvb, guint32 *offset, proto_tree *insert_tree) {
proto_item *crd_item = NULL;
proto_item *crd_length = NULL;
proto_tree *crd_tree = NULL;
guint8 length;
guint16 knx_address;
length = tvb_get_guint8(tvb, *offset);
crd_item = proto_tree_add_item(insert_tree, hf_knxnetip_crd, tvb, *offset, length, ENC_NA);
crd_tree = proto_item_add_subtree(crd_item, ett_knxnetip_crd);
crd_length= proto_tree_add_item(crd_tree, hf_knxnetip_structure_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(crd_length, " octets");
*offset+=1;
proto_tree_add_item(crd_tree, hf_knxnetip_connection_type, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
if (tvb_get_guint8(tvb, *offset-1) == KNX_TUNNEL_CONNECTION){
knx_address = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint_format(crd_tree, hf_knxnetip_knxaddress, tvb, *offset, 2, knx_address, "KNX Address %d.%d.%d", ((knx_address & 0xF000)>>12),((knx_address & 0x0F00)>>8),(knx_address & 0xFF));
*offset+=2;
}
else if (length > 2) {
proto_tree_add_item(crd_tree, hf_knxnetip_crd_protocol_data, tvb, *offset, (length-2), ENC_NA);
*offset+=(length-2);
}
}
static guint dissect_connection_header(tvbuff_t *tvb, guint32 offset, proto_tree *insert_tree, gboolean have_status) {
proto_item *struct_length = NULL;
struct_length= proto_tree_add_item(insert_tree, hf_knxnetip_structure_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(struct_length, " octets");
offset+=1;
proto_tree_add_item(insert_tree, hf_knxnetip_communication_channel_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(insert_tree, hf_knxnetip_counter, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if (have_status == FALSE){
proto_tree_add_item(insert_tree, hf_knxnetip_reserved, tvb, offset, 1, ENC_NA);
offset+=1;
}
return offset;
}
static guint dissect_selector(tvbuff_t *tvb, guint32 offset, proto_tree *insert_tree){
proto_item *struct_length = NULL;
struct_length= proto_tree_add_item(insert_tree, hf_knxnetip_structure_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(struct_length, " octets");
offset+=1;
proto_tree_add_item(insert_tree, hf_knxnetip_selector_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
if (tvb_get_guint8(tvb, offset-1)==0x02){
proto_tree_add_item(insert_tree, hf_knxnetip_mac_address, tvb, offset, 6, ENC_NA);
offset+=6;
}
return offset;
}
static void dissect_apci(tvbuff_t *tvb, guint32 *offset, proto_tree *insert_tree, gboolean tpdu){
guint16 type;
guint8 length;
length = tvb_get_guint8(tvb, *offset-1);
if (tpdu == TRUE){
proto_tree_add_bits_item(insert_tree, hf_knxnetip_cemi_reserved, tvb, (*offset*8), 6, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_bits_item(insert_tree, hf_knxnetip_cemi_tpci, tvb, (*offset*8), 2, ENC_BIG_ENDIAN);
type = (tvb_get_guint8(tvb, *offset)&0xC0);
if (type == 0x40 || type == 0xC0){
proto_tree_add_bits_item(insert_tree, hf_knxnetip_cemi_counter, tvb, ((*offset*8)+2), 4, ENC_BIG_ENDIAN);
}
}
if (length != 0) {
type = (tvb_get_ntohs(tvb, *offset) & 0x03C0);
if (type == A_GROUPVALUE_RES || type == A_GROUPVALUE_WRT || type == A_ADC_RED){
proto_tree_add_bits_item(insert_tree, hf_knxnetip_cemi_apci, tvb, (*offset*8)+6, 4, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(insert_tree, hf_knxnetip_cemi_data, tvb, (*offset*8)+10, 6, ENC_BIG_ENDIAN);
}
else if(type == A_MEM_RED || type == A_MEM_RES || type == A_MEM_WRT ){
proto_tree_add_bits_item(insert_tree, hf_knxnetip_cemi_apci, tvb, (*offset*8)+6, 6, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(insert_tree, hf_knxnetip_cemi_apci_memory_number, tvb, (*offset*8)+12, 4, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_bits_item(insert_tree, hf_knxnetip_cemi_apci, tvb, (*offset*8)+6, 10, ENC_BIG_ENDIAN);
}
*offset+=2;
if (length >= 1){
length-=1;
}
if (length >= 1){
proto_tree_add_item(insert_tree, hf_knxnetip_data, tvb, *offset, -1, ENC_NA);
*offset+=length;
}
}
else {
*offset+=1;
}
}
static gboolean dissect_cemi(tvbuff_t *tvb, guint32 *offset, proto_tree *insert_tree, packet_info *pinfo){
proto_item *cemi_item = NULL;
proto_item *additional_info_totallength = NULL;
proto_item *additional_item = NULL;
proto_item *additional_info = NULL;
proto_item *tpdu_length = NULL;
proto_item *npdu_length = NULL;
proto_tree *cemi_tree = NULL;
proto_tree *additional_tree = NULL;
proto_tree *additional_subtree = NULL;
guint8 i;
guint8 messagecode;
guint8 length;
guint8 type_id;
guint8 noe;
guint8 num_of_octets;
guint16 knx_address;
guint16 six;
cemi_item = proto_tree_add_item(insert_tree, hf_knxnetip_cemi, tvb, *offset, -1, ENC_NA);
cemi_tree = proto_item_add_subtree(cemi_item, ett_knxnetip_cemi);
messagecode = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_mc, tvb, *offset, 1, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO, "| cEMI: %s", val_to_str(messagecode, cemi_messagecodes, "Unknown MC:0x%0x"));
*offset+=1;
if ((messagecode & 0xF0) < 0xF0){
length = tvb_get_guint8(tvb, *offset);
additional_info_totallength= proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_addlength, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(additional_info_totallength, " octets");
*offset+=1;
if (length != 0){
additional_info = proto_tree_add_item(cemi_tree, hf_knxnetip_additional, tvb, *offset, length, ENC_NA);
additional_tree = proto_item_add_subtree(additional_info, ett_knxnetip_cemi_additional);
do {
type_id = tvb_get_guint8(tvb, *offset);
additional_item = proto_tree_add_item(additional_tree, hf_knxnetip_cemi_typid, tvb, *offset, 1, ENC_BIG_ENDIAN);
additional_subtree = proto_item_add_subtree(additional_item, ett_knxnetip_cemi_additional_item);
*offset+=1;
additional_info_totallength= proto_tree_add_item(additional_item, hf_knxnetip_cemi_additemlength, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(additional_info_totallength, " octets");
*offset+=1;
if (length >= 2){
length-=2;
}
else{
return TRUE;
}
switch(type_id){
case(PL_INFO):
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_pl, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
if (length >= 2){
length-=2;
}
else{
return TRUE;
}
break;
case(RF_INFO):
proto_tree_add_bitmask(additional_subtree, tvb, *offset, hf_knxnetip_cemi_type_rf_info, ett_knxnetip_cemi_rf_info, cemi_rf_info, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_rf_sn, tvb, *offset, 6, ENC_BIG_ENDIAN);
*offset+=6;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_rf_lfn, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
if (length >= 8){
length-=8;
}
else{
return TRUE;
}
break;
case(BUSMON_INFO):
proto_tree_add_bitmask(additional_subtree, tvb, *offset, hf_knxnetip_cemi_type_bus, ett_knxnetip_cemi_bus_info, cemi_bus_flags, ENC_BIG_ENDIAN);
*offset+=1;
if (length >= 1){
length-=1;
}
else{
return TRUE;
}
break;
case(TIME_REL):
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_relt, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
if (length >= 2){
length-=2;
}
else{
return TRUE;
}
break;
case(TIME_DELAY):
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_delay, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
if (length >= 4){
length-=4;
}
else{
return TRUE;
}
break;
case(EXEND_TIME):
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_exttime, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset+=4;
if (length >= 4){
length-=4;
}
else{
return TRUE;
}
break;
case(BIBAT_INFO):
proto_tree_add_bits_item(additional_subtree, hf_knxnetip_cemi_type_bibat, tvb, (*offset*8), 4, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_bibat_block, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
if (length >= 2){
length-=2;
}
else{
return TRUE;
}
break;
case(RF_MULTI):
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_rf_multi_freq, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_rf_multi_channel, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_rf_multi_fastack, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_rf_multi_recep_freq, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
if (length >= 4){
length-=4;
}
else{
return TRUE;
}
break;
case(PREAMBEL):
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_preamble_length, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_type_postamble_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
if (length >= 3){
length-=3;
}
else{
return TRUE;
}
break;
case(RF_FAST_ACK):
num_of_octets = tvb_get_guint8(tvb, *offset-1);
for(i=0; i<num_of_octets; i++) {
proto_tree_add_bitmask(additional_subtree, tvb, *offset, hf_knxnetip_cemi_type_fastack, ett_knxnetip_cemi_fastack, cemi_fastack_flags, ENC_BIG_ENDIAN);
*offset+=2;
if (length >= 2){
length-=2;
}
else{
return TRUE;
}
}
break;
case(MANU_DATA):
num_of_octets = tvb_get_guint8(tvb, *offset-1);
proto_tree_add_item(additional_subtree, hf_knxnetip_dib_manuid, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_subfunction, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(additional_subtree, hf_knxnetip_cemi_manuspecificdata, tvb, *offset, (num_of_octets-3), ENC_NA);
*offset+=(num_of_octets-3);
if (length >= num_of_octets){
length-=num_of_octets;
}
else{
return TRUE;
}
break;
default:
proto_tree_add_item(additional_subtree, hf_knxnetip_unknown, tvb, *offset, -1, ENC_NA);
return *offset;
}
} while (length > 0);
}
}
switch (messagecode){
case(DATA_REQ):
case(DATA_CON):
case(DATA_IND):
case(POLL_DATA_REQ):
case(POLL_DATA_CON):
proto_tree_add_bitmask(cemi_tree, tvb, *offset, hf_knxnetip_cemi_controlfield1, ett_knxnetip_cemi_control1, cemi_control1_flags, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_bitmask(cemi_tree, tvb, *offset, hf_knxnetip_cemi_controlfield2, ett_knxnetip_cemi_control2, cemi_control2_flags, ENC_BIG_ENDIAN);
*offset+=1;
knx_address = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint_format(cemi_tree, hf_knxnetip_cemi_sourceaddress, tvb, *offset, 2, knx_address, "Source Address %d.%d.%d", ((knx_address & 0xF000)>>12),((knx_address & 0x0F00)>>8),(knx_address & 0xFF));
*offset+=2;
knx_address = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint_format(cemi_tree, hf_knxnetip_cemi_destaddress, tvb, *offset, 2, knx_address, "Destination Address %d/%d/%d", ((knx_address & 0xF000)>>12),((knx_address & 0x0F00)>>8),(knx_address & 0xFF));
*offset+=2;
if (messagecode == POLL_DATA_REQ){
proto_tree_add_bits_item(cemi_tree, hf_knxnetip_cemi_numberofslots, tvb, (*offset*8)+4, 4, ENC_BIG_ENDIAN);
*offset+=1;
}
else if (messagecode == POLL_DATA_CON){
proto_tree_add_bits_item(cemi_tree, hf_knxnetip_cemi_numberofslots, tvb, (*offset*8)+4, 4, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(cemi_tree, hf_knxnetip_polldata, tvb, *offset, -1, ENC_NA);
}
else {
npdu_length = proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_npdu_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(npdu_length, " octets");
*offset+=1;
dissect_apci(tvb, offset, cemi_tree, FALSE);
}
break;
case(RAW_REQ):
case(RAW_CON):
case(RAW_IND):
case(BUSMON_IND):
proto_tree_add_item(cemi_tree, hf_knxnetip_raw, tvb, *offset, -1, ENC_NA);
break;
case(DATA_INDV_IND):
case(DATA_INDV_REQ):
case(DATA_CONNEC_IND):
case(DATA_CONNEC_REQ):
proto_tree_add_item(cemi_tree, hf_knxnetip_reserved, tvb, *offset, 6, ENC_NA);
*offset+=6;
tpdu_length = proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_tpdu_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tpdu_length, " octets");
*offset+=1;
dissect_apci(tvb, offset, cemi_tree, TRUE);
break;
case(PROPREAD_REQ):
case(PROPREAD_CON):
case(PROPWRITE_REQ):
case(PROPWRITE_CON):
case(PROPINFO_IND):
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_iot, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_oi, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_pid, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
noe = ((tvb_get_guint8(tvb, *offset)& 0xF0)>>4);
proto_tree_add_bits_item(cemi_tree, hf_knxnetip_cemi_noe, tvb, (*offset*8), 4, ENC_BIG_ENDIAN);
six = tvb_get_bits16(tvb, (*offset*8+4), 12, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(cemi_tree, hf_knxnetip_cemi_six, tvb, (*offset*8)+4, 12, ENC_BIG_ENDIAN);
*offset+=2;
if (messagecode == PROPREAD_REQ || (messagecode == PROPREAD_CON && noe > 0)){
break;
}
else if (noe == 0){
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_error, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
}
else if (noe == 1 && six == 0){
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_numberofelements, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
}
else {
proto_tree_add_item(cemi_tree, hf_knxnetip_data, tvb, *offset, -1, ENC_NA);
}
break;
case(FUNCPROPCOM_REQ):
case(FUNCPROPSTATREAD_REQ):
case(FUNCPROPCOM_CON):
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_iot, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset+=2;
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_oi, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_pid, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
if (messagecode == FUNCPROPCOM_CON){
proto_tree_add_item(cemi_tree, hf_knxnetip_cemi_return, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset+=1;
}
proto_tree_add_item(cemi_tree, hf_knxnetip_data, tvb, *offset, -1, ENC_NA);
break;
case(RESET_REQ):
case(RESET_IND):
break;
default:
proto_tree_add_item(cemi_tree, hf_knxnetip_data, tvb, *offset, -1, ENC_NA);
}
return FALSE;
}
static void dissect_knxnetip (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
proto_item *knx_item = NULL;
proto_item *total_length = NULL;
proto_item *struct_length = NULL;
proto_item *busy_item = NULL;
proto_tree *knx_tree = NULL;
proto_tree *header_tree = NULL;
proto_tree *body_tree = NULL;
guint offset = 0;
guint16 service_type = 0;
gboolean err = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KNXnetIP");
col_clear(pinfo->cinfo,COL_INFO);
knx_item = proto_tree_add_item(tree, proto_knxnetip, tvb, 0, -1, ENC_NA);
knx_tree = proto_item_add_subtree(knx_item, ett_knxnetip);
header_tree = proto_tree_add_subtree(knx_tree, tvb, offset, 6, ett_knxnetip_header, NULL, "Header");
proto_tree_add_item(header_tree, hf_knxnetip_headerlength, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(header_tree, hf_knxnetip_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
service_type = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(header_tree, hf_knxnetip_servicetype, tvb, offset, 2, ENC_BIG_ENDIAN);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %d > %d", val_to_str(service_type, knxnetip_service_identifier, "Unknown Identifier:0x%02x"), pinfo->srcport, pinfo->destport);
offset+=2;
total_length = proto_tree_add_item(header_tree, hf_knxnetip_totallength, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(total_length, " octets");
offset+=2;
body_tree = proto_tree_add_subtree(knx_tree, tvb, offset, -1, ett_knxnetip_body, NULL, "Body");
switch(service_type) {
case(SEARCH_REQ):
dissect_hpai(tvb, &offset, body_tree, ": Discovery endpoint");
break;
case(SEARCH_RES):
dissect_hpai(tvb, &offset, body_tree, ": Control endpoint");
err = dissect_dib(tvb, &offset, body_tree);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
break;
}
err = dissect_dib(tvb, &offset, body_tree);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
break;
}
break;
case(DESCRIPTION_REQ):
dissect_hpai(tvb, &offset, body_tree, ": Control endpoint");
break;
case(DESCRIPTION_RES):
err = dissect_dib(tvb, &offset, body_tree);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
break;
}
err = dissect_dib(tvb, &offset, body_tree);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
break;
}
if (tvb_reported_length_remaining(tvb, offset) != 0){
err = dissect_dib(tvb, &offset, body_tree);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
}
}
break;
case(CONNECT_REQ):
dissect_hpai(tvb, &offset, body_tree, ": Discovery endpoint");
dissect_hpai(tvb, &offset, body_tree, ": Data endpoint");
offset = dissect_cri(tvb, offset, body_tree);
break;
case(CONNECT_RES):
proto_tree_add_item(body_tree, hf_knxnetip_communication_channel_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(body_tree, hf_knxnetip_connect_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
dissect_hpai(tvb, &offset, body_tree, ": Data endpoint");
dissect_crd(tvb, &offset, body_tree);
break;
case(CONNECTIONSTATE_REQ):
case(DISCONNECT_REQ):
proto_tree_add_item(body_tree, hf_knxnetip_communication_channel_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(body_tree, hf_knxnetip_reserved, tvb, offset, 1, ENC_NA);
offset+=1;
dissect_hpai(tvb, &offset, body_tree, ": Control endpoint");
break;
case(DISCONNECT_RES):
case(CONNECTIONSTATE_RES):
proto_tree_add_item(body_tree, hf_knxnetip_communication_channel_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(body_tree, hf_knxnetip_connectionstate_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
break;
case(DEVICE_CONFIGURATION_ACK):
offset = dissect_connection_header(tvb, offset, body_tree, TRUE);
proto_tree_add_item(body_tree, hf_knxnetip_confack_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
break;
case(DEVICE_CONFIGURATION_REQ):
case(TUNNELLING_REQ):
offset = dissect_connection_header(tvb, offset, body_tree, FALSE);
err = dissect_cemi (tvb, &offset, body_tree, pinfo);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
}
break;
case(TUNNELLING_ACK):
offset = dissect_connection_header(tvb, offset, body_tree, TRUE);
proto_tree_add_item(body_tree, hf_knxnetip_tunnelack_status, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case(ROUTING_INDICATION):
err = dissect_cemi (tvb, &offset, body_tree, pinfo);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
}
break;
case(ROUTING_LOST):
struct_length= proto_tree_add_item(body_tree, hf_knxnetip_structure_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(struct_length, " octets");
offset+=1;
proto_tree_add_bitmask(body_tree, tvb, offset, hf_knxnetip_devicestate, ett_knxnetip_devicestate, devicestate_flags, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(body_tree, hf_knxnetip_numberoflost, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case(ROUTING_BUSY):
struct_length= proto_tree_add_item(body_tree, hf_knxnetip_structure_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(struct_length, " octets");
offset+=1;
proto_tree_add_bitmask(body_tree, tvb, offset, hf_knxnetip_devicestate, ett_knxnetip_devicestate, devicestate_flags, ENC_BIG_ENDIAN);
offset+=1;
busy_item = proto_tree_add_item(body_tree, hf_knxnetip_busywaittime, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(busy_item, " ms");
offset+=2;
proto_tree_add_item(body_tree, hf_knxnetip_busycontrol, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
case(REMOTE_DIAG_REQ):
dissect_hpai(tvb, &offset, body_tree, ": Discovery endpoint");
offset = dissect_selector(tvb ,offset, body_tree);
break;
case(REMOTE_DIAG_RES):
offset = dissect_selector(tvb ,offset, body_tree);
do{
err = dissect_dib(tvb, &offset, body_tree);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
break;
}
} while (tvb_reported_length_remaining(tvb,offset) > 0);
break;
case(REMOTE_BASIC_CONF_REQ):
dissect_hpai(tvb, &offset, body_tree, ": Discovery endpoint");
offset = dissect_selector(tvb ,offset, body_tree);
err = dissect_dib(tvb, &offset, body_tree);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
break;
}
if (tvb_reported_length_remaining(tvb,offset) > 0) {
err = dissect_dib(tvb, &offset, body_tree);
if (err == TRUE){
proto_tree_add_expert(body_tree, pinfo, &ei_knxnetip_length, tvb, offset, -1);
}
}
break;
case(REMOTE_RESET_REQ):
offset = dissect_selector(tvb ,offset, body_tree);
proto_tree_add_item(body_tree, hf_knxnetip_reset, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(body_tree, hf_knxnetip_reserved, tvb, offset, 1, ENC_NA);
offset+=1;
break;
default:
proto_tree_add_item(body_tree, hf_knxnetip_unknown, tvb, offset, -1, ENC_NA);
}
}
static gboolean dissect_knxnetip_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
gint idx;
idx = 0;
if (tvb_length(tvb) < 8){
return (FALSE);
}
if ( tvb_get_guint8(tvb, 0) != KNXNETIP_HEADER_LENGTH) {
return (FALSE);
}
if ( tvb_get_guint8(tvb, 1) != KNXNETIP_PROTOCOL_VERSION){
return (FALSE);
}
try_val_to_str_idx((guint32)tvb_get_ntohs(tvb, 2), knxnetip_service_identifier, &idx);
if (idx == -1){
return (FALSE);
}
dissect_knxnetip(tvb, pinfo, tree);
return (TRUE);
}
void proto_register_knxnetip (void) {
expert_module_t* expert_knxnetip;
static hf_register_info hf[] = {
{ &hf_knxnetip_headerlength,
{ "Header Length", "knxnetip.headerlength", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_version,
{ "Protocol Version", "knxnetip.version", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_servicetype,
{ "Service Type Identifier", "knxnetip.servicetype", FT_UINT16, BASE_HEX, VALS(knxnetip_service_identifier), 0x0, NULL, HFILL }},
{ &hf_knxnetip_totallength,
{ "Total Length", "knxnetip.totallength", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_hpai,
{ "HPAI", "knxnetip.hpai", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_hpai_structure_length,
{ "Structure Length", "knxnetip.hpailength", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_structure_length,
{ "Structure Length", "knxnetip.structlength", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_hpai_host_protocol,
{ "Host Protocol Code", "knxnetip.hpaihostprotocol", FT_UINT8, BASE_HEX, VALS(knxnetip_host_protocol_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_hpai_ip_address,
{ "IP Address", "knxnetip.hpaiip", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_hpai_port,
{ "IP Port", "knxnetip.hpaiport", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib,
{ "DIB", "knxnetip.dib", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cri,
{ "Connection Request Information", "knxnetip.cri", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_type,
{ "Description Type", "knxnetip.dibtype", FT_UINT8, BASE_HEX, VALS(knxnetip_dib_description_type_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_medium,
{ "KNX medium", "knxnetip.dibmedium", FT_UINT8, BASE_HEX, VALS(knxnetip_dib_medium_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_status,
{ "Device Status", "knxnetip.dibstatus", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_projectid,
{ "Project-Installation identifier", "knxnetip.dibprojectid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_knxaddress,
{ "KNX Individual Address", "knxnetip.knxaddress", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_serialnumber,
{ "KNXnet/IP device serial number", "knxnetip.serialnumber", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_multicast_address,
{ "KNXnet/IP device multicast address", "knxnetip.multicast", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_mac_address,
{ "KNXnet/IP device MAC address", "knxnetip.macaddress", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_friendly,
{ "Device Friendly Name", "knxnetip.devicename", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_service,
{ "Service ID", "knxnetip.dibservice", FT_UINT8, BASE_HEX, VALS(knxnetip_service_types), 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_ipaddress,
{ "IP Address", "knxnetip.dibipaddress", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_subnet,
{ "Subnet Mask", "knxnetip.dibsubnet", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_gateway,
{ "Default Gateway", "knxnetip.dibgateway", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_ipcapa,
{ "IP Capabilities", "knxnetip.dibipcapabilities", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_ipassign,
{ "IP assignment method", "knxnetip.dibassignment", FT_UINT8, BASE_HEX, VALS(knxnetip_ip_assignment_method), 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_dhcp,
{ "DHCP Server", "knxnetip.dibdhcp", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_manuid,
{ "Manufacturer ID", "knxnetip.manid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_manudata,
{ "Manufacturer specific data", "knxnetip.mandata", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_connection_type,
{ "Connection Type", "knxnetip.contype", FT_UINT8, BASE_HEX, VALS(knxnetip_connection_types), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cri_protocol_data,
{ "Protocol Data", "knxnetip.cridata", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_communication_channel_id,
{ "Communication Channel ID", "knxnetip.commid", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_connect_status,
{ "Status", "knxnetip.connectstatus", FT_UINT8, BASE_HEX, VALS(knxnetip_connect_response_status_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_crd_protocol_data,
{ "Protocol Data", "knxnetip.crddata", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_crd,
{ "Connection Response Data Block", "knxnetip.crd", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_connectionstate_status,
{ "Status", "knxnetip.connectstatestatus", FT_UINT8, BASE_HEX, VALS(knxnetip_connectionstate_response_status_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_counter,
{ "Sequence Counter", "knxnetip.sequencecounter", FT_UINT8, BASE_DEC, 0x0, 0x0, NULL, HFILL }},
{ &hf_knxnetip_confack_status,
{ "Status", "knxnetip.confackstatus", FT_UINT8, BASE_HEX, VALS(knxnetip_device_configuration_ack_status_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_tunnelack_status,
{ "Status", "knxnetip.tunnelstatus", FT_UINT8, BASE_HEX, VALS(knxnetip_tunneling_error_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_status_flag_reserved,
{ "reserved", "knxnetip.dibreserved", FT_UINT8, BASE_HEX, NULL, FLAGS_DEVICESTATUS_RESERVED, NULL, HFILL }},
{ &hf_knxnetip_dib_status_flag_program,
{ "program mode", "knxnetip.dibprog", FT_UINT8, BASE_DEC, NULL, FLAGS_DEVICESTATUS_PROGRAM, NULL , HFILL }},
{ &hf_knxnetip_dib_ipcapa_flag_reserved,
{ "reserved", "knxnetip.ipcapareserved", FT_UINT8, BASE_HEX, NULL, FLAGS_IPCAPABILITES_RESERVED, NULL, HFILL }},
{ &hf_knxnetip_dib_ipcapa_flag_bootip,
{ "BootIP", "knxnetip.ipcapabootip", FT_UINT8, BASE_DEC, NULL, FLAGS_IPCAPABILITES_BOOTIP, NULL, HFILL }},
{ &hf_knxnetip_dib_ipcapa_flag_dhcp,
{ "DHCP", "knxnetip.ipcapadhcp", FT_UINT8, BASE_DEC, NULL, FLAGS_IPCAPABILITES_DHCP, NULL, HFILL }},
{ &hf_knxnetip_dib_ipcapa_flag_autoip,
{ "AutoIP", "knxnetip.ipcapaautoip", FT_UINT8, BASE_DEC, NULL, FLAGS_IPCAPABILITES_AUTOIP, NULL, HFILL }},
{ &hf_knxnetip_devicestate,
{ "DeviceState", "knxnetip.devicestate", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_devicestate_reserved,
{ "reserved", "knxnetip.devicestatereserved", FT_UINT8, BASE_HEX, NULL, FLAGS_DEVICESTATE_RESERVED, NULL, HFILL }},
{ &hf_knxnetip_devicestate_knx,
{ "KNX Fault", "knxnetip.devicestateknx", FT_UINT8, BASE_DEC, NULL, FLAGS_DEVICESTATE_KNX, "is set if KNX network cannot be accessed", HFILL }},
{ &hf_knxnetip_devicestate_ip,
{ "IP Fault", "knxnetip.devicestateip", FT_UINT8, BASE_DEC, NULL, FLAGS_DEVICESTATE_IP, "is set if IP network cannot be accessed", HFILL }},
{ &hf_knxnetip_numberoflost,
{ "NumberofLostMessages", "knxnetip.losmessages", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_busywaittime,
{ "Busy Wait Time", "knxnetip.busytime", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_busycontrol,
{ "Busy Control Field", "knxnetip.busycontrol", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_knxlayer,
{ "KNX Layer", "knxnetip.layer", FT_UINT8, BASE_HEX, VALS(knxnetip_knxlayer_values), 0x0, NULL, HFILL }},
{ &hf_knxnetip_selector_type,
{ "Selector Type Code", "knxnetip.selector", FT_UINT8, BASE_HEX, VALS(knxnetip_selector_types), 0x0, NULL, HFILL }},
{ &hf_knxnetip_reset,
{ "Reset Command", "knxnetip.reset", FT_UINT8, BASE_HEX, VALS(knxnetip_reset_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi,
{ "cEMI", "knxnetip.cemi", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_mc,
{ "messagecode", "knxnetip.cemimc", FT_UINT8, BASE_HEX, VALS(cemi_messagecodes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_addlength,
{ "add information length", "knxnetip.addlength", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_additemlength,
{ "Length", "knxnetip.addlength", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_typid,
{ "Type id", "knxnetip.cemitypeid", FT_UINT8, BASE_HEX, VALS(cemi_add_type_id), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_pl,
{ "Domain-Address", "knxnetip.cemitypepl", FT_UINT16, BASE_HEX, 0x0, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bus,
{ "Busmonitor error flags", "knxnetip.cemitypebus", FT_UINT8, BASE_HEX, 0x0, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_relt,
{ "relative timestamp", "knxnetip.cemitypereltime", FT_UINT16, BASE_HEX, 0x0, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_delay,
{ "delay", "knxnetip.cemitypedelay", FT_UINT32, BASE_HEX, 0x0, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_exttime,
{ "extended timestamp", "knxnetip.cemitypeexttime", FT_UINT32, BASE_HEX, 0x0, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bibat,
{ "BiBat", "knxnetip.cemitypebibat", FT_UINT8, BASE_HEX, VALS(cemi_bibat_ctrl), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_controlfield1,
{ "Controlfield 1", "knxnetip.controlone", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_flag_frametype,
{ "Frametype", "knxnetip.controltype", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_CONTROL1_FT, "0: extended frame; 1: standard frame", HFILL }},
{ &hf_knxnetip_cemi_flag_repeat,
{ "Repeat", "knxnetip.controlrepeat", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_CONTROL1_R, "0: repeat if error frame; 1: do not repeat", HFILL }},
{ &hf_knxnetip_cemi_flag_sb,
{ "System-Broadcast", "knxnetip.controlcast", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_CONTROL1_SB, "0: system-broadcast; 1: broadcast", HFILL }},
{ &hf_knxnetip_cemi_flag_priority,
{ "Priority", "knxnetip.controlprio", FT_UINT8, BASE_HEX, NULL, FLAGS_CEMI_CONTROL1_P, NULL, HFILL }},
{ &hf_knxnetip_cemi_flag_ack,
{ "Acknowledge-Request", "knxnetip.controlack", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_CONTROL1_A, "0: no request for ack; 1: request ack", HFILL }},
{ &hf_knxnetip_cemi_flag_confirm,
{ "Confirm-Flag", "knxnetip.controlconf", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_CONTROL1_C, "0: no error in frame; 1: error in frame", HFILL }},
{ &hf_knxnetip_cemi_controlfield2,
{ "Controlfield 2", "knxnetip.controltwo", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_flag_destaddress,
{ "Destination address type", "knxnetip.controldestaddress", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_CONTROL2_AT, "0: individual; 1: group", HFILL }},
{ &hf_knxnetip_flag_hop,
{ "Hop count", "knxnetip.controlhop", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_CONTROL2_HC, NULL, HFILL }},
{ &hf_knxnetip_flag_eff,
{ "Extended Frame Format", "knxnetip.controleff", FT_UINT8, BASE_HEX, NULL, FLAGS_CEMI_CONTROL2_EFF, "0000b for standard frame", HFILL }},
{ &hf_knxnetip_cemi_sourceaddress,
{ "Source Address", "knxnetip.cemisource", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_destaddress,
{ "Destination Address", "knxnetip.cemidestination", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_tpci,
{ "TPCI", "knxnetip.cemitpci", FT_UINT8, BASE_HEX, VALS(cemi_tpci_vals), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_npdu_length,
{ "NPDU length", "knxnetip.npdulength", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_tpdu_length,
{ "TPDU length", "knxnetip.tpdulength", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_counter,
{ "sequence NCD/NDT", "knxnetip.npduseq", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_apci,
{ "APCI", "knxnetip.npduapci", FT_UINT16, BASE_HEX, VALS(cemi_apci_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_data,
{ "Data", "knxnetip.cemidata", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_numberofslots,
{ "number of slots", "knxnetip.ceminumberofslots", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_apci_memory_number,
{ "number of octets to be read/write", "knxnetip.cemidata", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_iot,
{ "Interface object type", "knxnetip.cemiiot", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_oi,
{ "Object Instance", "knxnetip.cemioi", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_pid,
{ "Property Identifier", "knxnetip.cemipid", FT_UINT8, BASE_DEC, VALS(cemi_propertyid), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_noe,
{ "Number of Elements", "knxnetip.ceminoe", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_six,
{ "Startindex", "knxnetip.cemipid", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_numberofelements,
{ "Number of Elements", "knxnetip.ceminumber", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_error,
{ "Error Code", "knxnetip.cemierror", FT_UINT8, BASE_HEX, VALS(cemi_error_codes), 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_return,
{ "retrun code", "knxnetip.cemireturn", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_reserved,
{ "reserved", "knxnetip.cemireserved", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_info,
{ "RF-Info", "knxnetip.cemirfinfo", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_mesure,
{ "received signal strength", "knxnetip.cemirfmesure", FT_UINT8, BASE_HEX, NULL, FLAGS_CEMI_RF_MESURE, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_reserved,
{ "reserved", "knxnetip.cemirfreserved", FT_UINT8, BASE_HEX, NULL, FLAGS_CEMI_RF_RESERVED, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_mesure_re,
{ "retransmitter signal strrength", "knxnetip.cemirfmesurere", FT_UINT8, BASE_HEX, NULL, FLAGS_CEMI_RF_MESURE_RE, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_battery,
{ "Battery state", "knxnetip.cemirfbattery", FT_UINT8, BASE_HEX, NULL, FLAGS_CEMI_RF_BATTERY, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_bidirekt,
{ "is not bidirektional", "knxnetip.cemirfbattery", FT_UINT8, BASE_HEX, NULL, FLAGS_CEMI_RF_BIDIRETIONAL, NULL, HFILL }},
{ &hf_knxnetip_cemi_rf_sn,
{ "KNX Serial Number", "knxnetip.cemiknxsn", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_rf_lfn,
{ "Data Link Layer frame number", "knxnetip.cemilfn", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bus_flag_f,
{ "Frame error flag", "knxnetip.cemibusferror", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_BUS_F, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bus_flag_b,
{ "Bit error flag", "knxnetip.cemibusberror", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_BUS_B, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bus_flag_p,
{ "Parity error flag", "knxnetip.cemibusparity", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_BUS_P, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bus_flag_d,
{ "dont care", "knxnetip.cemibusdont", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_BUS_D, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bus_flag_l,
{ "Lost flag", "knxnetip.cemibuslost", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_BUS_L, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bus_flag_sss,
{ "Sequence Number", "knxnetip.cemibusseq", FT_UINT8, BASE_DEC, NULL, FLAGS_CEMI_BUS_SSS, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_bibat_block,
{ "BiBat Block number", "knxnetip.cemibibbatblock", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_multi_fastack,
{ "KNX RF Multi Fast Ack", "knxnetip.cemirffastack", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_multi_freq,
{ "KNX RF Multi Transmission Frequency", "knxnetip.cemirffreq", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_multi_channel,
{ "KNX RF Multi Call Channel", "knxnetip.cemirfchannel", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_rf_multi_recep_freq,
{ "KNX RF Multi Reception Frequency", "knxnetip.cemirfrecfreq", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_preamble_length,
{ "Preamble Length", "knxnetip.cemipreamblelength", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_postamble_length,
{ "Postamble Length", "knxnetip.cemipostamblelength", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_fastack,
{ "Fast Ack information", "knxnetip.cemifastack", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_fastack_crc,
{ "Fast Ack is received with a CRC", "knxnetip.cemifastackcrc", FT_UINT16, BASE_DEC, NULL, FLAGS_CEMI_FASTACK_CRC, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_fastack_error,
{ "Fast Ack is received with a Manchester error", "knxnetip.cemifastackerror", FT_UINT16, BASE_DEC, NULL, FLAGS_CEMI_FASTACK_ERROR, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_fastack_received,
{ "Fast Ack has been received", "knxnetip.cemifastackres", FT_UINT16, BASE_DEC, NULL, FLAGS_CEMI_FASTACK_RES, NULL, HFILL }},
{ &hf_knxnetip_cemi_type_fastack_info,
{ "Fast Ack Info", "knxnetip.cemifastackinfo", FT_UINT16, BASE_HEX, NULL, FLAGS_CEMI_FASTACK_INFO, NULL, HFILL }},
{ &hf_knxnetip_cemi_subfunction,
{ "Subfunction", "knxnetip.cemisubfunction", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_cemi_manuspecificdata,
{ "Manufacturer specific data", "knxnetip.cemimanuspecificdata", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_projectnumber,
{ "Project number", "knxnetip.projectnumber", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_installnumber,
{ "Installation number", "knxnetip.installnumber", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_dib_svc_version,
{ "Version", "knxnetip.svcversion", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_reserved,
{ "reserved", "knxnetip.reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_data,
{ "data", "knxnetip.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_polldata,
{ "Poll data", "knxnetip.polldata", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_raw,
{ "RAW Frame", "knxnetip.raw", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_additional,
{ "Additional information", "knxnetip.additional", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_knxnetip_unknown,
{ "UNKNOWN", "knxnetip.unknown", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_knxnetip,
&ett_knxnetip_header,
&ett_knxnetip_body,
&ett_knxnetip_hpai,
&ett_knxnetip_dib,
&ett_knxnetip_dib_projectid,
&ett_knxnetip_dib_service,
&ett_knxnetip_cri,
&ett_knxnetip_crd,
&ett_knxnetip_dib_status,
&ett_knxnetip_dib_ipcapa,
&ett_knxnetip_devicestate,
&ett_knxnetip_cemi,
&ett_knxnetip_cemi_additional,
&ett_knxnetip_cemi_additional_item,
&ett_knxnetip_cemi_control1,
&ett_knxnetip_cemi_control2,
&ett_knxnetip_cemi_rf_info,
&ett_knxnetip_cemi_bus_info,
&ett_knxnetip_cemi_fastack
};
static ei_register_info ei[] = {
{ &ei_knxnetip_length, { "knxnetip.invalid.length", PI_PROTOCOL, PI_ERROR, "invalid length", EXPFILL }},
};
proto_knxnetip = proto_register_protocol("KNXnet/IP", "knxnetip", "knx");
proto_register_field_array(proto_knxnetip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_knxnetip = expert_register_protocol(proto_knxnetip);
expert_register_field_array(expert_knxnetip, ei, array_length(ei));
}
void proto_reg_handoff_knxnetip(void) {
heur_dissector_add("tcp", dissect_knxnetip_heur, proto_knxnetip);
heur_dissector_add("udp", dissect_knxnetip_heur, proto_knxnetip);
}
