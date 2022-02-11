static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 ) {
if ( V_4 == NULL )
return 0 ;
V_5 = F_2 ( V_4 ) ;
F_3 ( V_5 ) ;
return F_4 ( V_1 , V_2 , V_3 , NULL ) ;
}
void F_5 ( void ) {
static T_4 V_6 [] = {
#include "packet-q932-ros-hfarr.c"
} ;
static T_5 * V_7 [] = {
#include "packet-q932-ros-ettarr.c"
} ;
static T_6 V_8 [] = {
{ & V_9 , { L_1 , V_10 , V_11 , L_2 , V_12 } } ,
} ;
T_7 * V_13 ;
V_14 = F_6 ( V_15 , V_16 , V_17 ) ;
F_7 ( V_14 ) ;
F_8 ( V_14 , V_6 , F_9 ( V_6 ) ) ;
F_10 ( V_7 , F_9 ( V_7 ) ) ;
V_13 = F_11 ( V_14 ) ;
F_12 ( V_13 , V_8 , F_9 ( V_8 ) ) ;
F_13 ( V_17 , F_1 , V_14 ) ;
}
void F_14 ( void ) {
V_18 = F_15 ( L_3 ) ;
}
