static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 = NULL ;
T_3 * V_5 = NULL ;
struct V_6 * V_7 ;
V_8 = V_3 ;
V_7 = F_2 ( V_2 -> V_9 , V_10 ) ;
F_3 ( V_2 -> V_11 , V_12 , L_1 ) ;
V_4 = F_4 ( V_3 , V_10 , V_1 , 0 , - 1 , V_13 ) ;
V_5 = F_5 ( V_4 , V_14 ) ;
if ( V_7 ) {
switch ( V_7 -> V_15 [ V_2 -> V_9 -> V_16 ] ) {
case V_17 :
F_6 ( V_18 , V_1 , V_2 , V_5 ) ;
break;
case V_19 :
F_6 ( V_20 , V_1 , V_2 , V_5 ) ;
break;
case V_21 :
F_6 ( V_22 , V_1 , V_2 , V_5 ) ;
break;
case V_23 :
F_6 ( V_24 , V_1 , V_2 , V_5 ) ;
break;
case V_25 :
F_6 ( V_26 , V_1 , V_2 , V_5 ) ;
break;
default:
;
}
}
}
void F_7 ( void ) {
static T_5 V_27 [] = {
#include "packet-rrc-hfarr.c"
{ & V_28 ,
{ L_2 , L_3 ,
V_29 , V_30 , NULL , 0 ,
L_4 , V_31 } } ,
{ & V_32 ,
{ L_5 , L_6 ,
V_33 , V_34 , F_8 ( & V_35 ) , 0 ,
L_7 , V_31 } } ,
{ & V_36 ,
{ L_8 , L_9 ,
V_33 , V_34 , F_8 ( & V_37 ) , 0 ,
L_10 , V_31 } } ,
{ & V_38 ,
{ L_11 , L_12 ,
V_33 , V_34 , F_8 ( & V_39 ) , 0 ,
L_13 , V_31 } } ,
{ & V_40 ,
{ L_14 , L_15 ,
V_33 , V_34 , F_8 ( & V_41 ) , 0 ,
L_16 , V_31 } } ,
} ;
static T_6 * V_42 [] = {
& V_14 ,
#include "packet-rrc-ettarr.c"
& V_43 ,
& V_44 ,
} ;
V_10 = F_9 ( V_45 , V_46 , V_47 ) ;
F_10 ( V_10 , V_27 , F_11 ( V_27 ) ) ;
F_12 ( V_42 , F_11 ( V_42 ) ) ;
F_13 ( L_17 , F_1 , V_10 ) ;
#include "packet-rrc-dis-reg.c"
}
void
F_14 ( void )
{
V_48 = F_15 ( L_18 ) ;
V_18 = F_15 ( L_19 ) ;
V_20 = F_15 ( L_20 ) ;
V_22 = F_15 ( L_21 ) ;
V_24 = F_15 ( L_22 ) ;
V_26 = F_15 ( L_23 ) ;
V_49 = F_15 ( L_24 ) ;
V_26 = F_15 ( L_23 ) ;
V_50 = F_15 ( L_25 ) ;
V_51 = F_15 ( L_26 ) ;
}
