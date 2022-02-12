static void
bacapp_packet_stats_tree_init(stats_tree* st)
{
st_node_packets_by_ip = stats_tree_create_pivot(st, st_str_packets_by_ip, 0);
st_node_packets_by_ip_src = stats_tree_create_node(st, st_str_packets_by_ip_src, st_node_packets_by_ip, TRUE);
st_node_packets_by_ip_dst = stats_tree_create_node(st, st_str_packets_by_ip_dst, st_node_packets_by_ip, TRUE);
}
static int
bacapp_stats_tree_packet(stats_tree* st, packet_info* pinfo, epan_dissect_t* edt _U_, const void* p)
{
int packets_for_this_dst;
int packets_for_this_src;
int service_for_this_dst;
int service_for_this_src;
int src_for_this_dst;
int dst_for_this_src;
int objectid_for_this_dst;
int objectid_for_this_src;
int instanceid_for_this_dst;
int instanceid_for_this_src;
gchar *dststr;
gchar *srcstr;
const bacapp_info_value_t *binfo = (const bacapp_info_value_t *)p;
srcstr = wmem_strconcat(wmem_packet_scope(), "Src: ", address_to_str(&pinfo->src), NULL);
dststr = wmem_strconcat(wmem_packet_scope(), "Dst: ", address_to_str(&pinfo->dst), NULL);
tick_stat_node(st, st_str_packets_by_ip, 0, TRUE);
packets_for_this_dst = tick_stat_node(st, st_str_packets_by_ip_dst, st_node_packets_by_ip, TRUE);
packets_for_this_src = tick_stat_node(st, st_str_packets_by_ip_src, st_node_packets_by_ip, TRUE);
src_for_this_dst = tick_stat_node(st, dststr, packets_for_this_dst, TRUE);
dst_for_this_src = tick_stat_node(st, srcstr, packets_for_this_src, TRUE);
service_for_this_src = tick_stat_node(st, dststr, dst_for_this_src, TRUE);
service_for_this_dst = tick_stat_node(st, srcstr, src_for_this_dst, TRUE);
if (binfo->service_type) {
objectid_for_this_dst = tick_stat_node(st, binfo->service_type, service_for_this_dst, TRUE);
objectid_for_this_src = tick_stat_node(st, binfo->service_type, service_for_this_src, TRUE);
if (binfo->object_ident) {
instanceid_for_this_dst = tick_stat_node(st, binfo->object_ident, objectid_for_this_dst, TRUE);
tick_stat_node(st, binfo->instance_ident, instanceid_for_this_dst, FALSE);
instanceid_for_this_src = tick_stat_node(st, binfo->object_ident, objectid_for_this_src, TRUE);
tick_stat_node(st, binfo->instance_ident, instanceid_for_this_src, FALSE);
}
}
return 1;
}
static void
bacapp_service_stats_tree_init(stats_tree* st)
{
st_node_packets_by_service = stats_tree_create_pivot(st, st_str_packets_by_service, 0);
}
static int
bacapp_stats_tree_service(stats_tree* st, packet_info* pinfo, epan_dissect_t* edt _U_, const void* p)
{
int servicetype;
int src, dst;
int objectid;
gchar *dststr;
gchar *srcstr;
const bacapp_info_value_t *binfo = (const bacapp_info_value_t *)p;
srcstr = wmem_strconcat(wmem_packet_scope(), "Src: ", address_to_str(&pinfo->src), NULL);
dststr = wmem_strconcat(wmem_packet_scope(), "Dst: ", address_to_str(&pinfo->dst), NULL);
tick_stat_node(st, st_str_packets_by_service, 0, TRUE);
if (binfo->service_type) {
servicetype = tick_stat_node(st, binfo->service_type, st_node_packets_by_service, TRUE);
src = tick_stat_node(st, srcstr, servicetype, TRUE);
dst = tick_stat_node(st, dststr, src, TRUE);
if (binfo->object_ident) {
objectid = tick_stat_node(st, binfo->object_ident, dst, TRUE);
tick_stat_node(st, binfo->instance_ident, objectid, FALSE);
}
}
return 1;
}
static void
bacapp_objectid_stats_tree_init(stats_tree* st)
{
st_node_packets_by_objectid = stats_tree_create_pivot(st, st_str_packets_by_objectid, 0);
}
static int
bacapp_stats_tree_objectid(stats_tree* st, packet_info* pinfo, epan_dissect_t* edt _U_, const void* p)
{
int servicetype;
int src, dst;
int objectid;
gchar *dststr;
gchar *srcstr;
const bacapp_info_value_t *binfo = (const bacapp_info_value_t *)p;
srcstr = wmem_strconcat(wmem_packet_scope(), "Src: ", address_to_str(&pinfo->src), NULL);
dststr = wmem_strconcat(wmem_packet_scope(), "Dst: ", address_to_str(&pinfo->dst), NULL);
tick_stat_node(st, st_str_packets_by_objectid, 0, TRUE);
if (binfo->object_ident) {
objectid = tick_stat_node(st, binfo->object_ident, st_node_packets_by_objectid, TRUE);
src = tick_stat_node(st, srcstr, objectid, TRUE);
dst = tick_stat_node(st, dststr, src, TRUE);
if (binfo->service_type) {
servicetype = tick_stat_node(st, binfo->service_type, dst, TRUE);
tick_stat_node(st, binfo->instance_ident, servicetype, FALSE);
}
}
return 1;
}
static void
bacapp_instanceid_stats_tree_init(stats_tree* st)
{
st_node_packets_by_instanceid = stats_tree_create_pivot(st, st_str_packets_by_instanceid, 0);
}
static int
bacapp_stats_tree_instanceid(stats_tree* st, packet_info* pinfo, epan_dissect_t* edt _U_, const void* p)
{
int servicetype;
int src, dst;
int instanceid;
gchar *dststr;
gchar *srcstr;
const bacapp_info_value_t *binfo = (const bacapp_info_value_t *)p;
srcstr = wmem_strconcat(wmem_packet_scope(), "Src: ", address_to_str(&pinfo->src), NULL);
dststr = wmem_strconcat(wmem_packet_scope(), "Dst: ", address_to_str(&pinfo->dst), NULL);
tick_stat_node(st, st_str_packets_by_instanceid, 0, TRUE);
if (binfo->object_ident) {
instanceid = tick_stat_node(st, binfo->instance_ident, st_node_packets_by_instanceid, TRUE);
src = tick_stat_node(st, srcstr, instanceid, TRUE);
dst = tick_stat_node(st, dststr, src, TRUE);
if (binfo->service_type) {
servicetype = tick_stat_node(st, binfo->service_type, dst, TRUE);
tick_stat_node(st, binfo->object_ident, servicetype, FALSE);
}
}
return 1;
}
static void
register_bacapp_stat_trees(void)
{
stats_tree_register("bacapp", "bacapp_ip", "BACnet/Packets sorted by IP", 0,
bacapp_stats_tree_packet, bacapp_packet_stats_tree_init, NULL);
stats_tree_register("bacapp", "bacapp_service", "BACnet/Packets sorted by Service", 0,
bacapp_stats_tree_service, bacapp_service_stats_tree_init, NULL);
stats_tree_register("bacapp", "bacapp_objectid", "BACnet/Packets sorted by Object Type", 0,
bacapp_stats_tree_objectid, bacapp_objectid_stats_tree_init, NULL);
stats_tree_register("bacapp", "bacapp_instanceid", "BACnet/Packets sorted by Instance ID", 0,
bacapp_stats_tree_instanceid, bacapp_instanceid_stats_tree_init, NULL);
}
static gint
updateBacnetInfoValue(gint whichval, const gchar *data)
{
if (whichval == BACINFO_SERVICE) {
bacinfo.service_type = data;
return 0;
}
if (whichval == BACINFO_INVOKEID) {
bacinfo.invoke_id = data;
return 0;
}
if (whichval == BACINFO_OBJECTID) {
bacinfo.object_ident = data;
return 0;
}
if (whichval == BACINFO_INSTANCEID) {
bacinfo.instance_ident = data;
return 0;
}
return -1;
}
static const char*
val_to_split_str(guint32 val, guint32 split_val, const value_string *vs,
const char *fmt, const char *split_fmt)
{
if (val < split_val)
return val_to_str(val, vs, fmt);
else
return val_to_str(val, vs, split_fmt);
}
static gboolean
tag_is_extended_value(guint8 tag)
{
return (tag & 0x07) == 5;
}
static gboolean
tag_is_opening(guint8 tag)
{
return (tag & 0x07) == 6;
}
static gboolean
tag_is_closing(guint8 tag)
{
return (tag & 0x07) == 7;
}
static gboolean
tag_is_context_specific(guint8 tag)
{
return (tag & 0x08) != 0;
}
static gboolean
tag_is_extended_tag_number(guint8 tag)
{
return ((tag & 0xF0) == 0xF0);
}
static guint32
object_id_type(guint32 object_identifier)
{
return ((object_identifier >> 22) & 0x3FF);
}
static guint32
object_id_instance(guint32 object_identifier)
{
return (object_identifier & 0x3FFFFF);
}
static guint
fTagNo(tvbuff_t *tvb, guint offset)
{
return (guint)(tvb_get_guint8(tvb, offset) >> 4);
}
static gboolean
fUnsigned32(tvbuff_t *tvb, guint offset, guint32 lvt, guint32 *val)
{
gboolean valid = TRUE;
switch (lvt) {
case 1:
*val = tvb_get_guint8(tvb, offset);
break;
case 2:
*val = tvb_get_ntohs(tvb, offset);
break;
case 3:
*val = tvb_get_ntoh24(tvb, offset);
break;
case 4:
*val = tvb_get_ntohl(tvb, offset);
break;
default:
valid = FALSE;
break;
}
return valid;
}
static gboolean
fUnsigned64(tvbuff_t *tvb, guint offset, guint32 lvt, guint64 *val)
{
gboolean valid = FALSE;
gint64 value = 0;
guint8 data, i;
if (lvt && (lvt <= 8)) {
valid = TRUE;
for (i = 0; i < lvt; i++) {
data = tvb_get_guint8(tvb, offset+i);
value = (value << 8) + data;
}
*val = value;
}
return valid;
}
static gboolean
fSigned64(tvbuff_t *tvb, guint offset, guint32 lvt, gint64 *val)
{
gboolean valid = FALSE;
gint64 value = 0;
guint8 data;
guint32 i;
if (lvt && (lvt <= 7)) {
valid = TRUE;
data = tvb_get_guint8(tvb, offset);
if ((data & 0x80) != 0)
value = (-1 << 8) | data;
else
value = data;
for (i = 1; i < lvt; i++) {
data = tvb_get_guint8(tvb, offset+i);
value = (value << 8) + data;
}
*val = value;
}
return valid;
}
static guint
fTagHeaderTree(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, guint8 *tag_no, guint8* tag_info, guint32 *lvt)
{
proto_item *ti = NULL;
guint8 tag;
guint8 value;
guint tag_len = 1;
guint lvt_len = 1;
guint lvt_offset;
lvt_offset = offset;
tag = tvb_get_guint8(tvb, offset);
*tag_info = 0;
*lvt = tag & 0x07;
if (tag_is_context_specific(tag)) *tag_info = tag & 0x0F;
*tag_no = tag >> 4;
if (tag_is_extended_tag_number(tag)) {
*tag_no = tvb_get_guint8(tvb, offset + tag_len++);
}
if (tag_is_extended_value(tag)) {
lvt_offset += tag_len;
value = tvb_get_guint8(tvb, lvt_offset);
tag_len++;
if (value == 254) {
*lvt = tvb_get_ntohs(tvb, lvt_offset+1);
tag_len += 2;
lvt_len += 2;
} else if (value == 255) {
*lvt = tvb_get_ntohl(tvb, lvt_offset+1);
tag_len += 4;
lvt_len += 4;
} else
*lvt = value;
}
if (tree) {
proto_tree *subtree;
if (tag_is_opening(tag))
ti = proto_tree_add_text(tree, tvb, offset, tag_len, "{[%u]", *tag_no );
else if (tag_is_closing(tag))
ti = proto_tree_add_text(tree, tvb, offset, tag_len, "}[%u]", *tag_no );
else if (tag_is_context_specific(tag)) {
ti = proto_tree_add_text(tree, tvb, offset, tag_len,
"Context Tag: %u, Length/Value/Type: %u",
*tag_no, *lvt);
} else
ti = proto_tree_add_text(tree, tvb, offset, tag_len,
"Application Tag: %s, Length/Value/Type: %u",
val_to_str(*tag_no,
BACnetApplicationTagNumber,
ASHRAE_Reserved_Fmt),
*lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
proto_tree_add_item(subtree, hf_BACnetTagClass, tvb, offset, 1, ENC_BIG_ENDIAN);
if (tag_is_extended_tag_number(tag)) {
proto_tree_add_uint_format(subtree,
hf_BACnetContextTagNumber,
tvb, offset, 1, tag,
"Extended Tag Number");
proto_tree_add_item(subtree,
hf_BACnetExtendedTagNumber,
tvb, offset + 1, 1, ENC_BIG_ENDIAN);
} else {
if (tag_is_context_specific(tag))
proto_tree_add_item(subtree,
hf_BACnetContextTagNumber,
tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(subtree,
hf_BACnetApplicationTagNumber,
tvb, offset, 1, ENC_BIG_ENDIAN);
}
if (tag_is_closing(tag) || tag_is_opening(tag))
proto_tree_add_item(subtree,
hf_BACnetNamedTag,
tvb, offset, 1, ENC_BIG_ENDIAN);
else if (tag_is_extended_value(tag)) {
proto_tree_add_item(subtree,
hf_BACnetNamedTag,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(subtree, hf_bacapp_tag_lvt,
tvb, lvt_offset, lvt_len, *lvt);
} else
proto_tree_add_uint(subtree, hf_bacapp_tag_lvt,
tvb, lvt_offset, lvt_len, *lvt);
}
if (*lvt > tvb_length(tvb)) {
expert_add_info_format(pinfo, ti, &ei_bacapp_bad_length,
"LVT length too long: %d > %d", *lvt,
tvb_length(tvb));
*lvt = 1;
}
return tag_len;
}
static guint
fTagHeader(tvbuff_t *tvb, packet_info *pinfo, guint offset, guint8 *tag_no, guint8* tag_info,
guint32 *lvt)
{
return fTagHeaderTree(tvb, pinfo, NULL, offset, tag_no, tag_info, lvt);
}
static guint
fNullTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint8 tag_no, tag_info;
guint32 lvt;
proto_item *ti;
proto_tree *subtree;
ti = proto_tree_add_text(tree, tvb, offset, 1, "%sNULL", label);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset + 1;
}
static guint
fBooleanTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint8 tag_no, tag_info;
guint32 lvt = 0;
proto_item *ti;
proto_tree *subtree;
guint bool_len = 1;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_info && lvt == 1) {
lvt = tvb_get_guint8(tvb, offset+1);
++bool_len;
}
ti = proto_tree_add_text(tree, tvb, offset, bool_len,
"%s%s", label, lvt == 0 ? "FALSE" : "TRUE");
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset + bool_len;
}
static guint
fUnsignedTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint64 val = 0;
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fUnsigned64(tvb, offset + tag_len, lvt, &val))
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s(Unsigned) %" G_GINT64_MODIFIER "u", label, val);
else
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s - %u octets (Unsigned)", label, lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fDevice_Instance(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, int hf)
{
guint8 tag_no, tag_info;
guint32 lvt, safe_lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (lvt > 4)
safe_lvt = 4;
else
safe_lvt = lvt;
ti = proto_tree_add_item(tree, hf, tvb, offset+tag_len, safe_lvt, ENC_BIG_ENDIAN);
if (lvt != safe_lvt)
expert_add_info_format(pinfo, ti, &ei_bacapp_bad_length,
"This field claims to be an impossible %u bytes, while the max is %u", lvt, safe_lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fEnumeratedTagSplit(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, const gchar *label, const value_string *vs, guint32 split_val)
{
guint32 val = 0;
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fUnsigned32(tvb, offset+tag_len, lvt, &val)) {
if (vs)
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s %s", label, val_to_split_str(val, split_val, vs,
ASHRAE_Reserved_Fmt, Vendor_Proprietary_Fmt));
else
ti =proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s %u", label, val);
} else {
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s - %u octets (enumeration)", label, lvt);
}
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fEnumeratedTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset, const gchar *label, const value_string *vs)
{
return fEnumeratedTagSplit(tvb, pinfo, tree, offset, label, vs, 0);
}
static guint
fSignedTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
gint64 val = 0;
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fSigned64(tvb, offset + tag_len, lvt, &val))
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s(Signed) %" G_GINT64_MODIFIER "d", label, val);
else
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s - %u octets (Signed)", label, lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fRealTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
gfloat f_val;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
f_val = tvb_get_ntohieee_float(tvb, offset+tag_len);
ti = proto_tree_add_text(tree, tvb, offset, 4+tag_len,
"%s%f (Real)", label, f_val);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+4;
}
static guint
fDoubleTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
gdouble d_val;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
d_val = tvb_get_ntohieee_double(tvb, offset+tag_len);
ti = proto_tree_add_text(tree, tvb, offset, 8+tag_len,
"%s%f (Double)", label, d_val);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+8;
}
static guint
fProcessId(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint32 val = 0, lvt;
guint8 tag_no, tag_info;
proto_item *ti;
proto_tree *subtree;
guint tag_len;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fUnsigned32(tvb, offset+tag_len, lvt, &val))
ti = proto_tree_add_uint(tree, hf_bacapp_tag_ProcessId,
tvb, offset, lvt+tag_len, val);
else
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"Process Identifier - %u octets (Signed)", lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset += tag_len + lvt;
return offset;
}
static guint
fTimeSpan(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint32 val = 0, lvt;
guint8 tag_no, tag_info;
proto_item *ti;
proto_tree *subtree;
guint tag_len;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fUnsigned32(tvb, offset+tag_len, lvt, &val))
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s (hh.mm.ss): %d.%02d.%02d%s",
label,
(val / 3600), ((val % 3600) / 60), (val % 60),
val == 0 ? " (indefinite)" : "");
else
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s - %u octets (Signed)", label, lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fWeekNDay(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint32 month, weekOfMonth, dayOfWeek;
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
month = tvb_get_guint8(tvb, offset+tag_len);
weekOfMonth = tvb_get_guint8(tvb, offset+tag_len+1);
dayOfWeek = tvb_get_guint8(tvb, offset+tag_len+2);
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len, "%s %s, %s",
val_to_str(month, months, "month (%d) not found"),
val_to_str(weekOfMonth, weekofmonth, "week of month (%d) not found"),
val_to_str(dayOfWeek, day_of_week, "day of week (%d) not found"));
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fDate(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint32 year, month, day, weekday;
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
year = tvb_get_guint8(tvb, offset+tag_len);
month = tvb_get_guint8(tvb, offset+tag_len+1);
day = tvb_get_guint8(tvb, offset+tag_len+2);
weekday = tvb_get_guint8(tvb, offset+tag_len+3);
if ((year == 255) && (day == 255) && (month == 255) && (weekday == 255)) {
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%sany", label);
}
else if (year != 255) {
year += 1900;
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s%s %d, %d, (Day of Week = %s)",
label, val_to_str(month,
months,
"month (%d) not found"),
day, year, val_to_str(weekday,
day_of_week,
"(%d) not found"));
} else {
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s%s %d, any year, (Day of Week = %s)",
label, val_to_str(month, months, "month (%d) not found"),
day, val_to_str(weekday, day_of_week, "(%d) not found"));
}
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fTime(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint32 hour, minute, second, msec, lvt;
guint8 tag_no, tag_info;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
hour = tvb_get_guint8(tvb, offset+tag_len);
minute = tvb_get_guint8(tvb, offset+tag_len+1);
second = tvb_get_guint8(tvb, offset+tag_len+2);
msec = tvb_get_guint8(tvb, offset+tag_len+3);
if ((hour == 255) && (minute == 255) && (second == 255) && (msec == 255))
ti = proto_tree_add_text(tree, tvb, offset,
lvt+tag_len, "%sany", label);
else
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s%d:%02d:%02d.%d %s = %02d:%02d:%02d.%d",
label,
hour > 12 ? hour - 12 : hour,
minute, second, msec,
hour >= 12 ? "P.M." : "A.M.",
hour, minute, second, msec);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fDateTime(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
proto_tree *subtree = tree;
proto_item *tt;
if (label != NULL) {
tt = proto_tree_add_text(subtree, tvb, offset, 10, "%s", label);
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
}
offset = fDate(tvb, pinfo, subtree, offset, "Date: ");
return fTime(tvb, pinfo, subtree, offset, "Time: ");
}
static guint
fTimeValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
return offset;
}
offset = fTime(tvb, pinfo, tree, offset, "Time: ");
offset = fApplicationTypes(tvb, pinfo, tree, offset, "Value: ");
if (offset == lastoffset) break;
}
return offset;
}
static guint
fCalendarEntry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fDate(tvb, pinfo, tree, offset, "Date: ");
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fDateRange(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 2:
offset = fWeekNDay(tvb, pinfo, tree, offset);
break;
default:
return offset;
}
return offset;
}
static guint
fEventTimeStamps( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint32 lvt = 0;
proto_tree* subtree = tree;
proto_item* ti = 0;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
ti = proto_tree_add_text(tree, tvb, offset, lvt, "eventTimeStamps");
if (ti) {
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
}
offset = fTimeStamp(tvb, pinfo, subtree, offset, "TO-OFFNORMAL timestamp: ");
offset = fTimeStamp(tvb, pinfo, subtree, offset, "TO-FAULT timestamp: ");
offset = fTimeStamp(tvb, pinfo, subtree, offset, "TO-NORMAL timestamp: ");
}
return offset;
}
static guint
fTimeStamp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint8 tag_no = 0, tag_info = 0;
guint32 lvt = 0;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTime(tvb, pinfo, tree, offset, label?label:"time: ");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset,
label?label:"sequence number: ");
break;
case 2:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fDateTime(tvb, pinfo, tree, offset, label?label:"date time: ");
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
}
return offset;
}
static guint
fClientCOV(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
if (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = fApplicationTypes(tvb, pinfo, tree, offset, "increment: ");
}
return offset;
}
static guint
fDestination(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
if (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset,
"valid Days: ", BACnetDaysOfWeek);
offset = fTime(tvb, pinfo, tree, offset, "from time: ");
offset = fTime(tvb, pinfo, tree, offset, "to time: ");
offset = fRecipient(tvb, pinfo, tree, offset);
offset = fProcessId(tvb, pinfo, tree, offset);
offset = fApplicationTypes(tvb, pinfo, tree, offset,
"issue confirmed notifications: ");
offset = fBitStringTagVS(tvb, pinfo, tree, offset,
"transitions: ", BACnetEventTransitionBits);
}
return offset;
}
static guint
fOctetString(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label, guint32 lvt)
{
gchar *tmp;
guint start = offset;
guint8 tag_no, tag_info;
proto_tree *subtree = tree;
proto_item *ti = 0;
offset += fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (lvt > 0) {
tmp = tvb_bytes_to_str(tvb, offset, lvt);
ti = proto_tree_add_text(tree, tvb, offset, lvt, "%s %s", label, tmp);
offset += lvt;
}
if (ti)
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, start, &tag_no, &tag_info, &lvt);
return offset;
}
static guint
fMacAddress(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label, guint32 lvt)
{
gchar *tmp;
guint start = offset;
guint8 tag_no, tag_info;
proto_tree* subtree = tree;
proto_item* ti;
offset += fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
ti = proto_tree_add_text(tree, tvb, offset, 6, "%s", label);
if (lvt > 0) {
if (lvt == 6) {
guint32 ip = tvb_get_ipv4(tvb, offset);
guint16 port = tvb_get_ntohs(tvb, offset+4);
proto_tree_add_ipv4(tree, hf_bacapp_tag_IPV4, tvb, offset, 4, ip);
proto_tree_add_uint(tree, hf_bacapp_tag_PORT, tvb, offset+4, 2, port);
} else {
if (lvt == 18) {
struct e_in6_addr addr;
guint16 port = tvb_get_ntohs(tvb, offset+16);
tvb_get_ipv6(tvb, offset, &addr);
proto_tree_add_ipv6(tree, hf_bacapp_tag_IPV6, tvb, offset, 16, (const guint8 *) &addr);
proto_tree_add_uint(tree, hf_bacapp_tag_PORT, tvb, offset+16, 2, port);
} else {
tmp = tvb_bytes_to_str(tvb, offset, lvt);
ti = proto_tree_add_text(tree, tvb, offset, lvt, "%s", tmp);
}
}
offset += lvt;
}
if (ti)
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, start, &tag_no, &tag_info, &lvt);
return offset;
}
static guint
fAddress(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint offs;
offset = fUnsignedTag(tvb, pinfo, tree, offset, "network-number");
offs = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (lvt == 0) {
proto_tree_add_text(tree, tvb, offset, offs, "MAC-address: broadcast");
offset += offs;
} else
offset = fMacAddress(tvb, pinfo, tree, offset, "MAC-address: ", lvt);
return offset;
}
static guint
fSessionKey(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fOctetString(tvb, pinfo, tree, offset, "session key: ", 8);
return fAddress(tvb, pinfo, tree, offset);
}
static guint
fObjectIdentifier(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_length;
proto_item *ti;
proto_tree *subtree;
guint32 object_id;
tag_length = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
object_id = tvb_get_ntohl(tvb, offset+tag_length);
object_type = object_id_type(object_id);
ti = proto_tree_add_text(tree, tvb, offset, tag_length + 4,
"ObjectIdentifier: %s, %u",
val_to_split_str(object_type,
128,
BACnetObjectType,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt),
object_id_instance(object_id));
if (col_get_writable(pinfo->cinfo))
col_append_fstr(pinfo->cinfo, COL_INFO, "%s,%u ",
val_to_split_str(object_type,
128,
BACnetObjectType,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt),
object_id_instance(object_id));
updateBacnetInfoValue(BACINFO_OBJECTID,
wmem_strdup(wmem_packet_scope(),
val_to_split_str(object_type, 128,
BACnetObjectType, ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt)));
updateBacnetInfoValue(BACINFO_INSTANCEID,
wmem_strdup_printf(wmem_packet_scope(),
"Instance ID: %u",
object_id_instance(object_id)));
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset += tag_length;
proto_tree_add_item(subtree, hf_bacapp_objectType, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_bacapp_instanceNumber, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static guint
fRecipient(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_no < 2) {
if (tag_no == 0) {
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
}
else {
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fAddress(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
}
}
return offset;
}
static guint
fRecipientProcess(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *orgtree = tree;
proto_item *tt;
proto_tree *subtree;
tt = proto_tree_add_text(orgtree, tvb, offset, 1, "Recipient Process" );
tree = proto_item_add_subtree(tt, ett_bacapp_value);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
tt = proto_tree_add_text(tree, tvb, offset, 1, "Recipient");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset = fRecipient(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset = fProcessId(tvb, pinfo, tree, offset);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fCOVSubscription(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree;
proto_item *tt;
proto_tree *orgtree = tree;
guint itemno = 1;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info) ) {
return offset;
}
switch (tag_no) {
case 0:
tt = proto_tree_add_text(orgtree, tvb, offset, 1, "Subscription %d",itemno);
itemno = itemno + 1;
tree = proto_item_add_subtree(tt, ett_bacapp_value);
tt = proto_tree_add_text(tree, tvb, offset, 1, "Recipient");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fRecipientProcess(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
tt = proto_tree_add_text(tree, tvb, offset, 1, "Monitored Property Reference");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fBACnetObjectPropertyReference(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 2:
offset = fBooleanTag(tvb, pinfo, tree, offset, "Issue Confirmed Notifications: ");
break;
case 3:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Time Remaining: ");
break;
case 4:
offset = fRealTag(tvb, pinfo, tree, offset, "COV Increment: ");
break;
default:
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fAddressBinding(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
return fAddress(tvb, pinfo, tree, offset);
}
static guint
fActionCommand(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint8 tag_match)
{
guint lastoffset = 0, len;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
propertyArrayIndex = -1;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info) ) {
if (tag_no == tag_match) {
return offset;
}
offset += len;
subtree = tree;
continue;
}
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 2:
offset = fPropertyIdentifier(tvb, pinfo, subtree, offset);
break;
case 3:
offset = fPropertyArrayIndex(tvb, pinfo, subtree, offset);
break;
case 4:
offset = fPropertyValue(tvb, pinfo, subtree, offset, tag_info);
break;
case 5:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "Priority: ");
break;
case 6:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "Post Delay: ");
break;
case 7:
offset = fBooleanTag(tvb, pinfo, subtree, offset,
"Quit On Failure: ");
break;
case 8:
offset = fBooleanTag(tvb, pinfo, subtree, offset,
"Write Successful: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fActionList(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0, len;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *ti;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
subtree = tree;
if ( tag_no != 0 )
return offset;
offset += len;
continue;
}
if (tag_is_opening(tag_info)) {
ti = proto_tree_add_text(tree, tvb, offset, 1, "Action List");
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset,
&tag_no, &tag_info, &lvt);
}
switch (tag_no) {
case 0:
offset = fActionCommand(tvb, pinfo, subtree, offset, tag_no);
break;
default:
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fPropertyIdentifier(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
const gchar *label = "Property Identifier";
propertyIdentifier = 0;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fUnsigned32(tvb, offset+tag_len, lvt, (guint32 *)&propertyIdentifier)) {
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s: %s (%u)", label,
val_to_split_str(propertyIdentifier, 512,
BACnetPropertyIdentifier,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt), propertyIdentifier);
if (col_get_writable(pinfo->cinfo))
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_split_str(propertyIdentifier, 512,
BACnetPropertyIdentifier,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt));
} else {
return offset;
}
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
proto_tree_add_item(subtree, hf_BACnetPropertyIdentifier, tvb,
offset+tag_len, lvt, ENC_BIG_ENDIAN);
return offset+tag_len+lvt;
}
static guint
fPropertyArrayIndex(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fUnsigned32(tvb, offset + tag_len, lvt, (guint32 *)&propertyArrayIndex))
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"property Array Index (Unsigned) %u", propertyArrayIndex);
else
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"property Array Index - %u octets (Unsigned)", lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset+tag_len+lvt;
}
static guint
fCharacterString(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint8 tag_no, tag_info, character_set;
guint32 lvt, l;
gsize inbytesleft, outbytesleft = 512;
guint offs, extra = 1;
guint8 *str_val;
const char *coding;
guint8 bf_arr[512], *out = &bf_arr[0];
proto_item *ti;
proto_tree *subtree;
guint start = offset;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
offs = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
character_set = tvb_get_guint8(tvb, offset+offs);
if (character_set == 1) {
extra = 3;
}
offset += (offs+extra);
lvt -= (extra);
do {
inbytesleft = l = MIN(lvt, 256);
str_val = tvb_get_string(wmem_packet_scope(), tvb, offset, l);
switch (character_set) {
case ANSI_X34:
fConvertXXXtoUTF8(str_val, &inbytesleft, out, &outbytesleft, "UTF-8");
coding = "UTF-8";
break;
case IBM_MS_DBCS:
out = str_val;
coding = "IBM MS DBCS";
break;
case JIS_C_6226:
out = str_val;
coding = "JIS C 6226";
break;
case ISO_10646_UCS4:
fConvertXXXtoUTF8(str_val, &inbytesleft, out, &outbytesleft, "UCS-4BE");
coding = "ISO 10646 UCS-4";
break;
case ISO_10646_UCS2:
fConvertXXXtoUTF8(str_val, &inbytesleft, out, &outbytesleft, "UCS-2BE");
coding = "ISO 10646 UCS-2";
break;
case ISO_18859_1:
fConvertXXXtoUTF8(str_val, &inbytesleft, out, &outbytesleft, "ISO8859-1");
coding = "ISO 8859-1";
break;
default:
out = str_val;
coding = "unknown";
break;
}
ti = proto_tree_add_text(tree, tvb, offset, l, "%s%s '%s'", label, coding, out);
lvt -= l;
offset += l;
} while (lvt > 0);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, start, &tag_no, &tag_info, &lvt);
proto_tree_add_item(subtree, hf_BACnetCharacterSet, tvb, start+offs, 1, ENC_BIG_ENDIAN);
if (character_set == 1) {
proto_tree_add_text(subtree, tvb, start+offs+1, 2, "Code Page: %d", tvb_get_ntohs(tvb, start+offs+1));
}
}
return offset;
}
static guint
fBitStringTagVS(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label,
const value_string *src)
{
guint8 tag_no, tag_info, tmp;
gint j, unused, skip;
guint start = offset;
guint offs;
guint32 lvt, i, numberOfBytes;
guint8 bf_arr[256];
proto_tree* subtree = tree;
proto_item* ti;
offs = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
numberOfBytes = lvt-1;
offset += offs;
unused = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_text(tree, tvb, start, offs+lvt,
"%s(Bit String)", label);
if (ti) {
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
}
fTagHeaderTree(tvb, pinfo, subtree, start, &tag_no, &tag_info, &lvt);
proto_tree_add_text(subtree, tvb, offset, 1,
"Unused bits: %u", unused);
skip = 0;
for (i = 0; i < numberOfBytes; i++) {
tmp = tvb_get_guint8(tvb, (offset)+i+1);
if (i == numberOfBytes-1) { skip = unused; }
for (j = 0; j < 8-skip; j++) {
if (src != NULL) {
if (tmp & (1 << (7 - j)))
proto_tree_add_text(subtree, tvb,
offset+i+1, 1,
"%s = TRUE",
val_to_str((guint) (i*8 +j),
src,
ASHRAE_Reserved_Fmt));
else
proto_tree_add_text(subtree, tvb,
offset+i+1, 1,
"%s = FALSE",
val_to_str((guint) (i*8 +j),
src,
ASHRAE_Reserved_Fmt));
} else {
bf_arr[MIN(255, (i*8)+j)] = tmp & (1 << (7 - j)) ? '1' : '0';
}
}
}
if (src == NULL) {
bf_arr[MIN(255, numberOfBytes*8-unused)] = 0;
proto_tree_add_text(subtree, tvb, offset, lvt, "B'%s'", bf_arr);
}
offset += lvt;
return offset;
}
static guint
fBitStringTag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
return fBitStringTagVS(tvb, pinfo, tree, offset, label, NULL);
}
static guint
fApplicationTypesEnumeratedSplit(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset,
const gchar *label, const value_string *src, guint32 split_val)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
if (tvb_reported_length_remaining(tvb, offset) > 0) {
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (!tag_is_context_specific(tag_info)) {
switch (tag_no) {
case 0:
offset = fNullTag(tvb, pinfo, tree, offset, label);
break;
case 1:
offset = fBooleanTag(tvb, pinfo, tree, offset, label);
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, tree, offset, label);
break;
case 3:
offset = fSignedTag(tvb, pinfo, tree, offset, label);
break;
case 4:
offset = fRealTag(tvb, pinfo, tree, offset, label);
break;
case 5:
offset = fDoubleTag(tvb, pinfo, tree, offset, label);
break;
case 6:
offset = fOctetString(tvb, pinfo, tree, offset, label, lvt);
break;
case 7:
offset = fCharacterString(tvb, pinfo, tree, offset, label);
break;
case 8:
offset = fBitStringTagVS(tvb, pinfo, tree, offset, label, src);
break;
case 9:
offset = fEnumeratedTagSplit(tvb, pinfo, tree, offset, label, src, split_val);
break;
case 10:
offset = fDate(tvb, pinfo, tree, offset, label);
break;
case 11:
offset = fTime(tvb, pinfo, tree, offset, label);
break;
case 12:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 13:
case 14:
case 15:
proto_tree_add_text(tree, tvb, offset, lvt+tag_len, "%s'reserved for ASHRAE'", label);
offset += lvt + tag_len;
break;
default:
break;
}
}
}
return offset;
}
static guint
fShedLevel(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "shed percent: ");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "shed level: ");
break;
case 2:
offset = fRealTag(tvb, pinfo, tree, offset, "shed amount: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fApplicationTypesEnumerated(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset,
const gchar *label, const value_string *vs)
{
return fApplicationTypesEnumeratedSplit(tvb, pinfo, tree, offset, label, vs, 0);
}
static guint
fApplicationTypes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset,
const gchar *label)
{
return fApplicationTypesEnumeratedSplit(tvb, pinfo, tree, offset, label, NULL, 0);
}
static guint
fContextTaggedValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
gint tvb_len;
(void)label;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
tvb_len = tvb_reported_length_remaining(tvb, offset+tag_len);
if ((tvb_len >= 0) && ((guint32)tvb_len < lvt)) {
lvt = tvb_len;
}
ti = proto_tree_add_text(tree, tvb, offset+tag_len, lvt,
"Context Value (as %u DATA octets)", lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset + tag_len + lvt;
}
static guint
fPrescale(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info) ) {
return offset;
}
switch (tag_no) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Multiplier: ");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Modulo Divide: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fScale(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info) ) {
return offset;
}
switch (tag_no) {
case 0:
offset = fRealTag(tvb, pinfo, tree, offset, "Float Scale: ");
break;
case 1:
offset = fSignedTag(tvb, pinfo, tree, offset, "Integer Scale: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fLoggingRecord(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info) ) {
return offset;
}
switch (tag_no) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fDateTime(tvb, pinfo, tree, offset, "Timestamp: ");
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Present Value: ");
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Accumulated Value: ");
break;
case 3:
offset = fEnumeratedTag(tvb, pinfo, tree, offset, "Accumulator Status: ", BACnetAccumulatorStatus);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fSequenceOfEnums(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label, const value_string *vs)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info) ) {
return offset;
}
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, label, vs);
if ( offset == lastoffset ) break;
}
return offset;
}
static guint
fDoorMembers(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info) ) {
return offset;
}
offset = fDeviceObjectReference(tvb, pinfo, tree, offset);
if (offset == lastoffset) break;
}
return offset;
}
static guint
fListOfGroupMembers(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info) ) {
return offset;
}
offset = fReadAccessSpecification(tvb, pinfo, tree, offset);
if ( offset == lastoffset ) break;
}
return offset;
}
static guint
fAbstractSyntaxNType(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint lastoffset = 0, depth = 0;
char ar[256];
guint32 save_object_type;
if (propertyIdentifier >= 0) {
g_snprintf(ar, sizeof(ar), "%s: ",
val_to_split_str(propertyIdentifier, 512,
BACnetPropertyIdentifier,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt));
} else {
g_snprintf(ar, sizeof(ar), "Abstract Type: ");
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
if (depth <= 0) return offset;
}
switch (propertyIdentifier) {
case 2:
if (tag_is_context_specific(tag_info)) {
offset = fActionList(tvb, pinfo, tree, offset);
} else {
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar,
BACnetAction);
}
break;
case 30:
offset = fAddressBinding(tvb, pinfo, tree, offset);
break;
case 54:
offset = fLOPR(tvb, pinfo, tree, offset);
break;
case 55:
fSessionKey(tvb, pinfo, tree, offset);
break;
case 79:
case 96:
offset = fApplicationTypesEnumeratedSplit(tvb, pinfo, tree, offset, ar,
BACnetObjectType, 128);
break;
case 97:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar,
BACnetServicesSupported);
break;
case 102:
offset = fDestination(tvb, pinfo, tree, offset);
break;
case 107:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar,
BACnetSegmentation);
break;
case 111:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar,
BACnetStatusFlags);
break;
case 112:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar,
BACnetDeviceStatus);
break;
case 117:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar,
BACnetEngineeringUnits);
break;
case 87:
if (propertyArrayIndex == 0) {
offset = fApplicationTypes(tvb, pinfo, tree, offset, ar);
} else {
offset = fPriorityArray(tvb, pinfo, tree, offset);
}
break;
case 38:
if (object_type < 128) {
if (propertyArrayIndex == 0) {
offset = fApplicationTypes(tvb, pinfo, tree, offset, ar);
} else {
offset = fSpecialEvent(tvb, pinfo, tree, offset);
}
}
break;
case 19:
case 60:
case 132:
offset = fDeviceObjectPropertyReference(tvb, pinfo, tree, offset);
break;
case 109:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fBACnetObjectPropertyReference(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 123:
if (object_type < 128) {
if (propertyArrayIndex == 0) {
offset = fApplicationTypes(tvb, pinfo, tree, offset, ar);
} else {
offset = fWeeklySchedule(tvb, pinfo, tree, offset);
}
}
break;
case 127:
offset = fClientCOV(tvb, pinfo, tree, offset);
break;
case 131:
if ( object_type == 25 )
offset = fEventLogRecord(tvb, pinfo, tree, offset);
else if ( object_type == 27 )
offset = fLogMultipleRecord(tvb, pinfo, tree, offset);
else
offset = fLogRecord(tvb, pinfo, tree, offset);
break;
case 159:
case 165:
offset = fDeviceObjectReference(tvb, pinfo, tree, offset);
break;
case 196:
offset = fRestartReason(tvb, pinfo, tree, offset);
break;
case 212:
case 214:
case 218:
offset = fShedLevel(tvb, pinfo, tree, offset);
break;
case 152:
offset = fCOVSubscription(tvb, pinfo, tree, offset);
break;
case 23:
offset = fCalendarEntry(tvb, pinfo, tree, offset);
break;
case 116:
offset = fRecipient(tvb, pinfo, tree, offset);
break;
case 83:
offset = fEventParameter(tvb, pinfo, tree, offset);
break;
case 211:
offset = fDeviceObjectReference(tvb, pinfo, tree, offset);
break;
case 130:
offset = fEventTimeStamps(tvb, pinfo, tree, offset);
break;
case 197:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetLoggingType);
break;
case 36:
offset = fApplicationTypesEnumeratedSplit(tvb, pinfo, tree, offset, ar, BACnetEventState, 64);
break;
case 103:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetReliability);
break;
case 72:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetNotifyType);
break;
case 208:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetNodeType);
break;
case 231:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetDoorStatus);
break;
case 233:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetLockStatus);
break;
case 235:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetDoorSecuredStatus);
break;
case 158:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetMaintenance);
break;
case 92:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetProgramState);
break;
case 90:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetProgramRequest);
break;
case 100:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetProgramError);
break;
case 160:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetLifeSafetyMode);
break;
case 163:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetSilencedState);
break;
case 161:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetLifeSafetyOperation);
break;
case 164:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetLifeSafetyState);
break;
case 41:
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset, ar, BACnetFileAccessMethod);
break;
case 185:
offset = fPrescale(tvb, pinfo, tree, offset);
break;
case 187:
offset = fScale(tvb, pinfo, tree, offset);
break;
case 184:
offset = fLoggingRecord(tvb, pinfo, tree, offset);
break;
case 228:
offset = fDoorMembers(tvb, pinfo, tree, offset);
break;
case 181:
offset = fObjectPropertyReference(tvb, pinfo, tree, offset);
break;
case 78:
offset = fObjectPropertyReference(tvb, pinfo, tree, offset);
break;
case 234:
offset = fSequenceOfEnums(tvb, pinfo, tree, offset, "masked-alarm-value: ", BACnetDoorAlarmState);
break;
case 53:
save_object_type = object_type;
offset = fListOfGroupMembers(tvb, pinfo, tree, offset);
object_type = save_object_type;
break;
case 85:
if ( object_type == 11 )
{
offset = fReadAccessResult(tvb, pinfo, tree, offset);
break;
}
default:
if (tag_info) {
if (tag_is_opening(tag_info)) {
++depth;
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
} else if (tag_is_closing(tag_info)) {
--depth;
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
} else {
offset = fContextTaggedValue(tvb, pinfo, tree, offset, ar);
}
} else {
offset = fApplicationTypes(tvb, pinfo, tree, offset, ar);
}
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fPropertyValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint8 tag_info)
{
guint8 tag_no;
guint32 lvt;
if (tag_is_opening(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, tree, offset,
&tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, tree, offset);
if (tvb_length_remaining(tvb, offset) > 0) {
offset += fTagHeaderTree(tvb, pinfo, tree, offset,
&tag_no, &tag_info, &lvt);
}
} else {
proto_tree_add_text(tree, tvb, offset, tvb_length(tvb) - offset,
"expected Opening Tag!");
offset = tvb_length(tvb);
}
return offset;
}
static guint
fPropertyIdentifierValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint8 tagoffset)
{
guint lastoffset = offset;
guint8 tag_no, tag_info;
guint32 lvt;
offset = fPropertyReference(tvb, pinfo, tree, offset, tagoffset, 0);
if (offset > lastoffset) {
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_no == tagoffset+2) {
offset = fPropertyValue(tvb, pinfo, tree, offset, tag_info);
}
}
return offset;
}
static guint
fBACnetPropertyValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
offset = fPropertyIdentifierValue(tvb, pinfo, tree, offset, 0);
if (offset > lastoffset) {
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_context_specific(tag_info) && (tag_no == 3))
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Priority: ");
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fSubscribeCOVPropertyRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0, len;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += len;
subtree = tree;
continue;
}
switch (tag_no) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "subscriber Process Id: ");
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 2:
offset = fBooleanTag(tvb, pinfo, tree, offset, "issue Confirmed Notifications: ");
break;
case 3:
offset = fTimeSpan(tvb, pinfo, tree, offset, "life time");
break;
case 4:
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "monitoredPropertyIdentifier");
if (tt) {
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fBACnetPropertyReference(tvb, pinfo, subtree, offset, 1);
break;
}
FAULT;
break;
case 5:
offset = fRealTag(tvb, pinfo, tree, offset, "COV Increment: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fSubscribeCOVRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fSubscribeCOVPropertyRequest(tvb, pinfo, tree, offset);
}
static guint
fWhoHas(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "device Instance Low Limit: ");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "device Instance High Limit: ");
break;
case 2:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 3:
offset = fCharacterString(tvb, pinfo, tree, offset, "Object Name: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fDailySchedule(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_opening(tag_info) && tag_no == 0) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset;
}
offset = fTimeValue(tvb, pinfo, subtree, offset);
if (offset == lastoffset) break;
}
} else if ((tag_no == 0) && (lvt == 0)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
}
return offset;
}
static guint
fWeeklySchedule(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
guint i = 1;
proto_tree *subtree = tree;
proto_item *tt;
if (propertyArrayIndex > 0) {
i = propertyArrayIndex;
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
return offset;
}
tt = proto_tree_add_text(tree, tvb, offset, 0, "%s", val_to_str(i++, day_of_week, "day of week (%d) not found"));
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset = fDailySchedule(tvb, pinfo, subtree, offset);
if (offset == lastoffset) break;
}
return offset;
}
static guint
fUTCTimeSynchronizationRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return offset;
return fDateTime(tvb, pinfo, tree, offset, "UTC-Time: ");
}
static guint
fTimeSynchronizationRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return offset;
return fDateTime(tvb, pinfo, tree, offset, NULL);
}
static guint
fDateRange(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return offset;
offset = fDate(tvb, pinfo, tree, offset, "Start Date: ");
return fDate(tvb, pinfo, tree, offset, "End Date: ");
}
static guint
fVendorIdentifier(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint32 val = 0;
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
const gchar *label = "Vendor ID";
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fUnsigned32(tvb, offset + tag_len, lvt, &val))
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s: %s (%u)",
label,
val_to_str_ext_const(val, &BACnetVendorIdentifiers_ext, "Unknown Vendor"),
val);
else
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s - %u octets (Unsigned)", label, lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
if ((lvt < 1) || (lvt > 2)) {
proto_tree_add_expert_format(tree, pinfo, &ei_bacapp_bad_length, tvb, 0, lvt,
"Wrong length indicated. Expected 1 or 2, got %u", lvt);
return offset+tag_len+lvt;
}
proto_tree_add_item(subtree, hf_BACnetVendorIdentifier, tvb,
offset+tag_len, lvt, ENC_BIG_ENDIAN);
return offset+tag_len+lvt;
}
static guint
fRestartReason(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint32 val = 0;
guint8 tag_no, tag_info;
guint32 lvt;
guint tag_len;
proto_item *ti;
proto_tree *subtree;
const gchar *label = "Restart Reason";
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (fUnsigned32(tvb, offset + tag_len, lvt, &val))
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s: %s (%u)", label,
val_to_str_const(val, BACnetRestartReason, "Unknown reason"), val);
else
ti = proto_tree_add_text(tree, tvb, offset, lvt+tag_len,
"%s - %u octets (Unsigned)", label, lvt);
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
if (lvt != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_bacapp_bad_length, tvb, 0, lvt,
"Wrong length indicated. Expected 1, got %u", lvt);
return offset+tag_len+lvt;
}
proto_tree_add_item(subtree, hf_BACnetRestartReason, tvb,
offset+tag_len, lvt, ENC_BIG_ENDIAN);
return offset+tag_len+lvt;
}
static guint
fConfirmedTextMessageRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "message Class: ");
break;
case 1:
offset = fCharacterString(tvb, pinfo, tree, offset, "message Class: ");
break;
}
break;
case 2:
offset = fEnumeratedTag(tvb, pinfo, tree, offset, "message Priority: ",
BACnetMessagePriority);
break;
case 3:
offset = fCharacterString(tvb, pinfo, tree, offset, "message: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fUnconfirmedTextMessageRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fConfirmedTextMessageRequest(tvb, pinfo, tree, offset);
}
static guint
fConfirmedPrivateTransferRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset, len;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
tvbuff_t *next_tvb;
guint vendor_identifier = 0;
guint service_number = 0;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
fUnsigned32(tvb, offset+len, lvt, &vendor_identifier);
if (col_get_writable(pinfo->cinfo))
col_append_fstr(pinfo->cinfo, COL_INFO, "V=%u ", vendor_identifier);
offset = fVendorIdentifier(tvb, pinfo, subtree, offset);
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (dissector_try_uint(bacapp_dissector_table,
vendor_identifier, next_tvb, pinfo, tree)) {
offset += tvb_length(next_tvb);
return offset;
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
if (tag_no == 2) {
offset += len;
subtree = tree;
continue;
} else {
break;
}
}
switch (tag_no) {
case 1:
fUnsigned32(tvb, offset+len, lvt, &service_number);
if (col_get_writable(pinfo->cinfo))
col_append_fstr(pinfo->cinfo, COL_INFO, "SN=%u ", service_number);
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "service Number: ");
break;
case 2:
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "service Parameters");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
propertyIdentifier = -1;
offset = fAbstractSyntaxNType(tvb, pinfo, subtree, offset);
break;
}
FAULT;
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fUnconfirmedPrivateTransferRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fConfirmedPrivateTransferRequest(tvb, pinfo, tree, offset);
}
static guint
fConfirmedPrivateTransferAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fConfirmedPrivateTransferRequest(tvb, pinfo, tree, offset);
}
static guint
fLifeSafetyOperationRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const gchar *label)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
if (label != NULL) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "%s", label);
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 0:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "requesting Process Id: ");
break;
case 1:
offset = fCharacterString(tvb, pinfo, tree, offset, "requesting Source: ");
break;
case 2:
offset = fEnumeratedTagSplit(tvb, pinfo, tree, offset,
"request: ", BACnetLifeSafetyOperation, 64);
break;
case 3:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fBACnetPropertyStates(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
const gchar* label;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
label = wmem_strdup_printf(wmem_packet_scope(), "%s: ",
val_to_str_const( tag_no, VALS(BACnetPropertyStates), "Unknown State" ));
switch (tag_no) {
case 0:
offset = fBooleanTag(tvb, pinfo, tree, offset, label);
break;
case 11:
offset = fUnsignedTag(tvb, pinfo, tree, offset, label);
break;
default:
if ( (tag_no > BACnetPropertyStatesEnums_Size) ||
VALS(BACnetPropertyStatesEnums[tag_no].valstr) == NULL)
{
offset = fEnumeratedTag(tvb, pinfo, tree, offset, label, NULL);
}
else
{
offset = fEnumeratedTagSplit(tvb, pinfo, tree, offset, label,
VALS(BACnetPropertyStatesEnums[tag_no].valstr), 64);
}
break;
}
return offset;
}
static guint
fDeviceObjectPropertyValue(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
return offset;
}
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 2:
offset = fPropertyIdentifier(tvb, pinfo, tree, offset);
break;
case 3:
offset = fUnsignedTag(tvb, pinfo, tree, offset,
"arrayIndex: ");
break;
case 4:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fObjectPropertyReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fDeviceObjectPropertyReference(tvb, pinfo, tree, offset);
}
static guint
fDeviceObjectPropertyReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
return offset;
}
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
offset = fPropertyIdentifier(tvb, pinfo, tree, offset);
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, tree, offset,
"arrayIndex: ");
break;
case 3:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fNotificationParameters(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = offset;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
tt = proto_tree_add_text(subtree, tvb, offset, 0, "notification parameters (%d) %s",
tag_no, val_to_str_const(tag_no, BACnetEventType, "invalid type"));
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 0:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fBitStringTag(tvb, pinfo, subtree, offset,
"referenced-bitstring: ");
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 1:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fBACnetPropertyStates(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 2:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
switch (fTagNo(tvb, offset)) {
case 0:
offset = fBitStringTag(tvb, pinfo, subtree, offset,
"changed-bits: ");
break;
case 1:
offset = fRealTag(tvb, pinfo, subtree, offset,
"changed-value: ");
break;
default:
break;
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 3:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
propertyIdentifier = 85;
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
break;
case 2:
propertyIdentifier = 40;
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 4:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fRealTag(tvb, pinfo, subtree, offset, "reference-value: ");
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
break;
case 2:
offset = fRealTag(tvb, pinfo, subtree, offset, "setpoint-value: ");
break;
case 3:
offset = fRealTag(tvb, pinfo, subtree, offset, "error-limit: ");
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 5:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fRealTag(tvb, pinfo, subtree, offset, "exceeding-value: ");
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
break;
case 2:
offset = fRealTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
case 3:
offset = fRealTag(tvb, pinfo, subtree, offset, "exceeded-limit: ");
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 6:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
offset =fBACnetPropertyValue(tvb, pinfo, subtree, offset);
if (offset == lastoffset) break;
}
break;
case 7:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 2:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fDateTime(tvb, pinfo, subtree, offset, "previous-notification: ");
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 3:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fDateTime(tvb, pinfo, subtree, offset, "current-notification: ");
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 8:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fEnumeratedTagSplit(tvb, pinfo, subtree, offset,
"new-state: ", BACnetLifeSafetyState, 256);
break;
case 1:
offset = fEnumeratedTagSplit(tvb, pinfo, subtree, offset,
"new-mode: ", BACnetLifeSafetyMode, 256);
break;
case 2:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
break;
case 3:
offset = fEnumeratedTagSplit(tvb, pinfo, subtree, offset,
"operation-expected: ", BACnetLifeSafetyOperation, 64);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 9:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fVendorIdentifier(tvb, pinfo, subtree, offset);
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, subtree, offset,
"extended-event-type: ");
break;
case 2:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fApplicationTypes(tvb, pinfo, subtree, offset, "parameters: ");
offset = fDeviceObjectPropertyValue(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 10:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fDeviceObjectPropertyReference(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, subtree, offset,
"previous-notification: ");
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, subtree, offset,
"current-notification: ");
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 11:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, subtree, offset,
"exceeding-value: ");
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, subtree, offset,
"exceeded-limit: ");
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 13:
break;
case 14:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fDoubleTag(tvb, pinfo, subtree, offset, "exceeding-value: ");
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
break;
case 2:
offset = fDoubleTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
case 3:
offset = fDoubleTag(tvb, pinfo, subtree, offset, "exceeded-limit: ");
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 15:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fSignedTag(tvb, pinfo, subtree, offset, "exceeding-value: ");
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
case 3:
offset = fSignedTag(tvb, pinfo, subtree, offset, "exceeded-limit: ");
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 16:
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "exceeding-value: ");
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"status-flags: ", BACnetStatusFlags);
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
case 3:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "exceeded-limit: ");
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 17:
break;
case 18:
break;
default:
offset = fAbstractSyntaxNType(tvb, pinfo, subtree, offset);
break;
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset;
}
static guint
fEventParameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = offset;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
tt = proto_tree_add_text(subtree, tvb, offset, 0, "event parameters (%d) %s",
tag_no, val_to_str_const(tag_no, BACnetEventType, "invalid type"));
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 0:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
switch (tag_no) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset = fBitStringTag(tvb, pinfo, subtree, offset, "bitmask: ");
break;
case 2:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
offset = fBitStringTag(tvb, pinfo, subtree, offset,
"bitstring value: ");
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
default:
break;
}
}
break;
case 1:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
switch (tag_no) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
offset = fBACnetPropertyStates(tvb, pinfo, subtree, offset);
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
default:
break;
}
}
break;
case 2:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
switch (fTagNo(tvb, offset)) {
case 0:
offset = fBitStringTag(tvb, pinfo, subtree, offset, "bitmask: ");
break;
case 1:
offset = fRealTag(tvb, pinfo, subtree, offset,
"referenced Property Increment: ");
break;
default:
break;
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
default:
break;
}
}
break;
case 3:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
tag_no = fTagNo(tvb, offset);
switch (tag_no) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fDeviceObjectPropertyReference(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
default:
break;
}
}
break;
case 4:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
switch (tag_no) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fDeviceObjectPropertyReference(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 2:
offset = fRealTag(tvb, pinfo, subtree, offset, "low diff limit: ");
break;
case 3:
offset = fRealTag(tvb, pinfo, subtree, offset, "high diff limit: ");
break;
case 4:
offset = fRealTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
default:
break;
}
}
break;
case 5:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset = fRealTag(tvb, pinfo, subtree, offset, "low limit: ");
break;
case 2:
offset = fRealTag(tvb, pinfo, subtree, offset, "high limit: ");
break;
case 3:
offset = fRealTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
default:
break;
}
}
break;
case 7:
#if 0
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "notification threshold");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset,
"previous notification count: ");
break;
default:
return offset;
}
}
#endif
break;
case 8:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
offset = fEnumeratedTagSplit(tvb, pinfo, subtree, offset,
"life safety alarm value: ", BACnetLifeSafetyState, 256);
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 2:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
offset = fEnumeratedTagSplit(tvb, pinfo, subtree, offset,
"alarm value: ", BACnetLifeSafetyState, 256);
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 3:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fDeviceObjectPropertyReference(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
default:
break;
}
}
break;
case 9:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fVendorIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset,
"extended-event-type: ");
break;
case 2:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fApplicationTypes(tvb, pinfo, tree, offset, "parameters: ");
offset = fDeviceObjectPropertyValue(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
lastoffset = offset;
break;
default:
break;
}
if (offset == lastoffset) break;
}
break;
case 10:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, subtree, offset,
"notification-threshold: ");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, subtree, offset,
"previous-notification-count: ");
break;
default:
break;
}
}
break;
case 11:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, tree, offset, "Time Delay");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset,
"low-limit: ");
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, tree, offset,
"high-limit: ");
break;
default:
break;
}
}
break;
case 13:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
offset = fEnumeratedTagSplit(tvb, pinfo, subtree, offset,
"access event: ", BACnetAccessEvent, 512);
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fDeviceObjectPropertyReference(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
default:
break;
}
}
break;
case 14:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset = fDoubleTag(tvb, pinfo, subtree, offset, "low limit: ");
break;
case 2:
offset = fDoubleTag(tvb, pinfo, subtree, offset, "high limit: ");
break;
case 3:
offset = fDoubleTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
default:
break;
}
}
break;
case 15:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset = fSignedTag(tvb, pinfo, subtree, offset, "low limit: ");
break;
case 2:
offset = fSignedTag(tvb, pinfo, subtree, offset, "high limit: ");
break;
case 3:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
default:
break;
}
}
break;
case 16:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "low limit: ");
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "high limit: ");
break;
case 3:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "deadband: ");
break;
default:
break;
}
}
break;
case 17:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
offset = fCharacterString(tvb, pinfo, tree, offset, "alarm value: ");
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
default:
break;
}
}
break;
case 18:
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fTimeSpan(tvb, pinfo, subtree, offset, "Time Delay");
break;
case 1:
offset = fBitStringTagVS(tvb, pinfo, subtree, offset,
"selected flags: ", BACnetStatusFlags);
break;
default:
break;
}
}
break;
default:
break;
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
return offset;
}
static guint
fEventLogRecord(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fDate(tvb, pinfo, tree, offset, "Date: ");
offset = fTime(tvb, pinfo, tree, offset, "Time: ");
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
switch (fTagNo(tvb, offset)) {
case 0:
offset = fBitStringTagVS(tvb, pinfo, tree, offset, "log status:", BACnetLogStatus);
break;
case 1:
tt = proto_tree_add_text(tree, tvb, offset, 1, "notification: ");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fConfirmedEventNotificationRequest(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 2:
offset = fRealTag(tvb, pinfo, tree, offset, "time-change: ");
break;
default:
return offset;
}
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fLogRecord(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fDate(tvb, pinfo, tree, offset, "Date: ");
offset = fTime(tvb, pinfo, tree, offset, "Time: ");
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
switch (fTagNo(tvb, offset)) {
case 0:
offset = fBitStringTagVS(tvb, pinfo, tree, offset, "log status:", BACnetLogStatus);
break;
case 1:
offset = fBooleanTag(tvb, pinfo, tree, offset, "boolean-value: ");
break;
case 2:
offset = fRealTag(tvb, pinfo, tree, offset, "real value: ");
break;
case 3:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "enum value: ");
break;
case 4:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "unsigned value: ");
break;
case 5:
offset = fSignedTag(tvb, pinfo, tree, offset, "signed value: ");
break;
case 6:
offset = fBitStringTag(tvb, pinfo, tree, offset, "bitstring value: ");
break;
case 7:
offset = fNullTag(tvb, pinfo, tree, offset, "null value: ");
break;
case 8:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fError(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 9:
offset = fRealTag(tvb, pinfo, tree, offset, "time change: ");
break;
case 10:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 2:
offset = fBitStringTagVS(tvb, pinfo, tree, offset, "Status Flags:", BACnetStatusFlags);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fLogMultipleRecord(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fDate(tvb, pinfo, tree, offset, "Date: ");
offset = fTime(tvb, pinfo, tree, offset, "Time: ");
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
switch (fTagNo(tvb, offset)) {
case 0:
offset = fBitStringTagVS(tvb, pinfo, tree, offset, "log status:", BACnetLogStatus);
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
while ((tvb_reported_length_remaining(tvb, offset) > 0) && (offset != lastoffset)) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
lastoffset = offset;
break;
}
switch (tag_no) {
case 0:
offset = fBooleanTag(tvb, pinfo, tree, offset, "boolean-value: ");
break;
case 1:
offset = fRealTag(tvb, pinfo, tree, offset, "real value: ");
break;
case 2:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "enum value: ");
break;
case 3:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "unsigned value: ");
break;
case 4:
offset = fSignedTag(tvb, pinfo, tree, offset, "signed value: ");
break;
case 5:
offset = fBitStringTag(tvb, pinfo, tree, offset, "bitstring value: ");
break;
case 6:
offset = fNullTag(tvb, pinfo, tree, offset, "null value: ");
break;
case 7:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fError(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 8:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
}
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 2:
offset = fRealTag(tvb, pinfo, tree, offset, "time-change: ");
break;
default:
return offset;
}
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fConfirmedEventNotificationRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
switch (tag_no) {
case 0:
offset = fProcessId(tvb, pinfo, tree, offset);
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 2:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 3:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fTimeStamp(tvb, pinfo, tree, offset, NULL);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 4:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Notification Class: ");
break;
case 5:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Priority: ");
break;
case 6:
offset = fEnumeratedTagSplit(tvb, pinfo, tree, offset,
"Event Type: ", BACnetEventType, 64);
break;
case 7:
offset = fCharacterString(tvb, pinfo, tree, offset, "message Text: ");
break;
case 8:
offset = fEnumeratedTag(tvb, pinfo, tree, offset,
"Notify Type: ", BACnetNotifyType);
break;
case 9:
offset = fBooleanTag(tvb, pinfo, tree, offset, "ack Required: ");
break;
case 10:
offset = fEnumeratedTagSplit(tvb, pinfo, tree, offset,
"from State: ", BACnetEventState, 64);
break;
case 11:
offset = fEnumeratedTagSplit(tvb, pinfo, tree, offset,
"to State: ", BACnetEventState, 64);
break;
case 12:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fNotificationParameters(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fUnconfirmedEventNotificationRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fConfirmedEventNotificationRequest(tvb, pinfo, tree, offset);
}
static guint
fConfirmedCOVNotificationRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0, len;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += len;
subtree = tree;
continue;
}
switch (tag_no) {
case 0:
offset = fProcessId(tvb, pinfo, tree, offset);
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 2:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 3:
offset = fTimeSpan(tvb, pinfo, tree, offset, "Time remaining");
break;
case 4:
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "list of Values");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fBACnetPropertyValue(tvb, pinfo, subtree, offset);
break;
}
FAULT;
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fUnconfirmedCOVNotificationRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fConfirmedCOVNotificationRequest(tvb, pinfo, tree, offset);
}
static guint
fAcknowledgeAlarmRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no = 0, tag_info = 0;
guint32 lvt = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "acknowledging Process Id: ");
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 2:
offset = fEnumeratedTagSplit(tvb, pinfo, tree, offset,
"event State Acknowledged: ", BACnetEventState, 64);
break;
case 3:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fTimeStamp(tvb, pinfo, tree, offset, NULL);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 4:
offset = fCharacterString(tvb, pinfo, tree, offset, "acknowledgement Source: ");
break;
case 5:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fTimeStamp(tvb, pinfo, tree, offset, "acknowledgement timestamp: ");
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fGetAlarmSummaryAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
offset = fApplicationTypes(tvb, pinfo, tree, offset, "Object Identifier: ");
offset = fApplicationTypesEnumeratedSplit(tvb, pinfo, tree, offset,
"alarm State: ", BACnetEventState, 64);
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset,
"acknowledged Transitions: ", BACnetEventTransitionBits);
if (offset == lastoffset) break;
}
return offset;
}
static guint
fGetEnrollmentSummaryRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fEnumeratedTag(tvb, pinfo, tree, offset,
"acknowledgment Filter: ", BACnetAcknowledgementFilter);
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fRecipientProcess(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 2:
offset = fEnumeratedTag(tvb, pinfo, tree, offset,
"event State Filter: ", BACnetEventStateFilter);
break;
case 3:
offset = fEnumeratedTag(tvb, pinfo, tree, offset,
"event Type Filter: ", BACnetEventType);
break;
case 4:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fUnsignedTag(tvb, pinfo, tree, offset, "min Priority: ");
offset = fUnsignedTag(tvb, pinfo, tree, offset, "max Priority: ");
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 5:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "notification Class Filter: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fGetEnrollmentSummaryAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
offset = fApplicationTypes(tvb, pinfo, tree, offset, "Object Identifier: ");
offset = fApplicationTypesEnumeratedSplit(tvb, pinfo, tree, offset,
"event Type: ", BACnetEventType, 64);
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset,
"event State: ", BACnetEventState);
offset = fApplicationTypes(tvb, pinfo, tree, offset, "Priority: ");
if (tvb_reported_length_remaining(tvb, offset) > 0 && fTagNo(tvb, offset) == 2)
offset = fUnsignedTag(tvb, pinfo, tree, offset, "Notification Class: ");
if (offset == lastoffset) break;
}
return offset;
}
static guint
fGetEventInformationRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
if (tvb_reported_length_remaining(tvb, offset) > 0) {
if (fTagNo(tvb, offset) == 0) {
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
}
}
return offset;
}
static guint
flistOfEventSummaries(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree* subtree = tree;
proto_item* ti = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
offset = fEnumeratedTag(tvb, pinfo, tree, offset,
"event State: ", BACnetEventState);
break;
case 2:
offset = fBitStringTagVS(tvb, pinfo, tree, offset,
"acknowledged Transitions: ", BACnetEventTransitionBits);
break;
case 3:
ti = proto_tree_add_text(tree, tvb, offset, lvt, "eventTimeStamps");
if (ti) {
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fTimeStamp(tvb, pinfo, subtree, offset, "TO-OFFNORMAL timestamp: ");
offset = fTimeStamp(tvb, pinfo, subtree, offset, "TO-FAULT timestamp: ");
offset = fTimeStamp(tvb, pinfo, subtree, offset, "TO-NORMAL timestamp: ");
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
case 4:
offset = fEnumeratedTag(tvb, pinfo, tree, offset,
"Notify Type: ", BACnetNotifyType);
break;
case 5:
offset = fBitStringTagVS(tvb, pinfo, tree, offset,
"event Enable: ", BACnetEventTransitionBits);
break;
case 6:
ti = proto_tree_add_text(tree, tvb, offset, lvt, "eventPriorities");
if (ti) {
subtree = proto_item_add_subtree(ti, ett_bacapp_tag);
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "TO-OFFNORMAL Priority: ");
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "TO-FAULT Priority: ");
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "TO-NORMAL Priority: ");
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fLOPR(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
col_set_writable(pinfo->cinfo, FALSE);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
offset = fDeviceObjectPropertyReference(tvb, pinfo, tree, offset);
if (offset == lastoffset) break;
}
return offset;
}
static guint
fGetEventInformationACK(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = flistOfEventSummaries(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
case 1:
offset = fBooleanTag(tvb, pinfo, tree, offset, "more Events: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fAddListElementRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0, len;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
col_set_writable(pinfo->cinfo, FALSE);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += len;
subtree = tree;
continue;
}
switch (tag_no) {
case 0:
offset = fBACnetObjectPropertyReference(tvb, pinfo, subtree, offset);
break;
case 3:
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "listOfElements");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, subtree, offset);
break;
}
FAULT;
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fDeleteObjectRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fObjectIdentifier(tvb, pinfo, tree, offset);
}
static guint
fDeviceCommunicationControlRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "time Duration: ");
break;
case 1:
offset = fEnumeratedTag(tvb, pinfo, tree, offset, "enable-disable: ",
BACnetEnableDisable);
break;
case 2:
offset = fCharacterString(tvb, pinfo, tree, offset, "Password: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fReinitializeDeviceRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fEnumeratedTag(tvb, pinfo, tree, offset,
"reinitialized State Of Device: ",
BACnetReinitializedStateOfDevice);
break;
case 1:
offset = fCharacterString(tvb, pinfo, tree, offset, "Password: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fVtOpenRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset,
"vtClass: ", BACnetVTClass);
return fApplicationTypes(tvb, pinfo, tree, offset, "local VT Session ID: ");
}
static guint
fVtOpenAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fApplicationTypes(tvb, pinfo, tree, offset, "remote VT Session ID: ");
}
static guint
fVtCloseRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
offset= fApplicationTypes(tvb, pinfo, tree, offset, "remote VT Session ID: ");
if (offset == lastoffset) break;
}
return offset;
}
static guint
fVtDataRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset= fApplicationTypes(tvb, pinfo, tree, offset, "VT Session ID: ");
offset = fApplicationTypes(tvb, pinfo, tree, offset, "VT New Data: ");
return fApplicationTypes(tvb, pinfo, tree, offset, "VT Data Flag: ");
}
static guint
fVtDataAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fBooleanTag(tvb, pinfo, tree, offset, "all New Data Accepted: ");
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "accepted Octet Count: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fAuthenticateRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "pseudo Random Number: ");
break;
case 1:
proto_tree_add_item(tree, hf_bacapp_invoke_id, tvb, offset++, 1, ENC_BIG_ENDIAN);
break;
case 2:
offset = fCharacterString(tvb, pinfo, tree, offset, "operator Name: ");
break;
case 3:
offset = fCharacterString(tvb, pinfo, tree, offset, "operator Password: ");
break;
case 4:
offset = fBooleanTag(tvb, pinfo, tree, offset, "start Encyphered Session: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fAuthenticateAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fApplicationTypes(tvb, pinfo, tree, offset, "modified Random Number: ");
}
static guint
fRequestKeyRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
offset = fAddress(tvb, pinfo, tree, offset);
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
return fAddress(tvb, pinfo, tree, offset);
}
static guint
fRemoveListElementRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fAddListElementRequest(tvb, pinfo, tree, offset);
}
static guint
fReadPropertyRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fBACnetObjectPropertyReference(tvb, pinfo, tree, offset);
}
static guint
fReadPropertyAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0, len;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
propertyArrayIndex = -1;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += len;
subtree = tree;
continue;
}
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 1:
offset = fPropertyIdentifier(tvb, pinfo, subtree, offset);
break;
case 2:
offset = fPropertyArrayIndex(tvb, pinfo, subtree, offset);
break;
case 3:
offset = fPropertyValue(tvb, pinfo, subtree, offset, tag_info);
break;
default:
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fWritePropertyRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
propertyArrayIndex = -1;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 1:
offset = fPropertyIdentifier(tvb, pinfo, subtree, offset);
break;
case 2:
offset = fPropertyArrayIndex(tvb, pinfo, subtree, offset);
break;
case 3:
offset = fPropertyValue(tvb, pinfo, subtree, offset, tag_info);
break;
case 4:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "Priority: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fWriteAccessSpecification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, guint offset)
{
guint lastoffset = 0, len;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += len;
continue;
}
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 1:
if (tag_is_opening(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fBACnetPropertyValue(tvb, pinfo, subtree, offset);
break;
}
FAULT;
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fWritePropertyMultipleRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
if (offset >= tvb_reported_length(tvb))
return offset;
col_set_writable(pinfo->cinfo, FALSE);
return fWriteAccessSpecification(tvb, pinfo, tree, offset);
}
static guint
fPropertyReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint8 tagoffset, guint8 list)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
propertyArrayIndex = -1;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
return offset;
} else if (tag_is_opening(tag_info)) {
return offset;
}
switch (tag_no-tagoffset) {
case 0:
offset = fPropertyIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
offset = fPropertyArrayIndex(tvb, pinfo, tree, offset);
if (list != 0) break;
default:
lastoffset = offset;
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fBACnetPropertyReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint8 list)
{
col_set_writable(pinfo->cinfo, FALSE);
return fPropertyReference(tvb, pinfo, tree, offset, 0, list);
}
static guint
fBACnetObjectPropertyReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
offset = fPropertyReference(tvb, pinfo, tree, offset, 1, 0);
col_set_writable(pinfo->cinfo, FALSE);
default:
lastoffset = offset;
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fPriorityArray(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
char i = 1, ar[256];
guint lastoffset = 0;
if (propertyArrayIndex > 0) {
i = propertyArrayIndex;
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
g_snprintf(ar, sizeof(ar), "%s[%d]: ",
val_to_split_str(87 , 512,
BACnetPropertyIdentifier,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt),
i++);
offset = fApplicationTypes(tvb, pinfo, tree, offset, ar);
if (i > 16) {
break;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fDeviceObjectReference(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fSpecialEvent(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
guint lastoffset = 0, len;
gboolean closing_found = FALSE;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
if ( closing_found == TRUE )
break;
offset += len;
closing_found = TRUE;
continue;
}
switch (tag_no) {
case 0:
if (tag_is_opening(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fCalendarEntry(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
}
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 2:
if (tag_is_opening(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fTimeValue(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
}
FAULT;
break;
case 3:
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "event priority: ");
break;
default:
return offset;
}
closing_found = FALSE;
if (offset == lastoffset) break;
}
return offset;
}
static guint
fSelectionCriteria(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0, len;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += len;
continue;
}
switch (fTagNo(tvb, offset)) {
case 0:
offset = fPropertyIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
offset = fPropertyArrayIndex(tvb, pinfo, tree, offset);
break;
case 2:
offset = fEnumeratedTag(tvb, pinfo, tree, offset,
"relation Specifier: ", BACnetRelationSpecifier);
break;
case 3:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fObjectSelectionCriteria(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
break;
}
switch (tag_no) {
case 0:
offset = fEnumeratedTag(tvb, pinfo, subtree, offset,
"selection Logic: ", BACnetSelectionLogic);
break;
case 1:
if (tag_is_opening(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fSelectionCriteria(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
}
FAULT;
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fReadPropertyConditionalRequest(tvbuff_t *tvb, packet_info* pinfo, proto_tree *subtree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader (tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_opening(tag_info) && tag_no < 2) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 0:
offset = fObjectSelectionCriteria(tvb, pinfo, subtree, offset);
break;
case 1:
offset = fBACnetPropertyReference(tvb, pinfo, subtree, offset, 1);
break;
default:
return offset;
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fReadAccessSpecification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
proto_item *tt;
proto_tree *subtree = tree;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
case 1:
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "listOfPropertyReferences");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fBACnetPropertyReference(tvb, pinfo, subtree, offset, 1);
} else if (tag_is_closing(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset,
&tag_no, &tag_info, &lvt);
subtree = tree;
} else {
return offset;
}
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fReadAccessResult(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0, len;
guint8 tag_no;
guint8 tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += len;
if ((tag_no == 4 || tag_no == 5) && (subtree != tree)) subtree = subtree->parent;
continue;
}
switch (tag_no) {
case 0:
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
break;
case 1:
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(tree, tvb, offset, 1, "listOfResults");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
break;
}
FAULT;
break;
case 2:
offset = fPropertyIdentifierValue(tvb, pinfo, subtree, offset, 2);
break;
case 5:
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "propertyAccessError");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fError(tvb, pinfo, subtree, offset);
break;
}
FAULT;
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fReadPropertyConditionalAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fReadAccessResult(tvb, pinfo, tree, offset);
}
static guint
fCreateObjectRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_no < 2) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 0:
switch (fTagNo(tvb, offset)) {
case 0:
offset = fEnumeratedTagSplit(tvb, pinfo, subtree, offset, "Object Type: ", BACnetObjectType, 128);
break;
case 1:
offset = fObjectIdentifier(tvb, pinfo, subtree, offset);
break;
default:
break;
}
break;
case 1:
if (tag_is_opening(tag_info)) {
offset = fBACnetPropertyValue(tvb, pinfo, subtree, offset);
break;
}
FAULT;
break;
default:
break;
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fCreateObjectAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fObjectIdentifier(tvb, pinfo, tree, offset);
}
static guint
fReadRangeRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
offset = fBACnetObjectPropertyReference(tvb, pinfo, subtree, offset);
if (tvb_reported_length_remaining(tvb, offset) > 0) {
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "%s", val_to_str_const(tag_no, BACnetReadRangeOptions, "unknown range option"));
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 3:
case 6:
offset = fApplicationTypes(tvb, pinfo, subtree, offset, "reference Index: ");
offset = fApplicationTypes(tvb, pinfo, subtree, offset, "reference Count: ");
break;
case 4:
case 7:
offset = fDateTime(tvb, pinfo, subtree, offset, "reference Date/Time: ");
offset = fApplicationTypes(tvb, pinfo, subtree, offset, "reference Count: ");
break;
case 5:
offset = fDateTime(tvb, pinfo, subtree, offset, "beginning Time: ");
offset = fDateTime(tvb, pinfo, subtree, offset, "ending Time: ");
break;
default:
break;
}
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
}
}
return offset;
}
static guint
fReadRangeAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
propertyArrayIndex = -1;
offset = fBACnetObjectPropertyReference(tvb, pinfo, subtree, offset);
offset = fBitStringTagVS(tvb, pinfo, tree, offset,
"resultFlags: ",
BACnetResultFlags);
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "item Count: ");
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_opening(tag_info)) {
col_set_writable(pinfo->cinfo, FALSE);
tt = proto_tree_add_text(subtree, tvb, offset, 1, "itemData");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, subtree, offset);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
}
if (tvb_reported_length_remaining(tvb, offset) > 0) {
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "first Sequence Number: ");
}
return offset;
}
static guint
fAccessMethod(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint32 lvt;
guint8 tag_no, tag_info;
proto_item* tt;
proto_tree* subtree = NULL;
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(tree, tvb, offset, 1, "%s", val_to_str_const(tag_no, BACnetFileAccessOption, "invalid access method"));
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fApplicationTypes(tvb, pinfo, subtree, offset, val_to_str_const(tag_no, BACnetFileStartOption, "invalid option"));
offset = fApplicationTypes(tvb, pinfo, subtree, offset, val_to_str_const(tag_no, BACnetFileWriteInfo, "unknown option"));
if (tag_no == 1) {
while ((tvb_reported_length_remaining(tvb, offset) > 0)&&(offset>lastoffset)) {
lastoffset = offset;
offset = fApplicationTypes(tvb, pinfo, subtree, offset, "Record Data: ");
}
}
if ((bacapp_flags & BACAPP_MORE_SEGMENTS) == 0) {
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_closing(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
}
}
}
return offset;
}
static guint
fAtomicReadFileRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no, tag_info;
guint32 lvt;
proto_tree *subtree = tree;
proto_item *tt;
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1, "%s", val_to_str_const(tag_no, BACnetFileAccessOption, "unknown access method"));
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fSignedTag(tvb, pinfo, subtree, offset, val_to_str_const(tag_no, BACnetFileStartOption, "unknown option"));
offset = fUnsignedTag(tvb, pinfo, subtree, offset, val_to_str_const(tag_no, BACnetFileRequestCount, "unknown option"));
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
}
return offset;
}
static guint
fAtomicWriteFileRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fObjectIdentifier(tvb, pinfo, tree, offset);
offset = fAccessMethod(tvb, pinfo, tree, offset);
return offset;
}
static guint
fAtomicWriteFileAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint tag_no = fTagNo(tvb, offset);
return fSignedTag(tvb, pinfo, tree, offset, val_to_str_const(tag_no, BACnetFileStartOption, "unknown option"));
}
static guint
fAtomicReadFileAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fApplicationTypes(tvb, pinfo, tree, offset, "End Of File: ");
offset = fAccessMethod(tvb, pinfo, tree, offset);
return offset;
}
static guint
fReadPropertyMultipleRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *subtree, guint offset)
{
col_set_writable(pinfo->cinfo, FALSE);
return fReadAccessSpecification(tvb, pinfo, subtree, offset);
}
static guint
fReadPropertyMultipleAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
col_set_writable(pinfo->cinfo, FALSE);
return fReadAccessResult(tvb, pinfo, tree, offset);
}
static guint
fConfirmedServiceRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, gint service_choice)
{
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return offset;
switch (service_choice) {
case 0:
offset = fAcknowledgeAlarmRequest(tvb, pinfo, tree, offset);
break;
case 1:
offset = fConfirmedCOVNotificationRequest(tvb, pinfo, tree, offset);
break;
case 2:
offset = fConfirmedEventNotificationRequest(tvb, pinfo, tree, offset);
break;
case 3:
break;
case 4:
offset = fGetEnrollmentSummaryRequest(tvb, pinfo, tree, offset);
break;
case 5:
offset = fSubscribeCOVRequest(tvb, pinfo, tree, offset);
break;
case 6:
offset = fAtomicReadFileRequest(tvb, pinfo, tree, offset);
break;
case 7:
offset = fAtomicWriteFileRequest(tvb, pinfo, tree, offset);
break;
case 8:
offset = fAddListElementRequest(tvb, pinfo, tree, offset);
break;
case 9:
offset = fRemoveListElementRequest(tvb, pinfo, tree, offset);
break;
case 10:
offset = fCreateObjectRequest(tvb, pinfo, tree, offset);
break;
case 11:
offset = fDeleteObjectRequest(tvb, pinfo, tree, offset);
break;
case 12:
offset = fReadPropertyRequest(tvb, pinfo, tree, offset);
break;
case 13:
offset = fReadPropertyConditionalRequest(tvb, pinfo, tree, offset);
break;
case 14:
offset = fReadPropertyMultipleRequest(tvb, pinfo, tree, offset);
break;
case 15:
offset = fWritePropertyRequest(tvb, pinfo, tree, offset);
break;
case 16:
offset = fWritePropertyMultipleRequest(tvb, pinfo, tree, offset);
break;
case 17:
offset = fDeviceCommunicationControlRequest(tvb, pinfo, tree, offset);
break;
case 18:
offset = fConfirmedPrivateTransferRequest(tvb, pinfo, tree, offset);
break;
case 19:
offset = fConfirmedTextMessageRequest(tvb, pinfo, tree, offset);
break;
case 20:
offset = fReinitializeDeviceRequest(tvb, pinfo, tree, offset);
break;
case 21:
offset = fVtOpenRequest(tvb, pinfo, tree, offset);
break;
case 22:
offset = fVtCloseRequest(tvb, pinfo, tree, offset);
break;
case 23:
offset = fVtDataRequest(tvb, pinfo, tree, offset);
break;
case 24:
offset = fAuthenticateRequest(tvb, pinfo, tree, offset);
break;
case 25:
offset = fRequestKeyRequest(tvb, pinfo, tree, offset);
break;
case 26:
offset = fReadRangeRequest(tvb, pinfo, tree, offset);
break;
case 27:
offset = fLifeSafetyOperationRequest(tvb, pinfo, tree, offset, NULL);
break;
case 28:
offset = fSubscribeCOVPropertyRequest(tvb, pinfo, tree, offset);
break;
case 29:
offset = fGetEventInformationRequest(tvb, pinfo, tree, offset);
break;
default:
return offset;
}
return offset;
}
static guint
fConfirmedServiceAck(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, gint service_choice)
{
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return offset;
switch (service_choice) {
case 3:
offset = fGetAlarmSummaryAck(tvb, pinfo, tree, offset);
break;
case 4:
offset = fGetEnrollmentSummaryAck(tvb, pinfo, tree, offset);
break;
case 6:
offset = fAtomicReadFileAck(tvb, pinfo, tree, offset);
break;
case 7:
offset = fAtomicWriteFileAck(tvb, pinfo, tree, offset);
break;
case 10:
offset = fCreateObjectAck(tvb, pinfo, tree, offset);
break;
case 12:
offset = fReadPropertyAck(tvb, pinfo, tree, offset);
break;
case 13:
offset = fReadPropertyConditionalAck(tvb, pinfo, tree, offset);
break;
case 14:
offset = fReadPropertyMultipleAck(tvb, pinfo, tree, offset);
break;
case 18:
offset = fConfirmedPrivateTransferAck(tvb, pinfo, tree, offset);
break;
case 21:
offset = fVtOpenAck(tvb, pinfo, tree, offset);
break;
case 23:
offset = fVtDataAck(tvb, pinfo, tree, offset);
break;
case 24:
offset = fAuthenticateAck(tvb, pinfo, tree, offset);
break;
case 26:
offset = fReadRangeAck(tvb, pinfo, tree, offset);
break;
case 29:
offset = fGetEventInformationACK(tvb, pinfo, tree, offset);
break;
default:
return offset;
}
return offset;
}
static guint
fIAmRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fApplicationTypes(tvb, pinfo, tree, offset, "BACnet Object Identifier: ");
offset = fApplicationTypes(tvb, pinfo, tree, offset, "Maximum ADPU Length Accepted: ");
offset = fApplicationTypesEnumerated(tvb, pinfo, tree, offset,
"Segmentation Supported: ", BACnetSegmentation);
return fVendorIdentifier(tvb, pinfo, tree, offset);
}
static guint
fIHaveRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fApplicationTypes(tvb, pinfo, tree, offset, "Device Identifier: ");
offset = fApplicationTypes(tvb, pinfo, tree, offset, "Object Identifier: ");
return fApplicationTypes(tvb, pinfo, tree, offset, "Object Name: ");
}
static guint
fWhoIsRequest(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint val;
guint8 tag_len;
guint8 tag_no, tag_info;
guint32 lvt;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 0:
if (col_get_writable(pinfo->cinfo) && fUnsigned32(tvb, offset+tag_len, lvt, &val))
col_append_fstr(pinfo->cinfo, COL_INFO, "%d ", val);
offset = fDevice_Instance(tvb, pinfo, tree, offset,
hf_Device_Instance_Range_Low_Limit);
break;
case 1:
if (col_get_writable(pinfo->cinfo) && fUnsigned32(tvb, offset+tag_len, lvt, &val))
col_append_fstr(pinfo->cinfo, COL_INFO, "%d ", val);
offset = fDevice_Instance(tvb, pinfo, tree, offset,
hf_Device_Instance_Range_High_Limit);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fUnconfirmedServiceRequest(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, gint service_choice)
{
if (tvb_reported_length_remaining(tvb, offset) <= 0)
return offset;
switch (service_choice) {
case 0:
offset = fIAmRequest(tvb, pinfo, tree, offset);
break;
case 1:
offset = fIHaveRequest(tvb, pinfo, tree, offset);
break;
case 2:
offset = fUnconfirmedCOVNotificationRequest(tvb, pinfo, tree, offset);
break;
case 3:
offset = fUnconfirmedEventNotificationRequest(tvb, pinfo, tree, offset);
break;
case 4:
offset = fUnconfirmedPrivateTransferRequest(tvb, pinfo, tree, offset);
break;
case 5:
offset = fUnconfirmedTextMessageRequest(tvb, pinfo, tree, offset);
break;
case 206:
case 6:
offset = fTimeSynchronizationRequest(tvb, pinfo, tree, offset);
break;
case 7:
offset = fWhoHas(tvb, pinfo, tree, offset);
break;
case 8:
offset = fWhoIsRequest(tvb, pinfo, tree, offset);
break;
case 9:
offset = fUTCTimeSynchronizationRequest(tvb, pinfo, tree, offset);
break;
default:
break;
}
return offset;
}
static guint
fStartConfirmed(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *bacapp_tree, guint offset, guint8 ack,
gint *svc, proto_item **tt)
{
proto_item *tc;
proto_tree *bacapp_tree_control;
gint tmp;
guint extra = 2;
bacapp_seq = 0;
tmp = (gint) tvb_get_guint8(tvb, offset);
bacapp_flags = tmp & 0x0f;
if (ack == 0) {
extra = 3;
}
*svc = (gint) tvb_get_guint8(tvb, offset+extra);
if (bacapp_flags & 0x08)
*svc = (gint) tvb_get_guint8(tvb, offset+extra+2);
proto_tree_add_item(bacapp_tree, hf_bacapp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
tc = proto_tree_add_item(bacapp_tree, hf_bacapp_pduflags, tvb, offset, 1, ENC_BIG_ENDIAN);
bacapp_tree_control = proto_item_add_subtree(tc, ett_bacapp_control);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_SEG, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_MOR, tvb, offset, 1, ENC_BIG_ENDIAN);
if (ack == 0) {
proto_tree_add_item(bacapp_tree_control, hf_bacapp_SA, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree, hf_bacapp_response_segments, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree, hf_bacapp_max_adpu_size, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
offset++;
proto_tree_add_item(bacapp_tree, hf_bacapp_invoke_id, tvb, offset++, 1, ENC_BIG_ENDIAN);
if (bacapp_flags & 0x08) {
bacapp_seq = tvb_get_guint8(tvb, offset);
proto_tree_add_item(bacapp_tree, hf_bacapp_sequence_number, tvb,
offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree, hf_bacapp_window_size, tvb,
offset++, 1, ENC_BIG_ENDIAN);
}
*tt = proto_tree_add_item(bacapp_tree, hf_bacapp_service, tvb,
offset++, 1, ENC_BIG_ENDIAN);
return offset;
}
static guint
fContinueConfirmedRequestPDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bacapp_tree, guint offset, gint svc)
{
return fConfirmedServiceRequest(tvb, pinfo, bacapp_tree, offset, svc);
}
static guint
fConfirmedRequestPDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bacapp_tree, guint offset)
{
gint svc;
proto_item *tt = 0;
offset = fStartConfirmed(tvb, pinfo, bacapp_tree, offset, 0, &svc, &tt);
return fContinueConfirmedRequestPDU(tvb, pinfo, bacapp_tree, offset, svc);
}
static guint
fUnconfirmedRequestPDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bacapp_tree, guint offset)
{
gint tmp;
proto_tree_add_item(bacapp_tree, hf_bacapp_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
tmp = tvb_get_guint8(tvb, offset);
proto_tree_add_item(bacapp_tree, hf_bacapp_uservice, tvb,
offset++, 1, ENC_BIG_ENDIAN);
return fUnconfirmedServiceRequest(tvb, pinfo, bacapp_tree, offset, tmp);
}
static guint
fSimpleAckPDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *bacapp_tree, guint offset)
{
proto_tree_add_item(bacapp_tree, hf_bacapp_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree, hf_bacapp_invoke_id, tvb,
offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree, hf_bacapp_service, tvb,
offset++, 1, ENC_BIG_ENDIAN);
return offset;
}
static guint
fContinueComplexAckPDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bacapp_tree, guint offset, gint svc)
{
return fConfirmedServiceAck(tvb, pinfo, bacapp_tree, offset, svc);
}
static guint
fComplexAckPDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bacapp_tree, guint offset)
{
gint svc;
proto_item *tt = 0;
offset = fStartConfirmed(tvb, pinfo, bacapp_tree, offset, 1, &svc, &tt);
return fContinueComplexAckPDU(tvb, pinfo, bacapp_tree, offset, svc);
}
static guint
fSegmentAckPDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *bacapp_tree, guint offset)
{
proto_item *tc;
proto_tree *bacapp_tree_control;
tc = proto_tree_add_item(bacapp_tree, hf_bacapp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
bacapp_tree_control = proto_item_add_subtree(tc, ett_bacapp);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_NAK, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_SRV, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_invoke_id, tvb,
offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_sequence_number, tvb,
offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_window_size, tvb,
offset++, 1, ENC_BIG_ENDIAN);
return offset;
}
static guint
fContextTaggedError(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_info = 0;
guint8 parsed_tag = 0;
guint32 lvt = 0;
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &parsed_tag, &tag_info, &lvt);
offset = fError(tvb, pinfo, tree, offset);
return offset + fTagHeaderTree(tvb, pinfo, tree, offset, &parsed_tag, &tag_info, &lvt);
}
static guint
fConfirmedPrivateTransferError(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no = 0, tag_info = 0;
guint32 lvt = 0;
proto_tree *subtree = tree;
proto_item *tt;
guint vendor_identifier = 0;
guint service_number = 0;
guint8 tag_len = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
tag_len = fTagHeader(tvb, pinfo, offset, &tag_no, &tag_info, &lvt);
switch (tag_no) {
case 0:
offset = fContextTaggedError(tvb, pinfo, subtree, offset);
break;
case 1:
fUnsigned32(tvb, offset+tag_len, lvt, &vendor_identifier);
if (col_get_writable(pinfo->cinfo))
col_append_fstr(pinfo->cinfo, COL_INFO, "V=%u ", vendor_identifier);
offset = fVendorIdentifier(tvb, pinfo, subtree, offset);
break;
case 2:
fUnsigned32(tvb, offset+tag_len, lvt, &service_number);
if (col_get_writable(pinfo->cinfo))
col_append_fstr(pinfo->cinfo, COL_INFO, "SN=%u ", service_number);
offset = fUnsignedTag(tvb, pinfo, subtree, offset, "service Number: ");
break;
case 3:
if (tag_is_opening(tag_info)) {
tt = proto_tree_add_text(subtree, tvb, offset, 1,
"error Parameters");
subtree = proto_item_add_subtree(tt, ett_bacapp_value);
propertyIdentifier = -1;
offset += fTagHeaderTree(tvb, pinfo, subtree, offset, &tag_no, &tag_info, &lvt);
offset = fAbstractSyntaxNType(tvb, pinfo, subtree, offset);
} else if (tag_is_closing(tag_info)) {
offset += fTagHeaderTree(tvb, pinfo, subtree, offset,
&tag_no, &tag_info, &lvt);
subtree = tree;
} else {
return offset;
}
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fCreateObjectError(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fContextTaggedError(tvb, pinfo, tree, offset);
break;
case 1:
offset = fUnsignedTag(tvb, pinfo, tree, offset, "first failed element number: ");
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fChangeListError(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
return fCreateObjectError(tvb, pinfo, tree, offset);
}
static guint
fVTCloseError(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint8 tag_no = 0, tag_info = 0;
guint32 lvt = 0;
if (fTagNo(tvb, offset) == 0) {
offset = fContextTaggedError(tvb, pinfo, tree, offset);
if (fTagNo(tvb, offset) == 1) {
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fVtCloseRequest(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
}
}
return offset;
}
static guint
fWritePropertyMultipleError(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
guint lastoffset = 0;
guint8 tag_no = 0, tag_info = 0;
guint32 lvt = 0;
col_set_writable(pinfo->cinfo, FALSE);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
lastoffset = offset;
switch (fTagNo(tvb, offset)) {
case 0:
offset = fContextTaggedError(tvb, pinfo, tree, offset);
break;
case 1:
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
offset = fBACnetObjectPropertyReference(tvb, pinfo, tree, offset);
offset += fTagHeaderTree(tvb, pinfo, tree, offset, &tag_no, &tag_info, &lvt);
break;
default:
return offset;
}
if (offset == lastoffset) break;
}
return offset;
}
static guint
fError(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
offset = fApplicationTypesEnumeratedSplit(tvb, pinfo, tree, offset,
"error Class: ", BACnetErrorClass, 64);
return fApplicationTypesEnumeratedSplit(tvb, pinfo, tree, offset,
"error Code: ", BACnetErrorCode, 256);
}
static guint
fBACnetError(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, guint service)
{
switch (service) {
case 8:
case 9:
offset = fChangeListError(tvb, pinfo, tree, offset);
break;
case 10:
offset = fCreateObjectError(tvb, pinfo, tree, offset);
break;
case 16:
offset = fWritePropertyMultipleError(tvb, pinfo, tree, offset);
break;
case 18:
offset = fConfirmedPrivateTransferError(tvb, pinfo, tree, offset);
break;
case 22:
offset = fVTCloseError(tvb, pinfo, tree, offset);
break;
default:
return fError(tvb, pinfo, tree, offset);
}
return offset;
}
static guint
fErrorPDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bacapp_tree, guint offset)
{
proto_item *tc;
proto_tree *bacapp_tree_control;
guint8 tmp;
tc = proto_tree_add_item(bacapp_tree, hf_bacapp_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
bacapp_tree_control = proto_item_add_subtree(tc, ett_bacapp);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_invoke_id, tvb,
offset++, 1, ENC_BIG_ENDIAN);
tmp = tvb_get_guint8(tvb, offset);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_service, tvb,
offset++, 1, ENC_BIG_ENDIAN);
return fBACnetError(tvb, pinfo, bacapp_tree, offset, tmp);
}
static guint
fRejectPDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *bacapp_tree, guint offset)
{
proto_item *tc;
proto_tree *bacapp_tree_control;
tc = proto_tree_add_item(bacapp_tree, hf_bacapp_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
bacapp_tree_control = proto_item_add_subtree(tc, ett_bacapp);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_invoke_id, tvb,
offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree_control, hf_BACnetRejectReason, tvb,
offset++, 1, ENC_BIG_ENDIAN);
return offset;
}
static guint
fAbortPDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *bacapp_tree, guint offset)
{
proto_item *tc;
proto_tree *bacapp_tree_control;
tc = proto_tree_add_item(bacapp_tree, hf_bacapp_type, tvb, offset, 1, ENC_BIG_ENDIAN);
bacapp_tree_control = proto_item_add_subtree(tc, ett_bacapp);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_SRV, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree_control, hf_bacapp_invoke_id, tvb,
offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bacapp_tree_control, hf_BACnetAbortReason, tvb,
offset++, 1, ENC_BIG_ENDIAN);
return offset;
}
static guint
do_the_dissection(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 flag, bacapp_type;
guint offset = 0;
flag = (gint) tvb_get_guint8(tvb, 0);
bacapp_type = (flag >> 4) & 0x0f;
if (tvb == NULL) {
return 0;
}
switch (bacapp_type) {
case BACAPP_TYPE_CONFIRMED_SERVICE_REQUEST:
offset = fConfirmedRequestPDU(tvb, pinfo, tree, offset);
break;
case BACAPP_TYPE_UNCONFIRMED_SERVICE_REQUEST:
offset = fUnconfirmedRequestPDU(tvb, pinfo, tree, offset);
break;
case BACAPP_TYPE_SIMPLE_ACK:
offset = fSimpleAckPDU(tvb, pinfo, tree, offset);
break;
case BACAPP_TYPE_COMPLEX_ACK:
offset = fComplexAckPDU(tvb, pinfo, tree, offset);
break;
case BACAPP_TYPE_SEGMENT_ACK:
offset = fSegmentAckPDU(tvb, pinfo, tree, offset);
break;
case BACAPP_TYPE_ERROR:
offset = fErrorPDU(tvb, pinfo, tree, offset);
break;
case BACAPP_TYPE_REJECT:
offset = fRejectPDU(tvb, pinfo, tree, offset);
break;
case BACAPP_TYPE_ABORT:
offset = fAbortPDU(tvb, pinfo, tree, offset);
break;
}
return offset;
}
static void
dissect_bacapp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 flag, bacapp_type;
guint save_fragmented = FALSE, data_offset = 0, fragment = FALSE;
tvbuff_t *new_tvb = NULL;
guint offset = 0;
guint8 bacapp_seqno = 0;
guint8 bacapp_service, bacapp_reason;
guint8 bacapp_invoke_id = 0;
proto_item *ti;
proto_tree *bacapp_tree = NULL;
gint svc = 0;
proto_item *tt = 0;
gint8 ack = 0;
const gchar errstr[] = "ERROR: ";
const gchar rejstr[] = "REJECTED: ";
const gchar abortstr[] = "ABORTED: ";
const gchar sackstr[] = " (SimpleAck)";
const gchar cackstr[] = " (ComplexAck)";
const gchar uconfsreqstr[] = " (Unconfirmed Service Request)";
const gchar confsreqstr[] = " (Confirmed Service Request)";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "BACnet-APDU");
col_clear(pinfo->cinfo, COL_INFO);
flag = tvb_get_guint8(tvb, 0);
bacapp_type = (flag >> 4) & 0x0f;
col_add_fstr(pinfo->cinfo, COL_INFO, "%-16s",
val_to_str_const(bacapp_type, BACnetTypeName, "# unknown APDU #"));
bacinfo.service_type = NULL;
bacinfo.invoke_id = NULL;
bacinfo.instance_ident = NULL;
bacinfo.object_ident = NULL;
switch (bacapp_type) {
case BACAPP_TYPE_CONFIRMED_SERVICE_REQUEST:
if (flag & BACAPP_SEGMENTED_REQUEST) {
fragment = TRUE;
ack = 0;
bacapp_invoke_id = tvb_get_guint8(tvb, offset + 2);
bacapp_seqno = tvb_get_guint8(tvb, offset + 3);
bacapp_service = tvb_get_guint8(tvb, offset + 5);
data_offset = 6;
} else {
bacapp_invoke_id = tvb_get_guint8(tvb, offset + 2);
bacapp_service = tvb_get_guint8(tvb, offset + 3);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%3u] ",
val_to_str_const(bacapp_service,
BACnetConfirmedServiceChoice,
bacapp_unknown_service_str),
bacapp_invoke_id);
updateBacnetInfoValue(BACINFO_INVOKEID,
wmem_strdup_printf(wmem_packet_scope(), "Invoke ID: %d", bacapp_invoke_id));
updateBacnetInfoValue(BACINFO_SERVICE,
wmem_strconcat(wmem_packet_scope(),
val_to_str_const(bacapp_service,
BACnetConfirmedServiceChoice,
bacapp_unknown_service_str),
confsreqstr, NULL));
break;
case BACAPP_TYPE_UNCONFIRMED_SERVICE_REQUEST:
bacapp_service = tvb_get_guint8(tvb, offset + 1);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str_const(bacapp_service,
BACnetUnconfirmedServiceChoice,
bacapp_unknown_service_str));
updateBacnetInfoValue(BACINFO_SERVICE,
wmem_strconcat(wmem_packet_scope(),
val_to_str_const(bacapp_service,
BACnetUnconfirmedServiceChoice,
bacapp_unknown_service_str),
uconfsreqstr, NULL));
break;
case BACAPP_TYPE_SIMPLE_ACK:
bacapp_invoke_id = tvb_get_guint8(tvb, offset + 1);
bacapp_service = tvb_get_guint8(tvb, offset + 2);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%3u] ",
val_to_str_const(bacapp_service,
BACnetConfirmedServiceChoice,
bacapp_unknown_service_str),
bacapp_invoke_id);
updateBacnetInfoValue(BACINFO_INVOKEID,
wmem_strdup_printf(wmem_packet_scope(),
"Invoke ID: %d", bacapp_invoke_id));
updateBacnetInfoValue(BACINFO_SERVICE,
wmem_strconcat(wmem_packet_scope(),
val_to_str_const(bacapp_service,
BACnetConfirmedServiceChoice,
bacapp_unknown_service_str),
sackstr, NULL));
break;
case BACAPP_TYPE_COMPLEX_ACK:
if (flag & BACAPP_SEGMENTED_REQUEST) {
fragment = TRUE;
ack = 1;
bacapp_invoke_id = tvb_get_guint8(tvb, offset + 1);
bacapp_seqno = tvb_get_guint8(tvb, offset + 2);
bacapp_service = tvb_get_guint8(tvb, offset + 4);
data_offset = 5;
} else {
bacapp_invoke_id = tvb_get_guint8(tvb, offset + 1);
bacapp_service = tvb_get_guint8(tvb, offset + 2);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%3u] ",
val_to_str_const(bacapp_service,
BACnetConfirmedServiceChoice,
bacapp_unknown_service_str),
bacapp_invoke_id);
updateBacnetInfoValue(BACINFO_INVOKEID,
wmem_strdup_printf(wmem_packet_scope(), "Invoke ID: %d", bacapp_invoke_id));
updateBacnetInfoValue(BACINFO_SERVICE,
wmem_strconcat(wmem_packet_scope(),
val_to_str_const(bacapp_service,
BACnetConfirmedServiceChoice,
bacapp_unknown_service_str),
cackstr, NULL));
break;
case BACAPP_TYPE_SEGMENT_ACK:
break;
case BACAPP_TYPE_ERROR:
bacapp_invoke_id = tvb_get_guint8(tvb, offset + 1);
bacapp_service = tvb_get_guint8(tvb, offset + 2);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%3u] ",
val_to_str_const(bacapp_service,
BACnetConfirmedServiceChoice,
bacapp_unknown_service_str),
bacapp_invoke_id);
updateBacnetInfoValue(BACINFO_INVOKEID,
wmem_strdup_printf(wmem_packet_scope(), "Invoke ID: %d", bacapp_invoke_id));
updateBacnetInfoValue(BACINFO_SERVICE,
wmem_strconcat(wmem_packet_scope(),
errstr,
val_to_str_const(bacapp_service,
BACnetConfirmedServiceChoice,
bacapp_unknown_service_str),
NULL));
break;
case BACAPP_TYPE_REJECT:
bacapp_invoke_id = tvb_get_guint8(tvb, offset + 1);
bacapp_reason = tvb_get_guint8(tvb, offset + 2);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%3u] ",
val_to_split_str(bacapp_reason,
64,
BACnetRejectReason,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt), bacapp_invoke_id);
updateBacnetInfoValue(BACINFO_INVOKEID,
wmem_strdup_printf(wmem_packet_scope(), "Invoke ID: %d", bacapp_invoke_id));
updateBacnetInfoValue(BACINFO_SERVICE,
wmem_strconcat(wmem_packet_scope(), rejstr,
val_to_split_str(bacapp_reason, 64,
BACnetRejectReason,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt),
NULL));
break;
case BACAPP_TYPE_ABORT:
bacapp_invoke_id = tvb_get_guint8(tvb, offset + 1);
bacapp_reason = tvb_get_guint8(tvb, offset + 2);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s[%3u] ",
val_to_split_str(bacapp_reason,
64,
BACnetAbortReason,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt), bacapp_invoke_id);
updateBacnetInfoValue(BACINFO_INVOKEID,
wmem_strdup_printf(wmem_packet_scope(), "Invoke ID: %d", bacapp_invoke_id));
updateBacnetInfoValue(BACINFO_SERVICE,
wmem_strconcat(wmem_packet_scope(), abortstr,
val_to_split_str(bacapp_reason,
64,
BACnetAbortReason,
ASHRAE_Reserved_Fmt,
Vendor_Proprietary_Fmt),
NULL));
break;
default:
break;
}
save_fragmented = pinfo->fragmented;
ti = proto_tree_add_item(tree, proto_bacapp, tvb, offset, -1, ENC_NA);
bacapp_tree = proto_item_add_subtree(ti, ett_bacapp);
if (!fragment)
do_the_dissection(tvb, pinfo, bacapp_tree);
else
fStartConfirmed(tvb, pinfo, bacapp_tree, offset, ack, &svc, &tt);
if (fragment) {
fragment_head *frag_msg;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_check(&msg_reassembly_table,
tvb, data_offset,
pinfo,
bacapp_invoke_id,
NULL,
bacapp_seqno,
tvb_reported_length_remaining(tvb, data_offset),
flag & BACAPP_MORE_SEGMENTS);
new_tvb = process_reassembled_data(tvb, data_offset, pinfo,
"Reassembled BACapp", frag_msg, &msg_frag_items,
NULL, tree);
if (new_tvb) {
col_append_str(pinfo->cinfo, COL_INFO,
" (Message Reassembled)");
} else {
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Message fragment %u)", bacapp_seqno);
}
if (new_tvb) {
switch (bacapp_type) {
case BACAPP_TYPE_CONFIRMED_SERVICE_REQUEST:
fContinueConfirmedRequestPDU(new_tvb, pinfo, bacapp_tree, 0, svc);
break;
case BACAPP_TYPE_COMPLEX_ACK:
fContinueComplexAckPDU(new_tvb, pinfo, bacapp_tree, 0, svc);
break;
default:
break;
}
}
}
pinfo->fragmented = save_fragmented;
tap_queue_packet(bacapp_tap, pinfo, &bacinfo);
}
static void
bacapp_init_routine(void)
{
reassembly_table_init(&msg_reassembly_table,
&addresses_reassembly_table_functions);
}
static guint32
fConvertXXXtoUTF8(gchar *in, gsize *inbytesleft, gchar *out, gsize *outbytesleft, const gchar *fromcoding)
{
guint32 i;
GIConv icd;
if ((icd = g_iconv_open("UTF-8", fromcoding)) != (GIConv) -1) {
i = (guint32) g_iconv(icd, &in, inbytesleft, &out, outbytesleft);
out[0] = '\0';
g_iconv_close(icd);
return i;
}
uni_to_string(in, *inbytesleft, out);
out[*inbytesleft] = '\0';
*outbytesleft -= *inbytesleft;
*inbytesleft = 0;
return 0;
}
static void
uni_to_string(char * data, gsize str_length, char *dest_buf)
{
gint i;
guint16 c_char;
gsize length_remaining;
length_remaining = str_length;
dest_buf[0] = '\0';
if (str_length == 0) {
return;
}
for ( i = 0; i < (gint) str_length; i++ ) {
c_char = data[i];
if ((c_char < 0x20) || (c_char > 0x7e)) {
if (c_char != 0x00) {
c_char = '.';
dest_buf[i] = c_char & 0xff;
} else {
i--;
str_length--;
}
} else {
dest_buf[i] = c_char & 0xff;
}
length_remaining--;
if (length_remaining == 0) {
dest_buf[i+1] = '\0';
return;
}
}
if (i < 0) {
i = 0;
}
dest_buf[i] = '\0';
return;
}
void
proto_register_bacapp(void)
{
static hf_register_info hf[] = {
{ &hf_bacapp_type,
{ "APDU Type", "bacapp.type",
FT_UINT8, BASE_DEC, VALS(BACnetTypeName), 0xf0, NULL, HFILL }
},
{ &hf_bacapp_pduflags,
{ "PDU Flags", "bacapp.pduflags",
FT_UINT8, BASE_HEX, NULL, 0x0f, NULL, HFILL }
},
{ &hf_bacapp_SEG,
{ "Segmented Request", "bacapp.segmented_request",
FT_BOOLEAN, 8, TFS(&segments_follow), 0x08, NULL, HFILL }
},
{ &hf_bacapp_MOR,
{ "More Segments", "bacapp.more_segments",
FT_BOOLEAN, 8, TFS(&more_follow), 0x04, "More Segments Follow", HFILL }
},
{ &hf_bacapp_SA,
{ "SA", "bacapp.SA",
FT_BOOLEAN, 8, TFS(&segmented_accept), 0x02, "Segmented Response accepted", HFILL }
},
{ &hf_bacapp_max_adpu_size,
{ "Size of Maximum ADPU accepted", "bacapp.max_adpu_size",
FT_UINT8, BASE_DEC, VALS(BACnetMaxAPDULengthAccepted), 0x0f, NULL, HFILL }
},
{ &hf_bacapp_response_segments,
{ "Max Response Segments accepted", "bacapp.response_segments",
FT_UINT8, BASE_DEC, VALS(BACnetMaxSegmentsAccepted), 0x70, NULL, HFILL }
},
{ &hf_bacapp_objectType,
{ "Object Type", "bacapp.objectType",
FT_UINT32, BASE_DEC, VALS(BACnetObjectType), 0xffc00000, NULL, HFILL }
},
{ &hf_bacapp_instanceNumber,
{ "Instance Number", "bacapp.instance_number",
FT_UINT32, BASE_DEC, NULL, 0x003fffff, NULL, HFILL }
},
{ &hf_BACnetPropertyIdentifier,
{ "Property Identifier", "bacapp.property_identifier",
FT_UINT32, BASE_DEC, VALS(BACnetPropertyIdentifier), 0, NULL, HFILL }
},
{ &hf_BACnetVendorIdentifier,
{ "Vendor Identifier", "bacapp.vendor_identifier",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &BACnetVendorIdentifiers_ext, 0, NULL, HFILL }
},
{ &hf_BACnetRestartReason,
{ "Restart Reason", "bacapp.restart_reason",
FT_UINT8, BASE_DEC, VALS(BACnetRestartReason), 0, NULL, HFILL }
},
{ &hf_bacapp_invoke_id,
{ "Invoke ID", "bacapp.invoke_id",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_bacapp_sequence_number,
{ "Sequence Number", "bacapp.sequence_number",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_bacapp_window_size,
{ "Proposed Window Size", "bacapp.window_size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_bacapp_service,
{ "Service Choice", "bacapp.confirmed_service",
FT_UINT8, BASE_DEC, VALS(BACnetConfirmedServiceChoice), 0x00, NULL, HFILL }
},
{ &hf_bacapp_uservice,
{ "Unconfirmed Service Choice", "bacapp.unconfirmed_service",
FT_UINT8, BASE_DEC, VALS(BACnetUnconfirmedServiceChoice), 0x00, NULL, HFILL }
},
{ &hf_bacapp_NAK,
{ "NAK", "bacapp.NAK",
FT_BOOLEAN, 8, NULL, 0x02, "negative ACK", HFILL }
},
{ &hf_bacapp_SRV,
{ "SRV", "bacapp.SRV",
FT_BOOLEAN, 8, NULL, 0x01, "Server", HFILL }
},
{ &hf_Device_Instance_Range_Low_Limit,
{ "Device Instance Range Low Limit", "bacapp.who_is.low_limit",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_Device_Instance_Range_High_Limit,
{ "Device Instance Range High Limit", "bacapp.who_is.high_limit",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_BACnetRejectReason,
{ "Reject Reason", "bacapp.reject_reason",
FT_UINT8, BASE_DEC, VALS(BACnetRejectReason), 0x00, NULL, HFILL }
},
{ &hf_BACnetAbortReason,
{ "Abort Reason", "bacapp.abort_reason",
FT_UINT8, BASE_DEC, VALS(BACnetAbortReason), 0x00, NULL, HFILL }
},
{ &hf_BACnetApplicationTagNumber,
{ "Application Tag Number",
"bacapp.application_tag_number",
FT_UINT8, BASE_DEC, VALS(BACnetApplicationTagNumber), 0xF0,
NULL, HFILL }
},
{ &hf_BACnetContextTagNumber,
{ "Context Tag Number",
"bacapp.context_tag_number",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_BACnetExtendedTagNumber,
{ "Extended Tag Number",
"bacapp.extended_tag_number",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_BACnetNamedTag,
{ "Named Tag",
"bacapp.named_tag",
FT_UINT8, BASE_DEC, VALS(BACnetTagNames), 0x07,
NULL, HFILL }
},
{ &hf_BACnetCharacterSet,
{ "String Character Set",
"bacapp.string_character_set",
FT_UINT8, BASE_DEC, VALS(BACnetCharacterSet), 0,
NULL, HFILL }
},
{ &hf_BACnetTagClass,
{ "Tag Class", "bacapp.tag_class",
FT_BOOLEAN, 8, TFS(&BACnetTagClass), 0x08, NULL, HFILL }
},
{ &hf_bacapp_tag_lvt,
{ "Length Value Type",
"bacapp.LVT",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_bacapp_tag_ProcessId,
{ "ProcessIdentifier", "bacapp.processId",
FT_UINT32, BASE_DEC, NULL, 0, "Process Identifier", HFILL }
},
{ &hf_bacapp_tag_IPV4,
{ "IPV4", "bacapp.IPV4",
FT_IPv4, BASE_NONE, NULL, 0, "IP-Address", HFILL }
},
{ &hf_bacapp_tag_IPV6,
{ "IPV6", "bacapp.IPV6",
FT_IPv6, BASE_NONE, NULL, 0, "IP-Address", HFILL }
},
{ &hf_bacapp_tag_PORT,
{ "Port", "bacapp.Port",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{&hf_msg_fragments,
{"Message fragments", "bacapp.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment,
{"Message fragment", "bacapp.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_overlap,
{"Message fragment overlap", "bacapp.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"bacapp.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_multiple_tails,
{"Message has multiple tail fragments",
"bacapp.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_too_long_fragment,
{"Message fragment too long", "bacapp.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_error,
{"Message defragmentation error", "bacapp.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_fragment_count,
{"Message fragment count", "bacapp.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } },
{&hf_msg_reassembled_in,
{"Reassembled in", "bacapp.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL } },
{&hf_msg_reassembled_length,
{"Reassembled BACapp length", "bacapp.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL } }
};
static gint *ett[] = {
&ett_bacapp,
&ett_bacapp_control,
&ett_bacapp_tag,
&ett_bacapp_list,
&ett_bacapp_value,
&ett_msg_fragment,
&ett_msg_fragments
};
static ei_register_info ei[] = {
{ &ei_bacapp_bad_length, { "bacapp.bad_length", PI_MALFORMED, PI_ERROR, "Wrong length indicated", EXPFILL }},
};
expert_module_t* expert_bacapp;
proto_bacapp = proto_register_protocol("Building Automation and Control Network APDU",
"BACapp", "bacapp");
proto_register_field_array(proto_bacapp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_bacapp = expert_register_protocol(proto_bacapp);
expert_register_field_array(expert_bacapp, ei, array_length(ei));
register_dissector("bacapp", dissect_bacapp, proto_bacapp);
register_init_routine(&bacapp_init_routine);
bacapp_dissector_table = register_dissector_table("bacapp.vendor_identifier",
"BACapp Vendor Identifier",
FT_UINT8, BASE_HEX);
register_bacapp_stat_trees();
bacapp_tap = register_tap("bacapp");
}
void
proto_reg_handoff_bacapp(void)
{
data_handle = find_dissector("data");
}
