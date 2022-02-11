void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int T_2 F_3 ( unsigned int V_2 , struct V_3 * V_4 )
{
V_2 = F_4 ( V_2 ) ;
if ( ( ( F_5 ( V_5 ) >> ( 4 * V_2 ) ) & 3 ) == 3 )
F_6 ( 1 << V_2 , V_6 ) ;
else
F_6 ( 1 << V_2 , V_7 ) ;
return 0 ;
}
static void T_1 F_7 ( unsigned int V_8 )
{
F_8 ( V_9 ) ;
F_6 ( 0 , V_10 ) ;
F_6 ( F_9 ( V_11 ) , V_12 ) ;
F_10 ( V_9 , V_13 ) ;
}
static void T_1 F_11 ( void )
{
V_9 = F_12 ( V_14 ) ;
F_13 ( F_14 ( V_9 ) ) ;
}
static int F_15 ( unsigned int V_2 )
{
int V_15 ;
T_3 V_16 ;
for ( V_15 = 0 ; V_15 < 1000 ; V_15 ++ ) {
V_16 = ( F_5 ( V_5 ) >> ( 4 * V_2 ) ) & 3 ;
if ( V_16 == V_17 )
return 1 ;
F_16 ( 1 ) ;
}
return 0 ;
}
static void F_17 ( unsigned int V_2 )
{
F_10 ( V_9 , V_18 ) ;
F_18 () ;
}
static int F_19 ( unsigned int V_2 )
{
return 0 ;
}
