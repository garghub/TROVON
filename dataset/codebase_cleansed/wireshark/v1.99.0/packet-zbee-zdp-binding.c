void
zdp_parse_bind_table_entry(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint8 version)
{
proto_item *ti = NULL;
guint len = 0;
guint64 src64;
guint8 src_ep;
guint16 cluster;
guint8 mode;
guint64 dst64;
guint16 dst;
guint8 dst_ep;
src64 = tvb_get_letoh64(tvb, *offset + len);
if (tree) ti = proto_tree_add_text(tree, tvb, *offset, 0, "Bind {Src: %s", ep_eui64_to_display(src64));
len += (int)sizeof(guint64);
src_ep = tvb_get_guint8(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Src Endpoint: %d", src_ep);
len += (int)sizeof(guint8);
if (version >= ZBEE_VERSION_2007) {
cluster = tvb_get_letohs(tvb, *offset + len);
len += (int)sizeof(guint16);
}
else {
cluster = tvb_get_guint8(tvb, *offset + len);
len += (int)sizeof(guint8);
}
if (tree) proto_item_append_text(ti, ", Cluster: %d", cluster);
if (version >= ZBEE_VERSION_2007) {
mode = tvb_get_guint8(tvb, *offset + len);
len += (int)sizeof(guint8);
}
else {
mode = ZBEE_ZDP_ADDR_MODE_UNICAST;
}
if (mode == ZBEE_ZDP_ADDR_MODE_GROUP) {
dst = tvb_get_letohs(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Dst: 0x%04x}", dst);
len += (int)sizeof(guint16);
}
else if (mode == ZBEE_ZDP_ADDR_MODE_UNICAST) {
dst64 = tvb_get_letoh64(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Dst: %s", ep_eui64_to_display(dst64));
len += (int)sizeof(guint64);
dst_ep = tvb_get_guint8(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Dst Endpoint: %d}", dst_ep);
len += (int)sizeof(guint8);
}
else {
if (tree) proto_item_append_text(ti, "}");
}
if (tree) {
proto_item_set_len(ti, len);
}
*offset += len;
}
void
dissect_zbee_zdp_req_end_device_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
guint sizeof_cluster = (version >= ZBEE_VERSION_2007)?(int)sizeof(guint16):(int)sizeof(guint8);
guint i;
proto_tree *field_tree = NULL;
guint offset = 0;
guint16 target;
guint64 ext_addr = 0;
guint8 in_count;
guint8 out_count;
target = zbee_parse_uint(tree, hf_zbee_zdp_target, tvb, &offset, (guint)sizeof(guint16), NULL);
if (version >= ZBEE_VERSION_2007) {
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (guint)sizeof(guint64), NULL);
}
zbee_parse_uint(tree, hf_zbee_zdp_endpoint, tvb, &offset, (guint)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_profile, tvb, &offset, (guint)sizeof(guint16), NULL);
in_count = zbee_parse_uint(tree, hf_zbee_zdp_in_count, tvb, &offset, (guint)sizeof(guint8), NULL);
if ((tree) && (in_count)){
field_tree = proto_tree_add_subtree(tree, tvb, offset, (int)(in_count*sizeof_cluster),
ett_zbee_zdp_bind_end_in, NULL, "Input Cluster List");
}
for (i=0; i<in_count; i++) zbee_parse_uint(field_tree, hf_zbee_zdp_in_cluster, tvb, &offset, (guint)sizeof_cluster, NULL);
out_count = zbee_parse_uint(tree, hf_zbee_zdp_out_count, tvb, &offset, (guint)sizeof(guint8), NULL);
if ((tree) && (out_count)) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, (int)(out_count*sizeof_cluster),
ett_zbee_zdp_bind_end_out, NULL, "Output Cluster List");
}
for (i=0; i<out_count; i++) zbee_parse_uint(field_tree, hf_zbee_zdp_out_cluster, tvb, &offset, sizeof_cluster, NULL);
if (version >= ZBEE_VERSION_2007) {
zbee_append_info(tree, pinfo, " Src: %s", ep_eui64_to_display(ext_addr));
}
zbee_append_info(tree, pinfo, ", Target: 0x%04x", target);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
proto_item *ti;
guint offset = 0;
guint64 src64;
guint8 dst_mode;
guint16 dst = 0;
guint64 dst64 = 0;
src64 = zbee_parse_eui64(tree, hf_zbee_zdp_bind_src64, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_bind_src_ep, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_cluster, tvb, &offset, ZBEE_HAS_2006(version)?(int)sizeof(guint16):(int)sizeof(guint8), NULL);
if (version >= ZBEE_VERSION_2007) {
dst_mode = zbee_parse_uint(tree, hf_zbee_zdp_addr_mode, tvb, &offset, (int)sizeof(guint8), &ti);
if (tree) {
if (dst_mode == ZBEE_ZDP_ADDR_MODE_GROUP) proto_item_append_text(ti, " (Group)");
else if (dst_mode == ZBEE_ZDP_ADDR_MODE_UNICAST) proto_item_append_text(ti, " (Unicast)");
else proto_item_append_text(ti, " (Reserved)");
}
}
else {
dst_mode = ZBEE_ZDP_ADDR_MODE_UNICAST;
}
if (dst_mode == ZBEE_ZDP_ADDR_MODE_GROUP) {
dst = zbee_parse_uint(tree, hf_zbee_zdp_bind_dst, tvb, &offset, (int)sizeof(guint16), NULL);
}
else if (dst_mode == ZBEE_ZDP_ADDR_MODE_UNICAST) {
dst64 = zbee_parse_eui64(tree, hf_zbee_zdp_bind_dst64, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_bind_dst_ep, tvb, &offset, (int)sizeof(guint8), NULL);
}
if (version >= ZBEE_VERSION_2007) {
zbee_append_info(tree, pinfo, " Src: %s", ep_eui64_to_display(src64));
}
if (dst_mode == ZBEE_ZDP_ADDR_MODE_GROUP) {
zbee_append_info(tree, pinfo, ", Dst: 0x%04x", dst);
}
else {
zbee_append_info(tree, pinfo, ", Dst: %s", eui64_to_str(dst64));
}
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_unbind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
proto_item *ti;
guint offset = 0;
guint64 src64;
guint8 dst_mode;
guint16 dst = 0;
guint64 dst64 = 0;
src64 = zbee_parse_eui64(tree, hf_zbee_zdp_bind_src64, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_bind_src_ep, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_cluster, tvb, &offset, (version >= ZBEE_VERSION_2007)?(int)sizeof(guint16):(int)sizeof(guint8), NULL);
if (version >= ZBEE_VERSION_2007) {
dst_mode = zbee_parse_uint(tree, hf_zbee_zdp_addr_mode, tvb, &offset, (int)sizeof(guint8), &ti);
if (tree) {
if (dst_mode == ZBEE_ZDP_ADDR_MODE_GROUP) proto_item_append_text(ti, " (Group)");
else if (dst_mode == ZBEE_ZDP_ADDR_MODE_UNICAST) proto_item_append_text(ti, " (Unicast)");
else proto_item_append_text(ti, " (Reserved)");
}
}
else {
dst_mode = ZBEE_ZDP_ADDR_MODE_UNICAST;
}
if (dst_mode == ZBEE_ZDP_ADDR_MODE_GROUP) {
dst = zbee_parse_uint(tree, hf_zbee_zdp_bind_dst, tvb, &offset, (int)sizeof(guint16), NULL);
}
else if (dst_mode == ZBEE_ZDP_ADDR_MODE_UNICAST) {
dst64 = zbee_parse_eui64(tree, hf_zbee_zdp_bind_dst64, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_bind_dst_ep, tvb, &offset, (int)sizeof(guint8), NULL);
}
if (version >= ZBEE_VERSION_2007) {
zbee_append_info(tree, pinfo, " Src: %s", ep_eui64_to_display(src64));
}
if (dst_mode == ZBEE_ZDP_ADDR_MODE_GROUP) {
zbee_append_info(tree, pinfo, ", Dst: 0x%04x", dst);
}
else {
zbee_append_info(tree, pinfo, ", Dst: %s", eui64_to_str(dst64));
}
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_bind_register(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_append_info(tree, pinfo, ", Device: %s", ep_eui64_to_display(ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_replace_device(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
guint64 new_addr;
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_endpoint, tvb, &offset, (int)sizeof(guint8), NULL);
new_addr = zbee_parse_eui64(tree, hf_zbee_zdp_replacement, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_replacement_ep, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_append_info(tree, pinfo, ", Device: %s", ep_eui64_to_display(ext_addr));
zbee_append_info(tree, pinfo, ", Replacement: %s", ep_eui64_to_display(new_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_store_bak_bind_entry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
proto_item *ti;
guint offset = 0;
guint64 src64;
guint8 src_ep;
guint16 cluster;
guint8 dst_mode;
src64 = zbee_parse_eui64(tree, hf_zbee_zdp_bind_src64, tvb, &offset, (int)sizeof(guint64), NULL);
src_ep = zbee_parse_uint(tree, hf_zbee_zdp_bind_src_ep, tvb, &offset, (int)sizeof(guint8), NULL);
cluster = zbee_parse_uint(tree, hf_zbee_zdp_cluster, tvb, &offset, (version >= ZBEE_VERSION_2007)?(int)sizeof(guint16):(int)sizeof(guint8), NULL);
dst_mode = zbee_parse_uint(tree, hf_zbee_zdp_addr_mode, tvb, &offset, (int)sizeof(guint8), &ti);
if (dst_mode == ZBEE_ZDP_ADDR_MODE_GROUP) {
if (tree) proto_item_append_text(ti, " (Group)");
zbee_parse_uint(tree, hf_zbee_zdp_bind_dst, tvb, &offset, (int)sizeof(guint16), NULL);
}
else if (dst_mode == ZBEE_ZDP_ADDR_MODE_UNICAST) {
if (tree) proto_item_append_text(ti, " (Unicast)");
zbee_parse_eui64(tree, hf_zbee_zdp_bind_dst64, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_bind_dst_ep, tvb, &offset, (int)sizeof(guint8), NULL);
}
else if (tree) proto_item_append_text(ti, " (Reserved)");
zbee_append_info(tree, pinfo, ", Src: %s", ep_eui64_to_display(src64));
zbee_append_info(tree, pinfo, ", Src Endpoint: %d", src_ep);
zbee_append_info(tree, pinfo, ", Cluster: %d", cluster);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_remove_bak_bind_entry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
proto_item *ti;
guint offset = 0;
guint64 src64;
guint8 src_ep;
guint16 cluster;
guint8 dst_mode;
src64 = zbee_parse_eui64(tree, hf_zbee_zdp_bind_src64, tvb, &offset, (int)sizeof(guint64), NULL);
src_ep = zbee_parse_uint(tree, hf_zbee_zdp_bind_src_ep, tvb, &offset, (int)sizeof(guint8), NULL);
cluster = zbee_parse_uint(tree, hf_zbee_zdp_cluster, tvb, &offset, (version >= ZBEE_VERSION_2007)?(int)sizeof(guint16):(int)sizeof(guint8), NULL);
dst_mode = zbee_parse_uint(tree, hf_zbee_zdp_addr_mode, tvb, &offset, (int)sizeof(guint8), &ti);
if (dst_mode == ZBEE_ZDP_ADDR_MODE_GROUP) {
if (tree) proto_item_append_text(ti, " (Group)");
zbee_parse_uint(tree, hf_zbee_zdp_bind_dst, tvb, &offset, (int)sizeof(guint16), NULL);
}
else if (dst_mode == ZBEE_ZDP_ADDR_MODE_UNICAST) {
if (tree) proto_item_append_text(ti, " (Unicast)");
zbee_parse_eui64(tree, hf_zbee_zdp_bind_dst64, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_bind_dst_ep, tvb, &offset, (int)sizeof(guint8), NULL);
}
else if (tree) proto_item_append_text(ti, " (Reserved)");
zbee_append_info(tree, pinfo, ", Src: %s", ep_eui64_to_display(src64));
zbee_append_info(tree, pinfo, ", Src Endpoint: %d", src_ep);
zbee_append_info(tree, pinfo, ", Cluster: %d", cluster);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_backup_bind_table(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
proto_tree *field_tree;
guint i;
guint offset = 0;
guint16 table_count;
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint16), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint16), NULL);
field_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_zbee_zdp_bind, NULL, "Binding Table");
for (i=0; i<table_count; i++) {
zdp_parse_bind_table_entry(field_tree, tvb, &offset, version);
}
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_recover_bind_table(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint16), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_backup_source_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree;
guint i;
guint offset = 0;
guint16 count;
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint16), NULL);
count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint16), NULL);
field_tree = proto_tree_add_subtree(tree, tvb, offset, count*(int)sizeof(guint64),
ett_zbee_zdp_bind_source, NULL, "Source Table");
for (i=0; i<count; i++) zbee_parse_eui64(field_tree, hf_zbee_zdp_bind_src64, tvb, &offset, (int)sizeof(guint64), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_recover_source_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint16), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_end_device_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_unbind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_bind_register(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint16 table_count;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint16), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint16), NULL);
if (tree && table_count) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_zbee_zdp_bind, NULL, "Binding List");
}
for (i=0; i<table_count; i++) {
zdp_parse_bind_table_entry(field_tree, tvb, &offset, version);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_replace_device(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_store_bak_bind_entry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_remove_bak_bind_entry(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_backup_bind_table(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_recover_bind_table(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint16 table_count;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint16), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint16), NULL);
if (tree && table_count) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_zbee_zdp_bind, NULL, "Binding Table");
}
for (i=0; i<table_count; i++) {
zdp_parse_bind_table_entry(field_tree, tvb, &offset, version);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_backup_source_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_recover_source_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint16 table_count;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint16), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint16), NULL);
if (tree && table_count) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, table_count * (int)sizeof(guint64),
ett_zbee_zdp_bind_source, NULL, "Source Table");
}
for (i=0; i<table_count; i++) {
(void)zbee_parse_eui64(field_tree, hf_zbee_zdp_bind_src64, tvb, &offset, (int)sizeof(guint64), NULL);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
