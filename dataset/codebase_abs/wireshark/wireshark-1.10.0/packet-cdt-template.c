void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 = NULL ;
V_5 = V_3 ;
if ( V_3 ) {
V_6 = F_2 ( V_3 , V_7 , V_1 , 0 , - 1 , V_8 ) ;
V_4 = F_3 ( V_6 , V_9 ) ;
}
F_4 ( V_2 -> V_10 , V_11 , L_1 ) ;
F_5 ( V_2 -> V_10 , V_12 ) ;
F_6 ( V_1 , V_2 , V_4 ) ;
}
void F_7 ( void ) {
static T_4 V_13 [] = {
#include "packet-cdt-hfarr.c"
} ;
static T_5 * V_14 [] = {
#include "packet-cdt-ettarr.c"
} ;
V_7 = F_8 ( V_15 , V_16 , V_17 ) ;
F_9 ( V_7 , V_13 , F_10 ( V_13 ) ) ;
F_11 ( V_14 , F_10 ( V_14 ) ) ;
}
void F_12 ( void ) {
#include "packet-cdt-dis-tab.c"
V_18 = F_13 ( L_2 ) ;
}
