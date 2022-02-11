static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 21 "../../asn1/cdt/cdt.cnf"
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
#line 36 "../../asn1/cdt/cdt.cnf"
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
#line 50 "../../asn1/cdt/cdt.cnf"
const char * V_12 = NULL ;
T_5 = F_12 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 , & V_12 ) ;
if ( V_12 ) {
const char * V_13 = F_13 ( V_12 ) ;
if ( ! V_13 ) {
V_13 = V_12 ;
}
F_3 ( V_3 , L_1 , V_13 ) ;
F_5 ( T_7 -> V_5 -> V_6 , V_7 , L_3 , V_13 ) ;
}
return T_5 ;
}
static int
F_14 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_9 ( T_7 , T_9 , T_4 , T_5 ,
V_14 , T_10 , V_15 ,
NULL ) ;
return T_5 ;
}
static int
F_15 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 69 "../../asn1/cdt/cdt.cnf"
T_3 * V_16 = NULL , * V_17 = NULL ;
T_12 * V_18 = NULL ;
int V_19 = T_5 ;
T_5 = F_16 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_17 ) ;
if ( V_17 == NULL ) {
V_18 = F_17 ( V_20 , T_4 , V_19 , - 1 ,
L_4 ) ;
F_18 ( T_7 -> V_5 , V_18 , V_21 , V_22 ,
L_5 ) ;
F_19 ( T_7 -> V_5 -> V_6 , V_7 ,
L_4 ) ;
return T_5 ;
}
V_16 = F_20 ( T_4 , V_17 , 0 , F_21 ( V_17 ) ) ;
if ( V_16 == NULL ) {
V_18 = F_17 ( V_20 , T_4 , V_19 , - 1 ,
L_6 ) ;
F_18 ( T_7 -> V_5 , V_18 , V_21 , V_22 ,
L_7 ) ;
F_19 ( T_7 -> V_5 -> V_6 , V_7 ,
L_6 ) ;
return T_5 ;
}
F_22 ( T_7 -> V_5 , V_16 , L_8 ) ;
switch ( V_10 ) {
case V_23 :
F_23 ( V_24 , V_16 , T_7 -> V_5 , V_20 ) ;
break;
case V_25 :
F_24 ( T_7 -> V_5 , V_16 , 0 , V_20 ) ;
break;
case V_26 :
F_25 ( V_16 , T_7 -> V_5 , V_20 ) ;
break;
default:
F_23 ( V_24 , V_16 , T_7 -> V_5 , V_20 ) ;
break;
}
return T_5 ;
}
static int
F_26 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_27 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_27 , T_10 , V_28 ) ;
return T_5 ;
}
int
F_28 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 13 "../../asn1/cdt/cdt.cnf"
V_10 = 0 ;
T_5 = F_27 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_29 , T_10 , V_30 ) ;
return T_5 ;
}
static void F_29 ( T_3 * T_4 V_1 , T_13 * V_5 V_1 , T_8 * T_9 V_1 ) {
T_6 V_31 ;
F_30 ( & V_31 , V_32 , TRUE , V_5 ) ;
F_28 ( FALSE , T_4 , 0 , & V_31 , T_9 , V_33 ) ;
}
void F_31 ( T_3 * T_4 , T_13 * V_5 , T_8 * V_34 )
{
T_8 * T_9 = NULL ;
V_20 = V_34 ;
if ( V_34 ) {
V_3 = F_32 ( V_34 , V_35 , T_4 , 0 , - 1 , V_36 ) ;
T_9 = F_33 ( V_3 , V_30 ) ;
}
F_34 ( V_5 -> V_6 , V_37 , L_9 ) ;
F_35 ( V_5 -> V_6 , V_7 ) ;
F_29 ( T_4 , V_5 , T_9 ) ;
}
void F_36 ( void ) {
static T_14 V_38 [] = {
#line 1 "../../asn1/cdt/packet-cdt-hfarr.c"
{ & V_33 ,
{ L_10 , L_11 ,
V_39 , V_40 , NULL , 0 ,
NULL , V_41 } } ,
{ & V_42 ,
{ L_12 , L_13 ,
V_43 , V_44 , F_37 ( V_45 ) , 0 ,
L_14 , V_41 } } ,
{ & V_46 ,
{ L_15 , L_16 ,
V_39 , V_40 , NULL , 0 ,
NULL , V_41 } } ,
{ & V_47 ,
{ L_17 , L_18 ,
V_48 , V_44 , F_37 ( V_4 ) , 0 ,
NULL , V_41 } } ,
{ & V_49 ,
{ L_19 , L_20 ,
V_50 , V_40 , NULL , 0 ,
L_21 , V_41 } } ,
{ & V_51 ,
{ L_22 , L_23 ,
V_43 , V_44 , F_37 ( V_52 ) , 0 ,
NULL , V_41 } } ,
{ & V_53 ,
{ L_24 , L_25 ,
V_48 , V_44 , F_37 ( V_11 ) , 0 ,
NULL , V_41 } } ,
{ & V_54 ,
{ L_26 , L_27 ,
V_50 , V_40 , NULL , 0 ,
NULL , V_41 } } ,
{ & V_55 ,
{ L_28 , L_29 ,
V_56 , V_40 , NULL , 0 ,
NULL , V_41 } } ,
#line 97 "../../asn1/cdt/packet-cdt-template.c"
} ;
static T_15 * V_57 [] = {
#line 1 "../../asn1/cdt/packet-cdt-ettarr.c"
& V_30 ,
& V_9 ,
& V_28 ,
& V_15 ,
#line 102 "../../asn1/cdt/packet-cdt-template.c"
} ;
V_35 = F_38 ( V_58 , V_59 , V_60 ) ;
F_39 ( V_35 , V_38 , F_40 ( V_38 ) ) ;
F_41 ( V_57 , F_40 ( V_57 ) ) ;
}
void F_42 ( void ) {
#line 1 "../../asn1/cdt/packet-cdt-dis-tab.c"
F_43 ( L_30 , F_29 , V_35 , L_31 ) ;
#line 117 "../../asn1/cdt/packet-cdt-template.c"
V_24 = F_44 ( L_32 ) ;
}
