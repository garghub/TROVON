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
V_29 = F_48 ( T_6 , T_7 , V_33 + V_34 - T_7 , V_33 + V_34 - T_7 ) ;
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
T_16 * V_49 ;
T_10 * V_50 ;
V_49 = F_60 ( T_11 , T_6 , T_7 , - 1 , L_2 ) ;
V_50 = F_61 ( V_49 , V_51 ) ;
F_58 ( T_4 , T_9 , V_50 , T_6 , T_7 , V_52 , NULL ) ;
F_62 ( T_9 -> V_53 ) ;
T_7 = F_58 ( T_4 , T_9 , V_50 , T_6 , T_7 , V_54 ,
& V_47 ) ;
if ( V_47 ) {
V_33 = F_63 ( V_47 , 0 ) ;
switch( V_33 ) {
case 1 :
V_55 -> V_56 = F_64 ( V_47 , 0 ) ;
break;
case 2 :
V_55 -> V_56 = F_65 ( V_47 , 0 ) ;
break;
case 4 :
V_55 -> V_56 = F_66 ( V_47 , 0 ) ;
break;
default:
V_55 -> V_56 = 0 ;
break;
}
if ( V_33 ) {
F_67 ( T_9 -> V_36 -> V_57 , V_58 , L_3 ) ;
for( V_48 = 0 ; V_48 < V_33 ; V_48 ++ )
F_68 ( T_9 -> V_36 -> V_57 , V_58 , L_4 , F_64 ( V_47 , V_48 ) ) ;
F_67 ( T_9 -> V_36 -> V_57 , V_58 , L_5 ) ;
}
}
return T_7 ;
}
static int
F_69 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 204 "../../asn1/tcap/tcap.cnf"
V_55 -> V_59 = V_60 ;
F_70 ( T_9 -> V_36 -> V_57 , V_58 , L_6 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_61 , T_12 , V_62 ) ;
return T_7 ;
}
static int
F_71 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 167 "../../asn1/tcap/tcap.cnf"
T_5 * V_47 ;
T_15 V_33 , V_48 ;
T_16 * V_49 ;
T_10 * V_50 ;
V_49 = F_60 ( T_11 , T_6 , T_7 , - 1 , L_7 ) ;
V_50 = F_61 ( V_49 , V_63 ) ;
F_58 ( T_4 , T_9 , V_50 , T_6 , T_7 , V_52 , NULL ) ;
F_62 ( T_9 -> V_53 ) ;
T_7 = F_58 ( T_4 , T_9 , V_50 , T_6 , T_7 , V_64 ,
& V_47 ) ;
if ( V_47 ) {
V_33 = F_63 ( V_47 , 0 ) ;
switch( V_33 ) {
case 1 :
V_55 -> V_65 = F_64 ( V_47 , 0 ) ;
break;
case 2 :
V_55 -> V_65 = F_65 ( V_47 , 0 ) ;
break;
case 4 :
V_55 -> V_65 = F_66 ( V_47 , 0 ) ;
break;
default:
V_55 -> V_65 = 0 ;
break;
}
if ( V_33 ) {
F_67 ( T_9 -> V_36 -> V_57 , V_58 , L_8 ) ;
for( V_48 = 0 ; V_48 < V_33 ; V_48 ++ )
F_68 ( T_9 -> V_36 -> V_57 , V_58 , L_4 , F_64 ( V_47 , V_48 ) ) ;
F_67 ( T_9 -> V_36 -> V_57 , V_58 , L_5 ) ;
}
}
return T_7 ;
}
static int
F_72 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 218 "../../asn1/tcap/tcap.cnf"
V_55 -> V_59 = V_66 ;
F_70 ( T_9 -> V_36 -> V_57 , V_58 , L_9 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_67 , T_12 , V_68 ) ;
return T_7 ;
}
static int
F_73 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 225 "../../asn1/tcap/tcap.cnf"
V_55 -> V_59 = V_69 ;
F_70 ( T_9 -> V_36 -> V_57 , V_58 , L_10 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_70 , T_12 , V_71 ) ;
return T_7 ;
}
static int
F_74 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_75 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 10 , TRUE , F_74 ) ;
return T_7 ;
}
static int
F_76 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_72 , T_12 , V_73 ,
NULL ) ;
return T_7 ;
}
static int
F_77 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 232 "../../asn1/tcap/tcap.cnf"
V_55 -> V_59 = V_74 ;
F_70 ( T_9 -> V_36 -> V_57 , V_58 , L_11 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_75 , T_12 , V_76 ) ;
return T_7 ;
}
static int
F_78 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_77 , T_12 , V_78 ,
NULL ) ;
return T_7 ;
}
static int
F_79 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_79 , T_12 , V_80 ,
NULL ) ;
return T_7 ;
}
static int
F_80 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_81 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_81 , T_12 , V_82 ,
NULL ) ;
return T_7 ;
}
static int
F_82 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 111 "../../asn1/tcap/tcap.cnf"
T_7 = F_83 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_83 ) ;
V_84 . V_85 = ( const void * ) V_83 ;
V_84 . V_86 = TRUE ;
return T_7 ;
}
static int
F_84 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_85 ( T_4 , T_11 , T_6 , T_7 , T_9 , T_12 , NULL ) ;
return T_7 ;
}
static int
F_86 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_87 , T_12 , V_88 ) ;
return T_7 ;
}
static int
F_87 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_89 , T_12 , V_90 ) ;
return T_7 ;
}
static int
F_88 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 0 , TRUE , F_87 ) ;
return T_7 ;
}
int
F_89 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_91 , T_12 , V_92 ,
NULL ) ;
return T_7 ;
}
static int
F_90 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_81 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_93 , T_12 , V_94 ,
NULL ) ;
return T_7 ;
}
static int
F_91 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 116 "../../asn1/tcap/tcap.cnf"
T_7 = F_83 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_83 ) ;
V_84 . V_85 = ( const void * ) V_83 ;
V_84 . V_86 = TRUE ;
return T_7 ;
}
static int
F_92 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_95 , T_12 , V_96 ) ;
return T_7 ;
}
static int
F_93 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_97 , T_12 , V_98 ) ;
return T_7 ;
}
static int
F_94 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 0 , TRUE , F_93 ) ;
return T_7 ;
}
static int
F_95 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_81 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_99 , T_12 , V_100 ,
NULL ) ;
return T_7 ;
}
static int
F_96 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 121 "../../asn1/tcap/tcap.cnf"
T_7 = F_83 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_83 ) ;
V_84 . V_85 = ( const void * ) V_83 ;
V_84 . V_86 = TRUE ;
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
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_100 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_101 , T_12 , V_102 ,
NULL ) ;
return T_7 ;
}
static int
F_101 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_103 , T_12 , V_104 ) ;
return T_7 ;
}
static int
F_102 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_105 , T_12 , V_106 ) ;
return T_7 ;
}
static int
F_103 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 1 , TRUE , F_102 ) ;
return T_7 ;
}
static int
F_104 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_105 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_107 , T_12 , V_108 ) ;
return T_7 ;
}
static int
F_106 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_109 , T_12 , V_110 ) ;
return T_7 ;
}
static int
F_107 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 4 , TRUE , F_106 ) ;
return T_7 ;
}
int
F_16 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_111 , T_12 , V_112 ,
NULL ) ;
return T_7 ;
}
static void F_108 ( T_5 * T_6 V_6 , T_17 * V_36 V_6 , T_10 * T_11 V_6 ) {
T_8 V_113 ;
F_109 ( & V_113 , V_114 , TRUE , V_36 ) ;
F_89 ( FALSE , T_6 , 0 , & V_113 , T_11 , V_115 ) ;
}
static void F_110 ( T_5 * T_6 V_6 , T_17 * V_36 V_6 , T_10 * T_11 V_6 ) {
T_8 V_113 ;
F_109 ( & V_113 , V_114 , TRUE , V_36 ) ;
F_16 ( FALSE , T_6 , 0 , & V_113 , T_11 , V_116 ) ;
}
static void
F_111 ( T_18 V_117 , char * V_118 , ... )
{
T_19 V_119 ;
if ( V_117 > V_120 ) return;
va_start ( V_119 , V_118 ) ;
vfprintf ( V_121 , V_118 , V_119 ) ;
va_end ( V_119 ) ;
}
static T_14
F_112 ( T_20 V_122 , T_20 V_123 )
{
const struct V_124 * V_125 = ( const struct V_124 * ) V_122 ;
const struct V_124 * V_126 = ( const struct V_124 * ) V_123 ;
return ( V_125 -> V_127 == V_126 -> V_127 ) ;
}
static T_18
F_113 ( T_20 V_128 )
{
const struct V_124 * V_129 = ( const struct V_124 * ) V_128 ;
return V_129 -> V_127 ;
}
static T_14
F_114 ( T_20 V_122 , T_20 V_123 )
{
const struct V_130 * V_125 = ( const struct V_130 * ) V_122 ;
const struct V_130 * V_126 = ( const struct V_130 * ) V_123 ;
if ( V_125 -> V_131 == V_126 -> V_131 ) {
if ( ( ( V_125 -> V_132 == V_126 -> V_132 ) &&
( V_125 -> V_133 == V_126 -> V_133 ) &&
( V_125 -> V_134 == V_126 -> V_134 ) )
||
( ( V_125 -> V_132 == V_126 -> V_133 ) &&
( V_125 -> V_133 == V_126 -> V_132 ) &&
( V_125 -> V_134 == V_126 -> V_134 ) )
)
return TRUE ;
}
return FALSE ;
}
static T_18
F_115 ( T_20 V_128 )
{
const struct V_130 * V_129 = ( const struct V_130 * ) V_128 ;
T_18 V_135 ;
V_135 = V_129 -> V_134 ;
return V_135 ;
}
static T_14
F_116 ( T_20 V_122 , T_20 V_123 )
{
const struct V_136 * V_125 = ( const struct V_136 * ) V_122 ;
const struct V_136 * V_126 = ( const struct V_136 * ) V_123 ;
if ( V_125 -> V_131 == V_126 -> V_131 ) {
if ( ( V_125 -> V_132 == V_126 -> V_132 ) &&
( V_125 -> V_133 == V_126 -> V_133 ) &&
( V_125 -> V_56 == V_126 -> V_56 ) &&
( V_125 -> V_65 == V_126 -> V_65 ) ) {
return TRUE ;
}
else if ( ( V_125 -> V_132 == V_126 -> V_133 ) &&
( V_125 -> V_133 == V_126 -> V_132 ) &&
( V_125 -> V_56 == V_126 -> V_65 ) &&
( V_125 -> V_65 == V_126 -> V_56 ) ) {
return TRUE ;
}
}
return FALSE ;
}
static T_18
F_117 ( T_20 V_128 )
{
const struct V_136 * V_129 = ( const struct V_136 * ) V_128 ;
T_18 V_135 ;
V_135 = V_129 -> V_56 + V_129 -> V_65 ;
return V_135 ;
}
static T_14
F_118 ( T_20 V_122 , T_20 V_123 )
{
const struct V_137 * V_125 = ( const struct V_137 * ) V_122 ;
const struct V_137 * V_126 = ( const struct V_137 * ) V_123 ;
if ( V_125 -> V_131 == V_126 -> V_131 ) {
if ( ( ( V_125 -> V_132 == V_126 -> V_132 ) &&
( V_125 -> V_133 == V_126 -> V_133 ) &&
( V_125 -> V_134 == V_126 -> V_134 ) )
||
( ( V_125 -> V_132 == V_126 -> V_133 ) &&
( V_125 -> V_133 == V_126 -> V_132 ) &&
( V_125 -> V_134 == V_126 -> V_134 ) ) )
return TRUE ;
}
return FALSE ;
}
static T_18
F_119 ( T_20 V_128 )
{
const struct V_137 * V_129 = ( const struct V_137 * ) V_128 ;
T_18 V_135 ;
V_135 = V_129 -> V_134 ;
return V_135 ;
}
static T_14
F_120 ( T_20 V_122 , T_20 V_123 )
{
const struct V_138 * V_125 = ( const struct V_138 * ) V_122 ;
const struct V_138 * V_126 = ( const struct V_138 * ) V_123 ;
if ( V_125 -> V_131 == V_126 -> V_131 ) {
if ( ( ( V_125 -> V_132 == V_126 -> V_132 ) &&
( V_125 -> V_133 == V_126 -> V_133 ) &&
( V_125 -> V_134 == V_126 -> V_134 ) )
||
( ( V_125 -> V_132 == V_126 -> V_133 ) &&
( V_125 -> V_133 == V_126 -> V_132 ) &&
( V_125 -> V_134 == V_126 -> V_134 ) )
)
return TRUE ;
}
return FALSE ;
}
static T_18
F_121 ( T_20 V_128 )
{
const struct V_138 * V_129 = ( const struct V_138 * ) V_128 ;
T_18 V_135 ;
V_135 = V_129 -> V_134 ;
return V_135 ;
}
static void
F_122 ( struct V_139 * V_140 ,
T_17 * V_36 )
{
V_140 -> V_141 -> V_142 = V_36 -> V_143 -> V_144 ;
V_140 -> V_141 -> V_145 = 0 ;
V_140 -> V_141 -> V_146 = FALSE ;
V_140 -> V_141 -> V_147 = V_36 -> V_143 -> V_148 ;
}
static struct V_139 *
F_123 ( struct V_139 * V_149 ,
struct V_150 * V_151 ,
T_17 * V_36 )
{
struct V_139 * V_152 = NULL ;
#ifdef F_124
V_152 = (struct V_139 * ) F_125 ( sizeof( struct V_139 ) ) ;
#else
V_152 = F_126 ( struct V_139 ) ;
#endif
V_152 -> V_141 = V_151 ;
V_151 -> V_153 = V_152 ;
V_152 -> V_154 = V_149 -> V_154 ;
V_152 -> V_141 -> V_142 = V_36 -> V_143 -> V_144 ;
V_152 -> V_155 = NULL ;
V_152 -> V_156 = V_149 ;
V_152 -> V_157 = FALSE ;
#ifdef F_127
F_111 ( 10 , L_12 , V_152 -> V_141 -> V_127 ) ;
#endif
V_149 -> V_155 = V_152 ;
if ( V_149 -> V_141 -> V_145 == 0 ) {
#ifdef F_127
F_111 ( 10 , L_13 ) ;
#endif
V_149 -> V_141 -> V_145 = V_36 -> V_143 -> V_144 - 1 ;
}
return V_152 ;
}
static void
F_128 ( struct V_158 * V_159 ,
T_17 * V_36 )
{
V_159 -> V_141 -> V_142 = V_36 -> V_143 -> V_144 ;
V_159 -> V_141 -> V_145 = 0 ;
V_159 -> V_141 -> V_146 = FALSE ;
V_159 -> V_141 -> V_147 = V_36 -> V_143 -> V_148 ;
}
static struct V_158 *
F_129 ( struct V_158 * V_160 ,
struct V_150 * V_151 ,
T_17 * V_36 )
{
struct V_158 * V_161 = NULL ;
#ifdef F_124
V_161 = (struct V_158 * ) F_125 ( sizeof( struct V_158 ) ) ;
#else
V_161 = F_126 ( struct V_158 ) ;
#endif
V_161 -> V_141 = V_151 ;
V_151 -> V_162 = V_161 ;
V_161 -> V_163 = V_160 -> V_163 ;
V_161 -> V_141 -> V_142 = V_36 -> V_143 -> V_144 ;
V_161 -> V_164 = NULL ;
V_161 -> V_165 = V_160 ;
V_161 -> V_157 = FALSE ;
#ifdef F_127
F_111 ( 10 , L_14 , V_161 -> V_141 -> V_127 ) ;
#endif
V_160 -> V_164 = V_161 ;
if ( V_160 -> V_141 -> V_145 == 0 ) {
#ifdef F_127
F_111 ( 10 , L_13 ) ;
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
#ifdef F_124
V_168 = (struct V_166 * ) F_125 ( sizeof( struct V_166 ) ) ;
#else
V_168 = F_126 ( struct V_166 ) ;
#endif
V_168 -> V_141 = V_151 ;
V_151 -> V_169 = V_168 ;
V_168 -> V_170 = V_167 -> V_170 ;
V_168 -> V_171 = NULL ;
V_168 -> V_172 = V_167 ;
V_168 -> V_157 = FALSE ;
#ifdef F_127
F_111 ( 10 , L_15 , V_168 -> V_141 -> V_127 ) ;
#endif
V_167 -> V_171 = V_168 ;
return V_168 ;
}
static struct V_173 *
F_131 ( struct V_173 * V_174 ,
struct V_150 * V_151 )
{
struct V_173 * V_175 = NULL ;
#ifdef F_124
V_175 = (struct V_176 * ) F_125 ( sizeof( struct V_173 ) ) ;
#else
V_175 = F_126 ( struct V_173 ) ;
#endif
V_175 -> V_141 = V_151 ;
V_151 -> V_177 = V_175 ;
V_175 -> V_178 = V_174 -> V_178 ;
V_175 -> V_179 = NULL ;
V_175 -> V_180 = V_174 ;
V_175 -> V_157 = FALSE ;
#ifdef F_127
F_111 ( 10 , L_16 , V_175 -> V_141 -> V_127 ) ;
#endif
V_174 -> V_179 = V_175 ;
return V_175 ;
}
static struct V_139 *
F_132 ( struct V_130 * V_181 ,
T_17 * V_36 , T_3 V_182 )
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
F_111 ( 10 , L_17 , V_140 -> V_141 -> V_127 ) ;
#endif
return V_140 ;
}
#ifdef F_127
F_111 ( 60 , L_18 , V_140 -> V_141 -> V_127 ) ;
#endif
}
if( V_140 -> V_155 == NULL ) {
#ifdef F_127
F_111 ( 23 , L_19 ) ;
#endif
break;
}
V_140 = V_140 -> V_155 ;
} while ( V_140 != NULL ) ;
} else {
#ifdef F_127
F_111 ( 23 , L_20 ) ;
#endif
}
return NULL ;
}
static struct V_166 *
F_133 ( struct V_136 * V_184 ,
T_17 * V_36 )
{
struct V_166 * V_185 = NULL ;
V_185 = (struct V_166 * ) F_12 ( V_186 , V_184 ) ;
if( V_185 ) {
do {
if ( V_185 -> V_141 ) {
if ( V_36 -> V_143 -> V_144 >= V_185 -> V_141 -> V_142 &&
( V_185 -> V_141 -> V_145 ? V_36 -> V_143 -> V_144 <= V_185 -> V_141 -> V_145 : 1 ) ) {
#ifdef F_127
F_111 ( 10 , L_21 , V_185 -> V_141 -> V_127 ) ;
#endif
return V_185 ;
}
#ifdef F_127
F_111 ( 60 , L_22 , V_185 -> V_141 -> V_127 ) ;
#endif
}
if( V_185 -> V_171 == NULL ) {
#ifdef F_127
F_111 ( 23 , L_23 ) ;
#endif
break;
}
V_185 = V_185 -> V_171 ;
} while ( V_185 != NULL ) ;
} else {
#ifdef F_127
F_111 ( 23 , L_24 ) ;
#endif
}
return NULL ;
}
static struct V_173 *
F_134 ( struct V_137 * V_187 ,
T_17 * V_36 , T_3 V_188 )
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
F_111 ( 10 , L_25 , V_189 -> V_141 -> V_127 ) ;
#endif
return V_189 ;
}
#ifdef F_127
F_111 ( 60 , L_26 , V_189 -> V_141 -> V_127 ) ;
#endif
}
if( V_189 -> V_179 == NULL ) {
#ifdef F_127
F_111 ( 23 , L_27 ) ;
#endif
break;
}
V_189 = V_189 -> V_179 ;
} while ( V_189 != NULL ) ;
} else {
#ifdef F_127
F_111 ( 23 , L_28 ) ;
#endif
}
return NULL ;
}
static struct V_150 *
F_135 ( struct V_124 * V_191 ,
T_17 * V_36 )
{
struct V_124 * V_192 ;
struct V_150 * V_193 = NULL ;
#ifdef F_124
V_192 = (struct V_124 * ) F_136 ( sizeof( struct V_124 ) ) ;
#else
V_192 = F_137 ( struct V_124 ) ;
#endif
V_192 -> V_127 = V_191 -> V_127 ;
#ifdef F_124
V_193 = (struct V_150 * ) F_125 ( sizeof( struct V_150 ) ) ;
#else
V_193 = F_126 ( struct V_150 ) ;
#endif
V_193 -> V_129 = V_192 ;
V_193 -> V_127 = V_191 -> V_127 ;
V_193 -> V_142 = V_36 -> V_143 -> V_144 ;
#ifdef F_127
F_111 ( 10 , L_29 , V_193 -> V_127 ) ;
#endif
F_2 ( V_194 , V_192 , V_193 ) ;
return V_193 ;
}
static struct V_139 *
F_138 ( struct V_130 * V_181 ,
struct V_150 * V_151 )
{
struct V_130 * V_195 ;
struct V_139 * V_152 = NULL ;
#ifdef F_124
V_195 = (struct V_130 * ) F_136 ( sizeof( struct V_130 ) ) ;
#else
V_195 = F_137 ( struct V_130 ) ;
#endif
V_195 -> V_131 = V_181 -> V_131 ;
V_195 -> V_134 = V_181 -> V_134 ;
V_195 -> V_132 = V_181 -> V_132 ;
V_195 -> V_133 = V_181 -> V_133 ;
#ifdef F_124
V_152 = (struct V_139 * ) F_125 ( sizeof( struct V_139 ) ) ;
#else
V_152 = F_126 ( struct V_139 ) ;
#endif
V_152 -> V_154 = V_195 ;
V_152 -> V_141 = V_151 ;
V_151 -> V_153 = V_152 ;
V_152 -> V_157 = TRUE ;
V_152 -> V_155 = NULL ;
V_152 -> V_156 = NULL ;
#ifdef F_127
F_111 ( 10 , L_17 , V_152 -> V_141 -> V_127 ) ;
#endif
F_2 ( V_183 , V_195 , V_152 ) ;
return V_152 ;
}
static struct V_166 *
F_139 ( struct V_136 * V_184 ,
struct V_150 * V_151 )
{
struct V_136 * V_196 ;
struct V_166 * V_168 = NULL ;
#ifdef F_124
V_196 = (struct V_136 * ) F_136 ( sizeof( struct V_136 ) ) ;
#else
V_196 = F_137 ( struct V_136 ) ;
#endif
V_196 -> V_131 = V_184 -> V_131 ;
V_196 -> V_56 = V_184 -> V_56 ;
V_196 -> V_65 = V_184 -> V_65 ;
V_196 -> V_132 = V_184 -> V_132 ;
V_196 -> V_133 = V_184 -> V_133 ;
#ifdef F_124
V_168 = (struct V_166 * ) F_125 ( sizeof( struct V_166 ) ) ;
#else
V_168 = F_126 ( struct V_166 ) ;
#endif
V_168 -> V_170 = V_196 ;
V_168 -> V_141 = V_151 ;
V_151 -> V_169 = V_168 ;
V_168 -> V_157 = TRUE ;
V_168 -> V_171 = NULL ;
V_168 -> V_172 = NULL ;
#ifdef F_127
F_111 ( 10 , L_21 , V_168 -> V_141 -> V_127 ) ;
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
#ifdef F_124
V_197 = (struct V_137 * ) F_136 ( sizeof( struct V_137 ) ) ;
#else
V_197 = F_137 ( struct V_137 ) ;
#endif
V_197 -> V_131 = V_187 -> V_131 ;
V_197 -> V_134 = V_187 -> V_134 ;
V_197 -> V_132 = V_187 -> V_132 ;
V_197 -> V_133 = V_187 -> V_133 ;
#ifdef F_124
V_175 = (struct V_173 * ) F_125 ( sizeof( struct V_173 ) ) ;
#else
V_175 = F_126 ( struct V_173 ) ;
#endif
V_175 -> V_178 = V_197 ;
V_175 -> V_141 = V_151 ;
V_151 -> V_177 = V_175 ;
V_175 -> V_157 = TRUE ;
V_175 -> V_179 = NULL ;
V_175 -> V_180 = NULL ;
#ifdef F_127
F_111 ( 10 , L_25 , V_175 -> V_141 -> V_127 ) ;
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
#ifdef F_124
V_199 = (struct V_138 * ) F_136 ( sizeof( struct V_138 ) ) ;
#else
V_199 = F_137 ( struct V_138 ) ;
#endif
V_199 -> V_131 = V_198 -> V_131 ;
V_199 -> V_134 = V_198 -> V_134 ;
V_199 -> V_132 = V_198 -> V_132 ;
V_199 -> V_133 = V_198 -> V_133 ;
#ifdef F_124
V_161 = (struct V_158 * ) F_125 ( sizeof( struct V_158 ) ) ;
#else
V_161 = F_126 ( struct V_158 ) ;
#endif
V_161 -> V_163 = V_199 ;
V_161 -> V_141 = V_151 ;
V_151 -> V_162 = V_161 ;
V_161 -> V_157 = TRUE ;
V_161 -> V_164 = NULL ;
V_161 -> V_165 = NULL ;
#ifdef F_127
F_111 ( 10 , L_30 , V_161 -> V_141 -> V_127 ) ;
#endif
F_2 ( V_200 , V_199 , V_161 ) ;
return V_161 ;
}
static struct V_166 *
F_142 ( struct V_136 * V_184 ,
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
F_111 ( 16 , L_31 ) ;
#endif
F_145 ( V_194 ) ;
}
if ( V_183 != NULL ) {
#ifdef F_127
F_111 ( 16 , L_32 ) ;
#endif
F_145 ( V_183 ) ;
}
if ( V_186 != NULL ) {
#ifdef F_127
F_111 ( 16 , L_33 ) ;
#endif
F_145 ( V_186 ) ;
}
if ( V_190 != NULL ) {
#ifdef F_127
F_111 ( 16 , L_34 ) ;
#endif
F_145 ( V_190 ) ;
}
if ( V_200 != NULL ) {
#ifdef F_127
F_111 ( 16 , L_35 ) ;
#endif
F_145 ( V_200 ) ;
}
#ifdef F_127
F_111 ( 16 , L_36 ) ;
#endif
V_194 = F_146 ( F_113 , F_112 ) ;
V_183 = F_146 ( F_115 , F_114 ) ;
V_186 = F_146 ( F_117 , F_116 ) ;
V_190 = F_146 ( F_119 , F_118 ) ;
V_200 = F_146 ( F_121 , F_120 ) ;
V_203 = 1 ;
V_204 = V_205 || V_206 & V_207 ;
}
static struct V_150 *
F_147 ( T_5 * T_6 , T_17 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_151 = NULL ;
struct V_124 V_210 ;
struct V_139 * V_140 , * V_152 = NULL ;
struct V_130 V_211 ;
T_16 * V_212 ;
T_16 * V_213 = NULL ;
T_10 * V_214 = NULL ;
V_211 . V_134 = V_209 -> V_56 ;
if ( V_36 -> V_215 . type == V_216 && V_36 -> V_217 . type == V_216 )
{
V_211 . V_132 = F_148 ( ( const V_218 * ) V_36 -> V_215 . V_219 ) ;
V_211 . V_133 = F_148 ( ( const V_218 * ) V_36 -> V_217 . V_219 ) ;
} else {
V_211 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_215 ) ) ;
V_211 . V_133 = F_149 ( F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
}
V_211 . V_131 = F_115 ( & V_211 ) ;
#ifdef F_127
F_111 ( 10 , L_37 , V_36 -> V_143 -> V_144 ) ;
F_111 ( 11 , L_38 , V_211 . V_131 ) ;
F_111 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_215 ) , F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
F_111 ( 51 , L_40 , V_211 . V_134 ) ;
#endif
V_140 = (struct V_139 * )
F_12 ( V_183 , & V_211 ) ;
if ( V_140 ) {
do {
if ( V_36 -> V_143 -> V_144 == V_140 -> V_141 -> V_142 ) {
#ifdef F_127
F_111 ( 22 , L_41 ) ;
#endif
V_151 = V_140 -> V_141 ;
break;
}
if ( ! V_140 -> V_155 ) {
if ( ( V_140 -> V_141 -> V_145 != 0
&& V_36 -> V_143 -> V_144 > V_140 -> V_141 -> V_142
&& ( T_18 ) V_36 -> V_143 -> V_148 . V_220 > ( T_18 ) ( V_140 -> V_141 -> V_147 . V_220 + V_221 )
) ||
( V_140 -> V_141 -> V_145 == 0
&& V_36 -> V_143 -> V_144 > V_140 -> V_141 -> V_142
&& ( T_18 ) V_36 -> V_143 -> V_148 . V_220 > ( T_18 ) ( V_140 -> V_141 -> V_147 . V_220 + V_222 )
)
)
{
#ifdef F_127
F_111 ( 12 , L_42 , V_211 . V_131 ) ;
F_111 ( 12 , L_43 , V_36 -> V_143 -> V_144 , V_140 -> V_141 -> V_145 ) ;
#endif
V_210 . V_127 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_152 = F_123 ( V_140 ,
V_151 ,
V_36 ) ;
#ifdef F_127
F_111 ( 12 , L_44 , V_211 . V_131 ) ;
#endif
F_122 ( V_152 , V_36 ) ;
} else {
if ( V_140 -> V_141 -> V_223 ) {
#ifdef F_127
F_111 ( 12 , L_45 , V_211 . V_131 ) ;
F_111 ( 12 , L_43 , V_36 -> V_143 -> V_144 , V_140 -> V_141 -> V_145 ) ;
#endif
V_210 . V_127 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_152 = F_123 ( V_140 ,
V_151 ,
V_36 ) ;
#ifdef F_127
F_111 ( 12 , L_46 , V_211 . V_131 ) ;
#endif
F_122 ( V_152 , V_36 ) ;
} else {
#ifdef F_127
F_111 ( 21 , L_47 , V_140 -> V_141 -> V_142 ) ;
#endif
V_151 = V_140 -> V_141 ;
if ( V_204 && T_11 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , L_48 ) ;
F_152 ( V_213 ) ;
V_214 = F_61 ( V_213 , V_224 ) ;
V_212 = F_153 ( V_214 , V_225 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_49 ,
V_151 -> V_127 , V_151 -> V_142 ) ;
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
F_111 ( 10 , L_50 , V_211 . V_131 ) ;
#endif
V_210 . V_127 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_140 = F_138 ( & V_211 , V_151 ) ;
#ifdef F_127
F_111 ( 11 , L_44 , V_211 . V_131 ) ;
F_111 ( 11 , L_51 , V_36 -> V_143 -> V_144 ) ;
#endif
F_122 ( V_140 , V_36 ) ;
}
if ( V_204 && T_11 &&
V_151 &&
V_151 -> V_127 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , 0 , L_48 ) ;
F_152 ( V_213 ) ;
V_214 = F_61 ( V_213 , V_224 ) ;
V_212 = F_154 ( V_214 , V_226 , T_6 , 0 , 0 , V_151 -> V_127 ) ;
F_152 ( V_212 ) ;
if( V_151 -> V_145 != 0 ) {
#ifdef F_127
F_111 ( 20 , L_52 , V_151 -> V_145 ) ;
#endif
V_212 = F_153 ( V_214 , V_227 , T_6 , 0 , 0 ,
V_151 -> V_145 ,
L_53 ,
V_151 -> V_145 ) ;
F_152 ( V_212 ) ;
}
}
return V_151 ;
}
static struct V_150 *
F_155 ( T_5 * T_6 , T_17 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_151 = NULL ;
struct V_166 * V_185 ;
struct V_136 V_228 ;
struct V_130 V_211 ;
struct V_139 * V_140 ;
struct V_137 V_229 ;
T_16 * V_212 ;
T_16 * V_213 = NULL ;
T_10 * V_214 = NULL ;
#ifdef F_127
F_111 ( 10 , L_54 , V_36 -> V_143 -> V_144 ) ;
#endif
V_228 . V_56 = V_209 -> V_56 ;
V_228 . V_65 = V_209 -> V_65 ;
if ( V_36 -> V_215 . type == V_216 && V_36 -> V_217 . type == V_216 )
{
V_228 . V_132 = F_148 ( ( const V_218 * ) V_36 -> V_215 . V_219 ) ;
V_228 . V_133 = F_148 ( ( const V_218 * ) V_36 -> V_217 . V_219 ) ;
} else {
V_228 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_215 ) ) ;
V_228 . V_133 = F_149 ( F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
}
V_228 . V_131 = F_117 ( & V_228 ) ;
#ifdef F_127
F_111 ( 11 , L_55 , V_228 . V_131 ) ;
F_111 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_215 ) , F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
F_111 ( 51 , L_56 , V_228 . V_56 , V_228 . V_65 ) ;
#endif
V_185 = F_133 ( & V_228 , V_36 ) ;
if( V_185 ) {
#ifdef F_127
F_111 ( 12 , L_57 ) ;
#endif
V_151 = V_185 -> V_141 ;
} else {
#ifdef F_127
F_111 ( 12 , L_58 ) ;
#endif
V_211 . V_134 = V_209 -> V_65 ;
if ( V_36 -> V_215 . type == V_216 && V_36 -> V_217 . type == V_216 )
{
V_211 . V_132 = F_148 ( ( const V_218 * ) V_36 -> V_215 . V_219 ) ;
V_211 . V_133 = F_148 ( ( const V_218 * ) V_36 -> V_217 . V_219 ) ;
} else {
V_211 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_215 ) ) ;
V_211 . V_133 = F_149 ( F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
}
V_211 . V_131 = F_115 ( & V_211 ) ;
#ifdef F_127
F_111 ( 11 , L_59 , V_211 . V_131 ) ;
F_111 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_215 ) , F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
F_111 ( 51 , L_40 , V_211 . V_134 ) ;
#endif
V_140 = F_132 ( & V_211 , V_36 , FALSE ) ;
if( ! V_140 ) {
V_211 . V_134 = V_209 -> V_56 ;
V_211 . V_131 = F_115 ( & V_211 ) ;
V_140 = F_132 ( & V_211 , V_36 , FALSE ) ;
}
if( V_140 &&
! V_140 -> V_141 -> V_169 ) {
#ifdef F_127
F_111 ( 12 , L_60 ) ;
#endif
V_151 = V_140 -> V_141 ;
V_151 -> V_146 = TRUE ;
#ifdef F_127
F_111 ( 10 , L_61 , V_228 . V_131 ) ;
F_111 ( 11 , L_62 , V_36 -> V_143 -> V_144 ) ;
#endif
F_142 ( & V_228 ,
V_140 -> V_141 ) ;
V_229 . V_134 = V_209 -> V_56 ;
if ( V_36 -> V_215 . type == V_216 && V_36 -> V_217 . type == V_216 )
{
V_229 . V_132 = F_148 ( ( const V_218 * ) V_36 -> V_215 . V_219 ) ;
V_229 . V_133 = F_148 ( ( const V_218 * ) V_36 -> V_217 . V_219 ) ;
} else {
V_229 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_215 ) ) ;
V_229 . V_133 = F_149 ( F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
}
V_229 . V_131 = F_119 ( & V_229 ) ;
#ifdef F_127
F_111 ( 10 , L_63 , V_229 . V_131 ) ;
F_111 ( 11 , L_51 , V_36 -> V_143 -> V_144 ) ;
#endif
F_143 ( & V_229 ,
V_140 -> V_141 ) ;
} else {
#ifdef F_127
F_111 ( 12 , L_64 ) ;
#endif
}
}
if ( V_204 && T_11 &&
V_151 &&
V_151 -> V_127 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , L_48 ) ;
F_152 ( V_213 ) ;
V_214 = F_61 ( V_213 , V_224 ) ;
V_212 = F_154 ( V_214 , V_226 , T_6 , 0 , 0 , V_151 -> V_127 ) ;
F_152 ( V_212 ) ;
}
return V_151 ;
}
static struct V_150 *
F_156 ( T_5 * T_6 , T_17 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_151 = NULL ;
struct V_137 V_229 ;
struct V_173 * V_189 = NULL ;
struct V_130 V_211 ;
struct V_139 * V_140 = NULL ;
T_16 * V_212 ;
T_21 V_230 ;
T_16 * V_213 = NULL ;
T_10 * V_214 = NULL ;
#ifdef F_127
F_111 ( 10 , L_65 , V_36 -> V_143 -> V_144 ) ;
#endif
V_229 . V_134 = V_209 -> V_65 ;
if ( V_36 -> V_215 . type == V_216 && V_36 -> V_217 . type == V_216 )
{
V_229 . V_132 = F_148 ( ( const V_218 * ) V_36 -> V_215 . V_219 ) ;
V_229 . V_133 = F_148 ( ( const V_218 * ) V_36 -> V_217 . V_219 ) ;
} else {
V_229 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_215 ) ) ;
V_229 . V_133 = F_149 ( F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
}
V_229 . V_131 = F_119 ( & V_229 ) ;
#ifdef F_127
F_111 ( 11 , L_66 , V_229 . V_131 ) ;
F_111 ( 11 , L_39 , F_150 ( F_151 () , & V_36 -> V_215 ) , F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
F_111 ( 51 , L_67 , V_229 . V_134 ) ;
#endif
V_189 = F_134 ( & V_229 , V_36 , TRUE ) ;
if( ! V_189 ) {
#ifdef F_127
F_111 ( 12 , L_68 ) ;
#endif
V_211 . V_134 = V_209 -> V_65 ;
if ( V_36 -> V_215 . type == V_216 && V_36 -> V_217 . type == V_216 )
{
V_211 . V_132 = F_148 ( ( const V_218 * ) V_36 -> V_215 . V_219 ) ;
V_211 . V_133 = F_148 ( ( const V_218 * ) V_36 -> V_217 . V_219 ) ;
} else {
V_211 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_215 ) ) ;
V_211 . V_133 = F_149 ( F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
}
V_211 . V_131 = F_115 ( & V_211 ) ;
#ifdef F_127
F_111 ( 11 , L_59 , V_211 . V_131 ) ;
F_111 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_215 ) , F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
F_111 ( 51 , L_67 , V_211 . V_134 ) ;
#endif
V_140 = F_132 ( & V_211 , V_36 , FALSE ) ;
if( ! V_140 ) {
#ifdef F_127
F_111 ( 12 , L_64 ) ;
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
F_111 ( 12 , L_69 , V_151 -> V_142 ) ;
#endif
if ( V_204 && T_11 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , L_48 ) ;
F_152 ( V_213 ) ;
V_214 = F_61 ( V_213 , V_224 ) ;
V_212 = F_154 ( V_214 , V_226 , T_6 , 0 , 0 , V_151 -> V_127 ) ;
F_152 ( V_212 ) ;
}
#ifdef F_127
F_111 ( 20 , L_70 , V_151 -> V_142 ) ;
#endif
if ( V_204 && V_214 ) {
V_212 = F_153 ( V_214 , V_231 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_71 ,
V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
F_157 ( & V_230 , & V_36 -> V_143 -> V_148 , & V_151 -> V_147 ) ;
V_212 = F_158 ( V_214 , V_232 , T_6 , 0 , 0 , & V_230 ) ;
F_152 ( V_212 ) ;
}
F_159 ( V_151 , V_36 ) ;
} else {
#ifdef F_127
F_111 ( 12 , L_72 ) ;
#endif
}
return V_151 ;
}
static struct V_150 *
F_160 ( T_5 * T_6 , T_17 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_151 = NULL ;
struct V_124 V_210 ;
struct V_158 * V_159 , * V_161 ;
struct V_138 V_233 ;
T_16 * V_212 ;
T_21 V_230 ;
T_3 V_234 = FALSE ;
T_10 * V_214 = NULL ;
T_16 * V_213 = NULL ;
V_233 . V_134 = V_209 -> V_56 ;
if ( V_36 -> V_215 . type == V_216 && V_36 -> V_217 . type == V_216 )
{
V_233 . V_132 = F_148 ( ( const V_218 * ) V_36 -> V_215 . V_219 ) ;
V_233 . V_133 = F_148 ( ( const V_218 * ) V_36 -> V_217 . V_219 ) ;
} else {
V_233 . V_132 = F_149 ( F_150 ( F_151 () , & V_36 -> V_215 ) ) ;
V_233 . V_133 = F_149 ( F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
}
V_233 . V_131 = F_121 ( & V_233 ) ;
#ifdef F_127
F_111 ( 10 , L_73 , V_36 -> V_143 -> V_144 ) ;
F_111 ( 11 , L_38 , V_233 . V_131 ) ;
F_111 ( 51 , L_39 , F_150 ( F_151 () , & V_36 -> V_215 ) , F_150 ( F_151 () , & V_36 -> V_217 ) ) ;
F_111 ( 51 , L_67 , V_233 . V_134 ) ;
#endif
V_159 = (struct V_158 * )
F_12 ( V_200 , & V_233 ) ;
if ( V_159 ) {
do {
if ( V_36 -> V_143 -> V_144 == V_159 -> V_141 -> V_142 ) {
#ifdef F_127
F_111 ( 22 , L_74 ) ;
#endif
V_234 = FALSE ;
V_151 = V_159 -> V_141 ;
break;
}
if ( V_36 -> V_143 -> V_144 == V_159 -> V_141 -> V_145 ) {
#ifdef F_127
F_111 ( 22 , L_75 ) ;
#endif
V_234 = TRUE ;
V_151 = V_159 -> V_141 ;
break;
}
if ( V_36 -> V_143 -> V_144 > V_159 -> V_141 -> V_142 &&
V_159 -> V_141 -> V_145 == 0 ) {
#ifdef F_127
F_111 ( 12 , L_44 , V_233 . V_131 ) ;
#endif
V_159 -> V_141 -> V_145 = V_36 -> V_143 -> V_144 ;
V_159 -> V_141 -> V_146 = TRUE ;
V_159 -> V_141 -> V_223 = TRUE ;
V_151 = V_159 -> V_141 ;
V_234 = TRUE ;
if ( V_204 && T_11 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , L_48 ) ;
F_152 ( V_213 ) ;
V_214 = F_61 ( V_213 , V_224 ) ;
V_212 = F_154 ( V_214 , V_226 , T_6 , 0 , 0 , V_151 -> V_127 ) ;
F_152 ( V_212 ) ;
#ifdef F_127
F_111 ( 20 , L_70 , V_151 -> V_142 ) ;
#endif
V_212 = F_153 ( V_214 , V_231 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_71 ,
V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
F_157 ( & V_230 , & V_36 -> V_143 -> V_148 , & V_151 -> V_147 ) ;
V_212 = F_158 ( V_214 , V_232 , T_6 , 0 , 0 , & V_230 ) ;
F_152 ( V_212 ) ;
}
break;
}
if ( ! V_159 -> V_164 ) {
if ( ( V_159 -> V_141 -> V_145 != 0
&& V_36 -> V_143 -> V_144 > V_159 -> V_141 -> V_142
&& ( T_18 ) V_36 -> V_143 -> V_148 . V_220 > ( T_18 ) ( V_159 -> V_141 -> V_147 . V_220 + V_221 )
) ||
( V_159 -> V_141 -> V_145 == 0
&& V_36 -> V_143 -> V_144 > V_159 -> V_141 -> V_142
&& ( T_18 ) V_36 -> V_143 -> V_148 . V_220 > ( T_18 ) ( V_159 -> V_141 -> V_147 . V_220 + V_222 )
)
)
{
#ifdef F_127
F_111 ( 12 , L_42 , V_233 . V_131 ) ;
F_111 ( 12 , L_43 , V_36 -> V_143 -> V_144 , V_159 -> V_141 -> V_145 ) ;
#endif
V_210 . V_127 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_161 = F_129 ( V_159 ,
V_151 ,
V_36 ) ;
#ifdef F_127
F_111 ( 12 , L_44 , V_233 . V_131 ) ;
#endif
F_128 ( V_161 , V_36 ) ;
V_159 = V_161 ;
} else {
if ( V_159 -> V_141 -> V_223 ) {
#ifdef F_127
F_111 ( 12 , L_45 , V_233 . V_131 ) ;
F_111 ( 12 , L_43 , V_36 -> V_143 -> V_144 , V_159 -> V_141 -> V_145 ) ;
#endif
V_210 . V_127 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_161 = F_129 ( V_159 ,
V_151 ,
V_36 ) ;
#ifdef F_127
F_111 ( 12 , L_46 , V_233 . V_131 ) ;
#endif
F_128 ( V_161 , V_36 ) ;
V_159 = V_161 ;
} else {
V_151 = V_159 -> V_141 ;
#ifdef F_127
F_111 ( 12 , L_69 , V_151 -> V_142 ) ;
#endif
if ( V_204 && T_11 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , L_48 ) ;
F_152 ( V_213 ) ;
V_214 = F_61 ( V_213 , V_224 ) ;
V_212 = F_154 ( V_214 , V_226 , T_6 , 0 , 0 , V_151 -> V_127 ) ;
F_152 ( V_212 ) ;
#ifdef F_127
F_111 ( 20 , L_70 , V_151 -> V_142 ) ;
#endif
V_212 = F_153 ( V_214 , V_231 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_71 ,
V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
F_157 ( & V_230 , & V_36 -> V_143 -> V_148 , & V_151 -> V_147 ) ;
V_212 = F_158 ( V_214 , V_232 , T_6 , 0 , 0 , & V_230 ) ;
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
F_111 ( 10 , L_50 , V_233 . V_131 ) ;
#endif
V_210 . V_127 = V_203 ++ ;
V_151 = F_135 ( & V_210 , V_36 ) ;
V_159 = F_141 ( & V_233 , V_151 ) ;
#ifdef F_127
F_111 ( 11 , L_44 , V_233 . V_131 ) ;
F_111 ( 11 , L_51 , V_36 -> V_143 -> V_144 ) ;
#endif
F_128 ( V_159 , V_36 ) ;
}
if ( V_204 && T_11 &&
V_151 &&
V_151 -> V_127 ) {
V_213 = F_60 ( T_11 , T_6 , 0 , - 1 , L_48 ) ;
F_152 ( V_213 ) ;
V_214 = F_61 ( V_213 , V_224 ) ;
V_212 = F_154 ( V_214 , V_226 , T_6 , 0 , 0 , V_151 -> V_127 ) ;
F_152 ( V_212 ) ;
}
if( V_204 && V_214 &&
V_159 -> V_141 -> V_145 != 0 ) {
if ( ! V_234 ) {
#ifdef F_127
F_111 ( 20 , L_52 , V_159 -> V_141 -> V_145 ) ;
#endif
V_212 = F_153 ( V_214 , V_227 , T_6 , 0 , 0 ,
V_159 -> V_141 -> V_145 ,
L_53 ,
V_159 -> V_141 -> V_145 ) ;
F_152 ( V_212 ) ;
} else {
#ifdef F_127
F_111 ( 20 , L_70 , V_151 -> V_142 ) ;
#endif
if ( V_204 ) {
V_212 = F_153 ( V_214 , V_231 , T_6 , 0 , 0 ,
V_151 -> V_142 ,
L_71 ,
V_151 -> V_142 ) ;
F_152 ( V_212 ) ;
F_157 ( & V_230 , & V_36 -> V_143 -> V_148 , & V_151 -> V_147 ) ;
V_212 = F_158 ( V_214 , V_232 , T_6 , 0 , 0 , & V_230 ) ;
F_152 ( V_212 ) ;
}
}
}
return V_151 ;
}
struct V_150 *
F_161 ( T_5 * T_6 , T_17 * V_36 , T_10 * T_11 ,
struct V_208 * V_209 )
{
struct V_150 * V_235 = NULL ;
if( V_36 == NULL || V_36 -> V_143 -> V_144 == 0 ) {
return NULL ;
}
switch ( V_209 -> V_59 ) {
case V_60 :
#ifdef F_127
F_111 ( 1 , L_76 ) ;
#endif
V_235 = F_147 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
case V_69 :
#ifdef F_127
F_111 ( 1 , L_77 ) ;
#endif
V_235 = F_155 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
case V_74 :
#ifdef F_127
F_111 ( 1 , L_78 ) ;
#endif
V_235 = F_156 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
case V_66 :
#ifdef F_127
F_111 ( 1 , L_79 ) ;
#endif
V_235 = F_156 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
case V_236 :
case V_237 :
#ifdef F_127
F_111 ( 1 , L_80 ) ;
#endif
V_235 = F_160 ( T_6 , V_36 , T_11 , V_209 ) ;
break;
default:
#ifdef F_127
F_111 ( 1 , L_81 , V_209 -> V_59 ) ;
#endif
break;
}
#ifdef F_127
if ( V_235 )
F_111 ( 1 , L_82 , V_235 -> V_127 ) ;
#endif
return V_235 ;
}
struct V_208 *
F_162 ( void )
{
struct V_208 * V_209 ;
V_238 ++ ;
if( V_238 == V_239 ) {
V_238 = 0 ;
}
V_209 = & V_240 [ V_238 ] ;
memset ( V_209 , 0 , sizeof( struct V_208 ) ) ;
return V_209 ;
}
void
F_159 ( struct V_150 * V_151 ,
T_17 * V_36 )
{
#ifdef F_127
F_111 ( 60 , L_83 ) ;
#endif
if ( V_151 ) {
V_151 -> V_146 = TRUE ;
V_151 -> V_145 = V_36 -> V_143 -> V_144 ;
V_151 -> V_241 = V_36 -> V_143 -> V_148 ;
V_151 -> V_223 = TRUE ;
if ( V_151 -> V_177
&& ! V_205 ) {
if ( V_151 -> V_177 -> V_179 ) {
if ( V_151 -> V_177 -> V_180 ) {
#ifdef F_127
F_111 ( 20 , L_84 ) ;
#endif
V_151 -> V_177 -> V_180 -> V_179
= V_151 -> V_177 -> V_179 ;
V_151 -> V_177 -> V_179 -> V_180
= V_151 -> V_177 -> V_180 ;
F_7 ( V_190 , V_151 -> V_177 -> V_178 ) ;
#ifdef F_124
F_163 ( V_151 -> V_177 ) ;
#endif
} else {
#ifdef F_127
F_111 ( 20 , L_85 ) ;
#endif
}
} else if ( ! V_205 ) {
#ifdef F_127
F_111 ( 20 , L_86 ) ;
#endif
F_7 ( V_190 , V_151 -> V_177 -> V_178 ) ;
#ifdef F_124
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
F_111 ( 20 , L_87 ) ;
#endif
V_151 -> V_169 -> V_172 -> V_171
= V_151 -> V_169 -> V_171 ;
V_151 -> V_169 -> V_171 -> V_172
= V_151 -> V_169 -> V_172 ;
F_7 ( V_186 , V_151 -> V_169 -> V_170 ) ;
#ifdef F_124
F_163 ( V_151 -> V_169 ) ;
#endif
} else {
#ifdef F_127
F_111 ( 20 , L_88 ) ;
#endif
}
} else if ( ! V_205 ) {
#ifdef F_127
F_111 ( 20 , L_89 ) ;
#endif
F_7 ( V_186 , V_151 -> V_169 -> V_170 ) ;
#ifdef F_124
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
F_111 ( 20 , L_90 ) ;
#endif
V_151 -> V_153 -> V_156 -> V_155
= V_151 -> V_153 -> V_155 ;
V_151 -> V_153 -> V_155 -> V_156
= V_151 -> V_153 -> V_156 ;
F_7 ( V_183 , V_151 -> V_153 -> V_154 ) ;
#ifdef F_124
F_163 ( V_151 -> V_153 ) ;
#endif
} else {
#ifdef F_127
F_111 ( 20 , L_91 ) ;
#endif
}
} else if ( ! V_205 ) {
#ifdef F_127
F_111 ( 20 , L_92 ) ;
#endif
F_7 ( V_183 , V_151 -> V_153 -> V_154 ) ;
#ifdef F_124
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
F_111 ( 20 , L_93 ) ;
#endif
V_151 -> V_162 -> V_165 -> V_164
= V_151 -> V_162 -> V_164 ;
V_151 -> V_162 -> V_164 -> V_165
= V_151 -> V_162 -> V_165 ;
F_7 ( V_200 , V_151 -> V_162 -> V_163 ) ;
#ifdef F_124
F_163 ( V_151 -> V_162 ) ;
#endif
} else {
#ifdef F_127
F_111 ( 20 , L_94 ) ;
#endif
}
} else if ( ! V_205 ) {
#ifdef F_127
F_111 ( 20 , L_95 ) ;
#endif
F_7 ( V_200 , V_151 -> V_162 -> V_163 ) ;
#ifdef F_124
F_163 ( V_151 -> V_162 -> V_163 ) ;
F_163 ( V_151 -> V_162 ) ;
#endif
}
}
if ( ! V_205 ) {
#ifdef F_127
F_111 ( 20 , L_96 ) ;
#endif
F_7 ( V_194 , V_151 -> V_129 ) ;
#ifdef F_124
F_163 ( V_151 -> V_129 ) ;
F_163 ( V_151 ) ;
#endif
}
} else {
#ifdef F_127
F_111 ( 20 , L_97 ) ;
#endif
}
}
static void
F_164 ( T_5 * T_6 , T_17 * V_36 , T_10 * V_242 )
{
T_16 * V_243 = NULL ;
T_10 * T_11 = NULL ;
struct V_150 * V_244 ;
T_2 V_245 ;
T_8 V_113 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
F_165 ( T_6 , 0 , & V_30 , & V_31 , & V_32 ) ;
if( V_30 == V_246 ) {
switch( V_32 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
F_166 ( V_247 , T_6 , V_36 , V_242 ) ;
return;
break;
default:
return;
}
}
F_109 ( & V_113 , V_114 , TRUE , V_36 ) ;
V_42 = V_242 ;
V_248 = NULL ;
F_70 ( V_36 -> V_57 , V_249 , L_98 ) ;
if( V_242 ) {
V_243 = F_167 ( V_242 , V_250 , T_6 , 0 , - 1 , V_251 ) ;
T_11 = F_61 ( V_243 , V_252 ) ;
V_248 = T_11 ;
}
V_83 = NULL ;
V_253 = NULL ;
F_168 ( & V_84 ) ;
V_113 . V_254 = & V_84 ;
V_55 = F_162 () ;
V_255 = FALSE ;
V_256 = NULL ;
F_78 ( FALSE , T_6 , 0 , & V_113 , T_11 , - 1 ) ;
if ( V_206 && ! V_255 ) {
V_244 = F_161 ( T_6 , V_36 , V_248 , V_55 ) ;
V_84 . V_141 = V_244 ;
if ( V_244 && V_83 && ! V_244 -> V_257 ) {
F_169 ( V_244 -> V_85 , V_83 , sizeof( V_244 -> V_85 ) ) ;
V_244 -> V_257 = TRUE ;
if ( ( V_245 = F_170 ( V_258 , V_83 ) ) ) {
V_244 -> V_245 = V_245 ;
V_244 -> V_259 = TRUE ;
}
}
if ( V_206 && V_244 && V_244 -> V_260 ) {
( V_244 -> V_260 ) ( T_6 , V_36 , V_248 , V_244 ) ;
}
}
}
void
F_171 ( void )
{
V_261 = F_172 ( L_99 ) ;
V_247 = F_172 ( L_100 ) ;
V_258 = F_173 ( L_101 ) ;
#line 1 "../../asn1/tcap/packet-tcap-dis-tab.c"
F_174 ( L_102 , F_110 , V_250 , L_103 ) ;
F_174 ( L_104 , F_108 , V_250 , L_105 ) ;
#line 2077 "../../asn1/tcap/packet-tcap-template.c"
}
void
F_175 ( void )
{
static T_22 V_262 [] = {
{ & V_263 ,
{ L_106 , L_107 ,
V_264 , V_265 , NULL , 0 ,
NULL , V_266 }
} ,
{ & V_267 ,
{ L_108 , L_109 ,
V_264 , V_268 , NULL , 0 ,
NULL , V_266 }
} ,
{ & V_269 ,
{ L_110 , L_111 ,
V_270 , V_271 , NULL , 0 ,
NULL , V_266 }
} ,
{ & V_52 ,
{ L_112 , L_113 ,
V_270 , V_271 , NULL , 0 ,
NULL , V_266 }
} ,
{ & V_226 ,
{ L_114 ,
L_115 ,
V_272 , V_268 , NULL , 0x0 ,
NULL , V_266 }
} ,
{ & V_227 ,
{ L_116 ,
L_117 ,
V_273 , V_271 , NULL , 0x0 ,
L_118 , V_266 }
} ,
{ & V_231 ,
{ L_119 ,
L_120 ,
V_273 , V_271 , NULL , 0x0 ,
L_121 , V_266 }
} ,
{ & V_232 ,
{ L_122 ,
L_123 ,
V_274 , V_271 , NULL , 0x0 ,
L_124 , V_266 }
} ,
{ & V_225 ,
{ L_125 ,
L_126 ,
V_273 , V_271 , NULL , 0x0 ,
L_127 , V_266 }
} ,
#line 1 "../../asn1/tcap/packet-tcap-hfarr.c"
{ & V_115 ,
{ L_128 , L_129 ,
V_272 , V_268 , F_176 ( V_275 ) , 0 ,
NULL , V_266 } } ,
{ & V_116 ,
{ L_130 , L_131 ,
V_272 , V_268 , F_176 ( V_276 ) , 0 ,
NULL , V_266 } } ,
{ & V_277 ,
{ L_132 , L_133 ,
V_278 , V_271 , NULL , 0 ,
L_134 , V_266 } } ,
{ & V_279 ,
{ L_135 , L_136 ,
V_270 , V_271 , NULL , 0 ,
L_137 , V_266 } } ,
{ & V_280 ,
{ L_138 , L_139 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_282 ,
{ L_140 , L_141 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_283 ,
{ L_142 , L_143 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_284 ,
{ L_144 , L_145 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_285 ,
{ L_146 , L_147 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_286 ,
{ L_148 , L_149 ,
V_270 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_287 ,
{ L_150 , L_151 ,
V_272 , V_268 , NULL , 0 ,
L_152 , V_266 } } ,
{ & V_54 ,
{ L_153 , L_154 ,
V_270 , V_271 , NULL , 0 ,
L_155 , V_266 } } ,
{ & V_64 ,
{ L_156 , L_157 ,
V_270 , V_271 , NULL , 0 ,
L_158 , V_266 } } ,
{ & V_288 ,
{ L_159 , L_160 ,
V_272 , V_268 , F_176 ( V_289 ) , 0 ,
NULL , V_266 } } ,
{ & V_290 ,
{ L_161 , L_162 ,
V_272 , V_268 , F_176 ( V_291 ) , 0 ,
NULL , V_266 } } ,
{ & V_292 ,
{ L_163 , L_164 ,
V_270 , V_271 , NULL , 0 ,
L_165 , V_266 } } ,
{ & V_293 ,
{ L_166 , L_167 ,
V_272 , V_268 , F_176 ( V_294 ) , 0 ,
NULL , V_266 } } ,
{ & V_295 ,
{ L_168 , L_169 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_296 ,
{ L_170 , L_171 ,
V_281 , V_271 , NULL , 0 ,
L_172 , V_266 } } ,
{ & V_297 ,
{ L_173 , L_174 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_298 ,
{ L_175 , L_176 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_299 ,
{ L_177 , L_178 ,
V_281 , V_271 , NULL , 0 ,
L_172 , V_266 } } ,
{ & V_300 ,
{ L_179 , L_180 ,
V_301 , V_268 , NULL , 0 ,
L_181 , V_266 } } ,
{ & V_302 ,
{ L_182 , L_183 ,
V_301 , V_268 , NULL , 0 ,
L_181 , V_266 } } ,
{ & V_303 ,
{ L_184 , L_185 ,
V_272 , V_268 , F_176 ( V_304 ) , 0 ,
L_186 , V_266 } } ,
{ & V_305 ,
{ L_187 , L_188 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_306 ,
{ L_189 , L_190 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_307 ,
{ L_191 , L_192 ,
V_272 , V_268 , F_176 ( V_308 ) , 0 ,
NULL , V_266 } } ,
{ & V_309 ,
{ L_193 , L_194 ,
V_272 , V_268 , F_176 ( V_310 ) , 0 ,
NULL , V_266 } } ,
{ & V_311 ,
{ L_195 , L_196 ,
V_301 , V_268 , NULL , 0 ,
L_181 , V_266 } } ,
{ & V_312 ,
{ L_197 , L_198 ,
V_281 , V_271 , NULL , 0 ,
NULL , V_266 } } ,
{ & V_313 ,
{ L_199 , L_200 ,
V_272 , V_268 , F_176 ( V_314 ) , 0 ,
NULL , V_266 } } ,
{ & V_315 ,
{ L_201 , L_202 ,
V_301 , V_268 , F_176 ( V_316 ) , 0 ,
NULL , V_266 } } ,
{ & V_317 ,
{ L_203 , L_204 ,
V_301 , V_268 , F_176 ( V_318 ) , 0 ,
NULL , V_266 } } ,
{ & V_319 ,
{ L_205 , L_206 ,
V_301 , V_268 , F_176 ( V_320 ) , 0 ,
NULL , V_266 } } ,
{ & V_321 ,
{ L_207 , L_208 ,
V_301 , V_268 , F_176 ( V_322 ) , 0 ,
NULL , V_266 } } ,
{ & V_323 ,
{ L_209 , L_210 ,
V_301 , V_268 , NULL , 0 ,
L_211 , V_266 } } ,
{ & V_324 ,
{ L_212 , L_213 ,
V_278 , V_271 , NULL , 0 ,
L_134 , V_266 } } ,
{ & V_325 ,
{ L_214 , L_215 ,
V_301 , V_268 , NULL , 0 ,
L_216 , V_266 } } ,
{ & V_326 ,
{ L_217 , L_218 ,
V_301 , V_268 , NULL , 0 ,
L_211 , V_266 } } ,
{ & V_327 ,
{ L_219 , L_220 ,
V_281 , V_271 , NULL , 0 ,
L_221 , V_266 } } ,
{ & V_328 ,
{ L_222 , L_223 ,
V_270 , V_271 , NULL , 0 ,
L_224 , V_266 } } ,
{ & V_329 ,
{ L_225 , L_226 ,
V_278 , V_271 , NULL , 0 ,
L_227 , V_266 } } ,
{ & V_330 ,
{ L_228 , L_229 ,
V_272 , V_268 , NULL , 0 ,
L_230 , V_266 } } ,
{ & V_331 ,
{ L_231 , L_232 ,
V_281 , V_271 , NULL , 0 ,
L_233 , V_266 } } ,
{ & V_332 ,
{ L_234 , L_235 ,
V_281 , V_271 , NULL , 0 ,
L_236 , V_266 } } ,
{ & V_333 ,
{ L_237 , L_238 ,
V_281 , V_271 , NULL , 0 ,
L_239 , V_266 } } ,
{ & V_334 ,
{ L_240 , L_241 ,
V_281 , V_271 , NULL , 0 ,
L_242 , V_266 } } ,
{ & V_335 ,
{ L_222 , L_223 ,
V_270 , V_271 , NULL , 0 ,
L_243 , V_266 } } ,
{ & V_336 ,
{ L_225 , L_226 ,
V_278 , V_271 , NULL , 0 ,
L_244 , V_266 } } ,
{ & V_337 ,
{ L_228 , L_229 ,
V_272 , V_268 , NULL , 0 ,
L_245 , V_266 } } ,
{ & V_338 ,
{ L_231 , L_232 ,
V_281 , V_271 , NULL , 0 ,
L_233 , V_266 } } ,
{ & V_339 ,
{ L_222 , L_223 ,
V_270 , V_271 , NULL , 0 ,
L_246 , V_266 } } ,
{ & V_340 ,
{ L_225 , L_226 ,
V_278 , V_271 , NULL , 0 ,
L_247 , V_266 } } ,
{ & V_341 ,
{ L_248 , L_249 ,
V_301 , V_268 , F_176 ( V_342 ) , 0 ,
L_250 , V_266 } } ,
{ & V_343 ,
{ L_251 , L_252 ,
V_272 , V_268 , F_176 ( V_344 ) , 0 ,
L_253 , V_266 } } ,
{ & V_345 ,
{ L_228 , L_229 ,
V_272 , V_268 , NULL , 0 ,
L_254 , V_266 } } ,
{ & V_346 ,
{ L_231 , L_232 ,
V_281 , V_271 , NULL , 0 ,
L_233 , V_266 } } ,
{ & V_347 ,
{ L_255 , L_256 ,
V_301 , V_268 , F_176 ( V_348 ) , 0 ,
L_257 , V_266 } } ,
{ & V_349 ,
{ L_228 , L_229 ,
V_272 , V_268 , NULL , 0 ,
L_258 , V_266 } } ,
{ & V_350 ,
{ L_231 , L_232 ,
V_281 , V_271 , NULL , 0 ,
L_233 , V_266 } } ,
{ & V_351 ,
{ L_259 , L_260 ,
V_301 , V_268 , F_176 ( V_352 ) , 0 ,
NULL , V_266 } } ,
{ & V_353 ,
{ L_261 , L_262 ,
V_301 , V_268 , F_176 ( V_354 ) , 0 ,
NULL , V_266 } } ,
{ & V_355 ,
{ L_263 , L_264 ,
V_356 , 8 , NULL , 0x80 ,
NULL , V_266 } } ,
{ & V_357 ,
{ L_263 , L_264 ,
V_356 , 8 , NULL , 0x80 ,
NULL , V_266 } } ,
{ & V_358 ,
{ L_263 , L_264 ,
V_356 , 8 , NULL , 0x80 ,
NULL , V_266 } } ,
#line 2139 "../../asn1/tcap/packet-tcap-template.c"
} ;
static T_14 * V_359 [] = {
& V_252 ,
& V_360 ,
& V_51 ,
& V_63 ,
& V_224 ,
#line 1 "../../asn1/tcap/packet-tcap-ettarr.c"
& V_8 ,
& V_78 ,
& V_46 ,
& V_62 ,
& V_68 ,
& V_71 ,
& V_76 ,
& V_73 ,
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
& V_80 ,
& V_20 ,
& V_92 ,
& V_90 ,
& V_82 ,
& V_88 ,
& V_112 ,
& V_98 ,
& V_94 ,
& V_96 ,
& V_106 ,
& V_100 ,
& V_104 ,
& V_110 ,
& V_108 ,
& V_102 ,
#line 2149 "../../asn1/tcap/packet-tcap-template.c"
} ;
T_23 * V_361 ;
V_250 = F_177 ( V_362 , V_363 , V_364 ) ;
F_178 ( V_250 , V_262 , F_179 ( V_262 ) ) ;
F_180 ( V_359 , F_179 ( V_359 ) ) ;
V_361 = F_181 ( V_250 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_182 ( V_361 , L_265 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_182 ( V_361 , L_266 ) ;
#endif
F_183 ( & V_365 , L_267 , V_366 ) ;
V_367 = F_184 () ;
F_185 ( V_361 , L_268 , L_269 ,
L_270 ,
& V_365 , V_366 ) ;
F_186 ( V_361 , L_271 ,
L_272 ,
L_273 ,
& V_206 ) ;
F_186 ( V_361 , L_274 ,
L_275 ,
L_276 ,
& V_205 ) ;
F_187 ( V_361 , L_277 ,
L_278 ,
L_279 ,
10 , & V_221 ) ;
F_187 ( V_361 , L_280 ,
L_281 ,
L_282 ,
10 , & V_222 ) ;
V_3 = F_146 ( V_368 , V_369 ) ;
V_5 = F_146 ( V_368 , V_369 ) ;
F_188 ( L_283 , F_164 , V_250 ) ;
V_4 = F_189 ( F_164 , V_250 ) ;
F_190 ( & V_370 ) ;
}
static void F_191 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_192 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_370 ( void ) {
if ( V_367 ) {
F_193 ( V_367 , F_191 ) ;
F_163 ( V_367 ) ;
}
V_367 = F_194 ( V_365 ) ;
F_193 ( V_367 , F_192 ) ;
F_144 () ;
}
static int
F_29 ( T_8 * T_9 , T_10 * T_11 , T_5 * T_6 , int T_7 )
{
T_14 V_371 , V_372 , V_373 ;
T_5 * V_29 ;
T_10 * V_50 ;
T_16 * V_212 ;
T_13 V_30 ;
T_3 V_31 ;
T_24 V_32 ;
T_1 V_33 ;
T_1 V_374 ;
T_1 V_375 ;
T_3 V_35 ;
while ( F_195 ( T_6 , T_7 ) > 0 )
{
V_372 = T_7 ;
T_7 = F_165 ( T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_371 = T_7 ;
T_7 = F_196 ( T_6 , T_7 , & V_33 , & V_35 ) ;
V_373 = T_7 ;
V_374 = V_371 - V_372 ;
V_375 = V_373 - V_371 ;
if ( V_31 )
{
V_212 = F_60 ( T_11 , T_6 , V_372 ,
V_33 + ( V_373 - V_372 ) ,
L_284 ) ;
V_50 = F_61 ( V_212 , V_360 ) ;
F_153 ( V_50 , V_263 , T_6 ,
V_372 , V_374 , V_32 ,
L_285 ) ;
F_154 ( V_50 , V_263 , T_6 , V_372 ,
V_374 , V_30 ) ;
F_154 ( V_50 , V_267 , T_6 , V_371 ,
V_375 , V_33 ) ;
if ( V_33 - ( 2 * V_35 ) )
{
V_29 = F_48 ( T_6 , T_7 , V_33 - ( 2 * V_35 ) ,
V_33 - ( 2 * V_35 ) ) ;
F_29 ( T_9 , V_50 , V_29 , 0 ) ;
}
if ( V_35 )
F_60 ( V_50 , T_6 , T_7 + V_33 - 2 , 2 , L_286 ) ;
T_7 += V_33 ;
}
else
{
V_212 = F_60 ( T_11 , T_6 , V_372 ,
V_33 + ( V_373 - V_372 ) ,
L_287 , V_32 ) ;
V_50 = F_61 ( V_212 , V_360 ) ;
F_154 ( V_50 , V_263 , T_6 , V_372 ,
V_374 , V_32 ) ;
F_154 ( V_50 , V_267 , T_6 ,
V_372 + V_374 , V_375 , V_33 ) ;
if ( V_33 )
{
V_29 = F_48 ( T_6 , T_7 , V_33 , V_33 ) ;
F_58 ( TRUE , T_9 , T_11 , V_29 , 0 ,
V_269 , NULL ) ;
}
T_7 += V_33 ;
}
}
return T_7 ;
}
static void F_168 ( struct V_376 * V_377 )
{
memset ( V_377 , 0 , sizeof( struct V_376 ) ) ;
}
static int
F_52 ( T_3 T_4 V_6 , T_5 * T_6 , int T_7 , T_8 * T_9 V_6 , T_10 * T_11 , int T_12 V_6 )
{
T_2 V_245 = NULL ;
T_3 V_378 = FALSE ;
struct V_150 * V_244 = NULL ;
if ( V_206 ) {
if ( ! V_255 ) {
V_244 = F_161 ( T_6 , T_9 -> V_36 , V_248 , V_55 ) ;
V_255 = TRUE ;
V_256 = V_244 ;
V_84 . V_141 = V_244 ;
} else{
V_244 = V_256 ;
V_84 . V_141 = V_244 ;
}
}
if ( V_244 ) {
if ( V_83 ) {
if ( V_244 -> V_257 ) {
if ( strncmp ( V_244 -> V_85 , V_83 , sizeof( V_244 -> V_85 ) ) != 0 ) {
F_169 ( V_244 -> V_85 , V_83 , sizeof( V_244 -> V_85 ) ) ;
if ( ( V_245 = F_170 ( V_258 , V_83 ) ) ) {
V_244 -> V_245 = V_245 ;
V_244 -> V_259 = TRUE ;
}
}
} else {
F_169 ( V_244 -> V_85 , V_83 , sizeof( V_244 -> V_85 ) ) ;
V_244 -> V_257 = TRUE ;
if ( ( V_245
= F_170 ( V_258 , V_83 ) ) ) {
V_244 -> V_245 = V_245 ;
V_244 -> V_259 = TRUE ;
} else {
if ( ( V_245 = F_8 ( T_9 -> V_36 -> V_379 ) ) ) {
V_244 -> V_245 = V_245 ;
V_244 -> V_259 = TRUE ;
}
}
}
} else {
if ( V_244 -> V_257 ) {
V_84 . V_85 = ( void * ) V_244 -> V_85 ;
V_84 . V_86 = TRUE ;
}
}
}
if ( V_244
&& V_244 -> V_259 ) {
V_245 = V_244 -> V_245 ;
V_378 = TRUE ;
}
if ( ! V_378 && V_380 ) {
V_378 = TRUE ;
V_245 = V_380 ;
}
if ( ! V_378 ) {
if ( V_258 && V_83 ) {
if ( ( V_245
= F_170 ( V_258 , V_83 ) ) ) {
V_378 = TRUE ;
} else {
if ( ( V_245
= F_8 ( T_9 -> V_36 -> V_379 ) ) ) {
V_378 = TRUE ;
} else {
V_245 = V_261 ;
V_378 = TRUE ;
}
}
} else {
if ( ( V_245 = F_8 ( T_9 -> V_36 -> V_379 ) ) ) {
V_378 = TRUE ;
} else {
V_245 = V_261 ;
V_378 = TRUE ;
}
}
} else {
}
if ( V_378 ) {
F_197 ( V_245 , T_6 , T_9 -> V_36 , T_11 , T_9 -> V_254 ) ;
F_198 ( T_9 -> V_36 -> V_57 , V_58 ) ;
}
return T_7 ;
}
void F_199 ( T_2 V_381 , T_5 * T_6 , T_17 * V_36 , T_10 * T_11 ) {
V_380 = V_381 ;
F_49 {
F_164 ( T_6 , V_36 , T_11 ) ;
} F_200 {
V_380 = NULL ;
V_382 ;
} V_41 ;
V_380 = NULL ;
}
