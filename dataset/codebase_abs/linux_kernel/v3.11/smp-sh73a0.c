void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static int F_3 ( unsigned int V_2 , struct V_3 * V_4 )
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
V_13 = F_10 ( V_14 ) ;
V_15 = ( unsigned long ) V_9 ;
F_11 ( V_9 , V_16 ) ;
}
static void T_1 F_12 ( void )
{
V_9 = F_13 ( V_17 ) ;
F_14 ( F_15 ( V_9 ) ) ;
}
static int F_16 ( unsigned int V_2 )
{
int V_18 ;
T_2 V_19 ;
for ( V_18 = 0 ; V_18 < 1000 ; V_18 ++ ) {
V_19 = ( F_5 ( V_5 ) >> ( 4 * V_2 ) ) & 3 ;
if ( V_19 == V_20 )
return 1 ;
F_17 ( 1 ) ;
}
return 0 ;
}
static void F_18 ( unsigned int V_2 )
{
F_11 ( V_9 , V_21 ) ;
F_19 () ;
}
static int F_20 ( unsigned int V_2 )
{
return 0 ;
}
