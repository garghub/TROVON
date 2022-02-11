static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_5 |
V_4 ) ;
}
static int T_1 F_4 ( char * V_6 )
{
if ( ! strcmp ( V_6 , L_1 ) )
V_7 = 1 ;
else if ( ! strcmp ( V_6 , L_2 ) )
V_7 = 0 ;
else
F_5 ( L_3
L_4 ) ;
return 0 ;
}
static void T_1 F_6 ( void )
{
F_7 () ;
F_8 ( V_8 , F_9 ( V_8 ) ) ;
F_10 ( NULL ) ;
F_11 ( NULL ) ;
F_12 ( V_9 , F_9 ( V_9 ) ) ;
F_13 ( & V_10 ) ;
if ( V_7 )
F_14 ( & V_11 ) ;
F_15 ( & V_12 ) ;
if ( ! V_7 )
F_16 ( & V_13 ) ;
F_17 ( & V_14 ) ;
F_18 ( 0 , NULL ) ;
if ( F_19 ( V_15 , V_16 ) )
F_20 ( L_5
L_6 ) ;
F_21 ( & V_17 ) ;
}
static void T_1 F_22 ( void )
{
F_23 () ;
}
