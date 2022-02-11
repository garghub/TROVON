void F_1 ( int V_1 , int V_2 , T_1 V_3 )
{
if ( ( V_1 <= V_4 ) || ( V_1 >= V_5 ) )
return;
if ( ( V_2 < 0 ) || ( V_2 > 0x100 ) || ( ( V_2 & 0x03 ) != 0 ) )
return;
if ( V_6 [ V_1 ] != NULL )
V_6 [ V_1 ] ( V_2 , V_3 ) ;
}
T_1 F_2 ( int V_1 , int V_2 )
{
T_1 V_7 = 0 ;
if ( ( V_1 <= V_4 ) || ( V_1 >= V_5 ) )
return 0 ;
if ( ( V_2 < 0 ) || ( ( V_2 & 0x03 ) != 0 ) )
return 0 ;
if ( V_2 > 0x100 )
return 0xffffffff ;
if ( V_8 [ V_1 ] != NULL )
V_7 = V_8 [ V_1 ] ( V_2 ) ;
return V_7 ;
}
