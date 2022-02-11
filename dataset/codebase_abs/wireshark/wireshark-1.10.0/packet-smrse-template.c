static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_6 V_7 , V_8 ;
int V_9 = 0 ;
T_7 V_10 ;
F_2 ( & V_10 , V_11 , TRUE , V_2 ) ;
V_7 = F_3 ( V_1 , 0 ) ;
V_8 = F_3 ( V_1 , 3 ) ;
if( V_7 != 126 )
return 0 ;
if( ( V_8 < 1 ) || ( V_8 > 11 ) )
return 0 ;
if( V_3 ) {
V_5 = F_4 ( V_3 , V_12 , V_1 , 0 , - 1 , V_13 ) ;
V_6 = F_5 ( V_5 , V_14 ) ;
}
F_6 ( V_2 -> V_15 , V_16 , L_1 ) ;
if ( F_7 ( V_2 -> V_15 , V_17 ) )
F_8 ( V_2 -> V_15 , V_17 , F_9 ( V_8 , V_18 , L_2 ) ) ;
F_4 ( V_6 , V_19 , V_1 , 0 , 1 , V_20 ) ;
F_4 ( V_6 , V_21 , V_1 , 1 , 2 , V_20 ) ;
F_4 ( V_6 , V_22 , V_1 , 3 , 1 , V_20 ) ;
switch( V_8 ) {
case 1 :
case 2 :
V_9 = 4 ;
break;
case 3 :
V_9 = F_10 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
case 4 :
V_9 = F_11 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
case 5 :
V_9 = F_12 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
case 6 :
V_9 = F_13 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
case 7 :
V_9 = F_14 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
case 8 :
V_9 = F_15 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
case 9 :
V_9 = F_16 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
case 10 :
V_9 = F_17 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
case 11 :
V_9 = F_18 ( FALSE , V_1 , 4 , & V_10 , V_6 , - 1 ) ;
break;
}
return V_9 ;
}
void F_19 ( void ) {
static T_8 V_23 [] = {
{ & V_19 , {
L_3 , L_4 , V_24 , V_25 ,
NULL , 0 , L_5 , V_26 } } ,
{ & V_22 , {
L_6 , L_7 , V_24 , V_25 ,
F_20 ( V_18 ) , 0 , NULL , V_26 } } ,
{ & V_21 , {
L_8 , L_9 , V_27 , V_25 ,
NULL , 0 , L_10 , V_26 } } ,
{ & V_28 ,
{ L_11 , L_12 ,
V_29 , V_30 , NULL , 0 ,
L_13 , V_26 } } ,
#include "packet-smrse-hfarr.c"
} ;
static T_9 * V_31 [] = {
& V_14 ,
#include "packet-smrse-ettarr.c"
} ;
V_12 = F_21 ( V_32 , V_33 , V_34 ) ;
F_22 ( V_12 , V_23 , F_23 ( V_23 ) ) ;
F_24 ( V_31 , F_23 ( V_31 ) ) ;
}
void F_25 ( void ) {
T_10 V_35 ;
V_35 = F_26 ( F_1 , V_12 ) ;
F_27 ( L_14 , V_36 , V_35 ) ;
}
