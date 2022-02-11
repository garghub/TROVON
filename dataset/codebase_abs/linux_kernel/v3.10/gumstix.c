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
if ( ! ( V_4 & V_5 ) )
F_7 ( L_3
L_4 ) ;
else
return;
V_4 |= V_6 ;
do {
if ( V_4 & V_5 )
break;
F_8 ( 1 ) ;
} while ( -- V_3 );
if ( ! V_3 )
F_9 ( L_5 ) ;
}
static void T_1 F_10 ( void )
{
int V_7 ;
F_6 () ;
V_7 = F_11 ( V_8 , L_6 ) ;
if ( V_7 ) {
F_9 ( L_7 ) ;
return;
}
V_7 = F_12 ( V_8 , 1 ) ;
if ( V_7 ) {
F_9 ( L_8 ) ;
return;
}
F_13 ( V_8 , 0 ) ;
F_8 ( 100 ) ;
F_13 ( V_8 , 1 ) ;
}
static void F_10 ( void )
{
F_3 ( L_9 ) ;
}
static void T_1 F_14 ( void )
{
F_15 () ;
F_16 () ;
}
static void T_1 F_17 ( void )
{
F_18 ( F_19 ( V_9 ) ) ;
F_20 ( NULL ) ;
F_21 ( NULL ) ;
F_22 ( NULL ) ;
F_23 ( NULL ) ;
F_10 () ;
F_4 () ;
F_1 () ;
( void ) F_24 ( V_10 , F_25 ( V_10 ) ) ;
F_14 () ;
}
