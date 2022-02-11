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
#line 72 "../../asn1/tcap/tcap.cnf"
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
#line 67 "../../asn1/tcap/tcap.cnf"
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_9 , 8 , TRUE , F_17 ) ;
return T_7 ;
}
static int
F_21 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 62 "../../asn1/tcap/tcap.cnf"
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
#line 77 "../../asn1/tcap/tcap.cnf"
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
#line 82 "../../asn1/tcap/tcap.cnf"
T_5 * V_29 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
T_1 V_33 , V_34 ;
T_14 V_35 ;
V_34 = F_46 ( T_9 -> V_36 , T_11 , T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_34 = F_47 ( T_9 -> V_36 , T_11 , T_6 , V_34 , & V_33 , & V_35 ) ;
V_29 = F_48 ( T_6 , T_7 , V_33 + V_34 - T_7 ) ;
if ( ! V_29 )
return V_34 ;
F_49 {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_37 , T_12 , V_38 ,
NULL ) ;
}
F_50 {
F_51 ( T_6 , T_9 -> V_36 , T_11 , V_39 , V_40 ) ;
}
V_41 ;
F_52 ( T_4 , V_29 , 0 , T_9 , V_42 , T_12 ) ;
return T_7 ;
}
static int
F_53 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_43 , T_12 , V_44 ) ;
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
V_45 , T_12 , V_46 ) ;
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
T_5 * V_47 ;
T_15 V_33 , V_48 ;
T_10 * V_49 ;
V_49 = F_60 ( T_11 , T_6 , T_7 , - 1 , V_50 , NULL , L_2 ) ;
F_58 ( T_4 , T_9 , V_49 , T_6 , T_7 , V_51 , NULL ) ;
F_61 ( T_9 -> V_52 ) ;
T_7 = F_58 ( T_4 , T_9 , V_49 , T_6 , T_7 , V_53 ,
& V_47 ) ;
if ( V_47 ) {
V_33 = F_62 ( V_47 , 0 ) ;
switch( V_33 ) {
case 1 :
V_54 -> V_55 = F_63 ( V_47 , 0 ) ;
break;
case 2 :
V_54 -> V_55 = F_64 ( V_47 , 0 ) ;
break;
case 4 :
V_54 -> V_55 = F_65 ( V_47 , 0 ) ;
break;
default:
V_54 -> V_55 = 0 ;
break;
}
if ( V_33 ) {
F_66 ( T_9 -> V_36 -> V_56 , V_57 , L_3 ) ;
for( V_48 = 0 ; V_48 < V_33 ; V_48 ++ )
F_67 ( T_9 -> V_36 -> V_56 , V_57 , L_4 , F_63 ( V_47 , V_48 ) ) ;
F_66 ( T_9 -> V_36 -> V_56 , V_57 , L_5 ) ;
}
}
return T_7 ;
}
static int
F_68 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 200 "../../asn1/tcap/tcap.cnf"
V_54 -> V_58 = V_59 ;
F_69 ( T_9 -> V_36 -> V_56 , V_57 , L_6 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_60 , T_12 , V_61 ) ;
return T_7 ;
}
static int
F_70 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 165 "../../asn1/tcap/tcap.cnf"
T_5 * V_47 ;
T_15 V_33 , V_48 ;
T_10 * V_49 ;
V_49 = F_60 ( T_11 , T_6 , T_7 , - 1 , V_62 , NULL , L_7 ) ;
F_58 ( T_4 , T_9 , V_49 , T_6 , T_7 , V_51 , NULL ) ;
F_61 ( T_9 -> V_52 ) ;
T_7 = F_58 ( T_4 , T_9 , V_49 , T_6 , T_7 , V_63 ,
& V_47 ) ;
if ( V_47 ) {
V_33 = F_62 ( V_47 , 0 ) ;
switch( V_33 ) {
case 1 :
V_54 -> V_64 = F_63 ( V_47 , 0 ) ;
break;
case 2 :
V_54 -> V_64 = F_64 ( V_47 , 0 ) ;
break;
case 4 :
V_54 -> V_64 = F_65 ( V_47 , 0 ) ;
break;
default:
V_54 -> V_64 = 0 ;
break;
}
if ( V_33 ) {
F_66 ( T_9 -> V_36 -> V_56 , V_57 , L_8 ) ;
for( V_48 = 0 ; V_48 < V_33 ; V_48 ++ )
F_67 ( T_9 -> V_36 -> V_56 , V_57 , L_4 , F_63 ( V_47 , V_48 ) ) ;
F_66 ( T_9 -> V_36 -> V_56 , V_57 , L_5 ) ;
}
}
return T_7 ;
}
static int
F_71 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 214 "../../asn1/tcap/tcap.cnf"
V_54 -> V_58 = V_65 ;
F_69 ( T_9 -> V_36 -> V_56 , V_57 , L_9 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_66 , T_12 , V_67 ) ;
return T_7 ;
}
static int
F_72 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 221 "../../asn1/tcap/tcap.cnf"
V_54 -> V_58 = V_68 ;
F_69 ( T_9 -> V_36 -> V_56 , V_57 , L_10 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_69 , T_12 , V_70 ) ;
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
V_71 , T_12 , V_72 ,
NULL ) ;
return T_7 ;
}
static int
F_76 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 228 "../../asn1/tcap/tcap.cnf"
V_54 -> V_58 = V_73 ;
F_69 ( T_9 -> V_36 -> V_56 , V_57 , L_11 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_74 , T_12 , V_75 ) ;
return T_7 ;
}
static int
F_77 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_76 , T_12 , V_77 ,
NULL ) ;
return T_7 ;
}
static int
F_78 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_78 , T_12 , V_79 ,
NULL ) ;
return T_7 ;
}
static int
F_79 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_80 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_80 , T_12 , V_81 ,
NULL ) ;
return T_7 ;
}
static int
F_81 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 111 "../../asn1/tcap/tcap.cnf"
T_7 = F_82 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_82 ) ;
V_83 . V_84 = ( const void * ) V_82 ;
V_83 . V_85 = TRUE ;
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
V_86 , T_12 , V_87 ) ;
return T_7 ;
}
static int
F_86 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_88 , T_12 , V_89 ) ;
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
V_90 , T_12 , V_91 ,
NULL ) ;
return T_7 ;
}
static int
F_89 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_80 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_92 , T_12 , V_93 ,
NULL ) ;
return T_7 ;
}
static int
F_90 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 116 "../../asn1/tcap/tcap.cnf"
T_7 = F_82 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_82 ) ;
V_83 . V_84 = ( const void * ) V_82 ;
V_83 . V_85 = TRUE ;
return T_7 ;
}
static int
F_91 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_94 , T_12 , V_95 ) ;
return T_7 ;
}
static int
F_92 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_96 , T_12 , V_97 ) ;
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
V_98 , T_12 , V_99 ,
NULL ) ;
return T_7 ;
}
static int
F_95 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 121 "../../asn1/tcap/tcap.cnf"
T_7 = F_82 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_82 ) ;
V_83 . V_84 = ( const void * ) V_82 ;
V_83 . V_85 = TRUE ;
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
V_100 , T_12 , V_101 ,
NULL ) ;
return T_7 ;
}
static int
F_100 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_102 , T_12 , V_103 ) ;
return T_7 ;
}
static int
F_101 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_104 , T_12 , V_105 ) ;
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
V_106 , T_12 , V_107 ) ;
return T_7 ;
}
static int
F_105 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_108 , T_12 , V_109 ) ;
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
V_110 , T_12 , V_111 ,
NULL ) ;
return T_7 ;
}
static void F_107 ( T_5 * T_6 V_6 , T_16 * V_36 V_6 , T_10 * T_11 V_6 ) {
T_8 V_112 ;
F_108 ( & V_112 , V_113 , TRUE , V_36 ) ;
F_88 ( FALSE , T_6 , 0 , & V_112 , T_11 , V_114 ) ;
}
static void F_109 ( T_5 * T_6 V_6 , T_16 * V_36 V_6 , T_10 * T_11 V_6 ) {
T_8 V_112 ;
F_108 ( & V_112 , V_113 , TRUE , V_36 ) ;
F_16 ( FALSE , T_6 , 0 , & V_112 , T_11 , V_115 ) ;
}
static void
F_110 ( T_17 V_116 , char * V_117 , ... )
{
T_18 V_118 ;
if ( V_116 > V_119 ) return;
va_start ( V_118 , V_117 ) ;
vfprintf ( V_120 , V_117 , V_118 ) ;
va_end ( V_118 ) ;
}
static T_14
F_111 ( T_19 V_121 , T_19 V_122 )
{
const struct V_123 * V_124 = ( const struct V_123 * ) V_121 ;
const struct V_123 * V_125 = ( const struct V_123 * ) V_122 ;
return ( V_124 -> V_126 == V_125 -> V_126 ) ;
}
static T_17
F_112 ( T_19 V_127 )
{
const struct V_123 * V_128 = ( const struct V_123 * ) V_127 ;
return V_128 -> V_126 ;
}
static T_14
F_113 ( T_19 V_121 , T_19 V_122 )
{
const struct V_129 * V_124 = ( const struct V_129 * ) V_121 ;
const struct V_129 * V_125 = ( const struct V_129 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( ( V_124 -> V_131 == V_125 -> V_131 ) &&
( V_124 -> V_132 == V_125 -> V_132 ) &&
( V_124 -> V_133 == V_125 -> V_133 ) )
||
( ( V_124 -> V_131 == V_125 -> V_132 ) &&
( V_124 -> V_132 == V_125 -> V_131 ) &&
( V_124 -> V_133 == V_125 -> V_133 ) )
)
return TRUE ;
}
return FALSE ;
}
static T_17
F_114 ( T_19 V_127 )
{
const struct V_129 * V_128 = ( const struct V_129 * ) V_127 ;
T_17 V_134 ;
V_134 = V_128 -> V_133 ;
return V_134 ;
}
static T_14
F_115 ( T_19 V_121 , T_19 V_122 )
{
const struct V_135 * V_124 = ( const struct V_135 * ) V_121 ;
const struct V_135 * V_125 = ( const struct V_135 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( V_124 -> V_131 == V_125 -> V_131 ) &&
( V_124 -> V_132 == V_125 -> V_132 ) &&
( V_124 -> V_55 == V_125 -> V_55 ) &&
( V_124 -> V_64 == V_125 -> V_64 ) ) {
return TRUE ;
}
else if ( ( V_124 -> V_131 == V_125 -> V_132 ) &&
( V_124 -> V_132 == V_125 -> V_131 ) &&
( V_124 -> V_55 == V_125 -> V_64 ) &&
( V_124 -> V_64 == V_125 -> V_55 ) ) {
return TRUE ;
}
}
return FALSE ;
}
static T_17
F_116 ( T_19 V_127 )
{
const struct V_135 * V_128 = ( const struct V_135 * ) V_127 ;
T_17 V_134 ;
V_134 = V_128 -> V_55 + V_128 -> V_64 ;
return V_134 ;
}
static T_14
F_117 ( T_19 V_121 , T_19 V_122 )
{
const struct V_136 * V_124 = ( const struct V_136 * ) V_121 ;
const struct V_136 * V_125 = ( const struct V_136 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( ( V_124 -> V_131 == V_125 -> V_131 ) &&
( V_124 -> V_132 == V_125 -> V_132 ) &&
( V_124 -> V_133 == V_125 -> V_133 ) )
||
( ( V_124 -> V_131 == V_125 -> V_132 ) &&
( V_124 -> V_132 == V_125 -> V_131 ) &&
( V_124 -> V_133 == V_125 -> V_133 ) ) )
return TRUE ;
}
return FALSE ;
}
static T_17
F_118 ( T_19 V_127 )
{
const struct V_136 * V_128 = ( const struct V_136 * ) V_127 ;
T_17 V_134 ;
V_134 = V_128 -> V_133 ;
return V_134 ;
}
static T_14
F_119 ( T_19 V_121 , T_19 V_122 )
{
const struct V_137 * V_124 = ( const struct V_137 * ) V_121 ;
const struct V_137 * V_125 = ( const struct V_137 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( ( V_124 -> V_131 == V_125 -> V_131 ) &&
( V_124 -> V_132 == V_125 -> V_132 ) &&
( V_124 -> V_133 == V_125 -> V_133 ) )
||
( ( V_124 -> V_131 == V_125 -> V_132 ) &&
( V_124 -> V_132 == V_125 -> V_131 ) &&
( V_124 -> V_133 == V_125 -> V_133 ) )
)
return TRUE ;
}
return FALSE ;
}
static T_17
F_120 ( T_19 V_127 )
{
const struct V_137 * V_128 = ( const struct V_137 * ) V_127 ;
T_17 V_134 ;
V_134 = V_128 -> V_133 ;
return V_134 ;
}
static void
F_121 ( struct V_138 * V_139 ,
T_16 * V_36 )
{
V_139 -> V_140 -> V_141 = V_36 -> V_142 -> V_143 ;
V_139 -> V_140 -> V_144 = 0 ;
V_139 -> V_140 -> V_145 = FALSE ;
V_139 -> V_140 -> V_146 = V_36 -> V_142 -> V_147 ;
}
static struct V_138 *
F_122 ( struct V_138 * V_148 ,
struct V_149 * V_150 ,
T_16 * V_36 )
{
struct V_138 * V_151 = NULL ;
#ifdef F_123
V_151 = (struct V_138 * ) F_124 ( sizeof( struct V_138 ) ) ;
#else
V_151 = F_125 ( F_126 () , struct V_138 ) ;
#endif
V_151 -> V_140 = V_150 ;
V_150 -> V_152 = V_151 ;
V_151 -> V_153 = V_148 -> V_153 ;
V_151 -> V_140 -> V_141 = V_36 -> V_142 -> V_143 ;
V_151 -> V_154 = NULL ;
V_151 -> V_155 = V_148 ;
V_151 -> V_156 = FALSE ;
#ifdef F_127
F_110 ( 10 , L_12 , V_151 -> V_140 -> V_126 ) ;
#endif
V_148 -> V_154 = V_151 ;
if ( V_148 -> V_140 -> V_144 == 0 ) {
#ifdef F_127
F_110 ( 10 , L_13 ) ;
#endif
V_148 -> V_140 -> V_144 = V_36 -> V_142 -> V_143 - 1 ;
}
return V_151 ;
}
static void
F_128 ( struct V_157 * V_158 ,
T_16 * V_36 )
{
V_158 -> V_140 -> V_141 = V_36 -> V_142 -> V_143 ;
V_158 -> V_140 -> V_144 = 0 ;
V_158 -> V_140 -> V_145 = FALSE ;
V_158 -> V_140 -> V_146 = V_36 -> V_142 -> V_147 ;
}
static struct V_157 *
F_129 ( struct V_157 * V_159 ,
struct V_149 * V_150 ,
T_16 * V_36 )
{
struct V_157 * V_160 = NULL ;
#ifdef F_123
V_160 = (struct V_157 * ) F_124 ( sizeof( struct V_157 ) ) ;
#else
V_160 = F_125 ( F_126 () , struct V_157 ) ;
#endif
V_160 -> V_140 = V_150 ;
V_150 -> V_161 = V_160 ;
V_160 -> V_162 = V_159 -> V_162 ;
V_160 -> V_140 -> V_141 = V_36 -> V_142 -> V_143 ;
V_160 -> V_163 = NULL ;
V_160 -> V_164 = V_159 ;
V_160 -> V_156 = FALSE ;
#ifdef F_127
F_110 ( 10 , L_14 , V_160 -> V_140 -> V_126 ) ;
#endif
V_159 -> V_163 = V_160 ;
if ( V_159 -> V_140 -> V_144 == 0 ) {
#ifdef F_127
F_110 ( 10 , L_13 ) ;
#endif
V_159 -> V_140 -> V_144 = V_36 -> V_142 -> V_143 - 1 ;
}
return V_160 ;
}
static struct V_165 *
F_130 ( struct V_165 * V_166 ,
struct V_149 * V_150 )
{
struct V_165 * V_167 = NULL ;
#ifdef F_123
V_167 = (struct V_165 * ) F_124 ( sizeof( struct V_165 ) ) ;
#else
V_167 = F_125 ( F_126 () , struct V_165 ) ;
#endif
V_167 -> V_140 = V_150 ;
V_150 -> V_168 = V_167 ;
V_167 -> V_169 = V_166 -> V_169 ;
V_167 -> V_170 = NULL ;
V_167 -> V_171 = V_166 ;
V_167 -> V_156 = FALSE ;
#ifdef F_127
F_110 ( 10 , L_15 , V_167 -> V_140 -> V_126 ) ;
#endif
V_166 -> V_170 = V_167 ;
return V_167 ;
}
static struct V_172 *
F_131 ( struct V_172 * V_173 ,
struct V_149 * V_150 )
{
struct V_172 * V_174 = NULL ;
#ifdef F_123
V_174 = (struct V_175 * ) F_124 ( sizeof( struct V_172 ) ) ;
#else
V_174 = F_125 ( F_126 () , struct V_172 ) ;
#endif
V_174 -> V_140 = V_150 ;
V_150 -> V_176 = V_174 ;
V_174 -> V_177 = V_173 -> V_177 ;
V_174 -> V_178 = NULL ;
V_174 -> V_179 = V_173 ;
V_174 -> V_156 = FALSE ;
#ifdef F_127
F_110 ( 10 , L_16 , V_174 -> V_140 -> V_126 ) ;
#endif
V_173 -> V_178 = V_174 ;
return V_174 ;
}
static struct V_138 *
F_132 ( struct V_129 * V_180 ,
T_16 * V_36 , T_3 V_181 )
{
struct V_138 * V_139 = NULL ;
V_139 = (struct V_138 * ) F_12 ( V_182 , V_180 ) ;
if( V_139 ) {
do {
if ( V_139 -> V_140 ) {
if ( ( V_181 &&
V_36 -> V_142 -> V_143 == V_139 -> V_140 -> V_141 )
||
( ! V_181 &&
V_36 -> V_142 -> V_143 >= V_139 -> V_140 -> V_141 &&
( V_139 -> V_140 -> V_144 ? V_36 -> V_142 -> V_143 <= V_139 -> V_140 -> V_144 : 1 )
)
) {
#ifdef F_127
F_110 ( 10 , L_17 , V_139 -> V_140 -> V_126 ) ;
#endif
return V_139 ;
}
#ifdef F_127
F_110 ( 60 , L_18 , V_139 -> V_140 -> V_126 ) ;
#endif
}
if( V_139 -> V_154 == NULL ) {
#ifdef F_127
F_110 ( 23 , L_19 ) ;
#endif
break;
}
V_139 = V_139 -> V_154 ;
} while ( V_139 != NULL ) ;
} else {
#ifdef F_127
F_110 ( 23 , L_20 ) ;
#endif
}
return NULL ;
}
static struct V_165 *
F_133 ( struct V_135 * V_183 ,
T_16 * V_36 )
{
struct V_165 * V_184 = NULL ;
V_184 = (struct V_165 * ) F_12 ( V_185 , V_183 ) ;
if( V_184 ) {
do {
if ( V_184 -> V_140 ) {
if ( V_36 -> V_142 -> V_143 >= V_184 -> V_140 -> V_141 &&
( V_184 -> V_140 -> V_144 ? V_36 -> V_142 -> V_143 <= V_184 -> V_140 -> V_144 : 1 ) ) {
#ifdef F_127
F_110 ( 10 , L_21 , V_184 -> V_140 -> V_126 ) ;
#endif
return V_184 ;
}
#ifdef F_127
F_110 ( 60 , L_22 , V_184 -> V_140 -> V_126 ) ;
#endif
}
if( V_184 -> V_170 == NULL ) {
#ifdef F_127
F_110 ( 23 , L_23 ) ;
#endif
break;
}
V_184 = V_184 -> V_170 ;
} while ( V_184 != NULL ) ;
} else {
#ifdef F_127
F_110 ( 23 , L_24 ) ;
#endif
}
return NULL ;
}
static struct V_172 *
F_134 ( struct V_136 * V_186 ,
T_16 * V_36 , T_3 V_187 )
{
struct V_172 * V_188 = NULL ;
V_188 = (struct V_172 * ) F_12 ( V_189 , V_186 ) ;
if( V_188 ) {
do {
if ( V_188 -> V_140 ) {
if ( ( V_187 &&
( V_188 -> V_140 -> V_144 ? V_36 -> V_142 -> V_143 == V_188 -> V_140 -> V_144 : 1 )
)
||
( ! V_187 &&
V_36 -> V_142 -> V_143 >= V_188 -> V_140 -> V_141 &&
( V_188 -> V_140 -> V_144 ? V_36 -> V_142 -> V_143 <= V_188 -> V_140 -> V_144 : 1 )
)
) {
#ifdef F_127
F_110 ( 10 , L_25 , V_188 -> V_140 -> V_126 ) ;
#endif
return V_188 ;
}
#ifdef F_127
F_110 ( 60 , L_26 , V_188 -> V_140 -> V_126 ) ;
#endif
}
if( V_188 -> V_178 == NULL ) {
#ifdef F_127
F_110 ( 23 , L_27 ) ;
#endif
break;
}
V_188 = V_188 -> V_178 ;
} while ( V_188 != NULL ) ;
} else {
#ifdef F_127
F_110 ( 23 , L_28 ) ;
#endif
}
return NULL ;
}
static struct V_149 *
F_135 ( struct V_123 * V_190 ,
T_16 * V_36 )
{
struct V_123 * V_191 ;
struct V_149 * V_192 = NULL ;
#ifdef F_123
V_191 = (struct V_123 * ) F_136 ( sizeof( struct V_123 ) ) ;
#else
V_191 = F_137 ( F_126 () , struct V_123 ) ;
#endif
V_191 -> V_126 = V_190 -> V_126 ;
#ifdef F_123
V_192 = (struct V_149 * ) F_124 ( sizeof( struct V_149 ) ) ;
#else
V_192 = F_125 ( F_126 () , struct V_149 ) ;
#endif
V_192 -> V_128 = V_191 ;
V_192 -> V_126 = V_190 -> V_126 ;
V_192 -> V_141 = V_36 -> V_142 -> V_143 ;
#ifdef F_127
F_110 ( 10 , L_29 , V_192 -> V_126 ) ;
#endif
F_2 ( V_193 , V_191 , V_192 ) ;
return V_192 ;
}
static struct V_138 *
F_138 ( struct V_129 * V_180 ,
struct V_149 * V_150 )
{
struct V_129 * V_194 ;
struct V_138 * V_151 = NULL ;
#ifdef F_123
V_194 = (struct V_129 * ) F_136 ( sizeof( struct V_129 ) ) ;
#else
V_194 = F_137 ( F_126 () , struct V_129 ) ;
#endif
V_194 -> V_130 = V_180 -> V_130 ;
V_194 -> V_133 = V_180 -> V_133 ;
V_194 -> V_131 = V_180 -> V_131 ;
V_194 -> V_132 = V_180 -> V_132 ;
#ifdef F_123
V_151 = (struct V_138 * ) F_124 ( sizeof( struct V_138 ) ) ;
#else
V_151 = F_125 ( F_126 () , struct V_138 ) ;
#endif
V_151 -> V_153 = V_194 ;
V_151 -> V_140 = V_150 ;
V_150 -> V_152 = V_151 ;
V_151 -> V_156 = TRUE ;
V_151 -> V_154 = NULL ;
V_151 -> V_155 = NULL ;
#ifdef F_127
F_110 ( 10 , L_17 , V_151 -> V_140 -> V_126 ) ;
#endif
F_2 ( V_182 , V_194 , V_151 ) ;
return V_151 ;
}
static struct V_165 *
F_139 ( struct V_135 * V_183 ,
struct V_149 * V_150 )
{
struct V_135 * V_195 ;
struct V_165 * V_167 = NULL ;
#ifdef F_123
V_195 = (struct V_135 * ) F_136 ( sizeof( struct V_135 ) ) ;
#else
V_195 = F_137 ( F_126 () , struct V_135 ) ;
#endif
V_195 -> V_130 = V_183 -> V_130 ;
V_195 -> V_55 = V_183 -> V_55 ;
V_195 -> V_64 = V_183 -> V_64 ;
V_195 -> V_131 = V_183 -> V_131 ;
V_195 -> V_132 = V_183 -> V_132 ;
#ifdef F_123
V_167 = (struct V_165 * ) F_124 ( sizeof( struct V_165 ) ) ;
#else
V_167 = F_125 ( F_126 () , struct V_165 ) ;
#endif
V_167 -> V_169 = V_195 ;
V_167 -> V_140 = V_150 ;
V_150 -> V_168 = V_167 ;
V_167 -> V_156 = TRUE ;
V_167 -> V_170 = NULL ;
V_167 -> V_171 = NULL ;
#ifdef F_127
F_110 ( 10 , L_21 , V_167 -> V_140 -> V_126 ) ;
#endif
F_2 ( V_185 , V_195 , V_167 ) ;
return V_167 ;
}
static struct V_172 *
F_140 ( struct V_136 * V_186 ,
struct V_149 * V_150 )
{
struct V_136 * V_196 ;
struct V_172 * V_174 = NULL ;
#ifdef F_123
V_196 = (struct V_136 * ) F_136 ( sizeof( struct V_136 ) ) ;
#else
V_196 = F_137 ( F_126 () , struct V_136 ) ;
#endif
V_196 -> V_130 = V_186 -> V_130 ;
V_196 -> V_133 = V_186 -> V_133 ;
V_196 -> V_131 = V_186 -> V_131 ;
V_196 -> V_132 = V_186 -> V_132 ;
#ifdef F_123
V_174 = (struct V_172 * ) F_124 ( sizeof( struct V_172 ) ) ;
#else
V_174 = F_125 ( F_126 () , struct V_172 ) ;
#endif
V_174 -> V_177 = V_196 ;
V_174 -> V_140 = V_150 ;
V_150 -> V_176 = V_174 ;
V_174 -> V_156 = TRUE ;
V_174 -> V_178 = NULL ;
V_174 -> V_179 = NULL ;
#ifdef F_127
F_110 ( 10 , L_25 , V_174 -> V_140 -> V_126 ) ;
#endif
F_2 ( V_189 , V_196 , V_174 ) ;
return V_174 ;
}
static struct V_157 *
F_141 ( struct V_137 * V_197 ,
struct V_149 * V_150 )
{
struct V_137 * V_198 ;
struct V_157 * V_160 = NULL ;
#ifdef F_123
V_198 = (struct V_137 * ) F_136 ( sizeof( struct V_137 ) ) ;
#else
V_198 = F_137 ( F_126 () , struct V_137 ) ;
#endif
V_198 -> V_130 = V_197 -> V_130 ;
V_198 -> V_133 = V_197 -> V_133 ;
V_198 -> V_131 = V_197 -> V_131 ;
V_198 -> V_132 = V_197 -> V_132 ;
#ifdef F_123
V_160 = (struct V_157 * ) F_124 ( sizeof( struct V_157 ) ) ;
#else
V_160 = F_125 ( F_126 () , struct V_157 ) ;
#endif
V_160 -> V_162 = V_198 ;
V_160 -> V_140 = V_150 ;
V_150 -> V_161 = V_160 ;
V_160 -> V_156 = TRUE ;
V_160 -> V_163 = NULL ;
V_160 -> V_164 = NULL ;
#ifdef F_127
F_110 ( 10 , L_30 , V_160 -> V_140 -> V_126 ) ;
#endif
F_2 ( V_199 , V_198 , V_160 ) ;
return V_160 ;
}
static struct V_165 *
F_142 ( struct V_135 * V_183 ,
struct V_149 * V_150 )
{
struct V_165 * V_200 = NULL ;
struct V_165 * V_184 = NULL ;
V_200 = (struct V_165 * )
F_12 ( V_185 , V_183 ) ;
if ( V_200 ) {
do {
if ( ! V_200 -> V_170 ) {
V_184 = F_130 ( V_200 ,
V_150 ) ;
break;
}
V_200 = V_200 -> V_170 ;
} while ( V_200 != NULL );
} else {
V_184 = F_139 ( V_183 ,
V_150 ) ;
}
return V_184 ;
}
static struct V_172 *
F_143 ( struct V_136 * V_186 ,
struct V_149 * V_150 )
{
struct V_172 * V_201 = NULL ;
struct V_172 * V_188 = NULL ;
V_201 = (struct V_172 * )
F_12 ( V_189 , V_186 ) ;
if ( V_201 ) {
do {
if ( ! V_201 -> V_178 ) {
V_188 = F_131 ( V_201 ,
V_150 ) ;
break;
}
V_201 = V_201 -> V_178 ;
} while ( V_201 != NULL );
} else {
V_188 = F_140 ( V_186 ,
V_150 ) ;
}
return V_188 ;
}
void
F_144 ( void )
{
if ( V_193 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_31 ) ;
#endif
F_145 ( V_193 ) ;
}
if ( V_182 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_32 ) ;
#endif
F_145 ( V_182 ) ;
}
if ( V_185 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_33 ) ;
#endif
F_145 ( V_185 ) ;
}
if ( V_189 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_34 ) ;
#endif
F_145 ( V_189 ) ;
}
if ( V_199 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_35 ) ;
#endif
F_145 ( V_199 ) ;
}
#ifdef F_127
F_110 ( 16 , L_36 ) ;
#endif
V_193 = F_146 ( F_112 , F_111 ) ;
V_182 = F_146 ( F_114 , F_113 ) ;
V_185 = F_146 ( F_116 , F_115 ) ;
V_189 = F_146 ( F_118 , F_117 ) ;
V_199 = F_146 ( F_120 , F_119 ) ;
V_202 = 1 ;
V_203 = V_204 || V_205 & V_206 ;
}
static struct V_149 *
F_147 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_150 = NULL ;
struct V_123 V_209 ;
struct V_138 * V_139 , * V_151 = NULL ;
struct V_129 V_210 ;
T_20 * V_211 ;
T_20 * V_212 = NULL ;
T_10 * V_213 = NULL ;
V_210 . V_133 = V_208 -> V_55 ;
if ( V_36 -> V_214 . type == V_215 && V_36 -> V_216 . type == V_215 )
{
V_210 . V_131 = F_148 ( ( const V_217 * ) V_36 -> V_214 . V_218 ) ;
V_210 . V_132 = F_148 ( ( const V_217 * ) V_36 -> V_216 . V_218 ) ;
} else {
V_210 . V_131 = F_149 ( F_150 ( F_151 () , & V_36 -> V_214 ) ) ;
V_210 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
}
V_210 . V_130 = F_114 ( & V_210 ) ;
#ifdef F_127
F_110 ( 10 , L_37 , V_36 -> V_142 -> V_143 ) ;
F_110 ( 11 , L_38 , V_210 . V_130 ) ;
F_110 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_214 ) , F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_40 , V_210 . V_133 ) ;
#endif
V_139 = (struct V_138 * )
F_12 ( V_182 , & V_210 ) ;
if ( V_139 ) {
do {
if ( V_36 -> V_142 -> V_143 == V_139 -> V_140 -> V_141 ) {
#ifdef F_127
F_110 ( 22 , L_41 ) ;
#endif
V_150 = V_139 -> V_140 ;
break;
}
if ( ! V_139 -> V_154 ) {
if ( ( V_139 -> V_140 -> V_144 != 0
&& V_36 -> V_142 -> V_143 > V_139 -> V_140 -> V_141
&& ( T_17 ) V_36 -> V_142 -> V_147 . V_219 > ( T_17 ) ( V_139 -> V_140 -> V_146 . V_219 + V_220 )
) ||
( V_139 -> V_140 -> V_144 == 0
&& V_36 -> V_142 -> V_143 > V_139 -> V_140 -> V_141
&& ( T_17 ) V_36 -> V_142 -> V_147 . V_219 > ( T_17 ) ( V_139 -> V_140 -> V_146 . V_219 + V_221 )
)
)
{
#ifdef F_127
F_110 ( 12 , L_42 , V_210 . V_130 ) ;
F_110 ( 12 , L_43 , V_36 -> V_142 -> V_143 , V_139 -> V_140 -> V_144 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_135 ( & V_209 , V_36 ) ;
V_151 = F_122 ( V_139 ,
V_150 ,
V_36 ) ;
#ifdef F_127
F_110 ( 12 , L_44 , V_210 . V_130 ) ;
#endif
F_121 ( V_151 , V_36 ) ;
} else {
if ( V_139 -> V_140 -> V_222 ) {
#ifdef F_127
F_110 ( 12 , L_45 , V_210 . V_130 ) ;
F_110 ( 12 , L_43 , V_36 -> V_142 -> V_143 , V_139 -> V_140 -> V_144 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_135 ( & V_209 , V_36 ) ;
V_151 = F_122 ( V_139 ,
V_150 ,
V_36 ) ;
#ifdef F_127
F_110 ( 12 , L_46 , V_210 . V_130 ) ;
#endif
F_121 ( V_151 , V_36 ) ;
} else {
#ifdef F_127
F_110 ( 21 , L_47 , V_139 -> V_140 -> V_141 ) ;
#endif
V_150 = V_139 -> V_140 ;
if ( V_203 && T_11 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_212 , L_48 ) ;
F_152 ( V_212 ) ;
V_211 = F_153 ( V_213 , V_224 , T_6 , 0 , 0 ,
V_150 -> V_141 ,
L_49 ,
V_150 -> V_126 , V_150 -> V_141 ) ;
F_152 ( V_211 ) ;
}
return V_150 ;
}
}
break;
}
V_139 = V_139 -> V_154 ;
} while ( V_139 != NULL );
} else {
#ifdef F_127
F_110 ( 10 , L_50 , V_210 . V_130 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_135 ( & V_209 , V_36 ) ;
V_139 = F_138 ( & V_210 , V_150 ) ;
#ifdef F_127
F_110 ( 11 , L_44 , V_210 . V_130 ) ;
F_110 ( 11 , L_51 , V_36 -> V_142 -> V_143 ) ;
#endif
F_121 ( V_139 , V_36 ) ;
}
if ( V_203 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , 0 , V_223 , & V_212 , L_48 ) ;
F_152 ( V_212 ) ;
V_211 = F_154 ( V_213 , V_225 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_152 ( V_211 ) ;
if( V_150 -> V_144 != 0 ) {
#ifdef F_127
F_110 ( 20 , L_52 , V_150 -> V_144 ) ;
#endif
V_211 = F_153 ( V_213 , V_226 , T_6 , 0 , 0 ,
V_150 -> V_144 ,
L_53 ,
V_150 -> V_144 ) ;
F_152 ( V_211 ) ;
}
}
return V_150 ;
}
static struct V_149 *
F_155 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_150 = NULL ;
struct V_165 * V_184 ;
struct V_135 V_227 ;
struct V_129 V_210 ;
struct V_138 * V_139 ;
struct V_136 V_228 ;
T_20 * V_211 ;
T_20 * V_212 = NULL ;
T_10 * V_213 = NULL ;
#ifdef F_127
F_110 ( 10 , L_54 , V_36 -> V_142 -> V_143 ) ;
#endif
V_227 . V_55 = V_208 -> V_55 ;
V_227 . V_64 = V_208 -> V_64 ;
if ( V_36 -> V_214 . type == V_215 && V_36 -> V_216 . type == V_215 )
{
V_227 . V_131 = F_148 ( ( const V_217 * ) V_36 -> V_214 . V_218 ) ;
V_227 . V_132 = F_148 ( ( const V_217 * ) V_36 -> V_216 . V_218 ) ;
} else {
V_227 . V_131 = F_149 ( F_150 ( F_151 () , & V_36 -> V_214 ) ) ;
V_227 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
}
V_227 . V_130 = F_116 ( & V_227 ) ;
#ifdef F_127
F_110 ( 11 , L_55 , V_227 . V_130 ) ;
F_110 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_214 ) , F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_56 , V_227 . V_55 , V_227 . V_64 ) ;
#endif
V_184 = F_133 ( & V_227 , V_36 ) ;
if( V_184 ) {
#ifdef F_127
F_110 ( 12 , L_57 ) ;
#endif
V_150 = V_184 -> V_140 ;
} else {
#ifdef F_127
F_110 ( 12 , L_58 ) ;
#endif
V_210 . V_133 = V_208 -> V_64 ;
if ( V_36 -> V_214 . type == V_215 && V_36 -> V_216 . type == V_215 )
{
V_210 . V_131 = F_148 ( ( const V_217 * ) V_36 -> V_214 . V_218 ) ;
V_210 . V_132 = F_148 ( ( const V_217 * ) V_36 -> V_216 . V_218 ) ;
} else {
V_210 . V_131 = F_149 ( F_150 ( F_151 () , & V_36 -> V_214 ) ) ;
V_210 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
}
V_210 . V_130 = F_114 ( & V_210 ) ;
#ifdef F_127
F_110 ( 11 , L_59 , V_210 . V_130 ) ;
F_110 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_214 ) , F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_40 , V_210 . V_133 ) ;
#endif
V_139 = F_132 ( & V_210 , V_36 , FALSE ) ;
if( ! V_139 ) {
V_210 . V_133 = V_208 -> V_55 ;
V_210 . V_130 = F_114 ( & V_210 ) ;
V_139 = F_132 ( & V_210 , V_36 , FALSE ) ;
}
if( V_139 &&
! V_139 -> V_140 -> V_168 ) {
#ifdef F_127
F_110 ( 12 , L_60 ) ;
#endif
V_150 = V_139 -> V_140 ;
V_150 -> V_145 = TRUE ;
#ifdef F_127
F_110 ( 10 , L_61 , V_227 . V_130 ) ;
F_110 ( 11 , L_62 , V_36 -> V_142 -> V_143 ) ;
#endif
F_142 ( & V_227 ,
V_139 -> V_140 ) ;
V_228 . V_133 = V_208 -> V_55 ;
if ( V_36 -> V_214 . type == V_215 && V_36 -> V_216 . type == V_215 )
{
V_228 . V_131 = F_148 ( ( const V_217 * ) V_36 -> V_214 . V_218 ) ;
V_228 . V_132 = F_148 ( ( const V_217 * ) V_36 -> V_216 . V_218 ) ;
} else {
V_228 . V_131 = F_149 ( F_150 ( F_151 () , & V_36 -> V_214 ) ) ;
V_228 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
}
V_228 . V_130 = F_118 ( & V_228 ) ;
#ifdef F_127
F_110 ( 10 , L_63 , V_228 . V_130 ) ;
F_110 ( 11 , L_51 , V_36 -> V_142 -> V_143 ) ;
#endif
F_143 ( & V_228 ,
V_139 -> V_140 ) ;
} else {
#ifdef F_127
F_110 ( 12 , L_64 ) ;
#endif
}
}
if ( V_203 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_212 , L_48 ) ;
F_152 ( V_212 ) ;
V_211 = F_154 ( V_213 , V_225 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_152 ( V_211 ) ;
}
return V_150 ;
}
static struct V_149 *
F_156 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_150 = NULL ;
struct V_136 V_228 ;
struct V_172 * V_188 = NULL ;
struct V_129 V_210 ;
struct V_138 * V_139 = NULL ;
T_20 * V_211 ;
T_21 V_229 ;
T_20 * V_212 = NULL ;
T_10 * V_213 = NULL ;
#ifdef F_127
F_110 ( 10 , L_65 , V_36 -> V_142 -> V_143 ) ;
#endif
V_228 . V_133 = V_208 -> V_64 ;
if ( V_36 -> V_214 . type == V_215 && V_36 -> V_216 . type == V_215 )
{
V_228 . V_131 = F_148 ( ( const V_217 * ) V_36 -> V_214 . V_218 ) ;
V_228 . V_132 = F_148 ( ( const V_217 * ) V_36 -> V_216 . V_218 ) ;
} else {
V_228 . V_131 = F_149 ( F_150 ( F_151 () , & V_36 -> V_214 ) ) ;
V_228 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
}
V_228 . V_130 = F_118 ( & V_228 ) ;
#ifdef F_127
F_110 ( 11 , L_66 , V_228 . V_130 ) ;
F_110 ( 11 , L_39 , F_150 ( F_151 () , & V_36 -> V_214 ) , F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_67 , V_228 . V_133 ) ;
#endif
V_188 = F_134 ( & V_228 , V_36 , TRUE ) ;
if( ! V_188 ) {
#ifdef F_127
F_110 ( 12 , L_68 ) ;
#endif
V_210 . V_133 = V_208 -> V_64 ;
if ( V_36 -> V_214 . type == V_215 && V_36 -> V_216 . type == V_215 )
{
V_210 . V_131 = F_148 ( ( const V_217 * ) V_36 -> V_214 . V_218 ) ;
V_210 . V_132 = F_148 ( ( const V_217 * ) V_36 -> V_216 . V_218 ) ;
} else {
V_210 . V_131 = F_149 ( F_150 ( F_151 () , & V_36 -> V_214 ) ) ;
V_210 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
}
V_210 . V_130 = F_114 ( & V_210 ) ;
#ifdef F_127
F_110 ( 11 , L_59 , V_210 . V_130 ) ;
F_110 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_214 ) , F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_67 , V_210 . V_133 ) ;
#endif
V_139 = F_132 ( & V_210 , V_36 , FALSE ) ;
if( ! V_139 ) {
#ifdef F_127
F_110 ( 12 , L_64 ) ;
#endif
}
}
if ( V_188 ) {
V_150 = V_188 -> V_140 ;
} else if ( V_139 ) {
V_150 = V_139 -> V_140 ;
}
if ( V_150 ) {
#ifdef F_127
F_110 ( 12 , L_69 , V_150 -> V_141 ) ;
#endif
if ( V_203 && T_11 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_212 , L_48 ) ;
F_152 ( V_212 ) ;
V_211 = F_154 ( V_213 , V_225 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_152 ( V_211 ) ;
}
#ifdef F_127
F_110 ( 20 , L_70 , V_150 -> V_141 ) ;
#endif
if ( V_203 && V_213 ) {
V_211 = F_153 ( V_213 , V_230 , T_6 , 0 , 0 ,
V_150 -> V_141 ,
L_71 ,
V_150 -> V_141 ) ;
F_152 ( V_211 ) ;
F_157 ( & V_229 , & V_36 -> V_142 -> V_147 , & V_150 -> V_146 ) ;
V_211 = F_158 ( V_213 , V_231 , T_6 , 0 , 0 , & V_229 ) ;
F_152 ( V_211 ) ;
}
F_159 ( V_150 , V_36 ) ;
} else {
#ifdef F_127
F_110 ( 12 , L_72 ) ;
#endif
}
return V_150 ;
}
static struct V_149 *
F_160 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_150 = NULL ;
struct V_123 V_209 ;
struct V_157 * V_158 , * V_160 ;
struct V_137 V_232 ;
T_20 * V_211 ;
T_21 V_229 ;
T_3 V_233 = FALSE ;
T_10 * V_213 = NULL ;
T_20 * V_212 = NULL ;
V_232 . V_133 = V_208 -> V_55 ;
if ( V_36 -> V_214 . type == V_215 && V_36 -> V_216 . type == V_215 )
{
V_232 . V_131 = F_148 ( ( const V_217 * ) V_36 -> V_214 . V_218 ) ;
V_232 . V_132 = F_148 ( ( const V_217 * ) V_36 -> V_216 . V_218 ) ;
} else {
V_232 . V_131 = F_149 ( F_150 ( F_151 () , & V_36 -> V_214 ) ) ;
V_232 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
}
V_232 . V_130 = F_120 ( & V_232 ) ;
#ifdef F_127
F_110 ( 10 , L_73 , V_36 -> V_142 -> V_143 ) ;
F_110 ( 11 , L_38 , V_232 . V_130 ) ;
F_110 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_214 ) , F_150 ( F_151 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_67 , V_232 . V_133 ) ;
#endif
V_158 = (struct V_157 * )
F_12 ( V_199 , & V_232 ) ;
if ( V_158 ) {
do {
if ( V_36 -> V_142 -> V_143 == V_158 -> V_140 -> V_141 ) {
#ifdef F_127
F_110 ( 22 , L_74 ) ;
#endif
V_233 = FALSE ;
V_150 = V_158 -> V_140 ;
break;
}
if ( V_36 -> V_142 -> V_143 == V_158 -> V_140 -> V_144 ) {
#ifdef F_127
F_110 ( 22 , L_75 ) ;
#endif
V_233 = TRUE ;
V_150 = V_158 -> V_140 ;
break;
}
if ( V_36 -> V_142 -> V_143 > V_158 -> V_140 -> V_141 &&
V_158 -> V_140 -> V_144 == 0 ) {
#ifdef F_127
F_110 ( 12 , L_44 , V_232 . V_130 ) ;
#endif
V_158 -> V_140 -> V_144 = V_36 -> V_142 -> V_143 ;
V_158 -> V_140 -> V_145 = TRUE ;
V_158 -> V_140 -> V_222 = TRUE ;
V_150 = V_158 -> V_140 ;
V_233 = TRUE ;
if ( V_203 && T_11 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_212 , L_48 ) ;
F_152 ( V_212 ) ;
V_211 = F_154 ( V_213 , V_225 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_152 ( V_211 ) ;
#ifdef F_127
F_110 ( 20 , L_70 , V_150 -> V_141 ) ;
#endif
V_211 = F_153 ( V_213 , V_230 , T_6 , 0 , 0 ,
V_150 -> V_141 ,
L_71 ,
V_150 -> V_141 ) ;
F_152 ( V_211 ) ;
F_157 ( & V_229 , & V_36 -> V_142 -> V_147 , & V_150 -> V_146 ) ;
V_211 = F_158 ( V_213 , V_231 , T_6 , 0 , 0 , & V_229 ) ;
F_152 ( V_211 ) ;
}
break;
}
if ( ! V_158 -> V_163 ) {
if ( ( V_158 -> V_140 -> V_144 != 0
&& V_36 -> V_142 -> V_143 > V_158 -> V_140 -> V_141
&& ( T_17 ) V_36 -> V_142 -> V_147 . V_219 > ( T_17 ) ( V_158 -> V_140 -> V_146 . V_219 + V_220 )
) ||
( V_158 -> V_140 -> V_144 == 0
&& V_36 -> V_142 -> V_143 > V_158 -> V_140 -> V_141
&& ( T_17 ) V_36 -> V_142 -> V_147 . V_219 > ( T_17 ) ( V_158 -> V_140 -> V_146 . V_219 + V_221 )
)
)
{
#ifdef F_127
F_110 ( 12 , L_42 , V_232 . V_130 ) ;
F_110 ( 12 , L_43 , V_36 -> V_142 -> V_143 , V_158 -> V_140 -> V_144 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_135 ( & V_209 , V_36 ) ;
V_160 = F_129 ( V_158 ,
V_150 ,
V_36 ) ;
#ifdef F_127
F_110 ( 12 , L_44 , V_232 . V_130 ) ;
#endif
F_128 ( V_160 , V_36 ) ;
V_158 = V_160 ;
} else {
if ( V_158 -> V_140 -> V_222 ) {
#ifdef F_127
F_110 ( 12 , L_45 , V_232 . V_130 ) ;
F_110 ( 12 , L_43 , V_36 -> V_142 -> V_143 , V_158 -> V_140 -> V_144 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_135 ( & V_209 , V_36 ) ;
V_160 = F_129 ( V_158 ,
V_150 ,
V_36 ) ;
#ifdef F_127
F_110 ( 12 , L_46 , V_232 . V_130 ) ;
#endif
F_128 ( V_160 , V_36 ) ;
V_158 = V_160 ;
} else {
V_150 = V_158 -> V_140 ;
#ifdef F_127
F_110 ( 12 , L_69 , V_150 -> V_141 ) ;
#endif
if ( V_203 && T_11 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_212 , L_48 ) ;
F_152 ( V_212 ) ;
V_211 = F_154 ( V_213 , V_225 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_152 ( V_211 ) ;
#ifdef F_127
F_110 ( 20 , L_70 , V_150 -> V_141 ) ;
#endif
V_211 = F_153 ( V_213 , V_230 , T_6 , 0 , 0 ,
V_150 -> V_141 ,
L_71 ,
V_150 -> V_141 ) ;
F_152 ( V_211 ) ;
F_157 ( & V_229 , & V_36 -> V_142 -> V_147 , & V_150 -> V_146 ) ;
V_211 = F_158 ( V_213 , V_231 , T_6 , 0 , 0 , & V_229 ) ;
F_152 ( V_211 ) ;
}
V_150 = V_158 -> V_140 ;
}
}
break;
}
V_158 = V_158 -> V_163 ;
} while ( V_158 != NULL );
} else {
#ifdef F_127
F_110 ( 10 , L_50 , V_232 . V_130 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_135 ( & V_209 , V_36 ) ;
V_158 = F_141 ( & V_232 , V_150 ) ;
#ifdef F_127
F_110 ( 11 , L_44 , V_232 . V_130 ) ;
F_110 ( 11 , L_51 , V_36 -> V_142 -> V_143 ) ;
#endif
F_128 ( V_158 , V_36 ) ;
}
if ( V_203 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_212 , L_48 ) ;
F_152 ( V_212 ) ;
V_211 = F_154 ( V_213 , V_225 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_152 ( V_211 ) ;
}
if( V_203 && V_213 &&
V_158 -> V_140 -> V_144 != 0 ) {
if ( ! V_233 ) {
#ifdef F_127
F_110 ( 20 , L_52 , V_158 -> V_140 -> V_144 ) ;
#endif
V_211 = F_153 ( V_213 , V_226 , T_6 , 0 , 0 ,
V_158 -> V_140 -> V_144 ,
L_53 ,
V_158 -> V_140 -> V_144 ) ;
F_152 ( V_211 ) ;
} else {
#ifdef F_127
F_110 ( 20 , L_70 , V_150 -> V_141 ) ;
#endif
if ( V_203 ) {
V_211 = F_153 ( V_213 , V_230 , T_6 , 0 , 0 ,
V_150 -> V_141 ,
L_71 ,
V_150 -> V_141 ) ;
F_152 ( V_211 ) ;
F_157 ( & V_229 , & V_36 -> V_142 -> V_147 , & V_150 -> V_146 ) ;
V_211 = F_158 ( V_213 , V_231 , T_6 , 0 , 0 , & V_229 ) ;
F_152 ( V_211 ) ;
}
}
}
return V_150 ;
}
struct V_149 *
F_161 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_234 = NULL ;
if( V_36 == NULL || V_36 -> V_142 -> V_143 == 0 ) {
return NULL ;
}
switch ( V_208 -> V_58 ) {
case V_59 :
#ifdef F_127
F_110 ( 1 , L_76 ) ;
#endif
V_234 = F_147 ( T_6 , V_36 , T_11 , V_208 ) ;
break;
case V_68 :
#ifdef F_127
F_110 ( 1 , L_77 ) ;
#endif
V_234 = F_155 ( T_6 , V_36 , T_11 , V_208 ) ;
break;
case V_73 :
#ifdef F_127
F_110 ( 1 , L_78 ) ;
#endif
V_234 = F_156 ( T_6 , V_36 , T_11 , V_208 ) ;
break;
case V_65 :
#ifdef F_127
F_110 ( 1 , L_79 ) ;
#endif
V_234 = F_156 ( T_6 , V_36 , T_11 , V_208 ) ;
break;
case V_235 :
case V_236 :
#ifdef F_127
F_110 ( 1 , L_80 ) ;
#endif
V_234 = F_160 ( T_6 , V_36 , T_11 , V_208 ) ;
break;
default:
#ifdef F_127
F_110 ( 1 , L_81 , V_208 -> V_58 ) ;
#endif
break;
}
#ifdef F_127
if ( V_234 )
F_110 ( 1 , L_82 , V_234 -> V_126 ) ;
#endif
return V_234 ;
}
struct V_207 *
F_162 ( void )
{
struct V_207 * V_208 ;
V_237 ++ ;
if( V_237 == V_238 ) {
V_237 = 0 ;
}
V_208 = & V_239 [ V_237 ] ;
memset ( V_208 , 0 , sizeof( struct V_207 ) ) ;
return V_208 ;
}
void
F_159 ( struct V_149 * V_150 ,
T_16 * V_36 )
{
#ifdef F_127
F_110 ( 60 , L_83 ) ;
#endif
if ( V_150 ) {
V_150 -> V_145 = TRUE ;
V_150 -> V_144 = V_36 -> V_142 -> V_143 ;
V_150 -> V_240 = V_36 -> V_142 -> V_147 ;
V_150 -> V_222 = TRUE ;
if ( V_150 -> V_176
&& ! V_204 ) {
if ( V_150 -> V_176 -> V_178 ) {
if ( V_150 -> V_176 -> V_179 ) {
#ifdef F_127
F_110 ( 20 , L_84 ) ;
#endif
V_150 -> V_176 -> V_179 -> V_178
= V_150 -> V_176 -> V_178 ;
V_150 -> V_176 -> V_178 -> V_179
= V_150 -> V_176 -> V_179 ;
F_7 ( V_189 , V_150 -> V_176 -> V_177 ) ;
#ifdef F_123
F_163 ( V_150 -> V_176 ) ;
#endif
} else {
#ifdef F_127
F_110 ( 20 , L_85 ) ;
#endif
}
} else if ( ! V_204 ) {
#ifdef F_127
F_110 ( 20 , L_86 ) ;
#endif
F_7 ( V_189 , V_150 -> V_176 -> V_177 ) ;
#ifdef F_123
F_163 ( V_150 -> V_176 -> V_177 ) ;
F_163 ( V_150 -> V_176 ) ;
#endif
}
}
if ( V_150 -> V_168
&& ! V_204 ) {
if ( V_150 -> V_168 -> V_170 ) {
if ( V_150 -> V_168 -> V_171 ) {
#ifdef F_127
F_110 ( 20 , L_87 ) ;
#endif
V_150 -> V_168 -> V_171 -> V_170
= V_150 -> V_168 -> V_170 ;
V_150 -> V_168 -> V_170 -> V_171
= V_150 -> V_168 -> V_171 ;
F_7 ( V_185 , V_150 -> V_168 -> V_169 ) ;
#ifdef F_123
F_163 ( V_150 -> V_168 ) ;
#endif
} else {
#ifdef F_127
F_110 ( 20 , L_88 ) ;
#endif
}
} else if ( ! V_204 ) {
#ifdef F_127
F_110 ( 20 , L_89 ) ;
#endif
F_7 ( V_185 , V_150 -> V_168 -> V_169 ) ;
#ifdef F_123
F_163 ( V_150 -> V_168 -> V_169 ) ;
F_163 ( V_150 -> V_168 ) ;
#endif
}
}
if ( V_150 -> V_152
&& ! V_204 ) {
if ( V_150 -> V_152 -> V_154 ) {
if ( V_150 -> V_152 -> V_155 ) {
#ifdef F_127
F_110 ( 20 , L_90 ) ;
#endif
V_150 -> V_152 -> V_155 -> V_154
= V_150 -> V_152 -> V_154 ;
V_150 -> V_152 -> V_154 -> V_155
= V_150 -> V_152 -> V_155 ;
F_7 ( V_182 , V_150 -> V_152 -> V_153 ) ;
#ifdef F_123
F_163 ( V_150 -> V_152 ) ;
#endif
} else {
#ifdef F_127
F_110 ( 20 , L_91 ) ;
#endif
}
} else if ( ! V_204 ) {
#ifdef F_127
F_110 ( 20 , L_92 ) ;
#endif
F_7 ( V_182 , V_150 -> V_152 -> V_153 ) ;
#ifdef F_123
F_163 ( V_150 -> V_152 -> V_153 ) ;
F_163 ( V_150 -> V_152 ) ;
#endif
}
}
if ( V_150 -> V_161
&& ! V_204 ) {
if ( V_150 -> V_161 -> V_163 ) {
if ( V_150 -> V_161 -> V_164 ) {
#ifdef F_127
F_110 ( 20 , L_93 ) ;
#endif
V_150 -> V_161 -> V_164 -> V_163
= V_150 -> V_161 -> V_163 ;
V_150 -> V_161 -> V_163 -> V_164
= V_150 -> V_161 -> V_164 ;
F_7 ( V_199 , V_150 -> V_161 -> V_162 ) ;
#ifdef F_123
F_163 ( V_150 -> V_161 ) ;
#endif
} else {
#ifdef F_127
F_110 ( 20 , L_94 ) ;
#endif
}
} else if ( ! V_204 ) {
#ifdef F_127
F_110 ( 20 , L_95 ) ;
#endif
F_7 ( V_199 , V_150 -> V_161 -> V_162 ) ;
#ifdef F_123
F_163 ( V_150 -> V_161 -> V_162 ) ;
F_163 ( V_150 -> V_161 ) ;
#endif
}
}
if ( ! V_204 ) {
#ifdef F_127
F_110 ( 20 , L_96 ) ;
#endif
F_7 ( V_193 , V_150 -> V_128 ) ;
#ifdef F_123
F_163 ( V_150 -> V_128 ) ;
F_163 ( V_150 ) ;
#endif
}
} else {
#ifdef F_127
F_110 ( 20 , L_97 ) ;
#endif
}
}
static void
F_164 ( T_5 * T_6 , T_16 * V_36 , T_10 * V_241 )
{
T_20 * V_242 = NULL ;
T_10 * T_11 = NULL ;
struct V_149 * V_243 ;
T_2 V_244 ;
T_8 V_112 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
F_165 ( T_6 , 0 , & V_30 , & V_31 , & V_32 ) ;
if( V_30 == V_245 ) {
switch ( V_32 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
F_166 ( V_246 , T_6 , V_36 , V_241 ) ;
return;
break;
default:
return;
}
}
F_108 ( & V_112 , V_113 , TRUE , V_36 ) ;
V_42 = V_241 ;
V_247 = NULL ;
F_69 ( V_36 -> V_56 , V_248 , L_98 ) ;
if( V_241 ) {
V_242 = F_167 ( V_241 , V_249 , T_6 , 0 , - 1 , V_250 ) ;
T_11 = F_168 ( V_242 , V_251 ) ;
V_247 = T_11 ;
}
V_82 = NULL ;
V_252 = NULL ;
F_169 ( & V_83 ) ;
V_112 . V_253 = & V_83 ;
V_54 = F_162 () ;
V_254 = FALSE ;
V_255 = NULL ;
F_77 ( FALSE , T_6 , 0 , & V_112 , T_11 , - 1 ) ;
if ( V_205 && ! V_254 ) {
V_243 = F_161 ( T_6 , V_36 , V_247 , V_54 ) ;
V_83 . V_140 = V_243 ;
if ( V_243 && V_82 && ! V_243 -> V_256 ) {
F_170 ( V_243 -> V_84 , V_82 , sizeof( V_243 -> V_84 ) ) ;
V_243 -> V_256 = TRUE ;
if ( ( V_244 = F_171 ( V_257 , V_82 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
}
}
if ( V_205 && V_243 && V_243 -> V_259 ) {
( V_243 -> V_259 ) ( T_6 , V_36 , V_247 , V_243 ) ;
}
}
}
void
F_172 ( void )
{
V_260 = F_173 ( L_99 ) ;
V_246 = F_173 ( L_100 ) ;
V_257 = F_174 ( L_101 ) ;
#line 1 "../../asn1/tcap/packet-tcap-dis-tab.c"
F_175 ( L_102 , F_109 , V_249 , L_103 ) ;
F_175 ( L_104 , F_107 , V_249 , L_105 ) ;
#line 2073 "../../asn1/tcap/packet-tcap-template.c"
}
void
F_176 ( void )
{
static T_22 V_261 [] = {
{ & V_262 ,
{ L_106 ,
L_107 ,
V_263 , V_264 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_266 ,
{ L_108 ,
L_109 ,
V_263 , V_267 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_268 ,
{ L_110 ,
L_111 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_51 ,
{ L_112 ,
L_113 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_271 ,
{ L_114 ,
L_115 ,
V_272 , V_264 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_225 ,
{ L_116 ,
L_117 ,
V_273 , V_267 , NULL , 0x0 ,
NULL , V_265 }
} ,
{ & V_226 ,
{ L_118 ,
L_119 ,
V_274 , V_270 , NULL , 0x0 ,
L_120 , V_265 }
} ,
{ & V_230 ,
{ L_121 ,
L_122 ,
V_274 , V_270 , NULL , 0x0 ,
L_123 , V_265 }
} ,
{ & V_231 ,
{ L_124 ,
L_125 ,
V_275 , V_270 , NULL , 0x0 ,
L_126 , V_265 }
} ,
{ & V_224 ,
{ L_127 ,
L_128 ,
V_274 , V_270 , NULL , 0x0 ,
L_129 , V_265 }
} ,
#line 1 "../../asn1/tcap/packet-tcap-hfarr.c"
{ & V_114 ,
{ L_130 , L_131 ,
V_273 , V_267 , F_177 ( V_276 ) , 0 ,
NULL , V_265 } } ,
{ & V_115 ,
{ L_132 , L_133 ,
V_273 , V_267 , F_177 ( V_277 ) , 0 ,
NULL , V_265 } } ,
{ & V_278 ,
{ L_134 , L_135 ,
V_279 , V_270 , NULL , 0 ,
L_136 , V_265 } } ,
{ & V_280 ,
{ L_137 , L_138 ,
V_269 , V_270 , NULL , 0 ,
L_139 , V_265 } } ,
{ & V_281 ,
{ L_140 , L_141 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_283 ,
{ L_142 , L_143 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_284 ,
{ L_144 , L_145 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_285 ,
{ L_146 , L_147 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_286 ,
{ L_148 , L_149 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_287 ,
{ L_150 , L_151 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_288 ,
{ L_152 , L_153 ,
V_273 , V_267 , NULL , 0 ,
L_154 , V_265 } } ,
{ & V_53 ,
{ L_155 , L_156 ,
V_269 , V_270 , NULL , 0 ,
L_157 , V_265 } } ,
{ & V_63 ,
{ L_158 , L_159 ,
V_269 , V_270 , NULL , 0 ,
L_160 , V_265 } } ,
{ & V_289 ,
{ L_161 , L_162 ,
V_273 , V_267 , F_177 ( V_290 ) , 0 ,
NULL , V_265 } } ,
{ & V_291 ,
{ L_163 , L_164 ,
V_273 , V_267 , F_177 ( V_292 ) , 0 ,
NULL , V_265 } } ,
{ & V_293 ,
{ L_165 , L_166 ,
V_269 , V_270 , NULL , 0 ,
L_167 , V_265 } } ,
{ & V_294 ,
{ L_168 , L_169 ,
V_273 , V_267 , F_177 ( V_295 ) , 0 ,
NULL , V_265 } } ,
{ & V_296 ,
{ L_170 , L_171 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_297 ,
{ L_172 , L_173 ,
V_282 , V_270 , NULL , 0 ,
L_174 , V_265 } } ,
{ & V_298 ,
{ L_175 , L_176 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_299 ,
{ L_177 , L_178 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_300 ,
{ L_179 , L_180 ,
V_282 , V_270 , NULL , 0 ,
L_174 , V_265 } } ,
{ & V_301 ,
{ L_181 , L_182 ,
V_302 , V_267 , NULL , 0 ,
L_183 , V_265 } } ,
{ & V_303 ,
{ L_184 , L_185 ,
V_302 , V_267 , NULL , 0 ,
L_183 , V_265 } } ,
{ & V_304 ,
{ L_186 , L_187 ,
V_273 , V_267 , F_177 ( V_305 ) , 0 ,
L_188 , V_265 } } ,
{ & V_306 ,
{ L_189 , L_190 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_307 ,
{ L_191 , L_192 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_308 ,
{ L_193 , L_194 ,
V_273 , V_267 , F_177 ( V_309 ) , 0 ,
NULL , V_265 } } ,
{ & V_310 ,
{ L_195 , L_196 ,
V_273 , V_267 , F_177 ( V_311 ) , 0 ,
NULL , V_265 } } ,
{ & V_312 ,
{ L_197 , L_198 ,
V_302 , V_267 , NULL , 0 ,
L_183 , V_265 } } ,
{ & V_313 ,
{ L_199 , L_200 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_314 ,
{ L_201 , L_202 ,
V_273 , V_267 , F_177 ( V_315 ) , 0 ,
NULL , V_265 } } ,
{ & V_316 ,
{ L_203 , L_204 ,
V_302 , V_267 , F_177 ( V_317 ) , 0 ,
NULL , V_265 } } ,
{ & V_318 ,
{ L_205 , L_206 ,
V_302 , V_267 , F_177 ( V_319 ) , 0 ,
NULL , V_265 } } ,
{ & V_320 ,
{ L_207 , L_208 ,
V_302 , V_267 , F_177 ( V_321 ) , 0 ,
NULL , V_265 } } ,
{ & V_322 ,
{ L_209 , L_210 ,
V_302 , V_267 , F_177 ( V_323 ) , 0 ,
NULL , V_265 } } ,
{ & V_324 ,
{ L_211 , L_212 ,
V_302 , V_267 , NULL , 0 ,
L_213 , V_265 } } ,
{ & V_325 ,
{ L_214 , L_215 ,
V_279 , V_270 , NULL , 0 ,
L_136 , V_265 } } ,
{ & V_326 ,
{ L_216 , L_217 ,
V_302 , V_267 , NULL , 0 ,
L_218 , V_265 } } ,
{ & V_327 ,
{ L_219 , L_220 ,
V_302 , V_267 , NULL , 0 ,
L_213 , V_265 } } ,
{ & V_328 ,
{ L_221 , L_222 ,
V_282 , V_270 , NULL , 0 ,
L_223 , V_265 } } ,
{ & V_329 ,
{ L_224 , L_225 ,
V_269 , V_270 , NULL , 0 ,
L_226 , V_265 } } ,
{ & V_330 ,
{ L_227 , L_228 ,
V_279 , V_270 , NULL , 0 ,
L_229 , V_265 } } ,
{ & V_331 ,
{ L_230 , L_231 ,
V_273 , V_267 , NULL , 0 ,
L_232 , V_265 } } ,
{ & V_332 ,
{ L_233 , L_234 ,
V_282 , V_270 , NULL , 0 ,
L_235 , V_265 } } ,
{ & V_333 ,
{ L_236 , L_237 ,
V_282 , V_270 , NULL , 0 ,
L_238 , V_265 } } ,
{ & V_334 ,
{ L_239 , L_240 ,
V_282 , V_270 , NULL , 0 ,
L_241 , V_265 } } ,
{ & V_335 ,
{ L_242 , L_243 ,
V_282 , V_270 , NULL , 0 ,
L_244 , V_265 } } ,
{ & V_336 ,
{ L_224 , L_225 ,
V_269 , V_270 , NULL , 0 ,
L_245 , V_265 } } ,
{ & V_337 ,
{ L_227 , L_228 ,
V_279 , V_270 , NULL , 0 ,
L_246 , V_265 } } ,
{ & V_338 ,
{ L_230 , L_231 ,
V_273 , V_267 , NULL , 0 ,
L_247 , V_265 } } ,
{ & V_339 ,
{ L_233 , L_234 ,
V_282 , V_270 , NULL , 0 ,
L_235 , V_265 } } ,
{ & V_340 ,
{ L_224 , L_225 ,
V_269 , V_270 , NULL , 0 ,
L_248 , V_265 } } ,
{ & V_341 ,
{ L_227 , L_228 ,
V_279 , V_270 , NULL , 0 ,
L_249 , V_265 } } ,
{ & V_342 ,
{ L_250 , L_251 ,
V_302 , V_267 , F_177 ( V_343 ) , 0 ,
L_252 , V_265 } } ,
{ & V_344 ,
{ L_253 , L_254 ,
V_273 , V_267 , F_177 ( V_345 ) , 0 ,
L_255 , V_265 } } ,
{ & V_346 ,
{ L_230 , L_231 ,
V_273 , V_267 , NULL , 0 ,
L_256 , V_265 } } ,
{ & V_347 ,
{ L_233 , L_234 ,
V_282 , V_270 , NULL , 0 ,
L_235 , V_265 } } ,
{ & V_348 ,
{ L_257 , L_258 ,
V_302 , V_267 , F_177 ( V_349 ) , 0 ,
L_259 , V_265 } } ,
{ & V_350 ,
{ L_230 , L_231 ,
V_273 , V_267 , NULL , 0 ,
L_260 , V_265 } } ,
{ & V_351 ,
{ L_233 , L_234 ,
V_282 , V_270 , NULL , 0 ,
L_235 , V_265 } } ,
{ & V_352 ,
{ L_261 , L_262 ,
V_302 , V_267 , F_177 ( V_353 ) , 0 ,
NULL , V_265 } } ,
{ & V_354 ,
{ L_263 , L_264 ,
V_302 , V_267 , F_177 ( V_355 ) , 0 ,
NULL , V_265 } } ,
{ & V_356 ,
{ L_265 , L_266 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
{ & V_358 ,
{ L_265 , L_266 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
{ & V_359 ,
{ L_265 , L_266 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
#line 2145 "../../asn1/tcap/packet-tcap-template.c"
} ;
static T_14 * V_360 [] = {
& V_251 ,
& V_361 ,
& V_50 ,
& V_62 ,
& V_223 ,
#line 1 "../../asn1/tcap/packet-tcap-ettarr.c"
& V_8 ,
& V_77 ,
& V_46 ,
& V_61 ,
& V_67 ,
& V_70 ,
& V_75 ,
& V_72 ,
& V_44 ,
& V_38 ,
& V_14 ,
& V_18 ,
& V_16 ,
& V_22 ,
& V_28 ,
& V_24 ,
& V_26 ,
& V_12 ,
& V_79 ,
& V_20 ,
& V_91 ,
& V_89 ,
& V_81 ,
& V_87 ,
& V_111 ,
& V_97 ,
& V_93 ,
& V_95 ,
& V_105 ,
& V_99 ,
& V_103 ,
& V_109 ,
& V_107 ,
& V_101 ,
#line 2155 "../../asn1/tcap/packet-tcap-template.c"
} ;
T_23 * V_362 ;
V_249 = F_178 ( V_363 , V_364 , V_365 ) ;
F_179 ( V_249 , V_261 , F_180 ( V_261 ) ) ;
F_181 ( V_360 , F_180 ( V_360 ) ) ;
V_362 = F_182 ( V_249 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_183 ( V_362 , L_267 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_183 ( V_362 , L_268 ) ;
#endif
F_184 ( & V_366 , L_269 , V_367 ) ;
V_368 = F_185 () ;
F_186 ( V_362 , L_270 , L_271 ,
L_272 ,
& V_366 , V_367 ) ;
F_187 ( V_362 , L_273 ,
L_274 ,
L_275 ,
& V_205 ) ;
F_187 ( V_362 , L_276 ,
L_277 ,
L_278 ,
& V_204 ) ;
F_188 ( V_362 , L_279 ,
L_280 ,
L_281 ,
10 , & V_220 ) ;
F_188 ( V_362 , L_282 ,
L_283 ,
L_284 ,
10 , & V_221 ) ;
V_3 = F_146 ( V_369 , V_370 ) ;
V_5 = F_146 ( V_369 , V_370 ) ;
F_189 ( L_285 , F_164 , V_249 ) ;
V_4 = F_190 ( F_164 , V_249 ) ;
F_191 ( & V_371 ) ;
}
static void F_192 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_193 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_371 ( void )
{
if ( V_368 ) {
F_194 ( V_368 , F_192 ) ;
F_163 ( V_368 ) ;
}
V_368 = F_195 ( V_366 ) ;
F_194 ( V_368 , F_193 ) ;
F_144 () ;
}
static int
F_29 ( T_8 * T_9 , T_10 * T_11 , T_5 * T_6 , int T_7 )
{
T_14 V_372 , V_373 , V_374 ;
T_5 * V_29 ;
T_10 * V_49 ;
T_13 V_30 ;
T_3 V_31 ;
T_24 V_32 ;
T_1 V_33 ;
T_1 V_375 ;
T_1 V_376 ;
T_3 V_35 ;
while ( F_196 ( T_6 , T_7 ) > 0 )
{
V_373 = T_7 ;
T_7 = F_165 ( T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_372 = T_7 ;
T_7 = F_197 ( T_6 , T_7 , & V_33 , & V_35 ) ;
V_374 = T_7 ;
V_375 = V_372 - V_373 ;
V_376 = V_374 - V_372 ;
if ( V_31 )
{
V_49 = F_60 ( T_11 , T_6 , V_373 ,
V_33 + ( V_374 - V_373 ) , V_361 , NULL ,
L_286 ) ;
F_153 ( V_49 , V_262 , T_6 ,
V_373 , V_375 , V_32 ,
L_287 ) ;
F_154 ( V_49 , V_262 , T_6 , V_373 ,
V_375 , V_30 ) ;
F_154 ( V_49 , V_266 , T_6 , V_372 ,
V_376 , V_33 ) ;
if ( V_33 - ( 2 * V_35 ) )
{
V_29 = F_48 ( T_6 , T_7 , V_33 - ( 2 * V_35 ) ) ;
F_29 ( T_9 , V_49 , V_29 , 0 ) ;
}
if ( V_35 )
F_167 ( V_49 , V_271 , T_6 , T_7 + V_33 - 2 , 2 , V_377 ) ;
T_7 += V_33 ;
}
else
{
V_49 = F_198 ( T_11 , T_6 , V_373 ,
V_33 + ( V_374 - V_373 ) , V_361 , NULL ,
L_288 , V_32 ) ;
F_154 ( V_49 , V_262 , T_6 , V_373 ,
V_375 , V_32 ) ;
F_154 ( V_49 , V_266 , T_6 ,
V_373 + V_375 , V_376 , V_33 ) ;
if ( V_33 )
{
V_29 = F_48 ( T_6 , T_7 , V_33 ) ;
F_58 ( TRUE , T_9 , T_11 , V_29 , 0 ,
V_268 , NULL ) ;
}
T_7 += V_33 ;
}
}
return T_7 ;
}
static void F_169 ( struct V_378 * V_379 )
{
memset ( V_379 , 0 , sizeof( struct V_378 ) ) ;
}
static int
F_52 ( T_3 T_4 V_6 , T_5 * T_6 , int T_7 , T_8 * T_9 V_6 , T_10 * T_11 , int T_12 V_6 )
{
T_2 V_244 = NULL ;
T_3 V_380 = FALSE ;
struct V_149 * V_243 = NULL ;
if ( V_205 ) {
if ( ! V_254 ) {
V_243 = F_161 ( T_6 , T_9 -> V_36 , V_247 , V_54 ) ;
V_254 = TRUE ;
V_255 = V_243 ;
V_83 . V_140 = V_243 ;
} else {
V_243 = V_255 ;
V_83 . V_140 = V_243 ;
}
}
if ( V_243 ) {
if ( V_82 ) {
if ( V_243 -> V_256 ) {
if ( strncmp ( V_243 -> V_84 , V_82 , sizeof( V_243 -> V_84 ) ) != 0 ) {
F_170 ( V_243 -> V_84 , V_82 , sizeof( V_243 -> V_84 ) ) ;
if ( ( V_244 = F_171 ( V_257 , V_82 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
}
}
} else {
F_170 ( V_243 -> V_84 , V_82 , sizeof( V_243 -> V_84 ) ) ;
V_243 -> V_256 = TRUE ;
if ( ( V_244
= F_171 ( V_257 , V_82 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
} else {
if ( ( V_244 = F_8 ( T_9 -> V_36 -> V_381 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
}
}
}
} else {
if ( V_243 -> V_256 ) {
V_83 . V_84 = ( void * ) V_243 -> V_84 ;
V_83 . V_85 = TRUE ;
}
}
}
if ( V_243
&& V_243 -> V_258 ) {
V_244 = V_243 -> V_244 ;
V_380 = TRUE ;
}
if ( ! V_380 && V_382 ) {
V_380 = TRUE ;
V_244 = V_382 ;
}
if ( ! V_380 ) {
if ( V_257 && V_82 ) {
if ( ( V_244
= F_171 ( V_257 , V_82 ) ) ) {
V_380 = TRUE ;
} else {
if ( ( V_244
= F_8 ( T_9 -> V_36 -> V_381 ) ) ) {
V_380 = TRUE ;
} else {
V_244 = V_260 ;
V_380 = TRUE ;
}
}
} else {
if ( ( V_244 = F_8 ( T_9 -> V_36 -> V_381 ) ) ) {
V_380 = TRUE ;
} else {
V_244 = V_260 ;
V_380 = TRUE ;
}
}
} else {
}
if ( V_380 ) {
F_199 ( V_244 , T_6 , T_9 -> V_36 , T_11 , T_9 -> V_253 ) ;
F_200 ( T_9 -> V_36 -> V_56 , V_57 ) ;
}
return T_7 ;
}
void
F_201 ( T_2 V_383 , T_5 * T_6 , T_16 * V_36 , T_10 * T_11 )
{
V_382 = V_383 ;
F_49 {
F_164 ( T_6 , V_36 , T_11 ) ;
} F_202 {
V_382 = NULL ;
V_384 ;
} V_41 ;
V_382 = NULL ;
}
