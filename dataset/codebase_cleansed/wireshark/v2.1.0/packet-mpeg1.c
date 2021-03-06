static int
dissect_mpeg1( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_ )
{
proto_item *ti;
proto_tree *mpg_tree;
unsigned int offset = 0;
static const int * mpg_fields1[] = {
&hf_rtp_mpg_mbz,
&hf_rtp_mpg_T,
&hf_rtp_mpg_tr,
NULL
};
static const int * mpg_fields2[] = {
&hf_rtp_mpg_an,
&hf_rtp_mpg_n,
&hf_rtp_mpg_s,
&hf_rtp_mpg_b,
&hf_rtp_mpg_e,
&hf_rtp_mpg_p,
NULL
};
static const int * mpg_fields3[] = {
&hf_rtp_mpg_fbv,
&hf_rtp_mpg_bfc,
&hf_rtp_mpg_ffv,
&hf_rtp_mpg_ffc,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MPEG-1");
col_set_str(pinfo->cinfo, COL_INFO, "MPEG-1 message");
ti = proto_tree_add_item( tree, proto_mpg, tvb, offset, -1, ENC_NA );
mpg_tree = proto_item_add_subtree( ti, ett_mpg );
proto_tree_add_bitmask_list(mpg_tree, tvb, offset, 2, mpg_fields1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask_list(mpg_tree, tvb, offset, 2, mpg_fields2, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask_list(mpg_tree, tvb, offset, 1, mpg_fields3, ENC_NA);
offset += 1;
proto_tree_add_item( mpg_tree, hf_rtp_mpg_data, tvb, offset, -1, ENC_NA );
return tvb_captured_length(tvb);
}
void
proto_register_mpeg1(void)
{
static hf_register_info hf[] =
{
{
&hf_rtp_mpg_mbz,
{
"MBZ",
"rtp.payload_mpeg_mbz",
FT_UINT16,
BASE_DEC,
NULL,
0xF800,
NULL, HFILL
}
},
{
&hf_rtp_mpg_T,
{
"T",
"rtp.payload_mpeg_T",
FT_UINT16,
BASE_DEC,
NULL,
0x0400,
NULL, HFILL
}
},
{
&hf_rtp_mpg_tr,
{
"Temporal Reference",
"rtp.payload_mpeg_tr",
FT_UINT16,
BASE_DEC,
NULL,
0x03FF,
NULL, HFILL
}
},
{
&hf_rtp_mpg_an,
{
"AN",
"rtp.payload_mpeg_an",
FT_UINT16,
BASE_DEC,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_rtp_mpg_n,
{
"New Picture Header",
"rtp.payload_mpeg_n",
FT_UINT16,
BASE_DEC,
NULL,
0x40,
NULL, HFILL
}
},
{
&hf_rtp_mpg_s,
{
"Sequence Header",
"rtp.payload_mpeg_s",
FT_BOOLEAN,
16,
NULL,
0x20,
NULL, HFILL
}
},
{
&hf_rtp_mpg_b,
{
"Beginning-of-slice",
"rtp.payload_mpeg_b",
FT_BOOLEAN,
16,
NULL,
0x10,
NULL, HFILL
}
},
{
&hf_rtp_mpg_e,
{
"End-of-slice",
"rtp.payload_mpeg_e",
FT_BOOLEAN,
16,
NULL,
0x08,
NULL, HFILL
}
},
{
&hf_rtp_mpg_p,
{
"Picture type",
"rtp.payload_mpeg_p",
FT_UINT16,
BASE_DEC,
VALS(rtp_mpg_picture_types_vals),
0x07,
NULL, HFILL
}
},
{
&hf_rtp_mpg_fbv,
{
"FBV",
"rtp.payload_mpeg_fbv",
FT_UINT16,
BASE_DEC,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_rtp_mpg_bfc,
{
"BFC",
"rtp.payload_mpeg_bfc",
FT_UINT16,
BASE_DEC,
NULL,
0x70,
NULL, HFILL
}
},
{
&hf_rtp_mpg_ffv,
{
"FFV",
"rtp.payload_mpeg_ffv",
FT_UINT16,
BASE_DEC,
NULL,
0x08,
NULL, HFILL
}
},
{
&hf_rtp_mpg_ffc,
{
"FFC",
"rtp.payload_mpeg_ffc",
FT_UINT16,
BASE_DEC,
NULL,
0x07,
NULL, HFILL
}
},
{
&hf_rtp_mpg_data,
{
"MPEG-1 stream",
"mpeg1.stream",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_mpg,
};
proto_mpg = proto_register_protocol("RFC 2250 MPEG1","MPEG1","mpeg1");
proto_register_field_array(proto_mpg, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mpeg1(void)
{
dissector_handle_t mpeg1_handle;
mpeg1_handle = create_dissector_handle(dissect_mpeg1, proto_mpg);
dissector_add_uint("rtp.pt", PT_MPV, mpeg1_handle);
}
