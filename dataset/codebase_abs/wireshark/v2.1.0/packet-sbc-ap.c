static int
F_1 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
3 , NULL , FALSE , 0 , NULL ) ;
return T_3 ;
}
static int
F_3 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 255U , & V_2 , FALSE ) ;
#line 62 "./asn1/sbc-ap/sbc-ap.cnf"
F_5 ( T_5 -> V_3 -> V_4 , V_5 , L_1 ,
F_6 ( V_2 , V_6 ,
L_2 ) ) ;
return T_3 ;
}
static int
F_7 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 65535U , & V_7 , FALSE ) ;
return T_3 ;
}
static int
F_8 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 65535U , & V_8 , FALSE ) ;
#line 45 "./asn1/sbc-ap/sbc-ap.cnf"
if ( T_7 ) {
F_9 ( F_10 ( T_5 -> V_9 , 2 ) , L_3 , F_6 ( V_8 , F_11 ( V_10 ) , L_4 ) ) ;
}
return T_3 ;
}
static int
F_12 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
4 , NULL , FALSE , 0 , NULL ) ;
return T_3 ;
}
static int
F_13 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_14 ( T_2 , T_3 , T_5 , T_7 , T_8 , V_11 ) ;
return T_3 ;
}
static int
F_15 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_12 , V_13 ) ;
return T_3 ;
}
static int
F_17 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_14 , V_15 ,
0 , V_16 , FALSE ) ;
return T_3 ;
}
static int
F_19 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_14 ( T_2 , T_3 , T_5 , T_7 , T_8 , V_17 ) ;
return T_3 ;
}
static int
F_20 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_18 , V_19 ) ;
return T_3 ;
}
static int
F_21 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_20 , V_21 ,
1 , V_22 , FALSE ) ;
return T_3 ;
}
static int
F_22 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 255U , NULL , FALSE ) ;
return T_3 ;
}
static int
F_23 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_24 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
28 , 28 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_25 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
1 , NULL , FALSE , 0 , NULL ) ;
return T_3 ;
}
static int
F_26 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_2 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
2 , NULL , TRUE , 0 , NULL ) ;
return T_3 ;
}
static int
F_27 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_23 , V_24 ) ;
return T_3 ;
}
static int
F_28 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_25 , V_26 ,
1 , V_27 , FALSE ) ;
return T_3 ;
}
static int
F_29 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_28 , V_29 ) ;
return T_3 ;
}
static int
F_30 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_24 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
8 , 8 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_31 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
#line 99 "./asn1/sbc-ap/sbc-ap.cnf"
T_1 * V_30 = NULL ;
T_3 = F_32 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
3 , 3 , FALSE , & V_30 ) ;
if( F_33 ( T_2 ) == 0 )
return T_3 ;
if ( ! V_30 )
return T_3 ;
F_34 ( V_30 , T_5 -> V_3 , T_7 , 0 , V_31 , FALSE ) ;
return T_3 ;
}
static int
F_35 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_32 , V_33 ) ;
return T_3 ;
}
static int
F_36 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_34 , V_35 ,
1 , V_36 , FALSE ) ;
return T_3 ;
}
static int
F_37 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_32 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
3 , 3 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_38 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_37 , V_38 ,
1 , V_39 , FALSE ) ;
return T_3 ;
}
static int
F_39 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
4096U , 131071U , NULL , FALSE ) ;
return T_3 ;
}
static int
F_40 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_32 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
2 , 2 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_41 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_40 , V_41 ) ;
return T_3 ;
}
static int
F_42 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_42 , V_43 ) ;
return T_3 ;
}
static int
F_43 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_44 , V_45 ,
1 , V_46 , FALSE ) ;
return T_3 ;
}
static int
F_44 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_24 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
16 , 16 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_45 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 65535U , NULL , FALSE ) ;
return T_3 ;
}
static int
F_46 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_32 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
1 , 20 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_47 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_4 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
0U , 4096U , NULL , FALSE ) ;
return T_3 ;
}
static int
F_48 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_24 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
16 , 16 , FALSE , NULL , NULL ) ;
return T_3 ;
}
static int
F_49 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_18 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_47 , V_48 ,
1 , V_49 , FALSE ) ;
return T_3 ;
}
static int
F_50 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_51 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_50 , V_51 ,
NULL ) ;
return T_3 ;
}
static int
F_52 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_32 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
1 , 9600 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_53 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_32 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
50 , 50 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_54 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_32 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
2 , 2 , FALSE , NULL ) ;
return T_3 ;
}
static int
F_55 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_52 , V_53 ) ;
return T_3 ;
}
static int
F_56 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_54 , V_55 ) ;
return T_3 ;
}
static int
F_57 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_56 , V_57 ) ;
return T_3 ;
}
static int
F_58 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_58 , V_59 ) ;
return T_3 ;
}
static int
F_59 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_14 ( T_2 , T_3 , T_5 , T_7 , T_8 , V_60 ) ;
return T_3 ;
}
static int
F_60 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_61 , V_62 ) ;
return T_3 ;
}
static int
F_61 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_14 ( T_2 , T_3 , T_5 , T_7 , T_8 , V_63 ) ;
return T_3 ;
}
static int
F_62 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_64 , V_65 ) ;
return T_3 ;
}
static int
F_63 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_14 ( T_2 , T_3 , T_5 , T_7 , T_8 , V_66 ) ;
return T_3 ;
}
static int
F_64 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_16 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_67 , V_68 ) ;
return T_3 ;
}
static int
F_65 ( T_1 * T_2 V_1 , int T_3 V_1 , T_4 * T_5 V_1 , T_6 * T_7 V_1 , int T_8 V_1 ) {
T_3 = F_51 ( T_2 , T_3 , T_5 , T_7 , T_8 ,
V_69 , V_70 ,
NULL ) ;
return T_3 ;
}
static int F_66 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_22 ( T_2 , T_3 , & V_71 , T_7 , V_73 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_68 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_25 ( T_2 , T_3 , & V_71 , T_7 , V_74 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_69 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_29 ( T_2 , T_3 , & V_71 , T_7 , V_75 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_70 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_30 ( T_2 , T_3 , & V_71 , T_7 , V_76 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_71 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_39 ( T_2 , T_3 , & V_71 , T_7 , V_77 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_72 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_43 ( T_2 , T_3 , & V_71 , T_7 , V_78 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_73 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_44 ( T_2 , T_3 , & V_71 , T_7 , V_79 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_74 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_45 ( T_2 , T_3 , & V_71 , T_7 , V_80 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_75 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_46 ( T_2 , T_3 , & V_71 , T_7 , V_81 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_76 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_47 ( T_2 , T_3 , & V_71 , T_7 , V_82 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_77 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_48 ( T_2 , T_3 , & V_71 , T_7 , V_83 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_78 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_50 ( T_2 , T_3 , & V_71 , T_7 , V_84 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_79 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_52 ( T_2 , T_3 , & V_71 , T_7 , V_85 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_80 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_53 ( T_2 , T_3 , & V_71 , T_7 , V_86 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_81 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_54 ( T_2 , T_3 , & V_71 , T_7 , V_87 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_82 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_55 ( T_2 , T_3 , & V_71 , T_7 , V_88 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_83 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_56 ( T_2 , T_3 , & V_71 , T_7 , V_89 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_84 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_57 ( T_2 , T_3 , & V_71 , T_7 , V_90 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_85 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_58 ( T_2 , T_3 , & V_71 , T_7 , V_91 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int F_86 ( T_1 * T_2 V_1 , T_9 * V_3 V_1 , T_6 * T_7 V_1 , void * T_10 V_1 ) {
int T_3 = 0 ;
T_4 V_71 ;
F_67 ( & V_71 , V_72 , TRUE , V_3 ) ;
T_3 = F_65 ( T_2 , T_3 , & V_71 , T_7 , V_92 ) ;
T_3 += 7 ; T_3 >>= 3 ;
return T_3 ;
}
static int V_11 ( T_1 * T_2 , T_9 * V_3 , T_6 * T_7 , void * T_10 V_1 )
{
return ( F_87 ( V_93 , V_8 , T_2 , V_3 , T_7 ) ) ? F_88 ( T_2 ) : 0 ;
}
static int V_17 ( T_1 * T_2 , T_9 * V_3 , T_6 * T_7 , void * T_10 V_1 )
{
return ( F_87 ( V_94 , V_7 , T_2 , V_3 , T_7 ) ) ? F_88 ( T_2 ) : 0 ;
}
static int V_60 ( T_1 * T_2 , T_9 * V_3 , T_6 * T_7 , void * T_10 V_1 )
{
return ( F_87 ( V_95 , V_2 , T_2 , V_3 , T_7 ) ) ? F_88 ( T_2 ) : 0 ;
}
static int V_63 ( T_1 * T_2 , T_9 * V_3 , T_6 * T_7 , void * T_10 V_1 )
{
return ( F_87 ( V_96 , V_2 , T_2 , V_3 , T_7 ) ) ? F_88 ( T_2 ) : 0 ;
}
static int V_66 ( T_1 * T_2 , T_9 * V_3 , T_6 * T_7 , void * T_10 V_1 )
{
return ( F_87 ( V_97 , V_2 , T_2 , V_3 , T_7 ) ) ? F_88 ( T_2 ) : 0 ;
}
static int
F_89 ( T_1 * T_2 , T_9 * V_3 , T_6 * T_7 , void * T_10 V_1 )
{
T_11 * V_98 = NULL ;
T_6 * V_99 = NULL ;
F_90 ( V_3 -> V_4 , V_100 , V_101 ) ;
if ( T_7 ) {
V_98 = F_91 ( T_7 , V_102 , T_2 , 0 , - 1 , V_103 ) ;
V_99 = F_92 ( V_98 , V_104 ) ;
F_86 ( T_2 , V_3 , V_99 , NULL ) ;
}
return F_88 ( T_2 ) ;
}
void F_93 ( void ) {
static T_12 V_105 [] = {
#line 1 "./asn1/sbc-ap/packet-sbc-ap-hfarr.c"
{ & V_73 ,
{ L_5 , L_6 ,
V_106 , V_107 , F_11 ( V_108 ) , 0 ,
NULL , V_109 } } ,
{ & V_74 ,
{ L_7 , L_8 ,
V_106 , V_107 , F_11 ( V_110 ) , 0 ,
NULL , V_109 } } ,
{ & V_75 ,
{ L_9 , L_10 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_76 ,
{ L_11 , L_12 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_77 ,
{ L_13 , L_14 ,
V_106 , V_107 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_78 ,
{ L_15 , L_16 ,
V_106 , V_107 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_79 ,
{ L_17 , L_18 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_80 ,
{ L_19 , L_20 ,
V_106 , V_107 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_81 ,
{ L_21 , L_22 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_82 ,
{ L_23 , L_24 ,
V_106 , V_107 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_83 ,
{ L_25 , L_26 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_84 ,
{ L_27 , L_28 ,
V_106 , V_107 , F_11 ( V_114 ) , 0 ,
NULL , V_109 } } ,
{ & V_85 ,
{ L_29 , L_30 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_86 ,
{ L_31 , L_32 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_87 ,
{ L_33 , L_34 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_88 ,
{ L_35 , L_36 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_89 ,
{ L_37 , L_38 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_90 ,
{ L_39 , L_40 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_91 ,
{ L_41 , L_42 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_92 ,
{ L_43 , L_44 ,
V_106 , V_107 , F_11 ( V_115 ) , 0 ,
NULL , V_109 } } ,
{ & V_116 ,
{ L_45 , L_46 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_117 ,
{ L_47 , L_48 ,
V_106 , V_107 , F_11 ( V_10 ) , 0 ,
L_49 , V_109 } } ,
{ & V_118 ,
{ L_50 , L_51 ,
V_106 , V_107 , F_11 ( V_119 ) , 0 ,
NULL , V_109 } } ,
{ & V_120 ,
{ L_52 , L_53 ,
V_111 , V_112 , NULL , 0 ,
L_54 , V_109 } } ,
{ & V_121 ,
{ L_55 , L_56 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_122 ,
{ L_47 , L_48 ,
V_123 , V_107 , F_11 ( V_10 ) , 0 ,
L_57 , V_109 } } ,
{ & V_124 ,
{ L_58 , L_59 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_125 ,
{ L_60 , L_61 ,
V_106 , V_107 , F_11 ( V_6 ) , 0 ,
NULL , V_109 } } ,
{ & V_126 ,
{ L_62 , L_63 ,
V_106 , V_107 , F_11 ( V_127 ) , 0 ,
NULL , V_109 } } ,
{ & V_128 ,
{ L_64 , L_65 ,
V_106 , V_107 , F_11 ( V_119 ) , 0 ,
L_66 , V_109 } } ,
{ & V_129 ,
{ L_67 , L_68 ,
V_106 , V_107 , NULL , 0 ,
L_69 , V_109 } } ,
{ & V_130 ,
{ L_70 , L_71 ,
V_106 , V_107 , NULL , 0 ,
L_72 , V_109 } } ,
{ & V_131 ,
{ L_73 , L_74 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_132 ,
{ L_75 , L_76 ,
V_106 , V_107 , F_11 ( V_119 ) , 0 ,
L_66 , V_109 } } ,
{ & V_133 ,
{ L_77 , L_78 ,
V_106 , V_107 , F_11 ( V_10 ) , 0 ,
L_49 , V_109 } } ,
{ & V_134 ,
{ L_79 , L_80 ,
V_106 , V_107 , F_11 ( V_135 ) , 0 ,
NULL , V_109 } } ,
{ & V_136 ,
{ L_81 , L_82 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_137 ,
{ L_83 , L_84 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_138 ,
{ L_85 , L_86 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_139 ,
{ L_87 , L_88 ,
V_113 , V_112 , NULL , 0 ,
L_89 , V_109 } } ,
{ & V_140 ,
{ L_90 , L_91 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_141 ,
{ L_92 , L_93 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_142 ,
{ L_94 , L_95 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_143 ,
{ L_96 , L_97 ,
V_113 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_144 ,
{ L_98 , L_99 ,
V_106 , V_107 , NULL , 0 ,
L_100 , V_109 } } ,
{ & V_145 ,
{ L_101 , L_102 ,
V_106 , V_107 , NULL , 0 ,
L_103 , V_109 } } ,
{ & V_146 ,
{ L_104 , L_105 ,
V_106 , V_107 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_147 ,
{ L_106 , L_107 ,
V_106 , V_107 , NULL , 0 ,
L_108 , V_109 } } ,
{ & V_148 ,
{ L_109 , L_110 ,
V_106 , V_107 , NULL , 0 ,
L_72 , V_109 } } ,
{ & V_149 ,
{ L_111 , L_112 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_150 ,
{ L_113 , L_114 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_151 ,
{ L_115 , L_116 ,
V_111 , V_112 , NULL , 0 ,
NULL , V_109 } } ,
{ & V_152 ,
{ L_52 , L_53 ,
V_111 , V_112 , NULL , 0 ,
L_117 , V_109 } } ,
{ & V_153 ,
{ L_52 , L_53 ,
V_111 , V_112 , NULL , 0 ,
L_118 , V_109 } } ,
{ & V_154 ,
{ L_52 , L_53 ,
V_111 , V_112 , NULL , 0 ,
L_119 , V_109 } } ,
#line 151 "./asn1/sbc-ap/packet-sbc-ap-template.c"
} ;
static T_13 * V_155 [] = {
& V_104 ,
#line 1 "./asn1/sbc-ap/packet-sbc-ap-ettarr.c"
& V_14 ,
& V_12 ,
& V_20 ,
& V_18 ,
& V_28 ,
& V_25 ,
& V_23 ,
& V_34 ,
& V_37 ,
& V_32 ,
& V_44 ,
& V_42 ,
& V_47 ,
& V_40 ,
& V_50 ,
& V_52 ,
& V_54 ,
& V_56 ,
& V_58 ,
& V_69 ,
& V_61 ,
& V_64 ,
& V_67 ,
#line 157 "./asn1/sbc-ap/packet-sbc-ap-template.c"
} ;
V_102 = F_94 ( V_101 , V_156 , V_157 ) ;
F_95 ( V_102 , V_105 , F_96 ( V_105 ) ) ;
F_97 ( V_155 , F_96 ( V_155 ) ) ;
V_93 = F_98 ( L_120 , L_121 , V_102 , V_106 , V_107 , V_158 ) ;
V_94 = F_98 ( L_122 , L_123 , V_102 , V_106 , V_107 , V_158 ) ;
V_95 = F_98 ( L_124 , L_125 , V_102 , V_106 , V_107 , V_158 ) ;
V_96 = F_98 ( L_126 , L_127 , V_102 , V_106 , V_107 , V_158 ) ;
V_97 = F_98 ( L_128 , L_129 , V_102 , V_106 , V_107 , V_158 ) ;
}
void
F_99 ( void )
{
static T_14 V_159 = FALSE ;
static T_15 V_160 ;
if( ! V_159 ) {
V_161 = F_100 ( F_89 , V_102 ) ;
F_101 ( L_130 , V_162 , V_161 ) ;
V_159 = TRUE ;
#line 1 "./asn1/sbc-ap/packet-sbc-ap-dis-tab.c"
F_101 ( L_120 , V_163 , F_100 ( F_66 , V_102 ) ) ;
F_101 ( L_120 , V_164 , F_100 ( F_69 , V_102 ) ) ;
F_101 ( L_120 , V_165 , F_100 ( F_70 , V_102 ) ) ;
F_101 ( L_120 , V_166 , F_100 ( F_73 , V_102 ) ) ;
F_101 ( L_120 , V_167 , F_100 ( F_74 , V_102 ) ) ;
F_101 ( L_120 , V_168 , F_100 ( F_76 , V_102 ) ) ;
F_101 ( L_120 , V_169 , F_100 ( F_77 , V_102 ) ) ;
F_101 ( L_120 , V_170 , F_100 ( F_72 , V_102 ) ) ;
F_101 ( L_120 , V_171 , F_100 ( F_78 , V_102 ) ) ;
F_101 ( L_120 , V_172 , F_100 ( F_79 , V_102 ) ) ;
F_101 ( L_120 , V_173 , F_100 ( F_80 , V_102 ) ) ;
F_101 ( L_120 , V_174 , F_100 ( F_81 , V_102 ) ) ;
F_101 ( L_120 , V_175 , F_100 ( F_75 , V_102 ) ) ;
F_101 ( L_120 , V_176 , F_100 ( F_68 , V_102 ) ) ;
F_101 ( L_120 , V_177 , F_100 ( F_71 , V_102 ) ) ;
F_101 ( L_124 , V_178 , F_100 ( F_82 , V_102 ) ) ;
F_101 ( L_126 , V_178 , F_100 ( F_83 , V_102 ) ) ;
F_101 ( L_124 , V_179 , F_100 ( F_84 , V_102 ) ) ;
F_101 ( L_126 , V_179 , F_100 ( F_85 , V_102 ) ) ;
#line 190 "./asn1/sbc-ap/packet-sbc-ap-template.c"
} else {
if ( V_160 != 0 ) {
F_102 ( L_131 , V_160 , V_161 ) ;
}
}
V_160 = V_180 ;
if ( V_160 != 0 ) {
F_101 ( L_131 , V_160 , V_161 ) ;
}
}
