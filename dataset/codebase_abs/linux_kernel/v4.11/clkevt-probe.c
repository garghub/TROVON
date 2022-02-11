int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
T_2 V_5 ;
int V_6 , V_7 = 0 ;
F_2 (np, __clkevt_of_table, &match) {
if ( ! F_3 ( V_2 ) )
continue;
V_5 = V_4 -> V_8 ;
V_6 = V_5 ( V_2 ) ;
if ( V_6 ) {
F_4 ( L_1 ,
V_2 -> V_9 , V_6 ) ;
continue;
}
V_7 ++ ;
}
if ( ! V_7 ) {
F_5 ( L_2 , V_10 ) ;
return - V_11 ;
}
return 0 ;
}
