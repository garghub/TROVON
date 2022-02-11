static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_4 , V_5 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
return ( F_2 ( V_6 , V_5 , V_1 , V_2 , V_3 , FALSE ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_5 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
if ( ! V_7 ) return 0 ;
return ( F_6 ( V_8 , V_7 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_7 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
if ( ! V_7 ) return 0 ;
return ( F_6 ( V_9 , V_7 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static int F_8 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
if ( ! V_7 ) return 0 ;
return ( F_6 ( V_10 , V_7 , V_1 , V_2 , V_3 ) ) ? F_3 ( V_1 ) : 0 ;
}
static void
F_9 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_11 = NULL ;
T_3 * V_12 = NULL ;
F_10 ( V_2 -> V_13 , V_14 , L_1 ) ;
V_11 = F_11 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_12 = F_12 ( V_11 , V_17 ) ;
F_13 ( V_1 , V_2 , V_12 ) ;
}
void F_14 ( void ) {
static T_5 V_18 [] = {
{ & V_19 ,
{ L_2 , L_3 ,
V_20 , V_21 , NULL , 0 ,
NULL , V_22 } } ,
{ & V_23 ,
{ L_4 , L_5 ,
V_24 , V_21 , NULL , 0 ,
NULL , V_22 } } ,
{ & V_25 ,
{ L_6 , L_7 ,
V_26 , V_21 , NULL , 0 ,
NULL , V_22 } } ,
#include "packet-nbap-hfarr.c"
} ;
static T_6 * V_27 [] = {
& V_17 ,
& V_28 ,
& V_29 ,
& V_30 ,
#include "packet-nbap-ettarr.c"
} ;
V_15 = F_15 ( V_31 , V_32 , V_33 ) ;
F_16 ( V_15 , V_18 , F_17 ( V_18 ) ) ;
F_18 ( V_27 , F_17 ( V_27 ) ) ;
F_19 ( L_8 , F_9 , V_15 ) ;
V_4 = F_20 ( L_9 , L_10 , V_34 , V_35 ) ;
V_6 = F_20 ( L_11 , L_12 , V_34 , V_35 ) ;
V_8 = F_20 ( L_13 , L_14 , V_36 , V_21 ) ;
V_9 = F_20 ( L_15 , L_16 , V_36 , V_21 ) ;
V_10 = F_20 ( L_17 , L_18 , V_36 , V_21 ) ;
}
void
F_21 ( void )
{
T_7 V_37 ;
V_37 = F_22 ( L_8 ) ;
V_38 = F_22 ( L_19 ) ;
F_23 ( L_20 , V_39 , V_37 ) ;
F_24 ( L_21 , V_37 ) ;
#include "packet-nbap-dis-tab.c"
}
