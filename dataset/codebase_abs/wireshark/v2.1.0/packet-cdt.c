static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 19 "./asn1/cdt/cdt.cnf"
T_11 V_2 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_2 ) ;
F_3 ( V_3 , L_1 ,
F_4 ( V_2 , V_4 ,
L_2 ) ) ;
F_5 ( T_7 -> V_5 -> V_6 , V_7 , L_3 ,
F_4 ( V_2 , V_4 ,
L_2 ) ) ;
return T_5 ;
}
static int
F_6 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_7 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 , NULL ) ;
return T_5 ;
}
static int
F_8 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_9 ( T_7 , T_9 , T_4 , T_5 ,
V_8 , T_10 , V_9 ,
NULL ) ;
return T_5 ;
}
static int
F_10 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 34 "./asn1/cdt/cdt.cnf"
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_10 ) ;
F_3 ( V_3 , L_1 ,
F_4 ( V_10 , V_11 ,
L_2 ) ) ;
F_5 ( T_7 -> V_5 -> V_6 , V_7 , L_3 ,
F_4 ( V_10 , V_11 ,
L_2 ) ) ;
return T_5 ;
}
static int
F_11 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 48 "./asn1/cdt/cdt.cnf"
const char * V_12 = NULL ;
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 , & V_12 ) ;
if ( V_12 ) {
const char * V_13 = F_13 ( F_14 () , V_12 ) ;
if ( ! V_13 ) {
V_13 = V_12 ;
}
F_3 ( V_3 , L_1 , V_13 ) ;
F_5 ( T_7 -> V_5 -> V_6 , V_7 , L_3 , V_13 ) ;
}
return T_5 ;
}
static int
F_15 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_9 ( T_7 , T_9 , T_4 , T_5 ,
V_14 , T_10 , V_15 ,
NULL ) ;
return T_5 ;
}
static int
F_16 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 67 "./asn1/cdt/cdt.cnf"
T_3 * V_16 = NULL , * V_17 = NULL ;
int V_18 = T_5 ;
T_5 = F_17 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_17 ) ;
if ( V_17 == NULL ) {
F_18 ( V_19 , T_7 -> V_5 , & V_20 ,
T_4 , V_18 , - 1 ) ;
F_19 ( T_7 -> V_5 -> V_6 , V_7 ,
L_4 ) ;
return T_5 ;
}
V_16 = F_20 ( T_4 , V_17 , 0 , F_21 ( V_17 ) ) ;
if ( V_16 == NULL ) {
F_18 ( V_19 , T_7 -> V_5 , & V_21 ,
T_4 , V_18 , - 1 ) ;
F_19 ( T_7 -> V_5 -> V_6 , V_7 ,
L_5 ) ;
return T_5 ;
}
F_22 ( T_7 -> V_5 , V_16 , L_6 ) ;
switch ( V_10 ) {
case V_22 :
F_23 ( V_16 , T_7 -> V_5 , V_19 ) ;
break;
case V_23 :
F_24 ( T_7 -> V_5 , V_16 , 0 , V_19 ) ;
break;
case V_24 :
F_25 ( V_16 , T_7 -> V_5 , V_19 , NULL ) ;
break;
default:
F_23 ( V_16 , T_7 -> V_5 , V_19 ) ;
break;
}
return T_5 ;
}
static int
F_26 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_27 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_25 , T_10 , V_26 ) ;
return T_5 ;
}
int
F_28 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 11 "./asn1/cdt/cdt.cnf"
V_10 = 0 ;
T_5 = F_27 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_27 , T_10 , V_28 ) ;
return T_5 ;
}
static int F_29 ( T_3 * T_4 V_1 , T_12 * V_5 V_1 , T_8 * T_9 V_1 , void * T_13 V_1 ) {
int T_5 = 0 ;
T_6 V_29 ;
F_30 ( & V_29 , V_30 , TRUE , V_5 ) ;
T_5 = F_28 ( FALSE , T_4 , T_5 , & V_29 , T_9 , V_31 ) ;
return T_5 ;
}
void F_31 ( T_3 * T_4 , T_12 * V_5 , T_8 * V_32 )
{
T_8 * T_9 = NULL ;
V_19 = V_32 ;
if ( V_32 ) {
V_3 = F_32 ( V_32 , V_33 , T_4 , 0 , - 1 , V_34 ) ;
T_9 = F_33 ( V_3 , V_28 ) ;
} else {
V_3 = NULL ;
}
F_34 ( V_5 -> V_6 , V_35 , L_7 ) ;
F_35 ( V_5 -> V_6 , V_7 ) ;
F_29 ( T_4 , V_5 , T_9 , NULL ) ;
}
void F_36 ( void ) {
static T_14 V_36 [] = {
#line 1 "./asn1/cdt/packet-cdt-hfarr.c"
{ & V_31 ,
{ L_8 , L_9 ,
V_37 , V_38 , NULL , 0 ,
NULL , V_39 } } ,
{ & V_40 ,
{ L_10 , L_11 ,
V_41 , V_42 , F_37 ( V_43 ) , 0 ,
L_12 , V_39 } } ,
{ & V_44 ,
{ L_13 , L_14 ,
V_37 , V_38 , NULL , 0 ,
NULL , V_39 } } ,
{ & V_45 ,
{ L_15 , L_16 ,
V_46 , V_42 , F_37 ( V_4 ) , 0 ,
NULL , V_39 } } ,
{ & V_47 ,
{ L_17 , L_18 ,
V_48 , V_38 , NULL , 0 ,
L_19 , V_39 } } ,
{ & V_49 ,
{ L_20 , L_21 ,
V_41 , V_42 , F_37 ( V_50 ) , 0 ,
NULL , V_39 } } ,
{ & V_51 ,
{ L_22 , L_23 ,
V_46 , V_42 , F_37 ( V_11 ) , 0 ,
NULL , V_39 } } ,
{ & V_52 ,
{ L_24 , L_25 ,
V_48 , V_38 , NULL , 0 ,
NULL , V_39 } } ,
{ & V_53 ,
{ L_26 , L_27 ,
V_54 , V_38 , NULL , 0 ,
NULL , V_39 } } ,
#line 101 "./asn1/cdt/packet-cdt-template.c"
} ;
static T_15 * V_55 [] = {
#line 1 "./asn1/cdt/packet-cdt-ettarr.c"
& V_28 ,
& V_9 ,
& V_26 ,
& V_15 ,
#line 106 "./asn1/cdt/packet-cdt-template.c"
} ;
static T_16 V_56 [] = {
{ & V_20 , { L_28 , V_57 , V_58 , L_29 , V_59 } } ,
{ & V_21 , { L_30 , V_57 , V_58 , L_31 , V_59 } } ,
} ;
T_17 * V_60 ;
V_33 = F_38 ( V_61 , V_62 , V_63 ) ;
F_39 ( V_33 , V_36 , F_40 ( V_36 ) ) ;
F_41 ( V_55 , F_40 ( V_55 ) ) ;
V_60 = F_42 ( V_33 ) ;
F_43 ( V_60 , V_56 , F_40 ( V_56 ) ) ;
}
void F_44 ( void ) {
#line 1 "./asn1/cdt/packet-cdt-dis-tab.c"
F_45 ( L_32 , F_29 , V_33 , L_33 ) ;
#line 129 "./asn1/cdt/packet-cdt-template.c"
}
