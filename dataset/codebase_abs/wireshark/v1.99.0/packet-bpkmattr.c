static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 type ;
T_5 V_4 ;
int V_5 = 0 ;
T_6 V_6 ;
T_3 * V_7 , * V_8 , * V_9 ;
T_3 * V_10 , * V_11 , * V_12 ;
T_1 * V_13 , * V_14 , * V_15 ;
T_1 * V_16 , * V_17 , * V_18 ;
V_6 = F_2 ( V_1 , 0 ) ;
while ( V_5 < V_6 )
{
type = F_3 ( V_1 , V_5 ++ ) ;
V_4 = F_4 ( V_1 , V_5 ) ;
V_5 += 2 ;
switch ( type )
{
case V_19 :
break;
case V_20 :
F_5 ( V_3 , V_21 , V_1 , V_5 ,
V_4 , V_22 | V_23 ) ;
break;
case V_24 :
if ( V_4 == 3 )
F_5 ( V_3 , V_25 , V_1 , V_5 ,
V_4 , V_23 ) ;
else
F_6 ( V_26 ) ;
break;
case V_27 :
if ( V_4 == 6 )
F_5 ( V_3 , V_28 , V_1 , V_5 ,
V_4 , V_23 ) ;
else
F_6 ( V_26 ) ;
break;
case V_29 :
F_5 ( V_3 , V_30 , V_1 , V_5 ,
V_4 , V_23 ) ;
break;
case V_31 :
V_7 =
F_7 ( V_3 , V_1 , V_5 , V_4 ,
V_32 , NULL , L_1 ) ;
V_13 = F_8 ( V_1 , V_5 , V_4 ) ;
F_1 ( V_13 , V_2 , V_7 ) ;
break;
case V_33 :
F_5 ( V_3 , V_34 , V_1 , V_5 ,
V_4 , V_22 | V_23 ) ;
break;
case V_35 :
if ( ( V_4 == 96 ) || ( V_4 == 128 ) )
F_5 ( V_3 , V_36 , V_1 , V_5 ,
V_4 , V_23 ) ;
else
F_6 ( V_26 ) ;
break;
case V_37 :
if ( V_4 == 8 || V_4 == 16 )
F_5 ( V_3 , V_38 , V_1 , V_5 ,
V_4 , V_23 ) ;
else
F_6 ( V_26 ) ;
break;
case V_39 :
if ( V_4 == 4 )
F_5 ( V_3 , V_40 , V_1 , V_5 ,
V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_42 :
if ( V_4 == 1 )
F_5 ( V_3 , V_43 , V_1 , V_5 ,
V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_44 :
if ( V_4 == 20 )
F_5 ( V_3 , V_45 , V_1 ,
V_5 , V_4 , V_23 ) ;
else
F_6 ( V_26 ) ;
break;
case V_46 :
if ( V_4 == 2 )
F_5 ( V_3 , V_47 , V_1 , V_5 ,
V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_48 :
V_8 =
F_7 ( V_3 , V_1 , V_5 , V_4 , V_49 , NULL , L_2 ) ;
V_14 = F_8 ( V_1 , V_5 , V_4 ) ;
F_1 ( V_14 , V_2 , V_8 ) ;
break;
case V_50 :
break;
case V_51 :
if ( V_4 == 8 || V_4 == 16 )
F_5 ( V_3 , V_52 , V_1 , V_5 ,
V_4 , V_23 ) ;
else
F_6 ( V_26 ) ;
break;
case V_53 :
if ( V_4 == 1 )
F_5 ( V_3 , V_54 , V_1 ,
V_5 , V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_55 :
F_5 ( V_3 , V_56 , V_1 , V_5 ,
V_4 , V_23 ) ;
break;
case V_57 :
F_5 ( V_3 , V_58 , V_1 , V_5 ,
V_4 , V_23 ) ;
break;
case V_59 :
V_9 =
F_7 ( V_3 , V_1 , V_5 , V_4 ,
V_60 , NULL , L_3 ) ;
V_15 = F_8 ( V_1 , V_5 , V_4 ) ;
F_1 ( V_15 , V_2 , V_9 ) ;
break;
case V_61 :
if ( V_4 == 2 )
F_5 ( V_3 , V_62 , V_1 ,
V_5 , V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_63 :
F_5 ( V_3 , V_64 ,
V_1 , V_5 , V_4 , V_23 ) ;
break;
case V_65 :
if ( V_4 == 1 )
F_5 ( V_3 , V_66 , V_1 ,
V_5 , V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_67 :
V_12 =
F_7 ( V_3 , V_1 , V_5 , V_4 , V_68 , NULL , L_4 ) ;
V_18 = F_8 ( V_1 , V_5 , V_4 ) ;
F_1 ( V_18 , V_2 , V_12 ) ;
break;
case V_69 :
if ( V_4 == 1 )
F_5 ( V_3 , V_70 , V_1 , V_5 ,
V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_71 :
V_10 =
F_7 ( V_3 , V_1 , V_5 , V_4 , V_72 , NULL , L_5 ) ;
V_16 = F_8 ( V_1 , V_5 , V_4 ) ;
F_1 ( V_16 , V_2 , V_10 ) ;
break;
case V_73 :
if ( V_4 == 1 )
F_5 ( V_3 , V_74 , V_1 ,
V_5 , V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_75 :
if ( V_4 == 4 )
F_5 ( V_3 , V_76 , V_1 ,
V_5 , V_4 , V_41 ) ;
else
F_6 ( V_26 ) ;
break;
case V_77 :
F_5 ( V_3 , V_78 , V_1 , V_5 ,
V_4 , V_23 ) ;
break;
case V_79 :
V_11 =
F_7 ( V_3 , V_1 , V_5 , V_4 ,
V_80 , NULL , L_6 ) ;
V_17 = F_8 ( V_1 , V_5 , V_4 ) ;
F_1 ( V_17 , V_2 , V_11 ) ;
break;
default:
F_5 ( V_3 , V_78 , V_1 , V_5 ,
V_4 , V_23 ) ;
break;
}
V_5 += V_4 ;
}
}
static void
F_9 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_7 * V_81 ;
T_3 * V_82 ;
if ( V_3 )
{
V_81 =
F_10 ( V_3 , V_83 , V_1 , 0 , - 1 ,
L_7 ) ;
V_82 = F_11 ( V_81 , V_84 ) ;
F_1 ( V_1 , V_2 , V_82 ) ;
}
}
void
F_12 ( void )
{
static T_8 V_85 [] = {
{ & V_21 ,
{ L_8 , L_9 ,
V_86 , V_87 , NULL , 0x0 ,
L_10 , V_88 }
} ,
{ & V_25 ,
{ L_11 , L_12 ,
V_89 , V_87 , NULL , 0x0 ,
L_13 , V_88 }
} ,
{ & V_28 ,
{ L_14 , L_15 ,
V_90 , V_87 , NULL , 0x0 ,
L_16 , V_88 }
} ,
{ & V_30 ,
{ L_17 , L_18 ,
V_89 , V_87 , NULL , 0x0 ,
L_19 , V_88 }
} ,
#if 0
{&hf_docsis_bpkmattr_cm_id,
{"5 CM Identification", "docsis_bpkmattr.cmid",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CM Identification", HFILL}
},
#endif
{ & V_34 ,
{ L_20 , L_21 ,
V_86 , V_87 , NULL , 0x0 ,
L_22 , V_88 }
} ,
{ & V_36 ,
{ L_23 , L_24 ,
V_89 , V_87 , NULL , 0x0 ,
L_25 , V_88 }
} ,
{ & V_38 ,
{ L_26 , L_27 ,
V_89 , V_87 , NULL , 0x0 ,
L_28 , V_88 }
} ,
{ & V_40 ,
{ L_29 , L_30 ,
V_91 , V_92 , NULL , 0x0 ,
L_31 , V_88 }
} ,
{ & V_43 ,
{ L_32 , L_33 ,
V_93 , V_92 , NULL , 0x0 ,
L_34 , V_88 }
} ,
{ & V_45 ,
{ L_35 , L_36 ,
V_89 , V_87 , NULL , 0x0 ,
L_37 , V_88 }
} ,
{ & V_47 ,
{ L_38 , L_39 ,
V_94 , V_92 , NULL , 0x0 ,
L_40 , V_88 }
} ,
#if 0
{&hf_docsis_bpkmattr_tek_params,
{"13 TEK Parameters", "docsis_bpkmattr.tekparams",
FT_BYTES, BASE_NONE, NULL, 0x0,
"TEK Parameters", HFILL}
},
#endif
{ & V_52 ,
{ L_41 , L_42 ,
V_89 , V_87 , NULL , 0x0 ,
L_43 , V_88 }
} ,
{ & V_54 ,
{ L_44 , L_45 ,
V_93 , V_92 , F_13 ( V_95 ) , 0x0 ,
L_46 , V_88 }
} ,
{ & V_78 ,
{ L_47 , L_48 ,
V_89 , V_87 , NULL , 0x0 ,
L_49 , V_88 }
} ,
{ & V_56 ,
{ L_50 , L_51 ,
V_89 , V_87 , NULL , 0x0 ,
L_52 , V_88 }
} ,
{ & V_58 ,
{ L_53 , L_54 ,
V_89 , V_87 , NULL , 0x0 ,
L_55 , V_88 }
} ,
#if 0
{&hf_docsis_bpkmattr_security_cap,
{"19 Security Capabilities", "docsis_bpkmattr.seccap",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Security Capabilities", HFILL}
},
#endif
{ & V_62 ,
{ L_56 , L_57 ,
V_94 , V_96 , F_13 ( V_97 ) , 0x0 ,
L_58 , V_88 }
} ,
{ & V_64 ,
{ L_59 , L_60 ,
V_89 , V_87 , NULL , 0x0 ,
L_58 , V_88 }
} ,
{ & V_66 ,
{ L_61 , L_62 ,
V_93 , V_92 , F_13 ( V_98 ) , 0x0 ,
L_7 , V_88 }
} ,
#if 0
{&hf_docsis_bpkmattr_sa_descr,
{"23 SA Descriptor", "docsis_bpkmattr.sadescr",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SA Descriptor", HFILL}
},
#endif
{ & V_70 ,
{ L_63 , L_64 ,
V_93 , V_92 , NULL , 0x0 ,
L_65 , V_88 }
} ,
#if 0
{&hf_docsis_bpkmattr_sa_query,
{"25 SA Query", "docsis_bpkmattr.saquery",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SA Query", HFILL}
},
#endif
{ & V_74 ,
{ L_66 , L_67 ,
V_93 , V_96 , NULL , 0x0 ,
L_68 , V_88 }
} ,
{ & V_76 ,
{ L_69 , L_70 ,
V_99 , V_87 , NULL , 0x0 ,
L_71 , V_88 }
} ,
#if 0
{&hf_docsis_bpkmattr_download_param,
{"28 Download Parameters", "docsis_bpkmattr.dnld_params",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Download Parameters", HFILL}
},
#endif
} ;
static T_6 * V_100 [] = {
& V_84 ,
& V_32 ,
& V_60 ,
& V_49 ,
& V_68 ,
& V_72 ,
& V_80
} ;
V_83 =
F_14
( L_72 , L_73 ,
L_74 ) ;
F_15 ( V_83 , V_85 , F_16 ( V_85 ) ) ;
F_17 ( V_100 , F_16 ( V_100 ) ) ;
F_18 ( L_74 , F_9 ,
V_83 ) ;
}
void
F_19 ( void )
{
#if 0
dissector_handle_t docsis_bpkmattr_handle;
docsis_bpkmattr_handle = find_dissector ("docsis_bpkmattr");
dissector_add_uint ("docsis", 0xFE, docsis_bpkmattr_handle);
#endif
}
