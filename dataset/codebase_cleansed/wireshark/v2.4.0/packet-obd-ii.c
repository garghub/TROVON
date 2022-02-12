static gboolean
dissect_obdii_common_temperature(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree, int hf_field)
{
if (oinfo->value_bytes == 1)
{
gint16 val = ((int) oinfo->valueA) - 40;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %d " UTF8_DEGREE_SIGN "C", val);
proto_tree_add_int(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
return TRUE;
}
return FALSE;
}
static gboolean
dissect_obdii_common_percent(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree, int hf_field)
{
if (oinfo->value_bytes == 1)
{
double val = (100 * oinfo->valueA) / 255.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.2f %%", val);
proto_tree_add_double(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
return TRUE;
}
return FALSE;
}
static gboolean
dissect_obdii_common_percent_neg(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree, int hf_field)
{
if (oinfo->value_bytes == 1)
{
double val = ((100 * oinfo->valueA) / 128.0) - 100.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.2f %%", val);
proto_tree_add_double(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
return TRUE;
}
return FALSE;
}
static gboolean
dissect_obdii_common_fuel_rail_pressure(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree, int hf_field)
{
if (oinfo->value_bytes == 2)
{
guint val = 10 * (256 * oinfo->valueA + oinfo->valueB);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u kPa", val);
proto_tree_add_uint(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
return TRUE;
}
return FALSE;
}
static gboolean
dissect_obdii_common_absolute_pressure(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree, int hf_field)
{
if (oinfo->value_bytes == 1)
{
guint8 val = oinfo->valueA;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u kPa", val);
proto_tree_add_uint(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
return TRUE;
}
return FALSE;
}
static gboolean
dissect_obdii_common_distance_travelled(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree, int hf_field)
{
if (oinfo->value_bytes == 2)
{
guint16 val = 256 * oinfo->valueA + oinfo->valueB;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u km", val);
proto_tree_add_uint(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
return TRUE;
}
return FALSE;
}
static gboolean
dissect_obdii_common_time(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree, int hf_field)
{
if (oinfo->value_bytes == 2)
{
guint16 val = 256 * oinfo->valueA + oinfo->valueB;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u minutes", val);
proto_tree_add_uint(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
return TRUE;
}
return FALSE;
}
static gboolean
dissect_obdii_common_torque(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree, int hf_field)
{
if (oinfo->value_bytes == 1)
{
int val = ((int) oinfo->valueA) - 125;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %d %%", val);
proto_tree_add_int(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
return TRUE;
}
return FALSE;
}
static void
dissect_obdii_mode_01(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree)
{
guint8 pid = tvb_get_guint8(tvb, 2);
int value_offset;
gboolean handled = FALSE;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, "- %s", val_to_str_ext(pid, &obdii_mode01_pid_vals_ext, "Unknown (%.2x)"));
proto_tree_add_uint(tree, hf_obdii_mode01_pid, tvb, 2, 1, pid);
proto_tree_add_item(tree, hf_obdii_raw_value, tvb, 3, MIN(oinfo->value_bytes, 4), ENC_NA);
value_offset = 3;
oinfo->value_offset = value_offset;
switch (pid)
{
case OBDII_MODE01_PIDS_SUPPORT00:
case OBDII_MODE01_PIDS_SUPPORT20:
case OBDII_MODE01_PIDS_SUPPORT40:
case OBDII_MODE01_PIDS_SUPPORT60:
case OBDII_MODE01_PIDS_SUPPORT80:
case OBDII_MODE01_PIDS_SUPPORTA0:
case OBDII_MODE01_PIDS_SUPPORTC0:
if ((handled = (oinfo->value_bytes == 4)))
{
guint32 val = ((oinfo->valueA << 24) | (oinfo->valueB << 16) | (oinfo->valueC << 8) | (oinfo->valueD << 0));
int i;
const char *sepa;
char bits_str[33];
sepa = ": ";
for (i = 31; i >= 0; i--)
{
guint this_pid = (pid + 32 - i);
proto_item *ti;
memset(bits_str, '.', 32);
bits_str[32] = '\0';
if ((val & (1 << i)))
{
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, "%s%.2X", sepa, this_pid);
ti = proto_tree_add_uint(tree, hf_obdii_mode01_supported_pid, tvb, value_offset, oinfo->value_bytes, this_pid);
sepa = ",";
bits_str[31 - i] = '1';
}
else
{
ti = proto_tree_add_uint(tree, hf_obdii_mode01_unsupported_pid, tvb, value_offset, oinfo->value_bytes, this_pid);
bits_str[31 - i] = '0';
}
proto_item_prepend_text(ti, "%s = ", bits_str);
}
}
break;
case OBDII_MODE01_FUEL_SYSTEM_STATUS:
if ((handled = (oinfo->value_bytes == 2)))
{
guint8 fuel_system1_val = oinfo->valueA;
guint8 fuel_system2_val = oinfo->valueB;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": System 1: %s", val_to_str(fuel_system1_val, obdii_fuel_system_status_vals, "Unknown (%.2X)"));
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ", System 2: %s", val_to_str(fuel_system2_val, obdii_fuel_system_status_vals, "Unknown (%.2X)"));
proto_tree_add_uint(tree, hf_obdii_mode01_fuel_system1_status, tvb, value_offset + 0, 1, fuel_system1_val);
proto_tree_add_uint(tree, hf_obdii_mode01_fuel_system2_status, tvb, value_offset + 1, 1, fuel_system2_val);
}
break;
case OBDII_MODE01_ENGINE_LOAD:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_engine_load);
break;
case OBDII_MODE01_ENGINE_COOLANT_TEMP:
handled = dissect_obdii_common_temperature(tvb, oinfo, tree, hf_obdii_mode01_engine_coolant_temp);
break;
case OBDII_MODE01_SHORT_TERM_FUEL_BANK1:
handled = dissect_obdii_common_percent_neg(tvb, oinfo, tree, hf_obdii_mode01_short_term_fuel_bank1);
break;
case OBDII_MODE01_LONG_TERM_FUEL_BANK1:
handled = dissect_obdii_common_percent_neg(tvb, oinfo, tree, hf_obdii_mode01_long_term_fuel_bank1);
break;
case OBDII_MODE01_SHORT_TERM_FUEL_BANK2:
handled = dissect_obdii_common_percent_neg(tvb, oinfo, tree, hf_obdii_mode01_short_term_fuel_bank2);
break;
case OBDII_MODE01_LONG_TERM_FUEL_BANK2:
handled = dissect_obdii_common_percent_neg(tvb, oinfo, tree, hf_obdii_mode01_long_term_fuel_bank2);
break;
case OBDII_MODE01_FUEL_PRESSURE:
if ((handled = (oinfo->value_bytes == 1)))
{
guint16 val = 3 * oinfo->valueA;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u kPa", val);
proto_tree_add_uint(tree, hf_obdii_mode01_fuel_pressure, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_ENGINE_RPM:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = (256 * oinfo->valueA + oinfo->valueB) / 4.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.2f rpm", val);
proto_tree_add_double(tree, hf_obdii_mode01_engine_rpm, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_VEHICLE_SPEED:
if ((handled = (oinfo->value_bytes == 1)))
{
guint8 val = oinfo->valueA;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u km/h", val);
proto_tree_add_uint(tree, hf_obdii_mode01_vehicle_speed, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_TIMING_ADVANCE:
if ((handled = (oinfo->value_bytes == 1)))
{
double val = (oinfo->valueA - 128) / 2.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.2f " UTF8_DEGREE_SIGN "BTDC", val);
proto_tree_add_double(tree, hf_obdii_mode01_timing_advance, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_INTAKE_AIR_TEMP:
handled = dissect_obdii_common_temperature(tvb, oinfo, tree, hf_obdii_mode01_intake_air_temp);
break;
case OBDII_MODE01_MAF_AIR_FLOW_RATE:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = (256 * oinfo->valueA + oinfo->valueB) / 100.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.2f g/s", val);
proto_tree_add_double(tree, hf_obdii_mode01_maf_air_flow_rate, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_THROTTLE_POSITION:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_throttle_position);
break;
case OBDII_MODE01_SECONDARY_AIR_STATUS:
if ((handled = (oinfo->value_bytes == 1)))
{
guint8 air_status = oinfo->valueA;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %s", val_to_str(air_status, obdii_secondary_air_status_vals, "Unknown (%.2X)"));
proto_tree_add_uint(tree, hf_obdii_mode01_secondary_air_status, tvb, value_offset, oinfo->value_bytes, air_status);
}
break;
case OBDII_MODE01_OXYGEN_SENSOR_PRESET2:
if ((handled = (oinfo->value_bytes == 1)))
{
guint8 bank1_sensor1 = (oinfo->valueA & (1 << 0));
guint8 bank1_sensor2 = (oinfo->valueA & (1 << 1));
guint8 bank1_sensor3 = (oinfo->valueA & (1 << 2));
guint8 bank1_sensor4 = (oinfo->valueA & (1 << 3));
guint8 bank2_sensor1 = (oinfo->valueA & (1 << 4));
guint8 bank2_sensor2 = (oinfo->valueA & (1 << 5));
guint8 bank2_sensor3 = (oinfo->valueA & (1 << 6));
guint8 bank2_sensor4 = (oinfo->valueA & (1 << 7));
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": Bank1 sensors: %s%s%s%s%s",
bank1_sensor1 ? "1 " : "", bank1_sensor2 ? "2 " : "", bank1_sensor3 ? "3 " : "", bank1_sensor4 ? "4 " : "",
((bank1_sensor1 | bank1_sensor2 | bank1_sensor3 | bank1_sensor4)) ? "" : "None");
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ", Bank2 sensors: %s%s%s%s%s",
bank2_sensor1 ? "1 " : "", bank2_sensor2 ? "2 " : "", bank2_sensor3 ? "3 " : "", bank2_sensor4 ? "4 " : "",
((bank2_sensor1 | bank2_sensor2 | bank2_sensor3 | bank2_sensor4)) ? "" : "None");
}
break;
case OBDII_MODE01_OXYGEN_SENSOR_PRESET4:
if ((handled = (oinfo->value_bytes == 1)))
{
guint8 bank1_sensor1 = (oinfo->valueA & (1 << 0));
guint8 bank1_sensor2 = (oinfo->valueA & (1 << 1));
guint8 bank2_sensor1 = (oinfo->valueA & (1 << 2));
guint8 bank2_sensor2 = (oinfo->valueA & (1 << 3));
guint8 bank3_sensor1 = (oinfo->valueA & (1 << 4));
guint8 bank3_sensor2 = (oinfo->valueA & (1 << 5));
guint8 bank4_sensor1 = (oinfo->valueA & (1 << 6));
guint8 bank4_sensor2 = (oinfo->valueA & (1 << 7));
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": Bank1 sensors: %s%s%s",
bank1_sensor1 ? "1 " : "", bank1_sensor2 ? "2 " : "",
((bank1_sensor1 | bank1_sensor2)) ? "" : "None");
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ", Bank2 sensors: %s%s%s",
bank2_sensor1 ? "1 " : "", bank2_sensor2 ? "2 " : "",
((bank2_sensor1 | bank2_sensor2)) ? "" : "None");
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ", Bank3 sensors: %s%s%s",
bank3_sensor1 ? "1 " : "", bank3_sensor2 ? "2 " : "",
((bank3_sensor1 | bank3_sensor2)) ? "" : "None");
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ", Bank4 sensors: %s%s%s",
bank4_sensor1 ? "1 " : "", bank4_sensor2 ? "2 " : "",
((bank4_sensor1 | bank4_sensor2)) ? "" : "None");
}
break;
case OBDII_MODE01_OXYGEN_SENSOR1:
case OBDII_MODE01_OXYGEN_SENSOR2:
case OBDII_MODE01_OXYGEN_SENSOR3:
case OBDII_MODE01_OXYGEN_SENSOR4:
case OBDII_MODE01_OXYGEN_SENSOR5:
case OBDII_MODE01_OXYGEN_SENSOR6:
case OBDII_MODE01_OXYGEN_SENSOR7:
case OBDII_MODE01_OXYGEN_SENSOR8:
if ((handled = (oinfo->value_bytes == 2)))
{
double volt_val = (oinfo->valueA) / 200.0;
double fuel_trim = ((100.0 * oinfo->valueB) / 128.0) - 100.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": Voltage: %.3f V", volt_val);
if (oinfo->valueB != 0xFF)
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ", Short term fuel trim: %.2f %%", fuel_trim);
proto_tree_add_uint(tree, hf_obdii_mode01_oxygen_sensor_id, tvb, value_offset, oinfo->value_bytes, 1 + (pid - OBDII_MODE01_OXYGEN_SENSOR1));
proto_tree_add_double(tree, hf_obdii_mode01_oxygen_sensor_voltage, tvb, value_offset, 1, volt_val);
}
break;
case OBDII_MODE01_OBD_STANDARDS:
if ((handled = (oinfo->value_bytes == 1)))
{
guint8 val = oinfo->valueA;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %s", val_to_str(val, obdii_standards_vals, "Unknown (%u)"));
proto_tree_add_uint(tree, hf_obdii_mode01_obd_standards, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_ENGINE_UPTIME:
if ((handled = (oinfo->value_bytes == 2)))
{
guint16 val = 256 * oinfo->valueA + oinfo->valueB;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u s", val);
proto_tree_add_uint(tree, hf_obdii_mode01_engine_uptime, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_FUEL_RAIL_PRESSURE:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = 0.079 * (256 * oinfo->valueA + oinfo->valueB);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.3f kPa", val);
proto_tree_add_double(tree, hf_obdii_mode01_fuel_rail_pressure, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_FUEL_RAIL_GAUGE_PRESSURE:
handled = dissect_obdii_common_fuel_rail_pressure(tvb, oinfo, tree, hf_obdii_mode01_fuel_rail_gauge_pressure);
break;
case OBDII_MODE01_FUEL_RAIL_ABSOLUTE_PRESSURE:
handled = dissect_obdii_common_fuel_rail_pressure(tvb, oinfo, tree, hf_obdii_mode01_fuel_rail_absolute_pressure);
break;
case OBDII_MODE01_OXYGEN_SENSOR1_:
case OBDII_MODE01_OXYGEN_SENSOR2_:
case OBDII_MODE01_OXYGEN_SENSOR3_:
case OBDII_MODE01_OXYGEN_SENSOR4_:
case OBDII_MODE01_OXYGEN_SENSOR5_:
case OBDII_MODE01_OXYGEN_SENSOR6_:
case OBDII_MODE01_OXYGEN_SENSOR7_:
case OBDII_MODE01_OXYGEN_SENSOR8_:
if ((handled = (oinfo->value_bytes == 4)))
{
double fuel_air_ratio = (256 * oinfo->valueA + oinfo->valueB) * (2.0 / 65536.0);
double volt_val = (256 * oinfo->valueC + oinfo->valueD) * (8.0 / 65536.0);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": Fuel-Air Equivalence: %.4f ratio", fuel_air_ratio);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ", Voltage: %.4f V", volt_val);
proto_tree_add_uint(tree, hf_obdii_mode01_oxygen_sensor_id, tvb, value_offset, oinfo->value_bytes, 1 + (pid - OBDII_MODE01_OXYGEN_SENSOR1_));
proto_tree_add_double(tree, hf_obdii_mode01_oxygen_sensor_fuel_air_ratio, tvb, value_offset, 2, fuel_air_ratio);
proto_tree_add_double(tree, hf_obdii_mode01_oxygen_sensor_voltage, tvb, value_offset + 2, 2, volt_val);
}
break;
case OBDII_MODE01_COMMANDED_EGR:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_commanded_egr);
break;
case OBDII_MODE01_EGR_ERROR:
handled = dissect_obdii_common_percent_neg(tvb, oinfo, tree, hf_obdii_mode01_egr_error);
break;
case OBDII_MODE01_COMMANDED_EVAP_PURGE:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_commanded_evap_purge);
break;
case OBDII_MODE01_FUEL_TANK_LEVEL:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_fuel_tank_level_input);
break;
case OBDII_MODE01_WARM_UPS_SINCE_CLEAR:
if ((handled = (oinfo->value_bytes == 1)))
{
guint8 val = oinfo->valueA;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u", val);
proto_tree_add_uint(tree, hf_obdii_mode01_warm_ups, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_EVAP_SYSTEM_VAPOR_PRESSURE:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = ((gint16) (oinfo->valueA * 256 + oinfo->valueB)) / 4.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.2f kPa", val);
proto_tree_add_double(tree, hf_obdii_mode01_evap_system_vapor_pressure, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_ABSOLUTE_BAROMETRIC_PRESSURE:
handled = dissect_obdii_common_absolute_pressure(tvb, oinfo, tree, hf_obdii_mode01_absolute_barometric_pressure);
break;
case OBDII_MODE01_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE:
handled = dissect_obdii_common_absolute_pressure(tvb, oinfo, tree, hf_obdii_mode01_intake_manifold_absolute_pressure);
break;
case OBDII_MODE01_OXYGEN_SENSOR1_A:
case OBDII_MODE01_OXYGEN_SENSOR2_A:
case OBDII_MODE01_OXYGEN_SENSOR3_A:
case OBDII_MODE01_OXYGEN_SENSOR4_A:
case OBDII_MODE01_OXYGEN_SENSOR5_A:
case OBDII_MODE01_OXYGEN_SENSOR6_A:
case OBDII_MODE01_OXYGEN_SENSOR7_A:
case OBDII_MODE01_OXYGEN_SENSOR8_A:
if ((handled = (oinfo->value_bytes == 4)))
{
double fuel_air_ratio = (256 * oinfo->valueA + oinfo->valueB) * (2.0 / 65536.0);
double current_val = (((int) oinfo->valueC) - 128) + (oinfo->valueD / 256.0);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": Fuel-Air Equivalence: %.4f ratio", fuel_air_ratio);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ", Current: %.4f mA", current_val);
proto_tree_add_uint(tree, hf_obdii_mode01_oxygen_sensor_id, tvb, value_offset, oinfo->value_bytes, 1 + (pid - OBDII_MODE01_OXYGEN_SENSOR1_A));
proto_tree_add_double(tree, hf_obdii_mode01_oxygen_sensor_fuel_air_ratio, tvb, value_offset, 2, fuel_air_ratio);
proto_tree_add_double(tree, hf_obdii_mode01_oxygen_sensor_current, tvb, value_offset + 2, 2, current_val);
}
break;
case OBDII_MODE01_CATALYST_TEMP11:
case OBDII_MODE01_CATALYST_TEMP21:
case OBDII_MODE01_CATALYST_TEMP12:
case OBDII_MODE01_CATALYST_TEMP22:
if ((handled = (oinfo->value_bytes == 2)))
{
int hf_field =
(pid == OBDII_MODE01_CATALYST_TEMP11) ? hf_obdii_mode01_catalyst_temp_11 :
(pid == OBDII_MODE01_CATALYST_TEMP21) ? hf_obdii_mode01_catalyst_temp_21 :
(pid == OBDII_MODE01_CATALYST_TEMP12) ? hf_obdii_mode01_catalyst_temp_12 :
(pid == OBDII_MODE01_CATALYST_TEMP22) ? hf_obdii_mode01_catalyst_temp_22 :
-1;
double val = ((256 * oinfo->valueA + oinfo->valueB) / 10.0) - 40.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.2f " UTF8_DEGREE_SIGN "C", val);
proto_tree_add_double(tree, hf_field, tvb, oinfo->value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_CONTROL_MODULE_VOLTAGE:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = (256 * oinfo->valueA + oinfo->valueB) / 1000.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.3f V", val);
proto_tree_add_double(tree, hf_obdii_mode01_control_module_voltage, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_ABSOLUTE_LOAD_VALUE:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = ((256 * oinfo->valueA + oinfo->valueB) * 100) / 255.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.3f %%", val);
proto_tree_add_double(tree, hf_obdii_mode01_absolute_load_value, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_FUEL_AIR_COMMANDED_EQUIV_RATIO:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = (256 * oinfo->valueA + oinfo->valueB) * (2.0 / 65536.0);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.3f", val);
proto_tree_add_double(tree, hf_obdii_mode01_fuel_air_commanded_equiv_ratio, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_RELATIVE_THROTTLE_POSITION:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_relative_throttle_position);
break;
case OBDII_MODE01_AMBIENT_AIR_TEMP:
handled = dissect_obdii_common_temperature(tvb, oinfo, tree, hf_obdii_mode01_ambient_air_temp);
break;
case OBDII_MODE01_ABSOLUTE_THROTTLE_POSITION_B:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_absolute_throttle_position_B);
break;
case OBDII_MODE01_ABSOLUTE_THROTTLE_POSITION_C:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_absolute_throttle_position_C);
break;
case OBDII_MODE01_ACCELERATOR_PEDAL_POSITION_D:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_accelerator_pedal_position_D);
break;
case OBDII_MODE01_ACCELERATOR_PEDAL_POSITION_E:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_accelerator_pedal_position_E);
break;
case OBDII_MODE01_ACCELERATOR_PEDAL_POSITION_F:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_accelerator_pedal_position_F);
break;
case OBDII_MODE01_COMMANDED_THROTTLE_ACTUATOR:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_commanded_throttle_actuator);
break;
case OBDII_MODE01_DISTANCE_TRAVELED_WITH_MIL:
handled = dissect_obdii_common_distance_travelled(tvb, oinfo, tree, hf_obdii_mode01_distance_traveled_with_mil);
break;
case OBDII_MODE01_DISTANCE_TRAVELED_SINCE_CODES_CLEAR:
handled = dissect_obdii_common_distance_travelled(tvb, oinfo, tree, hf_obdii_mode01_distance_traveled_since_code_clear);
break;
case OBDII_MODE01_TIME_RUN_WITH_MIL:
handled = dissect_obdii_common_time(tvb, oinfo, tree, hf_obdii_mode01_time_run_with_mil);
break;
case OBDII_MODE01_TIME_SINCE_TROUBLE_CODES_CLEAR:
handled = dissect_obdii_common_time(tvb, oinfo, tree, hf_obdii_mode01_time_since_trouble_code_clear);
break;
case OBDII_MODE01_FUEL_TYPE:
if ((handled = (oinfo->value_bytes == 1)))
{
guint8 val = oinfo->valueA;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %s", val_to_str(val, obdii_fuel_type_coding_vals, "Unknown (%u)"));
proto_tree_add_uint(tree, hf_obdii_mode01_fuel_type, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_ETHANOL_FUEL:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_ethanol_fuel);
break;
case OBDII_MODE01_ABSOLUTE_EVAP_SYSTEM_VAPOR_PRESSURE:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = (oinfo->valueA * 256 + oinfo->valueB) / 200.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.2f kPa", val);
proto_tree_add_double(tree, hf_obdii_mode01_absolute_evap_system_vapor_pressure, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_SHORT_TERM_OXYGEN_BANK13:
case OBDII_MODE01_LONG_TERM_OXYGEN_BANK13:
case OBDII_MODE01_SHORT_TERM_OXYGEN_BANK24:
case OBDII_MODE01_LONG_TERM_OXYGEN_BANK24:
if ((handled = (oinfo->value_bytes == 2)))
{
double bankA_val = ((100.0 * oinfo->valueA) / 128.0) - 100.0;
double bankB_val = ((100.0 * oinfo->valueB) / 128.0) - 100.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": { %.2f %%, %.2f %% }", bankA_val, bankB_val);
}
break;
case OBDII_MODE01_RELATIVE_ACCELERATOR_PEDAL_POSITION:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_relative_accelerator_pedal_position);
break;
case OBDII_MODE01_HYBRID_BATTERY_REMAINING_LIFE:
handled = dissect_obdii_common_percent(tvb, oinfo, tree, hf_obdii_mode01_hybrid_battery_remaining_life);
break;
case OBDII_MODE01_ENGINE_OIL_TEMP:
handled = dissect_obdii_common_temperature(tvb, oinfo, tree, hf_obdii_mode01_engine_oil_temp);
break;
case OBDII_MODE01_FUEL_INJECTION_TIMING:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = ((256 * oinfo->valueA + oinfo->valueB - (210 * 128)) / 128.0);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.3f " UTF8_DEGREE_SIGN, val);
proto_tree_add_double(tree, hf_obdii_mode01_fuel_injection_timing, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_ENGINE_FUEL_RATE:
if ((handled = (oinfo->value_bytes == 2)))
{
double val = (256 * oinfo->valueA + oinfo->valueB) / 20.0;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %.3f L/h", val);
proto_tree_add_double(tree, hf_obdii_mode01_engine_fuel_rate, tvb, value_offset, oinfo->value_bytes, val);
}
break;
case OBDII_MODE01_TORQUE_DRIVER_DEMAND_ENGINE:
handled = dissect_obdii_common_torque(tvb, oinfo, tree, hf_obdii_mode01_torque_driver_demand_engine);
break;
case OBDII_MODE01_TORQUE_ACTUAL_ENGINE:
handled = dissect_obdii_common_torque(tvb, oinfo, tree, hf_obdii_mode01_torque_actual_engine);
break;
case OBDII_MODE01_TORQUE_REFERENCE_ENGINE:
if ((handled = (oinfo->value_bytes == 2)))
{
guint16 val = 256 * oinfo->valueA + oinfo->valueB;
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": %u Nm", val);
proto_tree_add_uint(tree, hf_obdii_mode01_torque_reference_engine, tvb, value_offset, oinfo->value_bytes, val);
}
break;
}
if (!handled)
{
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, ": <");
if (oinfo->value_bytes >= 1) col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, " %.2X", oinfo->valueA);
if (oinfo->value_bytes >= 2) col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, " %.2X", oinfo->valueB);
if (oinfo->value_bytes >= 3) col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, " %.2X", oinfo->valueC);
if (oinfo->value_bytes >= 4) col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, " %.2X", oinfo->valueD);
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, " >");
}
}
static int
dissect_obdii_query(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree)
{
guint16 pid;
int pid_len;
const char *mode_str;
const char *pid_str;
pid_len = oinfo->data_bytes - 1;
if (pid_len == 1)
pid = tvb_get_guint8(tvb, 2);
else if (pid_len == 2)
pid = tvb_get_ntohs(tvb, 2);
else
return 0;
mode_str = val_to_str(oinfo->mode, obdii_mode_vals, "Unknown (%.2x)");
switch (oinfo->mode)
{
case 0x01:
pid_str = val_to_str_ext(pid, &obdii_mode01_pid_vals_ext, "Unknown (%.2x)");
proto_tree_add_uint(tree, hf_obdii_mode01_pid, tvb, 2, pid_len, pid);
break;
default:
pid_str = wmem_strdup_printf(wmem_packet_scope(), "Unknown (%.2x)", pid);
break;
}
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, " Request[%.3x] %s - %s", oinfo->can_id, mode_str, pid_str);
return tvb_captured_length(tvb);
}
static int
dissect_obdii_response(tvbuff_t *tvb, struct obdii_packet_info *oinfo, proto_tree *tree)
{
col_append_fstr(oinfo->pinfo->cinfo, COL_INFO, "Response[%.3x] %s ", oinfo->can_id, val_to_str(oinfo->mode, obdii_mode_vals, "Unknown (%.2x)"));
oinfo->value_bytes = 1 + (oinfo->data_bytes - 3);
if (oinfo->value_bytes >= 1) oinfo->valueA = tvb_get_guint8(tvb, 3);
if (oinfo->value_bytes >= 2) oinfo->valueB = tvb_get_guint8(tvb, 4);
if (oinfo->value_bytes >= 3) oinfo->valueC = tvb_get_guint8(tvb, 5);
if (oinfo->value_bytes >= 4) oinfo->valueD = tvb_get_guint8(tvb, 6);
switch (oinfo->mode)
{
case 0x01:
dissect_obdii_mode_01(tvb, oinfo, tree);
break;
}
return tvb_captured_length(tvb);
}
static int
dissect_obdii(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
struct can_identifier *can_id = (struct can_identifier *) data;
struct obdii_packet_info oinfo;
proto_tree *obdii_tree;
proto_item *ti;
guint8 data_bytes;
guint8 mode;
if (!can_id || !(can_id->id == ODBII_CAN_QUERY_ID || (can_id->id >= ODBII_CAN_RESPONSE_ID_MIN && can_id->id <= ODBII_CAN_RESPONSE_ID_MAX)))
return 0;
if (tvb_reported_length(tvb) != 8)
return 0;
data_bytes = tvb_get_guint8(tvb, 0);
mode = tvb_get_guint8(tvb, 1);
if (can_id->id == ODBII_CAN_QUERY_ID)
{
if (!(data_bytes == 2 || data_bytes == 3))
return 0;
}
if ((can_id->id >= ODBII_CAN_RESPONSE_ID_MIN && can_id->id <= ODBII_CAN_RESPONSE_ID_MAX))
{
if (!(data_bytes >= 3 && data_bytes <= 7))
return 0;
if (mode < 0x40)
return 0;
mode -= 0x40;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OBD-II");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_obdii, tvb, 0, -1, ENC_NA);
obdii_tree = proto_item_add_subtree(ti, ett_obdii);
proto_tree_add_item(obdii_tree, hf_obdii_data_bytes, tvb, 0, 1, ENC_NA);
proto_tree_add_uint(obdii_tree, hf_obdii_mode, tvb, 1, 1, mode);
memset(&oinfo, 0, sizeof(oinfo));
oinfo.pinfo = pinfo;
oinfo.can_id = can_id->id;
oinfo.data_bytes = data_bytes;
oinfo.mode = mode;
if (can_id->id == ODBII_CAN_QUERY_ID)
return dissect_obdii_query(tvb, &oinfo, obdii_tree);
if (can_id->id >= ODBII_CAN_RESPONSE_ID_MIN && can_id->id <= ODBII_CAN_RESPONSE_ID_MAX)
return dissect_obdii_response(tvb, &oinfo, obdii_tree);
DISSECTOR_ASSERT_NOT_REACHED();
return tvb_captured_length(tvb);
}
void
proto_register_obdii(void)
{
static hf_register_info hf[] = {
{ &hf_obdii_data_bytes,
{ "Number of data bytes", "obd-ii.data_bytes", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode,
{ "Mode", "obd-ii.mode", FT_UINT8, BASE_HEX, VALS(obdii_mode_vals), 0x0, NULL, HFILL },
},
{ &hf_obdii_raw_value,
{ "Raw value", "obd-ii.raw_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_pid,
{ "PID", "obd-ii.mode01_pid", FT_UINT16, BASE_HEX | BASE_EXT_STRING, VALS_EXT_PTR(&obdii_mode01_pid_vals_ext), 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_supported_pid,
{ "Supported PID", "obd-ii.mode01_supported_pid", FT_UINT8, BASE_HEX | BASE_EXT_STRING, VALS_EXT_PTR(&obdii_mode01_pid_vals_ext), 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_unsupported_pid,
{ "NOT Supported PID", "obd-ii.mode01_unsupported_pid", FT_UINT8, BASE_HEX | BASE_EXT_STRING, VALS_EXT_PTR(&obdii_mode01_pid_vals_ext), 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_fuel_system1_status,
{ "Fuel system 1 status", "obd-ii.mode01_fuel_system1_status", FT_UINT8, BASE_HEX, VALS(obdii_fuel_system_status_vals), 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_fuel_system2_status,
{ "Fuel system 2 status", "obd-ii.mode01_fuel_system2_status", FT_UINT8, BASE_HEX, VALS(obdii_fuel_system_status_vals), 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_engine_load,
{ "Calculated engine load", "obd-ii.mode01_engine_load", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_engine_coolant_temp,
{ "Engine coolant temperature", "obd-ii.mode01_engine_coolant_temp", FT_INT16, BASE_DEC | BASE_UNIT_STRING, &units_degree_celsius, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_short_term_fuel_bank1,
{ "Short term fuel trim (Bank 1)", "obd-ii.mode01_short_term_fuel_bank1", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_short_term_fuel_bank2,
{ "Short term fuel trim (Bank 2)", "obd-ii.mode01_short_term_fuel_bank2", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_long_term_fuel_bank1,
{ "Long term fuel trim (Bank 1)", "obd-ii.mode01_long_term_fuel_bank1", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_long_term_fuel_bank2,
{ "Long term fuel trim (Bank 2)", "obd-ii.mode01_long_term_fuel_bank2", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_fuel_pressure,
{ "Fuel pressure", "obd-ii.mode01_fuel_pressure", FT_UINT16, BASE_DEC | BASE_UNIT_STRING, &units_kilopascal, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_engine_rpm,
{ "Engine RPM", "obd-ii.mode01_engine_rpm", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_revolutions_per_minute, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_vehicle_speed,
{ "Vehicle Speed", "obd-ii.mode01_vehicle_speed", FT_UINT8, BASE_DEC | BASE_UNIT_STRING, &units_kmh, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_timing_advance,
{ "Timing advance", "obd-ii.mode01_timing_advance", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_degree_btdc, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_intake_air_temp,
{ "Intake air temperature", "obd-ii.mode01_intake_air_temp", FT_INT16, BASE_DEC | BASE_UNIT_STRING, &units_degree_celsius, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_maf_air_flow_rate,
{ "MAF air flow rate", "obd-ii.mode01_maf_air_flow_rate", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_grams_per_second, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_throttle_position,
{ "Throttle position", "obd-ii.mode01_throttle_position", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_secondary_air_status,
{ "Commanded secondary air status", "obd-ii.mode01_secondary_air_status", FT_UINT8, BASE_HEX, VALS(obdii_secondary_air_status_vals), 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_obd_standards,
{ "OBD Standards", "obd-ii.mode01_obd_standards", FT_UINT8, BASE_DEC, VALS(obdii_standards_vals), 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_engine_uptime,
{ "Run time since engine start", "obd-ii.mode01_engine_uptime", FT_UINT16, BASE_DEC | BASE_UNIT_STRING, &units_seconds, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_fuel_rail_pressure,
{ "Fuel Rail Pressure", "obd-ii.mode01_fuel_rail_pressure", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_kilopascal, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_fuel_rail_gauge_pressure,
{ "Fuel Rail Gauge Pressure", "obd-ii.mode01_fuel_rail_gaguge_pressure", FT_UINT24, BASE_DEC | BASE_UNIT_STRING, &units_kilopascal, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_fuel_rail_absolute_pressure,
{ "Fuel rail absolute pressure", "obd-ii.mode01_fuel_rail_absolute_pressure", FT_UINT24, BASE_DEC | BASE_UNIT_STRING, &units_kilopascal, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_commanded_egr,
{ "Commanded EGR", "obd-ii.mode01_commanded_egr", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_egr_error,
{ "EGR Error", "obd-ii.mode01_egr_error", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_commanded_evap_purge,
{ "Commanded evaporative purge", "obd-ii.mode01_commanded_evap_purge", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_fuel_tank_level_input,
{ "Fuel Tank Level Input", "obd-ii.mode01_fuel_tank_level_input", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_warm_ups,
{ "Warm-ups since codes cleared", "obd-ii.mode01_warm_ups", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_evap_system_vapor_pressure,
{ "Evap. System Vapor Pressure", "obd-ii.mode01_evap_system_vapor_pressure", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_kilopascal, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_absolute_barometric_pressure,
{ "Absolute Barometric Pressure", "obd-ii.mode01_absolute_barometric_pressure", FT_UINT8, BASE_DEC | BASE_UNIT_STRING, &units_kilopascal, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_intake_manifold_absolute_pressure,
{ "Intake manifold absolute pressure", "obd-ii.mode01_intake_manifold_absolute_pressure", FT_UINT8, BASE_DEC | BASE_UNIT_STRING, &units_kilopascal, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_oxygen_sensor_id,
{ "Oxygen Sensor ID", "obd-ii.mode01_oxygen_sensor_id", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_oxygen_sensor_fuel_air_ratio,
{ "Fuel-Air Equivalence Ratio", "obd-ii.mode01_oxygen_sensor_fuel_air_ratio", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_oxygen_sensor_voltage,
{ "Voltage", "obd-ii.mode01_oxygen_sensor_voltage", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_volt, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_oxygen_sensor_current,
{ "Current", "obd-ii.mode01_oxygen_sensor_current", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_milliamps, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_distance_traveled_with_mil,
{ "Distance traveled with MIL on", "obd-ii.mode01_distance_traveled_with_mil", FT_UINT16, BASE_DEC | BASE_UNIT_STRING, &units_km, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_distance_traveled_since_code_clear,
{ "Distance traveled since codes cleared", "obd-ii.mode01_distance_traveled_since_code_clear", FT_UINT16, BASE_DEC | BASE_UNIT_STRING, &units_km, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_time_run_with_mil,
{ "Time run with MIL on", "obd-ii.mode01_time_run_with_mil", FT_UINT16, BASE_DEC | BASE_UNIT_STRING, &units_minute_minutes, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_time_since_trouble_code_clear,
{ "Time since trouble codes cleared", "obd-ii.mode01_time_since_trouble_code_clear", FT_UINT16, BASE_DEC | BASE_UNIT_STRING, &units_minute_minutes, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_fuel_type,
{ "Fuel type", "obd-ii.mode01_fuel_type", FT_UINT8, BASE_DEC, VALS(obdii_fuel_type_coding_vals), 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_control_module_voltage,
{ "Control module voltage", "obd-ii.mode01_control_module_voltage", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_volt, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_absolute_load_value,
{ "Absolute load value", "obd-ii.mode01_absolute_load_value", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_fuel_air_commanded_equiv_ratio,
{ "Fuel-Air commanded equivalence ratio", "obd-ii.mode01_fuel_air_commanded_equiv_ratio", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_relative_throttle_position,
{ "Relative throttle position", "obd-ii.mode01_relative_throttle_position", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_catalyst_temp_11,
{ "Catalyst Temperature (Bank 1, Sensor 1)", "obd-ii.mode01_catalyst_temp_11", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_degree_celsius, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_catalyst_temp_21,
{ "Catalyst Temperature (Bank 2, Sensor 1)", "obd-ii.mode01_catalyst_temp_21", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_degree_celsius, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_catalyst_temp_12,
{ "Catalyst Temperature (Bank 1, Sensor 2)", "obd-ii.mode01_catalyst_temp_12", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_degree_celsius, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_catalyst_temp_22,
{ "Catalyst Temperature (Bank 2, Sensor 2)", "obd-ii.mode01_catalyst_temp_22", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_degree_celsius, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_ambient_air_temp,
{ "Ambient air temperature", "obd-ii.mode01_ambient_air_temp", FT_INT16, BASE_DEC | BASE_UNIT_STRING, &units_degree_celsius, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_absolute_throttle_position_B,
{ "Absolute throttle position B", "obd-ii.mode01_bsolute_throttle_position_B", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_absolute_throttle_position_C,
{ "Absolute throttle position C", "obd-ii.mode01_absolute_throttle_position_C", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_accelerator_pedal_position_D,
{ "Accelerator pedal position D", "obd-ii.mode01_accelerator_pedal_position_D", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_accelerator_pedal_position_E,
{ "Accelerator pedal position E", "obd-ii.mode01_accelerator_pedal_position_E", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_accelerator_pedal_position_F,
{ "Accelerator pedal position F", "obd-ii.mode01_accelerator_pedal_position_F", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_commanded_throttle_actuator,
{ "Commanded throttle actuator", "obd-ii.mode01_commanded_throttle_actuator", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_ethanol_fuel,
{ "Ethanol fuel %", "obd-ii.mode01_ethanol_fuel", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_absolute_evap_system_vapor_pressure,
{ "Absolute Evap system Vapor Pressure", "obd-ii.mode01_absolute_evap_system_vapor_pressure", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_kilopascal, 0x0, NULL, HFILL }
},
{ &hf_obdii_mode01_relative_accelerator_pedal_position,
{ "Relative accelerator pedal position", "obd-ii.mode01_relative_accelerator_pedal_position", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_hybrid_battery_remaining_life,
{ "Hybrid battery pack remaining life", "obd-ii.mode01_hybrid_battery_remaining_life", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_engine_oil_temp,
{ "Engine oil temperature", "obd-ii.mode01_engine_oil_temp", FT_INT16, BASE_DEC | BASE_UNIT_STRING, &units_degree_celsius, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_fuel_injection_timing,
{ "Fuel injection timing", "obd-ii.mode01_fuel_injection_timing", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_degree_degrees, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_engine_fuel_rate,
{ "Engine fuel rate", "obd-ii.mode01_engine_fuel_rate", FT_DOUBLE, BASE_NONE | BASE_UNIT_STRING, &units_liter_per_hour, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_torque_driver_demand_engine,
{ "Driver's demand engine - percent torque", "obd-ii.mode01_torque_driver_demand_engine", FT_INT16, BASE_DEC | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_torque_actual_engine,
{ "Actual engine - percent torque", "obd-ii.mode01_torque_actual_engine", FT_INT16, BASE_DEC | BASE_UNIT_STRING, &units_percent, 0x0, NULL, HFILL },
},
{ &hf_obdii_mode01_torque_reference_engine,
{ "Engine reference torque", "obd-ii.mode01_torque_reference_engine", FT_UINT16, BASE_DEC | BASE_UNIT_STRING, &units_newton_metre, 0x0, NULL, HFILL },
},
};
static int *ett[] = {
&ett_obdii
};
proto_obdii = proto_register_protocol("OBD-II PID", "OBD-II", "obd-ii");
proto_register_field_array(proto_obdii, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_obdii(void)
{
dissector_handle_t obdii_handle;
obdii_handle = create_dissector_handle(dissect_obdii, proto_obdii);
dissector_add_for_decode_as("can.subdissector", obdii_handle);
}
