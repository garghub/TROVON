static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
int V_5 = 0 ;
T_5 * V_6 = NULL ;
T_3 * V_7 = NULL ;
T_6 V_8 ;
F_2 ( & V_8 , V_9 , TRUE , V_2 ) ;
if ( V_3 ) {
V_6 = F_3 ( V_3 , V_10 , V_1 , 0 , - 1 , V_11 ) ;
V_7 = F_4 ( V_6 , V_12 ) ;
}
F_5 ( V_2 -> V_13 , V_14 , L_1 ) ;
F_5 ( V_2 -> V_13 , V_15 , L_2 ) ;
F_6 ( TRUE , V_1 , V_5 , & V_8 , V_7 , - 1 ) ;
return F_7 ( V_1 ) ;
}
void F_8 ( void ) {
static T_7 V_16 [] =
{
#include "packet-p22-hfarr.c"
} ;
static T_8 * V_17 [] = {
& V_12 ,
#include "packet-p22-ettarr.c"
} ;
V_10 = F_9 ( V_18 , V_19 , V_20 ) ;
F_10 ( L_3 , F_1 , V_10 ) ;
F_11 ( V_10 , V_16 , F_12 ( V_16 ) ) ;
F_13 ( V_17 , F_12 ( V_17 ) ) ;
}
void F_14 ( void ) {
#include "packet-p22-dis-tab.c"
F_15 ( L_4 , F_1 , V_10 , L_5 ) ;
F_15 ( L_6 , F_1 , V_10 , L_7 ) ;
}
