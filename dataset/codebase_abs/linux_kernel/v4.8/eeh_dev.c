struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_1 * V_6 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 ) {
F_3 ( L_1 ,
V_8 ) ;
return NULL ;
}
V_3 -> V_6 = V_6 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_5 = V_5 ;
F_4 ( & V_6 -> V_9 ) ;
F_4 ( & V_6 -> V_10 ) ;
return V_6 ;
}
void F_5 ( struct V_4 * V_5 )
{
F_6 ( V_5 ) ;
}
static int T_1 F_7 ( void )
{
struct V_4 * V_5 , * V_11 ;
F_8 (phb, tmp, &hose_list, list_node)
F_5 ( V_5 ) ;
return 0 ;
}
