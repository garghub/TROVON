static int
dissect_diameter_3gpp_ms_timezone(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
guint8 oct;
char sign;
oct = tvb_get_guint8(tvb, offset);
sign = (oct & 0x08) ? '-' : '+';
oct = (oct >> 4) + (oct & 0x07) * 10;
proto_tree_add_text(tree, tvb, offset, 1, "Timezone: GMT %c %d hours %d minutes", sign, oct / 4, oct % 4 * 15);
offset++;
oct = tvb_get_guint8(tvb, offset) & 0x3;
proto_tree_add_text(tree, tvb, offset, 1, "%s", val_to_str_const(oct, daylight_saving_time_vals, "Unknown"));
offset++;
return offset;
}
static int
dissect_diameter_3gpp_ipv6addr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_diameter_3gpp_ipv6addr, tvb, offset, 16, ENC_NA);
offset += 16;
return offset;
}
static int
dissect_diameter_3gpp_sgsn_ipv6_address(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
if (tvb_reported_length(tvb) == 4)
return 4;
return dissect_diameter_3gpp_ipv6addr(tvb, pinfo, tree, data);
}
static int
dissect_diameter_3gpp_visited_nw_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
int offset = 0, i;
int length = tvb_length(tvb);
for(i = 0; i < length; i++)
if(!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item(tree, hf_diameter_3gpp_visited_nw_id, tvb, offset, length, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
return length;
}
static int
dissect_diameter_3gpp_feature_list_id(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_)
{
diam_sub_dis_t *diam_sub_dis_inf;
if(pinfo->private_data){
diam_sub_dis_inf = (diam_sub_dis_t*)pinfo->private_data;
diam_sub_dis_inf->feature_list_id = tvb_get_ntohl(tvb,0);
}
return 4;
}
static int
dissect_diameter_3gpp_uar_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_uar_flags_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_uar_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 31, ENC_BIG_ENDIAN);
bit_offset+=31;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_uar_flags_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
static int
dissect_diameter_3gpp_feature_list(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset, application_id = 0, feature_list_id = 0;
diam_sub_dis_t *diam_sub_dis_inf;
item = proto_tree_add_item(tree, hf_diameter_3gpp_feature_list_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_feature_list_ett);
if(pinfo->private_data){
diam_sub_dis_inf = (diam_sub_dis_t*)pinfo->private_data;
application_id = diam_sub_dis_inf->application_id;
feature_list_id = diam_sub_dis_inf->feature_list_id;
}
bit_offset = 0;
if(application_id == 16777216){
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 29, ENC_BIG_ENDIAN);
bit_offset+=29;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list_flags_bit2, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list_flags_bit1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
}else if(application_id == 16777251){
if(feature_list_id == 1){
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit31, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit30, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit29, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit28, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit27, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit26, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit25, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit24, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit23, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit22, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit21, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit20, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit19, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit18, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit17, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit16, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit15, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit14, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit13, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit12, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit11, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit10, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit9, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit8, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit7, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit6, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit5, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit4, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit3, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit2, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list1_s6a_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}else if(feature_list_id == 2){
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 30, ENC_BIG_ENDIAN);
bit_offset+=30;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list2_s6a_flags_bit1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_feature_list2_s6a_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
}
return 4;
}
static int
dissect_diameter_3gpp_path(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0, comma_offset;
int end_offset = tvb_length(tvb) - 1;
item = proto_tree_add_text(tree, tvb, offset, -1,"Paths");
sub_tree = proto_item_add_subtree(item,diameter_3gpp_path_ett);
while (offset < end_offset){
comma_offset = tvb_find_guint8(tvb, offset, -1, ',');
if(comma_offset == -1){
proto_tree_add_item(sub_tree, hf_diameter_3gpp_path, tvb, offset, comma_offset, ENC_ASCII|ENC_NA);
return end_offset;
}
proto_tree_add_item(sub_tree, hf_diameter_3gpp_path, tvb, offset, comma_offset, ENC_ASCII|ENC_NA);
offset = comma_offset+1;
}
return tvb_length(tvb);
}
static int
dissect_diameter_3gpp_contact(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
int offset = 0;
item = proto_tree_add_item(tree, hf_diameter_3gpp_contact, tvb, offset, -1, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
return tvb_length(tvb);
}
static int
dissect_diameter_3gpp_msisdn(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
const char *digit_str;
int length = tvb_length(tvb);
item = proto_tree_add_item(tree, hf_diameter_3gpp_msisdn, tvb, offset, length, ENC_NA);
sub_tree = proto_item_add_subtree(item,diameter_3gpp_msisdn_ett);
dissect_e164_cc(tvb, sub_tree, offset, TRUE);
digit_str = unpack_digits(tvb, 1);
proto_tree_add_string(sub_tree, hf_diameter_address_digits, tvb, 1, -1, digit_str);
return tvb_length(tvb);
}
static int
dissect_diameter_3gpp_user_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
guint8 word[6];
int length = tvb_length(tvb);
if(length < 38)
return length;
tvb_get_nstringz0(tvb, 0, sizeof(word),word);
if (g_ascii_strncasecmp(word, "<?xml", 5) == 0){
call_dissector(xml_handle, tvb, pinfo, tree);
}
return length;
}
static int
dissect_diameter_3gpp_service_ind(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
int offset = 0, i;
int length = tvb_length(tvb);
for(i = 0; i < length; i++)
if(!g_ascii_isprint(tvb_get_guint8(tvb, i)))
return length;
item = proto_tree_add_item(tree, hf_diameter_3gpp_service_ind, tvb, offset, length, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(item);
return length;
}
static int
dissect_diameter_3gpp_tmgi(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
item = proto_tree_add_item(tree, hf_diameter_3gpp_tmgi, tvb, offset, 6, ENC_NA);
sub_tree = proto_item_add_subtree(item,diameter_3gpp_tmgi_ett);
proto_tree_add_item(sub_tree, hf_diameter_mbms_service_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset = offset+3;
offset = dissect_e212_mcc_mnc(tvb, pinfo, sub_tree, offset, TRUE);
return offset;
}
static int
dissect_diameter_3gpp_ipaddr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
int offset = 0;
proto_tree_add_item(tree, hf_diameter_3gpp_ipaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
dissect_diameter_3gpp_mbms_required_qos(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset = 0;
guint length;
proto_tree_add_item(tree, hf_diameter_3gpp_mbms_required_qos_prio, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
length = tvb_length(tvb) - 1;
de_sm_qos(tvb, tree, pinfo, offset,length, NULL, 0);
return offset+length;
}
static int
dissect_diameter_3gpp_udp_port(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
proto_tree_add_item(tree, hf_diameter_3gpp_udp_port, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static int
dissect_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
int offset = 0;
const gchar *time_str;
time_str = tvb_ntp_fmt_ts(tvb, offset);
proto_tree_add_string(tree, hf_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer, tvb, offset, 8, time_str);
offset+=8;
return offset;
}
static int
dissect_diameter_3gpp_ulr_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_ulr_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_ulr_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 24, ENC_BIG_ENDIAN);
bit_offset+=24;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ulr_flags_bit7, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ulr_flags_bit6, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ulr_flags_bit5, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ulr_flags_bit4, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ulr_flags_bit3, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ulr_flags_bit2, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ulr_flags_bit1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ulr_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
static int
dissect_diameter_3gpp_ula_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_ula_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_ula_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 31, ENC_BIG_ENDIAN);
bit_offset+=31;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ula_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
static int
dissect_diameter_3gpp_dsr_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_dsr_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_dsr_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 15, ENC_BIG_ENDIAN);
bit_offset+=15;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit16, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit15, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit14, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit13, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit12, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit11, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit10, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit9, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit8, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit7, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit6, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit5, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit4, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit3, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit2, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsr_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
static int
dissect_diameter_3gpp_dsa_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_dsa_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_dsa_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 31, ENC_BIG_ENDIAN);
bit_offset+=31;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_dsa_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
static int
dissect_diameter_3gpp_ida_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_ida_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_ida_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 31, ENC_BIG_ENDIAN);
bit_offset+=31;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_ida_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
static int
dissect_diameter_3gpp_pua_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_pua_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_pua_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 30, ENC_BIG_ENDIAN);
bit_offset+=30;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_pua_flags_bit1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_pua_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
static int
dissect_diameter_3gpp_nor_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_nor_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_nor_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 25, ENC_BIG_ENDIAN);
bit_offset+=25;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_nor_flags_bit6, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_nor_flags_bit5, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_nor_flags_bit4, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_nor_flags_bit3, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_nor_flags_bit2, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_nor_flags_bit1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_nor_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
static int
dissect_diameter_3gpp_idr_flags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_) {
proto_item* item;
proto_tree *sub_tree;
int offset = 0;
guint32 bit_offset;
item = proto_tree_add_item(tree, hf_diameter_3gpp_idr_flags, tvb, offset, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(item, diameter_3gpp_idr_flags_ett);
bit_offset = 0;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_spare_bits, tvb, bit_offset, 25, ENC_BIG_ENDIAN);
bit_offset+=25;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_idr_flags_bit6, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_idr_flags_bit5, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_idr_flags_bit4, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_idr_flags_bit3, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_idr_flags_bit2, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_idr_flags_bit1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(sub_tree, hf_diameter_3gpp_idr_flags_bit0, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
offset = bit_offset>>3;
return offset;
}
void
proto_reg_handoff_diameter_3gpp(void)
{
dissector_add_uint("diameter.3gpp", 15, new_create_dissector_handle(dissect_diameter_3gpp_sgsn_ipv6_address, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 23, new_create_dissector_handle(dissect_diameter_3gpp_ms_timezone, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 600, new_create_dissector_handle(dissect_diameter_3gpp_visited_nw_id, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 606, new_create_dissector_handle(dissect_diameter_3gpp_user_data, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 629, new_create_dissector_handle(dissect_diameter_3gpp_feature_list_id, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 630, new_create_dissector_handle(dissect_diameter_3gpp_feature_list, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 637, new_create_dissector_handle(dissect_diameter_3gpp_uar_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 640, new_create_dissector_handle(dissect_diameter_3gpp_path, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 641, new_create_dissector_handle(dissect_diameter_3gpp_contact, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 701, new_create_dissector_handle(dissect_diameter_3gpp_msisdn, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 702, new_create_dissector_handle(dissect_diameter_3gpp_user_data, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 704, new_create_dissector_handle(dissect_diameter_3gpp_service_ind, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 900, new_create_dissector_handle(dissect_diameter_3gpp_tmgi, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 913, new_create_dissector_handle(dissect_diameter_3gpp_mbms_required_qos, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 917, new_create_dissector_handle(dissect_diameter_3gpp_ipv6addr, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 918, new_create_dissector_handle(dissect_diameter_3gpp_ipaddr, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 926, new_create_dissector_handle(dissect_diameter_3gpp_udp_port, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 927, new_create_dissector_handle(dissect_diameter_3gpp_udp_port, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 929, new_create_dissector_handle(dissect_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 930, new_create_dissector_handle(dissect_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1405, new_create_dissector_handle(dissect_diameter_3gpp_ulr_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1406, new_create_dissector_handle(dissect_diameter_3gpp_ula_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1421, new_create_dissector_handle(dissect_diameter_3gpp_dsr_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1422, new_create_dissector_handle(dissect_diameter_3gpp_dsa_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1441, new_create_dissector_handle(dissect_diameter_3gpp_ida_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1442, new_create_dissector_handle(dissect_diameter_3gpp_pua_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1443, new_create_dissector_handle(dissect_diameter_3gpp_nor_flags, proto_diameter_3gpp));
dissector_add_uint("diameter.3gpp", 1490, new_create_dissector_handle(dissect_diameter_3gpp_idr_flags, proto_diameter_3gpp));
xml_handle = find_dissector("xml");
}
void
proto_register_diameter_3gpp(void)
{
static hf_register_info hf[] = {
{ &hf_diameter_3gpp_path,
{ "Path", "diameter.3gpp.path",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_contact,
{ "Contact", "diameter.3gpp.contact",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_visited_nw_id,
{ "Visited-Network-Identifier", "diameter.3gpp.visited_nw_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_msisdn,
{ "MSISDN", "diameter.3gpp.msisdn",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_diameter_3gpp_user_data,
{ "User data", "diameter.3gpp.user_data",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_diameter_3gpp_ipaddr,
{ "IPv4 Address", "diameter.3gpp.ipaddr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_required_qos_prio,
{ "Allocation/Retention Priority", "diameter.3gpp.mbms_required_qos_prio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_tmgi,
{ "TMGI", "diameter.3gpp.tmgi",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_service_ind,
{ "Service-Indication", "diameter.3gpp.service_ind",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_mbms_service_id,
{ "MBMS Service ID", "diameter.3gpp.mbms_service_id",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_address_digits,
{ "Address digits", "diameter.3gpp.address_digits",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_spare_bits,
{ "Spare bit(s)", "diameter.3gpp.spare_bits",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_uar_flags_flags,
{ "Flags", "diameter.3gpp.uar_flags_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_uar_flags_flags_bit0,
{ "Emergency registration", "diameter.3gpp.uar_flags_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_flags,
{ "Feature-List Flags", "diameter.3gpp.feature_list_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_flags_bit0,
{ "Shared IFC Sets", "diameter.3gpp.feature_list_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_flags_bit1,
{ "Alias Indication", "diameter.3gpp.feature_list_flags_bit1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list_flags_bit2,
{ "IMS Restoration Indication", "diameter.3gpp.feature_list_flags_bit2",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit0,
{ "Operator Determined Barring of all Packet Oriented Services", "diameter.3gpp.feature_list1_s6a_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit1,
{ "Operator Determined Barring of Packet Oriented Services from access points that are within the HPLMN whilst the subscriber is roaming in a VPLMN", "diameter.3gpp.feature_list1_s6a_flags_bit1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit2,
{ "Operator Determined Barring of Packet Oriented Services from access points that are within the roamed to VPLMN", "diameter.3gpp.feature_list1_s6a_flags_bit2",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit3,
{ "Operator Determined Barring of all outgoing calls", "diameter.3gpp.feature_list1_s6a_flags_bit3",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit4,
{ "Operator Determined Barring of all outgoing international calls", "diameter.3gpp.feature_list1_s6a_flags_bit4",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit5,
{ "Operator Determined Barring of all outgoing international calls except those directed to the home PLMN country", "diameter.3gpp.feature_list1_s6a_flags_bit5",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit6,
{ "Operator Determined Barring of all outgoing inter-zonal calls", "diameter.3gpp.feature_list1_s6a_flags_bit6",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit7,
{ "Operator Determined Barring of all outgoing inter-zonal calls except those directed to the home PLMN country", "diameter.3gpp.feature_list1_s6a_flags_bit7",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit8,
{ "Operator Determined Barring of all outgoing international calls except those directed to the home PLMN country and Barring of all outgoing inter-zonal calls", "diameter.3gpp.feature_list1_s6a_flags_bit8",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit9,
{ "Regional Subscription", "diameter.3gpp.feature_list1_s6a_flags_bit9",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit10,
{ "Trace Function", "diameter.3gpp.feature_list1_s6a_flags_bit10",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit11,
{ "All LCS Privacy Exception Classes", "diameter.3gpp.feature_list1_s6a_flags_bit11",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit12,
{ "Allow location by any LCS client", "diameter.3gpp.feature_list1_s6a_flags_bit12",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit13,
{ "Allow location by any value added LCS client to which a call/session is established from the target UE", "diameter.3gpp.feature_list1_s6a_flags_bit13",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit14,
{ "Allow location by designated external value added LCS clients", "diameter.3gpp.feature_list1_s6a_flags_bit14",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit15,
{ "Allow location by designated PLMN operator LCS clients", "diameter.3gpp.feature_list1_s6a_flags_bit15",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit16,
{ "Allow location by LCS clients of a designated LCS service type", "diameter.3gpp.feature_list1_s6a_flags_bit16",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit17,
{ "All Mobile Originating Location Request Classes", "diameter.3gpp.feature_list1_s6a_flags_bit17",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit18,
{ "Allow an MS to request its own location", "diameter.3gpp.feature_list1_s6a_flags_bit18",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit19,
{ "Allow an MS to perform self location without interaction with the PLMN", "diameter.3gpp.feature_list1_s6a_flags_bit19",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit20,
{ "Allow an MS to request transfer of its location to another LCS client", "diameter.3gpp.feature_list1_s6a_flags_bit20",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit21,
{ "Short Message MO-PP", "diameter.3gpp.feature_list1_s6a_flags_bit21",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit22,
{ "Barring of Outgoing Calls", "diameter.3gpp.feature_list1_s6a_flags_bit22",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit23,
{ "Barring of all outgoing calls", "diameter.3gpp.feature_list1_s6a_flags_bit23",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit24,
{ "Barring of outgoing international calls", "diameter.3gpp.feature_list1_s6a_flags_bit24",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit25,
{ "Barring of outgoing international calls except those directed to the home PLMN Country", "diameter.3gpp.feature_list1_s6a_flags_bit25",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit26,
{ "UE Reachability Notifcation", "diameter.3gpp.feature_list1_s6a_flags_bit26",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit27,
{ "Terminating Access Domain Selection Data Retrieval", "diameter.3gpp.feature_list1_s6a_flags_bit27",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit28,
{ "State/Location Information Retrieval", "diameter.3gpp.feature_list1_s6a_flags_bit28",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit29,
{ "Partial Purge from a Combined MME/SGSN", "diameter.3gpp.feature_list1_s6a_flags_bit29",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit30,
{ "UE Time Zone Retrieval", "diameter.3gpp.feature_list1_s6a_flags1_bit30",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list1_s6a_flags_bit31,
{ "Additional MSISDN", "diameter.3gpp.feature_list1_s6a_flags_bit31",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit0,
{ "SMS in MME", "diameter.3gpp.feature_list2_s6a_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_feature_list2_s6a_flags_bit1,
{ "SMS in SGSN", "diameter.3gpp.feature_list2_s6a_flags_bit1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags,
{ "ULR Flags", "diameter.3gpp.ulr_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit0,
{ "Single-Registration-Indication", "diameter.3gpp.ulr_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit1,
{ "S6a/S6d-Indicator", "diameter.3gpp.ulr_flags_bit1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit2,
{ "Skip-Subscriber-Data", "diameter.3gpp.ulr_flags_bit2",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit3,
{ "GPRS-Subscription-Data-Indicator", "diameter.3gpp.ulr_flags_bit3",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit4,
{ "Node-Type-Indicator", "diameter.3gpp.ulr_flags_bit4",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit5,
{ "Initial-Attach-Indicator", "diameter.3gpp.ulr_flags_bit5",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit6,
{ "PS-LCS-Not-Supported-By-UE", "diameter.3gpp.ulr_flags_bit6",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ulr_flags_bit7,
{ "SMS-Only-Indication", "diameter.3gpp.ulr_flags_bit7",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ula_flags,
{ "ULA Flags", "diameter.3gpp.ula_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ula_flags_bit0,
{ "Separation Indication", "diameter.3gpp.ula_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags,
{ "DSR Flags", "diameter.3gpp.dsr_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit0,
{ "Regional Subscription Withdrawal", "diameter.3gpp.dsr_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit1,
{ "Complete APN Configuration Profile Withdrawal", "diameter.3gpp.dsr_flags_bit1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit2,
{ "Subscribed Charging Characteristics Withdrawal", "diameter.3gpp.dsr_flags_bit2",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit3,
{ "PDN subscription contexts Withdrawal", "diameter.3gpp.dsr_flags_bit3",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit4,
{ "STN-SR", "diameter.3gpp.dsr_flags_bit4",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit5,
{ "Complete PDP context list Withdrawal", "diameter.3gpp.dsr_flags_bit5",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit6,
{ "PDP contexts Withdrawal", "diameter.3gpp.dsr_flags_bit6",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit7,
{ "Roaming Restricted due to unsupported feature", "diameter.3gpp.dsr_flags_bit7",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit8,
{ "Trace Data Withdrawal", "diameter.3gpp.dsr_flags_bit8",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit9,
{ "CSG Deleted", "diameter.3gpp.dsr_flags_bit9",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit10,
{ "APN-OI-Replacement", "diameter.3gpp.dsr_flags_bit10",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit11,
{ "GMLC List Withdrawal", "diameter.3gpp.dsr_flags_bit11",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit12,
{ "LCS Withdrawal", "diameter.3gpp.dsr_flags_bit12",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit13,
{ "SMS Withdrawal", "diameter.3gpp.dsr_flags_bit13",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit14,
{ "Subscribed periodic RAU-TAU Timer Withdrawal", "diameter.3gpp.dsr_flags_bit14",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit15,
{ "Subscribed VSRVCC Withdrawal", "diameter.3gpp.dsr_flags_bit15",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsr_flags_bit16,
{ "A-MSISDN Withdrawal", "diameter.3gpp.dsr_flags_bit16",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsa_flags,
{ "DSA Flags", "diameter.3gpp.dsa_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_dsa_flags_bit0,
{ "Network Node area restricted", "diameter.3gpp.dsa_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ida_flags,
{ "IDA Flags", "diameter.3gpp.ida_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ida_flags_bit0,
{ "Network Node area restricted", "diameter.3gpp.ida_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_pua_flags,
{ "PUA Flags", "diameter.3gpp.pua_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_pua_flags_bit0,
{ "Freeze M-TMSI", "diameter.3gpp.pua_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_pua_flags_bit1,
{ "Freeze P-TMSI", "diameter.3gpp.pua_flags_bit1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags,
{ "NOR Flags", "diameter.3gpp.nor_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit0,
{ "Single-Registration-Indication", "diameter.3gpp.nor_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit1,
{ "SGSN area restricted", "diameter.3gpp.nor_flags_bit1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit2,
{ "Ready for SM", "diameter.3gpp.nor_flags_bit2",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit3,
{ "UE Reachable", "diameter.3gpp.nor_flags_bit3",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit4,
{ "Delete all APN and PDN GW identity pairs", "diameter.3gpp.nor_flags_bit4",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit5,
{ "UE Reachable from SGSN", "diameter.3gpp.nor_flags_bit5",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_nor_flags_bit6,
{ "Ready for SM from MME", "diameter.3gpp.nor_flags_bit6",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags,
{ "IDR Flags", "diameter.3gpp.idr_flags",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit0,
{ "UE Reachability Request", "diameter.3gpp.idr_flags_bit0",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit1,
{ "T-ADS Data Request", "diameter.3gpp.idr_flags_bit1",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit2,
{ "EPS User State Request", "diameter.3gpp.idr_flags_bit2",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit3,
{ "EPS Location Information Request", "diameter.3gpp.idr_flags_bit3",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit4,
{ "Current Location Request", "diameter.3gpp.idr_flags_bit4",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit5,
{ "Local Time Zone Request", "diameter.3gpp.idr_flags_bit5",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_idr_flags_bit6,
{ "Remove SMS Registration", "diameter.3gpp.idr_flags_bit6",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_set_notset), 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_ipv6addr,
{ "IPv6 Address", "diameter.3gpp.ipv6addr",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_mbms_abs_time_ofmbms_data_tfer,
{ "Absolute Time of MBMS Data Transfer", "diameter.3gpp.mbms_abs_time_ofmbms_data_tfer",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_diameter_3gpp_udp_port ,
{ "UDP Port", "diameter.3gpp.udp_port",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&diameter_3gpp_path_ett,
&diameter_3gpp_msisdn_ett,
&diameter_3gpp_uar_flags_ett,
&diameter_3gpp_feature_list_ett,
&diameter_3gpp_tmgi_ett,
&diameter_3gpp_ulr_flags_ett,
&diameter_3gpp_ula_flags_ett,
&diameter_3gpp_dsr_flags_ett,
&diameter_3gpp_dsa_flags_ett,
&diameter_3gpp_ida_flags_ett,
&diameter_3gpp_pua_flags_ett,
&diameter_3gpp_nor_flags_ett,
&diameter_3gpp_idr_flags_ett,
};
proto_diameter_3gpp = proto_register_protocol("Diameter 3GPP","Diameter3GPP", "diameter.3gpp");
proto_register_field_array(proto_diameter_3gpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
