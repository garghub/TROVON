static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 = NULL ;
T_3 * V_5 = NULL ;
T_5 V_6 , V_7 ;
int V_8 = 0 ;
T_6 V_9 ;
F_2 ( & V_9 , V_10 , TRUE , V_2 ) ;
V_6 = F_3 ( V_1 , 0 ) ;
V_7 = F_3 ( V_1 , 3 ) ;
if( V_6 != 126 )
return 0 ;
if( ( V_7 < 1 ) || ( V_7 > 11 ) )
return 0 ;
if( V_3 ) {
V_4 = F_4 ( V_3 , V_11 , V_1 , 0 , - 1 , V_12 ) ;
V_5 = F_5 ( V_4 , V_13 ) ;
}
F_6 ( V_2 -> V_14 , V_15 , L_1 ) ;
if ( F_7 ( V_2 -> V_14 , V_16 ) )
F_8 ( V_2 -> V_14 , V_16 , F_9 ( V_7 , V_17 , L_2 ) ) ;
F_4 ( V_5 , V_18 , V_1 , 0 , 1 , V_19 ) ;
F_4 ( V_5 , V_20 , V_1 , 1 , 2 , V_19 ) ;
F_4 ( V_5 , V_21 , V_1 , 3 , 1 , V_19 ) ;
switch( V_7 ) {
case 1 :
case 2 :
V_8 = 4 ;
break;
case 3 :
V_8 = F_10 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
case 4 :
V_8 = F_11 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
case 5 :
V_8 = F_12 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
case 6 :
V_8 = F_13 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
case 7 :
V_8 = F_14 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
case 8 :
V_8 = F_15 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
case 9 :
V_8 = F_16 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
case 10 :
V_8 = F_17 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
case 11 :
V_8 = F_18 ( FALSE , V_1 , 4 , & V_9 , V_5 , - 1 ) ;
break;
}
return V_8 ;
}
void F_19 ( void ) {
static T_7 V_22 [] = {
{ & V_18 , {
L_3 , L_4 , V_23 , V_24 ,
NULL , 0 , L_5 , V_25 } } ,
{ & V_21 , {
L_6 , L_7 , V_23 , V_24 ,
F_20 ( V_17 ) , 0 , NULL , V_25 } } ,
{ & V_20 , {
L_8 , L_9 , V_26 , V_24 ,
NULL , 0 , L_10 , V_25 } } ,
{ & V_27 ,
{ L_11 , L_12 ,
V_28 , V_29 , NULL , 0 ,
L_13 , V_25 } } ,
#include "packet-smrse-hfarr.c"
} ;
static T_8 * V_30 [] = {
& V_13 ,
#include "packet-smrse-ettarr.c"
} ;
V_11 = F_21 ( V_31 , V_32 , V_33 ) ;
F_22 ( V_11 , V_22 , F_23 ( V_22 ) ) ;
F_24 ( V_30 , F_23 ( V_30 ) ) ;
}
void F_25 ( void ) {
T_9 V_34 ;
V_34 = F_26 ( F_1 , V_11 ) ;
F_27 ( L_14 , V_35 , V_34 ) ;
}
