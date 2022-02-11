static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 45 "./asn1/credssp/credssp.cnf"
T_3 * V_2 = NULL ;
T_11 * V_3 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_2 ) ;
if( V_2 != NULL )
F_3 ( V_4 ,
V_2 , T_7 -> V_5 , F_4 ( T_9 ) , & V_3 , NULL ) ;
return T_5 ;
}
static int
F_5 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_6 , T_10 , V_7 ) ;
return T_5 ;
}
static int
F_7 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_8 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_8 , T_10 , V_9 ) ;
return T_5 ;
}
static int
F_9 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_10 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_10 , T_10 , V_11 ) ;
return T_5 ;
}
static int
F_11 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_13 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_12 , T_10 , V_13 ) ;
return T_5 ;
}
static int
F_14 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_14 , T_10 , V_15 ) ;
return T_5 ;
}
static int
F_15 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_16 ) ;
return T_5 ;
}
static int
F_16 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 23 "./asn1/credssp/credssp.cnf"
T_3 * V_17 = NULL ;
T_3 * V_18 = NULL ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_17 ) ;
if( ( V_18 != NULL ) &&
( ( V_16 == V_19 ) || ( V_16 == V_20 ) ) ) {
switch( V_16 ) {
case V_19 :
T_5 = F_10 ( FALSE , V_18 , 0 , T_7 , T_9 , V_21 ) ;
break;
case V_20 :
T_5 = F_14 ( FALSE , V_18 , 0 , T_7 , T_9 , V_22 ) ;
break;
}
}
return T_5 ;
}
static int
F_17 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_23 , T_10 , V_24 ) ;
return T_5 ;
}
static int
F_18 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 10 "./asn1/credssp/credssp.cnf"
T_3 * V_25 = NULL ;
T_3 * V_18 = NULL ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_25 ) ;
if( V_18 != NULL )
T_5 = F_17 ( FALSE , V_18 , 0 , T_7 , T_9 , V_26 ) ;
return T_5 ;
}
static int
F_19 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_27 , T_10 , V_28 ) ;
return T_5 ;
}
static int F_20 ( T_3 * T_4 V_1 , T_12 * V_5 V_1 , T_8 * T_9 V_1 , void * T_13 V_1 ) {
int T_5 = 0 ;
T_6 V_29 ;
F_21 ( & V_29 , V_30 , TRUE , V_5 ) ;
T_5 = F_19 ( FALSE , T_4 , T_5 , & V_29 , T_9 , V_31 ) ;
return T_5 ;
}
static int
F_22 ( T_3 * T_4 , T_12 * V_5 , T_8 * V_32 , void * T_13 )
{
T_14 * V_33 = NULL ;
T_8 * T_9 = NULL ;
if( V_32 ) {
V_33 = F_23 ( V_32 , V_34 , T_4 , 0 , - 1 , V_35 ) ;
T_9 = F_24 ( V_33 , V_36 ) ;
}
F_25 ( V_5 -> V_37 , V_38 , L_1 ) ;
F_26 ( V_5 -> V_37 , V_39 ) ;
V_16 = - 1 ;
return F_20 ( T_4 , V_5 , T_9 , T_13 ) ;
}
static T_1
F_27 ( T_3 * T_4 , T_12 * V_5 , T_8 * V_32 , void * T_13 V_1 )
{
T_6 V_29 ;
int T_5 = 0 ;
T_15 V_40 ;
T_1 V_41 ;
T_16 V_42 ;
T_17 V_43 ;
T_15 V_44 ;
F_21 ( & V_29 , V_30 , TRUE , V_5 ) ;
if( F_28 ( T_4 ) > 7 ) {
T_5 = F_29 ( T_4 , T_5 , & V_40 , & V_41 , & V_42 ) ;
if( ( V_40 == V_45 ) && ( V_42 == V_46 ) && ( V_41 == TRUE ) ) {
T_5 = F_30 ( T_4 , T_5 , NULL , NULL ) ;
T_5 = F_29 ( T_4 , T_5 , & V_40 , & V_41 , & V_42 ) ;
if( ( V_40 == V_47 ) && ( V_42 == 0 ) ) {
T_5 = F_30 ( T_4 , T_5 , NULL , NULL ) ;
T_5 = F_29 ( T_4 , T_5 , & V_40 , & V_41 , & V_42 ) ;
if( ( V_40 == V_45 ) && ( V_42 == V_48 ) ) {
T_5 = F_30 ( T_4 , T_5 , & V_43 , NULL ) ;
V_44 = F_31 ( T_4 , T_5 ) ;
if( ( V_43 == 1 ) && ( ( V_44 == 2 ) || ( V_44 == 3 ) ) ) {
if ( F_32 ( V_49 ) ) {
T_18 * V_50 = F_33 ( V_5 , L_2 , V_51 ) ;
V_50 -> F_28 = F_28 ( T_4 ) ;
V_50 -> V_52 = V_52 ( T_4 ) ;
V_50 -> V_53 = T_4 ;
F_34 ( V_49 , V_5 , V_50 ) ;
}
F_22 ( T_4 , V_5 , V_32 , NULL ) ;
return TRUE ;
}
}
}
}
}
return FALSE ;
}
void F_35 ( void ) {
static T_19 V_54 [] =
{
{ & V_21 ,
{ L_3 , L_4 ,
V_55 , V_56 , NULL , 0 ,
NULL , V_57 } } ,
{ & V_22 ,
{ L_5 , L_6 ,
V_55 , V_56 , NULL , 0 ,
NULL , V_57 } } ,
{ & V_26 ,
{ L_7 , L_8 ,
V_55 , V_56 , NULL , 0 ,
NULL , V_57 } } ,
#line 1 "./asn1/credssp/packet-credssp-hfarr.c"
{ & V_31 ,
{ L_9 , L_10 ,
V_55 , V_56 , NULL , 0 ,
NULL , V_57 } } ,
{ & V_58 ,
{ L_11 , L_12 ,
V_55 , V_56 , NULL , 0 ,
NULL , V_57 } } ,
{ & V_59 ,
{ L_13 , L_14 ,
V_60 , V_56 , NULL , 0 ,
NULL , V_57 } } ,
{ & V_61 ,
{ L_15 , L_16 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_62 ,
{ L_18 , L_19 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_63 ,
{ L_20 , L_21 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_64 ,
{ L_22 , L_23 ,
V_65 , V_66 , NULL , 0 ,
L_24 , V_57 } } ,
{ & V_67 ,
{ L_25 , L_26 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_68 ,
{ L_27 , L_28 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_69 ,
{ L_29 , L_30 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_70 ,
{ L_31 , L_32 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_71 ,
{ L_33 , L_34 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_72 ,
{ L_35 , L_36 ,
V_55 , V_56 , NULL , 0 ,
L_37 , V_57 } } ,
{ & V_73 ,
{ L_38 , L_39 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_74 ,
{ L_40 , L_41 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
{ & V_75 ,
{ L_42 , L_43 ,
V_65 , V_66 , NULL , 0 ,
NULL , V_57 } } ,
{ & V_76 ,
{ L_44 , L_45 ,
V_60 , V_56 , NULL , 0 ,
NULL , V_57 } } ,
{ & V_77 ,
{ L_46 , L_47 ,
V_65 , V_66 , NULL , 0 ,
L_24 , V_57 } } ,
{ & V_78 ,
{ L_48 , L_49 ,
V_79 , V_66 , NULL , 0 ,
L_50 , V_57 } } ,
{ & V_80 ,
{ L_51 , L_52 ,
V_60 , V_56 , NULL , 0 ,
NULL , V_57 } } ,
{ & V_81 ,
{ L_53 , L_54 ,
V_60 , V_56 , NULL , 0 ,
L_17 , V_57 } } ,
#line 147 "./asn1/credssp/packet-credssp-template.c"
} ;
static T_20 * V_82 [] = {
& V_36 ,
#line 1 "./asn1/credssp/packet-credssp-ettarr.c"
& V_9 ,
& V_7 ,
& V_11 ,
& V_13 ,
& V_15 ,
& V_24 ,
& V_28 ,
#line 153 "./asn1/credssp/packet-credssp-template.c"
} ;
V_34 = F_36 ( V_83 , V_84 , V_85 ) ;
F_37 ( L_2 , F_22 , V_34 ) ;
F_38 ( V_34 , V_54 , F_39 ( V_54 ) ) ;
F_40 ( V_82 , F_39 ( V_82 ) ) ;
V_4 = F_41 ( L_2 , V_34 ) ;
}
void F_42 ( void ) {
F_43 ( L_55 , F_27 , L_56 , L_57 , V_34 , V_86 ) ;
V_49 = F_44 ( V_87 ) ;
}
