static void F_1 ( int V_1 , int V_2 )
{
F_2 ( ( V_3 ) V_2 , ( V_4 ) ( V_1 + 0x378 ) ) ;
}
static int F_3 ( int V_1 )
{
int V_2 = 0 ;
V_2 = F_4 ( ( V_4 ) ( V_1 + 0x378 ) ) ;
return V_2 & 0xff ;
}
int F_5 ( void * V_5 , int V_6 , int V_7 , int V_8 )
{
int V_2 = 0 ;
int V_9 = 0 ;
int V_10 = 0 ;
if ( ! V_11 ) {
V_10 = F_3 ( 2 ) ;
F_1 ( 2 , ( V_10 | 0x02 ) & 0xdf ) ;
V_11 = 1 ;
}
V_2 = ( ( V_7 ? 0x40 : 0 ) | ( V_6 ? 0x02 : 0 ) ) ;
F_1 ( 0 , V_2 ) ;
if ( V_8 ) {
V_9 = F_3 ( 1 ) ;
V_9 = ( ( V_9 & 0x80 ) ? 0 : 1 ) ;
}
F_1 ( 0 , V_2 | 0x01 ) ;
F_1 ( 0 , V_2 ) ;
return V_9 ;
}
