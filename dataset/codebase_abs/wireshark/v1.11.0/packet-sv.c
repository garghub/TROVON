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
#line 19 "../../asn1/sv/sv.cnf"
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
#line 25 "../../asn1/sv/sv.cnf"
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
V_9 = ( T_11 ) ( ( ( V_14 ) V_8 * F_13 ( 1000000000U ) ) / F_13 ( 0x100000000U ) ) ;
V_10 . V_15 = V_7 ;
V_10 . V_16 = V_9 ;
V_11 = F_14 ( & V_10 , V_17 , TRUE ) ;
if( T_10 >= 0 )
{
F_10 ( T_9 , T_10 , T_4 , T_5 , V_6 , V_11 ) ;
}
T_5 += 8 ;
return T_5 ;
return T_5 ;
}
static int
F_15 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 66 "../../asn1/sv/sv.cnf"
T_11 V_3 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_3 ) ;
V_4 . V_18 = V_3 ;
return T_5 ;
}
static int
F_16 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_17 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_18 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 72 "../../asn1/sv/sv.cnf"
T_11 V_3 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_3 ) ;
V_4 . V_19 = V_3 ;
return T_5 ;
}
static int
F_19 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_20 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_20 , T_10 , V_21 ) ;
return T_5 ;
}
static int
F_21 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_22 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_22 , T_10 , V_23 ) ;
return T_5 ;
}
static int
F_23 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_20 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_24 , T_10 , V_25 ) ;
return T_5 ;
}
static int
F_24 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_25 ( T_7 , T_9 , T_4 , T_5 ,
V_26 , T_10 , V_27 ,
NULL ) ;
return T_5 ;
}
static void
F_26 ( T_3 * T_4 , T_14 * V_12 , T_8 * V_28 )
{
int T_5 = 0 ;
int V_29 ;
T_15 * V_30 = NULL ;
T_8 * T_9 = NULL ;
T_6 V_31 ;
F_27 ( & V_31 , V_32 , TRUE , V_12 ) ;
if ( V_28 ) {
V_30 = F_28 ( V_28 , V_33 , T_4 , 0 , - 1 , V_34 ) ;
T_9 = F_29 ( V_30 , V_35 ) ;
}
F_30 ( V_12 -> V_36 , V_37 , V_38 ) ;
F_31 ( V_12 -> V_36 , V_39 ) ;
if ( T_9 && F_32 ( T_4 , T_5 ) >= 2 )
F_28 ( T_9 , V_40 , T_4 , T_5 , 2 , V_41 ) ;
if ( T_9 && F_32 ( T_4 , T_5 ) >= 4 )
F_28 ( T_9 , V_42 , T_4 , T_5 + 2 , 2 , V_41 ) ;
if ( T_9 && F_32 ( T_4 , T_5 ) >= 6 )
F_28 ( T_9 , V_43 , T_4 , T_5 + 4 , 2 , V_41 ) ;
if ( T_9 && F_32 ( T_4 , T_5 ) >= 8 )
F_28 ( T_9 , V_44 , T_4 , T_5 + 6 , 2 , V_41 ) ;
T_5 = 8 ;
while ( T_9 && F_32 ( T_4 , T_5 ) > 0 ) {
V_29 = T_5 ;
T_5 = F_24 ( FALSE , T_4 , T_5 , & V_31 , T_9 , - 1 ) ;
if ( T_5 == V_29 ) {
F_33 ( T_9 , T_4 , T_5 , - 1 , L_3 ) ;
break;
}
}
if( T_9 )
F_34 ( V_45 , V_12 , & V_4 ) ;
}
void F_35 ( void ) {
static T_16 V_46 [] = {
{ & V_40 ,
{ L_4 , L_5 , V_47 , V_48 , NULL , 0x0 , NULL , V_49 } } ,
{ & V_42 ,
{ L_6 , L_7 , V_47 , V_50 , NULL , 0x0 , NULL , V_49 } } ,
{ & V_43 ,
{ L_8 , L_9 , V_47 , V_51 , NULL , 0x0 , NULL , V_49 } } ,
{ & V_44 ,
{ L_10 , L_11 , V_47 , V_51 , NULL , 0x0 , NULL , V_49 } } ,
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
{ & V_52 ,
{ L_12 , L_13 ,
V_53 , V_54 , NULL , 0 ,
NULL , V_49 } } ,
{ & V_55 ,
{ L_14 , L_15 ,
V_56 , V_50 , NULL , 0 ,
L_16 , V_49 } } ,
{ & V_57 ,
{ L_17 , L_18 ,
V_56 , V_50 , NULL , 0 ,
L_19 , V_49 } } ,
{ & V_58 ,
{ L_20 , L_21 ,
V_53 , V_54 , NULL , 0 ,
NULL , V_49 } } ,
{ & V_59 ,
{ L_22 , L_23 ,
V_60 , V_54 , NULL , 0 ,
L_24 , V_49 } } ,
{ & V_61 ,
{ L_25 , L_26 ,
V_60 , V_54 , NULL , 0 ,
L_24 , V_49 } } ,
{ & V_62 ,
{ L_27 , L_28 ,
V_56 , V_50 , NULL , 0 ,
NULL , V_49 } } ,
{ & V_63 ,
{ L_29 , L_30 ,
V_56 , V_50 , NULL , 0 ,
L_31 , V_49 } } ,
{ & V_64 ,
{ L_32 , L_33 ,
V_60 , V_54 , NULL , 0 ,
L_34 , V_49 } } ,
{ & V_65 ,
{ L_35 , L_36 ,
V_66 , V_50 , F_36 ( V_67 ) , 0 ,
NULL , V_49 } } ,
{ & V_68 ,
{ L_37 , L_38 ,
V_56 , V_50 , NULL , 0 ,
L_16 , V_49 } } ,
{ & V_69 ,
{ L_39 , L_40 ,
V_70 , V_54 , NULL , 0 ,
L_41 , V_49 } } ,
{ & V_71 ,
{ L_42 , L_43 ,
V_66 , V_50 , F_36 ( V_72 ) , 0 ,
NULL , V_49 } } ,
#line 311 "../../asn1/sv/packet-sv-template.c"
} ;
static T_17 * V_73 [] = {
& V_35 ,
& V_74 ,
& V_75 ,
#line 1 "../../asn1/sv/packet-sv-ettarr.c"
& V_27 ,
& V_25 ,
& V_23 ,
& V_21 ,
#line 319 "../../asn1/sv/packet-sv-template.c"
} ;
static T_18 V_76 [] = {
{ & V_13 , { L_44 , V_77 , V_78 , L_45 , V_79 } } ,
} ;
T_19 * V_80 ;
V_33 = F_37 ( V_38 , V_81 , V_82 ) ;
F_38 ( L_46 , F_26 , V_33 ) ;
F_39 ( V_33 , V_46 , F_40 ( V_46 ) ) ;
F_41 ( V_73 , F_40 ( V_73 ) ) ;
V_80 = F_42 ( V_33 ) ;
F_43 ( V_80 , V_76 , F_40 ( V_76 ) ) ;
V_45 = F_44 ( L_46 ) ;
}
void F_45 ( void ) {
T_20 V_83 ;
V_83 = F_46 ( L_46 ) ;
F_47 ( L_47 , V_84 , V_83 ) ;
}
