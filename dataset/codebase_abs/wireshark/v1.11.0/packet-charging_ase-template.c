static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 ;
T_3 * V_5 ;
V_4 = F_2 ( V_3 , V_6 , V_1 , 0 , F_3 ( V_1 ) , L_1 ) ;
V_5 = F_4 ( V_4 , V_7 ) ;
if( F_3 ( V_1 ) > 0 )
{
F_5 ( V_1 , V_2 , V_5 , NULL ) ;
}
}
void
F_6 ( void )
{
static T_5 V_8 [] = {
#include "packet-charging_ase-hfarr.c"
} ;
static T_6 * V_9 [] = {
& V_7 ,
#include "packet-charging_ase-ettarr.c"
} ;
V_6 = F_7 ( V_10 , V_11 , V_12 ) ;
F_8 ( V_6 , V_8 , F_9 ( V_8 ) ) ;
F_10 ( V_9 , F_9 ( V_9 ) ) ;
}
void
F_11 ( void )
{
V_13 = F_12 ( F_1 , V_6 ) ;
}
