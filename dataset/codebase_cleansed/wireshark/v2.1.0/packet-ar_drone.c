static int
dissect_ar_drone(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset, length;
gint master_offset = 0;
proto_item *ti, *sub_item;
proto_tree *ar_tree, *sub_tree;
char *command;
guint32 dword;
if (tvb_captured_length(tvb) < 4)
return 0;
dword = tvb_get_ntoh24(tvb, 0);
if (dword != 0x41542a)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ar_drone");
col_set_str(pinfo->cinfo, COL_INFO, "AR Drone Packet");
ti = proto_tree_add_item(tree, proto_ar_drone, tvb, 0, -1, ENC_NA);
ar_tree = proto_item_add_subtree(ti, ett_ar_drone);
while (tvb_reported_length_remaining(tvb, master_offset) > 3)
{
offset = tvb_find_guint8(tvb, master_offset, -1, '=');
if (offset < master_offset)
return master_offset;
command = tvb_get_string_enc(wmem_packet_scope(), tvb, master_offset, offset-master_offset, ENC_ASCII|ENC_NA);
sub_item = proto_tree_add_string(ar_tree, hf_command, tvb, master_offset, -1,
tvb_get_string_enc(wmem_packet_scope(), tvb, master_offset+3, offset-master_offset-3, ENC_ASCII|ENC_NA));
if (!strncmp(command, "AT*PCMD", 7))
{
guint8 PCMD_byte;
const char *PCMD_str;
sub_tree = proto_item_add_subtree(sub_item, ett_PCMD);
offset = master_offset + 8;
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_PCMD_id, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_PCMD_flag, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
ti = proto_tree_add_item(sub_tree, hf_PCMD_roll, tvb, offset, length, ENC_ASCII|ENC_NA);
PCMD_byte = tvb_get_guint8(tvb, offset);
if (PCMD_byte == 0x30)
{
PCMD_str = " (NO CHANGE)";
}
else if (PCMD_byte == 0x2d)
{
PCMD_byte = tvb_get_guint8(tvb, offset + 1);
if (PCMD_byte == 0x30)
{
PCMD_str = " (NO CHANGE)";
}
else
{
PCMD_str = " (ROLL LEFT)";
}
}
else
{
PCMD_str = " (ROLL RIGHT)";
}
proto_item_append_text(ti, "%s", PCMD_str);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
ti = proto_tree_add_item(sub_tree, hf_PCMD_pitch, tvb, offset, length, ENC_ASCII|ENC_NA);
PCMD_byte = tvb_get_guint8(tvb, offset);
if (PCMD_byte == 0x30)
{
PCMD_str = " (NO CHANGE)";
}
else if (PCMD_byte == 0x2d)
{
PCMD_byte = tvb_get_guint8(tvb, offset + 1);
if (PCMD_byte == 0x30)
{
PCMD_str = " (NO CHANGE)";
}
else
{
PCMD_str = " (PITCH FORWARD)";
}
}
else
{
PCMD_str = " (PITCH BACKWARD)";
}
proto_item_append_text(ti, "%s", PCMD_str);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
ti = proto_tree_add_item(sub_tree, hf_PCMD_gaz, tvb, offset, length, ENC_ASCII|ENC_NA);
PCMD_byte = tvb_get_guint8(tvb, offset);
if (PCMD_byte == 0x30)
{
PCMD_str = " (NO CHANGE)";
}
else if (PCMD_byte == 0x2d)
{
PCMD_byte = tvb_get_guint8(tvb, offset + 1);
if (PCMD_byte == 0x30)
{
PCMD_str = " (NO CHANGE)";
}
else
{
PCMD_str = " (DECREASE VERT SPEED)";
}
}
else
{
PCMD_str = " (INCREASE VERT SPEED)";
}
proto_item_append_text(ti, "%s", PCMD_str);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
ti = proto_tree_add_item(sub_tree, hf_PCMD_yaw, tvb, offset, length, ENC_ASCII|ENC_NA);
PCMD_byte = tvb_get_guint8(tvb, offset);
if (PCMD_byte == 0x30)
{
PCMD_str = " (NO CHANGE)";
}
else if (PCMD_byte == 0x2d)
{
PCMD_byte = tvb_get_guint8(tvb, offset + 1);
if (PCMD_byte == 0x30)
{
PCMD_str = " (NO CHANGE)";
}
else
{
PCMD_str = " (ROTATE LEFT)";
}
}
else
{
PCMD_str = " (ROTATE RIGHT)";
}
proto_item_append_text(ti, "%s", PCMD_str);
offset += (length + 1);
}
else if (!strncmp(command, "AT*REF", 6))
{
sub_tree = proto_item_add_subtree(sub_item, ett_REF);
offset = master_offset + 7;
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_REF_id, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
proto_tree_add_item(sub_tree, hf_REF_ctrl, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
} else if (!strncmp(command, "AT*CONFIG_IDS", 13))
{
sub_tree = proto_item_add_subtree(sub_item, ett_CONFIG_ID);
offset = master_offset + 14;
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_CONFIG_ID_seq, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_CONFIG_ID_session, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_CONFIG_ID_user, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
proto_tree_add_item(sub_tree, hf_CONFIG_ID_app, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
} else if (!strncmp(command, "AT*ANIM", 7))
{
sub_tree = proto_item_add_subtree(sub_item, ett_ANIM);
offset = master_offset + 8;
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_ANIM_seq, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_ANIM_anim, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
proto_tree_add_item(sub_tree, hf_ANIM_sec, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
} else if (!strncmp(command, "AT*FTRIM", 8))
{
sub_tree = proto_item_add_subtree(sub_item, ett_FTRIM);
offset = master_offset + 9;
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
proto_item_append_text(sub_item, " (Sets the reference for the horizontal plane)");
proto_tree_add_item(sub_tree, hf_FTRIM_seq, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
} else if (!strncmp(command, "AT*CONFIG", 9))
{
sub_tree = proto_item_add_subtree(sub_item, ett_CONFIG);
offset = master_offset + 10;
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_CONFIG_seq, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_CONFIG_name, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
proto_tree_add_item(sub_tree, hf_CONFIG_val, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
} else if (!strncmp(command, "AT*LED", 6))
{
sub_tree = proto_item_add_subtree(sub_item, ett_LED);
offset = master_offset + 7;
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_LED_seq, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_LED_anim, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_LED_freq, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
proto_tree_add_item(sub_tree, hf_LED_sec, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
} else if (!strncmp(command, "AT*COMWDG", 9))
{
sub_tree = proto_item_add_subtree(sub_item, ett_COMWDG);
offset = master_offset + 10;
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
proto_tree_add_item(sub_tree, hf_COMWDG, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
}else if (!strncmp(command, "AT*CTRL", 7))
{
sub_tree = proto_item_add_subtree(sub_item, ett_CTRL);
offset = master_offset + 8;
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
proto_tree_add_item(sub_tree, hf_CTRL_seq, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, ',') - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_COMMA);
return offset;
}
ti = proto_tree_add_item(sub_tree, hf_CTRL_mode, tvb, offset, length, ENC_ASCII|ENC_NA);
proto_item_append_text(ti, "%s",
str_to_str(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII|ENC_NA), CTRL_mode_vs, " (Unknown Mode)"));
offset += (length + 1);
length = tvb_find_guint8(tvb, offset, -1, 0x0d) - offset;
if (length < 0) {
expert_add_info(pinfo, sub_item, &ei_NO_CR);
return offset;
}
proto_tree_add_item(sub_tree, hf_CTRL_fsize, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += (length + 1);
}
else
{
return master_offset;
}
proto_item_set_len(sub_item, offset-master_offset);
master_offset = offset;
}
return master_offset;
}
void
proto_register_ar_drone(void)
{
static hf_register_info hf[] = {
{ &hf_command,
{ "Command", "ar_drone.command",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_PCMD_id,
{ "Sequence Number", "ar_drone.pcmd.id",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Progressive Command ID", HFILL }
},
{ &hf_PCMD_flag,
{ "Flag", "ar_drone.pcmd.flag",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Progressive Command Flag", HFILL }
},
{ &hf_PCMD_roll,
{ "Roll", "ar_drone.pcmd.roll",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Progressive Command Roll", HFILL }
},
{ &hf_PCMD_pitch,
{ "Pitch", "ar_drone.pcmd.pitch",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Progressive Command Pitch", HFILL }
},
{ &hf_PCMD_gaz,
{ "Gaz", "ar_drone.pcmd.gaz",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Progressive Command Gaz", HFILL }
},
{ &hf_PCMD_yaw,
{ "Yaw", "ar_drone.pcmd.yaw",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Progressive Command Yaw", HFILL }
},
{ &hf_REF_id,
{ "Sequence Number", "ar_drone.ref.id",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Reference ID", HFILL }
},
{ &hf_REF_ctrl,
{ "Control Command", "ar_drone.ref.ctrl",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_FTRIM_seq,
{ "Sequence Number", "ar_drone.ftrim.seq",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Flap Trim / Horizontal Plane Reference", HFILL }
},
{ &hf_CONFIG_ID_seq,
{ "Sequence Number", "ar_drone.configids.seq",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Configuration ID sequence number", HFILL }
},
{ &hf_CONFIG_ID_session,
{ "Current Session ID", "ar_drone.configids.session",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Configuration ID current session ID", HFILL }
},
{ &hf_CONFIG_ID_user,
{ "Current User ID", "ar_drone.configids.user",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Configuration ID current user ID", HFILL }
},
{ &hf_CONFIG_ID_app,
{ "Current Application ID", "ar_drone.configids.app",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Configuration ID current application ID", HFILL }
},
{ &hf_COMWDG,
{ "Command WatchDog Request", "ar_drone.comwdg",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Command WatchDog Reset request", HFILL }
},
{ &hf_CONFIG_seq,
{ "Sequence Number", "ar_drone.config.seq",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Configuration Seq Num", HFILL }
},
{ &hf_CONFIG_name,
{ "Option Name", "ar_drone.config.name",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_CONFIG_val,
{ "Option Parameter", "ar_drone.config.val",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_LED_seq,
{ "Sequence Number", "ar_drone.led.seq",
FT_STRING, BASE_NONE,
NULL, 0x0,
"LED Sequence Number", HFILL }
},
{ &hf_LED_anim,
{ "Selected Animation", "ar_drone.led.anim",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Selected LED Animation", HFILL }
},
{ &hf_LED_freq,
{ "Animation Frequency", "ar_drone.led.freq",
FT_STRING, BASE_NONE,
NULL, 0x0,
"LED Animation Frequency", HFILL }
},
{ &hf_LED_sec,
{ "LED Animation Length (Seconds)", "ar_drone.led.sec",
FT_STRING, BASE_NONE,
NULL, 0x0,
"LED Anim Length", HFILL }
},
{ &hf_ANIM_seq,
{ "Animation Sequence Number", "ar_drone.anim.seq",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Movment(Animation) Sequence #", HFILL }
},
{ &hf_ANIM_anim,
{ "Selected Animation Number", "ar_drone.anim.num",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Movment(Animation) to Play", HFILL }
},
{ &hf_ANIM_sec,
{ "Animation Duration (seconds)", "ar_drone.anim.sec",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Movment(Animation) Time in Seconds", HFILL }
},
{ &hf_CTRL_seq,
{ "Sequence Number", "ar_drone.ctrl.seq",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_CTRL_mode,
{ "Control Mode", "ar_drone.ctrl.mode",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_CTRL_fsize,
{ "Firmware Update File Size (0 for no update)", "ar_drone.ctrl.filesize",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_ar_drone,
&ett_PCMD,
&ett_REF,
&ett_FTRIM,
&ett_CONFIG,
&ett_CONFIG_ID,
&ett_COMWDG,
&ett_LED,
&ett_ANIM,
&ett_CTRL
};
static ei_register_info ei[] = {
{ &ei_NO_COMMA, { "ar_drone.no_comma", PI_MALFORMED, PI_ERROR, "Comma delimiter not found", EXPFILL }},
{ &ei_NO_CR, { "ar_drone.no_cr", PI_MALFORMED, PI_ERROR, "Carriage return delimiter (0x0d) not found", EXPFILL }},
};
module_t *drone_module;
expert_module_t* expert_drone;
proto_ar_drone = proto_register_protocol (
"AR Drone Packet",
"AR Drone",
"ar_drone"
);
proto_register_field_array(proto_ar_drone, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_drone = expert_register_protocol(proto_ar_drone);
expert_register_field_array(expert_drone, ei, array_length(ei));
drone_module = prefs_register_protocol(proto_ar_drone, NULL);
prefs_register_uint_preference(drone_module, "udp.port",
"AR Drone UDP Port",
"AR Drone UDP port",
10,
&ar_drone_port);
}
void
proto_reg_handoff_ar_drone(void)
{
static dissector_handle_t ar_drone_handle;
static guint old_port = 0;
static gboolean initialized = FALSE;
if (initialized == FALSE)
{
ar_drone_handle = create_dissector_handle(dissect_ar_drone, proto_ar_drone);
heur_dissector_add("udp", dissect_ar_drone, "AR Drone over UDP", "ar_drone_udp", proto_ar_drone, HEURISTIC_ENABLE);
initialized = TRUE;
}
if (old_port != 0 && old_port != ar_drone_port)
{
dissector_delete_uint("udp.port", old_port, ar_drone_handle);
}
if (ar_drone_port != 0 && old_port != ar_drone_port)
{
dissector_add_uint("udp.port", ar_drone_port, ar_drone_handle);
}
old_port = ar_drone_port;
}
