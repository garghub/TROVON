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
const T_6 * V_13 , * V_14 ;
T_7 V_15 ;
T_8 * V_16 ;
T_9 V_17 ;
F_2 ( V_2 -> V_18 , V_19 , L_1 ) ;
V_4 = F_3 ( V_3 , V_20 , V_1 , V_8 , - 1 , V_21 ) ;
V_5 = F_4 ( V_4 , V_22 ) ;
do {
V_9 = F_5 ( V_1 , V_8 ) ;
V_4 = F_3 ( V_5 , V_23 , V_1 , V_8 , 2 , V_24 ) ;
V_8 += 2 ;
V_6 = F_4 ( V_4 , V_25 ) ;
F_3 ( V_6 , V_26 , V_1 , V_8 , 2 , V_24 ) ;
V_10 = F_5 ( V_1 , V_8 ) ;
V_8 += 2 ;
switch( V_9 ) {
case V_27 :
V_11 = V_28 ;
V_12 = F_6 ( F_7 () , V_1 , V_8 , V_10 , V_29 | V_21 ) ;
F_3 ( V_6 , V_30 , V_1 , V_8 , V_10 , V_29 | V_21 ) ;
break;
case V_31 :
F_3 ( V_6 , V_32 , V_1 , V_8 , 4 , V_24 ) ;
V_13 = F_8 ( V_1 , V_8 , 4 ) ;
F_9 ( & V_2 -> V_33 , V_34 , 4 , V_13 ) ;
F_9 ( & V_2 -> V_35 , V_34 , 4 , V_13 ) ;
break;
case V_36 :
F_3 ( V_6 , V_37 , V_1 , V_8 , 4 , V_24 ) ;
V_14 = F_8 ( V_1 , V_8 , 4 ) ;
F_9 ( & V_2 -> V_38 , V_34 , 4 , V_14 ) ;
F_9 ( & V_2 -> V_39 , V_34 , 4 , V_14 ) ;
break;
case V_40 :
F_3 ( V_6 , V_41 , V_1 , V_8 , 16 , V_21 ) ;
V_13 = F_8 ( V_1 , V_8 , 16 ) ;
F_9 ( & V_2 -> V_33 , V_42 , 16 , V_13 ) ;
F_9 ( & V_2 -> V_35 , V_42 , 16 , V_13 ) ;
break;
case V_43 :
F_3 ( V_6 , V_44 , V_1 , V_8 , 16 , V_21 ) ;
V_14 = F_8 ( V_1 , V_8 , 16 ) ;
F_9 ( & V_2 -> V_38 , V_42 , 16 , V_14 ) ;
F_9 ( & V_2 -> V_39 , V_42 , 16 , V_14 ) ;
break;
case V_45 :
V_2 -> V_46 = ( V_47 ) F_10 ( V_1 , V_8 ) ;
F_11 ( V_6 , V_48 , V_1 , V_8 , 4 , V_2 -> V_46 ,
L_2 , F_12 ( V_2 -> V_46 ) , V_2 -> V_46 ) ;
break;
case V_49 :
F_3 ( V_6 , V_50 , V_1 , V_8 , 4 , V_24 ) ;
V_2 -> V_51 = F_10 ( V_1 , V_8 ) ;
break;
case V_52 :
F_3 ( V_6 , V_53 , V_1 , V_8 , 4 , V_24 ) ;
V_2 -> V_54 = F_10 ( V_1 , V_8 ) ;
break;
case V_55 :
F_3 ( V_6 , V_56 , V_1 , V_8 , 4 , V_24 ) ;
V_16 = ( T_8 * ) F_13 ( V_2 -> V_57 , sizeof( T_8 ) ) ;
V_16 -> V_58 = F_10 ( V_1 , V_8 ) ;
V_16 -> type = ( V_59 ) F_5 ( V_1 , V_8 + 4 ) ;
V_16 -> V_60 = F_14 ( V_1 , V_8 + 6 ) ;
F_9 ( & V_2 -> V_35 , V_61 , sizeof( T_8 ) , ( T_9 * ) V_16 ) ;
break;
case V_62 :
F_3 ( V_6 , V_63 , V_1 , V_8 , 4 , V_24 ) ;
V_16 = ( T_8 * ) F_13 ( V_2 -> V_57 , sizeof( T_8 ) ) ;
V_16 -> V_58 = F_10 ( V_1 , V_8 ) ;
V_16 -> type = ( V_59 ) F_5 ( V_1 , V_8 + 4 ) ;
V_16 -> V_60 = F_14 ( V_1 , V_8 + 6 ) ;
F_9 ( & V_2 -> V_39 , V_61 , sizeof( T_8 ) , ( T_9 * ) V_16 ) ;
break;
case V_64 :
F_3 ( V_6 , V_65 , V_1 , V_8 , 4 , V_24 ) ;
break;
case V_66 :
V_17 = F_14 ( V_1 , V_8 ) ;
F_3 ( V_6 , V_67 ,
V_1 , V_8 , 1 , V_24 ) ;
F_15 ( V_17 , V_2 ) ;
break;
case V_68 :
break;
default:
F_3 ( V_6 , V_69 , V_1 , V_8 , V_10 , V_21 ) ;
break;
}
V_8 = V_8 + V_10 ;
} while( V_9 != 0 );
V_7 = F_16 ( V_1 , V_8 ) ;
switch( V_11 ) {
case V_28 :
V_15 = F_17 ( V_12 ) ;
if ( V_15 ) {
F_18 ( V_2 -> V_18 , V_19 ) ;
F_19 ( V_15 , V_7 , V_2 , V_3 ) ;
}
break;
default:
break;
}
F_3 ( V_5 , V_70 , V_7 , 0 , - 1 , V_21 ) ;
}
void
F_20 ( void )
{
static T_10 V_71 [] = {
{ & V_23 ,
{ L_3 , L_4 ,
V_72 , V_73 , F_21 ( V_74 ) , 0 ,
NULL , V_75 }
} ,
{ & V_26 ,
{ L_5 , L_6 ,
V_72 , V_73 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_69 ,
{ L_7 , L_8 ,
V_76 , V_77 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_30 ,
{ L_9 , L_10 ,
V_78 , V_77 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_32 ,
{ L_11 , L_12 ,
V_79 , V_77 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_37 ,
{ L_13 , L_14 ,
V_79 , V_77 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_41 ,
{ L_15 , L_16 ,
V_80 , V_77 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_44 ,
{ L_17 , L_18 ,
V_80 , V_77 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_48 ,
{ L_19 , L_20 ,
V_81 , V_73 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_50 ,
{ L_21 , L_22 ,
V_81 , V_73 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_53 ,
{ L_23 , L_24 ,
V_81 , V_73 , NULL , 0 ,
NULL , V_75 }
} ,
#if 0
{ &hf_exported_pdu_sctp_ppid,
{ "SCTP PPID", "exported_pdu.sctp_ppid",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
#endif
{ & V_56 ,
{ L_25 , L_26 ,
V_81 , V_73 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_63 ,
{ L_27 , L_28 ,
V_81 , V_73 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_65 ,
{ L_29 , L_30 ,
V_81 , V_73 , NULL , 0 ,
NULL , V_75 }
} ,
{ & V_67 ,
{ L_31 , L_32 ,
V_82 , V_83 , F_21 ( V_84 ) , 0 ,
NULL , V_75 }
} ,
{ & V_70 ,
{ L_1 , L_33 ,
V_76 , V_77 , NULL , 0 ,
NULL , V_75 }
} ,
} ;
static T_11 * V_85 [] = {
& V_22 ,
& V_25
} ;
V_20 = F_22 ( L_34 ,
L_35 , L_35 ) ;
F_23 ( L_35 , F_1 , V_20 ) ;
F_24 ( V_20 , V_71 , F_25 ( V_71 ) ) ;
F_26 ( V_85 , F_25 ( V_85 ) ) ;
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
F_27 ( V_86 ) ;
F_27 ( V_87 ) ;
}
void
F_28 ( void )
{
static T_12 V_88 = FALSE ;
static T_7 V_89 ;
if ( ! V_88 ) {
V_89 = F_17 ( L_35 ) ;
F_29 ( L_36 , V_90 , V_89 ) ;
V_88 = TRUE ;
}
}
