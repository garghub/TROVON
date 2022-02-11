static T_1
F_1 ( int V_1 , unsigned short V_2 )
{
T_1 V_3 ;
switch( V_1 )
{
case 1 :
V_3 = ( T_1 ) V_4 ;
break;
default:
case 2 :
V_3 = ( T_1 ) V_5 ;
break;
}
V_3 -> V_6 [ 1 ] = ( unsigned char ) V_2 ;
V_3 -> V_6 [ 2 ] = ( unsigned char ) ( V_2 >> 8 ) ;
return V_3 ;
}
