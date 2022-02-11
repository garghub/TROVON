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
#line 72 "./asn1/tcap/tcap.cnf"
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
#line 67 "./asn1/tcap/tcap.cnf"
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_9 , 8 , TRUE , F_17 ) ;
return T_7 ;
}
static int
F_21 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 62 "./asn1/tcap/tcap.cnf"
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
#line 77 "./asn1/tcap/tcap.cnf"
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
#line 82 "./asn1/tcap/tcap.cnf"
T_5 * V_29 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
T_1 V_33 , V_34 ;
volatile T_1 V_35 ;
T_14 V_36 ;
V_34 = F_46 ( T_9 -> V_37 , T_11 , T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_34 = F_47 ( T_9 -> V_37 , T_11 , T_6 , V_34 , & V_33 , & V_36 ) ;
V_29 = F_48 ( T_6 , T_7 , V_33 + V_34 - T_7 ) ;
if ( ! V_29 )
return V_34 ;
V_35 = T_7 ;
F_49 {
V_35 = F_27 ( T_9 , T_11 , T_6 , V_35 ,
V_38 , T_12 , V_39 ,
NULL ) ;
}
F_50 {
F_51 ( T_6 , T_9 -> V_37 , T_11 , V_40 , V_41 ) ;
}
V_42 ;
T_7 = V_35 ;
F_52 ( T_4 , V_29 , 0 , T_9 , V_43 , T_12 ) ;
return T_7 ;
}
static int
F_53 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_44 , T_12 , V_45 ) ;
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
V_46 , T_12 , V_47 ) ;
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
#line 131 "./asn1/tcap/tcap.cnf"
T_5 * V_48 ;
T_15 V_33 , V_49 ;
T_10 * V_50 ;
int V_51 ;
T_12 = V_52 ;
V_51 = T_7 ;
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 8 , TRUE , F_57 ) ;
F_60 ( T_9 -> V_53 ) ;
T_7 = V_51 ;
V_50 = F_61 ( T_11 , T_6 , T_7 , - 1 , V_54 , NULL , L_2 ) ;
T_7 = F_58 ( T_4 , T_9 , V_50 , T_6 , T_7 , V_55 ,
& V_48 ) ;
if ( V_48 ) {
V_33 = F_62 ( V_48 , 0 ) ;
switch( V_33 ) {
case 1 :
V_56 -> V_57 = F_63 ( V_48 , 0 ) ;
break;
case 2 :
V_56 -> V_57 = F_64 ( V_48 , 0 ) ;
break;
case 4 :
V_56 -> V_57 = F_65 ( V_48 , 0 ) ;
break;
default:
V_56 -> V_57 = 0 ;
break;
}
if ( V_33 ) {
F_66 ( T_9 -> V_37 -> V_58 , V_59 , L_3 ) ;
for ( V_49 = 0 ; V_49 < V_33 ; V_49 ++ ) {
F_67 ( T_9 -> V_37 -> V_58 , V_59 , L_4 , F_63 ( V_48 , V_49 ) ) ;
}
F_66 ( T_9 -> V_37 -> V_58 , V_59 , L_5 ) ;
}
}
return T_7 ;
}
static int
F_68 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 215 "./asn1/tcap/tcap.cnf"
V_56 -> V_60 = V_61 ;
F_69 ( T_9 -> V_37 -> V_58 , V_59 , L_6 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_62 , T_12 , V_63 ) ;
return T_7 ;
}
static int
F_70 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 174 "./asn1/tcap/tcap.cnf"
T_5 * V_48 ;
T_15 V_33 , V_49 ;
T_10 * V_50 ;
int V_51 ;
T_12 = V_52 ;
V_51 = T_7 ;
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 9 , TRUE , F_57 ) ;
F_60 ( T_9 -> V_53 ) ;
T_7 = V_51 ;
V_50 = F_61 ( T_11 , T_6 , T_7 , - 1 , V_64 , NULL , L_7 ) ;
T_7 = F_58 ( T_4 , T_9 , V_50 , T_6 , T_7 , V_65 ,
& V_48 ) ;
if ( V_48 ) {
V_33 = F_62 ( V_48 , 0 ) ;
switch( V_33 ) {
case 1 :
V_56 -> V_66 = F_63 ( V_48 , 0 ) ;
break;
case 2 :
V_56 -> V_66 = F_64 ( V_48 , 0 ) ;
break;
case 4 :
V_56 -> V_66 = F_65 ( V_48 , 0 ) ;
break;
default:
V_56 -> V_66 = 0 ;
break;
}
if ( V_33 ) {
F_66 ( T_9 -> V_37 -> V_58 , V_59 , L_8 ) ;
for( V_49 = 0 ; V_49 < V_33 ; V_49 ++ ) {
F_67 ( T_9 -> V_37 -> V_58 , V_59 , L_4 , F_63 ( V_48 , V_49 ) ) ;
}
F_66 ( T_9 -> V_37 -> V_58 , V_59 , L_5 ) ;
}
}
return T_7 ;
}
static int
F_71 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 229 "./asn1/tcap/tcap.cnf"
V_56 -> V_60 = V_67 ;
F_69 ( T_9 -> V_37 -> V_58 , V_59 , L_9 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_68 , T_12 , V_69 ) ;
return T_7 ;
}
static int
F_72 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 236 "./asn1/tcap/tcap.cnf"
V_56 -> V_60 = V_70 ;
F_69 ( T_9 -> V_37 -> V_58 , V_59 , L_10 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_71 , T_12 , V_72 ) ;
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
V_73 , T_12 , V_74 ,
NULL ) ;
return T_7 ;
}
static int
F_76 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 243 "./asn1/tcap/tcap.cnf"
V_56 -> V_60 = V_75 ;
F_69 ( T_9 -> V_37 -> V_58 , V_59 , L_11 ) ;
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_76 , T_12 , V_77 ) ;
return T_7 ;
}
static int
F_77 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_78 , T_12 , V_79 ,
NULL ) ;
return T_7 ;
}
static int
F_78 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_79 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_80 , T_12 , V_81 ,
NULL ) ;
return T_7 ;
}
static int
F_80 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 116 "./asn1/tcap/tcap.cnf"
T_7 = F_81 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_82 ) ;
V_83 . V_84 = ( const void * ) V_82 ;
V_83 . V_85 = TRUE ;
return T_7 ;
}
static int
F_82 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_83 ( T_4 , T_11 , T_6 , T_7 , T_9 , T_12 , NULL ) ;
return T_7 ;
}
static int
F_84 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_86 , T_12 , V_87 ) ;
return T_7 ;
}
static int
F_85 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_88 , T_12 , V_89 ) ;
return T_7 ;
}
static int
F_86 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 0 , TRUE , F_85 ) ;
return T_7 ;
}
int
F_87 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_90 , T_12 , V_91 ,
NULL ) ;
return T_7 ;
}
static int
F_88 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_79 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_92 , T_12 , V_93 ,
NULL ) ;
return T_7 ;
}
static int
F_89 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 121 "./asn1/tcap/tcap.cnf"
T_7 = F_81 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_82 ) ;
V_83 . V_84 = ( const void * ) V_82 ;
V_83 . V_85 = TRUE ;
return T_7 ;
}
static int
F_90 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_94 , T_12 , V_95 ) ;
return T_7 ;
}
static int
F_91 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_96 , T_12 , V_97 ) ;
return T_7 ;
}
static int
F_92 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 0 , TRUE , F_91 ) ;
return T_7 ;
}
static int
F_93 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_79 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_98 , T_12 , V_99 ,
NULL ) ;
return T_7 ;
}
static int
F_94 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
#line 126 "./asn1/tcap/tcap.cnf"
T_7 = F_81 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_82 ) ;
V_83 . V_84 = ( const void * ) V_82 ;
V_83 . V_85 = TRUE ;
return T_7 ;
}
static int
F_95 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
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
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_100 , T_12 , V_101 ,
NULL ) ;
return T_7 ;
}
static int
F_99 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_102 , T_12 , V_103 ) ;
return T_7 ;
}
static int
F_100 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_104 , T_12 , V_105 ) ;
return T_7 ;
}
static int
F_101 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 1 , TRUE , F_100 ) ;
return T_7 ;
}
static int
F_102 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_24 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_103 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_54 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_106 , T_12 , V_107 ) ;
return T_7 ;
}
static int
F_104 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_18 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_108 , T_12 , V_109 ) ;
return T_7 ;
}
static int
F_105 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_20 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 4 , TRUE , F_104 ) ;
return T_7 ;
}
int
F_16 ( T_3 T_4 V_6 , T_5 * T_6 V_6 , int T_7 V_6 , T_8 * T_9 V_6 , T_10 * T_11 V_6 , int T_12 V_6 ) {
T_7 = F_27 ( T_9 , T_11 , T_6 , T_7 ,
V_110 , T_12 , V_111 ,
NULL ) ;
return T_7 ;
}
static int F_106 ( T_5 * T_6 V_6 , T_16 * V_37 V_6 , T_10 * T_11 V_6 , void * T_17 V_6 ) {
int T_7 = 0 ;
T_8 V_112 ;
F_107 ( & V_112 , V_113 , TRUE , V_37 ) ;
T_7 = F_87 ( FALSE , T_6 , T_7 , & V_112 , T_11 , V_114 ) ;
return T_7 ;
}
static int F_108 ( T_5 * T_6 V_6 , T_16 * V_37 V_6 , T_10 * T_11 V_6 , void * T_17 V_6 ) {
int T_7 = 0 ;
T_8 V_112 ;
F_107 ( & V_112 , V_113 , TRUE , V_37 ) ;
T_7 = F_16 ( FALSE , T_6 , T_7 , & V_112 , T_11 , V_115 ) ;
return T_7 ;
}
static void
F_109 ( T_18 V_116 , const char * V_117 , ... )
{
T_19 V_118 ;
if ( V_116 > V_119 ) return;
va_start ( V_118 , V_117 ) ;
vfprintf ( V_120 , V_117 , V_118 ) ;
va_end ( V_118 ) ;
}
static T_14
F_110 ( T_20 V_121 , T_20 V_122 )
{
const struct V_123 * V_124 = ( const struct V_123 * ) V_121 ;
const struct V_123 * V_125 = ( const struct V_123 * ) V_122 ;
return ( V_124 -> V_126 == V_125 -> V_126 ) ;
}
static T_18
F_111 ( T_20 V_127 )
{
const struct V_123 * V_128 = ( const struct V_123 * ) V_127 ;
return V_128 -> V_126 ;
}
static T_14
F_112 ( T_20 V_121 , T_20 V_122 )
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
F_113 ( T_20 V_127 )
{
const struct V_129 * V_128 = ( const struct V_129 * ) V_127 ;
T_18 V_133 ;
V_133 = V_128 -> V_132 ;
return V_133 ;
}
static T_14
F_114 ( T_20 V_121 , T_20 V_122 )
{
const struct V_134 * V_124 = ( const struct V_134 * ) V_121 ;
const struct V_134 * V_125 = ( const struct V_134 * ) V_122 ;
if ( V_124 -> V_130 == V_125 -> V_130 ) {
if ( ( V_124 -> V_135 == V_125 -> V_135 ) &&
( V_124 -> V_136 == V_125 -> V_136 ) &&
( V_124 -> V_57 == V_125 -> V_57 ) &&
( V_124 -> V_66 == V_125 -> V_66 ) ) {
return TRUE ;
}
else if ( ( V_124 -> V_135 == V_125 -> V_136 ) &&
( V_124 -> V_136 == V_125 -> V_135 ) &&
( V_124 -> V_57 == V_125 -> V_66 ) &&
( V_124 -> V_66 == V_125 -> V_57 ) ) {
return TRUE ;
}
}
return FALSE ;
}
static T_18
F_115 ( T_20 V_127 )
{
const struct V_134 * V_128 = ( const struct V_134 * ) V_127 ;
T_18 V_133 ;
V_133 = V_128 -> V_57 + V_128 -> V_66 ;
return V_133 ;
}
static T_14
F_116 ( T_20 V_121 , T_20 V_122 )
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
F_117 ( T_20 V_127 )
{
const struct V_137 * V_128 = ( const struct V_137 * ) V_127 ;
T_18 V_133 ;
V_133 = V_128 -> V_132 ;
return V_133 ;
}
static T_14
F_118 ( T_20 V_121 , T_20 V_122 )
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
F_119 ( T_20 V_127 )
{
const struct V_138 * V_128 = ( const struct V_138 * ) V_127 ;
T_18 V_133 ;
V_133 = V_128 -> V_132 ;
return V_133 ;
}
static void
F_120 ( struct V_139 * V_140 ,
T_16 * V_37 )
{
V_140 -> V_141 -> V_142 = V_37 -> V_143 ;
V_140 -> V_141 -> V_144 = 0 ;
V_140 -> V_141 -> V_145 = FALSE ;
V_140 -> V_141 -> V_146 = V_37 -> V_147 ;
}
static struct V_139 *
F_121 ( struct V_139 * V_148 ,
struct V_149 * V_150 ,
T_16 * V_37 )
{
struct V_139 * V_151 = NULL ;
#ifdef F_122
V_151 = (struct V_139 * ) F_123 ( sizeof( struct V_139 ) ) ;
#else
V_151 = F_124 ( F_125 () , struct V_139 ) ;
#endif
V_151 -> V_141 = V_150 ;
V_150 -> V_152 = V_151 ;
V_151 -> V_153 = V_148 -> V_153 ;
V_151 -> V_141 -> V_142 = V_37 -> V_143 ;
V_151 -> V_154 = NULL ;
V_151 -> V_155 = V_148 ;
V_151 -> V_156 = FALSE ;
#ifdef F_126
F_109 ( 10 , L_12 , V_151 -> V_141 -> V_126 ) ;
#endif
V_148 -> V_154 = V_151 ;
if ( V_148 -> V_141 -> V_144 == 0 ) {
#ifdef F_126
F_109 ( 10 , L_13 ) ;
#endif
V_148 -> V_141 -> V_144 = V_37 -> V_143 - 1 ;
}
return V_151 ;
}
static void
F_127 ( struct V_157 * V_158 ,
T_16 * V_37 )
{
V_158 -> V_141 -> V_142 = V_37 -> V_143 ;
V_158 -> V_141 -> V_144 = 0 ;
V_158 -> V_141 -> V_145 = FALSE ;
V_158 -> V_141 -> V_146 = V_37 -> V_147 ;
}
static struct V_157 *
F_128 ( struct V_157 * V_159 ,
struct V_149 * V_150 ,
T_16 * V_37 )
{
struct V_157 * V_160 = NULL ;
#ifdef F_122
V_160 = (struct V_157 * ) F_123 ( sizeof( struct V_157 ) ) ;
#else
V_160 = F_124 ( F_125 () , struct V_157 ) ;
#endif
V_160 -> V_141 = V_150 ;
V_150 -> V_161 = V_160 ;
V_160 -> V_162 = V_159 -> V_162 ;
V_160 -> V_141 -> V_142 = V_37 -> V_143 ;
V_160 -> V_163 = NULL ;
V_160 -> V_164 = V_159 ;
V_160 -> V_156 = FALSE ;
#ifdef F_126
F_109 ( 10 , L_14 , V_160 -> V_141 -> V_126 ) ;
#endif
V_159 -> V_163 = V_160 ;
if ( V_159 -> V_141 -> V_144 == 0 ) {
#ifdef F_126
F_109 ( 10 , L_13 ) ;
#endif
V_159 -> V_141 -> V_144 = V_37 -> V_143 - 1 ;
}
return V_160 ;
}
static struct V_165 *
F_129 ( struct V_165 * V_166 ,
struct V_149 * V_150 )
{
struct V_165 * V_167 = NULL ;
#ifdef F_122
V_167 = (struct V_165 * ) F_123 ( sizeof( struct V_165 ) ) ;
#else
V_167 = F_124 ( F_125 () , struct V_165 ) ;
#endif
V_167 -> V_141 = V_150 ;
V_150 -> V_168 = V_167 ;
V_167 -> V_169 = V_166 -> V_169 ;
V_167 -> V_170 = NULL ;
V_167 -> V_171 = V_166 ;
V_167 -> V_156 = FALSE ;
#ifdef F_126
F_109 ( 10 , L_15 , V_167 -> V_141 -> V_126 ) ;
#endif
V_166 -> V_170 = V_167 ;
return V_167 ;
}
static struct V_172 *
F_130 ( struct V_172 * V_173 ,
struct V_149 * V_150 )
{
struct V_172 * V_174 = NULL ;
#ifdef F_122
V_174 = (struct V_175 * ) F_123 ( sizeof( struct V_172 ) ) ;
#else
V_174 = F_124 ( F_125 () , struct V_172 ) ;
#endif
V_174 -> V_141 = V_150 ;
V_150 -> V_176 = V_174 ;
V_174 -> V_177 = V_173 -> V_177 ;
V_174 -> V_178 = NULL ;
V_174 -> V_179 = V_173 ;
V_174 -> V_156 = FALSE ;
#ifdef F_126
F_109 ( 10 , L_16 , V_174 -> V_141 -> V_126 ) ;
#endif
V_173 -> V_178 = V_174 ;
return V_174 ;
}
static struct V_139 *
F_131 ( struct V_129 * V_180 ,
T_16 * V_37 , T_3 V_181 )
{
struct V_139 * V_140 = NULL ;
V_140 = (struct V_139 * ) F_12 ( V_182 , V_180 ) ;
if( V_140 ) {
do {
if ( V_140 -> V_141 ) {
if ( ( V_181 &&
V_37 -> V_143 == V_140 -> V_141 -> V_142 )
||
( ! V_181 &&
V_37 -> V_143 >= V_140 -> V_141 -> V_142 &&
( V_140 -> V_141 -> V_144 ? V_37 -> V_143 <= V_140 -> V_141 -> V_144 : 1 )
)
) {
#ifdef F_126
F_109 ( 10 , L_17 , V_140 -> V_141 -> V_126 ) ;
#endif
return V_140 ;
}
#ifdef F_126
F_109 ( 60 , L_18 , V_140 -> V_141 -> V_126 ) ;
#endif
}
if( V_140 -> V_154 == NULL ) {
#ifdef F_126
F_109 ( 23 , L_19 ) ;
#endif
break;
}
V_140 = V_140 -> V_154 ;
} while ( V_140 != NULL ) ;
} else {
#ifdef F_126
F_109 ( 23 , L_20 ) ;
#endif
}
return NULL ;
}
static struct V_165 *
F_132 ( struct V_134 * V_183 ,
T_16 * V_37 )
{
struct V_165 * V_184 = NULL ;
V_184 = (struct V_165 * ) F_12 ( V_185 , V_183 ) ;
if( V_184 ) {
do {
if ( V_184 -> V_141 ) {
if ( V_37 -> V_143 >= V_184 -> V_141 -> V_142 &&
( V_184 -> V_141 -> V_144 ? V_37 -> V_143 <= V_184 -> V_141 -> V_144 : 1 ) ) {
#ifdef F_126
F_109 ( 10 , L_21 , V_184 -> V_141 -> V_126 ) ;
#endif
return V_184 ;
}
#ifdef F_126
F_109 ( 60 , L_22 , V_184 -> V_141 -> V_126 ) ;
#endif
}
if( V_184 -> V_170 == NULL ) {
#ifdef F_126
F_109 ( 23 , L_23 ) ;
#endif
break;
}
V_184 = V_184 -> V_170 ;
} while ( V_184 != NULL ) ;
} else {
#ifdef F_126
F_109 ( 23 , L_24 ) ;
#endif
}
return NULL ;
}
static struct V_172 *
F_133 ( struct V_137 * V_186 ,
T_16 * V_37 , T_3 V_187 )
{
struct V_172 * V_188 = NULL ;
V_188 = (struct V_172 * ) F_12 ( V_189 , V_186 ) ;
if( V_188 ) {
do {
if ( V_188 -> V_141 ) {
if ( ( V_187 &&
( V_188 -> V_141 -> V_144 ? V_37 -> V_143 == V_188 -> V_141 -> V_144 : 1 )
)
||
( ! V_187 &&
V_37 -> V_143 >= V_188 -> V_141 -> V_142 &&
( V_188 -> V_141 -> V_144 ? V_37 -> V_143 <= V_188 -> V_141 -> V_144 : 1 )
)
) {
#ifdef F_126
F_109 ( 10 , L_25 , V_188 -> V_141 -> V_126 ) ;
#endif
return V_188 ;
}
#ifdef F_126
F_109 ( 60 , L_26 , V_188 -> V_141 -> V_126 ) ;
#endif
}
if( V_188 -> V_178 == NULL ) {
#ifdef F_126
F_109 ( 23 , L_27 ) ;
#endif
break;
}
V_188 = V_188 -> V_178 ;
} while ( V_188 != NULL ) ;
} else {
#ifdef F_126
F_109 ( 23 , L_28 ) ;
#endif
}
return NULL ;
}
static struct V_149 *
F_134 ( struct V_123 * V_190 ,
T_16 * V_37 )
{
struct V_123 * V_191 ;
struct V_149 * V_192 = NULL ;
#ifdef F_122
V_191 = (struct V_123 * ) F_135 ( sizeof( struct V_123 ) ) ;
#else
V_191 = F_136 ( F_125 () , struct V_123 ) ;
#endif
V_191 -> V_126 = V_190 -> V_126 ;
#ifdef F_122
V_192 = (struct V_149 * ) F_123 ( sizeof( struct V_149 ) ) ;
#else
V_192 = F_124 ( F_125 () , struct V_149 ) ;
#endif
V_192 -> V_128 = V_191 ;
V_192 -> V_126 = V_190 -> V_126 ;
V_192 -> V_142 = V_37 -> V_143 ;
#ifdef F_126
F_109 ( 10 , L_29 , V_192 -> V_126 ) ;
#endif
F_2 ( V_193 , V_191 , V_192 ) ;
return V_192 ;
}
static struct V_139 *
F_137 ( struct V_129 * V_180 ,
struct V_149 * V_150 )
{
struct V_129 * V_194 ;
struct V_139 * V_151 = NULL ;
#ifdef F_122
V_194 = (struct V_129 * ) F_135 ( sizeof( struct V_129 ) ) ;
#else
V_194 = F_136 ( F_125 () , struct V_129 ) ;
#endif
V_194 -> V_130 = V_180 -> V_130 ;
V_194 -> V_132 = V_180 -> V_132 ;
V_194 -> V_131 = V_180 -> V_131 ;
#ifdef F_122
V_151 = (struct V_139 * ) F_123 ( sizeof( struct V_139 ) ) ;
#else
V_151 = F_124 ( F_125 () , struct V_139 ) ;
#endif
V_151 -> V_153 = V_194 ;
V_151 -> V_141 = V_150 ;
V_150 -> V_152 = V_151 ;
V_151 -> V_156 = TRUE ;
V_151 -> V_154 = NULL ;
V_151 -> V_155 = NULL ;
#ifdef F_126
F_109 ( 10 , L_17 , V_151 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_182 , V_194 , V_151 ) ;
return V_151 ;
}
static struct V_165 *
F_138 ( struct V_134 * V_183 ,
struct V_149 * V_150 )
{
struct V_134 * V_195 ;
struct V_165 * V_167 = NULL ;
#ifdef F_122
V_195 = (struct V_134 * ) F_135 ( sizeof( struct V_134 ) ) ;
#else
V_195 = F_136 ( F_125 () , struct V_134 ) ;
#endif
V_195 -> V_130 = V_183 -> V_130 ;
V_195 -> V_57 = V_183 -> V_57 ;
V_195 -> V_66 = V_183 -> V_66 ;
V_195 -> V_135 = V_183 -> V_135 ;
V_195 -> V_136 = V_183 -> V_136 ;
#ifdef F_122
V_167 = (struct V_165 * ) F_123 ( sizeof( struct V_165 ) ) ;
#else
V_167 = F_124 ( F_125 () , struct V_165 ) ;
#endif
V_167 -> V_169 = V_195 ;
V_167 -> V_141 = V_150 ;
V_150 -> V_168 = V_167 ;
V_167 -> V_156 = TRUE ;
V_167 -> V_170 = NULL ;
V_167 -> V_171 = NULL ;
#ifdef F_126
F_109 ( 10 , L_21 , V_167 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_185 , V_195 , V_167 ) ;
return V_167 ;
}
static struct V_172 *
F_139 ( struct V_137 * V_186 ,
struct V_149 * V_150 )
{
struct V_137 * V_196 ;
struct V_172 * V_174 = NULL ;
#ifdef F_122
V_196 = (struct V_137 * ) F_135 ( sizeof( struct V_137 ) ) ;
#else
V_196 = F_136 ( F_125 () , struct V_137 ) ;
#endif
V_196 -> V_130 = V_186 -> V_130 ;
V_196 -> V_132 = V_186 -> V_132 ;
V_196 -> V_131 = V_186 -> V_131 ;
#ifdef F_122
V_174 = (struct V_172 * ) F_123 ( sizeof( struct V_172 ) ) ;
#else
V_174 = F_124 ( F_125 () , struct V_172 ) ;
#endif
V_174 -> V_177 = V_196 ;
V_174 -> V_141 = V_150 ;
V_150 -> V_176 = V_174 ;
V_174 -> V_156 = TRUE ;
V_174 -> V_178 = NULL ;
V_174 -> V_179 = NULL ;
#ifdef F_126
F_109 ( 10 , L_25 , V_174 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_189 , V_196 , V_174 ) ;
return V_174 ;
}
static struct V_157 *
F_140 ( struct V_138 * V_197 ,
struct V_149 * V_150 )
{
struct V_138 * V_198 ;
struct V_157 * V_160 = NULL ;
#ifdef F_122
V_198 = (struct V_138 * ) F_135 ( sizeof( struct V_138 ) ) ;
#else
V_198 = F_136 ( F_125 () , struct V_138 ) ;
#endif
V_198 -> V_130 = V_197 -> V_130 ;
V_198 -> V_132 = V_197 -> V_132 ;
V_198 -> V_135 = V_197 -> V_135 ;
V_198 -> V_136 = V_197 -> V_136 ;
#ifdef F_122
V_160 = (struct V_157 * ) F_123 ( sizeof( struct V_157 ) ) ;
#else
V_160 = F_124 ( F_125 () , struct V_157 ) ;
#endif
V_160 -> V_162 = V_198 ;
V_160 -> V_141 = V_150 ;
V_150 -> V_161 = V_160 ;
V_160 -> V_156 = TRUE ;
V_160 -> V_163 = NULL ;
V_160 -> V_164 = NULL ;
#ifdef F_126
F_109 ( 10 , L_30 , V_160 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_199 , V_198 , V_160 ) ;
return V_160 ;
}
static struct V_165 *
F_141 ( struct V_134 * V_183 ,
struct V_149 * V_150 )
{
struct V_165 * V_200 = NULL ;
struct V_165 * V_184 = NULL ;
V_200 = (struct V_165 * )
F_12 ( V_185 , V_183 ) ;
if ( V_200 ) {
do {
if ( ! V_200 -> V_170 ) {
V_184 = F_129 ( V_200 ,
V_150 ) ;
break;
}
V_200 = V_200 -> V_170 ;
} while ( V_200 != NULL );
} else {
V_184 = F_138 ( V_183 ,
V_150 ) ;
}
return V_184 ;
}
static struct V_172 *
F_142 ( struct V_137 * V_186 ,
struct V_149 * V_150 )
{
struct V_172 * V_201 = NULL ;
struct V_172 * V_188 = NULL ;
V_201 = (struct V_172 * )
F_12 ( V_189 , V_186 ) ;
if ( V_201 ) {
do {
if ( ! V_201 -> V_178 ) {
V_188 = F_130 ( V_201 ,
V_150 ) ;
break;
}
V_201 = V_201 -> V_178 ;
} while ( V_201 != NULL );
} else {
V_188 = F_139 ( V_186 ,
V_150 ) ;
}
return V_188 ;
}
void
F_143 ( void )
{
if ( V_193 != NULL ) {
#ifdef F_126
F_109 ( 16 , L_31 ) ;
#endif
F_144 ( V_193 ) ;
}
if ( V_182 != NULL ) {
#ifdef F_126
F_109 ( 16 , L_32 ) ;
#endif
F_144 ( V_182 ) ;
}
if ( V_185 != NULL ) {
#ifdef F_126
F_109 ( 16 , L_33 ) ;
#endif
F_144 ( V_185 ) ;
}
if ( V_189 != NULL ) {
#ifdef F_126
F_109 ( 16 , L_34 ) ;
#endif
F_144 ( V_189 ) ;
}
if ( V_199 != NULL ) {
#ifdef F_126
F_109 ( 16 , L_35 ) ;
#endif
F_144 ( V_199 ) ;
}
#ifdef F_126
F_109 ( 16 , L_36 ) ;
#endif
V_193 = F_145 ( F_111 , F_110 ) ;
V_182 = F_145 ( F_113 , F_112 ) ;
V_185 = F_145 ( F_115 , F_114 ) ;
V_189 = F_145 ( F_117 , F_116 ) ;
V_199 = F_145 ( F_119 , F_118 ) ;
V_202 = 1 ;
V_203 = V_204 || V_205 & V_206 ;
}
static struct V_149 *
F_146 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_150 = NULL ;
struct V_123 V_209 ;
struct V_139 * V_140 , * V_151 = NULL ;
struct V_129 V_210 ;
T_21 * V_211 ;
T_21 * V_212 = NULL ;
T_10 * V_213 = NULL ;
#ifdef F_126
F_109 ( 51 , L_37 , F_147 ( F_148 () , & V_37 -> V_214 ) , V_208 -> V_57 , F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
#endif
V_210 . V_132 = V_208 -> V_57 ;
if ( V_37 -> V_214 . type == V_216 && V_37 -> V_215 . type == V_216 )
{
V_210 . V_131 = F_149 ( ( const V_217 * ) V_37 -> V_214 . T_17 ) ;
} else {
V_210 . V_131 = F_150 ( F_147 ( F_148 () , & V_37 -> V_214 ) ) ;
}
V_210 . V_130 = F_113 ( & V_210 ) ;
#ifdef F_126
F_109 ( 10 , L_38 , V_37 -> V_143 ) ;
F_109 ( 11 , L_39 , V_210 . V_130 ) ;
F_109 ( 51 , L_40 , F_147 ( F_148 () , & V_37 -> V_214 ) ) ;
F_109 ( 51 , L_41 , V_210 . V_132 ) ;
#endif
V_140 = (struct V_139 * )
F_12 ( V_182 , & V_210 ) ;
if ( V_140 ) {
do {
if ( V_37 -> V_143 == V_140 -> V_141 -> V_142 ) {
#ifdef F_126
F_109 ( 22 , L_42 ) ;
#endif
V_150 = V_140 -> V_141 ;
break;
}
if ( ! V_140 -> V_154 ) {
if ( ( V_140 -> V_141 -> V_144 != 0
&& V_37 -> V_143 > V_140 -> V_141 -> V_142
&& ( T_18 ) V_37 -> V_147 . V_218 > ( T_18 ) ( V_140 -> V_141 -> V_146 . V_218 + V_219 )
) ||
( V_140 -> V_141 -> V_144 == 0
&& V_37 -> V_143 > V_140 -> V_141 -> V_142
&& ( T_18 ) V_37 -> V_147 . V_218 > ( T_18 ) ( V_140 -> V_141 -> V_146 . V_218 + V_220 )
)
)
{
#ifdef F_126
F_109 ( 12 , L_43 , V_210 . V_130 ) ;
F_109 ( 12 , L_44 , V_37 -> V_143 , V_140 -> V_141 -> V_144 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_134 ( & V_209 , V_37 ) ;
V_151 = F_121 ( V_140 ,
V_150 ,
V_37 ) ;
#ifdef F_126
F_109 ( 12 , L_45 , V_210 . V_130 ) ;
#endif
F_120 ( V_151 , V_37 ) ;
} else {
if ( V_140 -> V_141 -> V_221 ) {
#ifdef F_126
F_109 ( 12 , L_46 , V_210 . V_130 ) ;
F_109 ( 12 , L_44 , V_37 -> V_143 , V_140 -> V_141 -> V_144 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_134 ( & V_209 , V_37 ) ;
V_151 = F_121 ( V_140 ,
V_150 ,
V_37 ) ;
#ifdef F_126
F_109 ( 12 , L_47 , V_210 . V_130 ) ;
#endif
F_120 ( V_151 , V_37 ) ;
} else {
#ifdef F_126
F_109 ( 21 , L_48 , V_140 -> V_141 -> V_142 ) ;
#endif
V_150 = V_140 -> V_141 ;
if ( V_203 && T_11 ) {
V_213 = F_61 ( T_11 , T_6 , 0 , - 1 , V_222 , & V_212 , L_49 ) ;
F_151 ( V_212 ) ;
V_211 = F_152 ( V_213 , V_223 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_50 ,
V_150 -> V_126 , V_150 -> V_142 ) ;
F_151 ( V_211 ) ;
}
return V_150 ;
}
}
break;
}
V_140 = V_140 -> V_154 ;
} while ( V_140 != NULL );
} else {
#ifdef F_126
F_109 ( 10 , L_51 , V_210 . V_130 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_134 ( & V_209 , V_37 ) ;
V_140 = F_137 ( & V_210 , V_150 ) ;
#ifdef F_126
F_109 ( 11 , L_45 , V_210 . V_130 ) ;
F_109 ( 11 , L_52 , V_37 -> V_143 ) ;
#endif
F_120 ( V_140 , V_37 ) ;
}
if ( V_203 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_213 = F_61 ( T_11 , T_6 , 0 , 0 , V_222 , & V_212 , L_49 ) ;
F_151 ( V_212 ) ;
V_211 = F_153 ( V_213 , V_224 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_151 ( V_211 ) ;
if( V_150 -> V_144 != 0 ) {
#ifdef F_126
F_109 ( 20 , L_53 , V_150 -> V_144 ) ;
#endif
V_211 = F_152 ( V_213 , V_225 , T_6 , 0 , 0 ,
V_150 -> V_144 ,
L_54 ,
V_150 -> V_144 ) ;
F_151 ( V_211 ) ;
}
}
return V_150 ;
}
static struct V_149 *
F_154 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_150 = NULL ;
struct V_165 * V_184 ;
struct V_134 V_226 ;
struct V_129 V_210 ;
struct V_139 * V_140 ;
struct V_137 V_227 ;
T_21 * V_211 ;
T_21 * V_212 = NULL ;
T_10 * V_213 = NULL ;
#ifdef F_126
F_109 ( 51 , L_55 , F_147 ( F_148 () , & V_37 -> V_214 ) , V_208 -> V_57 , F_147 ( F_148 () , & V_37 -> V_215 ) , V_208 -> V_66 ) ;
F_109 ( 10 , L_56 , V_37 -> V_143 ) ;
#endif
V_226 . V_57 = V_208 -> V_57 ;
V_226 . V_66 = V_208 -> V_66 ;
if ( V_37 -> V_214 . type == V_216 && V_37 -> V_215 . type == V_216 )
{
V_226 . V_135 = F_149 ( ( const V_217 * ) V_37 -> V_214 . T_17 ) ;
V_226 . V_136 = F_149 ( ( const V_217 * ) V_37 -> V_215 . T_17 ) ;
} else {
V_226 . V_135 = F_150 ( F_147 ( F_148 () , & V_37 -> V_214 ) ) ;
V_226 . V_136 = F_150 ( F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
}
V_226 . V_130 = F_115 ( & V_226 ) ;
#ifdef F_126
F_109 ( 11 , L_57 , V_226 . V_130 ) ;
F_109 ( 51 , L_58 , F_147 ( F_148 () , & V_37 -> V_214 ) , F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
F_109 ( 51 , L_59 , V_226 . V_57 , V_226 . V_66 ) ;
#endif
V_184 = F_132 ( & V_226 , V_37 ) ;
if( V_184 ) {
#ifdef F_126
F_109 ( 12 , L_60 ) ;
#endif
V_150 = V_184 -> V_141 ;
} else {
#ifdef F_126
F_109 ( 12 , L_61 ) ;
#endif
V_210 . V_132 = V_208 -> V_66 ;
if ( V_37 -> V_214 . type == V_216 && V_37 -> V_215 . type == V_216 )
{
V_210 . V_131 = F_149 ( ( const V_217 * ) V_37 -> V_215 . T_17 ) ;
} else {
V_210 . V_131 = F_150 ( F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
}
V_210 . V_130 = F_113 ( & V_210 ) ;
#ifdef F_126
F_109 ( 11 , L_62 , V_210 . V_130 ) ;
F_109 ( 51 , L_40 , F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
F_109 ( 51 , L_41 , V_210 . V_132 ) ;
#endif
V_140 = F_131 ( & V_210 , V_37 , FALSE ) ;
if( ! V_140 ) {
#ifdef F_126
F_109 ( 12 , L_63 ) ;
#endif
V_210 . V_132 = V_208 -> V_57 ;
if ( V_37 -> V_214 . type == V_216 && V_37 -> V_215 . type == V_216 )
{
V_210 . V_131 = F_149 ( ( const V_217 * ) V_37 -> V_214 . T_17 ) ;
} else {
V_210 . V_131 = F_150 ( F_147 ( F_148 () , & V_37 -> V_214 ) ) ;
}
V_210 . V_130 = F_113 ( & V_210 ) ;
#ifdef F_126
F_109 ( 11 , L_62 , V_210 . V_130 ) ;
F_109 ( 51 , L_40 , F_147 ( F_148 () , & V_37 -> V_214 ) ) ;
F_109 ( 51 , L_41 , V_210 . V_132 ) ;
#endif
V_140 = F_131 ( & V_210 , V_37 , FALSE ) ;
}
if( V_140 &&
! V_140 -> V_141 -> V_168 ) {
#ifdef F_126
F_109 ( 12 , L_64 ) ;
#endif
V_150 = V_140 -> V_141 ;
V_150 -> V_145 = TRUE ;
#ifdef F_126
F_109 ( 10 , L_65 , V_226 . V_130 ) ;
F_109 ( 11 , L_66 , V_37 -> V_143 ) ;
#endif
F_141 ( & V_226 ,
V_140 -> V_141 ) ;
V_227 . V_132 = V_208 -> V_57 ;
if ( V_37 -> V_214 . type == V_216 && V_37 -> V_215 . type == V_216 )
{
V_227 . V_131 = F_149 ( ( const V_217 * ) V_37 -> V_214 . T_17 ) ;
} else {
V_227 . V_131 = F_150 ( F_147 ( F_148 () , & V_37 -> V_214 ) ) ;
}
V_227 . V_130 = F_117 ( & V_227 ) ;
#ifdef F_126
F_109 ( 10 , L_67 , V_227 . V_130 ) ;
F_109 ( 51 , L_40 , F_147 ( F_148 () , & V_37 -> V_214 ) ) ;
F_109 ( 51 , L_68 , V_227 . V_132 ) ;
F_109 ( 11 , L_52 , V_37 -> V_143 ) ;
#endif
F_142 ( & V_227 ,
V_140 -> V_141 ) ;
} else {
#ifdef F_126
F_109 ( 12 , L_69 ) ;
#endif
}
}
if ( V_203 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_213 = F_61 ( T_11 , T_6 , 0 , - 1 , V_222 , & V_212 , L_49 ) ;
F_151 ( V_212 ) ;
V_211 = F_153 ( V_213 , V_224 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_151 ( V_211 ) ;
}
return V_150 ;
}
static struct V_149 *
F_155 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_150 = NULL ;
struct V_137 V_227 ;
struct V_172 * V_188 = NULL ;
struct V_129 V_210 ;
struct V_139 * V_140 = NULL ;
T_21 * V_211 ;
T_22 V_228 ;
T_21 * V_212 = NULL ;
T_10 * V_213 = NULL ;
#ifdef F_126
F_109 ( 51 , L_70 , F_147 ( F_148 () , & V_37 -> V_214 ) , F_147 ( F_148 () , & V_37 -> V_215 ) , V_208 -> V_66 ) ;
F_109 ( 10 , L_71 , V_37 -> V_143 ) ;
#endif
V_227 . V_132 = V_208 -> V_66 ;
if ( V_37 -> V_214 . type == V_216 && V_37 -> V_215 . type == V_216 )
{
V_227 . V_131 = F_149 ( ( const V_217 * ) V_37 -> V_215 . T_17 ) ;
} else {
V_227 . V_131 = F_150 ( F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
}
V_227 . V_130 = F_117 ( & V_227 ) ;
#ifdef F_126
F_109 ( 11 , L_72 , V_227 . V_130 ) ;
F_109 ( 11 , L_40 , F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
F_109 ( 51 , L_68 , V_227 . V_132 ) ;
#endif
V_188 = F_133 ( & V_227 , V_37 , TRUE ) ;
if( ! V_188 ) {
#ifdef F_126
F_109 ( 12 , L_73 ) ;
#endif
V_210 . V_132 = V_208 -> V_66 ;
if ( V_37 -> V_214 . type == V_216 && V_37 -> V_215 . type == V_216 )
{
V_210 . V_131 = F_149 ( ( const V_217 * ) V_37 -> V_215 . T_17 ) ;
} else {
V_210 . V_131 = F_150 ( F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
}
V_210 . V_130 = F_113 ( & V_210 ) ;
#ifdef F_126
F_109 ( 11 , L_62 , V_210 . V_130 ) ;
F_109 ( 51 , L_40 , F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
F_109 ( 51 , L_68 , V_210 . V_132 ) ;
#endif
V_140 = F_131 ( & V_210 , V_37 , FALSE ) ;
if( ! V_140 ) {
#ifdef F_126
F_109 ( 12 , L_69 ) ;
#endif
}
}
if ( V_188 ) {
V_150 = V_188 -> V_141 ;
} else if ( V_140 ) {
V_150 = V_140 -> V_141 ;
}
if ( V_150 ) {
#ifdef F_126
F_109 ( 12 , L_74 , V_150 -> V_142 ) ;
#endif
if ( V_203 && T_11 ) {
V_213 = F_61 ( T_11 , T_6 , 0 , - 1 , V_222 , & V_212 , L_49 ) ;
F_151 ( V_212 ) ;
V_211 = F_153 ( V_213 , V_224 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_151 ( V_211 ) ;
}
#ifdef F_126
F_109 ( 20 , L_75 , V_150 -> V_142 ) ;
#endif
if ( V_203 && V_213 ) {
V_211 = F_152 ( V_213 , V_229 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_76 ,
V_150 -> V_142 ) ;
F_151 ( V_211 ) ;
F_156 ( & V_228 , & V_37 -> V_147 , & V_150 -> V_146 ) ;
V_211 = F_157 ( V_213 , V_230 , T_6 , 0 , 0 , & V_228 ) ;
F_151 ( V_211 ) ;
}
F_158 ( V_150 , V_37 ) ;
} else {
#ifdef F_126
F_109 ( 12 , L_77 ) ;
#endif
}
return V_150 ;
}
static struct V_149 *
F_159 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_150 = NULL ;
struct V_123 V_209 ;
struct V_157 * V_158 , * V_160 ;
struct V_138 V_231 ;
T_21 * V_211 ;
T_22 V_228 ;
T_3 V_232 = FALSE ;
T_10 * V_213 = NULL ;
T_21 * V_212 = NULL ;
V_231 . V_132 = V_208 -> V_57 ;
if ( V_37 -> V_214 . type == V_216 && V_37 -> V_215 . type == V_216 )
{
V_231 . V_135 = F_149 ( ( const V_217 * ) V_37 -> V_214 . T_17 ) ;
V_231 . V_136 = F_149 ( ( const V_217 * ) V_37 -> V_215 . T_17 ) ;
} else {
V_231 . V_135 = F_150 ( F_147 ( F_148 () , & V_37 -> V_214 ) ) ;
V_231 . V_136 = F_150 ( F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
}
V_231 . V_130 = F_119 ( & V_231 ) ;
#ifdef F_126
F_109 ( 10 , L_78 , V_37 -> V_143 ) ;
F_109 ( 11 , L_39 , V_231 . V_130 ) ;
F_109 ( 51 , L_79 , F_147 ( F_148 () , & V_37 -> V_214 ) , F_147 ( F_148 () , & V_37 -> V_215 ) ) ;
F_109 ( 51 , L_68 , V_231 . V_132 ) ;
#endif
V_158 = (struct V_157 * )
F_12 ( V_199 , & V_231 ) ;
if ( V_158 ) {
do {
if ( V_37 -> V_143 == V_158 -> V_141 -> V_142 ) {
#ifdef F_126
F_109 ( 22 , L_80 ) ;
#endif
V_232 = FALSE ;
V_150 = V_158 -> V_141 ;
break;
}
if ( V_37 -> V_143 == V_158 -> V_141 -> V_144 ) {
#ifdef F_126
F_109 ( 22 , L_81 ) ;
#endif
V_232 = TRUE ;
V_150 = V_158 -> V_141 ;
break;
}
if ( V_37 -> V_143 > V_158 -> V_141 -> V_142 &&
V_158 -> V_141 -> V_144 == 0 ) {
#ifdef F_126
F_109 ( 12 , L_45 , V_231 . V_130 ) ;
#endif
V_158 -> V_141 -> V_144 = V_37 -> V_143 ;
V_158 -> V_141 -> V_145 = TRUE ;
V_158 -> V_141 -> V_221 = TRUE ;
V_150 = V_158 -> V_141 ;
V_232 = TRUE ;
if ( V_203 && T_11 ) {
V_213 = F_61 ( T_11 , T_6 , 0 , - 1 , V_222 , & V_212 , L_49 ) ;
F_151 ( V_212 ) ;
V_211 = F_153 ( V_213 , V_224 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_151 ( V_211 ) ;
#ifdef F_126
F_109 ( 20 , L_75 , V_150 -> V_142 ) ;
#endif
V_211 = F_152 ( V_213 , V_229 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_76 ,
V_150 -> V_142 ) ;
F_151 ( V_211 ) ;
F_156 ( & V_228 , & V_37 -> V_147 , & V_150 -> V_146 ) ;
V_211 = F_157 ( V_213 , V_230 , T_6 , 0 , 0 , & V_228 ) ;
F_151 ( V_211 ) ;
}
break;
}
if ( ! V_158 -> V_163 ) {
if ( ( V_158 -> V_141 -> V_144 != 0
&& V_37 -> V_143 > V_158 -> V_141 -> V_142
&& ( T_18 ) V_37 -> V_147 . V_218 > ( T_18 ) ( V_158 -> V_141 -> V_146 . V_218 + V_219 )
) ||
( V_158 -> V_141 -> V_144 == 0
&& V_37 -> V_143 > V_158 -> V_141 -> V_142
&& ( T_18 ) V_37 -> V_147 . V_218 > ( T_18 ) ( V_158 -> V_141 -> V_146 . V_218 + V_220 )
)
)
{
#ifdef F_126
F_109 ( 12 , L_43 , V_231 . V_130 ) ;
F_109 ( 12 , L_44 , V_37 -> V_143 , V_158 -> V_141 -> V_144 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_134 ( & V_209 , V_37 ) ;
V_160 = F_128 ( V_158 ,
V_150 ,
V_37 ) ;
#ifdef F_126
F_109 ( 12 , L_45 , V_231 . V_130 ) ;
#endif
F_127 ( V_160 , V_37 ) ;
V_158 = V_160 ;
} else {
if ( V_158 -> V_141 -> V_221 ) {
#ifdef F_126
F_109 ( 12 , L_46 , V_231 . V_130 ) ;
F_109 ( 12 , L_44 , V_37 -> V_143 , V_158 -> V_141 -> V_144 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_134 ( & V_209 , V_37 ) ;
V_160 = F_128 ( V_158 ,
V_150 ,
V_37 ) ;
#ifdef F_126
F_109 ( 12 , L_47 , V_231 . V_130 ) ;
#endif
F_127 ( V_160 , V_37 ) ;
V_158 = V_160 ;
} else {
V_150 = V_158 -> V_141 ;
#ifdef F_126
F_109 ( 12 , L_74 , V_150 -> V_142 ) ;
#endif
if ( V_203 && T_11 ) {
V_213 = F_61 ( T_11 , T_6 , 0 , - 1 , V_222 , & V_212 , L_49 ) ;
F_151 ( V_212 ) ;
V_211 = F_153 ( V_213 , V_224 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_151 ( V_211 ) ;
#ifdef F_126
F_109 ( 20 , L_75 , V_150 -> V_142 ) ;
#endif
V_211 = F_152 ( V_213 , V_229 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_76 ,
V_150 -> V_142 ) ;
F_151 ( V_211 ) ;
F_156 ( & V_228 , & V_37 -> V_147 , & V_150 -> V_146 ) ;
V_211 = F_157 ( V_213 , V_230 , T_6 , 0 , 0 , & V_228 ) ;
F_151 ( V_211 ) ;
}
V_150 = V_158 -> V_141 ;
}
}
break;
}
V_158 = V_158 -> V_163 ;
} while ( V_158 != NULL );
} else {
#ifdef F_126
F_109 ( 10 , L_51 , V_231 . V_130 ) ;
#endif
V_209 . V_126 = V_202 ++ ;
V_150 = F_134 ( & V_209 , V_37 ) ;
V_158 = F_140 ( & V_231 , V_150 ) ;
#ifdef F_126
F_109 ( 11 , L_45 , V_231 . V_130 ) ;
F_109 ( 11 , L_52 , V_37 -> V_143 ) ;
#endif
F_127 ( V_158 , V_37 ) ;
}
if ( V_203 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_213 = F_61 ( T_11 , T_6 , 0 , - 1 , V_222 , & V_212 , L_49 ) ;
F_151 ( V_212 ) ;
V_211 = F_153 ( V_213 , V_224 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_151 ( V_211 ) ;
}
if( V_203 && V_213 &&
V_158 -> V_141 -> V_144 != 0 ) {
if ( ! V_232 ) {
#ifdef F_126
F_109 ( 20 , L_53 , V_158 -> V_141 -> V_144 ) ;
#endif
V_211 = F_152 ( V_213 , V_225 , T_6 , 0 , 0 ,
V_158 -> V_141 -> V_144 ,
L_54 ,
V_158 -> V_141 -> V_144 ) ;
F_151 ( V_211 ) ;
} else {
#ifdef F_126
F_109 ( 20 , L_75 , V_150 -> V_142 ) ;
#endif
if ( V_203 ) {
V_211 = F_152 ( V_213 , V_229 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_76 ,
V_150 -> V_142 ) ;
F_151 ( V_211 ) ;
F_156 ( & V_228 , & V_37 -> V_147 , & V_150 -> V_146 ) ;
V_211 = F_157 ( V_213 , V_230 , T_6 , 0 , 0 , & V_228 ) ;
F_151 ( V_211 ) ;
}
}
}
return V_150 ;
}
struct V_149 *
F_160 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_207 * V_208 )
{
struct V_149 * V_233 = NULL ;
if( V_37 == NULL || V_37 -> V_143 == 0 ) {
return NULL ;
}
switch ( V_208 -> V_60 ) {
case V_61 :
#ifdef F_126
F_109 ( 1 , L_82 ) ;
#endif
V_233 = F_146 ( T_6 , V_37 , T_11 , V_208 ) ;
break;
case V_70 :
#ifdef F_126
F_109 ( 1 , L_83 ) ;
#endif
V_233 = F_154 ( T_6 , V_37 , T_11 , V_208 ) ;
break;
case V_75 :
#ifdef F_126
F_109 ( 1 , L_84 ) ;
#endif
V_233 = F_155 ( T_6 , V_37 , T_11 , V_208 ) ;
break;
case V_67 :
#ifdef F_126
F_109 ( 1 , L_85 ) ;
#endif
V_233 = F_155 ( T_6 , V_37 , T_11 , V_208 ) ;
break;
case V_234 :
case V_235 :
#ifdef F_126
F_109 ( 1 , L_86 ) ;
#endif
V_233 = F_159 ( T_6 , V_37 , T_11 , V_208 ) ;
break;
default:
#ifdef F_126
F_109 ( 1 , L_87 , V_208 -> V_60 ) ;
#endif
break;
}
#ifdef F_126
if ( V_233 )
F_109 ( 1 , L_88 , V_233 -> V_126 ) ;
#endif
return V_233 ;
}
struct V_207 *
F_161 ( void )
{
struct V_207 * V_208 ;
V_236 ++ ;
if( V_236 == V_237 ) {
V_236 = 0 ;
}
V_208 = & V_238 [ V_236 ] ;
memset ( V_208 , 0 , sizeof( struct V_207 ) ) ;
return V_208 ;
}
void
F_158 ( struct V_149 * V_150 ,
T_16 * V_37 )
{
#ifdef F_126
F_109 ( 60 , L_89 ) ;
#endif
if ( V_150 ) {
V_150 -> V_145 = TRUE ;
V_150 -> V_144 = V_37 -> V_143 ;
V_150 -> V_239 = V_37 -> V_147 ;
V_150 -> V_221 = TRUE ;
if ( V_150 -> V_176
&& ! V_204 ) {
if ( V_150 -> V_176 -> V_178 ) {
if ( V_150 -> V_176 -> V_179 ) {
#ifdef F_126
F_109 ( 20 , L_90 ) ;
#endif
V_150 -> V_176 -> V_179 -> V_178
= V_150 -> V_176 -> V_178 ;
V_150 -> V_176 -> V_178 -> V_179
= V_150 -> V_176 -> V_179 ;
F_7 ( V_189 , V_150 -> V_176 -> V_177 ) ;
#ifdef F_122
F_162 ( V_150 -> V_176 ) ;
#endif
} else {
#ifdef F_126
F_109 ( 20 , L_91 ) ;
#endif
}
} else if ( ! V_204 ) {
#ifdef F_126
F_109 ( 20 , L_92 ) ;
#endif
F_7 ( V_189 , V_150 -> V_176 -> V_177 ) ;
#ifdef F_122
F_162 ( V_150 -> V_176 -> V_177 ) ;
F_162 ( V_150 -> V_176 ) ;
#endif
}
}
if ( V_150 -> V_168
&& ! V_204 ) {
if ( V_150 -> V_168 -> V_170 ) {
if ( V_150 -> V_168 -> V_171 ) {
#ifdef F_126
F_109 ( 20 , L_93 ) ;
#endif
V_150 -> V_168 -> V_171 -> V_170
= V_150 -> V_168 -> V_170 ;
V_150 -> V_168 -> V_170 -> V_171
= V_150 -> V_168 -> V_171 ;
F_7 ( V_185 , V_150 -> V_168 -> V_169 ) ;
#ifdef F_122
F_162 ( V_150 -> V_168 ) ;
#endif
} else {
#ifdef F_126
F_109 ( 20 , L_94 ) ;
#endif
}
} else if ( ! V_204 ) {
#ifdef F_126
F_109 ( 20 , L_95 ) ;
#endif
F_7 ( V_185 , V_150 -> V_168 -> V_169 ) ;
#ifdef F_122
F_162 ( V_150 -> V_168 -> V_169 ) ;
F_162 ( V_150 -> V_168 ) ;
#endif
}
}
if ( V_150 -> V_152
&& ! V_204 ) {
if ( V_150 -> V_152 -> V_154 ) {
if ( V_150 -> V_152 -> V_155 ) {
#ifdef F_126
F_109 ( 20 , L_96 ) ;
#endif
V_150 -> V_152 -> V_155 -> V_154
= V_150 -> V_152 -> V_154 ;
V_150 -> V_152 -> V_154 -> V_155
= V_150 -> V_152 -> V_155 ;
F_7 ( V_182 , V_150 -> V_152 -> V_153 ) ;
#ifdef F_122
F_162 ( V_150 -> V_152 ) ;
#endif
} else {
#ifdef F_126
F_109 ( 20 , L_97 ) ;
#endif
}
} else if ( ! V_204 ) {
#ifdef F_126
F_109 ( 20 , L_98 ) ;
#endif
F_7 ( V_182 , V_150 -> V_152 -> V_153 ) ;
#ifdef F_122
F_162 ( V_150 -> V_152 -> V_153 ) ;
F_162 ( V_150 -> V_152 ) ;
#endif
}
}
if ( V_150 -> V_161
&& ! V_204 ) {
if ( V_150 -> V_161 -> V_163 ) {
if ( V_150 -> V_161 -> V_164 ) {
#ifdef F_126
F_109 ( 20 , L_99 ) ;
#endif
V_150 -> V_161 -> V_164 -> V_163
= V_150 -> V_161 -> V_163 ;
V_150 -> V_161 -> V_163 -> V_164
= V_150 -> V_161 -> V_164 ;
F_7 ( V_199 , V_150 -> V_161 -> V_162 ) ;
#ifdef F_122
F_162 ( V_150 -> V_161 ) ;
#endif
} else {
#ifdef F_126
F_109 ( 20 , L_100 ) ;
#endif
}
} else if ( ! V_204 ) {
#ifdef F_126
F_109 ( 20 , L_101 ) ;
#endif
F_7 ( V_199 , V_150 -> V_161 -> V_162 ) ;
#ifdef F_122
F_162 ( V_150 -> V_161 -> V_162 ) ;
F_162 ( V_150 -> V_161 ) ;
#endif
}
}
if ( ! V_204 ) {
#ifdef F_126
F_109 ( 20 , L_102 ) ;
#endif
F_7 ( V_193 , V_150 -> V_128 ) ;
#ifdef F_122
F_162 ( V_150 -> V_128 ) ;
F_162 ( V_150 ) ;
#endif
}
} else {
#ifdef F_126
F_109 ( 20 , L_103 ) ;
#endif
}
}
static int
F_163 ( T_5 * T_6 , T_16 * V_37 , T_10 * V_240 , void * T_17 V_6 )
{
T_21 * V_241 = NULL ;
T_10 * T_11 = NULL ;
struct V_149 * V_242 ;
T_2 V_243 ;
T_8 V_112 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
F_164 ( T_6 , 0 , & V_30 , & V_31 , & V_32 ) ;
if( V_30 == V_244 ) {
switch ( V_32 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
return F_165 ( V_245 , T_6 , V_37 , V_240 ) ;
default:
return F_166 ( T_6 ) ;
}
}
F_107 ( & V_112 , V_113 , TRUE , V_37 ) ;
V_43 = V_240 ;
V_246 = NULL ;
F_69 ( V_37 -> V_58 , V_247 , L_104 ) ;
if( V_240 ) {
V_241 = F_167 ( V_240 , V_248 , T_6 , 0 , - 1 , V_249 ) ;
T_11 = F_168 ( V_241 , V_250 ) ;
V_246 = T_11 ;
}
V_82 = NULL ;
V_251 = NULL ;
F_169 ( & V_83 ) ;
V_112 . V_252 = & V_83 ;
V_56 = F_161 () ;
V_253 = FALSE ;
V_254 = NULL ;
F_77 ( FALSE , T_6 , 0 , & V_112 , T_11 , - 1 ) ;
if ( V_205 && ! V_253 ) {
V_242 = F_160 ( T_6 , V_37 , V_246 , V_56 ) ;
V_83 . V_141 = V_242 ;
if ( V_242 && V_82 && ! V_242 -> V_255 ) {
F_170 ( V_242 -> V_84 , V_82 , sizeof( V_242 -> V_84 ) ) ;
V_242 -> V_255 = TRUE ;
if ( ( V_243 = F_171 ( V_256 , V_82 ) ) ) {
V_242 -> V_243 = V_243 ;
V_242 -> V_257 = TRUE ;
}
}
if ( V_205 && V_242 && V_242 -> V_258 ) {
( V_242 -> V_258 ) ( T_6 , V_37 , V_246 , V_242 ) ;
}
}
return F_166 ( T_6 ) ;
}
void
F_172 ( void )
{
V_259 = F_173 ( L_105 ) ;
V_245 = F_174 ( L_106 , V_248 ) ;
V_256 = F_175 ( L_107 ) ;
#line 1 "./asn1/tcap/packet-tcap-dis-tab.c"
F_176 ( L_108 , F_108 , V_248 , L_109 ) ;
F_176 ( L_110 , F_106 , V_248 , L_111 ) ;
#line 2068 "./asn1/tcap/packet-tcap-template.c"
}
void
F_177 ( void )
{
static T_23 V_260 [] = {
{ & V_261 ,
{ L_112 ,
L_113 ,
V_262 , V_263 , NULL , 0 ,
NULL , V_264 }
} ,
{ & V_265 ,
{ L_114 ,
L_115 ,
V_262 , V_266 , NULL , 0 ,
NULL , V_264 }
} ,
{ & V_267 ,
{ L_116 ,
L_117 ,
V_268 , V_269 , NULL , 0 ,
NULL , V_264 }
} ,
{ & V_52 ,
{ L_118 ,
L_119 ,
V_268 , V_269 , NULL , 0 ,
NULL , V_264 }
} ,
{ & V_270 ,
{ L_120 ,
L_121 ,
V_271 , V_263 , NULL , 0 ,
NULL , V_264 }
} ,
{ & V_224 ,
{ L_122 ,
L_123 ,
V_272 , V_266 , NULL , 0x0 ,
NULL , V_264 }
} ,
{ & V_225 ,
{ L_124 ,
L_125 ,
V_273 , V_269 , NULL , 0x0 ,
L_126 , V_264 }
} ,
{ & V_229 ,
{ L_127 ,
L_128 ,
V_273 , V_269 , NULL , 0x0 ,
L_129 , V_264 }
} ,
{ & V_230 ,
{ L_130 ,
L_131 ,
V_274 , V_269 , NULL , 0x0 ,
L_132 , V_264 }
} ,
{ & V_223 ,
{ L_133 ,
L_134 ,
V_273 , V_269 , NULL , 0x0 ,
L_135 , V_264 }
} ,
#line 1 "./asn1/tcap/packet-tcap-hfarr.c"
{ & V_114 ,
{ L_136 , L_137 ,
V_272 , V_266 , F_178 ( V_275 ) , 0 ,
NULL , V_264 } } ,
{ & V_115 ,
{ L_138 , L_139 ,
V_272 , V_266 , F_178 ( V_276 ) , 0 ,
NULL , V_264 } } ,
{ & V_277 ,
{ L_140 , L_141 ,
V_278 , V_269 , NULL , 0 ,
L_142 , V_264 } } ,
{ & V_279 ,
{ L_143 , L_144 ,
V_268 , V_269 , NULL , 0 ,
L_145 , V_264 } } ,
{ & V_280 ,
{ L_146 , L_147 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_282 ,
{ L_148 , L_149 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_283 ,
{ L_150 , L_151 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_284 ,
{ L_152 , L_153 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_285 ,
{ L_154 , L_155 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_286 ,
{ L_156 , L_157 ,
V_268 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_287 ,
{ L_158 , L_159 ,
V_272 , V_266 , NULL , 0 ,
L_160 , V_264 } } ,
{ & V_55 ,
{ L_161 , L_162 ,
V_268 , V_269 , NULL , 0 ,
L_163 , V_264 } } ,
{ & V_65 ,
{ L_164 , L_165 ,
V_268 , V_269 , NULL , 0 ,
L_166 , V_264 } } ,
{ & V_288 ,
{ L_167 , L_168 ,
V_272 , V_266 , F_178 ( V_289 ) , 0 ,
NULL , V_264 } } ,
{ & V_290 ,
{ L_169 , L_170 ,
V_272 , V_266 , F_178 ( V_291 ) , 0 ,
NULL , V_264 } } ,
{ & V_292 ,
{ L_171 , L_172 ,
V_268 , V_269 , NULL , 0 ,
L_173 , V_264 } } ,
{ & V_293 ,
{ L_174 , L_175 ,
V_272 , V_266 , F_178 ( V_294 ) , 0 ,
NULL , V_264 } } ,
{ & V_295 ,
{ L_176 , L_177 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_296 ,
{ L_178 , L_179 ,
V_281 , V_269 , NULL , 0 ,
L_180 , V_264 } } ,
{ & V_297 ,
{ L_181 , L_182 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_298 ,
{ L_183 , L_184 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_299 ,
{ L_185 , L_186 ,
V_281 , V_269 , NULL , 0 ,
L_180 , V_264 } } ,
{ & V_300 ,
{ L_187 , L_188 ,
V_301 , V_266 , NULL , 0 ,
L_189 , V_264 } } ,
{ & V_302 ,
{ L_190 , L_191 ,
V_301 , V_266 , NULL , 0 ,
L_189 , V_264 } } ,
{ & V_303 ,
{ L_192 , L_193 ,
V_272 , V_266 , F_178 ( V_304 ) , 0 ,
L_194 , V_264 } } ,
{ & V_305 ,
{ L_195 , L_196 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_306 ,
{ L_197 , L_198 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_307 ,
{ L_199 , L_200 ,
V_272 , V_266 , F_178 ( V_308 ) , 0 ,
NULL , V_264 } } ,
{ & V_309 ,
{ L_201 , L_202 ,
V_272 , V_266 , F_178 ( V_310 ) , 0 ,
NULL , V_264 } } ,
{ & V_311 ,
{ L_203 , L_204 ,
V_301 , V_266 , NULL , 0 ,
L_189 , V_264 } } ,
{ & V_312 ,
{ L_205 , L_206 ,
V_281 , V_269 , NULL , 0 ,
NULL , V_264 } } ,
{ & V_313 ,
{ L_207 , L_208 ,
V_272 , V_266 , F_178 ( V_314 ) , 0 ,
NULL , V_264 } } ,
{ & V_315 ,
{ L_209 , L_210 ,
V_301 , V_266 , F_178 ( V_316 ) , 0 ,
NULL , V_264 } } ,
{ & V_317 ,
{ L_211 , L_212 ,
V_301 , V_266 , F_178 ( V_318 ) , 0 ,
NULL , V_264 } } ,
{ & V_319 ,
{ L_213 , L_214 ,
V_301 , V_266 , F_178 ( V_320 ) , 0 ,
NULL , V_264 } } ,
{ & V_321 ,
{ L_215 , L_216 ,
V_301 , V_266 , F_178 ( V_322 ) , 0 ,
NULL , V_264 } } ,
{ & V_323 ,
{ L_217 , L_218 ,
V_301 , V_266 , NULL , 0 ,
L_219 , V_264 } } ,
{ & V_324 ,
{ L_220 , L_221 ,
V_278 , V_269 , NULL , 0 ,
L_142 , V_264 } } ,
{ & V_325 ,
{ L_222 , L_223 ,
V_301 , V_266 , NULL , 0 ,
L_224 , V_264 } } ,
{ & V_326 ,
{ L_225 , L_226 ,
V_301 , V_266 , NULL , 0 ,
L_219 , V_264 } } ,
{ & V_327 ,
{ L_227 , L_228 ,
V_281 , V_269 , NULL , 0 ,
L_229 , V_264 } } ,
{ & V_328 ,
{ L_230 , L_231 ,
V_268 , V_269 , NULL , 0 ,
L_232 , V_264 } } ,
{ & V_329 ,
{ L_233 , L_234 ,
V_278 , V_269 , NULL , 0 ,
L_235 , V_264 } } ,
{ & V_330 ,
{ L_236 , L_237 ,
V_272 , V_266 , NULL , 0 ,
L_238 , V_264 } } ,
{ & V_331 ,
{ L_239 , L_240 ,
V_281 , V_269 , NULL , 0 ,
L_241 , V_264 } } ,
{ & V_332 ,
{ L_242 , L_243 ,
V_281 , V_269 , NULL , 0 ,
L_244 , V_264 } } ,
{ & V_333 ,
{ L_245 , L_246 ,
V_281 , V_269 , NULL , 0 ,
L_247 , V_264 } } ,
{ & V_334 ,
{ L_248 , L_249 ,
V_281 , V_269 , NULL , 0 ,
L_250 , V_264 } } ,
{ & V_335 ,
{ L_230 , L_231 ,
V_268 , V_269 , NULL , 0 ,
L_251 , V_264 } } ,
{ & V_336 ,
{ L_233 , L_234 ,
V_278 , V_269 , NULL , 0 ,
L_252 , V_264 } } ,
{ & V_337 ,
{ L_236 , L_237 ,
V_272 , V_266 , NULL , 0 ,
L_253 , V_264 } } ,
{ & V_338 ,
{ L_239 , L_240 ,
V_281 , V_269 , NULL , 0 ,
L_241 , V_264 } } ,
{ & V_339 ,
{ L_230 , L_231 ,
V_268 , V_269 , NULL , 0 ,
L_254 , V_264 } } ,
{ & V_340 ,
{ L_233 , L_234 ,
V_278 , V_269 , NULL , 0 ,
L_255 , V_264 } } ,
{ & V_341 ,
{ L_256 , L_257 ,
V_301 , V_266 , F_178 ( V_342 ) , 0 ,
L_258 , V_264 } } ,
{ & V_343 ,
{ L_259 , L_260 ,
V_272 , V_266 , F_178 ( V_344 ) , 0 ,
L_261 , V_264 } } ,
{ & V_345 ,
{ L_236 , L_237 ,
V_272 , V_266 , NULL , 0 ,
L_262 , V_264 } } ,
{ & V_346 ,
{ L_239 , L_240 ,
V_281 , V_269 , NULL , 0 ,
L_241 , V_264 } } ,
{ & V_347 ,
{ L_263 , L_264 ,
V_301 , V_266 , F_178 ( V_348 ) , 0 ,
L_265 , V_264 } } ,
{ & V_349 ,
{ L_236 , L_237 ,
V_272 , V_266 , NULL , 0 ,
L_266 , V_264 } } ,
{ & V_350 ,
{ L_239 , L_240 ,
V_281 , V_269 , NULL , 0 ,
L_241 , V_264 } } ,
{ & V_351 ,
{ L_267 , L_268 ,
V_301 , V_266 , F_178 ( V_352 ) , 0 ,
NULL , V_264 } } ,
{ & V_353 ,
{ L_269 , L_270 ,
V_301 , V_266 , F_178 ( V_354 ) , 0 ,
NULL , V_264 } } ,
{ & V_355 ,
{ L_271 , L_272 ,
V_356 , 8 , NULL , 0x80 ,
NULL , V_264 } } ,
{ & V_357 ,
{ L_271 , L_272 ,
V_356 , 8 , NULL , 0x80 ,
NULL , V_264 } } ,
{ & V_358 ,
{ L_271 , L_272 ,
V_356 , 8 , NULL , 0x80 ,
NULL , V_264 } } ,
#line 2141 "./asn1/tcap/packet-tcap-template.c"
} ;
static T_14 * V_359 [] = {
& V_250 ,
& V_360 ,
& V_54 ,
& V_64 ,
& V_222 ,
#line 1 "./asn1/tcap/packet-tcap-ettarr.c"
& V_8 ,
& V_79 ,
& V_47 ,
& V_63 ,
& V_69 ,
& V_72 ,
& V_77 ,
& V_74 ,
& V_45 ,
& V_39 ,
& V_14 ,
& V_18 ,
& V_16 ,
& V_22 ,
& V_28 ,
& V_24 ,
& V_26 ,
& V_12 ,
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
#line 2151 "./asn1/tcap/packet-tcap-template.c"
} ;
T_24 * V_361 ;
V_248 = F_179 ( V_362 , V_363 , V_364 ) ;
F_180 ( V_248 , V_260 , F_181 ( V_260 ) ) ;
F_182 ( V_359 , F_181 ( V_359 ) ) ;
V_361 = F_183 ( V_248 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_184 ( V_361 , L_273 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_184 ( V_361 , L_274 ) ;
#endif
F_185 ( & V_365 , L_275 , V_366 ) ;
F_186 ( V_361 , L_276 , L_277 ,
L_278 ,
& V_365 , V_366 ) ;
F_187 ( V_361 , L_279 ,
L_280 ,
L_281 ,
& V_205 ) ;
F_187 ( V_361 , L_282 ,
L_283 ,
L_284 ,
& V_204 ) ;
F_188 ( V_361 , L_285 ,
L_286 ,
L_287 ,
10 , & V_219 ) ;
F_188 ( V_361 , L_288 ,
L_289 ,
L_290 ,
10 , & V_220 ) ;
V_3 = F_145 ( V_367 , V_368 ) ;
V_5 = F_145 ( V_367 , V_368 ) ;
F_189 ( L_291 , F_163 , V_248 ) ;
V_4 = F_190 ( F_163 , V_248 ) ;
F_191 ( & V_369 ) ;
F_192 ( & V_370 ) ;
}
static void F_193 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_194 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_369 ( void )
{
V_371 = F_195 ( V_365 ) ;
F_196 ( V_371 , F_194 ) ;
F_143 () ;
}
static void V_370 ( void )
{
F_196 ( V_371 , F_193 ) ;
F_162 ( V_371 ) ;
}
static int
F_29 ( T_8 * T_9 , T_10 * T_11 , T_5 * T_6 , int T_7 )
{
T_14 V_372 , V_51 , V_373 ;
T_5 * V_29 ;
T_10 * V_50 ;
T_13 V_30 ;
T_3 V_31 ;
T_25 V_32 ;
T_1 V_33 ;
T_1 V_374 ;
T_1 V_375 ;
T_3 V_36 ;
while ( F_62 ( T_6 , T_7 ) > 0 )
{
V_51 = T_7 ;
T_7 = F_164 ( T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_372 = T_7 ;
T_7 = F_197 ( T_6 , T_7 , & V_33 , & V_36 ) ;
V_373 = T_7 ;
V_374 = V_372 - V_51 ;
V_375 = V_373 - V_372 ;
if ( V_31 )
{
V_50 = F_61 ( T_11 , T_6 , V_51 ,
V_33 + ( V_373 - V_51 ) , V_360 , NULL ,
L_292 ) ;
F_152 ( V_50 , V_261 , T_6 ,
V_51 , V_374 , V_32 ,
L_293 ) ;
F_153 ( V_50 , V_261 , T_6 , V_51 ,
V_374 , V_30 ) ;
F_153 ( V_50 , V_265 , T_6 , V_372 ,
V_375 , V_33 ) ;
if ( V_33 - ( 2 * V_36 ) )
{
V_29 = F_48 ( T_6 , T_7 , V_33 - ( 2 * V_36 ) ) ;
F_29 ( T_9 , V_50 , V_29 , 0 ) ;
}
if ( V_36 )
F_167 ( V_50 , V_270 , T_6 , T_7 + V_33 - 2 , 2 , V_376 ) ;
T_7 += V_33 ;
}
else
{
V_50 = F_198 ( T_11 , T_6 , V_51 ,
V_33 + ( V_373 - V_51 ) , V_360 , NULL ,
L_294 , V_32 ) ;
F_153 ( V_50 , V_261 , T_6 , V_51 ,
V_374 , V_32 ) ;
F_153 ( V_50 , V_265 , T_6 ,
V_51 + V_374 , V_375 , V_33 ) ;
if ( V_33 )
{
V_29 = F_48 ( T_6 , T_7 , V_33 ) ;
F_58 ( TRUE , T_9 , T_11 , V_29 , 0 ,
V_267 , NULL ) ;
}
T_7 += V_33 ;
}
}
return T_7 ;
}
static void F_169 ( struct V_377 * V_378 )
{
memset ( V_378 , 0 , sizeof( struct V_377 ) ) ;
}
static int
F_52 ( T_3 T_4 V_6 , T_5 * T_6 , int T_7 , T_8 * T_9 V_6 , T_10 * T_11 , int T_12 V_6 )
{
T_2 V_243 = NULL ;
T_3 V_379 = FALSE ;
struct V_149 * V_242 = NULL ;
if ( V_205 ) {
if ( ! V_253 ) {
V_242 = F_160 ( T_6 , T_9 -> V_37 , V_246 , V_56 ) ;
V_253 = TRUE ;
V_254 = V_242 ;
V_83 . V_141 = V_242 ;
} else {
V_242 = V_254 ;
V_83 . V_141 = V_242 ;
}
}
if ( V_242 ) {
if ( V_82 ) {
if ( V_242 -> V_255 ) {
if ( strncmp ( V_242 -> V_84 , V_82 , sizeof( V_242 -> V_84 ) ) != 0 ) {
F_170 ( V_242 -> V_84 , V_82 , sizeof( V_242 -> V_84 ) ) ;
if ( ( V_243 = F_171 ( V_256 , V_82 ) ) ) {
V_242 -> V_243 = V_243 ;
V_242 -> V_257 = TRUE ;
}
}
} else {
F_170 ( V_242 -> V_84 , V_82 , sizeof( V_242 -> V_84 ) ) ;
V_242 -> V_255 = TRUE ;
if ( ( V_243
= F_171 ( V_256 , V_82 ) ) ) {
V_242 -> V_243 = V_243 ;
V_242 -> V_257 = TRUE ;
} else {
if ( ( V_243 = F_8 ( T_9 -> V_37 -> V_380 ) ) ) {
V_242 -> V_243 = V_243 ;
V_242 -> V_257 = TRUE ;
}
}
}
} else {
if ( V_242 -> V_255 ) {
V_83 . V_84 = ( void * ) V_242 -> V_84 ;
V_83 . V_85 = TRUE ;
}
}
}
if ( V_242
&& V_242 -> V_257 ) {
V_243 = V_242 -> V_243 ;
V_379 = TRUE ;
}
if ( ! V_379 && V_381 ) {
V_379 = TRUE ;
V_243 = V_381 ;
}
if ( ! V_379 ) {
if ( V_256 && V_82 ) {
if ( ( V_243
= F_171 ( V_256 , V_82 ) ) ) {
V_379 = TRUE ;
} else {
if ( ( V_243
= F_8 ( T_9 -> V_37 -> V_380 ) ) ) {
V_379 = TRUE ;
} else {
V_243 = V_259 ;
V_379 = TRUE ;
}
}
} else {
if ( ( V_243 = F_8 ( T_9 -> V_37 -> V_380 ) ) ) {
V_379 = TRUE ;
} else {
V_243 = V_259 ;
V_379 = TRUE ;
}
}
} else {
}
if ( V_379 ) {
F_199 ( V_243 , T_6 , T_9 -> V_37 , T_11 , T_9 -> V_252 ) ;
F_200 ( T_9 -> V_37 -> V_58 , V_59 ) ;
}
return T_7 ;
}
void
F_201 ( T_2 V_382 , T_5 * T_6 , T_16 * V_37 , T_10 * T_11 )
{
V_381 = V_382 ;
F_49 {
F_163 ( T_6 , V_37 , T_11 , NULL ) ;
} F_202 {
V_381 = NULL ;
V_383 ;
} V_42 ;
V_381 = NULL ;
}
