static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
T_4 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_5 V_7 ;
F_2 ( & V_7 , V_8 , TRUE , V_2 ) ;
if( V_3 ) {
V_5 = F_3 ( V_3 , V_9 , V_1 , 0 , - 1 , V_10 ) ;
V_6 = F_4 ( V_5 , V_11 ) ;
}
F_5 ( V_2 -> V_12 , V_13 , L_1 ) ;
F_5 ( V_2 -> V_12 , V_14 , L_2 ) ;
F_6 ( TRUE , V_1 , V_4 , & V_7 , V_6 , - 1 ) ;
}
void F_7 ( void ) {
static T_6 V_15 [] =
{
#include "packet-p22-hfarr.c"
} ;
static T_7 * V_16 [] = {
& V_11 ,
#include "packet-p22-ettarr.c"
} ;
V_9 = F_8 ( V_17 , V_18 , V_19 ) ;
F_9 ( L_3 , F_1 , V_9 ) ;
F_10 ( V_9 , V_15 , F_11 ( V_15 ) ) ;
F_12 ( V_16 , F_11 ( V_16 ) ) ;
}
void F_13 ( void ) {
#include "packet-p22-dis-tab.c"
F_14 ( L_4 , F_1 , V_9 , L_5 ) ;
F_14 ( L_6 , F_1 , V_9 , L_7 ) ;
}
