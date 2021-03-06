static int
dissect_contained_icmpv6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean save_in_error_pkt;
gint offset;
save_in_error_pkt = pinfo->flags.in_error_pkt;
pinfo->flags.in_error_pkt = TRUE;
if ((tvb_get_guint8(tvb, 0) & 0xf0) == 0x60) {
offset = call_dissector(ipv6_handle, tvb, pinfo, tree);
} else {
offset = call_data_dissector(tvb, pinfo, tree);
}
pinfo->flags.in_error_pkt = save_in_error_pkt;
return offset;
}
static conversation_t *_find_or_create_conversation(packet_info *pinfo)
{
conversation_t *conv = NULL;
conv = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, 0, 0, 0);
if (conv == NULL) {
conv = conversation_new(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, 0, 0, 0);
}
return conv;
}
static icmp_transaction_t *transaction_start(packet_info *pinfo, proto_tree *tree, guint32 *key)
{
conversation_t *conversation;
icmpv6_conv_info_t *icmpv6_info;
icmp_transaction_t *icmpv6_trans;
wmem_tree_key_t icmpv6_key[3];
proto_item *it;
conversation = _find_or_create_conversation(pinfo);
icmpv6_info = (icmpv6_conv_info_t *)conversation_get_proto_data(conversation, proto_icmpv6);
if (icmpv6_info == NULL) {
icmpv6_info = wmem_new(wmem_file_scope(), icmpv6_conv_info_t);
icmpv6_info->unmatched_pdus = wmem_tree_new(wmem_file_scope());
icmpv6_info->matched_pdus = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_icmpv6, icmpv6_info);
}
if (!PINFO_FD_VISITED(pinfo)) {
icmpv6_key[0].length = 2;
icmpv6_key[0].key = key;
icmpv6_key[1].length = 0;
icmpv6_key[1].key = NULL;
icmpv6_trans = wmem_new(wmem_file_scope(), icmp_transaction_t);
icmpv6_trans->rqst_frame = pinfo->num;
icmpv6_trans->resp_frame = 0;
icmpv6_trans->rqst_time = pinfo->abs_ts;
nstime_set_zero(&icmpv6_trans->resp_time);
wmem_tree_insert32_array(icmpv6_info->unmatched_pdus, icmpv6_key, (void *)icmpv6_trans);
} else {
guint32 frame_num = pinfo->num;
icmpv6_key[0].length = 2;
icmpv6_key[0].key = key;
icmpv6_key[1].length = 1;
icmpv6_key[1].key = &frame_num;
icmpv6_key[2].length = 0;
icmpv6_key[2].key = NULL;
icmpv6_trans = (icmp_transaction_t *)wmem_tree_lookup32_array(icmpv6_info->matched_pdus, icmpv6_key);
}
if (icmpv6_trans == NULL) {
if (pinfo->dst.type == AT_IPv6 &&
in6_is_addr_multicast((const struct e_in6_addr *)pinfo->dst.data)) {
col_append_str(pinfo->cinfo, COL_INFO, " (multicast)");
} else if (PINFO_FD_VISITED(pinfo)) {
it = proto_tree_add_item(tree, hf_icmpv6_no_resp, NULL, 0, 0,
ENC_NA);
PROTO_ITEM_SET_GENERATED(it);
col_append_fstr(pinfo->cinfo, COL_INFO, " (no response found!)");
expert_add_info_format(pinfo, it, &ei_icmpv6_resp_not_found,
"No response seen to ICMPv6 request in frame %u",
pinfo->num);
}
return NULL;
}
if (icmpv6_trans->resp_frame) {
if (tree) {
it = proto_tree_add_uint(tree, hf_icmpv6_resp_in, NULL, 0, 0,
icmpv6_trans->resp_frame);
PROTO_ITEM_SET_GENERATED(it);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (reply in %d)", icmpv6_trans->resp_frame);
}
return icmpv6_trans;
}
static icmp_transaction_t *transaction_end(packet_info *pinfo, proto_tree *tree, guint32 *key)
{
conversation_t *conversation;
icmpv6_conv_info_t *icmpv6_info;
icmp_transaction_t *icmpv6_trans;
wmem_tree_key_t icmpv6_key[3];
proto_item *it;
nstime_t ns;
double resp_time;
conversation = find_conversation(pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, 0, 0, 0);
if (conversation == NULL)
return NULL;
icmpv6_info = (icmpv6_conv_info_t *)conversation_get_proto_data(conversation, proto_icmpv6);
if (icmpv6_info == NULL)
return NULL;
if (!PINFO_FD_VISITED(pinfo)) {
guint32 frame_num;
icmpv6_key[0].length = 2;
icmpv6_key[0].key = key;
icmpv6_key[1].length = 0;
icmpv6_key[1].key = NULL;
icmpv6_trans = (icmp_transaction_t *)wmem_tree_lookup32_array(icmpv6_info->unmatched_pdus, icmpv6_key);
if (icmpv6_trans == NULL)
return NULL;
if (icmpv6_trans->resp_frame != 0)
return NULL;
icmpv6_trans->resp_frame = pinfo->num;
icmpv6_key[0].length = 2;
icmpv6_key[0].key = key;
icmpv6_key[1].length = 1;
icmpv6_key[1].key = &frame_num;
icmpv6_key[2].length = 0;
icmpv6_key[2].key = NULL;
frame_num = icmpv6_trans->rqst_frame;
wmem_tree_insert32_array(icmpv6_info->matched_pdus, icmpv6_key, (void *)icmpv6_trans);
frame_num = icmpv6_trans->resp_frame;
wmem_tree_insert32_array(icmpv6_info->matched_pdus, icmpv6_key, (void *)icmpv6_trans);
} else {
guint32 frame_num = pinfo->num;
icmpv6_key[0].length = 2;
icmpv6_key[0].key = key;
icmpv6_key[1].length = 1;
icmpv6_key[1].key = &frame_num;
icmpv6_key[2].length = 0;
icmpv6_key[2].key = NULL;
icmpv6_trans = (icmp_transaction_t *)wmem_tree_lookup32_array(icmpv6_info->matched_pdus, icmpv6_key);
if (icmpv6_trans == NULL)
return NULL;
}
if (tree) {
it = proto_tree_add_uint(tree, hf_icmpv6_resp_to, NULL, 0, 0,
icmpv6_trans->rqst_frame);
PROTO_ITEM_SET_GENERATED(it);
}
nstime_delta(&ns, &pinfo->abs_ts, &icmpv6_trans->rqst_time);
icmpv6_trans->resp_time = ns;
if (tree) {
resp_time = nstime_to_msec(&ns);
it = proto_tree_add_double_format_value(tree, hf_icmpv6_resptime, NULL,
0, 0, resp_time, "%.3f ms", resp_time);
PROTO_ITEM_SET_GENERATED(it);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (request in %d)",
icmpv6_trans->rqst_frame);
return icmpv6_trans;
}
static int
dissect_icmpv6_nd_opt(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree)
{
proto_tree *icmp6opt_tree;
proto_item *ti, *ti_opt, *ti_opt_len;
guint8 opt_type;
int opt_len;
int opt_offset;
tvbuff_t *opt_tvb;
guint used_bytes;
while ((int)tvb_reported_length(tvb) > offset) {
opt_len = tvb_get_guint8(tvb, offset + 1) * 8;
ti = proto_tree_add_item(tree, hf_icmpv6_opt, tvb, offset, opt_len, ENC_NA);
icmp6opt_tree = proto_item_add_subtree(ti, ett_icmpv6_opt);
opt_offset = offset;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_type, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_type = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_item_append_text(ti, " (%s", val_to_str(opt_type, option_vals, "Unknown %d"));
ti_opt_len = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_length, tvb,opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_item_append_text(ti_opt_len, " (%i bytes)", opt_len);
if(opt_len == 0){
expert_add_info_format(pinfo, ti_opt_len, &ei_icmpv6_invalid_option_length, "Invalid option length (Zero)");
return opt_offset;
}
switch (opt_type) {
case ND_OPT_SOURCE_LINKADDR:
{
const gchar *link_str;
if(opt_len == 8){
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_linkaddr_mac, tvb, opt_offset, 6, ENC_NA);
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_src_linkaddr_mac, tvb, opt_offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_opt);
link_str = tvb_ether_to_str(tvb, opt_offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " from %s", link_str);
proto_item_append_text(ti, " : %s", link_str);
}else if(opt_len == 16 && tvb_get_ntohl(tvb, opt_offset + 8) == 0 && tvb_get_ntohs(tvb, opt_offset + 12) == 0){
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_linkaddr_eui64, tvb, opt_offset, 8, ENC_BIG_ENDIAN);
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_src_linkaddr_eui64, tvb, opt_offset, 8, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(ti_opt);
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_linkaddr, tvb, opt_offset, 8, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_opt);
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_src_linkaddr, tvb, opt_offset, 8, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_opt);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_padding, tvb, opt_offset + 8, 6, ENC_NA);
link_str = tvb_eui64_to_str(tvb, opt_offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " from %s", link_str);
proto_item_append_text(ti, " : %s", link_str);
}else{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_linkaddr, tvb, opt_offset, opt_len-2, ENC_NA);
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_src_linkaddr, tvb, opt_offset, opt_len-2, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_opt);
}
opt_offset += opt_len;
break;
}
case ND_OPT_TARGET_LINKADDR:
{
const gchar *link_str;
if(opt_len == 8){
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_linkaddr_mac, tvb, opt_offset, 6, ENC_NA);
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_target_linkaddr_mac, tvb, opt_offset, 6, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_opt);
link_str = tvb_ether_to_str(tvb, opt_offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " is at %s", link_str);
proto_item_append_text(ti, " : %s", link_str);
}else if(opt_len == 16 && tvb_get_ntohl(tvb, opt_offset + 8) == 0 && tvb_get_ntohs(tvb, opt_offset + 12) == 0){
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_linkaddr_eui64, tvb, opt_offset, 8, ENC_BIG_ENDIAN);
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_target_linkaddr_eui64, tvb, opt_offset, 8, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(ti_opt);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_padding, tvb, opt_offset + 8, 6, ENC_NA);
link_str = tvb_eui64_to_str(tvb, opt_offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " from %s", link_str);
proto_item_append_text(ti, " : %s", link_str);
}else{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_linkaddr, tvb, opt_offset, opt_len-2, ENC_NA);
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_target_linkaddr, tvb, opt_offset, opt_len-2, ENC_NA);
PROTO_ITEM_SET_HIDDEN(ti_opt);
}
opt_offset += opt_len;
break;
}
case ND_OPT_PREFIX_INFORMATION:
{
static const int * prefix_flag[] = {
&hf_icmpv6_opt_prefix_flag_l,
&hf_icmpv6_opt_prefix_flag_a,
&hf_icmpv6_opt_prefix_flag_r,
&hf_icmpv6_opt_prefix_flag_reserved,
NULL
};
guint8 prefix_len;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_prefix_len, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
prefix_len = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_opt_prefix_flag, ett_icmpv6_flag_prefix, prefix_flag, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_prefix_valid_lifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_prefix_preferred_lifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 4, ENC_NA);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_prefix, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " : %s/%d", tvb_ip6_to_str(tvb, opt_offset), prefix_len);
opt_offset += 16;
break;
}
case ND_OPT_REDIRECTED_HEADER:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 6, ENC_NA);
opt_offset += 6;
if (opt_len > 8) {
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_redirected_packet, tvb, opt_offset, opt_len - 8, ENC_NA);
opt_tvb = tvb_new_subset_length(tvb, opt_offset, opt_len - 8);
opt_offset += dissect_contained_icmpv6(opt_tvb, pinfo, icmp6opt_tree);
}
break;
case ND_OPT_MTU:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 2, ENC_NA);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_mtu, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " : %d", tvb_get_ntohl(tvb, opt_offset));
opt_offset += 4;
break;
case ND_OPT_NBMA:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_nbma_shortcut_limit, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " : %d", tvb_get_guint8(tvb, opt_offset));
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 1, ENC_NA);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 4, ENC_NA);
opt_offset += 4;
break;
case ND_OPT_ADVINTERVAL:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 2, ENC_NA);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_advertisement_interval, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " : %d", tvb_get_ntohl(tvb, opt_offset));
opt_offset += 4;
break;
case ND_OPT_HOMEAGENT_INFO:
{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 2, ENC_NA);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_home_agent_preference, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_home_agent_lifetime, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
break;
}
case ND_OPT_SOURCE_ADDRLIST:
case ND_OPT_TARGET_ADDRLIST:
{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 6, ENC_NA);
opt_offset += 6;
while(opt_offset < (offset + opt_len) ) {
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_ipv6_address, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s", tvb_ip6_to_str(tvb, opt_offset));
opt_offset += 16;
}
break;
}
case ND_OPT_CGA:
{
proto_tree *cga_tree;
proto_item *cga_item;
guint16 ext_data_len;
guint8 padd_length;
int par_len;
asn1_ctx_t asn1_ctx;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_cga_pad_len, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
padd_length = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 1, ENC_NA);
opt_offset += 1;
par_len = opt_len -4 -padd_length;
cga_item = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_cga, tvb, opt_offset, par_len, ENC_NA);
par_len += opt_offset;
cga_tree = proto_item_add_subtree(cga_item, ett_icmpv6_cga_param_name);
proto_tree_add_item(cga_tree, hf_icmpv6_opt_cga_modifier, tvb, opt_offset, 16, ENC_NA);
opt_offset += 16;
proto_tree_add_item(cga_tree, hf_icmpv6_opt_cga_subnet_prefix, tvb, opt_offset, 8, ENC_NA);
opt_offset += 8;
proto_tree_add_item(cga_tree ,hf_icmpv6_opt_cga_count, tvb, opt_offset, 1, ENC_NA);
opt_offset += 1;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
opt_offset = dissect_x509af_SubjectPublicKeyInfo(FALSE, tvb, opt_offset, &asn1_ctx, cga_tree, -1);
while (opt_offset < par_len) {
proto_tree_add_item(cga_tree, hf_icmpv6_opt_cga_ext_type, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
ext_data_len = tvb_get_ntohs(tvb, opt_offset);
proto_tree_add_item(cga_tree, hf_icmpv6_opt_cga_ext_length, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
proto_tree_add_item(cga_tree, hf_icmpv6_opt_cga_ext_data, tvb, opt_offset, ext_data_len, ENC_NA);
opt_offset += ext_data_len;
}
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += padd_length;
break;
}
case ND_OPT_RSA:
{
int par_len;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 2, ENC_NA);
opt_offset = opt_offset + 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_rsa_key_hash, tvb, opt_offset, 16, ENC_NA);
opt_offset = opt_offset + 16;
par_len = opt_len - 20;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_digital_signature_padding , tvb, opt_offset, par_len, ENC_NA);
opt_offset += par_len;
break;
}
case ND_OPT_TIMESTAMP:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 6, ENC_NA);
opt_offset += 6;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_timestamp, tvb, opt_offset, 8, ENC_TIME_RFC_3971|ENC_BIG_ENDIAN);
opt_offset += 8;
break;
case ND_OPT_NONCE:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_nonce, tvb, opt_offset, opt_len - 2, ENC_NA);
opt_offset += opt_len -2;
break;
case ND_OPT_TRUST_ANCHOR:
{
proto_tree *name_tree;
proto_item *name_item;
guint8 name_type;
guint8 padd_length;
int par_len;
asn1_ctx_t asn1_ctx;
name_type = tvb_get_guint8(tvb, opt_offset);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_name_type, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
padd_length = tvb_get_guint8(tvb, opt_offset);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_cga_pad_len, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
par_len = opt_len - 4 - padd_length;
switch (name_type){
case 1:
name_item = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_name_x501, tvb, opt_offset, par_len, ENC_NA);
name_tree = proto_item_add_subtree(name_item, ett_icmpv6_opt_name);
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_x509if_Name(FALSE, tvb, opt_offset, &asn1_ctx, name_tree, hf_icmpv6_x509if_Name);
break;
case 2:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_name_fqdn, tvb, opt_offset, par_len, ENC_ASCII|ENC_NA);
break;
default:
break;
}
opt_offset += par_len;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += padd_length;
break;
}
case ND_OPT_CERTIFICATE:
{
guint8 cert_type;
guint8 padd_length;
asn1_ctx_t asn1_ctx;
cert_type = tvb_get_guint8(tvb, opt_offset);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_cert_type, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 1, ENC_NA);
opt_offset += 1;
if(cert_type == 1){
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
opt_offset = dissect_x509af_Certificate(FALSE, tvb, opt_offset, &asn1_ctx, icmp6opt_tree, hf_icmpv6_x509af_Certificate);
padd_length = opt_len - (opt_offset - offset);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += padd_length;
}else{
padd_length = opt_len - 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_certificate_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += padd_length;
}
break;
}
case ND_OPT_IP_ADDRESS_PREFIX:
{
guint8 prefix_len;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_ipa_option_code, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_ipa_prefix_len, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
prefix_len = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 4, ENC_NA);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_ipa_ipv6_address, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s/%d", tvb_ip6_to_str(tvb, opt_offset), prefix_len);
opt_offset += 16;
break;
}
case ND_OPT_NEW_ROUTER_PREFIX_INFO:
{
guint8 prefix_len;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_nrpi_option_code, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_nrpi_prefix_len, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
prefix_len = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 4, ENC_NA);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_nrpi_prefix, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s/%d", tvb_ip6_to_str(tvb, opt_offset), prefix_len);
opt_offset += 16;
break;
}
case ND_OPT_LINK_LAYER_ADDRESS:
{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_lla_option_code, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_lla_bytes, tvb, opt_offset, opt_len-3, ENC_NA);
opt_offset += opt_len - 3;
break;
}
case ND_OPT_NEIGHBOR_ADV_ACK:
{
guint8 status;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_naack_option_code, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_naack_status, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
status = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
if(status == 2){
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_naack_supplied_ncoa, tvb, opt_offset, 16, ENC_NA);
opt_offset += 16;
}else{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, opt_len - 4, ENC_NA);
opt_offset += opt_len - 4;
}
break;
}
case ND_OPT_MAP:
{
static const int * map_flags[] = {
&hf_icmpv6_opt_map_flag_r,
&hf_icmpv6_opt_map_flag_reserved,
NULL
};
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_map_dist, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_map_pref, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_opt_map_flag, ett_icmpv6_flag_map, map_flags, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_map_valid_lifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_map_global_address, tvb, opt_offset, 16, ENC_NA);
opt_offset += 16;
break;
}
case ND_OPT_ROUTE_INFO:
{
guint8 prefix_len;
guint8 route_preference;
struct e_in6_addr prefix;
address prefix_addr;
static const int * route_flags[] = {
&hf_icmpv6_opt_route_info_flag_route_preference,
&hf_icmpv6_opt_route_info_flag_reserved,
NULL
};
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_prefix_len, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
prefix_len = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_opt_route_info_flag, ett_icmpv6_flag_route_info, route_flags, ENC_BIG_ENDIAN);
route_preference = tvb_get_guint8(tvb, opt_offset);
route_preference = (route_preference & ND_RA_FLAG_RTPREF_MASK) >> 3;
proto_item_append_text(ti, " : %s", val_to_str(route_preference, nd_flag_router_pref, "Unknown %d") );
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_route_lifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
switch(opt_len){
case 8:
proto_item_append_text(ti, " ::/%d", prefix_len);
break;
case 16:
memset(&prefix, 0, sizeof(prefix));
tvb_memcpy(tvb, (guint8 *)&prefix.bytes, opt_offset, 8);
proto_tree_add_ipv6(icmp6opt_tree, hf_icmpv6_opt_prefix, tvb, opt_offset, 8, &prefix);
set_address(&prefix_addr, AT_IPv6, 16, prefix.bytes);
proto_item_append_text(ti, " %s/%d", address_to_str(wmem_packet_scope(), &prefix_addr), prefix_len);
opt_offset += 8;
break;
case 24:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_prefix, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s/%d", tvb_ip6_to_str(tvb, opt_offset), prefix_len);
opt_offset += 16;
break;
default:
expert_add_info(pinfo, ti_opt_len, &ei_icmpv6_invalid_option_length);
break;
}
break;
}
case ND_OPT_RECURSIVE_DNS_SERVER:
{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 2, ENC_NA);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_rdnss_lifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
while(opt_offset < (offset + opt_len) ) {
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_rdnss, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s", tvb_ip6_to_str(tvb, opt_offset));
opt_offset += 16;
}
break;
}
case ND_OPT_FLAGS_EXTENSION:
{
static const int * extension_flags[] = {
&hf_icmpv6_opt_efo_m,
&hf_icmpv6_opt_efo_o,
&hf_icmpv6_opt_efo_h,
&hf_icmpv6_opt_efo_prf,
&hf_icmpv6_opt_efo_p,
&hf_icmpv6_opt_efo_rsv,
NULL
};
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_opt_efo, ett_icmpv6_flag_efo, extension_flags, ENC_BIG_ENDIAN);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 4, ENC_NA);
opt_offset += 4;
break;
}
case ND_OPT_HANDOVER_KEY_REQUEST:
{
int par_len;
guint padd_length;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_pad_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
padd_length = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_at, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_reserved, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
par_len = opt_len-4-padd_length;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_encryption_public_key, tvb, opt_offset, par_len, ENC_NA);
opt_offset += par_len;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += 1;
break;
}
case ND_OPT_HANDOVER_KEY_REPLY:
{
int par_len;
guint padd_length;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_pad_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
padd_length = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_at, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_reserved, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_lifetime, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
par_len = opt_len-6-padd_length;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_encrypted_handover_key, tvb, opt_offset, par_len, ENC_NA);
opt_offset += par_len;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hkr_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += 1;
break;
}
case ND_OPT_HANDOVER_ASSIST_INFO:
{
guint8 hai_len;
int padd_length;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hai_option_code, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hai_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
hai_len = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_hai_value, tvb, opt_offset, hai_len, ENC_NA);
opt_offset += hai_len;
padd_length = opt_len - opt_offset;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += padd_length;
break;
}
case ND_OPT_MOBILE_NODE_ID:
{
guint8 mn_len;
int padd_length;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_mn_option_code, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_mn_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
mn_len = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_mn_value, tvb, opt_offset, mn_len, ENC_NA);
opt_offset += mn_len;
padd_length = opt_len - opt_offset;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += padd_length;
break;
}
case ND_OPT_DNS_SEARCH_LIST:
{
int dnssl_len;
const guchar *dnssl_name;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 2, ENC_NA);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_dnssl_lifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
while(opt_offset < (offset + opt_len) ) {
if(tvb_get_guint8(tvb, opt_offset) == 0){
int padd_length = (offset + opt_len) - opt_offset;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_padding, tvb, opt_offset, padd_length, ENC_NA);
opt_offset += padd_length;
break;
}
used_bytes = get_dns_name(tvb, opt_offset, 0, opt_offset, &dnssl_name, &dnssl_len);
proto_tree_add_string(icmp6opt_tree, hf_icmpv6_opt_dnssl, tvb, opt_offset, used_bytes, format_text(wmem_packet_scope(), dnssl_name, dnssl_len));
proto_item_append_text(ti, " %s", dnssl_name);
opt_offset += used_bytes;
}
break;
}
case ND_OPT_PROXY_SIGNATURE:
{
int par_len;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 2, ENC_NA);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_ps_key_hash, tvb, opt_offset, 16, ENC_NA);
opt_offset += 16;
par_len = opt_len - 20;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_digital_signature_padding , tvb, opt_offset, par_len, ENC_NA);
opt_offset += par_len;
break;
}
case ND_OPT_ADDR_REGISTRATION:
{
guint8 status;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_aro_status, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
status = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 3, ENC_NA);
opt_offset += 3;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_aro_registration_lifetime, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_aro_eui64, tvb, opt_offset, 8, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " : Register %s %s", tvb_eui64_to_str(tvb, opt_offset), val_to_str(status, nd_opt_6lowpannd_status_val, "Unknown %d"));
opt_offset += 8;
}
break;
case ND_OPT_6LOWPAN_CONTEXT:
{
ieee802154_hints_t *hints;
guint8 context_id;
guint8 context_len;
struct e_in6_addr context_prefix;
address context_prefix_addr;
static const int * _6lowpan_context_flags[] = {
&hf_icmpv6_opt_6co_flag_c,
&hf_icmpv6_opt_6co_flag_cid,
&hf_icmpv6_opt_6co_flag_reserved,
NULL
};
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_6co_context_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
context_len = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
context_id = tvb_get_guint8(tvb, opt_offset) & ND_OPT_6CO_FLAG_CID;
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_opt_6co_flag, ett_icmpv6_flag_6lowpan, _6lowpan_context_flags, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_reserved, tvb, opt_offset, 2, ENC_NA);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_6co_valid_lifetime, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
memset(&context_prefix.bytes, 0, sizeof(context_prefix));
switch(opt_len){
case 8:
proto_item_append_text(ti, " ::/%d", context_len);
break;
case 16:
tvb_memcpy(tvb, (guint8 *)&context_prefix.bytes, opt_offset, 8);
proto_tree_add_ipv6(icmp6opt_tree, hf_icmpv6_opt_6co_context_prefix, tvb, opt_offset, 8, &context_prefix);
set_address(&context_prefix_addr, AT_IPv6, 16, context_prefix.bytes);
proto_item_append_text(ti, " %s/%d", address_to_str(wmem_packet_scope(), &context_prefix_addr), context_len);
opt_offset += 8;
break;
case 24:
tvb_memcpy(tvb, (guint8 *)&context_prefix.bytes, opt_offset, 16);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_6co_context_prefix, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s/%d", tvb_ip6_to_str(tvb, opt_offset), context_len);
opt_offset += 16;
break;
default:
expert_add_info(pinfo, ti_opt_len, &ei_icmpv6_invalid_option_length);
break;
}
hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
if ((opt_len <= 24) && hints) {
lowpan_context_insert(context_id, hints->src_pan, context_len, &context_prefix, pinfo->num);
}
}
break;
case ND_OPT_AUTH_BORDER_ROUTER:
{
guint32 version_low, version_high, valid_lifetime;
proto_tree_add_item_ret_uint(icmp6opt_tree, hf_icmpv6_opt_abro_version_low, tvb, opt_offset, 2, ENC_BIG_ENDIAN, &version_low);
opt_offset += 2;
proto_tree_add_item_ret_uint(icmp6opt_tree, hf_icmpv6_opt_abro_version_high, tvb, opt_offset, 2, ENC_BIG_ENDIAN, &version_high);
opt_offset += 2;
proto_tree_add_item_ret_uint(icmp6opt_tree, hf_icmpv6_opt_abro_valid_lifetime, tvb, opt_offset, 2, ENC_BIG_ENDIAN, &valid_lifetime);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_abro_6lbr_address, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " : Version %d.%d, Valid Lifetime : %d, 6LBR : %s", version_high, version_low, valid_lifetime, tvb_ip6_to_str(tvb, opt_offset));
opt_offset += 16;
}
break;
case ND_OPT_6CIO:
{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_6cio_unassigned1, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_6cio_flag_g, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_opt_6cio_unassigned2, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
}
break;
default :
expert_add_info_format(pinfo, ti, &ei_icmpv6_undecoded_option,
"Dissector for ICMPv6 Option (%d)"
" code not implemented, Contact Wireshark developers"
" if you want this supported", opt_type);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_data, tvb, opt_offset, opt_len-2, ENC_NA);
opt_offset += opt_len - 2;
break;
}
offset += opt_len;
if(offset > opt_offset){
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_unknown_data, tvb, opt_offset, offset - opt_offset, ENC_NA);
expert_add_info(pinfo, ti_opt, &ei_icmpv6_unknown_data);
}
proto_item_append_text(ti, ")");
}
return offset;
}
static int
dissect_icmpv6_rpl_opt(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 icmp6_code)
{
proto_tree *icmp6opt_tree, *flag_tree;
proto_item *ti, *ti_opt, *ti_opt_len, *ti_opt_reply, *ti_opt_hop_by_hop, *ti_opt_num_of_routes,
*ti_opt_lifetime, *ti_opt_mr_nh = NULL;
guint8 opt_type;
int opt_len;
int opt_offset;
while ((int)tvb_reported_length(tvb) > offset) {
ti = proto_tree_add_item(tree, hf_icmpv6_rpl_opt, tvb, offset, 1, ENC_NA);
icmp6opt_tree = proto_item_add_subtree(ti, ett_icmpv6_rpl_opt);
opt_offset = offset;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_type, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_type = tvb_get_guint8(tvb, opt_offset);
opt_offset += 1;
proto_item_append_text(ti, " (%s", val_to_str(opt_type, rpl_option_vals, "Unknown %d"));
if (opt_type == RPL_OPT_PAD1) {
offset += 1;
proto_item_append_text(ti, ")");
continue;
}
ti_opt_len = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_len = tvb_get_guint8(tvb, opt_offset);
proto_item_set_len(ti, opt_len + 2);
opt_offset += 1;
switch (opt_type) {
case RPL_OPT_PADN:
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_padn, tvb, opt_offset, opt_len, ENC_NA);
proto_item_append_text(ti_opt, " (Length : %i bytes)", opt_len);
opt_offset += opt_len;
break;
case RPL_OPT_METRIC: {
proto_tree *metric_constraint_tree;
proto_item *ti_metric_constraint;
guint8 metric_constraint_type;
gint metric_len;
while (opt_offset < offset + opt_len) {
static const int * rpl_metric_flags[] = {
&hf_icmpv6_rpl_opt_metric_reserved,
&hf_icmpv6_rpl_opt_metric_flag_p,
&hf_icmpv6_rpl_opt_metric_flag_c,
&hf_icmpv6_rpl_opt_metric_flag_o,
&hf_icmpv6_rpl_opt_metric_flag_r,
&hf_icmpv6_rpl_opt_metric_a,
&hf_icmpv6_rpl_opt_metric_prec,
NULL
};
guint16 metric_constraint_flags;
metric_constraint_type = tvb_get_guint8(tvb, opt_offset);
ti_metric_constraint = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_metric_type, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
metric_constraint_tree = proto_item_add_subtree(ti_metric_constraint, ett_icmpv6_rpl_metric_type);
opt_offset += 1;
proto_tree_add_bitmask(metric_constraint_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_metric_flags, ett_icmpv6_rpl_metric_flags, rpl_metric_flags, ENC_BIG_ENDIAN);
metric_constraint_flags = tvb_get_guint16(tvb, opt_offset, ENC_BIG_ENDIAN);
opt_offset += 2;
metric_len = tvb_get_guint8(tvb, opt_offset);
proto_tree_add_item(metric_constraint_tree, hf_icmpv6_rpl_opt_metric_len, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
switch(metric_constraint_type) {
case RPL_METRIC_NSA:
{
static const int * metric_nsa_flags[] = {
&hf_icmpv6_rpl_opt_metric_nsa_object_reserved,
&hf_icmpv6_rpl_opt_metric_nsa_object_flags,
&hf_icmpv6_rpl_opt_metric_nsa_object_flag_a,
&hf_icmpv6_rpl_opt_metric_nsa_object_flag_o,
NULL
};
proto_tree_add_bitmask(metric_constraint_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_metric_nsa_object,
ett_icmpv6_rpl_metric_nsa_object, metric_nsa_flags, ENC_BIG_ENDIAN);
opt_offset += 2;
break;
}
case RPL_METRIC_NE:
{
static const int * metric_ne_flags[] = {
&hf_icmpv6_rpl_opt_metric_ne_object_flags,
&hf_icmpv6_rpl_opt_metric_ne_object_flag_i,
&hf_icmpv6_rpl_opt_metric_ne_object_type,
&hf_icmpv6_rpl_opt_metric_ne_object_flag_e,
&hf_icmpv6_rpl_opt_metric_ne_object_energy,
NULL
};
for (; metric_len > 0; metric_len -= 2) {
proto_tree_add_bitmask(metric_constraint_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_metric_ne_object,
ett_icmpv6_rpl_metric_ne_object, metric_ne_flags, ENC_BIG_ENDIAN);
opt_offset += 2;
}
break;
}
case RPL_METRIC_HP:
{
static const int * metric_hp_flags[] = {
&hf_icmpv6_rpl_opt_metric_hp_object_reserved,
&hf_icmpv6_rpl_opt_metric_hp_object_flags,
&hf_icmpv6_rpl_opt_metric_hp_object_hp,
NULL
};
proto_tree_add_bitmask(metric_constraint_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_metric_hp_object,
ett_icmpv6_rpl_metric_hp_object, metric_hp_flags, ENC_BIG_ENDIAN);
opt_offset += 2;
break;
}
case RPL_METRIC_LT:
for (; metric_len > 0; metric_len -= 4) {
proto_tree_add_item(metric_constraint_tree, hf_icmpv6_rpl_opt_metric_lt_object_lt, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
}
break;
case RPL_METRIC_LL:
for (; metric_len > 0; metric_len -= 4) {
proto_tree_add_item(metric_constraint_tree, hf_icmpv6_rpl_opt_metric_ll_object_ll, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
}
break;
case RPL_METRIC_LQL:
{
static const int * metric_lql_flags[] = {
&hf_icmpv6_rpl_opt_metric_lql_object_val,
&hf_icmpv6_rpl_opt_metric_lql_object_counter,
NULL
};
proto_tree_add_item(metric_constraint_tree, hf_icmpv6_rpl_opt_metric_lql_object_res, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
metric_len -= 1;
for (; metric_len > 0; metric_len -= 1) {
proto_tree_add_bitmask(metric_constraint_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_metric_lql_object,
ett_icmpv6_rpl_metric_lql_object, metric_lql_flags, ENC_BIG_ENDIAN);
opt_offset += 1;
}
break;
}
case RPL_METRIC_ETX:
for (; metric_len > 0; metric_len -= 2) {
proto_tree_add_item(metric_constraint_tree, hf_icmpv6_rpl_opt_metric_etx_object_etx, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
}
break;
case RPL_METRIC_LC:
proto_tree_add_item(metric_constraint_tree, hf_icmpv6_rpl_opt_metric_lc_object_res, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
metric_len -= 1;
for (; metric_len > 0; metric_len -= 2) {
ti_opt = proto_tree_add_item(metric_constraint_tree, hf_icmpv6_rpl_opt_metric_lc_object, tvb, opt_offset, 2, ENC_NA);
flag_tree = proto_item_add_subtree(ti_opt, ett_icmpv6_rpl_metric_lc_object);
proto_tree_add_item(flag_tree, hf_icmpv6_rpl_opt_metric_lc_object_lc, tvb, opt_offset, 2, ENC_NA);
if (metric_constraint_flags & RPL_METRIC_FLAG_C) {
proto_tree_add_item(flag_tree, hf_icmpv6_rpl_opt_metric_lc_object_reserved, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_icmpv6_rpl_opt_metric_lc_object_flag_i, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
} else if (metric_constraint_flags & RPL_METRIC_FLAG_R) {
proto_tree_add_item(flag_tree, hf_icmpv6_rpl_opt_metric_lc_object_counter, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
} else {
expert_add_info(pinfo, ti_opt, &ei_icmpv6_rpl_unknown_metric);
}
opt_offset += 2;
}
break;
default:
expert_add_info(pinfo, ti_opt_len, &ei_icmpv6_rpl_unknown_metric);
break;
}
}
break;
}
case RPL_OPT_ROUTING: {
guint8 prefix_len;
struct e_in6_addr prefix;
address prefix_addr;
static const int * rpl_flags[] = {
&hf_icmpv6_rpl_opt_route_pref,
&hf_icmpv6_rpl_opt_route_reserved,
NULL
};
prefix_len = tvb_get_guint8(tvb, opt_offset);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_prefix_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset +=1;
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_route_flag,
ett_icmpv6_rpl_flag_routing, rpl_flags, ENC_BIG_ENDIAN);
opt_offset +=1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_lifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
switch(opt_len){
case 6:
proto_item_append_text(ti, " ::/%d", prefix_len);
break;
case 14:
memset(&prefix, 0, sizeof(prefix));
tvb_memcpy(tvb, (guint8 *)&prefix.bytes, opt_offset, 8);
proto_tree_add_ipv6(icmp6opt_tree, hf_icmpv6_rpl_opt_route_prefix, tvb, opt_offset, 8, &prefix);
set_address(&prefix_addr, AT_IPv6, 16, prefix.bytes);
proto_item_append_text(ti, " %s/%d", address_to_str(wmem_packet_scope(), &prefix_addr), prefix_len);
opt_offset += 8;
break;
case 22:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_prefix, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s/%d", tvb_ip6_to_str(tvb, opt_offset), prefix_len);
opt_offset += 16;
break;
default:
expert_add_info(pinfo, ti_opt_len, &ei_icmpv6_invalid_option_length);
break;
}
break;
}
case RPL_OPT_CONFIG: {
static const int * rpl_config_flags[] = {
&hf_icmpv6_rpl_opt_config_reserved,
&hf_icmpv6_rpl_opt_config_auth,
&hf_icmpv6_rpl_opt_config_pcs,
NULL
};
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_config_flag,
ett_icmpv6_rpl_flag_config, rpl_config_flags, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_doublings, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_min_interval, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_redundancy, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_rank_incr, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_hop_rank_inc, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_ocp, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_rsv, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_def_lifetime, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_config_lifetime_unit, tvb, opt_offset, 2, ENC_BIG_ENDIAN);
opt_offset += 2;
break;
}
case RPL_OPT_TARGET: {
guint8 prefix_len;
struct e_in6_addr target_prefix;
address target_prefix_addr;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_target_flag, tvb, opt_offset, 1, ENC_NA);
opt_offset += 1;
prefix_len = tvb_get_guint8(tvb, opt_offset);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_target_prefix_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
switch(opt_len){
case 2:
proto_item_append_text(ti, " ::/%d", prefix_len);
break;
case 10:
memset(&target_prefix, 0, sizeof(target_prefix));
tvb_memcpy(tvb, (guint8 *)&target_prefix.bytes, opt_offset, 8);
proto_tree_add_ipv6(icmp6opt_tree, hf_icmpv6_rpl_opt_target_prefix, tvb, opt_offset, 8, &target_prefix);
set_address(&target_prefix_addr, AT_IPv6, 16, target_prefix.bytes);
proto_item_append_text(ti, " %s/%d", address_to_str(wmem_packet_scope(), &target_prefix_addr), prefix_len);
opt_offset += 8;
break;
case 18:
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_target_prefix, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s/%d", tvb_ip6_to_str(tvb, opt_offset), prefix_len);
opt_offset += 16;
break;
default:
expert_add_info(pinfo, ti_opt_len, &ei_icmpv6_invalid_option_length);
break;
}
break;
}
case RPL_OPT_TRANSIT: {
static const int * rpl_transit_flags[] = {
&hf_icmpv6_rpl_opt_transit_flag_e,
&hf_icmpv6_rpl_opt_transit_flag_rsv,
NULL
};
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_transit_flag,
ett_icmpv6_rpl_flag_transit, rpl_transit_flags, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_transit_pathctl, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_transit_pathseq, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_transit_pathlifetime, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
if(opt_len > 4)
{
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_transit_parent, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s", tvb_ip6_to_str(tvb, opt_offset));
opt_offset += 16;
}
break;
}
case RPL_OPT_SOLICITED: {
static const int * rpl_solicited_flags[] = {
&hf_icmpv6_rpl_opt_solicited_flag_v,
&hf_icmpv6_rpl_opt_solicited_flag_i,
&hf_icmpv6_rpl_opt_solicited_flag_d,
&hf_icmpv6_rpl_opt_solicited_flag_rsv,
NULL
};
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_solicited_instance, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_solicited_flag,
ett_icmpv6_rpl_flag_solicited, rpl_solicited_flags, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_solicited_dodagid, tvb, opt_offset, 16, ENC_NA);
opt_offset += 16;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_solicited_version, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset += 1;
break;
}
case RPL_OPT_PREFIX: {
guint32 prefix_len;
static const int * rpl_prefix_flags[] = {
&hf_icmpv6_rpl_opt_prefix_flag_l,
&hf_icmpv6_rpl_opt_prefix_flag_a,
&hf_icmpv6_rpl_opt_prefix_flag_r,
&hf_icmpv6_rpl_opt_prefix_flag_rsv,
NULL
};
proto_tree_add_item_ret_uint(icmp6opt_tree, hf_icmpv6_rpl_opt_prefix_length, tvb, opt_offset, 1, ENC_BIG_ENDIAN, &prefix_len);
opt_offset +=1;
proto_tree_add_bitmask(icmp6opt_tree, tvb, opt_offset, hf_icmpv6_rpl_opt_prefix_flag,
ett_icmpv6_rpl_flag_prefix, rpl_prefix_flags, ENC_BIG_ENDIAN);
opt_offset += 1;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_prefix_vlifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_prefix_plifetime, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_reserved, tvb, opt_offset, 4, ENC_NA);
opt_offset += 4;
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_prefix, tvb, opt_offset, 16, ENC_NA);
proto_item_append_text(ti, " %s/%d", tvb_ip6_to_str(tvb, opt_offset), prefix_len);
opt_offset += 16;
break;
}
case RPL_OPT_TARGETDESC: {
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_targetdesc, tvb, opt_offset, 4, ENC_BIG_ENDIAN);
opt_offset += 4;
break;
}
case RPL_OPT_ROUTE_DISCOVERY: {
int num_of_addr = 0;
guint8 flags = 0, compr = 0, addr_len = 0, lt_mr_nh = 0;
guint8 addr[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_discovery_flag, tvb, opt_offset, 1, ENC_NA);
flag_tree = proto_item_add_subtree(ti_opt, ett_icmpv6_rpl_route_discovery_flag);
flags = tvb_get_guint8(tvb, opt_offset);
compr = flags & RPL_OPT_ROUTE_DISCOVERY_COMPR;
ti_opt_reply = proto_tree_add_item(flag_tree, hf_icmpv6_rpl_opt_route_discovery_reply, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
ti_opt_hop_by_hop = proto_tree_add_item(flag_tree, hf_icmpv6_rpl_opt_route_discovery_hop_by_hop, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
ti_opt_num_of_routes = proto_tree_add_item(flag_tree, hf_icmpv6_rpl_opt_route_discovery_num_of_routes, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_icmpv6_rpl_opt_route_discovery_compr, tvb, opt_offset, 1, ENC_BIG_ENDIAN);
opt_offset +=1;
lt_mr_nh = tvb_get_guint8(tvb, opt_offset);
ti_opt_lifetime = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_discovery_lifetime, tvb, opt_offset, 1, ENC_NA);
if ((icmp6_code == ICMP6_RPL_P2P_DRO) || (icmp6_code == ICMP6_RPL_P2P_SDRO)) {
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_discovery_nh, tvb, opt_offset, 1, ENC_NA);
} else {
ti_opt_mr_nh = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_discovery_maxrank, tvb, opt_offset, 1, ENC_NA);
}
opt_offset +=1;
switch (icmp6_code) {
case ICMP6_RPL_P2P_SDRO:
case ICMP6_RPL_P2P_DRO:
if (flags & RPL_OPT_ROUTE_DISCOVERY_R) {
expert_add_info(pinfo, ti_opt_reply, &ei_icmpv6_rpl_p2p_dro_rdo_zero);
}
if (flags & RPL_OPT_ROUTE_DISCOVERY_N) {
expert_add_info(pinfo, ti_opt_num_of_routes, &ei_icmpv6_rpl_p2p_dro_rdo_zero);
}
if (lt_mr_nh & RPL_OPT_ROUTE_DISCOVERY_L) {
expert_add_info(pinfo, ti_opt_lifetime, &ei_icmpv6_rpl_p2p_dro_rdo_zero);
}
break;
default:
if (flags & RPL_OPT_ROUTE_DISCOVERY_H) {
if (!(flags & RPL_OPT_ROUTE_DISCOVERY_R)) {
expert_add_info(pinfo, ti_opt_hop_by_hop, &ei_icmpv6_rpl_p2p_hop_by_hop);
}
if (flags & RPL_OPT_ROUTE_DISCOVERY_N) {
expert_add_info(pinfo, ti_opt_num_of_routes, &ei_icmpv6_rpl_p2p_num_of_routes);
}
}
proto_item_append_text(ti_opt_lifetime, " (%d sec)", (int) pow(4.0, (lt_mr_nh & RPL_OPT_ROUTE_DISCOVERY_L) >> 6));
if (!(lt_mr_nh & RPL_OPT_ROUTE_DISCOVERY_MR_NH)) {
proto_item_append_text(ti_opt_mr_nh, " (Infinity)");
}
break;
}
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_discovery_target_addr, tvb, opt_offset, 16, ENC_NA);
opt_offset +=16;
addr_len = (16 - compr);
num_of_addr = (opt_len - 18) / addr_len;
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_rpl_opt_route_discovery_addr_vec, tvb, opt_offset, (opt_len - 18), ENC_NA);
flag_tree = proto_item_add_subtree(ti_opt, ett_icmpv6_rpl_route_discovery_addr_vec);
proto_item_append_text(flag_tree, " (%d Address%s)", num_of_addr, num_of_addr != 1 ? "es" : "");
while (num_of_addr--) {
memset(addr, 0, sizeof(addr));
tvb_memcpy(tvb, addr + compr, opt_offset, addr_len);
proto_tree_add_ipv6(flag_tree, hf_icmpv6_rpl_opt_route_discovery_addr_vec_addr, tvb, opt_offset, addr_len, (struct e_in6_addr *)addr);
opt_offset += addr_len;
}
break;
}
default :
expert_add_info_format(pinfo, ti, &ei_icmpv6_undecoded_rpl_option,
"Dissector for ICMPv6 RPL Option"
" (%d) code not implemented, Contact"
" Wireshark developers if you want this supported", opt_type);
proto_tree_add_item(icmp6opt_tree, hf_icmpv6_data, tvb, opt_offset, opt_len, ENC_NA);
opt_offset += opt_len;
break;
}
offset += opt_len + 2;
if(offset > opt_offset){
ti_opt = proto_tree_add_item(icmp6opt_tree, hf_icmpv6_unknown_data, tvb, opt_offset, offset - opt_offset, ENC_NA);
expert_add_info(pinfo, ti_opt, &ei_icmpv6_unknown_data);
}
proto_item_append_text(ti, ")");
}
return offset;
}
static int
dissect_rpl_control(tvbuff_t *tvb, int rpl_offset, packet_info *pinfo _U_, proto_tree *icmp6_tree, guint8 icmp6_type _U_, guint8 icmp6_code)
{
proto_item *ti;
if(icmp6_code & ICMP6_RPL_SECURE)
{
guint8 kim, lvl;
static const int * rpl_secure_flags[] = {
&hf_icmpv6_rpl_secure_flag_t,
&hf_icmpv6_rpl_secure_flag_rsv,
NULL
};
static const int * rpl_secure_flags2[] = {
&hf_icmpv6_rpl_secure_kim,
&hf_icmpv6_rpl_secure_lvl,
&hf_icmpv6_rpl_secure_rsv,
NULL
};
proto_tree_add_bitmask(icmp6_tree, tvb, rpl_offset, hf_icmpv6_rpl_secure_flag,
ett_icmpv6_flag_secure, rpl_secure_flags, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_secure_algorithm, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_bitmask(icmp6_tree, tvb, rpl_offset, hf_icmpv6_rpl_secure_flag,
ett_icmpv6_flag_secure, rpl_secure_flags2, ENC_BIG_ENDIAN);
kim = tvb_get_guint8(tvb, rpl_offset) & RPL_SECURE_KIM >> 6;
lvl = tvb_get_guint8(tvb, rpl_offset) & RPL_SECURE_LVL;
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_secure_flag, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_secure_counter, tvb, rpl_offset, 4, ENC_BIG_ENDIAN);
rpl_offset += 4;
switch(kim){
case 0:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_secure_key_index, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
break;
}
case 1:
{
break;
}
case 2:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_secure_key_source, tvb, rpl_offset, 8, ENC_NA);
rpl_offset += 8;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_secure_key_index, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
break;
}
case 3:
{
if(lvl == 1 || lvl == 3)
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_secure_key_source, tvb, rpl_offset, 8, ENC_NA);
rpl_offset += 8;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_secure_key_index, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
}
break;
}
}
}
switch(icmp6_code){
case ICMP6_RPL_DIS:
case ICMP6_RPL_SDIS:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dis_flag, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, rpl_offset, 1, ENC_NA);
rpl_offset += 1;
rpl_offset = dissect_icmpv6_rpl_opt(tvb, rpl_offset, pinfo, icmp6_tree, icmp6_code);
break;
}
case ICMP6_RPL_DIO:
case ICMP6_RPL_SDIO:
{
static const int * rpl_dio_flags[] = {
&hf_icmpv6_rpl_dio_flag_g,
&hf_icmpv6_rpl_dio_flag_0,
&hf_icmpv6_rpl_dio_flag_mop,
&hf_icmpv6_rpl_dio_flag_prf,
NULL
};
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dio_instance, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dio_version, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dio_rank, tvb, rpl_offset, 2, ENC_BIG_ENDIAN);
rpl_offset += 2;
proto_tree_add_bitmask(icmp6_tree, tvb, rpl_offset, hf_icmpv6_rpl_dio_flag,
ett_icmpv6_flag_rpl_dio, rpl_dio_flags, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dio_dtsn, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dio_flag, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, rpl_offset, 1, ENC_NA);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dio_dagid, tvb, rpl_offset, 16, ENC_NA);
rpl_offset += 16;
rpl_offset = dissect_icmpv6_rpl_opt(tvb, rpl_offset, pinfo, icmp6_tree, icmp6_code);
break;
}
case ICMP6_RPL_DAO:
case ICMP6_RPL_SDAO:
{
guint8 flags;
static const int * rpl_dao_flags[] = {
&hf_icmpv6_rpl_dao_flag_k,
&hf_icmpv6_rpl_dao_flag_d,
&hf_icmpv6_rpl_dao_flag_rsv,
NULL
};
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dao_instance, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_bitmask(icmp6_tree, tvb, rpl_offset, hf_icmpv6_rpl_dao_flag,
ett_icmpv6_flag_rpl_dao, rpl_dao_flags, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, rpl_offset);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, rpl_offset, 1, ENC_NA);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dao_sequence, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
if(flags & RPL_DAO_FLAG_D)
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_dao_dodagid, tvb, rpl_offset, 16, ENC_NA);
rpl_offset += 16;
}
rpl_offset = dissect_icmpv6_rpl_opt(tvb, rpl_offset, pinfo, icmp6_tree, icmp6_code);
break;
}
case ICMP6_RPL_DAOACK:
case ICMP6_RPL_SDAOACK:
{
guint8 flags;
static const int * rpl_daoack_flags[] = {
&hf_icmpv6_rpl_daoack_flag_d,
&hf_icmpv6_rpl_daoack_flag_rsv,
NULL
};
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_daoack_instance, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_bitmask(icmp6_tree, tvb, rpl_offset, hf_icmpv6_rpl_daoack_flag,
ett_icmpv6_flag_rpl_daoack, rpl_daoack_flags, ENC_BIG_ENDIAN);
flags = tvb_get_guint8(tvb, rpl_offset);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_daoack_sequence, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_daoack_status, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
if(flags & RPL_DAOACK_FLAG_D)
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_daoack_dodagid, tvb, rpl_offset, 16, ENC_NA);
rpl_offset += 16;
}
rpl_offset = dissect_icmpv6_rpl_opt(tvb, rpl_offset, pinfo, icmp6_tree, icmp6_code);
break;
}
case ICMP6_RPL_CC:
{
static const int * rpl_cc_flags[] = {
&hf_icmpv6_rpl_cc_flag_r,
&hf_icmpv6_rpl_cc_flag_rsv,
NULL
};
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_cc_instance, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_bitmask(icmp6_tree, tvb, rpl_offset, hf_icmpv6_rpl_cc_flag,
ett_icmpv6_flag_rpl_cc, rpl_cc_flags, ENC_BIG_ENDIAN);
rpl_offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_cc_nonce, tvb, rpl_offset, 2, ENC_BIG_ENDIAN);
rpl_offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_cc_dodagid, tvb, rpl_offset, 16, ENC_NA);
rpl_offset += 16;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_cc_destination_counter, tvb, rpl_offset, 4, ENC_BIG_ENDIAN);
rpl_offset += 4;
rpl_offset = dissect_icmpv6_rpl_opt(tvb, rpl_offset, pinfo, icmp6_tree, icmp6_code);
break;
}
case ICMP6_RPL_P2P_DRO:
case ICMP6_RPL_P2P_SDRO:
{
static const int * rpl_p2p_dro_flags[] = {
&hf_icmpv6_rpl_p2p_dro_flag_stop,
&hf_icmpv6_rpl_p2p_dro_flag_ack,
&hf_icmpv6_rpl_p2p_dro_flag_seq,
&hf_icmpv6_rpl_p2p_dro_flag_reserved,
NULL
};
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_p2p_dro_instance, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
ti = proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_p2p_dro_version, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb, rpl_offset)) {
expert_add_info(pinfo, ti, &ei_icmpv6_rpl_p2p_dro_zero);
}
rpl_offset += 1;
proto_tree_add_bitmask(icmp6_tree, tvb, rpl_offset, hf_icmpv6_rpl_p2p_dro_flag,
ett_icmpv6_rpl_p2p_dro_flag, rpl_p2p_dro_flags, ENC_BIG_ENDIAN);
rpl_offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_p2p_dro_dagid, tvb, rpl_offset, 16, ENC_NA);
rpl_offset += 16;
rpl_offset = dissect_icmpv6_rpl_opt(tvb, rpl_offset, pinfo, icmp6_tree, icmp6_code);
break;
}
case ICMP6_RPL_P2P_DROACK:
case ICMP6_RPL_P2P_SDROACK:
{
static const int * rpl_p2p_droack_flags[] = {
&hf_icmpv6_rpl_p2p_droack_flag_seq,
&hf_icmpv6_rpl_p2p_droack_flag_reserved,
NULL
};
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_p2p_dro_instance, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
rpl_offset += 1;
ti = proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_p2p_dro_version, tvb, rpl_offset, 1, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb, rpl_offset)) {
expert_add_info(pinfo, ti, &ei_icmpv6_rpl_p2p_dro_zero);
}
rpl_offset += 1;
proto_tree_add_bitmask(icmp6_tree, tvb, rpl_offset, hf_icmpv6_rpl_p2p_droack_flag,
ett_icmpv6_rpl_p2p_droack_flag, rpl_p2p_droack_flags, ENC_BIG_ENDIAN);
rpl_offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_rpl_p2p_dro_dagid, tvb, rpl_offset, 16, ENC_NA);
rpl_offset += 16;
break;
}
}
return rpl_offset;
}
static int
dissect_nodeinfo(tvbuff_t *tvb, int ni_offset, packet_info *pinfo _U_, proto_tree *tree, guint8 icmp6_type, guint8 icmp6_code)
{
guint16 qtype;
guint used_bytes;
static const int * ni_flags[] = {
&hf_icmpv6_ni_flag_g,
&hf_icmpv6_ni_flag_s,
&hf_icmpv6_ni_flag_l,
&hf_icmpv6_ni_flag_c,
&hf_icmpv6_ni_flag_a,
&hf_icmpv6_ni_flag_t,
&hf_icmpv6_ni_flag_rsv,
NULL
};
proto_tree_add_item(tree, hf_icmpv6_ni_qtype, tvb, ni_offset, 2, ENC_BIG_ENDIAN);
qtype = tvb_get_ntohs(tvb, ni_offset);
ni_offset += 2;
proto_tree_add_bitmask(tree, tvb, ni_offset, hf_icmpv6_ni_flag,
ett_icmpv6_flag_ni, ni_flags, ENC_BIG_ENDIAN);
ni_offset += 2;
proto_tree_add_item(tree, hf_icmpv6_ni_nonce, tvb, ni_offset, 8, ENC_BIG_ENDIAN);
ni_offset += 8;
if(tvb_reported_length_remaining(tvb, ni_offset) == 0){
return ni_offset;
}
if(icmp6_type == ICMP6_NI_QUERY){
switch(icmp6_code){
case ICMP6_NI_SUBJ_IPV6: {
proto_tree_add_item(tree, hf_icmpv6_ni_query_subject_ipv6, tvb, ni_offset, 16, ENC_NA);
ni_offset += 16;
break;
}
case ICMP6_NI_SUBJ_FQDN: {
int fqdn_len;
const guchar *fqdn_name;
used_bytes = get_dns_name(tvb, ni_offset, 0, ni_offset, &fqdn_name, &fqdn_len);
proto_tree_add_string(tree, hf_icmpv6_ni_query_subject_fqdn, tvb, ni_offset, used_bytes,
format_text(wmem_packet_scope(), fqdn_name, fqdn_len));
ni_offset += fqdn_len;
break;
}
case ICMP6_NI_SUBJ_IPV4: {
proto_tree_add_item(tree, hf_icmpv6_ni_query_subject_ipv4, tvb, ni_offset, 4, ENC_BIG_ENDIAN);
ni_offset += 4;
break;
}
}
} else {
switch(qtype){
case NI_QTYPE_NOOP:
break;
case NI_QTYPE_NODENAME: {
int node_name_len;
const guchar *node_name;
proto_tree_add_item(tree, hf_icmpv6_ni_reply_node_ttl, tvb, ni_offset, 4, ENC_BIG_ENDIAN);
ni_offset += 4;
if(tvb_reported_length_remaining(tvb, ni_offset) == 0){
return ni_offset;
}
while(ni_offset < (int)tvb_reported_length(tvb) ) {
if(tvb_get_guint8(tvb, ni_offset) == 0){
break;
}
used_bytes = get_dns_name(tvb, ni_offset, 0, ni_offset, &node_name, &node_name_len);
proto_tree_add_string(tree, hf_icmpv6_ni_reply_node_name, tvb, ni_offset, used_bytes,
format_text(wmem_packet_scope(), node_name, node_name_len));
ni_offset += used_bytes;
}
break;
}
case NI_QTYPE_NODEADDR: {
while(ni_offset < (int)tvb_reported_length(tvb) ) {
proto_tree_add_item(tree, hf_icmpv6_ni_reply_node_ttl, tvb, ni_offset, 4, ENC_BIG_ENDIAN);
ni_offset += 4;
proto_tree_add_item(tree, hf_icmpv6_ni_reply_node_address, tvb, ni_offset, 16, ENC_NA);
ni_offset += 16;
}
break;
}
case NI_QTYPE_IPV4ADDR: {
while(ni_offset < (int)tvb_reported_length(tvb) ) {
proto_tree_add_item(tree, hf_icmpv6_ni_reply_node_ttl, tvb, ni_offset, 4, ENC_BIG_ENDIAN);
ni_offset += 4;
proto_tree_add_item(tree, hf_icmpv6_ni_reply_ipv4_address, tvb, ni_offset, 4, ENC_BIG_ENDIAN);
ni_offset += 4;
}
break;
}
}
}
return ni_offset;
}
static int
dissect_rrenum(tvbuff_t *tvb, int rr_offset, packet_info *pinfo _U_, proto_tree *tree, guint8 icmp6_type _U_, guint8 icmp6_code)
{
proto_tree *mp_tree, *up_tree, *rm_tree;
proto_item *ti, *ti_mp, *ti_up, *ti_rm;
static const int * rr_flags[] = {
&hf_icmpv6_rr_flag_t,
&hf_icmpv6_rr_flag_r,
&hf_icmpv6_rr_flag_a,
&hf_icmpv6_rr_flag_s,
&hf_icmpv6_rr_flag_p,
&hf_icmpv6_rr_flag_rsv,
NULL
};
proto_tree_add_item(tree, hf_icmpv6_rr_sequencenumber, tvb, rr_offset, 4, ENC_BIG_ENDIAN);
rr_offset += 4;
proto_tree_add_item(tree, hf_icmpv6_rr_segmentnumber, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
rr_offset += 1;
proto_tree_add_bitmask(tree, tvb, rr_offset, hf_icmpv6_rr_flag,
ett_icmpv6_flag_rr, rr_flags, ENC_BIG_ENDIAN);
rr_offset += 1;
proto_tree_add_item(tree, hf_icmpv6_rr_maxdelay, tvb, rr_offset, 2, ENC_BIG_ENDIAN);
rr_offset += 2;
proto_tree_add_item(tree, hf_icmpv6_reserved, tvb, rr_offset, 4, ENC_NA);
rr_offset += 4;
if(tvb_reported_length_remaining(tvb, rr_offset) == 0){
return rr_offset;
}
if(icmp6_code == ICMP6_ROUTER_RENUMBERING_COMMAND){
guint8 opcode, matchlen, minlen, maxlen;
ti_mp = proto_tree_add_item(tree, hf_icmpv6_rr_pco_mp_part, tvb, rr_offset, 24, ENC_NA);
mp_tree = proto_item_add_subtree(ti_mp, ett_icmpv6_rr_mp);
proto_tree_add_item(mp_tree, hf_icmpv6_rr_pco_mp_opcode, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
opcode = tvb_get_guint8(tvb, rr_offset);
rr_offset += 1;
proto_tree_add_item(mp_tree, hf_icmpv6_rr_pco_mp_oplength, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
rr_offset += 1;
proto_tree_add_item(mp_tree, hf_icmpv6_rr_pco_mp_ordinal, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
rr_offset += 1;
ti = proto_tree_add_item(mp_tree, hf_icmpv6_rr_pco_mp_matchlen, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
matchlen = tvb_get_guint8(tvb, rr_offset);
if (matchlen > 128) {
expert_add_info(pinfo, ti, &ei_icmpv6_rr_pco_mp_matchlen);
}
rr_offset += 1;
proto_tree_add_item(mp_tree, hf_icmpv6_rr_pco_mp_minlen, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
minlen = tvb_get_guint8(tvb, rr_offset);
rr_offset += 1;
proto_tree_add_item(mp_tree, hf_icmpv6_rr_pco_mp_maxlen, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
maxlen = tvb_get_guint8(tvb, rr_offset);
rr_offset += 1;
proto_tree_add_item(mp_tree, hf_icmpv6_reserved, tvb, rr_offset, 2, ENC_NA);
rr_offset += 2;
proto_tree_add_item(mp_tree, hf_icmpv6_rr_pco_mp_matchprefix, tvb, rr_offset, 16, ENC_NA);
proto_item_append_text(ti_mp, ": %s %s/%u (%u-%u)", val_to_str(opcode, rr_pco_mp_opcode_val, "Unknown %d"), tvb_ip6_to_str(tvb, rr_offset), matchlen, minlen, maxlen);
rr_offset += 16;
while ((int)tvb_reported_length(tvb) > rr_offset) {
guint8 uselen, keeplen;
static const int * mask_flags[] = {
&hf_icmpv6_rr_pco_up_flagmask_l,
&hf_icmpv6_rr_pco_up_flagmask_a,
&hf_icmpv6_rr_pco_up_flagmask_reserved,
NULL
};
static const int * ra_flags[] = {
&hf_icmpv6_rr_pco_up_raflags_l,
&hf_icmpv6_rr_pco_up_raflags_a,
&hf_icmpv6_rr_pco_up_raflags_reserved,
NULL
};
static const int * up_flags[] = {
&hf_icmpv6_rr_pco_up_flag_v,
&hf_icmpv6_rr_pco_up_flag_p,
&hf_icmpv6_rr_pco_up_flag_reserved,
NULL
};
ti_up = proto_tree_add_item(tree, hf_icmpv6_rr_pco_up_part, tvb, rr_offset, 32, ENC_NA);
up_tree = proto_item_add_subtree(ti_up, ett_icmpv6_rr_up);
proto_tree_add_item(up_tree, hf_icmpv6_rr_pco_up_uselen, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
uselen = tvb_get_guint8(tvb, rr_offset);
rr_offset += 1;
proto_tree_add_item(up_tree, hf_icmpv6_rr_pco_up_keeplen, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
keeplen = tvb_get_guint8(tvb, rr_offset);
rr_offset += 1;
proto_tree_add_bitmask(tree, tvb, rr_offset, hf_icmpv6_rr_pco_up_flagmask, ett_icmpv6_rr_up_flag_mask, mask_flags, ENC_BIG_ENDIAN);
rr_offset += 1;
proto_tree_add_bitmask(tree, tvb, rr_offset, hf_icmpv6_rr_pco_up_raflags, ett_icmpv6_rr_up_flag_ra, ra_flags, ENC_BIG_ENDIAN);
rr_offset += 1;
proto_tree_add_item(up_tree, hf_icmpv6_rr_pco_up_validlifetime, tvb, rr_offset, 4, ENC_BIG_ENDIAN);
rr_offset += 4;
proto_tree_add_item(up_tree, hf_icmpv6_rr_pco_up_preferredlifetime, tvb, rr_offset, 4, ENC_BIG_ENDIAN);
rr_offset += 4;
proto_tree_add_bitmask(tree, tvb, rr_offset, hf_icmpv6_rr_pco_up_flag, ett_icmpv6_rr_up_flag, up_flags, ENC_BIG_ENDIAN);
rr_offset += 4;
proto_tree_add_item(up_tree, hf_icmpv6_rr_pco_up_useprefix, tvb, rr_offset, 16, ENC_NA);
rr_offset += 16;
proto_item_append_text(ti_up, ": %s/%u (keep %u)", tvb_ip6_to_str(tvb, rr_offset), uselen, keeplen);
}
}else if(icmp6_code == ICMP6_ROUTER_RENUMBERING_RESULT){
while ((int)tvb_reported_length(tvb) > rr_offset) {
guint8 matchlen;
guint32 interfaceindex;
static const int * rm_flags[] = {
&hf_icmpv6_rr_rm_flag_reserved,
&hf_icmpv6_rr_rm_flag_b,
&hf_icmpv6_rr_rm_flag_f,
NULL
};
ti_rm = proto_tree_add_item(tree, hf_icmpv6_rr_rm, tvb, rr_offset, 24, ENC_NA);
rm_tree = proto_item_add_subtree(ti_rm, ett_icmpv6_rr_rm);
proto_tree_add_bitmask(tree, tvb, rr_offset, hf_icmpv6_rr_rm_flag, ett_icmpv6_rr_rm_flag, rm_flags, ENC_BIG_ENDIAN);
rr_offset +=2;
proto_tree_add_item(rm_tree, hf_icmpv6_rr_rm_ordinal, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
rr_offset +=1;
ti = proto_tree_add_item(rm_tree, hf_icmpv6_rr_rm_matchedlen, tvb, rr_offset, 1, ENC_BIG_ENDIAN);
matchlen = tvb_get_guint8(tvb, rr_offset);
if (matchlen > 128) {
expert_add_info(pinfo, ti, &ei_icmpv6_rr_pco_mp_matchedlen);
}
rr_offset +=1;
proto_tree_add_item(rm_tree, hf_icmpv6_rr_rm_interfaceindex, tvb, rr_offset, 4, ENC_BIG_ENDIAN);
interfaceindex = tvb_get_ntohl(tvb, rr_offset);
rr_offset +=4;
proto_tree_add_item(rm_tree, hf_icmpv6_rr_rm_matchedprefix, tvb, rr_offset, 16, ENC_NA);
proto_item_append_text(ti_rm, ": %s/%u (interface %u)", tvb_ip6_to_str(tvb, rr_offset), matchlen, interfaceindex);
rr_offset +=16;
}
}
return rr_offset;
}
static int
dissect_mldrv2( tvbuff_t *tvb, guint32 offset, packet_info *pinfo _U_, proto_tree *tree )
{
proto_tree *mar_tree;
proto_item *ti_mar;
int mldr_offset = offset;
proto_tree_add_item(tree, hf_icmpv6_reserved, tvb, mldr_offset, 2, ENC_NA );
mldr_offset += 2;
proto_tree_add_item(tree, hf_icmpv6_mldr_nb_mcast_records, tvb, mldr_offset, 2, ENC_BIG_ENDIAN );
mldr_offset += 2;
while(mldr_offset < (int)tvb_reported_length(tvb) ) {
guint8 aux_data_len, record_type;
guint16 i, nb_sources;
ti_mar = proto_tree_add_item(tree, hf_icmpv6_mldr_mar, tvb, mldr_offset, -1, ENC_NA);
mar_tree = proto_item_add_subtree(ti_mar, ett_icmpv6_mar);
proto_tree_add_item(mar_tree, hf_icmpv6_mldr_mar_record_type, tvb, mldr_offset, 1, ENC_BIG_ENDIAN);
record_type = tvb_get_guint8(tvb, mldr_offset);
mldr_offset += 1;
proto_tree_add_item(mar_tree, hf_icmpv6_mldr_mar_aux_data_len, tvb, mldr_offset, 1, ENC_BIG_ENDIAN);
aux_data_len = tvb_get_guint8(tvb, mldr_offset);
mldr_offset += 1;
proto_tree_add_item(mar_tree, hf_icmpv6_mldr_mar_nb_sources, tvb, mldr_offset, 2, ENC_BIG_ENDIAN);
nb_sources = tvb_get_ntohs(tvb, mldr_offset);
mldr_offset += 2;
proto_tree_add_item(mar_tree, hf_icmpv6_mldr_mar_multicast_address, tvb, mldr_offset, 16, ENC_NA);
proto_item_append_text(ti_mar, " %s: %s", val_to_str(record_type, mldr_record_type_val,"Unknown Record Type (%d)"), tvb_ip6_to_str(tvb, mldr_offset));
mldr_offset += 16;
for (i=0; i < nb_sources; i++){
proto_tree_add_item(mar_tree, hf_icmpv6_mldr_mar_source_address, tvb, mldr_offset, 16, ENC_NA);
mldr_offset += 16;
}
if(aux_data_len)
{
proto_tree_add_item(mar_tree, hf_icmpv6_mldr_mar_auxiliary_data, tvb, mldr_offset, aux_data_len * 4, ENC_NA);
mldr_offset += aux_data_len * 4;
}
proto_item_set_len(ti_mar, 4 + 16 + (16 * nb_sources) + (aux_data_len * 4));
}
return mldr_offset;
}
static int
dissect_mpl_control(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 type _U_, guint8 code)
{
proto_tree *seed_info_tree, *bm_tree;
proto_item *ti;
const gint length_of_fixed_part = 2;
int body_offset = offset;
guint8 min_seqno, bm_len, s;
gint remaining, id_len = 0;
guint16 seed_info_index = 0;
gchar *seed_id = NULL;
int i, j;
guint8 b;
if (code != 0) {
ti = proto_tree_add_item(tree, hf_icmpv6_unknown_data, tvb, body_offset, 1, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_icmpv6_unknown_data, "Code must be 0");
return body_offset;
}
remaining = tvb_captured_length_remaining(tvb, body_offset);
while (remaining >= length_of_fixed_part) {
seed_info_index++;
seed_info_tree = proto_tree_add_subtree_format(tree, tvb, body_offset, length_of_fixed_part, ett_icmpv6_mpl_seed_info, NULL,
"MPL Seed Info: [%u]", seed_info_index);
min_seqno = tvb_get_guint8(tvb, body_offset);
proto_tree_add_item(seed_info_tree, hf_icmpv6_mpl_seed_info_min_sequence, tvb, body_offset, 1, ENC_BIG_ENDIAN);
body_offset++;
bm_len = tvb_get_guint8(tvb, body_offset) >> 2;
s = tvb_get_guint8(tvb, body_offset) & 0x03;
proto_tree_add_item(seed_info_tree, hf_icmpv6_mpl_seed_info_bm_len, tvb, body_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(seed_info_tree, hf_icmpv6_mpl_seed_info_s, tvb, body_offset, 1, ENC_BIG_ENDIAN);
body_offset++;
id_len = mpl_seed_id_code_to_length[s];
if ((remaining - length_of_fixed_part) < id_len) {
ti = proto_tree_add_item(seed_info_tree, hf_icmpv6_unknown_data, tvb, body_offset,
remaining - length_of_fixed_part, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_icmpv6_unknown_data,
"Remaining data, %u bytes, is too short for Seed ID of %u bytes",
remaining - length_of_fixed_part, id_len);
return remaining - length_of_fixed_part;
}
switch (s) {
case 0:
seed_id = address_to_str(wmem_packet_scope(), &pinfo->src);
break;
case 1:
seed_id = wmem_strdup_printf(wmem_packet_scope(), "%04x", tvb_get_ntohs(tvb, body_offset));
break;
case 2:
seed_id = tvb_eui64_to_str(tvb, body_offset);
break;
case 3:
seed_id = tvb_ip6_to_str(tvb, body_offset);
break;
default:
break;
}
proto_tree_add_string(seed_info_tree, hf_icmpv6_mpl_seed_info_seed_id, tvb, body_offset, id_len, seed_id);
body_offset += id_len;
if((remaining - length_of_fixed_part - id_len) < bm_len) {
ti = proto_tree_add_item(seed_info_tree, hf_icmpv6_unknown_data, tvb, body_offset,
remaining - length_of_fixed_part - id_len, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_icmpv6_unknown_data,
"Remaining data, %u bytes, is too short for Buffered Messages of %u bytes",
remaining - length_of_fixed_part - id_len, bm_len);
return body_offset - length_of_fixed_part - id_len;
}
if (bm_len > 0) {
bm_tree = proto_tree_add_subtree_format(seed_info_tree, tvb, body_offset, bm_len, ett_icmpv6_mpl_seed_info_bm, NULL,
"Buffered Messages");
for (i = 0; i < bm_len; i++) {
b = tvb_get_guint8(tvb, body_offset + i);
for (j = 0; j < 8; j++) {
if (b & (0x80 >> j)) {
proto_tree_add_uint(bm_tree, hf_icmpv6_mpl_seed_info_sequence, tvb, body_offset + i, 1, (min_seqno + 8 * i + j) % 0x100);
}
}
}
}
body_offset += bm_len;
remaining = tvb_captured_length_remaining(tvb, body_offset);
}
if (remaining != 0) {
ti = proto_tree_add_item(tree, hf_icmpv6_unknown_data, tvb, body_offset, body_offset - offset, ENC_NA);
expert_add_info_format(pinfo, ti, &ei_icmpv6_unknown_data,
"%u bytes data is left after dissecting MPL Control Message", remaining);
}
return body_offset;
}
static gboolean
capture_icmpv6(const guchar *pd _U_, int offset _U_, int len _U_, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
capture_dissector_increment_count(cpinfo, proto_icmpv6);
return TRUE;
}
static int
dissect_icmpv6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_tree *icmp6_tree = NULL;
proto_item *ti = NULL, *checksum_item = NULL, *code_item = NULL;
const char *code_name = NULL;
guint length = 0, reported_length;
vec_t cksum_vec[4];
guint32 phdr[2];
guint16 cksum;
int offset;
tvbuff_t *next_tvb;
guint8 icmp6_type, icmp6_code;
icmp_transaction_t *trans = NULL;
ws_ip *iph = (ws_ip*)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICMPv6");
col_clear(pinfo->cinfo, COL_INFO);
offset = 0;
if (tree) {
ti = proto_tree_add_item(tree, proto_icmpv6, tvb, offset, -1, ENC_NA);
icmp6_tree = proto_item_add_subtree(ti, ett_icmpv6);
proto_tree_add_item(icmp6_tree, hf_icmpv6_type, tvb, offset, 1, ENC_BIG_ENDIAN);
}
icmp6_type = tvb_get_guint8(tvb, offset);
offset += 1;
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(icmp6_type, icmpv6_type_val, "Unknown (%d)"));
if (tree)
code_item = proto_tree_add_item(icmp6_tree, hf_icmpv6_code, tvb, offset, 1, ENC_BIG_ENDIAN);
icmp6_code = tvb_get_guint8(tvb, offset);
offset += 1;
switch (icmp6_type) {
case ICMP6_DST_UNREACH:
code_name = val_to_str_const(icmp6_code, icmpv6_unreach_code_val, "Unknown");
break;
case ICMP6_TIME_EXCEEDED:
code_name = val_to_str(icmp6_code, icmpv6_timeex_code_val, "Unknown (%d)");
break;
case ICMP6_PARAM_PROB:
code_name = val_to_str(icmp6_code, icmpv6_paramprob_code_val, "Unknown (%d)");
break;
case ICMP6_ROUTER_RENUMBERING:
code_name = val_to_str(icmp6_code, icmpv6_rr_code_val, "Unknown (%d)");
break;
case ICMP6_NI_QUERY:
code_name = val_to_str(icmp6_code, ni_query_code_val, "Unknown (%d)");
break;
case ICMP6_NI_REPLY:
code_name = val_to_str(icmp6_code, ni_reply_code_val, "Unknown (%d)");
break;
case ICMP6_RPL_CONTROL:
code_name = val_to_str(icmp6_code, rpl_code_val, "Unknown (%d)");
break;
}
if (code_name)
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", code_name);
if (pinfo->destport == 3544 && icmp6_type == ICMP6_ECHO_REQUEST) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Teredo");
col_set_str(pinfo->cinfo, COL_INFO, "Direct IPv6 Connectivity Test");
}
if (code_name)
proto_item_append_text(code_item, " (%s)", code_name);
cksum = tvb_get_ntohs(tvb, offset);
length = tvb_captured_length(tvb);
reported_length = tvb_reported_length(tvb);
if (!pinfo->fragmented && length >= reported_length && !pinfo->flags.in_error_pkt) {
SET_CKSUM_VEC_PTR(cksum_vec[0], (const guint8 *)pinfo->src.data, pinfo->src.len);
SET_CKSUM_VEC_PTR(cksum_vec[1], (const guint8 *)pinfo->dst.data, pinfo->dst.len);
phdr[0] = g_htonl(reported_length);
phdr[1] = g_htonl(IP_PROTO_ICMPV6);
SET_CKSUM_VEC_PTR(cksum_vec[2], (const guint8 *)&phdr, 8);
SET_CKSUM_VEC_TVB(cksum_vec[3], tvb, 0, reported_length);
proto_tree_add_checksum(icmp6_tree, tvb, 2, hf_icmpv6_checksum, hf_icmpv6_checksum_status, &ei_icmpv6_checksum, pinfo, in_cksum(cksum_vec, 4),
ENC_BIG_ENDIAN, PROTO_CHECKSUM_VERIFY|PROTO_CHECKSUM_IN_CKSUM);
} else {
checksum_item = proto_tree_add_checksum(icmp6_tree, tvb, 2, hf_icmpv6_checksum, hf_icmpv6_checksum_status, &ei_icmpv6_checksum, pinfo, 0,
ENC_BIG_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
proto_item_append_text(checksum_item, " [%s]",
pinfo->flags.in_error_pkt ? "in ICMP error packet" : "fragmented datagram");
}
offset += 2;
if (icmp6_type == ICMP6_ECHO_REQUEST || icmp6_type == ICMP6_ECHO_REPLY) {
guint16 identifier, sequence;
proto_tree_add_item(icmp6_tree, hf_icmpv6_echo_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
identifier = tvb_get_ntohs(tvb, offset);
offset += 2;
if (tree)
proto_tree_add_item(icmp6_tree, hf_icmpv6_echo_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
sequence = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " id=0x%04x, seq=%u",
identifier, sequence);
if (iph != NULL) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", hop limit=%u",
iph->ip_ttl);
}
if (pinfo->destport == 3544 && icmp6_type == ICMP6_ECHO_REQUEST) {
proto_tree_add_item(icmp6_tree, hf_icmpv6_nonce, tvb, offset, 4, ENC_NA);
offset += 4;
} else {
if (!pinfo->flags.in_error_pkt) {
guint32 conv_key[2];
conv_key[1] = (guint32)((identifier << 16) | sequence);
if (icmp6_type == ICMP6_ECHO_REQUEST) {
conv_key[0] = (guint32)cksum;
if (pinfo->flags.in_gre_pkt)
conv_key[0] |= 0x00010000;
trans = transaction_start(pinfo, icmp6_tree, conv_key);
} else {
guint16 tmp[2];
tmp[0] = ~cksum;
tmp[1] = ~0x0100;
SET_CKSUM_VEC_PTR(cksum_vec[0], (guint8 *)tmp, sizeof(tmp));
conv_key[0] = in_cksum(cksum_vec, 1);
if (conv_key[0] == 0)
conv_key[0] = 0xffff;
if (pinfo->flags.in_gre_pkt)
conv_key[0] |= 0x00010000;
trans = transaction_end(pinfo, icmp6_tree, conv_key);
}
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset += call_data_dissector(next_tvb, pinfo, icmp6_tree);
}
}
if (1) {
switch (icmp6_type) {
case ICMP6_DST_UNREACH:
case ICMP6_TIME_EXCEEDED:
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset += dissect_contained_icmpv6(next_tvb, pinfo, icmp6_tree);
break;
case ICMP6_PACKET_TOO_BIG:
proto_tree_add_item(icmp6_tree, hf_icmpv6_mtu, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset += dissect_contained_icmpv6(next_tvb, pinfo, icmp6_tree);
break;
case ICMP6_PARAM_PROB:
proto_tree_add_item(icmp6_tree, hf_icmpv6_pointer, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset += dissect_contained_icmpv6(next_tvb, pinfo, icmp6_tree);
break;
case ICMP6_ECHO_REQUEST:
case ICMP6_ECHO_REPLY:
break;
case ICMP6_MEMBERSHIP_QUERY:
case ICMP6_MEMBERSHIP_REPORT:
case ICMP6_MEMBERSHIP_REDUCTION:
{
if ((icmp6_type == ICMP6_MEMBERSHIP_QUERY) && (length >= MLDV2_PACKET_MINLEN)) {
guint32 mrc;
guint16 qqi, i, nb_sources;
static const int * mld_flags[] = {
&hf_icmpv6_mld_flag_s,
&hf_icmpv6_mld_flag_qrv,
&hf_icmpv6_mld_flag_rsv,
NULL
};
mrc = tvb_get_ntohs(tvb, offset);
if (mrc >= 32768){
mrc = ((mrc & 0x0fff) | 0x1000) << (((mrc & 0x7000) >> 12) + 3);
}
proto_tree_add_uint(icmp6_tree, hf_icmpv6_mld_mrc, tvb, offset, 2, mrc);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_mld_multicast_address, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_bitmask(icmp6_tree, tvb, offset, hf_icmpv6_mld_flag, ett_icmpv6_flag_mld, mld_flags, ENC_BIG_ENDIAN);
offset += 1;
qqi = tvb_get_guint8(tvb, offset);
if (qqi >= 128){
qqi = ((qqi & 0x0f) | 0x10) << (((qqi & 0x70) >> 4) + 3);
}
proto_tree_add_uint(icmp6_tree, hf_icmpv6_mld_qqi, tvb, offset, 1, qqi);
offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_mld_nb_sources, tvb, offset, 2, ENC_BIG_ENDIAN);
nb_sources = tvb_get_ntohs(tvb, offset);
offset += 2;
for (i=0; i < nb_sources; i++){
proto_tree_add_item(icmp6_tree, hf_icmpv6_mld_source_address, tvb, offset, 16, ENC_NA);
offset += 16;
}
}else{
proto_tree_add_item(icmp6_tree, hf_icmpv6_mld_mrd, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_mld_multicast_address, tvb, offset, 16, ENC_NA);
offset += 16;
}
break;
}
case ICMP6_ND_ROUTER_SOLICIT:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_ND_ROUTER_ADVERT:
{
static const int * nd_ra_flags[] = {
&hf_icmpv6_nd_ra_flag_m,
&hf_icmpv6_nd_ra_flag_o,
&hf_icmpv6_nd_ra_flag_h,
&hf_icmpv6_nd_ra_flag_prf,
&hf_icmpv6_nd_ra_flag_p,
&hf_icmpv6_nd_ra_flag_rsv,
NULL
};
proto_tree_add_item(icmp6_tree, hf_icmpv6_nd_ra_cur_hop_limit, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(icmp6_tree, tvb, offset, hf_icmpv6_nd_ra_flag, ett_icmpv6_flag_ra, nd_ra_flags, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_nd_ra_router_lifetime, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_nd_ra_reachable_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(icmp6_tree, hf_icmpv6_nd_ra_retrans_timer, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_ND_NEIGHBOR_SOLICIT:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(icmp6_tree, hf_icmpv6_nd_ns_target_address, tvb, offset, 16, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " for %s", tvb_ip6_to_str(tvb, offset));
offset += 16;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_ND_NEIGHBOR_ADVERT:
{
guint32 na_flags;
wmem_strbuf_t *flags_strbuf = wmem_strbuf_new_label(wmem_packet_scope());
static const int * nd_na_flags[] = {
&hf_icmpv6_nd_na_flag_r,
&hf_icmpv6_nd_na_flag_s,
&hf_icmpv6_nd_na_flag_o,
&hf_icmpv6_nd_na_flag_rsv,
NULL
};
proto_tree_add_bitmask(icmp6_tree, tvb, offset, hf_icmpv6_nd_na_flag, ett_icmpv6_flag_na, nd_na_flags, ENC_BIG_ENDIAN);
na_flags = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(icmp6_tree, hf_icmpv6_nd_na_target_address, tvb, offset, 16, ENC_NA);
if (na_flags & ND_NA_FLAG_R) {
wmem_strbuf_append(flags_strbuf, "rtr, ");
}
if (na_flags & ND_NA_FLAG_S) {
wmem_strbuf_append(flags_strbuf, "sol, ");
}
if (na_flags & ND_NA_FLAG_O) {
wmem_strbuf_append(flags_strbuf, "ovr, ");
}
if (wmem_strbuf_get_len(flags_strbuf) > 2) {
wmem_strbuf_truncate(flags_strbuf, wmem_strbuf_get_len(flags_strbuf) - 2);
} else {
wmem_strbuf_truncate(flags_strbuf, 0);
wmem_strbuf_append(flags_strbuf, "none");
}
col_append_fstr(pinfo->cinfo, COL_INFO, " %s (%s)", tvb_ip6_to_str(tvb, offset), wmem_strbuf_get_str(flags_strbuf));
offset += 16;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_ND_REDIRECT:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(icmp6_tree, hf_icmpv6_nd_rd_target_address, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(icmp6_tree, hf_icmpv6_nd_rd_destination_address, tvb, offset, 16, ENC_NA);
offset += 16;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_ROUTER_RENUMBERING:
{
offset = dissect_rrenum(tvb, offset, pinfo, icmp6_tree, icmp6_type, icmp6_code);
break;
}
case ICMP6_NI_QUERY:
case ICMP6_NI_REPLY:
{
offset = dissect_nodeinfo(tvb, offset, pinfo, icmp6_tree, icmp6_type, icmp6_code);
break;
}
case ICMP6_IND_SOLICIT:
case ICMP6_IND_ADVERT:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 4, ENC_NA);
offset += 4;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_MLDV2_REPORT:
{
offset = dissect_mldrv2( tvb, offset, pinfo, icmp6_tree );
break;
}
case ICMP6_MIP6_DHAAD_REQUEST:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_mip6_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
break;
}
case ICMP6_MIP6_DHAAD_REPLY:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_mip6_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
while((int)length > offset)
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_mip6_home_agent_address, tvb, offset, 16, ENC_NA);
offset += 16;
}
break;
}
case ICMP6_MIP6_MPS:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_mip6_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
break;
}
case ICMP6_MIP6_MPA:
{
static const int * mip6_flags[] = {
&hf_icmpv6_mip6_flag_m,
&hf_icmpv6_mip6_flag_o,
&hf_icmpv6_mip6_flag_rsv,
NULL
};
proto_tree_add_item(icmp6_tree, hf_icmpv6_mip6_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(icmp6_tree, tvb, offset, hf_icmpv6_mip6_flag, ett_icmpv6_flag_mip6, mip6_flags, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_CERT_PATH_SOL:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_send_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_send_component, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_CERT_PATH_AD:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_send_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_send_all_components, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_send_component, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_EXPERIMENTAL_MOBILITY:
case ICMP6_FMIPV6_MESSAGES:
{
guint8 subtype;
proto_tree_add_item(icmp6_tree, hf_icmpv6_fmip6_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
subtype = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " (%s)", val_to_str(subtype, fmip6_subtype_val, "Unknown (%d)"));
offset += 1;
switch(subtype){
case FMIP6_SUBTYPE_RTSOLPR:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 1, ENC_NA);
}
break;
case FMIP6_SUBTYPE_PRRTADV:
{
proto_item_append_text(code_item, " (%s)", val_to_str(icmp6_code, fmip6_prrtadv_code_val, "Unknown %d") );
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 1, ENC_NA);
}
break;
case FMIP6_SUBTYPE_HI:
{
static const int * fmip6_hi_flags[] = {
&hf_icmpv6_fmip6_hi_flag_s,
&hf_icmpv6_fmip6_hi_flag_u,
&hf_icmpv6_fmip6_hi_flag_reserved,
NULL
};
proto_item_append_text(code_item, " (%s)", val_to_str(icmp6_code, fmip6_hi_code_val, "Unknown %d") );
proto_tree_add_bitmask(icmp6_tree, tvb, offset, hf_icmpv6_fmip6_hi_flag, ett_icmpv6_flag_fmip6, fmip6_hi_flags, ENC_BIG_ENDIAN);
}
break;
case FMIP6_SUBTYPE_HACK:
{
proto_item_append_text(code_item, " (%s)", val_to_str(icmp6_code, fmip6_hack_code_val, "Unknown %d") );
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 1, ENC_NA);
}
break;
}
offset +=1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_fmip6_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = dissect_icmpv6_nd_opt(tvb, offset, pinfo, icmp6_tree);
break;
}
case ICMP6_MCAST_ROUTER_ADVERT:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_mcast_ra_query_interval, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_mcast_ra_robustness_variable, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
case ICMP6_MCAST_ROUTER_SOLICIT:
case ICMP6_MCAST_ROUTER_TERM:
{
break;
}
case ICMP6_RPL_CONTROL:
{
offset = dissect_rpl_control(tvb, offset, pinfo, icmp6_tree, icmp6_type, icmp6_code);
break;
}
case ICMP6_ILNPV6:
{
guint8 nb_locs, i;
proto_tree_add_item(icmp6_tree, hf_icmpv6_ilnp_nb_locs, tvb, offset, 1, ENC_BIG_ENDIAN);
nb_locs = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_reserved, tvb, offset, 2, ENC_NA);
offset += 2;
for (i=0; i < nb_locs; i++){
proto_tree_add_item(icmp6_tree, hf_icmpv6_ilnp_locator, tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(icmp6_tree, hf_icmpv6_ilnp_preference, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_ilnp_lifetime, tvb, offset, 2, ENC_NA);
offset += 2;
}
break;
}
case ICMP6_6LOWPANND_DAR:
case ICMP6_6LOWPANND_DAC:
{
proto_tree_add_item(icmp6_tree, hf_icmpv6_da_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_da_rsv, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(icmp6_tree, hf_icmpv6_da_lifetime, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(icmp6_tree, hf_icmpv6_da_eui64, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(icmp6_tree, hf_icmpv6_da_raddr, tvb, offset, 16, ENC_NA);
offset += 16;
break;
}
case ICMP6_MPL_CONTROL:
{
offset = dissect_mpl_control(tvb, offset, pinfo, icmp6_tree, icmp6_type, icmp6_code);
break;
}
default:
expert_add_info_format(pinfo, ti, &ei_icmpv6_undecoded_type,
"Dissector for ICMPv6 Type (%d)"
" code not implemented, Contact Wireshark"
" developers if you want this supported", icmp6_type);
proto_tree_add_item(icmp6_tree, hf_icmpv6_data, tvb, offset, -1, ENC_NA);
break;
}
}
if (!PINFO_FD_VISITED(pinfo)) {
icmp_info_t *p_icmp_info = wmem_new(wmem_file_scope(), icmp_info_t);
p_icmp_info->type = icmp6_type;
p_icmp_info->code = icmp6_code;
p_add_proto_data(wmem_file_scope(), pinfo, proto_icmpv6, 0, p_icmp_info);
}
if (trans)
tap_queue_packet(icmpv6_tap, pinfo, trans);
return offset;
}
void
proto_register_icmpv6(void)
{
static hf_register_info hf[] = {
{ &hf_icmpv6_type,
{ "Type", "icmpv6.type", FT_UINT8, BASE_DEC, VALS(icmpv6_type_val), 0x0,
"Indicates the type of the message", HFILL }},
{ &hf_icmpv6_code,
{ "Code", "icmpv6.code", FT_UINT8, BASE_DEC, NULL, 0x0,
"Depends on the message type. It is used to create an additional level of message granularity", HFILL }},
{ &hf_icmpv6_checksum,
{ "Checksum", "icmpv6.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
"Used to detect data corruption in the ICMPv6 message and parts of the IPv6 header", HFILL }},
{ &hf_icmpv6_checksum_status,
{ "Checksum Status", "icmpv6.checksum.status", FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0x0,
NULL, HFILL }},
{ &hf_icmpv6_reserved,
{ "Reserved", "icmpv6.reserved", FT_BYTES, BASE_NONE, NULL, 0x0,
"Must be Zero", HFILL }},
{ &hf_icmpv6_data,
{ "Data", "icmpv6.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_unknown_data,
{ "Unknown Data", "icmpv6.unknown_data", FT_BYTES, BASE_NONE, NULL, 0x0,
"Not interpreted Data", HFILL }},
{ &hf_icmpv6_mtu,
{ "MTU", "icmpv6.mtu", FT_UINT32, BASE_DEC, NULL, 0x0,
"The Maximum Transmission Unit of the next-hop link", HFILL }},
{ &hf_icmpv6_pointer,
{ "Pointer", "icmpv6.pointer", FT_UINT32, BASE_DEC, NULL, 0x0,
"Identifies the octet offset within the invoking packet where the error was detected", HFILL }},
{ &hf_icmpv6_echo_identifier,
{ "Identifier", "icmpv6.echo.identifier", FT_UINT16, BASE_HEX, NULL, 0x0,
"An identifier to aid in matching with Request and Reply", HFILL }},
{ &hf_icmpv6_echo_sequence_number,
{ "Sequence", "icmpv6.echo.sequence_number", FT_UINT16, BASE_DEC, NULL, 0x0,
"A sequence number to aid in matching Echo Replies to this Echo Request", HFILL }},
{ &hf_icmpv6_nonce,
{ "Nonce", "icmpv6.nonce", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_nd_ra_cur_hop_limit,
{ "Cur hop limit", "icmpv6.nd.ra.cur_hop_limit", FT_UINT8, BASE_DEC, NULL, 0x0,
"The default value that should be placed in the Hop Count field of the IP header for outgoing IP packets", HFILL }},
{ &hf_icmpv6_nd_ra_flag,
{ "Flags", "icmpv6.nd.ra.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_nd_ra_flag_m,
{ "Managed address configuration", "icmpv6.nd.ra.flag.m", FT_BOOLEAN, 8, TFS(&tfs_set_notset), ND_RA_FLAG_M,
"When set, it indicates that addresses are available via DHCPv6", HFILL }},
{ &hf_icmpv6_nd_ra_flag_o,
{ "Other configuration", "icmpv6.nd.ra.flag.o", FT_BOOLEAN, 8, TFS(&tfs_set_notset), ND_RA_FLAG_O,
"When set, it indicates that other configuration information is available via DHCPv6", HFILL }},
{ &hf_icmpv6_nd_ra_flag_h,
{ "Home Agent", "icmpv6.nd.ra.flag.h", FT_BOOLEAN, 8, TFS(&tfs_set_notset), ND_RA_FLAG_H,
"When set, it indicate that the router sending this Router Advertisement is also functioning as a Mobile IPv6 home agent on this link", HFILL }},
{ &hf_icmpv6_nd_ra_flag_prf,
{ "Prf (Default Router Preference)", "icmpv6.nd.ra.flag.prf", FT_UINT8, BASE_DEC, VALS(nd_flag_router_pref), ND_RA_FLAG_PRF,
"Indicates whether to prefer this router over other default routers", HFILL }},
{ &hf_icmpv6_nd_ra_flag_p,
{ "Proxy", "icmpv6.nd.ra.flag.p", FT_BOOLEAN, 8, TFS(&tfs_set_notset), ND_RA_FLAG_P,
NULL, HFILL }},
{ &hf_icmpv6_nd_ra_flag_rsv,
{ "Reserved", "icmpv6.nd.ra.flag.rsv", FT_UINT8, BASE_DEC, NULL, ND_RA_FLAG_RSV,
"Must be Zero", HFILL }},
{ &hf_icmpv6_nd_ra_router_lifetime,
{ "Router lifetime (s)", "icmpv6.nd.ra.router_lifetime", FT_UINT16, BASE_DEC, NULL, 0x0,
"The lifetime associated with the default router", HFILL }},
{ &hf_icmpv6_nd_ra_reachable_time,
{ "Reachable time (ms)", "icmpv6.nd.ra.reachable_time", FT_UINT32, BASE_DEC, NULL, 0x0,
"The time that a node assumes a neighbor is reachable after having received a reachability confirmation", HFILL }},
{ &hf_icmpv6_nd_ra_retrans_timer,
{ "Retrans timer (ms)", "icmpv6.nd.ra.retrans_timer", FT_UINT32, BASE_DEC, NULL, 0x0,
"The time between retransmitted Neighbor Solicitation messages", HFILL }},
{ &hf_icmpv6_nd_ns_target_address,
{ "Target Address", "icmpv6.nd.ns.target_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"The IP address of the target of the solicitation", HFILL }},
{ &hf_icmpv6_nd_na_flag,
{ "Flags", "icmpv6.nd.na.flag", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_nd_na_flag_r,
{ "Router", "icmpv6.nd.na.flag.r", FT_BOOLEAN, 32, TFS(&tfs_set_notset), ND_NA_FLAG_R,
"When set, it indicates that the sender is a router", HFILL }},
{ &hf_icmpv6_nd_na_flag_s,
{ "Solicited", "icmpv6.nd.na.flag.s", FT_BOOLEAN, 32, TFS(&tfs_set_notset), ND_NA_FLAG_S,
"When set, it indicates that the advertisement was sent in response to a Neighbor Solicitation from the Destination address", HFILL }},
{ &hf_icmpv6_nd_na_flag_o,
{ "Override", "icmpv6.nd.na.flag.o", FT_BOOLEAN, 32, TFS(&tfs_set_notset), ND_NA_FLAG_O,
"When set, it indicates that the advertisement should override an existing cache entry and update the cached link-layer address", HFILL }},
{ &hf_icmpv6_nd_na_flag_rsv,
{ "Reserved", "icmpv6.nd.na.flag.rsv", FT_UINT32, BASE_DEC, NULL, ND_NA_FLAG_RSV,
"Must be Zero", HFILL }},
{ &hf_icmpv6_nd_na_target_address,
{ "Target Address", "icmpv6.nd.na.target_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"the Target Address field in the Neighbor Solicitation message that prompted this advertisement", HFILL }},
{ &hf_icmpv6_nd_rd_target_address,
{ "Target Address", "icmpv6.nd.rd.target_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"An IP address that is a better first hop to use for the ICMP Destination Address", HFILL }},
{ &hf_icmpv6_nd_rd_destination_address,
{ "Destination Address", "icmpv6.rd.na.destination_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"The IP address of the destination that is redirected to the target", HFILL }},
{ &hf_icmpv6_opt,
{ "ICMPv6 Option", "icmpv6.opt", FT_NONE, BASE_NONE, NULL, 0x0,
"Option", HFILL }},
{ &hf_icmpv6_opt_type,
{ "Type", "icmpv6.opt.type", FT_UINT8, BASE_DEC, VALS(option_vals), 0x0,
"Options type", HFILL }},
{ &hf_icmpv6_opt_length,
{ "Length", "icmpv6.opt.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The length (in units of 8 bytes) of the option (including the Type and Length fields)", HFILL }},
{ &hf_icmpv6_opt_reserved,
{ "Reserved", "icmpv6.opt.reserved", FT_NONE, BASE_NONE, NULL, 0x0,
"Reserved (Must be 0)", HFILL }},
{ &hf_icmpv6_opt_padding,
{ "Padding", "icmpv6.opt.padding", FT_NONE, BASE_NONE, NULL, 0x0,
"Padding (Must be 0)", HFILL }},
{ &hf_icmpv6_opt_linkaddr,
{ "Link-layer address", "icmpv6.opt.linkaddr", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_src_linkaddr,
{ "Source Link-layer address", "icmpv6.opt.src_linkaddr", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_target_linkaddr,
{ "Target Link-layer address", "icmpv6.opt.target_linkaddr", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_linkaddr_mac,
{ "Link-layer address", "icmpv6.opt.linkaddr", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_src_linkaddr_mac,
{ "Source Link-layer address", "icmpv6.opt.src_linkaddr", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_target_linkaddr_mac,
{ "Target Link-layer address", "icmpv6.opt.target_linkaddr", FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_linkaddr_eui64,
{ "Link-layer address", "icmpv6.opt.linkaddr_eui64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_src_linkaddr_eui64,
{ "Source Link-layer address", "icmpv6.opt.src_linkaddr_eui64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_target_linkaddr_eui64,
{ "Target Link-layer address", "icmpv6.opt.target_linkaddr_eui64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_prefix_len,
{ "Prefix Length", "icmpv6.opt.prefix.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of leading bits in the Prefix that are valid", HFILL }},
{ &hf_icmpv6_opt_prefix_flag,
{ "Flag", "icmpv6.opt.prefix.flag", FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_prefix_flag_l,
{ "On-link flag(L)", "icmpv6.opt.prefix.flag.l", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80,
"When set, indicates that this prefix can be used for on-link determination", HFILL }},
{ &hf_icmpv6_opt_prefix_flag_a,
{ "Autonomous address-configuration flag(A)", "icmpv6.opt.prefix.flag.a", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40,
"When set indicates that this prefix can be used for stateless address configuration", HFILL }},
{ &hf_icmpv6_opt_prefix_flag_r,
{ "Router address flag(R)", "icmpv6.opt.prefix.flag.r", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x20,
"When set indicates that the Prefix field contains a complete IP address assigned to the sending router", HFILL }},
{ &hf_icmpv6_opt_prefix_flag_reserved,
{ "Reserved", "icmpv6.opt.prefix.flag.reserved", FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }},
{ &hf_icmpv6_opt_prefix_valid_lifetime,
{ "Valid Lifetime", "icmpv6.opt.prefix.valid_lifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_infinity), 0x00,
"The length of time in seconds that the prefix is valid for the purpose of on-link determination", HFILL }},
{ &hf_icmpv6_opt_prefix_preferred_lifetime,
{ "Preferred Lifetime", "icmpv6.opt.prefix.preferred_lifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_infinity), 0x00,
"The length of time in seconds that addresses generated from the prefix via stateless address autoconfiguration remain preferred", HFILL }},
{ &hf_icmpv6_opt_prefix,
{ "Prefix", "icmpv6.opt.prefix", FT_IPv6, BASE_NONE, NULL, 0x00,
"An IP address or a prefix of an IP address", HFILL }},
{ &hf_icmpv6_opt_cga_pad_len,
{ "Pad Length", "icmpv6.opt.cga.pad_length", FT_UINT8, BASE_DEC, NULL, 0x0,
"Pad Length (in bytes)", HFILL }},
{ &hf_icmpv6_opt_cga,
{ "CGA", "icmpv6.opt.cga", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_cga_modifier,
{ "Modifier", "icmpv6.opt.cga.modifier", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_cga_subnet_prefix,
{ "Subnet Prefix", "icmpv6.opt.cga.subnet_prefix", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_cga_count,
{ "Count", "icmpv6.opt.cga.count", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_cga_ext_type,
{ "Ext Type", "icmpv6.opt.cga.ext_type", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_cga_ext_length,
{ "Ext Length", "icmpv6.opt.cga.ext_length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_cga_ext_data,
{ "Ext Data", "icmpv6.opt.cga.ext_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_rsa_key_hash,
{ "Key Hash", "icmpv6.opt.rsa.key_hash", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_digital_signature_padding,
{ "Digital Signature and Padding", "icmpv6.opt.digital_signature_padding", FT_NONE, BASE_NONE, NULL, 0x0,
"TO DO FIX ME !!", HFILL }},
{ &hf_icmpv6_opt_ps_key_hash,
{ "Key Hash", "icmpv6.opt.ps.key_hash", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_timestamp,
{ "Timestamp", "icmpv6.opt.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"The value indicates the number of seconds since January 1, 1970, 00:00 UTC", HFILL }},
{ &hf_icmpv6_opt_nonce,
{ "Nonce", "icmpv6.opt.nonce", FT_BYTES, BASE_NONE, NULL, 0x0,
"A field containing a random number selected by the sender of the solicitation message", HFILL }},
{ &hf_icmpv6_opt_certificate_padding,
{ "Certificate and Padding", "icmpv6.opt.certificate_padding", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_ipa_option_code,
{ "Option-code", "icmpv6.opt.ipa.option_code", FT_UINT8, BASE_DEC, VALS(nd_opt_ipa_option_code_val), 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_ipa_prefix_len,
{ "Prefix Length", "icmpv6.opt.ipa.prefix_len", FT_UINT8, BASE_DEC, NULL, 0x00,
"That indicates the length of the IPv6 Address Prefix", HFILL }},
{ &hf_icmpv6_opt_ipa_ipv6_address,
{ "IPv6 Address", "icmpv6.opt.ipa.ipv6_address", FT_IPv6, BASE_NONE, NULL, 0x00,
"The IP address/prefix defined by the Option-Code field", HFILL }},
{ &hf_icmpv6_opt_nrpi_option_code,
{ "Option-code", "icmpv6.opt.nrpi.option_code", FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_nrpi_prefix_len,
{ "Prefix Length", "icmpv6.opt.nrpi.prefix_len", FT_UINT8, BASE_DEC, NULL, 0x00,
"The number of leading bits in the Prefix that are valid", HFILL }},
{ &hf_icmpv6_opt_nrpi_prefix,
{ "Prefix", "icmpv6.opt.nrpi.prefix", FT_IPv6, BASE_NONE, NULL, 0x00,
"An IP address or a prefix of an IP address", HFILL }},
{ &hf_icmpv6_opt_lla_option_code,
{ "Option-code", "icmpv6.opt.lla.option_code", FT_UINT8, BASE_DEC, VALS(nd_opt_lla_option_code_val), 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_lla_bytes,
{ "Link-Layer Address", "icmpv6.opt.lla.bytes", FT_BYTES, BASE_NONE, NULL, 0x00,
"(in Bytes Format)", HFILL }},
{ &hf_icmpv6_opt_naack_option_code,
{ "Option-Code", "icmpv6.opt.naack.option_code", FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_naack_status,
{ "Status", "icmpv6.opt.naack.status", FT_UINT8, BASE_DEC, VALS(nd_opt_naack_status_val), 0x00,
"Indicating the disposition of the Unsolicited Neighbor Advertisement message", HFILL }},
{ &hf_icmpv6_opt_naack_supplied_ncoa,
{ "Supplied NCoA", "icmpv6.opt.naack.supplied_ncoa", FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_map_dist,
{ "Distance", "icmpv6.opt.map.distance", FT_UINT8, BASE_DEC, NULL, 0xF0,
"Identifying the distance between MAP and the receiver of the advertisement (in the number of hops)", HFILL }},
{ &hf_icmpv6_opt_map_pref,
{ "Preference", "icmpv6.opt.map.preference", FT_UINT8, BASE_DEC, NULL, 0x0F,
"Used as an indicator of operator preference (Highest is better)", HFILL }},
{ &hf_icmpv6_opt_map_flag,
{ "Flag", "icmpv6.opt.map.flag", FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_map_flag_r,
{ "RCoA Flag", "icmpv6.opt.map.flag.r", FT_BOOLEAN, 8, NULL, 0x80,
"It indicates that the mobile node is allocated the RCoA by the MAP", HFILL }},
{ &hf_icmpv6_opt_map_flag_reserved,
{ "Reserved", "icmpv6.opt.map.flag.reserved", FT_UINT8, BASE_DEC, NULL, 0x7F,
"Must be 0", HFILL }},
{ &hf_icmpv6_opt_map_valid_lifetime,
{ "Valid Lifetime", "icmpv6.opt.map.valid_lifetime", FT_UINT32, BASE_DEC, NULL, 0x0,
"This value indicates the validity of the MAP's address and the RCoA.", HFILL }},
{ &hf_icmpv6_opt_map_global_address,
{ "Global Address", "icmpv6.opt.map.global_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"One of the MAP's global addresses", HFILL }},
{ &hf_icmpv6_opt_route_info_flag,
{ "Flag", "icmpv6.opt.route_info.flag", FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_route_info_flag_route_preference,
{ "Route Preference", "icmpv6.opt.route_info.flag.route_preference", FT_UINT8, BASE_DEC, VALS(nd_flag_router_pref), ND_RA_FLAG_RTPREF_MASK,
"The Route Preference indicates whether to prefer the router associated with this prefix over others", HFILL }},
{ &hf_icmpv6_opt_route_info_flag_reserved,
{ "Reserved", "icmpv6.opt.route_info.flag.reserved", FT_UINT8, BASE_DEC, NULL, ND_RA_FLAG_RESERV_MASK,
"Must be 0", HFILL }},
{ &hf_icmpv6_opt_route_lifetime,
{ "Route Lifetime", "icmpv6.opt.route_lifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_infinity), 0x00,
"The length of time in seconds that the prefix is valid for the purpose of route determination", HFILL }},
{ &hf_icmpv6_opt_name_type,
{ "Name Type", "icmpv6.opt.name_type", FT_UINT8, BASE_DEC, VALS(icmpv6_option_name_type_vals), 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_name_x501,
{ "DER Encoded X.501 Name", "icmpv6.opt.name_x501", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_name_fqdn,
{ "FQDN", "icmpv6.opt.name_type.fqdn", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_cert_type,
{ "Cert Type", "icmpv6.opt.name_type", FT_UINT8, BASE_DEC, VALS(icmpv6_option_cert_type_vals), 0x0,
NULL, HFILL }},
{ &hf_icmpv6_send_identifier,
{ "Identifier", "icmpv6.send.identifier", FT_UINT16, BASE_DEC, NULL, 0x0,
"An identifier to aid in matching with Request and Reply", HFILL }},
{ &hf_icmpv6_send_all_components,
{ "All Components", "icmpv6.send.all_components", FT_UINT16, BASE_DEC, NULL, 0x0,
"Inform the receiver of the number of certificates in the entire path", HFILL }},
{ &hf_icmpv6_send_component,
{ "Component", "icmpv6.send.component", FT_UINT16, BASE_DEC, NULL, 0x0,
"If the field is set to 65,535 if the sender seeks to retrieve all certificates", HFILL }},
{ &hf_icmpv6_x509if_Name,
{ "Name", "icmpv6.x509_Name", FT_UINT32, BASE_DEC, VALS(x509if_Name_vals), 0x0,
NULL, HFILL }},
{ &hf_icmpv6_x509af_Certificate,
{ "Certificate", "icmpv6.x509_Certificate", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_redirected_packet,
{ "Redirected Packet", "icmpv6.opt.redirected_packet", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_mtu,
{ "MTU", "icmpv6.opt.mtu", FT_UINT32, BASE_DEC, NULL, 0x0,
"The recommended MTU for the link", HFILL }},
{ &hf_icmpv6_opt_nbma_shortcut_limit,
{ "Shortcut Limit", "icmpv6.opt.nbma.shortcut_limit", FT_UINT8, BASE_DEC, NULL, 0x0,
"Hop limit for shortcut attempt", HFILL }},
{ &hf_icmpv6_opt_advertisement_interval,
{ "Advertisement Interval", "icmpv6.opt.advertisement_interval", FT_UINT32, BASE_DEC, NULL, 0x0,
"The maximum time (in milliseconds) between successive unsolicited Router Advertisement messages sent by this router on this network interface", HFILL }},
{ &hf_icmpv6_opt_home_agent_preference,
{ "Home Agent Preference", "icmpv6.opt.home_agent_preference", FT_UINT16, BASE_DEC, NULL, 0x0,
"The preference for the home agent sending this Router Advertisement", HFILL }},
{ &hf_icmpv6_opt_home_agent_lifetime,
{ "Home Agent Preference", "icmpv6.opt.home_agent_lifetime", FT_UINT16, BASE_DEC, NULL, 0x0,
"The lifetime associated with the home agent in units of seconds.", HFILL }},
{ &hf_icmpv6_opt_ipv6_address,
{ "IPv6 Address", "icmpv6.opt.ipv6_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 addresses of the interface", HFILL }},
{ &hf_icmpv6_opt_rdnss_lifetime,
{ "Lifetime", "icmpv6.opt.rdnss.lifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(rdnss_infinity), 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_rdnss,
{ "Recursive DNS Servers", "icmpv6.opt.rdnss", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_efo,
{ "Flags Expansion Option", "icmpv6.opt.efo", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_efo_m,
{ "Managed address configuration", "icmpv6.opt.efo.m", FT_BOOLEAN, 16, TFS(&tfs_set_notset), FLAGS_EO_M,
"When set, it indicates that addresses are available via DHCPv6", HFILL }},
{ &hf_icmpv6_opt_efo_o,
{ "Other configuration", "icmpv6.opt.efo.o", FT_BOOLEAN, 16, TFS(&tfs_set_notset), FLAGS_EO_O,
"When set, it indicates that other configuration information is available via DHCPv6", HFILL }},
{ &hf_icmpv6_opt_efo_h,
{ "Home Agent", "icmpv6.opt.efo.h", FT_BOOLEAN, 16, TFS(&tfs_set_notset), FLAGS_EO_H,
"When set, it indicate that the router sending this Router Advertisement is also functioning as a Mobile IPv6 home agent on this link", HFILL }},
{ &hf_icmpv6_opt_efo_prf,
{ "Prf (Default Router Preference)", "icmpv6.opt.efo.prf", FT_UINT16, BASE_DEC, VALS(nd_flag_router_pref), FLAGS_EO_PRF,
"Indicates whether to prefer this router over other default routers", HFILL }},
{ &hf_icmpv6_opt_efo_p,
{ "Proxy", "icmpv6.opt.efo.p", FT_BOOLEAN, 16, TFS(&tfs_set_notset), FLAGS_EO_P,
NULL, HFILL }},
{ &hf_icmpv6_opt_efo_rsv,
{ "Reserved", "icmpv6.opt.efo.rsv", FT_UINT16, BASE_DEC, NULL, FLAGS_EO_RSV,
"Must be Zero", HFILL }},
{ &hf_icmpv6_opt_hkr_pad_length,
{ "Pad Length", "icmpv6.opt.hkr.pad_length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of padding octets beyond the end of the Handover Key", HFILL }},
{ &hf_icmpv6_opt_hkr_at,
{ "AT", "icmpv6.opt.hkr.at", FT_UINT8, BASE_DEC, NULL, 0xF0,
"The algorithm type field describing the algorithm used by FMIPv6 to calculate the authenticator", HFILL }},
{ &hf_icmpv6_opt_hkr_reserved,
{ "Reserved", "icmpv6.opt.hkr.reserved", FT_UINT8, BASE_DEC, NULL, 0x0F,
"Reserved (Must be Zero)", HFILL }},
{ &hf_icmpv6_opt_hkr_encryption_public_key,
{ "Handover Key Encryption Public Key", "icmpv6.opt.hkr.encryption_public_key", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_hkr_padding,
{ "Padding", "icmpv6.opt.hkr.padding", FT_BYTES, BASE_NONE, NULL, 0x0,
"A variable-length field making the option length a multiple of 8", HFILL }},
{ &hf_icmpv6_opt_hkr_lifetime,
{ "Padding", "icmpv6.opt.hkr.lifetime", FT_UINT16, BASE_DEC, NULL, 0x0,
"Lifetime of the handover key (in seconds)", HFILL }},
{ &hf_icmpv6_opt_hkr_encrypted_handover_key,
{ "Encrypted Handover Key", "icmpv6.opt.hkr.encrypted_handover_key", FT_BYTES, BASE_NONE, NULL, 0x0,
"The shared handover key, encrypted with the MN's handover key encryption public key", HFILL }},
{ &hf_icmpv6_opt_hai_option_code,
{ "Option-Code", "icmpv6.opt.hai.option_code", FT_UINT8, BASE_DEC, VALS(nd_opt_hai_option_code_val), 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_hai_length,
{ "HAI-Length", "icmpv6.opt.hai.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The size of the HAI-Value field in octets", HFILL }},
{ &hf_icmpv6_opt_hai_value,
{ "HAI-Value", "icmpv6.opt.hai.value", FT_BYTES, BASE_NONE, NULL, 0x0,
"The value specified by the Option-Code", HFILL }},
{ &hf_icmpv6_opt_mn_option_code,
{ "Option-Code", "icmpv6.opt.mn.option_code", FT_UINT8, BASE_DEC, VALS(nd_opt_mn_option_code_val), 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_mn_length,
{ "MN-Length", "icmpv6.opt.mn.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The size of the MN-Value field in octets", HFILL }},
{ &hf_icmpv6_opt_mn_value,
{ "MN-Value", "icmpv6.opt.mn.value", FT_BYTES, BASE_NONE, NULL, 0x0,
"The value specified by the Option-Code", HFILL }},
{ &hf_icmpv6_opt_dnssl_lifetime,
{ "Lifetime", "icmpv6.opt.dnssl.lifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(dnssl_infinity), 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_dnssl,
{ "Domain Names", "icmpv6.opt.dnssl", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_opt_aro_status,
{ "Status", "icmpv6.opt.aro.status", FT_UINT8, BASE_DEC, VALS(nd_opt_6lowpannd_status_val), 0x00,
"Indicates the status of a registration in the NA response", HFILL }},
{ &hf_icmpv6_opt_aro_registration_lifetime,
{ "Registration Lifetime", "icmpv6.opt.aro.registration_lifetime", FT_UINT16, BASE_DEC, NULL, 0x00,
"The amount of time (in a unit of 60 seconds) that the router should retain the Neighbor Cache entry", HFILL }},
{ &hf_icmpv6_opt_aro_eui64,
{ "EUI-64", "icmpv6.opt.aro.eui64", FT_EUI64, BASE_NONE, NULL, 0x00,
"This field is used to uniquely identify the interface of the registered address", HFILL }},
{ &hf_icmpv6_opt_6co_context_length,
{ "Context Length", "icmpv6.opt.6co.context_length", FT_UINT8, BASE_DEC, NULL, 0x00,
"The number of leading bits in the Context Prefix field that are valid", HFILL }},
{ &hf_icmpv6_opt_6co_flag,
{ "Flag", "icmpv6.opt.6co.flag", FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_opt_6co_flag_c,
{ "Compression Flag", "icmpv6.opt.6co.flag.c", FT_BOOLEAN, 8, TFS(&tfs_set_notset), ND_OPT_6CO_FLAG_C,
"This flag indicates if the context is valid for use in compression", HFILL }},
{ &hf_icmpv6_opt_6co_flag_cid,
{ "CID", "icmpv6.opt.6co.flag.cid", FT_UINT8, BASE_DEC, NULL, ND_OPT_6CO_FLAG_CID,
"Context Identifier for this prefix information", HFILL }},
{ &hf_icmpv6_opt_6co_flag_reserved,
{ "Reserved", "icmpv6.opt.6co.flag.reserved", FT_UINT8, BASE_DEC, NULL, ND_OPT_6CO_FLAG_RESERVED,
"Must be zero", HFILL }},
{ &hf_icmpv6_opt_6co_valid_lifetime,
{ "Lifetime", "icmpv6.opt.6co.valid_lifetime", FT_UINT16, BASE_DEC, NULL, 0x00,
"The length of time in a unit of 60 seconds that the context is valid for the purpose of header compression or decompression", HFILL }},
{ &hf_icmpv6_opt_6co_context_prefix,
{ "Context Prefix", "icmpv6.opt.6co.context_prefix", FT_IPv6, BASE_NONE, NULL, 0x00,
"The IPv6 prefix or address corresponding to the Context ID (CID) field", HFILL }},
{ &hf_icmpv6_opt_abro_version_low,
{ "Version Low", "icmpv6.opt.abro.version_low", FT_UINT16, BASE_DEC, NULL, 0x00,
"The version number low (the least significant 16 bits) corresponding to this set of information contained in the RA message", HFILL }},
{ &hf_icmpv6_opt_abro_version_high,
{ "Version", "icmpv6.opt.abro.version_high", FT_UINT16, BASE_DEC, NULL, 0x00,
"The version number high (most significant 16 bits) corresponding to this set of information contained in the RA message", HFILL }},
{ &hf_icmpv6_opt_abro_valid_lifetime,
{ "Valid Lifetime", "icmpv6.opt.abro.valid_lifetime", FT_UINT16, BASE_DEC, NULL, 0x00,
"The length of time in a unit of 60 seconds (relative to the time the packet is received) that this set of border router information is valid.", HFILL }},
{ &hf_icmpv6_opt_abro_6lbr_address,
{ "6LBR Address", "icmpv6.opt.abro.6lbr_address", FT_IPv6, BASE_NONE, NULL, 0x00,
"IPv6 address of the 6LBR that is the origin of the included version number", HFILL }},
{ &hf_icmpv6_opt_6cio_unassigned1,
{ "Unassigned", "icmpv6.opt.6cio.unassigned1", FT_UINT16, BASE_HEX, NULL, ND_OPT_6CIO_FLAG_UNASSIGNED,
NULL, HFILL }},
{ &hf_icmpv6_opt_6cio_flag_g,
{ "G", "icmpv6.opt.6cio.flag_g", FT_UINT16, BASE_HEX, NULL, ND_OPT_6CIO_FLAG_G,
NULL, HFILL }},
{ &hf_icmpv6_opt_6cio_unassigned2,
{ "Unassigned", "icmpv6.opt.6cio.unassigned2", FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_mld_mrd,
{ "Maximum Response Delay [ms]", "icmpv6.mld.maximum_response_delay", FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the maximum allowed delay before sending a responding Report, in units of milliseconds", HFILL }},
{ &hf_icmpv6_mld_multicast_address,
{ "Multicast Address", "icmpv6.mld.multicast_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"Specific IPv6 multicast address", HFILL }},
{ &hf_icmpv6_rr_sequencenumber,
{ "Sequence Number", "icmpv6.rr.sequence_number", FT_UINT32, BASE_DEC, NULL, 0x0,
"The sequence number MUST be non-decreasing between Sequence Number Resets", HFILL }},
{ &hf_icmpv6_rr_segmentnumber,
{ "Segment Number", "icmpv6.rr.segment_number", FT_UINT8, BASE_DEC, NULL, 0x0,
"Enumerates different valid RR messages having the same Sequence Number", HFILL }},
{ &hf_icmpv6_rr_flag,
{ "Flags", "icmpv6.rr.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
"Five are defined and three bits are reserved", HFILL }},
{ &hf_icmpv6_rr_flag_t,
{ "Test Command", "icmpv6.rr.flag.t", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RR_FLAG_T,
"Indicates a Test message: processing is to be simulated and no configuration changes are to be made", HFILL }},
{ &hf_icmpv6_rr_flag_r,
{ "Result requested", "icmpv6.rr.flag.r", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RR_FLAG_R,
"Indicates that the router send a Result message upon completion of processing the Command message", HFILL }},
{ &hf_icmpv6_rr_flag_a,
{ "All Interfaces", "icmpv6.rr.flag.a", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RR_FLAG_A,
"Indicates that the Command be applied to all interfaces regardless of administrative shutdown status", HFILL }},
{ &hf_icmpv6_rr_flag_s,
{ "Site-specific", "icmpv6.rr.flag.s", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RR_FLAG_S,
"Indicates that the Command be applied only to interfaces which belong to the same site as the interface to which the Command is addressed", HFILL }},
{ &hf_icmpv6_rr_flag_p,
{ "Processed previously", "icmpv6.rr.flag.p", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RR_FLAG_P,
"Indicates that the Command message was previously processed (and is not a Test) and the responding router is not processing it again", HFILL }},
{ &hf_icmpv6_rr_flag_rsv,
{ "Reserved", "icmpv6.rr.flag.rsv", FT_UINT8, BASE_DEC, NULL, RR_FLAG_RSV,
"Must be Zero", HFILL }},
{ &hf_icmpv6_rr_maxdelay,
{ "Max Delay", "icmpv6.rr.maxdelay", FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifying the maximum time (in milliseconds) by which a router MUST delay sending any reply to this Command", HFILL }},
{ &hf_icmpv6_rr_pco_mp_part,
{ "Match-Prefix Part", "icmpv6.rr.pco.mp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rr_pco_mp_opcode,
{ "OpCode", "icmpv6.rr.pco.mp.opcode", FT_UINT8, BASE_DEC, VALS(rr_pco_mp_opcode_val), 0x0,
"Specifying the operation to be performed when the associated MatchPrefix matches an interface's prefix or address", HFILL }},
{ &hf_icmpv6_rr_pco_mp_oplength,
{ "OpLength", "icmpv6.rr.pco.mp.oplength", FT_UINT8, BASE_DEC, NULL, 0x0,
"The total length of this Prefix Control Operation (in units of 8 octets)", HFILL }},
{ &hf_icmpv6_rr_pco_mp_ordinal,
{ "Ordinal", "icmpv6.rr.pco.mp.ordinal", FT_UINT8, BASE_HEX, NULL, 0x0,
"The value is otherwise unconstrained", HFILL }},
{ &hf_icmpv6_rr_pco_mp_matchlen,
{ "MatchLen", "icmpv6.rr.pco.mp.matchlen", FT_UINT8, BASE_DEC, NULL, 0x0,
"Between 0 and 128 inclusive specifying the number of initial bits of MatchPrefix which are significant in matching", HFILL }},
{ &hf_icmpv6_rr_pco_mp_minlen,
{ "MinLen", "icmpv6.rr.pco.mp.minlen", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying the minimum length which any configured prefix must have in order to be eligible for testing against the MatchPrefix", HFILL }},
{ &hf_icmpv6_rr_pco_mp_maxlen,
{ "MaxLen", "icmpv6.rr.pco.mp.maxlen", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying the maximum length which any configured prefix must have in order to be eligible for testing against the MatchPrefix", HFILL }},
{ &hf_icmpv6_rr_pco_mp_matchprefix,
{ "MatchPrefix", "icmpv6.rr.pco.mp.matchprefix", FT_IPv6, BASE_NONE, NULL, 0x0,
"The 128-bit prefix to be compared with each interface's prefix or address", HFILL }},
{ &hf_icmpv6_rr_pco_up_part,
{ "Use-Prefix Part", "icmpv6.rr.pco.up", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rr_pco_up_uselen,
{ "UseLen", "icmpv6.rr.pco.up.uselen", FT_UINT8, BASE_DEC, NULL, 0x0,
"specifying the number of initial bits of UsePrefix to use in creating a new prefix for an interface", HFILL }},
{ &hf_icmpv6_rr_pco_up_keeplen,
{ "KeepLen", "icmpv6.rr.pco.up.keeplen", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifying the number of bits of the prefix or address which matched the associated Match-Prefix which should be retained in the new prefix", HFILL }},
{ &hf_icmpv6_rr_pco_up_flagmask,
{ "FlagMask", "icmpv6.rr.pco.up.flagmask", FT_UINT8, BASE_HEX, NULL, 0x0,
"A 1 bit in any position means that the corresponding flag bit in a Router Advertisement (RA) Prefix Information Option for the New Prefix should be set from the RAFlags field in this Use-Prefix Part", HFILL }},
{ &hf_icmpv6_rr_pco_up_flagmask_l,
{ "On-link flag(L)", "icmpv6.rr.pco.up.flagmask.l", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80,
"When set, indicates the On-link (L) flag bit in a Router Advertisement (RA) Prefix Information Option for the New Prefix should be set from the RAFlags field in this Use-Prefix Part", HFILL }},
{ &hf_icmpv6_rr_pco_up_flagmask_a,
{ "Autonomous address-configuration flag(A)", "icmpv6.rr.pco.up.flagmask.a", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40,
"When set, indicates the Autonomous address-configuration (A) flag bit in a Router Advertisement (RA) Prefix Information Option for the New Prefix should be set from the RAFlags field in this Use-Prefix Part", HFILL }},
{ &hf_icmpv6_rr_pco_up_flagmask_reserved,
{ "Reserved", "icmpv6.rr.pco.up.flagmask.reserved", FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }},
{ &hf_icmpv6_rr_pco_up_raflags,
{ "RAFlags", "icmpv6.rr.pco.up.raflags", FT_UINT8, BASE_HEX, NULL, 0x0,
"Under control of the FlagMask field, may be used to initialize the flags in Router Advertisement Prefix Information Options which advertise the New Prefix", HFILL }},
{ &hf_icmpv6_rr_pco_up_raflags_l,
{ "On-link flag(L)", "icmpv6.rr.pco.up.flagmask.l", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80,
"When set, indicates that this prefix can be used for on-link determination", HFILL }},
{ &hf_icmpv6_rr_pco_up_raflags_a,
{ "Autonomous address-configuration flag(A)", "icmpv6.rr.pco.up.flagmask.a", FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40,
"When set indicates that this prefix can be used for stateless address configuration", HFILL }},
{ &hf_icmpv6_rr_pco_up_raflags_reserved,
{ "Reserved", "icmpv6.rr.pco.up.flagmask.reserved", FT_UINT8, BASE_DEC, NULL, 0x3f,
NULL, HFILL }},
{ &hf_icmpv6_rr_pco_up_validlifetime,
{ "Valid Lifetime", "icmpv6.rr.pco.up.validlifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_infinity), 0x0,
"The number of seconds for which the New Prefix will be valid", HFILL }},
{ &hf_icmpv6_rr_pco_up_preferredlifetime,
{ "Preferred Lifetime", "icmpv6.rr.pco.up.preferredlifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_infinity), 0x0,
"The number of seconds for which the New Prefix will be preferred", HFILL }},
{ &hf_icmpv6_rr_pco_up_flag,
{ "Flags", "icmpv6.rr.pco.up.flag", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rr_pco_up_flag_v,
{ "Decrement valid lifetime", "icmpv6.rr.pco.up.flag.v", FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x80000000,
"When set, indicating that the valid lifetime of the New Prefix MUST be effectively decremented in real time", HFILL }},
{ &hf_icmpv6_rr_pco_up_flag_p,
{ "Decrement preferred lifetime", "icmpv6.rr.pco.up.flag.p", FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x40000000,
"When set, indicating that the preferred lifetime of the New Prefix MUST be effectively decremented in real time", HFILL }},
{ &hf_icmpv6_rr_pco_up_flag_reserved,
{ "Reserved", "icmpv6.rr.pco.up.flag.reserved", FT_UINT32, BASE_DEC, NULL, 0x3FFFFFFF,
NULL, HFILL }},
{ &hf_icmpv6_rr_pco_up_useprefix,
{ "UsePrefix", "icmpv6.rr.pco.up.useprefix", FT_IPv6, BASE_NONE, NULL, 0x0,
"The 128-bit Use-prefix which either becomes or is used in forming (if KeepLen is nonzero) the New Prefix", HFILL }},
{ &hf_icmpv6_rr_rm,
{ "Result Message", "icmpv6.rr.rm", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rr_rm_flag,
{ "Flags", "icmpv6.rr.rm.flag", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rr_rm_flag_b,
{ "Bounds", "icmpv6.rr.rm.flag.b", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0002,
"When set, indicates that one or more fields in the associated PCO were out of bounds", HFILL }},
{ &hf_icmpv6_rr_rm_flag_f,
{ "Forbidden", "icmpv6.rr.rm.flag.f", FT_BOOLEAN, 16, TFS(&tfs_set_notset), 0x0001,
"When set, indicates that one or more Use-Prefix parts from the associated PCO were not honored by the router because of attempted formation of a forbidden prefix format, such as a multicast or loopback address", HFILL }},
{ &hf_icmpv6_rr_rm_flag_reserved,
{ "Reserved", "icmpv6.rr.rm.flag.reserved", FT_UINT16, BASE_DEC, NULL, 0xFFFC,
"Must be Zero", HFILL }},
{ &hf_icmpv6_rr_rm_ordinal,
{ "Ordinal", "icmpv6.rr.rm.ordinal", FT_UINT8, BASE_HEX, NULL, 0x0,
"The value is otherwise unconstrained", HFILL }},
{ &hf_icmpv6_rr_rm_matchedlen,
{ "MatchedLen", "icmpv6.rr.rm.matchedlen", FT_UINT8, BASE_DEC, NULL, 0x0,
"The length of the Matched Prefix", HFILL }},
{ &hf_icmpv6_rr_rm_interfaceindex,
{ "InterfaceIndex", "icmpv6.rr.rm.interfaceindex", FT_UINT32, BASE_DEC, NULL, 0x0,
"The router's numeric designation of the interface on which the MatchedPrefix was configured", HFILL }},
{ &hf_icmpv6_rr_rm_matchedprefix,
{ "MatchedPrefix", "icmpv6.rr.rm.matchedprefix", FT_IPv6, BASE_NONE, NULL, 0x0,
"The 128 Bits MatchedPrefix", HFILL }},
{ &hf_icmpv6_mip6_identifier,
{ "Identifier", "icmpv6.mip6.identifier", FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"An identifier to aid in matching with Request and Reply", HFILL }},
{ &hf_icmpv6_mip6_home_agent_address,
{ "Home Agent Address", "icmpv6.mip6.home_agent_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"A list of addresses of home agents on the home link for the mobile node", HFILL }},
{ &hf_icmpv6_mip6_flag,
{ "Flags", "icmpv6.mip6.flag", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_mip6_flag_m,
{ "Managed address configuration", "icmpv6.mip6.flag.m", FT_BOOLEAN, 16, TFS(&tfs_set_notset), FLAGS_EO_M,
"When set, it indicates that addresses are available via DHCPv6", HFILL }},
{ &hf_icmpv6_mip6_flag_o,
{ "Other configuration", "icmpv6.mip6.flag.o", FT_BOOLEAN, 16, TFS(&tfs_set_notset), FLAGS_EO_O,
"When set, it indicates that other configuration information is available via DHCPv6", HFILL }},
{ &hf_icmpv6_mip6_flag_rsv,
{ "Reserved", "icmpv6.mip6.flag.rsv", FT_UINT16, BASE_DEC, NULL, 0x2FFF,
"Must be Zero", HFILL }},
{ &hf_icmpv6_mld_mrc,
{ "Maximum Response Code", "icmpv6.mld.maximum_response_code", FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the maximum allowed delay before sending a responding Report", HFILL }},
{ &hf_icmpv6_mld_flag,
{ "Flags", "icmpv6.mld.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_mld_flag_s,
{ "Suppress Router-Side Processing", "icmpv6.mld.flag.s", FT_BOOLEAN, 8, NULL, MLD_FLAG_S,
"Indicates to any receiving multicast routers that they have to suppress the normal timer updates they perform upon hearing a Query", HFILL }},
{ &hf_icmpv6_mld_flag_qrv,
{ "QRV (Querier's Robustness Variable)", "icmpv6.mld.flag.qrv", FT_UINT8, BASE_DEC, NULL, MLD_FLAG_QRV,
"Contains the RV (Robustness Variable) value used by the Querier", HFILL }},
{ &hf_icmpv6_mld_flag_rsv,
{ "Reserved", "icmpv6.mld.flag.reserved", FT_UINT8, BASE_DEC, NULL, MLD_FLAG_RSV,
"Must Be Zero", HFILL }},
{ &hf_icmpv6_mld_qqi,
{ "QQIC (Querier's Query Interval Code)", "icmpv6.mld.qqi", FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the QI (Query Interval) used by the Querier", HFILL }},
{ &hf_icmpv6_mld_nb_sources,
{ "Number of Sources", "icmpv6.mld.nb_sources", FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies how many source addresses are present in the Query", HFILL }},
{ &hf_icmpv6_mld_source_address,
{ "Source Address", "icmpv6.mld.source_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"The Source Address fields are a vector of unicast addresses", HFILL }},
{ &hf_icmpv6_mldr_nb_mcast_records,
{ "Number of Multicast Address Records", "icmpv6.mldr.nb_mcast_records", FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies how many Multicast Address Records are present in this Report", HFILL }},
{ &hf_icmpv6_mldr_mar,
{ "Multicast Address Record", "icmpv6.mldr.mar", FT_NONE, BASE_NONE, NULL, 0x0,
"Each Multicast Address Record is a block of fields that contain information on the sender listening to a single multicast address on the interface from which the Report is sent", HFILL }},
{ &hf_icmpv6_mldr_mar_record_type,
{ "Record Type", "icmpv6.mldr.mar.record_type", FT_UINT8, BASE_DEC, VALS(mldr_record_type_val), 0x0,
"It specifies the type of the Multicast Address Record", HFILL }},
{ &hf_icmpv6_mldr_mar_aux_data_len,
{ "Aux Data Len", "icmpv6.mldr.mar.aux_data_len", FT_UINT8, BASE_DEC, NULL, 0x0,
"The Aux Data Len field contains the length (in units of 32-bit words) of the Auxiliary Data Field in this Multicast Address Record", HFILL }},
{ &hf_icmpv6_mldr_mar_nb_sources,
{ "Number of Sources", "icmpv6.mldr.mar.nb_sources", FT_UINT16, BASE_DEC, NULL, 0x0,
"The Number of Sources field specifies how many source addresses are present in this Multicast Address Record", HFILL }},
{ &hf_icmpv6_mldr_mar_multicast_address,
{ "Multicast Address", "icmpv6.mldr.mar.multicast_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"The Multicast Address field contains the multicast address to which this Multicast Address Record pertains", HFILL }},
{ &hf_icmpv6_mldr_mar_source_address,
{ "Source Address", "icmpv6.mldr.mar.source_address", FT_IPv6, BASE_NONE, NULL, 0x0,
"The Source Address fields are a vector of unicast addresses", HFILL }},
{ &hf_icmpv6_mldr_mar_auxiliary_data,
{ "Auxiliary Data", "icmpv6.mldr.mar.auxiliary_data", FT_BYTES, BASE_NONE, NULL, 0x0,
"Contains additional information that pertain to this Multicast Address Record", HFILL }},
{ &hf_icmpv6_fmip6_subtype,
{ "Subtype", "icmpv6.fmip6.subtype", FT_UINT8, BASE_DEC, VALS(fmip6_subtype_val), 0x0,
"Designates the Subtype of information", HFILL }},
{ &hf_icmpv6_fmip6_hi_flag,
{ "Flag", "icmpv6.fmip6.hi.flag", FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }},
{ &hf_icmpv6_fmip6_hi_flag_s,
{ "Assigned address configuration", "icmpv6.fmip6.hi.flag.s", FT_BOOLEAN, 8, TFS(&tfs_set_notset), FMIP6_HI_FLAG_S,
"When set, this message requests a new CoA to be returned by the destination", HFILL }},
{ &hf_icmpv6_fmip6_hi_flag_u,
{ "Buffer", "icmpv6.fmip6.hi.flag.a", FT_BOOLEAN, 8, TFS(&tfs_set_notset), FMIP6_HI_FLAG_U,
"When set, the destination SHOULD buffer any packets toward the node indicated in the options of this message", HFILL }},
{ &hf_icmpv6_fmip6_hi_flag_reserved,
{ "Reserved", "icmpv6.fmip6.hi.flag.reserved", FT_UINT8, BASE_DEC, NULL, FMIP6_HI_FLAG_RSV,
NULL, HFILL }},
{ &hf_icmpv6_fmip6_identifier,
{ "Identifier", "icmpv6.fmip6.identifier", FT_UINT16, BASE_DEC_HEX, NULL, 0x0,
"An identifier to aid in matching with Request and Reply", HFILL }},
{ &hf_icmpv6_mcast_ra_query_interval,
{ "Query Interval", "icmpv6.mcast_ra.query_interval", FT_UINT16, BASE_DEC, NULL, 0x0,
"The Query Interval value (in seconds) in use by MLD on the interface.", HFILL }},
{ &hf_icmpv6_mcast_ra_robustness_variable,
{ "Robustness Variable", "icmpv6.mcast_ra.robustness_variable", FT_UINT16, BASE_DEC, NULL, 0x0,
"The Robustness Variable in use by MLD on the advertising interface", HFILL }},
{ &hf_icmpv6_ni_qtype,
{ "Qtype", "icmpv6.ni.qtype", FT_UINT16, BASE_DEC, VALS(ni_qtype_val), 0x0,
"Designates the type of information", HFILL }},
{ &hf_icmpv6_ni_flag,
{ "Flags", "icmpv6.ni.flag", FT_UINT16, BASE_HEX, NULL, 0x0,
"Qtype-specific flags that may be defined for certain Query types and their Replies", HFILL }},
{ &hf_icmpv6_ni_flag_g,
{ "Global-scope addresses", "icmpv6.ni.flag.g", FT_BOOLEAN, 16, TFS(&tfs_set_notset), NI_FLAG_G,
"Global-scope addresses are requested", HFILL }},
{ &hf_icmpv6_ni_flag_s,
{ "Site-local addresses", "icmpv6.ni.flag.s", FT_BOOLEAN, 16, TFS(&tfs_set_notset), NI_FLAG_S,
"Site-local addresses are requested", HFILL }},
{ &hf_icmpv6_ni_flag_l,
{ "Link-local addresses", "icmpv6.ni.flag.l", FT_BOOLEAN, 16, TFS(&tfs_set_notset), NI_FLAG_L,
"Link-local addresses are requested", HFILL }},
{ &hf_icmpv6_ni_flag_c,
{ "Compression", "icmpv6.ni.flag.c", FT_BOOLEAN, 16, TFS(&tfs_set_notset), NI_FLAG_C,
"IPv4-compatible (now deprecated) and IPv4-mapped addresses are requested", HFILL }},
{ &hf_icmpv6_ni_flag_a,
{ "Unicast Addresses", "icmpv6.ni.flag.a", FT_BOOLEAN, 16, TFS(&tfs_ni_flag_a), NI_FLAG_A,
"Responder's unicast addresses", HFILL }},
{ &hf_icmpv6_ni_flag_t,
{ "Truncated", "icmpv6.ni.flag.t", FT_BOOLEAN, 16, TFS(&tfs_set_notset), NI_FLAG_T,
"Defined in a Reply only, indicates that the set of addresses is incomplete for space reasons", HFILL }},
{ &hf_icmpv6_ni_flag_rsv,
{ "Reserved", "icmpv6.ni.flag.rsv", FT_UINT16, BASE_HEX, NULL, NI_FLAG_RSV,
"Must be Zero", HFILL }},
{ &hf_icmpv6_ni_nonce,
{ "Nonce", "icmpv6.ni.nonce", FT_UINT64, BASE_HEX, NULL, 0x0,
"An opaque 64-bit field", HFILL }},
{ &hf_icmpv6_ni_query_subject_ipv6,
{ "IPv6 subject address", "icmpv6.ni.query.subject_ipv6", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_ni_query_subject_fqdn,
{ "FQDN subject", "icmpv6.ni.query.subject_fqdn", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_ni_query_subject_ipv4,
{ "IPv4 subject address", "icmpv6.ni.query.subject_ipv4", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_ni_reply_node_ttl,
{ "TTL", "icmpv6.ni.reply.node_ttl", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_ni_reply_node_name,
{ "Name Node", "icmpv6.ni.reply.node_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_ni_reply_node_address,
{ "IPv6 Node address", "icmpv6.ni.reply.node_address", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_ni_reply_ipv4_address,
{ "IPv4 Node address", "icmpv6.ni.reply.ipv4_address", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_dis_flag,
{ "Flags", "icmpv6.rpl.dis.flags", FT_UINT8, BASE_DEC, NULL, 0x0,
"8-bit unused field reserved for flags", HFILL }},
{ &hf_icmpv6_rpl_dio_instance,
{ "RPLInstanceID", "icmpv6.rpl.dio.instance", FT_UINT8, BASE_DEC, NULL, 0x0,
"Set by the DODAG root that indicates which RPL Instance the DODAG is part of", HFILL }},
{ &hf_icmpv6_rpl_dio_version,
{ "Version", "icmpv6.rpl.dio.version", FT_UINT8, BASE_DEC, NULL, 0x0,
"Set by the DODAG root to the DODAGVersionNumber", HFILL }},
{ &hf_icmpv6_rpl_dio_rank,
{ "Rank", "icmpv6.rpl.dio.rank", FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicating the DODAG rank of the node sending the DIO message", HFILL }},
{ &hf_icmpv6_rpl_dio_flag,
{ "Flags", "icmpv6.rpl.dio.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_dio_flag_g,
{ "Grounded (G)", "icmpv6.rpl.dio.flag.g", FT_BOOLEAN, 8, NULL, RPL_DIO_FLAG_G,
"Indicates whether the DODAG advertised can satisfy the application-defined goal", HFILL }},
{ &hf_icmpv6_rpl_dio_flag_0,
{ "Zero", "icmpv6.rpl.dio.flag.0", FT_BOOLEAN, 8, NULL, RPL_DIO_FLAG_0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_dio_flag_mop,
{ "Mode of Operation (MOP)", "icmpv6.rpl.dio.flag.mop", FT_UINT8, BASE_HEX, VALS(rpl_dio_map_val), RPL_DIO_FLAG_MOP,
"Identifies the mode of operation of the RPL Instance as administratively provisioned at and distributed by the DODAG Root", HFILL }},
{ &hf_icmpv6_rpl_dio_flag_prf,
{ "DODAG Preference", "icmpv6.rpl.dio.flag.preference", FT_UINT8, BASE_DEC, NULL, RPL_DIO_FLAG_PRF,
"Defines how preferable the root of this DODAG is compared to other DODAG roots within the instance", HFILL }},
{ &hf_icmpv6_rpl_dio_dtsn,
{ "Destination Advertisement Trigger Sequence Number (DTSN)", "icmpv6.rpl.dio.dtsn", FT_UINT8, BASE_DEC, NULL, 0x0,
"The DTSN is used as part of the procedure to maintain downward routes.", HFILL }},
{ &hf_icmpv6_rpl_dio_dagid,
{ "DODAGID", "icmpv6.rpl.dio.dagid", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 address set by a DODAG root which uniquely identifies a DODAG", HFILL }},
{ &hf_icmpv6_rpl_dao_instance,
{ "RPLInstanceID", "icmpv6.rpl.dao.instance", FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicating the topology instance associated with the DODAG as learned from the DIO", HFILL }},
{ &hf_icmpv6_rpl_dao_flag,
{ "Flags", "icmpv6.rpl.dao.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_dao_flag_k,
{ "DAO-ACK Request (K)", "icmpv6.rpl.dao.flag.k", FT_BOOLEAN, 8, NULL, RPL_DAO_FLAG_K,
"Indicates that the recipient is expected to send a DAO-ACK back", HFILL }},
{ &hf_icmpv6_rpl_dao_flag_d,
{ "DODAGID Present (D)", "icmpv6.rpl.dao.flag.d", FT_BOOLEAN, 8, NULL, RPL_DAO_FLAG_D,
"Indicates that the DODAGID field is present", HFILL }},
{ &hf_icmpv6_rpl_dao_flag_rsv,
{ "Reserved", "icmpv6.rpl.dao.flag.rsv", FT_UINT8, BASE_DEC, NULL, RPL_DAO_FLAG_RESERVED,
"Must be zero", HFILL }},
{ &hf_icmpv6_rpl_dao_sequence,
{ "DAO Sequence", "icmpv6.rpl.dao.sequence", FT_UINT8, BASE_DEC, NULL, 0x0,
"Incremented at each unique DAO message from a node and echoed in the DAO-ACK message", HFILL }},
{ &hf_icmpv6_rpl_dao_dodagid,
{ "DODAGID", "icmpv6.rpl.dao.dodagid", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 address set by a DODAG root which uniquely identifies a DODAG", HFILL }},
{ &hf_icmpv6_rpl_daoack_instance,
{ "RPLInstanceID", "icmpv6.rpl.daoack.instance", FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicating the topology instance associated with the DODAG, as learned from the DIO", HFILL }},
{ &hf_icmpv6_rpl_daoack_flag,
{ "Flag", "icmpv6.rpl.daoack.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_daoack_flag_d,
{ "DODAGID Present (D)", "icmpv6.rpl.daoack.flag.d", FT_BOOLEAN, 8, NULL, RPL_DAOACK_FLAG_D,
"Indicates that the DODAGID field is present", HFILL }},
{ &hf_icmpv6_rpl_daoack_flag_rsv,
{ "Reserved", "icmpv6.rpl.daoack.flag.rsv", FT_UINT8, BASE_DEC, NULL, RPL_DAOACK_FLAG_RESERVED,
"Must be zero", HFILL }},
{ &hf_icmpv6_rpl_daoack_sequence,
{ "DAO-ACK Sequence", "icmpv6.rpl.daoack.sequence", FT_UINT8, BASE_DEC, NULL, 0x0,
"Incremented at each DAO message from a node, and echoed in the DAO-ACK by the recipient", HFILL }},
{ &hf_icmpv6_rpl_daoack_status,
{ "Status", "icmpv6.rpl.daoack.status", FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the completion", HFILL }},
{ &hf_icmpv6_rpl_daoack_dodagid,
{ "DODAGID", "icmpv6.rpl.daoack.dodagid", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 address integer set by a DODAG root which uniquely identifies a DODAG", HFILL }},
{ &hf_icmpv6_rpl_cc_instance,
{ "RPLInstanceID", "icmpv6.rpl.cc.instance", FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicating the topology instance associated with the DODAG, as learned from the DIO", HFILL }},
{ &hf_icmpv6_rpl_cc_flag,
{ "Flag", "icmpv6.rpl.cc.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_cc_flag_r,
{ "Response (R)", "icmpv6.rpl.cc.flag.r", FT_BOOLEAN, 8, NULL, RPL_CC_FLAG_R,
"Indicates whether the CC message is a response", HFILL }},
{ &hf_icmpv6_rpl_cc_flag_rsv,
{ "Reserved", "icmpv6.rpl.cc.flag.rsv", FT_UINT8, BASE_DEC, NULL, RPL_CC_FLAG_RESERVED,
"Must be zero", HFILL }},
{ &hf_icmpv6_rpl_cc_nonce,
{ "CC Nonce", "icmpv6.rpl.cc.nonce", FT_UINT16, BASE_HEX, NULL, 0x0,
"The corresponding CC response includes the same CC nonce value as the request, as learned from the DIO", HFILL }},
{ &hf_icmpv6_rpl_cc_dodagid,
{ "DODAGID", "icmpv6.rpl.cc.dodagid", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 address integer set by a DODAG root which uniquely identifies a DODAG", HFILL }},
{ &hf_icmpv6_rpl_cc_destination_counter,
{ "Destination Counter", "icmpv6.rpl.cc.destination_counter", FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicating the sender's estimate of the destination's current security Counter value", HFILL }},
{ &hf_icmpv6_rpl_secure_flag,
{ "Flags", "icmpv6.rpl.secure.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_secure_flag_t,
{ "Counter is Time (T)", "icmpv6.rpl.secure.flag.t", FT_BOOLEAN, 8, NULL, RPL_SECURE_FLAG_T,
"If it is set then the Counter field is a timestamp", HFILL }},
{ &hf_icmpv6_rpl_secure_flag_rsv,
{ "Reserved", "icmpv6.rpl.secure.flag.rsv", FT_UINT8, BASE_DEC, NULL, RPL_SECURE_FLAG_RSV,
"Must be zero", HFILL }},
{ &hf_icmpv6_rpl_secure_algorithm,
{ "Algorithm", "icmpv6.rpl.secure.algorithm", FT_UINT8, BASE_DEC, VALS(rpl_secure_algorithm_vals), 0x0,
"The Security Algorithm field specifies the encryption, MAC, and signature scheme the network uses", HFILL }},
{ &hf_icmpv6_rpl_secure_kim,
{ "Key Identifier Mode (KIM)", "icmpv6.rpl.secure.kim", FT_UINT8, BASE_DEC, NULL, RPL_SECURE_KIM,
"That indicates whether the key used for packet protection is determined implicitly or explicitly and indicates the particular representation of the Key Identifier field", HFILL }},
{ &hf_icmpv6_rpl_secure_lvl,
{ "Security Level (LVL)", "icmpv6.rpl.secure.lvl", FT_UINT8, BASE_DEC, NULL, RPL_SECURE_LVL,
"Indicates the provided packet protection", HFILL }},
{ &hf_icmpv6_rpl_secure_rsv,
{ "Reserved", "icmpv6.rpl.secure.rsv", FT_UINT8, BASE_DEC, NULL, RPL_SECURE_RSV,
"Must be zero", HFILL }},
{ &hf_icmpv6_rpl_secure_counter,
{ "Counter", "icmpv6.rpl.secure.counter", FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the non-repeating 4-octet value used to construct the cryptographic mechanism that implements packet protection and allows for the provision of semantic security", HFILL }},
{ &hf_icmpv6_rpl_secure_key_source,
{ "Key Source", "icmpv6.rpl.secure.key.source", FT_BYTES, BASE_NONE, NULL, 0x0,
"Indicates the logical identifier of the originator of a group key", HFILL }},
{ &hf_icmpv6_rpl_secure_key_index,
{ "Key Source", "icmpv6.rpl.secure.key.index", FT_UINT8, BASE_DEC, NULL, 0x0,
"Allows unique identification of different keys with the same originator", HFILL }},
{ &hf_icmpv6_rpl_opt,
{ "ICMPv6 RPL Option", "icmpv6.opt", FT_NONE, BASE_NONE, NULL, 0x0,
"Option", HFILL }},
{ &hf_icmpv6_rpl_opt_type,
{ "Type", "icmpv6.rpl.opt.type", FT_UINT8, BASE_DEC, VALS(rpl_option_vals), 0x0,
"Options type", HFILL }},
{ &hf_icmpv6_rpl_opt_length,
{ "Length", "icmpv6.rpl.opt.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The length of the option in octets excluding the Type and Length fields", HFILL }},
{ &hf_icmpv6_rpl_opt_reserved,
{ "Reserved", "icmpv6.rpl.opt.reserved", FT_NONE, BASE_NONE, NULL, 0x0,
"Reserved (Must be 0)", HFILL }},
{ &hf_icmpv6_rpl_opt_padn,
{ "Paddn", "icmpv6.rpl.opt.padn", FT_NONE, BASE_NONE, NULL, 0x0,
"Padding (Must be 0)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_type,
{ "Routing Metric/Constraint Type", "icmpv6.rpl.opt.metric.type", FT_UINT8, BASE_DEC, VALS(rpl_metric_vals), 0x0,
"The Routing Metric/Constraint Type field uniquely identifies each Routing Metric/Constraint object. RFC 6551", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_flags,
{ "Flags","icmpv6.rpl.opt.metric.flags", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_metric_reserved,
{ "Reserved Flags","icmpv6.rpl.opt.metric.reserved", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_RESERVED,
"Reserved (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_flag_p,
{ "Flag P","icmpv6.rpl.opt.metric.flag.p", FT_BOOLEAN, 16, TFS(&tfs_set_notset), RPL_METRIC_FLAG_P,
"Only used for recorded metrics. When cleared, all nodes along the path successfully recorded the corresponding metric. When set, this indicates that one or several nodes along the path could not record the metric", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_flag_c,
{ "Flag C","icmpv6.rpl.opt.metric.flag.c", FT_BOOLEAN, 16, TFS(&tfs_set_notset), RPL_METRIC_FLAG_C,
"When set, this indicates that the object refers to a routing constraint. When cleared, the object refers to a routing metric.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_flag_o,
{ "Flag O","icmpv6.rpl.opt.metric.flag.o", FT_BOOLEAN, 16, TFS(&tfs_set_notset), RPL_METRIC_FLAG_O,
"Used exclusively for routing constraints. When set, this indicates that the constraint is optional. When cleared, the constraint is mandatory.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_flag_r,
{ "Flag R","icmpv6.rpl.opt.metric.flag.r", FT_BOOLEAN, 16, TFS(&tfs_set_notset), RPL_METRIC_FLAG_R,
"Only relevant for a routing metric. When set, this indicates that the routing metric is recorded along the path. When cleared, the routing metric is aggregated", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_a,
{ "A Field","icmpv6.rpl.opt.metric.flag.a", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_A,
"Only relevant for metrics, it indicates whether the aggregated routing metric is additive, is multiplicative, reports a maximum, or reports a minimum", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_prec,
{ "Precedence field","icmpv6.rpl.opt.metric.prec", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_PREC,
"It indicates the precedence of this Routing Metric/Constraint object relative to other objects in the container", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_len,
{ "Metric Length", "icmpv6.rpl.opt.metric.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The length of the object body, expressed in bytes.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_nsa_object,
{ "Node Sate and Attribute Object","icmpv6.rpl.opt.metric.nsa.object", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_metric_nsa_object_reserved,
{ "Reserved field","icmpv6.rpl.opt.metric.nsa.object.reserved", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_NSA_OBJECT_RESERVED,
"Reserved (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_nsa_object_flags,
{ "Flags","icmpv6.rpl.opt.metric.nsa.object.flags", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_NSA_OBJECT_FLAGS,
"Unspecified flags (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_nsa_object_flag_a,
{ "Flag A", "icmpv6.rpl.opt.metric.nsa.object.flag.a", FT_BOOLEAN, 16, TFS(&tfs_set_notset), RPL_METRIC_NSA_OBJECT_FLAG_A,
"When set, this indicates that the node can act as a traffic aggregator.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_nsa_object_flag_o,
{ "Flag O", "icmpv6.rpl.opt.metric.nsa.object.flag.o", FT_BOOLEAN, 16, TFS(&tfs_set_notset), RPL_METRIC_NSA_OBJECT_FLAG_O,
"When set, this indicates that the node is overloaded and may not be able to process traffic.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_ne_object,
{ "Node Energy Object","icmpv6.rpl.opt.metric.ne.object", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_metric_ne_object_flags,
{ "Flags field","icmpv6.rpl.opt.metric.ne.object.flags", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_NE_OBJECT_FLAGS,
"Unspecified flags (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_ne_object_flag_i,
{ "Flag I","icmpv6.rpl.opt.metric.ne.object.flag.i", FT_BOOLEAN, 16, TFS(&tfs_set_notset), RPL_METRIC_NE_OBJECT_FLAG_I,
"Only relevant when the node type is used as a constraint. When set, this indicates that nodes of the type specified in the node type field MUST be included", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_ne_object_type,
{ "Type", "icmpv6.rpl.opt.metric.ne.object.type", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_NE_OBJECT_TYPE,
"T=0 designates a mains-powered node, T=1 a battery-powered node, and T=2 a node powered by an energy scavenger.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_ne_object_flag_e,
{ "Flag E", "icmpv6.rpl.opt.metric.ne.object.flag.e", FT_BOOLEAN, 16, TFS(&tfs_set_notset), RPL_METRIC_NE_OBJECT_FLAG_E,
"When the 'E' bit is set for a metric, the estimated percentage of remaining energy on the node is indicated in the Energy 8-bit field. When cleared, the estimated percentage of remaining energy is not provided. When the 'E' bit is set for a constraint, the E_E field defines a threshold for the inclusion/exclusion: if an inclusion, nodes with values higher than the threshold are to be included; if an exclusion, nodes with values lower than the threshold are to be excluded.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_ne_object_energy,
{ "Energy", "icmpv6.rpl.opt.metric.ne.object.energy", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_NE_OBJECT_ENERGY,
"8-bit unsigned integer field indicating an estimated percentage of remaining energy. The Energy field is only relevant when the 'E' flag is set, and it MUST be set to 0 when the 'E' flag is cleared.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_hp_object,
{ "Hop Count Object","icmpv6.rpl.opt.metric.hp.object", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_metric_hp_object_reserved,
{ "Reserved field","icmpv6.rpl.opt.metric.hp.object.reserved", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_HP_OBJECT_RESERVED,
"Reserved (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_hp_object_flags,
{ "Flags","icmpv6.rpl.opt.metric.hp.object.flags", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_HP_OBJECT_FLAGS,
"Reserved (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_hp_object_hp,
{ "Hop Count", "icmpv6.rpl.opt.metric.hp.object.hp", FT_UINT16, BASE_DEC, NULL, RPL_METRIC_HP_OBJECT_HP,
"When used as a constraint, the DAG root indicates the maximum number of hops that a path may traverse. When used as a metric, each visited node simply increments the Hop Count field.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lt_object_lt,
{ "Link Throughput", "icmpv6.rpl.opt.metric.lt.object.lt", FT_UINT32, BASE_DEC, NULL, 0x0,
"The Throughput metric is the effective bit rate of a link.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_ll_object_ll,
{ "Link Latency", "icmpv6.rpl.opt.metric.ll.object.ll", FT_UINT32, BASE_DEC, NULL, 0x0,
"The Latency is encoded in 32 bits in unsigned integer format, expressed in microseconds.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lql_object,
{ "Link Quality Level Object","icmpv6.rpl.opt.metric.lql.object", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lql_object_res,
{ "Reserved field","icmpv6.rpl.opt.metric.lql.object.res", FT_UINT8, BASE_HEX, NULL, RPL_METRIC_LQL_OBJECT_RES,
"Reserved (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lql_object_val,
{ "Val(ue)","icmpv6.rpl.opt.metric.lql.object.val", FT_UINT8, BASE_HEX, NULL, RPL_METRIC_LQL_OBJECT_VAL,
"LQL value from 0 to 7 where 0 means undetermined and 1 indicates the highest link quality.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lql_object_counter,
{ "Counter", "icmpv6.rpl.opt.metric.lql.object.counter", FT_UINT8, BASE_DEC, NULL, RPL_METRIC_LQL_OBJECT_COUNTER,
"The Counter represents the number of links with that value.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_etx_object_etx,
{ "ETX", "icmpv6.rpl.opt.metric.etx.object.etx", FT_UINT16, BASE_DEC, NULL, 0x0,
"The ETX metric is the number of transmissions a node expects to make to a destination in order to successfully deliver a packet.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lc_object,
{ "Link Color Object","icmpv6.rpl.opt.metric.lc.object", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lc_object_res,
{ "Reserved field","icmpv6.rpl.opt.metric.lc.object.res", FT_UINT8, BASE_HEX, NULL, RPL_METRIC_LC_OBJECT_RES,
"Reserved (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lc_object_lc,
{ "Link Color","icmpv6.rpl.opt.metric.lc.object.lc", FT_UINT16, BASE_HEX, NULL, RPL_METRIC_LC_OBJECT_LC,
"The Link Color (LC) object is an administrative 10-bit link constraint used to avoid or attract specific links for specific traffic types.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lc_object_counter,
{ "Counter", "icmpv6.rpl.opt.metric.lc.object.counter", FT_UINT16, BASE_DEC, NULL, RPL_METRIC_LC_OBJECT_COUNTER,
"The Counter is used to compress the information where the number of links for each Link Color is reported.", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lc_object_reserved,
{ "Reserved", "icmpv6.rpl.opt.metric.lc.object.reserved", FT_UINT16, BASE_DEC, NULL, RPL_METRIC_LC_OBJECT_RESERVED,
"Reserved (Must be Zero).", HFILL }},
{ &hf_icmpv6_rpl_opt_metric_lc_object_flag_i,
{ "Flag I", "icmpv6.rpl.opt.metric.lc.object.flag.i", FT_UINT16, BASE_DEC, NULL, RPL_METRIC_LC_OBJECT_FLAG_I,
"The 'I' bit is only relevant when the Link Color is used as a constraint. When set, this indicates that links with the specified color must be included.", HFILL }},
{ &hf_icmpv6_rpl_opt_route_prefix_length,
{ "Prefix Length", "icmpv6.rpl.opt.route.prefix_length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of leading bits in the Prefix that are valid", HFILL }},
{ &hf_icmpv6_rpl_opt_route_flag,
{ "Flag","icmpv6.rpl.opt.route.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_route_pref,
{ "Preference","icmpv6.rpl.opt.route.pref", FT_UINT8, BASE_DEC, VALS(nd_flag_router_pref), RPL_OPT_ROUTE_PREFERENCE,
"The Route Preference indicates whether to prefer the router associated with this prefix over others, when multiple identical prefixes (for different routers) have been received", HFILL }},
{ &hf_icmpv6_rpl_opt_route_reserved,
{ "Reserved","icmpv6.rpl.opt.route.reserved", FT_UINT8, BASE_DEC, NULL, RPL_OPT_ROUTE_RESERVED,
"Reserved (Must be Zero)", HFILL }},
{ &hf_icmpv6_rpl_opt_route_lifetime,
{ "Route Lifetime", "icmpv6.rpl.opt.route.lifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_infinity), 0x0,
"The length of time in seconds (relative to the time the packet is sent) that the prefix is valid for route determination", HFILL }},
{ &hf_icmpv6_rpl_opt_route_prefix,
{ "Prefix", "icmpv6.rpl.opt.route.prefix", FT_IPv6, BASE_NONE, NULL, 0x0,
"Variable-length field containing an IP address or a prefix of an IPv6 address", HFILL }},
{ &hf_icmpv6_rpl_opt_config_flag,
{ "Flag","icmpv6.rpl.opt.config.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_config_reserved,
{ "Reserved","icmpv6.rpl.opt.config.reserved", FT_UINT8, BASE_DEC, NULL, RPL_OPT_CONFIG_FLAG_RESERVED,
"Must be Zero", HFILL }},
{ &hf_icmpv6_rpl_opt_config_auth,
{ "Authentication Enabled","icmpv6.rpl.opt.config.auth", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RPL_OPT_CONFIG_FLAG_AUTH,
"One bit flag describing the security mode of the network", HFILL }},
{ &hf_icmpv6_rpl_opt_config_pcs,
{ "Path Control Size", "icmpv6.rpl.opt.config.pcs", FT_UINT8, BASE_DEC, NULL, RPL_OPT_CONFIG_FLAG_PCS,
"Used to configure the number of bits that may be allocated to the Path Control field", HFILL }},
{ &hf_icmpv6_rpl_opt_config_doublings,
{ "DIOIntervalDoublings","icmpv6.rpl.opt.config.interval_double", FT_UINT8, BASE_DEC, NULL, 0x0,
"Used to configure Imax of the DIO trickle timer", HFILL }},
{ &hf_icmpv6_rpl_opt_config_min_interval,
{ "DIOIntervalMin", "icmpv6.rpl.opt.config.interval_min", FT_UINT16, BASE_DEC, NULL, 0x0,
"Used to configure Imin of the DIO trickle timer", HFILL }},
{ &hf_icmpv6_rpl_opt_config_redundancy,
{ "DIORedundancyConstant", "icmpv6.rpl.opt.config.redundancy", FT_UINT8, BASE_DEC, NULL, 0x0,
"Used to configure k of the DIO trickle timer", HFILL }},
{ &hf_icmpv6_rpl_opt_config_rank_incr,
{ "MaxRankInc", "icmpv6.rpl.opt.config.max_rank_inc", FT_UINT16, BASE_DEC, NULL, 0x0,
"Used to configure DAGMaxRankIncrease", HFILL }},
{ &hf_icmpv6_rpl_opt_config_hop_rank_inc,
{ "MinHopRankInc", "icmpv6.rpl.opt.config.min_hop_rank_inc", FT_UINT16, BASE_DEC, NULL, 0x0,
"Used to configure MinHopRankIncrease", HFILL }},
{ &hf_icmpv6_rpl_opt_config_ocp,
{ "OCP (Objective Code Point)","icmpv6.rpl.opt.config.ocp", FT_UINT16, BASE_DEC, NULL, 0x0,
"The OCP field identifies the OF and is managed by the IANA", HFILL }},
{ &hf_icmpv6_rpl_opt_config_rsv,
{ "Reserved", "icmpv6.rpl.opt.config.rsv", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_config_def_lifetime,
{ "Default Lifetime", "icmpv6.rpl.opt.config.def_lifetime", FT_UINT8, BASE_DEC, NULL, 0x0,
"This is the lifetime that is used as default for all RPL routes", HFILL }},
{ &hf_icmpv6_rpl_opt_config_lifetime_unit,
{ "Lifetime Unit", "icmpv6.rpl.opt.config.lifetime_unit", FT_UINT16, BASE_DEC, NULL, 0x0,
"Provides the unit in seconds that is used to express route lifetimes in RPL", HFILL }},
{ &hf_icmpv6_rpl_opt_target_flag,
{ "Reserved", "icmpv6.rpl.opt.target.flag", FT_NONE, BASE_NONE, NULL, 0x0,
"Unused field reserved for flags", HFILL }},
{ &hf_icmpv6_rpl_opt_target_prefix_length,
{ "Target Length", "icmpv6.rpl.opt.target.prefix_length", FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of valid leading bits in the IPv6 Prefix", HFILL }},
{ &hf_icmpv6_rpl_opt_target_prefix,
{ "Target", "icmpv6.rpl.opt.target.prefix", FT_IPv6, BASE_NONE, NULL, 0x0,
"Identifying an IPv6 destination address, prefix, or multicast group", HFILL }},
{ &hf_icmpv6_rpl_opt_transit_flag,
{ "Flags", "icmpv6.rpl.opt.transit.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_transit_flag_e,
{ "External", "icmpv6.rpl.opt.transit.flag.e", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RPL_OPT_TRANSIT_FLAG_E,
"Indicate that the parent router redistributes external targets into the RPL network", HFILL }},
{ &hf_icmpv6_rpl_opt_transit_flag_rsv,
{ "Reserved", "icmpv6.rpl.opt.transit.flag.rsv", FT_UINT8, BASE_DEC, NULL, RPL_OPT_TRANSIT_FLAG_RSV,
"Must be Zero", HFILL }},
{ &hf_icmpv6_rpl_opt_transit_pathctl,
{ "Path Control", "icmpv6.rpl.opt.transit.pathctl", FT_UINT8, BASE_DEC, NULL, 0x0,
"Limits the number of DAO-Parents to which a DAO message advertising connectivity", HFILL }},
{ &hf_icmpv6_rpl_opt_transit_pathseq,
{ "Path Sequence", "icmpv6.rpl.opt.transit.pathseq", FT_UINT8, BASE_DEC, NULL, 0x0,
"Increments the Path Sequence each time it issues a RPL Target option with updated information", HFILL }},
{ &hf_icmpv6_rpl_opt_transit_pathlifetime,
{ "Path Lifetime", "icmpv6.rpl.opt.transit.pathlifetime", FT_UINT8, BASE_DEC, NULL, 0x0,
"The length of time in Lifetime Units that the prefix is valid for route determination", HFILL }},
{ &hf_icmpv6_rpl_opt_transit_parent,
{ "Parent Address", "icmpv6.rpl.opt.transit.parent", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 Address of the DODAG Parent of the node originally issuing the Transit Information Option", HFILL }},
{ &hf_icmpv6_rpl_opt_solicited_instance,
{ "Instance", "icmpv6.rpl.opt.solicited.instance", FT_UINT8, BASE_DEC, NULL, 0x0,
"Containing the RPLInstanceID that is being solicited when valid", HFILL }},
{ &hf_icmpv6_rpl_opt_solicited_flag,
{ "Flag", "icmpv6.rpl.opt.solicited.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_solicited_flag_v,
{ "Version predicate", "icmpv6.rpl.opt.solicited.flag.v", FT_BOOLEAN, 8, TFS(&tfs_true_false), RPL_OPT_SOLICITED_FLAG_V,
"The Version predicate is true if the receiver's DODAGVersionNumber matches the requested Version Number", HFILL }},
{ &hf_icmpv6_rpl_opt_solicited_flag_i,
{ "InstanceID predicate","icmpv6.rpl.opt.solicited.flag.i", FT_BOOLEAN, 8, TFS(&tfs_true_false), RPL_OPT_SOLICITED_FLAG_I,
"The InstanceID predicate is true when the RPL node's current RPLInstanceID matches the requested RPLInstanceID", HFILL }},
{ &hf_icmpv6_rpl_opt_solicited_flag_d,
{ "DODAGID predicate", "icmpv6.rpl.opt.solicited.flag.d", FT_BOOLEAN, 8, TFS(&tfs_true_false), RPL_OPT_SOLICITED_FLAG_D,
"The DODAGID predicate is true if the RPL node's parent set has the same DODAGID as the DODAGID field", HFILL }},
{ &hf_icmpv6_rpl_opt_solicited_flag_rsv,
{ "Reserved", "icmpv6.rpl.opt.solicited.flag.rsv", FT_UINT8, BASE_DEC, NULL, RPL_OPT_SOLICITED_FLAG_RSV,
"Must be Zero", HFILL }},
{ &hf_icmpv6_rpl_opt_solicited_dodagid,
{ "DODAGID", "icmpv6.rpl.opt.solicited.dodagid", FT_IPv6, BASE_NONE, NULL, 0x0,
"the DODAGID that is being solicited when valid", HFILL }},
{ &hf_icmpv6_rpl_opt_solicited_version,
{ "Version", "icmpv6.rpl.opt.solicited.version", FT_UINT8, BASE_DEC, NULL, 0x0,
"the value of DODAGVersionNumber that is being solicited when valid", HFILL }},
{ &hf_icmpv6_rpl_opt_prefix_length,
{ "Prefix Length", "icmpv6.rpl.opt.prefix.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of leading bits in the Prefix that are valid", HFILL }},
{ &hf_icmpv6_rpl_opt_prefix_flag,
{ "Flag", "icmpv6.rpl.opt.prefix.flag", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_opt_prefix_flag_l,
{ "On Link", "icmpv6.rpl.opt.prefix.flag.l", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RPL_OPT_PREFIX_FLAG_L,
"When set, indicates that this prefix can be used for on-link determination", HFILL }},
{ &hf_icmpv6_rpl_opt_prefix_flag_a,
{ "Auto Address Config","icmpv6.rpl.opt.config.flag.a", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RPL_OPT_PREFIX_FLAG_A,
"When set indicates that this prefix can be used for stateless address configuration", HFILL }},
{ &hf_icmpv6_rpl_opt_prefix_flag_r,
{ "Router Address", "icmpv6.rpl.opt.config.flag.r", FT_BOOLEAN, 8, TFS(&tfs_set_notset), RPL_OPT_PREFIX_FLAG_R,
"When set, indicates that the Prefix field contains a complete IPv6 address assigned to the sending router that can be used as parent in a target option", HFILL }},
{ &hf_icmpv6_rpl_opt_prefix_flag_rsv,
{ "Reserved", "icmpv6.rpl.opt.config.flag.rsv", FT_UINT8, BASE_DEC, NULL, RPL_OPT_PREFIX_FLAG_RSV,
"Must Be Zero", HFILL }},
{ &hf_icmpv6_rpl_opt_prefix_vlifetime,
{ "Valid Lifetime", "icmpv6.rpl.opt.prefix.valid_lifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_infinity), 0x0,
"The length of time in seconds that the prefix is valid for the purpose of on-link determination", HFILL }},
{ &hf_icmpv6_rpl_opt_prefix_plifetime,
{ "Preferred Lifetime", "icmpv6.rpl.opt.prefix.preferred_lifetime", FT_UINT32, BASE_DEC|BASE_SPECIAL_VALS, VALS(unique_infinity), 0x0,
"The length of time in seconds that addresses generated from the prefix via stateless address autoconfiguration remain preferred", HFILL }},
{ &hf_icmpv6_rpl_opt_prefix,
{ "Destination Prefix", "icmpv6.rpl.opt.prefix", FT_IPv6, BASE_NONE, NULL, 0x0,
"An IPv6 address or a prefix of an IPv6 address", HFILL }},
{ &hf_icmpv6_rpl_opt_targetdesc,
{ "Descriptor", "icmpv6.rpl.opt.targetdesc.descriptor", FT_UINT32, BASE_HEX, NULL, 0x0,
"Opaque Data", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_flag,
{ "Flags", "icmpv6.rpl.opt.routediscovery.flag", FT_NONE, BASE_NONE, NULL, 0x0,
"NULL", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_reply,
{ "Reply", "icmpv6.rpl.opt.routediscovery.flag.reply", FT_BOOLEAN, 8, TFS(&tfs_yes_no), RPL_OPT_ROUTE_DISCOVERY_R,
"The Origin sets this flag to one to allow the Target(s) to send P2P-DRO messages back to the Origin", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_hop_by_hop,
{ "Hop-by-Hop", "icmpv6.rpl.opt.routediscovery.flag.hopbyhop", FT_BOOLEAN, 8, TFS(&tfs_yes_no), RPL_OPT_ROUTE_DISCOVERY_H,
"The Origin sets this flag to one if it desires Hop-by-hop Routes and to zero if it desires Source Routes.", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_num_of_routes,
{ "Number of Routes", "icmpv6.rpl.opt.routediscovery.flag.numofroutes", FT_UINT8, BASE_DEC, NULL, RPL_OPT_ROUTE_DISCOVERY_N,
"This value plus one indicates the number of Source Routes that each Target should convey to the Origin", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_compr,
{ "Compr", "icmpv6.rpl.opt.routediscovery.flag.compr", FT_UINT8, BASE_DEC, NULL, RPL_OPT_ROUTE_DISCOVERY_COMPR,
"Number of prefix octets that are elided from the Target field and Address vector", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_lifetime,
{ "Lifetime", "icmpv6.rpl.opt.routediscovery.lifetime", FT_UINT8, BASE_DEC, NULL, RPL_OPT_ROUTE_DISCOVERY_L,
"Lifetime of the temporary DODAG", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_maxrank,
{ "MaxRank", "icmpv6.rpl.opt.routediscovery.maxrank", FT_UINT8, BASE_DEC, NULL, RPL_OPT_ROUTE_DISCOVERY_MR_NH,
"Upper limit of the integer portion of the rank when used inside a DIO", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_nh,
{ "NH", "icmpv6.rpl.opt.routediscovery.nh", FT_UINT8, BASE_DEC, NULL, RPL_OPT_ROUTE_DISCOVERY_MR_NH,
"Index of the next-hop (NH) address inside the Address vector", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_target_addr,
{ "Target Address", "icmpv6.rpl.opt.routediscovery.targetaddr", FT_IPv6, BASE_NONE, NULL, 0x0,
"An IPv6 address of the Target after eliding Compr number of prefix octets", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_addr_vec,
{ "Address Vector", "icmpv6.rpl.opt.routediscovery.addr_vec", FT_NONE, BASE_NONE, NULL, 0x0,
"NULL", HFILL }},
{ &hf_icmpv6_rpl_opt_route_discovery_addr_vec_addr,
{ "Address", "icmpv6.rpl.opt.routediscovery.addrvec.addr", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_rpl_p2p_dro_instance,
{ "RPLInstanceID", "icmpv6.rpl.p2p.dro.instance", FT_UINT8, BASE_DEC, NULL, 0x0,
"Set by the DODAG root that indicates which RPL Instance the DODAG is part of", HFILL }},
{ &hf_icmpv6_rpl_p2p_dro_version,
{ "Version", "icmpv6.rpl.p2p.dro.version", FT_UINT8, BASE_DEC, NULL, 0x0,
"Set by the DODAG root to the DODAGVersionNumber", HFILL }},
{ &hf_icmpv6_rpl_p2p_dro_flag,
{ "Flags", "icmpv6.rpl.p2p.dro.flag", FT_UINT16, BASE_HEX, NULL, 0x0,
"NULL", HFILL }},
{ &hf_icmpv6_rpl_p2p_dro_flag_stop,
{ "Stop", "icmpv6.rpl.p2p.dro.flag.stop", FT_BOOLEAN, 16, TFS(&tfs_yes_no), RPL_P2P_DRO_FLAG_S,
"Indicates that the P2P-RPL route discovery is over", HFILL }},
{ &hf_icmpv6_rpl_p2p_dro_flag_ack,
{ "Ack", "icmpv6.rpl.p2p.dro.flag.ack", FT_BOOLEAN, 16, TFS(&tfs_yes_no), RPL_P2P_DRO_FLAG_A,
"Indicates that the Origin MUST unicast a P2P-DRO-ACK message to the Target", HFILL }},
{ &hf_icmpv6_rpl_p2p_dro_flag_seq,
{ "Seq", "icmpv6.rpl.p2p.dro.flag.seq", FT_UINT16, BASE_DEC, NULL, RPL_P2P_DRO_FLAG_SEQ,
"Indicates the sequence number for the P2P-DRO", HFILL }},
{ &hf_icmpv6_rpl_p2p_dro_flag_reserved,
{ "Reserved", "icmpv6.rpl.p2p.dro.flag.reserved", FT_UINT16, BASE_DEC, NULL, RPL_P2P_DRO_FLAG_RSV,
NULL, HFILL }},
{ &hf_icmpv6_rpl_p2p_dro_dagid,
{ "DODAGID", "icmpv6.rpl.p2p.dro.dagid", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPv6 address set by a DODAG root which uniquely identifies a DODAG", HFILL }},
{ &hf_icmpv6_rpl_p2p_droack_flag,
{ "Flags", "icmpv6.rpl.p2p.droack.flag", FT_UINT16, BASE_HEX, NULL, 0x0,
"NULL", HFILL }},
{ &hf_icmpv6_rpl_p2p_droack_flag_seq,
{ "Seq", "icmpv6.rpl.p2p.droack.flag.seq", FT_UINT16, BASE_DEC, NULL, RPL_P2P_DROACK_FLAG_SEQ,
"Indicates the sequence number for the P2P-DRO", HFILL }},
{ &hf_icmpv6_rpl_p2p_droack_flag_reserved,
{ "Reserved", "icmpv6.rpl.p2p.droack.flag.reserved", FT_UINT16, BASE_DEC, NULL, RPL_P2P_DROACK_FLAG_RSV,
NULL, HFILL }},
{ &hf_icmpv6_ilnp_nb_locs,
{ "Num of Locs", "icmpv6.ilnp.nb_locs", FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of 64-bit Locator values that are advertised in this message", HFILL }},
{ &hf_icmpv6_ilnp_locator,
{ "Locator", "icmpv6.ilnp.nb_locator", FT_UINT64, BASE_HEX, NULL, 0x0,
"The 64-bit Locator values currently valid for the sending ILNPv6 node", HFILL }},
{ &hf_icmpv6_ilnp_preference,
{ "Preference", "icmpv6.ilnp.nb_preference", FT_UINT32, BASE_DEC, NULL, 0x0,
"The preferability of each Locator relative to other valid Locator values", HFILL }},
{ &hf_icmpv6_ilnp_lifetime,
{ "Lifetime", "icmpv6.ilnp.nb_lifetime", FT_UINT32, BASE_DEC, NULL, 0x0,
"The maximum number of seconds that this particular Locator may be considered valid", HFILL }},
{ &hf_icmpv6_da_status,
{ "Status", "icmpv6.6lowpannd.da.status", FT_UINT8, BASE_DEC, VALS(nd_opt_6lowpannd_status_val), 0x0,
"Indicates the status of a registration in the DAC", HFILL }},
{ &hf_icmpv6_da_rsv,
{ "Reserved", "icmpv6.6lowpannd.da.rsv", FT_UINT8, BASE_DEC, NULL, 0x0,
"Must be Zero", HFILL }},
{ &hf_icmpv6_da_lifetime,
{ "Lifetime", "icmpv6.6lowpannd.da.lifetime", FT_UINT16, BASE_DEC, NULL, 0x0,
"The amount of time in a unit of 60 seconds that the router should retain the Neighbor Cache entry for the sender of the NS that includes this option", HFILL }},
{ &hf_icmpv6_da_eui64,
{ "EUI-64", "icmpv6.6lowpannd.da.eui64", FT_EUI64, BASE_NONE, NULL, 0x0,
"This field is used to uniquely identify the interface of the registered address by including the EUI-64 identifier", HFILL }},
{ &hf_icmpv6_da_raddr,
{ "Registered Address", "icmpv6.6lowpannd.da.reg_addr", FT_IPv6, BASE_NONE, NULL, 0x0,
"Carries the host address, which was contained in the IPv6 Source field in the NS that contained the ARO option sent by the host", HFILL }},
{ &hf_icmpv6_resp_in,
{ "Response In", "icmpv6.resp_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"The response to this request is in this frame", HFILL }},
{&hf_icmpv6_no_resp,
{"No response seen", "icmpv6.no_resp", FT_NONE, BASE_NONE, NULL, 0x0,
"No corresponding response frame was seen", HFILL}},
{ &hf_icmpv6_resp_to,
{ "Response To", "icmpv6.resp_to", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is the response to the request in this frame", HFILL }},
{ &hf_icmpv6_resptime,
{ "Response Time", "icmpv6.resptime", FT_DOUBLE, BASE_NONE, NULL, 0x0,
"The time between the request and the response, in ms.", HFILL }},
{ &hf_icmpv6_mpl_seed_info_min_sequence,
{ "MinSequence", "icmpv6.mpl.seed_info.min_sequence", FT_UINT8, BASE_DEC, NULL, 0x0,
"The lower-bound sequence number for the MPL Seed.", HFILL }},
{ &hf_icmpv6_mpl_seed_info_bm_len,
{ "Buffered Messages Length", "icmpv6.mpl.seed_info.bm_len", FT_UINT8, BASE_DEC, NULL, MPL_SEED_INFO_BM_LEN,
"The The size of buffered-mpl-messages in octets.", HFILL }},
{ &hf_icmpv6_mpl_seed_info_s,
{ "Seed ID Length", "icmpv6.mpl.seed_info.s", FT_UINT8, BASE_DEC, VALS(mpl_seed_id_lengths), MPL_SEED_INFO_S,
"The length of the seed-id.", HFILL }},
{ &hf_icmpv6_mpl_seed_info_seed_id,
{ "Seed ID", "icmpv6.mpl.seed_info.seed_id", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_icmpv6_mpl_seed_info_sequence,
{ "Sequence", "icmpv6.mpl.seed_info.sequence", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_icmpv6,
&ett_icmpv6_opt,
&ett_icmpv6_mar,
&ett_icmpv6_flag_prefix,
&ett_icmpv6_flag_map,
&ett_icmpv6_flag_route_info,
&ett_icmpv6_flag_6lowpan,
&ett_icmpv6_flag_efo,
&ett_icmpv6_rpl_opt,
&ett_icmpv6_rpl_metric_type,
&ett_icmpv6_rpl_metric_flags,
&ett_icmpv6_rpl_metric_nsa_object,
&ett_icmpv6_rpl_metric_ne_object,
&ett_icmpv6_rpl_metric_hp_object,
&ett_icmpv6_rpl_metric_lql_object,
&ett_icmpv6_rpl_metric_lc_object,
&ett_icmpv6_rpl_flag_routing,
&ett_icmpv6_rpl_flag_config,
&ett_icmpv6_rpl_flag_transit,
&ett_icmpv6_rpl_flag_solicited,
&ett_icmpv6_rpl_flag_prefix,
&ett_icmpv6_rpl_route_discovery_flag,
&ett_icmpv6_rpl_route_discovery_addr_vec,
&ett_icmpv6_rpl_p2p_dro_flag,
&ett_icmpv6_rpl_p2p_droack_flag,
&ett_icmpv6_flag_ni,
&ett_icmpv6_flag_rr,
&ett_icmpv6_rr_mp,
&ett_icmpv6_rr_up,
&ett_icmpv6_rr_up_flag_mask,
&ett_icmpv6_rr_up_flag_ra,
&ett_icmpv6_rr_up_flag,
&ett_icmpv6_rr_rm,
&ett_icmpv6_rr_rm_flag,
&ett_icmpv6_flag_mld,
&ett_icmpv6_flag_ra,
&ett_icmpv6_flag_na,
&ett_icmpv6_flag_mip6,
&ett_icmpv6_flag_fmip6,
&ett_icmpv6_flag_secure,
&ett_icmpv6_flag_rpl_dio,
&ett_icmpv6_flag_rpl_dao,
&ett_icmpv6_flag_rpl_daoack,
&ett_icmpv6_flag_rpl_cc,
&ett_icmpv6_opt_name,
&ett_icmpv6_cga_param_name,
&ett_icmpv6_mpl_seed_info,
&ett_icmpv6_mpl_seed_info_bm
};
static ei_register_info ei[] = {
{ &ei_icmpv6_invalid_option_length, { "icmpv6.invalid_option_length", PI_MALFORMED, PI_ERROR, "Invalid Option Length", EXPFILL }},
{ &ei_icmpv6_undecoded_option, { "icmpv6.undecoded.option", PI_UNDECODED, PI_NOTE, "Undecoded option", EXPFILL }},
{ &ei_icmpv6_unknown_data, { "icmpv6.unknown_data.expert", PI_MALFORMED, PI_ERROR, "Unknown Data (not interpreted)", EXPFILL }},
{ &ei_icmpv6_undecoded_rpl_option, { "icmpv6.undecoded.rpl_option", PI_UNDECODED, PI_NOTE, "Undecoded RPL Option", EXPFILL }},
{ &ei_icmpv6_undecoded_type, { "icmpv6.undecoded.type", PI_UNDECODED, PI_NOTE, "Undecoded type", EXPFILL }},
{ &ei_icmpv6_rr_pco_mp_matchlen, { "icmpv6.rr.pco.mp.matchlen.gt128", PI_PROTOCOL, PI_WARN, "MatchLen is greater than 128", EXPFILL }},
{ &ei_icmpv6_rr_pco_mp_matchedlen, { "icmpv6.rr.pco.mp.matchedlen.gt128", PI_PROTOCOL, PI_WARN, "MatchedLen is greater than 128", EXPFILL }},
{ &ei_icmpv6_checksum, { "icmpv6.checksum_bad.expert", PI_CHECKSUM, PI_WARN, "Bad checksum", EXPFILL }},
{ &ei_icmpv6_resp_not_found, { "icmpv6.resp_not_found", PI_SEQUENCE, PI_WARN, "Response not found", EXPFILL }},
{ &ei_icmpv6_rpl_unknown_metric, { "icmpv6.rpl.unknown.metric", PI_UNDECODED, PI_NOTE, "Unknown RPL metric/constraint type", EXPFILL }},
{ &ei_icmpv6_rpl_p2p_hop_by_hop, { "icmpv6.rpl.p2p.hop_by_hop", PI_PROTOCOL, PI_WARN, "Reply MUST be set to one in order to establish a Hop-by-Hop Route", EXPFILL }},
{ &ei_icmpv6_rpl_p2p_num_of_routes, { "icmpv6.rpl.p2p.num_of_routes", PI_PROTOCOL, PI_WARN, "This field MUST be set to zero when Hop-by-Hop Routes are being discovered", EXPFILL }},
{ &ei_icmpv6_rpl_p2p_dro_rdo_zero, { "icmpv6.rpl.p2p.dro.rdo.zero", PI_PROTOCOL, PI_WARN, "This field MUST be set to zero when the P2P-RDO is included in a P2P-DRO", EXPFILL }},
{ &ei_icmpv6_rpl_p2p_dro_zero, { "icmpv6.rpl.p2p.dro.zero", PI_PROTOCOL, PI_WARN, "This field MUST be set to zero", EXPFILL }},
};
expert_module_t* expert_icmpv6;
proto_icmpv6 = proto_register_protocol("Internet Control Message Protocol v6",
"ICMPv6", "icmpv6");
proto_register_field_array(proto_icmpv6, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_icmpv6 = expert_register_protocol(proto_icmpv6);
expert_register_field_array(expert_icmpv6, ei, array_length(ei));
icmpv6_handle = register_dissector("icmpv6", dissect_icmpv6, proto_icmpv6);
icmpv6_tap = register_tap("icmpv6");
}
void
proto_reg_handoff_icmpv6(void)
{
capture_dissector_handle_t icmpv6_cap_handle;
dissector_add_uint("ip.proto", IP_PROTO_ICMPV6, icmpv6_handle);
icmpv6_cap_handle = create_capture_dissector_handle(capture_icmpv6, proto_icmpv6);
capture_dissector_add_uint("ip.proto", IP_PROTO_ICMPV6, icmpv6_cap_handle);
ipv6_handle = find_dissector_add_dependency("ipv6", proto_icmpv6);
}
