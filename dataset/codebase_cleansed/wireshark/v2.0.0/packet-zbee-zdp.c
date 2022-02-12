const gchar *
zdp_status_name(guint8 status)
{
return val_to_str_const(status, zbee_zdp_status_names, "Reserved");
}
static guint16
zdp_convert_2003cluster(guint8 cluster)
{
guint16 cluster16 = (guint16)cluster;
if (cluster16 & ZBEE_ZDP_MSG_RESPONSE_BIT_2003) {
cluster16 &= ~(ZBEE_ZDP_MSG_RESPONSE_BIT_2003);
cluster16 |= (ZBEE_ZDP_MSG_RESPONSE_BIT);
}
return cluster16;
}
void
zdp_dump_excess(tvbuff_t *tvb, guint offset, packet_info *pinfo, proto_tree *tree)
{
proto_tree *root = proto_tree_get_root(tree);
guint length = tvb_captured_length_remaining(tvb, offset);
tvbuff_t *excess;
if (length > 0) {
excess = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, excess, pinfo, root);
}
}
void
zbee_append_info(proto_item *item, packet_info *pinfo, const gchar *format, ...)
{
static gchar buffer[512];
va_list ap;
va_start(ap, format);
g_vsnprintf(buffer, 512, format, ap);
va_end(ap);
if (item) {
proto_item_append_text(item, "%s", buffer);
}
col_append_str(pinfo->cinfo, COL_INFO, buffer);
}
guint
zbee_parse_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint *offset, guint length, proto_item **ti)
{
proto_item *item = NULL;
guint value = 0;
if (length == 0) {
return 0;
}
else if (length == 1) {
value = tvb_get_guint8(tvb, *offset);
}
else if (length == 2) {
value = tvb_get_letohs(tvb, *offset);
}
else if (length == 3) {
value = tvb_get_letohs(tvb, *offset);
value += ((guint32)tvb_get_guint8(tvb, *offset + 2) << 16);
}
else {
value = tvb_get_letohl(tvb, *offset);
}
if (tree) {
item = proto_tree_add_uint(tree, hfindex, tvb, *offset, length, value);
}
*offset += length;
if (ti) *ti = item;
return value;
}
guint64
zbee_parse_eui64(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint *offset, guint length, proto_item **ti)
{
proto_item *item = NULL;
guint64 value;
value = tvb_get_letoh64(tvb, *offset);
if (tree) {
item = proto_tree_add_eui64(tree, hfindex, tvb, *offset, length, value);
}
*offset += (int)sizeof(guint64);
if (ti) *ti = item;
return value;
}
guint8
zdp_parse_status(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
guint8 status;
status = tvb_get_guint8(tvb, *offset);
if (tree) {
proto_tree_add_uint(tree, hf_zbee_zdp_status, tvb, *offset, (int)sizeof(guint8), status);
}
*offset += (int)sizeof(guint8);
return status;
}
guint32
zdp_parse_chanmask(proto_tree *tree, tvbuff_t *tvb, guint *offset, int hf_channel)
{
int i;
guint32 mask;
proto_item *ti;
mask = tvb_get_letohl(tvb, *offset);
if (tree) {
ti = proto_tree_add_uint_format(tree, hf_channel, tvb, *offset, 4, mask, "Channels: ");
if (mask==0) {
proto_item_append_text(ti, "None");
}
for (i=0; i<(8*(int)(int)sizeof(guint32)); i++) {
if ((1<<i) & mask) {
proto_item_append_text(ti, "%d", i++);
break;
}
}
for (;i<(8*(int)(int)sizeof(guint32)); i++) {
if (!((1<<i) & mask)) {
continue;
}
if ( ! ((1<<(i-1)) & mask) ) {
proto_item_append_text(ti, ", %d", i);
}
if ((2<<i) & mask) {
while ((2<<i) & mask) i++;
proto_item_append_text(ti, "-%d", i);
}
}
}
*offset += (int)sizeof(guint32);
return mask;
}
guint8
zdp_parse_cinfo(proto_tree *tree, gint ettindex, tvbuff_t *tvb, guint *offset)
{
guint8 flags;
static const int * cinfo[] = {
&hf_zbee_zdp_cinfo_alt_coord,
&hf_zbee_zdp_cinfo_ffd,
&hf_zbee_zdp_cinfo_power,
&hf_zbee_zdp_cinfo_idle_rx,
&hf_zbee_zdp_cinfo_security,
&hf_zbee_zdp_cinfo_alloc,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, *offset, hf_zbee_zdp_cinfo, ettindex, cinfo, ENC_NA, BMT_NO_APPEND);
flags = tvb_get_guint8(tvb, *offset);
*offset += 1;
return flags;
}
guint16
zdp_parse_server_flags(proto_tree *tree, gint ettindex, tvbuff_t *tvb, guint *offset)
{
guint16 flags;
static const int * server_flags[] = {
&hf_zbee_zdp_server_pri_trust,
&hf_zbee_zdp_server_bak_trust,
&hf_zbee_zdp_server_pri_bind,
&hf_zbee_zdp_server_bak_bind,
&hf_zbee_zdp_server_pri_disc,
&hf_zbee_zdp_server_bak_disc,
NULL
};
flags = tvb_get_letohs(tvb, *offset);
proto_tree_add_bitmask_with_flags(tree, tvb, *offset, hf_zbee_zdp_server, ettindex, server_flags, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
*offset += 2;
return flags;
}
void
zdp_parse_node_desc(proto_tree *tree, gint ettindex, tvbuff_t *tvb, guint *offset, guint8 version)
{
proto_item *ti;
proto_item *field_root = NULL;
proto_tree *field_tree = NULL;
guint16 flags;
static const int * nodes[] = {
&hf_zbee_zdp_node_complex,
&hf_zbee_zdp_node_user,
&hf_zbee_zdp_node_freq_868,
&hf_zbee_zdp_node_freq_900,
&hf_zbee_zdp_node_freq_2400,
NULL
};
if ((tree) && (ettindex != -1)) {
field_tree = proto_tree_add_subtree(tree, tvb, *offset, -1, ettindex, &field_root, "Node Descriptor");
}
else
field_tree = tree;
flags = tvb_get_letohs(tvb, *offset);
if (tree) {
guint16 type = flags & ZBEE_ZDP_NODE_TYPE;
ti = proto_tree_add_uint(field_tree, hf_zbee_zdp_node_type, tvb, *offset, 2, type);
proto_tree_add_bitmask_list(field_tree, tvb, *offset, 2, nodes, ENC_LITTLE_ENDIAN);
if (type == ZBEE_ZDP_NODE_TYPE_COORD) proto_item_append_text(ti, " (Coordinator)");
else if (type == ZBEE_ZDP_NODE_TYPE_FFD) proto_item_append_text(ti, " (Router)");
else if (type == ZBEE_ZDP_NODE_TYPE_RFD) proto_item_append_text(ti, " (End Device)");
else proto_item_append_text(ti, " (Reserved)");
}
*offset += 2;
zdp_parse_cinfo(field_tree, ett_zbee_zdp_cinfo, tvb, offset);
zbee_parse_uint(field_tree, hf_zbee_zdp_node_manufacturer, tvb, offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(field_tree, hf_zbee_zdp_node_max_buffer, tvb, offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(field_tree, hf_zbee_zdp_node_max_incoming_transfer, tvb, offset, 2, NULL);
if (version >= ZBEE_VERSION_2007) {
const int * descriptors[] = {
&hf_zbee_zdp_dcf_eaela,
&hf_zbee_zdp_dcf_esdla,
NULL
};
zdp_parse_server_flags(field_tree, ett_zbee_zdp_server, tvb, offset);
zbee_parse_uint(field_tree, hf_zbee_zdp_node_max_outgoing_transfer, tvb, offset, 2, NULL);
proto_tree_add_bitmask_with_flags(field_tree, tvb, *offset, hf_zbee_zdp_dcf, ett_zbee_zdp_descriptor_capability_field, descriptors, ENC_NA, BMT_NO_APPEND);
*offset += 1;
}
if (tree && (ettindex != -1)) {
proto_item_set_len(field_root, *offset);
}
}
void
zdp_parse_power_desc(proto_tree *tree, gint ettindex, tvbuff_t *tvb, guint *offset)
{
static const int * power_desc[] = {
&hf_zbee_zdp_power_mode,
&hf_zbee_zdp_power_avail_ac,
&hf_zbee_zdp_power_avail_recharge,
&hf_zbee_zdp_power_avail_dispose,
&hf_zbee_zdp_power_source_ac,
&hf_zbee_zdp_power_source_recharge,
&hf_zbee_zdp_power_source_dispose,
&hf_zbee_zdp_power_level,
NULL
};
proto_tree_add_bitmask_with_flags(tree, tvb, *offset, hf_zbee_zdp_power, ettindex, power_desc, ENC_LITTLE_ENDIAN, BMT_NO_APPEND);
*offset += 2;
}
void
zdp_parse_simple_desc(proto_tree *tree, gint ettindex, tvbuff_t *tvb, guint *offset, guint8 version)
{
proto_item *field_root = NULL;
proto_tree *field_tree = NULL, *cluster_tree = NULL;
guint i, sizeof_cluster;
guint8 in_count;
guint8 out_count;
if ((tree) && (ettindex != -1)) {
field_tree = proto_tree_add_subtree(tree, tvb, *offset, -1, ettindex, &field_root, "Simple Descriptor");
}
else field_tree = tree;
zbee_parse_uint(field_tree, hf_zbee_zdp_endpoint, tvb, offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(field_tree, hf_zbee_zdp_profile, tvb, offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(field_tree, hf_zbee_zdp_simple_app_device, tvb, offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(field_tree, hf_zbee_zdp_simple_app_version, tvb, offset, (int)sizeof(guint8), NULL);
sizeof_cluster = (version >= ZBEE_VERSION_2007)?(int)sizeof(guint16):(int)sizeof(guint8);
in_count = zbee_parse_uint(field_tree, hf_zbee_zdp_in_count, tvb, offset, (int)sizeof(guint8), NULL);
if ((tree) && (in_count)) {
cluster_tree = proto_tree_add_subtree(field_tree, tvb, *offset, in_count*sizeof_cluster,
ett_zbee_zdp_node_in, NULL, "Input Cluster List");
}
for (i=0; i<in_count && tvb_bytes_exist(tvb, *offset, sizeof_cluster); i++) {
zbee_parse_uint(cluster_tree, hf_zbee_zdp_in_cluster, tvb, offset, sizeof_cluster, NULL);
}
out_count = zbee_parse_uint(field_tree, hf_zbee_zdp_out_count, tvb, offset, (int)sizeof(guint8), NULL);
if ((tree) && (out_count)) {
cluster_tree = proto_tree_add_subtree(field_tree, tvb, *offset, out_count*sizeof_cluster,
ett_zbee_zdp_node_out, NULL, "Output Cluster List");
}
for (i=0; (i<out_count) && tvb_bytes_exist(tvb, *offset, sizeof_cluster); i++) {
zbee_parse_uint(cluster_tree, hf_zbee_zdp_out_cluster, tvb, offset, sizeof_cluster, NULL);
}
if (tree && (ettindex != -1)) {
proto_item_set_len(field_root, *offset);
}
}
void
zdp_parse_complex_desc(proto_tree *tree, gint ettindex, tvbuff_t *tvb, guint *offset, guint length)
{
enum {
tag_charset = 1,
tag_mfr_name = 2,
tag_model_name = 3,
tag_serial_no = 4,
tag_url = 5,
tag_icon = 6,
tag_icon_url = 7
};
static const gchar *tag_name[] = {
"Reserved Tag",
"languageChar",
"manufacturerName",
"modelName",
"serialNumber",
"deviceURL",
"icon",
"outliner"
};
const gint max_len = 128;
proto_tree *field_tree;
gchar *str = (gchar *)wmem_alloc(wmem_packet_scope(), length);
gchar *complex = (gchar *)wmem_alloc(wmem_packet_scope(), max_len);
guint8 tag;
if ((tree) && (ettindex != -1)) {
field_tree = proto_tree_add_subtree(tree, tvb, *offset, length, ettindex, NULL, "Complex Descriptor");
}
else
field_tree = tree;
tag = tvb_get_guint8(tvb, *offset);
if (tag == tag_charset) {
gchar lang_str[3];
guint8 charset = tvb_get_guint8(tvb, *offset + 3);
const gchar *charset_str;
if (charset == 0x00) charset_str = "ASCII";
else charset_str = "Unknown Character Set";
lang_str[0] = tvb_get_guint8(tvb, *offset + 1);
lang_str[1] = tvb_get_guint8(tvb, *offset + 2);
lang_str[2] = '\0';
g_snprintf(complex, max_len, "<%s>%s, %s</%s>", tag_name[tag_charset], lang_str, charset_str, tag_name[tag_charset]);
}
else if (tag == tag_icon) {
g_snprintf(complex, max_len, "<%s>FixMe</%s>", tag_name[tag_icon], tag_name[tag_icon]);
}
else {
tvb_memcpy(tvb, str, *offset+1, length-1);
str[length-1] = '\0';
if (tag <= tag_icon_url) {
g_snprintf(complex, max_len, "<%s>%s</%s>", tag_name[tag], str, tag_name[tag]);
}
else {
g_snprintf(complex, max_len, "<%s>%s</%s>", tag_name[0], str, tag_name[0]);
}
}
if (tree) {
proto_tree_add_string(field_tree, hf_zbee_zdp_complex, tvb, *offset, length, complex);
}
*offset += (length);
}
static int
dissect_zbee_zdp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_tree *zdp_tree;
proto_item *proto_root;
tvbuff_t *zdp_tvb;
guint8 seqno;
guint16 cluster;
guint offset = 0;
zbee_nwk_packet *nwk;
if (data == NULL)
return 0;
nwk = (zbee_nwk_packet *)data;
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_zdp, tvb, offset, tvb_captured_length(tvb), "ZigBee Device Profile");
zdp_tree = proto_item_add_subtree(proto_root, ett_zbee_zdp);
#if 0
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee ZDP");
#endif
seqno = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(zdp_tree, hf_zbee_zdp_seqno, tvb, offset, (int)sizeof(guint8), seqno);
offset += (int)sizeof(guint8);
if (nwk->version <= ZBEE_VERSION_2004) {
cluster = zdp_convert_2003cluster((guint8)nwk->cluster_id);
}
else {
cluster = nwk->cluster_id;
}
proto_item_append_text(zdp_tree, ", %s", val_to_str_const(cluster, zbee_zdp_cluster_names, "Unknown Cluster"));
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(cluster, zbee_zdp_cluster_names, "Unknown Cluster"));
zdp_tvb = tvb_new_subset_remaining(tvb, offset);
switch (cluster) {
case ZBEE_ZDP_REQ_NWK_ADDR:
dissect_zbee_zdp_req_nwk_addr(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_IEEE_ADDR:
dissect_zbee_zdp_req_ext_addr(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_NODE_DESC:
dissect_zbee_zdp_req_node_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_POWER_DESC:
dissect_zbee_zdp_req_power_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_SIMPLE_DESC:
dissect_zbee_zdp_req_simple_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_ACTIVE_EP:
dissect_zbee_zdp_req_active_ep(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_MATCH_DESC:
dissect_zbee_zdp_req_match_desc(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_COMPLEX_DESC:
dissect_zbee_zdp_req_complex_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_USER_DESC:
dissect_zbee_zdp_req_user_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_DISCOVERY_CACHE:
dissect_zbee_zdp_req_discovery_cache(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_DEVICE_ANNCE:
dissect_zbee_zdp_device_annce(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_SET_USER_DESC:
dissect_zbee_zdp_req_set_user_desc(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_SYSTEM_SERVER_DISC:
dissect_zbee_zdp_req_system_server_disc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_STORE_DISCOVERY:
dissect_zbee_zdp_req_store_discovery(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_STORE_NODE_DESC:
dissect_zbee_zdp_req_store_node_desc(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_STORE_POWER_DESC:
dissect_zbee_zdp_req_store_power_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_STORE_ACTIVE_EP:
dissect_zbee_zdp_req_store_active_ep(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_STORE_SIMPLE_DESC:
dissect_zbee_zdp_req_store_simple_desc(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_REMOVE_NODE_CACHE:
dissect_zbee_zdp_req_remove_node_cache(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_FIND_NODE_CACHE:
dissect_zbee_zdp_req_find_node_cache(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_EXT_SIMPLE_DESC:
dissect_zbee_zdp_req_ext_simple_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_EXT_ACTIVE_EP:
dissect_zbee_zdp_req_ext_active_ep(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_END_DEVICE_BIND:
dissect_zbee_zdp_req_end_device_bind(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_BIND:
dissect_zbee_zdp_req_bind(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_UNBIND:
dissect_zbee_zdp_req_unbind(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_BIND_REGISTER:
dissect_zbee_zdp_req_bind_register(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_REPLACE_DEVICE:
dissect_zbee_zdp_req_replace_device(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_STORE_BAK_BIND_ENTRY:
dissect_zbee_zdp_req_store_bak_bind_entry(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_REMOVE_BAK_BIND_ENTRY:
dissect_zbee_zdp_req_remove_bak_bind_entry(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_BACKUP_BIND_TABLE:
dissect_zbee_zdp_req_backup_bind_table(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_RECOVER_BIND_TABLE:
dissect_zbee_zdp_req_recover_bind_table(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_BACKUP_SOURCE_BIND:
dissect_zbee_zdp_req_backup_source_bind(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_RECOVER_SOURCE_BIND:
dissect_zbee_zdp_req_recover_source_bind(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_MGMT_NWK_DISC:
dissect_zbee_zdp_req_mgmt_nwk_disc(zdp_tvb, pinfo, zdp_tree, hf_zbee_zdp_scan_channel);
break;
case ZBEE_ZDP_REQ_MGMT_LQI:
dissect_zbee_zdp_req_mgmt_lqi(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_MGMT_RTG:
dissect_zbee_zdp_req_mgmt_rtg(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_MGMT_BIND:
dissect_zbee_zdp_req_mgmt_bind(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_MGMT_LEAVE:
dissect_zbee_zdp_req_mgmt_leave(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_REQ_MGMT_DIRECT_JOIN:
dissect_zbee_zdp_req_mgmt_direct_join(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_MGMT_PERMIT_JOIN:
dissect_zbee_zdp_req_mgmt_permit_join(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_MGMT_CACHE:
dissect_zbee_zdp_req_mgmt_cache(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_REQ_MGMT_NWKUPDATE:
dissect_zbee_zdp_req_mgmt_nwkupdate(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_NWK_ADDR:
dissect_zbee_zdp_rsp_nwk_addr(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_IEEE_ADDR:
dissect_zbee_zdp_rsp_ext_addr(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_NODE_DESC:
dissect_zbee_zdp_rsp_node_desc(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_POWER_DESC:
dissect_zbee_zdp_rsp_power_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_SIMPLE_DESC:
dissect_zbee_zdp_rsp_simple_desc(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_ACTIVE_EP:
dissect_zbee_zdp_rsp_active_ep(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_MATCH_DESC:
dissect_zbee_zdp_rsp_match_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_COMPLEX_DESC:
dissect_zbee_zdp_rsp_complex_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_USER_DESC:
dissect_zbee_zdp_rsp_user_desc(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_DISCOVERY_CACHE:
dissect_zbee_zdp_rsp_discovery_cache(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_CONF_USER_DESC:
dissect_zbee_zdp_rsp_user_desc_conf(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_SYSTEM_SERVER_DISC:
dissect_zbee_zdp_rsp_system_server_disc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_STORE_DISCOVERY:
dissect_zbee_zdp_rsp_discovery_store(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_STORE_NODE_DESC:
dissect_zbee_zdp_rsp_store_node_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_STORE_POWER_DESC:
dissect_zbee_zdp_rsp_store_power_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_STORE_ACTIVE_EP:
dissect_zbee_zdp_rsp_store_active_ep(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_STORE_SIMPLE_DESC:
dissect_zbee_zdp_rsp_store_simple_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_REMOVE_NODE_CACHE:
dissect_zbee_zdp_rsp_remove_node_cache(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_FIND_NODE_CACHE:
dissect_zbee_zdp_rsp_find_node_cache(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_EXT_SIMPLE_DESC:
dissect_zbee_zdp_rsp_ext_simple_desc(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_EXT_ACTIVE_EP:
dissect_zbee_zdp_rsp_ext_active_ep(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_END_DEVICE_BIND:
dissect_zbee_zdp_rsp_end_device_bind(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_BIND:
dissect_zbee_zdp_rsp_bind(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_UNBIND:
dissect_zbee_zdp_rsp_unbind(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_BIND_REGISTER:
dissect_zbee_zdp_rsp_bind_register(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_REPLACE_DEVICE:
dissect_zbee_zdp_rsp_replace_device(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_STORE_BAK_BIND_ENTRY:
dissect_zbee_zdp_rsp_store_bak_bind_entry(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_REMOVE_BAK_BIND_ENTRY:
dissect_zbee_zdp_rsp_remove_bak_bind_entry(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_BACKUP_BIND_TABLE:
dissect_zbee_zdp_rsp_backup_bind_table(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_RECOVER_BIND_TABLE:
dissect_zbee_zdp_rsp_recover_bind_table(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_BACKUP_SOURCE_BIND:
dissect_zbee_zdp_rsp_backup_source_bind(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_RECOVER_SOURCE_BIND:
dissect_zbee_zdp_rsp_recover_source_bind(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_MGMT_NWK_DISC:
dissect_zbee_zdp_rsp_mgmt_nwk_disc(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_MGMT_LQI:
dissect_zbee_zdp_rsp_mgmt_lqi(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_MGMT_RTG:
dissect_zbee_zdp_rsp_mgmt_rtg(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_MGMT_BIND:
dissect_zbee_zdp_rsp_mgmt_bind(zdp_tvb, pinfo, zdp_tree, nwk->version);
break;
case ZBEE_ZDP_RSP_MGMT_LEAVE:
dissect_zbee_zdp_rsp_mgmt_leave(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_MGMT_DIRECT_JOIN:
dissect_zbee_zdp_rsp_mgmt_direct_join(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_MGMT_PERMIT_JOIN:
dissect_zbee_zdp_rsp_mgmt_permit_join(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_MGMT_CACHE:
dissect_zbee_zdp_rsp_mgmt_cache(zdp_tvb, pinfo, zdp_tree);
break;
case ZBEE_ZDP_RSP_MGMT_NWKUPDATE:
dissect_zbee_zdp_rsp_mgmt_nwkupdate(zdp_tvb, pinfo, zdp_tree);
break;
default:
call_dissector(data_handle, zdp_tvb, pinfo, tree);
break;
}
return tvb_captured_length(tvb);
}
void proto_register_zbee_zdp(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zdp_seqno,
{ "Sequence Number", "zbee_zdp.seqno", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_zbee_zdp_length,
{ "Length", "zbee_zdp.length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_zbee_zdp_ext_addr,
{ "Extended Address", "zbee_zdp.ext_addr", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_device,
{ "Device", "zbee_zdp.device", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_req_type,
{ "Request Type", "zbee_zdp.req_type", FT_UINT8, BASE_DEC, VALS(zbee_zdp_req_types), 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_index,
{ "Index", "zbee_zdp.index", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_status,
{ "Status", "zbee_zdp.status", FT_UINT8, BASE_DEC, VALS(zbee_zdp_status_names), 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_endpoint,
{ "Endpoint", "zbee_zdp.endpoint", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_ep_count,
{ "Endpoint Count", "zbee_zdp.ep_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_profile,
{ "Profile", "zbee_zdp.profile", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_addr_mode,
{ "Address Mode", "zbee_zdp.addr_mode", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_cluster,
{ "Cluster", "zbee_zdp.cluster", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_table_size,
{ "Table Size", "zbee_zdp.table_size", FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of entries in the table.", HFILL }},
{ &hf_zbee_zdp_table_count,
{ "Table Count", "zbee_zdp.table_count", FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of table entries included in this message.", HFILL }},
{ &hf_zbee_zdp_cache_address,
{ "Cache Address", "zbee_zdp.cache_address", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_in_count,
{ "Input Cluster Count", "zbee_zdp.in_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_out_count,
{ "Output Cluster Count", "zbee_zdp.out_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_in_cluster,
{ "Input Cluster", "zbee_zdp.in_cluster", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_out_cluster,
{ "Output Cluster", "zbee_zdp.out_cluster", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_assoc_device_count,
{ "Associated Device Count", "zbee_zdp.assoc_device_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_assoc_device,
{ "Associated Device", "zbee_zdp.assoc_device", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_cinfo,
{ "Capability Information", "zbee_zdp.cinfo", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_cinfo_alt_coord,
{ "Alternate Coordinator", "zbee_zdp.cinfo.alt_coord", FT_BOOLEAN, 8, NULL, ZBEE_CINFO_ALT_COORD,
"Indicates that the device is able to operate as a PAN coordinator.", HFILL }},
{ &hf_zbee_zdp_cinfo_ffd,
{ "Full-Function Device", "zbee_zdp.cinfo.ffd", FT_BOOLEAN, 8, NULL, ZBEE_CINFO_FFD,
NULL, HFILL }},
{ &hf_zbee_zdp_cinfo_power,
{ "AC Power", "zbee_zdp.cinfo.power", FT_BOOLEAN, 8, NULL, ZBEE_CINFO_POWER,
"Indicates this device is using AC/Mains power.", HFILL }},
{ &hf_zbee_zdp_cinfo_idle_rx,
{ "Rx On When Idle", "zbee_zdp.cinfo.power", FT_BOOLEAN, 8, NULL, ZBEE_CINFO_IDLE_RX,
"Indicates the receiver is active when the device is idle.", HFILL }},
{ &hf_zbee_zdp_cinfo_security,
{ "Security Capability", "zbee_zdp.cinfo.security", FT_BOOLEAN, 8, NULL, ZBEE_CINFO_SECURITY,
"Indicates this device is capable of performing encryption/decryption.", HFILL }},
{ &hf_zbee_zdp_cinfo_alloc,
{ "Allocate Short Address", "zbee_zdp.cinfo.alloc", FT_BOOLEAN, 8, NULL, ZBEE_CINFO_ALLOC,
"Flag requesting the parent to allocate a short address for this device.", HFILL }},
{ &hf_zbee_zdp_dcf,
{ "Descriptor Capability Field", "zbee_zdp.dcf", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_zbee_zdp_dcf_eaela,
{ "Extended Active Endpoint List Available", "zbee_zdp.dcf.eaela", FT_BOOLEAN, 8, NULL, ZBEE_ZDP_DCF_EAELA,
NULL, HFILL }},
{ &hf_zbee_zdp_dcf_esdla,
{ "Extended Simple Descriptor List Available", "zbee_zdp.dcf.esdla", FT_BOOLEAN, 8, NULL, ZBEE_ZDP_DCF_ESDLA,
NULL, HFILL }},
{ &hf_zbee_zdp_server,
{ "Server Flags", "zbee_zdp.server", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_server_pri_trust,
{ "Primary Trust Center", "zbee_zdp.server.pri_trust", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_SERVER_PRIMARY_TRUST,
NULL, HFILL }},
{ &hf_zbee_zdp_server_bak_trust,
{ "Backup Trust Center", "zbee_zdp.server.bak_trust", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_SERVER_BACKUP_TRUST,
NULL, HFILL }},
{ &hf_zbee_zdp_server_pri_bind,
{ "Primary Binding Table Cache","zbee_zdp.server.pri_bind", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_SERVER_PRIMARY_BIND,
NULL, HFILL }},
{ &hf_zbee_zdp_server_bak_bind,
{ "Backup Binding Table Cache", "zbee_zdp.server.bak_bind", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_SERVER_BACKUP_BIND,
NULL, HFILL }},
{ &hf_zbee_zdp_server_pri_disc,
{ "Primary Discovery Cache", "zbee_zdp.server.pri_disc", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_SERVER_PRIMARY_DISC,
NULL, HFILL }},
{ &hf_zbee_zdp_server_bak_disc,
{ "Backup Discovery Cache", "zbee_zdp.server.bak_bind", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_SERVER_BACKUP_DISC,
NULL, HFILL }},
{ &hf_zbee_zdp_node_type,
{ "Type", "zbee_zdp.node.type", FT_UINT16, BASE_DEC, NULL, ZBEE_ZDP_NODE_TYPE,
NULL, HFILL }},
{ &hf_zbee_zdp_node_complex,
{ "Complex Descriptor", "zbee_zdp.node.complex", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_COMPLEX,
NULL, HFILL }},
{ &hf_zbee_zdp_node_user,
{ "User Descriptor", "zbee_zdp.node.user", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_USER,
NULL, HFILL }},
{ &hf_zbee_zdp_node_freq_868,
{ "868MHz Band", "zbee_zdp.node.freq.868mhz", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_FREQ_868MHZ,
NULL, HFILL }},
{ &hf_zbee_zdp_node_freq_900,
{ "900MHz Band", "zbee_zdp.node.freq.900mhz", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_FREQ_900MHZ,
NULL, HFILL }},
{ &hf_zbee_zdp_node_freq_2400,
{ "2.4GHz Band", "zbee_zdp.node.freq.2400mhz", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_NODE_FREQ_2400MHZ,
NULL, HFILL }},
{ &hf_zbee_zdp_node_manufacturer,
{ "Manufacturer Code", "zbee_zdp.node.manufacturer", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_node_max_buffer,
{ "Max Buffer Size", "zbee_zdp.node.max_buffer", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_node_max_incoming_transfer,
{ "Max Incoming Transfer Size", "zbee_zdp.node.max_incoming_transfer", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_node_max_outgoing_transfer,
{ "Max Outgoing Transfer Size", "zbee_zdp.node.max_outgoing_transfer", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_power,
{ "Power Descriptor", "zbee_zdp.power", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_power_mode,
{ "Mode", "zbee_zdp.power.mode", FT_UINT16, BASE_DEC, VALS(zbee_zdp_power_mode_vals), ZBEE_ZDP_POWER_MODE,
NULL, HFILL }},
{ &hf_zbee_zdp_power_avail_ac,
{ "Available AC Power", "zbee_zdp.power.avail.ac", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_POWER_AVAIL_AC,
NULL, HFILL }},
{ &hf_zbee_zdp_power_avail_recharge,
{ "Available Rechargeable Battery", "zbee_zdp.power.avail.rech", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_POWER_AVAIL_RECHARGEABLE,
NULL, HFILL }},
{ &hf_zbee_zdp_power_avail_dispose,
{ "Available Disposeable Battery", "zbee_zdp.power.avail.disp", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_POWER_AVAIL_DISPOSEABLE,
NULL, HFILL }},
{ &hf_zbee_zdp_power_source_ac,
{ "Using AC Power", "zbee_zdp.power.source.ac", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_POWER_SOURCE_AC,
NULL, HFILL }},
{ &hf_zbee_zdp_power_source_recharge,
{ "Using Rechargeable Battery", "zbee_zdp.power.source.ac", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_POWER_SOURCE_RECHARGEABLE,
NULL, HFILL }},
{ &hf_zbee_zdp_power_source_dispose,
{ "Using Disposeable Battery", "zbee_zdp.power.source.ac", FT_BOOLEAN, 16, NULL, ZBEE_ZDP_POWER_SOURCE_DISPOSEABLE,
NULL, HFILL }},
{ &hf_zbee_zdp_power_level,
{ "Level", "zbee_zdp.power.level", FT_UINT16, BASE_DEC, VALS(zbee_zdp_power_level_vals), ZBEE_ZDP_POWER_LEVEL,
NULL, HFILL }},
{ &hf_zbee_zdp_simple_app_device,
{ "Application Device", "zbee_zdp.app.device", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_simple_app_version,
{ "Application Version", "zbee_zdp.app.version", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_complex_length,
{ "Complex Descriptor Length", "zbee_zdp.complex_length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_complex,
{ "Complex Descriptor", "zbee_zdp.complex", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_user,
{ "User Descriptor", "zbee_zdp.user", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_user_length,
{ "User Descriptor Length", "zbee_zdp.user_length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_simple_length,
{ "Simple Descriptor Length", "zbee_zdp.simple_length", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_disc_node_size,
{ "Node Descriptor Size", "zbee_zdp.node_size", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_disc_power_size,
{ "Power Descriptor Size", "zbee_zdp.power_size", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_cache,
{ "Cache", "zbee_zdp.cache", FT_UINT16, BASE_HEX, NULL, 0x0,
"Address of the device containing the discovery cache.", HFILL }},
{ &hf_zbee_zdp_disc_ep_count,
{ "Active Endpoint Count", "zbee_zdp.ep_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_disc_simple_count,
{ "Simple Descriptor Count", "zbee_zdp.simple_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_disc_simple_size,
{ "Simple Descriptor Size", "zbee_zdp.simple_size", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_target,
{ "Target", "zbee_zdp.target", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_replacement,
{ "Replacement", "zbee_zdp.replacement", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_replacement_ep,
{ "Replacement Endpoint", "zbee_zdp.replacement_ep", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_bind_src,
{ "Source", "zbee_zdp.bind.src", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_bind_src64,
{ "Source", "zbee_zdp.bind.src64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_bind_src_ep,
{ "Source Endpoint", "zbee_zdp.bind.src_ep", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_bind_dst,
{ "Destination", "zbee_zdp.bind.dst", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_bind_dst64,
{ "Destination", "zbee_zdp.bind.dst64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_bind_dst_ep,
{ "Destination Endpoint", "zbee_zdp.bind.dst_ep", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_duration,
{ "Duration", "zbee_zdp.duration", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_leave_children,
{ "Remove Children", "zbee_zdp.leave.children", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_leave_rejoin,
{ "Rejoin", "zbee_zdp.leave.rejoin", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_significance,
{ "Significance", "zbee_zdp.significance", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_scan_count,
{ "Scan Count", "zbee_zdp.scan_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_update_id,
{ "Update ID", "zbee_zdp.update_id", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_manager,
{ "Network Manager", "zbee_zdp.manager", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_tx_total,
{ "Total Transmissions", "zbee_zdp.tx_total", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_tx_fail,
{ "Failed Transmissions", "zbee_zdp.tx_fail", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_channel_count,
{ "Channel List Count", "zbee_zdp.channel_count", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_channel_mask,
{ "Channels", "zbee_zdp.channel_mask", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_channel_energy,
{ "Channel Energy", "zbee_zdp.channel_energy", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_pan_eui64,
{ "Pan", "zbee_zdp.pan.eui64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_pan_uint,
{ "Pan", "zbee_zdp.pan.uint", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_channel,
{ "Channel", "zbee_zdp.channel", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_nwk_desc_profile,
{ "Profile", "zbee_zdp.profile", FT_UINT8, BASE_HEX, NULL, 0x0F,
NULL, HFILL }},
{ &hf_zbee_zdp_profile_version,
{ "Version", "zbee_zdp.profile_version", FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{ &hf_zbee_zdp_beacon,
{ "Beacon Order", "zbee_zdp.beacon", FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{ &hf_zbee_zdp_superframe,
{ "Superframe Order", "zbee_zdp.superframe", FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{ &hf_zbee_zdp_permit_joining,
{ "Permit Joining", "zbee_zdp.permit_joining", FT_UINT8, BASE_DEC, VALS(zbee_zdp_true_false_plus_vals), 0x01,
NULL, HFILL }},
{ &hf_zbee_zdp_permit_joining_03,
{ "Permit Joining", "zbee_zdp.permit_joining", FT_UINT8, BASE_DEC, VALS(zbee_zdp_true_false_plus_vals), 0x03,
NULL, HFILL }},
{ &hf_zbee_zdp_extended_pan,
{ "Extended Pan", "zbee_zdp.extended_pan", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_addr,
{ "Addr", "zbee_zdp.addr", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_depth,
{ "Depth", "zbee_zdp.depth", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_lqi,
{ "LQI", "zbee_zdp.lqi", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_scan_channel,
{ "Scan Channels", "zbee_zdp.scan_channel", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_table_entry_type,
{ "Type", "zbee_zdp.table_entry_type", FT_UINT8, BASE_DEC, VALS(zbee_zdp_table_entry_type_vals), 0x03,
NULL, HFILL }},
{ &hf_zbee_zdp_table_entry_idle_rx_0c,
{ "Idle Rx", "zbee_zdp.idle_rx", FT_UINT8, BASE_DEC, VALS(zbee_zdp_true_false_plus_vals), 0x0c,
NULL, HFILL }},
{ &hf_zbee_zdp_table_entry_idle_rx_04,
{ "Idle Rx", "zbee_zdp.idle_rx", FT_UINT8, BASE_DEC, VALS(zbee_zdp_true_false_plus_vals), 0x04,
NULL, HFILL }},
{ &hf_zbee_zdp_table_entry_relationship_18,
{ "Relationship", "zbee_zdp.relationship", FT_UINT8, BASE_DEC, VALS(zbee_zdp_relationship_vals), 0x18,
NULL, HFILL }},
{ &hf_zbee_zdp_table_entry_relationship_70,
{ "Relationship", "zbee_zdp.relationship", FT_UINT8, BASE_DEC, VALS(zbee_zdp_relationship_vals), 0x70,
NULL, HFILL }},
{ &hf_zbee_zdp_rtg,
{ "Routing Table", "zbee_zdp.routing", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_rtg_entry,
{ "Routing Table Entry", "zbee_zdp.routing.entry", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_rtg_destination,
{ "Destination", "zbee_zdp.routing.destination", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_rtg_status,
{ "Status", "zbee_zdp.routing.status", FT_UINT8, BASE_DEC, VALS(zbee_zdp_rtg_status_vals), 0x0,
NULL, HFILL }},
{ &hf_zbee_zdp_rtg_next_hop,
{ "Next Hop", "zbee_zdp.routing.next_hop", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_zbee_zdp,
&ett_zbee_zdp_endpoint,
&ett_zbee_zdp_match_in,
&ett_zbee_zdp_match_out,
&ett_zbee_zdp_node,
&ett_zbee_zdp_node_in,
&ett_zbee_zdp_node_out,
&ett_zbee_zdp_power,
&ett_zbee_zdp_simple,
&ett_zbee_zdp_cinfo,
&ett_zbee_zdp_server,
&ett_zbee_zdp_simple_sizes,
&ett_zbee_zdp_bind,
&ett_zbee_zdp_bind_entry,
&ett_zbee_zdp_bind_end_in,
&ett_zbee_zdp_bind_end_out,
&ett_zbee_zdp_bind_table,
&ett_zbee_zdp_bind_source,
&ett_zbee_zdp_assoc_device,
&ett_zbee_zdp_nwk,
&ett_zbee_zdp_lqi,
&ett_zbee_zdp_rtg,
&ett_zbee_zdp_cache,
&ett_zbee_zdp_nwk_desc,
&ett_zbee_zdp_table_entry,
&ett_zbee_zdp_descriptor_capability_field,
};
proto_zbee_zdp = proto_register_protocol("ZigBee Device Profile", "ZigBee ZDP", "zbee_zdp");
proto_register_field_array(proto_zbee_zdp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("zbee_zdp", dissect_zbee_zdp, proto_zbee_zdp);
}
void proto_reg_handoff_zbee_zdp(void)
{
dissector_handle_t zdp_handle;
data_handle = find_dissector("data");
zdp_handle = find_dissector("zbee_zdp");
dissector_add_uint("zbee.profile", ZBEE_ZDP_PROFILE, zdp_handle);
}
