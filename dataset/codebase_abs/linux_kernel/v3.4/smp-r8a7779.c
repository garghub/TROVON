static void T_1 * F_1 ( void )
{
return ( void T_1 * ) 0xf0000000 ;
}
void T_2 F_2 ( void )
{
F_3 ( & V_1 ) ;
}
static void F_4 ( unsigned long V_2 , unsigned long V_3 )
{
void T_1 * V_4 = F_1 () ;
F_5 ( & V_5 ) ;
V_6 = F_6 ( V_4 + 8 ) ;
V_6 &= ~ V_3 ;
V_6 |= V_2 ;
F_7 ( & V_5 ) ;
F_8 ( V_6 , V_4 + 8 ) ;
}
unsigned int T_2 F_9 ( void )
{
void T_1 * V_4 = F_1 () ;
return F_10 ( V_4 ) ;
}
int F_11 ( unsigned int V_7 )
{
struct V_8 * V_9 = NULL ;
int V_10 = - V_11 ;
V_7 = F_12 ( V_7 ) ;
F_4 ( 3 << ( V_7 * 8 ) , 0 ) ;
if ( V_7 < F_13 ( V_12 ) )
V_9 = V_12 [ V_7 ] ;
if ( V_9 )
V_10 = F_14 ( V_9 ) ;
return V_10 ? V_10 : 1 ;
}
void T_3 F_15 ( unsigned int V_7 )
{
F_16 ( 0 ) ;
}
int T_3 F_17 ( unsigned int V_7 )
{
struct V_8 * V_9 = NULL ;
int V_10 = - V_11 ;
V_7 = F_12 ( V_7 ) ;
F_4 ( 0 , 3 << ( V_7 * 8 ) ) ;
if ( V_7 < F_13 ( V_12 ) )
V_9 = V_12 [ V_7 ] ;
if ( V_9 )
V_10 = F_18 ( V_9 ) ;
return V_10 ;
}
void T_2 F_19 ( void )
{
int V_7 = F_12 ( 0 ) ;
F_20 ( F_1 () ) ;
F_8 ( F_21 ( V_13 ) , V_14 ) ;
F_4 ( 0 , 3 << ( V_7 * 8 ) ) ;
F_22 () ;
F_11 ( 1 ) ;
F_11 ( 2 ) ;
F_11 ( 3 ) ;
}
