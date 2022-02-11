static void T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_3 ) ;
F_3 ( 2 , F_4 ( V_4 ) ) ;
}
static void T_1 F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 , NULL ) ;
F_7 ( V_2 , NULL ) ;
F_8 ( V_2 , NULL ) ;
}
static void T_1 F_9 ( void )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
V_2 = F_10 () ;
F_11 ( V_6 , F_12 ( V_6 ) ) ;
F_1 ( V_2 ) ;
F_13 ( V_2 ) ;
F_5 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < F_12 ( V_7 ) ; V_5 ++ )
V_7 [ V_5 ] -> V_8 . V_2 = V_2 ;
F_14 ( V_7 ,
F_12 ( V_7 ) ) ;
}
