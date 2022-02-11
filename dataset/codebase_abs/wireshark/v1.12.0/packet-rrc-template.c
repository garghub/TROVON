static T_1 F_1 ( T_2 V_1 , T_2 V_2 , T_3 T_4 V_3 ) {
if( F_2 ( V_2 ) > F_2 ( V_1 ) ) {
return - 1 ;
}
return F_2 ( V_2 ) < F_2 ( V_1 ) ;
}
static void F_3 ( T_3 T_5 V_3 ) {
}
static void F_4 ( T_3 V_4 ) {
F_5 ( V_4 ) ;
}
static void
F_6 ( T_6 * V_5 , T_7 * V_6 , T_8 * V_7 )
{
T_9 * V_8 = NULL ;
T_8 * V_9 = NULL ;
struct V_10 * V_11 ;
V_12 = V_7 ;
V_11 = (struct V_10 * ) F_7 ( F_8 () , V_6 , V_13 , 0 ) ;
F_9 ( V_6 -> V_14 , V_15 , L_1 ) ;
memset ( V_16 , 0 , sizeof( V_17 ) * V_18 ) ;
V_8 = F_10 ( V_7 , V_13 , V_5 , 0 , - 1 , V_19 ) ;
V_9 = F_11 ( V_8 , V_20 ) ;
if ( V_11 ) {
switch ( V_11 -> V_21 [ V_6 -> V_22 -> V_23 ] ) {
case V_24 :
F_12 ( V_25 , V_5 , V_6 , V_9 ) ;
break;
case V_26 :
F_12 ( V_27 , V_5 , V_6 , V_9 ) ;
break;
case V_28 :
F_12 ( V_29 , V_5 , V_6 , V_9 ) ;
break;
case V_30 :
F_12 ( V_31 , V_5 , V_6 , V_9 ) ;
break;
case V_32 :
F_12 ( V_33 , V_5 , V_6 , V_9 ) ;
break;
case V_34 :
F_12 ( V_35 , V_5 , V_6 , V_9 ) ;
break;
default:
;
}
}
}
static void F_13 ( void ) {
if( V_36 ) {
F_14 ( V_36 ) ;
}
if( V_37 ) {
F_14 ( V_37 ) ;
}
V_36 = F_15 ( F_1 ,
NULL ,
F_3 ,
F_4 ) ;
V_37 = F_15 ( F_1 ,
NULL ,
NULL ,
F_4 ) ;
}
void F_16 ( void ) {
static T_10 V_38 [] = {
#include "packet-rrc-hfarr.c"
{ & V_39 ,
{ L_2 , L_3 ,
V_40 , V_41 , NULL , 0 ,
L_4 , V_42 } } ,
{ & V_43 ,
{ L_5 , L_6 ,
V_44 , V_45 , F_17 ( & V_46 ) , 0 ,
L_7 , V_42 } } ,
{ & V_47 ,
{ L_8 , L_9 ,
V_44 , V_45 , F_17 ( & V_48 ) , 0 ,
L_10 , V_42 } } ,
{ & V_49 ,
{ L_11 , L_12 ,
V_44 , V_45 , F_17 ( & V_50 ) , 0 ,
L_13 , V_42 } } ,
{ & V_51 ,
{ L_14 , L_15 ,
V_44 , V_45 , F_17 ( & V_52 ) , 0 ,
L_16 , V_42 } } ,
} ;
static T_1 * V_53 [] = {
& V_20 ,
#include "packet-rrc-ettarr.c"
& V_54 ,
& V_55 ,
} ;
static T_11 V_56 [] = {
{ & V_57 , { L_17 , V_58 , V_59 , L_18 , V_60 } } ,
} ;
T_12 * V_61 ;
V_13 = F_18 ( V_62 , V_63 , V_64 ) ;
F_19 ( V_13 , V_38 , F_20 ( V_38 ) ) ;
F_21 ( V_53 , F_20 ( V_53 ) ) ;
V_61 = F_22 ( V_13 ) ;
F_23 ( V_61 , V_56 , F_20 ( V_56 ) ) ;
F_24 ( L_19 , F_6 , V_13 ) ;
#include "packet-rrc-dis-reg.c"
F_25 ( F_13 ) ;
}
void
F_26 ( void )
{
V_65 = F_27 ( L_20 ) ;
V_25 = F_27 ( L_21 ) ;
V_27 = F_27 ( L_22 ) ;
V_29 = F_27 ( L_23 ) ;
V_31 = F_27 ( L_24 ) ;
V_33 = F_27 ( L_25 ) ;
V_66 = F_27 ( L_26 ) ;
V_33 = F_27 ( L_25 ) ;
V_67 = F_27 ( L_27 ) ;
V_68 = F_27 ( L_28 ) ;
V_35 = F_27 ( L_29 ) ;
V_69 = F_27 ( L_30 ) ;
}
