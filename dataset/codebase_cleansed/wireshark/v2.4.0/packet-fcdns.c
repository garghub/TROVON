static gint
fcdns_equal(gconstpointer v, gconstpointer w)
{
const fcdns_conv_key_t *v1 = (const fcdns_conv_key_t *)v;
const fcdns_conv_key_t *v2 = (const fcdns_conv_key_t *)w;
return (v1->conv_idx == v2->conv_idx);
}
static guint
fcdns_hash (gconstpointer v)
{
const fcdns_conv_key_t *key = (const fcdns_conv_key_t *)v;
guint val;
val = key->conv_idx;
return val;
}
static void
dissect_cos_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, const header_field_info *hfinfo)
{
static const int * flags[] = {
&hfi_fcdns_cos_f.id,
&hfi_fcdns_cos_1.id,
&hfi_fcdns_cos_2.id,
&hfi_fcdns_cos_3.id,
&hfi_fcdns_cos_4.id,
&hfi_fcdns_cos_6.id,
NULL
};
proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hfinfo->id,
ett_cos_flags, flags, ENC_BIG_ENDIAN, BMT_NO_FALSE|BMT_NO_TFS);
}
static void
dissect_fc4features_and_type (proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
guint8 type;
static const int * flags[] = {
&hfi_fcdns_fc4features_i.id,
&hfi_fcdns_fc4features_t.id,
NULL
};
type = tvb_get_guint8(tvb, offset+1);
if(type==FC_TYPE_SCSI){
proto_tree_add_bitmask_with_flags(parent_tree, tvb, offset, hfi_fcdns_fc4features.id,
ett_fc4features, flags, ENC_NA, BMT_NO_FALSE|BMT_NO_TFS);
} else {
proto_tree_add_item(parent_tree, &hfi_fcdns_fc4features, tvb, offset, 1, ENC_NA);
}
proto_tree_add_item (parent_tree, &hfi_fcdns_req_fc4type, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
static void
dissect_fc4features (proto_tree *parent_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hfi_fcdns_fc4features_i.id,
&hfi_fcdns_fc4features_t.id,
NULL
};
proto_tree_add_bitmask(parent_tree, tvb, offset, hfi_fcdns_fc4features_i.id,
ett_fc4features, flags, ENC_NA);
}
static void
dissect_fc4type (proto_tree *parent_tree, tvbuff_t *tvb, int offset, header_field_info *hfinfo)
{
proto_item *item;
proto_tree *tree;
guint32 flags;
item=proto_tree_add_item(parent_tree, hfinfo, tvb, offset,
32, ENC_NA);
tree=proto_item_add_subtree(item, ett_fc4flags);
flags = tvb_get_ntohl (tvb, offset);
proto_tree_add_boolean(tree, &hfi_fcdns_fc4type_fcp, tvb, offset, 4, flags);
if (flags&0x0100){
proto_item_append_text(item, " FCP");
}
flags&=(~( 0x0100 ));
proto_tree_add_boolean(tree, &hfi_fcdns_fc4type_ip, tvb, offset, 4, flags);
if (flags&0x0020){
proto_item_append_text(item, " IP");
}
flags&=(~( 0x0020 ));
proto_tree_add_boolean(tree, &hfi_fcdns_fc4type_llcsnap, tvb, offset, 4, flags);
if (flags&0x0010){
proto_item_append_text(item, " LLC/SNAP");
}
flags = tvb_get_ntohl (tvb, offset+4);
proto_tree_add_boolean(tree, &hfi_fcdns_fc4type_swils, tvb, offset+4, 4, flags);
if (flags&0x0010){
proto_item_append_text(item, " SW_ILS");
}
flags&=(~( 0x0010 ));
proto_tree_add_boolean(tree, &hfi_fcdns_fc4type_snmp, tvb, offset+4, 4, flags);
if (flags&0x0004){
proto_item_append_text(item, " SNMP");
}
flags&=(~( 0x0004 ));
proto_tree_add_boolean(tree, &hfi_fcdns_fc4type_gs3, tvb, offset+4, 4, flags);
if (flags&0x0001){
proto_item_append_text(item, " GS3");
}
flags = tvb_get_ntohl (tvb, offset+8);
proto_tree_add_boolean(tree, &hfi_fcdns_fc4type_vi, tvb, offset+8, 4, flags);
if (flags&0x0001){
proto_item_append_text(item, " VI");
}
}
static void
dissect_fcdns_req_portid (tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item (tree, &hfi_fcdns_req_portid, tvb, offset, 3, ENC_NA);
}
static void
dissect_fcdns_ganxt (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 len;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
}
else {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_ptype, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid, tvb,
offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_pname, tvb,
offset+4, 8, ENC_NA);
len = tvb_get_guint8 (tvb, offset+12);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_spnamelen, tvb,
offset+12, 1, ENC_BIG_ENDIAN);
if (!tvb_offset_exists (tvb, 29+len))
return;
if (len) {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_spname, tvb,
offset+13, len, ENC_ASCII|ENC_NA);
}
if (tvb_offset_exists (tvb, 292)) {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_nname, tvb,
offset+268, 8, ENC_NA);
}
if (tvb_offset_exists (tvb, 548)) {
len = tvb_get_guint8 (tvb, offset+276);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_snamelen, tvb,
offset+276, 1, ENC_BIG_ENDIAN);
if (len) {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_sname, tvb,
offset+277, len, ENC_ASCII|ENC_NA);
}
}
if (tvb_offset_exists (tvb, 556)) {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_ipa, tvb,
offset+532, 8, ENC_NA);
}
if (tvb_offset_exists (tvb, 572)) {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_ipnode, tvb,
offset+540, 16, ENC_NA);
}
if (tvb_offset_exists (tvb, 576)) {
dissect_cos_flags(req_tree, tvb, offset+556, &hfi_fcdns_reply_cos);
}
if (tvb_offset_exists (tvb, 608)) {
dissect_fc4type(req_tree, tvb, offset+560, &hfi_fcdns_rply_gft);
}
if (tvb_offset_exists (tvb, 624)) {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_ipport, tvb,
offset+592, 16, ENC_NA);
}
if (tvb_offset_exists (tvb, 632)) {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_fpname, tvb,
offset+608, 8, ENC_NA);
}
if (tvb_offset_exists (tvb, 635)) {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_hrdaddr, tvb,
offset+617, 3, ENC_NA);
}
}
}
}
static void
dissect_fcdns_gpnid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
}
else {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_pname, tvb, offset,
8, ENC_NA);
}
}
}
static void
dissect_fcdns_gnnid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
}
else {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_nname, tvb,
offset, 8, ENC_NA);
}
}
}
static void
dissect_fcdns_gcsid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset);
}
else {
dissect_cos_flags(req_tree, tvb, offset, &hfi_fcdns_reply_cos);
}
}
}
static void
dissect_fcdns_gftid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
}
else {
dissect_fc4type(req_tree, tvb, offset, &hfi_fcdns_rply_gft);
}
}
}
static void
dissect_fcdns_gspnid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 len;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
}
else {
len = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_spnamelen,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_spname, tvb,
offset+1, len, ENC_ASCII|ENC_NA);
}
}
}
static void
dissect_fcdns_gptid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
}
else {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_ptype, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_fcdns_gfpnid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
}
else {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_fpname, tvb,
offset, 8, ENC_NA);
}
}
}
static void
dissect_fcdns_gfdid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
int tot_len, desclen;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
dissect_fc4type(req_tree, tvb, offset+4, &hfi_fcdns_fc4type);
}
else {
tot_len = tvb_reported_length_remaining (tvb, offset);
while (tot_len > 0) {
desclen = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_fc4desc, tvb,
offset, desclen, ENC_NA);
tot_len -= 255;
offset += 256;
}
}
}
}
static void
dissect_fcdns_gffid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
dissect_fcdns_req_portid (tvb, req_tree, offset+1);
}
else {
dissect_fc4features(req_tree, tvb, offset);
}
}
}
static void
dissect_fcdns_gidpn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_pname, tvb,
offset, 8, ENC_NA);
}
else {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid, tvb,
offset+1, 3, ENC_NA);
}
}
}
static void
dissect_fcdns_gipppn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_pname, tvb,
offset, 8, ENC_NA);
}
else {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_ipport, tvb, offset,
16, ENC_NA);
}
}
}
static void
dissect_fcdns_gidnn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 islast;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_nname, tvb,
offset, 8, ENC_NA);
}
else {
do {
islast = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid,
tvb, offset+1, 3, ENC_NA);
offset += 4;
} while (!(islast & 0x80));
}
}
}
static void
dissect_fcdns_gipnn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_nname, tvb,
offset, 8, ENC_NA);
}
else {
proto_tree_add_item (req_tree, &hfi_fcdns_rply_ipnode, tvb, offset,
16, ENC_NA);
}
}
}
static void
dissect_fcdns_gpnnn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 islast;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_nname, tvb,
offset, 8, ENC_NA);
}
else {
do {
islast = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid,
tvb, offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_pname,
tvb, offset+8, 8, ENC_NA);
offset += 16;
} while (!(islast & 0x80));
}
}
}
static void
dissect_fcdns_gsnnnn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 len;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_nname, tvb,
offset, 8, ENC_NA);
}
else {
len = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_snamelen, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_sname, tvb,
offset+1, len, ENC_ASCII|ENC_NA);
}
}
}
static void
dissect_fcdns_gidft (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 islast;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_domainscope,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_areascope,
tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_fc4type,
tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
else {
do {
islast = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid,
tvb, offset+1, 3, ENC_NA);
offset += 4;
} while (!(islast & 0x80));
}
}
}
static void
dissect_fcdns_gpnft (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 islast;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_domainscope,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_areascope,
tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_fc4type,
tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
else {
do {
islast = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid,
tvb, offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_pname,
tvb, offset+4, 8, ENC_NA);
offset += 16;
} while (!(islast & 0x80));
}
}
}
static void
dissect_fcdns_gnnft (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 islast;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_domainscope,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_areascope,
tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_fc4type,
tvb, offset+3, 1, ENC_BIG_ENDIAN);
}
else {
do {
islast = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid,
tvb, offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_nname,
tvb, offset+4, 8, ENC_NA);
offset += 16;
} while (!(islast & 0x80));
}
}
}
static void
dissect_fcdns_gidpt (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 islast = 0;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_ptype,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_domainscope,
tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_areascope,
tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
else {
do {
islast = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid,
tvb, offset+1, 3, ENC_NA);
offset += 4;
} while (!(islast & 0x80));
}
}
}
static void
dissect_fcdns_gidipp (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 islast;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_ip, tvb, offset,
16, ENC_NA);
}
else {
do {
islast = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid,
tvb, offset+1, 3, ENC_NA);
offset += 4;
} while (!(islast & 0x80));
}
}
}
static void
dissect_fcdns_gidff (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 islast;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_domainscope, tvb,
offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_areascope, tvb,
offset+2, 1, ENC_BIG_ENDIAN);
dissect_fc4features_and_type(req_tree, tvb, offset+6);
}
else {
do {
islast = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (req_tree, &hfi_fcdns_rply_portid,
tvb, offset+1, 3, ENC_NA);
offset += 4;
} while (!(islast & 0x80));
}
}
}
static void
dissect_fcdns_rpnid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid,
tvb, offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_req_pname, tvb,
offset+4, 8, ENC_NA);
}
}
}
static void
dissect_fcdns_rnnid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree) {
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid,
tvb, offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_req_nname, tvb,
offset+4, 8, ENC_NA);
}
}
}
static void
dissect_fcdns_rcsid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (req_tree && isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb,
offset+1, 3, ENC_NA);
dissect_cos_flags(req_tree, tvb, offset+4, &hfi_fcdns_req_cos);
}
}
static void
dissect_fcdns_rptid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb,
offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_req_ptype, tvb,
offset+4, 1, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcdns_rftid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb,
offset+1, 3, ENC_NA);
dissect_fc4type(req_tree, tvb, offset+4, &hfi_fcdns_req_fc4types);
}
}
static void
dissect_fcdns_rspnid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 len;
if (req_tree && isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb,
offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_req_spnamelen, tvb,
offset+4, 1, ENC_BIG_ENDIAN);
len = tvb_get_guint8 (tvb, offset+4);
proto_tree_add_item (req_tree, &hfi_fcdns_req_spname, tvb, offset+5,
len, ENC_ASCII|ENC_NA);
}
}
static void
dissect_fcdns_rippid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb,
offset+1, 3, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_req_ip, tvb,
offset+4, 16, ENC_NA);
}
}
static void
dissect_fcdns_rfdid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
int len;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb,
offset+1, 3, ENC_NA);
dissect_fc4type(req_tree, tvb, offset+4, &hfi_fcdns_req_fc4types);
offset += 36;
len = tvb_reported_length_remaining (tvb, offset);
while (len > 0) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_fdesclen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_fdesc, tvb, offset+1,
len, ENC_ASCII|ENC_NA);
offset += 256;
len -= 256;
}
}
}
static void
dissect_fcdns_rffid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb, offset+1, 3, ENC_NA);
dissect_fc4features_and_type(req_tree, tvb, offset+6);
}
}
static void
dissect_fcdns_ripnn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_nname, tvb, offset, 8, ENC_NA);
proto_tree_add_item (req_tree, &hfi_fcdns_req_ip, tvb, offset+8, 16, ENC_NA);
}
}
static void
dissect_fcdns_rsnnnn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
guint8 len;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_nname, tvb, offset, 8, ENC_NA);
len = tvb_get_guint8 (tvb, offset+8);
proto_tree_add_item (req_tree, &hfi_fcdns_req_snamelen, tvb, offset+8,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_req_sname, tvb, offset+9,
len, ENC_ASCII|ENC_NA);
}
}
static void
dissect_fcdns_daid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb, offset+1, 3, ENC_NA);
}
}
static guint8 *
zonenm_to_str (tvbuff_t *tvb, gint offset)
{
int len = tvb_get_guint8 (tvb, offset);
return tvb_get_string_enc(wmem_packet_scope(), tvb, offset+4, len, ENC_ASCII);
}
static void
dissect_fcdns_zone_mbr (tvbuff_t *tvb, packet_info* pinfo, proto_tree *zmbr_tree, int offset)
{
guint8 mbrtype;
int idlen;
proto_item* ti;
mbrtype = tvb_get_guint8 (tvb, offset);
ti = proto_tree_add_uint (zmbr_tree, &hfi_fcdns_zone_mbrtype, tvb,
offset, 1, mbrtype);
proto_tree_add_item(zmbr_tree, &hfi_fcdns_zone_flags, tvb, offset+2, 1, ENC_NA);
idlen = tvb_get_guint8 (tvb, offset+3);
proto_tree_add_item(zmbr_tree, &hfi_fcdns_id_length, tvb, offset+3, 1, ENC_NA);
switch (mbrtype) {
case FC_SWILS_ZONEMBR_WWN:
proto_tree_add_item (zmbr_tree, &hfi_fcdns_zone_mbrid_wwn, tvb,
offset+4, 8, ENC_NA);
break;
case FC_SWILS_ZONEMBR_DP:
proto_tree_add_item (zmbr_tree, &hfi_fcdns_zone_mbrid_uint, tvb,
offset+4, 4, ENC_BIG_ENDIAN);
break;
case FC_SWILS_ZONEMBR_FCID:
proto_tree_add_item (zmbr_tree, &hfi_fcdns_zone_mbrid_fc, tvb,
offset+4, 3, ENC_NA);
break;
case FC_SWILS_ZONEMBR_ALIAS:
proto_tree_add_string (zmbr_tree, &hfi_fcdns_zone_mbrid, tvb,
offset+4, idlen, zonenm_to_str (tvb, offset+4));
break;
default:
expert_add_info(pinfo, ti, &ei_fcdns_zone_mbrid);
}
}
static void
dissect_fcdns_swils_entries (tvbuff_t *tvb, proto_tree *tree, int offset)
{
int numrec, i, len;
guint8 objfmt;
if (tree) {
numrec = tvb_get_ntohl (tvb, offset);
proto_tree_add_uint(tree, &hfi_fcdns_num_entries, tvb, offset, 4, numrec);
offset += 4;
for (i = 0; i < numrec; i++) {
objfmt = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (tree, &hfi_fcdns_sw2_objfmt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, &hfi_fcdns_rply_ownerid, tvb, offset+1, 3, ENC_NA);
proto_tree_add_item (tree, &hfi_fcdns_rply_ptype, tvb, offset+4,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, &hfi_fcdns_rply_portid, tvb, offset+5, 3, ENC_NA);
proto_tree_add_item (tree, &hfi_fcdns_rply_pname, tvb, offset+8, 8, ENC_NA);
offset += 16;
if (!(objfmt & 0x1)) {
len = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (tree, &hfi_fcdns_rply_spnamelen, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, &hfi_fcdns_rply_spname, tvb,
offset+1, len, ENC_ASCII|ENC_NA);
offset += 256;
}
proto_tree_add_item (tree, &hfi_fcdns_rply_nname, tvb, offset, 8, ENC_NA);
offset += 8;
if (!(objfmt & 0x1)) {
len = tvb_get_guint8 (tvb, offset);
proto_tree_add_item (tree, &hfi_fcdns_rply_snamelen, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, &hfi_fcdns_rply_sname, tvb,
offset+1, len, ENC_ASCII|ENC_NA);
offset += 256;
}
proto_tree_add_item (tree, &hfi_fcdns_rply_ipa, tvb, offset, 8, ENC_NA);
proto_tree_add_item (tree, &hfi_fcdns_rply_ipnode, tvb, offset+8, 16,
ENC_NA);
dissect_cos_flags(tree, tvb, offset+24, &hfi_fcdns_reply_cos);
dissect_fc4type(tree, tvb, offset+28, &hfi_fcdns_rply_gft);
proto_tree_add_item (tree, &hfi_fcdns_rply_ipport, tvb, offset+60,
16, ENC_NA);
proto_tree_add_item (tree, &hfi_fcdns_rply_fpname, tvb, offset+76,
8, ENC_NA);
proto_tree_add_item (tree, &hfi_fcdns_rply_hrdaddr, tvb, offset+85,
3, ENC_NA);
offset += 88;
if (objfmt & 0x2) {
dissect_fc4features(tree, tvb, offset);
if (tvb_get_guint8 (tvb, offset+129)) {
proto_tree_add_item (tree, &hfi_fcdns_rply_fc4type, tvb,
offset+128, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, &hfi_fcdns_num_fc4desc, tvb,
offset+129, 1, ENC_BIG_ENDIAN);
len = tvb_get_guint8 (tvb, offset+132);
proto_tree_add_item (tree, &hfi_fcdns_rply_fc4desclen, tvb,
offset+132, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, &hfi_fcdns_rply_fc4desc, tvb,
offset+133, len, ENC_NA);
}
else {
proto_tree_add_item (tree, &hfi_fcdns_num_fc4desc, tvb,
offset+129, 1, ENC_BIG_ENDIAN);
}
offset += 388;
}
}
}
}
static void
dissect_fcdns_geid (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_portid, tvb, offset+1, 3, ENC_NA);
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_gepn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item(req_tree, &hfi_fcdns_req_pname, tvb, offset, 8, ENC_NA);
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_genn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_nname, tvb, offset, 8, ENC_NA);
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_geip (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
if (req_tree) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_ip, tvb, offset, 16, ENC_NA);
}
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_geft (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
if (req_tree) {
dissect_fc4type(req_tree, tvb, offset, &hfi_fcdns_fc4type);
}
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_gept (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
if (req_tree) {
proto_tree_add_item (req_tree, &hfi_fcdns_req_ptype, tvb, offset+3,
1, ENC_BIG_ENDIAN);
}
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_gezm (tvbuff_t *tvb, packet_info* pinfo, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
dissect_fcdns_zone_mbr (tvb, pinfo, req_tree, offset);
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_gezn (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
int str_len;
if (isreq) {
if (req_tree) {
str_len = tvb_get_guint8 (tvb, offset);
proto_tree_add_uint(req_tree, &hfi_fcdns_zonelen, tvb, offset, 1, str_len);
proto_tree_add_item (req_tree, &hfi_fcdns_zonenm, tvb, offset+3,
str_len, ENC_ASCII|ENC_NA);
}
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_geipp (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
if (req_tree) {
proto_tree_add_item (req_tree, &hfi_fcdns_portip, tvb, offset, 4, ENC_BIG_ENDIAN);
}
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_geff (tvbuff_t *tvb, proto_tree *req_tree, gboolean isreq)
{
int offset = 16;
if (isreq) {
if (req_tree) {
dissect_fc4features(req_tree, tvb, offset);
}
}
else {
dissect_fcdns_swils_entries (tvb, req_tree, offset);
}
}
static void
dissect_fcdns_rjt (tvbuff_t *tvb, proto_tree *req_tree)
{
int offset = 0;
if (req_tree) {
proto_tree_add_item (req_tree, &hfi_fcdns_reason, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_rjtdetail, tvb, offset+14, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item (req_tree, &hfi_fcdns_vendor, tvb, offset+15, 1, ENC_BIG_ENDIAN);
}
}
static int
dissect_fcdns (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ti = NULL;
proto_tree *fcdns_tree = NULL;
int offset = 0;
int opcode,
failed_opcode = 0;
int isreq = 1;
fc_ct_preamble cthdr;
conversation_t *conversation;
fcdns_conv_data_t *cdata;
fcdns_conv_key_t ckey, *req_key;
fc_hdr *fchdr;
if (data == NULL)
return 0;
fchdr = (fc_hdr *)data;
tvb_memcpy (tvb, (guint8 *)&cthdr, offset, FCCT_PRMBL_SIZE);
cthdr.revision = tvb_get_guint8 (tvb, offset);
cthdr.in_id = tvb_get_ntoh24 (tvb, offset+1);
cthdr.opcode = g_ntohs (cthdr.opcode);
opcode = cthdr.opcode;
cthdr.maxres_size = g_ntohs (cthdr.maxres_size);
if (cthdr.gstype == FCCT_GSTYPE_DIRSVC)
col_set_str (pinfo->cinfo, COL_PROTOCOL, "dNS");
else
col_set_str (pinfo->cinfo, COL_PROTOCOL, "Unzoned NS");
if (tree) {
if (cthdr.gstype == FCCT_GSTYPE_DIRSVC) {
ti = proto_tree_add_protocol_format (tree, hfi_fcdns->id, tvb, 0,
-1,
"dNS");
fcdns_tree = proto_item_add_subtree (ti, ett_fcdns);
}
else {
ti = proto_tree_add_protocol_format (tree, hfi_fcdns->id, tvb, 0,
-1,
"Unzoned NS");
fcdns_tree = proto_item_add_subtree (ti, ett_fcdns);
}
}
if ((opcode != FCCT_MSG_ACC) && (opcode != FCCT_MSG_RJT)) {
conversation = find_conversation (pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, fchdr->oxid,
fchdr->rxid, NO_PORT2);
if (!conversation) {
conversation = conversation_new (pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, fchdr->oxid,
fchdr->rxid, NO_PORT2);
}
ckey.conv_idx = conversation->conv_index;
cdata = (fcdns_conv_data_t *)wmem_map_lookup (fcdns_req_hash,
&ckey);
if (cdata) {
cdata->opcode = opcode;
}
else {
req_key = wmem_new(wmem_file_scope(), fcdns_conv_key_t);
req_key->conv_idx = conversation->conv_index;
cdata = wmem_new(wmem_file_scope(), fcdns_conv_data_t);
cdata->opcode = opcode;
wmem_map_insert (fcdns_req_hash, req_key, cdata);
}
col_add_str (pinfo->cinfo, COL_INFO, val_to_str (opcode, fc_dns_opcode_val,
"0x%x"));
}
else {
conversation = find_conversation (pinfo->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, fchdr->oxid,
fchdr->rxid, NO_PORT2);
isreq = 0;
if (!conversation) {
if (opcode == FCCT_MSG_ACC) {
col_add_str (pinfo->cinfo, COL_INFO,
val_to_str (opcode, fc_dns_opcode_val,
"0x%x"));
proto_tree_add_expert(fcdns_tree, pinfo, &ei_fcdns_no_record_of_exchange, tvb, 0, -1);
return 0;
}
}
else {
ckey.conv_idx = conversation->conv_index;
cdata = (fcdns_conv_data_t *)wmem_map_lookup (fcdns_req_hash, &ckey);
if (cdata != NULL) {
if (opcode == FCCT_MSG_ACC) {
opcode = cdata->opcode;
}
else
failed_opcode = cdata->opcode;
}
if (opcode != FCCT_MSG_RJT) {
col_add_fstr (pinfo->cinfo, COL_INFO, "ACC (%s)",
val_to_str (opcode, fc_dns_opcode_val,
"0x%x"));
}
else {
col_add_fstr (pinfo->cinfo, COL_INFO, "RJT (%s)",
val_to_str (failed_opcode,
fc_dns_opcode_val,
"0x%x"));
}
if (tree) {
if ((cdata == NULL) && (opcode != FCCT_MSG_RJT)) {
proto_tree_add_expert(fcdns_tree, pinfo, &ei_fcdns_no_record_of_exchange, tvb, 0, -1);
return 0;
}
}
}
}
if (tree) {
proto_tree_add_item (fcdns_tree, &hfi_fcdns_opcode, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (fcdns_tree, &hfi_fcdns_maxres_size, tvb, offset+10,
2, ENC_BIG_ENDIAN);
}
switch (opcode) {
case FCCT_MSG_RJT:
dissect_fcdns_rjt (tvb, fcdns_tree);
break;
case FCDNS_GA_NXT:
dissect_fcdns_ganxt (tvb, fcdns_tree, isreq);
break;
case FCDNS_GPN_ID:
dissect_fcdns_gpnid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GNN_ID:
dissect_fcdns_gnnid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GCS_ID:
dissect_fcdns_gcsid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GFT_ID:
dissect_fcdns_gftid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GSPN_ID:
dissect_fcdns_gspnid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GPT_ID:
dissect_fcdns_gptid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GFPN_ID:
dissect_fcdns_gfpnid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GFD_ID:
dissect_fcdns_gfdid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GFF_ID:
dissect_fcdns_gffid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GID_PN:
dissect_fcdns_gidpn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GIPP_PN:
dissect_fcdns_gipppn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GID_NN:
dissect_fcdns_gidnn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GPN_NN:
dissect_fcdns_gpnnn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GIP_NN:
dissect_fcdns_gipnn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GSNN_NN:
dissect_fcdns_gsnnnn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GID_FT:
dissect_fcdns_gidft (tvb, fcdns_tree, isreq);
break;
case FCDNS_GPN_FT:
dissect_fcdns_gpnft (tvb, fcdns_tree, isreq);
break;
case FCDNS_GNN_FT:
dissect_fcdns_gnnft (tvb, fcdns_tree, isreq);
break;
case FCDNS_GID_PT:
dissect_fcdns_gidpt (tvb, fcdns_tree, isreq);
break;
case FCDNS_GID_IPP:
dissect_fcdns_gidipp (tvb, fcdns_tree, isreq);
break;
case FCDNS_GID_FF:
dissect_fcdns_gidff (tvb, fcdns_tree, isreq);
break;
case FCDNS_RPN_ID:
dissect_fcdns_rpnid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RNN_ID:
dissect_fcdns_rnnid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RCS_ID:
dissect_fcdns_rcsid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RPT_ID:
dissect_fcdns_rptid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RFT_ID:
dissect_fcdns_rftid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RSPN_ID:
dissect_fcdns_rspnid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RIPP_ID:
dissect_fcdns_rippid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RFD_ID:
dissect_fcdns_rfdid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RFF_ID:
dissect_fcdns_rffid (tvb, fcdns_tree, isreq);
break;
case FCDNS_RIP_NN:
dissect_fcdns_ripnn (tvb, fcdns_tree, isreq);
break;
case FCDNS_RSNN_NN:
dissect_fcdns_rsnnnn (tvb, fcdns_tree, isreq);
break;
case FCDNS_DA_ID:
dissect_fcdns_daid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_ID:
dissect_fcdns_geid (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_PN:
dissect_fcdns_gepn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_NN:
dissect_fcdns_genn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_IP:
dissect_fcdns_geip (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_FT:
dissect_fcdns_geft (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_PT:
dissect_fcdns_gept (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_ZM:
dissect_fcdns_gezm (tvb, pinfo, fcdns_tree, isreq);
break;
case FCDNS_GE_ZN:
dissect_fcdns_gezn (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_IPP:
dissect_fcdns_geipp (tvb, fcdns_tree, isreq);
break;
case FCDNS_GE_FF:
dissect_fcdns_geff (tvb, fcdns_tree, isreq);
break;
default:
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_fcdns (void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_fcdns_opcode,
&hfi_fcdns_req_portid,
&hfi_fcdns_rply_pname,
&hfi_fcdns_rply_nname,
&hfi_fcdns_rply_snamelen,
&hfi_fcdns_rply_sname,
&hfi_fcdns_rply_ptype,
&hfi_fcdns_rply_fpname,
&hfi_fcdns_req_pname,
&hfi_fcdns_rply_portid,
&hfi_fcdns_req_nname,
&hfi_fcdns_req_domainscope,
&hfi_fcdns_req_areascope,
&hfi_fcdns_req_fc4type,
&hfi_fcdns_req_ptype,
&hfi_fcdns_req_ip,
&hfi_fcdns_rply_fc4type,
&hfi_fcdns_req_snamelen,
&hfi_fcdns_req_sname,
&hfi_fcdns_rply_spnamelen,
&hfi_fcdns_rply_spname,
&hfi_fcdns_rply_ipa,
&hfi_fcdns_rply_ipnode,
&hfi_fcdns_rply_ipport,
&hfi_fcdns_rply_fc4desclen,
&hfi_fcdns_rply_fc4desc,
&hfi_fcdns_rply_hrdaddr,
&hfi_fcdns_req_fdesclen,
&hfi_fcdns_req_fdesc,
&hfi_fcdns_req_spnamelen,
&hfi_fcdns_req_spname,
&hfi_fcdns_reason,
&hfi_fcdns_rjtdetail,
&hfi_fcdns_vendor,
&hfi_fcdns_zone_mbrtype,
&hfi_fcdns_zone_mbrid,
&hfi_fcdns_zone_mbrid_wwn,
&hfi_fcdns_zone_mbrid_uint,
&hfi_fcdns_zone_mbrid_fc,
&hfi_fcdns_zonenm,
&hfi_fcdns_portip,
&hfi_fcdns_sw2_objfmt,
&hfi_fcdns_num_fc4desc,
&hfi_fcdns_rply_ownerid,
&hfi_fcdns_maxres_size,
&hfi_fcdns_reply_cos,
&hfi_fcdns_req_cos,
&hfi_fcdns_cos_f,
&hfi_fcdns_cos_1,
&hfi_fcdns_cos_2,
&hfi_fcdns_cos_3,
&hfi_fcdns_cos_4,
&hfi_fcdns_cos_6,
&hfi_fcdns_fc4type_llcsnap,
&hfi_fcdns_fc4type_ip,
&hfi_fcdns_fc4type_fcp,
&hfi_fcdns_fc4type_swils,
&hfi_fcdns_fc4type_snmp,
&hfi_fcdns_fc4type_gs3,
&hfi_fcdns_fc4type_vi,
&hfi_fcdns_rply_gft,
&hfi_fcdns_req_fc4types,
&hfi_fcdns_fc4type,
&hfi_fcdns_fc4features,
&hfi_fcdns_fc4features_i,
&hfi_fcdns_fc4features_t,
};
#endif
static gint *ett[] = {
&ett_fcdns,
&ett_cos_flags,
&ett_fc4flags,
&ett_fc4features,
};
static ei_register_info ei[] = {
{ &ei_fcdns_no_record_of_exchange, { "fcdns.no_record_of_exchange", PI_UNDECODED, PI_WARN, "No record of Exchg. Unable to decode MSG_ACC/RJT", EXPFILL }},
{ &ei_fcdns_zone_mbrid, { "fcdns.zone.mbrid.unknown_type", PI_PROTOCOL, PI_WARN, "Unknown member type format", EXPFILL }},
};
expert_module_t* expert_fcdns;
int proto_fcdns;
proto_fcdns = proto_register_protocol("Fibre Channel Name Server", "FC-dNS", "fcdns");
hfi_fcdns = proto_registrar_get_nth(proto_fcdns);
proto_register_fields(proto_fcdns, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
expert_fcdns = expert_register_protocol(proto_fcdns);
expert_register_field_array(expert_fcdns, ei, array_length(ei));
fcdns_req_hash = wmem_map_new_autoreset(wmem_epan_scope(), wmem_file_scope(), fcdns_hash, fcdns_equal);
dns_handle = create_dissector_handle (dissect_fcdns, proto_fcdns);
}
void
proto_reg_handoff_fcdns (void)
{
dissector_add_uint("fcct.server", FCCT_GSRVR_DNS, dns_handle);
dissector_add_uint("fcct.server", FCCT_GSRVR_UNS, dns_handle);
}
