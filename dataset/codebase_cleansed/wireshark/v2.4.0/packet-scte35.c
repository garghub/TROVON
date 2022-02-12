static int
dissect_scte35_time_signal(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
gint tvb_len, min_length = 1, offset = 0;
guint8 time_specified_flag;
proto_item *ti;
proto_tree *time_tree;
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len < min_length)
return 0;
time_specified_flag = tvb_get_guint8(tvb, offset) & 0x80;
if (time_specified_flag)
min_length += 4;
if (tvb_len < min_length)
return 0;
col_add_fstr(pinfo->cinfo, COL_INFO, "Time Signal (%s)",
time_specified_flag ? "Future" : "Immediate");
ti = proto_tree_add_item(tree, proto_scte35_time, tvb, 0, -1, ENC_NA);
time_tree = proto_item_add_subtree(ti, ett_scte35_time_signal);
proto_tree_add_item(time_tree, hf_time_specified, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(time_tree, hf_time_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
if (time_specified_flag) {
proto_tree_add_item(time_tree, hf_time_pts, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 4;
}
offset += 1;
return offset;
}
void
proto_register_scte35_time_signal(void)
{
static gint *ett[] = {
&ett_scte35_time_signal,
&ett_scte35_time_signal_splice_time,
};
static hf_register_info hf[] = {
{&hf_time_specified,
{"Time Specified", "scte35_time.splice.time_specified", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_time_reserved,
{"Reserved", "scte35_time.splice.reserved", FT_UINT8, BASE_HEX,
NULL, 0x7E, NULL, HFILL}},
{&hf_time_pts,
{"PTS Time", "scte35_time.splice.pts", FT_UINT64, BASE_DEC,
NULL, G_GUINT64_CONSTANT(0x1FFFFFFFF), NULL, HFILL}},
};
proto_scte35_time = proto_register_protocol("SCTE-35 Time Signal", "SCTE35 TS", "scte35_time");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_scte35_time, hf, array_length(hf));
}
void
proto_reg_handoff_scte35_time_signal(void)
{
dissector_handle_t scte35_time_handle;
scte35_time_handle = create_dissector_handle(dissect_scte35_time_signal, proto_scte35_time);
dissector_add_uint("scte35.splice_command_type", SCTE35_CMD_TIME_SIGNAL, scte35_time_handle);
}
static int
dissect_scte35_private_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint tvb_len;
guint32 identifier;
gint offset = 0;
proto_item *ti;
proto_tree *pc_tree;
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len < 4)
return 0;
ti = proto_tree_add_item(tree, proto_private_command, tvb, 0, -1, ENC_NA);
pc_tree = proto_item_add_subtree(ti, ett_private_command);
proto_tree_add_item_ret_uint(pc_tree, hf_identifier, tvb, offset, 4, ENC_BIG_ENDIAN, &identifier);
col_add_fstr(pinfo->cinfo, COL_INFO, "Private Command (0x%08x)", identifier);
offset += 4;
proto_tree_add_item(pc_tree, hf_private_byte, tvb, offset, -1, ENC_NA);
dissector_try_uint(private_identifier_table, identifier, tvb, pinfo, tree);
return tvb_len;
}
void
proto_register_scte35_private_command(void)
{
static gint *ett[] = {
&ett_private_command,
};
static hf_register_info hf[] = {
{&hf_identifier,
{"Identifier", "scte35_private_command.identifier", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL}},
{&hf_private_byte,
{"Private Bytes", "scte35_private_command.private_byte", FT_BYTES, 0,
NULL, 0, NULL, HFILL}},
};
proto_private_command = proto_register_protocol("SCTE-35 Private Command", "SCTE35 PC", "scte35_private_command");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_private_command, hf, array_length(hf));
private_identifier_table = register_dissector_table(
"scte35_private_command.identifier", "SCTE-35 Private Command Identifier",
proto_private_command, FT_UINT32, BASE_HEX);
}
void
proto_reg_handoff_scte35_private_command(void)
{
dissector_handle_t scte35_private_command_handle;
scte35_private_command_handle = create_dissector_handle(dissect_scte35_private_command, proto_private_command);
dissector_add_uint("scte35.splice_command_type", SCTE35_CMD_PRIVATE_COMMAND, scte35_private_command_handle);
}
static int
dissect_component(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint8 sif, int idx)
{
gint offset = 0;
guint8 component_tag, tsf;
proto_tree *component_tree;
gint tvb_len, min_length = sif ? 1 : 2;
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len < min_length)
return 0;
if (!sif) {
tsf = tvb_get_guint8(tvb, offset + 1) & 0x80;
if (tsf) {
min_length += 4;
if (tvb_len < min_length)
return 0;
}
}
component_tag = tvb_get_guint8(tvb, offset);
proto_tree_add_subtree_format(
tree, tvb, offset, min_length, idx, &component_tree,
"Component %d (0x%02x)", idx, component_tag);
proto_tree_add_item(component_tree, hf_component_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (!sif) {
proto_tree_add_item(component_tree, hf_component_splice_time_tsf, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(component_tree, hf_component_splice_time_reserved,
tvb, offset, 1, ENC_BIG_ENDIAN);
if (tsf) {
proto_tree_add_item(component_tree, hf_component_splice_time_pts_time,
tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 4;
}
offset++;
}
return offset;
}
static int
dissect_scte35_splice_insert(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint tvb_len, min_length = 5, dissected_length;
guint8 cancel_flag, psf, df, sif, tsf, component_count;
guint32 event_id;
gint component;
gint offset = 0;
proto_item *ti;
proto_tree *si_tree, *st_tree;
static const int *new_event_fields[] = {
&hf_out_of_network_indicator,
&hf_program_splice_flag,
&hf_duration_flag,
&hf_splice_immediate_flag,
&hf_reserved1,
NULL
};
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len < min_length)
return 0;
cancel_flag = tvb_get_guint8(tvb, offset + 4) & 0x80;
event_id = tvb_get_ntohl(tvb, 0);
if (!cancel_flag) {
min_length += 5;
if (tvb_len < min_length)
return 0;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Splice %s Event 0x%08x",
cancel_flag ? "Cancellation" : "Insertion", event_id);
ti = proto_tree_add_item(tree, proto_scte35_si, tvb, 0, -1, ENC_NA);
si_tree = proto_item_add_subtree(ti, ett_scte35_splice_insert);
proto_tree_add_item(si_tree, hf_splice_insert_event_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(si_tree, hf_splice_cancel_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(si_tree, hf_reserved0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (!cancel_flag) {
psf = tvb_get_guint8(tvb, offset) & 0x40;
df = tvb_get_guint8(tvb, offset) & 0x20;
sif = tvb_get_guint8(tvb, offset) & 0x10;
proto_tree_add_bitmask_list(si_tree, tvb, offset, 1, new_event_fields, ENC_BIG_ENDIAN);
offset++;
if (psf && !sif) {
min_length += 1;
if (tvb_len < min_length)
return offset;
tsf = tvb_get_bits8(tvb, offset * 8, 1);
proto_tree_add_subtree(si_tree, tvb, offset, tsf ? 5 : 1, 0, &st_tree, "Program Splice Time");
proto_tree_add_item(st_tree, hf_splice_time_specified_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(st_tree, hf_splice_time_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
if (tsf) {
min_length += 4;
if (tvb_len < min_length)
return offset;
proto_tree_add_item(st_tree, hf_splice_time_pts_time, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 4;
}
offset++;
}
if (!psf) {
min_length += 1;
if (tvb_len < min_length)
return offset;
component_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(si_tree, hf_component_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
min_length += component_count * (sif ? 1 : 2);
if (tvb_len < min_length)
return offset;
for (component = 0; component < component_count; ++component) {
dissected_length = dissect_component(
tvb_new_subset_remaining(tvb, offset),
pinfo, si_tree, sif, component);
if (dissected_length < 1)
return offset;
offset += dissected_length;
}
}
if (df) {
min_length += 5;
if (tvb_len < min_length)
return offset;
proto_tree_add_item(si_tree, hf_break_duration_auto_return, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(si_tree, hf_break_duration_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(si_tree, hf_break_duration_duration, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
}
proto_tree_add_item(si_tree, hf_unique_program_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(si_tree, hf_avail_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(si_tree, hf_avails_expected, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
return offset;
}
void
proto_register_scte35_splice_insert(void)
{
static hf_register_info hf[] = {
{&hf_splice_insert_event_id,
{"Event ID", "scte35_si.event_id", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL}},
{&hf_splice_cancel_indicator,
{"Cancelled", "scte35_si.cancelled", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_reserved0,
{"Reserved", "scte35_si.reserved0", FT_UINT8, 1,
NULL, 0x7F, NULL, HFILL}},
{&hf_out_of_network_indicator,
{"Out of Network", "scte35_si.out_of_net", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_program_splice_flag,
{"Program Splice Point", "scte35_si.psf", FT_BOOLEAN, 8,
NULL, 0x40, NULL, HFILL}},
{&hf_duration_flag,
{"Duration Present", "scte35_si.duration_flag", FT_BOOLEAN, 8,
NULL, 0x20, NULL, HFILL}},
{&hf_splice_immediate_flag,
{"Splice Immediate", "scte35_si.splice_immediate", FT_BOOLEAN, 8,
NULL, 0x10, NULL, HFILL}},
{&hf_reserved1,
{"Reserved", "scte35_si.reserved1", FT_UINT8, 1,
NULL, 0x0f, NULL, HFILL}},
{&hf_splice_time_specified_flag,
{"Time Specified", "scte35_si.splice_time.time_specified", FT_BOOLEAN,
8, NULL, 0x80, NULL, HFILL}},
{&hf_splice_time_reserved,
{"Reserved", "scte35_si.splice_time.reserved", FT_UINT8, 1,
NULL, 0x7E, NULL, HFILL}},
{&hf_splice_time_pts_time,
{"PTS Time", "scte35_si.splice_time.pts", FT_UINT64, 5,
NULL, G_GUINT64_CONSTANT(0x1FFFFFFFF), NULL, HFILL}},
{&hf_component_count,
{"Component Count", "scte35_si.component_count", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{&hf_component_tag,
{"Component Tag", "scte35_si.component.tag", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{&hf_component_splice_time_tsf,
{"Time Specified", "scte35_si.component.time_specified", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_component_splice_time_reserved,
{"Reserved", "scte35_si.component.reserved", FT_UINT8, 1,
NULL, 0x7E, NULL, HFILL}},
{&hf_component_splice_time_pts_time,
{"PTS Time", "scte35_si.component.pts", FT_UINT64, 5,
NULL, G_GUINT64_CONSTANT(0x1FFFFFFFF), NULL, HFILL}},
{&hf_break_duration_auto_return,
{"Auto Return", "scte35_si.break.auto_return", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL}},
{&hf_break_duration_reserved,
{"Reserved", "scte35_si.break.reserved", FT_UINT8, 1,
NULL, 0x7E, NULL, HFILL}},
{&hf_break_duration_duration,
{"Duration", "scte35_si.break.duration", FT_UINT64, 5,
NULL, G_GUINT64_CONSTANT(0x1FFFFFFFF), NULL, HFILL}},
{&hf_unique_program_id,
{"Unique Program ID", "scte35_si.upid", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL}},
{&hf_avail_num,
{"Avail Number", "scte35_si.avail", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{&hf_avails_expected,
{"Avails Expected", "scte35_si.avails_expected", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_scte35_splice_insert,
};
proto_scte35_si = proto_register_protocol("SCTE-35 Splice Insert", "SCTE35 SI", "scte35_si");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_scte35_si, hf, array_length(hf));
}
void
proto_reg_handoff_scte35_splice_insert(void)
{
dissector_handle_t scte35_si_handle;
scte35_si_handle = create_dissector_handle(dissect_scte35_splice_insert, proto_scte35_si);
dissector_add_uint("scte35.splice_command_type", SCTE35_CMD_SPLICE_INSERT, scte35_si_handle);
}
static int
dissect_scte35_splice_schedule(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint tvb_len, min_length = 1;
guint8 splice_count, cancel_flag, psf, df, component_count;
gint component, splice;
gint offset = 0, splice_length;
proto_item *ti;
proto_tree *ss_tree, *sp_tree, *component_tree;
static const int *splice_event_flags[] = {
&hf_splice_out_of_network,
&hf_splice_program_splice_flag,
&hf_splice_duration_flag,
&hf_splice_reserved1,
NULL
};
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len < min_length)
return 0;
splice_count = tvb_get_guint8(tvb, 0);
min_length += splice_count * 5;
if (tvb_len < min_length)
return 0;
col_add_fstr(pinfo->cinfo, COL_INFO, "Splice Schedule (%d splices)", splice_count);
ti = proto_tree_add_item(tree, proto_scte35_splice_schedule, tvb, 0, -1, ENC_NA);
ss_tree = proto_item_add_subtree(ti, ett_scte35_splice_schedule);
proto_tree_add_item(ss_tree, hf_splice_count, tvb, offset, 1, ENC_NA);
offset++;
for (splice = 0; splice < splice_count; ++splice) {
cancel_flag = tvb_get_bits8(tvb, offset * 8 + 32, 1);
psf = cancel_flag ? 0 : tvb_get_bits8(tvb, offset * 8 + 41, 1);
df = cancel_flag ? 0 : tvb_get_bits8(tvb, offset * 8 + 42, 1);
component_count = cancel_flag ? 0 : (psf ? 0 : tvb_get_guint8(tvb, offset + 6));
splice_length = 5;
if (!cancel_flag)
splice_length += 4 + 1;
if (!cancel_flag && psf)
splice_length += 4;
if (!cancel_flag && !psf)
splice_length += 1 + 5 * component_count;
if (!cancel_flag && df)
splice_length += 5;
proto_tree_add_subtree_format(
ss_tree, tvb, offset, splice_length, splice, &sp_tree,
"Splice %d", splice);
proto_tree_add_item(ss_tree, hf_splice_event_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ss_tree, hf_splice_event_cancel_indicator, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ss_tree, hf_splice_reserved0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (!cancel_flag) {
min_length += 5;
if (tvb_len < min_length)
return offset;
df = tvb_get_bits8(tvb, offset * 8 + 2, 1);
proto_tree_add_bitmask_list(ss_tree, tvb, offset, 1, splice_event_flags, ENC_BIG_ENDIAN);
offset++;
min_length += (psf ? 4 : 1);
if (tvb_len < min_length)
return offset;
if (psf) {
proto_tree_add_item(ss_tree, hf_splice_utc_splice_time, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
component_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ss_tree, hf_splice_component_count, tvb, offset, 1, ENC_NA);
offset++;
min_length += 5 * component_count;
if (tvb_len < min_length)
return offset;
for (component = 0; component < component_count; ++component) {
proto_tree_add_subtree_format(sp_tree, tvb, offset, 5, component, &component_tree,
"Component %d", component);
proto_tree_add_item(component_tree, hf_splice_component_tag, tvb,
offset, 1, ENC_NA);
offset++;
proto_tree_add_item(component_tree, hf_splice_component_utc_splice_time, tvb,
offset, 4, ENC_NA);
offset += 4;
}
}
if (df) {
min_length += 5;
if (tvb_len < min_length)
return offset;
proto_tree_add_item(ss_tree, hf_splice_break_duration_auto_return, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ss_tree, hf_splice_break_duration_reserved, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ss_tree, hf_splice_break_duration_duration, tvb,
offset, 5, ENC_BIG_ENDIAN);
offset += 5;
}
}
proto_tree_add_item(ss_tree, hf_splice_unique_program_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(ss_tree, hf_splice_avail_num, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ss_tree, hf_splice_avails_expected, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}
return offset;
}
void
proto_register_scte35_splice_schedule(void)
{
static hf_register_info hf[] = {
{&hf_splice_count,
{"Splice Count", "scte35_splice_schedule.splice_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_splice_event_id,
{"Event ID", "scte35_splice_schedule.splice.event_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL}},
{&hf_splice_event_cancel_indicator,
{"Event Cancel Indicator", "scte35_splice_schedule.splice.event_cancel_indicator",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}},
{&hf_splice_reserved0,
{"Reserved", "scte35_splice_schedule.splice.reserved0",
FT_UINT8, BASE_HEX, NULL, 0x7F, NULL, HFILL}},
{&hf_splice_out_of_network,
{"Out of Network Indicator", "scte35_splice_schedule.splice.out_of_network_indicator",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}},
{&hf_splice_program_splice_flag,
{"Program Splice Flag", "scte35_splice_schedule.splice.program_splice_flag",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL}},
{&hf_splice_duration_flag,
{"Duration Flag", "scte35_splice_schedule.splice.duration_flag",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL}},
{&hf_splice_reserved1,
{"Reserved", "scte35_splice_schedule.splice.reserved1",
FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL}},
{&hf_splice_utc_splice_time,
{"UTC Splice Time", "scte35_splice_schedule.splice.utc_splice_time",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_splice_component_count,
{"Component Count", "scte35_splice_schedule.splice.component_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_splice_component_tag,
{"Component Tag", "scte35_splice_schedule.splice.component.tag",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL}},
{&hf_splice_component_utc_splice_time,
{"UTC Splice Time", "scte35_splice_schedule.splice.component.utc_splice_time",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_splice_break_duration_auto_return,
{"Auto Return", "scte35_splice_schedule.splice.break_duration.auto_return",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}},
{&hf_splice_break_duration_reserved,
{"Reserved", "scte35_splice_schedule.splice.break_duration.reserved",
FT_UINT8, BASE_HEX, NULL, 0x7E, NULL, HFILL}},
{&hf_splice_break_duration_duration,
{"Duration", "scte35_splice_schedule.splice.break_duration.duration",
FT_UINT64, BASE_DEC, NULL, G_GUINT64_CONSTANT(0x1FFFFFFFF), NULL, HFILL}},
{&hf_splice_unique_program_id,
{"Unique Program ID", "scte35_splice_schedule.splice.unique_program_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL}},
{&hf_splice_avail_num,
{"Avail Number", "scte35_splice_schedule.splice.avail_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_splice_avails_expected,
{"Avails Expected", "scte35_splice_schedule.splice.avails_expected",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_scte35_splice_schedule,
};
proto_scte35_splice_schedule = proto_register_protocol("SCTE-35 Splice Schedule", "SCTE35 SS", "scte35_splice_schedule");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_scte35_splice_schedule, hf, array_length(hf));
}
void
proto_reg_handoff_scte35_splice_schedule(void)
{
dissector_handle_t dissector;
dissector = create_dissector_handle(dissect_scte35_splice_schedule, proto_scte35_splice_schedule);
dissector_add_uint("scte35.splice_command_type", SCTE35_CMD_SPLICE_SCHEDULE, dissector);
}
static int
dissect_scte35_avail_descriptor(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
gint offset = 0;
gint tvb_len;
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len < 4)
return 0;
proto_tree_add_item(tree, hf_descriptor_provider_avail_id, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int
dissect_scte35_dtmf_descriptor(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
gint offset = 0;
gint tvb_len, min_length = 2;
guint8 dtmf_count;
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len < min_length)
return 0;
dtmf_count = tvb_get_bits8(tvb, (offset+1)* 8, 3);
min_length += dtmf_count;
if (tvb_len < min_length)
return 0;
proto_tree_add_item(tree, hf_descriptor_preroll, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_descriptor_dtmf_count, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_descriptor_dtmf_reserved, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_descriptor_dtmf, tvb,
offset, dtmf_count, ENC_NA | ENC_ASCII);
offset += dtmf_count;
return offset;
}
static int
dissect_scte35_component(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int idx) {
gint offset = 0;
proto_tree *subtree;
proto_tree_add_subtree_format(tree, tvb, offset, 6, idx, &subtree, "Component %d", idx);
proto_tree_add_item(subtree, hf_descriptor_component_tag, tvb,
offset, 1, ENC_NA);
offset++;
proto_tree_add_item(subtree, hf_descriptor_component_reserved, tvb,
offset, 1, ENC_NA);
proto_tree_add_item(subtree, hf_descriptor_component_pts_offset, tvb,
offset, 5, ENC_BIG_ENDIAN);
offset += 5;
return offset;
}
static int
dissect_scte35_segmentation_descriptor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset = 0, dissected_length = 0, component;
guint8 cancel_indicator, psf, sdf, dnr, component_count, upid_length;
proto_tree_add_item(tree, hf_descriptor_event_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
cancel_indicator = tvb_get_bits8(tvb, offset * 8, 1);
proto_tree_add_item(tree, hf_descriptor_cancel_indicator, tvb,
offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_descriptor_reserved0, tvb,
offset, 1, ENC_NA);
offset++;
if (!cancel_indicator) {
psf = tvb_get_bits8(tvb, offset * 8, 1);
sdf = tvb_get_bits8(tvb, offset * 8 + 1, 1);
dnr = tvb_get_bits8(tvb, offset * 8 + 2, 1);
proto_tree_add_item(tree, hf_descriptor_psf, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_descriptor_segmentation_duration_flag,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_descriptor_delivery_not_restricted_flag,
tvb, offset, 1, ENC_NA);
if (dnr) {
proto_tree_add_item(tree, hf_descriptor_reserved1, tvb, offset, 1, ENC_NA);
} else {
proto_tree_add_item(tree, hf_descriptor_web_delivery_allowed_flag,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_descriptor_no_regional_blackout_flag,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_descriptor_archive_allow_flag,
tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_descriptor_device_restrictions,
tvb, offset, 1, ENC_NA);
}
offset++;
if (!psf) {
component_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_descriptor_component_count, tvb,
offset, 1, ENC_NA);
offset++;
for (component = 0; component < component_count; ++component) {
dissected_length = dissect_scte35_component(
tvb_new_subset_length(tvb, offset, 6),
pinfo, tree, component);
if (dissected_length < 1)
return dissected_length;
offset += dissected_length;
}
}
if (sdf) {
proto_tree_add_item(tree, hf_descriptor_segmentation_duration, tvb,
offset, 5, ENC_BIG_ENDIAN);
offset += 5;
}
proto_tree_add_item(tree, hf_descriptor_segmentation_upid_type, tvb,
offset, 1, ENC_NA);
offset++;
upid_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_descriptor_segmentation_upid_length, tvb,
offset, 1, ENC_NA);
offset++;
if (upid_length) {
proto_tree_add_item(tree, hf_descriptor_segmentation_upid, tvb,
offset, upid_length, ENC_NA | ENC_ASCII);
offset += upid_length;
}
proto_tree_add_item(tree, hf_descriptor_segmentation_type_id, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_descriptor_segment_num, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_descriptor_segments_expected, tvb, offset, 1, ENC_NA);
offset++;
}
return offset;
}
static int
dissect_scte35_splice_descriptor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
proto_tree *subtree;
tvbuff_t *descriptor_tvb;
gint offset = 0, dissected_length = 0;
guint8 tag, length = 0;
tag = tvb_get_guint8(tvb, offset);
length = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_subtree_format(
tree, tvb, offset, length + 2, idx, &subtree,
"Descriptor %d (0x%02x)", idx, tag);
proto_tree_add_item(subtree, hf_splice_descriptor_tag, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(subtree, hf_splice_descriptor_length, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(subtree, hf_splice_descriptor_identifier, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
descriptor_tvb = tvb_new_subset_length(tvb, offset, length - 4);
switch (tag) {
case SCTE35_AVAIL_DESCRIPTOR:
dissected_length = dissect_scte35_avail_descriptor(descriptor_tvb, pinfo, subtree);
break;
case SCTE35_DTMF_DESCRIPTOR:
dissected_length = dissect_scte35_dtmf_descriptor(descriptor_tvb, pinfo, subtree);
break;
case SCTE35_SEGMENTATION_DESCRIPTOR:
dissected_length = dissect_scte35_segmentation_descriptor(descriptor_tvb, pinfo, subtree);
break;
default:
dissected_length = length - 4;
}
if (dissected_length < 1)
return dissected_length;
offset += dissected_length;
return offset;
}
static int
dissect_scte35_splice_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint tvb_len, min_length = SCTE35_SI_MIN_LEN, dissected_length = 0;
guint8 table_id, encrypted_packet, command_type;
guint16 command_length, descriptor_loop_length, i;
proto_item *ti;
proto_tree *splice_info_tree;
gint offset = 0, descriptor_offset = 0;
tvbuff_t *command_tvb;
const gint *section_flags[] = {
&hf_section_syntax_indicator,
&hf_private_indicator,
&hf_reserved,
&hf_section_length,
NULL
};
const gint *encrypt_flags[] = {
&hf_encrypted_packet,
&hf_encryption_algorithm,
&hf_pts_adjustment,
NULL
};
tvb_len = (gint)tvb_reported_length(tvb);
if (tvb_len < min_length)
return 0;
table_id = tvb_get_guint8(tvb, offset);
encrypted_packet = tvb_get_guint8(tvb, offset + 4) & 0x80;
command_type = tvb_get_guint8(tvb, offset + 13);
command_length = tvb_get_ntohs(tvb, offset + 11) & 0xFFF;
min_length += command_length;
if (tvb_len < min_length)
return 0;
descriptor_loop_length = tvb_get_ntohs(tvb, 14 + command_length);
min_length += descriptor_loop_length;
if (tvb_len < min_length)
return 0;
if (encrypted_packet)
min_length += 4;
if (tvb_len < min_length)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCTE-35");
col_add_fstr(pinfo->cinfo, COL_INFO, "Table 0x%02x", table_id);
ti = proto_tree_add_item(tree, proto_scte35, tvb, 0, -1, ENC_NA);
splice_info_tree = proto_item_add_subtree(ti, ett_scte35_splice_info_section);
proto_tree_add_item(splice_info_tree, hf_table_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_bitmask_list(splice_info_tree, tvb, offset, 2, section_flags, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(splice_info_tree, hf_protocol_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_bitmask_list(splice_info_tree, tvb, offset, 5, encrypt_flags, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(splice_info_tree, hf_cw_index, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(splice_info_tree, hf_tier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(splice_info_tree, hf_splice_command_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(splice_info_tree, hf_splice_command_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
command_tvb = tvb_new_subset_length(tvb, offset, command_length);
offset += command_length;
proto_tree_add_item(splice_info_tree, hf_descriptor_loop_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for (i = 0, descriptor_offset = offset;
descriptor_offset < offset + descriptor_loop_length;
++i) {
dissected_length = dissect_scte35_splice_descriptor( tvb_new_subset_remaining(tvb, descriptor_offset),
pinfo, splice_info_tree, i);
if (dissected_length < 1)
return offset;
descriptor_offset += dissected_length;
}
offset += descriptor_loop_length;
if (encrypted_packet) {
proto_tree_add_item(splice_info_tree, hf_e_crc32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(splice_info_tree, hf_crc32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
dissector_try_uint_new(scte35_cmd_dissector_table, command_type, command_tvb, pinfo, tree,
FALSE, NULL);
return offset;
}
void
proto_register_scte35(void)
{
static gint *ett[] = {
&ett_scte35_splice_info_section,
};
static hf_register_info hf[] = {
{&hf_table_id,
{"Table ID", "scte35.tid", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{&hf_section_syntax_indicator,
{"Section Syntax Identifier", "scte35.syntax_indicator", FT_BOOLEAN,
16, TFS(&tfs_section_syntax_indicator), 0x8000, NULL, HFILL }},
{&hf_private_indicator,
{"Private Indicator", "scte35.private", FT_BOOLEAN,
16, TFS(&tfs_private_indicator), 0x4000, NULL, HFILL }},
{&hf_reserved,
{"Reserved", "scte35.reserved", FT_UINT16, BASE_HEX,
NULL, 0x3000, NULL, HFILL }},
{&hf_section_length,
{"Section length", "scte35.len", FT_UINT16, BASE_DEC,
NULL, 0x0FFF, NULL, HFILL}},
{&hf_protocol_version,
{"Protocol Version", "scte35.protocol_version", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{&hf_encrypted_packet,
{"Encrypted Packet", "scte35.encrypted_packet", FT_BOOLEAN, 40,
TFS(&tfs_encrypted_packet), G_GUINT64_CONSTANT(0x8000000000), NULL, HFILL}},
{&hf_encryption_algorithm,
{"Encryption Algorithm", "scte35.encryption_algorithm", FT_UINT40,
BASE_HEX | BASE_RANGE_STRING, RVALS(rv_encryption_algorithm),
G_GUINT64_CONSTANT(0x7E00000000), NULL, HFILL}},
{&hf_pts_adjustment,
{"PTS Adjustment", "scte35.pts_adjustment", FT_UINT40, BASE_DEC,
NULL, G_GUINT64_CONSTANT(0x1FFFFFFFF), NULL, HFILL}},
{&hf_cw_index,
{"Control Word Index", "scte35.cw_index", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL}},
{&hf_tier,
{"Authorisation Tier", "scte35.tier", FT_UINT16, BASE_DEC,
NULL, 0xFFF0, NULL, HFILL}},
{&hf_splice_command_length,
{"Command Length", "scte35.splice_command_length", FT_UINT16, BASE_DEC,
NULL, 0xFFF, NULL, HFILL}},
{&hf_splice_command_type,
{"Command Type", "scte35.splice_command_type", FT_UINT8,
BASE_HEX | BASE_RANGE_STRING, RVALS(rv_splice_command_type),
0, NULL, HFILL}},
{&hf_descriptor_loop_length,
{"Descriptor Loop Length", "scte35.desc_len", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL}},
{&hf_splice_descriptor_tag,
{"Tag", "scte35.splice_descriptor.tag", FT_UINT8,
BASE_HEX | BASE_RANGE_STRING, RVALS(rv_splice_descriptor_tag),
0, NULL, HFILL}},
{&hf_splice_descriptor_length,
{"Length", "scte35.splice_descriptor.length", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL}},
{&hf_splice_descriptor_identifier,
{"Descriptor ID", "scte35.splice_descriptor.identifier", FT_UINT32,
BASE_HEX, NULL, 0, NULL, HFILL}},
{&hf_descriptor_provider_avail_id,
{"Provider Avail ID", "scte35.splice_descriptor.provider_avail_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL}},
{&hf_descriptor_preroll,
{"Preroll", "scte35.splice_descriptor.preroll",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_descriptor_dtmf_count,
{"DTMF Count", "scte35.splice_descriptor.dtmf_count",
FT_UINT8, BASE_DEC, NULL, 0xE0, NULL, HFILL}},
{&hf_descriptor_dtmf_reserved,
{"DTMF Reserved", "scte35.splice_descriptor.dtmf_reserved",
FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL}},
{&hf_descriptor_dtmf,
{"DTMF", "scte35.splice_descriptor.dtmf",
FT_STRING, 0, NULL, 0, NULL, HFILL}},
{&hf_descriptor_event_id,
{"Segmentation Event ID", "scte35.splice_descriptor.event_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL}},
{&hf_descriptor_cancel_indicator,
{"Cancel Indicator", "scte35.splice_descriptor.cancel_indicator",
FT_BOOLEAN, 8, TFS(&tfs_descriptor_cancel_indicator), 0x80, NULL, HFILL}},
{&hf_descriptor_reserved0,
{"Reserved", "scte35.splice_descriptor.reserved0",
FT_UINT8, BASE_HEX, NULL, 0x7F, NULL, HFILL}},
{&hf_descriptor_psf,
{"Program Segmentation Flag", "scte35.splice_descriptor.psf",
FT_BOOLEAN, 8, TFS(&tfs_descriptor_psf), 0x80, NULL, HFILL}},
{&hf_descriptor_segmentation_duration_flag,
{"Segmentation Duration Flag", "scte35.splice_descriptor.sdf",
FT_BOOLEAN, 8, TFS(&tfs_descriptor_sdf), 0x40, NULL, HFILL}},
{&hf_descriptor_delivery_not_restricted_flag,
{"Delivery not Restricted", "scte35.splice_descriptor.dnr",
FT_BOOLEAN, 8, TFS(&tfs_descriptor_dnr), 0x20, NULL, HFILL}},
{&hf_descriptor_web_delivery_allowed_flag,
{"Web Delivery Allowed", "scte35.splice_descriptor.web_delivery_allowed",
FT_BOOLEAN, 8, TFS(&tfs_descriptor_web), 0x10, NULL, HFILL}},
{&hf_descriptor_no_regional_blackout_flag,
{"No Regional Blackout", "scte35.splice_descriptor.no_regional_blackout",
FT_BOOLEAN, 8, TFS(&tfs_descriptor_blackout), 0x08, NULL, HFILL}},
{&hf_descriptor_archive_allow_flag,
{"Archive Allowed", "scte35.splice_descriptor.archive_allowed",
FT_BOOLEAN, 8, TFS(&tfs_descriptor_archive), 0x04, NULL, HFILL}},
{&hf_descriptor_device_restrictions,
{"Device Restrictions", "scte35.splice_descriptor.device_restrictions",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING,
RVALS(scte35_device_restrictions), 0x03, NULL, HFILL}},
{&hf_descriptor_reserved1,
{"Reserved", "scte35.splice_descriptor.reserved1",
FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL}},
{&hf_descriptor_component_count,
{"Component Count", "scte35.splice_descriptor.component_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_descriptor_component_tag,
{"Component Tag", "scte35.splice_descriptor.component.tag",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL}},
{&hf_descriptor_component_reserved,
{"Reserved", "scte35.splice_descriptor.component.reserved",
FT_UINT8, BASE_HEX, NULL, 0xFE, NULL, HFILL}},
{&hf_descriptor_component_pts_offset,
{"PTS Offset", "scte35.splice_descriptor.component.pts_offset",
FT_UINT64, BASE_DEC, NULL, 0x1FFFFFFFF, NULL, HFILL}},
{&hf_descriptor_segmentation_duration,
{"Segmentation Duration", "scte35.splice_descriptor.segmentation_duration",
FT_UINT64, BASE_DEC, NULL, 0xFFFFFFFFFF, NULL, HFILL}},
{&hf_descriptor_segmentation_upid_type,
{"UPID Type", "scte35.splice_descriptor.upid_type",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING,
RVALS(scte35_segmentation_upid_type), 0, NULL, HFILL}},
{&hf_descriptor_segmentation_upid_length,
{"UPID Length", "scte35.splice_descriptor.upid_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_descriptor_segmentation_upid,
{"UPID", "scte35.splice_descriptor.upid",
FT_STRING, 0, NULL, 0, NULL, HFILL}},
{&hf_descriptor_segmentation_type_id,
{"Segmentation Type", "scte35.splice_descriptor.segmentation_type_id",
FT_UINT8, BASE_HEX | BASE_RANGE_STRING,
RVALS(scte35_segmentation_type_id), 0, NULL, HFILL}},
{&hf_descriptor_segment_num,
{"Segment Number", "scte35.splice_descriptor.segment_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_descriptor_segments_expected,
{"Segments Expected", "scte35.splice_descriptor.segments_expected",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{&hf_e_crc32,
{"Encrypted CRC32", "scte35.ecrc32", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL}},
{&hf_crc32,
{"CRC32", "scte35.crc", FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL}},
};
proto_scte35 = proto_register_protocol(
"SCTE-35 Splice Information",
"SCTE 35",
"scte35"
);
scte35_handle = register_dissector("scte35", dissect_scte35_splice_info, proto_scte35);
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_scte35, hf, array_length(hf));
scte35_cmd_dissector_table = register_dissector_table(
"scte35.splice_command_type", "SCTE-35 Command", proto_scte35, FT_UINT8,
BASE_HEX);
}
void
proto_reg_handoff_scte35(void)
{
dissector_add_uint("mpeg_sect.tid", SCTE35_TABLE_ID, scte35_handle);
}
