static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ,
V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_6 ,
V_4 + F_4 ( V_2 -> V_7 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_6 ,
V_4 + F_6 ( V_2 -> V_7 ) ) ;
}
void T_1 F_7 ( void )
{
int V_8 ;
F_8 ( V_4 + V_9 ) ;
for ( V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
F_9 ( V_8 , & V_11 , V_12 ) ;
F_10 ( V_8 , V_13 ) ;
}
}
