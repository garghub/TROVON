extern void F_1 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( L_1 , V_1 , V_2 ) ;
F_2 ( L_2 , V_1 , V_3 ) ;
}
extern void F_3 ( T_1 V_1 , T_2 V_2 ) {
F_2 ( L_3 , V_1 , V_2 ) ;
F_2 ( L_2 , V_1 , V_3 ) ;
}
extern void F_4 ( T_1 V_1 , T_2 V_2 ) {
F_5 ( L_1 , V_1 , V_2 ) ;
if ( ! F_6 ( V_1 ) )
F_5 ( L_2 , V_1 , V_3 ) ;
}
extern void F_7 ( T_1 V_1 , T_2 V_2 V_4 ) {
F_5 ( L_3 , V_1 , V_2 ) ;
if ( ! F_8 ( V_1 ) )
F_5 ( L_2 , V_1 , V_3 ) ;
}
T_2 F_8 ( T_1 V_1 ) {
return F_9 ( V_5 , V_1 ) ;
}
T_2 F_6 ( T_1 V_1 ) {
return F_9 ( V_6 , V_1 ) ;
}
static int
F_10 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_11 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , NULL ) ;
return T_7 ;
}
static int
F_12 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 72 "./asn1/tcap/tcap.cnf"
T_7 = F_13 ( TRUE , T_6 , T_7 , T_9 , T_11 , - 1 ) ;
return T_7 ;
}
static int
F_14 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_7 , T_12 , V_8 ) ;
return T_7 ;
}
static int
F_16 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 67 "./asn1/tcap/tcap.cnf"
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_9 , 8 , TRUE , F_14 ) ;
return T_7 ;
}
static int
F_18 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 62 "./asn1/tcap/tcap.cnf"
T_7 = F_16 ( FALSE , T_6 , T_7 , T_9 , T_11 , - 1 ) ;
return T_7 ;
}
static int
F_19 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 11 , TRUE , F_18 ) ;
return T_7 ;
}
static int
F_20 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_22 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_23 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_11 , T_12 , V_12 ,
NULL ) ;
return T_7 ;
}
static int
F_25 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 77 "./asn1/tcap/tcap.cnf"
T_7 = F_26 ( T_9 , T_11 , T_6 , T_7 ) ;
return T_7 ;
}
static int
F_27 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_13 , T_12 , V_14 ) ;
return T_7 ;
}
static int
F_28 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_15 , T_12 , V_16 ) ;
return T_7 ;
}
static int
F_29 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_17 , T_12 , V_18 ) ;
return T_7 ;
}
static int
F_30 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_31 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_19 , T_12 , V_20 ,
NULL ) ;
return T_7 ;
}
static int
F_32 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_21 , T_12 , V_22 ) ;
return T_7 ;
}
static int
F_33 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_34 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ) ;
return T_7 ;
}
static int
F_35 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_23 , T_12 , V_24 ,
NULL ) ;
return T_7 ;
}
static int
F_36 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_37 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_38 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_39 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_40 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_25 , T_12 , V_26 ,
NULL ) ;
return T_7 ;
}
static int
F_41 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_27 , T_12 , V_28 ) ;
return T_7 ;
}
static int
F_42 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 82 "./asn1/tcap/tcap.cnf"
T_5 * V_29 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
T_1 V_33 , V_34 ;
volatile T_1 V_35 ;
T_14 V_36 ;
V_34 = F_43 ( T_9 -> V_37 , T_11 , T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_34 = F_44 ( T_9 -> V_37 , T_11 , T_6 , V_34 , & V_33 , & V_36 ) ;
V_29 = F_45 ( T_6 , T_7 , V_33 + V_34 - T_7 ) ;
if ( ! V_29 )
return V_34 ;
V_35 = T_7 ;
F_46 {
V_35 = F_24 ( T_9 , T_11 , T_6 , V_35 ,
V_38 , T_12 , V_39 ,
NULL ) ;
}
F_47 {
F_48 ( T_6 , T_9 -> V_37 , T_11 , V_40 , V_41 ) ;
}
V_42 ;
T_7 = V_35 ;
F_49 ( T_4 , V_29 , 0 , T_9 , V_43 , T_12 ) ;
return T_7 ;
}
static int
F_50 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_51 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_44 , T_12 , V_45 ) ;
return T_7 ;
}
static int
F_52 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 12 , TRUE , F_50 ) ;
return T_7 ;
}
static int
F_53 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_46 , T_12 , V_47 ) ;
return T_7 ;
}
static int
F_54 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_55 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_56 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 134 "./asn1/tcap/tcap.cnf"
T_5 * V_48 ;
T_15 V_33 , V_49 ;
T_10 * V_50 ;
int V_51 ;
struct V_52 * V_53 = (struct V_52 * ) T_9 -> V_54 ;
T_12 = V_55 ;
V_51 = T_7 ;
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 8 , TRUE , F_54 ) ;
F_57 ( T_9 -> V_56 ) ;
T_7 = V_51 ;
V_50 = F_58 ( T_11 , T_6 , T_7 , - 1 , V_57 , NULL , L_4 ) ;
T_7 = F_55 ( T_4 , T_9 , V_50 , T_6 , T_7 , V_58 ,
& V_48 ) ;
if ( V_48 ) {
V_33 = F_59 ( V_48 , 0 ) ;
switch( V_33 ) {
case 1 :
V_59 -> V_60 = F_60 ( V_48 , 0 ) ;
break;
case 2 :
V_59 -> V_60 = F_61 ( V_48 , 0 ) ;
break;
case 3 :
V_59 -> V_60 = F_62 ( V_48 , 0 ) ;
break;
case 4 :
V_59 -> V_60 = F_63 ( V_48 , 0 ) ;
break;
default:
V_59 -> V_60 = 0 ;
break;
}
V_53 -> V_60 = V_59 -> V_60 ;
if ( V_33 ) {
F_64 ( T_9 -> V_37 -> V_61 , V_62 , L_5 ) ;
for ( V_49 = 0 ; V_49 < V_33 ; V_49 ++ ) {
F_65 ( T_9 -> V_37 -> V_61 , V_62 , L_6 , F_60 ( V_48 , V_49 ) ) ;
}
F_64 ( T_9 -> V_37 -> V_61 , V_62 , L_7 ) ;
}
}
return T_7 ;
}
static int
F_66 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 228 "./asn1/tcap/tcap.cnf"
V_59 -> V_63 = V_64 ;
F_67 ( T_9 -> V_37 -> V_61 , V_62 , L_8 ) ;
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_65 , T_12 , V_66 ) ;
return T_7 ;
}
static int
F_68 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 182 "./asn1/tcap/tcap.cnf"
T_5 * V_48 ;
T_15 V_33 , V_49 ;
T_10 * V_50 ;
int V_51 ;
struct V_52 * V_53 = (struct V_52 * ) T_9 -> V_54 ;
T_12 = V_55 ;
V_51 = T_7 ;
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 9 , TRUE , F_54 ) ;
F_57 ( T_9 -> V_56 ) ;
T_7 = V_51 ;
V_50 = F_58 ( T_11 , T_6 , T_7 , - 1 , V_67 , NULL , L_9 ) ;
T_7 = F_55 ( T_4 , T_9 , V_50 , T_6 , T_7 , V_68 ,
& V_48 ) ;
if ( V_48 ) {
V_33 = F_59 ( V_48 , 0 ) ;
switch( V_33 ) {
case 1 :
V_59 -> V_69 = F_60 ( V_48 , 0 ) ;
break;
case 2 :
V_59 -> V_69 = F_61 ( V_48 , 0 ) ;
break;
case 3 :
V_59 -> V_69 = F_62 ( V_48 , 0 ) ;
break;
case 4 :
V_59 -> V_69 = F_63 ( V_48 , 0 ) ;
break;
default:
V_59 -> V_69 = 0 ;
break;
}
V_53 -> V_69 = V_59 -> V_69 ;
if ( V_33 ) {
F_64 ( T_9 -> V_37 -> V_61 , V_62 , L_10 ) ;
for( V_49 = 0 ; V_49 < V_33 ; V_49 ++ ) {
F_65 ( T_9 -> V_37 -> V_61 , V_62 , L_6 , F_60 ( V_48 , V_49 ) ) ;
}
F_64 ( T_9 -> V_37 -> V_61 , V_62 , L_7 ) ;
}
}
return T_7 ;
}
static int
F_69 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 242 "./asn1/tcap/tcap.cnf"
V_59 -> V_63 = V_70 ;
F_67 ( T_9 -> V_37 -> V_61 , V_62 , L_11 ) ;
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_71 , T_12 , V_72 ) ;
return T_7 ;
}
static int
F_70 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 249 "./asn1/tcap/tcap.cnf"
V_59 -> V_63 = V_73 ;
F_67 ( T_9 -> V_37 -> V_61 , V_62 , L_12 ) ;
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_74 , T_12 , V_75 ) ;
return T_7 ;
}
static int
F_71 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_72 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 10 , TRUE , F_71 ) ;
return T_7 ;
}
static int
F_73 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_76 , T_12 , V_77 ,
NULL ) ;
return T_7 ;
}
static int
F_74 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 256 "./asn1/tcap/tcap.cnf"
V_59 -> V_63 = V_78 ;
F_67 ( T_9 -> V_37 -> V_61 , V_62 , L_13 ) ;
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_79 , T_12 , V_80 ) ;
return T_7 ;
}
static int
F_75 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_81 , T_12 , V_82 ,
NULL ) ;
return T_7 ;
}
static int
F_76 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_77 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_83 , T_12 , V_84 ,
NULL ) ;
return T_7 ;
}
static int
F_78 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 116 "./asn1/tcap/tcap.cnf"
struct V_52 * V_53 = (struct V_52 * ) T_9 -> V_54 ;
T_7 = F_79 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_85 ) ;
V_53 -> V_86 = ( const void * ) V_85 ;
V_53 -> V_87 = TRUE ;
return T_7 ;
}
static int
F_80 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_81 ( T_4 , T_11 , T_6 , T_7 , T_9 , T_12 , NULL ) ;
return T_7 ;
}
static int
F_82 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_51 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_88 , T_12 , V_89 ) ;
return T_7 ;
}
static int
F_83 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_90 , T_12 , V_91 ) ;
return T_7 ;
}
static int
F_84 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 0 , TRUE , F_83 ) ;
return T_7 ;
}
int
F_85 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_92 , T_12 , V_93 ,
NULL ) ;
return T_7 ;
}
static int
F_86 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_77 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_94 , T_12 , V_95 ,
NULL ) ;
return T_7 ;
}
static int
F_87 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 122 "./asn1/tcap/tcap.cnf"
struct V_52 * V_53 = (struct V_52 * ) T_9 -> V_54 ;
T_7 = F_79 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_85 ) ;
V_53 -> V_86 = ( const void * ) V_85 ;
V_53 -> V_87 = TRUE ;
return T_7 ;
}
static int
F_88 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_51 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_96 , T_12 , V_97 ) ;
return T_7 ;
}
static int
F_89 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_98 , T_12 , V_99 ) ;
return T_7 ;
}
static int
F_90 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 0 , TRUE , F_89 ) ;
return T_7 ;
}
static int
F_91 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_77 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_100 , T_12 , V_101 ,
NULL ) ;
return T_7 ;
}
static int
F_92 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
#line 128 "./asn1/tcap/tcap.cnf"
struct V_52 * V_53 = (struct V_52 * ) T_9 -> V_54 ;
T_7 = F_79 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 , & V_85 ) ;
V_53 -> V_86 = ( const void * ) V_85 ;
V_53 -> V_87 = TRUE ;
return T_7 ;
}
static int
F_93 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_94 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_95 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_96 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_102 , T_12 , V_103 ,
NULL ) ;
return T_7 ;
}
static int
F_97 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_51 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_104 , T_12 , V_105 ) ;
return T_7 ;
}
static int
F_98 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_106 , T_12 , V_107 ) ;
return T_7 ;
}
static int
F_99 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 1 , TRUE , F_98 ) ;
return T_7 ;
}
static int
F_100 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_21 ( T_4 , T_9 , T_11 , T_6 , T_7 , T_12 ,
NULL ) ;
return T_7 ;
}
static int
F_101 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_51 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_108 , T_12 , V_109 ) ;
return T_7 ;
}
static int
F_102 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_15 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
V_110 , T_12 , V_111 ) ;
return T_7 ;
}
static int
F_103 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_17 ( T_4 , T_9 , T_11 , T_6 , T_7 ,
T_12 , V_10 , 4 , TRUE , F_102 ) ;
return T_7 ;
}
int
F_13 ( T_3 T_4 V_4 , T_5 * T_6 V_4 , int T_7 V_4 , T_8 * T_9 V_4 , T_10 * T_11 V_4 , int T_12 V_4 ) {
T_7 = F_24 ( T_9 , T_11 , T_6 , T_7 ,
V_112 , T_12 , V_113 ,
NULL ) ;
return T_7 ;
}
static int F_104 ( T_5 * T_6 V_4 , T_16 * V_37 V_4 , T_10 * T_11 V_4 , void * T_17 V_4 ) {
int T_7 = 0 ;
T_8 V_114 ;
F_105 ( & V_114 , V_115 , TRUE , V_37 ) ;
T_7 = F_85 ( FALSE , T_6 , T_7 , & V_114 , T_11 , V_116 ) ;
return T_7 ;
}
static int F_106 ( T_5 * T_6 V_4 , T_16 * V_37 V_4 , T_10 * T_11 V_4 , void * T_17 V_4 ) {
int T_7 = 0 ;
T_8 V_114 ;
F_105 ( & V_114 , V_115 , TRUE , V_37 ) ;
T_7 = F_13 ( FALSE , T_6 , T_7 , & V_114 , T_11 , V_117 ) ;
return T_7 ;
}
static void
F_107 ( T_18 V_118 , const char * V_119 , ... )
{
T_19 V_120 ;
if ( V_118 > V_121 ) return;
va_start ( V_120 , V_119 ) ;
vfprintf ( V_122 , V_119 , V_120 ) ;
va_end ( V_120 ) ;
}
static T_14
F_108 ( T_20 V_123 , T_20 V_124 )
{
const struct V_125 * V_126 = ( const struct V_125 * ) V_123 ;
const struct V_125 * V_127 = ( const struct V_125 * ) V_124 ;
return ( V_126 -> V_128 == V_127 -> V_128 ) ;
}
static T_18
F_109 ( T_20 V_129 )
{
const struct V_125 * V_130 = ( const struct V_125 * ) V_129 ;
return V_130 -> V_128 ;
}
static T_14
F_110 ( T_20 V_123 , T_20 V_124 )
{
const struct V_131 * V_126 = ( const struct V_131 * ) V_123 ;
const struct V_131 * V_127 = ( const struct V_131 * ) V_124 ;
if ( V_126 -> V_132 == V_127 -> V_132 ) {
if ( ( V_126 -> V_133 == V_127 -> V_133 ) && ( V_126 -> V_134 == V_127 -> V_134 ) )
return TRUE ;
}
return FALSE ;
}
static T_18
F_111 ( T_20 V_129 )
{
const struct V_131 * V_130 = ( const struct V_131 * ) V_129 ;
T_18 V_135 ;
V_135 = V_130 -> V_134 ;
return V_135 ;
}
static T_14
F_112 ( T_20 V_123 , T_20 V_124 )
{
const struct V_136 * V_126 = ( const struct V_136 * ) V_123 ;
const struct V_136 * V_127 = ( const struct V_136 * ) V_124 ;
if ( V_126 -> V_132 == V_127 -> V_132 ) {
if ( ( V_126 -> V_137 == V_127 -> V_137 ) &&
( V_126 -> V_138 == V_127 -> V_138 ) &&
( V_126 -> V_60 == V_127 -> V_60 ) &&
( V_126 -> V_69 == V_127 -> V_69 ) ) {
return TRUE ;
}
else if ( ( V_126 -> V_137 == V_127 -> V_138 ) &&
( V_126 -> V_138 == V_127 -> V_137 ) &&
( V_126 -> V_60 == V_127 -> V_69 ) &&
( V_126 -> V_69 == V_127 -> V_60 ) ) {
return TRUE ;
}
}
return FALSE ;
}
static T_18
F_113 ( T_20 V_129 )
{
const struct V_136 * V_130 = ( const struct V_136 * ) V_129 ;
T_18 V_135 ;
V_135 = V_130 -> V_60 + V_130 -> V_69 ;
return V_135 ;
}
static T_14
F_114 ( T_20 V_123 , T_20 V_124 )
{
const struct V_139 * V_126 = ( const struct V_139 * ) V_123 ;
const struct V_139 * V_127 = ( const struct V_139 * ) V_124 ;
if ( V_126 -> V_132 == V_127 -> V_132 ) {
if ( ( V_126 -> V_133 == V_127 -> V_133 ) && ( V_126 -> V_134 == V_127 -> V_134 ) )
return TRUE ;
}
return FALSE ;
}
static T_18
F_115 ( T_20 V_129 )
{
const struct V_139 * V_130 = ( const struct V_139 * ) V_129 ;
T_18 V_135 ;
V_135 = V_130 -> V_134 ;
return V_135 ;
}
static T_14
F_116 ( T_20 V_123 , T_20 V_124 )
{
const struct V_140 * V_126 = ( const struct V_140 * ) V_123 ;
const struct V_140 * V_127 = ( const struct V_140 * ) V_124 ;
if ( V_126 -> V_132 == V_127 -> V_132 ) {
if ( ( ( V_126 -> V_137 == V_127 -> V_137 ) &&
( V_126 -> V_138 == V_127 -> V_138 ) &&
( V_126 -> V_134 == V_127 -> V_134 ) )
||
( ( V_126 -> V_137 == V_127 -> V_138 ) &&
( V_126 -> V_138 == V_127 -> V_137 ) &&
( V_126 -> V_134 == V_127 -> V_134 ) )
)
return TRUE ;
}
return FALSE ;
}
static T_18
F_117 ( T_20 V_129 )
{
const struct V_140 * V_130 = ( const struct V_140 * ) V_129 ;
T_18 V_135 ;
V_135 = V_130 -> V_134 ;
return V_135 ;
}
static void
F_118 ( struct V_141 * V_142 ,
T_16 * V_37 )
{
V_142 -> V_143 -> V_144 = V_37 -> V_145 ;
V_142 -> V_143 -> V_146 = 0 ;
V_142 -> V_143 -> V_147 = FALSE ;
V_142 -> V_143 -> V_148 = V_37 -> V_149 ;
}
static struct V_141 *
F_119 ( struct V_141 * V_150 ,
struct V_151 * V_152 ,
T_16 * V_37 )
{
struct V_141 * V_153 = NULL ;
V_153 = F_120 ( F_121 () , struct V_141 ) ;
V_153 -> V_143 = V_152 ;
V_152 -> V_154 = V_153 ;
V_153 -> V_155 = V_150 -> V_155 ;
V_153 -> V_143 -> V_144 = V_37 -> V_145 ;
V_153 -> V_156 = NULL ;
V_153 -> V_157 = V_150 ;
V_153 -> V_158 = FALSE ;
#ifdef F_122
F_107 ( 10 , L_14 , V_153 -> V_143 -> V_128 ) ;
#endif
V_150 -> V_156 = V_153 ;
if ( V_150 -> V_143 -> V_146 == 0 ) {
#ifdef F_122
F_107 ( 10 , L_15 ) ;
#endif
V_150 -> V_143 -> V_146 = V_37 -> V_145 - 1 ;
}
return V_153 ;
}
static void
F_123 ( struct V_159 * V_160 ,
T_16 * V_37 )
{
V_160 -> V_143 -> V_144 = V_37 -> V_145 ;
V_160 -> V_143 -> V_146 = 0 ;
V_160 -> V_143 -> V_147 = FALSE ;
V_160 -> V_143 -> V_148 = V_37 -> V_149 ;
}
static struct V_159 *
F_124 ( struct V_159 * V_161 ,
struct V_151 * V_152 ,
T_16 * V_37 )
{
struct V_159 * V_162 = NULL ;
V_162 = F_120 ( F_121 () , struct V_159 ) ;
V_162 -> V_143 = V_152 ;
V_152 -> V_163 = V_162 ;
V_162 -> V_164 = V_161 -> V_164 ;
V_162 -> V_143 -> V_144 = V_37 -> V_145 ;
V_162 -> V_165 = NULL ;
V_162 -> V_166 = V_161 ;
V_162 -> V_158 = FALSE ;
#ifdef F_122
F_107 ( 10 , L_16 , V_162 -> V_143 -> V_128 ) ;
#endif
V_161 -> V_165 = V_162 ;
if ( V_161 -> V_143 -> V_146 == 0 ) {
#ifdef F_122
F_107 ( 10 , L_15 ) ;
#endif
V_161 -> V_143 -> V_146 = V_37 -> V_145 - 1 ;
}
return V_162 ;
}
static struct V_167 *
F_125 ( struct V_167 * V_168 ,
struct V_151 * V_152 )
{
struct V_167 * V_169 = NULL ;
V_169 = F_120 ( F_121 () , struct V_167 ) ;
V_169 -> V_143 = V_152 ;
V_152 -> V_170 = V_169 ;
V_169 -> V_171 = V_168 -> V_171 ;
V_169 -> V_172 = NULL ;
V_169 -> V_173 = V_168 ;
V_169 -> V_158 = FALSE ;
#ifdef F_122
F_107 ( 10 , L_17 , V_169 -> V_143 -> V_128 ) ;
#endif
V_168 -> V_172 = V_169 ;
return V_169 ;
}
static struct V_174 *
F_126 ( struct V_174 * V_175 ,
struct V_151 * V_152 )
{
struct V_174 * V_176 = NULL ;
V_176 = F_120 ( F_121 () , struct V_174 ) ;
V_176 -> V_143 = V_152 ;
V_152 -> V_177 = V_176 ;
V_176 -> V_178 = V_175 -> V_178 ;
V_176 -> V_179 = NULL ;
V_176 -> V_180 = V_175 ;
V_176 -> V_158 = FALSE ;
#ifdef F_122
F_107 ( 10 , L_18 , V_176 -> V_143 -> V_128 ) ;
#endif
V_175 -> V_179 = V_176 ;
return V_176 ;
}
static struct V_141 *
F_127 ( struct V_131 * V_181 ,
T_16 * V_37 , T_3 V_182 )
{
struct V_141 * V_142 = NULL ;
V_142 = (struct V_141 * ) F_128 ( V_183 , V_181 ) ;
if( V_142 ) {
do {
if ( V_142 -> V_143 ) {
if ( ( V_182 &&
V_37 -> V_145 == V_142 -> V_143 -> V_144 )
||
( ! V_182 &&
V_37 -> V_145 >= V_142 -> V_143 -> V_144 &&
( V_142 -> V_143 -> V_146 ? V_37 -> V_145 <= V_142 -> V_143 -> V_146 : 1 )
)
) {
#ifdef F_122
F_107 ( 10 , L_19 , V_142 -> V_143 -> V_128 ) ;
#endif
return V_142 ;
}
#ifdef F_122
F_107 ( 60 , L_20 , V_142 -> V_143 -> V_128 ) ;
#endif
}
if( V_142 -> V_156 == NULL ) {
#ifdef F_122
F_107 ( 23 , L_21 ) ;
#endif
break;
}
V_142 = V_142 -> V_156 ;
} while ( V_142 != NULL ) ;
} else {
#ifdef F_122
F_107 ( 23 , L_22 ) ;
#endif
}
return NULL ;
}
static struct V_167 *
F_129 ( struct V_136 * V_184 ,
T_16 * V_37 )
{
struct V_167 * V_185 = NULL ;
V_185 = (struct V_167 * ) F_128 ( V_186 , V_184 ) ;
if( V_185 ) {
do {
if ( V_185 -> V_143 ) {
if ( V_37 -> V_145 >= V_185 -> V_143 -> V_144 &&
( V_185 -> V_143 -> V_146 ? V_37 -> V_145 <= V_185 -> V_143 -> V_146 : 1 ) ) {
#ifdef F_122
F_107 ( 10 , L_23 , V_185 -> V_143 -> V_128 ) ;
#endif
return V_185 ;
}
#ifdef F_122
F_107 ( 60 , L_24 , V_185 -> V_143 -> V_128 ) ;
#endif
}
if( V_185 -> V_172 == NULL ) {
#ifdef F_122
F_107 ( 23 , L_25 ) ;
#endif
break;
}
V_185 = V_185 -> V_172 ;
} while ( V_185 != NULL ) ;
} else {
#ifdef F_122
F_107 ( 23 , L_26 ) ;
#endif
}
return NULL ;
}
static struct V_174 *
F_130 ( struct V_139 * V_187 ,
T_16 * V_37 , T_3 V_188 )
{
struct V_174 * V_189 = NULL ;
V_189 = (struct V_174 * ) F_128 ( V_190 , V_187 ) ;
if( V_189 ) {
do {
if ( V_189 -> V_143 ) {
if ( ( V_188 &&
( V_189 -> V_143 -> V_146 ? V_37 -> V_145 == V_189 -> V_143 -> V_146 : 1 )
)
||
( ! V_188 &&
V_37 -> V_145 >= V_189 -> V_143 -> V_144 &&
( V_189 -> V_143 -> V_146 ? V_37 -> V_145 <= V_189 -> V_143 -> V_146 : 1 )
)
) {
#ifdef F_122
F_107 ( 10 , L_27 , V_189 -> V_143 -> V_128 ) ;
#endif
return V_189 ;
}
#ifdef F_122
F_107 ( 60 , L_28 , V_189 -> V_143 -> V_128 ) ;
#endif
}
if( V_189 -> V_179 == NULL ) {
#ifdef F_122
F_107 ( 23 , L_29 ) ;
#endif
break;
}
V_189 = V_189 -> V_179 ;
} while ( V_189 != NULL ) ;
} else {
#ifdef F_122
F_107 ( 23 , L_30 ) ;
#endif
}
return NULL ;
}
static struct V_151 *
F_131 ( struct V_125 * V_191 ,
T_16 * V_37 )
{
struct V_125 * V_192 ;
struct V_151 * V_193 = NULL ;
V_192 = F_132 ( F_121 () , struct V_125 ) ;
V_192 -> V_128 = V_191 -> V_128 ;
V_193 = F_120 ( F_121 () , struct V_151 ) ;
V_193 -> V_130 = V_192 ;
V_193 -> V_128 = V_191 -> V_128 ;
V_193 -> V_144 = V_37 -> V_145 ;
#ifdef F_122
F_107 ( 10 , L_31 , V_193 -> V_128 ) ;
#endif
F_133 ( V_194 , V_192 , V_193 ) ;
return V_193 ;
}
static struct V_141 *
F_134 ( struct V_131 * V_181 ,
struct V_151 * V_152 )
{
struct V_131 * V_195 ;
struct V_141 * V_153 = NULL ;
V_195 = F_132 ( F_121 () , struct V_131 ) ;
V_195 -> V_132 = V_181 -> V_132 ;
V_195 -> V_134 = V_181 -> V_134 ;
V_195 -> V_133 = V_181 -> V_133 ;
V_153 = F_120 ( F_121 () , struct V_141 ) ;
V_153 -> V_155 = V_195 ;
V_153 -> V_143 = V_152 ;
V_152 -> V_154 = V_153 ;
V_153 -> V_158 = TRUE ;
V_153 -> V_156 = NULL ;
V_153 -> V_157 = NULL ;
#ifdef F_122
F_107 ( 10 , L_19 , V_153 -> V_143 -> V_128 ) ;
#endif
F_133 ( V_183 , V_195 , V_153 ) ;
return V_153 ;
}
static struct V_167 *
F_135 ( struct V_136 * V_184 ,
struct V_151 * V_152 )
{
struct V_136 * V_196 ;
struct V_167 * V_169 = NULL ;
V_196 = F_132 ( F_121 () , struct V_136 ) ;
V_196 -> V_132 = V_184 -> V_132 ;
V_196 -> V_60 = V_184 -> V_60 ;
V_196 -> V_69 = V_184 -> V_69 ;
V_196 -> V_137 = V_184 -> V_137 ;
V_196 -> V_138 = V_184 -> V_138 ;
V_169 = F_120 ( F_121 () , struct V_167 ) ;
V_169 -> V_171 = V_196 ;
V_169 -> V_143 = V_152 ;
V_152 -> V_170 = V_169 ;
V_169 -> V_158 = TRUE ;
V_169 -> V_172 = NULL ;
V_169 -> V_173 = NULL ;
#ifdef F_122
F_107 ( 10 , L_23 , V_169 -> V_143 -> V_128 ) ;
#endif
F_133 ( V_186 , V_196 , V_169 ) ;
return V_169 ;
}
static struct V_174 *
F_136 ( struct V_139 * V_187 ,
struct V_151 * V_152 )
{
struct V_139 * V_197 ;
struct V_174 * V_176 = NULL ;
V_197 = F_132 ( F_121 () , struct V_139 ) ;
V_197 -> V_132 = V_187 -> V_132 ;
V_197 -> V_134 = V_187 -> V_134 ;
V_197 -> V_133 = V_187 -> V_133 ;
V_176 = F_120 ( F_121 () , struct V_174 ) ;
V_176 -> V_178 = V_197 ;
V_176 -> V_143 = V_152 ;
V_152 -> V_177 = V_176 ;
V_176 -> V_158 = TRUE ;
V_176 -> V_179 = NULL ;
V_176 -> V_180 = NULL ;
#ifdef F_122
F_107 ( 10 , L_27 , V_176 -> V_143 -> V_128 ) ;
#endif
F_133 ( V_190 , V_197 , V_176 ) ;
return V_176 ;
}
static struct V_159 *
F_137 ( struct V_140 * V_198 ,
struct V_151 * V_152 )
{
struct V_140 * V_199 ;
struct V_159 * V_162 = NULL ;
V_199 = F_132 ( F_121 () , struct V_140 ) ;
V_199 -> V_132 = V_198 -> V_132 ;
V_199 -> V_134 = V_198 -> V_134 ;
V_199 -> V_137 = V_198 -> V_137 ;
V_199 -> V_138 = V_198 -> V_138 ;
V_162 = F_120 ( F_121 () , struct V_159 ) ;
V_162 -> V_164 = V_199 ;
V_162 -> V_143 = V_152 ;
V_152 -> V_163 = V_162 ;
V_162 -> V_158 = TRUE ;
V_162 -> V_165 = NULL ;
V_162 -> V_166 = NULL ;
#ifdef F_122
F_107 ( 10 , L_32 , V_162 -> V_143 -> V_128 ) ;
#endif
F_133 ( V_200 , V_199 , V_162 ) ;
return V_162 ;
}
static struct V_167 *
F_138 ( struct V_136 * V_184 ,
struct V_151 * V_152 )
{
struct V_167 * V_201 = NULL ;
struct V_167 * V_185 = NULL ;
V_201 = (struct V_167 * )
F_128 ( V_186 , V_184 ) ;
if ( V_201 ) {
do {
if ( ! V_201 -> V_172 ) {
V_185 = F_125 ( V_201 ,
V_152 ) ;
break;
}
V_201 = V_201 -> V_172 ;
} while ( V_201 != NULL );
} else {
V_185 = F_135 ( V_184 ,
V_152 ) ;
}
return V_185 ;
}
static struct V_174 *
F_139 ( struct V_139 * V_187 ,
struct V_151 * V_152 )
{
struct V_174 * V_202 = NULL ;
struct V_174 * V_189 = NULL ;
V_202 = (struct V_174 * )
F_128 ( V_190 , V_187 ) ;
if ( V_202 ) {
do {
if ( ! V_202 -> V_179 ) {
V_189 = F_126 ( V_202 ,
V_152 ) ;
break;
}
V_202 = V_202 -> V_179 ;
} while ( V_202 != NULL );
} else {
V_189 = F_136 ( V_187 ,
V_152 ) ;
}
return V_189 ;
}
static struct V_151 *
F_140 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_203 * V_204 )
{
struct V_151 * V_152 = NULL ;
struct V_125 V_205 ;
struct V_141 * V_142 , * V_153 = NULL ;
struct V_131 V_206 ;
T_21 * V_207 ;
T_21 * V_208 = NULL ;
T_10 * V_209 = NULL ;
#ifdef F_122
F_107 ( 51 , L_33 , F_141 ( F_142 () , & V_37 -> V_210 ) , V_204 -> V_60 , F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
#endif
V_206 . V_134 = V_204 -> V_60 ;
if ( V_37 -> V_210 . type == V_212 && V_37 -> V_211 . type == V_212 )
{
V_206 . V_133 = F_143 ( ( const V_213 * ) V_37 -> V_210 . T_17 ) ;
} else {
V_206 . V_133 = F_144 ( F_141 ( F_142 () , & V_37 -> V_210 ) ) ;
}
V_206 . V_132 = F_111 ( & V_206 ) ;
#ifdef F_122
F_107 ( 10 , L_34 , V_37 -> V_145 ) ;
F_107 ( 11 , L_35 , V_206 . V_132 ) ;
F_107 ( 51 , L_36 , F_141 ( F_142 () , & V_37 -> V_210 ) ) ;
F_107 ( 51 , L_37 , V_206 . V_134 ) ;
#endif
V_142 = (struct V_141 * )
F_128 ( V_183 , & V_206 ) ;
if ( V_142 ) {
do {
if ( V_37 -> V_145 == V_142 -> V_143 -> V_144 ) {
#ifdef F_122
F_107 ( 22 , L_38 ) ;
#endif
V_152 = V_142 -> V_143 ;
break;
}
if ( ! V_142 -> V_156 ) {
if ( ( V_142 -> V_143 -> V_146 != 0
&& V_37 -> V_145 > V_142 -> V_143 -> V_144
&& ( T_18 ) V_37 -> V_149 . V_214 > ( T_18 ) ( V_142 -> V_143 -> V_148 . V_214 + V_215 )
) ||
( V_142 -> V_143 -> V_146 == 0
&& V_37 -> V_145 > V_142 -> V_143 -> V_144
&& ( T_18 ) V_37 -> V_149 . V_214 > ( T_18 ) ( V_142 -> V_143 -> V_148 . V_214 + V_216 )
)
)
{
#ifdef F_122
F_107 ( 12 , L_39 , V_206 . V_132 ) ;
F_107 ( 12 , L_40 , V_37 -> V_145 , V_142 -> V_143 -> V_146 ) ;
#endif
V_205 . V_128 = V_217 ++ ;
V_152 = F_131 ( & V_205 , V_37 ) ;
V_153 = F_119 ( V_142 ,
V_152 ,
V_37 ) ;
#ifdef F_122
F_107 ( 12 , L_41 , V_206 . V_132 ) ;
#endif
F_118 ( V_153 , V_37 ) ;
} else {
if ( V_142 -> V_143 -> V_218 ) {
#ifdef F_122
F_107 ( 12 , L_42 , V_206 . V_132 ) ;
F_107 ( 12 , L_40 , V_37 -> V_145 , V_142 -> V_143 -> V_146 ) ;
#endif
V_205 . V_128 = V_217 ++ ;
V_152 = F_131 ( & V_205 , V_37 ) ;
V_153 = F_119 ( V_142 ,
V_152 ,
V_37 ) ;
#ifdef F_122
F_107 ( 12 , L_43 , V_206 . V_132 ) ;
#endif
F_118 ( V_153 , V_37 ) ;
} else {
#ifdef F_122
F_107 ( 21 , L_44 , V_142 -> V_143 -> V_144 ) ;
#endif
V_152 = V_142 -> V_143 ;
if ( V_219 && T_11 ) {
V_209 = F_58 ( T_11 , T_6 , 0 , - 1 , V_220 , & V_208 , L_45 ) ;
F_145 ( V_208 ) ;
V_207 = F_146 ( V_209 , V_221 , T_6 , 0 , 0 ,
V_152 -> V_144 ,
L_46 ,
V_152 -> V_128 , V_152 -> V_144 ) ;
F_145 ( V_207 ) ;
}
return V_152 ;
}
}
break;
}
V_142 = V_142 -> V_156 ;
} while ( V_142 != NULL );
} else {
#ifdef F_122
F_107 ( 10 , L_47 , V_206 . V_132 ) ;
#endif
V_205 . V_128 = V_217 ++ ;
V_152 = F_131 ( & V_205 , V_37 ) ;
V_142 = F_134 ( & V_206 , V_152 ) ;
#ifdef F_122
F_107 ( 11 , L_41 , V_206 . V_132 ) ;
F_107 ( 11 , L_48 , V_37 -> V_145 ) ;
#endif
F_118 ( V_142 , V_37 ) ;
}
if ( V_219 && T_11 &&
V_152 &&
V_152 -> V_128 ) {
V_209 = F_58 ( T_11 , T_6 , 0 , 0 , V_220 , & V_208 , L_45 ) ;
F_145 ( V_208 ) ;
V_207 = F_147 ( V_209 , V_222 , T_6 , 0 , 0 , V_152 -> V_128 ) ;
F_145 ( V_207 ) ;
if( V_152 -> V_146 != 0 ) {
#ifdef F_122
F_107 ( 20 , L_49 , V_152 -> V_146 ) ;
#endif
V_207 = F_146 ( V_209 , V_223 , T_6 , 0 , 0 ,
V_152 -> V_146 ,
L_50 ,
V_152 -> V_146 ) ;
F_145 ( V_207 ) ;
}
}
return V_152 ;
}
static struct V_151 *
F_148 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_203 * V_204 )
{
struct V_151 * V_152 = NULL ;
struct V_167 * V_185 ;
struct V_136 V_224 ;
struct V_131 V_206 ;
struct V_141 * V_142 ;
struct V_139 V_225 ;
T_21 * V_207 ;
T_21 * V_208 = NULL ;
T_10 * V_209 = NULL ;
T_3 V_226 = TRUE ;
#ifdef F_122
F_107 ( 51 , L_51 , F_141 ( F_142 () , & V_37 -> V_210 ) , V_204 -> V_60 , F_141 ( F_142 () , & V_37 -> V_211 ) , V_204 -> V_69 ) ;
F_107 ( 10 , L_52 , V_37 -> V_145 ) ;
#endif
V_224 . V_60 = V_204 -> V_60 ;
V_224 . V_69 = V_204 -> V_69 ;
if ( V_37 -> V_210 . type == V_212 && V_37 -> V_211 . type == V_212 )
{
V_224 . V_137 = F_143 ( ( const V_213 * ) V_37 -> V_210 . T_17 ) ;
V_224 . V_138 = F_143 ( ( const V_213 * ) V_37 -> V_211 . T_17 ) ;
} else {
V_224 . V_137 = F_144 ( F_141 ( F_142 () , & V_37 -> V_210 ) ) ;
V_224 . V_138 = F_144 ( F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
}
V_224 . V_132 = F_113 ( & V_224 ) ;
#ifdef F_122
F_107 ( 11 , L_53 , V_224 . V_132 ) ;
F_107 ( 51 , L_54 , F_141 ( F_142 () , & V_37 -> V_210 ) , F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
F_107 ( 51 , L_55 , V_224 . V_60 , V_224 . V_69 ) ;
#endif
V_185 = F_129 ( & V_224 , V_37 ) ;
if( V_185 ) {
#ifdef F_122
F_107 ( 12 , L_56 ) ;
#endif
V_152 = V_185 -> V_143 ;
} else {
#ifdef F_122
F_107 ( 12 , L_57 ) ;
#endif
V_206 . V_134 = V_204 -> V_69 ;
if ( V_37 -> V_210 . type == V_212 && V_37 -> V_211 . type == V_212 )
{
V_206 . V_133 = F_143 ( ( const V_213 * ) V_37 -> V_211 . T_17 ) ;
} else {
V_206 . V_133 = F_144 ( F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
}
V_206 . V_132 = F_111 ( & V_206 ) ;
#ifdef F_122
F_107 ( 11 , L_58 , V_206 . V_132 ) ;
F_107 ( 51 , L_36 , F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
F_107 ( 51 , L_37 , V_206 . V_134 ) ;
#endif
V_142 = F_127 ( & V_206 , V_37 , FALSE ) ;
if( ! V_142 ) {
V_227:
#ifdef F_122
F_107 ( 12 , L_59 ) ;
#endif
V_226 = FALSE ;
V_206 . V_134 = V_204 -> V_60 ;
if ( V_37 -> V_210 . type == V_212 && V_37 -> V_211 . type == V_212 )
{
V_206 . V_133 = F_143 ( ( const V_213 * ) V_37 -> V_210 . T_17 ) ;
} else {
V_206 . V_133 = F_144 ( F_141 ( F_142 () , & V_37 -> V_210 ) ) ;
}
V_206 . V_132 = F_111 ( & V_206 ) ;
#ifdef F_122
F_107 ( 11 , L_58 , V_206 . V_132 ) ;
F_107 ( 51 , L_36 , F_141 ( F_142 () , & V_37 -> V_210 ) ) ;
F_107 ( 51 , L_37 , V_206 . V_134 ) ;
#endif
V_142 = F_127 ( & V_206 , V_37 , FALSE ) ;
}
if( V_142 &&
! V_142 -> V_143 -> V_170 ) {
#ifdef F_122
F_107 ( 12 , L_60 ) ;
#endif
V_152 = V_142 -> V_143 ;
V_152 -> V_147 = TRUE ;
#ifdef F_122
F_107 ( 10 , L_61 , V_224 . V_132 ) ;
F_107 ( 11 , L_62 , V_37 -> V_145 ) ;
#endif
F_138 ( & V_224 ,
V_142 -> V_143 ) ;
V_225 . V_134 = V_226 ? V_204 -> V_69 : V_204 -> V_60 ;
if ( V_37 -> V_210 . type == V_212 && V_37 -> V_211 . type == V_212 )
{
V_225 . V_133 = F_143 ( ( const V_213 * ) ( V_226 ? V_37 -> V_211 . T_17 : V_37 -> V_210 . T_17 ) ) ;
} else {
V_225 . V_133 = F_144 ( F_141 ( F_142 () , V_226 ? & V_37 -> V_211 : & V_37 -> V_210 ) ) ;
}
V_225 . V_132 = F_115 ( & V_225 ) ;
#ifdef F_122
F_107 ( 10 , L_63 , V_225 . V_132 ) ;
F_107 ( 51 , L_36 , F_141 ( F_142 () , V_226 ? & V_37 -> V_211 : & V_37 -> V_210 ) ) ;
F_107 ( 51 , L_64 , V_225 . V_134 ) ;
F_107 ( 11 , L_48 , V_37 -> V_145 ) ;
#endif
F_139 ( & V_225 ,
V_142 -> V_143 ) ;
} else {
#ifdef F_122
F_107 ( 12 , L_65 ) ;
#endif
if ( V_226 ) {
goto V_227;
}
}
}
if ( V_219 && T_11 &&
V_152 &&
V_152 -> V_128 ) {
V_209 = F_58 ( T_11 , T_6 , 0 , - 1 , V_220 , & V_208 , L_45 ) ;
F_145 ( V_208 ) ;
V_207 = F_147 ( V_209 , V_222 , T_6 , 0 , 0 , V_152 -> V_128 ) ;
F_145 ( V_207 ) ;
}
return V_152 ;
}
static struct V_151 *
F_149 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_203 * V_204 )
{
struct V_151 * V_152 = NULL ;
struct V_139 V_225 ;
struct V_174 * V_189 = NULL ;
struct V_131 V_206 ;
struct V_141 * V_142 = NULL ;
T_21 * V_207 ;
T_22 V_228 ;
T_21 * V_208 = NULL ;
T_10 * V_209 = NULL ;
#ifdef F_122
F_107 ( 51 , L_66 , F_141 ( F_142 () , & V_37 -> V_210 ) , F_141 ( F_142 () , & V_37 -> V_211 ) , V_204 -> V_69 ) ;
F_107 ( 10 , L_67 , V_37 -> V_145 ) ;
#endif
V_225 . V_134 = V_204 -> V_69 ;
if ( V_37 -> V_210 . type == V_212 && V_37 -> V_211 . type == V_212 )
{
V_225 . V_133 = F_143 ( ( const V_213 * ) V_37 -> V_211 . T_17 ) ;
} else {
V_225 . V_133 = F_144 ( F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
}
V_225 . V_132 = F_115 ( & V_225 ) ;
#ifdef F_122
F_107 ( 11 , L_68 , V_225 . V_132 ) ;
F_107 ( 11 , L_36 , F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
F_107 ( 51 , L_64 , V_225 . V_134 ) ;
#endif
V_189 = F_130 ( & V_225 , V_37 , TRUE ) ;
if( ! V_189 ) {
#ifdef F_122
F_107 ( 12 , L_69 ) ;
#endif
V_206 . V_134 = V_204 -> V_69 ;
if ( V_37 -> V_210 . type == V_212 && V_37 -> V_211 . type == V_212 )
{
V_206 . V_133 = F_143 ( ( const V_213 * ) V_37 -> V_211 . T_17 ) ;
} else {
V_206 . V_133 = F_144 ( F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
}
V_206 . V_132 = F_111 ( & V_206 ) ;
#ifdef F_122
F_107 ( 11 , L_58 , V_206 . V_132 ) ;
F_107 ( 51 , L_36 , F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
F_107 ( 51 , L_64 , V_206 . V_134 ) ;
#endif
V_142 = F_127 ( & V_206 , V_37 , FALSE ) ;
if( ! V_142 ) {
#ifdef F_122
F_107 ( 12 , L_65 ) ;
#endif
}
}
if ( V_189 ) {
V_152 = V_189 -> V_143 ;
} else if ( V_142 ) {
V_152 = V_142 -> V_143 ;
}
if ( V_152 ) {
#ifdef F_122
F_107 ( 12 , L_70 , V_152 -> V_144 ) ;
#endif
if ( V_219 && T_11 ) {
V_209 = F_58 ( T_11 , T_6 , 0 , - 1 , V_220 , & V_208 , L_45 ) ;
F_145 ( V_208 ) ;
V_207 = F_147 ( V_209 , V_222 , T_6 , 0 , 0 , V_152 -> V_128 ) ;
F_145 ( V_207 ) ;
}
#ifdef F_122
F_107 ( 20 , L_71 , V_152 -> V_144 ) ;
#endif
if ( V_219 && V_209 ) {
V_207 = F_146 ( V_209 , V_229 , T_6 , 0 , 0 ,
V_152 -> V_144 ,
L_72 ,
V_152 -> V_144 ) ;
F_145 ( V_207 ) ;
F_150 ( & V_228 , & V_37 -> V_149 , & V_152 -> V_148 ) ;
V_207 = F_151 ( V_209 , V_230 , T_6 , 0 , 0 , & V_228 ) ;
F_145 ( V_207 ) ;
}
F_152 ( V_152 , V_37 ) ;
} else {
#ifdef F_122
F_107 ( 12 , L_73 ) ;
#endif
}
return V_152 ;
}
static struct V_151 *
F_153 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_203 * V_204 )
{
struct V_151 * V_152 = NULL ;
struct V_125 V_205 ;
struct V_159 * V_160 , * V_162 ;
struct V_140 V_231 ;
T_21 * V_207 ;
T_22 V_228 ;
T_3 V_232 = FALSE ;
T_10 * V_209 = NULL ;
T_21 * V_208 = NULL ;
V_231 . V_134 = V_204 -> V_60 ;
if ( V_37 -> V_210 . type == V_212 && V_37 -> V_211 . type == V_212 )
{
V_231 . V_137 = F_143 ( ( const V_213 * ) V_37 -> V_210 . T_17 ) ;
V_231 . V_138 = F_143 ( ( const V_213 * ) V_37 -> V_211 . T_17 ) ;
} else {
V_231 . V_137 = F_144 ( F_141 ( F_142 () , & V_37 -> V_210 ) ) ;
V_231 . V_138 = F_144 ( F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
}
V_231 . V_132 = F_117 ( & V_231 ) ;
#ifdef F_122
F_107 ( 10 , L_74 , V_37 -> V_145 ) ;
F_107 ( 11 , L_35 , V_231 . V_132 ) ;
F_107 ( 51 , L_75 , F_141 ( F_142 () , & V_37 -> V_210 ) , F_141 ( F_142 () , & V_37 -> V_211 ) ) ;
F_107 ( 51 , L_64 , V_231 . V_134 ) ;
#endif
V_160 = (struct V_159 * )
F_128 ( V_200 , & V_231 ) ;
if ( V_160 ) {
do {
if ( V_37 -> V_145 == V_160 -> V_143 -> V_144 ) {
#ifdef F_122
F_107 ( 22 , L_76 ) ;
#endif
V_232 = FALSE ;
V_152 = V_160 -> V_143 ;
break;
}
if ( V_37 -> V_145 == V_160 -> V_143 -> V_146 ) {
#ifdef F_122
F_107 ( 22 , L_77 ) ;
#endif
V_232 = TRUE ;
V_152 = V_160 -> V_143 ;
break;
}
if ( V_37 -> V_145 > V_160 -> V_143 -> V_144 &&
V_160 -> V_143 -> V_146 == 0 ) {
#ifdef F_122
F_107 ( 12 , L_41 , V_231 . V_132 ) ;
#endif
V_160 -> V_143 -> V_146 = V_37 -> V_145 ;
V_160 -> V_143 -> V_147 = TRUE ;
V_160 -> V_143 -> V_218 = TRUE ;
V_152 = V_160 -> V_143 ;
V_232 = TRUE ;
if ( V_219 && T_11 ) {
V_209 = F_58 ( T_11 , T_6 , 0 , - 1 , V_220 , & V_208 , L_45 ) ;
F_145 ( V_208 ) ;
V_207 = F_147 ( V_209 , V_222 , T_6 , 0 , 0 , V_152 -> V_128 ) ;
F_145 ( V_207 ) ;
#ifdef F_122
F_107 ( 20 , L_71 , V_152 -> V_144 ) ;
#endif
V_207 = F_146 ( V_209 , V_229 , T_6 , 0 , 0 ,
V_152 -> V_144 ,
L_72 ,
V_152 -> V_144 ) ;
F_145 ( V_207 ) ;
F_150 ( & V_228 , & V_37 -> V_149 , & V_152 -> V_148 ) ;
V_207 = F_151 ( V_209 , V_230 , T_6 , 0 , 0 , & V_228 ) ;
F_145 ( V_207 ) ;
}
break;
}
if ( ! V_160 -> V_165 ) {
if ( ( V_160 -> V_143 -> V_146 != 0
&& V_37 -> V_145 > V_160 -> V_143 -> V_144
&& ( T_18 ) V_37 -> V_149 . V_214 > ( T_18 ) ( V_160 -> V_143 -> V_148 . V_214 + V_215 )
) ||
( V_160 -> V_143 -> V_146 == 0
&& V_37 -> V_145 > V_160 -> V_143 -> V_144
&& ( T_18 ) V_37 -> V_149 . V_214 > ( T_18 ) ( V_160 -> V_143 -> V_148 . V_214 + V_216 )
)
)
{
#ifdef F_122
F_107 ( 12 , L_39 , V_231 . V_132 ) ;
F_107 ( 12 , L_40 , V_37 -> V_145 , V_160 -> V_143 -> V_146 ) ;
#endif
V_205 . V_128 = V_217 ++ ;
V_152 = F_131 ( & V_205 , V_37 ) ;
V_162 = F_124 ( V_160 ,
V_152 ,
V_37 ) ;
#ifdef F_122
F_107 ( 12 , L_41 , V_231 . V_132 ) ;
#endif
F_123 ( V_162 , V_37 ) ;
V_160 = V_162 ;
} else {
if ( V_160 -> V_143 -> V_218 ) {
#ifdef F_122
F_107 ( 12 , L_42 , V_231 . V_132 ) ;
F_107 ( 12 , L_40 , V_37 -> V_145 , V_160 -> V_143 -> V_146 ) ;
#endif
V_205 . V_128 = V_217 ++ ;
V_152 = F_131 ( & V_205 , V_37 ) ;
V_162 = F_124 ( V_160 ,
V_152 ,
V_37 ) ;
#ifdef F_122
F_107 ( 12 , L_43 , V_231 . V_132 ) ;
#endif
F_123 ( V_162 , V_37 ) ;
V_160 = V_162 ;
} else {
V_152 = V_160 -> V_143 ;
#ifdef F_122
F_107 ( 12 , L_70 , V_152 -> V_144 ) ;
#endif
if ( V_219 && T_11 ) {
V_209 = F_58 ( T_11 , T_6 , 0 , - 1 , V_220 , & V_208 , L_45 ) ;
F_145 ( V_208 ) ;
V_207 = F_147 ( V_209 , V_222 , T_6 , 0 , 0 , V_152 -> V_128 ) ;
F_145 ( V_207 ) ;
#ifdef F_122
F_107 ( 20 , L_71 , V_152 -> V_144 ) ;
#endif
V_207 = F_146 ( V_209 , V_229 , T_6 , 0 , 0 ,
V_152 -> V_144 ,
L_72 ,
V_152 -> V_144 ) ;
F_145 ( V_207 ) ;
F_150 ( & V_228 , & V_37 -> V_149 , & V_152 -> V_148 ) ;
V_207 = F_151 ( V_209 , V_230 , T_6 , 0 , 0 , & V_228 ) ;
F_145 ( V_207 ) ;
}
V_152 = V_160 -> V_143 ;
}
}
break;
}
V_160 = V_160 -> V_165 ;
} while ( V_160 != NULL );
} else {
#ifdef F_122
F_107 ( 10 , L_47 , V_231 . V_132 ) ;
#endif
V_205 . V_128 = V_217 ++ ;
V_152 = F_131 ( & V_205 , V_37 ) ;
V_160 = F_137 ( & V_231 , V_152 ) ;
#ifdef F_122
F_107 ( 11 , L_41 , V_231 . V_132 ) ;
F_107 ( 11 , L_48 , V_37 -> V_145 ) ;
#endif
F_123 ( V_160 , V_37 ) ;
}
if ( V_219 && T_11 &&
V_152 &&
V_152 -> V_128 ) {
V_209 = F_58 ( T_11 , T_6 , 0 , - 1 , V_220 , & V_208 , L_45 ) ;
F_145 ( V_208 ) ;
V_207 = F_147 ( V_209 , V_222 , T_6 , 0 , 0 , V_152 -> V_128 ) ;
F_145 ( V_207 ) ;
}
if( V_219 && V_209 &&
V_160 -> V_143 -> V_146 != 0 ) {
if ( ! V_232 ) {
#ifdef F_122
F_107 ( 20 , L_49 , V_160 -> V_143 -> V_146 ) ;
#endif
V_207 = F_146 ( V_209 , V_223 , T_6 , 0 , 0 ,
V_160 -> V_143 -> V_146 ,
L_50 ,
V_160 -> V_143 -> V_146 ) ;
F_145 ( V_207 ) ;
} else {
#ifdef F_122
F_107 ( 20 , L_71 , V_152 -> V_144 ) ;
#endif
if ( V_219 ) {
V_207 = F_146 ( V_209 , V_229 , T_6 , 0 , 0 ,
V_152 -> V_144 ,
L_72 ,
V_152 -> V_144 ) ;
F_145 ( V_207 ) ;
F_150 ( & V_228 , & V_37 -> V_149 , & V_152 -> V_148 ) ;
V_207 = F_151 ( V_209 , V_230 , T_6 , 0 , 0 , & V_228 ) ;
F_145 ( V_207 ) ;
}
}
}
return V_152 ;
}
struct V_151 *
F_154 ( T_5 * T_6 , T_16 * V_37 , T_10 * T_11 ,
struct V_203 * V_204 )
{
struct V_151 * V_233 = NULL ;
if( V_37 == NULL || V_37 -> V_145 == 0 ) {
return NULL ;
}
switch ( V_204 -> V_63 ) {
case V_64 :
#ifdef F_122
F_107 ( 1 , L_78 ) ;
#endif
V_233 = F_140 ( T_6 , V_37 , T_11 , V_204 ) ;
break;
case V_73 :
#ifdef F_122
F_107 ( 1 , L_79 ) ;
#endif
V_233 = F_148 ( T_6 , V_37 , T_11 , V_204 ) ;
break;
case V_78 :
#ifdef F_122
F_107 ( 1 , L_80 ) ;
#endif
V_233 = F_149 ( T_6 , V_37 , T_11 , V_204 ) ;
break;
case V_70 :
#ifdef F_122
F_107 ( 1 , L_81 ) ;
#endif
V_233 = F_149 ( T_6 , V_37 , T_11 , V_204 ) ;
break;
case V_234 :
case V_235 :
#ifdef F_122
F_107 ( 1 , L_82 ) ;
#endif
V_233 = F_153 ( T_6 , V_37 , T_11 , V_204 ) ;
break;
default:
#ifdef F_122
F_107 ( 1 , L_83 , V_204 -> V_63 ) ;
#endif
break;
}
#ifdef F_122
if ( V_233 )
F_107 ( 1 , L_84 , V_233 -> V_128 ) ;
#endif
return V_233 ;
}
struct V_203 *
F_155 ( void )
{
struct V_203 * V_204 ;
V_236 ++ ;
if( V_236 == V_237 ) {
V_236 = 0 ;
}
V_204 = & V_238 [ V_236 ] ;
memset ( V_204 , 0 , sizeof( struct V_203 ) ) ;
return V_204 ;
}
void
F_152 ( struct V_151 * V_152 ,
T_16 * V_37 )
{
#ifdef F_122
F_107 ( 60 , L_85 ) ;
#endif
if ( V_152 ) {
V_152 -> V_147 = TRUE ;
V_152 -> V_146 = V_37 -> V_145 ;
V_152 -> V_239 = V_37 -> V_149 ;
V_152 -> V_218 = TRUE ;
if ( V_152 -> V_177
&& ! V_240 ) {
if ( V_152 -> V_177 -> V_179 ) {
if ( V_152 -> V_177 -> V_180 ) {
#ifdef F_122
F_107 ( 20 , L_86 ) ;
#endif
V_152 -> V_177 -> V_180 -> V_179
= V_152 -> V_177 -> V_179 ;
V_152 -> V_177 -> V_179 -> V_180
= V_152 -> V_177 -> V_180 ;
F_156 ( V_190 , V_152 -> V_177 -> V_178 ) ;
} else {
#ifdef F_122
F_107 ( 20 , L_87 ) ;
#endif
}
} else if ( ! V_240 ) {
#ifdef F_122
F_107 ( 20 , L_88 ) ;
#endif
F_156 ( V_190 , V_152 -> V_177 -> V_178 ) ;
}
}
if ( V_152 -> V_170
&& ! V_240 ) {
if ( V_152 -> V_170 -> V_172 ) {
if ( V_152 -> V_170 -> V_173 ) {
#ifdef F_122
F_107 ( 20 , L_89 ) ;
#endif
V_152 -> V_170 -> V_173 -> V_172
= V_152 -> V_170 -> V_172 ;
V_152 -> V_170 -> V_172 -> V_173
= V_152 -> V_170 -> V_173 ;
F_156 ( V_186 , V_152 -> V_170 -> V_171 ) ;
} else {
#ifdef F_122
F_107 ( 20 , L_90 ) ;
#endif
}
} else if ( ! V_240 ) {
#ifdef F_122
F_107 ( 20 , L_91 ) ;
#endif
F_156 ( V_186 , V_152 -> V_170 -> V_171 ) ;
}
}
if ( V_152 -> V_154
&& ! V_240 ) {
if ( V_152 -> V_154 -> V_156 ) {
if ( V_152 -> V_154 -> V_157 ) {
#ifdef F_122
F_107 ( 20 , L_92 ) ;
#endif
V_152 -> V_154 -> V_157 -> V_156
= V_152 -> V_154 -> V_156 ;
V_152 -> V_154 -> V_156 -> V_157
= V_152 -> V_154 -> V_157 ;
F_156 ( V_183 , V_152 -> V_154 -> V_155 ) ;
} else {
#ifdef F_122
F_107 ( 20 , L_93 ) ;
#endif
}
} else if ( ! V_240 ) {
#ifdef F_122
F_107 ( 20 , L_94 ) ;
#endif
F_156 ( V_183 , V_152 -> V_154 -> V_155 ) ;
}
}
if ( V_152 -> V_163
&& ! V_240 ) {
if ( V_152 -> V_163 -> V_165 ) {
if ( V_152 -> V_163 -> V_166 ) {
#ifdef F_122
F_107 ( 20 , L_95 ) ;
#endif
V_152 -> V_163 -> V_166 -> V_165
= V_152 -> V_163 -> V_165 ;
V_152 -> V_163 -> V_165 -> V_166
= V_152 -> V_163 -> V_166 ;
F_156 ( V_200 , V_152 -> V_163 -> V_164 ) ;
} else {
#ifdef F_122
F_107 ( 20 , L_96 ) ;
#endif
}
} else if ( ! V_240 ) {
#ifdef F_122
F_107 ( 20 , L_97 ) ;
#endif
F_156 ( V_200 , V_152 -> V_163 -> V_164 ) ;
}
}
if ( ! V_240 ) {
#ifdef F_122
F_107 ( 20 , L_98 ) ;
#endif
F_156 ( V_194 , V_152 -> V_130 ) ;
}
} else {
#ifdef F_122
F_107 ( 20 , L_99 ) ;
#endif
}
}
static int
F_157 ( T_5 * T_6 , T_16 * V_37 , T_10 * V_241 , void * T_17 V_4 )
{
T_21 * V_242 = NULL ;
T_10 * T_11 = NULL ;
struct V_151 * V_243 ;
T_2 V_244 ;
T_8 V_114 ;
T_13 V_30 ;
T_3 V_31 ;
T_14 V_32 ;
struct V_52 * V_53 ;
F_158 ( T_6 , 0 , & V_30 , & V_31 , & V_32 ) ;
if( V_30 == V_245 ) {
switch ( V_32 ) {
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
case 6 :
case 22 :
return F_159 ( V_246 , T_6 , V_37 , V_241 ) ;
default:
return F_160 ( T_6 ) ;
}
}
F_105 ( & V_114 , V_115 , TRUE , V_37 ) ;
V_43 = V_241 ;
V_247 = NULL ;
F_67 ( V_37 -> V_61 , V_248 , L_100 ) ;
if( V_241 ) {
V_242 = F_161 ( V_241 , V_249 , T_6 , 0 , - 1 , V_250 ) ;
T_11 = F_162 ( V_242 , V_251 ) ;
V_247 = T_11 ;
}
V_85 = NULL ;
V_252 = NULL ;
V_53 = F_120 ( F_142 () , struct V_52 ) ;
V_114 . V_54 = V_53 ;
V_59 = F_155 () ;
V_253 = FALSE ;
V_254 = NULL ;
F_75 ( FALSE , T_6 , 0 , & V_114 , T_11 , - 1 ) ;
if ( V_255 && ! V_253 ) {
V_243 = F_154 ( T_6 , V_37 , V_247 , V_59 ) ;
V_53 -> V_143 = V_243 ;
if ( V_243 && V_85 && ! V_243 -> V_256 ) {
F_163 ( V_243 -> V_86 , V_85 , sizeof( V_243 -> V_86 ) ) ;
V_243 -> V_256 = TRUE ;
if ( ( V_244 = F_164 ( V_257 , V_85 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
}
}
if ( V_255 && V_243 && V_243 -> V_259 ) {
( V_243 -> V_259 ) ( T_6 , V_37 , V_247 , V_243 ) ;
}
}
return F_160 ( T_6 ) ;
}
void
F_165 ( void )
{
V_260 = F_166 ( L_101 ) ;
V_246 = F_167 ( L_102 , V_249 ) ;
V_257 = F_168 ( L_103 ) ;
V_212 = F_169 ( L_104 ) ;
#line 1 "./asn1/tcap/packet-tcap-dis-tab.c"
F_170 ( L_105 , F_106 , V_249 , L_106 ) ;
F_170 ( L_107 , F_104 , V_249 , L_108 ) ;
#line 1926 "./asn1/tcap/packet-tcap-template.c"
}
void
F_171 ( void )
{
static T_23 V_261 [] = {
{ & V_262 ,
{ L_109 ,
L_110 ,
V_263 , V_264 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_266 ,
{ L_111 ,
L_112 ,
V_263 , V_267 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_268 ,
{ L_113 ,
L_114 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_55 ,
{ L_115 ,
L_116 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_271 ,
{ L_117 ,
L_118 ,
V_272 , V_264 , NULL , 0 ,
NULL , V_265 }
} ,
{ & V_222 ,
{ L_119 ,
L_120 ,
V_273 , V_267 , NULL , 0x0 ,
NULL , V_265 }
} ,
{ & V_223 ,
{ L_121 ,
L_122 ,
V_274 , V_270 , NULL , 0x0 ,
L_123 , V_265 }
} ,
{ & V_229 ,
{ L_124 ,
L_125 ,
V_274 , V_270 , NULL , 0x0 ,
L_126 , V_265 }
} ,
{ & V_230 ,
{ L_127 ,
L_128 ,
V_275 , V_270 , NULL , 0x0 ,
L_129 , V_265 }
} ,
{ & V_221 ,
{ L_130 ,
L_131 ,
V_274 , V_270 , NULL , 0x0 ,
L_132 , V_265 }
} ,
#line 1 "./asn1/tcap/packet-tcap-hfarr.c"
{ & V_116 ,
{ L_133 , L_134 ,
V_273 , V_267 , F_172 ( V_276 ) , 0 ,
NULL , V_265 } } ,
{ & V_117 ,
{ L_135 , L_136 ,
V_273 , V_267 , F_172 ( V_277 ) , 0 ,
NULL , V_265 } } ,
{ & V_278 ,
{ L_137 , L_138 ,
V_279 , V_270 , NULL , 0 ,
L_139 , V_265 } } ,
{ & V_280 ,
{ L_140 , L_141 ,
V_269 , V_270 , NULL , 0 ,
L_142 , V_265 } } ,
{ & V_281 ,
{ L_143 , L_144 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_283 ,
{ L_145 , L_146 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_284 ,
{ L_147 , L_148 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_285 ,
{ L_149 , L_150 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_286 ,
{ L_151 , L_152 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_287 ,
{ L_153 , L_154 ,
V_269 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_288 ,
{ L_155 , L_156 ,
V_273 , V_267 , NULL , 0 ,
L_157 , V_265 } } ,
{ & V_58 ,
{ L_158 , L_159 ,
V_269 , V_270 , NULL , 0 ,
L_160 , V_265 } } ,
{ & V_68 ,
{ L_161 , L_162 ,
V_269 , V_270 , NULL , 0 ,
L_163 , V_265 } } ,
{ & V_289 ,
{ L_164 , L_165 ,
V_273 , V_267 , F_172 ( V_290 ) , 0 ,
NULL , V_265 } } ,
{ & V_291 ,
{ L_166 , L_167 ,
V_273 , V_267 , F_172 ( V_292 ) , 0 ,
NULL , V_265 } } ,
{ & V_293 ,
{ L_168 , L_169 ,
V_269 , V_270 , NULL , 0 ,
L_170 , V_265 } } ,
{ & V_294 ,
{ L_171 , L_172 ,
V_273 , V_267 , F_172 ( V_295 ) , 0 ,
NULL , V_265 } } ,
{ & V_296 ,
{ L_173 , L_174 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_297 ,
{ L_175 , L_176 ,
V_282 , V_270 , NULL , 0 ,
L_177 , V_265 } } ,
{ & V_298 ,
{ L_178 , L_179 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_299 ,
{ L_180 , L_181 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_300 ,
{ L_182 , L_183 ,
V_282 , V_270 , NULL , 0 ,
L_177 , V_265 } } ,
{ & V_301 ,
{ L_184 , L_185 ,
V_302 , V_267 , NULL , 0 ,
L_186 , V_265 } } ,
{ & V_303 ,
{ L_187 , L_188 ,
V_302 , V_267 , NULL , 0 ,
L_186 , V_265 } } ,
{ & V_304 ,
{ L_189 , L_190 ,
V_273 , V_267 , F_172 ( V_305 ) , 0 ,
L_191 , V_265 } } ,
{ & V_306 ,
{ L_192 , L_193 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_307 ,
{ L_194 , L_195 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_308 ,
{ L_196 , L_197 ,
V_273 , V_267 , F_172 ( V_309 ) , 0 ,
NULL , V_265 } } ,
{ & V_310 ,
{ L_198 , L_199 ,
V_273 , V_267 , F_172 ( V_311 ) , 0 ,
NULL , V_265 } } ,
{ & V_312 ,
{ L_200 , L_201 ,
V_302 , V_267 , NULL , 0 ,
L_186 , V_265 } } ,
{ & V_313 ,
{ L_202 , L_203 ,
V_282 , V_270 , NULL , 0 ,
NULL , V_265 } } ,
{ & V_314 ,
{ L_204 , L_205 ,
V_273 , V_267 , F_172 ( V_315 ) , 0 ,
NULL , V_265 } } ,
{ & V_316 ,
{ L_206 , L_207 ,
V_302 , V_267 , F_172 ( V_317 ) , 0 ,
NULL , V_265 } } ,
{ & V_318 ,
{ L_208 , L_209 ,
V_302 , V_267 , F_172 ( V_319 ) , 0 ,
NULL , V_265 } } ,
{ & V_320 ,
{ L_210 , L_211 ,
V_302 , V_267 , F_172 ( V_321 ) , 0 ,
NULL , V_265 } } ,
{ & V_322 ,
{ L_212 , L_213 ,
V_302 , V_267 , F_172 ( V_323 ) , 0 ,
NULL , V_265 } } ,
{ & V_324 ,
{ L_214 , L_215 ,
V_302 , V_267 , NULL , 0 ,
L_216 , V_265 } } ,
{ & V_325 ,
{ L_217 , L_218 ,
V_279 , V_270 , NULL , 0 ,
L_139 , V_265 } } ,
{ & V_326 ,
{ L_219 , L_220 ,
V_302 , V_267 , NULL , 0 ,
L_221 , V_265 } } ,
{ & V_327 ,
{ L_222 , L_223 ,
V_302 , V_267 , NULL , 0 ,
L_216 , V_265 } } ,
{ & V_328 ,
{ L_224 , L_225 ,
V_282 , V_270 , NULL , 0 ,
L_226 , V_265 } } ,
{ & V_329 ,
{ L_227 , L_228 ,
V_269 , V_270 , NULL , 0 ,
L_229 , V_265 } } ,
{ & V_330 ,
{ L_230 , L_231 ,
V_279 , V_270 , NULL , 0 ,
L_232 , V_265 } } ,
{ & V_331 ,
{ L_233 , L_234 ,
V_273 , V_267 , NULL , 0 ,
L_235 , V_265 } } ,
{ & V_332 ,
{ L_236 , L_237 ,
V_282 , V_270 , NULL , 0 ,
L_238 , V_265 } } ,
{ & V_333 ,
{ L_239 , L_240 ,
V_282 , V_270 , NULL , 0 ,
L_241 , V_265 } } ,
{ & V_334 ,
{ L_242 , L_243 ,
V_282 , V_270 , NULL , 0 ,
L_244 , V_265 } } ,
{ & V_335 ,
{ L_245 , L_246 ,
V_282 , V_270 , NULL , 0 ,
L_247 , V_265 } } ,
{ & V_336 ,
{ L_227 , L_228 ,
V_269 , V_270 , NULL , 0 ,
L_248 , V_265 } } ,
{ & V_337 ,
{ L_230 , L_231 ,
V_279 , V_270 , NULL , 0 ,
L_249 , V_265 } } ,
{ & V_338 ,
{ L_233 , L_234 ,
V_273 , V_267 , NULL , 0 ,
L_250 , V_265 } } ,
{ & V_339 ,
{ L_236 , L_237 ,
V_282 , V_270 , NULL , 0 ,
L_238 , V_265 } } ,
{ & V_340 ,
{ L_227 , L_228 ,
V_269 , V_270 , NULL , 0 ,
L_251 , V_265 } } ,
{ & V_341 ,
{ L_230 , L_231 ,
V_279 , V_270 , NULL , 0 ,
L_252 , V_265 } } ,
{ & V_342 ,
{ L_253 , L_254 ,
V_302 , V_267 , F_172 ( V_343 ) , 0 ,
L_255 , V_265 } } ,
{ & V_344 ,
{ L_256 , L_257 ,
V_273 , V_267 , F_172 ( V_345 ) , 0 ,
L_258 , V_265 } } ,
{ & V_346 ,
{ L_233 , L_234 ,
V_273 , V_267 , NULL , 0 ,
L_259 , V_265 } } ,
{ & V_347 ,
{ L_236 , L_237 ,
V_282 , V_270 , NULL , 0 ,
L_238 , V_265 } } ,
{ & V_348 ,
{ L_260 , L_261 ,
V_302 , V_267 , F_172 ( V_349 ) , 0 ,
L_262 , V_265 } } ,
{ & V_350 ,
{ L_233 , L_234 ,
V_273 , V_267 , NULL , 0 ,
L_263 , V_265 } } ,
{ & V_351 ,
{ L_236 , L_237 ,
V_282 , V_270 , NULL , 0 ,
L_238 , V_265 } } ,
{ & V_352 ,
{ L_264 , L_265 ,
V_302 , V_267 , F_172 ( V_353 ) , 0 ,
NULL , V_265 } } ,
{ & V_354 ,
{ L_266 , L_267 ,
V_302 , V_267 , F_172 ( V_355 ) , 0 ,
NULL , V_265 } } ,
{ & V_356 ,
{ L_268 , L_269 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
{ & V_358 ,
{ L_268 , L_269 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
{ & V_359 ,
{ L_268 , L_269 ,
V_357 , 8 , NULL , 0x80 ,
NULL , V_265 } } ,
#line 1999 "./asn1/tcap/packet-tcap-template.c"
} ;
static T_14 * V_360 [] = {
& V_251 ,
& V_361 ,
& V_57 ,
& V_67 ,
& V_220 ,
#line 1 "./asn1/tcap/packet-tcap-ettarr.c"
& V_8 ,
& V_82 ,
& V_47 ,
& V_66 ,
& V_72 ,
& V_75 ,
& V_80 ,
& V_77 ,
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
& V_93 ,
& V_91 ,
& V_84 ,
& V_89 ,
& V_113 ,
& V_99 ,
& V_95 ,
& V_97 ,
& V_107 ,
& V_101 ,
& V_105 ,
& V_111 ,
& V_109 ,
& V_103 ,
#line 2009 "./asn1/tcap/packet-tcap-template.c"
} ;
T_24 * V_362 ;
V_249 = F_173 ( V_363 , V_364 , V_365 ) ;
F_174 ( V_249 , V_261 , F_175 ( V_261 ) ) ;
F_176 ( V_360 , F_175 ( V_360 ) ) ;
V_5 = F_177 ( L_1 , L_270 , V_249 , V_263 , V_267 ) ;
V_6 = F_177 ( L_3 , L_271 , V_249 , V_263 , V_267 ) ;
V_362 = F_178 ( V_249 , NULL ) ;
#if 0
prefs_register_enum_preference(tcap_module, "standard", "ITU TCAP standard",
"The SS7 standard used in ITU TCAP packets",
&tcap_standard, tcap_options, FALSE);
#else
F_179 ( V_362 , L_272 ) ;
#endif
#if 0
prefs_register_bool_preference(tcap_module, "lock_info_col", "Lock Info column",
"Always show TCAP in Info column",
&lock_info_col);
#else
F_179 ( V_362 , L_273 ) ;
#endif
F_180 ( F_181 () , & V_366 , L_274 , V_367 ) ;
F_182 ( V_362 , L_275 , L_276 ,
L_277 ,
& V_366 , V_367 ) ;
F_183 ( V_362 , L_278 ,
L_279 ,
L_280 ,
& V_255 ) ;
F_183 ( V_362 , L_281 ,
L_282 ,
L_283 ,
& V_240 ) ;
F_184 ( V_362 , L_284 ,
L_285 ,
L_286 ,
10 , & V_215 ) ;
F_184 ( V_362 , L_287 ,
L_288 ,
L_289 ,
10 , & V_216 ) ;
F_185 ( L_290 , F_157 , V_249 ) ;
V_3 = F_186 ( F_157 , V_249 ) ;
V_194 = F_187 ( F_181 () , F_121 () , F_109 , F_108 ) ;
V_183 = F_187 ( F_181 () , F_121 () , F_111 , F_110 ) ;
V_186 = F_187 ( F_181 () , F_121 () , F_113 , F_112 ) ;
V_190 = F_187 ( F_181 () , F_121 () , F_115 , F_114 ) ;
V_200 = F_187 ( F_181 () , F_121 () , F_117 , F_116 ) ;
F_188 ( & V_368 ) ;
F_189 ( & V_369 ) ;
}
static void F_190 ( T_1 V_1 )
{
if ( V_1 && ! F_8 ( V_1 ) && ! F_6 ( V_1 ) ) {
F_5 ( L_2 , V_1 , V_3 ) ;
}
}
static void F_191 ( T_1 V_1 )
{
if ( V_1 && ! F_8 ( V_1 ) && ! F_6 ( V_1 ) ) {
F_2 ( L_2 , V_1 , V_3 ) ;
}
}
static void V_368 ( void )
{
V_370 = F_192 ( F_181 () , V_366 ) ;
F_193 ( V_370 , F_191 ) ;
V_217 = 1 ;
V_219 = V_240 || V_255 & V_371 ;
}
static void V_369 ( void )
{
F_193 ( V_370 , F_190 ) ;
F_194 ( F_181 () , V_370 ) ;
}
static int
F_26 ( T_8 * T_9 , T_10 * T_11 , T_5 * T_6 , int T_7 )
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
while ( F_59 ( T_6 , T_7 ) > 0 )
{
V_51 = T_7 ;
T_7 = F_158 ( T_6 , T_7 , & V_30 , & V_31 , & V_32 ) ;
V_372 = T_7 ;
T_7 = F_195 ( T_6 , T_7 , & V_33 , & V_36 ) ;
V_373 = T_7 ;
V_374 = V_372 - V_51 ;
V_375 = V_373 - V_372 ;
if ( V_31 )
{
V_50 = F_58 ( T_11 , T_6 , V_51 ,
V_33 + ( V_373 - V_51 ) , V_361 , NULL ,
L_291 ) ;
F_146 ( V_50 , V_262 , T_6 ,
V_51 , V_374 , V_32 ,
L_292 ) ;
F_147 ( V_50 , V_262 , T_6 , V_51 ,
V_374 , V_30 ) ;
F_147 ( V_50 , V_266 , T_6 , V_372 ,
V_375 , V_33 ) ;
if ( V_33 - ( 2 * V_36 ) )
{
V_29 = F_45 ( T_6 , T_7 , V_33 - ( 2 * V_36 ) ) ;
F_26 ( T_9 , V_50 , V_29 , 0 ) ;
}
if ( V_36 )
F_161 ( V_50 , V_271 , T_6 , T_7 + V_33 - 2 , 2 , V_376 ) ;
T_7 += V_33 ;
}
else
{
V_50 = F_196 ( T_11 , T_6 , V_51 ,
V_33 + ( V_373 - V_51 ) , V_361 , NULL ,
L_293 , V_32 ) ;
F_147 ( V_50 , V_262 , T_6 , V_51 ,
V_374 , V_32 ) ;
F_147 ( V_50 , V_266 , T_6 ,
V_51 + V_374 , V_375 , V_33 ) ;
if ( V_33 )
{
V_29 = F_45 ( T_6 , T_7 , V_33 ) ;
F_55 ( TRUE , T_9 , T_11 , V_29 , 0 ,
V_268 , NULL ) ;
}
T_7 += V_33 ;
}
}
return T_7 ;
}
static int
F_49 ( T_3 T_4 V_4 , T_5 * T_6 , int T_7 , T_8 * T_9 , T_10 * T_11 , int T_12 V_4 )
{
T_2 V_244 = NULL ;
T_3 V_377 = FALSE ;
struct V_151 * V_243 = NULL ;
struct V_52 * V_53 = (struct V_52 * ) T_9 -> V_54 ;
if ( V_255 ) {
if ( ! V_253 ) {
V_243 = F_154 ( T_6 , T_9 -> V_37 , V_247 , V_59 ) ;
V_253 = TRUE ;
V_254 = V_243 ;
V_53 -> V_143 = V_243 ;
} else {
V_243 = V_254 ;
V_53 -> V_143 = V_243 ;
}
}
if ( V_243 ) {
if ( V_85 ) {
if ( V_243 -> V_256 ) {
if ( strncmp ( V_243 -> V_86 , V_85 , sizeof( V_243 -> V_86 ) ) != 0 ) {
F_163 ( V_243 -> V_86 , V_85 , sizeof( V_243 -> V_86 ) ) ;
if ( ( V_244 = F_164 ( V_257 , V_85 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
}
}
} else {
F_163 ( V_243 -> V_86 , V_85 , sizeof( V_243 -> V_86 ) ) ;
V_243 -> V_256 = TRUE ;
if ( ( V_244
= F_164 ( V_257 , V_85 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
} else {
if ( ( V_244 = F_6 ( T_9 -> V_37 -> V_378 ) ) ) {
V_243 -> V_244 = V_244 ;
V_243 -> V_258 = TRUE ;
}
}
}
} else {
if ( V_243 -> V_256 ) {
V_53 -> V_86 = ( void * ) V_243 -> V_86 ;
V_53 -> V_87 = TRUE ;
}
}
}
if ( V_243
&& V_243 -> V_258 ) {
V_244 = V_243 -> V_244 ;
V_377 = TRUE ;
}
if ( ! V_377 && V_379 ) {
V_377 = TRUE ;
V_244 = V_379 ;
}
if ( ! V_377 ) {
if ( V_257 && V_85 ) {
if ( ( V_244
= F_164 ( V_257 , V_85 ) ) ) {
V_377 = TRUE ;
} else {
if ( ( V_244
= F_6 ( T_9 -> V_37 -> V_378 ) ) ) {
V_377 = TRUE ;
} else {
V_244 = V_260 ;
V_377 = TRUE ;
}
}
} else {
if ( ( V_244 = F_6 ( T_9 -> V_37 -> V_378 ) ) ) {
V_377 = TRUE ;
} else {
V_244 = V_260 ;
V_377 = TRUE ;
}
}
} else {
}
if ( V_377 ) {
F_197 ( V_244 , T_6 , T_9 -> V_37 , T_11 , T_9 -> V_54 ) ;
F_198 ( T_9 -> V_37 -> V_61 , V_62 ) ;
}
return T_7 ;
}
void
F_199 ( T_2 V_380 , T_5 * T_6 , T_16 * V_37 , T_10 * T_11 )
{
V_379 = V_380 ;
F_46 {
F_157 ( T_6 , V_37 , T_11 , NULL ) ;
} F_200 {
V_379 = NULL ;
V_381 ;
} V_42 ;
V_379 = NULL ;
}
