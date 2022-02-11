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
static void T_3 F_11 ( unsigned int V_7 )
{
F_12 ( 0 ) ;
}
static int T_3 F_13 ( unsigned int V_7 , struct V_8 * V_9 )
{
V_7 = F_14 ( V_7 ) ;
F_4 ( 0 , 3 << ( V_7 * 8 ) ) ;
if ( ( ( F_6 ( V_10 ) >> ( 4 * V_7 ) ) & 3 ) == 3 )
F_8 ( 1 << V_7 , V_11 ) ;
else
F_8 ( 1 << V_7 , V_12 ) ;
return 0 ;
}
static void T_2 F_15 ( unsigned int V_13 )
{
int V_7 = F_14 ( 0 ) ;
F_16 ( F_1 () ) ;
F_8 ( 0 , V_14 ) ;
F_8 ( F_17 ( V_15 ) , V_16 ) ;
F_4 ( 0 , 3 << ( V_7 * 8 ) ) ;
}
static void T_2 F_18 ( void )
{
unsigned int V_17 = F_9 () ;
F_19 ( V_17 ) ;
}
static int T_4 F_20 ( unsigned int V_7 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < 1000 ; V_18 ++ ) {
if ( F_21 ( V_7 ) )
return 1 ;
F_22 ( 1 ) ;
}
return 0 ;
}
