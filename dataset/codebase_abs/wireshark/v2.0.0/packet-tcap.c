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
static int F_107 ( T_5 * T_6 V_6 , T_16 * V_36 V_6 , T_10 * T_11 V_6 , void * T_17 V_6 ) {
int T_7 = 0 ;
T_8 V_112 ;
F_108 ( & V_112 , V_113 , TRUE , V_36 ) ;
T_7 = F_88 ( FALSE , T_6 , T_7 , & V_112 , T_11 , V_114 ) ;
return T_7 ;
}
static int F_109 ( T_5 * T_6 V_6 , T_16 * V_36 V_6 , T_10 * T_11 V_6 , void * T_17 V_6 ) {
int T_7 = 0 ;
T_8 V_112 ;
F_108 ( & V_112 , V_113 , TRUE , V_36 ) ;
T_7 = F_16 ( FALSE , T_6 , T_7 , & V_112 , T_11 , V_115 ) ;
return T_7 ;
}
static void
F_110 ( T_18 V_116 , const char * V_117 , ... )
{
T_19 V_118 ;
if ( V_116 > V_119 ) return;
va_start ( V_118 , V_117 ) ;
vfprintf ( V_120 , V_117 , V_118 ) ;
va_end ( V_118 ) ;
}
static T_14
F_111 ( T_20 V_121 , T_20 V_122 )
{
const struct V_123 * V_124 = ( const struct V_123 * ) V_121 ;
const struct V_123 * V_125 = ( const struct V_123 * ) V_122 ;
return ( V_124 -> V_126 == V_125 -> V_126 ) ;
}
static T_18
F_112 ( T_20 V_127 )
{
const struct V_123 * V_128 = ( const struct V_123 * ) V_127 ;
return V_128 -> V_126 ;
}
static T_14
F_113 ( T_20 V_121 , T_20 V_122 )
{
const struct V_129 * V_124 = ( const struct V_129 * ) V_121 ;
const struct V_129 * V_125 = ( const struct V_129 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( V_124 -> V_131 == V_125 -> V_131 ) && ( V_124 -> V_132 == V_125 -> V_132 ) )
return TRUE ;
}
return FALSE ;
}
static T_18
F_114 ( T_20 V_127 )
{
const struct V_129 * V_128 = ( const struct V_129 * ) V_127 ;
T_18 V_133 ;
V_133 = V_128 -> V_132 ;
return V_133 ;
}
static T_14
F_115 ( T_20 V_121 , T_20 V_122 )
{
const struct V_134 * V_124 = ( const struct V_134 * ) V_121 ;
const struct V_134 * V_125 = ( const struct V_134 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( V_124 -> V_135 == V_125 -> V_135 ) &&
( V_124 -> V_136 == V_125 -> V_136 ) &&
( V_124 -> V_55 == V_125 -> V_55 ) &&
( V_124 -> V_64 == V_125 -> V_64 ) ) {
return TRUE ;
}
else if ( ( V_124 -> V_135 == V_125 -> V_136 ) &&
( V_124 -> V_136 == V_125 -> V_135 ) &&
( V_124 -> V_55 == V_125 -> V_64 ) &&
( V_124 -> V_64 == V_125 -> V_55 ) ) {
return TRUE ;
}
}
return FALSE ;
}
static T_18
F_116 ( T_20 V_127 )
{
const struct V_134 * V_128 = ( const struct V_134 * ) V_127 ;
T_18 V_133 ;
V_133 = V_128 -> V_55 + V_128 -> V_64 ;
return V_133 ;
}
static T_14
F_117 ( T_20 V_121 , T_20 V_122 )
{
const struct V_137 * V_124 = ( const struct V_137 * ) V_121 ;
const struct V_137 * V_125 = ( const struct V_137 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( V_124 -> V_131 == V_125 -> V_131 ) && ( V_124 -> V_132 == V_125 -> V_132 ) )
return TRUE ;
}
return FALSE ;
}
static T_18
F_118 ( T_20 V_127 )
{
const struct V_137 * V_128 = ( const struct V_137 * ) V_127 ;
T_18 V_133 ;
V_133 = V_128 -> V_132 ;
return V_133 ;
}
static T_14
F_119 ( T_20 V_121 , T_20 V_122 )
{
const struct V_138 * V_124 = ( const struct V_138 * ) V_121 ;
const struct V_138 * V_125 = ( const struct V_138 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( ( V_124 -> V_135 == V_125 -> V_135 ) &&
( V_124 -> V_136 == V_125 -> V_136 ) &&
( V_124 -> V_132 == V_125 -> V_132 ) )
||
( ( V_124 -> V_135 == V_125 -> V_136 ) &&
( V_124 -> V_136 == V_125 -> V_135 ) &&
( V_124 -> V_132 == V_125 -> V_132 ) )
)
return TRUE ;
}
return FALSE ;
}
static T_18
F_120 ( T_20 V_127 )
{
const struct V_138 * V_128 = ( const struct V_138 * ) V_127 ;
T_18 V_133 ;
V_133 = V_128 -> V_132 ;
return V_133 ;
}
static void
F_121 ( struct V_139 * V_140 ,
T_16 * V_36 )
{
V_140 -> V_141 -> V_142 = V_36 -> V_143 -> V_144 ;
V_140 -> V_141 -> V_145 = 0 ;
V_140 -> V_141 -> V_146 = FALSE ;
V_140 -> V_141 -> V_147 = V_36 -> V_143 -> V_148 ;
}
static struct V_139 *
F_122 ( struct V_139 * V_149 ,
struct V_150 * V_151 ,
T_16 * V_36 )
{
struct V_139 * V_152 = NULL ;
#ifdef F_123
V_152 = (struct V_139 * ) F_124 ( sizeof( struct V_139 ) ) ;
#else
V_152 = F_125 ( F_126 () , struct V_139 ) ;
#endif
V_152 -> V_141 = V_151 ;
V_151 -> V_153 = V_152 ;
V_152 -> V_154 = V_149 -> V_154 ;
V_152 -> V_141 -> V_142 = V_36 -> V_143 -> V_144 ;
V_152 -> V_155 = NULL ;
V_152 -> V_156 = V_149 ;
V_152 -> V_157 = FALSE ;
#ifdef F_127
F_110 ( 10 , L_12 , V_152 -> V_141 -> V_126 ) ;
#endif
V_149 -> V_155 = V_152 ;
if ( V_149 -> V_141 -> V_145 == 0 ) {
#ifdef F_127
F_110 ( 10 , L_13 ) ;
#endif
V_149 -> V_141 -> V_145 = V_36 -> V_143 -> V_144 - 1 ;
}
return V_152 ;
}
static void
F_128 ( struct V_158 * V_159 ,
T_16 * V_36 )
{
V_159 -> V_141 -> V_142 = V_36 -> V_143 -> V_144 ;
V_159 -> V_141 -> V_145 = 0 ;
V_159 -> V_141 -> V_146 = FALSE ;
V_159 -> V_141 -> V_147 = V_36 -> V_143 -> V_148 ;
}
static struct V_158 *
F_129 ( struct V_158 * V_160 ,
struct V_150 * V_151 ,
T_16 * V_36 )
{
struct V_158 * V_161 = NULL ;
#ifdef F_123
V_161 = (struct V_158 * ) F_124 ( sizeof( struct V_158 ) ) ;
#else
V_161 = F_125 ( F_126 () , struct V_158 ) ;
#endif
V_161 -> V_141 = V_151 ;
V_151 -> V_162 = V_161 ;
V_161 -> V_163 = V_160 -> V_163 ;
V_161 -> V_141 -> V_142 = V_36 -> V_143 -> V_144 ;
V_161 -> V_164 = NULL ;
V_161 -> V_165 = V_160 ;
V_161 -> V_157 = FALSE ;
#ifdef F_127
F_110 ( 10 , L_14 , V_161 -> V_141 -> V_126 ) ;
#endif
V_160 -> V_164 = V_161 ;
if ( V_160 -> V_141 -> V_145 == 0 ) {
#ifdef F_127
F_110 ( 10 , L_13 ) ;
#endif
V_160 -> V_141 -> V_145 = V_36 -> V_143 -> V_144 - 1 ;
}
return V_161 ;
}
static struct V_166 *
F_130 ( struct V_166 * V_167 ,
struct V_150 * V_151 )
{
struct V_166 * V_168 = NULL ;
#ifdef F_123
V_168 = (struct V_166 * ) F_124 ( sizeof( struct V_166 ) ) ;
#else
V_168 = F_125 ( F_126 () , struct V_166 ) ;
#endif
V_168 -> V_141 = V_151 ;
V_151 -> V_169 = V_168 ;
V_168 -> V_170 = V_167 -> V_170 ;
V_168 -> V_171 = NULL ;
V_168 -> V_172 = V_167 ;
V_168 -> V_157 = FALSE ;
#ifdef F_127
F_110 ( 10 , L_15 , V_168 -> V_141 -> V_126 ) ;
#endif
V_167 -> V_171 = V_168 ;
return V_168 ;
}
static struct V_173 *
F_131 ( struct V_173 * V_174 ,
struct V_150 * V_151 )
{
struct V_173 * V_175 = NULL ;
#ifdef F_123
V_175 = (struct V_176 * ) F_124 ( sizeof( struct V_173 ) ) ;
#else
V_175 = F_125 ( F_126 () , struct V_173 ) ;
#endif
V_175 -> V_141 = V_151 ;
V_151 -> V_177 = V_175 ;
V_175 -> V_178 = V_174 -> V_178 ;
V_175 -> V_179 = NULL ;
V_175 -> V_180 = V_174 ;
V_175 -> V_157 = FALSE ;
#ifdef F_127
F_110 ( 10 , L_16 , V_175 -> V_141 -> V_126 ) ;
#endif
V_174 -> V_179 = V_175 ;
return V_175 ;
}
static struct V_139 *
F_132 ( struct V_129 * V_181 ,
T_16 * V_36 , T_3 V_182 )
{
struct V_139 * V_140 = NULL ;
V_140 = (struct V_139 * ) F_12 ( V_183 , V_181 ) ;
if( V_140 ) {
do {
if ( V_140 -> V_141 ) {
if ( ( V_182 &&
V_36 -> V_143 -> V_144 == V_140 -> V_141 -> V_142 )
||
( ! V_182 &&
V_36 -> V_143 -> V_144 >= V_140 -> V_141 -> V_142 &&
( V_140 -> V_141 -> V_145 ? V_36 -> V_143 -> V_144 <= V_140 -> V_141 -> V_145 : 1 )
)
) {
#ifdef F_127
F_110 ( 10 , L_17 , V_140 -> V_141 -> V_126 ) ;
#endif
return V_140 ;
}
#ifdef F_127
F_110 ( 60 , L_18 , V_140 -> V_141 -> V_126 ) ;
#endif
}
if( V_140 -> V_155 == NULL ) {
#ifdef F_127
F_110 ( 23 , L_19 ) ;
#endif
break;
}
V_140 = V_140 -> V_155 ;
} while ( V_140 != NULL ) ;
} else {
#ifdef F_127
F_110 ( 23 , L_20 ) ;
#endif
}
return NULL ;
}
static struct V_166 *
F_133 ( struct V_134 * V_184 ,
T_16 * V_36 )
{
struct V_166 * V_185 = NULL ;
V_185 = (struct V_166 * ) F_12 ( V_186 , V_184 ) ;
if( V_185 ) {
do {
if ( V_185 -> V_141 ) {
if ( V_36 -> V_143 -> V_144 >= V_185 -> V_141 -> V_142 &&
( V_185 -> V_141 -> V_145 ? V_36 -> V_143 -> V_144 <= V_185 -> V_141 -> V_145 : 1 ) ) {
#ifdef F_127
F_110 ( 10 , L_21 , V_185 -> V_141 -> V_126 ) ;
#endif
return V_185 ;
}
#ifdef F_127
F_110 ( 60 , L_22 , V_185 -> V_141 -> V_126 ) ;
#endif
}
if( V_185 -> V_171 == NULL ) {
#ifdef F_127
F_110 ( 23 , L_23 ) ;
#endif
break;
}
V_185 = V_185 -> V_171 ;
} while ( V_185 != NULL ) ;
} else {
#ifdef F_127
F_110 ( 23 , L_24 ) ;
#endif
}
return NULL ;
}
static struct V_173 *
F_134 ( struct V_137 * V_187 ,
T_16 * V_36 , T_3 V_188 )
{
struct V_173 * V_189 = NULL ;
V_189 = (struct V_173 * ) F_12 ( V_190 , V_187 ) ;
if( V_189 ) {
do {
if ( V_189 -> V_141 ) {
if ( ( V_188 &&
( V_189 -> V_141 -> V_145 ? V_36 -> V_143 -> V_144 == V_189 -> V_141 -> V_145 : 1 )
)
||
( ! V_188 &&
V_36 -> V_143 -> V_144 >= V_189 -> V_141 -> V_142 &&
( V_189 -> V_141 -> V_145 ? V_36 -> V_143 -> V_144 <= V_189 -> V_141 -> V_145 : 1 )
)
) {
#ifdef F_127
F_110 ( 10 , L_25 , V_189 -> V_141 -> V_126 ) ;
#endif
return V_189 ;
}
#ifdef F_127
F_110 ( 60 , L_26 , V_189 -> V_141 -> V_126 ) ;
#endif
}
if( V_189 -> V_179 == NULL ) {
#ifdef F_127
F_110 ( 23 , L_27 ) ;
#endif
break;
}
V_189 = V_189 -> V_179 ;
} while ( V_189 != NULL ) ;
} else {
#ifdef F_127
F_110 ( 23 , L_28 ) ;
#endif
}
return NULL ;
}
static struct V_150 *
F_135 ( struct V_123 * V_191 ,
T_16 * V_36 )
{
struct V_123 * V_192 ;
struct V_150 * V_193 = NULL ;
#ifdef F_123
V_192 = (struct V_123 * ) F_136 ( sizeof( struct V_123 ) ) ;
#else
V_192 = F_137 ( F_126 () , struct V_123 ) ;
#endif
V_192 -> V_126 = V_191 -> V_126 ;
#ifdef F_123
V_193 = (struct V_150 * ) F_124 ( sizeof( struct V_150 ) ) ;
#else
V_193 = F_125 ( F_126 () , struct V_150 ) ;
#endif
V_193 -> V_128 = V_192 ;
V_193 -> V_126 = V_191 -> V_126 ;
V_193 -> V_142 = V_36 -> V_143 -> V_144 ;
#ifdef F_127
F_110 ( 10 , L_29 , V_193 -> V_126 ) ;
#endif
F_2 ( V_194 , V_192 , V_193 ) ;
return V_193 ;
}
static struct V_139 *
F_138 ( struct V_129 * V_181 ,
struct V_150 * V_151 )
{
struct V_129 * V_195 ;
struct V_139 * V_152 = NULL ;
#ifdef F_123
V_195 = (struct V_129 * ) F_136 ( sizeof( struct V_129 ) ) ;
#else
V_195 = F_137 ( F_126 () , struct V_129 ) ;
#endif
V_195 -> V_130 = V_181 -> V_130 ;
V_195 -> V_132 = V_181 -> V_132 ;
V_195 -> V_131 = V_181 -> V_131 ;
#ifdef F_123
V_152 = (struct V_139 * ) F_124 ( sizeof( struct V_139 ) ) ;
#else
V_152 = F_125 ( F_126 () , struct V_139 ) ;
#endif
V_152 -> V_154 = V_195 ;
V_152 -> V_141 = V_151 ;
V_151 -> V_153 = V_152 ;
V_152 -> V_157 = TRUE ;
V_152 -> V_155 = NULL ;
V_152 -> V_156 = NULL ;
#ifdef F_127
F_110 ( 10 , L_17 , V_152 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_183 , V_195 , V_152 ) ;
return V_152 ;
}
static struct V_166 *
F_139 ( struct V_134 * V_184 ,
struct V_150 * V_151 )
{
struct V_134 * V_196 ;
struct V_166 * V_168 = NULL ;
#ifdef F_123
V_196 = (struct V_134 * ) F_136 ( sizeof( struct V_134 ) ) ;
#else
V_196 = F_137 ( F_126 () , struct V_134 ) ;
#endif
V_196 -> V_130 = V_184 -> V_130 ;
V_196 -> V_55 = V_184 -> V_55 ;
V_196 -> V_64 = V_184 -> V_64 ;
V_196 -> V_135 = V_184 -> V_135 ;
V_196 -> V_136 = V_184 -> V_136 ;
#ifdef F_123
V_168 = (struct V_166 * ) F_124 ( sizeof( struct V_166 ) ) ;
#else
V_168 = F_125 ( F_126 () , struct V_166 ) ;
#endif
V_168 -> V_170 = V_196 ;
V_168 -> V_141 = V_151 ;
V_151 -> V_169 = V_168 ;
V_168 -> V_157 = TRUE ;
V_168 -> V_171 = NULL ;
V_168 -> V_172 = NULL ;
#ifdef F_127
F_110 ( 10 , L_21 , V_168 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_186 , V_196 , V_168 ) ;
return V_168 ;
}
static struct V_173 *
F_140 ( struct V_137 * V_187 ,
struct V_150 * V_151 )
{
struct V_137 * V_197 ;
struct V_173 * V_175 = NULL ;
#ifdef F_123
V_197 = (struct V_137 * ) F_136 ( sizeof( struct V_137 ) ) ;
#else
V_197 = F_137 ( F_126 () , struct V_137 ) ;
#endif
V_197 -> V_130 = V_187 -> V_130 ;
V_197 -> V_132 = V_187 -> V_132 ;
V_197 -> V_131 = V_187 -> V_131 ;
#ifdef F_123
V_175 = (struct V_173 * ) F_124 ( sizeof( struct V_173 ) ) ;
#else
V_175 = F_125 ( F_126 () , struct V_173 ) ;
#endif
V_175 -> V_178 = V_197 ;
V_175 -> V_141 = V_151 ;
V_151 -> V_177 = V_175 ;
V_175 -> V_157 = TRUE ;
V_175 -> V_179 = NULL ;
V_175 -> V_180 = NULL ;
#ifdef F_127
F_110 ( 10 , L_25 , V_175 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_190 , V_197 , V_175 ) ;
return V_175 ;
}
static struct V_158 *
F_141 ( struct V_138 * V_198 ,
struct V_150 * V_151 )
{
struct V_138 * V_199 ;
struct V_158 * V_161 = NULL ;
#ifdef F_123
V_199 = (struct V_138 * ) F_136 ( sizeof( struct V_138 ) ) ;
#else
V_199 = F_137 ( F_126 () , struct V_138 ) ;
#endif
V_199 -> V_130 = V_198 -> V_130 ;
V_199 -> V_132 = V_198 -> V_132 ;
V_199 -> V_135 = V_198 -> V_135 ;
V_199 -> V_136 = V_198 -> V_136 ;
#ifdef F_123
V_161 = (struct V_158 * ) F_124 ( sizeof( struct V_158 ) ) ;
#else
V_161 = F_125 ( F_126 () , struct V_158 ) ;
#endif
V_161 -> V_163 = V_199 ;
V_161 -> V_141 = V_151 ;
V_151 -> V_162 = V_161 ;
V_161 -> V_157 = TRUE ;
V_161 -> V_164 = NULL ;
V_161 -> V_165 = NULL ;
#ifdef F_127
F_110 ( 10 , L_30 , V_161 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_200 , V_199 , V_161 ) ;
return V_161 ;
}
static struct V_166 *
F_142 ( struct V_134 * V_184 ,
struct V_150 * V_151 )
{
struct V_166 * V_201 = NULL ;
struct V_166 * V_185 = NULL ;
V_201 = (struct V_166 * )
F_12 ( V_186 , V_184 ) ;
if ( V_201 ) {
do {
if ( ! V_201 -> V_171 ) {
V_185 = F_130 ( V_201 ,
V_151 ) ;
break;
}
V_201 = V_201 -> V_171 ;
} while ( V_201 != NULL );
} else {
V_185 = F_139 ( V_184 ,
V_151 ) ;
}
return V_185 ;
}
static struct V_173 *
F_143 ( struct V_137 * V_187 ,
struct V_150 * V_151 )
{
struct V_173 * V_202 = NULL ;
struct V_173 * V_189 = NULL ;
V_202 = (struct V_173 * )
F_12 ( V_190 , V_187 ) ;
if ( V_202 ) {
do {
if ( ! V_202 -> V_179 ) {
V_189 = F_131 ( V_202 ,
V_151 ) ;
break;
}
V_202 = V_202 -> V_179 ;
} while ( V_202 != NULL );
} else {
V_189 = F_140 ( V_187 ,
V_151 ) ;
}
return V_189 ;
}
void
F_144 ( void )
{
if ( V_194 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_31 ) ;
#endif
F_145 ( V_194 ) ;
}
if ( V_183 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_32 ) ;
#endif
F_145 ( V_183 ) ;
}
if ( V_186 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_33 ) ;
#endif
F_145 ( V_186 ) ;
}
if ( V_190 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_34 ) ;
#endif
F_145 ( V_190 ) ;
}
if ( V_200 != NULL ) {
#ifdef F_127
F_110 ( 16 , L_35 ) ;
#endif
F_145 ( V_200 ) ;
}
#ifdef F_127
F_110 ( 16 , L_36 ) ;
#endif
V_194 = F_146 ( F_112 , F_111 ) ;
V_183 = F_146 ( F_114 , F_113 ) ;
V_186 = F_146 ( F_116 , F_115 ) ;
V_190 = F_146 ( F_118 , F_117 ) ;
V_200 = F_146 ( F_120 , F_119 ) ;
V_203 = 1 ;
V_204 = V_205 || V_206 & V_207 ;
}
static struct V_150 *
F_147 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_151 = NULL ;
struct V_123 V_210 ;
struct V_139 * V_140 , * V_152 = NULL ;
struct V_129 V_211 ;
T_21 * V_212 ;
T_21 * V_213 = NULL ;
T_10 * V_214 = NULL ;
#ifdef F_127
F_110 ( 51 , L_37 , F_148 ( F_149 () , & V_36 -> V_215 ) , V_209 -> V_55 , F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
#endif
V_211 . V_132 = V_209 -> V_55 ;
if ( V_36 -> V_215 . type == V_217 && V_36 -> V_216 . type == V_217 )
{
V_211 . V_131 = F_150 ( ( const V_218 * ) V_36 -> V_215 . T_17 ) ;
} else {
V_211 . V_131 = F_151 ( F_148 ( F_149 () , & V_36 -> V_215 ) ) ;
}
V_211 . V_130 = F_114 ( & V_211 ) ;
#ifdef F_127
F_110 ( 10 , L_38 , V_36 -> V_143 -> V_144 ) ;
F_110 ( 11 , L_39 , V_211 . V_130 ) ;
F_110 ( 51 , L_40 , F_148 ( F_149 () , & V_36 -> V_215 ) ) ;
F_110 ( 51 , L_41 , V_211 . V_132 ) ;
#endif
V_140 = (struct V_139 * )
F_12 ( V_183 , & V_211 ) ;
if ( V_140 ) {
do {
if ( V_36 -> V_143 -> V_144 == V_140 -> V_141 -> V_142 ) {
#ifdef F_127
F_110 ( 22 , L_42 ) ;
#endif
V_151 = V_140 -> V_141 ;
break;
}
if ( ! V_140 -> V_155 ) {
if ( ( V_140 -> V_141 -> V_145 != 0
&& V_36 -> V_143 -> V_144 > V_140 -> V_141 -> V_142
&& ( T_18 ) V_36 -> V_143 -> V_148 . V_219 > ( T_18 ) ( V_140 -> V_141 -> V_147 . V_219 + V_220 )
) ||
( V_140 -> V_141 -> V_145 == 0
&& V_36 -> V_143 -> V_144 > V_140 -> V_141 -> V_142
&& ( T_18 ) V_36 -> V_143 -> V_148 . V_219 > ( T_18 ) ( V_140 -> V_141 -> V_147 . V_219 + V_221 )
)
)
{
#ifdef F_127
F_110 ( 12 , L_43 , V_211 . V_130 ) ;
F_110 ( 12 , L_44 , V_36 -> V_143 -> V_144 , V_140 -> V_141 -> V_145 ) ;
#endif
V_210 . V_126 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_152 = F_122 ( V_140 ,
V_151 ,
V_36 ) ;
#ifdef F_127
F_110 ( 12 , L_45 , V_211 . V_130 ) ;
#endif
F_121 ( V_152 , V_36 ) ;
} else {
if ( V_140 -> V_141 -> V_222 ) {
#ifdef F_127
F_110 ( 12 , L_46 , V_211 . V_130 ) ;
F_110 ( 12 , L_44 , V_36 -> V_143 -> V_144 , V_140 -> V_141 -> V_145 ) ;
#endif
V_210 . V_126 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_152 = F_122 ( V_140 ,
V_151 ,
V_36 ) ;
#ifdef F_127
F_110 ( 12 , L_47 , V_211 . V_130 ) ;
#endif
F_121 ( V_152 , V_36 ) ;
} else {
#ifdef F_127
F_110 ( 21 , L_48 , V_140 -> V_141 -> V_142 ) ;
#endif
V_151 = V_140 -> V_141 ;
if ( V_204 && T_11 ) {
V_214 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_213 , L_49 ) ;
F_152 ( V_213 ) ;
V_212 = F_153 ( V_214 , V_224 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_50 ,
V_151 -> V_126 , V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
}
return V_151 ;
}
}
break;
}
V_140 = V_140 -> V_155 ;
} while ( V_140 != NULL );
} else {
#ifdef F_127
F_110 ( 10 , L_51 , V_211 . V_130 ) ;
#endif
V_210 . V_126 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_140 = F_138 ( & V_211 , V_151 ) ;
#ifdef F_127
F_110 ( 11 , L_45 , V_211 . V_130 ) ;
F_110 ( 11 , L_52 , V_36 -> V_143 -> V_144 ) ;
#endif
F_121 ( V_140 , V_36 ) ;
}
if ( V_204 && T_11 &&
V_151 &&
V_151 -> V_126 ) {
V_214 = F_60 ( T_11 , T_6 , 0 , 0 , V_223 , & V_213 , L_49 ) ;
F_152 ( V_213 ) ;
V_212 = F_154 ( V_214 , V_225 , T_6 , 0 , 0 , V_151 -> V_126 ) ;
F_152 ( V_212 ) ;
if( V_151 -> V_145 != 0 ) {
#ifdef F_127
F_110 ( 20 , L_53 , V_151 -> V_145 ) ;
#endif
V_212 = F_153 ( V_214 , V_226 , T_6 , 0 , 0 ,
V_151 -> V_145 ,
L_54 ,
V_151 -> V_145 ) ;
F_152 ( V_212 ) ;
}
}
return V_151 ;
}
static struct V_150 *
F_155 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_151 = NULL ;
struct V_166 * V_185 ;
struct V_134 V_227 ;
struct V_129 V_211 ;
struct V_139 * V_140 ;
struct V_137 V_228 ;
T_21 * V_212 ;
T_21 * V_213 = NULL ;
T_10 * V_214 = NULL ;
#ifdef F_127
F_110 ( 51 , L_55 , F_148 ( F_149 () , & V_36 -> V_215 ) , V_209 -> V_55 , F_148 ( F_149 () , & V_36 -> V_216 ) , V_209 -> V_64 ) ;
F_110 ( 10 , L_56 , V_36 -> V_143 -> V_144 ) ;
#endif
V_227 . V_55 = V_209 -> V_55 ;
V_227 . V_64 = V_209 -> V_64 ;
if ( V_36 -> V_215 . type == V_217 && V_36 -> V_216 . type == V_217 )
{
V_227 . V_135 = F_150 ( ( const V_218 * ) V_36 -> V_215 . T_17 ) ;
V_227 . V_136 = F_150 ( ( const V_218 * ) V_36 -> V_216 . T_17 ) ;
} else {
V_227 . V_135 = F_151 ( F_148 ( F_149 () , & V_36 -> V_215 ) ) ;
V_227 . V_136 = F_151 ( F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
}
V_227 . V_130 = F_116 ( & V_227 ) ;
#ifdef F_127
F_110 ( 11 , L_57 , V_227 . V_130 ) ;
F_110 ( 51 , L_58 , F_148 ( F_149 () , & V_36 -> V_215 ) , F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_59 , V_227 . V_55 , V_227 . V_64 ) ;
#endif
V_185 = F_133 ( & V_227 , V_36 ) ;
if( V_185 ) {
#ifdef F_127
F_110 ( 12 , L_60 ) ;
#endif
V_151 = V_185 -> V_141 ;
} else {
#ifdef F_127
F_110 ( 12 , L_61 ) ;
#endif
V_211 . V_132 = V_209 -> V_64 ;
if ( V_36 -> V_215 . type == V_217 && V_36 -> V_216 . type == V_217 )
{
V_211 . V_131 = F_150 ( ( const V_218 * ) V_36 -> V_216 . T_17 ) ;
} else {
V_211 . V_131 = F_151 ( F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
}
V_211 . V_130 = F_114 ( & V_211 ) ;
#ifdef F_127
F_110 ( 11 , L_62 , V_211 . V_130 ) ;
F_110 ( 51 , L_40 , F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_41 , V_211 . V_132 ) ;
#endif
V_140 = F_132 ( & V_211 , V_36 , FALSE ) ;
if( ! V_140 ) {
#ifdef F_127
F_110 ( 12 , L_63 ) ;
#endif
V_211 . V_132 = V_209 -> V_55 ;
if ( V_36 -> V_215 . type == V_217 && V_36 -> V_216 . type == V_217 )
{
V_211 . V_131 = F_150 ( ( const V_218 * ) V_36 -> V_215 . T_17 ) ;
} else {
V_211 . V_131 = F_151 ( F_148 ( F_149 () , & V_36 -> V_215 ) ) ;
}
V_211 . V_130 = F_114 ( & V_211 ) ;
#ifdef F_127
F_110 ( 11 , L_62 , V_211 . V_130 ) ;
F_110 ( 51 , L_40 , F_148 ( F_149 () , & V_36 -> V_215 ) ) ;
F_110 ( 51 , L_41 , V_211 . V_132 ) ;
#endif
V_140 = F_132 ( & V_211 , V_36 , FALSE ) ;
}
if( V_140 &&
! V_140 -> V_141 -> V_169 ) {
#ifdef F_127
F_110 ( 12 , L_64 ) ;
#endif
V_151 = V_140 -> V_141 ;
V_151 -> V_146 = TRUE ;
#ifdef F_127
F_110 ( 10 , L_65 , V_227 . V_130 ) ;
F_110 ( 11 , L_66 , V_36 -> V_143 -> V_144 ) ;
#endif
F_142 ( & V_227 ,
V_140 -> V_141 ) ;
V_228 . V_132 = V_209 -> V_55 ;
if ( V_36 -> V_215 . type == V_217 && V_36 -> V_216 . type == V_217 )
{
V_228 . V_131 = F_150 ( ( const V_218 * ) V_36 -> V_215 . T_17 ) ;
} else {
V_228 . V_131 = F_151 ( F_148 ( F_149 () , & V_36 -> V_215 ) ) ;
}
V_228 . V_130 = F_118 ( & V_228 ) ;
#ifdef F_127
F_110 ( 10 , L_67 , V_228 . V_130 ) ;
F_110 ( 51 , L_40 , F_148 ( F_149 () , & V_36 -> V_215 ) ) ;
F_110 ( 51 , L_68 , V_228 . V_132 ) ;
F_110 ( 11 , L_52 , V_36 -> V_143 -> V_144 ) ;
#endif
F_143 ( & V_228 ,
V_140 -> V_141 ) ;
} else {
#ifdef F_127
F_110 ( 12 , L_69 ) ;
#endif
}
}
if ( V_204 && T_11 &&
V_151 &&
V_151 -> V_126 ) {
V_214 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_213 , L_49 ) ;
F_152 ( V_213 ) ;
V_212 = F_154 ( V_214 , V_225 , T_6 , 0 , 0 , V_151 -> V_126 ) ;
F_152 ( V_212 ) ;
}
return V_151 ;
}
static struct V_150 *
F_156 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_151 = NULL ;
struct V_137 V_228 ;
struct V_173 * V_189 = NULL ;
struct V_129 V_211 ;
struct V_139 * V_140 = NULL ;
T_21 * V_212 ;
T_22 V_229 ;
T_21 * V_213 = NULL ;
T_10 * V_214 = NULL ;
#ifdef F_127
F_110 ( 51 , L_70 , F_148 ( F_149 () , & V_36 -> V_215 ) , F_148 ( F_149 () , & V_36 -> V_216 ) , V_209 -> V_64 ) ;
F_110 ( 10 , L_71 , V_36 -> V_143 -> V_144 ) ;
#endif
V_228 . V_132 = V_209 -> V_64 ;
if ( V_36 -> V_215 . type == V_217 && V_36 -> V_216 . type == V_217 )
{
V_228 . V_131 = F_150 ( ( const V_218 * ) V_36 -> V_216 . T_17 ) ;
} else {
V_228 . V_131 = F_151 ( F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
}
V_228 . V_130 = F_118 ( & V_228 ) ;
#ifdef F_127
F_110 ( 11 , L_72 , V_228 . V_130 ) ;
F_110 ( 11 , L_40 , F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_68 , V_228 . V_132 ) ;
#endif
V_189 = F_134 ( & V_228 , V_36 , TRUE ) ;
if( ! V_189 ) {
#ifdef F_127
F_110 ( 12 , L_73 ) ;
#endif
V_211 . V_132 = V_209 -> V_64 ;
if ( V_36 -> V_215 . type == V_217 && V_36 -> V_216 . type == V_217 )
{
V_211 . V_131 = F_150 ( ( const V_218 * ) V_36 -> V_216 . T_17 ) ;
} else {
V_211 . V_131 = F_151 ( F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
}
V_211 . V_130 = F_114 ( & V_211 ) ;
#ifdef F_127
F_110 ( 11 , L_62 , V_211 . V_130 ) ;
F_110 ( 51 , L_40 , F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_68 , V_211 . V_132 ) ;
#endif
V_140 = F_132 ( & V_211 , V_36 , FALSE ) ;
if( ! V_140 ) {
#ifdef F_127
F_110 ( 12 , L_69 ) ;
#endif
}
}
if ( V_189 ) {
V_151 = V_189 -> V_141 ;
} else if ( V_140 ) {
V_151 = V_140 -> V_141 ;
}
if ( V_151 ) {
#ifdef F_127
F_110 ( 12 , L_74 , V_151 -> V_142 ) ;
#endif
if ( V_204 && T_11 ) {
V_214 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_213 , L_49 ) ;
F_152 ( V_213 ) ;
V_212 = F_154 ( V_214 , V_225 , T_6 , 0 , 0 , V_151 -> V_126 ) ;
F_152 ( V_212 ) ;
}
#ifdef F_127
F_110 ( 20 , L_75 , V_151 -> V_142 ) ;
#endif
if ( V_204 && V_214 ) {
V_212 = F_153 ( V_214 , V_230 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_76 ,
V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
F_157 ( & V_229 , & V_36 -> V_143 -> V_148 , & V_151 -> V_147 ) ;
V_212 = F_158 ( V_214 , V_231 , T_6 , 0 , 0 , & V_229 ) ;
F_152 ( V_212 ) ;
}
F_159 ( V_151 , V_36 ) ;
} else {
#ifdef F_127
F_110 ( 12 , L_77 ) ;
#endif
}
return V_151 ;
}
static struct V_150 *
F_160 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_151 = NULL ;
struct V_123 V_210 ;
struct V_158 * V_159 , * V_161 ;
struct V_138 V_232 ;
T_21 * V_212 ;
T_22 V_229 ;
T_3 V_233 = FALSE ;
T_10 * V_214 = NULL ;
T_21 * V_213 = NULL ;
V_232 . V_132 = V_209 -> V_55 ;
if ( V_36 -> V_215 . type == V_217 && V_36 -> V_216 . type == V_217 )
{
V_232 . V_135 = F_150 ( ( const V_218 * ) V_36 -> V_215 . T_17 ) ;
V_232 . V_136 = F_150 ( ( const V_218 * ) V_36 -> V_216 . T_17 ) ;
} else {
V_232 . V_135 = F_151 ( F_148 ( F_149 () , & V_36 -> V_215 ) ) ;
V_232 . V_136 = F_151 ( F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
}
V_232 . V_130 = F_120 ( & V_232 ) ;
#ifdef F_127
F_110 ( 10 , L_78 , V_36 -> V_143 -> V_144 ) ;
F_110 ( 11 , L_39 , V_232 . V_130 ) ;
F_110 ( 51 , L_79 , F_148 ( F_149 () , & V_36 -> V_215 ) , F_148 ( F_149 () , & V_36 -> V_216 ) ) ;
F_110 ( 51 , L_68 , V_232 . V_132 ) ;
#endif
V_159 = (struct V_158 * )
F_12 ( V_200 , & V_232 ) ;
if ( V_159 ) {
do {
if ( V_36 -> V_143 -> V_144 == V_159 -> V_141 -> V_142 ) {
#ifdef F_127
F_110 ( 22 , L_80 ) ;
#endif
V_233 = FALSE ;
V_151 = V_159 -> V_141 ;
break;
}
if ( V_36 -> V_143 -> V_144 == V_159 -> V_141 -> V_145 ) {
#ifdef F_127
F_110 ( 22 , L_81 ) ;
#endif
V_233 = TRUE ;
V_151 = V_159 -> V_141 ;
break;
}
if ( V_36 -> V_143 -> V_144 > V_159 -> V_141 -> V_142 &&
V_159 -> V_141 -> V_145 == 0 ) {
#ifdef F_127
F_110 ( 12 , L_45 , V_232 . V_130 ) ;
#endif
V_159 -> V_141 -> V_145 = V_36 -> V_143 -> V_144 ;
V_159 -> V_141 -> V_146 = TRUE ;
V_159 -> V_141 -> V_222 = TRUE ;
V_151 = V_159 -> V_141 ;
V_233 = TRUE ;
if ( V_204 && T_11 ) {
V_214 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_213 , L_49 ) ;
F_152 ( V_213 ) ;
V_212 = F_154 ( V_214 , V_225 , T_6 , 0 , 0 , V_151 -> V_126 ) ;
F_152 ( V_212 ) ;
#ifdef F_127
F_110 ( 20 , L_75 , V_151 -> V_142 ) ;
#endif
V_212 = F_153 ( V_214 , V_230 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_76 ,
V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
F_157 ( & V_229 , & V_36 -> V_143 -> V_148 , & V_151 -> V_147 ) ;
V_212 = F_158 ( V_214 , V_231 , T_6 , 0 , 0 , & V_229 ) ;
F_152 ( V_212 ) ;
}
break;
}
if ( ! V_159 -> V_164 ) {
if ( ( V_159 -> V_141 -> V_145 != 0
&& V_36 -> V_143 -> V_144 > V_159 -> V_141 -> V_142
&& ( T_18 ) V_36 -> V_143 -> V_148 . V_219 > ( T_18 ) ( V_159 -> V_141 -> V_147 . V_219 + V_220 )
) ||
( V_159 -> V_141 -> V_145 == 0
&& V_36 -> V_143 -> V_144 > V_159 -> V_141 -> V_142
&& ( T_18 ) V_36 -> V_143 -> V_148 . V_219 > ( T_18 ) ( V_159 -> V_141 -> V_147 . V_219 + V_221 )
)
)
{
#ifdef F_127
F_110 ( 12 , L_43 , V_232 . V_130 ) ;
F_110 ( 12 , L_44 , V_36 -> V_143 -> V_144 , V_159 -> V_141 -> V_145 ) ;
#endif
V_210 . V_126 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_161 = F_129 ( V_159 ,
V_151 ,
V_36 ) ;
#ifdef F_127
F_110 ( 12 , L_45 , V_232 . V_130 ) ;
#endif
F_128 ( V_161 , V_36 ) ;
V_159 = V_161 ;
} else {
if ( V_159 -> V_141 -> V_222 ) {
#ifdef F_127
F_110 ( 12 , L_46 , V_232 . V_130 ) ;
F_110 ( 12 , L_44 , V_36 -> V_143 -> V_144 , V_159 -> V_141 -> V_145 ) ;
#endif
V_210 . V_126 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_161 = F_129 ( V_159 ,
V_151 ,
V_36 ) ;
#ifdef F_127
F_110 ( 12 , L_47 , V_232 . V_130 ) ;
#endif
F_128 ( V_161 , V_36 ) ;
V_159 = V_161 ;
} else {
V_151 = V_159 -> V_141 ;
#ifdef F_127
F_110 ( 12 , L_74 , V_151 -> V_142 ) ;
#endif
if ( V_204 && T_11 ) {
V_214 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_213 , L_49 ) ;
F_152 ( V_213 ) ;
V_212 = F_154 ( V_214 , V_225 , T_6 , 0 , 0 , V_151 -> V_126 ) ;
F_152 ( V_212 ) ;
#ifdef F_127
F_110 ( 20 , L_75 , V_151 -> V_142 ) ;
#endif
V_212 = F_153 ( V_214 , V_230 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_76 ,
V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
F_157 ( & V_229 , & V_36 -> V_143 -> V_148 , & V_151 -> V_147 ) ;
V_212 = F_158 ( V_214 , V_231 , T_6 , 0 , 0 , & V_229 ) ;
F_152 ( V_212 ) ;
}
V_151 = V_159 -> V_141 ;
}
}
break;
}
V_159 = V_159 -> V_164 ;
} while ( V_159 != NULL );
} else {
#ifdef F_127
F_110 ( 10 , L_51 , V_232 . V_130 ) ;
#endif
V_210 . V_126 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_159 = F_141 ( & V_232 , V_151 ) ;
#ifdef F_127
F_110 ( 11 , L_45 , V_232 . V_130 ) ;
F_110 ( 11 , L_52 , V_36 -> V_143 -> V_144 ) ;
#endif
F_128 ( V_159 , V_36 ) ;
}
if ( V_204 && T_11 &&
V_151 &&
V_151 -> V_126 ) {
V_214 = F_60 ( T_11 , T_6 , 0 , - 1 , V_223 , & V_213 , L_49 ) ;
F_152 ( V_213 ) ;
V_212 = F_154 ( V_214 , V_225 , T_6 , 0 , 0 , V_151 -> V_126 ) ;
F_152 ( V_212 ) ;
}
if( V_204 && V_214 &&
V_159 -> V_141 -> V_145 != 0 ) {
if ( ! V_233 ) {
#ifdef F_127
F_110 ( 20 , L_53 , V_159 -> V_141 -> V_145 ) ;
#endif
V_212 = F_153 ( V_214 , V_226 , T_6 , 0 , 0 ,
V_159 -> V_141 -> V_145 ,
L_54 ,
V_159 -> V_141 -> V_145 ) ;
F_152 ( V_212 ) ;
} else {
#ifdef F_127
F_110 ( 20 , L_75 , V_151 -> V_142 ) ;
#endif
if ( V_204 ) {
V_212 = F_153 ( V_214 , V_230 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_76 ,
V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
F_157 ( & V_229 , & V_36 -> V_143 -> V_148 , & V_151 -> V_147 ) ;
V_212 = F_158 ( V_214 , V_231 , T_6 , 0 , 0 , & V_229 ) ;
F_152 ( V_212 ) ;
}
}
}
return V_151 ;
}
struct V_150 *
F_161 ( T_5 * T_6 , T_16 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_234 = NULL ;
if( V_36 == NULL || V_36 -> V_143 -> V_144 == 0 ) {
return NULL ;
}
switch ( V_209 -> V_58 ) {
case V_59 :
#ifdef F_127
F_110 ( 1 , L_82 ) ;
#endif
V_234 = F_147 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
case V_68 :
#ifdef F_127
F_110 ( 1 , L_83 ) ;
#endif
V_234 = F_155 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
case V_73 :
#ifdef F_127
F_110 ( 1 , L_84 ) ;
#endif
V_234 = F_156 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
case V_65 :
#ifdef F_127
F_110 ( 1 , L_85 ) ;
#endif
V_234 = F_156 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
case V_235 :
case V_236 :
#ifdef F_127
F_110 ( 1 , L_86 ) ;
#endif
V_234 = F_160 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
default:
#ifdef F_127
F_110 ( 1 , L_87 , V_209 -> V_58 ) ;
#endif
break;
}
#ifdef F_127
if ( V_234 )
F_110 ( 1 , L_88 , V_234 -> V_126 ) ;
#endif
return V_234 ;
}
struct V_208 *
F_162 ( void )
{
struct V_208 * V_209 ;
V_237 ++ ;
if( V_237 == V_238 ) {
V_237 = 0 ;
}
V_209 = & V_239 [ V_237 ] ;
memset ( V_209 , 0 , sizeof( struct V_208 ) ) ;
return V_209 ;
}
void
F_159 ( struct V_150 * V_151 ,
T_16 * V_36 )
{
#ifdef F_127
F_110 ( 60 , L_89 ) ;
#endif
if ( V_151 ) {
V_151 -> V_146 = TRUE ;
V_151 -> V_145 = V_36 -> V_143 -> V_144 ;
V_151 -> V_240 = V_36 -> V_143 -> V_148 ;
V_151 -> V_222 = TRUE ;
if ( V_151 -> V_177
&& ! V_205 ) {
if ( V_151 -> V_177 -> V_179 ) {
if ( V_151 -> V_177 -> V_180 ) {
#ifdef F_127
F_110 ( 20 , L_90 ) ;
#endif
V_151 -> V_177 -> V_180 -> V_179
= V_151 -> V_177 -> V_179 ;
V_151 -> V_177 -> V_179 -> V_180
= V_151 -> V_177 -> V_180 ;
F_7 ( V_190 , V_151 -> V_177 -> V_178 ) ;
#ifdef F_123
F_163 ( V_151 -> V_177 ) ;
#endif
} else {
#ifdef F_127
F_110 ( 20 , L_91 ) ;
#endif
}
} else if ( ! V_205 ) {
#ifdef F_127
F_110 ( 20 , L_92 ) ;
#endif
F_7 ( V_190 , V_151 -> V_177 -> V_178 ) ;
#ifdef F_123
F_163 ( V_151 -> V_177 -> V_178 ) ;
F_163 ( V_151 -> V_177 ) ;
#endif
}
}
if ( V_151 -> V_169
&& ! V_205 ) {
if ( V_151 -> V_169 -> V_171 ) {
if ( V_151 -> V_169 -> V_172 ) {
#ifdef F_127
F_110 ( 20 , L_93 ) ;
#endif
V_151 -> V_169 -> V_172 -> V_171
= V_151 -> V_169 -> V_171 ;
V_151 -> V_169 -> V_171 -> V_172
= V_151 -> V_169 -> V_172 ;
F_7 ( V_186 , V_151 -> V_169 -> V_170 ) ;
#ifdef F_123
F_163 ( V_151 -> V_169 ) ;
#endif
} else {
#ifdef F_127
F_110 ( 20 , L_94 ) ;
#endif
}
} else if ( ! V_205 ) {
#ifdef F_127
F_110 ( 20 , L_95 ) ;
#endif
F_7 ( V_186 , V_151 -> V_169 -> V_170 ) ;
#ifdef F_123
F_163 ( V_151 -> V_169 -> V_170 ) ;
F_163 ( V_151 -> V_169 ) ;
#endif
}
}
if ( V_151 -> V_153
&& ! V_205 ) {
if ( V_151 -> V_153 -> V_155 ) {
if ( V_151 -> V_153 -> V_156 ) {
#ifdef F_127
F_110 ( 20 , L_96 ) ;
#endif
V_151 -> V_153 -> V_156 -> V_155
= V_151 -> V_153 -> V_155 ;
V_151 -> V_153 -> V_155 -> V_156
= V_151 -> V_153 -> V_156 ;
F_7 ( V_183 , V_151 -> V_153 -> V_154 ) ;
#ifdef F_123
F_163 ( V_151 -> V_153 ) ;
#endif
} else {
#ifdef F_127
F_110 ( 20 , L_97 ) ;
#endif
}
} else if ( ! V_205 ) {
#ifdef F_127
F_110 ( 20 , L_98 ) ;
#endif
F_7 ( V_183 , V_151 -> V_153 -> V_154 ) ;
#ifdef F_123
F_163 ( V_151 -> V_153 -> V_154 ) ;
F_163 ( V_151 -> V_153 ) ;
#endif
}
}
if ( V_151 -> V_162
&& ! V_205 ) {
if ( V_151 -> V_162 -> V_164 ) {
if ( V_151 -> V_162 -> V_165 ) {
#ifdef F_127
F_110 ( 20 , L_99 ) ;
#endif
V_151 -> V_162 -> V_165 -> V_164
= V_151 -> V_162 -> V_164 ;
V_151 -> V_162 -> V_164 -> V_165
= V_151 -> V_162 -> V_165 ;
F_7 ( V_200 , V_151 -> V_162 -> V_163 ) ;
#ifdef F_123
F_163 ( V_151 -> V_162 ) ;
#endif
} else {
#ifdef F_127
F_110 ( 20 , L_100 ) ;
#endif
}
} else if ( ! V_205 ) {
#ifdef F_127
F_110 ( 20 , L_101 ) ;
#endif
F_7 ( V_200 , V_151 -> V_162 -> V_163 ) ;
#ifdef F_123
F_163 ( V_151 -> V_162 -> V_163 ) ;
F_163 ( V_151 -> V_162 ) ;
#endif
}
}
if ( ! V_205 ) {
#ifdef F_127
F_110 ( 20 , L_102 ) ;
#endif
F_7 ( V_194 , V_151 -> V_128 ) ;
#ifdef F_123
F_163 ( V_151 -> V_128 ) ;
F_163 ( V_151 ) ;
#endif
}
} else {
#ifdef F_127
F_110 ( 20 , L_103 ) ;
#endif
}
}
static void
F_164 ( T_5 * T_6 , T_16 * V_36 , T_10 * V_241 )
{
T_21 * V_242 = NULL ;
T_10 * T_11 = NULL ;
struct V_150 * V_243 ;
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
F_69 ( V_36 -> V_56 , V_248 , L_104 ) ;
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
if ( V_206 && ! V_254 ) {
V_243 = F_161 ( T_6 , V_36 , V_247 , V_54 ) ;
V_83 . V_141 = V_243 ;
if ( V_243 && V_82 && ! V_243 -> V_256 ) {
F_170 ( V_243 -> V_84 , V_82 , sizeof( V_243 -> V_84 ) ) ;
V_243 -> V_256 = TRUE ;
if ( ( V_244 = F_171 ( V_257 , V_82 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
}
}
if ( V_206 && V_243 && V_243 -> V_259 ) {
( V_243 -> V_259 ) ( T_6 , V_36 , V_247 , V_243 ) ;
}
}
}
void
F_172 ( void )
{
V_260 = F_173 ( L_105 ) ;
V_246 = F_173 ( L_106 ) ;
V_257 = F_174 ( L_107 ) ;
#line 1 "../../asn1/tcap/packet-tcap-dis-tab.c"
F_175 ( L_108 , F_109 , V_249 , L_109 ) ;
F_175 ( L_110 , F_107 , V_249 , L_111 ) ;
#line 2071 "../../asn1/tcap/packet-tcap-template.c"
}
void
F_176 ( void )
{
static T_23 V_261 [] = {
{ & V_262 ,
{ L_112 ,
L_113 ,
V_263 , V_264 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_266 ,
{ L_114 ,
L_115 ,
V_263 , V_267 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_268 ,
{ L_116 ,
L_117 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_51 ,
{ L_118 ,
L_119 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_271 ,
{ L_120 ,
L_121 ,
V_272 , V_264 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_225 ,
{ L_122 ,
L_123 ,
V_273 , V_267 , NULL , 0x0 ,
NULL , V_265 }
} ,
{ & V_226 ,
{ L_124 ,
L_125 ,
V_274 , V_270 , NULL , 0x0 ,
L_126 , V_265 }
} ,
{ & V_230 ,
{ L_127 ,
L_128 ,
V_274 , V_270 , NULL , 0x0 ,
L_129 , V_265 }
} ,
{ & V_231 ,
{ L_130 ,
L_131 ,
V_275 , V_270 , NULL , 0x0 ,
L_132 , V_265 }
} ,
{ & V_224 ,
{ L_133 ,
L_134 ,
V_274 , V_270 , NULL , 0x0 ,
L_135 , V_265 }
} ,
#line 1 "../../asn1/tcap/packet-tcap-hfarr.c"
{ & V_114 ,
{ L_136 , L_137 ,
V_273 , V_267 , F_177 ( V_276 ) , 0 ,
NULL , V_265 } } ,
{ & V_115 ,
{ L_138 , L_139 ,
V_273 , V_267 , F_177 ( V_277 ) , 0 ,
NULL , V_265 } } ,
{ & V_278 ,
{ L_140 , L_141 ,
V_279 , V_270 , NULL , 0 ,
L_142 , V_265 } } ,
{ & V_280 ,
{ L_143 , L_144 ,
V_269 , V_270 , NULL , 0 ,
L_145 , V_265 } } ,
{ & V_281 ,
{ L_146 , L_147 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_283 ,
{ L_148 , L_149 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_284 ,
{ L_150 , L_151 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_285 ,
{ L_152 , L_153 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_286 ,
{ L_154 , L_155 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_287 ,
{ L_156 , L_157 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_288 ,
{ L_158 , L_159 ,
V_273 , V_267 , NULL , 0 ,
L_160 , V_265 } } ,
{ & V_53 ,
{ L_161 , L_162 ,
V_269 , V_270 , NULL , 0 ,
L_163 , V_265 } } ,
{ & V_63 ,
{ L_164 , L_165 ,
V_269 , V_270 , NULL , 0 ,
L_166 , V_265 } } ,
{ & V_289 ,
{ L_167 , L_168 ,
V_273 , V_267 , F_177 ( V_290 ) , 0 ,
NULL , V_265 } } ,
{ & V_291 ,
{ L_169 , L_170 ,
V_273 , V_267 , F_177 ( V_292 ) , 0 ,
NULL , V_265 } } ,
{ & V_293 ,
{ L_171 , L_172 ,
V_269 , V_270 , NULL , 0 ,
L_173 , V_265 } } ,
{ & V_294 ,
{ L_174 , L_175 ,
V_273 , V_267 , F_177 ( V_295 ) , 0 ,
NULL , V_265 } } ,
{ & V_296 ,
{ L_176 , L_177 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_297 ,
{ L_178 , L_179 ,
V_282 , V_270 , NULL , 0 ,
L_180 , V_265 } } ,
{ & V_298 ,
{ L_181 , L_182 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_299 ,
{ L_183 , L_184 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_300 ,
{ L_185 , L_186 ,
V_282 , V_270 , NULL , 0 ,
L_180 , V_265 } } ,
{ & V_301 ,
{ L_187 , L_188 ,
V_302 , V_267 , NULL , 0 ,
L_189 , V_265 } } ,
{ & V_303 ,
{ L_190 , L_191 ,
V_302 , V_267 , NULL , 0 ,
L_189 , V_265 } } ,
{ & V_304 ,
{ L_192 , L_193 ,
V_273 , V_267 , F_177 ( V_305 ) , 0 ,
L_194 , V_265 } } ,
{ & V_306 ,
{ L_195 , L_196 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_307 ,
{ L_197 , L_198 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_308 ,
{ L_199 , L_200 ,
V_273 , V_267 , F_177 ( V_309 ) , 0 ,
NULL , V_265 } } ,
{ & V_310 ,
{ L_201 , L_202 ,
V_273 , V_267 , F_177 ( V_311 ) , 0 ,
NULL , V_265 } } ,
{ & V_312 ,
{ L_203 , L_204 ,
V_302 , V_267 , NULL , 0 ,
L_189 , V_265 } } ,
{ & V_313 ,
{ L_205 , L_206 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_314 ,
{ L_207 , L_208 ,
V_273 , V_267 , F_177 ( V_315 ) , 0 ,
NULL , V_265 } } ,
{ & V_316 ,
{ L_209 , L_210 ,
V_302 , V_267 , F_177 ( V_317 ) , 0 ,
NULL , V_265 } } ,
{ & V_318 ,
{ L_211 , L_212 ,
V_302 , V_267 , F_177 ( V_319 ) , 0 ,
NULL , V_265 } } ,
{ & V_320 ,
{ L_213 , L_214 ,
V_302 , V_267 , F_177 ( V_321 ) , 0 ,
NULL , V_265 } } ,
{ & V_322 ,
{ L_215 , L_216 ,
V_302 , V_267 , F_177 ( V_323 ) , 0 ,
NULL , V_265 } } ,
{ & V_324 ,
{ L_217 , L_218 ,
V_302 , V_267 , NULL , 0 ,
L_219 , V_265 } } ,
{ & V_325 ,
{ L_220 , L_221 ,
V_279 , V_270 , NULL , 0 ,
L_142 , V_265 } } ,
{ & V_326 ,
{ L_222 , L_223 ,
V_302 , V_267 , NULL , 0 ,
L_224 , V_265 } } ,
{ & V_327 ,
{ L_225 , L_226 ,
V_302 , V_267 , NULL , 0 ,
L_219 , V_265 } } ,
{ & V_328 ,
{ L_227 , L_228 ,
V_282 , V_270 , NULL , 0 ,
L_229 , V_265 } } ,
{ & V_329 ,
{ L_230 , L_231 ,
V_269 , V_270 , NULL , 0 ,
L_232 , V_265 } } ,
{ & V_330 ,
{ L_233 , L_234 ,
V_279 , V_270 , NULL , 0 ,
L_235 , V_265 } } ,
{ & V_331 ,
{ L_236 , L_237 ,
V_273 , V_267 , NULL , 0 ,
L_238 , V_265 } } ,
{ & V_332 ,
{ L_239 , L_240 ,
V_282 , V_270 , NULL , 0 ,
L_241 , V_265 } } ,
{ & V_333 ,
{ L_242 , L_243 ,
V_282 , V_270 , NULL , 0 ,
L_244 , V_265 } } ,
{ & V_334 ,
{ L_245 , L_246 ,
V_282 , V_270 , NULL , 0 ,
L_247 , V_265 } } ,
{ & V_335 ,
{ L_248 , L_249 ,
V_282 , V_270 , NULL , 0 ,
L_250 , V_265 } } ,
{ & V_336 ,
{ L_230 , L_231 ,
V_269 , V_270 , NULL , 0 ,
L_251 , V_265 } } ,
{ & V_337 ,
{ L_233 , L_234 ,
V_279 , V_270 , NULL , 0 ,
L_252 , V_265 } } ,
{ & V_338 ,
{ L_236 , L_237 ,
V_273 , V_267 , NULL , 0 ,
L_253 , V_265 } } ,
{ & V_339 ,
{ L_239 , L_240 ,
V_282 , V_270 , NULL , 0 ,
L_241 , V_265 } } ,
{ & V_340 ,
{ L_230 , L_231 ,
V_269 , V_270 , NULL , 0 ,
L_254 , V_265 } } ,
{ & V_341 ,
{ L_233 , L_234 ,
V_279 , V_270 , NULL , 0 ,
L_255 , V_265 } } ,
{ & V_342 ,
{ L_256 , L_257 ,
V_302 , V_267 , F_177 ( V_343 ) , 0 ,
L_258 , V_265 } } ,
{ & V_344 ,
{ L_259 , L_260 ,
V_273 , V_267 , F_177 ( V_345 ) , 0 ,
L_261 , V_265 } } ,
{ & V_346 ,
{ L_236 , L_237 ,
V_273 , V_267 , NULL , 0 ,
L_262 , V_265 } } ,
{ & V_347 ,
{ L_239 , L_240 ,
V_282 , V_270 , NULL , 0 ,
L_241 , V_265 } } ,
{ & V_348 ,
{ L_263 , L_264 ,
V_302 , V_267 , F_177 ( V_349 ) , 0 ,
L_265 , V_265 } } ,
{ & V_350 ,
{ L_236 , L_237 ,
V_273 , V_267 , NULL , 0 ,
L_266 , V_265 } } ,
{ & V_351 ,
{ L_239 , L_240 ,
V_282 , V_270 , NULL , 0 ,
L_241 , V_265 } } ,
{ & V_352 ,
{ L_267 , L_268 ,
V_302 , V_267 , F_177 ( V_353 ) , 0 ,
NULL , V_265 } } ,
{ & V_354 ,
{ L_269 , L_270 ,
V_302 , V_267 , F_177 ( V_355 ) , 0 ,
NULL , V_265 } } ,
{ & V_356 ,
{ L_271 , L_272 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
{ & V_358 ,
{ L_271 , L_272 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
{ & V_359 ,
{ L_271 , L_272 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
#line 2144 "../../asn1/tcap/packet-tcap-template.c"
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
#line 2154 "../../asn1/tcap/packet-tcap-template.c"
} ;
T_24 * V_362 ;
V_249 = F_178 ( V_363 , V_364 , V_365 ) ;
F_179 ( V_249 , V_261 , F_180 ( V_261 ) ) ;
F_181 ( V_360 , F_180 ( V_360 ) ) ;
V_362 = F_182 ( V_249 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_183 ( V_362 , L_273 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_183 ( V_362 , L_274 ) ;
#endif
F_184 ( & V_366 , L_275 , V_367 ) ;
F_185 ( V_362 , L_276 , L_277 ,
L_278 ,
& V_366 , V_367 ) ;
F_186 ( V_362 , L_279 ,
L_280 ,
L_281 ,
& V_206 ) ;
F_186 ( V_362 , L_282 ,
L_283 ,
L_284 ,
& V_205 ) ;
F_187 ( V_362 , L_285 ,
L_286 ,
L_287 ,
10 , & V_220 ) ;
F_187 ( V_362 , L_288 ,
L_289 ,
L_290 ,
10 , & V_221 ) ;
V_3 = F_146 ( V_368 , V_369 ) ;
V_5 = F_146 ( V_368 , V_369 ) ;
F_188 ( L_291 , F_164 , V_249 ) ;
V_4 = F_189 ( F_164 , V_249 ) ;
F_190 ( & V_370 ) ;
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
static void V_370 ( void )
{
V_372 = F_194 ( V_366 ) ;
F_195 ( V_372 , F_193 ) ;
F_144 () ;
}
static void V_371 ( void )
{
F_195 ( V_372 , F_192 ) ;
F_163 ( V_372 ) ;
}
static int
F_29 ( T_8 * T_9 , T_10 * T_11 , T_5 * T_6 , int T_7 )
{
T_14 V_373 , V_374 , V_375 ;
T_5 * V_29 ;
T_10 * V_49 ;
T_13 V_30 ;
T_3 V_31 ;
T_25 V_32 ;
T_1 V_33 ;
T_1 V_376 ;
T_1 V_377 ;
T_3 V_35 ;
while ( F_62 ( T_6 , T_7 ) > 0 )
{
V_374 = T_7 ;
T_7 = F_165 ( T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_373 = T_7 ;
T_7 = F_196 ( T_6 , T_7 , & V_33 , & V_35 ) ;
V_375 = T_7 ;
V_376 = V_373 - V_374 ;
V_377 = V_375 - V_373 ;
if ( V_31 )
{
V_49 = F_60 ( T_11 , T_6 , V_374 ,
V_33 + ( V_375 - V_374 ) , V_361 , NULL ,
L_292 ) ;
F_153 ( V_49 , V_262 , T_6 ,
V_374 , V_376 , V_32 ,
L_293 ) ;
F_154 ( V_49 , V_262 , T_6 , V_374 ,
V_376 , V_30 ) ;
F_154 ( V_49 , V_266 , T_6 , V_373 ,
V_377 , V_33 ) ;
if ( V_33 - ( 2 * V_35 ) )
{
V_29 = F_48 ( T_6 , T_7 , V_33 - ( 2 * V_35 ) ) ;
F_29 ( T_9 , V_49 , V_29 , 0 ) ;
}
if ( V_35 )
F_167 ( V_49 , V_271 , T_6 , T_7 + V_33 - 2 , 2 , V_378 ) ;
T_7 += V_33 ;
}
else
{
V_49 = F_197 ( T_11 , T_6 , V_374 ,
V_33 + ( V_375 - V_374 ) , V_361 , NULL ,
L_294 , V_32 ) ;
F_154 ( V_49 , V_262 , T_6 , V_374 ,
V_376 , V_32 ) ;
F_154 ( V_49 , V_266 , T_6 ,
V_374 + V_376 , V_377 , V_33 ) ;
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
static void F_169 ( struct V_379 * V_380 )
{
memset ( V_380 , 0 , sizeof( struct V_379 ) ) ;
}
static int
F_52 ( T_3 T_4 V_6 , T_5 * T_6 , int T_7 , T_8 * T_9 V_6 , T_10 * T_11 , int T_12 V_6 )
{
T_2 V_244 = NULL ;
T_3 V_381 = FALSE ;
struct V_150 * V_243 = NULL ;
if ( V_206 ) {
if ( ! V_254 ) {
V_243 = F_161 ( T_6 , T_9 -> V_36 , V_247 , V_54 ) ;
V_254 = TRUE ;
V_255 = V_243 ;
V_83 . V_141 = V_243 ;
} else {
V_243 = V_255 ;
V_83 . V_141 = V_243 ;
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
if ( ( V_244 = F_8 ( T_9 -> V_36 -> V_382 ) ) ) {
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
V_381 = TRUE ;
}
if ( ! V_381 && V_383 ) {
V_381 = TRUE ;
V_244 = V_383 ;
}
if ( ! V_381 ) {
if ( V_257 && V_82 ) {
if ( ( V_244
= F_171 ( V_257 , V_82 ) ) ) {
V_381 = TRUE ;
} else {
if ( ( V_244
= F_8 ( T_9 -> V_36 -> V_382 ) ) ) {
V_381 = TRUE ;
} else {
V_244 = V_260 ;
V_381 = TRUE ;
}
}
} else {
if ( ( V_244 = F_8 ( T_9 -> V_36 -> V_382 ) ) ) {
V_381 = TRUE ;
} else {
V_244 = V_260 ;
V_381 = TRUE ;
}
}
} else {
}
if ( V_381 ) {
F_198 ( V_244 , T_6 , T_9 -> V_36 , T_11 , T_9 -> V_253 ) ;
F_199 ( T_9 -> V_36 -> V_56 , V_57 ) ;
}
return T_7 ;
}
void
F_200 ( T_2 V_384 , T_5 * T_6 , T_16 * V_36 , T_10 * T_11 )
{
V_383 = V_384 ;
F_49 {
F_164 ( T_6 , V_36 , T_11 ) ;
} F_201 {
V_383 = NULL ;
V_385 ;
} V_41 ;
V_383 = NULL ;
}
