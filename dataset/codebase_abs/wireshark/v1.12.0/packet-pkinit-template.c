int
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 * T_4 V_4 ) {
V_3 = F_2 ( FALSE , V_2 , V_3 , T_4 , V_1 , - 1 ) ;
return V_3 ;
}
int
F_3 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 * T_4 V_4 ) {
V_3 = F_4 ( FALSE , V_2 , V_3 , T_4 , V_1 , - 1 ) ;
return V_3 ;
}
static int
F_5 ( T_5 T_6 V_4 , T_2 * V_2 , int V_3 , T_3 * T_4 , T_1 * V_1 , int T_7 V_4 ) {
V_3 = F_6 ( V_1 , V_2 , V_3 , T_4 ) ;
return V_3 ;
}
static int
F_7 ( T_5 T_6 V_4 , T_2 * V_2 , int V_3 , T_3 * T_4 , T_1 * V_1 , int T_7 V_4 ) {
V_3 = F_8 ( V_1 , V_2 , V_3 , T_4 ) ;
return V_3 ;
}
static int
F_9 ( T_5 T_6 V_4 , T_2 * V_2 , int V_3 , T_3 * T_4 , T_1 * V_1 , int T_7 V_4 ) {
V_3 = F_10 ( V_1 , V_2 , V_3 , T_4 ) ;
return V_3 ;
}
static int
F_11 ( T_5 T_6 V_4 , T_2 * V_2 , int V_3 , T_3 * T_4 , T_1 * V_1 , int T_7 V_4 ) {
V_3 = F_12 ( V_1 , V_2 , V_3 , T_4 ) ;
return V_3 ;
}
void F_13 ( void ) {
static T_8 V_5 [] = {
#include "packet-pkinit-hfarr.c"
} ;
static T_9 * V_6 [] = {
#include "packet-pkinit-ettarr.c"
} ;
V_7 = F_14 ( V_8 , V_9 , V_10 ) ;
F_15 ( V_7 , V_5 , F_16 ( V_5 ) ) ;
F_17 ( V_6 , F_16 ( V_6 ) ) ;
}
void F_18 ( void ) {
#include "packet-pkinit-dis-tab.c"
}
