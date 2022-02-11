static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
int V_5 ;
T_4 * V_6 = NULL ;
T_3 * V_7 = NULL ;
T_5 V_8 ;
F_2 ( & V_8 , V_9 , TRUE , V_2 ) ;
if ( V_3 ) {
V_6 = F_3 ( V_3 , V_10 , V_1 , 0 , - 1 , V_11 ) ;
V_7 = F_4 ( V_6 , V_12 ) ;
}
F_5 ( V_2 -> V_13 , V_14 , V_15 ) ;
F_6 ( V_2 -> V_13 , V_16 ) ;
if ( V_7 && F_7 ( V_1 , V_4 ) >= 2 )
F_3 ( V_7 , V_17 , V_1 , V_4 , 2 , V_18 ) ;
if ( V_7 && F_7 ( V_1 , V_4 ) >= 4 )
F_3 ( V_7 , V_19 , V_1 , V_4 + 2 , 2 , V_18 ) ;
if ( V_7 && F_7 ( V_1 , V_4 ) >= 6 )
F_3 ( V_7 , V_20 , V_1 , V_4 + 4 , 2 , V_18 ) ;
if ( V_7 && F_7 ( V_1 , V_4 ) >= 8 )
F_3 ( V_7 , V_21 , V_1 , V_4 + 6 , 2 , V_18 ) ;
V_4 = 8 ;
while ( V_7 && F_7 ( V_1 , V_4 ) > 0 ) {
V_5 = V_4 ;
V_4 = F_8 ( FALSE , V_1 , V_4 , & V_8 , V_7 , - 1 ) ;
if ( V_4 == V_5 ) {
F_9 ( V_7 , V_1 , V_4 , - 1 , L_1 ) ;
break;
}
}
if( V_7 )
F_10 ( V_22 , V_2 , & V_23 ) ;
}
void F_11 ( void ) {
static T_6 V_24 [] = {
{ & V_17 ,
{ L_2 , L_3 , V_25 , V_26 , NULL , 0x0 , NULL , V_27 } } ,
{ & V_19 ,
{ L_4 , L_5 , V_25 , V_28 , NULL , 0x0 , NULL , V_27 } } ,
{ & V_20 ,
{ L_6 , L_7 , V_25 , V_29 , NULL , 0x0 , NULL , V_27 } } ,
{ & V_21 ,
{ L_8 , L_9 , V_25 , V_29 , NULL , 0x0 , NULL , V_27 } } ,
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
#include "packet-sv-hfarr.c"
} ;
static T_7 * V_30 [] = {
& V_12 ,
& V_31 ,
& V_32 ,
#include "packet-sv-ettarr.c"
} ;
V_10 = F_12 ( V_15 , V_33 , V_34 ) ;
F_13 ( L_10 , F_1 , V_10 ) ;
F_14 ( V_10 , V_24 , F_15 ( V_24 ) ) ;
F_16 ( V_30 , F_15 ( V_30 ) ) ;
V_22 = F_17 ( L_10 ) ;
}
void F_18 ( void ) {
T_8 V_35 ;
V_35 = F_19 ( L_10 ) ;
F_20 ( L_11 , V_36 , V_35 ) ;
}
