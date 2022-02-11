static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 46 "../../asn1/credssp/credssp.cnf"
T_3 * V_2 = NULL ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_2 ) ;
if( V_2 != NULL )
F_3 ( V_3 ,
V_2 , T_7 -> V_4 , F_4 ( T_9 ) , NULL ) ;
return T_5 ;
}
static int
F_5 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_5 , T_10 , V_6 ) ;
return T_5 ;
}
static int
F_7 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_8 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_7 , T_10 , V_8 ) ;
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
V_9 , T_10 , V_10 ) ;
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
V_11 , T_10 , V_12 ) ;
return T_5 ;
}
static int
F_14 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_13 , T_10 , V_14 ) ;
return T_5 ;
}
static int
F_15 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_15 ) ;
return T_5 ;
}
static int
F_16 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 24 "../../asn1/credssp/credssp.cnf"
T_3 * V_16 = NULL ;
T_3 * V_17 = NULL ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_16 ) ;
if( ( V_17 != NULL ) &&
( ( V_15 == V_18 ) || ( V_15 == V_19 ) ) ) {
switch( V_15 ) {
case V_18 :
T_5 = F_10 ( FALSE , V_17 , 0 , T_7 , T_9 , V_20 ) ;
break;
case V_19 :
T_5 = F_14 ( FALSE , V_17 , 0 , T_7 , T_9 , V_21 ) ;
break;
}
}
return T_5 ;
}
static int
F_17 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_22 , T_10 , V_23 ) ;
return T_5 ;
}
static int
F_18 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 11 "../../asn1/credssp/credssp.cnf"
T_3 * V_24 = NULL ;
T_3 * V_17 = NULL ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_24 ) ;
if( V_17 != NULL )
T_5 = F_17 ( FALSE , V_17 , 0 , T_7 , T_9 , V_25 ) ;
return T_5 ;
}
static int
F_19 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_6 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_26 , T_10 , V_27 ) ;
return T_5 ;
}
static void F_20 ( T_3 * T_4 V_1 , T_11 * V_4 V_1 , T_8 * T_9 V_1 ) {
T_6 V_28 ;
F_21 ( & V_28 , V_29 , TRUE , V_4 ) ;
F_19 ( FALSE , T_4 , 0 , & V_28 , T_9 , V_30 ) ;
}
static void
F_22 ( T_3 * T_4 , T_11 * V_4 , T_8 * V_31 )
{
T_12 * V_32 = NULL ;
T_8 * T_9 = NULL ;
if( V_31 ) {
V_32 = F_23 ( V_31 , V_33 , T_4 , 0 , - 1 , V_34 ) ;
T_9 = F_24 ( V_32 , V_35 ) ;
}
F_25 ( V_4 -> V_36 , V_37 , L_1 ) ;
F_26 ( V_4 -> V_36 , V_38 ) ;
V_15 = - 1 ;
F_20 ( T_4 , V_4 , T_9 ) ;
}
static T_1
F_27 ( T_3 * T_4 , T_11 * V_4 , T_8 * V_31 , void * T_13 V_1 )
{
T_6 V_28 ;
int T_5 = 0 ;
T_14 V_39 ;
T_1 V_40 ;
T_15 V_41 ;
T_16 V_42 ;
F_21 ( & V_28 , V_29 , TRUE , V_4 ) ;
if( F_28 ( T_4 ) > 7 ) {
T_5 = F_29 ( T_4 , T_5 , & V_39 , & V_40 , & V_41 ) ;
if( ( V_39 == V_43 ) && ( V_41 == V_44 ) && ( V_40 == TRUE ) ) {
T_5 = F_30 ( T_4 , T_5 , NULL , NULL ) ;
T_5 = F_29 ( T_4 , T_5 , & V_39 , & V_40 , & V_41 ) ;
if( ( V_39 == V_45 ) && ( V_41 == 0 ) ) {
T_5 = F_30 ( T_4 , T_5 , NULL , NULL ) ;
T_5 = F_29 ( T_4 , T_5 , & V_39 , & V_40 , & V_41 ) ;
if( ( V_39 == V_43 ) && ( V_41 == V_46 ) ) {
T_5 = F_30 ( T_4 , T_5 , & V_42 , NULL ) ;
if( ( V_42 == 1 ) && ( F_31 ( T_4 , T_5 ) == 2 ) ) {
F_22 ( T_4 , V_4 , V_31 ) ;
return TRUE ;
}
}
}
}
}
return FALSE ;
}
void F_32 ( void ) {
static T_17 V_47 [] =
{
{ & V_20 ,
{ L_2 , L_3 ,
V_48 , V_49 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_21 ,
{ L_4 , L_5 ,
V_48 , V_49 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_25 ,
{ L_6 , L_7 ,
V_48 , V_49 , NULL , 0 ,
NULL , V_50 } } ,
#line 1 "../../asn1/credssp/packet-credssp-hfarr.c"
{ & V_30 ,
{ L_8 , L_9 ,
V_48 , V_49 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_51 ,
{ L_10 , L_11 ,
V_48 , V_49 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_52 ,
{ L_12 , L_13 ,
V_53 , V_49 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_54 ,
{ L_14 , L_15 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_55 ,
{ L_17 , L_18 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_56 ,
{ L_19 , L_20 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_57 ,
{ L_21 , L_22 ,
V_58 , V_59 , NULL , 0 ,
L_23 , V_50 } } ,
{ & V_60 ,
{ L_24 , L_25 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_61 ,
{ L_26 , L_27 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_62 ,
{ L_28 , L_29 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_63 ,
{ L_30 , L_31 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_64 ,
{ L_32 , L_33 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_65 ,
{ L_34 , L_35 ,
V_48 , V_49 , NULL , 0 ,
L_36 , V_50 } } ,
{ & V_66 ,
{ L_37 , L_38 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_67 ,
{ L_39 , L_40 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
{ & V_68 ,
{ L_41 , L_42 ,
V_58 , V_59 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_69 ,
{ L_43 , L_44 ,
V_53 , V_49 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_70 ,
{ L_45 , L_46 ,
V_58 , V_59 , NULL , 0 ,
L_23 , V_50 } } ,
{ & V_71 ,
{ L_47 , L_48 ,
V_72 , V_59 , NULL , 0 ,
L_49 , V_50 } } ,
{ & V_73 ,
{ L_50 , L_51 ,
V_53 , V_49 , NULL , 0 ,
NULL , V_50 } } ,
{ & V_74 ,
{ L_52 , L_53 ,
V_53 , V_49 , NULL , 0 ,
L_16 , V_50 } } ,
#line 135 "../../asn1/credssp/packet-credssp-template.c"
} ;
static T_18 * V_75 [] = {
& V_35 ,
#line 1 "../../asn1/credssp/packet-credssp-ettarr.c"
& V_8 ,
& V_6 ,
& V_10 ,
& V_12 ,
& V_14 ,
& V_23 ,
& V_27 ,
#line 141 "../../asn1/credssp/packet-credssp-template.c"
} ;
V_33 = F_33 ( V_76 , V_77 , V_78 ) ;
F_34 ( L_54 , F_22 , V_33 ) ;
F_35 ( V_33 , V_47 , F_36 ( V_47 ) ) ;
F_37 ( V_75 , F_36 ( V_75 ) ) ;
F_38 ( L_54 , & V_3 ) ;
}
void F_39 ( void ) {
F_40 ( L_55 , F_27 , V_33 ) ;
}
