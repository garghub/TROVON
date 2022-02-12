static void
decode_sse(proto_tree *ext_tree, tvbuff_t *tvb, int offset, guint ext_len)
{
guint8 msid_len;
guint8 msid_start_offset;
guint8 msid_num_digits;
guint8 msid_index;
char *msid_digits;
const char *p_msid;
gboolean odd_even_ind;
if (ext_len < 2)
{
proto_tree_add_text(ext_tree, tvb, offset, 0,
"Cannot decode Protocol Type - SSE too short");
return;
}
proto_tree_add_item(ext_tree, hf_a11_ses_ptype, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ext_len -= 2;
if (ext_len < 4)
{
proto_tree_add_text(ext_tree, tvb, offset, 0,
"Cannot decode Session Key - SSE too short");
return;
}
proto_tree_add_item(ext_tree, hf_a11_ses_key, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ext_len -= 4;
if (ext_len < 2)
{
proto_tree_add_text(ext_tree, tvb, offset, 0,
"Cannot decode Session Id Version - SSE too short");
return;
}
proto_tree_add_item(ext_tree, hf_a11_ses_sidver, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
ext_len -= 2;
if (ext_len < 2)
{
proto_tree_add_text(ext_tree, tvb, offset, 0,
"Cannot decode SRID - SSE too short");
return;
}
proto_tree_add_item(ext_tree, hf_a11_ses_mnsrid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ext_len -= 2;
if (ext_len < 2)
{
proto_tree_add_text(ext_tree, tvb, offset, 0,
"Cannot decode MSID Type - SSE too short");
return;
}
proto_tree_add_item(ext_tree, hf_a11_ses_msid_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ext_len -= 2;
if (ext_len < 1)
{
proto_tree_add_text(ext_tree, tvb, offset, 0,
"Cannot decode MSID Length - SSE too short");
return;
}
msid_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ext_tree, hf_a11_ses_msid_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ext_len -= 1;
if (ext_len < msid_len)
{
proto_tree_add_text(ext_tree, tvb, offset, 0,
"Cannot decode MSID - SSE too short");
return;
}
msid_digits = (char *)ep_alloc(A11_MSG_MSID_LEN_MAX+2);
msid_start_offset = offset;
if (msid_len > A11_MSG_MSID_ELEM_LEN_MAX)
{
p_msid = "MSID is too long";
}else if (msid_len == 0)
{
p_msid = "MSID is too short";
}else
{
for(msid_index=0; msid_index<msid_len; msid_index++)
{
guint8 msid_digit = tvb_get_guint8(tvb, offset);
offset += 1;
ext_len -= 1;
msid_digits[msid_index*2] = (msid_digit & 0x0F) + '0';
msid_digits[(msid_index*2) + 1] = ((msid_digit & 0xF0) >> 4) + '0';
}
odd_even_ind = (msid_digits[0] == '1');
if (odd_even_ind)
{
msid_num_digits = ((msid_len-1) * 2) + 1;
}else
{
msid_num_digits = (msid_len-1) * 2;
}
msid_digits[msid_num_digits + 1] = '\0';
p_msid = msid_digits + 1;
}
proto_tree_add_string
(ext_tree, hf_a11_ses_msid, tvb, msid_start_offset, msid_len, p_msid);
return;
}
static void
dissect_a11_radius( tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree, int app_len)
{
proto_item *ti;
proto_tree *radius_tree;
if (!tree)
return;
if (tvb_reported_length_remaining(tvb, offset) < 12) {
return;
}
ti = proto_tree_add_text(tree, tvb, offset - 2, app_len, "Airlink Record");
radius_tree = proto_item_add_subtree(ti, ett_a11_radiuses);
dissect_attribute_value_pairs(radius_tree, pinfo, tvb, offset, app_len-2);
}
static const gchar *
dissect_3gpp2_service_option_profile(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
int offset = 0;
guint8 sub_type, sub_type_length;
proto_tree_add_item(tree, hf_a11_serv_opt_prof_max_serv, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
while (tvb_length_remaining(tvb,offset)>0){
sub_type_length = tvb_get_guint8(tvb,offset+1);
sub_type = tvb_get_guint8(tvb,offset);
proto_tree_add_item(tree, hf_a11_sub_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_a11_sub_type_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (sub_type==1){
proto_tree_add_item(tree, hf_a11_serv_opt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_a11_max_num_serv_opt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
offset = offset+sub_type_length-2;
}
return "";
}
static const gchar *
dissect_3gpp2_radius_aut_flow_profile_ids(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_)
{
proto_tree *sub_tree;
int offset = 0;
proto_item *item;
guint8 sub_type, sub_type_length;
guint32 value;
while (tvb_length_remaining(tvb,offset)>0){
sub_type = tvb_get_guint8(tvb,offset);
sub_type_length = tvb_get_guint8(tvb,offset+1);
value = tvb_get_ntohs(tvb,offset+2);
item = proto_tree_add_text(tree, tvb, offset, sub_type_length, "%s = %u",
val_to_str(sub_type, a11_aut_flow_prof_subtype_vals, "Unknown"), value);
sub_tree = proto_item_add_subtree(item, ett_a11_aut_flow_profile_ids);
proto_tree_add_item(sub_tree, hf_a11_aut_flow_prof_sub_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_a11_aut_flow_prof_sub_type_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_a11_aut_flow_prof_sub_type_value, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset+sub_type_length-2;
}
return "";
}
static void
dissect_ase(tvbuff_t *tvb, int offset, guint ase_len, proto_tree *ext_tree)
{
guint clen = 0;
while (clen < ase_len)
{
proto_tree *exts_tree;
guint8 srid = tvb_get_guint8(tvb, offset+1);
guint16 service_option = tvb_get_ntohs(tvb, offset+2);
proto_item *ti;
guint8 entry_lenght;
int entry_start_offset;
entry_start_offset = offset;
entry_lenght = tvb_get_guint8(tvb, offset);
if (registration_request_msg && (service_option==64 || service_option==67)){
if (service_option == 67){
ti = proto_tree_add_text(ext_tree, tvb, offset, entry_lenght+1, "GRE Key Entry (SRID: %d)", srid);
} else if (service_option== 64){
ti = proto_tree_add_text(ext_tree, tvb, offset, entry_lenght+1, "GRE Key Entry (SRID: %d)", srid);
} else {
proto_tree_add_text(ext_tree, tvb, offset, entry_lenght+1, "Unknown service option %u (SRID: %d)", service_option, srid);
clen+=entry_lenght+1;
continue;
}
}else{
ti = proto_tree_add_text(ext_tree, tvb, offset, entry_lenght, "GRE Key Entry (SRID: %d)", srid);
}
exts_tree = proto_item_add_subtree(ti, ett_a11_ase);
proto_tree_add_item(exts_tree, hf_a11_ase_len_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(exts_tree, hf_a11_ase_srid_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(exts_tree, hf_a11_ase_servopt_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(exts_tree, hf_a11_ase_gre_proto_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(exts_tree, hf_a11_ase_gre_key, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(exts_tree, hf_a11_ase_pcf_addr_key, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
if (registration_request_msg){
if (service_option == 0x0043){
proto_item *tl;
proto_tree *extv_tree;
guint8 profile_count=tvb_get_guint8(tvb, offset+6);
guint8 profile_index=0;
guint8 reverse_profile_count;
proto_item *tj = proto_tree_add_text(exts_tree, tvb, offset,6+(profile_count*2)+1, "Forward ROHC Info");
proto_tree *extt_tree = proto_item_add_subtree(tj, ett_a11_forward_rohc);
proto_tree_add_item(extt_tree, hf_a11_ase_forward_rohc_info_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(extt_tree, hf_a11_ase_forward_maxcid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(extt_tree, hf_a11_ase_forward_mrru, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(extt_tree, hf_a11_ase_forward_large_cids, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
profile_count=tvb_get_guint8(tvb, offset);
proto_tree_add_item(extt_tree, hf_a11_ase_forward_profile_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for(profile_index=0; profile_index<profile_count; profile_index++){
proto_item *tk = proto_tree_add_text (extt_tree, tvb, offset, (2*profile_count), "Forward Profile : %d", profile_index);
proto_tree *extu_tree = proto_item_add_subtree(tk, ett_a11_forward_profile);
proto_tree_add_item(extu_tree, hf_a11_ase_forward_profile, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
}
reverse_profile_count=tvb_get_guint8(tvb, offset+6);
tl = proto_tree_add_text(exts_tree, tvb, offset,6+(reverse_profile_count*2)+1, "Reverse ROHC Info");
extv_tree = proto_item_add_subtree(tl, ett_a11_reverse_rohc);
proto_tree_add_item(extv_tree, hf_a11_ase_reverse_rohc_info_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(extv_tree, hf_a11_ase_reverse_maxcid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(extv_tree, hf_a11_ase_reverse_mrru, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(extv_tree, hf_a11_ase_reverse_large_cids, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
profile_count=tvb_get_guint8(tvb, offset);
proto_tree_add_item(extv_tree, hf_a11_ase_reverse_profile_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
for(profile_index=0; profile_index<reverse_profile_count; profile_index++){
proto_item *tm = proto_tree_add_text(extv_tree, tvb, offset, (2*profile_count), "Reverse Profile : %d", profile_index);
proto_tree *extw_tree = proto_item_add_subtree(tm, ett_a11_reverse_profile);
proto_tree_add_item(extw_tree, hf_a11_ase_reverse_profile, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
}
}
}
clen+=entry_lenght+1;
offset = entry_start_offset + entry_lenght+1;
}
registration_request_msg =0;
}
static void
dissect_fwd_qosinfo_flags(tvbuff_t *tvb, int offset, proto_tree *ext_tree, guint8 *p_dscp_included)
{
guint8 flags = tvb_get_guint8(tvb, offset);
guint8 nbits = sizeof(flags) * 8;
proto_item *ti = proto_tree_add_text(ext_tree, tvb, offset, sizeof(flags),
"Flags: %#02x", flags);
proto_tree *flags_tree = proto_item_add_subtree(ti, ett_a11_fqi_flags);
proto_tree_add_text(flags_tree, tvb, offset, sizeof(flags), "%s",
decode_boolean_bitfield(flags, A11_FQI_IPFLOW_DISC_ENABLED, nbits,
"IP Flow Discriminator Enabled", "IP Flow Discriminator Disabled"));
proto_tree_add_text(flags_tree, tvb, offset, sizeof(flags), "%s",
decode_boolean_bitfield(flags, A11_FQI_DSCP_INCLUDED, nbits,
"DSCP Included", "DSCP Not Included"));
if (flags & A11_FQI_DSCP_INCLUDED)
{
*p_dscp_included = 1;
}else
{
*p_dscp_included = 0;
}
}
static void
dissect_fqi_entry_flags(tvbuff_t *tvb, int offset, proto_tree *ext_tree, guint8 dscp_enabled)
{
guint8 dscp = tvb_get_guint8(tvb, offset);
guint8 nbits = sizeof(dscp) * 8;
proto_item *ti = proto_tree_add_text(ext_tree, tvb, offset, sizeof(dscp),
"DSCP and Flow State: %#02x", dscp);
proto_tree *flags_tree = proto_item_add_subtree(ti, ett_a11_fqi_entry_flags);
if (dscp_enabled)
{
proto_tree_add_text(flags_tree, tvb, offset, sizeof(dscp), "%s",
decode_numeric_bitfield(dscp, A11_FQI_DSCP, nbits,
"DSCP: %u"));
}
proto_tree_add_text(flags_tree, tvb, offset, sizeof(dscp), "%s",
decode_boolean_bitfield(dscp, A11_FQI_FLOW_STATE, nbits,
"Flow State: Active", "Flow State: Inactive"));
}
static void
dissect_rqi_entry_flags(tvbuff_t *tvb, int offset, proto_tree *ext_tree)
{
guint8 flags = tvb_get_guint8(tvb, offset);
guint8 nbits = sizeof(flags) * 8;
proto_item *ti = proto_tree_add_text(ext_tree, tvb, offset, sizeof(flags),
"Flags: %#02x", flags);
proto_tree *flags_tree = proto_item_add_subtree(ti, ett_a11_rqi_entry_flags);
proto_tree_add_text(flags_tree, tvb, offset, sizeof(flags), "%s",
decode_boolean_bitfield(flags, A11_RQI_FLOW_STATE, nbits,
"Flow State: Active", "Flow State: Inactive"));
}
static void
dissect_fwd_qosinfo(tvbuff_t *tvb, int offset, proto_tree *ext_tree)
{
int clen = 0;
guint8 flow_count;
guint8 flow_index;
guint8 dscp_enabled = 0;
proto_tree_add_item(ext_tree, hf_a11_fqi_srid, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
dissect_fwd_qosinfo_flags(tvb, offset+clen, ext_tree, &dscp_enabled);
clen++;
flow_count = tvb_get_guint8(tvb, offset+clen);
flow_count &= 0x1F;
proto_tree_add_item(ext_tree, hf_a11_fqi_flowcount, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
for(flow_index=0; flow_index<flow_count; flow_index++)
{
guint8 requested_qos_len = 0;
guint8 granted_qos_len = 0;
guint8 entry_len = tvb_get_guint8(tvb, offset+clen);
guint8 flow_id = tvb_get_guint8(tvb, offset+clen+1);
proto_item *ti = proto_tree_add_text
(ext_tree, tvb, offset+clen, entry_len+1, "Forward Flow Entry (Flow Id: %d)", flow_id);
proto_tree *exts_tree = proto_item_add_subtree(ti, ett_a11_fqi_flowentry);
proto_tree_add_item(exts_tree, hf_a11_fqi_entrylen, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
proto_tree_add_item(exts_tree, hf_a11_fqi_flowid, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
dissect_fqi_entry_flags(tvb, offset+clen, exts_tree, dscp_enabled);
clen++;
requested_qos_len = tvb_get_guint8(tvb, offset+clen);
proto_tree_add_item(exts_tree, hf_a11_fqi_requested_qoslen, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
if (requested_qos_len)
{
proto_item *ti2;
proto_tree *exts_tree2;
proto_item *ti1 = proto_tree_add_text(ext_tree, tvb, offset+clen,requested_qos_len, "Forward Requested QoS ");
proto_tree *exts_tree1 = proto_item_add_subtree(ti1, ett_a11_fqi_requestedqos);
proto_tree_add_text(exts_tree1, tvb, offset+clen, requested_qos_len, "Forward Requested QoS Sub Blob");
proto_tree_add_item(exts_tree1, hf_a11_fqi_flow_priority, tvb,offset+clen , 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exts_tree1, hf_a11_fqi_num_qos_attribute_set, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exts_tree1, hf_a11_fqi_qos_attribute_setlen, tvb, offset+clen, 2, ENC_BIG_ENDIAN);
clen++;
ti2 = proto_tree_add_text(exts_tree1, tvb, offset+clen, 4, "QoS Attribute Set");
exts_tree2 = proto_item_add_subtree(ti2, ett_a11_fqi_qos_attribute_set);
proto_tree_add_item(exts_tree2, hf_a11_fqi_qos_attribute_setid, tvb, offset+clen, 2, ENC_BIG_ENDIAN);
clen++;
proto_tree_add_item(exts_tree2, hf_a11_fqi_verbose, tvb,offset+clen, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exts_tree2, hf_a11_fqi_flow_profileid, tvb, offset+clen, 3, ENC_BIG_ENDIAN);
clen += 3;
}
granted_qos_len = tvb_get_guint8(tvb, offset+clen);
proto_tree_add_item(exts_tree, hf_a11_fqi_granted_qoslen, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
if (granted_qos_len)
{
proto_item *ti3;
proto_tree *exts_tree3;
ti3 = proto_tree_add_text(ext_tree, tvb, offset+clen, granted_qos_len, "Forward Granted QoS ");
exts_tree3 = proto_item_add_subtree(ti3, ett_a11_fqi_grantedqos);
proto_tree_add_text(exts_tree3, tvb, offset+clen, granted_qos_len, "Forward Granted QoS Sub Blob");
proto_tree_add_item(exts_tree3, hf_a11_fqi_qos_granted_attribute_setid, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
}
}
}
static void
dissect_rev_qosinfo(tvbuff_t *tvb, int offset, proto_tree *ext_tree)
{
int clen = 0;
guint8 flow_count;
guint8 flow_index;
proto_tree_add_item(ext_tree, hf_a11_rqi_srid, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
flow_count = tvb_get_guint8(tvb, offset+clen);
flow_count &= 0x1F;
proto_tree_add_item(ext_tree, hf_a11_rqi_flowcount, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
for(flow_index=0; flow_index<flow_count; flow_index++)
{
guint8 requested_qos_len;
guint8 granted_qos_len;
guint8 entry_len = tvb_get_guint8(tvb, offset+clen);
guint8 flow_id = tvb_get_guint8(tvb, offset+clen+1);
proto_item *ti = proto_tree_add_text
(ext_tree, tvb, offset+clen, entry_len+1, "Reverse Flow Entry (Flow Id: %d)", flow_id);
proto_tree *exts_tree = proto_item_add_subtree(ti, ett_a11_rqi_flowentry);
proto_tree_add_item(exts_tree, hf_a11_rqi_entrylen, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
proto_tree_add_item(exts_tree, hf_a11_rqi_flowid, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
dissect_rqi_entry_flags(tvb, offset+clen, exts_tree);
clen++;
requested_qos_len = tvb_get_guint8(tvb, offset+clen);
proto_tree_add_item(exts_tree, hf_a11_rqi_requested_qoslen, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
if (requested_qos_len)
{
proto_item *ti1, *ti2;
proto_tree *exts_tree1, *exts_tree2;
ti1 = proto_tree_add_text(ext_tree, tvb, offset+clen,requested_qos_len , "Reverse Requested QoS ");
exts_tree1 = proto_item_add_subtree(ti1, ett_a11_rqi_requestedqos);
proto_tree_add_text(exts_tree1, tvb, offset+clen, requested_qos_len, "Reverse Requested QoS Sub Blob");
proto_tree_add_item(exts_tree1, hf_a11_rqi_flow_priority, tvb,offset+clen , 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exts_tree1, hf_a11_rqi_num_qos_attribute_set, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exts_tree1, hf_a11_rqi_qos_attribute_setlen, tvb, offset+clen, 2, ENC_BIG_ENDIAN);
clen++;
ti2 = proto_tree_add_text(exts_tree1, tvb, offset+clen, 4, "QoS Attribute Set");
exts_tree2 = proto_item_add_subtree(ti2, ett_a11_rqi_qos_attribute_set);
proto_tree_add_item(exts_tree2, hf_a11_rqi_qos_attribute_setid, tvb, offset+clen, 2, ENC_BIG_ENDIAN);
clen++;
proto_tree_add_item(exts_tree2, hf_a11_rqi_verbose, tvb,offset+clen, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(exts_tree2, hf_a11_rqi_flow_profileid, tvb, offset+clen, 3, ENC_BIG_ENDIAN);
clen += 3;
}
granted_qos_len = tvb_get_guint8(tvb, offset+clen);
proto_tree_add_item(exts_tree, hf_a11_rqi_granted_qoslen, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
if (granted_qos_len)
{
proto_item *ti3;
proto_tree *exts_tree3;
ti3 = proto_tree_add_text(ext_tree, tvb, offset+clen,granted_qos_len , "Reverse Granted QoS ");
exts_tree3 = proto_item_add_subtree(ti3, ett_a11_rqi_grantedqos);
proto_tree_add_text(exts_tree3, tvb, offset+clen, granted_qos_len, "Reverse Granted QoS Sub Blob");
proto_tree_add_item(exts_tree3, hf_a11_rqi_qos_granted_attribute_setid, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
}
}
}
static void
dissect_subscriber_qos_profile(tvbuff_t *tvb, packet_info *pinfo, int offset, int ext_len, proto_tree *ext_tree)
{
proto_tree *exts_tree;
int qos_profile_len = ext_len;
proto_item *ti =
proto_tree_add_text (ext_tree, tvb, offset, 0,
"Subscriber Qos Profile (%d bytes)",
qos_profile_len);
exts_tree = proto_item_add_subtree(ti, ett_a11_subscriber_profile);
if (qos_profile_len)
{
proto_tree_add_item
(exts_tree, hf_a11_subsciber_profile, tvb, offset,
qos_profile_len, ENC_NA);
dissect_attribute_value_pairs(exts_tree, pinfo, tvb, offset, qos_profile_len);
}
}
static void
dissect_fwd_qosupdate_info(tvbuff_t *tvb, int offset, proto_tree *ext_tree)
{
int clen = 0;
guint8 flow_count;
guint8 flow_index;
flow_count = tvb_get_guint8(tvb, offset+clen);
proto_tree_add_item(ext_tree, hf_a11_fqui_flowcount, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
for(flow_index=0; flow_index<flow_count; flow_index++)
{
proto_tree *exts_tree;
guint8 granted_qos_len;
guint8 flow_id = tvb_get_guint8(tvb, offset+clen);
proto_item *ti = proto_tree_add_text
(ext_tree, tvb, offset+clen, 1, "Forward Flow Entry (Flow Id: %d)", flow_id);
clen++;
exts_tree = proto_item_add_subtree(ti, ett_a11_fqui_flowentry);
granted_qos_len = tvb_get_guint8(tvb, offset+clen);
proto_tree_add_item
(exts_tree, hf_a11_fqui_updated_qoslen, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
if (granted_qos_len)
{
proto_tree_add_item
(exts_tree, hf_a11_fqui_updated_qos, tvb, offset+clen,
granted_qos_len, ENC_NA);
clen += granted_qos_len;
}
}
}
static void
dissect_rev_qosupdate_info(tvbuff_t *tvb, int offset, proto_tree *ext_tree)
{
int clen = 0;
guint8 flow_count;
guint8 flow_index;
flow_count = tvb_get_guint8(tvb, offset+clen);
proto_tree_add_item(ext_tree, hf_a11_rqui_flowcount, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
for(flow_index=0; flow_index<flow_count; flow_index++)
{
proto_tree *exts_tree;
guint8 granted_qos_len;
guint8 flow_id = tvb_get_guint8(tvb, offset+clen);
proto_item *ti = proto_tree_add_text
(ext_tree, tvb, offset+clen, 1, "Reverse Flow Entry (Flow Id: %d)", flow_id);
clen++;
exts_tree = proto_item_add_subtree(ti, ett_a11_rqui_flowentry);
granted_qos_len = tvb_get_guint8(tvb, offset+clen);
proto_tree_add_item
(exts_tree, hf_a11_rqui_updated_qoslen, tvb, offset+clen, 1, ENC_BIG_ENDIAN);
clen++;
if (granted_qos_len)
{
proto_tree_add_item
(exts_tree, hf_a11_rqui_updated_qos, tvb, offset+clen,
granted_qos_len, ENC_NA);
clen += granted_qos_len;
}
}
}
static void
dissect_a11_extensions( tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree)
{
proto_item *ti;
proto_tree *exts_tree;
proto_tree *ext_tree;
guint ext_len;
guint8 ext_type;
guint8 ext_subtype = 0;
guint hdrLen;
gint16 apptype = -1;
ti = proto_tree_add_text(tree, tvb, offset, -1, "Extensions");
exts_tree = proto_item_add_subtree(ti, ett_a11_exts);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
ext_type = tvb_get_guint8(tvb, offset);
if (ext_type == GEN_AUTH_EXT) {
ext_subtype = tvb_get_guint8(tvb, offset + 1);
ext_len = tvb_get_ntohs(tvb, offset + 2);
hdrLen = 4;
} else if ((ext_type == CVSE_EXT) || (ext_type == OLD_CVSE_EXT)) {
ext_len = tvb_get_ntohs(tvb, offset + 2);
ext_subtype = tvb_get_guint8(tvb, offset + 8);
hdrLen = 4;
} else {
ext_len = tvb_get_guint8(tvb, offset + 1);
hdrLen = 2;
}
ti = proto_tree_add_text(exts_tree, tvb, offset, ext_len + hdrLen,
"Extension: %s",
val_to_str(ext_type, a11_ext_types,
"Unknown Extension %u"));
ext_tree = proto_item_add_subtree(ti, ett_a11_ext);
proto_tree_add_uint(ext_tree, hf_a11_ext_type, tvb, offset, 1, ext_type);
offset++;
if (ext_type == SS_EXT) {
proto_tree_add_uint(ext_tree, hf_a11_ext_len, tvb, offset, 1, ext_len);
offset++;
}
else if ((ext_type == CVSE_EXT) || (ext_type == OLD_CVSE_EXT)) {
offset++;
proto_tree_add_uint(ext_tree, hf_a11_ext_len, tvb, offset, 2, ext_len);
offset+=2;
}
else if (ext_type != GEN_AUTH_EXT) {
proto_tree_add_uint(ext_tree, hf_a11_ext_len, tvb, offset, 1, ext_len);
offset++;
}
switch(ext_type) {
case SS_EXT:
decode_sse(ext_tree, tvb, offset, ext_len);
offset += ext_len;
ext_len = 0;
break;
case MH_AUTH_EXT:
case MF_AUTH_EXT:
case FH_AUTH_EXT:
case RU_AUTH_EXT:
if (ext_len < 4)
break;
proto_tree_add_item(ext_tree, hf_a11_aext_spi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ext_len -= 4;
if (ext_len == 0)
break;
proto_tree_add_item(ext_tree, hf_a11_aext_auth, tvb, offset, ext_len,
ENC_NA);
break;
case MN_NAI_EXT:
if (ext_len == 0)
break;
proto_tree_add_item(ext_tree, hf_a11_next_nai, tvb, offset,
ext_len, ENC_UTF_8|ENC_NA);
break;
case GEN_AUTH_EXT:
proto_tree_add_uint(ext_tree, hf_a11_ext_stype, tvb, offset, 1, ext_subtype);
offset++;
proto_tree_add_uint(ext_tree, hf_a11_ext_len, tvb, offset, 2, ext_len);
offset+=2;
if (ext_len < 4)
break;
proto_tree_add_item(ext_tree, hf_a11_aext_spi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ext_len -= 4;
if (ext_len == 0)
break;
proto_tree_add_item(ext_tree, hf_a11_aext_auth, tvb, offset,
ext_len, ENC_NA);
break;
case OLD_CVSE_EXT:
case CVSE_EXT:
if (ext_len < 4)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_vid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ext_len -= 4;
if (ext_len < 2)
break;
apptype = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(ext_tree, hf_a11_vse_apptype, tvb, offset, 2, apptype);
offset += 2;
ext_len -= 2;
if (apptype == 0x0101) {
if (tvb_reported_length_remaining(tvb, offset) > 0) {
dissect_a11_radius(tvb, pinfo, offset, ext_tree, ext_len + 2);
}
}
break;
case OLD_NVSE_EXT:
case NVSE_EXT:
if (ext_len < 6)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_vid, tvb, offset+2, 4, ENC_BIG_ENDIAN);
offset += 6;
ext_len -= 6;
proto_tree_add_item(ext_tree, hf_a11_vse_apptype, tvb, offset, 2, ENC_BIG_ENDIAN);
if (ext_len < 2)
break;
apptype = tvb_get_ntohs(tvb, offset);
offset += 2;
ext_len -= 2;
switch(apptype) {
case 0x0401:
if (ext_len < 5)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_panid, tvb, offset, 5, ENC_NA);
offset += 5;
ext_len -= 5;
if (ext_len < 5)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_canid, tvb, offset, 5, ENC_NA);
break;
case 0x0501:
if (ext_len < 4)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_ppaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 0x0601:
if (ext_len < 2)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_dormant, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x0701:
if (ext_len < 1)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_code, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x0801:
if (ext_len < 1)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_pdit, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x0802:
proto_tree_add_text(ext_tree, tvb, offset, -1, "Session Parameter - Always On");
break;
case 0x0803:
proto_tree_add_item(ext_tree, hf_a11_vse_qosmode, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x0901:
if (ext_len < 2)
break;
proto_tree_add_item(ext_tree, hf_a11_vse_srvopt, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case 0x0C01:
dissect_ase(tvb, offset, ext_len, ext_tree);
break;
case 0x0D01:
dissect_fwd_qosinfo(tvb, offset, ext_tree);
break;
case 0x0D02:
dissect_rev_qosinfo(tvb, offset, ext_tree);
break;
case 0x0D03:
dissect_subscriber_qos_profile(tvb, pinfo, offset, ext_len, ext_tree);
break;
case 0x0DFE:
dissect_fwd_qosupdate_info(tvb, offset, ext_tree);
break;
case 0x0DFF:
dissect_rev_qosupdate_info(tvb, offset, ext_tree);
break;
}
break;
case MF_CHALLENGE_EXT:
default:
proto_tree_add_item(ext_tree, hf_a11_ext, tvb, offset, ext_len, ENC_NA);
break;
}
offset += ext_len;
}
}
static int
dissect_a11( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *a11_tree = NULL;
proto_item *tf;
proto_tree *flags_tree;
guint8 type;
guint8 flags;
guint offset = 0;
if (!tvb_bytes_exist(tvb, offset, 1))
return 0;
type = tvb_get_guint8(tvb, offset);
if (match_strval(type, a11_types) == NULL)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "3GPP2 A11");
col_clear(pinfo->cinfo, COL_INFO);
if (type == REGISTRATION_REQUEST)
registration_request_msg =1;
else
registration_request_msg =0;
switch (type) {
case REGISTRATION_REQUEST:
registration_request_msg = 1;
col_add_fstr(pinfo->cinfo, COL_INFO, "Reg Request: PDSN=%s PCF=%s",
tvb_ip_to_str(tvb, 8),
tvb_ip_to_str(tvb, 12));
if (tree) {
ti = proto_tree_add_item(tree, proto_a11, tvb, offset, -1, ENC_NA);
a11_tree = proto_item_add_subtree(ti, ett_a11);
proto_tree_add_uint(a11_tree, hf_a11_type, tvb, offset, 1, type);
offset++;
flags = tvb_get_guint8(tvb, offset);
tf = proto_tree_add_uint(a11_tree, hf_a11_flags, tvb,
offset, 1, flags);
flags_tree = proto_item_add_subtree(tf, ett_a11_flags);
proto_tree_add_boolean(flags_tree, hf_a11_s, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_a11_b, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_a11_d, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_a11_m, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_a11_g, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_a11_v, tvb, offset, 1, flags);
proto_tree_add_boolean(flags_tree, hf_a11_t, tvb, offset, 1, flags);
offset++;
proto_tree_add_item(a11_tree, hf_a11_life, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(a11_tree, hf_a11_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_haaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_coa, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case REGISTRATION_REPLY:
col_add_fstr(pinfo->cinfo, COL_INFO, "Reg Reply: PDSN=%s, Code=%u",
tvb_ip_to_str(tvb, 8), tvb_get_guint8(tvb,1));
if (tree) {
ti = proto_tree_add_item(tree, proto_a11, tvb, offset, -1, ENC_NA);
a11_tree = proto_item_add_subtree(ti, ett_a11);
proto_tree_add_uint(a11_tree, hf_a11_type, tvb, offset, 1, type);
offset++;
proto_tree_add_item(a11_tree, hf_a11_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(a11_tree, hf_a11_life, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(a11_tree, hf_a11_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_haaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case REGISTRATION_UPDATE:
col_add_fstr(pinfo->cinfo, COL_INFO,"Reg Update: PDSN=%s",
tvb_ip_to_str(tvb, 8));
if (tree) {
ti = proto_tree_add_item(tree, proto_a11, tvb, offset, -1, ENC_NA);
a11_tree = proto_item_add_subtree(ti, ett_a11);
proto_tree_add_uint(a11_tree, hf_a11_type, tvb, offset, 1, type);
offset++;
offset+=3;
proto_tree_add_item(a11_tree, hf_a11_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_haaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case REGISTRATION_ACK:
col_add_fstr(pinfo->cinfo, COL_INFO, "Reg Ack: PCF=%s Status=%u",
tvb_ip_to_str(tvb, 8),
tvb_get_guint8(tvb,3));
if (tree) {
ti = proto_tree_add_item(tree, proto_a11, tvb, offset, -1, ENC_NA);
a11_tree = proto_item_add_subtree(ti, ett_a11);
proto_tree_add_uint(a11_tree, hf_a11_type, tvb, offset, 1, type);
offset++;
offset+=2;
proto_tree_add_item(a11_tree, hf_a11_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(a11_tree, hf_a11_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_coa, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case SESSION_UPDATE:
col_add_fstr(pinfo->cinfo, COL_INFO,"Ses Update: PDSN=%s",
tvb_ip_to_str(tvb, 8));
if (tree) {
ti = proto_tree_add_item(tree, proto_a11, tvb, offset, -1, ENC_NA);
a11_tree = proto_item_add_subtree(ti, ett_a11);
proto_tree_add_uint(a11_tree, hf_a11_type, tvb, offset, 1, type);
offset++;
offset+=3;
proto_tree_add_item(a11_tree, hf_a11_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_haaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case SESSION_ACK:
col_add_fstr(pinfo->cinfo, COL_INFO, "Ses Upd Ack: PCF=%s, Status=%u",
tvb_ip_to_str(tvb, 8),
tvb_get_guint8(tvb,3));
if (tree) {
ti = proto_tree_add_item(tree, proto_a11, tvb, offset, -1, ENC_NA);
a11_tree = proto_item_add_subtree(ti, ett_a11);
proto_tree_add_uint(a11_tree, hf_a11_type, tvb, offset, 1, type);
offset++;
offset+=2;
proto_tree_add_item(a11_tree, hf_a11_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(a11_tree, hf_a11_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_coa, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case CAPABILITIES_INFO:
col_add_fstr(pinfo->cinfo, COL_INFO, "Cap Info: PDSN=%s, PCF=%s",
tvb_ip_to_str(tvb, 8),
tvb_ip_to_str(tvb, 12));
if (tree) {
ti = proto_tree_add_item(tree, proto_a11, tvb, offset, -1, ENC_NA);
a11_tree = proto_item_add_subtree(ti, ett_a11);
proto_tree_add_uint(a11_tree, hf_a11_type, tvb, offset, 1, type);
offset++;
offset+=3;
proto_tree_add_item(a11_tree, hf_a11_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_haaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_coa, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
case CAPABILITIES_INFO_ACK:
col_add_fstr(pinfo->cinfo, COL_INFO, "Cap Info Ack: PCF=%s",
tvb_ip_to_str(tvb, 8));
if (tree) {
ti = proto_tree_add_item(tree, proto_a11, tvb, offset, -1, ENC_NA);
a11_tree = proto_item_add_subtree(ti, ett_a11);
proto_tree_add_uint(a11_tree, hf_a11_type, tvb, offset, 1, type);
offset++;
offset+=3;
proto_tree_add_item(a11_tree, hf_a11_homeaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_coa, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(a11_tree, hf_a11_ident, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
offset += 8;
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
if (tree && a11_tree) {
if (tvb_reported_length_remaining(tvb, offset) > 0)
dissect_a11_extensions(tvb, pinfo, offset, a11_tree);
}
return tvb_length(tvb);
}
void
proto_register_a11(void)
{
static hf_register_info hf[] = {
{ &hf_a11_type,
{ "Message Type", "a11.type",
FT_UINT8, BASE_DEC, VALS(a11_types), 0,
"A11 Message Type", HFILL }
},
{ &hf_a11_flags,
{ "Flags", "a11.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_a11_s,
{ "Simultaneous Bindings", "a11.s",
FT_BOOLEAN, 8, NULL, 128,
"Simultaneous Bindings Allowed", HFILL }
},
{ &hf_a11_b,
{ "Broadcast Datagrams", "a11.b",
FT_BOOLEAN, 8, NULL, 64,
"Broadcast Datagrams requested", HFILL }
},
{ &hf_a11_d,
{ "Co-located Care-of Address", "a11.d",
FT_BOOLEAN, 8, NULL, 32,
"MN using Co-located Care-of address", HFILL }
},
{ &hf_a11_m,
{ "Minimal Encapsulation", "a11.m",
FT_BOOLEAN, 8, NULL, 16,
"MN wants Minimal encapsulation", HFILL }
},
{ &hf_a11_g,
{ "GRE", "a11.g",
FT_BOOLEAN, 8, NULL, 8,
"MN wants GRE encapsulation", HFILL }
},
{ &hf_a11_v,
{ "Van Jacobson", "a11.v",
FT_BOOLEAN, 8, NULL, 4,
NULL, HFILL }
},
{ &hf_a11_t,
{ "Reverse Tunneling", "a11.t",
FT_BOOLEAN, 8, NULL, 2,
"Reverse tunneling requested", HFILL }
},
{ &hf_a11_code,
{ "Reply Code", "a11.code",
FT_UINT8, BASE_DEC, VALS(a11_reply_codes), 0,
"A11 Registration Reply code", HFILL }
},
{ &hf_a11_status,
{ "Reply Status", "a11.ackstat",
FT_UINT8, BASE_DEC, VALS(a11_ack_status), 0,
"A11 Registration Ack Status", HFILL }
},
{ &hf_a11_life,
{ "Lifetime", "a11.life",
FT_UINT16, BASE_DEC, NULL, 0,
"A11 Registration Lifetime", HFILL }
},
{ &hf_a11_homeaddr,
{ "Home Address", "a11.homeaddr",
FT_IPv4, BASE_NONE, NULL, 0,
"Mobile Node's home address", HFILL }
},
{ &hf_a11_haaddr,
{ "Home Agent", "a11.haaddr",
FT_IPv4, BASE_NONE, NULL, 0,
"Home agent IP Address", HFILL }
},
{ &hf_a11_coa,
{ "Care of Address", "a11.coa",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ident,
{ "Identification", "a11.ident",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0,
"MN Identification", HFILL }
},
{ &hf_a11_ext_type,
{ "Extension Type", "a11.ext.type",
FT_UINT8, BASE_DEC, VALS(a11_ext_types), 0,
"Mobile IP Extension Type", HFILL }
},
{ &hf_a11_ext_stype,
{ "Gen Auth Ext SubType", "a11.ext.auth.subtype",
FT_UINT8, BASE_DEC, VALS(a11_ext_stypes), 0,
"Mobile IP Auth Extension Sub Type", HFILL }
},
{ &hf_a11_ext_len,
{ "Extension Length", "a11.ext.len",
FT_UINT16, BASE_DEC, NULL, 0,
"Mobile IP Extension Length", HFILL }
},
{ &hf_a11_ext,
{ "Extension", "a11.extension",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_aext_spi,
{ "SPI", "a11.auth.spi",
FT_UINT32, BASE_HEX, NULL, 0,
"Authentication Header Security Parameter Index", HFILL }
},
{ &hf_a11_aext_auth,
{ "Authenticator", "a11.auth.auth",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_next_nai,
{ "NAI", "a11.nai",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ses_key,
{ "Key", "a11.ext.key",
FT_UINT32, BASE_HEX, NULL, 0,
"Session Key", HFILL }
},
{ &hf_a11_ses_sidver,
{ "Session ID Version", "a11.ext.sidver",
FT_UINT8, BASE_DEC, NULL, 3,
NULL, HFILL}
},
{ &hf_a11_ses_mnsrid,
{ "MNSR-ID", "a11.ext.mnsrid",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ses_msid_type,
{ "MSID Type", "a11.ext.msid_type",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ses_msid_len,
{ "MSID Length", "a11.ext.msid_len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ses_msid,
{ "MSID(BCD)", "a11.ext.msid",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ses_ptype,
{ "Protocol Type", "a11.ext.ptype",
FT_UINT16, BASE_HEX, VALS(a11_ses_ptype_vals), 0,
NULL, HFILL }
},
{ &hf_a11_vse_vid,
{ "Vendor ID", "a11.ext.vid",
FT_UINT32, BASE_HEX|BASE_EXT_STRING, &sminmpec_values_ext, 0,
NULL, HFILL }
},
{ &hf_a11_vse_apptype,
{ "Application Type", "a11.ext.apptype",
FT_UINT8, BASE_HEX, VALS(a11_ext_app), 0,
NULL, HFILL }
},
{ &hf_a11_vse_ppaddr,
{ "Anchor P-P Address", "a11.ext.ppaddr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_vse_dormant,
{ "All Dormant Indicator", "a11.ext.dormant",
FT_UINT16, BASE_HEX, VALS(a11_ext_dormant), 0,
NULL, HFILL }
},
{ &hf_a11_vse_code,
{ "Reply Code", "a11.ext.code",
FT_UINT8, BASE_DEC, VALS(a11_reply_codes), 0,
NULL, HFILL }
},
{ &hf_a11_vse_pdit,
{ "PDSN Code", "a11.ext.code",
FT_UINT8, BASE_HEX, VALS(a11_ext_nvose_pdsn_code), 0,
NULL, HFILL }
},
{ &hf_a11_vse_srvopt,
{ "Service Option", "a11.ext.srvopt",
FT_UINT16, BASE_HEX, VALS(a11_ext_nvose_srvopt), 0,
NULL, HFILL }
},
{ &hf_a11_vse_panid,
{ "PANID", "a11.ext.panid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_vse_canid,
{ "CANID", "a11.ext.canid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_vse_qosmode,
{ "QoS Mode", "a11.ext.qosmode",
FT_UINT8, BASE_HEX, VALS(a11_ext_nvose_qosmode), 0,
NULL, HFILL }
},
{ &hf_a11_ase_len_type,
{ "Entry Length", "a11.ext.ase.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_srid_type,
{ "Service Reference ID (SRID)", "a11.ext.ase.srid",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_servopt_type,
{ "Service Option", "a11.ext.ase.srvopt",
FT_UINT16, BASE_HEX, VALS(a11_ext_nvose_srvopt), 0,
NULL, HFILL }
},
{ &hf_a11_ase_gre_proto_type,
{ "GRE Protocol Type", "a11.ext.ase.ptype",
FT_UINT16, BASE_HEX, VALS(a11_ses_ptype_vals), 0,
NULL, HFILL }
},
{ &hf_a11_ase_gre_key,
{ "GRE Key", "a11.ext.ase.key",
FT_UINT32, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_pcf_addr_key,
{ "PCF IP Address", "a11.ext.ase.pcfip",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_fqi_srid,
{ "SRID", "a11.ext.fqi.srid",
FT_UINT8, BASE_DEC, NULL, 0,
"Forward Flow Entry SRID", HFILL }
},
{ &hf_a11_fqi_flags,
{ "Flags", "a11.ext.fqi.flags",
FT_UINT8, BASE_HEX, NULL, 0,
"Forward Flow Entry Flags", HFILL }
},
{ &hf_a11_fqi_flowcount,
{ "Forward Flow Count", "a11.ext.fqi.flowcount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_fqi_flowid,
{ "Forward Flow Id", "a11.ext.fqi.flowid",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_fqi_entrylen,
{ "Entry Length", "a11.ext.fqi.entrylen",
FT_UINT8, BASE_DEC, NULL, 0,
"Forward Entry Length", HFILL }
},
{ &hf_a11_fqi_dscp,
{ "Forward DSCP", "a11.ext.fqi.dscp",
FT_UINT8, BASE_HEX, NULL, 0,
"Forward Flow DSCP", HFILL }
},
{ &hf_a11_fqi_flowstate,
{ "Forward Flow State", "a11.ext.fqi.flowstate",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_fqi_requested_qoslen,
{ "Requested QoS Length", "a11.ext.fqi.reqqoslen",
FT_UINT8, BASE_DEC, NULL, 0,
"Forward Requested QoS Length", HFILL }
},
{ &hf_a11_fqi_flow_priority,
{ "Flow Priority", "a11.ext.fqi.flow_priority",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_a11_fqi_num_qos_attribute_set,
{ "Number of QoS Attribute Sets", "a11.ext.fqi.num_qos_attribute_set",
FT_UINT8, BASE_DEC, NULL, 0x0E,
NULL, HFILL }
},
{ &hf_a11_fqi_qos_attribute_setlen,
{ "QoS Attribute Set Length", "a11.ext.fqi.qos_attribute_setlen",
FT_UINT16, BASE_DEC, NULL, 0x01E0,
NULL, HFILL }
},
{ &hf_a11_fqi_qos_attribute_setid,
{ "QoS Attribute SetID", "a11.ext.fqi.qos_attribute_setid",
FT_UINT16, BASE_DEC, NULL, 0x1FC0,
NULL, HFILL }
},
{ &hf_a11_fqi_verbose,
{ "Verbose", "a11.ext.fqi.verbose",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{ &hf_a11_fqi_flow_profileid,
{ "Flow Profile Id", "a11.ext.fqi.flow_profileid",
FT_UINT24, BASE_DEC, NULL, 0x1FFFE0,
NULL, HFILL }
},
{ &hf_a11_fqi_qos_granted_attribute_setid,
{ "QoS Attribute SetID", "a11.ext.fqi.qos_granted_attribute_setid",
FT_UINT8, BASE_DEC, NULL, 0xFE,
NULL, HFILL }
},
{ &hf_a11_fqi_granted_qoslen,
{ "Granted QoS Length", "a11.ext.fqi.graqoslen",
FT_UINT8, BASE_DEC, NULL, 0,
"Forward Granted QoS Length", HFILL }
},
{ &hf_a11_rqi_flow_priority,
{ "Flow Priority", "a11.ext.rqi.flow_priority",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_a11_rqi_num_qos_attribute_set,
{ "Number of QoS Attribute Sets", "a11.ext.rqi.num_qos_attribute_set",
FT_UINT8, BASE_DEC, NULL, 0x0E,
NULL, HFILL }
},
{ &hf_a11_rqi_qos_attribute_setlen,
{ "QoS Attribute Set Length", "a11.ext.rqi.qos_attribute_setlen",
FT_UINT16, BASE_DEC, NULL, 0x01E0,
NULL, HFILL }
},
{ &hf_a11_rqi_qos_attribute_setid,
{ "QoS Attribute SetID", "a11.ext.rqi.qos_attribute_setid",
FT_UINT16, BASE_DEC, NULL, 0x1FC0,
NULL, HFILL }
},
{ &hf_a11_rqi_verbose,
{ "Verbose", "a11.ext.rqi.verbose",
FT_UINT8, BASE_DEC, NULL, 0x20,
NULL, HFILL }
},
{ &hf_a11_rqi_flow_profileid,
{ "Flow Profile Id", "a11.ext.rqi.flow_profileid",
FT_UINT24, BASE_DEC, NULL, 0x1FFFE0,
NULL, HFILL }
},
{ &hf_a11_rqi_qos_granted_attribute_setid,
{ "QoS Attribute SetID", "a11.ext.rqi.qos_granted_attribute_setid",
FT_UINT8, BASE_DEC, NULL, 0xFE,
NULL, HFILL }
},
{ &hf_a11_rqi_srid,
{ "SRID", "a11.ext.rqi.srid",
FT_UINT8, BASE_DEC, NULL, 0,
"Reverse Flow Entry SRID", HFILL }
},
{ &hf_a11_rqi_flowcount,
{ "Reverse Flow Count", "a11.ext.rqi.flowcount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_rqi_flowid,
{ "Reverse Flow Id", "a11.ext.rqi.flowid",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_rqi_entrylen,
{ "Entry Length", "a11.ext.rqi.entrylen",
FT_UINT8, BASE_DEC, NULL, 0,
"Reverse Flow Entry Length", HFILL }
},
{ &hf_a11_rqi_flowstate,
{ "Flow State", "a11.ext.rqi.flowstate",
FT_UINT8, BASE_HEX, NULL, 0,
"Reverse Flow State", HFILL }
},
{ &hf_a11_rqi_requested_qoslen,
{ "Requested QoS Length", "a11.ext.rqi.reqqoslen",
FT_UINT8, BASE_DEC, NULL, 0,
"Reverse Requested QoS Length", HFILL }
},
{ &hf_a11_rqi_requested_qos,
{ "Requested QoS", "a11.ext.rqi.reqqos",
FT_BYTES, BASE_NONE, NULL, 0,
"Reverse Requested QoS", HFILL }
},
{ &hf_a11_rqi_granted_qoslen,
{ "Granted QoS Length", "a11.ext.rqi.graqoslen",
FT_UINT8, BASE_DEC, NULL, 0,
"Reverse Granted QoS Length", HFILL }
},
{ &hf_a11_rqi_granted_qos,
{ "Granted QoS", "a11.ext.rqi.graqos",
FT_BYTES, BASE_NONE, NULL, 0,
"Reverse Granted QoS", HFILL }
},
{ &hf_a11_fqui_flowcount,
{ "Forward QoS Update Flow Count", "a11.ext.fqui.flowcount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_rqui_flowcount,
{ "Reverse QoS Update Flow Count", "a11.ext.rqui.flowcount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_fqui_updated_qoslen,
{ "Forward Updated QoS Sub-Blob Length", "a11.ext.fqui.updatedqoslen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_fqui_updated_qos,
{ "Forward Updated QoS Sub-Blob", "a11.ext.fqui.updatedqos",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_rqui_updated_qoslen,
{ "Reverse Updated QoS Sub-Blob Length", "a11.ext.rqui.updatedqoslen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_rqui_updated_qos,
{ "Reverse Updated QoS Sub-Blob", "a11.ext.rqui.updatedqos",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_subsciber_profile_len,
{ "Subscriber QoS Profile Length", "a11.ext.sqp.profilelen",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_subsciber_profile,
{ "Subscriber QoS Profile", "a11.ext.sqp.profile",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_forward_rohc_info_len,
{ "Forward ROHC Info Length", "a11.ext.ase.forwardlen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_forward_maxcid,
{ "Forward MAXCID", "a11.ext.ase.maxcid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_forward_mrru,
{ "Forward MRRU", "a11.ext.ase.mrru",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_forward_large_cids,
{ "Forward Large CIDS", "a11.ext.ase.forwardlargecids",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_a11_ase_forward_profile_count,
{ "Forward Profile Count", "a11.ext.ase.profilecount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_forward_profile,
{ "Forward Profile", "a11.ext.ase.forwardprofile",
FT_UINT16, BASE_DEC, VALS(a11_rohc_profile_vals), 0,
NULL, HFILL }
},
{ &hf_a11_ase_reverse_rohc_info_len,
{ "Reverse ROHC Info Length", "a11.ext.ase.reverselen",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_reverse_maxcid,
{ "Reverse MAXCID", "a11.ext.ase.revmaxcid",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_reverse_mrru,
{ "Reverse MRRU", "a11.ext.ase.revmrru",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_reverse_large_cids,
{ "Reverse Large CIDS", "a11.ext.ase.reverselargecids",
FT_UINT8, BASE_DEC, NULL, 128,
NULL, HFILL }
},
{ &hf_a11_ase_reverse_profile_count,
{ "Reverse Profile Count", "a11.ext.ase.revprofilecount",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_ase_reverse_profile,
{ "Reverse Profile", "a11.ext.ase.reverseprofile",
FT_UINT16, BASE_DEC, VALS(a11_rohc_profile_vals), 0,
NULL, HFILL }
},
{ &hf_a11_aut_flow_prof_sub_type,
{ "Sub type", "a11.aut_flow_prof.sub_type",
FT_UINT8, BASE_DEC, VALS(a11_aut_flow_prof_subtype_vals), 0,
NULL, HFILL }
},
{ &hf_a11_aut_flow_prof_sub_type_len,
{ "Length", "a11.aut_flow_prof.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_aut_flow_prof_sub_type_value,
{ "Value", "a11.aut_flow_prof.value",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_serv_opt_prof_max_serv,
{ "Service-Connections-Per-Link-flow", "a11.serv_opt_prof.scplf",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_sub_type,
{ "Sub-Type", "a11.sub_type",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_sub_type_length,
{ "Sub-Type Length", "a11.sub_type_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_serv_opt,
{ "Service Option", "a11.serviceoption",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_a11_max_num_serv_opt,
{ "Max number of service instances of Service Option", "a11.serviceoption",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_a11,
&ett_a11_flags,
&ett_a11_ext,
&ett_a11_exts,
&ett_a11_radius,
&ett_a11_radiuses,
&ett_a11_ase,
&ett_a11_fqi_flowentry,
&ett_a11_fqi_requestedqos,
&ett_a11_fqi_qos_attribute_set,
&ett_a11_fqi_grantedqos,
&ett_a11_rqi_flowentry,
&ett_a11_rqi_requestedqos,
&ett_a11_rqi_qos_attribute_set,
&ett_a11_rqi_grantedqos,
&ett_a11_fqi_flags,
&ett_a11_fqi_entry_flags,
&ett_a11_rqi_entry_flags,
&ett_a11_fqui_flowentry,
&ett_a11_rqui_flowentry,
&ett_a11_subscriber_profile,
&ett_a11_forward_rohc,
&ett_a11_reverse_rohc,
&ett_a11_forward_profile,
&ett_a11_reverse_profile,
&ett_a11_aut_flow_profile_ids,
};
proto_a11 = proto_register_protocol("3GPP2 A11", "3GPP2 A11", "a11");
new_register_dissector("a11", dissect_a11, proto_a11);
proto_register_field_array(proto_a11, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_a11(void)
{
dissector_handle_t a11_handle;
a11_handle = find_dissector("a11");
dissector_add_uint("udp.port", UDP_PORT_3GA11, a11_handle);
radius_register_avp_dissector(VENDOR_THE3GPP2, 74, dissect_3gpp2_service_option_profile);
radius_register_avp_dissector(VENDOR_THE3GPP2, 131, dissect_3gpp2_radius_aut_flow_profile_ids);
}
