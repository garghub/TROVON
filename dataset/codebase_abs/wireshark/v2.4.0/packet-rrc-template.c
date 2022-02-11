static T_1 * F_1 ( T_2 * V_1 )
{
if ( V_1 -> V_2 != NULL ) {
return ( T_1 * ) V_1 -> V_2 ;
}
else {
T_1 * V_3 = F_2 ( F_3 () , T_1 ) ;
V_1 -> V_2 = V_3 ;
return V_3 ;
}
}
static T_3 F_4 ( T_2 * V_1 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
return V_2 -> V_4 ;
}
static void F_5 ( T_2 * V_1 , T_3 V_4 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
V_2 -> V_4 = V_4 ;
}
static T_3 F_6 ( T_2 * V_1 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
return V_2 -> V_5 ;
}
static void F_7 ( T_2 * V_1 , T_3 V_5 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
V_2 -> V_5 = V_5 ;
}
static T_3 F_8 ( T_2 * V_1 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
return V_2 -> V_6 ;
}
static void F_9 ( T_2 * V_1 , T_3 V_6 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
V_2 -> V_6 = V_6 ;
}
static T_3 F_10 ( T_2 * V_1 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
return V_2 -> V_7 ;
}
static void F_11 ( T_2 * V_1 , T_3 V_7 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
V_2 -> V_7 = V_7 ;
}
static T_3 F_12 ( T_2 * V_1 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
return V_2 -> V_8 ;
}
static void F_13 ( T_2 * V_1 , T_3 V_8 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
V_2 -> V_8 = V_8 ;
}
static enum V_9 F_14 ( T_2 * V_1 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
return V_2 -> V_10 ;
}
static void F_15 ( T_2 * V_1 , enum V_9 V_10 )
{
T_1 * V_2 = ( T_1 * ) F_1 ( V_1 ) ;
V_2 -> V_10 = V_10 ;
}
static T_4 F_16 ( T_5 V_11 , T_5 V_12 , T_6 T_7 V_13 ) {
if( F_17 ( V_12 ) > F_17 ( V_11 ) ) {
return - 1 ;
}
return F_17 ( V_12 ) < F_17 ( V_11 ) ;
}
static void F_18 ( T_6 T_8 V_13 ) {
}
static void F_19 ( T_6 V_14 ) {
F_20 ( V_14 ) ;
}
static int
F_21 ( T_9 * V_15 , T_10 * V_16 , T_11 * V_17 , void * T_12 V_13 )
{
T_13 * V_18 = NULL ;
T_11 * V_19 = NULL ;
struct V_20 * V_21 ;
V_22 = V_17 ;
V_21 = (struct V_20 * ) F_22 ( F_23 () , V_16 , V_23 , 0 ) ;
F_24 ( V_16 -> V_24 , V_25 , L_1 ) ;
memset ( V_26 , 0 , sizeof( V_27 ) * V_28 ) ;
V_18 = F_25 ( V_17 , V_23 , V_15 , 0 , - 1 , V_29 ) ;
V_19 = F_26 ( V_18 , V_30 ) ;
if ( V_21 ) {
switch ( V_21 -> V_31 [ V_16 -> V_32 -> V_33 ] ) {
case V_34 :
F_27 ( V_35 , V_15 , V_16 , V_19 ) ;
break;
case V_36 :
F_27 ( V_37 , V_15 , V_16 , V_19 ) ;
break;
case V_38 :
F_27 ( V_39 , V_15 , V_16 , V_19 ) ;
break;
case V_40 :
F_27 ( V_41 , V_15 , V_16 , V_19 ) ;
break;
case V_42 :
F_27 ( V_43 , V_15 , V_16 , V_19 ) ;
break;
case V_44 :
F_27 ( V_45 , V_15 , V_16 , V_19 ) ;
break;
default:
;
}
}
return F_28 ( V_15 ) ;
}
static void
F_29 ( void ) {
V_46 = F_30 ( F_16 ,
NULL ,
F_18 ,
F_19 ) ;
V_47 = F_30 ( F_16 ,
NULL ,
NULL ,
F_19 ) ;
V_48 = F_30 ( F_16 ,
NULL ,
NULL ,
NULL ) ;
V_49 = F_31 ( F_32 () , F_23 () ) ;
}
static void
F_33 ( void ) {
F_34 ( V_46 ) ;
F_34 ( V_47 ) ;
}
void F_35 ( void ) {
static T_14 V_50 [] = {
#include "packet-rrc-hfarr.c"
{ & V_51 ,
{ L_2 , L_3 ,
V_52 , V_53 , NULL , 0 ,
L_4 , V_54 } } ,
{ & V_55 ,
{ L_5 , L_6 ,
V_56 , V_57 , F_36 ( & V_58 ) , 0 ,
L_7 , V_54 } } ,
{ & V_59 ,
{ L_8 , L_9 ,
V_56 , V_57 , F_36 ( & V_60 ) , 0 ,
L_10 , V_54 } } ,
{ & V_61 ,
{ L_11 , L_12 ,
V_56 , V_57 , F_36 ( & V_62 ) , 0 ,
L_13 , V_54 } } ,
{ & V_63 ,
{ L_14 , L_15 ,
V_56 , V_57 , F_36 ( & V_64 ) , 0 ,
L_16 , V_54 } } ,
{ & V_65 ,
{ L_17 , L_18 ,
V_52 , V_53 , F_37 ( V_66 ) , 0x3 ,
L_19 , V_54 } } ,
{ & V_67 ,
{ L_20 , L_21 ,
V_68 , V_53 , NULL , 0x0 ,
L_22 , V_54 } } ,
{ & V_69 ,
{ L_23 , L_24 ,
V_70 , V_57 , NULL , 0x0 ,
L_25 , V_54 } } ,
{ & V_71 ,
{ L_26 , L_27 ,
V_72 , V_57 , NULL , 0x0 ,
L_28 , V_54 } } ,
{ & V_73 ,
{ L_29 , L_30 ,
V_74 , V_53 , NULL , 0 ,
L_31 , V_54 } } ,
{ & V_75 ,
{ L_32 , L_33 ,
V_74 , V_53 , NULL , 0 ,
L_34 , V_54 } }
} ;
static T_4 * V_76 [] = {
& V_30 ,
#include "packet-rrc-ettarr.c"
& V_77 ,
& V_78 ,
& V_79 ,
& V_80 ,
} ;
static T_15 V_81 [] = {
{ & V_82 , { L_35 , V_83 , V_84 , L_36 , V_85 } } ,
} ;
T_16 * V_86 ;
V_23 = F_38 ( V_87 , V_88 , V_89 ) ;
F_39 ( V_23 , V_50 , F_40 ( V_50 ) ) ;
F_41 ( V_76 , F_40 ( V_76 ) ) ;
V_86 = F_42 ( V_23 ) ;
F_43 ( V_86 , V_81 , F_40 ( V_81 ) ) ;
F_44 ( L_37 , F_21 , V_23 ) ;
#include "packet-rrc-dis-reg.c"
F_45 ( F_29 ) ;
F_46 ( F_33 ) ;
}
void
F_47 ( void )
{
V_90 = F_48 ( L_38 , V_23 ) ;
V_35 = F_49 ( L_39 ) ;
V_37 = F_49 ( L_40 ) ;
V_39 = F_49 ( L_41 ) ;
V_41 = F_49 ( L_42 ) ;
V_43 = F_49 ( L_43 ) ;
V_91 = F_49 ( L_44 ) ;
V_43 = F_49 ( L_43 ) ;
V_92 = F_48 ( L_45 , V_23 ) ;
V_93 = F_48 ( L_46 , V_23 ) ;
V_45 = F_49 ( L_47 ) ;
V_94 = F_48 ( L_48 , V_23 ) ;
}
