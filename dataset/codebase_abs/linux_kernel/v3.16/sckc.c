static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
void (* F_2)( struct V_1 * , void T_2 * );
const struct V_4 * V_5 ;
void T_2 * V_6 = F_3 ( V_2 , 0 ) ;
if ( ! V_6 )
return;
F_4 (np, childnp) {
V_5 = F_5 ( V_7 , V_3 ) ;
if ( ! V_5 )
continue;
F_2 = V_5 -> V_8 ;
F_2 ( V_3 , V_6 ) ;
}
}
