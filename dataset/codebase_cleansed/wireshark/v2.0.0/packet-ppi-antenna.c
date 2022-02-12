static void
dissect_ppi_antenna(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
guint32 version;
guint length;
gint length_remaining;
proto_tree *ppi_antenna_tree = NULL;
proto_tree *antennaflags_tree = NULL;
proto_tree *pt, *my_pt;
proto_item *ti = NULL;
proto_item *antenna_line = NULL;
int bit;
guint32 present, next_present;
guint8 gaindb;
guint16 beamid;
guint32 t_hbw, t_vbw, t_pgain, t_appspecific_num;
gdouble horizbw, vertbw, pgain;
guint32 flags;
gchar *curr_str;
int offset = 0;
static const int * ppi_antenna_present_flags[] = {
&hf_ppi_antenna_present_flags,
&hf_ppi_antenna_present_gaindb,
&hf_ppi_antenna_present_horizbw,
&hf_ppi_antenna_present_vertbw,
&hf_ppi_antenna_present_pgain,
&hf_ppi_antenna_present_beamid,
&hf_ppi_antenna_present_serialnum,
&hf_ppi_antenna_present_modelname,
&hf_ppi_antenna_present_descstr,
&hf_ppi_antenna_present_appspecific_num,
&hf_ppi_antenna_present_appspecific_data,
&hf_ppi_antenna_present_ext,
NULL
};
col_clear(pinfo->cinfo,COL_INFO);
version = tvb_get_guint8(tvb, offset);
length = tvb_get_letohs(tvb, offset+2);
present = tvb_get_letohl(tvb, offset+4);
col_add_fstr(pinfo->cinfo, COL_INFO, "PPI Antenna info v%u, Length %u",
version, length);
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_ppi_antenna,
tvb, 0, length, "Antenna: ");
antenna_line = ti;
ppi_antenna_tree= proto_item_add_subtree(ti, ett_ppi_antenna);
proto_tree_add_uint(ppi_antenna_tree, hf_ppi_antenna_version,
tvb, offset, 1, version);
proto_tree_add_item(ppi_antenna_tree, hf_ppi_antenna_pad,
tvb, offset + 1, 1, ENC_LITTLE_ENDIAN);
ti = proto_tree_add_uint(ppi_antenna_tree, hf_ppi_antenna_length,
tvb, offset + 2, 2, length);
}
if (! (version == 1 || version == 2) ) {
if (tree)
proto_item_append_text(ti, "invalid version (got %d, expected 1 or 2)", version);
return;
}
length_remaining = length;
if (length_remaining < PPI_GEOBASE_MIN_HEADER_LEN) {
proto_item_append_text(ti, " (invalid - minimum length is 8)");
return;
}
if (length > PPI_ANTENNA_MAXTAGLEN ) {
proto_item_append_text(ti, "Invalid PPI-Antenna length (got %d, %d max\n)", length, PPI_ANTENNA_MAXTAGLEN);
return;
}
pt = proto_tree_add_bitmask(ppi_antenna_tree, tvb, offset + 4, hf_ppi_antenna_present, ett_ppi_antenna_present, ppi_antenna_present_flags, ENC_LITTLE_ENDIAN);
offset += PPI_GEOBASE_MIN_HEADER_LEN;
length_remaining -= PPI_GEOBASE_MIN_HEADER_LEN;
for (; present; present = next_present) {
next_present = present & (present - 1);
bit = BITNO_32(present ^ next_present);
switch (bit) {
case PPI_ANTENNA_ANTFLAGS:
if (length_remaining < 4)
break;
flags = tvb_get_letohl(tvb, offset);
if (tree) {
my_pt = proto_tree_add_uint(ppi_antenna_tree, hf_ppi_antenna_flags, tvb, offset , 4, flags);
antennaflags_tree= proto_item_add_subtree(my_pt, ett_ppi_antennaflags);
proto_tree_add_item(antennaflags_tree, hf_ppi_antennaflags_mimo, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(antennaflags_tree, hf_ppi_antennaflags_horizpol, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(antennaflags_tree, hf_ppi_antennaflags_vertpol, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(antennaflags_tree, hf_ppi_antennaflags_circpol_l, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(antennaflags_tree, hf_ppi_antennaflags_circpol_r, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(antennaflags_tree, hf_ppi_antennaflags_steer_elec, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(antennaflags_tree, hf_ppi_antennaflags_steer_mech, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
offset+=4;
length_remaining-=4;
break;
case PPI_ANTENNA_GAINDB:
if (length_remaining < 1)
break;
gaindb= tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(ppi_antenna_tree, hf_ppi_antenna_gaindb, tvb, offset, 1, gaindb);
proto_item_append_text(antenna_line, " Gain: %d", gaindb);
}
offset+=1;
length_remaining-=1;
break;
case PPI_ANTENNA_HORIZBW:
if (length_remaining < 4)
break;
t_hbw = tvb_get_letohl(tvb, offset);
horizbw = ppi_fixed3_6_to_gdouble(t_hbw);
if (tree) {
proto_tree_add_double(ppi_antenna_tree, hf_ppi_antenna_horizbw, tvb, offset, 4, horizbw);
proto_item_append_text(antenna_line, " HorizBw: %f", horizbw);
}
offset+=4;
length_remaining-=4;
break;
case PPI_ANTENNA_VERTBW:
if (length_remaining < 4)
break;
t_vbw = tvb_get_letohl(tvb, offset);
vertbw = ppi_fixed3_6_to_gdouble(t_vbw);
proto_tree_add_double(ppi_antenna_tree, hf_ppi_antenna_vertbw, tvb, offset, 4, vertbw);
offset+=4;
length_remaining-=4;
break;
case PPI_ANTENNA_PGAIN:
if (length_remaining < 4)
break;
t_pgain = tvb_get_letohl(tvb, offset);
pgain = ppi_fixed3_6_to_gdouble(t_pgain);
proto_tree_add_double(ppi_antenna_tree, hf_ppi_antenna_pgain, tvb, offset, 4, pgain);
offset+=4;
length_remaining-=4;
break;
case PPI_ANTENNA_BEAMID:
if (length_remaining < 2)
break;
beamid= tvb_get_letohs(tvb, offset);
proto_tree_add_uint(ppi_antenna_tree, hf_ppi_antenna_beamid, tvb, offset, 2, beamid);
offset+=2;
length_remaining-=2;
break;
case PPI_ANTENNA_SERIALNUM:
if (length_remaining < 32)
break;
proto_tree_add_item(ppi_antenna_tree, hf_ppi_antenna_serialnum, tvb, offset, 32, ENC_ASCII|ENC_NA);
offset+=32;
length_remaining-=32;
break;
case PPI_ANTENNA_MODELSTR:
if (length_remaining < 32)
break;
if (tree) {
curr_str = tvb_format_stringzpad(tvb, offset, 32);
proto_tree_add_string(ppi_antenna_tree, hf_ppi_antenna_modelname, tvb, offset, 32, curr_str);
proto_item_append_text(antenna_line, " (%s)", curr_str);
}
offset+=32;
length_remaining-=32;
break;
case PPI_ANTENNA_DESCSTR:
if (length_remaining < 32)
break;
if (tree) {
curr_str = tvb_format_stringzpad(tvb, offset, 32);
proto_tree_add_string(ppi_antenna_tree, hf_ppi_antenna_descstr, tvb, offset, 32, curr_str);
proto_item_append_text(antenna_line, " (%s)", curr_str);
}
offset+=32;
length_remaining-=32;
break;
case PPI_ANTENNA_APPID:
if (length_remaining < 4)
break;
t_appspecific_num = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(ppi_antenna_tree, hf_ppi_antenna_appspecific_num, tvb, offset, 4, t_appspecific_num);
offset+=4;
length_remaining-=4;
break;
case PPI_ANTENNA_APPDATA:
if (length_remaining < 60)
break;
proto_tree_add_item(ppi_antenna_tree, hf_ppi_antenna_appspecific_data, tvb, offset, 60, ENC_NA);
offset+=60;
length_remaining-=60;
break;
default:
expert_add_info_format(pinfo, pt, &ei_ppi_antenna_present_bit,
"Error: PPI-ANTENNA: unknown bit (%d) set in present field.", bit);
next_present = 0;
continue;
}
};
return;
}
void
proto_register_ppi_antenna(void) {
static hf_register_info hf[] = {
{ &hf_ppi_antenna_version,
{ "Header revision", "ppi_antenna.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Version of ppi_antenna header format", HFILL } },
{ &hf_ppi_antenna_pad,
{ "Header pad", "ppi_antenna.pad",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Padding", HFILL } },
{ &hf_ppi_antenna_length,
{ "Header length", "ppi_antenna.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of header including version, pad, length and data fields", HFILL } },
{ &hf_ppi_antenna_flags,
{ "Antenna flags", "ppi_antenna.antenna_flags",
FT_UINT32, BASE_HEX, NULL, 0x0, "Bitmask indicating polarity, etc", HFILL } },
{ &hf_ppi_antenna_present,
{ "Present", "ppi_antenna.present",
FT_UINT32, BASE_HEX, NULL, 0x0, "Bitmask indicating which fields are present", HFILL } },
#define PPI_ANTENNA_MASK_FLAGS 0x00000001
#define PPI_ANTENNA_MASK_GAINDB 0x00000002
#define PPI_ANTENNA_MASK_HORIZBW 0x00000004
#define PPI_ANTENNA_MASK_VERTBW 0x00000008
#define PPI_ANTENNA_MASK_PGAIN 0x00000010
#define PPI_ANTENNA_MASK_BEAMID 0x00000020
#define PPI_ANTENNA_MASK_RES7 0x00000080
#define PPI_ANTENNA_MASK_SERIALNUM 0x04000000
#define PPI_ANTENNA_MASK_MODELSTR 0x08000000
#define PPI_ANTENNA_MASK_DESCSTR 0x10000000
#define PPI_ANTENNA_MASK_APPID 0x20000000
#define PPI_ANTENNA_MASK_APPDATA 0x40000000
#define PPI_ANTENNA_MASK_EXT 0x80000000
#define PPI_ANTENNAFLAGS_MASK_MIMO 0x00000001
#define PPI_ANTENNAFLAGS_MASK_HPOL 0x00000002
#define PPI_ANTENNAFLAGS_MASK_VPOL 0x00000004
#define PPI_ANTENNAFLAGS_MASK_CPOL_L 0x00000008
#define PPI_ANTENNAFLAGS_MASK_CPOL_R 0x00000010
#define PPI_ANTENNAFLAGS_MASK_STEER_ELEC 0x00010000
#define PPI_ANTENNAFLAGS_MASK_STEER_MECH 0x00020000
{ &hf_ppi_antenna_present_flags,
{ "flags", "ppi_antenna.present.flags",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_FLAGS,
"Specifies if the flags bitfield is present", HFILL } },
{ &hf_ppi_antenna_present_gaindb,
{ "gaindb", "ppi_antenna.present.gaindb",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_GAINDB,
"Specifies if the antenna gain field is present", HFILL } },
{ &hf_ppi_antenna_present_horizbw,
{ "horizbw", "ppi_antenna.present.horizbw",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_HORIZBW,
"Specifies if the horizontal beamwidth field is present", HFILL } },
{ &hf_ppi_antenna_present_vertbw,
{ "vertbw", "ppi_antenna.present.vertbw",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_VERTBW,
"Specifies if the vertical beamwidth field is present", HFILL } },
{ &hf_ppi_antenna_present_pgain,
{ "pgain", "ppi_antenna.present.pgain",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_PGAIN,
"Specifies if the precision gain field is present", HFILL } },
{ &hf_ppi_antenna_present_beamid,
{ "beamid", "ppi_antenna.present.beamid",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_BEAMID,
"Specifies if the BeamID field is present", HFILL } },
{ &hf_ppi_antenna_present_serialnum,
{ "serialnum", "ppi_antenna.present.serialnum",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_SERIALNUM,
"Specifies if the serial num is present", HFILL } },
{ &hf_ppi_antenna_present_modelname,
{ "modelname", "ppi_antenna.present.modelname",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_MODELSTR,
"Specifies if the model name is present", HFILL } },
{ &hf_ppi_antenna_present_descstr,
{ "Description", "ppi_antenna.present.descr",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_DESCSTR,
"Specifies if the description string is present", HFILL } },
{ &hf_ppi_antenna_present_appspecific_num,
{ "appid", "ppi_antenna.present.appid",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_APPID,
"Specifies if the application specific field id is present", HFILL } },
{ &hf_ppi_antenna_present_appspecific_data,
{ "appdata", "ppi_antenna.present.appdata",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_APPDATA,
"Specifies if the application specific data field is present", HFILL } },
{ &hf_ppi_antenna_present_ext,
{ "ext", "ppi_antenna.present.ext",
FT_BOOLEAN, 32, NULL, PPI_ANTENNA_MASK_EXT,
"Specifies if there are any extensions to the header present", HFILL } },
{ &hf_ppi_antennaflags_mimo,
{ "mimo", "ppi_antenna.antennaflags.mimo",
FT_BOOLEAN, 32, NULL, PPI_ANTENNAFLAGS_MASK_MIMO,
"Antenna is part of MIMO system", HFILL } },
{ &hf_ppi_antennaflags_horizpol,
{ "horizontally polarized", "ppi_antenna.antennaflags.horizpol",
FT_BOOLEAN, 32, NULL, PPI_ANTENNAFLAGS_MASK_HPOL,
"Specifies if the antenna is horizontally polarized", HFILL } },
{ &hf_ppi_antennaflags_vertpol,
{ "vertically polarized", "ppi_antenna.antennaflags.vertpol",
FT_BOOLEAN, 32, NULL, PPI_ANTENNAFLAGS_MASK_VPOL,
"Specifies if the antenna is vertically polarized", HFILL } },
{ &hf_ppi_antennaflags_circpol_l,
{ "circularly polarized left", "ppi_antenna.antennaflags.circpol_l",
FT_BOOLEAN, 32, NULL, PPI_ANTENNAFLAGS_MASK_CPOL_L,
"Specifies if the antenna is circularly polarized, left handed", HFILL } },
{ &hf_ppi_antennaflags_circpol_r,
{ "circularly polarized right", "ppi_antenna.antennaflags.circpol_r",
FT_BOOLEAN, 32, NULL, PPI_ANTENNAFLAGS_MASK_CPOL_R,
"Specifies if the antenna is circularly polarized, right handed", HFILL } },
{ &hf_ppi_antennaflags_steer_elec,
{ "electrically steerable", "ppi_antenna.antennaflags.steer_elec",
FT_BOOLEAN, 32, NULL, PPI_ANTENNAFLAGS_MASK_STEER_ELEC,
"Specifies if the antenna is electrically steerable", HFILL } },
{ &hf_ppi_antennaflags_steer_mech,
{ "mechanically steerable", "ppi_antenna.antennaflags.steer_mech",
FT_BOOLEAN, 32, NULL, PPI_ANTENNAFLAGS_MASK_STEER_MECH,
"Specifies if the antenna is mechanically steerable", HFILL } },
{ &hf_ppi_antenna_gaindb,
{ "Gain (dBi)", "ppi_antenna.gaindb",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Gain of antenna (dBi)", HFILL } },
{ &hf_ppi_antenna_horizbw,
{ "HorizBw", "ppi_antenna.horizbw",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Horizontal beamwidth", HFILL } },
{ &hf_ppi_antenna_vertbw,
{ "VertBw", "ppi_antenna.vertbw",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Vertical beamwidth", HFILL } },
{ &hf_ppi_antenna_pgain,
{ "Precision Gain (dBi)", "ppi_antenna.pgain",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_ppi_antenna_beamid,
{ "BeamID", "ppi_antenna.beamid",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_ppi_antenna_serialnum,
{ "SerialNumber", "ppi_antenna.serialnum",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } } ,
{ &hf_ppi_antenna_modelname,
{ "ModelName", "ppi_antenna.modelname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } } ,
{ &hf_ppi_antenna_descstr,
{ "Description", "ppi_antenna.descr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL } } ,
{ &hf_ppi_antenna_appspecific_num,
{ "Application Specific id", "ppi_antenna.appid",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_ppi_antenna_appspecific_data,
{ "Application specific data", "ppi_antenna.appdata",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
};
static gint *ett[] = {
&ett_ppi_antenna,
&ett_ppi_antenna_present,
&ett_ppi_antennaflags
};
static ei_register_info ei[] = {
{ &ei_ppi_antenna_present_bit, { "ppi_antenna.present.unknown_bit", PI_PROTOCOL, PI_WARN, "Error: PPI-ANTENNA: unknown bit set in present field.", EXPFILL }},
};
expert_module_t* expert_ppi_antenna;
proto_ppi_antenna = proto_register_protocol("PPI antenna decoder", "PPI antenna Decoder", "ppi_antenna");
proto_register_field_array(proto_ppi_antenna, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_ppi_antenna = expert_register_protocol(proto_ppi_antenna);
expert_register_field_array(expert_ppi_antenna, ei, array_length(ei));
register_dissector("ppi_antenna", dissect_ppi_antenna, proto_ppi_antenna);
}
