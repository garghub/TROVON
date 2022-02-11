unsigned long F_1 ( void )
{
unsigned int V_1 , V_2 , V_3 ;
long V_4 ;
F_2 ( 0 , V_5 ) ;
F_3 () ;
V_1 = F_4 ( V_6 ) | ( F_4 ( V_7 ) << 8 ) ;
F_3 () ;
V_3 = F_4 ( V_8 ) ;
F_3 () ;
F_2 ( 0 , V_5 ) ;
F_3 () ;
V_2 = F_4 ( V_6 ) | ( F_4 ( V_7 ) << 8 ) ;
V_4 = V_2 ;
if ( V_2 < V_1 ) {
if ( V_3 & ( 1 << 5 ) )
V_4 -= V_9 ;
} else if ( V_2 > V_1 ) {
V_4 -= V_9 ;
}
V_4 = ( V_9 - V_4 ) * ( V_10 / 1000 ) ;
return ( V_4 + V_9 / 2 ) / V_9 ;
}
void T_1 F_5 ( void )
{
F_2 ( V_9 & 255 , V_11 ) ;
F_2 ( V_9 >> 8 , V_12 ) ;
F_2 ( 0 , V_13 ) ;
}
static T_2
F_6 ( int V_14 , void * V_15 )
{
F_7 () ;
return V_16 ;
}
static void T_1 F_8 ( void )
{
F_5 () ;
F_9 ( V_17 , & V_18 ) ;
}
