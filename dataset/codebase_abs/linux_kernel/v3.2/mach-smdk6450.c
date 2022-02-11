static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 ;
if ( V_3 ) {
V_4 = F_2 ( F_3 ( 5 ) , L_1 ) ;
if ( V_4 ) {
F_4 ( V_5 L_2 ) ;
return;
}
F_5 ( F_3 ( 5 ) , 1 ) ;
F_6 ( F_3 ( 5 ) , 0 ) ;
F_6 ( F_3 ( 5 ) , 1 ) ;
F_7 ( F_3 ( 5 ) ) ;
}
}
static void T_1 F_8 ( void )
{
F_9 ( NULL , 0 , V_6 ) ;
F_10 ( 19200000 ) ;
F_11 ( V_7 , F_12 ( V_7 ) ) ;
F_13 ( V_8 , V_9 ) ;
}
static void F_14 ( void )
{
unsigned int V_10 ;
V_10 = F_15 ( V_11 ) ;
V_10 &= ~ V_12 ;
V_10 |= V_13 ;
F_16 ( V_10 , V_11 ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( NULL ) ;
F_19 ( & V_14 ) ;
F_20 ( & V_15 ) ;
F_21 ( 0 , V_16 ,
F_12 ( V_16 ) ) ;
F_21 ( 1 , V_17 ,
F_12 ( V_17 ) ) ;
F_22 ( & V_18 , & V_19 ) ;
F_14 () ;
F_23 ( & V_20 ) ;
F_24 ( V_21 , F_12 ( V_21 ) ) ;
}
