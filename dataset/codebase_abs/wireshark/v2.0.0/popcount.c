int
F_1 ( unsigned int V_1 )
{
#if ( V_2 > 3 || ( V_2 == 3 && V_3 >= 4 ) )
return F_2 ( V_1 ) ;
#else
unsigned long V_4 ;
V_4 = ( V_1 >> 1 ) & 033333333333 ;
V_4 = V_1 - V_4 - ( ( V_4 >> 1 ) & 033333333333 ) ;
return ( ( ( V_4 + ( V_4 >> 3 ) ) & 030707070707 ) % 077 ) ;
#endif
}
