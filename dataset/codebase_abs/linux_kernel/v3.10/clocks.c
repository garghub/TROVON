void F_1 ( unsigned int V_1 )
{
V_2 = V_1 ;
}
unsigned int F_2 ( void )
{
return V_2 ;
}
unsigned long F_3 ( void )
{
return V_3 ;
}
void F_4 ( unsigned long V_4 )
{
V_3 = V_4 ;
}
unsigned long F_5 ( void )
{
unsigned long V_5 ;
if ( F_6 () )
V_5 = 396000000 ;
else
V_5 = ( F_7 ( V_6 ) & 0x0000003f ) * V_7 ;
V_8 = V_5 ;
F_4 ( V_5 / ( 2 * ( ( int ) ( F_7 ( V_9 )
& 0x03 ) + 2 ) * 16 ) ) ;
F_1 ( V_5 ) ;
return V_5 ;
}
