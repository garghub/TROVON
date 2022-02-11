int F_1 ( struct V_1 * V_1 )
{
return 0 ;
}
void F_2 ( struct V_1 * V_1 )
{
}
unsigned long F_3 ( struct V_1 * V_1 )
{
return V_2 ;
}
static void F_4 ( void )
{
F_5 ( V_3 , F_6 ( V_4 ) ) ;
F_7 () ;
}
void T_1 F_8 ( unsigned long V_5 )
{
V_6 = F_4 ;
V_7 = ( 1 << V_8 ) | ( 1 << V_9 )
| ( 1 << V_10 ) ;
}
void T_1 F_9 ( unsigned int V_11 [ V_12 ] )
{
if ( ! V_11 )
V_11 = V_13 ;
F_10 ( V_11 , V_7 ) ;
}
