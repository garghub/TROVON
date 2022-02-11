static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
int V_5 = 4 ;
F_2 ( V_2 -> V_6 , V_7 , L_1 ) ;
F_3 ( V_2 -> V_6 , V_8 ) ;
while ( F_4 ( V_1 , V_5 ) > 0 ) {
T_5 * V_9 = NULL ;
T_3 * V_10 = NULL ;
T_6 V_11 , V_12 ;
T_1 * V_13 ;
T_6 V_14 ;
T_7 V_15 = FALSE , V_16 = TRUE ;
T_8 V_17 = 2 ;
V_12 = F_5 ( V_1 , V_5 ) ;
V_11 = F_5 ( V_1 , V_5 + 1 ) ;
#if 0
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(msg_type, ehdlc_protocol_vals,
"unknown 0x%02x"));
#endif
if ( V_3 ) {
V_9 = F_6 ( V_3 , V_18 ,
V_1 , V_5 , F_7 ( V_11 , F_8 ( V_1 , V_5 ) ) ,
L_2 ,
F_9 ( V_12 , V_19 ,
L_3 ) ) ;
V_10 = F_10 ( V_9 , V_20 ) ;
F_11 ( V_10 , V_21 ,
V_1 , V_5 , 1 , V_22 ) ;
#if 0
proto_tree_add_item(ehdlc_tree, hf_ehdlc_sapi,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ehdlc_tree, hf_ehdlc_c_r,
tvb, offset, 1, ENC_BIG_ENDIAN);
#endif
F_11 ( V_10 , V_23 ,
V_1 , V_5 + 1 , 1 , V_22 ) ;
}
V_14 = F_12 ( V_1 , V_5 + 2 , V_2 , V_10 , V_24 ,
V_25 , & V_26 , & V_27 ,
NULL , NULL , V_15 , V_16 , FALSE ) ;
V_17 += F_13 ( V_14 , V_16 ) ;
if ( F_14 ( V_14 ) ) {
V_13 = F_15 ( V_1 , V_5 + V_17 ,
V_11 - V_17 ) ;
switch ( V_12 ) {
case 0x20 :
if ( V_11 <= 4 )
break;
F_16 ( V_28 [ V_29 ] , V_13 , V_2 , V_3 ) ;
break;
case 0xbc :
case 0xdc :
case 0xa0 :
case 0xc0 :
if ( V_11 <= 4 )
break;
F_16 ( V_28 [ V_30 ] , V_13 , V_2 , V_3 ) ;
break;
default:
F_16 ( V_28 [ V_31 ] , V_13 , V_2 , V_3 ) ;
break;
}
} else if ( V_14 == ( V_32 | V_33 ) ) {
F_11 ( V_10 , V_34 ,
V_1 , V_5 + V_17 ,
V_11 - V_17 , V_35 ) ;
}
if ( V_11 == 0 )
V_11 = 1 ;
V_5 += V_11 ;
}
return F_17 ( V_1 ) ;
}
void
F_18 ( void )
{
static T_9 V_36 [] = {
{ & V_23 ,
{ L_4 , L_5 ,
V_37 , V_38 , NULL , 0x0 ,
L_6 , V_39 }
} ,
{ & V_21 ,
{ L_7 , L_8 ,
V_37 , V_40 , F_19 ( V_19 ) , 0x0 ,
L_9 , V_39 }
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
{ & V_34 ,
{ L_10 , L_11 ,
V_41 , V_42 , NULL , 0 ,
NULL , V_39 }
} ,
{ & V_24 ,
{ L_12 , L_13 ,
V_43 , V_40 , NULL , 0 ,
NULL , V_39 }
} ,
{ & V_44 ,
{ L_14 , L_15 ,
V_43 , V_38 , NULL , V_45 ,
NULL , V_39 }
} ,
{ & V_46 ,
{ L_16 , L_17 ,
V_43 , V_38 , NULL , V_47 ,
NULL , V_39 }
} ,
{ & V_48 ,
{ L_18 , L_19 ,
V_49 , 8 , F_20 ( & V_50 ) , V_51 ,
NULL , V_39 }
} ,
{ & V_52 ,
{ L_18 , L_19 ,
V_49 , 16 , F_20 ( & V_50 ) , V_53 ,
NULL , V_39 }
} ,
{ & V_54 ,
{ L_20 , L_21 ,
V_49 , 8 , F_20 ( & V_50 ) , V_51 ,
NULL , V_39 }
} ,
{ & V_55 ,
{ L_20 , L_21 ,
V_49 , 16 , F_20 ( & V_50 ) , V_53 ,
NULL , V_39 }
} ,
{ & V_56 ,
{ L_22 , L_23 ,
V_43 , V_40 , F_19 ( V_57 ) , V_58 ,
NULL , V_39 }
} ,
{ & V_59 ,
{ L_24 , L_25 ,
V_37 , V_40 , F_19 ( V_60 ) , V_61 ,
NULL , V_39 }
} ,
{ & V_62 ,
{ L_26 , L_27 ,
V_37 , V_40 , F_19 ( V_63 ) , V_61 ,
NULL , V_39 }
} ,
{ & V_64 ,
{ L_28 , L_29 ,
V_43 , V_40 , F_19 ( V_65 ) , V_66 ,
NULL , V_39 }
} ,
{ & V_67 ,
{ L_28 , L_29 ,
V_37 , V_40 , F_19 ( V_65 ) , V_68 ,
NULL , V_39 }
} ,
{ & V_69 ,
{ L_28 , L_29 ,
V_43 , V_40 , F_19 ( V_65 ) , V_68 ,
NULL , V_39 }
} ,
} ;
static T_8 * V_70 [] = {
& V_20 ,
& V_25 ,
} ;
V_18 =
F_21 ( L_30 ,
L_31 , L_32 ) ;
F_22 ( V_18 , V_36 , F_23 ( V_36 ) ) ;
F_24 ( V_70 , F_23 ( V_70 ) ) ;
V_71 = F_25 ( L_32 , F_1 , V_18 ) ;
}
void
F_26 ( void )
{
V_28 [ V_29 ] = F_27 ( L_33 , V_18 ) ;
V_28 [ V_30 ] = F_27 ( L_34 , V_18 ) ;
V_28 [ V_31 ] = F_28 ( L_35 ) ;
F_29 ( L_36 , V_72 , V_71 ) ;
}
