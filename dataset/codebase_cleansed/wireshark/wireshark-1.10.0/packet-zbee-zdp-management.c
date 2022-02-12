void
zdp_parse_nwk_desc(proto_tree *tree, tvbuff_t *tvb, guint *offset, packet_info *pinfo)
{
proto_item *ti = NULL;
guint len = 0;
guint64 ext_pan;
guint16 pan;
guint8 channel;
guint8 profile;
guint8 version;
guint8 beacon;
guint8 superframe;
gboolean permit;
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
ext_pan = tvb_get_letoh64(tvb, *offset + len);
if (tree) ti = proto_tree_add_text(tree, tvb, *offset, 0, "{Pan: %s", eui64_to_str(ext_pan));
len += (int)sizeof(guint64);
}
else {
pan = tvb_get_letohs(tvb, *offset + len);
if (tree) ti = proto_tree_add_text(tree, tvb, *offset, 0, "{Pan: 0x%04x", pan);
len += (int)sizeof(guint16);
}
channel = tvb_get_guint8(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Channel: %d", channel);
len += (int)sizeof(guint8);
profile = (tvb_get_guint8(tvb, *offset + len) & 0x0f) >> 0;
version = (tvb_get_guint8(tvb, *offset + len) & 0xf0) >> 4;
if (tree) proto_item_append_text(ti, ", Profile: 0x%01x, Version: %d", profile, version);
len += (int)sizeof(guint8);
beacon = (tvb_get_guint8(tvb, *offset + len) & 0x0f) >> 0;
superframe = (tvb_get_guint8(tvb, *offset + len) & 0xf0) >> 4;
if ((tree) && (beacon == 0xf)) {
proto_item_append_text(ti, ", Beacons Disabled");
}
else if (tree) {
proto_item_append_text(ti, ", BeaconOrder: %d, SuperframeOrder: %d", beacon, superframe);
}
len += (int)sizeof(guint8);
permit = tvb_get_guint8(tvb, *offset) & 0x01;
if (tree) proto_item_append_text(ti, ", PermitJoining: %s}", permit?"True":"False");
len += (int)sizeof(guint8);
if (tree) proto_item_set_len(ti, len);
*offset += len;
}
void
zdp_parse_neighbor_table_entry(proto_tree *tree, tvbuff_t *tvb, guint *offset, packet_info *pinfo)
{
proto_item *ti = NULL;
guint len = 0;
guint64 ext_pan;
guint16 pan;
guint64 ext_addr;
guint16 device;
guint8 type;
guint8 idle_rx;
guint8 rel;
guint8 permit_joining;
guint8 depth;
guint8 lqi;
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
ext_pan = tvb_get_letoh64(tvb, *offset + len);
if (tree) ti = proto_tree_add_text(tree, tvb, *offset, 0, "{Extended PAN: %s", eui64_to_str(ext_pan));
len += (int)sizeof(guint64);
}
else {
pan = tvb_get_letohs(tvb, *offset + len);
if (tree) ti = proto_tree_add_text(tree, tvb, *offset, 0, "{PAN: 0x%04x", pan);
len += (int)sizeof(guint16);
}
ext_addr = tvb_get_letoh64(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Extended Addr: %s", get_eui64_name(ext_addr));
len += (int)sizeof(guint64);
device = tvb_get_letohs(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Addr: 0x%04x", device);
len += (int)sizeof(guint16);
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
type = (tvb_get_guint8(tvb, *offset + len) & 0x03) >> 0;
idle_rx = (tvb_get_guint8(tvb, *offset + len) & 0x0c) >> 2;
rel = (tvb_get_guint8(tvb, *offset + len) & 0x70) >> 4;
}
else {
type = (tvb_get_guint8(tvb, *offset + len) & 0x03) >> 0;
idle_rx = (tvb_get_guint8(tvb, *offset + len) & 0x04) >> 2;
rel = (tvb_get_guint8(tvb, *offset + len) & 0x18) >> 3;
}
if (tree) {
if (type == 0x00) proto_item_append_text(ti, ", Type: Coordinator");
else if (type == 0x01) proto_item_append_text(ti, ", Type: Router");
else if (type == 0x02) proto_item_append_text(ti, ", Type: End Device");
else proto_item_append_text(ti, ", Type: Unknown");
if (idle_rx == 0x00) proto_item_append_text(ti, ", Idle Rx: False");
else if (idle_rx==0x01) proto_item_append_text(ti, ", Idle Rx: True");
else proto_item_append_text(ti, ", Idle Rx: Unknown");
if (rel == 0x00) proto_item_append_text(ti, ", Relationship: Parent");
else if (rel == 0x01) proto_item_append_text(ti, ", Relationship: Child");
else if (rel == 0x02) proto_item_append_text(ti, ", Relationship: Sibling");
else if (rel == 0x03) proto_item_append_text(ti, ", Relationship: None");
else if (rel == 0x04) proto_item_append_text(ti, ", Relationship: Previous Child");
else proto_item_append_text(ti, ", Relationship: Unknown");
}
len += (int)sizeof(guint8);
if (pinfo->zbee_stack_vers <= ZBEE_VERSION_2004) {
depth = tvb_get_guint8(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Depth: %d", depth);
len += (int)sizeof(guint8);
}
permit_joining = (tvb_get_guint8(tvb, *offset + len) & 0x03) >> 0;
if (tree) {
if (permit_joining == 0x00) proto_item_append_text(ti, ", Permit Joining: False");
else if (permit_joining == 0x01)proto_item_append_text(ti, ", Permit Joining: True");
else proto_item_append_text(ti, ", Permit Joining: Unknown");
}
len += (int)sizeof(guint8);
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
depth = tvb_get_guint8(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", Depth: %d", depth);
len += (int)sizeof(guint8);
}
lqi = tvb_get_guint8(tvb, *offset + len);
if (tree) proto_item_append_text(ti, ", LQI: %d}", lqi);
len += (int)sizeof(guint8);
if (tree) proto_item_set_len(ti, len);
*offset += len;
}
static void
zdp_parse_routing_table_entry(proto_tree *tree, tvbuff_t *tvb, guint *offset)
{
proto_item *ti = NULL;
guint len = 0;
guint16 dest;
guint8 status;
guint16 next;
dest = tvb_get_letohs(tvb, *offset + len);
if (tree) ti = proto_tree_add_text(tree, tvb, *offset, 2*(int)sizeof(guint16) + (int)sizeof(guint8), "{Destination: 0x%04x", dest);
len += (int)sizeof(guint16);
status = tvb_get_guint8(tvb, *offset + len);
next = tvb_get_letohs(tvb, *offset + len + (int)sizeof(guint8));
if (tree) {
proto_item_append_text(ti, ", Next Hop: 0x%04x", next);
if (status == 0x00) proto_item_append_text(ti, ", Status: Active}");
else if (status == 0x01)proto_item_append_text(ti, ", Status: Discovery Underway}");
else if (status == 0x02)proto_item_append_text(ti, ", Status: Discovery Failed}");
else if (status == 0x03)proto_item_append_text(ti, ", Status: Inactive}");
else proto_item_append_text(ti, ", Status: Unknown}");
}
len += (int)sizeof(guint8) + (int)sizeof(guint16);
*offset += len;
}
void
dissect_zbee_zdp_req_mgmt_nwk_disc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
guint i;
guint offset = 0;
guint32 channels;
channels = tvb_get_letohl(tvb, offset);
if (tree) {
gboolean first = 1;
ti = proto_tree_add_text(tree, tvb, offset, (int)sizeof(guint32), "Scan Channels: ");
for (i=0; i<27; i++) {
if (channels & (1<<i)) {
if (first) proto_item_append_text(ti, "%d", i);
else proto_item_append_text(ti, ", %d", i);
if (channels & (2<<i)) {
while ((channels&(2<<i)) && (i<26)) i++;
proto_item_append_text(ti, "-%d", i);
}
first = 0;
}
}
if (first) proto_item_append_text(ti, "None");
}
offset += (int)sizeof(guint32);
zbee_parse_uint(tree, hf_zbee_zdp_duration, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_mgmt_lqi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_mgmt_rtg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_mgmt_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_mgmt_leave(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
guint8 flags;
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
if (pinfo->zbee_stack_vers >= ZBEE_VERSION_2007) {
flags = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_boolean(tree, hf_zbee_zdp_leave_children, tvb, offset, (int)sizeof(guint8), flags & ZBEE_ZDP_MGMT_LEAVE_CHILDREN);
proto_tree_add_boolean(tree, hf_zbee_zdp_leave_rejoin, tvb, offset, (int)sizeof(guint8), flags & ZBEE_ZDP_MGMT_LEAVE_REJOIN);
}
offset += (int)sizeof(guint8);
}
zbee_append_info(tree, pinfo, ", Device: %s", get_eui64_name(ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_mgmt_direct_join(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint64 ext_addr;
ext_addr = zbee_parse_eui64(tree, hf_zbee_zdp_ext_addr, tvb, &offset, (int)sizeof(guint64), NULL);
zdp_parse_cinfo(tree, ett_zbee_zdp_cinfo, tvb, &offset);
zbee_append_info(tree, pinfo, ", Device: %s", get_eui64_name(ext_addr));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_mgmt_permit_join(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
zbee_parse_uint(tree, hf_zbee_zdp_duration, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_significance, tvb, &offset, (int)sizeof(guint8), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_mgmt_cache(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_req_mgmt_nwkupdate(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 duration;
zdp_parse_chanmask(tree, tvb, &offset);
duration = zbee_parse_uint(tree, hf_zbee_zdp_duration, tvb, &offset, (int)sizeof(guint8), NULL);
if (duration == ZBEE_ZDP_NWKUPDATE_PARAMETERS) {
zbee_parse_uint(tree, hf_zbee_zdp_update_id, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_manager, tvb, &offset, (int)sizeof(guint16), NULL);
}
else if (duration == ZBEE_ZDP_NWKUPDATE_CHANNEL_HOP) {
zbee_parse_uint(tree, hf_zbee_zdp_update_id, tvb, &offset, (int)sizeof(guint8), NULL);
}
else if (duration <= ZBEE_ZDP_NWKUPDATE_SCAN_MAX) {
zbee_parse_uint(tree, hf_zbee_zdp_scan_count, tvb, &offset, (int)sizeof(guint8), NULL);
}
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_nwk_disc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint8 table_count;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && table_count) {
ti = proto_tree_add_text(tree, tvb, offset, tvb_length_remaining(tvb, offset), "Network List");
field_tree = proto_item_add_subtree(ti, ett_zbee_zdp_nwk);
}
for (i=0; i<table_count; i++) {
zdp_parse_nwk_desc(field_tree, tvb, &offset, pinfo);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_lqi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint8 table_count;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && table_count) {
ti = proto_tree_add_text(tree, tvb, offset, tvb_length_remaining(tvb, offset), "Neighbor Table");
field_tree = proto_item_add_subtree(ti, ett_zbee_zdp_lqi);
}
for (i=0; i<table_count; i++) {
zdp_parse_neighbor_table_entry(field_tree, tvb, &offset, pinfo);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_rtg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint8 table_count;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && table_count) {
ti = proto_tree_add_text(tree, tvb, offset, tvb_length_remaining(tvb, offset), "Routing Table");
field_tree = proto_item_add_subtree(ti, ett_zbee_zdp_rtg);
}
for (i=0; i<table_count; i++) {
zdp_parse_routing_table_entry(field_tree, tvb, &offset);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_bind(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *field_tree = NULL;
guint offset = 0;
guint i;
guint8 status;
guint8 table_count;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && table_count) {
ti = proto_tree_add_text(tree, tvb, offset, tvb_length_remaining(tvb, offset), "Binding Table");
field_tree = proto_item_add_subtree(ti, ett_zbee_zdp_bind);
}
for (i=0; i<table_count; i++) {
zdp_parse_bind_table_entry(field_tree, tvb, &offset, pinfo);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_leave(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_direct_join(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_permit_join(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint8 status;
status = zdp_parse_status(tree, tvb, &offset);
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_cache(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *field_tree;
guint offset = 0;
guint i;
guint8 status;
guint8 table_count;
status = zdp_parse_status(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_table_size, tvb, &offset, (int)sizeof(guint8), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_index, tvb, &offset, (int)sizeof(guint8), NULL);
table_count = zbee_parse_uint(tree, hf_zbee_zdp_table_count, tvb, &offset, (int)sizeof(guint8), NULL);
if (tree && table_count) {
ti = proto_tree_add_text(tree, tvb, offset, table_count*((int)sizeof(guint16)+(int)sizeof(guint64)), "Discovery Cache");
field_tree = proto_item_add_subtree(ti, ett_zbee_zdp_cache);
} else {
field_tree = NULL;
}
for (i=0; i<table_count; i++) {
guint64 addr64 = tvb_get_letoh64(tvb, offset);
guint16 addr16 = tvb_get_letohs(tvb, offset+(int)sizeof(guint64));
if (field_tree) {
proto_tree_add_text(field_tree, tvb, offset, (int)sizeof(guint16)+(int)sizeof(guint64), "{%s = 0x%04x}", get_eui64_name(addr64), addr16);
}
offset += (int)sizeof(guint16)+(int)sizeof(guint64);
}
zbee_append_info(tree, pinfo, ", Status: %s", zdp_status_name(status));
zdp_dump_excess(tvb, offset, pinfo, tree);
}
void
dissect_zbee_zdp_rsp_mgmt_nwkupdate(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0;
guint i, j;
guint32 channels;
guint8 channel_count;
zdp_parse_status(tree, tvb, &offset);
channels = zdp_parse_chanmask(tree, tvb, &offset);
zbee_parse_uint(tree, hf_zbee_zdp_tx_total, tvb, &offset, (int)sizeof(guint16), NULL);
zbee_parse_uint(tree, hf_zbee_zdp_tx_fail, tvb, &offset, (int)sizeof(guint16), NULL);
channel_count = zbee_parse_uint(tree, hf_zbee_zdp_channel_count, tvb, &offset, (int)sizeof(guint8), NULL);
for (i=0, j=0; i<(8*(int)sizeof(guint32)); i++) {
guint8 energy;
if ( ! ((1<<i) & channels) ) {
continue;
}
if (j>=channel_count) {
break;
}
energy = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_text(tree, tvb, offset, (int)sizeof(guint8), "Channel %d Energy = 0x%02x", i, energy);
}
offset += (int)sizeof(guint8);
j++;
}
zdp_dump_excess(tvb, offset, pinfo, tree);
}
