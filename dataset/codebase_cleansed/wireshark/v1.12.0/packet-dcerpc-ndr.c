int
dissect_ndr_uint8(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint8 *pdata)
{
if (pdata)
*pdata = 0;
if (di->conformant_run) {
return offset;
}
return dissect_dcerpc_uint8(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
PIDL_dissect_uint8_val(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 param, guint8 *pval)
{
guint8 val;
if (di->conformant_run) {
return offset;
}
offset = dissect_dcerpc_uint8(tvb, offset, pinfo,
tree, drep, hfindex, &val);
if (param&PIDL_SET_COL_INFO) {
header_field_info *hf_info;
char *valstr;
hf_info = proto_registrar_get_nth(hfindex);
valstr = (char *)wmem_alloc(wmem_packet_scope(), 64);
valstr[0]=0;
switch (hf_info->display) {
case BASE_DEC:
if (hf_info->strings) {
g_snprintf(valstr, 64, "%s(%d)",val_to_str(val, (const value_string *)hf_info->strings, "Unknown:%u"), val);
} else {
g_snprintf(valstr, 64, "%d", val);
}
break;
case BASE_HEX:
if (hf_info->strings) {
g_snprintf(valstr, 64, "%s(0x%02x)",val_to_str(val, (const value_string *)hf_info->strings, "Unknown:%u"), val);
} else {
g_snprintf(valstr, 64, "0x%02x", val);
}
break;
default:
REPORT_DISSECTOR_BUG("Invalid hf->display value");
}
col_append_fstr(pinfo->cinfo, COL_INFO," %s:%s", hf_info->name, valstr);
}
if (pval) {
*pval = val;
}
return offset;
}
int
PIDL_dissect_uint8(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 param)
{
return PIDL_dissect_uint8_val(tvb, offset, pinfo, tree, di, drep, hfindex, param, NULL);
}
int
dissect_ndr_uint16(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint16 *pdata)
{
if (pdata)
*pdata = 0;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 2)) {
offset++;
}
return dissect_dcerpc_uint16(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
PIDL_dissect_uint16_val(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 param, guint16 *pval)
{
guint16 val;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 2)) {
offset++;
}
offset = dissect_dcerpc_uint16(tvb, offset, pinfo,
tree, drep, hfindex, &val);
if (param&PIDL_SET_COL_INFO) {
header_field_info *hf_info;
char *valstr;
hf_info = proto_registrar_get_nth(hfindex);
valstr = (char *)wmem_alloc(wmem_packet_scope(), 64);
valstr[0]=0;
switch (hf_info->display) {
case BASE_DEC:
if (hf_info->strings) {
g_snprintf(valstr, 64, "%s(%d)",val_to_str(val, (const value_string *)hf_info->strings, "Unknown:%u"), val);
} else {
g_snprintf(valstr, 64, "%d", val);
}
break;
case BASE_HEX:
if (hf_info->strings) {
g_snprintf(valstr, 64, "%s(0x%04x)",val_to_str(val, (const value_string *)hf_info->strings, "Unknown:%u"), val);
} else {
g_snprintf(valstr, 64, "0x%04x", val);
}
break;
default:
REPORT_DISSECTOR_BUG("Invalid hf->display value");
}
col_append_fstr(pinfo->cinfo, COL_INFO," %s:%s", hf_info->name, valstr);
}
if (pval) {
*pval = val;
}
return offset;
}
int
PIDL_dissect_uint16(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 param _U_)
{
return PIDL_dissect_uint16_val(tvb, offset, pinfo, tree, di, drep, hfindex, param, NULL);
}
int
dissect_ndr_uint32(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 *pdata)
{
if (pdata)
*pdata = 0;
if ((di != NULL) && (di->conformant_run)) {
return offset;
}
if ((di != NULL) && (!di->no_align) && (offset % 4)) {
offset += 4 - (offset % 4);
}
return dissect_dcerpc_uint32(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
dissect_ndr_uint3264(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint3264 *pdata)
{
if (di->call_data->flags & DCERPC_IS_NDR64) {
return dissect_ndr_uint64(tvb, offset, pinfo, tree, di, drep, hfindex, pdata);
} else {
guint32 val = 0;
offset = dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hfindex, &val);
if (pdata) {
*pdata = val;
}
return offset;
}
}
int
dissect_ndr_uint1632(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint1632 *pdata)
{
if (di->call_data->flags & DCERPC_IS_NDR64) {
return dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hfindex, pdata);
} else {
guint16 val = 0;
offset = dissect_ndr_uint16(tvb, offset, pinfo, tree, di, drep, hfindex, &val);
if (pdata) {
*pdata = val;
}
return offset;
}
}
int
PIDL_dissect_uint32_val(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 param, guint32 *rval)
{
guint32 val;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 4)) {
offset += 4 - (offset % 4);
}
offset = dissect_dcerpc_uint32(tvb, offset, pinfo,
tree, drep, hfindex, &val);
if (param&PIDL_SET_COL_INFO) {
header_field_info *hf_info;
char *valstr;
hf_info = proto_registrar_get_nth(hfindex);
valstr = (char *)wmem_alloc(wmem_packet_scope(), 64);
valstr[0]=0;
switch (hf_info->display) {
case BASE_DEC:
if (hf_info->strings) {
g_snprintf(valstr, 64, "%s(%d)",val_to_str(val, (const value_string *)hf_info->strings, "Unknown:%u"), val);
} else {
g_snprintf(valstr, 64, "%d", val);
}
break;
case BASE_HEX:
if (hf_info->strings) {
g_snprintf(valstr, 64, "%s(0x%08x)",val_to_str(val, (const value_string *)hf_info->strings, "Unknown:%u"), val);
} else {
g_snprintf(valstr, 64, "0x%08x", val);
}
break;
default:
REPORT_DISSECTOR_BUG("Invalid hf->display value");
}
col_append_fstr(pinfo->cinfo, COL_INFO," %s:%s", hf_info->name, valstr);
}
if (rval != NULL) {
*rval = val;
}
return offset;
}
int
PIDL_dissect_uint32(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 param)
{
return PIDL_dissect_uint32_val(tvb, offset, pinfo, tree, di, drep, hfindex, param, NULL);
}
int
dissect_ndr_duint32(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint64 *pdata)
{
if (pdata)
*pdata = 0;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 4)) {
offset += 4 - (offset % 4);
}
return dissect_dcerpc_uint64(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
dissect_ndr_uint64(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint64 *pdata)
{
if (pdata)
*pdata = 0;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 8)) {
gint padding = 8 - (offset % 8);
proto_tree_add_text(tree, tvb, offset, padding, "NDR-Padding: %d bytes", padding);
offset += padding;
}
return dissect_dcerpc_uint64(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
PIDL_dissect_uint64_val(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 param, guint64 *pval)
{
guint64 val;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 8)) {
offset += 8 - (offset % 8);
}
offset = dissect_dcerpc_uint64(tvb, offset, pinfo,
tree, drep, hfindex, &val);
if (param&PIDL_SET_COL_INFO) {
header_field_info *hf_info;
char *valstr;
hf_info = proto_registrar_get_nth(hfindex);
valstr = (char *)wmem_alloc(wmem_packet_scope(), 64);
valstr[0]=0;
switch (hf_info->display) {
case BASE_DEC:
if (hf_info->strings) {
g_snprintf(valstr, 64, "%s(%" G_GINT64_MODIFIER "u)",val_to_str( (guint32) val, (const value_string *)hf_info->strings, "Unknown:%u"), val);
} else {
g_snprintf(valstr, 64, "%" G_GINT64_MODIFIER "u", val);
}
break;
case BASE_HEX:
if (hf_info->strings) {
g_snprintf(valstr, 64, "%s(0x%" G_GINT64_MODIFIER "x)",val_to_str( (guint32) val, (const value_string *)hf_info->strings, "Unknown:%u"), val);
} else {
g_snprintf(valstr, 64, "0x%" G_GINT64_MODIFIER "x", val);
}
break;
default:
REPORT_DISSECTOR_BUG("Invalid hf->display value");
}
col_append_fstr(pinfo->cinfo, COL_INFO," %s:%s", hf_info->name, valstr);
}
if (pval) {
*pval = val;
}
return offset;
}
int
PIDL_dissect_uint64(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 param)
{
return PIDL_dissect_uint64_val(tvb, offset, pinfo, tree, di, drep, hfindex, param, NULL);
}
int
dissect_ndr_float(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, gfloat *pdata)
{
if (pdata)
*pdata = 0;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 4)) {
offset += 4 - (offset % 4);
}
return dissect_dcerpc_float(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
dissect_ndr_double(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, gdouble *pdata)
{
if (pdata)
*pdata = 0;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 8)) {
offset += 8 - (offset % 8);
}
return dissect_dcerpc_double(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
dissect_ndr_time_t(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, guint32 *pdata)
{
if (pdata)
*pdata = 0;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 4)) {
offset += 4 - (offset % 4);
}
return dissect_dcerpc_time_t(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
dissect_ndr_uuid_t(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, e_uuid_t *pdata)
{
if (pdata)
memset(pdata, 0, sizeof(*pdata));
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 4)) {
offset += 4 - (offset % 4);
}
return dissect_dcerpc_uuid_t(tvb, offset, pinfo,
tree, drep, hfindex, pdata);
}
int
dissect_ndr_ctx_hnd(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_,
proto_tree *tree, dcerpc_info *di, guint8 *drep,
int hfindex, e_ctx_hnd *pdata)
{
static e_ctx_hnd ctx_hnd;
if (di->conformant_run) {
return offset;
}
if (!di->no_align && (offset % 2)) {
offset += 4 - (offset % 4);
}
ctx_hnd.attributes = dcerpc_tvb_get_ntohl(tvb, offset, drep);
dcerpc_tvb_get_uuid(tvb, offset+4, drep, &ctx_hnd.uuid);
if (tree) {
proto_tree_add_item(tree, hfindex, tvb, offset, 20, ENC_NA);
}
if (pdata) {
*pdata = ctx_hnd;
}
return offset + 20;
}
