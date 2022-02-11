T_1 void F_1 ( struct V_1 * V_2 )
{
extern void V_3 ( struct V_4 * V_2 ) ;
F_2 ( V_5 L_1 , __FILE__ , __LINE__ ) ;
V_3 ( (struct V_4 * ) V_2 ) ;
asm("halt");
}
void T_2 F_3 ( void )
{
int V_6 ;
for ( V_6 = 3 ; ( V_6 <= 23 ) ; V_6 ++ )
V_7 [ V_6 ] = V_8 ;
for ( V_6 = 33 ; ( V_6 <= 63 ) ; V_6 ++ )
V_7 [ V_6 ] = V_8 ;
for ( V_6 = 24 ; ( V_6 <= 31 ) ; V_6 ++ )
V_7 [ V_6 ] = V_9 ;
for ( V_6 = 64 ; ( V_6 < 255 ) ; V_6 ++ )
V_7 [ V_6 ] = V_9 ;
V_7 [ 255 ] = 0 ;
V_7 [ 2 ] = V_10 ;
V_7 [ 32 ] = V_11 ;
#ifdef F_4
V_7 [ 12 ] = V_12 ;
#endif
}
