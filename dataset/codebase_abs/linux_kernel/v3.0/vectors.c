T_1 void F_1 ( struct V_1 * V_2 )
{
extern void V_3 ( struct V_4 * V_2 ) ;
F_2 ( V_5 L_1 , __FILE__ , __LINE__ ) ;
V_3 ( (struct V_4 * ) V_2 ) ;
asm("halt");
}
void F_3 ( int V_6 , void (* F_4)( void ) )
{
if ( V_6 >= 0 && V_6 <= 255 )
V_7 [ V_6 ] = F_4 ;
}
void T_2 F_5 ( void )
{
int V_8 ;
for ( V_8 = 3 ; ( V_8 <= 23 ) ; V_8 ++ )
V_7 [ V_8 ] = V_9 ;
for ( V_8 = 33 ; ( V_8 <= 63 ) ; V_8 ++ )
V_7 [ V_8 ] = V_9 ;
for ( V_8 = 24 ; ( V_8 <= 31 ) ; V_8 ++ )
V_7 [ V_8 ] = V_10 ;
for ( V_8 = 64 ; ( V_8 < 255 ) ; V_8 ++ )
V_7 [ V_8 ] = V_10 ;
V_7 [ 255 ] = 0 ;
V_7 [ 2 ] = V_11 ;
V_7 [ 32 ] = V_12 ;
#ifdef F_6
V_7 [ 12 ] = V_13 ;
#endif
}
