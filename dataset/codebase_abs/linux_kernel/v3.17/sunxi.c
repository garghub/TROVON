static void F_1 ( enum V_1 V_2 , const char * V_3 )
{
if ( ! V_4 )
return;
F_2 ( V_5 | V_6 ,
V_4 + V_7 ) ;
F_2 ( V_8 , V_4 + V_9 ) ;
while ( 1 ) {
F_3 ( 5 ) ;
F_2 ( V_5 | V_6 ,
V_4 + V_7 ) ;
}
}
static void F_4 ( void )
{
struct V_10 * V_11 ;
V_11 = F_5 ( NULL , V_12 ) ;
if ( F_6 ( ! V_11 , L_1 ) )
return;
V_4 = F_7 ( V_11 , 0 ) ;
F_6 ( ! V_4 , L_2 ) ;
}
static void T_1 F_8 ( void )
{
F_4 () ;
F_9 ( NULL , V_13 , NULL , NULL ) ;
}
static void T_1 F_10 ( void )
{
F_11 ( NULL ) ;
if ( F_12 ( V_14 ) )
F_13 () ;
F_14 () ;
}
