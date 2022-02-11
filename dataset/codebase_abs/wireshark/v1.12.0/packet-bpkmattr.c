static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 type ;
T_5 V_4 ;
int V_5 = 0 ;
T_6 V_6 ;
T_7 * V_7 , * V_8 , * V_9 ;
T_7 * V_10 , * V_11 , * V_12 ;
T_3 * V_13 , * V_14 , * V_15 ;
T_3 * V_16 , * V_17 , * V_18 ;
T_1 * V_19 , * V_20 , * V_21 ;
T_1 * V_22 , * V_23 , * V_24 ;
V_6 = F_2 ( V_1 , 0 ) ;
while ( V_5 < V_6 )
{
type = F_3 ( V_1 , V_5 ++ ) ;
V_4 = F_4 ( V_1 , V_5 ) ;
V_5 += 2 ;
switch ( type )
{
case V_25 :
break;
case V_26 :
F_5 ( V_3 , V_27 , V_1 , V_5 ,
V_4 , V_28 | V_29 ) ;
break;
case V_30 :
if ( V_4 == 3 )
F_5 ( V_3 , V_31 , V_1 , V_5 ,
V_4 , V_29 ) ;
else
F_6 ( V_32 ) ;
break;
case V_33 :
if ( V_4 == 6 )
F_5 ( V_3 , V_34 , V_1 , V_5 ,
V_4 , V_29 ) ;
else
F_6 ( V_32 ) ;
break;
case V_35 :
F_5 ( V_3 , V_36 , V_1 , V_5 ,
V_4 , V_29 ) ;
break;
case V_37 :
V_7 =
F_7 ( V_3 , V_1 , V_5 , V_4 ,
L_1 ) ;
V_13 =
F_8 ( V_7 , V_38 ) ;
V_19 = F_9 ( V_1 , V_5 , V_4 , V_4 ) ;
F_1 ( V_19 , V_2 , V_13 ) ;
break;
case V_39 :
F_5 ( V_3 , V_40 , V_1 , V_5 ,
V_4 , V_28 | V_29 ) ;
break;
case V_41 :
if ( ( V_4 == 96 ) || ( V_4 == 128 ) )
F_5 ( V_3 , V_42 , V_1 , V_5 ,
V_4 , V_29 ) ;
else
F_6 ( V_32 ) ;
break;
case V_43 :
if ( V_4 == 8 || V_4 == 16 )
F_5 ( V_3 , V_44 , V_1 , V_5 ,
V_4 , V_29 ) ;
else
F_6 ( V_32 ) ;
break;
case V_45 :
if ( V_4 == 4 )
F_5 ( V_3 , V_46 , V_1 , V_5 ,
V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_48 :
if ( V_4 == 1 )
F_5 ( V_3 , V_49 , V_1 , V_5 ,
V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_50 :
if ( V_4 == 20 )
F_5 ( V_3 , V_51 , V_1 ,
V_5 , V_4 , V_29 ) ;
else
F_6 ( V_32 ) ;
break;
case V_52 :
if ( V_4 == 2 )
F_5 ( V_3 , V_53 , V_1 , V_5 ,
V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_54 :
V_8 =
F_7 ( V_3 , V_1 , V_5 , V_4 , L_2 ) ;
V_14 =
F_8 ( V_8 , V_55 ) ;
V_20 = F_9 ( V_1 , V_5 , V_4 , V_4 ) ;
F_1 ( V_20 , V_2 , V_14 ) ;
break;
case V_56 :
break;
case V_57 :
if ( V_4 == 8 || V_4 == 16 )
F_5 ( V_3 , V_58 , V_1 , V_5 ,
V_4 , V_29 ) ;
else
F_6 ( V_32 ) ;
break;
case V_59 :
if ( V_4 == 1 )
F_5 ( V_3 , V_60 , V_1 ,
V_5 , V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_61 :
F_5 ( V_3 , V_62 , V_1 , V_5 ,
V_4 , V_29 ) ;
break;
case V_63 :
F_5 ( V_3 , V_64 , V_1 , V_5 ,
V_4 , V_29 ) ;
break;
case V_65 :
V_9 =
F_7 ( V_3 , V_1 , V_5 , V_4 ,
L_3 ) ;
V_15 =
F_8 ( V_9 , V_66 ) ;
V_21 = F_9 ( V_1 , V_5 , V_4 , V_4 ) ;
F_1 ( V_21 , V_2 , V_15 ) ;
break;
case V_67 :
if ( V_4 == 2 )
F_5 ( V_3 , V_68 , V_1 ,
V_5 , V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_69 :
F_5 ( V_3 , V_70 ,
V_1 , V_5 , V_4 , V_29 ) ;
break;
case V_71 :
if ( V_4 == 1 )
F_5 ( V_3 , V_72 , V_1 ,
V_5 , V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_73 :
V_12 =
F_7 ( V_3 , V_1 , V_5 , V_4 , L_4 ) ;
V_18 =
F_8 ( V_12 , V_74 ) ;
V_24 = F_9 ( V_1 , V_5 , V_4 , V_4 ) ;
F_1 ( V_24 , V_2 , V_18 ) ;
break;
case V_75 :
if ( V_4 == 1 )
F_5 ( V_3 , V_76 , V_1 , V_5 ,
V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_77 :
V_10 =
F_7 ( V_3 , V_1 , V_5 , V_4 , L_5 ) ;
V_16 =
F_8 ( V_10 , V_78 ) ;
V_22 = F_9 ( V_1 , V_5 , V_4 , V_4 ) ;
F_1 ( V_22 , V_2 , V_16 ) ;
break;
case V_79 :
if ( V_4 == 1 )
F_5 ( V_3 , V_80 , V_1 ,
V_5 , V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_81 :
if ( V_4 == 4 )
F_5 ( V_3 , V_82 , V_1 ,
V_5 , V_4 , V_47 ) ;
else
F_6 ( V_32 ) ;
break;
case V_83 :
F_5 ( V_3 , V_84 , V_1 , V_5 ,
V_4 , V_29 ) ;
break;
case V_85 :
V_11 =
F_7 ( V_3 , V_1 , V_5 , V_4 ,
L_6 ) ;
V_17 =
F_8 ( V_11 , V_86 ) ;
V_23 = F_9 ( V_1 , V_5 , V_4 , V_4 ) ;
F_1 ( V_23 , V_2 , V_17 ) ;
break;
default:
F_5 ( V_3 , V_84 , V_1 , V_5 ,
V_4 , V_29 ) ;
break;
}
V_5 += V_4 ;
}
}
static void
F_10 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_7 * V_87 ;
T_3 * V_88 ;
if ( V_3 )
{
V_87 =
F_11 ( V_3 , V_89 , V_1 , 0 , - 1 ,
L_7 ) ;
V_88 = F_8 ( V_87 , V_90 ) ;
F_1 ( V_1 , V_2 , V_88 ) ;
}
}
void
F_12 ( void )
{
static T_8 V_91 [] = {
{ & V_27 ,
{ L_8 , L_9 ,
V_92 , V_93 , NULL , 0x0 ,
L_10 , V_94 }
} ,
{ & V_31 ,
{ L_11 , L_12 ,
V_95 , V_93 , NULL , 0x0 ,
L_13 , V_94 }
} ,
{ & V_34 ,
{ L_14 , L_15 ,
V_96 , V_93 , NULL , 0x0 ,
L_16 , V_94 }
} ,
{ & V_36 ,
{ L_17 , L_18 ,
V_95 , V_93 , NULL , 0x0 ,
L_19 , V_94 }
} ,
#if 0
{&hf_docsis_bpkmattr_cm_id,
{"5 CM Identification", "docsis_bpkmattr.cmid",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CM Identification", HFILL}
},
#endif
{ & V_40 ,
{ L_20 , L_21 ,
V_92 , V_93 , NULL , 0x0 ,
L_22 , V_94 }
} ,
{ & V_42 ,
{ L_23 , L_24 ,
V_95 , V_93 , NULL , 0x0 ,
L_25 , V_94 }
} ,
{ & V_44 ,
{ L_26 , L_27 ,
V_95 , V_93 , NULL , 0x0 ,
L_28 , V_94 }
} ,
{ & V_46 ,
{ L_29 , L_30 ,
V_97 , V_98 , NULL , 0x0 ,
L_31 , V_94 }
} ,
{ & V_49 ,
{ L_32 , L_33 ,
V_99 , V_98 , NULL , 0x0 ,
L_34 , V_94 }
} ,
{ & V_51 ,
{ L_35 , L_36 ,
V_95 , V_93 , NULL , 0x0 ,
L_37 , V_94 }
} ,
{ & V_53 ,
{ L_38 , L_39 ,
V_100 , V_98 , NULL , 0x0 ,
L_40 , V_94 }
} ,
#if 0
{&hf_docsis_bpkmattr_tek_params,
{"13 TEK Parameters", "docsis_bpkmattr.tekparams",
FT_BYTES, BASE_NONE, NULL, 0x0,
"TEK Parameters", HFILL}
},
#endif
{ & V_58 ,
{ L_41 , L_42 ,
V_95 , V_93 , NULL , 0x0 ,
L_43 , V_94 }
} ,
{ & V_60 ,
{ L_44 , L_45 ,
V_99 , V_98 , F_13 ( V_101 ) , 0x0 ,
L_46 , V_94 }
} ,
{ & V_84 ,
{ L_47 , L_48 ,
V_95 , V_93 , NULL , 0x0 ,
L_49 , V_94 }
} ,
{ & V_62 ,
{ L_50 , L_51 ,
V_95 , V_93 , NULL , 0x0 ,
L_52 , V_94 }
} ,
{ & V_64 ,
{ L_53 , L_54 ,
V_95 , V_93 , NULL , 0x0 ,
L_55 , V_94 }
} ,
#if 0
{&hf_docsis_bpkmattr_security_cap,
{"19 Security Capabilities", "docsis_bpkmattr.seccap",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Security Capabilities", HFILL}
},
#endif
{ & V_68 ,
{ L_56 , L_57 ,
V_100 , V_102 , F_13 ( V_103 ) , 0x0 ,
L_58 , V_94 }
} ,
{ & V_70 ,
{ L_59 , L_60 ,
V_95 , V_93 , NULL , 0x0 ,
L_58 , V_94 }
} ,
{ & V_72 ,
{ L_61 , L_62 ,
V_99 , V_98 , F_13 ( V_104 ) , 0x0 ,
L_7 , V_94 }
} ,
#if 0
{&hf_docsis_bpkmattr_sa_descr,
{"23 SA Descriptor", "docsis_bpkmattr.sadescr",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SA Descriptor", HFILL}
},
#endif
{ & V_76 ,
{ L_63 , L_64 ,
V_99 , V_98 , NULL , 0x0 ,
L_65 , V_94 }
} ,
#if 0
{&hf_docsis_bpkmattr_sa_query,
{"25 SA Query", "docsis_bpkmattr.saquery",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SA Query", HFILL}
},
#endif
{ & V_80 ,
{ L_66 , L_67 ,
V_99 , V_102 , NULL , 0x0 ,
L_68 , V_94 }
} ,
{ & V_82 ,
{ L_69 , L_70 ,
V_105 , V_93 , NULL , 0x0 ,
L_71 , V_94 }
} ,
#if 0
{&hf_docsis_bpkmattr_download_param,
{"28 Download Parameters", "docsis_bpkmattr.dnld_params",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Download Parameters", HFILL}
},
#endif
} ;
static T_6 * V_106 [] = {
& V_90 ,
& V_38 ,
& V_66 ,
& V_55 ,
& V_74 ,
& V_78 ,
& V_86
} ;
V_89 =
F_14
( L_72 , L_73 ,
L_74 ) ;
F_15 ( V_89 , V_91 , F_16 ( V_91 ) ) ;
F_17 ( V_106 , F_16 ( V_106 ) ) ;
F_18 ( L_74 , F_10 ,
V_89 ) ;
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
