struct V_1 * F_1 ( int type )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_3 (t, &g_transport_list, t_node) {
if ( V_2 -> V_4 == type ) {
if ( V_2 -> V_5 && ! F_4 ( V_2 -> V_5 ) ) {
V_2 = NULL ;
}
F_5 ( & V_3 ) ;
return V_2 ;
}
}
F_5 ( & V_3 ) ;
return NULL ;
}
void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
F_7 ( V_2 -> V_5 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_6 ) ;
F_2 ( & V_3 ) ;
F_10 ( & V_2 -> V_6 , & V_7 ) ;
F_5 ( & V_3 ) ;
F_11 ( L_1 , V_2 -> V_8 ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_13 ( & V_2 -> V_6 ) ;
F_5 ( & V_3 ) ;
F_11 ( L_2 , V_2 -> V_8 ) ;
}
