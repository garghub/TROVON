static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_3 * V_5 , * V_6 ;
T_1 * V_7 = NULL ;
int V_8 = 0 ;
T_5 V_9 ;
int V_10 ;
int V_11 = - 1 ;
char * V_12 = NULL ;
T_6 V_13 ;
T_7 * V_14 ;
T_8 V_15 ;
F_2 ( V_2 -> V_16 , V_17 , L_1 ) ;
V_4 = F_3 ( V_3 , V_18 , V_1 , V_8 , - 1 , V_19 ) ;
V_5 = F_4 ( V_4 , V_20 ) ;
do {
V_9 = F_5 ( V_1 , V_8 ) ;
V_4 = F_3 ( V_5 , V_21 , V_1 , V_8 , 2 , V_22 ) ;
V_8 += 2 ;
V_6 = F_4 ( V_4 , V_23 ) ;
F_3 ( V_6 , V_24 , V_1 , V_8 , 2 , V_22 ) ;
V_10 = F_5 ( V_1 , V_8 ) ;
V_8 += 2 ;
switch( V_9 ) {
case V_25 :
V_11 = V_26 ;
V_12 = F_6 ( F_7 () , V_1 , V_8 , V_10 , V_27 | V_19 ) ;
F_3 ( V_6 , V_28 , V_1 , V_8 , V_10 , V_27 | V_19 ) ;
break;
case V_29 :
V_11 = V_30 ;
V_12 = F_6 ( F_7 () , V_1 , V_8 , V_10 , V_27 | V_19 ) ;
F_3 ( V_6 , V_31 , V_1 , V_8 , V_10 , V_27 | V_19 ) ;
break;
case V_32 :
F_3 ( V_6 , V_33 , V_1 , V_8 , 4 , V_22 ) ;
F_8 ( & V_2 -> V_34 , V_35 , V_1 , V_8 , 4 ) ;
F_9 ( & V_2 -> V_36 , & V_2 -> V_34 ) ;
break;
case V_37 :
F_3 ( V_6 , V_38 , V_1 , V_8 , 4 , V_22 ) ;
F_8 ( & V_2 -> V_39 , V_35 , V_1 , V_8 , 4 ) ;
F_9 ( & V_2 -> V_40 , & V_2 -> V_39 ) ;
break;
case V_41 :
F_3 ( V_6 , V_42 , V_1 , V_8 , 16 , V_19 ) ;
F_8 ( & V_2 -> V_34 , V_43 , V_1 , V_8 , 16 ) ;
F_9 ( & V_2 -> V_36 , & V_2 -> V_34 ) ;
break;
case V_44 :
F_3 ( V_6 , V_45 , V_1 , V_8 , 16 , V_19 ) ;
F_8 ( & V_2 -> V_39 , V_43 , V_1 , V_8 , 16 ) ;
F_9 ( & V_2 -> V_40 , & V_2 -> V_39 ) ;
break;
case V_46 :
V_2 -> V_47 = ( V_48 ) F_10 ( V_1 , V_8 ) ;
F_11 ( V_6 , V_49 , V_1 , V_8 , 4 , V_2 -> V_47 ,
L_2 , F_12 ( V_2 -> V_47 ) , V_2 -> V_47 ) ;
break;
case V_50 :
F_3 ( V_6 , V_51 , V_1 , V_8 , 4 , V_22 ) ;
V_2 -> V_52 = F_10 ( V_1 , V_8 ) ;
break;
case V_53 :
F_3 ( V_6 , V_54 , V_1 , V_8 , 4 , V_22 ) ;
V_2 -> V_55 = F_10 ( V_1 , V_8 ) ;
break;
case V_56 :
F_3 ( V_6 , V_57 , V_1 , V_8 , 4 , V_22 ) ;
V_14 = ( T_7 * ) F_13 ( V_2 -> V_58 , sizeof( T_7 ) ) ;
V_14 -> V_59 = F_10 ( V_1 , V_8 ) ;
V_14 -> type = ( V_60 ) F_5 ( V_1 , V_8 + 4 ) ;
V_14 -> V_61 = F_14 ( V_1 , V_8 + 6 ) ;
F_15 ( & V_2 -> V_36 , V_62 , sizeof( T_7 ) , ( T_8 * ) V_14 ) ;
break;
case V_63 :
F_3 ( V_6 , V_64 , V_1 , V_8 , 4 , V_22 ) ;
V_14 = ( T_7 * ) F_13 ( V_2 -> V_58 , sizeof( T_7 ) ) ;
V_14 -> V_59 = F_10 ( V_1 , V_8 ) ;
V_14 -> type = ( V_60 ) F_5 ( V_1 , V_8 + 4 ) ;
V_14 -> V_61 = F_14 ( V_1 , V_8 + 6 ) ;
F_15 ( & V_2 -> V_40 , V_62 , sizeof( T_7 ) , ( T_8 * ) V_14 ) ;
break;
case V_65 :
F_3 ( V_6 , V_66 , V_1 , V_8 , 4 , V_22 ) ;
break;
case V_67 :
V_15 = F_14 ( V_1 , V_8 ) ;
F_3 ( V_6 , V_68 ,
V_1 , V_8 , 1 , V_22 ) ;
F_16 ( V_15 , V_2 ) ;
break;
case V_69 :
break;
default:
F_3 ( V_6 , V_70 , V_1 , V_8 , V_10 , V_19 ) ;
break;
}
V_8 = V_8 + V_10 ;
} while( V_9 != 0 );
V_7 = F_17 ( V_1 , V_8 ) ;
switch( V_11 ) {
case V_26 :
V_13 = F_18 ( V_12 ) ;
if ( V_13 ) {
F_19 ( V_2 -> V_16 , V_17 ) ;
F_20 ( V_13 , V_7 , V_2 , V_3 ) ;
}
break;
case V_30 :
{
T_9 * V_71 = F_21 ( V_12 ) ;
if ( V_71 ) {
F_19 ( V_2 -> V_16 , V_17 ) ;
F_22 ( V_71 , V_7 , V_2 , V_3 , NULL ) ;
}
break;
}
default:
break;
}
F_3 ( V_5 , V_72 , V_7 , 0 , - 1 , V_19 ) ;
}
void
F_23 ( void )
{
static T_10 V_73 [] = {
{ & V_21 ,
{ L_3 , L_4 ,
V_74 , V_75 , F_24 ( V_76 ) , 0 ,
NULL , V_77 }
} ,
{ & V_24 ,
{ L_5 , L_6 ,
V_74 , V_75 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_70 ,
{ L_7 , L_8 ,
V_78 , V_79 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_28 ,
{ L_9 , L_10 ,
V_80 , V_79 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_31 ,
{ L_11 , L_12 ,
V_80 , V_79 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_33 ,
{ L_13 , L_14 ,
V_81 , V_79 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_38 ,
{ L_15 , L_16 ,
V_81 , V_79 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_42 ,
{ L_17 , L_18 ,
V_82 , V_79 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_45 ,
{ L_19 , L_20 ,
V_82 , V_79 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_49 ,
{ L_21 , L_22 ,
V_83 , V_75 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_51 ,
{ L_23 , L_24 ,
V_83 , V_75 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_54 ,
{ L_25 , L_26 ,
V_83 , V_75 , NULL , 0 ,
NULL , V_77 }
} ,
#if 0
{ &hf_exported_pdu_sctp_ppid,
{ "SCTP PPID", "exported_pdu.sctp_ppid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
#endif
{ & V_57 ,
{ L_27 , L_28 ,
V_83 , V_75 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_64 ,
{ L_29 , L_30 ,
V_83 , V_75 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_66 ,
{ L_31 , L_32 ,
V_83 , V_75 , NULL , 0 ,
NULL , V_77 }
} ,
{ & V_68 ,
{ L_33 , L_34 ,
V_84 , V_85 , F_24 ( V_86 ) , 0 ,
NULL , V_77 }
} ,
{ & V_72 ,
{ L_1 , L_35 ,
V_78 , V_79 , NULL , 0 ,
NULL , V_77 }
} ,
} ;
static T_11 * V_87 [] = {
& V_20 ,
& V_23
} ;
V_18 = F_25 ( L_36 ,
L_37 , L_37 ) ;
F_26 ( L_37 , F_1 , V_18 ) ;
F_27 ( V_18 , V_73 , F_28 ( V_73 ) ) ;
F_29 ( V_87 , F_28 ( V_87 ) ) ;
#if 0
exported_pdu_module = prefs_register_protocol(exported_pdu,
proto_reg_handoff_exported_pdu);
prefs_register_bool_preference(exported_pdu_module, "show_hex",
"Display numbers in Hex",
"Enable to display numerical values in hexadecimal.",
&gPREF_HEX);
* Register an example port preference */
prefs_register_uint_preference(exported_pdu_module, "tcp.port", "exported_pdu TCP Port",
" exported_pdu TCP port if other than the default",
10, &gPORT_PREF);
#endif
F_30 ( V_88 ) ;
F_30 ( V_89 ) ;
}
void
F_31 ( void )
{
static T_12 V_90 = FALSE ;
static T_6 V_91 ;
if ( ! V_90 ) {
V_91 = F_18 ( L_37 ) ;
F_32 ( L_38 , V_92 , V_91 ) ;
V_90 = TRUE ;
}
}
