static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_5 V_5 ;
T_3 * V_6 = NULL ;
T_6 V_7 = 0 ;
F_2 ( V_2 -> V_8 , V_9 , L_1 ) ;
F_3 ( V_2 -> V_8 , V_10 ) ;
if ( V_3 ) {
T_7 * V_11 = F_4 ( V_3 , V_12 , V_1 , 0 , 6 , V_13 ) ;
V_6 = F_5 ( V_11 , V_14 ) ;
F_4 ( V_6 , V_15 , V_1 , V_7 , 1 , V_16 ) ;
V_7 += 1 ;
F_4 ( V_6 , V_17 , V_1 , V_7 , 1 , V_16 ) ;
V_7 += 1 ;
F_4 ( V_6 , V_18 , V_1 , V_7 , 2 , V_16 ) ;
V_7 += 2 ;
F_4 ( V_6 , V_19 , V_1 , V_7 , 2 , V_16 ) ;
}
V_4 = F_6 ( V_1 , 6 ) ;
#if 0
if (encap_proto <= IEEE_802_3_MAX_LEN) {
gboolean is_802_2 = TRUE;
if (tvb_length_remaining(tvb, 4) >= 2) {
if (tvb_get_ntohs(tvb, 4) == 0xffff)
is_802_2 = FALSE;
}
dissect_802_3(encap_proto, is_802_2, tvb, 4, pinfo, tree, cmd_tree, hf_eth_type, hf_cmd_trailer, 0);
} else {
#endif
V_5 . V_20 = V_4 ;
V_5 . V_21 = 8 ;
V_5 . V_22 = V_6 ;
V_5 . V_23 = V_24 ;
V_5 . V_25 = V_26 ;
V_5 . V_27 = 0 ;
F_7 ( V_28 , V_1 , V_2 , V_3 , & V_5 ) ;
}
void
F_8 ( void )
{
static T_8 V_29 [] = {
{ & V_15 ,
{ L_2 , L_3 , V_30 , V_31 , NULL , 0x0 , NULL , V_32 }
} ,
{ & V_17 ,
{ L_4 , L_5 , V_30 , V_31 , NULL , 0x0 , NULL , V_32 }
} ,
{ & V_18 ,
{ L_6 , L_7 , V_33 , V_34 , NULL , 0x0 , NULL , V_32 }
} ,
{ & V_19 ,
{ L_8 , L_9 , V_33 , V_31 , NULL , 0x0 , NULL , V_32 }
} ,
{ & V_24 ,
{ L_10 , L_11 , V_33 , V_34 , F_9 ( V_35 ) , 0x0 , NULL , V_32 }
} ,
{ & V_26 ,
{ L_12 , L_13 , V_36 , V_37 , NULL , 0x0 , NULL , V_32 }
} ,
} ;
static T_6 * V_38 [] = {
& V_14
} ;
V_12 = F_10 ( L_14 , L_14 , L_15 ) ;
F_11 ( V_12 , V_29 , F_12 ( V_29 ) ) ;
F_13 ( V_38 , F_12 ( V_38 ) ) ;
}
void
F_14 ( void )
{
T_9 V_39 ;
V_28 = F_15 ( L_16 ) ;
V_39 = F_16 ( F_1 , V_12 ) ;
F_17 ( L_16 , V_40 , V_39 ) ;
}
