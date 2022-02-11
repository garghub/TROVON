T_1 * F_1 ( T_1 * V_1 , const T_2 * type ) {
T_1 * V_2 ;
V_2 = F_2 ( sizeof( T_1 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_1 = V_1 ;
V_2 -> type = type ;
return V_2 ;
}
T_3 F_3 ( T_1 * V_2 ) {
return V_2 && ( V_2 -> V_3 == V_4 ) ;
}
T_1 * F_4 ( void * V_5 ) {
T_1 * V_2 = ( T_1 * ) V_5 ;
T_4 * V_6 = ( T_4 * ) V_5 ;
if ( ! F_5 ( V_6 ) )
V_6 = NULL ;
if ( V_6 )
V_2 = V_6 -> V_7 ;
if ( ! F_3 ( V_2 ) )
V_2 = NULL ;
return V_2 ;
}
void F_6 ( T_1 * V_2 ) {
const T_2 * V_8 ;
if ( ! V_2 ) return;
V_8 = ( V_2 -> V_1 ) ? V_2 -> V_1 -> V_9 : NULL ;
V_2 -> V_9 = F_7 (
L_1
L_2
L_1 ,
( V_8 ) ? V_8 : L_3 , ( V_8 ) ? L_4 : L_3 ,
( V_2 -> type ) ? V_2 -> type : L_3 , ( V_2 -> type && ( V_2 -> V_10 || V_2 -> V_11 ) ) ? L_4 : L_3 , ( V_2 -> V_10 ) ? V_2 -> V_10 : L_3 ,
( V_2 -> V_11 ) ? L_5 : L_3 , ( V_2 -> V_11 ) ? V_2 -> V_11 : L_3
) ;
}
static int
F_8 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_9 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_13 , V_13 , FALSE , NULL ) ;
return T_7 ;
}
static int
F_10 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_11 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_14 , V_15 ) ;
return T_7 ;
}
static int
F_12 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_13 ( T_6 , T_7 , V_6 , T_9 , T_10 ) ;
return T_7 ;
}
static int
F_14 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_15 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_16 , V_17 ) ;
return T_7 ;
}
static int
F_16 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_17 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
1U , 256U , NULL , FALSE ) ;
return T_7 ;
}
static int
F_18 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_19 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_18 , V_19 ,
NULL ) ;
return T_7 ;
}
static int
F_20 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_11 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_20 , V_21 ) ;
return T_7 ;
}
static int
F_21 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_15 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_22 , V_23 ) ;
return T_7 ;
}
static int
F_22 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_17 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
1U , 65535U , NULL , FALSE ) ;
return T_7 ;
}
static int
F_23 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_15 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_24 , V_25 ) ;
return T_7 ;
}
static int
F_24 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_25 ( T_6 , T_7 , V_6 , T_9 , T_10 ) ;
return T_7 ;
}
static int
F_26 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_15 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_26 , V_27 ) ;
return T_7 ;
}
static int
F_27 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_15 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_28 , V_29 ) ;
return T_7 ;
}
static int
F_28 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_11 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_30 , V_31 ) ;
return T_7 ;
}
static int
F_29 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_15 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_32 , V_33 ) ;
return T_7 ;
}
static int
F_30 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_15 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_34 , V_35 ) ;
return T_7 ;
}
static int
F_31 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_19 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_36 , V_37 ,
NULL ) ;
return T_7 ;
}
static int
F_32 ( T_5 * T_6 V_12 , int T_7 V_12 , T_4 * V_6 V_12 , T_8 * T_9 V_12 , int T_10 V_12 ) {
T_7 = F_15 ( T_6 , T_7 , V_6 , T_9 , T_10 ,
V_38 , V_39 ) ;
return T_7 ;
}
static int F_33 ( T_5 * T_6 V_12 , T_11 * T_12 V_12 , T_8 * T_9 V_12 ) {
int T_7 = 0 ;
T_4 V_40 ;
F_34 ( & V_40 , V_41 , TRUE , T_12 ) ;
T_7 = F_14 ( T_6 , T_7 , & V_40 , T_9 , V_42 ) ;
T_7 += 7 ; T_7 >>= 3 ;
return T_7 ;
}
static int F_35 ( T_5 * T_6 V_12 , T_11 * T_12 V_12 , T_8 * T_9 V_12 ) {
int T_7 = 0 ;
T_4 V_40 ;
F_34 ( & V_40 , V_41 , TRUE , T_12 ) ;
T_7 = F_32 ( T_6 , T_7 , & V_40 , T_9 , V_43 ) ;
T_7 += 7 ; T_7 >>= 3 ;
return T_7 ;
}
void F_36 ( void ) {
static T_13 V_44 [] = {
#line 1 "../../asn1/h323/packet-h323-hfarr.c"
{ & V_42 ,
{ L_6 , L_7 ,
V_45 , V_46 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_43 ,
{ L_8 , L_9 ,
V_45 , V_46 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_48 ,
{ L_10 , L_11 ,
V_45 , V_46 , NULL , 0 ,
L_12 , V_47 } } ,
{ & V_49 ,
{ L_13 , L_14 ,
V_50 , V_51 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_52 ,
{ L_15 , L_16 ,
V_53 , V_46 , NULL , 0 ,
L_17 , V_47 } } ,
{ & V_54 ,
{ L_18 , L_19 ,
V_45 , V_46 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_55 ,
{ L_20 , L_21 ,
V_45 , V_46 , NULL , 0 ,
L_22 , V_47 } } ,
{ & V_56 ,
{ L_23 , L_24 ,
V_50 , V_51 , NULL , 0 ,
L_25 , V_47 } } ,
{ & V_57 ,
{ L_26 , L_27 ,
V_50 , V_51 , F_37 ( V_58 ) , 0 ,
NULL , V_47 } } ,
{ & V_59 ,
{ L_28 , L_29 ,
V_45 , V_46 , NULL , 0 ,
L_30 , V_47 } } ,
{ & V_60 ,
{ L_31 , L_32 ,
V_45 , V_46 , NULL , 0 ,
L_33 , V_47 } } ,
{ & V_61 ,
{ L_34 , L_35 ,
V_45 , V_46 , NULL , 0 ,
L_36 , V_47 } } ,
{ & V_62 ,
{ L_37 , L_38 ,
V_45 , V_46 , NULL , 0 ,
L_39 , V_47 } } ,
{ & V_63 ,
{ L_40 , L_41 ,
V_45 , V_46 , NULL , 0 ,
L_42 , V_47 } } ,
{ & V_64 ,
{ L_43 , L_44 ,
V_45 , V_46 , NULL , 0 ,
L_45 , V_47 } } ,
{ & V_65 ,
{ L_46 , L_47 ,
V_50 , V_51 , F_37 ( V_66 ) , 0 ,
NULL , V_47 } } ,
{ & V_67 ,
{ L_48 , L_49 ,
V_50 , V_51 , F_37 ( V_68 ) , 0 ,
L_50 , V_47 } } ,
{ & V_69 ,
{ L_51 , L_52 ,
V_45 , V_46 , NULL , 0 ,
L_53 , V_47 } } ,
{ & V_70 ,
{ L_54 , L_55 ,
V_50 , V_51 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_71 ,
{ L_56 , L_57 ,
V_45 , V_46 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_72 ,
{ L_58 , L_59 ,
V_50 , V_51 , NULL , 0 ,
L_60 , V_47 } } ,
{ & V_73 ,
{ L_61 , L_62 ,
V_74 , V_46 , NULL , 0 ,
L_63 , V_47 } } ,
{ & V_75 ,
{ L_64 , L_65 ,
V_50 , V_51 , F_37 ( V_68 ) , 0 ,
L_50 , V_47 } } ,
{ & V_76 ,
{ L_66 , L_67 ,
V_50 , V_51 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_77 ,
{ L_68 , L_69 ,
V_53 , V_46 , NULL , 0 ,
L_17 , V_47 } } ,
{ & V_78 ,
{ L_70 , L_71 ,
V_45 , V_46 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_79 ,
{ L_72 , L_73 ,
V_50 , V_51 , NULL , 0 ,
NULL , V_47 } } ,
{ & V_80 ,
{ L_74 , L_75 ,
V_45 , V_46 , NULL , 0 ,
NULL , V_47 } } ,
#line 105 "../../asn1/h323/packet-h323-template.c"
} ;
static T_14 * V_81 [] = {
#line 1 "../../asn1/h323/packet-h323-ettarr.c"
& V_16 ,
& V_14 ,
& V_38 ,
& V_36 ,
& V_20 ,
& V_18 ,
& V_22 ,
& V_24 ,
& V_26 ,
& V_28 ,
& V_32 ,
& V_30 ,
& V_34 ,
#line 110 "../../asn1/h323/packet-h323-template.c"
} ;
V_82 = F_38 ( V_83 , V_84 , V_85 ) ;
F_39 ( V_82 , V_44 , F_40 ( V_44 ) ) ;
F_41 ( V_81 , F_40 ( V_81 ) ) ;
}
void F_42 ( void )
{
T_15 V_86 ;
V_86 = F_43 ( L_76 ) ;
F_44 ( L_77 , L_78 , V_86 ) ;
F_44 ( L_79 , L_80 ,
F_45 ( F_33 , V_82 ) ) ;
F_44 ( L_79 , L_81 ,
F_45 ( F_35 , V_82 ) ) ;
}
