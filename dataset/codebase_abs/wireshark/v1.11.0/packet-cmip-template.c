static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
static struct V_4 * V_5 ;
T_4 * V_6 = NULL ;
T_3 * V_7 = NULL ;
T_5 V_8 ;
F_2 ( & V_8 , V_9 , TRUE , V_2 ) ;
V_5 = (struct V_4 * ) V_2 -> V_10 ;
if( ! V_5 ) {
F_3 ( V_7 , V_1 , 0 , - 1 ,
L_1 ) ;
return;
} else {
if( V_5 -> V_11 == 0 ) {
F_3 ( V_7 , V_1 , 0 , - 1 ,
L_2 , V_5 -> V_11 ) ;
return;
}
}
if( V_3 ) {
V_6 = F_4 ( V_3 , V_12 , V_1 , 0 , - 1 , V_13 ) ;
V_7 = F_5 ( V_6 , V_14 ) ;
}
F_6 ( V_2 -> V_15 , V_16 , L_3 ) ;
F_7 ( V_2 -> V_15 , V_17 ) ;
switch( V_5 -> V_11 ) {
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_8 ( FALSE , V_1 , 0 , & V_8 , V_7 , - 1 ) ;
break;
case V_23 :
F_9 ( FALSE , V_1 , 0 , & V_8 , V_7 , - 1 ) ;
break;
case V_24 :
F_10 ( FALSE , V_1 , 0 , & V_8 , V_7 , - 1 ) ;
break;
default:
;
}
}
void F_11 ( void ) {
static T_6 V_25 [] = {
{ & V_26 ,
{ L_4 , L_5 ,
V_27 , V_28 , NULL , 0 ,
NULL , V_29 } } ,
{ & V_30 ,
{ L_6 , L_7 ,
V_27 , V_28 , NULL , 0 ,
NULL , V_29 } } ,
{ & V_31 ,
{ L_8 , L_9 ,
V_27 , V_28 , NULL , 0 ,
NULL , V_29 } } ,
{ & V_32 ,
{ L_10 , L_11 ,
V_27 , V_28 , NULL , 0 ,
NULL , V_29 } } ,
{ & V_33 ,
{ L_12 , L_13 ,
V_34 , V_35 , NULL , 0 ,
NULL , V_29 } } ,
{ & V_36 ,
{ L_14 , L_15 ,
V_34 , V_35 , NULL , 0 ,
NULL , V_29 } } ,
{ & V_37 ,
{ L_16 , L_17 ,
V_27 , V_28 , NULL , 0 ,
NULL , V_29 } } ,
{ & V_38 ,
{ L_18 , L_19 ,
V_34 , V_35 , F_12 ( V_39 ) , 0 ,
NULL , V_29 } } ,
#include "packet-cmip-hfarr.c"
} ;
static T_7 * V_40 [] = {
& V_14 ,
#include "packet-cmip-ettarr.c"
} ;
V_12 = F_13 ( V_41 , V_42 , V_43 ) ;
F_14 ( V_12 , V_25 , F_15 ( V_25 ) ) ;
F_16 ( V_40 , F_15 ( V_40 ) ) ;
#include "packet-cmip-dis-tab.c"
F_17 ( L_20 , L_21 ) ;
V_44 = F_18 ( L_22 , L_23 , V_34 , V_35 ) ;
}
void F_19 ( void ) {
F_20 ( L_24 , F_1 , V_12 , L_25 ) ;
F_20 ( L_26 , F_1 , V_12 , L_27 ) ;
F_17 ( L_28 , L_29 ) ;
F_17 ( L_30 , L_31 ) ;
F_17 ( L_32 , L_33 ) ;
F_17 ( L_34 , L_35 ) ;
F_17 ( L_36 , L_37 ) ;
F_17 ( L_38 , L_39 ) ;
F_17 ( L_40 , L_41 ) ;
F_17 ( L_42 , L_43 ) ;
F_17 ( L_44 , L_45 ) ;
F_17 ( L_46 , L_47 ) ;
F_17 ( L_48 , L_49 ) ;
F_17 ( L_50 , L_51 ) ;
F_17 ( L_52 , L_53 ) ;
F_17 ( L_54 , L_55 ) ;
F_17 ( L_56 , L_57 ) ;
F_17 ( L_26 , L_27 ) ;
}
