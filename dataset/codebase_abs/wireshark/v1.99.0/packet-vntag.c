static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_3 * V_5 = NULL ;
T_5 V_6 ;
F_2 ( V_2 -> V_7 , V_8 , L_1 ) ;
F_3 ( V_2 -> V_7 , V_9 ) ;
if ( V_3 ) {
T_6 * V_10 = F_4 ( V_3 , V_11 , V_1 , 0 , 4 , V_12 ) ;
V_5 = F_5 ( V_10 , V_13 ) ;
}
V_4 = F_6 ( V_1 , 4 ) ;
#if 0
if (encap_proto <= IEEE_802_3_MAX_LEN) {
gboolean is_802_2;
is_802_2 = TRUE;
if (tvb_length_remaining(tvb, 4) >= 2) {
if (tvb_get_ntohs(tvb, 4) == 0xffff)
is_802_2 = FALSE;
}
dissect_802_3(encap_proto, is_802_2, tvb, 4, pinfo, tree, vntag_tree, hf_vntag_len, hf_vntag_trailer, 0);
} else {
#endif
V_6 . V_14 = V_4 ;
V_6 . V_15 = 6 ;
V_6 . V_16 = V_5 ;
V_6 . V_17 = V_18 ;
V_6 . V_19 = V_20 ;
V_6 . V_21 = 0 ;
F_7 ( V_22 , V_1 , V_2 , V_3 , & V_6 ) ;
#if 0
}
#endif
}
void
F_8 ( void )
{
static T_7 V_23 [] = {
{ & V_18 ,
{ L_2 , L_3 , V_24 , V_25 , F_9 ( V_26 ) , 0x0 , NULL , V_27 }
} ,
#if 0
{ &hf_vntag_len,
{ "Length", "vntag.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_20 ,
{ L_4 , L_5 , V_28 , V_29 , NULL , 0x0 , NULL , V_27 }
}
} ;
static T_8 * V_30 [] = {
& V_13
} ;
V_11 = F_10 ( L_6 , L_1 , L_7 ) ;
F_11 ( V_11 , V_23 , F_12 ( V_23 ) ) ;
F_13 ( V_30 , F_12 ( V_30 ) ) ;
}
void
F_14 ( void )
{
T_9 V_31 ;
V_31 = F_15 ( F_1 , V_11 ) ;
F_16 ( L_8 , 0x8926 , V_31 ) ;
V_22 = F_17 ( L_8 ) ;
}
