static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 4 ;
F_2 ( V_2 -> V_5 , V_6 , L_1 ) ;
F_3 ( V_2 -> V_5 , V_7 ) ;
while ( F_4 ( V_1 , V_4 ) > 0 ) {
T_4 * V_8 = NULL ;
T_3 * V_9 = NULL ;
T_5 V_10 , V_11 ;
T_1 * V_12 ;
T_5 V_13 ;
T_6 V_14 = FALSE , V_15 = TRUE ;
T_7 V_16 = 2 ;
V_11 = F_5 ( V_1 , V_4 ) ;
V_10 = F_5 ( V_1 , V_4 + 1 ) ;
#if 0
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(msg_type, ehdlc_protocol_vals,
"unknown 0x%02x"));
#endif
if ( V_3 ) {
V_8 = F_6 ( V_3 , V_17 ,
V_1 , V_4 , F_7 ( V_10 , F_8 ( V_1 , V_4 ) ) ,
L_2 ,
F_9 ( V_11 , V_18 ,
L_3 ) ) ;
V_9 = F_10 ( V_8 , V_19 ) ;
F_11 ( V_9 , V_20 ,
V_1 , V_4 , 1 , V_21 ) ;
#if 0
proto_tree_add_item(ehdlc_tree, hf_ehdlc_sapi,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ehdlc_tree, hf_ehdlc_c_r,
tvb, offset, 1, ENC_BIG_ENDIAN);
#endif
F_11 ( V_9 , V_22 ,
V_1 , V_4 + 1 , 1 , V_21 ) ;
}
V_13 = F_12 ( V_1 , V_4 + 2 , V_2 , V_9 , V_23 ,
V_24 , & V_25 , & V_26 ,
NULL , NULL , V_14 , V_15 , FALSE ) ;
V_16 += F_13 ( V_13 , V_15 ) ;
if ( F_14 ( V_13 ) ) {
V_12 = F_15 ( V_1 , V_4 + V_16 ,
V_10 - V_16 ) ;
switch ( V_11 ) {
case 0x20 :
if ( V_10 <= 4 )
break;
F_16 ( V_27 [ V_28 ] , V_12 , V_2 , V_3 ) ;
break;
case 0xbc :
case 0xdc :
case 0xa0 :
case 0xc0 :
if ( V_10 <= 4 )
break;
F_16 ( V_27 [ V_29 ] , V_12 , V_2 , V_3 ) ;
break;
default:
F_16 ( V_27 [ V_30 ] , V_12 , V_2 , V_3 ) ;
break;
}
} else if ( V_13 == ( V_31 | V_32 ) ) {
F_11 ( V_9 , V_33 ,
V_1 , V_4 + V_16 ,
V_10 - V_16 , V_34 ) ;
}
if ( V_10 == 0 )
V_10 = 1 ;
V_4 += V_10 ;
}
}
void
F_17 ( void )
{
static T_8 V_35 [] = {
{ & V_22 ,
{ L_4 , L_5 ,
V_36 , V_37 , NULL , 0x0 ,
L_6 , V_38 }
} ,
{ & V_20 ,
{ L_7 , L_8 ,
V_36 , V_39 , F_18 ( V_18 ) , 0x0 ,
L_9 , V_38 }
} ,
#if 0
{ &hf_ehdlc_sapi,
{ "SAPI", "ehdlc.sapi",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_ehdlc_c_r,
{ "C/R", "ehdlc.c_r",
FT_UINT8, BASE_HEX, NULL, 0x20,
NULL, HFILL }
},
#endif
{ & V_33 ,
{ L_10 , L_11 ,
V_40 , V_41 , NULL , 0 ,
NULL , V_38 }
} ,
{ & V_23 ,
{ L_12 , L_13 ,
V_42 , V_39 , NULL , 0 ,
NULL , V_38 }
} ,
{ & V_43 ,
{ L_14 , L_15 ,
V_42 , V_37 , NULL , V_44 ,
NULL , V_38 }
} ,
{ & V_45 ,
{ L_16 , L_17 ,
V_42 , V_37 , NULL , V_46 ,
NULL , V_38 }
} ,
{ & V_47 ,
{ L_18 , L_19 ,
V_48 , 8 , F_19 ( & V_49 ) , V_50 ,
NULL , V_38 }
} ,
{ & V_51 ,
{ L_18 , L_19 ,
V_48 , 16 , F_19 ( & V_49 ) , V_52 ,
NULL , V_38 }
} ,
{ & V_53 ,
{ L_20 , L_21 ,
V_48 , 8 , F_19 ( & V_49 ) , V_50 ,
NULL , V_38 }
} ,
{ & V_54 ,
{ L_20 , L_21 ,
V_48 , 16 , F_19 ( & V_49 ) , V_52 ,
NULL , V_38 }
} ,
{ & V_55 ,
{ L_22 , L_23 ,
V_42 , V_39 , F_18 ( V_56 ) , V_57 ,
NULL , V_38 }
} ,
{ & V_58 ,
{ L_24 , L_25 ,
V_36 , V_39 , F_18 ( V_59 ) , V_60 ,
NULL , V_38 }
} ,
{ & V_61 ,
{ L_26 , L_27 ,
V_36 , V_39 , F_18 ( V_62 ) , V_60 ,
NULL , V_38 }
} ,
{ & V_63 ,
{ L_28 , L_29 ,
V_42 , V_39 , F_18 ( V_64 ) , V_65 ,
NULL , V_38 }
} ,
{ & V_66 ,
{ L_28 , L_29 ,
V_36 , V_39 , F_18 ( V_64 ) , V_67 ,
NULL , V_38 }
} ,
{ & V_68 ,
{ L_28 , L_29 ,
V_42 , V_39 , F_18 ( V_64 ) , V_67 ,
NULL , V_38 }
} ,
} ;
static T_7 * V_69 [] = {
& V_19 ,
& V_24 ,
} ;
V_17 =
F_20 ( L_30 ,
L_31 , L_32 ) ;
F_21 ( V_17 , V_35 , F_22 ( V_35 ) ) ;
F_23 ( V_69 , F_22 ( V_69 ) ) ;
F_24 ( L_32 , F_1 , V_17 ) ;
}
void
F_25 ( void )
{
V_27 [ V_28 ] = F_26 ( L_33 ) ;
V_27 [ V_29 ] = F_26 ( L_34 ) ;
V_27 [ V_30 ] = F_26 ( L_35 ) ;
}
