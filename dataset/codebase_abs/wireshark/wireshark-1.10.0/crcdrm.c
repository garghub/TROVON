unsigned long F_1 ( const char * V_1 , T_1 V_2 ,
unsigned short V_3 , unsigned long V_4 , int V_5 )
{
unsigned long V_6 , V_7 , V_8 , V_9 , V_10 ;
signed short V_11 ;
V_7 = ( 1 << V_3 ) - 1 ;
V_6 = V_7 ;
for ( V_8 = 0 ; V_8 < V_2 ; V_8 ++ )
for ( V_11 = 7 ; V_11 >= 0 ; V_11 -- )
{
V_6 <<= 1 ;
V_9 = V_6 >> V_3 ;
V_10 = ( V_1 [ V_8 ] >> V_11 ) & 1 ;
if ( ( V_9 ^ V_10 ) != 0 )
V_6 = V_6 ^ V_4 ;
V_6 = V_6 & V_7 ;
}
if ( V_5 )
V_6 = V_6 ^ V_7 ;
return V_6 ;
}
