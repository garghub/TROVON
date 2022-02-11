static void T_1 * F_1 ( void )
{
return ( void T_1 * ) 0xf0000000 ;
}
static void F_2 ( unsigned long V_1 , unsigned long V_2 )
{
void T_1 * V_3 = F_1 () ;
F_3 ( & V_4 ) ;
V_5 = F_4 ( V_3 + 8 ) ;
V_5 &= ~ V_2 ;
V_5 |= V_1 ;
F_5 ( & V_4 ) ;
F_6 ( V_5 , V_3 + 8 ) ;
}
unsigned int T_2 F_7 ( void )
{
void T_1 * V_3 = F_1 () ;
#ifdef F_8
V_6 = ( void T_1 * ) 0xf0000600 ;
#endif
return F_9 ( V_3 ) ;
}
int F_10 ( unsigned int V_7 )
{
struct V_8 * V_9 = NULL ;
int V_10 = - V_11 ;
V_7 = F_11 ( V_7 ) ;
F_2 ( 3 << ( V_7 * 8 ) , 0 ) ;
if ( V_7 < F_12 ( V_12 ) )
V_9 = V_12 [ V_7 ] ;
if ( V_9 )
V_10 = F_13 ( V_9 ) ;
return V_10 ? V_10 : 1 ;
}
void T_3 F_14 ( unsigned int V_7 )
{
F_15 ( 0 ) ;
}
int T_3 F_16 ( unsigned int V_7 )
{
struct V_8 * V_9 = NULL ;
int V_10 = - V_11 ;
V_7 = F_11 ( V_7 ) ;
F_2 ( 0 , 3 << ( V_7 * 8 ) ) ;
if ( V_7 < F_12 ( V_12 ) )
V_9 = V_12 [ V_7 ] ;
if ( V_9 )
V_10 = F_17 ( V_9 ) ;
return V_10 ;
}
void T_2 F_18 ( void )
{
int V_7 = F_11 ( 0 ) ;
F_19 ( F_1 () ) ;
F_6 ( F_20 ( V_13 ) , F_21 ( V_14 ) ) ;
F_2 ( 0 , 3 << ( V_7 * 8 ) ) ;
F_22 () ;
F_10 ( 1 ) ;
F_10 ( 2 ) ;
F_10 ( 3 ) ;
}
