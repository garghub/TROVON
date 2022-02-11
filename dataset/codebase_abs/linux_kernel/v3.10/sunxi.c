static void F_1 ( char V_1 , const char * V_2 )
{
if ( ! V_3 )
return;
F_2 ( V_4 | V_5 ,
V_3 + V_6 ) ;
F_2 ( V_7 , V_3 + V_8 ) ;
while ( 1 ) {
F_3 ( 5 ) ;
F_2 ( V_4 | V_5 ,
V_3 + V_6 ) ;
}
}
static void F_4 ( void )
{
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_12 = F_5 ( NULL , V_13 ) ;
if ( F_6 ( ! V_12 , L_1 ) )
return;
V_3 = F_7 ( V_12 , 0 ) ;
F_6 ( ! V_3 , L_2 ) ;
V_10 = F_8 ( V_13 , V_12 ) ;
F_6 ( ! V_10 , L_3 ) ;
V_14 = V_10 -> V_15 ;
}
void T_1 F_9 ( void )
{
F_10 ( V_16 , F_11 ( V_16 ) ) ;
}
static void T_1 F_12 ( void )
{
F_13 () ;
F_14 () ;
}
static void T_1 F_15 ( void )
{
F_4 () ;
F_16 ( NULL , V_17 , NULL , NULL ) ;
}
