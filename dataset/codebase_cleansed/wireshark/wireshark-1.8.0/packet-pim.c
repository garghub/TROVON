static const char *
dissect_pimv1_addr(tvbuff_t *tvb, int offset) {
guint16 flags_masklen;
flags_masklen = tvb_get_ntohs(tvb, offset);
if (flags_masklen & 0x0180) {
return ep_strdup_printf("(%s%s%s) ",
flags_masklen & 0x0100 ? "S" : "",
flags_masklen & 0x0080 ? "W" : "",
flags_masklen & 0x0040 ? "R" : "");
} else {
return ep_strdup_printf("%s/%u",
tvb_ip_to_str(tvb, offset + 2), flags_masklen & 0x3f);
}
}
int
dissect_pimv1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset) {
guint8 pim_type;
guint8 pim_ver;
guint length, pim_length;
guint16 pim_cksum, computed_cksum;
vec_t cksum_vec[1];
proto_tree *pim_tree = NULL;
proto_item *ti;
proto_tree *pimopt_tree = NULL;
proto_item *tiopt;
if (!proto_is_protocol_enabled(find_protocol_by_id(proto_pim))) {
return offset+tvb_length_remaining(tvb, offset);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PIMv1");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_pim, tvb, offset, -1, ENC_NA);
pim_tree = proto_item_add_subtree(ti, ett_pim);
proto_tree_add_text(pim_tree, tvb, offset, 1,
"Type: PIM (0x14)");
offset += 1;
pim_type = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(pim_type, type1vals, "Unknown (%u)"));
proto_tree_add_uint(pim_tree, hf_pim_code, tvb, offset, 1, pim_type);
offset += 1;
pim_cksum = tvb_get_ntohs(tvb, offset);
pim_ver = PIM_VER(tvb_get_guint8(tvb, offset + 2));
if (pim_ver != 1) {
proto_tree_add_uint(pim_tree, hf_pim_cksum, tvb,
offset, 2, pim_cksum);
offset += 2;
proto_tree_add_item(pim_tree, hf_pim_version, tvb, offset, 1, ENC_BIG_ENDIAN);
return offset+tvb_length_remaining(tvb, offset);
}
length = tvb_length(tvb);
if (pim_type == 1) {
pim_length = 8;
col_set_writable(pinfo->cinfo, FALSE);
} else {
pim_length = tvb_reported_length(tvb);
}
if (!pinfo->fragmented && length >= pim_length) {
cksum_vec[0].ptr = tvb_get_ptr(tvb, 0, pim_length);
cksum_vec[0].len = pim_length;
computed_cksum = in_cksum(&cksum_vec[0], 1);
if (computed_cksum == 0) {
proto_tree_add_uint_format(pim_tree, hf_pim_cksum, tvb,
offset, 2, pim_cksum,
"Checksum: 0x%04x [correct]",
pim_cksum);
} else {
proto_tree_add_uint_format(pim_tree, hf_pim_cksum, tvb,
offset, 2, pim_cksum,
"Checksum: 0x%04x [incorrect, should be 0x%04x]",
pim_cksum, in_cksum_shouldbe(pim_cksum, computed_cksum));
}
} else {
proto_tree_add_uint(pim_tree, hf_pim_cksum, tvb,
offset, 2, pim_cksum);
}
offset += 2;
proto_tree_add_item(pim_tree, hf_pim_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset += 3;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
tiopt = proto_tree_add_text(pim_tree, tvb, offset, -1, "PIM options");
pimopt_tree = proto_item_add_subtree(tiopt, ett_pim_opts);
} else
goto done;
switch (pim_type) {
case 0:
{
guint16 holdtime;
proto_tree_add_item(pimopt_tree, hf_pim_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
holdtime = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, holdtime,
"Holdtime: %us %s", holdtime,
holdtime == 0xffff ? "(infinity)": "");
offset += 2;
break;
}
case 1:
{
guint8 v_hl;
tvbuff_t *next_tvb;
next_tvb = tvb_new_subset_remaining(tvb, offset);
v_hl = tvb_get_guint8(tvb, offset);
switch((v_hl & 0xf0) >> 4) {
case 0:
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_text(pimopt_tree, tvb, offset, -1,
"IPv4 dummy header");
proto_tree_add_text(pimopt_tree, tvb, offset + 12, 4,
"Source: %s",
tvb_ip_to_str(tvb, offset + 12));
proto_tree_add_text(pimopt_tree, tvb, offset + 16, 4,
"Group: %s",
tvb_ip_to_str(tvb, offset + 16));
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_text(pimopt_tree, tvb, offset, -1,
"IPv6 dummy header");
proto_tree_add_text(pimopt_tree, tvb,
offset + 8, 16,
"Source: %s",
tvb_ip6_to_str(tvb, offset + 8));
proto_tree_add_text(pimopt_tree, tvb,
offset + 8 + 16, 16,
"Group: %s",
tvb_ip6_to_str(tvb, offset + 8));
} else
proto_tree_add_text(pimopt_tree, tvb, offset, -1,
"Dummy header for an unknown protocol");
break;
case 4:
#if 0
call_dissector(ip_handle, next_tvb, pinfo, tree);
#else
call_dissector(ip_handle, next_tvb, pinfo, pimopt_tree);
#endif
break;
case 6:
#if 0
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
#else
call_dissector(ipv6_handle, next_tvb, pinfo, pimopt_tree);
#endif
break;
default:
proto_tree_add_text(pimopt_tree, tvb, offset, -1,
"Unknown IP version %d", (v_hl & 0xf0) >> 4);
break;
}
break;
}
case 2:
{
proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Group: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Source: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
break;
}
case 3:
case 6:
case 7:
{
int off;
const char *s;
int ngroup, i, njoin, nprune, j;
guint16 holdtime;
guint8 mask_len;
guint8 adr_len;
proto_tree *grouptree = NULL;
proto_item *tigroup;
proto_tree *subtree = NULL;
proto_item *tisub;
proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Upstream-neighbor: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
offset += 2;
holdtime = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, holdtime,
"Holdtime: %us %s", holdtime,
holdtime == 0xffff ? "(infinity)": "");
offset += 2;
offset += 1;
mask_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"Mask length: %u", mask_len);
offset += 1;
adr_len = tvb_get_guint8(tvb, offset);
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"Address length: %u", adr_len);
offset += 1;
ngroup = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pimopt_tree, hf_pim_numgroups, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
for (i = 0; i < ngroup; i++) {
tigroup = proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Group %d: %s", i,
tvb_ip_to_str(tvb, offset));
grouptree = proto_item_add_subtree(tigroup, ett_pim);
offset += 4;
proto_tree_add_text(grouptree, tvb, offset, 4,
"Group %d Mask: %s", i,
tvb_ip_to_str(tvb, offset));
offset += 4;
njoin = tvb_get_ntohs(tvb, offset);
nprune = tvb_get_ntohs(tvb, offset + 2);
tisub = proto_tree_add_item(grouptree, hf_pim_numjoins, tvb,
offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(tisub, ett_pim);
off = offset + 4;
for (j = 0; j < njoin; j++) {
s = dissect_pimv1_addr(tvb, off);
proto_tree_add_text(subtree, tvb, off, 6,
"IP address: %s", s);
off += 6;
}
tisub = proto_tree_add_item(grouptree, hf_pim_numprunes, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(tisub, ett_pim);
for (j = 0; j < nprune; j++) {
s = dissect_pimv1_addr(tvb, off);
proto_tree_add_text(subtree, tvb, off, 6,
"IP address: %s", s);
off += 6;
}
offset = off;
}
break;
}
case 4:
{
guint16 holdtime;
proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Group Address: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Group Mask: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"RP Address: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
offset += 2;
holdtime = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, holdtime,
"Holdtime: %us %s", holdtime,
holdtime == 0xffff ? "(infinity)": "");
offset += 2;
break;
}
case 5:
{
guint32 pref;
proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Group Address: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Group Mask: %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_rpt, tvb, offset, 1, ENC_BIG_ENDIAN);
pref = tvb_get_ntohl(tvb, offset) & 0x7fffffff;
proto_tree_add_uint_format(pimopt_tree, hf_pim_metric_pref, tvb,
offset, 4, pref,
"Metric Preference: %u", pref);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
}
default:
break;
}
done:;
return offset+tvb_length_remaining(tvb, offset);
}
static const char *
dissect_pim_addr(tvbuff_t *tvb, int offset, enum pimv2_addrtype at,
int *advance) {
emem_strbuf_t *strbuf;
guint8 af;
guint8 et;
guint8 flags;
guint8 mask_len;
int len = 0;
af = tvb_get_guint8(tvb, offset);
if (af != AFNUM_INET && af != AFNUM_INET6) {
return NULL;
}
et = tvb_get_guint8(tvb, offset + 1);
if (et != 0) {
return NULL;
}
strbuf = ep_strbuf_new_label(NULL);
switch (at) {
case pimv2_unicast:
switch (af) {
case AFNUM_INET:
len = 4;
ep_strbuf_printf(strbuf, "%s", tvb_ip_to_str(tvb, offset + 2));
break;
case AFNUM_INET6:
len = 16;
ep_strbuf_printf(strbuf, "%s", tvb_ip6_to_str(tvb, offset + 2));
break;
}
if (advance)
*advance = 2 + len;
break;
case pimv2_group:
mask_len = tvb_get_guint8(tvb, offset + 3);
switch (af) {
case AFNUM_INET:
len = 4;
ep_strbuf_printf(strbuf, "%s/%u",
tvb_ip_to_str(tvb, offset + 4), mask_len);
break;
case AFNUM_INET6:
len = 16;
ep_strbuf_printf(strbuf, "%s/%u",
tvb_ip6_to_str(tvb, offset + 4), mask_len);
break;
}
if (advance)
*advance = 4 + len;
break;
case pimv2_source:
flags = tvb_get_guint8(tvb, offset + 2);
mask_len = tvb_get_guint8(tvb, offset + 3);
switch (af) {
case AFNUM_INET:
len = 4;
ep_strbuf_printf(strbuf, "%s/%u",
tvb_ip_to_str(tvb, offset + 4), mask_len);
break;
case AFNUM_INET6:
len = 16;
ep_strbuf_printf(strbuf, "%s/%u",
tvb_ip6_to_str(tvb, offset + 4), mask_len);
break;
}
if (flags) {
ep_strbuf_append_printf(strbuf,
" (%s%s%s)",
flags & 0x04 ? "S" : "",
flags & 0x02 ? "W" : "",
flags & 0x01 ? "R" : "");
}
if (advance)
*advance = 4 + len;
break;
default:
return NULL;
}
return strbuf->str;
}
static void
dissect_pim(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
int offset = 0;
guint8 pim_typever;
guint length, pim_length;
guint16 pim_cksum, computed_cksum;
vec_t cksum_vec[4];
guint32 phdr[2];
const char *typestr;
proto_tree *pim_tree = NULL;
proto_item *ti;
proto_tree *pimopt_tree = NULL;
proto_item *tiopt;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PIM");
col_clear(pinfo->cinfo, COL_INFO);
pim_typever = tvb_get_guint8(tvb, 0);
switch (PIM_VER(pim_typever)) {
case 2:
typestr = val_to_str(PIM_TYPE(pim_typever), type2vals, "Unknown (%u)");
break;
case 1:
default:
typestr = "Unknown";
break;
}
if (check_col(pinfo->cinfo, COL_PROTOCOL)) {
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "PIMv%d",
PIM_VER(pim_typever));
}
if (check_col(pinfo->cinfo, COL_INFO))
col_add_str(pinfo->cinfo, COL_INFO, typestr);
ti = proto_tree_add_item(tree, proto_pim, tvb, offset, -1, ENC_NA);
pim_tree = proto_item_add_subtree(ti, ett_pim);
proto_tree_add_item(pim_tree, hf_pim_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pim_tree, hf_pim_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pim_tree, hf_pim_res_bytes, tvb, offset + 1, 1, ENC_NA);
pim_cksum = tvb_get_ntohs(tvb, offset + 2);
length = tvb_length(tvb);
if (PIM_VER(pim_typever) == 2) {
if (PIM_TYPE(pim_typever) == 1) {
pim_length = 8;
col_set_writable(pinfo->cinfo, FALSE);
} else {
pim_length = tvb_reported_length(tvb);
}
} else {
pim_length = 0;
}
if (!pinfo->fragmented && length >= pim_length) {
switch (pinfo->src.type) {
case AT_IPv4:
cksum_vec[0].ptr = tvb_get_ptr(tvb, 0, pim_length);
cksum_vec[0].len = pim_length;
computed_cksum = in_cksum(&cksum_vec[0], 1);
break;
case AT_IPv6:
cksum_vec[0].ptr = pinfo->src.data;
cksum_vec[0].len = pinfo->src.len;
cksum_vec[1].ptr = pinfo->dst.data;
cksum_vec[1].len = pinfo->dst.len;
cksum_vec[2].ptr = (const guint8 *)&phdr;
phdr[0] = g_htonl(pim_length);
phdr[1] = g_htonl(IP_PROTO_PIM);
cksum_vec[2].len = 8;
cksum_vec[3].ptr = tvb_get_ptr(tvb, 0, pim_length);
cksum_vec[3].len = pim_length;
computed_cksum = in_cksum(&cksum_vec[0], 4);
break;
default:
computed_cksum = 0;
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
if (computed_cksum == 0) {
proto_tree_add_uint_format(pim_tree, hf_pim_cksum, tvb,
offset + 2, 2, pim_cksum,
"Checksum: 0x%04x [correct]",
pim_cksum);
} else {
proto_tree_add_uint_format(pim_tree, hf_pim_cksum, tvb,
offset + 2, 2, pim_cksum,
"Checksum: 0x%04x [incorrect, should be 0x%04x]",
pim_cksum, in_cksum_shouldbe(pim_cksum, computed_cksum));
}
} else {
proto_tree_add_uint(pim_tree, hf_pim_cksum, tvb,
offset + 2, 2, pim_cksum);
}
offset += 4;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
tiopt = proto_tree_add_text(pim_tree, tvb, offset, -1, "PIM options");
pimopt_tree = proto_item_add_subtree(tiopt, ett_pim_opts);
} else
goto done;
if (PIM_VER(pim_typever) != 2)
goto done;
switch (PIM_TYPE(pim_typever)) {
case 0:
{
int opt_count = 0;
while (tvb_reported_length_remaining(tvb, offset) >= 2) {
guint16 hello_opt, opt_len;
guint16 opt_value;
proto_item *opt_item;
proto_tree *opt_tree;
opt_count++;
hello_opt = tvb_get_ntohs(tvb, offset);
opt_len = tvb_get_ntohs(tvb, offset + 2);
opt_item = proto_tree_add_text(pimopt_tree, tvb, offset, 4 + opt_len,
"Option %u: %s", hello_opt,
val_to_str(hello_opt, pim_opt_vals, "Unknown: %u"));
opt_tree = proto_item_add_subtree(opt_item, ett_pim_opt);
proto_tree_add_item(opt_tree, hf_pim_optiontype, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_optionlength, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
switch(hello_opt) {
case 1:
opt_value = tvb_get_ntohs(tvb, offset + 4);
proto_tree_add_uint_format(opt_tree, hf_pim_holdtime, tvb,
offset + 4, opt_len, opt_value,
"Holdtime: %us %s", opt_value, opt_value == 0 ? "(goodbye)" :
opt_value == 0xffff ? "(infinity)": "");
proto_item_append_text(opt_item, ": %us %s", opt_value,
opt_value == 0 ? "(goodbye)" :
opt_value == 0xffff ? "(infinity)": "");
break;
case 2:
proto_tree_add_item(opt_tree, hf_pim_t, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_propagation_delay, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_override_interval, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(opt_item,
": T = %u, Propagation Delay = %ums, Override Interval = %ums",
tvb_get_guint8(tvb, offset + 4) & 0x80 ? 1 : 0,
tvb_get_ntohs(tvb, offset + 4) & 0x7fff,
tvb_get_ntohs(tvb, offset + 6));
break;
case 19:
proto_tree_add_item(opt_tree, hf_pim_dr_priority, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(opt_item, ": %u", tvb_get_ntohl(tvb, offset + 4));
break;
case 20:
proto_tree_add_item(opt_tree, hf_pim_generation_id, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_item_append_text(opt_item, ": %u", tvb_get_ntohl(tvb, offset + 4));
break;
case 21:
proto_tree_add_item(opt_tree, hf_pim_state_refresh_version, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_state_refresh_interval, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(opt_tree, hf_pim_state_refresh_reserved, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_item_append_text(opt_item, ": Version = %u, Interval = %us",
tvb_get_guint8(tvb, offset + 4),
tvb_get_guint8(tvb, offset + 5));
break;
case 24:
case 65001:
{
int i;
proto_tree *sub_tree = NULL;
proto_item *addrlist_option;
addrlist_option = proto_tree_add_text(opt_tree, tvb, offset, 4 + opt_len,
"%sAddress List (%u)",
hello_opt == 65001 ? "old " : "",
hello_opt);
sub_tree = proto_item_add_subtree(addrlist_option, ett_pim_opt);
for (i = offset + 4; i < offset + 4 + opt_len; ) {
int advance;
const char *s;
s = dissect_pim_addr(tvb, i, pimv2_unicast, &advance);
if (s == NULL)
break;
proto_tree_add_text(sub_tree, tvb, offset,
advance, "Address: %s", s);
i += advance;
}
break;
}
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
case 1:
{
guint32 flags;
guint8 v_hl;
tvbuff_t *next_tvb;
proto_tree *flag_tree = NULL;
proto_item *tiflag;
flags = tvb_get_ntohl(tvb, offset);
tiflag = proto_tree_add_text(pimopt_tree, tvb, offset, 4,
"Flags: 0x%08x", flags);
flag_tree = proto_item_add_subtree(tiflag, ett_pim);
proto_tree_add_text(flag_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(flags, 0x80000000, 32,
"Border", "Not border"));
proto_tree_add_text(flag_tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(flags, 0x40000000, 32,
"Null-Register", "Not Null-Register"));
offset += 4;
next_tvb = tvb_new_subset_remaining(tvb, offset);
v_hl = tvb_get_guint8(tvb, offset);
switch((v_hl & 0xf0) >> 4) {
case 0:
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_text(pimopt_tree, tvb, offset, -1,
"IPv4 dummy header");
proto_tree_add_text(pimopt_tree, tvb, offset + 12, 4,
"Source: %s",
tvb_ip_to_str(tvb, offset + 12));
proto_tree_add_text(pimopt_tree, tvb, offset + 16, 4,
"Group: %s",
tvb_ip_to_str(tvb, offset + 16));
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_text(pimopt_tree, tvb, offset, -1,
"IPv6 dummy header");
proto_tree_add_text(pimopt_tree, tvb,
offset + 8, 16,
"Source: %s",
tvb_ip6_to_str(tvb, offset + 8));
proto_tree_add_text(pimopt_tree, tvb,
offset + 8 + 16, 16,
"Group: %s",
tvb_ip6_to_str(tvb, offset + 8 + 16));
} else
proto_tree_add_text(pimopt_tree, tvb, offset, -1,
"Dummy header for an unknown protocol");
break;
case 4:
#if 0
call_dissector(ip_handle, next_tvb, pinfo, tree);
#else
call_dissector(ip_handle, next_tvb, pinfo, pimopt_tree);
#endif
break;
case 6:
#if 0
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
#else
call_dissector(ipv6_handle, next_tvb, pinfo, pimopt_tree);
#endif
break;
default:
proto_tree_add_text(pimopt_tree, tvb, offset, -1,
"Unknown IP version %d", (v_hl & 0xf0) >> 4);
break;
}
break;
}
case 2:
{
int advance;
const char *s;
s = dissect_pim_addr(tvb, offset, pimv2_group, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance, "Group: %s", s);
offset += advance;
s = dissect_pim_addr(tvb, offset, pimv2_unicast, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance, "Source: %s", s);
break;
}
case 3:
case 6:
case 7:
{
int advance;
int off;
const char *s;
int ngroup, i, njoin, nprune, j;
guint16 holdtime;
proto_tree *grouptree = NULL;
proto_item *tigroup;
proto_tree *subtree = NULL;
proto_item *tisub;
s = dissect_pim_addr(tvb, offset, pimv2_unicast, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance,
"Upstream-neighbor: %s", s);
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_res_bytes, tvb, offset, 1, ENC_NA);
offset += 1;
ngroup = tvb_get_guint8(tvb, offset);
proto_tree_add_item(pimopt_tree, hf_pim_numgroups, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
holdtime = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, holdtime,
"Holdtime: %us %s", holdtime,
holdtime == 0xffff ? "(infinity)": "");
offset += 2;
for (i = 0; i < ngroup; i++) {
s = dissect_pim_addr(tvb, offset, pimv2_group, &advance);
if (s == NULL)
goto breakbreak3;
tigroup = proto_tree_add_text(pimopt_tree, tvb, offset, advance,
"Group %d: %s", i, s);
grouptree = proto_item_add_subtree(tigroup, ett_pim);
offset += advance;
njoin = tvb_get_ntohs(tvb, offset);
nprune = tvb_get_ntohs(tvb, offset + 2);
tisub = proto_tree_add_item(grouptree, hf_pim_numjoins, tvb,
offset, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(tisub, ett_pim);
off = offset + 4;
for (j = 0; j < njoin; j++) {
s = dissect_pim_addr(tvb, off, pimv2_source, &advance);
if (s == NULL)
goto breakbreak3;
proto_tree_add_text(subtree, tvb, off, advance,
"IP address: %s", s);
off += advance;
}
tisub = proto_tree_add_item(grouptree, hf_pim_numprunes, tvb,
offset + 2, 2, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(tisub, ett_pim);
for (j = 0; j < nprune; j++) {
s = dissect_pim_addr(tvb, off, pimv2_source, &advance);
if (s == NULL)
goto breakbreak3;
proto_tree_add_text(subtree, tvb, off, advance,
"IP address: %s", s);
off += advance;
}
offset = off;
}
breakbreak3:
break;
}
case 4:
{
const char *s;
int advance;
int i, j;
int frpcnt;
guint16 holdtime;
proto_tree *grouptree = NULL;
proto_item *tigroup;
proto_tree_add_text(pimopt_tree, tvb, offset, 2,
"Fragment tag: 0x%04x", tvb_get_ntohs(tvb, offset));
offset += 2;
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"Hash mask len: %u", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"BSR priority: %u", tvb_get_guint8(tvb, offset));
offset += 1;
s = dissect_pim_addr(tvb, offset, pimv2_unicast, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance, "BSR: %s", s);
offset += advance;
for (i = 0; tvb_reported_length_remaining(tvb, offset) > 0; i++) {
s = dissect_pim_addr(tvb, offset, pimv2_group, &advance);
if (s == NULL)
goto breakbreak4;
tigroup = proto_tree_add_text(pimopt_tree, tvb, offset, advance,
"Group %d: %s", i, s);
grouptree = proto_item_add_subtree(tigroup, ett_pim);
offset += advance;
proto_tree_add_text(grouptree, tvb, offset, 1,
"RP count: %u", tvb_get_guint8(tvb, offset));
offset += 1;
frpcnt = tvb_get_guint8(tvb, offset);
proto_tree_add_text(grouptree, tvb, offset, 1,
"FRP count: %u", frpcnt);
offset += 3;
for (j = 0; j < frpcnt; j++) {
s = dissect_pim_addr(tvb, offset, pimv2_unicast, &advance);
if (s == NULL)
goto breakbreak4;
proto_tree_add_text(grouptree, tvb, offset, advance,
"RP %d: %s", j, s);
offset += advance;
holdtime = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(grouptree, hf_pim_holdtime, tvb,
offset, 2, holdtime,
"Holdtime: %us %s", holdtime,
holdtime == 0xffff ? "(infinity)": "");
offset += 2;
proto_tree_add_text(grouptree, tvb, offset, 1,
"Priority: %u", tvb_get_guint8(tvb, offset));
offset += 2;
}
}
breakbreak4:
break;
}
case 5:
{
const char *s;
int advance;
guint32 pref;
s = dissect_pim_addr(tvb, offset, pimv2_group, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance, "Group: %s", s);
offset += advance;
s = dissect_pim_addr(tvb, offset, pimv2_unicast, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance, "Source: %s", s);
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_rpt, tvb, offset, 1, ENC_BIG_ENDIAN);
pref = tvb_get_ntohl(tvb, offset) & 0x7fffffff;
proto_tree_add_uint_format(pimopt_tree, hf_pim_metric_pref, tvb,
offset, 4, pref,
"Metric Preference: %u", pref);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
}
case 8:
{
const char *s;
int advance;
int pfxcnt;
guint16 holdtime;
int i;
pfxcnt = tvb_get_guint8(tvb, offset);
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"Prefix-count: %u", pfxcnt);
offset += 1;
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"Priority: %u", tvb_get_guint8(tvb, offset));
offset += 1;
holdtime = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(pimopt_tree, hf_pim_holdtime, tvb,
offset, 2, holdtime,
"Holdtime: %us %s", holdtime,
holdtime == 0xffff ? "(infinity)": "");
offset += 2;
s = dissect_pim_addr(tvb, offset, pimv2_unicast, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance, "RP: %s", s);
offset += advance;
for (i = 0; i < pfxcnt; i++) {
s = dissect_pim_addr(tvb, offset, pimv2_group, &advance);
if (s == NULL)
goto breakbreak8;
proto_tree_add_text(pimopt_tree, tvb, offset, advance,
"Group %d: %s", i, s);
offset += advance;
}
breakbreak8:
break;
}
case 9:
{
const char *s;
int advance;
guint32 pref;
s = dissect_pim_addr(tvb, offset, pimv2_group, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance,
"Group: %s", s);
offset += advance;
s = dissect_pim_addr(tvb, offset, pimv2_unicast, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance,
"Source: %s", s);
offset += advance;
s = dissect_pim_addr(tvb, offset, pimv2_unicast, &advance);
if (s == NULL)
break;
proto_tree_add_text(pimopt_tree, tvb, offset, advance,
"Originator: %s", s);
offset += advance;
proto_tree_add_item(pimopt_tree, hf_pim_rpt, tvb, offset, 1, ENC_BIG_ENDIAN);
pref = tvb_get_ntohl(tvb, offset) & 0x7fffffff;
proto_tree_add_uint_format(pimopt_tree, hf_pim_metric_pref, tvb,
offset, 4, pref,
"Metric Preference: %u", pref);
offset += 4;
proto_tree_add_item(pimopt_tree, hf_pim_metric, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"Masklen: %u", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"TTL: %u", tvb_get_guint8(tvb, offset));
offset += 1;
proto_tree_add_text(pimopt_tree, tvb, offset, 1, "Prune indicator %s",
decode_boolean_bitfield(tvb_get_guint8(tvb, offset), 0x80, 8,
"set", "clear"));
proto_tree_add_text(pimopt_tree, tvb, offset, 1, "Prune now %s",
decode_boolean_bitfield(tvb_get_guint8(tvb, offset), 0x40, 8,
"set", "clear"));
proto_tree_add_text(pimopt_tree, tvb, offset, 1, "Assert override %s",
decode_boolean_bitfield(tvb_get_guint8(tvb, offset), 0x20, 8,
"set", "clear"));
offset += 1;
proto_tree_add_text(pimopt_tree, tvb, offset, 1,
"Interval: %u", tvb_get_guint8(tvb, offset));
offset += 1;
break;
}
default:
break;
}
done:;
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
FT_UINT8, BASE_DEC, VALS(type2vals), 0x0f,
NULL, HFILL }
},
{ &hf_pim_code,
{ "Code", "pim.code",
FT_UINT8, BASE_DEC, VALS(type1vals), 0x0,
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
{ &hf_pim_metric_pref ,
{ "Metric Preference", "pim.metric_pref",
FT_UINT32, BASE_DEC, NULL, 0x7fffffff,
NULL, HFILL }
},
{ &hf_pim_metric ,
{ "Metric", "pim.metric",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_pim,
&ett_pim_opts,
&ett_pim_opt
};
proto_pim = proto_register_protocol("Protocol Independent Multicast",
"PIM", "pim");
proto_register_field_array(proto_pim, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pim(void)
{
dissector_handle_t pim_handle;
pim_handle = create_dissector_handle(dissect_pim, proto_pim);
dissector_add_uint("ip.proto", IP_PROTO_PIM, pim_handle);
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
}
