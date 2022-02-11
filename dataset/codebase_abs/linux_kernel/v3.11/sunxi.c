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
const struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_13 = F_5 ( NULL , V_14 ) ;
if ( F_6 ( ! V_13 , L_1 ) )
return;
V_4 = F_7 ( V_13 , 0 ) ;
F_6 ( ! V_4 , L_2 ) ;
V_11 = F_8 ( V_14 , V_13 ) ;
F_6 ( ! V_11 , L_3 ) ;
V_15 = V_11 -> V_16 ;
}
static void T_1 F_9 ( void )
{
F_10 () ;
F_11 () ;
}
static void T_1 F_12 ( void )
{
F_4 () ;
F_13 ( NULL , V_17 , NULL , NULL ) ;
}
