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
#line 123 "../../asn1/tcap/tcap.cnf"
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
#line 201 "../../asn1/tcap/tcap.cnf"
V_55 -> V_59 = V_60 ;
F_70 ( T_9 -> V_36 -> V_57 , V_58 , L_6 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_61 , T_12 , V_62 ) ;
return T_7 ;
}
static int
F_71 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 164 "../../asn1/tcap/tcap.cnf"
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
#line 215 "../../asn1/tcap/tcap.cnf"
V_55 -> V_59 = V_66 ;
F_70 ( T_9 -> V_36 -> V_57 , V_58 , L_9 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_67 , T_12 , V_68 ) ;
return T_7 ;
}
static int
F_73 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 222 "../../asn1/tcap/tcap.cnf"
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
#line 229 "../../asn1/tcap/tcap.cnf"
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
#line 108 "../../asn1/tcap/tcap.cnf"
T_7 = F_83 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_83 ) ;
V_84 . V_85 = ( void * ) V_83 ;
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
#line 113 "../../asn1/tcap/tcap.cnf"
T_7 = F_83 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_83 ) ;
V_84 . V_85 = ( void * ) V_83 ;
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
#line 118 "../../asn1/tcap/tcap.cnf"
T_7 = F_83 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_83 ) ;
V_84 . V_85 = ( void * ) V_83 ;
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
F_111 ( T_5 * T_6 , T_17 * V_36 , T_10 * V_117 )
{
T_16 * V_118 = NULL ;
T_10 * T_11 = NULL ;
struct V_119 * V_120 ;
T_2 V_121 ;
T_8 V_113 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
F_112 ( T_6 , 0 , & V_30 , & V_31 , & V_32 ) ;
if( V_30 == V_122 ) {
switch( V_32 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
F_113 ( V_123 , T_6 , V_36 , V_117 ) ;
return;
break;
default:
return;
}
}
F_109 ( & V_113 , V_114 , TRUE , V_36 ) ;
V_42 = V_117 ;
V_124 = NULL ;
F_70 ( V_36 -> V_57 , V_125 , L_12 ) ;
if( V_117 ) {
V_118 = F_114 ( V_117 , V_126 , T_6 , 0 , - 1 , V_127 ) ;
T_11 = F_61 ( V_118 , V_128 ) ;
V_124 = T_11 ;
}
V_83 = NULL ;
V_129 = NULL ;
F_115 ( & V_84 ) ;
V_36 -> V_130 = & V_84 ;
V_55 = F_116 () ;
V_131 = FALSE ;
V_132 = NULL ;
F_78 ( FALSE , T_6 , 0 , & V_113 , T_11 , - 1 ) ;
if ( V_133 && ! V_131 ) {
V_120 = F_117 ( T_6 , V_36 , V_124 , V_55 ) ;
V_84 . V_134 = V_120 ;
if ( V_120 && V_83 && ! V_120 -> V_135 ) {
F_118 ( V_120 -> V_85 , V_83 , sizeof( V_120 -> V_85 ) ) ;
V_120 -> V_135 = TRUE ;
if ( ( V_121 = F_119 ( V_136 , V_83 ) ) ) {
V_120 -> V_121 = V_121 ;
V_120 -> V_137 = TRUE ;
}
}
if ( V_133 && V_120 && V_120 -> V_138 ) {
( V_120 -> V_138 ) ( T_6 , V_36 , V_124 , V_120 ) ;
}
}
}
void
F_120 ( void )
{
V_139 = F_121 ( L_13 ) ;
V_123 = F_121 ( L_14 ) ;
V_136 = F_122 ( L_15 ) ;
#line 1 "../../asn1/tcap/packet-tcap-dis-tab.c"
F_123 ( L_16 , F_110 , V_126 , L_17 ) ;
F_123 ( L_18 , F_108 , V_126 , L_19 ) ;
#line 252 "../../asn1/tcap/packet-tcap-template.c"
}
void
F_124 ( void )
{
static T_18 V_140 [] = {
{ & V_141 ,
{ L_20 , L_21 ,
V_142 , V_143 , NULL , 0 ,
NULL , V_144 }
} ,
{ & V_145 ,
{ L_22 , L_23 ,
V_142 , V_146 , NULL , 0 ,
NULL , V_144 }
} ,
{ & V_147 ,
{ L_24 , L_25 ,
V_148 , V_149 , NULL , 0 ,
NULL , V_144 }
} ,
{ & V_52 ,
{ L_26 , L_27 ,
V_148 , V_149 , NULL , 0 ,
NULL , V_144 }
} ,
{ & V_150 ,
{ L_28 ,
L_29 ,
V_151 , V_146 , NULL , 0x0 ,
NULL , V_144 }
} ,
{ & V_152 ,
{ L_30 ,
L_31 ,
V_153 , V_149 , NULL , 0x0 ,
L_32 , V_144 }
} ,
{ & V_154 ,
{ L_33 ,
L_34 ,
V_153 , V_149 , NULL , 0x0 ,
L_35 , V_144 }
} ,
{ & V_155 ,
{ L_36 ,
L_37 ,
V_156 , V_149 , NULL , 0x0 ,
L_38 , V_144 }
} ,
{ & V_157 ,
{ L_39 ,
L_40 ,
V_153 , V_149 , NULL , 0x0 ,
L_41 , V_144 }
} ,
#line 1 "../../asn1/tcap/packet-tcap-hfarr.c"
{ & V_115 ,
{ L_42 , L_43 ,
V_151 , V_146 , F_125 ( V_158 ) , 0 ,
NULL , V_144 } } ,
{ & V_116 ,
{ L_44 , L_45 ,
V_151 , V_146 , F_125 ( V_159 ) , 0 ,
NULL , V_144 } } ,
{ & V_160 ,
{ L_46 , L_47 ,
V_161 , V_149 , NULL , 0 ,
L_48 , V_144 } } ,
{ & V_162 ,
{ L_49 , L_50 ,
V_148 , V_149 , NULL , 0 ,
L_51 , V_144 } } ,
{ & V_163 ,
{ L_52 , L_53 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_165 ,
{ L_54 , L_55 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_166 ,
{ L_56 , L_57 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_167 ,
{ L_58 , L_59 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_168 ,
{ L_60 , L_61 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_169 ,
{ L_62 , L_63 ,
V_148 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_170 ,
{ L_64 , L_65 ,
V_151 , V_146 , NULL , 0 ,
L_66 , V_144 } } ,
{ & V_54 ,
{ L_67 , L_68 ,
V_148 , V_149 , NULL , 0 ,
L_69 , V_144 } } ,
{ & V_64 ,
{ L_70 , L_71 ,
V_148 , V_149 , NULL , 0 ,
L_72 , V_144 } } ,
{ & V_171 ,
{ L_73 , L_74 ,
V_151 , V_146 , F_125 ( V_172 ) , 0 ,
NULL , V_144 } } ,
{ & V_173 ,
{ L_75 , L_76 ,
V_151 , V_146 , F_125 ( V_174 ) , 0 ,
NULL , V_144 } } ,
{ & V_175 ,
{ L_77 , L_78 ,
V_148 , V_149 , NULL , 0 ,
L_79 , V_144 } } ,
{ & V_176 ,
{ L_80 , L_81 ,
V_151 , V_146 , F_125 ( V_177 ) , 0 ,
NULL , V_144 } } ,
{ & V_178 ,
{ L_82 , L_83 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_179 ,
{ L_84 , L_85 ,
V_164 , V_149 , NULL , 0 ,
L_86 , V_144 } } ,
{ & V_180 ,
{ L_87 , L_88 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_181 ,
{ L_89 , L_90 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_182 ,
{ L_91 , L_92 ,
V_164 , V_149 , NULL , 0 ,
L_86 , V_144 } } ,
{ & V_183 ,
{ L_93 , L_94 ,
V_184 , V_146 , NULL , 0 ,
L_95 , V_144 } } ,
{ & V_185 ,
{ L_96 , L_97 ,
V_184 , V_146 , NULL , 0 ,
L_95 , V_144 } } ,
{ & V_186 ,
{ L_98 , L_99 ,
V_151 , V_146 , F_125 ( V_187 ) , 0 ,
L_100 , V_144 } } ,
{ & V_188 ,
{ L_101 , L_102 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_189 ,
{ L_103 , L_104 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_190 ,
{ L_105 , L_106 ,
V_151 , V_146 , F_125 ( V_191 ) , 0 ,
NULL , V_144 } } ,
{ & V_192 ,
{ L_107 , L_108 ,
V_151 , V_146 , F_125 ( V_193 ) , 0 ,
NULL , V_144 } } ,
{ & V_194 ,
{ L_109 , L_110 ,
V_184 , V_146 , NULL , 0 ,
L_95 , V_144 } } ,
{ & V_195 ,
{ L_111 , L_112 ,
V_164 , V_149 , NULL , 0 ,
NULL , V_144 } } ,
{ & V_196 ,
{ L_113 , L_114 ,
V_151 , V_146 , F_125 ( V_197 ) , 0 ,
NULL , V_144 } } ,
{ & V_198 ,
{ L_115 , L_116 ,
V_184 , V_146 , F_125 ( V_199 ) , 0 ,
NULL , V_144 } } ,
{ & V_200 ,
{ L_117 , L_118 ,
V_184 , V_146 , F_125 ( V_201 ) , 0 ,
NULL , V_144 } } ,
{ & V_202 ,
{ L_119 , L_120 ,
V_184 , V_146 , F_125 ( V_203 ) , 0 ,
NULL , V_144 } } ,
{ & V_204 ,
{ L_121 , L_122 ,
V_184 , V_146 , F_125 ( V_205 ) , 0 ,
NULL , V_144 } } ,
{ & V_206 ,
{ L_123 , L_124 ,
V_184 , V_146 , NULL , 0 ,
L_125 , V_144 } } ,
{ & V_207 ,
{ L_126 , L_127 ,
V_161 , V_149 , NULL , 0 ,
L_48 , V_144 } } ,
{ & V_208 ,
{ L_128 , L_129 ,
V_184 , V_146 , NULL , 0 ,
L_130 , V_144 } } ,
{ & V_209 ,
{ L_131 , L_132 ,
V_184 , V_146 , NULL , 0 ,
L_125 , V_144 } } ,
{ & V_210 ,
{ L_133 , L_134 ,
V_164 , V_149 , NULL , 0 ,
L_135 , V_144 } } ,
{ & V_211 ,
{ L_136 , L_137 ,
V_148 , V_149 , NULL , 0 ,
L_138 , V_144 } } ,
{ & V_212 ,
{ L_139 , L_140 ,
V_161 , V_149 , NULL , 0 ,
L_141 , V_144 } } ,
{ & V_213 ,
{ L_142 , L_143 ,
V_151 , V_146 , NULL , 0 ,
L_144 , V_144 } } ,
{ & V_214 ,
{ L_145 , L_146 ,
V_164 , V_149 , NULL , 0 ,
L_147 , V_144 } } ,
{ & V_215 ,
{ L_148 , L_149 ,
V_164 , V_149 , NULL , 0 ,
L_150 , V_144 } } ,
{ & V_216 ,
{ L_151 , L_152 ,
V_164 , V_149 , NULL , 0 ,
L_153 , V_144 } } ,
{ & V_217 ,
{ L_154 , L_155 ,
V_164 , V_149 , NULL , 0 ,
L_156 , V_144 } } ,
{ & V_218 ,
{ L_136 , L_137 ,
V_148 , V_149 , NULL , 0 ,
L_157 , V_144 } } ,
{ & V_219 ,
{ L_139 , L_140 ,
V_161 , V_149 , NULL , 0 ,
L_158 , V_144 } } ,
{ & V_220 ,
{ L_142 , L_143 ,
V_151 , V_146 , NULL , 0 ,
L_159 , V_144 } } ,
{ & V_221 ,
{ L_145 , L_146 ,
V_164 , V_149 , NULL , 0 ,
L_147 , V_144 } } ,
{ & V_222 ,
{ L_136 , L_137 ,
V_148 , V_149 , NULL , 0 ,
L_160 , V_144 } } ,
{ & V_223 ,
{ L_139 , L_140 ,
V_161 , V_149 , NULL , 0 ,
L_161 , V_144 } } ,
{ & V_224 ,
{ L_162 , L_163 ,
V_184 , V_146 , F_125 ( V_225 ) , 0 ,
L_164 , V_144 } } ,
{ & V_226 ,
{ L_165 , L_166 ,
V_151 , V_146 , F_125 ( V_227 ) , 0 ,
L_167 , V_144 } } ,
{ & V_228 ,
{ L_142 , L_143 ,
V_151 , V_146 , NULL , 0 ,
L_168 , V_144 } } ,
{ & V_229 ,
{ L_145 , L_146 ,
V_164 , V_149 , NULL , 0 ,
L_147 , V_144 } } ,
{ & V_230 ,
{ L_169 , L_170 ,
V_184 , V_146 , F_125 ( V_231 ) , 0 ,
L_171 , V_144 } } ,
{ & V_232 ,
{ L_142 , L_143 ,
V_151 , V_146 , NULL , 0 ,
L_172 , V_144 } } ,
{ & V_233 ,
{ L_145 , L_146 ,
V_164 , V_149 , NULL , 0 ,
L_147 , V_144 } } ,
{ & V_234 ,
{ L_173 , L_174 ,
V_184 , V_146 , F_125 ( V_235 ) , 0 ,
NULL , V_144 } } ,
{ & V_236 ,
{ L_175 , L_176 ,
V_184 , V_146 , F_125 ( V_237 ) , 0 ,
NULL , V_144 } } ,
{ & V_238 ,
{ L_177 , L_178 ,
V_239 , 8 , NULL , 0x80 ,
NULL , V_144 } } ,
{ & V_240 ,
{ L_177 , L_178 ,
V_239 , 8 , NULL , 0x80 ,
NULL , V_144 } } ,
{ & V_241 ,
{ L_177 , L_178 ,
V_239 , 8 , NULL , 0x80 ,
NULL , V_144 } } ,
#line 314 "../../asn1/tcap/packet-tcap-template.c"
} ;
static T_14 * V_242 [] = {
& V_128 ,
& V_243 ,
& V_51 ,
& V_63 ,
& V_244 ,
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
#line 324 "../../asn1/tcap/packet-tcap-template.c"
} ;
T_19 * V_245 ;
V_126 = F_126 ( V_246 , V_247 , V_248 ) ;
F_127 ( V_126 , V_140 , F_128 ( V_140 ) ) ;
F_129 ( V_242 , F_128 ( V_242 ) ) ;
V_245 = F_130 ( V_126 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_131 ( V_245 , L_179 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_131 ( V_245 , L_180 ) ;
#endif
F_132 ( & V_249 , L_181 , V_250 ) ;
V_251 = F_133 () ;
F_134 ( V_245 , L_182 , L_183 ,
L_184 ,
& V_249 , V_250 ) ;
F_135 ( V_245 , L_185 ,
L_186 ,
L_187 ,
& V_133 ) ;
F_135 ( V_245 , L_188 ,
L_189 ,
L_190 ,
& V_252 ) ;
F_136 ( V_245 , L_191 ,
L_192 ,
L_193 ,
10 , & V_253 ) ;
F_136 ( V_245 , L_194 ,
L_195 ,
L_196 ,
10 , & V_254 ) ;
V_3 = F_137 ( V_255 , V_256 ) ;
V_5 = F_137 ( V_255 , V_256 ) ;
F_138 ( L_197 , F_111 , V_126 ) ;
V_4 = F_139 ( F_111 , V_126 ) ;
F_140 ( & V_257 ) ;
}
static void F_141 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_142 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_257 ( void ) {
if ( V_251 ) {
F_143 ( V_251 , F_141 ) ;
F_144 ( V_251 ) ;
}
V_251 = F_145 ( V_249 ) ;
F_143 ( V_251 , F_142 ) ;
F_146 () ;
}
static int
F_29 ( T_8 * T_9 , T_10 * T_11 , T_5 * T_6 , int T_7 )
{
T_14 V_258 , V_259 , V_260 ;
T_5 * V_29 ;
T_10 * V_50 ;
T_16 * V_261 ;
T_13 V_30 ;
T_3 V_31 ;
T_20 V_32 ;
T_1 V_33 ;
T_1 V_262 ;
T_1 V_263 ;
T_3 V_35 ;
while ( F_147 ( T_6 , T_7 ) > 0 )
{
V_259 = T_7 ;
T_7 = F_112 ( T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_258 = T_7 ;
T_7 = F_148 ( T_6 , T_7 , & V_33 , & V_35 ) ;
V_260 = T_7 ;
V_262 = V_258 - V_259 ;
V_263 = V_260 - V_258 ;
if ( V_31 )
{
V_261 = F_60 ( T_11 , T_6 , V_259 ,
V_33 + ( V_260 - V_259 ) ,
L_198 ) ;
V_50 = F_61 ( V_261 , V_243 ) ;
F_149 ( V_50 , V_141 , T_6 ,
V_259 , V_262 , V_32 ,
L_199 ) ;
F_150 ( V_50 , V_141 , T_6 , V_259 ,
V_262 , V_30 ) ;
F_150 ( V_50 , V_145 , T_6 , V_258 ,
V_263 , V_33 ) ;
if ( V_33 - ( 2 * V_35 ) )
{
V_29 = F_48 ( T_6 , T_7 , V_33 - ( 2 * V_35 ) ,
V_33 - ( 2 * V_35 ) ) ;
F_29 ( T_9 , V_50 , V_29 , 0 ) ;
}
if ( V_35 )
F_60 ( V_50 , T_6 , T_7 + V_33 - 2 , 2 , L_200 ) ;
T_7 += V_33 ;
}
else
{
V_261 = F_60 ( T_11 , T_6 , V_259 ,
V_33 + ( V_260 - V_259 ) ,
L_201 , V_32 ) ;
V_50 = F_61 ( V_261 , V_243 ) ;
F_150 ( V_50 , V_141 , T_6 , V_259 ,
V_262 , V_32 ) ;
F_150 ( V_50 , V_145 , T_6 ,
V_259 + V_262 , V_263 , V_33 ) ;
if ( V_33 )
{
V_29 = F_48 ( T_6 , T_7 , V_33 , V_33 ) ;
F_58 ( TRUE , T_9 , T_11 , V_29 , 0 ,
V_147 , NULL ) ;
}
T_7 += V_33 ;
}
}
return T_7 ;
}
static void F_115 ( struct V_264 * V_265 )
{
memset ( V_265 , 0 , sizeof( struct V_264 ) ) ;
}
static int
F_52 ( T_3 T_4 V_6 , T_5 * T_6 , int T_7 , T_8 * T_9 V_6 , T_10 * T_11 , int T_12 V_6 )
{
T_2 V_121 = NULL ;
T_3 V_266 = FALSE ;
struct V_119 * V_120 = NULL ;
if ( V_133 ) {
if ( ! V_131 ) {
V_120 = F_117 ( T_6 , T_9 -> V_36 , V_124 , V_55 ) ;
V_131 = TRUE ;
V_132 = V_120 ;
V_84 . V_134 = V_120 ;
} else{
V_120 = V_132 ;
V_84 . V_134 = V_120 ;
}
}
if ( V_120 ) {
if ( V_83 ) {
if ( V_120 -> V_135 ) {
if ( strncmp ( V_120 -> V_85 , V_83 , sizeof( V_120 -> V_85 ) ) != 0 ) {
F_118 ( V_120 -> V_85 , V_83 , sizeof( V_120 -> V_85 ) ) ;
if ( ( V_121 = F_119 ( V_136 , V_83 ) ) ) {
V_120 -> V_121 = V_121 ;
V_120 -> V_137 = TRUE ;
}
}
} else {
F_118 ( V_120 -> V_85 , V_83 , sizeof( V_120 -> V_85 ) ) ;
V_120 -> V_135 = TRUE ;
if ( ( V_121
= F_119 ( V_136 , V_83 ) ) ) {
V_120 -> V_121 = V_121 ;
V_120 -> V_137 = TRUE ;
} else {
if ( ( V_121 = F_8 ( T_9 -> V_36 -> V_267 ) ) ) {
V_120 -> V_121 = V_121 ;
V_120 -> V_137 = TRUE ;
}
}
}
} else {
if ( V_120 -> V_135 ) {
V_84 . V_85 = ( void * ) V_120 -> V_85 ;
V_84 . V_86 = TRUE ;
}
}
}
if ( V_120
&& V_120 -> V_137 ) {
V_121 = V_120 -> V_121 ;
V_266 = TRUE ;
}
if ( ! V_266 && V_268 ) {
V_266 = TRUE ;
V_121 = V_268 ;
}
if ( ! V_266 ) {
if ( V_136 && V_83 ) {
if ( ( V_121
= F_119 ( V_136 , V_83 ) ) ) {
V_266 = TRUE ;
} else {
if ( ( V_121
= F_8 ( T_9 -> V_36 -> V_267 ) ) ) {
V_266 = TRUE ;
} else {
V_121 = V_139 ;
V_266 = TRUE ;
}
}
} else {
if ( ( V_121 = F_8 ( T_9 -> V_36 -> V_267 ) ) ) {
V_266 = TRUE ;
} else {
V_121 = V_139 ;
V_266 = TRUE ;
}
}
} else {
}
if ( V_266 )
F_113 ( V_121 , T_6 , T_9 -> V_36 , T_11 ) ;
return T_7 ;
}
void F_151 ( T_2 V_269 , T_5 * T_6 , T_17 * V_36 , T_10 * T_11 ) {
V_268 = V_269 ;
F_49 {
F_111 ( T_6 , V_36 , T_11 ) ;
} F_152 {
V_268 = NULL ;
V_270 ;
} V_41 ;
V_268 = NULL ;
}
