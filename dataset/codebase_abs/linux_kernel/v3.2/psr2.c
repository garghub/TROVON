static void F_1 ( void )
{
F_2 () ;
for (; ; ) ;
}
static void F_3 ( char * V_1 )
{
F_1 () ;
}
static int F_4 ( void )
{
struct V_2 * V_3 ;
V_3 = F_5 ( NULL , NULL , L_1 ) ;
if ( V_3 != NULL ) {
struct V_4 V_5 ;
if ( F_6 ( V_3 , 0 , & V_5 ) == 0 )
F_7 ( L_2 , 0 , & V_5 , 1 ) ;
}
return 0 ;
}
static void T_1 F_8 ( void )
{
V_6 = 50000000 ;
F_9 () ;
#ifdef F_10
F_11 () ;
#endif
#ifdef F_12
F_13 () ;
#endif
}
static int T_1 F_14 ( void )
{
unsigned long V_7 = F_15 () ;
if ( ! F_16 ( V_7 , L_3 ) )
return 0 ;
return 1 ;
}
static void T_1 F_17 ( void )
{
F_18 () ;
F_19 () ;
}
