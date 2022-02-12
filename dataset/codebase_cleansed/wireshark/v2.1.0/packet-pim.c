static void
dissect_pimv1_addr(tvbuff_t *tvb, int offset, proto_tree *pim_tree, int hf_ip) {
proto_tree_add_bitmask_list(pim_tree, tvb, offset, 1, pim_src_flags_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pim_tree, hf_pim_mask_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pim_tree, hf_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
}
static int
dissect_pimv1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
guint8 pim_type;
guint8 pim_ver;
guint length, pim_length;
guint16 pim_cksum, computed_cksum;
vec_t cksum_vec[1];
proto_tree *pim_tree = NULL;
proto_item *ti;
proto_tree *pimopt_tree = NULL;
proto_item *ticksum;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PIMv1");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_pim, tvb, offset, -1, ENC_NA);
pim_tree = proto_item_add_subtree(ti, ett_pim);
proto_tree_add_string(pim_tree, hf_pim_igmp_type, tvb, offset, 0, "PIM (0x14)");
offset += 1;
pim_type = tvb_get_guint8(tvb, offset);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(pim_type, pim_type1_vals, "Unknown (%u)"));
proto_tree_add_uint(pim_tree, hf_pim_code, tvb, offset, 1, pim_type);
offset += 1;
pim_cksum = tvb_get_ntohs(tvb, offset);
ticksum = proto_tree_add_item(pim_tree, hf_pim_cksum, tvb, offset, 2, ENC_BIG_ENDIAN);
pim_ver = PIM_VER(tvb_get_guint8(tvb, offset + 2));
if (pim_ver != 1) {
offset += 2;
proto_tree_add_item(pim_tree, hf_pim_version, tvb, offset, 1, ENC_BIG_ENDIAN);
return offset+tvb_reported_length_remaining(tvb, offset);
}
length = tvb_reported_length(tvb);
if (pim_type == 1) {
pim_length = 8;
col_set_writable(pinfo->cinfo, FALSE);
} else {
pim_length = length;
}
if (!pinfo->fragmented && length >= pim_length &&
tvb_captured_length(tvb) >= pim_length) {
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, 0, pim_length);
computed_cksum = in_cksum(&cksum_vec[0], 1);
if (computed_cksum == 0) {
proto_item_append_text(ticksum, " [correct]");
} else {
proto_item_append_text(ticksum, " [incorrect, should be 0x%04x]", in_cksum_shouldbe(pim_cksum, computed_cksum));
}
}
offset += 2;
proto_tree_add_item(pim_tree, hf_pim_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pim_tree, hf_pim_res_bytes, tvb, offset, 3, ENC_NA);
offset += 3;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_item *subitem;
subitem = proto_tree_add_item(pim_tree, hf_pim_option, tvb, offset, -1, ENC_NA);
pimopt_tree = proto_item_add_subtree(subitem, ett_pim_opts);
} else
return offset;
switch (pim_type) {
case 0:
{
guint32 holdtime;
proto_item *ti_hold;
proto_tree_add_item(pimopt_tree, hf_pim_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
ti_hold = proto_tree_add_item_ret_uint(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, ENC_BIG_ENDIAN, &holdtime);
if(holdtime == 0xFFFF){
proto_item_append_text(ti_hold, " (Infinity)");
}
offset += 2;
break;
}
case 1:
{
guint8 v_hl;
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
v_hl = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pimopt_tree, hf_pim_ip_version, tvb, offset, 1, ENC_BIG_ENDIAN);
switch((v_hl & 0xf0) >> 4) {
case 0:
ti = proto_tree_add_item(pimopt_tree, hf_pim_dummy_header, tvb, offset, -1, ENC_NA);
if (pinfo->src.type == AT_IPv4) {
proto_item_append_text(ti, " IPv4");
proto_tree_add_item(pimopt_tree, hf_pim_source_ip4, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pimopt_tree, hf_pim_group_ip4, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
} else if (pinfo->src.type == AT_IPv6) {
proto_item_append_text(ti, " IPv6");
proto_tree_add_item(pimopt_tree, hf_pim_source_ip6, tvb, offset + 8, 16, ENC_NA);
proto_tree_add_item(pimopt_tree, hf_pim_group_ip6, tvb, offset + 8 + 16, 16, ENC_NA);
} else
proto_item_append_text(ti, " for an unknown protocol");
break;
case 4:
if (use_main_tree) {
call_dissector(ip_handle, next_tvb, pinfo, tree);
} else {
call_dissector(ip_handle, next_tvb, pinfo, pimopt_tree);
}
break;
case 6:
if (use_main_tree) {
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
} else {
call_dissector(ipv6_handle, next_tvb, pinfo, pimopt_tree);
}
break;
default:
break;
}
break;
}
case 2:
{
proto_tree_add_item(pimopt_tree, hf_pim_group_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_source_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
}
case 3:
case 6:
case 7:
{
int off;
int ngroup, i, njoin, nprune, j;
guint32 holdtime;
proto_tree *grouptree = NULL;
proto_item *tigroup;
proto_tree *subtree = NULL;
proto_item *tisub;
proto_item *ti_hold;
proto_tree_add_item(pimopt_tree, hf_pim_upstream_neighbor_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pim_tree, hf_pim_res_bytes, tvb, offset, 2, ENC_NA);
offset += 2;
ti_hold = proto_tree_add_item_ret_uint(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, ENC_BIG_ENDIAN, &holdtime);
if(holdtime == 0xFFFF){
proto_item_append_text(ti_hold, " (Infinity)");
}
offset += 2;
proto_tree_add_item(pim_tree, hf_pim_res_bytes, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(pimopt_tree, hf_pim_mask_len, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(pimopt_tree, hf_pim_addr_len, tvb, offset, 1, ENC_NA);
offset += 1;
ngroup = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pimopt_tree, hf_pim_numgroups, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i = 0; i < ngroup; i++) {
tigroup = proto_tree_add_ipv4_format(pimopt_tree, hf_pim_group_ip4, tvb, offset, 4,
tvb_get_ipv4(tvb, offset), "Group %d: %s", i, tvb_ip_to_str(tvb, offset));
grouptree = proto_item_add_subtree(tigroup, ett_pim);
offset += 4;
proto_tree_add_ipv4_format(grouptree, hf_pim_group_mask_ip4, tvb, offset, 4,
tvb_get_ipv4(tvb, offset), "Group %d Mask: %s", i, tvb_ip_to_str(tvb, offset));
offset += 4;
njoin = tvb_get_ntohs(tvb, offset);
nprune = tvb_get_ntohs(tvb, offset + 2);
tisub = proto_tree_add_item(grouptree, hf_pim_numjoins, tvb,
offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(tisub, ett_pim);
off = offset + 4;
for (j = 0; j < njoin; j++) {
dissect_pimv1_addr(tvb, off, subtree, hf_pim_join_ip4);
off += 6;
}
tisub = proto_tree_add_item(grouptree, hf_pim_numprunes, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(tisub, ett_pim);
for (j = 0; j < nprune; j++) {
dissect_pimv1_addr(tvb, off, subtree, hf_pim_prune_ip4);
off += 6;
}
offset = off;
}
break;
}
case 4:
{
guint32 holdtime;
proto_item *ti_hold;
proto_tree_add_item(pimopt_tree, hf_pim_group_address_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_group_mask_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_rp_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pim_tree, hf_pim_res_bytes, tvb, offset, 2, ENC_NA);
offset += 2;
ti_hold = proto_tree_add_item_ret_uint(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, ENC_BIG_ENDIAN, &holdtime);
if(holdtime == 0xFFFF){
proto_item_append_text(ti_hold, " (Infinity)");
}
offset += 2;
break;
}
case 5:
{
proto_tree_add_item(pimopt_tree, hf_pim_group_address_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_group_mask_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_rpt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pimopt_tree, hf_pim_metric_pref, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
}
default:
break;
}
return offset;
}
static gboolean
dissect_pim_addr(proto_tree* tree, tvbuff_t *tvb, int offset, enum pimv2_addrtype at,
const char* label, proto_item** ret_item, int hf_ip4, int hf_ip6, int *advance) {
guint8 af, et, flags, mask_len;
struct e_in6_addr ipv6;
guint32 ipv4;
proto_item* ti = NULL;
int len = 0;
af = tvb_get_guint8(tvb, offset);
if (af != AFNUM_INET && af != AFNUM_INET6) {
return FALSE;
}
et = tvb_get_guint8(tvb, offset + 1);
if (et != 0) {
return FALSE;
}
switch (at) {
case pimv2_unicast:
switch (af) {
case AFNUM_INET:
len = 4;
ipv4 = tvb_get_ipv4(tvb, offset + 2);
if (label)
{
ti = proto_tree_add_ipv4_format(tree, hf_ip4, tvb, offset, 2 + len,
ipv4, "%s: %s", label, tvb_ip_to_str(tvb, offset + 2));
}
else
{
ti = proto_tree_add_ipv4(tree, hf_ip4, tvb, offset, 2 + len, ipv4);
}
break;
case AFNUM_INET6:
len = 16;
tvb_get_ipv6(tvb, offset + 2, &ipv6);
if (label)
{
ti = proto_tree_add_ipv6_format(tree, hf_ip6, tvb, offset, 2 + len,
&ipv6, "%s: %s", label, tvb_ip6_to_str(tvb, offset + 2));
}
else
{
ti = proto_tree_add_ipv6(tree, hf_ip6, tvb, offset, 2 + len, &ipv6);
}
break;
}
*advance = 2 + len;
break;
case pimv2_group:
mask_len = tvb_get_guint8(tvb, offset + 3);
switch (af) {
case AFNUM_INET:
len = 4;
ipv4 = tvb_get_ipv4(tvb, offset + 4);
if (label)
{
ti = proto_tree_add_ipv4_format(tree, hf_ip4, tvb, offset, 4 + len,
ipv4, "%s: %s", label, tvb_ip_to_str(tvb, offset + 4));
}
else
{
ti = proto_tree_add_ipv4(tree, hf_ip4, tvb, offset, 4 + len, ipv4);
}
proto_item_append_text(ti, "/%u", mask_len);
break;
case AFNUM_INET6:
len = 16;
tvb_get_ipv6(tvb, offset + 4, &ipv6);
if (label)
{
ti = proto_tree_add_ipv6_format(tree, hf_ip6, tvb, offset, 4 + len,
&ipv6, "%s: %s", label, tvb_ip6_to_str(tvb, offset + 4));
}
else
{
ti = proto_tree_add_ipv6(tree, hf_ip6, tvb, offset, 4 + len, &ipv6);
}
proto_item_append_text(ti, "/%u", mask_len);
break;
}
*advance = 4 + len;
break;
case pimv2_source:
flags = tvb_get_guint8(tvb, offset + 2);
mask_len = tvb_get_guint8(tvb, offset + 3);
switch (af) {
case AFNUM_INET:
len = 4;
ipv4 = tvb_get_ipv4(tvb, offset + 4);
if (label)
{
ti = proto_tree_add_ipv4_format(tree, hf_ip4, tvb, offset, 4 + len,
ipv4, "%s: %s", label, tvb_ip_to_str(tvb, offset + 4));
}
else
{
ti = proto_tree_add_ipv4_format_value(tree, hf_ip4, tvb, offset, 4 + len, ipv4,
"%s", tvb_ip_to_str(tvb, offset + 4));
}
proto_item_append_text(ti, "/%u", mask_len);
break;
case AFNUM_INET6:
len = 16;
tvb_get_ipv6(tvb, offset + 4, &ipv6);
if (label)
{
ti = proto_tree_add_ipv6_format(tree, hf_ip6, tvb, offset, 4 + len,
&ipv6, "%s: %s", label, tvb_ip6_to_str(tvb, offset + 4));
}
else
{
ti = proto_tree_add_ipv6_format_value(tree, hf_ip6, tvb, offset, 4 + len, &ipv6,
"%s", tvb_ip6_to_str(tvb, offset + 4));
}
proto_item_append_text(ti, "/%u", mask_len);
break;
}
if (flags) {
proto_item_append_text(ti, " (%s%s%s)",
flags & 0x04 ? "S" : "",
flags & 0x02 ? "W" : "",
flags & 0x01 ? "R" : "");
}
*advance = 4 + len;
break;
default:
return FALSE;
}
if (ret_item != NULL)
*ret_item = ti;
return TRUE;
}
static int
dissect_pim(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
int offset = 0;
guint8 pim_typever;
guint8 pim_bidir_subtype = 0;
guint length, pim_length;
guint16 pim_cksum, computed_cksum;
vec_t cksum_vec[4];
guint32 phdr[2];
const char *typestr;
proto_tree *pim_tree = NULL;
proto_item *ti;
proto_tree *pimopt_tree = NULL;
proto_item *tiopt, *ticksum;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PIM");
col_clear(pinfo->cinfo, COL_INFO);
pim_typever = tvb_get_guint8(tvb, 0);
switch (PIM_VER(pim_typever)) {
case 2:
typestr = val_to_str(PIM_TYPE(pim_typever), pimtypevals, "Unknown (%u)");
break;
case 1:
default:
typestr = "Unknown";
break;
}
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "PIMv%d",
PIM_VER(pim_typever));
col_add_str(pinfo->cinfo, COL_INFO, typestr);
ti = proto_tree_add_item(tree, proto_pim, tvb, offset, -1, ENC_NA);
pim_tree = proto_item_add_subtree(ti, ett_pim);
proto_tree_add_item(pim_tree, hf_pim_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pim_tree, hf_pim_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (PIM_TYPE(pim_typever) == PIM_TYPE_DF_ELECT) {
proto_tree_add_item(pim_tree, hf_pim_df_elect_subtype, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pim_tree, hf_pim_df_elect_rsvd, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
pim_bidir_subtype = tvb_get_guint8(tvb,offset);
}
else {
proto_tree_add_item(pim_tree, hf_pim_res_bytes, tvb, offset + 1, 1, ENC_NA);
}
pim_cksum = tvb_get_ntohs(tvb, offset + 2);
ticksum = proto_tree_add_item(pim_tree, hf_pim_cksum, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (PIM_VER(pim_typever) != 2) {
if (tvb_reported_length_remaining(tvb, offset) > 0) {
proto_tree_add_item(pim_tree, hf_pim_option, tvb, offset, -1, ENC_NA);
}
goto done;
}
length = tvb_reported_length(tvb);
if (PIM_TYPE(pim_typever) == 1) {
pim_length = 8;
col_set_writable(pinfo->cinfo, FALSE);
} else {
pim_length = length;
}
if (!pinfo->fragmented && length >= pim_length &&
tvb_captured_length(tvb) >= pim_length) {
switch (pinfo->src.type) {
case AT_IPv4:
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, 0, pim_length);
computed_cksum = in_cksum(&cksum_vec[0], 1);
break;
case AT_IPv6:
SET_CKSUM_VEC_PTR(cksum_vec[0], (const guint8 *)pinfo->src.data, pinfo->src.len);
SET_CKSUM_VEC_PTR(cksum_vec[1], (const guint8 *)pinfo->dst.data, pinfo->dst.len);
phdr[0] = g_htonl(pim_length);
phdr[1] = g_htonl(IP_PROTO_PIM);
SET_CKSUM_VEC_PTR(cksum_vec[2], (const guint8 *)&phdr, 8);
SET_CKSUM_VEC_TVB(cksum_vec[3], tvb, 0, pim_length);
computed_cksum = in_cksum(&cksum_vec[0], 4);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
if (computed_cksum == 0) {
proto_item_append_text(ticksum, " [correct]");
} else {
proto_item_append_text(ticksum, " [incorrect, should be 0x%04x]", in_cksum_shouldbe(pim_cksum, computed_cksum));
}
}
offset += 4;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
tiopt = proto_tree_add_item(pim_tree, hf_pim_option, tvb, offset, -1, ENC_NA);
pimopt_tree = proto_item_add_subtree(tiopt, ett_pim_opts);
} else
goto done;
switch (PIM_TYPE(pim_typever)) {
case PIM_TYPE_HELLO:
{
int opt_count = 0;
while (tvb_reported_length_remaining(tvb, offset) >= 2) {
guint16 hello_opt, opt_len;
guint32 holdtime;
proto_item *opt_item;
proto_item *ti_hold;
proto_tree *opt_tree;
opt_count++;
hello_opt = tvb_get_ntohs(tvb, offset);
opt_len = tvb_get_ntohs(tvb, offset + 2);
opt_tree = proto_tree_add_subtree_format(pimopt_tree, tvb, offset, 4 + opt_len,
ett_pim_opt, &opt_item, "Option %u: %s", hello_opt,
val_to_str(hello_opt, pim_opt_vals, "Unknown: %u"));
proto_tree_add_item(opt_tree, hf_pim_optiontype, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_optionlength, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
switch(hello_opt) {
case PIM_HELLO_HOLD_T:
ti_hold = proto_tree_add_item_ret_uint(opt_tree, hf_pim_holdtime, tvb,
offset+4, 2, ENC_BIG_ENDIAN, &holdtime);
switch(holdtime){
case 0:
proto_item_append_text(ti_hold, " (goodbye)");
proto_item_append_text(opt_item, ": %u (goodbye)", holdtime);
break;
case 0xFFFF:
proto_item_append_text(ti_hold, " (Infinity)");
proto_item_append_text(opt_item, ": %u (Infinity)", holdtime);
break;
default:
proto_item_append_text(opt_item, ": %u", holdtime);
break;
}
break;
case PIM_HELLO_LAN_PRUNE_DELAY:
proto_tree_add_item(opt_tree, hf_pim_t, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_propagation_delay, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_override_interval, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(opt_item,
": T = %u, Propagation Delay = %ums, Override Interval = %ums",
tvb_get_guint8(tvb, offset + 4) & 0x80 ? 1 : 0,
tvb_get_ntohs(tvb, offset + 4) & 0x7fff,
tvb_get_ntohs(tvb, offset + 6));
break;
case PIM_HELLO_DR_PRIORITY:
proto_tree_add_item(opt_tree, hf_pim_dr_priority, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(opt_item, ": %u", tvb_get_ntohl(tvb, offset + 4));
break;
case PIM_HELLO_GEN_ID:
proto_tree_add_item(opt_tree, hf_pim_generation_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(opt_item, ": %u", tvb_get_ntohl(tvb, offset + 4));
break;
case PIM_HELLO_STATE_REFRESH:
proto_tree_add_item(opt_tree, hf_pim_state_refresh_version, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_state_refresh_interval, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_state_refresh_reserved, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(opt_item, ": Version = %u, Interval = %us",
tvb_get_guint8(tvb, offset + 4),
tvb_get_guint8(tvb, offset + 5));
break;
case PIM_HELLO_VAR_ADDR_LST:
case 65001:
{
int i;
proto_tree *sub_tree = NULL;
sub_tree = proto_tree_add_subtree_format(opt_tree, tvb, offset, 4 + opt_len,
ett_pim_opt, NULL, "%sAddress List (%u)",
hello_opt == 65001 ? "old " : "",
hello_opt);
for (i = offset + 4; i < offset + 4 + opt_len; ) {
int advance;
if (!dissect_pim_addr(sub_tree, tvb, i, pimv2_unicast, NULL, NULL,
hf_pim_address_list_ip4, hf_pim_address_list_ip6, &advance))
break;
i += advance;
}
break;
}
case PIM_HELLO_LABEL_PARA:
case PIM_HELLO_BIDIR_CAPA:
case PIM_HELLO_VCI_CAPA:
case PIM_HELLO_VAR_NEIG_LST:
case PIM_HELL0_JOIN_ATTR:
case PIM_HELLO_O_TCP_CAPA:
case PIM_HELLO_O_SCTP_CAPA:
case PIM_HELLO_VAR_POP_COUNT:
case PIM_HELLO_MT_ID:
case PIM_HELLO_INT_ID:
case PIM_HELLO_ECMP_REDIR:
case PIM_HELLO_VPC_PEER_ID:
case PIM_HELLO_DR_LB_CAPA:
case PIM_HELLO_LB_GDR:
default:
if (opt_len)
proto_tree_add_item(opt_tree, hf_pim_optionvalue, tvb,
offset + 4, opt_len, ENC_NA);
break;
}
offset += 4 + opt_len;
}
proto_item_append_text(tiopt, ": %u", opt_count);
break;
}
case PIM_TYPE_REGISTER:
{
guint8 v_hl;
tvbuff_t *next_tvb;
proto_tree *flag_tree;
proto_item *tiflag;
tiflag = proto_tree_add_item(pimopt_tree, hf_pim_register_flag, tvb, offset, 4, ENC_BIG_ENDIAN);
flag_tree = proto_item_add_subtree(tiflag, ett_pim);
proto_tree_add_item(flag_tree, hf_pim_register_flag_border, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(flag_tree, hf_pim_register_flag_null_register, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
next_tvb = tvb_new_subset_remaining(tvb, offset);
v_hl = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pimopt_tree, hf_pim_ip_version, tvb, offset, 1, ENC_BIG_ENDIAN);
switch((v_hl & 0xf0) >> 4) {
case 0:
ti = proto_tree_add_item(pimopt_tree, hf_pim_dummy_header, tvb, offset, -1, ENC_NA);
if (pinfo->src.type == AT_IPv4) {
proto_item_append_text(ti, "IPv4");
proto_tree_add_item(pimopt_tree, hf_pim_source_ip4, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pimopt_tree, hf_pim_group_ip4, tvb, offset + 16, 4, ENC_BIG_ENDIAN);
} else if (pinfo->src.type == AT_IPv6) {
proto_item_append_text(ti, "IPv6");
proto_tree_add_item(pimopt_tree, hf_pim_source_ip6, tvb, offset + 8, 16, ENC_NA);
proto_tree_add_item(pimopt_tree, hf_pim_group_ip6, tvb, offset + 8 + 16, 16, ENC_NA);
} else
proto_item_append_text(ti, "for an unknown protocol");
break;
case 4:
if (use_main_tree) {
call_dissector(ip_handle, next_tvb, pinfo, tree);
} else {
call_dissector(ip_handle, next_tvb, pinfo, pimopt_tree);
}
break;
case 6:
if (use_main_tree) {
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
} else {
call_dissector(ipv6_handle, next_tvb, pinfo, pimopt_tree);
}
break;
default:
break;
}
break;
}
case PIM_TYPE_REGISTER_STOP:
{
int advance;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_group, NULL, NULL,
hf_pim_group_ip4, hf_pim_group_ip6, &advance))
break;
offset += advance;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast, NULL, NULL,
hf_pim_source_ip4, hf_pim_source_ip6, &advance))
break;
break;
}
case PIM_TYPE_JOIN_PRUNE:
case PIM_TYPE_GRAFT:
case PIM_TYPE_GRAFT_ACK:
{
int advance;
int off;
int ngroup, i, njoin, nprune, j;
guint32 holdtime;
proto_tree *grouptree = NULL;
proto_item *tigroup;
proto_tree *subtree = NULL;
proto_item *tisub;
proto_item *ti_hold;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast, NULL, NULL,
hf_pim_upstream_neighbor_ip4, hf_pim_upstream_neighbor_ip6, &advance))
break;
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_res_bytes, tvb, offset, 1, ENC_NA);
offset += 1;
ngroup = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pimopt_tree, hf_pim_numgroups, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti_hold = proto_tree_add_item_ret_uint(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, ENC_BIG_ENDIAN, &holdtime);
if(holdtime == 0xFFFF){
proto_item_append_text(ti_hold, " (Infinity)");
}
offset += 2;
for (i = 0; i < ngroup; i++) {
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_group,
wmem_strdup_printf(wmem_packet_scope(), "Group %d", i), &tigroup,
hf_pim_group_ip4, hf_pim_group_ip6, &advance))
goto breakbreak3;
grouptree = proto_item_add_subtree(tigroup, ett_pim);
offset += advance;
njoin = tvb_get_ntohs(tvb, offset);
nprune = tvb_get_ntohs(tvb, offset + 2);
tisub = proto_tree_add_item(grouptree, hf_pim_numjoins, tvb,
offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(tisub, ett_pim);
off = offset + 4;
for (j = 0; j < njoin; j++) {
if (!dissect_pim_addr(subtree, tvb, off, pimv2_source, NULL, NULL,
hf_pim_join_ip4, hf_pim_join_ip6, &advance))
goto breakbreak3;
off += advance;
}
tisub = proto_tree_add_item(grouptree, hf_pim_numprunes, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(tisub, ett_pim);
for (j = 0; j < nprune; j++) {
if (!dissect_pim_addr(subtree, tvb, off, pimv2_source, NULL, NULL,
hf_pim_prune_ip4, hf_pim_prune_ip6, &advance))
goto breakbreak3;
off += advance;
}
offset = off;
}
breakbreak3:
break;
}
case PIM_TYPE_BOOTSTRAP:
{
int advance;
int i, j;
int frpcnt;
guint32 holdtime;
proto_tree *grouptree = NULL;
proto_item *tigroup;
proto_item *ti_hold;
proto_tree_add_item(pimopt_tree, hf_pim_fragment_tag, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pimopt_tree, hf_pim_hash_mask_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pimopt_tree, hf_pim_bsr_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast, NULL, NULL,
hf_pim_bsr_ip4, hf_pim_bsr_ip6, &advance))
break;
offset += advance;
for (i = 0; tvb_reported_length_remaining(tvb, offset) > 0; i++) {
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_group,
wmem_strdup_printf(wmem_packet_scope(), "Group %d", i), &tigroup,
hf_pim_group_ip4, hf_pim_group_ip6, &advance))
goto breakbreak4;
grouptree = proto_item_add_subtree(tigroup, ett_pim);
offset += advance;
proto_tree_add_item(grouptree, hf_pim_rp_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
frpcnt = tvb_get_guint8(tvb, offset);
proto_tree_add_item(grouptree, hf_pim_frp_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 3;
for (j = 0; j < frpcnt; j++) {
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast,
wmem_strdup_printf(wmem_packet_scope(), "RP %d", j), NULL,
hf_pim_rp_ip4, hf_pim_rp_ip6, &advance))
goto breakbreak4;
offset += advance;
ti_hold = proto_tree_add_item_ret_uint(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, ENC_BIG_ENDIAN, &holdtime);
if(holdtime == 0xFFFF){
proto_item_append_text(ti_hold, " (Infinity)");
}
offset += 2;
proto_tree_add_item(grouptree, hf_pim_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pim_tree, hf_pim_res_bytes, tvb, offset, 1, ENC_NA);
offset += 1;
}
}
breakbreak4:
break;
}
case PIM_TYPE_ASSERT:
{
int advance;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_group,
NULL, NULL,
hf_pim_group_ip4, hf_pim_group_ip6, &advance))
break;
offset += advance;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast,
NULL, NULL,
hf_pim_source_ip4, hf_pim_source_ip6, &advance))
break;
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_rpt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pimopt_tree, hf_pim_metric_pref, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
}
case PIM_TYPE_CAND_RP_ADV:
{
int advance;
int pfxcnt;
guint32 holdtime;
int i;
proto_item *ti_hold;
pfxcnt = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pimopt_tree, hf_pim_prefix_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pimopt_tree, hf_pim_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti_hold = proto_tree_add_item_ret_uint(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, ENC_BIG_ENDIAN, &holdtime);
if(holdtime == 0xFFFF){
proto_item_append_text(ti_hold, " (Infinity)");
}
offset += 2;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast,
NULL, NULL,
hf_pim_rp_ip4, hf_pim_rp_ip6, &advance))
break;
offset += advance;
for (i = 0; i < pfxcnt; i++) {
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_group,
wmem_strdup_printf(wmem_packet_scope(), "Group %d", i), NULL,
hf_pim_group_ip4, hf_pim_group_ip6, &advance))
goto breakbreak8;
offset += advance;
}
breakbreak8:
break;
}
case PIM_TYPE_STATE_REFRESH:
{
int advance;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_group,
NULL, NULL,
hf_pim_group_ip4, hf_pim_group_ip6, &advance))
break;
offset += advance;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast,
NULL, NULL,
hf_pim_source_ip4, hf_pim_source_ip6, &advance))
break;
offset += advance;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast,
NULL, NULL,
hf_pim_originator_ip4, hf_pim_originator_ip6, &advance))
break;
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_rpt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pimopt_tree, hf_pim_metric_pref, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_mask_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pimopt_tree, hf_pim_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pimopt_tree, hf_pim_prune_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pimopt_tree, hf_pim_prune_now, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pimopt_tree, hf_pim_assert_override, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pimopt_tree, hf_pim_interval, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
case PIM_TYPE_DF_ELECT:
{
int advance;
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast,
NULL, NULL,
hf_pim_rp_ip4, hf_pim_rp_ip6, &advance))
break;
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_df_metric_pref, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
switch(PIM_BIDIR_SUBTYPE(pim_bidir_subtype)) {
case PIM_BDIR_DF_BACKOFF :
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast,
NULL, NULL,
hf_pim_bd_bo_offer_ip4, hf_pim_bd_bo_offer_ip6, &advance))
break;
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_bd_offer_metric_pref, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_bd_offer_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_bd_offer_interval, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case PIM_BDIR_DF_PASS:
if (!dissect_pim_addr(pimopt_tree, tvb, offset, pimv2_unicast,
NULL, NULL,
hf_pim_bd_pass_ip4, hf_pim_bd_pass_ip6, &advance))
break;
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_bd_pass_metric_pref, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_bd_pass_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
}
}
default:
break;
}
done:
return tvb_captured_length(tvb);
}
void
proto_register_pim(void)
{
static hf_register_info hf[] =
{
{ &hf_pim_version,
{ "Version", "pim.version",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_pim_type,
{ "Type", "pim.type",
FT_UINT8, BASE_DEC, VALS(pimtypevals), 0x0f,
NULL, HFILL }
},
{ &hf_pim_df_elect_subtype,
{ "DF Subtype", "pim.df_elect.subtype",
FT_UINT8, BASE_DEC, VALS(pimbdirdfvals), 0xf0,
NULL, HFILL}
},
{ &hf_pim_df_elect_rsvd,
{ "DF reserved", "pim.df_elect.rsvd",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL}
},
{ &hf_pim_igmp_type,
{ "Type", "pim.igmp_type",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_code,
{ "Code", "pim.code",
FT_UINT8, BASE_DEC, VALS(pim_type1_vals), 0x0,
NULL, HFILL }
},
{ &hf_pim_cksum,
{ "Checksum", "pim.cksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_res_bytes,
{ "Reserved byte(s)", "pim.res_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_option,
{ "PIM Options", "pim.option",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_optiontype,
{ "Type", "pim.optiontype",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_optionlength,
{ "Length", "pim.optionlength",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_optionvalue,
{ "Unknown", "pim.optionvalue",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_register_flag,
{ "Flags", "pim.register_flag",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_register_flag_border,
{ "Border", "pim.register_flag.border",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x80000000,
NULL, HFILL }
},
{ &hf_pim_register_flag_null_register,
{ "Null-Register", "pim.register_flag.null_register",
FT_BOOLEAN, 32, TFS(&tfs_yes_no), 0x40000000,
NULL, HFILL }
},
{ &hf_pim_mode,
{ "Mode", "pim.mode",
FT_UINT8, BASE_DEC, VALS(pimv1_modevals), 0xf0,
NULL, HFILL }
},
{ &hf_pim_holdtime,
{ "Holdtime", "pim.holdtime",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The amount of time a receiver must keep the neighbor "
"reachable, in seconds.", HFILL }
},
{ &hf_pim_numgroups,
{ "Num Groups", "pim.numgroups",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of multicast group sets contained in the message.",
HFILL }
},
{ &hf_pim_numjoins,
{ "Num Joins", "pim.numjoins",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of joined sources.", HFILL }
},
{ &hf_pim_numprunes,
{ "Num Prunes", "pim.numprunes",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of pruned sources.", HFILL }
},
{ &hf_pim_t,
{ "T", "pim.t",
FT_BOOLEAN, 8, NULL, 0x80,
"Specifies the ability of the sending router to disable joins "
"suppression.", HFILL }
},
{ &hf_pim_propagation_delay,
{ "Propagation Delay", "pim.propagation_delay",
FT_UINT16, BASE_DEC, NULL, 0x07fff,
"Units are milli-seconds", HFILL }
},
{ &hf_pim_override_interval,
{ "Override Interval", "pim.override_interval",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Units are milli-seconds", HFILL }
},
{ &hf_pim_dr_priority,
{ "DR Priority", "pim.dr_priority",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_generation_id,
{ "Generation ID", "pim.generation_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_state_refresh_version,
{ "Version", "pim.state_refresh_version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_state_refresh_interval,
{ "Interval", "pim.state_refresh_interval",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Units in seconds.", HFILL }
},
{ &hf_pim_state_refresh_reserved,
{ "Reserved", "pim.state_refresh_reserved",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_rpt,
{ "RP Tree", "pim.rpt",
FT_BOOLEAN, 8, NULL, 0x80,
"Set to 1 for assert(*,G) messages and 0 for assert(S,G) "
"messages.", HFILL }
},
{ &hf_pim_metric_pref,
{ "Metric Preference", "pim.metric_pref",
FT_UINT32, BASE_DEC, NULL, 0x7fffffff,
NULL, HFILL }
},
{ &hf_pim_df_metric_pref,
{ "DF Metric Preference", "pim.metric_pref",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_metric,
{ "Metric", "pim.metric",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_prune_indicator,
{ "Prune indicator", "pim.prune_indicator",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x80,
NULL, HFILL }
},
{ &hf_pim_prune_now,
{ "Prune now", "pim.prune_now",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x40,
NULL, HFILL }
},
{ &hf_pim_assert_override,
{ "Assert override", "pim.assert_override",
FT_BOOLEAN, 8, TFS(&tfs_set_notset), 0x20,
NULL, HFILL }
},
{ &hf_pim_ip_version,
{ "IP Version", "pim.ip_version",
FT_UINT8, BASE_DEC, VALS(pim_ip_version_vals), 0xF0,
NULL, HFILL }
},
{ &hf_pim_dummy_header,
{ "Dummy Header", "pim.dummy_header",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_source_ip4,
{ "Source", "pim.source",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_source_ip6,
{ "Source", "pim.source_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_group_ip4,
{ "Group", "pim.group",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_group_mask_ip4,
{ "Mask", "pim.group_mask",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_group_ip6,
{ "Group", "pim.group_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_upstream_neighbor_ip4,
{ "Upstream-neighbor", "pim.upstream_neighbor",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_upstream_neighbor_ip6,
{ "Upstream-neighbor", "pim.upstream_neighbor_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_join_ip4,
{ "IP address", "pim.join_ip",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_join_ip6,
{ "IP address", "pim.join_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_prune_ip4,
{ "IP address", "pim.prune_ip",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_prune_ip6,
{ "IP address", "pim.prune_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_address_list_ip4,
{ "Address", "pim.address_list",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_address_list_ip6,
{ "Address", "pim.address_list_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bsr_ip4,
{ "BSR", "pim.bsr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bsr_ip6,
{ "BSR", "pim.bsr_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_rp_ip4,
{ "RP", "pim.rp",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_rp_ip6,
{ "RP", "pim.rp_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_originator_ip4,
{ "Originator", "pim.originator",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_originator_ip6,
{ "Originator", "pim.originator_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_group_address_ip4,
{ "Group Address", "pim.group_address",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_pass_ip4,
{ "New Winner IP", "pim.bidir_winner_ip4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_pass_ip6,
{ "New Winner IP", "pim.bidir_winner_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_pass_metric_pref,
{ "Winner Metric Preference", "pim.bidir_win_metric_pref",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_pass_metric,
{ "Winner Metric", "pim.bidir_win_metric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_bo_offer_ip4,
{ "Offering IP", "pim.bidir_offering_ip4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_bo_offer_ip6,
{ "Offering IP", "pim.bidir_offering_ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_offer_metric_pref,
{ "Offering Metric Preference", "pim.bidir_off_metric_pref",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_offer_metric,
{ "Offering Metric", "pim.bidir_off_metric",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_bd_offer_interval,
{ "Offering interval (ms)", "pim.bidir_offering_interval",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_pim_fragment_tag,
{ "Fragment tag", "pim.fragment_tag",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_hash_mask_len,
{ "Hash mask len", "pim.hash_mask_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_bsr_priority,
{ "BSR priority", "pim.bsr_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_rp_count,
{ "RP count", "pim.rp_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_frp_count,
{ "FRP count", "pim.frp_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_priority,
{ "Priority", "pim.priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_prefix_count,
{ "Prefix-count", "pim.prefix_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_src_flags_a,
{ "Annotated", "pim.src_flags.a",
FT_UINT8, BASE_DEC, NULL, 0x08,
NULL, HFILL }
},
{ &hf_pim_src_flags_s,
{ "Sparse", "pim.src_flags.s",
FT_UINT8, BASE_DEC, NULL, 0x04,
NULL, HFILL }
},
{ &hf_pim_src_flags_w,
{ "WC", "pim.src_flags.w",
FT_UINT8, BASE_DEC, NULL, 0x02,
NULL, HFILL }
},
{ &hf_pim_src_flags_r,
{ "RP", "pim.src_flags.r",
FT_UINT8, BASE_DEC, NULL, 0x01,
NULL, HFILL }
},
{ &hf_pim_src_flags_rsv,
{ "Reserved", "pim.src_flags.rsv",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_pim_mask_len,
{ "Masklen", "pim.mask_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_addr_len,
{ "Address Len", "pim.addr_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_ttl,
{ "TTL", "pim.ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_pim_interval,
{ "Interval", "pim.interval",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_pim,
&ett_pim_opts,
&ett_pim_opt
};
module_t *pim_module;
proto_pim = proto_register_protocol("Protocol Independent Multicast",
"PIM", "pim");
proto_register_field_array(proto_pim, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pim_module = prefs_register_protocol(proto_pim, NULL);
prefs_register_bool_preference(pim_module, "payload_tree",
"PIM payload shown on main tree",
"Whether the PIM payload is shown off of the main tree or encapsulated within the PIM options",
&use_main_tree);
}
void
proto_reg_handoff_pim(void)
{
dissector_handle_t pim_handle, pimv1_handle;
pim_handle = create_dissector_handle(dissect_pim, proto_pim);
dissector_add_uint("ip.proto", IP_PROTO_PIM, pim_handle);
pimv1_handle = create_dissector_handle(dissect_pimv1, proto_pim);
dissector_add_uint("igmp.type", IGMP_V1_PIM_ROUTING_MESSAGE, pimv1_handle);
ip_handle = find_dissector_add_dependency("ip", proto_pim);
ipv6_handle = find_dissector_add_dependency("ipv6", proto_pim);
}
