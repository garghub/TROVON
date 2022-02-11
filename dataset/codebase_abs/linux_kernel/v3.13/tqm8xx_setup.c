static void T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ ) {
F_2 ( V_3 -> V_5 , V_3 -> V_3 , V_3 -> V_6 ) ;
V_3 ++ ;
}
}
static void T_1 F_3 ( void )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
F_1 ( F_4 ( V_12 ) , & V_12 [ 0 ] ) ;
F_5 ( V_13 , V_14 , V_15 ) ;
V_8 = F_6 ( NULL , L_1 ) ;
if ( V_8 == NULL )
return;
V_10 = F_7 ( V_8 , L_2 , & V_11 ) ;
if ( V_10 == NULL )
return;
F_1 ( F_4 ( V_16 ) , & V_16 [ 0 ] ) ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
F_3 () ;
}
static int T_1 F_10 ( void )
{
unsigned long V_17 = F_11 () ;
return F_12 ( V_17 , L_3 ) ;
}
static int T_1 F_13 ( void )
{
F_14 ( NULL , V_18 , NULL ) ;
return 0 ;
}
