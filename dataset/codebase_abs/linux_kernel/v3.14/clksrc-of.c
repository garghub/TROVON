void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const struct V_3 * V_4 ;
T_2 V_5 ;
unsigned V_6 = 0 ;
F_2 (np, __clksrc_of_table, &match) {
if ( ! F_3 ( V_2 ) )
continue;
V_5 = V_4 -> V_7 ;
V_5 ( V_2 ) ;
V_6 ++ ;
}
if ( ! V_6 )
F_4 ( L_1 , V_8 ) ;
}
