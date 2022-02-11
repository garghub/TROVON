void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_4 ) ;
F_5 ( & V_2 -> V_3 , & V_5 ) ;
F_6 ( & V_4 ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_4 ( & V_4 ) ;
F_8 ( & V_2 -> V_3 ) ;
F_6 ( & V_4 ) ;
}
int F_9 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( V_2 -> V_7 )
return - V_8 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_9 = V_7 -> V_10 ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
V_2 -> V_7 = NULL ;
V_2 -> V_9 = NULL ;
return 0 ;
}
struct V_1 * F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
F_4 ( & V_4 ) ;
F_12 (panel, &panel_list, list) {
if ( V_2 -> V_10 -> V_13 == V_12 ) {
F_6 ( & V_4 ) ;
return V_2 ;
}
}
F_6 ( & V_4 ) ;
return NULL ;
}
