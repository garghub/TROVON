int F_1 ( T_1 * V_1 , const T_2 V_2 ,
const T_1 * V_3 , const T_2 V_4 )
{
T_2 V_5 = 0 ;
T_2 V_6 = 0 ;
T_2 V_7 = 0 ;
T_2 V_8 = 0 ;
static const T_1 * V_9 = ( T_1 * ) L_1 ;
while ( V_6 < V_4 ) {
V_7 |= ( ( unsigned ) V_3 [ V_6 ++ ] ) << V_8 ;
V_8 += 8 ;
while ( V_8 >= 5 ) {
if ( V_5 >= V_2 ) {
return V_10 ;
}
V_1 [ V_5 ++ ] = V_9 [ V_7 & 31 ] ;
V_8 -= 5 ;
V_7 >>= 5 ;
}
}
if ( V_8 ) {
if ( V_5 >= V_2 ) {
return V_10 ;
}
V_1 [ V_5 ++ ] = V_9 [ V_7 & 31 ] ;
}
if ( V_5 < V_2 ) {
V_1 [ V_5 ] = '\0' ;
}
return V_5 ;
}
