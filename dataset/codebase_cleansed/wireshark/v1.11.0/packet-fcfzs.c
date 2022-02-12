static gint
fcfzs_equal(gconstpointer v, gconstpointer w)
{
const fcfzs_conv_key_t *v1 = (const fcfzs_conv_key_t *)v;
const fcfzs_conv_key_t *v2 = (const fcfzs_conv_key_t *)w;
return (v1->conv_idx == v2->conv_idx);
}
static guint
fcfzs_hash(gconstpointer v)
{
const fcfzs_conv_key_t *key = (const fcfzs_conv_key_t *)v;
guint val;
val = key->conv_idx;
return val;
}
static void
fcfzs_init_protocol(void)
{
if (fcfzs_req_hash)
g_hash_table_destroy(fcfzs_req_hash);
fcfzs_req_hash = g_hash_table_new(fcfzs_hash, fcfzs_equal);
}
static void
dissect_fcfzs_zoneset(tvbuff_t *tvb, proto_tree *tree, int offset)
{
int numzones, nummbrs, i, j, len;
if (tree) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonesetnmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonesetname, tvb, offset+4,
len, ENC_ASCII|ENC_NA);
offset += 4 + len + (4-(len % 4));
numzones = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_numzones, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < numzones; i++) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonenmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonename, tvb, offset+4,
len, ENC_ASCII|ENC_NA);
offset += 4 + len + (4-(len % 4));
nummbrs = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_nummbrentries, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
for (j = 0; j < nummbrs; j++) {
proto_tree_add_item(tree, hf_fcfzs_mbrtype, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (tvb_get_guint8(tvb, offset)) {
case FC_FZS_ZONEMBR_PWWN:
case FC_FZS_ZONEMBR_NWWN:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 8,
tvb_fcwwn_to_str(tvb, offset+4));
break;
case FC_FZS_ZONEMBR_DP:
proto_tree_add_string_format(tree,
hf_fcfzs_mbrid,
tvb, offset+4, 3, " ",
"0x%x",
tvb_get_ntoh24(tvb,
offset+4));
break;
case FC_FZS_ZONEMBR_FCID:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 4,
tvb_fc_to_str(tvb, offset+4));
break;
case FC_FZS_ZONEMBR_PWWN_LUN:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 8,
tvb_fcwwn_to_str(tvb, offset+4));
proto_tree_add_item(tree, hf_fcfzs_mbrid_lun, tvb,
offset+8, 8, ENC_NA);
break;
case FC_FZS_ZONEMBR_DP_LUN:
proto_tree_add_string_format(tree,
hf_fcfzs_mbrid,
tvb, offset+4, 3, " ",
"0x%x",
tvb_get_ntoh24(tvb,
offset+4));
proto_tree_add_item(tree, hf_fcfzs_mbrid_lun, tvb,
offset+4, 8, ENC_NA);
break;
case FC_FZS_ZONEMBR_FCID_LUN:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 4,
tvb_fc_to_str(tvb, offset+4));
proto_tree_add_item(tree, hf_fcfzs_mbrid_lun, tvb,
offset+4, 8, ENC_NA);
break;
default:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 8,
"Unknown member type format");
}
offset += 12;
}
}
}
}
static void
dissect_fcfzs_gzc(tvbuff_t *tvb, int offset, proto_tree *parent_tree, gboolean isreq)
{
if (!isreq) {
guint8 flags;
proto_item *item = NULL;
proto_tree *tree = NULL;
flags = tvb_get_guint8(tvb, offset);
if (parent_tree) {
item = proto_tree_add_uint(parent_tree, hf_fcfzs_gzc_flags, tvb, offset, 1, flags);
tree = proto_item_add_subtree(item, ett_fcfzs_gzc_flags);
}
proto_tree_add_boolean(tree, hf_fcfzs_gzc_flags_hard_zones, tvb, offset, 1, flags);
if (flags & 0x80) {
proto_item_append_text(item, " Hard Zones");
}
flags &= (~( 0x80 ));
proto_tree_add_boolean(tree, hf_fcfzs_gzc_flags_soft_zones, tvb, offset, 1, flags);
if (flags & 0x40) {
proto_item_append_text(item, " Soft Zones");
}
flags &= (~( 0x40 ));
proto_tree_add_boolean(tree, hf_fcfzs_gzc_flags_zoneset_db, tvb, offset, 1, flags);
if (flags & 0x01) {
proto_item_append_text(item, " ZoneSet Database Available");
}
proto_tree_add_item(tree, hf_fcfzs_gzc_vendor, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcfzs_gest(tvbuff_t *tvb, proto_tree *parent_tree, gboolean isreq)
{
int offset = 16;
if (!isreq) {
guint8 flags;
proto_item *item = NULL;
proto_tree *tree = NULL;
flags = tvb_get_guint8(tvb, offset);
if (parent_tree) {
item = proto_tree_add_uint(parent_tree, hf_fcfzs_zone_state, tvb, offset, 1, flags);
tree = proto_item_add_subtree(item, ett_fcfzs_zone_state);
}
proto_tree_add_boolean(tree, hf_fcfzs_soft_zone_set_enforced, tvb, offset, 1, flags);
if (flags & 0x80) {
proto_item_append_text(item, " Soft Zone Set Enforced");
}
flags &= (~( 0x80 ));
proto_tree_add_boolean(tree, hf_fcfzs_hard_zone_set_enforced, tvb, offset, 1, flags);
if (flags & 0x40) {
proto_item_append_text(item, " Hard Zone Set Enforced");
}
proto_tree_add_item(parent_tree, hf_fcfzs_gest_vendor, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcfzs_gzsn(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int numrec, i, len;
int offset = 16;
if (tree) {
if (!isreq) {
numrec = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_numzonesetattrs, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < numrec; i++) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonesetnmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonesetname, tvb, offset+1,
len, ENC_ASCII|ENC_NA);
offset += len + 1 + (len % 4);
proto_tree_add_item(tree, hf_fcfzs_numzones, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
}
}
}
static void
dissect_fcfzs_gzd(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int numrec, i, len;
int offset = 16;
if (tree) {
if (isreq) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonesetnmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonesetname, tvb, offset+1,
len, ENC_ASCII|ENC_NA);
}
else {
numrec = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_numzoneattrs, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < numrec; i++) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonenmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonename, tvb, offset+1,
len, ENC_ASCII|ENC_NA);
offset += len + 1 + (len % 4);
proto_tree_add_item(tree, hf_fcfzs_nummbrs, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
}
}
}
}
static void
dissect_fcfzs_gzm(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int numrec, i, len;
int offset = 16;
if (tree) {
if (isreq) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonenmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonename, tvb, offset+1,
len, ENC_ASCII|ENC_NA);
}
else {
numrec = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_nummbrentries, tvb, offset,
4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < numrec; i++) {
proto_tree_add_item(tree, hf_fcfzs_mbrtype, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (tvb_get_guint8(tvb, offset)) {
case FC_FZS_ZONEMBR_PWWN:
case FC_FZS_ZONEMBR_NWWN:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 8,
tvb_fcwwn_to_str(tvb, offset+4));
break;
case FC_FZS_ZONEMBR_DP:
proto_tree_add_string_format(tree,
hf_fcfzs_mbrid,
tvb, offset+4, 3, " ",
"0x%x",
tvb_get_ntoh24(tvb,
offset+4));
break;
case FC_FZS_ZONEMBR_FCID:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 4,
tvb_fc_to_str(tvb, offset+4));
break;
default:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 8,
"Unknown member type format");
}
offset += 12;
}
}
}
}
static void
dissect_fcfzs_gazs(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int offset = 16;
if (tree) {
if (!isreq) {
dissect_fcfzs_zoneset(tvb, tree, offset);
}
}
}
static void
dissect_fcfzs_gzs(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int offset = 16;
int len;
if (tree) {
if (isreq) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonesetnmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonesetname, tvb, offset+4,
len, ENC_ASCII|ENC_NA);
}
else {
dissect_fcfzs_zoneset(tvb, tree, offset);
}
}
}
static void
dissect_fcfzs_adzs(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int offset = 16;
if (tree) {
if (isreq) {
dissect_fcfzs_zoneset(tvb, tree, offset);
}
}
}
static void
dissect_fcfzs_azsd(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int offset = 16;
if (tree) {
if (isreq) {
dissect_fcfzs_zoneset(tvb, tree, offset);
}
}
}
static void
dissect_fcfzs_arzs(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int offset = 16;
int len;
if (tree) {
if (isreq) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonesetnmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonesetname, tvb, offset+4,
len, ENC_ASCII|ENC_NA);
}
}
}
static void
dissect_fcfzs_dzs(tvbuff_t *tvb _U_, proto_tree *tree _U_, gboolean isreq _U_)
{
return;
}
static void
dissect_fcfzs_arzm(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int numrec, i, len, plen;
int offset = 16;
if (tree) {
if (isreq) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonenmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonename, tvb, offset+1,
len, ENC_ASCII|ENC_NA);
len += (len % 4);
plen = tvb_length(tvb) - offset - len;
numrec = plen/12;
offset += len;
for (i = 0; i < numrec; i++) {
proto_tree_add_item(tree, hf_fcfzs_mbrtype, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (tvb_get_guint8(tvb, offset)) {
case FC_FZS_ZONEMBR_PWWN:
case FC_FZS_ZONEMBR_NWWN:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 8,
tvb_fcwwn_to_str(tvb, offset+4));
break;
case FC_FZS_ZONEMBR_DP:
proto_tree_add_string_format(tree,
hf_fcfzs_mbrid,
tvb, offset+4, 3, " ",
"0x%x",
tvb_get_ntoh24(tvb,
offset+4));
break;
case FC_FZS_ZONEMBR_FCID:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 4,
tvb_fc_to_str(tvb, offset+4));
break;
default:
proto_tree_add_string(tree, hf_fcfzs_mbrid, tvb,
offset+4, 8,
"Unknown member type format");
}
offset += 12;
}
}
}
}
static void
dissect_fcfzs_arzd(tvbuff_t *tvb, proto_tree *tree, gboolean isreq)
{
int offset = 16;
int len;
if (tree) {
if (isreq) {
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonesetnmlen, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonesetname, tvb, offset+4,
len, ENC_ASCII|ENC_NA);
len += (len % 4);
offset += len;
len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_fcfzs_zonenmlen, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_zonename, tvb, offset+4,
len, ENC_ASCII|ENC_NA);
}
}
}
static void
dissect_fcfzs_rjt(tvbuff_t *tvb, proto_tree *tree)
{
int offset = 0;
if (tree) {
proto_tree_add_item(tree, hf_fcfzs_reason, tvb, offset+13, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_rjtdetail, tvb, offset+14, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_fcfzs_rjtvendor, tvb, offset+15, 1, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcfzs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *fcfzs_tree = NULL;
int offset = 0;
fc_ct_preamble cthdr;
int opcode;
int failed_opcode = 0;
conversation_t *conversation;
fcfzs_conv_data_t *cdata;
fcfzs_conv_key_t ckey, *req_key;
gboolean isreq = TRUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Zone Server");
tvb_memcpy(tvb, (guint8 *)&cthdr, offset, FCCT_PRMBL_SIZE);
cthdr.revision = tvb_get_guint8(tvb, offset+1);
cthdr.in_id = tvb_get_ntoh24(tvb, offset);
cthdr.opcode = g_ntohs(cthdr.opcode);
opcode = cthdr.opcode;
cthdr.maxres_size = g_ntohs(cthdr.maxres_size);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_fcfzs, tvb, 0,
tvb_length(tvb),
"Zone Server");
fcfzs_tree = proto_item_add_subtree(ti, ett_fcfzs);
proto_tree_add_item(fcfzs_tree, hf_fcfzs_opcode, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(fcfzs_tree, hf_fcfzs_maxres_size, tvb, offset+10,
2, ENC_BIG_ENDIAN);
}
if ((opcode != FCCT_MSG_ACC) && (opcode != FCCT_MSG_RJT)) {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->oxid,
pinfo->rxid, NO_PORT2);
if (!conversation) {
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->oxid,
pinfo->rxid, NO_PORT2);
}
ckey.conv_idx = conversation->index;
cdata = (fcfzs_conv_data_t *)g_hash_table_lookup(fcfzs_req_hash,
&ckey);
if (cdata) {
cdata->opcode = opcode;
}
else {
req_key = wmem_new(wmem_file_scope(), fcfzs_conv_key_t);
req_key->conv_idx = conversation->index;
cdata = wmem_new(wmem_file_scope(), fcfzs_conv_data_t);
cdata->opcode = opcode;
g_hash_table_insert(fcfzs_req_hash, req_key, cdata);
}
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(opcode, fc_fzs_opcode_val,
"0x%x"));
}
else {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->oxid,
pinfo->rxid, NO_PORT2);
isreq = FALSE;
if (!conversation) {
if (opcode == FCCT_MSG_ACC) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(opcode, fc_fzs_opcode_val,
"0x%x"));
proto_tree_add_text(fcfzs_tree, tvb, 0, tvb_length(tvb),
"No record of Exchg. Unable to decode MSG_ACC");
return;
}
}
else {
ckey.conv_idx = conversation->index;
cdata = (fcfzs_conv_data_t *)g_hash_table_lookup(fcfzs_req_hash, &ckey);
if (cdata != NULL) {
if (opcode == FCCT_MSG_ACC)
opcode = cdata->opcode;
else
failed_opcode = cdata->opcode;
}
if (opcode != FCCT_MSG_RJT) {
col_add_fstr(pinfo->cinfo, COL_INFO, "MSG_ACC (%s)",
val_to_str(opcode,
fc_fzs_opcode_val, "0x%x"));
}
else {
col_add_fstr(pinfo->cinfo, COL_INFO, "MSG_RJT (%s)",
val_to_str(failed_opcode,
fc_fzs_opcode_val, "0x%x"));
}
if ((cdata == NULL) && (opcode != FCCT_MSG_RJT)) {
proto_tree_add_text(fcfzs_tree, tvb, 0, tvb_length(tvb),
"No record of Exchg. Unable to decode MSG_ACC/RJT");
return;
}
}
}
switch (opcode) {
case FCCT_MSG_RJT:
dissect_fcfzs_rjt(tvb, fcfzs_tree);
break;
case FC_FZS_GZC:
dissect_fcfzs_gzc(tvb, 16, fcfzs_tree, isreq);
break;
case FC_FZS_GEST:
dissect_fcfzs_gest(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_GZSN:
dissect_fcfzs_gzsn(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_GZD:
dissect_fcfzs_gzd(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_GZM:
dissect_fcfzs_gzm(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_GAZS:
dissect_fcfzs_gazs(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_GZS:
dissect_fcfzs_gzs(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_ADZS:
dissect_fcfzs_adzs(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_AZSD:
dissect_fcfzs_azsd(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_AZS:
dissect_fcfzs_arzs(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_DZS:
dissect_fcfzs_dzs(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_AZM:
dissect_fcfzs_arzm(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_AZD:
dissect_fcfzs_arzd(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_RZM:
dissect_fcfzs_arzm(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_RZD:
dissect_fcfzs_arzd(tvb, fcfzs_tree, isreq);
break;
case FC_FZS_RZS:
dissect_fcfzs_arzs(tvb, fcfzs_tree, isreq);
break;
default:
call_dissector(data_handle, tvb, pinfo, tree);
break;
}
}
void
proto_register_fcfzs(void)
{
static hf_register_info hf[] = {
{ &hf_fcfzs_opcode,
{"Opcode", "fcfzs.opcode",
FT_UINT16, BASE_HEX, VALS(fc_fzs_opcode_val), 0x0,
NULL, HFILL}},
{ &hf_fcfzs_gzc_vendor,
{"Vendor Specific Flags", "fcfzs.gzc.vendor",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_gest_vendor,
{"Vendor Specific State", "fcfzs.gest.vendor",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_numzoneattrs,
{"Number of Zone Attribute Entries", "fcfzs.zone.numattrs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_zonesetnmlen,
{"Zone Set Name Length", "fcfzs.zoneset.namelen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_zonesetname,
{"Zone Set Name", "fcfzs.zoneset.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_numzones,
{"Number of Zones", "fcfzs.zoneset.numzones",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_numzonesetattrs,
{"Number of Zone Set Attribute Entries", "fcfzs.zoneset.numattrs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_zonenmlen,
{"Zone Name Length", "fcfzs.zone.namelen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_zonename,
{"Zone Name", "fcfzs.zone.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_nummbrs,
{"Number of Zone Members", "fcfzs.zone.nummbrs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_nummbrentries,
{"Number of Zone Member Attribute Entries", "fcfzs.zonembr.numattrs",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_mbrtype,
{"Zone Member Identifier Type", "fcfzs.zonembr.idtype",
FT_UINT8, BASE_HEX, VALS(fc_fzs_zonembr_type_val), 0x0,
NULL, HFILL}},
#if 0
{ &hf_fcfzs_mbridlen,
{"Zone Member Identifier Length", "fcfzs.zonembr.idlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
#endif
{ &hf_fcfzs_mbrid,
{"Zone Member Identifier", "fcfzs.zone.mbrid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_reason,
{"Reason Code", "fcfzs.reason",
FT_UINT8, BASE_HEX, VALS(fc_ct_rjt_code_vals), 0x0,
NULL, HFILL}},
{ &hf_fcfzs_rjtdetail,
{"Reason Code Explanation", "fcfzs.rjtdetail",
FT_UINT8, BASE_HEX, VALS(fc_fzs_rjt_code_val), 0x0,
NULL, HFILL}},
{ &hf_fcfzs_rjtvendor,
{"Vendor Specific Reason", "fcfzs.rjtvendor",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_maxres_size,
{"Maximum/Residual Size", "fcfzs.maxres_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_mbrid_lun,
{"LUN", "fcfzs.zone.lun",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_gzc_flags,
{"Capabilities", "fcfzs.gzc.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_gzc_flags_hard_zones,
{"Hard Zones", "fcfzs.gzc.flags.hard_zones",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x80,
NULL, HFILL}},
{ &hf_fcfzs_gzc_flags_soft_zones,
{"Soft Zones", "fcfzs.gzc.flags.soft_zones",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x40,
NULL, HFILL}},
{ &hf_fcfzs_gzc_flags_zoneset_db,
{"ZoneSet Database", "fcfzs.gzc.flags.zoneset_db",
FT_BOOLEAN, 8, TFS(&tfs_available_not_available), 0x01,
NULL, HFILL}},
{ &hf_fcfzs_zone_state,
{"Zone State", "fcfzs.zone.state",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcfzs_soft_zone_set_enforced,
{"Soft Zone Set", "fcfzs.soft_zone_set.enforced",
FT_BOOLEAN, 8, TFS(&tfs_enforced_not_enforced), 0x80,
NULL, HFILL}},
{ &hf_fcfzs_hard_zone_set_enforced,
{"Hard Zone Set", "fcfzs.hard_zone_set.enforced",
FT_BOOLEAN, 8, TFS(&tfs_enforced_not_enforced), 0x40,
NULL, HFILL}},
};
static gint *ett[] = {
&ett_fcfzs,
&ett_fcfzs_gzc_flags,
&ett_fcfzs_zone_state,
};
proto_fcfzs = proto_register_protocol("Fibre Channel Fabric Zone Server", "FC FZS", "fcfzs");
proto_register_field_array(proto_fcfzs, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(&fcfzs_init_protocol);
}
void
proto_reg_handoff_fcfzs(void)
{
dissector_handle_t fzs_handle;
fzs_handle = create_dissector_handle(dissect_fcfzs, proto_fcfzs);
dissector_add_uint("fcct.server", FCCT_GSRVR_FZS, fzs_handle);
data_handle = find_dissector("data");
}
