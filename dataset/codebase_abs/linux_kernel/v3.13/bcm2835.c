static void F_1 ( void )
{
struct V_1 * V_2 = F_2 ( NULL , NULL ,
L_1 ) ;
if ( F_3 ( ! V_2 , L_2 ) )
return;
V_3 = F_4 ( V_2 , 0 ) ;
F_3 ( ! V_3 , L_3 ) ;
}
static void F_5 ( enum V_4 V_5 , const char * V_6 )
{
T_1 V_7 ;
if ( ! V_3 )
return;
F_6 ( 10 | V_8 , V_3 + V_9 ) ;
V_7 = F_7 ( V_3 + V_10 ) ;
V_7 &= ~ V_11 ;
V_7 |= V_8 | V_12 ;
F_6 ( V_7 , V_3 + V_10 ) ;
F_8 ( 1 ) ;
}
static void F_9 ( void )
{
T_1 V_7 ;
V_7 = F_7 ( V_3 + V_13 ) ;
V_7 &= ~ V_11 ;
V_7 |= V_8 | V_14 ;
F_6 ( V_7 , V_3 + V_13 ) ;
F_5 ( V_15 , L_4 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_16 , 1 ) ;
}
static void T_2 F_12 ( void )
{
int V_17 ;
F_1 () ;
if ( V_3 )
V_18 = F_9 ;
F_13 () ;
V_17 = F_14 ( NULL , V_19 , NULL ,
NULL ) ;
if ( V_17 ) {
F_15 ( L_5 , V_17 ) ;
F_16 () ;
}
}
