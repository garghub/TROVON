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
static T_4
F_8 ( T_2 * V_2 V_12 , T_1 * V_1 , int V_13 )
{
T_5 V_14 ;
int V_15 ;
T_6 V_16 ;
F_9 ( & V_16 , V_17 , TRUE , V_2 ) ;
V_13 = V_13 + 3 ;
V_15 = V_13 << 3 ;
F_10 ( V_1 , V_15 , & V_16 , NULL , - 1 , & V_14 ) ;
if ( V_14 < 128 )
return V_14 + 4 ;
return V_14 + 5 ;
}
static void
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_7 * V_18 = NULL ;
T_3 * V_19 = NULL ;
F_12 ( V_2 -> V_20 , V_21 , V_22 ) ;
V_18 = F_13 ( V_3 , V_23 , V_1 , 0 , - 1 , V_24 ) ;
V_19 = F_14 ( V_18 , V_25 ) ;
F_15 ( V_1 , V_2 , V_19 ) ;
}
static void
F_16 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
F_17 ( V_1 , V_2 , V_3 , V_26 , 5 ,
F_8 , F_11 ) ;
}
void F_18 ( void ) {
static T_8 V_27 [] = {
{ & V_28 ,
{ L_1 , L_2 ,
V_29 , V_30 , NULL , 0 ,
NULL , V_31 } } ,
#include "packet-sabp-hfarr.c"
} ;
static T_9 * V_32 [] = {
& V_25 ,
& V_33 ,
& V_34 ,
& V_35 ,
& V_36 ,
& V_37 ,
#include "packet-sabp-ettarr.c"
} ;
V_23 = F_19 ( V_38 , V_22 , V_39 ) ;
F_20 ( V_23 , V_27 , F_21 ( V_27 ) ) ;
F_22 ( V_32 , F_21 ( V_32 ) ) ;
F_23 ( L_3 , F_11 , V_23 ) ;
F_23 ( L_4 , F_16 , V_23 ) ;
V_4 = F_24 ( L_5 , L_6 , V_40 , V_30 ) ;
V_6 = F_24 ( L_7 , L_8 , V_40 , V_30 ) ;
V_8 = F_24 ( L_9 , L_10 , V_40 , V_30 ) ;
V_10 = F_24 ( L_11 , L_12 , V_40 , V_30 ) ;
V_11 = F_24 ( L_13 , L_14 , V_40 , V_30 ) ;
}
void
F_25 ( void )
{
T_10 V_41 ;
T_10 V_42 ;
V_41 = F_26 ( L_3 ) ;
V_42 = F_26 ( L_4 ) ;
F_27 ( L_15 , 3452 , V_41 ) ;
F_27 ( L_16 , 3452 , V_42 ) ;
F_27 ( L_17 , V_43 , V_41 ) ;
#include "packet-sabp-dis-tab.c"
}
