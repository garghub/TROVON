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
static void
F_13 ( void ) {
V_36 = F_14 ( F_1 ,
NULL ,
F_3 ,
F_4 ) ;
V_37 = F_14 ( F_1 ,
NULL ,
NULL ,
F_4 ) ;
}
static void
F_15 ( void ) {
F_16 ( V_36 ) ;
F_16 ( V_37 ) ;
}
void F_17 ( void ) {
static T_10 V_38 [] = {
#include "packet-rrc-hfarr.c"
{ & V_39 ,
{ L_2 , L_3 ,
V_40 , V_41 , NULL , 0 ,
L_4 , V_42 } } ,
{ & V_43 ,
{ L_5 , L_6 ,
V_44 , V_45 , F_18 ( & V_46 ) , 0 ,
L_7 , V_42 } } ,
{ & V_47 ,
{ L_8 , L_9 ,
V_44 , V_45 , F_18 ( & V_48 ) , 0 ,
L_10 , V_42 } } ,
{ & V_49 ,
{ L_11 , L_12 ,
V_44 , V_45 , F_18 ( & V_50 ) , 0 ,
L_13 , V_42 } } ,
{ & V_51 ,
{ L_14 , L_15 ,
V_44 , V_45 , F_18 ( & V_52 ) , 0 ,
L_16 , V_42 } } ,
{ & V_53 ,
{ L_17 , L_18 ,
V_40 , V_41 , F_19 ( V_54 ) , 0x3 ,
L_19 , V_42 } } ,
{ & V_55 ,
{ L_20 , L_21 ,
V_56 , V_41 , NULL , 0x0 ,
L_22 , V_42 } } ,
{ & V_57 ,
{ L_23 , L_24 ,
V_58 , V_45 , NULL , 0x0 ,
L_25 , V_42 } } ,
{ & V_59 ,
{ L_26 , L_27 ,
V_60 , V_45 , NULL , 0x0 ,
L_28 , V_42 } } ,
} ;
static T_1 * V_61 [] = {
& V_20 ,
#include "packet-rrc-ettarr.c"
& V_62 ,
& V_63 ,
& V_64 ,
} ;
static T_11 V_65 [] = {
{ & V_66 , { L_29 , V_67 , V_68 , L_30 , V_69 } } ,
} ;
T_12 * V_70 ;
V_13 = F_20 ( V_71 , V_72 , V_73 ) ;
F_21 ( V_13 , V_38 , F_22 ( V_38 ) ) ;
F_23 ( V_61 , F_22 ( V_61 ) ) ;
V_70 = F_24 ( V_13 ) ;
F_25 ( V_70 , V_65 , F_22 ( V_65 ) ) ;
F_26 ( L_31 , F_6 , V_13 ) ;
#include "packet-rrc-dis-reg.c"
F_27 ( F_13 ) ;
F_28 ( F_15 ) ;
}
void
F_29 ( void )
{
V_74 = F_30 ( L_32 ) ;
V_25 = F_30 ( L_33 ) ;
V_27 = F_30 ( L_34 ) ;
V_29 = F_30 ( L_35 ) ;
V_31 = F_30 ( L_36 ) ;
V_33 = F_30 ( L_37 ) ;
V_75 = F_30 ( L_38 ) ;
V_33 = F_30 ( L_37 ) ;
V_76 = F_30 ( L_39 ) ;
V_77 = F_30 ( L_40 ) ;
V_35 = F_30 ( L_41 ) ;
V_78 = F_30 ( L_42 ) ;
}
