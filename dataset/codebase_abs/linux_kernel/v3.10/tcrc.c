T_1 F_1 ( T_2 * V_1 , unsigned int V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = V_3 ;
while ( V_2 -- ) {
V_4 = V_5 [ ( T_2 ) ( ( V_4 ^ ( * V_1 ) ) & 0xFF ) ] ^
( V_4 >> 8 ) ;
V_1 ++ ;
}
return V_4 ;
}
T_1 F_2 ( T_2 * V_1 , unsigned int V_2 )
{
return ~ F_1 ( V_1 , V_2 , 0xFFFFFFFFL ) ;
}
T_1 F_3 ( T_2 * V_1 , unsigned int V_2 , T_1 V_6 )
{
return F_1 ( V_1 , V_2 , V_6 ) ;
}
