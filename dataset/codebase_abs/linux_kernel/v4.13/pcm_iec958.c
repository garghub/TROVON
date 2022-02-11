static int F_1 ( T_1 V_1 , T_1 V_2 ,
T_2 * V_3 , T_3 V_4 )
{
unsigned int V_5 , V_6 ;
if ( V_4 < 4 )
return - V_7 ;
switch ( V_1 ) {
case 32000 :
V_5 = V_8 ;
break;
case 44100 :
V_5 = V_9 ;
break;
case 48000 :
V_5 = V_10 ;
break;
case 88200 :
V_5 = V_11 ;
break;
case 96000 :
V_5 = V_12 ;
break;
case 176400 :
V_5 = V_13 ;
break;
case 192000 :
V_5 = V_14 ;
break;
default:
return - V_7 ;
}
if ( V_4 > 4 ) {
switch ( V_2 ) {
case 16 :
V_6 = V_15 ;
break;
case 18 :
V_6 = V_16 ;
break;
case 20 :
V_6 = V_15 |
V_17 ;
break;
case 24 :
case 32 :
V_6 = V_18 |
V_17 ;
break;
default:
return - V_7 ;
}
}
memset ( V_3 , 0 , V_4 ) ;
V_3 [ 0 ] = V_19 | V_20 ;
V_3 [ 1 ] = V_21 ;
V_3 [ 2 ] = V_22 | V_23 ;
V_3 [ 3 ] = V_24 | V_5 ;
if ( V_4 > 4 )
V_3 [ 4 ] = V_6 ;
return V_4 ;
}
int F_2 ( struct V_25 * V_26 , T_2 * V_3 ,
T_3 V_4 )
{
return F_1 ( V_26 -> V_1 ,
F_3 ( V_26 -> V_27 ) ,
V_3 , V_4 ) ;
}
int F_4 ( struct V_28 * V_29 ,
T_2 * V_3 , T_3 V_4 )
{
return F_1 ( F_5 ( V_29 ) , F_6 ( V_29 ) ,
V_3 , V_4 ) ;
}
