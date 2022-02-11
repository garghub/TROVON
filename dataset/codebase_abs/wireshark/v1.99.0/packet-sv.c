static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_3 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_4 ( T_2 , V_2 ,
T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_5 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 18 "../../asn1/sv/sv.cnf"
T_11 V_3 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_3 ) ;
V_4 . V_5 = V_3 ;
return T_5 ;
}
static int
F_6 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_7 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 24 "../../asn1/sv/sv.cnf"
T_11 V_6 ;
T_11 V_7 ;
T_11 V_8 ;
T_11 V_9 ;
T_12 V_10 ;
T_13 * V_11 ;
V_6 = F_8 ( T_4 , T_5 ) ;
if( V_6 != 8 )
{
F_9 ( T_9 , T_7 -> V_12 , & V_13 , T_4 , T_5 , V_6 ,
L_1 ) ;
if( T_10 >= 0 )
{
F_10 ( T_9 , T_10 , T_4 , T_5 , V_6 , L_2 ) ;
}
return T_5 ;
}
V_7 = F_11 ( T_4 , T_5 ) ;
V_8 = F_12 ( T_4 , T_5 + 4 ) * 0x100 ;
V_9 = ( T_11 ) ( ( ( V_14 ) V_8 * F_13 ( 1000000000 ) ) / F_13 ( 0x100000000 ) ) ;
V_10 . V_15 = V_7 ;
V_10 . V_16 = V_9 ;
V_11 = F_14 ( F_15 () , & V_10 , V_17 , TRUE ) ;
if( T_10 >= 0 )
{
F_10 ( T_9 , T_10 , T_4 , T_5 , V_6 , V_11 ) ;
}
T_5 += 8 ;
return T_5 ;
return T_5 ;
}
static int
F_16 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 65 "../../asn1/sv/sv.cnf"
T_11 V_3 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_3 ) ;
V_4 . V_18 = V_3 ;
return T_5 ;
}
static int
F_17 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_18 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_19 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 71 "../../asn1/sv/sv.cnf"
T_11 V_3 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_3 ) ;
V_4 . V_19 = V_3 ;
return T_5 ;
}
static int
F_20 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_21 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_20 , T_10 , V_21 ) ;
return T_5 ;
}
static int
F_22 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_23 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_22 , T_10 , V_23 ) ;
return T_5 ;
}
static int
F_24 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_21 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_24 , T_10 , V_25 ) ;
return T_5 ;
}
static int
F_25 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_26 ( T_7 , T_9 , T_4 , T_5 ,
V_26 , T_10 , V_27 ,
NULL ) ;
return T_5 ;
}
static void
F_27 ( T_3 * T_4 , T_14 * V_12 , T_8 * V_28 )
{
int T_5 = 0 ;
int V_29 ;
T_15 * V_30 ;
T_8 * T_9 ;
T_6 V_31 ;
F_28 ( & V_31 , V_32 , TRUE , V_12 ) ;
V_30 = F_29 ( V_28 , V_33 , T_4 , 0 , - 1 , V_34 ) ;
T_9 = F_30 ( V_30 , V_35 ) ;
F_31 ( V_12 -> V_36 , V_37 , V_38 ) ;
F_32 ( V_12 -> V_36 , V_39 ) ;
if ( T_9 && F_33 ( T_4 , T_5 ) >= 2 )
F_29 ( T_9 , V_40 , T_4 , T_5 , 2 , V_41 ) ;
if ( T_9 && F_33 ( T_4 , T_5 ) >= 4 )
F_29 ( T_9 , V_42 , T_4 , T_5 + 2 , 2 , V_41 ) ;
if ( T_9 && F_33 ( T_4 , T_5 ) >= 6 )
F_29 ( T_9 , V_43 , T_4 , T_5 + 4 , 2 , V_41 ) ;
if ( T_9 && F_33 ( T_4 , T_5 ) >= 8 )
F_29 ( T_9 , V_44 , T_4 , T_5 + 6 , 2 , V_41 ) ;
T_5 = 8 ;
while ( T_9 && F_33 ( T_4 , T_5 ) > 0 ) {
V_29 = T_5 ;
T_5 = F_25 ( FALSE , T_4 , T_5 , & V_31 , T_9 , - 1 ) ;
if ( T_5 == V_29 ) {
F_34 ( T_9 , V_12 , & V_45 , T_4 , T_5 , - 1 ) ;
break;
}
}
if( T_9 )
F_35 ( V_46 , V_12 , & V_4 ) ;
}
void F_36 ( void ) {
static T_16 V_47 [] = {
{ & V_40 ,
{ L_3 , L_4 , V_48 , V_49 , NULL , 0x0 , NULL , V_50 } } ,
{ & V_42 ,
{ L_5 , L_6 , V_48 , V_51 , NULL , 0x0 , NULL , V_50 } } ,
{ & V_43 ,
{ L_7 , L_8 , V_48 , V_52 , NULL , 0x0 , NULL , V_50 } } ,
{ & V_44 ,
{ L_9 , L_10 , V_48 , V_52 , NULL , 0x0 , NULL , V_50 } } ,
#if 0
{ &hf_sv_phmeas_instmag_i,
{ "value", "sv.meas_value", FT_INT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_sv_phsmeas_q,
{ "quality", "sv.meas_quality", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_sv_phsmeas_q_validity,
{ "validity", "sv.meas_quality.validity", FT_UINT32, BASE_HEX, VALS(sv_q_validity_vals), Q_VALIDITY_MASK, NULL, HFILL}},
{ &hf_sv_phsmeas_q_overflow,
{ "overflow", "sv.meas_quality.overflow", FT_BOOLEAN, 32, NULL, Q_OVERFLOW, NULL, HFILL}},
{ &hf_sv_phsmeas_q_outofrange,
{ "out of range", "sv.meas_quality.outofrange", FT_BOOLEAN, 32, NULL, Q_OUTOFRANGE, NULL, HFILL}},
{ &hf_sv_phsmeas_q_badreference,
{ "bad reference", "sv.meas_quality.badreference", FT_BOOLEAN, 32, NULL, Q_BADREFERENCE, NULL, HFILL}},
{ &hf_sv_phsmeas_q_oscillatory,
{ "oscillatory", "sv.meas_quality.oscillatory", FT_BOOLEAN, 32, NULL, Q_OSCILLATORY, NULL, HFILL}},
{ &hf_sv_phsmeas_q_failure,
{ "failure", "sv.meas_quality.failure", FT_BOOLEAN, 32, NULL, Q_FAILURE, NULL, HFILL}},
{ &hf_sv_phsmeas_q_olddata,
{ "old data", "sv.meas_quality.olddata", FT_BOOLEAN, 32, NULL, Q_OLDDATA, NULL, HFILL}},
{ &hf_sv_phsmeas_q_inconsistent,
{ "inconsistent", "sv.meas_quality.inconsistent", FT_BOOLEAN, 32, NULL, Q_INCONSISTENT, NULL, HFILL}},
{ &hf_sv_phsmeas_q_inaccurate,
{ "inaccurate", "sv.meas_quality.inaccurate", FT_BOOLEAN, 32, NULL, Q_INACCURATE, NULL, HFILL}},
{ &hf_sv_phsmeas_q_source,
{ "source", "sv.meas_quality.source", FT_UINT32, BASE_HEX, VALS(sv_q_source_vals), Q_SOURCE_MASK, NULL, HFILL}},
{ &hf_sv_phsmeas_q_test,
{ "test", "sv.meas_quality.teset", FT_BOOLEAN, 32, NULL, Q_TEST, NULL, HFILL}},
{ &hf_sv_phsmeas_q_operatorblocked,
{ "operator blocked", "sv.meas_quality.operatorblocked", FT_BOOLEAN, 32, NULL, Q_OPERATORBLOCKED, NULL, HFILL}},
{ &hf_sv_phsmeas_q_derived,
{ "derived", "sv.meas_quality.derived", FT_BOOLEAN, 32, NULL, Q_DERIVED, NULL, HFILL}},
#endif
#line 1 "../../asn1/sv/packet-sv-hfarr.c"
{ & V_53 ,
{ L_11 , L_12 ,
V_54 , V_55 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_56 ,
{ L_13 , L_14 ,
V_57 , V_51 , NULL , 0 ,
L_15 , V_50 } } ,
{ & V_58 ,
{ L_16 , L_17 ,
V_57 , V_51 , NULL , 0 ,
L_18 , V_50 } } ,
{ & V_59 ,
{ L_19 , L_20 ,
V_54 , V_55 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_60 ,
{ L_21 , L_22 ,
V_61 , V_55 , NULL , 0 ,
L_23 , V_50 } } ,
{ & V_62 ,
{ L_24 , L_25 ,
V_61 , V_55 , NULL , 0 ,
L_23 , V_50 } } ,
{ & V_63 ,
{ L_26 , L_27 ,
V_57 , V_51 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_64 ,
{ L_28 , L_29 ,
V_57 , V_51 , NULL , 0 ,
L_30 , V_50 } } ,
{ & V_65 ,
{ L_31 , L_32 ,
V_61 , V_55 , NULL , 0 ,
L_33 , V_50 } } ,
{ & V_66 ,
{ L_34 , L_35 ,
V_67 , V_51 , F_37 ( V_68 ) , 0 ,
NULL , V_50 } } ,
{ & V_69 ,
{ L_36 , L_37 ,
V_57 , V_51 , NULL , 0 ,
L_15 , V_50 } } ,
{ & V_70 ,
{ L_38 , L_39 ,
V_71 , V_55 , NULL , 0 ,
L_40 , V_50 } } ,
{ & V_72 ,
{ L_41 , L_42 ,
V_67 , V_51 , F_37 ( V_73 ) , 0 ,
NULL , V_50 } } ,
#line 306 "../../asn1/sv/packet-sv-template.c"
} ;
static T_17 * V_74 [] = {
& V_35 ,
& V_75 ,
& V_76 ,
#line 1 "../../asn1/sv/packet-sv-ettarr.c"
& V_27 ,
& V_25 ,
& V_23 ,
& V_21 ,
#line 314 "../../asn1/sv/packet-sv-template.c"
} ;
static T_18 V_77 [] = {
{ & V_13 , { L_43 , V_78 , V_79 , L_44 , V_80 } } ,
{ & V_45 , { L_45 , V_81 , V_82 , L_46 , V_80 } } ,
} ;
T_19 * V_83 ;
V_33 = F_38 ( V_38 , V_84 , V_85 ) ;
F_39 ( L_47 , F_27 , V_33 ) ;
F_40 ( V_33 , V_47 , F_41 ( V_47 ) ) ;
F_42 ( V_74 , F_41 ( V_74 ) ) ;
V_83 = F_43 ( V_33 ) ;
F_44 ( V_83 , V_77 , F_41 ( V_77 ) ) ;
V_46 = F_45 ( L_47 ) ;
}
void F_46 ( void ) {
T_20 V_86 ;
V_86 = F_47 ( L_47 ) ;
F_48 ( L_48 , V_87 , V_86 ) ;
}
