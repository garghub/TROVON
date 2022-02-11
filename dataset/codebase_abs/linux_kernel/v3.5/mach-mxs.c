static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
F_2 ( V_2 , 128 , 0 , 0 , & V_4 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
static int V_5 = V_6 ;
F_2 ( V_2 , 32 , V_5 , 0 , & V_4 , NULL ) ;
V_5 += 32 ;
return 0 ;
}
static void T_1 F_4 ( void )
{
F_5 () ;
F_6 ( V_7 ) ;
}
static void T_1 F_7 ( void )
{
F_8 () ;
}
static void T_1 F_9 ( void )
{
F_10 () ;
}
static void T_1 F_11 ( void )
{
struct V_8 * V_8 ;
V_8 = F_12 ( L_1 , NULL ) ;
if ( ! F_13 ( V_8 ) )
F_14 ( V_8 ) ;
}
static void T_1 F_15 ( void )
{
if ( F_16 ( L_2 ) )
F_11 () ;
F_17 ( NULL , V_9 ,
NULL , NULL ) ;
}
