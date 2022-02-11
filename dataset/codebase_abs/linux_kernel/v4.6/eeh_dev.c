void * F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 ) {
F_3 ( L_1 ,
V_9 ) ;
return NULL ;
}
V_2 -> V_7 = V_7 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_5 = V_5 ;
F_4 ( & V_7 -> V_10 ) ;
F_4 ( & V_7 -> V_11 ) ;
return NULL ;
}
void F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_12 = V_5 -> V_13 ;
F_6 ( V_5 ) ;
F_1 ( V_12 , V_5 ) ;
F_7 ( V_12 , F_1 , V_5 ) ;
}
static int T_1 F_8 ( void )
{
struct V_4 * V_5 , * V_14 ;
F_9 (phb, tmp, &hose_list, list_node)
F_5 ( V_5 ) ;
F_10 ( L_2 ) ;
return 0 ;
}
