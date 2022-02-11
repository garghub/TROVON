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
T_12 * V_7 ;
T_11 V_8 ;
T_11 V_9 ;
T_11 V_10 ;
T_13 V_11 ;
T_14 * V_12 ;
V_6 = F_8 ( T_4 , T_5 ) ;
if( V_6 != 8 )
{
V_7 = F_9 ( T_9 , T_4 , T_5 , V_6 ,
L_1
L_2 ) ;
F_10 ( V_7 , V_13 , V_14 ) ;
F_11 ( T_7 -> V_15 , V_7 , V_13 , V_14 , L_3 ) ;
if( T_10 >= 0 )
{
F_12 ( T_9 , T_10 , T_4 , T_5 , V_6 , L_4 ) ;
}
return T_5 ;
}
V_8 = F_13 ( T_4 , T_5 ) ;
V_9 = F_14 ( T_4 , T_5 + 4 ) * 0x100 ;
V_10 = ( T_11 ) ( ( ( V_16 ) V_9 * F_15 ( 1000000000U ) ) / F_15 ( 0x100000000U ) ) ;
V_11 . V_17 = V_8 ;
V_11 . V_18 = V_10 ;
V_12 = F_16 ( & V_11 , V_19 , TRUE ) ;
if( T_10 >= 0 )
{
F_12 ( T_9 , T_10 , T_4 , T_5 , V_6 , V_12 ) ;
}
T_5 += 8 ;
return T_5 ;
return T_5 ;
}
static int
F_17 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 70 "../../asn1/sv/sv.cnf"
T_11 V_3 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_3 ) ;
V_4 . V_20 = V_3 ;
return T_5 ;
}
static int
F_18 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_20 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 76 "../../asn1/sv/sv.cnf"
T_11 V_3 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_3 ) ;
V_4 . V_21 = V_3 ;
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
T_5 = F_24 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_24 , T_10 , V_25 ) ;
return T_5 ;
}
static int
F_25 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_22 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_26 , T_10 , V_27 ) ;
return T_5 ;
}
static int
F_26 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_27 ( T_7 , T_9 , T_4 , T_5 ,
V_28 , T_10 , V_29 ,
NULL ) ;
return T_5 ;
}
static void
F_28 ( T_3 * T_4 , T_15 * V_15 , T_8 * V_30 )
{
int T_5 = 0 ;
int V_31 ;
T_12 * V_32 = NULL ;
T_8 * T_9 = NULL ;
T_6 V_33 ;
F_29 ( & V_33 , V_34 , TRUE , V_15 ) ;
if ( V_30 ) {
V_32 = F_30 ( V_30 , V_35 , T_4 , 0 , - 1 , V_36 ) ;
T_9 = F_31 ( V_32 , V_37 ) ;
}
F_32 ( V_15 -> V_38 , V_39 , V_40 ) ;
F_33 ( V_15 -> V_38 , V_41 ) ;
if ( T_9 && F_34 ( T_4 , T_5 ) >= 2 )
F_30 ( T_9 , V_42 , T_4 , T_5 , 2 , V_43 ) ;
if ( T_9 && F_34 ( T_4 , T_5 ) >= 4 )
F_30 ( T_9 , V_44 , T_4 , T_5 + 2 , 2 , V_43 ) ;
if ( T_9 && F_34 ( T_4 , T_5 ) >= 6 )
F_30 ( T_9 , V_45 , T_4 , T_5 + 4 , 2 , V_43 ) ;
if ( T_9 && F_34 ( T_4 , T_5 ) >= 8 )
F_30 ( T_9 , V_46 , T_4 , T_5 + 6 , 2 , V_43 ) ;
T_5 = 8 ;
while ( T_9 && F_34 ( T_4 , T_5 ) > 0 ) {
V_31 = T_5 ;
T_5 = F_26 ( FALSE , T_4 , T_5 , & V_33 , T_9 , - 1 ) ;
if ( T_5 == V_31 ) {
F_9 ( T_9 , T_4 , T_5 , - 1 , L_5 ) ;
break;
}
}
if( T_9 )
F_35 ( V_47 , V_15 , & V_4 ) ;
}
void F_36 ( void ) {
static T_16 V_48 [] = {
{ & V_42 ,
{ L_6 , L_7 , V_49 , V_50 , NULL , 0x0 , NULL , V_51 } } ,
{ & V_44 ,
{ L_8 , L_9 , V_49 , V_52 , NULL , 0x0 , NULL , V_51 } } ,
{ & V_45 ,
{ L_10 , L_11 , V_49 , V_53 , NULL , 0x0 , NULL , V_51 } } ,
{ & V_46 ,
{ L_12 , L_13 , V_49 , V_53 , NULL , 0x0 , NULL , V_51 } } ,
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
{ & V_54 ,
{ L_14 , L_15 ,
V_55 , V_56 , NULL , 0 ,
NULL , V_51 } } ,
{ & V_57 ,
{ L_16 , L_17 ,
V_58 , V_52 , NULL , 0 ,
L_18 , V_51 } } ,
{ & V_59 ,
{ L_19 , L_20 ,
V_58 , V_52 , NULL , 0 ,
L_21 , V_51 } } ,
{ & V_60 ,
{ L_22 , L_23 ,
V_55 , V_56 , NULL , 0 ,
NULL , V_51 } } ,
{ & V_61 ,
{ L_24 , L_25 ,
V_62 , V_56 , NULL , 0 ,
L_26 , V_51 } } ,
{ & V_63 ,
{ L_27 , L_28 ,
V_62 , V_56 , NULL , 0 ,
L_26 , V_51 } } ,
{ & V_64 ,
{ L_29 , L_30 ,
V_58 , V_52 , NULL , 0 ,
NULL , V_51 } } ,
{ & V_65 ,
{ L_31 , L_32 ,
V_58 , V_52 , NULL , 0 ,
L_33 , V_51 } } ,
{ & V_66 ,
{ L_34 , L_35 ,
V_62 , V_56 , NULL , 0 ,
L_36 , V_51 } } ,
{ & V_67 ,
{ L_37 , L_38 ,
V_68 , V_52 , F_37 ( V_69 ) , 0 ,
NULL , V_51 } } ,
{ & V_70 ,
{ L_39 , L_40 ,
V_58 , V_52 , NULL , 0 ,
L_18 , V_51 } } ,
{ & V_71 ,
{ L_41 , L_42 ,
V_72 , V_56 , NULL , 0 ,
L_43 , V_51 } } ,
{ & V_73 ,
{ L_44 , L_45 ,
V_68 , V_52 , F_37 ( V_74 ) , 0 ,
NULL , V_51 } } ,
#line 310 "../../asn1/sv/packet-sv-template.c"
} ;
static T_17 * V_75 [] = {
& V_37 ,
& V_76 ,
& V_77 ,
#line 1 "../../asn1/sv/packet-sv-ettarr.c"
& V_29 ,
& V_27 ,
& V_25 ,
& V_23 ,
#line 318 "../../asn1/sv/packet-sv-template.c"
} ;
V_35 = F_38 ( V_40 , V_78 , V_79 ) ;
F_39 ( L_46 , F_28 , V_35 ) ;
F_40 ( V_35 , V_48 , F_41 ( V_48 ) ) ;
F_42 ( V_75 , F_41 ( V_75 ) ) ;
V_47 = F_43 ( L_46 ) ;
}
void F_44 ( void ) {
T_18 V_80 ;
V_80 = F_45 ( L_46 ) ;
F_46 ( L_47 , V_81 , V_80 ) ;
}
