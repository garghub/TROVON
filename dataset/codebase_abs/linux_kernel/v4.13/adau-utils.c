int F_1 ( unsigned int V_1 , unsigned int V_2 ,
T_1 V_3 [ 5 ] )
{
unsigned int V_4 , V_5 , V_6 , V_7 , V_8 ;
unsigned int div ;
if ( ! V_2 ) {
V_4 = 0 ;
V_5 = 0 ;
V_6 = 0 ;
div = 0 ;
} else {
if ( V_2 % V_1 != 0 ) {
div = F_2 ( V_1 , 13500000 ) ;
V_1 /= div ;
V_4 = V_2 / V_1 ;
V_7 = V_2 % V_1 ;
V_8 = F_3 ( V_7 , V_1 ) ;
V_5 = V_7 / V_8 ;
V_6 = V_1 / V_8 ;
div -- ;
} else {
V_4 = V_2 / V_1 ;
V_5 = 0 ;
V_6 = 0 ;
div = 0 ;
}
if ( V_5 > 0xffff || V_6 > 0xffff || div > 3 || V_4 > 8 || V_4 < 2 )
return - V_9 ;
}
V_3 [ 0 ] = V_6 >> 8 ;
V_3 [ 1 ] = V_6 & 0xff ;
V_3 [ 2 ] = V_5 >> 8 ;
V_3 [ 3 ] = V_5 & 0xff ;
V_3 [ 4 ] = ( V_4 << 3 ) | ( div << 1 ) ;
if ( V_6 != 0 )
V_3 [ 4 ] |= 1 ;
return 0 ;
}
