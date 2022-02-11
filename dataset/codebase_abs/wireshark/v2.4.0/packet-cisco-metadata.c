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
static int
F_9 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_8 * V_12 = NULL ;
T_3 * V_7 = NULL ;
T_5 V_5 ;
T_1 * V_30 ;
T_7 V_8 = 0 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
F_3 ( V_2 -> V_9 , V_11 ) ;
if ( V_3 ) {
V_12 = F_4 ( V_3 , V_13 , V_1 , 0 , 6 , V_14 ) ;
V_7 = F_5 ( V_12 , V_15 ) ;
}
V_5 = F_6 ( V_1 , 0 ) ;
F_4 ( V_7 , V_25 , V_1 , V_8 , 2 , V_17 ) ;
V_8 += 2 ;
F_4 ( V_7 , V_16 , V_1 , V_8 , 1 , V_17 ) ;
V_8 += 1 ;
F_4 ( V_7 , V_18 , V_1 , V_8 , 1 , V_17 ) ;
V_8 += 1 ;
F_4 ( V_7 , V_19 , V_1 , V_8 , 2 , V_17 ) ;
V_8 += 2 ;
F_4 ( V_7 , V_20 , V_1 , V_8 , 2 , V_17 ) ;
V_8 += 2 ;
V_30 = F_10 ( V_1 , V_8 ) ;
if ( ! F_11 ( V_31 , V_5 , V_30 , V_2 , V_3 ) )
F_12 ( V_30 , V_2 , V_3 ) ;
return F_8 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_9 V_32 [] = {
{ & V_16 ,
{ L_2 , L_3 , V_33 , V_34 , NULL , 0x0 , NULL , V_35 }
} ,
{ & V_18 ,
{ L_4 , L_5 , V_33 , V_34 , NULL , 0x0 , NULL , V_35 }
} ,
{ & V_19 ,
{ L_6 , L_7 , V_36 , V_37 , NULL , 0x0 , NULL , V_35 }
} ,
{ & V_20 ,
{ L_8 , L_9 , V_36 , V_34 , NULL , 0x0 , NULL , V_35 }
} ,
{ & V_25 ,
{ L_10 , L_11 , V_36 , V_37 , F_14 ( V_38 ) , 0x0 , NULL , V_35 }
} ,
{ & V_27 ,
{ L_12 , L_13 , V_39 , V_40 , NULL , 0x0 , NULL , V_35 }
} ,
} ;
static T_7 * V_41 [] = {
& V_15
} ;
V_13 = F_15 ( L_14 , L_14 , L_15 ) ;
F_16 ( V_13 , V_32 , F_17 ( V_32 ) ) ;
F_18 ( V_41 , F_17 ( V_41 ) ) ;
}
void
F_19 ( void )
{
T_10 V_42 ;
T_10 V_43 ;
V_29 = F_20 ( L_16 , V_13 ) ;
V_31 = F_21 ( L_17 ) ;
V_42 = F_22 ( F_1 , V_13 ) ;
V_43 = F_22 ( F_9 , V_13 ) ;
F_23 ( L_16 , V_44 , V_42 ) ;
F_23 ( L_17 , V_44 , V_43 ) ;
}
