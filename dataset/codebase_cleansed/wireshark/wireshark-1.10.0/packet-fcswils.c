static gint
fcswils_equal(gconstpointer v, gconstpointer w)
{
const fcswils_conv_key_t *v1 = (const fcswils_conv_key_t *)v;
const fcswils_conv_key_t *v2 = (const fcswils_conv_key_t *)w;
return (v1->conv_idx == v2->conv_idx);
}
static guint
fcswils_hash(gconstpointer v)
{
const fcswils_conv_key_t *key = (const fcswils_conv_key_t *)v;
guint val;
val = key->conv_idx;
return val;
}
static void
fcswils_init_protocol(void)
{
if (fcswils_req_hash)
g_hash_table_destroy(fcswils_req_hash);
fcswils_req_hash = g_hash_table_new(fcswils_hash, fcswils_equal);
}
static guint8 *
zonenm_to_str(tvbuff_t *tvb, gint offset)
{
int len = tvb_get_guint8(tvb, offset);
return tvb_get_ephemeral_string(tvb, offset+4, len);
}
static gint
get_zoneobj_len(tvbuff_t *tvb, gint offset)
{
gint numrec, numrec1;
guint8 objtype;
gint i, j, len;
objtype = tvb_get_guint8(tvb, offset);
len = 4 + ZONENAME_LEN(tvb, offset+4);
numrec = tvb_get_ntohl(tvb, offset+len);
len += 4;
for (i = 0; i < numrec; i++) {
if (objtype == FC_SWILS_ZONEOBJ_ZONESET) {
len += 4 + ZONENAME_LEN(tvb, offset+4+len);
numrec1 = tvb_get_ntohl(tvb, offset+len);
len += 4;
for (j = 0; j < numrec1; j++) {
len += 4 + tvb_get_guint8(tvb, offset+3+len);
}
}
else {
len += 4 + tvb_get_guint8(tvb, offset+3+len);
}
}
return len;
}
static int
dissect_swils_interconnect_element_info(tvbuff_t *tvb, proto_tree *tree, int offset)
{
int len, max_len = MAX_INTERCONNECT_ELEMENT_INFO_LEN;
if (tree) {
proto_tree_add_item(tree, hf_swils_interconnect_list_len, tvb, offset+3, 1, ENC_BIG_ENDIAN);
len = tvb_strsize(tvb, offset+4);
proto_tree_add_item(tree, hf_swils_ess_vendorname, tvb, offset+4, len, ENC_ASCII|ENC_NA);
offset += (4 + len);
max_len -= len;
len = tvb_strsize(tvb, offset);
proto_tree_add_item(tree, hf_swils_ess_modelname, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
max_len -= len;
len = tvb_strsize(tvb, offset);
proto_tree_add_item(tree, hf_swils_ess_relcode, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
max_len -= len;
while (max_len > 0) {
len = tvb_strsize(tvb, offset);
proto_tree_add_item(tree, hf_swils_ess_vendorspecific, tvb, offset, len, ENC_ASCII|ENC_NA);
offset += len;
max_len -= len;
}
}
return TRUE;
}
static void
dissect_swils_ess_capability(tvbuff_t *tvb, proto_tree *tree, int offset,
guint8 srvr_type)
{
if (tree) {
switch (srvr_type) {
case FCCT_GSRVR_DNS:
proto_tree_add_item(tree, hf_swils_ess_dns_zlacc, tvb, offset+3,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_dns_obj3h, tvb, offset+3,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_dns_obj2h, tvb, offset+3,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_dns_obj1h, tvb, offset+3,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_dns_obj0h, tvb, offset+3,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_dns_vendor, tvb,
offset+4, 4, ENC_BIG_ENDIAN);
break;
case FCCT_GSRVR_FCTLR:
proto_tree_add_item(tree, hf_swils_ess_fctlr_rscn, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fctlr_vendor, tvb,
offset+4, 4, ENC_BIG_ENDIAN);
break;
case FCCT_GSRVR_FCS:
proto_tree_add_item(tree, hf_swils_ess_fcs_basic, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fcs_platform, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fcs_topology, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fcs_enhanced, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
break;
case FCCT_GSRVR_FZS:
proto_tree_add_item(tree, hf_swils_ess_fzs_enh_supp, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fzs_enh_ena, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fzs_mr, tvb, offset+3,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fzs_defzone, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fzs_zsdb_supp, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fzs_zsdb_ena, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fzs_adc_supp, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ess_fzs_hardzone, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
}
return;
}
static int
dissect_swils_ess_capability_obj(tvbuff_t *tvb, proto_tree *tree, int offset)
{
int i = 0, num_entries = 0, len = 0, total_len = 0;
guint8 type, subtype, srvr_type;
proto_item *ti = NULL;
proto_tree *capinfo_tree = NULL;
if (tree) {
type = tvb_get_guint8(tvb, offset);
if (type != FCCT_GSTYPE_VENDOR) {
num_entries = tvb_get_guint8(tvb, offset+3);
total_len = 4 + (num_entries*8);
ti = proto_tree_add_text(tree, tvb, offset,
total_len, "Capability Object (%s)",
val_to_str(type, fc_ct_gstype_vals,
"Unknown (0x%x)"));
capinfo_tree = proto_item_add_subtree(ti, ett_fcswils_capinfo);
} else {
i = tvb_get_guint8(tvb, offset+3);
i += 12;
ti = proto_tree_add_text(tree, tvb, offset,
i, "Capability Object (Vendor-specific 0x%x)",
type);
capinfo_tree = proto_item_add_subtree(ti, ett_fcswils_capinfo);
}
proto_tree_add_item(capinfo_tree, hf_swils_ess_cap_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(capinfo_tree, hf_swils_ess_cap_subtype, tvb, offset+1,
1, ENC_BIG_ENDIAN);
subtype = tvb_get_guint8(tvb, offset+1);
if (type != FCCT_GSTYPE_VENDOR) {
srvr_type = get_gs_server(type, subtype);
proto_tree_add_uint(capinfo_tree, hf_swils_ess_cap_svc, tvb, offset, 2,
srvr_type);
proto_tree_add_item(capinfo_tree, hf_swils_ess_cap_numentries, tvb,
offset+3, 1, ENC_BIG_ENDIAN);
offset += 4;
len += 4;
while ((num_entries > 0) && tvb_bytes_exist(tvb, offset, 8)) {
dissect_swils_ess_capability(tvb, capinfo_tree, offset, srvr_type);
num_entries--;
offset += 8;
len += 8;
}
} else {
proto_tree_add_item(capinfo_tree, hf_swils_ess_cap_len, tvb, offset+3,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(capinfo_tree, hf_swils_ess_cap_t10, tvb, offset+4,
8, ENC_ASCII|ENC_NA);
i -= 8;
offset += 12;
len += 12;
while ((i > 0) && tvb_bytes_exist(tvb, offset, 8)) {
proto_tree_add_item(capinfo_tree, hf_swils_ess_cap_vendorobj,
tvb, offset, 8, ENC_NA);
i -= 8;
offset += 8;
len += 12;
}
}
}
return len;
}
static void
dissect_swils_nullpayload(tvbuff_t *tvb _U_, proto_tree *tree _U_,
guint8 isreq _U_)
{
return;
}
static void
dissect_swils_elp(tvbuff_t *tvb, proto_tree *elp_tree, guint8 isreq _U_)
{
int offset = 0;
const gchar *flags;
fcswils_elp elp;
tvb_memcpy(tvb, (guint8 *)&elp, 4, FC_SWILS_ELP_SIZE);
elp.r_a_tov = g_ntohl(elp.r_a_tov);
elp.e_d_tov = g_ntohl(elp.e_d_tov);
elp.isl_flwctrl_mode = g_ntohs(elp.isl_flwctrl_mode);
elp.flw_ctrl_parmlen = g_ntohs(elp.flw_ctrl_parmlen);
if (elp_tree) {
offset += 4;
proto_tree_add_item(elp_tree, hf_swils_elp_rev, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(elp_tree, hf_swils_elp_flags, tvb, offset, 2, ENC_NA);
offset += 3;
proto_tree_add_uint_format(elp_tree, hf_swils_elp_r_a_tov, tvb, offset, 4,
elp.r_a_tov, "R_A_TOV: %d msecs", elp.r_a_tov);
offset += 4;
proto_tree_add_uint_format(elp_tree, hf_swils_elp_e_d_tov, tvb, offset, 4,
elp.e_d_tov, "E_D_TOV: %d msecs", elp.e_d_tov);
offset += 4;
proto_tree_add_string(elp_tree, hf_swils_elp_req_epn, tvb, offset, 8,
fcwwn_to_str(elp.req_epname));
offset += 8;
proto_tree_add_string(elp_tree, hf_swils_elp_req_esn, tvb, offset, 8,
fcwwn_to_str(elp.req_sname));
offset += 8;
if (elp.clsf_svcparm[0] & 0x80) {
if (elp.clsf_svcparm[4] & 0x20) {
flags="Class F Valid | X_ID Interlock";
} else {
flags="Class F Valid | No X_ID Interlk";
}
} else {
flags="Class F Invld";
}
proto_tree_add_bytes_format(elp_tree, hf_swils_elp_clsf_svcp, tvb, offset, 6,
&elp.clsf_svcparm[0], "Class F Svc Parameters: (%s)", flags);
offset += 6;
proto_tree_add_item(elp_tree, hf_swils_elp_clsf_rcvsz, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(elp_tree, hf_swils_elp_clsf_conseq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(elp_tree, hf_swils_elp_clsf_e2e, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(elp_tree, hf_swils_elp_clsf_openseq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 4;
if (elp.cls1_svcparm[0] & 0x80) {
#define MAX_FLAGS_LEN 40
char *flagsbuf;
gint stroff, returned_length;
flagsbuf=(char *)ep_alloc(MAX_FLAGS_LEN);
stroff = 0;
returned_length = g_snprintf(flagsbuf+stroff, MAX_FLAGS_LEN-stroff,
"Class 1 Valid");
stroff += MIN(returned_length, MAX_FLAGS_LEN-stroff);
if (elp.cls1_svcparm[0] & 0x40) {
returned_length = g_snprintf(flagsbuf+stroff, MAX_FLAGS_LEN-stroff, " | IMX");
stroff += MIN(returned_length, MAX_FLAGS_LEN-stroff);
}
if (elp.cls1_svcparm[0] & 0x20) {
returned_length = g_snprintf(flagsbuf+stroff, MAX_FLAGS_LEN-stroff, " | IPS");
stroff += MIN(returned_length, MAX_FLAGS_LEN-stroff);
}
if (elp.cls1_svcparm[0] & 0x10) {
returned_length = g_snprintf(flagsbuf+stroff, MAX_FLAGS_LEN-stroff, " | LKS");
}
flags=flagsbuf;
}
else {
flags="Class 1 Invalid";
}
proto_tree_add_bytes_format(elp_tree, hf_swils_elp_cls1_svcp, tvb, offset, 2,
NULL, "Class 1 Svc Parameters: (%s)", flags);
offset += 2;
if (elp.cls1_svcparm[0] & 0x80) {
proto_tree_add_item(elp_tree, hf_swils_elp_cls1_rcvsz, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
if (elp.cls2_svcparm[0] & 0x80) {
if (elp.cls2_svcparm[0] & 0x08) {
flags="Class 2 Valid | Seq Delivery";
}
else {
flags="Class 2 Valid | No Seq Delivery";
}
}
else {
flags="Class 2 Invld";
}
proto_tree_add_bytes_format(elp_tree, hf_swils_elp_cls2_svcp, tvb, offset, 2,
&elp.cls2_svcparm[0],
"Class 2 Svc Parameters: (%s)", flags);
offset += 2;
if (elp.cls2_svcparm[0] & 0x80) {
proto_tree_add_item(elp_tree, hf_swils_elp_cls2_rcvsz, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
if (elp.cls3_svcparm[0] & 0x80) {
if (elp.cls3_svcparm[0] & 0x08) {
flags="Class 3 Valid | Seq Delivery";
}
else {
flags="Class 3 Valid | No Seq Delivery";
}
}
else {
flags="Class 3 Invld";
}
proto_tree_add_bytes_format(elp_tree, hf_swils_elp_cls3_svcp, tvb, offset, 2,
&elp.cls3_svcparm[0],
"Class 3 Svc Parameters: (%s)", flags);
offset += 2;
if (elp.cls3_svcparm[0] & 0x80) {
proto_tree_add_item(elp_tree, hf_swils_elp_cls3_rcvsz, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 22;
proto_tree_add_string(elp_tree, hf_swils_elp_isl_fc_mode, tvb, offset, 2,
val_to_str_const(elp.isl_flwctrl_mode, fcswils_elp_fc_val, "Vendor Unique"));
offset += 2;
proto_tree_add_item(elp_tree, hf_swils_elp_fcplen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(elp_tree, hf_swils_elp_b2bcredit, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(elp_tree, hf_swils_elp_compat1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(elp_tree, hf_swils_elp_compat2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(elp_tree, hf_swils_elp_compat3, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(elp_tree, hf_swils_elp_compat4, tvb, offset, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_swils_efp(tvbuff_t *tvb, proto_tree *efp_tree, guint8 isreq _U_)
{
proto_item *subti;
proto_tree *lrec_tree;
int num_listrec = 0;
int offset = 0;
fcswils_efp efp;
guint8 rec_type;
offset += 1;
efp.reclen = tvb_get_guint8(tvb, offset);
if (efp_tree)
proto_tree_add_uint(efp_tree, hf_swils_efp_record_len, tvb, offset, 1, efp.reclen);
offset += 1;
efp.payload_len = tvb_get_ntohs(tvb, offset);
if (efp.payload_len < FC_SWILS_EFP_SIZE) {
if (efp_tree)
proto_tree_add_uint_format(efp_tree, hf_swils_efp_payload_len,
tvb, offset, 2, efp.payload_len,
"Payload Len: %u (bogus, must be >= %u)",
efp.payload_len, FC_SWILS_EFP_SIZE);
return;
}
if (efp_tree)
proto_tree_add_item(efp_tree, hf_swils_efp_payload_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 5;
if (efp_tree)
proto_tree_add_item(efp_tree, hf_swils_efp_pswitch_pri, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset += 1;
tvb_memcpy(tvb, efp.pswitch_name, offset, 8);
if (efp_tree)
proto_tree_add_string(efp_tree, hf_swils_efp_pswitch_name, tvb, offset,
8, fcwwn_to_str(efp.pswitch_name));
offset += 8;
if (efp_tree) {
if (efp.reclen == 0) {
proto_tree_add_text(efp_tree, tvb, 0, 0, "Record length is zero");
return;
}
num_listrec = (efp.payload_len - FC_SWILS_EFP_SIZE)/efp.reclen;
while (num_listrec-- > 0) {
rec_type = tvb_get_guint8(tvb, offset);
subti = proto_tree_add_text(efp_tree, tvb, offset, -1,
"%s",
val_to_str(rec_type,
fcswils_rectype_val,
"Unknown record type (0x%02x)"));
lrec_tree = proto_item_add_subtree(subti, ett_fcswils_efplist);
proto_tree_add_uint(lrec_tree, hf_swils_efp_rec_type, tvb, offset, 1,
rec_type);
switch (rec_type) {
case FC_SWILS_LRECTYPE_DOMAIN:
proto_tree_add_item(lrec_tree, hf_swils_efp_dom_id, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_string(lrec_tree, hf_swils_efp_switch_name, tvb, offset+8, 8,
tvb_fcwwn_to_str(tvb, offset+8));
break;
case FC_SWILS_LRECTYPE_MCAST:
proto_tree_add_item(lrec_tree, hf_swils_efp_mcast_grpno, tvb, offset+1, 1, ENC_BIG_ENDIAN);
break;
}
offset += efp.reclen;
}
}
}
static void
dissect_swils_dia(tvbuff_t *tvb, proto_tree *dia_tree, guint8 isreq _U_)
{
int offset = 0;
if (dia_tree) {
proto_tree_add_string(dia_tree, hf_swils_dia_switch_name, tvb, offset+4,
8, tvb_fcwwn_to_str(tvb, offset+4));
}
}
static void
dissect_swils_rdi(tvbuff_t *tvb, proto_tree *rdi_tree, guint8 isreq)
{
int offset = 0;
int i, plen, numrec;
if (rdi_tree) {
plen = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_item(rdi_tree, hf_swils_rdi_payload_len, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_string(rdi_tree, hf_swils_rdi_req_sname, tvb, offset+4,
8, tvb_fcwwn_to_str(tvb, offset+4));
numrec = (plen - 12)/4;
offset = 12;
for (i = 0; i < numrec; i++) {
if (isreq) {
proto_tree_add_text(rdi_tree, tvb, offset+3, 1,
"Requested Domain ID: %d",
tvb_get_guint8(tvb, offset+3));
}
else {
proto_tree_add_text(rdi_tree, tvb, offset+3, 1,
"Granted Domain ID: %d",
tvb_get_guint8(tvb, offset+3));
}
offset += 4;
}
}
}
static void
dissect_swils_fspf_hdr(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *subti;
proto_tree *fspfh_tree;
if (tree) {
subti = proto_tree_add_text(tree, tvb, offset, 20, "FSPF Header");
fspfh_tree = proto_item_add_subtree(subti, ett_fcswils_fspfhdr);
proto_tree_add_item(fspfh_tree, hf_swils_fspfh_rev, tvb, offset+4,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(fspfh_tree, hf_swils_fspfh_ar_num, tvb,
offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fspfh_tree, hf_swils_fspfh_auth_type, tvb,
offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fspfh_tree, hf_swils_fspfh_dom_id, tvb, offset+11,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(fspfh_tree, hf_swils_fspfh_auth, tvb, offset+12,
8, ENC_NA);
}
}
static void
dissect_swils_fspf_lsrechdr(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_swils_lsrh_lsr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, offset+2, 2, "LSR Age: %d secs",
tvb_get_ntohs(tvb, offset+2));
proto_tree_add_text(tree, tvb, offset+4, 4, "Options : 0x%x",
tvb_get_ntohl(tvb, offset+4));
proto_tree_add_item(tree, hf_swils_lsrh_lsid, tvb, offset+11, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_lsrh_adv_domid, tvb, offset+15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_lsrh_ls_incid, tvb, offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, offset+20, 2, "Checksum: 0x%x",
tvb_get_ntohs(tvb, offset+20));
proto_tree_add_text(tree, tvb, offset+22, 2, "LSR Length: %d",
tvb_get_ntohs(tvb, offset+22));
}
static void
dissect_swils_fspf_ldrec(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_string(tree, hf_swils_ldrec_linkid, tvb, offset, 4,
tvb_fc_to_str(tvb, offset+1));
proto_tree_add_item(tree, hf_swils_ldrec_out_pidx, tvb, offset+5, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ldrec_nbr_pidx, tvb, offset+9, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ldrec_link_type, tvb, offset+12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_ldrec_link_cost, tvb, offset+14, 2, ENC_BIG_ENDIAN);
}
static void
dissect_swils_fspf_lsrec(tvbuff_t *tvb, proto_tree *tree, int offset,
int num_lsrec)
{
int i, j, num_ldrec;
proto_item *subti1, *subti;
proto_tree *lsrec_tree, *ldrec_tree, *lsrechdr_tree;
if (tree) {
for (j = 0; j < num_lsrec; j++) {
num_ldrec = tvb_get_ntohs(tvb, offset+26);
subti = proto_tree_add_text(tree, tvb, offset, (28+num_ldrec*16),
"Link State Record %d (Domain %d)", j,
tvb_get_guint8(tvb, offset+15));
lsrec_tree = proto_item_add_subtree(subti, ett_fcswils_lsrec);
subti = proto_tree_add_text(lsrec_tree, tvb, offset, 24,
"Link State Record Header");
lsrechdr_tree = proto_item_add_subtree(subti,
ett_fcswils_lsrechdr);
dissect_swils_fspf_lsrechdr(tvb, lsrechdr_tree, offset);
proto_tree_add_text(tree, tvb, offset+26, 2, "Number of Links: %d",
num_ldrec);
offset += 28;
for (i = 0; i < num_ldrec; i++) {
subti1 = proto_tree_add_text(lsrec_tree, tvb, offset, 16,
"Link Descriptor %d "
"(Neighbor domain %d)", i,
tvb_get_guint8(tvb, offset+3));
ldrec_tree = proto_item_add_subtree(subti1, ett_fcswils_ldrec);
dissect_swils_fspf_ldrec(tvb, ldrec_tree, offset);
offset += 16;
}
}
}
}
static void
dissect_swils_hello(tvbuff_t *tvb, proto_tree *hlo_tree, guint8 isreq _U_)
{
int offset = 0;
if (hlo_tree) {
dissect_swils_fspf_hdr(tvb, hlo_tree, offset);
proto_tree_add_item(hlo_tree, hf_swils_hlo_options, tvb, offset+20, 4, ENC_NA);
proto_tree_add_item(hlo_tree, hf_swils_hlo_hloint, tvb, offset+24, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(hlo_tree, hf_swils_hlo_deadint, tvb, offset+28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(hlo_tree, hf_swils_hlo_rcv_domid, tvb, offset+35, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hlo_tree, hf_swils_hlo_orig_pidx, tvb, offset+37, 3, ENC_BIG_ENDIAN);
}
}
static void
dissect_swils_lsupdate(tvbuff_t *tvb, proto_tree *lsu_tree, guint8 isreq _U_)
{
int offset = 0;
int num_lsrec;
if (lsu_tree) {
dissect_swils_fspf_hdr(tvb, lsu_tree, offset);
proto_tree_add_text(lsu_tree, tvb, offset+23, 1, "Flags : %s",
val_to_str(tvb_get_guint8(tvb, offset+23),
fc_swils_fspf_lsrflags_val, "0x%x"));
num_lsrec = tvb_get_ntohl(tvb, offset+24);
proto_tree_add_text(lsu_tree, tvb, offset+24, 4, "Num of LSRs: %d",
num_lsrec);
offset = 28;
dissect_swils_fspf_lsrec(tvb, lsu_tree, offset, num_lsrec);
}
}
static void
dissect_swils_lsack(tvbuff_t *tvb, proto_tree *lsa_tree, guint8 isreq _U_)
{
int offset = 0;
int num_lsrechdr, i;
proto_item *subti;
proto_tree *lsrechdr_tree;
if (lsa_tree) {
dissect_swils_fspf_hdr(tvb, lsa_tree, offset);
proto_tree_add_text(lsa_tree, tvb, offset+23, 1, "Flags : %s",
val_to_str(tvb_get_guint8(tvb, offset+23),
fc_swils_fspf_lsrflags_val, "0x%x"));
num_lsrechdr = tvb_get_ntohl(tvb, offset+24);
proto_tree_add_text(lsa_tree, tvb, offset+24, 4, "Num of LSR Headers: %d",
num_lsrechdr);
offset = 28;
for (i = 0; i < num_lsrechdr; i++) {
subti = proto_tree_add_text(lsa_tree, tvb, offset, 24,
"Link State Record Header (Domain %d)",
tvb_get_guint8(tvb, offset+15));
lsrechdr_tree = proto_item_add_subtree(subti,
ett_fcswils_lsrechdr);
dissect_swils_fspf_lsrechdr(tvb, lsrechdr_tree, offset);
offset += 24;
}
}
}
static void
dissect_swils_rscn(tvbuff_t *tvb, proto_tree *rscn_tree, guint8 isreq)
{
int offset = 0;
proto_tree *dev_tree;
int numrec, i;
proto_item *subti;
if (rscn_tree) {
if (!isreq)
return;
proto_tree_add_item(rscn_tree, hf_swils_rscn_evtype, tvb, offset+4,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(rscn_tree, hf_swils_rscn_addrfmt, tvb, offset+4,
1, ENC_BIG_ENDIAN);
proto_tree_add_string(rscn_tree, hf_swils_rscn_affectedport, tvb,
offset+5, 3, tvb_fc_to_str(tvb, offset+5));
proto_tree_add_item(rscn_tree, hf_swils_rscn_detectfn, tvb,
offset+8, 4, ENC_BIG_ENDIAN);
numrec = tvb_get_ntohl(tvb, offset+12);
if (!tvb_bytes_exist(tvb, offset+16, FC_SWILS_RSCN_DEVENTRY_SIZE*numrec)) {
return;
}
proto_tree_add_text(rscn_tree, tvb, offset+12, 4, "Num Entries: %d",
numrec);
offset = 16;
for (i = 0; i < numrec; i++) {
subti = proto_tree_add_text(rscn_tree, tvb, offset, 20,
"Device Entry %d", i);
dev_tree = proto_item_add_subtree(subti, ett_fcswils_rscn_dev);
proto_tree_add_item(dev_tree, hf_swils_rscn_portstate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_string(dev_tree, hf_swils_rscn_portid, tvb, offset+1, 3,
tvb_fc_to_str(tvb, offset+1));
proto_tree_add_string(dev_tree, hf_swils_rscn_pwwn, tvb, offset+4, 8,
tvb_fcwwn_to_str(tvb, offset+4));
proto_tree_add_string(dev_tree, hf_swils_rscn_nwwn, tvb, offset+12, 8,
tvb_fcwwn_to_str(tvb, offset+12));
offset += 20;
}
}
}
static void
dissect_swils_zone_mbr(tvbuff_t *tvb, proto_tree *zmbr_tree, int offset)
{
guint8 mbrtype;
int idlen;
char dpbuf[2+8+1];
char *str;
mbrtype = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(zmbr_tree, hf_swils_zone_mbrtype, tvb,
offset, 1, mbrtype);
proto_tree_add_text(zmbr_tree, tvb, offset+2, 1, "Flags: 0x%x",
tvb_get_guint8(tvb, offset+2));
idlen = tvb_get_guint8(tvb, offset+3);
proto_tree_add_text(zmbr_tree, tvb, offset+3, 1,
"Identifier Length: %u", idlen);
switch (mbrtype) {
case FC_SWILS_ZONEMBR_WWN:
proto_tree_add_string(zmbr_tree, hf_swils_zone_mbrid, tvb,
offset+4, 8,
tvb_fcwwn_to_str(tvb, offset+4));
break;
case FC_SWILS_ZONEMBR_DP:
g_snprintf(dpbuf, sizeof(dpbuf), "0x%08x", tvb_get_ntohl(tvb, offset+4));
proto_tree_add_string(zmbr_tree, hf_swils_zone_mbrid, tvb,
offset+4, 4, dpbuf);
break;
case FC_SWILS_ZONEMBR_FCID:
proto_tree_add_string(zmbr_tree, hf_swils_zone_mbrid, tvb,
offset+4, 4,
tvb_fc_to_str(tvb, offset+5));
break;
case FC_SWILS_ZONEMBR_ALIAS:
str = zonenm_to_str(tvb, offset+4);
proto_tree_add_string(zmbr_tree, hf_swils_zone_mbrid, tvb,
offset+4, idlen, str);
break;
case FC_SWILS_ZONEMBR_WWN_LUN:
proto_tree_add_string(zmbr_tree, hf_swils_zone_mbrid, tvb,
offset+4, 8,
tvb_fcwwn_to_str(tvb, offset+4));
proto_tree_add_item(zmbr_tree, hf_swils_zone_mbrid_lun, tvb,
offset+12, 8, ENC_NA);
break;
case FC_SWILS_ZONEMBR_DP_LUN:
g_snprintf(dpbuf, sizeof(dpbuf), "0x%08x", tvb_get_ntohl(tvb, offset+4));
proto_tree_add_string(zmbr_tree, hf_swils_zone_mbrid, tvb,
offset+4, 4, dpbuf);
proto_tree_add_item(zmbr_tree, hf_swils_zone_mbrid_lun, tvb,
offset+8, 8, ENC_NA);
break;
case FC_SWILS_ZONEMBR_FCID_LUN:
proto_tree_add_string(zmbr_tree, hf_swils_zone_mbrid, tvb,
offset+4, 4,
tvb_fc_to_str(tvb, offset+5));
proto_tree_add_item(zmbr_tree, hf_swils_zone_mbrid_lun, tvb,
offset+8, 8, ENC_NA);
break;
default:
proto_tree_add_string(zmbr_tree, hf_swils_zone_mbrid, tvb,
offset+4, idlen,
"Unknown member type format");
}
}
static void
dissect_swils_zone_obj(tvbuff_t *tvb, proto_tree *zobj_tree, int offset)
{
proto_tree *zmbr_tree;
int mbrlen, numrec, i, objtype;
char *str;
proto_item *subti;
objtype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(zobj_tree, hf_swils_zone_objtype, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(zobj_tree, hf_swils_zone_protocol, tvb,
offset+1, 1, ENC_BIG_ENDIAN);
str = zonenm_to_str(tvb, offset+4);
proto_tree_add_string(zobj_tree, hf_swils_zone_objname, tvb,
offset+4, ZONENAME_LEN(tvb, offset+4), str);
numrec = tvb_get_ntohl(tvb, offset+4+ZONENAME_LEN(tvb, offset+4));
proto_tree_add_text(zobj_tree, tvb,
offset+4+ZONENAME_LEN(tvb, offset+4), 4,
"Number of Zone Members: %d", numrec);
offset += 8 + ZONENAME_LEN(tvb, offset+4);
for (i = 0; i < numrec; i++) {
if (objtype == FC_SWILS_ZONEOBJ_ZONESET) {
dissect_swils_zone_obj(tvb, zobj_tree, offset);
offset += get_zoneobj_len(tvb, offset);
}
else {
mbrlen = 4 + tvb_get_guint8(tvb, offset+3);
subti = proto_tree_add_text(zobj_tree, tvb, offset, mbrlen,
"Zone Member %d", i);
zmbr_tree = proto_item_add_subtree(subti,
ett_fcswils_zonembr);
dissect_swils_zone_mbr(tvb, zmbr_tree, offset);
offset += mbrlen;
}
}
}
static void
dissect_swils_mergereq(tvbuff_t *tvb, proto_tree *mr_tree, guint8 isreq)
{
int offset = 0;
proto_tree *zobjlist_tree, *zobj_tree;
int numrec, i, zonesetlen, objlistlen, objlen;
char *str;
proto_item *subti;
if (mr_tree) {
if (isreq) {
zonesetlen = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(mr_tree, tvb, offset+2, 2,
"Active ZoneSet Length: %u", zonesetlen);
if (zonesetlen) {
str = zonenm_to_str(tvb, offset+4);
proto_tree_add_string(mr_tree, hf_swils_zone_activezonenm, tvb,
offset+4, ZONENAME_LEN(tvb, offset+4),
str);
objlistlen = zonesetlen - ZONENAME_LEN(tvb, offset+4);
offset = offset + (4 + ZONENAME_LEN(tvb, offset+4));
numrec = tvb_get_ntohl(tvb, offset);
subti = proto_tree_add_text(mr_tree, tvb, offset, objlistlen,
"Active Zone Set");
zobjlist_tree = proto_item_add_subtree(subti,
ett_fcswils_zoneobjlist);
proto_tree_add_text(zobjlist_tree, tvb, offset, 4,
"Number of zoning objects: %d", numrec);
offset += 4;
for (i = 0; i < numrec; i++) {
objlen = get_zoneobj_len(tvb, offset);
subti = proto_tree_add_text(zobjlist_tree, tvb, offset+4,
objlen, "Zone Object %d", i);
zobj_tree = proto_item_add_subtree(subti, ett_fcswils_zoneobj);
dissect_swils_zone_obj(tvb, zobj_tree, offset);
offset += objlen;
}
}
else {
offset += 4;
}
zonesetlen = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(mr_tree, tvb, offset, 4,
"Full Zone Set Length: %d", zonesetlen);
if (zonesetlen) {
objlistlen = zonesetlen;
offset += 4;
numrec = tvb_get_ntohl(tvb, offset);
subti = proto_tree_add_text(mr_tree, tvb, offset, objlistlen,
"Full Zone Set");
zobjlist_tree = proto_item_add_subtree(subti,
ett_fcswils_zoneobjlist);
proto_tree_add_text(zobjlist_tree, tvb, offset, 4,
"Number of zoning objects: %d", numrec);
offset += 4;
for (i = 0; i < numrec; i++) {
objlen = get_zoneobj_len(tvb, offset);
subti = proto_tree_add_text(zobjlist_tree, tvb, offset,
objlen, "Zone Object %d", i);
zobj_tree = proto_item_add_subtree(subti, ett_fcswils_zoneobj);
dissect_swils_zone_obj(tvb, zobj_tree, offset);
offset += objlen;
}
}
}
else {
proto_tree_add_item(mr_tree, hf_swils_zone_status, tvb,
offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mr_tree, hf_swils_zone_reason, tvb,
offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(mr_tree, tvb, offset+7, 1,
"Vendor Unique: 0x%x",
tvb_get_guint8(tvb, offset+7));
}
}
}
static void
dissect_swils_aca(tvbuff_t *tvb, proto_tree *aca_tree, guint8 isreq)
{
int offset = 0;
int numrec, plen, i;
if (aca_tree) {
if (isreq) {
plen = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(aca_tree, tvb, offset+2, 2,
"Domain ID List Length: %d", plen);
numrec = plen/4;
offset = 4;
for (i = 0; i < numrec; i++) {
proto_tree_add_uint_format(aca_tree, hf_swils_aca_domainid,
tvb, offset+3, 1,
tvb_get_guint8(tvb, offset+3),
"Domain ID %d: %d", i,
tvb_get_guint8(tvb, offset+3));
offset += 4;
}
}
else {
proto_tree_add_item(aca_tree, hf_swils_zone_status, tvb,
offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(aca_tree, hf_swils_zone_reason, tvb,
offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(aca_tree, tvb, offset+7, 1,
"Vendor Unique: 0x%x",
tvb_get_guint8(tvb, offset+7));
}
}
}
static void
dissect_swils_rca(tvbuff_t *tvb, proto_tree *rca_tree, guint8 isreq)
{
int offset = 0;
if (rca_tree) {
if (!isreq) {
proto_tree_add_item(rca_tree, hf_swils_zone_status, tvb,
offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rca_tree, hf_swils_zone_reason, tvb,
offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(rca_tree, tvb, offset+7, 1,
"Vendor Unique: 0x%x",
tvb_get_guint8(tvb, offset+7));
}
}
}
static void
dissect_swils_sfc(tvbuff_t *tvb, proto_tree *sfc_tree, guint8 isreq)
{
int offset = 0;
proto_tree *zobjlist_tree, *zobj_tree;
int numrec, i, zonesetlen, objlistlen, objlen;
char *str;
proto_item *subti;
if (sfc_tree) {
if (isreq) {
proto_tree_add_item(sfc_tree, hf_swils_sfc_opcode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
zonesetlen = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(sfc_tree, tvb, offset+2, 2,
"ZoneSet Length: %d", zonesetlen);
if (zonesetlen) {
str = zonenm_to_str(tvb, offset+4);
proto_tree_add_string(sfc_tree, hf_swils_sfc_zonenm, tvb,
offset+4, ZONENAME_LEN(tvb, offset+4),
str);
objlistlen = zonesetlen - ZONENAME_LEN(tvb, offset+4);
offset = offset + (4 + ZONENAME_LEN(tvb, offset+4));
numrec = tvb_get_ntohl(tvb, offset);
subti = proto_tree_add_text(sfc_tree, tvb, offset, objlistlen,
"Zone Set");
zobjlist_tree = proto_item_add_subtree(subti,
ett_fcswils_zoneobjlist);
proto_tree_add_text(zobjlist_tree, tvb, offset, 4,
"Number of zoning objects: %d", numrec);
offset += 4;
for (i = 0; i < numrec; i++) {
objlen = get_zoneobj_len(tvb, offset);
subti = proto_tree_add_text(zobjlist_tree, tvb, offset,
objlen, "Zone Object %d", i);
zobj_tree = proto_item_add_subtree(subti, ett_fcswils_zoneobj);
dissect_swils_zone_obj(tvb, zobj_tree, offset);
offset += objlen;
}
}
else {
offset += 4;
}
zonesetlen = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(sfc_tree, tvb, offset, 4,
"Full Zone Set Length: %d", zonesetlen);
if (zonesetlen) {
objlistlen = zonesetlen;
offset += 4;
numrec = tvb_get_ntohl(tvb, offset);
subti = proto_tree_add_text(sfc_tree, tvb, offset, objlistlen,
"Full Zone Set");
zobjlist_tree = proto_item_add_subtree(subti,
ett_fcswils_zoneobjlist);
proto_tree_add_text(zobjlist_tree, tvb, offset, 4,
"Number of zoning objects: %d", numrec);
offset += 4;
for (i = 0; i < numrec; i++) {
objlen = get_zoneobj_len(tvb, offset);
subti = proto_tree_add_text(zobjlist_tree, tvb, offset,
objlen, "Zone Object %d", i);
zobj_tree = proto_item_add_subtree(subti, ett_fcswils_zoneobj);
dissect_swils_zone_obj(tvb, zobj_tree, offset);
offset += objlen;
}
}
}
else {
proto_tree_add_item(sfc_tree, hf_swils_zone_status, tvb,
offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sfc_tree, hf_swils_zone_reason, tvb,
offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(sfc_tree, tvb, offset+7, 1,
"Vendor Unique: 0x%x",
tvb_get_guint8(tvb, offset+7));
}
}
}
static void
dissect_swils_ufc(tvbuff_t *tvb, proto_tree *ufc_tree, guint8 isreq)
{
int offset = 0;
if (ufc_tree) {
if (!isreq) {
proto_tree_add_item(ufc_tree, hf_swils_zone_status, tvb,
offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ufc_tree, hf_swils_zone_reason, tvb,
offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(ufc_tree, tvb, offset+7, 1,
"Vendor Unique: 0x%x",
tvb_get_guint8(tvb, offset+7));
}
}
}
static void
dissect_swils_esc(tvbuff_t *tvb, proto_tree *esc_tree, guint8 isreq)
{
int offset = 0;
int i, numrec, plen;
proto_tree *pdesc_tree;
proto_item *subti;
if (esc_tree) {
if (isreq) {
plen = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(esc_tree, tvb, offset+2, 2,
"Payload Length: %d", plen);
proto_tree_add_item(esc_tree, hf_swils_esc_swvendorid, tvb,
offset+4, 8, ENC_ASCII|ENC_NA);
numrec = (plen - 12)/12;
offset = 12;
for (i = 0; i < numrec; i++) {
subti = proto_tree_add_text(esc_tree, tvb, offset, 12,
"Protocol Descriptor %d", i);
pdesc_tree = proto_item_add_subtree(subti,
ett_fcswils_esc_pdesc);
proto_tree_add_item(pdesc_tree, hf_swils_esc_pdesc_vendorid, tvb,
offset, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item(pdesc_tree, hf_swils_esc_protocolid,
tvb, offset+10, 2, ENC_BIG_ENDIAN);
offset += 12;
}
}
else {
proto_tree_add_item(esc_tree, hf_swils_esc_swvendorid, tvb,
offset+4, 8, ENC_ASCII|ENC_NA);
subti = proto_tree_add_text(esc_tree, tvb, offset+12, 12,
"Accepted Protocol Descriptor");
pdesc_tree = proto_item_add_subtree(subti, ett_fcswils_esc_pdesc);
proto_tree_add_item(pdesc_tree, hf_swils_esc_pdesc_vendorid, tvb,
offset+12, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item(pdesc_tree, hf_swils_esc_protocolid,
tvb, offset+22, 2, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_swils_drlir(tvbuff_t *tvb _U_, proto_tree *drlir_tree _U_,
guint8 isreq _U_)
{
return;
}
static void
dissect_swils_swrjt(tvbuff_t *tvb, proto_tree *swrjt_tree, guint8 isreq _U_)
{
int offset = 0;
if (swrjt_tree) {
proto_tree_add_item(swrjt_tree, hf_swils_rjt, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(swrjt_tree, hf_swils_rjtdet, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(swrjt_tree, hf_swils_rjtvendor, tvb, offset+7,
1, ENC_BIG_ENDIAN);
}
}
static void
dissect_swils_ess(tvbuff_t *tvb, proto_tree *ess_tree, guint8 isreq _U_)
{
int offset = 0;
gint16 numcapobj = 0;
gint len = 0;
gint capobjlen = 0;
proto_item *ti = NULL;
proto_tree *ieinfo_tree = NULL;
if (!ess_tree) {
return;
}
proto_tree_add_item(ess_tree, hf_swils_ess_rev, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ess_tree, hf_swils_ess_len, tvb, offset+8, 4, ENC_BIG_ENDIAN);
len = tvb_get_ntohl(tvb, offset+8);
ti = proto_tree_add_text(ess_tree, tvb, offset+12,
MAX_INTERCONNECT_ELEMENT_INFO_LEN+4,
"Interconnect Element Info");
ieinfo_tree = proto_item_add_subtree(ti, ett_fcswils_ieinfo);
dissect_swils_interconnect_element_info(tvb, ieinfo_tree, offset+12);
len -= 256;
offset += 268;
proto_tree_add_item(ess_tree, hf_swils_ess_numobj, tvb, offset, 2, ENC_BIG_ENDIAN);
numcapobj = tvb_get_ntohs(tvb, offset);
len -= 4;
offset += 4;
while ((len > 0) && (numcapobj > 0)) {
capobjlen = dissect_swils_ess_capability_obj(tvb, ess_tree, offset);
numcapobj--;
len -= capobjlen;
offset += capobjlen;
}
}
static void
dissect_swils_mrra(tvbuff_t *tvb, proto_tree *tree, guint8 isreq)
{
int offset = 0;
if (!tree) {
return;
}
if (isreq) {
proto_tree_add_item(tree, hf_swils_mrra_rev, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_mrra_size, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_mrra_vendorid, tvb, offset+12, 8, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_swils_mrra_vendorinfo, tvb, offset+20,
8, ENC_NA);
} else {
proto_tree_add_item(tree, hf_swils_mrra_vendorid, tvb, offset+4,
8, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_swils_mrra_reply, tvb, offset+12,
4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_mrra_reply_size, tvb, offset+16,
4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_swils_mrra_waittime, tvb, offset+20,
4, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcswils(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
guint8 opcode;
guint8 failed_opcode = 0;
int offset = 0;
conversation_t *conversation;
fcswils_conv_data_t *cdata;
fcswils_conv_key_t ckey, *req_key;
proto_tree *swils_tree = NULL;
guint8 isreq = FC_SWILS_REQ;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SW_ILS");
opcode = tvb_get_guint8(tvb, 0);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_fcswils, tvb, 0,
tvb_length(tvb), "SW_ILS");
swils_tree = proto_item_add_subtree(ti, ett_fcswils);
}
if ((opcode != FC_SWILS_SWACC) && (opcode != FC_SWILS_SWRJT)) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->oxid,
pinfo->rxid, NO_PORT2);
if (!conversation) {
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->oxid,
pinfo->rxid, NO_PORT2);
}
ckey.conv_idx = conversation->index;
cdata = (fcswils_conv_data_t *)g_hash_table_lookup(fcswils_req_hash,
&ckey);
if (cdata) {
cdata->opcode = opcode;
}
else {
req_key = se_new(fcswils_conv_key_t);
req_key->conv_idx = conversation->index;
cdata = se_new(fcswils_conv_data_t);
cdata->opcode = opcode;
g_hash_table_insert(fcswils_req_hash, req_key, cdata);
}
}
else {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->oxid,
pinfo->rxid, NO_PORT2);
isreq = FC_SWILS_RPLY;
if (!conversation) {
if (tree && (opcode == FC_SWILS_SWACC)) {
proto_tree_add_text(swils_tree, tvb, 0, tvb_length(tvb),
"No record of Exchg. Unable to decode SW_ACC");
return;
}
}
else {
ckey.conv_idx = conversation->index;
cdata = (fcswils_conv_data_t *)g_hash_table_lookup(fcswils_req_hash, &ckey);
if (cdata != NULL) {
if (opcode == FC_SWILS_SWACC)
opcode = cdata->opcode;
else
failed_opcode = cdata->opcode;
}
if (tree) {
if ((cdata == NULL) && (opcode != FC_SWILS_SWRJT)) {
proto_tree_add_text(swils_tree, tvb, 0, tvb_length(tvb),
"No record of SW_ILS Req. Unable to decode SW_ACC");
return;
}
}
}
}
if (check_col(pinfo->cinfo, COL_INFO)) {
if (isreq == FC_SWILS_REQ) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(opcode, fc_swils_opcode_key_val, "0x%x"));
}
else if (opcode == FC_SWILS_SWRJT) {
col_add_fstr(pinfo->cinfo, COL_INFO, "SW_RJT (%s)",
val_to_str(failed_opcode, fc_swils_opcode_key_val, "0x%x"));
}
else {
col_add_fstr(pinfo->cinfo, COL_INFO, "SW_ACC (%s)",
val_to_str(opcode, fc_swils_opcode_key_val, "0x%x"));
}
}
if (tree) {
proto_tree_add_item(swils_tree, hf_swils_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if ((opcode < FC_SWILS_MAXCODE) && fcswils_func_table[opcode].func) {
fcswils_func_table[opcode].func(tvb, swils_tree, isreq);
} else if (opcode == FC_SWILS_AUTH_ILS) {
if (isreq && fcsp_handle)
call_dissector(fcsp_handle, tvb, pinfo, swils_tree);
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset+4);
call_dissector(data_handle, next_tvb, pinfo, tree);
}
}
void
proto_register_fcswils(void)
{
static hf_register_info hf[] = {
{ &hf_swils_opcode,
{"Cmd Code", "swils.opcode",
FT_UINT8, BASE_HEX, VALS(fc_swils_opcode_key_val), 0x0,
NULL, HFILL}},
{ &hf_swils_elp_rev,
{"Revision", "swils.elp.rev",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_flags,
{"Flag", "swils.elp.flag",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_r_a_tov,
{"R_A_TOV", "swils.elp.ratov",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_e_d_tov,
{"E_D_TOV", "swils.elp.edtov",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_req_epn,
{"Req Eport Name", "swils.elp.reqepn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_req_esn,
{"Req Switch Name", "swils.elp.reqesn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_clsf_svcp,
{"Class F Svc Param", "swils.elp.clsfp",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_clsf_rcvsz,
{"Max Class F Frame Size", "swils.elp.clsfrsz",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_clsf_conseq,
{"Class F Max Concurrent Seq", "swils.elp.clsfcs",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_clsf_e2e,
{"Class F E2E Credit", "swils.elp.cfe2e",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_clsf_openseq,
{"Class F Max Open Seq", "swils.elp.oseq",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_cls1_svcp,
{"Class 1 Svc Param", "swils.elp.cls1p",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_cls1_rcvsz,
{"Class 1 Frame Size", "swils.elp.cls1rsz",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_cls2_svcp,
{"Class 2 Svc Param", "swils.elp.cls2p",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_cls2_rcvsz,
{"Class 2 Frame Size", "swils.elp.cls2rsz",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_cls3_svcp,
{"Class 3 Svc Param", "swils.elp.cls3p",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_cls3_rcvsz,
{"Class 3 Frame Size", "swils.elp.cls3rsz",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_isl_fc_mode,
{"ISL Flow Ctrl Mode", "swils.elp.fcmode",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_fcplen,
{"Flow Ctrl Param Len", "swils.elp.fcplen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_b2bcredit,
{"B2B Credit", "swils.elp.b2b",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_compat1,
{"Compatibility Param 1", "swils.elp.compat1",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_compat2,
{"Compatibility Param 2", "swils.elp.compat2",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_compat3,
{"Compatibility Param 3", "swils.elp.compat3",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_elp_compat4,
{"Compatibility Param 4", "swils.elp.compat4",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_efp_rec_type,
{"Record Type", "swils.efp.rectype",
FT_UINT8, BASE_HEX, VALS(fcswils_rectype_val), 0x0,
NULL, HFILL}},
{ &hf_swils_efp_dom_id,
{"Domain ID", "swils.efp.domid",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_efp_switch_name,
{"Switch Name", "swils.efp.sname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_efp_mcast_grpno,
{"Mcast Grp#", "swils.efp.mcastno",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
#if 0
{ &hf_swils_efp_alias_token,
{"Alias Token", "swils.efp.aliastok",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
#endif
{ &hf_swils_efp_record_len,
{"Record Len", "swils.efp.recordlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_efp_payload_len,
{"Payload Len", "swils.efp.payloadlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_efp_pswitch_pri,
{"Principal Switch Priority", "swils.efp.psprio",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_efp_pswitch_name,
{"Principal Switch Name", "swils.efp.psname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_dia_switch_name,
{"Switch Name", "swils.dia.sname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_rdi_payload_len,
{"Payload Len", "swils.rdi.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_rdi_req_sname,
{"Req Switch Name", "swils.rdi.reqsn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
#if 0
{ &hf_swils_fspfh_cmd,
{"Command:", "swils.fspf.cmd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
#endif
{ &hf_swils_fspfh_rev,
{"Version", "swils.fspf.ver",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_fspfh_ar_num,
{"AR Number", "swils.fspf.arnum",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_fspfh_auth_type,
{"Authentication Type", "swils.fspf.authtype",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_fspfh_dom_id,
{"Originating Domain ID", "swils.fspf.origdomid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_fspfh_auth,
{"Authentication", "swils.fspf.auth",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_hlo_options,
{"Options", "swils.hlo.options",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_hlo_hloint,
{"Hello Interval (secs)", "swils.hlo.hloint",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_hlo_deadint,
{"Dead Interval (secs)", "swils.hlo.deadint",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_hlo_rcv_domid,
{"Recipient Domain ID", "swils.hlo.rcvdomid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_hlo_orig_pidx,
{"Originating Port Idx", "swils.hlo.origpidx",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_lsrh_lsr_type,
{"LSR Type", "swils.lsr.type",
FT_UINT8, BASE_HEX, VALS(fc_swils_fspf_linkrec_val), 0x0,
NULL, HFILL}},
{ &hf_swils_lsrh_lsid,
{"Link State Id", "swils.ls.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_lsrh_adv_domid,
{"Advertising Domain Id", "swils.lsr.advdomid",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_lsrh_ls_incid,
{"LS Incarnation Number", "swils.lsr.incid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ldrec_linkid,
{"Link ID", "swils.ldr.linkid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ldrec_out_pidx,
{"Output Port Idx", "swils.ldr.out_portidx",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ldrec_nbr_pidx,
{"Neighbor Port Idx", "swils.ldr.nbr_portidx",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ldrec_link_type,
{"Link Type", "swils.ldr.linktype",
FT_UINT8, BASE_HEX, VALS(fc_swils_link_type_val), 0x0,
NULL, HFILL}},
{ &hf_swils_ldrec_link_cost,
{"Link Cost", "swils.ldr.linkcost",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_rscn_evtype,
{"Event Type", "swils.rscn.evtype",
FT_UINT8, BASE_DEC, VALS(fc_swils_rscn_portstate_val), 0xF0,
NULL, HFILL}},
{ &hf_swils_rscn_addrfmt,
{"Address Format", "swils.rscn.addrfmt",
FT_UINT8, BASE_DEC, VALS(fc_swils_rscn_addrfmt_val), 0x0F,
NULL, HFILL}},
{ &hf_swils_rscn_affectedport,
{"Affected Port ID", "swils.rscn.affectedport",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_rscn_detectfn,
{"Detection Function", "swils.rscn.detectfn",
FT_UINT32, BASE_HEX, VALS(fc_swils_rscn_detectfn_val), 0x0,
NULL, HFILL}},
{ &hf_swils_rscn_portstate,
{"Port State", "swils.rscn.portstate",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_rscn_portid,
{"Port Id", "swils.rscn.portid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_rscn_pwwn,
{"Port WWN", "swils.rscn.pwwn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_rscn_nwwn,
{"Node WWN", "swils.rscn.nwwn",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_esc_swvendorid,
{"Switch Vendor ID", "swils.esc.swvendor",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_esc_pdesc_vendorid,
{"Vendor ID", "swils.esc.vendorid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_esc_protocolid,
{"Protocol ID", "swils.esc.protocol",
FT_UINT16, BASE_HEX, VALS(fc_swils_esc_protocol_val), 0x0,
NULL, HFILL}},
{ &hf_swils_zone_activezonenm,
{"Active Zoneset Name", "swils.mr.activezonesetname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_zone_objname,
{"Zone Object Name", "swils.zone.zoneobjname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_zone_objtype,
{"Zone Object Type", "swils.zone.zoneobjtype",
FT_UINT8, BASE_HEX, VALS(fc_swils_zoneobj_type_val), 0x0,
NULL, HFILL}},
{ &hf_swils_zone_mbrtype,
{"Zone Member Type", "swils.zone.mbrtype",
FT_UINT8, BASE_HEX, VALS(fc_swils_zonembr_type_val), 0x0,
NULL, HFILL}},
{ &hf_swils_zone_protocol,
{"Zone Protocol", "swils.zone.protocol",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_zone_mbrid,
{"Member Identifier", "swils.zone.mbrid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_zone_status,
{"Zone Command Status", "swils.zone.status",
FT_UINT8, BASE_HEX, VALS(fc_swils_mr_rsp_val), 0x0,
"Applies to MR, ACA, RCA, SFC, UFC", HFILL}},
{ &hf_swils_zone_reason,
{"Zone Command Reason Code", "swils.zone.reason",
FT_UINT8, BASE_HEX, VALS(fc_swils_mr_reason_val), 0x0,
"Applies to MR, ACA, RCA, SFC, UFC", HFILL}},
{ &hf_swils_aca_domainid,
{"Known Domain ID", "swils.aca.domainid",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_sfc_opcode,
{"Operation Request", "swils.sfc.opcode",
FT_UINT8, BASE_HEX, VALS(fc_swils_sfc_op_val), 0x0,
NULL, HFILL}},
{ &hf_swils_sfc_zonenm,
{"Zone Set Name", "swils.sfc.zonename",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_rjt,
{"Reason Code", "swils.rjt.reason",
FT_UINT8, BASE_HEX, VALS(fc_swils_rjt_val), 0x0,
NULL, HFILL}},
{ &hf_swils_rjtdet,
{"Reason Code Explanantion", "swils.rjt.reasonexpl",
FT_UINT8, BASE_HEX, VALS(fc_swils_deterr_val), 0x0,
NULL, HFILL}},
{ &hf_swils_rjtvendor,
{"Vendor Unique Error Code", "swils.rjt.vendor",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_zone_mbrid_lun,
{"LUN", "swils.zone.lun",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_rev,
{"Revision", "swils.ess.revision",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_len,
{"Payload Length", "swils.ess.leb",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_numobj,
{"Number of Capability Objects", "swils.ess.numobj",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_interconnect_list_len,
{"List Length", "swils.ess.listlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_vendorname,
{"Vendor Name", "swils.ess.vendorname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_modelname,
{"Model Name", "swils.ess.modelname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_relcode,
{"Release Code", "swils.ess.relcode",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_vendorspecific,
{"Vendor Specific", "swils.ess.vendorspecific",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_cap_type,
{"Type", "swils.ess.capability.type",
FT_UINT8, BASE_DEC, VALS(fc_ct_gstype_vals), 0x0,
NULL, HFILL}},
{ &hf_swils_ess_cap_subtype,
{"Subtype", "swils.ess.capability.subtype",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_cap_numentries,
{"Number of Entries", "swils.ess.capability.numentries",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_cap_svc,
{"Service Name", "swils.ess.capability.service",
FT_UINT8, BASE_DEC, VALS(fc_ct_gsserver_vals), 0x0,
NULL, HFILL}},
{ &hf_swils_ess_dns_obj0h,
{"Name Server Entry Object 00h Support", "swils.ess.capability.dns.obj0h",
FT_BOOLEAN, 8, NULL, 0x1,
NULL, HFILL}},
{ &hf_swils_ess_dns_obj1h,
{"Name Server Entry Object 01h Support", "swils.ess.capability.dns.obj1h",
FT_BOOLEAN, 8, NULL, 0x2,
NULL, HFILL}},
{ &hf_swils_ess_dns_obj2h,
{"Name Server Entry Object 02h Support", "swils.ess.capability.dns.obj2h",
FT_BOOLEAN, 8, NULL, 0x4,
NULL, HFILL}},
{ &hf_swils_ess_dns_obj3h,
{"Name Server Entry Object 03h Support", "swils.ess.capability.dns.obj3h",
FT_BOOLEAN, 8, NULL, 0x8,
NULL, HFILL}},
{ &hf_swils_ess_dns_zlacc,
{"GE_PT Zero Length Accepted", "swils.ess.capability.dns.zlacc",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL}},
{ &hf_swils_ess_dns_vendor,
{"Vendor Specific Flags", "swils.ess.capability.dns.vendor",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_fctlr_rscn,
{"SW_RSCN Supported", "swils.ess.capability.fctlr.rscn",
FT_BOOLEAN, 8, NULL, 0x1,
NULL, HFILL}},
{ &hf_swils_ess_fctlr_vendor,
{"Vendor Specific Flags", "swils.ess.capability.fctlr.vendor",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_fcs_basic,
{"Basic Configuration Services", "swils.ess.capability.fcs.basic",
FT_BOOLEAN, 8, NULL, 0x1,
NULL, HFILL}},
{ &hf_swils_ess_fcs_platform,
{"Platform Configuration Services", "swils.ess.capability.fcs.platform",
FT_BOOLEAN, 8, NULL, 0x2,
NULL, HFILL}},
{ &hf_swils_ess_fcs_topology,
{"Topology Discovery Services", "swils.ess.capability.fcs.topology",
FT_BOOLEAN, 8, NULL, 0x4,
NULL, HFILL}},
{ &hf_swils_ess_fcs_enhanced,
{"Enhanced Configuration Services", "swils.ess.capability.fcs.enhanced",
FT_BOOLEAN, 8, NULL, 0x8,
NULL, HFILL}},
{ &hf_swils_ess_fzs_enh_supp,
{"Enhanced Zoning Supported", "swils.ess.capability.fzs.ezonesupp",
FT_BOOLEAN, 8, NULL, 0x1,
NULL, HFILL}},
{ &hf_swils_ess_fzs_enh_ena,
{"Enhanced Zoning Enabled", "swils.ess.capability.fzs.ezoneena",
FT_BOOLEAN, 8, NULL, 0x2,
NULL, HFILL}},
{ &hf_swils_ess_fzs_mr,
{"Merge Control Setting", "swils.ess.capability.fzs.mr",
FT_BOOLEAN, 8, NULL, 0x4,
NULL, HFILL}},
{ &hf_swils_ess_fzs_defzone,
{"Default Zone Setting", "swils.ess.capability.fzs.defzone",
FT_BOOLEAN, 8, NULL, 0x8,
NULL, HFILL}},
{ &hf_swils_ess_fzs_zsdb_supp,
{"Zoneset Database Supported", "swils.ess.capability.fzs.zsdbsupp",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL}},
{ &hf_swils_ess_fzs_zsdb_ena,
{"Zoneset Database Enabled", "swils.ess.capability.fzs.zsdbena",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL}},
{ &hf_swils_ess_fzs_adc_supp,
{"Active Direct Command Supported", "swils.ess.capability.fzs.adcsupp",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL}},
{ &hf_swils_ess_fzs_hardzone,
{"Hard Zoning Supported", "swils.ess.capability.fzs.hardzone",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL}},
{ &hf_swils_ess_cap_len,
{"Length", "swils.ess.capability.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_cap_t10,
{"T10 Vendor ID", "swils.ess.capability.t10id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_ess_cap_vendorobj,
{"Vendor-Specific Info", "swils.ess.capability.vendorobj",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_mrra_rev,
{"Revision", "swils.mrra.revision",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_mrra_size,
{"Merge Request Size", "swils.mrra.size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_mrra_vendorid,
{"Vendor ID", "swils.mrra.vendorid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_mrra_vendorinfo,
{"Vendor-Specific Info", "swils.mrra.vendorinfo",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_mrra_reply,
{"MRRA Response", "swils.mrra.reply",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_mrra_reply_size,
{"Maximum Resources Available", "swils.mrra.replysize",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_swils_mrra_waittime,
{"Waiting Period (secs)", "swils.mrra.waittime",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_fcswils,
&ett_fcswils_swacc,
&ett_fcswils_swrjt,
&ett_fcswils_elp,
&ett_fcswils_efp,
&ett_fcswils_efplist,
&ett_fcswils_dia,
&ett_fcswils_rdi,
&ett_fcswils_fspfhdr,
&ett_fcswils_hlo,
&ett_fcswils_lsrec,
&ett_fcswils_lsrechdr,
&ett_fcswils_ldrec,
&ett_fcswils_lsu,
&ett_fcswils_lsa,
&ett_fcswils_bf,
&ett_fcswils_rcf,
&ett_fcswils_rscn,
&ett_fcswils_rscn_dev,
&ett_fcswils_drlir,
&ett_fcswils_mr,
&ett_fcswils_zoneobjlist,
&ett_fcswils_zoneobj,
&ett_fcswils_zonembr,
&ett_fcswils_aca,
&ett_fcswils_rca,
&ett_fcswils_sfc,
&ett_fcswils_ufc,
&ett_fcswils_esc,
&ett_fcswils_esc_pdesc,
&ett_fcswils_ieinfo,
&ett_fcswils_capinfo
};
proto_fcswils = proto_register_protocol("Fibre Channel SW_ILS", "FC-SWILS", "swils");
proto_register_field_array(proto_fcswils, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(&fcswils_init_protocol);
}
void
proto_reg_handoff_fcswils(void)
{
dissector_handle_t swils_handle;
swils_handle = create_dissector_handle(dissect_fcswils, proto_fcswils);
dissector_add_uint("fc.ftype", FC_FTYPE_SWILS, swils_handle);
data_handle = find_dissector("data");
fcsp_handle = find_dissector("fcsp");
}
