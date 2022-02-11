static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_5 , V_6 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_7 , V_8 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_5 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_9 , V_10 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_11 , V_10 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
return ( F_2 ( V_12 , V_10 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static void
F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_5 * V_13 = NULL ;
T_3 * V_14 = NULL ;
F_9 ( V_2 -> V_15 , V_16 , L_1 ) ;
V_13 = F_10 ( V_3 , V_17 , V_1 , 0 , - 1 , V_18 ) ;
V_14 = F_11 ( V_13 , V_19 ) ;
F_12 ( V_1 , V_2 , V_14 , NULL ) ;
}
void
F_13 ( void )
{
static T_6 V_20 = FALSE ;
static T_7 V_21 ;
static T_8 V_22 ;
V_21 = F_14 ( L_2 ) ;
if ( ! V_20 ) {
V_23 = F_14 ( L_3 ) ;
V_24 = F_14 ( L_4 ) ;
V_25 = F_14 ( L_5 ) ;
F_15 ( L_6 , V_21 ) ;
F_16 ( L_7 , V_26 , V_21 ) ;
V_20 = TRUE ;
#include "packet-s1ap-dis-tab.c"
} else {
if ( V_22 != 0 ) {
F_17 ( L_6 , V_22 , V_21 ) ;
}
}
V_22 = V_27 ;
if ( V_22 != 0 ) {
F_16 ( L_6 , V_22 , V_21 ) ;
}
}
void F_18 ( void ) {
static T_9 V_28 [] = {
{ & V_29 ,
{ L_8 , L_9 ,
V_30 , V_31 , NULL , 0 ,
NULL , V_32 } } ,
{ & V_33 ,
{ L_10 , L_11 ,
V_34 , V_31 , NULL , 0 ,
NULL , V_32 } } ,
#include "packet-s1ap-hfarr.c"
} ;
static T_10 * V_35 [] = {
& V_19 ,
& V_36 ,
& V_37 ,
& V_38 ,
& V_39 ,
& V_40 ,
& V_41 ,
#include "packet-s1ap-ettarr.c"
} ;
T_11 * V_42 ;
V_17 = F_19 ( V_43 , V_44 , V_45 ) ;
F_20 ( V_17 , V_28 , F_21 ( V_28 ) ) ;
F_22 ( V_35 , F_21 ( V_35 ) ) ;
F_23 ( L_2 , F_8 , V_17 ) ;
V_5 = F_24 ( L_12 , L_13 , V_46 , V_47 ) ;
V_48 = F_24 ( L_14 , L_15 , V_46 , V_47 ) ;
V_49 = F_24 ( L_16 , L_17 , V_46 , V_47 ) ;
V_7 = F_24 ( L_18 , L_19 , V_46 , V_47 ) ;
V_9 = F_24 ( L_20 , L_21 , V_46 , V_47 ) ;
V_11 = F_24 ( L_22 , L_23 , V_46 , V_47 ) ;
V_12 = F_24 ( L_24 , L_25 , V_46 , V_47 ) ;
V_42 = F_25 ( V_17 , F_13 ) ;
F_26 ( V_42 , L_6 ,
L_26 ,
L_27 ,
10 ,
& V_27 ) ;
F_27 ( V_42 , L_28 , L_29 , L_30 , & V_50 ) ;
}
