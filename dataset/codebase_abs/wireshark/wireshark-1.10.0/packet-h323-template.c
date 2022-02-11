T_1 * F_1 ( T_1 * V_1 , const T_2 * type ) {
T_1 * V_2 ;
V_2 = F_2 ( T_1 ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_1 = V_1 ;
V_2 -> type = type ;
return V_2 ;
}
T_3 F_3 ( T_1 * V_2 ) {
return V_2 && ( V_2 -> V_3 == V_4 ) ;
}
T_1 * F_4 ( void * V_5 ) {
T_1 * V_2 = ( T_1 * ) V_5 ;
T_4 * V_6 = ( T_4 * ) V_5 ;
if ( ! F_5 ( V_6 ) )
V_6 = NULL ;
if ( V_6 )
V_2 = ( T_1 * ) V_6 -> V_7 ;
if ( ! F_3 ( V_2 ) )
V_2 = NULL ;
return V_2 ;
}
void F_6 ( T_1 * V_2 ) {
const T_2 * V_8 ;
if ( ! V_2 ) return;
V_8 = ( V_2 -> V_1 ) ? V_2 -> V_1 -> V_9 : NULL ;
V_2 -> V_9 = F_7 (
L_1
L_2
L_1 ,
( V_8 ) ? V_8 : L_3 , ( V_8 ) ? L_4 : L_3 ,
( V_2 -> type ) ? V_2 -> type : L_3 , ( V_2 -> type && ( V_2 -> V_10 || V_2 -> V_11 ) ) ? L_4 : L_3 , ( V_2 -> V_10 ) ? V_2 -> V_10 : L_3 ,
( V_2 -> V_11 ) ? L_5 : L_3 , ( V_2 -> V_11 ) ? V_2 -> V_11 : L_3
) ;
}
void F_8 ( void ) {
static T_5 V_12 [] = {
#include "packet-h323-hfarr.c"
} ;
static T_6 * V_13 [] = {
#include "packet-h323-ettarr.c"
} ;
V_14 = F_9 ( V_15 , V_16 , V_17 ) ;
F_10 ( V_14 , V_12 , F_11 ( V_12 ) ) ;
F_12 ( V_13 , F_11 ( V_13 ) ) ;
}
void F_13 ( void )
{
T_7 V_18 ;
V_18 = F_14 ( L_6 ) ;
F_15 ( L_7 , L_8 , V_18 ) ;
F_15 ( L_9 , L_10 ,
F_16 ( V_19 , V_14 ) ) ;
F_15 ( L_9 , L_11 ,
F_16 ( V_20 , V_14 ) ) ;
}
