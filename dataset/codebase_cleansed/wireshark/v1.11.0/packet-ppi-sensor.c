static gdouble
base_10_expt(int power)
{
gdouble ret = 1;
int provide_frac = 0;
if (power == 0)
return 1;
if (power < 0)
{
power *= -1;
provide_frac = 1;
}
while (power > 0)
{
ret = ret * 10;
power--;
}
if (! provide_frac)
return ret;
else
return (1.0/ret);
}
static void
dissect_ppi_sensor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
guint32 version;
guint length;
guint length_remaining;
proto_tree *ppi_sensor_tree = NULL;
proto_tree *present_tree = NULL;
proto_tree *pt, *my_pt;
proto_item *ti = NULL;
proto_item *sensor_line = NULL;
const gchar *type_str = "Unknown sensor";
const gchar *unit_str = "Unknown unit";
int bit;
guint32 present, next_present;
int offset = 0;
guint16 sensortype =0;
gchar scalefactor = 0;
gdouble c_val=0;
guint32 val_t=0;
guint32 t_appspecific_num;
gdouble curr_native_val;
gchar* curr_str;
col_clear(pinfo->cinfo,COL_INFO);
version = tvb_get_guint8(tvb, offset);
length = tvb_get_letohs(tvb, offset+2);
present = tvb_get_letohl(tvb, offset+4);
col_add_fstr(pinfo->cinfo, COL_INFO, "PPI Sensor info v%u, Length %u ",
version, length);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_ppi_sensor,
tvb, 0, length, "PPI Sensor Header v%u, Length %u", version, length);
sensor_line = ti;
ppi_sensor_tree= proto_item_add_subtree(ti, ett_ppi_sensor);
proto_tree_add_uint(ppi_sensor_tree, hf_ppi_sensor_version,
tvb, offset, 1, version);
proto_tree_add_item(ppi_sensor_tree, hf_ppi_sensor_pad,
tvb, offset + 1, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_uint(ppi_sensor_tree, hf_ppi_sensor_length,
tvb, offset + 2, 2, length);
}
if (! (version == 1 || version == 2) ) {
if (tree)
proto_item_append_text(ti, "invalid version (got %d, expected 1 or 2)", version);
return;
}
length_remaining = length;
if (length_remaining < PPI_GEOBASE_MIN_HEADER_LEN) {
if (tree)
proto_item_append_text(ti, " (invalid - minimum length is 8)");
return;
}
if (length > PPI_SENSOR_MAXTAGLEN ) {
if (tree)
proto_item_append_text(ti, "Invalid PPI-Sensor length (got %d, %d max\n)", length, PPI_SENSOR_MAXTAGLEN);
return;
}
if (tree) {
pt = proto_tree_add_uint(ppi_sensor_tree, hf_ppi_sensor_present, tvb, offset + 4, 4, present);
present_tree = proto_item_add_subtree(pt, ett_ppi_sensor_present);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_sensortype, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_scalefactor, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_val_x, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_val_y, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_val_z, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_val_t, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_val_e, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_descstr, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_appspecific_num, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_appspecific_data, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(present_tree, hf_ppi_sensor_present_ext, tvb, 4, 4, ENC_LITTLE_ENDIAN);
}
offset += PPI_GEOBASE_MIN_HEADER_LEN;
length_remaining -= PPI_GEOBASE_MIN_HEADER_LEN;
for (; present; present = next_present) {
next_present = present & (present - 1);
bit = BITNO_32(present ^ next_present);
switch (bit) {
case PPI_SENSOR_SENSORTYPE:
if (length_remaining < 2)
break;
sensortype= tvb_get_letohs(tvb, offset);
type_str = val_to_str_const (sensortype, sensor_type_str, "Unknown Sensor type");
unit_str = val_to_str_const (sensortype, sensor_unit_str, "Unknown Unit");
if (tree) {
my_pt = proto_tree_add_uint(ppi_sensor_tree, hf_ppi_sensor_sensortype, tvb, offset , 2, sensortype);
proto_item_append_text (my_pt, " %s", type_str);
proto_item_set_text(sensor_line, "Sensor: %s", type_str);
}
offset+=2;
length_remaining-=2;
break;
case PPI_SENSOR_SCALEFACTOR:
if (length_remaining < 1)
break;
scalefactor = (gchar) tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_int(ppi_sensor_tree, hf_ppi_sensor_scalefactor, tvb, offset, 1, scalefactor);
}
offset+=1;
length_remaining-=1;
break;
case PPI_SENSOR_VAL_X:
if (length_remaining < 4)
break;
val_t = tvb_get_letohl(tvb, offset);
c_val = ppi_fixed6_4_to_gdouble(val_t);
if (tree) {
my_pt = proto_tree_add_double(ppi_sensor_tree, hf_ppi_sensor_val_x, tvb, offset, 4, c_val);
proto_item_append_text (my_pt, " %s", unit_str);
curr_native_val = c_val * base_10_expt(scalefactor);
proto_item_set_text(sensor_line, "Sensor: %s %f %s", type_str, curr_native_val, unit_str);
}
offset+=4;
length_remaining-=4;
break;
case PPI_SENSOR_VAL_Y:
if (length_remaining < 4)
break;
val_t = tvb_get_letohl(tvb, offset);
c_val = ppi_fixed6_4_to_gdouble(val_t);
if (tree) {
my_pt = proto_tree_add_double(ppi_sensor_tree, hf_ppi_sensor_val_y, tvb, offset, 4, c_val);
proto_item_append_text (my_pt, " %s", unit_str);
curr_native_val = c_val * base_10_expt(scalefactor);
proto_item_set_text(sensor_line, "Sensor: %s %f %s", type_str, curr_native_val, unit_str);
}
offset+=4;
length_remaining-=4;
break;
case PPI_SENSOR_VAL_Z:
if (length_remaining < 4)
break;
val_t = tvb_get_letohl(tvb, offset);
c_val = ppi_fixed6_4_to_gdouble(val_t);
if (tree) {
my_pt = proto_tree_add_double(ppi_sensor_tree, hf_ppi_sensor_val_z, tvb, offset, 4, c_val);
proto_item_append_text (my_pt, " %s", unit_str);
curr_native_val = c_val * base_10_expt(scalefactor);
proto_item_set_text(sensor_line, "Sensor: %s %f %s", type_str, curr_native_val, unit_str);
}
offset+=4;
length_remaining-=4;
break;
case PPI_SENSOR_VAL_T:
if (length_remaining < 4)
break;
val_t = tvb_get_letohl(tvb, offset);
c_val = ppi_fixed6_4_to_gdouble(val_t);
if (tree) {
my_pt = proto_tree_add_double(ppi_sensor_tree, hf_ppi_sensor_val_t, tvb, offset, 4, c_val);
proto_item_append_text (my_pt, " %s", unit_str);
curr_native_val = c_val * base_10_expt(scalefactor);
proto_item_set_text(sensor_line, "Sensor: %s %f %s", type_str, curr_native_val, unit_str);
}
offset+=4;
length_remaining-=4;
break;
case PPI_SENSOR_VAL_E:
if (length_remaining < 4)
break;
val_t = tvb_get_letohl(tvb, offset);
c_val = ppi_fixed6_4_to_gdouble(val_t);
if (tree) {
my_pt = proto_tree_add_double(ppi_sensor_tree, hf_ppi_sensor_val_e, tvb, offset, 4, c_val);
proto_item_append_text (my_pt, " %s", unit_str);
}
offset+=4;
length_remaining-=4;
break;
case PPI_SENSOR_DESCSTR:
if (length_remaining < 32)
break;
if (tree)
{
curr_str = tvb_format_stringzpad(tvb, offset, 32);
proto_tree_add_string(ppi_sensor_tree, hf_ppi_sensor_descstr, tvb, offset, 32, curr_str);
proto_item_append_text(sensor_line, " (%s)", curr_str);
}
offset+=32;
length_remaining-=32;
break;
case PPI_SENSOR_APPID:
if (length_remaining < 4)
break;
t_appspecific_num = tvb_get_letohl(tvb, offset);
if (tree) {
proto_tree_add_uint(ppi_sensor_tree, hf_ppi_sensor_appspecific_num, tvb, offset, 4, t_appspecific_num);
}
offset+=4;
length_remaining-=4;
break;
case PPI_SENSOR_APPDATA:
if (length_remaining < 60)
break;
if (tree) {
proto_tree_add_item(ppi_sensor_tree, hf_ppi_sensor_appspecific_data, tvb, offset, 60, ENC_NA);
}
offset+=60;
length_remaining-=60;
break;
default:
proto_tree_add_text(ppi_sensor_tree, tvb, offset, 0, "Error: PPI-SENSOR: unknown bit (%d) set in present field.\n", bit);
next_present = 0;
continue;
}
};
return;
}
void
proto_register_ppi_sensor(void) {
static hf_register_info hf[] = {
{ &hf_ppi_sensor_version,
{ "Header revision", "ppi_sensor.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Version of ppi_sensor header format", HFILL } },
{ &hf_ppi_sensor_pad,
{ "Header pad", "ppi_sensor.pad",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Padding", HFILL } },
{ &hf_ppi_sensor_length,
{ "Header length", "ppi_sensor.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of header including version, pad, length and data fields", HFILL } },
{ &hf_ppi_sensor_present,
{ "Present", "ppi_sensor.present",
FT_UINT32, BASE_HEX, NULL, 0x0, "Bitmask indicating which fields are present", HFILL } },
#define PPI_SENSOR_MASK_SENSORTYPE 0x00000001
#define PPI_SENSOR_MASK_SCALEFACTOR 0x00000002
#define PPI_SENSOR_MASK_VAL_X 0x00000004
#define PPI_SENSOR_MASK_VAL_Y 0x00000008
#define PPI_SENSOR_MASK_VAL_Z 0x00000010
#define PPI_SENSOR_MASK_VAL_T 0x00000020
#define PPI_SENSOR_MASK_VAL_E 0x00000040
#define PPI_SENSOR_MASK_SERIALNUM 0x04000000
#define PPI_SENSOR_MASK_MODELSTR 0x08000000
#define PPI_SENSOR_MASK_DESCSTR 0x10000000
#define PPI_SENSOR_MASK_APPID 0x20000000
#define PPI_SENSOR_MASK_APPDATA 0x40000000
#define PPI_SENSOR_MASK_EXT 0x80000000
{ &hf_ppi_sensor_present_sensortype,
{ "sensortype", "ppi_sensor.present.sensortype",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_SENSORTYPE,
"Specifies if the sensor type field is present", HFILL } },
{ &hf_ppi_sensor_present_scalefactor,
{ "scalefactor", "ppi_sensor.present.scalefactor",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_SCALEFACTOR,
"Specifies if the sensor scale factor field is present", HFILL } },
{ &hf_ppi_sensor_present_val_x,
{ "val_x", "ppi_sensor.present.val_x",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_VAL_X,
"Specifies if the sensor val_x field is present", HFILL } },
{ &hf_ppi_sensor_present_val_y,
{ "val_y", "ppi_sensor.present.val_y",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_VAL_Y,
"Specifies if the sensor val_y field is present", HFILL } },
{ &hf_ppi_sensor_present_val_z,
{ "val_z", "ppi_sensor.present.val_z",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_VAL_Z,
"Specifies if the BeamID field is present", HFILL } },
{ &hf_ppi_sensor_present_val_t,
{ "val_t", "ppi_sensor.present.val_t",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_VAL_T,
"Specifies if the val_t field is present", HFILL } },
{ &hf_ppi_sensor_present_val_e,
{ "val_e", "ppi_sensor.present.val_e",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_VAL_E,
"Specifies if the val_e field is present", HFILL } },
{ &hf_ppi_sensor_present_descstr,
{ "Description", "ppi_sensor.present.descr",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_DESCSTR,
"Specifies if the description string is present", HFILL } },
{ &hf_ppi_sensor_present_appspecific_num,
{ "appid", "ppi_sensor.present.appid",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_APPID,
"Specifies if the application specific field id is present", HFILL } },
{ &hf_ppi_sensor_present_appspecific_data,
{ "appdata", "ppi_sensor.present.appdata",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_APPDATA,
"Specifies if the application specific data field is present", HFILL } },
{ &hf_ppi_sensor_present_ext,
{ "ext", "ppi_sensor.present.ext",
FT_BOOLEAN, 32, NULL, PPI_SENSOR_MASK_EXT,
"Specifies if there are any extensions to the header present", HFILL } },
{ &hf_ppi_sensor_sensortype,
{ "SensorType", "ppi_sensor.sensortype",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Type of sensor", HFILL } },
{ &hf_ppi_sensor_scalefactor,
{ "ScaleFactor", "ppi_sensor.scalefactor",
FT_INT8, BASE_DEC, NULL, 0x0,
"Scaling factor", HFILL } },
{ &hf_ppi_sensor_val_x,
{ "Val_X", "ppi_sensor.val_x",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Value in X-dimesion", HFILL } },
{ &hf_ppi_sensor_val_y,
{ "Val_Y", "ppi_sensor.val_y",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Value in Y-dimension", HFILL } },
{ &hf_ppi_sensor_val_z,
{ "Val_Z", "ppi_sensor.val_z",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Value in Z-dimension", HFILL } },
{ &hf_ppi_sensor_val_t,
{ "Val_T", "ppi_sensor.val_t",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Value total (dimensionless)", HFILL } },
{ &hf_ppi_sensor_val_e,
{ "Val_E", "ppi_sensor.val_e",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Margin of error", HFILL } },
{ &hf_ppi_sensor_descstr,
{ "Description", "ppi_sensor.descr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } } ,
{ &hf_ppi_sensor_appspecific_num,
{ "Application Specific id", "ppi_sensor.appid",
FT_UINT32, BASE_HEX, NULL, 0x0,
"Application-specific identifier", HFILL } },
{ &hf_ppi_sensor_appspecific_data,
{ "Application specific data", "ppi_sensor.appdata",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Application-specific data", HFILL } },
};
static gint *ett[] = {
&ett_ppi_sensor,
&ett_ppi_sensor_present,
};
proto_ppi_sensor = proto_register_protocol("PPI sensor decoder", "PPI sensor Decoder", "ppi_sensor");
proto_register_field_array(proto_ppi_sensor, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("ppi_sensor", dissect_ppi_sensor, proto_ppi_sensor);
}
