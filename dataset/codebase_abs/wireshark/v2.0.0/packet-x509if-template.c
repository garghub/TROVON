static void
F_1 ( void )
{
V_1 = NULL ;
V_2 = NULL ;
V_3 = FALSE ;
V_4 = FALSE ;
V_5 = FALSE ;
V_6 = NULL ;
V_7 = NULL ;
V_8 = NULL ;
}
const char * F_2 ( void )
{
return V_6 ;
}
T_1 F_3 ( int V_9 , const T_2 * V_10 )
{
static int V_11 = 0 ;
if( V_11 < ( V_12 - 1 ) ) {
V_13 [ V_11 ] . V_14 = V_9 ;
V_13 [ V_11 ] . V_15 = V_10 ;
V_11 ++ ;
V_13 [ V_11 ] . V_14 = 0 ;
V_13 [ V_11 ] . V_15 = NULL ;
return TRUE ;
} else
return FALSE ;
}
const char * F_4 ( void )
{
return V_8 ;
}
void F_5 ( void ) {
static T_3 V_16 [] = {
{ & V_17 ,
{ L_1 , L_2 , V_18 , V_19 , NULL , 0 ,
L_3 , V_20 } } ,
{ & V_21 ,
{ L_4 , L_5 , V_22 , V_19 ,
NULL , 0 , L_6 , V_20 } } ,
#include "packet-x509if-hfarr.c"
} ;
static T_4 * V_23 [] = {
#include "packet-x509if-ettarr.c"
} ;
V_24 = F_6 ( V_25 , V_26 , V_27 ) ;
F_7 ( V_24 , V_16 , F_8 ( V_16 ) ) ;
F_9 ( V_23 , F_8 ( V_23 ) ) ;
V_13 [ 0 ] . V_14 = 0 ;
V_13 [ 0 ] . V_15 = NULL ;
}
void F_10 ( void ) {
#include "packet-x509if-dis-tab.c"
}
