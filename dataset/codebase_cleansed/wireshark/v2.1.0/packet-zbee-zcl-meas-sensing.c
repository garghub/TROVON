static int
dissect_zbee_zcl_illum_meas(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
static void
dissect_zcl_illum_meas_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_illum_meas_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_MIN_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_illum_meas_min_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_MAX_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_illum_meas_max_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_TOLERANCE:
proto_tree_add_item(tree, hf_zbee_zcl_illum_meas_tolerance, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_LIGHT_SENSOR_TYPE:
proto_tree_add_item(tree, hf_zbee_zcl_illum_meas_sensor_type, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
decode_illum_meas_value(gchar *s, guint16 value)
{
if (value == ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_TOO_LOW_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Value too low to be measured");
else if (value == ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_INVALID_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d (=%f [lx])", value, pow(10,value/10000.0)-1);
return;
}
static void
decode_illum_meas_min_value(gchar *s, guint16 value)
{
if ( (value < ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_MIN_LO_VALUE) ||
(value > ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_MIN_HI_VALUE) )
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d (=%f [lx])", value, pow(10,value/10000.0)-1);
return;
}
static void
decode_illum_meas_max_value(gchar *s, guint16 value)
{
if ( (value < ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_MAX_LO_VALUE) ||
(value > ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_MAX_HI_VALUE) )
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d (=%f [lx])", value, pow(10,value/10000.0)-1);
return;
}
static void
decode_illum_meas_tolerance(gchar *s, guint16 value)
{
if (value > ZBEE_ZCL_ATTR_ID_ILLUM_MEAS_TOL_HI_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d", value);
return;
}
void
proto_register_zbee_zcl_illum_meas(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_illum_meas_attr_id,
{ "Attribute", "zbee_zcl_meas_sensing.illummeas.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_illum_meas_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_illum_meas_measured_value,
{ "Measured Value", "zbee_zcl_meas_sensing.illummeas.attr.value", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_illum_meas_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_illum_meas_min_measured_value,
{ "Min Measured Value", "zbee_zcl_meas_sensing.illummeas.attr.value.min", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_illum_meas_min_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_illum_meas_max_measured_value,
{ "Max Measured Value", "zbee_zcl_meas_sensing.illummeas.attr.value.max", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_illum_meas_max_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_illum_meas_tolerance,
{ "Tolerance", "zbee_zcl_meas_sensing.illummeas.attr.tolerance", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_illum_meas_tolerance),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_illum_meas_sensor_type,
{ "Sensor Type", "zbee_zcl_meas_sensing.illummeas.attr.sensor_type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_illum_meas_sensor_type_names),
0x00, NULL, HFILL } }
};
proto_zbee_zcl_illum_meas = proto_register_protocol("ZigBee ZCL Illuminance Meas.", "ZCL Illuminance Meas.", ZBEE_PROTOABBREV_ZCL_ILLUMMEAS);
proto_register_field_array(proto_zbee_zcl_illum_meas, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_ILLUMMEAS, dissect_zbee_zcl_illum_meas, proto_zbee_zcl_illum_meas);
}
void
proto_reg_handoff_zbee_zcl_illum_meas(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_illum_meas,
ett_zbee_zcl_illum_meas,
ZBEE_ZCL_CID_ILLUMINANCE_MEASUREMENT,
hf_zbee_zcl_illum_meas_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_illum_meas_attr_data
);
}
static int
dissect_zbee_zcl_illum_level_sen(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
static void
dissect_zcl_illum_level_sen_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_ILLUM_LEVEL_SEN_LEVEL_STATUS:
proto_tree_add_item(tree, hf_zbee_zcl_illum_level_sen_level_status, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_ILLUM_LEVEL_SEN_LIGHT_SENSOR_TYPE:
proto_tree_add_item(tree, hf_zbee_zcl_illum_level_sen_light_sensor_type, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_ILLUM_LEVEL_SEN_ILLUM_TARGET_LEVEL:
proto_tree_add_item(tree, hf_zbee_zcl_illum_level_sen_illum_target_level, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
decode_illum_level_sen_target_level(gchar *s, guint16 value)
{
if (value == ZBEE_ZCL_ATTR_ID_ILLUM_LEVEL_SEN_TOO_LOW_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Value too low to be measured");
else if (value == ZBEE_ZCL_ATTR_ID_ILLUM_LEVEL_SEN_INVALID_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d (=%f [lx])", value, pow(10,value/10000.0)-1);
return;
}
void
proto_register_zbee_zcl_illum_level_sen(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_illum_level_sen_attr_id,
{ "Attribute", "zbee_zcl_meas_sensing.illumlevelsen.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_illum_level_sen_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_illum_level_sen_level_status,
{ "Level Status", "zbee_zcl_meas_sensing.illumlevelsen.attr.level_status", FT_UINT8, BASE_HEX, VALS(zbee_zcl_illum_level_sen_level_status_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_illum_level_sen_light_sensor_type,
{ "Light Sensor Type", "zbee_zcl_meas_sensing.illumlevelsen.attr.light_sensor_type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_illum_level_sen_sensor_type_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_illum_level_sen_illum_target_level,
{ "Target Level", "zbee_zcl_meas_sensing.illumlevelsen.attr.target_level", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_illum_level_sen_target_level),
0x00, NULL, HFILL } }
};
proto_zbee_zcl_illum_level_sen = proto_register_protocol("ZigBee ZCL Illuminance Level Sensing", "ZCL Illuminance Level Sensing", ZBEE_PROTOABBREV_ZCL_ILLUMLEVELSEN);
proto_register_field_array(proto_zbee_zcl_illum_level_sen, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_ILLUMLEVELSEN, dissect_zbee_zcl_illum_level_sen, proto_zbee_zcl_illum_level_sen);
}
void
proto_reg_handoff_zbee_zcl_illum_level_sen(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_illum_level_sen,
ett_zbee_zcl_illum_level_sen,
ZBEE_ZCL_CID_ILLUMINANCE_LEVEL_SENSING,
hf_zbee_zcl_illum_level_sen_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_illum_level_sen_attr_data
);
}
static int
dissect_zbee_zcl_temp_meas(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
static void
dissect_zcl_temp_meas_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_TEMP_MEAS_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_temp_meas_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_TEMP_MEAS_MIN_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_temp_meas_min_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_TEMP_MEAS_MAX_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_temp_meas_max_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_TEMP_MEAS_TOLERANCE:
proto_tree_add_item(tree, hf_zbee_zcl_temp_meas_tolerance, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
decode_temp_meas_value(gchar *s, gint16 value)
{
if (value == (gint16)ZBEE_ZCL_ATTR_ID_TEMP_MEAS_INVALID_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%.2f [" UTF8_DEGREE_SIGN "C]", value/100.0);
return;
}
static void
decode_temp_meas_min_value(gchar *s, gint16 value)
{
if ( (value < (gint16)ZBEE_ZCL_ATTR_ID_TEMP_MEAS_MIN_LO_VALUE) ||
(value > (gint16)ZBEE_ZCL_ATTR_ID_TEMP_MEAS_MIN_HI_VALUE) )
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%.2f [" UTF8_DEGREE_SIGN "C]", value/100.0);
return;
}
static void
decode_temp_meas_max_value(gchar *s, gint16 value)
{
if (value < (gint16)ZBEE_ZCL_ATTR_ID_TEMP_MEAS_MAX_LO_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%.2f [" UTF8_DEGREE_SIGN "C]", value/100.0);
return;
}
static void
decode_temp_meas_tolerance(gchar *s, guint16 value)
{
if (value > ZBEE_ZCL_ATTR_ID_TEMP_MEAS_TOL_HI_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%d [" UTF8_DEGREE_SIGN "C]", value/100, value%100);
return;
}
void
proto_register_zbee_zcl_temp_meas(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_temp_meas_attr_id,
{ "Attribute", "zbee_zcl_meas_sensing.tempmeas.attr_idd", FT_UINT16, BASE_HEX, VALS(zbee_zcl_temp_meas_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_temp_meas_measured_value,
{ "Measured Value", "zbee_zcl_meas_sensing.tempmeas.attr.value", FT_INT16, BASE_CUSTOM, CF_FUNC(decode_temp_meas_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_temp_meas_min_measured_value,
{ "Min Measured Value", "zbee_zcl_meas_sensing.tempmeas.attr.value.min", FT_INT16, BASE_CUSTOM, CF_FUNC(decode_temp_meas_min_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_temp_meas_max_measured_value,
{ "Max Measured Value", "zbee_zcl_meas_sensing.tempmeas.attr.value.max", FT_INT16, BASE_CUSTOM, CF_FUNC(decode_temp_meas_max_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_temp_meas_tolerance,
{ "Tolerance", "zbee_zcl_meas_sensing.tempmeas.attr.tolerance", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_temp_meas_tolerance),
0x00, NULL, HFILL } }
};
proto_zbee_zcl_temp_meas = proto_register_protocol("ZigBee ZCL Temperature Meas.", "ZCL Temperature Meas.", ZBEE_PROTOABBREV_ZCL_TEMPMEAS);
proto_register_field_array(proto_zbee_zcl_temp_meas, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_TEMPMEAS, dissect_zbee_zcl_temp_meas, proto_zbee_zcl_temp_meas);
}
void
proto_reg_handoff_zbee_zcl_temp_meas(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_temp_meas,
ett_zbee_zcl_temp_meas,
ZBEE_ZCL_CID_TEMPERATURE_MEASUREMENT,
hf_zbee_zcl_temp_meas_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_temp_meas_attr_data
);
}
static int
dissect_zbee_zcl_press_meas(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
static void
dissect_zcl_press_meas_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_MIN_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_min_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_MAX_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_max_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_TOLERANCE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_tolerance, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_SCALED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_scaled_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_MIN_SCALED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_min_scaled_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_MAX_SCALED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_max_scaled_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_SCALED_TOLERANCE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_scaled_tolerance, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_PRESS_MEAS_SCALE:
proto_tree_add_item(tree, hf_zbee_zcl_press_meas_scale, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
decode_press_meas_value(gchar *s, gint16 value)
{
if (value == (gint16)ZBEE_ZCL_ATTR_ID_PRESS_MEAS_INVALID_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value");
if (value < (gint16)ZBEE_ZCL_ATTR_ID_PRESS_MEAS_MIN_LO_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%d [kPa]", value/10, value%10);
return;
}
static void
decode_press_meas_min_value(gchar *s, gint16 value)
{
if (value > (gint16)ZBEE_ZCL_ATTR_ID_PRESS_MEAS_MIN_HI_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%d [kPa]", value/10, value%10);
return;
}
static void
decode_press_meas_max_value(gchar *s, gint16 value)
{
if (value < (gint16)ZBEE_ZCL_ATTR_ID_PRESS_MEAS_MAX_LO_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%d [kPa]", value/10, value%10);
return;
}
static void
decode_press_meas_tolerance(gchar *s, guint16 value)
{
if (value > (guint16)ZBEE_ZCL_ATTR_ID_PRESS_MEAS_TOL_HI_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%d [kPa]", value/10, value%10);
return;
}
void
proto_register_zbee_zcl_press_meas(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_press_meas_attr_id,
{ "Attribute", "zbee_zcl_meas_sensing.pressmeas.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_press_meas_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_measured_value,
{ "Measured Value", "zbee_zcl_meas_sensing.pressmeas.attr.value", FT_INT16, BASE_CUSTOM, CF_FUNC(decode_press_meas_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_min_measured_value,
{ "Min Measured Value", "zbee_zcl_meas_sensing.pressmeas.attr.value.min", FT_INT16, BASE_CUSTOM, CF_FUNC(decode_press_meas_min_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_max_measured_value,
{ "Max Measured Value", "zbee_zcl_meas_sensing.pressmeas.attr.value.max", FT_INT16, BASE_CUSTOM, CF_FUNC(decode_press_meas_max_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_tolerance,
{ "Tolerance", "zbee_zcl_meas_sensing.pressmeas.attr.tolerance", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_press_meas_tolerance),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_scaled_value,
{ "Scaled Value", "zbee_zcl_meas_sensing.pressmeas.attr.scaled_value", FT_INT16, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_min_scaled_value,
{ "Min Scaled Value", "zbee_zcl_meas_sensing.pressmeas.attr.scaled_value.min", FT_INT16, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_max_scaled_value,
{ "Max Scaled Value", "zbee_zcl_meas_sensing.pressmeas.attr.scaled_value.max", FT_INT16, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_scaled_tolerance,
{ "Scaled Tolerance", "zbee_zcl_meas_sensing.pressmeas.attr.scaled_tolerance", FT_UINT16, BASE_DEC, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_press_meas_scale,
{ "Scale", "zbee_zcl_meas_sensing.pressmeas.attr.scale", FT_UINT8, BASE_DEC, NULL,
0x00, NULL, HFILL } }
};
proto_zbee_zcl_press_meas = proto_register_protocol("ZigBee ZCL Pressure Meas.", "ZCL Pressure Meas.", ZBEE_PROTOABBREV_ZCL_PRESSMEAS);
proto_register_field_array(proto_zbee_zcl_press_meas, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_PRESSMEAS, dissect_zbee_zcl_press_meas, proto_zbee_zcl_press_meas);
}
void
proto_reg_handoff_zbee_zcl_press_meas(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_press_meas,
ett_zbee_zcl_press_meas,
ZBEE_ZCL_CID_PRESSURE_MEASUREMENT,
hf_zbee_zcl_press_meas_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_press_meas_attr_data
);
}
static int
dissect_zbee_zcl_flow_meas(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
static void
dissect_zcl_flow_meas_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_FLOW_MEAS_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_flow_meas_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_FLOW_MEAS_MIN_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_flow_meas_min_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_FLOW_MEAS_MAX_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_flow_meas_max_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_FLOW_MEAS_TOLERANCE:
proto_tree_add_item(tree, hf_zbee_zcl_flow_meas_tolerance, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
decode_flow_meas_value(gchar *s, guint16 value)
{
if (value == ZBEE_ZCL_ATTR_ID_FLOW_MEAS_TOO_LOW_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Value too low to be measured");
else if (value == ZBEE_ZCL_ATTR_ID_FLOW_MEAS_INVALID_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d (=%f [m^3/h])", value, value/10.0);
return;
}
static void
decode_flow_meas_min_value(gchar *s, guint16 value)
{
if ( (value > ZBEE_ZCL_ATTR_ID_FLOW_MEAS_MIN_LO_VALUE) ||
(value > ZBEE_ZCL_ATTR_ID_FLOW_MEAS_MIN_HI_VALUE) )
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d (=%f [m^3/h])", value, value/10.0);
return;
}
static void
decode_flow_meas_max_value(gchar *s, guint16 value)
{
if ( (value < ZBEE_ZCL_ATTR_ID_FLOW_MEAS_MAX_LO_VALUE) ||
(value > ZBEE_ZCL_ATTR_ID_FLOW_MEAS_MAX_HI_VALUE) )
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d (=%f [m^3/h])", value, value/10.0);
return;
}
static void
decode_flow_meas_tolerance(gchar *s, guint16 value)
{
if (value > ZBEE_ZCL_ATTR_ID_FLOW_MEAS_TOL_HI_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d", value);
return;
}
void
proto_register_zbee_zcl_flow_meas(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_flow_meas_attr_id,
{ "Attribute", "zbee_zcl_meas_sensing.flowmeas.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_flow_meas_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_flow_meas_measured_value,
{ "Measured Value", "zbee_zcl_meas_sensing.flowmeas.attr.value", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_flow_meas_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_flow_meas_min_measured_value,
{ "Min Measured Value", "zbee_zcl_meas_sensing.flowmeas.attr.value.min", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_flow_meas_min_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_flow_meas_max_measured_value,
{ "Max Measured Value", "zbee_zcl_meas_sensing.flowmeas.attr.value.max", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_flow_meas_max_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_flow_meas_tolerance,
{ "Tolerance", "zbee_zcl_meas_sensing.flowmeas.attr.tolerance", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_flow_meas_tolerance),
0x00, NULL, HFILL } }
};
proto_zbee_zcl_flow_meas = proto_register_protocol("ZigBee ZCL Flow Meas.", "ZCL Flow Meas.", ZBEE_PROTOABBREV_ZCL_FLOWMEAS);
proto_register_field_array(proto_zbee_zcl_flow_meas, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_FLOWMEAS, dissect_zbee_zcl_flow_meas, proto_zbee_zcl_flow_meas);
}
void
proto_reg_handoff_zbee_zcl_flow_meas(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_flow_meas,
ett_zbee_zcl_flow_meas,
ZBEE_ZCL_CID_FLOW_MEASUREMENT,
hf_zbee_zcl_flow_meas_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_flow_meas_attr_data
);
}
static int
dissect_zbee_zcl_relhum_meas(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
static void
dissect_zcl_relhum_meas_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_RELHUM_MEAS_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_relhum_meas_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_RELHUM_MEAS_MIN_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_relhum_meas_min_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_RELHUM_MEAS_MAX_MEASURED_VALUE:
proto_tree_add_item(tree, hf_zbee_zcl_relhum_meas_max_measured_value, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_RELHUM_MEAS_TOLERANCE:
proto_tree_add_item(tree, hf_zbee_zcl_relhum_meas_tolerance, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
static void
decode_relhum_meas_value(gchar *s, guint16 value)
{
if (value == ZBEE_ZCL_ATTR_ID_RELHUM_MEAS_INVALID_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid value");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%02d [%%]", value/100, value%100);
return;
}
static void
decode_relhum_meas_min_value(gchar *s, guint16 value)
{
if (value > ZBEE_ZCL_ATTR_ID_RELHUM_MEAS_MIN_HI_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%02d [%%]", value/100, value%100);
return;
}
static void
decode_relhum_meas_max_value(gchar *s, guint16 value)
{
if (value > ZBEE_ZCL_ATTR_ID_RELHUM_MEAS_MAX_HI_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%02d [%%]", value/100, value%100);
return;
}
static void
decode_relhum_meas_tolerance(gchar *s, guint16 value)
{
if (value > ZBEE_ZCL_ATTR_ID_RELHUM_MEAS_TOL_HI_VALUE)
g_snprintf(s, ITEM_LABEL_LENGTH, "Out of range");
else
g_snprintf(s, ITEM_LABEL_LENGTH, "%d.%02d [%%]", value/100, value%100);
return;
}
void
proto_register_zbee_zcl_relhum_meas(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_relhum_meas_attr_id,
{ "Attribute", "zbee_zcl_meas_sensing.relhummeas.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_relhum_meas_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_relhum_meas_measured_value,
{ "Measured Value", "zbee_zcl_meas_sensing.relhummeas.attr.value", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_relhum_meas_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_relhum_meas_min_measured_value,
{ "Min Measured Value", "zbee_zcl_meas_sensing.relhummeas.attr.value.min", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_relhum_meas_min_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_relhum_meas_max_measured_value,
{ "Max Measured Value", "zbee_zcl_meas_sensing.relhummeas.attr.value.max", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_relhum_meas_max_value),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_relhum_meas_tolerance,
{ "Tolerance", "zbee_zcl_meas_sensing.relhummeas.attr.tolerance", FT_UINT16, BASE_CUSTOM, CF_FUNC(decode_relhum_meas_tolerance),
0x00, NULL, HFILL } }
};
proto_zbee_zcl_relhum_meas = proto_register_protocol("ZigBee ZCL Rel. Humidity Meas.", "ZCL Relative Humidity Meas.", ZBEE_PROTOABBREV_ZCL_RELHUMMEAS);
proto_register_field_array(proto_zbee_zcl_relhum_meas, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_RELHUMMEAS, dissect_zbee_zcl_relhum_meas, proto_zbee_zcl_relhum_meas);
}
void
proto_reg_handoff_zbee_zcl_relhum_meas(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_relhum_meas,
ett_zbee_zcl_relhum_meas,
ZBEE_ZCL_CID_REL_HUMIDITY_MEASUREMENT,
hf_zbee_zcl_relhum_meas_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_relhum_meas_attr_data
);
}
static int
dissect_zbee_zcl_occ_sen(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void* data _U_)
{
return tvb_captured_length(tvb);
}
static void
dissect_zcl_occ_sen_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
static const int *occupancy[] = {
&hf_zbee_zcl_occ_sen_occupancy,
NULL
};
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_OCC_SEN_OCCUPANCY:
proto_tree_add_bitmask(tree, tvb, *offset, hf_zbee_zcl_occ_sen_occupancy, ett_zbee_zcl_occ, occupancy, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_OCC_SEN_OCC_SENSOR_TYPE:
proto_tree_add_item(tree, hf_zbee_zcl_occ_sen_occ_sensor_type, tvb, *offset, 1, ENC_LITTLE_ENDIAN);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_OCC_SEN_PIR_OCC_TO_UNOCC_DELAY:
case ZBEE_ZCL_ATTR_ID_OCC_SEN_PIR_UNOCC_TO_OCC_DELAY:
case ZBEE_ZCL_ATTR_ID_OCC_SEN_PIR_UNOCC_TO_OCC_THOLD:
case ZBEE_ZCL_ATTR_ID_OCC_SEN_USONIC_OCC_TO_UNOCC_DELAY:
case ZBEE_ZCL_ATTR_ID_OCC_SEN_USONIC_UNOCC_TO_OCC_DELAY:
case ZBEE_ZCL_ATTR_ID_OCC_SEN_USONIC_UNOCC_TO_OCC_THOLD:
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_occ_sen(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_occ_sen_attr_id,
{ "Attribute", "zbee_zcl_meas_sensing.occsen.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_occ_sen_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_occ_sen_occupancy,
{ "Occupancy", "zbee_zcl_meas_sensing.occsen.attr.occupancy", FT_UINT8, BASE_HEX, VALS(zbee_zcl_occ_sen_sensed_occ_names),
ZBEE_ZCL_OCCUPANCY_SENSED_OCC, NULL, HFILL } },
{ &hf_zbee_zcl_occ_sen_occ_sensor_type,
{ "Occupancy Sensor Type", "zbee_zcl_meas_sensing.occsen.attr.occ_sensor_type", FT_UINT8, BASE_HEX, VALS(zbee_zcl_occ_sen_sensor_type_names),
0x00, NULL, HFILL } }
};
proto_zbee_zcl_occ_sen = proto_register_protocol("ZigBee ZCL Occupancy Sensing", "ZCL Occupancy Sensing", ZBEE_PROTOABBREV_ZCL_OCCSEN);
proto_register_field_array(proto_zbee_zcl_occ_sen, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_OCCSEN, dissect_zbee_zcl_occ_sen, proto_zbee_zcl_occ_sen);
}
void
proto_reg_handoff_zbee_zcl_occ_sen(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_occ_sen,
ett_zbee_zcl_occ_sen,
ZBEE_ZCL_CID_ILLUMINANCE_LEVEL_SENSING,
hf_zbee_zcl_occ_sen_attr_id,
-1, -1,
(zbee_zcl_fn_attr_data)dissect_zcl_occ_sen_attr_data
);
}
