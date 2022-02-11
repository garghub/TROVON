int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
int F_7 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
if ( ! V_7 || ! V_2 )
return - V_8 ;
if ( V_2 -> V_7 )
return - V_9 ;
V_2 -> V_7 = V_7 ;
if ( V_2 -> V_10 -> V_11 )
return V_2 -> V_10 -> V_11 ( V_2 ) ;
return 0 ;
}
struct V_1 * F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_9 (bridge, &bridge_list, list) {
if ( V_2 -> V_14 == V_13 ) {
F_4 ( & V_3 ) ;
return V_2 ;
}
}
F_4 ( & V_3 ) ;
return NULL ;
}
