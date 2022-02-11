unsigned long F_1 ( unsigned long V_1 , const unsigned char * V_2 , int V_3 )
{
unsigned long V_4 = V_1 & 0xffff ;
unsigned long V_5 = ( V_1 >> 16 ) & 0xffff ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
V_4 = ( V_4 + V_2 [ V_6 ] ) % V_7 ;
V_5 = ( V_5 + V_4 ) % V_7 ;
}
return ( V_5 << 16 ) + V_4 ;
}
unsigned long F_2 ( const unsigned char * V_2 , int V_3 )
{
return F_1 ( 1L , V_2 , V_3 ) ;
}
unsigned long F_3 ( const char * V_2 )
{
return F_1 ( 1L , ( const unsigned char * ) V_2 , ( int ) strlen ( V_2 ) ) ;
}
