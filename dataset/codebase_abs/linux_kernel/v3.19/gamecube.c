static void F_1 ( void )
{
for (; ; )
F_2 () ;
}
static void F_3 ( char * V_1 )
{
F_4 () ;
F_5 () ;
F_1 () ;
}
static void F_6 ( void )
{
F_4 () ;
F_1 () ;
}
static void F_7 ( void )
{
F_3 ( NULL ) ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
}
static int T_1 F_10 ( void )
{
unsigned long V_2 ;
V_2 = F_11 () ;
if ( ! F_12 ( V_2 , L_1 ) )
return 0 ;
V_3 = F_6 ;
return 1 ;
}
static void F_13 ( void )
{
F_14 () ;
}
static int T_1 F_15 ( void )
{
if ( ! F_16 ( V_4 ) )
return 0 ;
F_17 ( NULL , V_5 , NULL ) ;
return 0 ;
}
