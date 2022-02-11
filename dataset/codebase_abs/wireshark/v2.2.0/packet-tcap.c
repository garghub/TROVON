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
V_151 = F_122 ( F_123 () , struct V_139 ) ;
V_151 -> V_141 = V_150 ;
V_150 -> V_152 = V_151 ;
V_151 -> V_153 = V_148 -> V_153 ;
V_151 -> V_141 -> V_142 = V_37 -> V_143 ;
V_151 -> V_154 = NULL ;
V_151 -> V_155 = V_148 ;
V_151 -> V_156 = FALSE ;
#ifdef F_124
F_109 ( 10 , L_12 , V_151 -> V_141 -> V_126 ) ;
#endif
V_148 -> V_154 = V_151 ;
if ( V_148 -> V_141 -> V_144 == 0 ) {
#ifdef F_124
F_109 ( 10 , L_13 ) ;
#endif
V_148 -> V_141 -> V_144 = V_37 -> V_143 - 1 ;
}
return V_151 ;
}
static void
F_125 ( struct V_157 * V_158 ,
T_16 * V_37 )
{
V_158 -> V_141 -> V_142 = V_37 -> V_143 ;
V_158 -> V_141 -> V_144 = 0 ;
V_158 -> V_141 -> V_145 = FALSE ;
V_158 -> V_141 -> V_146 = V_37 -> V_147 ;
}
static struct V_157 *
F_126 ( struct V_157 * V_159 ,
struct V_149 * V_150 ,
T_16 * V_37 )
{
struct V_157 * V_160 = NULL ;
V_160 = F_122 ( F_123 () , struct V_157 ) ;
V_160 -> V_141 = V_150 ;
V_150 -> V_161 = V_160 ;
V_160 -> V_162 = V_159 -> V_162 ;
V_160 -> V_141 -> V_142 = V_37 -> V_143 ;
V_160 -> V_163 = NULL ;
V_160 -> V_164 = V_159 ;
V_160 -> V_156 = FALSE ;
#ifdef F_124
F_109 ( 10 , L_14 , V_160 -> V_141 -> V_126 ) ;
#endif
V_159 -> V_163 = V_160 ;
if ( V_159 -> V_141 -> V_144 == 0 ) {
#ifdef F_124
F_109 ( 10 , L_13 ) ;
#endif
V_159 -> V_141 -> V_144 = V_37 -> V_143 - 1 ;
}
return V_160 ;
}
static struct V_165 *
F_127 ( struct V_165 * V_166 ,
struct V_149 * V_150 )
{
struct V_165 * V_167 = NULL ;
V_167 = F_122 ( F_123 () , struct V_165 ) ;
V_167 -> V_141 = V_150 ;
V_150 -> V_168 = V_167 ;
V_167 -> V_169 = V_166 -> V_169 ;
V_167 -> V_170 = NULL ;
V_167 -> V_171 = V_166 ;
V_167 -> V_156 = FALSE ;
#ifdef F_124
F_109 ( 10 , L_15 , V_167 -> V_141 -> V_126 ) ;
#endif
V_166 -> V_170 = V_167 ;
return V_167 ;
}
static struct V_172 *
F_128 ( struct V_172 * V_173 ,
struct V_149 * V_150 )
{
struct V_172 * V_174 = NULL ;
V_174 = F_122 ( F_123 () , struct V_172 ) ;
V_174 -> V_141 = V_150 ;
V_150 -> V_175 = V_174 ;
V_174 -> V_176 = V_173 -> V_176 ;
V_174 -> V_177 = NULL ;
V_174 -> V_178 = V_173 ;
V_174 -> V_156 = FALSE ;
#ifdef F_124
F_109 ( 10 , L_16 , V_174 -> V_141 -> V_126 ) ;
#endif
V_173 -> V_177 = V_174 ;
return V_174 ;
}
static struct V_139 *
F_129 ( struct V_129 * V_179 ,
T_16 * V_37 , T_3 V_180 )
{
struct V_139 * V_140 = NULL ;
V_140 = (struct V_139 * ) F_12 ( V_181 , V_179 ) ;
if( V_140 ) {
do {
if ( V_140 -> V_141 ) {
if ( ( V_180 &&
V_37 -> V_143 == V_140 -> V_141 -> V_142 )
||
( ! V_180 &&
V_37 -> V_143 >= V_140 -> V_141 -> V_142 &&
( V_140 -> V_141 -> V_144 ? V_37 -> V_143 <= V_140 -> V_141 -> V_144 : 1 )
)
) {
#ifdef F_124
F_109 ( 10 , L_17 , V_140 -> V_141 -> V_126 ) ;
#endif
return V_140 ;
}
#ifdef F_124
F_109 ( 60 , L_18 , V_140 -> V_141 -> V_126 ) ;
#endif
}
if( V_140 -> V_154 == NULL ) {
#ifdef F_124
F_109 ( 23 , L_19 ) ;
#endif
break;
}
V_140 = V_140 -> V_154 ;
} while ( V_140 != NULL ) ;
} else {
#ifdef F_124
F_109 ( 23 , L_20 ) ;
#endif
}
return NULL ;
}
static struct V_165 *
F_130 ( struct V_134 * V_182 ,
T_16 * V_37 )
{
struct V_165 * V_183 = NULL ;
V_183 = (struct V_165 * ) F_12 ( V_184 , V_182 ) ;
if( V_183 ) {
do {
if ( V_183 -> V_141 ) {
if ( V_37 -> V_143 >= V_183 -> V_141 -> V_142 &&
( V_183 -> V_141 -> V_144 ? V_37 -> V_143 <= V_183 -> V_141 -> V_144 : 1 ) ) {
#ifdef F_124
F_109 ( 10 , L_21 , V_183 -> V_141 -> V_126 ) ;
#endif
return V_183 ;
}
#ifdef F_124
F_109 ( 60 , L_22 , V_183 -> V_141 -> V_126 ) ;
#endif
}
if( V_183 -> V_170 == NULL ) {
#ifdef F_124
F_109 ( 23 , L_23 ) ;
#endif
break;
}
V_183 = V_183 -> V_170 ;
} while ( V_183 != NULL ) ;
} else {
#ifdef F_124
F_109 ( 23 , L_24 ) ;
#endif
}
return NULL ;
}
static struct V_172 *
F_131 ( struct V_137 * V_185 ,
T_16 * V_37 , T_3 V_186 )
{
struct V_172 * V_187 = NULL ;
V_187 = (struct V_172 * ) F_12 ( V_188 , V_185 ) ;
if( V_187 ) {
do {
if ( V_187 -> V_141 ) {
if ( ( V_186 &&
( V_187 -> V_141 -> V_144 ? V_37 -> V_143 == V_187 -> V_141 -> V_144 : 1 )
)
||
( ! V_186 &&
V_37 -> V_143 >= V_187 -> V_141 -> V_142 &&
( V_187 -> V_141 -> V_144 ? V_37 -> V_143 <= V_187 -> V_141 -> V_144 : 1 )
)
) {
#ifdef F_124
F_109 ( 10 , L_25 , V_187 -> V_141 -> V_126 ) ;
#endif
return V_187 ;
}
#ifdef F_124
F_109 ( 60 , L_26 , V_187 -> V_141 -> V_126 ) ;
#endif
}
if( V_187 -> V_177 == NULL ) {
#ifdef F_124
F_109 ( 23 , L_27 ) ;
#endif
break;
}
V_187 = V_187 -> V_177 ;
} while ( V_187 != NULL ) ;
} else {
#ifdef F_124
F_109 ( 23 , L_28 ) ;
#endif
}
return NULL ;
}
static struct V_149 *
F_132 ( struct V_123 * V_189 ,
T_16 * V_37 )
{
struct V_123 * V_190 ;
struct V_149 * V_191 = NULL ;
V_190 = F_133 ( F_123 () , struct V_123 ) ;
V_190 -> V_126 = V_189 -> V_126 ;
V_191 = F_122 ( F_123 () , struct V_149 ) ;
V_191 -> V_128 = V_190 ;
V_191 -> V_126 = V_189 -> V_126 ;
V_191 -> V_142 = V_37 -> V_143 ;
#ifdef F_124
F_109 ( 10 , L_29 , V_191 -> V_126 ) ;
#endif
F_2 ( V_192 , V_190 , V_191 ) ;
return V_191 ;
}
static struct V_139 *
F_134 ( struct V_129 * V_179 ,
struct V_149 * V_150 )
{
struct V_129 * V_193 ;
struct V_139 * V_151 = NULL ;
V_193 = F_133 ( F_123 () , struct V_129 ) ;
V_193 -> V_130 = V_179 -> V_130 ;
V_193 -> V_132 = V_179 -> V_132 ;
V_193 -> V_131 = V_179 -> V_131 ;
V_151 = F_122 ( F_123 () , struct V_139 ) ;
V_151 -> V_153 = V_193 ;
V_151 -> V_141 = V_150 ;
V_150 -> V_152 = V_151 ;
V_151 -> V_156 = TRUE ;
V_151 -> V_154 = NULL ;
V_151 -> V_155 = NULL ;
#ifdef F_124
F_109 ( 10 , L_17 , V_151 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_181 , V_193 , V_151 ) ;
return V_151 ;
}
static struct V_165 *
F_135 ( struct V_134 * V_182 ,
struct V_149 * V_150 )
{
struct V_134 * V_194 ;
struct V_165 * V_167 = NULL ;
V_194 = F_133 ( F_123 () , struct V_134 ) ;
V_194 -> V_130 = V_182 -> V_130 ;
V_194 -> V_57 = V_182 -> V_57 ;
V_194 -> V_66 = V_182 -> V_66 ;
V_194 -> V_135 = V_182 -> V_135 ;
V_194 -> V_136 = V_182 -> V_136 ;
V_167 = F_122 ( F_123 () , struct V_165 ) ;
V_167 -> V_169 = V_194 ;
V_167 -> V_141 = V_150 ;
V_150 -> V_168 = V_167 ;
V_167 -> V_156 = TRUE ;
V_167 -> V_170 = NULL ;
V_167 -> V_171 = NULL ;
#ifdef F_124
F_109 ( 10 , L_21 , V_167 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_184 , V_194 , V_167 ) ;
return V_167 ;
}
static struct V_172 *
F_136 ( struct V_137 * V_185 ,
struct V_149 * V_150 )
{
struct V_137 * V_195 ;
struct V_172 * V_174 = NULL ;
V_195 = F_133 ( F_123 () , struct V_137 ) ;
V_195 -> V_130 = V_185 -> V_130 ;
V_195 -> V_132 = V_185 -> V_132 ;
V_195 -> V_131 = V_185 -> V_131 ;
V_174 = F_122 ( F_123 () , struct V_172 ) ;
V_174 -> V_176 = V_195 ;
V_174 -> V_141 = V_150 ;
V_150 -> V_175 = V_174 ;
V_174 -> V_156 = TRUE ;
V_174 -> V_177 = NULL ;
V_174 -> V_178 = NULL ;
#ifdef F_124
F_109 ( 10 , L_25 , V_174 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_188 , V_195 , V_174 ) ;
return V_174 ;
}
static struct V_157 *
F_137 ( struct V_138 * V_196 ,
struct V_149 * V_150 )
{
struct V_138 * V_197 ;
struct V_157 * V_160 = NULL ;
V_197 = F_133 ( F_123 () , struct V_138 ) ;
V_197 -> V_130 = V_196 -> V_130 ;
V_197 -> V_132 = V_196 -> V_132 ;
V_197 -> V_135 = V_196 -> V_135 ;
V_197 -> V_136 = V_196 -> V_136 ;
V_160 = F_122 ( F_123 () , struct V_157 ) ;
V_160 -> V_162 = V_197 ;
V_160 -> V_141 = V_150 ;
V_150 -> V_161 = V_160 ;
V_160 -> V_156 = TRUE ;
V_160 -> V_163 = NULL ;
V_160 -> V_164 = NULL ;
#ifdef F_124
F_109 ( 10 , L_30 , V_160 -> V_141 -> V_126 ) ;
#endif
F_2 ( V_198 , V_197 , V_160 ) ;
return V_160 ;
}
static struct V_165 *
F_138 ( struct V_134 * V_182 ,
struct V_149 * V_150 )
{
struct V_165 * V_199 = NULL ;
struct V_165 * V_183 = NULL ;
V_199 = (struct V_165 * )
F_12 ( V_184 , V_182 ) ;
if ( V_199 ) {
do {
if ( ! V_199 -> V_170 ) {
V_183 = F_127 ( V_199 ,
V_150 ) ;
break;
}
V_199 = V_199 -> V_170 ;
} while ( V_199 != NULL );
} else {
V_183 = F_135 ( V_182 ,
V_150 ) ;
}
return V_183 ;
}
static struct V_172 *
F_139 ( struct V_137 * V_185 ,
struct V_149 * V_150 )
{
struct V_172 * V_200 = NULL ;
struct V_172 * V_187 = NULL ;
V_200 = (struct V_172 * )
F_12 ( V_188 , V_185 ) ;
if ( V_200 ) {
do {
if ( ! V_200 -> V_177 ) {
V_187 = F_128 ( V_200 ,
V_150 ) ;
break;
}
V_200 = V_200 -> V_177 ;
} while ( V_200 != NULL );
} else {
V_187 = F_136 ( V_185 ,
V_150 ) ;
}
return V_187 ;
}
void
F_140 ( void )
{
if ( V_192 != NULL ) {
#ifdef F_124
F_109 ( 16 , L_31 ) ;
#endif
F_141 ( V_192 ) ;
}
if ( V_181 != NULL ) {
#ifdef F_124
F_109 ( 16 , L_32 ) ;
#endif
F_141 ( V_181 ) ;
}
if ( V_184 != NULL ) {
#ifdef F_124
F_109 ( 16 , L_33 ) ;
#endif
F_141 ( V_184 ) ;
}
if ( V_188 != NULL ) {
#ifdef F_124
F_109 ( 16 , L_34 ) ;
#endif
F_141 ( V_188 ) ;
}
if ( V_198 != NULL ) {
#ifdef F_124
F_109 ( 16 , L_35 ) ;
#endif
F_141 ( V_198 ) ;
}
#ifdef F_124
F_109 ( 16 , L_36 ) ;
#endif
V_192 = F_142 ( F_111 , F_110 ) ;
V_181 = F_142 ( F_113 , F_112 ) ;
V_184 = F_142 ( F_115 , F_114 ) ;
V_188 = F_142 ( F_117 , F_116 ) ;
V_198 = F_142 ( F_119 , F_118 ) ;
V_201 = 1 ;
V_202 = V_203 || V_204 & V_205 ;
}
static struct V_149 *
F_143 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_206 * V_207 )
{
struct V_149 * V_150 = NULL ;
struct V_123 V_208 ;
struct V_139 * V_140 , * V_151 = NULL ;
struct V_129 V_209 ;
T_21 * V_210 ;
T_21 * V_211 = NULL ;
T_10 * V_212 = NULL ;
#ifdef F_124
F_109 ( 51 , L_37 , F_144 ( F_145 () , & V_37 -> V_213 ) , V_207 -> V_57 , F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
#endif
V_209 . V_132 = V_207 -> V_57 ;
if ( V_37 -> V_213 . type == V_215 && V_37 -> V_214 . type == V_215 )
{
V_209 . V_131 = F_146 ( ( const V_216 * ) V_37 -> V_213 . T_17 ) ;
} else {
V_209 . V_131 = F_147 ( F_144 ( F_145 () , & V_37 -> V_213 ) ) ;
}
V_209 . V_130 = F_113 ( & V_209 ) ;
#ifdef F_124
F_109 ( 10 , L_38 , V_37 -> V_143 ) ;
F_109 ( 11 , L_39 , V_209 . V_130 ) ;
F_109 ( 51 , L_40 , F_144 ( F_145 () , & V_37 -> V_213 ) ) ;
F_109 ( 51 , L_41 , V_209 . V_132 ) ;
#endif
V_140 = (struct V_139 * )
F_12 ( V_181 , & V_209 ) ;
if ( V_140 ) {
do {
if ( V_37 -> V_143 == V_140 -> V_141 -> V_142 ) {
#ifdef F_124
F_109 ( 22 , L_42 ) ;
#endif
V_150 = V_140 -> V_141 ;
break;
}
if ( ! V_140 -> V_154 ) {
if ( ( V_140 -> V_141 -> V_144 != 0
&& V_37 -> V_143 > V_140 -> V_141 -> V_142
&& ( T_18 ) V_37 -> V_147 . V_217 > ( T_18 ) ( V_140 -> V_141 -> V_146 . V_217 + V_218 )
) ||
( V_140 -> V_141 -> V_144 == 0
&& V_37 -> V_143 > V_140 -> V_141 -> V_142
&& ( T_18 ) V_37 -> V_147 . V_217 > ( T_18 ) ( V_140 -> V_141 -> V_146 . V_217 + V_219 )
)
)
{
#ifdef F_124
F_109 ( 12 , L_43 , V_209 . V_130 ) ;
F_109 ( 12 , L_44 , V_37 -> V_143 , V_140 -> V_141 -> V_144 ) ;
#endif
V_208 . V_126 = V_201 ++ ;
V_150 = F_132 ( & V_208 , V_37 ) ;
V_151 = F_121 ( V_140 ,
V_150 ,
V_37 ) ;
#ifdef F_124
F_109 ( 12 , L_45 , V_209 . V_130 ) ;
#endif
F_120 ( V_151 , V_37 ) ;
} else {
if ( V_140 -> V_141 -> V_220 ) {
#ifdef F_124
F_109 ( 12 , L_46 , V_209 . V_130 ) ;
F_109 ( 12 , L_44 , V_37 -> V_143 , V_140 -> V_141 -> V_144 ) ;
#endif
V_208 . V_126 = V_201 ++ ;
V_150 = F_132 ( & V_208 , V_37 ) ;
V_151 = F_121 ( V_140 ,
V_150 ,
V_37 ) ;
#ifdef F_124
F_109 ( 12 , L_47 , V_209 . V_130 ) ;
#endif
F_120 ( V_151 , V_37 ) ;
} else {
#ifdef F_124
F_109 ( 21 , L_48 , V_140 -> V_141 -> V_142 ) ;
#endif
V_150 = V_140 -> V_141 ;
if ( V_202 && T_11 ) {
V_212 = F_61 ( T_11 , T_6 , 0 , - 1 , V_221 , & V_211 , L_49 ) ;
F_148 ( V_211 ) ;
V_210 = F_149 ( V_212 , V_222 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_50 ,
V_150 -> V_126 , V_150 -> V_142 ) ;
F_148 ( V_210 ) ;
}
return V_150 ;
}
}
break;
}
V_140 = V_140 -> V_154 ;
} while ( V_140 != NULL );
} else {
#ifdef F_124
F_109 ( 10 , L_51 , V_209 . V_130 ) ;
#endif
V_208 . V_126 = V_201 ++ ;
V_150 = F_132 ( & V_208 , V_37 ) ;
V_140 = F_134 ( & V_209 , V_150 ) ;
#ifdef F_124
F_109 ( 11 , L_45 , V_209 . V_130 ) ;
F_109 ( 11 , L_52 , V_37 -> V_143 ) ;
#endif
F_120 ( V_140 , V_37 ) ;
}
if ( V_202 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_212 = F_61 ( T_11 , T_6 , 0 , 0 , V_221 , & V_211 , L_49 ) ;
F_148 ( V_211 ) ;
V_210 = F_150 ( V_212 , V_223 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_148 ( V_210 ) ;
if( V_150 -> V_144 != 0 ) {
#ifdef F_124
F_109 ( 20 , L_53 , V_150 -> V_144 ) ;
#endif
V_210 = F_149 ( V_212 , V_224 , T_6 , 0 , 0 ,
V_150 -> V_144 ,
L_54 ,
V_150 -> V_144 ) ;
F_148 ( V_210 ) ;
}
}
return V_150 ;
}
static struct V_149 *
F_151 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_206 * V_207 )
{
struct V_149 * V_150 = NULL ;
struct V_165 * V_183 ;
struct V_134 V_225 ;
struct V_129 V_209 ;
struct V_139 * V_140 ;
struct V_137 V_226 ;
T_21 * V_210 ;
T_21 * V_211 = NULL ;
T_10 * V_212 = NULL ;
#ifdef F_124
F_109 ( 51 , L_55 , F_144 ( F_145 () , & V_37 -> V_213 ) , V_207 -> V_57 , F_144 ( F_145 () , & V_37 -> V_214 ) , V_207 -> V_66 ) ;
F_109 ( 10 , L_56 , V_37 -> V_143 ) ;
#endif
V_225 . V_57 = V_207 -> V_57 ;
V_225 . V_66 = V_207 -> V_66 ;
if ( V_37 -> V_213 . type == V_215 && V_37 -> V_214 . type == V_215 )
{
V_225 . V_135 = F_146 ( ( const V_216 * ) V_37 -> V_213 . T_17 ) ;
V_225 . V_136 = F_146 ( ( const V_216 * ) V_37 -> V_214 . T_17 ) ;
} else {
V_225 . V_135 = F_147 ( F_144 ( F_145 () , & V_37 -> V_213 ) ) ;
V_225 . V_136 = F_147 ( F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
}
V_225 . V_130 = F_115 ( & V_225 ) ;
#ifdef F_124
F_109 ( 11 , L_57 , V_225 . V_130 ) ;
F_109 ( 51 , L_58 , F_144 ( F_145 () , & V_37 -> V_213 ) , F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
F_109 ( 51 , L_59 , V_225 . V_57 , V_225 . V_66 ) ;
#endif
V_183 = F_130 ( & V_225 , V_37 ) ;
if( V_183 ) {
#ifdef F_124
F_109 ( 12 , L_60 ) ;
#endif
V_150 = V_183 -> V_141 ;
} else {
#ifdef F_124
F_109 ( 12 , L_61 ) ;
#endif
V_209 . V_132 = V_207 -> V_66 ;
if ( V_37 -> V_213 . type == V_215 && V_37 -> V_214 . type == V_215 )
{
V_209 . V_131 = F_146 ( ( const V_216 * ) V_37 -> V_214 . T_17 ) ;
} else {
V_209 . V_131 = F_147 ( F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
}
V_209 . V_130 = F_113 ( & V_209 ) ;
#ifdef F_124
F_109 ( 11 , L_62 , V_209 . V_130 ) ;
F_109 ( 51 , L_40 , F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
F_109 ( 51 , L_41 , V_209 . V_132 ) ;
#endif
V_140 = F_129 ( & V_209 , V_37 , FALSE ) ;
if( ! V_140 ) {
#ifdef F_124
F_109 ( 12 , L_63 ) ;
#endif
V_209 . V_132 = V_207 -> V_57 ;
if ( V_37 -> V_213 . type == V_215 && V_37 -> V_214 . type == V_215 )
{
V_209 . V_131 = F_146 ( ( const V_216 * ) V_37 -> V_213 . T_17 ) ;
} else {
V_209 . V_131 = F_147 ( F_144 ( F_145 () , & V_37 -> V_213 ) ) ;
}
V_209 . V_130 = F_113 ( & V_209 ) ;
#ifdef F_124
F_109 ( 11 , L_62 , V_209 . V_130 ) ;
F_109 ( 51 , L_40 , F_144 ( F_145 () , & V_37 -> V_213 ) ) ;
F_109 ( 51 , L_41 , V_209 . V_132 ) ;
#endif
V_140 = F_129 ( & V_209 , V_37 , FALSE ) ;
}
if( V_140 &&
! V_140 -> V_141 -> V_168 ) {
#ifdef F_124
F_109 ( 12 , L_64 ) ;
#endif
V_150 = V_140 -> V_141 ;
V_150 -> V_145 = TRUE ;
#ifdef F_124
F_109 ( 10 , L_65 , V_225 . V_130 ) ;
F_109 ( 11 , L_66 , V_37 -> V_143 ) ;
#endif
F_138 ( & V_225 ,
V_140 -> V_141 ) ;
V_226 . V_132 = V_207 -> V_57 ;
if ( V_37 -> V_213 . type == V_215 && V_37 -> V_214 . type == V_215 )
{
V_226 . V_131 = F_146 ( ( const V_216 * ) V_37 -> V_213 . T_17 ) ;
} else {
V_226 . V_131 = F_147 ( F_144 ( F_145 () , & V_37 -> V_213 ) ) ;
}
V_226 . V_130 = F_117 ( & V_226 ) ;
#ifdef F_124
F_109 ( 10 , L_67 , V_226 . V_130 ) ;
F_109 ( 51 , L_40 , F_144 ( F_145 () , & V_37 -> V_213 ) ) ;
F_109 ( 51 , L_68 , V_226 . V_132 ) ;
F_109 ( 11 , L_52 , V_37 -> V_143 ) ;
#endif
F_139 ( & V_226 ,
V_140 -> V_141 ) ;
} else {
#ifdef F_124
F_109 ( 12 , L_69 ) ;
#endif
}
}
if ( V_202 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_212 = F_61 ( T_11 , T_6 , 0 , - 1 , V_221 , & V_211 , L_49 ) ;
F_148 ( V_211 ) ;
V_210 = F_150 ( V_212 , V_223 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_148 ( V_210 ) ;
}
return V_150 ;
}
static struct V_149 *
F_152 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_206 * V_207 )
{
struct V_149 * V_150 = NULL ;
struct V_137 V_226 ;
struct V_172 * V_187 = NULL ;
struct V_129 V_209 ;
struct V_139 * V_140 = NULL ;
T_21 * V_210 ;
T_22 V_227 ;
T_21 * V_211 = NULL ;
T_10 * V_212 = NULL ;
#ifdef F_124
F_109 ( 51 , L_70 , F_144 ( F_145 () , & V_37 -> V_213 ) , F_144 ( F_145 () , & V_37 -> V_214 ) , V_207 -> V_66 ) ;
F_109 ( 10 , L_71 , V_37 -> V_143 ) ;
#endif
V_226 . V_132 = V_207 -> V_66 ;
if ( V_37 -> V_213 . type == V_215 && V_37 -> V_214 . type == V_215 )
{
V_226 . V_131 = F_146 ( ( const V_216 * ) V_37 -> V_214 . T_17 ) ;
} else {
V_226 . V_131 = F_147 ( F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
}
V_226 . V_130 = F_117 ( & V_226 ) ;
#ifdef F_124
F_109 ( 11 , L_72 , V_226 . V_130 ) ;
F_109 ( 11 , L_40 , F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
F_109 ( 51 , L_68 , V_226 . V_132 ) ;
#endif
V_187 = F_131 ( & V_226 , V_37 , TRUE ) ;
if( ! V_187 ) {
#ifdef F_124
F_109 ( 12 , L_73 ) ;
#endif
V_209 . V_132 = V_207 -> V_66 ;
if ( V_37 -> V_213 . type == V_215 && V_37 -> V_214 . type == V_215 )
{
V_209 . V_131 = F_146 ( ( const V_216 * ) V_37 -> V_214 . T_17 ) ;
} else {
V_209 . V_131 = F_147 ( F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
}
V_209 . V_130 = F_113 ( & V_209 ) ;
#ifdef F_124
F_109 ( 11 , L_62 , V_209 . V_130 ) ;
F_109 ( 51 , L_40 , F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
F_109 ( 51 , L_68 , V_209 . V_132 ) ;
#endif
V_140 = F_129 ( & V_209 , V_37 , FALSE ) ;
if( ! V_140 ) {
#ifdef F_124
F_109 ( 12 , L_69 ) ;
#endif
}
}
if ( V_187 ) {
V_150 = V_187 -> V_141 ;
} else if ( V_140 ) {
V_150 = V_140 -> V_141 ;
}
if ( V_150 ) {
#ifdef F_124
F_109 ( 12 , L_74 , V_150 -> V_142 ) ;
#endif
if ( V_202 && T_11 ) {
V_212 = F_61 ( T_11 , T_6 , 0 , - 1 , V_221 , & V_211 , L_49 ) ;
F_148 ( V_211 ) ;
V_210 = F_150 ( V_212 , V_223 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_148 ( V_210 ) ;
}
#ifdef F_124
F_109 ( 20 , L_75 , V_150 -> V_142 ) ;
#endif
if ( V_202 && V_212 ) {
V_210 = F_149 ( V_212 , V_228 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_76 ,
V_150 -> V_142 ) ;
F_148 ( V_210 ) ;
F_153 ( & V_227 , & V_37 -> V_147 , & V_150 -> V_146 ) ;
V_210 = F_154 ( V_212 , V_229 , T_6 , 0 , 0 , & V_227 ) ;
F_148 ( V_210 ) ;
}
F_155 ( V_150 , V_37 ) ;
} else {
#ifdef F_124
F_109 ( 12 , L_77 ) ;
#endif
}
return V_150 ;
}
static struct V_149 *
F_156 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_206 * V_207 )
{
struct V_149 * V_150 = NULL ;
struct V_123 V_208 ;
struct V_157 * V_158 , * V_160 ;
struct V_138 V_230 ;
T_21 * V_210 ;
T_22 V_227 ;
T_3 V_231 = FALSE ;
T_10 * V_212 = NULL ;
T_21 * V_211 = NULL ;
V_230 . V_132 = V_207 -> V_57 ;
if ( V_37 -> V_213 . type == V_215 && V_37 -> V_214 . type == V_215 )
{
V_230 . V_135 = F_146 ( ( const V_216 * ) V_37 -> V_213 . T_17 ) ;
V_230 . V_136 = F_146 ( ( const V_216 * ) V_37 -> V_214 . T_17 ) ;
} else {
V_230 . V_135 = F_147 ( F_144 ( F_145 () , & V_37 -> V_213 ) ) ;
V_230 . V_136 = F_147 ( F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
}
V_230 . V_130 = F_119 ( & V_230 ) ;
#ifdef F_124
F_109 ( 10 , L_78 , V_37 -> V_143 ) ;
F_109 ( 11 , L_39 , V_230 . V_130 ) ;
F_109 ( 51 , L_79 , F_144 ( F_145 () , & V_37 -> V_213 ) , F_144 ( F_145 () , & V_37 -> V_214 ) ) ;
F_109 ( 51 , L_68 , V_230 . V_132 ) ;
#endif
V_158 = (struct V_157 * )
F_12 ( V_198 , & V_230 ) ;
if ( V_158 ) {
do {
if ( V_37 -> V_143 == V_158 -> V_141 -> V_142 ) {
#ifdef F_124
F_109 ( 22 , L_80 ) ;
#endif
V_231 = FALSE ;
V_150 = V_158 -> V_141 ;
break;
}
if ( V_37 -> V_143 == V_158 -> V_141 -> V_144 ) {
#ifdef F_124
F_109 ( 22 , L_81 ) ;
#endif
V_231 = TRUE ;
V_150 = V_158 -> V_141 ;
break;
}
if ( V_37 -> V_143 > V_158 -> V_141 -> V_142 &&
V_158 -> V_141 -> V_144 == 0 ) {
#ifdef F_124
F_109 ( 12 , L_45 , V_230 . V_130 ) ;
#endif
V_158 -> V_141 -> V_144 = V_37 -> V_143 ;
V_158 -> V_141 -> V_145 = TRUE ;
V_158 -> V_141 -> V_220 = TRUE ;
V_150 = V_158 -> V_141 ;
V_231 = TRUE ;
if ( V_202 && T_11 ) {
V_212 = F_61 ( T_11 , T_6 , 0 , - 1 , V_221 , & V_211 , L_49 ) ;
F_148 ( V_211 ) ;
V_210 = F_150 ( V_212 , V_223 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_148 ( V_210 ) ;
#ifdef F_124
F_109 ( 20 , L_75 , V_150 -> V_142 ) ;
#endif
V_210 = F_149 ( V_212 , V_228 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_76 ,
V_150 -> V_142 ) ;
F_148 ( V_210 ) ;
F_153 ( & V_227 , & V_37 -> V_147 , & V_150 -> V_146 ) ;
V_210 = F_154 ( V_212 , V_229 , T_6 , 0 , 0 , & V_227 ) ;
F_148 ( V_210 ) ;
}
break;
}
if ( ! V_158 -> V_163 ) {
if ( ( V_158 -> V_141 -> V_144 != 0
&& V_37 -> V_143 > V_158 -> V_141 -> V_142
&& ( T_18 ) V_37 -> V_147 . V_217 > ( T_18 ) ( V_158 -> V_141 -> V_146 . V_217 + V_218 )
) ||
( V_158 -> V_141 -> V_144 == 0
&& V_37 -> V_143 > V_158 -> V_141 -> V_142
&& ( T_18 ) V_37 -> V_147 . V_217 > ( T_18 ) ( V_158 -> V_141 -> V_146 . V_217 + V_219 )
)
)
{
#ifdef F_124
F_109 ( 12 , L_43 , V_230 . V_130 ) ;
F_109 ( 12 , L_44 , V_37 -> V_143 , V_158 -> V_141 -> V_144 ) ;
#endif
V_208 . V_126 = V_201 ++ ;
V_150 = F_132 ( & V_208 , V_37 ) ;
V_160 = F_126 ( V_158 ,
V_150 ,
V_37 ) ;
#ifdef F_124
F_109 ( 12 , L_45 , V_230 . V_130 ) ;
#endif
F_125 ( V_160 , V_37 ) ;
V_158 = V_160 ;
} else {
if ( V_158 -> V_141 -> V_220 ) {
#ifdef F_124
F_109 ( 12 , L_46 , V_230 . V_130 ) ;
F_109 ( 12 , L_44 , V_37 -> V_143 , V_158 -> V_141 -> V_144 ) ;
#endif
V_208 . V_126 = V_201 ++ ;
V_150 = F_132 ( & V_208 , V_37 ) ;
V_160 = F_126 ( V_158 ,
V_150 ,
V_37 ) ;
#ifdef F_124
F_109 ( 12 , L_47 , V_230 . V_130 ) ;
#endif
F_125 ( V_160 , V_37 ) ;
V_158 = V_160 ;
} else {
V_150 = V_158 -> V_141 ;
#ifdef F_124
F_109 ( 12 , L_74 , V_150 -> V_142 ) ;
#endif
if ( V_202 && T_11 ) {
V_212 = F_61 ( T_11 , T_6 , 0 , - 1 , V_221 , & V_211 , L_49 ) ;
F_148 ( V_211 ) ;
V_210 = F_150 ( V_212 , V_223 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_148 ( V_210 ) ;
#ifdef F_124
F_109 ( 20 , L_75 , V_150 -> V_142 ) ;
#endif
V_210 = F_149 ( V_212 , V_228 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_76 ,
V_150 -> V_142 ) ;
F_148 ( V_210 ) ;
F_153 ( & V_227 , & V_37 -> V_147 , & V_150 -> V_146 ) ;
V_210 = F_154 ( V_212 , V_229 , T_6 , 0 , 0 , & V_227 ) ;
F_148 ( V_210 ) ;
}
V_150 = V_158 -> V_141 ;
}
}
break;
}
V_158 = V_158 -> V_163 ;
} while ( V_158 != NULL );
} else {
#ifdef F_124
F_109 ( 10 , L_51 , V_230 . V_130 ) ;
#endif
V_208 . V_126 = V_201 ++ ;
V_150 = F_132 ( & V_208 , V_37 ) ;
V_158 = F_137 ( & V_230 , V_150 ) ;
#ifdef F_124
F_109 ( 11 , L_45 , V_230 . V_130 ) ;
F_109 ( 11 , L_52 , V_37 -> V_143 ) ;
#endif
F_125 ( V_158 , V_37 ) ;
}
if ( V_202 && T_11 &&
V_150 &&
V_150 -> V_126 ) {
V_212 = F_61 ( T_11 , T_6 , 0 , - 1 , V_221 , & V_211 , L_49 ) ;
F_148 ( V_211 ) ;
V_210 = F_150 ( V_212 , V_223 , T_6 , 0 , 0 , V_150 -> V_126 ) ;
F_148 ( V_210 ) ;
}
if( V_202 && V_212 &&
V_158 -> V_141 -> V_144 != 0 ) {
if ( ! V_231 ) {
#ifdef F_124
F_109 ( 20 , L_53 , V_158 -> V_141 -> V_144 ) ;
#endif
V_210 = F_149 ( V_212 , V_224 , T_6 , 0 , 0 ,
V_158 -> V_141 -> V_144 ,
L_54 ,
V_158 -> V_141 -> V_144 ) ;
F_148 ( V_210 ) ;
} else {
#ifdef F_124
F_109 ( 20 , L_75 , V_150 -> V_142 ) ;
#endif
if ( V_202 ) {
V_210 = F_149 ( V_212 , V_228 , T_6 , 0 , 0 ,
V_150 -> V_142 ,
L_76 ,
V_150 -> V_142 ) ;
F_148 ( V_210 ) ;
F_153 ( & V_227 , & V_37 -> V_147 , & V_150 -> V_146 ) ;
V_210 = F_154 ( V_212 , V_229 , T_6 , 0 , 0 , & V_227 ) ;
F_148 ( V_210 ) ;
}
}
}
return V_150 ;
}
struct V_149 *
F_157 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_206 * V_207 )
{
struct V_149 * V_232 = NULL ;
if( V_37 == NULL || V_37 -> V_143 == 0 ) {
return NULL ;
}
switch ( V_207 -> V_60 ) {
case V_61 :
#ifdef F_124
F_109 ( 1 , L_82 ) ;
#endif
V_232 = F_143 ( T_6 , V_37 , T_11 , V_207 ) ;
break;
case V_70 :
#ifdef F_124
F_109 ( 1 , L_83 ) ;
#endif
V_232 = F_151 ( T_6 , V_37 , T_11 , V_207 ) ;
break;
case V_75 :
#ifdef F_124
F_109 ( 1 , L_84 ) ;
#endif
V_232 = F_152 ( T_6 , V_37 , T_11 , V_207 ) ;
break;
case V_67 :
#ifdef F_124
F_109 ( 1 , L_85 ) ;
#endif
V_232 = F_152 ( T_6 , V_37 , T_11 , V_207 ) ;
break;
case V_233 :
case V_234 :
#ifdef F_124
F_109 ( 1 , L_86 ) ;
#endif
V_232 = F_156 ( T_6 , V_37 , T_11 , V_207 ) ;
break;
default:
#ifdef F_124
F_109 ( 1 , L_87 , V_207 -> V_60 ) ;
#endif
break;
}
#ifdef F_124
if ( V_232 )
F_109 ( 1 , L_88 , V_232 -> V_126 ) ;
#endif
return V_232 ;
}
struct V_206 *
F_158 ( void )
{
struct V_206 * V_207 ;
V_235 ++ ;
if( V_235 == V_236 ) {
V_235 = 0 ;
}
V_207 = & V_237 [ V_235 ] ;
memset ( V_207 , 0 , sizeof( struct V_206 ) ) ;
return V_207 ;
}
void
F_155 ( struct V_149 * V_150 ,
T_16 * V_37 )
{
#ifdef F_124
F_109 ( 60 , L_89 ) ;
#endif
if ( V_150 ) {
V_150 -> V_145 = TRUE ;
V_150 -> V_144 = V_37 -> V_143 ;
V_150 -> V_238 = V_37 -> V_147 ;
V_150 -> V_220 = TRUE ;
if ( V_150 -> V_175
&& ! V_203 ) {
if ( V_150 -> V_175 -> V_177 ) {
if ( V_150 -> V_175 -> V_178 ) {
#ifdef F_124
F_109 ( 20 , L_90 ) ;
#endif
V_150 -> V_175 -> V_178 -> V_177
= V_150 -> V_175 -> V_177 ;
V_150 -> V_175 -> V_177 -> V_178
= V_150 -> V_175 -> V_178 ;
F_7 ( V_188 , V_150 -> V_175 -> V_176 ) ;
} else {
#ifdef F_124
F_109 ( 20 , L_91 ) ;
#endif
}
} else if ( ! V_203 ) {
#ifdef F_124
F_109 ( 20 , L_92 ) ;
#endif
F_7 ( V_188 , V_150 -> V_175 -> V_176 ) ;
}
}
if ( V_150 -> V_168
&& ! V_203 ) {
if ( V_150 -> V_168 -> V_170 ) {
if ( V_150 -> V_168 -> V_171 ) {
#ifdef F_124
F_109 ( 20 , L_93 ) ;
#endif
V_150 -> V_168 -> V_171 -> V_170
= V_150 -> V_168 -> V_170 ;
V_150 -> V_168 -> V_170 -> V_171
= V_150 -> V_168 -> V_171 ;
F_7 ( V_184 , V_150 -> V_168 -> V_169 ) ;
} else {
#ifdef F_124
F_109 ( 20 , L_94 ) ;
#endif
}
} else if ( ! V_203 ) {
#ifdef F_124
F_109 ( 20 , L_95 ) ;
#endif
F_7 ( V_184 , V_150 -> V_168 -> V_169 ) ;
}
}
if ( V_150 -> V_152
&& ! V_203 ) {
if ( V_150 -> V_152 -> V_154 ) {
if ( V_150 -> V_152 -> V_155 ) {
#ifdef F_124
F_109 ( 20 , L_96 ) ;
#endif
V_150 -> V_152 -> V_155 -> V_154
= V_150 -> V_152 -> V_154 ;
V_150 -> V_152 -> V_154 -> V_155
= V_150 -> V_152 -> V_155 ;
F_7 ( V_181 , V_150 -> V_152 -> V_153 ) ;
} else {
#ifdef F_124
F_109 ( 20 , L_97 ) ;
#endif
}
} else if ( ! V_203 ) {
#ifdef F_124
F_109 ( 20 , L_98 ) ;
#endif
F_7 ( V_181 , V_150 -> V_152 -> V_153 ) ;
}
}
if ( V_150 -> V_161
&& ! V_203 ) {
if ( V_150 -> V_161 -> V_163 ) {
if ( V_150 -> V_161 -> V_164 ) {
#ifdef F_124
F_109 ( 20 , L_99 ) ;
#endif
V_150 -> V_161 -> V_164 -> V_163
= V_150 -> V_161 -> V_163 ;
V_150 -> V_161 -> V_163 -> V_164
= V_150 -> V_161 -> V_164 ;
F_7 ( V_198 , V_150 -> V_161 -> V_162 ) ;
} else {
#ifdef F_124
F_109 ( 20 , L_100 ) ;
#endif
}
} else if ( ! V_203 ) {
#ifdef F_124
F_109 ( 20 , L_101 ) ;
#endif
F_7 ( V_198 , V_150 -> V_161 -> V_162 ) ;
}
}
if ( ! V_203 ) {
#ifdef F_124
F_109 ( 20 , L_102 ) ;
#endif
F_7 ( V_192 , V_150 -> V_128 ) ;
}
} else {
#ifdef F_124
F_109 ( 20 , L_103 ) ;
#endif
}
}
static int
F_159 ( T_5 * T_6 , T_16 * V_37 , T_10 * V_239 , void * T_17 V_6 )
{
T_21 * V_240 = NULL ;
T_10 * T_11 = NULL ;
struct V_149 * V_241 ;
T_2 V_242 ;
T_8 V_112 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
F_160 ( T_6 , 0 , & V_30 , & V_31 , & V_32 ) ;
if( V_30 == V_243 ) {
switch ( V_32 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
return F_161 ( V_244 , T_6 , V_37 , V_239 ) ;
default:
return F_162 ( T_6 ) ;
}
}
F_107 ( & V_112 , V_113 , TRUE , V_37 ) ;
V_43 = V_239 ;
V_245 = NULL ;
F_69 ( V_37 -> V_58 , V_246 , L_104 ) ;
if( V_239 ) {
V_240 = F_163 ( V_239 , V_247 , T_6 , 0 , - 1 , V_248 ) ;
T_11 = F_164 ( V_240 , V_249 ) ;
V_245 = T_11 ;
}
V_82 = NULL ;
V_250 = NULL ;
F_165 ( & V_83 ) ;
V_112 . V_251 = & V_83 ;
V_56 = F_158 () ;
V_252 = FALSE ;
V_253 = NULL ;
F_77 ( FALSE , T_6 , 0 , & V_112 , T_11 , - 1 ) ;
if ( V_204 && ! V_252 ) {
V_241 = F_157 ( T_6 , V_37 , V_245 , V_56 ) ;
V_83 . V_141 = V_241 ;
if ( V_241 && V_82 && ! V_241 -> V_254 ) {
F_166 ( V_241 -> V_84 , V_82 , sizeof( V_241 -> V_84 ) ) ;
V_241 -> V_254 = TRUE ;
if ( ( V_242 = F_167 ( V_255 , V_82 ) ) ) {
V_241 -> V_242 = V_242 ;
V_241 -> V_256 = TRUE ;
}
}
if ( V_204 && V_241 && V_241 -> V_257 ) {
( V_241 -> V_257 ) ( T_6 , V_37 , V_245 , V_241 ) ;
}
}
return F_162 ( T_6 ) ;
}
void
F_168 ( void )
{
V_258 = F_169 ( L_105 ) ;
V_244 = F_170 ( L_106 , V_247 ) ;
V_255 = F_171 ( L_107 ) ;
V_215 = F_172 ( L_108 ) ;
#line 1 "./asn1/tcap/packet-tcap-dis-tab.c"
F_173 ( L_109 , F_108 , V_247 , L_110 ) ;
F_173 ( L_111 , F_106 , V_247 , L_112 ) ;
#line 1982 "./asn1/tcap/packet-tcap-template.c"
}
void
F_174 ( void )
{
static T_23 V_259 [] = {
{ & V_260 ,
{ L_113 ,
L_114 ,
V_261 , V_262 , NULL , 0 ,
NULL , V_263 }
} ,
{ & V_264 ,
{ L_115 ,
L_116 ,
V_261 , V_265 , NULL , 0 ,
NULL , V_263 }
} ,
{ & V_266 ,
{ L_117 ,
L_118 ,
V_267 , V_268 , NULL , 0 ,
NULL , V_263 }
} ,
{ & V_52 ,
{ L_119 ,
L_120 ,
V_267 , V_268 , NULL , 0 ,
NULL , V_263 }
} ,
{ & V_269 ,
{ L_121 ,
L_122 ,
V_270 , V_262 , NULL , 0 ,
NULL , V_263 }
} ,
{ & V_223 ,
{ L_123 ,
L_124 ,
V_271 , V_265 , NULL , 0x0 ,
NULL , V_263 }
} ,
{ & V_224 ,
{ L_125 ,
L_126 ,
V_272 , V_268 , NULL , 0x0 ,
L_127 , V_263 }
} ,
{ & V_228 ,
{ L_128 ,
L_129 ,
V_272 , V_268 , NULL , 0x0 ,
L_130 , V_263 }
} ,
{ & V_229 ,
{ L_131 ,
L_132 ,
V_273 , V_268 , NULL , 0x0 ,
L_133 , V_263 }
} ,
{ & V_222 ,
{ L_134 ,
L_135 ,
V_272 , V_268 , NULL , 0x0 ,
L_136 , V_263 }
} ,
#line 1 "./asn1/tcap/packet-tcap-hfarr.c"
{ & V_114 ,
{ L_137 , L_138 ,
V_271 , V_265 , F_175 ( V_274 ) , 0 ,
NULL , V_263 } } ,
{ & V_115 ,
{ L_139 , L_140 ,
V_271 , V_265 , F_175 ( V_275 ) , 0 ,
NULL , V_263 } } ,
{ & V_276 ,
{ L_141 , L_142 ,
V_277 , V_268 , NULL , 0 ,
L_143 , V_263 } } ,
{ & V_278 ,
{ L_144 , L_145 ,
V_267 , V_268 , NULL , 0 ,
L_146 , V_263 } } ,
{ & V_279 ,
{ L_147 , L_148 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_281 ,
{ L_149 , L_150 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_282 ,
{ L_151 , L_152 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_283 ,
{ L_153 , L_154 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_284 ,
{ L_155 , L_156 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_285 ,
{ L_157 , L_158 ,
V_267 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_286 ,
{ L_159 , L_160 ,
V_271 , V_265 , NULL , 0 ,
L_161 , V_263 } } ,
{ & V_55 ,
{ L_162 , L_163 ,
V_267 , V_268 , NULL , 0 ,
L_164 , V_263 } } ,
{ & V_65 ,
{ L_165 , L_166 ,
V_267 , V_268 , NULL , 0 ,
L_167 , V_263 } } ,
{ & V_287 ,
{ L_168 , L_169 ,
V_271 , V_265 , F_175 ( V_288 ) , 0 ,
NULL , V_263 } } ,
{ & V_289 ,
{ L_170 , L_171 ,
V_271 , V_265 , F_175 ( V_290 ) , 0 ,
NULL , V_263 } } ,
{ & V_291 ,
{ L_172 , L_173 ,
V_267 , V_268 , NULL , 0 ,
L_174 , V_263 } } ,
{ & V_292 ,
{ L_175 , L_176 ,
V_271 , V_265 , F_175 ( V_293 ) , 0 ,
NULL , V_263 } } ,
{ & V_294 ,
{ L_177 , L_178 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_295 ,
{ L_179 , L_180 ,
V_280 , V_268 , NULL , 0 ,
L_181 , V_263 } } ,
{ & V_296 ,
{ L_182 , L_183 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_297 ,
{ L_184 , L_185 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_298 ,
{ L_186 , L_187 ,
V_280 , V_268 , NULL , 0 ,
L_181 , V_263 } } ,
{ & V_299 ,
{ L_188 , L_189 ,
V_300 , V_265 , NULL , 0 ,
L_190 , V_263 } } ,
{ & V_301 ,
{ L_191 , L_192 ,
V_300 , V_265 , NULL , 0 ,
L_190 , V_263 } } ,
{ & V_302 ,
{ L_193 , L_194 ,
V_271 , V_265 , F_175 ( V_303 ) , 0 ,
L_195 , V_263 } } ,
{ & V_304 ,
{ L_196 , L_197 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_305 ,
{ L_198 , L_199 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_306 ,
{ L_200 , L_201 ,
V_271 , V_265 , F_175 ( V_307 ) , 0 ,
NULL , V_263 } } ,
{ & V_308 ,
{ L_202 , L_203 ,
V_271 , V_265 , F_175 ( V_309 ) , 0 ,
NULL , V_263 } } ,
{ & V_310 ,
{ L_204 , L_205 ,
V_300 , V_265 , NULL , 0 ,
L_190 , V_263 } } ,
{ & V_311 ,
{ L_206 , L_207 ,
V_280 , V_268 , NULL , 0 ,
NULL , V_263 } } ,
{ & V_312 ,
{ L_208 , L_209 ,
V_271 , V_265 , F_175 ( V_313 ) , 0 ,
NULL , V_263 } } ,
{ & V_314 ,
{ L_210 , L_211 ,
V_300 , V_265 , F_175 ( V_315 ) , 0 ,
NULL , V_263 } } ,
{ & V_316 ,
{ L_212 , L_213 ,
V_300 , V_265 , F_175 ( V_317 ) , 0 ,
NULL , V_263 } } ,
{ & V_318 ,
{ L_214 , L_215 ,
V_300 , V_265 , F_175 ( V_319 ) , 0 ,
NULL , V_263 } } ,
{ & V_320 ,
{ L_216 , L_217 ,
V_300 , V_265 , F_175 ( V_321 ) , 0 ,
NULL , V_263 } } ,
{ & V_322 ,
{ L_218 , L_219 ,
V_300 , V_265 , NULL , 0 ,
L_220 , V_263 } } ,
{ & V_323 ,
{ L_221 , L_222 ,
V_277 , V_268 , NULL , 0 ,
L_143 , V_263 } } ,
{ & V_324 ,
{ L_223 , L_224 ,
V_300 , V_265 , NULL , 0 ,
L_225 , V_263 } } ,
{ & V_325 ,
{ L_226 , L_227 ,
V_300 , V_265 , NULL , 0 ,
L_220 , V_263 } } ,
{ & V_326 ,
{ L_228 , L_229 ,
V_280 , V_268 , NULL , 0 ,
L_230 , V_263 } } ,
{ & V_327 ,
{ L_231 , L_232 ,
V_267 , V_268 , NULL , 0 ,
L_233 , V_263 } } ,
{ & V_328 ,
{ L_234 , L_235 ,
V_277 , V_268 , NULL , 0 ,
L_236 , V_263 } } ,
{ & V_329 ,
{ L_237 , L_238 ,
V_271 , V_265 , NULL , 0 ,
L_239 , V_263 } } ,
{ & V_330 ,
{ L_240 , L_241 ,
V_280 , V_268 , NULL , 0 ,
L_242 , V_263 } } ,
{ & V_331 ,
{ L_243 , L_244 ,
V_280 , V_268 , NULL , 0 ,
L_245 , V_263 } } ,
{ & V_332 ,
{ L_246 , L_247 ,
V_280 , V_268 , NULL , 0 ,
L_248 , V_263 } } ,
{ & V_333 ,
{ L_249 , L_250 ,
V_280 , V_268 , NULL , 0 ,
L_251 , V_263 } } ,
{ & V_334 ,
{ L_231 , L_232 ,
V_267 , V_268 , NULL , 0 ,
L_252 , V_263 } } ,
{ & V_335 ,
{ L_234 , L_235 ,
V_277 , V_268 , NULL , 0 ,
L_253 , V_263 } } ,
{ & V_336 ,
{ L_237 , L_238 ,
V_271 , V_265 , NULL , 0 ,
L_254 , V_263 } } ,
{ & V_337 ,
{ L_240 , L_241 ,
V_280 , V_268 , NULL , 0 ,
L_242 , V_263 } } ,
{ & V_338 ,
{ L_231 , L_232 ,
V_267 , V_268 , NULL , 0 ,
L_255 , V_263 } } ,
{ & V_339 ,
{ L_234 , L_235 ,
V_277 , V_268 , NULL , 0 ,
L_256 , V_263 } } ,
{ & V_340 ,
{ L_257 , L_258 ,
V_300 , V_265 , F_175 ( V_341 ) , 0 ,
L_259 , V_263 } } ,
{ & V_342 ,
{ L_260 , L_261 ,
V_271 , V_265 , F_175 ( V_343 ) , 0 ,
L_262 , V_263 } } ,
{ & V_344 ,
{ L_237 , L_238 ,
V_271 , V_265 , NULL , 0 ,
L_263 , V_263 } } ,
{ & V_345 ,
{ L_240 , L_241 ,
V_280 , V_268 , NULL , 0 ,
L_242 , V_263 } } ,
{ & V_346 ,
{ L_264 , L_265 ,
V_300 , V_265 , F_175 ( V_347 ) , 0 ,
L_266 , V_263 } } ,
{ & V_348 ,
{ L_237 , L_238 ,
V_271 , V_265 , NULL , 0 ,
L_267 , V_263 } } ,
{ & V_349 ,
{ L_240 , L_241 ,
V_280 , V_268 , NULL , 0 ,
L_242 , V_263 } } ,
{ & V_350 ,
{ L_268 , L_269 ,
V_300 , V_265 , F_175 ( V_351 ) , 0 ,
NULL , V_263 } } ,
{ & V_352 ,
{ L_270 , L_271 ,
V_300 , V_265 , F_175 ( V_353 ) , 0 ,
NULL , V_263 } } ,
{ & V_354 ,
{ L_272 , L_273 ,
V_355 , 8 , NULL , 0x80 ,
NULL , V_263 } } ,
{ & V_356 ,
{ L_272 , L_273 ,
V_355 , 8 , NULL , 0x80 ,
NULL , V_263 } } ,
{ & V_357 ,
{ L_272 , L_273 ,
V_355 , 8 , NULL , 0x80 ,
NULL , V_263 } } ,
#line 2055 "./asn1/tcap/packet-tcap-template.c"
} ;
static T_14 * V_358 [] = {
& V_249 ,
& V_359 ,
& V_54 ,
& V_64 ,
& V_221 ,
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
#line 2065 "./asn1/tcap/packet-tcap-template.c"
} ;
T_24 * V_360 ;
V_247 = F_176 ( V_361 , V_362 , V_363 ) ;
F_177 ( V_247 , V_259 , F_178 ( V_259 ) ) ;
F_179 ( V_358 , F_178 ( V_358 ) ) ;
V_360 = F_180 ( V_247 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_181 ( V_360 , L_274 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_181 ( V_360 , L_275 ) ;
#endif
F_182 ( & V_364 , L_276 , V_365 ) ;
F_183 ( V_360 , L_277 , L_278 ,
L_279 ,
& V_364 , V_365 ) ;
F_184 ( V_360 , L_280 ,
L_281 ,
L_282 ,
& V_204 ) ;
F_184 ( V_360 , L_283 ,
L_284 ,
L_285 ,
& V_203 ) ;
F_185 ( V_360 , L_286 ,
L_287 ,
L_288 ,
10 , & V_218 ) ;
F_185 ( V_360 , L_289 ,
L_290 ,
L_291 ,
10 , & V_219 ) ;
V_3 = F_142 ( V_366 , V_367 ) ;
V_5 = F_142 ( V_366 , V_367 ) ;
F_186 ( L_292 , F_159 , V_247 ) ;
V_4 = F_187 ( F_159 , V_247 ) ;
F_188 ( & V_368 ) ;
F_189 ( & V_369 ) ;
}
static void F_190 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_9 ( L_1 , V_1 , V_4 ) ;
}
}
static void F_191 ( T_1 V_1 )
{
if ( V_1 && ! F_11 ( V_1 ) && ! F_8 ( V_1 ) ) {
F_4 ( L_1 , V_1 , V_4 ) ;
}
}
static void V_368 ( void )
{
V_370 = F_192 ( V_364 ) ;
F_193 ( V_370 , F_191 ) ;
F_140 () ;
}
static void V_369 ( void )
{
F_193 ( V_370 , F_190 ) ;
F_194 ( V_370 ) ;
}
static int
F_29 ( T_8 * T_9 , T_10 * T_11 , T_5 * T_6 , int T_7 )
{
T_14 V_371 , V_51 , V_372 ;
T_5 * V_29 ;
T_10 * V_50 ;
T_13 V_30 ;
T_3 V_31 ;
T_25 V_32 ;
T_1 V_33 ;
T_1 V_373 ;
T_1 V_374 ;
T_3 V_36 ;
while ( F_62 ( T_6 , T_7 ) > 0 )
{
V_51 = T_7 ;
T_7 = F_160 ( T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_371 = T_7 ;
T_7 = F_195 ( T_6 , T_7 , & V_33 , & V_36 ) ;
V_372 = T_7 ;
V_373 = V_371 - V_51 ;
V_374 = V_372 - V_371 ;
if ( V_31 )
{
V_50 = F_61 ( T_11 , T_6 , V_51 ,
V_33 + ( V_372 - V_51 ) , V_359 , NULL ,
L_293 ) ;
F_149 ( V_50 , V_260 , T_6 ,
V_51 , V_373 , V_32 ,
L_294 ) ;
F_150 ( V_50 , V_260 , T_6 , V_51 ,
V_373 , V_30 ) ;
F_150 ( V_50 , V_264 , T_6 , V_371 ,
V_374 , V_33 ) ;
if ( V_33 - ( 2 * V_36 ) )
{
V_29 = F_48 ( T_6 , T_7 , V_33 - ( 2 * V_36 ) ) ;
F_29 ( T_9 , V_50 , V_29 , 0 ) ;
}
if ( V_36 )
F_163 ( V_50 , V_269 , T_6 , T_7 + V_33 - 2 , 2 , V_375 ) ;
T_7 += V_33 ;
}
else
{
V_50 = F_196 ( T_11 , T_6 , V_51 ,
V_33 + ( V_372 - V_51 ) , V_359 , NULL ,
L_295 , V_32 ) ;
F_150 ( V_50 , V_260 , T_6 , V_51 ,
V_373 , V_32 ) ;
F_150 ( V_50 , V_264 , T_6 ,
V_51 + V_373 , V_374 , V_33 ) ;
if ( V_33 )
{
V_29 = F_48 ( T_6 , T_7 , V_33 ) ;
F_58 ( TRUE , T_9 , T_11 , V_29 , 0 ,
V_266 , NULL ) ;
}
T_7 += V_33 ;
}
}
return T_7 ;
}
static void F_165 ( struct V_376 * V_377 )
{
memset ( V_377 , 0 , sizeof( struct V_376 ) ) ;
}
static int
F_52 ( T_3 T_4 V_6 , T_5 * T_6 , int T_7 , T_8 * T_9 V_6 , T_10 * T_11 , int T_12 V_6 )
{
T_2 V_242 = NULL ;
T_3 V_378 = FALSE ;
struct V_149 * V_241 = NULL ;
if ( V_204 ) {
if ( ! V_252 ) {
V_241 = F_157 ( T_6 , T_9 -> V_37 , V_245 , V_56 ) ;
V_252 = TRUE ;
V_253 = V_241 ;
V_83 . V_141 = V_241 ;
} else {
V_241 = V_253 ;
V_83 . V_141 = V_241 ;
}
}
if ( V_241 ) {
if ( V_82 ) {
if ( V_241 -> V_254 ) {
if ( strncmp ( V_241 -> V_84 , V_82 , sizeof( V_241 -> V_84 ) ) != 0 ) {
F_166 ( V_241 -> V_84 , V_82 , sizeof( V_241 -> V_84 ) ) ;
if ( ( V_242 = F_167 ( V_255 , V_82 ) ) ) {
V_241 -> V_242 = V_242 ;
V_241 -> V_256 = TRUE ;
}
}
} else {
F_166 ( V_241 -> V_84 , V_82 , sizeof( V_241 -> V_84 ) ) ;
V_241 -> V_254 = TRUE ;
if ( ( V_242
= F_167 ( V_255 , V_82 ) ) ) {
V_241 -> V_242 = V_242 ;
V_241 -> V_256 = TRUE ;
} else {
if ( ( V_242 = F_8 ( T_9 -> V_37 -> V_379 ) ) ) {
V_241 -> V_242 = V_242 ;
V_241 -> V_256 = TRUE ;
}
}
}
} else {
if ( V_241 -> V_254 ) {
V_83 . V_84 = ( void * ) V_241 -> V_84 ;
V_83 . V_85 = TRUE ;
}
}
}
if ( V_241
&& V_241 -> V_256 ) {
V_242 = V_241 -> V_242 ;
V_378 = TRUE ;
}
if ( ! V_378 && V_380 ) {
V_378 = TRUE ;
V_242 = V_380 ;
}
if ( ! V_378 ) {
if ( V_255 && V_82 ) {
if ( ( V_242
= F_167 ( V_255 , V_82 ) ) ) {
V_378 = TRUE ;
} else {
if ( ( V_242
= F_8 ( T_9 -> V_37 -> V_379 ) ) ) {
V_378 = TRUE ;
} else {
V_242 = V_258 ;
V_378 = TRUE ;
}
}
} else {
if ( ( V_242 = F_8 ( T_9 -> V_37 -> V_379 ) ) ) {
V_378 = TRUE ;
} else {
V_242 = V_258 ;
V_378 = TRUE ;
}
}
} else {
}
if ( V_378 ) {
F_197 ( V_242 , T_6 , T_9 -> V_37 , T_11 , T_9 -> V_251 ) ;
F_198 ( T_9 -> V_37 -> V_58 , V_59 ) ;
}
return T_7 ;
}
void
F_199 ( T_2 V_381 , T_5 * T_6 , T_16 * V_37 , T_10 * T_11 )
{
V_380 = V_381 ;
F_49 {
F_159 ( T_6 , V_37 , T_11 , NULL ) ;
} F_200 {
V_380 = NULL ;
V_382 ;
} V_42 ;
V_380 = NULL ;
}
