void * T_1 F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_3 ( L_1 , V_9 ) ;
return NULL ;
}
F_4 ( V_2 ) -> V_7 = V_7 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_5 = V_5 ;
return NULL ;
}
void T_1 F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
F_1 ( V_2 , V_5 ) ;
F_6 ( V_2 , F_1 , V_5 ) ;
}
void T_2 F_7 ( void )
{
struct V_4 * V_5 , * V_10 ;
F_8 (phb, tmp, &hose_list, list_node)
F_5 ( V_5 ) ;
}
