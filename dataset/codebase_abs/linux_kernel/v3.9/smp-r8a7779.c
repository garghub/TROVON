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
static unsigned int T_2 F_9 ( void )
{
void T_1 * V_4 = F_1 () ;
return F_10 ( V_4 ) ;
}
static int F_11 ( unsigned int V_7 )
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
static int T_3 F_15 ( unsigned int V_7 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 1000 ; V_13 ++ ) {
if ( F_16 ( V_7 ) )
return F_11 ( V_7 ) ;
F_17 ( 1 ) ;
}
return 0 ;
}
static void T_4 F_18 ( unsigned int V_7 )
{
F_19 ( 0 ) ;
}
static int T_4 F_20 ( unsigned int V_7 , struct V_14 * V_15 )
{
struct V_8 * V_9 = NULL ;
int V_10 = - V_11 ;
V_7 = F_12 ( V_7 ) ;
F_4 ( 0 , 3 << ( V_7 * 8 ) ) ;
if ( V_7 < F_13 ( V_12 ) )
V_9 = V_12 [ V_7 ] ;
if ( V_9 )
V_10 = F_21 ( V_9 ) ;
return V_10 ;
}
static void T_2 F_22 ( unsigned int V_16 )
{
int V_7 = F_12 ( 0 ) ;
F_23 ( F_1 () ) ;
F_8 ( F_24 ( V_17 ) , V_18 ) ;
F_4 ( 0 , 3 << ( V_7 * 8 ) ) ;
F_25 () ;
F_11 ( 1 ) ;
F_11 ( 2 ) ;
F_11 ( 3 ) ;
}
static void T_2 F_26 ( void )
{
unsigned int V_19 = F_9 () ;
F_27 ( V_19 ) ;
}
