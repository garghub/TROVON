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
if ( F_9 ( V_2 -> V_14 , V_15 ) )
F_10 ( V_2 -> V_14 , V_15 , V_16 ) ;
if ( V_3 ) {
V_12 = F_11 ( V_3 , V_17 , V_1 , 0 , - 1 , V_18 ) ;
V_13 = F_12 ( V_12 , V_19 ) ;
F_13 ( V_1 , V_2 , V_13 ) ;
}
}
void F_14 ( void ) {
static T_5 V_20 [] = {
#include "packet-sbc-ap-hfarr.c"
} ;
static T_6 * V_21 [] = {
& V_19 ,
#include "packet-sbc-ap-ettarr.c"
} ;
V_17 = F_15 ( V_16 , V_22 , V_23 ) ;
F_16 ( V_17 , V_20 , F_17 ( V_20 ) ) ;
F_18 ( V_21 , F_17 ( V_21 ) ) ;
V_4 = F_19 ( L_1 , L_2 , V_24 , V_25 ) ;
V_6 = F_19 ( L_3 , L_4 , V_24 , V_25 ) ;
V_8 = F_19 ( L_5 , L_6 , V_24 , V_25 ) ;
V_10 = F_19 ( L_7 , L_8 , V_24 , V_25 ) ;
V_11 = F_19 ( L_9 , L_10 , V_24 , V_25 ) ;
}
void
F_20 ( void )
{
static T_7 V_26 = FALSE ;
static T_8 V_27 ;
if( ! V_26 ) {
V_28 = F_21 ( F_8 , V_17 ) ;
F_22 ( L_11 , V_29 , V_28 ) ;
V_26 = TRUE ;
#include "packet-sbc-ap-dis-tab.c"
} else {
if ( V_27 != 0 ) {
F_23 ( L_12 , V_27 , V_28 ) ;
}
}
V_27 = V_30 ;
if ( V_27 != 0 ) {
F_22 ( L_12 , V_27 , V_28 ) ;
}
}
