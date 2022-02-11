static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
struct V_5 * V_6 ;
T_4 * V_7 ;
T_3 * V_8 ;
T_5 V_9 ;
F_2 ( & V_9 , V_10 , TRUE , V_2 ) ;
if ( V_4 == NULL )
return 0 ;
V_6 = (struct V_5 * ) V_4 ;
if( V_6 -> V_11 == 0 ) {
F_3 ( V_3 , V_2 , & V_12 , V_1 , 0 , - 1 ,
L_1 , V_6 -> V_11 ) ;
return 0 ;
}
V_9 . V_13 = V_6 ;
V_7 = F_4 ( V_3 , V_14 , V_1 , 0 , - 1 , V_15 ) ;
V_8 = F_5 ( V_7 , V_16 ) ;
F_6 ( V_2 -> V_17 , V_18 , L_2 ) ;
F_7 ( V_2 -> V_17 , V_19 ) ;
switch( V_6 -> V_11 ) {
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
F_8 ( FALSE , V_1 , 0 , & V_9 , V_8 , - 1 ) ;
break;
case V_25 :
F_9 ( FALSE , V_1 , 0 , & V_9 , V_8 , - 1 ) ;
break;
case V_26 :
F_10 ( FALSE , V_1 , 0 , & V_9 , V_8 , - 1 ) ;
break;
default:
;
}
return F_11 ( V_1 ) ;
}
void F_12 ( void ) {
static T_6 V_27 [] = {
{ & V_28 ,
{ L_3 , L_4 ,
V_29 , V_30 , NULL , 0 ,
NULL , V_31 } } ,
{ & V_32 ,
{ L_5 , L_6 ,
V_29 , V_30 , NULL , 0 ,
NULL , V_31 } } ,
{ & V_33 ,
{ L_7 , L_8 ,
V_29 , V_30 , NULL , 0 ,
NULL , V_31 } } ,
{ & V_34 ,
{ L_9 , L_10 ,
V_29 , V_30 , NULL , 0 ,
NULL , V_31 } } ,
{ & V_35 ,
{ L_11 , L_12 ,
V_36 , V_37 , NULL , 0 ,
NULL , V_31 } } ,
{ & V_38 ,
{ L_13 , L_14 ,
V_36 , V_37 , NULL , 0 ,
NULL , V_31 } } ,
{ & V_39 ,
{ L_15 , L_16 ,
V_29 , V_30 , NULL , 0 ,
NULL , V_31 } } ,
{ & V_40 ,
{ L_17 , L_18 ,
V_36 , V_37 , F_13 ( V_41 ) , 0 ,
NULL , V_31 } } ,
#include "packet-cmip-hfarr.c"
} ;
static T_7 * V_42 [] = {
& V_16 ,
#include "packet-cmip-ettarr.c"
} ;
static T_8 V_43 [] = {
{ & V_12 , { L_19 , V_44 , V_45 , L_20 , V_46 } } ,
} ;
T_9 * V_47 ;
V_14 = F_14 ( V_48 , V_49 , V_50 ) ;
V_51 = F_15 ( L_21 , F_1 , V_14 ) ;
F_16 ( V_14 , V_27 , F_17 ( V_27 ) ) ;
F_18 ( V_42 , F_17 ( V_42 ) ) ;
V_47 = F_19 ( V_14 ) ;
F_20 ( V_47 , V_43 , F_17 ( V_43 ) ) ;
#include "packet-cmip-dis-tab.c"
F_21 ( L_22 , L_23 ) ;
V_52 = F_22 ( L_24 , L_25 , V_14 , V_36 , V_37 ) ;
}
void F_23 ( void ) {
F_24 ( L_26 , V_51 , V_14 , L_21 ) ;
F_24 ( L_27 , V_51 , V_14 , L_28 ) ;
F_21 ( L_29 , L_30 ) ;
F_21 ( L_31 , L_32 ) ;
F_21 ( L_33 , L_34 ) ;
F_21 ( L_35 , L_36 ) ;
F_21 ( L_37 , L_38 ) ;
F_21 ( L_39 , L_40 ) ;
F_21 ( L_41 , L_42 ) ;
F_21 ( L_43 , L_44 ) ;
F_21 ( L_45 , L_46 ) ;
F_21 ( L_47 , L_48 ) ;
F_21 ( L_49 , L_50 ) ;
F_21 ( L_51 , L_52 ) ;
F_21 ( L_53 , L_54 ) ;
F_21 ( L_55 , L_56 ) ;
F_21 ( L_57 , L_58 ) ;
F_21 ( L_27 , L_28 ) ;
}
