void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
T_2 V_5 ;
unsigned V_6 = 0 ;
int V_7 ;
F_2 (np, __timer_of_table, &match) {
if ( ! F_3 ( V_2 ) )
continue;
V_5 = V_4 -> V_8 ;
V_7 = V_5 ( V_2 ) ;
if ( V_7 ) {
F_4 ( L_1 ,
F_5 ( V_2 ) , V_7 ) ;
continue;
}
V_6 ++ ;
}
V_6 += F_6 ( V_9 ) ;
if ( ! V_6 )
F_7 ( L_2 , V_10 ) ;
}
