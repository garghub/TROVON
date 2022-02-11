static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_4 = NULL ;
V_2 -> V_5 = NULL ;
if ( V_4 )
F_2 ( V_4 ) ;
}
void
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_6 == V_7 ) {
F_4 ( F_5 ( V_4 ) ) ;
return;
}
F_6 ( V_2 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = F_1 ;
}
static int T_1 F_7 ( void )
{
F_8 ( L_1 ) ;
F_8 ( L_2 ) ;
return 0 ;
}
