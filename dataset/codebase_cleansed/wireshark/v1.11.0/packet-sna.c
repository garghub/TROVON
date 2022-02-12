static void
dissect_optional_0d(tvbuff_t *tvb, proto_tree *tree)
{
int bits, offset, len, pad;
proto_tree *sub_tree;
proto_item *sub_ti = NULL;
if (!tree)
return;
proto_tree_add_item(tree, hf_sna_nlp_opti_0d_version, tvb, 2, 2, ENC_BIG_ENDIAN);
bits = tvb_get_guint8(tvb, 4);
sub_ti = proto_tree_add_uint(tree, hf_sna_nlp_opti_0d_4,
tvb, 4, 1, bits);
sub_tree = proto_item_add_subtree(sub_ti,
ett_sna_nlp_opti_0d_4);
proto_tree_add_boolean(sub_tree, hf_sna_nlp_opti_0d_target,
tvb, 4, 1, bits);
proto_tree_add_boolean(sub_tree, hf_sna_nlp_opti_0d_arb,
tvb, 4, 1, bits);
proto_tree_add_boolean(sub_tree, hf_sna_nlp_opti_0d_reliable,
tvb, 4, 1, bits);
proto_tree_add_boolean(sub_tree, hf_sna_nlp_opti_0d_dedicated,
tvb, 4, 1, bits);
proto_tree_add_text(tree, tvb, 5, 3, "Reserved");
offset = 8;
while (tvb_offset_exists(tvb, offset)) {
len = tvb_get_guint8(tvb, offset+0);
if (len) {
dissect_control(tvb, offset, len, tree, 1, LT);
pad = (len+3) & 0xfffc;
if (pad > len)
proto_tree_add_text(tree, tvb, offset+len,
pad-len, "Padding");
offset += pad;
} else {
return;
}
}
}
static void
dissect_optional_0e(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int bits, offset;
proto_tree *sub_tree;
proto_item *sub_ti = NULL;
bits = tvb_get_guint8(tvb, 2);
offset = 20;
if (tree) {
sub_ti = proto_tree_add_item(tree, hf_sna_nlp_opti_0e_stat,
tvb, 2, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_ti,
ett_sna_nlp_opti_0e_stat);
proto_tree_add_boolean(sub_tree, hf_sna_nlp_opti_0e_gap,
tvb, 2, 1, bits);
proto_tree_add_boolean(sub_tree, hf_sna_nlp_opti_0e_idle,
tvb, 2, 1, bits);
proto_tree_add_item(tree, hf_sna_nlp_opti_0e_nabsp,
tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_nlp_opti_0e_sync,
tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_nlp_opti_0e_echo,
tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_nlp_opti_0e_rseq,
tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, 12, 8, "Reserved");
if (tvb_offset_exists(tvb, offset))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 4), pinfo, tree);
}
if (bits & 0x40) {
col_set_str(pinfo->cinfo, COL_INFO, "HPR Idle Message");
} else {
col_set_str(pinfo->cinfo, COL_INFO, "HPR Status Message");
}
}
static void
dissect_optional_0f(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!tree)
return;
proto_tree_add_item(tree, hf_sna_nlp_opti_0f_bits, tvb, 2, 2, ENC_BIG_ENDIAN);
if (tvb_offset_exists(tvb, 4))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 4), pinfo, tree);
}
static void
dissect_optional_10(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!tree)
return;
proto_tree_add_text(tree, tvb, 2, 2, "Reserved");
proto_tree_add_item(tree, hf_sna_nlp_opti_10_tcid, tvb, 4, 8, ENC_NA);
if (tvb_offset_exists(tvb, 12))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 12), pinfo, tree);
}
static void
dissect_optional_12(tvbuff_t *tvb, proto_tree *tree)
{
if (!tree)
return;
proto_tree_add_text(tree, tvb, 2, 2, "Reserved");
proto_tree_add_item(tree, hf_sna_nlp_opti_12_sense, tvb, 4, -1, ENC_NA);
}
static void
dissect_optional_14(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *sub_tree, *bf_tree;
proto_item *sub_item, *bf_item;
int len, pad, type, bits, offset, num, sublen;
if (!tree)
return;
proto_tree_add_text(tree, tvb, 2, 2, "Reserved");
offset = 4;
len = tvb_get_guint8(tvb, offset);
type = tvb_get_guint8(tvb, offset+1);
if ((type != 0x83) || (len <= 16)) {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return;
}
sub_item = proto_tree_add_text(tree, tvb, offset, len,
"Switching Information Control Vector");
sub_tree = proto_item_add_subtree(sub_item, ett_sna_nlp_opti_14_si);
proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_14_si_len,
tvb, offset, 1, len);
proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_14_si_key,
tvb, offset+1, 1, type);
bits = tvb_get_guint8(tvb, offset+2);
bf_item = proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_14_si_2,
tvb, offset+2, 1, bits);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_nlp_opti_14_si_2);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_opti_14_si_refifo,
tvb, offset+2, 1, bits);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_opti_14_si_mobility,
tvb, offset+2, 1, bits);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_opti_14_si_dirsearch,
tvb, offset+2, 1, bits);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_opti_14_si_limitres,
tvb, offset+2, 1, bits);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_opti_14_si_ncescope,
tvb, offset+2, 1, bits);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_opti_14_si_mnpsrscv,
tvb, offset+2, 1, bits);
proto_tree_add_text(sub_tree, tvb, offset+3, 1, "Reserved");
proto_tree_add_item(sub_tree, hf_sna_nlp_opti_14_si_maxpsize,
tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_sna_nlp_opti_14_si_switch,
tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_sna_nlp_opti_14_si_alive,
tvb, offset+12, 4, ENC_BIG_ENDIAN);
dissect_control(tvb, offset+16, len-16, sub_tree, 1, LT);
pad = (len+3) & 0xfffc;
if (pad > len)
proto_tree_add_text(sub_tree, tvb, offset+len, pad-len,
"Padding");
offset += pad;
len = tvb_get_guint8(tvb, offset);
type = tvb_get_guint8(tvb, offset+1);
if ((type != 0x85) || ( len < 4)) {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return;
}
sub_item = proto_tree_add_text(tree, tvb, offset, len,
"Return Route TG Descriptor Control Vector");
sub_tree = proto_item_add_subtree(sub_item, ett_sna_nlp_opti_14_rr);
proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_14_rr_len,
tvb, offset, 1, len);
proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_14_rr_key,
tvb, offset+1, 1, type);
bits = tvb_get_guint8(tvb, offset+2);
bf_item = proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_14_rr_2,
tvb, offset+2, 1, bits);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_nlp_opti_14_rr_2);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_opti_14_rr_bfe,
tvb, offset+2, 1, bits);
num = tvb_get_guint8(tvb, offset+3);
proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_14_rr_num,
tvb, offset+3, 1, num);
offset += 4;
while (num) {
sublen = tvb_get_guint8(tvb, offset);
if (sublen) {
dissect_control(tvb, offset, sublen, sub_tree, 1, LT);
} else {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return;
}
offset += sublen;
num--;
}
}
static void
dissect_optional_22(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *bf_tree;
proto_item *bf_item;
int bits, type;
if (!tree)
return;
bits = tvb_get_guint8(tvb, 2);
type = (bits & 0xc0) >> 6;
bf_item = proto_tree_add_uint(tree, hf_sna_nlp_opti_22_2,
tvb, 2, 1, bits);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_nlp_opti_22_2);
proto_tree_add_uint(bf_tree, hf_sna_nlp_opti_22_type,
tvb, 2, 1, bits);
proto_tree_add_uint(bf_tree, hf_sna_nlp_opti_22_raa,
tvb, 2, 1, bits);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_opti_22_parity,
tvb, 2, 1, bits);
proto_tree_add_uint(bf_tree, hf_sna_nlp_opti_22_arb,
tvb, 2, 1, bits);
bits = tvb_get_guint8(tvb, 3);
bf_item = proto_tree_add_uint(tree, hf_sna_nlp_opti_22_3,
tvb, 3, 1, bits);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_nlp_opti_22_3);
proto_tree_add_uint(bf_tree, hf_sna_nlp_opti_22_ratereq,
tvb, 3, 1, bits);
proto_tree_add_uint(bf_tree, hf_sna_nlp_opti_22_raterep,
tvb, 3, 1, bits);
proto_tree_add_item(tree, hf_sna_nlp_opti_22_field1,
tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_nlp_opti_22_field2,
tvb, 8, 4, ENC_BIG_ENDIAN);
if (type == 0) {
proto_tree_add_item(tree, hf_sna_nlp_opti_22_field3,
tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_nlp_opti_22_field4,
tvb, 16, 4, ENC_BIG_ENDIAN);
if (tvb_offset_exists(tvb, 20))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 20), pinfo, tree);
} else {
if (tvb_offset_exists(tvb, 12))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 12), pinfo, tree);
}
}
static void
dissect_optional(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *sub_tree;
proto_item *sub_item;
int offset, type, len;
gint ett;
sub_tree = NULL;
offset = 0;
while (tvb_offset_exists(tvb, offset)) {
len = tvb_get_guint8(tvb, offset);
type = tvb_get_guint8(tvb, offset+1);
if (len == 0) {
if (tree)
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, tree);
return;
}
ett = ett_sna_nlp_opti_un;
if(type == 0x0d) ett = ett_sna_nlp_opti_0d;
if(type == 0x0e) ett = ett_sna_nlp_opti_0e;
if(type == 0x0f) ett = ett_sna_nlp_opti_0f;
if(type == 0x10) ett = ett_sna_nlp_opti_10;
if(type == 0x12) ett = ett_sna_nlp_opti_12;
if(type == 0x14) ett = ett_sna_nlp_opti_14;
if(type == 0x22) ett = ett_sna_nlp_opti_22;
if (tree) {
sub_item = proto_tree_add_text(tree, tvb,
offset, len << 2, "%s",
val_to_str(type, sna_nlp_opti_vals,
"Unknown Segment Type"));
sub_tree = proto_item_add_subtree(sub_item, ett);
proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_len,
tvb, offset, 1, len);
proto_tree_add_uint(sub_tree, hf_sna_nlp_opti_type,
tvb, offset+1, 1, type);
}
switch(type) {
case 0x0d:
dissect_optional_0d(tvb_new_subset(tvb, offset,
len << 2, -1), sub_tree);
break;
case 0x0e:
dissect_optional_0e(tvb_new_subset(tvb, offset,
len << 2, -1), pinfo, sub_tree);
break;
case 0x0f:
dissect_optional_0f(tvb_new_subset(tvb, offset,
len << 2, -1), pinfo, sub_tree);
break;
case 0x10:
dissect_optional_10(tvb_new_subset(tvb, offset,
len << 2, -1), pinfo, sub_tree);
break;
case 0x12:
dissect_optional_12(tvb_new_subset(tvb, offset,
len << 2, -1), sub_tree);
break;
case 0x14:
dissect_optional_14(tvb_new_subset(tvb, offset,
len << 2, -1), pinfo, sub_tree);
break;
case 0x22:
dissect_optional_22(tvb_new_subset(tvb, offset,
len << 2, -1), pinfo, sub_tree);
break;
default:
call_dissector(data_handle,
tvb_new_subset(tvb, offset,
len << 2, -1), pinfo, sub_tree);
}
offset += (len << 2);
}
}
static void
dissect_nlp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *parent_tree)
{
proto_tree *nlp_tree, *bf_tree;
proto_item *nlp_item, *bf_item;
guint8 nhdr_0, nhdr_1, nhdr_x, thdr_8, thdr_9, fid;
guint32 thdr_len, thdr_dlf;
guint16 subindx;
int indx = 0, counter = 0;
nlp_tree = NULL;
nlp_item = NULL;
nhdr_0 = tvb_get_guint8(tvb, indx);
nhdr_1 = tvb_get_guint8(tvb, indx+1);
col_set_str(pinfo->cinfo, COL_INFO, "HPR NLP Packet");
if (tree) {
nlp_item = proto_tree_add_item(tree, hf_sna_nlp_nhdr, tvb,
indx, -1, ENC_NA);
nlp_tree = proto_item_add_subtree(nlp_item, ett_sna_nlp_nhdr);
bf_item = proto_tree_add_uint(nlp_tree, hf_sna_nlp_nhdr_0, tvb,
indx, 1, nhdr_0);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_nlp_nhdr_0);
proto_tree_add_uint(bf_tree, hf_sna_nlp_sm, tvb, indx, 1,
nhdr_0);
proto_tree_add_uint(bf_tree, hf_sna_nlp_tpf, tvb, indx, 1,
nhdr_0);
bf_item = proto_tree_add_uint(nlp_tree, hf_sna_nlp_nhdr_1, tvb,
indx+1, 1, nhdr_1);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_nlp_nhdr_1);
proto_tree_add_uint(bf_tree, hf_sna_nlp_ft, tvb,
indx+1, 1, nhdr_1);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_tspi, tvb,
indx+1, 1, nhdr_1);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_slowdn1, tvb,
indx+1, 1, nhdr_1);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_slowdn2, tvb,
indx+1, 1, nhdr_1);
}
indx += 2;
counter = 0;
if ((nhdr_0 & 0xe0) == 0xa0) {
do {
nhdr_x = tvb_get_guint8(tvb, indx + counter);
counter ++;
} while (nhdr_x != 0xff);
if (tree)
proto_tree_add_item(nlp_tree,
hf_sna_nlp_fra, tvb, indx, counter, ENC_NA);
indx += counter;
if (tree)
proto_tree_add_text(nlp_tree, tvb, indx, 1,
"Reserved");
indx++;
if (tree)
proto_item_set_len(nlp_item, indx);
if ((nhdr_1 & 0xf0) == 0x10) {
nhdr_x = tvb_get_guint8(tvb, indx);
if (tree)
proto_tree_add_uint(tree, hf_sna_nlp_frh,
tvb, indx, 1, nhdr_x);
indx ++;
if (tvb_offset_exists(tvb, indx))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, indx),
pinfo, parent_tree);
return;
}
}
if ((nhdr_0 & 0xe0) == 0xc0) {
do {
nhdr_x = tvb_get_guint8(tvb, indx + counter);
counter ++;
} while (nhdr_x != 0xff);
if (tree)
proto_tree_add_item(nlp_tree, hf_sna_nlp_anr,
tvb, indx, counter, ENC_NA);
indx += counter;
if (tree)
proto_tree_add_text(nlp_tree, tvb, indx, 1,
"Reserved");
indx++;
if (tree)
proto_item_set_len(nlp_item, indx);
}
thdr_8 = tvb_get_guint8(tvb, indx+8);
thdr_9 = tvb_get_guint8(tvb, indx+9);
thdr_len = tvb_get_ntohs(tvb, indx+10);
thdr_dlf = tvb_get_ntohl(tvb, indx+12);
if (tree) {
nlp_item = proto_tree_add_item(tree, hf_sna_nlp_thdr, tvb,
indx, thdr_len << 2, ENC_NA);
nlp_tree = proto_item_add_subtree(nlp_item, ett_sna_nlp_thdr);
proto_tree_add_item(nlp_tree, hf_sna_nlp_tcid, tvb,
indx, 8, ENC_NA);
bf_item = proto_tree_add_uint(nlp_tree, hf_sna_nlp_thdr_8, tvb,
indx+8, 1, thdr_8);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_nlp_thdr_8);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_setupi, tvb,
indx+8, 1, thdr_8);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_somi, tvb, indx+8,
1, thdr_8);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_eomi, tvb, indx+8,
1, thdr_8);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_sri, tvb, indx+8,
1, thdr_8);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_rasapi, tvb,
indx+8, 1, thdr_8);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_retryi, tvb,
indx+8, 1, thdr_8);
bf_item = proto_tree_add_uint(nlp_tree, hf_sna_nlp_thdr_9, tvb,
indx+9, 1, thdr_9);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_nlp_thdr_9);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_lmi, tvb, indx+9,
1, thdr_9);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_cqfi, tvb, indx+9,
1, thdr_9);
proto_tree_add_boolean(bf_tree, hf_sna_nlp_osi, tvb, indx+9,
1, thdr_9);
proto_tree_add_uint(nlp_tree, hf_sna_nlp_offset, tvb, indx+10,
2, thdr_len);
proto_tree_add_uint(nlp_tree, hf_sna_nlp_dlf, tvb, indx+12,
4, thdr_dlf);
proto_tree_add_item(nlp_tree, hf_sna_nlp_bsn, tvb, indx+16,
4, ENC_BIG_ENDIAN);
}
subindx = 20;
if (((thdr_9 & 0x18) == 0x08) && ((thdr_len << 2) > subindx)) {
counter = tvb_get_guint8(tvb, indx + subindx);
if (tvb_get_guint8(tvb, indx+subindx+1) == 5)
dissect_control(tvb, indx + subindx, counter+2, nlp_tree, 1, LT);
else
call_dissector(data_handle,
tvb_new_subset(tvb, indx + subindx, counter+2,
-1), pinfo, nlp_tree);
subindx += (counter+2);
}
if ((thdr_9 & 0x04) && ((thdr_len << 2) > subindx))
dissect_optional(
tvb_new_subset(tvb, indx + subindx,
(thdr_len << 2) - subindx, -1),
pinfo, nlp_tree);
indx += (thdr_len << 2);
if (((thdr_8 & 0x20) == 0) && thdr_dlf) {
col_set_str(pinfo->cinfo, COL_INFO, "HPR Fragment");
if (tvb_offset_exists(tvb, indx)) {
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, indx), pinfo,
parent_tree);
}
return;
}
if (tvb_offset_exists(tvb, indx)) {
fid = hi_nibble(tvb_get_guint8(tvb, indx));
if (fid == 5)
dissect_fid(tvb_new_subset_remaining(tvb, indx), pinfo,
tree, parent_tree);
else {
if (tvb_get_ntohs(tvb, indx+2) == 0x12ce) {
col_set_str(pinfo->cinfo, COL_INFO, "HPR Route Setup");
dissect_gds(tvb_new_subset_remaining(tvb, indx),
pinfo, tree, parent_tree);
} else
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, indx),
pinfo, parent_tree);
}
}
}
static void
dissect_xid1(tvbuff_t *tvb, proto_tree *tree)
{
if (!tree)
return;
proto_tree_add_text(tree, tvb, 0, 2, "Reserved");
}
static void
dissect_xid2(tvbuff_t *tvb, proto_tree *tree)
{
guint dlen, offset;
if (!tree)
return;
dlen = tvb_get_guint8(tvb, 0);
offset = dlen;
while (tvb_offset_exists(tvb, offset)) {
dlen = tvb_get_guint8(tvb, offset+1);
dissect_control(tvb, offset, dlen+2, tree, 0, KL);
offset += (dlen + 2);
}
}
static void
dissect_xid3(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree *sub_tree;
proto_item *sub_ti = NULL;
guint val, dlen, offset;
if (!tree)
return;
proto_tree_add_text(tree, tvb, 0, 2, "Reserved");
val = tvb_get_ntohs(tvb, 2);
sub_ti = proto_tree_add_uint(tree, hf_sna_xid_3_8, tvb,
2, 2, val);
sub_tree = proto_item_add_subtree(sub_ti, ett_sna_xid_3_8);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_init_self, tvb, 2, 2,
val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_stand_bind, tvb, 2, 2,
val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_gener_bind, tvb, 2, 2,
val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_recve_bind, tvb, 2, 2,
val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_actpu, tvb, 2, 2, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_nwnode, tvb, 2, 2, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_cp, tvb, 2, 2, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_cpcp, tvb, 2, 2, val);
proto_tree_add_uint(sub_tree, hf_sna_xid_3_state, tvb, 2, 2, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_nonact, tvb, 2, 2, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_cpchange, tvb, 2, 2,
val);
val = tvb_get_guint8(tvb, 4);
sub_ti = proto_tree_add_uint(tree, hf_sna_xid_3_10, tvb,
4, 1, val);
sub_tree = proto_item_add_subtree(sub_ti, ett_sna_xid_3_10);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_asend_bind, tvb, 4, 1,
val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_arecv_bind, tvb, 4, 1,
val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_quiesce, tvb, 4, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_pucap, tvb, 4, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_pbn, tvb, 4, 1, val);
proto_tree_add_uint(sub_tree, hf_sna_xid_3_pacing, tvb, 4, 1, val);
val = tvb_get_guint8(tvb, 5);
sub_ti = proto_tree_add_uint(tree, hf_sna_xid_3_11, tvb,
5, 1, val);
sub_tree = proto_item_add_subtree(sub_ti, ett_sna_xid_3_11);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_tgshare, tvb, 5, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_dedsvc, tvb, 5, 1, val);
val = tvb_get_guint8(tvb, 6);
sub_ti = proto_tree_add_item(tree, hf_sna_xid_3_12, tvb,
6, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_ti, ett_sna_xid_3_12);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_negcsup, tvb, 6, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_negcomp, tvb, 6, 1, val);
proto_tree_add_text(tree, tvb, 7, 2, "Reserved");
val = tvb_get_guint8(tvb, 9);
sub_ti = proto_tree_add_item(tree, hf_sna_xid_3_15, tvb,
9, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_ti, ett_sna_xid_3_15);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_partg, tvb, 9, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_dlur, tvb, 9, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_dlus, tvb, 9, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_exbn, tvb, 9, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_genodai, tvb, 9, 1, val);
proto_tree_add_uint(sub_tree, hf_sna_xid_3_branch, tvb, 9, 1, val);
proto_tree_add_boolean(sub_tree, hf_sna_xid_3_brnn, tvb, 9, 1, val);
proto_tree_add_item(tree, hf_sna_xid_3_tg, tvb, 10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_xid_3_dlc, tvb, 11, 1, ENC_BIG_ENDIAN);
dlen = tvb_get_guint8(tvb, 12);
proto_tree_add_uint(tree, hf_sna_xid_3_dlen, tvb, 12, 1, dlen);
offset = 12 + dlen;
while (tvb_offset_exists(tvb, offset)) {
dlen = tvb_get_guint8(tvb, offset+1);
dissect_control(tvb, offset, dlen+2, tree, 0, KL);
offset += (dlen+2);
}
}
static void
dissect_xid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *parent_tree)
{
proto_tree *sub_tree;
proto_item *sub_ti = NULL;
int format, type, len;
guint32 id;
len = tvb_get_guint8(tvb, 1);
type = tvb_get_guint8(tvb, 0);
id = tvb_get_ntohl(tvb, 2);
format = hi_nibble(type);
col_add_fstr(pinfo->cinfo, COL_INFO,
"SNA XID Format:%d Type:%s", format,
val_to_str_const(lo_nibble(type), sna_xid_type_vals,
"Unknown Type"));
if (tree) {
sub_ti = proto_tree_add_item(tree, hf_sna_xid_0, tvb,
0, 1, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_ti, ett_sna_xid_0);
proto_tree_add_uint(sub_tree, hf_sna_xid_format, tvb, 0, 1,
type);
proto_tree_add_uint(sub_tree, hf_sna_xid_type, tvb, 0, 1,
type);
proto_tree_add_uint(tree, hf_sna_xid_len, tvb, 1, 1, len);
sub_ti = proto_tree_add_item(tree, hf_sna_xid_id, tvb,
2, 4, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(sub_ti, ett_sna_xid_id);
proto_tree_add_uint(sub_tree, hf_sna_xid_idblock, tvb, 2, 4,
id);
proto_tree_add_uint(sub_tree, hf_sna_xid_idnum, tvb, 2, 4,
id);
switch(format) {
case 0:
break;
case 1:
dissect_xid1(tvb_new_subset(tvb, 6, len-6, -1),
tree);
break;
case 2:
dissect_xid2(tvb_new_subset(tvb, 6, len-6, -1),
tree);
break;
case 3:
dissect_xid3(tvb_new_subset(tvb, 6, len-6, -1),
tree);
break;
default:
call_dissector(data_handle,
tvb_new_subset(tvb, 6, len-6, -1),
pinfo, tree);
}
}
if (format == 0)
len = 6;
if (tvb_offset_exists(tvb, len))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, len), pinfo, parent_tree);
}
static unsigned int
mpf_value(guint8 th_byte)
{
return (th_byte & 0x0c) >> 2;
}
static tvbuff_t*
defragment_by_sequence(packet_info *pinfo, tvbuff_t *tvb, int offset, int mpf,
int id)
{
fragment_head *fd_head;
int frag_number = -1;
int more_frags = TRUE;
tvbuff_t *rh_tvb = NULL;
gint frag_len;
switch(mpf) {
case MPF_WHOLE_BIU:
break;
case MPF_FIRST_SEGMENT:
frag_number = FIRST_FRAG_NUMBER;
break;
case MPF_MIDDLE_SEGMENT:
frag_number = MIDDLE_FRAG_NUMBER;
break;
case MPF_LAST_SEGMENT:
frag_number = LAST_FRAG_NUMBER;
more_frags = FALSE;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if (frag_number > -1) {
frag_len = tvb_reported_length_remaining(tvb, offset);
if (tvb_bytes_exist(tvb, offset, frag_len)) {
fd_head = fragment_add_seq(&sna_reassembly_table,
tvb, offset, pinfo, id, NULL,
frag_number, frag_len, more_frags, 0);
if (mpf == MPF_LAST_SEGMENT && !fd_head) {
fd_head = fragment_add_seq(&sna_reassembly_table,
tvb, offset, pinfo, id, NULL,
MIDDLE_FRAG_NUMBER, 0, TRUE, 0);
}
if (fd_head != NULL) {
rh_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, rh_tvb,
"Reassembled SNA BIU");
}
}
}
return rh_tvb;
}
static int
dissect_fid0_1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *bf_tree;
proto_item *bf_item;
guint8 th_0;
const guint8 *ptr;
const int bytes_in_header = 10;
if (tree) {
th_0 = tvb_get_guint8(tvb, 0);
bf_item = proto_tree_add_uint(tree, hf_sna_th_0, tvb, 0, 1,
th_0);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_uint(bf_tree, hf_sna_th_fid, tvb, 0, 1, th_0);
proto_tree_add_uint(bf_tree, hf_sna_th_mpf, tvb, 0, 1, th_0);
proto_tree_add_uint(bf_tree, hf_sna_th_efi, tvb, 0, 1, th_0);
proto_tree_add_text(tree, tvb, 1, 1, "Reserved");
proto_tree_add_item(tree, hf_sna_th_daf, tvb, 2, 2, ENC_BIG_ENDIAN);
}
ptr = tvb_get_ptr(tvb, 2, SNA_FID01_ADDR_LEN);
SET_ADDRESS(&pinfo->net_dst, AT_SNA, SNA_FID01_ADDR_LEN, ptr);
SET_ADDRESS(&pinfo->dst, AT_SNA, SNA_FID01_ADDR_LEN, ptr);
if (tree)
proto_tree_add_item(tree, hf_sna_th_oaf, tvb, 4, 2, ENC_BIG_ENDIAN);
ptr = tvb_get_ptr(tvb, 4, SNA_FID01_ADDR_LEN);
SET_ADDRESS(&pinfo->net_src, AT_SNA, SNA_FID01_ADDR_LEN, ptr);
SET_ADDRESS(&pinfo->src, AT_SNA, SNA_FID01_ADDR_LEN, ptr);
if (tree)
return bytes_in_header;
proto_tree_add_item(tree, hf_sna_th_snf, tvb, 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_th_dcf, tvb, 8, 2, ENC_BIG_ENDIAN);
return bytes_in_header;
}
static int
dissect_fid2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
tvbuff_t **rh_tvb_ptr, next_dissection_t *continue_dissecting)
{
proto_tree *bf_tree;
proto_item *bf_item;
guint8 th_0;
const guint8 *ptr;
unsigned int mpf, id;
const int bytes_in_header = 6;
th_0 = tvb_get_guint8(tvb, 0);
mpf = mpf_value(th_0);
if (tree) {
bf_item = proto_tree_add_item(tree, hf_sna_th_0, tvb, 0, 1, ENC_NA);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_item(bf_tree, hf_sna_th_fid, tvb, 0, 1, ENC_NA);
proto_tree_add_item(bf_tree, hf_sna_th_mpf, tvb, 0, 1, ENC_NA);
proto_tree_add_item(bf_tree, hf_sna_th_odai,tvb, 0, 1, ENC_NA);
proto_tree_add_item(bf_tree, hf_sna_th_efi, tvb, 0, 1, ENC_NA);
proto_tree_add_text(tree, tvb, 1, 1, "Reserved");
proto_tree_add_item(tree, hf_sna_th_daf, tvb, 2, 1, ENC_NA);
}
ptr = tvb_get_ptr(tvb, 2, SNA_FID2_ADDR_LEN);
SET_ADDRESS(&pinfo->net_dst, AT_SNA, SNA_FID2_ADDR_LEN, ptr);
SET_ADDRESS(&pinfo->dst, AT_SNA, SNA_FID2_ADDR_LEN, ptr);
proto_tree_add_item(tree, hf_sna_th_oaf, tvb, 3, 1, ENC_NA);
ptr = tvb_get_ptr(tvb, 3, SNA_FID2_ADDR_LEN);
SET_ADDRESS(&pinfo->net_src, AT_SNA, SNA_FID2_ADDR_LEN, ptr);
SET_ADDRESS(&pinfo->src, AT_SNA, SNA_FID2_ADDR_LEN, ptr);
id = tvb_get_ntohs(tvb, 4);
proto_tree_add_item(tree, hf_sna_th_snf, tvb, 4, 2, ENC_BIG_ENDIAN);
if (mpf != MPF_WHOLE_BIU && !sna_defragment) {
if (mpf == MPF_FIRST_SEGMENT) {
*continue_dissecting = rh_only;
} else {
*continue_dissecting = stop_here;
}
}
else if (sna_defragment) {
*rh_tvb_ptr = defragment_by_sequence(pinfo, tvb,
bytes_in_header, mpf, id);
}
return bytes_in_header;
}
static int
dissect_fid3(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree *bf_tree;
proto_item *bf_item;
guint8 th_0;
const int bytes_in_header = 2;
if (!tree)
return bytes_in_header;
th_0 = tvb_get_guint8(tvb, 0);
bf_item = proto_tree_add_uint(tree, hf_sna_th_0, tvb, 0, 1, th_0);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_uint(bf_tree, hf_sna_th_fid, tvb, 0, 1, th_0);
proto_tree_add_uint(bf_tree, hf_sna_th_mpf, tvb, 0, 1, th_0);
proto_tree_add_uint(bf_tree, hf_sna_th_efi, tvb, 0, 1, th_0);
proto_tree_add_item(tree, hf_sna_th_lsid, tvb, 1, 1, ENC_BIG_ENDIAN);
return bytes_in_header;
}
static int
dissect_fid4(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *bf_tree;
proto_item *bf_item;
int offset = 0;
guint8 th_byte, mft;
guint16 th_word;
guint16 def, oef;
guint32 dsaf, osaf;
static struct sna_fid_type_4_addr src, dst;
const int bytes_in_header = 26;
if (!tree)
return bytes_in_header;
th_byte = tvb_get_guint8(tvb, offset);
bf_item = proto_tree_add_uint(tree, hf_sna_th_0, tvb, offset,
1, th_byte);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_uint(bf_tree, hf_sna_th_fid, tvb,
offset, 1, th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_tg_sweep, tvb,
offset, 1, th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_er_vr_supp_ind, tvb,
offset, 1, th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_vr_pac_cnt_ind, tvb,
offset, 1, th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_ntwk_prty, tvb,
offset, 1, th_byte);
offset += 1;
th_byte = tvb_get_guint8(tvb, offset);
bf_item = proto_tree_add_text(tree, tvb, offset, 1,
"Transmission Header Byte 1");
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_uint(bf_tree, hf_sna_th_tgsf, tvb, offset, 1,
th_byte);
proto_tree_add_boolean(bf_tree, hf_sna_th_mft, tvb, offset, 1,
th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_piubf, tvb, offset, 1,
th_byte);
mft = th_byte & 0x04;
offset += 1;
th_byte = tvb_get_guint8(tvb, offset);
bf_item = proto_tree_add_text(tree, tvb, offset, 1,
"Transmission Header Byte 2");
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
if (mft) {
proto_tree_add_uint(bf_tree, hf_sna_th_nlpoi, tvb,
offset, 1, th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_nlp_cp, tvb,
offset, 1, th_byte);
} else {
proto_tree_add_uint(bf_tree, hf_sna_th_iern, tvb,
offset, 1, th_byte);
}
proto_tree_add_uint(bf_tree, hf_sna_th_ern, tvb, offset, 1,
th_byte);
offset += 1;
th_byte = tvb_get_guint8(tvb, offset);
bf_item = proto_tree_add_text(tree, tvb, offset, 1,
"Transmission Header Byte 3");
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_uint(bf_tree, hf_sna_th_vrn, tvb, offset, 1,
th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_tpf, tvb, offset, 1,
th_byte);
offset += 1;
th_word = tvb_get_ntohs(tvb, offset);
bf_item = proto_tree_add_text(tree, tvb, offset, 2,
"Transmission Header Bytes 4-5");
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_uint(bf_tree, hf_sna_th_vr_cwi, tvb,
offset, 2, th_word);
proto_tree_add_boolean(bf_tree, hf_sna_th_tg_nonfifo_ind, tvb,
offset, 2, th_word);
proto_tree_add_uint(bf_tree, hf_sna_th_vr_sqti, tvb,
offset, 2, th_word);
proto_tree_add_uint(bf_tree, hf_sna_th_tg_snf, tvb,
offset, 2, th_word);
offset += 2;
th_word = tvb_get_ntohs(tvb, offset);
bf_item = proto_tree_add_text(tree, tvb, offset, 2,
"Transmission Header Bytes 6-7");
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_boolean(bf_tree, hf_sna_th_vrprq, tvb, offset,
2, th_word);
proto_tree_add_boolean(bf_tree, hf_sna_th_vrprs, tvb, offset,
2, th_word);
proto_tree_add_uint(bf_tree, hf_sna_th_vr_cwri, tvb, offset,
2, th_word);
proto_tree_add_boolean(bf_tree, hf_sna_th_vr_rwi, tvb, offset,
2, th_word);
proto_tree_add_uint(bf_tree, hf_sna_th_vr_snf_send, tvb,
offset, 2, th_word);
offset += 2;
dsaf = tvb_get_ntohl(tvb, 8);
proto_tree_add_uint(tree, hf_sna_th_dsaf, tvb, offset, 4, dsaf);
offset += 4;
osaf = tvb_get_ntohl(tvb, 12);
proto_tree_add_uint(tree, hf_sna_th_osaf, tvb, offset, 4, osaf);
offset += 4;
th_byte = tvb_get_guint8(tvb, offset);
bf_item = proto_tree_add_text(tree, tvb, offset, 2,
"Transmission Header Byte 16");
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_boolean(bf_tree, hf_sna_th_snai, tvb, offset, 1, th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_mpf, tvb, offset, 1, th_byte);
proto_tree_add_uint(bf_tree, hf_sna_th_efi, tvb, offset, 1, th_byte);
offset += 2;
def = tvb_get_ntohs(tvb, 18);
proto_tree_add_uint(tree, hf_sna_th_def, tvb, offset, 2, def);
dst.saf = dsaf;
dst.ef = def;
SET_ADDRESS(&pinfo->net_dst, AT_SNA, SNA_FID_TYPE_4_ADDR_LEN,
(guint8* )&dst);
SET_ADDRESS(&pinfo->dst, AT_SNA, SNA_FID_TYPE_4_ADDR_LEN,
(guint8 *)&dst);
oef = tvb_get_ntohs(tvb, 20);
proto_tree_add_uint(tree, hf_sna_th_oef, tvb, offset+2, 2, oef);
src.saf = osaf;
src.ef = oef;
SET_ADDRESS(&pinfo->net_src, AT_SNA, SNA_FID_TYPE_4_ADDR_LEN,
(guint8 *)&src);
SET_ADDRESS(&pinfo->src, AT_SNA, SNA_FID_TYPE_4_ADDR_LEN,
(guint8 *)&src);
proto_tree_add_item(tree, hf_sna_th_snf, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_th_dcf, tvb, offset+6, 2, ENC_BIG_ENDIAN);
return bytes_in_header;
}
static int
dissect_fid5(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree *bf_tree;
proto_item *bf_item;
guint8 th_0;
const int bytes_in_header = 12;
if (!tree)
return bytes_in_header;
th_0 = tvb_get_guint8(tvb, 0);
bf_item = proto_tree_add_uint(tree, hf_sna_th_0, tvb, 0, 1, th_0);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_uint(bf_tree, hf_sna_th_fid, tvb, 0, 1, th_0);
proto_tree_add_uint(bf_tree, hf_sna_th_mpf, tvb, 0, 1, th_0);
proto_tree_add_uint(bf_tree, hf_sna_th_efi, tvb, 0, 1, th_0);
proto_tree_add_text(tree, tvb, 1, 1, "Reserved");
proto_tree_add_item(tree, hf_sna_th_snf, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_th_sa, tvb, 4, 8, ENC_NA);
return bytes_in_header;
}
static int
dissect_fidf(tvbuff_t *tvb, proto_tree *tree)
{
proto_tree *bf_tree;
proto_item *bf_item;
guint8 th_0;
const int bytes_in_header = 26;
if (!tree)
return bytes_in_header;
th_0 = tvb_get_guint8(tvb, 0);
bf_item = proto_tree_add_uint(tree, hf_sna_th_0, tvb, 0, 1, th_0);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_th_fid);
proto_tree_add_uint(bf_tree, hf_sna_th_fid, tvb, 0, 1, th_0);
proto_tree_add_text(tree, tvb, 1, 1, "Reserved");
proto_tree_add_item(tree, hf_sna_th_cmd_fmt, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_th_cmd_type, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_sna_th_cmd_sn, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, 6, 18, "Reserved");
proto_tree_add_item(tree, hf_sna_th_dcf, tvb, 24, 2, ENC_BIG_ENDIAN);
return bytes_in_header;
}
static void
dissect_fid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *parent_tree)
{
proto_tree *th_tree = NULL, *rh_tree = NULL;
proto_item *th_ti = NULL, *rh_ti = NULL;
guint8 th_fid;
int th_header_len = 0;
int offset, rh_offset;
tvbuff_t *rh_tvb = NULL;
next_dissection_t continue_dissecting = everything;
th_fid = hi_nibble(tvb_get_guint8(tvb, 0));
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(th_fid, sna_th_fid_vals, "Unknown FID: %01x"));
if (tree) {
th_ti = proto_tree_add_item(tree, hf_sna_th, tvb, 0, -1,
ENC_NA);
th_tree = proto_item_add_subtree(th_ti, ett_sna_th);
}
switch(th_fid) {
case 0x0:
case 0x1:
th_header_len = dissect_fid0_1(tvb, pinfo, th_tree);
break;
case 0x2:
th_header_len = dissect_fid2(tvb, pinfo, th_tree,
&rh_tvb, &continue_dissecting);
break;
case 0x3:
th_header_len = dissect_fid3(tvb, th_tree);
break;
case 0x4:
th_header_len = dissect_fid4(tvb, pinfo, th_tree);
break;
case 0x5:
th_header_len = dissect_fid5(tvb, th_tree);
break;
case 0xf:
th_header_len = dissect_fidf(tvb, th_tree);
break;
default:
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, 1), pinfo, parent_tree);
return;
}
offset = th_header_len;
if (continue_dissecting == stop_here) {
if (tree) {
proto_tree_add_text(tree, tvb, offset, -1,
"BIU segment data");
}
return;
}
if (!rh_tvb)
rh_tvb = tvb_new_subset_remaining(tvb, offset);
rh_offset = 0;
if (tree) {
proto_item_set_len(th_ti, th_header_len);
rh_ti = proto_tree_add_item(tree, hf_sna_rh, rh_tvb, rh_offset,
RH_LEN, ENC_NA);
rh_tree = proto_item_add_subtree(rh_ti, ett_sna_rh);
dissect_rh(rh_tvb, rh_offset, rh_tree);
}
rh_offset += RH_LEN;
if (tvb_offset_exists(rh_tvb, rh_offset)) {
if (continue_dissecting == rh_only) {
if (tree)
proto_tree_add_text(tree, rh_tvb, rh_offset, -1,
"BIU segment data");
return;
}
call_dissector(data_handle,
tvb_new_subset_remaining(rh_tvb, rh_offset),
pinfo, parent_tree);
}
}
static void
dissect_rh(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree *bf_tree;
proto_item *bf_item;
gboolean is_response;
guint8 rh_0, rh_1, rh_2;
if (!tree)
return;
rh_0 = tvb_get_guint8(tvb, offset);
is_response = (rh_0 & 0x80);
bf_item = proto_tree_add_uint(tree, hf_sna_rh_0, tvb, offset, 1, rh_0);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_rh_0);
proto_tree_add_uint(bf_tree, hf_sna_rh_rri, tvb, offset, 1, rh_0);
proto_tree_add_uint(bf_tree, hf_sna_rh_ru_category, tvb, offset, 1,
rh_0);
proto_tree_add_boolean(bf_tree, hf_sna_rh_fi, tvb, offset, 1, rh_0);
proto_tree_add_boolean(bf_tree, hf_sna_rh_sdi, tvb, offset, 1, rh_0);
proto_tree_add_boolean(bf_tree, hf_sna_rh_bci, tvb, offset, 1, rh_0);
proto_tree_add_boolean(bf_tree, hf_sna_rh_eci, tvb, offset, 1, rh_0);
offset += 1;
rh_1 = tvb_get_guint8(tvb, offset);
bf_item = proto_tree_add_uint(tree, hf_sna_rh_1, tvb, offset, 1, rh_1);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_rh_1);
proto_tree_add_boolean(bf_tree, hf_sna_rh_dr1, tvb, offset, 1, rh_1);
if (!is_response)
proto_tree_add_boolean(bf_tree, hf_sna_rh_lcci, tvb, offset, 1,
rh_1);
proto_tree_add_boolean(bf_tree, hf_sna_rh_dr2, tvb, offset, 1, rh_1);
if (is_response) {
proto_tree_add_boolean(bf_tree, hf_sna_rh_rti, tvb, offset, 1,
rh_1);
} else {
proto_tree_add_boolean(bf_tree, hf_sna_rh_eri, tvb, offset, 1,
rh_1);
proto_tree_add_boolean(bf_tree, hf_sna_rh_rlwi, tvb, offset, 1,
rh_1);
}
proto_tree_add_boolean(bf_tree, hf_sna_rh_qri, tvb, offset, 1, rh_1);
proto_tree_add_boolean(bf_tree, hf_sna_rh_pi, tvb, offset, 1, rh_1);
offset += 1;
rh_2 = tvb_get_guint8(tvb, offset);
bf_item = proto_tree_add_uint(tree, hf_sna_rh_2, tvb, offset, 1, rh_2);
if (!is_response) {
bf_tree = proto_item_add_subtree(bf_item, ett_sna_rh_2);
proto_tree_add_boolean(bf_tree, hf_sna_rh_bbi, tvb, offset, 1,
rh_2);
proto_tree_add_boolean(bf_tree, hf_sna_rh_ebi, tvb, offset, 1,
rh_2);
proto_tree_add_boolean(bf_tree, hf_sna_rh_cdi, tvb, offset, 1,
rh_2);
proto_tree_add_uint(bf_tree, hf_sna_rh_csi, tvb, offset, 1,
rh_2);
proto_tree_add_boolean(bf_tree, hf_sna_rh_edi, tvb, offset, 1,
rh_2);
proto_tree_add_boolean(bf_tree, hf_sna_rh_pdi, tvb, offset, 1,
rh_2);
proto_tree_add_boolean(bf_tree, hf_sna_rh_cebi, tvb, offset, 1,
rh_2);
}
}
static void
dissect_control_05hpr(tvbuff_t *tvb, proto_tree *tree, int hpr,
enum parse parse)
{
proto_tree *bf_tree;
proto_item *bf_item;
guint8 type;
guint16 offset, len, pad;
if (!tree)
return;
type = tvb_get_guint8(tvb, 2);
bf_item = proto_tree_add_uint(tree, hf_sna_control_05_type, tvb,
2, 1, type);
bf_tree = proto_item_add_subtree(bf_item, ett_sna_control_05hpr_type);
proto_tree_add_boolean(bf_tree, hf_sna_control_05_ptp, tvb, 2, 1, type);
proto_tree_add_text(tree, tvb, 3, 1, "Reserved");
offset = 4;
while (tvb_offset_exists(tvb, offset)) {
if (parse == LT) {
len = tvb_get_guint8(tvb, offset+0);
} else {
len = tvb_get_guint8(tvb, offset+1);
}
if (len) {
dissect_control(tvb, offset, len, tree, hpr, parse);
pad = (len+3) & 0xfffc;
if (pad > len) {
tvb_ensure_bytes_exist(tvb, offset+len, pad-len);
proto_tree_add_text(tree, tvb, offset+len,
pad-len, "Padding");
}
offset += pad;
} else {
return;
}
}
}
static void
dissect_control_05(tvbuff_t *tvb, proto_tree *tree)
{
if(!tree)
return;
proto_tree_add_item(tree, hf_sna_control_05_delay, tvb, 2, 2, ENC_BIG_ENDIAN);
}
static void
dissect_control_0e(tvbuff_t *tvb, proto_tree *tree)
{
gint len;
guint8 *buf;
if (!tree)
return;
proto_tree_add_item(tree, hf_sna_control_0e_type, tvb, 2, 1, ENC_BIG_ENDIAN);
len = tvb_reported_length_remaining(tvb, 3);
if (len <= 0)
return;
buf = tvb_get_string(wmem_packet_scope(), tvb, 3, len);
EBCDIC_to_ASCII(buf, len);
proto_tree_add_string(tree, hf_sna_control_0e_value, tvb, 3, len, (char *)buf);
}
static void
dissect_control(tvbuff_t *parent_tvb, int offset, int control_len,
proto_tree *tree, int hpr, enum parse parse)
{
tvbuff_t *tvb;
gint length, reported_length;
proto_tree *sub_tree;
proto_item *sub_item;
int len, key;
gint ett;
length = tvb_length_remaining(parent_tvb, offset);
reported_length = tvb_reported_length_remaining(parent_tvb, offset);
if (control_len < length)
length = control_len;
if (control_len < reported_length)
reported_length = control_len;
tvb = tvb_new_subset(parent_tvb, offset, length, reported_length);
sub_tree = NULL;
if (parse == LT) {
len = tvb_get_guint8(tvb, 0);
key = tvb_get_guint8(tvb, 1);
} else {
key = tvb_get_guint8(tvb, 0);
len = tvb_get_guint8(tvb, 1);
}
ett = ett_sna_control_un;
if (tree) {
if (key == 5) {
if (hpr) ett = ett_sna_control_05hpr;
else ett = ett_sna_control_05;
}
if (key == 0x0e) ett = ett_sna_control_0e;
if (((key == 0) || (key == 3) || (key == 5)) && hpr)
sub_item = proto_tree_add_text(tree, tvb, 0, -1, "%s",
val_to_str_const(key, sna_control_hpr_vals,
"Unknown Control Vector"));
else
sub_item = proto_tree_add_text(tree, tvb, 0, -1, "%s",
val_to_str_const(key, sna_control_vals,
"Unknown Control Vector"));
sub_tree = proto_item_add_subtree(sub_item, ett);
if (parse == LT) {
proto_tree_add_uint(sub_tree, hf_sna_control_len,
tvb, 0, 1, len);
if (((key == 0) || (key == 3) || (key == 5)) && hpr)
proto_tree_add_uint(sub_tree,
hf_sna_control_hprkey, tvb, 1, 1, key);
else
proto_tree_add_uint(sub_tree,
hf_sna_control_key, tvb, 1, 1, key);
} else {
if (((key == 0) || (key == 3) || (key == 5)) && hpr)
proto_tree_add_uint(sub_tree,
hf_sna_control_hprkey, tvb, 0, 1, key);
else
proto_tree_add_uint(sub_tree,
hf_sna_control_key, tvb, 0, 1, key);
proto_tree_add_uint(sub_tree, hf_sna_control_len,
tvb, 1, 1, len);
}
}
switch(key) {
case 0x05:
if (hpr)
dissect_control_05hpr(tvb, sub_tree, hpr,
parse);
else
dissect_control_05(tvb, sub_tree);
break;
case 0x0e:
dissect_control_0e(tvb, sub_tree);
break;
}
}
static void
dissect_gds(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *parent_tree)
{
guint16 length;
guint16 type;
int cont;
int offset = 0;
proto_tree *gds_tree;
proto_item *gds_item;
do {
length = tvb_get_ntohs(tvb, offset) & 0x7fff;
cont = (tvb_get_ntohs(tvb, offset) & 0x8000) ? 1 : 0;
type = tvb_get_ntohs(tvb, offset+2);
if (length < 2 )
return;
if (tree) {
gds_item = proto_tree_add_item(tree, hf_sna_gds, tvb,
offset, length, ENC_NA);
gds_tree = proto_item_add_subtree(gds_item,
ett_sna_gds);
proto_tree_add_uint(gds_tree, hf_sna_gds_len, tvb,
offset, 2, length);
proto_tree_add_boolean(gds_tree, hf_sna_gds_cont, tvb,
offset, 2, cont);
proto_tree_add_uint(gds_tree, hf_sna_gds_type, tvb,
offset+2, 2, type);
}
offset += length;
} while(cont);
if (tvb_offset_exists(tvb, offset))
call_dissector(data_handle,
tvb_new_subset_remaining(tvb, offset), pinfo, parent_tree);
}
static void
dissect_sna(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 fid;
proto_tree *sna_tree = NULL;
proto_item *sna_ti = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SNA");
col_clear(pinfo->cinfo, COL_INFO);
pinfo->fd->flags.encoding = PACKET_CHAR_ENC_CHAR_EBCDIC;
if (tree) {
sna_ti = proto_tree_add_item(tree, proto_sna, tvb, 0, -1,
ENC_NA);
sna_tree = proto_item_add_subtree(sna_ti, ett_sna);
}
fid = hi_nibble(tvb_get_guint8(tvb, 0));
switch(fid) {
case 0xa:
case 0xb:
case 0xc:
case 0xd:
dissect_nlp(tvb, pinfo, sna_tree, tree);
break;
default:
dissect_fid(tvb, pinfo, sna_tree, tree);
}
}
static void
dissect_sna_xid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *sna_tree = NULL;
proto_item *sna_ti = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SNA");
col_clear(pinfo->cinfo, COL_INFO);
pinfo->fd->flags.encoding = PACKET_CHAR_ENC_CHAR_EBCDIC;
if (tree) {
sna_ti = proto_tree_add_item(tree, proto_sna_xid, tvb, 0, -1,
ENC_NA);
sna_tree = proto_item_add_subtree(sna_ti, ett_sna);
}
dissect_xid(tvb, pinfo, sna_tree, tree);
}
static void
sna_init(void)
{
reassembly_table_init(&sna_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_sna(void)
{
static hf_register_info hf[] = {
{ &hf_sna_th,
{ "Transmission Header", "sna.th", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_0,
{ "Transmission Header Byte 0", "sna.th.0", FT_UINT8, BASE_HEX,
NULL, 0x0,
"TH Byte 0", HFILL }},
{ &hf_sna_th_fid,
{ "Format Identifier", "sna.th.fid", FT_UINT8, BASE_HEX,
VALS(sna_th_fid_vals), 0xf0, NULL, HFILL }},
{ &hf_sna_th_mpf,
{ "Mapping Field", "sna.th.mpf", FT_UINT8,
BASE_DEC, VALS(sna_th_mpf_vals), 0x0c, NULL, HFILL }},
{ &hf_sna_th_odai,
{ "ODAI Assignment Indicator", "sna.th.odai", FT_UINT8,
BASE_DEC, NULL, 0x02, NULL, HFILL }},
{ &hf_sna_th_efi,
{ "Expedited Flow Indicator", "sna.th.efi", FT_UINT8,
BASE_DEC, VALS(sna_th_efi_vals), 0x01, NULL, HFILL }},
{ &hf_sna_th_daf,
{ "Destination Address Field", "sna.th.daf", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_oaf,
{ "Origin Address Field", "sna.th.oaf", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_snf,
{ "Sequence Number Field", "sna.th.snf", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_dcf,
{ "Data Count Field", "sna.th.dcf", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_lsid,
{ "Local Session Identification", "sna.th.lsid", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_tg_sweep,
{ "Transmission Group Sweep", "sna.th.tg_sweep", FT_UINT8,
BASE_DEC, VALS(sna_th_tg_sweep_vals), 0x08, NULL, HFILL }},
{ &hf_sna_th_er_vr_supp_ind,
{ "ER and VR Support Indicator", "sna.th.er_vr_supp_ind",
FT_UINT8, BASE_DEC, VALS(sna_th_er_vr_supp_ind_vals),
0x04, NULL, HFILL }},
{ &hf_sna_th_vr_pac_cnt_ind,
{ "Virtual Route Pacing Count Indicator",
"sna.th.vr_pac_cnt_ind", FT_UINT8, BASE_DEC,
VALS(sna_th_vr_pac_cnt_ind_vals), 0x02, NULL, HFILL }},
{ &hf_sna_th_ntwk_prty,
{ "Network Priority", "sna.th.ntwk_prty", FT_UINT8, BASE_DEC,
VALS(sna_th_ntwk_prty_vals), 0x01, NULL, HFILL }},
{ &hf_sna_th_tgsf,
{ "Transmission Group Segmenting Field", "sna.th.tgsf",
FT_UINT8, BASE_HEX, VALS(sna_th_tgsf_vals), 0xc0,
NULL, HFILL }},
{ &hf_sna_th_mft,
{ "MPR FID4 Type", "sna.th.mft", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL }},
{ &hf_sna_th_piubf,
{ "PIU Blocking Field", "sna.th.piubf", FT_UINT8, BASE_HEX,
VALS(sna_th_piubf_vals), 0x03, NULL, HFILL }},
{ &hf_sna_th_iern,
{ "Initial Explicit Route Number", "sna.th.iern", FT_UINT8,
BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_sna_th_nlpoi,
{ "NLP Offset Indicator", "sna.th.nlpoi", FT_UINT8, BASE_DEC,
VALS(sna_th_nlpoi_vals), 0x80, NULL, HFILL }},
{ &hf_sna_th_nlp_cp,
{ "NLP Count or Padding", "sna.th.nlp_cp", FT_UINT8, BASE_DEC,
NULL, 0x70, NULL, HFILL }},
{ &hf_sna_th_ern,
{ "Explicit Route Number", "sna.th.ern", FT_UINT8, BASE_DEC,
NULL, 0x0f, NULL, HFILL }},
{ &hf_sna_th_vrn,
{ "Virtual Route Number", "sna.th.vrn", FT_UINT8, BASE_DEC,
NULL, 0xf0, NULL, HFILL }},
{ &hf_sna_th_tpf,
{ "Transmission Priority Field", "sna.th.tpf", FT_UINT8,
BASE_HEX, VALS(sna_th_tpf_vals), 0x03, NULL, HFILL }},
{ &hf_sna_th_vr_cwi,
{ "Virtual Route Change Window Indicator", "sna.th.vr_cwi",
FT_UINT16, BASE_DEC, VALS(sna_th_vr_cwi_vals), 0x8000,
"Change Window Indicator", HFILL }},
{ &hf_sna_th_tg_nonfifo_ind,
{ "Transmission Group Non-FIFO Indicator",
"sna.th.tg_nonfifo_ind", FT_BOOLEAN, 16,
TFS(&sna_th_tg_nonfifo_ind_truth), 0x4000, NULL, HFILL }},
{ &hf_sna_th_vr_sqti,
{ "Virtual Route Sequence and Type Indicator", "sna.th.vr_sqti",
FT_UINT16, BASE_HEX, VALS(sna_th_vr_sqti_vals), 0x3000,
"Route Sequence and Type", HFILL }},
{ &hf_sna_th_tg_snf,
{ "Transmission Group Sequence Number Field", "sna.th.tg_snf",
FT_UINT16, BASE_DEC, NULL, 0x0fff, NULL, HFILL }},
{ &hf_sna_th_vrprq,
{ "Virtual Route Pacing Request", "sna.th.vrprq", FT_BOOLEAN,
16, TFS(&sna_th_vrprq_truth), 0x8000, NULL, HFILL }},
{ &hf_sna_th_vrprs,
{ "Virtual Route Pacing Response", "sna.th.vrprs", FT_BOOLEAN,
16, TFS(&sna_th_vrprs_truth), 0x4000, NULL, HFILL }},
{ &hf_sna_th_vr_cwri,
{ "Virtual Route Change Window Reply Indicator",
"sna.th.vr_cwri", FT_UINT16, BASE_DEC,
VALS(sna_th_vr_cwri_vals), 0x2000, NULL, HFILL }},
{ &hf_sna_th_vr_rwi,
{ "Virtual Route Reset Window Indicator", "sna.th.vr_rwi",
FT_BOOLEAN, 16, TFS(&sna_th_vr_rwi_truth), 0x1000,
NULL, HFILL }},
{ &hf_sna_th_vr_snf_send,
{ "Virtual Route Send Sequence Number Field",
"sna.th.vr_snf_send", FT_UINT16, BASE_DEC, NULL, 0x0fff,
"Send Sequence Number Field", HFILL }},
{ &hf_sna_th_dsaf,
{ "Destination Subarea Address Field", "sna.th.dsaf",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_osaf,
{ "Origin Subarea Address Field", "sna.th.osaf", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_snai,
{ "SNA Indicator", "sna.th.snai", FT_BOOLEAN, 8, NULL, 0x10,
"Used to identify whether the PIU originated or is destined for an SNA or non-SNA device.", HFILL }},
{ &hf_sna_th_def,
{ "Destination Element Field", "sna.th.def", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_oef,
{ "Origin Element Field", "sna.th.oef", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_sa,
{ "Session Address", "sna.th.sa", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_cmd_fmt,
{ "Command Format", "sna.th.cmd_fmt", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_cmd_type,
{ "Command Type", "sna.th.cmd_type", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_th_cmd_sn,
{ "Command Sequence Number", "sna.th.cmd_sn", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_nhdr,
{ "Network Layer Packet Header", "sna.nlp.nhdr", FT_NONE,
BASE_NONE, NULL, 0x0, "NHDR", HFILL }},
{ &hf_sna_nlp_nhdr_0,
{ "Network Layer Packet Header Byte 0", "sna.nlp.nhdr.0",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_nhdr_1,
{ "Network Layer Packet Header Byte 1", "sna.nlp.nhdr.1",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_sm,
{ "Switching Mode Field", "sna.nlp.nhdr.sm", FT_UINT8,
BASE_HEX, VALS(sna_nlp_sm_vals), 0xe0, NULL, HFILL }},
{ &hf_sna_nlp_tpf,
{ "Transmission Priority Field", "sna.nlp.nhdr.tpf", FT_UINT8,
BASE_HEX, VALS(sna_th_tpf_vals), 0x06, NULL, HFILL }},
{ &hf_sna_nlp_ft,
{ "Function Type", "sna.nlp.nhdr.ft", FT_UINT8, BASE_HEX,
VALS(sna_nlp_ft_vals), 0xF0, NULL, HFILL }},
{ &hf_sna_nlp_tspi,
{ "Time Sensitive Packet Indicator", "sna.nlp.nhdr.tspi",
FT_BOOLEAN, 8, TFS(&sna_nlp_tspi_truth), 0x08, NULL, HFILL }},
{ &hf_sna_nlp_slowdn1,
{ "Slowdown 1", "sna.nlp.nhdr.slowdn1", FT_BOOLEAN, 8,
TFS(&sna_nlp_slowdn1_truth), 0x04, NULL, HFILL }},
{ &hf_sna_nlp_slowdn2,
{ "Slowdown 2", "sna.nlp.nhdr.slowdn2", FT_BOOLEAN, 8,
TFS(&sna_nlp_slowdn2_truth), 0x02, NULL, HFILL }},
{ &hf_sna_nlp_fra,
{ "Function Routing Address Entry", "sna.nlp.nhdr.fra",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_sna_nlp_anr,
{ "Automatic Network Routing Entry", "sna.nlp.nhdr.anr",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_sna_nlp_frh,
{ "Transmission Priority Field", "sna.nlp.frh", FT_UINT8,
BASE_HEX, VALS(sna_nlp_frh_vals), 0, NULL, HFILL }},
{ &hf_sna_nlp_thdr,
{ "RTP Transport Header", "sna.nlp.thdr", FT_NONE, BASE_NONE,
NULL, 0x0, "THDR", HFILL }},
{ &hf_sna_nlp_tcid,
{ "Transport Connection Identifier", "sna.nlp.thdr.tcid",
FT_BYTES, BASE_NONE, NULL, 0x0, "TCID", HFILL }},
{ &hf_sna_nlp_thdr_8,
{ "RTP Transport Packet Header Byte 8", "sna.nlp.thdr.8",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_setupi,
{ "Setup Indicator", "sna.nlp.thdr.setupi", FT_BOOLEAN, 8,
TFS(&sna_nlp_setupi_truth), 0x40, NULL, HFILL }},
{ &hf_sna_nlp_somi,
{ "Start Of Message Indicator", "sna.nlp.thdr.somi",
FT_BOOLEAN, 8, TFS(&sna_nlp_somi_truth), 0x20, NULL, HFILL }},
{ &hf_sna_nlp_eomi,
{ "End Of Message Indicator", "sna.nlp.thdr.eomi", FT_BOOLEAN,
8, TFS(&sna_nlp_eomi_truth), 0x10, NULL, HFILL }},
{ &hf_sna_nlp_sri,
{ "Session Request Indicator", "sna.nlp.thdr.sri", FT_BOOLEAN,
8, TFS(&sna_nlp_sri_truth), 0x08, NULL, HFILL }},
{ &hf_sna_nlp_rasapi,
{ "Reply ASAP Indicator", "sna.nlp.thdr.rasapi", FT_BOOLEAN,
8, TFS(&sna_nlp_rasapi_truth), 0x04, NULL, HFILL }},
{ &hf_sna_nlp_retryi,
{ "Retry Indicator", "sna.nlp.thdr.retryi", FT_BOOLEAN,
8, TFS(&sna_nlp_retryi_truth), 0x02, NULL, HFILL }},
{ &hf_sna_nlp_thdr_9,
{ "RTP Transport Packet Header Byte 9", "sna.nlp.thdr.9",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_lmi,
{ "Last Message Indicator", "sna.nlp.thdr.lmi", FT_BOOLEAN,
8, TFS(&sna_nlp_lmi_truth), 0x80, NULL, HFILL }},
{ &hf_sna_nlp_cqfi,
{ "Connection Qualifier Field Indicator", "sna.nlp.thdr.cqfi",
FT_BOOLEAN, 8, TFS(&sna_nlp_cqfi_truth), 0x08, NULL, HFILL }},
{ &hf_sna_nlp_osi,
{ "Optional Segments Present Indicator", "sna.nlp.thdr.osi",
FT_BOOLEAN, 8, TFS(&sna_nlp_osi_truth), 0x04, NULL, HFILL }},
{ &hf_sna_nlp_offset,
{ "Data Offset/4", "sna.nlp.thdr.offset", FT_UINT16, BASE_HEX,
NULL, 0x0, "Data Offset in Words", HFILL }},
{ &hf_sna_nlp_dlf,
{ "Data Length Field", "sna.nlp.thdr.dlf", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_bsn,
{ "Byte Sequence Number", "sna.nlp.thdr.bsn", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_len,
{ "Optional Segment Length/4", "sna.nlp.thdr.optional.len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_type,
{ "Optional Segment Type", "sna.nlp.thdr.optional.type",
FT_UINT8, BASE_HEX, VALS(sna_nlp_opti_vals), 0x0, NULL,
HFILL }},
{ &hf_sna_nlp_opti_0d_version,
{ "Version", "sna.nlp.thdr.optional.0d.version",
FT_UINT16, BASE_HEX, VALS(sna_nlp_opti_0d_version_vals),
0, NULL, HFILL }},
{ &hf_sna_nlp_opti_0d_4,
{ "Connection Setup Byte 4", "sna.nlp.thdr.optional.0e.4",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_sna_nlp_opti_0d_target,
{ "Target Resource ID Present",
"sna.nlp.thdr.optional.0d.target",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_sna_nlp_opti_0d_arb,
{ "ARB Flow Control", "sna.nlp.thdr.optional.0d.arb",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_sna_nlp_opti_0d_reliable,
{ "Reliable Connection", "sna.nlp.thdr.optional.0d.reliable",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_sna_nlp_opti_0d_dedicated,
{ "Dedicated RTP Connection",
"sna.nlp.thdr.optional.0d.dedicated",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_sna_nlp_opti_0e_stat,
{ "Status", "sna.nlp.thdr.optional.0e.stat",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_sna_nlp_opti_0e_gap,
{ "Gap Detected", "sna.nlp.thdr.optional.0e.gap",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_sna_nlp_opti_0e_idle,
{ "RTP Idle Packet", "sna.nlp.thdr.optional.0e.idle",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_sna_nlp_opti_0e_nabsp,
{ "Number Of ABSP", "sna.nlp.thdr.optional.0e.nabsp",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_0e_sync,
{ "Status Report Number", "sna.nlp.thdr.optional.0e.sync",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_0e_echo,
{ "Status Acknowledge Number", "sna.nlp.thdr.optional.0e.echo",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_0e_rseq,
{ "Received Sequence Number", "sna.nlp.thdr.optional.0e.rseq",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_sna_nlp_opti_0e_abspbeg,
{ "ABSP Begin", "sna.nlp.thdr.optional.0e.abspbeg",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
#endif
#if 0
{ &hf_sna_nlp_opti_0e_abspend,
{ "ABSP End", "sna.nlp.thdr.optional.0e.abspend",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_sna_nlp_opti_0f_bits,
{ "Client Bits", "sna.nlp.thdr.optional.0f.bits",
FT_UINT8, BASE_HEX, VALS(sna_nlp_opti_0f_bits_vals),
0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_10_tcid,
{ "Transport Connection Identifier",
"sna.nlp.thdr.optional.10.tcid",
FT_BYTES, BASE_NONE, NULL, 0x0, "TCID", HFILL }},
{ &hf_sna_nlp_opti_12_sense,
{ "Sense Data", "sna.nlp.thdr.optional.12.sense",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_len,
{ "Length", "sna.nlp.thdr.optional.14.si.len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_key,
{ "Key", "sna.nlp.thdr.optional.14.si.key",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_2,
{ "Switching Information Byte 2",
"sna.nlp.thdr.optional.14.si.2",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_refifo,
{ "Resequencing (REFIFO) Indicator",
"sna.nlp.thdr.optional.14.si.refifo",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_mobility,
{ "Mobility Indicator",
"sna.nlp.thdr.optional.14.si.mobility",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_dirsearch,
{ "Directory Search Required on Path Switch Indicator",
"sna.nlp.thdr.optional.14.si.dirsearch",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_limitres,
{ "Limited Resource Link Indicator",
"sna.nlp.thdr.optional.14.si.limitres",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_ncescope,
{ "NCE Scope Indicator",
"sna.nlp.thdr.optional.14.si.ncescope",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_mnpsrscv,
{ "MNPS RSCV Retention Indicator",
"sna.nlp.thdr.optional.14.si.mnpsrscv",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_maxpsize,
{ "Maximum Packet Size On Return Path",
"sna.nlp.thdr.optional.14.si.maxpsize",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_switch,
{ "Path Switch Time", "sna.nlp.thdr.optional.14.si.switch",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_si_alive,
{ "RTP Alive Timer", "sna.nlp.thdr.optional.14.si.alive",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_rr_len,
{ "Length", "sna.nlp.thdr.optional.14.rr.len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_rr_key,
{ "Key", "sna.nlp.thdr.optional.14.rr.key",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_rr_2,
{ "Return Route TG Descriptor Byte 2",
"sna.nlp.thdr.optional.14.rr.2",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_rr_bfe,
{ "BF Entry Indicator",
"sna.nlp.thdr.optional.14.rr.bfe",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_sna_nlp_opti_14_rr_num,
{ "Number Of TG Control Vectors",
"sna.nlp.thdr.optional.14.rr.num",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_2,
{ "Adaptive Rate Based Segment Byte 2",
"sna.nlp.thdr.optional.22.2",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_type,
{ "Message Type",
"sna.nlp.thdr.optional.22.type",
FT_UINT8, BASE_HEX,
VALS(sna_nlp_opti_22_type_vals), 0xc0, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_raa,
{ "Rate Adjustment Action",
"sna.nlp.thdr.optional.22.raa",
FT_UINT8, BASE_HEX,
VALS(sna_nlp_opti_22_raa_vals), 0x38, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_parity,
{ "Parity Indicator",
"sna.nlp.thdr.optional.22.parity",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_arb,
{ "ARB Mode",
"sna.nlp.thdr.optional.22.arb",
FT_UINT8, BASE_HEX,
VALS(sna_nlp_opti_22_arb_vals), 0x03, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_3,
{ "Adaptive Rate Based Segment Byte 3",
"sna.nlp.thdr.optional.22.3",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_ratereq,
{ "Rate Request Correlator",
"sna.nlp.thdr.optional.22.ratereq",
FT_UINT8, BASE_DEC, NULL, 0xf0, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_raterep,
{ "Rate Reply Correlator",
"sna.nlp.thdr.optional.22.raterep",
FT_UINT8, BASE_DEC, NULL, 0x0f, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_field1,
{ "Field 1", "sna.nlp.thdr.optional.22.field1",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_field2,
{ "Field 2", "sna.nlp.thdr.optional.22.field2",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_field3,
{ "Field 3", "sna.nlp.thdr.optional.22.field3",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_nlp_opti_22_field4,
{ "Field 4", "sna.nlp.thdr.optional.22.field4",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_rh,
{ "Request/Response Header", "sna.rh", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_rh_0,
{ "Request/Response Header Byte 0", "sna.rh.0", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_rh_1,
{ "Request/Response Header Byte 1", "sna.rh.1", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_rh_2,
{ "Request/Response Header Byte 2", "sna.rh.2", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_rh_rri,
{ "Request/Response Indicator", "sna.rh.rri", FT_UINT8,
BASE_DEC, VALS(sna_rh_rri_vals), 0x80, NULL, HFILL }},
{ &hf_sna_rh_ru_category,
{ "Request/Response Unit Category", "sna.rh.ru_category",
FT_UINT8, BASE_HEX, VALS(sna_rh_ru_category_vals), 0x60,
NULL, HFILL }},
{ &hf_sna_rh_fi,
{ "Format Indicator", "sna.rh.fi", FT_BOOLEAN, 8,
TFS(&sna_rh_fi_truth), 0x08, NULL, HFILL }},
{ &hf_sna_rh_sdi,
{ "Sense Data Included", "sna.rh.sdi", FT_BOOLEAN, 8,
TFS(&sna_rh_sdi_truth), 0x04, NULL, HFILL }},
{ &hf_sna_rh_bci,
{ "Begin Chain Indicator", "sna.rh.bci", FT_BOOLEAN, 8,
TFS(&sna_rh_bci_truth), 0x02, NULL, HFILL }},
{ &hf_sna_rh_eci,
{ "End Chain Indicator", "sna.rh.eci", FT_BOOLEAN, 8,
TFS(&sna_rh_eci_truth), 0x01, NULL, HFILL }},
{ &hf_sna_rh_dr1,
{ "Definite Response 1 Indicator", "sna.rh.dr1", FT_BOOLEAN,
8, NULL, 0x80, NULL, HFILL }},
{ &hf_sna_rh_lcci,
{ "Length-Checked Compression Indicator", "sna.rh.lcci",
FT_BOOLEAN, 8, TFS(&sna_rh_lcci_truth), 0x40, NULL, HFILL }},
{ &hf_sna_rh_dr2,
{ "Definite Response 2 Indicator", "sna.rh.dr2", FT_BOOLEAN,
8, NULL, 0x20, NULL, HFILL }},
{ &hf_sna_rh_eri,
{ "Exception Response Indicator", "sna.rh.eri", FT_BOOLEAN,
8, NULL, 0x10, NULL, HFILL }},
{ &hf_sna_rh_rti,
{ "Response Type Indicator", "sna.rh.rti", FT_BOOLEAN,
8, TFS(&sna_rh_rti_truth), 0x10, NULL, HFILL }},
{ &hf_sna_rh_rlwi,
{ "Request Larger Window Indicator", "sna.rh.rlwi", FT_BOOLEAN,
8, NULL, 0x04, NULL, HFILL }},
{ &hf_sna_rh_qri,
{ "Queued Response Indicator", "sna.rh.qri", FT_BOOLEAN,
8, TFS(&sna_rh_qri_truth), 0x02, NULL, HFILL }},
{ &hf_sna_rh_pi,
{ "Pacing Indicator", "sna.rh.pi", FT_BOOLEAN,
8, NULL, 0x01, NULL, HFILL }},
{ &hf_sna_rh_bbi,
{ "Begin Bracket Indicator", "sna.rh.bbi", FT_BOOLEAN,
8, NULL, 0x80, NULL, HFILL }},
{ &hf_sna_rh_ebi,
{ "End Bracket Indicator", "sna.rh.ebi", FT_BOOLEAN,
8, NULL, 0x40, NULL, HFILL }},
{ &hf_sna_rh_cdi,
{ "Change Direction Indicator", "sna.rh.cdi", FT_BOOLEAN,
8, NULL, 0x20, NULL, HFILL }},
{ &hf_sna_rh_csi,
{ "Code Selection Indicator", "sna.rh.csi", FT_UINT8, BASE_DEC,
VALS(sna_rh_csi_vals), 0x08, NULL, HFILL }},
{ &hf_sna_rh_edi,
{ "Enciphered Data Indicator", "sna.rh.edi", FT_BOOLEAN, 8,
NULL, 0x04, NULL, HFILL }},
{ &hf_sna_rh_pdi,
{ "Padded Data Indicator", "sna.rh.pdi", FT_BOOLEAN, 8, NULL,
0x02, NULL, HFILL }},
{ &hf_sna_rh_cebi,
{ "Conditional End Bracket Indicator", "sna.rh.cebi",
FT_BOOLEAN, 8, NULL, 0x01, NULL, HFILL }},
{ &hf_sna_gds,
{ "GDS Variable", "sna.gds", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_sna_gds_len,
{ "GDS Variable Length", "sna.gds.len", FT_UINT16, BASE_DEC,
NULL, 0x7fff, NULL, HFILL }},
{ &hf_sna_gds_cont,
{ "Continuation Flag", "sna.gds.cont", FT_BOOLEAN, 16, NULL,
0x8000, NULL, HFILL }},
{ &hf_sna_gds_type,
{ "Type of Variable", "sna.gds.type", FT_UINT16, BASE_HEX,
VALS(sna_gds_var_vals), 0x0, NULL, HFILL }},
#if 0
{ &hf_sna_xid,
{ "XID", "sna.xid", FT_NONE, BASE_NONE, NULL, 0x0,
"XID Frame", HFILL }},
#endif
{ &hf_sna_xid_0,
{ "XID Byte 0", "sna.xid.0", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_sna_xid_format,
{ "XID Format", "sna.xid.format", FT_UINT8, BASE_DEC, NULL,
0xf0, NULL, HFILL }},
{ &hf_sna_xid_type,
{ "XID Type", "sna.xid.type", FT_UINT8, BASE_DEC,
VALS(sna_xid_type_vals), 0x0f, NULL, HFILL }},
{ &hf_sna_xid_len,
{ "XID Length", "sna.xid.len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_sna_xid_id,
{ "Node Identification", "sna.xid.id", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_xid_idblock,
{ "ID Block", "sna.xid.idblock", FT_UINT32, BASE_HEX, NULL,
0xfff00000, NULL, HFILL }},
{ &hf_sna_xid_idnum,
{ "ID Number", "sna.xid.idnum", FT_UINT32, BASE_HEX, NULL,
0x0fffff, NULL, HFILL }},
{ &hf_sna_xid_3_8,
{ "Characteristics of XID sender", "sna.xid.type3.8", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_xid_3_init_self,
{ "INIT-SELF support", "sna.xid.type3.initself",
FT_BOOLEAN, 16, NULL, 0x8000, NULL, HFILL }},
{ &hf_sna_xid_3_stand_bind,
{ "Stand-Alone BIND Support", "sna.xid.type3.stand_bind",
FT_BOOLEAN, 16, NULL, 0x4000, NULL, HFILL }},
{ &hf_sna_xid_3_gener_bind,
{ "Whole BIND PIU generated indicator",
"sna.xid.type3.gener_bind", FT_BOOLEAN, 16, NULL, 0x2000,
"Whole BIND PIU generated", HFILL }},
{ &hf_sna_xid_3_recve_bind,
{ "Whole BIND PIU required indicator",
"sna.xid.type3.recve_bind", FT_BOOLEAN, 16, NULL, 0x1000,
"Whole BIND PIU required", HFILL }},
{ &hf_sna_xid_3_actpu,
{ "ACTPU suppression indicator", "sna.xid.type3.actpu",
FT_BOOLEAN, 16, NULL, 0x0080, NULL, HFILL }},
{ &hf_sna_xid_3_nwnode,
{ "Sender is network node", "sna.xid.type3.nwnode",
FT_BOOLEAN, 16, NULL, 0x0040, NULL, HFILL }},
{ &hf_sna_xid_3_cp,
{ "Control Point Services", "sna.xid.type3.cp",
FT_BOOLEAN, 16, NULL, 0x0020, NULL, HFILL }},
{ &hf_sna_xid_3_cpcp,
{ "CP-CP session support", "sna.xid.type3.cpcp",
FT_BOOLEAN, 16, NULL, 0x0010, NULL, HFILL }},
{ &hf_sna_xid_3_state,
{ "XID exchange state indicator", "sna.xid.type3.state",
FT_UINT16, BASE_HEX, VALS(sna_xid_3_state_vals),
0x000c, NULL, HFILL }},
{ &hf_sna_xid_3_nonact,
{ "Nonactivation Exchange", "sna.xid.type3.nonact",
FT_BOOLEAN, 16, NULL, 0x0002, NULL, HFILL }},
{ &hf_sna_xid_3_cpchange,
{ "CP name change support", "sna.xid.type3.cpchange",
FT_BOOLEAN, 16, NULL, 0x0001, NULL, HFILL }},
{ &hf_sna_xid_3_10,
{ "XID Type 3 Byte 10", "sna.xid.type3.10", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_xid_3_asend_bind,
{ "Adaptive BIND pacing support as sender",
"sna.xid.type3.asend_bind", FT_BOOLEAN, 8, NULL, 0x80,
"Pacing support as sender", HFILL }},
{ &hf_sna_xid_3_arecv_bind,
{ "Adaptive BIND pacing support as receiver",
"sna.xid.type3.asend_recv", FT_BOOLEAN, 8, NULL, 0x40,
"Pacing support as receive", HFILL }},
{ &hf_sna_xid_3_quiesce,
{ "Quiesce TG Request",
"sna.xid.type3.quiesce", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_sna_xid_3_pucap,
{ "PU Capabilities",
"sna.xid.type3.pucap", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_sna_xid_3_pbn,
{ "Peripheral Border Node",
"sna.xid.type3.pbn", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_sna_xid_3_pacing,
{ "Qualifier for adaptive BIND pacing support",
"sna.xid.type3.pacing", FT_UINT8, BASE_HEX, NULL, 0x03,
NULL, HFILL }},
{ &hf_sna_xid_3_11,
{ "XID Type 3 Byte 11", "sna.xid.type3.11", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_xid_3_tgshare,
{ "TG Sharing Prohibited Indicator",
"sna.xid.type3.tgshare", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_sna_xid_3_dedsvc,
{ "Dedicated SVC Indicator",
"sna.xid.type3.dedsvc", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_sna_xid_3_12,
{ "XID Type 3 Byte 12", "sna.xid.type3.12", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_xid_3_negcsup,
{ "Negotiation Complete Supported",
"sna.xid.type3.negcsup", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_sna_xid_3_negcomp,
{ "Negotiation Complete",
"sna.xid.type3.negcomp", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_sna_xid_3_15,
{ "XID Type 3 Byte 15", "sna.xid.type3.15", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_sna_xid_3_partg,
{ "Parallel TG Support",
"sna.xid.type3.partg", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_sna_xid_3_dlur,
{ "Dependent LU Requester Indicator",
"sna.xid.type3.dlur", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_sna_xid_3_dlus,
{ "DLUS Served LU Registration Indicator",
"sna.xid.type3.dlus", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_sna_xid_3_exbn,
{ "Extended HPR Border Node",
"sna.xid.type3.exbn", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_sna_xid_3_genodai,
{ "Generalized ODAI Usage Option",
"sna.xid.type3.genodai", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_sna_xid_3_branch,
{ "Branch Indicator", "sna.xid.type3.branch",
FT_UINT8, BASE_HEX, VALS(sna_xid_3_branch_vals),
0x06, NULL, HFILL }},
{ &hf_sna_xid_3_brnn,
{ "Option Set 1123 Indicator",
"sna.xid.type3.brnn", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_sna_xid_3_tg,
{ "XID TG", "sna.xid.type3.tg", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_sna_xid_3_dlc,
{ "XID DLC", "sna.xid.type3.dlc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_sna_xid_3_dlen,
{ "DLC Dependent Section Length", "sna.xid.type3.dlen",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_control_len,
{ "Control Vector Length", "sna.control.len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_control_key,
{ "Control Vector Key", "sna.control.key",
FT_UINT8, BASE_HEX, VALS(sna_control_vals), 0x0, NULL,
HFILL }},
{ &hf_sna_control_hprkey,
{ "Control Vector HPR Key", "sna.control.hprkey",
FT_UINT8, BASE_HEX, VALS(sna_control_hpr_vals), 0x0, NULL,
HFILL }},
{ &hf_sna_control_05_delay,
{ "Channel Delay", "sna.control.05.delay",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_control_05_type,
{ "Network Address Type", "sna.control.05.type",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_sna_control_05_ptp,
{ "Point-to-point", "sna.control.05.ptp",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }},
{ &hf_sna_control_0e_type,
{ "Type", "sna.control.0e.type",
FT_UINT8, BASE_HEX, VALS(sna_control_0e_type_vals),
0, NULL, HFILL }},
{ &hf_sna_control_0e_value,
{ "Value", "sna.control.0e.value",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_sna,
&ett_sna_th,
&ett_sna_th_fid,
&ett_sna_nlp_nhdr,
&ett_sna_nlp_nhdr_0,
&ett_sna_nlp_nhdr_1,
&ett_sna_nlp_thdr,
&ett_sna_nlp_thdr_8,
&ett_sna_nlp_thdr_9,
&ett_sna_nlp_opti_un,
&ett_sna_nlp_opti_0d,
&ett_sna_nlp_opti_0d_4,
&ett_sna_nlp_opti_0e,
&ett_sna_nlp_opti_0e_stat,
&ett_sna_nlp_opti_0e_absp,
&ett_sna_nlp_opti_0f,
&ett_sna_nlp_opti_10,
&ett_sna_nlp_opti_12,
&ett_sna_nlp_opti_14,
&ett_sna_nlp_opti_14_si,
&ett_sna_nlp_opti_14_si_2,
&ett_sna_nlp_opti_14_rr,
&ett_sna_nlp_opti_14_rr_2,
&ett_sna_nlp_opti_22,
&ett_sna_nlp_opti_22_2,
&ett_sna_nlp_opti_22_3,
&ett_sna_rh,
&ett_sna_rh_0,
&ett_sna_rh_1,
&ett_sna_rh_2,
&ett_sna_gds,
&ett_sna_xid_0,
&ett_sna_xid_id,
&ett_sna_xid_3_8,
&ett_sna_xid_3_10,
&ett_sna_xid_3_11,
&ett_sna_xid_3_12,
&ett_sna_xid_3_15,
&ett_sna_control_un,
&ett_sna_control_05,
&ett_sna_control_05hpr,
&ett_sna_control_05hpr_type,
&ett_sna_control_0e,
};
module_t *sna_module;
proto_sna = proto_register_protocol("Systems Network Architecture",
"SNA", "sna");
proto_register_field_array(proto_sna, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("sna", dissect_sna, proto_sna);
proto_sna_xid = proto_register_protocol(
"Systems Network Architecture XID", "SNA XID", "sna_xid");
register_dissector("sna_xid", dissect_sna_xid, proto_sna_xid);
sna_module = prefs_register_protocol(proto_sna, NULL);
prefs_register_bool_preference(sna_module, "defragment",
"Reassemble fragmented BIUs",
"Whether fragmented BIUs should be reassembled",
&sna_defragment);
register_init_routine(sna_init);
}
void
proto_reg_handoff_sna(void)
{
dissector_handle_t sna_handle;
dissector_handle_t sna_xid_handle;
sna_handle = find_dissector("sna");
sna_xid_handle = find_dissector("sna_xid");
dissector_add_uint("llc.dsap", SAP_SNA_PATHCTRL, sna_handle);
dissector_add_uint("llc.dsap", SAP_SNA1, sna_handle);
dissector_add_uint("llc.dsap", SAP_SNA2, sna_handle);
dissector_add_uint("llc.dsap", SAP_SNA3, sna_handle);
dissector_add_uint("llc.xid_dsap", SAP_SNA_PATHCTRL, sna_xid_handle);
dissector_add_uint("llc.xid_dsap", SAP_SNA1, sna_xid_handle);
dissector_add_uint("llc.xid_dsap", SAP_SNA2, sna_xid_handle);
dissector_add_uint("llc.xid_dsap", SAP_SNA3, sna_xid_handle);
dissector_add_uint("ppp.protocol", PPP_SNA, sna_handle);
data_handle = find_dissector("data");
}
