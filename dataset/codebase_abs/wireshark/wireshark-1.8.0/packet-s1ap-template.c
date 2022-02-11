static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_4 , V_5 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_6 , V_7 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_5 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_8 , V_9 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_10 , V_9 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_11 , V_9 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static void
F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_12 = NULL ;
T_3 * V_13 = NULL ;
F_9 ( V_2 -> V_14 , V_15 , L_1 ) ;
V_12 = F_10 ( V_3 , V_16 , V_1 , 0 , - 1 , V_17 ) ;
V_13 = F_11 ( V_12 , V_18 ) ;
F_12 ( V_1 , V_2 , V_13 ) ;
}
void
F_13 ( void )
{
static T_5 V_19 = FALSE ;
static T_6 V_20 ;
static T_7 V_21 ;
V_20 = F_14 ( L_2 ) ;
if ( ! V_19 ) {
V_22 = F_14 ( L_3 ) ;
V_23 = F_14 ( L_4 ) ;
V_24 = F_14 ( L_5 ) ;
F_15 ( L_6 , V_20 ) ;
F_16 ( L_7 , V_25 , V_20 ) ;
V_19 = TRUE ;
#include "packet-s1ap-dis-tab.c"
} else {
if ( V_21 != 0 ) {
F_17 ( L_6 , V_21 , V_20 ) ;
}
}
V_21 = V_26 ;
if ( V_21 != 0 ) {
F_16 ( L_6 , V_21 , V_20 ) ;
}
}
void F_18 ( void ) {
static T_8 V_27 [] = {
{ & V_28 ,
{ L_8 , L_9 ,
V_29 , V_30 , NULL , 0 ,
NULL , V_31 } } ,
{ & V_32 ,
{ L_10 , L_11 ,
V_33 , V_30 , NULL , 0 ,
NULL , V_31 } } ,
#include "packet-s1ap-hfarr.c"
} ;
static T_9 * V_34 [] = {
& V_18 ,
& V_35 ,
& V_36 ,
& V_37 ,
& V_38 ,
& V_39 ,
& V_40 ,
#include "packet-s1ap-ettarr.c"
} ;
T_10 * V_41 ;
V_16 = F_19 ( V_42 , V_43 , V_44 ) ;
F_20 ( V_16 , V_27 , F_21 ( V_27 ) ) ;
F_22 ( V_34 , F_21 ( V_34 ) ) ;
F_23 ( L_2 , F_8 , V_16 ) ;
V_4 = F_24 ( L_12 , L_13 , V_45 , V_46 ) ;
V_47 = F_24 ( L_14 , L_15 , V_45 , V_46 ) ;
V_48 = F_24 ( L_16 , L_17 , V_45 , V_46 ) ;
V_6 = F_24 ( L_18 , L_19 , V_45 , V_46 ) ;
V_8 = F_24 ( L_20 , L_21 , V_45 , V_46 ) ;
V_10 = F_24 ( L_22 , L_23 , V_45 , V_46 ) ;
V_11 = F_24 ( L_24 , L_25 , V_45 , V_46 ) ;
V_41 = F_25 ( V_16 , F_13 ) ;
F_26 ( V_41 , L_6 ,
L_26 ,
L_27 ,
10 ,
& V_26 ) ;
F_27 ( V_41 , L_28 , L_29 , L_30 , & V_49 ) ;
}
