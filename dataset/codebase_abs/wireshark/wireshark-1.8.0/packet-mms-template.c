static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
int V_5 ;
T_4 * V_6 = NULL ;
T_3 * V_7 = NULL ;
T_5 V_8 ;
F_2 ( & V_8 , V_9 , TRUE , V_2 ) ;
if( V_3 ) {
V_6 = F_3 ( V_3 , V_10 , V_1 , 0 , - 1 , V_11 ) ;
V_7 = F_4 ( V_6 , V_12 ) ;
}
F_5 ( V_2 -> V_13 , V_14 , L_1 ) ;
F_6 ( V_2 -> V_13 , V_15 ) ;
while ( F_7 ( V_1 , V_4 ) > 0 ) {
V_5 = V_4 ;
V_4 = F_8 ( FALSE , V_1 , V_4 , & V_8 , V_7 , - 1 ) ;
if( V_4 == V_5 ) {
F_9 ( V_7 , V_1 , V_4 , - 1 , L_2 ) ;
break;
}
}
}
void F_10 ( void ) {
static T_6 V_16 [] =
{
#include "packet-mms-hfarr.c"
} ;
static T_7 * V_17 [] = {
& V_12 ,
#include "packet-mms-ettarr.c"
} ;
V_10 = F_11 ( V_18 , V_19 , V_20 ) ;
F_12 ( L_3 , F_1 , V_10 ) ;
F_13 ( V_10 , V_16 , F_14 ( V_16 ) ) ;
F_15 ( V_17 , F_14 ( V_17 ) ) ;
}
static T_8
F_16 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
int V_4 = 0 ;
T_9 V_21 = 0 ;
T_9 V_22 ;
T_7 V_23 = 0 ;
T_10 V_24 ;
T_8 V_25 ;
T_11 V_26 ;
if ( ! F_17 ( V_1 , 0 , 2 ) )
return FALSE ;
V_4 = F_18 ( V_1 , V_4 , & V_24 , & V_25 , & V_26 ) ;
if ( V_24 != V_27 )
return FALSE ;
F_19 ( V_26 , V_28 , & V_23 ) ;
if ( V_23 == - 1 ) {
return FALSE ;
}
V_22 = F_20 ( V_1 , V_4 ) & 0x7F ;
if ( V_22 == 0 )
return FALSE ;
V_4 = F_21 ( V_1 , V_4 , & V_21 , NULL ) ;
if ( ! F_17 ( V_1 , V_4 , V_21 ) )
return FALSE ;
F_1 ( V_1 , V_2 , V_3 ) ;
return TRUE ;
}
void F_22 ( void ) {
F_23 ( L_4 , F_1 , V_10 , L_1 ) ;
F_23 ( L_5 , F_1 , V_10 , L_6 ) ;
F_24 ( L_7 , F_16 , V_10 ) ;
F_24 ( L_8 , F_16 , V_10 ) ;
}
