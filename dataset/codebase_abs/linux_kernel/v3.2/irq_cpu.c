static void F_1 ( struct V_1 * V_2 )
{
F_2 ( ( long ) V_2 -> V_3 ) ;
}
static void F_3 ( unsigned int V_3 )
{
F_2 ( ( long ) V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( ( long ) V_2 -> V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( ( long ) V_2 -> V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_4 )
{
return 0 ;
}
void T_1 F_9 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
F_3 ( V_3 ) ;
F_10 ( V_3 , & V_6 ,
V_7 ) ;
}
}
