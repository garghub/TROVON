static int
F_1 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 255U , NULL , FALSE ) ;
return T_3 ;
}
static int
F_3 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 65535U , NULL , FALSE ) ;
return T_3 ;
}
static int
F_4 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_5 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_2 , V_3 ) ;
return T_3 ;
}
static int
F_6 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_7 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_8 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_9 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_4 , V_5 ,
NULL ) ;
return T_3 ;
}
static int
F_10 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_11 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_6 , V_6 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_12 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_5 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_7 , V_8 ) ;
return T_3 ;
}
static int
F_13 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_5 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_9 , V_10 ) ;
return T_3 ;
}
static int
F_14 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 4294967295U , NULL , FALSE ) ;
return T_3 ;
}
static int
F_15 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ) ;
return T_3 ;
}
static int
F_17 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 , NULL ) ;
return T_3 ;
}
static int
F_19 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 58 "../../asn1/h283/h283.cnf"
T_9 V_11 = - 1 ;
const T_10 * V_12 = NULL ;
T_3 = F_9 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_13 , V_14 ,
& V_11 ) ;
#line 61 "../../asn1/h283/h283.cnf"
V_12 = F_20 ( V_11 , F_21 ( V_15 ) ) ;
if ( ! V_16 && V_12 ) {
F_22 ( T_5 -> V_17 -> V_18 , V_19 , L_1 , V_12 ) ;
V_16 = TRUE ;
}
return T_3 ;
}
static int
F_23 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 105 "../../asn1/h283/h283.cnf"
T_1 * V_20 = NULL ;
T_3 = F_11 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_6 , V_6 , FALSE , & V_20 ) ;
if ( V_20 && F_24 ( V_20 ) ) {
F_25 ( ( V_21 ) ? V_21 : V_22 , V_20 , T_5 -> V_17 , T_7 ) ;
}
return T_3 ;
}
static int
F_26 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 71 "../../asn1/h283/h283.cnf"
T_9 V_11 = - 1 ;
const T_10 * V_12 = NULL ;
T_3 = F_9 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_23 , V_24 ,
& V_11 ) ;
#line 74 "../../asn1/h283/h283.cnf"
V_12 = F_20 ( V_11 , F_21 ( V_25 ) ) ;
if ( ! V_16 && V_12 ) {
F_22 ( T_5 -> V_17 -> V_18 , V_19 , L_2 , V_12 ) ;
V_16 = TRUE ;
}
return T_3 ;
}
static int
F_27 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 84 "../../asn1/h283/h283.cnf"
T_9 V_11 = - 1 ;
const T_10 * V_12 = NULL ;
T_3 = F_9 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_26 , V_27 ,
& V_11 ) ;
#line 87 "../../asn1/h283/h283.cnf"
V_12 = F_20 ( V_11 , F_21 ( V_28 ) ) ;
if ( ! V_16 && V_12 ) {
F_22 ( T_5 -> V_17 -> V_18 , V_19 , L_3 , V_12 ) ;
V_16 = TRUE ;
}
return T_3 ;
}
static int
F_28 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_29 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_29 , V_30 ) ;
return T_3 ;
}
static int
F_30 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_5 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_31 , V_32 ) ;
return T_3 ;
}
static int
F_31 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 45 "../../asn1/h283/h283.cnf"
T_9 V_11 = - 1 ;
const T_10 * V_12 = NULL ;
T_3 = F_9 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_33 , V_34 ,
& V_11 ) ;
#line 48 "../../asn1/h283/h283.cnf"
V_12 = F_20 ( V_11 , F_21 ( V_35 ) ) ;
if ( ! V_16 && V_12 ) {
F_22 ( T_5 -> V_17 -> V_18 , V_19 , L_4 , V_12 ) ;
V_16 = TRUE ;
}
return T_3 ;
}
static int
F_32 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 95 "../../asn1/h283/h283.cnf"
T_1 * V_20 = NULL ;
T_3 = F_11 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_6 , V_6 , FALSE , & V_20 ) ;
if ( V_20 && F_24 ( V_20 ) ) {
F_25 ( ( V_36 ) ? V_36 : V_22 , V_20 , T_5 -> V_17 , F_33 ( T_7 ) ) ;
}
V_16 = TRUE ;
return T_3 ;
}
static int
F_34 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 32 "../../asn1/h283/h283.cnf"
T_9 V_37 = - 1 ;
const T_10 * V_12 = NULL ;
T_3 = F_9 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_38 , V_39 ,
& V_37 ) ;
#line 35 "../../asn1/h283/h283.cnf"
V_12 = F_20 ( V_37 , F_21 ( V_40 ) ) ;
if ( ! V_16 && V_12 ) {
F_22 ( T_5 -> V_17 -> V_18 , V_19 , L_5 , V_12 ) ;
V_16 = TRUE ;
}
return T_3 ;
}
static int
F_35 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_5 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_41 , V_42 ) ;
return T_3 ;
}
static int
F_36 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 19 "../../asn1/h283/h283.cnf"
T_9 V_43 = - 1 ;
const T_10 * V_12 = NULL ;
T_3 = F_9 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_44 , V_45 ,
& V_43 ) ;
#line 22 "../../asn1/h283/h283.cnf"
V_12 = F_20 ( V_43 , F_21 ( V_46 ) ) ;
if ( ! V_16 && V_12 ) {
F_37 ( T_5 -> V_17 -> V_18 , V_19 , V_12 ) ;
V_16 = TRUE ;
}
return T_3 ;
}
static int
F_38 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_5 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_47 , V_48 ) ;
return T_3 ;
}
static int F_39 ( T_1 * T_2 V_1 , T_11 * V_17 V_1 , T_6 * T_7 V_1 ) {
int T_3 = 0 ;
T_4 V_49 ;
F_40 ( & V_49 , V_50 , TRUE , V_17 ) ;
T_3 = F_38 ( T_2 , T_3 , & V_49 , T_7 , V_51 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int
F_41 ( T_1 * T_2 , T_11 * V_17 , T_6 * T_7 )
{
T_12 * V_52 = NULL ;
T_6 * V_53 = NULL ;
F_37 ( V_17 -> V_18 , V_54 , V_55 ) ;
V_16 = FALSE ;
V_52 = F_42 ( T_7 , V_56 , T_2 , 0 , - 1 , V_57 ) ;
V_53 = F_43 ( V_52 , V_58 ) ;
return F_39 ( T_2 , V_17 , V_53 ) ;
}
void F_44 ( void ) {
static T_13 V_59 [] = {
#line 1 "../../asn1/h283/packet-h283-hfarr.c"
{ & V_51 ,
{ L_6 , L_7 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_63 ,
{ L_8 , L_9 ,
V_64 , V_65 , NULL , 0 ,
L_10 , V_62 } } ,
{ & V_66 ,
{ L_11 , L_12 ,
V_64 , V_65 , NULL , 0 ,
L_10 , V_62 } } ,
{ & V_67 ,
{ L_13 , L_14 ,
V_64 , V_65 , NULL , 0 ,
L_15 , V_62 } } ,
{ & V_68 ,
{ L_16 , L_17 ,
V_69 , V_61 , NULL , 0 ,
L_18 , V_62 } } ,
{ & V_70 ,
{ L_19 , L_20 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_71 ,
{ L_21 , L_22 ,
V_64 , V_65 , F_21 ( V_72 ) , 0 ,
NULL , V_62 } } ,
{ & V_73 ,
{ L_23 , L_24 ,
V_74 , V_61 , NULL , 0 ,
L_25 , V_62 } } ,
{ & V_75 ,
{ L_26 , L_27 ,
V_60 , V_61 , NULL , 0 ,
L_28 , V_62 } } ,
{ & V_76 ,
{ L_29 , L_30 ,
V_60 , V_61 , NULL , 0 ,
L_28 , V_62 } } ,
{ & V_77 ,
{ L_31 , L_32 ,
V_64 , V_65 , NULL , 0 ,
L_33 , V_62 } } ,
{ & V_78 ,
{ L_34 , L_35 ,
V_64 , V_65 , NULL , 0 ,
L_15 , V_62 } } ,
{ & V_79 ,
{ L_36 , L_37 ,
V_64 , V_65 , F_21 ( V_46 ) , 0 ,
NULL , V_62 } } ,
{ & V_80 ,
{ L_38 , L_39 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_81 ,
{ L_40 , L_41 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_82 ,
{ L_42 , L_43 ,
V_64 , V_65 , NULL , 0 ,
L_44 , V_62 } } ,
{ & V_83 ,
{ L_45 , L_46 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_84 ,
{ L_47 , L_48 ,
V_64 , V_65 , NULL , 0 ,
L_15 , V_62 } } ,
{ & V_85 ,
{ L_49 , L_50 ,
V_64 , V_65 , NULL , 0 ,
L_15 , V_62 } } ,
{ & V_86 ,
{ L_51 , L_52 ,
V_87 , V_61 , NULL , 0 ,
L_53 , V_62 } } ,
{ & V_88 ,
{ L_54 , L_55 ,
V_64 , V_65 , F_21 ( V_40 ) , 0 ,
NULL , V_62 } } ,
{ & V_89 ,
{ L_56 , L_57 ,
V_64 , V_65 , F_21 ( V_35 ) , 0 ,
NULL , V_62 } } ,
{ & V_90 ,
{ L_58 , L_59 ,
V_64 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_91 ,
{ L_60 , L_61 ,
V_64 , V_65 , F_21 ( V_15 ) , 0 ,
NULL , V_62 } } ,
{ & V_92 ,
{ L_62 , L_63 ,
V_64 , V_65 , F_21 ( V_25 ) , 0 ,
NULL , V_62 } } ,
{ & V_93 ,
{ L_64 , L_65 ,
V_64 , V_65 , F_21 ( V_28 ) , 0 ,
NULL , V_62 } } ,
{ & V_94 ,
{ L_66 , L_67 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_95 ,
{ L_68 , L_69 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_96 ,
{ L_70 , L_71 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_97 ,
{ L_72 , L_73 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_98 ,
{ L_74 , L_75 ,
V_64 , V_65 , NULL , 0 ,
NULL , V_62 } } ,
{ & V_99 ,
{ L_76 , L_77 ,
V_60 , V_61 , NULL , 0 ,
NULL , V_62 } } ,
#line 80 "../../asn1/h283/packet-h283-template.c"
} ;
static T_14 * V_100 [] = {
& V_58 ,
#line 1 "../../asn1/h283/packet-h283-ettarr.c"
& V_2 ,
& V_4 ,
& V_7 ,
& V_47 ,
& V_44 ,
& V_29 ,
& V_9 ,
& V_41 ,
& V_38 ,
& V_33 ,
& V_13 ,
& V_23 ,
& V_26 ,
& V_31 ,
#line 86 "../../asn1/h283/packet-h283-template.c"
} ;
V_56 = F_45 ( V_101 , V_55 , V_102 ) ;
F_46 ( V_56 , V_59 , F_47 ( V_59 ) ) ;
F_48 ( V_100 , F_47 ( V_100 ) ) ;
F_49 ( V_102 , F_41 , V_56 ) ;
}
void F_50 ( void )
{
T_15 V_103 ;
V_103 = F_51 ( V_102 ) ;
F_52 ( L_78 , V_103 ) ;
V_36 = F_51 ( L_79 ) ;
V_21 = F_51 ( L_80 ) ;
V_22 = F_51 ( L_23 ) ;
}
