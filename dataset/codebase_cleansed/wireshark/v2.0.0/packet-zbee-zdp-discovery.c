void
dissect_zbee_zdp_req_nwk_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_req_type, tvb, &offset, sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, sizeof(guint8), NULL);
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_ext_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_req_type, tvb, &offset, sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, sizeof(guint8), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_node_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, sizeof(guint16), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_power_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, sizeof(guint16), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_simple_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
guint8 endpt;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, sizeof(guint16), NULL);
endpt = zbee_parse_uint(tree, hf_zbee_zdp_endpoint, tvb, &offset, sizeof(guint8), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x, Endpoint: %d", device, endpt);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_active_ep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, sizeof(guint16), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_match_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
proto_tree *field_tree = NULL;
guint offset = 0, i;
guint sizeof_cluster = (version >= ZBEE_VERSION_2007)?(int)sizeof(guint16):(int)sizeof(guint8);
guint16 device;
guint16 profile;
guint8 in_count;
guint8 out_count;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
profile = zbee_parse_uint(tree, hf_zbee_zdp_profile, tvb, &offset, (int)sizeof(guint16), NULL);
in_count = zbee_parse_uint(tree, hf_zbee_zdp_in_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && in_count) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, in_count*sizeof_cluster,
ett_zbee_zdp_match_in, NULL, "Input Cluster List");
}
for (i=0; i<in_count; i++) zbee_parse_uint(field_tree, hf_zbee_zdp_in_cluster, tvb, &offset, sizeof_cluster, NULL);
out_count = zbee_parse_uint(tree, hf_zbee_zdp_out_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && out_count) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, out_count*sizeof_cluster, ett_zbee_zdp_match_out, NULL, "Output Cluster List");
}
for (i=0; i<out_count; i++) zbee_parse_uint(field_tree, hf_zbee_zdp_out_cluster, tvb, &offset, sizeof_cluster, NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x, Profile: 0x%04x", device, profile);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_complex_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_user_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_discovery_cache(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_device_annce(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zdp_parse_cinfo(tree, ett_zbee_zdp_cinfo, tvb, &offset);
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_set_user_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
guint offset = 0;
guint16 device;
guint8 user_length;
gchar *user;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
if (version >= ZBEE_VERSION_2007) {
user_length = zbee_parse_uint(tree, hf_zbee_zdp_user_length, tvb, &offset, (int)sizeof(guint8), NULL);
}
else {
user_length = 16;
}
user = (gchar *)wmem_alloc(wmem_packet_scope(), user_length+1);
user = (gchar *)tvb_memcpy(tvb, user, offset, user_length);
user[user_length] = '\0';
if (tree) {
proto_tree_add_string(tree, hf_zbee_zdp_user, tvb, offset, user_length, user);
}
offset += user_length;
zbee_append_info(tree, pinfo, ", Device: 0x%04x, Desc: \'%s\'", device, user);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_system_server_disc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
zdp_parse_server_flags(tree, ett_zbee_zdp_server, tvb, &offset);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_store_discovery(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree;
guint offset = 0;
guint i;
guint64 ext_addr;
guint8 simple_count;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_disc_node_size, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_disc_power_size, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_disc_ep_count, tvb, &offset, (int)sizeof(guint8), NULL);
simple_count= zbee_parse_uint(tree, hf_zbee_zdp_disc_simple_count, tvb, &offset, (int)sizeof(guint8), NULL);
field_tree = proto_tree_add_subtree(tree, tvb, offset, simple_count, ett_zbee_zdp_simple_sizes, NULL, "Simple Descriptor Sizes");
for (i=0; i<simple_count; i++) {
zbee_parse_uint(field_tree, hf_zbee_zdp_disc_simple_size, tvb, &offset, (int)sizeof(guint8), NULL);
}
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_store_node_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
guint offset = 0;
guint64 ext_addr;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zdp_parse_node_desc(tree, ett_zbee_zdp_node, tvb, &offset, version);
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_store_power_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zdp_parse_power_desc(tree, ett_zbee_zdp_power, tvb, &offset);
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_store_active_ep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree;
guint offset = 0;
guint i;
guint64 ext_addr;
guint8 ep_count;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
ep_count = zbee_parse_uint(tree, hf_zbee_zdp_ep_count, tvb, &offset, (int)sizeof(guint8), NULL);
field_tree = proto_tree_add_subtree(tree, tvb, offset, ep_count, ett_zbee_zdp_endpoint, NULL, "Active Endpoints");
for (i=0; i<ep_count; i++) {
(void)zbee_parse_uint(field_tree, hf_zbee_zdp_endpoint, tvb, &offset, (int)sizeof(guint8), NULL);
}
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_store_simple_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
guint offset = 0;
guint64 ext_addr;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_simple_length, tvb, &offset, (int)sizeof(guint8), NULL);
zdp_parse_simple_desc(tree, ett_zbee_zdp_simple, tvb, &offset, version);
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_remove_node_cache(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_find_node_cache(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_append_info(tree, pinfo, ", Device: %s", eui64_to_display(wmem_packet_scope(), ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_ext_simple_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
guint8 endpt;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
endpt = zbee_parse_uint(tree, hf_zbee_zdp_endpoint, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x, Endpoint: %d", device, endpt);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_ext_active_ep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 device;
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_nwk_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint64 ext_addr;
guint16 device;
guint8 assoc;
status = zdp_parse_status(tree, tvb, &offset);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
if (tvb_bytes_exist(tvb, offset, 2*(int)sizeof(guint8))) {
assoc = zbee_parse_uint(tree, hf_zbee_zdp_assoc_device_count, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
if ((tree) && (assoc)) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, assoc*(int)sizeof(guint16),
ett_zbee_zdp_assoc_device, NULL, "Associated Device List");
}
for (i=0; i<assoc; i++) {
(void)zbee_parse_uint(field_tree, hf_zbee_zdp_assoc_device, tvb, &offset, (int)sizeof(guint16), NULL);
}
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
if (status == ZBEE_ZDP_STATUS_SUCCESS) {
zbee_append_info(tree, pinfo, ", Device: %s = 0x%04x", eui64_to_display(wmem_packet_scope(), ext_addr), device);
}
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_ext_addr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint64 ext_addr;
guint16 device;
guint8 assoc;
status = zdp_parse_status(tree, tvb, &offset);
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
if (tvb_bytes_exist(tvb, offset, 2*(int)sizeof(guint8))) {
assoc = zbee_parse_uint(tree, hf_zbee_zdp_assoc_device_count, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
if ((tree) && (assoc)) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, assoc*(int)sizeof(guint16),
ett_zbee_zdp_assoc_device, NULL, "Associated Device List");
}
for (i=0; i<assoc; i++) {
(void)zbee_parse_uint(field_tree, hf_zbee_zdp_assoc_device, tvb, &offset, (int)sizeof(guint16), NULL);
}
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
if (status == ZBEE_ZDP_STATUS_SUCCESS) {
zbee_append_info(tree, pinfo, ", Device: 0x%04x = %s", device, eui64_to_display(wmem_packet_scope(), ext_addr));
}
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_node_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
guint offset = 0;
guint8 status;
guint16 device;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
if (status == ZBEE_ZDP_STATUS_SUCCESS) {
zdp_parse_node_desc(tree, ett_zbee_zdp_node, tvb, &offset, version);
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_power_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
guint16 device;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
if (status == ZBEE_ZDP_STATUS_SUCCESS) {
zdp_parse_power_desc(tree, ett_zbee_zdp_power, tvb, &offset);
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_simple_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
guint offset = 0;
guint8 status;
guint16 device;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_simple_length, tvb, &offset, (int)sizeof(guint8), NULL);
if (status == ZBEE_ZDP_STATUS_SUCCESS) {
zdp_parse_simple_desc(tree, ett_zbee_zdp_simple, tvb, &offset, version);
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_active_ep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint16 device;
guint8 ep_count;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ep_count = zbee_parse_uint(tree, hf_zbee_zdp_ep_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && ep_count) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, ep_count*(int)sizeof(guint8),
ett_zbee_zdp_endpoint, NULL, "Active Endpoint List");
}
for (i=0; i<ep_count; i++) {
(void)zbee_parse_uint(field_tree, hf_zbee_zdp_endpoint, tvb, &offset, (int)sizeof(guint8), NULL);
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_match_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint16 device;
guint8 ep_count;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ep_count = zbee_parse_uint(tree, hf_zbee_zdp_ep_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && ep_count) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, ep_count*(int)sizeof(guint8),
ett_zbee_zdp_endpoint, NULL, "Matching Endpoint List");
}
for (i=0; i<ep_count; i++) {
(void)zbee_parse_uint(field_tree, hf_zbee_zdp_endpoint, tvb, &offset, (int)sizeof(guint8), NULL);
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_complex_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
guint8 length;
guint16 device;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
length = zbee_parse_uint(tree, hf_zbee_zdp_complex_length, tvb, &offset, (int)sizeof(guint8), NULL);
if (length) {
zdp_parse_complex_desc(tree, -1, tvb, &offset, length);
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_user_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
guint offset = 0;
guint8 status;
guint16 device;
guint8 user_length;
gchar *user;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
if ((version >= ZBEE_VERSION_2007) || (status == ZBEE_ZDP_STATUS_SUCCESS)) {
user_length = zbee_parse_uint(tree, hf_zbee_zdp_user_length, tvb, &offset, (int)sizeof(guint8), NULL);
}
else user_length = 0;
user = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, user_length, ENC_ASCII);
if (tree) {
proto_tree_add_string(tree, hf_zbee_zdp_user, tvb, offset, user_length, user);
}
offset += user_length;
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
if (status == ZBEE_ZDP_STATUS_SUCCESS) {
zbee_append_info(tree, pinfo, ", Desc: \'%s\'", user);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_user_desc_conf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 version)
{
guint offset = 0;
guint8 status;
guint16 device = 0;
status = zdp_parse_status(tree, tvb, &offset);
if (version >= ZBEE_VERSION_2007) {
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_discovery_cache(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_system_server_disc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zdp_parse_server_flags(tree, ett_zbee_zdp_server, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_discovery_store(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_store_node_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_store_power_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_store_active_ep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_store_simple_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_remove_node_cache(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_find_node_cache(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint16 cache;
guint16 device;
cache = zbee_parse_uint(tree, hf_zbee_zdp_cache, tvb, &offset, (int)sizeof(guint16), NULL);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zbee_append_info(tree, pinfo, ", Cache: 0x%04x", cache);
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_ext_simple_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint i;
guint sizeof_cluster = (int)sizeof(guint16);
guint8 status;
guint16 device;
guint8 in_count;
guint8 out_count;
guint8 idx;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_endpoint, tvb, &offset, (int)sizeof(guint8), NULL);
in_count = zbee_parse_uint(tree, hf_zbee_zdp_in_count, tvb, &offset, (int)sizeof(guint8), NULL);
out_count = zbee_parse_uint(tree, hf_zbee_zdp_out_count, tvb, &offset, (int)sizeof(guint8), NULL);
idx = zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
for (i=idx; (i<in_count) && tvb_bytes_exist(tvb, offset, sizeof_cluster); i++) {
zbee_parse_uint(tree, hf_zbee_zdp_in_cluster, tvb, &offset, sizeof_cluster, NULL);
}
for (i-=in_count; (i<out_count) && tvb_bytes_exist(tvb, offset, sizeof_cluster); i++) {
zbee_parse_uint(tree, hf_zbee_zdp_out_cluster, tvb, &offset, sizeof_cluster, NULL);
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_ext_active_ep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint16 device;
guint8 ep_count;
guint8 idx;
status = zdp_parse_status(tree, tvb, &offset);
device = zbee_parse_uint(tree, hf_zbee_zdp_device, tvb, &offset, (int)sizeof(guint16), NULL);
ep_count = zbee_parse_uint(tree, hf_zbee_zdp_ep_count, tvb, &offset, (int)sizeof(guint8), NULL);
idx = zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && ep_count) {
field_tree = proto_tree_add_subtree(tree, tvb, offset, ep_count*(int)sizeof(guint8),
ett_zbee_zdp_endpoint, NULL, "Active Endpoint List");
for (i=idx; (i<ep_count) && tvb_bytes_exist(tvb, offset, (int)sizeof(guint8)); i++) {
(void)zbee_parse_uint(field_tree, hf_zbee_zdp_endpoint, tvb, &offset, (int)sizeof(guint8), NULL);
}
}
zbee_append_info(tree, pinfo, ", Device: 0x%04x", device);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
