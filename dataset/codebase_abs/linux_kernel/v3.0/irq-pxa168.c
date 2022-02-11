static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , F_3 ( V_2 -> V_4 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_5 | V_6 , F_3 ( V_2 -> V_4 ) ) ;
}
void T_1 F_5 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 64 ; V_4 ++ ) {
F_1 ( F_6 ( V_4 ) ) ;
F_7 ( V_4 , & V_7 , V_8 ) ;
F_8 ( V_4 , V_9 ) ;
}
}
