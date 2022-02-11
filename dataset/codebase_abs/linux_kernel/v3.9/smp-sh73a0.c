static void T_1 * F_1 ( void )
{
return ( void T_1 * ) 0xf0000000 ;
}
void T_2 F_2 ( void )
{
F_3 ( & V_1 ) ;
}
static unsigned int T_2 F_4 ( void )
{
void T_1 * V_2 = F_1 () ;
return F_5 ( V_2 ) ;
}
static void T_3 F_6 ( unsigned int V_3 )
{
F_7 ( 0 ) ;
}
static int T_3 F_8 ( unsigned int V_3 , struct V_4 * V_5 )
{
V_3 = F_9 ( V_3 ) ;
if ( ( ( F_10 ( V_6 ) >> ( 4 * V_3 ) ) & 3 ) == 3 )
F_11 ( 1 << V_3 , V_7 ) ;
else
F_11 ( 1 << V_3 , V_8 ) ;
return 0 ;
}
static void T_2 F_12 ( unsigned int V_9 )
{
F_13 ( F_1 () ) ;
F_11 ( 0 , V_10 ) ;
F_11 ( F_14 ( V_11 ) , V_12 ) ;
F_15 ( F_1 () , V_13 ) ;
}
static void T_2 F_16 ( void )
{
unsigned int V_14 = F_4 () ;
F_17 ( V_14 ) ;
}
static int F_18 ( unsigned int V_3 )
{
int V_15 ;
T_4 V_16 ;
for ( V_15 = 0 ; V_15 < 1000 ; V_15 ++ ) {
V_16 = ( F_10 ( V_6 ) >> ( 4 * V_3 ) ) & 3 ;
if ( V_16 == V_17 )
return 1 ;
F_19 ( 1 ) ;
}
return 0 ;
}
static void F_20 ( unsigned int V_3 )
{
F_21 () ;
F_22 () ;
F_15 ( F_1 () , V_18 ) ;
F_23 () ;
}
