static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_3 * V_5 = NULL ;
T_5 V_6 ;
static const int * V_7 [] = {
& V_8 ,
& V_9 ,
& V_10 ,
& V_11 ,
& V_12 ,
& V_13 ,
& V_14 ,
& V_15 ,
NULL
} ;
F_2 ( V_2 -> V_16 , V_17 , L_1 ) ;
F_3 ( V_2 -> V_16 , V_18 ) ;
if ( V_3 ) {
T_6 * V_19 = F_4 ( V_3 , V_20 , V_1 , 0 , 4 , V_21 ) ;
V_5 = F_5 ( V_19 , V_22 ) ;
F_6 ( V_5 , V_1 , 0 , 4 , V_7 , V_23 ) ;
}
V_4 = F_7 ( V_1 , 4 ) ;
#if 0
if (encap_proto <= IEEE_802_3_MAX_LEN) {
gboolean is_802_2;
is_802_2 = TRUE;
if (tvb_captured_length_remaining(tvb, 4) >= 2) {
if (tvb_get_ntohs(tvb, 4) == 0xffff)
is_802_2 = FALSE;
}
dissect_802_3(encap_proto, is_802_2, tvb, 4, pinfo, tree, vntag_tree, hf_vntag_len, hf_vntag_trailer, 0);
} else {
#endif
V_6 . V_24 = V_4 ;
V_6 . V_25 = 6 ;
V_6 . V_26 = V_5 ;
V_6 . V_27 = V_28 ;
V_6 . V_29 = V_30 ;
V_6 . V_31 = 0 ;
F_8 ( V_32 , V_1 , V_2 , V_3 , & V_6 ) ;
#if 0
}
#endif
}
void
F_9 ( void )
{
static T_7 V_33 [] = {
{ & V_28 ,
{ L_2 , L_3 , V_34 , V_35 , F_10 ( V_36 ) , 0x0 , NULL , V_37 }
} ,
{ & V_8 ,
{ L_4 , L_5 , V_38 , V_39 , NULL , 0x80000000 , NULL , V_37 }
} ,
{ & V_9 ,
{ L_6 , L_7 , V_38 , V_39 , NULL , 0x40000000 , NULL , V_37 }
} ,
{ & V_10 ,
{ L_8 , L_9 , V_38 , V_39 , NULL , 0x30000000 , NULL , V_37 }
} ,
{ & V_11 ,
{ L_10 , L_11 , V_38 , V_39 , NULL , 0x0FFF0000 , NULL , V_37 }
} ,
{ & V_12 ,
{ L_12 , L_13 , V_38 , V_39 , NULL , 0x00008000 , NULL , V_37 }
} ,
{ & V_13 ,
{ L_14 , L_15 , V_38 , V_39 , NULL , 0x00004000 , NULL , V_37 }
} ,
{ & V_14 ,
{ L_16 , L_17 , V_38 , V_39 , NULL , 0x00003000 , NULL , V_37 }
} ,
{ & V_15 ,
{ L_18 , L_19 , V_38 , V_39 , NULL , 0x00000FFF , NULL , V_37 }
} ,
#if 0
{ &hf_vntag_len,
{ "Length", "vntag.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_30 ,
{ L_20 , L_21 , V_40 , V_41 , NULL , 0x0 , NULL , V_37 }
}
} ;
static T_8 * V_42 [] = {
& V_22
} ;
V_20 = F_11 ( L_22 , L_1 , L_23 ) ;
F_12 ( V_20 , V_33 , F_13 ( V_33 ) ) ;
F_14 ( V_42 , F_13 ( V_42 ) ) ;
}
void
F_15 ( void )
{
T_9 V_43 ;
V_43 = F_16 ( F_1 , V_20 ) ;
F_17 ( L_24 , V_44 , V_43 ) ;
V_32 = F_18 ( L_24 ) ;
}
