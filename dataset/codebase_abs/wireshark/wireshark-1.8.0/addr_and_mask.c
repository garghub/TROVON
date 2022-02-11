int
F_1 ( T_1 * V_1 , int V_2 , T_2 * V_3 , T_3 V_4 )
{
T_3 V_5 ;
if ( V_4 > 32 )
return - 1 ;
V_5 = ( V_4 + 7 ) / 8 ;
memset ( V_3 , 0 , 4 ) ;
F_2 ( V_1 , V_3 , V_2 , V_5 ) ;
if ( V_4 % 8 )
V_3 [ V_5 - 1 ] &= ( ( 0xff00 >> ( V_4 % 8 ) ) & 0xff ) ;
return V_5 ;
}
int
F_3 ( T_1 * V_1 , int V_2 , struct V_6 * V_3 ,
T_3 V_4 )
{
T_3 V_5 ;
if ( V_4 > 128 )
return - 1 ;
V_5 = ( V_4 + 7 ) / 8 ;
memset ( V_3 -> V_7 , 0 , 16 ) ;
F_2 ( V_1 , V_3 -> V_7 , V_2 , V_5 ) ;
if ( V_4 % 8 ) {
V_3 -> V_7 [ V_5 - 1 ] &=
( ( 0xff00 >> ( V_4 % 8 ) ) & 0xff ) ;
}
return V_5 ;
}
