static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_3 * V_6 = NULL ;
T_6 V_7 ;
static const int * V_8 [] = {
& V_9 ,
& V_10 ,
& V_11 ,
& V_12 ,
& V_13 ,
& V_14 ,
& V_15 ,
& V_16 ,
NULL
} ;
F_2 ( V_2 -> V_17 , V_18 , L_1 ) ;
F_3 ( V_2 -> V_17 , V_19 ) ;
if ( V_3 ) {
T_7 * V_20 = F_4 ( V_3 , V_21 , V_1 , 0 , 4 , V_22 ) ;
V_6 = F_5 ( V_20 , V_23 ) ;
F_6 ( V_6 , V_1 , 0 , 4 , V_8 , V_24 ) ;
}
V_5 = F_7 ( V_1 , 4 ) ;
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
V_7 . V_25 = V_5 ;
V_7 . V_26 = 6 ;
V_7 . V_27 = V_6 ;
V_7 . V_28 = V_29 ;
V_7 . V_30 = V_31 ;
V_7 . V_32 = 0 ;
F_8 ( V_33 , V_1 , V_2 , V_3 , & V_7 ) ;
#if 0
}
#endif
return F_9 ( V_1 ) ;
}
void
F_10 ( void )
{
static T_8 V_34 [] = {
{ & V_29 ,
{ L_2 , L_3 , V_35 , V_36 , F_11 ( V_37 ) , 0x0 , NULL , V_38 }
} ,
{ & V_9 ,
{ L_4 , L_5 , V_39 , V_40 , NULL , 0x80000000 , NULL , V_38 }
} ,
{ & V_10 ,
{ L_6 , L_7 , V_39 , V_40 , NULL , 0x40000000 , NULL , V_38 }
} ,
{ & V_11 ,
{ L_8 , L_9 , V_39 , V_40 , NULL , 0x30000000 , NULL , V_38 }
} ,
{ & V_12 ,
{ L_10 , L_11 , V_39 , V_40 , NULL , 0x0FFF0000 , NULL , V_38 }
} ,
{ & V_13 ,
{ L_12 , L_13 , V_39 , V_40 , NULL , 0x00008000 , NULL , V_38 }
} ,
{ & V_14 ,
{ L_14 , L_15 , V_39 , V_40 , NULL , 0x00004000 , NULL , V_38 }
} ,
{ & V_15 ,
{ L_16 , L_17 , V_39 , V_40 , NULL , 0x00003000 , NULL , V_38 }
} ,
{ & V_16 ,
{ L_18 , L_19 , V_39 , V_40 , NULL , 0x00000FFF , NULL , V_38 }
} ,
#if 0
{ &hf_vntag_len,
{ "Length", "vntag.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_31 ,
{ L_20 , L_21 , V_41 , V_42 , NULL , 0x0 , NULL , V_38 }
}
} ;
static T_9 * V_43 [] = {
& V_23
} ;
V_21 = F_12 ( L_22 , L_1 , L_23 ) ;
F_13 ( V_21 , V_34 , F_14 ( V_34 ) ) ;
F_15 ( V_43 , F_14 ( V_43 ) ) ;
}
void
F_16 ( void )
{
T_10 V_44 ;
V_44 = F_17 ( F_1 , V_21 ) ;
F_18 ( L_24 , V_45 , V_44 ) ;
V_33 = F_19 ( L_24 , V_21 ) ;
}
