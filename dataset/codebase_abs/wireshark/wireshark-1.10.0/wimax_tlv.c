T_1 F_1 ( T_2 * V_1 , T_3 * V_2 , T_1 V_3 )
{
T_4 V_4 ;
V_1 -> type = ( V_5 ) F_2 ( V_2 , V_3 ) ;
V_4 = ( T_4 ) F_2 ( V_2 , ( V_3 + 1 ) ) ;
V_1 -> V_6 = 2 ;
if( ( V_4 & V_7 ) != 0 )
{
V_1 -> V_8 = 1 ;
V_4 = ( V_4 & V_9 ) ;
V_1 -> V_10 = V_4 ;
V_1 -> V_6 += V_4 ;
switch ( V_4 )
{
case 0 :
V_1 -> V_11 = 0 ;
break;
case 1 :
V_1 -> V_11 = ( V_12 ) F_2 ( V_2 , ( V_3 + 2 ) ) ;
break;
case 2 :
V_1 -> V_11 = ( V_12 ) F_3 ( V_2 , ( V_3 + 2 ) ) ;
break;
case 3 :
V_1 -> V_11 = ( V_12 ) F_4 ( V_2 , ( V_3 + 2 ) ) ;
break;
case 4 :
V_1 -> V_11 = ( V_12 ) F_5 ( V_2 , ( V_3 + 2 ) ) ;
break;
default:
V_1 -> V_13 = 0 ;
return ( T_1 ) V_4 ;
break;
}
}
else
{
V_1 -> V_8 = 0 ;
V_1 -> V_10 = 0 ;
V_1 -> V_11 = ( V_12 ) V_4 ;
}
V_1 -> V_13 = 1 ;
return 0 ;
}
T_1 F_6 ( T_2 * V_1 )
{
if( V_1 -> V_13 )
return ( T_1 ) V_1 -> type ;
return - 1 ;
}
T_1 F_7 ( T_2 * V_1 )
{
if( V_1 -> V_13 )
return ( T_1 ) V_1 -> V_10 ;
return - 1 ;
}
V_12 F_8 ( T_2 * V_1 )
{
if( V_1 -> V_13 )
return ( V_12 ) V_1 -> V_11 ;
return - 1 ;
}
T_1 F_9 ( T_2 * V_1 )
{
if( V_1 -> V_13 )
return ( T_1 ) V_1 -> V_6 ;
return - 1 ;
}
T_1 F_10 ( T_2 * V_1 )
{
if( V_1 -> V_13 )
return ( T_1 ) V_1 -> V_8 ;
return - 1 ;
}
