static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_3 * V_5 = NULL ;
F_2 ( V_2 -> V_6 , V_7 , L_1 ) ;
F_3 ( V_2 -> V_6 , V_8 ) ;
if ( V_3 ) {
T_5 * V_9 = F_4 ( V_3 , V_10 , V_1 , 0 , 4 , V_11 ) ;
V_5 = F_5 ( V_9 , V_12 ) ;
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
} else
#endif
F_7 ( V_4 , V_1 , 6 , V_2 , V_3 , V_5 , V_13 , V_14 , 0 ) ;
}
void
F_8 ( void )
{
static T_6 V_15 [] = {
{ & V_13 ,
{ L_2 , L_3 , V_16 , V_17 , F_9 ( V_18 ) , 0x0 , NULL , V_19 }
} ,
#if 0
{ &hf_vntag_len,
{ "Length", "vntag.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_14 ,
{ L_4 , L_5 , V_20 , V_21 , NULL , 0x0 , NULL , V_19 }
}
} ;
static T_7 * V_22 [] = {
& V_12
} ;
V_10 = F_10 ( L_6 , L_1 , L_7 ) ;
F_11 ( V_10 , V_15 , F_12 ( V_15 ) ) ;
F_13 ( V_22 , F_12 ( V_22 ) ) ;
}
void
F_14 ( void )
{
T_8 V_23 ;
V_23 = F_15 ( F_1 , V_10 ) ;
F_16 ( L_8 , 0x8926 , V_23 ) ;
}
