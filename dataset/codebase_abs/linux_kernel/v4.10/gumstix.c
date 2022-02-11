static void T_1 F_1 ( void )
{
F_2 ( & V_1 ) ;
}
static void T_1 F_1 ( void )
{
F_3 ( L_1 ) ;
}
static void T_1 F_4 ( void )
{
F_5 ( & V_2 ) ;
}
static void F_4 ( void )
{
F_3 ( L_2 ) ;
}
static void F_6 ( void )
{
int V_3 = 500 ;
if ( ! ( F_7 ( V_4 ) & V_5 ) )
F_8 ( L_3 ) ;
else
return;
F_9 ( F_7 ( V_4 ) | V_6 , V_4 ) ;
do {
if ( F_7 ( V_4 ) & V_5 )
break;
F_10 ( 1 ) ;
} while ( -- V_3 );
if ( ! V_3 )
F_11 ( L_4 ) ;
}
static void T_1 F_12 ( void )
{
int V_7 ;
F_6 () ;
V_7 = F_13 ( V_8 , L_5 ) ;
if ( V_7 ) {
F_11 ( L_6 ) ;
return;
}
V_7 = F_14 ( V_8 , 1 ) ;
if ( V_7 ) {
F_11 ( L_7 ) ;
return;
}
F_15 ( V_8 , 0 ) ;
F_10 ( 100 ) ;
F_15 ( V_8 , 1 ) ;
}
static void F_12 ( void )
{
F_3 ( L_8 ) ;
}
static void T_1 F_16 ( void )
{
F_17 () ;
F_18 () ;
}
static void T_1 F_19 ( void )
{
F_20 ( F_21 ( V_9 ) ) ;
F_22 ( NULL ) ;
F_23 ( NULL ) ;
F_24 ( NULL ) ;
F_25 ( NULL ) ;
F_12 () ;
F_4 () ;
F_1 () ;
( void ) F_26 ( V_10 , F_27 ( V_10 ) ) ;
F_16 () ;
}
