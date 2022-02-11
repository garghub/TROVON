static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_6 V_6 ;
T_3 * V_7 = NULL ;
T_7 V_8 = 0 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
F_3 ( V_2 -> V_9 , V_11 ) ;
if ( V_3 ) {
T_8 * V_12 = F_4 ( V_3 , V_13 , V_1 , 0 , 6 , V_14 ) ;
V_7 = F_5 ( V_12 , V_15 ) ;
F_4 ( V_7 , V_16 , V_1 , V_8 , 1 , V_17 ) ;
V_8 += 1 ;
F_4 ( V_7 , V_18 , V_1 , V_8 , 1 , V_17 ) ;
V_8 += 1 ;
F_4 ( V_7 , V_19 , V_1 , V_8 , 2 , V_17 ) ;
V_8 += 2 ;
F_4 ( V_7 , V_20 , V_1 , V_8 , 2 , V_17 ) ;
}
V_5 = F_6 ( V_1 , 6 ) ;
#if 0
if (encap_proto <= IEEE_802_3_MAX_LEN) {
gboolean is_802_2 = TRUE;
if (tvb_captured_length_remaining(tvb, 4) >= 2) {
if (tvb_get_ntohs(tvb, 4) == 0xffff)
is_802_2 = FALSE;
}
dissect_802_3(encap_proto, is_802_2, tvb, 4, pinfo, tree, cmd_tree, hf_eth_type, hf_cmd_trailer, 0);
} else {
#endif
V_6 . V_21 = V_5 ;
V_6 . V_22 = 8 ;
V_6 . V_23 = V_7 ;
V_6 . V_24 = V_25 ;
V_6 . V_26 = V_27 ;
V_6 . V_28 = 0 ;
F_7 ( V_29 , V_1 , V_2 , V_3 , & V_6 ) ;
return F_8 ( V_1 ) ;
}
void
F_9 ( void )
{
static T_9 V_30 [] = {
{ & V_16 ,
{ L_2 , L_3 , V_31 , V_32 , NULL , 0x0 , NULL , V_33 }
} ,
{ & V_18 ,
{ L_4 , L_5 , V_31 , V_32 , NULL , 0x0 , NULL , V_33 }
} ,
{ & V_19 ,
{ L_6 , L_7 , V_34 , V_35 , NULL , 0x0 , NULL , V_33 }
} ,
{ & V_20 ,
{ L_8 , L_9 , V_34 , V_32 , NULL , 0x0 , NULL , V_33 }
} ,
{ & V_25 ,
{ L_10 , L_11 , V_34 , V_35 , F_10 ( V_36 ) , 0x0 , NULL , V_33 }
} ,
{ & V_27 ,
{ L_12 , L_13 , V_37 , V_38 , NULL , 0x0 , NULL , V_33 }
} ,
} ;
static T_7 * V_39 [] = {
& V_15
} ;
V_13 = F_11 ( L_14 , L_14 , L_15 ) ;
F_12 ( V_13 , V_30 , F_13 ( V_30 ) ) ;
F_14 ( V_39 , F_13 ( V_39 ) ) ;
}
void
F_15 ( void )
{
T_10 V_40 ;
V_29 = F_16 ( L_16 , V_13 ) ;
V_40 = F_17 ( F_1 , V_13 ) ;
F_18 ( L_16 , V_41 , V_40 ) ;
}
