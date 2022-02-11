extern void F_1 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( V_3 , F_3 ( V_1 ) , V_2 ) ;
F_4 ( L_1 , V_1 , V_4 ) ;
}
extern void F_5 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( V_5 , F_3 ( V_1 ) , V_2 ) ;
F_4 ( L_1 , V_1 , V_4 ) ;
}
extern void F_6 ( T_1 V_1 , T_2 V_2 V_6 ) {
F_7 ( V_3 , F_3 ( V_1 ) ) ;
if ( ! F_8 ( V_1 ) )
F_9 ( L_1 , V_1 , V_4 ) ;
}
extern void F_10 ( T_1 V_1 , T_2 V_2 V_6 ) {
F_7 ( V_5 , F_3 ( V_1 ) ) ;
if ( ! F_11 ( V_1 ) )
F_9 ( L_1 , V_1 , V_4 ) ;
}
T_2 F_11 ( T_1 V_1 ) {
return ( T_2 ) F_12 ( V_3 , F_3 ( V_1 ) ) ;
}
T_2 F_8 ( T_1 V_1 ) {
return ( T_2 ) F_12 ( V_5 , F_3 ( V_1 ) ) ;
}
static int
F_13 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_14 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , NULL ) ;
return T_7 ;
}
static int
F_15 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 69 "../../asn1/tcap/tcap.cnf"
T_7 = F_16 ( TRUE , T_6 , T_7 , T_9 , T_11 , - 1 ) ;
return T_7 ;
}
static int
F_17 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_7 , T_12 , V_8 ) ;
return T_7 ;
}
static int
F_19 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 64 "../../asn1/tcap/tcap.cnf"
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_9 , 8 , TRUE , F_17 ) ;
return T_7 ;
}
static int
F_21 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 59 "../../asn1/tcap/tcap.cnf"
T_7 = F_19 ( FALSE , T_6 , T_7 , T_9 , T_11 , - 1 ) ;
return T_7 ;
}
static int
F_22 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 11 , TRUE , F_21 ) ;
return T_7 ;
}
static int
F_23 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_25 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_26 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_11 , T_12 , V_12 ,
NULL ) ;
return T_7 ;
}
static int
F_28 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 74 "../../asn1/tcap/tcap.cnf"
T_7 = F_29 ( T_9 , T_11 , T_6 , T_7 ) ;
return T_7 ;
}
static int
F_30 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_13 , T_12 , V_14 ) ;
return T_7 ;
}
static int
F_31 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_15 , T_12 , V_16 ) ;
return T_7 ;
}
static int
F_32 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_17 , T_12 , V_18 ) ;
return T_7 ;
}
static int
F_33 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_34 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_19 , T_12 , V_20 ,
NULL ) ;
return T_7 ;
}
static int
F_35 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_21 , T_12 , V_22 ) ;
return T_7 ;
}
static int
F_36 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_37 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ) ;
return T_7 ;
}
static int
F_38 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_23 , T_12 , V_24 ,
NULL ) ;
return T_7 ;
}
static int
F_39 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_40 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_41 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_42 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_43 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_25 , T_12 , V_26 ,
NULL ) ;
return T_7 ;
}
static int
F_44 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_27 , T_12 , V_28 ) ;
return T_7 ;
}
static int
F_45 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 79 "../../asn1/tcap/tcap.cnf"
T_5 * V_29 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
T_1 V_33 , V_34 ;
T_14 V_35 ;
V_34 = F_46 ( T_9 -> V_36 , T_11 , T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_34 = F_47 ( T_9 -> V_36 , T_11 , T_6 , V_34 , & V_33 , & V_35 ) ;
V_29 = F_48 ( T_6 , T_7 , V_33 + V_34 - T_7 , V_33 + V_34 - T_7 ) ;
if ( ! V_29 )
return V_34 ;
F_49 {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_37 , T_12 , V_38 ,
NULL ) ;
}
F_50 (BoundsError) {
V_39 ;
}
F_50 (ReportedBoundsError) {
F_51 ( T_6 , T_9 -> V_36 , T_11 ) ;
}
V_40 ;
F_52 ( T_4 , V_29 , 0 , T_9 , V_41 , T_12 ) ;
return T_7 ;
}
static int
F_53 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_42 , T_12 , V_43 ) ;
return T_7 ;
}
static int
F_55 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 12 , TRUE , F_53 ) ;
return T_7 ;
}
static int
F_56 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_44 , T_12 , V_45 ) ;
return T_7 ;
}
static int
F_57 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_58 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_59 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 126 "../../asn1/tcap/tcap.cnf"
T_5 * V_46 ;
T_15 V_33 , V_47 ;
T_16 * V_48 ;
T_10 * V_49 ;
V_48 = F_60 ( T_11 , T_6 , T_7 , - 1 , L_2 ) ;
V_49 = F_61 ( V_48 , V_50 ) ;
T_7 = F_58 ( T_4 , T_9 , V_49 , T_6 , T_7 , V_51 ,
& V_46 ) ;
if ( V_46 ) {
V_33 = F_62 ( V_46 , 0 ) ;
switch( V_33 ) {
case 1 :
V_52 -> V_53 = F_63 ( V_46 , 0 ) ;
break;
case 2 :
V_52 -> V_53 = F_64 ( V_46 , 0 ) ;
break;
case 4 :
V_52 -> V_53 = F_65 ( V_46 , 0 ) ;
break;
default:
V_52 -> V_53 = 0 ;
break;
}
if ( V_33 ) {
F_66 ( T_9 -> V_36 -> V_54 , V_55 , L_3 ) ;
for( V_47 = 0 ; V_47 < V_33 ; V_47 ++ )
F_67 ( T_9 -> V_36 -> V_54 , V_55 , L_4 , F_63 ( V_46 , V_47 ) ) ;
F_66 ( T_9 -> V_36 -> V_54 , V_55 , L_5 ) ;
}
}
return T_7 ;
}
static int
F_68 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 200 "../../asn1/tcap/tcap.cnf"
V_52 -> V_56 = V_57 ;
F_69 ( T_9 -> V_36 -> V_54 , V_55 , L_6 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_58 , T_12 , V_59 ) ;
return T_7 ;
}
static int
F_70 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 165 "../../asn1/tcap/tcap.cnf"
T_5 * V_46 ;
T_15 V_33 , V_47 ;
T_16 * V_48 ;
T_10 * V_49 ;
V_48 = F_60 ( T_11 , T_6 , T_7 , - 1 , L_7 ) ;
V_49 = F_61 ( V_48 , V_50 ) ;
T_7 = F_58 ( T_4 , T_9 , V_49 , T_6 , T_7 , V_51 ,
& V_46 ) ;
if ( V_46 ) {
V_33 = F_62 ( V_46 , 0 ) ;
switch( V_33 ) {
case 1 :
V_52 -> V_60 = F_63 ( V_46 , 0 ) ;
break;
case 2 :
V_52 -> V_60 = F_64 ( V_46 , 0 ) ;
break;
case 4 :
V_52 -> V_60 = F_65 ( V_46 , 0 ) ;
break;
default:
V_52 -> V_60 = 0 ;
break;
}
if ( V_33 ) {
F_66 ( T_9 -> V_36 -> V_54 , V_55 , L_8 ) ;
for( V_47 = 0 ; V_47 < V_33 ; V_47 ++ )
F_67 ( T_9 -> V_36 -> V_54 , V_55 , L_4 , F_63 ( V_46 , V_47 ) ) ;
F_66 ( T_9 -> V_36 -> V_54 , V_55 , L_5 ) ;
}
}
return T_7 ;
}
static int
F_71 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 214 "../../asn1/tcap/tcap.cnf"
V_52 -> V_56 = V_61 ;
F_69 ( T_9 -> V_36 -> V_54 , V_55 , L_9 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_62 , T_12 , V_63 ) ;
return T_7 ;
}
static int
F_72 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 221 "../../asn1/tcap/tcap.cnf"
V_52 -> V_56 = V_64 ;
F_69 ( T_9 -> V_36 -> V_54 , V_55 , L_10 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_65 , T_12 , V_66 ) ;
return T_7 ;
}
static int
F_73 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_74 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 10 , TRUE , F_73 ) ;
return T_7 ;
}
static int
F_75 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_67 , T_12 , V_68 ,
NULL ) ;
return T_7 ;
}
static int
F_76 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 228 "../../asn1/tcap/tcap.cnf"
V_52 -> V_56 = V_69 ;
F_69 ( T_9 -> V_36 -> V_54 , V_55 , L_11 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_70 , T_12 , V_71 ) ;
return T_7 ;
}
static int
F_77 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_72 , T_12 , V_73 ,
NULL ) ;
return T_7 ;
}
static int
F_78 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_74 , T_12 , V_75 ,
NULL ) ;
return T_7 ;
}
static int
F_79 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_80 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_76 , T_12 , V_77 ,
NULL ) ;
return T_7 ;
}
static int
F_81 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 111 "../../asn1/tcap/tcap.cnf"
T_7 = F_82 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_78 ) ;
V_79 . V_80 = ( void * ) V_78 ;
V_79 . V_81 = TRUE ;
return T_7 ;
}
static int
F_83 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_84 ( T_4 , T_11 , T_6 , T_7 , T_9 , T_12 , NULL ) ;
return T_7 ;
}
static int
F_85 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_82 , T_12 , V_83 ) ;
return T_7 ;
}
static int
F_86 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_84 , T_12 , V_85 ) ;
return T_7 ;
}
static int
F_87 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 0 , TRUE , F_86 ) ;
return T_7 ;
}
int
F_88 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_86 , T_12 , V_87 ,
NULL ) ;
return T_7 ;
}
static int
F_89 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_80 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_88 , T_12 , V_89 ,
NULL ) ;
return T_7 ;
}
static int
F_90 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 116 "../../asn1/tcap/tcap.cnf"
T_7 = F_82 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_78 ) ;
V_79 . V_80 = ( void * ) V_78 ;
V_79 . V_81 = TRUE ;
return T_7 ;
}
static int
F_91 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_90 , T_12 , V_91 ) ;
return T_7 ;
}
static int
F_92 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_92 , T_12 , V_93 ) ;
return T_7 ;
}
static int
F_93 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 0 , TRUE , F_92 ) ;
return T_7 ;
}
static int
F_94 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_80 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_94 , T_12 , V_95 ,
NULL ) ;
return T_7 ;
}
static int
F_95 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 121 "../../asn1/tcap/tcap.cnf"
T_7 = F_82 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_78 ) ;
V_79 . V_80 = ( void * ) V_78 ;
V_79 . V_81 = TRUE ;
return T_7 ;
}
static int
F_96 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_97 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_98 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_99 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_96 , T_12 , V_97 ,
NULL ) ;
return T_7 ;
}
static int
F_100 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_98 , T_12 , V_99 ) ;
return T_7 ;
}
static int
F_101 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_100 , T_12 , V_101 ) ;
return T_7 ;
}
static int
F_102 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 1 , TRUE , F_101 ) ;
return T_7 ;
}
static int
F_103 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_104 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_102 , T_12 , V_103 ) ;
return T_7 ;
}
static int
F_105 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_104 , T_12 , V_105 ) ;
return T_7 ;
}
static int
F_106 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 4 , TRUE , F_105 ) ;
return T_7 ;
}
int
F_16 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_106 , T_12 , V_107 ,
NULL ) ;
return T_7 ;
}
static void F_107 ( T_5 * T_6 V_6 , T_17 * V_36 V_6 , T_10 * T_11 V_6 ) {
T_8 V_108 ;
F_108 ( & V_108 , V_109 , TRUE , V_36 ) ;
F_88 ( FALSE , T_6 , 0 , & V_108 , T_11 , V_110 ) ;
}
static void F_109 ( T_5 * T_6 V_6 , T_17 * V_36 V_6 , T_10 * T_11 V_6 ) {
T_8 V_108 ;
F_108 ( & V_108 , V_109 , TRUE , V_36 ) ;
F_16 ( FALSE , T_6 , 0 , & V_108 , T_11 , V_111 ) ;
}
static void
F_110 ( T_5 * T_6 , T_17 * V_36 , T_10 * V_112 )
{
T_16 * V_113 = NULL ;
T_10 * T_11 = NULL ;
struct V_114 * V_115 ;
T_2 V_116 ;
T_8 V_108 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
F_111 ( T_6 , 0 , & V_30 , & V_31 , & V_32 ) ;
if( V_30 == V_117 ) {
switch( V_32 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
F_112 ( V_118 , T_6 , V_36 , V_112 ) ;
return;
break;
default:
return;
}
}
F_108 ( & V_108 , V_109 , TRUE , V_36 ) ;
V_41 = V_112 ;
V_119 = NULL ;
F_69 ( V_36 -> V_54 , V_120 , L_12 ) ;
if( V_112 ) {
V_113 = F_113 ( V_112 , V_121 , T_6 , 0 , - 1 , V_122 ) ;
T_11 = F_61 ( V_113 , V_123 ) ;
V_119 = T_11 ;
}
V_78 = NULL ;
V_124 = NULL ;
F_114 ( & V_79 ) ;
V_36 -> V_125 = & V_79 ;
V_52 = F_115 () ;
V_126 = FALSE ;
V_127 = NULL ;
F_77 ( FALSE , T_6 , 0 , & V_108 , T_11 , - 1 ) ;
if ( V_128 && ! V_126 ) {
V_115 = F_116 ( T_6 , V_36 , V_119 , V_52 ) ;
V_79 . V_129 = V_115 ;
if ( V_115 && V_78 && ! V_115 -> V_130 ) {
F_117 ( V_115 -> V_80 , V_78 , sizeof( V_115 -> V_80 ) ) ;
V_115 -> V_130 = TRUE ;
if ( ( V_116 = F_118 ( V_131 , V_78 ) ) ) {
V_115 -> V_116 = V_116 ;
V_115 -> V_132 = TRUE ;
}
}
if ( V_128 && V_115 && V_115 -> V_133 ) {
( V_115 -> V_133 ) ( T_6 , V_36 , V_119 , V_115 ) ;
}
}
}
void
F_119 ( void )
{
V_134 = F_120 ( L_13 ) ;
V_118 = F_120 ( L_14 ) ;
V_131 = F_121 ( L_15 ) ;
#line 1 "../../asn1/tcap/packet-tcap-dis-tab.c"
F_122 ( L_16 , F_109 , V_121 , L_17 ) ;
F_122 ( L_18 , F_107 , V_121 , L_19 ) ;
#line 254 "../../asn1/tcap/packet-tcap-template.c"
}
void
F_123 ( void )
{
static T_18 V_135 [] = {
{ & V_136 ,
{ L_20 , L_21 ,
V_137 , V_138 , NULL , 0 ,
NULL , V_139 }
} ,
{ & V_140 ,
{ L_22 , L_23 ,
V_137 , V_141 , NULL , 0 ,
NULL , V_139 }
} ,
{ & V_142 ,
{ L_24 , L_25 ,
V_143 , V_144 , NULL , 0 ,
NULL , V_139 }
} ,
{ & V_51 ,
{ L_26 , L_27 ,
V_143 , V_144 , NULL , 0 ,
NULL , V_139 }
} ,
{ & V_145 ,
{ L_28 ,
L_29 ,
V_146 , V_141 , NULL , 0x0 ,
NULL , V_139 }
} ,
{ & V_147 ,
{ L_30 ,
L_31 ,
V_148 , V_144 , NULL , 0x0 ,
L_32 , V_139 }
} ,
{ & V_149 ,
{ L_33 ,
L_34 ,
V_148 , V_144 , NULL , 0x0 ,
L_35 , V_139 }
} ,
{ & V_150 ,
{ L_36 ,
L_37 ,
V_151 , V_144 , NULL , 0x0 ,
L_38 , V_139 }
} ,
{ & V_152 ,
{ L_39 ,
L_40 ,
V_148 , V_144 , NULL , 0x0 ,
L_41 , V_139 }
} ,
#line 1 "../../asn1/tcap/packet-tcap-hfarr.c"
{ & V_110 ,
{ L_42 , L_43 ,
V_146 , V_141 , F_124 ( V_153 ) , 0 ,
NULL , V_139 } } ,
{ & V_111 ,
{ L_44 , L_45 ,
V_146 , V_141 , F_124 ( V_154 ) , 0 ,
NULL , V_139 } } ,
{ & V_155 ,
{ L_46 , L_47 ,
V_156 , V_144 , NULL , 0 ,
L_48 , V_139 } } ,
{ & V_157 ,
{ L_49 , L_50 ,
V_143 , V_144 , NULL , 0 ,
L_51 , V_139 } } ,
{ & V_158 ,
{ L_52 , L_53 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_160 ,
{ L_54 , L_55 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_161 ,
{ L_56 , L_57 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_162 ,
{ L_58 , L_59 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_163 ,
{ L_60 , L_61 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_164 ,
{ L_62 , L_63 ,
V_143 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_165 ,
{ L_64 , L_65 ,
V_146 , V_141 , NULL , 0 ,
L_66 , V_139 } } ,
{ & V_166 ,
{ L_67 , L_68 ,
V_143 , V_144 , NULL , 0 ,
L_69 , V_139 } } ,
{ & V_167 ,
{ L_70 , L_71 ,
V_143 , V_144 , NULL , 0 ,
L_72 , V_139 } } ,
{ & V_168 ,
{ L_73 , L_74 ,
V_146 , V_141 , F_124 ( V_169 ) , 0 ,
NULL , V_139 } } ,
{ & V_170 ,
{ L_75 , L_76 ,
V_146 , V_141 , F_124 ( V_171 ) , 0 ,
NULL , V_139 } } ,
{ & V_172 ,
{ L_77 , L_78 ,
V_143 , V_144 , NULL , 0 ,
L_79 , V_139 } } ,
{ & V_173 ,
{ L_80 , L_81 ,
V_146 , V_141 , F_124 ( V_174 ) , 0 ,
NULL , V_139 } } ,
{ & V_175 ,
{ L_82 , L_83 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_176 ,
{ L_84 , L_85 ,
V_159 , V_144 , NULL , 0 ,
L_86 , V_139 } } ,
{ & V_177 ,
{ L_87 , L_88 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_178 ,
{ L_89 , L_90 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_179 ,
{ L_91 , L_92 ,
V_159 , V_144 , NULL , 0 ,
L_86 , V_139 } } ,
{ & V_180 ,
{ L_93 , L_94 ,
V_181 , V_141 , NULL , 0 ,
L_95 , V_139 } } ,
{ & V_182 ,
{ L_96 , L_97 ,
V_181 , V_141 , NULL , 0 ,
L_95 , V_139 } } ,
{ & V_183 ,
{ L_98 , L_99 ,
V_146 , V_141 , F_124 ( V_184 ) , 0 ,
L_100 , V_139 } } ,
{ & V_185 ,
{ L_101 , L_102 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_186 ,
{ L_103 , L_104 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_187 ,
{ L_105 , L_106 ,
V_146 , V_141 , F_124 ( V_188 ) , 0 ,
NULL , V_139 } } ,
{ & V_189 ,
{ L_107 , L_108 ,
V_146 , V_141 , F_124 ( V_190 ) , 0 ,
NULL , V_139 } } ,
{ & V_191 ,
{ L_109 , L_110 ,
V_181 , V_141 , NULL , 0 ,
L_95 , V_139 } } ,
{ & V_192 ,
{ L_111 , L_112 ,
V_159 , V_144 , NULL , 0 ,
NULL , V_139 } } ,
{ & V_193 ,
{ L_113 , L_114 ,
V_146 , V_141 , F_124 ( V_194 ) , 0 ,
NULL , V_139 } } ,
{ & V_195 ,
{ L_115 , L_116 ,
V_181 , V_141 , F_124 ( V_196 ) , 0 ,
NULL , V_139 } } ,
{ & V_197 ,
{ L_117 , L_118 ,
V_181 , V_141 , F_124 ( V_198 ) , 0 ,
NULL , V_139 } } ,
{ & V_199 ,
{ L_119 , L_120 ,
V_181 , V_141 , F_124 ( V_200 ) , 0 ,
NULL , V_139 } } ,
{ & V_201 ,
{ L_121 , L_122 ,
V_181 , V_141 , F_124 ( V_202 ) , 0 ,
NULL , V_139 } } ,
{ & V_203 ,
{ L_123 , L_124 ,
V_181 , V_141 , NULL , 0 ,
L_125 , V_139 } } ,
{ & V_204 ,
{ L_126 , L_127 ,
V_156 , V_144 , NULL , 0 ,
L_48 , V_139 } } ,
{ & V_205 ,
{ L_128 , L_129 ,
V_181 , V_141 , NULL , 0 ,
L_130 , V_139 } } ,
{ & V_206 ,
{ L_131 , L_132 ,
V_181 , V_141 , NULL , 0 ,
L_125 , V_139 } } ,
{ & V_207 ,
{ L_133 , L_134 ,
V_159 , V_144 , NULL , 0 ,
L_135 , V_139 } } ,
{ & V_208 ,
{ L_136 , L_137 ,
V_143 , V_144 , NULL , 0 ,
L_138 , V_139 } } ,
{ & V_209 ,
{ L_139 , L_140 ,
V_156 , V_144 , NULL , 0 ,
L_141 , V_139 } } ,
{ & V_210 ,
{ L_142 , L_143 ,
V_146 , V_141 , NULL , 0 ,
L_144 , V_139 } } ,
{ & V_211 ,
{ L_145 , L_146 ,
V_159 , V_144 , NULL , 0 ,
L_147 , V_139 } } ,
{ & V_212 ,
{ L_148 , L_149 ,
V_159 , V_144 , NULL , 0 ,
L_150 , V_139 } } ,
{ & V_213 ,
{ L_151 , L_152 ,
V_159 , V_144 , NULL , 0 ,
L_153 , V_139 } } ,
{ & V_214 ,
{ L_154 , L_155 ,
V_159 , V_144 , NULL , 0 ,
L_156 , V_139 } } ,
{ & V_215 ,
{ L_136 , L_137 ,
V_143 , V_144 , NULL , 0 ,
L_157 , V_139 } } ,
{ & V_216 ,
{ L_139 , L_140 ,
V_156 , V_144 , NULL , 0 ,
L_158 , V_139 } } ,
{ & V_217 ,
{ L_142 , L_143 ,
V_146 , V_141 , NULL , 0 ,
L_159 , V_139 } } ,
{ & V_218 ,
{ L_145 , L_146 ,
V_159 , V_144 , NULL , 0 ,
L_147 , V_139 } } ,
{ & V_219 ,
{ L_136 , L_137 ,
V_143 , V_144 , NULL , 0 ,
L_160 , V_139 } } ,
{ & V_220 ,
{ L_139 , L_140 ,
V_156 , V_144 , NULL , 0 ,
L_161 , V_139 } } ,
{ & V_221 ,
{ L_162 , L_163 ,
V_181 , V_141 , F_124 ( V_222 ) , 0 ,
L_164 , V_139 } } ,
{ & V_223 ,
{ L_165 , L_166 ,
V_146 , V_141 , F_124 ( V_224 ) , 0 ,
L_167 , V_139 } } ,
{ & V_225 ,
{ L_142 , L_143 ,
V_146 , V_141 , NULL , 0 ,
L_168 , V_139 } } ,
{ & V_226 ,
{ L_145 , L_146 ,
V_159 , V_144 , NULL , 0 ,
L_147 , V_139 } } ,
{ & V_227 ,
{ L_169 , L_170 ,
V_181 , V_141 , F_124 ( V_228 ) , 0 ,
L_171 , V_139 } } ,
{ & V_229 ,
{ L_142 , L_143 ,
V_146 , V_141 , NULL , 0 ,
L_172 , V_139 } } ,
{ & V_230 ,
{ L_145 , L_146 ,
V_159 , V_144 , NULL , 0 ,
L_147 , V_139 } } ,
{ & V_231 ,
{ L_173 , L_174 ,
V_181 , V_141 , F_124 ( V_232 ) , 0 ,
NULL , V_139 } } ,
{ & V_233 ,
{ L_175 , L_176 ,
V_181 , V_141 , F_124 ( V_234 ) , 0 ,
NULL , V_139 } } ,
{ & V_235 ,
{ L_177 , L_178 ,
V_236 , 8 , NULL , 0x80 ,
NULL , V_139 } } ,
{ & V_237 ,
{ L_177 , L_178 ,
V_236 , 8 , NULL , 0x80 ,
NULL , V_139 } } ,
{ & V_238 ,
{ L_177 , L_178 ,
V_236 , 8 , NULL , 0x80 ,
NULL , V_139 } } ,
#line 316 "../../asn1/tcap/packet-tcap-template.c"
} ;
static T_14 * V_239 [] = {
& V_123 ,
& V_240 ,
& V_50 ,
& V_241 ,
& V_242 ,
#line 1 "../../asn1/tcap/packet-tcap-ettarr.c"
& V_8 ,
& V_73 ,
& V_45 ,
& V_59 ,
& V_63 ,
& V_66 ,
& V_71 ,
& V_68 ,
& V_43 ,
& V_38 ,
& V_14 ,
& V_18 ,
& V_16 ,
& V_22 ,
& V_28 ,
& V_24 ,
& V_26 ,
& V_12 ,
& V_75 ,
& V_20 ,
& V_87 ,
& V_85 ,
& V_77 ,
& V_83 ,
& V_107 ,
& V_93 ,
& V_89 ,
& V_91 ,
& V_101 ,
& V_95 ,
& V_99 ,
& V_105 ,
& V_103 ,
& V_97 ,
#line 326 "../../asn1/tcap/packet-tcap-template.c"
} ;
T_19 * V_243 ;
V_121 = F_125 ( V_244 , V_245 , V_246 ) ;
F_126 ( V_121 , V_135 , F_127 ( V_135 ) ) ;
F_128 ( V_239 , F_127 ( V_239 ) ) ;
V_243 = F_129 ( V_121 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_130 ( V_243 , L_179 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_130 ( V_243 , L_180 ) ;
#endif
F_131 ( & V_247 , L_181 , V_248 ) ;
V_249 = F_132 () ;
F_133 ( V_243 , L_182 , L_183 ,
L_184 ,
& V_247 , V_248 ) ;
F_134 ( V_243 , L_185 ,
L_186 ,
L_187 ,
& V_128 ) ;
F_134 ( V_243 , L_188 ,
L_189 ,
L_190 ,
& V_250 ) ;
F_135 ( V_243 , L_191 ,
L_192 ,
L_193 ,
10 , & V_251 ) ;
F_135 ( V_243 , L_194 ,
L_195 ,
L_196 ,
10 , & V_252 ) ;
V_3 = F_136 ( V_253 , V_254 ) ;
V_5 = F_136 ( V_253 , V_254 ) ;
F_137 ( L_197 , F_110 , V_121 ) ;
V_4 = F_138 ( F_110 , V_121 ) ;
F_139 ( & V_255 ) ;
}
static void F_140 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_141 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_255 ( void ) {
if ( V_249 ) {
F_142 ( V_249 , F_140 ) ;
F_143 ( V_249 ) ;
}
V_249 = F_144 ( V_247 ) ;
F_142 ( V_249 , F_141 ) ;
F_145 () ;
}
static int
F_29 ( T_8 * T_9 , T_10 * T_11 , T_5 * T_6 , int T_7 )
{
T_14 V_256 , V_257 , V_258 ;
T_5 * V_29 ;
T_10 * V_49 ;
T_16 * V_259 ;
T_13 V_30 ;
T_3 V_31 ;
T_20 V_32 ;
T_1 V_33 ;
T_1 V_260 ;
T_1 V_261 ;
T_3 V_35 ;
while ( F_146 ( T_6 , T_7 ) > 0 )
{
V_257 = T_7 ;
T_7 = F_111 ( T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_256 = T_7 ;
T_7 = F_147 ( T_6 , T_7 , & V_33 , & V_35 ) ;
V_258 = T_7 ;
V_260 = V_256 - V_257 ;
V_261 = V_258 - V_256 ;
if ( V_31 )
{
V_259 = F_60 ( T_11 , T_6 , V_257 ,
V_33 + ( V_258 - V_257 ) ,
L_198 ) ;
V_49 = F_61 ( V_259 , V_240 ) ;
F_148 ( V_49 , V_136 , T_6 ,
V_257 , V_260 , V_32 ,
L_199 ) ;
F_149 ( V_49 , V_136 , T_6 , V_257 ,
V_260 , V_30 ) ;
F_149 ( V_49 , V_140 , T_6 , V_256 ,
V_261 , V_33 ) ;
if ( V_33 - ( 2 * V_35 ) )
{
V_29 = F_48 ( T_6 , T_7 , V_33 - ( 2 * V_35 ) ,
V_33 - ( 2 * V_35 ) ) ;
F_29 ( T_9 , V_49 , V_29 , 0 ) ;
}
if ( V_35 )
F_60 ( V_49 , T_6 , T_7 + V_33 - 2 , 2 , L_200 ) ;
T_7 += V_33 ;
}
else
{
V_259 = F_60 ( T_11 , T_6 , V_257 ,
V_33 + ( V_258 - V_257 ) ,
L_201 , V_32 ) ;
V_49 = F_61 ( V_259 , V_240 ) ;
F_149 ( V_49 , V_136 , T_6 , V_257 ,
V_260 , V_32 ) ;
F_149 ( V_49 , V_140 , T_6 ,
V_257 + V_260 , V_261 , V_33 ) ;
if ( V_33 )
{
V_29 = F_48 ( T_6 , T_7 , V_33 , V_33 ) ;
F_58 ( TRUE , T_9 , T_11 , V_29 , 0 ,
V_142 , NULL ) ;
}
T_7 += V_33 ;
}
}
return T_7 ;
}
static void F_114 ( struct V_262 * V_263 )
{
memset ( V_263 , 0 , sizeof( struct V_262 ) ) ;
}
static int
F_52 ( T_3 T_4 V_6 , T_5 * T_6 , int T_7 , T_8 * T_9 V_6 , T_10 * T_11 , int T_12 V_6 )
{
T_2 V_116 = NULL ;
T_3 V_264 = FALSE ;
struct V_114 * V_115 = NULL ;
if ( V_128 ) {
if ( ! V_126 ) {
V_115 = F_116 ( T_6 , T_9 -> V_36 , V_119 , V_52 ) ;
V_126 = TRUE ;
V_127 = V_115 ;
V_79 . V_129 = V_115 ;
} else{
V_115 = V_127 ;
V_79 . V_129 = V_115 ;
}
}
if ( V_115 ) {
if ( V_78 ) {
if ( V_115 -> V_130 ) {
if ( strncmp ( V_115 -> V_80 , V_78 , sizeof( V_115 -> V_80 ) ) != 0 ) {
F_117 ( V_115 -> V_80 , V_78 , sizeof( V_115 -> V_80 ) ) ;
if ( ( V_116 = F_118 ( V_131 , V_78 ) ) ) {
V_115 -> V_116 = V_116 ;
V_115 -> V_132 = TRUE ;
}
}
} else {
F_117 ( V_115 -> V_80 , V_78 , sizeof( V_115 -> V_80 ) ) ;
V_115 -> V_130 = TRUE ;
if ( ( V_116
= F_118 ( V_131 , V_78 ) ) ) {
V_115 -> V_116 = V_116 ;
V_115 -> V_132 = TRUE ;
} else {
if ( ( V_116 = F_8 ( T_9 -> V_36 -> V_265 ) ) ) {
V_115 -> V_116 = V_116 ;
V_115 -> V_132 = TRUE ;
}
}
}
} else {
if ( V_115 -> V_130 ) {
V_79 . V_80 = ( void * ) V_115 -> V_80 ;
V_79 . V_81 = TRUE ;
}
}
}
if ( V_115
&& V_115 -> V_132 ) {
V_116 = V_115 -> V_116 ;
V_264 = TRUE ;
}
if ( ! V_264 && V_266 ) {
V_264 = TRUE ;
V_116 = V_266 ;
}
if ( ! V_264 ) {
if ( V_131 && V_78 ) {
if ( ( V_116
= F_118 ( V_131 , V_78 ) ) ) {
V_264 = TRUE ;
} else {
if ( ( V_116
= F_8 ( T_9 -> V_36 -> V_265 ) ) ) {
V_264 = TRUE ;
} else {
V_116 = V_134 ;
V_264 = TRUE ;
}
}
} else {
if ( ( V_116 = F_8 ( T_9 -> V_36 -> V_265 ) ) ) {
V_264 = TRUE ;
} else {
V_116 = V_134 ;
V_264 = TRUE ;
}
}
} else {
}
if ( V_264 )
F_112 ( V_116 , T_6 , T_9 -> V_36 , T_11 ) ;
return T_7 ;
}
void F_150 ( T_2 V_267 , T_5 * T_6 , T_17 * V_36 , T_10 * T_11 ) {
V_266 = V_267 ;
F_49 {
F_110 ( T_6 , V_36 , T_11 ) ;
} F_151 {
V_266 = NULL ;
V_39 ;
} V_40 ;
V_266 = NULL ;
}
