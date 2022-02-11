void
F_1 ( T_1 * V_1 , T_2 * V_2 , int type ,
int V_3 , int * * V_4 , T_3 * * V_5 )
{
T_4 * V_6 = NULL , * V_7 ;
T_2 * V_8 = NULL , * V_9 ;
int exp ;
T_5 V_10 ;
switch ( type ) {
case 1 :
V_6 = F_2 ( V_2 , V_11 , V_1 , V_3 , 4 , V_12 ) ;
V_8 = F_3 ( V_6 , V_13 ) ;
F_4 ( V_6 , L_1 ) ;
V_3 ++ ;
exp = F_5 ( V_1 , V_3 ) & 7 ;
F_6 ( V_8 , V_14 , V_1 , V_3 , 1 , exp ) ;
F_7 ( V_6 , L_2 , exp ) ;
V_3 ++ ;
break;
case 2 :
V_8 = V_2 ;
break;
default:
return;
}
V_7 = F_2 ( V_8 , V_15 , V_1 , V_3 , 2 , V_12 ) ;
V_9 = F_3 ( V_7 , V_16 ) ;
F_4 ( V_7 , L_3 , ( type == 1 ) ? V_17 : L_4 ) ;
V_10 = F_8 ( V_1 , V_3 ) ;
if ( ( V_10 & 1 ) == 0 ) {
F_6 ( V_9 , V_18 ,
V_1 , V_3 , 2 , V_10 ) ;
if ( type == 1 )
F_7 ( V_6 , L_5 , V_10 >> 10 ) ;
F_7 ( V_7 , L_5 , V_10 >> 10 ) ;
}
else {
F_6 ( V_9 , V_19 ,
V_1 , V_3 , 2 , V_10 ) ;
if ( type == 1 )
F_7 ( V_6 , L_6 , V_10 >> 4 ) ;
F_7 ( V_7 , L_6 , V_10 >> 4 ) ;
}
F_6 ( V_9 , V_20 , V_1 , V_3 , 2 , V_10 ) ;
F_6 ( V_9 , V_21 , V_1 , V_3 , 2 , V_10 ) ;
}
